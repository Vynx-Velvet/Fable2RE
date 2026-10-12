"""Reader for D3D frame captures written by Fable2Recomp/src/d3d_capture.cpp (F9 in game).

    python tools/capture_reader.py <capture dir> [--stats] [--event N] [--draws]

Library use: Capture(dir) gives .events (list of Event), .device_at(seq) (device bytes as of
an event), .read_virtual(addr, n) / .read_physical(addr, n) against the frame-start memory dump
plus the ranges recorded during the frame.
"""
import os, struct, sys
from collections import Counter

FN = ["DrawIndexedVertices", "DrawVertices", "BeginIndexedVertices", "BeginVertices", "DrawRect2D",
      "DrawIndexedVertices2", "Resolve", "ClearF", "Swap", "CommitShaders", "CommitRenderStates",
      "GameStateFlush", "GpuLoadShaders", "GpuLoadShaderConstantF4"]
KIND = {1: 'device', 2: 'virtual', 3: 'physical', 4: 'commands', 5: 'updata', 6: 'gapcmds'}
EVH = struct.Struct('<4I8IdIIII')
BLH = struct.Struct('<4I')
DEVICE_SIZE = 16384


class Event:
    __slots__ = ('fn', 'phase', 'seq', 'r', 'f1', 'sp', 'frame', 'blobs')

    @property
    def name(self):
        return FN[self.fn]


class Capture:
    def __init__(self, d):
        self.dir = d
        self.regions = []  # (space, guest, size, file_offset)
        for line in open(os.path.join(d, 'memory_index.txt')):
            if line.startswith('#'):
                continue
            sp, a, n, o = line.split()
            self.regions.append((sp, int(a, 16), int(n, 16), int(o, 16)))
        self.mem = open(os.path.join(d, 'memory.bin'), 'rb')
        self.events = []
        data = open(os.path.join(d, 'events.bin'), 'rb').read()
        pos = 0
        while pos + EVH.size <= len(data):
            v = EVH.unpack_from(data, pos)
            pos += EVH.size
            if v[0] != 0x31545645:
                raise ValueError('bad event magic at %d' % pos)
            e = Event()
            e.fn, e.phase, e.seq = v[1], v[2], v[3]
            e.r = list(v[4:12])
            e.f1, e.sp, e.frame, nblobs = v[12], v[13], v[14], v[15]
            e.blobs = []
            for _ in range(nblobs):
                kind, addr, size, _r = BLH.unpack_from(data, pos)
                pos += BLH.size
                e.blobs.append((kind, addr, data[pos:pos + size]))
                pos += size
            self.events.append(e)
        # device state reconstruction
        self._dev_cache = {}

    def device_at(self, index):
        """Device bytes after applying device blobs of events[0..index]."""
        dev = bytearray(DEVICE_SIZE)
        for e in self.events[:index + 1]:
            for kind, addr, b in e.blobs:
                if kind == 1:
                    dev[addr:addr + len(b)] = b
        return bytes(dev)

    def _dump(self, space, addr, n):
        for sp, a, size, off in self.regions:
            if sp == space and a <= addr and addr + n <= a + size:
                self.mem.seek(off + addr - a)
                return self.mem.read(n)
        return None

    def read_physical(self, addr, n, upto=None):
        addr &= 0x1FFFFFFF
        best = None
        for e in (self.events if upto is None else self.events[:upto + 1]):
            for kind, a, b in e.blobs:
                if kind == 3 and a <= addr and addr + n <= a + len(b):
                    best = b[addr - a:addr - a + n]
        return best if best is not None else self._dump('P', addr, n)

    def read_virtual(self, addr, n, upto=None):
        if addr >= 0xA0000000:
            # 0xA0000000/0xC0000000/0xE0000000 views alias physical memory; the 0xE0000000 heap is
            # shifted by 0x1000 (memory_index.txt header: E0000000 -> ...E0001000).
            off = 0x1000 if addr >= 0xE0000000 else 0
            return self.read_physical((addr & 0x1FFFFFFF) + off, n, upto)
        best = None
        for e in (self.events if upto is None else self.events[:upto + 1]):
            for kind, a, b in e.blobs:
                if kind in (2, 5) and a <= addr and addr + n <= a + len(b):
                    best = b[addr - a:addr - a + n]
        return best if best is not None else self._dump('V', addr, n)


def be32(b, o=0):
    return struct.unpack_from('>I', b, o)[0]


def main(argv):
    cap = Capture(argv[0])
    evs = cap.events
    print('%d events, %d memory regions (%d MB)' % (len(evs), len(cap.regions),
                                                    sum(r[2] for r in cap.regions) >> 20))
    c = Counter((e.name, e.phase) for e in evs)
    for (n, ph), k in sorted(c.items()):
        print('  %-22s %s %d' % (n, 'after' if ph else 'before', k))
    kinds = Counter()
    for e in evs:
        for kind, a, b in e.blobs:
            kinds[KIND.get(kind, kind)] += len(b)
    print('blob bytes:', {k: v for k, v in kinds.items()})
    if '--event' in argv:
        i = int(argv[argv.index('--event') + 1])
        e = evs[i]
        print(e.seq, e.name, e.phase, ['%08X' % x for x in e.r], e.f1)
        for kind, a, b in e.blobs:
            print('   %-8s %08X %d  %s' % (KIND.get(kind, kind), a, len(b), b[:32].hex()))


if __name__ == '__main__':
    main(sys.argv[1:])
