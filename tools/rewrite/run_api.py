"""Rewrites lifted functions into clean C++ with a model over the OpenAI chat-completions protocol (DeepSeek,
OpenRouter, a local server ...), checking every answer with the differential tester and feeding failures back.

    python tools/api_keys.py set deepseek    (once: stores the key outside the repository)
    python tools/rewrite/run_api.py --list-models
    python tools/rewrite/run_api.py [--model deepseek-flash] [--packets 5] [--rounds 3] [--jobs 4]

    --url            base URL (default https://api.deepseek.com; OpenRouter: https://openrouter.ai/api/v1)
    --key NAME       the stored key (tools/api_keys.py) or environment variable NAME_API_KEY to use (default:
                     from the URL - api.deepseek.com: deepseek, openrouter.ai: openrouter)
    --api-key-env    an environment variable with the key, instead of --key
    --model          the model (default deepseek-flash); --list-models shows what the endpoint offers
    --packets N      stop after N packets (default: until the queue is done)
    --rounds N       fix rounds per function after a failed check (default 3)
    --jobs N         functions asked for in parallel (checks run one at a time)
    --workers N      packets worked on at a time (default 1): while one packet is checked the others wait for the
                     model; the checks take turns (one tester build directory)
    --keep-balance X take no new packet once the balance (api.deepseek.com) is below X, e.g. to keep enough for
                     the review (tools/rewrite/review_api.py)
    --quick          the plain relaxed check on profiles 0,1,4,5 (before 2026-10-16) instead of the promotion
                     check (profiles 0-5 and the registers callers read after the return, as promote.py checks)
    --effort E       how much the model thinks before answering: none, low, high, max (default: the provider's
                     own; DeepSeek thinks at high effort and bills the reasoning as output, tools/model_api.py)
    --max-tokens N   output limit per answer (default: 32768 with --effort none, else the provider's own)

No agent framework: for each packet (build/rewrite/packets, handed out by next_packet.py) every function is
sent with the rules (RULES.md), the reply's code block is saved as build/rewrite/answers/<packet>/sub_X.cpp,
tools/rewrite/check.py runs once for the packet, and each failing function gets its checker line back and
another try. What cannot be fixed is listed in notes.txt. Stop and restart any time: finished packets are
skipped, a packet abandoned for 90 minutes is handed out again. When the provider refuses the key or the
account is out of balance (HTTP 401/402) the run stops at once and the packet is not marked done, so the next
run offers it again. On api.deepseek.com the account balance is shown at the start and after every packet,
with the tokens so far (how many of the output tokens were reasoning, how many prompt tokens came from the
provider's cache).

The packets contain lifted game code; sending them to a hosted model sends that code to the provider.
"""
import argparse
import concurrent.futures as cf
import difflib
import json
import os
import re
import subprocess
import sys
import threading
import time
import urllib.error
import urllib.request

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import api_keys  # noqa: E402
import check as checker  # noqa: E402
import model_api  # noqa: E402
import next_packet as next_packet_mod  # noqa: E402

RULES = open(os.path.join(HERE, 'RULES.md'), encoding='utf-8').read()
SYSTEM = RULES + '''

You answer with the complete file for ONE function: a single ```cpp code block and nothing else. No prose
before or after it. The file starts with the definition line copied from the lifted code and ends with the
CPU_STATE_ENTRY line.'''
USAGE = {'prompt': 0, 'cached': 0, 'completion': 0, 'reasoning': 0, 'requests': 0}
_ULOCK = threading.Lock()
STRICT = ['--outputs', '--profiles', '0,1,2,3,4,5']   # what promote.py checks
CHECK_LOCK = threading.Lock()


class Fatal(RuntimeError):
    """The provider refuses every further request (key refused, out of balance): stop the run."""


