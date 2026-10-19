// Start-up initialisers of global objects (they register property and definition names) at
// 0x8325xxxx, as readable C++.
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

uint64_t Construct_TXT_834985C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985C4_G_ = int32_t(0x834985C4);
	constexpr int32_t str_TXT_820BD244_B_ = int32_t(0x820BD244);
	constexpr int32_t Destroy_TXT_834985C4_G__address = int32_t(0x832A30F8);
	if (!UseLiftedCode(143, 0x83250030)) { __imp__sub_83250030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250030);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C4_G_, str_TXT_820BD244_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985C4_G__address);
}
PROMOTED_ENTRY(143, sub_83250030, 0x83250030) { ctx.r3.u64 = Construct_TXT_834985C4_G_(ctx, base); }

uint64_t Construct_TXT_834985C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985C8_G_ = int32_t(0x834985C8);
	constexpr int32_t str_TXT_820A8F8C_B_ = int32_t(0x820A8F8C);
	constexpr int32_t Destroy_TXT_834985C8_G__address = int32_t(0x832A3108);
	if (!UseLiftedCode(143, 0x83250070)) { __imp__sub_83250070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250070);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C8_G_, str_TXT_820A8F8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985C8_G__address);
}
PROMOTED_ENTRY(143, sub_83250070, 0x83250070) { ctx.r3.u64 = Construct_TXT_834985C8_G_(ctx, base); }

uint64_t Construct_TXT_834985CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985CC_G_ = int32_t(0x834985CC);
	constexpr int32_t str_TXT_820A8F94_B_ = int32_t(0x820A8F94);
	constexpr int32_t Destroy_TXT_834985CC_G__address = int32_t(0x832A3118);
	if (!UseLiftedCode(143, 0x832500B0)) { __imp__sub_832500B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832500B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985CC_G_, str_TXT_820A8F94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985CC_G__address);
}
PROMOTED_ENTRY(143, sub_832500B0, 0x832500B0) { ctx.r3.u64 = Construct_TXT_834985CC_G_(ctx, base); }

uint64_t Construct_TXT_834985D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985D0_G_ = int32_t(0x834985D0);
	constexpr int32_t str_TXT_820BD24C_B_ = int32_t(0x820BD24C);
	constexpr int32_t Destroy_TXT_834985D0_G__address = int32_t(0x832A3128);
	if (!UseLiftedCode(143, 0x832500F0)) { __imp__sub_832500F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832500F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D0_G_, str_TXT_820BD24C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985D0_G__address);
}
PROMOTED_ENTRY(143, sub_832500F0, 0x832500F0) { ctx.r3.u64 = Construct_TXT_834985D0_G_(ctx, base); }

uint64_t Construct_TXT_834985D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985D4_G_ = int32_t(0x834985D4);
	constexpr int32_t str_TXT_820BD974_B_ = int32_t(0x820BD974);
	constexpr int32_t Destroy_TXT_834985D4_G__address = int32_t(0x832A3138);
	if (!UseLiftedCode(143, 0x83250130)) { __imp__sub_83250130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250130);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D4_G_, str_TXT_820BD974_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985D4_G__address);
}
PROMOTED_ENTRY(143, sub_83250130, 0x83250130) { ctx.r3.u64 = Construct_TXT_834985D4_G_(ctx, base); }

uint64_t Construct_TXT_834985D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985D8_G_ = int32_t(0x834985D8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834985D8_G__address = int32_t(0x832A3148);
	if (!UseLiftedCode(143, 0x83250170)) { __imp__sub_83250170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250170);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985D8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985D8_G__address);
}
PROMOTED_ENTRY(143, sub_83250170, 0x83250170) { ctx.r3.u64 = Construct_TXT_834985D8_G_(ctx, base); }

uint64_t Construct_TXT_834985DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985DC_G_ = int32_t(0x834985DC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834985DC_G__address = int32_t(0x832A3158);
	if (!UseLiftedCode(143, 0x832501B0)) { __imp__sub_832501B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832501B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985DC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985DC_G__address);
}
PROMOTED_ENTRY(143, sub_832501B0, 0x832501B0) { ctx.r3.u64 = Construct_TXT_834985DC_G_(ctx, base); }

uint64_t Construct_TXT_834985E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985E0_G_ = int32_t(0x834985E0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834985E0_G__address = int32_t(0x832A3168);
	if (!UseLiftedCode(143, 0x832501F0)) { __imp__sub_832501F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832501F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985E0_G__address);
}
PROMOTED_ENTRY(143, sub_832501F0, 0x832501F0) { ctx.r3.u64 = Construct_TXT_834985E0_G_(ctx, base); }

uint64_t Construct_TXT_834985E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985E4_G_ = int32_t(0x834985E4);
	constexpr int32_t str_TXT_820BDCCC_B_ = int32_t(0x820BDCCC);
	constexpr int32_t Destroy_TXT_834985E4_G__address = int32_t(0x832A3178);
	if (!UseLiftedCode(143, 0x83250230)) { __imp__sub_83250230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E4_G_, str_TXT_820BDCCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985E4_G__address);
}
PROMOTED_ENTRY(143, sub_83250230, 0x83250230) { ctx.r3.u64 = Construct_TXT_834985E4_G_(ctx, base); }

uint64_t Construct_TXT_834985E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985E8_G_ = int32_t(0x834985E8);
	constexpr int32_t str_TXT_820BDCD4_B_ = int32_t(0x820BDCD4);
	constexpr int32_t Destroy_TXT_834985E8_G__address = int32_t(0x832A3188);
	if (!UseLiftedCode(143, 0x83250270)) { __imp__sub_83250270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250270);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985E8_G_, str_TXT_820BDCD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985E8_G__address);
}
PROMOTED_ENTRY(143, sub_83250270, 0x83250270) { ctx.r3.u64 = Construct_TXT_834985E8_G_(ctx, base); }

uint64_t Construct_TXT_834985EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985EC_G_ = int32_t(0x834985EC);
	constexpr int32_t str_TXT_820BDCDC_B_ = int32_t(0x820BDCDC);
	constexpr int32_t Destroy_TXT_834985EC_G__address = int32_t(0x832A3198);
	if (!UseLiftedCode(143, 0x832502B0)) { __imp__sub_832502B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832502B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985EC_G_, str_TXT_820BDCDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985EC_G__address);
}
PROMOTED_ENTRY(143, sub_832502B0, 0x832502B0) { ctx.r3.u64 = Construct_TXT_834985EC_G_(ctx, base); }

uint64_t Construct_TXT_834985F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985F0_G_ = int32_t(0x834985F0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834985F0_G__address = int32_t(0x832A31A8);
	if (!UseLiftedCode(143, 0x832502F0)) { __imp__sub_832502F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832502F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985F0_G__address);
}
PROMOTED_ENTRY(143, sub_832502F0, 0x832502F0) { ctx.r3.u64 = Construct_TXT_834985F0_G_(ctx, base); }

uint64_t Construct_TXT_834985F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985F4_G_ = int32_t(0x834985F4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834985F4_G__address = int32_t(0x832A31B8);
	if (!UseLiftedCode(143, 0x83250330)) { __imp__sub_83250330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250330);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985F4_G__address);
}
PROMOTED_ENTRY(143, sub_83250330, 0x83250330) { ctx.r3.u64 = Construct_TXT_834985F4_G_(ctx, base); }

uint64_t Construct_TXT_834985F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985F8_G_ = int32_t(0x834985F8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834985F8_G__address = int32_t(0x832A31C8);
	if (!UseLiftedCode(143, 0x83250370)) { __imp__sub_83250370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250370);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985F8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985F8_G__address);
}
PROMOTED_ENTRY(143, sub_83250370, 0x83250370) { ctx.r3.u64 = Construct_TXT_834985F8_G_(ctx, base); }

uint64_t Construct_TXT_834985FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985FC_G_ = int32_t(0x834985FC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834985FC_G__address = int32_t(0x832A31D8);
	if (!UseLiftedCode(143, 0x832503B0)) { __imp__sub_832503B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832503B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985FC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985FC_G__address);
}
PROMOTED_ENTRY(143, sub_832503B0, 0x832503B0) { ctx.r3.u64 = Construct_TXT_834985FC_G_(ctx, base); }

uint64_t Construct_TXT_83498600_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498600_G_ = int32_t(0x83498600);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498600_G__address = int32_t(0x832A31E8);
	if (!UseLiftedCode(143, 0x832503F0)) { __imp__sub_832503F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832503F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498600_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498600_G__address);
}
PROMOTED_ENTRY(143, sub_832503F0, 0x832503F0) { ctx.r3.u64 = Construct_TXT_83498600_G_(ctx, base); }

uint64_t Construct_TXT_83498604_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498604_G_ = int32_t(0x83498604);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498604_G__address = int32_t(0x832A31F8);
	if (!UseLiftedCode(143, 0x83250430)) { __imp__sub_83250430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250430);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498604_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498604_G__address);
}
PROMOTED_ENTRY(143, sub_83250430, 0x83250430) { ctx.r3.u64 = Construct_TXT_83498604_G_(ctx, base); }

uint64_t Construct_TXT_83498608_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498608_G_ = int32_t(0x83498608);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498608_G__address = int32_t(0x832A3208);
	if (!UseLiftedCode(143, 0x83250470)) { __imp__sub_83250470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250470);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498608_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498608_G__address);
}
PROMOTED_ENTRY(143, sub_83250470, 0x83250470) { ctx.r3.u64 = Construct_TXT_83498608_G_(ctx, base); }

uint64_t Construct_TXT_8349860C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349860C_G_ = int32_t(0x8349860C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349860C_G__address = int32_t(0x832A3218);
	if (!UseLiftedCode(143, 0x832504B0)) { __imp__sub_832504B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832504B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349860C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349860C_G__address);
}
PROMOTED_ENTRY(143, sub_832504B0, 0x832504B0) { ctx.r3.u64 = Construct_TXT_8349860C_G_(ctx, base); }

uint64_t Construct_TXT_83498610_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498610_G_ = int32_t(0x83498610);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498610_G__address = int32_t(0x832A3228);
	if (!UseLiftedCode(143, 0x832504F0)) { __imp__sub_832504F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832504F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498610_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498610_G__address);
}
PROMOTED_ENTRY(143, sub_832504F0, 0x832504F0) { ctx.r3.u64 = Construct_TXT_83498610_G_(ctx, base); }

uint64_t n_sub_83250530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_83498614 = int32_t(0x83498614);
	constexpr int32_t n_sub_832A3238_address = int32_t(0x832A3238);
	if (!UseLiftedCode(143, 0x83250530)) { __imp__sub_83250530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498614, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832A3238_address);
}
PROMOTED_ENTRY(143, sub_83250530, 0x83250530) { ctx.r3.u64 = n_sub_83250530(ctx, base); }

uint64_t Construct_TXT_83498624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498624_G_ = int32_t(0x83498624);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498624_G__address = int32_t(0x832A3280);
	if (!UseLiftedCode(143, 0x832505A8)) { __imp__sub_832505A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832505A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498624_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498624_G__address);
}
PROMOTED_ENTRY(143, sub_832505A8, 0x832505A8) { ctx.r3.u64 = Construct_TXT_83498624_G_(ctx, base); }

uint64_t Construct_TXT_83498628_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498628_G_ = int32_t(0x83498628);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498628_G__address = int32_t(0x832A3290);
	if (!UseLiftedCode(143, 0x832505E8)) { __imp__sub_832505E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832505E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498628_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498628_G__address);
}
PROMOTED_ENTRY(143, sub_832505E8, 0x832505E8) { ctx.r3.u64 = Construct_TXT_83498628_G_(ctx, base); }

uint64_t Construct_TXT_8349862C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349862C_G_ = int32_t(0x8349862C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349862C_G__address = int32_t(0x832A32A0);
	if (!UseLiftedCode(143, 0x83250628)) { __imp__sub_83250628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349862C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349862C_G__address);
}
PROMOTED_ENTRY(143, sub_83250628, 0x83250628) { ctx.r3.u64 = Construct_TXT_8349862C_G_(ctx, base); }

uint64_t Construct_TXT_83498648_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498648_G_ = int32_t(0x83498648);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498648_G__address = int32_t(0x832A32B0);
	if (!UseLiftedCode(143, 0x832507B8)) { __imp__sub_832507B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832507B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498648_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498648_G__address);
}
PROMOTED_ENTRY(143, sub_832507B8, 0x832507B8) { ctx.r3.u64 = Construct_TXT_83498648_G_(ctx, base); }

uint64_t Construct_TXT_8349864C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349864C_G_ = int32_t(0x8349864C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349864C_G__address = int32_t(0x832A32C0);
	if (!UseLiftedCode(143, 0x832507F8)) { __imp__sub_832507F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832507F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349864C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349864C_G__address);
}
PROMOTED_ENTRY(143, sub_832507F8, 0x832507F8) { ctx.r3.u64 = Construct_TXT_8349864C_G_(ctx, base); }

uint64_t Construct_TXT_83498650_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498650_G_ = int32_t(0x83498650);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498650_G__address = int32_t(0x832A32D0);
	if (!UseLiftedCode(143, 0x83250838)) { __imp__sub_83250838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498650_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498650_G__address);
}
PROMOTED_ENTRY(143, sub_83250838, 0x83250838) { ctx.r3.u64 = Construct_TXT_83498650_G_(ctx, base); }

uint64_t Construct_TXT_834986A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986A0_G_ = int32_t(0x834986A0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834986A0_G__address = int32_t(0x832A32E0);
	if (!UseLiftedCode(143, 0x83250888)) { __imp__sub_83250888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986A0_G__address);
}
PROMOTED_ENTRY(143, sub_83250888, 0x83250888) { ctx.r3.u64 = Construct_TXT_834986A0_G_(ctx, base); }

uint64_t Construct_TXT_834986A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986A4_G_ = int32_t(0x834986A4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834986A4_G__address = int32_t(0x832A32F0);
	if (!UseLiftedCode(143, 0x832508C8)) { __imp__sub_832508C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832508C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986A4_G__address);
}
PROMOTED_ENTRY(143, sub_832508C8, 0x832508C8) { ctx.r3.u64 = Construct_TXT_834986A4_G_(ctx, base); }

uint64_t Construct_TXT_834986A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986A8_G_ = int32_t(0x834986A8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834986A8_G__address = int32_t(0x832A3300);
	if (!UseLiftedCode(143, 0x83250908)) { __imp__sub_83250908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986A8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986A8_G__address);
}
PROMOTED_ENTRY(143, sub_83250908, 0x83250908) { ctx.r3.u64 = Construct_TXT_834986A8_G_(ctx, base); }

uint64_t Construct_TXT_834986AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986AC_G_ = int32_t(0x834986AC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834986AC_G__address = int32_t(0x832A3320);
	if (!UseLiftedCode(143, 0x83250948)) { __imp__sub_83250948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986AC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986AC_G__address);
}
PROMOTED_ENTRY(143, sub_83250948, 0x83250948) { ctx.r3.u64 = Construct_TXT_834986AC_G_(ctx, base); }

uint64_t Construct_TXT_834986B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986B0_G_ = int32_t(0x834986B0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834986B0_G__address = int32_t(0x832A3330);
	if (!UseLiftedCode(143, 0x83250988)) { __imp__sub_83250988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986B0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986B0_G__address);
}
PROMOTED_ENTRY(143, sub_83250988, 0x83250988) { ctx.r3.u64 = Construct_TXT_834986B0_G_(ctx, base); }

uint64_t Construct_TXT_834986B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986B4_G_ = int32_t(0x834986B4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834986B4_G__address = int32_t(0x832A3340);
	if (!UseLiftedCode(143, 0x832509C8)) { __imp__sub_832509C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832509C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986B4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986B4_G__address);
}
PROMOTED_ENTRY(143, sub_832509C8, 0x832509C8) { ctx.r3.u64 = Construct_TXT_834986B4_G_(ctx, base); }

uint64_t Construct_TXT_834986D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986D4_G_ = int32_t(0x834986D4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834986D4_G__address = int32_t(0x832A3350);
	if (!UseLiftedCode(143, 0x83250B90)) { __imp__sub_83250B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250B90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986D4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986D4_G__address);
}
PROMOTED_ENTRY(143, sub_83250B90, 0x83250B90) { ctx.r3.u64 = Construct_TXT_834986D4_G_(ctx, base); }

uint64_t Construct_TXT_834986D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986D8_G_ = int32_t(0x834986D8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834986D8_G__address = int32_t(0x832A3360);
	if (!UseLiftedCode(143, 0x83250BD0)) { __imp__sub_83250BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250BD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986D8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986D8_G__address);
}
PROMOTED_ENTRY(143, sub_83250BD0, 0x83250BD0) { ctx.r3.u64 = Construct_TXT_834986D8_G_(ctx, base); }

uint64_t Construct_TXT_834986DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986DC_G_ = int32_t(0x834986DC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834986DC_G__address = int32_t(0x832A3370);
	if (!UseLiftedCode(143, 0x83250C10)) { __imp__sub_83250C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986DC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986DC_G__address);
}
PROMOTED_ENTRY(143, sub_83250C10, 0x83250C10) { ctx.r3.u64 = Construct_TXT_834986DC_G_(ctx, base); }

uint64_t Construct_TXT_834986E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986E0_G_ = int32_t(0x834986E0);
	constexpr int32_t str_TXT_820BEF3C_B_ = int32_t(0x820BEF3C);
	constexpr int32_t Destroy_TXT_834986E0_G__address = int32_t(0x832A3380);
	if (!UseLiftedCode(143, 0x83250C50)) { __imp__sub_83250C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E0_G_, str_TXT_820BEF3C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986E0_G__address);
}
PROMOTED_ENTRY(143, sub_83250C50, 0x83250C50) { ctx.r3.u64 = Construct_TXT_834986E0_G_(ctx, base); }

uint64_t Construct_TXT_834986E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986E4_G_ = int32_t(0x834986E4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834986E4_G__address = int32_t(0x832A3390);
	if (!UseLiftedCode(143, 0x83250C90)) { __imp__sub_83250C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250C90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986E4_G__address);
}
PROMOTED_ENTRY(143, sub_83250C90, 0x83250C90) { ctx.r3.u64 = Construct_TXT_834986E4_G_(ctx, base); }

uint64_t Construct_TXT_834986E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986E8_G_ = int32_t(0x834986E8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834986E8_G__address = int32_t(0x832A33A0);
	if (!UseLiftedCode(143, 0x83250CD0)) { __imp__sub_83250CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986E8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986E8_G__address);
}
PROMOTED_ENTRY(143, sub_83250CD0, 0x83250CD0) { ctx.r3.u64 = Construct_TXT_834986E8_G_(ctx, base); }

uint64_t Construct_TXT_834986EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986EC_G_ = int32_t(0x834986EC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834986EC_G__address = int32_t(0x832A33B0);
	if (!UseLiftedCode(143, 0x83250D10)) { __imp__sub_83250D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250D10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986EC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986EC_G__address);
}
PROMOTED_ENTRY(143, sub_83250D10, 0x83250D10) { ctx.r3.u64 = Construct_TXT_834986EC_G_(ctx, base); }

uint64_t Construct_TXT_834986F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986F4_G_ = int32_t(0x834986F4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834986F4_G__address = int32_t(0x832A33C0);
	if (!UseLiftedCode(143, 0x83250D88)) { __imp__sub_83250D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986F4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986F4_G__address);
}
PROMOTED_ENTRY(143, sub_83250D88, 0x83250D88) { ctx.r3.u64 = Construct_TXT_834986F4_G_(ctx, base); }

uint64_t Construct_TXT_834986F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986F8_G_ = int32_t(0x834986F8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834986F8_G__address = int32_t(0x832A33D0);
	if (!UseLiftedCode(143, 0x83250DC8)) { __imp__sub_83250DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986F8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986F8_G__address);
}
PROMOTED_ENTRY(143, sub_83250DC8, 0x83250DC8) { ctx.r3.u64 = Construct_TXT_834986F8_G_(ctx, base); }

uint64_t Construct_TXT_834986FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834986FC_G_ = int32_t(0x834986FC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834986FC_G__address = int32_t(0x832A33E0);
	if (!UseLiftedCode(143, 0x83250E08)) { __imp__sub_83250E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834986FC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834986FC_G__address);
}
PROMOTED_ENTRY(143, sub_83250E08, 0x83250E08) { ctx.r3.u64 = Construct_TXT_834986FC_G_(ctx, base); }

uint64_t n_sub_83250E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83498700 = int32_t(0x83498700);
	constexpr int32_t n_sub_832A33F0_address = int32_t(0x832A33F0);
	if (!UseLiftedCode(143, 0x83250E48)) { __imp__sub_83250E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498700, (int64_t)str_TXT_820B0000_B_ + 11652, -1);
	return RegisterAtExit(ctx, base, n_sub_832A33F0_address);
}
PROMOTED_ENTRY(143, sub_83250E48, 0x83250E48) { ctx.r3.u64 = n_sub_83250E48(ctx, base); }

uint64_t n_sub_83250E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83498704 = int32_t(0x83498704);
	constexpr int32_t n_sub_832A3400_address = int32_t(0x832A3400);
	if (!UseLiftedCode(143, 0x83250E88)) { __imp__sub_83250E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498704, (int64_t)str_TXT_820B0000_B_ + 11656, -1);
	return RegisterAtExit(ctx, base, n_sub_832A3400_address);
}
PROMOTED_ENTRY(143, sub_83250E88, 0x83250E88) { ctx.r3.u64 = n_sub_83250E88(ctx, base); }

uint64_t Construct_TXT_83498708_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498708_G_ = int32_t(0x83498708);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498708_G__address = int32_t(0x832A3410);
	if (!UseLiftedCode(143, 0x83250EC8)) { __imp__sub_83250EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498708_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498708_G__address);
}
PROMOTED_ENTRY(143, sub_83250EC8, 0x83250EC8) { ctx.r3.u64 = Construct_TXT_83498708_G_(ctx, base); }

uint64_t Construct_TXT_8349870C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349870C_G_ = int32_t(0x8349870C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349870C_G__address = int32_t(0x832A3420);
	if (!UseLiftedCode(143, 0x83250F08)) { __imp__sub_83250F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349870C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349870C_G__address);
}
PROMOTED_ENTRY(143, sub_83250F08, 0x83250F08) { ctx.r3.u64 = Construct_TXT_8349870C_G_(ctx, base); }

uint64_t Construct_TXT_83498710_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498710_G_ = int32_t(0x83498710);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498710_G__address = int32_t(0x832A3430);
	if (!UseLiftedCode(143, 0x83250F48)) { __imp__sub_83250F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498710_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498710_G__address);
}
PROMOTED_ENTRY(143, sub_83250F48, 0x83250F48) { ctx.r3.u64 = Construct_TXT_83498710_G_(ctx, base); }

uint64_t Construct_TXT_83498714_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498714_G_ = int32_t(0x83498714);
	constexpr int32_t str_TXT_820BF6A0_B_ = int32_t(0x820BF6A0);
	constexpr int32_t Destroy_TXT_83498714_G__address = int32_t(0x832A3440);
	if (!UseLiftedCode(143, 0x83250F88)) { __imp__sub_83250F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498714_G_, str_TXT_820BF6A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498714_G__address);
}
PROMOTED_ENTRY(143, sub_83250F88, 0x83250F88) { ctx.r3.u64 = Construct_TXT_83498714_G_(ctx, base); }

uint64_t Construct_TXT_83498718_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498718_G_ = int32_t(0x83498718);
	constexpr int32_t str_TXT_820BF6B8_B_ = int32_t(0x820BF6B8);
	constexpr int32_t Destroy_TXT_83498718_G__address = int32_t(0x832A3450);
	if (!UseLiftedCode(143, 0x83250FC8)) { __imp__sub_83250FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498718_G_, str_TXT_820BF6B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498718_G__address);
}
PROMOTED_ENTRY(143, sub_83250FC8, 0x83250FC8) { ctx.r3.u64 = Construct_TXT_83498718_G_(ctx, base); }

uint64_t Construct_TXT_8349871C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349871C_G_ = int32_t(0x8349871C);
	constexpr int32_t str_TXT_820BF6D0_B_ = int32_t(0x820BF6D0);
	constexpr int32_t Destroy_TXT_8349871C_G__address = int32_t(0x832A3460);
	if (!UseLiftedCode(143, 0x83251008)) { __imp__sub_83251008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349871C_G_, str_TXT_820BF6D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349871C_G__address);
}
PROMOTED_ENTRY(143, sub_83251008, 0x83251008) { ctx.r3.u64 = Construct_TXT_8349871C_G_(ctx, base); }

uint64_t Construct_TXT_83498720_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498720_G_ = int32_t(0x83498720);
	constexpr int32_t str_TXT_820BF6E8_B_ = int32_t(0x820BF6E8);
	constexpr int32_t Destroy_TXT_83498720_G__address = int32_t(0x832A3470);
	if (!UseLiftedCode(143, 0x83251048)) { __imp__sub_83251048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498720_G_, str_TXT_820BF6E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498720_G__address);
}
PROMOTED_ENTRY(143, sub_83251048, 0x83251048) { ctx.r3.u64 = Construct_TXT_83498720_G_(ctx, base); }

uint64_t Construct_TXT_83498724_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498724_G_ = int32_t(0x83498724);
	constexpr int32_t str_TXT_820BF700_B_ = int32_t(0x820BF700);
	constexpr int32_t Destroy_TXT_83498724_G__address = int32_t(0x832A3480);
	if (!UseLiftedCode(143, 0x83251088)) { __imp__sub_83251088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498724_G_, str_TXT_820BF700_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498724_G__address);
}
PROMOTED_ENTRY(143, sub_83251088, 0x83251088) { ctx.r3.u64 = Construct_TXT_83498724_G_(ctx, base); }

uint64_t Construct_TXT_83498728_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498728_G_ = int32_t(0x83498728);
	constexpr int32_t str_TXT_820BF714_B_ = int32_t(0x820BF714);
	constexpr int32_t Destroy_TXT_83498728_G__address = int32_t(0x832A3490);
	if (!UseLiftedCode(143, 0x832510C8)) { __imp__sub_832510C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832510C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498728_G_, str_TXT_820BF714_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498728_G__address);
}
PROMOTED_ENTRY(143, sub_832510C8, 0x832510C8) { ctx.r3.u64 = Construct_TXT_83498728_G_(ctx, base); }

uint64_t Construct_TXT_8349872C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349872C_G_ = int32_t(0x8349872C);
	constexpr int32_t str_TXT_820BF728_B_ = int32_t(0x820BF728);
	constexpr int32_t Destroy_TXT_8349872C_G__address = int32_t(0x832A34A0);
	if (!UseLiftedCode(143, 0x83251108)) { __imp__sub_83251108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349872C_G_, str_TXT_820BF728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349872C_G__address);
}
PROMOTED_ENTRY(143, sub_83251108, 0x83251108) { ctx.r3.u64 = Construct_TXT_8349872C_G_(ctx, base); }

uint64_t Construct_TXT_83498730_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498730_G_ = int32_t(0x83498730);
	constexpr int32_t str_TXT_820BF738_B_ = int32_t(0x820BF738);
	constexpr int32_t Destroy_TXT_83498730_G__address = int32_t(0x832A34B0);
	if (!UseLiftedCode(143, 0x83251148)) { __imp__sub_83251148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498730_G_, str_TXT_820BF738_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498730_G__address);
}
PROMOTED_ENTRY(143, sub_83251148, 0x83251148) { ctx.r3.u64 = Construct_TXT_83498730_G_(ctx, base); }

uint64_t Construct_TXT_83498734_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498734_G_ = int32_t(0x83498734);
	constexpr int32_t str_TXT_820BF750_B_ = int32_t(0x820BF750);
	constexpr int32_t Destroy_TXT_83498734_G__address = int32_t(0x832A34C0);
	if (!UseLiftedCode(143, 0x83251188)) { __imp__sub_83251188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498734_G_, str_TXT_820BF750_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498734_G__address);
}
PROMOTED_ENTRY(143, sub_83251188, 0x83251188) { ctx.r3.u64 = Construct_TXT_83498734_G_(ctx, base); }

uint64_t Construct_TXT_83498738_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498738_G_ = int32_t(0x83498738);
	constexpr int32_t str_TXT_820BF768_B_ = int32_t(0x820BF768);
	constexpr int32_t Destroy_TXT_83498738_G__address = int32_t(0x832A34D0);
	if (!UseLiftedCode(143, 0x832511C8)) { __imp__sub_832511C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832511C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498738_G_, str_TXT_820BF768_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498738_G__address);
}
PROMOTED_ENTRY(143, sub_832511C8, 0x832511C8) { ctx.r3.u64 = Construct_TXT_83498738_G_(ctx, base); }

uint64_t Construct_TXT_8349873C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349873C_G_ = int32_t(0x8349873C);
	constexpr int32_t str_TXT_820BF780_B_ = int32_t(0x820BF780);
	constexpr int32_t Destroy_TXT_8349873C_G__address = int32_t(0x832A34E0);
	if (!UseLiftedCode(143, 0x83251208)) { __imp__sub_83251208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349873C_G_, str_TXT_820BF780_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349873C_G__address);
}
PROMOTED_ENTRY(143, sub_83251208, 0x83251208) { ctx.r3.u64 = Construct_TXT_8349873C_G_(ctx, base); }

uint64_t Construct_TXT_83498740_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498740_G_ = int32_t(0x83498740);
	constexpr int32_t str_TXT_820BF794_B_ = int32_t(0x820BF794);
	constexpr int32_t Destroy_TXT_83498740_G__address = int32_t(0x832A34F0);
	if (!UseLiftedCode(143, 0x83251248)) { __imp__sub_83251248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498740_G_, str_TXT_820BF794_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498740_G__address);
}
PROMOTED_ENTRY(143, sub_83251248, 0x83251248) { ctx.r3.u64 = Construct_TXT_83498740_G_(ctx, base); }

uint64_t Construct_TXT_83498744_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498744_G_ = int32_t(0x83498744);
	constexpr int32_t str_TXT_820BF7B0_B_ = int32_t(0x820BF7B0);
	constexpr int32_t Destroy_TXT_83498744_G__address = int32_t(0x832A3500);
	if (!UseLiftedCode(143, 0x83251288)) { __imp__sub_83251288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498744_G_, str_TXT_820BF7B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498744_G__address);
}
PROMOTED_ENTRY(143, sub_83251288, 0x83251288) { ctx.r3.u64 = Construct_TXT_83498744_G_(ctx, base); }

uint64_t Construct_TXT_83498748_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498748_G_ = int32_t(0x83498748);
	constexpr int32_t str_TXT_820BF7C8_B_ = int32_t(0x820BF7C8);
	constexpr int32_t Destroy_TXT_83498748_G__address = int32_t(0x832A3510);
	if (!UseLiftedCode(143, 0x832512C8)) { __imp__sub_832512C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832512C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498748_G_, str_TXT_820BF7C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498748_G__address);
}
PROMOTED_ENTRY(143, sub_832512C8, 0x832512C8) { ctx.r3.u64 = Construct_TXT_83498748_G_(ctx, base); }

uint64_t Construct_TXT_8349874C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349874C_G_ = int32_t(0x8349874C);
	constexpr int32_t str_TXT_820BF7DC_B_ = int32_t(0x820BF7DC);
	constexpr int32_t Destroy_TXT_8349874C_G__address = int32_t(0x832A3520);
	if (!UseLiftedCode(143, 0x83251308)) { __imp__sub_83251308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349874C_G_, str_TXT_820BF7DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349874C_G__address);
}
PROMOTED_ENTRY(143, sub_83251308, 0x83251308) { ctx.r3.u64 = Construct_TXT_8349874C_G_(ctx, base); }

uint64_t Construct_TXT_83498750_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498750_G_ = int32_t(0x83498750);
	constexpr int32_t str_TXT_820BF7F0_B_ = int32_t(0x820BF7F0);
	constexpr int32_t Destroy_TXT_83498750_G__address = int32_t(0x832A3530);
	if (!UseLiftedCode(143, 0x83251348)) { __imp__sub_83251348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498750_G_, str_TXT_820BF7F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498750_G__address);
}
PROMOTED_ENTRY(143, sub_83251348, 0x83251348) { ctx.r3.u64 = Construct_TXT_83498750_G_(ctx, base); }

uint64_t Construct_TXT_83498754_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498754_G_ = int32_t(0x83498754);
	constexpr int32_t str_TXT_820BF804_B_ = int32_t(0x820BF804);
	constexpr int32_t Destroy_TXT_83498754_G__address = int32_t(0x832A3540);
	if (!UseLiftedCode(143, 0x83251388)) { __imp__sub_83251388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498754_G_, str_TXT_820BF804_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498754_G__address);
}
PROMOTED_ENTRY(143, sub_83251388, 0x83251388) { ctx.r3.u64 = Construct_TXT_83498754_G_(ctx, base); }

uint64_t Construct_TXT_83498758_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498758_G_ = int32_t(0x83498758);
	constexpr int32_t str_TXT_820BF818_B_ = int32_t(0x820BF818);
	constexpr int32_t Destroy_TXT_83498758_G__address = int32_t(0x832A3550);
	if (!UseLiftedCode(143, 0x832513C8)) { __imp__sub_832513C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832513C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498758_G_, str_TXT_820BF818_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498758_G__address);
}
PROMOTED_ENTRY(143, sub_832513C8, 0x832513C8) { ctx.r3.u64 = Construct_TXT_83498758_G_(ctx, base); }

uint64_t Construct_TXT_8349875C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349875C_G_ = int32_t(0x8349875C);
	constexpr int32_t str_TXT_820BF828_B_ = int32_t(0x820BF828);
	constexpr int32_t Destroy_TXT_8349875C_G__address = int32_t(0x832A3560);
	if (!UseLiftedCode(143, 0x83251408)) { __imp__sub_83251408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349875C_G_, str_TXT_820BF828_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349875C_G__address);
}
PROMOTED_ENTRY(143, sub_83251408, 0x83251408) { ctx.r3.u64 = Construct_TXT_8349875C_G_(ctx, base); }

uint64_t Construct_TXT_83498760_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498760_G_ = int32_t(0x83498760);
	constexpr int32_t str_TXT_820BF838_B_ = int32_t(0x820BF838);
	constexpr int32_t Destroy_TXT_83498760_G__address = int32_t(0x832A3570);
	if (!UseLiftedCode(143, 0x83251448)) { __imp__sub_83251448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498760_G_, str_TXT_820BF838_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498760_G__address);
}
PROMOTED_ENTRY(143, sub_83251448, 0x83251448) { ctx.r3.u64 = Construct_TXT_83498760_G_(ctx, base); }

uint64_t Construct_TXT_83498764_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498764_G_ = int32_t(0x83498764);
	constexpr int32_t str_TXT_820BF84C_B_ = int32_t(0x820BF84C);
	constexpr int32_t Destroy_TXT_83498764_G__address = int32_t(0x832A3580);
	if (!UseLiftedCode(143, 0x83251488)) { __imp__sub_83251488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498764_G_, str_TXT_820BF84C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498764_G__address);
}
PROMOTED_ENTRY(143, sub_83251488, 0x83251488) { ctx.r3.u64 = Construct_TXT_83498764_G_(ctx, base); }

uint64_t Construct_TXT_83498768_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498768_G_ = int32_t(0x83498768);
	constexpr int32_t str_TXT_820BF86C_B_ = int32_t(0x820BF86C);
	constexpr int32_t Destroy_TXT_83498768_G__address = int32_t(0x832A3590);
	if (!UseLiftedCode(143, 0x832514C8)) { __imp__sub_832514C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832514C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498768_G_, str_TXT_820BF86C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498768_G__address);
}
PROMOTED_ENTRY(143, sub_832514C8, 0x832514C8) { ctx.r3.u64 = Construct_TXT_83498768_G_(ctx, base); }

