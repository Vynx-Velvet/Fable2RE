"""The project's changes to the ReXGlue SDK, kept as one patch over a public release.

`rexglue-sdk/` is a submodule pinned to the public ReXGlue release the project builds on (BASE below);
`patches/rexglue-sdk.patch` holds every change the project made to it (source text only). tools/setup_all.ps1
applies it before building the SDK.

    python tools/sdk_patch.py status    is the checkout at BASE, is the patch applied, are there changes it lacks
    python tools/sdk_patch.py apply     apply the patch to the working tree (nothing to do when already applied)
    python tools/sdk_patch.py export    rewrite the patch from the working tree (after changing the SDK)

Exit codes: 0 ok; 1 the checkout is not in a state the command can work with (the message says what to do).
"""
import argparse
import os
import subprocess
import sys
import tempfile

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
SDK = os.path.join(ROOT, 'rexglue-sdk')
PATCH = os.path.join(ROOT, 'patches', 'rexglue-sdk.patch')
BASE = 'e8ce24fa73cd7c1ede80262c06f34893b7963dbe'   # ReXGlue "Release v0.8.0" (2026-05-16), public


def git(*args, env=None, check=True, raw=False):
    # raw: the output as bytes (a patch is UTF-8 text; decoding with the console code page would mangle it)
    r = subprocess.run(['git', '-C', SDK, *args], capture_output=True, text=not raw, env=env)
    if check and r.returncode:
        err = r.stderr.decode('utf-8', 'replace') if raw else r.stderr
        sys.exit(f'sdk_patch: git {" ".join(args)} failed: {err.strip()}')
    return r


def head():
    r = git('rev-parse', 'HEAD', check=False)
    return r.stdout.strip() if r.returncode == 0 else None


def applied():
    """True: the working tree has the patch; False: it applies cleanly (not applied); None: neither."""
    if git('apply', '--reverse', '--check', PATCH, check=False).returncode == 0:
        return True
    if git('apply', '--check', PATCH, check=False).returncode == 0:
        return False
    return None


def working_diff():
    """The working tree (tracked and new files, .gitignore respected) as a patch against BASE. Uses a temporary
    index, so the checkout's own index is not touched."""
    fd, index = tempfile.mkstemp(prefix='sdk_patch_index_')
    os.close(fd)
    os.remove(index)
    env = dict(os.environ, GIT_INDEX_FILE=index)
    try:
        git('read-tree', BASE, env=env)
        git('add', '-A', '--', '.', env=env)
        return git('diff', '--cached', '--binary', '--full-index', BASE, env=env, raw=True).stdout
    finally:
        if os.path.exists(index):
            os.remove(index)


def need_base():
    if not os.path.isdir(SDK) or not os.path.exists(os.path.join(SDK, '.git')):
        sys.exit('sdk_patch: rexglue-sdk/ is not checked out: git submodule update --init --recursive rexglue-sdk')
    h = head()
    if h != BASE:
        sys.exit(f'sdk_patch: rexglue-sdk is at {str(h)[:12]}, the patch is made for {BASE[:12]} (ReXGlue v0.8.0): '
                 f'git submodule update --init --recursive rexglue-sdk (this discards changes the patch lacks: run '
                 f'"python tools/sdk_patch.py export" first if you changed the SDK)')


def cmd_status(_):
    need_base()
    state = applied()
    print(f'rexglue-sdk at {BASE[:12]} (ReXGlue v0.8.0); patch: '
          + {True: 'applied', False: 'not applied', None: 'neither applied nor applicable'}[state])
    if state:
        with open(PATCH, 'rb') as f:
            same = f.read() == working_diff()
        print('working tree matches the patch' if same else
              'the working tree has SDK changes the patch lacks: python tools/sdk_patch.py export')
    return 0 if state else 1


def cmd_apply(_):
    need_base()
    state = applied()
    if state:
        print('sdk_patch: already applied')
        return 0
    if state is None:
        sys.exit('sdk_patch: the patch does not apply to this checkout (local changes in rexglue-sdk?): '
                 'git -C rexglue-sdk status')
    git('apply', '--whitespace=nowarn', PATCH)
    print(f'sdk_patch: applied {os.path.relpath(PATCH, ROOT)} to rexglue-sdk')
    return 0


def cmd_export(_):
    need_base()
    text = working_diff()
    with open(PATCH, 'wb') as f:
        f.write(text)
    files = text.count(b'\ndiff --git ') + text.startswith(b'diff --git ')
    print(f'sdk_patch: wrote {os.path.relpath(PATCH, ROOT)}: {files} files, {len(text) // 1024} KB')
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    for name in ('status', 'apply', 'export'):
        sub.add_parser(name)
    a = ap.parse_args()
    sys.exit({'status': cmd_status, 'apply': cmd_apply, 'export': cmd_export}[a.cmd](a))


if __name__ == '__main__':
    main()
