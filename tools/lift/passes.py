"""Readability passes over the item list of a lifted function (see emit.py). Each keeps behaviour
identical:

fold_compares   crN.compare(a, b) followed by branches on crN.lt/gt/eq becomes the branch
                conditions a < b / a > b / a == b (when a and b do not change in between); the
                compare goes away when nothing else reads crN.
inline_temps    a register written once and read once soon after (same straight-line code, its
                inputs unchanged, no store or call in between when it reads memory) is replaced
                by its expression at the use.
"""
from cparse import (Member, Name, Index, Call, Cast, Unary, Binary, Ternary, InitList, Num, Assign, ExprStmt, Decl,
                    Goto, Return, If, Block, Switch, map_expr, walk)
import os

import regs
from regs import reg_bits

# ---------------------------------------------------------------------------------------------
# Debugging aid (tools/lift/pass_bisect.py): switch passes off / stop a pass after N changes.
#   LIFT_NO=fold,inline,dead,sugar1,sugar2,structure     passes not to run
#   LIFT_LIMIT=inline:37                                 that pass makes only its first 37 changes
#   LIFT_COUNT=1                                         lift.py prints how many changes each pass made
DISABLED = set(filter(None, os.environ.get('LIFT_NO', '').split(',')))
_LIMIT = None
if os.environ.get('LIFT_LIMIT'):
    _n, _c = os.environ['LIFT_LIMIT'].split(':')
    _LIMIT = (_n, int(_c))
COUNT = {}


def allow(name, describe=None):
    """True if the pass may make one more change (always, unless LIFT_LIMIT names it). describe: a function
    returning text about the change; printed for the last change that is still allowed."""
    n = COUNT.get(name, 0)
    if _LIMIT and _LIMIT[0] == name:
        if n >= _LIMIT[1]:
            return False
        if n == _LIMIT[1] - 1 and describe is not None:
            print(f'LAST {name} #{n + 1}: {describe()}')
    COUNT[name] = n + 1
    return True

# ---------------------------------------------------------------------------------------------
# helpers


def _sobj(it):
    if it[0] == 'stmt' and len(it) > 2:
        return it[2]
    if it[0] == 'if' and len(it) > 3:
        return it[3]
    return None


def _cond_of(it):
    """The condition expression an item evaluates (for 'if' items and If statements)."""
    if it[0] == 'if':
        return it[1]
    if it[0] == 'stmt' and type(it[1]) is If:
        return it[1].cond
    return None


def _with_cond(it, cond):
    if it[0] == 'if':
        return ('if', cond, it[2]) + tuple(it[3:])
    st = it[1]
    return ('stmt', If(cond, st.body)) + tuple(it[2:])


def _mentions(e, name):
    return any(type(x) is Name and x.id == name for x in walk(e))


_LOADS = {'REX_LOAD_U8', 'REX_LOAD_U16', 'REX_LOAD_U32', 'REX_LOAD_U64', 'REX_RAW_ADDR', 'LOAD8', 'LOAD16', 'LOAD32',
          'LOAD64', 'RAW', 'LOAD_F32', 'LOAD_F64', 'VLOAD'}
_STORES = {'REX_STORE_U8', 'REX_STORE_U16', 'REX_STORE_U32', 'REX_STORE_U64', 'STORE8', 'STORE16', 'STORE32', 'STORE64',
           'STORE_F32', 'STORE_F64', 'VSTORE', 'SET_V8', 'SET_VF'}
_PURE_CALLS = _LOADS | {'AS_F32', 'AS_U32', 'V8', 'VF', 'double', 'float',
               'uint32_t', 'int32_t', 'uint64_t', 'int64_t', 'uint16_t', 'int16_t', 'uint8_t', 'int8_t',
               '__builtin_rotateleft32', '__builtin_rotateleft64', '__builtin_bswap16', '__builtin_bswap32',
               '__builtin_bswap64', '__builtin_clz', '__builtin_clzll', 'std::isnan', 'sqrt', 'std::sqrt', 'std::fma',
               'std::abs', 'fabs', 'static_cast', 'simde_mm_cvttsd_si32', 'simde_mm_load_sd'}


