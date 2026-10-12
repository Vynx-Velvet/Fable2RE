"""Applies changes of the naming dictionary (research/names) to the lifted code, touching only what they affect.

    python tools/lift/apply_names.py            re-lift the affected functions (then: update.ps1 -Build)
    python tools/lift/apply_names.py --dry-run  only say what would be re-lifted
    python tools/lift/apply_names.py --init     record the dictionary as applied (after a whole-game lift)

What a change affects:
  * a function got / changed its name: that function and every lifted function that calls it
  * a class or one of its fields got / changed its name: the functions whose first argument is that class
  * a local variable got / changed its name (locals.tsv): that function only
The names in effect at the last application are kept in tools/lift/cache/applied_names.json.
Afterwards `tools/lift/update.ps1 -Build` tests the re-lifted functions and compiles only their files.
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import names as dictionary  # noqa: E402

APPLIED = os.path.join(HERE, 'cache', 'applied_names.json')
LIFTED = os.path.join(ROOT, 'Fable2Recomp', 'lifted')


def current():
    d = dictionary.load()
    locs = {}
    lp = os.path.join(ROOT, 'research', 'names', 'locals.tsv')
    if os.path.exists(lp):
        with open(lp, encoding='utf-8') as f:
            head = f.readline().rstrip('\n').split('\t')
            for line in f:
                c = dict(zip(head, line.rstrip('\n').split('\t')))
                if c.get('function') and c.get('variable') and c.get('name'):
                    locs[f"{c['function'].upper()}:{c['variable']}"] = c['name']
    return {'locals': locs,
            'functions': {f'{a:08X}': n for a, n in d['functions'].items()},
            'classes': {f'{v:08X}': n for v, n in d['classes'].items()},
            'fields': {f'{v:08X}:{o:X}': n for (v, o), n in d['fields'].items()}}


def _lock():
    """Only one apply at a time: two at once rewrite the same lifted files and leave callers and definitions
    with different names (2026-10-04: 752 functions had to be re-lifted after that)."""
    path = os.path.join(HERE, 'cache', 'apply_names.lock')
    try:
        fd = os.open(path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
    except FileExistsError:
        sys.exit(f'another apply_names.py is running (or crashed: delete {path})')
    os.write(fd, str(os.getpid()).encode())
    os.close(fd)
    import atexit
    atexit.register(lambda: os.path.exists(path) and os.remove(path))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--init', action='store_true')
    a = ap.parse_args()
    if not a.dry_run:
        _lock()
    problems = dictionary.load()['problems']
    if problems:
        sys.exit('dictionary problems:\n' + '\n'.join(problems))
    now = current()
    if a.init:
        with open(APPLIED, 'w', encoding='utf-8') as f:
            json.dump(now, f, indent=0, sort_keys=True)
        print(f'recorded {len(now["functions"])} function, {len(now["classes"])} class and {len(now["fields"])} '
              f'field names as applied')
        return
    old = json.load(open(APPLIED, encoding='utf-8')) if os.path.exists(APPLIED) else \
        {'functions': {}, 'classes': {}, 'fields': {}}
    old.setdefault('locals', {})
    local_fns = {k.split(':')[0] for k in set(now['locals']) | set(old['locals'])
                 if now['locals'].get(k) != old['locals'].get(k)}
    funcs = {k for k in set(now['functions']) | set(old['functions'])
             if now['functions'].get(k) != old['functions'].get(k)}
    classes = {k for k in set(now['classes']) | set(old['classes']) if now['classes'].get(k) != old['classes'].get(k)}
    classes |= {k.split(':')[0] for k in set(now['fields']) | set(old['fields'])
                if now['fields'].get(k) != old['fields'].get(k)}
    if not funcs and not classes and not local_fns:
        print('the dictionary is already applied')
        return
    affected = {f'sub_{k}' for k in funcs | local_fns}
    if funcs:
        # callers: lifted functions whose text calls the name in effect so far
        tokens = {(old['functions'].get(k) or f'n_sub_{k}') for k in funcs}
        pattern = re.compile(r'\b(' + '|'.join(re.escape(t) for t in sorted(tokens)) + r')\(ctx, base')
        for path in glob.glob(os.path.join(LIFTED, 'lifted.*.*.cpp')):
            text = open(path, encoding='utf-8').read()
            if not pattern.search(text):
                continue
            for block in text.split('// @lift ')[1:]:
                if pattern.search(block):
                    affected.add(block.split('\n', 1)[0].strip())
    if classes:
        cp = os.path.join(HERE, 'cache', 'classes.json')
        this = json.load(open(cp, encoding='utf-8'))['this'] if os.path.exists(cp) else {}
        affected |= {f for f, c in this.items() if c in classes}
    print(f'{len(funcs)} function names, {len(classes)} classes and locals of {len(local_fns)} functions changed -> {len(affected)} functions to re-lift')
    if a.dry_run:
        return
    out = os.path.join(ROOT, 'build', 'naming')
    os.makedirs(out, exist_ok=True)
    listing = os.path.join(out, 'affected.txt')
    with open(listing, 'w') as f:
        f.write('\n'.join(sorted(affected)) + '\n')

    def run(*cmd):
        r = subprocess.run([sys.executable] + list(cmd), cwd=HERE)
        if r.returncode:
            sys.exit(f'{cmd[0]} failed')
    # the promoted source modules (tools/rewrite/promote.py) are written with the names applied so far
    promote = os.path.join(ROOT, 'tools', 'rewrite', 'promote.py')
    sys.path.insert(0, os.path.dirname(promote))
    import promote as promoted_modules
    promoted_modules.snapshot(old)
    if classes:
        run('classes.py')       # struct and member names (cache/classes.json, structs.json, classes.h)
    if funcs:
        run('native_gen.py')    # prototypes and bridges under the new names
    skip = os.path.join(HERE, 'skip.txt')
    # a machine set up from the verification manifest (tools/setup_all.ps1 -Tested manifest) has no tester results
    # of its own: its list is cache/manifest_skip.txt, not the tracked skip.txt (the development machine's)
    manifest_skip = os.path.join(HERE, 'cache', 'manifest_skip.txt')
    if os.path.exists(manifest_skip) and not os.path.exists(os.path.join(HERE, 'difftest', 'results', 'status.json')):
        skip = manifest_skip
    run('lift.py', '--funcs', listing, '--skip', skip if os.path.exists(skip) else os.path.join(HERE, 'overridden.txt'))
    run(promote, 'sync')
    with open(APPLIED, 'w', encoding='utf-8') as f:
        json.dump(now, f, indent=0, sort_keys=True)
    print('applied. Next: powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Build')


if __name__ == '__main__':
    main()