uint64_t Construct_TXT_8349876C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349876C_G_ = int32_t(0x8349876C);
	constexpr int32_t str_TXT_820BF880_B_ = int32_t(0x820BF880);
	constexpr int32_t Destroy_TXT_8349876C_G__address = int32_t(0x832A35A0);
	if (!UseLiftedCode(143, 0x83251508)) { __imp__sub_83251508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349876C_G_, str_TXT_820BF880_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349876C_G__address);
}
PROMOTED_ENTRY(143, sub_83251508, 0x83251508) { ctx.r3.u64 = Construct_TXT_8349876C_G_(ctx, base); }

uint64_t Construct_TXT_83498770_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498770_G_ = int32_t(0x83498770);
	constexpr int32_t str_TXT_820BF894_B_ = int32_t(0x820BF894);
	constexpr int32_t Destroy_TXT_83498770_G__address = int32_t(0x832A35B0);
	if (!UseLiftedCode(143, 0x83251548)) { __imp__sub_83251548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498770_G_, str_TXT_820BF894_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498770_G__address);
}
PROMOTED_ENTRY(143, sub_83251548, 0x83251548) { ctx.r3.u64 = Construct_TXT_83498770_G_(ctx, base); }

uint64_t Construct_TXT_83498774_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498774_G_ = int32_t(0x83498774);
	constexpr int32_t str_TXT_820BF8AC_B_ = int32_t(0x820BF8AC);
	constexpr int32_t Destroy_TXT_83498774_G__address = int32_t(0x832A35C0);
	if (!UseLiftedCode(143, 0x83251588)) { __imp__sub_83251588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498774_G_, str_TXT_820BF8AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498774_G__address);
}
PROMOTED_ENTRY(143, sub_83251588, 0x83251588) { ctx.r3.u64 = Construct_TXT_83498774_G_(ctx, base); }

uint64_t Construct_TXT_83498778_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498778_G_ = int32_t(0x83498778);
	constexpr int32_t str_TXT_820BF894_B_ = int32_t(0x820BF894);
	constexpr int32_t Destroy_TXT_83498778_G__address = int32_t(0x832A35D0);
	if (!UseLiftedCode(143, 0x832515C8)) { __imp__sub_832515C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832515C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498778_G_, str_TXT_820BF894_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498778_G__address);
}
PROMOTED_ENTRY(143, sub_832515C8, 0x832515C8) { ctx.r3.u64 = Construct_TXT_83498778_G_(ctx, base); }

uint64_t Construct_TXT_8349877C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349877C_G_ = int32_t(0x8349877C);
	constexpr int32_t str_TXT_820BF8AC_B_ = int32_t(0x820BF8AC);
	constexpr int32_t Destroy_TXT_8349877C_G__address = int32_t(0x832A35E0);
	if (!UseLiftedCode(143, 0x83251608)) { __imp__sub_83251608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349877C_G_, str_TXT_820BF8AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349877C_G__address);
}
PROMOTED_ENTRY(143, sub_83251608, 0x83251608) { ctx.r3.u64 = Construct_TXT_8349877C_G_(ctx, base); }

uint64_t Construct_TXT_83498780_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498780_G_ = int32_t(0x83498780);
	constexpr int32_t str_TXT_820BF728_B_ = int32_t(0x820BF728);
	constexpr int32_t Destroy_TXT_83498780_G__address = int32_t(0x832A35F0);
	if (!UseLiftedCode(143, 0x83251648)) { __imp__sub_83251648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498780_G_, str_TXT_820BF728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498780_G__address);
}
PROMOTED_ENTRY(143, sub_83251648, 0x83251648) { ctx.r3.u64 = Construct_TXT_83498780_G_(ctx, base); }

uint64_t Construct_TXT_83498784_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498784_G_ = int32_t(0x83498784);
	constexpr int32_t str_TXT_820BF738_B_ = int32_t(0x820BF738);
	constexpr int32_t Destroy_TXT_83498784_G__address = int32_t(0x832A3600);
	if (!UseLiftedCode(143, 0x83251688)) { __imp__sub_83251688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251688);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498784_G_, str_TXT_820BF738_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498784_G__address);
}
PROMOTED_ENTRY(143, sub_83251688, 0x83251688) { ctx.r3.u64 = Construct_TXT_83498784_G_(ctx, base); }

uint64_t Construct_TXT_83498788_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498788_G_ = int32_t(0x83498788);
	constexpr int32_t str_TXT_820BF8C4_B_ = int32_t(0x820BF8C4);
	constexpr int32_t Destroy_TXT_83498788_G__address = int32_t(0x832A3610);
	if (!UseLiftedCode(143, 0x832516C8)) { __imp__sub_832516C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832516C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498788_G_, str_TXT_820BF8C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498788_G__address);
}
PROMOTED_ENTRY(143, sub_832516C8, 0x832516C8) { ctx.r3.u64 = Construct_TXT_83498788_G_(ctx, base); }

uint64_t Construct_TXT_8349878C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349878C_G_ = int32_t(0x8349878C);
	constexpr int32_t str_TXT_820BF8D8_B_ = int32_t(0x820BF8D8);
	constexpr int32_t Destroy_TXT_8349878C_G__address = int32_t(0x832A3620);
	if (!UseLiftedCode(143, 0x83251708)) { __imp__sub_83251708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349878C_G_, str_TXT_820BF8D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349878C_G__address);
}
PROMOTED_ENTRY(143, sub_83251708, 0x83251708) { ctx.r3.u64 = Construct_TXT_8349878C_G_(ctx, base); }

uint64_t Construct_TXT_83498790_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498790_G_ = int32_t(0x83498790);
	constexpr int32_t str_TXT_820BF8F0_B_ = int32_t(0x820BF8F0);
	constexpr int32_t Destroy_TXT_83498790_G__address = int32_t(0x832A3630);
	if (!UseLiftedCode(143, 0x83251748)) { __imp__sub_83251748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251748);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498790_G_, str_TXT_820BF8F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498790_G__address);
}
PROMOTED_ENTRY(143, sub_83251748, 0x83251748) { ctx.r3.u64 = Construct_TXT_83498790_G_(ctx, base); }

uint64_t Construct_TXT_83498794_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498794_G_ = int32_t(0x83498794);
	constexpr int32_t str_TXT_820BF908_B_ = int32_t(0x820BF908);
	constexpr int32_t Destroy_TXT_83498794_G__address = int32_t(0x832A3640);
	if (!UseLiftedCode(143, 0x83251788)) { __imp__sub_83251788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498794_G_, str_TXT_820BF908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498794_G__address);
}
PROMOTED_ENTRY(143, sub_83251788, 0x83251788) { ctx.r3.u64 = Construct_TXT_83498794_G_(ctx, base); }

uint64_t Construct_TXT_83498798_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498798_G_ = int32_t(0x83498798);
	constexpr int32_t str_TXT_820BF920_B_ = int32_t(0x820BF920);
	constexpr int32_t Destroy_TXT_83498798_G__address = int32_t(0x832A3650);
	if (!UseLiftedCode(143, 0x832517C8)) { __imp__sub_832517C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832517C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498798_G_, str_TXT_820BF920_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498798_G__address);
}
PROMOTED_ENTRY(143, sub_832517C8, 0x832517C8) { ctx.r3.u64 = Construct_TXT_83498798_G_(ctx, base); }

uint64_t Construct_TXT_8349879C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349879C_G_ = int32_t(0x8349879C);
	constexpr int32_t str_TXT_820BF930_B_ = int32_t(0x820BF930);
	constexpr int32_t Destroy_TXT_8349879C_G__address = int32_t(0x832A3660);
	if (!UseLiftedCode(143, 0x83251808)) { __imp__sub_83251808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349879C_G_, str_TXT_820BF930_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349879C_G__address);
}
PROMOTED_ENTRY(143, sub_83251808, 0x83251808) { ctx.r3.u64 = Construct_TXT_8349879C_G_(ctx, base); }

uint64_t Construct_TXT_834987A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987A0_G_ = int32_t(0x834987A0);
	constexpr int32_t str_TXT_820BF94C_B_ = int32_t(0x820BF94C);
	constexpr int32_t Destroy_TXT_834987A0_G__address = int32_t(0x832A3670);
	if (!UseLiftedCode(143, 0x83251848)) { __imp__sub_83251848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A0_G_, str_TXT_820BF94C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987A0_G__address);
}
PROMOTED_ENTRY(143, sub_83251848, 0x83251848) { ctx.r3.u64 = Construct_TXT_834987A0_G_(ctx, base); }

uint64_t Construct_TXT_834987A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987A4_G_ = int32_t(0x834987A4);
	constexpr int32_t str_TXT_820BF728_B_ = int32_t(0x820BF728);
	constexpr int32_t Destroy_TXT_834987A4_G__address = int32_t(0x832A3680);
	if (!UseLiftedCode(143, 0x83251888)) { __imp__sub_83251888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A4_G_, str_TXT_820BF728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987A4_G__address);
}
PROMOTED_ENTRY(143, sub_83251888, 0x83251888) { ctx.r3.u64 = Construct_TXT_834987A4_G_(ctx, base); }

uint64_t Construct_TXT_834987A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987A8_G_ = int32_t(0x834987A8);
	constexpr int32_t str_TXT_820BF968_B_ = int32_t(0x820BF968);
	constexpr int32_t Destroy_TXT_834987A8_G__address = int32_t(0x832A3690);
	if (!UseLiftedCode(143, 0x832518C8)) { __imp__sub_832518C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832518C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987A8_G_, str_TXT_820BF968_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987A8_G__address);
}
PROMOTED_ENTRY(143, sub_832518C8, 0x832518C8) { ctx.r3.u64 = Construct_TXT_834987A8_G_(ctx, base); }

uint64_t Construct_TXT_834987AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987AC_G_ = int32_t(0x834987AC);
	constexpr int32_t str_TXT_820BF738_B_ = int32_t(0x820BF738);
	constexpr int32_t Destroy_TXT_834987AC_G__address = int32_t(0x832A36A0);
	if (!UseLiftedCode(143, 0x83251908)) { __imp__sub_83251908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987AC_G_, str_TXT_820BF738_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987AC_G__address);
}
PROMOTED_ENTRY(143, sub_83251908, 0x83251908) { ctx.r3.u64 = Construct_TXT_834987AC_G_(ctx, base); }

uint64_t Construct_TXT_834987B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987B0_G_ = int32_t(0x834987B0);
	constexpr int32_t str_TXT_820BF984_B_ = int32_t(0x820BF984);
	constexpr int32_t Destroy_TXT_834987B0_G__address = int32_t(0x832A36B0);
	if (!UseLiftedCode(143, 0x83251948)) { __imp__sub_83251948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B0_G_, str_TXT_820BF984_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987B0_G__address);
}
PROMOTED_ENTRY(143, sub_83251948, 0x83251948) { ctx.r3.u64 = Construct_TXT_834987B0_G_(ctx, base); }

uint64_t Construct_TXT_834987B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987B4_G_ = int32_t(0x834987B4);
	constexpr int32_t str_TXT_820BF9A8_B_ = int32_t(0x820BF9A8);
	constexpr int32_t Destroy_TXT_834987B4_G__address = int32_t(0x832A36C0);
	if (!UseLiftedCode(143, 0x83251988)) { __imp__sub_83251988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B4_G_, str_TXT_820BF9A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987B4_G__address);
}
PROMOTED_ENTRY(143, sub_83251988, 0x83251988) { ctx.r3.u64 = Construct_TXT_834987B4_G_(ctx, base); }

uint64_t Construct_TXT_834987B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987B8_G_ = int32_t(0x834987B8);
	constexpr int32_t str_TXT_820BF9C0_B_ = int32_t(0x820BF9C0);
	constexpr int32_t Destroy_TXT_834987B8_G__address = int32_t(0x832A36D0);
	if (!UseLiftedCode(143, 0x832519C8)) { __imp__sub_832519C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832519C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987B8_G_, str_TXT_820BF9C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987B8_G__address);
}
PROMOTED_ENTRY(143, sub_832519C8, 0x832519C8) { ctx.r3.u64 = Construct_TXT_834987B8_G_(ctx, base); }

uint64_t Construct_TXT_834987BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987BC_G_ = int32_t(0x834987BC);
	constexpr int32_t str_TXT_820BF9DC_B_ = int32_t(0x820BF9DC);
	constexpr int32_t Destroy_TXT_834987BC_G__address = int32_t(0x832A36E0);
	if (!UseLiftedCode(143, 0x83251A08)) { __imp__sub_83251A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987BC_G_, str_TXT_820BF9DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987BC_G__address);
}
PROMOTED_ENTRY(143, sub_83251A08, 0x83251A08) { ctx.r3.u64 = Construct_TXT_834987BC_G_(ctx, base); }

uint64_t Construct_TXT_834987C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987C0_G_ = int32_t(0x834987C0);
	constexpr int32_t str_TXT_820BF9FC_B_ = int32_t(0x820BF9FC);
	constexpr int32_t Destroy_TXT_834987C0_G__address = int32_t(0x832A36F0);
	if (!UseLiftedCode(143, 0x83251A48)) { __imp__sub_83251A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C0_G_, str_TXT_820BF9FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987C0_G__address);
}
PROMOTED_ENTRY(143, sub_83251A48, 0x83251A48) { ctx.r3.u64 = Construct_TXT_834987C0_G_(ctx, base); }

uint64_t Construct_TXT_834987C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987C4_G_ = int32_t(0x834987C4);
	constexpr int32_t str_TXT_820BFA14_B_ = int32_t(0x820BFA14);
	constexpr int32_t Destroy_TXT_834987C4_G__address = int32_t(0x832A3700);
	if (!UseLiftedCode(143, 0x83251A88)) { __imp__sub_83251A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251A88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C4_G_, str_TXT_820BFA14_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987C4_G__address);
}
PROMOTED_ENTRY(143, sub_83251A88, 0x83251A88) { ctx.r3.u64 = Construct_TXT_834987C4_G_(ctx, base); }

uint64_t Construct_TXT_834987C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987C8_G_ = int32_t(0x834987C8);
	constexpr int32_t str_TXT_820BFA30_B_ = int32_t(0x820BFA30);
	constexpr int32_t Destroy_TXT_834987C8_G__address = int32_t(0x832A3710);
	if (!UseLiftedCode(143, 0x83251AC8)) { __imp__sub_83251AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987C8_G_, str_TXT_820BFA30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987C8_G__address);
}
PROMOTED_ENTRY(143, sub_83251AC8, 0x83251AC8) { ctx.r3.u64 = Construct_TXT_834987C8_G_(ctx, base); }

uint64_t Construct_TXT_834987CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987CC_G_ = int32_t(0x834987CC);
	constexpr int32_t str_TXT_820BFA4C_B_ = int32_t(0x820BFA4C);
	constexpr int32_t Destroy_TXT_834987CC_G__address = int32_t(0x832A3720);
	if (!UseLiftedCode(143, 0x83251B08)) { __imp__sub_83251B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987CC_G_, str_TXT_820BFA4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987CC_G__address);
}
PROMOTED_ENTRY(143, sub_83251B08, 0x83251B08) { ctx.r3.u64 = Construct_TXT_834987CC_G_(ctx, base); }

uint64_t Construct_TXT_834987D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987D0_G_ = int32_t(0x834987D0);
	constexpr int32_t str_TXT_820BFA6C_B_ = int32_t(0x820BFA6C);
	constexpr int32_t Destroy_TXT_834987D0_G__address = int32_t(0x832A3730);
	if (!UseLiftedCode(143, 0x83251B48)) { __imp__sub_83251B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D0_G_, str_TXT_820BFA6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987D0_G__address);
}
PROMOTED_ENTRY(143, sub_83251B48, 0x83251B48) { ctx.r3.u64 = Construct_TXT_834987D0_G_(ctx, base); }

uint64_t Construct_TXT_834987D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987D4_G_ = int32_t(0x834987D4);
	constexpr int32_t str_TXT_820BFA88_B_ = int32_t(0x820BFA88);
	constexpr int32_t Destroy_TXT_834987D4_G__address = int32_t(0x832A3740);
	if (!UseLiftedCode(143, 0x83251B88)) { __imp__sub_83251B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251B88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D4_G_, str_TXT_820BFA88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987D4_G__address);
}
PROMOTED_ENTRY(143, sub_83251B88, 0x83251B88) { ctx.r3.u64 = Construct_TXT_834987D4_G_(ctx, base); }

uint64_t Construct_TXT_834987D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987D8_G_ = int32_t(0x834987D8);
	constexpr int32_t str_TXT_820BFAA0_B_ = int32_t(0x820BFAA0);
	constexpr int32_t Destroy_TXT_834987D8_G__address = int32_t(0x832A3750);
	if (!UseLiftedCode(143, 0x83251BC8)) { __imp__sub_83251BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251BC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987D8_G_, str_TXT_820BFAA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987D8_G__address);
}
PROMOTED_ENTRY(143, sub_83251BC8, 0x83251BC8) { ctx.r3.u64 = Construct_TXT_834987D8_G_(ctx, base); }

uint64_t Construct_TXT_834987DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987DC_G_ = int32_t(0x834987DC);
	constexpr int32_t str_TXT_820BFAB8_B_ = int32_t(0x820BFAB8);
	constexpr int32_t Destroy_TXT_834987DC_G__address = int32_t(0x832A3760);
	if (!UseLiftedCode(143, 0x83251C08)) { __imp__sub_83251C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987DC_G_, str_TXT_820BFAB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987DC_G__address);
}
PROMOTED_ENTRY(143, sub_83251C08, 0x83251C08) { ctx.r3.u64 = Construct_TXT_834987DC_G_(ctx, base); }

uint64_t Construct_TXT_834987E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987E0_G_ = int32_t(0x834987E0);
	constexpr int32_t str_TXT_820BFAD0_B_ = int32_t(0x820BFAD0);
	constexpr int32_t Destroy_TXT_834987E0_G__address = int32_t(0x832A3770);
	if (!UseLiftedCode(143, 0x83251C48)) { __imp__sub_83251C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E0_G_, str_TXT_820BFAD0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987E0_G__address);
}
PROMOTED_ENTRY(143, sub_83251C48, 0x83251C48) { ctx.r3.u64 = Construct_TXT_834987E0_G_(ctx, base); }

uint64_t Construct_TXT_834987E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987E4_G_ = int32_t(0x834987E4);
	constexpr int32_t str_TXT_820BF728_B_ = int32_t(0x820BF728);
	constexpr int32_t Destroy_TXT_834987E4_G__address = int32_t(0x832A3780);
	if (!UseLiftedCode(143, 0x83251C88)) { __imp__sub_83251C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251C88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E4_G_, str_TXT_820BF728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987E4_G__address);
}
PROMOTED_ENTRY(143, sub_83251C88, 0x83251C88) { ctx.r3.u64 = Construct_TXT_834987E4_G_(ctx, base); }

uint64_t Construct_TXT_834987E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987E8_G_ = int32_t(0x834987E8);
	constexpr int32_t str_TXT_820BF738_B_ = int32_t(0x820BF738);
	constexpr int32_t Destroy_TXT_834987E8_G__address = int32_t(0x832A3790);
	if (!UseLiftedCode(143, 0x83251CC8)) { __imp__sub_83251CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987E8_G_, str_TXT_820BF738_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987E8_G__address);
}
PROMOTED_ENTRY(143, sub_83251CC8, 0x83251CC8) { ctx.r3.u64 = Construct_TXT_834987E8_G_(ctx, base); }

uint64_t Construct_TXT_834987EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987EC_G_ = int32_t(0x834987EC);
	constexpr int32_t str_TXT_820BFAF4_B_ = int32_t(0x820BFAF4);
	constexpr int32_t Destroy_TXT_834987EC_G__address = int32_t(0x832A37A0);
	if (!UseLiftedCode(143, 0x83251D08)) { __imp__sub_83251D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987EC_G_, str_TXT_820BFAF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987EC_G__address);
}
PROMOTED_ENTRY(143, sub_83251D08, 0x83251D08) { ctx.r3.u64 = Construct_TXT_834987EC_G_(ctx, base); }

uint64_t Construct_TXT_834987F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987F0_G_ = int32_t(0x834987F0);
	constexpr int32_t str_TXT_820BFB14_B_ = int32_t(0x820BFB14);
	constexpr int32_t Destroy_TXT_834987F0_G__address = int32_t(0x832A37B0);
	if (!UseLiftedCode(143, 0x83251D48)) { __imp__sub_83251D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F0_G_, str_TXT_820BFB14_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987F0_G__address);
}
PROMOTED_ENTRY(143, sub_83251D48, 0x83251D48) { ctx.r3.u64 = Construct_TXT_834987F0_G_(ctx, base); }

uint64_t Construct_TXT_834987F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987F4_G_ = int32_t(0x834987F4);
	constexpr int32_t str_TXT_820BFB34_B_ = int32_t(0x820BFB34);
	constexpr int32_t Destroy_TXT_834987F4_G__address = int32_t(0x832A37C0);
	if (!UseLiftedCode(143, 0x83251D88)) { __imp__sub_83251D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F4_G_, str_TXT_820BFB34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987F4_G__address);
}
PROMOTED_ENTRY(143, sub_83251D88, 0x83251D88) { ctx.r3.u64 = Construct_TXT_834987F4_G_(ctx, base); }

uint64_t Construct_TXT_834987F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987F8_G_ = int32_t(0x834987F8);
	constexpr int32_t str_TXT_820BFB50_B_ = int32_t(0x820BFB50);
	constexpr int32_t Destroy_TXT_834987F8_G__address = int32_t(0x832A37D0);
	if (!UseLiftedCode(143, 0x83251DC8)) { __imp__sub_83251DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987F8_G_, str_TXT_820BFB50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987F8_G__address);
}
PROMOTED_ENTRY(143, sub_83251DC8, 0x83251DC8) { ctx.r3.u64 = Construct_TXT_834987F8_G_(ctx, base); }

uint64_t Construct_TXT_834987FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834987FC_G_ = int32_t(0x834987FC);
	constexpr int32_t str_TXT_820BFB6C_B_ = int32_t(0x820BFB6C);
	constexpr int32_t Destroy_TXT_834987FC_G__address = int32_t(0x832A37E0);
	if (!UseLiftedCode(143, 0x83251E08)) { __imp__sub_83251E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834987FC_G_, str_TXT_820BFB6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834987FC_G__address);
}
PROMOTED_ENTRY(143, sub_83251E08, 0x83251E08) { ctx.r3.u64 = Construct_TXT_834987FC_G_(ctx, base); }

uint64_t Construct_TXT_83498800_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498800_G_ = int32_t(0x83498800);
	constexpr int32_t str_TXT_820BFB8C_B_ = int32_t(0x820BFB8C);
	constexpr int32_t Destroy_TXT_83498800_G__address = int32_t(0x832A37F0);
	if (!UseLiftedCode(143, 0x83251E48)) { __imp__sub_83251E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498800_G_, str_TXT_820BFB8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498800_G__address);
}
PROMOTED_ENTRY(143, sub_83251E48, 0x83251E48) { ctx.r3.u64 = Construct_TXT_83498800_G_(ctx, base); }

uint64_t Construct_TXT_83498804_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498804_G_ = int32_t(0x83498804);
	constexpr int32_t str_TXT_820BFBA0_B_ = int32_t(0x820BFBA0);
	constexpr int32_t Destroy_TXT_83498804_G__address = int32_t(0x832A3800);
	if (!UseLiftedCode(143, 0x83251E88)) { __imp__sub_83251E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498804_G_, str_TXT_820BFBA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498804_G__address);
}
PROMOTED_ENTRY(143, sub_83251E88, 0x83251E88) { ctx.r3.u64 = Construct_TXT_83498804_G_(ctx, base); }

uint64_t Construct_TXT_83498808_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498808_G_ = int32_t(0x83498808);
	constexpr int32_t str_TXT_820BFBB4_B_ = int32_t(0x820BFBB4);
	constexpr int32_t Destroy_TXT_83498808_G__address = int32_t(0x832A3810);
	if (!UseLiftedCode(143, 0x83251EC8)) { __imp__sub_83251EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498808_G_, str_TXT_820BFBB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498808_G__address);
}
PROMOTED_ENTRY(143, sub_83251EC8, 0x83251EC8) { ctx.r3.u64 = Construct_TXT_83498808_G_(ctx, base); }

uint64_t Construct_TXT_8349880C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349880C_G_ = int32_t(0x8349880C);
	constexpr int32_t str_TXT_820BFBD4_B_ = int32_t(0x820BFBD4);
	constexpr int32_t Destroy_TXT_8349880C_G__address = int32_t(0x832A3820);
	if (!UseLiftedCode(143, 0x83251F08)) { __imp__sub_83251F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349880C_G_, str_TXT_820BFBD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349880C_G__address);
}
PROMOTED_ENTRY(143, sub_83251F08, 0x83251F08) { ctx.r3.u64 = Construct_TXT_8349880C_G_(ctx, base); }

uint64_t Construct_TXT_83498810_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498810_G_ = int32_t(0x83498810);
	constexpr int32_t str_TXT_820BFBEC_B_ = int32_t(0x820BFBEC);
	constexpr int32_t Destroy_TXT_83498810_G__address = int32_t(0x832A3830);
	if (!UseLiftedCode(143, 0x83251F48)) { __imp__sub_83251F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498810_G_, str_TXT_820BFBEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498810_G__address);
}
PROMOTED_ENTRY(143, sub_83251F48, 0x83251F48) { ctx.r3.u64 = Construct_TXT_83498810_G_(ctx, base); }

uint64_t Construct_TXT_83498814_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498814_G_ = int32_t(0x83498814);
	constexpr int32_t str_TXT_820BFC04_B_ = int32_t(0x820BFC04);
	constexpr int32_t Destroy_TXT_83498814_G__address = int32_t(0x832A3840);
	if (!UseLiftedCode(143, 0x83251F88)) { __imp__sub_83251F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498814_G_, str_TXT_820BFC04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498814_G__address);
}
PROMOTED_ENTRY(143, sub_83251F88, 0x83251F88) { ctx.r3.u64 = Construct_TXT_83498814_G_(ctx, base); }

uint64_t Construct_TXT_83498818_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498818_G_ = int32_t(0x83498818);
	constexpr int32_t str_TXT_820BFC20_B_ = int32_t(0x820BFC20);
	constexpr int32_t Destroy_TXT_83498818_G__address = int32_t(0x832A3850);
	if (!UseLiftedCode(143, 0x83251FC8)) { __imp__sub_83251FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83251FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498818_G_, str_TXT_820BFC20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498818_G__address);
}
PROMOTED_ENTRY(143, sub_83251FC8, 0x83251FC8) { ctx.r3.u64 = Construct_TXT_83498818_G_(ctx, base); }

uint64_t Construct_TXT_8349881C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349881C_G_ = int32_t(0x8349881C);
	constexpr int32_t str_TXT_820BFC40_B_ = int32_t(0x820BFC40);
	constexpr int32_t Destroy_TXT_8349881C_G__address = int32_t(0x832A3860);
	if (!UseLiftedCode(143, 0x83252008)) { __imp__sub_83252008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349881C_G_, str_TXT_820BFC40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349881C_G__address);
}
PROMOTED_ENTRY(143, sub_83252008, 0x83252008) { ctx.r3.u64 = Construct_TXT_8349881C_G_(ctx, base); }

uint64_t Construct_TXT_83498820_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498820_G_ = int32_t(0x83498820);
	constexpr int32_t str_TXT_820BFC60_B_ = int32_t(0x820BFC60);
	constexpr int32_t Destroy_TXT_83498820_G__address = int32_t(0x832A3870);
	if (!UseLiftedCode(143, 0x83252048)) { __imp__sub_83252048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498820_G_, str_TXT_820BFC60_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498820_G__address);
}
PROMOTED_ENTRY(143, sub_83252048, 0x83252048) { ctx.r3.u64 = Construct_TXT_83498820_G_(ctx, base); }

uint64_t Construct_TXT_83498824_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498824_G_ = int32_t(0x83498824);
	constexpr int32_t str_TXT_820BFC7C_B_ = int32_t(0x820BFC7C);
	constexpr int32_t Destroy_TXT_83498824_G__address = int32_t(0x832A3880);
	if (!UseLiftedCode(143, 0x83252088)) { __imp__sub_83252088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498824_G_, str_TXT_820BFC7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498824_G__address);
}
PROMOTED_ENTRY(143, sub_83252088, 0x83252088) { ctx.r3.u64 = Construct_TXT_83498824_G_(ctx, base); }

uint64_t Construct_TXT_83498828_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498828_G_ = int32_t(0x83498828);
	constexpr int32_t str_TXT_820BFC94_B_ = int32_t(0x820BFC94);
	constexpr int32_t Destroy_TXT_83498828_G__address = int32_t(0x832A3890);
	if (!UseLiftedCode(143, 0x832520C8)) { __imp__sub_832520C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832520C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498828_G_, str_TXT_820BFC94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498828_G__address);
}
PROMOTED_ENTRY(143, sub_832520C8, 0x832520C8) { ctx.r3.u64 = Construct_TXT_83498828_G_(ctx, base); }

uint64_t Construct_TXT_8349882C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349882C_G_ = int32_t(0x8349882C);
	constexpr int32_t str_TXT_820BFCA4_B_ = int32_t(0x820BFCA4);
	constexpr int32_t Destroy_TXT_8349882C_G__address = int32_t(0x832A38A0);
	if (!UseLiftedCode(143, 0x83252108)) { __imp__sub_83252108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349882C_G_, str_TXT_820BFCA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349882C_G__address);
}
PROMOTED_ENTRY(143, sub_83252108, 0x83252108) { ctx.r3.u64 = Construct_TXT_8349882C_G_(ctx, base); }

uint64_t Construct_TXT_83498830_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498830_G_ = int32_t(0x83498830);
	constexpr int32_t str_TXT_820BFCC4_B_ = int32_t(0x820BFCC4);
	constexpr int32_t Destroy_TXT_83498830_G__address = int32_t(0x832A38B0);
	if (!UseLiftedCode(143, 0x83252148)) { __imp__sub_83252148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498830_G_, str_TXT_820BFCC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498830_G__address);
}
PROMOTED_ENTRY(143, sub_83252148, 0x83252148) { ctx.r3.u64 = Construct_TXT_83498830_G_(ctx, base); }

uint64_t Construct_TXT_83498834_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498834_G_ = int32_t(0x83498834);
	constexpr int32_t str_TXT_820BFCE0_B_ = int32_t(0x820BFCE0);
	constexpr int32_t Destroy_TXT_83498834_G__address = int32_t(0x832A38C0);
	if (!UseLiftedCode(143, 0x83252188)) { __imp__sub_83252188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498834_G_, str_TXT_820BFCE0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498834_G__address);
}
PROMOTED_ENTRY(143, sub_83252188, 0x83252188) { ctx.r3.u64 = Construct_TXT_83498834_G_(ctx, base); }

uint64_t Construct_TXT_83498838_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498838_G_ = int32_t(0x83498838);
	constexpr int32_t str_TXT_820BF894_B_ = int32_t(0x820BF894);
	constexpr int32_t Destroy_TXT_83498838_G__address = int32_t(0x832A38D0);
	if (!UseLiftedCode(143, 0x832521C8)) { __imp__sub_832521C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832521C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498838_G_, str_TXT_820BF894_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498838_G__address);
}
PROMOTED_ENTRY(143, sub_832521C8, 0x832521C8) { ctx.r3.u64 = Construct_TXT_83498838_G_(ctx, base); }

uint64_t Construct_TXT_8349883C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349883C_G_ = int32_t(0x8349883C);
	constexpr int32_t str_TXT_820BF8AC_B_ = int32_t(0x820BF8AC);
	constexpr int32_t Destroy_TXT_8349883C_G__address = int32_t(0x832A38E0);
	if (!UseLiftedCode(143, 0x83252208)) { __imp__sub_83252208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349883C_G_, str_TXT_820BF8AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349883C_G__address);
}
PROMOTED_ENTRY(143, sub_83252208, 0x83252208) { ctx.r3.u64 = Construct_TXT_8349883C_G_(ctx, base); }

uint64_t Construct_TXT_83498840_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498840_G_ = int32_t(0x83498840);
	constexpr int32_t str_TXT_820BF894_B_ = int32_t(0x820BF894);
	constexpr int32_t Destroy_TXT_83498840_G__address = int32_t(0x832A38F0);
	if (!UseLiftedCode(143, 0x83252248)) { __imp__sub_83252248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498840_G_, str_TXT_820BF894_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498840_G__address);
}
PROMOTED_ENTRY(143, sub_83252248, 0x83252248) { ctx.r3.u64 = Construct_TXT_83498840_G_(ctx, base); }

uint64_t Construct_TXT_83498844_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498844_G_ = int32_t(0x83498844);
	constexpr int32_t str_TXT_820BF8AC_B_ = int32_t(0x820BF8AC);
	constexpr int32_t Destroy_TXT_83498844_G__address = int32_t(0x832A3900);
	if (!UseLiftedCode(143, 0x83252288)) { __imp__sub_83252288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498844_G_, str_TXT_820BF8AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498844_G__address);
}
PROMOTED_ENTRY(143, sub_83252288, 0x83252288) { ctx.r3.u64 = Construct_TXT_83498844_G_(ctx, base); }

uint64_t Construct_TXT_83498848_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498848_G_ = int32_t(0x83498848);
	constexpr int32_t str_TXT_820BF728_B_ = int32_t(0x820BF728);
	constexpr int32_t Destroy_TXT_83498848_G__address = int32_t(0x832A3910);
	if (!UseLiftedCode(143, 0x832522C8)) { __imp__sub_832522C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832522C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498848_G_, str_TXT_820BF728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498848_G__address);
}
PROMOTED_ENTRY(143, sub_832522C8, 0x832522C8) { ctx.r3.u64 = Construct_TXT_83498848_G_(ctx, base); }

uint64_t Construct_TXT_8349884C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349884C_G_ = int32_t(0x8349884C);
	constexpr int32_t str_TXT_820BF738_B_ = int32_t(0x820BF738);
	constexpr int32_t Destroy_TXT_8349884C_G__address = int32_t(0x832A3920);
	if (!UseLiftedCode(143, 0x83252308)) { __imp__sub_83252308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349884C_G_, str_TXT_820BF738_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349884C_G__address);
}
PROMOTED_ENTRY(143, sub_83252308, 0x83252308) { ctx.r3.u64 = Construct_TXT_8349884C_G_(ctx, base); }

uint64_t Construct_TXT_83498850_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498850_G_ = int32_t(0x83498850);
	constexpr int32_t str_TXT_820BFCFC_B_ = int32_t(0x820BFCFC);
	constexpr int32_t Destroy_TXT_83498850_G__address = int32_t(0x832A3930);
	if (!UseLiftedCode(143, 0x83252348)) { __imp__sub_83252348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498850_G_, str_TXT_820BFCFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498850_G__address);
}
PROMOTED_ENTRY(143, sub_83252348, 0x83252348) { ctx.r3.u64 = Construct_TXT_83498850_G_(ctx, base); }

uint64_t Construct_TXT_83498854_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498854_G_ = int32_t(0x83498854);
	constexpr int32_t str_TXT_820BFCFC_B_ = int32_t(0x820BFCFC);
	constexpr int32_t Destroy_TXT_83498854_G__address = int32_t(0x832A3940);
	if (!UseLiftedCode(143, 0x83252388)) { __imp__sub_83252388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498854_G_, str_TXT_820BFCFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498854_G__address);
}
PROMOTED_ENTRY(143, sub_83252388, 0x83252388) { ctx.r3.u64 = Construct_TXT_83498854_G_(ctx, base); }

