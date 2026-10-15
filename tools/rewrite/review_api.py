"""Reviews the promoted modules with a model over the OpenAI chat-completions protocol (DeepSeek, OpenRouter ...).
Every fix it proposes is run through the strict check (tools/rewrite/check.py --outputs, as promote.py record
does) and failures are fed back; what the model cannot settle, where it disagrees with an earlier reviewer, and
a sample of the rest are listed for a second reviewer. The result is in the form promote.py record reads.

    python tools/api_keys.py set deepseek                             (once)
    python tools/rewrite/review_api.py prepare [--earlier DIR]        the work list, from the modules as they are
    python tools/rewrite/review_api.py run [--jobs 4] [--max N]       stop and start again any time
    python tools/rewrite/review_api.py status
    python tools/rewrite/review_api.py collect                        verdicts/, fixes/, escalate.tsv
    (second reviewer: the functions in escalate.tsv; correct verdicts/ and fixes/ where needed)
    python tools/rewrite/promote.py record --dir build/rewrite/review_api --reviewer <who>

Work directory build/rewrite/review_api/ (local: it holds lifted code). An earlier review in the same form
(DIR/verdicts/<Module>.tsv, DIR/fixes/sub_X.cpp, DIR/verified.txt = the functions a second reviewer confirmed)
is taken over for functions whose module text is unchanged:
  * confirmed verdicts stand; their fixes are only checked (a failing fix goes to the model for repair);
  * single verdicts are verified: the model sees the earlier verdict, note and fix and confirms or corrects it;
  * functions without one get a full review.
The model sees each function's module text, the lifter's exact output, the static flags of promote.py review,
the current result of the strict check and the earlier review, and answers with a verdict per function
(OK, FIX with the whole corrected function, EARLIER-FIX to take the earlier fix as it is, DEMOTE). A function
that fails the check cannot be OK, and a fix counts only when it passes the check.

The packets contain lifted game code: with a hosted model, that code is sent to the provider.
"""
import argparse
import collections
import concurrent.futures as cf
import hashlib
import json
import os
import re
import shutil
import sys
import threading
import time
import urllib.error
import urllib.request
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import api_keys  # noqa: E402
import promote  # noqa: E402

WORK = os.path.join(ROOT, 'build', 'rewrite', 'review_api')
EARLIER = os.path.join(ROOT, 'build', 'rewrite', 'review_2026-10-10')
CHUNK_FUNCS = 5
CHUNK_BYTES = 40000
SAMPLE = 10   # one function in SAMPLE that the model alone decided goes to the second reviewer as well

CHECKLIST = open(os.path.join(ROOT, 'docs', 'promoted-code.md'), encoding='utf-8').read() \
    .split('<!-- checklist -->')[1].split('<!-- /checklist -->')[0].strip()
SYSTEM = f'''You review C++ functions of the game Fable II (Xbox 360) that were rewritten from mechanically lifted
code into readable code. Each function comes as its module text (the readable version under review), the lifter's
exact output (the truth: what runs today), the result of a strict differential check and sometimes an earlier
reviewer's verdict and fix.

The lifted code: game memory is the byte array `base`, game addresses are 32-bit, LOAD32(a)/STORE32(a, v) (also
8, 16, 64, F32, F64) read and write big-endian values. `GameObject<Class>(base, addr)->field` is a field of the
object at addr. `ctx` is the CPU state: ctx.rN / ctx.fN registers, ctx.r1 the game stack pointer. A line
`ctx.rN.u64 = x;` before a call hands a value to the callee through the register file; a callee may read it even
when it is not among the call's arguments. Registers set right before a `return` are read by callers.

The check runs the module text and the original on six input profiles and compares the memory writes, the calls
with their arguments (including values passed through ctx), the return value and the registers callers read after
the return. A function whose check fails is wrong; it cannot be OK. A passing check does not prove a function
right on paths the inputs did not reach: read the code.

{CHECKLIST}

Answer for every function you are asked about, in this form and nothing else:

### sub_XXXXXXXX
VERDICT: OK | FIX | EARLIER-FIX | DEMOTE
NOTE: one or two plain sentences: what is wrong and what the fix changes, or why it is right.
```cpp
(FIX only) the whole corrected function
```

- OK: the module text is right as it is (only possible when its check passes).
- FIX: the whole corrected function in one ```cpp block. Start from the module text (or from the earlier
  reviewer's fix when there is one and it is better) and change only what is needed. Keep the first line (the
  definition) and the `if (!UseLiftedCode(...))` line exactly, and end with the module text's PROMOTED_ENTRY line
  unchanged. Keep comments true, no quoted game text.
- EARLIER-FIX: the earlier reviewer's fix is right exactly as it is (only when its check passes); no code.
- DEMOTE: the function cannot be made right with a small change; the lifter's own output is used instead.
'''