def chat(url, key, model, messages, timeout=600, temperature=0.2, retries=4, effort=None, max_tokens=0):
    fields = model_api.request_fields(effort, max_tokens)
    body = json.dumps({'model': model, 'temperature': temperature, 'stream': False, 'messages': messages,
                       **fields}).encode()
    for attempt in range(retries):
        req = urllib.request.Request(url.rstrip('/') + '/chat/completions', data=body,
                                     headers={'Content-Type': 'application/json', 'Authorization': f'Bearer {key}'})
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                doc = json.load(r)
            with _ULOCK:
                model_api.count(USAGE, doc.get('usage'))
            choice = doc['choices'][0]
            if choice.get('finish_reason') == 'length':
                raise RuntimeError(f'the reply was cut off at the output limit (max_tokens '
                                   f'{fields.get("max_tokens", "of the provider")}; --max-tokens sets it)')
            return choice['message'].get('content') or ''
        except urllib.error.HTTPError as e:
            text = e.read().decode(errors='replace')[:300]
            if e.code in (401, 402):
                raise Fatal(f'HTTP {e.code}: {text}')
            if e.code in (429, 500, 502, 503, 504) and attempt + 1 < retries:
                time.sleep(10 * (attempt + 1))
                continue
            raise RuntimeError(f'HTTP {e.code}: {text}')
        except (urllib.error.URLError, TimeoutError) as e:
            if attempt + 1 < retries:
                time.sleep(10 * (attempt + 1))
                continue
            raise RuntimeError(str(e))


def balance(url, key):
    """The account balance as text (api.deepseek.com only), or None."""
    if 'api.deepseek.com' not in url:
        return None
    req = urllib.request.Request(url.rstrip('/') + '/user/balance', headers={'Authorization': f'Bearer {key}'})
    try:
        with urllib.request.urlopen(req, timeout=60) as r:
            doc = json.load(r)
        return ', '.join(f'{b["total_balance"]} {b["currency"]}' for b in doc.get('balance_infos', []))
    except (urllib.error.URLError, TimeoutError, ValueError, KeyError):
        return None


def list_models(url, key):
    req = urllib.request.Request(url.rstrip('/') + '/models', headers={'Authorization': f'Bearer {key}'})
    with urllib.request.urlopen(req, timeout=60) as r:
        doc = json.load(r)
    for m in doc.get('data', []):
        print(m.get('id'))


def code_block(reply):
    blocks = re.findall(r'```(?:cpp|c\+\+|c)?\s*\n(.*?)```', reply, re.S)
    if blocks:
        return max(blocks, key=len).rstrip('\n') + '\n'
    return reply.strip() + '\n' if 'CPU_STATE_ENTRY(' in reply or 'F2_LIFTED(' in reply else None


def parse_packet(path):
    """[(function name, section text)] of a packet file."""
    text = open(path, encoding='utf-8').read()
    body = text.split('\n# Packet:', 1)[1] if '\n# Packet:' in text else text
    parts = re.split(r'^### (sub_[0-9A-F]{8})', body, flags=re.M)
    return [(parts[i], '### ' + parts[i] + parts[i + 1]) for i in range(1, len(parts) - 1, 2)]


def next_packet():
    r = subprocess.run([sys.executable, os.path.join(HERE, 'next_packet.py')], cwd=ROOT, capture_output=True,
                       text=True)
    lines = r.stdout.strip().split('\n')
    if not lines or lines[0] == 'DONE':
        return None, None
    return lines[0], lines[1]


def run_check(packet, quick=False, jobs=2):
    with CHECK_LOCK:   # (one tester build directory)
        r = subprocess.run([sys.executable, os.path.join(HERE, 'check.py'), packet, '--jobs', str(jobs)]
                           + ([] if quick else STRICT), cwd=ROOT, capture_output=True, text=True)
    res = os.path.join(ROOT, 'build', 'rewrite', 'answers', packet, 'results.txt')
    out = {}
    if os.path.exists(res):
        for line in open(res, encoding='utf-8'):
            if '\t' in line:
                n, _, why = line.rstrip('\n').partition('\t')
                out[n] = why
    return out, r.stdout[-3000:]


