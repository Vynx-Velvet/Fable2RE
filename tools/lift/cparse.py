"""Parser for the C++ the ReXGlue recompiler emits (Fable2Recomp/generated/*.cpp).

The recompiled code is a small, regular subset of C++: assignments to register views
(ctx.r3.u64 = ...), macro calls (REX_LOAD_U32(...)), simde intrinsics, `if (...) goto loc_X;`,
labels and jump-table switches. This module turns one function's text into a list of nodes
whose statements are expression trees, so later passes can reason about every register read
and write exactly - the semantics stay the recompiler's own.
"""
import re

# ---------------------------------------------------------------------------------------------
# Expression tree


class Node:
    __slots__ = ()

    def __eq__(self, other):
        return type(self) is type(other) and all(getattr(self, s) == getattr(other, s) for s in self.__slots__)

    def __hash__(self):
        return hash((type(self).__name__,) + tuple(
            tuple(v) if isinstance(v, list) else v for v in (getattr(self, s) for s in self.__slots__)))

    def __repr__(self):
        return f"{type(self).__name__}({', '.join(repr(getattr(self, s)) for s in self.__slots__)})"


class Num(Node):
    __slots__ = ('text',)

    def __init__(self, text):
        self.text = text

    def value(self):
        t = self.text.rstrip('uUlL')
        if t.startswith(('0x', '0X')):
            return int(t, 16)
        if re.fullmatch(r'-?\d+', t):
            return int(t)
        return float(t.rstrip('fF'))


class Name(Node):
    __slots__ = ('id',)

    def __init__(self, id):
        self.id = id


class Member(Node):  # obj.field  (or obj->field when arrow)
    __slots__ = ('obj', 'field', 'arrow')

    def __init__(self, obj, field, arrow=False):
        self.obj, self.field, self.arrow = obj, field, arrow


class Index(Node):
    __slots__ = ('obj', 'index')

    def __init__(self, obj, index):
        self.obj, self.index = obj, index


class Call(Node):  # func(args) - func is an expression; tmpl is the text inside <...> if any
    __slots__ = ('func', 'args', 'tmpl')

    def __init__(self, func, args, tmpl=None):
        self.func, self.args, self.tmpl = func, list(args), tmpl


class Cast(Node):  # (type)x
    __slots__ = ('type', 'x')

    def __init__(self, type, x):
        self.type, self.x = type, x


class Unary(Node):  # prefix op (incl. pre ++/--); postfix ops are 'post++'/'post--'
    __slots__ = ('op', 'x')

    def __init__(self, op, x):
        self.op, self.x = op, x


class Binary(Node):
    __slots__ = ('op', 'a', 'b')

    def __init__(self, op, a, b):
        self.op, self.a, self.b = op, a, b


class Ternary(Node):
    __slots__ = ('c', 'a', 'b')

    def __init__(self, c, a, b):
        self.c, self.a, self.b = c, a, b


class InitList(Node):  # {a, b} / {}
    __slots__ = ('items',)

    def __init__(self, items):
        self.items = list(items)


# ---------------------------------------------------------------------------------------------
# Statements


class Stmt:
    __slots__ = ()

    def __repr__(self):
        return f"{type(self).__name__}({', '.join(repr(getattr(self, s)) for s in self.__slots__)})"


class Assign(Stmt):  # lhs op rhs; op in = += -= |= &= ^= <<= >>= *= /=
    __slots__ = ('lhs', 'op', 'rhs')

    def __init__(self, lhs, op, rhs):
        self.lhs, self.op, self.rhs = lhs, op, rhs


class ExprStmt(Stmt):
    __slots__ = ('e',)

    def __init__(self, e):
        self.e = e


class Decl(Stmt):  # type name = init;  /  type name{};
    __slots__ = ('type', 'name', 'init')

    def __init__(self, type, name, init):
        self.type, self.name, self.init = type, name, init


class Goto(Stmt):
    __slots__ = ('label',)

    def __init__(self, label):
        self.label = label


class Return(Stmt):
    __slots__ = ()


