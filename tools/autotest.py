"""Unattended test run of the release build (src/autotest.cpp): scripted controller input inside the game,
snapshots, clean exit. No desktop keys/mouse are sent; the window stays behind the others; audio is muted.

    python tools/autotest.py --scenario menu|load|play|boot      built-in scripts, see SCENARIOS
    python tools/autotest.py --suite [menu,load,play]            in sequence, stops at the first failure
    python tools/autotest.py --script "at 40; shot; exit" [--cvars "lifted_disable_ranges=..."] [--tag name]
    python tools/autotest.py --make-golden [--force]             golden save from the current save slot

Every run starts from the golden save (out/build/<preset>/runs/save_golden/Hero000) once it exists. `load` and
`play` (and any --require-golden run) refuse to start without it (SETUP_ERROR). Create it with --make-golden
after the game has saved and was closed normally. The golden save is the user's own save: it stays under
out/build (not tracked by git) and is never published.

The save slot is the one you play in (out/build/<preset>/assets/game/.../00000001). For a run, your slot is moved
to out/build/<preset>/runs/save_before_autotest and the golden save is copied into the slot. After the run,
whatever the game saved during the test is discarded and your slot is moved back. That also happens on an error
or Ctrl+C. If the process is killed before it can move the slot back, the next run (or --make-golden) does it
first. The slot it finds then is not deleted: it is kept as runs/save_slot_found_<time>. Without a golden save,
the slot is not touched. The summary and the ledger say where the slot was kept and whether it was moved back.

Results go to build/autotest/<tag>/: the snapshots (shot_<n>_f<frame>.png) and summary.txt. Every run, also a
failed or refused one, appends one JSON line to build/validation/ledger.jsonl: time, scenario, result, exe path
+ sha256, sha256 of the Fable2.toml next to the exe, git revision + dirty flag (tracked files changed; untracked
files do not count) of the umbrella, Fable2Recomp and rexglue-sdk checkouts, golden save digest, shot counts.
(The file hashes are remembered by path + size + modification time in build/validation/sha256_cache.json.)

A run passes only on evidence written by this launch:
  - the log is read from where it stood before the launch: fable2.log's size, file identity and last bytes
    are recorded first, and if the file was rotated (spdlog: fable2.log -> fable2.1.log -> ...) or shrank,
    the run's lines are followed into the rotated segments. That text must contain "Fable2 starting".
  - the script reached its 'exit' step (or "script finished" for scripts without one). The echo of the script
    text ("autotest: script '...; exit'") does not count. No [critical]/FATAL line, no unknown script command,
    and the game's audio mix not silent all through (when audio_level_log is on).
  - every 'shot' step has its own snapshot from this run (matched through the log's "native renderer:
    snapshot" lines; a file left from an earlier run does not count unless this run rewrote it), and that
    snapshot is not black (mean luminance < --min-luma), not flat (luminance standard deviation < --min-std)
    and not scrambled (noise, the mean difference between neighbouring pixels, > SCRAMBLED). The extra frames
    the game saves after each requested one (frame trace) are reported but not judged.
    Calibration (2026-10-10, 187 of the 788 snapshots under build/autotest): real frames had mean luminance
    >= 24.1, standard deviation >= 21.8 and noise <= 9.4 (0..255 scale); a black or single-colour frame has
    standard deviation 0. The floors (8 and 6) leave a wide margin for dark scenes.

Result classes and exit codes:
  OK             0  all of the above, and the game closed cleanly after its exit step
  OK_EXIT_CRASH  0  all of the above, but the process crashed (e.g. 0xC0000005) or hung while closing after the
                    exit step. A teardown fault: reported and counted separately (summary, ledger, suite line).
                    With --strict-exit the exit code is 3 instead.
  PROBLEM        1  the game ran and a check failed
  NOT_STARTED    1  this launch left no "Fable2 starting" in the log (launcher failed, exe died at once, ...)
  SETUP_ERROR    2  nothing was run: Fable2.exe missing, golden save missing for load/play, bad arguments
  --suite exits with the code of its first run that does not exit 0 (and stops there), else 0.
  --make-golden exits 0 when the golden save was written, 2 when it refused.
"""
import argparse
import datetime
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time
import zlib

TOOLS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(TOOLS, '..'))
PRESET = 'win-amd64-release'
SAVE_SLOT = ('assets', 'game', 'B13EBABEBABEBABE', '4D5307F1', '00000001')

SCRAMBLED = 12.0  # noise score above which a frame counts as scrambled
MIN_LUMA = 8.0    # mean luminance (0..255) below which a frame counts as black
MIN_STD = 6.0     # luminance standard deviation below which a frame counts as flat (one colour)

SCENARIOS = {
    # (script, time limit in seconds) - timings measured on this machine
    'boot': ('at 20; shot; at 40; shot; at 60; shot; at 80; shot; exit', 120),
    'menu': ('at 40; shot; exit', 80),  # the main menu is up about 30 s after start
    # Press A to start -> Continue -> confirm -> the save loads (about 25 s) -> two snapshots in the game
    # load, then about two minutes of walking, turning the camera, attacks and the menu
    'play': ('at 38; press A; wait 6; press DOWN; wait 1.5; press A; wait 7; press A; wait 32; shot; '
             'stick 0 1; wait 8; shot; rstick 0.6 0; wait 4; rstick 0 0; press X; wait 1; press X; wait 1; press X; '
             'wait 3; shot; stick 1 0; wait 6; press B; wait 2; press Y; wait 3; shot; stick 0 -1; wait 8; shot; '
             'stick -1 0.5; rstick -0.5 0; wait 8; rstick 0 0; shot; stick 0 1; wait 15; shot; press START; wait 4; '
             'shot; press START; wait 4; stick 0 0; press A; wait 5; shot; stick 0 1; wait 20; shot; stick 0 0; exit',
             260),
    'load': ('at 38; press A; wait 6; press DOWN; wait 1.5; press A; wait 7; press A; wait 32; shot; wait 10; shot; exit',
             150),
}
NEEDS_GOLDEN = {'load', 'play'}  # these press Continue: without the golden save they test whatever save is there
SUITE = ('menu', 'load', 'play')

