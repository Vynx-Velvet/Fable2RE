"""Checks how the game's compiled code uses registers across calls, to justify the ABI the lifter
relies on: which registers callers read after direct / indirect calls (return values), and which
registers functions read on entry (arguments). Prints histograms of anything outside the
standard convention. Runs on all generated files in parallel."""
import collections
import multiprocessing as mp
import sys

from genfile import read_file, generated_files
import lift
import regs
from cparse import Call, Name, ExprStmt, walk

ABI_IN = 0
for n in ['r1', 'r2', 'r13'] + [f'r{i}' for i in range(3, 11)] + [f'f{i}' for i in range(1, 14)] + \
        [f'v{i}' for i in range(1, 14)]:
    ABI_IN |= regs.bit(n)


def callee_of(st):
    for x in walk(st.e if isinstance(st, ExprStmt) else getattr(st, 'body', st)):
        if type(x) is Call and type(x.func) is Name:
            if x.func.id == 'REX_CALL_INDIRECT_FUNC':
                return 'indirect'
            if x.args and type(x.args[0]) is Name and x.args[0].id == 'ctx':
                return x.func.id
    return '?'


def survey(path):
    after_direct = collections.Counter()
    after_indirect = collections.Counter()
    entry = collections.Counter()
    odd_entry = []
    odd_after = []
    xer_so_writes = 0
    nfn = 0
    for fn in read_file(path):
        try:
            stmts = lift.build(fn)
            lift.analyse(stmts)
        except Exception:
            continue
        nfn += 1
        if stmts:
            ein = stmts[0].live_in & ~ABI_IN
            for r in regs.names(ein):
                entry[r] += 1
            if ein:
                odd_entry.append((fn.name, regs.names(ein)))
        for s in stmts:
            if not s.acc.sync:
                continue
            c = callee_of(s.stmt)
            live = s.live_out & regs.VOLATILE & ~s.acc.def_
            key = tuple(regs.names(live))
            if c == 'indirect':
                after_indirect[key] += 1
            elif not c.startswith('__'):
                after_direct[key] += 1
                if live & ~(regs.bit('r3') | regs.bit('f1') | regs.bit('r4')):
                    odd_after.append((fn.name, c, regs.names(live)))
    return nfn, after_direct, after_indirect, entry, odd_entry[:50], odd_after[:50]


def main():
    files = generated_files()
    if len(sys.argv) > 1:
        files = [f for f in files if int(f.split('.')[-2]) in {int(a) for a in sys.argv[1:]}]
    with mp.Pool(8) as pool:
        res = pool.map(survey, files)
    nfn = sum(r[0] for r in res)
    ad, ai, en = collections.Counter(), collections.Counter(), collections.Counter()
    oe, oa = [], []
    for r in res:
        ad.update(r[1]); ai.update(r[2]); en.update(r[3]); oe.extend(r[4]); oa.extend(r[5])
    print(f'functions analysed: {nfn}')
    print('\nlive volatile registers after DIRECT calls:')
    for k, v in ad.most_common(15):
        print(f'  {v:8d} {k}')
    print('\nlive volatile registers after INDIRECT calls:')
    for k, v in ai.most_common(15):
        print(f'  {v:8d} {k}')
    print('\nnon-argument registers read on entry (functions):')
    for k, v in en.most_common(30):
        print(f'  {v:8d} {k}')
    print('\nexamples entry:', oe[:15])
    print('\nexamples after direct call:', oa[:15])


if __name__ == '__main__':
    main()
