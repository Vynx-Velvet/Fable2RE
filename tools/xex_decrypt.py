#!/usr/bin/env python3
"""Decrypt a retail XEX2 (AES-CBC, "basic" block compression) into a flat image
laid out at its load address, so strings and constant pools can be searched
without running the game.

Usage: python tools/xex_decrypt.py iso/extracted/default.xex out/default_image.bin
Requires the `cryptography` package. Prints the load address and image size;
guest address = load address + file offset.
"""
import os
import re
import struct
import sys

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

# The retail XEX2 key is not part of this repository: it is read from the ReXGlue SDK (rexglue-sdk/, the public
# submodule; the key comes from Xenia), which loads executables with it. None when the submodule is missing.
SDK_KEY_SOURCE = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                              'rexglue-sdk', 'src', 'system', 'xex_module.cpp')


def _sdk_retail_key():
    try:
        with open(SDK_KEY_SOURCE, encoding='utf-8', errors='replace') as f:
            src = f.read()
    except OSError:
        return None
    m = re.search(r'xe_xex2_retail_key\[16\]\s*=\s*\{([^}]*)\}', src)
    vals = [int(x, 16) for x in re.findall(r'0x([0-9A-Fa-f]{2})', m.group(1))] if m else []
    return bytes(vals) if len(vals) == 16 else None


RETAIL_KEY = _sdk_retail_key()
DEVKIT_KEY = bytes(16)


def main(argv):
    src, dst = argv[0], argv[1]
    d = open(src, "rb").read()
    if d[:4] != b"XEX2":
        sys.exit("not an XEX2 file")
    hdr_size = struct.unpack(">I", d[8:12])[0]
    sec_off = struct.unpack(">I", d[0x10:0x14])[0]
    n = struct.unpack(">I", d[0x14:0x18])[0]
    image_size = struct.unpack(">I", d[sec_off + 4:sec_off + 8])[0]
    load_addr = struct.unpack(">I", d[sec_off + 0x110:sec_off + 0x114])[0]
    file_key = d[sec_off + 0x150:sec_off + 0x160]
    blocks = None
    for i in range(n):
        key, val = struct.unpack(">II", d[0x18 + 8 * i:0x20 + 8 * i])
        if key == 0x3FF:
            size, enc, comp = struct.unpack(">IHH", d[val:val + 8])
            if comp != 1:
                sys.exit(f"only basic compression is supported (got {comp})")
            blocks = []
            j = val + 8
            while j + 8 <= val + size:
                b = struct.unpack(">II", d[j:j + 8])
                j += 8
                if b == (0, 0):
                    break
                blocks.append(b)
    payload = d[hdr_size:]
    plen = len(payload) // 16 * 16
    be = default_backend()
    plain = None
    for key in (RETAIL_KEY, DEVKIT_KEY):
        if key is None:
            continue
        dec = Cipher(algorithms.AES(key), modes.ECB(), backend=be).decryptor()
        session = dec.update(file_key) + dec.finalize()
        dec = Cipher(algorithms.AES(session), modes.CBC(bytes(16)), backend=be).decryptor()
        cand = dec.update(payload[:plen]) + dec.finalize()
        if cand[:2] == b"MZ":
            plain = cand
            break
    if plain is None:
        if RETAIL_KEY is None:
            sys.exit(f"the retail key is read from {SDK_KEY_SOURCE}, which is missing: fetch the SDK "
                     "submodule (git submodule update --init --recursive rexglue-sdk)")
        sys.exit("neither retail nor devkit key decrypts this XEX")
    img = bytearray()
    pos = 0
    for data_size, zero_size in blocks:
        img += plain[pos:pos + data_size]
        pos += data_size
        img += bytes(zero_size)
    img = img[:image_size] if len(img) >= image_size else img + bytes(image_size - len(img))
    open(dst, "wb").write(img)
    print(f"load address 0x{load_addr:08X}, image size 0x{image_size:X}, wrote {len(img)} bytes to {dst}")


if __name__ == "__main__":
    main(sys.argv[1:])
