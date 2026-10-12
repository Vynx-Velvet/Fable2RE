"""Shorter spellings for the recompiler's idioms (macros in Fable2Recomp/lifted/lifted.h), plus
constant folding. Pure rewrites of equivalent C++.

  temp.u32 = REX_LOAD_U32(a); f0 = double(temp.f32);    ->  f0 = double(LOAD_F32(a));
  temp.f32 = float(f1); REX_STORE_U32(a, temp.u32);      ->  STORE_F32(a, float(f1));
  f0.u64 = REX_LOAD_U64(a) / REX_STORE_U64(a, f0.u64)   ->  LOAD_F64(a) / STORE_F64(a, f0)
  simde_mm_load_si128((simde__m128i*)v1.u8)             ->  V8(v1)        (VF(v1) for floats)
  simde_mm_store_si128((simde__m128i*)v1.u8, x)         ->  SET_V8(v1, x)  (SET_VF)
  shuffle(load(REX_RAW_ADDR(ea)), VectorMaskL)          ->  VLOAD(ea)      (VSTORE(ea, x))
  ea = x; ... VLOAD(ea)                                  ->  VLOAD(x)       (single use)
"""
from cparse import (Member, Name, Index, Call, Cast, Unary, Binary, Ternary, InitList, Num, Assign, ExprStmt, Decl,
                    If, Block, Switch, map_expr, walk)
from passes import _sobj, _writes_memory, _reads_memory


def _is(x, name):
    if type(x) is not Call or type(x.func) is not Name:
        return False
    return x.func.id == name or _RENAME.get(name) == x.func.id or _RENAME.get(x.func.id) == name


def _strip_cast(x):
    while type(x) is Cast:
        x = x.x
    return x


def _vreg(x):
    """'v12' for v12.u8 / v12.u32 / v12.f32 (localized vector register view)."""
    x = _strip_cast(x)
    if type(x) is Member and type(x.obj) is Name and x.obj.id.startswith('v') and x.obj.id[1:].isdigit():
        return x.obj.id, x.field
    return None


def _is_mask_load(x):
    return _is('simde_mm_load_si128', x) if False else (
        _is(x, 'simde_mm_load_si128') and type(_strip_cast(x.args[0])) is Name and _strip_cast(x.args[0]).id == 'VectorMaskL')


def _raw_addr_arg(x):
    """ea for (cast)REX_RAW_ADDR(ea)."""
    x = _strip_cast(x)
    if _is(x, 'REX_RAW_ADDR'):
        return x.args[0]
    return None


def expr(e):
    def f(x):
        t = type(x)
        if t is Unary and x.op == '-' and type(x.x) is Num and _num(x.x) is not None:
            return _make_num(-_num(x.x))
        if t is Call and type(x.func) is Name:
            n = x.func.id
            if n == 'simde_mm_load_si128' and x.args:
                vr = _vreg(x.args[0])
                if vr and vr[1] in ('u8', 'u32', 'u16', 's8', 's16', 's32'):
                    return Call(Name('V8'), [Name(vr[0])])
            if n == 'simde_mm_load_ps' and x.args:
                vr = _vreg(x.args[0])
                if vr and vr[1] == 'f32':
                    return Call(Name('VF'), [Name(vr[0])])
            if n == 'simde_mm_shuffle_epi8' and len(x.args) == 2 and _is_mask_load(x.args[1]):
                a = x.args[0]
                if _is(a, 'simde_mm_load_si128'):
                    ea = _raw_addr_arg(a.args[0])
                    if ea is not None:
                        return Call(Name('VLOAD'), [ea])
            if n in _RENAME:
                return Call(Name(_RENAME[n]), x.args)
            if n in ('uint32_t', 'int32_t') and len(x.args) == 1 and type(x.args[0]) is Num:
                v = _num(x.args[0])
                if v is not None:
                    if n == 'uint32_t':
                        # keeps its type: 3 << 30 is a negative int (sign-extended into a 64-bit register), 3u << 30
                        # is not (sub_8227F0B0)
                        return _make_u32(v)
                    return _make_num(_s32(v))
        if t is Binary and x.op == '&' and type(x.b) is Num:
            r = _rlwinm(x)
            if r is not None:
                return r
        if t is Binary and type(x.a) is Num and type(x.b) is Num and x.op in ('+', '-', '*', '&', '|', '^'):
            a, b = _num(x.a), _num(x.b)
            if a is not None and b is not None:
                v = {'+': a + b, '-': a - b, '*': a * b, '&': a & b, '|': a | b, '^': a ^ b}[x.op]
                if _is_u32(x.a) or _is_u32(x.b):
                    if _is_wide(x.a) or _is_wide(x.b):
                        return None  # (mixed 32/64-bit constants: left to the compiler)
                    return _make_u32(v)  # unsigned 32-bit arithmetic wraps and stays unsigned
                return _make_num(_s64(v))
        if t is Binary and x.op in ('+', '-', '|', '^') and type(x.b) is Num and _num(x.b) == 0:
            return x.a
        if t is Binary and x.op == '+' and type(x.b) is Num and (_num(x.b) or 0) < 0 and _num(x.b) > -0x10000:
            return Binary('-', x.a, _make_num(-_num(x.b)))
        return None
    return map_expr(e, f)


