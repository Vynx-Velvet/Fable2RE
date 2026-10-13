"""Names of the game's global string objects, from the start-up functions that create them.

    python tools/naming/global_strings.py [--out PATH] [--jobs N]
        -> research/decomp/global_names.tsv (local, like everything else under research/decomp)

The game keeps property and definition names in global string objects.
Each one is built by its own small start-up function (research/catalog/scope.tsv: game-static): it constructs
the string object at a fixed address from a text constant and registers its destructor. This lifts those
functions in memory (tools/lift/lift.py; nothing is written to Fable2Recomp/lifted), reads the address and the
text out of them, and names each global after its text, so code that uses it shows the name
(tools/lift/readable.py).

A name is the game's own text, so the file is not published: every setup writes it from the user's own copy
(tools/setup_all.ps1, step 'globals': the generated code, the shipped analysis, the image and the naming
dictionary, which names the string constructors). It must exist before the lift: the lifted text carries these
names, and the verification manifest's hashes were taken from text that carried them.

global_names.tsv: address, name (g_<Text>), text, basis. Keyed by address for the exact default.xex.
"""
import argparse
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
LIFT = os.path.join(ROOT, 'tools', 'lift')
sys.path.insert(0, LIFT)
import readable  # noqa: E402
import scope  # noqa: E402

OUT = os.path.join(ROOT, 'research', 'decomp', 'global_names.tsv')
_CONST = re.compile(r'constexpr int32_t (\w+) = int32_t\(0x([0-9A-F]{8})\);')
_COPY = re.compile(r'^\t+(\w+) = (\w+);$')
_ADD = re.compile(r'^\t+(\w+) = \((?:int64_t|int32_t)\)(?:\(uint64_t\))?(\w+) ([-+]) (\d+);$')
_CALL = re.compile(r'\b\w*ConstructFromCStr\w*\(ctx, base, (\w+), (\w+)')


def evaluate(block):
    """(global address, text address) of the string construction in one start-up function, or None."""
    val = {}
    for line in block.split('\n'):
        m = _CONST.search(line)
        if m:
            val[m.group(1)] = int(m.group(2), 16)
            continue
        m = _COPY.match(line)
        if m and m.group(2) in val:
            val[m.group(1)] = val[m.group(2)]
            continue
        m = _ADD.match(line)
        if m and m.group(2) in val:
            d = int(m.group(4))
            val[m.group(1)] = (val[m.group(2)] + (d if m.group(3) == '+' else -d)) & 0xFFFFFFFF
            continue
        m = _CALL.search(line)
        if m and m.group(1) in val and m.group(2) in val:
            return val[m.group(1)], val[m.group(2)]
    return None


def startup_functions():
    """{generated file index: {function names}} of the game-static functions (scope.tsv)."""
    import chunks
    with open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json'), encoding='utf-8') as f:
        db = json.load(f)
    by_file = {}
    for a in db:
        addr = int(a, 16)
        if scope.category(addr) == 'game-static':
            name = f'sub_{addr:08X}'
            idx = chunks.file_of(name)
            if idx is not None:
                by_file.setdefault(idx, set()).add(name)
    return by_file


def _job(item):
    """[(global address, text, function)] of the start-up functions of one generated file."""
    idx, names = item
    import lift
    path = [p for p in lift.generated_files() if p.endswith(f'.{idx}.cpp')][0]
    out = []
    for fn in lift.read_file(path, only=names):
        if fn.name not in names:
            continue
        try:
            text = '\n'.join(lift.lift_function(fn))
        except Exception:   # (a function the lifter cannot lift is no string construction it can read either)
            continue
        r = evaluate(text)
        if r is None:
            continue
        s = readable.game_string(r[1])
        if s:
            out.append((r[0], s, fn.name))
    return out


def rows(found):
    """The table rows for {global address: (text, function)}."""
    used, out = {}, []
    for addr, (text, fn) in sorted(found.items()):
        ident = re.sub(r'[^A-Za-z0-9]+', '_', text).strip('_')[:60]
        if not ident:
            continue
        nm = 'g_' + ident
        if nm in used:  # (the same text in several globals: the address tells them apart)
            nm = f'{nm}_{addr:08X}'
        used[nm] = addr
        out.append(f'{addr:08X}\t{nm}\t{text[:80]}\tBuilt at start-up by {fn} from this text.')
    return out


def main():
    ap = argparse.ArgumentParser(description="Names of the game's global string objects (local).")
    ap.add_argument('--out', default=OUT, help='the table to write (default: research/decomp/global_names.tsv)')
    ap.add_argument('--jobs', type=int, default=min(8, os.cpu_count() or 1))
    a = ap.parse_args()
    by_file = startup_functions()
    items = sorted((idx, names) for idx, names in by_file.items())
    if a.jobs > 1:
        import multiprocessing as mp
        with mp.Pool(a.jobs) as pool:
            results = pool.map(_job, items)
    else:
        results = [_job(i) for i in items]
    found = {}
    for res in results:   # (in function order: a global built twice keeps its last start-up function)
        for addr, text, fn in res:
            found[addr] = (text, fn)
    table = rows(found)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tname\ttext\tbasis\n' + '\n'.join(table) + '\n')
    n = sum(len(v) for v in by_file.values())
    print(f'{n} start-up / shut-down functions read, {len(table)} global strings -> {a.out}')


if __name__ == '__main__':
    main()
