// CECSpellHeatable (vtable 0x82004420): methods of the class as readable C++.
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

uint64_t CECSpellHeatable_GetTypeId(CpuState& ctx, uint8_t* base) {
	if (!UseLiftedCode(68, 0x82996398)) { __imp__sub_82996398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82996398);
	uint32_t typeId{};
	typeId = 174;
	return typeId;
}
PROMOTED_ENTRY(68, sub_82996398, 0x82996398) { ctx.r3.u64 = CECSpellHeatable_GetTypeId(ctx, base); }

uint64_t CECSpellHeatable_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameResult) {
	constexpr int32_t str_TXT_820C90D4_B_ = int32_t(0x820C90D4);
	if (!UseLiftedCode(68, 0x829963A0)) { ctx.r3.u64 = classNameResult; __imp__sub_829963A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829963A0);
	uint64_t classNameString{};
	int32_t stringLength{};
	GameStackFrame stackFrame(ctx, base, 96);
	stringLength = -1;
	classNameString = str_TXT_820C90D4_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameResult, classNameString, stringLength);
	return classNameResult;
}
PROMOTED_ENTRY(68, sub_829963A0, 0x829963A0) { ctx.r3.u64 = CECSpellHeatable_GetClassName(ctx, base, ctx.r3.u64); }
