"""Promotes verified rewrites into reviewed source modules: Fable2Recomp/src/game/promoted/<Class>.cpp.

A rewrite (Fable2Recomp/rewritten/sub_X.cpp, local) is model-written readable C++ for one function, accepted by
the differential checker. Promotion turns it into published replacement code (CONTRIBUTING.md):

    python tools/rewrite/promote.py build [--funcs FILE] [--jobs N]
        1. names in effect now; comments quoting game text removed; the fallback calls the recompiled
           original directly; the entry names the generated file it came from (PROMOTED_ENTRY)
        2. register hand-overs (ctx.rN = ...) that no callee reads are dropped
        3. every function is checked again on input profiles 0-5 (both forms; the cleaner one that passes wins)
        4. the passing functions go into one module per class; the lifted files leave them out from then on
           (tools/lift/chunks.py), the stored rewrite moves to build/rewrite/promote/sources
    python tools/rewrite/promote.py check [--module NAME]      re-check module functions (profiles 0-5)
    python tools/rewrite/promote.py review                     review packets: build/rewrite/review/<module>.md
    python tools/rewrite/promote.py record --reviewer ID [--dir DIR]
        applies a review: DIR/verdicts/<Module>.tsv (sub_X<TAB>OK|FIX|DEMOTE<TAB>note, one line per function of
        every module) and DIR/fixes/sub_X.cpp (FIX: the whole function, ending in its unchanged PROMOTED_ENTRY
        line); fixes are checked again (a failing fix is reported and left out), DEMOTE verdicts are demoted, and
        Fable2Recomp/src/game/promoted/REVIEW.tsv records every function reviewed OK. RECORDED keeps the row of a
        review recorded earlier, when the function's text is still the one reviewed (digests: local
        build/rewrite/promote/reviewed_texts.json, started from the published modules the first time)
    python tools/rewrite/promote.py lint                       what is still left to clean, per module
    python tools/rewrite/promote.py demote sub_X ... --reason  back to the lifter (the text is kept, revoked)
    python tools/rewrite/promote.py sync                       (run by tools/lift/apply_names.py: names given or
                                                                changed in the dictionary reach the modules)
Every check here runs `check.py --outputs`: besides memory writes, calls and the return value, the function is
called as lifted code calls it (arguments natively, their registers in the CPU state stale) and must leave the
registers its callers read and pass arguments through as the original does
(research/findings/2026-10-10-native-call-check.md).
Then tools/lift/update.ps1 -Build and the game checks. Review: docs/promoted-code.md.
"""
import argparse
import collections
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
LIFT = os.path.join(ROOT, 'tools', 'lift')
sys.path.insert(0, LIFT)
sys.path.insert(0, os.path.join(LIFT, 'difftest'))
import chunks  # noqa: E402

PROMOTED = os.path.normpath(chunks.PROMOTED_DIR)
REWRITTEN = os.path.normpath(chunks.REWRITTEN_DIR)
WORK = os.path.join(ROOT, 'build', 'rewrite', 'promote')
SNAPSHOT = os.path.join(WORK, 'names_before.json')
PROFILES = '0,1,2,3,4,5'

DEF_RE = re.compile(r'^[A-Za-z_][\w:<>]*\*? (\w+)\(CpuState& ctx, uint8_t\* base')
ENTRY_RE = re.compile(r'^PROMOTED_ENTRY\((\d+), (sub_[0-9A-F]{8}), (0x[0-9A-F]{8})\)')
HANDOVER_RE = re.compile(r'^\s*ctx\.(?:r(?:[3-9]|10)|f(?:[1-9]|1[0-3]))\.(?:u64|u32|s64|s32|f64)\s*=\s*[^;{}]*;\s*$')
# calls that take their arguments through the CPU state: the hand-overs before them stay
STATE_CALL_RE = re.compile(r'REX_CALL_INDIRECT_FUNC|__imp__|\b\w+\(ctx, base\)')
_ANY_CALL_RE = re.compile(r'\b\w+\(ctx, base\b')
GHIDRA_RE = re.compile(r'\b(?:uVar\d+|iVar\d+|puVar\d+|undefined\d?|param_\d+|in_r\d+|extraout_\w+)\b')


# ---- text forms ------------------------------------------------------------------------------------------------

def strip_quote_comments(text):
    """Comments that quote game text (`// "Drone"`) go: the address constant they explain stays."""
    out = []
    for line in text.split('\n'):
        i = line.find('//')
        if i >= 0 and '"' in line[i:] and '"' not in line[:i]:
            line = line[:i].rstrip()
        out.append(line)
    return '\n'.join(out)


def module_form(name, text):
    """Stored rewrite (address-form names, CPU_STATE_ENTRY) -> the text a module holds."""
    text = chunks.current_names(text.rstrip('\n'))
    text = '\n'.join(l for l in text.split('\n') if not re.match(r'\s*//\s*name:', l) and not l.startswith(chunks.MARK))
    text = strip_quote_comments(text)
    text = text.replace(f'{name}_original(ctx, base)', f'__imp__{name}(ctx, base)')
    idx = chunks.file_of(name)
    text = re.sub(rf'^CPU_STATE_ENTRY\({name}, (0x[0-9A-F]{{8}})\)', rf'PROMOTED_ENTRY({idx}, {name}, \1)', text,
                  flags=re.M)
    return text.strip('\n')


