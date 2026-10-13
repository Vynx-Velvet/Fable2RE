"""Last step of the lifter: the function's text in game terms (no register names, no F2_ plumbing).

Only renames and re-spells; what the code does is unchanged (the differential tester checks every function).
  * the object a method works on: `CECVillage* village` (host view) and `villageAddr` (its game address)
  * locals named after what they hold: a call's result after the function (EntityHandle_Get -> entity), a
    field's value after the field (self->m_WealthIndex -> wealthIndex), loop counters i / j / k, a string
    constant's address after its text (str_PieceName), a game global after its address (g_83496920)
  * the stack pointer is `stack`; frame set-up and tear-down are PushStackFrame / PopStackFrame
  * condition / carry flags are `compare0..7` / `flags`; a register-indirect call target is `callTarget`
  * parameters with no better name: arg1, arg2 ... (integer), floatArg1 ... (floating point)
  * leftovers: local1, local2 ...
Names from the naming dictionary (research/names/locals.tsv, by function address and variable) win.
"""
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
IMAGE_BASE = 0x82000000
_IMG = None
_LOCALS = None
# function address -> {name in the readable text: register variable it stands for}, for the functions rewritten
# in this process (lift.py saves it to cache/varmap; the naming tools map a model's local names back with it)
VARMAP = {}
REG_VAR = re.compile(r'(?<![.\w>])(r\d{1,2}(?:_\d+)?|f\d{1,2}(?:_\d+)?|v\d{1,3}(?:_\d+)?|cr\d|xer|ctr|temp|ea|vTemp)\b')
ANY_IDENT = re.compile(r'(?<![.>\w])([A-Za-z_]\w*)')
VERBS = ('Get', 'Find', 'Create', 'Load', 'Read', 'Make', 'Alloc', 'Allocate', 'Lookup', 'Compute', 'Calc',
         'Calculate', 'Fetch', 'Resolve', 'Acquire', 'New', 'Build', 'Query', 'Construct')
KEEP_VERBS = ('Is', 'Has', 'Can', 'Should', 'Was', 'Will', 'Did')
CPP_WORDS = {'int', 'char', 'float', 'double', 'bool', 'void', 'new', 'delete', 'this', 'class', 'struct', 'union',
             'return', 'if', 'else', 'for', 'while', 'do', 'switch', 'case', 'default', 'break', 'continue', 'goto',
             'auto', 'const', 'static', 'operator', 'template', 'typename', 'namespace', 'true', 'false', 'register',
             'signed', 'unsigned', 'short', 'long', 'volatile', 'inline', 'friend', 'virtual', 'public', 'private',
             'protected', 'sizeof', 'typedef', 'enum', 'extern', 'mutable', 'explicit', 'export', 'try', 'catch',
             'throw', 'and', 'or', 'not', 'xor', 'ctx', 'base', 'stack', 'flags', 'callTarget', 'scratch', 'value',
             # (C runtime / Windows header macros)
             'stderr', 'stdout', 'stdin', 'errno', 'assert', 'NULL', 'EOF', 'min', 'max', 'near', 'far',
             'interface', 'small', 'hyper', 'offsetof', 'setjmp', 'alloca', 'environ', 'timezone', 'daylight',
             'pascal', 'cdecl', 'IN', 'OUT', 'OPTIONAL', 'CONST', 'VOID', 'TRUE', 'FALSE', 'DELETE', 'ERROR',
             'RGB', 'INFINITE', 'MAX_PATH', 'CALLBACK', 'WINAPI', 'abs', 'exp', 'log', 'pow', 'sqrt', 'floor',
             'ceil', 'round', 'index', 'time', 'clock', 'signal', 'remove', 'rename', 'exit', 'free', 'malloc',
             'memcpy', 'memset', 'strlen', 'printf', 'main'}


def image():
    global _IMG
    if _IMG is None:
        p = os.path.join(ROOT, 'research', 'decomp', 'default_image.bin')
        _IMG = open(p, 'rb').read() if os.path.exists(p) else b''
    return _IMG


