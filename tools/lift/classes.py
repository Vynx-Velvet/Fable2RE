"""Class model for Phase B2: classes from vtables, the type of each function's first argument, fields.

    python tools/lift/lift.py --facts          (per-function facts, tools/lift/typefacts.py)
    python tools/lift/classes.py               -> tools/lift/cache/classes.json + statistics

Sources:
  * vtables: constants in code that point at a table of function addresses (as vtables.py)
  * names: MSVC RTTI where the binary has it (word before the vtable -> type descriptor); else C_<address>
  * constructors / destructors: functions that store a vtable address at offset 0 of their first argument;
    a function storing several (inlined base constructors) links derived class -> base classes
  * `this` types: functions in a vtable and constructors are methods of that class; a function that receives
    an unchanged `this` from a typed function as its own first argument is a method too (propagated)
  * fields: constant-offset memory accesses through `this` in all methods of a class
"""
import collections
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
CACHE = os.path.join(HERE, 'cache')
IMAGE_BASE = 0x82000000
RDATA = (0x82000600, 0x82000600 + 0x10A348)
DATA = (0x832D0000, 0x832D0000 + 0x22B5EC)


def load_image():
    return open(os.path.join(ROOT, 'research', 'decomp', 'default_image.bin'), 'rb').read()


def find_vtables(img, db):
    starts = {int(a, 16) for a in db}

    def word(a):
        o = a - IMAGE_BASE
        return struct.unpack_from('>I', img, o)[0] if 0 <= o <= len(img) - 4 else None

    def in_tables(a):
        return RDATA[0] <= a < RDATA[1] or DATA[0] <= a < DATA[1]
    vt_starts = set()
    for a, e in db.items():
        for c in e.get('consts', []):
            v = int(c, 16)
            if in_tables(v) and v % 4 == 0 and word(v) in starts:
                vt_starts.add(v)
    tables = {}
    for vt in sorted(vt_starts):
        k, entries = 0, []
        while True:
            a = vt + 4 * k
            w = word(a)
            if w not in starts or (k and a in vt_starts):
                break
            entries.append(f'sub_{w:08X}')
            k += 1
        tables[vt] = entries
    return tables, word


def rtti_name(vt, word, img):
    """Class name from the RTTI complete object locator stored before the vtable, if any."""
    loc = word(vt - 4)
    if loc is None or not (RDATA[0] <= loc < RDATA[1] or DATA[0] <= loc < DATA[1]):
        return None
    td = word(loc + 12)
    if td is None or not (RDATA[0] <= td < RDATA[1] or DATA[0] <= td < DATA[1]):
        return None
    o = td + 8 - IMAGE_BASE
    raw = img[o:o + 128].split(b'\0')[0]
    m = re.fullmatch(rb'\.\?A[VU]([A-Za-z0-9_@?$]+)@@', raw)
    if not m:
        return None
    parts = m.group(1).decode().split('@')
    if any(p.startswith('?') or '$' in p for p in parts):
        return None  # (templates / anonymous namespaces: not a plain name)
    return '::'.join(reversed(parts))


def load_facts():
    facts = {}
    d = os.path.join(CACHE, 'facts')
    for f in os.listdir(d):
        if f.endswith('.jsonl'):
            for line in open(os.path.join(d, f), encoding='utf-8'):
                x = json.loads(line)
                facts[x['f']] = x
    return facts


