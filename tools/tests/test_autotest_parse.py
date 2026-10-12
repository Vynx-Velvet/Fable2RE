"""Verdicts of tools/autotest.py without the game (seconds, no Fable2.exe, nothing under out/build touched).

    python -m unittest discover -s tools/tests

A scratch layout (temporary directory; F2_TEST_TMP picks its parent) stands in for the build folder, and a fake
launcher stands in for tools/run_game.ps1 + Fable2.exe: it appends log lines from fixtures/*.txt (the game's
log format; synthetic, no game data), rotates the log the way spdlog does, writes snapshot PNGs generated here
and returns a run_game status line. Fixtures:
  previous_run_ok.txt    an earlier run that passed (stale content the new run must not be judged by)
  menu_run.txt           a menu run: one shot step (3 snapshot files: the frame + 2 trace frames), exit
  load_run.txt           a load run: two shot steps, exit
  crash_after_start.txt  the game started and died before the end (the script echo contains "; exit")
  no_exit_run.txt        a script without an exit step ("script finished", closed at the time limit)
"""
import contextlib
import hashlib
import io
import json
import os
import random
import shutil
import stat
import struct
import subprocess
import sys
import tempfile
import unittest
import zlib
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import autotest  # noqa: E402

FIXTURES = os.path.join(HERE, 'fixtures')
MENU = autotest.SCENARIOS['menu'][0]
LOAD = autotest.SCENARIOS['load'][0]
NO_EXIT = 'at 1; shot; wait 5'
OK_STATUS = 'run_game: exited code=0 after 43s'
CRASH_STATUS = 'run_game: exited code=-1073741819 after 43s'  # 0xC0000005 as .NET prints the exit code
HANG_STATUS = 'run_game: still running after 80s -> closed (forced)'
LIMIT_STATUS = 'run_game: still running after 10s -> closed'


# ---------------------------------------------------------------- pictures

def _filter(kind, line, prev, bpp):
    out = bytearray(len(line))
    for i in range(len(line)):
        a = line[i - bpp] if i >= bpp else 0
        b, c = prev[i], (prev[i - bpp] if i >= bpp else 0)
        if kind == 0:
            p = 0
        elif kind == 1:
            p = a
        elif kind == 2:
            p = b
        elif kind == 3:
            p = (a + b) // 2
        else:
            pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
            p = a if pa <= pb and pa <= pc else b if pb <= pc else c
        out[i] = (line[i] - p) & 255
    return out


def png_bytes(w, h, pixel, filters=(0,)):
    """RGBA PNG; `filters` cycles over the rows (the game writes filter 0 only)."""
    raw, prev = bytearray(), bytearray(w * 4)
    for y in range(h):
        line = bytearray()
        for x in range(w):
            line += bytes(pixel(x, y)) + b'\xff'
        kind = filters[y % len(filters)]
        raw.append(kind)
        raw += _filter(kind, line, prev, 4)
        prev = line

    def chunk(kind, body):
        return struct.pack('>I', len(body)) + kind + body + struct.pack('>I', zlib.crc32(kind + body) & 0xFFFFFFFF)
    return (autotest.PNG_SIGNATURE + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0)) +
            chunk(b'IDAT', zlib.compress(bytes(raw))) + chunk(b'IEND', b''))


def real(x, y):
    return ((x * 4) % 256, (y * 6) % 256, 120)


def black(x, y):
    return (0, 0, 0)


def grey(x, y):
    return (128, 128, 128)


_rng = random.Random(1234)
_NOISE = [tuple(_rng.randrange(256) for _ in range(3)) for _ in range(64 * 36)]


def scrambled(x, y):
    return _NOISE[(y * 64 + x) % len(_NOISE)]


def write_png(path, pixel, w=64, h=36, filters=(0,)):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, 'wb') as f:
        f.write(png_bytes(w, h, pixel, filters))


# ---------------------------------------------------------------- scratch layout and fake game

def fixture(name):
    with open(os.path.join(FIXTURES, name), encoding='utf-8') as f:
        return f.read()


def crlf(text):
    return text.replace('\r\n', '\n').replace('\n', '\r\n').encode('utf-8')


def filler(n, tag='filler'):
    return ''.join(f'[2026-10-07 13:49:00.{i % 1000:03}] [debug] [sys] [t9] {tag} line {i} '
                   f'Completed delivery of APC to 82CC9F00\n' for i in range(n))


class Sandbox:
    def __init__(self, exe=True, config=True):
        parent = os.environ.get('F2_TEST_TMP') or None
        if parent:
            os.makedirs(parent, exist_ok=True)
        self.root = tempfile.mkdtemp(prefix='f2autotest_', dir=parent)
        self.layout = autotest.Layout(root=self.root, preset='test')
        self.layout.repos = {}  # (no git calls; GitStateTests covers them)
        os.makedirs(self.layout.build)
        if exe:
            with open(self.layout.exe, 'wb') as f:
                f.write(b'MZ fake exe for tests\0' * 10)
        if config:
            with open(self.layout.config, 'w', encoding='utf-8') as f:
                f.write('log_level = "debug"\n')

    def close(self):
        def writable_again(func, path, _):  # (git's object files are read-only on Windows)
            try:
                os.chmod(path, stat.S_IWRITE)
                func(path)
            except OSError:
                pass
        if sys.version_info >= (3, 12):
            shutil.rmtree(self.root, onexc=writable_again)
        else:
            shutil.rmtree(self.root, onerror=writable_again)

    def write_log(self, text, path=None):
        with open(path or self.layout.log, 'wb') as f:
            f.write(crlf(text))

    def segment(self, i):
        base, ext = os.path.splitext(self.layout.log)
        return self.layout.log if i == 0 else f'{base}.{i}{ext}'

    def make_save(self, where, content=b'save data', name='mainsave.bin'):
        d = os.path.join(where, 'Hero000')
        os.makedirs(d, exist_ok=True)
        with open(os.path.join(d, name), 'wb') as f:
            f.write(content)

    def ledger(self):
        try:
            with open(self.layout.ledger, encoding='utf-8') as f:
                return [json.loads(l) for l in f if l.strip()]
        except FileNotFoundError:
            return []


