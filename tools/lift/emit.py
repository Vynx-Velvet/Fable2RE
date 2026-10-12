"""Turns an analysed function (lift.build + lift.analyse) into a list of items, then prints it.

Items (tuples):
  ('label', name)
  ('asm', text)                     the PowerPC instruction a group of statements came from
  ('stmt', stmt, S)                 a localized statement (cparse tree, registers as locals)
  ('flush', bits, names)            write these locals to the context (before a call / at a return);
                                    names: register -> variable holding it there
  ('reload', bits, names)           read these locals back from the context (after a call)
  ('ret',)                          return
  ('if', cond, [items], S)          conditional block
  ('ifelse' / 'dowhile' / 'while' / 'loop' / 'break' / 'continue')   after structuring
The readable passes (typing, condition folding, inlining, structuring) work on this list.

General-purpose registers are split into webs (webs.py): r11 holding unrelated values in different
parts of a function becomes r11, r11_2, ... each with its own type.
"""
from cparse import (Assign, ExprStmt, Decl, Goto, Return, If, Block, Switch, Member, Name, Call, Index, stmt_str,
                    expr_str, map_expr)
import regs
from regs import names
import os

import typer

GPR_NAMES = [f'r{i}' for i in range(32)]


def base(name):
    """'r11_2' -> 'r11' (variable of a split register)."""
    if '_' in name:
        b = name.split('_')[0]
        if b in regs.LOCAL_REGS:
            return b
    return name


class Webs:
    """Variable names per definition, from webs.analyse."""

    def __init__(self, res):
        self.res = res
        order = {}
        for k, (r, kind, i) in enumerate(res.defs):
            w = res.web[k]
            order.setdefault((r, w), (i, k))
            if (i, k) < order[(r, w)]:
                order[(r, w)] = (i, k)
        per_reg = {}
        for (r, w), pos in order.items():
            per_reg.setdefault(r, []).append((pos, w))
        self.name_of_web = {}
        for r, lst in per_reg.items():
            lst.sort()
            for n, (pos, w) in enumerate(lst):
                self.name_of_web[w] = f'r{r}' if n == 0 else f'r{r}_{n + 1}'
        self.wide_vars = set()
        for k, wd in enumerate(res.wide):
            if wd:
                self.wide_vars.add(self.name_of_web[res.web[k]])
        self.ext_vars = {}

    def set_kinds(self, kinds):
        """kinds: def id -> 'z' / 's' / None (extkind.py); a variable gets a kind when all its
        definitions agree."""
        per = {}
        for k, kind in kinds.items():
            v = self.name_of_web[self.res.web[k]]
            per.setdefault(v, set()).add(kind)
        self.ext_vars = {v: ks.pop() for v, ks in per.items() if len(ks) == 1 and None not in ks}

    def var_of_def(self, k):
        return self.name_of_web[self.res.web[k]]

    def read_var(self, i, r):
        bs = self.res.rd_in[i].get(r, 0) if i >= 0 else 0
        if not bs:
            return f'r{r}'
        k = (bs & -bs).bit_length() - 1
        return self.var_of_def(k)

    def out_var(self, i, r):
        bs = self.res.rd_out[i].get(r, 0)
        if not bs:
            return f'r{r}'
        k = (bs & -bs).bit_length() - 1
        return self.var_of_def(k)

    def write_var(self, i, r):
        k = self.res.def_at[i].get(r)
        return self.var_of_def(k) if k is not None else self.read_var(i, r)

    def call_var(self, i, r):
        k = self.res.call_def_at[i].get(r)
        return self.var_of_def(k) if k is not None else self.read_var(i, r)

    def entry_var(self, r):
        return self.var_of_def(self.res.entry_def[r])


def _gpr_index(name):
    return int(name[1:]) if name in typer.GPR else None


