"""Print the PowerPC disassembly of guest functions from the generated C++.
Usage: python tools/asm.py 82213C10 [8219CE10 ...] [-n 200]"""
import json, os, re, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
args = sys.argv[1:]
maxl = 10**9
if '-n' in args:
    i = args.index('-n'); maxl = int(args[i + 1]); del args[i:i + 2]
cache = {}
for a in args:
    a = a.upper().replace('SUB_', '').replace('0X', '')
    f = db.get(a)
    if not f:
        print('no function', a); continue
    path = os.path.join(ROOT, 'Fable2Recomp', 'generated', f['file'])
    if path not in cache:
        cache[path] = open(path, encoding='utf-8', errors='replace').read().split('\n')
    lines = cache[path]
    out = []
    i = f['line']
    addr = int(a, 16)
    while i < len(lines) and not lines[i].startswith('}'):
        l = lines[i]
        m = re.match(r'\s*// (.*)', l)
        if m:
            out.append('  %08X  %s' % (addr, m.group(1))); addr += 4
        elif l.startswith('loc_'):
            addr = int(l[4:12], 16)
        i += 1
    print('=== sub_%s  insns=%d callers=%d %s' % (a, f['ninsn'], len(f['callers']), ' '.join(f['callers'][:8])))
    print('\n'.join(out[:maxl]))