class If(Stmt):  # if (cond) body   (body: a single Stmt)
    __slots__ = ('cond', 'body')

    def __init__(self, cond, body):
        self.cond, self.body = cond, body


class Block(Stmt):  # { stmts }
    __slots__ = ('stmts',)

    def __init__(self, stmts):
        self.stmts = list(stmts)


class Switch(Stmt):  # switch (e) { case v: goto L; ... default: <stmt> }
    __slots__ = ('e', 'cases', 'default')

    def __init__(self, e, cases, default):
        self.e, self.cases, self.default = e, list(cases), default


class Raw(Stmt):  # unparsed text (kept verbatim)
    __slots__ = ('text',)

    def __init__(self, text):
        self.text = text


# ---------------------------------------------------------------------------------------------
# Tokenizer

_OPS = ['<<=', '>>=', '->', '++', '--', '<<', '>>', '<=', '>=', '==', '!=', '&&', '||', '+=', '-=', '*=',
        '/=', '&=', '|=', '^=', '%=', '::', '(', ')', '[', ']', '{', '}', '.', ',', ';', ':', '?', '+', '-',
        '*', '/', '%', '&', '|', '^', '~', '!', '<', '>', '=']
_TOKEN = re.compile(r'\s*(?:(?P<num>0[xX][0-9A-Fa-f]+[uUlL]*|\d+\.\d*(?:[eE][+-]?\d+)?[fF]?|\d+[eE][+-]?\d+[fF]?|\d+[uUlL]*)'
                    r'|(?P<id>[A-Za-z_][A-Za-z0-9_]*)|(?P<op>' + '|'.join(re.escape(o) for o in _OPS) + r'))')


class ParseError(Exception):
    pass


def tokenize(text):
    out, pos, n = [], 0, len(text)
    while pos < n:
        if text[pos].isspace():
            pos += 1
            continue
        m = _TOKEN.match(text, pos)
        if not m or m.end() == pos:
            raise ParseError(f'bad token at {text[pos:pos + 20]!r}')
        if m.group('num') is not None:
            out.append(('num', m.group('num')))
        elif m.group('id') is not None:
            out.append(('id', m.group('id')))
        else:
            out.append(('op', m.group('op')))
        pos = m.end()
    return out


_TEMPLATE_FUNCS = {'compare', 'static_cast', 'reinterpret_cast', 'const_cast', 'bit_cast', 'numeric_limits'}
_TYPE_WORDS = {'void', 'char', 'short', 'int', 'long', 'unsigned', 'signed', 'float', 'double', 'bool', 'const',
               'volatile', 'auto'}


def _is_type_name(name):
    return name in _TYPE_WORDS or name.endswith('_t') or name.startswith('simde__') or name in (
        'PPCRegister', 'PPCVRegister', 'PPCContext', 'u8', 'u16', 'u32', 'u64', 'be')