# memory access as inline functions (the REX_ macros evaluate their address twice)
_RENAME = {'REX_LOAD_U8': 'LOAD8', 'REX_LOAD_U16': 'LOAD16', 'REX_LOAD_U32': 'LOAD32', 'REX_LOAD_U64': 'LOAD64',
           'REX_STORE_U8': 'STORE8', 'REX_STORE_U16': 'STORE16', 'REX_STORE_U32': 'STORE32',
           'REX_STORE_U64': 'STORE64', 'REX_RAW_ADDR': 'RAW'}


def _rlwinm(x):
    """__builtin_rotateleft64(r.u32 | r.u64 << 32, n) & m  (m < 2^32)  ->  32-bit shift / rotate and mask.
    The low 32 bits of that 64-bit rotate are rotl32(r, n), and the mask keeps only those."""
    m = _num(x.b)
    rot = x.a
    if m is None or not (0 <= m <= 0xFFFFFFFF) or not _is(rot, '__builtin_rotateleft64') or len(rot.args) != 2:
        return None
    n = _num(rot.args[1]) if type(rot.args[1]) is Num else None
    v = rot.args[0]
    if n is None or type(v) is not Binary or v.op != '|' or type(v.b) is not Binary or v.b.op != '<<':
        return None
    lo, hi = v.a, v.b.a
    if not (type(lo) is Member and type(hi) is Member and lo.field == 'u32' and hi.field == 'u64' and
            type(lo.obj) is Name and type(hi.obj) is Name and lo.obj.id == hi.obj.id and _num(v.b.b) == 32):
        return None
    n &= 31
    val = lo
    if n == 0:
        return Binary('&', val, _make_num(m)) if m != 0xFFFFFFFF else val
    low_mask = (1 << n) - 1
    if m & low_mask == 0:  # only bits shifted in from the left side: a left shift
        shifted = Binary('<<', val, Num(str(n)))
        return shifted if m == (0xFFFFFFFF & ~low_mask) else Binary('&', shifted, _make_num(m))
    if m <= low_mask:  # only the bits rotated around: a right shift
        k = 32 - n
        shifted = Binary('>>', val, Num(str(k)))
        return shifted if m == (1 << n) - 1 else Binary('&', shifted, _make_num(m))
    return Binary('&', Call(Name('__builtin_rotateleft32'), [val, Num(str(n))]), _make_num(m))


def _num(n):
    try:
        v = n.value()
    except Exception:
        return None
    return v if isinstance(v, int) else None


def _s64(v):
    v &= 0xFFFFFFFFFFFFFFFF
    return v - (1 << 64) if v >> 63 else v


def _s32(v):
    v &= 0xFFFFFFFF
    return v - (1 << 32) if v >> 31 else v


def _is_u32(n):
    """An unsigned 32-bit literal (3u)."""
    t = n.text.lower()
    return t.endswith('u') and not t.endswith(('ul', 'lu'))


def _is_wide(n):
    t = n.text.lower()
    return t.endswith(('l', 'ul', 'lu', 'll', 'ull'))


def _make_u32(v):
    v &= 0xFFFFFFFF
    return Num(f'{v}u' if v < 0x10000 else f'0x{v:X}u')


def _make_num(v):
    if -0x10000 < v < 0x10000:
        return Num(str(v))
    if 0 <= v <= 0xFFFFFFFF:
        return Num(f'0x{v:X}')
    if -0x80000000 <= v < 0:
        return Num(str(v))
    return Num(str(v) + ('ll' if v < 0 else 'ull'))


