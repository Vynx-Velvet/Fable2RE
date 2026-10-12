#!/usr/bin/env python3
"""Fable II text (language/<lang>/text/book.babel): export to an editable text file, rebuild.

Format (big-endian):
  u32 version (0x5B010000), u32 N
  N x {u32 string id, u32 block key, u32 byte offset of the string inside the decompressed block}
      (sorted by string id, ids unique)
  u32 B, then B x {u32 block key, u32 compressed size, u32 size, zlib stream}
      block contents: strings as {u32 length in UTF-16 units incl. the NUL, UTF-16BE text, u16 0}
  trailer (kept verbatim): u32 0x4000, u32 M, M x 10-byte records {u32 string id, u32, u16} (speech
      links); u32 C, C x {u32 key, u32 n, n x u32 string id} (id groups); u32 L, L x {u32 key,
      u32 n, n UTF-16BE units} (named records).
  Every table after the entry table refers to strings by id, never by position (checked on en-uk:
  45,708 speech links, 3,385 groups holding 44,344 ids, 347 named records).

Export file: UTF-8, one string per line:  <id hex8><TAB><text>   (\\n, \\t, \\\\ escaped)
Edit the text column, keep the ids. Lines can be reordered or deleted (deleted = unchanged); when an
id appears twice the later line wins. The separator must be a TAB: a line that starts with an id but
has no tab (an editor turned it into spaces) is an error, not skipped. Notes go on lines starting with #.

New ids: a line whose id the book does not contain adds a new string. The entry is inserted in id
order (the table stays sorted) and the text goes into a new block; since nothing else in the file
refers to entries by position, existing strings and their speech links are unaffected. Whether and
where the game shows a new id depends on the script that asks for it (not verified in game). import
lists the ids it added, so a mistyped id shows up instead of silently changing nothing.

Usage:
  python tools/babel.py export <book.babel> <out.txt>
  python tools/babel.py import <book.babel> <edited.txt> <out book.babel>
"""
import re
import struct
import sys
import zlib


def be32(d, o):
    return struct.unpack('>I', d[o:o + 4])[0]


class Babel:
    def __init__(self, path):
        d = self.raw = open(path, 'rb').read()
        self.version = be32(d, 0)
        n = be32(d, 4)
        self.entries = [(be32(d, 8 + i * 12), be32(d, 12 + i * 12), be32(d, 16 + i * 12)) for i in range(n)]
        o = 8 + n * 12
        nblk = be32(d, o)
        o += 4
        self.block_order, self.blocks, self.compressed = [], {}, {}
        for _ in range(nblk):
            key, comp, size = be32(d, o), be32(d, o + 4), be32(d, o + 8)
            z = zlib.decompressobj()
            data = z.decompress(d[o + 12:o + 12 + comp]) + z.flush()
            if len(data) != size:
                raise ValueError(f'block {key:08X}: {len(data)} bytes, expected {size}')
            self.blocks[key] = data
            self.compressed[key] = d[o + 12:o + 12 + comp]  # (written back as is when unchanged)
            self.block_order.append(key)
            o += 12 + comp
        self.trailer = d[o:]

    def text(self, key, off):
        b = self.blocks[key]
        n = be32(b, off)  # UTF-16 units including the terminating NUL
        return b[off + 4:off + 4 + 2 * max(n - 1, 0)].decode('utf-16-be')

    def strings(self):
        return [(sid, self.text(key, off)) for sid, key, off in self.entries]


def escape(s):
    return s.replace('\\', '\\\\').replace('\n', '\\n').replace('\r', '\\r').replace('\t', '\\t')


def unescape(s):
    out, i = [], 0
    while i < len(s):
        c = s[i]
        if c == '\\' and i + 1 < len(s):
            nxt = s[i + 1]
            out.append({'n': '\n', 'r': '\r', 't': '\t', '\\': '\\'}.get(nxt, nxt))
            i += 2
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def cmd_export(src, out):
    b = Babel(src)
    with open(out, 'w', encoding='utf-8', newline='\n') as f:
        f.write('# Fable II text - edit the text after the tab, keep the id. tools/babel.py import rebuilds.\n')
        for sid, text in b.strings():
            f.write(f'{sid:08X}\t{escape(text)}\n')
    print(f'exported {len(b.entries)} strings from {src} to {out}')


BLOCK_LIMIT = 0x4000  # the game's blocks hold ~16 KB of strings (a block ends after the string that crosses it)
ID = re.compile(r'[0-9A-Fa-f]{1,8}')
# A line that starts like "<id> <text>" or is a bare id, but has no tab: an editor turned the tab into
# spaces, or stripped it with trailing whitespace. Skipping it would leave that string unchanged silently.
TABLESS = re.compile(r'\s*[0-9A-Fa-f]{1,8}(?:\s+\S.*|\s*)')


