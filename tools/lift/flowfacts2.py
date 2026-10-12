"""Flow facts, second version, for the structural type inference (structflow.py).

    python tools/lift/flowfacts2.py [--jobs 4] [files ...]     -> tools/lift/cache/flow2/<file>.jsonl

Same idea as typefacts.collect_flow (how values move between variables, calls, returns and memory), but for
every variable - also the ones written more than once - and with what the first version could not connect:

  copies   [dst, src]            dst = src
  adds     [dst, src, k]         dst = src + k        (a pointer into the object src points to, or the next
                                                       element of an array when dst is src)
  consts   {var: address}        var = a constant address of the game image
  loads    [dst, base, off]      dst = LOAD32(base + off);  base "@": off is an absolute address (a global)
  stores   [base, off, value]    STORE32(base + off, value); base "@" likewise
  vptr     [base, off, const]    STORE32(base + off, vtable constant)
  acc      {base: [[off, size, float?], ...]}   constant-offset accesses; base "@" for absolute addresses
  calls    [callee, {register: variable}, result variable or null]
                                                arguments of direct calls: the locals handed over, and for
                                                registers still holding what the caller got, its entry variable
  icalls   [slot offset or null, object variable or null, vtable offset in the object (-1: object taken
            to be the first argument), {register: variable}, result variable or null]
  results  [callee or "indirect", var]
  rets     [var, ...]
  entry    {register: variable}; written: entry variables assigned again

It runs the lifter's own pipeline up to the point where typefacts.collect_flow is called and replaces that
function, so the variable names are the ones of the lifted code. Writes no lifted code.
"""
import argparse
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from cparse import Member, Name, Call, Binary, Num, Assign, ExprStmt, walk  # noqa: E402
import typefacts  # noqa: E402
from typefacts import _var, _strip, _num, _base_offset, _LOADS, _STORES, _def_counts  # noqa: E402

_ARG_REGS = tuple(f'r{i}' for i in range(3, 11))
IMAGE = (0x82000000, 0x84000000)
_SM = None


def _summaries():
    global _SM
    if _SM is None:
        import lift
        _SM = lift.summaries()
    return _SM


def _address(e):
    k = _num(e)
    if k is None:
        return None
    k &= 0xFFFFFFFF
    return k if IMAGE[0] <= k < IMAGE[1] else None


def _load_parts(e):
    """(base variable or '@', offset) of a LOAD32 expression, else None."""
    e = _strip(e)
    if type(e) is Call and type(e.func) is Name and e.func.id == 'LOAD32' and e.args:
        a = _address(e.args[0])
        if a is not None:
            return '@', a
        b, off = _base_offset(e.args[0])
        if b is not None and off is not None and -0x8000 <= off < 0x10000:
            return b, off
    return None


