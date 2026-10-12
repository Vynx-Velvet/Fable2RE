"""Diagnostics: which statements make a function read an argument's upper 32 bits on their own
(per value, ignoring callees and callers). Usage: diag_wide.py <file-index> [max]"""
import collections
import sys

from genfile import read_file, generated_files
import lift
import regs
import typer
import webs
import summarize
from cparse import stmt_str


def main():
    idx = int(sys.argv[1])
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else 15
    path = [p for p in generated_files() if p.endswith(f'.{idx}.cpp')][0]
    g0 = regs.INDEX['r0']
    cand = (regs.ABI_INPUTS | regs.ABI_OUTPUTS) & summarize.GPR_BITS
    kinds = collections.Counter()
    shown = nfn = nwide = 0
    for fn in read_file(path):
        try:
            stmts = lift.build(fn)
        except Exception:
            continue
        recs = []
        texts = []
        for s in stmts:
            if s.removed:
                recs.append((0, 0, False, None, tuple(s.succ), 0, ()))
                texts.append('')
                continue
            loc = lift.localize_stmt(s.stmt)
            w, e = typer.demand_info(loc)
            wb = 0
            for r in w:
                wb |= regs.bit(r)
            recs.append((s.acc.use, s.acc.def_, s.acc.sync, s.acc.callee, tuple(s.succ), wb,
                         tuple((regs.INDEX[a], regs.INDEX[b]) for a, b in e)))
            texts.append((s.insn.asm if s.insn else '') + ' :: ' + stmt_str(loc, '').strip())
        nfn += 1
        res = webs.analyse(recs, g0, lambda i: regs.VOLATILE & summarize.GPR_BITS, lambda i: 0, 0, need_webs=False)
        wi = res.wide_in & regs.ABI_INPUTS
        if not wi:
            continue
        nwide += 1
        # the wide-read statements whose reaching definitions include an entry definition
        entry = {k for k in res.entry_def.values()}
        for i, st in enumerate(recs):
            for r in webs._bits((st[5] >> g0)):
                rd = res.rd_in[i].get(r, 0)
                if any((rd >> k) & 1 for k in entry):
                    kinds[texts[i].split(' ')[0]] += 1
                    if shown < limit:
                        print(f'{fn.name} r{r}: {texts[i][:150]}')
                        shown += 1
    print(f'{nwide} of {nfn} functions read an argument as 64-bit locally')
    print('direct 64-bit reads of entry values by instruction:', kinds.most_common(15))


if __name__ == '__main__':
    main()