def stmt(st):
    t = type(st)
    if t is Assign:
        lhs, rhs = st.lhs, expr(st.rhs)
        # f0.u64 = REX_LOAD_U64(a)  ->  f0.f64 = LOAD_F64(a)
        if type(lhs) is Member and lhs.field == 'u64' and type(lhs.obj) is Name and lhs.obj.id.startswith('f') and \
                _is(rhs, 'REX_LOAD_U64') and st.op == '=':
            return Assign(Member(lhs.obj, 'f64'), '=', Call(Name('LOAD_F64'), rhs.args))
        return Assign(lhs, st.op, rhs)
    if t is ExprStmt:
        e = expr(st.e)
        if _is(e, 'REX_STORE_U64') and len(e.args) == 2:
            v = e.args[1]
            if type(v) is Member and v.field == 'u64' and type(v.obj) is Name and v.obj.id.startswith('f'):
                return ExprStmt(Call(Name('STORE_F64'), [e.args[0], Member(v.obj, 'f64')]))
        if type(e) is Call and type(e.func) is Name and e.args:
            n = e.func.id
            if n == 'simde_mm_store_si128':
                vr = _vreg(e.args[0])
                if vr and vr[1] in ('u8', 'u32', 'u16', 's8', 's16', 's32'):
                    return ExprStmt(Call(Name('SET_V8'), [Name(vr[0]), e.args[1]]))
                ea = _raw_addr_arg(e.args[0])
                v = e.args[1]
                if ea is not None and _is(v, 'simde_mm_shuffle_epi8') and _is_mask_load(v.args[1]):
                    return ExprStmt(Call(Name('VSTORE'), [ea, v.args[0]]))
            if n == 'simde_mm_store_ps':
                vr = _vreg(e.args[0])
                if vr and vr[1] == 'f32':
                    return ExprStmt(Call(Name('SET_VF'), [Name(vr[0]), e.args[1]]))
        return ExprStmt(e)
    if t is If:
        return If(expr(st.cond), stmt(st.body))
    if t is Block:
        return Block([stmt(x) for x in st.stmts])
    if t is Switch:
        return Switch(expr(st.e), st.cases, st.default)
    if t is Decl:
        return Decl(st.type, st.name, expr(st.init) if st.init is not None else None)
    return st


def apply(items, first=False):
    """Rewrites statements in place (recursively) and inlines the scratch variables. first: nothing
    has been moved between instructions yet, so the recompiler's per-instruction scratch variables
    are dead at the next instruction."""
    for i, it in enumerate(items):
        k = it[0]
        if k == 'stmt':
            items[i] = ('stmt', stmt(it[1])) + tuple(it[2:])
        elif k == 'if':
            items[i] = ('if', expr(it[1]), it[2]) + tuple(it[3:])
            apply(it[2], first)
        elif k == 'ifelse':
            items[i] = ('ifelse', expr(it[1]), it[2], it[3])
            apply(it[2])
            apply(it[3])
        elif k in ('dowhile', 'while'):
            items[i] = (k, expr(it[1]), it[2])
            apply(it[2])
        elif k == 'loop':
            apply(it[2])
    _inline_scratch(items, first)


# ---------------------------------------------------------------------------------------------
# scratch variables: temp (PPCRegister) and ea (uint32_t)

def _scratch_write(st):
    """('temp', 'u32', expr) / ('ea', None, expr) for full writes of the scratch variables."""
    if type(st) is not Assign or st.op != '=':
        return None
    lhs = st.lhs
    if type(lhs) is Name and lhs.id == 'ea':
        return 'ea', None, st.rhs
    if type(lhs) is Member and type(lhs.obj) is Name and lhs.obj.id == 'temp' and lhs.field in ('u32', 'f32', 'u64',
                                                                                               's64', 'f64'):
        return 'temp', lhs.field, st.rhs
    return None


def _scratch_reads(e, var):
    n = 0
    for x in walk(e):
        if var == 'ea' and type(x) is Name and x.id == 'ea':
            n += 1
        if var == 'temp' and type(x) is Member and type(x.obj) is Name and x.obj.id == 'temp':
            n += 1
    return n


def _exprs_of_item(it):
    k = it[0]
    if k == 'stmt':
        st = it[1]
        t = type(st)
        if t is Assign:
            return [st.lhs, st.rhs]
        if t is ExprStmt:
            return [st.e]
        if t is If:
            return [st.cond] + (_exprs_of_item(('stmt', st.body)))
        if t is Block:
            out = []
            for x in st.stmts:
                out.extend(_exprs_of_item(('stmt', x)))
            return out
        if t is Switch:
            return [st.e]
        return []
    if k in ('if', 'dowhile', 'while', 'ifelse'):
        return [it[1]]
    return []


