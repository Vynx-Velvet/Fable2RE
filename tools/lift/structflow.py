"""Structural type inference (Phase B2, third step): a struct type for every pointer the game code uses.

    python tools/lift/structflow.py [--no-write] [--trace N]
        reads cache/flow2/*.jsonl (flowfacts2.py) and cache/classes.json; writes cache/structs_inferred.json

typeflow.py only carries class identities (vtables) around and reaches 7% of the accesses. Here every variable
that memory is accessed through is a pointer to *some* struct, and the structs are found by unification:

  x = y                      x and y have the same type
  x = y + k                  x points to the part of y's object at offset k (an embedded object; the next
                             element of an array when x is y)
  LOAD32(p + k) into x       x has the type of field k of p's struct
  STORE32(p + k, x)          field k of p's struct has x's type
  LOAD32(address) / STORE32  the same for the game's global variables
  f(.., x, ..)               x has the type of f's parameter;  x = f(..) / return x likewise for the result
  STORE32(p, vtable of C)    p's struct is class C (so are the first arguments of C's methods)

Two types that are unified become one (union-find); unifying two pointers unifies their structs, field by
field. The known failure of this method is over-unification: one helper used with unrelated types (a
container routine, a getter the linker folded for many classes) glues them all together. Guards:
  * two structs are not merged when they are different classes that are not on one inheritance line, or when
    the fields they have in common mostly disagree in size; the unification that asked for it is dropped and
    counted against the function it came through;
  * functions blamed that way, and pass-through helpers called from very many places, are "generic": they
    work on any type. Their constraints are applied again for every call site, with fresh variables, instead
    of once for all callers.
"""
import argparse
import collections
import glob
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

SKIP = {'r1', 'ea'}


class Types:
    def __init__(self, related):
        self.parent = []        # type nodes
        self.ptr = []           # root type node -> struct node (or -1)
        self.sparent = []       # struct nodes
        self.fields = []        # root struct -> {offset or ('e', offset): type node}
        self.sizes = []         # root struct -> {offset: set of (size, float?)}
        self.tags = []          # root struct -> set of class keys
        self.nvars = []         # root struct -> pointers unified into it
        self.related = related
        self.conflicts = 0
        self.work = []
        self.reason = None          # what the current unification comes from (for the merge log)
        self.big_merges = collections.Counter()   # reason -> merges of two already large structs
        self.max_off = 0x4000       # accesses beyond this are not fields of an object (split global addresses)

    def node(self):
        self.parent.append(len(self.parent))
        self.ptr.append(-1)
        return len(self.parent) - 1

    def find(self, a):
        p = self.parent
        while p[a] != a:
            p[a] = p[p[a]]
            a = p[a]
        return a

    def sfind(self, s):
        p = self.sparent
        while p[s] != s:
            p[s] = p[p[s]]
            s = p[s]
        return s

    def struct_of(self, a, create=True):
        a = self.find(a)
        if self.ptr[a] < 0:
            if not create:
                return -1
            self.sparent.append(len(self.sparent))
            self.fields.append({})
            self.sizes.append({})
            self.tags.append(set())
            self.nvars.append(1)
            self.ptr[a] = len(self.sparent) - 1
        return self.sfind(self.ptr[a])

    def field(self, s, off):
        s = self.sfind(s)
        f = self.fields[s].get(off)
        if f is None:
            f = self.fields[s][off] = self.node()
        return f

    def access(self, a, off, size, fl=0):
        if abs(off) > self.max_off:
            return
        s = self.struct_of(a)
        self.sizes[s].setdefault(off, set()).add((size, fl))

    def tag(self, a, key):
        s = self.struct_of(a)
        if all(self.related(key, t) for t in self.tags[s]):
            self.tags[s].add(key)
            return True
        return False

    def compatible(self, sa, sb):
        ta, tb = self.tags[sa], self.tags[sb]
        if ta and tb and not all(self.related(x, y) for x in ta for y in tb):
            return False
        za, zb = self.sizes[sa], self.sizes[sb]
        if len(za) > len(zb):
            za, zb = zb, za
        common = bad = 0
        for off, x in za.items():
            y = zb.get(off)
            if y is None:
                continue
            common += 1
            if not ({s for s, _ in x} & {s for s, _ in y}):
                bad += 1
        return not (common >= 6 and bad * 4 > common)

    def unify(self, a, b):
        """False when the unification itself was refused (not one it implies further down)."""
        ok = True
        self.work.append((a, b, True))
        while self.work:
            a, b, top = self.work.pop()
            a, b = self.find(a), self.find(b)
            if a == b:
                continue
            pa, pb = self.ptr[a], self.ptr[b]
            if pa >= 0 and pb >= 0:
                sa, sb = self.sfind(pa), self.sfind(pb)
                if sa != sb:
                    if not self.compatible(sa, sb):
                        self.conflicts += 1
                        if top:
                            ok = False
                        continue
                    if len(self.sizes[sa]) >= 40 and len(self.sizes[sb]) >= 40:
                        self.big_merges[self.reason] += 1
                    if len(self.fields[sa]) + len(self.sizes[sa]) < len(self.fields[sb]) + len(self.sizes[sb]):
                        sa, sb = sb, sa
                    self.sparent[sb] = sa
                    fa, fb = self.fields[sa], self.fields[sb]
                    for off, n in fb.items():
                        if off in fa:
                            self.work.append((fa[off], n, False))
                        else:
                            fa[off] = n
                    za = self.sizes[sa]
                    for off, zs in self.sizes[sb].items():
                        za.setdefault(off, set()).update(zs)
                    self.tags[sa] |= self.tags[sb]
                    self.nvars[sa] += self.nvars[sb]
                    self.fields[sb] = self.sizes[sb] = self.tags[sb] = None
                self.parent[b] = a
                self.ptr[a] = sa
            else:
                self.parent[b] = a
                if pb >= 0:
                    self.ptr[a] = pb
        return ok


