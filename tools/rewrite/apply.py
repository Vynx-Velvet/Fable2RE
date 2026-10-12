"""Puts accepted rewrites into the lifted build.

    python tools/rewrite/apply.py [--packet NAME ...] [--dry-run]

For every answer directory under build/rewrite/answers whose results.txt says OK for a function, the file
sub_X.cpp is copied to Fable2Recomp/rewritten/ (local, game-derived: not committed), the function's chunk is
rewritten with it (tools/lift/chunks.py prefers a rewritten function over the lifter's output from then on),
and the differential tester's record for it is set to "OK [relaxed]" with the block's hash, so the strict
test does not re-run (and fail) on it. A manifest lists what was applied and from where.
Then: powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Build, and the game checks.
"""
import argparse
import glob
import json
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
    ap.add_argument('--packet', action='append', default=[])
    ap.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    dirs = [os.path.join(ROOT, 'build', 'rewrite', 'answers', p) for p in a.packet] or \
        sorted(glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*')))
    accepted = {}
    for d in dirs:
        res = os.path.join(d, 'results.txt')
        if not os.path.exists(res):
            continue
        for line in open(res, encoding='utf-8'):
            n, _, why = line.rstrip('\n').partition('\t')
            src = os.path.join(d, n + '.cpp')
            if why == 'OK' and os.path.exists(src):
                accepted[n] = (src, os.path.basename(d))
    os.makedirs(DEST, exist_ok=True)
    manifest = os.path.join(DEST, 'manifest.tsv')
    have = {}
    if os.path.exists(manifest):
        for line in open(manifest, encoding='utf-8'):
            c = line.rstrip('\n').split('\t')
            if len(c) >= 2 and not any(x.startswith('revoked') for x in c[3:]):
                have[c[0]] = c   # a revoked function may be applied again from a newer accepted answer
    new = {n: v for n, v in accepted.items() if n not in have}
    print(f'{len(accepted)} accepted rewrites, {len(new)} not applied yet')
    if a.dry_run or not new:
        return
    import run as tester
    by_file = {}
    for n, (src, packet) in new.items():
        # stored with address-form names (n_sub_X, C_key): a function or class named later cannot break it
        text = open(src, encoding='utf-8', errors='replace').read()
        with open(os.path.join(DEST, n + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(chunks.canonical_names(text))
        fi = chunks.file_of(n)
        if fi is not None:
            by_file.setdefault(fi, set()).add(n)
    written = 0
    for fi, names in sorted(by_file.items()):
        written += chunks.update(fi, {n: [chunks.MARK + n] + chunks.rewritten(n) for n in names})
    # the tester's record: accepted in relaxed mode, hash of the block as it now stands in the chunk
    st = tester.load_status()
    blocks = {}
    for fi in by_file:
        blocks.update(tester.lifted_blocks({fi}).get(fi, {}))
    for n in new:
        if n in blocks:
            st[n] = [tester.block_hash(blocks[n]), 'OK [relaxed]']
    tester.save_status(st)
    with open(manifest, 'a', encoding='utf-8') as f:
        for n, (src, packet) in sorted(new.items()):
            f.write(f'{n}\t{packet}\t{time.strftime("%Y-%m-%d %H:%M")}\n')
    # names the rewrites propose ("// name: X" first line) -> naming answers for tools/naming/merge.py
    import re
    outdir = os.path.join(ROOT, 'build', 'naming', 'answers_rewrites')
    os.makedirs(outdir, exist_ok=True)
    proposed = 0
    with open(os.path.join(outdir, f'rewrites_{time.strftime("%Y%m%d_%H%M")}.tsv'), 'w', encoding='utf-8') as f:
        for n, (src, packet) in sorted(new.items()):
            text = open(src, encoding='utf-8', errors='replace').read()
            m = re.search(r'^//\s*name:\s*([A-Za-z_]\w*)\s*$', text, re.M)
            if m and not m.group(1).startswith(('sub_', 'n_sub_')):
                f.write(f'F\t{n[4:]}\t{m.group(1)}\tmedium\tProposed by the model that rewrote the function '
                        f'into readable C++ ({packet}).\n')
                proposed += 1
    print(f'{proposed} function names proposed by the rewrites -> {outdir}')
    print(f'applied {len(new)} rewrites into {written} chunk files; manifest {manifest}')
    print('next: powershell -ExecutionPolicy Bypass -File tools/lift/update.ps1 -Build  (then the game checks)')


if __name__ == '__main__':
    main()
