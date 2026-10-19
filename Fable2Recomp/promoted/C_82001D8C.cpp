// C_82001D8C (vtable 0x82001D8C): methods of the class as readable C++.
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

// sub_821D1440  [16 bytes]
uint64_t n_sub_821D1440(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(3, 0x821D1440)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_821D1440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D1440);
	uint64_t result = n_sub_821CA640(ctx, base, arg2, arg1);
	return result;
}
PROMOTED_ENTRY(3, sub_821D1440, 0x821D1440) { ctx.r3.u64 = n_sub_821D1440(ctx, base, ctx.r3.u64, ctx.r4.u64); }
