"""Precise per-function signatures for Phase B (native calls), next to the conservative summaries.

    python tools/lift/signatures.py            -> tools/lift/cache/signatures.pkl + statistics

For every function (same compact statements as summarize.py, phase A cache):
  MD(f)  registers written on every path to a return (through direct callees too)
  P(f)   parameters: registers f's own instructions read before writing them, plus what the functions it
         calls directly need of f's incoming values. Calls through pointers and kernel imports add nothing
         (their arguments keep travelling through the context).
  RET(f) the result register handed back natively: r3 when the conservative summary says callers read it
         after the call, else f1 when they read that. f need not write it on every path: a return hands back
         the register's current value (its local, or what a callee left in the context).
See research/findings/2026-10-04-full-native-plan.md (B1 design).
"""
import collections
import os
import pickle
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import regs  # noqa: E402
import summarize  # noqa: E402
from summarize import EXIT, CACHE, is_indirect  # noqa: E402
from regs import helper_summary, bit  # noqa: E402
from genfile import generated_files  # noqa: E402

ALL = regs.ALL
# never parameters: the stack pointer / small-data / thread registers and the flag state that stays global
ENV = bit('r1') | bit('r2') | bit('r13') | regs.reg_bits('xer')
CR = 0
for _i in range(8):
    CR |= regs.reg_bits(f'cr{_i}')
GPR = sum(bit(f'r{i}') for i in range(32))
FPR = sum(bit(f'f{i}') for i in range(32))
PARAM_OK = (GPR | FPR) & regs.VOLATILE & ~ENV  # (vector, condition and callee-saved registers: context)


def must_def(funcs):
    """MD(f): greatest fixpoint, so recursion does not lose definitions."""
    md = {f: ALL for f in funcs}
    changed, rounds = True, 0
    while changed:
        changed, rounds = False, rounds + 1
        for f, st in funcs.items():
            n = len(st)
            if not n:
                if md[f]:
                    md[f], changed = 0, True
                continue
            d_in = [None] * n
            d_in[0] = 0
            work = [0]
            result = None
            while work:
                i = work.pop()
                use, def_, sync, callee, succ = st[i][:5]
                o = d_in[i] | def_
                if sync:
                    if callee in md:
                        o |= md[callee]
                    else:
                        h = helper_summary(callee) if callee and not is_indirect(callee) else None
                        if h is not None:
                            o |= 0  # (save/restore helpers: their writes are in def_ of the statement)
                for j in succ:
                    if j == EXIT:
                        result = o if result is None else result & o
                    elif d_in[j] is None:
                        d_in[j] = o
                        work.append(j)
                    elif d_in[j] & o != d_in[j]:
                        d_in[j] &= o
                        work.append(j)
            v = 0 if result is None else result  # (no return: nothing a caller could rely on)
            if v != md[f]:
                md[f], changed = v, True
    return md, rounds


def params(funcs, md):
    """P(f): least fixpoint of backward liveness with exact call effects for direct callees."""
    p = {f: 0 for f in funcs}
    changed, rounds = True, 0
    while changed:
        changed, rounds = False, rounds + 1
        for f, st in funcs.items():
            n = len(st)
            if not n:
                continue
            live_in = [0] * n
            again = True
            while again:
                again = False
                for i in range(n - 1, -1, -1):
                    use, def_, sync, callee, succ = st[i][:5]
                    out = 0
                    for j in succ:
                        if j != EXIT:
                            out |= live_in[j]
                    if sync:
                        if callee in p:
                            inn = use | p[callee] | (out & ~md[callee])
                        else:
                            h = helper_summary(callee) if callee and not is_indirect(callee) else None
                            # helpers (__savegprlr ...): exact; pointers / imports: read nothing of ours natively,
                            # may leave anything alone
                            inn = use | (h[0] if h is not None else 0) | (out & ~def_ if h is not None else out)
                    else:
                        inn = use | (out & ~def_)
                    if inn != live_in[i]:
                        live_in[i] = inn
                        again = True
            v = live_in[0]
            if v != p[f]:
                p[f], changed = v, True
    return p, rounds


def main():
    t0 = time.time()
    funcs, failed = summarize.phase_a(generated_files())
    print(f'{len(funcs)} functions loaded in {time.time() - t0:.0f} s', flush=True)
    t0 = time.time()
    md, r1 = must_def(funcs)
    print(f'must-def: {r1} rounds, {time.time() - t0:.0f} s', flush=True)
    t0 = time.time()
    p, r2 = params(funcs, md)
    print(f'params: {r2} rounds, {time.time() - t0:.0f} s', flush=True)
    with open(os.path.join(CACHE, 'summaries.pkl'), 'rb') as f:
        sm = pickle.load(f)
    ret = {}
    for f in funcs:
        o = sm['outputs'].get(f, 0)
        ret[f] = bit('r3') if o & bit('r3') else bit('f1') if o & bit('f1') else 0
    with open(os.path.join(CACHE, 'signatures.pkl'), 'wb') as f:
        pickle.dump({'params': p, 'must_def': md, 'ret': ret}, f)

    def regset(b):
        return sorted({n.split('.')[0] for n in regs.names(b)})
    hist = collections.Counter(min(len(regset(p[f] & PARAM_OK)), 12) for f in funcs)
    print('parameters (GPR/FPR) per function:', sorted(hist.items()))
    odd = collections.Counter()
    for f in funcs:
        for r in regset(p[f] & ~PARAM_OK & ~ENV):
            odd[r] += 1
    print('functions reading other registers on entry (stay in the context):', odd.most_common(10))
    nonabi = collections.Counter()
    for f in funcs:
        for r in regset(p[f] & PARAM_OK & ~regs.ABI_INPUTS):
            nonabi[r] += 1
    print('non-ABI parameter registers:', nonabi.most_common(12))
    print('result: r3', sum(1 for f in funcs if ret[f] == bit('r3')), ' f1', sum(1 for f in funcs if ret[f] == bit('f1')),
          ' none', sum(1 for f in funcs if not ret[f]))


if __name__ == '__main__':
    main()
