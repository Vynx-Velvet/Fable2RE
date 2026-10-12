"""Differential test of lifted code against the recompiled originals, one function at a time.

  python tools/lift/difftest/run.py                 test only lifted functions that changed since their last test
  python tools/lift/difftest/run.py --funcs a,b     test these functions (names, addresses or a file of names)
  python tools/lift/difftest/run.py 83 95 --all     re-test every function of these files (no files: whole game)

Results: difftest/results/status.json. Uses the objects of the release build: build it first.

Needs (checked at startup, see prerequisites()): clang++ (LLVM_ROOT, else PATH, else C:\\Program Files\\LLVM),
the recompiled code (Fable2Recomp/generated), the lifted output with lifted/native_decls.h, native_bridges.N.cpp
and classes.h, the configured and built release tree (Fable2Recomp/out/build/win-amd64-release: rexglue-sdk/
include, rexruntime.dll) and the SDK's import libraries (rexglue-sdk/out/win-amd64). The whole-game summaries
come from tools/lift/cache/summaries.pkl when this machine computed them, else from the analysis shipped with
the project (research/lift/summaries.json.gz, tools/lift/bundle.py) - as the lifter's.
"""
import glob
import os
import pickle
import re
import shutil
import subprocess
import sys
import concurrent.futures as cf

HERE = os.path.dirname(os.path.abspath(__file__))
LIFT = os.path.dirname(HERE)
ROOT = os.path.normpath(os.path.join(LIFT, '..', '..'))
REC = os.path.join(ROOT, 'Fable2Recomp')
BUILD = os.path.join(REC, 'out', 'build', 'win-amd64-release')
OBJ = os.path.join(BUILD, 'CMakeFiles', 'Fable2.dir')
OUT = os.path.join(HERE, 'build')
RESULTS = os.path.join(HERE, 'results')
# --relaxed (tools/rewrite): a rewritten function only has to make the same memory writes, the same calls with
# the arguments the callees really read (summaries 'rin'), and return the same value - not the register state
# the original leaves behind. Checked in build_relaxed with its own stubs.
RELAXED = False
# --relaxed --outputs (tools/rewrite/promote.py): also the registers callers read after the return (summaries
# 'outputs', low 32 bits), which a rewrite must leave as the original does (register write-backs at a return)
RELAXED_OUTPUTS = False
SDK = os.path.join(ROOT, 'rexglue-sdk')
sys.path.insert(0, LIFT)
import regs  # noqa: E402
# (--relaxed: what a call through a pointer is compared on)
_RELAXED_INDIRECT = sum(regs.bit(r) for r in [f'r{i}' for i in range(3, 11)] + [f'f{i}' for i in range(1, 5)]
                        + [f'v{i}' for i in range(1, 5)])

CLANG_DEFAULT = r'C:\Program Files\LLVM\bin\clang++.exe'


def find_clang():
    """clang++: from LLVM_ROOT (an LLVM installation or its bin directory) when set, else the one on PATH - the
    compiler the game build uses (CMakePresets.json: clang++) and setup_all.ps1 checks - else LLVM's default
    installation (which may be missing: prerequisites() says so). Generic variables such as LLVM_DIR are not
    read: they often name another LLVM, set for other projects, than the one the build compiles with."""
    exe = 'clang++.exe' if os.name == 'nt' else 'clang++'
    d = os.environ.get('LLVM_ROOT', '').strip().strip('"')
    if d:
        for p in (os.path.join(d, 'bin', exe), os.path.join(d, exe)):
            if os.path.isfile(p):
                return os.path.normpath(p)
    return shutil.which('clang++') or CLANG_DEFAULT


CLANG = find_clang()
INCLUDES = [REC, os.path.join(REC, 'generated'), os.path.join(SDK, 'include'),
            os.path.join(BUILD, 'rexglue-sdk', 'include'), os.path.join(SDK, 'thirdparty', 'fmt', 'include'),
            os.path.join(SDK, 'thirdparty', 'simde'), os.path.join(SDK, 'thirdparty', 'spdlog', 'include'),
            os.path.join(SDK, 'thirdparty', 'tracy', 'public'), HERE]
CFLAGS = ['-mssse3', '-msse4.1', '-O2', '-DNDEBUG', '-std=gnu++23', '-D_DLL', '-D_MT', '-Xclang',
          '--dependent-lib=msvcrt', '-DSPDLOG_COMPILED_LIB', '-DSPDLOG_FMT_EXTERNAL', '-DTRACY_ENABLE',
          '-DTRACY_ON_DEMAND', '-DTRACY_IMPORTS', '-DTRACY_DELAYED_INIT', '-DTRACY_MANUAL_LIFETIME', '-DTRACY_FIBERS',
          '-w'] + [f'-I{p}' for p in INCLUDES]
SDKLIB = os.path.join(SDK, 'out', 'win-amd64')
LIBS = [os.path.join(SDKLIB, 'rexruntime.lib'), os.path.join(SDKLIB, 'spdlog.lib'), os.path.join(SDKLIB, 'fmt.lib'),
        os.path.join(SDKLIB, 'TracyClient.lib'), '-lkernel32', '-luser32', '-ladvapi32', '-lole32', '-lws2_32',
        '-ldbghelp', '-lwinmm', '-loldnames']