def rotate(log, keep=4):
    """spdlog rotating_file_sink: fable2.log -> fable2.1.log -> ... -> fable2.<keep>.log, new empty fable2.log."""
    base, ext = os.path.splitext(log)
    name = lambda i: log if i == 0 else f'{base}.{i}{ext}'  # noqa: E731
    if os.path.exists(name(keep)):
        os.remove(name(keep))
    for i in range(keep - 1, -1, -1):
        if os.path.exists(name(i)):
            os.replace(name(i), name(i + 1))
    open(log, 'wb').close()


class FakeGame:
    """Plays one run: log lines (with rotations at given line numbers), snapshot files, a status line."""

    def __init__(self, log_text='', frames=None, status=OK_STATUS, rc=0, stderr='', rotate_at=(), before_write=None):
        self.log_text, self.frames, self.status, self.rc, self.stderr = log_text, frames or {}, status, rc, stderr
        self.rotate_at, self.before_write = tuple(rotate_at), before_write
        self.calls, self.env, self.saves_seen = 0, None, None

    def __call__(self, layout, env, limit, tag):
        self.calls += 1
        self.env = env
        hero = os.path.join(layout.saves, 'Hero000')
        if os.path.isdir(hero):
            self.saves_seen = sorted(os.listdir(hero))
        if self.before_write:
            self.before_write(layout)
        text = self.log_text.format(snapdir=layout.snapshots, build=layout.build)
        lines = text.splitlines(keepends=True)
        cuts = [0] + [c for c in self.rotate_at] + [len(lines)]
        for k in range(len(cuts) - 1):
            if k:
                rotate(layout.log)
            with open(layout.log, 'ab') as f:
                f.write(crlf(''.join(lines[cuts[k]:cuts[k + 1]])))
        for name, pixel in self.frames.items():
            write_png(os.path.join(layout.snapshots, name), pixel)
        out = (self.status + '\n') if self.status else ''
        return self.rc, out + '  stderr: (fake)\n', self.stderr


MENU_FRAMES = {'frame_001802.png': real, 'frame_001803.png': real, 'frame_001804.png': real}
LOAD_FRAMES = {f'frame_{n:06}.png': real for n in (4385, 4386, 4387, 4986, 4987, 4988)}


class SandboxCase(unittest.TestCase):
    def setUp(self):
        self.sb = Sandbox()
        self.layout = self.sb.layout

    def tearDown(self):
        self.sb.close()

    def run_game(self, script, game, tag='t', **kw):
        return autotest.run(script, '', tag, 60, quiet=True, layout=self.layout, launcher=game, **kw)

    def summary(self, r):
        with open(os.path.join(r['dir'], 'summary.txt'), encoding='utf-8') as f:
            return f.read()


# ---------------------------------------------------------------- tests

class ScriptTests(unittest.TestCase):
    def test_shot_and_exit_steps(self):
        self.assertEqual(autotest.expectations(MENU), {'shots': 1, 'exit': True})
        self.assertEqual(autotest.expectations(LOAD), {'shots': 2, 'exit': True})
        self.assertEqual(autotest.expectations(autotest.SCENARIOS['boot'][0])['shots'], 4)
        self.assertEqual(autotest.expectations(autotest.SCENARIOS['play'][0])['shots'], 10)
        self.assertEqual(autotest.expectations('shot; exit; shot'), {'shots': 1, 'exit': True})  # nothing after exit
        self.assertEqual(autotest.expectations(NO_EXIT), {'shots': 1, 'exit': False})

    def test_scenario_inferred_from_script(self):
        self.assertEqual(autotest.scenario_of(LOAD), 'load')
        self.assertIsNone(autotest.scenario_of('at 1; exit'))


