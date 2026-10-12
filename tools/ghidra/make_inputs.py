#!/usr/bin/env python3
"""Prepare the inputs of the Ghidra project from the user's own copy of the game.

Writes into research/decomp/ (local only - everything there is derived from the game):
  default_image.bin   decrypted XEX image, loaded at 0x82000000 (tools/xex_decrypt.py)
  functions.tsv       address, end (exclusive, 0 = unknown), name - every function the recompiler
                      emitted (Fable2Recomp/generated/Fable2_init.cpp) with our names from
                      research/symbols/*.md where we have them
  strings.tsv         address, length - NUL-terminated ASCII strings (>= 5 chars) outside code

Usage: python tools/ghidra/make_inputs.py [--xex iso/extracted/default.xex]
Then:  tools/ghidra/run_ghidra.ps1   (imports, seeds functions/names/strings, exports decompiled C)
"""
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OUT = os.path.join(ROOT, 'research', 'decomp')
BASE = 0x82000000
CODE_BEGIN, CODE_END = 0x82170000, 0x832C2A3C  # .text of this XEX (pdata-verified)


def main(argv):
    xex = os.path.join(ROOT, 'iso', 'extracted', 'default.xex')
    if '--xex' in argv:
        xex = argv[argv.index('--xex') + 1]
    os.makedirs(OUT, exist_ok=True)
    image = os.path.join(OUT, 'default_image.bin')
    if not os.path.exists(image):
        subprocess.check_call([sys.executable, os.path.join(ROOT, 'tools', 'xex_decrypt.py'), xex, image])
    img = open(image, 'rb').read()

    # Functions the recompiler emitted, with sizes from the function database when available.
    init = open(os.path.join(ROOT, 'Fable2Recomp', 'generated', 'Fable2_init.cpp'), encoding='utf-8').read()
    funcs = {}
    for addr, name in re.findall(r'\{ 0x([0-9A-F]{8}), (\w+) \}', init):
        a = int(addr, 16)
        if a == 0:
            continue
        funcs.setdefault(a, name.replace('__imp__', 'imp_') if name.startswith('__imp__') else name)
    db_path = os.path.join(ROOT, 'research', 'symbols', 'func_db.json')
    ends = {}
    if os.path.exists(db_path):
        for k, v in json.load(open(db_path)).items():
            ends[int(k, 16)] = int(v['end'], 16)  # exclusive

    # Our names (research/symbols/*.md tables: | 0xADDR | Name | ...).
    named = 0
    sym_dir = os.path.join(ROOT, 'research', 'symbols')
    for f in sorted(os.listdir(sym_dir)):
        if not f.endswith('.md'):
            continue
        for line in open(os.path.join(sym_dir, f), encoding='utf-8'):
            m = re.match(r'\|\s*0x([0-9A-Fa-f]{8})\s*\|\s*([^|]+?)\s*\|', line)
            if not m:
                continue
            a = int(m.group(1), 16)
            name = re.sub(r'[^A-Za-z0-9_]', '_', m.group(2).split('(')[0].strip().replace('::', '__'))
            name = re.sub(r'_+', '_', name).strip('_')
            if a in funcs and name and not name[0].isdigit():
                funcs[a] = name
                named += 1

    with open(os.path.join(OUT, 'functions.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        for a in sorted(funcs):
            f.write(f'{a:08X}\t{ends.get(a, 0):08X}\t{funcs[a]}\n')

    # Strings outside the code range.
    n_str = 0
    with open(os.path.join(OUT, 'strings.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        for m in re.finditer(rb'[\x20-\x7e\t\r\n]{5,}\x00', img):
            a = BASE + m.start()
            if CODE_BEGIN <= a < CODE_END:
                continue
            f.write(f'{a:08X}\t{m.end() - m.start()}\n')
            n_str += 1
    print(f'{len(funcs)} functions ({named} named from research/symbols), {n_str} strings -> {OUT}')


if __name__ == '__main__':
    main(sys.argv[1:])