def _replace_scratch(e, var, field, value):
    def f(x):
        if var == 'ea' and type(x) is Name and x.id == 'ea':
            return value
        if var == 'temp' and type(x) is Member and type(x.obj) is Name and x.obj.id == 'temp':
            if x.field == field:
                return value
            if field == 'u32' and x.field == 'f32':
                if _is(value, 'REX_LOAD_U32'):
                    return Call(Name('LOAD_F32'), value.args)
                return Call(Name('AS_F32'), [value])
            if field == 'f32' and x.field == 'u32':
                return Call(Name('AS_U32'), [value])
            raise ValueError
        return None
    return map_expr(e, f)


def _inline_scratch(items, first=False):
    i = 0
    while i < len(items):
        it = items[i]
        w = _scratch_write(it[1]) if it[0] == 'stmt' else None
        if not w:
            i += 1
            continue
        var, field, value = w
        # the single use: the next item (skipping comments) must read it once and nothing later before
        # the next write of the variable
        j = i + 1
        while j < len(items) and items[j][0] == 'asm':
            j += 1
        if j >= len(items) or items[j][0] not in ('stmt', 'if'):
            i += 1
            continue
        uses = sum(_scratch_reads(e, var) for e in _exprs_of_item(items[j]))
        st_j = items[j][1]
        target_is_var = items[j][0] == 'stmt' and _scratch_write(st_j) and _scratch_write(st_j)[0] == var
        if uses != 1 or not _dead_after(items, j, var, target_is_var, first):
            i += 1
            continue
        # STORE_F32 pattern: temp.f32 = x; REX_STORE_U32(a, temp.u32)
        try:
            new = _rewrite_item(items[j], var, field, value)
        except ValueError:
            i += 1
            continue
        items[j] = new
        del items[i]
    return items


def _rewrite_item(it, var, field, value):
    k = it[0]
    if k == 'stmt':
        st = it[1]
        t = type(st)
        if t is ExprStmt and _is(st.e, 'REX_STORE_U32') and field == 'f32' and var == 'temp' and \
                type(st.e.args[1]) is Member and type(st.e.args[1].obj) is Name and st.e.args[1].obj.id == 'temp':
            return ('stmt', ExprStmt(Call(Name('STORE_F32'), [st.e.args[0], value]))) + tuple(it[2:])
        if t is Assign:
            return ('stmt', Assign(_replace_scratch(st.lhs, var, field, value) if type(st.lhs) is not Name else st.lhs,
                                   st.op, _replace_scratch(st.rhs, var, field, value))) + tuple(it[2:])
        if t is ExprStmt:
            return ('stmt', ExprStmt(_replace_scratch(st.e, var, field, value))) + tuple(it[2:])
        if t is If:
            return ('stmt', If(_replace_scratch(st.cond, var, field, value), st.body)) + tuple(it[2:])
        raise ValueError
    if k == 'if':
        return ('if', _replace_scratch(it[1], var, field, value), it[2]) + tuple(it[3:])
    raise ValueError


def _dead_after(items, j, var, overwritten, first=False):
    if overwritten:
        return True
    for k in range(j + 1, len(items)):
        it = items[k]
        if first and it[0] in ('asm', 'label'):
            return True  # end of the instruction: the scratch variable is dead
        if it[0] == 'label':
            return False  # (joins: be safe)
        if it[0] == 'stmt':
            w = _scratch_write(it[1])
            if any(_scratch_reads(e, var) for e in _exprs_of_item(it)) and not (w and w[0] == var and
                                                                               not _scratch_reads(it[1].rhs, var)):
                return False
            if w and w[0] == var:
                return True
        elif it[0] in ('if', 'ifelse', 'dowhile', 'while', 'loop'):
            if _mentions_deep(it, var):
                return False
    return True


def _mentions_deep(it, var):
    for e in _exprs_of_item(it):
        if _scratch_reads(e, var):
            return True
    for sub in ([it[2]] if it[0] in ('if', 'dowhile', 'while', 'loop') else [it[2], it[3]] if it[0] == 'ifelse' else []):
        for x in sub:
            if _mentions_deep(x, var) if x[0] != 'stmt' else any(_scratch_reads(e, var) for e in _exprs_of_item(x)):
                return True
    return False
