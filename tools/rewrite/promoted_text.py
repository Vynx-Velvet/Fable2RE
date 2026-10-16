"""The promoted modules without the game's text: the form the repository holds and how setup renders them.

The promoted modules (Fable2Recomp/src/game/promoted/, docs/promoted-code.md) keep names the lifter made from the
game's own text (tools/lift/readable.py): a string constant after its text (str_PieceName), a local after the
constant it holds (pieceName), a global after the text it is built from (research/decomp/global_names.tsv), and
comments and review notes that mention them. Game text stays out of the repository, so Fable2Recomp/promoted/
holds the modules with each such span replaced by a reference to the string's address in the game image:

    TXT_<address>_<kind>_   B  the text part of the constant's name as the lifter writes it (str_ + B)
                            W  the same without the lifter's 48-character limit
                            L  a local named after the constant (lower camel case of B)
                            R  the text itself
                            G  the global's name (research/decomp/global_names.tsv, by the global's address)

A reference is valid inside an identifier, so the published form compiles as it is. `render` writes the modules
back from it with your own copy: the decrypted image (research/decomp/default_image.bin, setup step `image`,
checked against the reference hash) and the global names (setup step `globals`), and checks every file against
the SHA-256 recorded by `publish`, so the result is the same text, byte for byte, as on the machine that
published it.

    python tools/rewrite/promoted_text.py publish   src/game/promoted/ -> Fable2Recomp/promoted/ (+ manifest.tsv)
    python tools/rewrite/promoted_text.py render    Fable2Recomp/promoted/ + your copy -> src/game/promoted/
    python tools/rewrite/promoted_text.py check     the published form carries no game text and renders back
"""
import argparse
import hashlib
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import readable  # noqa: E402

LOCAL = os.path.join(ROOT, 'Fable2Recomp', 'src', 'game', 'promoted')   # what the build and the tools use
PUBLISHED = os.path.join(ROOT, 'Fable2Recomp', 'promoted')              # what the repository holds
MANIFEST = 'manifest.tsv'
RENDERED = '.rendered.tsv'   # (in LOCAL: the SHA-256 of what render last wrote, to recognise later local edits)
REF = re.compile(r'TXT_([0-9A-F]{8})_([BWLRG])_')
DECL = re.compile(r'constexpr\s+[\w:]+\s+((?:str|g)_\w+)\s*=\s*([^;]*);')
INT = re.compile(r'-?\b(?:0x[0-9A-Fa-f]+|\d+)\b')
ADDR = re.compile(r'\b0x(8[23][0-9A-Fa-f]{6})u?\b')
STR_TOKEN = re.compile(r'\bstr_([A-Za-z]\w*)')
IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
DISTINCT = 8   # a constant's text or name part this long is replaced wherever it occurs (shorter: only as a name)


class TextError(Exception):
    pass


def norm(text):
    return text.replace('\r\n', '\n')


def sha(text):
    return hashlib.sha256(norm(text).encode('utf-8')).hexdigest()


# ---- the recipes ---------------------------------------------------------------------------------------------------

def words(s):
    return re.findall(r'[A-Za-z0-9]+', s)[:6]


def body(s):
    """The text part of the lifter's constant name (readable.ident_from_text without its prefix)."""
    n = readable.ident_from_text(s, 'str_') if s else None
    return n[4:] if n else None


def body_full(s):
    """The same without the 48-character limit (names written before it, or by hand)."""
    w = words(s or '')
    b = ''.join(x[:1].upper() + x[1:] for x in w)
    return b if b and re.fullmatch(r'[A-Za-z_]\w*', 'str_' + b) else None


_TEXT_GLOBALS = None


def text_globals():
    """name -> address of the globals named after their text (research/decomp/global_names.tsv)."""
    global _TEXT_GLOBALS
    if _TEXT_GLOBALS is None:
        _TEXT_GLOBALS = {n: a for a, n in readable.global_names().items() if not re.fullmatch(r'g_[0-9A-F]{8}', n)}
    return _TEXT_GLOBALS


def resolve(addr, kind):
    """The text a reference stands for, from this machine's copy of the game."""
    if kind == 'G':
        v = readable.global_names().get(addr)
    else:
        s = readable.game_string(addr)
        v = {'B': body(s), 'W': body_full(s), 'L': readable.lower_camel(body(s) or '') if s else None,
             'R': s}.get(kind)
    if not v:
        raise TextError(f'TXT_{addr:08X}_{kind}_: nothing at this address in this copy of the game '
                        f'(research/decomp/default_image.bin, research/decomp/global_names.tsv: setup steps '
                        f'image and globals)')
    return v


def render_text(text):
    return REF.sub(lambda m: resolve(int(m.group(1), 16), m.group(2)), text)


