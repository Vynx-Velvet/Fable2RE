"""Work packets for rewriting lifted functions into clean C++ (for any model; this only writes prompt files).

    python tools/rewrite/make_packets.py [--limit 400] [--per-packet 12] [--class KEY] [--funcs names.txt]
        -> build/rewrite/packets/NNNN_<group>.md and build/rewrite/queue.txt

Each packet holds the functions of one class (or a run of neighbouring functions): for each, the exact lifted
code (the readable form in Fable2Recomp/lifted), Ghidra's decompilation of the same function as a second
opinion, and what is known about it. A model answers with one file per function,
build/rewrite/answers/<packet>/sub_X.cpp, and checks them with tools/rewrite/check.py (the differential tester
in relaxed mode). Packets contain lifted game code: local files (build/ is not committed).

Order: game code only (research/catalog/scope.tsv), classes with a name first, then the rest by address.
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'naming'))
import names as dictionary  # noqa: E402
import scope  # noqa: E402
import make_batches as mb  # noqa: E402

RULES = open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'RULES.md'), encoding='utf-8').read()
_GHIDRA = {}
_TYPES = None


def inferred_types():
    """cache/structs_inferred.json (tools/lift/structflow.py): variable -> struct id per function, and the
    structs' fields and class identities; plus how many functions use each struct."""
    global _TYPES
    if _TYPES is None:
        p = os.path.join(ROOT, 'tools', 'lift', 'cache', 'structs_inferred.json')
        _TYPES = {'vars': {}, 'structs': {}, 'users': {}}
        if os.path.exists(p):
            d = json.load(open(p, encoding='utf-8'))
            users = collections.Counter()
            for f, vs in d['vars'].items():
                for sid in set(vs.values()):
                    users[sid] += 1
            _TYPES = {'vars': d['vars'], 'structs': d['structs'], 'users': users}
    return _TYPES


_VARMAP = {}


def shown_names(name):
    """register variable -> name shown in the readable code, for one function (tools/lift/cache/varmap)."""
    import chunks
    idx = chunks.file_of(name)
    if idx is None:
        return {}
    if idx not in _VARMAP:
        p = os.path.join(ROOT, 'tools', 'lift', 'cache', 'varmap', f'{idx}.json')
        _VARMAP[idx] = json.load(open(p, encoding='utf-8')) if os.path.exists(p) else {}
    m = _VARMAP[idx].get(name[4:], {})
    return {reg: shown for shown, reg in m.items()}


def types_section(name, cname):
    """Text about the inferred types of a function's pointer variables, or ''."""
    t = inferred_types()
    vs = t['vars'].get(name)
    if not vs:
        return ''
    shown = shown_names(name)
    by_struct = collections.defaultdict(list)
    for v, sid in vs.items():
        if v in shown:   # (variables the readable code does not show, such as copies it folded, are left out)
            by_struct[sid].append(shown[v])
    lines = []
    for sid, vars_ in sorted(by_struct.items(), key=lambda kv: -t['users'][kv[0]]):
        st = t['structs'].get(str(sid), {})
        fields = st.get('fields', {})
        if not fields:
            continue
        cls = [cname.get(int(k, 16), k) for k in st.get('classes', [])]
        offs = sorted(fields.items(), key=lambda kv: int(kv[0]))
        shown = []
        for off, e in offs[:14]:
            sz = '/'.join(str(z) for z in e['sizes'])
            kind = 'float' if e.get('float') else ('ptr to T%s' % e['to'] if 'to' in e else 'int')
            shown.append(f'0x{int(off):X}:{sz}b {kind}')
        more = f', +{len(offs) - 14} more' if len(offs) > 14 else ''
        lines.append(f'- {", ".join(sorted(vars_))} -> T{sid}' + (f' = class {", ".join(cls)}' if cls else '')
                     + f' (used by {t["users"][sid]} functions): ' + ', '.join(shown) + more)
    if not lines:
        return ''
    return ('\n**Inferred types** (same T-number = same kind of object, here and in other functions; offsets '
            'are field offset:size):\n' + '\n'.join(lines) + '\n')