def code_lines(text):
    out = []
    for line in text.split('\n'):
        line = line.strip()
        if line and not line.startswith('//'):
            out.append(re.sub(r'\s+', ' ', line))
    return out


def lifted_of(section):
    m = re.search(r'\*\*Lifted \(exact\):\*\*\n```cpp\n(.*?)```', section, re.S)
    return m.group(1) if m else ''


def unchanged(answer, lifted, min_lines=15, limit=0.9):
    """'NOT REWRITTEN: ...' when an answer is still the lifted code (it passes the check because it is the same
    code, but it is not the readable rewrite asked for), else None."""
    a, b = code_lines(answer), code_lines(lifted)
    if len(b) <= min_lines:
        return None
    ratio = difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()
    if ratio >= limit:
        return (f'NOT REWRITTEN: {ratio:.0%} of the answer is the lifted code unchanged. Rewrite it as readable '
                'C++: real names instead of localNN, structured control flow instead of gotos, no redundant '
                'register hand-overs.')
    # renamed but not restructured: the lifted length and most of its gotos (2026-10-18: 5 of 1,832 accepted
    # answers, three of them judged non-rewrites by review)
    ga, gb = (len(re.findall(r'\bgoto\b', t)) for t in (answer, lifted))
    if len(a) >= limit * len(b) and gb >= 3 and ga >= 0.75 * gb:
        return (f'NOT REWRITTEN: the answer keeps the lifted code\'s length ({len(a)} of {len(b)} lines) and {ga} '
                f'of its {gb} gotos: renaming is not enough. Restructure it: structured control flow, the lifter\'s '
                'flag and register machinery removed.')
    return None


def guard(outdir, funcs, results):
    """Marks answers that are the lifted code unchanged as failures, in `results` and in results.txt."""
    sections = dict(funcs)
    changed = False
    for n, why in list(results.items()):
        p = os.path.join(outdir, n + '.cpp')
        if why == 'OK' and n in sections and os.path.exists(p):
            bad = unchanged(open(p, encoding='utf-8').read(), lifted_of(sections[n]))
            if bad:
                results[n] = bad
                changed = True
    if changed:
        with open(os.path.join(outdir, 'results.txt'), 'w', encoding='utf-8', newline='\n') as f:
            f.write(''.join(f'{n}\t{why}\n' for n, why in results.items()))
    return results