# ---- finding the text --------------------------------------------------------------------------------------------

_INDEX = None


def string_index():
    """name part -> address over every string in the image (for names whose constant is not declared nearby)."""
    global _INDEX
    if _INDEX is None:
        _INDEX = {}
        img = readable.image()
        start = 0
        for run in img.split(b'\0'):
            if len(run) >= 2:
                addr = readable.IMAGE_BASE + start
                s = readable.game_string(addr)
                if s:
                    for part, kind in ((body(s), 'B'), (body_full(s), 'W')):
                        if part and part not in _INDEX:
                            _INDEX[part] = (addr, kind)
            start += len(run) + 1
    return _INDEX


def declared(text):
    """The string constants a module declares: (name part -> (address, kind) for its str_ names, text spans of
    DISTINCT length or more -> (address, kind), local name -> address). Addresses written elsewhere in the module
    count for str_ names too (a constant renamed by hand is still mentioned in comments and notes)."""
    parts, spans, locals_ = {}, {}, {}

    def name_parts(addr, s):
        for part, kind in ((body(s), 'B'), (body_full(s), 'W')):
            if part:
                parts.setdefault(part, (addr, kind))
        if re.fullmatch(r'\w+', s):
            parts.setdefault(s, (addr, 'R'))

    for m in DECL.finditer(text):
        ints = INT.findall(m.group(2))
        if m.group(1).startswith('g_') or not ints:
            continue
        addr = int(ints[-1], 0) & 0xFFFFFFFF
        s = readable.game_string(addr)
        if not s:
            continue
        name_parts(addr, s)
        for part, kind in ((body(s), 'B'), (body_full(s), 'W')):
            if part and len(part) >= DISTINCT:
                spans.setdefault(part, (addr, kind))
        if len(s) >= DISTINCT:
            spans.setdefault(s, (addr, 'R'))
        lc = readable.lower_camel(body(s) or '')
        if lc:
            locals_.setdefault(lc, addr)
    for m in ADDR.finditer(text):
        addr = int(m.group(1), 16)
        s = readable.game_string(addr)
        if s:
            name_parts(addr, s)
    return parts, spans, locals_


def ref(addr, kind):
    return f'TXT_{addr:08X}_{kind}_'


_NAMES = None


def dictionary_names():
    """Names the repository already publishes (research/names: classes, functions, fields, locals)."""
    global _NAMES
    if _NAMES is None:
        _NAMES = set()
        d = os.path.join(ROOT, 'research', 'names')
        for f in ('classes.tsv', 'functions.tsv', 'fields.tsv', 'locals.tsv'):
            p = os.path.join(d, f)
            if os.path.exists(p):
                lines = read(p).split('\n')
                head = lines[0].split('\t')
                i = head.index('name') if 'name' in head else None
                for line in lines[1:]:
                    cells = line.split('\t')
                    if i is not None and len(cells) > i and cells[i]:
                        _NAMES.add(cells[i])
                        _NAMES.add('m_' + cells[i])
    return _NAMES


def split_comment(line):
    """(code, comment) of one line ('//' comments)."""
    i = line.find('//')
    return (line, '') if i < 0 else (line[:i], line[i:])


def encode(text, context=None, prose=False):
    """The published form of a module text, or of a review note (prose=True, its module's text as context)."""
    text = norm(text)
    if REF.search(text):
        raise TextError('the text already contains a reference (TXT_<address>_<kind>_)')
    parts, spans, locals_ = declared(context if context is not None else text)
    spans = {s: v for s, v in spans.items() if s not in dictionary_names()}
    globals_ = text_globals()
    span_re = re.compile('|'.join(re.escape(s) for s in sorted(spans, key=len, reverse=True))) if spans else None
    code_spans = [s for s in sorted(spans, key=len, reverse=True) if re.fullmatch(r'\w+', s)]
    code_span_re = re.compile('|'.join(re.escape(s) for s in code_spans)) if code_spans else None

    def str_token(m):
        name = m.group(1)
        for k in range(len(name), 0, -1):   # the longest known name part; the rest must be a number
            part, rest = name[:k], name[k:]
            if rest and not rest.isdigit():
                continue
            hit = parts.get(part) or string_index().get(part)
            if hit:
                return 'str_' + ref(*hit) + rest
        raise TextError(f'str_{name}: no string in the image has this name (rename it to the lifter\'s name)')

    def code_ident(m):
        w = m.group(0)
        if w in globals_:
            return ref(globals_[w], 'G')
        lm = re.fullmatch(r'([A-Za-z]\w*?)(\d*)', w)
        if lm and lm.group(1) in locals_:
            return ref(locals_[lm.group(1)], 'L') + lm.group(2)
        if code_span_re and w not in dictionary_names() and not w.startswith('str_'):
            return code_span_re.sub(lambda m2: ref(*spans[m2.group(0)]), w)   # (a name made around the text)
        return w

    def prose_part(s):
        s = STR_TOKEN.sub(str_token, s)
        s = re.sub(r'\b(?!TXT_)[A-Za-z_]\w*\b', lambda m: ref(globals_[m.group(0)], 'G')
                   if m.group(0) in globals_ else m.group(0), s)
        if span_re:
            pieces = REF.split(s)   # (never inside a reference already placed)
            out = []
            for i in range(0, len(pieces), 3):
                out.append(span_re.sub(lambda m: ref(*spans[m.group(0)]), pieces[i]))
                if i + 2 < len(pieces):
                    out.append(ref(int(pieces[i + 1], 16), pieces[i + 2]))
            s = ''.join(out)
        return s

    def code_part(s):
        s = STR_TOKEN.sub(str_token, s)
        return re.sub(r'\b(?!TXT_|str_TXT_)[A-Za-z_]\w*\b', code_ident, s)

    if prose:
        out = prose_part(text)
    else:
        lines = []
        for line in text.split('\n'):
            code, comment = split_comment(line)
            lines.append(code_part(code) + (prose_part(comment) if comment else ''))
        out = '\n'.join(lines)
    if render_text(out) != text:
        raise TextError('the published form does not render back to the same text')
    return out


