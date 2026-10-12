#!/usr/bin/env python3
"""Find guest code that the recompiler never emitted: words between emitted functions
that decode as PPC code, split into functions by following branches.

Usage:
  python tools/find_gap_functions.py <decrypted image.bin> [--toml]

Inputs: research/symbols/func_db.json (tools/build_func_db.py over the generated tree)
and Fable2Recomp/Fable2_config.toml (existing [functions] entries).
Prints each candidate (start, size, first words, whether an existing config entry is
undersized). With --toml prints `[functions]` lines to paste into the config.

Candidates whose branches leave the chunk for anything other than a known function start
(conditional branches included; codegen emits conditional tail calls)
are reported as fragments of a neighbouring function and are not emitted.

A function ends at blr / bctr / unconditional b once no earlier branch inside it jumps
past that point (so conditional early-outs are kept inside).
"""
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = 0x82000000

# Regions the runtime/codegen handle specially (not ordinary functions).
SKIP = [
    (0x82CA2BB0, 0x82CA2C54),  # __savegprlr / __restgprlr helpers
    (0x82CA74D0, 0x82CA7568),  # __savefpr / __restfpr helpers
    (0x82CBB968, 0x82CBBB34),  # import-pointer pair + xstart (named, emitted separately)
    (0x82FFFCD0, 0x83000200),  # __savevmx / __restvmx helpers
    (0x83000200, 0x830004D0),  # setjmp (manifest setjmp_address) and its asm neighbours
    (0x832B21FC, 0x832B3600),  # kernel import thunks
]


def load(argv):
    img = open(argv[0], 'rb').read()
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    cfg = open(os.path.join(ROOT, 'Fable2Recomp', 'Fable2_config.toml'), encoding='utf-8').read()
    entries = {}
    for m in re.finditer(r'^(0x[0-9A-Fa-f]+)\s*=\s*\{([^}]*)\}', cfg, re.M):
        size = re.search(r'size\s*=\s*(0x[0-9A-Fa-f]+|\d+)', m.group(2))
        entries[int(m.group(1), 16)] = int(size.group(1), 0) if size else None
    return img, db, entries


def word(img, a):
    return struct.unpack('>I', img[a - BASE:a - BASE + 4])[0]


def sext(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def chunk_end(img, start, limit):
    """End address (exclusive) of the function starting at `start`, or None."""
    a, far = start, start
    while a < limit:
        w = word(img, a)
        if w == 0:
            return None
        op = w >> 26
        if op == 18:  # b / bl
            tgt = (sext(w & 0x03FFFFFC, 26) + (0 if w & 2 else a)) & 0xFFFFFFFF
            if not (w & 1):  # unconditional b without link
                if start <= tgt < limit and tgt > far:
                    far = tgt
                elif a >= far:
                    return a + 4
        elif op == 16:  # bc
            tgt = (sext(w & 0xFFFC, 16) + (0 if w & 2 else a)) & 0xFFFFFFFF
            if start <= tgt < limit:
                far = max(far, tgt)
        elif w in (0x4E800020, 0x4E800420) and a >= far:  # blr / bctr
            return a + 4
        a += 4
    return None


def outside_targets(img, start, size):
    """Branch targets that leave [start, start+size): (address, is_conditional)."""
    res = []
    for a in range(start, start + size, 4):
        w = word(img, a)
        op = w >> 26
        if op == 18:
            tgt = (sext(w & 0x03FFFFFC, 26) + (0 if w & 2 else a)) & 0xFFFFFFFF
            cond = False
        elif op == 16:
            tgt = (sext(w & 0xFFFC, 16) + (0 if w & 2 else a)) & 0xFFFFFFFF
            cond = True
        else:
            continue
        if not (start <= tgt < start + size):
            res.append((tgt, cond))
    return res


def main(argv):
    img, db, entries = load(argv)
    funcs = sorted((int(k, 16), int(v['end'], 16)) for k, v in db.items())
    out = []
    for (s, e), (nxt, _) in zip(funcs, funcs[1:]):
        a = e
        while a < nxt:
            while a < nxt and word(img, a) in (0, 0x4E800020) and a not in entries:
                a += 4  # padding, and the db's end address stops before the final blr
            if a >= nxt or any(lo <= a < hi for lo, hi in SKIP):
                break
            end = chunk_end(img, a, nxt)
            if end is None:
                break
            out.append((a, end - a))
            a = end
    # Undersized config entries: entry + size lands on a candidate that continues it.
    starts = {a for a, _ in out}
    fixes = {}
    for a, size in entries.items():
        if size and a + size in starts:
            end = chunk_end(img, a, a + 0x1000)
            if end and end > a + size:
                fixes[a] = end - a
    known = {f for f, _ in funcs} | set(entries) | starts
    imports = (0x832B21FC, 0x832B3600)
    fragments = set()
    for a, size in out:
        for tgt, cond in outside_targets(img, a, size):
            # codegen turns (conditional) branches to a known function start into tail calls
            if tgt not in known and not imports[0] <= tgt < imports[1]:
                fragments.add(a)
    toml = '--toml' in argv
    if toml:
        print('# Gap functions: code between emitted functions with no .pdata entry,')
        print('# found by tools/find_gap_functions.py (2026-10-02).')
    for a, size in out:
        if any(fa < a < fa + fs for fa, fs in fixes.items()):
            continue  # absorbed by a corrected existing entry
        words = ' '.join('%08X' % word(img, x) for x in range(a, a + min(size, 16), 4))
        if a in fragments:
            bad = ' '.join('%08X' % t for t, _ in outside_targets(img, a, size))
            print('%sfragment %08X size 0x%X: branches to non-function %s (part of a neighbour; not added)'
                  % ('# ' if toml else '', a, size, bad))
            continue
        if toml:
            print('0x%08X = { size = 0x%X }  # %s' % (a, size, words))
        else:
            print('new   %08X size 0x%-4X %s' % (a, size, words))
    for a, size in sorted(fixes.items()):
        if toml:
            print('# fix existing entry: 0x%08X size 0x%X -> 0x%X' % (a, entries[a], size))
        else:
            print('fix   %08X size 0x%X -> 0x%X' % (a, entries[a], size))


if __name__ == '__main__':
    main(sys.argv[1:])
