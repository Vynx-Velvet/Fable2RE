// CECPhysicsSimulationRopeBridge (vtable 0x820B93C8): methods of the class as readable C++.
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

uint64_t CECPhysicsSimulationRopeBridge_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B9374_B_ = int32_t(0x820B9374);
	if (!UseLiftedCode(30, 0x824F04D8)) { ctx.r3.u64 = classNameString; __imp__sub_824F04D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824F04D8);
	uint64_t TXT_820B9374_L_{};
	int32_t length{};
	GameStackFrame stackFrame(ctx, base, 96);
	length = -1;
	TXT_820B9374_L_ = str_TXT_820B9374_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820B9374_L_, length);
	return classNameString;
}
PROMOTED_ENTRY(30, sub_824F04D8, 0x824F04D8) { ctx.r3.u64 = CECPhysicsSimulationRopeBridge_GetClassName(ctx, base, ctx.r3.u64); }
