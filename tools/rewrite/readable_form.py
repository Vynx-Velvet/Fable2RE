"""The readable form of promoted functions: machine-level code the whole-game analysis shows to be unneeded is
removed, and what must stay moves into documented helpers (Fable2Recomp/lifted/readable_support.h). Every
changed function takes the strict check again (profiles 0-5, the registers callers read: promote.py verify) and
only a function that passes is written back. docs/promoted-code.md (readability levels).

Steps, each only where it provably keeps the behaviour the check compares:

  register writes   `ctx.rN.u64 = <value>;` (N not r1) goes when, in the straight-line code after it, the register
                    is written again or changed by a call (summaries 'mods') before anything reads it: a call that
                    reads it ('rin'), a read of ctx.rN, a return with N among the registers callers read
                    ('outputs'), a branch, a label or a call through a pointer (undecided). A callee that only
                    passes the register on ('fwd') does not read it when the value is a literal or a constexpr
                    address; a frame address, a variable or a parameter is a real argument (2026-10-20: dropping
                    `ctx.r4 = stack + 144` before BoneDriver_Update, which hands the address on, corrupted the
                    bone drivers and crashed Havok on a later load; the check cannot see it, its stand-in callees
                    read nothing). The value must have no side effects (no call, no memory read).
  stack frame       `stack = PushStackFrame(base, stack, N)` ... `PopStackFrame` around a body that keeps nothing in
                    the frame becomes one line, GameStackFrame stackFrame(ctx, base, N);
  at-exit           CRT atexit called with the r8 it was handed (`..., ctx.r8.u64)`) becomes
                    RegisterAtExit(ctx, base, function)
  addresses         a 64 KiB page base plus an offset passed as a call argument (`(int64_t)g_832A0000 + 12536`)
                    becomes the name of what is at that address: the function (`Destroy_g_X_address`) or the
                    string (the lifter's str_ name), declared with its address like the lifter's constants

    python tools/rewrite/readable_form.py [--only MODULE,...] [--limit N]        what would change (no check)
    python tools/rewrite/readable_form.py --apply [--only ...] [--jobs 4]        check and write back
"""
import argparse
import collections
import csv
import os
import pickle
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import promote  # noqa: E402
import readable  # noqa: E402
import regs  # noqa: E402
import summarize  # noqa: E402

WRITE = re.compile(r'^(\s*)ctx\.([rf]\d+)\.(?:u64|s64|u32|s32|f64)\s*=\s*([^;]*);\s*$')
READ = re.compile(r'ctx\.([rf]\d+)\.')
CALL = re.compile(r'\b(\w+)\(ctx, base\b')
FLOW = re.compile(r'^\s*(?:if\b|else\b|for\b|while\b|do\b|switch\b|case\b|default\b|goto\b|break\b|continue\b|'
                  r'\w+:\s*$|\}|\{)')
RETURN = re.compile(r'^\s*return\b')
CONSTEXPR = re.compile(r'^\s*constexpr\s+([\w:]+)\s+(\w+)\s*=\s*(.*);\s*$')
AT_EXIT = ('n_sub_82CA3700', 'CRT_atexit')
PAGE_ARG = re.compile(r'(?<=[(,])\s*(?:\(int64_t\)\s*)?(\w+)\s*([+-])\s*(\d+)\s*(?=[,)])')

_S = None
_FUNCS = None
_NAMES = None


def summaries():
    global _S
    if _S is None:
        with open(os.path.join(ROOT, 'tools', 'lift', 'cache', 'summaries.pkl'), 'rb') as f:
            _S = summarize.apply_invariants(pickle.load(f))   # (the facts the check uses: difftest/run.py)
    return _S


def catalog():
    """{address: size} of every function of the executable."""
    global _FUNCS
    if _FUNCS is None:
        with open(os.path.join(ROOT, 'research', 'catalog', 'functions.tsv'), encoding='utf-8') as f:
            _FUNCS = {int(r['address'], 16): r for r in csv.DictReader(f, delimiter='\t')}
    return _FUNCS


def callee_names():
    """{name in code: sub_X} for the dictionary's function names."""
    global _NAMES
    if _NAMES is None:
        _NAMES = {}
        with open(os.path.join(ROOT, 'research', 'names', 'functions.tsv'), encoding='utf-8') as f:
            for r in csv.DictReader(f, delimiter='\t'):
                _NAMES[r['name']] = 'sub_' + r['address'].upper()
    return _NAMES


def callee(name):
    m = re.fullmatch(r'(?:n_)?sub_([0-9A-F]{8})', name)
    return 'sub_' + m.group(1) if m else callee_names().get(name)


def pure(expr):
    """A value without side effects or memory reads."""
    return not re.search(r'\(ctx, base|\bLOAD|\+\+|--|(?<![=!<>])=(?!=)|\bRAW\(|->|\[', expr)


