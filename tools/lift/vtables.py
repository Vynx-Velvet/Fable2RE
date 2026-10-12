"""Virtual function tables: which functions can sit in each vtable slot.

Constructors store the address of their class's vtable with a constant (lis/addi), so every
constant that points at a function address in read-only data is a vtable start. Slot k of every
vtable gives the candidates of a virtual call that loads offset 4*k from the vtable.

  python tools/lift/vtables.py  -> tools/lift/cache/vtables.pkl  {offset: set of 'sub_XXXXXXXX'}
"""
import json
import os
import pickle
import struct

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.join(HERE, '..', '..')
IMAGE_BASE = 0x82000000
RDATA = (0x82000600, 0x82000600 + 0x10A348)
DATA = (0x832D0000, 0x832D0000 + 0x22B5EC)


def main():
    db = json.load(open(os.path.join(ROOT, 'research', 'symbols', 'func_db.json')))
    starts = {int(a, 16) for a in db}
    img = open(os.path.join(ROOT, 'research', 'decomp', 'default_image.bin'), 'rb').read()

    def word(a):
        o = a - IMAGE_BASE
        return struct.unpack_from('>I', img, o)[0] if 0 <= o <= len(img) - 4 else None

    def in_tables(a):
        return RDATA[0] <= a < RDATA[1] or DATA[0] <= a < DATA[1]
    vt_starts = set()
    for a, e in db.items():
        for c in e.get('consts', []):
            v = int(c, 16)
            if in_tables(v) and v % 4 == 0 and word(v) in starts:
                vt_starts.add(v)
    slots = {}
    for vt in vt_starts:
        k = 0
        while True:
            w = word(vt + 4 * k)
            if w not in starts:
                break
            slots.setdefault(4 * k, set()).add(f'sub_{w:08X}')
            k += 1
            if k > 512:
                break
    with open(os.path.join(HERE, 'cache', 'vtables.pkl'), 'wb') as f:
        pickle.dump(slots, f)
    sizes = sorted((len(v) for v in slots.values()), reverse=True)
    print(f'{len(vt_starts)} vtables, {len(slots)} slot offsets; candidates per slot: max {sizes[0] if sizes else 0}, '
          f'median {sizes[len(sizes) // 2] if sizes else 0}')


if __name__ == '__main__':
    main()
