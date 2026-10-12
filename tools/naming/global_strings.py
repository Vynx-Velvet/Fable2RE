"""Names of the game's global string objects, from the start-up functions that create them.

    python tools/naming/global_strings.py            writes research/names/globals.tsv

The game keeps property and definition names ("DamageAmount", "StartTimeInSeconds") in global string objects.
Each one is built by its own small start-up function (research/catalog/scope.tsv: game-static): it constructs
the string object at a fixed address from a text constant and registers its destructor. This reads the address
and the text out of those functions, so code that uses the global can show its name.

globals.tsv: address, name (g_<Text>), text, basis. Keyed by address for the exact default.xex.
"""
import glob
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import readable  # noqa: E402
import scope  # noqa: E402

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


def main():
    found, seen_fn = {}, 0
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        for b in open(f, encoding='utf-8').read().split('// @lift ')[1:]:
            name = b.split('\n', 1)[0].strip()
            if not name.startswith('sub_') or scope.category(int(name[4:], 16)) != 'game-static':
                continue
            seen_fn += 1
            r = evaluate(b)
            if r is None:
                continue
            text = readable.game_string(r[1])
            if text:
                found[r[0]] = (text, name)
    used = {}
    rows = []
    for addr, (text, fn) in sorted(found.items()):
        ident = re.sub(r'[^A-Za-z0-9]+', '_', text).strip('_')[:60]
        if not ident:
            continue
        nm = 'g_' + ident
        if nm in used:  # (the same text in several globals: the address tells them apart)
            nm = f'{nm}_{addr:08X}'
        used[nm] = addr
        rows.append(f'{addr:08X}\t{nm}\t{text[:80]}\tBuilt at start-up by {fn} from this text.')
    out = os.path.join(ROOT, 'research', 'names', 'globals.tsv')
    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tname\ttext\tbasis\n' + '\n'.join(rows) + '\n')
    print(f'{seen_fn} start-up / shut-down functions read, {len(rows)} global strings -> {out}')


if __name__ == '__main__':
    main()