uint64_t Construct_TXT_83498858_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498858_G_ = int32_t(0x83498858);
	constexpr int32_t str_TXT_820BFD0C_B_ = int32_t(0x820BFD0C);
	constexpr int32_t Destroy_TXT_83498858_G__address = int32_t(0x832A3950);
	if (!UseLiftedCode(143, 0x832523C8)) { __imp__sub_832523C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832523C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498858_G_, str_TXT_820BFD0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498858_G__address);
}
PROMOTED_ENTRY(143, sub_832523C8, 0x832523C8) { ctx.r3.u64 = Construct_TXT_83498858_G_(ctx, base); }

uint64_t Construct_TXT_8349885C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349885C_G_ = int32_t(0x8349885C);
	constexpr int32_t str_TXT_820BFD20_B_ = int32_t(0x820BFD20);
	constexpr int32_t Destroy_TXT_8349885C_G__address = int32_t(0x832A3960);
	if (!UseLiftedCode(143, 0x83252408)) { __imp__sub_83252408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349885C_G_, str_TXT_820BFD20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349885C_G__address);
}
PROMOTED_ENTRY(143, sub_83252408, 0x83252408) { ctx.r3.u64 = Construct_TXT_8349885C_G_(ctx, base); }

uint64_t Construct_TXT_83498860_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498860_G_ = int32_t(0x83498860);
	constexpr int32_t str_TXT_820BFD30_B_ = int32_t(0x820BFD30);
	constexpr int32_t Destroy_TXT_83498860_G__address = int32_t(0x832A3970);
	if (!UseLiftedCode(143, 0x83252448)) { __imp__sub_83252448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498860_G_, str_TXT_820BFD30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498860_G__address);
}
PROMOTED_ENTRY(143, sub_83252448, 0x83252448) { ctx.r3.u64 = Construct_TXT_83498860_G_(ctx, base); }

uint64_t Construct_TXT_83498864_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498864_G_ = int32_t(0x83498864);
	constexpr int32_t str_TXT_820BFD44_B_ = int32_t(0x820BFD44);
	constexpr int32_t Destroy_TXT_83498864_G__address = int32_t(0x832A3980);
	if (!UseLiftedCode(143, 0x83252488)) { __imp__sub_83252488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498864_G_, str_TXT_820BFD44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498864_G__address);
}
PROMOTED_ENTRY(143, sub_83252488, 0x83252488) { ctx.r3.u64 = Construct_TXT_83498864_G_(ctx, base); }

uint64_t Construct_TXT_83498868_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498868_G_ = int32_t(0x83498868);
	constexpr int32_t str_TXT_820BFD58_B_ = int32_t(0x820BFD58);
	constexpr int32_t Destroy_TXT_83498868_G__address = int32_t(0x832A3990);
	if (!UseLiftedCode(143, 0x832524C8)) { __imp__sub_832524C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832524C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498868_G_, str_TXT_820BFD58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498868_G__address);
}
PROMOTED_ENTRY(143, sub_832524C8, 0x832524C8) { ctx.r3.u64 = Construct_TXT_83498868_G_(ctx, base); }

uint64_t Construct_TXT_8349886C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349886C_G_ = int32_t(0x8349886C);
	constexpr int32_t str_TXT_820BFD6C_B_ = int32_t(0x820BFD6C);
	constexpr int32_t Destroy_TXT_8349886C_G__address = int32_t(0x832A39A0);
	if (!UseLiftedCode(143, 0x83252508)) { __imp__sub_83252508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349886C_G_, str_TXT_820BFD6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349886C_G__address);
}
PROMOTED_ENTRY(143, sub_83252508, 0x83252508) { ctx.r3.u64 = Construct_TXT_8349886C_G_(ctx, base); }

uint64_t Construct_TXT_83498870_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498870_G_ = int32_t(0x83498870);
	constexpr int32_t str_TXT_820BFD84_B_ = int32_t(0x820BFD84);
	constexpr int32_t Destroy_TXT_83498870_G__address = int32_t(0x832A39B0);
	if (!UseLiftedCode(143, 0x83252548)) { __imp__sub_83252548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498870_G_, str_TXT_820BFD84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498870_G__address);
}
PROMOTED_ENTRY(143, sub_83252548, 0x83252548) { ctx.r3.u64 = Construct_TXT_83498870_G_(ctx, base); }

uint64_t Construct_TXT_83498874_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498874_G_ = int32_t(0x83498874);
	constexpr int32_t str_TXT_820BFDA0_B_ = int32_t(0x820BFDA0);
	constexpr int32_t Destroy_TXT_83498874_G__address = int32_t(0x832A39C0);
	if (!UseLiftedCode(143, 0x83252588)) { __imp__sub_83252588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498874_G_, str_TXT_820BFDA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498874_G__address);
}
PROMOTED_ENTRY(143, sub_83252588, 0x83252588) { ctx.r3.u64 = Construct_TXT_83498874_G_(ctx, base); }

uint64_t Construct_TXT_83498878_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498878_G_ = int32_t(0x83498878);
	constexpr int32_t str_TXT_820BFDBC_B_ = int32_t(0x820BFDBC);
	constexpr int32_t Destroy_TXT_83498878_G__address = int32_t(0x832A39D0);
	if (!UseLiftedCode(143, 0x832525C8)) { __imp__sub_832525C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832525C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498878_G_, str_TXT_820BFDBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498878_G__address);
}
PROMOTED_ENTRY(143, sub_832525C8, 0x832525C8) { ctx.r3.u64 = Construct_TXT_83498878_G_(ctx, base); }

uint64_t Construct_TXT_8349887C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349887C_G_ = int32_t(0x8349887C);
	constexpr int32_t str_TXT_820BFDD8_B_ = int32_t(0x820BFDD8);
	constexpr int32_t Destroy_TXT_8349887C_G__address = int32_t(0x832A39E0);
	if (!UseLiftedCode(143, 0x83252608)) { __imp__sub_83252608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349887C_G_, str_TXT_820BFDD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349887C_G__address);
}
PROMOTED_ENTRY(143, sub_83252608, 0x83252608) { ctx.r3.u64 = Construct_TXT_8349887C_G_(ctx, base); }

uint64_t Construct_TXT_83498880_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498880_G_ = int32_t(0x83498880);
	constexpr int32_t str_TXT_820AE844_B_ = int32_t(0x820AE844);
	constexpr int32_t Destroy_TXT_83498880_G__address = int32_t(0x832A39F0);
	if (!UseLiftedCode(143, 0x83252648)) { __imp__sub_83252648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498880_G_, str_TXT_820AE844_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498880_G__address);
}
PROMOTED_ENTRY(143, sub_83252648, 0x83252648) { ctx.r3.u64 = Construct_TXT_83498880_G_(ctx, base); }

uint64_t Construct_TXT_83498884_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498884_G_ = int32_t(0x83498884);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498884_G__address = int32_t(0x832A3A00);
	if (!UseLiftedCode(143, 0x83252688)) { __imp__sub_83252688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252688);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498884_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498884_G__address);
}
PROMOTED_ENTRY(143, sub_83252688, 0x83252688) { ctx.r3.u64 = Construct_TXT_83498884_G_(ctx, base); }

uint64_t Construct_TXT_83498888_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498888_G_ = int32_t(0x83498888);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498888_G__address = int32_t(0x832A3A10);
	if (!UseLiftedCode(143, 0x832526C8)) { __imp__sub_832526C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832526C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498888_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498888_G__address);
}
PROMOTED_ENTRY(143, sub_832526C8, 0x832526C8) { ctx.r3.u64 = Construct_TXT_83498888_G_(ctx, base); }

uint64_t Construct_TXT_8349888C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349888C_G_ = int32_t(0x8349888C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349888C_G__address = int32_t(0x832A3A20);
	if (!UseLiftedCode(143, 0x83252708)) { __imp__sub_83252708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349888C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349888C_G__address);
}
PROMOTED_ENTRY(143, sub_83252708, 0x83252708) { ctx.r3.u64 = Construct_TXT_8349888C_G_(ctx, base); }

uint64_t Construct_TXT_834988E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988E4_G_ = int32_t(0x834988E4);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834988E4_G__address = int32_t(0x832A3A30);
	if (!UseLiftedCode(143, 0x83252BE0)) { __imp__sub_83252BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252BE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988E4_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988E4_G__address);
}
PROMOTED_ENTRY(143, sub_83252BE0, 0x83252BE0) { ctx.r3.u64 = Construct_TXT_834988E4_G_(ctx, base); }

uint64_t Construct_TXT_834988E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988E8_G_ = int32_t(0x834988E8);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_834988E8_G__address = int32_t(0x832A3A40);
	if (!UseLiftedCode(143, 0x83252C20)) { __imp__sub_83252C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252C20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988E8_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988E8_G__address);
}
PROMOTED_ENTRY(143, sub_83252C20, 0x83252C20) { ctx.r3.u64 = Construct_TXT_834988E8_G_(ctx, base); }

uint64_t Construct_TXT_834988EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988EC_G_ = int32_t(0x834988EC);
	constexpr int32_t str_TXT_820BFE58_B_ = int32_t(0x820BFE58);
	constexpr int32_t Destroy_TXT_834988EC_G__address = int32_t(0x832A3A50);
	if (!UseLiftedCode(143, 0x83252C60)) { __imp__sub_83252C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252C60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988EC_G_, str_TXT_820BFE58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988EC_G__address);
}
PROMOTED_ENTRY(143, sub_83252C60, 0x83252C60) { ctx.r3.u64 = Construct_TXT_834988EC_G_(ctx, base); }

uint64_t Construct_TXT_834988F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988F0_G_ = int32_t(0x834988F0);
	constexpr int32_t str_TXT_820BFE9C_B_ = int32_t(0x820BFE9C);
	constexpr int32_t Destroy_TXT_834988F0_G__address = int32_t(0x832A3A60);
	if (!UseLiftedCode(143, 0x83252CA0)) { __imp__sub_83252CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F0_G_, str_TXT_820BFE9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988F0_G__address);
}
PROMOTED_ENTRY(143, sub_83252CA0, 0x83252CA0) { ctx.r3.u64 = Construct_TXT_834988F0_G_(ctx, base); }

uint64_t Construct_TXT_834988F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988F4_G_ = int32_t(0x834988F4);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_834988F4_G__address = int32_t(0x832A3A70);
	if (!UseLiftedCode(143, 0x83252CE0)) { __imp__sub_83252CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252CE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F4_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988F4_G__address);
}
PROMOTED_ENTRY(143, sub_83252CE0, 0x83252CE0) { ctx.r3.u64 = Construct_TXT_834988F4_G_(ctx, base); }

uint64_t Construct_TXT_834988F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988F8_G_ = int32_t(0x834988F8);
	constexpr int32_t str_TXT_820BFEDC_B_ = int32_t(0x820BFEDC);
	constexpr int32_t Destroy_TXT_834988F8_G__address = int32_t(0x832A3A80);
	if (!UseLiftedCode(143, 0x83252D20)) { __imp__sub_83252D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252D20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988F8_G_, str_TXT_820BFEDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988F8_G__address);
}
PROMOTED_ENTRY(143, sub_83252D20, 0x83252D20) { ctx.r3.u64 = Construct_TXT_834988F8_G_(ctx, base); }

uint64_t Construct_TXT_834988FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834988FC_G_ = int32_t(0x834988FC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834988FC_G__address = int32_t(0x832A3A90);
	if (!UseLiftedCode(143, 0x83252D60)) { __imp__sub_83252D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252D60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834988FC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834988FC_G__address);
}
PROMOTED_ENTRY(143, sub_83252D60, 0x83252D60) { ctx.r3.u64 = Construct_TXT_834988FC_G_(ctx, base); }

uint64_t Construct_TXT_83498900_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498900_G_ = int32_t(0x83498900);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498900_G__address = int32_t(0x832A3AA0);
	if (!UseLiftedCode(143, 0x83252DA0)) { __imp__sub_83252DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252DA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498900_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498900_G__address);
}
PROMOTED_ENTRY(143, sub_83252DA0, 0x83252DA0) { ctx.r3.u64 = Construct_TXT_83498900_G_(ctx, base); }

uint64_t Construct_TXT_83498904_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498904_G_ = int32_t(0x83498904);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498904_G__address = int32_t(0x832A3AB0);
	if (!UseLiftedCode(143, 0x83252DE0)) { __imp__sub_83252DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252DE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498904_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498904_G__address);
}
PROMOTED_ENTRY(143, sub_83252DE0, 0x83252DE0) { ctx.r3.u64 = Construct_TXT_83498904_G_(ctx, base); }

uint64_t Construct_TXT_8349895C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349895C_G_ = int32_t(0x8349895C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349895C_G__address = int32_t(0x832A3AC0);
	if (!UseLiftedCode(143, 0x832532B8)) { __imp__sub_832532B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832532B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349895C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349895C_G__address);
}
PROMOTED_ENTRY(143, sub_832532B8, 0x832532B8) { ctx.r3.u64 = Construct_TXT_8349895C_G_(ctx, base); }

// sub_832532F8  [64 bytes]
uint64_t n_sub_832532F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498960_G_ = int32_t(0x83498960);
	constexpr int32_t str_TXT_820C02A8_B_ = int32_t(0x820C02A8);
	constexpr int32_t Destroy_TXT_83498960_G__address = int32_t(0x832A3AD0);
	if (!UseLiftedCode(143, 0x832532F8)) { __imp__sub_832532F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832532F8);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498960_G_, str_TXT_820C02A8_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83498960_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832532F8, 0x832532F8) { ctx.r3.u64 = n_sub_832532F8(ctx, base); }

uint64_t Construct_TXT_83498964_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498964_G_ = int32_t(0x83498964);
	constexpr int32_t str_TXT_820C02D4_B_ = int32_t(0x820C02D4);
	constexpr int32_t Destroy_TXT_83498964_G__address = int32_t(0x832A3AE0);
	if (!UseLiftedCode(143, 0x83253338)) { __imp__sub_83253338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253338);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498964_G_, str_TXT_820C02D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498964_G__address);
}
PROMOTED_ENTRY(143, sub_83253338, 0x83253338) { ctx.r3.u64 = Construct_TXT_83498964_G_(ctx, base); }

uint64_t Construct_TXT_83498A3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A3C_G_ = int32_t(0x83498A3C);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_83498A3C_G__address = int32_t(0x832A3BC0);
	if (!UseLiftedCode(143, 0x83253B00)) { __imp__sub_83253B00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A3C_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A3C_G__address);
}
PROMOTED_ENTRY(143, sub_83253B00, 0x83253B00) { ctx.r3.u64 = Construct_TXT_83498A3C_G_(ctx, base); }

uint64_t Construct_TXT_83498A40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A40_G_ = int32_t(0x83498A40);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498A40_G__address = int32_t(0x832A3BD0);
	if (!UseLiftedCode(143, 0x83253B40)) { __imp__sub_83253B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A40_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A40_G__address);
}
PROMOTED_ENTRY(143, sub_83253B40, 0x83253B40) { ctx.r3.u64 = Construct_TXT_83498A40_G_(ctx, base); }

uint64_t Construct_TXT_83498A44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A44_G_ = int32_t(0x83498A44);
	constexpr int32_t str_TXT_820C0334_B_ = int32_t(0x820C0334);
	constexpr int32_t Destroy_TXT_83498A44_G__address = int32_t(0x832A3BE0);
	if (!UseLiftedCode(143, 0x83253B80)) { __imp__sub_83253B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253B80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A44_G_, str_TXT_820C0334_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A44_G__address);
}
PROMOTED_ENTRY(143, sub_83253B80, 0x83253B80) { ctx.r3.u64 = Construct_TXT_83498A44_G_(ctx, base); }

uint64_t Construct_TXT_83498A48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A48_G_ = int32_t(0x83498A48);
	constexpr int32_t str_TXT_820C0358_B_ = int32_t(0x820C0358);
	constexpr int32_t Destroy_TXT_83498A48_G__address = int32_t(0x832A3BF0);
	if (!UseLiftedCode(143, 0x83253BC0)) { __imp__sub_83253BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253BC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A48_G_, str_TXT_820C0358_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A48_G__address);
}
PROMOTED_ENTRY(143, sub_83253BC0, 0x83253BC0) { ctx.r3.u64 = Construct_TXT_83498A48_G_(ctx, base); }

uint64_t Construct_TXT_83498A4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A4C_G_ = int32_t(0x83498A4C);
	constexpr int32_t str_TXT_820C037C_B_ = int32_t(0x820C037C);
	constexpr int32_t Destroy_TXT_83498A4C_G__address = int32_t(0x832A3C00);
	if (!UseLiftedCode(143, 0x83253C00)) { __imp__sub_83253C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A4C_G_, str_TXT_820C037C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A4C_G__address);
}
PROMOTED_ENTRY(143, sub_83253C00, 0x83253C00) { ctx.r3.u64 = Construct_TXT_83498A4C_G_(ctx, base); }

uint64_t Construct_TXT_83498A50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A50_G_ = int32_t(0x83498A50);
	constexpr int32_t str_TXT_820C03A8_B_ = int32_t(0x820C03A8);
	constexpr int32_t Destroy_TXT_83498A50_G__address = int32_t(0x832A3C10);
	if (!UseLiftedCode(143, 0x83253C40)) { __imp__sub_83253C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A50_G_, str_TXT_820C03A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A50_G__address);
}
PROMOTED_ENTRY(143, sub_83253C40, 0x83253C40) { ctx.r3.u64 = Construct_TXT_83498A50_G_(ctx, base); }

uint64_t Construct_TXT_83498A54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A54_G_ = int32_t(0x83498A54);
	constexpr int32_t str_TXT_820C03C8_B_ = int32_t(0x820C03C8);
	constexpr int32_t Destroy_TXT_83498A54_G__address = int32_t(0x832A3C20);
	if (!UseLiftedCode(143, 0x83253C80)) { __imp__sub_83253C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253C80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A54_G_, str_TXT_820C03C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A54_G__address);
}
PROMOTED_ENTRY(143, sub_83253C80, 0x83253C80) { ctx.r3.u64 = Construct_TXT_83498A54_G_(ctx, base); }

uint64_t Construct_TXT_83498A58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A58_G_ = int32_t(0x83498A58);
	constexpr int32_t str_TXT_820C03E8_B_ = int32_t(0x820C03E8);
	constexpr int32_t Destroy_TXT_83498A58_G__address = int32_t(0x832A3C30);
	if (!UseLiftedCode(143, 0x83253CC0)) { __imp__sub_83253CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253CC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A58_G_, str_TXT_820C03E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A58_G__address);
}
PROMOTED_ENTRY(143, sub_83253CC0, 0x83253CC0) { ctx.r3.u64 = Construct_TXT_83498A58_G_(ctx, base); }

uint64_t Construct_TXT_83498A5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A5C_G_ = int32_t(0x83498A5C);
	constexpr int32_t str_TXT_820C0410_B_ = int32_t(0x820C0410);
	constexpr int32_t Destroy_TXT_83498A5C_G__address = int32_t(0x832A3C40);
	if (!UseLiftedCode(143, 0x83253D00)) { __imp__sub_83253D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A5C_G_, str_TXT_820C0410_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A5C_G__address);
}
PROMOTED_ENTRY(143, sub_83253D00, 0x83253D00) { ctx.r3.u64 = Construct_TXT_83498A5C_G_(ctx, base); }

uint64_t Construct_TXT_83498A60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A60_G_ = int32_t(0x83498A60);
	constexpr int32_t str_TXT_820C043C_B_ = int32_t(0x820C043C);
	constexpr int32_t Destroy_TXT_83498A60_G__address = int32_t(0x832A3C50);
	if (!UseLiftedCode(143, 0x83253D40)) { __imp__sub_83253D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A60_G_, str_TXT_820C043C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A60_G__address);
}
PROMOTED_ENTRY(143, sub_83253D40, 0x83253D40) { ctx.r3.u64 = Construct_TXT_83498A60_G_(ctx, base); }

uint64_t Construct_TXT_83498A64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498A64_G_ = int32_t(0x83498A64);
	constexpr int32_t str_TXT_820C045C_B_ = int32_t(0x820C045C);
	constexpr int32_t Destroy_TXT_83498A64_G__address = int32_t(0x832A3C60);
	if (!UseLiftedCode(143, 0x83253D80)) { __imp__sub_83253D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253D80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498A64_G_, str_TXT_820C045C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498A64_G__address);
}
PROMOTED_ENTRY(143, sub_83253D80, 0x83253D80) { ctx.r3.u64 = Construct_TXT_83498A64_G_(ctx, base); }

uint64_t Construct_TXT_83498ABC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498ABC_G_ = int32_t(0x83498ABC);
	constexpr int32_t str_TXT_820C04F0_B_ = int32_t(0x820C04F0);
	constexpr int32_t Destroy_TXT_83498ABC_G__address = int32_t(0x832A3C70);
	if (!UseLiftedCode(143, 0x83254258)) { __imp__sub_83254258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ABC_G_, str_TXT_820C04F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498ABC_G__address);
}
PROMOTED_ENTRY(143, sub_83254258, 0x83254258) { ctx.r3.u64 = Construct_TXT_83498ABC_G_(ctx, base); }

uint64_t Construct_TXT_83498AC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AC0_G_ = int32_t(0x83498AC0);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498AC0_G__address = int32_t(0x832A3C80);
	if (!UseLiftedCode(143, 0x83254298)) { __imp__sub_83254298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC0_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AC0_G__address);
}
PROMOTED_ENTRY(143, sub_83254298, 0x83254298) { ctx.r3.u64 = Construct_TXT_83498AC0_G_(ctx, base); }

uint64_t Construct_TXT_83498AC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AC4_G_ = int32_t(0x83498AC4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498AC4_G__address = int32_t(0x832A3C90);
	if (!UseLiftedCode(143, 0x832542D8)) { __imp__sub_832542D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832542D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AC4_G__address);
}
PROMOTED_ENTRY(143, sub_832542D8, 0x832542D8) { ctx.r3.u64 = Construct_TXT_83498AC4_G_(ctx, base); }

uint64_t Construct_TXT_83498AC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AC8_G_ = int32_t(0x83498AC8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498AC8_G__address = int32_t(0x832A3CA0);
	if (!UseLiftedCode(143, 0x83254318)) { __imp__sub_83254318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254318);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AC8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AC8_G__address);
}
PROMOTED_ENTRY(143, sub_83254318, 0x83254318) { ctx.r3.u64 = Construct_TXT_83498AC8_G_(ctx, base); }

uint64_t Construct_TXT_83498ACC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498ACC_G_ = int32_t(0x83498ACC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498ACC_G__address = int32_t(0x832A3CB0);
	if (!UseLiftedCode(143, 0x83254358)) { __imp__sub_83254358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ACC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498ACC_G__address);
}
PROMOTED_ENTRY(143, sub_83254358, 0x83254358) { ctx.r3.u64 = Construct_TXT_83498ACC_G_(ctx, base); }

uint64_t Construct_TXT_83498AD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AD0_G_ = int32_t(0x83498AD0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498AD0_G__address = int32_t(0x832A3CC0);
	if (!UseLiftedCode(143, 0x83254398)) { __imp__sub_83254398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AD0_G__address);
}
PROMOTED_ENTRY(143, sub_83254398, 0x83254398) { ctx.r3.u64 = Construct_TXT_83498AD0_G_(ctx, base); }

uint64_t Construct_TXT_83498AD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AD4_G_ = int32_t(0x83498AD4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498AD4_G__address = int32_t(0x832A3CD0);
	if (!UseLiftedCode(143, 0x832543D8)) { __imp__sub_832543D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832543D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AD4_G__address);
}
PROMOTED_ENTRY(143, sub_832543D8, 0x832543D8) { ctx.r3.u64 = Construct_TXT_83498AD4_G_(ctx, base); }

uint64_t Construct_TXT_83498AD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498AD8_G_ = int32_t(0x83498AD8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498AD8_G__address = int32_t(0x832A3CE0);
	if (!UseLiftedCode(143, 0x83254418)) { __imp__sub_83254418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498AD8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498AD8_G__address);
}
PROMOTED_ENTRY(143, sub_83254418, 0x83254418) { ctx.r3.u64 = Construct_TXT_83498AD8_G_(ctx, base); }

uint64_t Construct_TXT_83498B24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B24_G_ = int32_t(0x83498B24);
	constexpr int32_t str_TXT_820C0624_B_ = int32_t(0x820C0624);
	constexpr int32_t Destroy_TXT_83498B24_G__address = int32_t(0x832A3CF0);
	if (!UseLiftedCode(143, 0x83254848)) { __imp__sub_83254848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B24_G_, str_TXT_820C0624_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B24_G__address);
}
PROMOTED_ENTRY(143, sub_83254848, 0x83254848) { ctx.r3.u64 = Construct_TXT_83498B24_G_(ctx, base); }

uint64_t Construct_TXT_83498B28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B28_G_ = int32_t(0x83498B28);
	constexpr int32_t str_TXT_820C0648_B_ = int32_t(0x820C0648);
	constexpr int32_t Destroy_TXT_83498B28_G__address = int32_t(0x832A3D00);
	if (!UseLiftedCode(143, 0x83254888)) { __imp__sub_83254888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B28_G_, str_TXT_820C0648_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B28_G__address);
}
PROMOTED_ENTRY(143, sub_83254888, 0x83254888) { ctx.r3.u64 = Construct_TXT_83498B28_G_(ctx, base); }

uint64_t Construct_TXT_83498B2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B2C_G_ = int32_t(0x83498B2C);
	constexpr int32_t str_TXT_820C066C_B_ = int32_t(0x820C066C);
	constexpr int32_t Destroy_TXT_83498B2C_G__address = int32_t(0x832A3D10);
	if (!UseLiftedCode(143, 0x832548C8)) { __imp__sub_832548C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832548C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B2C_G_, str_TXT_820C066C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B2C_G__address);
}
PROMOTED_ENTRY(143, sub_832548C8, 0x832548C8) { ctx.r3.u64 = Construct_TXT_83498B2C_G_(ctx, base); }

uint64_t Construct_TXT_83498B30_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B30_G_ = int32_t(0x83498B30);
	constexpr int32_t str_TXT_820B27E4_B_ = int32_t(0x820B27E4);
	constexpr int32_t Destroy_TXT_83498B30_G__address = int32_t(0x832A3D20);
	if (!UseLiftedCode(143, 0x83254908)) { __imp__sub_83254908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B30_G_, str_TXT_820B27E4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B30_G__address);
}
PROMOTED_ENTRY(143, sub_83254908, 0x83254908) { ctx.r3.u64 = Construct_TXT_83498B30_G_(ctx, base); }

uint64_t Construct_TXT_83498B34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B34_G_ = int32_t(0x83498B34);
	constexpr int32_t str_TXT_820B2800_B_ = int32_t(0x820B2800);
	constexpr int32_t Destroy_TXT_83498B34_G__address = int32_t(0x832A3D30);
	if (!UseLiftedCode(143, 0x83254948)) { __imp__sub_83254948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B34_G_, str_TXT_820B2800_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B34_G__address);
}
PROMOTED_ENTRY(143, sub_83254948, 0x83254948) { ctx.r3.u64 = Construct_TXT_83498B34_G_(ctx, base); }

uint64_t Construct_TXT_83498B38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B38_G_ = int32_t(0x83498B38);
	constexpr int32_t str_TXT_820C068C_B_ = int32_t(0x820C068C);
	constexpr int32_t Destroy_TXT_83498B38_G__address = int32_t(0x832A3D40);
	if (!UseLiftedCode(143, 0x83254988)) { __imp__sub_83254988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B38_G_, str_TXT_820C068C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B38_G__address);
}
PROMOTED_ENTRY(143, sub_83254988, 0x83254988) { ctx.r3.u64 = Construct_TXT_83498B38_G_(ctx, base); }

uint64_t Construct_TXT_83498B3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B3C_G_ = int32_t(0x83498B3C);
	constexpr int32_t str_TXT_820C06AC_B_ = int32_t(0x820C06AC);
	constexpr int32_t Destroy_TXT_83498B3C_G__address = int32_t(0x832A3D50);
	if (!UseLiftedCode(143, 0x832549C8)) { __imp__sub_832549C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832549C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B3C_G_, str_TXT_820C06AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B3C_G__address);
}
PROMOTED_ENTRY(143, sub_832549C8, 0x832549C8) { ctx.r3.u64 = Construct_TXT_83498B3C_G_(ctx, base); }

uint64_t Construct_TXT_83498B40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B40_G_ = int32_t(0x83498B40);
	constexpr int32_t str_TXT_820C06C8_B_ = int32_t(0x820C06C8);
	constexpr int32_t Destroy_TXT_83498B40_G__address = int32_t(0x832A3D60);
	if (!UseLiftedCode(143, 0x83254A08)) { __imp__sub_83254A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B40_G_, str_TXT_820C06C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B40_G__address);
}
PROMOTED_ENTRY(143, sub_83254A08, 0x83254A08) { ctx.r3.u64 = Construct_TXT_83498B40_G_(ctx, base); }

uint64_t Construct_TXT_83498B44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B44_G_ = int32_t(0x83498B44);
	constexpr int32_t str_TXT_820C06E4_B_ = int32_t(0x820C06E4);
	constexpr int32_t Destroy_TXT_83498B44_G__address = int32_t(0x832A3D70);
	if (!UseLiftedCode(143, 0x83254A48)) { __imp__sub_83254A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B44_G_, str_TXT_820C06E4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B44_G__address);
}
PROMOTED_ENTRY(143, sub_83254A48, 0x83254A48) { ctx.r3.u64 = Construct_TXT_83498B44_G_(ctx, base); }

uint64_t Construct_TXT_83498B48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B48_G_ = int32_t(0x83498B48);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498B48_G__address = int32_t(0x832A3D80);
	if (!UseLiftedCode(143, 0x83254A88)) { __imp__sub_83254A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254A88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B48_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B48_G__address);
}
PROMOTED_ENTRY(143, sub_83254A88, 0x83254A88) { ctx.r3.u64 = Construct_TXT_83498B48_G_(ctx, base); }

uint64_t Construct_TXT_83498B4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B4C_G_ = int32_t(0x83498B4C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498B4C_G__address = int32_t(0x832A3D90);
	if (!UseLiftedCode(143, 0x83254AC8)) { __imp__sub_83254AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B4C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B4C_G__address);
}
PROMOTED_ENTRY(143, sub_83254AC8, 0x83254AC8) { ctx.r3.u64 = Construct_TXT_83498B4C_G_(ctx, base); }

uint64_t Construct_TXT_83498B50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B50_G_ = int32_t(0x83498B50);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498B50_G__address = int32_t(0x832A3DA0);
	if (!UseLiftedCode(143, 0x83254B08)) { __imp__sub_83254B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254B08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B50_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B50_G__address);
}
PROMOTED_ENTRY(143, sub_83254B08, 0x83254B08) { ctx.r3.u64 = Construct_TXT_83498B50_G_(ctx, base); }

uint64_t Construct_TXT_83498B54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B54_G_ = int32_t(0x83498B54);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83498B54_G__address = int32_t(0x832A3DB0);
	if (!UseLiftedCode(143, 0x83254B48)) { __imp__sub_83254B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254B48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B54_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B54_G__address);
}
PROMOTED_ENTRY(143, sub_83254B48, 0x83254B48) { ctx.r3.u64 = Construct_TXT_83498B54_G_(ctx, base); }

uint64_t Construct_TXT_83498B60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B60_G_ = int32_t(0x83498B60);
	constexpr int32_t str_TXT_820C09B4_B_ = int32_t(0x820C09B4);
	constexpr int32_t Destroy_TXT_83498B60_G__address = int32_t(0x832A3DC0);
	if (!UseLiftedCode(143, 0x83254BF8)) { __imp__sub_83254BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B60_G_, str_TXT_820C09B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B60_G__address);
}
PROMOTED_ENTRY(143, sub_83254BF8, 0x83254BF8) { ctx.r3.u64 = Construct_TXT_83498B60_G_(ctx, base); }

uint64_t Construct_TXT_83498B64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B64_G_ = int32_t(0x83498B64);
	constexpr int32_t str_TXT_820C09C4_B_ = int32_t(0x820C09C4);
	constexpr int32_t Destroy_TXT_83498B64_G__address = int32_t(0x832A3DD0);
	if (!UseLiftedCode(143, 0x83254C38)) { __imp__sub_83254C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254C38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B64_G_, str_TXT_820C09C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B64_G__address);
}
PROMOTED_ENTRY(143, sub_83254C38, 0x83254C38) { ctx.r3.u64 = Construct_TXT_83498B64_G_(ctx, base); }

uint64_t Construct_TXT_83498B68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B68_G_ = int32_t(0x83498B68);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83498B68_G__address = int32_t(0x832A3DE0);
	if (!UseLiftedCode(143, 0x83254C78)) { __imp__sub_83254C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254C78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B68_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B68_G__address);
}
PROMOTED_ENTRY(143, sub_83254C78, 0x83254C78) { ctx.r3.u64 = Construct_TXT_83498B68_G_(ctx, base); }

uint64_t Construct_TXT_83498B6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B6C_G_ = int32_t(0x83498B6C);
	constexpr int32_t str_TXT_820AF1BC_B_ = int32_t(0x820AF1BC);
	constexpr int32_t Destroy_TXT_83498B6C_G__address = int32_t(0x832A3DF0);
	if (!UseLiftedCode(143, 0x83254CB8)) { __imp__sub_83254CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254CB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B6C_G_, str_TXT_820AF1BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B6C_G__address);
}
PROMOTED_ENTRY(143, sub_83254CB8, 0x83254CB8) { ctx.r3.u64 = Construct_TXT_83498B6C_G_(ctx, base); }

uint64_t Construct_TXT_83498B70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B70_G_ = int32_t(0x83498B70);
	constexpr int32_t str_TXT_820C0A00_B_ = int32_t(0x820C0A00);
	constexpr int32_t Destroy_TXT_83498B70_G__address = int32_t(0x832A3E00);
	if (!UseLiftedCode(143, 0x83254CF8)) { __imp__sub_83254CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254CF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B70_G_, str_TXT_820C0A00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B70_G__address);
}
PROMOTED_ENTRY(143, sub_83254CF8, 0x83254CF8) { ctx.r3.u64 = Construct_TXT_83498B70_G_(ctx, base); }

uint64_t Construct_TXT_83498B74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B74_G_ = int32_t(0x83498B74);
	constexpr int32_t str_TXT_820C0A18_B_ = int32_t(0x820C0A18);
	constexpr int32_t Destroy_TXT_83498B74_G__address = int32_t(0x832A3E10);
	if (!UseLiftedCode(143, 0x83254D38)) { __imp__sub_83254D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254D38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B74_G_, str_TXT_820C0A18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B74_G__address);
}
PROMOTED_ENTRY(143, sub_83254D38, 0x83254D38) { ctx.r3.u64 = Construct_TXT_83498B74_G_(ctx, base); }

uint64_t Construct_TXT_83498B78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B78_G_ = int32_t(0x83498B78);
	constexpr int32_t str_TXT_820C0A38_B_ = int32_t(0x820C0A38);
	constexpr int32_t Destroy_TXT_83498B78_G__address = int32_t(0x832A3E20);
	if (!UseLiftedCode(143, 0x83254D78)) { __imp__sub_83254D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254D78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B78_G_, str_TXT_820C0A38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B78_G__address);
}
PROMOTED_ENTRY(143, sub_83254D78, 0x83254D78) { ctx.r3.u64 = Construct_TXT_83498B78_G_(ctx, base); }