def game_string(addr):
    """The text at a game address if it is a plain printable string, else None."""
    img = image()
    o = addr - IMAGE_BASE
    if not 0 <= o < len(img) - 1:
        return None
    raw = img[o:o + 120].split(b'\0')[0]
    if len(raw) < 2 or len(raw) >= 120:
        return None
    try:
        s = raw.decode('ascii')
    except UnicodeDecodeError:
        return None
    return s if all(32 <= ord(c) < 127 for c in s) and sum(c.isalpha() for c in s) >= 2 else None


def ident_from_text(text, prefix):
    words = re.findall(r'[A-Za-z0-9]+', text)[:6]
    if not words:
        return None
    s = prefix + ''.join(w[:1].upper() + w[1:] for w in words)
    return s[:48] if re.fullmatch(r'[A-Za-z_]\w*', s) else None


def lower_camel(s):
    s = re.sub(r'^m_', '', s)
    s = re.sub(r'[^A-Za-z0-9]', '', s)
    if not s:
        return None
    if s.isupper():
        return s.lower()
    return s[:1].lower() + s[1:]


def from_callee(name):
    """Variable name for a value returned by the function `name` (None: nothing better than generic)."""
    if name.startswith('n_sub_') or name.startswith('sub_'):
        return None
    method = name.split('_')[-1] if '_' in name else name
    cls = name.split('_')[0] if '_' in name else ''
    for v in KEEP_VERBS:
        if method.startswith(v) and len(method) > len(v) and method[len(v)].isupper():
            return lower_camel(method)
    for v in VERBS:
        if method.startswith(v) and len(method) > len(v) and method[len(v)].isupper():
            return lower_camel(method[len(v):])
    if method in ('Get', 'Find', 'Create', 'New') and cls:
        return lower_camel(re.sub(r'^C(EC)?(?=[A-Z])', '', cls))
    return None


def object_name(struct):
    """village for CECVillage, breakable for CECBreakable, xmlReader for CXmlReader."""
    s = re.sub(r'^C(EC)?(?=[A-Z])', '', struct)
    s = re.sub(r'^hk(p|a)?(?=[A-Z])', '', s)
    s = re.sub(r'_[0-9A-F]{8}$', '', s)
    n = lower_camel(s)
    return n if n and n not in CPP_WORDS else 'object'


_GLOBALS = None


def global_names():
    """address -> name of the game's global objects that have one (research/decomp/global_names.tsv: the global
    string objects, named after their text by tools/naming/global_strings.py on this machine)."""
    global _GLOBALS
    if _GLOBALS is None:
        _GLOBALS = {}
        p = os.path.join(ROOT, 'research', 'decomp', 'global_names.tsv')
        if os.path.exists(p) and os.environ.get('LIFT_NAMES', '1') != '0':
            with open(p, encoding='utf-8') as f:
                head = f.readline().rstrip('\n').split('\t')
                for line in f:
                    c = dict(zip(head, line.rstrip('\n').split('\t')))
                    if c.get('address') and c.get('name'):
                        _GLOBALS[int(c['address'], 16)] = c['name']
    return _GLOBALS


def locals_dictionary():
    global _LOCALS
    if _LOCALS is None:
        _LOCALS = {}
        p = os.path.join(ROOT, 'research', 'names', 'locals.tsv')
        if os.path.exists(p) and os.environ.get('LIFT_NAMES', '1') != '0':
            with open(p, encoding='utf-8') as f:
                head = f.readline().rstrip('\n').split('\t')
                for line in f:
                    c = dict(zip(head, line.rstrip('\n').split('\t')))
                    if c.get('function') and c.get('variable') and c.get('name'):
                        _LOCALS[(int(c['function'], 16), c['variable'])] = c['name']
    return _LOCALS


def _split_args(text):
    """Top-level comma-separated parts of an argument list."""
    parts, depth, cur = [], 0, ''
    for ch in text:
        if ch in '([{':
            depth += 1
        elif ch in ')]}':
            depth -= 1
        if ch == ',' and depth == 0:
            parts.append(cur)
            cur = ''
        else:
            cur += ch
    parts.append(cur)
    return parts


