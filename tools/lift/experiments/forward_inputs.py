"""Experiment 3 (2026-10-05): split a function's inputs into what its code really reads and what it may only
pass on to a call through a pointer.

    python tools/lift/experiments/forward_inputs.py

Today (summarize.py) a call through a pointer reads every argument register that may hold a value, and at a
function's entry all of them may. That makes the function "read" them all, and a direct caller has to provide
all of them - also at a call site where a register was just destroyed by an earlier call and so cannot be an
argument.

Split:
  Rin(f)   registers f's own instructions (and the functions it calls directly) read before writing them:
           the liveness of summarize.py with calls through pointers and imports reading nothing.
  Fwd(f)   argument registers that still hold their entry value (not written, not possibly changed by a call)
           at a call through a pointer / an import in f, or at a direct call of g for the registers in Fwd(g).
A direct call of f then reads  Rin(f) | (Fwd(f) & ready(site))  where ready(site) is what summarize.set_up_args
already computes for calls through pointers. This script measures Rin | Fwd (what a caller has to provide when
everything is ready) against today's inputs.
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
from regs import ABI_INPUTS, VOLATILE  # noqa: E402

CACHE = os.path.join(LIFT, 'cache')
EXIT = summarize.EXIT


def main():
    funcs = {}
    for p in glob.glob(os.path.join(CACHE, 'Fable2_recomp.*.cpp.pkl')):
        with open(p, 'rb') as f:
            _, o, _ = pickle.load(f)
        funcs.update(o)
    old = pickle.load(open(os.path.join(CACHE, 'summaries.pkl'), 'rb'))
    summarize.IND.update(old.get('ind', {}))
    mods, old_in = old['mods'], old['inputs']
    SP = summarize.SP
    orig = summarize.call_summary

    def standard(c):
        return summarize.is_indirect(c) or (c is not None and c.startswith('__imp__'))

    # ---- Fwd: entry values that reach a call with unknown arguments
    E_at = {}   # f -> [(callee, entry-valued argument registers at the site)]
    for f, st in funcs.items():
        n = len(st)
        if not n:
            continue
        ent = [None] * n
        ent[0] = ABI_INPUTS
        work = [0]
        while work:
            i = work.pop()
            use, def_, sync, callee, succ = st[i][:5]
            o = ent[i] & ~def_
            if sync:
                o &= ~orig(callee, old_in, mods)[1]
            for j in succ:
                if j != EXIT and (ent[j] is None or (ent[j] | o) != ent[j]):
                    ent[j] = o if ent[j] is None else ent[j] | o
                    work.append(j)
        E_at[f] = [(rec[3], ent[i] & ABI_INPUTS & ~SP) for i, rec in enumerate(st)
                   if rec[2] and ent[i] is not None and ent[i] & ABI_INPUTS & ~SP]
    fwd = {f: 0 for f in funcs}
    rnd, changed = 0, True
    while changed:
        changed, rnd = False, rnd + 1
        for f, sites in E_at.items():
            v = fwd[f]
            for c, e in sites:
                if c is None or standard(c):
                    v |= e
                elif c in fwd:
                    v |= fwd[c] & e
            if v != fwd[f]:
                fwd[f] = v
                changed = True
    print(f'Fwd converged after {rnd} rounds', flush=True)

    # ---- Rin: real reads
    def call_summary(callee, inputs_, mods_):
        if standard(callee):
            return SP, orig(callee, inputs_, mods_)[1]
        return orig(callee, inputs_, mods_)
    summarize.call_summary = call_summary
    rin = {f: 0 for f in funcs}
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
            li, _ = summarize.liveness(st, rin, mods)
            if li[0] != rin[f]:
                rin[f] = li[0]
                changed = True
                n += 1
        print(f'Rin round {rnd}: {n} changed ({time.time() - t0:.0f} s)', flush=True)

    def cnt(b):
        return bin(b).count('1')

    def report(tag, tab):
        c = sorted(cnt(tab[f] & ~SP) for f in funcs if f in tab)
        print(f'{tag}: median {c[len(c) // 2]}, mean {sum(c) / len(c):.1f}, 90th percentile {c[len(c) * 9 // 10]}, '
              f'{sum(1 for x in c if x >= 12)} functions with 12 or more')
    print('registers besides the stack and table pointers:')
    report('inputs today            ', old_in)
    report('really read (Rin)       ', rin)
    report('may be passed on (Fwd)  ', fwd)
    report('Rin | Fwd               ', {f: rin[f] | fwd[f] for f in funcs})
    with open(os.path.join(CACHE, 'experiment_forward_inputs.pkl'), 'wb') as f:
        pickle.dump({'rin': rin, 'fwd': fwd}, f)


if __name__ == '__main__':
    main()
