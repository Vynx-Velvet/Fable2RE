"""Naming work packets for a language model (any model: this only writes prompt files).

    python tools/naming/make_batches.py [--limit 2000] [--tokens 6000] [--anchors-only] [--out build/naming/batches]

Writes build/naming/batches/batch_NNNN.md: instructions + the lifted code of some functions that have no name
yet, each with what is already known around it (names of the functions it calls and of its callers, strings,
its class). A model answers each batch with a TSV (see PROMPT) saved as build/naming/answers/batch_NNNN.tsv;
tools/naming/merge.py checks the answers and adds them to research/names/.

Order: bottom-up. A function is offered once the functions it calls are named or have been offered in an
earlier batch, so run the pipeline in rounds: make_batches -> model -> merge -> make_batches ...

The batches contain lifted game code: they are local build files (build/ is not committed). Sending them to a
hosted model sends that code to the provider - the user's decision.
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 'tools', 'lift'))
import names as dictionary  # noqa: E402
import scope  # noqa: E402  (only the game's own code is offered: research/catalog/scope.tsv)

PROMPT = """You are naming functions of the game Fable II (Xbox 360, 2008, Lionhead Studios) from mechanically
lifted C++. Each function below is listed with its address, the functions it calls and its callers (already
named where possible), the strings it references and the class of its first argument if known.

In the code: LOAD8/16/32 and STORE8/16/32 read and write game memory at an address; `<object>->m_XX` is a
field of the object in the first argument; arg1, arg2, ... (floatArg1, ...) are the parameters in order and
local1, local2, ... locals without a name yet; str_Xxx constants are game strings and g_XXXXXXXX game globals;
`n_sub_XXXXXXXX` is a function without a name yet; `Lua_<Class>_<Method>` implements the script function
Class.Method.

For each function decide what it does and give it a name. Rules:
- Name only what the code shows. Prefer `Class_Method` (for example `SpellManager_SetMagicEnabled`), plain
  library names for library code (Lua 5.1: lua_*, luaL_*, luaV_*, luaH_*; C runtime: memcpy, strlen;
  containers: `Vector_PushBack`, `List_Erase`, `String_Assign`).
- confidence: high = identified exactly (a known library function, or the direct implementation of a named
  script binding); medium = clear from use; low = a plausible guess. If you cannot tell, do not answer for
  that function at all.
- basis: one short sentence in your own words saying why. Never copy code into it.
- Names are C++ identifiers: letters, digits, underscore; unique; not starting with sub_ or n_sub_.
- You may also name the class of the first argument and its fields when the function makes them clear.
- You may also rename parameters and locals (arg1, local7, or a name already given) to say what they hold in
  game terms (lowerCamelCase: targetCreature, goldAmount, questIndex), when the code makes it clear.

