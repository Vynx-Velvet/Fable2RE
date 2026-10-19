"""How readable each promoted function is: what still keeps it from being plain, fully named C++.

A promoted function (Fable2Recomp/promoted/, docs/promoted-code.md) behaves exactly like the original, which
says nothing yet about whether a person can read it. Each function is measured on the published form (the text
without the game's strings, so every clone and the CI measure the same) against two bars:

    readable   plain C++: no CPU state in the body (ctx.r3, ctx.f1, ctx.xer, ...: register hand-overs to and from
               the recompiled code) and no stack-frame bookkeeping (PushStackFrame, PopStackFrame)
    named      readable, and every name says what it is: the function itself, every function it calls, every
               global (no g_820A0000 or page base plus offset), every variable and parameter (no local12, arg2,
               r31), every field (no LOAD32(self + 144), no self->m_1C)

A function that meets neither is a rewrite: checked and reviewed for behaviour, still at the level of the machine.

    python tools/rewrite/readability.py                  counts per bar and the most frequent issues
    python tools/rewrite/readability.py --module NAME    every function of one module with its issues
    python tools/rewrite/readability.py --unnamed N      the N unnamed callees and globals used most (what to name
                                                         first)
"""
import argparse
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PUBLISHED = ROOT / 'Fable2Recomp' / 'promoted'

ENTRY = re.compile(r'^PROMOTED_ENTRY\(\d+, (sub_[0-9A-F]{8}), 0x[0-9A-F]{8}\).*$', re.M)
# (the fallback to the original, the frame markers and includes: the same in every function; GameStackFrame is
# the function's frame on the game's stack, Fable2Recomp/lifted/readable_support.h)
BOILERPLATE = re.compile(r'\bUseLiftedCode\(|\bLiftedFrame\b|^\s*GameStackFrame \w+\(ctx, base, \d+\);\s*$|'
                         r'^\s*#include\b')
DEFINITION = re.compile(r'^[A-Za-z_][\w:<>,\s\*&]*?\b([A-Za-z_]\w*)\s*\(\s*CpuState\s*&', re.M)

STRUCTURE = {
    'cpu state': re.compile(r'\bctx\.\w'),
    'stack frame': re.compile(r'\b(?:PushStackFrame|PopStackFrame)\b'),
}
UNNAMED = r'(?:n_)?sub_[0-9A-F]{8}'
NAMING = {
    'unnamed callee': re.compile(rf'\b({UNNAMED})\s*\(|\b(\w*sub_[0-9A-F]{{8}}\w*)\b(?!\s*\()'),
    'address': re.compile(r'\b(g_[0-9A-F]{8})\b|\b((?:str_)?TXT_[0-9A-F]{8}_[A-Z]_)\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d)'
                          r'|(?<![\w.])(0x8[0-9A-Fa-f]{7})(?:[uU][lL]{0,2})?\b'),
    'machine variable name': re.compile(r'(?<![\w.])((?:local|arg|var|temp|tmp|stack|v|r|f)\d+)\b'),
    # a name made from an offset or a position is a placeholder too: flag144, GetField8, GetByte31, unk_10
    'placeholder name': re.compile(r'\b((?:[A-Za-z_]\w*?)?(?:[Ff]ield|[Bb]yte|[Dd]?[Ww]ord|[Ff]lag|[Oo]ffset|[Uu]nk'
                                   r'(?:nown)?)_?(?:0x)?[0-9A-Fa-f]*[0-9][0-9A-Fa-f]*)\b'),
    'field offset': re.compile(r'\b(?:LOAD|STORE)\w*\(\s*([A-Za-z_]\w*(?:\.\w+)*)\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d+)'
                               r'\s*[,)]|(?:->|\.)(m_[0-9A-Fa-f]{1,5}|field_?[0-9A-Fa-f]+|unk_?[0-9A-Fa-f]+)\b'),
}
CONSTEXPR = re.compile(r'^\s*constexpr\b')


def functions(text):
    """[(sub_X, defined name, body lines)] of a module text: each function is the text before its
    PROMOTED_ENTRY line, without comments, includes, the fallback and frame lines and the constexpr lines."""
    out, start = [], 0
    for m in ENTRY.finditer(text):
        chunk = text[start:m.start()]
        start = m.end()
        d = None
        for d in DEFINITION.finditer(chunk):
            pass
        name = d.group(1) if d else ''
        body = chunk[d.start():] if d else chunk
        lines = []
        for line in body.split('\n'):
            code = re.sub(r'//.*', '', line)
            if not code.strip() or BOILERPLATE.search(code) or CONSTEXPR.match(code):
                continue
            lines.append(code)
        out.append((m.group(1), name, lines))
    return out


def issues(name, lines):
    """{issue: [examples]} of one function."""
    found = collections.defaultdict(list)
    body = '\n'.join(lines[1:])   # (the first line is the signature: its parameters are ctx and base)
    for what, rx in STRUCTURE.items():
        found[what] += [m.group(0) for m in rx.finditer(body)]
    if re.fullmatch(UNNAMED, name):
        found['unnamed function'].append(name)
    elif NAMING['placeholder name'].fullmatch(name):
        found['placeholder name'].append(name)
    for what, rx in NAMING.items():
        found[what] += [next(g for g in m.groups() if g) if m.groups() and any(m.groups()) else m.group(0)
                        for m in rx.finditer(body)]
    # a name that still says which global it means by address (DestroyGlobalList_8349AD9C); a reference to a
    # name made from the game's text (TXT_<address>_G_) is a name
    for ident in set(re.findall(r'\b[A-Za-z_]\w*\b', body)) | {name}:
        if 'TXT_' not in ident and not re.search(r'sub_[0-9A-F]{8}', ident) and \
                not re.fullmatch(r'g_[0-9A-F]{8}', ident) and \
                re.search(r'(?<![0-9A-Fa-f])8[0-9A-F]{7}(?![0-9A-Fa-f])', ident):
            found['address'].append(ident)
    return {k: v for k, v in found.items() if v}


def level(found):
    if any(k in found for k in STRUCTURE):
        return 'rewrite'
    return 'readable' if found else 'named'


def measure(published=PUBLISHED):
    """{sub_X: (module, defined name, level, issues)} of every published promoted function."""
    out = {}
    for p in sorted(Path(published).glob('*.cpp')):
        for n, name, lines in functions(p.read_text(encoding='utf-8')):
            found = issues(name, lines)
            out[n] = (p.stem, name, level(found), found)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--module')
    ap.add_argument('--unnamed', type=int, default=0)
    a = ap.parse_args()
    m = measure()
    if a.module:
        for n, (module, name, lvl, found) in m.items():
            if module == a.module:
                print(f'{n} {name}: {lvl}')
                for k, v in found.items():
                    print(f'    {k}: {len(v)} ({", ".join(sorted(set(v))[:6])})')
        return 0
    levels = collections.Counter(v[2] for v in m.values())
    print(f'{len(m)} promoted functions: ' + ', '.join(f'{levels[k]} {k}' for k in ('named', 'readable', 'rewrite')))
    per_issue = collections.Counter(k for v in m.values() for k in v[3])
    for k, c in per_issue.most_common():
        print(f'  {c:6} functions with: {k}')
    if a.unnamed:
        use = collections.Counter()
        for v in m.values():
            for k in ('unnamed callee', 'address'):
                for x in set(v[3].get(k, [])):
                    use[x] += 1
        print(f'most used unnamed callees and addresses (functions using each):')
        for x, c in use.most_common(a.unnamed):
            print(f'  {c:6}  {x}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
