"""Whole-game register summaries for the lifter (interprocedural, exact for volatile registers).

The Xbox 360 compiler's link-time code generation sometimes keeps values in volatile registers
across calls to functions it knows do not touch them, so the standard calling convention is
not enough to decide what must be in the context at a call. For every function this computes:

  inputs(f)   resources f may read before writing them (directly or in its callees)
  mods(f)     volatile resources f may change (directly or in its callees)
  outputs(f)  resources of mods(f) that some caller reads after the call (or the ABI return
              registers, since any function may also be called through a pointer)

Non-volatile registers are trusted to be preserved by every callee (callee-saved).

  python tools/lift/summarize.py          -> tools/lift/cache/summaries.pkl
"""
import os
import pickle
import multiprocessing as mp
import sys
import time

from genfile import read_file, generated_files
import regs
import typer
from regs import ALL, VOLATILE, ABI_INPUTS, ABI_OUTPUTS, helper_summary, bit

CACHE = os.path.join(os.path.dirname(__file__), 'cache')
# Bump when a change to the analysis rules (regs.py, frame.py, typer.py demand, webs.py, this file)
# changes the summaries: the bundled research/lift/summaries.json.gz is then ignored until re-exported.
ANALYSIS_VERSION = 7   # 7: inputs split into real reads and forwarded arguments (SPLIT)
EXIT = -1
SP = bit('r1') | bit('r2') | bit('r13')


def compact(path):
    """Phase A for one file: {name: [(use, def, sync, callee, succ), ...]} (+ failures)."""
    import lift
    import re
    out, failed = {}, {}
    for fn in read_file(path, keep_text=True):
        try:
            stmts = lift.build(fn)
        except Exception as e:
            # still recompiled: we cannot see what it reads after its calls, so its callees must write
            # back everything they change
            text = '\n'.join(fn.text)
            callees = sorted(set(re.findall(r'\b(sub_[0-9A-F]{8})\(ctx, base\)', text)))
            failed[fn.name] = {'error': str(e), 'callees': callees,
                               'indirect': 'REX_CALL_INDIRECT_FUNC' in text}
            continue
        recs = []
        for s in stmts:
            if s.removed:
                recs.append((0, 0, False, None, tuple(s.succ), 0, ()))
                continue
            w, e = typer.demand_info(lift.localize_stmt(s.stmt))
            wb = 0
            for r in w:
                wb |= bit(r)
            recs.append((s.acc.use, s.acc.def_, s.acc.sync, s.acc.callee, tuple(s.succ), wb,
                         tuple((regs.INDEX[a], regs.INDEX[b]) for a, b in e)))
        out[fn.name] = recs
    return os.path.basename(path), out, failed


def phase_a(files, jobs=8):
    os.makedirs(CACHE, exist_ok=True)
    funcs, failed = {}, {}
    todo = []
    for p in files:
        c = os.path.join(CACHE, os.path.basename(p) + '.pkl')
        here = os.path.dirname(os.path.abspath(__file__))
        deps = [p] + [os.path.join(here, m) for m in ('summarize.py', 'regs.py', 'lift.py', 'frame.py', 'cparse.py', 'genfile.py',
                                                       'typer.py')]
        if os.path.exists(c) and os.path.getmtime(c) > max(os.path.getmtime(d) for d in deps):
            with open(c, 'rb') as f:
                name, o, fl = pickle.load(f)
            funcs.update(o)
            failed.update(fl)
        else:
            todo.append(p)
    if todo:
        with mp.Pool(jobs) as pool:
            for name, o, fl in pool.imap_unordered(compact, todo):
                with open(os.path.join(CACHE, name + '.pkl'), 'wb') as f:
                    pickle.dump((name, o, fl), f)
                funcs.update(o)
                failed.update(fl)
                print(f'  parsed {name}: {len(o)} functions', flush=True)
    return funcs, failed


FAILED = {}  # functions the lifter could not analyse (set by main)

# Calls through pointers: what any address-taken function may read / change (set by phase_b; lift.py
# loads it from the summaries). Before the analysis: the standard convention.
IND = {'in': ABI_INPUTS, 'mods': VOLATILE, 'after': ABI_OUTPUTS, 'wide_in': 0}


XER_SO_OV = bit('xer.so') | bit('xer.ov')
XER_INVARIANT_DEFAULT = '0'   # (LIFT_XER_SO=0: invariant on; flip the default with the next whole-game cycle)


