"""Experiment (2026-10-05): how much smaller do the functions' input sets get when a virtual call reads what the
functions in its vtable slot read, instead of every standard argument register?

    python tools/lift/experiments/slot_inputs.py        (reads the cached phase-A data; writes nothing but
                                                         cache/experiment_slot_inputs.pkl)

Today a call through a pointer counts as reading all argument registers that may hold a value (summarize.py:
IND['in'] = ABI_INPUTS). At a function's entry every argument register "may hold a value", so any function with
a call through a pointer near its start reads them all, and so do its callers.
Here: 'indirect@OFF' reads the union of the inputs of the functions in slot OFF of any vtable, plus those of the
address-taken functions that are in no vtable (callbacks); a plain 'indirect' reads the union over all
address-taken functions. Everything else as in summarize.phase_b.
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


def main():
    funcs = {}
    for p in glob.glob(os.path.join(CACHE, 'Fable2_recomp.*.cpp.pkl')):
        with open(p, 'rb') as f:
            _, o, _ = pickle.load(f)
        funcs.update(o)
    old = pickle.load(open(os.path.join(CACHE, 'summaries.pkl'), 'rb'))
    mods = old['mods']
    taken = pickle.load(open(os.path.join(CACHE, 'address_taken.pkl'), 'rb'))
    slots = {off: [f for f in fs if f in funcs] for off, fs in
             pickle.load(open(os.path.join(CACHE, 'vtables.pkl'), 'rb')).items()}
    in_vt = set()
    for fs in slots.values():
        in_vt |= set(fs)
    taken_f = [f for f in funcs if f in taken]
    nonvt = [f for f in taken_f if f not in in_vt]
    print(f'{len(funcs)} functions, {len(taken_f)} address-taken, {len(in_vt)} in vtables, {len(nonvt)} callbacks '
          f'outside vtables, {len(slots)} slots', flush=True)
    inputs = {f: 0 for f in funcs}
    state = {'slot': {off: 0 for off in slots}, 'nonvt': 0, 'all': 0}
    SP = summarize.SP
    orig = summarize.call_summary

    def call_summary(callee, inputs_, mods_):
        if summarize.is_indirect(callee):
            off = summarize.slot_of(callee)
            if off is not None and off in state['slot']:
                return ((state['slot'][off] | state['nonvt']) & ABI_INPUTS) | SP, VOLATILE
            if os.environ.get('SLOT_ONLY') == '1':
                return orig(callee, inputs_, mods_)   # (other calls through pointers: as today)
            return (state['all'] & ABI_INPUTS) | SP, VOLATILE
        return orig(callee, inputs_, mods_)
    summarize.call_summary = call_summary
    names = list(funcs)
    rnd, changed = 0, True
    while changed:
        changed, rnd = False, rnd + 1
        t0 = time.time()
        for off, fs in slots.items():
            v = 0
            for f in fs:
                v |= inputs[f]
            state['slot'][off] = v
        v = 0
        if os.environ.get('SLOT_ONLY') != '1':   # (SLOT_ONLY=1: upper bound of the gain - vtable members only)
            for f in nonvt:
                v |= inputs[f]
        state['nonvt'] = v
        v = 0
        for f in taken_f:
            v |= inputs[f]
        state['all'] = v
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
        print(f'round {rnd}: {n} functions changed ({time.time() - t0:.0f} s)', flush=True)

    def cnt(b):
        return bin(b).count('1')

    def report(tag, tab):
        c = sorted(cnt(tab[f]) for f in funcs if f in tab)
        print(f'{tag}: median {c[len(c) // 2]} input registers, mean {sum(c) / len(c):.1f}, '
              f'{sum(1 for x in c if x >= 12)} functions with 12 or more')
    report('today ', old['inputs'])
    report('by slot', inputs)
    print('callbacks outside vtables read', len(regs.names(state['nonvt'] & ABI_INPUTS)), 'argument registers;',
          'all address-taken functions read', len(regs.names(state['all'] & ABI_INPUTS)))
    sl = sorted(bin(v & ABI_INPUTS).count('1') for v in state['slot'].values())
    print('argument registers read per slot: median', sl[len(sl) // 2], 'max', sl[-1])
    nsl = sum(1 for st in funcs.values() for r in st if r[2] and r[3] and r[3].startswith('indirect@'))
    ngen = sum(1 for st in funcs.values() for r in st if r[2] and r[3] == 'indirect')
    print(f'call sites through pointers: {nsl} with a vtable slot, {ngen} without')
    with open(os.path.join(CACHE, 'experiment_slot_inputs.pkl'), 'wb') as f:
        pickle.dump({'inputs': inputs, 'state': state}, f)


if __name__ == '__main__':
    main()