def hint(why):
    if why.startswith('NOT REWRITTEN'):
        return 'Keep exactly the behaviour; only the form changes.'
    if why.startswith('BUILD FAILED') or why.startswith('INVALID'):
        return 'Fix the error and keep the required lines exactly as in the lifted code.'
    if 'argument value' in why:
        return ('A call receives a different argument. Count the calls from 0; the argument numbers count the '
                'registers the callee reads (integer r3.. first, then floats f1.., then vectors). Often a value '
                'the callee takes through ctx (a `ctx.rN = ...` line before the call) that must stay, or an '
                'argument expression that differs from the lifted code.')
    if 'call #' in why:
        return 'The sequence of calls differs: a call is missing, extra, or in another order.'
    if 'memory differs' in why:
        return 'A store writes a different address or value than the lifted code.'
    m = re.search(r'\b(r(?:[0-9]|[12][0-9]|3[01])|f(?:[0-9]|[12][0-9]|3[01])) after return', why)
    if m and m.group(1) not in ('r3', 'f1'):
        return (f'Callers read {m.group(1)} after this function returns. Leave in {m.group(1)} what the lifted '
                f'code leaves there: keep its `ctx.{m.group(1)}.... = ...;` write-backs before each return (the '
                'function is called directly, so a register you do not write holds a stale value).')
    if 'after return' in why:
        return 'The return value differs from the lifted code.'
    if 'timeout' in why:
        return 'One version loops where the other ends: check loop conditions and 32-bit wraparound.'
    return 'Compare your code with the lifted code step by step.'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--url', default='https://api.deepseek.com')
    ap.add_argument('--key', help='stored key name (tools/api_keys.py); default: from the URL')
    ap.add_argument('--api-key-env', help='environment variable with the key, instead of --key')
    ap.add_argument('--model', default='deepseek-flash')
    ap.add_argument('--list-models', action='store_true')
    ap.add_argument('--packets', type=int, default=0, help='stop after this many packets (0: until DONE)')
    ap.add_argument('--rounds', type=int, default=3)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--temperature', type=float, default=0.2)
    ap.add_argument('--workers', type=int, default=1, help='packets worked on at a time (their checks take turns)')
    ap.add_argument('--keep-balance', type=float, default=0, help='take no new packet once the account balance '
                                                                    '(api.deepseek.com) is below this')
    ap.add_argument('--quick', action='store_true', help='plain relaxed check (profiles 0,1,4,5), not the '
                                                         'promotion check')
    model_api.add_effort_arg(ap)
    ap.add_argument('--max-tokens', type=int, default=0, help='output limit per answer (0: 32768 with --effort '
                                                              'none, else the provider\'s own)')
    a = ap.parse_args()
    key = api_keys.key_for(a.url, a.key, a.api_key_env)
    if a.list_models:
        list_models(a.url, key)
        return
    log = open(os.path.join(ROOT, 'build', 'rewrite', f'run_api_{re.sub(r"[^A-Za-z0-9]+", "_", a.model)}.log'), 'a',
               encoding='utf-8')

    say_lock = threading.Lock()

    def say(msg):
        line = f'{time.strftime("%H:%M:%S")} {msg}'
        with say_lock:
            print(line, flush=True)
            log.write(line + '\n')
            log.flush()
    money = balance(a.url, key)
    say(f'model {a.model}, effort {a.effort or "default"}, {"plain relaxed" if a.quick else "promotion"} check, '
        f'{a.workers} packet(s) at a time' +
        (f'; balance {money}' if money else ''))
    t0 = time.time()
    counts = {'done': 0}
    stop = threading.Event()
    take = threading.Lock()

    def worker():
        while not stop.is_set():
            with take:
                if a.packets and counts['done'] + counts.get('taken', 0) >= a.packets:
                    return
                packet, path = next_packet()
                if packet is None:
                    return
                counts['taken'] = counts.get('taken', 0) + 1
            funcs = parse_packet(path)
            outdir = os.path.join(ROOT, 'build', 'rewrite', 'answers', packet)
            os.makedirs(outdir, exist_ok=True)
            psay = (lambda msg, p=packet: say(f'[{p}] {msg.strip()}')) if a.workers > 1 else say
            say(f'packet {packet}: {len(funcs)} functions')
            try:
                run_packet(a, key, psay, packet, funcs, outdir)
            except Fatal as e:
                # the packet is not done: the next run offers it again and keeps the answers already written
                with open(os.path.join(outdir, next_packet_mod.STOPPED), 'w', encoding='utf-8') as f:
                    f.write(f'{time.strftime("%Y-%m-%d %H:%M")}\t{e}\n')
                if not stop.is_set():
                    say(f'stopped: the provider refuses further requests ({e}); unfinished packets are offered '
                        'again next run')
                stop.set()
                return
            with take:
                counts['done'] += 1
                counts['taken'] -= 1
            money = balance(a.url, key)
            say(f'  {counts["done"]} packets done; tokens so far {model_api.describe(USAGE)} '
                f'({(time.time() - t0) / 60:.0f} min)' +
                (f'; balance {money}' if money else ''))
            left = re.match(r'[\d.]+', money or '')
            if a.keep_balance and left and float(left.group()) < a.keep_balance and not stop.is_set():
                say(f'balance below {a.keep_balance}: no new packets (the ones being worked on are finished)')
                stop.set()
    threads = [threading.Thread(target=worker, daemon=True) for _ in range(max(1, a.workers))]
    for t in threads:
        t.start()
    for t in threads:
        t.join()
    if not stop.is_set():
        say('queue done' if not a.packets or counts['done'] < a.packets else f'{a.packets} packets done')
    say(f'finished: {counts["done"]} packets; tokens {model_api.describe(USAGE)}')