class _P:
    def __init__(self, toks):
        self.t, self.i = toks, 0

    def peek(self, k=0):
        j = self.i + k
        return self.t[j] if j < len(self.t) else (None, None)

    def take(self):
        tok = self.peek()
        self.i += 1
        return tok

    def accept(self, val):
        if self.peek()[1] == val:
            self.i += 1
            return True
        return False

    def expect(self, val):
        tok = self.take()
        if tok[1] != val:
            raise ParseError(f'expected {val!r}, got {tok!r}')

    def at_end(self):
        return self.i >= len(self.t)

    # type text up to the matching '>' of a template argument list
    def template_args(self):
        depth, parts = 1, []
        while True:
            kind, v = self.take()
            if kind is None:
                raise ParseError('unterminated template')
            if v == '<':
                depth += 1
            elif v == '>':
                depth -= 1
                if depth == 0:
                    return ' '.join(parts).replace(' ::', '::').replace(':: ', '::').replace(' *', '*')
            elif v == '>>':
                depth -= 2
                if depth <= 0:
                    raise ParseError('nested >> in template')
            parts.append(v)

    def qualified_id(self, first):
        name = first
        while self.peek()[1] == '::' and self.peek(1)[0] == 'id':
            self.i += 1
            name += '::' + self.take()[1]
        return name

    # --- expressions
    def expr(self):
        e = self.assignment_free()
        while self.peek()[1] == ',' and False:
            pass
        return e

    def assignment_free(self):
        return self.ternary()

    def ternary(self):
        c = self.binary(0)
        if self.accept('?'):
            a = self.ternary()
            self.expect(':')
            b = self.ternary()
            return Ternary(c, a, b)
        return c

    _BIN = [['||'], ['&&'], ['|'], ['^'], ['&'], ['==', '!='], ['<', '>', '<=', '>='], ['<<', '>>'], ['+', '-'],
            ['*', '/', '%']]

    def binary(self, level):
        if level == len(self._BIN):
            return self.unary()
        e = self.binary(level + 1)
        while True:
            kind, v = self.peek()
            if kind == 'op' and v in self._BIN[level]:
                self.i += 1
                e = Binary(v, e, self.binary(level + 1))
            else:
                return e

    def unary(self):
        kind, v = self.peek()
        if kind == 'op' and v in ('!', '~', '-', '+', '*', '&', '++', '--'):
            self.i += 1
            return Unary(v, self.unary())
        if kind == 'op' and v == '(':
            # C-style cast: '(' type-name ['*'...] ')'
            j, parts = self.i + 1, []
            while j < len(self.t) and (self.t[j][0] == 'id' or self.t[j][1] in ('*', '::')):
                parts.append(self.t[j][1])
                j += 1
            if parts and j < len(self.t) and self.t[j][1] == ')' and _is_type_name(parts[0]) and \
                    j + 1 < len(self.t) and (self.t[j + 1][0] in ('id', 'num') or self.t[j + 1][1] in ('(', '-', '~', '!', '*', '&')):
                self.i = j + 1
                typ = ''.join(p if p in ('*', '::') else (' ' + p) for p in parts).strip()
                return Cast(typ, self.unary())
        return self.postfix(self.primary())

    def postfix(self, e):
        while True:
            kind, v = self.peek()
            if v == '(':
                self.i += 1
                e = Call(e, self.args(')'))
            elif v == '[':
                self.i += 1
                idx = self.ternary()
                self.expect(']')
                e = Index(e, idx)
            elif v in ('.', '->'):
                self.i += 1
                kind2, f = self.take()
                if kind2 != 'id':
                    raise ParseError('member name expected')
                e = Member(e, f, v == '->')
                if f in _TEMPLATE_FUNCS and self.peek()[1] == '<':  # obj.compare<T>(...)
                    self.i += 1
                    tmpl = self.template_args()
                    self.expect('(')
                    e = Call(e, self.args(')'), tmpl)
            elif v in ('++', '--'):
                self.i += 1
                e = Unary('post' + v, e)
            else:
                return e

    def args(self, close):
        out = []
        if self.accept(close):
            return out
        while True:
            out.append(self.ternary())
            if self.accept(close):
                return out
            self.expect(',')

    def primary(self):
        kind, v = self.take()
        if kind == 'num':
            return Num(v)
        if kind == 'id':
            name = self.qualified_id(v)
            base = name.split('::')[-1]
            if self.peek()[1] == '<' and base in _TEMPLATE_FUNCS:
                self.i += 1
                tmpl = self.template_args()
                if self.peek()[1] == '::':  # std::numeric_limits<T>::max()
                    self.i += 1
                    name2 = self.qualified_id(self.take()[1])
                    return Name(f'{name}<{tmpl}>::{name2}')
                self.expect('(')
                return Call(Name(name), self.args(')'), tmpl)
            return Name(name)
        if v == '(':
            e = self.ternary()
            self.expect(')')
            return e
        if v == '{':
            return InitList(self.args('}'))
        raise ParseError(f'unexpected {v!r}')


_ASSIGN_OPS = ('=', '+=', '-=', '|=', '&=', '^=', '<<=', '>>=', '*=', '/=', '%=')


def parse_expr(text):
    p = _P(tokenize(text))
    e = p.ternary()
    if not p.at_end():
        raise ParseError(f'trailing tokens in {text!r}')
    return e


