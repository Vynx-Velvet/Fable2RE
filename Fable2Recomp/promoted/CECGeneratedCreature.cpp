// CECGeneratedCreature (vtable 0x820DF248): methods of the class as readable C++.
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

uint64_t CECGeneratedCreature_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8C68_B_ = int32_t(0x820C8C68);
	if (!UseLiftedCode(59, 0x8286FD40)) { ctx.r3.u64 = classNameString; __imp__sub_8286FD40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8286FD40);
	uint64_t TXT_820C8C68_L_{};
	int32_t stringLength{};
	GameStackFrame stackFrame(ctx, base, 96);
	stringLength = -1;
	TXT_820C8C68_L_ = str_TXT_820C8C68_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820C8C68_L_, stringLength);
	return classNameString;
}
PROMOTED_ENTRY(59, sub_8286FD40, 0x8286FD40) { ctx.r3.u64 = CECGeneratedCreature_GetClassName(ctx, base, ctx.r3.u64); }
