"""The naming step for globals the promoted functions still use by address (g_834976F8), and for the start-up and
shut-down functions of those globals.

    python tools/rewrite/name_globals_pass.py prepare          packets -> build/rewrite/naming_globals/packets/
    python tools/rewrite/name_globals_pass.py run [--workers 6]   answers (DeepSeek, as tools/rewrite/name_pass.py)
    python tools/rewrite/name_globals_pass.py collect [--dry-run]  rename in the promoted modules

A global is named from what the code does with it: each packet shows, per global, up to three promoted functions
and three lifted functions that use it (excerpts). Only a whole global is named (a constant `g_<address>` the code
uses as a value, never with an offset: a 64 KiB page base plus an offset is another thing at another address).

collect keeps medium and high confidence only, and names that are identifiers not taken in any module, not made
from an offset or an address; it renames the constant in every promoted function that declares it (module-local
names: the lifted code keeps the address until a dictionary of globals exists), then names a start-up or
shut-down function of such a global that does nothing but construct or release it (Construct_/Destroy_<global>,
as tools/rewrite/name_globals.py). A function whose published form would show game text after the rename keeps
its old text. A rename changes no code; the review recorded for the function carries over.
"""
import argparse
import collections
import concurrent.futures
import glob
import os
import re
import sys
import threading

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, 'tools'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import promote  # noqa: E402
import promoted_text  # noqa: E402
import readability  # noqa: E402

WORK = os.path.join(ROOT, 'build', 'rewrite', 'naming_globals')
PACKETS, ANSWERS = os.path.join(WORK, 'packets'), os.path.join(WORK, 'answers')
GLOBAL = re.compile(r'\bg_([0-9A-F]{8})\b')
IDENT = re.compile(r'g_[A-Z][A-Za-z0-9_]{2,78}\Z')

PROMPT = """You are naming global variables of the game Fable II (Xbox 360, 2008, Lionhead Studios) in readable C++.
Each global below is shown with code that uses it: promoted (readable) functions and lifted functions. In the
code, `g_XXXXXXXX` is the global at game address XXXXXXXX; LOAD/STORE read and write game memory; functions
called `n_sub_...` have no name yet.

For each global decide what it holds and give it a name: G<TAB>address<TAB>name<TAB>confidence<TAB>basis
- Names start with `g_` followed by UpperCamelCase words for what it holds in game terms (g_SoundEventFilters,
  g_PlayerSaveSlots, g_DefaultFont). Never make a name from an address, an offset or a type alone
  (g_Global834976F8, g_StringVector, g_Object1).
- confidence: high = clear from the code; medium = clear from use; low = a guess. If you cannot tell what it
  holds, give no line for it.
- basis: one short sentence in your own words saying why. Never copy code into it.

Answer with tab-separated lines only, no other text.
"""


def lifted_blocks():
    out = {}
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        for b in open(f, encoding='utf-8').read().split('// @lift ')[1:]:
            out[b.split('\n', 1)[0].strip()] = b
    return out


def whole_uses(text, g):
    """Whether a function text uses g only as a whole value (never with an offset)."""
    return not re.search(rf'\b{g}\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d)', text)


def targets(funcs):
    """{address: [functions]} of the globals that keep promoted readable functions from being named."""
    out = collections.defaultdict(list)
    for n, (path, text) in funcs.items():
        fs = readability.functions(text)
        if len(fs) != 1:
            continue
        found = readability.issues(fs[0][1], fs[0][2])
        if readability.level(found) != 'readable' or set(found) - {'address', 'unnamed function', 'unnamed callee'}:
            continue
        for a in set(GLOBAL.findall(text)):
            if whole_uses(text, f'g_{a}') and int(a, 16) & 0xFFFF:
                out[a].append(n)
    return out


def excerpt(text, lines=25):
    out = [l for l in text.split('\n') if l.strip() and 'UseLiftedCode' not in l and 'LiftedFrame' not in l]
    return '\n'.join(out[:lines]) + ('\n\t...' if len(out) > lines else '')


def cmd_prepare(a):
    funcs = promote.module_functions()
    want = targets(funcs)
    blocks = lifted_blocks()
    users = collections.defaultdict(list)
    pat = re.compile(r'\bg_(' + '|'.join(want) + r')\b') if want else None
    for n, b in blocks.items():
        for g in set(pat.findall(b)) if pat else ():
            if len(users[g]) < 3 and whole_uses(b, f'g_{g}'):
                users[g].append(b)
    os.makedirs(PACKETS, exist_ok=True)
    for f in glob.glob(os.path.join(PACKETS, '*.md')):
        os.remove(f)
    order = sorted(want, key=lambda g: -len(want[g]))
    k = 0
    for i in range(0, len(order), a.per_packet):
        parts = [PROMPT, '']
        for g in order[i:i + a.per_packet]:
            parts += [f'## Global {g}', '']
            for n in want[g][:3]:
                parts += ['```cpp', excerpt(funcs[n][1]), '```', '']
            for b in users[g]:
                parts += ['```cpp', excerpt(b.split('\n', 1)[1]), '```', '']
        with open(os.path.join(PACKETS, f'globals_{k:04d}.md'), 'w', encoding='utf-8', newline='\n') as f:
            f.write('\n'.join(parts))
        k += 1
    print(f'{len(want)} globals used by {len({n for v in want.values() for n in v})} functions in {k} packets')
    return 0