def temporary(expr, consts):
    """A leftover temporary: a literal or a constexpr address, nothing else. A frame address (stack + 144), a
    variable or a parameter handed to a callee that passes the register on is a real argument the check cannot
    see (its stand-in callees read nothing; 2026-10-20: dropping `ctx.r4 = stack + 144` before BoneDriver_Update
    corrupted the bone drivers and crashed Havok on a later load)."""
    if not pure(expr) or 'ctx.' in expr:
        return False
    idents = set(re.findall(r'\b[A-Za-z_]\w*\b', expr)) - {'int64_t', 'int32_t', 'uint64_t', 'uint32_t'}
    return idents <= set(consts)


def write_needed(fn, lines, i, reg, value, consts):
    """Whether the register write on line i can be seen by anything the check compares."""
    S = summaries()
    b = regs.bit(reg)
    outputs = S['outputs'].get(fn, regs.ABI_OUTPUTS)
    for line in lines[i + 1:]:
        w = WRITE.match(line)
        rhs = w.group(3) if w else line
        if reg in READ.findall(rhs):
            return True
        if 'REX_CALL_INDIRECT' in line:
            return True   # (a call through a pointer: any function may be reached, reading any register)
        for m in CALL.finditer(line):
            c = callee(m.group(1))
            if m.group(1) in ('RegisterAtExit',):
                c = 'sub_82CA3700'
            if c is None or c not in S['rin']:
                return True
            if S['rin'][c] & b:
                return True
            if S['fwd'][c] & b and not temporary(value, consts):
                return True
            if S['mods'][c] & b:
                return False
        if w and w.group(2) == reg:
            return False
        if RETURN.match(line):
            return bool(outputs & b)
        if FLOW.match(line):
            return True
    return bool(outputs & b)


def frame_form(lines):
    """Lines with the standard frame push/pop replaced by GameStackFrame, or None."""
    text = '\n'.join(lines)
    # (the lifter declares its locals between reading the stack pointer and the push, and sets ctx.r1 again
    # before every call; while `stack` keeps the pushed frame, those settings repeat the same value)
    m = re.search(r'^(\s*)uint32_t stack = ctx\.r1\.u(?:64|32);\n((?:\s*[\w:<>]+ \w+\{\};\n)*)'
                  r'\s*stack = PushStackFrame\(base, stack, (\d+)\);\n', text, re.M)
    if not m:
        return None
    size = m.group(3)
    pop = re.compile(rf'^\s*stack = PopStackFrame\(stack, {size}\);\n\s*ctx\.r1\.u64 = stack;\n', re.M)
    rest = text[m.end():]
    if len(re.findall(r'^\s*stack = ', rest, re.M)) != len(pop.findall(rest)):
        return None   # (the frame variable changes elsewhere)
    rest = pop.sub('\x00POP\x00', rest)
    rest = re.sub(r'^\s*ctx\.r1\.u64 = stack;\n', '', rest, flags=re.M)
    rest = rest.replace('\x00POP\x00', f'\tstack = PopStackFrame(stack, {size});\n\tctx.r1.u64 = stack;\n')
    pops = list(pop.finditer(rest))
    if not pops:
        return None
    # every pop is followed only by register hand-overs or nothing before its return or the end, no call
    for p in pops:
        after = rest[p.end():].split('\n')
        for line in after:
            if RETURN.match(line) or line.strip() == '}':
                if CALL.search(line) or 'REX_CALL_INDIRECT' in line:
                    return None   # (a tail call after the pop runs in the caller's frame)
                break
            if CALL.search(line) or 'REX_CALL_INDIRECT' in line or not (WRITE.match(line) or not line.strip()):
                return None
    rest = pop.sub('', rest)
    if re.search(r'\bstack\b', rest):
        return None   # (the body uses its frame: records on the stack)
    return (text[:m.start()] + (m.group(2) or '') + f'{m.group(1)}GameStackFrame stackFrame(ctx, base, {size});\n'
            + rest).split('\n')


def constants(lines):
    """{name: (type, value as int or None)} of the function's constexpr lines."""
    out = {}
    for line in lines:
        m = CONSTEXPR.match(line)
        if m:
            ints = re.findall(r'0x[0-9A-Fa-f]+|-?\d+', m.group(3))
            out[m.group(2)] = (m.group(1), int(ints[-1], 0) if ints else None)
    return out


def address_name(addr, module_names):
    """(name, type) for the thing at a game address: a function (named or not) or a string constant, or None."""
    if addr in catalog():
        n = f'sub_{addr:08X}'
        name = module_names.get(n) or next((k for k, v in callee_names().items() if v == n), f'n_{n}')
        return f'{name}_address', 'int32_t'
    s = readable.game_string(addr)
    if s:
        ident = readable.ident_from_text(s, 'str_')
        if ident:
            return ident, 'int32_t'
    return None


