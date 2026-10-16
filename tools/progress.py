"""How much of Fable II this repository holds as human-readable C++: the numbers, their history, the README block.

Every function of the game's executable (research/catalog/functions.tsv, its areas from research/catalog/scope.tsv)
counts once, in its most finished form. Only tracked files are read, so every clone and the CI get the same numbers:

    reviewed     human-readable C++, reviewed (Fable2Recomp/promoted/: docs/promoted-code.md)
    hand         human-readable C++ written by hand (F2_REWRITE in Fable2Recomp/src/game/: docs/conversion-guide.md)
    translated   machine-translated C++, exact and tested (research/lift/verified.json.gz: the lifter's output that a
                 setup keeps)
    recompiled   the instruction-by-instruction recompilation only

Writes research/progress/history.tsv (a row whenever a number changes, dated the day it was recorded),
docs/progress.md, docs/images/progress-light.svg and -dark.svg, and the block between the progress markers in
README.md.

    python tools/progress.py            bring them up to date
    python tools/progress.py --check    exit 1 when one of them is out of date (CI, tools/publish.py)
"""
import argparse
import datetime
import gzip
import json
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CATALOG = ROOT / 'research' / 'catalog' / 'functions.tsv'
SCOPE = ROOT / 'research' / 'catalog' / 'scope.tsv'
MANIFEST = ROOT / 'research' / 'lift' / 'verified.json.gz'
PUBLISHED = ROOT / 'Fable2Recomp' / 'promoted'
GAME_SRC = ROOT / 'Fable2Recomp' / 'src' / 'game'
NAMES = ROOT / 'research' / 'names'
HISTORY = ROOT / 'research' / 'progress' / 'history.tsv'
PAGE = ROOT / 'docs' / 'progress.md'
CHARTS = {'light': ROOT / 'docs' / 'images' / 'progress-light.svg',
          'dark': ROOT / 'docs' / 'images' / 'progress-dark.svg'}
README = ROOT / 'README.md'
BEGIN = '<!-- progress:begin (written by tools/progress.py from tracked files: do not edit by hand) -->'
END = '<!-- progress:end -->'
BLOCK = re.compile(r'<!-- progress:begin[^>]*-->.*?<!-- progress:end -->', re.S)

KINDS = [('reviewed', 'Human-readable C++, reviewed', 'Readable, reviewed'),
         ('hand', 'Human-readable C++, written by hand', 'Readable, written by hand'),
         ('translated', 'Machine-translated C++, exact and tested', 'Machine-translated'),
         ('recompiled', 'Recompiled only', 'Recompiled only')]
READABLE = ('reviewed', 'hand')
AREAS = [('game', 'Game and engine code'), ('game-static', 'Start-up initialisers'),
         ('library', 'Middleware libraries'), ('system', 'System libraries'), ('unknown', 'Unidentified code')]
LIONHEAD = ('game', 'game-static')
FIELDS = ['date', 'game_functions', 'game_bytes', 'reviewed', 'hand', 'translated', 'recompiled', 'readable_bytes',
          'named', 'modules', 'executable_functions', 'executable_readable']
DEFINITIONS = {
    'reviewed': 'A language model rewrote the lifter\'s exact code for the function into readable C++; it passes a '
                'strict differential check against the original on six input profiles, a review, a build and the '
                'game checks ([promoted code](promoted-code.md)).',
    'hand': 'Written by hand for this port and checked against the original ([conversion guide](conversion-guide.md)).',
    'translated': 'The lifter\'s structured C++ with real signatures and every name the dictionary knows. It is '
                  'exact (the differential tester compares it with the original), but mechanical to read '
                  '([lifted code](lifted-code.md)).',
    'recompiled': 'Runs as ReXGlue\'s instruction-by-instruction recompilation, because no translated form of it has '
                  'passed the tester yet.',
}
PALETTE = {
    'light': {'fg': '#1f2328', 'muted': '#59636e', 'reviewed': '#b7791f', 'hand': '#2f855a', 'translated': '#cdd5df',
              'recompiled': '#6b7785'},
    'dark': {'fg': '#e6edf3', 'muted': '#9198a1', 'reviewed': '#f2c14e', 'hand': '#5fc48b', 'translated': '#323b47',
             'recompiled': '#8b97a6'},
}