class CleanRunTests(SandboxCase):
    def test_menu_ok(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES))
        self.assertEqual((r['result'], r['exit_code'], r['ok']), ('OK', 0, True), r['reasons'])
        self.assertEqual(len(r['shots']), 3)
        self.assertEqual([s['step'] for s in r['shot_info']], [1, 0, 0])
        self.assertTrue(os.path.basename(r['shots'][0][0]).startswith('shot_01_f1802'))
        self.assertEqual(os.listdir(self.layout.snapshots), [])  # moved into the result folder
        self.assertIn('RESULT: OK', self.summary(r))

    def test_load_ok(self):
        self.sb.make_save(self.layout.golden)
        self.sb.write_log(fixture('previous_run_ok.txt'))
        r = self.run_game(LOAD, FakeGame(fixture('load_run.txt'), LOAD_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual([s['step'] for s in r['shot_info']], [1, 0, 0, 2, 0, 0])

    def test_no_exit_script_closed_at_time_limit(self):
        r = self.run_game(NO_EXIT, FakeGame(fixture('no_exit_run.txt'),
                                            {'frame_000031.png': real, 'frame_000032.png': real}, LIMIT_STATUS))
        self.assertEqual(r['result'], 'OK', r['reasons'])

    def test_no_exit_script_game_ended_by_itself(self):
        r = self.run_game(NO_EXIT, FakeGame(fixture('no_exit_run.txt'),
                                            {'frame_000031.png': real, 'frame_000032.png': real}, OK_STATUS))
        self.assertEqual(r['result'], 'PROBLEM')

    def test_unknown_script_command_fails(self):
        text = fixture('menu_run.txt').replace(
            "autotest: script 'at 40; shot; exit'\n",
            "autotest: script 'at 40; shot; exit'\n[2026-10-10 09:00:00.900] [error] [core] [t1001] "
            "autotest: unknown command ' jump'\n")
        r = self.run_game(MENU, FakeGame(text, MENU_FRAMES))
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any('unknown command' in x for x in r['reasons']))


class StaleLogTests(SandboxCase):
    """The log is appended across runs: a launch that did not start the game must not inherit the last run."""

    def setUp(self):
        super().setUp()
        self.sb.write_log(fixture('previous_run_ok.txt'))
        self.sb.write_log(fixture('previous_run_ok.txt'), self.sb.segment(1))

    def test_launcher_failed(self):
        game = FakeGame(status=None, rc=1, stderr='missing ...\\Fable2.exe\nAt run_game.ps1:21 char:31')
        r = self.run_game(MENU, game)
        self.assertEqual(game.calls, 1)
        self.assertEqual((r['result'], r['exit_code'], r['ok'], r['finished']), ('NOT_STARTED', 1, False, False))
        self.assertTrue(any('launcher exit code 1' in x for x in r['reasons']))

    def test_game_wrote_nothing(self):
        r = self.run_game(MENU, FakeGame(status=OK_STATUS))
        self.assertEqual(r['result'], 'NOT_STARTED')
        self.assertEqual(r['steps'], [])

    def test_lines_without_a_start_are_not_a_run(self):
        # a zombie instance's last words written after the launch point, but no start of this launch
        tail = fixture('previous_run_ok.txt').split('\n', 1)[1]
        r = self.run_game(MENU, FakeGame(tail, MENU_FRAMES))
        self.assertEqual(r['result'], 'NOT_STARTED')

    def test_old_snapshot_files_do_not_count(self):
        for name in MENU_FRAMES:  # left by an earlier run, same names (frame numbers restart every run)
            write_png(os.path.join(self.layout.snapshots, name), real)
        text = fixture('menu_run.txt')
        r = self.run_game(MENU, FakeGame(text, {}))  # the log names them, but this run did not write them
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertEqual(r['shots'], [])
        self.assertTrue(any('was not written by this run' in x for x in r['reasons']))

    def test_missing_exe_is_a_setup_error(self):
        os.remove(self.layout.exe)
        game = FakeGame(fixture('menu_run.txt'), MENU_FRAMES)
        r = self.run_game(MENU, game)
        self.assertEqual(game.calls, 0)
        self.assertEqual((r['result'], r['exit_code']), ('SETUP_ERROR', 2))

    def test_script_echo_is_not_the_end(self):
        # "autotest: script 'at 40; shot; exit'" contains " exit": it must not count as the exit step
        r = self.run_game(MENU, FakeGame(fixture('crash_after_start.txt'), {}, CRASH_STATUS))
        self.assertFalse(r['finished'])
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any('0xC0000005 first' in x for x in r['reasons']), r['reasons'])


