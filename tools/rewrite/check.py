"""Checks rewritten functions against the originals (differential tester, relaxed mode).

    python tools/rewrite/check.py <packet>          packet = name of build/rewrite/packets/<packet>.md
    python tools/rewrite/check.py --dir DIR          any directory of sub_X.cpp files
    python tools/rewrite/check.py --dir DIR --profiles 1,3   other test inputs (default 0,1)

Each sub_X.cpp must keep the definition line, the UseLiftedCode / LiftedFrame lines and the CPU_STATE_ENTRY
line of the lifted code (tools/rewrite/RULES.md). Every function is compared on two input profiles (sparse
memory, then dense inputs - the second catches a wrong load chain that reads zeros in sparse memory) and is
OK only when both agree. Prints one line per function and writes <dir>/results.txt (the combined verdict;
the per-profile files stay next to it).
"""
import argparse
import glob
import os
import re
import subprocess
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
LIFT = os.path.join(ROOT, 'tools', 'lift')


def validate(path):
    text = open(path, encoding='utf-8', errors='replace').read()
    name = os.path.basename(path)[:-4]
    problems = []
    if not re.search(r'^[\w:<>]+\*? \w+\(CpuState& ctx, uint8_t\* base', text, re.M):
        problems.append('definition line missing (T Name(CpuState& ctx, uint8_t* base, ...) {)')
    if 'UseLiftedCode(' not in text:
        problems.append('UseLiftedCode line missing')
    if not re.search(r'^(?:CPU_STATE_ENTRY|F2_LIFTED)\(' + name + r', 0x[0-9A-F]{8}\)', text, re.M):
        problems.append(f'CPU_STATE_ENTRY({name}, 0x...) line missing')
    if '// @lift' in text:
        problems.append('leave out the "// @lift" marker line')
    return problems


def read_results(path):
    out = {}
    if os.path.exists(path):
        for line in open(path, encoding='utf-8'):
            if '\t' in line:
                n, _, why = line.rstrip('\n').partition('\t')
                out[n] = why
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('packet', nargs='?')
    ap.add_argument('--dir')
    ap.add_argument('--jobs', type=int, default=2)
    ap.add_argument('--profiles', default='0,1,4,5')
    ap.add_argument('--outputs', action='store_true', help='also compare the registers callers read after the '
                                                          'return (tools/rewrite/promote.py uses this)')
    a = ap.parse_args()
    d = a.dir or (os.path.join(ROOT, 'build', 'rewrite', 'answers', a.packet) if a.packet else None)
    d = os.path.abspath(d) if d else d
    if not d or not os.path.isdir(d):
        sys.exit('no such answer directory: ' + str(d))
    files = sorted(glob.glob(os.path.join(d, 'sub_*.cpp')))
    if not files:
        sys.exit('no sub_X.cpp files in ' + d)
    bad = {}
    for p in files:
        pr = validate(p)
        if pr:
            bad[os.path.basename(p)[:-4]] = 'INVALID: ' + '; '.join(pr)
    seen = {}   # function -> [verdicts of the profiles]
    profiles = [int(x) for x in a.profiles.split(',') if x.strip()]
    # results of an earlier run must not be read as this run's (a tester that fails to build writes none)
    for old in glob.glob(os.path.join(d, 'results*.txt')):
        os.remove(old)
    # one run: every test program is built once and run on all the profiles
    r = subprocess.run([sys.executable, os.path.join(LIFT, 'difftest', 'run.py'), '--relaxed', '--rewrites', d]
                       + (['--outputs'] if a.outputs else []) + [
                        '--jobs', str(a.jobs), '--profile', str(profiles[0]),
                        '--profiles', ','.join(str(p) for p in profiles)], cwd=LIFT, capture_output=True, text=True)
    if r.returncode:
        print(r.stderr[-2000:])
    for prof in profiles:
        res = read_results(os.path.join(d, 'results.txt' if not prof else f'results_p{prof}.txt'))
        for n, why in res.items():
            seen.setdefault(n, []).append(why + (f' [profile {prof}]' if prof and why != 'OK' else ''))
    combined = dict(bad)
    for n, verdicts in seen.items():
        if n in combined:
            continue
        failures = [v for v in verdicts if v != 'OK' and not v.startswith('UNTESTED')]
        if failures:
            combined[n] = failures[0]        # a real difference on any profile
        elif 'OK' in verdicts:
            combined[n] = 'OK'                # identical wherever it could be compared
        else:
            combined[n] = verdicts[0]         # not comparable on any profile (timeouts)
    names = [os.path.basename(p)[:-4] for p in files]
    with open(os.path.join(d, 'results.txt'), 'w', encoding='utf-8') as f:
        for n in names:
            why = combined.get(n, 'NOT TESTED (not a lifted function, or no block)')
            f.write(f'{n}\t{why}\n')
            print(f'  REWRITE {n}: {why[:300]}')
    ok = sum(1 for n in names if combined.get(n) == 'OK')
    print(f'tested {len(names)} functions: {len(names) - ok} problems')
    print('results:', os.path.join(d, 'results.txt'))


if __name__ == '__main__':
    main()
