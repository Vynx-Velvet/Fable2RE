"""The whole-game register analysis (summarize.py, ~30 min) as a file that ships with the project,
so users do not have to compute it.

It contains only facts about the executable: for each function address, bit masks of the registers it reads,
may change and returns, which values need 64 bits, and which functions can be called through pointers. It
contains no code. It is tied to the executable it was computed from and to the analysis rules
(ANALYSIS_VERSION in summarize.py). lift.py uses it only when both match.

An executable's identity is the SHA-256 of its true extent: the bytes its XEX header accounts for
(tools/xex_info.py). A copy with junk after the executable is therefore the same executable. An older extract
produced such a copy by over-reading the file to 100 MiB. Some identities were recorded as whole-file hashes of
that copy. tools/xex_info.py ALIASES maps those hashes to the executable they contain, and xex_matches()
compares through the map. The shipped research/lift/summaries.json.gz and research/lift/verified.json.gz record
39f0c8cd..., the over-read copy of the disc executable 88c4ef2e.... load() below, and so lift.py and
difftest/run.py, accept the analysis for both files. A record describes both files only for a consumer that
compares through xex_matches(): one that compares bundle.xex_sha256() with == refuses the 21 MB disc file. That
includes tools/lift/difftest/make_skip.py with the verification manifest, until it compares through
xex_matches() and xex_identity().

  python tools/lift/bundle.py export [--xex PATH]   cache/*.pkl -> research/lift/summaries.json.gz
  python tools/lift/bundle.py check [--xex PATH]    does the bundle match this machine's default.xex (or PATH)?

For other scripts:
  bundle.xex_matches(recorded_sha[, path_or_sha])
      Is the executable recorded as recorded_sha (a bundle's or manifest's xex_sha256) the one at path_or_sha?
      path_or_sha is a default.xex path, or an identity from xex_identity() (a recorded hash also works).
      Omitted, it is this machine's default.xex; None never matches. Do not pass xex_sha256()'s raw hash.
  bundle.xex_identity(path=None)
      (canonical SHA-256, path) of an executable. Compare and record this value.
  bundle.xex_sha256(path=None)
      (whole-file SHA-256, path). It names this exact file only: a padded copy of a supported executable has a
      whole-file hash no table knows. Use it for display, never for comparison.
"""
import argparse
import functools
import gzip
import importlib.util
import json
import os
import pickle
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
BUNDLE = os.path.join(ROOT, 'research', 'lift', 'summaries.json.gz')
CACHE = os.path.join(HERE, 'cache')
# where users have the executable (Fable2_config.toml: file_path = "assets/game/default.xex")
XEX_CANDIDATES = [os.path.join(ROOT, 'Fable2Recomp', 'assets', 'game', 'default.xex'),
                  os.path.join(ROOT, 'iso', 'extracted', 'default.xex')]


class XexInfoMissing(ImportError):
    """tools/xex_info.py, which identifies the executable, is missing or cannot be loaded."""


def _xex_info():
    """tools/xex_info.py: the XEX2 parser and the table of supported executables and aliases. It is loaded by path
    because tools/ is not on sys.path when the lifter scripts run. Raises XexInfoMissing when it cannot be loaded;
    load() reports that as its reason."""
    mod = sys.modules.get('xex_info')
    if mod is None:
        path = os.path.join(ROOT, 'tools', 'xex_info.py')
        if not os.path.isfile(path):
            raise XexInfoMissing('tools/xex_info.py is missing (it identifies default.xex; restore it from the '
                                 'repository)')
        spec = importlib.util.spec_from_file_location('xex_info', path)
        mod = importlib.util.module_from_spec(spec)
        sys.modules['xex_info'] = mod
        try:
            spec.loader.exec_module(mod)
        except Exception as e:
            del sys.modules['xex_info']
            raise XexInfoMissing(f'tools/xex_info.py cannot be loaded: {type(e).__name__}: {e}') from e
        except BaseException:
            del sys.modules['xex_info']
            raise
    return mod


def _shown(path):
    """A path for messages: relative to the repository when it lies inside it."""
    try:
        rel = os.path.relpath(path, ROOT)
    except ValueError:   # another drive
        return path
    return path if rel == os.pardir or rel.startswith(os.pardir + os.sep) else rel.replace(os.sep, '/')


