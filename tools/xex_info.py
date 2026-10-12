#!/usr/bin/env python3
"""Identify a default.xex without running or changing anything. It prints the XEX2 header facts and the size
the header accounts for (the executable's true extent). It hashes both the whole file and that extent with
SHA-256, and it reports any trailing data after the executable's end, which an older extract leaves when it
over-reads the file to 100 MiB.

  python tools/xex_info.py PATH                 readable report
  python tools/xex_info.py PATH --json          the same as one JSON object (for scripts such as tools/setup_all.ps1)
  python tools/xex_info.py PATH --no-decrypt    skip the payload key check (it needs the `cryptography` package)

Exit status:
  0  a supported executable with no trailing data
  4  a supported executable followed by trailing data. The canonical SHA-256 of the true extent is still printed,
     and the first `true_size` bytes are the supported executable.
  3  not a supported executable. Any trailing data is still reported.
  2  not readable as a complete XEX2: no XEX2 magic, a malformed header, or a file shorter than its header says

An executable's identity is the SHA-256 of its true extent (SUPPORTED). ALIASES maps the whole-file hashes of
known over-read copies to that identity, and canonical() applies the map. A record made from such a copy, such as
research/lift/summaries.json.gz or research/lift/verified.json.gz (both record the 100 MiB alias), describes the
executable itself only where the consumer compares through canonical(). tools/lift/bundle.py does this
(bundle.xex_matches; lift.py loads the shipped analysis through it). A consumer that compares a raw whole-file
hash with == refuses every other copy of the executable, the 21 MB disc file included.

The output contains only header fields, sizes and hashes. None of the executable's content is printed.
The XEX2 layout follows tools/xex_decrypt.py. That script decrypts the image with the same block table and keys.
"""
import argparse
import datetime
import hashlib
import importlib.util
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))

# The executables the project supports, keyed by the SHA-256 of the true extent (see true_extent()).
CANONICAL_SHA256 = '88c4ef2e18e65409444d1b068eff921d1f7e180a5ae64edc64ba6b0872372662'
SUPPORTED = {
    CANONICAL_SHA256: {
        'label': 'Fable II disc executable, media ID 716F0A0D (Game of the Year disc)',
        'title_id': '4D5307F1', 'media_id': '716F0A0D', 'version': '0000001A', 'size': 21217280,
    },
}
# Whole-file SHA-256 of known over-read copies -> the identity of the executable they start with.
ALIASES = {
    # A 104,857,600-byte (100 MiB) copy made by an older extract. Its first 21,217,280 bytes are the disc
    # executable above, and the rest is unrelated data read past the file's end. The shipped lifter analysis and
    # verification manifest were recorded from this copy.
    '39f0c8cdd2ba3486ba347e8e6646a783b2b372c874b21d762e455349185627d5': CANONICAL_SHA256,
}

MAGIC = b'XEX2'
HDR_FILE_FORMAT_INFO = 0x000003FF
HDR_ENTRY_POINT = 0x00010100
HDR_IMAGE_BASE_ADDRESS = 0x00010201
HDR_CHECKSUM_TIMESTAMP = 0x00018002
HDR_ORIGINAL_PE_NAME = 0x000183FF
HDR_EXECUTION_INFO = 0x00040006
HDR_ALTERNATE_TITLE_IDS = 0x000407FF
MODULE_FLAGS = [(0x01, 'title'), (0x02, 'exports to title'), (0x04, 'system debugger'), (0x08, 'DLL'),
                (0x10, 'module patch'), (0x20, 'full patch'), (0x40, 'delta patch'), (0x80, 'user mode')]
REGIONS = [(0x000000FF, 'NTSC-U'), (0x0000FF00, 'NTSC-J'), (0x00FF0000, 'PAL'), (0xFF000000, 'other')]
COMPRESSION = {0: 'none', 1: 'basic', 2: 'normal (LZX)', 3: 'delta patch'}
ENCRYPTION = {0: 'none', 1: 'AES'}
MAX_HEADER = 64 << 20
_SHA = re.compile(r'[0-9a-fA-F]{64}')


class XexError(Exception):
    """The file is not a complete, well-formed XEX2."""


