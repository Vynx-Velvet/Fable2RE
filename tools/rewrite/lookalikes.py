"""Look-alike functions: groups of Lionhead functions whose lifted code is the same apart from names, addresses
and numbers (research/findings/2026-10-18-lookalike-functions.md).

    python tools/rewrite/lookalikes.py            group the lifted functions -> build/rewrite/lookalikes.json
    python tools/rewrite/lookalikes.py --report   the biggest groups (after a grouping run)

Members of a group differ only in what the grouping abstracts: their own name, the functions they call,
classes, fields, globals, strings, labels, numbers and every identifier that fewer than COMMON functions use
(keywords, types, the memory macros and common callees stay as they are). One readable rewrite of one member,
the group's representative (make_packets.py --representatives), can be carried over to the others with their
own values; every copy is checked like a model answer. Converted functions are no longer in the lifted files:
the lifted text the packets keep stands in for them, so a group knows its converted members. About four
minutes for the whole game.
"""
import argparse
import collections
import csv
import glob
import hashlib
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import scope  # noqa: E402

OUT = os.path.join(ROOT, 'build', 'rewrite', 'lookalikes.json')
LIONHEAD = ('game', 'game-static')
COMMON = 200   # an identifier used by this many functions is part of the code's shape, not a value

COMMENT = re.compile(r'//[^\n]*')
DEF = re.compile(r'^[^\n]*?\b([A-Za-z_]\w*)\(CpuState& ctx', re.M)
TOK = re.compile(r'''(?P<C>(?<=GameObject<)\w+(?=>))
  |(?P<M>(?<=->)\w+)
  |(?P<F>\b[A-Za-z_]\w*(?=\(ctx,\s*base)|\b(?:n_)?sub_[0-9A-F]{8}\w*)
  |(?P<T>\bstr_\w+)
  |(?P<G>\bg_\w+)
  |(?P<L>\bloc_[0-9A-F]{8}\b)
  |(?P<F2>\b[A-Za-z]\w*_[0-9A-F]{8}\b)
  |(?P<V>\b(?:local|arg|var)\w*)
  |(?P<K>\b0x[0-9A-Fa-f]+\b)
  |(?P<N>\b\d+\b)
  |(?P<I>\b[A-Za-z_]\w*\b)
  |(?P<S>\s+)''', re.X)
IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
SPLIT = re.compile(r'^// @lift (sub_[0-9A-F]{8})\n', re.M)
SECTION = re.compile(r'^### (sub_[0-9A-F]{8}).*?\*\*Lifted \(exact\):\*\*\n```cpp\n(.*?)```', re.S | re.M)


def tokens(code, common):
    """(the code's shape, [(kind, value)]) of a function's lifted text."""
    code = COMMENT.sub('', code)
    m = DEF.search(code)
    own = m.group(1) if m else None
    out, values, pos = [], [], 0
    for t in TOK.finditer(code):
        out.append(code[pos:t.start()])
        pos = t.end()
        k, v = t.lastgroup, t.group()
        if k == 'S':
            out.append(' ')
            continue
        if k == 'I' and v in common and v != own:
            out.append(v)
            continue
        if k == 'F2':
            k = 'F'
        if k in ('F', 'I') and v == own:
            k = 'SELF'
        values.append((k, v))
        out.append(k)
    out.append(code[pos:])
    return hashlib.sha1(''.join(out).encode()).hexdigest()[:16], values


def lifted_functions():
    """{address: lifted text} of every function in Fable2Recomp/lifted."""
    out = {}
    for path in sorted(glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp'))):
        parts = SPLIT.split(open(path, encoding='utf-8').read())
        for i in range(1, len(parts) - 1, 2):
            out[parts[i][4:]] = parts[i + 1]
    return out


def converted():
    """{address: lifted text or None} of the converted functions: promoted, hand-written, accepted answers (the
    lifted text of promoted ones from the packets, which keep it)."""
    done = set()
    for p in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'src', 'game', 'promoted', '*.cpp')):
        done |= set(re.findall(r'^PROMOTED_ENTRY\(\d+, sub_([0-9A-F]{8})', open(p, encoding='utf-8').read(), re.M))
    with open(os.path.join(ROOT, 'research', 'catalog', 'converted.tsv'), encoding='utf-8') as f:
        done |= {r['address'] for r in csv.DictReader(f, delimiter='\t')}
    for p in glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*', 'results.txt')):
        for line in open(p, encoding='utf-8'):
            n, _, why = line.rstrip('\n').partition('\t')
            if why == 'OK' and n.startswith('sub_'):
                done.add(n[4:])
    texts = dict.fromkeys(done)
    for p in glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'packets', '*.md')):
        for m in SECTION.finditer(open(p, encoding='utf-8').read()):
            if m.group(1)[4:] in texts and texts[m.group(1)[4:]] is None:
                texts[m.group(1)[4:]] = m.group(2)
    return texts


def group():
    lifted = lifted_functions()
    seen = collections.Counter()
    for text in lifted.values():
        seen.update(set(IDENT.findall(COMMENT.sub('', text))))
    common = {w for w, c in seen.items() if c >= COMMON}
    with open(os.path.join(ROOT, 'research', 'catalog', 'functions.tsv'), encoding='utf-8') as f:
        size = {r['address']: int(r['size'] or 0) for r in csv.DictReader(f, delimiter='\t')}
    conv = converted()
    members = collections.defaultdict(list)
    info = {}
    texts = dict(lifted)
    texts.update({a: t for a, t in conv.items() if t and a not in lifted})
    for a, text in texts.items():
        area = scope.category(int(a, 16))
        if area not in LIONHEAD:
            continue
        h, _ = tokens(text, common)
        members[h].append(a)
        info.setdefault(h, (collections.Counter(), text.count('\n')))[0][area] += 1
    groups = []
    for h, addrs in members.items():
        todo = sorted(a for a in addrs if a not in conv)
        if len(addrs) < 2 or not todo:
            continue
        area = info[h][0].most_common(1)[0][0]   # (a group can hold both areas: most of its members' area)
        groups.append({'shape': h, 'area': area, 'lines': info[h][1], 'members': todo,
                       'converted': sorted(a for a in addrs if a in conv),
                       'bytes': sum(size.get(a, 0) for a in todo)})
    groups.sort(key=lambda g: (-len(g['members']), -g['bytes']))
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, 'w', encoding='utf-8') as f:
        json.dump({'common': sorted(common), 'groups': groups}, f)
    n = sum(len(g['members']) for g in groups)
    print(f'{len(groups)} groups, {n} unconverted look-alikes ({sum(1 for g in groups if g["converted"])} groups '
          f'with a converted member) -> {os.path.relpath(OUT, ROOT)}')


def report(top):
    d = json.load(open(OUT, encoding='utf-8'))
    for area in LIONHEAD:
        gs = [g for g in d['groups'] if g['area'] == area]
        print(f'{area}: {len(gs)} groups, {sum(len(g["members"]) for g in gs)} functions, '
              f'{sum(g["bytes"] for g in gs):,} bytes')
    for g in d['groups'][:top]:
        print(f'  x{len(g["members"]):5} {g["area"]:11} {g["lines"]:4} lines {g["bytes"]:8,} bytes  converted '
              f'{len(g["converted"])}  e.g. sub_{g["members"][0]}')


def main():
    ap = argparse.ArgumentParser(description='Groups of look-alike functions (see the docstring).')
    ap.add_argument('--report', type=int, nargs='?', const=30, help='print the biggest groups')
    a = ap.parse_args()
    if a.report:
        report(a.report)
    else:
        group()


if __name__ == '__main__':
    main()