def check_form(name, text):
    """Module text -> the form the checker takes (tools/rewrite/check.py)."""
    text = text.replace(f'__imp__{name}(ctx, base)', f'{name}_original(ctx, base)')
    return re.sub(rf'^PROMOTED_ENTRY\(\d+, {name}, (0x[0-9A-F]{{8}})\)', rf'CPU_STATE_ENTRY({name}, \1)', text,
                  flags=re.M)


def drop_handovers(text):
    """Hand-overs of argument registers (ctx.rN = x;) that neither a call nor a return follows. (Until
    2026-10-10 hand-overs before native calls and before returns were dropped too: a callee may pass them on
    to a call through a pointer, and callers read registers set before a return;
    research/findings/2026-10-10-native-call-check.md.)"""
    lines = text.split('\n')
    keep = [True] * len(lines)
    for i, line in enumerate(lines):
        if not HANDOVER_RE.match(line):
            continue
        j = i + 1
        while j < len(lines) and (HANDOVER_RE.match(lines[j]) or not lines[j].strip()
                                  or 'PopStackFrame(' in lines[j] or lines[j].strip() == 'ctx.r1.u64 = stack;'):
            j += 1
        if j < len(lines) and (STATE_CALL_RE.search(lines[j]) or _ANY_CALL_RE.search(lines[j])
                               or re.match(r'^\s*(?:return\b|\}\s*$)', lines[j])):
            continue
        keep[i] = False
    return '\n'.join(l for l, k in zip(lines, keep) if k), keep.count(False)


# ---- modules ---------------------------------------------------------------------------------------------------

def split_module(text):
    """(header text, {function: text}) of a module."""
    lines = text.split('\n')
    ends = [i for i, l in enumerate(lines) if ENTRY_RE.match(l)]
    funcs = {}
    first = len(lines)
    prev_end = -1
    for e in ends:
        name = ENTRY_RE.match(lines[e]).group(2)
        s = e
        while s > prev_end + 1 and not DEF_RE.match(lines[s]):
            s -= 1
        while s - 1 > prev_end and lines[s - 1].startswith('//'):
            s -= 1
        funcs[name] = '\n'.join(lines[s:e + 1])
        first = min(first, s)
        prev_end = e
    return '\n'.join(lines[:first]).rstrip('\n'), funcs


def class_of():
    cl = json.load(open(os.path.join(LIFT, 'cache', 'classes.json'), encoding='utf-8'))
    return cl['this'], {k: c['struct'] for k, c in cl['classes'].items()}, cl['classes']


def module_path(struct):
    return os.path.join(PROMOTED, f'{struct}.cpp')


MODULE_HEADER_LINES = [
    '// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md). Each function was written',
    "// by a language model from the lifter's exact code for the user's own copy and accepted by the differential",
    '// checker on input profiles 0-5 (tools/rewrite/check.py --outputs). Review and game-check status per function:',
    '// REVIEW.tsv in this directory and docs/status.md. A function keeps the address of the original',
    '// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).',
    '// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).',
]
_OLD_HEADER_START = '// Promoted from verified model rewrites'


def refresh_header(head):
    """Module header text with the current provenance lines (older modules claimed review and game checks)."""
    lines = head.split('\n')
    i = next((k for k, l in enumerate(lines) if l.startswith((_OLD_HEADER_START, MODULE_HEADER_LINES[0]))), None)
    if i is None:
        return head
    j = i
    while j < len(lines) and lines[j].startswith('//') and not lines[j].startswith('#'):
        j += 1
    return '\n'.join(lines[:i] + MODULE_HEADER_LINES + lines[j:])


def header_for(struct, key, info):
    return '\n'.join([
        f'// {struct} (vtable 0x{key}): methods of the class as readable C++.',
        '//',
        *MODULE_HEADER_LINES,
        '#include "lifted/lifted.h"',
        '#include "lifted/classes.h"',
        '#include "lifted/native_decls.h"',
    ])


def free_module(n):
    """(module, header line) of a function without a class: the functions of the start-up and shut-down areas of
    global objects (thousands of look-alikes) by 64 KiB page, the others free_functions."""
    import scope
    addr = int(n[4:], 16)
    for lo, hi, area, what in scope.ranges():
        if lo <= addr < hi and area == 'game-static':
            kind = 'startup_area' if what.startswith('Start-up') else 'shutdown_area'
            return (f'{kind}_{addr >> 16:04X}',
                    f'// Functions of the area "{what}" at 0x{addr >> 16:04X}xxxx, as readable C++.')
    return 'free_functions', '// Functions of no known class, as readable C++.'


def write_modules(new):
    """Adds {function: module text} to the modules of their classes; returns {function: module path}."""
    this, structs, classes = class_of()
    by_key = collections.defaultdict(dict)
    free_heads = {}
    for n, t in new.items():
        key = this.get(n)
        if key is None:
            module, line = free_module(n)
            free_heads[module] = line
            key = 'free:' + module
        by_key[key][n] = t
    os.makedirs(PROMOTED, exist_ok=True)
    where = {}
    for key, funcs in by_key.items():
        if key.startswith('free:'):
            struct = key[5:]
            head = '\n'.join([free_heads[struct], '//', *MODULE_HEADER_LINES, '#include "lifted/lifted.h"',
                              '#include "lifted/classes.h"', '#include "lifted/native_decls.h"'])
        else:
            struct = structs.get(key, f'C_{key}')
            head = header_for(struct, key, classes.get(key))
        path = module_path(struct)
        have = {}
        if os.path.exists(path):
            head, have = split_module(open(path, encoding='utf-8').read())
            head = refresh_header(head)
        have.update(funcs)
        order = sorted(have, key=lambda n: int(n[4:], 16))
        text = head + '\n\n' + '\n\n'.join(have[n] for n in order) + '\n'
        with open(path, 'w', encoding='utf-8', newline='\n') as f:
            f.write(text)
        for n in funcs:
            where[n] = path
    return where