# ---- text helpers ---------------------------------------------------------------------------------------------

def digest(text):
    return hashlib.sha1(text.encode('utf-8')).hexdigest()[:16]


def norm(code):
    return code.strip('\n').replace('\r', '')


def check_text(fn, text):
    """The form promote.py record checks a fix in."""
    return promote.check_form(fn, promote.strip_quote_comments(norm(text)))


def structure_problem(text, module_text):
    """Why a fix text cannot replace the function in its module (promote.py record's rule), or None."""
    entry = module_text.rstrip().split('\n')[-1]
    t = norm(text)
    if t.split('\n')[-1] != entry:
        return f'the fix must end with the unchanged line `{entry}`'
    if len(promote.split_module(t)[1]) != 1:
        return 'the fix must be exactly one function'
    return None


def hint(why):
    if 'after return' in why:
        return ('callers read this register after the return: set it on every return path as the lifter\'s output '
                'does (`ctx.rN.u64 = value;` before `return`).')
    if 'passed through to the callee' in why or 'argument value' in why:
        return ('the callee receives a different value: keep the hand-over (`ctx.rN.u64 = value;`) before that call '
                'as in the lifter\'s output, or use the same argument expression. Calls count from 0.')
    if 'call #' in why:
        return 'the sequence of calls differs: a call is missing, extra, or in another order.'
    if why.startswith('BUILD FAILED') or why.startswith('INVALID'):
        return 'it does not compile: fix the error, keep the required lines exactly.'
    if 'store' in why or 'write' in why:
        return 'a memory write differs (address, value, or a write missing or extra).'
    if 'return' in why:
        return 'the return value differs.'
    if 'timeout' in why:
        return 'one version loops where the other ends: check loop conditions and 32-bit wraparound.'
    return 'compare it with the lifter\'s output step by step.'


def parse_reply(reply):
    """{function: {verdict, note, code}} from a reply."""
    out = {}
    parts = re.split(r'^#{2,4}\s*(sub_[0-9A-F]{8})\b.*$', reply, flags=re.M)
    for i in range(1, len(parts) - 1, 2):
        fn, body = parts[i], parts[i + 1]
        v = re.search(r'VERDICT\W*\s*(EARLIER-FIX|OK|FIX|DEMOTE)\b', body)
        note = re.search(r'NOTE\W*\s*(.+)', body)
        blocks = re.findall(r'```(?:cpp|c\+\+|c)?[ \t]*\n(.*?)```', body, re.S)
        out[fn] = {'verdict': v.group(1) if v else '', 'note': ' '.join(note.group(1).split())[:400] if note else '',
                   'code': max(blocks, key=len) if blocks else None}
    return out


# ---- the model ------------------------------------------------------------------------------------------------

USAGE = collections.Counter()
_ULOCK = threading.Lock()


