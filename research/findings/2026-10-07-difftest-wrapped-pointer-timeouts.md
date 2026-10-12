# Differential tester: "timeout in one version only" was a harness fault (2026-10-07)

## Symptom

After the dense / mixed input profiles (1, 4, 5) were added to the rewrite checker, 268 accepted rewrites were
revoked with `MISMATCH sub_X: timeout in one version only (the lifted / rewritten)`. Many of them were
trivially correct (a two-call wrapper, a 12-byte setter). Measuring the test thread's own CPU time instead
of wall-clock time (first suspicion: load from a parallel build) changed nothing: the verdicts were
deterministic, and the lifter's own output for the same functions "timed out" the same way.

## Cause

Profiles 1/4/5 hand small negative numbers (`0u - n`, e.g. `0xFFFFFF91`) as arguments. When the function
uses such a value as an object pointer:

- the recompiled original computes every access as `base + (u32)(ptr + offset) [+ 0x1000 above 0xE0000000]`,
  so the address wraps in 32 bits and lands on a normal guest page;
- the lifted / rewritten code makes a typed view once (`GameObject<T>(base, ptr)` = `base + ptr + shift`) and
  adds the field offset in 64 bits, so the host address lies past the guest's 4 GB (or in the gap page
  below the 0xE0000000 shift).

The harness's page-fault handler truncated the host offset to 32 bits before choosing the page to commit, so
it committed the *wrapped* page, the faulting instruction re-faulted, and the thread spun in page faults
until the 500 ms limit: a "timeout" in exactly one version. `gdb` on the kept test program showed the worker
at `mov 0xd0(%rcx,%rax,1)` (`obj->m_D0`) with `rcx = 0x1000, rax = base + 0xFFFFFF91`, 400+ access
violations at the same instruction.

## Fix (tools/lift/difftest/driver.cpp)

The handler now commits the page that actually faulted. If it is not the guest page's own host page, it is an
*alias* page (tracked in `g_alias` by host offset): it is filled with the content of the guest page it stands
for (`FillPageAt(p, GuestOf(hoff))`), so both versions read identical values; `ResetMemory` decommits alias
pages too; `Snapshot` folds bytes written to an alias page into the record of the guest page they stand for,
so a store through a wrapped pointer still compares against the original's store. The per-run limit stays
on thread CPU time (`GetThreadTimes`), which is the right measure on a loaded machine anyway.

With the fix, `sub_8323A788` (the probe case) is OK on profiles 1, 4 and 5. Re-check of the 268: 226 OK at
once.

## Second artefact: 64-bit carries in call arguments

27 of the remaining 42 failed with `argument value #k: 100000093 vs 93`: the original keeps 64-bit
registers, so `0xFFFFFF00 + 0x93` (a small negative test input plus a field offset) carries into bit 32,
while the rewrite's `uint32_t` does not. The checker compared 64 bits because the callee's `wide_in` is
conservative (anything reaching an indirect call counts as read wide). The game's C code is 32-bit and no
real pointer sits near 4 GB, so in relaxed mode (`driver.cpp` `SameArgs32`, flag passed by `run.py` as the
third argument) integer arguments that differ only by a carry into bit 32 or by sign extension
(upper half 0 / 1 / 0xFFFFFFFF on both sides) are equal; a 64-bit value truncated to 32 bits still differs.
23 more OK.

## What was left

Of the last 19, 14 fail identically when the lifter's own exact block is fed through the same relaxed check
(and 6 of them fail the strict tester on profile 1 as well: `80000070 vs 70`, sub-word store differences at
wrapped addresses). They are therefore not rewrite errors; whether they are lifter inexactness on impossible
inputs or further harness subtleties of the alias pages is open (functions: build/rewrite/artefact14.txt).
The 5 real failures (sub_82188088, sub_821D2470, sub_824293D0, sub_82548598, sub_82C3E7F8: a wrong return
value, wrong argument values with the real low 32 bits differing) stay revoked and go back to the model via
`make_packets.py --retry`.

Result: 263 of the 268 revokes were harness artefacts; restored with `tools/rewrite/restore.py`.

## Lessons

- A verdict that hits a trivially correct function is a harness bug until proven otherwise; reproduce it
  with the lifter's own block as the "rewrite" before revoking (`check.py --dir` with the chunk's block).
- The wrap-around difference between per-access 32-bit addressing and a typed pointer is real but only
  reachable with impossible pointers (objects at 0xFFFFFxxx); the test inputs must not turn it into a verdict.
