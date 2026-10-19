// C_82001B48 (vtable 0x82001B48): methods of the class as readable C++.
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

uint64_t C_82001B48_GetInstance(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8333C50C = int32_t(0x8333C50C);
	if (!UseLiftedCode(9, 0x82275480)) { __imp__sub_82275480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82275480);
	return g_8333C50C;
}
PROMOTED_ENTRY(9, sub_82275480, 0x82275480) { ctx.r3.u64 = C_82001B48_GetInstance(ctx, base); }
