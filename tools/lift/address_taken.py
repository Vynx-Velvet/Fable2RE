"""Functions whose address the game can take - the only possible targets of calls through
pointers (vtables, callbacks, function tables). A function is address-taken when its start
address appears as a 32-bit big-endian word in the image's data (outside the code section) or as
a constant built in code (lis/addi pairs, research/symbols/func_db.json 'consts').

  python tools/lift/address_taken.py  -> tools/lift/cache/address_taken.pkl  (set of 'sub_XXXXXXXX')
"""
import json
import os
import pickle
import struct

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.join(HERE, '..', '..')
IMAGE_BASE = 0x82000000
# Sections whose words are not function pointers: code (.text, BINK), the exception table (.pdata lists
# every function's start), relocations.
SKIP = [(0x82170000, 0x82170000 + 0x11434C4), (0x832B3600, 0x832B3600 + 0xF43C), (0x8210AA00, 0x8210AA00 + 0x59FC0),
        (0x83520200, 0x83520200 + 0xFBB38)]


def main():
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    starts = {int(a, 16) for a in db}
    img = open(os.path.join(ROOT, 'research', 'decomp', 'default_image.bin'), 'rb').read()
    taken = set()
    words = struct.unpack(f'>{len(img) // 4}I', img[:len(img) // 4 * 4])
    data_hits = 0
    for i, w in enumerate(words):
        addr = IMAGE_BASE + i * 4
        if any(lo <= addr < hi for lo, hi in SKIP):
            continue
        if w in starts:
            taken.add(w)
            data_hits += 1
    const_hits = 0
    for a, e in db.items():
        for c in e.get('consts', []):
            v = int(c, 16)
            if v in starts:
                if v not in taken:
                    const_hits += 1
                taken.add(v)
    names = {f'sub_{a:08X}' for a in taken}
    os.makedirs(os.path.join(HERE, 'cache'), exist_ok=True)
    with open(os.path.join(HERE, 'cache', 'address_taken.pkl'), 'wb') as f:
        pickle.dump(names, f)
    print(f'address-taken functions: {len(names)} of {len(starts)} ({data_hits} data references, '
          f'{const_hits} more from code constants)')


if __name__ == '__main__':
    main()