def masks(bits):
    """resource bit set -> (gpr32, fpr32, vr64, cr32, xer_ca)"""
    g = (bits >> regs.INDEX['r0']) & 0xFFFFFFFF
    f = (bits >> regs.INDEX['f0']) & 0xFFFFFFFF
    v = (bits >> regs.INDEX['v0']) & 0xFFFFFFFFFFFFFFFF
    c = (bits >> regs.INDEX['cr0.lt']) & 0xFFFFFFFF
    x = (bits >> regs.INDEX['xer.ca']) & 1
    return g, f, v, c, x


SUMMARIES_PKL = os.path.join(LIFT, 'cache', 'summaries.pkl')
SUMMARIES_SOURCE = None   # (the file summaries() read: the recording stubs are made again when it is newer)


def summaries():
    """The whole-game summaries, with the same facts as the lifter: this machine's (python tools/lift/summarize.py)
    when there, else the analysis shipped with the project, loaded as lift.py loads it (tools/lift/bundle.py;
    valid only for the exact default.xex it was computed from)."""
    global SUMMARIES_SOURCE
    import summarize
    if os.path.exists(SUMMARIES_PKL):
        SUMMARIES_SOURCE = SUMMARIES_PKL
        with open(SUMMARIES_PKL, 'rb') as f:
            return summarize.apply_invariants(pickle.load(f))   # (same facts as the lifter)
    import bundle
    sm, why = bundle.load()
    if sm is None:
        raise SystemExit(f'difftest: no whole-game summaries: {why}.\nThe shipped analysis '
                         f'(research/lift/summaries.json.gz) is only valid for the default.xex it was computed from; '
                         f'for another one run python tools/lift/summarize.py (about 30 minutes).')
    SUMMARIES_SOURCE = bundle.BUNDLE
    return summarize.apply_invariants(sm)


def gen_stubs(sm):
    """Weak recording stubs for every function and kernel import (the generated objects call them)."""
    declared = re.findall(r'DECLARE_REX_FUNC\((sub_[0-9A-F]{8})\)',
                          open(os.path.join(REC, 'generated', 'Fable2_init.h'), encoding='utf-8').read())
    names = sorted(set(n for n in sm['inputs'] if not n.startswith('__')) | set(declared))
    imports = sorted(set(re.findall(r'DECLARE_REX_FUNC\((__imp__[A-Za-z][A-Za-z0-9_]*)\)',
                                    open(os.path.join(REC, 'generated', 'Fable2_init.h'), encoding='utf-8').read())))
    imports = [i for i in imports if not i.startswith('__imp__sub_')]
    lines = ['#include "difftest.h"', 'namespace f2t {', 'const CalleeInfo kCallees[] = {']
    abi = _RELAXED_INDIRECT if RELAXED else regs.ABI_INPUTS
    reads = sm.get('rin', sm['inputs']) if RELAXED else sm['inputs']
    for n in names:
        gi, fi, vi, _, _ = masks(reads.get(n, regs.ABI_INPUTS))
        gw = masks(sm.get('wide_in', {}).get(n, 0))[0]
        gm, fm, vm, cm, xm = masks(sm['mods'].get(n, regs.VOLATILE))
        addr = int(n[4:], 16) if n.startswith('sub_') else 0
        fwd = ''
        if RELAXED_OUTPUTS:   # (registers passed on unread: compared where an argument is passed through)
            gf, ff, _, _, _ = masks(sm.get('fwd', {}).get(n, 0))
            fwd = f', 0x{gf:X}u, 0x{ff:X}u'
        lines.append(f'  {{0x{addr:08X}u, 0x{gi:X}u, 0x{gw:X}u, 0x{fi:X}u, 0x{vi:X}ull, 0x{gm:X}u, 0x{fm:X}u, '
                     f'0x{vm:X}ull, 0x{cm:X}u, {xm}u{fwd}}},')
    gi, fi, vi, _, _ = masks(abi)
    gm, fm, vm, cm, xm = masks(regs.VOLATILE)
    imp_line = f'0x{gi:X}u, 0u, 0x{fi:X}u, 0x{vi:X}ull, 0x{gm:X}u, 0x{fm:X}u, 0x{vm:X}ull, 0x{cm:X}u, {xm}u'
    for k, n in enumerate(imports):
        lines.append(f'  {{0x{0xF0000000 + k:08X}u, {imp_line}}},')
    lines.append('};')
    gw_ind = masks(sm.get('ind', {}).get('wide_in', abi))[0]
    lines.append(f'const CalleeInfo kIndirectCallee = {{0xFFFFFFFFu, 0x{gi:X}u, 0x{gw_ind:X}u, 0x{fi:X}u, 0x{vi:X}ull, '
                 f'0x{gm:X}u, 0x{fm:X}u, 0x{vm:X}ull, 0x{cm:X}u, {xm}u}};')
    lines.append('}  // namespace f2t')
    for k, n in enumerate(names + imports):
        lines.append(f'extern "C" __attribute__((weak, noinline)) void {n}(PPCContext& ctx, uint8_t* base) '
                     f'{{ f2t::OnCall(f2t::kCallees[{k}], ctx); }}')
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, 'stubs.cpp'), 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines) + '\n')


def compile_(src, obj, opt=None):
    flags = [f for f in CFLAGS if not (opt and f.startswith('-O'))] + ([opt] if opt else [])
    r = subprocess.run([CLANG] + flags + ['-c', src, '-o', obj], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f'compile {src} failed:\n{r.stderr[-3000:]}')




