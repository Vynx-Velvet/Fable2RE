#!/usr/bin/env python3
"""String literals each function references, from the user's own copy of the game (local, never committed).

    python tools/catalog/function_strings.py [--image research/decomp/default_image.bin] [--out FILE]

The published catalog (research/catalog/functions.tsv) carries no text from the game. This tool recovers, for
each function, the C strings its constants point at: research/symbols/func_db.json lists the constants of every
function, and the decrypted image (tools/xex_decrypt.py; tools/setup_all.ps1's image step writes it) holds the
strings. The result, research/decomp/function_strings.tsv (address, strings: up to 4, each cut to 40
characters, joined by " | "), stays local like everything under research/decomp/. The naming batches
(tools/naming/make_batches.py) show it as context.

When a Ghidra export exists, tools/catalog/build_catalog.py writes the same file from the decompiled code
instead (it also finds strings reached through computed addresses).
"""
import argparse
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
DEFAULT_IMAGE = os.path.join(ROOT, 'research', 'decomp', 'default_image.bin')
DEFAULT_OUT = os.path.join(ROOT, 'research', 'decomp', 'function_strings.tsv')
FUNC_DB = os.path.join(ROOT, 'research', 'symbols', 'func_db.json')
BASE = 0x82000000


def c_string(image, address, longest=256):
    """The printable NUL-terminated ASCII string at a guest address (at least 2 characters), or None."""
    o = address - BASE
    if not 0 <= o < len(image):
        return None
    end = image.find(b'\0', o, o + longest)
    if end - o < 2:
        return None
    b = image[o:end]
    if all(32 <= c < 127 or c in (9, 10, 13) for c in b):
        return b.decode('ascii')
    return None


def function_strings(image, db):
    """{address 'XXXXXXXX': [string, ...]} in the order of each function's constants."""
    out = {}
    for a, v in db.items():
        found = []
        for c in v.get('consts', []):
            try:
                s = c_string(image, int(c, 16))
            except ValueError:
                continue
            if s and s not in found:
                found.append(s)
        if found:
            out[a] = found
    return out


def write_tsv(path, strings):
    """address<TAB>strings rows, the format build_catalog.py writes too."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + '.new'
    with open(tmp, 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tstrings\n')
        for a in sorted(strings):
            text = ' | '.join(s[:40] for s in strings[a][:4])
            f.write(f'{a}\t' + text.replace('\t', ' ').replace('\n', ' ').replace('\r', ' ') + '\n')
    os.replace(tmp, path)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    ap.add_argument('--image', default=DEFAULT_IMAGE, help='decrypted image (tools/xex_decrypt.py)')
    ap.add_argument('--out', default=DEFAULT_OUT)
    a = ap.parse_args(argv)
    if not os.path.exists(a.image):
        sys.exit(f'function_strings: {a.image} not found: run tools/setup_all.ps1 (image step) or '
                 'python tools/xex_decrypt.py <default.xex> research/decomp/default_image.bin')
    with open(a.image, 'rb') as f:
        image = f.read()
    with open(FUNC_DB, encoding='utf-8') as f:
        db = json.load(f)
    strings = function_strings(image, db)
    write_tsv(a.out, strings)
    print(f'function_strings: {len(strings)} functions with strings -> {a.out}')


if __name__ == '__main__':
    main()
