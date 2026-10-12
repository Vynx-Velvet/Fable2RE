"""Facts for class recovery (Phase B2), collected per function while lifting (lift.py --facts).

For every function, from its final statements:
  aliases     variables that hold the function's first argument (r3 at entry) unchanged
  fields      [offset, size, kind] of memory accesses through such a variable: kind 'r' / 'w', size in bytes,
              'f' appended for float accesses (LOAD_F32 ...)
  passes      callees that receive such a variable as their first argument
  vptr        constants stored to offset 0 of such a variable (a constructor / destructor setting the vtable)
Written as one JSON line per function to tools/lift/cache/facts/<file>.jsonl; tools/lift/classes.py reads them.
"""
from cparse import Member, Name, Call, Binary, Num, Assign, ExprStmt, Cast, walk

_LOADS = {'LOAD8': (1, ''), 'LOAD16': (2, ''), 'LOAD32': (4, ''), 'LOAD64': (8, ''), 'LOAD_F32': (4, 'f'),
          'LOAD_F64': (8, 'f')}
_STORES = {'STORE8': (1, ''), 'STORE16': (2, ''), 'STORE32': (4, ''), 'STORE64': (8, ''), 'STORE_F32': (4, 'f'),
           'STORE_F64': (8, 'f')}


def _strip(e):
    while type(e) is Cast or (type(e) is Call and type(e.func) is Name and e.func.id in ('uint32_t', 'int32_t',
                                                                                         'uint64_t', 'int64_t')
                              and len(e.args) == 1):
        e = e.x if type(e) is Cast else e.args[0]
    return e


def _var(e):
    """Variable name if e is a plain read of a register variable (any integer view)."""
    e = _strip(e)
    if type(e) is Member and type(e.obj) is Name and e.field in ('u32', 'u64', 's32', 's64'):
        return e.obj.id
    if type(e) is Name:
        return e.id
    return None


def _num(e):
    e = _strip(e)
    if type(e) is Num:
        try:
            v = e.value()
        except Exception:
            return None
        return v if isinstance(v, int) else None
    return None


def _base_offset(addr):
    """(variable, offset) for 'var' / 'var + const' / 'var - const' address expressions."""
    addr = _strip(addr)
    v = _var(addr)
    if v is not None:
        return v, 0
    if type(addr) is Binary and addr.op in ('+', '-'):
        v, k = _var(addr.a), _num(addr.b)
        if v is not None and k is not None:
            return v, k if addr.op == '+' else -k
    return None, None


def this_aliases(items, walk_items, entry_var):
    """Variables that hold the function's first argument unchanged.

    A variable is written by assignments and by the values read back after calls (a call's result often
    reuses the name of the argument register: r3 = n_sub_X(...)). If the argument's own variable is never
    written, it and every single-assignment copy of it are aliases. If it is written later, only copies made
    at the very top of the function - before a call, a branch or a label - are."""
    import regs
    everything = list(walk_items(items))
    defs = {}
    for it in everything:
        if it[0] == 'stmt':
            st = it[1]
            if type(st) is Assign and type(st.lhs) is Member and type(st.lhs.obj) is Name:
                defs[st.lhs.obj.id] = defs.get(st.lhs.obj.id, 0) + 1
        elif it[0] == 'reload':
            vars_ = (it[2] if len(it) > 2 else None) or {}
            for r in regs.names(it[1]):
                reg = r.split('.')[0]
                v = vars_.get(reg, reg)
                defs[v] = defs.get(v, 0) + 1

    def copy_of(st, sources):
        if type(st) is Assign and st.op == '=' and type(st.lhs) is Member and type(st.lhs.obj) is Name:
            v = st.lhs.obj.id
            if defs.get(v) == 1 and _var(st.rhs) in sources:
                return v
        return None
    aliases = set()
    if defs.get(entry_var, 0) == 0:
        aliases.add(entry_var)
    else:
        for it in items:  # top level, in order
            if it[0] == 'asm':
                continue
            if it[0] != 'stmt' or (len(it) > 2 and getattr(it[2].acc, 'sync', False)):
                break
            st = it[1]
            if type(st) is Assign and type(st.lhs) is Member and type(st.lhs.obj) is Name and \
                    st.lhs.obj.id == entry_var:
                break
            v = copy_of(st, {entry_var})
            if v is not None:
                aliases.add(v)
        if not aliases:
            return aliases
    changed = True
    while changed:
        changed = False
        for it in everything:
            if it[0] == 'stmt':
                v = copy_of(it[1], aliases)
                if v is not None and v not in aliases:
                    aliases.add(v)
                    changed = True
    return aliases


def collect(fname, items, walk_items, entry_var):
    """entry_var: the variable holding r3 at entry (None: the function does not read r3)."""
    if entry_var is None:
        return None
    aliases = this_aliases(items, walk_items, entry_var)
    if not aliases:
        return None
    fields, vptr = set(), set()
    for it in walk_items(items):
        exprs = []
        if it[0] == 'stmt':
            st = it[1]
            exprs = [st.lhs, st.rhs] if type(st) is Assign else [st.e] if type(st) is ExprStmt else []
            if type(st) not in (Assign, ExprStmt):
                from passes import _stmt_exprs
                exprs = _stmt_exprs(st)
        elif it[0] in ('if', 'ifelse', 'dowhile', 'while'):
            exprs = [it[1]]
        for e in exprs:
            for x in walk(e):
                if type(x) is Call and type(x.func) is Name and x.args:
                    n = x.func.id
                    if n in _LOADS or n in _STORES:
                        v, off = _base_offset(x.args[0])
                        if v in aliases and off is not None and 0 <= off < 0x10000:
                            size, fl = (_LOADS.get(n) or _STORES.get(n))
                            fields.add((off, size, ('r' if n in _LOADS else 'w') + fl))
                            if n == 'STORE32' and off == 0 and len(x.args) > 1:
                                k = _num(x.args[1])
                                if k is not None:
                                    vptr.add(k & 0xFFFFFFFF)
    passes = set()
    seq = list(walk_items(items))
    for pos, it in enumerate(seq):
        if it[0] == 'flush' and it[1] and len(it) > 2:
            # the registers handed to the next call: is r3 one of our aliases?
            vars_ = it[2] or {}
            if vars_.get('r3') in aliases:
                for nxt in seq[pos + 1:pos + 4]:
                    if nxt[0] == 'stmt' and len(nxt) > 2 and getattr(nxt[2].acc, 'sync', False):
                        c = nxt[2].acc.callee
                        if c and not c.startswith('indirect') and not c.startswith('__'):
                            passes.add(c)
                        break
    return {'f': fname, 'aliases': len(aliases), 'fields': sorted(fields), 'passes': sorted(passes),
            'vptr': sorted(vptr)}


