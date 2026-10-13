"""Publish progress to the hosted repository in one command (docs/publishing.md).

Progress is what the project gains between sessions and may be published: the research data (research/: the
naming dictionary, the catalog, findings, the shipped analysis, class model and verification manifest), the
documentation (docs/), and promoted modules whose functions are all reviewed OK (Fable2Recomp/src/game/promoted/
with REVIEW.tsv). Changes anywhere else (tools, runtime code, the SDK patch) are listed and left out: commit those
yourself, with a message that explains them.

    python tools/publish.py                  what would be published, and every check (changes nothing)
    python tools/publish.py --refresh        first export the verification manifest and the class model again
                                             (the development machine: from its tester results and class model)
    python tools/publish.py --commit         commit it on main, locally
    python tools/publish.py --publish        commit, push it to a progress/<date> branch with a pull request, wait
                                             for the CI and move main to it (a fast-forward: no merge commit)
    python tools/publish.py --publish --no-merge
                                             leave the pull request open: merge it on GitHub (Create a merge
                                             commit), then git pull
Options: --note TEXT adds a paragraph to the commit message, --trailer LINE a trailer (Co-Authored-By: ...).

Every check must pass before a commit:
  * the commit identity and the staged changes contain none of the strings in .git/info/publish-private (one per
    line: your e-mail addresses, names, machine paths; the file lives in .git and is never committed)
  * main is the branch, and it is not behind origin/main
  * tools/validate_metadata.py, tools/validate_commit.py (game material, user folders, promoted modules without
    review records), git diff --check, the unit tests (tools/tests, tools/test_commit_validation.py),
    tools/sdk_patch.py status, tools/lift/bundle.py check (when default.xex is here)
  * on a machine with lifted code: the shipped class model and verification manifest are the ones this lift was
    made with (classes.py --verify; make_skip.py --manifest finds no function whose lifted text differs from the
    text that was tested). A new setup then lifts exactly the tested text. Published unchanged, a mismatch is a
    warning (run the tester, then --refresh).
"""
import argparse
import datetime
import gzip
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PROGRESS = ('research/', 'docs/')
PROMOTED = 'Fable2Recomp/src/game/promoted/'
REVIEW = PROMOTED + 'REVIEW.tsv'
MANIFEST = 'research/lift/verified.json.gz'
CLASS_MODEL = 'research/lift/class_model.json.gz'
FINDINGS = 'research/findings/'
# naming dictionary: file -> (key columns, name column, what)
NAMES = {
    'research/names/functions.tsv': ((0,), 1, 'functions'),
    'research/names/classes.tsv': ((0,), 1, 'classes'),
    'research/names/fields.tsv': ((0, 1), 2, 'fields'),
    'research/names/locals.tsv': ((0, 1), 2, 'locals'),
}
ENTRY = re.compile(r'^PROMOTED_ENTRY\(\d+, (sub_[0-9A-F]{8}), 0x[0-9A-F]{8}\)', re.M)
COUNTS = re.compile(r'hash differs: (\d+)')


# ---- git ---------------------------------------------------------------------------------------------------------

def git(*args, check=True, input=None, binary=False):
    """git -C ROOT args; the completed process (text, or bytes with binary=True)."""
    r = subprocess.run(['git', '-C', str(ROOT), *args], input=input, capture_output=True, text=not binary,
                       encoding=None if binary else 'utf-8', errors=None if binary else 'replace')
    if check and r.returncode:
        err = r.stderr.decode('utf-8', 'replace') if binary else r.stderr
        sys.exit(f'publish: git {" ".join(args)} failed: {err.strip()}')
    return r


def changed_paths():
    """Paths with changes (staged, unstaged or untracked; renames as both paths), submodules left out."""
    items = git('status', '--porcelain=v1', '-z', '--untracked-files=all', '--ignore-submodules=all').stdout.split('\0')
    paths, i = set(), 0
    while i < len(items):
        entry = items[i]
        i += 1
        if not entry:
            continue
        paths.add(entry[3:])
        if entry[0] in 'RC' or entry[1] in 'RC':
            if i < len(items) and items[i]:
                paths.add(items[i])   # (the path it was renamed or copied from)
            i += 1
    return sorted(paths)


def head_bytes(path):
    """The file at HEAD (bytes), or None."""
    r = git('show', f'HEAD:{path}', check=False, binary=True)
    return r.stdout if r.returncode == 0 else None


