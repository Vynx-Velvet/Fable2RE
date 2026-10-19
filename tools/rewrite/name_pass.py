"""The naming step for promoted functions: a model names what their code still calls by address or by the lifter's
placeholder (tools/rewrite/readability.py: unnamed function, unnamed callee, machine variable name, field offset).

    python tools/rewrite/name_pass.py prepare [--limit N] [--tokens 6000]   packets -> build/rewrite/naming/packets/
    python tools/rewrite/name_pass.py run [--workers 4] [--model deepseek-flash] [--effort low] [--limit N]
                                                                          answers -> build/rewrite/naming/answers/
    python tools/rewrite/name_pass.py collect [--dry-run]                 apply what the answers give

A packet holds the module text of some functions and, for each function they call without a name, an excerpt of
that callee's own code, so the callee is named from what it does. Answers use the naming pipeline's lines
(tools/naming/make_batches.py):

    F  address  name  confidence  basis                  a function: the one shown, or a callee
    M  class id  offset  name  confidence  basis          a field of the function's class
    L  function address  variable as shown  name  ...    a parameter or variable of a promoted function

collect hands F and M lines to tools/naming/merge.py (checked, then added to research/names/; they take effect
with the next tools/lift/apply_names.py, which re-lifts what they affect, and promote.py sync, which writes them
into the modules) and applies L lines at once to the promoted modules, where those names exist only: a rename
inside one function, refused when the new name is not an identifier, is reserved, or is already used there. A
rename changes no code, so it takes no new check; the review recorded for the function carries over.

The packets contain game code (the user's own copy). `run` sends them to the model's provider, as the rewrite
runner does with its packets.
"""
import argparse
import collections
import concurrent.futures
import glob
import json
import os
import re
import subprocess
import sys
import threading

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, 'tools'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import promote  # noqa: E402
import readability  # noqa: E402

WORK = os.path.join(ROOT, 'build', 'rewrite', 'naming')
PACKETS = os.path.join(WORK, 'packets')
ANSWERS = os.path.join(WORK, 'answers')
MERGE_IN = os.path.join(ROOT, 'build', 'naming', 'answers_promoted')
NAMING = ('unnamed function', 'unnamed callee', 'machine variable name', 'field offset')
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]{2,79}\Z')
RESERVED = {'new', 'delete', 'class', 'this', 'operator', 'int', 'float', 'double', 'void', 'ctx', 'base', 'self',
            'main', 'vtable', 'result', 'stack', 'frame', 'stackFrame'}

PROMPT = """You are naming the parts of readable C++ functions of the game Fable II (Xbox 360, 2008, Lionhead
Studios). Each function below already behaves exactly like the original game code and has been reviewed; what it
still lacks are names. Give names to:

- the function itself, when it is called `n_sub_XXXXXXXX`: an F line with its address;
- functions it calls that have no name (`n_sub_XXXXXXXX(...)`): their own code is shown under "Callees"; an F line
  with the callee's address;
- parameters and variables with placeholder names (arg1, local12, r31, or a name made from an offset such as
  flag144): an L line with the function's address, the variable exactly as shown, and the new name;
- fields of the function's class that the code reads or writes at an offset (`LOAD32(self + 144)`,
  `self->m_1C`): an M line with the class id shown in the function's header, the offset in hex, and the name.

In the code: LOAD8/16/32/64 and STORE8/16/32/64 read and write game memory at an address; GameObject<C>(base, x)
is the object of class C at game address x; str_Xxx constants are game strings and g_Xxx game globals;
`Lua_<Class>_<Method>` implements the script function Class.Method; RegisterAtExit registers a function to run
when the game exits; GameStackFrame is the function's frame on the game's stack (no name needed).

Rules:
- Name only what the code shows. Functions: `Class_Method` (for example `SpellManager_SetMagicEnabled`) or a
  plain descriptive name for helpers (`Vector_PushBack`, `String_Assign`). Variables and fields: lowerCamelCase
  for what they hold in game terms (targetCreature, goldAmount, isOpen).
- Do not rename anything that already has a real name. Do not invent names for things the code does not show.
- Never make a name from an offset or a position (`GetField8`, `GetByte31`, `flag144`, `unk10`): that is not a
  name. If the code shows nothing more than "a byte at offset 31", give no line for it.
- confidence: high = identified exactly; medium = clear from use; low = a plausible reading. If you cannot tell,
  give no line for it.
- basis: one short sentence in your own words saying why. Never copy code into it.
- Names are C++ identifiers: letters, digits, underscore, 3 to 80 characters; not starting with sub_ or n_sub_.

Answer with tab-separated lines only, no other text:
F<TAB>address<TAB>name<TAB>confidence<TAB>basis
M<TAB>class id<TAB>field offset in hex<TAB>name<TAB>confidence<TAB>basis
L<TAB>function address<TAB>variable as shown<TAB>new name<TAB>confidence<TAB>basis
"""


