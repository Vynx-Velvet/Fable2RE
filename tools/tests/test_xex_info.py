"""tools/xex_info.py and the executable identity in tools/lift/bundle.py, on synthetic XEX2 files (seconds; no game
files, no build, nothing written outside a temporary directory).

    python -m unittest discover -s tools/tests -p "test_xex_info.py"

Every file is generated here: an XEX2 header with only the fields xex_info.py reads, made-up title and media IDs,
and random filler as the payload. None of it comes from the game. Cases: basic compression (exact, padded,
truncated), uncompressed, a normal-compression (LZX) block chain (plain, AES under the retail key when the
`cryptography` package is installed, a damaged block, a block shorter than its header, a wrong first SHA-1, a
chain past the end of the file), no XEX2 magic, a file shorter than the magic, a file that ends inside its header,
and the command line with a path the console code page cannot encode. The identity checks (canonical(),
bundle.xex_matches(), xex_identity()) use hashes and these files. F2_TEST_TMP picks the temporary directory's
parent.
"""
import gzip
import hashlib
import io
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
LIFT = os.path.join(TOOLS, 'lift')
XEX_INFO = os.path.join(TOOLS, 'xex_info.py')
BUNDLE_PY = os.path.join(LIFT, 'bundle.py')
for p in (TOOLS, LIFT):   # (as the lifter scripts run: tools/lift first)
    if p not in sys.path:
        sys.path.insert(0, p)
import xex_info  # noqa: E402
import bundle  # noqa: E402

HS, SEC, FFI, EXEC = 0x1000, 0x100, 0x400, 0x500
OPT_FFI, OPT_ENTRY, OPT_EXEC = 0x000003FF, 0x00010100, 0x00040006
LOAD_ADDRESS = 0x82000000
OTHER = 'ab' * 32   # a SHA-256 no table knows


def sha(data):
    return hashlib.sha256(data).hexdigest()


def header(ffi, image_size=0x10000, entry=None, execution=True, file_key=bytes(16)):
    """An XEX2 header of HS bytes: the optional headers xex_info.parse() reads, the security info and `ffi` (the
    file format info)."""
    opts = [(OPT_FFI, FFI)]
    if entry is not None:
        opts.append((OPT_ENTRY, entry))
    if execution:
        opts.append((OPT_EXEC, EXEC))
    h = bytearray(HS)
    struct.pack_into('>4sIIIII', h, 0, b'XEX2', 0x01, HS, 0, SEC, len(opts))
    for i, (key, value) in enumerate(opts):
        struct.pack_into('>II', h, 0x18 + 8 * i, key, value)
    struct.pack_into('>II', h, SEC, 0x180, image_size)
    struct.pack_into('>I', h, SEC + 0x110, LOAD_ADDRESS)
    h[SEC + 0x150:SEC + 0x160] = file_key
    struct.pack_into('>I', h, SEC + 0x178, 0x000000FF)
    h[FFI:FFI + len(ffi)] = ffi
    if execution:   # media ID, version, base version, title ID (made up), platform, table, disc 1 of 1, savegame
        struct.pack_into('>IIIIBBBBI', h, EXEC, 0x0BADF00D, 0x10000000, 0x10000000, 0x5A5A0001, 0, 0, 1, 1, 0)
    return bytes(h)


BASIC_SIZES = (0x300, 0x200)


def basic_xex(**kw):
    """Basic compression: (data size, zero fill) per block; the payload starts with MZ (unencrypted)."""
    pairs = b''.join(struct.pack('>II', d, 0x100) for d in BASIC_SIZES) + bytes(8)
    ffi = struct.pack('>IHH', 8 + len(pairs), 0, 1) + pairs
    return header(ffi, **kw) + b'MZ' + os.urandom(sum(BASIC_SIZES) - 2)


LZX_SIZES = (0x200, 0x310, 0x120)   # multiples of 16, so the AES case needs no padding


def lzx_chain(sizes=LZX_SIZES):
    """(payload, first block size, first block SHA-1): each block starts with the next block's size and SHA-1."""
    blocks, nxt_size, nxt_hash = [], 0, bytes(20)
    for s in reversed(sizes):
        b = struct.pack('>I', nxt_size) + nxt_hash + os.urandom(s - 24)
        blocks.insert(0, b)
        nxt_size, nxt_hash = s, hashlib.sha1(b).digest()
    return b''.join(blocks), nxt_size, nxt_hash


def lzx_ffi(first_size, first_hash, enc=0):
    return struct.pack('>IHHII', 36, enc, 2, 0x8000, first_size) + first_hash


def lzx_xex():
    payload, size, digest = lzx_chain()
    return header(lzx_ffi(size, digest)) + payload