def run_packet(a, key, say, packet, funcs, outdir):
    """Asks for every function of the packet (reusing answers a stopped run already wrote), checks, fixes."""
    history = {}
    todo = []
    for name, section in funcs:
        msgs = [{'role': 'system', 'content': SYSTEM},
                {'role': 'user', 'content': 'Rewrite this function.\n\n' + section}]
        have = os.path.join(outdir, name + '.cpp')
        if os.path.exists(have):
            msgs.append({'role': 'assistant', 'content': '```cpp\n' + open(have, encoding='utf-8').read() + '```'})
            history[name] = msgs
        else:
            todo.append((name, msgs))
    if len(todo) < len(funcs):
        say(f'  {len(funcs) - len(todo)} answers from an earlier run kept')

    def ask(item):
        name, msgs = item
        try:
            reply = chat(a.url, key, a.model, msgs, temperature=a.temperature, effort=a.effort,
                         max_tokens=a.max_tokens)
        except Fatal:
            raise
        except RuntimeError as e:
            return name, msgs, None, str(e)
        msgs.append({'role': 'assistant', 'content': reply})
        return name, msgs, code_block(reply), None
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        for name, msgs, code, err in ex.map(ask, todo):
            history[name] = msgs
            if err:
                say(f'  {name}: request failed: {err}')
                continue
            if code is None:
                say(f'  {name}: no code block in the reply')
                continue
            with open(os.path.join(outdir, name + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
                f.write(code)
    results = guard(outdir, funcs, run_check(packet, a.quick)[0])
    ok = sum(1 for v in results.values() if v == 'OK')
    say(f'  check: {ok} of {len(funcs)} OK')
    for rnd in range(1, a.rounds + 1):
        failing = [(n, why) for n, why in results.items() if why != 'OK' and n in history]
        if not failing:
            break
        say(f'  fix round {rnd}: {len(failing)} functions')

        def fix(item):
            name, why = item
            msgs = history[name]
            msgs.append({'role': 'user', 'content': f'The checker reports for {name}:\n{why}\n\n{hint(why)}\n'
                         'Reply with the corrected complete file in one ```cpp block.'})
            try:
                reply = chat(a.url, key, a.model, msgs, temperature=a.temperature, effort=a.effort,
                             max_tokens=a.max_tokens)
            except Fatal:
                raise
            except RuntimeError as e:
                return name, None, str(e)
            msgs.append({'role': 'assistant', 'content': reply})
            return name, code_block(reply), None
        with cf.ThreadPoolExecutor(a.jobs) as ex:
            for name, code, err in ex.map(fix, failing):
                if err or code is None:
                    say(f'  {name}: {err or "no code block"}')
                    continue
                with open(os.path.join(outdir, name + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
                    f.write(code)
        results = guard(outdir, funcs, run_check(packet, a.quick)[0])
        ok = sum(1 for v in results.values() if v == 'OK')
        say(f'  check: {ok} of {len(funcs)} OK')
    left = {n: why for n, why in results.items() if why != 'OK'}
    for name, _ in funcs:
        if name not in results:
            left[name] = 'no answer'
    with open(os.path.join(outdir, 'notes.txt'), 'w', encoding='utf-8') as f:
        f.write(f'model {a.model}, effort {a.effort or "default"}, {a.rounds} fix rounds, '
                f'{"plain relaxed" if a.quick else "promotion"} check\n')
        for n, why in sorted(left.items()):
            f.write(f'{n}\t{why}\n')
    say(f'  packet done: {len(funcs) - len(left)} of {len(funcs)} accepted')


if __name__ == '__main__':
    main()
