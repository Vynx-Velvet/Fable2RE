"""Build a function database from the rexglue-generated C++ (which keeps the
original PowerPC disassembly as `// insn` comments).

For every guest function it records:
  - callees (bl targets, including tail-call `b` to other functions)
  - kernel/XAM imports called (__imp__Name)
  - 32-bit constants materialised with lis + ori/addi (per register)
  - PM4 packet headers among those constants (type 0 register writes, type 3 opcodes)
  - load/store displacements used off each base register (to spot struct fields)

Usage:
  python tools/build_func_db.py [generated_dir] [out.json]
Default out: research/symbols/func_db.json
"""
import json
import os
import re
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GEN = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'Fable2Recomp', 'generated')
OUT = sys.argv[2] if len(sys.argv) > 2 else os.path.join(ROOT, 'research', 'symbols', 'func_db.json')

RE_FUNC = re.compile(r'^DEFINE_REX_FUNC\((sub_[0-9A-F]{8}|\w+)\)\s*\{')
RE_LABEL = re.compile(r'^loc_([0-9A-F]{8}):')
RE_ASM = re.compile(r'^\s*// (\S+)\s*(.*)$')
RE_CALL = re.compile(r'^\s*(__imp__)?(sub_[0-9A-F]{8}|__imp__\w+|\w+)\(ctx, base\);')
RE_IMP = re.compile(r'__imp__([A-Za-z_]\w*)\(ctx, base\)')
RE_SUB = re.compile(r'\bsub_([0-9A-F]{8})\(ctx, base\)')

PM4_T3 = {
    0x48: 'ME_INIT', 0x10: 'NOP', 0x3f: 'INDIRECT_BUFFER', 0x37: 'INDIRECT_BUFFER_PFD',
    0x26: 'WAIT_FOR_IDLE', 0x3c: 'WAIT_REG_MEM', 0x52: 'WAIT_REG_EQ', 0x53: 'WAIT_REG_GTE',
    0x5c: 'WAIT_UNTIL_READ', 0x5d: 'WAIT_IB_PFD_COMPLETE', 0x21: 'REG_RMW', 0x3e: 'REG_TO_MEM',
    0x3d: 'MEM_WRITE', 0x4f: 'MEM_WRITE_CNTR', 0x44: 'COND_EXEC', 0x45: 'COND_WRITE',
    0x46: 'EVENT_WRITE', 0x58: 'EVENT_WRITE_SHD', 0x59: 'EVENT_WRITE_CFL', 0x5a: 'EVENT_WRITE_EXT',
    0x5b: 'EVENT_WRITE_ZPD', 0x22: 'DRAW_INDX', 0x36: 'DRAW_INDX_2', 0x34: 'DRAW_INDX_BIN',
    0x35: 'DRAW_INDX_2_BIN', 0x23: 'VIZ_QUERY', 0x25: 'SET_STATE', 0x2d: 'SET_CONSTANT',
    0x55: 'SET_CONSTANT2', 0x56: 'SET_SHADER_CONSTANTS', 0x2f: 'LOAD_ALU_CONSTANT',
    0x27: 'IM_LOAD', 0x2b: 'IM_LOAD_IMMEDIATE', 0x2e: 'LOAD_CONSTANT_CONTEXT',
    0x3b: 'INVALIDATE_STATE', 0x4a: 'SET_SHADER_BASES', 0x4b: 'SET_BIN_BASE_OFFSET',
    0x50: 'SET_BIN_MASK', 0x51: 'SET_BIN_SELECT', 0x5e: 'CONTEXT_UPDATE', 0x54: 'INTERRUPT',
    0x2c: 'IM_STORE', 0x60: 'SET_BIN_MASK_LO', 0x61: 'SET_BIN_MASK_HI',
    0x62: 'SET_BIN_SELECT_LO', 0x63: 'SET_BIN_SELECT_HI',
}


def s16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def parse_imm(tok):
    tok = tok.strip()
    return int(tok, 0)


def classify_pm4(v):
    t = v >> 30
    if t == 3:
        op = (v >> 8) & 0x7F
        if op in PM4_T3 and (v & 0xFF) == 0 and ((v >> 16) & 0x3FFF) < 0x400:
            return 'T3:%s' % PM4_T3[op]
    return None


