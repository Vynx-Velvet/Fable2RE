#!/usr/bin/env python3
"""Record conversion status of game functions in research/catalog/converted.tsv.

Usage: python tools/convert/mark.py <status> <module path> <address> [<address> ...]
  status: draft | rewritten | verified
  e.g. python tools/convert/mark.py rewritten Fable2Recomp/src/game/combat/health.cpp 8268BD90
Rebuild the catalog afterwards (tools/catalog/build_catalog.py) to see it in functions.tsv/summary.md.
"""
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PATH = os.path.join(ROOT, 'research', 'catalog', 'converted.tsv')
csv.field_size_limit(10 ** 8)


def main(argv):
    if len(argv) < 3 or argv[0] not in ('draft', 'rewritten', 'verified'):
        print(__doc__)
        return 1
    status, module, addrs = argv[0], argv[1], [a.upper().replace('0X', '') for a in argv[2:]]
    names = {}
    for r in csv.DictReader(open(os.path.join(ROOT, 'research', 'catalog', 'functions.tsv'), encoding='utf-8'),
                            delimiter='\t', quoting=csv.QUOTE_NONE):
        if r.get('address'):
            names[r['address']] = r['name']
    conv = {}
    if os.path.exists(PATH):
        for r in csv.DictReader(open(PATH, encoding='utf-8'), delimiter='\t'):
            conv[r['address']] = r
    for a in addrs:
        conv[a] = {'address': a, 'name': names.get(a, f'sub_{a}'), 'status': status, 'module': module}
    with open(PATH, 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tname\tstatus\tmodule\n')
        for a in sorted(conv):
            r = conv[a]
            f.write(f"{a}\t{r['name']}\t{r['status']}\t{r['module']}\n")
    print(f'{len(addrs)} functions marked {status}')
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