def collect_flow(fname, items, walk_items, entry):
    import regs
    import summarize
    sm = _summaries()
    everything = list(walk_items(items))
    defs = _def_counts(everything)
    out = {'f': fname, 'entry': {r: v for r, v in entry.items() if r in _ARG_REGS},
           'written': sorted(v for v in entry.values() if defs.get(v, 0) >= 1),
           'copies': [], 'adds': [], 'consts': {}, 'loads': [], 'stores': [], 'vptr': [], 'acc': {},
           'calls': [], 'icalls': [], 'results': [], 'rets': []}
    acc = {}
    single_load = {}   # variable written once by a LOAD32: (base, off)  (to find the object of a virtual call)
    const_writes, const_count = {}, {}   # variable -> constants assigned to it / how many times

    def note_access(call):
        n = call.func.id
        size, fl = _LOADS.get(n) or _STORES.get(n)
        a = _address(call.args[0])
        if a is not None:
            acc.setdefault('@', set()).add((a, size, 1 if fl else 0))
            return '@', a
        v, off = _base_offset(call.args[0])
        if v is not None and off is not None and -0x8000 <= off < 0x10000:
            acc.setdefault(v, set()).add((off, size, 1 if fl else 0))
            return v, off
        return None, None

    # registers that still hold what the caller passed: not flushed and not possibly changed by a call so far
    # (in text order; a register changed by a call inside a loop is dropped for the whole function)
    arg_bits = {r: regs.bit(r) for r in _ARG_REGS}
    loop_clobber = 0

    def scan_loops(lst, inside):
        nonlocal loop_clobber
        for it in lst:
            k = it[0]
            if inside and k == 'stmt' and len(it) > 2 and getattr(it[2].acc, 'sync', False):
                loop_clobber |= summarize.call_summary(it[2].acc.callee, sm['inputs'], sm['mods'])[1]
            if inside and k == 'flush':
                loop_clobber |= it[1]
            if k in ('dowhile', 'while', 'loop'):
                scan_loops(it[2], True)
            elif k == 'if':
                scan_loops(it[2], inside)
            elif k == 'ifelse':
                scan_loops(it[2], inside)
                scan_loops(it[3], inside)
    scan_loops(items, False)
    has_label = any(it[0] == 'label' for it in everything)   # (gotos: order in the text is not execution order)
    untouched = 0
    if not has_label:
        for r, b in arg_bits.items():
            if r in out['entry'] and out['entry'][r] not in out['written'] and not (loop_clobber & b):
                untouched |= b

    last = {}   # variable -> its latest assignment in text order: ('copy', src) or ('load', base, off)

    def loaded_from(v):
        """(base, off) of the LOAD32 a variable's value comes from (through copies), or None."""
        for _ in range(6):
            d = last.get(v)
            if d is None:
                return single_load.get(v)
            if d[0] == 'load':
                return d[1], d[2]
            v = d[1]
        return None

    def object_of(e):
        """(slot offset, object variable, vtable offset) for the target expression of a virtual call."""
        p = _load_parts(e)
        v = _var(e)
        if p is None and v is not None:
            p = loaded_from(v)
        if p is None:
            # LOAD32(LOAD32(obj + k) + slot) written as one expression
            x = _strip(e)
            if type(x) is Call and type(x.func) is Name and x.func.id == 'LOAD32' and x.args:
                a = _strip(x.args[0])
                inner, slot = a, 0
                if type(a) is Binary and a.op == '+' and _num(a.b) is not None:
                    inner, slot = a.a, _num(a.b)
                q = _load_parts(inner)
                if q is not None and q[0] != '@':
                    return slot, q[0], q[1]
                return (slot, None, None) if q is None else (None, None, None)
        if p is None or p[0] == '@':
            return None, None, None
        vt, slot = p
        q = loaded_from(vt)
        if q is None or q[0] == '@':
            return slot, None, None
        return slot, q[0], q[1]

    pending = {}
    last_call = None
    last_entry = None   # the record of the call just seen: its last element becomes the result variable
    for it in everything:
        k = it[0]
        if k == 'flush':
            vars_ = (it[2] if len(it) > 2 else None) or {}
            if len(it) > 3 and it[3] == 'ret':
                v = vars_.get('r3')
                if v:
                    out['rets'].append(v)
            else:
                for r in regs.names(it[1]):
                    if r in arg_bits:
                        untouched &= ~arg_bits[r]
                        if vars_.get(r):
                            pending[r] = vars_[r]
            last_call = None
            continue
        if k == 'reload':
            if last_call is not None:
                vars_ = (it[2] if len(it) > 2 else None) or {}
                if regs.bit('r3') & it[1] and vars_.get('r3'):
                    out['results'].append([last_call, vars_['r3']])
                    if last_entry is not None and last_entry[-1] is None:
                        last_entry[-1] = vars_['r3']   # (the call's own record: its result variable)
                if len(it) <= 3:
                    last_call = None
                    last_entry = None
            continue
        if k == 'ret':
            v = pending.get('r3')
            if v and v not in out['rets']:
                out['rets'].append(v)
            pending = {}
            continue
        if k == 'asm':
            continue
        exprs = []
        if k == 'stmt':
            st = it[1]
            s = it[2] if len(it) > 2 else None
            if s is not None and getattr(s.acc, 'sync', False):
                c = s.acc.callee
                args = dict(pending)
                for r, b in arg_bits.items():   # (what the caller passed and nobody touched: still the argument)
                    if r not in args and untouched & b:
                        args[r] = out['entry'][r]
                last_entry = None
                if c and c.startswith('sub_'):
                    last_entry = [c, args, None]
                    out['calls'].append(last_entry)
                    last_call = c
                elif c and c.startswith('indirect'):
                    slot = obj = voff = None
                    e = st.e if type(st) is ExprStmt else None
                    if type(e) is Call and e.args:
                        slot, obj, voff = object_of(e.args[-1])
                    if slot is None and '@' in c:
                        slot = int(c.split('@')[1])
                    if obj is None and slot is not None and '@' in c and args.get('r3'):
                        obj, voff = args['r3'], -1   # (not traced: a virtual call's object is its first argument)
                    last_entry = [slot, obj, voff, args, None]
                    out['icalls'].append(last_entry)
                    last_call = 'indirect'
                else:
                    last_call = None
                untouched &= ~summarize.call_summary(c, sm['inputs'], sm['mods'])[1]
                pending = {}
                continue
            pending = {}
            last_call = None
            if type(st) is Assign and st.op == '=' and type(st.lhs) is Member and type(st.lhs.obj) is Name:
                dst = st.lhs.obj.id
                src = _var(st.rhs)
                last.pop(dst, None)
                if src is not None:
                    out['copies'].append([dst, src])
                    last[dst] = ('copy', src)
                else:
                    r = _strip(st.rhs)
                    a = _address(r)
                    p = _load_parts(r)
                    if a is not None:
                        # a constant address: certain when the variable is written once; a variable assigned
                        # several times is a constant too when every assignment is this same constant
                        const_writes.setdefault(dst, set()).add(a)
                        const_count[dst] = const_count.get(dst, 0) + 1
                    elif p is not None:
                        out['loads'].append([dst, p[0], p[1]])
                        last[dst] = ('load', p[0], p[1])
                        if defs.get(dst) == 1:
                            single_load[dst] = p
                    elif type(r) is Binary and r.op in ('+', '-'):
                        b, kk = _var(r.a), _num(r.b)
                        if b is not None and kk is not None and abs(kk) < 0x10000:
                            out['adds'].append([dst, b, kk if r.op == '+' else -kk])
            exprs = [st.lhs, st.rhs] if type(st) is Assign else [st.e] if type(st) is ExprStmt else []
            if type(st) not in (Assign, ExprStmt):
                from passes import _stmt_exprs
                exprs = _stmt_exprs(st)
        elif k in ('if', 'ifelse', 'dowhile', 'while'):
            exprs = [it[1]]
            pending = {}
            last_call = None
        else:
            pending = {}
            last_call = None
        for e in exprs:
            for x in walk(e):
                if type(x) is Call and type(x.func) is Name and x.args:
                    n = x.func.id
                    if n in _LOADS:
                        note_access(x)
                    elif n in _STORES:
                        b, off = note_access(x)
                        if n == 'STORE32' and b is not None and len(x.args) > 1:
                            a = _address(x.args[1])
                            v = _var(x.args[1])
                            if a is not None:
                                out['vptr'].append([b, off, a])
                            elif v is not None:
                                out['stores'].append([b, off, v])
    for v, vals in const_writes.items():
        if len(vals) == 1 and const_count[v] >= defs.get(v, 0):   # (every write of v is this constant)
            out['consts'][v] = next(iter(vals))
    out['acc'] = {v: sorted(s) for v, s in acc.items()}
    if not any(out[k] for k in ('copies', 'adds', 'loads', 'stores', 'vptr', 'acc', 'calls', 'icalls', 'results',
                                'rets')):
        return None
    return out


