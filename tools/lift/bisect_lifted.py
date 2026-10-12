"""Finds the lifted file (then function range) that makes the game crash, by switching halves of the
lifted code back to the recompiled originals (cvars lifted_disable_files / lifted_disable_ranges) and
launching the game briefly (tools/run_game.ps1). Launches open the game window.

  python tools/lift/bisect_lifted.py files            -> the generated file whose lifted functions crash
  python tools/lift/bisect_lifted.py ranges <file>    -> narrows it to one function
"""
import json
import os
import re
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
BUILD = os.path.join(ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release')
LIFTED = os.path.join(ROOT, 'Fable2Recomp', 'lifted')
SECONDS = int(os.environ.get('BISECT_SECONDS', '15'))


def run(args):
    """Launch with extra cvars; True when it crashed."""
    log = os.path.join(BUILD, 'fable2.log')
    before = os.path.getsize(log) if os.path.exists(log) else 0
    cmd = ['powershell', '-ExecutionPolicy', 'Bypass', '-File', os.path.join(ROOT, 'tools', 'run_game.ps1'),
           '-Preset', 'win-amd64-release', '-Seconds', str(SECONDS), '-Tag', 'bisect', '-GameArgs'] + \
        [' '.join(args)] if args else \
        ['powershell', '-ExecutionPolicy', 'Bypass', '-File', os.path.join(ROOT, 'tools', 'run_game.ps1'),
         '-Preset', 'win-amd64-release', '-Seconds', str(SECONDS), '-Tag', 'bisect']
    subprocess.run(cmd, capture_output=True, text=True)
    with open(log, 'rb') as f:
        f.seek(before if os.path.getsize(log) >= before else 0)
        text = f.read().decode('utf-8', 'replace')
    crashed = bool(re.search(r'\[FATAL\]|lifted code: (crash|call through)', text))
    m = re.search(r'lifted code: [^\n]*', text)
    stack = re.search(r'lifted functions running on this thread[^\n]*', text)
    print(f'    {m.group(0)[:150] if m else "(no lifted-code line)"} -> {"CRASH" if crashed else "ok"}'
          + (f'  [{stack.group(0)[-120:]}]' if stack else ''), flush=True)
    return crashed


def files():
    idx = sorted(int(m.group(1)) for f in os.listdir(LIFTED) for m in [re.fullmatch(r'lifted\.(\d+)\.cpp', f)] if m)
    print('baseline (all lifted):', flush=True)
    if not run([]):
        print('no crash with everything lifted - nothing to find')
        return
    print('everything off:', flush=True)
    if run(['--lifted_disable_files', ','.join(map(str, idx))]):
        print('crashes with every lifted file off: not the lifted code (or a range not covered)')
        return
    cand = idx
    while len(cand) > 1:
        half = cand[:len(cand) // 2]
        print(f'{len(cand)} candidates; switching off {len(half)} ({half[0]}..{half[-1]}):', flush=True)
        if run(['--lifted_disable_files', ','.join(map(str, half))]):
            cand = cand[len(cand) // 2:]  # still crashes: culprit among the ones left on
        else:
            cand = half
    print(f'culprit file: generated/Fable2_recomp.{cand[0]}.cpp (lifted/lifted.{cand[0]}.cpp)')


def ranges(file_idx):
    text = open(os.path.join(LIFTED, f'lifted.{file_idx}.cpp'), encoding='utf-8').read()
    addrs = sorted(int(a, 16) for a in re.findall(r'(?:F2_LIFTED|CPU_STATE_ENTRY)\(\w+, 0x([0-9A-F]{8})\)', text))
    cand = addrs
    while len(cand) > 1:
        half = cand[:len(cand) // 2]
        rng = f'{half[0]:08X}-{half[-1] + 1:08X}'
        print(f'{len(cand)} candidates; switching off {rng}:', flush=True)
        if run(['--lifted_disable_ranges', rng + ',82C40000-82CF0000']):  # (+ the audio range from Fable2.toml)
            cand = cand[len(cand) // 2:]
        else:
            cand = half
    print(f'culprit function: sub_{cand[0]:08X}')


if __name__ == '__main__':
    if sys.argv[1] == 'files':
        files()
    else:
        ranges(int(sys.argv[2]))