def work_bytes(path):
    p = ROOT / path
    return p.read_bytes() if p.is_file() else None


# ---- what is published -------------------------------------------------------------------------------------------

def review_records():
    """function -> verdict from the working tree's REVIEW.tsv of the promoted modules."""
    p = ROOT / REVIEW
    rows = {}
    if p.is_file():
        for line in p.read_text(encoding='utf-8').splitlines()[1:]:
            cells = line.split('\t')
            if len(cells) >= 3:
                rows[cells[1]] = cells[2]
    return rows


def select(paths):
    """(publish, held {path: problems}, other): progress paths, promoted modules that are not reviewed yet, the
    rest."""
    sys.path.insert(0, str(ROOT / 'tools'))
    import validate_commit
    reviewed = None
    publish, held, other = [], {}, []
    for p in paths:
        if p.startswith(PROGRESS):
            publish.append(p)
        elif p.startswith(PROMOTED):
            f = ROOT / p
            if p.endswith('.cpp') and f.is_file():
                if reviewed is None:
                    reviewed = review_records()
                problems = validate_commit.promoted_problems(p, f.read_text(encoding='utf-8'), reviewed)
                if problems:
                    held[p] = problems
                    continue
            publish.append(p)
        else:
            other.append(p)
    return publish, held, other


# ---- summary -----------------------------------------------------------------------------------------------------

def tsv_rows(data, keys, name):
    """{key tuple: name} of a dictionary file's rows (bytes or None)."""
    rows = {}
    if data:
        for line in data.decode('utf-8', 'replace').splitlines()[1:]:
            c = line.split('\t')
            if len(c) > max(max(keys), name):
                rows[tuple(c[k] for k in keys)] = c[name]
    return rows


def names_change(old, new, keys, name):
    """(added, renamed, removed) between two versions of a dictionary file."""
    a, b = tsv_rows(old, keys, name), tsv_rows(new, keys, name)
    return (sum(1 for k in b if k not in a), sum(1 for k in b if k in a and a[k] != b[k]),
            sum(1 for k in a if k not in b))


def gz_json(data):
    if not data:
        return None
    try:
        return json.loads(gzip.decompress(data).decode('utf-8'))
    except (OSError, ValueError):
        return None


def verified_count(doc):
    return sum(1 for v in doc.get('functions', {}).values() if v[1] == 'OK') if doc else 0


def first_heading(data):
    for line in (data or b'').decode('utf-8', 'replace').splitlines():
        if line.startswith('# '):
            return line[2:].strip()
    return None


def summarize(publish):
    """(subject parts, body lines) describing the published changes."""
    parts, lines = [], []
    added_names = 0
    name_lines = []
    for path, (keys, name, what) in NAMES.items():
        if path in publish:
            added, renamed, removed = names_change(head_bytes(path), work_bytes(path), keys, name)
            added_names += added
            bits = [f'+{added:,}'] + ([f'{renamed:,} renamed'] if renamed else []) + ([f'-{removed:,}'] if removed else [])
            name_lines.append(f'{what} {", ".join(bits)}')
    if name_lines:
        parts.append(f'names +{added_names:,}')
        lines.append('Names: ' + '; '.join(name_lines) + '.')
    modules = [p for p in publish if p.startswith(PROMOTED) and p.endswith('.cpp') and (ROOT / p).is_file()]
    if modules:
        count = sum(len(ENTRY.findall((ROOT / p).read_text(encoding='utf-8'))) for p in modules)
        new = sum(1 for p in modules if head_bytes(p) is None)
        parts.append(f'{len(modules)} module{"s" * (len(modules) != 1)}')
        lines.append(f'Promoted modules: {len(modules)} ({new} new, {count:,} functions): '
                     + ', '.join(Path(p).stem for p in sorted(modules)) + '.')
    if MANIFEST in publish:
        old, now = gz_json(head_bytes(MANIFEST)), gz_json(work_bytes(MANIFEST))
        parts.append('test records')
        lines.append(f'Verification manifest: {verified_count(now):,} functions tested OK '
                     f'(was {verified_count(old):,}).')
    if CLASS_MODEL in publish:
        old, now = gz_json(head_bytes(CLASS_MODEL)), gz_json(work_bytes(CLASS_MODEL))
        parts.append('class model')
        was = f' (was {len(old["classes"]):,} and {len(old["this"]):,})' if old else ' (new)'
        lines.append(f'Class model: {len(now["classes"]):,} classes, {len(now["this"]):,} functions with a '
                     f'`this` class{was}.' if now else 'Class model: removed.')
    findings = [p for p in publish if p.startswith(FINDINGS) and p.endswith('.md') and head_bytes(p) is None
                and (ROOT / p).is_file()]
    if findings:
        parts.append(f'{len(findings)} finding{"s" * (len(findings) != 1)}')
        lines.append('Findings: ' + '; '.join(first_heading(work_bytes(p)) or Path(p).stem for p in findings) + '.')
    rest = [p for p in publish if p not in NAMES and p not in (MANIFEST, CLASS_MODEL) and p not in findings
            and p not in modules]
    if rest:
        if not parts:
            parts.append('research and docs')
        shown = ', '.join(rest[:12]) + (f' and {len(rest) - 12} more' if len(rest) > 12 else '')
        lines.append(f'Also: {shown}.')
    return parts, lines


