"""Copies the readable rewrite of a look-alike representative to the other members of its group
(research/findings/2026-10-18-lookalike-functions.md).

    python tools/rewrite/copy_lookalikes.py PACKET [PACKET ...]   copy the reviewed representatives of these packets
                                                                  (make_packets.py --representatives) and check
    --only sub_X        only this representative (repeatable)
    --limit N           at most N members per representative (trials)
    --unreviewed        also representatives without an approving verdict in review_lookalikes.tsv (trials:
                        their copies go to build/rewrite/copies_trial, never to an answer directory)
    --no-check          write the copies, do not check them
    --retry             copy again the members whose copy failed (after a representative was fixed)
    --batch N           copies per check run (default 150: a check holds the tester for a few minutes, and an agent
                        session's checks get their turn between batches)

A representative and its look-alikes have the same lifted code apart from the values the grouping abstracts
(lookalikes.py): names, callees, classes, fields, globals, strings, numbers. Their lifted texts are aligned value
by value, which maps each of the representative's values to the member's; the copy is the rewrite with the
member's values wherever it uses one of the representative's, the member's own constexpr, UseLiftedCode and
LiftedFrame lines, and no comments (they speak of the representative). A copy is refused, with the reason in
copies.tsv, when the rewrite uses a value that maps to two different values in the member, a number the lifted
code does not have while the member's numbers differ (a constant the model worked out, which cannot be swapped),
a class type the lifted code does not have, or a name built from one of the representative's own values (a
callee, global, string or class the member does not share).

Every copy is checked like an answer (check.py --dir, --outputs, profiles 0-5) in batches staged under
build/rewrite/copies/<packet>/; the checked copies collect in build/rewrite/answers/copies_<packet>/ with one
results.txt, which apply.py takes like any answer directory. Members with a result there are not copied again
(with --retry, those whose copy failed are).
Only representatives whose answer is OK in its packet and whose review verdict (build/rewrite/review_lookalikes.tsv:
packet, function, verdict, note) is GOOD, MINOR or FIXED are copied: a wrong representative would be wrong in its
whole group.
"""
import argparse
import csv
import json
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, HERE)
import lookalikes  # noqa: E402

RW = os.path.join(ROOT, 'build', 'rewrite')
REVIEW = os.path.join(RW, 'review_lookalikes.tsv')
APPROVED = ('GOOD', 'MINOR', 'FIXED')   # FIXED: the review made its fix itself (comments, names), checked again
STRICT = ['--outputs', '--profiles', '0,1,2,3,4,5']   # what promote.py checks (run_api.STRICT)
PAUSE = 10   # seconds between check batches: a waiting check (it polls the lock every 3 s) goes first

FIXED = re.compile(r'^\s*(?:if \(!UseLiftedCode\(|LiftedFrame frame\()')
CONSTEXPR = re.compile(r'^\s*constexpr [\w:]+ (\w+) = [^;]*?(0x[0-9A-Fa-f]+|\b\d+\b)?\)?;')
# an address as the lifted code spells it: a global, often with an offset (g_820A0000 + 1148); the bases are
# 64 KiB pages, so one base of the representative can be two bases of a look-alike, while the whole address
# maps to one
ADDRESS = re.compile(r'\b(g_\w+)\b(?!\s*=(?!=))(?:\s*([+-])\s*(0x[0-9A-Fa-f]+|\d+)\b(?!\s*[*/%<>]))?')
MARK = 0xE000   # private-use characters stand for addresses while the rest of a line is mapped
WORDS = re.compile(r'[A-Z]+(?![a-z])|[A-Z]?[a-z]+')
PLAIN_NUMBERS = {0, 1}


def number(v):
    return int(v, 16) if v.lower().startswith('0x') else int(v)


def body(text):
    """The lifted text without comments and without the lines every copy takes from its own lifted text."""
    lines = lookalikes.COMMENT.sub('', text).split('\n')
    return '\n'.join(line for line in lines if not FIXED.match(line))


def globals_of(text):
    """{g_ name: address} from a function's constexpr lines."""
    out = {}
    for line in text.split('\n'):
        m = CONSTEXPR.match(line)
        if m and m.group(1).startswith('g_') and m.group(2):
            out[m.group(1)] = number(m.group(2)) & 0xFFFFFFFF
    return out


