"""The check for answers written in an agent session (tools/rewrite/AGENT.md): the same check run_api.py makes.

    python tools/rewrite/agent_check.py <packet>          check every answer of the packet
    python tools/rewrite/agent_check.py <packet> --done   the same, then write notes.txt with what still fails:
                                                          the packet counts as done and the next one is offered

Runs check.py with the promotion check (--outputs, profiles 0-5: what promote.py checks), counts an answer that
is still the lifted code (90% of its lines unchanged, for functions over 15 lines) as NOT REWRITTEN, and prints
one line per function with a hint for each failure. The verdicts are in results.txt of the answer directory
(tools/rewrite/apply.py takes the OK ones, as from run_api.py). While another check runs (run_api.py,
promote.py, review_api.py: one tester build directory) it waits.

Every check is logged in checks.log of the answer directory. A packet stops by itself (notes.txt, as --done)
when every function that still fails has failed MAX_FAILED_CHECKS checks, or after MAX_FIX_MINUTES of fixing
(the time between its checks; a gap of more than BREAK_MINUTES is a session break and does not count): in an
agent session most functions pass within minutes and the last few take an hour or more, so the session goes
on with the next packet and the hard functions wait for a later pass.
"""
import argparse
import os
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import run_api  # noqa: E402  (run_check, guard, hint, parse_packet: the API runner's check)

LOG = 'checks.log'
MAX_FAILED_CHECKS = 3   # a function that failed this many checks is left
MAX_FIX_MINUTES = 15    # fixing time per packet, after its first check
BREAK_MINUTES = 30      # a longer gap between two checks is a session break
JOBS = 4                # test programs built at once (8 cores; run_api.py's own checks build 2)


def history(outdir):
    """[(time, [failing functions])] of the packet's earlier checks."""
    out = []
    path = os.path.join(outdir, LOG)
    if os.path.exists(path):
        for line in open(path, encoding='utf-8'):
            c = line.rstrip('\n').split('\t')
            if len(c) >= 2:
                out.append((time.mktime(time.strptime(c[0], '%Y-%m-%d %H:%M:%S')), c[2].split() if len(c) > 2 else []))
    return out


def fix_minutes(checks):
    """Minutes of fixing between the checks (gaps over BREAK_MINUTES left out)."""
    gaps = [b[0] - a[0] for a, b in zip(checks, checks[1:])]
    return sum(g for g in gaps if g <= BREAK_MINUTES * 60) / 60


def write_notes(outdir, funcs, missing, results, why_stopped):
    with open(os.path.join(outdir, 'notes.txt'), 'w', encoding='utf-8', newline='\n') as f:
        f.write(f'agent session (tools/rewrite/AGENT.md), promotion check; {why_stopped}\n')
        for name, _ in funcs:
            why = 'no answer' if name in missing else results.get(name, 'not tested')
            if why != 'OK':
                f.write(f'{name}\t{why}\n')


def main():
    ap = argparse.ArgumentParser(description='Check an agent session\'s answers for one packet (see the docstring).')
    ap.add_argument('packet', help='packet name, as next_packet.py prints it')
    ap.add_argument('--done', action='store_true', help='after the check, write notes.txt with the functions that '
                                                        'still fail (the packet then counts as done)')
    a = ap.parse_args()
    path = os.path.join(ROOT, 'build', 'rewrite', 'packets', a.packet + '.md')
    if not os.path.exists(path):
        sys.exit(f'no packet {a.packet} (build/rewrite/packets/{a.packet}.md)')
    outdir = os.path.join(ROOT, 'build', 'rewrite', 'answers', a.packet)
    funcs = run_api.parse_packet(path)
    missing = [n for n, _ in funcs if not os.path.exists(os.path.join(outdir, n + '.cpp'))]
    if len(missing) == len(funcs):
        sys.exit(f'no answers yet: write build/rewrite/answers/{a.packet}/sub_X.cpp for the packet\'s functions first')
    print(f'checking {len(funcs) - len(missing)} answers of {a.packet} (promotion check, profiles 0-5; '
          'about a minute) ...', flush=True)
    results, output = run_api.run_check(a.packet, jobs=JOBS)
    results = run_api.guard(outdir, funcs, results)
    if not results:
        print('the check gave no results; its output ends with:\n' + output[-1500:])
    failing = [n for n, _ in funcs if n not in missing and results.get(n, 'not tested') != 'OK']
    if results:
        with open(os.path.join(outdir, LOG), 'a', encoding='utf-8', newline='\n') as f:
            f.write(f'{time.strftime("%Y-%m-%d %H:%M:%S")}\t{len(funcs) - len(failing) - len(missing)}/{len(funcs)}'
                    f'\t{" ".join(failing)}\n')
    checks = history(outdir)
    failed = {n: sum(1 for _, fails in checks if n in fails) for n in failing}
    minutes = fix_minutes(checks)
    ok = 0
    for name, _ in funcs:
        why = 'no answer yet' if name in missing else results.get(name, 'not tested')
        if why == 'OK':
            ok += 1
            print(f'OK    {name}')
            continue
        print(f'FAIL  {name}: {why[:400]}')
        if name not in missing:
            print(f'      hint: {run_api.hint(why)}')
            print(f'      (failed {failed[name]} of at most {MAX_FAILED_CHECKS} checks)')
    print(f'{ok} of {len(funcs)} OK')
    stop = ''
    if failing and not missing and all(c >= MAX_FAILED_CHECKS for c in failed.values()):
        stop = f'every failing function failed {MAX_FAILED_CHECKS} checks'
    elif failing and minutes >= MAX_FIX_MINUTES:
        stop = f'{minutes:.0f} minutes of fixing (limit {MAX_FIX_MINUTES})'
    if a.done or (stop and ok < len(funcs)):
        write_notes(outdir, funcs, missing, results, stop or 'stopped with --done')
        if stop:
            print(f'limit reached ({stop}): the failing functions are left for a later pass, notes.txt written.')
        print('The packet counts as done. Next: python tools/rewrite/next_packet.py --agent')
    elif ok == len(funcs):
        print('packet done. Next: python tools/rewrite/next_packet.py --agent')
    else:
        left = [n for n in failing if failed[n] < MAX_FAILED_CHECKS]
        print(f'fix {", ".join(left) if left else "the failures"} and run this again '
              f'({max(0, MAX_FIX_MINUTES - minutes):.0f} of {MAX_FIX_MINUTES} minutes of fixing left for this packet)')


if __name__ == '__main__':
    main()