# ---- per-function testing ------------------------------------------------------------------------------------
# results/status.json: {function: [hash of its lifted text, "OK" or the problem line]}. A function is tested again
# only when its lifted text changed (python run.py), so re-lifting a few hundred functions re-tests just those.

STATUS = os.path.join(RESULTS, 'status.json')
PROFILE = 0  # test inputs (driver.cpp g_profile): 0 sparse, 1 dense
BATCH = 128
import chunks  # noqa: E402


_CANON = None
_IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')


def _canonical(text):
    """The text with the naming dictionary's names replaced by the address-based ones they stand for: a rename
    does not change the compiled code, so it must not make a function count as changed (no re-test).
    (F2_NAMED(x) and F2_NATIVE(x) both stand for the definition; field names are mapped to m_<offset>.)"""
    global _CANON
    if _CANON is None:
        import names
        d = names.load()
        subs = {'F2_NAMED': 'F2_NATIVE'}
        for addr, n in d['functions'].items():
            subs[n] = f'n_sub_{addr:08X}'
        for v, n in d['classes'].items():
            subs[n] = f'C_{v:08X}'
        for (v, off), n in d['fields'].items():
            subs[n] = f'm_{off:X}'
        subs['CPU_STATE_ENTRY'] = 'F2_LIFTED'
        _CANON = subs
    subs = _CANON
    return _IDENT.sub(lambda m: subs.get(m.group(0), m.group(0)), text)


_PARAMS = re.compile(r'\((?:CpuState|PPCContext)& ctx, uint8_t\* base((?:, [^)]*)?)\) \{$', re.M)
_DECLS = re.compile(r'^\t+(?:constexpr )?[\w:<>]+\*? (\w+)(?:\{\}|;| = )', re.M)


def _canonical_vars(text):
    """Variable names (parameters, locals, constants) replaced by numbers in order of appearance: the readable
    names come from the dictionary and from the functions a value comes from, so renames change them, but not
    the compiled code."""
    declared = set(_DECLS.findall(text))
    m = _PARAMS.search(text)
    if m:
        declared |= {p.strip().rpartition(' ')[2] for p in m.group(1).split(',') if p.strip()}
    declared.discard('')
    order = {}
    for w in _IDENT.findall(text):
        if w in declared and w not in order:
            order[w] = f'v{len(order) + 1}'
    if not order:
        return text
    return _IDENT.sub(lambda mm: order.get(mm.group(0), mm.group(0)), text)


def block_hash(lines):
    import hashlib
    return hashlib.sha1(_canonical_vars(_canonical('\n'.join(lines))).encode()).hexdigest()[:16]


def block_hash_v1(lines):
    """The hash before variable names were left out (2026-10-05; for migrating results)."""
    import hashlib
    return hashlib.sha1(_canonical('\n'.join(lines)).encode()).hexdigest()[:16]


def raw_hash(lines):
    import hashlib
    return hashlib.sha1('\n'.join(lines).encode()).hexdigest()[:16]


def lifted_blocks(files=None):
    """{generated file: {name: block lines}} of the lifted output (all files, or these)."""
    out = {}
    for f in os.listdir(chunks.OUT_DIR):
        m = re.fullmatch(r'lifted\.(\d+)\.(\d+)\.cpp', f)
        if m and (files is None or int(m.group(1)) in files):
            out.setdefault(int(m.group(1)), {}).update(chunks.read_blocks(os.path.join(chunks.OUT_DIR, f)))
    return out


def original_bodies(idx, names):
    """Recompiled bodies (text) of these functions of generated file idx."""
    lines = open(os.path.join(REC, 'generated', f'Fable2_recomp.{idx}.cpp'), encoding='utf-8').read().split('\n')
    out, i, n = [], 0, len(lines)
    while i < n:
        m = re.match(r'DEFINE_REX_FUNC\((\w+)\) \{$', lines[i])
        if not m:
            i += 1
            continue
        j = i + 1
        while j < n and lines[j] != '}':
            j += 1
        if m.group(1) in names:
            out.append('\n'.join(lines[i:j + 1]))
        i = j + 1
    return out


def address_of(block):
    for line in block:
        m = re.match(r'(?:F2_LIFTED|CPU_STATE_ENTRY)\(\w+, 0x([0-9A-F]{8})\)', line)
        if m:
            return int(m.group(1), 16)
    raise ValueError('no F2_LIFTED line')


_ENTRY_ARG = re.compile(r'\bctx\.([rf]\d+)\b')


def _native_call_entry(line):
    """--outputs: the entry reads its arguments from the CPU state and then overwrites those registers with
    poison values before calling the function - the state a direct call from lifted code leaves (arguments
    travel as C++ parameters, the state copy is stale). A function that leaves a register its callers read only
    by not touching it, or that reads an argument back from the state, then differs from the original."""
    i = line.find('(ctx, base')
    brace = line.find('{')
    if i < 0 or brace < 0 or brace > i or not line.rstrip().endswith('}'):
        return line
    j = i + len('(ctx, base')
    args = line[j:]
    regs_ = sorted(set(_ENTRY_ARG.findall(args)), key=lambda r: (r[0], int(r[1:])))
    if not regs_:
        return line

    def poison(r):
        n = int(r[1:])
        return 0xD5AD0000D5AD0000 + n if r[0] == 'r' else 0x7FF4D5AD00000000 + n
    caps = ' '.join(f'const auto f2t_{r} = ctx.{r};' for r in regs_)
    kill = ' '.join(f'ctx.{r}.u64 = 0x{poison(r):016X}ull;' for r in regs_)
    return (line[:brace + 1] + ' ' + caps + ' ' + kill + line[brace + 1:j]
            + _ENTRY_ARG.sub(lambda m: f'f2t_{m.group(1)}', args))