def canonical(sha):
    """The identity a recorded SHA-256 stands for: the executable an alias names, else the hash itself, in lower case.
    None stays None."""
    if not sha:
        return None
    sha = str(sha).strip().lower()
    return ALIASES.get(sha, sha)


def is_sha256(text):
    return bool(text) and bool(_SHA.fullmatch(str(text)))


# ---- header ------------------------------------------------------------------------------------------------------

def _u32(b, off, what):
    if off < 0 or off + 4 > len(b):
        raise XexError(f'{what} at 0x{off:X} lies outside the header')
    return struct.unpack_from('>I', b, off)[0]


def read_header(f):
    """The XEX2 header of an open file: bytes 0 up to the PE data offset."""
    f.seek(0)
    head = f.read(0x18)
    if len(head) < 0x18 or head[:4] != MAGIC:
        raise XexError('not an XEX2 file (no XEX2 magic)')
    header_size = struct.unpack_from('>I', head, 8)[0]
    if header_size < 0x18 or header_size > MAX_HEADER:
        raise XexError(f'implausible header size 0x{header_size:X}')
    f.seek(0)
    hdr = f.read(header_size)
    if len(hdr) < header_size:
        raise XexError(f'the file ends inside its header ({len(hdr)} of {header_size} bytes)')
    return hdr


def parse(hdr):
    """The facts of an XEX2 header (from read_header) as a dict. Keys starting with '_' are internal: the payload's
    block table and file key. They are not part of the report. Raises XexError."""
    module_flags, header_size, _, sec, count = struct.unpack_from('>IIIII', hdr, 4)
    if 0x18 + 8 * count > len(hdr):
        raise XexError(f'{count} optional headers do not fit the header')
    opt = {}
    for i in range(count):
        key, value = struct.unpack_from('>II', hdr, 0x18 + 8 * i)
        opt[key] = value

    def data(key):
        """An optional header's data: None when absent, an int for inline values, otherwise bytes."""
        if key not in opt:
            return None
        value, low = opt[key], key & 0xFF
        if low in (0, 1):
            return value
        size = _u32(hdr, value, f'optional header 0x{key:X}') if low == 0xFF else low * 4
        if value + size > len(hdr):
            raise XexError(f'optional header 0x{key:X} runs past the header')
        return hdr[value:value + size]

    if sec + 0x180 > len(hdr):
        raise XexError('the security info lies outside the header')
    info = {
        'module_flags': module_flags,
        'header_size': header_size,
        'security_info_offset': sec,
        'image_size': _u32(hdr, sec + 0x4, 'image size'),
        'image_flags': _u32(hdr, sec + 0x10C, 'image flags'),
        'load_address': _u32(hdr, sec + 0x110, 'load address'),
        'media_id_full': hdr[sec + 0x140:sec + 0x150].hex().upper(),   # the last 4 bytes are the media ID
        'region': _u32(hdr, sec + 0x178, 'region'),
        'allowed_media_types': _u32(hdr, sec + 0x17C, 'allowed media types'),
        '_file_key': hdr[sec + 0x150:sec + 0x160],
    }
    info['entry_point'] = data(HDR_ENTRY_POINT)
    info['image_base'] = data(HDR_IMAGE_BASE_ADDRESS)
    ct = data(HDR_CHECKSUM_TIMESTAMP)
    if isinstance(ct, bytes) and len(ct) >= 8:
        info['pe_checksum'], info['pe_timestamp'] = struct.unpack_from('>II', ct, 0)
    pe = data(HDR_ORIGINAL_PE_NAME)
    if isinstance(pe, bytes) and len(pe) > 4:
        info['original_pe_name'] = pe[4:].split(b'\0')[0].decode('ascii', 'replace')
    ei = data(HDR_EXECUTION_INFO)
    if isinstance(ei, bytes) and len(ei) >= 24:
        (info['media_id'], info['version'], info['base_version'], info['title_id'], info['platform'],
         info['executable_table'], info['disc_number'], info['disc_count'], info['savegame_id']) = \
            struct.unpack_from('>IIIIBBBBI', ei, 0)
    alt = data(HDR_ALTERNATE_TITLE_IDS)
    if isinstance(alt, bytes) and len(alt) >= 4:
        info['alternate_title_ids'] = [struct.unpack_from('>I', alt, o)[0] for o in range(4, len(alt) - 3, 4)]

    ffi = data(HDR_FILE_FORMAT_INFO)
    if not isinstance(ffi, bytes) or len(ffi) < 8:
        raise XexError('no file format info header')
    _, info['encryption'], info['compression'] = struct.unpack_from('>IHH', ffi, 0)
    if info['compression'] == 1:            # basic: (data size, zero fill) per block, as in tools/xex_decrypt.py
        blocks = []
        for j in range(8, len(ffi) - 7, 8):
            b = struct.unpack_from('>II', ffi, j)
            if b == (0, 0):
                break
            blocks.append(b)
        info['_blocks'] = blocks
    elif info['compression'] == 2:          # normal: window size, then the first block's size and SHA-1
        if len(ffi) < 36:
            raise XexError('short normal-compression info')
        info['window_size'], first = struct.unpack_from('>II', ffi, 8)
        info['_first_block'] = (first, ffi[16:36])
    return info


