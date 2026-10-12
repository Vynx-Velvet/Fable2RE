"""Phase B2 pass: memory accesses through `this` become member accesses.

In a function whose first argument has a known class (tools/lift/classes.py), LOAD32(this + 0x7C) is printed as
self->m_7C and STORE32(this + 0x7C, v) as self->m_7C = v, with  auto* self = F2_OBJ(Class, r3);  at the top.
The address and the value read / written are the same as before: the struct only names them.
"""
import json
import os

from cparse import Member, Name, Call, Binary, Assign, ExprStmt, Ternary, Cast, Unary, Index
import typefacts

_CLASSES = None
_PLAIN = {'uint8_t': 'uint8_t', 'BigEndian<uint16_t>': 'uint16_t', 'BigEndian<uint32_t>': 'uint32_t',
          'BigEndian<uint64_t>': 'uint64_t', 'BigEndian<float>': 'float', 'BigEndian<double>': 'double',
          'f2::Be<uint16_t>': 'uint16_t', 'f2::Be<uint32_t>': 'uint32_t', 'f2::Be<uint64_t>': 'uint64_t',
          'f2::Be<float>': 'float', 'f2::Be<double>': 'double'}
_INT_LOAD = {'LOAD8': 1, 'LOAD16': 2, 'LOAD32': 4, 'LOAD64': 8}
_FLT_LOAD = {'LOAD_F32': 4, 'LOAD_F64': 8}
_INT_STORE = {'STORE8': 1, 'STORE16': 2, 'STORE32': 4, 'STORE64': 8}
_FLT_STORE = {'STORE_F32': 4, 'STORE_F64': 8}
_CASTS = ('uint8_t', 'uint16_t', 'uint32_t', 'uint64_t', 'int8_t', 'int16_t', 'int32_t', 'int64_t', 'double', 'float')


def classes():
    global _CLASSES
    if _CLASSES is None:
        p = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'cache', 'classes.json')
        _CLASSES = {'classes': {}, 'this': {}}
        if os.path.exists(p) and os.environ.get('LIFT_FIELDS', '1') != '0':
            with open(p, encoding='utf-8') as f:
                _CLASSES = json.load(f)
    return _CLASSES


def class_of(fname):
    """(struct name, {offset: (member, C type, size)}) of the function's `this`, or None."""
    cl = classes()
    key = cl['this'].get(fname)
    if key is None:
        return None
    c = cl['classes'][key]
    if not c['fields']:
        return None
    return c['struct'], {int(o): tuple(v) for o, v in c['fields'].items()}


_VARTYPES = None
_HIER = None


def vartypes():
    """{function: {variable: class key}} from the whole-program type propagation (typeflow.py), with the class
    hierarchy to look fields up in. Off unless LIFT_TYPES=1 (or types.on exists next to the cache)."""
    global _VARTYPES, _HIER
    if _VARTYPES is None:
        _VARTYPES = {}
        here = os.path.dirname(os.path.abspath(__file__))
        p = os.path.join(here, 'cache', 'vartypes.json')
        on = os.environ.get('LIFT_TYPES', '1' if os.path.exists(os.path.join(here, 'cache', 'types.on')) else '0')
        if on == '1' and os.path.exists(p) and classes()['classes']:
            import typeflow
            with open(p, encoding='utf-8') as f:
                _VARTYPES = json.load(f)['vars']
            _HIER = typeflow.Hierarchy(classes())
    return _VARTYPES, _HIER


def _base_expr(addr):
    """The sub-expression that is the base variable of 'var' / 'var + const' (as written, with its view)."""
    e = addr
    while type(e) is Cast or (type(e) is Call and type(e.func) is Name and e.func.id in _CASTS and len(e.args) == 1):
        e = e.x if type(e) is Cast else e.args[0]
    if type(e) is Binary and e.op in ('+', '-'):
        return e.a
    return e


