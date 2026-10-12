"""Pixel statistics for the (uncompressed) PNGs Fable2Replay writes. Usage: png_stats.py <dir>"""
import glob, os, struct, sys, zlib
def load(f):
    d = open(f, 'rb').read()
    w, h = struct.unpack('>II', d[16:24])
    idat = b''; p = 8
    while p < len(d):
        n = struct.unpack('>I', d[p:p + 4])[0]; t = d[p + 4:p + 8]
        if t == b'IDAT': idat += d[p + 8:p + 8 + n]
        p += 12 + n
    return w, h, zlib.decompress(idat)
for f in sorted(glob.glob(os.path.join(sys.argv[1] if len(sys.argv) > 1 else '.', '*.png'))):
    w, h, raw = load(f)
    stride = w * 4 + 1; s = [0, 0, 0]; nz = 0; n = 0
    for y in range(0, h, 4):
        row = raw[y * stride + 1:(y + 1) * stride]
        for x in range(0, w, 4):
            r, g, b = row[x * 4], row[x * 4 + 1], row[x * 4 + 2]
            n += 1; nz += (r | g | b) != 0; s[0] += r; s[1] += g; s[2] += b
    print('%-18s %4dx%-4d nonzero %5.1f%%  mean %5.1f %5.1f %5.1f' % (os.path.basename(f), w, h, 100 * nz / n, s[0] / n, s[1] / n, s[2] / n))