def module_functions(only=None):
    """{function: (module path, text)} of every promoted function."""
    out = {}
    if not os.path.isdir(PROMOTED):
        return out
    for f in sorted(os.listdir(PROMOTED)):
        if f.endswith('.cpp') and (only is None or f[:-4] in only):
            p = os.path.join(PROMOTED, f)
            for n, t in split_module(open(p, encoding='utf-8').read())[1].items():
                out[n] = (p, t)
    return out


# ---- checking --------------------------------------------------------------------------------------------------

def earlier_results(tag, texts):
    """Verdicts of an earlier (interrupted) run of the same check for functions whose text is unchanged."""
    d = os.path.join(WORK, tag)
    res = os.path.join(d, 'results.txt')
    out = {}
    if not os.path.exists(res):
        return out
    for line in open(res, encoding='utf-8'):
        n, _, why = line.rstrip('\n').partition('\t')
        p = os.path.join(d, n + '.cpp')
        if n in texts and why and not why.startswith('NOT TESTED') and os.path.exists(p) and \
                open(p, encoding='utf-8').read() == texts[n] + '\n':
            out[n] = why
    return out


def verify(texts, tag, jobs):
    """Checks {function: check-form text} on profiles 0-5; {function: verdict}. Functions an interrupted
    earlier run already checked in the same form keep their verdict. Promoted code also has to leave the
    registers its callers read after the return as the original does (check.py --outputs); the result
    directories carry '-o' so verdicts of the older check without it are never reused."""
    tag += '-o'
    done = earlier_results(tag, texts)
    if done:
        print(f'  {tag}: {len(done)} verdicts kept from the earlier run, {len(texts) - len(done)} to check')
    texts = {n: t for n, t in texts.items() if n not in done}
    if not texts:
        return done
    d = os.path.join(WORK, tag)
    keep = os.path.join(WORK, tag + '.done')
    if done:   # (the earlier run's files move aside: the new run writes its own results.txt)
        shutil.rmtree(keep, ignore_errors=True)
        shutil.copytree(d, keep)
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    for n, t in texts.items():
        with open(os.path.join(d, n + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(t + '\n')
    r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'rewrite', 'check.py'), '--dir', d,
                        '--profiles', PROFILES, '--jobs', str(jobs), '--outputs'], capture_output=True, text=True)
    if r.returncode:
        print(r.stdout[-1500:], r.stderr[-1500:])
    out = {}
    res = os.path.join(d, 'results.txt')
    if os.path.exists(res):
        for line in open(res, encoding='utf-8'):
            n, _, why = line.rstrip('\n').partition('\t')
            out[n] = why
    if done:
        # the directory keeps every function checked so far, so a further interruption loses nothing either
        for n, why in done.items():
            shutil.copy(os.path.join(keep, n + '.cpp'), os.path.join(d, n + '.cpp'))
        out.update(done)
        with open(res, 'w', encoding='utf-8') as f:
            for n in sorted(out):
                f.write(f'{n}\t{out[n]}\n')
        shutil.rmtree(keep, ignore_errors=True)
    return out


def stored_rewrites(only=None):
    out = {}
    for f in sorted(os.listdir(REWRITTEN)):
        if f.startswith('sub_') and f.endswith('.cpp') and (only is None or f[:-4] in only):
            out[f[:-4]] = open(os.path.join(REWRITTEN, f), encoding='utf-8').read()
    return out


