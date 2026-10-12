"""Sends the naming batches to a model over the OpenAI chat-completions protocol and saves its answers.

    python tools/naming/run_local.py --model <name> [--url http://localhost:11434/v1] [--max 50]
    python tools/naming/run_local.py --model <provider/model> --url https://openrouter.ai/api/v1 --allow-remote
        (hosted: needs --allow-remote and the key in OPENROUTER_API_KEY; one request per batch, no agent overhead)

Works with any server that speaks the OpenAI chat-completions protocol on this machine (Ollama, LM Studio,
llama.cpp server, vLLM ...). Reads build/naming/batches/batch_NNNN.md, writes build/naming/answers/
batch_NNNN.tsv; batches that already have an answer are skipped, so the run can be stopped and continued.
Then: python tools/naming/merge.py

Only lines of the expected form are kept (F / C / M records); a model that separates the columns with spaces
instead of tabs is accepted. The raw reply is saved next to the answer as batch_NNNN.raw.txt.
"""
import argparse
import glob
import json
import os
import re
import sys
import time
import urllib.error
import urllib.request

ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
_CONF = ('high', 'medium', 'low')


def records(text):
    """The F / C / M records of a reply, normalised to tab-separated lines."""
    out = []
    for line in text.splitlines():
        line = line.strip().strip('`').strip()
        if not re.match(r'[FCML](\t| {1,}|\|)', line):
            continue
        if '\t' in line:
            cells = [c.strip() for c in line.split('\t')]
        elif '|' in line:
            cells = [c.strip() for c in line.strip('|').split('|')]
        else:
            n = 5 if line[0] in 'ML' else 4
            cells = line.split(None, n)
        want = 6 if cells[0] in 'ML' else 5
        if len(cells) != want or cells[-2].lower() not in _CONF:
            continue
        cells[-2] = cells[-2].lower()
        if cells[0] in 'FL':   # (an address written as sub_XXXXXXXX)
            cells[1] = re.sub(r'^(?:sub_|0x)', '', cells[1], flags=re.I)
        out.append('\t'.join(cells))
    return out


def ask(url, model, prompt, timeout, temperature, key='local'):
    body = json.dumps({'model': model, 'temperature': temperature, 'stream': False,
                       'messages': [{'role': 'user', 'content': prompt}]}).encode()
    req = urllib.request.Request(url.rstrip('/') + '/chat/completions', data=body,
                                 headers={'Content-Type': 'application/json', 'Authorization': f'Bearer {key}'})
    with urllib.request.urlopen(req, timeout=timeout) as r:
        doc = json.load(r)
    return doc['choices'][0]['message']['content']


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--model', required=True)
    ap.add_argument('--url', default='http://localhost:11434/v1', help='base URL of the local server')
    ap.add_argument('--batches', default=os.path.join(ROOT, 'build', 'naming', 'batches'))
    ap.add_argument('--answers', default=os.path.join(ROOT, 'build', 'naming', 'answers'))
    ap.add_argument('--max', type=int, default=0, help='stop after this many batches (0: all)')
    ap.add_argument('--timeout', type=int, default=900)
    ap.add_argument('--temperature', type=float, default=0.2)
    ap.add_argument('--allow-remote', action='store_true',
                    help='allow a hosted endpoint (for example https://openrouter.ai/api/v1): the batches, which '
                         'contain lifted game code, are sent to that provider')
    ap.add_argument('--api-key-env', default='OPENROUTER_API_KEY', help='environment variable holding the API key '
                                                                         'for a hosted endpoint')
    a = ap.parse_args()
    host = re.sub(r'^https?://', '', a.url).split('/')[0].split(':')[0]
    key = 'local'
    if host not in ('localhost', '127.0.0.1', '::1', '[::1]'):
        if not a.allow_remote:
            sys.exit(f'{a.url} is not on this machine. The batches contain lifted game code; pass --allow-remote '
                     f'to send them to this provider.')
        key = os.environ.get(a.api_key_env, '')
        if not key:
            sys.exit(f'set {a.api_key_env} to the API key for {host}')
    os.makedirs(a.answers, exist_ok=True)
    done = total = 0
    for path in sorted(glob.glob(os.path.join(a.batches, 'batch_*.md'))):
        name = os.path.basename(path)[:-3]
        out = os.path.join(a.answers, name + '.tsv')
        if os.path.exists(out):
            continue
        if a.max and done >= a.max:
            break
        prompt = open(path, encoding='utf-8').read()
        t0 = time.time()
        try:
            reply = ask(a.url, a.model, prompt, a.timeout, a.temperature, key)
        except (urllib.error.URLError, TimeoutError, KeyError, json.JSONDecodeError) as e:
            print(f'{name}: failed ({e}); stopping. Is the server running at {a.url} with model {a.model}?')
            break
        with open(os.path.join(a.answers, name + '.raw.txt'), 'w', encoding='utf-8') as f:
            f.write(reply)
        recs = records(reply)
        with open(out, 'w', encoding='utf-8', newline='\n') as f:
            f.write('\n'.join(recs) + ('\n' if recs else ''))
        offered = prompt.count('### function ')
        done += 1
        total += len(recs)
        print(f'{name}: {len(recs)} records for {offered} functions ({time.time() - t0:.0f} s)', flush=True)
    print(f'{done} batches answered, {total} records. Next: python tools/naming/merge.py')


if __name__ == '__main__':
    main()