uint64_t Construct_TXT_83498B7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B7C_G_ = int32_t(0x83498B7C);
	constexpr int32_t str_TXT_820C0A5C_B_ = int32_t(0x820C0A5C);
	constexpr int32_t Destroy_TXT_83498B7C_G__address = int32_t(0x832A3E30);
	if (!UseLiftedCode(143, 0x83254DB8)) { __imp__sub_83254DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B7C_G_, str_TXT_820C0A5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B7C_G__address);
}
PROMOTED_ENTRY(143, sub_83254DB8, 0x83254DB8) { ctx.r3.u64 = Construct_TXT_83498B7C_G_(ctx, base); }

uint64_t Construct_TXT_83498B80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B80_G_ = int32_t(0x83498B80);
	constexpr int32_t str_TXT_820C0A68_B_ = int32_t(0x820C0A68);
	constexpr int32_t Destroy_TXT_83498B80_G__address = int32_t(0x832A3E40);
	if (!UseLiftedCode(143, 0x83254DF8)) { __imp__sub_83254DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B80_G_, str_TXT_820C0A68_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B80_G__address);
}
PROMOTED_ENTRY(143, sub_83254DF8, 0x83254DF8) { ctx.r3.u64 = Construct_TXT_83498B80_G_(ctx, base); }

uint64_t Construct_TXT_83498B84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B84_G_ = int32_t(0x83498B84);
	constexpr int32_t str_TXT_820C0A74_B_ = int32_t(0x820C0A74);
	constexpr int32_t Destroy_TXT_83498B84_G__address = int32_t(0x832A3E50);
	if (!UseLiftedCode(143, 0x83254E38)) { __imp__sub_83254E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B84_G_, str_TXT_820C0A74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B84_G__address);
}
PROMOTED_ENTRY(143, sub_83254E38, 0x83254E38) { ctx.r3.u64 = Construct_TXT_83498B84_G_(ctx, base); }

uint64_t Construct_TXT_83498B88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B88_G_ = int32_t(0x83498B88);
	constexpr int32_t str_TXT_820C0A7C_B_ = int32_t(0x820C0A7C);
	constexpr int32_t Destroy_TXT_83498B88_G__address = int32_t(0x832A3E60);
	if (!UseLiftedCode(143, 0x83254E78)) { __imp__sub_83254E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B88_G_, str_TXT_820C0A7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B88_G__address);
}
PROMOTED_ENTRY(143, sub_83254E78, 0x83254E78) { ctx.r3.u64 = Construct_TXT_83498B88_G_(ctx, base); }

uint64_t Construct_TXT_83498B8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B8C_G_ = int32_t(0x83498B8C);
	constexpr int32_t str_TXT_820C0A7C_B_ = int32_t(0x820C0A7C);
	constexpr int32_t Destroy_TXT_83498B8C_G__address = int32_t(0x832A3E70);
	if (!UseLiftedCode(143, 0x83254EB8)) { __imp__sub_83254EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B8C_G_, str_TXT_820C0A7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B8C_G__address);
}
PROMOTED_ENTRY(143, sub_83254EB8, 0x83254EB8) { ctx.r3.u64 = Construct_TXT_83498B8C_G_(ctx, base); }

uint64_t Construct_TXT_83498B90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B90_G_ = int32_t(0x83498B90);
	constexpr int32_t str_TXT_820C0A9C_B_ = int32_t(0x820C0A9C);
	constexpr int32_t Destroy_TXT_83498B90_G__address = int32_t(0x832A3E80);
	if (!UseLiftedCode(143, 0x83254EF8)) { __imp__sub_83254EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B90_G_, str_TXT_820C0A9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B90_G__address);
}
PROMOTED_ENTRY(143, sub_83254EF8, 0x83254EF8) { ctx.r3.u64 = Construct_TXT_83498B90_G_(ctx, base); }

uint64_t Construct_TXT_83498B94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B94_G_ = int32_t(0x83498B94);
	constexpr int32_t str_TXT_820C0ABC_B_ = int32_t(0x820C0ABC);
	constexpr int32_t Destroy_TXT_83498B94_G__address = int32_t(0x832A3E90);
	if (!UseLiftedCode(143, 0x83254F38)) { __imp__sub_83254F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B94_G_, str_TXT_820C0ABC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B94_G__address);
}
PROMOTED_ENTRY(143, sub_83254F38, 0x83254F38) { ctx.r3.u64 = Construct_TXT_83498B94_G_(ctx, base); }

uint64_t Construct_TXT_83498B98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B98_G_ = int32_t(0x83498B98);
	constexpr int32_t str_TXT_820C0AE0_B_ = int32_t(0x820C0AE0);
	constexpr int32_t Destroy_TXT_83498B98_G__address = int32_t(0x832A3EA0);
	if (!UseLiftedCode(143, 0x83254F78)) { __imp__sub_83254F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B98_G_, str_TXT_820C0AE0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B98_G__address);
}
PROMOTED_ENTRY(143, sub_83254F78, 0x83254F78) { ctx.r3.u64 = Construct_TXT_83498B98_G_(ctx, base); }

uint64_t Construct_TXT_83498B9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498B9C_G_ = int32_t(0x83498B9C);
	constexpr int32_t str_TXT_820C0B04_B_ = int32_t(0x820C0B04);
	constexpr int32_t Destroy_TXT_83498B9C_G__address = int32_t(0x832A3EB0);
	if (!UseLiftedCode(143, 0x83254FB8)) { __imp__sub_83254FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498B9C_G_, str_TXT_820C0B04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498B9C_G__address);
}
PROMOTED_ENTRY(143, sub_83254FB8, 0x83254FB8) { ctx.r3.u64 = Construct_TXT_83498B9C_G_(ctx, base); }

uint64_t Construct_TXT_83498BA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BA0_G_ = int32_t(0x83498BA0);
	constexpr int32_t str_TXT_820C0B28_B_ = int32_t(0x820C0B28);
	constexpr int32_t Destroy_TXT_83498BA0_G__address = int32_t(0x832A3EC0);
	if (!UseLiftedCode(143, 0x83254FF8)) { __imp__sub_83254FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA0_G_, str_TXT_820C0B28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BA0_G__address);
}
PROMOTED_ENTRY(143, sub_83254FF8, 0x83254FF8) { ctx.r3.u64 = Construct_TXT_83498BA0_G_(ctx, base); }

uint64_t Construct_TXT_83498BA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BA4_G_ = int32_t(0x83498BA4);
	constexpr int32_t str_TXT_820C0B34_B_ = int32_t(0x820C0B34);
	constexpr int32_t Destroy_TXT_83498BA4_G__address = int32_t(0x832A3ED0);
	if (!UseLiftedCode(143, 0x83255038)) { __imp__sub_83255038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA4_G_, str_TXT_820C0B34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BA4_G__address);
}
PROMOTED_ENTRY(143, sub_83255038, 0x83255038) { ctx.r3.u64 = Construct_TXT_83498BA4_G_(ctx, base); }

uint64_t Construct_TXT_83498BA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BA8_G_ = int32_t(0x83498BA8);
	constexpr int32_t str_TXT_820C0B50_B_ = int32_t(0x820C0B50);
	constexpr int32_t Destroy_TXT_83498BA8_G__address = int32_t(0x832A3EE0);
	if (!UseLiftedCode(143, 0x83255078)) { __imp__sub_83255078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BA8_G_, str_TXT_820C0B50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BA8_G__address);
}
PROMOTED_ENTRY(143, sub_83255078, 0x83255078) { ctx.r3.u64 = Construct_TXT_83498BA8_G_(ctx, base); }

uint64_t Construct_TXT_83498BAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BAC_G_ = int32_t(0x83498BAC);
	constexpr int32_t str_TXT_820C0B64_B_ = int32_t(0x820C0B64);
	constexpr int32_t Destroy_TXT_83498BAC_G__address = int32_t(0x832A3EF0);
	if (!UseLiftedCode(143, 0x832550B8)) { __imp__sub_832550B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832550B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BAC_G_, str_TXT_820C0B64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BAC_G__address);
}
PROMOTED_ENTRY(143, sub_832550B8, 0x832550B8) { ctx.r3.u64 = Construct_TXT_83498BAC_G_(ctx, base); }

uint64_t Construct_TXT_83498BB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BB0_G_ = int32_t(0x83498BB0);
	constexpr int32_t str_TXT_820C06C8_B_ = int32_t(0x820C06C8);
	constexpr int32_t Destroy_TXT_83498BB0_G__address = int32_t(0x832A3F00);
	if (!UseLiftedCode(143, 0x832550F8)) { __imp__sub_832550F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832550F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB0_G_, str_TXT_820C06C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BB0_G__address);
}
PROMOTED_ENTRY(143, sub_832550F8, 0x832550F8) { ctx.r3.u64 = Construct_TXT_83498BB0_G_(ctx, base); }

uint64_t Construct_TXT_83498BB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BB4_G_ = int32_t(0x83498BB4);
	constexpr int32_t str_TXT_820C0B28_B_ = int32_t(0x820C0B28);
	constexpr int32_t Destroy_TXT_83498BB4_G__address = int32_t(0x832A3F10);
	if (!UseLiftedCode(143, 0x83255138)) { __imp__sub_83255138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB4_G_, str_TXT_820C0B28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BB4_G__address);
}
PROMOTED_ENTRY(143, sub_83255138, 0x83255138) { ctx.r3.u64 = Construct_TXT_83498BB4_G_(ctx, base); }

uint64_t Construct_TXT_83498BB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BB8_G_ = int32_t(0x83498BB8);
	constexpr int32_t str_TXT_820C0B80_B_ = int32_t(0x820C0B80);
	constexpr int32_t Destroy_TXT_83498BB8_G__address = int32_t(0x832A3F20);
	if (!UseLiftedCode(143, 0x83255178)) { __imp__sub_83255178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255178);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BB8_G_, str_TXT_820C0B80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BB8_G__address);
}
PROMOTED_ENTRY(143, sub_83255178, 0x83255178) { ctx.r3.u64 = Construct_TXT_83498BB8_G_(ctx, base); }

uint64_t Construct_TXT_83498BBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BBC_G_ = int32_t(0x83498BBC);
	constexpr int32_t str_TXT_8200252C_B_ = int32_t(0x8200252C);
	constexpr int32_t Destroy_TXT_83498BBC_G__address = int32_t(0x832A3F30);
	if (!UseLiftedCode(143, 0x832551B8)) { __imp__sub_832551B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832551B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BBC_G_, str_TXT_8200252C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BBC_G__address);
}
PROMOTED_ENTRY(143, sub_832551B8, 0x832551B8) { ctx.r3.u64 = Construct_TXT_83498BBC_G_(ctx, base); }

uint64_t Construct_TXT_83498BC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BC0_G_ = int32_t(0x83498BC0);
	constexpr int32_t str_TXT_820A8BEC_B_ = int32_t(0x820A8BEC);
	constexpr int32_t Destroy_TXT_83498BC0_G__address = int32_t(0x832A3F40);
	if (!UseLiftedCode(143, 0x832551F8)) { __imp__sub_832551F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832551F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC0_G_, str_TXT_820A8BEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BC0_G__address);
}
PROMOTED_ENTRY(143, sub_832551F8, 0x832551F8) { ctx.r3.u64 = Construct_TXT_83498BC0_G_(ctx, base); }

uint64_t Construct_TXT_83498BC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BC4_G_ = int32_t(0x83498BC4);
	constexpr int32_t str_TXT_820A8BB4_B_ = int32_t(0x820A8BB4);
	constexpr int32_t Destroy_TXT_83498BC4_G__address = int32_t(0x832A3F50);
	if (!UseLiftedCode(143, 0x83255238)) { __imp__sub_83255238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC4_G_, str_TXT_820A8BB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BC4_G__address);
}
PROMOTED_ENTRY(143, sub_83255238, 0x83255238) { ctx.r3.u64 = Construct_TXT_83498BC4_G_(ctx, base); }

uint64_t Construct_TXT_83498BC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BC8_G_ = int32_t(0x83498BC8);
	constexpr int32_t str_TXT_820A8BD0_B_ = int32_t(0x820A8BD0);
	constexpr int32_t Destroy_TXT_83498BC8_G__address = int32_t(0x832A3F60);
	if (!UseLiftedCode(143, 0x83255278)) { __imp__sub_83255278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BC8_G_, str_TXT_820A8BD0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BC8_G__address);
}
PROMOTED_ENTRY(143, sub_83255278, 0x83255278) { ctx.r3.u64 = Construct_TXT_83498BC8_G_(ctx, base); }

uint64_t Construct_TXT_83498BCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498BCC_G_ = int32_t(0x83498BCC);
	constexpr int32_t str_TXT_820C0BA0_B_ = int32_t(0x820C0BA0);
	constexpr int32_t Destroy_TXT_83498BCC_G__address = int32_t(0x832A3F70);
	if (!UseLiftedCode(143, 0x832552B8)) { __imp__sub_832552B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832552B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498BCC_G_, str_TXT_820C0BA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498BCC_G__address);
}
PROMOTED_ENTRY(143, sub_832552B8, 0x832552B8) { ctx.r3.u64 = Construct_TXT_83498BCC_G_(ctx, base); }

uint64_t Construct_TXT_83498C24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C24_G_ = int32_t(0x83498C24);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_83498C24_G__address = int32_t(0x832A3F80);
	if (!UseLiftedCode(143, 0x83255790)) { __imp__sub_83255790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C24_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C24_G__address);
}
PROMOTED_ENTRY(143, sub_83255790, 0x83255790) { ctx.r3.u64 = Construct_TXT_83498C24_G_(ctx, base); }

uint64_t Construct_TXT_83498C28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C28_G_ = int32_t(0x83498C28);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498C28_G__address = int32_t(0x832A3F90);
	if (!UseLiftedCode(143, 0x832557D0)) { __imp__sub_832557D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832557D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C28_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C28_G__address);
}
PROMOTED_ENTRY(143, sub_832557D0, 0x832557D0) { ctx.r3.u64 = Construct_TXT_83498C28_G_(ctx, base); }

uint64_t Construct_TXT_83498C2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C2C_G_ = int32_t(0x83498C2C);
	constexpr int32_t str_TXT_820C0D8C_B_ = int32_t(0x820C0D8C);
	constexpr int32_t Destroy_TXT_83498C2C_G__address = int32_t(0x832A3FA0);
	if (!UseLiftedCode(143, 0x83255810)) { __imp__sub_83255810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255810);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C2C_G_, str_TXT_820C0D8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C2C_G__address);
}
PROMOTED_ENTRY(143, sub_83255810, 0x83255810) { ctx.r3.u64 = Construct_TXT_83498C2C_G_(ctx, base); }

uint64_t Construct_TXT_83498C30_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C30_G_ = int32_t(0x83498C30);
	constexpr int32_t str_TXT_820C0D8C_B_ = int32_t(0x820C0DC8);
	constexpr int32_t Destroy_TXT_83498C30_G__address = int32_t(0x832A3FB0);
	if (!UseLiftedCode(143, 0x83255850)) { __imp__sub_83255850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255850);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C30_G_, str_TXT_820C0D8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C30_G__address);
}
PROMOTED_ENTRY(143, sub_83255850, 0x83255850) { ctx.r3.u64 = Construct_TXT_83498C30_G_(ctx, base); }

uint64_t Construct_TXT_83498C34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C34_G_ = int32_t(0x83498C34);
	constexpr int32_t str_TXT_820C0DFC_B_ = int32_t(0x820C0DFC);
	constexpr int32_t Destroy_TXT_83498C34_G__address = int32_t(0x832A3FC0);
	if (!UseLiftedCode(143, 0x83255890)) { __imp__sub_83255890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255890);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C34_G_, str_TXT_820C0DFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C34_G__address);
}
PROMOTED_ENTRY(143, sub_83255890, 0x83255890) { ctx.r3.u64 = Construct_TXT_83498C34_G_(ctx, base); }

uint64_t Construct_TXT_83498C38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C38_G_ = int32_t(0x83498C38);
	constexpr int32_t str_TXT_820C0DFC_B_ = int32_t(0x820C0E38);
	constexpr int32_t Destroy_TXT_83498C38_G__address = int32_t(0x832A3FD0);
	if (!UseLiftedCode(143, 0x832558D0)) { __imp__sub_832558D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832558D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C38_G_, str_TXT_820C0DFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C38_G__address);
}
PROMOTED_ENTRY(143, sub_832558D0, 0x832558D0) { ctx.r3.u64 = Construct_TXT_83498C38_G_(ctx, base); }

uint64_t Construct_TXT_83498C3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C3C_G_ = int32_t(0x83498C3C);
	constexpr int32_t str_TXT_820C0E6C_B_ = int32_t(0x820C0E6C);
	constexpr int32_t Destroy_TXT_83498C3C_G__address = int32_t(0x832A3FE0);
	if (!UseLiftedCode(143, 0x83255910)) { __imp__sub_83255910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C3C_G_, str_TXT_820C0E6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C3C_G__address);
}
PROMOTED_ENTRY(143, sub_83255910, 0x83255910) { ctx.r3.u64 = Construct_TXT_83498C3C_G_(ctx, base); }

uint64_t Construct_TXT_83498C94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C94_G_ = int32_t(0x83498C94);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498C94_G__address = int32_t(0x832A3FF0);
	if (!UseLiftedCode(143, 0x83255DE8)) { __imp__sub_83255DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255DE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C94_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C94_G__address);
}
PROMOTED_ENTRY(143, sub_83255DE8, 0x83255DE8) { ctx.r3.u64 = Construct_TXT_83498C94_G_(ctx, base); }

uint64_t Construct_TXT_83498C98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C98_G_ = int32_t(0x83498C98);
	constexpr int32_t str_TXT_820C0F54_B_ = int32_t(0x820C0F54);
	constexpr int32_t Destroy_TXT_83498C98_G__address = int32_t(0x832A4000);
	if (!UseLiftedCode(143, 0x83255E28)) { __imp__sub_83255E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255E28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C98_G_, str_TXT_820C0F54_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C98_G__address);
}
PROMOTED_ENTRY(143, sub_83255E28, 0x83255E28) { ctx.r3.u64 = Construct_TXT_83498C98_G_(ctx, base); }

uint64_t Construct_TXT_83498C9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498C9C_G_ = int32_t(0x83498C9C);
	constexpr int32_t str_TXT_820C0F78_B_ = int32_t(0x820C0F78);
	constexpr int32_t Destroy_TXT_83498C9C_G__address = int32_t(0x832A4010);
	if (!UseLiftedCode(143, 0x83255E68)) { __imp__sub_83255E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255E68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498C9C_G_, str_TXT_820C0F78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498C9C_G__address);
}
PROMOTED_ENTRY(143, sub_83255E68, 0x83255E68) { ctx.r3.u64 = Construct_TXT_83498C9C_G_(ctx, base); }

uint64_t Construct_TXT_83498CF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498CF4_G_ = int32_t(0x83498CF4);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_83498CF4_G__address = int32_t(0x832A4020);
	if (!UseLiftedCode(143, 0x83256340)) { __imp__sub_83256340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256340);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498CF4_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498CF4_G__address);
}
PROMOTED_ENTRY(143, sub_83256340, 0x83256340) { ctx.r3.u64 = Construct_TXT_83498CF4_G_(ctx, base); }

uint64_t Construct_TXT_83498CF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498CF8_G_ = int32_t(0x83498CF8);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498CF8_G__address = int32_t(0x832A4030);
	if (!UseLiftedCode(143, 0x83256380)) { __imp__sub_83256380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256380);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498CF8_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498CF8_G__address);
}
PROMOTED_ENTRY(143, sub_83256380, 0x83256380) { ctx.r3.u64 = Construct_TXT_83498CF8_G_(ctx, base); }

uint64_t Construct_TXT_83498D58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498D58_G_ = int32_t(0x83498D58);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498D58_G__address = int32_t(0x832A4040);
	if (!UseLiftedCode(143, 0x832568C8)) { __imp__sub_832568C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832568C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498D58_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498D58_G__address);
}
PROMOTED_ENTRY(143, sub_832568C8, 0x832568C8) { ctx.r3.u64 = Construct_TXT_83498D58_G_(ctx, base); }

uint64_t Construct_TXT_83498D5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498D5C_G_ = int32_t(0x83498D5C);
	constexpr int32_t str_TXT_820C0F78_B_ = int32_t(0x820C0F78);
	constexpr int32_t Destroy_TXT_83498D5C_G__address = int32_t(0x832A4050);
	if (!UseLiftedCode(143, 0x83256908)) { __imp__sub_83256908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498D5C_G_, str_TXT_820C0F78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498D5C_G__address);
}
PROMOTED_ENTRY(143, sub_83256908, 0x83256908) { ctx.r3.u64 = Construct_TXT_83498D5C_G_(ctx, base); }

uint64_t Construct_TXT_83498DB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DB4_G_ = int32_t(0x83498DB4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498DB4_G__address = int32_t(0x832A4060);
	if (!UseLiftedCode(143, 0x83256DE0)) { __imp__sub_83256DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256DE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DB4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DB4_G__address);
}
PROMOTED_ENTRY(143, sub_83256DE0, 0x83256DE0) { ctx.r3.u64 = Construct_TXT_83498DB4_G_(ctx, base); }

uint64_t Construct_TXT_83498DB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DB8_G_ = int32_t(0x83498DB8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498DB8_G__address = int32_t(0x832A4070);
	if (!UseLiftedCode(143, 0x83256E20)) { __imp__sub_83256E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256E20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DB8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DB8_G__address);
}
PROMOTED_ENTRY(143, sub_83256E20, 0x83256E20) { ctx.r3.u64 = Construct_TXT_83498DB8_G_(ctx, base); }

uint64_t Construct_TXT_83498DBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DBC_G_ = int32_t(0x83498DBC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498DBC_G__address = int32_t(0x832A4080);
	if (!UseLiftedCode(143, 0x83256E60)) { __imp__sub_83256E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256E60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DBC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DBC_G__address);
}
PROMOTED_ENTRY(143, sub_83256E60, 0x83256E60) { ctx.r3.u64 = Construct_TXT_83498DBC_G_(ctx, base); }

uint64_t Construct_TXT_83498DC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DC0_G_ = int32_t(0x83498DC0);
	constexpr int32_t str_TXT_820C1940_B_ = int32_t(0x820C1940);
	constexpr int32_t Destroy_TXT_83498DC0_G__address = int32_t(0x832A4090);
	if (!UseLiftedCode(143, 0x83256EA0)) { __imp__sub_83256EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256EA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC0_G_, str_TXT_820C1940_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DC0_G__address);
}
PROMOTED_ENTRY(143, sub_83256EA0, 0x83256EA0) { ctx.r3.u64 = Construct_TXT_83498DC0_G_(ctx, base); }

uint64_t Construct_TXT_83498DC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DC4_G_ = int32_t(0x83498DC4);
	constexpr int32_t str_TXT_820C1940_B_ = int32_t(0x820C194C);
	constexpr int32_t Destroy_TXT_83498DC4_G__address = int32_t(0x832A40A0);
	if (!UseLiftedCode(143, 0x83256EE0)) { __imp__sub_83256EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256EE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC4_G_, str_TXT_820C1940_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DC4_G__address);
}
PROMOTED_ENTRY(143, sub_83256EE0, 0x83256EE0) { ctx.r3.u64 = Construct_TXT_83498DC4_G_(ctx, base); }

uint64_t Construct_TXT_83498DC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DC8_G_ = int32_t(0x83498DC8);
	constexpr int32_t str_TXT_820C1994_B_ = int32_t(0x820C1994);
	constexpr int32_t Destroy_TXT_83498DC8_G__address = int32_t(0x832A40B0);
	if (!UseLiftedCode(143, 0x83256F20)) { __imp__sub_83256F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256F20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DC8_G_, str_TXT_820C1994_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DC8_G__address);
}
PROMOTED_ENTRY(143, sub_83256F20, 0x83256F20) { ctx.r3.u64 = Construct_TXT_83498DC8_G_(ctx, base); }

uint64_t Construct_TXT_83498DCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DCC_G_ = int32_t(0x83498DCC);
	constexpr int32_t str_TXT_820C19A0_B_ = int32_t(0x820C19A0);
	constexpr int32_t Destroy_TXT_83498DCC_G__address = int32_t(0x832A40C0);
	if (!UseLiftedCode(143, 0x83256F60)) { __imp__sub_83256F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256F60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DCC_G_, str_TXT_820C19A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DCC_G__address);
}
PROMOTED_ENTRY(143, sub_83256F60, 0x83256F60) { ctx.r3.u64 = Construct_TXT_83498DCC_G_(ctx, base); }

uint64_t Construct_TXT_83498DD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DD0_G_ = int32_t(0x83498DD0);
	constexpr int32_t str_TXT_820C19B0_B_ = int32_t(0x820C19B0);
	constexpr int32_t Destroy_TXT_83498DD0_G__address = int32_t(0x832A40D0);
	if (!UseLiftedCode(143, 0x83256FA0)) { __imp__sub_83256FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256FA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD0_G_, str_TXT_820C19B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DD0_G__address);
}
PROMOTED_ENTRY(143, sub_83256FA0, 0x83256FA0) { ctx.r3.u64 = Construct_TXT_83498DD0_G_(ctx, base); }

uint64_t Construct_TXT_83498DD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DD4_G_ = int32_t(0x83498DD4);
	constexpr int32_t str_TXT_820ABD40_B_ = int32_t(0x820ABD40);
	constexpr int32_t Destroy_TXT_83498DD4_G__address = int32_t(0x832A40E0);
	if (!UseLiftedCode(143, 0x83256FE0)) { __imp__sub_83256FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256FE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD4_G_, str_TXT_820ABD40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DD4_G__address);
}
PROMOTED_ENTRY(143, sub_83256FE0, 0x83256FE0) { ctx.r3.u64 = Construct_TXT_83498DD4_G_(ctx, base); }

uint64_t Construct_TXT_83498DD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498DD8_G_ = int32_t(0x83498DD8);
	constexpr int32_t str_TXT_820ABD48_B_ = int32_t(0x820ABD48);
	constexpr int32_t Destroy_TXT_83498DD8_G__address = int32_t(0x832A40F0);
	if (!UseLiftedCode(143, 0x83257020)) { __imp__sub_83257020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257020);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498DD8_G_, str_TXT_820ABD48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498DD8_G__address);
}
PROMOTED_ENTRY(143, sub_83257020, 0x83257020) { ctx.r3.u64 = Construct_TXT_83498DD8_G_(ctx, base); }

uint64_t Construct_TXT_83498E44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E44_G_ = int32_t(0x83498E44);
	constexpr int32_t str_TXT_820C1A60_B_ = int32_t(0x820C1A60);
	constexpr int32_t Destroy_TXT_83498E44_G__address = int32_t(0x832A4100);
	if (!UseLiftedCode(143, 0x83257558)) { __imp__sub_83257558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E44_G_, str_TXT_820C1A60_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E44_G__address);
}
PROMOTED_ENTRY(143, sub_83257558, 0x83257558) { ctx.r3.u64 = Construct_TXT_83498E44_G_(ctx, base); }

uint64_t Construct_TXT_83498E48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E48_G_ = int32_t(0x83498E48);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498E48_G__address = int32_t(0x832A4110);
	if (!UseLiftedCode(143, 0x83257598)) { __imp__sub_83257598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E48_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E48_G__address);
}
PROMOTED_ENTRY(143, sub_83257598, 0x83257598) { ctx.r3.u64 = Construct_TXT_83498E48_G_(ctx, base); }

uint64_t Construct_TXT_83498E4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E4C_G_ = int32_t(0x83498E4C);
	constexpr int32_t str_TXT_820C1A7C_B_ = int32_t(0x820C1A7C);
	constexpr int32_t Destroy_TXT_83498E4C_G__address = int32_t(0x832A4120);
	if (!UseLiftedCode(143, 0x832575D8)) { __imp__sub_832575D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832575D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E4C_G_, str_TXT_820C1A7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E4C_G__address);
}
PROMOTED_ENTRY(143, sub_832575D8, 0x832575D8) { ctx.r3.u64 = Construct_TXT_83498E4C_G_(ctx, base); }

uint64_t Construct_TXT_83498E50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E50_G_ = int32_t(0x83498E50);
	constexpr int32_t str_TXT_820C1AB8_B_ = int32_t(0x820C1AB8);
	constexpr int32_t Destroy_TXT_83498E50_G__address = int32_t(0x832A4130);
	if (!UseLiftedCode(143, 0x83257618)) { __imp__sub_83257618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257618);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E50_G_, str_TXT_820C1AB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E50_G__address);
}
PROMOTED_ENTRY(143, sub_83257618, 0x83257618) { ctx.r3.u64 = Construct_TXT_83498E50_G_(ctx, base); }

uint64_t Construct_TXT_83498E54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E54_G_ = int32_t(0x83498E54);
	constexpr int32_t str_TXT_820C1ADC_B_ = int32_t(0x820C1ADC);
	constexpr int32_t Destroy_TXT_83498E54_G__address = int32_t(0x832A4140);
	if (!UseLiftedCode(143, 0x83257658)) { __imp__sub_83257658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257658);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E54_G_, str_TXT_820C1ADC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E54_G__address);
}
PROMOTED_ENTRY(143, sub_83257658, 0x83257658) { ctx.r3.u64 = Construct_TXT_83498E54_G_(ctx, base); }

uint64_t Construct_TXT_83498E58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E58_G_ = int32_t(0x83498E58);
	constexpr int32_t str_TXT_820C1B00_B_ = int32_t(0x820C1B00);
	constexpr int32_t Destroy_TXT_83498E58_G__address = int32_t(0x832A4150);
	if (!UseLiftedCode(143, 0x83257698)) { __imp__sub_83257698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257698);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E58_G_, str_TXT_820C1B00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E58_G__address);
}
PROMOTED_ENTRY(143, sub_83257698, 0x83257698) { ctx.r3.u64 = Construct_TXT_83498E58_G_(ctx, base); }

uint64_t Construct_TXT_83498E5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E5C_G_ = int32_t(0x83498E5C);
	constexpr int32_t str_TXT_820C1B20_B_ = int32_t(0x820C1B20);
	constexpr int32_t Destroy_TXT_83498E5C_G__address = int32_t(0x832A4160);
	if (!UseLiftedCode(143, 0x832576D8)) { __imp__sub_832576D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832576D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E5C_G_, str_TXT_820C1B20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E5C_G__address);
}
PROMOTED_ENTRY(143, sub_832576D8, 0x832576D8) { ctx.r3.u64 = Construct_TXT_83498E5C_G_(ctx, base); }

uint64_t Construct_TXT_83498E60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E60_G_ = int32_t(0x83498E60);
	constexpr int32_t str_TXT_820C1B40_B_ = int32_t(0x820C1B40);
	constexpr int32_t Destroy_TXT_83498E60_G__address = int32_t(0x832A4170);
	if (!UseLiftedCode(143, 0x83257718)) { __imp__sub_83257718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257718);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E60_G_, str_TXT_820C1B40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E60_G__address);
}
PROMOTED_ENTRY(143, sub_83257718, 0x83257718) { ctx.r3.u64 = Construct_TXT_83498E60_G_(ctx, base); }

uint64_t Construct_TXT_83498E64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E64_G_ = int32_t(0x83498E64);
	constexpr int32_t str_TXT_820C1B6C_B_ = int32_t(0x820C1B6C);
	constexpr int32_t Destroy_TXT_83498E64_G__address = int32_t(0x832A4180);
	if (!UseLiftedCode(143, 0x83257758)) { __imp__sub_83257758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E64_G_, str_TXT_820C1B6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E64_G__address);
}
PROMOTED_ENTRY(143, sub_83257758, 0x83257758) { ctx.r3.u64 = Construct_TXT_83498E64_G_(ctx, base); }

uint64_t Construct_TXT_83498E68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E68_G_ = int32_t(0x83498E68);
	constexpr int32_t str_TXT_820C1B98_B_ = int32_t(0x820C1B98);
	constexpr int32_t Destroy_TXT_83498E68_G__address = int32_t(0x832A4190);
	if (!UseLiftedCode(143, 0x83257798)) { __imp__sub_83257798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E68_G_, str_TXT_820C1B98_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E68_G__address);
}
PROMOTED_ENTRY(143, sub_83257798, 0x83257798) { ctx.r3.u64 = Construct_TXT_83498E68_G_(ctx, base); }

uint64_t Construct_TXT_83498E6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E6C_G_ = int32_t(0x83498E6C);
	constexpr int32_t str_TXT_820C1BC4_B_ = int32_t(0x820C1BC4);
	constexpr int32_t Destroy_TXT_83498E6C_G__address = int32_t(0x832A41A0);
	if (!UseLiftedCode(143, 0x832577D8)) { __imp__sub_832577D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832577D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E6C_G_, str_TXT_820C1BC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E6C_G__address);
}
PROMOTED_ENTRY(143, sub_832577D8, 0x832577D8) { ctx.r3.u64 = Construct_TXT_83498E6C_G_(ctx, base); }

uint64_t Construct_TXT_83498E70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E70_G_ = int32_t(0x83498E70);
	constexpr int32_t str_TXT_820C1BEC_B_ = int32_t(0x820C1BEC);
	constexpr int32_t Destroy_TXT_83498E70_G__address = int32_t(0x832A41B0);
	if (!UseLiftedCode(143, 0x83257818)) { __imp__sub_83257818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E70_G_, str_TXT_820C1BEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E70_G__address);
}
PROMOTED_ENTRY(143, sub_83257818, 0x83257818) { ctx.r3.u64 = Construct_TXT_83498E70_G_(ctx, base); }

uint64_t Construct_TXT_83498E74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E74_G_ = int32_t(0x83498E74);
	constexpr int32_t str_TXT_820C1C14_B_ = int32_t(0x820C1C14);
	constexpr int32_t Destroy_TXT_83498E74_G__address = int32_t(0x832A41C0);
	if (!UseLiftedCode(143, 0x83257858)) { __imp__sub_83257858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257858);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E74_G_, str_TXT_820C1C14_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E74_G__address);
}
PROMOTED_ENTRY(143, sub_83257858, 0x83257858) { ctx.r3.u64 = Construct_TXT_83498E74_G_(ctx, base); }

uint64_t Construct_TXT_83498E78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E78_G_ = int32_t(0x83498E78);
	constexpr int32_t str_TXT_820C1C40_B_ = int32_t(0x820C1C40);
	constexpr int32_t Destroy_TXT_83498E78_G__address = int32_t(0x832A41D0);
	if (!UseLiftedCode(143, 0x83257898)) { __imp__sub_83257898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E78_G_, str_TXT_820C1C40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E78_G__address);
}
PROMOTED_ENTRY(143, sub_83257898, 0x83257898) { ctx.r3.u64 = Construct_TXT_83498E78_G_(ctx, base); }

uint64_t Construct_TXT_83498E7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E7C_G_ = int32_t(0x83498E7C);
	constexpr int32_t str_TXT_820C1C6C_B_ = int32_t(0x820C1C6C);
	constexpr int32_t Destroy_TXT_83498E7C_G__address = int32_t(0x832A41E0);
	if (!UseLiftedCode(143, 0x832578D8)) { __imp__sub_832578D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832578D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E7C_G_, str_TXT_820C1C6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E7C_G__address);
}
PROMOTED_ENTRY(143, sub_832578D8, 0x832578D8) { ctx.r3.u64 = Construct_TXT_83498E7C_G_(ctx, base); }

uint64_t Construct_TXT_83498E80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498E80_G_ = int32_t(0x83498E80);
	constexpr int32_t str_TXT_820C04F0_B_ = int32_t(0x820C04F0);
	constexpr int32_t Destroy_TXT_83498E80_G__address = int32_t(0x832A41F0);
	if (!UseLiftedCode(143, 0x83257918)) { __imp__sub_83257918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257918);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498E80_G_, str_TXT_820C04F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498E80_G__address);
}
PROMOTED_ENTRY(143, sub_83257918, 0x83257918) { ctx.r3.u64 = Construct_TXT_83498E80_G_(ctx, base); }

