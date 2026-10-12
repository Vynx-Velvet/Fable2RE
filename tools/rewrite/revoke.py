"""Takes rewrites out of the build again (a later check or a game run showed them wrong).

    python tools/rewrite/revoke.py sub_822848B8 [sub_...] --reason "calls the vtable (profile 1)"
    python tools/rewrite/revoke.py --from-results DIR/results.txt     every function not OK in that file

The rewritten file is removed, the manifest line is marked, the function's answer in build/rewrite/answers
gets the reason as its result (so apply.py does not put it back), the function is lifted again (the lifter's
own output returns to its chunk) and its tester record is cleared so the strict test runs on it next time.
Then: tools/lift/update.ps1 -Build.
"""
import argparse
import glob
import os
import subprocess
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
    ap.add_argument('names', nargs='*')
    ap.add_argument('--from-results')
    ap.add_argument('--reason', default='revoked')
    a = ap.parse_args()
    names = {}
    for n in a.names:
        names[n] = a.reason
    if a.from_results:
        for line in open(a.from_results, encoding='utf-8'):
            n, _, why = line.rstrip('\n').partition('\t')
            if n.startswith('sub_') and why and why != 'OK' and not why.startswith('UNTESTED'):
                names[n] = why
    if not names:
        sys.exit('nothing to revoke')
    gone = []
    for n, why in names.items():
        p = os.path.join(DEST, n + '.cpp')
        if os.path.exists(p):
            os.replace(p, os.path.join(DEST, n + '.cpp.revoked'))
            gone.append(n)
        for res in glob.glob(os.path.join(ROOT, 'build', 'rewrite', 'answers', '*', 'results.txt')):
            lines = open(res, encoding='utf-8').read().split('\n')
            if not any(l.startswith(n + '\t') for l in lines):
                continue
            with open(res, 'w', encoding='utf-8') as f:
                for l in lines:
                    if l.startswith(n + '\t'):
                        l = f'{n}\tREVOKED: {why[:200]}'
                    if l:
                        f.write(l + '\n')
    man = os.path.join(DEST, 'manifest.tsv')
    if os.path.exists(man):
        lines = [l for l in open(man, encoding='utf-8').read().split('\n') if l]
        with open(man, 'w', encoding='utf-8') as f:
            for l in lines:
                n = l.split('\t')[0]
                f.write((l + f'\trevoked {time.strftime("%Y-%m-%d %H:%M")}: {names[n][:120]}' if n in names and
                         'revoked' not in l else l) + '\n')
    import run as tester
    st = tester.load_status()
    for n in names:
        st.pop(n, None)
    tester.save_status(st)
    if gone:
        listing = os.path.join(ROOT, 'build', 'rewrite', 'revoked.txt')
        with open(listing, 'w') as f:
            f.write('\n'.join(gone) + '\n')
        r = subprocess.run([sys.executable, 'lift.py', '--funcs', listing, '--skip', 'overridden.txt'], cwd=LIFT,
                           capture_output=True, text=True)
        print(r.stdout.strip().split('\n')[-1])
    print(f'revoked {len(gone)} rewrites; next: tools/lift/update.ps1 -Build')


if __name__ == '__main__':
    main()
