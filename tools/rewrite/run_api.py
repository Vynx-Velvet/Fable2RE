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

No agent framework: for each packet (build/rewrite/packets, handed out by next_packet.py) every function is
sent with the rules (RULES.md), the reply's code block is saved as build/rewrite/answers/<packet>/sub_X.cpp,
tools/rewrite/check.py runs once for the packet, and each failing function gets its checker line back and
another try. What cannot be fixed is listed in notes.txt. Stop and restart any time: finished packets are
skipped, a packet abandoned for 90 minutes is handed out again.

The packets contain lifted game code; sending them to a hosted model sends that code to the provider.
"""
import argparse
import concurrent.futures as cf
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

RULES = open(os.path.join(HERE, 'RULES.md'), encoding='utf-8').read()
SYSTEM = RULES + '''

You answer with the complete file for ONE function: a single ```cpp code block and nothing else. No prose
before or after it. The file starts with the definition line copied from the lifted code and ends with the
CPU_STATE_ENTRY line.'''
USAGE = {'prompt': 0, 'completion': 0, 'requests': 0}
_ULOCK = threading.Lock()


def chat(url, key, model, messages, timeout=600, temperature=0.2, retries=4):
    body = json.dumps({'model': model, 'temperature': temperature, 'stream': False, 'messages': messages}).encode()
    for attempt in range(retries):
        req = urllib.request.Request(url.rstrip('/') + '/chat/completions', data=body,
                                     headers={'Content-Type': 'application/json', 'Authorization': f'Bearer {key}'})
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                doc = json.load(r)
            u = doc.get('usage', {})
            with _ULOCK:
                USAGE['prompt'] += u.get('prompt_tokens', 0)
                USAGE['completion'] += u.get('completion_tokens', 0)
                USAGE['requests'] += 1
            return doc['choices'][0]['message']['content']
        except urllib.error.HTTPError as e:
            text = e.read().decode(errors='replace')[:300]
            if e.code in (429, 500, 502, 503, 504) and attempt + 1 < retries:
                time.sleep(10 * (attempt + 1))
                continue
            raise RuntimeError(f'HTTP {e.code}: {text}')
        except (urllib.error.URLError, TimeoutError) as e:
            if attempt + 1 < retries:
                time.sleep(10 * (attempt + 1))
                continue
            raise RuntimeError(str(e))


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


def run_check(packet):
    r = subprocess.run([sys.executable, os.path.join(HERE, 'check.py'), packet, '--jobs', '2'], cwd=ROOT,
                       capture_output=True, text=True)
    res = os.path.join(ROOT, 'build', 'rewrite', 'answers', packet, 'results.txt')
    out = {}
    if os.path.exists(res):
        for line in open(res, encoding='utf-8'):
            if '\t' in line:
                n, _, why = line.rstrip('\n').partition('\t')
                out[n] = why
    return out, r.stdout[-3000:]


def hint(why):
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
    a = ap.parse_args()
    key = api_keys.key_for(a.url, a.key, a.api_key_env)
    if a.list_models:
        list_models(a.url, key)
        return
    log = open(os.path.join(ROOT, 'build', 'rewrite', f'run_api_{re.sub(r"[^A-Za-z0-9]+", "_", a.model)}.log'), 'a',
               encoding='utf-8')

    def say(msg):
        line = f'{time.strftime("%H:%M:%S")} {msg}'
        print(line, flush=True)
        log.write(line + '\n')
        log.flush()
    done_packets = 0
    t0 = time.time()
    while a.packets == 0 or done_packets < a.packets:
        packet, path = next_packet()
        if packet is None:
            say('queue done')
            break
        funcs = parse_packet(path)
        outdir = os.path.join(ROOT, 'build', 'rewrite', 'answers', packet)
        os.makedirs(outdir, exist_ok=True)
        say(f'packet {packet}: {len(funcs)} functions')
        history = {}

        def ask(item):
            name, section = item
            msgs = [{'role': 'system', 'content': SYSTEM},
                    {'role': 'user', 'content': 'Rewrite this function.\n\n' + section}]
            try:
                reply = chat(a.url, key, a.model, msgs, temperature=a.temperature)
            except RuntimeError as e:
                return name, msgs, None, str(e)
            msgs.append({'role': 'assistant', 'content': reply})
            return name, msgs, code_block(reply), None
        with cf.ThreadPoolExecutor(a.jobs) as ex:
            for name, msgs, code, err in ex.map(ask, funcs):
                history[name] = msgs
                if err:
                    say(f'  {name}: request failed: {err}')
                    continue
                if code is None:
                    say(f'  {name}: no code block in the reply')
                    continue
                with open(os.path.join(outdir, name + '.cpp'), 'w', encoding='utf-8', newline='\n') as f:
                    f.write(code)
        results, _ = run_check(packet)
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
                    reply = chat(a.url, key, a.model, msgs, temperature=a.temperature)
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
            results, _ = run_check(packet)
            ok = sum(1 for v in results.values() if v == 'OK')
            say(f'  check: {ok} of {len(funcs)} OK')
        left = {n: why for n, why in results.items() if why != 'OK'}
        for name, _ in funcs:
            if name not in results:
                left[name] = 'no answer'
        with open(os.path.join(outdir, 'notes.txt'), 'w', encoding='utf-8') as f:
            f.write(f'model {a.model}, {a.rounds} fix rounds\n')
            for n, why in sorted(left.items()):
                f.write(f'{n}\t{why}\n')
        done_packets += 1
        say(f'  packet done: {len(funcs) - len(left)} of {len(funcs)} accepted; tokens so far '
            f'{USAGE["prompt"]} in / {USAGE["completion"]} out in {USAGE["requests"]} requests '
            f'({(time.time() - t0) / 60:.0f} min)')
    say(f'finished: {done_packets} packets; tokens {USAGE["prompt"]} in / {USAGE["completion"]} out')


if __name__ == '__main__':
    main()
