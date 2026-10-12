#!/usr/bin/env python3
"""Start a hand-written C++ rewrite of one or more game functions.

Creates Fable2Recomp/src/game/<subsystem>/<file>.cpp (or appends to it) with, per function:
  - what the catalog knows (address, name, Lua binding, callers/callees, strings),
  - a reminder to consult locally generated references without copying them into source,
  - a replacement stub that still calls the original recompiled code, ready to be rewritten:
        REX_HOOK_RAW(sub_XXXXXXXX) { ... __imp__sub_XXXXXXXX(ctx, base); }
and records the functions in research/catalog/converted.tsv with status "draft".

Statuses (edit converted.tsv): draft -> rewritten (no call to the original left) -> verified
(checked in game, e.g. with f2::VerifyCall or a play test).

Usage:
  python tools/convert/new_module.py <subsystem> <file> <address> [<address> ...]
  e.g. python tools/convert/new_module.py debug debug_draw 823A5918 823A5928
The new .cpp is picked up by CMake automatically (src/game/**/*.cpp).
"""
import csv
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CATALOG = os.path.join(ROOT, 'research', 'catalog')
GAME_SRC = os.path.join(ROOT, 'Fable2Recomp', 'src', 'game')
csv.field_size_limit(10 ** 8)


def catalog():
    rows = csv.DictReader(open(os.path.join(CATALOG, 'functions.tsv'), encoding='utf-8'), delimiter='\t',
                          quoting=csv.QUOTE_NONE)
    return {r['address']: r for r in rows if r.get('address')}


def main(argv):
    if len(argv) < 3:
        print(__doc__)
        return 1
    subsystem, fname, addrs = argv[0], argv[1], [a.upper().replace('0X', '') for a in argv[2:]]
    cat = catalog()
    out_dir = os.path.join(GAME_SRC, subsystem)
    os.makedirs(out_dir, exist_ok=True)
    path = os.path.join(out_dir, fname + '.cpp')
    new_file = not os.path.exists(path)
    parts = []
    if new_file:
        parts.append(f'''// Hand-written C++ for Fable II ({subsystem}): readable replacements of recompiled game functions.
// Each function below replaces the recompiled one (sub_ADDRESS) for every caller; __imp__sub_ADDRESS is
// the original recompiled code. Reference decompilations come from research/decomp/named (generated
// locally from your own copy of the game). See docs/conversion-guide.md.
#include <fable2/sdk.h>

#include "generated/Fable2_init.h"

#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/ppc.h>
''')
    existing = open(path, encoding='utf-8').read() if not new_file else ''
    conv_path = os.path.join(CATALOG, 'converted.tsv')
    conv = {}
    if os.path.exists(conv_path):
        for r in csv.DictReader(open(conv_path, encoding='utf-8'), delimiter='\t'):
            conv[r['address']] = r
    for a in addrs:
        row = cat.get(a)
        if not row:
            print(f'{a}: not in the catalog')
            continue
        if f'sub_{a})' in existing:
            print(f'{a}: already in {path}')
            continue
        # Reference material stays in ignored research/decomp, never in source scaffolds.
        ref = '// Inspect the reference locally under research/decomp/named; do not paste it here.'
        lua = f"\n// Lua binding: {row['lua']}" if row.get('lua') else ''
        parts.append(f'''
// ============================================================================================
// {row['name']}  (guest 0x{a}, {row['size']} bytes, {row['callers']} callers, {row['callees']} callees){lua}
// Local reference:
{ref}
REX_HOOK_RAW(sub_{a}) {{
  // TODO: rewrite as readable C++ (arguments: ctx.r3.., result: ctx.r3 / ctx.f1). Until then the
  // original recompiled code runs:
  __imp__sub_{a}(ctx, base);
}}
''')
        conv[a] = {'address': a, 'name': row['name'], 'status': 'draft',
                   'module': os.path.relpath(path, ROOT).replace(os.sep, '/')}
        print(f'{a} {row["name"]} -> {path}')
    with open(path, 'a' if not new_file else 'w', encoding='utf-8', newline='\n') as f:
        f.write(''.join(parts))
    with open(conv_path, 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tname\tstatus\tmodule\n')
        for a in sorted(conv):
            r = conv[a]
            f.write(f"{a}\t{r['name']}\t{r['status']}\t{r['module']}\n")
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
