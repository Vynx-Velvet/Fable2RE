"""Per-value analysis of general-purpose registers: reaching definitions, 64-bit demand per value,
and webs (a register split into independent variables, one per group of definitions that reach
common uses).

Compiled code reuses registers for unrelated values; deciding "64-bit or not" per register lets
one 64-bit store of r11 make every value r11 ever holds 64-bit. Per definition, only the values
that reach that store are.

Input: compact statements (use, def, sync, callee, succ, wide_reads, edges) as in summarize.py, plus
per-call information from the caller of analyse():
  call_mods(i)     GPR bits a call at statement i may change (each becomes a new definition there)
  arg_wide(i)      GPR bits whose upper half the callee at i reads
  exit_wide        GPR bits whose upper half the caller reads after this function returns
"""
EXIT = -1
NGPR = 32


def _bits(x):
    """Indices of the set bits of x (jumps from set bit to set bit: def-id sets are large and sparse)."""
    out = []
    while x:
        low = x & -x
        out.append(low.bit_length() - 1)
        x ^= low
    return out


class Result:
    __slots__ = ('defs', 'rd_in', 'rd_out', 'def_at', 'call_def_at', 'entry_def', 'wide', 'web', 'nweb_of',
                 'wide_in', 'callee_wide_out', 'deps')


def analyse(stmts, gpr_index, call_mods, arg_wide, exit_wide, extra_reads=None, need_webs=True, _deps_only=False):
    """gpr_index: resource bit index of r0 (GPRs are bits gpr_index .. gpr_index+31).
    extra_reads(i) -> GPR bits read at statement i besides its own uses (context write-backs).
    Returns Result with:
      defs[k] = (reg, kind, i)  kind 'E' entry / 'S' statement / 'C' call
      rd_in[i][reg], rd_out[i][reg]  bitsets of def ids
      wide[k]  bool, web[k] web id, wide_in GPR bits, callee_wide_out {i: GPR bits}"""
    n = len(stmts)
    g0 = gpr_index
    mask = ((1 << NGPR) - 1) << g0
    used = exit_wide & mask
    for i, st in enumerate(stmts):
        used |= (st[0] | st[1] | st[5]) & mask
        for a, b in st[6]:
            used |= (1 << a) | (1 << b)
        if st[2]:
            used |= arg_wide(i) & mask
        if extra_reads:
            used |= extra_reads(i) & mask
            if EXIT in st[4]:
                used |= extra_reads(-1 - i) & mask
    used &= mask
    used_regs = _bits(used >> g0)
    defs = []
    entry_def = {}
    for r in used_regs:
        k = len(defs)
        defs.append((r, 'E', -1))
        entry_def[r] = k
    def_at = [dict() for _ in range(n)]       # statement def: reg -> def id
    call_def_at = [dict() for _ in range(n)]  # call def
    for i, st in enumerate(stmts):
        use, def_, sync, callee, succ = st[:5]
        if sync:
            for r in _bits((call_mods(i) & used) >> g0):
                call_def_at[i][r] = len(defs)
                defs.append((r, 'C', i))
            for r in _bits((def_ & mask) >> g0):
                if r not in call_def_at[i]:
                    def_at[i][r] = len(defs)
                    defs.append((r, 'S', i))
        else:
            for r in _bits((def_ & mask) >> g0):
                def_at[i][r] = len(defs)
                defs.append((r, 'S', i))
    # reaching definitions (all registers at once: per statement a dict reg -> bitset)
    rd_in = [None] * n
    rd_out = [None] * n
    if n:
        rd_in[0] = {r: 1 << entry_def[r] for r in used_regs}
    work = list(range(n - 1, -1, -1)) if n else []
    inq = set(work)
    while work:
        i = work.pop()
        inq.discard(i)
        cur = rd_in[i]
        if cur is None:
            continue
        out = dict(cur)
        for r, k in call_def_at[i].items():
            out[r] = 1 << k
        for r, k in def_at[i].items():
            out[r] = 1 << k
        rd_out[i] = out
        for j in stmts[i][4]:
            if j == EXIT:
                continue
            if rd_in[j] is None:
                rd_in[j] = dict(out)
                ch = True
            else:
                ch = False
                tgt = rd_in[j]
                for r, v in out.items():
                    o = tgt.get(r, 0)
                    if v | o != o:
                        tgt[r] = v | o
                        ch = True
            if ch and j not in inq:
                work.append(j)
                inq.add(j)
    for i in range(n):
        if rd_in[i] is None:
            rd_in[i] = {}
            rd_out[i] = {}
    # 64-bit demand per definition
    nd = len(defs)
    wide = [False] * nd
    stack = []
    if _deps_only:
        deps = [[] for _ in range(nd)]

    def mark(bitset):
        for k in _bits(bitset):
            if not wide[k]:
                wide[k] = True
                stack.append(k)
    for i, st in enumerate(stmts):
        if _deps_only:
            break
        use, def_, sync, callee, succ, wb, edges = st
        for r in _bits((wb & mask) >> g0):
            mark(rd_in[i].get(r, 0))
        if sync:
            for r in _bits((arg_wide(i) & mask) >> g0):
                mark(rd_in[i].get(r, 0))
        if EXIT in succ:
            for r in _bits((exit_wide & mask) >> g0):
                mark(rd_out[i].get(r, 0))
    # dependencies: def k depends on (statement i, src reg) reads
    deps = [[] for _ in range(nd)]
    for i, st in enumerate(stmts):
        use, def_, sync, callee, succ, wb, edges = st
        for a, b in edges:
            ra, rb = a - g0, b - g0
            if 0 <= ra < NGPR and 0 <= rb < NGPR:
                k = def_at[i].get(rb)
                if k is not None:
                    deps[k].append(rd_in[i].get(ra, 0))
        for r, k in def_at[i].items():  # partial / compound writes keep (part of) the old value
            if (use >> (g0 + r)) & 1:
                deps[k].append(rd_in[i].get(r, 0))
        for r, k in call_def_at[i].items():  # the callee may leave the value as it was
            deps[k].append(rd_in[i].get(r, 0))
    while stack:
        k = stack.pop()
        for bs in deps[k]:
            mark(bs)
    res = Result()
    res.defs, res.rd_in, res.rd_out, res.def_at, res.call_def_at = defs, rd_in, rd_out, def_at, call_def_at
    if _deps_only:
        res.deps = deps
        res.entry_def = entry_def
        return res
    res.entry_def, res.wide = entry_def, wide
    res.wide_in = 0
    res.web = None
    for r, k in entry_def.items():
        if wide[k]:
            res.wide_in |= 1 << (g0 + r)
    res.callee_wide_out = {}
    for i in range(n):
        for r, k in call_def_at[i].items():
            if wide[k]:
                res.callee_wide_out[i] = res.callee_wide_out.get(i, 0) | (1 << (g0 + r))
    if not need_webs:
        return res
    # webs: definitions reaching a common read (or joined by a partial write) share a variable
    parent = list(range(nd))

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union_bits(bitset, extra=None):
        ks = _bits(bitset)
        if extra is not None:
            ks.append(extra)
        if len(ks) < 2:
            return
        r0 = find(ks[0])
        for k in ks[1:]:
            rk = find(k)
            if rk != r0:
                parent[rk] = r0
    for i, st in enumerate(stmts):
        use, def_, sync = st[0], st[1], st[2]
        reads = use | (extra_reads(i) if extra_reads else 0)
        for r in _bits((reads & mask) >> g0):
            union_bits(rd_in[i].get(r, 0))
        for r, k in def_at[i].items():
            if (use >> (g0 + r)) & 1:
                union_bits(rd_in[i].get(r, 0), k)
        if EXIT in st[4] and extra_reads:
            for r in _bits((extra_reads(-1 - i) & mask) >> g0):  # (write-backs after statement i)
                union_bits(rd_out[i].get(r, 0))
    res.web = [find(k) for k in range(nd)]
    return res


