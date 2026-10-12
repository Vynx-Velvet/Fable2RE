"""Lifts recompiled functions (Fable2Recomp/generated) into readable C++ (Fable2Recomp/lifted).

Pass 1 (this file, correct by construction): registers become local variables; the context
(ctx) is only touched at the function boundary and around calls. Before a call every local that
was modified since the last synchronisation is written back to ctx; after it every local still
needed is read back. Statements keep the recompiler's exact semantics.

Usage:
  python tools/lift/lift.py <file-index> [...]       lift generated/Fable2_recomp.<i>.cpp
  python tools/lift/lift.py --func 821B23F8           print one function
"""
import argparse
import re
import os
import sys

from cparse import (Member, Name, Index, Call, Cast, Unary, Binary, Ternary, InitList, Assign, ExprStmt, Decl, Goto,
                    Return, If, Block, Switch, Raw, map_expr, stmt_str, expr_str)
from genfile import read_file, generated_files, Insn, Label
import regs
from regs import stmt_access, Unsupported, reg_of, ALL, names, ctype

OUT_DIR = os.path.join(os.path.dirname(__file__), '..', '..', 'Fable2Recomp', 'lifted')
EXIT = -1
READABLE = True


class LiftError(Exception):
    pass


# ---------------------------------------------------------------------------------------------
# Linear statement list + CFG

class S:
    """One top-level statement of the function."""
    __slots__ = ('stmt', 'insn', 'acc', 'succ', 'live_in', 'live_out', 'dirty_in', 'labels', 'returns', 'flush',
                 'reload', 'removed', 'native', 'nflush', 'nreload', 'nret_ctx', 'dirty_after')

    def __init__(self, stmt, insn):
        self.stmt, self.insn = stmt, insn
        self.acc = stmt_access(stmt)
        self.succ = []
        self.live_in = self.live_out = 0
        self.dirty_in = None
        self.labels = []  # labels placed before this statement
        self.returns = False  # leaves the function (Return / If(...) return)
        self.flush = self.reload = 0
        self.removed = False
        # a call made with native arguments (see analyse): (callee, parameter bits, result bit); the locals
        # passed as arguments; the result register if it goes into a local / into the context
        self.native = None
        self.nflush = self.nreload = 0
        self.nret_ctx = False
        self.dirty_after = 0


def build(fn):
    if fn.error:
        raise LiftError(fn.error)
    for d in fn.decls:
        if not isinstance(d, (Decl, ExprStmt)):
            raise LiftError('unexpected declaration')
        if isinstance(d, Decl) and d.name not in ('temp', 'ea', 'vTemp'):
            raise LiftError(f'declaration {d.name}')
    stmts, label_at, pending_labels = [], {}, []
    for it in fn.items:
        if isinstance(it, Label):
            pending_labels.append(it.name)
            continue
        for st in it.stmts:
            s = S(st, it)
            s.labels, pending_labels = pending_labels, []
            for l in s.labels:
                label_at[l] = len(stmts)
            stmts.append(s)
    if pending_labels:  # label at the very end
        for l in pending_labels:
            label_at[l] = len(stmts)
        end = S(Return(), None)
        end.labels = pending_labels
        stmts.append(end)

    def target(l):
        if l not in label_at:
            raise LiftError(f'goto unknown label {l}')
        return label_at[l]

    n = len(stmts)
    for i, s in enumerate(stmts):
        st = s.stmt
        nxt = i + 1 if i + 1 < n else EXIT
        t = type(st)
        if t is Goto:
            s.succ = [target(st.label)]
        elif t is Return:
            s.succ, s.returns = [EXIT], True
        elif t is If and type(st.body) is Goto:
            s.succ = [nxt, target(st.body.label)]
        elif t is If and type(st.body) is Return:
            s.succ, s.returns = [nxt, EXIT], True
        elif t is Switch:
            s.succ = sorted({target(l) for _, l in st.cases})
            if st.default is not None and type(st.default) is Goto:
                s.succ.append(target(st.default.label))
        elif s.acc.noreturn:
            s.succ = []
        else:
            s.succ = [nxt]
        if nxt == EXIT and s.succ == [EXIT] and t not in (Return,) and not s.returns:
            s.returns = True  # falls off the end
    import frame
    frame.strip(stmts)
    _tag_virtual_calls(fn, stmts)
    return stmts


