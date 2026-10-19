// C_8200BBA0 (vtable 0x8200BBA0): methods of the class as readable C++.
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

uint64_t n_sub_82C2AA48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83334D88_G_ = int32_t(0x83334D88);
	if (!UseLiftedCode(90, 0x82C2AA48)) { __imp__sub_82C2AA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C2AA48);
	return TXT_83334D88_G_;
}
PROMOTED_ENTRY(90, sub_82C2AA48, 0x82C2AA48) { ctx.r3.u64 = n_sub_82C2AA48(ctx, base); }