def ghidra(addr):
    """Ghidra's decompilation of the function at addr (research/decomp/named), or ''."""
    key = f'{addr:08X}'[:4]
    if key not in _GHIDRA:
        idx = {}
        p = os.path.join(ROOT, 'research', 'decomp', 'named', f'decomp_{key}.c')
        if os.path.exists(p):
            text = open(p, encoding='utf-8', errors='replace').read()
            parts = re.split(r'^// ---- (sub_[0-9A-F]{8}) @ ', text, flags=re.M)
            for i in range(1, len(parts) - 1, 2):
                body = parts[i + 1]
                body = body[body.find('\n') + 1:]
                idx[parts[i]] = body.strip('\n')
        _GHIDRA[key] = idx
    return _GHIDRA[key].get(f'sub_{addr:08X}', '')


def section(n, b, known, cl, cname, note=None):
    """The packet text for one function."""
    addr = int(n[4:], 16)
    head = [f'### {n}' + (f'  ({known[addr]})' if addr in known else '')]
    if note:
        head.append(note)
    k = cl['this'].get(n)
    if k:
        head.append(f'class of the first argument: {cname.get(int(k, 16), cl["classes"][k]["struct"])}')
    g = ghidra(addr)
    code = b.split('\n', 1)[1].rstrip('\n') if '\n' in b else b   # (without the marker's name line)
    return ('\n'.join(head) + '\n' + types_section(n, cname) + '\n**Lifted (exact):**\n```cpp\n' + code + '\n```\n'
            + ('\n**Ghidra (approximate, for reading only):**\n```c\n' + g[:6000] + '\n```\n' if g else ''))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--limit', type=int, default=400, help='functions in this round')
    ap.add_argument('--per-packet', type=int, default=12)
    ap.add_argument('--max-function', type=int, default=14000, help='skip lifted functions longer than this (chars)')
    ap.add_argument('--class', dest='cls', help='only the methods of this class (vtable key)')
    ap.add_argument('--funcs', help='file of function names, one per line')
    ap.add_argument('--out', default=os.path.join(ROOT, 'build', 'rewrite', 'packets'))
    ap.add_argument('--refresh', action='store_true',
                    help='rewrite the waiting packets with the current code and names (after a naming round)')
    ap.add_argument('--retry', action='store_true',
                    help='new packets for the functions whose rewrite was revoked, with the reason as a warning')
    a = ap.parse_args()
    blocks = mb.load_blocks()
    d = dictionary.load()
    known = dict(mb.catalog()[0])
    known.update(d['functions'])
    cl = json.load(open(os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json'), encoding='utf-8'))
    cname = {int(k, 16): n for k, n in d['classes'].items()} if isinstance(next(iter(d['classes']), None), str) \
        else dict(d['classes'])
    done = set()
    for p in glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*', 'results.txt')):
        for line in open(p, encoding='utf-8'):
            n, _, r = line.rstrip('\n').partition('\t')
            if r == 'OK':
                done.add(n)
    offered = set()
    for p in glob.glob(os.path.join(a.out, '*.md')):
        offered |= set(re.findall(r'^### (sub_[0-9A-F]{8})', open(p, encoding='utf-8').read(), re.M))
    if a.refresh:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import next_packet
        q = os.path.join(ROOT, 'build', 'rewrite', 'queue.txt')
        n = 0
        for tag in [l.strip() for l in open(q, encoding='utf-8') if l.strip()]:
            if next_packet.state(tag) != 'waiting':
                continue
            path = os.path.join(a.out, tag + '.md')
            if not os.path.exists(path):
                continue
            fns = re.findall(r'^### (sub_[0-9A-F]{8})', open(path, encoding='utf-8').read(), re.M)
            gname = tag.split('_', 1)[1] if '_' in tag else tag
            parts = [RULES, f'\n# Packet: {gname}\n']
            for fn in fns:
                if fn in blocks:
                    parts.append(section(fn, blocks[fn], known, cl, cname))
            with open(path, 'w', encoding='utf-8') as f:
                f.write('\n'.join(parts))
            n += 1
        print(f'{n} waiting packets refreshed')
        return
    notes = {}
    if a.retry:
        # the latest verdict of every function with a revoked answer; a function rewritten since is not retried
        verdict = {}
        for p in sorted(glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*', 'results.txt')),
                        key=os.path.getmtime):
            for line in open(p, encoding='utf-8'):
                n, _, r = line.rstrip('\n').partition('\t')
                if n.startswith('sub_') and r:
                    verdict[n] = r
        wanted = sorted(n for n, r in verdict.items() if r.startswith('REVOKED') and n in blocks
                        and not os.path.exists(os.path.join(ROOT, 'Fable2Recomp', 'rewritten', n + '.cpp')))
        for n in wanted:
            why = verdict[n][len('REVOKED:'):].strip()
            notes[n] = ('**Warning:** an earlier rewrite of this function was rejected by the checker: `' + why[:300] +
                        '`. Read the lifted code again line by line before writing; keep every load in a chain and '
                        'every call argument.')
        groups = [('retry', wanted)]
    elif a.funcs:
        wanted = [l.strip() for l in open(a.funcs) if l.strip()]
        groups = [('list', wanted)]
    else:
        by_class = collections.defaultdict(list)
        rest = []
        for n in blocks:
            if not n.startswith('sub_') or n in done or n in offered:
                continue
            addr = int(n[4:], 16)
            if not scope.in_game(addr) or len(blocks[n]) > a.max_function:
                continue
            k = cl['this'].get(n)
            if a.cls and k != a.cls.upper():
                continue
            if k:
                by_class[k].append(n)
            elif not a.cls:
                rest.append(n)
        named = [k for k in by_class if int(k, 16) in cname]
        order = sorted(named, key=lambda k: -len(by_class[k])) + sorted(set(by_class) - set(named), key=lambda k: -len(by_class[k]))
        groups = [(cname.get(int(k, 16), f'class_{k}'), sorted(by_class[k])) for k in order]
        groups.append(('misc', sorted(rest)))
    os.makedirs(a.out, exist_ok=True)
    existing = len(glob.glob(os.path.join(a.out, '*.md')))
    written = total = 0
    queue = []
    for gname, fns in groups:
        for i in range(0, len(fns), a.per_packet):
            if total >= a.limit:
                break
            chunk = fns[i:i + a.per_packet]
            parts = [RULES, f'\n# Packet: {gname}\n']
            for n in chunk:
                parts.append(section(n, blocks[n], known, cl, cname, notes.get(n)))
            total += len(chunk)
            written += 1
            tag = f'{existing + written:04}_{re.sub(r"[^A-Za-z0-9]+", "_", gname)[:40]}'
            with open(os.path.join(a.out, tag + '.md'), 'w', encoding='utf-8') as f:
                f.write('\n'.join(parts))
            queue.append(tag)
        if total >= a.limit:
            break
    if os.path.normpath(a.out) != os.path.normpath(os.path.join(ROOT, 'build', 'rewrite', 'packets')):
        print(f'{total} functions in {written} packets -> {a.out} (not queued: not the standard packet directory)')
        return
    with open(os.path.join(ROOT, 'build', 'rewrite', 'queue.txt'), 'a', encoding='utf-8') as f:
        f.write('\n'.join(queue) + ('\n' if queue else ''))
    print(f'{total} functions in {written} packets -> {a.out} (queue: build/rewrite/queue.txt)')


if __name__ == '__main__':
    main()