OK, OK_EXIT_CRASH, PROBLEM, NOT_STARTED, SETUP_ERROR = 'OK', 'OK_EXIT_CRASH', 'PROBLEM', 'NOT_STARTED', 'SETUP_ERROR'
PASSING = (OK, OK_EXIT_CRASH)
EXIT_CODES = {OK: 0, OK_EXIT_CRASH: 0, PROBLEM: 1, NOT_STARTED: 1, SETUP_ERROR: 2}
EXIT_CRASH_STRICT = 3


class Layout:
    """Where the game, its files and the results are. Tests point this at a scratch directory."""

    def __init__(self, root=ROOT, preset=PRESET):
        self.root, self.preset = root, preset
        self.build = os.path.join(root, 'Fable2Recomp', 'out', 'build', preset)
        self.exe = os.path.join(self.build, 'Fable2.exe')
        self.config = os.path.join(self.build, 'Fable2.toml')
        self.saves = os.path.join(self.build, *SAVE_SLOT)
        self.runs = os.path.join(self.build, 'runs')
        self.golden = os.path.join(self.runs, 'save_golden')
        self.slot_stash = os.path.join(self.runs, 'save_before_autotest')  # the user's save slot during a run
        self.snapshots = os.path.join(self.build, 'native_snapshots')
        self.log = os.path.join(self.build, 'fable2.log')
        self.results = os.path.join(root, 'build', 'autotest')
        self.ledger = os.path.join(root, 'build', 'validation', 'ledger.jsonl')
        # (the runtime, Fable2Recomp/, is part of the repository; rexglue-sdk is the public ReXGlue release with
        # patches/rexglue-sdk.patch applied to its working tree, so its 'dirty' flag is expected: the patch hash says
        # which changes it carries)
        self.repos = {'umbrella': root, 'rexglue-sdk': os.path.join(root, 'rexglue-sdk')}
        self.sdk_patch = os.path.join(root, 'patches', 'rexglue-sdk.patch')


_DEFAULT = Layout()
BUILD, SAVES, GOLDEN = _DEFAULT.build, _DEFAULT.saves, _DEFAULT.golden  # (older callers)


# ---------------------------------------------------------------- the script

def script_steps(script):
    """The commands as src/autotest.cpp runs them: ';'-separated, first word = verb, nothing after 'exit'."""
    out = []
    for command in script.split(';'):
        words = command.split()
        if not words:
            continue
        out.append(words)
        if words[0] == 'exit':
            break
    return out


def expectations(script):
    steps = script_steps(script)
    return {'shots': sum(1 for w in steps if w[0] == 'shot'), 'exit': any(w[0] == 'exit' for w in steps)}


def scenario_of(script):
    return next((name for name, (s, _) in SCENARIOS.items() if s == script), None)


# ---------------------------------------------------------------- the log of this run only

LOG_TAIL = 4096      # bytes before the launch point kept to recognise it again
LOG_SEGMENTS = 64    # rotated copies looked at: fable2.1.log ... fable2.64.log


def log_segments(path):
    """The log and its rotated copies (spdlog rotating sink), newest first: [(path, os.stat_result)]."""
    base, ext = os.path.splitext(path)
    out = []
    for i in range(LOG_SEGMENTS + 1):
        p = path if i == 0 else f'{base}.{i}{ext}'
        try:
            out.append((p, os.stat(p)))
        except OSError:
            pass
    return out


def mark_log(path):
    """Where the log stands before a launch (size, file identity, last bytes, every segment's signature)."""
    m = {'path': path, 'time': time.time(), 'size': 0, 'ino': 0, 'tail': b'',
         'before': [(st.st_ino, st.st_size, st.st_mtime_ns) for _, st in log_segments(path)]}
    try:
        st = os.stat(path)
    except OSError:
        return m
    m['size'], m['ino'] = st.st_size, st.st_ino
    n = min(LOG_TAIL, st.st_size)
    if n:
        with open(path, 'rb') as f:
            f.seek(st.st_size - n)
            m['tail'] = f.read(n)
    return m


def _tail_matches(path, size, tail):
    try:
        with open(path, 'rb') as f:
            f.seek(size - len(tail))
            return f.read(len(tail)) == tail
    except OSError:
        return False


def run_log_plan(mark):
    """What the log gained since `mark`: ([(path, offset)] oldest first, notes)."""
    segs = log_segments(mark['path'])  # newest first
    notes, start = [], None
    if mark['size']:
        # 1. the pre-launch file by identity (a rename keeps it), its old end recognised by the bytes before it
        for i, (p, st) in enumerate(segs):
            if not mark['ino'] or st.st_ino != mark['ino']:
                continue
            if st.st_size < mark['size']:
                notes.append(f'{os.path.basename(p)} shrank from {mark["size"]} to {st.st_size} bytes during the run '
                             '(truncated): the lines before that are lost')
                start = (i, 0)
            elif _tail_matches(p, mark['size'], mark['tail']):
                start = (i, mark['size'])
            break
        # 2. by content alone (no file identity on this file system, or the file was copied)
        if start is None:
            for i, (p, st) in enumerate(segs):
                if st.st_size >= mark['size'] and _tail_matches(p, mark['size'], mark['tail']):
                    start = (i, mark['size'])
                    if mark['ino']:
                        notes.append('found where the log stood before the launch by its content')
                    break
    if start is not None:
        i, offset = start
        if i:
            notes.append(f'log rotated during the run: read {i + 1} segments')
        return [(segs[i][0], offset)] + [(segs[j][0], 0) for j in range(i - 1, -1, -1)], notes
    # Nothing to continue from (the log was empty or missing), or it is gone (rotated out, deleted): every
    # segment that differs from all the segments that existed before the launch was written by this run.
    before = set(mark['before'])
    plan = [(p, 0) for p, st in reversed(segs) if (st.st_ino, st.st_size, st.st_mtime_ns) not in before]
    if mark['size']:
        notes.append('the log as it was before the launch is gone (rotated out or deleted): '
                     f'read the {len(plan)} segment(s) written since')
    return plan, notes


def iter_plan_lines(plan):
    for path, offset in plan:
        try:
            with open(path, 'rb') as f:
                f.seek(offset)
                for raw in f:
                    yield raw.decode('utf-8', 'replace')
        except OSError:
            continue


def plan_bytes(plan):
    total = 0
    for path, offset in plan:
        try:
            total += max(0, os.path.getsize(path) - offset)
        except OSError:
            pass
    return total