Answer with tab-separated lines only, no other text:
F<TAB>address<TAB>name<TAB>confidence<TAB>basis
C<TAB>class id<TAB>name<TAB>confidence<TAB>basis
M<TAB>class id<TAB>field offset in hex<TAB>name<TAB>confidence<TAB>basis
L<TAB>function address<TAB>variable as shown<TAB>new name<TAB>confidence<TAB>basis
(address and class id exactly as shown in the function headers below.)
"""

_NOISE = re.compile(r'\s*((uint\d+_t|int\d+_t|double|PPC\w+) \w+(\{\}| = ctx\.\w+(\.\w+)?);'
                    r'|(r\d+(_\d+)?|f\d+(_\d+)?|cr\d\.\w+|xer\.\w+) = ctx\.\w+(\.\w+)*;'
                    r'|ctx\.(r\d+|f\d+|cr\d|xer)(\.\w+)+ = [\w.]+;'
                    r'|F2_NATIVE_ENTER\(.*|REX_FUNC_PROLOGUE\(\);|(?:F2_LIFTED|CPU_STATE_ENTRY)\(.*|ea = -?\d+ \+ r1;|STORE32\(ea, r1\);'
                    r'|r1 = ea;|r1 = \((int64_t\)\(uint64_t\)|int32_t\))r1 \+ \d+;|ctx\.fpscr\.\w+\(\);)$')


def load_blocks():
    blocks = {}
    for f in glob.glob(os.path.join(ROOT, 'Fable2Recomp', 'lifted', 'lifted.*.cpp')):
        with open(f, encoding='utf-8') as fh:
            for b in fh.read().split('// @lift ')[1:]:
                blocks[b.split('\n', 1)[0].strip()] = b
    return blocks


def catalog():
    """Names from the catalog; the strings each function references from the local research/decomp/
    function_strings.tsv (text from the user's copy: tools/catalog/function_strings.py, run by the setup)."""
    names, strings = {}, {}
    p = os.path.join(ROOT, 'research', 'catalog', 'functions.tsv')
    with open(p, encoding='utf-8') as f:
        head = f.readline().rstrip('\n').split('\t')
        ia, iname = head.index('address'), head.index('name')
        for line in f:
            r = line.rstrip('\n').split('\t')
            if len(r) > iname:
                a = int(r[ia], 16)
                if not r[iname].startswith(('sub_', 'FUN_', 'thunk')):
                    names[a] = r[iname]
    p = os.path.join(ROOT, 'research', 'decomp', 'function_strings.tsv')
    if os.path.exists(p):
        with open(p, encoding='utf-8') as f:
            f.readline()
            for line in f:
                r = line.rstrip('\n').split('\t')
                if len(r) == 2 and r[1]:
                    strings[int(r[0], 16)] = r[1]
    else:
        print('make_batches: research/decomp/function_strings.tsv not found (python tools/catalog/function_strings.py): '
              'batches go out without string context')
    return names, strings


def compact(block):
    out = []
    for line in block.split('\n')[1:]:
        s = line.strip()
        if not s or (s.startswith('//') and not s.startswith('// sub_')) or _NOISE.match(line):
            continue
        if s.startswith(('if (!UseLiftedCode(', 'LiftedFrame frame(', 'stack = PushStackFrame(', 'stack = PopStackFrame(',
                         'uint32_t stack = ctx.')) or re.fullmatch(r'[\w:<>]+ local\d+\{\};', s):
            continue
        out.append(line.rstrip())
    return '\n'.join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--limit', type=int, default=2000, help='functions to offer in this round')
    ap.add_argument('--tokens', type=int, default=6000, help='approximate size of one batch (4 characters = 1 token)')
    ap.add_argument('--max-function', type=int, default=12000, help='skip functions longer than this many characters')
    ap.add_argument('--all-code', action='store_true', help='also library and system code (default: game code only)')
    ap.add_argument('--anchors-only', action='store_true', help='only functions called by an already named function')
    ap.add_argument('--again', action='store_true', help='--locals: also offer functions earlier rounds offered')
    ap.add_argument('--dry-run', action='store_true', help='--locals: do not record the offered functions')
    ap.add_argument('--locals', action='store_true',
                    help='a round for locals: functions that have a name but still many local1/arg1 variables')
    ap.add_argument('--out', default=os.path.join(ROOT, 'build', 'naming', 'batches'))
    args = ap.parse_args()
    blocks = load_blocks()
    cat, strings = catalog()
    known = dict(cat)
    known.update(dictionary.load()['functions'])
    if args.locals:
        return locals_round(args, blocks, known, strings)
    by_name = {v: k for k, v in known.items()}
    cls = {'this': {}, 'classes': {}}
    cp = os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json')
    if os.path.exists(cp):
        cls = json.load(open(cp, encoding='utf-8'))

    def addr_of(token):
        if token.startswith('n_sub_'):
            return int(token[6:], 16)
        return by_name.get(token)
    call_re = re.compile(r'\b(n_sub_[0-9A-F]{8}|[A-Za-z_]\w*)\(ctx, base')
    callees, callers = {}, collections.defaultdict(set)
    for n, b in blocks.items():
        a = int(n[4:], 16) if n.startswith('sub_') else None
        if a is None:
            continue
        cs = set()
        for m in call_re.finditer(b.split('F2_NATIVE_ENTER', 1)[-1]):
            c = addr_of(m.group(1))
            if c is not None and c != a:
                cs.add(c)
        callees[a] = cs
        for c in cs:
            callers[c].add(a)
    todo = [a for a in callees if a not in known and (args.all_code or scope.in_game(a))]
    if args.anchors_only:
        todo = [x for x in todo if any(c in known for c in callers[x])]
    # bottom-up: fewest unnamed callees first, then most named callers (best context), then address
    todo.sort(key=lambda x: (sum(1 for c in callees[x] if c not in known),
                             -sum(1 for c in callers[x] if c in known), x))
    os.makedirs(args.out, exist_ok=True)
    for f in glob.glob(os.path.join(args.out, 'batch_*.md')):
        os.remove(f)

    def label(x):
        return known.get(x) or f'n_sub_{x:08X}'
    batch, size, written, offered = [], 0, 0, 0
    budget = args.tokens * 4

    def flush():
        nonlocal batch, size, written
        if batch:
            written += 1
            with open(os.path.join(args.out, f'batch_{written:04}.md'), 'w', encoding='utf-8') as f:
                f.write(PROMPT + '\n' + '\n'.join(batch))
            batch, size = [], 0
    for x in todo:
        if offered >= args.limit:
            break
        code = compact(blocks[f'sub_{x:08X}'])
        code = re.sub(r'\bn_sub_([0-9A-F]{8})\b', lambda m: label(int(m.group(1), 16)), code)
        if len(code) > args.max_function:
            continue
        key = cls['this'].get(f'sub_{x:08X}')
        head = [f'### function {x:08X}']
        if key:
            head.append(f'class of first argument: id {key} ({cls["classes"][key]["struct"]})')
        cs = sorted(label(c) for c in callers[x] if c in known)[:12]
        if cs:
            head.append('called by: ' + ', '.join(cs))
        if callers[x]:
            head.append(f'number of callers: {len(callers[x])}')
        if x in strings:
            head.append('strings: ' + strings[x][:300])
        text = '\n'.join(head) + '\n```cpp\n' + code + '\n```\n'
        if size + len(text) > budget:
            flush()
        batch.append(text)
        size += len(text)
        offered += 1
    flush()
    print(f'{len(todo)} functions without a name; offered {offered} in {written} batches -> {args.out}')


LOCALS_PROMPT = """You are naming the local variables and parameters of functions of the game Fable II (Xbox 360,
2008, Lionhead Studios) in mechanically lifted C++. The functions already have names. Variables called arg1,
arg2, ... (floatArg1, ...) are parameters, local1, local2, ... are locals without a name; other variables were
named mechanically after what they hold. In the code: `<object>->m_XX` is a field of the object the function
works on, LOAD8/16/32 and STORE8/16/32 read and write game memory, str_Xxx constants are game strings and
g_XXXXXXXX game globals; `stack`, `scratch`, `compareN`, `flags` and `callTarget` are machine details, leave them.

Give each variable whose purpose the code makes clear a name saying what it is in game terms (lowerCamelCase:
targetCreature, goldAmount, questIndex, isVisible, itemCount). Skip variables you cannot tell; skip the
temporaries of address arithmetic. confidence: high = certain from the code, medium = clear from use, low = a
plausible guess. basis: one short sentence in your own words; never copy code into it.

Answer with tab-separated lines only, no other text:
L<TAB>function address<TAB>variable as shown<TAB>new name<TAB>confidence<TAB>basis
(function address exactly as shown in the function headers below.)
"""


def locals_round(args, blocks, known, strings):
    import json
    varmap = {}
    for p in glob.glob(os.path.join(ROOT, 'tools', 'lift', 'cache', 'varmap', '*.json')):
        varmap.update(json.load(open(p, encoding='utf-8')))
    lp = os.path.join(ROOT, 'research', 'names', 'locals.tsv')
    done = set()
    if os.path.exists(lp):
        with open(lp, encoding='utf-8') as f:
            f.readline()
            done = {line.split('\t')[0] for line in f}
    # functions an earlier round offered (a model found nothing to name there then: offer new ones first)
    seen_path = os.path.join(ROOT, 'build', 'naming', 'offered_locals.txt')
    seen = set(open(seen_path).read().split()) if os.path.exists(seen_path) else set()
    if not args.again:
        done |= seen
    generic = re.compile(r'^(?:local|arg|floatArg)\d+$')
    todo = []
    for a, name in known.items():
        key = f'{a:08X}'
        b = blocks.get(f'sub_{key}')
        if not b or key in done or key not in varmap or not (args.all_code or scope.in_game(a)):
            continue
        n = sum(1 for v in varmap[key] if generic.match(v))
        if n >= 2:
            todo.append((n, a, name))
    # most generic variables first among functions small enough to read whole
    todo.sort(key=lambda t: (-min(t[0], 12), t[1]))
    os.makedirs(args.out, exist_ok=True)
    for f in glob.glob(os.path.join(args.out, 'batch_*.md')):
        os.remove(f)
    batch, size, written, offered = [], 0, 0, 0
    offered_keys = []
    budget = args.tokens * 4

    def flush():
        nonlocal batch, size, written
        if batch:
            written += 1
            with open(os.path.join(args.out, f'batch_{written:04}.md'), 'w', encoding='utf-8') as f:
                f.write(LOCALS_PROMPT + '\n' + '\n'.join(batch))
            batch, size = [], 0
    for _, a, name in todo:
        if offered >= args.limit:
            break
        code = compact(blocks[f'sub_{a:08X}'])
        if len(code) > args.max_function:
            continue
        head = f'### function {a:08X}  ({name})'
        if a in strings:
            head += '\nstrings: ' + strings[a][:300]
        text = head + '\n```cpp\n' + code + '\n```\n'
        if size + len(text) > budget:
            flush()
        batch.append(text)
        size += len(text)
        offered += 1
        offered_keys.append(f'{a:08X}')
    flush()
    if not args.dry_run:
        with open(seen_path, 'w') as f:
            f.write('\n'.join(sorted(seen | set(offered_keys))) + '\n')
    print(f'{len(todo)} named functions with unnamed locals; offered {offered} in {written} batches -> {args.out}')


if __name__ == '__main__':
    main()
