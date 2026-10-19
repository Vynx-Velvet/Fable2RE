"""Names the start-up and shut-down functions of global strings after the global they build or release.

The start-up area of the executable holds one small function per global string object: it constructs the string
from its text and registers its destructor to run at exit; the shut-down area holds that destructor. Each is fully
described by its global, so where the global has a name (research/decomp/global_names.tsv, written on every
machine from its own copy of the game, because the name is the game's text) the function is named after it:

    Construct_<global>   CCharString_ConstructFromCStr(<global>, ...), then the at-exit registration of its
                         destructor, and nothing else
    Destroy_<global>     CCharString_ReleaseAndDecGlobalCountA(<global>), and nothing else

The names live only in the promoted modules: the lifted code reaches these functions through pointers, and their
weak native bridges (lifted/native_bridges.N.cpp) reach them through their entries. The repository holds them with
a reference in place of the global's name (Destroy_TXT_<address>_G_, tools/rewrite/promoted_text.py), so every
setup renders the same names from its own copy. A rename changes no code; the review recorded for the function
applies to the renamed text (build/rewrite/promote/reviewed_texts.json is carried over).

    python tools/rewrite/name_globals.py            what it would rename
    python tools/rewrite/name_globals.py --apply    rename in Fable2Recomp/src/game/promoted/
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import promote  # noqa: E402
import promoted_text  # noqa: E402

UNNAMED = re.compile(r'n_sub_[0-9A-F]{8}')
CALL = re.compile(r'\b(\w+)\(ctx, base(?:, ([^()]*(?:\([^()]*\)[^()]*)*))?\)')
CONSTRUCT = 'CCharString_ConstructFromCStr'
RELEASE = 'CCharString_ReleaseAndDecGlobalCountA'
AT_EXIT = ('n_sub_82CA3700', 'CRT_atexit')


def calls(text, n):
    """[(callee, [arguments])] of a function text, without its fallback to the original."""
    out = []
    for m in CALL.finditer(text):
        if m.group(1) in (f'__imp__{n}', f'{n}_original'):
            continue
        args = [a.strip() for a in re.split(r',(?![^()]*\))', m.group(2) or '') if a.strip()]
        out.append((m.group(1), args))
    return out


def proposal(n, text):
    """(new name, global) for a start-up or shut-down function of a global named after its text, or None."""
    d = promote.DEF_RE.search(text)
    if not d or not UNNAMED.fullmatch(d.group(1)):
        return None
    names = promoted_text.text_globals()
    cs = [c for c in calls(text, n) if c[0] != d.group(1)]
    if len(cs) == 1 and cs[0][0] == RELEASE and len(cs[0][1]) == 1 and cs[0][1][0] in names:
        return f'Destroy_{cs[0][1][0]}', cs[0][1][0]
    if (len(cs) == 2 and cs[0][0] == CONSTRUCT and cs[0][1] and cs[0][1][0] in names
            and cs[1][0] in AT_EXIT):
        return f'Construct_{cs[0][1][0]}', cs[0][1][0]
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    funcs = promote.module_functions()
    found = {n: p for n, (path, text) in funcs.items() if (p := proposal(n, text))}
    # one function per name: a global built or released by two functions keeps both unnamed
    count = collections.Counter(p[0] for p in found.values())
    renames = {n: p[0] for n, p in found.items() if count[p[0]] == 1}
    kinds = collections.Counter(new.split('_', 1)[0] for new in renames.values())
    print(f'{len(renames)} functions to name ({dict(kinds)}); {len(found) - len(renames)} left unnamed '
          '(their global has two such functions)')
    if not a.apply:
        for n, new in list(renames.items())[:5]:
            print(f'  {n} -> {promoted_text.embed_refs(new)}')
        return 0
    by_module = collections.defaultdict(dict)
    for n, new in renames.items():
        by_module[funcs[n][0]][n] = new
    reviewed = promote.reviewed_texts()
    moved = 0
    for path, these in sorted(by_module.items()):
        head, have = promote.split_module(open(path, encoding='utf-8').read())
        for n, new in these.items():
            old_text = have[n]
            old = promote.DEF_RE.search(old_text).group(1)
            have[n] = re.sub(rf'\b{old}\b', new, old_text)
            if reviewed.get(n) == promote.text_digest(old_text):   # (the review applies to the renamed text too)
                reviewed[n] = promote.text_digest(have[n])
                moved += 1
        promote.write_module(path, head, have)
    promote.save_reviewed_texts(reviewed)
    print(f'renamed {len(renames)} functions in {len(by_module)} modules; {moved} recorded reviews carried over')
    return 0


if __name__ == '__main__':
    sys.exit(main())