def xex_path(path=None):
    """The default.xex to use. Returns `path` when given and present, else the first of XEX_CANDIDATES that exists.
    None when there is none."""
    if path:
        return path if os.path.isfile(path) else None
    return next((p for p in XEX_CANDIDATES if os.path.isfile(p)), None)


@functools.lru_cache(maxsize=None)
def _ids(path, size, mtime_ns):
    """(whole-file SHA-256, canonical identity) of one version of a file, computed once."""
    r = _xex_info().inspect(path, check_payload=False)
    return r.get('file_sha256'), r.get('canonical_sha256')


def _file_ids(path):
    st = os.stat(path)
    return _ids(os.path.abspath(path), st.st_size, st.st_mtime_ns)


def xex_sha256(path=None):
    """(SHA-256 of the whole file, path) of this machine's default.xex or `path`. (None, None) when absent.
    This raw file hash names this exact file only. Use it for display. To compare or record an executable use
    xex_identity(), or pass the path to xex_matches()."""
    p = xex_path(path)
    return (_file_ids(p)[0], p) if p else (None, None)


def xex_identity(path=None):
    """(canonical SHA-256, path) of this machine's default.xex or `path`. The hash covers the executable's true
    extent, so it is the same for an over-read copy (tools/xex_info.py). (None, None) when absent."""
    p = xex_path(path)
    return (_file_ids(p)[1], p) if p else (None, None)


def canonical_xex(sha):
    """The executable a recorded SHA-256 stands for: an alias resolves to its executable. Lower case."""
    return _xex_info().canonical(sha)


THIS_MACHINE = object()   # xex_matches(): this machine's default.xex (XEX_CANDIDATES)


def xex_matches(recorded_sha, path_or_sha=THIS_MACHINE):
    """Is the executable recorded as `recorded_sha` (a bundle's or manifest's xex_sha256) the one at `path_or_sha`?
    When omitted, `path_or_sha` is this machine's default.xex. An explicit None or a missing file never matches.
    Identical executables match through tools/xex_info.py ALIASES, so 39f0c8cd... (the over-read copy) matches
    88c4ef2e... and vice versa.

    Pass a path, or a hash that is itself an identity: xex_identity()'s value or another recorded xex_sha256. Do
    not pass a raw whole-file hash (xex_sha256()). Only the known alias resolves; the whole-file hash of any other
    padded copy matches nothing, although the file at its path would match."""
    want = canonical_xex(recorded_sha)
    if want is None or path_or_sha is None or path_or_sha == '':
        return False
    if path_or_sha is not THIS_MACHINE and _xex_info().is_sha256(path_or_sha):
        return canonical_xex(path_or_sha) == want
    p = xex_path(None if path_or_sha is THIS_MACHINE else path_or_sha)
    if p is None:
        return False
    file_sha, ident = _file_ids(p)
    return want in (canonical_xex(file_sha), ident)


def _short(sha):
    return f'{str(sha)[:16]}...' if sha else '?'


def _hexmap(d):
    return {k: format(v, 'x') for k, v in d.items() if v}


def _unhex(d):
    return {k: int(v, 16) for k, v in d.items()}


def export(xex=None):
    import summarize
    with open(os.path.join(CACHE, 'summaries.pkl'), 'rb') as f:
        sm = pickle.load(f)
    with open(os.path.join(CACHE, 'address_taken.pkl'), 'rb') as f:
        taken = pickle.load(f)
    sha, path = xex_identity(xex)   # the canonical identity, the same for an over-read copy
    if not sha:
        sys.exit(f'{xex or "default.xex"} not found')
    names = sorted(sm['inputs'])
    doc = {
        'format': 'fable2re-lift-summaries',
        'xex_sha256': sha,
        'analysis_version': summarize.ANALYSIS_VERSION,
        'resources': __import__('regs').NAMES,  # bit i of every mask = resource i
        'functions': names,
        'inputs': _hexmap(sm['inputs']),
        'mods': _hexmap(sm['mods']),
        'outputs': _hexmap(sm['outputs']),
        'rin': _hexmap(sm.get('rin', {})),   # (inputs split: really read / may be passed on)
        'fwd': _hexmap(sm.get('fwd', {})),
        'wide_in': _hexmap(sm.get('wide_in', {})),
        'wide_out': _hexmap(sm.get('wide_out', {})),
        'ind': {k: format(v, 'x') for k, v in sm.get('ind', {}).items()},
        'slot_wide': {str(k): format(v, 'x') for k, v in sm.get('slot_wide', {}).items()},
        'failed': sm.get('failed', {}),
        'address_taken': sorted(taken),
        'vtables': {str(k): sorted(v) for k, v in pickle.load(open(os.path.join(CACHE, 'vtables.pkl'), 'rb')).items()},
    }
    sig_path = os.path.join(CACHE, 'signatures.pkl')  # precise signatures (tools/lift/signatures.py)
    if os.path.exists(sig_path):
        with open(sig_path, 'rb') as f:
            sg = pickle.load(f)
        doc['sig_params'] = _hexmap(sg['params'])
        doc['sig_ret'] = _hexmap(sg['ret'])
    os.makedirs(os.path.dirname(BUNDLE), exist_ok=True)
    with gzip.open(BUNDLE, 'wt', encoding='utf-8') as f:
        json.dump(doc, f, separators=(',', ':'))
    print(f'wrote {BUNDLE} ({os.path.getsize(BUNDLE) // 1024} KB) for default.xex {_short(sha)}')


