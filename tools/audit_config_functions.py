#!/usr/bin/env python3
"""
Audit the [functions] entries of Fable2_config.toml against the loaded XEX image.

Input: a raw dump of guest memory 0x82000000..0x83620000 (see runs/cdb_dumpimage.txt),
which is the PE image the runtime mapped. From it we read the PE exception directory
(.pdata, IMAGE_CE_RUNTIME_FUNCTION entries, big-endian) to get authoritative function
starts and lengths, and classify every config entry:

  PDATA      address is a .pdata function start          -> trustworthy
  INSIDE     address falls strictly inside a .pdata range -> bogus (splits a function)
  ORPHAN     address is in no .pdata range               -> check instruction heuristics
             (prologue-looking start preceded by blr/b/padding = plausible leaf/thunk)

Usage:
  python tools/audit_config_functions.py <image.bin> <config.toml> [--write-clean out.toml]
"""
import re
import struct
import sys
from bisect import bisect_right

IMAGE_BASE = 0x82000000


def u32be(b, off):
    return struct.unpack_from(">I", b, off)[0]


def u32le(b, off):
    return struct.unpack_from("<I", b, off)[0]


def load_pdata(img):
    e_lfanew = u32le(img, 0x3C)
    nt = e_lfanew
    assert img[nt:nt + 4] == b"PE\0\0", "not a PE image at 0x82000000"
    opt = nt + 24
    magic = struct.unpack_from("<H", img, opt)[0]
    dd_off = opt + (0x60 if magic == 0x10B else 0x70)
    exc_rva = u32le(img, dd_off + 3 * 8)
    exc_size = u32le(img, dd_off + 3 * 8 + 4)
    funcs = []
    for i in range(exc_size // 8):
        begin = u32be(img, exc_rva + i * 8)
        data = u32be(img, exc_rva + i * 8 + 4)
        # IMAGE_CE_RUNTIME_FUNCTION: FunctionLength is bits 8..29 (22 bits), in instructions
        length = ((data >> 8) & 0x3FFFFF) * 4
        if length == 0:
            length = 4
        funcs.append((begin, begin + length))
    funcs.sort()
    return funcs


def classify(addr, starts, funcs):
    i = bisect_right(starts, addr) - 1
    if i >= 0:
        b, e = funcs[i]
        if addr == b:
            return "PDATA", (b, e)
        if b < addr < e:
            return "INSIDE", (b, e)
    return "ORPHAN", None


def insn(img, addr):
    off = addr - IMAGE_BASE
    if off < 0 or off + 4 > len(img):
        return None
    return u32be(img, off)


def looks_like_start(img, addr):
    prev = insn(img, addr - 4)
    cur = insn(img, addr)
    if cur is None:
        return False, "out of image"
    prev_ok = prev in (0x4E800020, 0x00000000, 0x60000000) or (prev is not None and (prev >> 26) == 18 and (prev & 1) == 0)
    op = cur >> 26
    cur_ok = cur == 0x7D8802A6 or (op == 18 and (cur & 1) == 0) or op in (36, 37, 62, 15, 14, 44, 32)  # mflr r12 / b / stw / stwu / std / addis / addi / sth / lwz
    why = f"prev={prev:08X} cur={cur:08X}"
    return (prev_ok and cur_ok), why


def parse_config(path):
    entries = []
    with open(path, encoding="utf-8") as f:
        for ln, line in enumerate(f, 1):
            m = re.match(r"^\s*0[xX]([0-9A-Fa-f]{8})\s*=\s*\{(.*)\}", line)
            if not m:
                continue
            addr = int(m.group(1), 16)
            body = m.group(2)
            name = re.search(r'name\s*=\s*"([^"]*)"', body)
            size = re.search(r"size\s*=\s*(0[xX][0-9A-Fa-f]+|\d+)", body)
            parent = re.search(r"parent\s*=\s*(0[xX][0-9A-Fa-f]+)", body)
            entries.append({
                "line": ln, "addr": addr, "raw": line.rstrip("\n"),
                "name": name.group(1) if name else None,
                "size": int(size.group(1), 0) if size else None,
                "parent": int(parent.group(1), 16) if parent else None,
            })
    return entries


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        sys.exit(1)
    img = open(sys.argv[1], "rb").read()
    entries = parse_config(sys.argv[2])
    write_clean = None
    if "--write-clean" in sys.argv:
        write_clean = sys.argv[sys.argv.index("--write-clean") + 1]

    funcs = load_pdata(img)
    starts = [b for b, _ in funcs]
    print(f"pdata functions: {len(funcs)}  config entries: {len(entries)}")

    counts = {}
    keep = []
    for e in entries:
        kind, rng = classify(e["addr"], starts, funcs)
        note = ""
        ok = kind == "PDATA"
        if kind == "PDATA" and e["size"] and rng and e["size"] != rng[1] - rng[0]:
            note = f"size {e['size']:#x} != pdata {rng[1]-rng[0]:#x}"
        if kind == "ORPHAN":
            plausible, why = looks_like_start(img, e["addr"])
            ok = plausible
            note = ("plausible " if plausible else "IMPLAUSIBLE ") + why
        if kind == "INSIDE":
            note = f"inside {rng[0]:08X}-{rng[1]:08X}"
        counts[(kind, ok)] = counts.get((kind, ok), 0) + 1
        tag = "keep" if ok else "DROP"
        print(f"{tag:4} {kind:6} 0x{e['addr']:08X} {e['name'] or '':32} {note}")
        if ok:
            keep.append(e)

    print("\nsummary:")
    for (kind, ok), n in sorted(counts.items()):
        print(f"  {kind:6} {'keep' if ok else 'drop'}: {n}")

    if write_clean:
        with open(sys.argv[2], encoding="utf-8") as f:
            lines = f.read().split("\n")
        keep_lines = {e["line"] for e in keep}
        drop_lines = {e["line"] for e in entries} - keep_lines
        out = []
        for i, line in enumerate(lines, 1):
            if i in drop_lines:
                out.append("# dropped by audit_config_functions.py (not a function start in this XEX): " + line)
            else:
                out.append(line)
        with open(write_clean, "w", encoding="utf-8") as f:
            f.write("\n".join(out))
        print(f"\nwrote {write_clean}: kept {len(keep)}, dropped {len(drop_lines)}")


if __name__ == "__main__":
    main()