def main():
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    img = load_image()
    tables, word = find_vtables(img, db)
    facts = load_facts()
    import names as dictionary  # research/names: our own names win over RTTI and placeholders
    names = {}
    for vt in tables:
        n = dictionary.cls(vt) or rtti_name(vt, word, img)
        names[vt] = n or f'C_{vt:08X}'
    # constructors / destructors and the base links they show
    ctor_of = collections.defaultdict(set)   # vtable -> functions storing it
    for f, x in facts.items():
        for v in x['vptr']:
            if v in tables:
                ctor_of[v].add(f)

    def vptrs(f, seen=None):
        seen = seen if seen is not None else set()
        if f in seen or f not in facts:
            return set()
        seen.add(f)
        out = {v for v in facts[f]['vptr'] if v in tables}
        for g in facts[f]['passes']:
            if g in facts and facts[g]['vptr']:
                out |= vptrs(g, seen)
        return out
    bases = collections.defaultdict(set)
    for f, x in facts.items():
        vs = vptrs(f)
        if len(vs) > 1:
            derived = max(vs, key=lambda v: (len(tables[v]), v))
            for v in vs:
                if v != derived and len(tables[v]) <= len(tables[derived]):
                    bases[derived].add(v)

    def ancestors(v, seen=None):
        seen = seen if seen is not None else set()
        for b in bases.get(v, ()):
            if b not in seen:
                seen.add(b)
                ancestors(b, seen)
        return seen
    # seeds: the class of `this`
    this = {}  # function -> vtable
    in_tables = collections.defaultdict(list)
    for vt, entries in tables.items():
        for f in entries:
            in_tables[f].append(vt)
    for f, vts in in_tables.items():
        # a method inherited by several classes belongs to the base-most one (fewest slots)
        this[f] = min(vts, key=lambda v: (len(tables[v]), v))
    for v, fs in ctor_of.items():
        for f in fs:
            vs = vptrs(f)
            this[f] = max(vs, key=lambda x: (len(tables[x]), x))
    seeds = len(this)
    # propagate through calls that pass `this` on unchanged
    cand = collections.defaultdict(collections.Counter)
    work = list(this)
    while work:
        f = work.pop()
        c = this[f]
        for g in facts.get(f, {}).get('passes', ()):
            if g in in_tables or g in facts and facts[g]['vptr']:
                continue  # (already typed by its own vtable / constructor role)
            cand[g][c] += 1
            best = pick(cand[g], ancestors, tables)
            if this.get(g) != best:
                this[g] = best
                work.append(g)
    # fields
    fields = collections.defaultdict(dict)  # class -> offset -> [sizes, integer accesses, float accesses]
    for f, c in this.items():
        for off, size, kind in facts.get(f, {}).get('fields', ()):
            cur = fields[c].setdefault(off, [set(), 0, 0])
            cur[0].add(size)
            cur[2 if 'f' in kind else 1] += 1
    layouts = {v: layout(fields[v]) for v in tables if fields.get(v)}
    for v, lay in layouts.items():
        for off in list(lay):
            n = dictionary.field(v, off)
            if n and n not in {x[0] for x in lay.values()}:
                lay[off] = (n,) + tuple(lay[off][1:])
    idents = identifiers(tables, names)
    write_header(layouts, idents, tables, names, ctor_of)
    out = {'classes': {f'{v:08X}': {'name': names[v], 'vtable': tables[v], 'bases': sorted(f'{b:08X}' for b in bases.get(v, ())),
                                    'ctors': sorted(ctor_of.get(v, ())),
                                    'struct': idents[v],
                                    'fields': {str(o): [n, t, s] for o, (n, t, s) in layouts.get(v, {}).items()}}
                       for v in tables},
           'this': {f: f'{c:08X}' for f, c in this.items()}}
    with open(os.path.join(CACHE, 'classes.json'), 'w', encoding='utf-8') as f:
        json.dump(out, f, separators=(',', ':'))
    typed_fields = sum(len(v) for v in layouts.values())
    with_fields = sum(1 for v in tables if fields.get(v))
    print(f'{len(tables)} vtables / classes ({sum(1 for v in names.values() if not v.startswith("C_"))} named by RTTI), '
          f'{sum(1 for v in tables if ctor_of.get(v))} with a constructor or destructor found, '
          f'{sum(1 for v in tables if bases.get(v))} with a base class')
    print(f'functions with a facts record: {len(facts)}; with a typed first argument: {len(this)} '
          f'({seeds} from vtables/constructors, {len(this) - seeds} by propagation)')
    acc = sum(len(x['fields']) for x in facts.values())
    acc_typed = sum(len(facts[f]['fields']) for f in this if f in facts)
    print(f'field accesses through the first argument: {acc} sites, {acc_typed} in typed functions '
          f'({100 * acc_typed // max(acc, 1)}%)')
    print(f'classes with fields: {with_fields}, distinct fields: {typed_fields}')
    big = sorted(tables, key=lambda v: -len(layouts.get(v, {})))[:8]
    for v in big:
        print(f'  {idents[v]}: {len(tables[v])} virtual functions, {len(layouts.get(v, {}))} fields, '
              f'{sum(1 for f, c in this.items() if c == v)} methods')