_LWZ = re.compile(r'^lwz (r\d+),(-?\d+)\((r\d+)\)$')


def _tag_virtual_calls(fn, stmts):
    """Calls through pointers of the form  vt = LOAD32(obj + k); f = LOAD32(vt + OFF); f(...)  are virtual
    calls of vtable slot OFF: their callee becomes 'indirect@OFF' (see vtables.py)."""
    order = [it for it in fn.items]
    pos = {id(it): n for n, it in enumerate(order)}
    for s in stmts:
        if s.acc.callee != 'indirect' or s.insn is None or s.insn.op not in ('bctrl', 'bctr'):
            continue
        n = pos.get(id(s.insn))
        if n is None:
            continue
        reg = None
        off = None
        j = n - 1
        while j >= 0:
            it = order[j]
            if isinstance(it, Label):
                break
            if reg is None:
                if it.op == 'mtctr':
                    reg = it.operands()[0]
            elif off is None:
                m = _LWZ.match(it.asm)
                if m and m.group(1) == reg:
                    off, vreg = int(m.group(2)), m.group(3)
                elif reg in it.operands()[:1]:
                    break  # written some other way
            else:
                m = _LWZ.match(it.asm)
                if m and m.group(1) == vreg:
                    s.acc.callee = f'indirect@{off}'
                    break
                if vreg in it.operands()[:1]:
                    break
            j -= 1



_SUMMARIES = None
_NAMES = None


def catalog_names():
    """address (int) -> (name, lua binding, size) from research/catalog/functions.tsv."""
    global _NAMES
    if _NAMES is None:
        _NAMES = {}
        p = os.path.join(os.path.dirname(__file__), '..', '..', 'research', 'catalog', 'functions.tsv')
        if os.path.exists(p):
            with open(p, encoding='utf-8') as f:
                head = f.readline().rstrip('\n').split('\t')
                ia, iname, isize, ilua = head.index('address'), head.index('name'), head.index('size'), head.index('lua')
                for line in f:
                    r = line.rstrip('\n').split('\t')
                    if len(r) > ilua:
                        _NAMES[int(r[ia], 16)] = (r[iname], r[ilua], r[isize])
    return _NAMES


def summaries():
    global _SUMMARIES
    if _SUMMARIES is None:
        import pickle
        import summarize
        p = os.path.join(os.path.dirname(__file__), 'cache', 'summaries.pkl')
        if os.path.exists(p):  # computed on this machine (python tools/lift/summarize.py)
            with open(p, 'rb') as f:
                _SUMMARIES = pickle.load(f)
        else:  # shipped with the project, valid for the exact default.xex it was computed from
            import bundle
            _SUMMARIES, why = bundle.load()
            if _SUMMARIES is None:
                raise SystemExit(f'lift: {why}.\nRun python tools/lift/summarize.py (about 30 minutes) to compute '
                                 f'the whole-game analysis for your copy.')
        summarize.apply_invariants(_SUMMARIES)
        summarize.IND.update(_SUMMARIES.get('ind', {}))
        if 'rin' in _SUMMARIES and os.environ.get('LIFT_SPLIT', '1') != '0':
            summarize.SPLIT = {'rin': _SUMMARIES['rin'], 'fwd': _SUMMARIES['fwd']}
    return _SUMMARIES


_SIGNATURES = None
_SIGNATURES_LOCK = __import__("threading").Lock()
_GPR_ALL = sum(regs.bit(f'r{i}') for i in range(32))
_FPR_ALL = sum(regs.bit(f'f{i}') for i in range(32))
# Registers that can be native parameters: volatile integer / float registers. Callee-saved ones a function
# reads from its caller (compiler-generated cleanup blocks) keep going through the context, where the caller
# restores them on return (a bridge writing them to the context would leave them changed).
PARAM_OK = (_GPR_ALL | _FPR_ALL) & regs.VOLATILE & ~(regs.bit('r1') | regs.bit('r2') | regs.bit('r13'))