def lifted_blocks():
    """{sub_X: lifted text} of the functions still in the lifted files."""
    blocks = {}
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        with open(f, encoding='utf-8') as fh:
            for b in fh.read().split('// @lift ')[1:]:
                blocks[b.split('\n', 1)[0].strip()] = b
    return blocks


def excerpt(text, lines=30):
    out = [l for l in text.split('\n') if l.strip() and 'UseLiftedCode' not in l and 'LiftedFrame' not in l]
    return '\n'.join(out[:lines]) + ('\n\t...' if len(out) > lines else '')


def issues_of(text):
    """The readability issues of one function's module text (it ends with its PROMOTED_ENTRY line)."""
    [(_, name, lines)] = readability.functions(text)
    return readability.issues(name, lines)


def cmd_prepare(a):
    funcs = promote.module_functions()
    this, structs, _ = promote.class_of()
    blocks = lifted_blocks()
    todo = []
    for n, (path, text) in funcs.items():
        found = issues_of(text)
        if any(k in found for k in NAMING):
            level = readability.level(found)
            todo.append((level != 'readable', os.path.basename(path)[:-4], int(n[4:], 16), n, found))
    todo.sort()
    if a.limit:
        todo = todo[:a.limit]
    os.makedirs(PACKETS, exist_ok=True)
    for f in glob.glob(os.path.join(PACKETS, '*.md')):
        os.remove(f)
    packets, cur, size, module = [], [], 0, None
    for _, mod, _, n, found in todo:
        t = funcs[n][1]
        if cur and (size + len(t) > a.tokens * 4 or mod != module):
            packets.append(cur)
            cur, size = [], 0
        cur.append(n)
        size += len(t)
        module = mod
    if cur:
        packets.append(cur)
    for k, names in enumerate(packets):
        parts = [PROMPT, '']
        callees = {}
        for n in names:
            path, text = funcs[n]
            key = this.get(n)
            cls = f'class id {key} ({structs.get(key, "C_" + key)})' if key else 'no known class'
            parts += [f'### Function {n[4:]} ({cls})', '```cpp', text.strip(), '```', '']
            for c in re.findall(r'\bn_sub_([0-9A-F]{8})\(ctx, base\b', text):
                if 'sub_' + c not in names:   # (not the functions shown above: their own code is there)
                    callees.setdefault('sub_' + c, None)
        if callees:
            parts += ['## Callees without a name (their own code)', '']
            for c in callees:
                src = funcs[c][1] if c in funcs else blocks.get(c)
                if src:
                    parts += [f'### Callee {c[4:]}', '```cpp', excerpt(src), '```', '']
        with open(os.path.join(PACKETS, f'naming_{k:04d}.md'), 'w', encoding='utf-8', newline='\n') as f:
            f.write('\n'.join(parts))
    print(f'{len(todo)} functions with names to give in {len(packets)} packets -> {os.path.relpath(PACKETS, ROOT)}')
    return 0


def cmd_run(a):
    import api_keys
    import run_api
    key = api_keys.key_for(a.url)
    if not key:
        print('no API key for this provider (python tools/api_keys.py set deepseek)')
        return 1
    os.makedirs(ANSWERS, exist_ok=True)
    todo = sorted(p for p in glob.glob(os.path.join(PACKETS, '*.md'))
                  if not os.path.exists(os.path.join(ANSWERS, os.path.basename(p)[:-3] + '.tsv')))
    if a.limit:
        todo = todo[:a.limit]
    print(f'{len(todo)} packets to answer; balance {run_api.balance(a.url, key)}', flush=True)
    lock = threading.Lock()
    done = [0]

    def one(p):
        text = open(p, encoding='utf-8').read()
        reply = run_api.chat(a.url, key, a.model, [{'role': 'user', 'content': text}], effort=a.effort,
                             max_tokens=a.max_tokens)
        lines = [l.strip() for l in reply.split('\n') if re.match(r'^\s*[FML]\t', l)]
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
            except run_api.Fatal as e:
                print(f'stopped: {e}')
                break
            except Exception as e:   # (one packet failing leaves it for the next run)
                print(f'  a packet failed: {str(e)[:200]}')
    print(f'balance {run_api.balance(a.url, key)}; tokens {run_api.model_api.describe(run_api.USAGE)}')
    return 0