def _private(block, native_call=False):
    """The function under test gets a private name (f2t_native_...), so calls to its public name - also its own
    recursive calls - reach the recording stubs as before. Readable blocks define it as `T Name(CpuState& ctx,
    uint8_t* base, ...)` and the F2_LIFTED wrapper calls it (native_call: as a direct call would, see
    _native_call_entry)."""
    out, name = [], None
    for line in block:
        m = re.match(r'^([\w:<>]+) (\w+)\(CpuState& ctx, uint8_t\* base', line)
        if m and name is None:
            name = m.group(2)
            line = line.replace(f' {name}(CpuState&', f' f2t_native_{name}(CpuState&', 1)
        elif name and line.startswith(('F2_LIFTED(', 'CPU_STATE_ENTRY(')):
            line = re.sub(r'\b' + re.escape(name) + r'\(ctx, base', f'f2t_native_{name}(ctx, base', line)
            if native_call:
                line = _native_call_entry(line)
        out.append(line)
    return out


def build_batch(tag, idx, blocks, sm):
    """Test program for some functions of generated file idx: just their recompiled and lifted bodies. Both get
    private names (__imp__sub_X / f2t_lifted_sub_X), so every call - also between them - reaches a recording
    stub (sub_X)."""
    names = sorted(blocks, key=lambda n: address_of(blocks[n]))
    lines = ['#include "difftest.h"']
    for n in names:
        lines.append(f'extern "C" void __imp__{n}(PPCContext&, uint8_t*); '
                     f'extern "C" void f2t_lifted_{n}(PPCContext&, uint8_t*);')
    lines += ['namespace f2t {', 'const TestFunc kTests[] = {']
    for n in names:
        go, fo, _, co, _ = masks(sm['outputs'].get(n, 0))
        gw = masks(sm.get('wide_out', {}).get(n, 0))[0]
        if RELAXED and RELAXED_OUTPUTS:   # (the registers callers read, 32-bit like the relaxed arguments)
            gw = 0
        elif RELAXED:   # (only the value the function returns natively)
            import lift
            sig = lift.native_sig(n)
            go, fo, co = masks(sig[1] if sig and sig[1] else 0)[0], masks(sig[1] if sig and sig[1] else 0)[1], 0
        lines.append(f'  {{0x{address_of(blocks[n]):08X}u, __imp__{n}, f2t_lifted_{n}, 0x{go:X}u, 0x{gw:X}u, '
                     f'0x{fo:X}u, 0x{co:X}u}},')
    lines += ['};', f'const size_t kTestCount = {len(names)};', '}  // namespace f2t']
    srcs = {
        f'table_{tag}.cpp': '\n'.join(lines) + '\n',
        f'orig_{tag}.cpp': '#include "Fable2_init.h"\n#undef DEFINE_REX_FUNC\n'
                           '#define DEFINE_REX_FUNC(name) REX_EXTERN(__imp__##name)\n\n'
                           + '\n\n'.join(original_bodies(idx, set(names))) + '\n',
        # (the functions under test get private names; every call they make (n_sub_Y) reaches the bridges,
        # which call the recording stubs)
        f'lift_{tag}.cpp': f'#define F2_LIFTED_FILE {idx}\n#define F2_NATIVE(name) f2t_native_##name\n'
                           '#define F2_NAMED(name) f2t_native_##name\n'
                           '#include "lifted/lifted.h"\n#include "lifted/classes.h"\n#include "lifted/native_decls.h"\n'
                           '#undef F2_LIFTED\n'
                           '#define F2_LIFTED(name, address) extern "C" void f2t_lifted_##name('
                           '[[maybe_unused]] PPCContext& __restrict ctx, uint8_t* base)\n\n'
                           + ''.join(f'inline void {n}_original(CpuState& ctx, uint8_t* base) {{ __imp__{n}(ctx, base); }}\n'
                                     for n in names if any(f'{n}_original(ctx, base)' in l for l in blocks[n]))
                           + '\n\n'.join('\n'.join(_private(blocks[n], RELAXED_OUTPUTS)) for n in names) + '\n',
    }
    objs = [os.path.join(OUT, 'driver.obj'), os.path.join(OUT, 'stubs.obj'), os.path.join(OUT, 'helpers.obj')]
    objs += BRIDGE_OBJS
    for fname, text in srcs.items():
        src = os.path.join(OUT, fname)
        with open(src, 'w', encoding='utf-8') as f:
            f.write(text)
        objs.append(src.replace('.cpp', '.obj'))
        compile_(src, objs[-1], None if fname.startswith('table') else '-O1')
    exe = os.path.join(OUT, f'difftest_{tag}.exe')
    r = subprocess.run([CLANG, '-fuse-ld=lld-link', '-o', exe] + objs + LIBS +
                       ['-Xlinker', '/subsystem:console', '-Xlinker', '/force:multiple'],
                       capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f'link difftest_{tag} failed:\n{r.stderr[-4000:]}')
    return exe, names