class Scratch(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix='xex_info_', dir=os.environ.get('F2_TEST_TMP') or None)
        self.addCleanup(shutil.rmtree, self.tmp, ignore_errors=True)

    def write(self, name, data):
        path = os.path.join(self.tmp, name)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, 'wb') as f:
            f.write(data)
        return path

    def inspect(self, name, data, **kw):
        r = xex_info.inspect(self.write(name, data), **kw)
        xex_info.render(r)   # the text report never fails either
        return r


class Report(Scratch):
    def test_basic_exact(self):
        data = basic_xex()
        r = self.inspect('basic.xex', data)
        self.assertEqual((r['status'], r['exit_code']), ('unknown', 3))
        self.assertEqual(r['true_size'], HS + sum(BASIC_SIZES))
        self.assertEqual(r['trailing_bytes'], 0)
        self.assertEqual(r['true_sha256'], sha(data))
        self.assertEqual(r['file_sha256'], sha(data))
        self.assertEqual(r['canonical_sha256'], sha(data))
        self.assertEqual((r['compression'], r['payload_blocks']), ('basic', 2))
        self.assertTrue(r['payload_check'].startswith('starts with a PE image'))
        self.assertEqual((r['title_id'], r['media_id']), ('5A5A0001', '0BADF00D'))

    def test_supported_exact_and_padded(self):
        data = basic_xex()
        ident = sha(data)
        with mock.patch.dict(xex_info.SUPPORTED, {ident: {'label': 'synthetic test executable'}}):
            r = self.inspect('exact.xex', data)
            self.assertEqual((r['status'], r['exit_code'], r['supported']), ('supported', 0, True))
            padded = data + bytes(4096)
            r = self.inspect('padded.xex', padded)
            self.assertEqual((r['status'], r['exit_code']), ('trailing-data', 4))
            self.assertEqual(r['trailing_bytes'], 4096)
            self.assertEqual(r['true_sha256'], ident)
            self.assertEqual(r['canonical_sha256'], ident)
            self.assertEqual(r['file_sha256'], sha(padded))
            self.assertIsNone(r['alias_of'])
            self.assertIn('SUPPORTED executable followed by trailing data', xex_info.render(r))
            with mock.patch.dict(xex_info.ALIASES, {sha(padded): ident}):   # a known over-read copy
                r = self.inspect('alias.xex', padded)
                self.assertEqual((r['alias_of'], r['exit_code']), (ident, 4))

    def test_truncated(self):
        r = self.inspect('truncated.xex', basic_xex()[:-100])
        self.assertEqual((r['status'], r['exit_code']), ('error', 2))
        self.assertIn('truncated', r['error'])
        self.assertIsNone(r['true_sha256'])

    def test_uncompressed(self):
        data = header(struct.pack('>IHH', 8, 0, 0), image_size=0x800) + b'MZ' + os.urandom(0x7FE)
        r = self.inspect('raw.xex', data)
        self.assertEqual((r['exit_code'], r['true_size'], r['trailing_bytes']), (3, HS + 0x800, 0))

    def test_not_xex(self):
        data = os.urandom(1024).replace(b'XEX2', b'....')
        r = self.inspect('not.xex', data)
        self.assertEqual((r['status'], r['exit_code']), ('error', 2))
        self.assertIn('no XEX2 magic', r['error'])
        self.assertEqual(r['file_sha256'], sha(data))

    def test_shorter_than_magic(self):
        r = self.inspect('tiny.xex', b'XEX2')
        self.assertEqual(r['exit_code'], 2)

    def test_ends_inside_header(self):
        r = self.inspect('cut.xex', basic_xex()[:0x800])
        self.assertEqual(r['exit_code'], 2)
        self.assertIn('ends inside its header', r['error'])

    def test_missing_file(self):
        r = xex_info.inspect(os.path.join(self.tmp, 'absent.xex'))
        self.assertEqual(r['exit_code'], 2)
        self.assertIn('cannot read', r['error'])

    def test_lzx_plain_padded(self):
        r = self.inspect('lzx.xex', lzx_xex() + b'\xAA' * 100)
        self.assertEqual(r['true_size'], HS + sum(LZX_SIZES))
        self.assertEqual(r['trailing_bytes'], 100)
        self.assertIn('3 compressed blocks (SHA-1 chain verified)', r['true_size_basis'])
        self.assertIsNone(r['payload_key'])
        self.assertEqual(r['exit_code'], 3)

    @unittest.skipIf(xex_info._crypto() is None, 'the cryptography package is not installed')
    @unittest.skipIf(xex_info._crypto() is not None and xex_info._crypto().RETAIL_KEY is None,
                     'the retail key is read from the rexglue-sdk submodule, which is not checked out')
    def test_lzx_aes_retail(self):
        xd = xex_info._crypto()
        payload, size, digest = lzx_chain()
        session, be = os.urandom(16), xd.default_backend()
        e = xd.Cipher(xd.algorithms.AES(xd.RETAIL_KEY), xd.modes.ECB(), backend=be).encryptor()
        file_key = e.update(session) + e.finalize()   # decrypts to `session` under the retail key
        e = xd.Cipher(xd.algorithms.AES(session), xd.modes.CBC(bytes(16)), backend=be).encryptor()
        data = header(lzx_ffi(size, digest, enc=1), file_key=file_key) + e.update(payload) + e.finalize()
        r = self.inspect('aes.xex', data + b'\xBB' * 48)
        self.assertEqual((r['payload_key'], r['encryption']), ('retail', 'AES'))
        self.assertEqual((r['true_size'], r['trailing_bytes']), (HS + sum(LZX_SIZES), 48))
        self.assertEqual(r['true_sha256'], sha(data))

    def test_lzx_damaged_block(self):
        data = bytearray(lzx_xex())
        data[HS + LZX_SIZES[0] + 40] ^= 1   # inside block 2
        r = self.inspect('damaged.xex', bytes(data))
        self.assertIsNone(r['true_size'])
        self.assertIn('block 2 does not match its SHA-1', r['true_size_basis'])
        self.assertEqual(r['exit_code'], 3)

    def test_lzx_block_shorter_than_its_header(self):
        payload = os.urandom(64)
        data = header(lzx_ffi(3, hashlib.sha1(payload[:3]).digest())) + payload   # a 3-byte block, SHA-1 matches
        r = self.inspect('short_block.xex', data)
        self.assertIsNone(r['true_size'])
        self.assertIn('shorter than its 24-byte header', r['true_size_basis'])
        self.assertEqual(r['exit_code'], 3)

    def test_lzx_wrong_first_sha1(self):
        payload, size, _ = lzx_chain()
        r = self.inspect('wrong.xex', header(lzx_ffi(size, bytes(20))) + payload)
        self.assertIsNone(r['true_size'])
        self.assertIn('no key verifies the first compressed block', r['true_size_basis'])

    def test_lzx_chain_past_end(self):
        r = self.inspect('cut_chain.xex', lzx_xex()[:HS + LZX_SIZES[0] + 16])
        self.assertIsNone(r['true_size'])
        self.assertIn('runs past the end of the file', r['true_size_basis'])

    def test_render_without_entry_point_or_execution_info(self):
        text = xex_info.render(self.inspect('bare.xex', basic_xex(execution=False)))
        self.assertIn('entry point none in the header', text)
        self.assertIn('(no execution info)', text)
        self.assertNotIn('None', text)
        text = xex_info.render(self.inspect('entry.xex', basic_xex(entry=0x82000100)))
        self.assertIn('entry point 0x82000100', text)