def layout(fields):
    """offset -> (member name, C type, size) for the fields that have one size and overlap nothing."""
    out = {}
    end = 0
    for off in sorted(fields):
        sizes, n_int, n_float = fields[off]
        if len(sizes) != 1:
            continue
        size = next(iter(sizes))
        if off < end:
            continue  # overlaps the previous field: left as a raw access
        if size == 1:
            t = 'uint8_t'
        elif n_float and not n_int:
            t = 'BigEndian<float>' if size == 4 else 'BigEndian<double>'
        else:
            t = {2: 'BigEndian<uint16_t>', 4: 'BigEndian<uint32_t>', 8: 'BigEndian<uint64_t>'}[size]
        out[off] = ('vtable' if off == 0 and size == 4 and t == 'BigEndian<uint32_t>' else f'm_{off:X}', t, size)
        end = off + size
    return out


def identifiers(tables, names):
    seen, out = set(), {}
    for v in sorted(tables):
        n = re.sub(r'[^A-Za-z0-9_]', '_', names[v])
        if n in seen:
            n = f'{n}_{v:08X}'
        seen.add(n)
        out[v] = n
    return out


def write_header(layouts, idents, tables, names, ctor_of):
    lines = ['// Classes recovered from the game (tools/lift/classes.py - do not edit). A struct lists the fields the',
             '// methods of its class access through `this`; f2::Be<T> is a big-endian value in game memory.',
             '// All classes together, for reference and for the test harness: the lifted files do not include this',
             '// file, each carries the structs it uses.',
             '#pragma once', '#include <cstddef>', '#include <cstdint>', '', '#pragma pack(push, 1)', '']
    def member(name, t, off):
        # a named field stays reachable under its offset name too: rewritten functions (tools/rewrite) were
        # written against the names of their day, and a name given later must not break them
        if name == 'vtable' or name == f'm_{off:X}':
            return f'\t{t} {name};'
        return f'\tunion {{ {t} {name}; {t} m_{off:X}; }};'
    for v in sorted(layouts):
        lay = layouts[v]
        if not lay:
            continue
        lines.append(f'// {names[v]}: vtable 0x{v:08X}, {len(tables[v])} virtual functions'
                     + (f', constructor/destructor {", ".join(sorted(ctor_of[v])[:3])}' if ctor_of.get(v) else ''))
        lines.append(f'struct {idents[v]} {{')
        pos = 0
        for off in sorted(lay):
            name, t, size = lay[off]
            if off > pos:
                lines.append(f'\tuint8_t pad_{pos:X}[0x{off - pos:X}];')
            lines.append(member(name, t, off))
            pos = off + size
        lines.append('};')
        last = max(lay)
        lines.append(f'static_assert(offsetof({idents[v]}, {lay[last][0]}) == 0x{last:X});')
        lines.append('')
    lines.append('#pragma pack(pop)')
    # the same definitions one by one: each lifted file carries the structs it uses (chunks.py), so renaming
    # a class or a field only changes the files of that class
    structs = {}
    for v in sorted(layouts):
        lay = layouts[v]
        if not lay:
            continue
        s = [f'// {names[v]}: vtable 0x{v:08X}, {len(tables[v])} virtual functions', f'struct {idents[v]} {{']
        pos = 0
        for off in sorted(lay):
            name, t, size = lay[off]
            if off > pos:
                s.append(f'\tuint8_t pad_{pos:X}[0x{off - pos:X}];')
            s.append(member(name, t, off))
            pos = off + size
        last = max(lay)
        s += ['};', f'static_assert(offsetof({idents[v]}, {lay[last][0]}) == 0x{last:X});']
        structs[idents[v]] = s
    with open(os.path.join(CACHE, 'structs.json'), 'w', encoding='utf-8') as f:
        json.dump(structs, f, separators=(',', ':'))
    path = os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'classes.h')
    text = '\n'.join(lines) + '\n'
    old = open(path, encoding='utf-8').read() if os.path.exists(path) else None
    if old != text:
        with open(path, 'w', encoding='utf-8', newline='\n') as f:
            f.write(text)


def pick(counter, ancestors, tables):
    """The class for a function reached with several `this` types: a common ancestor if there is one among
    the candidates, else the most frequent."""
    cs = list(counter)
    if len(cs) == 1:
        return cs[0]
    for c in sorted(cs, key=lambda v: (len(tables[v]), v)):
        if all(c == d or c in ancestors(d) for d in cs):
            return c
    return counter.most_common(1)[0][0]


if __name__ == '__main__':
    main()
