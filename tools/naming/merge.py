"""Checks a model's naming answers and merges them into the dictionary (research/names/*.tsv).

    python tools/naming/merge.py [--answers build/naming/answers] [--dry-run]

Answer files hold tab-separated lines (tools/naming/make_batches.py, PROMPT):
    F  address  name  confidence  basis
    C  class id  name  confidence  basis
    M  class id  offset  name  confidence  basis
    L  function address  variable as shown  name  confidence  basis   (a local variable or parameter)
Rejected: malformed lines, invalid identifiers, unknown addresses / classes, names already used for something
else, and anything that would replace an existing entry of equal or higher confidence. Everything rejected is
listed in build/naming/rejected.txt with the reason.
"""
import argparse
import glob
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
NAMES = os.path.join(ROOT, 'research', 'names')
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]{2,79}\Z')
RESERVED = {'new', 'delete', 'class', 'this', 'operator', 'int', 'float', 'double', 'void', 'ctx', 'base', 'self',
            'main', 'vtable'}
RANK = {'low': 0, 'medium': 1, 'high': 2}


def read_table(name, key_cols):
    rows = {}
    path = os.path.join(NAMES, name)
    head = None
    if os.path.exists(path):
        with open(path, encoding='utf-8') as f:
            head = f.readline().rstrip('\n').split('\t')
            for line in f:
                c = line.rstrip('\n').split('\t')
                if len(c) >= len(head):
                    rows[tuple(c[:key_cols])] = c
    return head, rows