def load_flow(sub='flow2'):
    flow = {}
    for p in glob.glob(os.path.join(HERE, 'cache', sub, '*.jsonl')):
        with open(p, encoding='utf-8') as f:
            for line in f:
                d = json.loads(line)
                flow[d['f']] = d
    return flow


def constants(d):
    """{variable: absolute address} for the variables of one function that hold a constant address: assigned
    one, or a constant plus an offset (the two halves of an address are often separate statements)."""
    k = dict(d.get('consts', {}))
    if not k:
        return k
    ndef = collections.Counter()
    for dst, _ in d.get('copies', ()):
        ndef[dst] += 1
    for dst, _, _ in d.get('adds', ()):
        ndef[dst] += 1
    for dst, _, _ in d.get('loads', ()):
        ndef[dst] += 1
    for _ in range(3):
        grew = False
        for dst, src, off in d.get('adds', ()):
            if src in k and dst not in k and ndef[dst] == 1:
                k[dst] = (k[src] + off) & 0xFFFFFFFF
                grew = True
        for dst, src in d.get('copies', ()):
            if src in k and dst not in k and ndef[dst] == 1:
                k[dst] = k[src]
                grew = True
        if not grew:
            break
    return k


class Solver:
    def __init__(self, flow, cl, log=print):
        import typeflow
        self.flow, self.cl, self.log = flow, cl, log
        h = typeflow.Hierarchy(cl)
        self.h = h
        rel = {}

        def related(a, b):
            if a == b:
                return True
            key = (a, b) if a < b else (b, a)
            r = rel.get(key)
            if r is None:
                r = rel[key] = a in h.line(b) or b in h.line(a)
            return r
        self.T = Types(related)
        self.var = {}
        self.ret = {}
        self.glob = {}
        self.gptr = {}
        self.frames = {}
        self.blame = collections.Counter()
        self.consts = {f: constants(d) for f, d in flow.items()}
        self.instances = 0

    def V(self, ns, v):
        k = (ns, v)
        n = self.var.get(k)
        if n is None:
            n = self.var[k] = self.T.node()
        return n

    def R(self, ns):
        n = self.ret.get(ns)
        if n is None:
            n = self.ret[ns] = self.T.node()
        return n

    def G(self, addr):
        """The type of the 32-bit value stored at a global address."""
        n = self.glob.get(addr)
        if n is None:
            n = self.glob[addr] = self.T.node()
        return n

    def GP(self, addr):
        """A pointer to the global object at addr (a constant address used as a pointer)."""
        n = self.gptr.get(addr)
        if n is None:
            n = self.gptr[addr] = self.T.node()
            self.T.struct_of(n)
        return n

    def frame(self, f):
        """The function's stack frame as a struct: `stack + k` points to the temporary at k."""
        n = self.frames.get(f)
        if n is None:
            n = self.frames[f] = self.T.node()
            self.T.struct_of(n)
        return n

    def local(self, f, ns, seeds=True):
        """The constraints inside function f, on the variables of namespace ns (f itself, or one call site)."""
        T, d, K = self.T, self.flow[f], self.consts[f]
        V = self.V
        if seeds:
            k = self.cl['this'].get(f)
            ev = d['entry'].get('r3')
            if k and ev and ev not in d.get('written', ()):
                T.tag(V(ns, ev), k)
            for b, off, const in d.get('vptr', ()):
                key = f'{const:08X}'
                if off == 0 and b not in SKIP and b != '@' and b not in K and key in self.cl['classes']:
                    T.tag(V(ns, b), key)
        for b, accs in d.get('acc', {}).items():
            if b in SKIP or b == '@':
                continue
            n = self.GP(K[b]) if b in K else V(ns, b)
            for off, size, fl in accs:
                T.access(n, off, size, fl)
        T.reason = ('copy', f)
        for dst, src in d.get('copies', ()):
            if dst in SKIP or src in SKIP or dst in K:
                continue
            T.unify(V(ns, dst), self.GP(K[src]) if src in K else V(ns, src))
        T.reason = ('add', f)
        for dst, src, off in d.get('adds', ()):
            if dst in SKIP or dst in K or off == 0 or abs(off) > T.max_off:
                continue
            if src in ('r1', 'ea'):
                T.unify(V(ns, dst), T.field(T.struct_of(self.frame(ns)), ('e', off)))   # (a stack temporary)
            elif src in K:
                T.unify(V(ns, dst), self.GP((K[src] + off) & 0xFFFFFFFF))
            elif src not in SKIP:
                T.unify(V(ns, dst), T.field(T.struct_of(V(ns, src)), ('e', off)))
        T.reason = ('load', f)
        for dst, b, off in d.get('loads', ()):
            if dst in SKIP or b in SKIP or (b != '@' and b not in K and abs(off) > T.max_off):
                continue
            if b == '@':
                T.unify(V(ns, dst), self.G(off))
            elif b in K:
                T.unify(V(ns, dst), T.field(T.struct_of(self.GP(K[b])), off))
            else:
                T.unify(V(ns, dst), T.field(T.struct_of(V(ns, b)), off))
        T.reason = ('store', f)
        for b, off, v in d.get('stores', ()):
            if v in SKIP or b in SKIP or v in K or (b != '@' and b not in K and abs(off) > T.max_off):
                continue
            if b == '@':
                T.unify(self.G(off), V(ns, v))
            elif b in K:
                T.unify(T.field(T.struct_of(self.GP(K[b])), off), V(ns, v))
            else:
                T.unify(T.field(T.struct_of(V(ns, b)), off), V(ns, v))
        T.reason = ('ret', f)
        for v in d.get('rets', ()):
            if v not in SKIP:
                T.unify(self.R(ns), self.GP(K[v]) if v in K else V(ns, v))

    def call(self, f, ns, callee, args, res, generic, depth=0):
        T = self.T
        cd = self.flow.get(callee)
        if cd is None:
            return
        K = self.consts[f]
        # inside a per-call-site copy every call is copied too (or left out when big): a shared callee there
        # would join all the copies again (operator new -> the heap allocator -> every allocated object)
        if callee in generic or not isinstance(ns, str):
            size = sum(len(cd.get(k, ())) for k in ('copies', 'adds', 'loads', 'stores')) + len(cd.get('acc', ()))
            if depth >= 2 or size > 120:
                return                      # (too big to repeat per call site: its callers stay unconnected)
            self.instances += 1
            cns = (callee, self.instances)
            self.local(callee, cns, seeds=False)
            for c2, a2, r2 in cd.get('calls', ()):
                self.call(callee, cns, c2, a2, r2, generic, depth + 1)
            target_ns = cns
        else:
            target_ns = callee
        for reg, v in args.items():
            ev = cd['entry'].get(reg)
            if ev is None or v in SKIP or ev in SKIP:
                continue
            T.reason = ('arg', callee, reg)
            src = self.GP(K[v]) if v in K else self.V(ns, v)
            if not T.unify(src, self.V(target_ns, ev)) and target_ns is callee:
                self.blame[callee] += 1
        if res and res not in SKIP and cd.get('rets'):
            T.reason = ('result', callee)
            if not T.unify(self.V(ns, res), self.R(target_ns)) and target_ns is callee:
                self.blame[callee] += 1

    def run(self, generic=frozenset()):
        T = self.T
        for f in self.flow:
            self.local(f, f)
        self.log(f'  inside functions: {len(T.parent)} type nodes, {len(T.sparent)} structs, {T.conflicts} refused')
        for f, d in self.flow.items():
            for callee, args, res in d.get('calls', ()):
                self.call(f, f, callee, args, res, generic)
        self.log(f'  between functions: {T.conflicts} refused in all, {len(self.blame)} functions blamed, '
                 f'{self.instances} per-call-site copies of generic functions')
        if T.big_merges:
            self.log('  merges of two already large structs (40+ offsets each), by what asked for them:')
            for r, n in T.big_merges.most_common(12):
                self.log(f'    {n:5}  {r}')
        return self


