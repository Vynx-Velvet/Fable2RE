// C_820C84D0 (vtable 0x820C84D0): methods of the class as readable C++.
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

uint64_t n_sub_82638618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83499E70 = int32_t(0x83499E70);
	if (!UseLiftedCode(41, 0x82638618)) { __imp__sub_82638618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82638618);
	return g_83499E70;
}
PROMOTED_ENTRY(41, sub_82638618, 0x82638618) { ctx.r3.u64 = n_sub_82638618(ctx, base); }
