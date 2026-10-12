"""Parses every generated function and checks that printing the parsed statements reproduces
the recompiler's text (modulo whitespace / redundant parentheses). Usage: test_parse.py [file-index ...]"""
import re
import sys
import collections

from genfile import read_file, generated_files, Insn
from cparse import stmt_str, Block, Switch


def norm(s):
    return re.sub(r'[\s()]', '', s)


def main():
    files = generated_files()
    if len(sys.argv) > 1:
        files = [f for f in files if int(f.split('.')[-2]) in {int(a) for a in sys.argv[1:]}]
    nfunc = nerr = nst = nbad = 0
    errs = collections.Counter()
    for path in files:
        for fn in read_file(path, keep_text=True):
            nfunc += 1
            if fn.error:
                nerr += 1
                errs[fn.error[:80]] += 1
                continue
            text_stmts = [l.split(' // ')[0].strip() for l in fn.text[1:-1] if l.strip() and not l.strip().startswith('//')
                          and not re.match(r'^loc_[0-9A-F]+:$', l.strip())]
            printed = []
            for st in fn.decls:
                printed.append(stmt_str(st, ''))
            for it in fn.items:
                if isinstance(it, Insn):
                    for st in it.stmts:
                        printed.append(stmt_str(st, ''))
            a = norm(''.join(text_stmts))
            b = norm(''.join(printed))
            nst += len(printed)
            if a != b:
                nbad += 1
                if nbad <= 5:
                    # first difference
                    k = next((k for k in range(min(len(a), len(b))) if a[k] != b[k]), min(len(a), len(b)))
                    print('MISMATCH', fn.name, '\n  text:', a[max(0, k - 80):k + 80], '\n  ours:', b[max(0, k - 80):k + 80])
    print(f'functions {nfunc}, parse errors {nerr}, round-trip mismatches {nbad}, statements {nst}')
    for e, c in errs.most_common(20):
        print(f'  {c:6d} {e}')


if __name__ == '__main__':
    main()