uint64_t Construct_TXT_83498ED8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498ED8_G_ = int32_t(0x83498ED8);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498ED8_G__address = int32_t(0x832A4200);
	if (!UseLiftedCode(143, 0x83257DF0)) { __imp__sub_83257DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257DF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498ED8_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498ED8_G__address);
}
PROMOTED_ENTRY(143, sub_83257DF0, 0x83257DF0) { ctx.r3.u64 = Construct_TXT_83498ED8_G_(ctx, base); }

uint64_t Construct_TXT_83498F30_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F30_G_ = int32_t(0x83498F30);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_83498F30_G__address = int32_t(0x832A4210);
	if (!UseLiftedCode(143, 0x832582C8)) { __imp__sub_832582C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832582C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F30_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F30_G__address);
}
PROMOTED_ENTRY(143, sub_832582C8, 0x832582C8) { ctx.r3.u64 = Construct_TXT_83498F30_G_(ctx, base); }

uint64_t Construct_TXT_83498F34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F34_G_ = int32_t(0x83498F34);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83498F34_G__address = int32_t(0x832A4220);
	if (!UseLiftedCode(143, 0x83258308)) { __imp__sub_83258308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F34_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F34_G__address);
}
PROMOTED_ENTRY(143, sub_83258308, 0x83258308) { ctx.r3.u64 = Construct_TXT_83498F34_G_(ctx, base); }

uint64_t Construct_TXT_83498F38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F38_G_ = int32_t(0x83498F38);
	constexpr int32_t str_TXT_820C1E24_B_ = int32_t(0x820C1E24);
	constexpr int32_t Destroy_TXT_83498F38_G__address = int32_t(0x832A4230);
	if (!UseLiftedCode(143, 0x83258348)) { __imp__sub_83258348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F38_G_, str_TXT_820C1E24_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F38_G__address);
}
PROMOTED_ENTRY(143, sub_83258348, 0x83258348) { ctx.r3.u64 = Construct_TXT_83498F38_G_(ctx, base); }

uint64_t Construct_TXT_83498F3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F3C_G_ = int32_t(0x83498F3C);
	constexpr int32_t str_TXT_820C1E48_B_ = int32_t(0x820C1E48);
	constexpr int32_t Destroy_TXT_83498F3C_G__address = int32_t(0x832A4240);
	if (!UseLiftedCode(143, 0x83258388)) { __imp__sub_83258388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F3C_G_, str_TXT_820C1E48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F3C_G__address);
}
PROMOTED_ENTRY(143, sub_83258388, 0x83258388) { ctx.r3.u64 = Construct_TXT_83498F3C_G_(ctx, base); }

uint64_t Construct_TXT_83498F40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F40_G_ = int32_t(0x83498F40);
	constexpr int32_t str_TXT_820C1E68_B_ = int32_t(0x820C1E68);
	constexpr int32_t Destroy_TXT_83498F40_G__address = int32_t(0x832A4250);
	if (!UseLiftedCode(143, 0x832583C8)) { __imp__sub_832583C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832583C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F40_G_, str_TXT_820C1E68_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F40_G__address);
}
PROMOTED_ENTRY(143, sub_832583C8, 0x832583C8) { ctx.r3.u64 = Construct_TXT_83498F40_G_(ctx, base); }

uint64_t Construct_TXT_83498F44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F44_G_ = int32_t(0x83498F44);
	constexpr int32_t str_TXT_820C1E88_B_ = int32_t(0x820C1E88);
	constexpr int32_t Destroy_TXT_83498F44_G__address = int32_t(0x832A4260);
	if (!UseLiftedCode(143, 0x83258408)) { __imp__sub_83258408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F44_G_, str_TXT_820C1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F44_G__address);
}
PROMOTED_ENTRY(143, sub_83258408, 0x83258408) { ctx.r3.u64 = Construct_TXT_83498F44_G_(ctx, base); }

uint64_t Construct_TXT_83498F48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F48_G_ = int32_t(0x83498F48);
	constexpr int32_t str_TXT_820C1EAC_B_ = int32_t(0x820C1EAC);
	constexpr int32_t Destroy_TXT_83498F48_G__address = int32_t(0x832A4270);
	if (!UseLiftedCode(143, 0x83258448)) { __imp__sub_83258448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F48_G_, str_TXT_820C1EAC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F48_G__address);
}
PROMOTED_ENTRY(143, sub_83258448, 0x83258448) { ctx.r3.u64 = Construct_TXT_83498F48_G_(ctx, base); }

uint64_t Construct_TXT_83498F4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F4C_G_ = int32_t(0x83498F4C);
	constexpr int32_t str_TXT_820C22E4_B_ = int32_t(0x820C22E4);
	constexpr int32_t Destroy_TXT_83498F4C_G__address = int32_t(0x832A42E0);
	if (!UseLiftedCode(143, 0x83258488)) { __imp__sub_83258488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F4C_G_, str_TXT_820C22E4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F4C_G__address);
}
PROMOTED_ENTRY(143, sub_83258488, 0x83258488) { ctx.r3.u64 = Construct_TXT_83498F4C_G_(ctx, base); }

uint64_t Construct_TXT_83498F50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F50_G_ = int32_t(0x83498F50);
	constexpr int32_t str_TXT_820C230C_B_ = int32_t(0x820C230C);
	constexpr int32_t Destroy_TXT_83498F50_G__address = int32_t(0x832A42F0);
	if (!UseLiftedCode(143, 0x832584C8)) { __imp__sub_832584C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832584C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F50_G_, str_TXT_820C230C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F50_G__address);
}
PROMOTED_ENTRY(143, sub_832584C8, 0x832584C8) { ctx.r3.u64 = Construct_TXT_83498F50_G_(ctx, base); }

uint64_t Construct_TXT_83498F54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F54_G_ = int32_t(0x83498F54);
	constexpr int32_t str_TXT_820C2328_B_ = int32_t(0x820C2328);
	constexpr int32_t Destroy_TXT_83498F54_G__address = int32_t(0x832A4300);
	if (!UseLiftedCode(143, 0x83258508)) { __imp__sub_83258508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F54_G_, str_TXT_820C2328_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F54_G__address);
}
PROMOTED_ENTRY(143, sub_83258508, 0x83258508) { ctx.r3.u64 = Construct_TXT_83498F54_G_(ctx, base); }

uint64_t Construct_TXT_83498F58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F58_G_ = int32_t(0x83498F58);
	constexpr int32_t str_TXT_820C312C_B_ = int32_t(0x820C312C);
	constexpr int32_t Destroy_TXT_83498F58_G__address = int32_t(0x832A4320);
	if (!UseLiftedCode(143, 0x83258548)) { __imp__sub_83258548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F58_G_, str_TXT_820C312C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F58_G__address);
}
PROMOTED_ENTRY(143, sub_83258548, 0x83258548) { ctx.r3.u64 = Construct_TXT_83498F58_G_(ctx, base); }

uint64_t Construct_TXT_83498F5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F5C_G_ = int32_t(0x83498F5C);
	constexpr int32_t str_TXT_820C35F0_B_ = int32_t(0x820C35F0);
	constexpr int32_t Destroy_TXT_83498F5C_G__address = int32_t(0x832A4330);
	if (!UseLiftedCode(143, 0x83258588)) { __imp__sub_83258588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F5C_G_, str_TXT_820C35F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F5C_G__address);
}
PROMOTED_ENTRY(143, sub_83258588, 0x83258588) { ctx.r3.u64 = Construct_TXT_83498F5C_G_(ctx, base); }

uint64_t Construct_TXT_83498F60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F60_G_ = int32_t(0x83498F60);
	constexpr int32_t str_TXT_820C35F8_B_ = int32_t(0x820C35F8);
	constexpr int32_t Destroy_TXT_83498F60_G__address = int32_t(0x832A4340);
	if (!UseLiftedCode(143, 0x832585C8)) { __imp__sub_832585C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832585C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F60_G_, str_TXT_820C35F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F60_G__address);
}
PROMOTED_ENTRY(143, sub_832585C8, 0x832585C8) { ctx.r3.u64 = Construct_TXT_83498F60_G_(ctx, base); }

uint64_t Construct_TXT_83498F64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F64_G_ = int32_t(0x83498F64);
	constexpr int32_t str_TXT_820C3608_B_ = int32_t(0x820C3608);
	constexpr int32_t Destroy_TXT_83498F64_G__address = int32_t(0x832A4350);
	if (!UseLiftedCode(143, 0x83258608)) { __imp__sub_83258608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F64_G_, str_TXT_820C3608_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F64_G__address);
}
PROMOTED_ENTRY(143, sub_83258608, 0x83258608) { ctx.r3.u64 = Construct_TXT_83498F64_G_(ctx, base); }

uint64_t Construct_TXT_83498F74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F74_G_ = int32_t(0x83498F74);
	constexpr int32_t str_TXT_820C5744_B_ = int32_t(0x820C5744);
	constexpr int32_t Destroy_TXT_83498F74_G__address = int32_t(0x832A4370);
	if (!UseLiftedCode(143, 0x832586D8)) { __imp__sub_832586D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832586D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F74_G_, str_TXT_820C5744_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F74_G__address);
}
PROMOTED_ENTRY(143, sub_832586D8, 0x832586D8) { ctx.r3.u64 = Construct_TXT_83498F74_G_(ctx, base); }

uint64_t Construct_TXT_83498F78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F78_G_ = int32_t(0x83498F78);
	constexpr int32_t str_TXT_820C574C_B_ = int32_t(0x820C574C);
	constexpr int32_t Destroy_TXT_83498F78_G__address = int32_t(0x832A4380);
	if (!UseLiftedCode(143, 0x83258718)) { __imp__sub_83258718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258718);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F78_G_, str_TXT_820C574C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F78_G__address);
}
PROMOTED_ENTRY(143, sub_83258718, 0x83258718) { ctx.r3.u64 = Construct_TXT_83498F78_G_(ctx, base); }

uint64_t Construct_TXT_83498F7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F7C_G_ = int32_t(0x83498F7C);
	constexpr int32_t str_TXT_820C5754_B_ = int32_t(0x820C5754);
	constexpr int32_t Destroy_TXT_83498F7C_G__address = int32_t(0x832A4390);
	if (!UseLiftedCode(143, 0x83258758)) { __imp__sub_83258758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F7C_G_, str_TXT_820C5754_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F7C_G__address);
}
PROMOTED_ENTRY(143, sub_83258758, 0x83258758) { ctx.r3.u64 = Construct_TXT_83498F7C_G_(ctx, base); }

uint64_t Construct_TXT_83498F80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F80_G_ = int32_t(0x83498F80);
	constexpr int32_t str_TXT_820C575C_B_ = int32_t(0x820C575C);
	constexpr int32_t Destroy_TXT_83498F80_G__address = int32_t(0x832A43A0);
	if (!UseLiftedCode(143, 0x83258798)) { __imp__sub_83258798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F80_G_, str_TXT_820C575C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F80_G__address);
}
PROMOTED_ENTRY(143, sub_83258798, 0x83258798) { ctx.r3.u64 = Construct_TXT_83498F80_G_(ctx, base); }

uint64_t Construct_TXT_83498F84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F84_G_ = int32_t(0x83498F84);
	constexpr int32_t str_TXT_820C5764_B_ = int32_t(0x820C5764);
	constexpr int32_t Destroy_TXT_83498F84_G__address = int32_t(0x832A43B0);
	if (!UseLiftedCode(143, 0x832587D8)) { __imp__sub_832587D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832587D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F84_G_, str_TXT_820C5764_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F84_G__address);
}
PROMOTED_ENTRY(143, sub_832587D8, 0x832587D8) { ctx.r3.u64 = Construct_TXT_83498F84_G_(ctx, base); }

uint64_t Construct_TXT_83498F88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F88_G_ = int32_t(0x83498F88);
	constexpr int32_t str_TXT_820C576C_B_ = int32_t(0x820C576C);
	constexpr int32_t Destroy_TXT_83498F88_G__address = int32_t(0x832A43C0);
	if (!UseLiftedCode(143, 0x83258818)) { __imp__sub_83258818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F88_G_, str_TXT_820C576C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F88_G__address);
}
PROMOTED_ENTRY(143, sub_83258818, 0x83258818) { ctx.r3.u64 = Construct_TXT_83498F88_G_(ctx, base); }

uint64_t Construct_TXT_83498F8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F8C_G_ = int32_t(0x83498F8C);
	constexpr int32_t str_TXT_820C5774_B_ = int32_t(0x820C5774);
	constexpr int32_t Destroy_TXT_83498F8C_G__address = int32_t(0x832A43D0);
	if (!UseLiftedCode(143, 0x83258858)) { __imp__sub_83258858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258858);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F8C_G_, str_TXT_820C5774_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F8C_G__address);
}
PROMOTED_ENTRY(143, sub_83258858, 0x83258858) { ctx.r3.u64 = Construct_TXT_83498F8C_G_(ctx, base); }

uint64_t Construct_TXT_83498F90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F90_G_ = int32_t(0x83498F90);
	constexpr int32_t str_TXT_820C577C_B_ = int32_t(0x820C577C);
	constexpr int32_t Destroy_TXT_83498F90_G__address = int32_t(0x832A43E0);
	if (!UseLiftedCode(143, 0x83258898)) { __imp__sub_83258898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F90_G_, str_TXT_820C577C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F90_G__address);
}
PROMOTED_ENTRY(143, sub_83258898, 0x83258898) { ctx.r3.u64 = Construct_TXT_83498F90_G_(ctx, base); }

uint64_t Construct_TXT_83498F94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F94_G_ = int32_t(0x83498F94);
	constexpr int32_t str_TXT_820C578C_B_ = int32_t(0x820C578C);
	constexpr int32_t Destroy_TXT_83498F94_G__address = int32_t(0x832A43F0);
	if (!UseLiftedCode(143, 0x832588D8)) { __imp__sub_832588D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832588D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F94_G_, str_TXT_820C578C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F94_G__address);
}
PROMOTED_ENTRY(143, sub_832588D8, 0x832588D8) { ctx.r3.u64 = Construct_TXT_83498F94_G_(ctx, base); }

uint64_t Construct_TXT_83498F98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F98_G_ = int32_t(0x83498F98);
	constexpr int32_t str_TXT_820C579C_B_ = int32_t(0x820C579C);
	constexpr int32_t Destroy_TXT_83498F98_G__address = int32_t(0x832A4400);
	if (!UseLiftedCode(143, 0x83258918)) { __imp__sub_83258918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258918);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F98_G_, str_TXT_820C579C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F98_G__address);
}
PROMOTED_ENTRY(143, sub_83258918, 0x83258918) { ctx.r3.u64 = Construct_TXT_83498F98_G_(ctx, base); }

uint64_t Construct_TXT_83498F9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498F9C_G_ = int32_t(0x83498F9C);
	constexpr int32_t str_TXT_820C57A4_B_ = int32_t(0x820C57A4);
	constexpr int32_t Destroy_TXT_83498F9C_G__address = int32_t(0x832A4410);
	if (!UseLiftedCode(143, 0x83258958)) { __imp__sub_83258958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258958);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498F9C_G_, str_TXT_820C57A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498F9C_G__address);
}
PROMOTED_ENTRY(143, sub_83258958, 0x83258958) { ctx.r3.u64 = Construct_TXT_83498F9C_G_(ctx, base); }

uint64_t Construct_TXT_83498FA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FA0_G_ = int32_t(0x83498FA0);
	constexpr int32_t str_TXT_820C57AC_B_ = int32_t(0x820C57AC);
	constexpr int32_t Destroy_TXT_83498FA0_G__address = int32_t(0x832A4420);
	if (!UseLiftedCode(143, 0x83258998)) { __imp__sub_83258998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258998);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA0_G_, str_TXT_820C57AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FA0_G__address);
}
PROMOTED_ENTRY(143, sub_83258998, 0x83258998) { ctx.r3.u64 = Construct_TXT_83498FA0_G_(ctx, base); }

uint64_t Construct_TXT_83498FA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FA4_G_ = int32_t(0x83498FA4);
	constexpr int32_t str_TXT_820C57B8_B_ = int32_t(0x820C57B8);
	constexpr int32_t Destroy_TXT_83498FA4_G__address = int32_t(0x832A4430);
	if (!UseLiftedCode(143, 0x832589D8)) { __imp__sub_832589D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832589D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA4_G_, str_TXT_820C57B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FA4_G__address);
}
PROMOTED_ENTRY(143, sub_832589D8, 0x832589D8) { ctx.r3.u64 = Construct_TXT_83498FA4_G_(ctx, base); }

uint64_t Construct_TXT_83498FA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FA8_G_ = int32_t(0x83498FA8);
	constexpr int32_t str_TXT_820A62B4_B_ = int32_t(0x820A62B4);
	constexpr int32_t Destroy_TXT_83498FA8_G__address = int32_t(0x832A4440);
	if (!UseLiftedCode(143, 0x83258A18)) { __imp__sub_83258A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FA8_G_, str_TXT_820A62B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FA8_G__address);
}
PROMOTED_ENTRY(143, sub_83258A18, 0x83258A18) { ctx.r3.u64 = Construct_TXT_83498FA8_G_(ctx, base); }

uint64_t Construct_TXT_83498FAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FAC_G_ = int32_t(0x83498FAC);
	constexpr int32_t str_TXT_820C57C0_B_ = int32_t(0x820C57C0);
	constexpr int32_t Destroy_TXT_83498FAC_G__address = int32_t(0x832A4450);
	if (!UseLiftedCode(143, 0x83258A58)) { __imp__sub_83258A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FAC_G_, str_TXT_820C57C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FAC_G__address);
}
PROMOTED_ENTRY(143, sub_83258A58, 0x83258A58) { ctx.r3.u64 = Construct_TXT_83498FAC_G_(ctx, base); }

uint64_t Construct_TXT_83498FB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FB0_G_ = int32_t(0x83498FB0);
	constexpr int32_t str_TXT_820A8094_B_ = int32_t(0x820A8094);
	constexpr int32_t Destroy_TXT_83498FB0_G__address = int32_t(0x832A4460);
	if (!UseLiftedCode(143, 0x83258A98)) { __imp__sub_83258A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258A98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB0_G_, str_TXT_820A8094_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FB0_G__address);
}
PROMOTED_ENTRY(143, sub_83258A98, 0x83258A98) { ctx.r3.u64 = Construct_TXT_83498FB0_G_(ctx, base); }

uint64_t Construct_TXT_83498FB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FB4_G_ = int32_t(0x83498FB4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498FB4_G__address = int32_t(0x832A44D8);
	if (!UseLiftedCode(143, 0x83258AD8)) { __imp__sub_83258AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258AD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FB4_G__address);
}
PROMOTED_ENTRY(143, sub_83258AD8, 0x83258AD8) { ctx.r3.u64 = Construct_TXT_83498FB4_G_(ctx, base); }

uint64_t Construct_TXT_83498FB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FB8_G_ = int32_t(0x83498FB8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498FB8_G__address = int32_t(0x832A44E8);
	if (!UseLiftedCode(143, 0x83258B18)) { __imp__sub_83258B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258B18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FB8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FB8_G__address);
}
PROMOTED_ENTRY(143, sub_83258B18, 0x83258B18) { ctx.r3.u64 = Construct_TXT_83498FB8_G_(ctx, base); }

uint64_t Construct_TXT_83498FBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FBC_G_ = int32_t(0x83498FBC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498FBC_G__address = int32_t(0x832A44F8);
	if (!UseLiftedCode(143, 0x83258B58)) { __imp__sub_83258B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258B58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FBC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FBC_G__address);
}
PROMOTED_ENTRY(143, sub_83258B58, 0x83258B58) { ctx.r3.u64 = Construct_TXT_83498FBC_G_(ctx, base); }

uint64_t Construct_TXT_83498FDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FDC_G_ = int32_t(0x83498FDC);
	constexpr int32_t str_TXT_820C6648_B_ = int32_t(0x820C6648);
	constexpr int32_t Destroy_TXT_83498FDC_G__address = int32_t(0x832A4580);
	if (!UseLiftedCode(143, 0x83258C50)) { __imp__sub_83258C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258C50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FDC_G_, str_TXT_820C6648_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FDC_G__address);
}
PROMOTED_ENTRY(143, sub_83258C50, 0x83258C50) { ctx.r3.u64 = Construct_TXT_83498FDC_G_(ctx, base); }

uint64_t Construct_TXT_83498FE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FE0_G_ = int32_t(0x83498FE0);
	constexpr int32_t str_TXT_820C6660_B_ = int32_t(0x820C6660);
	constexpr int32_t Destroy_TXT_83498FE0_G__address = int32_t(0x832A4590);
	if (!UseLiftedCode(143, 0x83258C90)) { __imp__sub_83258C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258C90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FE0_G_, str_TXT_820C6660_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FE0_G__address);
}
PROMOTED_ENTRY(143, sub_83258C90, 0x83258C90) { ctx.r3.u64 = Construct_TXT_83498FE0_G_(ctx, base); }

uint64_t Construct_TXT_83498FE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FE4_G_ = int32_t(0x83498FE4);
	constexpr int32_t str_TXT_820C6674_B_ = int32_t(0x820C6674);
	constexpr int32_t Destroy_TXT_83498FE4_G__address = int32_t(0x832A45A0);
	if (!UseLiftedCode(143, 0x83258CD0)) { __imp__sub_83258CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FE4_G_, str_TXT_820C6674_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FE4_G__address);
}
PROMOTED_ENTRY(143, sub_83258CD0, 0x83258CD0) { ctx.r3.u64 = Construct_TXT_83498FE4_G_(ctx, base); }

uint64_t n_sub_83258D10(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A45B0_address = int32_t(0x832A45B0);
	if (!UseLiftedCode(143, 0x83258D10)) { ctx.r8.u64 = exitContext; __imp__sub_83258D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D10);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A45B0_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83258D10, 0x83258D10) { ctx.r3.u64 = n_sub_83258D10(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83498FF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FF0_G_ = int32_t(0x83498FF0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498FF0_G__address = int32_t(0x832A45C0);
	if (!UseLiftedCode(143, 0x83258D20)) { __imp__sub_83258D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FF0_G__address);
}
PROMOTED_ENTRY(143, sub_83258D20, 0x83258D20) { ctx.r3.u64 = Construct_TXT_83498FF0_G_(ctx, base); }

uint64_t Construct_TXT_83498FF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FF4_G_ = int32_t(0x83498FF4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498FF4_G__address = int32_t(0x832A45D0);
	if (!UseLiftedCode(143, 0x83258D60)) { __imp__sub_83258D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FF4_G__address);
}
PROMOTED_ENTRY(143, sub_83258D60, 0x83258D60) { ctx.r3.u64 = Construct_TXT_83498FF4_G_(ctx, base); }

uint64_t Construct_TXT_83498FF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FF8_G_ = int32_t(0x83498FF8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498FF8_G__address = int32_t(0x832A45E0);
	if (!UseLiftedCode(143, 0x83258DA0)) { __imp__sub_83258DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258DA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FF8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FF8_G__address);
}
PROMOTED_ENTRY(143, sub_83258DA0, 0x83258DA0) { ctx.r3.u64 = Construct_TXT_83498FF8_G_(ctx, base); }

uint64_t Construct_TXT_83498FFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498FFC_G_ = int32_t(0x83498FFC);
	constexpr int32_t str_TXT_820C6B78_B_ = int32_t(0x820C6B78);
	constexpr int32_t Destroy_TXT_83498FFC_G__address = int32_t(0x832A45F0);
	if (!UseLiftedCode(143, 0x83258DE0)) { __imp__sub_83258DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258DE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498FFC_G_, str_TXT_820C6B78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498FFC_G__address);
}
PROMOTED_ENTRY(143, sub_83258DE0, 0x83258DE0) { ctx.r3.u64 = Construct_TXT_83498FFC_G_(ctx, base); }

uint64_t Construct_TXT_83499000_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83499000_G_ = int32_t(0x83499000);
	constexpr int32_t str_TXT_820C71B4_B_ = int32_t(0x820C71B4);
	constexpr int32_t Destroy_TXT_83499000_G__address = int32_t(0x832A4600);
	if (!UseLiftedCode(143, 0x83258E20)) { __imp__sub_83258E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258E20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83499000_G_, str_TXT_820C71B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83499000_G__address);
}
PROMOTED_ENTRY(143, sub_83258E20, 0x83258E20) { ctx.r3.u64 = Construct_TXT_83499000_G_(ctx, base); }

uint64_t n_sub_83258E60(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4610_address = int32_t(0x832A4610);
	if (!UseLiftedCode(143, 0x83258E60)) { ctx.r8.u64 = exitContext; __imp__sub_83258E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258E60);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4610_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83258E60, 0x83258E60) { ctx.r3.u64 = n_sub_83258E60(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349AA40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA40_G_ = int32_t(0x8349AA40);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349AA40_G__address = int32_t(0x832A4A48);
	if (!UseLiftedCode(143, 0x83259960)) { __imp__sub_83259960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259960);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA40_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA40_G__address);
}
PROMOTED_ENTRY(143, sub_83259960, 0x83259960) { ctx.r3.u64 = Construct_TXT_8349AA40_G_(ctx, base); }

uint64_t Construct_TXT_8349AA44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA44_G_ = int32_t(0x8349AA44);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349AA44_G__address = int32_t(0x832A4A58);
	if (!UseLiftedCode(143, 0x832599A0)) { __imp__sub_832599A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832599A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA44_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA44_G__address);
}
PROMOTED_ENTRY(143, sub_832599A0, 0x832599A0) { ctx.r3.u64 = Construct_TXT_8349AA44_G_(ctx, base); }

uint64_t Construct_TXT_8349AA48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA48_G_ = int32_t(0x8349AA48);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349AA48_G__address = int32_t(0x832A4A68);
	if (!UseLiftedCode(143, 0x832599E0)) { __imp__sub_832599E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832599E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA48_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA48_G__address);
}
PROMOTED_ENTRY(143, sub_832599E0, 0x832599E0) { ctx.r3.u64 = Construct_TXT_8349AA48_G_(ctx, base); }

uint64_t Construct_TXT_8349AA4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA4C_G_ = int32_t(0x8349AA4C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349AA4C_G__address = int32_t(0x832A4A78);
	if (!UseLiftedCode(143, 0x83259A20)) { __imp__sub_83259A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259A20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA4C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA4C_G__address);
}
PROMOTED_ENTRY(143, sub_83259A20, 0x83259A20) { ctx.r3.u64 = Construct_TXT_8349AA4C_G_(ctx, base); }

uint64_t Construct_TXT_8349AA50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA50_G_ = int32_t(0x8349AA50);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349AA50_G__address = int32_t(0x832A4A88);
	if (!UseLiftedCode(143, 0x83259A60)) { __imp__sub_83259A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259A60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA50_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA50_G__address);
}
PROMOTED_ENTRY(143, sub_83259A60, 0x83259A60) { ctx.r3.u64 = Construct_TXT_8349AA50_G_(ctx, base); }

uint64_t Construct_TXT_8349AA54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AA54_G_ = int32_t(0x8349AA54);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349AA54_G__address = int32_t(0x832A4A98);
	if (!UseLiftedCode(143, 0x83259AA0)) { __imp__sub_83259AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AA54_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AA54_G__address);
}
PROMOTED_ENTRY(143, sub_83259AA0, 0x83259AA0) { ctx.r3.u64 = Construct_TXT_8349AA54_G_(ctx, base); }

uint64_t n_sub_83259B38(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4AF8_address = int32_t(0x832A4AF8);
	if (!UseLiftedCode(143, 0x83259B38)) { ctx.r8.u64 = exitContext; __imp__sub_83259B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B38);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4AF8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83259B38, 0x83259B38) { ctx.r3.u64 = n_sub_83259B38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83259B60(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4B08_address = int32_t(0x832A4B08);
	if (!UseLiftedCode(143, 0x83259B60)) { ctx.r8.u64 = exitContext; __imp__sub_83259B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B60);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4B08_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83259B60, 0x83259B60) { ctx.r3.u64 = n_sub_83259B60(ctx, base, ctx.r8.u64); }

// sub_83259BD0  [64 bytes]
uint64_t n_sub_83259BD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD2C_G_ = int32_t(0x8349AD2C);
	constexpr int32_t str_TXT_820C9AF8_B_ = int32_t(0x820C9AF8);
	constexpr int32_t Destroy_TXT_8349AD2C_G__address = int32_t(0x832A4BA8);
	if (!UseLiftedCode(143, 0x83259BD0)) { __imp__sub_83259BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259BD0);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD2C_G_, str_TXT_820C9AF8_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349AD2C_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259BD0, 0x83259BD0) { ctx.r3.u64 = n_sub_83259BD0(ctx, base); }

uint64_t Construct_TXT_8349AD5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD5C_G_ = int32_t(0x8349AD5C);
	constexpr int32_t str_TXT_820C9E38_B_ = int32_t(0x820C9E38);
	constexpr int32_t Destroy_TXT_8349AD5C_G__address = int32_t(0x832A4BC8);
	if (!UseLiftedCode(143, 0x83259C88)) { __imp__sub_83259C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259C88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD5C_G_, str_TXT_820C9E38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD5C_G__address);
}
PROMOTED_ENTRY(143, sub_83259C88, 0x83259C88) { ctx.r3.u64 = Construct_TXT_8349AD5C_G_(ctx, base); }

uint64_t Construct_TXT_8349AD80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD80_G_ = int32_t(0x8349AD80);
	constexpr int32_t str_TXT_820C9E44_B_ = int32_t(0x820C9E44);
	constexpr int32_t Destroy_TXT_8349AD80_G__address = int32_t(0x832A4BD8);
	if (!UseLiftedCode(143, 0x83259CC8)) { __imp__sub_83259CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD80_G_, str_TXT_820C9E44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD80_G__address);
}
PROMOTED_ENTRY(143, sub_83259CC8, 0x83259CC8) { ctx.r3.u64 = Construct_TXT_8349AD80_G_(ctx, base); }

uint64_t Construct_TXT_8349AD84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD84_G_ = int32_t(0x8349AD84);
	constexpr int32_t str_TXT_820C9E4C_B_ = int32_t(0x820C9E4C);
	constexpr int32_t Destroy_TXT_8349AD84_G__address = int32_t(0x832A4BE8);
	if (!UseLiftedCode(143, 0x83259D08)) { __imp__sub_83259D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD84_G_, str_TXT_820C9E4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD84_G__address);
}
PROMOTED_ENTRY(143, sub_83259D08, 0x83259D08) { ctx.r3.u64 = Construct_TXT_8349AD84_G_(ctx, base); }

uint64_t Construct_TXT_8349AD88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD88_G_ = int32_t(0x8349AD88);
	constexpr int32_t str_TXT_820C9E54_B_ = int32_t(0x820C9E54);
	constexpr int32_t Destroy_TXT_8349AD88_G__address = int32_t(0x832A4BF8);
	if (!UseLiftedCode(143, 0x83259D48)) { __imp__sub_83259D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD88_G_, str_TXT_820C9E54_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD88_G__address);
}
PROMOTED_ENTRY(143, sub_83259D48, 0x83259D48) { ctx.r3.u64 = Construct_TXT_8349AD88_G_(ctx, base); }

uint64_t Construct_TXT_8349AD8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD8C_G_ = int32_t(0x8349AD8C);
	constexpr int32_t str_TXT_820C9E64_B_ = int32_t(0x820C9E64);
	constexpr int32_t Destroy_TXT_8349AD8C_G__address = int32_t(0x832A4C08);
	if (!UseLiftedCode(143, 0x83259D88)) { __imp__sub_83259D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD8C_G_, str_TXT_820C9E64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD8C_G__address);
}
PROMOTED_ENTRY(143, sub_83259D88, 0x83259D88) { ctx.r3.u64 = Construct_TXT_8349AD8C_G_(ctx, base); }

uint64_t Construct_TXT_8349AD90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD90_G_ = int32_t(0x8349AD90);
	constexpr int32_t str_TXT_820C9E78_B_ = int32_t(0x820C9E78);
	constexpr int32_t Destroy_TXT_8349AD90_G__address = int32_t(0x832A4C18);
	if (!UseLiftedCode(143, 0x83259DC8)) { __imp__sub_83259DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD90_G_, str_TXT_820C9E78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD90_G__address);
}
PROMOTED_ENTRY(143, sub_83259DC8, 0x83259DC8) { ctx.r3.u64 = Construct_TXT_8349AD90_G_(ctx, base); }

uint64_t Construct_TXT_8349AD94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD94_G_ = int32_t(0x8349AD94);
	constexpr int32_t str_TXT_820C9E8C_B_ = int32_t(0x820C9E8C);
	constexpr int32_t Destroy_TXT_8349AD94_G__address = int32_t(0x832A4C28);
	if (!UseLiftedCode(143, 0x83259E08)) { __imp__sub_83259E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD94_G_, str_TXT_820C9E8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD94_G__address);
}
PROMOTED_ENTRY(143, sub_83259E08, 0x83259E08) { ctx.r3.u64 = Construct_TXT_8349AD94_G_(ctx, base); }

uint64_t Construct_TXT_8349AD98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD98_G_ = int32_t(0x8349AD98);
	constexpr int32_t str_TXT_820C9EA0_B_ = int32_t(0x820C9EA0);
	constexpr int32_t Destroy_TXT_8349AD98_G__address = int32_t(0x832A4C38);
	if (!UseLiftedCode(143, 0x83259E48)) { __imp__sub_83259E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD98_G_, str_TXT_820C9EA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AD98_G__address);
}
PROMOTED_ENTRY(143, sub_83259E48, 0x83259E48) { ctx.r3.u64 = Construct_TXT_8349AD98_G_(ctx, base); }

uint64_t n_sub_8325A098(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4CC0_address = int32_t(0x832A4CC0);
	if (!UseLiftedCode(143, 0x8325A098)) { ctx.r8.u64 = exitContext; __imp__sub_8325A098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A098);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4CC0_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A098, 0x8325A098) { ctx.r3.u64 = n_sub_8325A098(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349ADDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349ADDC_G_ = int32_t(0x8349ADDC);
	constexpr int32_t str_TXT_820C9AF8_B_ = int32_t(0x820C9AF8);
	constexpr int32_t Destroy_TXT_8349ADDC_G__address = int32_t(0x832A4DA8);
	if (!UseLiftedCode(143, 0x8325A180)) { __imp__sub_8325A180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A180);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349ADDC_G_, str_TXT_820C9AF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349ADDC_G__address);
}
PROMOTED_ENTRY(143, sub_8325A180, 0x8325A180) { ctx.r3.u64 = Construct_TXT_8349ADDC_G_(ctx, base); }

