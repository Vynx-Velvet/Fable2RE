"""Which register hand-off is missing in one function? (after pass_bisect.py found the plain translation bad
and LIFT_SYNC=ret makes it good)

    python tools/lift/sync_bisect.py sub_8221FD60 --scenario load --check terrain

Re-lifts the function with only some of the volatile registers treated as results (LIFT_SYNC=ret +
LIFT_SYNC_REGS), rebuilds its chunk and runs the game test, halving the register set until one is left.
"""
import argparse
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import autotest  # noqa: E402
import auto_bisect  # noqa: E402
import pass_bisect  # noqa: E402
import regs  # noqa: E402
import lift as lift_mod  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('func')
    ap.add_argument('--scenario', default='load')
    ap.add_argument('--check', default='load')
    a = ap.parse_args()
    script, limit = autotest.SCENARIOS[a.scenario]
    outputs = lift_mod.summaries()['outputs'].get(a.func, regs.ABI_OUTPUTS)
    cand = sorted({n.split('.')[0] for n in regs.names(regs.VOLATILE & ~outputs)})
    print(f'{len(cand)} candidate registers: {" ".join(cand)}', flush=True)
    k = [0]

    def bad(group):
        pass_bisect.lift(a.func, LIFT_SYNC='ret', LIFT_SYNC_REGS=','.join(group))
        if not pass_bisect.build():
            raise SystemExit('build failed')
        k[0] += 1
        r = autotest.run(script, '', f'sync{k[0]}', limit, quiet=True)
        b = auto_bisect.bad(r, a.check)
        print(f'  [{" ".join(group)}] as results -> {"BAD" if b else "good"}', flush=True)
        return b

    try:
        while len(cand) > 1:
            h = cand[:len(cand) // 2]
            cand = cand[len(cand) // 2:] if bad(h) else h
        print(f'FOUND register {cand[0]}')
    finally:
        pass_bisect.lift(a.func)


if __name__ == '__main__':
    main()