def cmd_build(a):
    # modules take the names applied to the lifted code (classes.h, native_decls.h): not a dictionary in between
    import apply_names
    applied = os.path.join(LIFT, 'cache', 'applied_names.json')
    if os.path.exists(applied) and json.load(open(applied, encoding='utf-8')) != json.loads(json.dumps(
            apply_names.current())):
        sys.exit('the dictionary has changes not applied yet: run tools/lift/apply_names.py first')
    only = {l.strip() for l in open(a.funcs) if l.strip()} if a.funcs else None
    src = {n: t for n, t in stored_rewrites(only).items() if not chunks.promoted(n)}
    print(f'{len(src)} rewrites to promote')
    base = {n: module_form(n, t) for n, t in src.items()}
    clean, dropped = {}, 0
    for n, t in base.items():
        c, k = drop_handovers(t)
        if k:
            clean[n] = c
            dropped += k
    print(f'cleaner form: {dropped} register hand-overs dropped in {len(clean)} functions; checking both forms')
    t0 = time.time()
    res_clean = verify({n: check_form(n, t) for n, t in clean.items()}, 'clean', a.jobs) if clean else {}
    retry = {n: t for n, t in base.items() if res_clean.get(n) != 'OK'}
    res_base = verify({n: check_form(n, t) for n, t in retry.items()}, 'base', a.jobs) if retry else {}
    final, failed = {}, {}
    for n in base:
        if res_clean.get(n) == 'OK':
            final[n] = clean[n]
        elif res_base.get(n) == 'OK':
            final[n] = base[n]
        else:
            failed[n] = res_base.get(n) or res_clean.get(n) or 'not checked'
    print(f'checked in {time.time() - t0:.0f} s: {len(final)} pass on every profile '
          f'({sum(1 for n in final if final[n] is clean.get(n))} in the cleaner form), {len(failed)} do not')
    os.makedirs(WORK, exist_ok=True)
    with open(os.path.join(WORK, 'not_promoted.txt'), 'w', encoding='utf-8') as f:
        for n, why in sorted(failed.items()):
            f.write(f'{n}\t{why}\n')
    if a.dry_run or not final:
        return
    where = write_modules(final)
    chunks._promoted = None
    keep = os.path.join(WORK, 'sources')
    os.makedirs(keep, exist_ok=True)
    for n in final:
        shutil.move(os.path.join(REWRITTEN, n + '.cpp'), os.path.join(keep, n + '.cpp'))
    by_file = collections.defaultdict(set)
    for n in final:
        by_file[chunks.file_of(n)].add(n)
    written = sum(chunks.update(fi, {}, remove=ns) for fi, ns in by_file.items() if fi is not None)
    with open(os.path.join(REWRITTEN, 'manifest.tsv'), 'a', encoding='utf-8') as f:
        for n in sorted(final):
            f.write(f'{n}\tpromoted\t{time.strftime("%Y-%m-%d %H:%M")}\t'
                    f'{os.path.relpath(where[n], ROOT).replace(os.sep, "/")}\n')
    print(f'{len(final)} functions in {len(set(where.values()))} modules ({PROMOTED}); {written} lifted files '
          f'rewritten without them; not promoted: {os.path.join(WORK, "not_promoted.txt")}')
    print('next: tools/lift/update.ps1 -Build, the game checks, then promote.py review')


def cmd_check(a):
    funcs = module_functions({a.module} if a.module else None)
    res = verify({n: check_form(n, t) for n, (p, t) in funcs.items()}, 'recheck', a.jobs)
    bad = {n: r for n, r in res.items() if r != 'OK'}
    print(f'{len(funcs)} module functions: {len(funcs) - len(bad)} OK on every profile')
    for n, r in sorted(bad.items()):
        print(f'  {n} ({os.path.basename(funcs[n][0])}): {r[:200]}')
    return 1 if bad else 0


# ---- review ----------------------------------------------------------------------------------------------------

def lifter_texts(names):
    """The lifter's own exact output for these functions (what the rewrite has to match)."""
    import lift
    out = {}
    by_file = collections.defaultdict(set)
    for n in names:
        by_file[chunks.file_of(n)].add(n)
    paths = {int(p.split('.')[-2]): p for p in lift.generated_files()}
    for fi, ns in by_file.items():
        if fi is None:
            continue
        for fn in lift.read_file(paths[fi], only=ns):
            if fn.name in ns:
                try:
                    out[fn.name] = '\n'.join(lift.lift_function(fn))
                except Exception as e:   # noqa: BLE001
                    out[fn.name] = f'(lifter failed: {e})'
    return out


_CALLEE = re.compile(r'\b([A-Za-z_]\w*)\(ctx, base')
_ADDR = re.compile(r'\b0x(8[23][0-9A-Fa-f]{6})\b')
_REG_WRITE = re.compile(r'\bctx\.([rf]\d+|xer\.ca|cr\d)\.?\w*\s*=(?!=)')
_EPILOGUE = re.compile(r'^\s*(?:$|//|stack = PopStackFrame\(|ctx\.r1\.u64 = stack;|loc_[0-9A-F]+:|\}\s*$)')


def return_writebacks(text):
    """Registers a function leaves set for its callers: register writes right before a `return` (the checker
    compares only the returned value, so a dropped write-back that a caller reads is invisible to it)."""
    lines = text.split('\n')
    out = set()
    for i, line in enumerate(lines):
        if 'UseLiftedCode' in line or ENTRY_RE.match(line) or not re.search(r'\breturn\b', line):
            continue
        out.update(r for r in _REG_WRITE.findall(line.split('return')[0]) if r != 'r1')
        j = i - 1
        while j >= 0:
            regs_here = [r for r in _REG_WRITE.findall(lines[j])]
            if regs_here and re.match(r'^\s*ctx\.', lines[j]):
                out.update(r for r in regs_here if r != 'r1')
            elif not _EPILOGUE.match(lines[j]):
                break
            j -= 1
    return out