def signatures():
    """Precise signatures (tools/lift/signatures.py); {} when not computed or LIFT_NATIVE=0."""
    global _SIGNATURES
    if _SIGNATURES is None:
        with _SIGNATURES_LOCK:
            if _SIGNATURES is None:
                # (built in a local and published once: threads that ask while it loads wait instead of seeing an
                # empty table - which made native_sig() return None and the relaxed tester skip return values)
                sg = {}
                p = os.path.join(os.path.dirname(__file__), 'cache', 'signatures.pkl')
                if os.environ.get('LIFT_NATIVE', '1') != '0':
                    if os.path.exists(p):
                        import pickle
                        with open(p, 'rb') as f:
                            sg = pickle.load(f)
                    else:  # shipped with the whole-game analysis (bundle.py)
                        sg = summaries().get('signatures', {})
                _SIGNATURES = sg
    return _SIGNATURES


def native_sig(name):
    """(parameter bits, result bit) of a function that has a native entry point n_<name>; None otherwise."""
    sg = signatures()
    if not READABLE or not sg or not name or name.startswith('__') or name not in sg['params']:
        return None
    return sg['params'][name] & PARAM_OK, sg['ret'].get(name, 0)


def native_result(s):
    """The register a call statement defines as a local value: the native result of its callee."""
    if not s.acc.sync or type(s.stmt) is not ExprStmt:
        return 0
    import summarize
    if summarize.is_indirect(s.acc.callee):
        return 0
    sig = native_sig(s.acc.callee)
    return sig[1] if sig else 0


def param_order(bits):
    """Parameter registers in signature order: r0..r31, f0..f31."""
    return [r for r in ([f'r{i}' for i in range(32)] + [f'f{i}' for i in range(32)]) if bits & regs.bit(r)]


def param_type(func, reg):
    sm = summaries()
    if reg.startswith('f'):
        return 'double'
    return 'uint64_t' if sm.get('wide_in', {}).get(func, _GPR_ALL) & regs.bit(reg) else 'uint32_t'


def ret_type(func, reg):
    if not reg:
        return 'void'
    if reg.startswith('f'):
        return 'double'
    return 'uint64_t' if summaries().get('wide_out', {}).get(func, _GPR_ALL) & regs.bit(reg) else 'uint32_t'


_SAVE_INSN = re.compile(r'^(std|stfd|stvx128|stvx) ([rfv])(\d+),')


def unsaved_callee_saved(stmts):
    """Callee-saved registers the function writes without saving them first: compiler-generated cleanup
    blocks (__finally) set their parent's frame registers (r31 = r12 - 208 ...) on purpose and return
    them changed. Those are written back to the context at the return like results."""
    saved = 0
    defs = 0
    for s in stmts:
        defs |= s.acc.def_
        if s.insn is None:
            continue
        m = _SAVE_INSN.match(s.insn.asm)
        if m:
            saved |= regs.reg_bits(f'{m.group(2)}{m.group(3)}') if f'{m.group(2)}{m.group(3)}' in regs.LOCAL_REGS else 0
        if s.insn.asm.startswith('mfcr'):
            saved |= regs.reg_bits('cr2') | regs.reg_bits('cr3') | regs.reg_bits('cr4')
        st = s.stmt
        if type(st) is ExprStmt and type(st.e) is Call and type(st.e.func) is Name:
            m = re.fullmatch(r'__save(gprlr|fpr|vmx)_(\d+)', st.e.func.id)
            if m:
                k = int(m.group(2))
                kind = {'gprlr': 'r', 'fpr': 'f', 'vmx': 'v'}[m.group(1)]
                top = 31 if kind != 'v' or k < 32 else 127
                for i in range(k, top + 1):
                    saved |= regs.bit(f'{kind}{i}')
    sp = regs.bit('r1') | regs.bit('r2') | regs.bit('r13')
    return defs & regs.NONVOLATILE & ~saved & ~sp


