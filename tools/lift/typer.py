"""Gives lifted registers plain C types.

A general-purpose register is 64 bits wide, but the game is 32-bit code: most values only ever
have their low 32 bits looked at. A register whose every read only needs the low 32 bits (a
32-bit view, or a 64-bit view feeding an operation whose low 32 result bits depend only on the
low 32 operand bits: + - * & | ^ ~ <<, 32-bit stores, address computations, ...) becomes a
uint32_t; the rest stay uint64_t. A floating-point register that is only used as a double becomes
a double. Values written to the context (call arguments, results) are written as 64 bits; the
upper half of a uint32_t register is then zero, which is only allowed where the reader does not
look at it (demand information from summarize.py; without it such registers stay 64-bit).

The rewrite keeps every value bit that anybody reads identical to the recompiled code.
"""
from cparse import (Member, Name, Index, Call, Cast, Unary, Binary, Ternary, InitList, Num, Assign, ExprStmt, Decl,
                    If, Block, Switch, map_expr)

GPR = {f'r{i}' for i in range(32)}
FPR = {f'f{i}' for i in range(32)}
NARROW_VIEWS = {'u32', 's32', 'u16', 's16', 'u8', 's8'}
WIDE_VIEWS = {'u64', 's64'}
_NARROW_TYPES = {'uint32_t', 'int32_t', 'uint16_t', 'int16_t', 'uint8_t', 'int8_t', 'u32', 'u16', 'u8', 'int',
                 'unsigned', 'uint', 'bool'}
_SAME_DEMAND = {'+', '-', '*', '&', '|', '^'}
_NARROW_CALLS = {'REX_LOAD_U8', 'REX_LOAD_U16', 'REX_LOAD_U32', 'REX_LOAD_U64', 'REX_RAW_ADDR',
                 '__builtin_rotateleft32', '__builtin_bswap32', '__builtin_clz', 'REX_STORE_U8', 'REX_STORE_U16',
                 'REX_STORE_U32'}
CTYPE = {'u32': 'uint32_t', 's32': 'int32_t', 'u16': 'uint16_t', 's16': 'int16_t', 'u8': 'uint8_t', 's8': 'int8_t',
         'u64': 'uint64_t', 's64': 'int64_t'}


def _b(name):
    """Register of a variable: 'r11_2' (a web of r11, see webs.py) -> 'r11'."""
    return name.split('_')[0] if '_' in name else name


def reg_view(e):
    """('r3', 'u32') for the node r3.u32 (localized register view)."""
    if type(e) is Member and type(e.obj) is Name and (_b(e.obj.id) in GPR or _b(e.obj.id) in FPR) and not e.arrow:
        return e.obj.id, e.field
    return None


class Typing:
    def __init__(self):
        self.wide = set()       # GPRs that must keep 64 bits
        self.not_double = set()  # FPRs used other than as a double
        # 64-bit-read variables whose upper half is known from how they are produced (extkind.py):
        # 'z' zero / 's' sign extension -> stored as uint32_t / int32_t, written back extended
        self.ext = {}

    def gpr_type(self, r):
        if r in self.wide:
            k = self.ext.get(r)
            return 'uint32_t' if k == 'z' else 'int32_t' if k == 's' else 'uint64_t'
        return 'uint32_t'