def flags(name, text, lifted):
    """Static differences worth a reviewer's look (the checker compared behaviour; these point at paths it may
    not have reached)."""
    import loadchain
    out = []
    own = {name, f'__imp__{name}', f'{name}_original'}
    a = collections.Counter(m for m in _CALLEE.findall(lifted) if m not in own)
    b = collections.Counter(m for m in _CALLEE.findall(text) if m not in own)
    if set(a) - set(b):
        out.append('calls in the lifted code missing here: ' + ', '.join(sorted(set(a) - set(b))))
    if set(b) - set(a):
        out.append('calls here that the lifted code does not make: ' + ', '.join(sorted(set(b) - set(a))))
    ca = {x.upper() for x in _ADDR.findall(lifted)}
    cb = {x.upper() for x in _ADDR.findall(text)}
    if ca - cb:
        out.append('game addresses in the lifted code missing here: ' + ', '.join(sorted(ca - cb)))
    da, db = loadchain.deepest(lifted), loadchain.deepest(text)
    if db < da:
        out.append(f'deepest chain of dependent loads {db}, lifted code {da}')
    wa, wb = return_writebacks(lifted), return_writebacks(text)
    if wa - wb:
        out.append('registers the lifted code sets for its callers at a return, not set here (the checker does '
                   'not compare them): ' + ', '.join(sorted(wa - wb, key=lambda r: (r[0], len(r), r))))
    fa, fb = lifted.count('ctx.fpscr.'), text.count('ctx.fpscr.')
    if fa > fb:
        out.append(f'floating-point mode switches (ctx.fpscr) in the lifted code: {fa}, here: {fb}')
    return out


def debt(text):
    body = [l for l in text.split('\n') if 'UseLiftedCode' not in l and not ENTRY_RE.match(l)]
    return {
        'hand-overs': sum(1 for l in body if HANDOVER_RE.match(l)),
        'read-backs': sum(1 for l in body if re.search(r'=\s*ctx\.(?:r(?:[3-9]|10)|f\d+)\.', l)),
        'raw loads/stores': sum(len(re.findall(r'\b(?:LOAD|STORE)(?:8|16|32|64|_F32|_F64)\(', l)) for l in body),
        'argN names': len(set(re.findall(r'\b(?:arg|floatArg)\d+\b', text))),
        'unnamed calls': len(set(re.findall(r'\bn_sub_[0-9A-F]{8}\(', text))),
        'indirect calls': sum(1 for l in body if 'REX_CALL_INDIRECT' in l),
    }


def cmd_review(a):
    sys.path.insert(0, os.path.join(ROOT, 'tools', 'rewrite'))
    funcs = module_functions({a.module} if a.module else None)
    lifted = lifter_texts(list(funcs))
    out_dir = os.path.join(ROOT, 'build', 'rewrite', 'review')
    os.makedirs(out_dir, exist_ok=True)
    by_mod = collections.defaultdict(list)
    for n, (p, t) in funcs.items():
        by_mod[p].append(n)
    total_flags = 0
    index = []
    for p, ns in sorted(by_mod.items()):
        mod = os.path.basename(p)[:-4]
        parts = [f'# Review: {mod} ({len(ns)} functions)\n', open(os.path.join(ROOT, 'docs', 'promoted-code.md'),
                 encoding='utf-8').read().split('<!-- checklist -->')[1].split('<!-- /checklist -->')[0].strip(), '']
        nflag = 0
        for n in sorted(ns, key=lambda x: int(x[4:], 16)):
            t = funcs[n][1]
            lt = lifted.get(n, '(not lifted)')
            fl = flags(n, t, lt)
            nflag += bool(fl)
            parts.append(f'## {n}\n')
            parts.append('Flags: ' + ('; '.join(fl) if fl else 'none'))
            parts.append('\n**Module text:**\n```cpp\n' + t + '\n```\n')
            parts.append("**Lifter's exact output:**\n```cpp\n" + lt + '\n```\n')
        total_flags += nflag
        path = os.path.join(out_dir, mod + '.md')
        with open(path, 'w', encoding='utf-8') as f:
            f.write('\n'.join(parts))
        index.append(f'{mod}\t{len(ns)}\t{nflag}')
    with open(os.path.join(out_dir, 'index.tsv'), 'w', encoding='utf-8') as f:
        f.write('module\tfunctions\tflagged\n' + '\n'.join(index) + '\n')
    print(f'{len(funcs)} functions in {len(by_mod)} review packets ({total_flags} flagged) -> {out_dir}')


def cmd_lint(a):
    funcs = module_functions()
    per = collections.defaultdict(collections.Counter)
    problems = []
    for n, (p, t) in funcs.items():
        per[os.path.basename(p)[:-4]].update(debt(t))
        if GHIDRA_RE.search(t):
            problems.append(f'{n}: decompiler-style names')
        if chunks.MARK in t:
            problems.append(f'{n}: lifter marker')
        for line in t.split('\n'):
            i = line.find('//')
            if i >= 0 and '"' in line[i:]:
                problems.append(f'{n}: comment quoting text: {line.strip()[:80]}')
    keys = ['hand-overs', 'read-backs', 'raw loads/stores', 'argN names', 'unnamed calls', 'indirect calls']
    count = collections.Counter(os.path.basename(p)[:-4] for p, _ in funcs.values())
    # functions the default configuration never runs (always-off lift ranges: they fall back to the recompiled
    # original, so neither the game checks nor players exercise them), and the recorded review
    off = always_off_ranges()
    inactive = collections.Counter(os.path.basename(p)[:-4] for n, (p, _) in funcs.items()
                                   if any(lo <= int(n[4:], 16) < hi for lo, hi in off))
    reviewed = collections.Counter()
    if os.path.exists(REVIEW_RECORD):
        for line in open(REVIEW_RECORD, encoding='utf-8').read().splitlines()[1:]:
            c = line.split('\t')
            if len(c) >= 3 and c[2] == 'OK' and c[1] in funcs:
                reviewed[c[0]] += 1
    print('module\tfunctions\treviewed\tinactive\t' + '\t'.join(keys))
    tot = collections.Counter()
    for m in sorted(per):
        tot.update(per[m])
        print(f'{m}\t{count[m]}\t{reviewed[m]}\t{inactive[m]}\t' + '\t'.join(str(per[m][k]) for k in keys))
    print(f'TOTAL\t{len(funcs)}\t{sum(reviewed.values())}\t{sum(inactive.values())}\t'
          + '\t'.join(str(tot[k]) for k in keys))
    if inactive:
        print(f'note: {sum(inactive.values())} functions lie in always-off lift ranges '
              f'({", ".join(f"{lo:08X}-{hi:08X}" for lo, hi in off)}) and never run in the default configuration')
    for p in problems:
        print('PROBLEM', p)
    return 1 if problems else 0