def rename_stmt(st, i, w):
    """Registers in a statement of S_i -> their web variables (reads at i, the target written at i)."""
    def rd(e):
        def f(x):
            if type(x) is Name and x.id in typer.GPR:
                return Name(w.read_var(i, int(x.id[1:])))
            return None
        return map_expr(e, f)

    def target(lhs, conditional):
        # innermost object of the target chain is the register written; index expressions are reads
        if type(lhs) is Member:
            return Member(target(lhs.obj, conditional), lhs.field, lhs.arrow)
        if type(lhs) is Index:
            return Index(target(lhs.obj, conditional), rd(lhs.index))
        if type(lhs) is Name and lhs.id in typer.GPR:
            r = int(lhs.id[1:])
            return Name(w.read_var(i, r) if conditional else w.write_var(i, r))
        return rd(lhs)

    def stmt(s, conditional=False):
        t = type(s)
        if t is Assign:
            return Assign(target(s.lhs, conditional), s.op, rd(s.rhs))
        if t is ExprStmt:
            return ExprStmt(rd(s.e))
        if t is If:
            return If(rd(s.cond), stmt(s.body, True))
        if t is Block:
            return Block([stmt(x, conditional) for x in s.stmts])
        if t is Switch:
            return Switch(rd(s.e), s.cases, s.default)
        if t is Decl:
            return Decl(s.type, s.name, rd(s.init) if s.init is not None else None)
        return s
    return stmt(st)


def items_of(fn, stmts, outputs, localize_stmt, is_call_lr, w=None, my_ret=0):
    """my_ret: the register this function returns natively (0: none). It is not written to the context at a
    return; a ('flush', bit, names, 'ret') item before the 'ret' names the local that holds it."""
    index = {id(s): i for i, s in enumerate(stmts)}

    def ret_items(dirty, i, where):
        out_ = [('flush', dirty & outputs & ~my_ret, names_at(dirty & outputs & ~my_ret, i, where))]
        if my_ret & dirty:
            out_.append(('flush', my_ret, names_at(my_ret, i, where), 'ret'))
        out_.append(('ret',))
        return out_

    def names_at(bits, i, where):
        if w is None:
            return {}
        out = {}
        for r in names(bits):
            if r in typer.GPR:
                n = int(r[1:])
                out[r] = (w.read_var(i, n) if where == 'pre' else w.out_var(i, n) if where == 'post'
                          else w.call_var(i, n))
        return out

    out = []
    for s in stmts:
        i = index[id(s)]
        for l in s.labels:
            out.append(('label', l))
        if s.removed:
            if type(s.stmt) is Return or (s.returns and type(s.stmt) is not If):
                out.extend(ret_items(s.dirty_in, i, 'pre'))
            continue
        if is_call_lr(s):
            continue
        if s.insn is not None and next((x for x in stmts if x.insn is s.insn and not x.removed and not is_call_lr(x)),
                                       None) is s:
            out.append(('asm', s.insn.asm))
        st = localize_stmt(s.stmt)
        if w is not None:
            st = rename_stmt(st, i, w)
        a = s.acc
        t = type(st)
        if a.sync:
            out.append(('flush', s.flush, names_at(s.flush, i, 'pre')))
            rl = ('reload', s.reload, names_at(s.reload, i, 'call'))
            if t is If and type(st.body) not in (Goto, Return):
                out.append(('if', st.cond, [('stmt', st.body, s), rl], s))
            else:
                if s.native is not None:  # arguments taken from locals (read like a flush by the passes)
                    out.append(('flush', s.nflush, names_at(s.nflush, i, 'pre'), 'args'))
                out.append(('stmt', st, s))
                if s.nreload:
                    out.append(('reload', s.nreload, names_at(s.nreload, i, 'call'), 'result'))
                out.append(rl)
            if s.returns and t is not Return:
                dirty = s.dirty_after if s.native is not None else ((s.dirty_in & ~s.flush) | a.def_)
                out.extend(ret_items(dirty, i, 'post'))
        elif t is Return:
            out.extend(ret_items(s.dirty_in, i, 'pre'))
        elif s.returns and t is not If:
            out.append(('stmt', st, s))
            out.extend(ret_items(s.dirty_in | a.def_, i, 'post'))
        elif t is If and type(st.body) is Return:
            out.append(('if', st.cond, ret_items(s.dirty_in, i, 'pre'), s))
        else:
            out.append(('stmt', st, s))
    return out


def _res(r):
    if '.' in r:
        reg, f = r.split('.')
        return reg, '.' + f
    return r, ''


def walk_items(items):
    for it in items:
        yield it
        if it[0] in ('if', 'dowhile', 'while', 'loop'):
            yield from walk_items(it[2])
        elif it[0] == 'ifelse':
            yield from walk_items(it[2])
            yield from walk_items(it[3])


def stmts_of(items):
    return [it[1] for it in walk_items(items) if it[0] == 'stmt']