def address_key(m, globs):
    g, op, off = m.group(1), m.group(2), m.group(3)
    if g not in globs:
        return None
    n = number(off) if off else 0
    return (globs[g] + (n if op != '-' else -n)) & 0xFFFFFFFF, n


def addresses(text):
    """(the text with each address outside constexpr lines replaced by a mark, [(address, offset, spelling)])."""
    globs = globals_of(text)
    found, lines = [], []
    for line in text.split('\n'):
        if CONSTEXPR.match(line):
            # a declared value is aligned where the code uses it, not here: the declarations are in address
            # order, and two look-alikes' addresses can order differently (the copy declares its own anyway)
            continue
        def mark(m):
            k = address_key(m, globs)
            if k is None:
                return m.group(0)
            found.append((k[0], k[1], m.group(0)))
            return chr(MARK)
        lines.append(ADDRESS.sub(mark, line))
    return '\n'.join(lines), found


def value_map(rep, member, common):
    """The maps from the representative's values to a look-alike's, from their lifted texts, or None when the
    two are not of one shape: ({address: {spelling}}, {offset: {offset}}, {name: {name}}, {number: {number}})."""
    ra, rlist = addresses(body(rep))
    ma, mlist = addresses(body(member))
    if len(rlist) != len(mlist):
        return None
    ha, a = lookalikes.tokens(ra, common)
    hb, b = lookalikes.tokens(ma, common)
    if ha != hb or len(a) != len(b):
        return None
    member_numbers = [number(v) for k, v in b if k in ('K', 'N')]
    sites = {}   # number: [(the look-alike's value there, the line around it)] for every place of it
    for (n, skel, i), m in zip(number_sites(ra, common), member_numbers):
        sites.setdefault(n, []).append((m, skel, i))
    addr, offsets, names, nums = {}, {}, {}, {}
    for (va, oa, _), (_, ob, sb) in zip(rlist, mlist):
        addr.setdefault(va, set()).add(re.sub(r'\s+', ' ', sb))
        offsets.setdefault(oa, set()).add(ob)
    for (k, va), (kb, vb) in zip(a, b):
        if k != kb:
            return None
        if k in ('K', 'N'):
            nums.setdefault(number(va), set()).add(number(vb))
        else:
            names.setdefault(va, set()).add(vb)
    return addr, offsets, names, nums, sites


SKELETON = re.compile(r'[A-Za-z_]\w*|0x[0-9A-Fa-f]+|\d+|[^\s\w]')
LIFTED_VARIABLE = re.compile(r'(?:local|arg|var)\d+$')   # (common names, but a rewrite renames them)


def skeleton(line, common):
    """A line's tokens with the names a rewrite renames as one placeholder: the code around a number."""
    out, starts = [], {}
    for t in SKELETON.finditer(line):
        v = t.group()
        if v[0].isdigit():
            v = str(number(v))
        elif (v[0].isalpha() or v[0] == '_') and (v not in common or LIFTED_VARIABLE.match(v)):
            v = 'x'
        starts[t.start()] = len(out)
        out.append(v)
    return out, starts


def number_sites(text, common):
    """[(number, the skeleton of its line, its place in it)] in the order lookalikes.tokens lists the numbers."""
    out = []
    for line in text.split('\n'):
        skel, starts = None, None
        for t in lookalikes.TOK.finditer(line):
            if t.lastgroup in ('K', 'N'):
                if skel is None:
                    skel, starts = skeleton(line, common)
                out.append((number(t.group()), skel, starts.get(t.start())))
    return out


def context_score(a, i, b, j):
    """How well the code around place i of a matches the code around place j of b (nearer tokens weigh more)."""
    if i is None or j is None:
        return 0
    s = 0
    for d in range(1, 5):
        if i - d >= 0 and j - d >= 0 and a[i - d] == b[j - d]:
            s += 5 - d
        if i + d < len(a) and j + d < len(b) and a[i + d] == b[j + d]:
            s += 5 - d
    return s


CONTEXT_MIN = 12   # the code around a number this alike (both neighbours and more) settles which place it is