def always_off_ranges():
    """The lift ranges every tested configuration keeps on the recompiled code (tools/lift/auto_bisect.py
    ALWAYS_OFF, the same list as the lifted_disable_ranges default)."""
    src = open(os.path.join(LIFT, 'auto_bisect.py'), encoding='utf-8').read()
    m = re.search(r'^ALWAYS_OFF\s*=\s*\[([^\]]*)\]', src, re.M)
    out = []
    for lo, hi in re.findall(r'([0-9A-Fa-f]{8})-([0-9A-Fa-f]{8})', m.group(1) if m else ''):
        out.append((int(lo, 16), int(hi, 16)))
    return out


# ---- names -----------------------------------------------------------------------------------------------------

def snapshot(applied):
    """Called by tools/lift/apply_names.py before it applies dictionary changes, with the names applied so far
    (cache/applied_names.json): the names the modules are written with. sync() maps them to the new ones."""
    if os.path.exists(SNAPSHOT):
        return   # (an earlier apply not synced yet: its names are the ones in the modules)
    funcs = {n: f'n_sub_{a}' for a, n in applied.get('functions', {}).items()}
    _, structs, _ = class_of()   # (classes.json still holds the identifiers in effect)
    cls = {s: f'C_{k}' for k, s in structs.items() if not s.startswith('C_')}
    fields = collections.defaultdict(list)
    for key, n in applied.get('fields', {}).items():
        fields[n].append(key)
    os.makedirs(WORK, exist_ok=True)
    with open(SNAPSHOT, 'w', encoding='utf-8') as f:
        json.dump({'functions': funcs, 'classes': cls, 'fields': fields}, f)


def _field_subs(old_fields):
    """Old field name -> new name (or its offset form), where the old name belonged to one field only."""
    import names
    new = {f'{v:08X}:{o:X}': n for (v, o), n in names.load()['fields'].items()}
    subs = {}
    for name, keys in old_fields.items():
        if len(keys) != 1:
            continue   # (the same name in several classes: cannot tell which one a module means)
        k = keys[0]
        target = new.get(k) or f'm_{k.split(":")[1]}'
        if target != name:
            subs[name] = target
    return subs


def cmd_sync(a):
    """After the new names are in effect (tools/lift/apply_names.py): the modules take them."""
    if not os.path.exists(SNAPSHOT):
        print('promote sync: no name snapshot (nothing changed since the modules were written)')
        return
    old = json.load(open(SNAPSHOT, encoding='utf-8'))
    subs = dict(old['functions'])
    subs.update(old['classes'])
    fsubs = _field_subs(old.get('fields', {}))
    changed = 0
    for f in sorted(os.listdir(PROMOTED)) if os.path.isdir(PROMOTED) else []:
        if not f.endswith('.cpp'):
            continue
        p = os.path.join(PROMOTED, f)
        text = open(p, encoding='utf-8').read()
        canon = re.sub(r'\b[A-Za-z_]\w*\b', lambda m: subs.get(m.group(0), m.group(0)), text)
        new = chunks.current_names(canon)
        new = re.sub(r'(->|\.)\s*([A-Za-z_]\w*)\b', lambda m: m.group(1) + fsubs.get(m.group(2), m.group(2)), new)
        if new != text:
            with open(p, 'w', encoding='utf-8', newline='\n') as fh:
                fh.write(new)
            changed += 1
    # a class that got a name: its module file takes it too
    this, structs, _ = class_of()
    for key, s in structs.items():
        oldp, newp = module_path(f'C_{key}'), module_path(s)
        if s != f'C_{key}' and os.path.exists(oldp) and not os.path.exists(newp):
            text = open(oldp, encoding='utf-8').read().replace(f'// C_{key} (', f'// {s} (', 1)
            with open(newp, 'w', encoding='utf-8', newline='\n') as fh:
                fh.write(text)
            os.remove(oldp)
            changed += 1
    os.remove(SNAPSHOT)
    print(f'promote sync: {changed} module files updated to the current names')


