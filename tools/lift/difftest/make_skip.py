"""Functions that must stay on their recompiled original: hand-written replacements (overridden.txt)
plus every lifted function the differential test has not shown identical in its current form (a problem,
or never tested / changed since its test). Reads results/status.json (run.py) and writes tools/lift/skip.txt.

lift.py leaves them out of the lifted output (removes their blocks from the chunk files):
    python tools/lift/lift.py --funcs tools/lift/skip.txt --skip tools/lift/skip.txt

The verification manifest (research/lift/verified.json.gz) carries the tester's verdicts to machines that have not
run the tester (a fresh setup from the user's own copy): per function only the hash of the lifted text it was
tested on (run.py block_hash: dictionary names and variable names left out) and the verdict class - no code. A
function whose lifted text has the same hash was tested in exactly that form.

  python make_skip.py                          status.json -> tools/lift/skip.txt
  python make_skip.py --export-manifest [PATH] status.json -> the manifest (default research/lift/verified.json.gz;
                                               verdicts of local rewrites, "OK [relaxed]", are left out)
  python make_skip.py --manifest PATH --out FILE
      the list from the manifest instead of status.json: overridden.txt, every lifted function that is not an
      exact hash match with verdict OK, and the manifest's problem functions that are not lifted (so FILE also
      serves as the skip list of later lifts). Exit 2 when the manifest is for another default.xex or analysis
      version. Then drop them:  python lift.py --funcs FILE --skip FILE
"""
import functools
import gzip
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
LIFT = os.path.dirname(HERE)
ROOT = os.path.normpath(os.path.join(LIFT, '..', '..'))
sys.path.insert(0, HERE)
import run  # noqa: E402
import chunks  # noqa: E402

SKIP = os.path.join(LIFT, 'skip.txt')
OVERRIDDEN = os.path.join(LIFT, 'overridden.txt')
MANIFEST = os.path.join(ROOT, 'research', 'lift', 'verified.json.gz')
MANIFEST_FORMAT = 1


def overridden():
    with open(OVERRIDDEN) as f:
        return {l.strip() for l in f if l.strip()}


def _hash_file(idx):
    """{name: block hash} of the lifted functions of generated file idx (a worker of current_hashes)."""
    return {n: run.block_hash(b) for blocks in run.lifted_blocks({idx}).values() for n, b in blocks.items()}


def current_hashes(files=None, jobs=1):
    """{name: run.block_hash} of every function in the lifted output (or in that of these generated files)."""
    if jobs <= 1:
        return {n: run.block_hash(b) for blocks in run.lifted_blocks(files).values() for n, b in blocks.items()}
    import multiprocessing as mp
    idx = sorted({int(m.group(1)) for f in os.listdir(chunks.OUT_DIR)
                  if (m := re.fullmatch(r'lifted\.(\d+)\.\d+\.cpp', f)) and (files is None or int(m.group(1)) in files)})
    out = {}
    with mp.Pool(jobs) as pool:
        for part in pool.imap_unordered(_hash_file, idx):
            out.update(part)
    return out


def _in(name, files):
    return files is None or chunks.file_of(name) in files


def write_list(path, names):
    with open(path, 'w') as f:
        f.write('\n'.join(sorted(names)) + '\n')


# ---- the skip list from this machine's tester results (status.json) -------------------------------------------

def status_skip(st, hashes, files=None):
    """(names, counts): overridden.txt plus the lifted functions status.json does not show OK in their current
    form, plus the dropped functions whose last result is a problem."""
    names = overridden()
    counts = {'problem': 0, 'untested/changed': 0}
    for n, h in hashes.items():
        if chunks.rewritten(n) is not None or chunks.promoted(n):
            continue   # (rewritten functions are accepted in relaxed mode, tools/rewrite: never a problem here)
        s = st.get(n)
        if s is None or s[0] != h:
            counts['untested/changed'] += 1
            names.add(n)
        elif not s[1].startswith('OK'):   # ('OK' / 'OK [relaxed]': a rewritten function, tools/rewrite)
            counts['problem'] += 1
            names.add(n)
    # functions already dropped from the lifted output keep their place on the list while their last result is a
    # problem (they are not in the lifted files any more, so the loop above does not see them)
    for n, s in st.items():
        if n not in hashes and not s[1].startswith('OK') and n not in names and chunks.rewritten(n) is None \
                and not chunks.promoted(n) and _in(n, files):
            counts['problem'] += 1
            names.add(n)
    return names, counts


# ---- the verification manifest ----------------------------------------------------------------------------------