def apply(fname, items, walk_items, entry_var):
    """Rewrites the items in place; returns the struct name if an access through `this` was rewritten (the
    caller declares `self`), else None. Accesses through other typed variables (vartypes) are printed inline:
    F2_OBJ(Class, var)->member."""
    info = class_of(fname) if entry_var is not None else None
    struct, fields = info if info is not None else (None, {})
    aliases = typefacts.this_aliases(items, walk_items, entry_var) if info is not None else set()
    typed, hier = vartypes()
    typed = dict(typed.get(fname, {}))
    if typed:
        # a typed variable must hold one value: written once, or an argument that is never written
        defs = typefacts._def_counts(list(walk_items(items)))
        typed = {v: k for v, k in typed.items() if v not in aliases and defs.get(v, 0) <= 1}
    if not aliases and not typed:
        return None
    done = [0]
    done_self = [0]
    cl = classes()['classes']

    def member(addr, size):
        """(object expression, field) of the member this access names, or None."""
        v, off = typefacts._base_offset(addr)
        if v in aliases and off in fields and fields[off][2] == size:
            done_self[0] += 1
            return Name('self'), fields[off]
        k = typed.get(v)
        if k is not None and off is not None:
            r = hier.field(k, off, size)
            if r is not None:
                owner, fld = r
                return Call(Name('F2_OBJ'), [Name(cl[owner]['struct']), _base_expr(addr)]), tuple(fld)
        return None

    def load(x, in_call):
        n = x.func.id
        size = _INT_LOAD.get(n) or _FLT_LOAD.get(n)
        fld = member(x.args[0], size)
        if fld is None:
            return None
        obj, (name, ctype, _) = fld
        is_float_field = 'float' in ctype or 'double' in ctype
        m = Member(obj, name, True)
        if n in _FLT_LOAD:
            if not is_float_field:
                if size != 4:
                    return None
                m = Call(Name('AS_F32'), [m])  # (an integer field read as a float: same bytes)
            elif in_call:
                m = Call(Name(_PLAIN[ctype]), [m])
        else:
            if is_float_field:
                return None  # (a float field read as an integer: left as a raw access)
            if in_call:
                m = Call(Name(_PLAIN[ctype]), [m])
        done[0] += 1
        return m

    def rewrite(e, in_call=False):
        """in_call: e is an argument of a call or an arm of ?: - there the member is converted to its plain type
        explicitly (templates and ?: do not convert a Be<T> on their own)."""
        t = type(e)
        if t is Call and type(e.func) is Name:
            n = e.func.id
            if (n in _INT_LOAD or n in _FLT_LOAD) and e.args:
                r = load(e, in_call)
                if r is not None:
                    return r
            is_cast = n in _CASTS  # (a cast written as a call converts by itself)
            return Call(e.func, [rewrite(x, not is_cast) for x in e.args], e.tmpl)
        if t is Call:
            return Call(rewrite(e.func), [rewrite(x, True) for x in e.args], e.tmpl)
        if t is Binary:
            return Binary(e.op, rewrite(e.a, in_call), rewrite(e.b, in_call))
        if t is Ternary:
            return Ternary(rewrite(e.c), rewrite(e.a, True), rewrite(e.b, True))
        if t is Cast:
            return Cast(e.type, rewrite(e.x))
        if t is Unary:
            return Unary(e.op, rewrite(e.x, in_call))
        if t is Member:
            return Member(rewrite(e.obj), e.field, e.arrow)
        if t is Index:
            return Index(rewrite(e.obj), rewrite(e.index))
        return e

    def store(st):
        """STOREn(this + off, v);  ->  self->m = v;"""
        if type(st) is not ExprStmt or type(st.e) is not Call or type(st.e.func) is not Name:
            return None
        n = st.e.func.id
        size = _INT_STORE.get(n) or _FLT_STORE.get(n)
        if size is None or len(st.e.args) != 2:
            return None
        fld = member(st.e.args[0], size)
        if fld is None:
            return None
        obj, (name, ctype, _) = fld
        is_float_field = 'float' in ctype or 'double' in ctype
        value = rewrite(st.e.args[1], True)
        if n in _FLT_STORE and not is_float_field:
            if size != 4:
                return None
            value = Call(Name('AS_U32'), [value])
        elif n in _INT_STORE and is_float_field:
            return None
        done[0] += 1
        return ExprStmt(Call(Name('F2_SET'), [Member(obj, name, True), value]))

    def do_stmt(st):
        s2 = store(st)
        if s2 is not None:
            return s2
        t = type(st)
        if t is Assign:
            return Assign(st.lhs, st.op, rewrite(st.rhs))
        if t is ExprStmt:
            return ExprStmt(rewrite(st.e, False))
        return st

    def visit(lst):
        for k, it in enumerate(lst):
            kind = it[0]
            if kind == 'stmt':
                new = do_stmt(it[1])
                if new is not it[1]:
                    lst[k] = ('stmt', new) + tuple(it[2:])
            elif kind in ('if', 'dowhile', 'while'):
                lst[k] = (kind, rewrite(it[1]), it[2]) + tuple(it[3:])
                visit(it[2])
            elif kind == 'ifelse':
                lst[k] = (kind, rewrite(it[1]), it[2], it[3]) + tuple(it[4:])
                visit(it[2])
                visit(it[3])
            elif kind == 'loop':
                visit(it[2])
    visit(items)
    return struct if done_self[0] else None