def parse_simple_stmt(text):
    """One statement without the trailing ';' handled by the caller (text includes it)."""
    text = text.strip()
    m = re.fullmatch(r'goto (loc_[0-9A-Fa-f]+);', text)
    if m:
        return Goto(m.group(1))
    if text == 'return;':
        return Return()
    m = re.match(r'if \((.*)\) (goto loc_[0-9A-Fa-f]+;|return;|.*;)$', text)
    if m:
        # split at the ')' that closes 'if ('
        depth = 0
        for j in range(3, len(text)):
            if text[j] == '(':
                depth += 1
            elif text[j] == ')':
                depth -= 1
                if depth == 0:
                    cond, body = text[4:j], text[j + 1:].strip()
                    return If(parse_expr(cond), parse_simple_stmt(body))
        raise ParseError('bad if')
    if not text.endswith(';'):
        raise ParseError(f'no ; in {text!r}')
    body = text[:-1]
    toks = tokenize(body)
    p = _P(toks)
    # declaration: Type name{} / Type name = expr / Type name{expr}
    if toks and toks[0][0] == 'id' and _is_type_name(toks[0][1]) and len(toks) >= 2:
        j = 0
        typ = []
        while j < len(toks) and (toks[j][0] == 'id' or toks[j][1] in ('*', '::')) and \
                not (toks[j][0] == 'id' and j + 1 < len(toks) and toks[j + 1][1] in ('=', '{', '[', ';') and typ):
            typ.append(toks[j][1])
            j += 1
        if typ and j < len(toks) and toks[j][0] == 'id':
            name = toks[j][1]
            p.i = j + 1
            init = None
            if p.accept('='):
                init = p.ternary()
            elif p.peek()[1] == '{':
                p.i += 1
                init = InitList(p.args('}'))
            if p.at_end():
                return Decl(''.join(t if t in ('*', '::') else ' ' + t for t in typ).strip(), name, init)
            p.i = 0
    lhs = p.ternary()
    if p.at_end():
        return ExprStmt(lhs)
    kind, v = p.take()
    if v not in _ASSIGN_OPS:
        raise ParseError(f'unexpected {v!r} in {text!r}')
    rhs = p.ternary()
    if not p.at_end():
        raise ParseError(f'trailing tokens in {text!r}')
    return Assign(lhs, v, rhs)


# ---------------------------------------------------------------------------------------------
# Printing (C++ text back from the tree)

_PREC = {'||': 1, '&&': 2, '|': 3, '^': 4, '&': 5, '==': 6, '!=': 6, '<': 7, '>': 7, '<=': 7, '>=': 7, '<<': 8,
         '>>': 8, '+': 9, '-': 9, '*': 10, '/': 10, '%': 10}


_BITWISE = {'&', '|', '^', '<<', '>>'}


def expr_str(e, prec=0):
    t = type(e)
    if t is Num:
        return e.text
    if t is Name:
        return e.id
    if t is Member:
        return expr_str(e.obj, 12) + ('->' if e.arrow else '.') + e.field
    if t is Index:
        return expr_str(e.obj, 12) + '[' + expr_str(e.index) + ']'
    if t is Call:
        f = expr_str(e.func, 12)
        if e.tmpl is not None:
            f += '<' + e.tmpl + '>'
        return f + '(' + ', '.join(expr_str(a) for a in e.args) + ')'
    if t is Cast:
        s = '(' + e.type + ')' + expr_str(e.x, 11)
        return '(' + s + ')' if prec > 11 else s
    if t is Unary:
        if e.op.startswith('post'):
            return expr_str(e.x, 12) + e.op[4:]
        inner = expr_str(e.x, 11)
        if e.op in ('-', '+', '&', '*') and inner.startswith(e.op):
            inner = '(' + inner + ')'  # (-(-x), not --x)
        s = e.op + inner
        return '(' + s + ')' if prec > 11 else s
    if t is Binary:
        p = _PREC[e.op]
        sa, sb = expr_str(e.a, p), expr_str(e.b, p + 1)
        # parenthesise arithmetic inside bitwise/shift operators (and vice versa) for readers
        def mixed(child):
            # arithmetic inside bitwise/shift, or a shift inside &, |, ^ : parenthesise for readers
            return type(child) is Binary and ((child.op not in _BITWISE) or
                                              (e.op in ('&', '|', '^') and child.op in ('<<', '>>')))
        if e.op in _BITWISE and mixed(e.a) and not sa.startswith('('):
            sa = '(' + sa + ')'
        if e.op in _BITWISE and mixed(e.b) and not sb.startswith('('):
            sb = '(' + sb + ')'
        s = sa + ' ' + e.op + ' ' + sb
        return '(' + s + ')' if prec > p else s
    if t is Ternary:
        s = expr_str(e.c, 1) + ' ? ' + expr_str(e.a) + ' : ' + expr_str(e.b)
        return '(' + s + ')' if prec > 0 else s
    if t is InitList:
        return '{' + ', '.join(expr_str(a) for a in e.items) + '}'
    raise TypeError(t)