def _demands(e, narrow, wide, edges):
    """Walk e with demand `narrow`: True (only the low 32 bits of e matter), False (all 64), or a
    register name (the low 32 bits matter iff that register is 32-bit). Adds to `wide` every GPR
    whose 64-bit view is read with a full demand, and to `edges` (src, dst) for 64-bit reads of src
    whose demand is that of dst."""
    stack = [(e, narrow)]
    while stack:
        x, n = stack.pop()
        t = type(x)
        rv = reg_view(x)
        if rv:
            r, v = rv
            if _b(r) in GPR and v in WIDE_VIEWS:
                if n is False:
                    wide.add(r)
                elif n is not True:
                    edges.add((r, n))  # (self edges too: r3 = r3 + 1 links two values of r3)
            continue
        if t is Binary:
            if x.op in _SAME_DEMAND:
                stack.append((x.a, n))
                stack.append((x.b, n))
            elif x.op == '<<':
                # x << k (k >= 32) moves only the low 64-k bits: with k = 32 the upper half is discarded
                k = x.b.value() if type(x.b) is Num and x.b.text.rstrip('uUlL').isdigit() else None
                stack.append((x.a, True if (k is not None and k >= 32) else n))
                stack.append((x.b, True))
            else:  # >> / % == < ... && ||
                stack.append((x.a, False))
                stack.append((x.b, False))
        elif t is Unary:
            stack.append((x.x, n if x.op in ('-', '~', '+') else False))
        elif t is Cast:
            ty = x.type.replace('const', '').strip()
            stack.append((x.x, True if ty in _NARROW_TYPES else False))
        elif t is Call:
            f = x.func
            fname = f.id if type(f) is Name else None
            if fname in ('uint32_t', 'int32_t', 'uint16_t', 'int16_t', 'uint8_t', 'int8_t', 'int'):
                for a in x.args:
                    stack.append((a, True))
            elif fname in ('static_cast', 'reinterpret_cast') and x.tmpl in _NARROW_TYPES:
                for a in x.args:
                    stack.append((a, True))
            elif fname in _NARROW_CALLS:
                for a in x.args:
                    stack.append((a, True))
            elif fname == 'REX_STORE_U64':
                stack.append((x.args[0], True))
                stack.append((x.args[1], False))
            elif type(f) is Member and f.field == 'compare':
                narrow_cmp = x.tmpl in ('uint32_t', 'int32_t')
                for a in x.args[:2]:
                    stack.append((a, narrow_cmp))
            else:
                stack.append((f, False))
                for a in x.args:
                    stack.append((a, False))
        elif t is Ternary:
            stack.append((x.c, False))
            stack.append((x.a, n))
            stack.append((x.b, n))
        elif t is Member:
            stack.append((x.obj, False))
        elif t is Index:
            stack.append((x.obj, False))
            stack.append((x.index, True))
        elif t is InitList:
            for a in x.items:
                stack.append((a, False))


def _target_demand(lhs):
    """Demand of an assignment's right-hand side given its target."""
    rv = reg_view(lhs)
    if rv:
        r, v = rv
        if _b(r) in GPR:
            if v in NARROW_VIEWS:
                return True
            return r  # 32-bit iff the target register is
        return False
    if type(lhs) is Member and type(lhs.obj) is Name and lhs.obj.id == 'temp':
        return lhs.field in NARROW_VIEWS
    if type(lhs) is Name and lhs.id == 'ea':
        return True
    return False


def demand_info(st, wide=None, edges=None):
    """(wide, edges) of one localized statement (see _demands)."""
    if wide is None:
        wide, edges = set(), set()
    t = type(st)
    if t is Assign:
        n = _target_demand(st.lhs)
        if st.op != '=' and st.op not in ('+=', '-=', '*=', '&=', '|=', '^=', '<<='):
            n = False
            rv = reg_view(st.lhs)
            if rv and _b(rv[0]) in GPR and rv[1] in WIDE_VIEWS:
                wide.add(rv[0])
        _demands(st.rhs, n, wide, edges)
        x = st.lhs
        while type(x) in (Member, Index):
            if type(x) is Index:
                _demands(x.index, True, wide, edges)
            x = x.obj
    elif t is ExprStmt:
        e = st.e
        if type(e) is Unary and e.op in ('++', '--', 'post++', 'post--'):
            return wide, edges
        _demands(e, False, wide, edges)
    elif t is Decl:
        if st.init is not None:
            _demands(st.init, False, wide, edges)
    elif t is If:
        _demands(st.cond, False, wide, edges)
        demand_info(st.body, wide, edges)
    elif t is Block:
        for x in st.stmts:
            demand_info(x, wide, edges)
    elif t is Switch:
        _demands(st.e, False, wide, edges)
    return wide, edges


