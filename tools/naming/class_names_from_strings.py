"""Class names the game states itself: many classes (all the CEC... entity components) have a small virtual
method that builds a string object from the class's own name ("CECPlayer"). Finds those methods in the lifted
code and writes dictionary answers (C and F lines) for tools/naming/merge.py.

    python tools/naming/class_names_from_strings.py [--out build/naming/classname_import]
    python tools/naming/merge.py --answers build/naming/classname_import

A method qualifies when it is in a class's vtable, references exactly one string, that string looks like a
class name (C + capital), and its only call constructs a string object from it. A name that would go to two
classes (an inherited method) is not used. 2026-10-05: 260 classes, 80 of them agreeing with names a model gave.
"""
import argparse
import collections
import glob
import json
import os
import re

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=os.path.join(ROOT, 'build', 'naming', 'classname_import'))
    a = ap.parse_args()
    cl = json.load(open(os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json'), encoding='utf-8'))
    blocks = {}
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        for b in open(f, encoding='utf-8').read().split('// @lift ')[1:]:
            blocks[b.split('\n', 1)[0].strip()] = b
    owners = collections.defaultdict(set)
    for k, c in cl['classes'].items():
        for fn in c['vtable']:
            owners[fn].add(k)
    cands, fns = collections.defaultdict(set), {}
    for fn, keys in owners.items():
        b = blocks.get(fn)
        if not b or len(b) > 2500:
            continue
        body = b.split(') {\n', 1)[-1]
        body = re.split(r'\n(?:CPU_STATE_ENTRY|F2_LIFTED)\(', body)[0]
        strs = re.findall(r'constexpr int32_t str_\w+ = int32_t\(0x[0-9A-F]+\);  // "([^"]*)"', body)
        calls = {c for c in re.findall(r'\b([A-Za-z_]\w*)\(ctx, base', body) if not c.endswith('_original')}
        if len(strs) != 1 or not re.fullmatch(r'C[A-Z][A-Za-z0-9_]{2,60}', strs[0]):
            continue
        if len(calls) != 1 or 'ConstructFromCStr' not in next(iter(calls)):
            continue
        for k in keys:
            cands[k].add(strs[0])
        fns[fn] = strs[0]
    by_name = collections.defaultdict(set)
    for k, ns in cands.items():
        if len(ns) == 1:
            by_name[next(iter(ns))].add(k)
    unique = {n: next(iter(ks)) for n, ks in by_name.items() if len(ks) == 1}
    out = [f'C\t{k}\t{n}\thigh\tIts own name method returns the string {n}, the name the game gives the class.'
           for n, k in sorted(unique.items())]
    out += [f'F\t{fn[4:]}\t{n}_GetClassName\thigh\tReturns the class name string {n} as a string object.'
            for fn, n in sorted(fns.items()) if n in unique]
    os.makedirs(a.out, exist_ok=True)
    with open(os.path.join(a.out, 'classnames.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(out) + '\n')
    print(f'{len(fns)} name methods, {len(unique)} classes -> {a.out}')


if __name__ == '__main__':
    main()
