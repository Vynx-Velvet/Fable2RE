#!/usr/bin/env python3
"""Tabulate the periodic 5-second diagnostics the SDK logs at debug level:
GPU swaps/FPS, guest audio callback timing, SDL audio queue, XMA decoder.

Usage: python tools/summarize_run.py <job_or_fable2.log> [--all]
"""
import re
import sys

PATTERNS = {
    "gpu": re.compile(r"GPU 5s stats: swaps=(\d+) avg_fps=([\d.]+) max_frame_gap=(\d+)ms(?: draws=(\d+))?(?: skipped=(\d+) issued=(\d+))?(?: repeated=(\d+))?"),
    "cb": re.compile(r"Audio callback 5s stats: calls=(\d+) avg=([\d.]+)ms max=([\d.]+)ms busy=(\d+)%"),
    "sdl": re.compile(r"SDL audio 5s stats: submitted=(\d+) played=(\d+) silence_fills=(\d+) queued_now=(\d+)"),
    "xma": re.compile(r"XMA 5s stats: work_units=(\d+) enabled_contexts=(\d+)"),
    "mex": re.compile(r"Memexport 5s stats: draws=(\d+) readbacks=(\d+) full_invalidations=(\d+)"),
    "flt": re.compile(r"Fault 5s stats: mmio=(\d+) page_protect=(\d+) spurious=(\d+)"),
}


def main(argv):
    path = argv[0]
    rows = []  # (line_no, kind, values)
    with open(path, encoding="utf-8", errors="replace") as f:
        for i, line in enumerate(f, 1):
            for kind, pat in PATTERNS.items():
                m = pat.search(line)
                if m:
                    rows.append((i, kind, m.groups()))
                    break
    if not rows:
        print("no 5s stats found (needs log_level=debug and the instrumented runtime)")
        return
    print(f"{'line':>7s}  {'kind':4s}  values")
    for i, kind, vals in rows:
        if kind == "gpu":
            v = f"swaps={vals[0]:>4s} fps={vals[1]:>5s} max_gap={vals[2]:>4s}ms draws={vals[3] or '?'} skipped={vals[4] or '?'} issued={vals[5] or '?'} repeated={vals[6] or '?'}"
        elif kind == "cb":
            v = f"calls={vals[0]:>4s} avg={vals[1]:>6s}ms max={vals[2]:>7s}ms busy={vals[3]:>3s}%"
        elif kind == "sdl":
            v = f"submitted={vals[0]:>4s} played={vals[1]:>4s} silence={vals[2]:>4s} queued={vals[3]}"
        elif kind == "mex":
            v = f"memexport draws={vals[0]:>5s} readbacks={vals[1]:>5s} full_invalidations={vals[2]}"
        elif kind == "flt":
            v = f"faults mmio={vals[0]:>5s} page_protect={vals[1]:>5s} spurious={vals[2]}"
        else:
            v = f"work_units={vals[0]:>5s} enabled={vals[1]}"
        print(f"{i:7d}  {kind:4s}  {v}")


if __name__ == "__main__":
    main(sys.argv[1:])
