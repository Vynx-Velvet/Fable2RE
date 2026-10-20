// CMaterialParamAlignmentQuat (vtable 0x820F1CC0): methods of the class as readable C++.
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

uint64_t CMaterialParamAlignmentQuat_GetType(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(73, 0x82A14668)) { __imp__sub_82A14668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A14668);
	uint32_t type{};
	type = 131072;
	return type;
}
PROMOTED_ENTRY(73, sub_82A14668, 0x82A14668) { ctx.r3.u64 = CMaterialParamAlignmentQuat_GetType(ctx, base); }
