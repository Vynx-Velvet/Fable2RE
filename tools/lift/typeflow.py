"""Whole-program propagation of class types (Phase B2, second step).

    python tools/lift/typeflow.py            reads cache/flow/*.jsonl + cache/classes.json, writes cache/vartypes.json

classes.py types a method's own object (`this`). This carries those types on to every variable they reach:

  seeds     the first argument of a class's methods and constructors (classes.json 'this');
            a variable that gets a class's vtable stored at offset 0 (an object built in place)
  copies    dst = src
  calls     a typed variable passed as an argument types the callee's parameter, when the call sites agree
  returns   a function whose returned variables have one class returns that class; so does the variable that
            receives its result
  fields    a typed variable stored to a field of a typed object types the field; a load of the field is typed

"Agree" = every typed source names the same class (or classes on one inheritance line: the base is taken) and
at least half of the sources are typed. A type is only a label for display: the lifter prints an access
through a typed variable as a member access when the class has a field of that offset and size, and as the
same raw access otherwise, so a wrong guess cannot change behaviour.

vartypes.json: vars {function: {variable: class key}}, params {function: {register: class key}},
rets {function: class key}, fields {"class:offset": class key}.
"""
import collections
import glob
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))


def load():
    flow = {}
    for p in glob.glob(os.path.join(HERE, 'cache', 'flow', '*.jsonl')):
        with open(p, encoding='utf-8') as f:
            for line in f:
                d = json.loads(line)
                flow[d['f']] = d
    cl = json.load(open(os.path.join(HERE, 'cache', 'classes.json'), encoding='utf-8'))
    return flow, cl


class Hierarchy:
    def __init__(self, cl):
        self.base = {}
        for k, c in cl['classes'].items():
            b = [x for x in c.get('bases', []) if x in cl['classes'] and x != k]
            if b:
                self.base[k] = b[0]
        self.fields = {k: {int(o): v for o, v in c['fields'].items()} for k, c in cl['classes'].items()}
        self.inferred = self._bases_from_vtables(cl)
        for k, b in self.inferred.items():
            self.base.setdefault(k, b)

    @staticmethod
    def _bases_from_vtables(cl, min_shared=3, share=0.8):
        """Base classes from the tables themselves: a derived class's vtable keeps the base's function in every
        slot it does not override. B derives from A when A's table is no longer than B's and at least 80% of
        A's slots (3 or more; slot 0, the destructor, not counted) hold the same function in B; a sibling shares
        less, because each overrides its own. The longest such A is the closest ancestor."""
        import collections
        vt = {k: c['vtable'] for k, c in cl['classes'].items() if len(c['vtable']) >= 2}
        owners = collections.defaultdict(list)
        for k, t in vt.items():
            for i, fn in enumerate(t):
                if i:
                    owners[(i, fn)].append(k)
        out = {}
        for b, tb in vt.items():
            count = collections.Counter()
            for i, fn in enumerate(tb):
                if i:
                    for a in owners.get((i, fn), ()):
                        if a != b:
                            count[a] += 1
            best = None
            for a, n in count.items():
                ta = vt[a]
                if len(ta) > len(tb) or len(ta) - 1 < min_shared or n < min_shared or n < share * (len(ta) - 1):
                    continue
                if len(ta) == len(tb):
                    continue   # (tables of equal length: a sibling or the base - no way to tell which)
                if best is None or len(ta) > len(vt[best]) or (len(ta) == len(vt[best]) and n > count[best]):
                    best = a
            if best is not None:
                out[b] = best
        # no cycles: drop an inferred base that would make a class its own ancestor
        for b in list(out):
            seen, x = set(), b
            while x in out and x not in seen:
                seen.add(x)
                x = out[x]
            if x in seen:
                del out[b]
        return out

    def line(self, k):
        out, seen = [], set()
        while k is not None and k not in seen:
            out.append(k)
            seen.add(k)
            k = self.base.get(k)
        return out

    def join(self, kinds):
        """The class all of `kinds` are (the most derived common one), or None."""
        kinds = list(kinds)
        if not kinds:
            return None
        common = self.line(kinds[0])
        for k in kinds[1:]:
            ln = set(self.line(k))
            common = [x for x in common if x in ln]
            if not common:
                return None
        return common[0]

    def field(self, k, off, size):
        """(owning class, field) for an access of `size` bytes at `off` in an object of class k, or None."""
        for c in self.line(k):
            f = self.fields.get(c, {}).get(off)
            if f is not None and f[2] == size:
                return c, f
        return None


def agree(h, cands, total, need=0.5):
    """cands: classes named by the typed sources; total: number of sources."""
    if not cands or len(cands) < need * total:
        return None
    return h.join(set(cands))