def message(parts, lines, notes, trailers, today):
    subject = f'Progress {today}: ' + ', '.join(parts)
    if len(subject) > 72:
        subject = subject[:69].rstrip(', ') + '...'
    body = '\n\n'.join(lines + list(notes) + ['Published with tools/publish.py (docs/publishing.md); every check '
                                               'passed.'])
    text = subject + '\n\n' + body + '\n'
    if trailers:
        text += '\n' + '\n'.join(trailers) + '\n'
    return subject, text


# ---- private strings -----------------------------------------------------------------------------------------------

def private_file():
    p = git('rev-parse', '--git-path', 'info/publish-private').stdout.strip()
    return Path(p) if os.path.isabs(p) else ROOT / p


def private_strings():
    p = private_file()
    if not p.is_file():
        return []
    return [l.strip() for l in p.read_text(encoding='utf-8').splitlines() if l.strip() and not l.startswith('#')]


def _fold(text):
    return text.replace('\\', '/').lower()


def private_hits(strings, text):
    """The private strings that occur in the text (case and slash direction ignored)."""
    t = _fold(text)
    return [s for s in strings if _fold(s) in t]


# ---- checks ------------------------------------------------------------------------------------------------------

class Checks:
    def __init__(self):
        self.rows = []

    def add(self, status, what, detail=''):
        self.rows.append((status, what, detail))
        print(f'  {status:<5} {what}' + (f': {detail}' if detail else ''))

    def failed(self):
        return [r for r in self.rows if r[0] == 'FAIL']


def tool(args, cwd=None):
    """(exit status, output) of a Python tool or command."""
    r = subprocess.run(args, cwd=str(cwd or ROOT), capture_output=True, text=True, encoding='utf-8',
                       errors='replace')
    return r.returncode, (r.stdout + r.stderr).strip()


def tail(text, n=6):
    return ' | '.join(text.splitlines()[-n:])