class RotatedLogTests(SandboxCase):
    def test_rotated_during_the_run(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        self.sb.write_log(fixture('previous_run_ok.txt'), self.sb.segment(1))  # older, stale, also "passed"
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, rotate_at=(3,)))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertTrue(os.path.exists(self.sb.segment(2)))  # the stale segment moved on, unread
        self.assertIn('log rotated during the run: read 2 segments', self.summary(r))

    def test_rotated_and_shrank(self):
        before = fixture('previous_run_ok.txt') + filler(400)
        self.sb.write_log(before)
        size_before = os.path.getsize(self.layout.log)
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, rotate_at=(6,)))
        self.assertLess(os.path.getsize(self.layout.log), size_before)  # (the case under test)
        self.assertEqual(r['result'], 'OK', r['reasons'])

    def test_rotated_twice(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, rotate_at=(2, 7)))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertIn('read 3 segments', self.summary(r))

    def test_start_rotated_into_old_segment_but_run_did_not_finish(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        r = self.run_game(MENU, FakeGame(fixture('crash_after_start.txt'), {}, CRASH_STATUS, rotate_at=(1,)))
        self.assertEqual(r['result'], 'PROBLEM')

    def test_found_by_content_without_file_identity(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        mark = autotest.mark_log(self.layout.log)
        mark['ino'] = 0  # (a file system without file ids)
        FakeGame(fixture('menu_run.txt'), rotate_at=(4,))(self.layout, {}, 60, 't')
        log = autotest.read_run_log(mark)
        self.assertEqual((log['starts'], log['finished'], log['segments']), (1, True, 2))
        self.assertEqual(log['primaries'], ['frame_001802.png'])

    def test_no_log_before_the_launch(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, rotate_at=(5,)))
        self.assertEqual(r['result'], 'OK', r['reasons'])

    def test_old_log_deleted_during_the_run(self):
        self.sb.write_log(fixture('previous_run_ok.txt') + filler(50))
        self.sb.write_log(fixture('previous_run_ok.txt'), self.sb.segment(1))
        game = FakeGame(fixture('menu_run.txt'), MENU_FRAMES, before_write=lambda lay: os.remove(lay.log))
        r = self.run_game(MENU, game)
        self.assertEqual(r['result'], 'OK', r['reasons'])
        if sys.platform == 'win32':
            self.assertIn('is gone', self.summary(r))
        else:
            # (Linux reuses the deleted file's inode for the new log at once: the same file, shorter, as when
            # truncated in place. The game and this check run on Windows, whose file ids are not reused so.)
            self.assertRegex(self.summary(r), 'is gone|truncated')
        self.assertEqual(len(r['steps']), 3)  # this run's script echo, shot, exit; nothing from fable2.1.log

    def test_truncated_in_place(self):
        # spdlog truncates the file when a rotation rename fails: same file, smaller; the start line is lost
        self.sb.write_log(fixture('previous_run_ok.txt') + filler(50))

        def truncate(lay):
            open(lay.log, 'wb').close()
        tail = fixture('menu_run.txt').split('\n', 3)[3]  # (lines after the start, as if written after truncation)
        r = self.run_game(MENU, FakeGame(tail, MENU_FRAMES, before_write=truncate))
        self.assertEqual(r['result'], 'NOT_STARTED')
        self.assertIn('truncated', self.summary(r))


class ShotTests(SandboxCase):
    def setUp(self):
        super().setUp()
        self.sb.write_log(fixture('previous_run_ok.txt'))

    def test_zero_shots(self):
        text = ''.join(l for l in fixture('menu_run.txt').splitlines(keepends=True) if 'native renderer' not in l)
        r = self.run_game(MENU, FakeGame(text, {}))
        self.assertEqual((r['result'], r['exit_code']), ('PROBLEM', 1))
        self.assertIn('1 shot step(s) but 0 snapshot file(s) from this run', r['reasons'])

    def test_zero_shots_even_on_crash_on_close(self):
        text = ''.join(l for l in fixture('menu_run.txt').splitlines(keepends=True) if 'native renderer' not in l)
        r = self.run_game(MENU, FakeGame(text, {}, CRASH_STATUS))
        self.assertEqual(r['result'], 'PROBLEM')

    def test_fewer_pictures_than_shot_steps(self):
        text = fixture('load_run.txt')
        text = ''.join(l for l in text.splitlines(keepends=True) if 'frame_0049' not in l)
        frames = {k: v for k, v in LOAD_FRAMES.items() if '0043' in k}
        self.sb.make_save(self.layout.golden)
        r = self.run_game(LOAD, FakeGame(text, frames))
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertIn('2 shot step(s) but 1 snapshot(s) taken for them', r['reasons'])

    def test_black_frame(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), dict(MENU_FRAMES, **{'frame_001802.png': black})))
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any(x.startswith('shot step 1 (frame_001802.png): black') for x in r['reasons']), r['reasons'])
        self.assertEqual(r['shots'][0][1], 0.0)  # (noise alone, the old check, scores it as perfect)

    def test_flat_frame(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), dict(MENU_FRAMES, **{'frame_001802.png': grey})))
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any('flat' in x for x in r['reasons']))

    def test_scrambled_frame(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'),
                                         dict(MENU_FRAMES, **{'frame_001802.png': scrambled})))
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any('scrambled' in x for x in r['reasons']))

    def test_unreadable_frame(self):
        game = FakeGame(fixture('menu_run.txt'), MENU_FRAMES)

        def corrupt_after(layout, env, limit, tag):
            res = game(layout, env, limit, tag)
            with open(os.path.join(layout.snapshots, 'frame_001802.png'), 'wb') as f:
                f.write(b'\x89PNG\r\n\x1a\nbroken')
            return res
        r = self.run_game(MENU, corrupt_after)
        self.assertEqual(r['result'], 'PROBLEM')
        self.assertTrue(any('unreadable' in x for x in r['reasons']))

    def test_black_follow_up_frame_is_reported_not_judged(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), dict(MENU_FRAMES, **{'frame_001804.png': black})))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertIn('(follow-up frame: black', self.summary(r))

    def test_matched_by_frame_numbers_without_snapshot_lines(self):
        text = ''.join(l for l in fixture('load_run.txt').splitlines(keepends=True) if 'native renderer' not in l)
        self.sb.make_save(self.layout.golden)
        r = self.run_game(LOAD, FakeGame(text, LOAD_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual([s['step'] for s in r['shot_info']], [1, 0, 0, 2, 0, 0])
        self.assertEqual(autotest.frame_groups(['frame_000010.png', 'frame_000011.png', 'frame_000400.png']),
                         ['frame_000010.png', 'frame_000400.png'])


class ImageStatsTests(unittest.TestCase):
    def setUp(self):
        self.sb = Sandbox(exe=False, config=False)

    def tearDown(self):
        self.sb.close()

    def test_floors(self):
        floors = autotest.default_floors()
        cases = {'real': (real, 'ok'), 'black': (black, 'black'), 'grey': (grey, 'flat'),
                 'scrambled': (scrambled, 'scrambled')}
        for name, (pixel, want) in cases.items():
            p = os.path.join(self.sb.root, name + '.png')
            write_png(p, pixel)
            self.assertTrue(autotest.verdict(autotest.image_stats(p), floors).startswith(want), name)

    def test_stdlib_decoder_matches(self):
        for name, pixel in (('real', real), ('black', black), ('scrambled', scrambled)):
            for filters in ((0,), (1, 2, 3, 4)):
                p = os.path.join(self.sb.root, f'{name}{len(filters)}.png')
                write_png(p, pixel, filters=filters)
                fast, slow = autotest.image_stats(p), autotest.image_stats_stdlib(p)
                for k in ('luma', 'std', 'lit', 'noise'):
                    self.assertAlmostEqual(fast[k], slow[k], places=3, msg=f'{name} {filters} {k}')

    def test_not_a_png(self):
        p = os.path.join(self.sb.root, 'x.png')
        with open(p, 'wb') as f:
            f.write(b'nope')
        self.assertIsNone(autotest.image_stats(p))
        self.assertEqual(autotest.verdict(None, autotest.default_floors()), 'unreadable')


class ExitCrashTests(SandboxCase):
    def setUp(self):
        super().setUp()
        self.sb.write_log(fixture('previous_run_ok.txt'))

    def test_crash_on_close(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, CRASH_STATUS))
        self.assertEqual((r['result'], r['exit_code'], r['ok']), ('OK_EXIT_CRASH', 0, True), r['reasons'])
        self.assertEqual(r['exit_detail'], 'crashed while closing (exit code 0xC0000005)')
        self.assertIn('RESULT: OK_EXIT_CRASH (crashed while closing (exit code 0xC0000005))', self.summary(r))
        self.assertEqual(self.sb.ledger()[-1]['result'], 'OK_EXIT_CRASH')

    def test_crash_on_close_strict(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, CRASH_STATUS), strict_exit=True)
        self.assertEqual((r['result'], r['exit_code']), ('OK_EXIT_CRASH', 3))

    def test_hang_on_close(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES, HANG_STATUS))
        self.assertEqual(r['result'], 'OK_EXIT_CRASH')
        self.assertIn('did not close after the exit step', r['exit_detail'])

    def test_crash_on_close_does_not_hide_problems(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), dict(MENU_FRAMES, **{'frame_001802.png': black}),
                                         CRASH_STATUS))
        self.assertEqual(r['result'], 'PROBLEM')