def cmd_collect(a):
    funcs = promote.module_functions()
    by_addr = {n[4:]: n for n in funcs}
    dictionary_lines, renames = [], collections.defaultdict(dict)
    refused = collections.Counter()
    placeholder = readability.NAMING['placeholder name']
    for f in sorted(glob.glob(os.path.join(ANSWERS, '*.tsv'))):
        for line in open(f, encoding='utf-8'):
            c = [x.strip() for x in line.rstrip('\n').split('\t')]
            name, conf = (c[-3], c[-2]) if len(c) >= 5 else ('', '')
            if c[0] not in ('F', 'M', 'L') or len(c) < 5:
                continue
            if conf.lower() not in ('medium', 'high'):
                refused[f'{c[0]}: low confidence'] += 1   # (a guess misleads: wrong is worse than none)
                continue
            if placeholder.fullmatch(name):
                refused[f'{c[0]}: a name made from an offset'] += 1
                continue
            if c[0] in ('F', 'M'):
                dictionary_lines.append('\t'.join(c))
            else:
                n = by_addr.get(c[1].upper().replace('0X', '')[-8:])
                old, new = c[2].strip(), c[3].strip()
                if n is None:   # (a variable of a callee still in the lifted code: the dictionary's locals)
                    dictionary_lines.append('\t'.join(c))
                elif not IDENT.match(new) or new in RESERVED or new.startswith(('sub_', 'n_sub_')) or old == new:
                    refused['L: not a usable name'] += 1
                else:
                    renames[n][old] = new
    # module-local renames
    applied = 0
    by_module = collections.defaultdict(dict)
    for n, rn in renames.items():
        text = funcs[n][1]
        lines = text.split('\n')
        body = '\n'.join(lines[:-1])   # (not the PROMOTED_ENTRY line)
        taken = set(re.findall(r'\b[A-Za-z_]\w*\b', body))
        for old, new in rn.items():
            if not re.search(rf'\b{re.escape(old)}\b', body):
                refused['L: variable not in the function'] += 1
                continue
            if new in taken:
                refused['L: name already used in the function'] += 1
                continue
            body = re.sub(rf'(?<![\w.>]){re.escape(old)}\b', new, body)
            taken.add(new)
            applied += 1
        new_text = body + '\n' + lines[-1]
        if new_text != text:
            by_module[funcs[n][0]][n] = new_text
    print(f'{len(dictionary_lines)} function and field names for the dictionary; {applied} variable renames in '
          f'{sum(len(v) for v in by_module.values())} functions; refused: {dict(refused)}')
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
    os.makedirs(MERGE_IN, exist_ok=True)
    with open(os.path.join(MERGE_IN, 'promoted.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(dictionary_lines) + '\n')
    r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'naming', 'merge.py'), '--answers', MERGE_IN],
                       capture_output=True, text=True)
    print(r.stdout[-2000:], r.stderr[-1000:])
    print('next: tools/lift/apply_names.py (re-lifts what the new names affect), promote.py sync, the build')
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('prepare')
    p.add_argument('--limit', type=int, default=0)
    p.add_argument('--tokens', type=int, default=6000)
    r = sub.add_parser('run')
    r.add_argument('--url', default='https://api.deepseek.com')
    r.add_argument('--model', default='deepseek-flash')
    r.add_argument('--effort', default='low')
    r.add_argument('--max-tokens', type=int, default=0)
    r.add_argument('--workers', type=int, default=4)
    r.add_argument('--limit', type=int, default=0)
    c = sub.add_parser('collect')
    c.add_argument('--dry-run', action='store_true')
    a = ap.parse_args()
    return {'prepare': cmd_prepare, 'run': cmd_run, 'collect': cmd_collect}[a.cmd](a)


if __name__ == '__main__':
    sys.exit(main())
