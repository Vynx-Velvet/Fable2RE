"""Runtime bisection of lifted code via lifted_disable_ranges (no re-lift, no rebuild).

    python tools/lift/bisect_ranges.py LO HI [KEEP]   # test the upper half of [LO, HI); KEEP and up stay lifted

Each step: of the suspect interval [LO, HI), only the upper half by function count stays lifted (step
prints both halves). Broken -> recurse into the upper half; fine -> into the lower half.
The audio range (82C40000-82CF8E10) always stays recompiled.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import chunks  # noqa: E402

AUDIO = (0x82C40000, 0x82CF8E10)  # XAudio2 library incl. its mixer routines (tables at 820165D0)
TOML = os.path.join(chunks.ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release', 'Fable2.toml')


def lifted_addresses():
    addrs = []
    for f in os.listdir(chunks.OUT_DIR):
        if re.fullmatch(r'lifted\.\d+\.\d+\.cpp', f):
            text = open(os.path.join(chunks.OUT_DIR, f), encoding='utf-8').read()
            addrs += [int(a, 16) for a in re.findall(r'^(?:F2_LIFTED|CPU_STATE_ENTRY)\(\w+, 0x([0-9A-F]{8})\)', text, re.M)]
    return sorted(a for a in addrs if not AUDIO[0] <= a < AUDIO[1])


def main():
    lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
    # optional 3rd argument KEEP: everything from KEEP up is already cleared and stays lifted
    keep = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0xFFFFFFFF
    addrs = lifted_addresses()
    inside = [a for a in addrs if lo <= a < hi]
    mid = inside[len(inside) // 2]
    on = (mid, hi)
    ranges = [f'{AUDIO[0]:08X}-{AUDIO[1]:08X}', f'00000000-{on[0]:08X}']
    if on[1] < keep:
        ranges.append(f'{on[1]:08X}-{keep:08X}')
    setting = ','.join(ranges)
    text = open(TOML, encoding='utf-8').read()
    text, n = re.subn(r'^lifted_disable_ranges = ".*"$', f'lifted_disable_ranges = "{setting}"', text, flags=re.M)
    if n == 0:
        # the key equals its compiled default (the XAudio2 range) and the F4 'Save to config' leaves such keys out
        text = text.rstrip('\n') + f'\nlifted_disable_ranges = "{setting}"\n'
    elif n > 1:
        sys.exit(f'{TOML}: lifted_disable_ranges is set {n} times')
    with open(TOML, 'w', encoding='utf-8', newline='') as f:
        f.write(text)
    print(f'suspect {lo:08X}-{hi:08X}: {len(inside)} functions')
    print(f'lifted now {on[0]:08X}-{on[1]:08X} ({sum(1 for a in inside if a >= mid)} functions)')
    print(f'  broken -> next: {on[0]:08X} {on[1]:08X}    fine -> next: {lo:08X} {mid:08X}')


if __name__ == '__main__':
    main()
