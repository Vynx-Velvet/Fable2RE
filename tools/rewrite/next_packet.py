"""The next rewrite packet to work on (for an agent loop; see AGENT.md).

    python tools/rewrite/next_packet.py          prints the packet name and path, or DONE
    python tools/rewrite/next_packet.py --agent  the same for an agent session: first a packet an earlier agent
                                                 session left unfinished (the session ended in the middle of it)
    python tools/rewrite/next_packet.py --status  how many packets are done / in progress / waiting

A packet is done when build/rewrite/answers/<packet>/results.txt exists and every function in it is OK (or
notes.txt explains the rest). A packet is taken when its answer directory exists (created by this script).
A packet whose run was stopped by the provider (stopped.txt, written by run_api.py) is waiting again. When a
waiting packet is handed out, a notes.txt an earlier run left in it (one that wrote no answers) moves to
notes_old.txt, so that it does not mark the new run's packet done. A packet taken with --agent carries agent.txt (when it was taken); --agent hands it out again until it is done once nothing
in it has changed for RESUME_MINUTES (so a session still working on it keeps it to itself), and the next session
goes on with it.
"""
import argparse
import os
import re
import time

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
RW = os.path.join(ROOT, 'build', 'rewrite')


STALE_MINUTES = 90   # a packet taken this long ago with nothing new written is offered again (a session died)
RESUME_MINUTES = 10  # an unfinished agent packet idle this long goes to the next agent session (--agent)
STOPPED = 'stopped.txt'
AGENT = 'agent.txt'
NOTES = 'notes.txt'
NOTES_OLD = 'notes_old.txt'


def idle_seconds(d):
    """Seconds since anything in the answer directory d changed."""
    newest = max([os.path.getmtime(os.path.join(d, f)) for f in os.listdir(d)] + [os.path.getmtime(d)])
    return time.time() - newest


def state(packet):
    d = os.path.join(RW, 'answers', packet)
    if not os.path.isdir(d) or os.path.exists(os.path.join(d, STOPPED)):
        return 'waiting'
    res = os.path.join(d, 'results.txt')
    if not os.path.exists(res):
        return 'waiting' if idle_seconds(d) > STALE_MINUTES * 60 else 'taken'
    results = {l.split('\t')[0]: l.split('\t')[1] for l in open(res, encoding='utf-8').read().split('\n')
               if '\t' in l}
    pk = os.path.join(RW, 'packets', packet + '.md')
    wanted = re.findall(r'^### (sub_[0-9A-F]{8})', open(pk, encoding='utf-8').read(), re.M) \
        if os.path.exists(pk) else []
    if all(results.get(n) == 'OK' for n in wanted) or os.path.exists(os.path.join(d, NOTES)):
        return 'done'
    return 'taken'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--status', action='store_true')
    ap.add_argument('--agent', action='store_true', help='for an agent session: resume its unfinished packet first')
    a = ap.parse_args()
    q = os.path.join(RW, 'queue.txt')
    packets = [l.strip() for l in open(q, encoding='utf-8')] if os.path.exists(q) else []
    packets = [p for p in packets if p]
    if a.status:
        from collections import Counter
        c = Counter(state(p) for p in packets)
        print(f'{len(packets)} packets: {c["done"]} done, {c["taken"]} in progress, {c["waiting"]} waiting')
        return
    if a.agent:
        for p in packets:
            d = os.path.join(RW, 'answers', p)
            if (os.path.exists(os.path.join(d, AGENT)) and state(p) != 'done'
                    and idle_seconds(d) >= RESUME_MINUTES * 60):
                os.utime(d, None)
                print(p)
                print(os.path.join(RW, 'packets', p + '.md'))
                print('(resumed: an earlier session left this packet unfinished; the answers it wrote are there)')
                return
    for p in packets:
        if state(p) == 'waiting':
            d = os.path.join(RW, 'answers', p)
            os.makedirs(d, exist_ok=True)
            if os.path.exists(os.path.join(d, STOPPED)):
                os.remove(os.path.join(d, STOPPED))
            if os.path.exists(os.path.join(d, NOTES)):   # (left by an earlier run: it would end the packet)
                os.replace(os.path.join(d, NOTES), os.path.join(d, NOTES_OLD))
            if a.agent:
                with open(os.path.join(d, AGENT), 'w', encoding='utf-8') as f:
                    f.write(time.strftime('%Y-%m-%d %H:%M') + '\n')
            os.utime(d, None)   # (taken now)
            print(p)
            print(os.path.join(RW, 'packets', p + '.md'))
            return
    print('DONE')


if __name__ == '__main__':
    main()
