#!/usr/bin/env python3
"""Find luaL_Reg-style arrays in Fable II's data: runs of {const char* name, function*} pairs
(8 bytes each, big-endian) - Lua bindings that are registered from static tables rather than one
call per function (missed by tools/find_lua_bindings.py).

Adds rows to research/symbols/lua_bindings.tsv (registered_by = "array@ADDRESS") and prints the
arrays found with their first names.
Usage: python tools/catalog/find_lua_reg_arrays.py
"""
import csv
import json
import os
import re
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
BASE = 0x82000000
CODE = (0x82170000, 0x832C2A3C)


def main():
    img = open(os.path.join(ROOT, 'research', 'decomp', 'default_image.bin'), 'rb').read()
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    starts = {int(k, 16) for k in db}

    def ident(a):
        o = a - BASE
        if not (0 <= o < len(img)) or CODE[0] <= a < CODE[1]:
            return None
        e = img.find(b'\0', o, o + 96)
        if e <= o:
            return None
        s = img[o:e]
        return s.decode() if re.fullmatch(rb'[A-Za-z_][A-Za-z0-9_]{1,80}', s) else None

    arrays = []
    n = len(img) // 4
    words = struct.unpack(f'>{n}I', img[:n * 4])
    i = 0
    while i < n - 1:
        a = BASE + i * 4
        if CODE[0] <= a < CODE[1]:
            i = (CODE[1] - BASE) // 4
            continue
        run = []
        j = i
        while j < n - 1 and ident(words[j]) and words[j + 1] in starts:
            run.append((ident(words[j]), words[j + 1], BASE + j * 4))
            j += 2
        if len(run) >= 2:
            arrays.append(run)
            i = j
        else:
            i += 1
    path = os.path.join(ROOT, 'research', 'symbols', 'lua_bindings.tsv')
    rows = list(csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'))
    have = {(r['function'], r['name']) for r in rows}
    added = 0
    for run in arrays:
        tag = f'array@{run[0][2]:08X}'
        for name, fn, at in run:
            key = (f'{fn:08X}', name)
            if key in have:
                continue
            rows.append({'function': f'{fn:08X}', 'name': name, 'registered_by': tag, 'string': f'{words[(at - BASE) // 4]:08X}'})
            have.add(key)
            added += 1
    rows.sort(key=lambda r: r['function'])
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write('function\tname\tregistered_by\tstring\n')
        for r in rows:
            f.write(f"{r['function']}\t{r['name']}\t{r['registered_by']}\t{r['string']}\n")
    print(f'{len(arrays)} arrays, {sum(len(r) for r in arrays)} pairs, {added} new bindings')
    for run in sorted(arrays, key=len, reverse=True)[:30]:
        print(f'  {run[0][2]:08X} x{len(run):3d}: ' + ', '.join(n for n, _, _ in run[:8]))


if __name__ == '__main__':
    main()