class CommandLine(Scratch):
    def run_tool(self, *args):
        env = dict(os.environ, PYTHONUTF8='0')   # the console code page, as when output is piped on Windows
        env.pop('PYTHONIOENCODING', None)
        return subprocess.run([sys.executable, *args], capture_output=True, env=env, timeout=60)

    def test_exit_codes(self):
        cases = [('basic.xex', basic_xex(), 3), ('not.xex', b'\0' * 64, 2), ('truncated.xex', basic_xex()[:-1], 2)]
        for name, data, code in cases:
            path = self.write(name, data)
            p = self.run_tool(XEX_INFO, path)
            self.assertEqual(p.returncode, code, p.stderr.decode(errors='replace'))
            p = self.run_tool(XEX_INFO, path, '--json')
            self.assertEqual(json.loads(p.stdout)['exit_code'], code)

    def test_non_ascii_path_piped(self):
        path = self.write(os.path.join('日本', 'default.xex'), basic_xex())
        p = self.run_tool(XEX_INFO, path)
        self.assertEqual(p.returncode, 3, p.stderr.decode(errors='replace'))
        self.assertNotIn(b'Traceback', p.stderr)

    def test_bundle_check_non_ascii_path(self):
        """bundle.py check prints the path it was given; stdout in a code page without those characters."""
        summaries = os.path.join(self.tmp, 'summaries.json.gz')
        with gzip.open(summaries, 'wt', encoding='utf-8') as f:
            json.dump({'xex_sha256': OTHER}, f)
        absent = os.path.join(self.tmp, '日本', 'absent.xex')
        out = io.TextIOWrapper(io.BytesIO(), encoding='cp1252')
        with mock.patch.object(sys, 'stdout', out), mock.patch.object(bundle, 'BUNDLE', summaries), \
                mock.patch.object(sys, 'argv', [BUNDLE_PY, 'check', '--xex', absent]):
            with self.assertRaises(SystemExit) as cm:
                bundle.main()
        out.flush()
        self.assertEqual(cm.exception.code, 1)
        self.assertIn(b'NO: ', out.buffer.getvalue())
        self.assertIn(b'\\u65e5\\u672c', out.buffer.getvalue())

    def test_paths_in_messages(self):
        self.assertEqual(bundle._shown(os.path.join(bundle.ROOT, 'iso', 'extracted', 'default.xex')),
                         'iso/extracted/default.xex')
        outside = os.path.join(os.path.dirname(bundle.ROOT), 'elsewhere', 'default.xex')
        self.assertEqual(bundle._shown(outside), outside)


