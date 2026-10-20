



// CECBloodAlcohol (vtable 0x82003FD8): methods of the class as readable C++.
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
#include "lifted/readable_support.h"

// When the alcohol level is above a threshold, reduce it by a fixed amount. Both values are floats
// stored in the game's data.
uint64_t CECBloodAlcohol_Update(CpuState& ctx, uint8_t* base, uint64_t bloodAlcoholAddr) {
	if (!UseLiftedCode(0, 0x8218AC58)) { ctx.r3.u64 = bloodAlcoholAddr; __imp__sub_8218AC58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218AC58);
	constexpr uint32_t kThresholdAddr = 0x820A0000u - 27468;
	constexpr uint32_t kReductionAddr = kThresholdAddr + 120;
	CECBloodAlcohol* bloodAlcohol = GameObject<CECBloodAlcohol>(base, bloodAlcoholAddr);
	ctx.fpscr.disableFlushMode();
	double alcoholLevel = double(bloodAlcohol->m_alcoholLevel);
	double threshold = double(LOAD_F32(kThresholdAddr));
	if (!(alcoholLevel > threshold)) return bloodAlcoholAddr;
	double reductionAmount = double(LOAD_F32(kReductionAddr));
	return CECBloodAlcohol_ReduceAlcoholLevel(ctx, base, bloodAlcoholAddr, reductionAmount);
}
PROMOTED_ENTRY(0, sub_8218AC58, 0x8218AC58) { ctx.r3.u64 = CECBloodAlcohol_Update(ctx, base, ctx.r3.u64); }

uint64_t CECBloodAlcohol_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C922C_B_ = int32_t(0x820C922C);
	if (!UseLiftedCode(65, 0x82919778)) { ctx.r3.u64 = classNameString; __imp__sub_82919778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82919778);
	uint64_t TXT_820C922C_L_{};
	int32_t stringLength{};
	GameStackFrame stackFrame(ctx, base, 96);
	stringLength = -1;
	TXT_820C922C_L_ = str_TXT_820C922C_B_;
	CCharString_ConstructFromCStr(ctx, base, classNameString, TXT_820C922C_L_, stringLength);
	return classNameString;
}
PROMOTED_ENTRY(65, sub_82919778, 0x82919778) { ctx.r3.u64 = CECBloodAlcohol_GetClassName(ctx, base, ctx.r3.u64); }
