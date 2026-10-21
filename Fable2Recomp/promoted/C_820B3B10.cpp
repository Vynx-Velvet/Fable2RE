// C_820B3B10 (vtable 0x820B3B10): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md). Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs). Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md. A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"
#include "lifted/readable_support.h"

uint64_t n_sub_8245CAD0(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(26, 0x8245CAD0)) { __imp__sub_8245CAD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8245CAD0);
	return n_sub_8245C730(ctx, base);
}
PROMOTED_ENTRY(26, sub_8245CAD0, 0x8245CAD0) { ctx.r3.u64 = n_sub_8245CAD0(ctx, base); }
