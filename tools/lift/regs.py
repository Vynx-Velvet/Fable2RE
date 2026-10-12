"""Register resources and per-statement read/write sets for recompiled code.

Registers that become local variables in lifted code ("localized"): r0-r31, f0-f31, v0-v127,
cr0-cr7, xer, ctr. Everything else in the context (lr, msr, fpscr, reserved, ...) stays in ctx.

Liveness is tracked per *resource*: whole registers for r/f/v/ctr, single fields for the
condition registers (cr6.eq ...) and XER (xer.ca ...), because the code writes those field by
field. Sets are Python ints used as bit sets.
"""
from cparse import (Member, Name, Index, Call, Cast, Unary, Binary, Ternary, InitList, Num, Assign, ExprStmt,
                    Decl, Goto, Return, If, Block, Switch, Raw)

CR_FIELDS = ('lt', 'gt', 'eq', 'so')
XER_FIELDS = ('so', 'ov', 'ca')
NAMES = [f'r{i}' for i in range(32)] + [f'f{i}' for i in range(32)] + [f'v{i}' for i in range(128)] + \
    [f'cr{i}.{f}' for i in range(8) for f in CR_FIELDS] + [f'xer.{f}' for f in XER_FIELDS] + ['ctr']
INDEX = {n: i for i, n in enumerate(NAMES)}
ALL = (1 << len(NAMES)) - 1
LOCAL_REGS = {f'r{i}' for i in range(32)} | {f'f{i}' for i in range(32)} | {f'v{i}' for i in range(128)} | \
    {f'cr{i}' for i in range(8)} | {'xer', 'ctr'}


def bit(name):
    return 1 << INDEX[name]


def reg_bits(reg):
    """All resource bits of a localized register (cr6 -> its four fields)."""
    if reg.startswith('cr'):
        return sum(bit(f'{reg}.{f}') for f in CR_FIELDS)
    if reg == 'xer':
        return sum(bit(f'xer.{f}') for f in XER_FIELDS)
    return bit(reg)


def field_bit(reg, field):
    if reg.startswith('cr') and field in CR_FIELDS + ('un',):
        return bit(f'{reg}.{"so" if field == "un" else field}')
    if reg == 'xer' and field in XER_FIELDS:
        return bit(f'xer.{field}')
    return None


def names(bits):
    out, i = [], 0
    while bits:
        if bits & 1:
            out.append(NAMES[i])
        bits >>= 1
        i += 1
    return out


def ctype(reg):
    if reg.startswith('cr'):
        return 'PPCCRRegister'
    if reg == 'xer':
        return 'PPCXERRegister'
    if reg.startswith('v'):
        return 'PPCVRegister'
    return 'PPCRegister'


def _bits(names_):
    b = 0
    for n in names_:
        b |= reg_bits(n) if n in LOCAL_REGS and (n.startswith('cr') or n == 'xer') else bit(n)
    return b


# ABI classes. Volatile = may be changed by any call; the rest is preserved by every callee
# (callee-saved), which the lifter trusts. Xbox 360: r0, r3-r12, f0-f13, v0-v13, v32-v63, cr0/1/5/6/7,
# xer, ctr are volatile; v14-v31 and v64-v127 are saved by __savevmx/__restvmx.
VOLATILE = _bits(['r0'] + [f'r{i}' for i in range(3, 13)] + [f'f{i}' for i in range(14)] +
                 [f'v{i}' for i in range(14)] + [f'v{i}' for i in range(32, 64)] +
                 ['cr0', 'cr1', 'cr5', 'cr6', 'cr7', 'xer', 'ctr'])
NONVOLATILE = ALL & ~VOLATILE
# What a call through a pointer may read / a caller of an unknown function may expect back.
ABI_INPUTS = _bits(['r1', 'r2', 'r13'] + [f'r{i}' for i in range(3, 11)] + [f'f{i}' for i in range(1, 14)] +
                   [f'v{i}' for i in range(1, 14)])
