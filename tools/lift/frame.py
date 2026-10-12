"""Removes the register save/restore code of function prologues and epilogues.

Callee-saved registers live in local variables in lifted code and are never written to the
context, so the code that saves them on entry and restores them on exit (and the link-register
shuffle around it) has no effect any more. A save/restore is only removed when

  - it saves a callee-saved register (or the link register) at a fixed stack slot,
  - nothing else in the function reads or writes that slot directly,
  - the restored value is not used before the function returns.

Otherwise the function keeps it (still correct, just noisier).
"""
import re

from cparse import Assign, ExprStmt, Call, Name, Return, If, Goto
import regs
from regs import Access

_MEM = re.compile(r'^(stw|std|stfd|lwz|ld|lfd|stb|sth|lbz|lhz|lha|lwa|lfs|stfs|stwu|stdu)\s+(\w+),(-?\d+)\(r1\)$')
_SAVE_HELPER = re.compile(r'^__save(gprlr|fpr|vmx)_(\d+)$')
_REST_HELPER = re.compile(r'^__rest(gprlr|fpr|vmx)_(\d+)$')


def _helper(st):
    if type(st) is ExprStmt and type(st.e) is Call and type(st.e.func) is Name:
        return st.e.func.id
    return None


def r1_offsets(stmts):
    """Offset of r1 from its value on entry, before each statement (None where unknown).
    Returns None when r1 is changed in a way this does not follow."""
    EXIT = -1
    n = len(stmts)
    off = [None] * n
    if not n:
        return off
    off[0] = 0
    work = [0]
    seen = set()
    while work:
        i = work.pop()
        s = stmts[i]
        cur = off[i]
        nxt = cur
        insn = s.insn
        first = insn is not None and insn.stmts and insn.stmts[-1] is s.stmt  # last stmt of the insn
        if insn is not None and first:
            op, ops = insn.op, insn.operands()
            if op == 'stwu' and ops and ops[0] == 'r1':
                m = re.fullmatch(r'(-?\d+)\(r1\)', ops[1])
                if not m:
                    return None
                nxt = cur + int(m.group(1))
            elif op == 'addi' and ops[:2] == ['r1', 'r1']:
                nxt = cur + int(ops[2])
            elif op == 'lwz' and ops == ['r1', '0(r1)']:
                nxt = 0  # back-chain: back to the caller's stack pointer
            elif ops and ops[0] == 'r1' and op not in ('stw', 'std', 'stb', 'sth', 'stfd', 'stfs', 'cmpwi', 'cmplwi',
                                                        'cmpw', 'cmplw'):
                return None  # other writes of r1 (alloca, ...)
        for j in s.succ:
            if j == EXIT:
                continue
            if off[j] is None:
                off[j] = nxt
                work.append(j)
            elif off[j] != nxt:
                return None
    return off


def strip(stmts):
    """Marks prologue/epilogue statements as removed (s.acc emptied, s.removed = True)."""
    off = r1_offsets(stmts)
    if off is None:
        return 0
    saves = {}      # entry-relative slot -> (register, [stmt indices])
    restores = {}   # stmt index -> (register, slot)
    lr_save = []    # indices
    mflr = []
    lr_restore = []
    helpers = []    # indices of save/restore helper calls (+ their 'ctx.lr =' statement)
    other_slots = set()
    for i, s in enumerate(stmts):
        insn = s.insn
        if insn is None or off[i] is None:
            continue
        op, ops = insn.op, insn.operands()
        h = _helper(s.stmt)
        if h and (_SAVE_HELPER.match(h) or _REST_HELPER.match(h)):
            helpers.append(i)
            continue
        if op == 'mflr' and ops == ['r12']:
            mflr.append(i)
            continue
        if op == 'mtlr' and ops == ['r12']:
            lr_restore.append(i)
            continue
        m = _MEM.match(insn.asm)
        if m and op != 'stwu':
            kind, reg, d = m.group(1), m.group(2), int(m.group(3))
            slot = off[i] + d
            if kind in ('std', 'stfd') and _callee_saved(reg) and off[i] == 0:
                saves.setdefault(slot, (reg, []))[1].append(i)
            elif kind == 'stw' and reg == 'r12' and d == -8 and off[i] == 0:
                lr_save.append(i)
            elif kind in ('ld', 'lfd') and _callee_saved(reg) and off[i] == 0:
                restores[i] = (reg, slot)
            elif kind == 'lwz' and reg == 'r12' and d == -8 and off[i] == 0:
                lr_restore.append(i)
            else:
                other_slots.add(slot)
    removed = set()
    # callee-saved register saves / restores
    for slot, (reg, idx) in saves.items():
        if slot in other_slots:
            continue
        rest = [i for i, (r, sl) in restores.items() if sl == slot]
        if any(restores[i][0] != reg for i in rest):
            continue
        if any(_used_after(stmts, i, reg) for i in rest):
            continue
        removed.update(idx)
        removed.update(rest)
    # link register: mflr r12 / stw r12,-8(r1) ... lwz r12,-8(r1) / mtlr r12
    if -8 not in other_slots:
        removed.update(lr_save)
        removed.update(i for i in lr_restore)
        removed.update(mflr)
    # helper calls: the instruction's 'ctx.lr = ...' goes with them
    for i in helpers:
        removed.add(i)
        if i > 0 and stmts[i - 1].insn is stmts[i].insn:
            removed.add(i - 1)
    # mflr r12 must only feed the removed saves
    for i in mflr:
        if _used_after(stmts, i, 'r12', ignore=removed):
            removed.discard(i)
            for j in lr_save:
                removed.discard(j)
    for i in removed:
        s = stmts[i]
        s.acc = Access()
        s.removed = True
    return len(removed)


def _callee_saved(reg):
    m = re.fullmatch(r'([rf])(\d+)', reg)
    return bool(m) and int(m.group(2)) >= 14


def _used_after(stmts, i, reg, ignore=()):
    """Is `reg` read after statement i before being overwritten / the function returning?
    (Forward search over successors.)"""
    b = regs.reg_bits(reg) if reg in regs.LOCAL_REGS else 0
    seen = set()
    work = [j for j in stmts[i].succ if j >= 0]
    while work:
        j = work.pop()
        if j in seen:
            continue
        seen.add(j)
        if j in ignore:
            work.extend(k for k in stmts[j].succ if k >= 0)
            continue
        a = stmts[j].acc
        if a.use & b or (a.sync and reg in ('r12', 'r11', 'r0') and a.callee and a.callee.startswith('__')):
            return True
        if a.def_ & b:
            continue
        work.extend(k for k in stmts[j].succ if k >= 0)
    return False
