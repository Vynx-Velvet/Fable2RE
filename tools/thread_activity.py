#!/usr/bin/env python3
"""From all-thread cdb dumps (tools/sample_thread.ps1 -AllThreads), report per
named thread how often it was found running (leaf frame not a wait/sleep/yield)
versus waiting, and its most common running leaf frames. Threads that are
"running" in most samples while the frame rate is low are the bottleneck.

Usage: python tools/thread_activity.py runs/samples_all_*.txt
"""
import collections
import glob
import re
import sys

HDR = re.compile(r"^\s*(\d+)\s+Id:\s+[0-9a-f.]+\s+Suspend:.*?(?:\"(.*)\")?\s*$")
FRAME = re.compile(r"((?:Fable2|rexruntime[a-z]*|ntdll|KERNELBASE|d3d12|dxgi|nvwgf2umx|SDL3\w*|ucrtbase\w*|VCRUNTIME\w*|win32u|USER32)!?[A-Za-z_:0-9<>~,. ]*)(?:\+0x[0-9a-f]+)?")
WAIT_LEAVES = ("NtWaitFor", "NtDelayExecution", "SleepEx", "NtYieldExecution", "SleepConditionVariable",
               "NtWaitForAlertByThreadId", "NtRemoveIoCompletion", "GetQueuedCompletionStatus",
               "NtUserMsgWaitForMultipleObjects", "NtUserGetMessage", "WaitForMultipleObjects",
               "WaitForSingleObject", "NtSignalAndWaitForSingleObject", "RtlWaitOnAddress")


def main(argv):
    paths = []
    for a in argv:
        paths.extend(sorted(glob.glob(a)) or [a])
    running = collections.Counter()
    seen = collections.Counter()
    leaves = collections.defaultdict(collections.Counter)
    samples = 0
    for p in paths:
        cur, cur_leaf = None, None
        with open(p, encoding="utf-8", errors="replace") as f:
            for line in f:
                if line.startswith("=== SAMPLE"):
                    samples += 1
                m = HDR.match(line)
                if m:
                    cur = (m.group(2) or f"thread{m.group(1)}").split(" (")[0]
                    cur_leaf = None
                    seen[cur] += 1
                    continue
                if cur is None or cur_leaf is not None:
                    continue
                fm = FRAME.search(line)
                if fm and "!" in fm.group(1):
                    cur_leaf = fm.group(1).strip()
                    if not any(w in cur_leaf for w in WAIT_LEAVES):
                        running[cur] += 1
                        leaves[cur][cur_leaf] += 1
    print(f"{samples} samples; per named thread: running / seen (top running leaves)")
    for name, n in sorted(seen.items(), key=lambda kv: -running[kv[0]]):
        if running[name] == 0:
            continue
        top = ", ".join(f"{fr.split('!')[-1][:40]}x{c}" for fr, c in leaves[name].most_common(3))
        print(f"  {running[name]:3d}/{n:<3d} {name:32s} {top}")
    idle = [name for name in seen if running[name] == 0]
    print(f"  always waiting: {len(idle)} threads")


if __name__ == "__main__":
    main(sys.argv[1:])
