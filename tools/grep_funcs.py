"""grep the generated code's disassembly comments and report the containing guest functions.
Usage: python tools/grep_funcs.py "<regex on the asm text>" """
import bisect, json, os, re, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
byfile = {}
for a, f in db.items():
    byfile.setdefault(f['file'], []).append((f['line'], a))
for v in byfile.values(): v.sort()
pat = re.compile(sys.argv[1])
gen = os.path.join(ROOT, 'Fable2Recomp', 'generated')
hits = {}
for fn in sorted(byfile):
    starts = byfile[fn]; lines = [s for s, _ in starts]
    with open(os.path.join(gen, fn), encoding='utf-8', errors='replace') as fh:
        for no, line in enumerate(fh, 1):
            m = re.match(r'\s*// (.*)', line)
            if m and pat.search(m.group(1)):
                i = bisect.bisect_right(lines, no) - 1
                if i >= 0:
                    a = starts[i][1]
                    hits.setdefault(a, []).append(m.group(1))
for a in sorted(hits):
    f = db[a]
    print('%s n=%d callers=%d  %s' % (a, f['ninsn'], len(f['callers']), ' | '.join(hits[a][:4])))