STEP_EXIT = re.compile(r'autotest: [\d.]+ s exit')
STEP_SHOT = re.compile(r'autotest: [\d.]+ s shot')
SNAPSHOT_LINE = 'native renderer: snapshot '


def _log_state(starts=0):
    return {'starts': starts, 'steps': [], 'critical': [], 'levels': [], 'unknown': [], 'shot_requests': 0,
            'snapshots': [], 'primaries': [], 'finished': False, 'exit_step': False, '_pending': 0}


def parse_log(lines):
    """The facts of the last game start in `lines` (the log text of one launch)."""
    p = _log_state()
    for line in lines:
        if 'Fable2 starting' in line:
            p = _log_state(p['starts'] + 1)  # (a second start in one launch's text: keep the last one)
        elif '[critical]' in line or 'FATAL' in line:
            p['critical'].append(line.strip()[:300])
        elif 'autotest:' in line:
            s = line.strip()
            s = s[s.find('autotest:'):]
            p['steps'].append(s[:120])
            if STEP_EXIT.fullmatch(s):
                p['finished'] = p['exit_step'] = True
            elif s == 'autotest: script finished':
                p['finished'] = True
            elif STEP_SHOT.fullmatch(s):
                p['shot_requests'] += 1
                p['_pending'] += 1
            elif s.startswith('autotest: unknown command'):
                p['unknown'].append(s[:200])
        elif SNAPSHOT_LINE in line:
            name = line.strip().split(SNAPSHOT_LINE, 1)[1].strip().replace('\\', '/').rsplit('/', 1)[-1]
            p['snapshots'].append(name)
            if p['_pending']:  # the first snapshot after a shot request is that step's picture
                p['primaries'].append(name)
                p['_pending'] = 0
        elif 'audio level: peak ' in line:  # (hooks_audio_trace.cpp; the game's mix, measured also when muted)
            try:
                p['levels'].append(float(line.split('audio level: peak ')[1].split(',')[0]))
            except (IndexError, ValueError):
                pass
    del p['_pending']
    return p


def read_run_log(mark):
    plan, notes = run_log_plan(mark)
    log = parse_log(iter_plan_lines(plan))
    log['bytes'], log['segments'], log['notes'] = plan_bytes(plan), len(plan), notes
    if log['starts'] > 1:
        log['notes'].append(f'{log["starts"]} game starts in the log of this launch: judged the last one')
    return log


# ---------------------------------------------------------------- snapshots

FRAME = re.compile(r'frame_(\d+)\.png')


def list_snapshots(directory):
    out = {}
    try:
        names = os.listdir(directory)
    except OSError:
        return out
    for n in names:
        if FRAME.fullmatch(n):
            try:
                st = os.stat(os.path.join(directory, n))
            except OSError:
                continue
            out[n] = (st.st_size, st.st_mtime_ns)
    return out


def new_snapshots(directory, before):
    """Snapshot files written by this run (new, or rewritten: frame numbers restart with every run)."""
    after = list_snapshots(directory)
    return sorted((n for n, sig in after.items() if before.get(n) != sig),
                  key=lambda n: int(FRAME.fullmatch(n).group(1)))


def frame_groups(names, gap=4):
    """Fallback without snapshot lines in the log: one shot step = one run of nearly consecutive frames."""
    firsts, last = [], None
    for n in names:
        f = int(FRAME.fullmatch(n).group(1))
        if last is None or f - last > gap:
            firsts.append(n)
        last = f
    return firsts


PNG_SIGNATURE = b'\x89PNG\r\n\x1a\n'