def chat(url, key, model, messages, timeout=1800, retries=5, max_tokens=0):
    """(answer, finish reason). No output limit by default: a reasoning model spends part of it on its hidden
    reasoning first, and a limit that is too small leaves an empty answer."""
    payload = {'model': model, 'temperature': 0.1, 'stream': False, 'messages': messages}
    if max_tokens:
        payload['max_tokens'] = max_tokens
    for attempt in range(retries):
        req = urllib.request.Request(url.rstrip('/') + '/chat/completions', data=json.dumps(payload).encode(),
                                     headers={'Content-Type': 'application/json', 'Authorization': f'Bearer {key}'})
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                doc = json.load(r)
            u = doc.get('usage', {})
            with _ULOCK:
                USAGE['prompt'] += u.get('prompt_tokens', 0)
                USAGE['completion'] += u.get('completion_tokens', 0)
                USAGE['cached'] += u.get('prompt_cache_hit_tokens', 0)
                USAGE['requests'] += 1
            choice = doc['choices'][0]
            return choice['message'].get('content') or '', choice.get('finish_reason', '')
        except urllib.error.HTTPError as e:
            text = e.read().decode(errors='replace')[:300]
            if e.code == 400 and 'max_tokens' in text and 'max_tokens' in payload:
                payload.pop('max_tokens')   # (a model that does not take this many: its own limit)
                continue
            if e.code in (429, 500, 502, 503, 504) and attempt + 1 < retries:
                time.sleep(15 * (attempt + 1))
                continue
            raise RuntimeError(f'HTTP {e.code}: {text}')
        except (urllib.error.URLError, TimeoutError, ConnectionError) as e:
            if attempt + 1 < retries:
                time.sleep(15 * (attempt + 1))
                continue
            raise RuntimeError(str(e))
    raise RuntimeError('no answer')


# ---- prepare ----------------------------------------------------------------------------------------------------

def read_earlier(d):
    """({function: (verdict, note)}, {confirmed functions}) of an earlier review directory."""
    verdicts, confirmed = {}, set()
    vd = os.path.join(d, 'verdicts')
    if os.path.isdir(vd):
        for f in sorted(os.listdir(vd)):
            if f.endswith('.tsv'):
                for line in open(os.path.join(vd, f), encoding='utf-8'):
                    c = line.rstrip('\n').split('\t')
                    if len(c) >= 2 and re.fullmatch(r'sub_[0-9A-F]{8}', c[0]):
                        verdicts[c[0]] = (c[1].strip().upper(), c[2].strip() if len(c) > 2 else '')
    vf = os.path.join(d, 'verified.txt')
    if os.path.exists(vf):
        confirmed = {l.strip() for l in open(vf, encoding='utf-8') if l.strip()}
    return verdicts, confirmed


def earlier_texts(d):
    """{function: module text} the earlier review saw (its chunks/*.md), to tell whether a verdict still applies."""
    out = {}
    cd = os.path.join(d, 'chunks')
    if os.path.isdir(cd):
        for f in os.listdir(cd):
            t = open(os.path.join(cd, f), encoding='utf-8').read()
            for m in re.finditer(r'^## (sub_[0-9A-F]{8})\n.*?\*\*Module text:\*\*\n```cpp\n(.*?)\n```', t, re.S | re.M):
                out[m.group(1)] = m.group(2)
    return out


