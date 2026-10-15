r"""API keys for the tools that call a hosted model, stored once per user account.

    python tools/api_keys.py set deepseek               paste the key at the prompt (it is not shown)
    python tools/api_keys.py set deepseek --clipboard   take it from the clipboard instead
    python tools/api_keys.py list                       the stored keys (last four characters only)
    python tools/api_keys.py remove deepseek
    python tools/api_keys.py where                      the file that holds them

tools/rewrite/run_api.py and tools/naming/run_local.py take the key for a provider from this store, so a new
terminal needs nothing set; without a stored key, from the environment variable <NAME>_API_KEY
(DEEPSEEK_API_KEY, OPENROUTER_API_KEY ...); with --api-key-env VAR, from that variable first. They pick the name
from the URL (api.deepseek.com: deepseek, openrouter.ai: openrouter) or from --key NAME.

The file is in the user's settings folder, outside the repository, so no commit can pick it up:
%APPDATA%\Fable2RE\api_keys.json on Windows, ~/.config/fable2re/api_keys.json elsewhere (the environment
variable FABLE2RE_KEY_STORE names another file). On Windows every key is encrypted for the signed-in account
(DPAPI): the file is of no use to another account or on another machine. Elsewhere the file is plain text that
only its owner may read (mode 600), like other command-line tools' tokens.
"""
import argparse
import base64
import getpass
import json
import os
import re
import subprocess
import sys
import time

NAME = re.compile(r'^[a-z0-9][a-z0-9-]{0,39}$')
HOSTS = {'api.deepseek.com': 'deepseek', 'openrouter.ai': 'openrouter'}
_ENTROPY = b'Fable2RE API key'


class KeyStoreError(Exception):
    pass


def store_path():
    p = os.environ.get('FABLE2RE_KEY_STORE', '').strip()
    if p:
        return p
    if os.name == 'nt':
        base = os.environ.get('APPDATA') or os.path.join(os.path.expanduser('~'), 'AppData', 'Roaming')
        return os.path.join(base, 'Fable2RE', 'api_keys.json')
    base = os.environ.get('XDG_CONFIG_HOME') or os.path.join(os.path.expanduser('~'), '.config')
    return os.path.join(base, 'fable2re', 'api_keys.json')


def env_var(name):
    """The environment variable that overrides a stored key: deepseek -> DEEPSEEK_API_KEY."""
    return name.upper().replace('-', '_') + '_API_KEY'


def name_of_env(var):
    """The stored key an environment variable stands for: DEEPSEEK_API_KEY -> deepseek."""
    v = var.strip().upper()
    if v.endswith('_API_KEY'):
        v = v[:-len('_API_KEY')]
    return v.lower().replace('_', '-') if v else ''


def name_for_url(url):
    """The key name of a known provider's URL, or None."""
    host = re.sub(r'^https?://', '', url.strip()).split('/')[0].split(':')[0].lower()
    for h, n in HOSTS.items():
        if host == h or host.endswith('.' + h):
            return n
    return None


def check_key(key):
    """Why a pasted text cannot be a key, or None. Never quotes the text."""
    if not key:
        return 'nothing was entered'
    if any(c.isspace() for c in key):
        return 'it contains spaces or line breaks'
    if len(key) < 16:
        return f'it is only {len(key)} characters long'
    if not all(33 <= ord(c) < 127 for c in key):
        return 'it contains characters an API key does not have'
    return None


# ---- encryption (Windows: DPAPI, bound to the signed-in account) --------------------------------------------------

def _dpapi(data, protect):
    import ctypes
    from ctypes import wintypes

    class Blob(ctypes.Structure):
        _fields_ = [('cbData', wintypes.DWORD), ('pbData', ctypes.POINTER(ctypes.c_ubyte))]

    def blob(b):
        buf = (ctypes.c_ubyte * len(b)).from_buffer_copy(b)
        return Blob(len(b), ctypes.cast(buf, ctypes.POINTER(ctypes.c_ubyte))), buf

    crypt32 = ctypes.WinDLL('crypt32', use_last_error=True)
    kernel32 = ctypes.WinDLL('kernel32', use_last_error=True)
    fn = crypt32.CryptProtectData if protect else crypt32.CryptUnprotectData
    fn.argtypes = [ctypes.POINTER(Blob), ctypes.c_void_p, ctypes.POINTER(Blob), ctypes.c_void_p, ctypes.c_void_p,
                   wintypes.DWORD, ctypes.POINTER(Blob)]
    fn.restype = wintypes.BOOL
    kernel32.LocalFree.argtypes = [ctypes.c_void_p]
    kernel32.LocalFree.restype = ctypes.c_void_p
    inp, _keep1 = blob(data)
    ent, _keep2 = blob(_ENTROPY)
    out = Blob()
    if not fn(ctypes.byref(inp), None, ctypes.byref(ent), None, None, 1, ctypes.byref(out)):  # (1: no UI)
        raise KeyStoreError(f'Windows could not {"encrypt" if protect else "decrypt"} the key '
                            f'(error {ctypes.get_last_error()})')
    try:
        return ctypes.string_at(out.pbData, out.cbData)
    finally:
        kernel32.LocalFree(ctypes.cast(out.pbData, ctypes.c_void_p))