def _pure(e):
    for x in walk(e):
        if type(x) is Call:
            f = x.func
            if type(f) is Name and f.id in _PURE_CALLS:
                continue
            return False
        if type(x) is Unary and x.op in ('++', '--', 'post++', 'post--'):
            return False
    return True


def _has_fp(e):
    for x in walk(e):
        if type(x) is Name and len(x.id) > 1 and x.id[0] == 'f' and x.id[1:].isdigit():
            return True
        if type(x) is Call and type(x.func) is Name and (x.func.id in ('double', 'float', 'sqrt', 'std::fma', 'LOAD_F32',
                                                                       'LOAD_F64', 'AS_F32') or x.func.id.endswith('_ps')
                                                         or x.func.id.endswith('_pd') or x.func.id.endswith('_sd')):
            return True
    return False


def _is_fpscr(it):
    if it[0] != 'stmt' or type(it[1]) is not ExprStmt:
        return False
    e = it[1].e
    return type(e) is Call and type(e.func) is Member and type(e.func.obj) is Member and         type(e.func.obj.obj) is Name and e.func.obj.obj.id == 'ctx' and e.func.obj.field == 'fpscr'


def _reads_memory(e):
    return any(type(x) is Call and type(x.func) is Name and x.func.id in _LOADS for x in walk(e))


def _writes_memory(it):
    k = it[0]
    if k == 'if':
        return any(_writes_memory(x) for x in it[2])
    if k != 'stmt':
        return False
    s = _sobj(it)
    if s is not None and s.acc.sync:
        return True
    st = it[1]
    for x in walk(st.e if type(st) is ExprStmt else (st.rhs if type(st) is Assign else Num('0'))):
        if type(x) is Call and type(x.func) is Name and ((x.func.id in _STORES and x.func.id not in ('SET_V8', 'SET_VF')) or
                                                          (x.func.id.startswith('simde_mm_store') and _raw_addr_dst(x))):
            return True
    if type(st) in (Block, If):
        return True  # (conservative)
    return False


def _raw_addr_dst(call):
    return bool(call.args) and any(type(y) is Call and type(y.func) is Name and y.func.id in ('REX_RAW_ADDR', 'RAW')
                                   for y in walk(call.args[0]))


def _item_reads(it):
    s = _sobj(it)
    if it[0] in ('stmt', 'if') and s is not None:
        return s.acc.use
    if it[0] == 'flush':
        return it[1]
    return 0


def _item_writes(it):
    s = _sobj(it)
    if it[0] == 'stmt' and s is not None:
        return s.acc.def_ | (s.acc.use if s.acc.sync else 0)
    if it[0] == 'if' and s is not None:
        return s.acc.def_ | s.acc.use
    if it[0] == 'reload':
        return it[1]
    return 0


def _live_at(items, j):
    """Resources live before item j (None if unknown)."""
    for k in range(j, len(items)):
        it = items[k]
        s = _sobj(it)
        if s is not None:
            return s.live_in
        if it[0] == 'ret':
            return 0
        if it[0] == 'flush' and k + 1 < len(items) and items[k + 1][0] == 'ret':
            return it[1]
    return None


# ---------------------------------------------------------------------------------------------
# compare folding

_FIELD_OP = {'lt': '<', 'gt': '>', 'eq': '=='}
_NEG = {'<': '>=', '>': '<=', '==': '!=', '!=': '==', '<=': '>', '>=': '<'}


def _compare_of(it):
    """(cr, a, b, tmpl) for 'crN.compare<T>(a, b[, xer]);' items."""
    if it[0] != 'stmt' or type(it[1]) is not ExprStmt:
        return None
    e = it[1].e
    if type(e) is Call and type(e.func) is Member and e.func.field == 'compare' and type(e.func.obj) is Name and \
            e.func.obj.id.startswith('cr'):
        return e.func.obj.id, e.args[0], e.args[1], e.tmpl
    return None


