#!/usr/bin/env python3
"""Aggregate several cdb `~*kb` dumps (tools/stack_snapshots.ps1)
into a poor-man's sampling profile: for each interesting thread, count how often
each frame appears (leaf frames first), so the hot guest functions stand out.

Usage: python tools/aggregate_stacks.py runs/stacks_prof1_*.txt [--threads GameThread,"3D Engine"] [--depth 6]
"""
import argparse
import collections
import glob
import re

HDR = re.compile(r"^\s*(\d+)\s+Id:\s+[0-9a-f.]+\s+Suspend:.*?(?:\"(.*)\")?\s*$")
FRAME = re.compile(r"((?:Fable2|rexruntime[a-z]*|ntdll|KERNELBASE|d3d12|dxgi|nvwgf2umx|SDL3\w*|ucrtbase\w*|VCRUNTIME\w*)!?[A-Za-z_:0-9<>~,. ]*(?:\+0x[0-9a-f]+)?)")
DEFAULT_THREADS = ["GameThread", "3D Engine", "GPU Commands", "Audio Worker", "Texture Streamer", "XrnmThread"]


def parse(path):
    threads = {}
    cur = None
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = HDR.match(line)
            if m:
                base = m.group(2) or f"thread{m.group(1)}"
                cur = base
                k = 1
                while cur in threads:  # repeated blocks (sample_thread.ps1) get unique keys
                    k += 1
                    cur = f"{base}#{k}"
                threads[cur] = []
                continue
            if cur is None:
                continue
            fm = FRAME.search(line)
            if fm:
                name = fm.group(1).strip()
                name = re.sub(r"\+0x[0-9a-f]+$", "", name)  # drop offsets
                if not threads[cur] or threads[cur][-1] != name:
                    threads[cur].append(name)
    return threads


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("files", nargs="+")
    ap.add_argument("--threads", default=",".join(DEFAULT_THREADS))
    ap.add_argument("--depth", type=int, default=6, help="frames from the leaf to count")
    args = ap.parse_args()
    paths = []
    for a in args.files:
        paths.extend(sorted(glob.glob(a)) or [a])
    wanted = [t.strip() for t in args.threads.split(",")]
    leaf = collections.defaultdict(collections.Counter)
    anywhere = collections.defaultdict(collections.Counter)
    samples = collections.Counter()
    for p in paths:
        for tname, frames in parse(p).items():
            key = next((w for w in wanted if tname.startswith(w)), None)
            if not key or not frames:
                continue
            samples[key] += 1
            leaf[key][frames[0]] += 1
            for fr in frames[: args.depth]:
                anywhere[key][fr] += 1
    for key in wanted:
        if samples[key] == 0:
            continue
        print(f"\n=== {key}: {samples[key]} samples ===")
        print("  leaf frames:")
        for fr, n in leaf[key].most_common(8):
            print(f"    {n:3d}  {fr}")
        print(f"  frames within top {args.depth}:")
        for fr, n in anywhere[key].most_common(12):
            print(f"    {n:3d}  {fr}")


if __name__ == "__main__":
    main()