def run_checks(publish, checks, offline, private, jobs):
    py = sys.executable
    name = git('config', 'user.name', check=False).stdout.strip()
    email = git('config', 'user.email', check=False).stdout.strip()
    hits = private_hits(private, f'{name}\n{email}')
    checks.add('FAIL' if hits or not email else 'OK', 'commit identity',
               f'{name} <{email}>' + (f' contains private {", ".join(hits)}' if hits else '')
               + ('' if email else ' (no user.email)'))
    branch = git('rev-parse', '--abbrev-ref', 'HEAD').stdout.strip()
    checks.add('OK' if branch == 'main' else 'FAIL', 'branch', branch)
    if git('remote', 'get-url', 'origin', check=False).returncode == 0:
        if not offline:
            r = git('fetch', '-q', 'origin', check=False)
            if r.returncode:
                checks.add('FAIL', 'fetch origin', r.stderr.strip())
        r = git('rev-list', '--left-right', '--count', 'origin/main...HEAD', check=False)
        if r.returncode == 0:
            behind, ahead = (int(x) for x in r.stdout.split())
            checks.add('FAIL' if behind else 'OK', 'origin/main',
                       (f'main is {behind} commit(s) behind: git pull first' if behind else 'not behind')
                       + (f'; {ahead} local commit(s) not pushed yet go along' if ahead else ''))
    else:
        checks.add('SKIP', 'origin/main', 'no remote named origin')

    rc, out = tool([py, 'tools/validate_metadata.py'])
    checks.add('OK' if rc == 0 else 'FAIL', 'validate_metadata.py', tail(out, 1 if rc == 0 else 8))
    rc, out = tool([py, 'tools/validate_commit.py'])
    checks.add('OK' if rc == 0 else 'FAIL', 'validate_commit.py', tail(out, 1 if rc == 0 else 8))
    r = git('diff', '--cached', '--check', check=False)
    checks.add('OK' if r.returncode == 0 else 'FAIL', 'whitespace (git diff --check)', tail(r.stdout, 6))
    rc, out = tool([py, '-m', 'unittest', 'discover', '-s', 'tools/tests'])
    checks.add('OK' if rc == 0 else 'FAIL', 'unit tests (tools/tests)', tail(out, 1 if rc == 0 else 10))
    rc, out = tool([py, '-m', 'unittest', 'test_commit_validation'], cwd=ROOT / 'tools')
    checks.add('OK' if rc == 0 else 'FAIL', 'unit tests (test_commit_validation.py)', tail(out, 1 if rc == 0 else 10))
    rc, out = tool([py, 'tools/sdk_patch.py', 'status'])
    checks.add('OK' if rc == 0 else 'FAIL', 'sdk_patch.py status', tail(out, 1 if rc == 0 else 6))
    xex = [p for p in (ROOT / 'Fable2Recomp/assets/game/default.xex', ROOT / 'iso/extracted/default.xex') if p.is_file()]
    if xex:
        rc, out = tool([py, 'tools/lift/bundle.py', 'check'])
        checks.add('OK' if rc == 0 else 'FAIL', 'bundle.py check', tail(out, 1))
    else:
        checks.add('SKIP', 'bundle.py check', 'no default.xex on this machine')

    lift = ROOT / 'tools' / 'lift'
    if (lift / 'cache' / 'classes.json').is_file() and (ROOT / CLASS_MODEL).is_file():
        rc, out = tool([py, 'classes.py', '--verify'], cwd=lift)
        status = 'OK' if rc == 0 else 'FAIL' if CLASS_MODEL in publish else 'WARN'
        checks.add(status, 'class model = this lift (classes.py --verify)', tail(out, 1))
    else:
        checks.add('SKIP', 'class model = this lift', 'no class model built here')
    lifted = ROOT / 'Fable2Recomp' / 'lifted'
    if (ROOT / MANIFEST).is_file() and lifted.is_dir() and any(lifted.glob('lifted.*.*.cpp')):
        with tempfile.TemporaryDirectory(prefix='f2_publish_') as tmp:
            rc, out = tool([py, 'difftest/make_skip.py', '--manifest', str(ROOT / MANIFEST), '--out',
                            os.path.join(tmp, 'skip.txt'), '--jobs', str(jobs)], cwd=lift)
        m = COUNTS.search(out)
        differs = int(m.group(1)) if m else None
        ok = rc == 0 and differs == 0
        status = 'OK' if ok else 'FAIL' if MANIFEST in publish else 'WARN'
        detail = (f'{differs:,} lifted functions differ from the text that was tested' if differs
                  else 'every tested function lifts to the tested text' if ok else tail(out, 3))
        if not ok and MANIFEST not in publish:
            detail += ' (published unchanged; run the tester, then publish with --refresh)'
        checks.add(status, 'verification manifest = this lift (make_skip.py --manifest)', detail)
    else:
        checks.add('SKIP', 'verification manifest = this lift', 'no lifted code here')

    diff = git('diff', '--cached', '-U0', '--no-color', '--no-ext-diff').stdout
    added = '\n'.join(l[1:] for l in diff.splitlines() if l.startswith('+') and not l.startswith('+++'))
    added += '\n' + git('diff', '--cached', '--name-only').stdout
    hits = private_hits(private, added)
    if private:
        checks.add('FAIL' if hits else 'OK', 'private strings (.git/info/publish-private)',
                   ('found: ' + ', '.join(hits)) if hits else f'none of {len(private)} in the staged changes')
    else:
        checks.add('WARN', 'private strings', f'{private_file()} is missing: list your e-mail addresses, names and '
                                              'machine paths there, one per line')