def close_wide(wide, edges):
    """Registers that must be 64-bit: `wide` plus every src feeding a 64-bit dst."""
    wide = set(wide)
    changed = True
    while changed:
        changed = False
        for src, dst in edges:
            if dst in wide and src not in wide:
                wide.add(src)
                changed = True
    return wide


def compute(stmts_local, flush_wide):
    """stmts_local: localized statements (cparse trees using r3.u64 ... names).
    flush_wide: GPRs written to the context where the reader needs all 64 bits."""
    typing = Typing()
    wide, edges = set(flush_wide), set()
    for st in stmts_local:
        demand_info(st, wide, edges)
    typing.wide = close_wide(wide, edges)
    for st in stmts_local:
        for x in _all_nodes(st):
            rv = reg_view(x)
            if rv and _b(rv[0]) in FPR and rv[1] != 'f64':
                typing.not_double.add(rv[0])
    return typing


def _all_nodes(st):
    from cparse import walk
    t = type(st)
    if t is Assign:
        yield from walk(st.lhs)
        yield from walk(st.rhs)
    elif t is ExprStmt:
        yield from walk(st.e)
    elif t is Decl and st.init is not None:
        yield from walk(st.init)
    elif t is If:
        yield from walk(st.cond)
        yield from _all_nodes(st.body)
    elif t is Block:
        for x in st.stmts:
            yield from _all_nodes(x)
    elif t is Switch:
        yield from walk(st.e)


# ---------------------------------------------------------------------------------------------
# Rewriting register views into typed variables

def _widen_big_shifts(e, typing):
    """x << k with k >= 32 is undefined for a 32-bit x in C++ (the recompiled code shifts 64-bit values):
    widen 32-bit operands first."""
    def f(x):
        if type(x) is Binary and x.op == '<<' and type(x.b) is Num:
            try:
                k = int(x.b.value())
            except Exception:
                return None
            if k >= 32 and not (type(x.a) is Cast and x.a.type in ('uint64_t', 'int64_t')):
                a = x.a
                if type(a) is Name and _b(a.id) in GPR and (a.id not in typing.wide or typing.ext.get(a.id)):
                    return Binary('<<', Cast('uint64_t', a), x.b)
                if type(a) is Cast and a.type in ('uint32_t', 'int32_t', 'uint16_t', 'int16_t', 'uint8_t', 'int8_t'):
                    return Binary('<<', Cast('uint64_t', a), x.b)
        return None
    return map_expr(e, f)


def rewrite_expr(e, typing):
    return _widen_big_shifts(_rewrite_expr(e, typing), typing)


def _rewrite_expr(e, typing):
    def f(x):
        rv = reg_view(x)
        if not rv:
            return None
        r, v = rv
        if _b(r) in GPR:
            if r in typing.wide and typing.ext.get(r) == 'z':
                if v == 'u32':
                    return Name(r)
                if v == 'u64':
                    return Cast('uint64_t', Name(r))
                if v == 's64':
                    return Cast('int64_t', Cast('uint64_t', Name(r)))
                return Cast(CTYPE[v], Name(r))
            if r in typing.wide and typing.ext.get(r) == 's':
                if v == 's32':
                    return Name(r)
                if v == 's64':
                    return Cast('int64_t', Name(r))
                if v == 'u64':
                    return Cast('uint64_t', Cast('int64_t', Name(r)))
                return Cast(CTYPE[v], Name(r))
            if r in typing.wide:
                if v == 'u64':
                    return Name(r)
                return Cast(CTYPE[v], Name(r))
            if v in ('u32', 'u64'):
                return Name(r)
            if v == 's64':
                return Cast('int32_t', Name(r))  # (only the low half is read: sign irrelevant)
            return Cast(CTYPE[v], Name(r))
        if _b(r) in FPR and r not in typing.not_double and v == 'f64':
            return Name(r)
        return None
    return map_expr(e, f)