def _job(idx):
    import emit
    import lift
    from genfile import read_file, generated_files
    typefacts.collect_flow = collect_flow          # (emit calls typefacts.collect_flow by name)
    path = [p for p in generated_files() if p.endswith(f'.{idx}.cpp')][0]
    emit.FACTS, emit.FLOW = [], []
    failed = 0
    for fn in read_file(path):
        if fn.name.startswith('__'):
            continue
        try:
            lift.lift_function(fn)
        except Exception:
            if os.environ.get('LIFT_FACTS_STRICT'):
                raise
            failed += 1
    out = os.path.join(HERE, 'cache', 'flow2')
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, f'{idx}.jsonl'), 'w', encoding='utf-8') as f:
        for fact in emit.FLOW:
            f.write(json.dumps(fact, separators=(',', ':')) + '\n')
    return len(emit.FLOW), failed


def main():
    import multiprocessing as mp
    from genfile import generated_files
    ap = argparse.ArgumentParser()
    ap.add_argument('files', nargs='*', type=int)
    ap.add_argument('--jobs', type=int, default=4)
    a = ap.parse_args()
    idx = a.files or [int(p.split('.')[-2]) for p in generated_files()]
    if len(idx) == 1:
        res = [_job(idx[0])]
    else:
        with mp.Pool(a.jobs) as pool:
            res = pool.map(_job, idx)
    print(f'flow facts for {sum(r[0] for r in res)} functions ({sum(r[1] for r in res)} could not be lifted) '
          f'in tools/lift/cache/flow2')


if __name__ == '__main__':
    main()