def load(xex=None):
    """The bundled summaries in lift.py's format, or (None, reason). `xex` is the default.xex to check against.
    By default it is this machine's (XEX_CANDIDATES)."""
    import summarize
    import regs
    if not os.path.exists(BUNDLE):
        return None, 'no bundled analysis (research/lift/summaries.json.gz)'
    try:
        _xex_info()
    except XexInfoMissing as e:
        return None, str(e)
    with gzip.open(BUNDLE, 'rt', encoding='utf-8') as f:
        doc = json.load(f)
    path = xex_path(xex)
    if path is None:
        return None, (f'{xex} not found' if xex else
                      'default.xex not found (expected in Fable2Recomp/assets/game/)')
    recorded = doc.get('xex_sha256')
    if not xex_matches(recorded, path):
        return None, (f'bundled analysis is for a different default.xex ({_short(recorded)}, '
                      f'yours {_short(xex_identity(path)[0])}; python tools/xex_info.py identifies it)')
    if doc.get('analysis_version') != summarize.ANALYSIS_VERSION:
        return None, (f'bundled analysis has version {doc.get("analysis_version")}, the lifter expects '
                      f'{summarize.ANALYSIS_VERSION}')
    if doc.get('resources') != regs.NAMES:
        return None, 'bundled analysis uses a different register numbering'
    names = doc['functions']

    def full(key):
        m = _unhex(doc[key])
        return {f: m.get(f, 0) for f in names}
    sm = {'inputs': full('inputs'), 'mods': full('mods'), 'outputs': full('outputs'),
          'wide_in': full('wide_in'), 'wide_out': full('wide_out'),
          'ind': {k: int(v, 16) for k, v in doc['ind'].items()}, 'failed': doc.get('failed', {}),
          'slot_wide': {int(k): int(v, 16) for k, v in doc.get('slot_wide', {}).items()}}
    if 'rin' in doc and 'fwd' in doc:
        sm['rin'], sm['fwd'] = full('rin'), full('fwd')
    if 'sig_params' in doc:
        sm['signatures'] = {'params': full('sig_params'), 'ret': full('sig_ret')}
    ident = xex_identity(path)[0]
    same = '' if str(recorded).lower() == ident else f', recorded as {_short(recorded)}: the same executable'
    return sm, f'bundled analysis matches this default.xex ({_shown(path)}: {_short(ident)}{same})'


def main():
    ap = argparse.ArgumentParser(description='The shipped whole-game register analysis (research/lift/summaries.json.gz).')
    ap.add_argument('cmd', nargs='?', default='check', choices=['check', 'export'],
                    help='check (default): does the bundle match the executable; export: write the bundle')
    ap.add_argument('--xex', help='the default.xex to use (default: Fable2Recomp/assets/game/default.xex, '
                                  'else iso/extracted/default.xex)')
    args = ap.parse_args()
    try:   # print characters the output encoding lacks (a path, redirected on Windows) as escapes
        sys.stdout.reconfigure(errors='backslashreplace')
    except (AttributeError, ValueError, OSError):
        pass
    if args.cmd == 'export':
        try:
            export(args.xex)
        except XexInfoMissing as e:
            sys.exit(f'bundle.py: {e}')
    else:
        sm, why = load(args.xex)
        print(('OK: ' if sm else 'NO: ') + why)
        sys.exit(0 if sm else 1)


if __name__ == '__main__':
    main()