def leftovers(published, context=None, prose=False):
    """Game text the published form still shows (empty when it is clean): names the lifter makes from text
    anywhere, the longer text of the module's constants in comments and notes, and code names containing it."""
    found = {'str_' + f for f in STR_TOKEN.findall(published)
             if not f.startswith('TXT_') and not re.fullmatch(r'[0-9A-F]{8}(?:_\d+)?', f)}
    found |= set(IDENT.findall(published)) & set(text_globals())
    _, spans, locals_ = declared(render_text(context if context is not None else published))
    spans = [s for s in spans if s not in dictionary_names()]
    names = dictionary_names()
    for line in ([published] if prose else published.split('\n')):
        code, comment = ('', line) if prose else split_comment(line)
        found |= {s for s in spans if s in comment}
        for w in IDENT.findall(code):
            if w in names or w.startswith('str_TXT_'):
                continue
            lm = re.fullmatch(r'([A-Za-z]\w*?)(\d*)', w)
            if (lm and lm.group(1) in locals_) or any(s in w for s in spans if re.fullmatch(r'\w+', s)):
                found.add(w)
    return sorted(found)


# ---- files -------------------------------------------------------------------------------------------------------

def read(path):
    with open(path, encoding='utf-8', newline='') as f:
        return norm(f.read())


def write(path, text):
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write(text)


def review_rows(text):
    lines = text.split('\n')
    return lines[0], [l.split('\t') for l in lines[1:] if l]


def module_texts(directory):
    return {f: read(os.path.join(directory, f)) for f in sorted(os.listdir(directory)) if f.endswith('.cpp')}


def encode_review(text, modules):
    """REVIEW.tsv with every note encoded in the context of its module."""
    head, rows = review_rows(text)
    out = [head]
    for cells in rows:
        if len(cells) >= 6 and cells[5]:
            ctx = modules.get(cells[0] + '.cpp', '')
            cells = cells[:5] + [encode(cells[5], ctx, prose=True)] + cells[6:]
        out.append('\t'.join(cells))
    return '\n'.join(out) + '\n'


def cmd_publish(a):
    if not os.path.isdir(LOCAL):
        sys.exit(f'publish: no local modules ({LOCAL})')
    local = module_texts(LOCAL)
    os.makedirs(PUBLISHED, exist_ok=True)
    rows, problems, refs = [], [], 0
    for f, text in local.items():
        try:
            pub = encode(text)
        except TextError as e:
            problems.append(f'{f}: {e}')
            continue
        left = leftovers(pub)
        if left:
            problems.append(f'{f}: game text left: {", ".join(left[:5])}')
            continue
        refs += len(REF.findall(pub))
        write(os.path.join(PUBLISHED, f), pub)
        rows.append((f, sha(text), len(REF.findall(pub))))
    review = os.path.join(LOCAL, 'REVIEW.tsv')
    if os.path.exists(review):
        text = read(review)
        try:
            pub = encode_review(text, local)
            write(os.path.join(PUBLISHED, 'REVIEW.tsv'), pub)
            rows.append(('REVIEW.tsv', sha(text), len(REF.findall(pub))))
        except TextError as e:
            problems.append(f'REVIEW.tsv: {e}')
    if problems:
        print('not published (fix these in the local modules first):')
        for p in problems:
            print('  ' + p)
        return 1
    keep = {r[0] for r in rows} | {MANIFEST}
    for f in os.listdir(PUBLISHED):
        if f not in keep:
            os.remove(os.path.join(PUBLISHED, f))
    write(os.path.join(PUBLISHED, MANIFEST),
          'file\tsha256\treferences\n' + ''.join(f'{f}\t{h}\t{n}\n' for f, h, n in rows))
    print(f'published {len(rows)} files to {os.path.relpath(PUBLISHED, ROOT)} ({refs} references to the game\'s text)')
    return 0