@functools.cache
def _xex():
    """This machine's executable as an identity (the hash of the executable's true extent, tools/xex_info.py):
    the same for the disc's 21 MB default.xex and an over-read copy of it."""
    import bundle
    return bundle.xex_identity()[0]


def analysis_in_use():
    """(xex_sha256, analysis_version, what) of the whole-game analysis lift.py lifts with (lift.py summaries()):
    this machine's own (cache/summaries.pkl: its default.xex, the current rules) or the shipped one
    (research/lift/summaries.json.gz: the default.xex and version it names). None for what cannot be told."""
    import bundle
    if os.path.exists(os.path.join(LIFT, 'cache', 'summaries.pkl')):
        import summarize
        return _xex(), summarize.ANALYSIS_VERSION, "this machine's analysis (tools/lift/cache/summaries.pkl)"
    if not os.path.exists(bundle.BUNDLE):
        return None, None, 'no analysis (neither tools/lift/cache/summaries.pkl nor research/lift/summaries.json.gz)'
    with gzip.open(bundle.BUNDLE, 'rt', encoding='utf-8') as f:
        doc = json.load(f)
    return doc.get('xex_sha256'), doc.get('analysis_version'), 'the shipped analysis (research/lift/summaries.json.gz)'


def verdict_class(verdict):
    """A status.json verdict as the manifest has it: 'OK', the problem class ('MISMATCH', 'CRASH', 'UNTESTED',
    'BUILD FAILED'), or None for an acceptance only this machine can reproduce ('OK [relaxed]': a local rewrite,
    tools/rewrite - the rewritten text is not published)."""
    if verdict == 'OK':
        return 'OK'
    if verdict.startswith('OK'):
        return None
    m = re.match(r'[A-Z]+(?: FAILED)?\b', verdict)
    return m.group(0) if m else 'PROBLEM'


def export_manifest(path):
    st = run.load_status()
    if not st:
        sys.exit(f'make_skip: no tester results ({run.STATUS}): run tools/lift/difftest/run.py first')
    sha, ver, what = analysis_in_use()
    if sha is None or ver is None:
        sys.exit(f'make_skip: cannot tell the default.xex and analysis version of {what}')
    import bundle
    if _xex() is not None and not bundle.xex_matches(sha):
        sys.exit(f'make_skip: {what} is for another default.xex ({sha[:16]}..., this one {_xex()[:16]}...)')
    sha = bundle.canonical_xex(sha) or sha   # (new manifests name the executable, not an over-read copy)
    funcs, left_out = {}, 0
    for n, s in st.items():
        c = verdict_class(s[1])
        if c is None:
            left_out += 1
        else:
            funcs[n] = [s[0], c]
    # one function per line, fixed order and a fixed gzip header (no name, mtime 0): an unchanged export is the
    # same file, a changed one differs in its changed lines (zcat)
    text = ('{"format": %d,\n"xex_sha256": %s,\n"analysis_version": %s,\n"functions": {\n' %
            (MANIFEST_FORMAT, json.dumps(sha), json.dumps(ver))
            + ',\n'.join(f'{json.dumps(n)}: {json.dumps(funcs[n])}' for n in sorted(funcs)) + '\n}}\n')
    json.loads(text)   # (well-formed)
    path = os.path.abspath(path)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    tmp = path + '.tmp'
    with open(tmp, 'wb') as raw, gzip.GzipFile(filename='', mode='wb', fileobj=raw, compresslevel=9, mtime=0) as gz:
        gz.write(text.encode('utf-8'))
    os.replace(tmp, path)
    classes = {}
    for _, c in funcs.values():
        classes[c] = classes.get(c, 0) + 1
    print(f'wrote {path} ({os.path.getsize(path) // 1024} KB): {len(funcs)} functions '
          f'({", ".join(f"{k} {v}" for k, v in sorted(classes.items(), key=lambda kv: -kv[1]))}); '
          f'{left_out} local acceptances left out; default.xex {sha[:16]}..., analysis version {ver}')


def load_manifest(path):
    try:
        with gzip.open(path, 'rt', encoding='utf-8') as f:
            doc = json.load(f)
    except (OSError, ValueError) as e:
        print(f'make_skip: cannot read the manifest {path}: {e}')
        sys.exit(2)
    if doc.get('format') != MANIFEST_FORMAT or not isinstance(doc.get('functions'), dict):
        print(f'make_skip: {path} is not a verification manifest of format {MANIFEST_FORMAT}')
        sys.exit(2)
    return doc


