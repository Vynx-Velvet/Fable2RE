// CECOwnedEntity (vtable 0x820044E0): methods of the class as readable C++.
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

uint64_t CECOwnedEntity_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BD058_B_ = int32_t(0x820BD058);
	if (!UseLiftedCode(61, 0x828AB7D8)) { ctx.r3.u64 = classNameString; __imp__sub_828AB7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828AB7D8);
	uint64_t TXT_820BD058_L_{};
	int32_t stringLength{};
	GameStackFrame stackFrame(ctx, base, 96);
	stringLength = -1;
	TXT_820BD058_L_ = str_TXT_820BD058_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820BD058_L_, stringLength);
	return classNameString;
}
PROMOTED_ENTRY(61, sub_828AB7D8, 0x828AB7D8) { ctx.r3.u64 = CECOwnedEntity_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECOwnedEntity_GetOwnerWrapper(CpuState& ctx, uint8_t* base, uint64_t ownedEntity) {
	if (!UseLiftedCode(61, 0x828ABB98)) { ctx.r3.u64 = ownedEntity; __imp__sub_828ABB98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828ABB98);
	uint64_t owner{};
	owner = CECOwnedEntity_GetOwner(ctx, base, ownedEntity);
	return owner;
}
PROMOTED_ENTRY(61, sub_828ABB98, 0x828ABB98) { ctx.r3.u64 = CECOwnedEntity_GetOwnerWrapper(ctx, base, ctx.r3.u64); }
