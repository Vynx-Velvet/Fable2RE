"""Reads Fable2Recomp/generated/Fable2_recomp.*.cpp into functions of instructions.

A function is a list of items in program order:
  Label('loc_82796C6C')
  Insn(addr, asm, stmts)   - one PowerPC instruction: its disassembly comment and the C++
                             statements the recompiler emitted for it (parsed, see cparse)
plus the declarations at the top (PPCRegister temp{}; uint32_t ea{}; ...).
"""
import re
import os

from cparse import parse_simple_stmt, parse_expr, Block, Switch, Raw, ParseError, Goto

GENERATED = os.path.join(os.path.dirname(__file__), '..', '..', 'Fable2Recomp', 'generated')


class Label:
    __slots__ = ('name',)

    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f'Label({self.name})'


class Insn:
    __slots__ = ('addr', 'asm', 'stmts')

    def __init__(self, addr, asm, stmts):
        self.addr, self.asm, self.stmts = addr, asm, stmts

    @property
    def op(self):
        return self.asm.split(' ', 1)[0]

    def operands(self):
        parts = self.asm.split(' ', 1)
        return [x.strip() for x in parts[1].split(',')] if len(parts) > 1 and parts[1].strip() else []

    def __repr__(self):
        return f'Insn({self.addr:08X} {self.asm!r} {self.stmts!r})'


class Function:
    __slots__ = ('name', 'addr', 'decls', 'items', 'file', 'line', 'error', 'text')

    def __init__(self, name, file, line):
        self.name, self.file, self.line = name, file, line
        self.addr = int(name[4:], 16) if name.startswith('sub_') else named_addresses().get(name, 0)
        self.decls, self.items, self.error, self.text = [], [], None, []

    def insns(self):
        return [x for x in self.items if isinstance(x, Insn)]


_FUNC_START = re.compile(r'^DEFINE_REX_FUNC\(([A-Za-z_][A-Za-z0-9_]*)\) \{$')
_NAMED = None


def named_addresses():
    """Guest addresses of functions the recompiler gave names (xstart, __savegprlr_14, ...), from the
    function table in generated/Fable2_init.cpp."""
    global _NAMED
    if _NAMED is None:
        _NAMED = {}
        p = os.path.join(GENERATED, 'Fable2_init.cpp')
        if os.path.exists(p):
            for line in open(p, encoding='utf-8', errors='replace'):
                m = re.match(r'\s*\{ 0x([0-9A-F]+), ([A-Za-z_][A-Za-z0-9_]*) \},', line)
                if m and not m.group(2).startswith('sub_'):
                    _NAMED[m.group(2)] = int(m.group(1), 16)
    return _NAMED
_LABEL = re.compile(r'^(loc_[0-9A-F]+):$')


def _parse_body(lines, fn):
    """lines: the function's body lines (between the braces)."""
    cur = None  # current Insn
    pending = []  # statements before the first instruction comment
    i = 0
    n = len(lines)
    addr = fn.addr
    while i < n:
        raw = lines[i]
        s = raw.strip()
        i += 1
        if not s.startswith('//') and ' // ' in s:  # trailing comment on a statement
            s = s[:s.index(' // ')].rstrip()
        if not s:
            continue
        m = _LABEL.match(raw)
        if m:
            fn.items.append(Label(m.group(1)))
            cur = None
            continue
        if s.startswith('// '):
            asm = s[3:].strip()
            cur = Insn(addr, asm, [])
            addr += 4
            fn.items.append(cur)
            continue
        # multi-line constructs
        if s.startswith('switch (') and s.endswith('{'):
            e = parse_expr(s[len('switch ('):-3] if s.endswith(') {') else s[8:-1].rstrip(') '))
            cases, default = [], None
            while i < n:
                t = lines[i].strip()
                i += 1
                if t == '}':
                    break
                mc = re.fullmatch(r'case (-?\d+):', t)
                if mc:
                    g = lines[i].strip()
                    i += 1
                    mg = re.fullmatch(r'goto (loc_[0-9A-F]+);', g)
                    if not mg:
                        raise ParseError(f'switch case body {g!r}')
                    cases.append((int(mc.group(1)), mg.group(1)))
                elif t == 'default:':
                    d = lines[i].strip()
                    if ' // ' in d:
                        d = d[:d.index(' // ')].rstrip()
                    default = parse_simple_stmt(d)
                    i += 1
                else:
                    raise ParseError(f'switch line {t!r}')
            st = Switch(e, cases, default)
        elif s == '{':
            body = []
            depth = 1
            while i < n:
                t = lines[i].strip()
                i += 1
                if t == '}':
                    depth -= 1
                    if depth == 0:
                        break
                body.append(parse_simple_stmt(t))
            st = Block(body)
        else:
            st = parse_simple_stmt(s)
        if cur is None:
            if fn.items:  # statements after a label but before the next comment: belong to no insn
                raise ParseError(f'statement outside an instruction: {s!r}')
            pending.append(st)
        else:
            cur.stmts.append(st)
    fn.decls = pending


def read_file(path, keep_text=False, only=None):
    """Yields Function objects of one generated file (fn.error set when parsing failed). only: a set of
    function names - the others are skipped without parsing."""
    with open(path, encoding='utf-8', errors='replace') as f:
        lines = f.read().split('\n')
    i, n = 0, len(lines)
    base = os.path.basename(path)
    while i < n:
        m = _FUNC_START.match(lines[i])
        if not m:
            i += 1
            continue
        if only is not None and m.group(1) not in only:
            j = i + 1
            while j < n and lines[j] != '}':
                j += 1
            i = j + 1
            continue
        fn = Function(m.group(1), base, i + 1)
        j = i + 1
        while j < n and lines[j] != '}':
            j += 1
        body = lines[i + 1:j]
        if keep_text:
            fn.text = lines[i:j + 1]
        try:
            _parse_body(body, fn)
        except ParseError as e:
            fn.error = str(e)
        i = j + 1
        yield fn


def generated_files():
    names = [f for f in os.listdir(GENERATED) if re.fullmatch(r'Fable2_recomp\.\d+\.cpp', f)]
    names.sort(key=lambda f: int(f.split('.')[1]))
    return [os.path.join(GENERATED, f) for f in names]
