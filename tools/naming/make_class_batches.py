"""Naming work packets per class: one class (from its vtable) with all its methods and its field layout.

    python tools/naming/make_class_batches.py [--limit 300] [--tokens 9000] [--min-methods 3]

A model sees how the methods of one class use the same fields, which says much more than one function at a
time, and names the class, its fields and its methods together. Writes build/naming/batches/batch_NNNN.md in
the same answer format as make_batches.py (F / C / M lines); merge.py reads the answers.
Order: classes with the most unnamed methods and fields first.
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import names as dictionary  # noqa: E402
import make_batches as mb  # noqa: E402
import scope  # noqa: E402

PROMPT = mb.PROMPT.replace(
    'Each function below is listed with its address',
    'Each packet below is ONE C++ class: its id, its field layout (offset, size, type) and its methods. Name the '
    'class (a C line), the fields you can tell (M lines, offset in hex as shown) and the methods (F lines). Each '
    'method is listed with its address')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--limit', type=int, default=300, help='classes in this round')
    ap.add_argument('--tokens', type=int, default=9000, help='approximate size of one batch')
    ap.add_argument('--max-class', type=int, default=30000, help='skip classes whose packet is larger (characters)')
    ap.add_argument('--min-methods', type=int, default=3)
    ap.add_argument('--out', default=os.path.join(ROOT, 'build', 'naming', 'batches'))
    ap.add_argument('--all-code', action='store_true', help='also library and system classes')
    ap.add_argument('--again', action='store_true', help='also offer classes that earlier rounds already offered')
    args = ap.parse_args()
    cl = json.load(open(os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json'), encoding='utf-8'))
    blocks = mb.load_blocks()
    cat, strings = mb.catalog()
    d = dictionary.load()
    known = dict(cat)
    known.update(d['functions'])
    methods = {}
    for f, c in cl['this'].items():
        methods.setdefault(c, []).append(int(f[4:], 16))
    # classes already offered in an earlier round (a model could not name them then; offer new ones first)
    seen_path = os.path.join(ROOT, 'build', 'naming', 'offered_classes.txt')
    seen = set(open(seen_path).read().split()) if os.path.exists(seen_path) else set()
    for old in glob.glob(os.path.join(ROOT, 'build', 'naming', '*', 'batches', 'batch_*.md')) +             glob.glob(os.path.join(args.out, 'batch_*.md')):
        seen |= set(re.findall(r'^## class id ([0-9A-F]{8})', open(old, encoding='utf-8').read(), re.M))
    order = []
    for key, c in cl['classes'].items():
        if key in seen and not args.again:
            continue
        ms = [a for a in methods.get(key, []) if f'sub_{a:08X}' in blocks]
        if ms and not args.all_code and sum(1 for a in ms if scope.in_game(a)) * 2 < len(ms):
            continue  # (a library or system class: not part of the readable-code work)
        unnamed = [a for a in ms if a not in known]
        v = int(key, 16)
        if len(ms) < args.min_methods or not unnamed or v in d['classes']:
            continue
        order.append((len(unnamed) + len(c['fields']) // 4, key, sorted(ms)))
    order.sort(reverse=True)
    os.makedirs(args.out, exist_ok=True)
    for f in glob.glob(os.path.join(args.out, 'batch_*.md')):
        os.remove(f)

    def label(x):
        return known.get(x) or f'n_sub_{x:08X}'
    batch, size, written, offered, funcs = [], 0, 0, 0, 0
    budget = args.tokens * 4

    def flush():
        nonlocal batch, size, written
        if batch:
            written += 1
            with open(os.path.join(args.out, f'batch_{written:04}.md'), 'w', encoding='utf-8') as f:
                f.write(PROMPT + '\n' + '\n'.join(batch))
            batch, size = [], 0
    for _, key, ms in order:
        if offered >= args.limit:
            break
        c = cl['classes'][key]
        parts = [f'## class id {key}' + (f' (RTTI name {c["name"]})' if not c['name'].startswith('C_') else ''),
                 f'{len(c["vtable"])} virtual functions; constructor/destructor: '
                 + (', '.join(label(int(x[4:], 16)) for x in c['ctors'][:3]) or 'not found'),
                 'fields (offset hex: type):  ' + ',  '.join(f'{int(o):X}: {t.replace("f2::Be<", "").rstrip(">")}'
                                                             for o, (n, t, s) in sorted(c['fields'].items(),
                                                                                         key=lambda x: int(x[0])))]
        for a in ms:
            code = mb.compact(blocks[f'sub_{a:08X}'])
            code = re.sub(r'\bn_sub_([0-9A-F]{8})\b', lambda m: label(int(m.group(1), 16)), code)
            if len(code) > 4000:
                code = code[:4000] + '\n\t... (rest omitted)'
            head = f'### function {a:08X}' + (f'  (already named {known[a]})' if a in known else '')
            if a in strings:
                head += f'\nstrings: {strings[a][:200]}'
            parts.append(head + '\n```cpp\n' + code + '\n```')
        text = '\n'.join(parts) + '\n'
        if len(text) > args.max_class:
            continue
        if size + len(text) > budget:
            flush()
        batch.append(text)
        size += len(text)
        offered += 1
        funcs += len(ms)
    flush()
    with open(seen_path, 'w') as f:
        f.write(chr(10).join(sorted(seen | {k for _, k, _ in order[:offered]})) + chr(10))
    print(f'{len(order)} classes with unnamed methods; offered {offered} classes ({funcs} methods) in {written} '
          f'batches -> {args.out}')


if __name__ == '__main__':
    main()
