#!/usr/bin/env python3
"""Find recompiled functions that reference guest addresses (data/constant pools).

Scans Fable2Recomp/generated/Fable2_recomp.*.cpp; inside each function every
`ctx.rN.s64 = <lis value>;` is paired with every `ctx.rM.{s64,u32} + <off>` in the
same function (any register), so lis/addi and lis/lfs pairs are found even when
the pool base lives in a callee-saved register for the whole function.

Usage: python tools/find_addr_refs.py 0x8209be64 0x8209be60 [--any]
  default: print functions referencing ALL given addresses; --any: at least one.
"""
import glob, re, sys, os

def main(argv):
    want_any = "--any" in argv
    addrs = [int(a, 16) for a in argv if not a.startswith("--")]
    gen = os.path.join(os.path.dirname(__file__), "..", "Fable2Recomp", "generated", "Fable2_recomp.*.cpp")
    lis_re = re.compile(r"ctx\.r\d+\.s64 = (-?\d+);")
    off_re = re.compile(r"ctx\.r\d+\.(?:s64|u32) \+ (-?\d+)[;)]")
    for f in sorted(glob.glob(gen)):
        txt = open(f, encoding="utf-8", errors="replace").read()
        parts = txt.split("\nDEFINE_REX_FUNC(")
        for p in parts[1:]:
            name = p.split(")", 1)[0]
            lis = {int(v) & 0xFFFFFFFF for v in lis_re.findall(p) if (int(v) & 0xFFFF) == 0 and (int(v) & 0xFFFFFFFF) >> 24 == 0x82 or (int(v) & 0xFFFFFFFF) >> 24 == 0x83}
            if not lis:
                continue
            offs = [int(o) for o in off_re.findall(p)]
            have = {(l + o) & 0xFFFFFFFF for l in lis for o in offs}
            hit = [a for a in addrs if a in have]
            if (want_any and hit) or (not want_any and len(hit) == len(addrs)):
                print(f"{name:14s} {os.path.basename(f):24s} refs={' '.join(f'{a:08x}' for a in hit)}")

if __name__ == "__main__":
    main(sys.argv[1:])
