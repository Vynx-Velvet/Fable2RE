#!/usr/bin/env python3
"""Analyse the raw 5.1 frames dumped by the SDL audio driver (cvar audio_dump_raw).

Layout per frame: 6 channels x 256 samples, sequential (planar), big-endian float32,
channel order fl, fr, fc, lfe, bl, br. Reports per-channel RMS, the cross-correlation
delay between the front and the rear channels, and the strongest echo (autocorrelation
peak) inside the front-left channel itself. If the echo is already inside fl, the
game's own mix (recompiled DSP) produces it; if it only appears in bl/br, it is the
surround/reverb bus and the output fold decides how loud it is.

Usage: python tools/analyze_audio_dump.py <dump.raw> [--seconds 20 --skip 0]
"""
import argparse

import numpy as np

CH = 6
N = 256
RATE = 48000
NAMES = ["fl", "fr", "fc", "lfe", "bl", "br"]


def load(path, skip_s, seconds):
    frame_bytes = CH * N * 4
    with open(path, "rb") as f:
        f.seek(int(skip_s * RATE / N) * frame_bytes)
        raw = f.read(int(seconds * RATE / N) * frame_bytes)
    nframes = len(raw) // frame_bytes
    a = np.frombuffer(raw[: nframes * frame_bytes], dtype=">f4").reshape(nframes, CH, N)
    return np.transpose(a, (1, 0, 2)).reshape(CH, nframes * N).astype(np.float32)


def xcorr_delay(a, b, max_lag):
    # Positive lag means b lags a (b is a delayed copy of a).
    a = a - a.mean()
    b = b - b.mean()
    best_lag, best_val = 0, 0.0
    denom = np.sqrt((a * a).sum() * (b * b).sum()) + 1e-9
    for lag in range(0, max_lag, 8):
        v = float((a[: len(a) - lag] * b[lag:]).sum()) / denom
        if abs(v) > abs(best_val):
            best_lag, best_val = lag, v
    return best_lag, best_val


def autocorr_peaks(x, min_lag, max_lag):
    x = x - x.mean()
    e = float((x * x).sum()) + 1e-9
    out = []
    for lag in range(min_lag, max_lag, 16):
        v = float((x[: len(x) - lag] * x[lag:]).sum()) / e
        out.append((v, lag))
    out.sort(reverse=True)
    return out[:5]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("path")
    ap.add_argument("--seconds", type=float, default=20)
    ap.add_argument("--skip", type=float, default=0)
    args = ap.parse_args()
    ch = load(args.path, args.skip, args.seconds)
    dur = ch.shape[1] / RATE
    print(f"loaded {dur:.1f}s ({ch.shape[1]} samples/channel) from {args.path}")
    rms = np.sqrt((ch * ch).mean(axis=1))
    peak = np.abs(ch).max(axis=1)
    for i, n in enumerate(NAMES):
        print(f"  {n:4s} rms={rms[i]:.4f} peak={peak[i]:.3f}")
    max_lag = int(0.5 * RATE)
    for i, n in ((4, "bl"), (5, "br"), (2, "fc")):
        lag, v = xcorr_delay(ch[0] if i != 5 else ch[1], ch[i], max_lag)
        print(f"  front vs {n}: best lag {lag / RATE * 1000:.1f} ms corr {v:+.3f}")
    print("  autocorrelation peaks in fl (20 ms .. 500 ms):")
    for v, lag in autocorr_peaks(ch[0], int(0.02 * RATE), max_lag):
        print(f"    lag {lag / RATE * 1000:6.1f} ms  corr {v:+.3f}")
    print("  autocorrelation peaks in fc (20 ms .. 500 ms):")
    for v, lag in autocorr_peaks(ch[2], int(0.02 * RATE), max_lag):
        print(f"    lag {lag / RATE * 1000:6.1f} ms  corr {v:+.3f}")


if __name__ == "__main__":
    main()