def _call_args(line, start):
    """(argument text, end index) of the parenthesised list that starts at line[start] == '('."""
    depth = 0
    for i in range(start, len(line)):
        if line[i] == '(':
            depth += 1
        elif line[i] == ')':
            depth -= 1
            if depth == 0:
                return line[start + 1:i], i
    return None, None


def rewrite(lines, fn_addr, file_idx, struct=None, self_var=None, param_regs=()):
    """lines: the printed function (header comment, definition, body, wrapper). Returns new lines.
    struct / self_var: the class of the first argument and the variable holding it (None: not a method)."""
    if not lines:
        return lines
    text = '\n'.join(lines)
    obj = object_name(struct) if struct else None
    names = {}          # old variable -> new name
    taken = set(CPP_WORDS)
    taken |= {m.group(1) for m in re.finditer(r'\b([A-Za-z_]\w*)\(ctx, base', text)}  # (called functions)
    # every other word already in the text (types, macros, fields, functions) and the helpers the rewrite adds
    code = re.sub(r'//[^\n]*', '', text)
    taken |= {w for w in re.findall(r'\b[A-Za-z_]\w*\b', code) if not REG_VAR.fullmatch(w)}
    taken |= {'frame', 'GameObject', 'PushStackFrame', 'PopStackFrame', 'UseLiftedCode', 'LiftedFrame', 'CpuState',
              'BigEndian'}
    if obj and obj in taken:
        obj = obj + 'Object'
    consts = {}         # address -> constant name (string literals, globals)

    def claim(old, want):
        if old in names or not want:
            return
        want = re.sub(r'[^A-Za-z0-9_]', '', want)
        if not want or want[0].isdigit():
            want = 'v' + want
        cand, n = want, 2
        while cand in taken:
            cand = f'{want}{n}'
            n += 1
        taken.add(cand)
        names[old] = cand
    loc = locals_dictionary()
    for (fa, var), nm in loc.items():
        if fa == fn_addr and REG_VAR.fullmatch(var) and not re.search(r'\b' + var + r'_in\b', text):
            claim(var, nm)   # (a parameter kept in a register variable: below)
    # the object the method works on
    if obj and self_var:
        claim(self_var, obj + 'Addr')
        taken.add(obj)
    # fixed roles
    for old, new in (('r1', 'stack'), ('xer', 'flags'), ('ctr', 'callTarget'), ('temp', 'scratch'),
                     ('ea', 'frameAddr'), ('vTemp', 'vectorScratch')):
        names.setdefault(old, new)
        taken.add(new)
    for k in range(8):
        names.setdefault(f'cr{k}', f'compare{k}')
        taken.add(f'compare{k}')
    # copies of the object's address: the same name with a number
    if obj and self_var:
        for m in re.finditer(r'^\t+(r\d+(?:_\d+)?) = (?:\(\w+\))?' + re.escape(self_var) + r';$', text, re.M):
            claim(m.group(1), obj + 'Addr')
    # names from what is assigned
    assign = re.compile(r'^\t+(r\d+(?:_\d+)?|f\d+(?:_\d+)?) = (.+);$', re.M)
    loop_vars = set(re.findall(r'^\t+(r\d+(?:_\d+)?) = \(int32_t\)\1 \+ 1;$', text, re.M))
    counters = iter(['i', 'j', 'k', 'n', 'm'])
    for v in sorted(loop_vars):
        c = next(counters, None)
        if c:
            claim(v, c)
    n_assign = {}
    for m in assign.finditer(text):
        n_assign[m.group(1)] = n_assign.get(m.group(1), 0) + 1
        mk = re.fullmatch(r'(-?\d+|0x[0-9A-F]+)u?', m.group(2))
        if mk:  # every game address assigned as a constant: a string or a global
            addr = int(mk.group(1), 0) & 0xFFFFFFFF
            st_ = game_string(addr) if addr >= IMAGE_BASE else None
            if st_ and ident_from_text(st_, 'str_') and addr not in consts:
                cn, k = ident_from_text(st_, 'str_'), 2
                while cn in consts.values():
                    cn = f'{ident_from_text(st_, "str_")}{k}'
                    k += 1
                consts[addr] = cn
            elif IMAGE_BASE <= addr < 0x84000000:
                consts.setdefault(addr, global_names().get(addr) or f'g_{addr:08X}')
    for m in assign.finditer(text):
        var, rhs = m.group(1), m.group(2)
        if var in names or n_assign.get(var, 0) != 1:
            continue
        mc = re.match(r'([A-Za-z_]\w*)\(ctx, base', rhs)
        if mc:
            claim(var, from_callee(mc.group(1)))
            continue
        mf = re.fullmatch(r'(?:\w+\()?(?:double\()?\w+->(m_\w+)\)?\)?', rhs)
        if mf and mf.group(1) != 'vtable':
            claim(var, lower_camel(mf.group(1)))
            continue
        if re.fullmatch(r'\w+->vtable', rhs):
            claim(var, 'vtable')
            continue
        mk = re.fullmatch(r'(-?\d+|0x[0-9A-F]+)u?', rhs)
        if mk:
            addr = int(mk.group(1), 0) & 0xFFFFFFFF
            s = game_string(addr) if addr >= IMAGE_BASE else None
            if s:
                cname = consts.get(addr) or ident_from_text(s, 'str_')
                if cname:
                    consts[addr] = cname
                    claim(var, lower_camel(cname[4:]) or 'text')

    # parameters
    ints = floats = 0
    renamed_in = {}  # (a parameter the body keeps in a register-typed variable: <reg>_in -> the parameter name)
    for reg in param_regs:
        if reg.startswith('f'):
            floats += 1
            pname = f'floatArg{floats}'
        else:
            ints += 1
            pname = f'arg{ints}'
        if re.search(r'\b' + reg + r'_in\b', text):
            want = loc.get((fn_addr, reg)) or pname   # (a dictionary name for the register names the parameter)
            cand, k = want, 2
            while cand in taken:
                cand = f'{want}{k}'
                k += 1
            renamed_in[f'{reg}_in'] = cand
            taken.add(cand)
            claim(reg, cand + 'Reg')
        else:
            claim(reg, pname)
    # everything else that still looks like a register
    rest = sorted({m.group(1) for m in REG_VAR.finditer(text)} - set(names),
                  key=lambda s: (re.sub(r'\d', '', s), [int(x) for x in re.findall(r'\d+', s)]))
    n = 0
    for v in rest:
        if v.startswith(('r', 'f', 'v')):
            n += 1
            claim(v, f'local{n}')

    # ---- rewrite the text ----
    out = []
    push_left = 0
    for line in lines:
        s = line
        st = s.strip()
        if st == 'REX_FUNC_PROLOGUE();':
            continue
        if st.startswith('//') and not st.startswith('// sub_') and out:
            continue  # (instruction comments: the code itself says it)
        # stack frame set-up / tear-down
        m = re.fullmatch(r'(\t+)ea = -(\d+) \+ r1;', s)
        if m:
            out.append(f'{m.group(1)}stack = PushStackFrame(base, stack, {m.group(2)});')
            push_left = 2   # (the link store and the stack pointer update that belong to it)
            continue
        if push_left and (re.fullmatch(r'\t+STORE32\(ea, r1\);', s) or re.fullmatch(r'\t+r1 = ea;', s)):
            push_left -= 1
            continue
        push_left = 0   # (any other frame change - a dynamic one after alloca - stays as written)
        m = re.fullmatch(r'(\t+)r1 = \((?:int64_t\)\(uint64_t|int32_t)\)r1 \+ (\d+);', s)
        if m:
            out.append(f'{m.group(1)}stack = PopStackFrame(stack, {m.group(2)});')
            continue
        # string / global constants
        def const_sub(mm):
            # (the named constants are int32_t like the negative literals the lifter prints; a hex literal is
            # unsigned in C++, so it keeps that type)
            v = int(mm.group(1), 0) & 0xFFFFFFFF
            if v not in consts:
                return mm.group(0)
            return consts[v] if mm.group(1).startswith('-') else f'uint32_t({consts[v]})'
        if 'F2_NATIVE_ENTER(' not in s:  # (its address stays a number)
            s = re.sub(r'(?<![\w.])(-?\d{9,10}|0x8[0-9A-F]{7})u?(?![\w.])', const_sub, s)
        # registers saved on entry and restored on return
        s = re.sub(r'\bf2_entry_([a-z]+)(\d+)\b', lambda mm: f'saved{mm.group(1).upper()}{mm.group(2)}', s)
        if renamed_in:
            s = re.sub(r'\b(?:' + '|'.join(renamed_in) + r')\b', lambda mm: renamed_in[mm.group(0)], s)
        # F2_SET(member, value) -> member = value
        while 'F2_SET(' in s:
            i = s.index('F2_SET(')
            args, end = _call_args(s, i + 6)
            if args is None:
                break
            parts = _split_args(args)
            if len(parts) != 2:
                break
            s = s[:i] + f'{parts[0].strip()} = {parts[1].strip()}' + s[end + 1:]
        # the object view
        m = re.fullmatch(r'(\t+)auto\* self = F2_OBJ\((\w+), (\w+)\);', s)
        if m and obj:
            s = f'{m.group(1)}{m.group(2)}* {obj} = GameObject<{m.group(2)}>(base, {m.group(3)});'
        s = re.sub(r'\bself->', f'{obj}->' if obj else 'self->', s)
        # an access through another typed variable (typeflow.py): the object at that address
        s = re.sub(r'\bF2_OBJ\((\w+), ', r'GameObject<\1>(base, ', s)
        # definition header and the switch back to the recompiled original
        m = re.fullmatch(r'(\w+) F2_(?:NAMED|NATIVE)\((\w+)\)\(F2_ENV(.*)\) \{', s)
        if m:
            s = f'{m.group(1)} {m.group(2) if not m.group(2).startswith("sub_") else "n_" + m.group(2)}' \
                f'(CpuState& ctx, uint8_t* base{m.group(3)}) {{'
        m = re.fullmatch(r'(\t+)F2_NATIVE_ENTER\((\w+), (0x[0-9A-F]+), \((.*)\), (.*)\);', s)
        if m:
            sets = '; '.join(x.strip() for x in _split_args(m.group(4)) if x.strip() and x.strip() != 'void()')
            ret = m.group(5).strip()
            body = (sets + '; ' if sets else '') + f'{m.group(2)}_original(ctx, base); return{" " + ret if ret else ""};'
            s = f'{m.group(1)}if (!UseLiftedCode({file_idx}, {m.group(3)})) {{ {body} }}'
            s += f'\n{m.group(1)}LiftedFrame frame({m.group(3)});'
        # register-style names -> game names
        s = REG_VAR.sub(lambda mm: names.get(mm.group(1), mm.group(1)), s)
        out.append(s)
    out = _tidy(out)
    shown = set(re.findall(r'\b[A-Za-z_]\w*\b', '\n'.join(out)))
    VARMAP[fn_addr] = {new: old for old, new in names.items()
                       if new in shown and re.fullmatch(r'[rfv]\d{1,3}(?:_\d+)?', old)}
    for old, new in renamed_in.items():   # (the parameter stands for its register, like its Reg copy)
        VARMAP[fn_addr][new] = old[:-3]
    if consts:
        decl = [f'\tconstexpr int32_t {nm} = int32_t(0x{a:08X});' + (f'  // "{game_string(a)}"' if nm.startswith('str_') else '')
                for a, nm in sorted(consts.items()) if any(re.search(r'\b' + nm + r'\b', l) for l in out)]
        for k, l in enumerate(out):
            if l.endswith(') {') and not l.startswith('\t'):
                out[k + 1:k + 1] = decl
                break
    return out


