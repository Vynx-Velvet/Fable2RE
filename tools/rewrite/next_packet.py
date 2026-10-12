"""The next rewrite packet to work on (for an agent loop; see AGENT.md).

    python tools/rewrite/next_packet.py          prints the packet name and path, or DONE
    python tools/rewrite/next_packet.py --status  how many packets are done / in progress / waiting

A packet is done when build/rewrite/answers/<packet>/results.txt exists and every function in it is OK (or
notes.txt explains the rest). A packet is taken when its answer directory exists (created by this script).
"""
import argparse
import os
import re

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
RW = os.path.join(ROOT, 'build', 'rewrite')


STALE_MINUTES = 90   # a packet taken this long ago with nothing new written is offered again (a session died)


def state(packet):
    import time
    d = os.path.join(RW, 'answers', packet)
    if not os.path.isdir(d):
        return 'waiting'
    res = os.path.join(d, 'results.txt')
    if not os.path.exists(res):
        newest = max([os.path.getmtime(os.path.join(d, f)) for f in os.listdir(d)] + [os.path.getmtime(d)])
        return 'waiting' if time.time() - newest > STALE_MINUTES * 60 else 'taken'
    results = {l.split('\t')[0]: l.split('\t')[1] for l in open(res, encoding='utf-8').read().split('\n')
               if '\t' in l}
    pk = os.path.join(RW, 'packets', packet + '.md')
    wanted = re.findall(r'^### (sub_[0-9A-F]{8})', open(pk, encoding='utf-8').read(), re.M) \
        if os.path.exists(pk) else []
    if all(results.get(n) == 'OK' for n in wanted) or os.path.exists(os.path.join(d, 'notes.txt')):
        return 'done'
    return 'taken'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--status', action='store_true')
    a = ap.parse_args()
    q = os.path.join(RW, 'queue.txt')
    packets = [l.strip() for l in open(q, encoding='utf-8')] if os.path.exists(q) else []
    packets = [p for p in packets if p]
    if a.status:
        from collections import Counter
        c = Counter(state(p) for p in packets)
        print(f'{len(packets)} packets: {c["done"]} done, {c["taken"]} in progress, {c["waiting"]} waiting')
        return
    for p in packets:
        if state(p) == 'waiting':
            d = os.path.join(RW, 'answers', p)
            os.makedirs(d, exist_ok=True)
            os.utime(d, None)   # (taken now)
            print(p)
            print(os.path.join(RW, 'packets', p + '.md'))
            return
    print('DONE')


if __name__ == '__main__':
    main()