def polymorphic(flow, cl, log=print):
    """Functions whose callers hand a parameter objects of classes that are not on one inheritance line, or
    whose result lands in variables of such classes: they work on any type (allocation, lists, folded
    getters). Found with the types known inside each function alone (no call edges)."""
    S = Solver(flow, cl, log=lambda *_: None)
    T = S.T
    for f in flow:
        S.local(f, f)
    seen = collections.defaultdict(set)
    for f, d in flow.items():
        for callee, args, res in d.get('calls', ()):
            if callee not in flow:
                continue
            for reg, v in args.items():
                if v in SKIP or (f, v) not in S.var or reg not in flow[callee]['entry']:
                    continue
                st = T.struct_of(S.var[(f, v)], create=False)
                if st >= 0 and T.tags[st]:
                    seen[(callee, reg)].update(T.tags[st])
            if res and (f, res) in S.var:
                st = T.struct_of(S.var[(f, res)], create=False)
                if st >= 0 and T.tags[st]:
                    seen[(callee, 'ret')].update(T.tags[st])
    out = set()
    for (callee, reg), tags in seen.items():
        tags = sorted(tags)
        if any(not T.related(a, b) for i, a in enumerate(tags) for b in tags[i + 1:]):
            out.add(callee)
    log(f'  polymorphic by their callers: {len(out)} functions')
    return out


