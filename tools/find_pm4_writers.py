"""Finds functions in the recompiled code that build PM4 type-3 packet headers (0xC000xx00).

Scans the generated C++ (the original PPC instruction is kept as a comment above each statement)
for header constants built with lis/oris 0xC000 (or -16384) followed by an ori of opcode << 8, and
prints each function with the packet opcodes it writes.

    python tools/find_pm4_writers.py [opcode-hex ...]
"""
import glob
import re
import sys

OPS = {
    0x10: "NOP", 0x3F: "INDIRECT_BUFFER_PFD", 0x37: "INDIRECT_BUFFER", 0x3C: "WAIT_REG_MEM",
    0x3D: "MEM_WRITE", 0x3E: "REG_TO_MEM", 0x45: "COND_WRITE", 0x4F: "MEM_WRITE_CNTR", 0x46: "EVENT_WRITE", 0x58: "EVENT_WRITE_SHD",
    0x59: "EVENT_WRITE_CFL", 0x5A: "EVENT_WRITE_EXT", 0x5B: "EVENT_WRITE_ZPD", 0x54: "INTERRUPT",
    0x64: "XE_SWAP", 0x21: "REG_RMW", 0x22: "DRAW_INDX", 0x36: "DRAW_INDX_2", 0x2D: "SET_CONSTANT",
    0x2F: "LOAD_ALU_CONSTANT", 0x27: "IM_LOAD", 0x2B: "IM_LOAD_IMMEDIATE", 0x3B: "INVALIDATE_STATE",
    0x5E: "CONTEXT_UPDATE", 0x23: "VIZ_QUERY", 0x60: "SET_BIN_MASK_LO", 0x61: "SET_BIN_MASK_HI",
    0x62: "SET_BIN_SELECT_LO", 0x63: "SET_BIN_SELECT_HI", 0x4A: "SET_SHADER_CONSTANTS", 0x48: "ME_INIT",
    0x55: "WAIT_FOR_IDLE",
}

want = {int(a, 16) for a in sys.argv[1:]}
func_re = re.compile(r"^DEFINE_REX_FUNC\((sub_[0-9A-F]+)\)")
hi_re = re.compile(r"// (lis|oris) (r\d+),(?:r\d+,)?(-?\d+)$")
ori_re = re.compile(r"// ori (r\d+),(r\d+),(\d+)$")
results = {}
for path in sorted(glob.glob("Fable2Recomp/generated/Fable2_recomp.*.cpp")):
    func = None
    recent_hi = {}  # register -> line index of the 0xC000 high half
    with open(path, encoding="utf-8", errors="replace") as f:
        for i, line in enumerate(f):
            line = line.strip()
            m = func_re.match(line)
            if m:
                func, recent_hi = m.group(1), {}
                continue
            m = hi_re.match(line)
            if m:
                v = int(m.group(3)) & 0xFFFF
                if v >= 0xC000:  # type-3 header high half (0xC000 | count - 1)
                    recent_hi[m.group(2)] = i
                continue
            m = ori_re.match(line)
            if m and func:
                dst, src, imm = m.group(1), m.group(2), int(m.group(3))
                if src in recent_hi and i - recent_hi[src] < 40 and imm & 0xFF == 0:
                    op = (imm >> 8) & 0x7F
                    if op in OPS and (not want or op in want):
                        results.setdefault(func, set()).add(op)
for func in sorted(results):
    print(func, " ".join(OPS[o] for o in sorted(results[func])))