def manifest():
    p = os.path.join(PUBLISHED, MANIFEST)
    if not os.path.exists(p):
        return {}
    _, rows = review_rows(read(p))
    return {c[0]: c[1] for c in rows if len(c) >= 2}


def cmd_render(a):
    want = manifest()
    if not want:
        print('render: no published modules (Fable2Recomp/promoted/manifest.tsv): nothing to do')
        return 0
    if not readable.image():
        sys.exit('render: research/decomp/default_image.bin is missing (setup step image)')
    os.makedirs(LOCAL, exist_ok=True)
    stamp_path = os.path.join(LOCAL, RENDERED)
    last = {}
    if os.path.exists(stamp_path):
        _, rows = review_rows(read(stamp_path))
        last = {c[0]: c[1] for c in rows if len(c) >= 2}
    wrote, same, kept, bad = 0, 0, [], []
    stamp = {}
    for f, h in sorted(want.items()):
        try:
            text = render_text(read(os.path.join(PUBLISHED, f)))
        except (TextError, OSError) as e:
            bad.append(f'{f}: {e}')
            continue
        if sha(text) != h:
            bad.append(f'{f}: renders to different text than was published (another executable?)')
            continue
        dest = os.path.join(LOCAL, f)
        if os.path.exists(dest):
            have = read(dest)
            if have == text:
                same += 1
                stamp[f] = h
                continue
            if sha(have) != last.get(f) and not a.force:
                kept.append(f)   # (changed here since the last render: yours)
                continue
        write(dest, text)
        stamp[f] = h
        wrote += 1
    for f in sorted(os.listdir(LOCAL)):
        if f.endswith('.cpp') and f not in want and f in last and sha(read(os.path.join(LOCAL, f))) == last[f]:
            os.remove(os.path.join(LOCAL, f))   # (a module the repository no longer has, unchanged here)
    write(stamp_path, 'file\tsha256\n' + ''.join(f'{f}\t{h}\n' for f, h in sorted(stamp.items())))
    print(f'rendered {len(want)} files from {os.path.relpath(PUBLISHED, ROOT)}: {wrote} written, {same} already the '
          f'same' + (f', {len(kept)} kept (changed here; --force replaces them)' if kept else ''))
    for f in kept:
        print(f'  kept {f}')
    for b in bad:
        print(f'  FAILED {b}')
    return 1 if bad else 0


def cmd_check(a):
    want = manifest()
    problems = []
    published = {f: read(os.path.join(PUBLISHED, f)) for f in want if os.path.exists(os.path.join(PUBLISHED, f))}
    for f in sorted(set(want) - set(published)):
        problems.append(f'{f}: in the manifest but not published')
    modules = {}
    for f, pub in published.items():
        try:
            text = render_text(pub)
        except TextError as e:
            problems.append(f'{f}: {e}')
            continue
        if sha(text) != want[f]:
            problems.append(f'{f}: renders to different text than was published')
        if f.endswith('.cpp'):
            modules[f] = text
            left = leftovers(pub)
            if left:
                problems.append(f'{f}: game text left: {", ".join(left[:5])}')
    if 'REVIEW.tsv' in published:
        _, rows = review_rows(published['REVIEW.tsv'])
        for cells in rows:
            if len(cells) >= 6:
                left = leftovers(cells[5], modules.get(cells[0] + '.cpp', ''), prose=True)
                if left:
                    problems.append(f'REVIEW.tsv {cells[1]}: game text left: {", ".join(left[:5])}')
    if os.path.isdir(LOCAL):
        for f, pub in published.items():
            p = os.path.join(LOCAL, f)
            if os.path.exists(p) and read(p) != render_text(pub):
                problems.append(f'{f}: the local module differs from the published one (publish it, or render)')
    for p in problems:
        print('  ' + p)
    print(f'{len(published)} published files: ' + ('OK' if not problems else f'{len(problems)} problem(s)'))
    return 1 if problems else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    sub.add_parser('publish')
    r = sub.add_parser('render')
    r.add_argument('--force', action='store_true', help='also replace local modules changed since the last render')
    sub.add_parser('check')
    a = ap.parse_args()
    sys.exit({'publish': cmd_publish, 'render': cmd_render, 'check': cmd_check}[a.cmd](a) or 0)


if __name__ == '__main__':
    main()