def run_batch(job):
    """Tests one batch; when the process dies on a function (a crash the harness cannot catch, or a timeout),
    that function is reported and testing resumes after it. Returns (tag, {name: "OK" or problem line})."""
    tag, idx, blocks, sm = job
    try:
        exe, names = build_batch(tag, idx, blocks, sm)
    except SystemExit as e:
        if len(blocks) > 1:
            # one function that does not compile must not fail the others: halve the batch until it is found
            order = sorted(blocks, key=lambda n: address_of(blocks[n]))
            half = len(order) // 2
            result = {}
            for k, part in (('a', order[:half]), ('b', order[half:])):
                result.update(run_batch((f'{tag}{k}', idx, {n: blocks[n] for n in part}, sm))[1])
            return tag, result
        errors = re.findall(r'error: ([^\n]*)', str(e))
        why = '; '.join(errors[:3]) if errors else str(e)[-300:]
        failed = {n: f'BUILD FAILED {n}: {why[:400]}' for n in blocks}
        with _EXTRA_LOCK:
            for prof in EXTRA_PROFILES:
                EXTRA_RESULTS.setdefault(prof, {}).update(failed)
        return tag, failed
    by_addr = {address_of(blocks[n]): n for n in names}
    addrs = sorted(by_addr)
    env = dict(os.environ)
    env['PATH'] = BUILD + os.pathsep + env.get('PATH', '')  # rexruntime.dll
    # one build, every profile asked for (--profiles): the test program takes the profile as an argument
    for prof in EXTRA_PROFILES:
        res = run_profile(exe, names, by_addr, addrs, env, prof)
        with _EXTRA_LOCK:
            EXTRA_RESULTS.setdefault(prof, {}).update(res)
    result = run_profile(exe, names, by_addr, addrs, env, PROFILE)
    try:
        os.remove(exe)
    except OSError:
        pass
    return tag, result


EXTRA_PROFILES = []      # (--profiles: further input profiles run on the same test programs)
EXTRA_RESULTS = {}       # profile -> {name: verdict}
_EXTRA_LOCK = __import__('threading').Lock()


def run_profile(exe, names, by_addr, addrs, env, profile):
    """Runs a built test program on one input profile; {name: "OK" or problem line}."""
    result = {}
    start = 0
    while True:
        try:
            r = subprocess.run([exe, f'{start:08X}', str(profile), '1' if RELAXED else '0'], capture_output=True, text=True, env=env,
                               timeout=300)   # (a frozen test program must not hold the whole run: 2026-10-05)
            out, rc = r.stdout, r.returncode
        except subprocess.TimeoutExpired as e:
            out, rc = (e.stdout or b'').decode() if isinstance(e.stdout, bytes) else (e.stdout or ''), -1
        tested = [int(m.group(1), 16) for m in re.finditer(r'^TEST ([0-9A-F]{8})$', out, re.M)]
        for a in tested:
            result.setdefault(by_addr[a], 'OK')
        for m in re.finditer(r'^MISMATCH sub_([0-9A-F]{8}): (.*)$', out, re.M):
            n = by_addr.get(int(m.group(1), 16))
            if n:
                result[n] = f'MISMATCH {n}: {m.group(2)}'
        if rc == 0 and re.search(r'^tested ', out, re.M):
            break
        if not tested:
            for a in addrs:
                if a >= start:
                    result.setdefault(by_addr[a], f'UNTESTED {by_addr[a]}: harness failed (exit {rc})')
            break
        bad = tested[-1]
        if rc == 3 and re.search(rf'^RESTART {bad:08X}$', out, re.M):
            if result[by_addr[bad]] == 'OK':
                result[by_addr[bad]] = f'UNTESTED {by_addr[bad]}: timed out (not compared)'
        else:
            result[by_addr[bad]] = f'CRASH {by_addr[bad]}: the test process died (exit {rc & 0xFFFFFFFF:08X})'
        nxt = [a for a in addrs if a > bad]
        if not nxt:
            break
        start = nxt[0]
    for n in names:
        result.setdefault(n, f'UNTESTED {n}: not reached')
    return result


def load_status():
    import json
    if os.path.exists(STATUS):
        with open(STATUS, encoding='utf-8') as f:
            return json.load(f)
    return {}


def save_status(st):
    import json
    os.makedirs(RESULTS, exist_ok=True)
    tmp = STATUS + '.tmp'
    with open(tmp, 'w', encoding='utf-8') as f:
        json.dump(st, f, indent=0, sort_keys=True)
    os.replace(tmp, STATUS)


BRIDGE_OBJS = []