def _subst_cr(cond, cr, a, b, is_float):
    def f(x):
        if type(x) is Member and type(x.obj) is Name and x.obj.id == cr and x.field in _FIELD_OP:
            return Binary(_FIELD_OP[x.field], a, b)
        return None
    new = map_expr(cond, f)
    ok = [not any(type(x) is Name and x.id == cr for x in walk(new))]

    def neg(x):  # !(a < b) -> a >= b for integers; !(a == b) -> a != b always
        if type(x) is Unary and x.op == '!' and type(x.x) is Binary and x.x.op in _NEG:
            if not is_float or x.x.op == '==':
                return Binary(_NEG[x.x.op], x.x.a, x.x.b)
        return None
    return map_expr(new, neg), ok[0]


def stmt_text(it):
    """One line of text for an item (debug output)."""
    from cparse import stmt_str, expr_str
    try:
        if it[0] == 'stmt':
            return stmt_str(it[1], '').strip().replace('\n', ' ')
        if it[0] == 'if':
            return 'if (' + expr_str(it[1]) + ') {...}'
    except Exception as e:  # (debug only)
        return f'<{it[0]}: {e}>'
    return f'<{it[0]}>'


def fold_compares(items, stmts=None):
    """stmts: the function's statements (lift.build), to see what a branch's target still reads."""
    i = 0
    while i < len(items):
        c = _compare_of(items[i])
        if not c:
            if items[i][0] == 'if':
                fold_compares(items[i][2], stmts)
            i += 1
            continue
        if not allow('fold', lambda: stmt_text(items[i])):
            i += 1
            continue
        cr, a, b, tmpl = c
        is_float = tmpl is None
        s = _sobj(items[i])
        operands = s.acc.use & ~regs.bit('xer.so')
        crb = reg_bits(cr)
        all_folded = True
        j = i + 1
        while j < len(items):
            it = items[j]
            k = it[0]
            if k in ('label', 'ret'):
                break
            if k == 'asm':
                j += 1
                continue
            if k == 'flush':
                if it[1] & crb:
                    all_folded = False
                    break
                j += 1
                continue
            if k == 'reload':
                if it[1] & (crb | operands):
                    break
                j += 1
                continue
            cond = _cond_of(it)
            sj = _sobj(it)
            # Any jump passed on the way (also one on another condition: beq cr0 -> X with X reading cr6,
            # sub_822065F0) may lead to code that still reads crN: then the compare stays.
            if sj is not None and stmts is not None:
                for t in sj.succ[1:]:
                    if t >= 0 and stmts[t].live_in & crb:
                        all_folded = False
            if k == 'stmt' and type(it[1]) in (Goto, Switch, Return):
                # control leaves here: stop, so the check below sees what is live at the jump (= its targets),
                # not at the code after it (cmpw cr6; b X with X reading cr6 - sub_82BC8DD0)
                break
            if cond is not None and any(type(x) is Name and x.id == cr for x in walk(cond)):
                new, ok = _subst_cr(cond, cr, a, b, is_float)
                if ok:
                    items[j] = _with_cond(it, new)
                else:
                    all_folded = False
            elif sj is not None and sj.acc.use & crb:
                all_folded = False  # read some other way (mfcr ...)
                break
            if sj is not None and (_item_writes(it) & (operands | crb)):
                break
            j += 1
        if all_folded:
            live = _live_at(items, j)
            if live is not None and not (live & crb):
                items[i] = ('asm', '(compare folded into the branches below)') if False else ('nop',)
        i += 1
    items[:] = [it for it in items if it[0] != 'nop']


# ---------------------------------------------------------------------------------------------
# inlining single-use temporaries