def conds_of(items):
    """Conditions of structured items (if / ifelse / while / do-while), which hold inlined expressions too."""
    return [it[1] for it in walk_items(items) if it[0] in ('if', 'ifelse', 'dowhile', 'while')]


class Printer:
    def __init__(self, typing=None, restore=(), lr_into_r12=False, ret=None):
        self.typing = typing
        self.lr_into_r12 = lr_into_r12
        self.ret = ret          # (register, C type) this function returns natively, or None
        self._args = (0, {})    # locals passed to the next native call
        self._retvar = None     # local holding the value of the next return
        # callee-saved registers this function writes to the context (inputs of a callee): restored on return
        self.restore = list(restore)

    def stmt(self, st, indent):
        if self.typing is not None:
            st = typer.rewrite_stmt(st, self.typing)
        text = stmt_str(st, indent)
        # name the callee of 'sub_XXXXXXXX(ctx, base);'
        if type(st) is ExprStmt and type(st.e) is Call and type(st.e.func) is Name and st.e.func.id.startswith('sub_'):
            import lift
            n = lift.catalog_names().get(int(st.e.func.id[4:], 16))
            if n and not n[0].startswith('sub_'):
                text += f'  // {n[0]}'
        return text

    def flush(self, bits, vars_, indent):
        out = []
        for r in names(bits):
            reg, f = _res(r)
            var = vars_.get(reg, reg) if vars_ else reg
            if f or self.typing is None:
                out.append(f'{indent}ctx.{reg}{f} = {var}{f};')
            else:
                out.append(indent + typer.ctx_write(reg, self.typing, var))
        return out

    def reload(self, bits, vars_, indent):
        out = []
        for r in names(bits):
            reg, f = _res(r)
            var = vars_.get(reg, reg) if vars_ else reg
            if f or self.typing is None:
                out.append(f'{indent}{var}{f} = ctx.{reg}{f};')
            else:
                out.append(f'{indent}{var} = {typer.ctx_read(reg, self.typing, var)};')
        return out

    def local_value(self, reg, var):
        """Expression for the value of a local register variable (as an argument / return value)."""
        if reg in typer.FPR and self.typing is not None and var in self.typing.not_double:
            return f'{var}.f64'
        return var

    def native_call(self, s):
        import lift
        callee, npg, ret = s.native
        bits, vars_ = self._args
        self._args = (0, {})
        args = ['ctx', 'base']
        for reg in lift.param_order(npg):
            if bits & regs.bit(reg):
                args.append(self.local_value(reg, vars_.get(reg, reg) if vars_ else reg))
            elif reg in typer.FPR:
                args.append(f'ctx.{reg}.f64')
            else:
                args.append(f'ctx.{reg}.' + ('u64' if lift.param_type(callee, reg) == 'uint64_t' else 'u32'))
        import names as names_
        native = names_.native_name(callee)
        text = f'{native}({", ".join(args)})'
        n = lift.catalog_names().get(int(callee[4:], 16)) if callee.startswith('sub_') else None
        note = f'  // {n[0]}' if n and not n[0].startswith('sub_') and native.startswith('n_sub_') else ''
        return text, note

    def items(self, items, indent='\t'):
        out = []
        skip = False
        for pos, it in enumerate(items):
            if skip:
                skip = False
                continue
            k = it[0]
            if k == 'flush' and len(it) > 3:
                if it[3] == 'args':
                    self._args = (it[1], it[2])
                else:  # 'ret'
                    reg = names(it[1])[0]
                    self._retvar = self.local_value(reg, it[2].get(reg, reg) if it[2] else reg)
                continue
            if k == 'stmt' and len(it) > 2 and getattr(it[2], 'native', None) is not None and \
                    type(it[1]) is ExprStmt:
                s = it[2]
                text, note = self.native_call(s)
                nxt = items[pos + 1] if pos + 1 < len(items) else None
                reg = names(s.native[2])[0] if s.native[2] else None
                if nxt is not None and nxt[0] == 'reload' and len(nxt) > 3:
                    var = nxt[2].get(reg, reg) if nxt[2] else reg
                    out.append(f'{indent}{self.local_value(reg, var)} = {text};{note}')
                    skip = True
                elif s.nret_ctx:
                    out.append(f'{indent}ctx.{reg}.{"f64" if reg in typer.FPR else "u64"} = {text};{note}')
                else:
                    out.append(f'{indent}{text};{note}')
                continue
            if k == 'label':
                out.append(f'{it[1]}:')
            elif k == 'asm':
                out.append(f'{indent}// {it[1]}')
            elif k == 'stmt':
                out.append(self.stmt(it[1], indent))
            elif k == 'flush':
                out.extend(self.flush(it[1], it[2] if len(it) > 2 else None, indent))
            elif k == 'reload':
                out.extend(self.reload(it[1], it[2] if len(it) > 2 else None, indent))
            elif k == 'ret':
                for reg in self.restore:
                    out.append(f'{indent}ctx.{reg} = f2_entry_{reg};')
                if self.lr_into_r12:
                    out.append(f'{indent}ctx.r12.u64 = uint32_t(ctx.lr);  // (the stripped epilogue left the link register in r12)')
                if self.ret is None:
                    out.append(f'{indent}return;')
                else:
                    reg, ty = self.ret
                    value = self._retvar or (f'ctx.{reg}.f64' if reg in typer.FPR else
                                             f'ctx.{reg}.' + ('u64' if ty == 'uint64_t' else 'u32'))
                    self._retvar = None
                    out.append(f'{indent}return {value};')
            elif k == 'if':
                cond = self.cond(it[1])
                body = self.items(it[2], indent + '\t')
                if len(body) == 1 and not body[0].strip().startswith(('//', 'if', 'for', 'while', 'do')) and \
                        not body[0].endswith(':'):
                    out.append(f'{indent}if ({cond}) {body[0].strip()}')
                else:
                    out.append(f'{indent}if ({cond}) {{')
                    out.extend(body)
                    out.append(f'{indent}}}')
            elif k == 'ifelse':
                out.append(f'{indent}if ({self.cond(it[1])}) {{')
                out.extend(self.items(it[2], indent + '\t'))
                out.append(f'{indent}}} else {{')
                out.extend(self.items(it[3], indent + '\t'))
                out.append(f'{indent}}}')
            elif k == 'dowhile':
                out.append(f'{indent}do {{')
                out.extend(self.items(it[2], indent + '\t'))
                out.append(f'{indent}}} while ({self.cond(it[1])});')
            elif k == 'while':
                out.append(f'{indent}while ({self.cond(it[1])}) {{')
                out.extend(self.items(it[2], indent + '\t'))
                out.append(f'{indent}}}')
            elif k == 'loop':
                out.append(f'{indent}for (;;) {{')
                out.extend(self.items(it[2], indent + '\t'))
                out.append(f'{indent}}}')
            elif k in ('break', 'continue'):
                out.append(f'{indent}{k};')
        return out

    def cond(self, c):
        if self.typing is not None:
            c = typer.rewrite_expr(c, self.typing)
        return expr_str(c)

    def declarations(self, used_vars, entry_live, entry_vars, indent='\t', params=None):
        """used_vars: variables still mentioned; entry_vars: register -> variable holding its entry value.
        params: register -> (name, C type) of the function's native parameters; a parameter whose entry
        variable has the same name and type needs no declaration."""
        out = []
        params = params or {}
        order = {r: i for i, r in enumerate(regs.NAMES)}

        def key(v):
            b = base(v)
            return (order.get(b, order.get(b + '.lt', order.get('xer.so', 0))), v)
        for var in sorted(used_vars, key=key):
            reg = base(var)
            rb = regs.reg_bits(reg)
            live = entry_live & rb if entry_vars.get(reg, reg) == var else 0
            d = typer.decl(var, self.typing) if self.typing is not None else None
            if reg in params and entry_vars.get(reg, reg) == var:
                pname, ptype = params[reg]
                if d is not None:
                    if pname != var:
                        out.append(f'{indent}{d.split("{")[0]} = {pname};')
                else:
                    view = 'f64' if reg in typer.FPR else 'u64'
                    out.append(f'{indent}{regs.ctype(reg)} {var}{{}};')
                    out.append(f'{indent}{var}.{view} = {pname};')
                continue
            if d is not None:
                if live:
                    out.append(f'{indent}{d.split("{")[0]} = {typer.ctx_read(reg, self.typing, var)};')
                else:
                    out.append(f'{indent}{d};')
                continue
            if live == rb:
                out.append(f'{indent}{regs.ctype(reg)} {var} = ctx.{reg};')
            else:
                out.append(f'{indent}{regs.ctype(reg)} {var}{{}};')
                out.extend(self.reload(live, {reg: var}, indent))
        return out