def main():
    funcs = {}
    files = sorted(f for f in os.listdir(GEN) if f.startswith('Fable2_recomp.') and f.endswith('.cpp'))
    for fn in files:
        cur = None
        addr = 0
        regs = {}
        with open(os.path.join(GEN, fn), encoding='utf-8', errors='replace') as fh:
            for lineno, line in enumerate(fh, 1):
                m = RE_FUNC.match(line)
                if m:
                    name = m.group(1)
                    if not name.startswith('sub_'):
                        cur = None
                        continue
                    addr = int(name[4:], 16)
                    cur = {
                        'addr': addr, 'file': fn, 'line': lineno, 'ninsn': 0,
                        'calls': set(), 'imports': set(), 'consts': set(), 'pm4': defaultdict(int),
                        'offsets': defaultdict(set), 'end': addr,
                    }
                    funcs[addr] = cur
                    regs = {}
                    continue
                if cur is None:
                    continue
                if line.startswith('}'):
                    cur = None
                    continue
                m = RE_LABEL.match(line)
                if m:
                    addr = int(m.group(1), 16)
                    regs = {}
                    continue
                m = RE_ASM.match(line)
                if m:
                    op, args = m.group(1), m.group(2)
                    cur['ninsn'] += 1
                    cur['end'] = max(cur['end'], addr + 4)
                    addr += 4
                    a = [x.strip() for x in args.split(',')]
                    try:
                        if op == 'lis' and len(a) == 2:
                            regs[a[0]] = (parse_imm(a[1]) & 0xFFFF) << 16
                        elif op == 'li' and len(a) == 2:
                            regs[a[0]] = parse_imm(a[1]) & 0xFFFFFFFF
                        elif op in ('ori', 'oris') and len(a) == 3 and a[1] in regs:
                            imm = parse_imm(a[2]) & 0xFFFF
                            v = regs[a[1]] | (imm << 16 if op == 'oris' else imm)
                            regs[a[0]] = v & 0xFFFFFFFF
                            cur['consts'].add(regs[a[0]])
                            k = classify_pm4(regs[a[0]])
                            if k:
                                cur['pm4'][k] += 1
                        elif op == 'addi' and len(a) == 3 and a[1] in regs and a[1] != 'r1':
                            v = (regs[a[1]] + parse_imm(a[2])) & 0xFFFFFFFF
                            regs[a[0]] = v
                            cur['consts'].add(v)
                            k = classify_pm4(v)
                            if k:
                                cur['pm4'][k] += 1
                        else:
                            if a and re.fullmatch(r'r\d+', a[0]) and op not in ('stw', 'stb', 'sth', 'std', 'stwu', 'cmplwi', 'cmpwi', 'cmplw', 'cmpw'):
                                regs.pop(a[0], None)
                        # displacement(base) operands
                        if len(a) == 2 and '(' in a[1]:
                            mm = re.match(r'(-?\d+)\((r\d+)\)', a[1])
                            if mm and mm.group(2) not in ('r1',):
                                cur['offsets'][mm.group(2)].add(int(mm.group(1)))
                    except ValueError:
                        pass
                    if op in ('bl', 'b') and a:
                        try:
                            tgt = int(a[0], 16)
                        except ValueError:
                            tgt = None
                        if tgt is not None and op == 'bl':
                            cur['calls'].add(tgt)
                    continue
                for mm in RE_IMP.finditer(line):
                    cur['imports'].add(mm.group(1))
                for mm in RE_SUB.finditer(line):
                    tgt = int(mm.group(1), 16)
                    if tgt != cur['addr']:
                        cur['calls'].add(tgt)
    out = {}
    for a, f in funcs.items():
        out['%08X' % a] = {
            'file': f['file'], 'line': f['line'], 'ninsn': f['ninsn'], 'end': '%08X' % f['end'],
            'calls': sorted('%08X' % c for c in f['calls']),
            'imports': sorted(f['imports']),
            'pm4': dict(f['pm4']),
            'consts': sorted('%08X' % c for c in f['consts'] if c > 0xFFFF),
            'offsets': {r: sorted(v) for r, v in f['offsets'].items() if r in ('r3', 'r31', 'r30', 'r29')},
        }
    # callers
    callers = defaultdict(set)
    for a, f in out.items():
        for c in f['calls']:
            callers[c].add(a)
    for a, f in out.items():
        f['callers'] = sorted(callers.get(a, ()))
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, 'w') as fh:
        json.dump(out, fh)
    print('functions: %d -> %s' % (len(out), OUT))


if __name__ == '__main__':
    main()
