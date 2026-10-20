"""Bisects which lifted or promoted functions cause a crash the game logs, by running it with half of a suspect
address interval on the recompiled original (lifted_disable_ranges, set for the run only through F2_CVARS;
Fable2.toml is not touched) and a scripted input sequence (F2_AUTOTEST), until one function is left.

    python tools/lift/bisect_crash.py --script "at 38; press A; ..." [--lo 82170000 --hi 83300000]
                                      [--seconds 120] [--marker REGEX] [--survive REGEX] [--cvars "k=v;..."]

A run is "broken" when the game's log for that run matches --marker (default: the lifted code's null-call report
or the runtime's call to an unregistered function) and "fine" when it matches --survive (default: the script's
first snapshot) without the marker. Each step disables the lower half of the interval: broken -> the fault is in
the upper half; fine -> in the lower half (so a fault that needs two functions in different halves is not found:
the log says so when neither half is broken). The audio library's range stays recompiled throughout. Progress and
the result go to build/bisect_crash/log.txt.
"""
import argparse
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import chunks  # noqa: E402

AUDIO = (0x82C40000, 0x82CF8E10)
BUILD = os.path.join(ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release')
LOG = os.path.join(BUILD, 'fable2.log')
OUT = os.path.join(ROOT, 'build', 'bisect_crash')


def lifted_addresses():
    """Every function that runs as lifted or promoted code (address order)."""
    addrs = set()
    for f in os.listdir(chunks.OUT_DIR):
        if re.fullmatch(r'lifted\.\d+\.\d+\.cpp', f):
            text = open(os.path.join(chunks.OUT_DIR, f), encoding='utf-8').read()
            addrs |= {int(a, 16) for a in re.findall(r'^(?:F2_LIFTED|CPU_STATE_ENTRY)\(\w+, 0x([0-9A-F]{8})\)', text, re.M)}
    for f in os.listdir(chunks.PROMOTED_DIR):
        if f.endswith('.cpp'):
            text = open(os.path.join(chunks.PROMOTED_DIR, f), encoding='utf-8').read()
            addrs |= {int(a, 16) for a in re.findall(r'^PROMOTED_ENTRY\(\d+, \w+, 0x([0-9A-F]{8})\)', text, re.M)}
    return sorted(a for a in addrs if not AUDIO[0] <= a < AUDIO[1])


def run(disable, script, seconds, cvars, tag):
    """Runs the game once; returns the log of that run."""
    ranges = [f'{AUDIO[0]:08X}-{AUDIO[1]:08X}'] + [f'{lo:08X}-{hi:08X}' for lo, hi in disable]
    env = dict(os.environ, F2_AUTOTEST=script,
               F2_CVARS=f'lifted_disable_ranges={",".join(ranges)}' + (';' + cvars if cvars else ''))
    before = os.path.getsize(LOG) if os.path.exists(LOG) else 0
    subprocess.run(['powershell', '-ExecutionPolicy', 'Bypass', '-File', os.path.join(ROOT, 'tools', 'run_game.ps1'),
                    '-Preset', 'win-amd64-release', '-Seconds', str(seconds), '-Tag', tag], cwd=ROOT, env=env,
                   capture_output=True, text=True)
    with open(LOG, 'rb') as f:
        f.seek(before if os.path.getsize(LOG) >= before else 0)   # (the runtime truncates a log that grew large)
        return f.read().decode('utf-8', errors='replace')


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--script', required=True)
    ap.add_argument('--lo', default='82170000')
    ap.add_argument('--hi', default='83300000')
    ap.add_argument('--seconds', type=int, default=120)
    ap.add_argument('--marker', default=r'call through a null pointer|invalid or unregistered function')
    ap.add_argument('--survive', default=r'autotest: [0-9.]+ s shot')
    ap.add_argument('--cvars', default='')
    a = ap.parse_args()
    os.makedirs(OUT, exist_ok=True)
    out = open(os.path.join(OUT, 'log.txt'), 'a', encoding='utf-8')

    def say(s):
        print(s, flush=True)
        out.write(time.strftime('%H:%M:%S ') + s + '\n')
        out.flush()

    addrs = lifted_addresses()
    lo, hi = int(a.lo, 16), int(a.hi, 16)
    suspects = [x for x in addrs if lo <= x < hi]
    say(f'bisect over {len(suspects)} lifted/promoted functions in [{lo:08X}, {hi:08X})')
    step = 0
    while len(suspects) > 1:
        step += 1
        mid = suspects[len(suspects) // 2]
        lower, upper = [x for x in suspects if x < mid], [x for x in suspects if x >= mid]
        # the lower half runs recompiled: a crash then lies in the upper half
        text = run([(lower[0], mid)], a.script, a.seconds, a.cvars, f'bisect{step}')
        broken, fine = bool(re.search(a.marker, text)), bool(re.search(a.survive, text))
        say(f'step {step}: lower {lower[0]:08X}-{mid:08X} ({len(lower)}) off, upper {mid:08X}-{suspects[-1]:08X} '
            f'({len(upper)}) on -> ' + ('BROKEN: fault in the upper half' if broken else
                                        'fine: fault in the lower half' if fine else 'neither marker: stop'))
        if broken:
            suspects = upper
        elif fine:
            suspects = lower
        else:
            say('the run neither crashed nor reached a snapshot (a hang, or the script never ran): stopping')
            return 1
    say(f'result: sub_{suspects[0]:08X}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
