"""Layout of the lifted output: Fable2Recomp/lifted/lifted.<file>.<chunk>.cpp, CHUNK functions per file.

A function's chunk depends only on its position in its generated file (generated/Fable2_recomp.<file>.cpp),
never on which other functions are lifted, so re-lifting some functions rewrites only their chunks and
the build recompiles only those (files whose text did not change keep their timestamps).

Each function is one block in its chunk:
    // @lift sub_XXXXXXXX
    // (description)
    F2_LIFTED(sub_XXXXXXXX, 0x...) { ... }
"""
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
OUT_DIR = os.path.join(ROOT, 'Fable2Recomp', 'lifted')
GENERATED = os.path.join(ROOT, 'Fable2Recomp', 'generated')
CHUNK = 64
MARK = '// @lift '

_order_cache = {}


def functions_in_file(idx):
    """Names of the functions of generated file idx, in file order (fast text scan, cached)."""
    if idx not in _order_cache:
        names = []
        with open(os.path.join(GENERATED, f'Fable2_recomp.{idx}.cpp'), encoding='utf-8', errors='replace') as f:
            for line in f:
                if line.startswith('DEFINE_REX_FUNC('):
                    m = re.match(r'DEFINE_REX_FUNC\(([A-Za-z_][A-Za-z0-9_]*)\)', line)
                    if m:
                        names.append(m.group(1))
        _order_cache[idx] = names
    return _order_cache[idx]


_file_of = None


def file_of(name):
    """generated file index of a function name (index built once from all generated files)."""
    global _file_of
    if _file_of is None:
        _file_of = {}
        for fname in os.listdir(GENERATED):
            m = re.fullmatch(r'Fable2_recomp\.(\d+)\.cpp', fname)
            if m:
                for n in functions_in_file(int(m.group(1))):
                    _file_of[n] = int(m.group(1))
    return _file_of.get(name)


def chunk_of(idx, name):
    return functions_in_file(idx).index(name) // CHUNK


def chunk_path(idx, k):
    return os.path.join(OUT_DIR, f'lifted.{idx}.{k}.cpp')


_PROTOS = None
_CALL = re.compile(r'\b([A-Za-z_]\w*)\(ctx, base')


def prototypes_for(blocks):
    """Prototypes of the native functions the blocks call (a lifted file declares what it uses, so naming a
    function only changes the files that mention it)."""
    global _PROTOS
    if _PROTOS is None:
        import native_gen
        _PROTOS = native_gen.prototypes()
    used = set()
    for lines in blocks.values():
        for line in lines:
            for m in _CALL.finditer(line):
                if m.group(1) in _PROTOS:
                    used.add(m.group(1))
    return [_PROTOS[n] for n in sorted(used)]


_STRUCTS = None
_OBJ = re.compile(r'F2_OBJ\((\w+),|GameObject<(\w+)>')   # (plain form / readable form)


def structs_for(blocks):
    """Definitions of the classes the blocks use (F2_OBJ(Class, ...)), from tools/lift/cache/structs.json."""
    global _STRUCTS
    if _STRUCTS is None:
        import json
        p = os.path.join(HERE, 'cache', 'structs.json')
        _STRUCTS = json.load(open(p, encoding='utf-8')) if os.path.exists(p) else {}
    used = set()
    for lines in blocks.values():
        for line in lines:
            for m in _OBJ.finditer(line):   # (several classes in one line: accesses through typed variables)
                if (m.group(1) or m.group(2)) in _STRUCTS:
                    used.add(m.group(1) or m.group(2))
    if not used:
        return []
    out = ['#pragma pack(push, 1)']
    for n in sorted(used):
        out.extend(_STRUCTS[n])
    out.append('#pragma pack(pop)')
    return out


REWRITTEN_DIR = os.path.join(OUT_DIR, '..', 'rewritten')   # Fable2Recomp/rewritten/sub_X.cpp (local, game-derived)


_CANON_RE = re.compile(r'\b(?:n_sub_|C_)([0-9A-F]{8})\b')