def analyse(stmts, fname=None):
    """Liveness (with callee summaries) and, per call, which locals to write to the context before
    it (s.flush) and read back after it (s.reload). See summarize.py for the summaries."""
    import summarize
    sm = summaries()
    inputs, mods, outputs = sm['inputs'], sm['mods'], sm['outputs']
    my_outputs = outputs.get(fname, regs.ABI_OUTPUTS) | summarize.SP | unsaved_callee_saved(stmts)
    # Debugging (pass_bisect.py): LIFT_SYNC=ret returns every volatile register it changed; LIFT_SYNC=calls
    # hands every changed register to each callee and takes every live one back (ignores the summaries).
    sync_dbg = set(filter(None, os.environ.get('LIFT_SYNC', '').split(',')))
    if 'ret' in sync_dbg:
        only = set(filter(None, os.environ.get('LIFT_SYNC_REGS', '').split(',')))  # (sync_bisect.py)
        extra = regs.VOLATILE
        if only:
            extra = 0
            for r in only:
                extra |= regs.reg_bits(r)
        my_outputs |= extra & regs.VOLATILE
    compact = [(s.acc.use, s.acc.def_ | native_result(s), s.acc.sync, s.acc.callee, tuple(s.succ)) for s in stmts]
    # Native signature: the parameters arrive as locals (not in the context); calls to functions with a native
    # entry point pass their parameters as arguments and get r3 / f1 back as a value.
    mine = native_sig(fname)
    np_self = mine[0] if mine else 0
    li, lo = summarize.liveness(compact, inputs, mods, local_only=True, outputs_f=my_outputs, entry_written=np_self)
    lo_full = None
    if signatures() and READABLE:
        lo_full = summarize.liveness(compact, inputs, mods, exit_out=my_outputs)[1]
    ready = summarize.set_up_args(compact, inputs, mods)
    ready_res = summarize.set_up_args(compact, inputs, mods, results=True) if summarize.SPLIT is not None else None
    for s, a, b in zip(stmts, li, lo):
        s.live_in, s.live_out = a, b
    n = len(stmts)
    for s in stmts:
        s.dirty_in = None
    if n:
        stmts[0].dirty_in = np_self
    work = [0] if n else []
    while work:
        i = work.pop()
        s = stmts[i]
        a = s.acc
        if a.sync:
            # (standard calls: only arguments set up for this call; direct calls: what the callee really reads
            # plus what it may pass on of the registers that can hold an argument here)
            cin, cmods = summarize.site_inputs(a.callee, inputs, mods, ready[i],
                                               ready_res[i] if ready_res is not None else None)
            cin |= summarize.SP
            s.flush = s.dirty_in & (cin | (cmods & (s.live_out | my_outputs)))
            s.reload = s.live_out & cmods & ~a.def_
            if 'calls' in sync_dbg:
                s.flush = s.dirty_in
                s.reload = s.live_out & ~a.def_
            s.native, s.nflush, s.nreload, s.nret_ctx = None, 0, 0, False
            sig = native_sig(a.callee) if type(s.stmt) is ExprStmt and not summarize.is_indirect(a.callee) else None
            if sig is not None:
                npg, ret = sig
                s.native = (a.callee, npg, ret)
                s.nflush = s.flush & npg  # arguments that come from locals (the others are read from the context)
                s.flush &= ~npg
                if ret & s.reload:
                    s.nreload = ret       # the result goes into a local
                    s.reload &= ~ret
                elif ret and lo_full is not None and lo_full[i] & ret:
                    s.nret_ctx = True     # something later reads it from the context
            out = (s.dirty_in & ~s.flush & ~cmods) | a.def_ | s.nreload
            s.dirty_after = out
        else:
            out = s.dirty_in | a.def_
        for j in s.succ:
            if j == EXIT:
                continue
            t = stmts[j]
            new = out if t.dirty_in is None else (t.dirty_in | out)
            if new != t.dirty_in:
                t.dirty_in = new
                work.append(j)
    for s in stmts:
        if s.dirty_in is None:
            s.dirty_in = 0
    return my_outputs


