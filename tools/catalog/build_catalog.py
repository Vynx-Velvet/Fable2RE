#!/usr/bin/env python3
"""Function catalog of Fable II + a readable copy of the Ghidra decompilation.

Builds, from what the project already knows:
  research/catalog/functions.tsv   one row per function: address, best name, name source, size,
                                   library (lionhead / havok / lua / gameface / kynapse / d3d / crt /
                                   xaudio / bink / zlib / xbox), Lua binding, callers, callees,
                                   strings it references, decompilation file:line, conversion status
  research/catalog/summary.md      counts per library, largest functions, top string users
  research/decomp/named/*.c        the Ghidra output with every guest address constant resolved:
                                   functions -> names, strings -> "literal", data -> g_ADDRESS, and
                                   calls renamed (the "readable reference" for C++ rewrites)

Names (highest priority first): research/symbols/*.md tables (hand-verified), Lua bindings
(Lua_<Table>_<Name>, research/symbols/lua_bindings_named.tsv), middleware class registrations,
research/catalog/names_manual.tsv (community names), else sub_ADDRESS.

Conversion status comes from research/catalog/converted.tsv (address, status, module) - filled as
functions get hand-written C++ replacements.

Usage: python tools/catalog/build_catalog.py
"""
import collections
import csv
import glob
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
DECOMP = os.path.join(ROOT, 'research', 'decomp')
CATALOG = os.path.join(ROOT, 'research', 'catalog')
SYMBOLS = os.path.join(ROOT, 'research', 'symbols')
BASE = 0x82000000
IMAGE_END = 0x83620000

# Library seeds: string patterns (regex on referenced string literals) and address ranges.
LIB_STRINGS = [
    ('havok', re.compile(r'^hk[A-Z]|Havok|\\hk[A-Za-z]+\.cpp|hkp[A-Z]|hka[A-Z]')),
    ('lua', re.compile(r"attempt to (call|index|compare|perform|concatenate)|C stack overflow|'%s' expected|"
                       r'bad argument #|stack overflow|LuaPlus|lhlua|luaL_|LuaDebugger|__gc$|__mode$|__newindex$')),
    ('gameface', re.compile(r'Anark|GameFace|gameface|fscommand|_level0|\bAK\.|BGF|\.bsg\b|\.bgf\b')),
    ('kynapse', re.compile(r'Kynapse|kynapse|Kaim|^CK[A-Z]|PathObject|AiMesh|Hierarchical')),
    ('bink', re.compile(r'Bink|bink')),
    ('zlib', re.compile(r'incorrect header check|invalid distance|invalid stored block|deflate |inflate ')),
    ('d3d', re.compile(r'D3D|Direct3D|XGRAPHICS')),
    ('xaudio', re.compile(r'XAudio|XAPO|XACT|xact')),
]
LIB_RANGES = [
    ('crt', 0x82CA0000, 0x82CC4000),     # C runtime (xstart, _lock, setjmp/longjmp, printf family)
    ('xaudio', 0x82CD0000, 0x82CE8000),  # XAudio2 + FX (reverb XAPO 0x82CDxxxx)
    ('havok', 0x82D70000, 0x83240000),   # refined below by the data; Havok sits high in .text
]