uint64_t n_sub_8325A1C0(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4DB8_address = int32_t(0x832A4DB8);
	if (!UseLiftedCode(143, 0x8325A1C0)) { ctx.r8.u64 = exitContext; __imp__sub_8325A1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A1C0);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4DB8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A1C0, 0x8325A1C0) { ctx.r3.u64 = n_sub_8325A1C0(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349AE18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE18_G_ = int32_t(0x8349AE18);
	constexpr int32_t str_TXT_820C56F8_B_ = int32_t(0x820C56F8);
	constexpr int32_t Destroy_TXT_8349AE18_G__address = int32_t(0x832A4DC8);
	if (!UseLiftedCode(143, 0x8325A1D0)) { __imp__sub_8325A1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A1D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE18_G_, str_TXT_820C56F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE18_G__address);
}
PROMOTED_ENTRY(143, sub_8325A1D0, 0x8325A1D0) { ctx.r3.u64 = Construct_TXT_8349AE18_G_(ctx, base); }

uint64_t n_sub_8325A210(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4DD8_address = int32_t(0x832A4DD8);
	if (!UseLiftedCode(143, 0x8325A210)) { ctx.r8.u64 = exitContext; __imp__sub_8325A210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A210);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4DD8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A210, 0x8325A210) { ctx.r3.u64 = n_sub_8325A210(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A220(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4E40_address = int32_t(0x832A4E40);
	if (!UseLiftedCode(143, 0x8325A220)) { ctx.r8.u64 = exitContext; __imp__sub_8325A220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A220);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4E40_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A220, 0x8325A220) { ctx.r3.u64 = n_sub_8325A220(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349AE3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE3C_G_ = int32_t(0x8349AE3C);
	constexpr int32_t str_TXT_820CA7C8_B_ = int32_t(0x820CA7C8);
	constexpr int32_t Destroy_TXT_8349AE3C_G__address = int32_t(0x832A4EA8);
	if (!UseLiftedCode(143, 0x8325A230)) { __imp__sub_8325A230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE3C_G_, str_TXT_820CA7C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE3C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A230, 0x8325A230) { ctx.r3.u64 = Construct_TXT_8349AE3C_G_(ctx, base); }

uint64_t Construct_TXT_8349AE40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE40_G_ = int32_t(0x8349AE40);
	constexpr int32_t str_TXT_820CAB5C_B_ = int32_t(0x820CAB5C);
	constexpr int32_t Destroy_TXT_8349AE40_G__address = int32_t(0x832A4EB8);
	if (!UseLiftedCode(143, 0x8325A270)) { __imp__sub_8325A270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A270);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE40_G_, str_TXT_820CAB5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE40_G__address);
}
PROMOTED_ENTRY(143, sub_8325A270, 0x8325A270) { ctx.r3.u64 = Construct_TXT_8349AE40_G_(ctx, base); }

uint64_t Construct_TXT_8349AE44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE44_G_ = int32_t(0x8349AE44);
	constexpr int32_t str_TXT_820A8094_B_ = int32_t(0x820A8094);
	constexpr int32_t Destroy_TXT_8349AE44_G__address = int32_t(0x832A4EC8);
	if (!UseLiftedCode(143, 0x8325A2B0)) { __imp__sub_8325A2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A2B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE44_G_, str_TXT_820A8094_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE44_G__address);
}
PROMOTED_ENTRY(143, sub_8325A2B0, 0x8325A2B0) { ctx.r3.u64 = Construct_TXT_8349AE44_G_(ctx, base); }

uint64_t Construct_TXT_8349AE48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE48_G_ = int32_t(0x8349AE48);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349AE48_G__address = int32_t(0x832A4ED8);
	if (!UseLiftedCode(143, 0x8325A2F0)) { __imp__sub_8325A2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A2F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE48_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE48_G__address);
}
PROMOTED_ENTRY(143, sub_8325A2F0, 0x8325A2F0) { ctx.r3.u64 = Construct_TXT_8349AE48_G_(ctx, base); }

uint64_t Construct_TXT_8349AE4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE4C_G_ = int32_t(0x8349AE4C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349AE4C_G__address = int32_t(0x832A4EE8);
	if (!UseLiftedCode(143, 0x8325A330)) { __imp__sub_8325A330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A330);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE4C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE4C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A330, 0x8325A330) { ctx.r3.u64 = Construct_TXT_8349AE4C_G_(ctx, base); }

uint64_t Construct_TXT_8349AE50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE50_G_ = int32_t(0x8349AE50);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349AE50_G__address = int32_t(0x832A4EF8);
	if (!UseLiftedCode(143, 0x8325A370)) { __imp__sub_8325A370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A370);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE50_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE50_G__address);
}
PROMOTED_ENTRY(143, sub_8325A370, 0x8325A370) { ctx.r3.u64 = Construct_TXT_8349AE50_G_(ctx, base); }

uint64_t n_sub_8325A3B0(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4F08_address = int32_t(0x832A4F08);
	if (!UseLiftedCode(143, 0x8325A3B0)) { ctx.r8.u64 = exitContext; __imp__sub_8325A3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A3B0);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A4F08_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A3B0, 0x8325A3B0) { ctx.r3.u64 = n_sub_8325A3B0(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349AE68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE68_G_ = int32_t(0x8349AE68);
	constexpr int32_t str_TXT_820CB90C_B_ = int32_t(0x820CB90C);
	constexpr int32_t Destroy_TXT_8349AE68_G__address = int32_t(0x832A4F70);
	if (!UseLiftedCode(143, 0x8325A3C0)) { __imp__sub_8325A3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A3C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE68_G_, str_TXT_820CB90C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE68_G__address);
}
PROMOTED_ENTRY(143, sub_8325A3C0, 0x8325A3C0) { ctx.r3.u64 = Construct_TXT_8349AE68_G_(ctx, base); }

uint64_t Construct_TXT_8349AE6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE6C_G_ = int32_t(0x8349AE6C);
	constexpr int32_t str_TXT_82000E18_B_ = int32_t(0x82000E18);
	constexpr int32_t Destroy_TXT_8349AE6C_G__address = int32_t(0x832A4F80);
	if (!UseLiftedCode(143, 0x8325A400)) { __imp__sub_8325A400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A400);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE6C_G_, str_TXT_82000E18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE6C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A400, 0x8325A400) { ctx.r3.u64 = Construct_TXT_8349AE6C_G_(ctx, base); }

uint64_t Construct_TXT_8349AE70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE70_G_ = int32_t(0x8349AE70);
	constexpr int32_t str_TXT_820CB920_B_ = int32_t(0x820CB920);
	constexpr int32_t Destroy_TXT_8349AE70_G__address = int32_t(0x832A4F90);
	if (!UseLiftedCode(143, 0x8325A440)) { __imp__sub_8325A440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A440);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE70_G_, str_TXT_820CB920_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE70_G__address);
}
PROMOTED_ENTRY(143, sub_8325A440, 0x8325A440) { ctx.r3.u64 = Construct_TXT_8349AE70_G_(ctx, base); }

uint64_t Construct_TXT_8349AE74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE74_G_ = int32_t(0x8349AE74);
	constexpr int32_t str_TXT_820CB944_B_ = int32_t(0x820CB944);
	constexpr int32_t Destroy_TXT_8349AE74_G__address = int32_t(0x832A4FA0);
	if (!UseLiftedCode(143, 0x8325A480)) { __imp__sub_8325A480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A480);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE74_G_, str_TXT_820CB944_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE74_G__address);
}
PROMOTED_ENTRY(143, sub_8325A480, 0x8325A480) { ctx.r3.u64 = Construct_TXT_8349AE74_G_(ctx, base); }

uint64_t Construct_TXT_8349AE78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE78_G_ = int32_t(0x8349AE78);
	constexpr int32_t str_TXT_820CB964_B_ = int32_t(0x820CB964);
	constexpr int32_t Destroy_TXT_8349AE78_G__address = int32_t(0x832A4FB0);
	if (!UseLiftedCode(143, 0x8325A4C0)) { __imp__sub_8325A4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A4C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE78_G_, str_TXT_820CB964_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE78_G__address);
}
PROMOTED_ENTRY(143, sub_8325A4C0, 0x8325A4C0) { ctx.r3.u64 = Construct_TXT_8349AE78_G_(ctx, base); }

uint64_t Construct_TXT_8349AE7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE7C_G_ = int32_t(0x8349AE7C);
	constexpr int32_t str_TXT_820CB99C_B_ = int32_t(0x820CB99C);
	constexpr int32_t Destroy_TXT_8349AE7C_G__address = int32_t(0x832A4FC0);
	if (!UseLiftedCode(143, 0x8325A500)) { __imp__sub_8325A500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A500);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE7C_G_, str_TXT_820CB99C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE7C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A500, 0x8325A500) { ctx.r3.u64 = Construct_TXT_8349AE7C_G_(ctx, base); }

uint64_t Construct_TXT_8349AE80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE80_G_ = int32_t(0x8349AE80);
	constexpr int32_t str_TXT_820CB9C0_B_ = int32_t(0x820CB9C0);
	constexpr int32_t Destroy_TXT_8349AE80_G__address = int32_t(0x832A4FD0);
	if (!UseLiftedCode(143, 0x8325A540)) { __imp__sub_8325A540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A540);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE80_G_, str_TXT_820CB9C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE80_G__address);
}
PROMOTED_ENTRY(143, sub_8325A540, 0x8325A540) { ctx.r3.u64 = Construct_TXT_8349AE80_G_(ctx, base); }

uint64_t Construct_TXT_8349AE84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE84_G_ = int32_t(0x8349AE84);
	constexpr int32_t str_TXT_820CB9F0_B_ = int32_t(0x820CB9F0);
	constexpr int32_t Destroy_TXT_8349AE84_G__address = int32_t(0x832A4FE0);
	if (!UseLiftedCode(143, 0x8325A580)) { __imp__sub_8325A580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A580);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE84_G_, str_TXT_820CB9F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE84_G__address);
}
PROMOTED_ENTRY(143, sub_8325A580, 0x8325A580) { ctx.r3.u64 = Construct_TXT_8349AE84_G_(ctx, base); }

uint64_t Construct_TXT_8349AE88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE88_G_ = int32_t(0x8349AE88);
	constexpr int32_t str_TXT_820CBA20_B_ = int32_t(0x820CBA20);
	constexpr int32_t Destroy_TXT_8349AE88_G__address = int32_t(0x832A4FF0);
	if (!UseLiftedCode(143, 0x8325A5C0)) { __imp__sub_8325A5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A5C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE88_G_, str_TXT_820CBA20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE88_G__address);
}
PROMOTED_ENTRY(143, sub_8325A5C0, 0x8325A5C0) { ctx.r3.u64 = Construct_TXT_8349AE88_G_(ctx, base); }

uint64_t Construct_TXT_8349AE8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE8C_G_ = int32_t(0x8349AE8C);
	constexpr int32_t str_TXT_820CBA44_B_ = int32_t(0x820CBA44);
	constexpr int32_t Destroy_TXT_8349AE8C_G__address = int32_t(0x832A5000);
	if (!UseLiftedCode(143, 0x8325A600)) { __imp__sub_8325A600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A600);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE8C_G_, str_TXT_820CBA44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE8C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A600, 0x8325A600) { ctx.r3.u64 = Construct_TXT_8349AE8C_G_(ctx, base); }

uint64_t Construct_TXT_8349AE90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE90_G_ = int32_t(0x8349AE90);
	constexpr int32_t str_TXT_820CBA70_B_ = int32_t(0x820CBA70);
	constexpr int32_t Destroy_TXT_8349AE90_G__address = int32_t(0x832A5010);
	if (!UseLiftedCode(143, 0x8325A640)) { __imp__sub_8325A640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A640);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE90_G_, str_TXT_820CBA70_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE90_G__address);
}
PROMOTED_ENTRY(143, sub_8325A640, 0x8325A640) { ctx.r3.u64 = Construct_TXT_8349AE90_G_(ctx, base); }

uint64_t Construct_TXT_8349AE94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE94_G_ = int32_t(0x8349AE94);
	constexpr int32_t str_TXT_820CBAB0_B_ = int32_t(0x820CBAB0);
	constexpr int32_t Destroy_TXT_8349AE94_G__address = int32_t(0x832A5020);
	if (!UseLiftedCode(143, 0x8325A680)) { __imp__sub_8325A680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A680);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE94_G_, str_TXT_820CBAB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE94_G__address);
}
PROMOTED_ENTRY(143, sub_8325A680, 0x8325A680) { ctx.r3.u64 = Construct_TXT_8349AE94_G_(ctx, base); }

uint64_t Construct_TXT_8349AE98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE98_G_ = int32_t(0x8349AE98);
	constexpr int32_t str_TXT_820A8DDC_B_ = int32_t(0x820A8DDC);
	constexpr int32_t Destroy_TXT_8349AE98_G__address = int32_t(0x832A5030);
	if (!UseLiftedCode(143, 0x8325A6C0)) { __imp__sub_8325A6C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A6C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE98_G_, str_TXT_820A8DDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE98_G__address);
}
PROMOTED_ENTRY(143, sub_8325A6C0, 0x8325A6C0) { ctx.r3.u64 = Construct_TXT_8349AE98_G_(ctx, base); }

uint64_t Construct_TXT_8349AE9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AE9C_G_ = int32_t(0x8349AE9C);
	constexpr int32_t str_TXT_820A8DE8_B_ = int32_t(0x820A8DE8);
	constexpr int32_t Destroy_TXT_8349AE9C_G__address = int32_t(0x832A5040);
	if (!UseLiftedCode(143, 0x8325A700)) { __imp__sub_8325A700(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A700);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AE9C_G_, str_TXT_820A8DE8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AE9C_G__address);
}
PROMOTED_ENTRY(143, sub_8325A700, 0x8325A700) { ctx.r3.u64 = Construct_TXT_8349AE9C_G_(ctx, base); }

uint64_t Construct_TXT_8349AEA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEA0_G_ = int32_t(0x8349AEA0);
	constexpr int32_t str_TXT_820ABFD8_B_ = int32_t(0x820ABFD8);
	constexpr int32_t Destroy_TXT_8349AEA0_G__address = int32_t(0x832A5050);
	if (!UseLiftedCode(143, 0x8325A740)) { __imp__sub_8325A740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A740);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA0_G_, str_TXT_820ABFD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEA0_G__address);
}
PROMOTED_ENTRY(143, sub_8325A740, 0x8325A740) { ctx.r3.u64 = Construct_TXT_8349AEA0_G_(ctx, base); }

uint64_t Construct_TXT_8349AEA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEA4_G_ = int32_t(0x8349AEA4);
	constexpr int32_t str_TXT_820ABFB0_B_ = int32_t(0x820ABFB0);
	constexpr int32_t Destroy_TXT_8349AEA4_G__address = int32_t(0x832A5060);
	if (!UseLiftedCode(143, 0x8325A780)) { __imp__sub_8325A780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A780);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA4_G_, str_TXT_820ABFB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEA4_G__address);
}
PROMOTED_ENTRY(143, sub_8325A780, 0x8325A780) { ctx.r3.u64 = Construct_TXT_8349AEA4_G_(ctx, base); }

uint64_t Construct_TXT_8349AEA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEA8_G_ = int32_t(0x8349AEA8);
	constexpr int32_t str_TXT_820ABFC8_B_ = int32_t(0x820ABFC8);
	constexpr int32_t Destroy_TXT_8349AEA8_G__address = int32_t(0x832A5070);
	if (!UseLiftedCode(143, 0x8325A7C0)) { __imp__sub_8325A7C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A7C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEA8_G_, str_TXT_820ABFC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEA8_G__address);
}
PROMOTED_ENTRY(143, sub_8325A7C0, 0x8325A7C0) { ctx.r3.u64 = Construct_TXT_8349AEA8_G_(ctx, base); }

uint64_t Construct_TXT_8349AEAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEAC_G_ = int32_t(0x8349AEAC);
	constexpr int32_t str_TXT_820CBAEC_B_ = int32_t(0x820CBAEC);
	constexpr int32_t Destroy_TXT_8349AEAC_G__address = int32_t(0x832A5080);
	if (!UseLiftedCode(143, 0x8325A800)) { __imp__sub_8325A800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A800);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEAC_G_, str_TXT_820CBAEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEAC_G__address);
}
PROMOTED_ENTRY(143, sub_8325A800, 0x8325A800) { ctx.r3.u64 = Construct_TXT_8349AEAC_G_(ctx, base); }

uint64_t Construct_TXT_8349AEB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEB0_G_ = int32_t(0x8349AEB0);
	constexpr int32_t str_TXT_820CBAF8_B_ = int32_t(0x820CBAF8);
	constexpr int32_t Destroy_TXT_8349AEB0_G__address = int32_t(0x832A5090);
	if (!UseLiftedCode(143, 0x8325A840)) { __imp__sub_8325A840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A840);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB0_G_, str_TXT_820CBAF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEB0_G__address);
}
PROMOTED_ENTRY(143, sub_8325A840, 0x8325A840) { ctx.r3.u64 = Construct_TXT_8349AEB0_G_(ctx, base); }

uint64_t Construct_TXT_8349AEB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEB4_G_ = int32_t(0x8349AEB4);
	constexpr int32_t str_TXT_820CBB04_B_ = int32_t(0x820CBB04);
	constexpr int32_t Destroy_TXT_8349AEB4_G__address = int32_t(0x832A50A0);
	if (!UseLiftedCode(143, 0x8325A880)) { __imp__sub_8325A880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A880);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB4_G_, str_TXT_820CBB04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEB4_G__address);
}
PROMOTED_ENTRY(143, sub_8325A880, 0x8325A880) { ctx.r3.u64 = Construct_TXT_8349AEB4_G_(ctx, base); }

uint64_t Construct_TXT_8349AEB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEB8_G_ = int32_t(0x8349AEB8);
	constexpr int32_t str_TXT_820CBB10_B_ = int32_t(0x820CBB10);
	constexpr int32_t Destroy_TXT_8349AEB8_G__address = int32_t(0x832A50B0);
	if (!UseLiftedCode(143, 0x8325A8C0)) { __imp__sub_8325A8C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A8C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEB8_G_, str_TXT_820CBB10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEB8_G__address);
}
PROMOTED_ENTRY(143, sub_8325A8C0, 0x8325A8C0) { ctx.r3.u64 = Construct_TXT_8349AEB8_G_(ctx, base); }

uint64_t Construct_TXT_8349AEBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEBC_G_ = int32_t(0x8349AEBC);
	constexpr int32_t str_TXT_820CBB1C_B_ = int32_t(0x820CBB1C);
	constexpr int32_t Destroy_TXT_8349AEBC_G__address = int32_t(0x832A50C0);
	if (!UseLiftedCode(143, 0x8325A900)) { __imp__sub_8325A900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A900);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEBC_G_, str_TXT_820CBB1C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEBC_G__address);
}
PROMOTED_ENTRY(143, sub_8325A900, 0x8325A900) { ctx.r3.u64 = Construct_TXT_8349AEBC_G_(ctx, base); }

uint64_t Construct_TXT_8349AEC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AEC0_G_ = int32_t(0x8349AEC0);
	constexpr int32_t str_TXT_820CBB34_B_ = int32_t(0x820CBB34);
	constexpr int32_t Destroy_TXT_8349AEC0_G__address = int32_t(0x832A50D0);
	if (!UseLiftedCode(143, 0x8325A940)) { __imp__sub_8325A940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A940);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AEC0_G_, str_TXT_820CBB34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AEC0_G__address);
}
PROMOTED_ENTRY(143, sub_8325A940, 0x8325A940) { ctx.r3.u64 = Construct_TXT_8349AEC0_G_(ctx, base); }

uint64_t Construct_TXT_8349AED0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AED0_G_ = int32_t(0x8349AED0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349AED0_G__address = int32_t(0x832A50F0);
	if (!UseLiftedCode(143, 0x8325A9F0)) { __imp__sub_8325A9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AED0_G__address);
}
PROMOTED_ENTRY(143, sub_8325A9F0, 0x8325A9F0) { ctx.r3.u64 = Construct_TXT_8349AED0_G_(ctx, base); }

uint64_t Construct_TXT_8349AED4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AED4_G_ = int32_t(0x8349AED4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349AED4_G__address = int32_t(0x832A5100);
	if (!UseLiftedCode(143, 0x8325AA30)) { __imp__sub_8325AA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AA30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AED4_G__address);
}
PROMOTED_ENTRY(143, sub_8325AA30, 0x8325AA30) { ctx.r3.u64 = Construct_TXT_8349AED4_G_(ctx, base); }

uint64_t Construct_TXT_8349AED8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AED8_G_ = int32_t(0x8349AED8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349AED8_G__address = int32_t(0x832A5110);
	if (!UseLiftedCode(143, 0x8325AA70)) { __imp__sub_8325AA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AA70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AED8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AED8_G__address);
}
PROMOTED_ENTRY(143, sub_8325AA70, 0x8325AA70) { ctx.r3.u64 = Construct_TXT_8349AED8_G_(ctx, base); }

uint64_t Construct_TXT_8349AF98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AF98_G_ = int32_t(0x8349AF98);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349AF98_G__address = int32_t(0x832A5220);
	if (!UseLiftedCode(143, 0x8325ADF0)) { __imp__sub_8325ADF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ADF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AF98_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AF98_G__address);
}
PROMOTED_ENTRY(143, sub_8325ADF0, 0x8325ADF0) { ctx.r3.u64 = Construct_TXT_8349AF98_G_(ctx, base); }

uint64_t Construct_TXT_8349AF9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AF9C_G_ = int32_t(0x8349AF9C);
	constexpr int32_t str_TXT_820CD080_B_ = int32_t(0x820CD080);
	constexpr int32_t Destroy_TXT_8349AF9C_G__address = int32_t(0x832A5230);
	if (!UseLiftedCode(143, 0x8325AE30)) { __imp__sub_8325AE30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AE30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AF9C_G_, str_TXT_820CD080_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AF9C_G__address);
}
PROMOTED_ENTRY(143, sub_8325AE30, 0x8325AE30) { ctx.r3.u64 = Construct_TXT_8349AF9C_G_(ctx, base); }

uint64_t Construct_TXT_8349AFAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AFAC_G_ = int32_t(0x8349AFAC);
	constexpr int32_t str_TXT_820CD0CC_B_ = int32_t(0x820CD0CC);
	constexpr int32_t Destroy_TXT_8349AFAC_G__address = int32_t(0x832A5240);
	if (!UseLiftedCode(143, 0x8325AF18)) { __imp__sub_8325AF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AF18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AFAC_G_, str_TXT_820CD0CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AFAC_G__address);
}
PROMOTED_ENTRY(143, sub_8325AF18, 0x8325AF18) { ctx.r3.u64 = Construct_TXT_8349AFAC_G_(ctx, base); }

uint64_t Construct_TXT_8349AFB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AFB0_G_ = int32_t(0x8349AFB0);
	constexpr int32_t str_TXT_820CD0EC_B_ = int32_t(0x820CD0EC);
	constexpr int32_t Destroy_TXT_8349AFB0_G__address = int32_t(0x832A5250);
	if (!UseLiftedCode(143, 0x8325AF58)) { __imp__sub_8325AF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AF58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AFB0_G_, str_TXT_820CD0EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349AFB0_G__address);
}
PROMOTED_ENTRY(143, sub_8325AF58, 0x8325AF58) { ctx.r3.u64 = Construct_TXT_8349AFB0_G_(ctx, base); }

uint64_t Construct_TXT_8349B038_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B038_G_ = int32_t(0x8349B038);
	constexpr int32_t str_TXT_820CD1A4_B_ = int32_t(0x820CD1A4);
	constexpr int32_t Destroy_TXT_8349B038_G__address = int32_t(0x832A5268);
	if (!UseLiftedCode(143, 0x8325B758)) { __imp__sub_8325B758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B038_G_, str_TXT_820CD1A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B038_G__address);
}
PROMOTED_ENTRY(143, sub_8325B758, 0x8325B758) { ctx.r3.u64 = Construct_TXT_8349B038_G_(ctx, base); }

uint64_t Construct_TXT_8349B03C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B03C_G_ = int32_t(0x8349B03C);
	constexpr int32_t str_TXT_820B45BC_B_ = int32_t(0x820B45BC);
	constexpr int32_t Destroy_TXT_8349B03C_G__address = int32_t(0x832A5278);
	if (!UseLiftedCode(143, 0x8325B798)) { __imp__sub_8325B798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B03C_G_, str_TXT_820B45BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B03C_G__address);
}
PROMOTED_ENTRY(143, sub_8325B798, 0x8325B798) { ctx.r3.u64 = Construct_TXT_8349B03C_G_(ctx, base); }

uint64_t Construct_TXT_8349B040_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B040_G_ = int32_t(0x8349B040);
	constexpr int32_t str_TXT_820B45C8_B_ = int32_t(0x820B45C8);
	constexpr int32_t Destroy_TXT_8349B040_G__address = int32_t(0x832A5288);
	if (!UseLiftedCode(143, 0x8325B7D8)) { __imp__sub_8325B7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B7D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B040_G_, str_TXT_820B45C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B040_G__address);
}
PROMOTED_ENTRY(143, sub_8325B7D8, 0x8325B7D8) { ctx.r3.u64 = Construct_TXT_8349B040_G_(ctx, base); }

uint64_t Construct_TXT_8349B044_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B044_G_ = int32_t(0x8349B044);
	constexpr int32_t str_TXT_820CD0EC_B_ = int32_t(0x820CD0EC);
	constexpr int32_t Destroy_TXT_8349B044_G__address = int32_t(0x832A5298);
	if (!UseLiftedCode(143, 0x8325B818)) { __imp__sub_8325B818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B044_G_, str_TXT_820CD0EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B044_G__address);
}
PROMOTED_ENTRY(143, sub_8325B818, 0x8325B818) { ctx.r3.u64 = Construct_TXT_8349B044_G_(ctx, base); }

uint64_t Construct_TXT_8349B088_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B088_G_ = int32_t(0x8349B088);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t Destroy_TXT_8349B088_G__address = int32_t(0x832A5388);
	if (!UseLiftedCode(143, 0x8325BB68)) { __imp__sub_8325BB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BB68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B088_G_, str_TXT_820BFECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B088_G__address);
}
PROMOTED_ENTRY(143, sub_8325BB68, 0x8325BB68) { ctx.r3.u64 = Construct_TXT_8349B088_G_(ctx, base); }

uint64_t Construct_TXT_8349B08C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B08C_G_ = int32_t(0x8349B08C);
	constexpr int32_t str_TXT_820CD1CC_B_ = int32_t(0x820CD1CC);
	constexpr int32_t Destroy_TXT_8349B08C_G__address = int32_t(0x832A5398);
	if (!UseLiftedCode(143, 0x8325BBA8)) { __imp__sub_8325BBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BBA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B08C_G_, str_TXT_820CD1CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B08C_G__address);
}
PROMOTED_ENTRY(143, sub_8325BBA8, 0x8325BBA8) { ctx.r3.u64 = Construct_TXT_8349B08C_G_(ctx, base); }

uint64_t Construct_TXT_8349B090_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B090_G_ = int32_t(0x8349B090);
	constexpr int32_t str_TXT_820CD1EC_B_ = int32_t(0x820CD1EC);
	constexpr int32_t Destroy_TXT_8349B090_G__address = int32_t(0x832A53A8);
	if (!UseLiftedCode(143, 0x8325BBE8)) { __imp__sub_8325BBE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BBE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B090_G_, str_TXT_820CD1EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B090_G__address);
}
PROMOTED_ENTRY(143, sub_8325BBE8, 0x8325BBE8) { ctx.r3.u64 = Construct_TXT_8349B090_G_(ctx, base); }

uint64_t Construct_TXT_8349B094_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B094_G_ = int32_t(0x8349B094);
	constexpr int32_t str_TXT_820CD1EC_B_ = int32_t(0x820CD210);
	constexpr int32_t Destroy_TXT_8349B094_G__address = int32_t(0x832A53B8);
	if (!UseLiftedCode(143, 0x8325BC28)) { __imp__sub_8325BC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BC28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B094_G_, str_TXT_820CD1EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B094_G__address);
}
PROMOTED_ENTRY(143, sub_8325BC28, 0x8325BC28) { ctx.r3.u64 = Construct_TXT_8349B094_G_(ctx, base); }

uint64_t Construct_TXT_8349B098_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B098_G_ = int32_t(0x8349B098);
	constexpr int32_t str_TXT_820A815C_B_ = int32_t(0x820A815C);
	constexpr int32_t Destroy_TXT_8349B098_G__address = int32_t(0x832A53C8);
	if (!UseLiftedCode(143, 0x8325BC68)) { __imp__sub_8325BC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BC68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B098_G_, str_TXT_820A815C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B098_G__address);
}
PROMOTED_ENTRY(143, sub_8325BC68, 0x8325BC68) { ctx.r3.u64 = Construct_TXT_8349B098_G_(ctx, base); }

uint64_t Construct_TXT_8349B09C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B09C_G_ = int32_t(0x8349B09C);
	constexpr int32_t str_TXT_820CD234_B_ = int32_t(0x820CD234);
	constexpr int32_t Destroy_TXT_8349B09C_G__address = int32_t(0x832A53D8);
	if (!UseLiftedCode(143, 0x8325BCA8)) { __imp__sub_8325BCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BCA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B09C_G_, str_TXT_820CD234_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B09C_G__address);
}
PROMOTED_ENTRY(143, sub_8325BCA8, 0x8325BCA8) { ctx.r3.u64 = Construct_TXT_8349B09C_G_(ctx, base); }

uint64_t Construct_TXT_8349B0A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0A0_G_ = int32_t(0x8349B0A0);
	constexpr int32_t str_TXT_820CD254_B_ = int32_t(0x820CD254);
	constexpr int32_t Destroy_TXT_8349B0A0_G__address = int32_t(0x832A53E8);
	if (!UseLiftedCode(143, 0x8325BCE8)) { __imp__sub_8325BCE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BCE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A0_G_, str_TXT_820CD254_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0A0_G__address);
}
PROMOTED_ENTRY(143, sub_8325BCE8, 0x8325BCE8) { ctx.r3.u64 = Construct_TXT_8349B0A0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0A4_G_ = int32_t(0x8349B0A4);
	constexpr int32_t str_TXT_820CD274_B_ = int32_t(0x820CD274);
	constexpr int32_t Destroy_TXT_8349B0A4_G__address = int32_t(0x832A53F8);
	if (!UseLiftedCode(143, 0x8325BD28)) { __imp__sub_8325BD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BD28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A4_G_, str_TXT_820CD274_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0A4_G__address);
}
PROMOTED_ENTRY(143, sub_8325BD28, 0x8325BD28) { ctx.r3.u64 = Construct_TXT_8349B0A4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0A8_G_ = int32_t(0x8349B0A8);
	constexpr int32_t str_TXT_820CD298_B_ = int32_t(0x820CD298);
	constexpr int32_t Destroy_TXT_8349B0A8_G__address = int32_t(0x832A5408);
	if (!UseLiftedCode(143, 0x8325BD68)) { __imp__sub_8325BD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BD68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0A8_G_, str_TXT_820CD298_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0A8_G__address);
}
PROMOTED_ENTRY(143, sub_8325BD68, 0x8325BD68) { ctx.r3.u64 = Construct_TXT_8349B0A8_G_(ctx, base); }

uint64_t Construct_TXT_8349B0AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0AC_G_ = int32_t(0x8349B0AC);
	constexpr int32_t str_TXT_820B4D6C_B_ = int32_t(0x820B4D6C);
	constexpr int32_t Destroy_TXT_8349B0AC_G__address = int32_t(0x832A5418);
	if (!UseLiftedCode(143, 0x8325BDA8)) { __imp__sub_8325BDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BDA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0AC_G_, str_TXT_820B4D6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0AC_G__address);
}
PROMOTED_ENTRY(143, sub_8325BDA8, 0x8325BDA8) { ctx.r3.u64 = Construct_TXT_8349B0AC_G_(ctx, base); }

uint64_t Construct_TXT_8349B0B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0B0_G_ = int32_t(0x8349B0B0);
	constexpr int32_t str_TXT_820B4C7C_B_ = int32_t(0x820B4C7C);
	constexpr int32_t Destroy_TXT_8349B0B0_G__address = int32_t(0x832A5428);
	if (!UseLiftedCode(143, 0x8325BDE8)) { __imp__sub_8325BDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BDE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B0_G_, str_TXT_820B4C7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0B0_G__address);
}
PROMOTED_ENTRY(143, sub_8325BDE8, 0x8325BDE8) { ctx.r3.u64 = Construct_TXT_8349B0B0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0B4_G_ = int32_t(0x8349B0B4);
	constexpr int32_t str_TXT_820CD2B8_B_ = int32_t(0x820CD2B8);
	constexpr int32_t Destroy_TXT_8349B0B4_G__address = int32_t(0x832A5438);
	if (!UseLiftedCode(143, 0x8325BE28)) { __imp__sub_8325BE28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BE28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B4_G_, str_TXT_820CD2B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0B4_G__address);
}
PROMOTED_ENTRY(143, sub_8325BE28, 0x8325BE28) { ctx.r3.u64 = Construct_TXT_8349B0B4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0B8_G_ = int32_t(0x8349B0B8);
	constexpr int32_t str_TXT_820CD2E0_B_ = int32_t(0x820CD2E0);
	constexpr int32_t Destroy_TXT_8349B0B8_G__address = int32_t(0x832A5448);
	if (!UseLiftedCode(143, 0x8325BE68)) { __imp__sub_8325BE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BE68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0B8_G_, str_TXT_820CD2E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0B8_G__address);
}
PROMOTED_ENTRY(143, sub_8325BE68, 0x8325BE68) { ctx.r3.u64 = Construct_TXT_8349B0B8_G_(ctx, base); }

uint64_t Construct_TXT_8349B0BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0BC_G_ = int32_t(0x8349B0BC);
	constexpr int32_t str_TXT_820CD2F0_B_ = int32_t(0x820CD2F0);
	constexpr int32_t Destroy_TXT_8349B0BC_G__address = int32_t(0x832A5458);
	if (!UseLiftedCode(143, 0x8325BEA8)) { __imp__sub_8325BEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BEA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0BC_G_, str_TXT_820CD2F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0BC_G__address);
}
PROMOTED_ENTRY(143, sub_8325BEA8, 0x8325BEA8) { ctx.r3.u64 = Construct_TXT_8349B0BC_G_(ctx, base); }

uint64_t Construct_TXT_8349B0C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0C0_G_ = int32_t(0x8349B0C0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B0C0_G__address = int32_t(0x832A5468);
	if (!UseLiftedCode(143, 0x8325BEE8)) { __imp__sub_8325BEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BEE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0C0_G__address);
}
PROMOTED_ENTRY(143, sub_8325BEE8, 0x8325BEE8) { ctx.r3.u64 = Construct_TXT_8349B0C0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0C4_G_ = int32_t(0x8349B0C4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B0C4_G__address = int32_t(0x832A5478);
	if (!UseLiftedCode(143, 0x8325BF28)) { __imp__sub_8325BF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BF28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0C4_G__address);
}
PROMOTED_ENTRY(143, sub_8325BF28, 0x8325BF28) { ctx.r3.u64 = Construct_TXT_8349B0C4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0C8_G_ = int32_t(0x8349B0C8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B0C8_G__address = int32_t(0x832A5488);
	if (!UseLiftedCode(143, 0x8325BF68)) { __imp__sub_8325BF68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BF68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0C8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0C8_G__address);
}
PROMOTED_ENTRY(143, sub_8325BF68, 0x8325BF68) { ctx.r3.u64 = Construct_TXT_8349B0C8_G_(ctx, base); }

uint64_t Construct_TXT_8349B0CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0CC_G_ = int32_t(0x8349B0CC);
	constexpr int32_t str_TXT_820CD548_B_ = int32_t(0x820CD548);
	constexpr int32_t Destroy_TXT_8349B0CC_G__address = int32_t(0x832A5498);
	if (!UseLiftedCode(143, 0x8325BFA8)) { __imp__sub_8325BFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BFA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0CC_G_, str_TXT_820CD548_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0CC_G__address);
}
PROMOTED_ENTRY(143, sub_8325BFA8, 0x8325BFA8) { ctx.r3.u64 = Construct_TXT_8349B0CC_G_(ctx, base); }

uint64_t Construct_TXT_8349B0D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0D0_G_ = int32_t(0x8349B0D0);
	constexpr int32_t str_TXT_820CD558_B_ = int32_t(0x820CD558);
	constexpr int32_t Destroy_TXT_8349B0D0_G__address = int32_t(0x832A54A8);
	if (!UseLiftedCode(143, 0x8325BFE8)) { __imp__sub_8325BFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325BFE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D0_G_, str_TXT_820CD558_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0D0_G__address);
}
PROMOTED_ENTRY(143, sub_8325BFE8, 0x8325BFE8) { ctx.r3.u64 = Construct_TXT_8349B0D0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0D4_G_ = int32_t(0x8349B0D4);
	constexpr int32_t str_TXT_820CD0EC_B_ = int32_t(0x820CD0EC);
	constexpr int32_t Destroy_TXT_8349B0D4_G__address = int32_t(0x832A54B8);
	if (!UseLiftedCode(143, 0x8325C028)) { __imp__sub_8325C028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C028);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D4_G_, str_TXT_820CD0EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0D4_G__address);
}
PROMOTED_ENTRY(143, sub_8325C028, 0x8325C028) { ctx.r3.u64 = Construct_TXT_8349B0D4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0D8_G_ = int32_t(0x8349B0D8);
	constexpr int32_t str_TXT_820CD568_B_ = int32_t(0x820CD568);
	constexpr int32_t Destroy_TXT_8349B0D8_G__address = int32_t(0x832A54C8);
	if (!UseLiftedCode(143, 0x8325C068)) { __imp__sub_8325C068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C068);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0D8_G_, str_TXT_820CD568_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0D8_G__address);
}
PROMOTED_ENTRY(143, sub_8325C068, 0x8325C068) { ctx.r3.u64 = Construct_TXT_8349B0D8_G_(ctx, base); }