def cmd_prepare(a):
    if os.path.isdir(os.path.join(a.dir, 'results')) and os.listdir(os.path.join(a.dir, 'results')) and not a.force:
        sys.exit(f'{a.dir} has results of a run: --force starts over (or use another --dir)')
    shutil.rmtree(a.dir, ignore_errors=True)
    for sub in ('lifted', 'earlier_fixes', 'results', 'answers', 'fixes'):
        os.makedirs(os.path.join(a.dir, sub))
    funcs = promote.module_functions()
    print(f'{len(funcs)} promoted functions; lifting them for the comparison text ...', flush=True)
    lifted = promote.lifter_texts(list(funcs))
    checked = promote.earlier_results('recheck-o', {n: promote.check_form(n, t) for n, (p, t) in funcs.items()})
    ev, confirmed, seen = {}, set(), {}
    if a.earlier and os.path.isdir(a.earlier):
        ev, confirmed = read_earlier(a.earlier)
        seen = earlier_texts(a.earlier)
    info = {}
    for n, (p, t) in funcs.items():
        e = ev.get(n) if seen.get(n) == t else None   # (a verdict on another text does not apply)
        fix = os.path.join(a.earlier or '', 'fixes', n + '.cpp')
        if e and e[0] == 'FIX':
            if not os.path.exists(fix):
                e = None
            else:
                shutil.copy(fix, os.path.join(a.dir, 'earlier_fixes', n + '.cpp'))
        kind = 'review' if not e else 'settled' if n in confirmed else 'verify'
        with open(os.path.join(a.dir, 'lifted', n + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(lifted.get(n, '(not lifted)') + '\n')
        info[n] = {'module': os.path.basename(p)[:-4], 'kind': kind, 'text': digest(t),
                   'check': checked.get(n, 'not checked yet'),
                   'flags': promote.flags(n, t, lifted.get(n, '')),
                   'earlier': {'verdict': e[0], 'note': e[1]} if e else None}
    chunk_list = []
    by_mod = collections.defaultdict(list)
    for n in info:
        by_mod[info[n]['module']].append(n)
    for mod, ns in sorted(by_mod.items()):
        cur, size, k = [], 0, 0
        for n in sorted(ns, key=lambda x: int(x[4:], 16)):
            s = len(funcs[n][1]) + len(lifted.get(n, ''))
            if info[n]['earlier'] and info[n]['earlier']['verdict'] == 'FIX':
                s += os.path.getsize(os.path.join(a.dir, 'earlier_fixes', n + '.cpp'))
            if cur and (len(cur) >= CHUNK_FUNCS or size + s > CHUNK_BYTES):
                chunk_list.append({'id': f'{mod}.{k}', 'module': mod, 'funcs': cur})
                cur, size, k = [], 0, k + 1
            cur.append(n)
            size += s
        if cur:
            chunk_list.append({'id': f'{mod}.{k}', 'module': mod, 'funcs': cur})
    with open(os.path.join(a.dir, 'work.json'), 'w', encoding='utf-8') as f:
        json.dump({'prepared': time.strftime('%Y-%m-%d %H:%M'), 'earlier': a.earlier, 'functions': info,
                   'chunks': chunk_list}, f, indent=1)
    kinds = collections.Counter(i['kind'] for i in info.values())
    failing = sum(1 for i in info.values() if i['check'] != 'OK')
    print(f'{len(info)} functions in {len(chunk_list)} chunks: {kinds["review"]} to review, {kinds["verify"]} to '
          f'verify (one earlier verdict), {kinds["settled"]} settled (confirmed earlier; fixes only checked); '
          f'{failing} fail the strict check now -> {a.dir}')


# ---- run ----------------------------------------------------------------------------------------------------------

class Runner:
    def __init__(self, a):
        self.a = a
        self.work = json.load(open(os.path.join(a.dir, 'work.json'), encoding='utf-8'))
        self.info = self.work['functions']
        self.check_lock = threading.Lock()
        self.log = open(os.path.join(a.dir, 'run.log'), 'a', encoding='utf-8')
        self.log_lock = threading.Lock()
        self.key = api_keys.key_for(a.url, a.key, a.api_key_env)

    def say(self, msg):
        line = f'{time.strftime("%H:%M:%S")} {msg}'
        with self.log_lock:
            print(line, flush=True)
            self.log.write(line + '\n')
            self.log.flush()

    def check(self, cid, texts):
        """{function: check result} of {function: fix text}; one check at a time."""
        if not texts:
            return {}
        with self.check_lock:
            return promote.verify({n: check_text(n, t) for n, t in texts.items()}, f'review_api/{cid}',
                                  self.a.check_jobs)

    def section(self, fn, mod_text, efix, efix_check):
        i = self.info[fn]
        parts = [f'## {fn}', '',
                 'Check of the module text: ' + ('passes on every profile' if i['check'] == 'OK'
                                                 else 'FAILS: ' + i['check'][:300]),
                 'Flags: ' + ('; '.join(i['flags']) if i['flags'] else 'none')]
        e = i['earlier']
        if e:
            parts.append(f'Earlier review (another reviewer; check it, do not just trust it): {e["verdict"]}: '
                         f'{e["note"] or "-"}')
        parts += ['', '**Module text:**', '```cpp', mod_text, '```']
        if efix is not None:
            parts += ['', '**Earlier reviewer\'s fix** (check: ' + ('passes' if efix_check == 'OK'
                                                                   else 'FAILS: ' + efix_check[:300]) + '):',
                      '```cpp', norm(efix), '```']
        lifted = open(os.path.join(self.a.dir, 'lifted', fn + '.cpp'), encoding='utf-8').read().rstrip('\n')
        parts += ['', '**Lifter\'s exact output:**', '```cpp', lifted, '```', '']
        return '\n'.join(parts)

    def chunk(self, c):
        cid = c['id']
        out_path = os.path.join(self.a.dir, 'results', cid + '.json')
        if os.path.exists(out_path):
            return 'done before'
        funcs = promote.module_functions({c['module']})
        texts = {}
        for fn in c['funcs']:
            if fn not in funcs or digest(funcs[fn][1]) != self.info[fn]['text']:
                self.say(f'{cid}: {fn} changed since prepare; run prepare again (skipped)')
                return 'stale'
            texts[fn] = funcs[fn][1]
        efix = {}
        for fn in c['funcs']:
            p = os.path.join(self.a.dir, 'earlier_fixes', fn + '.cpp')
            if os.path.exists(p):
                efix[fn] = open(p, encoding='utf-8').read()
        efix_check, whole = {}, {}
        for fn, t in efix.items():
            sp = structure_problem(t, texts[fn])
            if sp:
                efix_check[fn] = 'INVALID: ' + sp
            else:
                whole[fn] = t
        found = self.check(cid + '-earlier', whole)
        efix_check.update({fn: found.get(fn) or 'no check result' for fn in whole})
        res, need = {}, []
        for fn in c['funcs']:
            i = self.info[fn]
            e = i['earlier']
            base = {'module': c['module'], 'kind': i['kind'], 'earlier': e['verdict'] if e else '', 'rounds': 0}
            if i['kind'] == 'settled':
                if e['verdict'] == 'OK' and i['check'] == 'OK':
                    res[fn] = dict(base, verdict='OK', note=e['note'], source='earlier', check='OK')
                    continue
                if e['verdict'] == 'FIX' and efix_check.get(fn) == 'OK':
                    res[fn] = dict(base, verdict='FIX', note=e['note'], source='earlier', check='OK')
                    continue
                if e['verdict'] == 'DEMOTE':
                    res[fn] = dict(base, verdict='DEMOTE', note=e['note'], source='earlier', check='')
                    continue
            need.append(fn)
        if need:
            self.ask(cid, c, need, texts, efix, efix_check, res)
        for fn, r in res.items():
            if r['verdict'] == 'FIX':
                src = os.path.join(self.a.dir, 'earlier_fixes', fn + '.cpp') if r['source'] == 'earlier' else None
                if src:
                    shutil.copy(src, os.path.join(self.a.dir, 'fixes', fn + '.cpp'))
        with open(out_path, 'w', encoding='utf-8') as f:
            json.dump(res, f, indent=1)
        v = collections.Counter(r['verdict'] + ('?' if r.get('unresolved') else '') for r in res.values())
        return ', '.join(f'{k} {n}' for k, n in sorted(v.items())) + f' (model: {len(need)})'

    def ask(self, cid, c, need, texts, efix, efix_check, res):
        intro = (f'# Review: {c["module"]} - answer for {", ".join(need)}\n\n'
                 f'(the module file is Fable2Recomp/src/game/promoted/{c["module"]}.cpp)\n')
        user = intro + '\n'.join(self.section(fn, texts[fn], efix.get(fn), efix_check.get(fn, '')) for fn in need)
        messages = [{'role': 'system', 'content': SYSTEM}, {'role': 'user', 'content': user}]
        pending, last = list(need), {}
        answers = {}
        raw = open(os.path.join(self.a.dir, 'answers', cid + '.txt'), 'a', encoding='utf-8')
        for rnd in range(self.a.rounds + 1):
            try:
                reply, finish = chat(self.a.url, self.key, self.a.model, messages, max_tokens=self.a.max_tokens)
            except RuntimeError as e:
                self.say(f'{cid}: request failed ({e}); the chunk stays open')
                raise
            raw.write(f'\n===== round {rnd} ({finish}) =====\n{reply}\n')
            raw.flush()
            parsed = parse_reply(reply)
            problems, to_check = {}, {}
            for fn in pending:
                p = parsed.get(fn)
                if not p or not p['verdict']:
                    problems[fn] = 'no answer in the required form' + (' (the reply was cut off: answer fewer '
                                                                       'functions at a time)' if finish == 'length' else '')
                    continue
                v = p['verdict']
                ck = self.info[fn]['check']
                if v == 'OK':
                    if ck != 'OK':
                        problems[fn] = f'OK is not possible: the module text fails the check ({ck[:200]}). FIX or DEMOTE.'
                    else:
                        answers[fn] = dict(p, source='model', check='OK')
                elif v == 'EARLIER-FIX':
                    if fn not in efix:
                        problems[fn] = 'there is no earlier fix for this function: answer OK, FIX or DEMOTE.'
                    elif efix_check.get(fn) != 'OK':
                        problems[fn] = f'the earlier fix fails the check ({efix_check.get(fn, "")[:200]}): FIX it.'
                    else:
                        answers[fn] = dict(p, verdict='FIX', source='earlier', check='OK', took_earlier=True)
                elif v == 'FIX':
                    if not p['code']:
                        problems[fn] = 'FIX needs the whole corrected function in a ```cpp block.'
                        continue
                    sp = structure_problem(p['code'], texts[fn])
                    if sp:
                        problems[fn] = sp + '.'
                        continue
                    to_check[fn] = p['code']
                elif v == 'DEMOTE':
                    answers[fn] = dict(p, source='model', check='')
            for fn, why in self.check(cid, to_check).items():
                if why == 'OK':
                    answers[fn] = dict(parsed[fn], source='model', check='OK')
                    with open(os.path.join(self.a.dir, 'fixes', fn + '.cpp'), 'w', encoding='utf-8',
                              newline='\n') as f:
                        f.write(norm(to_check[fn]) + '\n')
                else:
                    problems[fn] = f'your fix fails the check: {why[:300]} - {hint(why)}'
            last.update(problems)
            pending = [fn for fn in pending if fn in problems]
            if not pending:
                break
            if rnd < self.a.rounds:
                messages += [{'role': 'assistant', 'content': reply},
                             {'role': 'user', 'content': 'Not settled yet:\n' + '\n'.join(
                                 f'- {fn}: {problems[fn]}' for fn in pending)
                              + '\n\nAnswer again, in the same form, only for: ' + ', '.join(pending)}]
        raw.close()
        for fn in need:
            i = self.info[fn]
            e = i['earlier']
            base = {'module': c['module'], 'kind': i['kind'], 'earlier': e['verdict'] if e else ''}
            if fn in answers:
                p = answers[fn]
                res[fn] = dict(base, verdict=p['verdict'], note=p['note'], source=p['source'], check=p['check'],
                               took_earlier=p.get('took_earlier', False), rounds=rnd)
            else:
                res[fn] = dict(base, verdict='', note='', source='model', check='', rounds=rnd,
                               unresolved=last.get(fn, 'no answer')[:400])

    def run(self):
        chunks_ = [c for c in self.work['chunks']
                   if not os.path.exists(os.path.join(self.a.dir, 'results', c['id'] + '.json'))]
        total, open_ = len(self.work['chunks']), len(chunks_)
        if self.a.chunks:
            chunks_ = [c for c in chunks_ if c['id'] in self.a.chunks.split(',')]
        if self.a.max:
            chunks_ = chunks_[:self.a.max]
        self.say(f'{total - open_} of {total} chunks done before; {len(chunks_)} now with {self.a.model} '
                 f'({self.a.jobs} at a time, checks with {self.a.check_jobs} jobs)')
        t0 = time.time()
        done = 0
        with cf.ThreadPoolExecutor(self.a.jobs) as pool:
            futs = {pool.submit(self.chunk, c): c['id'] for c in chunks_}
            for fut in cf.as_completed(futs):
                cid = futs[fut]
                try:
                    msg = fut.result()
                except Exception as e:   # noqa: BLE001  (the chunk stays open for the next run)
                    msg = f'FAILED: {e}'
                done += 1
                self.say(f'[{done}/{len(chunks_)}] {cid}: {msg}; tokens in {USAGE["prompt"]:,} out '
                         f'{USAGE["completion"]:,}, {(time.time() - t0) / 60:.0f} min')
        self.say('run finished; next: python tools/rewrite/review_api.py collect')


def cmd_run(a):
    if not os.path.exists(os.path.join(a.dir, 'work.json')):
        sys.exit(f'no work list in {a.dir}: run prepare first')
    Runner(a).run()


# ---- status / collect -------------------------------------------------------------------------------------------

def results(d):
    out = {}
    rd = os.path.join(d, 'results')
    for f in sorted(os.listdir(rd)):
        if f.endswith('.json'):
            out.update(json.load(open(os.path.join(rd, f), encoding='utf-8')))
    return out


def escalation(fn, r):
    """Why a function's verdict needs a second reviewer, or None."""
    if r.get('unresolved'):
        return 'unresolved: ' + r['unresolved']
    if r['source'] == 'earlier' and r['kind'] == 'settled':
        return None
    if r['verdict'] == 'DEMOTE' and r['earlier'] != 'DEMOTE':
        return 'model demotes it'
    if r['kind'] == 'verify':
        agree = (r['earlier'] == r['verdict'] == 'OK' or r['earlier'] == r['verdict'] == 'DEMOTE'
                 or (r['earlier'] == 'FIX' and r.get('took_earlier')))
        if not agree:
            return f'disagrees with the earlier review ({r["earlier"]} -> {r["verdict"]}' + \
                (', new fix' if r['verdict'] == 'FIX' else '') + ')'
        return None
    if zlib.crc32(fn.encode()) % SAMPLE == 0:
        return 'sample of the model\'s own verdicts'
    return None


def cmd_status(a):
    work = json.load(open(os.path.join(a.dir, 'work.json'), encoding='utf-8'))
    res = results(a.dir)
    n_chunks = len(work['chunks'])
    done = len([f for f in os.listdir(os.path.join(a.dir, 'results')) if f.endswith('.json')])
    v = collections.Counter(r['verdict'] or 'unresolved' for r in res.values())
    esc = sum(1 for fn, r in res.items() if escalation(fn, r))
    print(f'chunks {done}/{n_chunks}; functions {len(res)}/{len(work["functions"])}: {dict(v)}; '
          f'for the second reviewer so far: {esc}')


def cmd_collect(a):
    work = json.load(open(os.path.join(a.dir, 'work.json'), encoding='utf-8'))
    res = results(a.dir)
    missing = [fn for fn in work['functions'] if fn not in res]
    vd = os.path.join(a.dir, 'verdicts')
    shutil.rmtree(vd, ignore_errors=True)
    os.makedirs(vd)
    by_mod = collections.defaultdict(list)
    for fn, r in res.items():
        by_mod[r['module']].append(fn)
    for mod, fns in by_mod.items():
        with open(os.path.join(vd, mod + '.tsv'), 'w', encoding='utf-8', newline='\n') as f:
            for fn in sorted(fns, key=lambda x: int(x[4:], 16)):
                r = res[fn]
                if r['verdict']:
                    note = ' '.join((r['note'] or '-').split()).replace('\t', ' ')[:300]
                    f.write(f'{fn}\t{r["verdict"]}\t{note}\n')
    esc = {fn: escalation(fn, r) for fn, r in res.items()}
    esc = {fn: why for fn, why in esc.items() if why}
    with open(os.path.join(a.dir, 'escalate.tsv'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('function\tmodule\tverdict\tearlier\treason\n')
        for fn in sorted(esc, key=lambda x: (res[x]['module'], x)):
            r = res[fn]
            f.write(f'{fn}\t{r["module"]}\t{r["verdict"] or "-"}\t{r["earlier"] or "-"}\t{esc[fn]}\n')
    # the fixes' check results, where promote.py record looks for them (it checks again only what changed)
    cache = os.path.join(promote.WORK, 'review-fix-o')
    shutil.rmtree(cache, ignore_errors=True)
    os.makedirs(cache)
    passed = []
    for fn, r in sorted(res.items()):
        p = os.path.join(a.dir, 'fixes', fn + '.cpp')
        if r['verdict'] == 'FIX' and r['check'] == 'OK' and os.path.exists(p):
            with open(os.path.join(cache, fn + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
                f.write(check_text(fn, open(p, encoding='utf-8').read()) + '\n')
            passed.append(fn)
    with open(os.path.join(cache, 'results.txt'), 'w', encoding='utf-8', newline='\n') as f:
        f.write(''.join(f'{fn}\tOK\n' for fn in passed))
    v = collections.Counter(r['verdict'] or 'unresolved' for r in res.values())
    reasons = collections.Counter(why.split(':')[0].split(' (')[0] for why in esc.values())
    print(f'{len(res)} of {len(work["functions"])} functions have a result: {dict(v)}')
    print(f'{len(esc)} for the second reviewer ({a.dir}/escalate.tsv): {dict(reasons)}')
    if missing:
        print(f'{len(missing)} functions not reviewed yet: run `review_api.py run` again')
    print('verdicts -> ' + vd + '; when the second review is done: python tools/rewrite/promote.py record --dir '
          + a.dir + ' --reviewer <who>')


def main():
    ap = argparse.ArgumentParser(description='Review the promoted modules with a model (see the docstring).')
    ap.add_argument('--dir', default=WORK, help='work directory (default build/rewrite/review_api)')
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('prepare')
    p.add_argument('--earlier', default=EARLIER, help='an earlier review to take over (default the 2026-10-10 one)')
    p.add_argument('--force', action='store_true')
    r = sub.add_parser('run')
    r.add_argument('--url', default='https://api.deepseek.com')
    r.add_argument('--key', help='stored key name (tools/api_keys.py); default: from the URL')
    r.add_argument('--api-key-env', help='environment variable with the key, instead of --key')
    r.add_argument('--model', default='deepseek-flash')
    r.add_argument('--jobs', type=int, default=4, help='chunks asked for at a time')
    r.add_argument('--check-jobs', type=int, default=2, help='processes per check (checks run one at a time)')
    r.add_argument('--rounds', type=int, default=3, help='feedback rounds per chunk')
    r.add_argument('--max-tokens', type=int, default=0, help='output limit per answer (0: the provider\'s own)')
    r.add_argument('--max', type=int, default=0, help='stop after this many chunks (0: all)')
    r.add_argument('--chunks', help='only these chunks (comma-separated ids from work.json)')
    sub.add_parser('status')
    sub.add_parser('collect')
    a = ap.parse_args()
    a.dir = os.path.abspath(a.dir)
    {'prepare': cmd_prepare, 'run': cmd_run, 'status': cmd_status, 'collect': cmd_collect}[a.cmd](a)


if __name__ == '__main__':
    main()