def solve(flow, cl, rounds=12, log=print):
    h = Hierarchy(cl)
    T = collections.defaultdict(dict)   # function -> {variable: class}
    multi = {f: set(d.get('multi', ())) | set(d.get('written', ())) for f, d in flow.items()}

    def put(f, v, k):
        if k is None or v in T[f] or v in multi[f]:
            return False
        T[f][v] = k
        return True
    # seeds
    for f, k in cl['this'].items():
        d = flow.get(f)
        if d and d['entry'].get('r3'):
            put(f, d['entry']['r3'], k)
    vtable_len = {k: len(c['vtable']) for k, c in cl['classes'].items()}
    for f, d in flow.items():
        best = {}
        for v, const in d.get('vptr', ()):
            k = f'{const:08X}'
            if k in cl['classes'] and vtable_len[k] >= vtable_len.get(best.get(v), -1):
                best[v] = k   # (constructors store the base's table first: the largest table is the object's own)
        for v, k in best.items():
            put(f, v, k)
    P, R, FT = {}, {}, {}
    callers = collections.defaultdict(list)   # callee -> [(caller, {reg: var})]
    for f, d in flow.items():
        for callee, args in d.get('calls', ()):
            callers[callee].append((f, args))
    for rnd in range(rounds):
        changed = 0
        # inside each function
        for f, d in flow.items():
            t = T[f]
            again = True
            while again:
                again = False
                for dst, src in d.get('copies', ()):
                    if src in t and put(f, dst, t[src]):
                        again = True
                for dst, b, off in d.get('loads', ()):
                    if b in t:
                        for c in h.line(t[b]):
                            k = FT.get((c, off))
                            if k:
                                if put(f, dst, k):
                                    again = True
                                break
                for callee, v in d.get('results', ()):
                    if callee in R and put(f, v, R[callee]):
                        again = True
                if again:
                    changed += 1
        # parameters
        for callee, sites in callers.items():
            d = flow.get(callee)
            if d is None:
                continue
            for reg, ev in d['entry'].items():
                if (callee, reg) in P or (reg == 'r3' and callee in cl['this']):
                    continue
                cands, total = [], 0
                for caller, args in sites:
                    v = args.get(reg)
                    if v is None:
                        continue
                    total += 1
                    k = T[caller].get(v)
                    if k:
                        cands.append(k)
                k = agree(h, cands, total)
                if k:
                    P[(callee, reg)] = k
                    if put(callee, ev, k):
                        changed += 1
        # return values
        for f, d in flow.items():
            if f in R or not d.get('rets'):
                continue
            cands = [T[f][v] for v in d['rets'] if v in T[f]]
            k = agree(h, cands, len(d['rets']))
            if k:
                R[f] = k
                changed += 1
        # fields that hold objects
        stores = collections.defaultdict(lambda: [[], 0])
        for f, d in flow.items():
            t = T[f]
            for b, off, v in d.get('stores', ()):
                if b in t and off:
                    s = stores[(t[b], off)]
                    s[1] += 1
                    if v in t:
                        s[0].append(t[v])
        for key, (cands, total) in stores.items():
            if key not in FT:
                k = agree(h, cands, total)
                if k:
                    FT[key] = k
                    changed += 1
        log(f'round {rnd + 1}: {sum(len(t) for t in T.values())} typed variables, {len(P)} parameters, '
            f'{len(R)} return types, {len(FT)} object fields')
        if not changed:
            break
    return h, T, P, R, FT


def main():
    flow, cl = load()
    h, T, P, R, FT = solve(flow, cl)
    # what it buys: constant-offset accesses that can be printed as member accesses
    this_only = typed = total = 0
    for f, d in flow.items():
        t = T.get(f, {})
        k0 = cl['this'].get(f)
        ev = d['entry'].get('r3')
        for v, accs in d.get('acc', {}).items():
            if v in ('ea', 'r1'):
                continue
            total += len(accs)
            if v in t:
                n = sum(1 for off, size in accs if h.field(t[v], off, size))
                typed += n
                if k0 and t[v] == k0 and (v == ev or [v, ev] in d.get('copies', ())):
                    this_only += n
    funcs = sum(1 for t in T.values() if t)
    print(f'{funcs} functions with typed variables; distinct access sites through variables: {total}, '
          f'typed with a known field: {typed} ({100 * typed / max(total, 1):.1f}%), of them through the '
          f'method\'s own object: {this_only}')
    out = {'vars': {f: t for f, t in T.items() if t},
           'params': collections.defaultdict(dict), 'rets': R,
           'fields': {f'{c}:{off:X}': k for (c, off), k in FT.items()}}
    for (f, reg), k in P.items():
        out['params'][f][reg] = k
    with open(os.path.join(HERE, 'cache', 'vartypes.json'), 'w', encoding='utf-8') as f:
        json.dump(out, f, separators=(',', ':'), sort_keys=True)


if __name__ == '__main__':
    main()
