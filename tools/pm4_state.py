"""Reference GPU register state from a capture's command bytes (debugging oracle for the native
renderer, which reads the device shadow instead). Interprets type-0 writes, SET_CONSTANT and
LOAD_ALU_CONSTANT from the command blobs (kind 6 before each call, kind 4 written by the call),
and diffs the state at a chosen draw against the device-shadow view.

Usage: python tools/pm4_state.py <capture dir> <event seq of a draw (before)> [--regs 0x2000-0x2400]
"""
import struct, sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from capture_reader import Capture

BLOCKS = [(10368, 0x2000, 16), (10444, 0x2100, 21), (10528, 0x2180, 5), (10548, 0x2200, 12),
          (10596, 0x2280, 21), (10680, 0x2300, 38), (10832, 0x2380, 8),
          (1152, 0x4800, 192), (1920, 0x4000, 1024), (6016, 0x4400, 1024), (10112, 0x4900, 40)]


def be(b, o=0):
    return struct.unpack_from('>I', b, o)[0]


def run(cap, stop_seq):
    regs = {}
    def exec_bytes(b):
        w = [be(b, 4 * i) for i in range(len(b) // 4)]
        i = 0
        while i < len(w):
            h = w[i]; t = h >> 30
            if t == 0:
                cnt = ((h >> 16) & 0x3FFF) + 1; base = h & 0x7FFF; one = (h >> 15) & 1
                for k in range(cnt):
                    if i + 1 + k < len(w): regs[base if one else base + k] = w[i + 1 + k]
                i += 1 + cnt
            elif t == 3:
                cnt = ((h >> 16) & 0x3FFF) + 1; op = (h >> 8) & 0x7F
                def base_for(ot):
                    idx = ot & 0x7FF; ty = (ot >> 16) & 0xFF
                    return {0: 0x4000, 1: 0x4800, 2: 0x4900, 3: 0x4908, 4: 0x2000}.get(ty, None), idx
                if op == 0x2D and i + 1 < len(w):
                    b0, idx = base_for(w[i + 1])
                    if b0 is not None:
                        for k in range(cnt - 1):
                            if i + 2 + k < len(w): regs[b0 + idx + k] = w[i + 2 + k]
                elif op == 0x2F and i + 3 < len(w):
                    addr = w[i + 1] & 0x3FFFFFFF; b0, idx = base_for(w[i + 2]); n = w[i + 3] & 0xFFF
                    data = cap.read_physical(addr, n * 4)
                    if b0 is not None and data:
                        for k in range(n): regs[b0 + idx + k] = be(data, 4 * k)
                i += 1 + cnt
            else:
                i += 1
    for idx, e in enumerate(cap.events):
        for k, a, b in e.blobs:
            if k == 6: exec_bytes(b)
        for k, a, b in e.blobs:
            if k == 4: exec_bytes(b)
        if e.seq == stop_seq:
            return regs, idx
    return regs, len(cap.events) - 1


def main(argv):
    cap = Capture(argv[0])
    seq = int(argv[1])
    lo, hi = 0x2000, 0x4A00
    if '--regs' in argv:
        r = argv[argv.index('--regs') + 1].split('-'); lo, hi = int(r[0], 16), int(r[1], 16)
    # The draw's own flush happens inside the call: include the call's commands (the after event).
    regs, idx = run(cap, seq + 1)
    dev = cap.device_at(idx)
    shadow = {}
    for off, base, n in BLOCKS:
        for k in range(n): shadow[base + k] = be(dev, off + 4 * k)
    diffs = 0
    for r in range(lo, hi):
        if r in regs and r in shadow and regs[r] != shadow[r]:
            diffs += 1
            if diffs <= 80: print('reg %04X  pm4 %08X  shadow %08X' % (r, regs[r], shadow[r]))
        elif r in regs and r not in shadow and r < 0x4000:
            print('reg %04X  pm4 %08X  (not in shadow)' % (r, regs[r]))
    print('%d differing registers in %04X-%04X' % (diffs, lo, hi))


if __name__ == '__main__':
    main(sys.argv[1:])


def compare_dump(capdir, seq, dump_path, lo=0x2000, hi=0x4A00):
    """Compare a renderer register dump (Fable2Replay --dump-seq) with the command-stream state."""
    cap = Capture(capdir)
    regs, idx = run(cap, seq + 1)
    d = open(dump_path, 'rb').read()
    mine = {0x2000 + i: struct.unpack_from('<I', d, 4 * i)[0] for i in range(len(d) // 4)}
    diffs = 0
    for r in range(lo, hi):
        if r in regs and regs[r] != mine.get(r):
            diffs += 1
            if diffs <= 100: print('reg %04X  pm4 %08X  native %08X' % (r, regs[r], mine.get(r, 0)))
    print('%d differing registers' % diffs)


IGNORE = set([0x2080, 0x2081, 0x2082, 0x2203, 0x2325, 0x2CC3, 0x3086] + list(range(0x2388, 0x23A0)))


def compare_all(capdir, dump_path, lo=0x2000, hi=0x4A00, show=40):
    """Compare every draw of a Fable2Replay --dump-all file with the command-stream state after the
    draw's own call (the 'after' event, seq + 1)."""
    cap = Capture(capdir)
    raw = open(dump_path, 'rb').read()
    rec = 4 + 0x2A00 * 4
    dumps = {}
    for off in range(0, len(raw) - rec + 1, rec):
        seq = struct.unpack_from('<I', raw, off)[0]
        dumps.setdefault(seq, raw[off + 4:off + rec])
    # One pass over the stream, snapshot at each dumped draw's after event.
    regs = {}
    results = []
    def exec_bytes(b):
        w = [be(b, 4 * i) for i in range(len(b) // 4)]
        i = 0
        while i < len(w):
            h = w[i]; t = h >> 30
            if t == 0:
                cnt = ((h >> 16) & 0x3FFF) + 1; base = h & 0x7FFF; one = (h >> 15) & 1
                for k in range(cnt):
                    if i + 1 + k < len(w): regs[base if one else base + k] = w[i + 1 + k]
                i += 1 + cnt
            elif t == 3:
                cnt = ((h >> 16) & 0x3FFF) + 1; op = (h >> 8) & 0x7F
                def base_for(ot):
                    return {0: 0x4000, 1: 0x4800, 2: 0x4900, 3: 0x4908, 4: 0x2000}.get((ot >> 16) & 0xFF), ot & 0x7FF
                if op == 0x2D and i + 1 < len(w):
                    b0, idx = base_for(w[i + 1])
                    if b0 is not None:
                        for k in range(cnt - 1):
                            if i + 2 + k < len(w): regs[b0 + idx + k] = w[i + 2 + k]
                elif op == 0x2F and i + 3 < len(w):
                    addr = w[i + 1] & 0x3FFFFFFF; b0, idx = base_for(w[i + 2]); n = w[i + 3] & 0xFFF
                    data = cap.read_physical(addr, n * 4)
                    if b0 is not None and data:
                        for k in range(n): regs[b0 + idx + k] = be(data, 4 * k)
                i += 1 + cnt
            else:
                i += 1
    for e in cap.events:
        for k, a, b in e.blobs:
            if k == 6: exec_bytes(b)
        for k, a, b in e.blobs:
            if k == 4: exec_bytes(b)
        if e.phase == 1 and (e.seq - 1) in dumps:
            mine = dumps[e.seq - 1]
            diff = [r for r in range(lo, hi) if r in regs and r not in IGNORE
                    and regs[r] != struct.unpack_from('<I', mine, 4 * (r - 0x2000))[0]]
            results.append((e.seq - 1, e.name, diff))
    bad = [x for x in results if x[2]]
    print('%d draws compared, %d with differences' % (len(results), len(bad)))
    import collections
    c = collections.Counter(r for x in bad for r in x[2])
    print('most frequent differing registers:', ' '.join('%04X:%d' % kv for kv in c.most_common(30)))
    for seq, name, diff in bad[:show]:
        print(seq, name, ' '.join('%04X' % r for r in diff[:16]), '...' if len(diff) > 16 else '')
