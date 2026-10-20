// C_820CC520 (vtable 0x820CC520): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs).Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md.A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"

uint64_t GetCAbilityActionRangedAttackString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CC2CC_B_ = int32_t(0x820CC2CC);
	if (!UseLiftedCode(45, 0x826AEA30)) { __imp__sub_826AEA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826AEA30);
	return str_TXT_820CC2CC_B_;
}
PROMOTED_ENTRY(45, sub_826AEA30, 0x826AEA30) { ctx.r3.u64 = GetCAbilityActionRangedAttackString(ctx, base); }