def canonical_names(text):
    """Dictionary names of functions and classes in `text` replaced by their address forms (n_sub_X, C_key):
    the form rewrites are stored in, so a name given later does not break them."""
    import json
    import names
    d = names.load()
    subs = {n: f'n_sub_{a:08X}' for a, n in d['functions'].items()}
    p = os.path.join(HERE, 'cache', 'classes.json')
    if os.path.exists(p):
        for key, c in json.load(open(p, encoding='utf-8'))['classes'].items():
            if not c['struct'].startswith('C_'):
                subs[c['struct']] = f'C_{key}'
    return re.sub(r'\b[A-Za-z_]\w*\b', lambda m: subs.get(m.group(0), m.group(0)), text)


_structs_cache = (None, None)


def _class_structs():
    """class key -> struct identifier from cache/classes.json (read again only when the file changed)."""
    global _structs_cache
    import json
    p = os.path.join(HERE, 'cache', 'classes.json')
    if not os.path.exists(p):
        return {}
    stamp = os.path.getmtime(p)
    if _structs_cache[0] != stamp:
        _structs_cache = (stamp, {key: c['struct'] for key, c in
                                  json.load(open(p, encoding='utf-8'))['classes'].items()})
    return _structs_cache[1]


def current_names(text):
    """The reverse: address forms replaced by the names in effect now."""
    import names
    structs = _class_structs()

    def sub(m):
        tok = m.group(0)
        if tok.startswith('n_sub_'):
            return names.native_name('sub_' + m.group(1))
        return structs.get(m.group(1), tok)
    return _CANON_RE.sub(sub, text)


PROMOTED_DIR = os.path.join(OUT_DIR, '..', 'src', 'game', 'promoted')   # reviewed source modules (published)
_PROMOTED_RE = re.compile(r'^PROMOTED_ENTRY\((\d+), (sub_[0-9A-F]{8}), 0x[0-9A-F]{8}\)', re.M)
_promoted = None


def promoted_modules():
    """{function: module path} of the functions defined in source modules (tools/rewrite/promote.py)."""
    global _promoted
    if _promoted is None:
        _promoted = {}
        if os.path.isdir(PROMOTED_DIR):
            for f in sorted(os.listdir(PROMOTED_DIR)):
                if f.endswith('.cpp'):
                    p = os.path.join(PROMOTED_DIR, f)
                    with open(p, encoding='utf-8') as fh:
                        for m in _PROMOTED_RE.finditer(fh.read()):
                            _promoted[m.group(2)] = p
    return _promoted


def promoted(name):
    """Whether the function lives in a source module: the lifted files leave it out (the module defines it)."""
    return name in promoted_modules()


def rewritten(name):
    """The lines of a rewritten function's block (without the marker), with the names in effect now, or None."""
    if promoted(name):
        return None
    p = os.path.join(REWRITTEN_DIR, name + '.cpp')
    if not os.path.exists(p):
        return None
    with open(p, encoding='utf-8') as f:
        text = current_names(f.read().rstrip('\n'))
    return [l.rstrip('\r') for l in text.split('\n') if not l.startswith(MARK)]


def rewrite_all():
    """Writes every chunk file again from its own blocks (after the declarations a file carries changed);
    returns the number of files whose text changed."""
    n = 0
    for f in sorted(os.listdir(OUT_DIR)):
        m = re.fullmatch(r'lifted\.(\d+)\.(\d+)\.cpp', f)
        if m:
            idx, k = int(m.group(1)), int(m.group(2))
            if write_chunk(idx, k, read_blocks(os.path.join(OUT_DIR, f))):
                n += 1
    return n


def header(idx, k):
    return [f'// Lifted from generated/Fable2_recomp.{idx}.cpp (chunk {k}) by tools/lift/lift.py - do not edit;',
            '// regenerate instead. Local, game-derived output: not for distribution.',
            f'#define LIFTED_FILE_INDEX {idx}', '#include "lifted/lifted.h"', '']