def xer_invariant():
    return os.environ.get('LIFT_XER_SO', XER_INVARIANT_DEFAULT) == '0'


def apply_invariants(sm):
    """Whole-game facts applied to the summaries after loading (on with LIFT_XER_SO=0, see xer_invariant).

    XER summary overflow / overflow (xer.so, xer.ov): no instruction of the game sets them (no overflow-recording
    "o" forms); the only writer is the full context restore in Fable2_recomp.94 (mtxer from a saved context,
    which holds what an earlier capture read, so 0 again). They are 0 throughout, so no function changes them or
    hands them on: a caller's copy stays valid across calls (no reload after every call, no flush before it).
    research/findings/2026-10-05-xer-so-invariant.md"""
    if not xer_invariant() or sm.get('_invariants'):
        return sm
    for key in ('inputs', 'mods', 'outputs', 'rin'):
        tab = sm.get(key)
        if tab:
            for f in tab:
                tab[f] &= ~XER_SO_OV
    if 'ind' in sm:
        for k in ('in', 'mods'):
            if k in sm['ind']:
                sm['ind'][k] &= ~XER_SO_OV
    sm['_invariants'] = True
    return sm


def call_summary(callee, inputs, mods):
    """(inputs, mods) of a call target."""
    keep = ~XER_SO_OV if xer_invariant() else ALL   # (apply_invariants)
    if callee is None:
        return regs.ALL & keep, VOLATILE & keep
    if is_indirect(callee):
        return (IND['in'] | SP) & keep, IND['mods'] & keep
    h = helper_summary(callee)
    if h is not None:
        return h
    if callee in inputs:
        return inputs[callee] | SP, mods[callee]
    return ABI_INPUTS & keep, VOLATILE & keep  # imports / unknown


_HOOKED = None


def hooked_extra(callee):
    """Extra registers a call target reads because the project replaced or wrapped it with hand-written code
    (tools/lift/overridden.txt: REX_HOOK / F2_REWRITE functions): that code takes its arguments by the
    standard convention, also ones the original function never read (the native renderer's draw hook reads
    the primitive type in r4 that sub_8221C9C8 itself ignores). Callers apply it to the arguments set up for
    the call, like for a call through a pointer."""
    global _HOOKED
    if _HOOKED is None:
        path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'overridden.txt')
        _HOOKED = set()
        if os.path.exists(path):
            with open(path) as f:
                _HOOKED = {l.strip() for l in f if l.strip()}
    return ABI_INPUTS if callee in _HOOKED else 0


def is_indirect(callee):
    """'indirect' (call through a pointer) or 'indirect@OFF' (virtual call of vtable slot OFF)."""
    return callee is not None and callee.startswith('indirect')


def slot_of(callee):
    return int(callee.split('@')[1]) if callee and '@' in callee else None


def slot_wide_in(callee, sm):
    """Arguments whose upper half the possible targets of an indirect call may read."""
    off = slot_of(callee)
    if off is not None and off in sm.get('slot_wide', {}):
        return sm['slot_wide'][off]
    return IND.get('wide_in', ABI_INPUTS)


def _standard_call(callee):
    """Calls that follow the standard convention: through pointers, and kernel imports."""
    return is_indirect(callee) or (callee is not None and callee.startswith('__imp__'))


def set_up_args(stmts, inputs=None, mods=None, results=False):
    """For each statement: the argument registers that may hold a value set up for a call there -
    written since the previous call that may have changed them (or received from the caller). A call
    to a function known to leave a register alone keeps it set up (the compiler relies on that).
    results: the standard result registers of a call also count as set up after it (a result handed on
    unchanged to the next call)."""
    n = len(stmts)
    ready = [None] * n
    if not n:
        return ready
    ready[0] = ABI_INPUTS
    work = [0]
    while work:
        i = work.pop()
        use, def_, sync, callee, succ = stmts[i][:5]
        if sync:
            cm = call_summary(callee, inputs, mods)[1] if inputs is not None else ALL
            o = (ready[i] & ~cm) | def_
            if results:
                o |= cm & ABI_OUTPUTS
        else:
            o = ready[i] | def_
        for j in succ:
            if j != EXIT and (ready[j] is None or (ready[j] | o) != ready[j]):
                ready[j] = o if ready[j] is None else ready[j] | o
                work.append(j)
    return [0 if r is None else r for r in ready]


