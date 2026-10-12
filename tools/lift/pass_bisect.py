"""Finds the lifter transformation that breaks one function (after auto_bisect.py named the function).

    python tools/lift/pass_bisect.py sub_8221FD60 --scenario load --check terrain
    python tools/lift/pass_bisect.py sub_8227F0B0 --difftest       (oracle: the differential tester, no game run)

The function is re-lifted with passes switched off / limited (LIFT_NO, LIFT_LIMIT: passes.py), its chunk is
rebuilt and the game test runs (tools/autotest.py), until one change of one pass is left: printed as
"LAST <pass> #n: <statement>". The function is left lifted normally at the end.
"""
import argparse
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import autotest  # noqa: E402
import auto_bisect  # noqa: E402

PASSES = ['fold', 'sugar1', 'inline', 'sugar2', 'dead', 'structure']
LIMITED = ['fold', 'inline', 'dead']  # passes that count their changes


def lift(func, **env):
    e = dict(os.environ, LIFT_COUNT='1', **env)
    r = subprocess.run([sys.executable, os.path.join(HERE, 'lift.py'), '--funcs', func, '--skip',
                        os.path.join(HERE, 'overridden.txt')], capture_output=True, text=True, env=e, cwd=HERE)
    if 'lifted 1 functions' not in r.stdout:
        raise SystemExit(f'lift failed: {r.stdout[-500:]} {r.stderr[-1500:]}')
    counts = {}
    m = re.search(r'^PASSCOUNT (.*)$', r.stdout, re.M)
    if m:
        counts = {k: int(v) for k, v in (x.split('=') for x in m.group(1).split())}
    last = re.search(r'^LAST .*$', r.stdout, re.M)
    return counts, last.group(0) if last else None


def build():
    e = dict(os.environ, REXSDK=os.path.join(ROOT, 'rexglue-sdk').replace('\\', '/'))
    r = subprocess.run(['powershell', '-ExecutionPolicy', 'Bypass', '-File', os.path.join(ROOT, 'tools', 'build.ps1'),
                        '-Preset', 'win-amd64-release', '-Target', 'Fable2'], capture_output=True, text=True, env=e)
    if r.returncode:
        return False
    return True


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('func')
    ap.add_argument('--scenario', default='load')
    ap.add_argument('--check', default='load')
    ap.add_argument('--difftest', action='store_true', help='use the differential tester as the oracle')
    a = ap.parse_args()
    script, limit = autotest.SCENARIOS[a.scenario]
    n = [0]

    def bad(label, **env):
        counts, last = lift(a.func, **env)
        if a.difftest:
            r = subprocess.run([sys.executable, os.path.join(HERE, 'difftest', 'run.py'), '--funcs', a.func],
                               capture_output=True, text=True, cwd=HERE)
            m = re.search(r'tested 1 functions: (\d+) problems', r.stdout)
            why = re.search(r'^\s*(MISMATCH|CRASH|UNTESTED|BUILD FAILED).*$', r.stdout, re.M)
            b = None if (m is None or (why and why.group(1) == 'BUILD FAILED')) else m.group(1) != '0'
            print(f'  [{label}] -> {"BAD" if b else "good" if b is False else "does not build"}'
                  + (f'   {why.group(0).strip()[:150]}' if why else ''), flush=True)
            return b, counts, last
        if not build():
            print(f'  [{label}] does not compile -> skipped', flush=True)
            return None, counts, last
        n[0] += 1
        r = autotest.run(script, '', f'pass{n[0]}', limit, quiet=True)
        b = auto_bisect.bad(r, a.check)
        print(f'  [{label}] -> {"BAD" if b else "good"}', flush=True)
        return b, counts, last

    try:
        culprit = None
        for p in PASSES:
            b, counts, _ = bad(f'without {p}', LIFT_NO=p)
            if b is False:
                culprit = p
                break
        if culprit is None:
            b, _, _ = bad('without any pass', LIFT_NO=','.join(PASSES))
            print('no single pass is responsible; ' + ('the plain translation is bad too' if b else
                                                       'a combination of passes is'))
            if b:
                for sync in ('calls,ret', 'ret', 'calls'):
                    b2, _, _ = bad(f'register hand-off: LIFT_SYNC={sync}', LIFT_SYNC=sync)
                    if b2 is False:
                        print(f'register hand-off ({sync}): the whole-game analysis misses a register here')
                        break
                else:
                    print('not the register hand-off either: typing / variable splitting')
            return 1
        print(f'pass: {culprit}', flush=True)
        if culprit not in LIMITED:
            return 0
        total = lift(a.func)[0].get(culprit, 0)
        lo, hi = 0, total  # good with lo changes, bad with hi
        while hi - lo > 1:
            mid = (lo + hi) // 2
            b, _, _ = bad(f'{culprit} limited to {mid}/{total}', LIFT_LIMIT=f'{culprit}:{mid}')
            if b:
                hi = mid
            else:
                lo = mid
        _, last = lift(a.func, LIFT_LIMIT=f'{culprit}:{hi}')
        print(f'FOUND change {hi} of {total} of pass {culprit}:')
        print(last)
        return 0
    finally:
        lift(a.func)  # back to the normal form (the caller fixes the lifter and rebuilds)


if __name__ == '__main__':
    sys.exit(main())
