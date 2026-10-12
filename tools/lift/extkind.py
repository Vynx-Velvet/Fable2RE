"""How a register value's upper 32 bits relate to its lower 32 bits, from the instruction that produced it.

  'z'  upper half is zero         (32/16/8-bit loads, 32-bit masks, non-negative constants, ...)
  's'  upper half is the sign of bit 31  (sign extensions, negative constants)
  None unknown (64-bit arithmetic, 64-bit loads, values from callers/callees)

A web (webs.py) whose definitions are all 'z' can live in a uint32_t even when somebody reads all
64 bits: writing it back zero-extended reproduces the original exactly (likewise 's' / int32_t).
"""
from cparse import Member, Name, Call, Cast, Binary, Num, Assign, Unary


def _num(e):
    if type(e) is Unary and e.op == '-' and type(e.x) is Num:
        v = _num(e.x)
        return -v if v is not None else None
    if type(e) is Num:
        try:
            v = e.value()
        except Exception:
            return None
        return v if isinstance(v, int) else None
    return None


def _is_call(e, *names):
    return type(e) is Call and type(e.func) is Name and e.func.id in names


def rhs_kind(lhs_view, rhs):
    """Kind of the value written by `reg.<lhs_view> = rhs` (full writes only), or ('copy', reg) for
    register copies, or None."""
    if lhs_view == 'u64':
        if _is_call(rhs, 'REX_LOAD_U8', 'REX_LOAD_U16', 'REX_LOAD_U32', 'LOAD8', 'LOAD16', 'LOAD32'):
            return 'z'
        if type(rhs) is Binary and rhs.op == '&':
            m = _num(rhs.b)
            if m is not None and 0 <= m <= 0xFFFFFFFF:
                return 'z'
        if type(rhs) is Member and type(rhs.obj) is Name and rhs.field == 'u64':
            return ('copy', rhs.obj.id)
        if type(rhs) is Member and type(rhs.obj) is Name and rhs.field in ('u32', 'u16', 'u8'):
            return 'z'
        v = _num(rhs)
        if v is not None:
            return 'z' if 0 <= v <= 0x7FFFFFFF else ('s' if -0x80000000 <= v < 0 else None)
    if lhs_view == 's64':
        v = _num(rhs)
        if v is not None:
            if 0 <= v <= 0x7FFFFFFF:
                return 'z'  # (both, in fact)
            if -0x80000000 <= v < 0:
                return 's'
            return None
        if type(rhs) is Member and type(rhs.obj) is Name and rhs.field in ('s32', 's16', 's8'):
            return 's'
        if type(rhs) is Member and type(rhs.obj) is Name and rhs.field in ('u16', 'u8'):
            return 'z'
    return None


def def_kinds(res, stmt_of_def, gpr_names):
    """res: webs.Result; stmt_of_def(i) -> localized statement at index i.
    Returns {def id: 'z' / 's' / None}."""
    kinds = {}
    copies = {}
    for k, (r, kind, i) in enumerate(res.defs):
        if r in (1, 13):
            # the stack pointer and the thread pointer are 32-bit addresses held zero-extended (set by the
            # runtime, adjusted only by small offsets)
            kinds[k] = 'z'
            continue
        if kind != 'S':
            kinds[k] = None
            continue
        st = stmt_of_def(i)
        val = None
        if type(st) is Assign and st.op == '=' and type(st.lhs) is Member and type(st.lhs.obj) is Name and \
                st.lhs.obj.id == f'r{r}':
            val = rhs_kind(st.lhs.field, st.rhs)
            if st.lhs.field in ('u32', 's32') and val is None:
                # low half written, upper half kept: same kind as before (if the new low half agrees: only
                # for 'z' is that guaranteed, since bit 31 may change)
                val = ('keep', r)
        if type(val) is tuple:
            copies[k] = (val, i)
            kinds[k] = 'pending'
        else:
            kinds[k] = val
    # resolve copies / kept halves (fixpoint, pessimistic: anything unresolved is None)
    changed = True
    while changed:
        changed = False
        for k, ((how, src), i) in copies.items():
            if kinds[k] != 'pending':
                continue
            src_reg = int(src[1:]) if how == 'copy' else src
            if how == 'copy' and src not in gpr_names:
                kinds[k] = None
                changed = True
                continue
            bs = res.rd_in[i].get(src_reg, 0)
            ks = set()
            j = 0
            while bs:
                if bs & 1:
                    ks.add(kinds.get(j))
                bs >>= 1
                j += 1
            if 'pending' in ks:
                continue
            if how == 'keep':
                kinds[k] = 'z' if ks == {'z'} else None
            else:
                kinds[k] = ks.pop() if len(ks) == 1 else None
            changed = True
    for k, v in kinds.items():
        if v == 'pending':
            kinds[k] = None
    return kinds
