#!/usr/bin/env python3
"""Summarise a burst of window captures: brightness, frame-to-frame change,
black frames, and a crude "tearing/garbage" indicator (fraction of pixels
that are pure magenta/green/black rows), so visual glitches can be spotted
without eyeballing every frame.

Usage: python tools/analyze_frames.py <png> [<png> ...]
       python tools/analyze_frames.py runs/burst/burst1_*.png
"""
import glob
import sys

import numpy as np
from PIL import Image

TITLE_BAR = 32  # window chrome rows to skip


def load(path):
    img = np.asarray(Image.open(path).convert("RGB"), dtype=np.float32)
    return img[TITLE_BAR:, :, :]


def main(argv):
    paths = []
    for a in argv:
        paths.extend(sorted(glob.glob(a)) or [a])
    prev = None
    print(f"{'frame':40s} {'mean':>6s} {'std':>6s} {'diff':>6s} {'black%':>7s} {'sat%':>6s}")
    for p in paths:
        img = load(p)
        gray = img.mean(axis=2)
        mean, std = gray.mean(), gray.std()
        black = (gray < 4).mean() * 100.0
        mx, mn = img.max(axis=2), img.min(axis=2)
        sat = ((mx - mn) > 200).mean() * 100.0  # fully saturated pixels (debug colours)
        diff = float(np.abs(gray - prev).mean()) if prev is not None and prev.shape == gray.shape else 0.0
        flags = []
        if black > 95:
            flags.append("BLACK")
        if prev is not None and diff > 60:
            flags.append("BIG-CHANGE")
        if sat > 5:
            flags.append("SATURATED")
        name = p.replace("\\", "/").split("/")[-1]
        print(f"{name:40s} {mean:6.1f} {std:6.1f} {diff:6.1f} {black:7.1f} {sat:6.1f} {' '.join(flags)}")
        prev = gray


if __name__ == "__main__":
    main(sys.argv[1:])
