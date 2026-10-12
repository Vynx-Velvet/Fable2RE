#!/usr/bin/env python3
"""Fable II .bnk archives with compressed files (gamescripts_r.bnk, guiscripts.bnk): list, extract, pack.

Format (big-endian, verified on guiscripts.bnk, gamescripts.bnk and gamescripts_r.bnk):
  header   u32 block size (0x8000), u32 ?, u8 layout flag, u32 directory compressed size,
           u32 directory size, zlib stream (directory)          -- at offset 0
  directory: u32 count, then per file
           u32 name length (incl. NUL), name, u32 data offset, u32 size, u32 compressed size,
           u32 chunk count N, N x u32 uncompressed chunk size (they add up to size)
  data     starts at the first block boundary after the header; a file is N zlib streams (each
           sync-flushed, no end marker) at data start + offset: chunk k at k * block size, every
           chunk but the last exactly one block long; `compressed size` bytes in all (stored as is
           when N is 0).
Only banks whose layout flag is 1 are supported (6 of the 127 banks in data/, among them the three
script banks). Flag-0 banks (120: levels.bnk, streaming.bnk, skeletalmorphs.bnk, the audio banks,
most globals/ and art/ banks) use another directory layout (observed on skeletalmorphs.bnk:
{name, offset, size} entries, files stored uncompressed) and are refused with UnsupportedBank
instead of being misread, as is anything else.

Which bank the game reads: data/startup.vfsconfig mounts gamescripts_r.bnk, never gamescripts.bnk.
gamescripts.bnk holds the same 554 scripts compiled with debug information, so it decompiles with
the original local names: extract it to read scripts, put edits under gamescripts_r (tools/mods.py).

Usage:
  python tools/bnk.py list    <bank.bnk>
  python tools/bnk.py extract <bank.bnk> <out dir> [--decompile]   (.lua -> readable source via unluac)
  python tools/bnk.py pack    <in dir> <out.bnk> --like <original.bnk>
      rebuilds a bank from a directory tree (same file order as the original, new files appended);
      text .lua sources are stored as text - the game's Lua loader accepts source as well as bytecode.

--decompile runs tools/thirdparty/unluac.jar with Java: the JAVA environment variable (path to
java/java.exe), else JAVA_HOME/bin/java, else `java` on PATH, else
C:/Program Files/Java/jdk-23/bin/java.exe.
"""
import os
import shutil
import struct
import subprocess
import sys
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CHUNK = 0x7000  # uncompressed bytes per chunk when packing: compressed it always fits one 32 KB block
UNLUAC = os.path.join(ROOT, 'tools', 'thirdparty', 'unluac.jar')
LEGACY_JAVA = r'C:/Program Files/Java/jdk-23/bin/java.exe'


class UnsupportedBank(ValueError):
    """The file is not a bank this tool can read and rewrite (see the module docstring)."""


def find_java():
    """Java for unluac: $JAVA, $JAVA_HOME/bin/java, `java` on PATH, then the old fixed default.

    Raises FileNotFoundError naming everything that was tried."""
    tried = []
    exe = 'java.exe' if os.name == 'nt' else 'java'
    explicit = os.environ.get('JAVA')
    if explicit:
        if os.path.isfile(explicit):
            return explicit
        tried.append(f'JAVA={explicit} (no such file)')
    home = os.environ.get('JAVA_HOME')
    if home:
        candidate = os.path.join(home, 'bin', exe)
        if os.path.isfile(candidate):
            return candidate
        tried.append(f'JAVA_HOME={home} (no bin/{exe})')
    on_path = shutil.which('java')
    if on_path:
        return on_path
    tried.append('java on PATH (not found)')
    if os.path.isfile(LEGACY_JAVA):
        return LEGACY_JAVA
    tried.append(LEGACY_JAVA + ' (no such file)')
    raise FileNotFoundError('Java is needed for --decompile (unluac) but was not found. Tried: ' + '; '.join(tried)
                            + '. Install a JDK/JRE and set JAVA_HOME or put java on PATH.')


def u32(b, o):
    return struct.unpack('>I', b[o:o + 4])[0]


def inflate(data):
    z = zlib.decompressobj()
    return z.decompress(data) + z.flush(zlib.Z_SYNC_FLUSH)


