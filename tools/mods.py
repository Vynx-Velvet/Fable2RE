#!/usr/bin/env python3
"""Install / remove mods into the game data and the executable folder the recomp runs from.

A mod is a folder under mods/ (repo root; --mods <dir> uses another folder):
  mods/<Mod>/<bank>/<path inside the bank>   replaces / adds a file inside data/<bank>.bnk
        Only banks the game mounts take effect. Game scripts go under gamescripts_r/:
        data/startup.vfsconfig mounts gamescripts_r.bnk and never gamescripts.bnk (that bank holds
        the same scripts with debug information - extract it only to read them with real names).
        e.g. mods/MyQuest/gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua
             mods/MyMenus/guiscripts/scripts/gameface/menu/menulib.lua
  mods/<Mod>/data/<path>                      replaces / adds a loose file under data/
        e.g. mods/MyDebug/data/scripts/Startup/DebugMenu.txt
  mods/<Mod>/text/<language>.txt              "<id hex8><TAB><text>" lines for
                                              data/language/<language>/text/book.babel: an id the
                                              game has changes that string, a new id adds one
                                              (get ids/text: python tools/babel.py export ...)
  mods/<Mod>/tuning.toml                      [tuning] Name = value overrides of the game's tuning
                                              values (research/catalog/tuning.tsv), installed as
                                              <exe dir>/mods/<Mod>/tuning.toml
  mods/<Mod>/native/*.dll                     native C++ plugin (sdk/include/fable2/mod_api.h),
                                              installed to <exe dir>/mods/<Mod>/native/
  Other files at the top of a mod folder (README, plugin sources) are not installed; folders whose
  names start with . (.git, .vscode) and __pycache__ are skipped. A mod with nothing to install is
  reported (e.g. native/ missing because the plugin DLL was never copied into it).
Fable2.exe reads tuning.toml and native plugins from mods/ beside itself (src/modding/mod_loader.cpp),
not from the game folder, so the two locations are separate options.

Scripts may be Lua source text (the game's Lua loader compiles source as well as bytecode): extract
with `python tools/bnk.py extract <bank> extracted/<bank> --decompile`, copy the *.src.lua you want to
change into the mod as <name>.lua and edit it.

Mods are applied in alphabetical order; folders starting with _ are disabled. When two mods change the
same bank file, data file, string id or tuning value differently, the later mod wins: list, check and
apply print these conflicts as a table (including tuning.toml files already in <exe dir>/mods that
tools/mods.py did not install, such as the F2 menu's LiveTuning), and --strict makes list, check and
apply fail on any conflict.

apply checks every mod against the game first (bank exists, is mounted by a vfsconfig, can be
rewritten; .src.lua names; text languages; exe folder) and changes nothing when a check fails. It then
undoes the previous apply, backs every file it replaces up as <file>.orig, and records each file and
folder it wrote - in the game folder and in the exe folder - in <game>/fable2re_mods_state.json.
restore reads that record from the game folder (give it the --game, or the --exe-dir, that apply was
given), moves every original back byte for byte and removes what apply added. A file changed after
apply is kept as <file>.after-mods before the original returns. When the game folder was moved after
apply, the recorded paths are taken relative to where the record is now (and the exe folder moves with
the game when the game was inside it, as in the default layout).

Usage:
  python tools/mods.py list    [--game DIR] [--exe-dir DIR] [--mods DIR] [--strict]
  python tools/mods.py check   [--game DIR] [--exe-dir DIR] [--mods DIR] [--strict] [--allow-unmounted]
  python tools/mods.py apply   [--game DIR] [--exe-dir DIR] [--mods DIR] [--strict] [--allow-unmounted]
  python tools/mods.py restore [--game DIR] [--exe-dir DIR]
Defaults: --exe-dir Fable2Recomp/out/build/win-amd64-release (the folder of Fable2.exe);
          --game <exe dir>/assets/game (what Fable2.exe uses without --game_directory).
Exit status: 0 done (restore: also when there was nothing to restore), 1 a check failed / conflicts
under --strict / unreadable record / restore incomplete or game folder missing, 2 bad usage.
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import babel  # noqa: E402
import bnk  # noqa: E402

try:
    import tomllib
except ImportError:  # (Python < 3.11: tuning files are installed but not checked)
    tomllib = None

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MODS = os.path.join(ROOT, 'mods')
DEFAULT_EXE = os.path.join(ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release')
TUNING_CATALOG = os.path.join(ROOT, 'research', 'catalog', 'tuning.tsv')
STATE_NAME = 'fable2re_mods_state.json'
SPECIAL = {'data', 'text', 'native'}  # top-level mod folders that are not bank names
SKIPPED = {'__pycache__'}  # top-level mod folders that are never installed (as are names starting with .)
# Bank folders the shipped vfsconfig is known to leave unmounted, for `list` (check reads the vfsconfig).
KNOWN_UNMOUNTED = {'gamescripts': 'gamescripts_r'}

BANK_PATH = re.compile(r'<Bank\b[^>]*?\bPath\s*=\s*"([^"]*)"', re.I)
XML_COMMENT = re.compile(r'<!--.*?-->', re.S)


# ---------------------------------------------------------------------------------------- helpers

def show(path):
    """A path for messages: relative to the repository when inside it."""
    try:
        rel = os.path.relpath(path, ROOT)
    except ValueError:  # (another drive)
        return path
    return path if rel.startswith('..') else rel


def norm(path):
    return os.path.normcase(os.path.abspath(path))


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()


def resolve_ci(base, rel_parts):
    """base joined with rel_parts, using the on-disk spelling of every part that exists (so replacing a
    file never changes the case of its name) and the given spelling for the rest."""
    path = base
    for i, part in enumerate(rel_parts):
        found = None
        try:
            for entry in os.listdir(path):
                if entry.lower() == part.lower():
                    found = entry
                    break
        except OSError:
            return os.path.join(path, *rel_parts[i:])
        if found is None:
            return os.path.join(path, *rel_parts[i:])
        path = os.path.join(path, found)
    return path


class Notes:
    def __init__(self):
        self.errors, self.warnings, self.infos = [], [], []

    def error(self, text):
        self.errors.append(text)

    def warn(self, text):
        self.warnings.append(text)

    def info(self, text):
        self.infos.append(text)

    def print(self):
        for text in self.infos:
            print(f'note: {text}')
        for text in self.warnings:
            print(f'warning: {text}')
        for text in self.errors:
            print(f'error: {text}')


class Item:
    """One change a mod makes. key: what two mods can both change (None: per-mod, cannot collide)."""

    def __init__(self, mod, kind, target, src, key=None, value=None, where=None):
        self.mod, self.kind, self.target, self.src = mod, kind, target, src
        self.key, self.value, self.where = key, value, where or src

    def content(self):
        if self.kind in ('text', 'tuning'):
            return self.value
        return sha256(self.src)

    def describe_key(self):
        kind = self.key[0]
        if kind == 'bank':
            return f'{self.target[0]}.bnk', self.target[1]
        if kind == 'data':
            return 'data', self.target
        if kind == 'text':
            return f'text {self.target[0]}', f'{self.target[1]:08X}'
        return 'tuning', self.target


# ------------------------------------------------------------------------------------ mod folders

def tuning_names():
    if not os.path.isfile(TUNING_CATALOG):
        return None
    with open(TUNING_CATALOG, encoding='utf-8') as f:
        return {line.split('\t', 1)[0] for line in f.read().splitlines()[1:] if line.strip()}


def scan(mods_dir, notes, static_hints=False):
    """(enabled mod names in apply order, [Item]) from a mods folder. static_hints: warn about bank
    folders known to be unmounted (for list, which does not read the game's vfsconfig)."""
    mods, items = [], []
    if not os.path.isdir(mods_dir):
        notes.info(f'{show(mods_dir)} does not exist: no mods')
        return mods, items
    known_tuning = tuning_names()
    disabled = 0
    for mod in sorted(os.listdir(mods_dir)):
        mdir = os.path.join(mods_dir, mod)
        if not os.path.isdir(mdir) or mod.startswith('.'):
            continue
        if mod.startswith('_'):  # (_Name = disabled)
            disabled += 1
            continue
        mods.append(mod)
        first_item, first_error = len(items), len(notes.errors)
        for top in sorted(os.listdir(mdir)):
            tpath = os.path.join(mdir, top)
            low = top.lower()
            if os.path.isfile(tpath):
                if low == 'tuning.toml':
                    items.extend(scan_tuning(mod, tpath, known_tuning, notes))
                continue  # (README, sources: not installed)
            if top.startswith('.') or low in SKIPPED:
                notes.info(f'{mod}/{top}/: skipped (editor, version-control or Python cache folder, not a bank)')
                continue
            if low == 'text':
                items.extend(scan_text(mod, tpath, notes))
            elif low == 'native':
                items.extend(scan_native(mod, tpath, notes))
            elif low == 'data':
                for dp, _, files in os.walk(tpath):
                    for f in sorted(files):
                        src = os.path.join(dp, f)
                        rel = os.path.relpath(src, tpath).replace(os.sep, '/')
                        items.append(Item(mod, 'data', rel, src, key=('data', rel.lower())))
            else:
                if static_hints and low in KNOWN_UNMOUNTED:
                    notes.warn(f'{mod}/{top}/: the game mounts {KNOWN_UNMOUNTED[low]}.bnk (data/startup.vfsconfig), '
                               f'not {low}.bnk - check/apply refuse this folder; move it to {KNOWN_UNMOUNTED[low]}/')
                for dp, _, files in os.walk(tpath):
                    for f in sorted(files):
                        src = os.path.join(dp, f)
                        inner = os.path.relpath(src, tpath).replace(os.sep, '\\')
                        items.append(Item(mod, 'bank', (top, inner), src, key=('bank', low, inner.lower())))
        if len(items) == first_item and len(notes.errors) == first_error:
            notes.warn(f'{mod}: nothing to install - a mod needs a bank folder, data/, text/<language>.txt, '
                       f'tuning.toml or native/*.dll (a plugin\'s DLL must be copied into the mod\'s native/)')
    if disabled:
        notes.info(f'{disabled} disabled mod folder(s) starting with _ skipped')
    return mods, items


def scan_text(mod, tdir, notes):
    items = []
    for f in sorted(os.listdir(tdir)):
        path = os.path.join(tdir, f)
        if os.path.isdir(path) or not f.lower().endswith('.txt'):
            notes.warn(f'{mod}/text/{f}: ignored (text mods are text/<language>.txt files)')
            continue
        lang = f[:-4]
        try:
            rows = babel.read_lines(path)
        except (ValueError, UnicodeDecodeError) as e:
            text = str(e)
            notes.error(text.replace(path, f'{mod}/text/{f}') if path in text else f'{mod}/text/{f}: {text}')
            continue
        seen = {}
        for number, sid, text in rows:
            if sid in seen:
                notes.warn(f'{mod}/text/{f}:{number}: id {sid:08X} also on line {seen[sid]}; the later line wins')
            seen[sid] = number
        last = {sid: (number, text) for number, sid, text in rows}
        for sid, (number, text) in last.items():
            items.append(Item(mod, 'text', (lang, sid), path, key=('text', lang.lower(), sid), value=text,
                              where=f'{path}:{number}'))
        if not rows:
            notes.warn(f'{mod}/text/{f}: no "<id><TAB><text>" lines')
    return items


def scan_tuning(mod, path, known, notes):
    items = [Item(mod, 'tuningfile', mod, path)]
    if tomllib is None:
        notes.warn(f'{mod}/tuning.toml: not checked (Python 3.11+ has tomllib)')
        return items
    try:
        with open(path, 'rb') as f:
            doc = tomllib.load(f)
    except (tomllib.TOMLDecodeError, UnicodeDecodeError) as e:
        notes.error(f'{mod}/tuning.toml: {e} (the game would skip the whole file)')
        return items
    table = doc.get('tuning')
    if not isinstance(table, dict):
        notes.warn(f'{mod}/tuning.toml: no [tuning] table - the game reads only [tuning] and ignores this file')
        return items
    for name, value in table.items():
        if isinstance(value, bool) or isinstance(value, (int, float)):
            if known is not None and name not in known:
                notes.warn(f'{mod}/tuning.toml: {name} is not a tuning value (research/catalog/tuning.tsv); '
                           f'the game ignores it')
            items.append(Item(mod, 'tuning', name, path, key=('tuning', name), value=float(value),
                              where=str(value).lower()))
        else:
            notes.warn(f'{mod}/tuning.toml: {name} = {value!r} is not a number or true/false; the game ignores it')
    return items


def scan_native(mod, ndir, notes):
    items, refused = [], False
    for f in sorted(os.listdir(ndir)):
        path = os.path.join(ndir, f)
        if os.path.isdir(path):
            notes.warn(f'{mod}/native/{f}/: not installed (the loader reads only native/*.dll)')
            continue
        if f.lower().endswith('.dll') and not f.endswith('.dll'):
            notes.error(f'{mod}/native/{f}: the loader only loads names ending in lowercase ".dll"; rename it')
            refused = True
            continue
        items.append(Item(mod, 'native', f, path))
    if not refused and not any(i.target.endswith('.dll') for i in items):
        notes.warn(f'{mod}/native/: no .dll - nothing for the loader to load')
    return items


# --------------------------------------------------------------------------------------- conflicts

def resolve(items, external=()):
    """(winning item per key, conflicts [(key, [items in order])], identical duplicates count).

    Order is the apply order (sorted mod names), which is also the order Fable2.exe applies
    mods/*/tuning.toml in; external items are tuning files already in <exe dir>/mods."""
    groups = {}
    for it in list(items) + list(external):
        if it.key is not None:
            groups.setdefault(it.key, []).append(it)
    winners, conflicts, duplicates = {}, [], 0
    for key, its in groups.items():
        its.sort(key=lambda it: it.mod)
        winners[key] = its[-1]
        if len({it.mod for it in its}) < 2:
            continue
        if len({it.content() for it in its}) == 1:
            duplicates += 1
            continue
        conflicts.append((key, its))
    conflicts.sort(key=lambda c: c[0])
    return winners, conflicts, duplicates


def print_conflicts(conflicts, duplicates, strict):
    if duplicates:
        print(f'note: {duplicates} target(s) are set identically by several mods (not conflicts)')
    if not conflicts:
        print('conflicts: none')
        return
    rule = 'refused (--strict)' if strict else 'the last mod listed wins; --strict refuses'
    print(f'conflicts: {len(conflicts)} target(s) changed differently by several mods ({rule}):')
    rows = [('what', 'target', 'mods in apply order', 'wins')]
    for key, its in conflicts:
        what, target = its[0].describe_key()
        names = []
        for it in its:
            if it.mod not in names:
                names.append(it.mod)
        rows.append((what, target, ', '.join(names), its[-1].mod))
    widths = [max(len(r[i]) for r in rows) for i in range(3)]
    for r in rows:
        print('  ' + '  '.join(r[i].ljust(widths[i]) for i in range(3)) + '  ' + r[3])


# ------------------------------------------------------------------------------------------- state

class StateError(Exception):
    """The state file exists but cannot be used."""


def under(path, base):
    """path relative to base ('.' for base itself), or None when path is not inside base."""
    try:
        rel = os.path.relpath(path, base)
    except ValueError:  # (another drive)
        return None
    return None if rel == os.pardir or rel.startswith(os.pardir + os.sep) else rel


def backups_near(game, exe_dir):
    """*.orig files in <game>/data and <exe dir>/mods (what an unreadable state file leaves to go by)."""
    found = []
    for base in (os.path.join(game, 'data'), os.path.join(exe_dir, 'mods') if exe_dir else None):
        if base and os.path.isdir(base):
            for dp, _, files in os.walk(base):
                found += [os.path.join(dp, f) for f in files if f.endswith('.orig')]
    return sorted(found)


def load_state(state_path, exe_dir=None):
    """(record, [(old folder, new folder)]) from a state file, its paths moved to where the folders are
    now: the game folder is the one holding the record; the exe folder moves with the game when the
    game was inside it (default layout), else it stays as recorded unless it is gone and exe_dir (an
    explicit --exe-dir) is given. Raises StateError when the file cannot be read."""
    try:
        with open(state_path, encoding='utf-8') as f:
            st = json.load(f)
        if not isinstance(st, dict) or not isinstance(st.get('files'), list):
            raise ValueError('no "files" list')
        st.setdefault('dirs', [])
        if not isinstance(st['dirs'], list) or not all(isinstance(d, str) for d in st['dirs']):
            raise ValueError('"dirs" is not a list of folders')
        for e in st['files']:
            if not (isinstance(e, dict) and isinstance(e.get('path'), str)
                    and isinstance(e.get('backup'), (str, type(None)))):
                raise ValueError('a file entry has no "path" / "backup"')
    except (OSError, UnicodeDecodeError, ValueError) as e:
        game = os.path.dirname(os.path.abspath(state_path))
        orig = backups_near(game, exe_dir or DEFAULT_EXE)
        shown = ''.join(f'\n  {show(p)}' for p in orig[:20]) + ('\n  ...' if len(orig) > 20 else '')
        raise StateError(
            f'{show(state_path)} is unreadable ({e}). It is the only record of what the last apply changed: '
            f'move each <file>.orig backup back over <file> (game data/ and <exe dir>/mods), delete the files and '
            f'<exe dir>/mods folders that apply added, then delete {STATE_NAME}. '
            + (f'{len(orig)} *.orig file(s) found:{shown}' if orig else 'No *.orig files were found.')) from None
    game = os.path.dirname(os.path.abspath(state_path))
    old_game = st.get('game') if isinstance(st.get('game'), str) else game
    old_exe = st.get('exe_dir') if isinstance(st.get('exe_dir'), str) else None
    moves, new_exe = [], None
    if norm(old_game) != norm(game):
        moves.append((old_game, game))  # (first: the game folder can lie inside the exe folder)
        rel = under(old_game, old_exe) if old_exe else None
        if rel and rel != os.curdir:
            candidate = game
            for _ in rel.split(os.sep):
                candidate = os.path.dirname(candidate)
            if norm(os.path.join(candidate, rel)) == norm(game):
                new_exe = candidate
    if old_exe and new_exe is None and exe_dir and not os.path.isdir(old_exe):
        new_exe = os.path.abspath(exe_dir)
    if old_exe and new_exe and norm(new_exe) != norm(old_exe):
        moves.append((old_exe, new_exe))

    def move(p):
        for old, new in moves:
            rel = under(p, old) if p else None
            if rel is not None:
                return os.path.normpath(os.path.join(new, rel))
        return p
    if moves:
        for e in st['files']:
            e['path'], e['backup'] = move(e['path']), move(e['backup'])
        st['dirs'] = [move(d) for d in st['dirs']]
        st['game'], st['exe_dir'] = game, new_exe or old_exe
    return st, moves


def moved_note(state_path, moves):
    return (f'{show(state_path)} was written for ' + ' and '.join(show(old) for old, _ in moves)
            + '; its paths are taken relative to ' + ' and '.join(show(new) for _, new in moves))


class State:
    """<game>/fable2re_mods_state.json: what the last apply wrote, for restore. Without one, backups and
    markers an older tools/mods.py left (legacy) stand in for it."""

    def __init__(self, game, exe_dir, exe_hint=None):
        self.path = os.path.join(game, STATE_NAME)
        self.data, self.legacy, self.files, self.moves = None, [], [], []
        if os.path.isfile(self.path):
            self.data, self.moves = load_state(self.path, exe_hint)
            self.files = self.data['files']
        else:
            self.legacy = legacy_artifacts(game, exe_dir)
            for p in self.legacy:
                if p.endswith('.orig') and os.path.isfile(p):
                    self.files.append({'path': p[:-5], 'backup': p})
                elif p.endswith('.modadded'):
                    self.files.append({'path': p[:-9], 'backup': None})

    def exists(self):
        return self.data is not None

    def entry(self, path):
        key = norm(path)
        for f in self.files:
            if norm(f['path']) == key:
                return f
        return None

    def original(self, path):
        """Where the game's own version of path is now: its backup while a mod replaces it, None when
        a mod added it or it does not exist."""
        e = self.entry(path)
        if e is not None:
            return e['backup']
        return path if os.path.exists(path) else None

    def is_backup(self, path):
        key = norm(path)
        return any(f['backup'] and norm(f['backup']) == key for f in self.files)


class Recorder:
    """Writes files for apply, recording each one in the state file before it is touched."""

    def __init__(self, game, exe_dir, mods):
        self.path = os.path.join(game, STATE_NAME)
        self.data = {'tool': 'tools/mods.py', 'version': 2, 'game': os.path.abspath(game),
                     'exe_dir': os.path.abspath(exe_dir), 'mods': mods,
                     'applied': time.strftime('%Y-%m-%d %H:%M:%S'), 'files': [], 'dirs': []}

    def save(self):
        tmp = self.path + '.tmp'
        with open(tmp, 'w', encoding='utf-8', newline='\n') as f:
            json.dump(self.data, f, indent=1)
        os.replace(tmp, self.path)

    def ensure_dir(self, d):
        missing = []
        while not os.path.isdir(d):
            missing.append(d)
            d = os.path.dirname(d)
        for m in reversed(missing):
            self.data['dirs'].append(os.path.abspath(m))
            self.save()
            os.mkdir(m)

    def write(self, path, produce):
        """produce(tmp path, original path or None) writes the new content; the original (if any) is
        kept as <path>.orig."""
        if any(norm(f['path']) == norm(path) for f in self.data['files']):  # (check_game refuses this)
            raise RuntimeError(f'{path} would be written twice; its backup would be lost')
        self.ensure_dir(os.path.dirname(path))
        backup = path + '.orig' if os.path.exists(path) else None
        entry = {'path': os.path.abspath(path), 'backup': os.path.abspath(backup) if backup else None, 'sha256': None}
        self.data['files'].append(entry)
        self.save()
        if backup:  # (a complete backup or none: restore trusts any <path>.orig it finds)
            shutil.copy2(path, backup + '.mods-tmp')
            os.replace(backup + '.mods-tmp', backup)
        tmp = path + '.mods-tmp'
        produce(tmp, backup)
        os.replace(tmp, path)
        entry['sha256'] = sha256(path)
        self.save()


def restore_state(state_path, exe_hint=None):
    """Undo the apply recorded in state_path. True when everything was restored. Raises StateError when
    the record cannot be read (nothing is changed then)."""
    st, moves = load_state(state_path, exe_hint)
    if moves:
        print(f'note: {moved_note(state_path, moves)}')
    restored, remaining = 0, []
    for e in reversed(st['files']):
        path, backup, digest = e['path'], e['backup'], e.get('sha256')
        if os.path.exists(path) and digest and sha256(path) != digest:
            keep = path + '.after-mods'
            shutil.copy2(path, keep)
            print(f'warning: {show(path)} changed after apply; that version is kept as {show(keep)}')
        for tmp in (path + '.mods-tmp', (backup or path) + '.mods-tmp'):
            if os.path.exists(tmp):  # (an apply interrupted while writing)
                os.remove(tmp)
        if backup:
            if os.path.exists(backup):
                os.replace(backup, path)
            elif digest is not None:
                print(f'error: backup {show(backup)} is missing; {show(path)} cannot be restored')
                remaining.append(e)
                continue
            # (else apply stopped before the backup existed, so the file was never replaced)
        elif os.path.exists(path):
            os.remove(path)
        restored += 1
    kept_dirs = []
    for d in reversed(st['dirs']):
        if not os.path.isdir(d):
            continue
        try:
            os.rmdir(d)
        except OSError:
            kept_dirs.append(d)
    print(f'restored {restored} file(s) from {show(state_path)}'
          + (f'; kept {len(kept_dirs)} folder(s) that hold other files' if kept_dirs else ''))
    if remaining:
        st['files'] = list(reversed(remaining))
        st['dirs'] = [d for d in st['dirs'] if d in kept_dirs]
        with open(state_path, 'w', encoding='utf-8', newline='\n') as f:
            json.dump(st, f, indent=1)
        return False
    os.remove(state_path)
    return True


def legacy_artifacts(game, exe_dir):
    """Backups and markers an older tools/mods.py (no state file) left behind."""
    found = []
    data = os.path.join(game, 'data')
    for dp, _, files in os.walk(data):
        for f in files:
            if f.endswith('.orig') or f.endswith('.modadded'):
                found.append(os.path.join(dp, f))
    for base in {norm(exe_dir), norm(os.path.dirname(os.path.dirname(os.path.abspath(game))))}:
        mods = os.path.join(base, 'mods')
        if os.path.isdir(mods):
            for mod in os.listdir(mods):
                if os.path.exists(os.path.join(mods, mod, '.installed_by_mods_py')):
                    found.append(os.path.join(mods, mod))
    return found


def legacy_restore(found):
    for p in found:
        if os.path.isdir(p):
            shutil.rmtree(p, ignore_errors=True)
        elif p.endswith('.orig'):
            shutil.copy2(p, p[:-5])
            os.remove(p)
        else:
            target = p[:-9]
            if os.path.exists(target):
                os.remove(target)
            os.remove(p)
    print(f'restored {len(found)} item(s) left by an older tools/mods.py (*.orig / *.modadded / '
          f'.installed_by_mods_py)')


# ---------------------------------------------------------------------------------- game checks

def mounted_banks(data, state, data_items):
    """(bank paths relative to data/ in lower case with '/', config files read), or (None, []) when the
    game has no startup.vfsconfig. A vfsconfig supplied by a data mod is read instead of the game's."""
    from_mods = {it.target.lower(): it.src for it in data_items}
    configs = []
    startup = from_mods.get('startup.vfsconfig') or state.original(resolve_ci(data, ['startup.vfsconfig']))
    if not startup:
        return None, []
    configs.append(startup)
    worlds = resolve_ci(data, ['worlds'])
    for dp, _, files in os.walk(worlds):
        for f in files:
            if f.lower() == 'level.vfsconfig':
                p = os.path.join(dp, f)
                rel = os.path.relpath(p, data).replace(os.sep, '/').lower()
                src = from_mods.get(rel) or state.original(p)
                if src:
                    configs.append(src)
    configs += [src for rel, src in from_mods.items() if rel.endswith('.vfsconfig') and src not in configs]
    banks = set()
    for c in configs:
        with open(c, encoding='utf-8', errors='replace') as f:
            text = XML_COMMENT.sub('', f.read())
        banks |= {p.replace('\\', '/').lstrip('/').lower() for p in BANK_PATH.findall(text)}
    return banks, configs


def bank_names(path):
    try:
        return {n.lower() for n in bnk.read_directory(path)}
    except (bnk.UnsupportedBank, OSError):
        return None


def target_path(it, data, exe_dir):
    """The file an item writes (several bank or text items share their bank / book)."""
    if it.kind == 'bank':
        return resolve_ci(data, [it.target[0] + '.bnk'])
    if it.kind == 'data':
        return resolve_ci(data, it.target.split('/'))
    if it.kind == 'text':
        return resolve_ci(data, ['language', it.target[0], 'text', 'book.babel'])
    if it.kind == 'tuningfile':
        return resolve_ci(exe_dir, ['mods', it.mod, 'tuning.toml'])
    if it.kind == 'native':
        return resolve_ci(exe_dir, ['mods', it.mod, 'native', it.target])
    return None


def writer(it):
    """Items with the same writer build one file together (a bank, a book); different writers of the
    same file would overwrite each other. Folder and language names are case-insensitive, as on disk."""
    if it.kind == 'bank':
        return f'bank folder {it.target[0].lower()}/'
    if it.kind == 'text':
        return f'text/{it.target[0].lower()}.txt'
    return f'{it.mod}: {it.kind} {it.target if isinstance(it.target, str) else it.target[-1]}'


def check_game(game, exe_dir, items, winners, state, notes, allow_unmounted):
    """Checks the planned changes against the game folder; problems go to notes."""
    data = os.path.join(game, 'data')
    if not os.path.isdir(data):
        notes.error(f'{show(data)} does not exist - pass --game <folder that contains data/> '
                    f'(default: <exe dir>/assets/game)')
        return
    win = [it for it in items if it.key is None or winners.get(it.key) is it]
    data_items = [it for it in win if it.kind == 'data']
    mounted, configs = mounted_banks(data, state, data_items)
    if mounted is None:
        notes.warn(f'{show(data)}/startup.vfsconfig not found: cannot tell which banks the game mounts')
    else:
        notes.info(f'mounted banks read from {len(configs)} vfsconfig file(s): '
                   + ', '.join(sorted(b for b in mounted if '/' not in b)) + ' (top level)')

    # Bank files.
    banks = {}
    for it in win:
        if it.kind == 'bank':
            banks.setdefault(it.target[0].lower(), []).append(it)
    for low, its in sorted(banks.items()):
        folder = its[0].target[0]
        users = ', '.join(sorted({it.mod for it in items if it.kind == 'bank' and it.target[0].lower() == low}))
        path = resolve_ci(data, [folder + '.bnk'])
        orig = state.original(path)
        if orig is None:
            alt = f' (data/{low}_r.bnk exists: did you mean {low}_r/?)' if os.path.exists(
                resolve_ci(data, [low + '_r.bnk'])) else ''
            notes.error(f'{users}: {folder}/ - data/{folder}.bnk does not exist{alt}. A folder at the top of a '
                        f'mod names a bank in data/; loose files go under data/, text under text/, plugins under native/')
            continue
        if mounted is not None and low + '.bnk' not in mounted:
            if low + '_r.bnk' in mounted:
                notes.error(f'{users}: {folder}/ targets {low}.bnk, which the game never mounts - '
                            f'data/startup.vfsconfig mounts {low}_r.bnk instead (same scripts without debug '
                            f'information). Move the folder to {low}_r/')
                continue
            text = (f'{users}: {folder}/ targets {low}.bnk, which no vfsconfig mounts; the game may still open it '
                    f'by other means (levels.bnk and streaming.bnk are read without being listed), but nothing '
                    f'shows that a changed file there is used')
            if not allow_unmounted:
                notes.error(text + ' - pass --allow-unmounted to apply it anyway')
                continue
            notes.warn(text)
        try:
            names = {n.lower() for n in bnk.read_directory(orig)}
        except bnk.UnsupportedBank as e:
            notes.error(f'{users}: {folder}/: {e}')
            continue
        added = []
        for it in its:
            inner = it.target[1]
            if inner.lower() in names:
                continue
            if inner.lower().endswith('.src.lua') and inner.lower()[:-8] + '.lua' in names:
                notes.error(f'{it.mod}: {folder}/{inner} is a decompiler output name - the game loads '
                            f'{inner[:-8]}.lua; rename the file (drop ".src")')
            else:
                added.append(f'{it.mod}: {inner}')
        if added:
            notes.warn(f'{folder}.bnk has no file at these paths, so they are added as new files; the game reads '
                       f'them only if something asks for that exact path (check spelling and folders): '
                       + '; '.join(added))

    # Loose data files that shadow a file inside a mounted bank.
    if mounted is not None and data_items:
        inside = {}
        for b in sorted(mounted):
            orig = state.original(resolve_ci(data, b.split('/')))
            names = bank_names(orig) if orig else None
            if names:
                inside[b] = names
        for it in data_items:
            inner = it.target.replace('/', '\\').lower()
            hits = [b for b, names in inside.items() if inner in names]
            if hits:
                notes.warn(f'{it.mod}: data/{it.target} is also inside {", ".join(hits)}; which copy the game reads is '
                           f'not established - put the change under {hits[0][:-4]}/ in the mod instead')

    # Text.
    langs = {}
    for it in win:
        if it.kind == 'text':
            langs.setdefault(it.target[0].lower(), []).append(it)
    for _, its in sorted(langs.items()):
        lang = its[0].target[0]
        book = resolve_ci(data, ['language', lang, 'text', 'book.babel'])
        orig = state.original(book)
        if orig is None:
            have = sorted(d for d in os.listdir(os.path.join(data, 'language'))
                          if os.path.isdir(os.path.join(data, 'language', d))) if os.path.isdir(
                os.path.join(data, 'language')) else []
            notes.error(f'{", ".join(sorted({it.mod for it in its}))}: text/{lang}.txt - no data/language/{lang}/'
                        f'text/book.babel (languages: {", ".join(have) or "none"})')
            continue
        ids = {sid for sid, _, _ in babel.Babel(orig).entries}
        new = sorted(it.target[1] for it in its if it.target[1] not in ids)
        if new:
            shown = ', '.join(f'{sid:08X}' for sid in new[:8]) + (' ...' if len(new) > 8 else '')
            notes.warn(f'text/{lang}: {len(new)} id(s) are not in the game\'s text and are added as new strings '
                       f'(a mistyped id ends up here): {shown}')

    # Every file apply writes: one writer per file, and no foreign <file>.orig in the way of the backup.
    writers = {}
    for it in win:
        t = target_path(it, data, exe_dir)
        if t is not None:  # (tuning values travel inside their mod's tuning.toml)
            writers.setdefault(norm(t), (t, set()))[1].add(writer(it))
    for t, ws in writers.values():
        if len(ws) > 1:
            notes.error(f'{show(t)} would be written by {" and by ".join(sorted(ws))}; keep one of them')
        if os.path.exists(t + '.orig') and not state.is_backup(t + '.orig'):
            notes.error(f'{show(t)}.orig exists and is not a backup recorded in {STATE_NAME}; move it away '
                        f'(apply would overwrite it with its own backup)')

    # Executable folder.
    exe_items = [it for it in win if it.kind in ('native', 'tuningfile')]
    if exe_items:
        if not os.path.isdir(exe_dir):
            notes.error(f'{show(exe_dir)} does not exist - pass --exe-dir <folder of Fable2.exe> '
                        f'(native plugins and tuning.toml are read from <exe dir>/mods)')
        elif not os.path.exists(os.path.join(exe_dir, 'Fable2.exe')):
            notes.warn(f'{show(exe_dir)} has no Fable2.exe; native plugins and tuning.toml go to {show(exe_dir)}/mods')


def external_tuning(exe_dir, mod_items, state):
    """Tuning values in <exe dir>/mods/*/tuning.toml that tools/mods.py did not install (read only).
    state may be None (no usable record: every file found counts)."""
    items = []
    root = os.path.join(exe_dir, 'mods')
    if tomllib is None or not os.path.isdir(root):
        return items
    # Only a mod with its own tuning.toml replaces the file in its exe folder; a mod with, say, only
    # native/ leaves an existing tuning.toml there in effect.
    ours = {it.mod.lower() for it in mod_items if it.kind == 'tuningfile'}
    for d in sorted(os.listdir(root)):
        path = os.path.join(root, d, 'tuning.toml')
        if d.startswith('_') or not os.path.isfile(path):
            continue
        if d.lower() in ours:
            continue  # (apply replaces it; restore brings it back)
        e = state.entry(path) if state else None
        if e is not None:  # (installed by the last apply: what was there before, if anything)
            if not e['backup'] or not os.path.isfile(e['backup']):
                continue
            path = e['backup']
        try:
            with open(path, 'rb') as f:
                table = tomllib.load(f).get('tuning', {})
        except (tomllib.TOMLDecodeError, UnicodeDecodeError, OSError):
            continue
        label = f'{d} (exe mods/, not from tools/mods.py)'
        for name, value in table.items() if isinstance(table, dict) else []:
            if isinstance(value, (bool, int, float)):
                items.append(Item(label, 'tuning', name, path, key=('tuning', name), value=float(value)))
    return items


# ------------------------------------------------------------------------------------------ install

def install(game, exe_dir, mods, items, winners):
    data = os.path.join(game, 'data')
    rec = Recorder(game, exe_dir, mods)
    rec.save()
    win = [it for it in items if it.key is None or winners.get(it.key) is it]

    def copy_from(src):
        return lambda tmp, orig: shutil.copyfile(src, tmp)

    banks, langs = {}, {}
    for it in win:
        if it.kind == 'bank':
            banks.setdefault(it.target[0].lower(), []).append(it)
        elif it.kind == 'text':
            langs.setdefault(it.target[0].lower(), []).append(it)
    for low, its in sorted(banks.items()):
        path = resolve_ci(data, [its[0].target[0] + '.bnk'])
        overrides = {it.target[1].lower(): it for it in its}

        def build(tmp, orig, overrides=overrides):
            bank = bnk.Bank(orig)
            todo = dict(overrides)
            contents = []
            for e in bank.files:
                it = todo.pop(e[0].lower(), None)
                contents.append((e[0], open(it.src, 'rb').read() if it else bank.read(e)))
            for key in sorted(todo):  # (new files)
                contents.append((todo[key].target[1], open(todo[key].src, 'rb').read()))
            bnk.write_bank(tmp, bank, contents)
        rec.write(path, build)
        print(f'{os.path.basename(path)}: {len(its)} file(s) replaced/added')
    data_items = [it for it in win if it.kind == 'data']
    for it in data_items:
        rec.write(resolve_ci(data, it.target.split('/')), copy_from(it.src))
    if data_items:
        print(f'data: {len(data_items)} loose file(s)')
    for _, its in sorted(langs.items()):
        lang = its[0].target[0]
        path = resolve_ci(data, ['language', lang, 'text', 'book.babel'])
        overrides = {it.target[1]: it.value for it in its}
        result = {}

        def build_text(tmp, orig, overrides=overrides, result=result):
            result['r'] = babel.rebuild(orig, overrides, tmp)
        rec.write(path, build_text)
        changed, added, _, _ = result['r']
        print(f'text/{lang}: {len(changed)} string(s) changed, {len(added)} new id(s) added')
    exe_mods = os.path.join(exe_dir, 'mods')
    for it in win:
        if it.kind == 'tuningfile':
            rec.write(resolve_ci(exe_dir, ['mods', it.mod, 'tuning.toml']), copy_from(it.src))
            print(f'{it.mod}: tuning.toml -> {show(os.path.join(exe_mods, it.mod))}')
        elif it.kind == 'native':
            rec.write(resolve_ci(exe_dir, ['mods', it.mod, 'native', it.target]), copy_from(it.src))
            print(f'{it.mod}: native/{it.target} -> {show(os.path.join(exe_mods, it.mod, "native"))}')
    print(f'applied {len(mods)} mod(s); {len(rec.data["files"])} file(s) recorded in {show(rec.path)}')


# --------------------------------------------------------------------------------------------- main

def print_list(mods_dir, mods, items):
    print(f'{len(mods)} enabled mod(s) in {show(mods_dir)}, in apply order:')
    for mod in mods:
        print(mod)
        texts = {}
        for it in items:
            if it.mod != mod:
                continue
            if it.kind == 'bank':
                print(f'   {it.target[0]}.bnk  {it.target[1]}  <- {show(it.src)}')
            elif it.kind == 'data':
                print(f'   data  {it.target}  <- {show(it.src)}')
            elif it.kind == 'text':
                texts.setdefault(it.target[0], [0, it.src])[0] += 1
            elif it.kind == 'tuning':
                print(f'   tuning  {it.target} = {it.where}')
            elif it.kind == 'tuningfile':
                print(f'   tuning.toml -> <exe dir>/mods/{mod}/  <- {show(it.src)}')
            elif it.kind == 'native':
                print(f'   native  {it.target} -> <exe dir>/mods/{mod}/native/  <- {show(it.src)}')
        for lang, (n, src) in sorted(texts.items()):
            print(f'   text {lang}  {n} string(s)  <- {show(src)}')


def main(argv):
    parser = argparse.ArgumentParser(prog='tools/mods.py', description=__doc__.split('\n', 1)[0],
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('command', nargs='?', default='list', choices=['list', 'check', 'apply', 'restore'])
    parser.add_argument('--game', help='game folder that contains data/ (default: <exe dir>/assets/game)')
    parser.add_argument('--exe-dir', help='folder of Fable2.exe; mods/ beside it gets tuning.toml and native '
                                          'plugins (default: Fable2Recomp/out/build/win-amd64-release)')
    parser.add_argument('--mods', default=MODS, help='folder of mods (default: mods/ in the repository)')
    parser.add_argument('--strict', action='store_true', help='fail when two mods change the same thing')
    parser.add_argument('--allow-unmounted', action='store_true',
                        help='apply bank changes even to a bank no vfsconfig mounts (not for gamescripts)')
    try:
        args = parser.parse_args(argv)
    except SystemExit as e:
        return 2 if e.code else 0
    exe_dir = os.path.abspath(args.exe_dir or DEFAULT_EXE)
    game = os.path.abspath(args.game or os.path.join(exe_dir, 'assets', 'game'))
    exe_hint = os.path.abspath(args.exe_dir) if args.exe_dir else None  # (explicit only)

    if args.command == 'restore':
        state_path = os.path.join(game, STATE_NAME)
        if os.path.isfile(state_path):
            try:
                return 0 if restore_state(state_path, exe_hint) else 1
            except StateError as e:
                print(f'error: {e}')
                print('restore: nothing was changed')
                return 1
        if not os.path.isdir(game):
            print(f'error: {show(game)} does not exist - pass the --game (or the --exe-dir) that apply was given')
            return 1
        found = legacy_artifacts(game, exe_dir)
        if found:
            legacy_restore(found)
            return 0
        given = ('--game' if args.game else '--exe-dir' if args.exe_dir else None)
        print(f'nothing to restore: no {STATE_NAME} in {show(game)}'
              + (f' (the game folder from {given})' if given else
                 ' (the default game folder, <exe dir>/assets/game)')
              + '. apply writes its record into the game folder it used: if mods are still applied, pass '
                'the same --game, or the same --exe-dir when apply was given only --exe-dir.')
        return 0

    notes = Notes()
    mods, items = scan(args.mods, notes, static_hints=args.command == 'list')
    try:
        state = State(game, exe_dir, exe_hint)
    except StateError as e:
        if args.command != 'list':
            notes.print()
            print(f'error: {e}')
            print(f'{args.command}: nothing was changed')
            return 1
        notes.warn(str(e))
        state = None
    if state and state.legacy:
        notes.info(f'an older tools/mods.py left {len(state.legacy)} backup(s)/marker(s); they count as the '
                   f'originals here and apply restores them first')
    if state and state.moves:
        notes.info(moved_note(state.path, state.moves))
    external = external_tuning(exe_dir, items, state)
    winners, conflicts, duplicates = resolve(items, external)
    if args.command == 'list':
        print_list(args.mods, mods, items)
        notes.print()
        print_conflicts(conflicts, duplicates, args.strict)
        print('(run `python tools/mods.py check` to validate the mods against the game folder)')
        return 1 if notes.errors or (args.strict and conflicts) else 0

    check_game(game, exe_dir, items, winners, state, notes, args.allow_unmounted)
    notes.print()
    print_conflicts(conflicts, duplicates, args.strict)
    if notes.errors or (args.strict and conflicts):
        why = f'{len(notes.errors)} error(s)' if notes.errors else f'{len(conflicts)} conflict(s) under --strict'
        print(f'{args.command}: {why}; nothing was changed')
        return 1
    if args.command == 'check':
        print(f'check: ok ({len(mods)} mod(s), {len(items)} change(s))')
        return 0

    if state.exists():
        if not restore_state(state.path, exe_hint):
            print('apply: the previous apply could not be fully undone; fix the errors above first')
            return 1
    elif state.legacy:
        legacy_restore(state.legacy)
    if not mods:
        print('no enabled mods: the game is unmodified')
        return 0
    install(game, exe_dir, mods, items, winners)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