ABI_OUTPUTS = _bits(['r3', 'r4', 'f1', 'f2', 'f3', 'f4', 'v1', 'v2', 'v3'])

FULL_VIEWS = {'u64', 's64', 'f64'}
_VEC_FULL_STORES = {'simde_mm_store_si128', 'simde_mm_store_ps', 'simde_mm_storeu_si128', 'simde_mm_storeu_ps',
                    'simde_mm_store_pd', 'simde_mm_storeu_pd'}
_CR_FULL_METHODS = {'compare', 'setFromMask', 'set_raw'}


class Unsupported(Exception):
    pass


def reg_of(e):
    """'r3' for the node ctx.r3 (Member(Name ctx, 'r3')), else None."""
    if type(e) is Member and type(e.obj) is Name and e.obj.id == 'ctx' and not e.arrow and e.field in LOCAL_REGS:
        return e.field
    return None


class Access:
    __slots__ = ('use', 'def_', 'sync', 'noreturn', 'callee', 'regs')

    def __init__(self):
        self.use = 0  # resources read before being fully written
        self.def_ = 0  # resources fully written
        self.sync = False  # passes the whole context (a call)
        self.noreturn = False
        self.callee = None  # 'sub_XXXXXXXX' / '__restgprlr_29' / 'indirect' / 'ppc_trap' ...
        self.regs = set()  # localized registers mentioned

    def seq(self, other):
        """self followed by other."""
        self.use |= other.use & ~self.def_
        self.def_ |= other.def_
        self.sync |= other.sync
        self.noreturn |= other.noreturn
        self.callee = self.callee or other.callee
        self.regs |= other.regs


def _reads_all(e, acc):
    """Records every localized register (or register field) that expression e reads.

    ctx.r3.u32 / ctx.f1.f64      -> the whole register
    ctx.cr6.eq / ctx.xer.ca      -> that field
    ctx.v0 (bare) / ctx.cr6      -> every field of the register
    crN.compare(a, b, ctx.xer)   -> only xer.so (compare copies the summary-overflow bit)
    bare ctx                     -> a call: the whole context (acc.sync)
    """
    stack = [(e, None)]
    while stack:
        x, parent = stack.pop()
        t = type(x)
        r = reg_of(x)
        if r:
            acc.regs.add(r)
            if type(parent) is Member and parent.obj is x:
                fb = field_bit(r, parent.field)
                acc.use |= fb if fb is not None else reg_bits(r)
            elif r == 'xer' and type(parent) is Call and type(parent.func) is Member and parent.func.field == 'compare':
                acc.use |= bit('xer.so')
            else:
                acc.use |= reg_bits(r)
            continue
        if t is Name:
            if x.id == 'ctx':
                acc.sync = True
            continue
        if t is Member:
            if type(x.obj) is Name and x.obj.id == 'ctx':
                continue  # ctx.lr / ctx.fpscr ...: stays in the context
            stack.append((x.obj, x))
        elif t is Index:
            stack.append((x.obj, x))
            stack.append((x.index, x))
        elif t is Call:
            f = x.func
            if type(f) is Name:
                if f.id == 'REX_CALL_INDIRECT_FUNC':
                    acc.sync = True
                    acc.callee = 'indirect'
                elif x.args and type(x.args[0]) is Name and x.args[0].id == 'ctx':
                    acc.callee = f.id
            stack.append((f, x))
            stack.extend((a, x) for a in x.args)
        elif t is Cast or t is Unary:
            stack.append((x.x, x))
        elif t is Binary:
            stack.append((x.a, x))
            stack.append((x.b, x))
        elif t is Ternary:
            stack.extend(((x.c, x), (x.a, x), (x.b, x)))
        elif t is InitList:
            stack.extend((a, x) for a in x.items)


