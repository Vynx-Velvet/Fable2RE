// CECExpressionPerformer (vtable 0x82003088): methods of the class as readable C++.
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

uint64_t CECExpressionPerformer_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820ADDC0_B_ = int32_t(0x820ADDC0);
	if (!UseLiftedCode(22, 0x823E5568)) { ctx.r3.u64 = classNameString; __imp__sub_823E5568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823E5568);
	uint64_t TXT_820ADDC0_L_{};
	int32_t length{};
	GameStackFrame stackFrame(ctx, base, 96);
	length = -1;
	TXT_820ADDC0_L_ = str_TXT_820ADDC0_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820ADDC0_L_, length);
	return classNameString;
}
PROMOTED_ENTRY(22, sub_823E5568, 0x823E5568) { ctx.r3.u64 = CECExpressionPerformer_GetClassName(ctx, base, ctx.r3.u64); }