# Inputs split in two (phase_b; lift.py loads them from the summaries): what a function's code really reads,
# and the argument registers it may only pass on to a call whose arguments are not known (through a pointer,
# an import, hand-written code). None: not computed (older summaries) - every input counts at every call.
SPLIT = None


def site_inputs(callee, inputs, mods, ready, ready_res=None):
    """(registers the call may read at this call site, registers it may change).
    ready / ready_res: set_up_args at the site, without / with call results.

    A direct call reads what the callee really reads, plus the registers it may pass on - but those only when
    they can hold an argument here: a register that an earlier call destroyed and nobody wrote since is not
    an argument, whatever the callee would do with it."""
    cin, cmods = call_summary(callee, inputs, mods)
    if _standard_call(callee):
        cin &= ready | SP
    elif SPLIT is not None and callee in SPLIT['rin']:
        cin = SPLIT['rin'][callee] | (SPLIT['fwd'].get(callee, 0) & (ready if ready_res is None else ready_res)) | SP
    cin |= hooked_extra(callee) & ready
    return cin, cmods


def forwarded(funcs, inputs, mods):
    """Fwd(f): argument registers that may still hold their value from f's entry (not written, not possibly
    changed by a call) at a call with unknown arguments in f - or at a direct call of g, for Fwd(g)."""
    arg = ABI_INPUTS & ~SP
    sites = {}
    for f, st in funcs.items():
        n = len(st)
        if not n:
            continue
        ent = [None] * n
        ent[0] = arg
        work = [0]
        while work:
            i = work.pop()
            use, def_, sync, callee, succ = st[i][:5]
            o = ent[i] & ~def_
            if sync:
                o &= ~call_summary(callee, inputs, mods)[1]
            for j in succ:
                if j != EXIT and (ent[j] is None or (ent[j] | o) != ent[j]):
                    ent[j] = o if ent[j] is None else ent[j] | o
                    work.append(j)
        sites[f] = [(rec[3], ent[i]) for i, rec in enumerate(st) if rec[2] and ent[i]]
    fwd = {f: 0 for f in funcs}
    changed = True
    while changed:
        changed = False
        for f, ss in sites.items():
            v = fwd[f]
            for c, e in ss:
                if c in fwd and not hooked_extra(c):
                    v |= fwd[c] & e
                elif c is None or helper_summary(c) is None:
                    v |= e          # (through a pointer, an import, unknown or hand-written code)
            if v != fwd[f]:
                fwd[f] = v
                changed = True
    return fwd


def liveness(stmts, inputs, mods, local_only=False, outputs_f=0, entry_written=0, exit_out=0, real_only=False):
    """Backward liveness for one compact function; returns (live_in list, live_out list).

    local_only: what the lifted code needs in local variables - a call's inputs only count
    for registers the function itself writes (the others are still in the context).
    real_only: only what the code really reads (`inputs` holds those sets): calls with unknown arguments
    read nothing but the stack and table pointers."""
    n = len(stmts)
    written_before = None
    if local_only:
        # registers written on some path from the entry to each statement
        written_before = [None] * n
        if n:
            written_before[0] = entry_written  # (native parameters: values that only exist as locals)
        work = [0] if n else []
        while work:
            i = work.pop()
            o = written_before[i] | stmts[i][1]
            for j in stmts[i][4]:
                if j != EXIT and (written_before[j] is None or (written_before[j] | o) != written_before[j]):
                    written_before[j] = o if written_before[j] is None else written_before[j] | o
                    work.append(j)
    args_ready = set_up_args(stmts, inputs, mods)
    args_ready_res = set_up_args(stmts, inputs, mods, results=True) if SPLIT is not None and not real_only else None
    live_in = [0] * n
    live_out = [0] * n
    changed = True
    while changed:
        changed = False
        for i in range(n - 1, -1, -1):
            use, def_, sync, callee, succ = stmts[i][:5]
            out = 0
            for j in succ:
                if j != EXIT:
                    out |= live_in[j]
                elif not local_only:
                    out |= exit_out
            if sync:
                if real_only:
                    cin, cmods = call_summary(callee, inputs, mods)
                    if callee is not None and callee not in inputs and helper_summary(callee) is None:
                        cin = SP   # (what such a call may be handed is in forwarded())
                else:
                    cin, cmods = site_inputs(callee, inputs, mods, args_ready[i],
                                             args_ready_res[i] if args_ready_res is not None else None)
                if local_only:
                    # locals written to the context here must be valid on every path: callee inputs and,
                    # for results the caller reads, registers the callee may change
                    cin = (cin | (cmods & outputs_f)) & (written_before[i] or 0)
                inn = use | cin | out  # a maybe-write does not end liveness
            else:
                inn = use | (out & ~def_)
            if local_only and EXIT in succ:
                inn |= outputs_f & ((written_before[i] or 0) | def_)  # written back at the return
            if inn != live_in[i] or out != live_out[i]:
                live_in[i], live_out[i] = inn, out
                changed = True
    return live_in, live_out