# ---------------------------------------------------------------------------------------------
# Emission (pass 1)

def localize(e):
    def f(x):
        r = reg_of(x)
        if r:
            return Name(r)
        return None
    return map_expr(e, f)


def localize_stmt(st):
    t = type(st)
    if t is Assign:
        return Assign(localize(st.lhs), st.op, localize(st.rhs))
    if t is ExprStmt:
        return ExprStmt(localize(st.e))
    if t is Decl:
        return Decl(st.type, st.name, localize(st.init) if st.init is not None else None)
    if t is If:
        return If(localize(st.cond), localize_stmt(st.body))
    if t is Block:
        return Block([localize_stmt(x) for x in st.stmts])
    if t is Switch:
        return Switch(localize(st.e), st.cases, st.default)
    return st


def _res(r):
    """'cr6.eq' -> ('cr6', '.eq'); 'r3' -> ('r3', '')"""
    if '.' in r:
        reg, f = r.split('.')
        return reg, '.' + f
    return r, ''


def flush_lines(bits, indent):
    out = []
    for r in names(bits):
        reg, f = _res(r)
        out.append(f'{indent}ctx.{reg}{f} = {reg}{f};')
    return out


def reload_lines(bits, indent):
    out = []
    for r in names(bits):
        reg, f = _res(r)
        out.append(f'{indent}{reg}{f} = ctx.{reg}{f};')
    return out


def emit_function(fn, stmts, outputs, comment=None):
    used = set()
    for s in stmts:
        used |= s.acc.regs
    entry_live = stmts[0].live_in if stmts else 0
    out = []
    if comment:
        out.append(f'// {comment}')
    out.append(f'F2_LIFTED({fn.name}) {{')
    for d in fn.decls:
        out.append(stmt_str(d))
    order = {r: i for i, r in enumerate(regs.NAMES)}
    for reg in sorted(used, key=lambda r: order.get(r, order.get(r + '.lt', order.get('xer.so', 0)))):
        rb = regs.reg_bits(reg)
        if entry_live & rb == rb:
            out.append(f'	{ctype(reg)} {reg} = ctx.{reg};')
        else:
            out.append(f'	{ctype(reg)} {reg}{{}};')
            out.extend(reload_lines(entry_live & rb, '	'))
    for s in stmts:
        for l in s.labels:
            out.append(f'{l}:')
        if s.removed:
            if type(s.stmt) is Return or (s.returns and type(s.stmt) is not If):
                out.extend(flush_lines(s.dirty_in & outputs, '	'))
                out.append('	return;')
            continue
        if _is_call_lr(s):
            continue
        if s.insn is not None and s.insn.stmts and next((x for x in stmts if x.insn is s.insn and not x.removed and not _is_call_lr(x)), None) is s:
            out.append(f'	// {s.insn.asm}')
        st = localize_stmt(s.stmt)
        a = s.acc
        t = type(st)
        if a.sync:
            out.extend(flush_lines(s.flush, '	'))
            if t is If and type(st.body) is not Goto and type(st.body) is not Return:
                out.append(f'	if ({expr_str(st.cond)}) {{')
                out.append(stmt_str(st.body, '		'))
                out.extend(reload_lines(s.reload, '		'))
                out.append('	}')
            else:
                out.append(stmt_str(st))
                out.extend(reload_lines(s.reload, '	'))
            if s.returns and t is not Return:
                out.extend(flush_lines(((s.dirty_in & ~s.flush) | a.def_) & outputs, '	'))
                out.append('	return;')
        elif t is Return:
            out.extend(flush_lines(s.dirty_in & outputs, '	'))
            out.append('	return;')
        elif s.returns and t is not If:
            out.append(stmt_str(st))
            out.extend(flush_lines((s.dirty_in | a.def_) & outputs, '	'))
            out.append('	return;')
        elif t is If and type(st.body) is Return:
            fl = flush_lines(s.dirty_in & outputs, '		')
            if fl:
                out.append(f'	if ({expr_str(st.cond)}) {{')
                out.extend(fl)
                out.append('		return;')
                out.append('	}')
            else:
                out.append(stmt_str(st))
        else:
            out.append(stmt_str(st))
    out.append('}')
    return out