# ---- publishing --------------------------------------------------------------------------------------------------

def unique_branch(base):
    r = git('ls-remote', '--heads', 'origin', f'{base}*', check=False)
    taken = {l.split('refs/heads/', 1)[1] for l in r.stdout.splitlines() if 'refs/heads/' in l}
    if base not in taken:
        return base
    n = 2
    while f'{base}-{n}' in taken:
        n += 1
    return f'{base}-{n}'


def gh(*args, check=False):
    return subprocess.run(['gh', *args], cwd=str(ROOT), capture_output=True, text=True, encoding='utf-8',
                          errors='replace', check=check)


def wait_for_ci(branch, sha):
    """(conclusion, url) of the CI run for this commit on the branch; conclusion None when none appeared."""
    deadline = time.time() + 180
    run_id = None
    while time.time() < deadline and run_id is None:
        r = gh('run', 'list', '--branch', branch, '--json', 'databaseId,headSha', '--limit', '20')
        for x in json.loads(r.stdout or '[]') if r.returncode == 0 else []:
            if x.get('headSha') == sha:
                run_id = x['databaseId']
                break
        if run_id is None:
            time.sleep(5)
    if run_id is None:
        return None, None
    print(f'  waiting for CI run {run_id} ...')
    gh('run', 'watch', str(run_id), '--exit-status', '--interval', '10')
    r = gh('run', 'view', str(run_id), '--json', 'conclusion,url')
    info = json.loads(r.stdout or '{}') if r.returncode == 0 else {}
    return info.get('conclusion'), info.get('url')


def push_and_merge(subject, text, sha, today, merge):
    branch = unique_branch(f'progress/{today}')
    git('push', '-q', 'origin', f'HEAD:refs/heads/{branch}')
    print(f'pushed {sha[:12]} to {branch}')
    if not shutil.which('gh'):
        print('gh (GitHub CLI) not found: open the pull request on GitHub, merge it with a merge commit, then git pull')
        return 0
    body = text.split('\n', 2)[2] if text.count('\n') >= 2 else text
    r = gh('pr', 'create', '--base', 'main', '--head', branch, '--title', subject, '--body', body)
    url = r.stdout.strip() if r.returncode == 0 else None
    print(f'pull request: {url}' if url else f'pull request not created: {r.stderr.strip()}')
    if not merge:
        print('left open (--no-merge): merge it on GitHub with "Create a merge commit", then git pull')
        return 0
    conclusion, run_url = wait_for_ci(branch, sha)
    if conclusion != 'success':
        print(f'CI: {conclusion or "no run appeared within 3 minutes"} {run_url or ""}'.rstrip())
        print(f'main was not moved; the commit stays on {branch} and the pull request stays open. Fix it, then run '
              'publish.py --publish again (the new commit goes along).')
        return 1
    r = git('push', '-q', 'origin', 'HEAD:main', check=False)
    if r.returncode:
        print(f'CI passed, but main could not be moved (fast-forward refused: {r.stderr.strip()}). git pull, then '
              'run publish.py --publish again.')
        return 1
    git('push', '-q', 'origin', '--delete', branch, check=False)
    git('fetch', '-q', 'origin', check=False)
    print(f'CI passed ({run_url}); origin/main is now {sha[:12]}. GitHub shows the pull request as merged.')
    return 0


def refresh(checks, lift_jobs):
    """Export the manifest from this machine's tester results and the class model from its facts."""
    py = sys.executable
    lift = ROOT / 'tools' / 'lift'
    if (lift / 'difftest' / 'results' / 'status.json').is_file():
        rc, out = tool([py, 'difftest/make_skip.py', '--export-manifest'], cwd=lift)
        checks.add('OK' if rc == 0 else 'FAIL', 'refresh: verification manifest', tail(out, 1))
    else:
        checks.add('SKIP', 'refresh: verification manifest', 'no tester results on this machine')
    if (lift / 'cache' / 'facts').is_dir() and (lift / 'cache' / 'classes.json').is_file():
        rc, out = tool([py, 'classes.py', '--export'], cwd=lift)
        checks.add('OK' if rc == 0 else 'FAIL', 'refresh: class model', tail(out, 2))
    else:
        checks.add('SKIP', 'refresh: class model', 'no facts and class model on this machine')