def read_lines(path):
    """[(line number, string id, text)] of an export-format file (comments and blank lines skipped).

    Raises ValueError naming the line when a line has a tab but its id is not 1-8 hex digits, or when a
    line without a tab starts with an id (start a note with # instead)."""
    rows = []
    with open(path, encoding='utf-8-sig') as f:
        for number, line in enumerate(f, 1):
            line = line.rstrip('\r\n')
            if not line.strip() or line.startswith('#'):
                continue
            if '\t' not in line:
                if TABLESS.fullmatch(line):
                    raise ValueError(f'{path}:{number}: id and text must be separated by a TAB, and this line '
                                     f'has none ("{line[:40]}"); start a note line with #')
                continue
            sid_hex, text = line.split('\t', 1)
            if not ID.fullmatch(sid_hex.strip()):
                raise ValueError(f'{path}:{number}: "{sid_hex}" is not a string id (1-8 hex digits)')
            rows.append((number, int(sid_hex, 16), unescape(text)))
    return rows


def rebuild(src, overrides, out):
    """Writes src with {string id: text} applied to out; ids src lacks are added as new strings.

    Returns (changed ids, added ids, block count, new block count). Unchanged blocks are written with
    their original compressed bytes, so applying nothing reproduces src byte for byte."""
    b = Babel(src)
    texts = {sid: t for sid, t in b.strings()}
    original = dict(texts)
    changed, added = [], {}
    for sid, text in overrides.items():
        if sid not in texts:
            added[sid] = text
        elif texts[sid] != text:
            texts[sid] = text
            changed.append(sid)
    # Rebuild every block with its strings in the original order (offset order inside the block);
    # a block that grows past the limit is split into new blocks (new keys).
    # (Several ids can share one stored string: group entries by (block, offset), write it once.)
    per_block = {}
    for i, (sid, key, off) in enumerate(b.entries):
        per_block.setdefault(key, {}).setdefault(off, []).append(i)
    used_keys = set(b.block_order)
    next_key = [0x7F000000]

    def fresh_key():
        while next_key[0] in used_keys:
            next_key[0] += 1
        used_keys.add(next_key[0])
        return next_key[0]

    def record(text):
        enc = text.encode('utf-16-be')
        return struct.pack('>I', len(enc) // 2 + 1) + enc + bytes(2)  # (length counts the NUL)

    new_entries = list(b.entries)
    out_blocks = []  # (key, data, original compressed bytes or None)
    for key in b.block_order:
        members = [i for idxs in per_block.get(key, {}).values() for i in idxs]
        if all(texts[b.entries[i][0]] == original[b.entries[i][0]] for i in members):
            out_blocks.append((key, b.blocks[key], b.compressed[key]))  # untouched: exactly the game's block
            continue
        cur_key, data = key, bytearray()
        for off, idxs in sorted(per_block.get(key, {}).items()):
            # Ids sharing a string stay shared unless an edit made them differ.
            groups = {}
            for i in idxs:
                groups.setdefault(texts[b.entries[i][0]], []).append(i)
            for text, members in groups.items():
                if data and len(data) >= BLOCK_LIMIT:  # (as the game's own blocks: ~16 KB each)
                    out_blocks.append((cur_key, bytes(data), None))
                    cur_key, data = fresh_key(), bytearray()
                for i in members:
                    new_entries[i] = (b.entries[i][0], cur_key, len(data))
                data += record(text)
        out_blocks.append((cur_key, bytes(data), None))
    if added:  # new strings: their own blocks, entries inserted in id order
        cur_key, data = fresh_key(), bytearray()
        for sid in sorted(added):
            if data and len(data) >= BLOCK_LIMIT:
                out_blocks.append((cur_key, bytes(data), None))
                cur_key, data = fresh_key(), bytearray()
            new_entries.append((sid, cur_key, len(data)))
            data += record(added[sid])
        out_blocks.append((cur_key, bytes(data), None))
        new_entries.sort(key=lambda e: e[0])
    body = bytearray(struct.pack('>II', b.version, len(new_entries)))
    for sid, key, off in new_entries:
        body += struct.pack('>III', sid, key, off)
    body += struct.pack('>I', len(out_blocks))
    for key, data, comp in out_blocks:
        if comp is None:
            c = zlib.compressobj(9)
            comp = c.compress(data) + c.flush()
        body += struct.pack('>III', key, len(comp), len(data)) + comp
    body += b.trailer
    with open(out, 'wb') as f:
        f.write(bytes(body))
    return changed, sorted(added), len(out_blocks), len(out_blocks) - len(b.block_order)


def cmd_import(src, edited, out):
    overrides = {}
    for _, sid, text in read_lines(edited):
        overrides[sid] = text  # (later lines win)
    changed, added, blocks, new_blocks = rebuild(src, overrides, out)
    print(f'{len(changed)} strings changed, {len(added)} new string ids added, {blocks} blocks ({new_blocks} new) -> {out}')
    if added:
        shown = ', '.join(f'{sid:08X}' for sid in added[:10])
        print(f'new ids (not in {src}): {shown}{" ..." if len(added) > 10 else ""}')


def main(argv):
    try:
        if len(argv) >= 3 and argv[0] == 'export':
            cmd_export(argv[1], argv[2])
        elif len(argv) >= 4 and argv[0] == 'import':
            cmd_import(argv[1], argv[2], argv[3])
        else:
            print(__doc__)
            return 1
    except ValueError as e:
        print(f'error: {e}', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