def phase_b(funcs, taken):
    """taken: names of address-taken functions (the possible targets of calls through pointers)."""
    names = list(funcs)
    taken_f = [f for f in names if f in taken]
    inputs = {f: 0 for f in names}
    mods = {f: 0 for f in names}
    IND['in'], IND['mods'] = ABI_INPUTS, VOLATILE  # (standard convention for calls through pointers)
    local_mods = {}
    for f, stmts in funcs.items():
        m = 0
        for use, def_, sync, callee, succ, *_ in stmts:
            m |= def_
        local_mods[f] = m & VOLATILE
    callees = {f: {s[3] for s in st if s[2]} for f, st in funcs.items()}
    for f in names:
        mods[f] = local_mods[f]
    # mods: transitive closure; calls through pointers change what any address-taken function may change
    changed, it = True, 0
    while changed:
        changed, it = False, it + 1
        for f in names:
            m = mods[f]
            for c in callees[f]:
                m |= mods[c] if c in mods else call_summary(c, inputs, mods)[1]
            if m != mods[f]:
                mods[f] = m
                changed = True
    print(f'  mods converged after {it} rounds', flush=True)
    # inputs, in two parts (SPLIT): what the code really reads - liveness at entry with the callees' real reads -
    # and the argument registers it may pass on to calls with unknown arguments
    global SPLIT
    SPLIT = None
    rin = {f: 0 for f in names}
    changed, it = True, 0
    while changed:
        changed, it = False, it + 1
        t0 = time.time()
        for f in names:
            st = funcs[f]
            if not st:
                continue
            li, _ = liveness(st, rin, mods, real_only=True)
            # (callee-saved registers too: compiler-generated cleanup blocks (__finally) read their parent's
            # r14-r31 as inputs; callers then write them to the context and restore them on return)
            v = li[0]
            if v != rin[f]:
                rin[f] = v
                changed = True
        print(f'  real reads round {it}: {time.time() - t0:.0f} s', flush=True)
    fwd = forwarded(funcs, rin, mods)
    for f in names:
        inputs[f] = rin[f] | fwd[f]
    SPLIT = {'rin': rin, 'fwd': fwd}
    print(f'  inputs split: really read - median {sorted(bin(v).count("1") for v in rin.values())[len(rin) // 2]} '
          f'registers; may be passed on - median {sorted(bin(v).count("1") for v in fwd.values())[len(fwd) // 2]}',
          flush=True)
    # outputs: what callers read after calling f. The usual return registers always (callers we cannot
    # see: the host, unanalysed code); for address-taken functions also what any call through a
    # pointer reads afterwards.
    ret_regs = bit('r3') | bit('f1')
    outputs = {f: ret_regs & mods[f] for f in names}
    after_indirect = 0
    for f in names:
        st = funcs[f]
        if not st:
            continue
        _, lo = liveness(st, inputs, mods)
        for i, (use, def_, sync, callee, succ, *_) in enumerate(st):
            if not sync:
                continue
            if callee in outputs:
                outputs[callee] |= lo[i] & mods[callee]
            elif is_indirect(callee):
                after_indirect |= lo[i]
    for f in taken_f:
        outputs[f] |= ABI_OUTPUTS & mods[f]  # callers through pointers read the standard return registers
    # callers the lifter could not analyse (still recompiled): assume they read everything back
    for name, info in FAILED.items():
        for c in info.get('callees', []) if isinstance(info, dict) else []:
            if c in outputs:
                outputs[c] |= mods[c]
    IND['after'] = after_indirect
    print('  read after calls through pointers:', len(regs.names(after_indirect & VOLATILE)), 'volatile resources')
    wide_in, wide_out, wide_regs = demand_fixpoint(funcs, inputs, mods, outputs, taken_f)
    return inputs, mods, outputs, wide_in, wide_out, wide_regs


