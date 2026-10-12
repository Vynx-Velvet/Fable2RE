#!/usr/bin/env python3
"""
Find functions the codegen missed, by scanning the mapped XEX image for code
addresses that the generated mapping table does not know about.

Two sources are checked:
  1. Pointers in the data/rdata regions (vtables, callback tables): every big-endian
     32-bit word in [0x82000000,0x82170000) and [code_end, image_end) that lands in the
     code range.
  2. lis/addi (and lis/ori) pairs in code that compute a code address at least 4 KB
     away from the instruction (near ones are inline SEH scope tables / labels).

A candidate is reported only if it looks like a function start: the previous word is
blr / bctr / b / padding, its first word is not an embedded pointer, and a terminator
(blr / bctr / b) follows within 2 KB. Output is TOML lines for [functions].

Candidates that fall inside an already-emitted function are rejected: an address that is a
`loc_` label, or lies between a function's base and its highest label, in the generated tree
is a fall-through/switch-case block, not a function (splitting there plants
REX_FATAL landmines, as regen #5/#6 showed on 2026-09-28).

Usage:
  python tools/find_missing_functions.py <image.bin> <generated_dir> [<config.toml>]
"""
import glob
import os
import re
import struct
import sys
from bisect import bisect_right

BASE = 0x82000000
CODE_LO = 0x82170000
CODE_HI = 0x832C2A3C
IMG_END = 0x83620000


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        sys.exit(1)
    img = open(sys.argv[1], "rb").read()
    gen_dir = sys.argv[2]
    init_cpp = gen_dir if gen_dir.endswith(".cpp") else os.path.join(gen_dir, "Fable2_init.cpp")
    regs = set(int(m, 16) for m in re.findall(r"\{ 0x([0-9A-F]{8}),", open(init_cpp).read()))

    # Function extents from the generated tree: base -> highest loc_ label inside it.
    extent = {}
    if os.path.isdir(gen_dir):
        fn_pat = re.compile(r"^DEFINE_REX_FUNC\(sub_([0-9A-F]{8})\)", re.M)
        lab_pat = re.compile(r"^loc_([0-9A-F]{8}):", re.M)
        for f in glob.glob(os.path.join(gen_dir, "Fable2_recomp.*.cpp")):
            txt = open(f, encoding="utf-8", errors="ignore").read()
            fns = [(m.start(), int(m.group(1), 16)) for m in fn_pat.finditer(txt)] + [(len(txt), None)]
            for (s, base), (e, _) in zip(fns, fns[1:]):
                mx = base
                for m in lab_pat.finditer(txt[s:e]):
                    a = int(m.group(1), 16)
                    if mx < a < base + 0x100000:
                        mx = a
                extent[base] = mx
    bases = sorted(extent)

    def inside_existing(t):
        j = bisect_right(bases, t) - 1
        return j >= 0 and bases[j] < t <= extent[bases[j]]
    cfg = set()
    if len(sys.argv) > 3:
        cfg = set(int(m, 16) for m in re.findall(r"^0x([0-9A-Fa-f]{8})\s*=", open(sys.argv[3]).read(), re.M))

    def w(a):
        return struct.unpack_from(">I", img, a - BASE)[0]

    def prev_ok(t):
        p = w(t - 4)
        return p in (0x4E800020, 0x4E800420, 0, 0x60000000) or ((p >> 26) == 18 and (p & 1) == 0)

    def looks_data(v):
        return 0x82000000 <= v < 0x83700000 or v == 0

    def size_to_term(t, limit=0x800):
        a = t
        while a - t < limit:
            v = w(a)
            if v in (0x4E800020, 0x4E800420) or ((v >> 26) == 18 and (v & 1) == 0):
                return a + 4 - t
            a += 4
        return 0

    found = {}
    for lo, hi in ((BASE, CODE_LO), (CODE_HI & ~3, IMG_END)):
        for a in range(lo, hi, 4):
            v = w(a)
            if CODE_LO <= v < CODE_HI and (v & 3) == 0:
                found.setdefault(v, []).append(("ptr", a))

    lis = {}
    for a in range(CODE_LO, CODE_HI, 4):
        v = w(a)
        op = v >> 26
        if op == 15 and ((v >> 16) & 31) == 0:
            lis[(v >> 21) & 31] = ((v & 0xFFFF) << 16, a)
            continue
        t = None
        if op == 14:
            ra = (v >> 16) & 31
            if ra != 0 and ra in lis:
                lo = v & 0xFFFF
                if lo & 0x8000:
                    lo -= 0x10000
                t = (lis[ra][0] + lo) & 0xFFFFFFFF
        elif op == 24:
            ra = (v >> 16) & 31
            if ra in lis:
                t = lis[ra][0] | (v & 0xFFFF)
        if t is not None and CODE_LO <= t < CODE_HI and (t & 3) == 0 and abs(a - t) >= 0x1000:
            found.setdefault(t, []).append(("lis", a))
        if op in (32, 33, 34, 35, 40, 41, 42, 43, 58, 31, 7, 8, 12, 13):
            lis.pop((v >> 21) & 31, None)

    out = []
    for t in sorted(found):
        if t in regs or t in cfg:
            continue
        if not prev_ok(t) or looks_data(w(t)) or inside_existing(t):
            continue
        sz = size_to_term(t)
        if not sz:
            continue
        kind, ref = found[t][0]
        out.append(f"0x{t:08X} = {{ size = 0x{sz:X} }}  # {kind} ref at {ref:08X} (+{len(found[t]) - 1}), first insn {w(t):08X}")
    print("\n".join(out))
    print(f"# {len(out)} candidates", file=sys.stderr)


if __name__ == "__main__":
    main()