uint64_t Construct_TXT_8349B0DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0DC_G_ = int32_t(0x8349B0DC);
	constexpr int32_t str_TXT_820CD578_B_ = int32_t(0x820CD578);
	constexpr int32_t Destroy_TXT_8349B0DC_G__address = int32_t(0x832A54D8);
	if (!UseLiftedCode(143, 0x8325C0A8)) { __imp__sub_8325C0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C0A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0DC_G_, str_TXT_820CD578_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0DC_G__address);
}
PROMOTED_ENTRY(143, sub_8325C0A8, 0x8325C0A8) { ctx.r3.u64 = Construct_TXT_8349B0DC_G_(ctx, base); }

uint64_t Construct_TXT_8349B0E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0E0_G_ = int32_t(0x8349B0E0);
	constexpr int32_t str_TXT_820CD590_B_ = int32_t(0x820CD590);
	constexpr int32_t Destroy_TXT_8349B0E0_G__address = int32_t(0x832A54E8);
	if (!UseLiftedCode(143, 0x8325C0E8)) { __imp__sub_8325C0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C0E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0E0_G_, str_TXT_820CD590_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0E0_G__address);
}
PROMOTED_ENTRY(143, sub_8325C0E8, 0x8325C0E8) { ctx.r3.u64 = Construct_TXT_8349B0E0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0E4_G_ = int32_t(0x8349B0E4);
	constexpr int32_t str_TXT_820CD5A4_B_ = int32_t(0x820CD5A4);
	constexpr int32_t Destroy_TXT_8349B0E4_G__address = int32_t(0x832A54F8);
	if (!UseLiftedCode(143, 0x8325C128)) { __imp__sub_8325C128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C128);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0E4_G_, str_TXT_820CD5A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0E4_G__address);
}
PROMOTED_ENTRY(143, sub_8325C128, 0x8325C128) { ctx.r3.u64 = Construct_TXT_8349B0E4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0F0_G_ = int32_t(0x8349B0F0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B0F0_G__address = int32_t(0x832A5518);
	if (!UseLiftedCode(143, 0x8325C2E8)) { __imp__sub_8325C2E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C2E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0F0_G__address);
}
PROMOTED_ENTRY(143, sub_8325C2E8, 0x8325C2E8) { ctx.r3.u64 = Construct_TXT_8349B0F0_G_(ctx, base); }

uint64_t Construct_TXT_8349B0F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0F4_G_ = int32_t(0x8349B0F4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B0F4_G__address = int32_t(0x832A5528);
	if (!UseLiftedCode(143, 0x8325C328)) { __imp__sub_8325C328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C328);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0F4_G__address);
}
PROMOTED_ENTRY(143, sub_8325C328, 0x8325C328) { ctx.r3.u64 = Construct_TXT_8349B0F4_G_(ctx, base); }

uint64_t Construct_TXT_8349B0F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0F8_G_ = int32_t(0x8349B0F8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B0F8_G__address = int32_t(0x832A5538);
	if (!UseLiftedCode(143, 0x8325C368)) { __imp__sub_8325C368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C368);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0F8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0F8_G__address);
}
PROMOTED_ENTRY(143, sub_8325C368, 0x8325C368) { ctx.r3.u64 = Construct_TXT_8349B0F8_G_(ctx, base); }

uint64_t Construct_TXT_8349B0FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B0FC_G_ = int32_t(0x8349B0FC);
	constexpr int32_t str_TXT_820CD8E0_B_ = int32_t(0x820CD8E0);
	constexpr int32_t Destroy_TXT_8349B0FC_G__address = int32_t(0x832A5548);
	if (!UseLiftedCode(143, 0x8325C3A8)) { __imp__sub_8325C3A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C3A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B0FC_G_, str_TXT_820CD8E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B0FC_G__address);
}
PROMOTED_ENTRY(143, sub_8325C3A8, 0x8325C3A8) { ctx.r3.u64 = Construct_TXT_8349B0FC_G_(ctx, base); }

uint64_t Construct_TXT_8349B100_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B100_G_ = int32_t(0x8349B100);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B100_G__address = int32_t(0x832A5558);
	if (!UseLiftedCode(143, 0x8325C3E8)) { __imp__sub_8325C3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C3E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B100_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B100_G__address);
}
PROMOTED_ENTRY(143, sub_8325C3E8, 0x8325C3E8) { ctx.r3.u64 = Construct_TXT_8349B100_G_(ctx, base); }

uint64_t Construct_TXT_8349B104_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B104_G_ = int32_t(0x8349B104);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B104_G__address = int32_t(0x832A5568);
	if (!UseLiftedCode(143, 0x8325C428)) { __imp__sub_8325C428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C428);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B104_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B104_G__address);
}
PROMOTED_ENTRY(143, sub_8325C428, 0x8325C428) { ctx.r3.u64 = Construct_TXT_8349B104_G_(ctx, base); }

uint64_t Construct_TXT_8349B108_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B108_G_ = int32_t(0x8349B108);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B108_G__address = int32_t(0x832A5578);
	if (!UseLiftedCode(143, 0x8325C468)) { __imp__sub_8325C468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C468);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B108_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B108_G__address);
}
PROMOTED_ENTRY(143, sub_8325C468, 0x8325C468) { ctx.r3.u64 = Construct_TXT_8349B108_G_(ctx, base); }

uint64_t Construct_TXT_8349B10C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B10C_G_ = int32_t(0x8349B10C);
	constexpr int32_t str_TXT_820CDEE4_B_ = int32_t(0x820CDEE4);
	constexpr int32_t Destroy_TXT_8349B10C_G__address = int32_t(0x832A5588);
	if (!UseLiftedCode(143, 0x8325C4A8)) { __imp__sub_8325C4A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C4A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B10C_G_, str_TXT_820CDEE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B10C_G__address);
}
PROMOTED_ENTRY(143, sub_8325C4A8, 0x8325C4A8) { ctx.r3.u64 = Construct_TXT_8349B10C_G_(ctx, base); }

uint64_t Construct_TXT_8349B110_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B110_G_ = int32_t(0x8349B110);
	constexpr int32_t str_TXT_820CDF00_B_ = int32_t(0x820CDF00);
	constexpr int32_t Destroy_TXT_8349B110_G__address = int32_t(0x832A5598);
	if (!UseLiftedCode(143, 0x8325C4E8)) { __imp__sub_8325C4E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C4E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B110_G_, str_TXT_820CDF00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B110_G__address);
}
PROMOTED_ENTRY(143, sub_8325C4E8, 0x8325C4E8) { ctx.r3.u64 = Construct_TXT_8349B110_G_(ctx, base); }

uint64_t Construct_TXT_8349B114_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B114_G_ = int32_t(0x8349B114);
	constexpr int32_t str_TXT_820CDF1C_B_ = int32_t(0x820CDF1C);
	constexpr int32_t Destroy_TXT_8349B114_G__address = int32_t(0x832A55A8);
	if (!UseLiftedCode(143, 0x8325C528)) { __imp__sub_8325C528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C528);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B114_G_, str_TXT_820CDF1C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B114_G__address);
}
PROMOTED_ENTRY(143, sub_8325C528, 0x8325C528) { ctx.r3.u64 = Construct_TXT_8349B114_G_(ctx, base); }

uint64_t Construct_TXT_8349B118_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B118_G_ = int32_t(0x8349B118);
	constexpr int32_t str_TXT_820CDF3C_B_ = int32_t(0x820CDF3C);
	constexpr int32_t Destroy_TXT_8349B118_G__address = int32_t(0x832A55B8);
	if (!UseLiftedCode(143, 0x8325C568)) { __imp__sub_8325C568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C568);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B118_G_, str_TXT_820CDF3C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B118_G__address);
}
PROMOTED_ENTRY(143, sub_8325C568, 0x8325C568) { ctx.r3.u64 = Construct_TXT_8349B118_G_(ctx, base); }

uint64_t Construct_TXT_8349B11C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B11C_G_ = int32_t(0x8349B11C);
	constexpr int32_t str_TXT_820CDF5C_B_ = int32_t(0x820CDF5C);
	constexpr int32_t Destroy_TXT_8349B11C_G__address = int32_t(0x832A55C8);
	if (!UseLiftedCode(143, 0x8325C5A8)) { __imp__sub_8325C5A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C5A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B11C_G_, str_TXT_820CDF5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B11C_G__address);
}
PROMOTED_ENTRY(143, sub_8325C5A8, 0x8325C5A8) { ctx.r3.u64 = Construct_TXT_8349B11C_G_(ctx, base); }

uint64_t Construct_TXT_8349B120_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B120_G_ = int32_t(0x8349B120);
	constexpr int32_t str_TXT_820CDF78_B_ = int32_t(0x820CDF78);
	constexpr int32_t Destroy_TXT_8349B120_G__address = int32_t(0x832A55D8);
	if (!UseLiftedCode(143, 0x8325C5E8)) { __imp__sub_8325C5E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C5E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B120_G_, str_TXT_820CDF78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B120_G__address);
}
PROMOTED_ENTRY(143, sub_8325C5E8, 0x8325C5E8) { ctx.r3.u64 = Construct_TXT_8349B120_G_(ctx, base); }

uint64_t Construct_TXT_8349B124_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B124_G_ = int32_t(0x8349B124);
	constexpr int32_t str_TXT_820CDF94_B_ = int32_t(0x820CDF94);
	constexpr int32_t Destroy_TXT_8349B124_G__address = int32_t(0x832A55E8);
	if (!UseLiftedCode(143, 0x8325C628)) { __imp__sub_8325C628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B124_G_, str_TXT_820CDF94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B124_G__address);
}
PROMOTED_ENTRY(143, sub_8325C628, 0x8325C628) { ctx.r3.u64 = Construct_TXT_8349B124_G_(ctx, base); }

uint64_t n_sub_8325C668(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A55F8_address = int32_t(0x832A55F8);
	if (!UseLiftedCode(143, 0x8325C668)) { ctx.r8.u64 = exitContext; __imp__sub_8325C668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C668);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A55F8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325C668, 0x8325C668) { ctx.r3.u64 = n_sub_8325C668(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349B130_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B130_G_ = int32_t(0x8349B130);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B130_G__address = int32_t(0x832A5698);
	if (!UseLiftedCode(143, 0x8325C678)) { __imp__sub_8325C678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C678);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B130_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B130_G__address);
}
PROMOTED_ENTRY(143, sub_8325C678, 0x8325C678) { ctx.r3.u64 = Construct_TXT_8349B130_G_(ctx, base); }

uint64_t Construct_TXT_8349B134_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B134_G_ = int32_t(0x8349B134);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B134_G__address = int32_t(0x832A56A8);
	if (!UseLiftedCode(143, 0x8325C6B8)) { __imp__sub_8325C6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C6B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B134_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B134_G__address);
}
PROMOTED_ENTRY(143, sub_8325C6B8, 0x8325C6B8) { ctx.r3.u64 = Construct_TXT_8349B134_G_(ctx, base); }

uint64_t Construct_TXT_8349B138_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B138_G_ = int32_t(0x8349B138);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B138_G__address = int32_t(0x832A56B8);
	if (!UseLiftedCode(143, 0x8325C6F8)) { __imp__sub_8325C6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C6F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B138_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B138_G__address);
}
PROMOTED_ENTRY(143, sub_8325C6F8, 0x8325C6F8) { ctx.r3.u64 = Construct_TXT_8349B138_G_(ctx, base); }

uint64_t Construct_TXT_8349B13C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B13C_G_ = int32_t(0x8349B13C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B13C_G__address = int32_t(0x832A56C8);
	if (!UseLiftedCode(143, 0x8325C738)) { __imp__sub_8325C738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C738);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B13C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B13C_G__address);
}
PROMOTED_ENTRY(143, sub_8325C738, 0x8325C738) { ctx.r3.u64 = Construct_TXT_8349B13C_G_(ctx, base); }

uint64_t Construct_TXT_8349B140_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B140_G_ = int32_t(0x8349B140);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B140_G__address = int32_t(0x832A56D8);
	if (!UseLiftedCode(143, 0x8325C778)) { __imp__sub_8325C778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C778);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B140_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B140_G__address);
}
PROMOTED_ENTRY(143, sub_8325C778, 0x8325C778) { ctx.r3.u64 = Construct_TXT_8349B140_G_(ctx, base); }

uint64_t Construct_TXT_8349B144_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B144_G_ = int32_t(0x8349B144);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B144_G__address = int32_t(0x832A56E8);
	if (!UseLiftedCode(143, 0x8325C7B8)) { __imp__sub_8325C7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C7B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B144_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B144_G__address);
}
PROMOTED_ENTRY(143, sub_8325C7B8, 0x8325C7B8) { ctx.r3.u64 = Construct_TXT_8349B144_G_(ctx, base); }

uint64_t Construct_TXT_8349B148_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B148_G_ = int32_t(0x8349B148);
	constexpr int32_t str_TXT_820CE648_B_ = int32_t(0x820CE648);
	constexpr int32_t Destroy_TXT_8349B148_G__address = int32_t(0x832A56F8);
	if (!UseLiftedCode(143, 0x8325C7F8)) { __imp__sub_8325C7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C7F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B148_G_, str_TXT_820CE648_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B148_G__address);
}
PROMOTED_ENTRY(143, sub_8325C7F8, 0x8325C7F8) { ctx.r3.u64 = Construct_TXT_8349B148_G_(ctx, base); }

uint64_t Construct_TXT_8349B14C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B14C_G_ = int32_t(0x8349B14C);
	constexpr int32_t str_TXT_820CE650_B_ = int32_t(0x820CE650);
	constexpr int32_t Destroy_TXT_8349B14C_G__address = int32_t(0x832A5708);
	if (!UseLiftedCode(143, 0x8325C838)) { __imp__sub_8325C838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B14C_G_, str_TXT_820CE650_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B14C_G__address);
}
PROMOTED_ENTRY(143, sub_8325C838, 0x8325C838) { ctx.r3.u64 = Construct_TXT_8349B14C_G_(ctx, base); }

uint64_t Construct_TXT_8349B150_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B150_G_ = int32_t(0x8349B150);
	constexpr int32_t str_TXT_820CE654_B_ = int32_t(0x820CE654);
	constexpr int32_t Destroy_TXT_8349B150_G__address = int32_t(0x832A5718);
	if (!UseLiftedCode(143, 0x8325C878)) { __imp__sub_8325C878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C878);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B150_G_, str_TXT_820CE654_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B150_G__address);
}
PROMOTED_ENTRY(143, sub_8325C878, 0x8325C878) { ctx.r3.u64 = Construct_TXT_8349B150_G_(ctx, base); }

uint64_t Construct_TXT_8349B154_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B154_G_ = int32_t(0x8349B154);
	constexpr int32_t str_TXT_820CE660_B_ = int32_t(0x820CE660);
	constexpr int32_t Destroy_TXT_8349B154_G__address = int32_t(0x832A5728);
	if (!UseLiftedCode(143, 0x8325C8B8)) { __imp__sub_8325C8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C8B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B154_G_, str_TXT_820CE660_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B154_G__address);
}
PROMOTED_ENTRY(143, sub_8325C8B8, 0x8325C8B8) { ctx.r3.u64 = Construct_TXT_8349B154_G_(ctx, base); }

uint64_t Construct_TXT_8349B158_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B158_G_ = int32_t(0x8349B158);
	constexpr int32_t str_TXT_820CE668_B_ = int32_t(0x820CE668);
	constexpr int32_t Destroy_TXT_8349B158_G__address = int32_t(0x832A5738);
	if (!UseLiftedCode(143, 0x8325C8F8)) { __imp__sub_8325C8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C8F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B158_G_, str_TXT_820CE668_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B158_G__address);
}
PROMOTED_ENTRY(143, sub_8325C8F8, 0x8325C8F8) { ctx.r3.u64 = Construct_TXT_8349B158_G_(ctx, base); }

uint64_t Construct_TXT_8349B15C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B15C_G_ = int32_t(0x8349B15C);
	constexpr int32_t str_TXT_820CE670_B_ = int32_t(0x820CE670);
	constexpr int32_t Destroy_TXT_8349B15C_G__address = int32_t(0x832A5748);
	if (!UseLiftedCode(143, 0x8325C938)) { __imp__sub_8325C938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C938);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B15C_G_, str_TXT_820CE670_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B15C_G__address);
}
PROMOTED_ENTRY(143, sub_8325C938, 0x8325C938) { ctx.r3.u64 = Construct_TXT_8349B15C_G_(ctx, base); }

uint64_t Construct_TXT_8349B160_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B160_G_ = int32_t(0x8349B160);
	constexpr int32_t str_TXT_820CE67C_B_ = int32_t(0x820CE67C);
	constexpr int32_t Destroy_TXT_8349B160_G__address = int32_t(0x832A5758);
	if (!UseLiftedCode(143, 0x8325C978)) { __imp__sub_8325C978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C978);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B160_G_, str_TXT_820CE67C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B160_G__address);
}
PROMOTED_ENTRY(143, sub_8325C978, 0x8325C978) { ctx.r3.u64 = Construct_TXT_8349B160_G_(ctx, base); }

uint64_t Construct_TXT_8349B164_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B164_G_ = int32_t(0x8349B164);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B164_G__address = int32_t(0x832A5770);
	if (!UseLiftedCode(143, 0x8325C9B8)) { __imp__sub_8325C9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C9B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B164_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B164_G__address);
}
PROMOTED_ENTRY(143, sub_8325C9B8, 0x8325C9B8) { ctx.r3.u64 = Construct_TXT_8349B164_G_(ctx, base); }

uint64_t Construct_TXT_8349B168_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B168_G_ = int32_t(0x8349B168);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B168_G__address = int32_t(0x832A5780);
	if (!UseLiftedCode(143, 0x8325C9F8)) { __imp__sub_8325C9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C9F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B168_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B168_G__address);
}
PROMOTED_ENTRY(143, sub_8325C9F8, 0x8325C9F8) { ctx.r3.u64 = Construct_TXT_8349B168_G_(ctx, base); }

uint64_t Construct_TXT_8349B16C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B16C_G_ = int32_t(0x8349B16C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B16C_G__address = int32_t(0x832A5790);
	if (!UseLiftedCode(143, 0x8325CA38)) { __imp__sub_8325CA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CA38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B16C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B16C_G__address);
}
PROMOTED_ENTRY(143, sub_8325CA38, 0x8325CA38) { ctx.r3.u64 = Construct_TXT_8349B16C_G_(ctx, base); }

uint64_t Construct_TXT_8349B170_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B170_G_ = int32_t(0x8349B170);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B170_G__address = int32_t(0x832A57A0);
	if (!UseLiftedCode(143, 0x8325CA78)) { __imp__sub_8325CA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CA78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B170_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B170_G__address);
}
PROMOTED_ENTRY(143, sub_8325CA78, 0x8325CA78) { ctx.r3.u64 = Construct_TXT_8349B170_G_(ctx, base); }

uint64_t Construct_TXT_8349B174_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B174_G_ = int32_t(0x8349B174);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B174_G__address = int32_t(0x832A57B0);
	if (!UseLiftedCode(143, 0x8325CAB8)) { __imp__sub_8325CAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B174_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B174_G__address);
}
PROMOTED_ENTRY(143, sub_8325CAB8, 0x8325CAB8) { ctx.r3.u64 = Construct_TXT_8349B174_G_(ctx, base); }

uint64_t Construct_TXT_8349B178_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B178_G_ = int32_t(0x8349B178);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B178_G__address = int32_t(0x832A57C0);
	if (!UseLiftedCode(143, 0x8325CAF8)) { __imp__sub_8325CAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B178_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B178_G__address);
}
PROMOTED_ENTRY(143, sub_8325CAF8, 0x8325CAF8) { ctx.r3.u64 = Construct_TXT_8349B178_G_(ctx, base); }

uint64_t Construct_TXT_8349B17C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t str_TXT_820CEB20_B_ = int32_t(0x820CEB20);
	constexpr int32_t Destroy_TXT_8349B17C_G__address = int32_t(0x832A57D0);
	if (!UseLiftedCode(143, 0x8325CB38)) { __imp__sub_8325CB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CB38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B17C_G_, str_TXT_820CEB20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B17C_G__address);
}
PROMOTED_ENTRY(143, sub_8325CB38, 0x8325CB38) { ctx.r3.u64 = Construct_TXT_8349B17C_G_(ctx, base); }

uint64_t Construct_TXT_8349B1A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1A4_G_ = int32_t(0x8349B1A4);
	constexpr int32_t str_TXT_820CEBA4_B_ = int32_t(0x820CEBA4);
	constexpr int32_t Destroy_TXT_8349B1A4_G__address = int32_t(0x832A5850);
	if (!UseLiftedCode(143, 0x8325CE40)) { __imp__sub_8325CE40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CE40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1A4_G_, str_TXT_820CEBA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1A4_G__address);
}
PROMOTED_ENTRY(143, sub_8325CE40, 0x8325CE40) { ctx.r3.u64 = Construct_TXT_8349B1A4_G_(ctx, base); }

uint64_t Construct_TXT_8349B1AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t str_TXT_820CEBBC_B_ = int32_t(0x820CEBBC);
	constexpr int32_t Destroy_TXT_8349B1AC_G__address = int32_t(0x832A5870);
	if (!UseLiftedCode(143, 0x8325CED8)) { __imp__sub_8325CED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1AC_G_, str_TXT_820CEBBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1AC_G__address);
}
PROMOTED_ENTRY(143, sub_8325CED8, 0x8325CED8) { ctx.r3.u64 = Construct_TXT_8349B1AC_G_(ctx, base); }

uint64_t Construct_TXT_8349B1C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	constexpr int32_t str_TXT_820CEBF4_B_ = int32_t(0x820CEBF4);
	constexpr int32_t Destroy_TXT_8349B1C8_G__address = int32_t(0x832A58D0);
	if (!UseLiftedCode(143, 0x8325D100)) { __imp__sub_8325D100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D100);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1C8_G_, str_TXT_820CEBF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1C8_G__address);
}
PROMOTED_ENTRY(143, sub_8325D100, 0x8325D100) { ctx.r3.u64 = Construct_TXT_8349B1C8_G_(ctx, base); }

uint64_t Construct_TXT_8349B1CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1CC_G_ = int32_t(0x8349B1CC);
	constexpr int32_t str_TXT_820CEC04_B_ = int32_t(0x820CEC04);
	constexpr int32_t Destroy_TXT_8349B1CC_G__address = int32_t(0x832A58E0);
	if (!UseLiftedCode(143, 0x8325D140)) { __imp__sub_8325D140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D140);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1CC_G_, str_TXT_820CEC04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1CC_G__address);
}
PROMOTED_ENTRY(143, sub_8325D140, 0x8325D140) { ctx.r3.u64 = Construct_TXT_8349B1CC_G_(ctx, base); }

uint64_t Construct_TXT_8349B1E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1E4_G_ = int32_t(0x8349B1E4);
	constexpr int32_t str_TXT_820CEC44_B_ = int32_t(0x820CEC44);
	constexpr int32_t Destroy_TXT_8349B1E4_G__address = int32_t(0x832A5940);
	if (!UseLiftedCode(143, 0x8325D370)) { __imp__sub_8325D370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D370);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1E4_G_, str_TXT_820CEC44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1E4_G__address);
}
PROMOTED_ENTRY(143, sub_8325D370, 0x8325D370) { ctx.r3.u64 = Construct_TXT_8349B1E4_G_(ctx, base); }

uint64_t Construct_TXT_8349B1F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1F4_G_ = int32_t(0x8349B1F4);
	constexpr int32_t str_TXT_820CEC6C_B_ = int32_t(0x820CEC6C);
	constexpr int32_t Destroy_TXT_8349B1F4_G__address = int32_t(0x832A5980);
	if (!UseLiftedCode(143, 0x8325D4B8)) { __imp__sub_8325D4B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D4B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1F4_G_, str_TXT_820CEC6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1F4_G__address);
}
PROMOTED_ENTRY(143, sub_8325D4B8, 0x8325D4B8) { ctx.r3.u64 = Construct_TXT_8349B1F4_G_(ctx, base); }

uint64_t Construct_TXT_8349B1F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1F8_G_ = int32_t(0x8349B1F8);
	constexpr int32_t str_TXT_820CEC7C_B_ = int32_t(0x820CEC7C);
	constexpr int32_t Destroy_TXT_8349B1F8_G__address = int32_t(0x832A5990);
	if (!UseLiftedCode(143, 0x8325D4F8)) { __imp__sub_8325D4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D4F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1F8_G_, str_TXT_820CEC7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1F8_G__address);
}
PROMOTED_ENTRY(143, sub_8325D4F8, 0x8325D4F8) { ctx.r3.u64 = Construct_TXT_8349B1F8_G_(ctx, base); }

uint64_t Construct_TXT_8349B1FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B1FC_G_ = int32_t(0x8349B1FC);
	constexpr int32_t str_TXT_820CEC90_B_ = int32_t(0x820CEC90);
	constexpr int32_t Destroy_TXT_8349B1FC_G__address = int32_t(0x832A59A0);
	if (!UseLiftedCode(143, 0x8325D538)) { __imp__sub_8325D538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D538);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B1FC_G_, str_TXT_820CEC90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B1FC_G__address);
}
PROMOTED_ENTRY(143, sub_8325D538, 0x8325D538) { ctx.r3.u64 = Construct_TXT_8349B1FC_G_(ctx, base); }

uint64_t Construct_TXT_8349B208_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B208_G_ = int32_t(0x8349B208);
	constexpr int32_t str_TXT_820CECB0_B_ = int32_t(0x820CECB0);
	constexpr int32_t Destroy_TXT_8349B208_G__address = int32_t(0x832A59D0);
	if (!UseLiftedCode(143, 0x8325D628)) { __imp__sub_8325D628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B208_G_, str_TXT_820CECB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B208_G__address);
}
PROMOTED_ENTRY(143, sub_8325D628, 0x8325D628) { ctx.r3.u64 = Construct_TXT_8349B208_G_(ctx, base); }

uint64_t Construct_TXT_8349B20C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B20C_G_ = int32_t(0x8349B20C);
	constexpr int32_t str_TXT_820BC2AC_B_ = int32_t(0x820BC2AC);
	constexpr int32_t Destroy_TXT_8349B20C_G__address = int32_t(0x832A59E0);
	if (!UseLiftedCode(143, 0x8325D668)) { __imp__sub_8325D668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D668);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B20C_G_, str_TXT_820BC2AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B20C_G__address);
}
PROMOTED_ENTRY(143, sub_8325D668, 0x8325D668) { ctx.r3.u64 = Construct_TXT_8349B20C_G_(ctx, base); }

uint64_t Construct_TXT_8349B210_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B210_G_ = int32_t(0x8349B210);
	constexpr int32_t str_TXT_820CECC4_B_ = int32_t(0x820CECC4);
	constexpr int32_t Destroy_TXT_8349B210_G__address = int32_t(0x832A59F0);
	if (!UseLiftedCode(143, 0x8325D6A8)) { __imp__sub_8325D6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D6A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B210_G_, str_TXT_820CECC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B210_G__address);
}
PROMOTED_ENTRY(143, sub_8325D6A8, 0x8325D6A8) { ctx.r3.u64 = Construct_TXT_8349B210_G_(ctx, base); }

uint64_t Construct_TXT_8349B214_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B214_G_ = int32_t(0x8349B214);
	constexpr int32_t str_TXT_820CECE4_B_ = int32_t(0x820CECE4);
	constexpr int32_t Destroy_TXT_8349B214_G__address = int32_t(0x832A5A00);
	if (!UseLiftedCode(143, 0x8325D6E8)) { __imp__sub_8325D6E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D6E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B214_G_, str_TXT_820CECE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B214_G__address);
}
PROMOTED_ENTRY(143, sub_8325D6E8, 0x8325D6E8) { ctx.r3.u64 = Construct_TXT_8349B214_G_(ctx, base); }

uint64_t Construct_TXT_8349B218_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B218_G_ = int32_t(0x8349B218);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B218_G__address = int32_t(0x832A5A10);
	if (!UseLiftedCode(143, 0x8325D728)) { __imp__sub_8325D728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D728);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B218_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B218_G__address);
}
PROMOTED_ENTRY(143, sub_8325D728, 0x8325D728) { ctx.r3.u64 = Construct_TXT_8349B218_G_(ctx, base); }

uint64_t Construct_TXT_8349B21C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B21C_G_ = int32_t(0x8349B21C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B21C_G__address = int32_t(0x832A5A20);
	if (!UseLiftedCode(143, 0x8325D768)) { __imp__sub_8325D768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D768);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B21C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B21C_G__address);
}
PROMOTED_ENTRY(143, sub_8325D768, 0x8325D768) { ctx.r3.u64 = Construct_TXT_8349B21C_G_(ctx, base); }

uint64_t Construct_TXT_8349B220_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B220_G_ = int32_t(0x8349B220);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B220_G__address = int32_t(0x832A5A30);
	if (!UseLiftedCode(143, 0x8325D7A8)) { __imp__sub_8325D7A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B220_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B220_G__address);
}
PROMOTED_ENTRY(143, sub_8325D7A8, 0x8325D7A8) { ctx.r3.u64 = Construct_TXT_8349B220_G_(ctx, base); }

uint64_t n_sub_8325D7E8(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A5A40_address = int32_t(0x832A5A40);
	if (!UseLiftedCode(143, 0x8325D7E8)) { ctx.r8.u64 = exitContext; __imp__sub_8325D7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7E8);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A5A40_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325D7E8, 0x8325D7E8) { ctx.r3.u64 = n_sub_8325D7E8(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349B234_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B234_G_ = int32_t(0x8349B234);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B234_G__address = int32_t(0x832A5AB0);
	if (!UseLiftedCode(143, 0x8325D7F8)) { __imp__sub_8325D7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B234_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B234_G__address);
}
PROMOTED_ENTRY(143, sub_8325D7F8, 0x8325D7F8) { ctx.r3.u64 = Construct_TXT_8349B234_G_(ctx, base); }

uint64_t Construct_TXT_8349B238_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B238_G_ = int32_t(0x8349B238);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B238_G__address = int32_t(0x832A5AC0);
	if (!UseLiftedCode(143, 0x8325D838)) { __imp__sub_8325D838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B238_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B238_G__address);
}
PROMOTED_ENTRY(143, sub_8325D838, 0x8325D838) { ctx.r3.u64 = Construct_TXT_8349B238_G_(ctx, base); }

uint64_t Construct_TXT_8349B23C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B23C_G_ = int32_t(0x8349B23C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B23C_G__address = int32_t(0x832A5AD0);
	if (!UseLiftedCode(143, 0x8325D878)) { __imp__sub_8325D878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D878);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B23C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B23C_G__address);
}
PROMOTED_ENTRY(143, sub_8325D878, 0x8325D878) { ctx.r3.u64 = Construct_TXT_8349B23C_G_(ctx, base); }

uint64_t Construct_TXT_8349B240_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B240_G_ = int32_t(0x8349B240);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B240_G__address = int32_t(0x832A5AE0);
	if (!UseLiftedCode(143, 0x8325D8B8)) { __imp__sub_8325D8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D8B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B240_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B240_G__address);
}
PROMOTED_ENTRY(143, sub_8325D8B8, 0x8325D8B8) { ctx.r3.u64 = Construct_TXT_8349B240_G_(ctx, base); }

uint64_t Construct_TXT_8349B244_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B244_G_ = int32_t(0x8349B244);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B244_G__address = int32_t(0x832A5AF0);
	if (!UseLiftedCode(143, 0x8325D8F8)) { __imp__sub_8325D8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D8F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B244_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B244_G__address);
}
PROMOTED_ENTRY(143, sub_8325D8F8, 0x8325D8F8) { ctx.r3.u64 = Construct_TXT_8349B244_G_(ctx, base); }

uint64_t Construct_TXT_8349B248_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B248_G_ = int32_t(0x8349B248);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B248_G__address = int32_t(0x832A5B00);
	if (!UseLiftedCode(143, 0x8325D938)) { __imp__sub_8325D938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D938);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B248_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B248_G__address);
}
PROMOTED_ENTRY(143, sub_8325D938, 0x8325D938) { ctx.r3.u64 = Construct_TXT_8349B248_G_(ctx, base); }

uint64_t Construct_TXT_8349B24C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B24C_G_ = int32_t(0x8349B24C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B24C_G__address = int32_t(0x832A5B10);
	if (!UseLiftedCode(143, 0x8325D978)) { __imp__sub_8325D978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D978);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B24C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B24C_G__address);
}
PROMOTED_ENTRY(143, sub_8325D978, 0x8325D978) { ctx.r3.u64 = Construct_TXT_8349B24C_G_(ctx, base); }

uint64_t Construct_TXT_8349B250_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B250_G_ = int32_t(0x8349B250);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B250_G__address = int32_t(0x832A5B20);
	if (!UseLiftedCode(143, 0x8325D9B8)) { __imp__sub_8325D9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D9B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B250_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B250_G__address);
}
PROMOTED_ENTRY(143, sub_8325D9B8, 0x8325D9B8) { ctx.r3.u64 = Construct_TXT_8349B250_G_(ctx, base); }

uint64_t Construct_TXT_8349B254_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B254_G_ = int32_t(0x8349B254);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B254_G__address = int32_t(0x832A5B30);
	if (!UseLiftedCode(143, 0x8325D9F8)) { __imp__sub_8325D9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D9F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B254_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B254_G__address);
}
PROMOTED_ENTRY(143, sub_8325D9F8, 0x8325D9F8) { ctx.r3.u64 = Construct_TXT_8349B254_G_(ctx, base); }

uint64_t Construct_TXT_8349B258_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B258_G_ = int32_t(0x8349B258);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B258_G__address = int32_t(0x832A5B40);
	if (!UseLiftedCode(143, 0x8325DA38)) { __imp__sub_8325DA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DA38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B258_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B258_G__address);
}
PROMOTED_ENTRY(143, sub_8325DA38, 0x8325DA38) { ctx.r3.u64 = Construct_TXT_8349B258_G_(ctx, base); }