GPR_BITS = sum(bit(f'r{i}') for i in range(32))


def _unknown_reader(callee):
    """Calls whose target's register use is unknown (unidentified). Kernel imports (__imp__*) are
    host code that reads integer arguments as 32-bit (rex/ppc/function.h ArgTranslator)."""
    return callee is None


def demand_fixpoint(funcs, inputs, mods, outputs, taken_f):
    """64-bit demand per value (webs.py), whole game, with a worklist (a function is analysed again
    only when something it depends on changed):
      wide_in(f):   inputs whose upper half f (or a callee) reads
      wide_out(f):  results whose upper half a caller reads
    Calls through pointers: a virtual call of vtable slot OFF ('indirect@OFF') can reach the
    functions in that slot of any vtable (vtables.py) plus address-taken functions that are in no
    vtable (callbacks); any other call through a pointer can reach every address-taken function."""
    import webs
    names = list(funcs)
    wide_in = {f: 0 for f in names}
    local_wide_in = {f: 0 for f in names}
    wide_out = {f: 0 for f in names}
    taken_set = set(taken_f)
    with open(os.path.join(CACHE, 'vtables.pkl'), 'rb') as fh:
        slots = {off: {f for f in fs if f in funcs} for off, fs in pickle.load(fh).items()}
    in_vtable = set()
    for fs in slots.values():
        in_vtable |= fs
    nonvt = [f for f in taken_f if f not in in_vtable]
    member_slots = {}
    for off, fs in slots.items():
        for f in fs:
            member_slots.setdefault(f, []).append(off)
    state = {'all': 0, 'nonvt': 0}          # unions of local 64-bit argument reads
    slot_union = {off: 0 for off in slots}  # (without the non-vtable part)
    slot_after = {}                         # slot -> results read as 64-bit after its calls
    g0 = regs.INDEX['r0']
    ready_cache = {f: set_up_args(st, inputs, mods) for f, st in funcs.items() if st}
    callers = {f: set() for f in names}
    slot_callers = {}
    generic_callers = set()
    for f, st in funcs.items():
        for rec in st:
            if rec[2]:
                c = rec[3]
                if c in callers:
                    callers[c].add(f)
                elif is_indirect(c):
                    off = slot_of(c)
                    if off is not None and off in slots:
                        slot_callers.setdefault(off, set()).add(f)
                    else:
                        generic_callers.add(f)

    def indirect_wide_args(c):
        off = slot_of(c)
        if off is not None and off in slots:
            return (slot_union[off] | state['nonvt']) & ABI_INPUTS
        return state['all'] & ABI_INPUTS

    def targets(c):
        off = slot_of(c)
        if off is not None and off in slots:
            return list(slots[off]) + nonvt
        return taken_f
    work = list(names)
    queued = set(names)
    t0 = time.time()
    last_report = t0
    done = 0
    preps = {}
    CANDIDATES = (ABI_INPUTS | ABI_OUTPUTS) & GPR_BITS

    def enqueue(f):
        if f not in queued:
            queued.add(f)
            work.append(f)

    def grew_local(f, new_bits):
        """f's own 64-bit argument reads grew: update the unions of the indirect calls that reach f."""
        nb = new_bits & ABI_INPUTS
        if f in taken_set and nb & ~state['all']:
            state['all'] |= nb
            for c in generic_callers:
                enqueue(c)
        for off in member_slots.get(f, ()):
            if nb & ~slot_union[off]:
                slot_union[off] |= nb
                for c in slot_callers.get(off, ()):
                    enqueue(c)
        if f in taken_set and f not in in_vtable and nb & ~state['nonvt']:
            state['nonvt'] |= nb
            for cs in slot_callers.values():
                for c in cs:
                    enqueue(c)
    while work:
        f = work.pop()
        queued.discard(f)
        st = funcs[f]
        if not st:
            continue
        done += 1
        if time.time() - last_report > 30:
            last_report = time.time()
            print(f'  demand: {done} analyses, {len(work)} queued, {time.time() - t0:.0f} s', flush=True)
        ready = ready_cache[f]

        def call_mods(i, st=st):
            return call_summary(st[i][3], inputs, mods)[1] & GPR_BITS

        def arg_wide(i, st=st, ready=ready, local=False):
            c = st[i][3]
            if c in funcs:
                return inputs[c] & (local_wide_in[c] if local else wide_in[c])
            if is_indirect(c):
                return 0 if local else (IND['in'] & indirect_wide_args(c) & ready[i])
            if _unknown_reader(c):
                return ABI_INPUTS & GPR_BITS
            return 0
        exit_wide = outputs.get(f, 0) & wide_out[f]
        prep = preps.get(f)
        if prep is None:
            prep = preps[f] = webs.prepare(st, g0, call_mods, CANDIDATES)
        w_in, cwo = webs.propagate(prep, arg_wide, exit_wide)
        if w_in != wide_in[f]:
            wide_in[f] = w_in
            for c in callers[f]:
                enqueue(c)
        if f in taken_set:
            w2, _ = webs.propagate(prep, lambda i, st=st, ready=ready: arg_wide(i, st, ready, True), exit_wide)
            if w2 != local_wide_in[f]:
                local_wide_in[f] = w2
                for c in callers[f]:
                    enqueue(c)
                grew_local(f, w2)
        for i, bitsv in cwo.items():
            c = st[i][3]
            if c in funcs:
                v = bitsv & mods[c]
                if v & ~wide_out[c]:
                    wide_out[c] |= v
                    enqueue(c)
            elif is_indirect(c):
                v = bitsv & ABI_OUTPUTS
                key = slot_of(c) if slot_of(c) in slots else None
                if v & ~slot_after.get(key, 0):
                    slot_after[key] = slot_after.get(key, 0) | v
                    for t in targets(c):
                        nv = v & mods[t]
                        if nv & ~wide_out[t]:
                            wide_out[t] |= nv
                            enqueue(t)
    print(f'  demand: {done} analyses in {time.time() - t0:.0f} s')
    IND['wide_in'] = state['all'] & ABI_INPUTS
    slot_wide = {off: (u | state['nonvt']) & ABI_INPUTS for off, u in slot_union.items()}
    narrow_slots = sum(1 for v in slot_wide.values() if not (v & bit('r3')))
    print('  64-bit argument reads: any address-taken function', regs.names(state['all'] & ABI_INPUTS),
          '| callbacks outside vtables', regs.names(state['nonvt'] & ABI_INPUTS))
    print(f'  vtable slots whose calls pass r3 (this) as 32-bit: {narrow_slots} of {len(slot_wide)}')
    nwide = sum(1 for v in wide_in.values() if v)
    print(f'  functions reading some input as 64-bit: {nwide}')
    DEMAND_EXTRA['slot_wide'] = slot_wide
    return wide_in, wide_out, {}