def transform(n, text, module_names):
    """(new text, [what changed]) of one function."""
    lines = text.split('\n')
    changes = []
    d = promote.DEF_RE.search(text)
    params = re.findall(r'\b(?:u?int\d+_t|double|float)\s+(\w+)(?=[,)])', lines[0]) if d else []
    # at-exit with the r8 it was handed
    for i, line in enumerate(lines):
        for name in AT_EXIT:
            new = re.sub(rf'\b{name}\(ctx, base, (.+?), ctx\.r8\.u64\)', r'RegisterAtExit(ctx, base, \1)', line)
            if new != line:
                lines[i] = new
                changes.append('at-exit')
    # page base plus offset as a call argument
    consts = constants(lines)
    added = []
    for i, line in enumerate(lines):
        if CONSTEXPR.match(line) or 'UseLiftedCode' in line:
            continue

        def sub(m):
            base_name, sign, off = m.group(1), m.group(2), int(m.group(3))
            if base_name not in consts or consts[base_name][1] is None:
                return m.group(0)
            page = consts[base_name][1] & 0xFFFFFFFF
            if page & 0xFFFF:
                return m.group(0)
            addr = (page + off if sign == '+' else page - off) & 0xFFFFFFFF
            hit = address_name(addr, module_names)
            if not hit:
                return m.group(0)
            name, typ = hit
            have = consts.get(name)
            if have and (have[1] or 0) & 0xFFFFFFFF != addr:
                return m.group(0)
            if not have:
                consts[name] = (typ, addr)
                added.append(f'\tconstexpr {typ} {name} = {typ}(0x{addr:08X});')
            changes.append('address')
            return (' ' if m.group(0).startswith(' ') else '') + name
        lines[i] = PAGE_ARG.sub(sub, line)
    if added:
        k = max((i for i, l in enumerate(lines) if CONSTEXPR.match(l)), default=0)
        lines[k + 1:k + 1] = added
    # register writes
    keep = []
    for i, line in enumerate(lines):
        w = WRITE.match(line)
        if w and w.group(2) != 'r1' and pure(w.group(3)) and not write_needed(n, lines, i, w.group(2), w.group(3),
                                                                             list(consts)):
            changes.append('register write')
            continue
        keep.append(line)
    lines = keep
    # the frame
    f = frame_form(lines)
    if f:
        lines = f
        changes.append('stack frame')
    # `T result = <call>; return result;` at the end: return the call
    rtype = re.escape(lines[0].split(' ', 1)[0])   # (only a variable of the function's own return type)
    text2 = re.sub(rf'^(\s*){rtype} (\w+) = ([^;]+);\n\s*return \2;\n\}}', r'\1return \3;\n}', '\n'.join(lines),
                   flags=re.M)
    if text2 != '\n'.join(lines):
        lines = text2.split('\n')
    # constants nothing uses any more
    def used(name):   # (in the code, or in another constant's value)
        return any(re.search(rf'\b{name}\b', CONSTEXPR.match(l).group(3) if CONSTEXPR.match(l) else l)
                   for l in lines if not (CONSTEXPR.match(l) and CONSTEXPR.match(l).group(2) == name))
    lines = [l for l in lines if not (CONSTEXPR.match(l) and not used(CONSTEXPR.match(l).group(2)))]
    return '\n'.join(lines), changes


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--only', help='modules (comma-separated, without .cpp)')
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--show', type=int, default=0, help='print N changed functions before and after')
    a = ap.parse_args()
    every = promote.module_functions()
    module_names = {n: promote.DEF_RE.search(t).group(1) for n, (_, t) in every.items() if promote.DEF_RE.search(t)}
    only = set(a.only.split(',')) if a.only else None
    funcs = {n: v for n, v in every.items() if only is None or os.path.basename(v[0])[:-4] in only}
    changed, why = {}, collections.Counter()
    for n, (path, text) in sorted(funcs.items()):
        new, changes = transform(n, text, module_names)
        if new != text:
            changed[n] = new
            for c in set(changes):
                why[c] += 1
            if a.limit and len(changed) >= a.limit:
                break
    print(f'{len(changed)} of {len(funcs)} functions change: {dict(why)}')
    for n in list(changed)[:a.show]:
        print(f'--- {n} before\n{funcs[n][1]}\n--- after\n{changed[n]}\n')
    if not a.apply or not changed:
        return 0
    res = promote.verify({n: promote.check_form(n, t) for n, t in changed.items()}, 'readable-form', a.jobs)
    ok = {n: t for n, t in changed.items() if res.get(n) == 'OK'}
    failed = collections.Counter((res.get(n) or 'no result')[:60] for n in changed if n not in ok)
    print(f'checked: {len(ok)} pass, {len(changed) - len(ok)} do not' + (f': {dict(failed.most_common(8))}'
                                                                           if failed else ''))
    by_module = collections.defaultdict(dict)
    for n, t in ok.items():
        by_module[funcs[n][0]][n] = t
    reviewed = promote.reviewed_texts()
    carried = 0
    for path, these in sorted(by_module.items()):
        head, have = promote.split_module(open(path, encoding='utf-8').read())
        for n, t in these.items():
            if reviewed.get(n) == promote.text_digest(have[n]):
                reviewed[n] = promote.text_digest(t)   # (a review applies to the readable form of its text)
                carried += 1
            have[n] = t
        promote.write_module(path, promote.ensure_includes(head), have)
    promote.save_reviewed_texts(reviewed)
    print(f'wrote {len(ok)} functions in {len(by_module)} modules ({carried} recorded reviews carried over)')
    return 0


if __name__ == '__main__':
    sys.exit(main())