def _full_write_target(st):
    """(reg, view, expr) for 'rN.view = expr' writing the whole register."""
    if type(st) is not Assign or st.op != '=':
        return None
    lhs = st.lhs
    if type(lhs) is Member and type(lhs.obj) is Name and lhs.field in ('u64', 's64', 'f64'):
        r = lhs.obj.id
        rb_ = r.split('_')[0]
        if (rb_.startswith('r') or rb_.startswith('f')) and rb_[1:].isdigit():
            if r.startswith('f') and lhs.field != 'f64':
                return None
            return r, lhs.field, st.rhs
    return None


_VIEW_TYPE = {'u32': 'uint32_t', 's32': 'int32_t', 'u16': 'uint16_t', 's16': 'int16_t', 'u8': 'uint8_t',
              's8': 'int8_t', 'u64': 'uint64_t', 's64': 'int64_t', 'f64': 'double'}


def _fits_u32(e):
    return type(e) is Call and type(e.func) is Name and e.func.id in ('REX_LOAD_U32', 'REX_LOAD_U16', 'REX_LOAD_U8',
                                                                         'LOAD32', 'LOAD16', 'LOAD8')


def _is64(e):
    """Is the C type of e certainly 64-bit (so it can stand for a 64-bit register view)?"""
    if type(e) is Member and e.field in ('u64', 's64'):
        return True
    if type(e) is Cast and e.type in ('uint64_t', 'int64_t'):
        return True
    if type(e) is Call and type(e.func) is Name and e.func.id in ('uint64_t', 'int64_t', 'REX_LOAD_U64', 'LOAD64'):
        return True
    if type(e) is Binary and e.op in ('+', '-', '*', '&', '|', '^') and (_is64(e.a) or _is64(e.b)):
        return True
    return False


def _replace_use(e, r, expr, wview):
    count = [0]

    def f(x):
        if type(x) is Member and type(x.obj) is Name and x.obj.id == r:
            count[0] += 1
            v = x.field
            if v in ('u64', 's64') and wview in ('u64', 's64'):
                # a 64-bit register read: the expression must keep 64-bit arithmetic (LOAD32(a) - LOAD32(b) is a
                # 32-bit subtraction in C; the recompiled code subtracts the zero-extended 64-bit values)
                e2 = expr if _is64(expr) or type(expr) is Num else Cast(_VIEW_TYPE[wview], expr)
                return e2 if v == wview else Cast(_VIEW_TYPE[v], e2)
            if v == wview or (v == 'u32' and wview == 'u64' and _fits_u32(expr)):
                return expr
            if v == 'u32' and wview in ('u64', 's64'):
                return Call(Name('uint32_t'), [expr])
            if v in _VIEW_TYPE and wview in ('u64', 's64'):
                return Call(Name(_VIEW_TYPE[v]), [expr])
            count[0] += 100  # cannot express
        return None
    new = map_expr(e, f)
    return new, count[0]


def _uses_in_item(it, r):
    """Number of reads of register r in an item (approximation from its tree)."""
    k = it[0]
    if k == 'flush':
        vars_ = it[2] if len(it) > 2 else {}
        if vars_ and r.split('_')[0] in vars_:
            return 1 if vars_[r.split('_')[0]] == r and it[1] & reg_bits(r.split('_')[0]) else 0
        return 1 if it[1] & reg_bits(r.split('_')[0]) else 0
    if k == 'stmt':
        st = it[1]
        n = 0
        for part in _stmt_exprs(st):
            n += sum(1 for x in walk(part) if type(x) is Member and type(x.obj) is Name and x.obj.id == r)
        if type(st) is Assign and type(st.lhs) is Member and type(st.lhs.obj) is Name and st.lhs.obj.id == r:
            n -= 1  # the target itself
            if st.op != '=' or st.lhs.field not in ('u64', 's64', 'f64'):
                n += 1
        return n
    if k == 'if':
        n = sum(1 for x in walk(it[1]) if type(x) is Name and x.id == r)
        return n + sum(_uses_in_item(x, r) for x in it[2])
    return 0


