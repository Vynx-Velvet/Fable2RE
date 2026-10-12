#!/usr/bin/env python3
"""Estimate reverberation in the raw 5.1 dump (cvar audio_dump_raw) from the
decay after signal offsets. For every channel with signal, find moments where the
short-time envelope drops by >= 20 dB from a recent peak and measure how long it
takes (ms). Dry dialogue: tens of ms. Cave-like reverb: hundreds of ms.

Usage: python tools/analyze_reverb.py <dump.raw> [--skip S --seconds N] [--channel fc]
"""
import argparse

import numpy as np

CH, N, RATE = 6, 256, 48000
NAMES = ["fl", "fr", "fc", "lfe", "bl", "br"]


def load(path, skip_s, seconds):
    fb = CH * N * 4
    with open(path, "rb") as f:
        f.seek(int(skip_s * RATE / N) * fb)
        raw = f.read(int(seconds * RATE / N) * fb if seconds else -1)
    nf = len(raw) // fb
    a = np.frombuffer(raw[: nf * fb], dtype=">f4").reshape(nf, CH, N)
    return np.transpose(a, (1, 0, 2)).reshape(CH, nf * N).astype(np.float64)


def envelope_db(x, hop=240):  # 5 ms hops
    n = len(x) // hop
    e = np.sqrt((x[: n * hop].reshape(n, hop) ** 2).mean(axis=1)) + 1e-9
    return 20 * np.log10(e), hop


def decay_times(env_db, hop, drop_db=20.0, min_peak_db=-35.0, floor_db=-70.0):
    times = []
    i = 1
    while i < len(env_db) - 1:
        # local peak that is loud enough and followed by a drop
        if env_db[i] > min_peak_db and env_db[i] >= env_db[i - 1] and env_db[i] > env_db[i + 1]:
            target = env_db[i] - drop_db
            j = i + 1
            rose = False
            while j < len(env_db) and env_db[j] > target:
                if env_db[j] > env_db[i]:  # new louder onset: not an offset
                    rose = True
                    break
                j += 1
            if not rose and j < len(env_db) and env_db[i] - floor_db > drop_db:
                times.append((j - i) * hop / RATE * 1000.0)
                i = j
                continue
        i += 1
    return np.array(times)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("path")
    ap.add_argument("--skip", type=float, default=0)
    ap.add_argument("--seconds", type=float, default=0)
    ap.add_argument("--drop", type=float, default=20.0)
    args = ap.parse_args()
    ch = load(args.path, args.skip, args.seconds)
    print(f"{ch.shape[1] / RATE:.1f}s loaded; decay-to-{args.drop:.0f}dB times after offsets (ms):")
    for i, name in enumerate(NAMES):
        x = ch[i]
        if np.abs(x).max() < 1e-4:
            print(f"  {name:4s} silent")
            continue
        env, hop = envelope_db(x)
        t = decay_times(env, hop, args.drop)
        if len(t) == 0:
            print(f"  {name:4s} no clean offsets found")
            continue
        q = np.percentile(t, [10, 50, 90])
        print(f"  {name:4s} offsets={len(t):4d}  p10={q[0]:6.0f}  median={q[1]:6.0f}  p90={q[2]:6.0f}  max={t.max():6.0f}")


if __name__ == "__main__":
    main()