# ---------------------------------------------------------------------------------------------
# Flow facts for whole-program type propagation (typeflow.py): how values move between variables,
# functions and fields. Names are the function's variable names at this point of the pipeline.

def _def_counts(everything):
    import regs
    defs = {}
    for it in everything:
        if it[0] == 'stmt':
            st = it[1]
            if type(st) is Assign and type(st.lhs) is Member and type(st.lhs.obj) is Name:
                defs[st.lhs.obj.id] = defs.get(st.lhs.obj.id, 0) + 1
        elif it[0] == 'reload':
            vars_ = (it[2] if len(it) > 2 else None) or {}
            for r in regs.names(it[1]):
                reg = r.split('.')[0]
                v = vars_.get(reg, reg)
                defs[v] = defs.get(v, 0) + 1
    return defs


_ARG_REGS = tuple(f'r{i}' for i in range(3, 11))


def collect_flow(fname, items, walk_items, entry):
    """entry: {register: variable holding its value at entry} for the integer registers the function reads.
    Returns a dict (JSON-able), or None when there is nothing to say:
      entry    as given (only r3..r10)
      multi    variables written more than once (their type is not tracked)
      copies   [dst, src]            dst = src, dst written once
      loads    [dst, base, off]      dst = LOAD32(base + off), dst written once
      stores   [base, off, value]    STORE32(base + off, value)
      vptr     [var, constant]       STORE32(var + 0, constant)
      acc      {var: [[off, size], ...]}  constant-offset accesses through the variable
      calls    [callee, {register: variable}]   arguments of direct calls
      results  [callee, var]         variable that receives r3 after a direct call
      rets     [var, ...]            variables returned in r3"""
    import regs
    everything = list(walk_items(items))
    defs = _def_counts(everything)
    out = {'f': fname, 'entry': {r: v for r, v in entry.items() if r in _ARG_REGS},
           'multi': sorted(v for v, n in defs.items() if n > 1),
           # (entry variables written later: they hold the argument only at the start)
           'written': sorted(v for v in entry.values() if defs.get(v, 0) >= 1),
           'copies': [], 'loads': [], 'stores': [], 'vptr': [], 'acc': {}, 'calls': [], 'results': [], 'rets': []}
    acc = {}

    def note_access(call):
        n = call.func.id
        size = (_LOADS.get(n) or _STORES.get(n))[0]
        v, off = _base_offset(call.args[0])
        if v is not None and off is not None and 0 <= off < 0x4000:
            acc.setdefault(v, set()).add((off, size))
        return v, off
    pending = {}      # register -> variable, from the flushes right before a call
    last_call = None  # callee of the call just seen (for the reloads after it)
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
                    if r in _ARG_REGS and vars_.get(r):
                        pending[r] = vars_[r]
            last_call = None
            continue
        if k == 'reload':
            if last_call is not None:
                vars_ = (it[2] if len(it) > 2 else None) or {}
                if regs.bit('r3') & it[1] and vars_.get('r3'):
                    out['results'].append([last_call, vars_['r3']])
                if len(it) <= 3:
                    last_call = None
            continue
        if k == 'ret':
            v = pending.get('r3')   # (returned through the context: the value handed to r3 just before)
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
                if c and c.startswith('sub_') and pending:
                    out['calls'].append([c, dict(pending)])
                last_call = c if c and c.startswith('sub_') else None
                pending = {}
                continue
            pending = {}
            last_call = None
            if type(st) is Assign and st.op == '=' and type(st.lhs) is Member and type(st.lhs.obj) is Name:
                dst = st.lhs.obj.id
                if defs.get(dst) == 1:
                    src = _var(st.rhs)
                    if src is not None:
                        out['copies'].append([dst, src])
                    else:
                        r = _strip(st.rhs)
                        if type(r) is Call and type(r.func) is Name and r.func.id == 'LOAD32' and r.args:
                            b, off = _base_offset(r.args[0])
                            if b is not None and off is not None and 0 <= off < 0x4000:
                                out['loads'].append([dst, b, off])
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
                        if n == 'STORE32' and b is not None and off is not None and len(x.args) > 1:
                            kk = _num(x.args[1])
                            if off == 0 and kk is not None:
                                out['vptr'].append([b, kk & 0xFFFFFFFF])
                            else:
                                v = _var(x.args[1])
                                if v is not None and 0 <= off < 0x4000:
                                    out['stores'].append([b, off, v])
    out['acc'] = {v: sorted(s) for v, s in acc.items()}
    if not (out['copies'] or out['loads'] or out['stores'] or out['vptr'] or out['acc'] or out['calls']
            or out['results'] or out['rets']):
        return None
    return out