# ---- payload -----------------------------------------------------------------------------------------------------

def _sibling(name):
    """A module next to this file, loaded by path because tools/ need not be on sys.path."""
    mod = sys.modules.get(name)
    if mod is None:
        spec = importlib.util.spec_from_file_location(name, os.path.join(HERE, name + '.py'))
        mod = importlib.util.module_from_spec(spec)
        sys.modules[name] = mod
        try:
            spec.loader.exec_module(mod)
        except BaseException:
            del sys.modules[name]
            raise
    return mod


def _crypto():
    """tools/xex_decrypt.py: its retail and devkit keys and the `cryptography` primitives it imports. None when the
    package is not installed."""
    try:
        return _sibling('xex_decrypt')
    except ImportError:
        return None


def _session_keys(xd, info):
    """[(name, AES session key)] for the retail and devkit keys, derived as in tools/xex_decrypt.py."""
    out = []
    for name, master in (('retail', xd.RETAIL_KEY), ('devkit', xd.DEVKIT_KEY)):
        if master is None:   # the retail key comes from the ReXGlue SDK submodule (tools/xex_decrypt.py)
            continue
        dec = xd.Cipher(xd.algorithms.AES(master), xd.modes.ECB(), backend=xd.default_backend()).decryptor()
        out.append((name, dec.update(info['_file_key']) + dec.finalize()))
    return out


class _Payload:
    """Sequential reader of the payload that follows the header. It decrypts with AES-CBC (zero IV) when given a
    session key."""

    def __init__(self, f, start, xd=None, session=None):
        self.f, self.pos = f, start
        self.dec = None if session is None else \
            xd.Cipher(xd.algorithms.AES(session), xd.modes.CBC(bytes(16)), backend=xd.default_backend()).decryptor()
        self.buf = bytearray()

    def take(self, n):
        """The next n payload bytes, or fewer when the file ends."""
        while len(self.buf) < n:
            self.f.seek(self.pos)
            chunk = self.f.read(1 << 20)
            if not chunk:
                break
            self.pos += len(chunk)
            self.buf += self.dec.update(chunk) if self.dec else chunk
        out = bytes(self.buf[:n])
        del self.buf[:n]
        return out


def _walk_normal(info, f, xd, session):
    """(payload size, blocks) of a normal-compression chain. Each block starts with the next block's size and SHA-1.
    Returns None when the first block's SHA-1 does not match, which means a wrong key, or (None, why) for a damaged
    chain."""
    size, digest = info['_first_block']
    rd = _Payload(f, info['header_size'], xd, session)
    total = n = 0
    while size:
        block = rd.take(size)
        if len(block) < size:
            return None, 'the compressed block chain runs past the end of the file'
        if hashlib.sha1(block).digest() != digest:
            return None if n == 0 else (None, f'compressed block {n + 1} does not match its SHA-1')
        if size < 24:
            return None, f'compressed block {n + 1} is shorter than its 24-byte header ({size} bytes)'
        total += size
        n += 1
        size, digest = struct.unpack_from('>I', block, 0)[0], block[4:24]
    return total, n


