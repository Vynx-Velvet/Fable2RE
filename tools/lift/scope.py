"""Which code a function belongs to (research/catalog/scope.tsv: address ranges of the default.xex).

    game         Lionhead's own game and engine code: the target of the readable-code work
    game-static  compiler-generated start-up / shut-down functions of the game's global objects (named mechanically)
    library      third-party middleware that stays a library (Havok, Kynapse, Scaleform, image and XML readers)
    system       Xbox system libraries that a PC build replaces (audio, C runtime, Direct3D, shader compiler, imports)
    unknown      not identified yet

    python tools/lift/scope.py            counts per category, with how much of each is named
"""
import bisect
import os

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
_RANGES = None


def ranges():
    global _RANGES
    if _RANGES is None:
        _RANGES = []
        with open(os.path.join(ROOT, 'research', 'catalog', 'scope.tsv'), encoding='utf-8') as f:
            head = f.readline().rstrip('\n').split('\t')
            for line in f:
                c = dict(zip(head, line.rstrip('\n').split('\t')))
                if c.get('start'):
                    _RANGES.append((int(c['start'], 16), int(c['end'], 16), c['category'], c['what']))
        _RANGES.sort()
    return _RANGES


def category(addr):
    """'game', 'game-static', 'library', 'system' or 'unknown' for a function address."""
    r = ranges()
    i = bisect.bisect_right(r, (addr, 0xFFFFFFFF, '', '')) - 1
    if i >= 0 and r[i][0] <= addr < r[i][1]:
        return r[i][2]
    return 'unknown'


def in_game(addr):
    return category(addr) == 'game'


def main():
    import collections
    import json
    import sys
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import names
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    named = names.load()['functions']
    total, have = collections.Counter(), collections.Counter()
    for a in db:
        c = category(int(a, 16))
        total[c] += 1
        if int(a, 16) in named:
            have[c] += 1
    for c in ('game', 'game-static', 'library', 'system', 'unknown'):
        if total[c]:
            print(f'{c:12} {total[c]:6} functions, {have[c]:5} named ({100 * have[c] / total[c]:.1f}%)')


if __name__ == '__main__':
    main()