def compute_webs(fn, stmts, outputs):
    """Splits GPRs into web variables and decides 64-bit-ness per value (webs.py), with the
    whole-game demand summaries for callees and callers."""
    import summarize
    import typer
    import webs
    import emit
    sm = summaries()
    inputs, mods = sm['inputs'], sm['mods']
    wide_in, wide_out = sm.get('wide_in', {}), sm.get('wide_out', {})
    ind = summarize.IND
    gpr = summarize.GPR_BITS
    recs = []
    for s in stmts:
        if s.removed:
            recs.append((0, 0, False, None, tuple(s.succ), 0, ()))
            continue
        wset, e = typer.demand_info(localize_stmt(s.stmt))
        wb = 0
        for r in wset:
            wb |= regs.bit(r)
        recs.append((s.acc.use, s.acc.def_, s.acc.sync, s.acc.callee, tuple(s.succ), wb,
                     tuple((regs.INDEX[a], regs.INDEX[b]) for a, b in e)))
    ready = summarize.set_up_args([(r[0], r[1] | native_result(s)) + r[2:] for r, s in zip(recs, stmts)],
                                  inputs, mods)

    def call_mods(i):
        return summarize.call_summary(recs[i][3], inputs, mods)[1] & gpr

    def arg_wide(i):
        c = recs[i][3]
        if c in inputs:
            return inputs[c] & wide_in.get(c, gpr)
        if summarize.is_indirect(c):
            return ind['in'] & summarize.slot_wide_in(c, sm) & ready[i]
        if summarize._unknown_reader(c):
            return regs.ABI_INPUTS & gpr
        return 0
    # (callee-saved registers the function returns changed on purpose: the caller sees all 64 bits)
    exit_wide = (outputs & wide_out.get(fn.name, gpr)) | (unsaved_callee_saved(stmts) & gpr)

    def extra_reads(i):
        if i >= 0:
            return (stmts[i].flush | stmts[i].nflush) if stmts[i].acc.sync else 0
        s = stmts[-1 - i]
        return ((s.dirty_in & ~s.flush) | s.acc.def_ | s.dirty_in) & outputs
    res = webs.analyse(recs, regs.INDEX['r0'], call_mods, arg_wide, exit_wide, extra_reads)
    w = emit.Webs(res)
    import extkind
    w.set_kinds(extkind.def_kinds(res, lambda i: localize_stmt(stmts[i].stmt), typer.GPR))
    return w


def _is_call_lr(s):
    """'ctx.lr = 0x...;' before an ordinary call: callees only save/restore the link register."""
    st = s.stmt
    return (type(st) is Assign and st.op == '=' and type(st.lhs) is Member and type(st.lhs.obj) is Name and
            st.lhs.obj.id == 'ctx' and st.lhs.field == 'lr' and s.insn is not None and s.insn.op in ('bl', 'bctrl')
            and not any(x for x in s.insn.stmts if x is not st and 'setjmp' in stmt_str(x)))