DEMAND_EXTRA = {}


def main():

    files = generated_files()
    t0 = time.time()
    funcs, failed = phase_a(files)
    print(f'phase A: {len(funcs)} functions ({len(failed)} not liftable) in {time.time() - t0:.0f} s', flush=True)
    FAILED.update(failed)
    t0 = time.time()
    with open(os.path.join(CACHE, 'address_taken.pkl'), 'rb') as f:
        taken = pickle.load(f)
    inputs, mods, outputs, wide_in, wide_out, wide_regs = phase_b(funcs, taken)
    print(f'phase B: {time.time() - t0:.0f} s', flush=True)
    with open(os.path.join(CACHE, 'summaries.pkl'), 'wb') as f:
        pickle.dump({'inputs': inputs, 'mods': mods, 'outputs': outputs, 'failed': failed, 'wide_in': wide_in,
                     'wide_out': wide_out, 'wide_regs': wide_regs, 'ind': dict(IND),
                     'rin': SPLIT['rin'], 'fwd': SPLIT['fwd'],
                     'slot_wide': DEMAND_EXTRA.get('slot_wide', {})}, f)

    # report non-standard conventions
    std_in = ABI_INPUTS | SP
    odd_in = {f: v & ~std_in for f, v in inputs.items() if v & ~std_in}
    odd_out = {f: v & ~ABI_OUTPUTS for f, v in outputs.items() if v & ~ABI_OUTPUTS}
    print(f'functions reading non-argument registers on entry: {len(odd_in)}')
    print(f'functions whose callers read non-return registers after the call: {len(odd_out)}')
    import collections
    c = collections.Counter(r for v in odd_in.values() for r in regs.names(v))
    print('  entry:', c.most_common(12))
    c = collections.Counter(r for v in odd_out.values() for r in regs.names(v))
    print('  after:', c.most_common(12))


if __name__ == '__main__':
    main()