def load_tsv(path):
    if not os.path.exists(path):
        return []
    return list(csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'))


def c_escape(s, limit=80):
    s = s[:limit]
    return s.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n').replace('\r', '\\r').replace('\t', '\\t')


def main():
    os.makedirs(CATALOG, exist_ok=True)
    img = open(os.path.join(DECOMP, 'default_image.bin'), 'rb').read()
    index = load_tsv(os.path.join(DECOMP, 'c', 'index.tsv'))
    db = json.load(open(os.path.join(SYMBOLS, 'func_db.json')))

    # ---- names
    names, source = {}, {}
    for r in index:
        a = int(r['entry'], 16)
        names[a] = r['name']
        source[a] = 'ghidra' if not r['name'].startswith('sub_') else 'address'
    for r in load_tsv(os.path.join(SYMBOLS, 'lua_bindings.tsv')):
        a = int(r['function'], 16)
        if r['registered_by'].startswith('sub_83') or r['registered_by'].startswith('sub_82E5'):
            nm = 'Reg_' + r['name']  # middleware class registration (Kynapse / Havok VDB)
            if source.get(a) == 'address':
                names[a], source[a] = nm, 'registration'
    lua = {}
    for r in load_tsv(os.path.join(SYMBOLS, 'lua_bindings_named.tsv')):
        a = int(r['function'], 16)
        table = r['table'] or 'Lua'
        lua.setdefault(a, f"{table}.{r['name']}")
        if source.get(a) in ('address', 'registration'):
            names[a], source[a] = f"Lua_{table}_{r['name']}", 'lua'
    for r in load_tsv(os.path.join(CATALOG, 'names_manual.tsv')):
        a = int(r['address'], 16)
        names[a], source[a] = r['name'], 'manual'
    for f in sorted(glob.glob(os.path.join(SYMBOLS, '*.md'))):
        for line in open(f, encoding='utf-8'):
            m = re.match(r'\|\s*0x([0-9A-Fa-f]{8})\s*\|\s*([^|]+?)\s*\|', line)
            if m:
                a = int(m.group(1), 16)
                nm = re.sub(r'[^A-Za-z0-9_]', '_', m.group(2).split('(')[0].strip().replace('::', '__'))
                nm = re.sub(r'_+', '_', nm).strip('_')
                if a in names and nm and not nm[0].isdigit():
                    names[a], source[a] = nm, 'verified'
    # Unique names (Lua binding names repeat across tables / overloads).
    seen = collections.Counter()
    for a in sorted(names):
        n = names[a]
        seen[n] += 1
        if seen[n] > 1:
            names[a] = f'{n}_{a:08X}'

    # ---- strings in the image (for literal resolution)
    def cstr(a):
        o = a - BASE
        if not (0 <= o < len(img)):
            return None
        e = img.find(b'\0', o, o + 512)
        if e <= o:
            return None
        s = img[o:e]
        if len(s) >= 2 and all(32 <= c < 127 or c in (9, 10, 13) for c in s):
            return s.decode('ascii')
        return None

    # ---- decompilation: resolve constants, collect strings per function, write the named copy
    os.makedirs(os.path.join(DECOMP, 'named'), exist_ok=True)
    const_re = re.compile(r'0xffffffff(8[0-9a-f]{7})\b|\b0x(8[23][0-9a-f]{6})\b')
    call_re = re.compile(r'\b(?:sub|FUN)_([0-9A-Fa-f]{8})\b')
    func_strings = collections.defaultdict(list)
    file_of = {}
    for path in sorted(glob.glob(os.path.join(DECOMP, 'c', 'decomp_*.c'))):
        text = open(path, encoding='utf-8').read()
        out_lines, current = [], None
        for line in text.split('\n'):
            m = re.match(r'// ---- (\S+) @ ([0-9A-F]{8})', line)
            if m:
                current = int(m.group(2), 16)
                file_of[current] = (os.path.basename(path), len(out_lines) + 1)
                nm = names.get(current, m.group(1))
                extra = f'  [Lua {lua[current]}]' if current in lua else ''
                out_lines.append(f'// ---- {nm} @ {current:08X}{line[m.end():]}{extra}')
                continue

            def sub_const(mm):
                a = int(mm.group(1) or mm.group(2), 16)
                if a in names:
                    return names[a]
                s = cstr(a)
                if s is not None:
                    if current is not None and len(func_strings[current]) < 12:
                        func_strings[current].append(s)
                    return f'"{c_escape(s)}"'
                if BASE <= a < IMAGE_END:
                    return f'g_{a:08X}'
                return mm.group(0)

            line = const_re.sub(sub_const, line)
            line = call_re.sub(lambda mm: names.get(int(mm.group(1), 16), mm.group(0)), line)
            out_lines.append(line)
        open(os.path.join(DECOMP, 'named', os.path.basename(path)), 'w', encoding='utf-8', newline='\n').write(
            '\n'.join(out_lines))

    # ---- libraries
    lib = {}
    for a, ss in func_strings.items():
        for name, pat in LIB_STRINGS:
            if any(pat.search(s) for s in ss):
                lib[a] = name
                break
    for a in names:
        for name, lo, hi in LIB_RANGES[:2]:
            if lo <= a < hi and a not in lib:
                lib[a] = name
    for a, n in names.items():
        if n.startswith('imp_'):
            lib[a] = 'xbox'
        elif n.startswith('Reg_C') or n.startswith('Reg_k'):
            lib.setdefault(a, 'kynapse')
    callers = {int(k, 16): [int(x, 16) for x in v.get('callers', [])] for k, v in db.items()}
    callees = {int(k, 16): [int(x, 16) for x in v.get('calls', [])] for k, v in db.items()}
    for a, v in db.items():
        if v.get('imports'):
            if any(i.startswith(('NetDll_', 'Xam', 'XNet', 'Xe', 'Vd', 'Ke', 'Nt', 'Rtl', 'Ex', 'Ob', 'Io', 'Mm'))
                   for i in v['imports']) and int(a, 16) not in lib and len(v.get('calls', [])) <= 3:
                lib[int(a, 16)] = 'xbox'
    # Propagation: a function only called from one library's functions is that library's internal
    # helper (callees of library code are not enough: game code calls library code all the time).
    for _ in range(12):
        changed = 0
        for a in names:
            if a in lib:
                continue
            cs = callers.get(a, [])
            if not cs:
                continue
            libs = {lib.get(b) for b in cs}
            if len(libs) == 1 and None not in libs:
                lib[a] = libs.pop()
                changed += 1
        if not changed:
            break
    converted = {int(r['address'], 16): r for r in load_tsv(os.path.join(CATALOG, 'converted.tsv'))}

    # ---- write the catalog
    rows = []
    for r in index:
        a = int(r['entry'], 16)
        d = db.get(f'{a:08X}', {})
        rows.append({
            'address': f'{a:08X}', 'name': names.get(a, r['name']), 'name_source': source.get(a, ''),
            'size': d.get('ninsn', 0) * 4, 'library': lib.get(a, 'lionhead'), 'lua': lua.get(a, ''),
            'callers': len(d.get('callers', [])), 'callees': len(d.get('calls', [])),
            'decomp': '{}:{}'.format(*file_of[a]) if a in file_of else '',
            'status': converted[a]['status'] if a in converted else ('decompile-failed' if r['status'] != 'ok' else 'recompiled'),
        })
    cols = list(rows[0].keys())
    with open(os.path.join(CATALOG, 'functions.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('\t'.join(cols) + '\n')
        for r in rows:
            f.write('\t'.join(str(r[c]).replace('\t', ' ').replace('\n', ' ').replace('\r', ' ')
                               for c in cols) + '\n')

    # the strings each function references are text from the game: they go to the local research/decomp/, never
    # into the published catalog (tools/catalog/function_strings.py writes the same file without Ghidra)
    import importlib.util
    spec = importlib.util.spec_from_file_location('function_strings', os.path.join(os.path.dirname(__file__),
                                                                                 'function_strings.py'))
    fs = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(fs)
    fs.write_tsv(fs.DEFAULT_OUT, {f'{a:08X}': ss for a, ss in func_strings.items() if ss})

    by_lib = collections.Counter(r['library'] for r in rows)
    size_lib = collections.Counter()
    for r in rows:
        size_lib[r['library']] += r['size']
    by_src = collections.Counter(r['name_source'] for r in rows)
    with open(os.path.join(CATALOG, 'summary.md'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('# Function catalog summary\n\nGenerated by tools/catalog/build_catalog.py.\n\n')
        f.write('| Library | Functions | Code bytes |\n|---|---|---|\n')
        for k, v in by_lib.most_common():
            f.write(f'| {k} | {v} | {size_lib[k]:,} |\n')
        f.write('\n| Name source | Functions |\n|---|---|\n')
        for k, v in by_src.most_common():
            f.write(f'| {k or "-"} | {v} |\n')
        st = collections.Counter(r['status'] for r in rows)
        f.write('\n| Status | Functions |\n|---|---|\n')
        for k, v in st.most_common():
            f.write(f'| {k} | {v} |\n')
    print('libraries:', dict(by_lib.most_common()))
    print('name sources:', dict(by_src.most_common()))


if __name__ == '__main__':
    main()
