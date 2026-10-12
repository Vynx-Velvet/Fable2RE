#!/usr/bin/env python3
"""Map Fable II's Lua bindings to the C++ functions behind them.

The game registers its C functions with LuaPlus through small helpers called as
helper(r3 = table/state, r4 = "Name" string, r5 = function address). This scans the recompiled code
(the original PowerPC is kept as `// insn` comments) for calls where r4 was just set to a string
and r5 to a function start, and records the table being filled when the same registration function
also names it (e.g. "Debug", "PhysicsCharacter").

Output: research/symbols/lua_bindings.tsv  (function, name, registered by, string address)
Usage: python tools/find_lua_bindings.py <decrypted image.bin>
"""
import glob
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GEN = os.path.join(ROOT, 'Fable2Recomp', 'generated')
BASE = 0x82000000

RE_FUNC = re.compile(r'^DEFINE_REX_FUNC\((\w+)\)')
RE_ASM = re.compile(r'^\s*// (\w+\.?)\s+(.*)$')


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def main(argv):
    img = open(argv[0], 'rb').read()
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    starts = {int(k, 16) for k in db}

    def cstr(a):
        o = a - BASE
        if not (0 <= o < len(img)):
            return None
        e = img.find(b'\0', o, o + 128)
        if e < 0:
            return None
        s = img[o:e]
        if 2 <= len(s) and all(32 <= c < 127 for c in s) and re.match(rb'^[A-Za-z_][A-Za-z0-9_]*$', s):
            return s.decode()
        return None

    out = []
    for path in sorted(glob.glob(os.path.join(GEN, 'Fable2_recomp.*.cpp'))):
        func = None
        regs = {}
        for line in open(path, encoding='utf-8', errors='replace'):
            m = RE_FUNC.match(line)
            if m:
                func, regs = m.group(1), {}
                continue
            m = RE_ASM.match(line)
            if not m or func is None:
                continue
            op, args = m.group(1), m.group(2).replace(' ', '')
            a = args.split(',')
            try:
                if op == 'lis' and len(a) == 2:
                    regs[a[0]] = (int(a[1], 0) << 16) & 0xFFFFFFFF
                elif op == 'addi' and len(a) == 3:
                    if a[1] in regs and regs[a[1]] is not None:
                        regs[a[0]] = (regs[a[1]] + s16(int(a[2], 0) & 0xFFFF)) & 0xFFFFFFFF
                    else:
                        regs[a[0]] = None
                elif op == 'ori' and len(a) == 3 and a[1] in regs and regs[a[1]] is not None:
                    regs[a[0]] = regs[a[1]] | (int(a[2], 0) & 0xFFFF)
                elif op in ('bl', 'b'):
                    r4, r5 = regs.get('r4'), regs.get('r5')
                    if r4 is not None and r5 is not None and r5 in starts:
                        name = cstr(r4)
                        if name:
                            out.append((r5, name, func, r4))
                    if op == 'bl':
                        for r in ('r3', 'r4', 'r5', 'r6', 'r7', 'r8', 'r9', 'r10', 'r11', 'r12'):
                            regs.pop(r, None)
                elif a and re.match(r'^r\d+$', a[0]) and op not in ('stw', 'stb', 'sth', 'std', 'stwu', 'cmpw',
                                                                     'cmplw', 'cmpwi', 'cmplwi', 'stfs', 'stfd'):
                    regs.pop(a[0], None)
            except ValueError:
                pass
    seen = set()
    rows = []
    for fn, name, by, sa in out:
        key = (fn, name)
        if key in seen:
            continue
        seen.add(key)
        rows.append((fn, name, by, sa))
    rows.sort()
    dst = os.path.join(ROOT, 'research', 'symbols', 'lua_bindings.tsv')
    with open(dst, 'w', encoding='utf-8', newline='\n') as f:
        f.write('function\tname\tregistered_by\tstring\n')
        for fn, name, by, sa in rows:
            f.write(f'{fn:08X}\t{name}\t{by}\t{sa:08X}\n')
    print(f'{len(rows)} bindings -> {dst}')


if __name__ == '__main__':
    main(sys.argv[1:])
