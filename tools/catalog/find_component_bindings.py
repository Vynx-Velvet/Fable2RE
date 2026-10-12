#!/usr/bin/env python3
"""Find Lua component-method bindings registered as
    pcStack_NN = <function>;  String(&a, "<Method>");  String(&b, "<Table>");  helper(..., a, b, fn)
(e.g. Health.Modify -> sub_8268BD90) by reading the named decompilation (research/decomp/named), and
add them to research/symbols/lua_bindings_named.tsv (function, table, name, registered_by).

The table is the string repeated across the function's registrations; the other is the method.
Usage: python tools/catalog/find_component_bindings.py
"""
import collections
import csv
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
NAMED = os.path.join(ROOT, 'research', 'decomp', 'named')
OUT = os.path.join(ROOT, 'research', 'symbols', 'lua_bindings_named.tsv')

FUNC_RE = re.compile(r'^// ---- (\S+) @ ([0-9A-F]{8})')
FNPTR_RE = re.compile(r'^\s*\w+Stack_\w+ = (?:\(code \*\))?&?(sub_[0-9A-F]{8}|[A-Za-z_]\w*);')
STR_RE = re.compile(r'^\s*sub_8222CF18\(\w+,"([A-Za-z_]\w*)",')


def main():
    found = []
    for path in sorted(glob.glob(os.path.join(NAMED, 'decomp_*.c'))):
        func = None
        pending_fn, strings, regs = None, [], []
        for line in open(path, encoding='utf-8'):
            m = FUNC_RE.match(line)
            if m:
                if func and len(regs) >= 2:
                    found.extend(analyse(func, regs))
                func, pending_fn, strings, regs = (m.group(1), m.group(2)), None, [], []
                continue
            m = FNPTR_RE.match(line)
            if m:
                pending_fn, strings = m.group(1), []
                continue
            m = STR_RE.match(line)
            if m and pending_fn:
                strings.append(m.group(1))
                if len(strings) == 2:
                    regs.append((pending_fn, strings[0], strings[1]))
                    pending_fn, strings = None, []
        if func and len(regs) >= 2:
            found.extend(analyse(func, regs))
    # Resolve function names to addresses via the catalog.
    cat = {}
    csv.field_size_limit(10 ** 8)
    for r in csv.DictReader(open(os.path.join(ROOT, 'research', 'catalog', 'functions.tsv'), encoding='utf-8'),
                            delimiter='\t', quoting=csv.QUOTE_NONE):
        if r.get('address'):
            cat[r['name']] = r['address']
    rows = list(csv.DictReader(open(OUT, encoding='utf-8'), delimiter='\t'))
    have = {(r['function'], r['table'], r['name']) for r in rows}
    added = 0
    for fn, table, name, reg in found:
        addr = fn[4:] if fn.startswith('sub_') else cat.get(fn)
        if not addr:
            continue
        key = (addr, table, name)
        if key in have:
            continue
        rows.append({'function': addr, 'table': table, 'name': name, 'registered_by': reg})
        have.add(key)
        added += 1
    rows.sort(key=lambda r: (r['function'], r['table'], r['name']))
    with open(OUT, 'w', encoding='utf-8', newline='\n') as f:
        f.write('function\ttable\tname\tregistered_by\n')
        for r in rows:
            f.write(f"{r['function']}\t{r['table']}\t{r['name']}\t{r['registered_by']}\n")
    tables = collections.Counter(t for _, t, _, _ in found)
    print(f'{len(found)} component bindings ({added} new) in {len(tables)} tables')
    print(', '.join(f'{t}:{n}' for t, n in tables.most_common(60)))


def analyse(func, regs):
    counts = collections.Counter()
    for _, a, b in regs:
        counts[a] += 1
        counts[b] += 1
    out = []
    for fn, a, b in regs:
        table, name = (a, b) if counts[a] > counts[b] else (b, a)
        out.append((fn, table, name, f'sub_{func[1]}'))
    return out


if __name__ == '__main__':
    main()
