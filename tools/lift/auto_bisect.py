"""Unattended bisection of a lifted-code bug (tools/autotest.py runs the game; nothing is rebuilt).

    python tools/lift/auto_bisect.py LO HI [--scenario menu] [--check scrambled|crash]

Suspects: the lifted functions with addresses in [LO, HI). Everything else stays lifted (except the ranges
in ALWAYS_OFF). Each step switches half of the suspects back to the recompiled originals through
F2_CVARS=lifted_disable_ranges=... and looks at the result:
  good -> the bug is in the half that was off;   bad -> it is in the half still on (the other half stays off).
Ends with one function; prints it. Fable2.toml is not touched.
"""
import argparse
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import autotest  # noqa: E402
import chunks  # noqa: E402

ALWAYS_OFF = ['82C40000-82CF8E10']  # XAudio2 library


def lifted_addresses():
    addrs = []
    for f in os.listdir(chunks.OUT_DIR):
        if re.fullmatch(r'lifted\.\d+\.\d+\.cpp', f):
            text = open(os.path.join(chunks.OUT_DIR, f), encoding='utf-8').read()
            addrs += [int(a, 16) for a in re.findall(r'^(?:F2_LIFTED|CPU_STATE_ENTRY)\(\w+, 0x([0-9A-F]{8})\)', text, re.M)]
    return sorted(addrs)


def ranges_of(addrs, universe):
    """Compact 'lo-hi' ranges covering exactly these lifted functions (universe: all lifted addresses, sorted)."""
    s = set(addrs)
    out, start, prev = [], None, None
    for a in universe:
        if a in s:
            if start is None:
                start = a
            prev = a
        elif start is not None:
            out.append(f'{start:08X}-{prev + 1:08X}')
            start = None
    if start is not None:
        out.append(f'{start:08X}-{prev + 1:08X}')
    return out


def bad(result, check):
    # a run that could not start (no golden save, missing exe, ...) says nothing about the suspects: counting it
    # as bad would end the bisection with "still bad with every suspect off"
    if result.get('result') in ('SETUP_ERROR', 'NOT_STARTED'):
        raise SystemExit('game check cannot run: ' + '; '.join(result.get('reasons') or [result['result']]))
    if check == 'crash':
        return not result['ok']
    if check == 'load':
        # the save must load: the game still presents frames afterwards, they are not scrambled, no fatal error
        return (not result['finished'] or bool(result['critical']) or not result['shots'] or
                max(n for _, n in result['shots']) > autotest.SCRAMBLED)
    if check == 'terrain':
        # the loaded level must show its terrain: without it the frame is mostly sky (blue above red; the
        # canyon of the test save is brown: mean blue - red about -24 with terrain, +47 without)
        if bad(result, 'load'):
            return True
        from PIL import Image
        import numpy as np
        m = np.asarray(Image.open(result['shots'][-1][0]).convert('RGB')).astype(np.float32).reshape(-1, 3).mean(0)
        return float(m[2] - m[0]) > 10
    if not result['shots']:
        return True  # (no picture at all)
    return max(n for _, n in result['shots']) > autotest.SCRAMBLED


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('lo')
    ap.add_argument('hi')
    ap.add_argument('--scenario', default='menu')
    ap.add_argument('--check', default='scrambled')
    ap.add_argument('--funcs', help='file of function names: only these are suspects (within lo-hi)')
    a = ap.parse_args()
    lo, hi = int(a.lo, 16), int(a.hi, 16)
    script, limit = autotest.SCENARIOS[a.scenario]
    universe = lifted_addresses()
    suspects = [x for x in universe if lo <= x < hi]
    if a.funcs:
        only = {int(l.strip()[4:], 16) for l in open(a.funcs) if l.strip().startswith('sub_')}
        suspects = [x for x in suspects if x in only]
    off = []  # suspects not being examined: kept on the recompiled code

    def test(disabled, tag):
        cvars = 'lifted_disable_ranges=' + ','.join(ALWAYS_OFF + ranges_of(disabled, universe))
        r = autotest.run(script, cvars, tag, limit, quiet=True)
        b = bad(r, a.check)
        print(f'  [{tag}] {len(disabled)} off -> {"BAD" if b else "good"}  '
              f'(noise {", ".join(f"{n:.1f}" for _, n in r["shots"])}; {r["status"]})', flush=True)
        return b

    print(f'{len(suspects)} suspects in {lo:08X}-{hi:08X}', flush=True)
    if test(suspects, 'all_off'):
        print('still bad with every suspect off: the bug is not (only) in this range')
        return 1
    step = 0
    while len(suspects) > 1:
        step += 1
        h1, h2 = suspects[:len(suspects) // 2], suspects[len(suspects) // 2:]
        if test(off + h1, f'step{step}'):
            suspects, off = h2, off + h1  # a bug is in the half still on
        else:
            suspects = h1                  # h2 is clean
        print(f'step {step}: {len(suspects)} suspects left ({suspects[0]:08X}-{suspects[-1] + 1:08X})', flush=True)
    print(f'FOUND sub_{suspects[0]:08X}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