def lift_function(fn, comment=None):
    if comment is None:
        n = catalog_names().get(fn.addr)
        if n:
            name, lua, size = n
            parts = [fn.name]
            if not name.startswith('sub_'):
                parts.append('= ' + name)
            if lua:
                parts.append(f'(Lua {lua})')
            comment = ' '.join(parts) + f'  [{size} bytes]'
    try:
        stmts = build(fn)
        outputs = analyse(stmts, fn.name)
        import emit
        w = compute_webs(fn, stmts, outputs) if READABLE else None
        sig = native_sig(fn.name)
        items = emit.items_of(fn, stmts, outputs, localize_stmt, _is_call_lr, w, my_ret=sig[1] if sig else 0)
        return emit.print_function(fn, stmts, items, READABLE, comment, w)
    except (LiftError, Unsupported) as e:
        raise LiftError(f'{fn.name}: {e}')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('files', nargs='*', type=int)
    ap.add_argument('--func')
    ap.add_argument('--skip', default='', help='file of function names to leave unlifted')
    ap.add_argument('--exact-views', action='store_true', help='keep PPCRegister locals (no typing)')
    ap.add_argument('--all', action='store_true', help='every generated file (in parallel)')
    ap.add_argument('--funcs', default='', help='only these functions (comma list of names/addresses, or a file '
                                                'with one name per line): rewrites only their chunk files')
    ap.add_argument('--split', action='store_true', help='one-time: split old lifted.N.cpp files into chunks')
    ap.add_argument('--rechunk', action='store_true', help='write every lifted file again from its blocks '
                                                           '(declarations at the top changed); lifts nothing')
    ap.add_argument('--facts', action='store_true', help='collect class-recovery facts for every function into '
                                                         'cache/facts (typefacts.py); writes no lifted code')
    ap.add_argument('--jobs', type=int, default=8)
    args = ap.parse_args()
    global READABLE
    READABLE = not (args.exact_views or os.environ.get('LIFT_EXACT'))  # (LIFT_EXACT=1: same, for scripts)
    if args.rechunk:
        import chunks
        print(f'{chunks.rewrite_all()} lifted files rewritten')
        return
    if args.facts:
        import multiprocessing as mp
        idx = [int(p.split('.')[-2]) for p in generated_files()]
        with mp.Pool(args.jobs) as pool:
            n = sum(pool.map(_facts_job, idx))
        print(f'facts for {n} functions in tools/lift/cache/facts')
        return
    if args.split:
        import chunks
        n = sum(chunks.split_monolithic(int(p.split('.')[-2])) for p in generated_files())
        print(f'split {n} functions into chunk files')
        return
    if args.funcs:
        # only these functions: re-lift them and rewrite just their chunk files
        import chunks
        names = set()
        for item in args.funcs.split(','):
            item = item.strip()
            if os.path.exists(item):
                names |= {l.strip().split()[0] for l in open(item) if l.strip()}
            elif item:
                names.add(item if item.startswith(('sub_', 'xstart')) else 'sub_' + item.upper())
        by_file = {}
        for n in names:
            fi = chunks.file_of(n)
            if fi is not None:
                by_file.setdefault(fi, set()).add(n)
        skip = set()
        if args.skip and os.path.exists(args.skip):
            skip = {l.strip() for l in open(args.skip) if l.strip()}
        tot_ok = tot_fail = tot_written = 0
        for fi, ns in sorted(by_file.items()):
            gone = {n for n in ns if n in skip or n.startswith('__')}
            if gone:  # (skipped: just drop their blocks, nothing to lift)
                tot_written += chunks.update(fi, {}, gone)
            if not ns - gone:
                continue
            ok, fail, failures, written = lift_file(fi, skip, only=ns - gone)
            tot_ok += ok
            tot_fail += fail
            tot_written += written
            for e in failures[:5]:
                print('   ', e)
        print(f'lifted {tot_ok} functions ({tot_fail} failed) in {len(by_file)} generated files; '
              f'{tot_written} chunk files rewritten')
        if os.environ.get('LIFT_COUNT'):
            import passes
            print('PASSCOUNT ' + ' '.join(f'{k}={v}' for k, v in sorted(passes.COUNT.items())))
        return
    if args.all:
        import multiprocessing as mp
        idx = [int(p.split('.')[-2]) for p in generated_files()]
        with mp.Pool(args.jobs) as pool:
            res = pool.map(_lift_file_job, [(i, args.skip, READABLE) for i in idx])
        ok = sum(r[0] for r in res)
        fail = sum(r[1] for r in res)
        written = sum(r[3] for r in res)
        print(f'lifted {ok} functions, {fail} left as recompiled; {written} chunk files rewritten')
        with open(os.path.join(OUT_DIR, 'lift_report.txt'), 'w', encoding='utf-8') as f:
            for r in res:
                for e in r[2]:
                    f.write(e + '\n')
        return
    paths = generated_files()
    if args.func:
        import json
        db = json.load(open(os.path.join(os.path.dirname(__file__), '..', '..', 'research', 'symbols', 'func_db.json')))
        e = db[args.func.upper()]
        for fn in read_file(os.path.join(os.path.dirname(paths[0]), e['file'])):
            if fn.addr == int(args.func, 16):
                print('\n'.join(lift_function(fn)))
        return
    skip = set()
    if args.skip and os.path.exists(args.skip):
        skip = {l.strip() for l in open(args.skip) if l.strip()}
    for idx in args.files:
        ok, fail, failures, written = lift_file(idx, skip)
        print(f'Fable2_recomp.{idx}.cpp: lifted {ok}, left as recompiled {fail}; {written} chunk files rewritten')
        for e in failures[:10]:
            print('   ', e)