def _target(lhs):
    """(register, written resource bits, full) for an assignment target; (None, 0, False) otherwise."""
    e = lhs
    path = []
    while True:
        r = reg_of(e)
        if r:
            break
        t = type(e)
        if t is Member:
            path.append(e.field)
            e = e.obj
        elif t is Index:
            path.append('[]')
            e = e.obj
        else:
            return None, 0, False
    if r.startswith('cr') or r == 'xer':
        if len(path) == 1:
            fb = field_bit(r, path[0])
            if fb is not None:
                return r, fb, True  # one field, fully written
        return r, reg_bits(r), False
    if len(path) == 1 and path[0] in FULL_VIEWS and not r.startswith('v'):
        return r, bit(r), True
    return r, bit(r), False


def stmt_access(s):
    acc = Access()
    t = type(s)
    if t is Assign:
        r, wbits, full = _target(s.lhs)
        _reads_all(s.rhs, acc)
        if r is None:
            _reads_all(s.lhs, acc)
            return acc
        acc.regs.add(r)
        lhs = s.lhs
        while not reg_of(lhs):
            if type(lhs) is Index:
                _reads_all(lhs.index, acc)
            lhs = lhs.obj
        if s.op != '=' or not full:
            acc.use |= wbits
        acc.def_ |= wbits
        return acc
    if t is ExprStmt:
        e = s.e
        if type(e) is Unary and e.op in ('++', '--', 'post++', 'post--'):
            r, wbits, full = _target(e.x)
            if r:
                acc.regs.add(r)
                acc.use |= wbits
                acc.def_ |= wbits
                return acc
        if type(e) is Call:
            f = e.func
            if type(f) is Name and f.id.startswith(('simde_mm_store', 'simde_mm_storeu')) and e.args:
                dst = e.args[0]
                while type(dst) is Cast:
                    dst = dst.x
                r, wbits, _ = _target(dst)
                if r:
                    acc.regs.add(r)
                    for a in e.args[1:]:
                        _reads_all(a, acc)
                    if f.id not in _VEC_FULL_STORES or type(dst) is not Member or reg_of(dst.obj) is None:
                        acc.use |= wbits
                    acc.def_ |= wbits
                    return acc
            if type(f) is Member and reg_of(f.obj) and reg_of(f.obj).startswith('cr'):
                r = reg_of(f.obj)
                acc.regs.add(r)
                for a in e.args:
                    _reads_all(a, acc)
                if f.field in _CR_FULL_METHODS:
                    acc.def_ |= reg_bits(r)
                else:
                    acc.use |= reg_bits(r)
                return acc
            if type(f) is Member and reg_of(f.obj):
                raise Unsupported(f'method on register: {f.field}')
            if type(f) is Name and f.id == '__builtin_trap':
                acc.noreturn = True
                return acc
        _reads_all(e, acc)
        return acc
    if t is Decl:
        if s.init is not None:
            _reads_all(s.init, acc)
        return acc
    if t is If:
        _reads_all(s.cond, acc)
        b = stmt_access(s.body)
        acc.use |= b.use | b.def_  # a conditional write keeps the old value on the other path
        acc.sync |= b.sync
        acc.callee = b.callee
        acc.regs |= b.regs
        return acc
    if t is Block:
        for x in s.stmts:
            acc.seq(stmt_access(x))
        return acc
    if t is Switch:
        _reads_all(s.e, acc)
        return acc
    if t in (Goto, Return):
        return acc
    raise Unsupported(f'statement {t.__name__}')


# ---------------------------------------------------------------------------------------------
# Known non-ABI helpers (assembly routines of the Xbox 360 compiler runtime)

def helper_summary(name):
    """(inputs, mods) for runtime helpers called with the whole context, or None."""
    import re
    m = re.fullmatch(r'__(save|rest)(gprlr|fpr|vmx)_(\d+)', name)
    if m:
        # They read the stack pointer / r12 / r11 / r0 and (save) the registers they store; they
        # change only scratch registers (and, for rest*, the callee-saved registers they reload,
        # which hold the same values again).
        ins = bit('r1') | bit('r11') | bit('r12') | bit('r0')
        mods = bit('r11') | bit('r12') | bit('r0')
        return ins, mods
    if name == 'ppc_trap':
        return 0, 0
    return None