def own_lines(lifted):
    """The member's constexpr lines by the name they declare, and its UseLiftedCode / LiftedFrame lines."""
    consts, fixed = {}, []
    for line in lifted.split('\n'):
        m = CONSTEXPR.match(line)
        if m:
            consts[m.group(1)] = line
        elif FIXED.match(line):
            fixed.append(line)
    return consts, fixed


PARAMS = re.compile(r'^[^\n]*?\b[A-Za-z_]\w*\(CpuState& ctx, uint8_t\* base((?:, [^)]*)?)\)\s*\{', re.M)


def params(text):
    """The parameter names of the definition in a function's text (after ctx and base), or None."""
    m = PARAMS.search(lookalikes.COMMENT.sub('', text))
    if not m:
        return None
    return [p.split()[-1].lstrip('*&') for p in m.group(1).split(',')[1:]] if m.group(1) else []


def words(name):
    return {w.lower() for w in WORDS.findall(name) if len(w) >= 4}


def single(values):
    return next(iter(values)) if len(values) == 1 else None


class Rep:
    """A representative: its rewrite and lifted text, what the copies need of them."""

    def __init__(self, name, rewrite, lifted, common, rep_class):
        self.name, self.rewrite, self.lifted, self.common = name, rewrite, lifted, common
        _, values = lookalikes.tokens(addresses(body(lifted))[0], common)
        self.lifted_names = {v for k, v in values if k not in ('K', 'N')}
        self.lifted_classes = {v for k, v in values if k == 'C'}
        self.lifted_idents = set(lookalikes.IDENT.findall(lookalikes.COMMENT.sub('', lifted)))
        self.lifted_consts = set(own_lines(lifted)[0])
        self.globals = globals_of(lifted)
        self.rep_class = rep_class

    def mark_addresses(self, code, addr, nums, problems):
        """(the line with each address of the lifted code replaced by a mark, [the look-alike's spelling of each]).
        A base and an offset the rewrite folded into one address (`g_82540000 + 19848`) while the lifted code
        keeps them apart (`local = g_82540000; ... local + 19848`) are mapped one by one: the base as the bare
        address, the offset as the number."""
        spelled = []

        def mark(m):
            k = address_key(m, self.globals)
            to = addr.get(k[0]) if k else None
            if not to and k and k[1]:
                base, n = addr.get(self.globals[m.group(1)]), nums.get(k[1])
                if base and len(base) == 1 and n and len(n) == 1:
                    spelled.append(f'{single(base)} {m.group(2)} {single(n)}')
                    return chr(MARK + len(spelled))
            if not to:
                return m.group(0)   # (not an address of the lifted code: its parts are mapped one by one)
            if len(to) > 1:
                problems.append(f'address {m.group(0)} has several values in the look-alike')
                return m.group(0)
            spelled.append(single(to))
            return chr(MARK + len(spelled))
        return ADDRESS.sub(mark, code), spelled

    def choose_numbers(self, marked, nums, sites):
        """{(line, column): the look-alike's value} for the rewrite's numbers that have several values in the
        look-alike: each takes the value of the lifted place with the same code around it. Places the rewrite
        matches clearly are claimed first; a number whose code changed takes the value the unclaimed places
        agree on. None where nothing decides."""
        occurrences = {}
        for li, code in enumerate(marked):
            skel = None
            for t in lookalikes.TOK.finditer(code):
                if t.lastgroup in ('K', 'N') and len(nums.get(number(t.group()), ())) > 1:
                    if skel is None:
                        skel = skeleton(code, self.common)
                    occurrences.setdefault(number(t.group()), []).append(((li, t.start()), skel[0],
                                                                          skel[1].get(t.start())))
        out = {}
        for n, occ in occurrences.items():
            places = sites[n]
            claimed, weak = set(), []
            for key, skel, i in occ:
                scores = [context_score(skel, i, s, j) for _, s, j in places]
                best = max(scores)
                top = [p for p, sc in enumerate(scores) if sc == best]
                values = {places[p][0] for p in top}
                if best >= CONTEXT_MIN and len(values) == 1:
                    out[key] = single(values)
                    claimed |= set(top)
                else:
                    weak.append((key, top if best >= CONTEXT_MIN else None))
            for key, top in weak:
                free = [p for p in (top or []) if p not in claimed] or [p for p in range(len(places))
                                                                       if p not in claimed]
                values = {places[p][0] for p in free}
                out[key] = single(values) if len(values) == 1 else None
        return out

    def map_line(self, li, code, spelled, maps, choices, problems):
        addr, offsets, names, nums, sites, varying, rep_only = maps
        out, pos = [], 0
        for t in lookalikes.TOK.finditer(code):
            k, v = t.lastgroup, t.group()
            out.append(code[pos:t.start()])
            pos = t.end()
            if k == 'S':
                out.append(v)
                continue
            if k in ('K', 'N'):
                n = number(v)
                to = nums.get(n)
                if to is None and n in offsets and offsets[n] != {n}:
                    problems.append(f'number {v} is an address offset of the lifted code apart from its global '
                                    '(the copy cannot know which)')
                elif to is None:
                    if n not in PLAIN_NUMBERS and varying:
                        problems.append(f'number {v} is not in the lifted code (a value worked out cannot be '
                                        'swapped)')
                else:
                    m = single(to) if len(to) == 1 else choices.get((li, t.start()))
                    if m is None:
                        problems.append(f'number {v} has several values in the look-alike')
                    else:
                        v = v if m == n else (f'0x{m:X}' if v.lower().startswith('0x') else str(m))
                out.append(v)
                continue
            to = names.get(v)
            if to and len(to) > 1:
                problems.append(f'{v} has several values in the look-alike')
            elif to:
                v = single(to)
            elif k == 'C' and v not in self.lifted_classes:
                problems.append(f'class type {v} the lifted code does not have')
            elif k == 'M' and v not in self.lifted_names:
                problems.append(f'field {v} the lifted code does not use')
            elif k in ('I', 'V') and v not in self.lifted_idents and words(v) & rep_only:
                problems.append(f'name {v} is made from the representative\'s own '
                                f'{"/".join(sorted(words(v) & rep_only))}')
            out.append(v)
        out.append(code[pos:])
        code = ''.join(out)
        for c in self.lifted_classes:   # (class names outside GameObject<>: typed pointers)
            to = names.get(c)
            if to and len(to) == 1 and single(to) != c:
                code = re.sub(r'\b' + re.escape(c) + r'\b', single(to), code)
        return re.sub('[%s-%s]' % (chr(MARK + 1), chr(MARK + 0x1000)), lambda m: spelled[ord(m.group()) - MARK - 1],
                      code)

    def copy(self, member_name, member):
        """(text, None) or (None, why it is not copied)."""
        maps = value_map(self.lifted, member, self.common)
        if maps is None:
            return None, 'not the same shape'
        addr, offsets, names, nums, sites = maps
        own = lookalikes.DEF.search(lookalikes.COMMENT.sub('', self.rewrite))
        member_own = lookalikes.DEF.search(lookalikes.COMMENT.sub('', member))
        if own and member_own:   # (the rewrite's definition name can be newer than its lifted text's)
            names[own.group(1)] = {member_own.group(1)}
        varying = any(n != m for n, ms in nums.items() for m in ms) or any(
            s != t for s, ts in offsets.items() for t in ts)
        member_words = set()
        for ident in lookalikes.IDENT.findall(lookalikes.COMMENT.sub('', member)):
            member_words |= words(ident)
        rep_only = set()
        lifted_own = lookalikes.DEF.search(lookalikes.COMMENT.sub('', self.lifted))
        own_names = {m.group(1) for m in (own, lifted_own) if m}   # (every look-alike has a name of its own)
        for va, vbs in names.items():
            if vbs != {va} and va not in own_names:
                rep_only |= words(va) - member_words
        if self.rep_class:
            rep_only |= words(re.sub(r'^(CEC|C)(?=[A-Z])', '', self.rep_class)) - member_words
        maps = (addr, offsets, names, nums, sites, varying, rep_only)
        consts, fixed = own_lines(member)
        # parameters the rewrite renamed: the look-alike's own UseLiftedCode line uses them too
        ps = [params(t) for t in (self.lifted, self.rewrite, member)]
        if all(ps) and len(set(map(len, ps))) == 1:
            renamed = {m: r for l, r, m in zip(*ps) if r != l}
            for i, line in enumerate(fixed):
                for old, new in renamed.items():
                    line = re.sub(r'\b' + re.escape(old) + r'\b', new, line)
                fixed[i] = line
        problems, lines, fixed_used, const_at = [], [], 0, None
        todo = []   # (index in lines, the line marked, the spellings of its addresses)
        for line in self.rewrite.split('\n'):
            if line.startswith('// name:') or re.match(r'\s*// sub_[0-9A-F]{8}\b', line):
                continue
            if FIXED.match(line):
                if fixed_used < len(fixed):
                    lines.append(fixed[fixed_used])
                fixed_used += 1
                continue
            m = CONSTEXPR.match(line)
            if m and m.group(1) in self.lifted_consts:
                if const_at is None:
                    const_at = len(lines)   # (the look-alike's own constexpr lines go here)
                continue
            code = lookalikes.COMMENT.sub('', line)
            if not code.strip():
                if not line.strip():
                    lines.append('')
                continue
            todo.append((len(lines), *self.mark_addresses(code, addr, nums, problems)))
            lines.append(None)
        choices = self.choose_numbers([code for _, code, _ in todo], nums, sites)
        for li, (at, code, spelled) in enumerate(todo):
            lines[at] = self.map_line(li, code, spelled, maps, choices, problems).rstrip()
        if fixed_used != len(fixed):
            problems.append('the UseLiftedCode / LiftedFrame lines differ from the lifted code\'s')
        if problems:
            return None, '; '.join(sorted(set(problems)))
        used = set(lookalikes.IDENT.findall('\n'.join(lines)))
        own_consts = [line for name, line in consts.items() if name in used]
        if const_at is None:
            const_at = 1
        lines[const_at:const_at] = own_consts
        text = '\n'.join(lines).strip('\n')
        return re.sub(r'\n{3,}', '\n\n', text) + '\n', None


