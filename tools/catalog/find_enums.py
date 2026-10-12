#!/usr/bin/env python3
"""Recover the C++ enums Fable II exports to Lua (ETrackedStatType, ECreatureType, EInputKey, ...)
from static {const char* name, int value} tables in the data sections.

Writes research/symbols/enums.tsv (enum table address, value, name) and prints the tables found.
Usage: python tools/catalog/find_enums.py [prefix filter]
"""
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
BASE = 0x82000000
CODE = (0x82170000, 0x832C2A3C)


def main(argv):
    img = open(os.path.join(ROOT, 'research', 'decomp', 'default_image.bin'), 'rb').read()
    n = len(img) // 4
    words = struct.unpack(f'>{n}I', img[:n * 4])

    def ident(a):
        o = a - BASE
        if not (0 <= o < len(img)) or CODE[0] <= a < CODE[1]:
            return None
        e = img.find(b'\0', o, o + 128)
        if e <= o:
            return None
        s = img[o:e]
        return s.decode() if re.fullmatch(rb'[A-Z][A-Z0-9_]{2,100}', s) else None

    tables = []
    i = 0
    while i < n - 3:
        a = BASE + i * 4
        if CODE[0] <= a < CODE[1]:
            i = (CODE[1] - BASE) // 4
            continue
        run = []
        j = i
        while j < n - 1 and ident(words[j]) and words[j + 1] < 0x10000:
            run.append((ident(words[j]), words[j + 1]))
            j += 2
        if len(run) >= 3:
            tables.append((a, run))
            i = j
        else:
            i += 1
    flt = argv[0] if argv else ''
    out = os.path.join(ROOT, 'research', 'symbols', 'enums.tsv')
    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('table\tvalue\tname\n')
        for a, run in tables:
            for name, v in run:
                f.write(f'{a:08X}\t{v}\t{name}\n')
    print(f'{len(tables)} enum tables, {sum(len(r) for _, r in tables)} values -> {out}')
    for a, run in tables:
        if flt and not any(name.startswith(flt) for name, _ in run):
            continue
        print(f'{a:08X} x{len(run):4d}: ' + ', '.join(f'{nm}={v}' for nm, v in run[:12]))


if __name__ == '__main__':
    main(sys.argv[1:])