class GoldenSaveTests(SandboxCase):
    def test_load_without_golden_save(self):
        game = FakeGame(fixture('load_run.txt'), LOAD_FRAMES)
        r = self.run_game(LOAD, game, scenario='load')
        self.assertEqual(game.calls, 0)
        self.assertEqual((r['result'], r['exit_code'], r['ok']), ('SETUP_ERROR', 2, False))
        self.assertTrue(any('--make-golden' in x for x in r['reasons']))
        self.assertEqual(self.sb.ledger()[-1]['result'], 'SETUP_ERROR')

    def test_bisect_style_call_still_needs_it(self):
        game = FakeGame(fixture('load_run.txt'), LOAD_FRAMES)
        r = autotest.run(LOAD, '', 'pass1', 150, quiet=True, layout=self.layout, launcher=game)  # (no scenario)
        self.assertEqual((r['result'], game.calls), ('SETUP_ERROR', 0))

    def test_play_without_golden_save(self):
        r = self.run_game(autotest.SCENARIOS['play'][0], FakeGame())
        self.assertEqual(r['result'], 'SETUP_ERROR')

    def test_require_golden_for_custom_script(self):
        r = self.run_game(NO_EXIT, FakeGame(), require_golden=True)
        self.assertEqual(r['result'], 'SETUP_ERROR')

    def test_menu_runs_without_it(self):
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertFalse(self.sb.ledger()[-1]['golden_save']['restored'])

    def test_golden_save_restored_before_launch(self):
        self.sb.make_save(self.layout.golden, b'golden')
        self.sb.make_save(self.layout.saves, b'played on', name='stray.bin')
        game = FakeGame(fixture('load_run.txt'), LOAD_FRAMES)
        r = self.run_game(LOAD, game)
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(game.saves_seen, ['mainsave.bin'])
        self.assertTrue(self.sb.ledger()[-1]['golden_save']['restored'])
        self.assertEqual(tree(self.layout.saves), {'Hero000/stray.bin': b'played on'})  # the user's slot is back

    def test_make_golden(self):
        never = lambda: False  # noqa: E731
        self.assertEqual(autotest.make_golden(self.layout, is_running=never, quiet=True), 2)  # no save yet
        self.sb.make_save(self.layout.saves, b'')
        self.assertEqual(autotest.make_golden(self.layout, is_running=never, quiet=True), 2)  # empty file
        self.sb.make_save(self.layout.saves, b'hero')
        self.assertEqual(autotest.make_golden(self.layout, is_running=lambda: True, quiet=True), 2)  # game running
        self.assertEqual(autotest.make_golden(self.layout, is_running=never, quiet=True), 0)
        with open(os.path.join(self.layout.golden, 'Hero000', 'mainsave.bin'), 'rb') as f:
            self.assertEqual(f.read(), b'hero')
        with open(self.layout.golden + '.json', encoding='utf-8') as f:
            self.assertEqual(json.load(f)['sha256'], autotest.tree_sha256(self.layout.golden))
        self.assertEqual(autotest.make_golden(self.layout, is_running=never, quiet=True), 2)  # exists
        self.sb.make_save(self.layout.saves, b'hero 2')
        self.assertEqual(autotest.make_golden(self.layout, force=True, is_running=never, quiet=True), 0)
        old = sorted(d for d in os.listdir(self.layout.runs) if d.startswith('save_golden.old_'))
        self.assertEqual(len(old), 2, old)  # the old save and its manifest
        self.assertEqual(old[1], old[0] + '.json')
        self.assertEqual(tree(os.path.join(self.layout.runs, old[0])), {'Hero000/mainsave.bin': b'hero'})
        with open(os.path.join(self.layout.golden, 'Hero000', 'mainsave.bin'), 'rb') as f:
            self.assertEqual(f.read(), b'hero 2')
        with open(self.layout.golden + '.json', encoding='utf-8') as f:
            self.assertEqual(json.load(f)['sha256'], autotest.tree_sha256(self.layout.golden))


def tree(where):
    """{relative path: content} of the files under `where` ({} when it does not exist)."""
    out = {}
    for base, _, files in os.walk(where):
        for name in files:
            p = os.path.join(base, name)
            with open(p, 'rb') as f:
                out[os.path.relpath(p, where).replace('\\', '/')] = f.read()
    return out