def main():
    ap = argparse.ArgumentParser(description='Publish progress (research data, docs, reviewed promoted modules) in '
                                             'one command. Without --commit or --publish: report only.')
    ap.add_argument('--refresh', action='store_true', help='export the verification manifest and class model first')
    g = ap.add_mutually_exclusive_group()
    g.add_argument('--commit', action='store_true', help='commit on main, locally')
    g.add_argument('--publish', action='store_true', help='commit, push a branch with a pull request, wait for CI, '
                                                          'move main to it')
    ap.add_argument('--no-merge', action='store_true', help='with --publish: leave the pull request open')
    ap.add_argument('--note', action='append', default=[], help='a paragraph for the commit message')
    ap.add_argument('--trailer', action='append', default=[], help='a trailer line for the commit message')
    ap.add_argument('--offline', action='store_true', help='do not fetch origin (report only)')
    ap.add_argument('--jobs', type=int, default=min(8, os.cpu_count() or 1), help='processes for make_skip.py')
    a = ap.parse_args()
    try:   # (paths and messages the console code page cannot encode)
        sys.stdout.reconfigure(errors='backslashreplace')
    except (AttributeError, ValueError, OSError):
        pass
    if a.publish and a.offline:
        sys.exit('publish: --offline is for reports only')
    if git('diff', '--cached', '--quiet', '--ignore-submodules=all', check=False).returncode:
        sys.exit('publish: the index already has staged changes: commit them or unstage them (git reset) first')

    checks = Checks()
    if a.refresh:
        print('refresh:')
        refresh(checks, a.jobs)
        if checks.failed():
            sys.exit('publish: the refresh failed (see above)')
    publish, held, other = select(changed_paths())
    print(f'to publish ({len(publish)}):')
    for p in publish:
        print(f'  {p}')
    if held:
        print(f'held back ({len(held)} promoted module(s) not fully reviewed):')
        for p, problems in sorted(held.items()):
            print(f'  {p}: {problems[0]}' + (f' (+{len(problems) - 1} more)' if len(problems) > 1 else ''))
    if other:
        print(f'other changes, not published by this script ({len(other)}; commit them yourself):')
        for p in other[:20]:
            print(f'  {p}')
        if len(other) > 20:
            print(f'  ... and {len(other) - 20} more')
    ahead = 0
    if git('remote', 'get-url', 'origin', check=False).returncode == 0:
        r = git('rev-list', '--count', 'origin/main..HEAD', check=False)
        ahead = int(r.stdout.strip() or 0) if r.returncode == 0 else 0
    if not publish and not ahead:
        print('nothing to publish')
        return 0

    today = datetime.date.today().isoformat()
    committed = False
    try:
        if publish:
            git('--literal-pathspecs', 'add', '-A', '--pathspec-from-file=-', '--pathspec-file-nul',
                input='\0'.join(publish))
        print('checks:')
        run_checks(publish, checks, a.offline, private_strings(), a.jobs)
        parts, lines = summarize(publish)
        subject, text = message(parts, lines, a.note, a.trailer, today)
        print('commit message:')
        print('\n'.join('  | ' + l for l in text.rstrip('\n').split('\n')))
        if checks.failed():
            print(f'{len(checks.failed())} check(s) failed: nothing was committed')
            return 1
        if not (a.commit or a.publish):
            print('report only: run with --commit or --publish to publish this')
            return 0
        if publish:
            with tempfile.NamedTemporaryFile('w', encoding='utf-8', delete=False, suffix='.txt') as f:
                f.write(text)
            try:
                git('commit', '-q', '-F', f.name)
            finally:
                os.unlink(f.name)
            committed = True
            sha = git('rev-parse', 'HEAD').stdout.strip()
            print(f'committed {sha[:12]} on main')
        else:
            sha = git('rev-parse', 'HEAD').stdout.strip()
            subject = git('log', '-1', '--format=%s').stdout.strip()
            text = git('log', '-1', '--format=%B').stdout
            print(f'nothing new to commit; publishing the {ahead} local commit(s) up to {sha[:12]}')
        if a.publish:
            return push_and_merge(subject, text, sha, today, not a.no_merge)
        return 0
    finally:
        if not committed:
            git('reset', '-q', check=False)   # (the index was clean before: back to HEAD)


if __name__ == '__main__':
    sys.exit(main())
