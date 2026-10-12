"""For an agent working through the naming batches: which batch is next, and where its answer goes.

    python tools/naming/next_batch.py            -> prints the next batch without an answer and the answer path
    python tools/naming/next_batch.py --count    -> how many are left

See tools/naming/AGENT.md.
"""
import glob
import os
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
BATCHES = os.path.join(ROOT, 'build', 'naming', 'batches')
ANSWERS = os.path.join(ROOT, 'build', 'naming', 'answers')


def main():
    os.makedirs(ANSWERS, exist_ok=True)
    todo = [p for p in sorted(glob.glob(os.path.join(BATCHES, 'batch_*.md')))
            if not os.path.exists(os.path.join(ANSWERS, os.path.basename(p)[:-3] + '.tsv'))]
    if '--count' in sys.argv:
        print(len(todo))
        return
    if not todo:
        print('DONE: every batch has an answer. Run: python tools/naming/merge.py')
        return
    p = todo[0]
    print(f'BATCH {p}')
    print(f'ANSWER {os.path.join(ANSWERS, os.path.basename(p)[:-3] + ".tsv")}')
    print(f'LEFT {len(todo)}')


if __name__ == '__main__':
    main()