def _names_used(items):
    """Local variables (registers / web variables) still mentioned by the items."""
    from cparse import walk
    from passes import _stmt_exprs
    out = set()
    for it in walk_items(items):
        k = it[0]
        exprs = []
        if k == 'stmt':
            exprs = _stmt_exprs(it[1])
        elif k in ('if', 'ifelse', 'dowhile', 'while'):
            exprs = [it[1]]
        elif k in ('flush', 'reload'):
            vars_ = it[2] if len(it) > 2 else {}
            for r in names(it[1]):
                reg = r.split('.')[0]
                out.add(vars_.get(reg, reg))
            continue
        for e in exprs:
            for x in walk(e):
                if type(x) is Name and base(x.id) in regs.LOCAL_REGS:
                    out.add(x.id)
    return out


def _scratch_used(items):
    from cparse import walk
    from passes import _stmt_exprs
    out = set()
    for it in walk_items(items):
        exprs = _stmt_exprs(it[1]) if it[0] == 'stmt' else [it[1]] if it[0] in ('if', 'ifelse', 'dowhile', 'while') else []
        for e in exprs:
            for x in walk(e):
                if type(x) is Name and x.id in ('temp', 'ea', 'vTemp'):
                    out.add(x.id)
    return out


def _nonvolatile_flushed(items):
    bits = 0
    for it in walk_items(items):
        if it[0] == 'flush' and len(it) <= 3:
            bits |= it[1]
    sp = regs.bit('r1') | regs.bit('r2') | regs.bit('r13')
    out = []
    for r in names(bits & regs.NONVOLATILE & ~sp):
        reg = r.split('.')[0]
        if reg not in out:
            out.append(reg)
    return out


