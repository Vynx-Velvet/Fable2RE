#!/usr/bin/env python3
"""Turn the in-process sampler's "Sampler 10s" log lines (module+offset percentages)
into function names using llvm-symbolizer and the PDBs next to the binaries.

Usage: python tools/symbolize_samples.py <fable2.log> <build dir> [--top 40]
Aggregates all windows of the last session (weighted by their sample counts) and
prints the hottest self (leaf) and inclusive frames.
"""
import collections
import os
import re
import shutil
import struct
import subprocess
import sys

LINE = re.compile(r"Sampler 10s '([^']+)': (\d+) samples \((\d+) unwound\) \| self:(.*)$")
INCL = re.compile(r"Sampler 10s '([^']+)': inclusive:(.*)$")
ENTRY = re.compile(r"(\S+?)\+0x([0-9a-f]+)=([\d.]+)%")
SYMBOLIZER = (shutil.which("llvm-symbolizer")
              or os.path.join(os.environ.get("LLVM_ROOT", r"C:\Program Files\LLVM"), "bin", "llvm-symbolizer.exe"))


def image_base(path):
    with open(path, "rb") as f:
        d = f.read(0x400)
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    magic = struct.unpack_from("<H", d, pe + 24)[0]
    return struct.unpack_from("<Q", d, pe + 24 + 24)[0] if magic == 0x20B else struct.unpack_from("<I", d, pe + 24 + 28)[0]


def symbolize(module_path, offsets):
    base = image_base(module_path)
    inp = "".join(f"0x{base + o:x}\n" for o in offsets)
    out = subprocess.run([SYMBOLIZER, f"--obj={module_path}", "--inlining=false", "--demangle"],
                         input=inp, capture_output=True, text=True).stdout
    blocks = [b for b in out.strip().split("\n\n")]
    names = {}
    for o, b in zip(offsets, blocks):
        lines = b.split("\n")
        fn = lines[0].strip() if lines else "?"
        loc = lines[1].strip() if len(lines) > 1 else ""
        loc = os.path.basename(loc.split(":")[0]) + ":" + loc.split(":")[1] if ":" in loc else loc
        names[o] = f"{fn} ({loc})" if loc else fn
    return names


def main(argv):
    log, build_dir = argv[0], argv[1]
    top = int(argv[argv.index("--top") + 1]) if "--top" in argv else 40
    thread = argv[argv.index("--thread") + 1] if "--thread" in argv else None
    text = open(log, encoding="utf-8", errors="replace").read()
    session_start = text.rfind("Sampler: profiling thread") if "Sampler: profiling thread" in text else 0
    text = text[session_start:] if session_start >= 0 else text
    self_w, incl_w, total = collections.Counter(), collections.Counter(), 0
    for line in text.splitlines():
        m = LINE.search(line)
        if m and thread and m.group(1) != thread:
            continue
        if m:
            n = int(m.group(2))
            total += n
            for mod, off, pct in ENTRY.findall(m.group(4)):
                self_w[(mod, int(off, 16))] += float(pct) * n / 100.0
            continue
        m = INCL.search(line)
        if m and (not thread or m.group(1) == thread):
            # inclusive lines follow their self line; reuse its sample count
            for mod, off, pct in ENTRY.findall(m.group(2)):
                incl_w[(mod, int(off, 16))] += float(pct) * n / 100.0
    if not total:
        sys.exit("no Sampler lines found")
    modules = {}
    for (mod, off) in list(self_w) + list(incl_w):
        modules.setdefault(mod, set()).add(off)
    names = {}
    for mod, offs in modules.items():
        path = os.path.join(build_dir, mod)
        if not os.path.exists(path):
            for o in offs:
                names[(mod, o)] = f"{mod}+0x{o:x}"
            continue
        offs = sorted(offs)
        for o, nm in symbolize(path, offs).items():
            names[(mod, o)] = nm
    # Fold addresses into functions.
    def fold(counter):
        byfn = collections.Counter()
        for key, w in counter.items():
            fn = names.get(key, f"{key[0]}+0x{key[1]:x}").split(" (")[0]
            byfn[fn] += w
        return byfn
    print(f"{total} samples over the session")
    print("\n=== self (leaf) time by function ===")
    for fn, w in fold(self_w).most_common(top):
        print(f"{100.0 * w / total:6.1f}%  {fn}")
    print("\n=== inclusive time by function ===")
    for fn, w in fold(incl_w).most_common(top):
        print(f"{100.0 * w / total:6.1f}%  {fn}")


if __name__ == "__main__":
    main(sys.argv[1:])