class Identity(Scratch):
    C = xex_info.CANONICAL_SHA256
    A = next(a for a, c in xex_info.ALIASES.items() if c == xex_info.CANONICAL_SHA256)

    def test_canonical(self):
        self.assertEqual(xex_info.canonical(self.A), self.C)
        self.assertEqual(xex_info.canonical(self.A.upper()), self.C)
        self.assertEqual(xex_info.canonical(' ' + self.C.upper() + '\n'), self.C)
        self.assertEqual(xex_info.canonical(OTHER), OTHER)
        self.assertIsNone(xex_info.canonical(None))
        self.assertIsNone(xex_info.canonical(''))
        self.assertTrue(xex_info.is_sha256(self.C))
        self.assertFalse(xex_info.is_sha256(self.C[:-1]))
        self.assertFalse(xex_info.is_sha256(None))

    def test_matches_by_hash(self):
        m = bundle.xex_matches
        for recorded, other in [(self.A, self.C), (self.C, self.A), (self.A, self.A), (self.C, self.C),
                                (self.C.upper(), self.A), (self.A, self.C.upper())]:
            self.assertTrue(m(recorded, other), (recorded, other))
        for recorded, other in [(self.C, OTHER), (OTHER, self.C), (self.A, OTHER), (None, self.C), (self.C, None),
                                (self.C, ''), ('', self.C)]:
            self.assertFalse(m(recorded, other), (recorded, other))

    def test_matches_by_path(self):
        data = basic_xex()
        ident = sha(data)
        padded = data + bytes(4096)
        raw = sha(padded)
        path = self.write('padded.xex', padded)
        self.assertEqual(bundle.xex_identity(path), (ident, path))
        self.assertEqual(bundle.xex_sha256(path), (raw, path))
        self.assertTrue(bundle.xex_matches(ident, path))
        self.assertTrue(bundle.xex_matches(ident, bundle.xex_identity(path)[0]))
        self.assertFalse(bundle.xex_matches(ident, raw))   # a raw whole-file hash: documented not to work
        self.assertFalse(bundle.xex_matches(OTHER, path))
        self.assertFalse(bundle.xex_matches(ident, os.path.join(self.tmp, 'absent.xex')))
        with mock.patch.dict(xex_info.ALIASES, {raw: ident}):   # once a table knows the copy, its hash works too
            self.assertTrue(bundle.xex_matches(raw, path))
            self.assertTrue(bundle.xex_matches(ident, raw))

    def test_this_machine(self):
        data = basic_xex()
        path = self.write('assets/default.xex', data)
        with mock.patch.object(bundle, 'XEX_CANDIDATES', [os.path.join(self.tmp, 'absent.xex'), path]):
            self.assertTrue(bundle.xex_matches(sha(data)))
            self.assertEqual(bundle.xex_identity(), (sha(data), path))
        with mock.patch.object(bundle, 'XEX_CANDIDATES', [os.path.join(self.tmp, 'absent.xex')]):
            self.assertFalse(bundle.xex_matches(sha(data)))
            self.assertEqual(bundle.xex_identity(), (None, None))

    def test_xex_info_missing_or_broken(self):
        xex = self.write('default.xex', basic_xex())
        summaries = os.path.join(self.tmp, 'summaries.json.gz')
        with gzip.open(summaries, 'wt', encoding='utf-8') as f:
            json.dump({'xex_sha256': OTHER}, f)
        saved = sys.modules.pop('xex_info')
        try:
            with mock.patch.object(bundle, 'ROOT', self.tmp), mock.patch.object(bundle, 'BUNDLE', summaries):
                with self.assertRaises(bundle.XexInfoMissing):
                    bundle._xex_info()
                sm, why = bundle.load(xex)
                self.assertIsNone(sm)
                self.assertIn('tools/xex_info.py is missing', why)
                self.write(os.path.join('tools', 'xex_info.py'), b'def broken(:\n')
                sm, why = bundle.load(xex)
                self.assertIsNone(sm)
                self.assertIn('tools/xex_info.py cannot be loaded: SyntaxError', why)
                self.assertNotIn('xex_info', sys.modules)
        finally:
            sys.modules['xex_info'] = saved


if __name__ == '__main__':
    unittest.main()