def write_table(name, head, rows):
    with open(os.path.join(NAMES, name), 'w', encoding='utf-8', newline='\n') as f:
        f.write('\t'.join(head) + '\n')
        for k in sorted(rows):
            f.write('\t'.join(rows[k]) + '\n')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--answers', default=os.path.join(ROOT, 'build', 'naming', 'answers'))
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    fh, funcs = read_table('functions.tsv', 1)
    ch, classes = read_table('classes.tsv', 1)
    mh, fields = read_table('fields.tsv', 2)
    fh = fh or ['address', 'name', 'confidence', 'basis']
    ch = ch or ['vtable', 'name', 'confidence', 'basis']
    mh = mh or ['vtable', 'offset', 'name', 'confidence', 'basis']
    lh, locs = read_table('locals.tsv', 2)
    lh = lh or ['function', 'variable', 'name', 'confidence', 'basis']
    varmap = {}  # function -> {shown name: register variable} (tools/lift/cache/varmap, written by lift.py)
    for vp in glob.glob(os.path.join(ROOT, 'tools', 'lift', 'cache', 'varmap', '*.json')):
        varmap.update(json.load(open(vp, encoding='utf-8')))
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    known_funcs = {a.upper() for a in db}
    cp = os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json')
    known_classes = set(json.load(open(cp, encoding='utf-8'))['classes']) if os.path.exists(cp) else set()
    used_f = {r[1]: k[0] for k, r in funcs.items()}
    used_c = {r[1]: k[0] for k, r in classes.items()}
    added = {'F': 0, 'C': 0, 'M': 0, 'L': 0}
    rejected = []

    def ok_ident(n):
        return bool(IDENT.match(n)) and n not in RESERVED and not n.startswith(('sub_', 'n_sub_', '__', 'f2', 'F2_'))
    for path in sorted(glob.glob(os.path.join(a.answers, '*.tsv'))):
        for ln, line in enumerate(open(path, encoding='utf-8', errors='replace'), 1):
            line = line.rstrip('\r\n')
            if not line.strip() or line.startswith(('#', '```')):
                continue
            c = [x.strip() for x in line.split('\t')]
            where = f'{os.path.basename(path)}:{ln}'

            def reject(why):
                rejected.append(f'{where}: {why}: {line[:160]}')
            kind = c[0]
            want = {'F': 5, 'C': 5, 'M': 6, 'L': 6}.get(kind)
            if want is None or len(c) != want:
                reject('malformed line')
                continue
            conf = c[-2].lower()
            if conf not in RANK:
                reject('confidence must be high / medium / low')
                continue
            if not c[-1] or any(ch_ in c[-1] for ch_ in '{}') or len(c[-1]) > 300:
                reject('basis must be one plain sentence')
                continue
            if kind == 'F':
                addr, name = c[1].upper().removeprefix('SUB_').removeprefix('0X'), c[2]
                if addr not in known_funcs:
                    reject('unknown function address')
                elif not ok_ident(name):
                    reject('invalid identifier')
                elif used_f.get(name, addr) != addr and used_f.get(f'{name}_{addr}', addr) != addr:
                    reject(f'name already used for {used_f[name]}')
                elif used_f.get(name, addr) != addr and (addr,) in funcs:
                    reject(f'name already used for {used_f[name]}')
                elif used_f.get(name, addr) != addr:
                    # another copy of a function that already has this name (the compiler duplicates small helpers):
                    # same name with the address appended
                    name = f'{name}_{addr}'
                    funcs[(addr,)] = [addr, name, conf, c[4]]
                    used_f[name] = addr
                    added['F'] += 1
                elif (addr,) in funcs and RANK[funcs[(addr,)][2]] >= RANK[conf]:
                    reject('already named with equal or higher confidence')
                else:
                    if (addr,) in funcs:
                        used_f.pop(funcs[(addr,)][1], None)
                    funcs[(addr,)] = [addr, name, conf, c[4]]
                    used_f[name] = addr
                    added['F'] += 1
            elif kind == 'C':
                key, name = c[1].upper(), c[2]
                if key not in known_classes:
                    reject('unknown class id')
                elif not ok_ident(name):
                    reject('invalid identifier')
                elif used_c.get(name, key) != key:
                    reject(f'class name already used for {used_c[name]}')
                elif (key,) in classes and RANK[classes[(key,)][2]] >= RANK[conf]:
                    reject('already named with equal or higher confidence')
                else:
                    classes[(key,)] = [key, name, conf, c[4]]
                    used_c[name] = key
                    added['C'] += 1
            elif kind == 'L':
                fa, shown, name = c[1].upper().removeprefix('SUB_').removeprefix('0X'), c[2], c[3]
                vm = varmap.get(fa, {})
                var = vm.get(shown) or vm.get(shown + 'Reg') or (shown if shown in vm.values() else None)
                if var is None:
                    reject('unknown function or variable (not in tools/lift/cache/varmap)')
                elif not ok_ident(name) or not name[0].islower() or name.startswith(('g_', 'str_', 'm_')):
                    reject('invalid local name (lowerCamelCase identifier)')
                elif any(k[0] == fa and r[2] == name and k[1] != var for k, r in locs.items()) or                         (name in vm and vm[name] != var):
                    reject('name already used for another variable of this function')
                elif (fa, var) in locs and RANK[locs[(fa, var)][3]] >= RANK[conf]:
                    reject('already named with equal or higher confidence')
                else:
                    locs[(fa, var)] = [fa, var, name, conf, c[5]]
                    added['L'] += 1
            else:
                key, off, name = c[1].upper(), c[2].upper().removeprefix('0X'), c[3]
                if key not in known_classes or not re.fullmatch(r'[0-9A-F]{1,5}', off):
                    reject('unknown class id or bad offset')
                elif not ok_ident(name):
                    reject('invalid identifier')
                elif any(k[0] == key and r[2] == name and k[1] != off for k, r in fields.items()):
                    reject('field name already used in this class')
                elif (key, off) in fields and RANK[fields[(key, off)][3]] >= RANK[conf]:
                    reject('already named with equal or higher confidence')
                else:
                    fields[(key, off)] = [key, off, name, conf, c[5]]
                    added['M'] += 1
    os.makedirs(os.path.join(ROOT, 'build', 'naming'), exist_ok=True)
    with open(os.path.join(ROOT, 'build', 'naming', 'rejected.txt'), 'w', encoding='utf-8') as f:
        f.write('\n'.join(rejected) + '\n')
    if not a.dry_run:
        write_table('functions.tsv', fh, funcs)
        write_table('classes.tsv', ch, classes)
        write_table('fields.tsv', mh, fields)
        if locs:
            write_table('locals.tsv', lh, locs)
    print(f'added {added["F"]} functions, {added["C"]} classes, {added["M"]} fields, {added["L"]} locals; rejected {len(rejected)} lines '
          f'(build/naming/rejected.txt); dictionary now {len(funcs)} functions, {len(classes)} classes, '
          f'{len(fields)} fields, {len(locs)} locals' + (' [dry run: nothing written]' if a.dry_run else ''))


if __name__ == '__main__':
    main()