def prerequisites():
    """What building and running the test programs needs and this machine does not have yet, in the order the
    setup makes it (tools/setup_all.ps1): [(what, where it was looked for, the step that makes it)]."""
    lifted, gen = os.path.join(REC, 'lifted'), os.path.join(REC, 'generated')

    def has(d, pattern):
        return os.path.isdir(d) and any(re.fullmatch(pattern, f) for f in os.listdir(d))
    # (setup_all.ps1 runs the lift tools in tools/lift: lift.py reads --skip relative to the current directory)
    decls_step = "tools/setup_all.ps1 step 'decls' (in tools/lift: python native_gen.py)"
    build_step = "tools/setup_all.ps1 step 'build' (tools/build.ps1 -Preset win-amd64-release -Target Fable2)"
    # (the SDK's own build - setup step 'toolchain' - and the game build both write them to rexglue-sdk/out)
    libs = [os.path.basename(lib) for lib in LIBS if lib.endswith('.lib') and not os.path.isfile(lib)]
    checks = [
        (os.path.isfile(os.path.join(lifted, 'lifted.h')), 'Fable2Recomp/lifted/lifted.h (part of this repository)',
         os.path.join(lifted, 'lifted.h'), 'git checkout -- Fable2Recomp/lifted/lifted.h'),
        (os.path.isfile(CLANG), 'clang++', CLANG, 'install LLVM/Clang 20+ (winget install LLVM.LLVM) or set LLVM_ROOT'),
        (not libs, f'the SDK import libraries {", ".join(libs)}', SDKLIB,
         "tools/setup_all.ps1 step 'toolchain' (tools/build.ps1 -Sdk) or 'build'"),
        (os.path.isfile(os.path.join(gen, 'Fable2_init.h')) and has(gen, r'Fable2_recomp\.\d+\.cpp'),
         'the recompiled code', os.path.join(gen, 'Fable2_init.h'),
         "tools/setup_all.ps1 step 'codegen' (rexglue codegen Fable2_config.toml)"),
        (os.path.isfile(os.path.join(lifted, 'classes.h')), 'the class model', os.path.join(lifted, 'classes.h'),
         "tools/setup_all.ps1 step 'classes' (in tools/lift: python lift.py --facts, then python classes.py)"),
        (os.path.isfile(os.path.join(lifted, 'native_decls.h')), 'the native declarations',
         os.path.join(lifted, 'native_decls.h'), decls_step),
        (has(lifted, r'native_bridges\.\d+\.cpp'), 'the native bridges', os.path.join(lifted, 'native_bridges.N.cpp'),
         decls_step),
        (has(lifted, r'lifted\.\d+\.\d+\.cpp'), 'the lifted output', os.path.join(lifted, 'lifted.N.M.cpp'),
         "tools/setup_all.ps1 step 'lift' (in tools/lift: python lift.py --all --skip overridden.txt)"),
        (os.path.isdir(os.path.join(BUILD, 'rexglue-sdk', 'include')), 'the configured release build tree',
         os.path.join(BUILD, 'rexglue-sdk', 'include'), build_step),
        (os.path.isfile(os.path.join(BUILD, 'rexruntime.dll')), 'rexruntime.dll of the release build',
         os.path.join(BUILD, 'rexruntime.dll'), build_step),
    ]
    return [(what, where, step) for ok, what, where, step in checks if not ok]


def check_prerequisites():
    """Stops with a list of what is missing and how to make it, instead of a failed compile deep in a run. The
    message stays short (paths relative to the repository, one line per setup step) and its last line says what
    happened: tools/rewrite/check.py and promote.py show only the end of it."""
    missing = prerequisites()
    if not missing:
        return

    def rel(p):
        try:
            r = os.path.relpath(p, ROOT)
        except ValueError:   # (another drive)
            return p
        return p if r.startswith('..') else r
    by_step = {}   # step -> what is missing (where), in the order of prerequisites()
    for what, where, step in missing:
        by_step.setdefault(step, []).append(f'{what} ({rel(where)})')
    lines = [f'difftest: cannot build the test programs on this machine yet (paths relative to {ROOT}):']
    for step, items in by_step.items():
        lines += ['  - missing: ' + '; '.join(items), '    made by: ' + step]
    lines.append(f'difftest: {len(missing)} prerequisite(s) missing (listed above, in the order to make them); '
                 f'nothing was tested. One setup step: tools/setup_all.ps1 -From <step> -To <step>')
    raise SystemExit('\n'.join(lines))