def true_extent(info, f):
    """(size, basis, key) of the executable: its header plus the payload the header accounts for. `key` names the AES
    key that verified the payload ('retail', 'devkit' or None). Returns (None, why, None) when the extent cannot be
    determined."""
    hs, comp = info['header_size'], info['compression']
    if comp == 1:
        blocks = info['_blocks']
        return hs + sum(d for d, _ in blocks), f'header + {len(blocks)} basic-compression data blocks', None
    if comp == 0:
        return hs + info['image_size'], 'header + image size (uncompressed payload)', None
    if comp == 2:
        if info['encryption'] == 0:
            r = _walk_normal(info, f, None, None)
            keys = [(None, r)]
        else:
            xd = _crypto()
            if xd is None:
                return None, 'walking an encrypted compressed payload needs the cryptography package', None
            keys = [(name, _walk_normal(info, f, xd, s)) for name, s in _session_keys(xd, info)]
        for name, r in keys:
            if r is None:
                continue
            if r[0] is None:
                return None, r[1], name
            return hs + r[0], f'header + {r[1]} compressed blocks (SHA-1 chain verified)', name
        return None, 'no key verifies the first compressed block', None
    return None, f'compression type {comp} ({COMPRESSION.get(comp, "unknown")}) has no executable extent', None


def payload_check(info, f):
    """Does the payload start with a PE image ('MZ')? Reports which key makes it so. Applies to basic and
    uncompressed payloads only."""
    if info['compression'] not in (0, 1):
        return None
    f.seek(info['header_size'])
    first = f.read(16)
    if len(first) < 16:
        return 'the payload is missing'
    if info['encryption'] == 0:
        return 'starts with a PE image (MZ), not encrypted' if first[:2] == b'MZ' else 'no PE image (MZ) at its start'
    xd = _crypto()
    if xd is None:
        return 'skipped: the cryptography package is not installed'
    for name, session in _session_keys(xd, info):
        dec = xd.Cipher(xd.algorithms.AES(session), xd.modes.CBC(bytes(16)), backend=xd.default_backend()).decryptor()
        if (dec.update(first) + dec.finalize())[:2] == b'MZ':
            return f'decrypts to a PE image (MZ) with the {name} key'
    return 'neither the retail nor the devkit key decrypts it to a PE image (MZ)'


def hash_file(f, extent=None):
    """(SHA-256 of the whole file, SHA-256 of its first `extent` bytes) in one pass. The second value is None when
    the file is shorter than `extent` or `extent` is None."""
    whole, part, pos = hashlib.sha256(), None, 0
    f.seek(0)
    while True:
        chunk = f.read(1 << 20)
        end = pos + len(chunk)
        if extent is not None and part is None and pos <= extent <= end:
            k = extent - pos
            whole.update(chunk[:k])
            part = whole.copy()
            whole.update(chunk[k:])
        else:
            whole.update(chunk)
        pos = end
        if not chunk:
            break
    return whole.hexdigest(), (part.hexdigest() if part is not None else None)


# ---- report ------------------------------------------------------------------------------------------------------

def _hex8(v):
    return None if v is None else f'{v:08X}'


def _version(v):
    return f'{v >> 28}.{(v >> 24) & 0xF}.{(v >> 8) & 0xFFFF}.{v & 0xFF}'