def pass_through_helpers(flow, min_callers=40):
    """Functions called from many places that do not access memory through their arguments themselves."""
    callers = collections.Counter()
    for d in flow.values():
        for callee, _, _ in d.get('calls', ()):
            callers[callee] += 1
    out = set()
    for f, n in callers.items():
        d = flow.get(f)
        if n >= min_callers and d is not None:
            if all(not d.get('acc', {}).get(ev) for ev in d['entry'].values()):
                out.add(f)
    return out


def report(S, log=print):
    T, flow, cl = S.T, S.flow, S.cl
    by_vars = collections.Counter()
    funcs_of = collections.defaultdict(set)
    site_struct = collections.Counter()
    sites = tagged = 0
    for (ns, v), n in S.var.items():
        if not isinstance(ns, str):
            continue                      # (per-call-site copies of generic functions)
        s = T.struct_of(n, create=False)
        if s < 0:
            continue
        by_vars[s] += 1
        k = len(flow[ns].get('acc', {}).get(v, ()))
        if k:
            sites += k
            site_struct[s] += k
            funcs_of[s].add(ns)
            if T.tags[s]:
                tagged += k
    shared = sum(k for s, k in site_struct.items() if len(funcs_of[s]) >= 5)
    alone = sum(k for s, k in site_struct.items() if len(funcs_of[s]) == 1)
    log(f'  access sites through variables: {sites}; structs they fall into: {len(site_struct)}')
    log(f'    in a struct with a class identity: {tagged} ({100 * tagged / max(sites, 1):.1f}%)')
    log(f'    in a struct used by 5 or more functions: {shared} ({100 * shared / max(sites, 1):.1f}%)')
    log(f'    in a struct only one function uses: {alone} ({100 * alone / max(sites, 1):.1f}%)')
    log('  largest structs (access sites, functions, offsets, classes):')
    for s, k in site_struct.most_common(8):
        tg = sorted(T.tags[s])
        names = [cl['classes'][t]['name'] for t in tg[:3]]
        log(f'    {k:7} sites  {len(funcs_of[s]):6} functions  {len(T.sizes[s]):5} offsets  '
            f'{len(tg)} classes {names}')
    # virtual calls: does the object's struct say which classes it can be?
    n = known = 0
    cands = []
    kids = collections.defaultdict(set)
    for k in cl['classes']:
        for b in S.h.line(k)[1:]:
            kids[b].add(k)
    for f, d in flow.items():
        for slot, obj, voff, args, res in d.get('icalls', ()):
            if slot is None:
                continue
            n += 1
            if obj is None or obj in SKIP or (f, obj) not in S.var:
                continue
            s = T.struct_of(S.var[(f, obj)], create=False)
            if s < 0 or not T.tags[s]:
                continue
            known += 1
            top = max(T.tags[s], key=lambda t: len(kids[t]))
            cands.append(1 + len(kids[top]))
    cands.sort()
    log(f'  virtual calls: {n}; object of a known class: {known} ({100 * known / max(n, 1):.1f}%)'
        + (f'; classes it can be: median {cands[len(cands) // 2]}, 90th percentile {cands[len(cands) * 9 // 10]}'
           if cands else ''))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-write', action='store_true')
    a = ap.parse_args()
    flow = load_flow()
    cl = json.load(open(os.path.join(HERE, 'cache', 'classes.json'), encoding='utf-8'))
    print(f'{len(flow)} functions with flow facts')
    print('pass 1: every function once for all its callers')
    S = Solver(flow, cl).run()
    report(S)
    generic = set(S.blame) | pass_through_helpers(flow) | polymorphic(flow, cl)
    for rnd in (2, 3):
        print(f'pass {rnd}: {len(generic)} generic functions repeated per call site')
        S = Solver(flow, cl).run(frozenset(generic))
        report(S)
        new = set(S.blame) - generic
        if not new:
            break
        generic |= new
    if a.no_write:
        return
    T = S.T
    out = {'vars': collections.defaultdict(dict), 'structs': {}, 'generic': sorted(generic)}
    ids = {}
    for (ns, v), n in S.var.items():
        if not isinstance(ns, str):
            continue
        s = T.struct_of(n, create=False)
        if s >= 0 and T.sizes[s]:
            out['vars'][ns][v] = ids.setdefault(s, len(ids))
    for s, i in list(ids.items()):
        fl = {}
        for off, zs in T.sizes[s].items():
            e = {'sizes': sorted({z for z, _ in zs}), 'float': int(all(fl_ for _, fl_ in zs))}
            n = T.fields[s].get(off)
            if n is not None:
                ps = T.struct_of(n, create=False)
                if ps >= 0 and ps in ids:
                    e['to'] = ids[ps]
            fl[str(off)] = e
        out['structs'][str(i)] = {'fields': fl, 'classes': sorted(T.tags[s])}
    with open(os.path.join(HERE, 'cache', 'structs_inferred.json'), 'w', encoding='utf-8') as f:
        json.dump(out, f, separators=(',', ':'))
    print(f'{len(ids)} structs written')


if __name__ == '__main__':
    main()