def stmt_str(s, indent='\t'):
    t = type(s)
    if t is Assign:
        return f'{indent}{expr_str(s.lhs)} {s.op} {expr_str(s.rhs)};'
    if t is ExprStmt:
        return f'{indent}{expr_str(s.e)};'
    if t is Decl:
        if s.init is None:
            return f'{indent}{s.type} {s.name};'
        if isinstance(s.init, InitList):
            return f'{indent}{s.type} {s.name}{expr_str(s.init)};'
        return f'{indent}{s.type} {s.name} = {expr_str(s.init)};'
    if t is Goto:
        return f'{indent}goto {s.label};'
    if t is Return:
        return f'{indent}return;'
    if t is If:
        return f'{indent}if ({expr_str(s.cond)}) {stmt_str(s.body, "").strip()}'
    if t is Block:
        return '\n'.join([indent + '{'] + [stmt_str(x, indent + '\t') for x in s.stmts] + [indent + '}'])
    if t is Raw:
        return indent + s.text
    if t is Switch:
        lines = [f'{indent}switch ({expr_str(s.e)}) {{']
        for v, lab in s.cases:
            lines.append(f'{indent}case {v}:')
            lines.append(f'{indent}\tgoto {lab};')
        if s.default is not None:
            lines.append(f'{indent}default:')
            lines.append(stmt_str(s.default, indent + '\t'))
        lines.append(indent + '}')
        return '\n'.join(lines)
    raise TypeError(t)


def walk(e):
    """All sub-expressions of e (pre-order)."""
    stack = [e]
    while stack:
        x = stack.pop()
        yield x
        t = type(x)
        if t is Member:
            stack.append(x.obj)
        elif t is Index:
            stack.extend((x.obj, x.index))
        elif t is Call:
            stack.append(x.func)
            stack.extend(x.args)
        elif t is Cast or t is Unary:
            stack.append(x.x)
        elif t is Binary:
            stack.extend((x.a, x.b))
        elif t is Ternary:
            stack.extend((x.c, x.a, x.b))
        elif t is InitList:
            stack.extend(x.items)


def map_expr(e, f):
    """Rebuild e bottom-up, replacing each node n by f(n) (f returns None to keep n)."""
    t = type(e)
    if t is Member:
        e2 = Member(map_expr(e.obj, f), e.field, e.arrow)
    elif t is Index:
        e2 = Index(map_expr(e.obj, f), map_expr(e.index, f))
    elif t is Call:
        e2 = Call(map_expr(e.func, f), [map_expr(a, f) for a in e.args], e.tmpl)
    elif t is Cast:
        e2 = Cast(e.type, map_expr(e.x, f))
    elif t is Unary:
        e2 = Unary(e.op, map_expr(e.x, f))
    elif t is Binary:
        e2 = Binary(e.op, map_expr(e.a, f), map_expr(e.b, f))
    elif t is Ternary:
        e2 = Ternary(map_expr(e.c, f), map_expr(e.a, f), map_expr(e.b, f))
    elif t is InitList:
        e2 = InitList([map_expr(a, f) for a in e.items])
    else:
        e2 = e
    r = f(e2)
    return e2 if r is None else r