def rewrite_stmt(st, typing):
    t = type(st)
    if t is Assign:
        rv = reg_view(st.lhs)
        rhs = rewrite_expr(st.rhs, typing)
        if rv and _b(rv[0]) in GPR:
            r, v = rv
            if r in typing.wide and typing.ext.get(r) in ('z', 's') and st.op == '=':
                return Assign(Name(r), '=', rhs)  # (its upper half is implied by how it is produced)
            if r in typing.wide:
                if v == 'u64':
                    return Assign(Name(r), st.op, rhs)
                if v == 's64' and st.op == '=':
                    return Assign(Name(r), '=', rhs)  # (int64 -> uint64 conversion keeps every bit)
                if v in ('u32', 's32') and st.op == '=':  # partial write: keep the upper half
                    return Assign(Name(r), '=', Binary('|', Binary('&', Name(r), Num('0xFFFFFFFF00000000ull')),
                                                       Call(Name('uint32_t'), [rhs])))
                return Assign(rewrite_expr(st.lhs, typing), st.op, rhs)
            # 32-bit register: any write keeps the low 32 bits
            if type(rhs) is Num and st.op == '=':
                try:
                    val = rhs.value()
                    if isinstance(val, int) and (val < 0 or val > 0xFFFF):
                        rhs = Num(f'0x{val & 0xFFFFFFFF:X}')
                except Exception:
                    pass
            if v in ('u64', 's64', 'u32', 's32') or st.op == '=':
                if v in ('u16', 's16', 'u8', 's8') and st.op == '=':
                    mask = '0xFFFF0000' if v in ('u16', 's16') else '0xFFFFFF00'
                    return Assign(Name(r), '=', Binary('|', Binary('&', Name(r), Num(mask)),
                                                       Call(Name(CTYPE['u' + v[1:]]), [rhs])))
                return Assign(Name(r), st.op, rhs)
        if rv and _b(rv[0]) in FPR and rv[0] not in typing.not_double and rv[1] == 'f64':
            return Assign(Name(rv[0]), st.op, rhs)
        return Assign(rewrite_expr(st.lhs, typing), st.op, rhs)
    if t is ExprStmt:
        return ExprStmt(rewrite_expr(st.e, typing))
    if t is Decl:
        return Decl(st.type, st.name, rewrite_expr(st.init, typing) if st.init is not None else None)
    if t is If:
        return If(rewrite_expr(st.cond, typing), rewrite_stmt(st.body, typing))
    if t is Block:
        return Block([rewrite_stmt(x, typing) for x in st.stmts])
    if t is Switch:
        return Switch(rewrite_expr(st.e, typing), st.cases, st.default)
    return st


def _is_int64(e):
    return type(e) is Cast and e.type in ('int64_t', 'uint64_t')


def decl(r, typing, init=None):
    if _b(r) in GPR:
        ty = typing.gpr_type(r)
    elif _b(r) in FPR and r not in typing.not_double:
        ty = 'double'
    else:
        return None
    return f'{ty} {r}' + (f' = {init}' if init else '{}')


def ctx_read(reg, typing, var=None):
    """Expression reading context register `reg` for the local variable `var` (default: reg)."""
    var = var or reg
    if reg in GPR:
        return f'ctx.{reg}.u32' if var not in typing.wide else f'ctx.{reg}.u64'
    if reg in FPR and var not in typing.not_double:
        return f'ctx.{reg}.f64'
    return f'ctx.{reg}'


def ctx_write(reg, typing, var=None):
    """Statement writing local variable `var` (default: reg) back to context register `reg`."""
    var = var or reg
    if reg in GPR:
        if var in typing.wide and typing.ext.get(var) == 's':
            return f'ctx.{reg}.s64 = {var};'
        return f'ctx.{reg}.u64 = {var};'
    if reg in FPR and var not in typing.not_double:
        return f'ctx.{reg}.f64 = {var};'
    return f'ctx.{reg} = {var};'
