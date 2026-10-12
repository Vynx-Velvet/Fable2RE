"""Experiment 2 (2026-10-05): bound a function's argument registers by what its direct call sites supply.

    python tools/lift/experiments/arity_inputs.py

Experiment 1 (slot_inputs.py) changed nothing: 16,514 address-taken functions sit in no known vtable, they have
to count as possible targets of every virtual call, and together they read every argument register.

Idea here: a real argument is supplied at every call site. At a direct call site of f, an argument register is
"supplied" when the caller touched it before the call (wrote it, or called something that may have changed
it), or when it is one of the caller's own arguments (passed through).
    A(f) = intersection over the direct call sites s of f of ( touched(s) | A(caller of s) )
(least fixpoint; all argument registers for a function without analysed direct call sites).
A direct call of f then reads, of the argument registers, only  P(f) | (inputs(f) & A(f)),  where P(f) is what
f's own code and its direct callees really read (signatures.py). Other registers of inputs(f) stay.
Not sound in one case: an argument that only some call sites set and that is passed on to a call through a
pointer. This script only measures what the bound would buy.
"""
import glob
import os
import pickle
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
LIFT = os.path.dirname(HERE)
sys.path.insert(0, LIFT)
import regs  # noqa: E402
import summarize  # noqa: E402
from regs import ABI_INPUTS  # noqa: E402

CACHE = os.path.join(LIFT, 'cache')
EXIT = summarize.EXIT


def main():
    funcs, failed = {}, {}
    for p in glob.glob(os.path.join(CACHE, 'Fable2_recomp.*.cpp.pkl')):
        with open(p, 'rb') as f:
            _, o, fl = pickle.load(f)
        funcs.update(o)
        failed.update(fl)
    old = pickle.load(open(os.path.join(CACHE, 'summaries.pkl'), 'rb'))
    summarize.IND.update(old.get('ind', {}))
    mods, old_in = old['mods'], old['inputs']
    sig = pickle.load(open(os.path.join(CACHE, 'signatures.pkl'), 'rb'))
    params = sig.get('params', sig) if isinstance(sig, dict) else {}
    print('signature keys:', list(sig.keys())[:6] if isinstance(sig, dict) else type(sig), flush=True)

    # touched(s): registers written, or possibly changed by a call, on some path from the entry to s
    sites = {f: [] for f in funcs}
    t0 = time.time()
    for f, st in funcs.items():
        n = len(st)
        if not n:
            continue
        touch = [None] * n
        touch[0] = 0
        work = [0]
        while work:
            i = work.pop()
            use, def_, sync, callee, succ = st[i][:5]
            o = touch[i] | def_
            if sync:
                o |= summarize.call_summary(callee, old_in, mods)[1]
            for j in succ:
                if j != EXIT and (touch[j] is None or (touch[j] | o) != touch[j]):
                    touch[j] = o if touch[j] is None else touch[j] | o
                    work.append(j)
        for i, rec in enumerate(st):
            if rec[2] and rec[3] in sites and touch[i] is not None:
                sites[rec[3]].append((f, touch[i] & ABI_INPUTS))
    print(f'call sites collected ({time.time() - t0:.0f} s)', flush=True)
    unknown_callers = set()
    for info in failed.values():
        if isinstance(info, dict):
            unknown_callers |= set(info.get('callees', []))
    # least fixpoint: an argument is real only if some chain of callers really supplies it. Functions whose
    # callers are not all known (no direct call site: reached through pointers; or called from code that
    # could not be analysed) keep every argument register.
    A = {f: (ABI_INPUTS if (not sites[f] or f in unknown_callers) else 0) for f in funcs}
    rnd, changed = 0, True
    while changed:
        changed, rnd = False, rnd + 1
        for f, ss in sites.items():
            if not ss or f in unknown_callers:
                continue
            v = ABI_INPUTS
            for c, t in ss:
                v &= t | A[c]
                if not v:
                    break
            if v != A[f]:
                A[f] = v
                changed = True
    nosite = sum(1 for f, ss in sites.items() if not ss)
    print(f'A converged after {rnd} rounds; {nosite} functions without a direct call site, '
          f'{len(unknown_callers)} called from code that could not be analysed', flush=True)

    def cnt(b):
        return bin(b).count('1')
    c = sorted(cnt(A[f]) for f in funcs if sites[f])
    print(f'A(f) for functions with direct call sites: median {c[len(c) // 2]} registers, '
          f'{sum(1 for x in c if x <= 4)} of {len(c)} have 4 or fewer', flush=True)

    P = {}
    try:
        import lift
        for f in funcs:
            s = lift.native_sig(f)
            P[f] = s[0] if s else ABI_INPUTS
    except Exception as e:
        print('no signatures:', e)
        P = {f: ABI_INPUTS for f in funcs}
    orig = summarize.call_summary
    inputs = {f: 0 for f in funcs}

    def call_summary(callee, inputs_, mods_):
        cin, cm = orig(callee, inputs_, mods_)
        if callee in A:
            cin = (cin & ~ABI_INPUTS) | (cin & ABI_INPUTS & (A[callee] | P[callee]))
        return cin, cm
    summarize.call_summary = call_summary
    names = list(funcs)
    rnd, changed = 0, True
    while changed:
        changed, rnd = False, rnd + 1
        t0 = time.time()
        n = 0
        for f in names:
            st = funcs[f]
            if not st:
                continue
            li, _ = summarize.liveness(st, inputs, mods)
            if li[0] != inputs[f]:
                inputs[f] = li[0]
                changed = True
                n += 1
        print(f'inputs round {rnd}: {n} functions changed ({time.time() - t0:.0f} s)', flush=True)
    # what a direct caller has to provide
    eff = {f: (inputs[f] & ~ABI_INPUTS) | (inputs[f] & ABI_INPUTS & (A[f] | P[f])) for f in funcs}

    def report(tag, tab):
        c = sorted(cnt(tab[f]) for f in funcs if f in tab)
        print(f'{tag}: median {c[len(c) // 2]} registers, mean {sum(c) / len(c):.1f}, '
              f'{sum(1 for x in c if x >= 12)} functions with 12 or more')
    report('inputs today                        ', old_in)
    report('inputs with the bound (entry)       ', inputs)
    report('what a direct call has to provide   ', eff)
    with open(os.path.join(CACHE, 'experiment_arity_inputs.pkl'), 'wb') as f:
        pickle.dump({'A': A, 'inputs': inputs, 'eff': eff}, f)


if __name__ == '__main__':
    main()