def check_manifest(doc):
    """Why the manifest does not describe the lifted output of this machine ([] when it does)."""
    sha, ver, what = analysis_in_use()
    m_sha, m_ver = doc.get('xex_sha256'), doc.get('analysis_version')
    import bundle
    why = []
    # executables compare as identities: a manifest recorded with the over-read copy's hash is valid for the disc's
    # 21 MB default.xex and the other way round (bundle.xex_matches, tools/xex_info.py ALIASES)
    if bundle.xex_path() is not None and not bundle.xex_matches(m_sha):
        why.append(f'it is for another default.xex ({str(m_sha)[:16]}..., yours {str(_xex())[:16]}...)')
    elif sha is None or bundle.canonical_xex(m_sha) != bundle.canonical_xex(sha):
        why.append(f'it is for default.xex {str(m_sha)[:16]}..., {what} for {str(sha)[:16]}...')
    if m_ver != ver:
        why.append(f'it is for analysis version {m_ver}, {what} has {ver}')
    return why


def manifest_skip(doc, hashes, files=None):
    """(names, counts): overridden.txt plus every lifted function that is not an exact hash match with verdict OK
    in the manifest, plus the manifest's problem functions that are not lifted (they stay out of later lifts)."""
    names = overridden()
    funcs = doc['functions']
    counts = {'matched OK': 0, 'hash differs': 0, 'not in manifest': 0, 'manifest verdict not OK': 0,
              'overridden': len(names), 'not lifted, manifest verdict not OK': 0, 'local rewrites listed': 0}
    for n, h in hashes.items():
        if n in names:
            continue   # (listed anyway)
        e = funcs.get(n)
        if e is None:
            key = 'not in manifest'
        elif e[0] != h:
            key = 'hash differs'
        elif e[1] != 'OK':
            key = 'manifest verdict not OK'
        else:
            counts['matched OK'] += 1
            continue
        counts[key] += 1
        names.add(n)
        if os.path.exists(os.path.join(chunks.REWRITTEN_DIR, n + '.cpp')):
            counts['local rewrites listed'] += 1   # (accepted in relaxed mode here, not by the manifest)
    for n, e in funcs.items():
        if n not in hashes and e[1] != 'OK' and n not in names and not chunks.promoted(n) and _in(n, files):
            counts['not lifted, manifest verdict not OK'] += 1
            names.add(n)
    return names, counts


def main():
    import argparse
    ap = argparse.ArgumentParser(description='The skip list (functions left on their recompiled original) from the '
                                             'tester results, or the verification manifest that ships them.')
    ap.add_argument('files', nargs='*', type=int, help='only the lifted functions of these generated files '
                                                       '(testing; needs --out)')
    ap.add_argument('--export-manifest', nargs='?', const=MANIFEST, metavar='PATH',
                    help='write results/status.json as a verification manifest (default '
                         'research/lift/verified.json.gz)')
    ap.add_argument('--manifest', metavar='PATH', help='the list from this verification manifest instead of '
                                                      'status.json (needs --out)')
    ap.add_argument('--out', metavar='FILE', help='write the list here (default: tools/lift/skip.txt, '
                                                  'status.json mode only)')
    ap.add_argument('--jobs', type=int, default=1, help='hash the lifted output in this many processes')
    args = ap.parse_args()
    if args.export_manifest:
        if args.manifest or args.files:
            ap.error('--export-manifest takes no --manifest or files')
        export_manifest(args.export_manifest)
        return
    files = set(args.files) if args.files else None
    out = os.path.abspath(args.out) if args.out else None
    if args.manifest:
        if not out:
            ap.error('--manifest needs --out FILE')
        if os.path.normcase(out) == os.path.normcase(SKIP):
            ap.error('tools/lift/skip.txt is the tester\'s list (tracked): write the manifest\'s list elsewhere, '
                     'e.g. cache/manifest_skip.txt (what tools/setup_all.ps1 uses)')
        doc = load_manifest(args.manifest)
        why = check_manifest(doc)
        if why:
            print(f'make_skip: the manifest {args.manifest} does not apply here: {"; ".join(why)}')
            sys.exit(2)
        names, counts = manifest_skip(doc, current_hashes(files, args.jobs), files)
        write_list(out, names)
        print(f'skip list: {len(names)} functions -> {out} ({", ".join(f"{k}: {v}" for k, v in counts.items())})')
        return
    if files is not None and not out:
        ap.error('the list of some generated files only needs --out (it would replace tools/lift/skip.txt)')
    names, counts = status_skip(run.load_status(), current_hashes(files, args.jobs), files)
    write_list(out or SKIP, names)
    print(f'skip list: {len(names)} functions ({counts})' + (f' -> {out}' if out else ''))


if __name__ == '__main__':
    main()