def inflate_chunks(data, sizes, block):
    """A file's zlib streams: chunk k starts at k * block (every chunk but the last fills one block)."""
    out = []
    for k, size in enumerate(sizes):
        chunk = data[k * block:(k + 1) * block]
        # (Repacked chunks are zero-padded after their sync-flush marker; the game's inflate stops at
        # the chunk's output size and never reads the padding.)
        stripped = chunk.rstrip(b'\0')
        if len(stripped) < len(chunk) and stripped.endswith(b'\x00\x00\xff\xff'):
            chunk = stripped
        z = zlib.decompressobj()
        out.append(z.decompress(chunk, size))
    return b''.join(out)


def parse_header(path, head):
    """(block, h1, layout flag, directory compressed size, directory size) from the first 17 bytes."""
    if len(head) < 17:
        raise UnsupportedBank(f'{path}: {len(head)} bytes, too short for a bank header')
    block, h1, flag, dir_comp, dir_size = u32(head, 0), u32(head, 4), head[8], u32(head, 9), u32(head, 13)
    if block == 0 or block & (block - 1):
        raise UnsupportedBank(f'{path}: block size 0x{block:X} is not a power of two - not a bank')
    if flag != 1:
        raise UnsupportedBank(f'{path}: bank layout flag {flag} is not supported by tools/bnk.py (only flag 1, '
                              f'the compressed script banks such as gamescripts_r.bnk and guiscripts.bnk)')
    return block, h1, flag, dir_comp, dir_size


def parse_directory(path, dir_raw):
    """[(name, offset, size, comp, chunk sizes)] of a flag-1 directory."""
    files = []
    try:
        n, o = u32(dir_raw, 0), 4
        for _ in range(n):
            ln = u32(dir_raw, o)
            name = dir_raw[o + 4:o + 4 + ln].rstrip(b'\0').decode('latin1')
            o += 4 + ln
            off, size, comp, nchunks = (u32(dir_raw, o + 4 * k) for k in range(4))
            chunks = [u32(dir_raw, o + 16 + 4 * k) for k in range(nchunks)]
            o += 16 + 4 * nchunks
            files.append((name, off, size, comp, chunks))
    except struct.error:
        raise UnsupportedBank(f'{path}: directory ends early after {len(files)} entries') from None
    return files


def read_directory(path):
    """File names inside a bank, reading only its header and directory (cheap even for big banks).

    Raises UnsupportedBank when the bank cannot be read or rewritten by this tool."""
    with open(path, 'rb') as f:
        head = f.read(17)
        _, _, _, dir_comp, dir_size = parse_header(path, head)
        dir_raw = inflate(f.read(dir_comp))
    if len(dir_raw) != dir_size:
        raise UnsupportedBank(f'{path}: directory size {len(dir_raw)} != {dir_size}')
    return [e[0] for e in parse_directory(path, dir_raw)]


class Bank:
    def __init__(self, path):
        self.path = path
        d = self.raw = open(path, 'rb').read()
        self.block, self.h1, self.h2, dir_comp, dir_size = parse_header(path, d[:17])
        self.dir_raw = inflate(d[17:17 + dir_comp])
        if len(self.dir_raw) != dir_size:
            raise UnsupportedBank(f'{path}: directory size {len(self.dir_raw)} != {dir_size}')
        self.data_start = (17 + dir_comp + self.block - 1) // self.block * self.block
        self.files = parse_directory(path, self.dir_raw)  # (name, offset, size, comp, chunk sizes)

    def read(self, entry):
        name, off, size, comp, chunks = entry
        p = self.data_start + off
        data = self.raw[p:p + comp]
        out = inflate_chunks(data, chunks, self.block) if chunks else data
        if len(out) != size:
            raise ValueError(f'{name}: {len(out)} bytes, expected {size}')
        return out


def cmd_list(path):
    bank = Bank(path)
    print(f'{path}: {len(bank.files)} files, block 0x{bank.block:X}, data at 0x{bank.data_start:X}')
    for name, off, size, comp, chunks in bank.files:
        print(f'{size:9d} {comp:9d} {len(chunks):2d}  {name}')