def _facts_job(idx):
    import json
    import emit
    path = [p for p in generated_files() if p.endswith(f'.{idx}.cpp')][0]
    emit.FACTS = []
    emit.FLOW = []
    for fn in read_file(path):
        if fn.name.startswith('__'):
            continue
        try:
            lift_function(fn)
        except Exception:
            if os.environ.get('LIFT_FACTS_STRICT'):
                raise
    out = os.path.join(os.path.dirname(__file__), 'cache', 'facts')
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, f'{idx}.jsonl'), 'w', encoding='utf-8') as f:
        for fact in emit.FACTS:
            f.write(json.dumps(fact, separators=(',', ':')) + '\n')
    out = os.path.join(os.path.dirname(__file__), 'cache', 'flow')   # (typeflow.py)
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, f'{idx}.jsonl'), 'w', encoding='utf-8') as f:
        for fact in emit.FLOW:
            f.write(json.dumps(fact, separators=(',', ':')) + '\n')
    return len(emit.FACTS)


def _lift_file_job(a):
    idx, skipfile, readable = a
    global READABLE
    READABLE = readable
    skip = set()
    if skipfile and os.path.exists(skipfile):
        skip = {l.strip() for l in open(skipfile) if l.strip()}
    return lift_file(idx, skip)


def lift_file(idx, skip, only=None):
    """Lifts the functions of generated file idx (all, or only the names in `only`) into their chunk files
    (chunks.py). Returns (lifted, failed, failure messages, chunk files rewritten)."""
    import chunks
    paths = generated_files()
    path = [p for p in paths if p.endswith(f'.{idx}.cpp')][0]
    ok = fail = 0
    failures = []
    blocks, remove = {}, set()
    for fn in read_file(path, only=only):
        if only is not None and fn.name not in only:
            continue
        if fn.name in skip or fn.name.startswith('__'):
            remove.add(fn.name)  # (hand-written replacements, failed checks; the compiler's save/restore helpers)
            continue
        try:
            body = lift_function(fn)
            blocks[fn.name] = [chunks.MARK + fn.name] + body
            ok += 1
        except Exception as e:
            fail += 1
            remove.add(fn.name)
            failures.append(f'{fn.name}: {type(e).__name__}: {e}')
    written = chunks.update(idx, blocks, remove, replace_all=only is None)
    _save_varmap(idx, {int(n[4:], 16) for n in set(blocks) | remove if n.startswith('sub_')}, only is None)
    return ok, fail, failures, written


def _save_varmap(idx, addrs, whole):
    """cache/varmap/<idx>.json: which register variable each readable local of the file's functions stands for
    (readable.VARMAP; research/names/locals.tsv is keyed by the register variable)."""
    import json
    import readable
    path = os.path.join(os.path.dirname(__file__), 'cache', 'varmap', f'{idx}.json')
    os.makedirs(os.path.dirname(path), exist_ok=True)
    data = {}
    if not whole and os.path.exists(path):
        data = json.load(open(path, encoding='utf-8'))
    for a in addrs:
        data.pop(f'{a:08X}', None)
        if readable.VARMAP.get(a):
            data[f'{a:08X}'] = readable.VARMAP[a]
    with open(path, 'w', encoding='utf-8') as f:
        json.dump(data, f, separators=(',', ':'), sort_keys=True)


if __name__ == '__main__':
    main()