class SaveSlotTests(SandboxCase):
    """The user's own save slot (the one they play in) is moved aside for a run and moved back after it."""
    never = staticmethod(lambda: False)

    def golden(self, content=b'golden'):
        self.sb.make_save(self.layout.golden, content)

    def runs_entries(self, prefix):
        return sorted(d for d in os.listdir(self.layout.runs) if d.startswith(prefix))

    def test_played_on_after_the_golden_save(self):
        # (review 2026-10-10: a menu check after more play used to leave the slot at the golden save)
        self.sb.make_save(self.layout.saves, b'progress at hour 1')
        self.assertEqual(autotest.make_golden(self.layout, is_running=self.never, quiet=True), 0)
        self.sb.make_save(self.layout.saves, b'progress at hour 9')
        self.sb.make_save(self.layout.saves, b'x', name='chaptersave.bin')
        mine = tree(self.layout.saves)
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(tree(self.layout.saves), mine)
        self.assertFalse(os.path.exists(self.layout.slot_stash))
        rec = self.sb.ledger()[-1]['save_slot']
        self.assertEqual((rec['moved_to'], rec['put_back'], rec['error']), (self.layout.slot_stash, True, None))
        self.assertIn(f'yours was kept in {self.layout.slot_stash} and moved back', self.summary(r))

    def test_what_the_game_saved_during_the_run_is_discarded(self):
        self.golden()
        self.sb.make_save(self.layout.saves, b'mine')

        def autosave(lay):
            self.sb.make_save(lay.saves, b'test progress', name='autosave.bin')
        game = FakeGame(fixture('load_run.txt'), LOAD_FRAMES, before_write=autosave)
        r = self.run_game(LOAD, game)
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        self.assertEqual(self.runs_entries('save_slot_after_autotest'), [])  # (the test's slot is deleted)
        self.assertEqual(tree(self.layout.golden), {'Hero000/mainsave.bin': b'golden'})

    def test_no_slot_before_the_run(self):
        self.golden()
        r = self.run_game(LOAD, FakeGame(fixture('load_run.txt'), LOAD_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertFalse(os.path.exists(self.layout.saves))
        self.assertEqual((r['save_slot']['moved_to'], r['save_slot']['put_back']), (None, True))

    def test_slot_not_touched_without_golden_save(self):
        self.sb.make_save(self.layout.saves, b'mine')
        game = FakeGame(fixture('menu_run.txt'), MENU_FRAMES)
        r = self.run_game(MENU, game)
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(r['save_slot']['put_back'], None)
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        self.assertFalse(os.path.exists(self.layout.runs))
        self.assertIn('save slot: not touched (no golden save)', self.summary(r))

    def test_moved_back_after_ctrl_c(self):
        self.golden()
        self.sb.make_save(self.layout.saves, b'mine')
        seen = []

        def interrupted(layout, env, limit, tag):
            seen.append(tree(layout.saves))
            raise KeyboardInterrupt
        with self.assertRaises(KeyboardInterrupt):
            self.run_game(LOAD, interrupted)
        self.assertEqual(seen, [{'Hero000/mainsave.bin': b'golden'}])
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        self.assertFalse(os.path.exists(self.layout.slot_stash))

    def test_golden_copy_fails_is_a_setup_error(self):
        self.golden()
        self.sb.make_save(self.layout.saves, b'mine')
        game = FakeGame(fixture('load_run.txt'), LOAD_FRAMES)
        with mock.patch.object(autotest.shutil, 'copytree', side_effect=PermissionError('locked')):
            r = self.run_game(LOAD, game)
        self.assertEqual((r['result'], game.calls), ('SETUP_ERROR', 0))
        self.assertTrue(any('the save slot was left as it was' in x for x in r['reasons']), r['reasons'])
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        self.assertFalse(os.path.exists(self.layout.slot_stash))

    def test_not_moved_back_is_reported_then_recovered(self):
        self.golden()
        self.sb.make_save(self.layout.saves, b'mine')
        err = io.StringIO()
        with mock.patch.object(autotest, 'put_back_slot', side_effect=PermissionError('locked')), \
                contextlib.redirect_stderr(err):
            r = self.run_game(LOAD, FakeGame(fixture('load_run.txt'), LOAD_FRAMES), tag='a')
        self.assertEqual(r['result'], 'OK', r['reasons'])  # (a verdict about the game, not about the slot)
        self.assertEqual((r['save_slot']['put_back'], r['save_slot']['error']), (False, 'locked'))
        self.assertEqual(self.sb.ledger()[-1]['save_slot']['put_back'], False)
        self.assertIn('YOURS WAS NOT MOVED BACK', self.summary(r))
        self.assertIn(self.layout.slot_stash, err.getvalue())
        self.assertEqual(tree(self.layout.slot_stash), {'Hero000/mainsave.bin': b'mine'})
        # the next run moves it back first and keeps what it found in the slot
        with contextlib.redirect_stderr(io.StringIO()):
            r = self.run_game(LOAD, FakeGame(fixture('load_run.txt'), LOAD_FRAMES), tag='b')
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(len(r['save_slot']['recovered']), 2, r['save_slot'])
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        found = self.runs_entries('save_slot_found_')
        self.assertEqual(len(found), 1)
        self.assertEqual(tree(os.path.join(self.layout.runs, found[0])), {'Hero000/mainsave.bin': b'golden'})

    def test_killed_run_recovered_without_golden_save(self):
        # (the process was killed during a run; the golden save was deleted since)
        self.sb.make_save(self.layout.slot_stash, b'mine')
        self.sb.make_save(self.layout.saves, b'test leftover')
        with contextlib.redirect_stderr(io.StringIO()):
            r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES))
        self.assertEqual(r['result'], 'OK', r['reasons'])
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'mine'})
        self.assertEqual(len(self.runs_entries('save_slot_found_')), 1)

    def test_make_golden_after_a_killed_run_uses_the_users_slot(self):
        self.golden(b'old golden')
        self.sb.make_save(self.layout.slot_stash, b'hour 9')
        self.sb.make_save(self.layout.saves, b'old golden')  # (the slot the killed run started from)
        self.assertEqual(autotest.make_golden(self.layout, force=True, is_running=self.never, quiet=True), 0)
        self.assertEqual(tree(self.layout.golden), {'Hero000/mainsave.bin': b'hour 9'})
        self.assertEqual(tree(self.layout.saves), {'Hero000/mainsave.bin': b'hour 9'})
        self.assertFalse(os.path.exists(self.layout.slot_stash))

    def make_first_golden(self):
        self.sb.make_save(self.layout.saves, b'hero')
        self.assertEqual(autotest.make_golden(self.layout, is_running=self.never, quiet=True), 0)
        with open(self.layout.golden + '.json', 'rb') as f:
            manifest = f.read()
        self.sb.make_save(self.layout.saves, b'hero 2')
        return manifest

    def assert_first_golden_kept(self, manifest):
        self.assertEqual(tree(self.layout.golden), {'Hero000/mainsave.bin': b'hero'})
        with open(self.layout.golden + '.json', 'rb') as f:
            self.assertEqual(f.read(), manifest)
        self.assertEqual(self.runs_entries('save_golden.'), ['save_golden.json'])  # (no .old_, no .tmp left)

    def test_make_golden_force_copy_fails(self):
        # (review 2026-10-10: the old golden save used to be renamed away before the copy)
        manifest = self.make_first_golden()
        with mock.patch.object(autotest.shutil, 'copytree', side_effect=PermissionError('locked')):
            self.assertEqual(autotest.make_golden(self.layout, force=True, is_running=self.never, quiet=True), 2)
        self.assert_first_golden_kept(manifest)
        self.assertTrue(autotest.has_golden(self.layout))

    def test_make_golden_force_last_rename_fails(self):
        manifest = self.make_first_golden()
        real = os.replace

        def replace(a, b):
            if os.path.basename(a) == 'save_golden.json.tmp':
                raise PermissionError('locked')
            return real(a, b)
        with mock.patch.object(autotest.os, 'replace', side_effect=replace), \
                mock.patch.object(autotest, 'RETRY_WAIT', 0):
            self.assertEqual(autotest.make_golden(self.layout, force=True, is_running=self.never, quiet=True), 2)
        self.assert_first_golden_kept(manifest)


