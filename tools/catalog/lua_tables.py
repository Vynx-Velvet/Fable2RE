#!/usr/bin/env python3
"""Infer the Lua table each binding registrar fills ("Debug", "GUI", "ScriptFunction", ...) from how
the game's decompiled scripts call the bindings (`Table.Name(` / `Table:Name(`), and write
research/symbols/lua_bindings_named.tsv: function, table, name, registrar.

Usage: python tools/catalog/lua_tables.py   (after tools/find_lua_bindings.py and bnk extraction)
"""
import collections
import csv
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'research', 'symbols', 'lua_bindings.tsv')), delimiter='\t'))
    names = {r['name'] for r in rows}
    usage = collections.defaultdict(collections.Counter)  # binding name -> table counts
    pat = re.compile(r'\b([A-Z][A-Za-z0-9_]*)\s*[.:]\s*([A-Za-z_][A-Za-z0-9_]*)\s*\(')
    for path in glob.glob(os.path.join(ROOT, 'extracted', '**', '*.src.lua'), recursive=True) + \
            glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release', 'assets', 'game',
                                   'data', 'scripts', 'Startup', '*.txt')):
        for table, name in pat.findall(open(path, encoding='latin1').read()):
            if name in names:
                usage[name][table] += 1
    # Registrar -> table by majority over its bindings.
    by_reg = collections.defaultdict(collections.Counter)
    for r in rows:
        for table, n in usage[r['name']].items():
            by_reg[r['registered_by']][table] += n
    reg_table = {reg: c.most_common(1)[0][0] for reg, c in by_reg.items() if c}
    out = os.path.join(ROOT, 'research', 'symbols', 'lua_bindings_named.tsv')
    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('function\ttable\tname\tregistered_by\n')
        for r in rows:
            table = reg_table.get(r['registered_by'], '')
            f.write(f"{r['function']}\t{table}\t{r['name']}\t{r['registered_by']}\n")
    print(f'{len(rows)} bindings; registrar tables:')
    for reg, t in sorted(reg_table.items(), key=lambda kv: -sum(by_reg[kv[0]].values()))[:40]:
        print(f'  {reg} -> {t}  ({dict(by_reg[reg].most_common(3))})')


if __name__ == '__main__':
    main()