def inspect(path, check_payload=True):
    """The report on one file as a dict (the --json output). It never raises for a bad file; status 'error' with
    'error' set says why."""
    r = {'path': path, 'status': 'error', 'exit_code': 2, 'error': None, 'notes': []}
    try:
        r['file_size'] = os.path.getsize(path)
        with open(path, 'rb') as f:
            try:
                info = parse(read_header(f))
                size, basis, key = true_extent(info, f)
                check = payload_check(info, f) if check_payload else None
            except (XexError, struct.error) as e:   # (struct.error: a field that does not fit; a backstop)
                r['error'] = str(e) if isinstance(e, XexError) else f'malformed header or payload ({e})'
                r['file_sha256'] = hash_file(f)[0]
                r['canonical_sha256'] = canonical(r['file_sha256'])
                return r
            file_sha, extent_sha = hash_file(f, size)
    except OSError as e:
        r['error'] = f'cannot read {path}: {e.strerror or e}'
        return r

    r.update({
        'magic': 'XEX2',
        'module_flags': _hex8(info['module_flags']),
        'module_flag_names': [n for b, n in MODULE_FLAGS if info['module_flags'] & b],
        'title_id': _hex8(info.get('title_id')),
        'media_id': _hex8(info.get('media_id')),
        'media_id_full': info['media_id_full'],
        'version': _hex8(info.get('version')),
        'version_text': _version(info['version']) if 'version' in info else None,
        'base_version': _hex8(info.get('base_version')),
        'base_version_text': _version(info['base_version']) if 'base_version' in info else None,
        'disc_number': info.get('disc_number'),
        'disc_count': info.get('disc_count'),
        'savegame_id': _hex8(info.get('savegame_id')),
        'region': _hex8(info['region']),
        'region_names': [n for m, n in REGIONS if info['region'] & m],
        'allowed_media_types': _hex8(info['allowed_media_types']),
        'image_flags': _hex8(info['image_flags']),
        'original_pe_name': info.get('original_pe_name'),
        'pe_timestamp': info.get('pe_timestamp'),
        'pe_timestamp_utc': (datetime.datetime.fromtimestamp(info['pe_timestamp'], datetime.timezone.utc)
                             .strftime('%Y-%m-%dT%H:%M:%SZ') if info.get('pe_timestamp') else None),
        'alternate_title_ids': [_hex8(t) for t in info.get('alternate_title_ids', [])],
        'load_address': _hex8(info['load_address']),
        'entry_point': _hex8(info['entry_point']) if isinstance(info['entry_point'], int) else None,
        'image_size': info['image_size'],
        'header_size': info['header_size'],
        'encryption': ENCRYPTION.get(info['encryption'], f'type {info["encryption"]}'),
        'compression': COMPRESSION.get(info['compression'], f'type {info["compression"]}'),
        'payload_blocks': len(info['_blocks']) if '_blocks' in info else None,
        'payload_data_size': sum(d for d, _ in info['_blocks']) if '_blocks' in info else None,
        'payload_zero_fill': sum(z for _, z in info['_blocks']) if '_blocks' in info else None,
        'payload_key': key,
        'payload_check': check,
        'true_size': size,
        'true_size_basis': basis,
        'file_sha256': file_sha,
        'true_sha256': extent_sha,
        'trailing_bytes': None if size is None else max(0, r['file_size'] - size),
    })
    if 'version' in info:
        if info['version'] == info['base_version']:
            r['notes'].append('version equals base version: no title update is applied to this file')
        else:
            r['notes'].append('version differs from base version: this file carries a title update')
    if info['region'] == 0xFFFFFFFF:
        r['notes'].append('region field is all ones: region-free')
    if info['module_flags'] & 0x70:
        r['notes'].append('this is a patch module, not a game executable')

    r['canonical_sha256'] = canonical(extent_sha or file_sha)
    r['alias_of'] = ALIASES.get(file_sha)
    entry = SUPPORTED.get(r['canonical_sha256'])
    r['supported'] = bool(entry)
    r['label'] = entry['label'] if entry else None
    if size is not None and r['file_size'] < size:
        r['error'] = f'the file is {size - r["file_size"]:,} bytes shorter than its header says (truncated)'
        r['status'], r['exit_code'] = 'error', 2
    elif not entry:
        r['status'], r['exit_code'] = 'unknown', 3
    elif r['trailing_bytes']:
        r['status'], r['exit_code'] = 'trailing-data', 4
    else:
        r['status'], r['exit_code'] = 'supported', 0
    return r


