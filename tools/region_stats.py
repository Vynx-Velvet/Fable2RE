"""Per-function stats for an address range: size, callers, stwu count (packet writes),
calls, device-offset (>=10000) fields touched.  Usage: region_stats.py 82214000 82230000"""
import json, os, re, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
cache = {}
for a in sorted(db):
    ai = int(a, 16)
    if not lo <= ai < hi: continue
    f = db[a]
    path = os.path.join(ROOT, 'Fable2Recomp', 'generated', f['file'])
    if path not in cache:
        cache[path] = open(path, encoding='utf-8', errors='replace').read().split('\n')
    L = cache[path]; i = f['line']; stwu = 0; hioff = set()
    while i < len(L) and not L[i].startswith('}'):
        m = re.match(r'\s*// (\S+) (.*)', L[i])
        if m:
            if m.group(1) == 'stwu' and ',4(' in m.group(2): stwu += 1
            mm = re.search(r',(\d{5})\(r\d+\)', m.group(2))
            if mm: hioff.add(int(mm.group(1)))
        i += 1
    print('%s n=%4d callers=%3d stwu4=%3d calls=%-40s dev=%s' % (a, f['ninsn'], len(f['callers']), stwu,
          ' '.join(c for c in f['calls'][:5]), ' '.join(str(x) for x in sorted(hioff)[:10])))