_DECL = re.compile(r'^\t([\w:<>]+(?:\*)?) (\w+)(?:\{\}| = (.+));$')
_ASSIGN = re.compile(r'^\t+(\w+) = (.+?);(?:\s*//.*)?$')
_ANY_WRITE = re.compile(r'(?<![.\w>])(\w+) (?:[-+*/|&^%]|<<|>>)?= (?!=)')


def _tidy(lines):
    """Copy propagation and unused declarations, on the readable text:
    * `a = b;` where both are plain variables of the same declared type, each assigned exactly once in the
      function (or b a parameter never assigned): every a becomes b, the line and a's declaration go
    * a declared variable that is no longer mentioned anywhere: its declaration goes"""
    head = next((i for i, l in enumerate(lines) if l.endswith(') {') and not l.startswith('\t')), None)
    if head is None:
        return lines
    end = max(i for i, l in enumerate(lines) if l == '}')
    params = {}
    m = re.search(r'\(CpuState& ctx, uint8_t\* base(.*)\) \{$', lines[head])
    if m:
        for p in [x.strip() for x in m.group(1).split(',') if x.strip()]:
            t, _, n = p.rpartition(' ')
            params[n] = t
    for _ in range(4):
        body = lines[head + 1:end]
        decls = {}
        for l in body:
            d = _DECL.match(l)
            if d:
                decls[d.group(2)] = (d.group(1), d.group(3))
        assigns = {}
        for l in body:  # every write anywhere in a line (also `if (c) x = y;`, compound assignments)
            if _DECL.match(l):
                continue
            for mm in _ANY_WRITE.finditer(l):
                assigns[mm.group(1)] = assigns.get(mm.group(1), 0) + 1
            for mm in re.finditer(r'(?:\+\+|--)(\w+)|(\w+)(?:\+\+|--)', l):
                v = mm.group(1) or mm.group(2)
                assigns[v] = assigns.get(v, 0) + 2
        types = dict(params)
        types.update({k: v[0] for k, v in decls.items()})
        subst = {}
        for l in body:
            a = _ASSIGN.match(l)
            if not a or l.startswith('\t\t'):
                continue  # (top level only: a copy inside a branch is not valid everywhere)
            dst, src = a.group(1), a.group(2)
            if not re.fullmatch(r'\w+', src) or dst == src or dst in subst or src in subst:
                continue
            if dst in subst.values():  # (a chain: the next round takes it, one substitution is one pass)
                continue
            if dst not in decls or decls[dst][1] is not None or types.get(src) != decls[dst][0]:
                continue
            if assigns.get(dst) != 1 or assigns.get(src, 0) > (0 if src in params else 1):
                continue
            if src in decls and decls[src][1] is not None and assigns.get(src, 0) > 0:
                continue
            subst[dst] = src
        if not subst:
            break
        pat = re.compile(r'(?<![.\w>])(' + '|'.join(map(re.escape, subst)) + r')\b')
        new = []
        for l in lines[head + 1:end]:
            a = _ASSIGN.match(l)
            d = _DECL.match(l)
            if a and a.group(1) in subst and a.group(2) == subst[a.group(1)]:
                continue
            if d and d.group(2) in subst:
                continue
            new.append(pat.sub(lambda mm: subst[mm.group(1)], l))
        lines = lines[:head + 1] + new + lines[end:]
        end = head + 1 + len(new)
    # declarations nothing mentions any more
    body = lines[head + 1:end]
    text = '\n'.join(body)
    keep = []
    for l in body:
        d = _DECL.match(l)
        if d and d.group(3) is None or (d and re.fullmatch(r'ctx\.\w+(\.\w+)?', d.group(3) or '')):
            n = d.group(2)
            if len(re.findall(r'(?<![.\w>])' + re.escape(n) + r'\b', text)) <= 1:
                continue
        keep.append(l)
    return lines[:head + 1] + keep + lines[end:]