def _png_rows(path, step=1):
    """Minimal PNG decoder (8-bit, not interlaced) for machines without Pillow/numpy: (width, rgb rows of
    every `step`-th row)."""
    with open(path, 'rb') as f:
        data = f.read()
    if data[:8] != PNG_SIGNATURE:
        raise ValueError('not a PNG')
    pos, idat, hdr = 8, [], None
    while pos + 8 <= len(data):
        n = struct.unpack('>I', data[pos:pos + 4])[0]
        kind, body = data[pos + 4:pos + 8], data[pos + 8:pos + 8 + n]
        pos += 12 + n
        if kind == b'IHDR':
            hdr = struct.unpack('>IIBBBBB', body[:13])
        elif kind == b'IDAT':
            idat.append(body)
        elif kind == b'IEND':
            break
    if hdr is None:
        raise ValueError('no IHDR')
    w, h, depth, ctype, _, _, interlace = hdr
    if depth != 8 or interlace or ctype not in (0, 2, 4, 6):
        raise ValueError('unsupported PNG format')
    bpp = {0: 1, 2: 3, 4: 2, 6: 4}[ctype]
    raw = zlib.decompress(b''.join(idat))
    stride = w * bpp
    prev = bytearray(stride)
    rows = []
    for y in range(h):
        i = y * (stride + 1)
        kind, line = raw[i], bytearray(raw[i + 1:i + 1 + stride])
        if kind == 1:
            for x in range(bpp, stride):
                line[x] = (line[x] + line[x - bpp]) & 255
        elif kind == 2:
            for x in range(stride):
                line[x] = (line[x] + prev[x]) & 255
        elif kind == 3:
            for x in range(stride):
                line[x] = (line[x] + ((line[x - bpp] if x >= bpp else 0) + prev[x]) // 2) & 255
        elif kind == 4:
            for x in range(stride):
                a = line[x - bpp] if x >= bpp else 0
                b, c = prev[x], (prev[x - bpp] if x >= bpp else 0)
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                line[x] = (line[x] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 255
        elif kind != 0:
            raise ValueError(f'bad PNG filter {kind}')
        if y % step == 0:
            if bpp >= 3:
                rows.append([(line[x], line[x + 1], line[x + 2]) for x in range(0, stride, bpp)])
            else:
                rows.append([(line[x], line[x], line[x]) for x in range(0, stride, bpp)])
        prev = line
    return w, rows


def image_stats_stdlib(path):
    _, rows = _png_rows(path, step=2)
    n = s = s2 = lit = 0
    diff = pairs = 0
    for row in rows:
        for i, (r, g, b) in enumerate(row):
            y = 0.299 * r + 0.587 * g + 0.114 * b
            n += 1
            s += y
            s2 += y * y
            lit += y > 16
            if i:
                pr, pg, pb = row[i - 1]
                diff += abs(r - pr) + abs(g - pg) + abs(b - pb)
                pairs += 3
    mean = s / n
    return {'luma': mean, 'std': max(0.0, s2 / n - mean * mean) ** 0.5, 'lit': lit / n,
            'noise': diff / pairs if pairs else 0.0}


def image_stats(path):
    """Mean luminance, its standard deviation, share of pixels brighter than 16 and the noise score (mean
    difference between horizontally neighbouring pixels) over every second row. None: unreadable."""
    try:
        try:
            import numpy as np
            from PIL import Image
        except ImportError:
            return image_stats_stdlib(path)
        with Image.open(path) as im:
            a = np.asarray(im.convert('RGB'))
        rows = a[::2].astype(np.int16)
        y = rows[..., 0] * 0.299 + rows[..., 1] * 0.587 + rows[..., 2] * 0.114
        return {'luma': float(y.mean()), 'std': float(y.std()), 'lit': float((y > 16).mean()),
                'noise': float(np.abs(rows[:, 1:] - rows[:, :-1]).mean()) if rows.shape[1] > 1 else 0.0}
    except Exception:  # (any decoder error: the file is not a usable picture)
        return None


def noise(path):
    st = image_stats(path)
    return st['noise'] if st else 255.0


def verdict(stats, floors):
    if stats is None:
        return 'unreadable'
    if stats['luma'] < floors['luma']:
        return f'black (luminance {stats["luma"]:.1f} < {floors["luma"]:g})'
    if stats['std'] < floors['std']:
        return f'flat (luminance deviation {stats["std"]:.1f} < {floors["std"]:g})'
    if stats['noise'] > floors['noise']:
        return f'scrambled (noise {stats["noise"]:.1f} > {floors["noise"]:g})'
    return 'ok'


def default_floors():
    return {'luma': MIN_LUMA, 'std': MIN_STD, 'noise': SCRAMBLED}


# ---------------------------------------------------------------- run outcome

def parse_status(stdout):
    """run_game.ps1's status line -> (line or None, how the process ended)."""
    line = next((l.strip() for l in (stdout or '').splitlines() if l.strip().startswith('run_game:')), None)
    if line is None:
        return None, {'kind': 'none'}
    m = re.search(r'exited code=(-?\d+)', line)
    if m:
        return line, {'kind': 'exited', 'code': int(m.group(1))}
    if 'still running' in line:
        return line, {'kind': 'time_limit', 'forced': '(forced)' in line}
    return line, {'kind': 'unknown'}


def hex_code(code):
    return f'0x{code & 0xFFFFFFFF:08X}'


def classify(expect, status, end, log, shots, missing, floors):
    """-> (result, reasons, exit_detail). `shots`: dicts with name, step (0 = follow-up frame), verdict."""
    if status is None:
        return NOT_STARTED, ['the launcher did not report a game run (no "run_game:" status line)'], None
    if not log['starts']:
        return NOT_STARTED, ['no "Fable2 starting" line in the log written since this launch'], None
    reasons, detail = [], None
    if not log['finished']:
        why = 'the script did not reach its end'
        if end['kind'] == 'exited':
            why += f' (the game exited with code {hex_code(end["code"])} first)'
        elif end['kind'] == 'time_limit':
            why += ' (stopped at the time limit)'
        reasons.append(why)
    elif log['shot_requests'] < expect['shots']:
        reasons.append(f'only {log["shot_requests"]} of {expect["shots"]} shot steps are in the log')
    reasons += [f'script error: {u}' for u in log['unknown']]
    if log['critical']:
        reasons.append(f'{len(log["critical"])} critical/FATAL log line(s)')
    if log['levels'] and max(log['levels']) < 1e-3:
        reasons.append('no sound: the game\'s audio mix stayed silent all through')
    if len(shots) < expect['shots']:
        reasons.append(f'{expect["shots"]} shot step(s) but {len(shots)} snapshot file(s) from this run')
    taken = [s for s in shots if s['step']]
    if len(taken) < expect['shots']:
        reasons.append(f'{expect["shots"]} shot step(s) but {len(taken)} snapshot(s) taken for them')
    reasons += [f'snapshot {n} named in the log was not written by this run' for n in missing]
    reasons += [f'shot step {s["step"]} ({s["name"]}): {s["verdict"]}' for s in taken if s['verdict'] != 'ok']
    if end['kind'] == 'unknown':
        reasons.append(f'unrecognised launcher status: {status}')
    if log['finished']:
        if expect['exit']:
            if end['kind'] == 'exited' and end['code'] != 0:
                detail = f'crashed while closing (exit code {hex_code(end["code"])})'
            elif end['kind'] == 'time_limit':
                detail = 'did not close after the exit step: closed at the time limit' + \
                         (' (killed)' if end['forced'] else '')
        elif end['kind'] == 'exited':
            reasons.append(f'the game ended by itself (exit code {hex_code(end["code"])}) although the script has '
                           'no exit step')
        elif end['kind'] == 'time_limit' and end['forced']:
            detail = 'did not close when asked at the time limit (killed)'
    if reasons:
        return PROBLEM, reasons, detail
    return (OK_EXIT_CRASH if detail else OK), [], detail


def exit_code_of(result, strict_exit=False):
    if result == OK_EXIT_CRASH and strict_exit:
        return EXIT_CRASH_STRICT
    return EXIT_CODES[result]


# ---------------------------------------------------------------- saves

def _files_under(directory):
    out = []
    for base, dirs, files in os.walk(directory):
        dirs.sort()
        for f in sorted(files):
            p = os.path.join(base, f)
            out.append((os.path.relpath(p, directory).replace('\\', '/'), os.path.getsize(p)))
    return out


_HASHES = {}


def sha256_file(path):
    try:
        st = os.stat(path)
    except OSError:
        return None
    key = (os.path.abspath(path), st.st_size, st.st_mtime_ns)
    if key not in _HASHES:
        h = hashlib.sha256()
        with open(path, 'rb') as f:
            for chunk in iter(lambda: f.read(1 << 20), b''):
                h.update(chunk)
        _HASHES[key] = h.hexdigest()
    return _HASHES[key]


def tree_sha256(directory):
    """One digest of a directory: relative paths and file digests (None when it does not exist)."""
    if not os.path.isdir(directory):
        return None
    h = hashlib.sha256()
    for rel, _ in _files_under(directory):
        h.update(f'{rel}\0{sha256_file(os.path.join(directory, rel))}\n'.encode())
    return h.hexdigest()


def has_golden(layout):
    return os.path.isdir(layout.golden) and bool(_files_under(layout.golden))


RETRY_TRIES, RETRY_WAIT = 10, 0.5  # a rename refused while a handle is still open (game just closed, scanner)


def _retry(fn, *args):
    for i in range(RETRY_TRIES):
        try:
            return fn(*args)
        except PermissionError:
            if i == RETRY_TRIES - 1:
                raise
            time.sleep(RETRY_WAIT)


def _unique(path):
    """`path`, or `path`_2, _3, ... when it exists (nothing is ever overwritten)."""
    if not os.path.exists(path):
        return path
    n = 2
    while os.path.exists(f'{path}_{n}'):
        n += 1
    return f'{path}_{n}'


def _stamp():
    return time.strftime('%Y%m%d_%H%M%S')


def recover_slot(layout):
    """An earlier run was killed before it moved the user's save slot back: the slot is still in layout.slot_stash.
    Move it back. What the slot holds now (the test's save, or anything played since) is kept as
    runs/save_slot_found_<time>, never deleted. -> messages (empty when there was nothing to do). Raises OSError."""
    if not os.path.exists(layout.slot_stash):
        return []
    notes = []
    if os.path.exists(layout.saves):
        kept = _unique(os.path.join(layout.runs, f'save_slot_found_{_stamp()}'))
        _retry(os.replace, layout.saves, kept)
        notes.append(f'kept the save slot that an interrupted check left behind as {kept}')
    os.makedirs(os.path.dirname(layout.saves), exist_ok=True)
    _retry(os.replace, layout.slot_stash, layout.saves)
    notes.append(f'an earlier check did not finish: moved your save slot back from {layout.slot_stash}')
    return notes


def swap_in_golden(layout):
    """Move the user's save slot to layout.slot_stash and copy the golden save into the slot. -> the stash path,
    or None when there was no slot. Raises OSError; the slot is then as it was."""
    stash = None
    if os.path.exists(layout.saves):
        if os.path.exists(layout.slot_stash):
            raise FileExistsError(f'{layout.slot_stash} exists (an earlier check did not move it back)')
        os.makedirs(layout.runs, exist_ok=True)
        _retry(os.replace, layout.saves, layout.slot_stash)
        stash = layout.slot_stash
    try:
        shutil.copytree(layout.golden, layout.saves)
    except BaseException:
        put_back_slot(layout, stash)
        raise
    return stash


def put_back_slot(layout, stash):
    """Replace the slot the test ran with by the user's slot (`stash`, from swap_in_golden; None: there was no
    slot). The test's slot is deleted only after the user's is back in place. Raises OSError."""
    trash = None
    if os.path.exists(layout.saves):
        trash = _unique(os.path.join(layout.runs, 'save_slot_after_autotest'))
        _retry(os.replace, layout.saves, trash)
    try:
        if stash is not None:
            _retry(os.replace, stash, layout.saves)
    finally:
        if trash:
            shutil.rmtree(trash, ignore_errors=True)


def game_running():
    if os.name != 'nt':
        return False
    try:
        r = subprocess.run(['tasklist', '/FI', 'IMAGENAME eq Fable2.exe', '/NH'], capture_output=True, text=True,
                           timeout=30)
    except (OSError, subprocess.TimeoutExpired):
        return False
    return 'fable2.exe' in r.stdout.lower()


def make_golden(layout=None, force=False, is_running=game_running, quiet=False):
    """Copy the current save slot to the golden save. Returns 0, or 2 when it refuses or fails. The new copy is
    complete (with its manifest) before an existing golden save is moved to save_golden.old_<time>; when a step
    fails, the renames are undone and the previous golden save stays in place."""
    layout = layout or _DEFAULT
    say = (lambda *a: None) if quiet else print
    src, dst = layout.saves, layout.golden
    if is_running():
        say('make-golden: Fable2.exe is running; close the game normally first (it may be writing the save)')
        return 2
    try:
        for note in recover_slot(layout):  # (else the slot would be a test's save, not the user's)
            say(f'make-golden: {note}')
    except OSError as e:
        say(f'make-golden: an earlier check left your save slot in {layout.slot_stash} and it could not be moved '
            f'back ({e}). Move it back to {src} yourself, then run this again.')
        return 2
    files = _files_under(src) if os.path.isdir(src) else []
    if not any(rel.rsplit('/', 1)[-1].lower() == 'mainsave.bin' for rel, _ in files):
        say(f'make-golden: no save (no mainsave.bin) in {src}: play until the game has saved, close it normally, '
            'then run this again')
        return 2
    empty = [rel for rel, size in files if size == 0]
    if empty:
        say(f'make-golden: empty file(s) in the save slot ({", ".join(empty[:5])}): the save looks incomplete')
        return 2
    if os.path.exists(dst) and not force:
        say(f'make-golden: {dst} exists; pass --force to replace it (the old one is kept next to it)')
        return 2
    tmp, tmp_manifest, old, had_golden = dst + '.tmp', dst + '.json.tmp', None, os.path.exists(dst)
    done = []  # renames made so far, undone in reverse order when a later step fails

    def rename(a, b):
        _retry(os.replace, a, b)
        done.append((a, b))
    try:
        for p in (tmp, tmp_manifest):
            if os.path.isdir(p):
                shutil.rmtree(p)
            elif os.path.exists(p):
                os.remove(p)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copytree(src, tmp)
        if _files_under(tmp) != files:
            raise OSError(f'the save slot changed while it was copied ({src})')
        manifest = {'time': datetime.datetime.now().astimezone().isoformat(timespec='seconds'), 'source': src,
                    'sha256': tree_sha256(tmp),  # (relative paths + contents: the same digest once renamed)
                    'files': [{'path': rel, 'bytes': size, 'sha256': sha256_file(os.path.join(tmp, rel))}
                              for rel, size in files]}
        with open(tmp_manifest, 'w', encoding='utf-8') as f:
            json.dump(manifest, f, indent=1)
        if os.path.exists(dst):
            old = _unique(f'{dst}.old_{_stamp()}')
            rename(dst, old)
            if os.path.exists(dst + '.json'):
                rename(dst + '.json', old + '.json')
        rename(tmp, dst)
        rename(tmp_manifest, dst + '.json')
    except BaseException as e:  # (also Ctrl+C: never leave the golden save renamed away)
        undone = True
        for a, b in reversed(done):
            try:
                _retry(os.replace, b, a)
            except OSError:
                undone = False
        for p in (tmp, tmp_manifest):
            if os.path.isdir(p):
                shutil.rmtree(p, ignore_errors=True)
            elif os.path.exists(p):
                try:
                    os.remove(p)
                except OSError:
                    pass
        if undone:
            state = f'the previous golden save {dst} is unchanged' if had_golden else 'nothing was changed'
        else:
            state = f'the previous golden save could not be put back: it is {old}; rename it to {dst}'
        if not isinstance(e, OSError):
            print(f'make-golden: stopped; {state}', file=sys.stderr)
            raise
        say(f'make-golden: could not write the golden save ({e}); {state}')
        return 2
    if old:
        say(f'  previous golden save kept as {old}')
    say(f'golden save: {len(files)} files, {sum(s for _, s in files)} bytes, {src} -> {dst}')
    say(f'  Game checks now start from it. During each check your save slot is moved to {layout.slot_stash}, '
        'the golden save is copied into the slot, and your slot is moved back when the check ends (whatever '
        'the game saved during the check is discarded).')
    say('  This is your own save: it stays on this machine (out/build is not tracked by git). Do not publish it.')
    return 0


# ---------------------------------------------------------------- ledger

def git_state(path):
    """Revision and dirty flag (tracked files changed) of the checkout whose own .git is at `path`. Read-only:
    --no-optional-locks keeps `git status` from refreshing .git/index (it would take index.lock, and a git add,
    commit or checkout run at the same moment by the user or another tool would fail on it)."""
    if not os.path.exists(os.path.join(path, '.git')):
        return None

    def git(*args):
        return subprocess.run(['git', '--no-optional-locks', '-C', path, *args], capture_output=True, text=True,
                              timeout=60, env=dict(os.environ, GIT_OPTIONAL_LOCKS='0'))
    try:
        rev = git('rev-parse', 'HEAD')
        st = git('status', '--porcelain', '--untracked-files=no', '--ignore-submodules=dirty')
    except (OSError, subprocess.TimeoutExpired):
        return {'rev': None, 'dirty': None}
    return {'rev': rev.stdout.strip() if rev.returncode == 0 else None,
            'dirty': bool(st.stdout.strip()) if st.returncode == 0 else None}


HASH_CACHE_ENTRIES = 32


def cached_sha256(paths, cache_path):
    """sha256 of each file, remembered across runs by (path, size, modification time) in `cache_path`: the
    exe is ~230 MB and every game check is its own process."""
    try:
        with open(cache_path, encoding='utf-8') as f:
            cache = dict(json.load(f))
    except (OSError, ValueError, TypeError):
        cache = {}
    out, changed = {}, False
    for p in paths:
        try:
            st = os.stat(p)
        except OSError:
            out[p] = None
            continue
        key = f'{os.path.abspath(p)}|{st.st_size}|{st.st_mtime_ns}'
        if key not in cache:
            cache[key], changed = sha256_file(p), True
        else:
            cache[key] = cache.pop(key)  # (most recently used last)
        out[p] = cache[key]
    if changed:
        try:
            os.makedirs(os.path.dirname(cache_path), exist_ok=True)
            with open(cache_path, 'w', encoding='utf-8') as f:
                json.dump(dict(list(cache.items())[-HASH_CACHE_ENTRIES:]), f, indent=1)
        except OSError:
            pass
    return out


def build_identity(layout):
    patch_file = getattr(layout, 'sdk_patch', None)
    files = [layout.exe, layout.config] + ([patch_file] if patch_file else [])
    sums = cached_sha256(files, os.path.join(os.path.dirname(layout.ledger), 'sha256_cache.json'))
    out = {'exe': {'path': layout.exe, 'sha256': sums[layout.exe]},
           'config': {'path': layout.config, 'sha256': sums[layout.config]},
           'git': {name: git_state(path) for name, path in layout.repos.items()}}
    if patch_file:
        out['sdk_patch'] = {'path': patch_file, 'sha256': sums[patch_file]}
    return out


def append_ledger(path, record):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, 'a', encoding='utf-8') as f:
        f.write(json.dumps(record) + '\n')


# ---------------------------------------------------------------- one run

def launch_game(layout, env, limit, tag):
    """tools/run_game.ps1: job object, time limit, close then kill. -> (returncode, stdout, stderr)"""
    r = subprocess.run(['powershell', '-ExecutionPolicy', 'Bypass', '-File', os.path.join(TOOLS, 'run_game.ps1'),
                        '-Preset', layout.preset, '-Seconds', str(limit), '-Tag', 'autotest_' + tag],
                       env=env, capture_output=True, text=True)
    return r.returncode, r.stdout, r.stderr


def setup_problems(layout, scenario, require_golden=False):
    out = []
    if not os.path.isfile(layout.exe):
        out.append(f'missing {layout.exe} (build the {layout.preset} preset first)')
    if (require_golden or scenario in NEEDS_GOLDEN) and not has_golden(layout):
        out.append(f'no golden save in {layout.golden}: the {scenario or "script"} check loads a save. Create it '
                   'from your current save slot with: python tools/autotest.py --make-golden')
    return out


def slot_text(slot):
    """One line about the user's save slot during a run (run()'s save_slot dict)."""
    if slot['put_back'] is None:
        return 'save slot: not touched (no golden save)'
    if slot['put_back']:
        if slot['moved_to'] is None:
            return 'save slot: the run started from the golden save (there was no slot before; the test\'s was removed)'
        return f'save slot: the run started from the golden save; yours was kept in {slot["moved_to"]} and moved back'
    if slot['moved_to'] is None:
        return (f'save slot: the test\'s save could not be removed from {slot["path"]} ({slot["error"]}); '
                'the next check moves it aside')
    return (f'save slot: YOURS WAS NOT MOVED BACK ({slot["error"]}): it is in {slot["moved_to"]}. The next check '
            f'(or --make-golden) moves it back, or move it to {slot["path"]} yourself.')


def format_summary(info):
    lines = [f'script: {info["script"]}', f'cvars: {info["cvars"]}', f'scenario: {info["scenario"] or "custom"}']
    slot = info.get('slot')
    if slot:
        lines += [f'save slot: {n}' for n in slot['recovered']]
        if info['result'] != SETUP_ERROR:
            lines.append(slot_text(slot))
    if info['status'] is not None or info['result'] != SETUP_ERROR:
        lines += [info['status'] or '(no run_game status line)', f'wall: {info["wall"]:.0f} s']
    log = info.get('log')
    if log is not None:
        lines.append(f'log: {log["bytes"]} bytes from this launch in {log["segments"]} segment(s), '
                     f'{log["starts"]} game start(s)')
        lines += [f'  note: {n}' for n in log['notes']]
        lines.append(f'script steps run: {len(log["steps"])}' +
                     ('' if log['finished'] else '  (DID NOT REACH THE END)'))
    shots = info.get('shot_info') or []
    if info['result'] != SETUP_ERROR:
        lines.append(f'shots: {info["expect"]["shots"]} shot step(s), {len(shots)} snapshot file(s), '
                     f'{sum(1 for s in shots if s["step"])} taken for the steps' +
                     (f' (matched by {info["matched_by"]})' if shots else ''))
    for s in shots:
        st = s['stats']
        nums = (f'luma {st["luma"]:5.1f}  std {st["std"]:5.1f}  noise {st["noise"]:4.1f}' if st else 'unreadable')
        lines.append(f'  {os.path.basename(s["path"])}  {nums}  ' +
                     (f'step {s["step"]}: {s["verdict"]}' if s['step'] else f'(follow-up frame: {s["verdict"]})'))
    if log is not None:
        levels = log['levels']
        if levels:
            lines.append(f'audio: loudest {max(levels):.3f}, {sum(1 for v in levels if v >= 1e-3)} of {len(levels)} '
                         '2-second periods not silent' + ('  NO SOUND' if max(levels) < 1e-3 else ''))
        else:
            lines.append('audio: not measured (no "audio level" lines; audio_level_log off?)')
        lines.append(f'critical log lines: {len(log["critical"])}')
        lines += log['critical'][:10]
    if info['reasons']:
        lines.append('problems:')
        lines += [f'  - {r}' for r in info['reasons']]
    lines.append(f'RESULT: {info["result"]}' + (f' ({info["detail"]})' if info['detail'] else '') +
                 f'   exit code {info["exit_code"]}   ({info["dir"]})')
    return '\n'.join(lines)


def run(script, cvars='', tag=None, limit=180, quiet=False, *, scenario=None, layout=None, launcher=None,
        require_golden=False, strict_exit=False, floors=None, suite=None):
    """One game run. Returns a dict: result, exit_code, ok, finished, status, shots [(path, noise)] (every snapshot
    file, also follow-up frames), shot_info [dicts], critical [lines], steps [lines], reasons [text], exit_detail,
    save_slot {path, moved_to, put_back, error, recovered}, dir.

    `ok` is result in (OK, OK_EXIT_CRASH): every check passed, the snapshot checks included (a black, flat,
    scrambled or missing shot makes it False). Before 2026-10 it meant only "finished, no critical line, not
    silent"; that narrower test is `finished and not critical`. SETUP_ERROR and NOT_STARTED say nothing about the
    game (ok and finished are False, no shots): a caller that bisects should stop on them, not count them as bad."""
    layout = layout or _DEFAULT
    launcher = launcher or launch_game
    floors = floors or default_floors()
    scenario = scenario or scenario_of(script)
    tag = tag or time.strftime('%H%M%S')
    out = os.path.join(layout.results, tag)
    if os.path.isdir(out):
        shutil.rmtree(out)
    os.makedirs(out)
    expect = expectations(script)
    started = datetime.datetime.now().astimezone().isoformat(timespec='seconds')
    info = {'script': script, 'cvars': cvars, 'scenario': scenario, 'expect': expect, 'status': None, 'wall': 0.0,
            'log': None, 'shot_info': [], 'matched_by': None, 'reasons': [], 'detail': None, 'dir': out}
    identity = build_identity(layout)
    restored = False
    slot = {'path': layout.saves, 'moved_to': None, 'put_back': None, 'error': None, 'recovered': []}
    info['slot'] = slot
    problems = setup_problems(layout, scenario, require_golden)
    if not problems:
        try:
            slot['recovered'] = recover_slot(layout)
        except OSError as e:
            problems = [f'an earlier check left your save slot in {layout.slot_stash} and it could not be moved back '
                        f'({e}); move it back to {layout.saves} yourself']
        for note in slot['recovered']:
            print(f'autotest: {note}', file=sys.stderr)
    if not problems and has_golden(layout):
        try:
            slot['moved_to'] = swap_in_golden(layout)
            restored = True
        except OSError as e:
            where = (f'your save slot is in {layout.slot_stash} (the next check moves it back)'
                     if os.path.exists(layout.slot_stash) else 'the save slot was left as it was')
            problems = [f'could not start from the golden save ({e}); {where}. Is the game running?']
    if problems:
        result, reasons = SETUP_ERROR, problems
    else:
        try:
            mark = mark_log(layout.log)
            snaps_before = list_snapshots(layout.snapshots)
            env = dict(os.environ, F2_AUTOTEST=script, F2_CVARS=cvars)
            t0 = time.time()
            try:
                rc, stdout, stderr = launcher(layout, env, limit, tag)
            except OSError as e:
                rc, stdout, stderr = None, '', f'could not start the launcher: {e}'
            info['wall'] = time.time() - t0
            status, end = parse_status(stdout)
            info['status'] = status
            log = read_run_log(mark)
            info['log'] = log
            names = new_snapshots(layout.snapshots, snaps_before)
            if log['snapshots']:
                primaries, info['matched_by'] = log['primaries'], 'the log'
            else:
                primaries, info['matched_by'] = frame_groups(names), 'frame numbers (no snapshot lines in the log)'
            step_of = {}
            for i, n in enumerate(primaries):
                step_of.setdefault(n, i + 1)
            missing = [n for n in primaries if n not in names]
            for i, n in enumerate(names):
                dst = os.path.join(out, f'shot_{i + 1:02}_f{int(FRAME.fullmatch(n).group(1))}.png')
                shutil.move(os.path.join(layout.snapshots, n), dst)
                st = image_stats(dst)
                info['shot_info'].append({'name': n, 'path': dst, 'step': step_of.get(n, 0), 'stats': st,
                                          'verdict': verdict(st, floors)})
            result, reasons, info['detail'] = classify(expect, status, end, log, info['shot_info'], missing, floors)
            if result == NOT_STARTED:
                tail = (stderr or '').strip().splitlines()[-3:]
                reasons += [f'launcher: {t.strip()[:200]}' for t in tail]
                if rc not in (0, None):
                    reasons.append(f'launcher exit code {rc}')
        finally:  # (also on an exception or Ctrl+C: the user's slot goes back before anything else)
            if restored:
                try:
                    put_back_slot(layout, slot['moved_to'])
                    slot['put_back'] = True
                except OSError as e:
                    slot['put_back'], slot['error'] = False, str(e)
                    print(f'autotest: WARNING: {slot_text(slot)}', file=sys.stderr)
    info['result'], info['reasons'] = result, reasons
    info['exit_code'] = exit_code_of(result, strict_exit)
    text = format_summary(info)
    with open(os.path.join(out, 'summary.txt'), 'w', encoding='utf-8') as f:
        f.write(text + '\n')
    shots = info['shot_info']
    record = {'time': started, 'scenario': scenario or 'custom', 'suite': suite, 'tag': tag, 'result': result,
              'exit_code': info['exit_code'], 'exit_detail': info['detail'], 'reasons': reasons, 'script': script,
              'cvars': cvars, 'wall_s': round(info['wall'], 1), **identity,
              'shots': {'expected': expect['shots'], 'files': len(shots), 'taken': sum(1 for s in shots if s['step']),
                        'passing': sum(1 for s in shots if s['step'] and s['verdict'] == 'ok')},
              'golden_save': {'path': layout.golden, 'sha256': tree_sha256(layout.golden), 'restored': restored},
              'save_slot': slot,
              'log': ({'bytes': info['log']['bytes'], 'segments': info['log']['segments'],
                       'notes': info['log']['notes']} if info['log'] else None),
              'dir': out}
    append_ledger(layout.ledger, record)
    if not quiet:
        print(text)
    log = info['log'] or _log_state()
    return {'ok': result in PASSING, 'result': result, 'exit_code': info['exit_code'], 'exit_detail': info['detail'],
            'reasons': reasons, 'finished': log['finished'], 'status': info['status'],
            'shots': [(s['path'], s['stats']['noise'] if s['stats'] else 255.0) for s in shots], 'shot_info': shots,
            'critical': log['critical'], 'steps': log['steps'], 'save_slot': slot, 'dir': out}


def run_suite(names=SUITE, tag=None, cvars='', quiet=False, strict_exit=False, layout=None, **kw):
    """Scenarios in sequence; stops at the first run whose exit code is not 0. -> (exit code, [(name, result)])"""
    layout = layout or _DEFAULT
    base = tag or 'suite_' + time.strftime('%Y%m%d_%H%M%S')
    # A scenario that cannot run is refused before the earlier ones spend minutes running.
    order = list(names)
    blocked = next((n for n in order if setup_problems(layout, n)), None)
    if blocked is not None:
        order = [blocked]
    done, code = [], 0
    for name in order:
        script, limit = SCENARIOS[name]
        r = run(script, cvars, f'{base}_{name}', limit, quiet, scenario=name, layout=layout, strict_exit=strict_exit,
                suite=base, **kw)
        done.append((name, r))
        if r['exit_code'] != 0:
            code = r['exit_code']
            break
    skipped = [n for n in names if n not in [d for d, _ in done]]
    line = f'SUITE {base}: ' + ', '.join(f'{n} {r["result"]}' for n, r in done) + \
           (f'; not run: {", ".join(skipped)}' if skipped else '') + \
           f'; teardown crashes: {sum(1 for _, r in done if r["result"] == OK_EXIT_CRASH)}   exit code {code}'
    print(line)
    return code, done


def main(argv=None):
    ap = argparse.ArgumentParser(description='Unattended game checks (see the module documentation).')
    ap.add_argument('--script', default='')
    ap.add_argument('--scenario', choices=sorted(SCENARIOS), default='')
    ap.add_argument('--suite', nargs='?', const=','.join(SUITE), default=None,
                    help='comma-separated scenarios run in sequence (default: menu,load,play)')
    ap.add_argument('--make-golden', action='store_true', help='copy the current save slot to the golden save')
    ap.add_argument('--force', action='store_true', help='with --make-golden: replace an existing golden save')
    ap.add_argument('--cvars', default='')
    ap.add_argument('--tag', default=None)
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--preset', default=PRESET)
    ap.add_argument('--require-golden', action='store_true', help='--script runs: refuse to run without it')
    ap.add_argument('--strict-exit', action='store_true', help='exit code 3 for OK_EXIT_CRASH instead of 0')
    ap.add_argument('--min-luma', type=float, default=MIN_LUMA)
    ap.add_argument('--min-std', type=float, default=MIN_STD)
    ap.add_argument('--ledger', default=None, help='JSON-lines ledger (default build/validation/ledger.jsonl)')
    a = ap.parse_args(argv)
    layout = Layout(preset=a.preset)
    if a.ledger:
        layout.ledger = os.path.abspath(a.ledger)
    floors = {'luma': a.min_luma, 'std': a.min_std, 'noise': SCRAMBLED}
    if a.make_golden:
        return make_golden(layout, force=a.force)
    if a.suite is not None:
        names = [n.strip() for n in a.suite.split(',') if n.strip()]
        unknown = [n for n in names if n not in SCENARIOS]
        if unknown or not names:
            ap.error(f'--suite: unknown scenario(s) {", ".join(unknown)} (known: {", ".join(sorted(SCENARIOS))})')
        return run_suite(names, a.tag, a.cvars, strict_exit=a.strict_exit, layout=layout, floors=floors)[0]
    if a.scenario:
        script, limit = SCENARIOS[a.scenario]
    elif a.script.strip():
        script, limit = a.script, 180
    else:
        ap.error('give --scenario, --script, --suite or --make-golden')
    r = run(script, a.cvars, a.tag, a.limit or limit, scenario=a.scenario or None, layout=layout,
            require_golden=a.require_golden, strict_exit=a.strict_exit, floors=floors)
    return r['exit_code']


if __name__ == '__main__':
    sys.exit(main())