def _stmt_exprs(st):
    t = type(st)
    if t is Assign:
        return [st.lhs, st.rhs]
    if t is ExprStmt:
        return [st.e]
    if t is If:
        return [st.cond] + _stmt_exprs(st.body)
    if t is Block:
        out = []
        for x in st.stmts:
            out.extend(_stmt_exprs(x))
        return out
    if t is Switch:
        return [st.e]
    if t is Decl and st.init is not None:
        return [st.init]
    return []


def _substitute(it, r, expr, wview):
    k = it[0]
    st = it[1]
    if k == 'stmt':
        t = type(st)
        if t is Assign:
            lhs = st.lhs
            if type(lhs) is Member and type(lhs.obj) is Name and lhs.obj.id == r:
                rhs, n = _replace_use(st.rhs, r, expr, wview)
                return ('stmt', Assign(lhs, st.op, rhs)) + tuple(it[2:]), n
            lhs2, n1 = _replace_use(lhs, r, expr, wview)
            rhs, n2 = _replace_use(st.rhs, r, expr, wview)
            return ('stmt', Assign(lhs2, st.op, rhs)) + tuple(it[2:]), n1 + n2
        if t is ExprStmt:
            e, n = _replace_use(st.e, r, expr, wview)
            return ('stmt', ExprStmt(e)) + tuple(it[2:]), n
        if t is If:
            c, n = _replace_use(st.cond, r, expr, wview)
            return ('stmt', If(c, st.body)) + tuple(it[2:]), n
        return it, 100
    if k == 'if':
        c, n = _replace_use(it[1], r, expr, wview)
        return ('if', c, it[2]) + tuple(it[3:]), n
    return it, 100


def _all_flushed(items):
    b = 0
    for it in items:
        if it[0] == 'flush':
            b |= it[1]
        elif it[0] == 'if':
            b |= _all_flushed(it[2])
    return b


def var_counts(items):
    """variable -> (definitions, reads) over the whole item list (web variables of split registers)."""
    defs, reads = {}, {}

    def add(d, k):
        d[k] = d.get(k, 0) + 1

    def visit(lst):
        for it in lst:
            k = it[0]
            if k == 'stmt':
                st = it[1]
                if type(st) is Assign and type(st.lhs) is Member and type(st.lhs.obj) is Name:
                    add(defs, st.lhs.obj.id)
                    if st.op != '=' or st.lhs.field not in ('u64', 's64', 'f64'):
                        add(reads, st.lhs.obj.id)
                    exprs = [st.rhs]
                else:
                    exprs = _stmt_exprs(st)
                for e in exprs:
                    for x in walk(e):
                        if type(x) is Name:
                            add(reads, x.id)
            elif k in ('if', 'ifelse', 'dowhile', 'while'):
                for x in walk(it[1]):
                    if type(x) is Name:
                        add(reads, x.id)
            elif k == 'flush':
                vars_ = it[2] if len(it) > 2 else {}
                for r in regs.names(it[1]):
                    reg = r.split('.')[0]
                    add(reads, vars_.get(reg, reg))
            elif k == 'reload':
                vars_ = it[2] if len(it) > 2 else {}
                for r in regs.names(it[1]):
                    reg = r.split('.')[0]
                    add(defs, vars_.get(reg, reg))
            for sub in _child_lists(it):
                visit(sub)
    visit(items)
    return {v: (defs.get(v, 0), reads.get(v, 0)) for v in set(defs) | set(reads)}


def _expr_inputs(expr):
    """Resource bits of the register variables an expression reads (r31_3 -> r31)."""
    bits = 0
    for x in walk(expr):
        if type(x) is Name:
            try:
                bits |= reg_bits(x.id.split('_')[0])
            except (KeyError, ValueError):
                pass
    return bits


