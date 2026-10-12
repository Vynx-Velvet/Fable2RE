#!/usr/bin/env python3
"""Builds this example mod's script from your own game files.

Writes gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua (next to this file): the
game's postscriptsloaded.lua decompiled to Lua source, followed by modtest.lua. The decompile is
taken from gamescripts.bnk, which holds the same compiled code as gamescripts_r.bnk plus debug
information (so it decompiles with the original local names); the mod goes under gamescripts_r/
because data/startup.vfsconfig mounts gamescripts_r.bnk and never gamescripts.bnk.

The output is derived from the game and stays on your machine: this folder's .gitignore keeps
gamescripts_r/ out of `git add`, and tools/validate_commit.py, run before a commit, fails if it is
staged anyway. Needs Java and tools/thirdparty/unluac.jar (see tools/bnk.py).

Usage: python mods/_Example_ModLoadTest/make_example.py [--game <folder that contains data/>] [--out <file>]
"""
import argparse
import os
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(ROOT, 'tools'))
import bnk  # noqa: E402

SCRIPT = 'scripts\\miscellaneous\\saveload\\postscriptsloaded.lua'
DEFAULT_GAME = os.path.join(ROOT, 'Fable2Recomp', 'out', 'build', 'win-amd64-release', 'assets', 'game')


def source_bank(data):
    """gamescripts.bnk (debug names) if present; else the unmodified gamescripts_r.bnk."""
    for name in ('gamescripts.bnk', 'gamescripts_r.bnk.orig', 'gamescripts_r.bnk'):
        path = os.path.join(data, name)
        if os.path.isfile(path):
            return path
    raise FileNotFoundError(f'no gamescripts.bnk or gamescripts_r.bnk in {data}')


def main(argv):
    parser = argparse.ArgumentParser(description=__doc__.split('\n', 1)[0])
    parser.add_argument('--game', default=DEFAULT_GAME, help='game folder that contains data/')
    parser.add_argument('--out', default=os.path.join(HERE, 'gamescripts_r', *SCRIPT.split('\\')))
    args = parser.parse_args(argv)
    try:
        bank_path = source_bank(os.path.join(args.game, 'data'))
        bank = bnk.Bank(bank_path)
        entry = next((e for e in bank.files if e[0].lower() == SCRIPT), None)
        if entry is None:
            raise FileNotFoundError(f'{bank_path} has no {SCRIPT}')
        if not os.path.isfile(bnk.UNLUAC):
            raise FileNotFoundError(f'{bnk.UNLUAC} is missing (unluac, needed to decompile)')
        java = bnk.find_java()
    except (FileNotFoundError, bnk.UnsupportedBank) as e:
        print(f'error: {e}', file=sys.stderr)
        return 1
    with tempfile.TemporaryDirectory() as tmp:
        chunk = os.path.join(tmp, 'postscriptsloaded.lua')
        with open(chunk, 'wb') as f:
            f.write(bank.read(entry))
        r = subprocess.run([java, '-jar', bnk.UNLUAC, chunk], capture_output=True)
    if r.returncode != 0 or not r.stdout:
        print(f'error: unluac failed: {r.stderr.decode("utf-8", "replace").strip()}', file=sys.stderr)
        return 1
    with open(os.path.join(HERE, 'modtest.lua'), 'rb') as f:
        test = f.read()
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, 'wb') as f:
        f.write(r.stdout.replace(b'\r\n', b'\n') + test)
    print(f'wrote {args.out} (decompiled from {bank_path} + modtest.lua)')
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