def cmd_demote(a):
    funcs = module_functions()
    rev = REWRITTEN
    gone = []
    for n in a.names:
        if n not in funcs:
            print(f'{n}: not in a module')
            continue
        p, t = funcs[n]
        head, have = split_module(open(p, encoding="utf-8").read())
        head = refresh_header(head)
        have.pop(n)
        if have:
            order = sorted(have, key=lambda x: int(x[4:], 16))
            with open(p, 'w', encoding='utf-8', newline='\n') as f:
                f.write(head + '\n\n' + '\n\n'.join(have[x] for x in order) + '\n')
        else:
            os.remove(p)
        with open(os.path.join(rev, n + '.cpp.revoked'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(chunks.canonical_names(check_form(n, t)) + '\n')
        gone.append(n)
    if not gone:
        return
    with open(os.path.join(REWRITTEN, 'manifest.tsv'), 'a', encoding='utf-8') as f:
        for n in gone:
            why = getattr(a, 'reasons', {}).get(n, a.reason)
            f.write(f'{n}\tdemoted\t{time.strftime("%Y-%m-%d %H:%M")}\t{why[:200]}\n')
    chunks._promoted = None
    import run as tester
    st = tester.load_status()
    for n in gone:
        st.pop(n, None)
    tester.save_status(st)
    listing = os.path.join(WORK, 'demoted.txt')
    with open(listing, 'w') as f:
        f.write('\n'.join(gone) + '\n')
    r = subprocess.run([sys.executable, 'lift.py', '--funcs', listing, '--skip', 'overridden.txt'], cwd=LIFT,
                       capture_output=True, text=True)
    print(r.stdout.strip().split('\n')[-1] if r.stdout.strip() else r.stderr[-500:])
    print(f'demoted {len(gone)}; next: tools/lift/update.ps1 -Build')


REVIEW_RECORD = os.path.join(PROMOTED, 'REVIEW.tsv')
REVIEWED_TEXTS = os.path.join(WORK, 'reviewed_texts.json')   # local: the text each recorded review applies to


def text_digest(text):
    return hashlib.sha1(text.strip('\n').replace('\r', '').encode('utf-8')).hexdigest()[:16]


def recorded_ok():
    """{function: its REVIEW.tsv row} of the functions recorded OK."""
    out = {}
    if os.path.exists(REVIEW_RECORD):
        for line in open(REVIEW_RECORD, encoding='utf-8').read().splitlines()[1:]:
            cells = line.split('\t')
            if len(cells) >= 3 and cells[2] == 'OK':
                out[cells[1]] = cells
    return out


def reviewed_texts():
    """{function: digest of the module text its recorded review applies to}, kept by `record`. Started, the first
    time, from the modules identical to their published form (Fable2Recomp/promoted/manifest.tsv): those hold
    exactly the texts REVIEW.tsv records."""
    if os.path.exists(REVIEWED_TEXTS):
        return json.load(open(REVIEWED_TEXTS, encoding='utf-8'))
    import promoted_text
    published = promoted_text.manifest()
    ok = recorded_ok()
    out = {}
    for f in sorted(os.listdir(PROMOTED)) if os.path.isdir(PROMOTED) else []:
        p = os.path.join(PROMOTED, f)
        if not f.endswith('.cpp') or f not in published:
            continue
        if promoted_text.sha(open(p, encoding='utf-8', newline='').read()) != published[f]:
            continue
        for n, t in split_module(open(p, encoding='utf-8').read())[1].items():
            if n in ok:
                out[n] = text_digest(t)
    save_reviewed_texts(out)
    return out


def save_reviewed_texts(texts):
    os.makedirs(WORK, exist_ok=True)
    with open(REVIEWED_TEXTS, 'w', encoding='utf-8', newline='\n') as f:
        json.dump(dict(sorted(texts.items())), f, indent=0)


def write_module(p, head, funcs):
    """Writes a module from its header and {function: text} (functions in address order); removes an empty one."""
    if not funcs:
        os.remove(p)
        return
    order = sorted(funcs, key=lambda x: int(x[4:], 16))
    with open(p, 'w', encoding='utf-8', newline='\n') as f:
        f.write(head + '\n\n' + '\n\n'.join(funcs[x] for x in order) + '\n')


def cmd_record(a):
    """Applies a review (verdicts/<Module>.tsv, fixes/sub_X.cpp under --dir): FIX texts go into their modules
    and are checked again on every profile (a failing fix is undone and reported), DEMOTE verdicts are demoted,
    and REVIEW.tsv records an OK verdict for every function left in the modules."""
    vdir, fdir = os.path.join(a.dir, 'verdicts'), os.path.join(a.dir, 'fixes')
    funcs = module_functions()
    verdicts = {}
    for f in sorted(os.listdir(vdir)):
        if f.endswith('.tsv'):
            for line in open(os.path.join(vdir, f), encoding='utf-8'):
                cells = line.rstrip('\n').split('\t')
                if len(cells) >= 2 and re.fullmatch(r'sub_[0-9A-F]{8}', cells[0]):
                    verdicts[cells[0]] = (cells[1].strip().upper(), cells[2].strip() if len(cells) > 2 else '')
    missing = sorted(n for n in funcs if n not in verdicts)
    if missing and not a.partial:
        print(f'{len(missing)} module functions have no verdict: {" ".join(missing[:20])} (--partial: record the '
              'others and leave these without a review row)')
        return 1
    bad = sorted(n for n, (v, _) in verdicts.items() if v not in ('OK', 'FIX', 'DEMOTE', 'RECORDED'))
    if bad:
        print(f'unknown verdicts: {" ".join(bad)}')
        return 1
    # RECORDED: the review recorded earlier stands (review_api.py prepare leaves such functions out)
    fixes, problems = {}, {}
    ok_rows, reviewed = recorded_ok(), reviewed_texts()
    for n, (v, _) in verdicts.items():
        if v == 'RECORDED' and n in funcs:
            if n not in ok_rows:
                problems[n] = 'RECORDED, but REVIEW.tsv has no OK row for it'
            elif reviewed.get(n) != text_digest(funcs[n][1]):
                problems[n] = 'RECORDED, but its text changed since that review'
    # fixes
    for n, (v, note) in verdicts.items():
        if v != 'FIX' or n not in funcs:
            continue
        p = os.path.join(fdir, n + '.cpp')
        if not os.path.exists(p):
            problems[n] = 'FIX without a fix file'
            continue
        t = open(p, encoding='utf-8').read().strip('\n').replace('\r', '')
        old_entry = funcs[n][1].rstrip().split('\n')[-1]
        if t.split('\n')[-1] != old_entry or len(split_module(t)[1]) != 1:
            problems[n] = 'fix text is not one function ending in its unchanged PROMOTED_ENTRY line'
            continue
        fixes[n] = strip_quote_comments(t)
    if fixes:
        res = verify({n: check_form(n, t) for n, t in fixes.items()}, 'review-fix', a.jobs)
        for n in list(fixes):
            if res.get(n) != 'OK':
                problems[n] = 'fix fails the check: ' + (res.get(n) or 'no result')[:200]
                del fixes[n]
        by_module = collections.defaultdict(dict)
        for n, t in fixes.items():
            by_module[funcs[n][0]][n] = t
        for p, new in by_module.items():
            head, have = split_module(open(p, encoding='utf-8').read())
            head = refresh_header(head)
            have.update(new)
            write_module(p, head, have)
    # demotions
    demote = sorted(n for n, (v, _) in verdicts.items() if v == 'DEMOTE' and n in funcs)
    if demote:
        cmd_demote(argparse.Namespace(names=demote, reason='review',
                                      reasons={n: 'review: ' + verdicts[n][1] for n in demote}))
    # the record
    chunks._promoted = None
    left = module_functions()
    today = time.strftime('%Y-%m-%d')
    old = {}
    if os.path.exists(REVIEW_RECORD):
        for line in open(REVIEW_RECORD, encoding='utf-8').read().splitlines()[1:]:
            cells = line.split('\t')
            if len(cells) >= 3:
                old[cells[1]] = cells
    rows = []
    for n in sorted(left, key=lambda x: (os.path.basename(left[x][0]), x)):
        module = os.path.basename(left[n][0])[:-4]
        if n in problems:
            continue
        if n in verdicts and verdicts[n][0] in ('OK', 'FIX'):
            note = ('fixed: ' + verdicts[n][1]) if verdicts[n][0] == 'FIX' else verdicts[n][1].strip('- ')
            rows.append([module, n, 'OK', a.reviewer, today, note.replace('\t', ' ')[:300].rstrip()])
        elif n in old and old[n][2] == 'OK':
            rows.append([module] + old[n][1:])
    with open(REVIEW_RECORD, 'w', encoding='utf-8', newline='\n') as f:
        f.write('module\tfunction\tverdict\treviewer\tdate\tnote\n')
        for r in rows:
            f.write('\t'.join(r) + '\n')
    # the texts these reviews apply to: new verdicts on the text as it is now, earlier ones as they were
    save_reviewed_texts({r[1]: text_digest(left[r[1]][1]) if verdicts.get(r[1], ('',))[0] in ('OK', 'FIX')
                         else reviewed.get(r[1], text_digest(left[r[1]][1])) for r in rows})
    c = collections.Counter(v for v, _ in verdicts.values())
    print(f'verdicts {dict(c)}; {len(fixes)} fixes applied, {len(demote)} demoted; '
          f'{len(rows)} of {len(left)} module functions recorded OK in {REVIEW_RECORD}' +
          (f'; {len(missing)} without a verdict not recorded (--partial)' if missing else ''))
    for n, why in sorted(problems.items()):
        print(f'  needs attention: {n}: {why}')
    return 1 if problems else 0


def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest='cmd', required=True)
    b = sub.add_parser('build')
    b.add_argument('--funcs')
    b.add_argument('--jobs', type=int, default=3)
    b.add_argument('--dry-run', action='store_true')
    c = sub.add_parser('check')
    c.add_argument('--module')
    c.add_argument('--jobs', type=int, default=3)
    r = sub.add_parser('review')
    r.add_argument('--module')
    sub.add_parser('lint')
    sub.add_parser('sync')
    d = sub.add_parser('demote')
    d.add_argument('names', nargs='+')
    d.add_argument('--reason', required=True)
    rc = sub.add_parser('record')
    rc.add_argument('--dir', default=os.path.join(ROOT, 'build', 'rewrite', 'review'))
    rc.add_argument('--reviewer', required=True)
    rc.add_argument('--jobs', type=int, default=3)
    rc.add_argument('--partial', action='store_true', help='functions without a verdict get no review row (a '
                                                           'module is published once all of its functions have one)')
    a = ap.parse_args()
    fn = {'build': cmd_build, 'check': cmd_check, 'review': cmd_review, 'lint': cmd_lint, 'sync': cmd_sync,
          'demote': cmd_demote, 'record': cmd_record}[a.cmd]
    sys.exit(fn(a) or 0)


if __name__ == '__main__':
    main()
