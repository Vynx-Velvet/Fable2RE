"""The naming dictionary (research/names/*.tsv): names for functions, classes and fields.

    names.function(0x82228488)        -> 'lua_getfield' or None
    names.cls(0x82004A60)             -> 'CECSpellManager' or None
    names.field(0x82004A60, 0x269)    -> 'm_magicEnabled' or None

Names are labels only: the lifter prints them instead of n_sub_XXXXXXXX / C_XXXXXXXX / m_XX. LIFT_NAMES=0
switches the dictionary off. `python tools/lift/names.py` checks the files (identifiers, duplicates).
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DIR = os.path.normpath(os.path.join(HERE, '..', '..', 'research', 'names'))
_IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*\Z')
_RESERVED = {'new', 'delete', 'class', 'this', 'operator', 'int', 'float', 'double', 'void', 'ctx', 'base', 'self'}
_DATA = None


def _rows(name):
    path = os.path.join(DIR, name)
    if not os.path.exists(path):
        return
    with open(path, encoding='utf-8') as f:
        head = f.readline().rstrip('\n').split('\t')
        for n, line in enumerate(f, 2):
            line = line.rstrip('\n')
            if not line or line.startswith('#'):
                continue
            cells = line.split('\t')
            yield n, dict(zip(head, cells))


def load():
    global _DATA
    if _DATA is None:
        _DATA = {'functions': {}, 'classes': {}, 'fields': {}, 'problems': []}
        if os.environ.get('LIFT_NAMES', '1') == '0':
            return _DATA
        seen = {}
        for n, r in _rows('functions.tsv'):
            a, name = int(r['address'], 16), r['name']
            if not _IDENT.match(name) or name in _RESERVED or name.startswith(('n_sub_', 'sub_', '__')):
                _DATA['problems'].append(f'functions.tsv:{n}: bad identifier {name!r}')
            elif name in seen:
                _DATA['problems'].append(f'functions.tsv:{n}: {name} already names {seen[name]:08X}')
            else:
                seen[name] = a
                _DATA['functions'][a] = name
        seen = {}
        for n, r in _rows('classes.tsv'):
            v, name = int(r['vtable'], 16), r['name']
            if not _IDENT.match(name) or name in seen:
                _DATA['problems'].append(f'classes.tsv:{n}: bad or duplicate class name {name!r}')
            else:
                seen[name] = v
                _DATA['classes'][v] = name
        seen = set()
        for n, r in _rows('fields.tsv'):
            v, off, name = int(r['vtable'], 16), int(r['offset'], 16), r['name']
            if not _IDENT.match(name) or (v, name) in seen:
                _DATA['problems'].append(f'fields.tsv:{n}: bad or duplicate field name {name!r}')
            else:
                seen.add((v, name))
                _DATA['fields'][(v, off)] = name
    return _DATA


def function(address):
    return load()['functions'].get(address)


def cls(vtable):
    return load()['classes'].get(vtable)


def field(vtable, offset):
    return load()['fields'].get((vtable, offset))


def native_name(func):
    """The C++ name of a function's native entry point: its dictionary name, else n_<name>."""
    if func.startswith('sub_'):
        n = function(int(func[4:], 16))
        if n:
            return n
    return 'n_' + func


if __name__ == '__main__':
    d = load()
    print(f'{len(d["functions"])} functions, {len(d["classes"])} classes, {len(d["fields"])} fields')
    for p in d['problems']:
        print('PROBLEM', p)
    sys.exit(1 if d['problems'] else 0)