uint64_t Construct_TXT_8349B25C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B25C_G_ = int32_t(0x8349B25C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B25C_G__address = int32_t(0x832A5B50);
	if (!UseLiftedCode(143, 0x8325DA78)) { __imp__sub_8325DA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DA78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B25C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B25C_G__address);
}
PROMOTED_ENTRY(143, sub_8325DA78, 0x8325DA78) { ctx.r3.u64 = Construct_TXT_8349B25C_G_(ctx, base); }

uint64_t Construct_TXT_8349B260_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B260_G_ = int32_t(0x8349B260);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B260_G__address = int32_t(0x832A5B60);
	if (!UseLiftedCode(143, 0x8325DAB8)) { __imp__sub_8325DAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B260_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B260_G__address);
}
PROMOTED_ENTRY(143, sub_8325DAB8, 0x8325DAB8) { ctx.r3.u64 = Construct_TXT_8349B260_G_(ctx, base); }

uint64_t Construct_TXT_8349B264_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B264_G_ = int32_t(0x8349B264);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B264_G__address = int32_t(0x832A5B70);
	if (!UseLiftedCode(143, 0x8325DAF8)) { __imp__sub_8325DAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B264_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B264_G__address);
}
PROMOTED_ENTRY(143, sub_8325DAF8, 0x8325DAF8) { ctx.r3.u64 = Construct_TXT_8349B264_G_(ctx, base); }

uint64_t Construct_TXT_8349B268_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B268_G_ = int32_t(0x8349B268);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B268_G__address = int32_t(0x832A5B80);
	if (!UseLiftedCode(143, 0x8325DB38)) { __imp__sub_8325DB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DB38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B268_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B268_G__address);
}
PROMOTED_ENTRY(143, sub_8325DB38, 0x8325DB38) { ctx.r3.u64 = Construct_TXT_8349B268_G_(ctx, base); }

uint64_t Construct_TXT_8349B26C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B26C_G_ = int32_t(0x8349B26C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B26C_G__address = int32_t(0x832A5B90);
	if (!UseLiftedCode(143, 0x8325DB78)) { __imp__sub_8325DB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DB78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B26C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B26C_G__address);
}
PROMOTED_ENTRY(143, sub_8325DB78, 0x8325DB78) { ctx.r3.u64 = Construct_TXT_8349B26C_G_(ctx, base); }

uint64_t Construct_TXT_8349B290_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B290_G_ = int32_t(0x8349B290);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B290_G__address = int32_t(0x832A5BA0);
	if (!UseLiftedCode(143, 0x8325DD78)) { __imp__sub_8325DD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DD78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B290_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B290_G__address);
}
PROMOTED_ENTRY(143, sub_8325DD78, 0x8325DD78) { ctx.r3.u64 = Construct_TXT_8349B290_G_(ctx, base); }

uint64_t Construct_TXT_8349B294_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B294_G_ = int32_t(0x8349B294);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B294_G__address = int32_t(0x832A5BB0);
	if (!UseLiftedCode(143, 0x8325DDB8)) { __imp__sub_8325DDB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DDB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B294_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B294_G__address);
}
PROMOTED_ENTRY(143, sub_8325DDB8, 0x8325DDB8) { ctx.r3.u64 = Construct_TXT_8349B294_G_(ctx, base); }

uint64_t Construct_TXT_8349B298_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B298_G_ = int32_t(0x8349B298);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B298_G__address = int32_t(0x832A5BC0);
	if (!UseLiftedCode(143, 0x8325DDF8)) { __imp__sub_8325DDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DDF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B298_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B298_G__address);
}
PROMOTED_ENTRY(143, sub_8325DDF8, 0x8325DDF8) { ctx.r3.u64 = Construct_TXT_8349B298_G_(ctx, base); }

uint64_t Construct_TXT_8349B2B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2B4_G_ = int32_t(0x8349B2B4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B2B4_G__address = int32_t(0x832A5BD0);
	if (!UseLiftedCode(143, 0x8325DF88)) { __imp__sub_8325DF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2B4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2B4_G__address);
}
PROMOTED_ENTRY(143, sub_8325DF88, 0x8325DF88) { ctx.r3.u64 = Construct_TXT_8349B2B4_G_(ctx, base); }

uint64_t Construct_TXT_8349B2B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2B8_G_ = int32_t(0x8349B2B8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B2B8_G__address = int32_t(0x832A5BE0);
	if (!UseLiftedCode(143, 0x8325DFC8)) { __imp__sub_8325DFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2B8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2B8_G__address);
}
PROMOTED_ENTRY(143, sub_8325DFC8, 0x8325DFC8) { ctx.r3.u64 = Construct_TXT_8349B2B8_G_(ctx, base); }

uint64_t Construct_TXT_8349B2BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2BC_G_ = int32_t(0x8349B2BC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B2BC_G__address = int32_t(0x832A5BF0);
	if (!UseLiftedCode(143, 0x8325E008)) { __imp__sub_8325E008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2BC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2BC_G__address);
}
PROMOTED_ENTRY(143, sub_8325E008, 0x8325E008) { ctx.r3.u64 = Construct_TXT_8349B2BC_G_(ctx, base); }

uint64_t Construct_TXT_8349B2C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2C8_G_ = int32_t(0x8349B2C8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B2C8_G__address = int32_t(0x832A5C00);
	if (!UseLiftedCode(143, 0x8325E0B8)) { __imp__sub_8325E0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E0B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2C8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2C8_G__address);
}
PROMOTED_ENTRY(143, sub_8325E0B8, 0x8325E0B8) { ctx.r3.u64 = Construct_TXT_8349B2C8_G_(ctx, base); }

uint64_t Construct_TXT_8349B2CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2CC_G_ = int32_t(0x8349B2CC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B2CC_G__address = int32_t(0x832A5C10);
	if (!UseLiftedCode(143, 0x8325E0F8)) { __imp__sub_8325E0F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E0F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2CC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2CC_G__address);
}
PROMOTED_ENTRY(143, sub_8325E0F8, 0x8325E0F8) { ctx.r3.u64 = Construct_TXT_8349B2CC_G_(ctx, base); }

uint64_t Construct_TXT_8349B2D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2D0_G_ = int32_t(0x8349B2D0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B2D0_G__address = int32_t(0x832A5C20);
	if (!UseLiftedCode(143, 0x8325E138)) { __imp__sub_8325E138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2D0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2D0_G__address);
}
PROMOTED_ENTRY(143, sub_8325E138, 0x8325E138) { ctx.r3.u64 = Construct_TXT_8349B2D0_G_(ctx, base); }

uint64_t Construct_TXT_8349B2E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2E8_G_ = int32_t(0x8349B2E8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B2E8_G__address = int32_t(0x832A5C30);
	if (!UseLiftedCode(143, 0x8325E290)) { __imp__sub_8325E290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E290);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2E8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2E8_G__address);
}
PROMOTED_ENTRY(143, sub_8325E290, 0x8325E290) { ctx.r3.u64 = Construct_TXT_8349B2E8_G_(ctx, base); }

uint64_t Construct_TXT_8349B2EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2EC_G_ = int32_t(0x8349B2EC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B2EC_G__address = int32_t(0x832A5C40);
	if (!UseLiftedCode(143, 0x8325E2D0)) { __imp__sub_8325E2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E2D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2EC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2EC_G__address);
}
PROMOTED_ENTRY(143, sub_8325E2D0, 0x8325E2D0) { ctx.r3.u64 = Construct_TXT_8349B2EC_G_(ctx, base); }

uint64_t Construct_TXT_8349B2F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2F0_G_ = int32_t(0x8349B2F0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B2F0_G__address = int32_t(0x832A5C50);
	if (!UseLiftedCode(143, 0x8325E310)) { __imp__sub_8325E310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E310);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2F0_G__address);
}
PROMOTED_ENTRY(143, sub_8325E310, 0x8325E310) { ctx.r3.u64 = Construct_TXT_8349B2F0_G_(ctx, base); }

uint64_t Construct_TXT_8349B2F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2F4_G_ = int32_t(0x8349B2F4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B2F4_G__address = int32_t(0x832A5C60);
	if (!UseLiftedCode(143, 0x8325E350)) { __imp__sub_8325E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E350);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2F4_G__address);
}
PROMOTED_ENTRY(143, sub_8325E350, 0x8325E350) { ctx.r3.u64 = Construct_TXT_8349B2F4_G_(ctx, base); }

uint64_t Construct_TXT_8349B2F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2F8_G_ = int32_t(0x8349B2F8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B2F8_G__address = int32_t(0x832A5C70);
	if (!UseLiftedCode(143, 0x8325E390)) { __imp__sub_8325E390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E390);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2F8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2F8_G__address);
}
PROMOTED_ENTRY(143, sub_8325E390, 0x8325E390) { ctx.r3.u64 = Construct_TXT_8349B2F8_G_(ctx, base); }

uint64_t Construct_TXT_8349B2FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B2FC_G_ = int32_t(0x8349B2FC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B2FC_G__address = int32_t(0x832A5C80);
	if (!UseLiftedCode(143, 0x8325E3D0)) { __imp__sub_8325E3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E3D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B2FC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B2FC_G__address);
}
PROMOTED_ENTRY(143, sub_8325E3D0, 0x8325E3D0) { ctx.r3.u64 = Construct_TXT_8349B2FC_G_(ctx, base); }

uint64_t Construct_TXT_8349B300_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B300_G_ = int32_t(0x8349B300);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B300_G__address = int32_t(0x832A5C90);
	if (!UseLiftedCode(143, 0x8325E410)) { __imp__sub_8325E410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B300_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B300_G__address);
}
PROMOTED_ENTRY(143, sub_8325E410, 0x8325E410) { ctx.r3.u64 = Construct_TXT_8349B300_G_(ctx, base); }

uint64_t Construct_TXT_8349B304_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B304_G_ = int32_t(0x8349B304);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B304_G__address = int32_t(0x832A5CA0);
	if (!UseLiftedCode(143, 0x8325E450)) { __imp__sub_8325E450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B304_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B304_G__address);
}
PROMOTED_ENTRY(143, sub_8325E450, 0x8325E450) { ctx.r3.u64 = Construct_TXT_8349B304_G_(ctx, base); }

uint64_t Construct_TXT_8349B308_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B308_G_ = int32_t(0x8349B308);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B308_G__address = int32_t(0x832A5CB0);
	if (!UseLiftedCode(143, 0x8325E490)) { __imp__sub_8325E490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B308_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B308_G__address);
}
PROMOTED_ENTRY(143, sub_8325E490, 0x8325E490) { ctx.r3.u64 = Construct_TXT_8349B308_G_(ctx, base); }

uint64_t Construct_TXT_8349B370_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B370_G_ = int32_t(0x8349B370);
	constexpr int32_t str_TXT_820BC8AC_B_ = int32_t(0x820BC8AC);
	constexpr int32_t Destroy_TXT_8349B370_G__address = int32_t(0x832A5CE0);
	if (!UseLiftedCode(143, 0x8325E7C8)) { __imp__sub_8325E7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E7C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B370_G_, str_TXT_820BC8AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B370_G__address);
}
PROMOTED_ENTRY(143, sub_8325E7C8, 0x8325E7C8) { ctx.r3.u64 = Construct_TXT_8349B370_G_(ctx, base); }

// sub_8325E808  [64 bytes]
uint64_t n_sub_8325E808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B374_G_ = int32_t(0x8349B374);
	constexpr int32_t str_TXT_820D1418_B_ = int32_t(0x820D1418);
	constexpr int32_t Destroy_TXT_8349B374_G__address = int32_t(0x832A5CF0);
	if (!UseLiftedCode(143, 0x8325E808)) { __imp__sub_8325E808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E808);
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B374_G_, str_TXT_820D1418_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349B374_G__address);
	return result;
}
PROMOTED_ENTRY(143, sub_8325E808, 0x8325E808) { ctx.r3.u64 = n_sub_8325E808(ctx, base); }

uint64_t n_sub_8325E848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B378_G_ = int32_t(0x8349B378);
	constexpr int32_t str_TXT_820D1424_B_ = int32_t(0x820D1424);
	constexpr int32_t Destroy_TXT_8349B378_G__address = int32_t(0x832A5D00);
	if (!UseLiftedCode(143, 0x8325E848)) { __imp__sub_8325E848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B378_G_, str_TXT_820D1424_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B378_G__address);
}
PROMOTED_ENTRY(143, sub_8325E848, 0x8325E848) { ctx.r3.u64 = n_sub_8325E848(ctx, base); }

uint64_t n_sub_8325E888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B37C_G_ = int32_t(0x8349B37C);
	constexpr int32_t str_TXT_820D1434_B_ = int32_t(0x820D1434);
	constexpr int32_t Destroy_TXT_8349B37C_G__address = int32_t(0x832A5D10);
	if (!UseLiftedCode(143, 0x8325E888)) { __imp__sub_8325E888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B37C_G_, str_TXT_820D1434_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B37C_G__address);
}
PROMOTED_ENTRY(143, sub_8325E888, 0x8325E888) { ctx.r3.u64 = n_sub_8325E888(ctx, base); }

uint64_t n_sub_8325E8C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B380_G_ = int32_t(0x8349B380);
	constexpr int32_t str_TXT_820D1444_B_ = int32_t(0x820D1444);
	constexpr int32_t Destroy_TXT_8349B380_G__address = int32_t(0x832A5D20);
	if (!UseLiftedCode(143, 0x8325E8C8)) { __imp__sub_8325E8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B380_G_, str_TXT_820D1444_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B380_G__address);
}
PROMOTED_ENTRY(143, sub_8325E8C8, 0x8325E8C8) { ctx.r3.u64 = n_sub_8325E8C8(ctx, base); }

uint64_t Construct_TXT_8349B384_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B384_G_ = int32_t(0x8349B384);
	constexpr int32_t str_TXT_820B7768_B_ = int32_t(0x820B7768);
	constexpr int32_t Destroy_TXT_8349B384_G__address = int32_t(0x832A5D30);
	if (!UseLiftedCode(143, 0x8325E908)) { __imp__sub_8325E908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B384_G_, str_TXT_820B7768_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B384_G__address);
}
PROMOTED_ENTRY(143, sub_8325E908, 0x8325E908) { ctx.r3.u64 = Construct_TXT_8349B384_G_(ctx, base); }

uint64_t Construct_TXT_8349B388_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B388_G_ = int32_t(0x8349B388);
	constexpr int32_t str_TXT_820B76C4_B_ = int32_t(0x820B76C4);
	constexpr int32_t Destroy_TXT_8349B388_G__address = int32_t(0x832A5D40);
	if (!UseLiftedCode(143, 0x8325E948)) { __imp__sub_8325E948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B388_G_, str_TXT_820B76C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B388_G__address);
}
PROMOTED_ENTRY(143, sub_8325E948, 0x8325E948) { ctx.r3.u64 = Construct_TXT_8349B388_G_(ctx, base); }

uint64_t Construct_TXT_8349B38C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B38C_G_ = int32_t(0x8349B38C);
	constexpr int32_t str_TXT_820B76D8_B_ = int32_t(0x820B76D8);
	constexpr int32_t Destroy_TXT_8349B38C_G__address = int32_t(0x832A5D50);
	if (!UseLiftedCode(143, 0x8325E988)) { __imp__sub_8325E988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B38C_G_, str_TXT_820B76D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B38C_G__address);
}
PROMOTED_ENTRY(143, sub_8325E988, 0x8325E988) { ctx.r3.u64 = Construct_TXT_8349B38C_G_(ctx, base); }

uint64_t Construct_TXT_8349B390_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B390_G_ = int32_t(0x8349B390);
	constexpr int32_t str_TXT_820BE2E0_B_ = int32_t(0x820BE2E0);
	constexpr int32_t Destroy_TXT_8349B390_G__address = int32_t(0x832A5D60);
	if (!UseLiftedCode(143, 0x8325E9C8)) { __imp__sub_8325E9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E9C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B390_G_, str_TXT_820BE2E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B390_G__address);
}
PROMOTED_ENTRY(143, sub_8325E9C8, 0x8325E9C8) { ctx.r3.u64 = Construct_TXT_8349B390_G_(ctx, base); }

uint64_t Construct_TXT_8349B394_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B394_G_ = int32_t(0x8349B394);
	constexpr int32_t str_TXT_820013B0_B_ = int32_t(0x820013B0);
	constexpr int32_t Destroy_TXT_8349B394_G__address = int32_t(0x832A5D70);
	if (!UseLiftedCode(143, 0x8325EA08)) { __imp__sub_8325EA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B394_G_, str_TXT_820013B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B394_G__address);
}
PROMOTED_ENTRY(143, sub_8325EA08, 0x8325EA08) { ctx.r3.u64 = Construct_TXT_8349B394_G_(ctx, base); }

uint64_t Construct_TXT_8349B398_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B398_G_ = int32_t(0x8349B398);
	constexpr int32_t str_TXT_820013A0_B_ = int32_t(0x820013A0);
	constexpr int32_t Destroy_TXT_8349B398_G__address = int32_t(0x832A5D80);
	if (!UseLiftedCode(143, 0x8325EA48)) { __imp__sub_8325EA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B398_G_, str_TXT_820013A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B398_G__address);
}
PROMOTED_ENTRY(143, sub_8325EA48, 0x8325EA48) { ctx.r3.u64 = Construct_TXT_8349B398_G_(ctx, base); }

uint64_t n_sub_8325EA88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B39C_G_ = int32_t(0x8349B39C);
	constexpr int32_t str_TXT_820D1454_B_ = int32_t(0x820D1454);
	constexpr int32_t Destroy_TXT_8349B39C_G__address = int32_t(0x832A5D90);
	if (!UseLiftedCode(143, 0x8325EA88)) { __imp__sub_8325EA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B39C_G_, str_TXT_820D1454_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B39C_G__address);
}
PROMOTED_ENTRY(143, sub_8325EA88, 0x8325EA88) { ctx.r3.u64 = n_sub_8325EA88(ctx, base); }

uint64_t n_sub_8325EAC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A0_G_ = int32_t(0x8349B3A0);
	constexpr int32_t str_TXT_820D1468_B_ = int32_t(0x820D1468);
	constexpr int32_t Destroy_TXT_8349B3A0_G__address = int32_t(0x832A5DA0);
	if (!UseLiftedCode(143, 0x8325EAC8)) { __imp__sub_8325EAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A0_G_, str_TXT_820D1468_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EAC8, 0x8325EAC8) { ctx.r3.u64 = n_sub_8325EAC8(ctx, base); }

uint64_t n_sub_8325EB08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A4_G_ = int32_t(0x8349B3A4);
	constexpr int32_t str_TXT_820D147C_B_ = int32_t(0x820D147C);
	constexpr int32_t Destroy_TXT_8349B3A4_G__address = int32_t(0x832A5DB0);
	if (!UseLiftedCode(143, 0x8325EB08)) { __imp__sub_8325EB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A4_G_, str_TXT_820D147C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB08, 0x8325EB08) { ctx.r3.u64 = n_sub_8325EB08(ctx, base); }

uint64_t n_sub_8325EB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A8_G_ = int32_t(0x8349B3A8);
	constexpr int32_t str_TXT_820D1490_B_ = int32_t(0x820D1490);
	constexpr int32_t Destroy_TXT_8349B3A8_G__address = int32_t(0x832A5DC0);
	if (!UseLiftedCode(143, 0x8325EB48)) { __imp__sub_8325EB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A8_G_, str_TXT_820D1490_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB48, 0x8325EB48) { ctx.r3.u64 = n_sub_8325EB48(ctx, base); }

uint64_t n_sub_8325EB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3AC_G_ = int32_t(0x8349B3AC);
	constexpr int32_t str_TXT_820D14A4_B_ = int32_t(0x820D14A4);
	constexpr int32_t Destroy_TXT_8349B3AC_G__address = int32_t(0x832A5DD0);
	if (!UseLiftedCode(143, 0x8325EB88)) { __imp__sub_8325EB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3AC_G_, str_TXT_820D14A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3AC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB88, 0x8325EB88) { ctx.r3.u64 = n_sub_8325EB88(ctx, base); }

uint64_t n_sub_8325EBC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B0_G_ = int32_t(0x8349B3B0);
	constexpr int32_t str_TXT_820D14B8_B_ = int32_t(0x820D14B8);
	constexpr int32_t Destroy_TXT_8349B3B0_G__address = int32_t(0x832A5DE0);
	if (!UseLiftedCode(143, 0x8325EBC8)) { __imp__sub_8325EBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B0_G_, str_TXT_820D14B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EBC8, 0x8325EBC8) { ctx.r3.u64 = n_sub_8325EBC8(ctx, base); }

uint64_t n_sub_8325EC08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B4_G_ = int32_t(0x8349B3B4);
	constexpr int32_t str_TXT_820D14C8_B_ = int32_t(0x820D14C8);
	constexpr int32_t Destroy_TXT_8349B3B4_G__address = int32_t(0x832A5DF0);
	if (!UseLiftedCode(143, 0x8325EC08)) { __imp__sub_8325EC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B4_G_, str_TXT_820D14C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC08, 0x8325EC08) { ctx.r3.u64 = n_sub_8325EC08(ctx, base); }

uint64_t n_sub_8325EC48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B8_G_ = int32_t(0x8349B3B8);
	constexpr int32_t str_TXT_820D14D8_B_ = int32_t(0x820D14D8);
	constexpr int32_t Destroy_TXT_8349B3B8_G__address = int32_t(0x832A5E00);
	if (!UseLiftedCode(143, 0x8325EC48)) { __imp__sub_8325EC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B8_G_, str_TXT_820D14D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC48, 0x8325EC48) { ctx.r3.u64 = n_sub_8325EC48(ctx, base); }

uint64_t n_sub_8325EC88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3BC_G_ = int32_t(0x8349B3BC);
	constexpr int32_t str_TXT_820D14E8_B_ = int32_t(0x820D14E8);
	constexpr int32_t Destroy_TXT_8349B3BC_G__address = int32_t(0x832A5E10);
	if (!UseLiftedCode(143, 0x8325EC88)) { __imp__sub_8325EC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3BC_G_, str_TXT_820D14E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3BC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC88, 0x8325EC88) { ctx.r3.u64 = n_sub_8325EC88(ctx, base); }

uint64_t n_sub_8325ECC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C0_G_ = int32_t(0x8349B3C0);
	constexpr int32_t str_TXT_820D14F8_B_ = int32_t(0x820D14F8);
	constexpr int32_t Destroy_TXT_8349B3C0_G__address = int32_t(0x832A5E20);
	if (!UseLiftedCode(143, 0x8325ECC8)) { __imp__sub_8325ECC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ECC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C0_G_, str_TXT_820D14F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C0_G__address);
}
PROMOTED_ENTRY(143, sub_8325ECC8, 0x8325ECC8) { ctx.r3.u64 = n_sub_8325ECC8(ctx, base); }

uint64_t n_sub_8325ED08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C4_G_ = int32_t(0x8349B3C4);
	constexpr int32_t str_TXT_820D150C_B_ = int32_t(0x820D150C);
	constexpr int32_t Destroy_TXT_8349B3C4_G__address = int32_t(0x832A5E30);
	if (!UseLiftedCode(143, 0x8325ED08)) { __imp__sub_8325ED08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C4_G_, str_TXT_820D150C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C4_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED08, 0x8325ED08) { ctx.r3.u64 = n_sub_8325ED08(ctx, base); }

uint64_t n_sub_8325ED48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C8_G_ = int32_t(0x8349B3C8);
	constexpr int32_t str_TXT_820D1520_B_ = int32_t(0x820D1520);
	constexpr int32_t Destroy_TXT_8349B3C8_G__address = int32_t(0x832A5E40);
	if (!UseLiftedCode(143, 0x8325ED48)) { __imp__sub_8325ED48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C8_G_, str_TXT_820D1520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C8_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED48, 0x8325ED48) { ctx.r3.u64 = n_sub_8325ED48(ctx, base); }

uint64_t n_sub_8325ED88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3CC_G_ = int32_t(0x8349B3CC);
	constexpr int32_t str_TXT_820D1534_B_ = int32_t(0x820D1534);
	constexpr int32_t Destroy_TXT_8349B3CC_G__address = int32_t(0x832A5E50);
	if (!UseLiftedCode(143, 0x8325ED88)) { __imp__sub_8325ED88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3CC_G_, str_TXT_820D1534_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3CC_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED88, 0x8325ED88) { ctx.r3.u64 = n_sub_8325ED88(ctx, base); }

uint64_t n_sub_8325EDC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D0_G_ = int32_t(0x8349B3D0);
	constexpr int32_t str_TXT_820D1548_B_ = int32_t(0x820D1548);
	constexpr int32_t Destroy_TXT_8349B3D0_G__address = int32_t(0x832A5E60);
	if (!UseLiftedCode(143, 0x8325EDC8)) { __imp__sub_8325EDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EDC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D0_G_, str_TXT_820D1548_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EDC8, 0x8325EDC8) { ctx.r3.u64 = n_sub_8325EDC8(ctx, base); }

uint64_t n_sub_8325EE08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D4_G_ = int32_t(0x8349B3D4);
	constexpr int32_t str_TXT_820D155C_B_ = int32_t(0x820D155C);
	constexpr int32_t Destroy_TXT_8349B3D4_G__address = int32_t(0x832A5E70);
	if (!UseLiftedCode(143, 0x8325EE08)) { __imp__sub_8325EE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D4_G_, str_TXT_820D155C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE08, 0x8325EE08) { ctx.r3.u64 = n_sub_8325EE08(ctx, base); }

uint64_t n_sub_8325EE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D8_G_ = int32_t(0x8349B3D8);
	constexpr int32_t str_TXT_820D1570_B_ = int32_t(0x820D1570);
	constexpr int32_t Destroy_TXT_8349B3D8_G__address = int32_t(0x832A5E80);
	if (!UseLiftedCode(143, 0x8325EE48)) { __imp__sub_8325EE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D8_G_, str_TXT_820D1570_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE48, 0x8325EE48) { ctx.r3.u64 = n_sub_8325EE48(ctx, base); }

uint64_t n_sub_8325EE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3DC_G_ = int32_t(0x8349B3DC);
	constexpr int32_t str_TXT_820D1580_B_ = int32_t(0x820D1580);
	constexpr int32_t Destroy_TXT_8349B3DC_G__address = int32_t(0x832A5E90);
	if (!UseLiftedCode(143, 0x8325EE88)) { __imp__sub_8325EE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3DC_G_, str_TXT_820D1580_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3DC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE88, 0x8325EE88) { ctx.r3.u64 = n_sub_8325EE88(ctx, base); }

uint64_t n_sub_8325EEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E0_G_ = int32_t(0x8349B3E0);
	constexpr int32_t str_TXT_820D1590_B_ = int32_t(0x820D1590);
	constexpr int32_t Destroy_TXT_8349B3E0_G__address = int32_t(0x832A5EA0);
	if (!UseLiftedCode(143, 0x8325EEC8)) { __imp__sub_8325EEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E0_G_, str_TXT_820D1590_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EEC8, 0x8325EEC8) { ctx.r3.u64 = n_sub_8325EEC8(ctx, base); }

uint64_t n_sub_8325EF08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E4_G_ = int32_t(0x8349B3E4);
	constexpr int32_t str_TXT_820D15A0_B_ = int32_t(0x820D15A0);
	constexpr int32_t Destroy_TXT_8349B3E4_G__address = int32_t(0x832A5EB0);
	if (!UseLiftedCode(143, 0x8325EF08)) { __imp__sub_8325EF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E4_G_, str_TXT_820D15A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF08, 0x8325EF08) { ctx.r3.u64 = n_sub_8325EF08(ctx, base); }

uint64_t n_sub_8325EF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E8_G_ = int32_t(0x8349B3E8);
	constexpr int32_t str_TXT_820D15B0_B_ = int32_t(0x820D15B0);
	constexpr int32_t Destroy_TXT_8349B3E8_G__address = int32_t(0x832A5EC0);
	if (!UseLiftedCode(143, 0x8325EF48)) { __imp__sub_8325EF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E8_G_, str_TXT_820D15B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF48, 0x8325EF48) { ctx.r3.u64 = n_sub_8325EF48(ctx, base); }

uint64_t n_sub_8325EF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3EC_G_ = int32_t(0x8349B3EC);
	constexpr int32_t str_TXT_820D15C4_B_ = int32_t(0x820D15C4);
	constexpr int32_t Destroy_TXT_8349B3EC_G__address = int32_t(0x832A5ED0);
	if (!UseLiftedCode(143, 0x8325EF88)) { __imp__sub_8325EF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3EC_G_, str_TXT_820D15C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3EC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF88, 0x8325EF88) { ctx.r3.u64 = n_sub_8325EF88(ctx, base); }

uint64_t n_sub_8325EFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3F0_G_ = int32_t(0x8349B3F0);
	constexpr int32_t str_TXT_820D15D4_B_ = int32_t(0x820D15D4);
	constexpr int32_t Destroy_TXT_8349B3F0_G__address = int32_t(0x832A5EE0);
	if (!UseLiftedCode(143, 0x8325EFC8)) { __imp__sub_8325EFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F0_G_, str_TXT_820D15D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3F0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EFC8, 0x8325EFC8) { ctx.r3.u64 = n_sub_8325EFC8(ctx, base); }

uint64_t n_sub_8325F008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3F4_G_ = int32_t(0x8349B3F4);
	constexpr int32_t str_TXT_820D15DC_B_ = int32_t(0x820D15DC);
	constexpr int32_t Destroy_TXT_8349B3F4_G__address = int32_t(0x832A5EF0);
	if (!UseLiftedCode(143, 0x8325F008)) { __imp__sub_8325F008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F4_G_, str_TXT_820D15DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3F4_G__address);
}
PROMOTED_ENTRY(143, sub_8325F008, 0x8325F008) { ctx.r3.u64 = n_sub_8325F008(ctx, base); }

uint64_t Construct_TXT_8349B3F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3F8_G_ = int32_t(0x8349B3F8);
	constexpr int32_t str_TXT_82005670_B_ = int32_t(0x82005670);
	constexpr int32_t Destroy_TXT_8349B3F8_G__address = int32_t(0x832A5F00);
	if (!UseLiftedCode(143, 0x8325F048)) { __imp__sub_8325F048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B3F8_G_, str_TXT_82005670_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3F8_G__address);
}
PROMOTED_ENTRY(143, sub_8325F048, 0x8325F048) { ctx.r3.u64 = Construct_TXT_8349B3F8_G_(ctx, base); }

uint64_t Construct_TXT_8349B3FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3FC_G_ = int32_t(0x8349B3FC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B3FC_G__address = int32_t(0x832A5F10);
	if (!UseLiftedCode(143, 0x8325F088)) { __imp__sub_8325F088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B3FC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3FC_G__address);
}
PROMOTED_ENTRY(143, sub_8325F088, 0x8325F088) { ctx.r3.u64 = Construct_TXT_8349B3FC_G_(ctx, base); }

uint64_t Construct_TXT_8349B400_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B400_G_ = int32_t(0x8349B400);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B400_G__address = int32_t(0x832A5F20);
	if (!UseLiftedCode(143, 0x8325F0C8)) { __imp__sub_8325F0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B400_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B400_G__address);
}
PROMOTED_ENTRY(143, sub_8325F0C8, 0x8325F0C8) { ctx.r3.u64 = Construct_TXT_8349B400_G_(ctx, base); }

uint64_t Construct_TXT_8349B404_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B404_G_ = int32_t(0x8349B404);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B404_G__address = int32_t(0x832A5F30);
	if (!UseLiftedCode(143, 0x8325F108)) { __imp__sub_8325F108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B404_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B404_G__address);
}
PROMOTED_ENTRY(143, sub_8325F108, 0x8325F108) { ctx.r3.u64 = Construct_TXT_8349B404_G_(ctx, base); }

uint64_t Construct_TXT_8349B4E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B4E4_G_ = int32_t(0x8349B4E4);
	constexpr int32_t str_TXT_820B7768_B_ = int32_t(0x820B7768);
	constexpr int32_t Destroy_TXT_8349B4E4_G__address = int32_t(0x832A6010);
	if (!UseLiftedCode(143, 0x8325FCD8)) { __imp__sub_8325FCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FCD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B4E4_G_, str_TXT_820B7768_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B4E4_G__address);
}
PROMOTED_ENTRY(143, sub_8325FCD8, 0x8325FCD8) { ctx.r3.u64 = Construct_TXT_8349B4E4_G_(ctx, base); }

uint64_t n_sub_8325FDD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B500_G_ = int32_t(0x8349B500);
	constexpr int32_t str_TXT_820D15C4_B_ = int32_t(0x820D15C4);
	constexpr int32_t Destroy_TXT_8349B500_G__address = int32_t(0x832A60F0);
	if (!UseLiftedCode(143, 0x8325FDD8)) { __imp__sub_8325FDD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FDD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B500_G_, str_TXT_820D15C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B500_G__address);
}
PROMOTED_ENTRY(143, sub_8325FDD8, 0x8325FDD8) { ctx.r3.u64 = n_sub_8325FDD8(ctx, base); }

uint64_t n_sub_8325FE18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B504_G_ = int32_t(0x8349B504);
	constexpr int32_t str_TXT_820D5508_B_ = int32_t(0x820D5508);
	constexpr int32_t Destroy_TXT_8349B504_G__address = int32_t(0x832A6100);
	if (!UseLiftedCode(143, 0x8325FE18)) { __imp__sub_8325FE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B504_G_, str_TXT_820D5508_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B504_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE18, 0x8325FE18) { ctx.r3.u64 = n_sub_8325FE18(ctx, base); }

uint64_t n_sub_8325FE58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B508_G_ = int32_t(0x8349B508);
	constexpr int32_t str_TXT_820D5520_B_ = int32_t(0x820D5520);
	constexpr int32_t Destroy_TXT_8349B508_G__address = int32_t(0x832A6110);
	if (!UseLiftedCode(143, 0x8325FE58)) { __imp__sub_8325FE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B508_G_, str_TXT_820D5520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B508_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE58, 0x8325FE58) { ctx.r3.u64 = n_sub_8325FE58(ctx, base); }

uint64_t n_sub_8325FE98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B50C_G_ = int32_t(0x8349B50C);
	constexpr int32_t str_TXT_820D5538_B_ = int32_t(0x820D5538);
	constexpr int32_t Destroy_TXT_8349B50C_G__address = int32_t(0x832A6120);
	if (!UseLiftedCode(143, 0x8325FE98)) { __imp__sub_8325FE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B50C_G_, str_TXT_820D5538_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B50C_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE98, 0x8325FE98) { ctx.r3.u64 = n_sub_8325FE98(ctx, base); }

uint64_t n_sub_8325FED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B510_G_ = int32_t(0x8349B510);
	constexpr int32_t str_TXT_820D5550_B_ = int32_t(0x820D5550);
	constexpr int32_t Destroy_TXT_8349B510_G__address = int32_t(0x832A6130);
	if (!UseLiftedCode(143, 0x8325FED8)) { __imp__sub_8325FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B510_G_, str_TXT_820D5550_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B510_G__address);
}
PROMOTED_ENTRY(143, sub_8325FED8, 0x8325FED8) { ctx.r3.u64 = n_sub_8325FED8(ctx, base); }

uint64_t n_sub_8325FF18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B514_G_ = int32_t(0x8349B514);
	constexpr int32_t str_TXT_820D5574_B_ = int32_t(0x820D5574);
	constexpr int32_t Destroy_TXT_8349B514_G__address = int32_t(0x832A6140);
	if (!UseLiftedCode(143, 0x8325FF18)) { __imp__sub_8325FF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FF18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B514_G_, str_TXT_820D5574_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B514_G__address);
}
PROMOTED_ENTRY(143, sub_8325FF18, 0x8325FF18) { ctx.r3.u64 = n_sub_8325FF18(ctx, base); }