def inline_temps(items, flushed=None, counts=None):
    if flushed is None:
        flushed = _all_flushed(items)  # (a register written to the context later must keep its value)
    if counts is None:
        counts = var_counts(items)
    changed = True
    while changed:
        changed = False
        i = 0
        while i < len(items):
            it = items[i]
            if it[0] == 'if':
                inline_temps(it[2], flushed, counts)
            tgt = _full_write_target(it[1]) if it[0] == 'stmt' else None
            s = _sobj(it)
            if not tgt or s is None or not _pure(tgt[2]):
                i += 1
                continue
            r, wview, expr = tgt
            rb = reg_bits(r.split('_')[0])
            # Inline only a variable that is read exactly once in the whole function (write-backs to the
            # context included). Liveness from before the earlier passes is not used: folding moves reads
            # (a compare's operands into the branch below it).
            if counts.get(r, (0, 0))[1] != 1:
                i += 1
                continue
            # (the registers the expression reads NOW: after an earlier inlining into this statement they are
            # more than the instruction's own - r7 = r10 << 2 that became r7 = (r31 >> 5) << 2 reads r31)
            inputs = s.acc.use | _expr_inputs(expr)
            mem = _reads_memory(expr)
            fp = _has_fp(expr)
            j = i + 1
            use_j = None
            ok = False
            while j < len(items):
                it2 = items[j]
                k = it2[0]
                if k in ('label', 'ret'):
                    break
                if k == 'asm':
                    j += 1
                    continue
                n = _uses_in_item(it2, r)
                if n:
                    if n == 1 and k in ('stmt', 'if'):
                        use_j = j
                        s2 = _sobj(it2)
                        ok = s2 is not None
                        # the use's own writes must not clobber the expression inputs before it reads them:
                        # (it reads first, so fine)
                    break
                if _item_writes(it2) & (inputs | rb):
                    break
                if mem and _writes_memory(it2):
                    break
                if fp and _is_fpscr(it2):
                    break  # floating-point results depend on the host FPU mode set here
                if k == 'if':
                    break
                j += 1
            if ok and use_j is not None and \
                    allow('inline', lambda: f'{stmt_text(items[i])}  INTO  {stmt_text(items[use_j])}'):
                new, n = _substitute(items[use_j], r, expr, wview)
                if n == 1:
                    items[use_j] = new
                    del items[i]
                    counts.pop(r, None)
                    changed = True
                    continue
            i += 1


def merge_asm(items):
    """Consecutive instruction comments (left behind by folding / inlining) become one line."""
    out = []
    for it in items:
        if it[0] == 'asm' and out and out[-1][0] == 'asm':
            out[-1] = ('asm', out[-1][1] + ' | ' + it[1])
            continue
        if it[0] == 'if':
            merge_asm(it[2])
        out.append(it)
    items[:] = out


# ---------------------------------------------------------------------------------------------
# dead stores

def remove_dead(items, flushed=None, counts=None):
    """Drops assignments to registers that nothing reads afterwards (and that are never written
    back to the context): carry flags of shifts, overwritten temporaries, ..."""
    if flushed is None:
        flushed = _all_flushed(items)
    if counts is None:
        counts = var_counts(items)
    out = []
    for it in items:
        if it[0] == 'stmt':
            st = it[1]
            s = _sobj(it)
            if type(st) is Assign and s is not None and not s.acc.sync and s.acc.def_ and _pure(st.rhs) and \
                    _local_target(st.lhs):
                # (only variables nobody reads anywhere: liveness from before the earlier passes is stale)
                v = _target_var(st.lhs)
                if v is not None and counts.get(v, (0, 0))[1] == 0 and allow('dead', lambda: stmt_text(it)):
                    continue
        for sub in _child_lists(it):
            remove_dead(sub, flushed, counts)
        out.append(it)
    items[:] = out


def _target_var(lhs):
    x = lhs
    while type(x) in (Member, Index):
        x = x.obj
    return x.id if type(x) is Name else None


def _local_target(lhs):
    x = lhs
    while type(x) in (Member, Index):
        x = x.obj
    return type(x) is Name and x.id not in ('ctx', 'temp', 'ea')


def _child_lists(it):
    k = it[0]
    if k in ('if', 'dowhile', 'while', 'loop'):
        return [it[2]]
    if k == 'ifelse':
        return [it[2], it[3]]
    return []