class ByScenario:
    """One FakeGame per scenario, chosen by the script the run passes to the game."""

    def __init__(self, games):
        self.games, self.order = games, []

    def __call__(self, layout, env, limit, tag):
        name = autotest.scenario_of(env['F2_AUTOTEST'])
        self.order.append(name)
        return self.games[name](layout, env, limit, tag)


class SuiteTests(SandboxCase):
    def suite(self, games, **kw):
        with contextlib.redirect_stdout(io.StringIO()) as out:
            code, done = autotest.run_suite(autotest.SUITE, 'S', quiet=True, layout=self.layout, launcher=games, **kw)
        return code, done, out.getvalue()

    def test_stops_at_first_failure(self):
        self.sb.make_save(self.layout.golden)
        games = ByScenario({'menu': FakeGame(fixture('menu_run.txt'), MENU_FRAMES),
                            'load': FakeGame(fixture('load_run.txt'), dict(LOAD_FRAMES, **{'frame_004385.png': black})),
                            'play': FakeGame()})
        code, done, out = self.suite(games)
        self.assertEqual(code, 1)
        self.assertEqual(games.order, ['menu', 'load'])
        self.assertIn('SUITE S: menu OK, load PROBLEM; not run: play', out)
        self.assertEqual([(l['scenario'], l['suite'], l['tag']) for l in self.sb.ledger()],
                         [('menu', 'S', 'S_menu'), ('load', 'S', 'S_load')])

    def test_refused_up_front_without_golden_save(self):
        games = ByScenario({'menu': FakeGame(fixture('menu_run.txt'), MENU_FRAMES)})
        code, done, out = self.suite(games)
        self.assertEqual((code, games.order), (2, []))
        self.assertEqual([l['result'] for l in self.sb.ledger()], ['SETUP_ERROR'])

    def test_exit_crashes_counted(self):
        self.sb.make_save(self.layout.golden)
        games = ByScenario({'menu': FakeGame(fixture('menu_run.txt'), MENU_FRAMES, CRASH_STATUS),
                            'load': FakeGame(fixture('load_run.txt'), LOAD_FRAMES),
                            'play': FakeGame(self.play_log(), {f'frame_{1000 * k:06}.png': real for k in range(1, 11)})})
        code, done, out = self.suite(games)
        self.assertEqual(code, 0, out)
        self.assertIn('teardown crashes: 1', out)

    def test_exit_crash_stops_strict_suite(self):
        self.sb.make_save(self.layout.golden)
        games = ByScenario({'menu': FakeGame(fixture('menu_run.txt'), MENU_FRAMES, CRASH_STATUS)})
        code, done, out = self.suite(games, strict_exit=True)
        self.assertEqual((code, games.order), (3, ['menu']))

    @staticmethod
    def play_log():
        lines = ['[2026-10-10 10:00:00.000] [info] [core] [t1] Fable2 starting\n']
        for k in range(1, 11):
            lines.append(f'[2026-10-10 10:00:{k:02}.000] [info] [core] [t2] autotest: {k * 10}.0 s shot\n')
            lines.append(f'[2026-10-10 10:00:{k:02}.100] [info] [core] [t3] native renderer: snapshot '
                         f'{{snapdir}}\\frame_{1000 * k:06}.png\n')
        lines.append('[2026-10-10 10:01:00.000] [info] [core] [t2] autotest: 200.0 s exit\n')
        return ''.join(lines)


class LedgerTests(SandboxCase):
    def test_fields(self):
        self.sb.write_log(fixture('previous_run_ok.txt'))
        r = self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES), scenario='menu')
        rec = self.sb.ledger()[-1]
        with open(self.layout.exe, 'rb') as f:
            exe_sha = hashlib.sha256(f.read()).hexdigest()
        with open(self.layout.config, 'rb') as f:
            cfg_sha = hashlib.sha256(f.read()).hexdigest()
        self.assertEqual(rec['result'], r['result'])
        self.assertEqual(rec['scenario'], 'menu')
        self.assertEqual(rec['exe'], {'path': self.layout.exe, 'sha256': exe_sha})
        self.assertEqual(rec['config'], {'path': self.layout.config, 'sha256': cfg_sha})
        self.assertEqual(rec['shots'], {'expected': 1, 'files': 3, 'taken': 1, 'passing': 1})
        self.assertEqual(rec['git'], {})
        for key in ('time', 'tag', 'exit_code', 'exit_detail', 'script', 'cvars', 'wall_s', 'golden_save', 'log',
                    'dir'):
            self.assertIn(key, rec)

    def test_exe_hash_follows_a_rebuild(self):
        self.run_game(MENU, FakeGame(), tag='a')
        with open(self.layout.exe, 'ab') as f:
            f.write(b'rebuilt')
        self.run_game(MENU, FakeGame(), tag='b')
        with open(self.layout.exe, 'rb') as f:
            now = hashlib.sha256(f.read()).hexdigest()
        first, second = self.sb.ledger()
        self.assertNotEqual(first['exe']['sha256'], second['exe']['sha256'])
        self.assertEqual(second['exe']['sha256'], now)
        cache = os.path.join(os.path.dirname(self.layout.ledger), 'sha256_cache.json')
        with open(cache, encoding='utf-8') as f:
            self.assertIn(now, json.load(f).values())

    def test_one_line_per_run(self):
        self.run_game(MENU, FakeGame(fixture('menu_run.txt'), MENU_FRAMES), tag='a')
        self.run_game(MENU, FakeGame(), tag='b')
        self.assertEqual([l['tag'] for l in self.sb.ledger()], ['a', 'b'])