def prepare():
    sm = summaries()
    os.makedirs(OUT, exist_ok=True)
    # native entry points of all functions (tools/lift/native_gen.py): arguments -> context -> the stub
    del BRIDGE_OBJS[:]
    lifted_dir = os.path.join(REC, 'lifted')
    for f in sorted(os.listdir(lifted_dir)):
        if re.fullmatch(r'native_bridges\.\d+\.cpp', f):
            src, obj = os.path.join(lifted_dir, f), os.path.join(OUT, f.replace('.cpp', '.obj'))
            newest = max(os.path.getmtime(src), os.path.getmtime(os.path.join(lifted_dir, 'native_decls.h')),
                         os.path.getmtime(os.path.join(lifted_dir, 'lifted.h')))
            if not os.path.exists(obj) or os.path.getmtime(obj) < newest:
                compile_(src, obj, '-O1')
            BRIDGE_OBJS.append(obj)
    sp = os.path.join(OUT, 'stubs.cpp')
    if not os.path.exists(sp) or os.path.getmtime(sp) < os.path.getmtime(SUMMARIES_SOURCE):
        gen_stubs(sm)
    if RELAXED and not RELAXED_OUTPUTS:
        # build_batch asks lift.native_sig from the worker threads: load the signatures here, once. (A thread that
        # asks while another one loads them gets none - lift.signatures() - and would not compare the value the
        # function returns. Before 2026-10-10 the first batches of a --jobs >= 2 run could skip that comparison;
        # promote.py's --outputs check does not use the signatures and was not affected.)
        import lift
        lift.signatures()
    stubs_obj = os.path.join(OUT, 'stubs.obj')
    if not os.path.exists(stubs_obj) or os.path.getmtime(stubs_obj) < os.path.getmtime(sp):
        compile_(sp, stubs_obj, '-O0')  # (60,000 tiny functions: no optimisation needed)
    drv, drv_obj = os.path.join(HERE, 'driver.cpp'), os.path.join(OUT, 'driver.obj')
    newest = max(os.path.getmtime(drv), os.path.getmtime(os.path.join(HERE, 'difftest.h')),
                 os.path.getmtime(os.path.join(REC, 'lifted', 'lifted.h')))
    if not os.path.exists(drv_obj) or os.path.getmtime(drv_obj) < newest:
        compile_(drv, drv_obj)
    hp = os.path.join(OUT, 'helpers.cpp')
    if not os.path.exists(hp):
        # the compiler's register save/restore routines, wherever the recompiler put them
        bodies = []
        for fname in sorted(os.listdir(os.path.join(REC, 'generated'))):
            if not re.fullmatch(r'Fable2_recomp\.\d+\.cpp', fname):
                continue
            src = open(os.path.join(REC, 'generated', fname), encoding='utf-8').read()
            bodies += re.findall(r'(DEFINE_REX_FUNC\(__(?:save|rest)\w+\) \{.*?\n\})', src, re.S)
        with open(hp, 'w', encoding='utf-8') as f:
            f.write('#include "Fable2_init.h"\n\n' + '\n\n'.join(bodies) + '\n')
        compile_(hp, os.path.join(OUT, 'helpers.obj'))
    return sm


def parse_names(items):
    names = set()
    for item in items:
        for part in item.split(','):
            part = part.strip()
            if not part:
                continue
            if os.path.exists(part):
                names |= {l.split()[0] for l in open(part) if l.strip()}
            else:
                names.add(part if part.startswith(('sub_', 'xstart')) else 'sub_' + part.upper())
    return names


def seed_from_old_results():
    """One-time: status.json from the old per-file results (file_N.txt) and the current lifted text."""
    bad = {}
    for p in os.listdir(RESULTS):
        if re.fullmatch(r'file_\d+\.txt', p):
            for line in open(os.path.join(RESULTS, p), encoding='utf-8'):
                m = re.match(r'^(MISMATCH|CRASH|UNTESTED) (sub_[0-9A-F]{8})', line)
                if m:
                    bad[m.group(2)] = line.strip()
    st = {}
    for idx, blocks in lifted_blocks().items():
        for n, b in blocks.items():
            st[n] = [block_hash(b), bad.get(n, 'OK')]
    save_status(st)
    print(f'seeded {len(st)} functions ({sum(1 for v in st.values() if v[1] != "OK")} with problems)')