# ---------------------------------------------------------------------------------------------
# redundant context traffic

def drop_redundant_sync(items, sm=None):
    """A value written back to the context register it was just read from (no call or other write to that
    register in between, the variable unchanged) is already there: the write goes. A value read from the
    context that nothing uses any more is not read. Straight-line code only; state is reset at labels,
    returns and around nested blocks."""
    import summarize
    if sm is None:
        import lift
        sm = lift.summaries()
    inputs, mods = sm['inputs'], sm['mods']

    def walk_list(lst):
        known = {}  # context resource name -> variable that holds the same value

        def forget_var(v):
            for k in [k for k, x in known.items() if x == v]:
                del known[k]
        for idx, it in enumerate(lst):
            k = it[0]
            if k in ('label', 'ret'):
                known.clear()
            elif k == 'reload':
                vars_ = (it[2] if len(it) > 2 else None) or {}
                for r in regs.names(it[1]):
                    reg, _, field = r.partition('.')
                    v = vars_.get(reg, reg) + ('.' + field if field else '')
                    forget_var(v)
                    if len(it) <= 3:          # (a native result goes into the variable only, not the context)
                        known[r] = v
            elif k == 'flush':
                if len(it) > 3:               # (native arguments / return value: not context writes)
                    continue
                vars_ = (it[2] if len(it) > 2 else None) or {}
                keep = 0
                for r in regs.names(it[1]):
                    reg, _, field = r.partition('.')
                    v = vars_.get(reg, reg) + ('.' + field if field else '')
                    if known.get(r) == v:
                        continue              # already in the context
                    keep |= regs.bit(r)
                    known[r] = v
                if keep != it[1]:
                    lst[idx] = ('flush', keep) + tuple(it[2:])
            elif k == 'stmt':
                st, s = it[1], (it[2] if len(it) > 2 else None)
                if s is not None and s.acc.sync:
                    cm = summarize.call_summary(s.acc.callee, inputs, mods)[1]
                    for r in list(known):
                        if regs.bit(r) & cm:
                            del known[r]
                if type(st) is Assign:
                    v = _target_var(st.lhs)
                    if v is not None:
                        f = st.lhs.field if type(st.lhs) is Member and type(st.lhs.obj) is Member else None
                        forget_var(v)
                        for x in [x for x in known.values() if x.startswith(v + '.')]:
                            forget_var(x)
                    if type(st.lhs) is Member and type(st.lhs.obj) is Name and st.lhs.obj.id == 'ctx':
                        known.clear()
                else:
                    # (other statements can write a variable too: SET_V8(v1, ...) and the like; a variable they
                    # mention no longer counts as the same as the context)
                    for e in _stmt_exprs(st):
                        for x in walk(e):
                            if type(x) is Name:
                                if x.id == 'ctx' and not (s is not None and s.acc.sync):
                                    known.clear()   # (a call's context changes are its summary's, above)
                                forget_var(x.id)
                                for y in [y for y in known.values() if y.startswith(x.id + '.')]:
                                    forget_var(y)
            elif k in ('if', 'ifelse', 'dowhile', 'while', 'loop'):
                for sub in _child_lists(it):
                    walk_list(sub)
                known.clear()
            else:
                known.clear()
    walk_list(items)
    # reads from the context into variables that nothing uses
    counts = var_counts(items)

    def prune(lst):
        for idx, it in enumerate(lst):
            if it[0] == 'reload' and len(it) <= 3:
                vars_ = (it[2] if len(it) > 2 else None) or {}
                keep = 0
                for r in regs.names(it[1]):
                    reg = r.split('.')[0]
                    v = vars_.get(reg, reg)
                    if counts.get(v, (0, 0))[1] > 0:
                        keep |= regs.bit(r)
                if keep != it[1]:
                    lst[idx] = ('reload', keep) + tuple(it[2:])
            for sub in _child_lists(it):
                prune(sub)
    prune(items)