# ---------------------------------------------------------------------------------------------
# Fast path for the whole-game demand fixpoint: everything that does not depend on the other
# functions' summaries is computed once per function (prepare); each re-analysis only seeds and
# propagates 64-bit demand through the dependency graph (propagate).

class Prep:
    __slots__ = ('nd', 'g0', 'seed_static', 'sync_rd', 'exit_rd', 'deps', 'entry_def', 'call_defs')


def prepare(stmts, gpr_index, call_mods, candidate_regs):
    """candidate_regs: GPR bits that arguments / results may involve beyond the function's own
    uses (so pass-through arguments get entry definitions)."""
    g0 = gpr_index
    mask = ((1 << NGPR) - 1) << g0
    res = analyse(stmts, g0, call_mods, lambda i: candidate_regs, candidate_regs, need_webs=False,
                  _deps_only=True)
    p = Prep()
    p.nd = len(res.defs)
    p.g0 = g0
    seed = 0
    for i, st in enumerate(stmts):
        for r in _bits((st[5] & mask) >> g0):
            seed |= res.rd_in[i].get(r, 0)
    p.seed_static = seed
    p.sync_rd = [(i, {r: res.rd_in[i].get(r, 0) for r in _bits((candidate_regs & mask) >> g0) if res.rd_in[i].get(r, 0)})
                 for i, st in enumerate(stmts) if st[2]]
    ex = {}
    for i, st in enumerate(stmts):
        if EXIT in st[4]:
            for r, v in res.rd_out[i].items():
                ex[r] = ex.get(r, 0) | v
    p.exit_rd = ex
    p.deps = res.deps
    p.entry_def = res.entry_def
    p.call_defs = [(i, r, k) for i in range(len(stmts)) for r, k in res.call_def_at[i].items()]
    return p


def propagate(p, arg_wide, exit_wide):
    """(wide_in GPR bits, {statement: callee result bits read as 64-bit})"""
    g0 = p.g0
    wide = bytearray(p.nd)
    seed = p.seed_static
    for i, rdmap in p.sync_rd:
        aw = arg_wide(i) >> g0
        if aw:
            for r, v in rdmap.items():
                if (aw >> r) & 1:
                    seed |= v
    ew = exit_wide >> g0
    if ew:
        for r, v in p.exit_rd.items():
            if (ew >> r) & 1:
                seed |= v
    stack = []
    for k in _bits(seed):
        wide[k] = 1
        stack.append(k)
    deps = p.deps
    while stack:
        k = stack.pop()
        for bs in deps[k]:
            while bs:
                low = bs & -bs
                j = low.bit_length() - 1
                bs ^= low
                if not wide[j]:
                    wide[j] = 1
                    stack.append(j)
    wide_in = 0
    for r, k in p.entry_def.items():
        if wide[k]:
            wide_in |= 1 << (g0 + r)
    cwo = {}
    for i, r, k in p.call_defs:
        if wide[k]:
            cwo[i] = cwo.get(i, 0) | (1 << (g0 + r))
    return wide_in, cwo