def cmd_extract(path, out, decompile):
    bank = Bank(path)
    java = None
    if decompile:  # (fail before writing anything)
        if not os.path.isfile(UNLUAC):
            raise FileNotFoundError(f'--decompile needs {UNLUAC} (unluac, https://sourceforge.net/projects/unluac/); '
                                    'download unluac.jar there or extract without --decompile')
        java = find_java()
    lua = []
    for e in bank.files:
        rel = e[0].replace('\\', os.sep)
        dst = os.path.join(out, rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        data = bank.read(e)
        open(dst, 'wb').write(data)
        if decompile and data[:4] == b'\x1bLua':
            lua.append(dst)
    print(f'extracted {len(bank.files)} files to {out}')
    if lua:
        from concurrent.futures import ThreadPoolExecutor

        def one(f):
            src = f[:-4] + '.src.lua' if f.endswith('.lua') else f + '.src.lua'
            r = subprocess.run([java, '-jar', UNLUAC, f], capture_output=True)
            if r.returncode == 0 and r.stdout:
                open(src, 'wb').write(r.stdout)
                return True
            open(src + '.error.txt', 'wb').write(r.stderr)
            return False

        with ThreadPoolExecutor(max_workers=6) as pool:
            ok = sum(pool.map(one, lua))
        print(f'decompiled {ok}/{len(lua)} Lua chunks to *.src.lua')


def write_bank(out, base, contents):
    """Writes a bank with base's header parameters; contents = [(name, bytes)] in directory order."""
    blobs, entries, off = [], [], 0
    for n, data in contents:
        sizes, pieces = [], []
        for i in range(0, max(len(data), 1), CHUNK):
            part = data[i:i + CHUNK]
            c = zlib.compressobj(9)
            pieces.append(c.compress(part) + c.flush(zlib.Z_SYNC_FLUSH))
            assert len(pieces[-1]) <= base.block
            sizes.append(len(part))
        # Chunk k of a file starts k blocks after the file's start (the game reads fixed blocks).
        comp = b''.join(p + bytes(base.block - len(p)) for p in pieces[:-1]) + pieces[-1]
        entries.append((n, off, len(data), len(comp), sizes))
        blobs.append(comp)
        off += len(comp)
    d = struct.pack('>I', len(entries))
    for n, o, size, comp, sizes in entries:
        nb = n.encode('latin1') + bytes(1)
        d += struct.pack('>I', len(nb)) + nb + struct.pack('>4I', o, size, comp, len(sizes))
        d += b''.join(struct.pack('>I', x) for x in sizes)
    c = zlib.compressobj(9)
    dcomp = c.compress(d) + c.flush(zlib.Z_SYNC_FLUSH)
    head = struct.pack('>II', base.block, base.h1) + bytes([base.h2]) + struct.pack('>II', len(dcomp), len(d)) + dcomp
    data_start = (len(head) + base.block - 1) // base.block * base.block
    with open(out, 'wb') as f:
        f.write(head + bytes(data_start - len(head)))
        for b in blobs:
            f.write(b)
    return len(entries)


def cmd_pack(src_dir, out, like):
    base = Bank(like)
    names = [e[0] for e in base.files]
    present = set()
    for dp, _, fs in os.walk(src_dir):
        for f in fs:
            if f.endswith('.src.lua') or f.endswith('.error.txt'):
                continue
            present.add(os.path.relpath(os.path.join(dp, f), src_dir).replace(os.sep, '\\'))
    order = [n for n in names if n in present] + sorted(present - set(names))
    contents = [(n, open(os.path.join(src_dir, n.replace('\\', os.sep)), 'rb').read()) for n in order]
    n = write_bank(out, base, contents)
    print(f'packed {n} files into {out}')


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 1
    try:
        if argv[0] == 'list':
            cmd_list(argv[1])
        elif argv[0] == 'extract' and len(argv) >= 3:
            cmd_extract(argv[1], argv[2], '--decompile' in argv)
        elif argv[0] == 'pack' and len(argv) >= 5 and '--like' in argv[3:-1]:
            cmd_pack(argv[1], argv[2], argv[argv.index('--like') + 1])
        else:
            print(__doc__)
            return 1
    except (UnsupportedBank, FileNotFoundError) as e:
        print(f'error: {e}', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