def reviewed():
    """{(packet, function): verdict} from review_lookalikes.tsv."""
    if not os.path.exists(REVIEW):
        return {}
    with open(REVIEW, encoding='utf-8') as f:
        return {(r['packet'], r['function']): r['verdict'] for r in csv.DictReader(f, delimiter='\t')}


def packet_reps(packet):
    """[(function, lifted text)] of a packet, in its order."""
    text = open(os.path.join(RW, 'packets', packet + '.md'), encoding='utf-8').read()
    return [(m.group(1)[4:], m.group(2)) for m in lookalikes.SECTION.finditer(text)]


def read_results(path):
    out = {}
    if os.path.exists(path):
        for line in open(path, encoding='utf-8'):
            n, sep, why = line.rstrip('\n').partition('\t')
            if sep:
                out[n] = why
    return out


def check(batch_dir, jobs):
    r = subprocess.run([sys.executable, os.path.join(HERE, 'check.py'), '--dir', batch_dir, '--jobs', str(jobs)]
                       + STRICT, cwd=ROOT, capture_output=True, text=True)
    res = read_results(os.path.join(batch_dir, 'results.txt'))
    if not res:
        print(r.stdout[-1500:], r.stderr[-1500:])
    return res


def main():
    ap = argparse.ArgumentParser(description='Copy look-alike representatives\' rewrites (see the docstring).')
    ap.add_argument('packets', nargs='+')
    ap.add_argument('--only', action='append', default=[])
    ap.add_argument('--limit', type=int)
    ap.add_argument('--unreviewed', action='store_true')
    ap.add_argument('--no-check', action='store_true')
    ap.add_argument('--retry', action='store_true')
    ap.add_argument('--batch', type=int, default=150)
    ap.add_argument('--jobs', type=int, default=4)
    a = ap.parse_args()

    data = json.load(open(lookalikes.OUT, encoding='utf-8'))
    common = set(data['common'])
    group_of = {m: g for g in data['groups'] for m in g['members']}
    lifted = lookalikes.lifted_functions()
    done = lookalikes.converted()
    verdicts = reviewed()
    cl = json.load(open(os.path.join(ROOT, 'tools', 'lift', 'cache', 'classes.json'), encoding='utf-8'))
    class_of = lambda f: cl['classes'].get(cl['this'].get(f, ''), {}).get('struct')  # noqa: E731

    for packet in a.packets:
        answers = os.path.join(RW, 'answers', packet)
        results = read_results(os.path.join(answers, 'results.txt'))
        if a.unreviewed:
            final = os.path.join(RW, 'copies_trial', packet)
        else:
            final = os.path.join(RW, 'answers', 'copies_' + packet)
        stage = os.path.join(RW, 'copies', packet)
        final_results = read_results(os.path.join(final, 'results.txt'))
        log_path = os.path.join(final, 'copies.tsv')
        os.makedirs(final, exist_ok=True)
        new_log = not os.path.exists(log_path)
        log = open(log_path, 'a', encoding='utf-8', newline='\n')
        if new_log:
            log.write('member\trepresentative\toutcome\n')
        todo = []   # (member, representative)
        for rep, rep_lifted in packet_reps(packet):
            fn = 'sub_' + rep
            if a.only and fn not in a.only:
                continue
            verdict = verdicts.get((packet, fn))
            if results.get(fn) != 'OK':
                print(f'{fn}: not copied: its answer is not OK ({results.get(fn, "no result")[:80]})')
                continue
            if verdict not in APPROVED and not a.unreviewed:
                print(f'{fn}: not copied: review verdict {verdict or "missing"} (review_lookalikes.tsv)')
                continue
            g = group_of.get(rep)
            if not g:
                print(f'{fn}: no group in lookalikes.json (run lookalikes.py again?)')
                continue
            r = Rep(fn, open(os.path.join(answers, fn + '.cpp'), encoding='utf-8').read(), rep_lifted, common,
                    class_of(fn))
            members = [m for m in g['members'] if m != rep and m not in done and
                       ('sub_' + m not in final_results or (a.retry and final_results['sub_' + m] != 'OK'))]
            if a.limit:
                members = members[:a.limit]
            copied = refused = 0
            for m in members:
                if m not in lifted:
                    continue
                text, why = r.copy('sub_' + m, lifted[m])
                if why:
                    log.write(f'sub_{m}\t{fn}\tnot copied: {why}\n')
                    refused += 1
                    continue
                todo.append(('sub_' + m, fn, text))
                copied += 1
            print(f'{fn}: group of {len(g["members"]) + len(g["converted"])}, {copied} copies, {refused} refused')
        log.flush()
        if not todo:
            log.close()
            continue
        if a.no_check:
            for m, rep, text in todo:
                open(os.path.join(final, m + '.cpp'), 'w', encoding='utf-8', newline='\n').write(text)
                log.write(f'{m}\t{rep}\tcopied, not checked\n')
            log.close()
            print(f'{packet}: {len(todo)} copies written to {os.path.relpath(final, ROOT)} (not checked)')
            continue
        ok = 0
        for i in range(0, len(todo), a.batch):
            batch = todo[i:i + a.batch]
            batch_dir = os.path.join(stage, f'batch_{i // a.batch:03}')
            shutil.rmtree(batch_dir, ignore_errors=True)
            os.makedirs(batch_dir)
            for m, rep, text in batch:
                open(os.path.join(batch_dir, m + '.cpp'), 'w', encoding='utf-8', newline='\n').write(text)
            t0 = time.time()
            res = check(batch_dir, a.jobs)
            for m, rep, _ in batch:
                why = res.get(m, 'NOT TESTED (no result)')
                if why == 'OK':
                    shutil.copy(os.path.join(batch_dir, m + '.cpp'), os.path.join(final, m + '.cpp'))
                    ok += 1
                elif os.path.exists(os.path.join(final, m + '.cpp')):
                    os.remove(os.path.join(final, m + '.cpp'))   # (an earlier copy, from a representative since fixed)
                final_results[m] = why if why == 'OK' else 'COPY FAILED: ' + why
                log.write(f'{m}\t{rep}\t{"OK" if why == "OK" else "check: " + why[:300]}\n')
            with open(os.path.join(final, 'results.txt'), 'w', encoding='utf-8', newline='\n') as f:
                f.writelines(f'{m}\t{why}\n' for m, why in sorted(final_results.items()))
            log.flush()
            print(f'{packet}: batch {i // a.batch + 1}: {sum(1 for m, _, _ in batch if res.get(m) == "OK")} of '
                  f'{len(batch)} OK ({time.time() - t0:.0f} s)', flush=True)
            if i + a.batch < len(todo):
                time.sleep(PAUSE)
        log.close()
        print(f'{packet}: {ok} of {len(todo)} copies OK -> {os.path.relpath(final, ROOT)}')


if __name__ == '__main__':
    main()