def cmd_run(a):
    import api_keys
    import run_api
    key = api_keys.key_for(a.url)
    os.makedirs(ANSWERS, exist_ok=True)
    todo = sorted(p for p in glob.glob(os.path.join(PACKETS, '*.md'))
                  if not os.path.exists(os.path.join(ANSWERS, os.path.basename(p)[:-3] + '.tsv')))
    print(f'{len(todo)} packets; balance {run_api.balance(a.url, key)}', flush=True)
    lock, done = threading.Lock(), [0]

    def one(p):
        reply = run_api.chat(a.url, key, a.model, [{'role': 'user', 'content': open(p, encoding='utf-8').read()}],
                             effort=a.effort)
        lines = [l.strip() for l in reply.split('\n') if re.match(r'^\s*G\t', l)]
        with open(os.path.join(ANSWERS, os.path.basename(p)[:-3] + '.tsv'), 'w', encoding='utf-8',
                  newline='\n') as f:
            f.write('\n'.join(lines) + '\n')
        with lock:
            done[0] += 1
            if done[0] % 10 == 0 or done[0] == len(todo):
                print(f'  {done[0]}/{len(todo)} answered', flush=True)

    with concurrent.futures.ThreadPoolExecutor(a.workers) as ex:
        for fut in [ex.submit(one, p) for p in todo]:
            try:
                fut.result()
            except Exception as e:
                print(f'  a packet failed: {str(e)[:200]}')
    print(f'balance {run_api.balance(a.url, key)}; tokens {run_api.model_api.describe(run_api.USAGE)}')
    return 0


def cmd_collect(a):
    funcs = promote.module_functions()
    taken = set()
    for _, t in funcs.values():
        taken |= set(re.findall(r'\b[A-Za-z_]\w*\b', t))
    taken |= promoted_text.dictionary_names()
    placeholder = readability.NAMING['placeholder name']
    names, refused = {}, collections.Counter()
    for f in sorted(glob.glob(os.path.join(ANSWERS, '*.tsv'))):
        for line in open(f, encoding='utf-8'):
            c = [x.strip() for x in line.rstrip('\n').split('\t')]
            if len(c) < 5 or c[0] != 'G':
                continue
            addr = c[1].upper().replace('0X', '')[-8:]
            name, conf = c[2], c[3].lower()
            if conf not in ('medium', 'high'):
                refused['low confidence'] += 1
            elif not IDENT.match(name) or placeholder.fullmatch(name) or re.search(r'[0-9A-F]{6}', name):
                refused['not a usable name'] += 1
            elif name in taken or name in names.values():
                refused['name already used'] += 1
            else:
                names[addr] = name
    # rename in every promoted function that declares the global and uses it whole
    by_module = collections.defaultdict(dict)
    renamed = collections.Counter()
    for n, (path, text) in funcs.items():
        new = text
        for g in set(GLOBAL.findall(text)):
            if g in names and whole_uses(text, f'g_{g}'):
                new = re.sub(rf'\bg_{g}\b', names[g], new)
        if new == text:
            continue
        # a start-up or shut-down function of one such global, otherwise unnamed: named after it
        d = promote.DEF_RE.search(new)
        import name_globals
        if d and re.fullmatch(r'n_sub_[0-9A-F]{8}', d.group(1)):
            cs = [c for c in name_globals.calls(new, n) if c[0] != d.group(1)]
            mod = os.path.basename(path)
            fname = None
            if mod.startswith('shutdown_area') and len(cs) == 1 and len(cs[0][1]) == 1 and \
                    cs[0][1][0] in names.values():
                fname = f'Destroy_{cs[0][1][0]}'
            elif mod.startswith('startup_area') and cs and cs[0][1] and cs[0][1][0] in names.values() and \
                    all(c[0] in ('RegisterAtExit',) for c in cs[1:]):
                fname = f'Construct_{cs[0][1][0]}'
            if fname and fname not in taken:
                new = re.sub(rf'\b{d.group(1)}\b', fname, new)
                taken.add(fname)
        try:
            if promoted_text.leftovers(promoted_text.encode(new, context=new)):
                raise promoted_text.TextError('text')
        except promoted_text.TextError:
            refused['would publish game text'] += 1
            continue
        by_module[path][n] = new
        renamed['functions'] += 1
    print(f'{len(names)} global names; {renamed["functions"]} functions changed; refused {dict(refused)}')
    if a.dry_run:
        return 0
    reviewed = promote.reviewed_texts()
    for path, these in sorted(by_module.items()):
        head, have = promote.split_module(open(path, encoding='utf-8').read())
        for n, t in these.items():
            if reviewed.get(n) == promote.text_digest(have[n]):
                reviewed[n] = promote.text_digest(t)
            have[n] = t
        promote.write_module(path, head, have)
    promote.save_reviewed_texts(reviewed)
    with open(os.path.join(WORK, 'global_names.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('address\tname\n' + ''.join(f'{k}\t{v}\n' for k, v in sorted(names.items())))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('prepare')
    p.add_argument('--per-packet', type=int, default=20)
    r = sub.add_parser('run')
    r.add_argument('--url', default='https://api.deepseek.com')
    r.add_argument('--model', default='deepseek-flash')
    r.add_argument('--effort', default='low')
    r.add_argument('--workers', type=int, default=6)
    c = sub.add_parser('collect')
    c.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    return {'prepare': cmd_prepare, 'run': cmd_run, 'collect': cmd_collect}[a.cmd](a)


if __name__ == '__main__':
    sys.exit(main())