@unittest.skipUnless(shutil.which('git'), 'git not found')
class GitStateTests(unittest.TestCase):
    def test_rev_and_dirty(self):
        sb = Sandbox(exe=False, config=False)
        try:
            repo = os.path.join(sb.root, 'repo')
            os.makedirs(repo)
            self.assertIsNone(autotest.git_state(repo))  # (no .git of its own: never a parent's revision)

            def git(*a):
                subprocess.run(['git', '-C', repo, '-c', 'user.name=t', '-c', 'user.email=t@example.invalid',
                                '-c', 'commit.gpgsign=false', *a], check=True, capture_output=True)
            git('init', '-q')
            with open(os.path.join(repo, 'a.txt'), 'w') as f:
                f.write('1')
            git('add', 'a.txt')
            git('commit', '-q', '-m', 'x')
            st = autotest.git_state(repo)
            self.assertEqual(len(st['rev']), 40)
            self.assertFalse(st['dirty'])
            with open(os.path.join(repo, 'untracked.txt'), 'w') as f:
                f.write('u')
            self.assertFalse(autotest.git_state(repo)['dirty'])  # untracked files do not count
            with open(os.path.join(repo, 'a.txt'), 'w') as f:
                f.write('2')
            self.assertTrue(autotest.git_state(repo)['dirty'])
        finally:
            sb.close()

    def test_status_leaves_the_index_alone(self):
        # (review 2026-10-10: a plain `git status` refreshes .git/index under index.lock; a git add/commit run at
        # the same moment by the user or another tool then fails with "index.lock: File exists")
        sb = Sandbox(exe=False, config=False)
        try:
            repo = os.path.join(sb.root, 'repo')
            os.makedirs(repo)

            def git(*a):
                return subprocess.run(['git', '-C', repo, '-c', 'user.name=t', '-c', 'user.email=t@example.invalid',
                                       '-c', 'commit.gpgsign=false', *a], check=True, capture_output=True)
            git('init', '-q')
            p = os.path.join(repo, 'a.txt')
            with open(p, 'w') as f:
                f.write('1')
            git('add', 'a.txt')
            git('commit', '-q', '-m', 'x')
            st = os.stat(p)
            os.utime(p, ns=(st.st_atime_ns, st.st_mtime_ns - 100 * 10**9))  # same content, stale stat data
            index = os.path.join(repo, '.git', 'index')

            def index_state():
                with open(index, 'rb') as f:
                    return os.stat(index).st_mtime_ns, f.read()
            before = index_state()
            self.assertEqual(autotest.git_state(repo)['dirty'], False)
            self.assertEqual(index_state(), before)
            git('status', '--porcelain')
            if index_state() == before:
                self.skipTest('this git does not refresh the index on status: nothing to compare against')
        finally:
            sb.close()


class CommandLineTests(unittest.TestCase):
    def test_needs_a_mode(self):
        with contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit) as e:
            autotest.main([])
        self.assertEqual(e.exception.code, 2)

    def test_unknown_suite_scenario(self):
        with contextlib.redirect_stderr(io.StringIO()), self.assertRaises(SystemExit) as e:
            autotest.main(['--suite', 'menu,bogus'])
        self.assertEqual(e.exception.code, 2)


POWERSHELL = shutil.which('powershell') or shutil.which('pwsh')
FULL_CYCLE_CHECK = r'''
param([string]$Path, [string]$Py)
$tokens = $null; $errors = $null
$ast = [System.Management.Automation.Language.Parser]::ParseFile($Path, [ref]$tokens, [ref]$errors)
if ($errors.Count) { foreach ($e in $errors) { "PARSE ERROR: $($e.Message)" }; exit 1 }
$calls = $ast.FindAll({ param($n) $n -is [System.Management.Automation.Language.CommandAst] -and
    $n.Extent.Text -match 'autotest\.py' -and $n.GetCommandName() -ne 'Step' }, $true)
$unchecked = 0
foreach ($c in $calls) {
    $p = $c.Parent; $inStep = $false
    while ($p) {
        if ($p -is [System.Management.Automation.Language.CommandAst] -and $p.GetCommandName() -eq 'Step') { $inStep = $true; break }
        $p = $p.Parent
    }
    if (-not $inStep) { "UNCHECKED: $($c.Extent.Text)"; $unchecked++ }
}
"CALLS $($calls.Count) UNCHECKED $unchecked"
# the script's own Step function must stop on a failing command
$fn = $ast.Find({ param($n) $n -is [System.Management.Automation.Language.FunctionDefinitionAst] -and $n.Name -eq 'Step' }, $true)
Invoke-Expression $fn.Extent.Text
try { Step 'game check: fake' { & $Py -c 'import sys; sys.exit(1)' } *> $null; 'STEP DID NOT STOP' } catch { "STEP STOPPED: $($_.Exception.Message)" }
'''


@unittest.skipUnless(POWERSHELL, 'PowerShell not found')
class FullCycleTests(unittest.TestCase):
    def test_game_checks_stop_the_cycle(self):
        sb = Sandbox(exe=False, config=False)
        try:
            check = os.path.join(sb.root, 'check.ps1')
            with open(check, 'w', encoding='utf-8') as f:
                f.write(FULL_CYCLE_CHECK)
            r = subprocess.run([POWERSHELL, '-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File',
                                check, '-Path', os.path.join(TOOLS, 'lift', 'full_cycle.ps1'), '-Py', sys.executable],
                               capture_output=True, text=True, timeout=90)
        finally:
            sb.close()
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
        self.assertRegex(r.stdout, r'CALLS [1-9]\d* UNCHECKED 0')
        self.assertIn('STEP STOPPED: game check: fake failed (exit 1)', r.stdout)


if __name__ == '__main__':
    unittest.main()