def read_tsv(path):
    lines = Path(path).read_text(encoding='utf-8').splitlines()
    head = lines[0].split('\t')
    return [dict(zip(head, line.split('\t'))) for line in lines[1:] if line]


def measure():
    """The numbers, from tracked files."""
    scope = [(int(r['start'], 16), int(r['end'], 16), r['category']) for r in read_tsv(SCOPE)]

    def area(addr):
        return next((c for s, e, c in scope if s <= addr < e), 'unknown')

    reviewed, modules = set(), 0
    for p in sorted(PUBLISHED.glob('*.cpp')):
        modules += 1
        reviewed |= set(re.findall(r'^PROMOTED_ENTRY\(\d+, (sub_[0-9A-F]{8})', p.read_text(encoding='utf-8'), re.M))
    hand = set()
    for p in sorted(GAME_SRC.rglob('*.cpp')):
        if 'promoted' in p.relative_to(GAME_SRC).parts:
            continue   # (rendered locally from Fable2Recomp/promoted/)
        hand |= {'sub_' + a for a in re.findall(r'F2_REWRITE\("[^"]*", sub_([0-9A-F]{8})', p.read_text(encoding='utf-8'))}
    tested = {n for n, v in json.loads(gzip.decompress(MANIFEST.read_bytes()))['functions'].items() if v[1] == 'OK'}

    count = {a: {k: 0 for k, _, _ in KINDS} for a, _ in AREAS}
    size = {a: {k: 0 for k, _, _ in KINDS} for a, _ in AREAS}
    for r in read_tsv(CATALOG):
        name, a = 'sub_' + r['address'], area(int(r['address'], 16))
        kind = ('reviewed' if name in reviewed else 'hand' if name in hand else
                'translated' if name in tested else 'recompiled')
        count[a][kind] += 1
        size[a][kind] += int(r['size'] or 0)
    names = {f: len(read_tsv(NAMES / f'{f}.tsv')) for f in ('functions', 'classes', 'fields', 'locals')}
    named = sum(1 for r in read_tsv(NAMES / 'functions.tsv') if area(int(r['address'], 16)) in LIONHEAD)
    return {'count': count, 'size': size, 'names': names, 'named': named, 'modules': modules}


def summary(m):
    """The history row of these numbers (without its date)."""
    own = lambda table, k: sum(table[a][k] for a in LIONHEAD)
    row = {k: own(m['count'], k) for k, _, _ in KINDS}
    row.update(game_functions=sum(row.values()),
               game_bytes=sum(own(m['size'], k) for k, _, _ in KINDS),
               readable_bytes=sum(own(m['size'], k) for k in READABLE),
               named=m['named'], modules=m['modules'],
               executable_functions=sum(sum(c.values()) for c in m['count'].values()),
               executable_readable=sum(c[k] for c in m['count'].values() for k in READABLE))
    return {f: str(row[f]) for f in FIELDS if f != 'date'}


def read_history():
    return read_tsv(HISTORY) if HISTORY.exists() else []


def updated_history(history, row, today):
    if history and all(history[-1][f] == row[f] for f in row):
        return history
    new = dict(row, date=today)
    if history and history[-1]['date'] == today:
        return history[:-1] + [new]
    return history + [new]


def history_text(history):
    return '\t'.join(FIELDS) + '\n' + ''.join('\t'.join(r[f] for f in FIELDS) + '\n' for r in history)


# ---- rendering ---------------------------------------------------------------------------------------------------

def n(v):
    return f'{int(v):,}'


