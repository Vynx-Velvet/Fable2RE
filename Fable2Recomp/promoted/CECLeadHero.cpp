// CECLeadHero (vtable 0x820EB4C0): methods of the class as readable C++.
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

uint64_t CECLeadHero_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8E24_B_ = int32_t(0x820C8E24);
	if (!UseLiftedCode(65, 0x82934360)) { ctx.r3.u64 = classNameString; __imp__sub_82934360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82934360);
	uint64_t TXT_820C8E24_L_{};
	int32_t stringLength{};
	GameStackFrame stackFrame(ctx, base, 96);
	stringLength = -1;
	TXT_820C8E24_L_ = str_TXT_820C8E24_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820C8E24_L_, stringLength);
	return classNameString;
}
PROMOTED_ENTRY(65, sub_82934360, 0x82934360) { ctx.r3.u64 = CECLeadHero_GetClassName(ctx, base, ctx.r3.u64); }
