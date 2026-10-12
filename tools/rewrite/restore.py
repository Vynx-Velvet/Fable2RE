"""Puts revoked rewrites back after a re-check cleared them.

    python tools/rewrite/restore.py --from-results DIR/results.txt [--dry-run]

For every function that is OK in that results file and has a Fable2Recomp/rewritten/sub_X.cpp.revoked, the
file is renamed back, the function's chunk takes the rewrite again, its tester record becomes "OK [relaxed]",
its answer in build/rewrite/answers gets OK again and the manifest gets a "restored" line.
Then: tools/lift/update.ps1 -Build, and the game checks.
"""
import argparse
import glob
import os
import sys
import time

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
LIFT = os.path.join(ROOT, 'tools', 'lift')
sys.path.insert(0, LIFT)
sys.path.insert(0, os.path.join(LIFT, 'difftest'))
import chunks  # noqa: E402

DEST = os.path.normpath(chunks.REWRITTEN_DIR)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--from-results', required=True)
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    names = []
    for line in open(a.from_results, encoding='utf-8'):
        n, _, why = line.rstrip('\n').partition('\t')
        if n.startswith('sub_') and why == 'OK' and os.path.exists(os.path.join(DEST, n + '.cpp.revoked')):
            names.append(n)
    print(f'{len(names)} revoked rewrites passed the re-check')
    if a.dry_run or not names:
        return
    by_file = {}
    for n in names:
        os.replace(os.path.join(DEST, n + '.cpp.revoked'), os.path.join(DEST, n + '.cpp'))
        fi = chunks.file_of(n)
        if fi is not None:
            by_file.setdefault(fi, set()).add(n)
    written = 0
    for fi, fnames in sorted(by_file.items()):
        written += chunks.update(fi, {n: [chunks.MARK + n] + chunks.rewritten(n) for n in fnames})
    import run as tester
    st = tester.load_status()
    blocks = {}
    for fi in by_file:
        blocks.update(tester.lifted_blocks({fi}).get(fi, {}))
    for n in names:
        if n in blocks:
            st[n] = [tester.block_hash(blocks[n]), 'OK [relaxed]']
    tester.save_status(st)
    stamp = time.strftime('%Y-%m-%d %H:%M')
    for res in glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*', 'results.txt')):
        lines = open(res, encoding='utf-8').read().split('\n')
        hit = False
        for i, l in enumerate(lines):
            n = l.split('\t')[0]
            if n in names and '\tREVOKED' in l:
                lines[i] = n + '\tOK'
                hit = True
        if hit:
            with open(res, 'w', encoding='utf-8') as f:
                f.write('\n'.join(l for l in lines if l) + '\n')
    with open(os.path.join(DEST, 'manifest.tsv'), 'a', encoding='utf-8') as f:
        for n in sorted(names):
            f.write(f'{n}\trestored\t{stamp}\n')
    print(f'restored {len(names)} rewrites into {written} chunk files')
    print('next: powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Build  (then the game checks)')


if __name__ == '__main__':
    main()