def pct(part, whole):
    return f'{100 * int(part) / int(whole):.1f}%' if int(whole) else '-'


def esc(s):
    return s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')


def squares(row):
    """Squares of about 100 functions per kind (largest remainder; at least one for a kind that has any)."""
    total = int(row['game_functions'])
    want = round(total / 100)
    exact = [int(row[k]) / total * want for k, _, _ in KINDS]
    cells = [max(1, int(x)) if int(row[k]) else 0 for x, (k, _, _) in zip(exact, KINDS)]
    left = want - sum(cells)
    for _, i in sorted(((x - int(x), i) for i, x in enumerate(exact)), reverse=True):
        if left <= 0:
            break
        cells[i] += 1
        left -= 1
    while left < 0:
        i = cells.index(max(cells))
        cells[i] -= 1
        left += 1
    return cells


def chart(row, theme):
    """The README's chart: the share in human-readable C++ and one square per 100 of Lionhead's functions."""
    c = PALETTE[theme]
    width, pad, size, gap = 860, 24, 12, 3
    cols = (width - 2 * pad + gap) // (size + gap)
    cells = squares(row)
    total = sum(cells)
    rows = -(-total // cols)
    top = 112
    legend_y = top + rows * (size + gap) + 26
    height = legend_y + 46
    readable = int(row['reviewed']) + int(row['hand'])
    sans = "Segoe UI, -apple-system, BlinkMacSystemFont, Helvetica, Arial, sans-serif"
    serif = "Georgia, 'Times New Roman', serif"
    out = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" '
           f'role="img" aria-label="{pct(readable, row["game_functions"])} of Lionhead\'s game functions are '
           f'human-readable C++ ({n(readable)} of {n(row["game_functions"])}), as of {row["date"]}">',
           f'<text x="{pad}" y="30" font-family="{sans}" font-size="12" letter-spacing="1.2" fill="{c["muted"]}">'
           f'FABLE II IN HUMAN-READABLE C++ · LIONHEAD\'S GAME CODE · {row["date"]}</text>',
           f'<text x="{pad}" y="78" font-family="{serif}" font-size="46" fill="{c["fg"]}">'
           f'{pct(readable, row["game_functions"])}</text>',
           f'<text x="{pad + 150}" y="62" font-family="{sans}" font-size="16" fill="{c["fg"]}">of the game\'s functions '
           f'are human-readable C++: {n(readable)} of {n(row["game_functions"])}.</text>',
           f'<text x="{pad + 150}" y="84" font-family="{sans}" font-size="13" fill="{c["muted"]}">Almost all the rest '
           f'already runs as exact machine-translated C++. Each square is about 100 functions.</text>']
    i = 0
    for (k, _, _), cnt in zip(KINDS, cells):
        for _ in range(cnt):
            x, y = pad + (i % cols) * (size + gap), top + (i // cols) * (size + gap)
            out.append(f'<rect x="{x}" y="{y}" width="{size}" height="{size}" rx="2.5" fill="{c[k]}"/>')
            i += 1
    step = (width - 2 * pad) // len(KINDS)
    for j, (k, _, short) in enumerate(KINDS):
        x = pad + j * step
        out.append(f'<rect x="{x}" y="{legend_y - 10}" width="12" height="12" rx="2.5" fill="{c[k]}"/>')
        out.append(f'<text x="{x + 18}" y="{legend_y}" font-family="{sans}" font-size="13" fill="{c["fg"]}">'
                   f'{esc(short)}</text>')
        out.append(f'<text x="{x + 18}" y="{legend_y + 18}" font-family="{sans}" font-size="12" fill="{c["muted"]}">'
                   f'{n(row[k])} · {pct(row[k], row["game_functions"])}</text>')
    out.append('</svg>')
    return '\n'.join(out) + '\n'


def picture(prefix, row):
    readable = int(row['reviewed']) + int(row['hand'])
    return (f'<picture>\n  <source media="(prefers-color-scheme: dark)" srcset="{prefix}progress-dark.svg">\n'
            f'  <img alt="{pct(readable, row["game_functions"])} of Lionhead\'s game functions are human-readable C++ '
            f'({n(readable)} of {n(row["game_functions"])}), as of {row["date"]}" src="{prefix}progress-light.svg" '
            f'width="860">\n</picture>')


def kind_table(row):
    lines = ['| Lionhead\'s game code | Functions | Share |', '|---|---:|---:|']
    for k, label, _ in KINDS:
        lines.append(f'| {label} | {n(row[k])} | {pct(row[k], row["game_functions"])} |')
    lines.append(f'| **All of Lionhead\'s functions** | **{n(row["game_functions"])}** | |')
    return '\n'.join(lines)


def readme_block(row):
    readable = int(row['reviewed']) + int(row['hand'])
    return '\n'.join([
        BEGIN,
        picture('docs/images/', row),
        '',
        kind_table(row),
        '',
        f'{n(row["modules"])} reviewed class modules; {n(row["named"])} of the game\'s functions '
        f'({pct(row["named"], row["game_functions"])}) carry a name in the shared dictionary. By code size, '
        f'{pct(row["readable_bytes"], row["game_bytes"])} of the game is human-readable so far '
        f'({n(readable)} functions). Details, every area of the executable and the history: '
        f'[conversion progress](docs/progress.md). Counted by `tools/progress.py` from the files in this '
        f'repository, as of {row["date"]}.',
        END])


def page(m, history):
    row = history[-1]
    readable = int(row['reviewed']) + int(row['hand'])
    out = ['# Conversion progress', '',
           '<!-- written by tools/progress.py from tracked files: do not edit by hand -->', '',
           f'As of **{row["date"]}**, **{pct(readable, row["game_functions"])}** of Lionhead\'s game functions are '
           f'human-readable C++ in this repository: {n(readable)} of {n(row["game_functions"])}, '
           f'{pct(row["readable_bytes"], row["game_bytes"])} of the game\'s code by size. Fable2RE rebuilds the game as '
           f'readable C++ ([direction](project-direction.md)); this page counts how far that has come.', '',
           picture('images/', row), '',
           '## Lionhead\'s game code', '',
           'The game and engine code and its start-up initialisers: the code Lionhead wrote.', '',
           '| Kind | Functions | Share | Code bytes | Share |', '|---|---:|---:|---:|---:|']
    for k, label, _ in KINDS:
        b = sum(m['size'][a][k] for a in LIONHEAD)
        out.append(f'| {label} | {n(row[k])} | {pct(row[k], row["game_functions"])} | {n(b)} | '
                   f'{pct(b, row["game_bytes"])} |')
    out += [f'| **Total** | **{n(row["game_functions"])}** | | **{n(row["game_bytes"])}** | |', '',
            '## The whole executable', '',
            'Every function of `default.xex`, by area ([scope](../research/catalog/scope.tsv)). Middleware and '
            'system libraries are not reconstructed as readable code; they are to be replaced by native PC '
            'equivalents ([roadmap](roadmap.md)).', '',
            '| Area | Functions | Human-readable | Machine-translated | Recompiled only |', '|---|---:|---:|---:|---:|']
    for a, label in AREAS:
        c = m['count'][a]
        total = sum(c.values())
        readable_a = sum(c[k] for k in READABLE)
        out.append(f'| {label} | {n(total)} | {n(readable_a)} ({pct(readable_a, total)}) | '
                   f'{n(c["translated"])} ({pct(c["translated"], total)}) | {n(c["recompiled"])} '
                   f'({pct(c["recompiled"], total)}) |')
    out += [f'| **All** | **{n(row["executable_functions"])}** | **{n(row["executable_readable"])}** '
            f'({pct(row["executable_readable"], row["executable_functions"])}) | | |', '',
            '## Names', '',
            'The shared naming dictionary ([research/names](../research/names/README.md)) that every translation '
            'and every readable module uses.', '',
            '| Names | Count |', '|---|---:|',
            f'| Game functions with a name | {n(row["named"])} ({pct(row["named"], row["game_functions"])}) |',
            f'| Function names | {n(m["names"]["functions"])} |',
            f'| Class names | {n(m["names"]["classes"])} |',
            f'| Field names | {n(m["names"]["fields"])} |',
            f'| Local variable names | {n(m["names"]["locals"])} |', '',
            '## History', '',
            'A row for every day the numbers changed in this repository.', '',
            '| Date | Human-readable | Share | Reviewed | By hand | Machine-translated | Recompiled only | Named |',
            '|---|---:|---:|---:|---:|---:|---:|---:|']
    for r in reversed(history):
        rd = int(r['reviewed']) + int(r['hand'])
        out.append(f'| {r["date"]} | {n(rd)} | {pct(rd, r["game_functions"])} | {n(r["reviewed"])} | {n(r["hand"])} | '
                   f'{n(r["translated"])} | {n(r["recompiled"])} | {n(r["named"])} |')
    out += ['', '## What is counted', '']
    for k, label, _ in KINDS:
        out.append(f'- **{label}.** {DEFINITIONS[k]}')
    out += ['', 'Every function of the executable counts once, in its most finished form. Only files in this repository '
            'count: the catalog (`research/catalog/`), the published modules (`Fable2Recomp/promoted/`), the '
            'hand-written replacements (`Fable2Recomp/src/game/`), the verification manifest '
            '(`research/lift/verified.json.gz`) and the dictionary (`research/names/`). Work on a development '
            'machine that is not published yet (rewrites waiting for review, newer tester results) counts once it '
            'is. `python tools/progress.py` updates this page, the chart and the README; `--check` (run by the CI '
            'and by `tools/publish.py`) fails when they are out of date.', '']
    return '\n'.join(out)


def outputs(m, history):
    """{path: text} of everything this script writes."""
    row = history[-1]
    files = {HISTORY: history_text(history), PAGE: page(m, history)}
    for theme, path in CHARTS.items():
        files[path] = chart(row, theme)
    readme = README.read_text(encoding='utf-8').replace('\r\n', '\n')
    if BLOCK.search(readme):
        files[README] = BLOCK.sub(lambda _: readme_block(row), readme, count=1)
    return files


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--check', action='store_true', help='exit 1 when an output is out of date (writes nothing)')
    a = ap.parse_args()
    m = measure()
    today = os.environ.get('PROGRESS_DATE') or datetime.date.today().isoformat()
    history = read_history()
    new_history = updated_history(history, summary(m), today)
    files = outputs(m, new_history)
    stale = [p for p, text in files.items()
             if not p.exists() or p.read_text(encoding='utf-8').replace('\r\n', '\n') != text]
    if not BLOCK.search(README.read_text(encoding='utf-8')):
        print(f'progress: README.md has no {BEGIN[:22]}...{END} block')
        return 1
    row = new_history[-1]
    readable = int(row['reviewed']) + int(row['hand'])
    status = (f'{pct(readable, row["game_functions"])} of Lionhead\'s game functions human-readable '
              f'({n(readable)} of {n(row["game_functions"])}), as of {row["date"]}')
    if a.check:
        if stale:
            print('progress: out of date (python tools/progress.py): '
                  + ', '.join(str(p.relative_to(ROOT)).replace(os.sep, '/') for p in stale))
            return 1
        print('progress: up to date: ' + status)
        return 0
    for p in stale:
        p.parent.mkdir(parents=True, exist_ok=True)
        with open(p, 'w', encoding='utf-8', newline='\n') as f:
            f.write(files[p])
    print(f'progress: {status}; ' + (f'{len(stale)} file(s) written' if stale else 'nothing to write'))
    return 0


if __name__ == '__main__':
    sys.exit(main())