FACTS = None  # a list when lift.py --facts collects class-recovery facts (typefacts.py)
FLOW = None   # with it: flow facts for the whole-program type propagation (typeflow.py)


def print_function(fn, stmts, items, readable, comment=None, w=None):
    entry_live = stmts[0].live_in if stmts else 0
    entry_vars = {f'r{r}': w.entry_var(r) for r in w.res.entry_def} if w is not None else {}
    typing = None
    self_struct = ev = None
    if readable:
        import passes
        import sugar
        import structure
        off = passes.DISABLED  # (debugging: LIFT_NO, see passes.py)
        if 'fold' not in off:
            passes.fold_compares(items, stmts)
        if 'sugar1' not in off:
            sugar.apply(items, first=True)
        if 'inline' not in off:
            passes.inline_temps(items)
        if 'sugar2' not in off:
            sugar.apply(items)
        if 'dead' not in off:
            passes.remove_dead(items)
        if 'sync' not in off:
            passes.drop_redundant_sync(items)  # (values handed to the context that are already there)
            passes.remove_dead(items)
        ev = (w.entry_var(3) if 3 in w.res.entry_def else None) if w is not None else None
        if FACTS is not None:
            import typefacts
            fact = typefacts.collect(fn.name, items, walk_items, ev)
            if fact is not None:
                FACTS.append(fact)
            if FLOW is not None and w is not None:
                flow = typefacts.collect_flow(fn.name, items, walk_items,
                                              {f'r{n}': w.entry_var(n) for n in w.res.entry_def})
                if flow is not None:
                    FLOW.append(flow)
        elif 'fields' not in off:
            import fields  # accesses through `this` -> members of its class
            self_struct = fields.apply(fn.name, items, walk_items, ev)
            if self_struct and 'dead' not in off:
                passes.remove_dead(items)  # (copies of `this` that nothing reads any more)
        passes.merge_asm(items)
        if 'structure' not in off:
            structure.structure(items)
        typing = typer.compute(stmts_of(items) + [ExprStmt(c) for c in conds_of(items)], set())
        if w is not None:
            typing.wide = set(w.wide_vars)
            typing.ext = dict(w.ext_vars)
    used = _names_used(items)
    if self_struct:
        used.add(ev)  # (`self` is made from it)
    if not readable:
        used = set()
        for s in stmts:
            if not s.removed:
                used |= s.acc.regs
    import lift
    unsaved = lift.unsaved_callee_saved(stmts)
    restore = [r for r in _nonvolatile_flushed(items) if not (regs.reg_bits(r) & unsaved)]
    import lift
    my_out = lift.summaries()['outputs'].get(fn.name, 0)
    def _restores_lr(s):
        if s.insn is not None and s.insn.asm.replace(' ', '') == 'lwzr12,-8(r1)':
            return True
        st = s.stmt  # (__restgprlr_N reloads the link register into r12 as well)
        return type(st) is ExprStmt and type(st.e) is Call and type(st.e.func) is Name and             st.e.func.id.startswith('__restgprlr')
    stripped_lr = any(s.removed and _restores_lr(s) for s in stmts)
    sig = lift.native_sig(fn.name) if readable else None
    out = []
    if comment:
        out.append(f'// {comment}')
    params = {}
    ret = None
    if sig is None:
        out.append(f'F2_LIFTED({fn.name}, 0x{fn.addr:08X}) {{')
    else:
        # the function proper, with its arguments and result, then the entry point other code calls
        # (recompiled code, hooks, calls through pointers): context -> arguments -> context
        pbits, rbit = sig
        rreg = names(rbit)[0] if rbit else None
        rtype = lift.ret_type(fn.name, rreg)
        ret = (rreg, rtype) if rreg else None
        plist, set_ctx, from_ctx = [], [], []
        for reg in lift.param_order(pbits):
            ptype = lift.param_type(fn.name, reg)
            var = entry_vars.get(reg, reg)
            d = typer.decl(var, typing) if typing is not None and var in used else None
            same = d is not None and d.split(' ')[0] == ptype
            pname = var if (same or var not in used) else f'{reg}_in'
            params[reg] = (pname, ptype)
            plist.append(f'{ptype} {pname}')
            view = 'f64' if reg in typer.FPR else 'u64'
            set_ctx.append(f'ctx.{reg}.{view} = {pname}')
            from_ctx.append(f'ctx.{reg}.' + ('f64' if reg in typer.FPR else 'u64' if ptype == 'uint64_t' else 'u32'))
        rexpr = '' if ret is None else (f'ctx.{rreg}.f64' if rreg in typer.FPR else
                                        f'ctx.{rreg}.' + ('u64' if rtype == 'uint64_t' else 'u32'))
        import names as names_
        native = names_.native_name(fn.name)
        defname = f'F2_NATIVE({fn.name})' if native == 'n_' + fn.name else f'F2_NAMED({native})'
        out.append(f'{rtype} {defname}(F2_ENV{"".join(", " + x for x in plist)}) {{')
        out.append(f'\tF2_NATIVE_ENTER({fn.name}, 0x{fn.addr:08X}, ({", ".join(set_ctx) or "void()"}), {rexpr});')
    p = Printer(typing, restore, lr_into_r12=bool(stripped_lr and (my_out & regs.bit('r12'))), ret=ret)
    scratch = _scratch_used(items) if readable else None
    for d in fn.decls:
        if scratch is not None and type(d) is Decl and d.name not in scratch:
            continue
        out.append(stmt_str(d))
    for reg in restore:
        out.append(f'\t{regs.ctype(reg)} f2_entry_{reg} = ctx.{reg};  // (restored on return)')
    out.extend(p.declarations(used, entry_live | (regs.bit('r3') if self_struct else 0), entry_vars, params=params))
    if self_struct:
        out.append(f'\tauto* self = F2_OBJ({self_struct}, {ev});')
    out.extend(p.items(items))
    out.append('}')
    if sig is not None and readable and os.environ.get('LIFT_PLAIN', '1') != '0':
        # game-term names, no F2_ plumbing (readable.py)
        import readable as readable_
        wrapper_call = native if native != 'n_' + fn.name else 'n_' + fn.name
        body = readable_.rewrite(out, fn.addr, int(fn.file.split('.')[-2]) if hasattr(fn, 'file') else 0,
                                 struct=self_struct, self_var=ev if self_struct else None,
                                 param_regs=[r for r in lift.param_order(pbits)])
        out = body
        call = f'{wrapper_call}(ctx, base{"".join(", " + x for x in from_ctx)})'
        if ret is not None:
            call = f'ctx.{rreg}.{"f64" if rreg in typer.FPR else "u64"} = {call}'
        out.append(f'CPU_STATE_ENTRY({fn.name}, 0x{fn.addr:08X}) {{ {call}; }}')
        return out
    if sig is not None:
        call = f'{defname}(ctx, base{"".join(", " + x for x in from_ctx)})'
        if ret is not None:
            call = f'ctx.{rreg}.{"f64" if rreg in typer.FPR else "u64"} = {call}'
        out.append(f'F2_LIFTED({fn.name}, 0x{fn.addr:08X}) {{ {call}; }}')
    return out