def read_blocks(path):
    """name -> block text (lines) of a chunk file."""
    blocks = {}
    if not os.path.exists(path):
        return blocks
    cur = None
    with open(path, encoding='utf-8') as f:
        for line in f.read().split('\n'):
            if line.startswith(MARK):
                cur = line[len(MARK):].strip()
                blocks[cur] = [line]
            elif cur is not None:
                blocks[cur].append(line)
    for n in blocks:
        while blocks[n] and blocks[n][-1] == '':
            blocks[n].pop()
    return blocks


def write_chunk(idx, k, blocks):
    """Writes chunk k of file idx from {name: lines} (ordered as in the generated file); only if changed.
    An empty chunk removes the file."""
    path = chunk_path(idx, k)
    order = functions_in_file(idx)
    # a function promoted into a source module is defined there, not here
    for n in [n for n in blocks if promoted(n)]:
        del blocks[n]
    names = sorted(blocks, key=order.index)
    if not names:
        if os.path.exists(path):
            os.remove(path)
        return True
    # a function rewritten by hand or by a model (tools/rewrite/apply.py) keeps its rewritten text, whatever
    # the lifter produced for it
    for n in names:
        rw = rewritten(n)
        if rw is not None:
            blocks[n] = [MARK + n] + rw
    lines = header(idx, k)
    structs = structs_for(blocks)
    if structs:
        lines.extend(structs)
        lines.append('')
    protos = prototypes_for(blocks)
    # the recompiled original of each readable function (UseLiftedCode(...) switches back to it)
    for n in names:
        if any(f'{n}_original(ctx, base)' in line for line in blocks[n]):
            protos.append(f'inline void {n}_original(CpuState& ctx, uint8_t* base) {{ __imp__{n}(ctx, base); }}')
    if protos:
        lines.extend(protos)
        lines.append('')
    for n in names:
        lines.extend(blocks[n])
        lines.append('')
    text = '\n'.join(lines) + '\n'
    old = None
    if os.path.exists(path):
        with open(path, encoding='utf-8', newline='') as f:
            old = f.read()
    if old == text:
        return False
    os.makedirs(OUT_DIR, exist_ok=True)
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write(text)
    return True


def update(idx, new_blocks, remove=(), replace_all=False):
    """Puts new function blocks ({name: lines}) into their chunks of file idx and drops `remove`.
    replace_all: the chunks of this file hold exactly new_blocks afterwards (a whole-file lift).
    Returns the number of chunk files rewritten."""
    by_chunk = {}
    for n in list(new_blocks) + list(remove):
        by_chunk.setdefault(chunk_of(idx, n), set()).add(n)
    if replace_all:
        nchunks = (len(functions_in_file(idx)) + CHUNK - 1) // CHUNK
        for k in range(nchunks):
            by_chunk.setdefault(k, set())
    written = 0
    for k, names in by_chunk.items():
        blocks = {} if replace_all else read_blocks(chunk_path(idx, k))
        for n in names:
            if n in new_blocks:
                blocks[n] = new_blocks[n]
            else:
                blocks.pop(n, None)
        if write_chunk(idx, k, blocks):
            written += 1
    return written


def split_monolithic(idx):
    """One-time conversion of an old lifted.<idx>.cpp into chunks (no re-lifting)."""
    old = os.path.join(OUT_DIR, f'lifted.{idx}.cpp')
    if not os.path.exists(old):
        return 0
    text = open(old, encoding='utf-8').read().split('\n')
    blocks, cur, pending = {}, None, []
    for line in text:
        m = re.match(r'(?:F2_LIFTED|CPU_STATE_ENTRY)\((\w+), 0x[0-9A-F]+\) \{$', line)
        if m:
            cur = m.group(1)
            blocks[cur] = [MARK + cur] + pending + [line]
            pending = []
            continue
        if cur is None:
            if line.startswith('// sub_') or line.startswith('// xstart'):
                pending = [line]
            continue
        blocks[cur].append(line)
        if line == '}':
            cur = None
    update(idx, blocks, replace_all=True)
    os.remove(old)
    return len(blocks)