def main():
    import argparse
    import time
    ap = argparse.ArgumentParser(description='Differential test of lifted functions against the recompiled code. '
                                             'Default: test only functions whose lifted text changed since their '
                                             'last test.')
    ap.add_argument('files', nargs='*', type=int, help='limit to these generated files')
    ap.add_argument('--funcs', action='append', default=[], help='test these functions (names/addresses, '
                                                                 'comma list or a file of names)')
    ap.add_argument('--all', action='store_true', help='test everything again, changed or not')
    ap.add_argument('--failed', action='store_true', help='also re-test functions whose last result was a problem')
    ap.add_argument('--seed', action='store_true', help='one-time: build status.json from old file_N.txt results')
    ap.add_argument('--profile', type=int, default=0, help='2: zero memory, 3: small numbers; 1: dense test inputs (more paths, more timeouts) - an '
                                                           'extra pass over functions that passed; only new '
                                                           'mismatches are recorded')
    ap.add_argument('--only-untested', action='store_true', help='with --profile: only functions the normal '
                                                                 'inputs could not compare (timed out)')
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--rewrites', help='directory of sub_X.cpp files: test these blocks in place of the lifted ones '
                                       '(results go to <dir>/results.txt, not to status.json)')
    ap.add_argument('--profiles', default='', help='with --rewrites: further profiles (comma list) run on the same '
                                                   'test programs; results_pN.txt each')
    ap.add_argument('--relaxed', action='store_true', help='compare memory, calls (arguments the callees really '
                                                           'read) and the return value only (tools/rewrite)')
    ap.add_argument('--outputs', action='store_true', help='with --relaxed: call the function as lifted code does '
                    '(arguments natively, their registers in the CPU state stale), compare the registers callers '
                    'read after the return (low 32 bits) and arguments passed through to callees that only pass '
                    'them on (tools/rewrite/promote.py; build_relaxed_out)')
    ap.add_argument('--out', help='build directory for the test programs (default: build, or build_relaxed)')
    args = ap.parse_args()
    if args.seed:
        seed_from_old_results()
        return
    check_prerequisites()
    global PROFILE, RELAXED, RELAXED_OUTPUTS, OUT
    PROFILE = args.profile
    RELAXED = args.relaxed
    RELAXED_OUTPUTS = args.relaxed and args.outputs
    # (--outputs has its own directory: its stubs carry the pass-through masks)
    OUT = args.out or (os.path.join(HERE, 'build_relaxed_out' if RELAXED_OUTPUTS else 'build_relaxed') if RELAXED
                       else OUT)
    rewrites = None
    if args.rewrites:
        rewrites = {}
        for p in sorted(glob.glob(os.path.join(args.rewrites, 'sub_*.cpp'))):
            n = os.path.basename(p)[:-4]
            lines = open(p, encoding='utf-8', errors='replace').read().rstrip('\n').split('\n')
            # (stored rewrites hold address-form names: the names in effect now are substituted)
            rewrites[n] = chunks.current_names('\n'.join(l.rstrip('\r') for l in lines)).split('\n')
        args.funcs = [','.join(rewrites)] if rewrites else args.funcs
        if not rewrites:
            print('no sub_X.cpp files in', args.rewrites)
            return
    t0 = time.time()
    want = parse_names(args.funcs) if args.funcs else None
    if rewrites:
        want = set(rewrites)
    files = set(args.files) if args.files else None
    if want is not None:
        files = {chunks.file_of(n) for n in want} - {None}
    st = load_status()
    todo = {}
    for idx, blocks in lifted_blocks(files).items():
        for n, b in blocks.items():
            h = block_hash(b)
            old = st.get(n)
            if rewrites is not None:
                pick = n in want   # (checking rewrites: every one, on whatever profile was asked for)
            elif PROFILE:
                # extra pass: functions that passed the normal test in their current form, or could not be
                # compared there (timed out: another profile may let their loops end)
                # (a profile already tried on this text of the function is not tried again)
                pick = (want is None or n in want) and old is not None and old[0] == h and \
                    PROFILE not in (old[2] if len(old) > 2 else ()) and \
                    (old[1].startswith('UNTESTED') or (old[1] == 'OK' and not args.only_untested))
            elif rewrites is None and chunks.rewritten(n) is not None:
                pick = False   # (a rewritten function: accepted in relaxed mode by tools/rewrite, never strictly)
                if old is None or old[0] != h or not old[1].startswith('OK'):
                    st[n] = [h, 'OK [relaxed]']
            elif want is not None:
                pick = n in want
            else:
                pick = args.all or old is None or old[0] != h or (args.failed and not old[1].startswith('OK'))
            if pick:
                todo.setdefault(idx, {})[n] = (rewrites or {}).get(n, b)
    if rewrites:
        # (a function that is not in the lifted files any more - promoted into a source module - is still tested
        # from the text given)
        present = {n for v in todo.values() for n in v}
        for n in want - present:
            idx = chunks.file_of(n)
            if idx is not None:
                todo.setdefault(idx, {})[n] = rewrites[n]
        EXTRA_PROFILES[:] = [int(x) for x in args.profiles.split(',') if x.strip() and int(x) != PROFILE]
    count = sum(len(v) for v in todo.values())
    if want is not None:
        missing = want - {n for v in todo.values() for n in v}
        if missing:
            print(f'not lifted (nothing to test): {", ".join(sorted(missing)[:20])}')
    print(f'{count} functions to test', flush=True)
    if not count:
        return
    sm = prepare()
    jobs = []
    for idx, blocks in sorted(todo.items()):
        names = list(blocks)
        for k in range(0, len(names), BATCH):
            jobs.append((f'{idx}_{k // BATCH}', idx, {n: blocks[n] for n in names[k:k + BATCH]}, sm))
    done = problems = 0
    rewrite_results = {}
    with cf.ThreadPoolExecutor(args.jobs) as ex:
        for tag, result in ex.map(run_batch, jobs):
            idx = int(tag.split('_')[0])
            if rewrites:
                for n, r in result.items():
                    rewrite_results[n] = r
                    if r != 'OK':
                        problems += 1
                    print(f'  REWRITE {n}: {r}', flush=True)
                done += len(result)
                continue
            for n, r in result.items():
                if PROFILE and r == 'OK' and st.get(n, ['', ''])[1].startswith('UNTESTED'):
                    st[n] = [block_hash(todo[idx][n]), 'OK']  # (compared on this profile's inputs)
                    continue
                if PROFILE and not r.startswith(('MISMATCH', 'CRASH')):
                    # (passed, or timed out on these inputs: the previous result stands)
                    old = st.get(n)
                    if old is not None:
                        st[n] = [old[0], old[1], sorted(set(old[2] if len(old) > 2 else []) | {PROFILE})]
                    continue
                st[n] = [block_hash(todo[idx][n]), r + (f' [profile {PROFILE}]' if PROFILE else '')]
                if r != 'OK':
                    problems += 1
                    print(' ', r, flush=True)
            done += len(result)
            save_status(st)
            print(f'[{done}/{count}] batch {tag} done ({time.time() - t0:.0f} s)', flush=True)
    print(f'tested {count} functions: {problems} problems ({time.time() - t0:.0f} s)')
    if rewrites:
        for prof, res in [(PROFILE, rewrite_results)] + sorted(EXTRA_RESULTS.items()):
            fname = 'results.txt' if not prof else f'results_p{prof}.txt'
            with open(os.path.join(args.rewrites, fname), 'w', encoding='utf-8') as f:
                for n in sorted(rewrites):
                    f.write(f'{n}\t{res.get(n, "NOT TESTED (not a lifted function, or no block)")}\n')


if __name__ == '__main__':
    main()