def _seal(key):
    if os.name == 'nt':
        return {'dpapi': base64.b64encode(_dpapi(key.encode('ascii'), True)).decode('ascii')}
    return {'plain': key}


def _open(entry, name):
    if 'dpapi' in entry:
        if os.name != 'nt':
            raise KeyStoreError(f'the {name} key was stored on Windows; store it again here')
        try:
            return _dpapi(base64.b64decode(entry['dpapi']), False).decode('ascii')
        except KeyStoreError:
            raise KeyStoreError(f'the stored {name} key belongs to another Windows account or machine; '
                                f'store it again: python tools/api_keys.py set {name}')
    return entry.get('plain', '')


# ---- the file -----------------------------------------------------------------------------------------------------

def load(path=None):
    path = path or store_path()
    if not os.path.isfile(path):
        return {'version': 1, 'keys': {}}
    try:
        with open(path, encoding='utf-8') as f:
            doc = json.load(f)
    except (OSError, ValueError) as e:
        raise KeyStoreError(f'{path} cannot be read ({e.__class__.__name__}); remove it and store the keys again')
    doc.setdefault('keys', {})
    return doc


def save(doc, path=None):
    path = path or store_path()
    folder = os.path.dirname(os.path.abspath(path))
    os.makedirs(folder, mode=0o700, exist_ok=True)
    tmp = path + '.tmp'
    fd = os.open(tmp, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
    with os.fdopen(fd, 'w', encoding='utf-8', newline='\n') as f:
        json.dump(doc, f, indent=1, sort_keys=True)
        f.write('\n')
    os.replace(tmp, path)
    if os.name != 'nt':
        os.chmod(path, 0o600)


def store(name, key, path=None):
    """Stores (or replaces) a key; True when one was replaced."""
    if not NAME.match(name):
        raise KeyStoreError(f'{name!r} is not a key name: lower-case letters, digits and -')
    why = check_key(key)
    if why:
        raise KeyStoreError(f'that does not look like an API key: {why}')
    doc = load(path)
    replaced = name in doc['keys']
    doc['keys'][name] = dict(_seal(key), saved=time.strftime('%Y-%m-%d'))
    save(doc, path)
    return replaced


def remove(name, path=None):
    doc = load(path)
    if doc['keys'].pop(name, None) is None:
        return False
    save(doc, path)
    return True


def get(name, path=None):
    """The stored key of that name, or ''."""
    entry = load(path)['keys'].get(name)
    return _open(entry, name) if entry else ''


def stored_values(path=None):
    """[(name, key)] of every stored key this account can read (for the publishing checks)."""
    try:
        keys = load(path)['keys']
    except KeyStoreError:
        return []
    out = []
    for name, entry in sorted(keys.items()):
        try:
            k = _open(entry, name)
        except KeyStoreError:
            continue
        if k:
            out.append((name, k))
    return out


# ---- for the tools ------------------------------------------------------------------------------------------------

def resolve(name, var=None, prefer_env=False):
    """(key, where it came from) for a provider, ('', None) when there is none: the stored key, else the
    environment variable (var, default NAME_API_KEY); with prefer_env (--api-key-env) the variable first.

    The stored key comes first so that storing a new key is enough: an old key left in the environment (set
    permanently, or inherited by an open terminal) does not shadow it."""
    var = var or env_var(name)

    def from_env():
        v = os.environ.get(var, '').strip()
        return (v, f'environment variable {var}') if v else None

    def from_store():
        k = get(name)
        return (k, f'stored key {name!r} (tools/api_keys.py)') if k else None

    for source in ((from_env, from_store) if prefer_env else (from_store, from_env)):
        found = source()
        if found:
            return found
    return '', None


def key_name(url, key=None, api_key_env=None):
    """The key name a tool uses: --key, else --api-key-env, else the provider of the URL; None if unknown."""
    if key:
        return key
    if api_key_env:
        return name_of_env(api_key_env)
    return name_for_url(url)


def key_for(url, key=None, api_key_env=None):
    """The API key for a tool's endpoint, or exits with what to do."""
    name = key_name(url, key, api_key_env)
    if not name:
        sys.exit(f'which API key goes to {url}? Pass --key NAME (a key stored with tools/api_keys.py, '
                 f'or the environment variable NAME_API_KEY).')
    explicit = bool(api_key_env) and not key
    var = api_key_env if explicit else env_var(name)
    try:
        k, _ = resolve(name, var, prefer_env=explicit)
    except KeyStoreError as e:
        sys.exit(str(e))
    if not k:
        sys.exit(f'no API key for {name}. Store it once:  python tools/api_keys.py set {name}\n'
                 f'(or set the environment variable {var} in this terminal)')
    return k


# ---- command line -------------------------------------------------------------------------------------------------

def clipboard_text():
    if os.name == 'nt':
        import ctypes
        from ctypes import wintypes
        user32 = ctypes.WinDLL('user32', use_last_error=True)
        kernel32 = ctypes.WinDLL('kernel32', use_last_error=True)
        user32.OpenClipboard.argtypes = [wintypes.HWND]
        user32.GetClipboardData.argtypes = [wintypes.UINT]
        user32.GetClipboardData.restype = wintypes.HANDLE
        kernel32.GlobalLock.argtypes = [wintypes.HGLOBAL]
        kernel32.GlobalLock.restype = ctypes.c_void_p
        kernel32.GlobalUnlock.argtypes = [wintypes.HGLOBAL]
        if not user32.OpenClipboard(None):
            raise KeyStoreError('the clipboard is in use by another program; try again')
        try:
            h = user32.GetClipboardData(13)   # (CF_UNICODETEXT)
            if not h:
                return ''
            p = kernel32.GlobalLock(h)
            try:
                return ctypes.wstring_at(p) if p else ''
            finally:
                kernel32.GlobalUnlock(h)
        finally:
            user32.CloseClipboard()
    for cmd in (['pbpaste'], ['wl-paste', '-n'], ['xclip', '-o', '-selection', 'clipboard'], ['xsel', '-b']):
        try:
            return subprocess.run(cmd, capture_output=True, text=True, timeout=5).stdout
        except (OSError, subprocess.TimeoutExpired):
            continue
    raise KeyStoreError('no clipboard tool found (pbpaste, wl-paste, xclip, xsel): paste the key at the prompt')


def _tail(key):
    return '...' + key[-4:]


def main(argv=None):
    ap = argparse.ArgumentParser(description='API keys for the model tools (stored outside the repository).')
    sub = ap.add_subparsers(dest='cmd', required=True)
    s = sub.add_parser('set', help='store a key (replaces one of the same name)')
    s.add_argument('name', help='provider name: deepseek, openrouter, ... (lower case)')
    s.add_argument('--clipboard', action='store_true', help='take the key from the clipboard')
    sub.add_parser('list', help='the stored keys')
    r = sub.add_parser('remove', help='delete a stored key')
    r.add_argument('name')
    sub.add_parser('where', help='the file that holds the keys')
    a = ap.parse_args(argv)
    path = store_path()
    try:
        if a.cmd == 'where':
            print(path)
        elif a.cmd == 'set':
            if a.clipboard:
                key = clipboard_text()
            elif sys.stdin.isatty():
                key = getpass.getpass(f'API key for {a.name} (paste it, then Enter; it is not shown): ')
            else:
                key = sys.stdin.readline()
            key = key.strip()
            replaced = store(a.name, key, path)
            print(f'{"Replaced" if replaced else "Stored"} the {a.name} key ({_tail(key)}) in {path}'
                  + (' (encrypted for this Windows account)' if os.name == 'nt' else ' (readable by you only)'))
            if os.environ.get(env_var(a.name), '').strip():
                print(f'Note: {env_var(a.name)} is also set in your environment. The stored key is used instead; the '
                      f'variable only counts when no key is stored. If it holds an old key, remove it'
                      + (f" (PowerShell: [Environment]::SetEnvironmentVariable('{env_var(a.name)}', $null, 'User'))."
                         if os.name == 'nt' else ' from your shell profile.'))
        elif a.cmd == 'list':
            keys = load(path)['keys']
            if not keys:
                print(f'No keys stored ({path}). Store one: python tools/api_keys.py set deepseek')
            for name, entry in sorted(keys.items()):
                try:
                    shown = _tail(_open(entry, name))
                except KeyStoreError as e:
                    shown = f'unreadable: {e}'
                env = (f' ({env_var(name)} is also set: not used while this key is stored)'
                       if os.environ.get(env_var(name), '').strip() else '')
                print(f'{name:<12} {shown:<10} saved {entry.get("saved", "?")}{env}')
        elif a.cmd == 'remove':
            print(f'Removed the {a.name} key.' if remove(a.name, path) else f'No {a.name} key is stored.')
    except KeyStoreError as e:
        sys.exit(str(e))


if __name__ == '__main__':
    main()