def render(r):
    """The report as text."""
    out = []

    def row(k, v):
        out.append(f'{k:<16}{v}')

    row('file', r['path'])
    if r.get('file_size') is not None:
        row('file size', f'{r["file_size"]:,} bytes')
    if r.get('file_sha256'):
        row('file SHA-256', r['file_sha256'])
    if r.get('magic'):
        row('format', f'XEX2, module flags 0x{r["module_flags"]} ({", ".join(r["module_flag_names"]) or "none"})')
        row('title ID', r['title_id'] or '(no execution info)')
        row('media ID', f'{r["media_id"] or "(no execution info)"} (security info: {r["media_id_full"]})')
        if r['version']:
            row('version', f'0x{r["version"]} ({r["version_text"]}), base version 0x{r["base_version"]} '
                           f'({r["base_version_text"]})')
            row('disc', f'{r["disc_number"]} of {r["disc_count"]}')
        row('region', f'0x{r["region"]} ({", ".join(r["region_names"]) or "none"})')
        if r['original_pe_name'] or r['pe_timestamp_utc']:
            row('original PE', f'{r["original_pe_name"] or "?"}, timestamp {r["pe_timestamp_utc"] or "?"}')
        if r['alternate_title_ids']:
            row('alt title IDs', f'{len(r["alternate_title_ids"])}')
        entry = f'0x{r["entry_point"]}' if r['entry_point'] else 'none in the header'
        row('image', f'load address 0x{r["load_address"]}, entry point {entry}, '
                     f'image size 0x{r["image_size"]:X} ({r["image_size"]:,} bytes)')
        row('header', f'0x{r["header_size"]:X} bytes ({r["header_size"]:,})')
        pay = f'{r["encryption"]}, {r["compression"]} compression'
        if r['payload_blocks'] is not None:
            pay += (f': {r["payload_blocks"]} data blocks, 0x{r["payload_data_size"]:X} bytes '
                    f'(+0x{r["payload_zero_fill"]:X} zero fill)')
        if r['payload_key']:
            pay += f', blocks verified with the {r["payload_key"]} key'
        row('payload', pay)
        if r['payload_check']:
            row('payload check', r['payload_check'])
        if r['true_size'] is not None:
            row('true extent', f'{r["true_size"]:,} bytes ({r["true_size_basis"]})')
            row('extent SHA-256', r['true_sha256'] or '(file shorter than the extent)')
            if r['trailing_bytes']:
                row('trailing data', f'{r["trailing_bytes"]:,} bytes after the executable\'s end (an over-read copy; '
                                     f'the first {r["true_size"]:,} bytes are the executable)')
            else:
                row('trailing data', 'none')
        else:
            row('true extent', f'unknown: {r["true_size_basis"]}')
        for n in r['notes']:
            row('note', n)
    if r.get('canonical_sha256'):
        row('canonical', r['canonical_sha256'])
    if r.get('alias_of'):
        row('alias', 'the whole file is a known over-read copy of the canonical executable')
    if r.get('error'):
        row('error', r['error'])
    verdict = {
        'supported': f'SUPPORTED: {r.get("label")}',
        'trailing-data': f'SUPPORTED executable followed by trailing data: {r.get("label")}',
        'unknown': 'UNKNOWN: not a supported executable (other revisions need their own validation)',
        'error': 'ERROR: not a complete XEX2',
    }[r['status']]
    row('result', f'{verdict} (exit {r["exit_code"]})')
    return '\n'.join(out)


def safe_stdout():
    """Print characters the output encoding lacks as escapes instead of failing. Redirected output on Windows uses
    the ANSI code page, which cannot encode every path. tools/lift/bundle.py calls this too."""
    try:
        sys.stdout.reconfigure(errors='backslashreplace')
    except (AttributeError, ValueError, OSError):   # not a text stream that can be reconfigured
        pass


def main(argv=None):
    safe_stdout()
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0],
                                 epilog='exit status: 0 supported, 4 supported with trailing data, 3 unknown, '
                                        '2 not a complete XEX2')
    ap.add_argument('xex', help='path to a default.xex')
    ap.add_argument('--json', action='store_true', help='print the report as one JSON object')
    ap.add_argument('--no-decrypt', action='store_true', help='skip the payload key check')
    args = ap.parse_args(argv)
    r = inspect(args.xex, check_payload=not args.no_decrypt)
    print(json.dumps(r, indent=2) if args.json else render(r))
    return r['exit_code']


if __name__ == '__main__':
    sys.exit(main())
