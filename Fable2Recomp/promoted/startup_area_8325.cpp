// Start-up initialisers of global objects (they register property and definition names) at
// 0x8325xxxx, as readable C++.
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

uint64_t InitGlobalString_83498614(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_83498614 = int32_t(0x83498614);
	constexpr int32_t n_sub_832A3238_address = int32_t(0x832A3238);
	if (!UseLiftedCode(143, 0x83250530)) { __imp__sub_83250530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498614, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832A3238_address);
}
PROMOTED_ENTRY(143, sub_83250530, 0x83250530) { ctx.r3.u64 = InitGlobalString_83498614(ctx, base); }

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

uint64_t HashName_TXT_820A2CE0_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__9 = 0x83498630u;
	if (!UseLiftedCode(143, 0x83250668)) { __imp__sub_83250668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250668, 0x83250668) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__9(ctx, base); }

uint64_t HashName_TXT_820BE3B8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BE3B8_B_ = int32_t(0x820BE3B8);
	constexpr uint32_t g_HashOf_TXT_820BE3B8_B_ = 0x83498634u;
	if (!UseLiftedCode(143, 0x832506A0)) { __imp__sub_832506A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832506A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BE3B8_B_);
	STORE32(g_HashOf_TXT_820BE3B8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832506A0, 0x832506A0) { ctx.r3.u64 = HashName_TXT_820BE3B8_B_(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__9 = 0x83498638u;
	if (!UseLiftedCode(143, 0x832506D8)) { __imp__sub_832506D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832506D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832506D8, 0x832506D8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__9(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__9 = 0x8349863Cu;
	if (!UseLiftedCode(143, 0x83250710)) { __imp__sub_83250710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250710);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250710, 0x83250710) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__9(ctx, base); }

uint64_t HashName_TXT_820BE3D0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BE3D0_B_ = int32_t(0x820BE3D0);
	constexpr uint32_t g_HashOf_TXT_820BE3D0_B_ = 0x83498640u;
	if (!UseLiftedCode(143, 0x83250748)) { __imp__sub_83250748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250748);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BE3D0_B_);
	STORE32(g_HashOf_TXT_820BE3D0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250748, 0x83250748) { ctx.r3.u64 = HashName_TXT_820BE3D0_B_(ctx, base); }

uint64_t HashName_TXT_820BE3E8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BE3E8_B_ = int32_t(0x820BE3E8);
	constexpr uint32_t g_HashOf_TXT_820BE3E8_B_ = 0x83498644u;
	if (!UseLiftedCode(143, 0x83250780)) { __imp__sub_83250780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250780);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BE3E8_B_);
	STORE32(g_HashOf_TXT_820BE3E8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250780, 0x83250780) { ctx.r3.u64 = HashName_TXT_820BE3E8_B_(ctx, base); }

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

uint64_t HashName_TXT_820BEE4C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEE4C_B_ = int32_t(0x820BEE4C);
	constexpr uint32_t g_HashOf_TXT_820BEE4C_B_ = 0x834986B8u;
	if (!UseLiftedCode(143, 0x83250A08)) { __imp__sub_83250A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250A08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEE4C_B_);
	STORE32(g_HashOf_TXT_820BEE4C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250A08, 0x83250A08) { ctx.r3.u64 = HashName_TXT_820BEE4C_B_(ctx, base); }

uint64_t HashName_TXT_820BEE5C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEE5C_B_ = int32_t(0x820BEE5C);
	constexpr uint32_t g_HashOf_TXT_820BEE5C_B_ = 0x834986BCu;
	if (!UseLiftedCode(143, 0x83250A40)) { __imp__sub_83250A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250A40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEE5C_B_);
	STORE32(g_HashOf_TXT_820BEE5C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250A40, 0x83250A40) { ctx.r3.u64 = HashName_TXT_820BEE5C_B_(ctx, base); }

uint64_t HashName_TXT_820BEE70_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEE70_B_ = int32_t(0x820BEE70);
	constexpr uint32_t g_HashOf_TXT_820BEE70_B_ = 0x834986C0u;
	if (!UseLiftedCode(143, 0x83250A78)) { __imp__sub_83250A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250A78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEE70_B_);
	STORE32(g_HashOf_TXT_820BEE70_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250A78, 0x83250A78) { ctx.r3.u64 = HashName_TXT_820BEE70_B_(ctx, base); }

uint64_t HashName_TXT_820BEE84_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEE84_B_ = int32_t(0x820BEE84);
	constexpr uint32_t g_HashOf_TXT_820BEE84_B_ = 0x834986C4u;
	if (!UseLiftedCode(143, 0x83250AB0)) { __imp__sub_83250AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEE84_B_);
	STORE32(g_HashOf_TXT_820BEE84_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250AB0, 0x83250AB0) { ctx.r3.u64 = HashName_TXT_820BEE84_B_(ctx, base); }

uint64_t HashName_TXT_820BEE9C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEE9C_B_ = int32_t(0x820BEE9C);
	constexpr uint32_t g_HashOf_TXT_820BEE9C_B_ = 0x834986C8u;
	if (!UseLiftedCode(143, 0x83250AE8)) { __imp__sub_83250AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEE9C_B_);
	STORE32(g_HashOf_TXT_820BEE9C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250AE8, 0x83250AE8) { ctx.r3.u64 = HashName_TXT_820BEE9C_B_(ctx, base); }

uint64_t HashName_TXT_820BEEAC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEEAC_B_ = int32_t(0x820BEEAC);
	constexpr uint32_t g_HashOf_TXT_820BEEAC_B_ = 0x834986CCu;
	if (!UseLiftedCode(143, 0x83250B20)) { __imp__sub_83250B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250B20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEEAC_B_);
	STORE32(g_HashOf_TXT_820BEEAC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250B20, 0x83250B20) { ctx.r3.u64 = HashName_TXT_820BEEAC_B_(ctx, base); }

uint64_t HashName_TXT_820BEEBC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BEEBC_B_ = int32_t(0x820BEEBC);
	constexpr uint32_t g_HashOf_TXT_820BEEBC_B_ = 0x834986D0u;
	if (!UseLiftedCode(143, 0x83250B58)) { __imp__sub_83250B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250B58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BEEBC_B_);
	STORE32(g_HashOf_TXT_820BEEBC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250B58, 0x83250B58) { ctx.r3.u64 = HashName_TXT_820BEEBC_B_(ctx, base); }

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

uint64_t HashName_TXT_820A89CC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A89CC_B_ = int32_t(0x820A89CC);
	constexpr uint32_t g_HashOf_TXT_820A89CC_B__2 = 0x834986F0u;
	if (!UseLiftedCode(143, 0x83250D50)) { __imp__sub_83250D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250D50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A89CC_B_);
	STORE32(g_HashOf_TXT_820A89CC_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83250D50, 0x83250D50) { ctx.r3.u64 = HashName_TXT_820A89CC_B__2(ctx, base); }

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

uint64_t InitGlobalString_83498700(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83498700 = int32_t(0x83498700);
	constexpr int32_t n_sub_832A33F0_address = int32_t(0x832A33F0);
	if (!UseLiftedCode(143, 0x83250E48)) { __imp__sub_83250E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498700, (int64_t)str_TXT_820B0000_B_ + 11652, -1);
	return RegisterAtExit(ctx, base, n_sub_832A33F0_address);
}
PROMOTED_ENTRY(143, sub_83250E48, 0x83250E48) { ctx.r3.u64 = InitGlobalString_83498700(ctx, base); }

uint64_t InitGlobalString_83498704(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_83498704 = int32_t(0x83498704);
	constexpr int32_t n_sub_832A3400_address = int32_t(0x832A3400);
	if (!UseLiftedCode(143, 0x83250E88)) { __imp__sub_83250E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83250E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83498704, (int64_t)str_TXT_820B0000_B_ + 11656, -1);
	return RegisterAtExit(ctx, base, n_sub_832A3400_address);
}
PROMOTED_ENTRY(143, sub_83250E88, 0x83250E88) { ctx.r3.u64 = InitGlobalString_83498704(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__9 = 0x83498890u;
	if (!UseLiftedCode(143, 0x83252748)) { __imp__sub_83252748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252748);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252748, 0x83252748) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__9(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__10 = 0x83498894u;
	if (!UseLiftedCode(143, 0x83252780)) { __imp__sub_83252780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252780);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252780, 0x83252780) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__10(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__9 = 0x83498898u;
	if (!UseLiftedCode(143, 0x832527B8)) { __imp__sub_832527B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832527B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832527B8, 0x832527B8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__9 = 0x8349889Cu;
	if (!UseLiftedCode(143, 0x832527F0)) { __imp__sub_832527F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832527F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832527F0, 0x832527F0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__9 = 0x834988A0u;
	if (!UseLiftedCode(143, 0x83252828)) { __imp__sub_83252828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252828);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252828, 0x83252828) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__9 = 0x834988A4u;
	if (!UseLiftedCode(143, 0x83252860)) { __imp__sub_83252860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252860);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252860, 0x83252860) { ctx.r3.u64 = HashName_TXT_820A2C34_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__9 = 0x834988A8u;
	if (!UseLiftedCode(143, 0x83252898)) { __imp__sub_83252898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252898);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252898, 0x83252898) { ctx.r3.u64 = HashName_TXT_820A2C44_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__9 = 0x834988ACu;
	if (!UseLiftedCode(143, 0x832528D0)) { __imp__sub_832528D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832528D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832528D0, 0x832528D0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__9 = 0x834988B0u;
	if (!UseLiftedCode(143, 0x83252908)) { __imp__sub_83252908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252908);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252908, 0x83252908) { ctx.r3.u64 = HashName_TXT_820A2C74_B__9(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__9 = 0x834988B4u;
	if (!UseLiftedCode(143, 0x83252940)) { __imp__sub_83252940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252940);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252940, 0x83252940) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__9 = 0x834988B8u;
	if (!UseLiftedCode(143, 0x83252978)) { __imp__sub_83252978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252978);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252978, 0x83252978) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__9(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__9 = 0x834988BCu;
	if (!UseLiftedCode(143, 0x832529B0)) { __imp__sub_832529B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832529B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832529B0, 0x832529B0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__9(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__9 = 0x834988C0u;
	if (!UseLiftedCode(143, 0x832529E8)) { __imp__sub_832529E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832529E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832529E8, 0x832529E8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__9(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__10 = 0x834988C4u;
	if (!UseLiftedCode(143, 0x83252A20)) { __imp__sub_83252A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252A20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252A20, 0x83252A20) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__10 = 0x834988C8u;
	if (!UseLiftedCode(143, 0x83252A58)) { __imp__sub_83252A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252A58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252A58, 0x83252A58) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__9 = 0x834988CCu;
	if (!UseLiftedCode(143, 0x83252A90)) { __imp__sub_83252A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252A90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252A90, 0x83252A90) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__9(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__9 = 0x834988D0u;
	if (!UseLiftedCode(143, 0x83252AC8)) { __imp__sub_83252AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252AC8, 0x83252AC8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__9 = 0x834988D4u;
	if (!UseLiftedCode(143, 0x83252B00)) { __imp__sub_83252B00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252B00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252B00, 0x83252B00) { ctx.r3.u64 = HashName_TXT_820A2D24_B__9(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__9 = 0x834988D8u;
	if (!UseLiftedCode(143, 0x83252B38)) { __imp__sub_83252B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252B38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252B38, 0x83252B38) { ctx.r3.u64 = HashName_TXT_820A2D30_B__9(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__9 = 0x834988DCu;
	if (!UseLiftedCode(143, 0x83252B70)) { __imp__sub_83252B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252B70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252B70, 0x83252B70) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__9(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__9(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__9 = 0x834988E0u;
	if (!UseLiftedCode(143, 0x83252BA8)) { __imp__sub_83252BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252BA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__9, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252BA8, 0x83252BA8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__9(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__10 = 0x83498908u;
	if (!UseLiftedCode(143, 0x83252E20)) { __imp__sub_83252E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252E20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252E20, 0x83252E20) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__10(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__11 = 0x8349890Cu;
	if (!UseLiftedCode(143, 0x83252E58)) { __imp__sub_83252E58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252E58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252E58, 0x83252E58) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__11(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__10 = 0x83498910u;
	if (!UseLiftedCode(143, 0x83252E90)) { __imp__sub_83252E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252E90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252E90, 0x83252E90) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__10 = 0x83498914u;
	if (!UseLiftedCode(143, 0x83252EC8)) { __imp__sub_83252EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252EC8, 0x83252EC8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__10 = 0x83498918u;
	if (!UseLiftedCode(143, 0x83252F00)) { __imp__sub_83252F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252F00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252F00, 0x83252F00) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__10 = 0x8349891Cu;
	if (!UseLiftedCode(143, 0x83252F38)) { __imp__sub_83252F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252F38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252F38, 0x83252F38) { ctx.r3.u64 = HashName_TXT_820A2C34_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__10 = 0x83498920u;
	if (!UseLiftedCode(143, 0x83252F70)) { __imp__sub_83252F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252F70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252F70, 0x83252F70) { ctx.r3.u64 = HashName_TXT_820A2C44_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__10 = 0x83498924u;
	if (!UseLiftedCode(143, 0x83252FA8)) { __imp__sub_83252FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252FA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252FA8, 0x83252FA8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__10 = 0x83498928u;
	if (!UseLiftedCode(143, 0x83252FE0)) { __imp__sub_83252FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83252FE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83252FE0, 0x83252FE0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__10(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__10 = 0x8349892Cu;
	if (!UseLiftedCode(143, 0x83253018)) { __imp__sub_83253018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253018);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253018, 0x83253018) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__10 = 0x83498930u;
	if (!UseLiftedCode(143, 0x83253050)) { __imp__sub_83253050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253050);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253050, 0x83253050) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__10 = 0x83498934u;
	if (!UseLiftedCode(143, 0x83253088)) { __imp__sub_83253088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253088);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253088, 0x83253088) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__10 = 0x83498938u;
	if (!UseLiftedCode(143, 0x832530C0)) { __imp__sub_832530C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832530C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832530C0, 0x832530C0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__10(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__11 = 0x8349893Cu;
	if (!UseLiftedCode(143, 0x832530F8)) { __imp__sub_832530F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832530F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832530F8, 0x832530F8) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__11 = 0x83498940u;
	if (!UseLiftedCode(143, 0x83253130)) { __imp__sub_83253130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253130, 0x83253130) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__10 = 0x83498944u;
	if (!UseLiftedCode(143, 0x83253168)) { __imp__sub_83253168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253168, 0x83253168) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__10(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__10 = 0x83498948u;
	if (!UseLiftedCode(143, 0x832531A0)) { __imp__sub_832531A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832531A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832531A0, 0x832531A0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__10 = 0x8349894Cu;
	if (!UseLiftedCode(143, 0x832531D8)) { __imp__sub_832531D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832531D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832531D8, 0x832531D8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__10(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__10 = 0x83498950u;
	if (!UseLiftedCode(143, 0x83253210)) { __imp__sub_83253210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253210, 0x83253210) { ctx.r3.u64 = HashName_TXT_820A2D30_B__10(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__10 = 0x83498954u;
	if (!UseLiftedCode(143, 0x83253248)) { __imp__sub_83253248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253248, 0x83253248) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__10(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__10 = 0x83498958u;
	if (!UseLiftedCode(143, 0x83253280)) { __imp__sub_83253280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__10, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253280, 0x83253280) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__10(ctx, base); }

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
uint64_t PhotoModeDialogBoxMessageGroupMessage_Init(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498960_G_ = int32_t(0x83498960);
	constexpr int32_t str_TXT_820C02A8_B_ = int32_t(0x820C02A8);
	constexpr int32_t Destroy_TXT_83498960_G__address = int32_t(0x832A3AD0);
	if (!UseLiftedCode(143, 0x832532F8)) { __imp__sub_832532F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832532F8);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (RegisterAtExit is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498960_G_, str_TXT_820C02A8_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83498960_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832532F8, 0x832532F8) { ctx.r3.u64 = PhotoModeDialogBoxMessageGroupMessage_Init(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__11 = 0x834989E8u;
	if (!UseLiftedCode(143, 0x83253668)) { __imp__sub_83253668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253668, 0x83253668) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__11(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__12 = 0x834989ECu;
	if (!UseLiftedCode(143, 0x832536A0)) { __imp__sub_832536A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832536A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832536A0, 0x832536A0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__12(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__11 = 0x834989F0u;
	if (!UseLiftedCode(143, 0x832536D8)) { __imp__sub_832536D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832536D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832536D8, 0x832536D8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__11 = 0x834989F4u;
	if (!UseLiftedCode(143, 0x83253710)) { __imp__sub_83253710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253710);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253710, 0x83253710) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__11 = 0x834989F8u;
	if (!UseLiftedCode(143, 0x83253748)) { __imp__sub_83253748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253748);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253748, 0x83253748) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__11 = 0x834989FCu;
	if (!UseLiftedCode(143, 0x83253780)) { __imp__sub_83253780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253780);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253780, 0x83253780) { ctx.r3.u64 = HashName_TXT_820A2C34_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__11 = 0x83498A00u;
	if (!UseLiftedCode(143, 0x832537B8)) { __imp__sub_832537B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832537B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832537B8, 0x832537B8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__11 = 0x83498A04u;
	if (!UseLiftedCode(143, 0x832537F0)) { __imp__sub_832537F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832537F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832537F0, 0x832537F0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__11 = 0x83498A08u;
	if (!UseLiftedCode(143, 0x83253828)) { __imp__sub_83253828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253828);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253828, 0x83253828) { ctx.r3.u64 = HashName_TXT_820A2C74_B__11(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__11 = 0x83498A0Cu;
	if (!UseLiftedCode(143, 0x83253860)) { __imp__sub_83253860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253860);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253860, 0x83253860) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__11 = 0x83498A10u;
	if (!UseLiftedCode(143, 0x83253898)) { __imp__sub_83253898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253898);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253898, 0x83253898) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__11 = 0x83498A14u;
	if (!UseLiftedCode(143, 0x832538D0)) { __imp__sub_832538D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832538D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832538D0, 0x832538D0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__11 = 0x83498A18u;
	if (!UseLiftedCode(143, 0x83253908)) { __imp__sub_83253908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253908);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253908, 0x83253908) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__11(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__12 = 0x83498A1Cu;
	if (!UseLiftedCode(143, 0x83253940)) { __imp__sub_83253940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253940);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253940, 0x83253940) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__12 = 0x83498A20u;
	if (!UseLiftedCode(143, 0x83253978)) { __imp__sub_83253978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253978);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253978, 0x83253978) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__11 = 0x83498A24u;
	if (!UseLiftedCode(143, 0x832539B0)) { __imp__sub_832539B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832539B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832539B0, 0x832539B0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__11(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__11 = 0x83498A28u;
	if (!UseLiftedCode(143, 0x832539E8)) { __imp__sub_832539E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832539E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832539E8, 0x832539E8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__11 = 0x83498A2Cu;
	if (!UseLiftedCode(143, 0x83253A20)) { __imp__sub_83253A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253A20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253A20, 0x83253A20) { ctx.r3.u64 = HashName_TXT_820A2D24_B__11(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__11 = 0x83498A30u;
	if (!UseLiftedCode(143, 0x83253A58)) { __imp__sub_83253A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253A58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253A58, 0x83253A58) { ctx.r3.u64 = HashName_TXT_820A2D30_B__11(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__11 = 0x83498A34u;
	if (!UseLiftedCode(143, 0x83253A90)) { __imp__sub_83253A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253A90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253A90, 0x83253A90) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__11(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__11(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__11 = 0x83498A38u;
	if (!UseLiftedCode(143, 0x83253AC8)) { __imp__sub_83253AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__11, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253AC8, 0x83253AC8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__11(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__12 = 0x83498A68u;
	if (!UseLiftedCode(143, 0x83253DC0)) { __imp__sub_83253DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253DC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253DC0, 0x83253DC0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__12(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__13 = 0x83498A6Cu;
	if (!UseLiftedCode(143, 0x83253DF8)) { __imp__sub_83253DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253DF8, 0x83253DF8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__13(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__12 = 0x83498A70u;
	if (!UseLiftedCode(143, 0x83253E30)) { __imp__sub_83253E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253E30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253E30, 0x83253E30) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__12 = 0x83498A74u;
	if (!UseLiftedCode(143, 0x83253E68)) { __imp__sub_83253E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253E68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253E68, 0x83253E68) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__12 = 0x83498A78u;
	if (!UseLiftedCode(143, 0x83253EA0)) { __imp__sub_83253EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253EA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253EA0, 0x83253EA0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__12 = 0x83498A7Cu;
	if (!UseLiftedCode(143, 0x83253ED8)) { __imp__sub_83253ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253ED8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253ED8, 0x83253ED8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__12 = 0x83498A80u;
	if (!UseLiftedCode(143, 0x83253F10)) { __imp__sub_83253F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253F10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253F10, 0x83253F10) { ctx.r3.u64 = HashName_TXT_820A2C44_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__12 = 0x83498A84u;
	if (!UseLiftedCode(143, 0x83253F48)) { __imp__sub_83253F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253F48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253F48, 0x83253F48) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__12 = 0x83498A88u;
	if (!UseLiftedCode(143, 0x83253F80)) { __imp__sub_83253F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253F80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253F80, 0x83253F80) { ctx.r3.u64 = HashName_TXT_820A2C74_B__12(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__12 = 0x83498A8Cu;
	if (!UseLiftedCode(143, 0x83253FB8)) { __imp__sub_83253FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253FB8, 0x83253FB8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__12 = 0x83498A90u;
	if (!UseLiftedCode(143, 0x83253FF0)) { __imp__sub_83253FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83253FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83253FF0, 0x83253FF0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__12 = 0x83498A94u;
	if (!UseLiftedCode(143, 0x83254028)) { __imp__sub_83254028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254028);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254028, 0x83254028) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__12 = 0x83498A98u;
	if (!UseLiftedCode(143, 0x83254060)) { __imp__sub_83254060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254060);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254060, 0x83254060) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__12(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__13 = 0x83498A9Cu;
	if (!UseLiftedCode(143, 0x83254098)) { __imp__sub_83254098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254098);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254098, 0x83254098) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__13 = 0x83498AA0u;
	if (!UseLiftedCode(143, 0x832540D0)) { __imp__sub_832540D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832540D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832540D0, 0x832540D0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__12 = 0x83498AA4u;
	if (!UseLiftedCode(143, 0x83254108)) { __imp__sub_83254108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254108);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254108, 0x83254108) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__12(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__12 = 0x83498AA8u;
	if (!UseLiftedCode(143, 0x83254140)) { __imp__sub_83254140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254140);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254140, 0x83254140) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__12 = 0x83498AACu;
	if (!UseLiftedCode(143, 0x83254178)) { __imp__sub_83254178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254178);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254178, 0x83254178) { ctx.r3.u64 = HashName_TXT_820A2D24_B__12(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__12 = 0x83498AB0u;
	if (!UseLiftedCode(143, 0x832541B0)) { __imp__sub_832541B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832541B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832541B0, 0x832541B0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__12(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__12 = 0x83498AB4u;
	if (!UseLiftedCode(143, 0x832541E8)) { __imp__sub_832541E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832541E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832541E8, 0x832541E8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__12(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__12(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__12 = 0x83498AB8u;
	if (!UseLiftedCode(143, 0x83254220)) { __imp__sub_83254220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254220);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__12, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254220, 0x83254220) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__12(ctx, base); }

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

uint64_t HashName_TXT_820C0560_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0560_B_ = int32_t(0x820C0560);
	constexpr uint32_t g_HashOf_TXT_820C0560_B_ = 0x83498ADCu;
	if (!UseLiftedCode(143, 0x83254458)) { __imp__sub_83254458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254458);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0560_B_);
	STORE32(g_HashOf_TXT_820C0560_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254458, 0x83254458) { ctx.r3.u64 = HashName_TXT_820C0560_B_(ctx, base); }

uint64_t HashName_TXT_820C056C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C056C_B_ = int32_t(0x820C056C);
	constexpr uint32_t g_HashOf_TXT_820C056C_B_ = 0x83498AE0u;
	if (!UseLiftedCode(143, 0x83254490)) { __imp__sub_83254490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254490);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C056C_B_);
	STORE32(g_HashOf_TXT_820C056C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254490, 0x83254490) { ctx.r3.u64 = HashName_TXT_820C056C_B_(ctx, base); }

uint64_t HashName_TXT_820C0578_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0578_B_ = int32_t(0x820C0578);
	constexpr uint32_t g_HashOf_TXT_820C0578_B_ = 0x83498AE4u;
	if (!UseLiftedCode(143, 0x832544C8)) { __imp__sub_832544C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832544C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0578_B_);
	STORE32(g_HashOf_TXT_820C0578_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832544C8, 0x832544C8) { ctx.r3.u64 = HashName_TXT_820C0578_B_(ctx, base); }

uint64_t HashName_TXT_820C0584_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0584_B_ = int32_t(0x820C0584);
	constexpr uint32_t g_HashOf_TXT_820C0584_B_ = 0x83498AE8u;
	if (!UseLiftedCode(143, 0x83254500)) { __imp__sub_83254500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254500);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0584_B_);
	STORE32(g_HashOf_TXT_820C0584_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254500, 0x83254500) { ctx.r3.u64 = HashName_TXT_820C0584_B_(ctx, base); }

uint64_t HashName_TXT_820C0590_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0590_B_ = int32_t(0x820C0590);
	constexpr uint32_t g_HashOf_TXT_820C0590_B_ = 0x83498AECu;
	if (!UseLiftedCode(143, 0x83254538)) { __imp__sub_83254538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254538);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0590_B_);
	STORE32(g_HashOf_TXT_820C0590_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254538, 0x83254538) { ctx.r3.u64 = HashName_TXT_820C0590_B_(ctx, base); }

uint64_t HashName_TXT_820C05A0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05A0_B_ = int32_t(0x820C05A0);
	constexpr uint32_t g_HashOf_TXT_820C05A0_B_ = 0x83498AF0u;
	if (!UseLiftedCode(143, 0x83254570)) { __imp__sub_83254570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254570);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05A0_B_);
	STORE32(g_HashOf_TXT_820C05A0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254570, 0x83254570) { ctx.r3.u64 = HashName_TXT_820C05A0_B_(ctx, base); }

uint64_t HashName_TXT_820C05B0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05B0_B_ = int32_t(0x820C05B0);
	constexpr uint32_t g_HashOf_TXT_820C05B0_B_ = 0x83498AF4u;
	if (!UseLiftedCode(143, 0x832545A8)) { __imp__sub_832545A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832545A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05B0_B_);
	STORE32(g_HashOf_TXT_820C05B0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832545A8, 0x832545A8) { ctx.r3.u64 = HashName_TXT_820C05B0_B_(ctx, base); }

uint64_t HashName_TXT_820C05C4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05C4_B_ = int32_t(0x820C05C4);
	constexpr uint32_t g_HashOf_TXT_820C05C4_B_ = 0x83498AF8u;
	if (!UseLiftedCode(143, 0x832545E0)) { __imp__sub_832545E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832545E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05C4_B_);
	STORE32(g_HashOf_TXT_820C05C4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832545E0, 0x832545E0) { ctx.r3.u64 = HashName_TXT_820C05C4_B_(ctx, base); }

uint64_t HashName_TXT_820C05D4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05D4_B_ = int32_t(0x820C05D4);
	constexpr uint32_t g_HashOf_TXT_820C05D4_B_ = 0x83498AFCu;
	if (!UseLiftedCode(143, 0x83254618)) { __imp__sub_83254618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254618);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05D4_B_);
	STORE32(g_HashOf_TXT_820C05D4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254618, 0x83254618) { ctx.r3.u64 = HashName_TXT_820C05D4_B_(ctx, base); }

uint64_t HashName_TXT_820C05E0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05E0_B_ = int32_t(0x820C05E0);
	constexpr uint32_t g_HashOf_TXT_820C05E0_B_ = 0x83498B00u;
	if (!UseLiftedCode(143, 0x83254650)) { __imp__sub_83254650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05E0_B_);
	STORE32(g_HashOf_TXT_820C05E0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254650, 0x83254650) { ctx.r3.u64 = HashName_TXT_820C05E0_B_(ctx, base); }

uint64_t HashName_TXT_8200262C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8200262C_B_ = int32_t(0x8200262C);
	constexpr uint32_t g_HashOf_TXT_8200262C_B_ = 0x83498B04u;
	if (!UseLiftedCode(143, 0x83254688)) { __imp__sub_83254688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_8200262C_B_);
	STORE32(g_HashOf_TXT_8200262C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254688, 0x83254688) { ctx.r3.u64 = HashName_TXT_8200262C_B_(ctx, base); }

uint64_t HashName_TXT_820C05EC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05EC_B_ = int32_t(0x820C05EC);
	constexpr uint32_t g_HashOf_TXT_820C05EC_B_ = 0x83498B08u;
	if (!UseLiftedCode(143, 0x832546C0)) { __imp__sub_832546C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832546C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05EC_B_);
	STORE32(g_HashOf_TXT_820C05EC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832546C0, 0x832546C0) { ctx.r3.u64 = HashName_TXT_820C05EC_B_(ctx, base); }

uint64_t HashName_TXT_820A8AD4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A8AD4_B_ = int32_t(0x820A8AD4);
	constexpr uint32_t g_HashOf_TXT_820A8AD4_B_ = 0x83498B0Cu;
	if (!UseLiftedCode(143, 0x832546F8)) { __imp__sub_832546F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832546F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A8AD4_B_);
	STORE32(g_HashOf_TXT_820A8AD4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832546F8, 0x832546F8) { ctx.r3.u64 = HashName_TXT_820A8AD4_B_(ctx, base); }

uint64_t HashName_TXT_820C05F8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C05F8_B_ = int32_t(0x820C05F8);
	constexpr uint32_t g_HashOf_TXT_820C05F8_B_ = 0x83498B10u;
	if (!UseLiftedCode(143, 0x83254730)) { __imp__sub_83254730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C05F8_B_);
	STORE32(g_HashOf_TXT_820C05F8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254730, 0x83254730) { ctx.r3.u64 = HashName_TXT_820C05F8_B_(ctx, base); }

uint64_t HashName_TXT_820A8AEC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A8AEC_B_ = int32_t(0x820A8AEC);
	constexpr uint32_t g_HashOf_TXT_820A8AEC_B_ = 0x83498B14u;
	if (!UseLiftedCode(143, 0x83254768)) { __imp__sub_83254768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A8AEC_B_);
	STORE32(g_HashOf_TXT_820A8AEC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254768, 0x83254768) { ctx.r3.u64 = HashName_TXT_820A8AEC_B_(ctx, base); }

uint64_t HashName_TXT_820C0604_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0604_B_ = int32_t(0x820C0604);
	constexpr uint32_t g_HashOf_TXT_820C0604_B_ = 0x83498B18u;
	if (!UseLiftedCode(143, 0x832547A0)) { __imp__sub_832547A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832547A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0604_B_);
	STORE32(g_HashOf_TXT_820C0604_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832547A0, 0x832547A0) { ctx.r3.u64 = HashName_TXT_820C0604_B_(ctx, base); }

uint64_t HashName_TXT_820C0614_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0614_B_ = int32_t(0x820C0614);
	constexpr uint32_t g_HashOf_TXT_820C0614_B_ = 0x83498B1Cu;
	if (!UseLiftedCode(143, 0x832547D8)) { __imp__sub_832547D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832547D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0614_B_);
	STORE32(g_HashOf_TXT_820C0614_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832547D8, 0x832547D8) { ctx.r3.u64 = HashName_TXT_820C0614_B_(ctx, base); }

uint64_t HashName_TXT_820C061C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C061C_B_ = int32_t(0x820C061C);
	constexpr uint32_t g_HashOf_TXT_820C061C_B_ = 0x83498B20u;
	if (!UseLiftedCode(143, 0x83254810)) { __imp__sub_83254810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C061C_B_);
	STORE32(g_HashOf_TXT_820C061C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254810, 0x83254810) { ctx.r3.u64 = HashName_TXT_820C061C_B_(ctx, base); }

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

uint64_t HashName_TXT_820C0994_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0994_B_ = int32_t(0x820C0994);
	constexpr uint32_t g_HashOf_TXT_820C0994_B_ = 0x83498B58u;
	if (!UseLiftedCode(143, 0x83254B88)) { __imp__sub_83254B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254B88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C0994_B_);
	STORE32(g_HashOf_TXT_820C0994_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254B88, 0x83254B88) { ctx.r3.u64 = HashName_TXT_820C0994_B_(ctx, base); }

uint64_t HashName_TXT_820C09A4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C09A4_B_ = int32_t(0x820C09A4);
	constexpr uint32_t g_HashOf_TXT_820C09A4_B_ = 0x83498B5Cu;
	if (!UseLiftedCode(143, 0x83254BC0)) { __imp__sub_83254BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83254BC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C09A4_B_);
	STORE32(g_HashOf_TXT_820C09A4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83254BC0, 0x83254BC0) { ctx.r3.u64 = HashName_TXT_820C09A4_B_(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__13 = 0x83498BD0u;
	if (!UseLiftedCode(143, 0x832552F8)) { __imp__sub_832552F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832552F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832552F8, 0x832552F8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__13(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__14 = 0x83498BD4u;
	if (!UseLiftedCode(143, 0x83255330)) { __imp__sub_83255330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255330);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255330, 0x83255330) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__14(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__13 = 0x83498BD8u;
	if (!UseLiftedCode(143, 0x83255368)) { __imp__sub_83255368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255368);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255368, 0x83255368) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__13 = 0x83498BDCu;
	if (!UseLiftedCode(143, 0x832553A0)) { __imp__sub_832553A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832553A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832553A0, 0x832553A0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__13 = 0x83498BE0u;
	if (!UseLiftedCode(143, 0x832553D8)) { __imp__sub_832553D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832553D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832553D8, 0x832553D8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__13 = 0x83498BE4u;
	if (!UseLiftedCode(143, 0x83255410)) { __imp__sub_83255410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255410);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255410, 0x83255410) { ctx.r3.u64 = HashName_TXT_820A2C34_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__13 = 0x83498BE8u;
	if (!UseLiftedCode(143, 0x83255448)) { __imp__sub_83255448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255448);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255448, 0x83255448) { ctx.r3.u64 = HashName_TXT_820A2C44_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__13 = 0x83498BECu;
	if (!UseLiftedCode(143, 0x83255480)) { __imp__sub_83255480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255480);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255480, 0x83255480) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__13 = 0x83498BF0u;
	if (!UseLiftedCode(143, 0x832554B8)) { __imp__sub_832554B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832554B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832554B8, 0x832554B8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__13(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__13 = 0x83498BF4u;
	if (!UseLiftedCode(143, 0x832554F0)) { __imp__sub_832554F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832554F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832554F0, 0x832554F0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__13 = 0x83498BF8u;
	if (!UseLiftedCode(143, 0x83255528)) { __imp__sub_83255528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255528);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255528, 0x83255528) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__13 = 0x83498BFCu;
	if (!UseLiftedCode(143, 0x83255560)) { __imp__sub_83255560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255560);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255560, 0x83255560) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__13 = 0x83498C00u;
	if (!UseLiftedCode(143, 0x83255598)) { __imp__sub_83255598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255598);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255598, 0x83255598) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__13(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__14 = 0x83498C04u;
	if (!UseLiftedCode(143, 0x832555D0)) { __imp__sub_832555D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832555D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832555D0, 0x832555D0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__14 = 0x83498C08u;
	if (!UseLiftedCode(143, 0x83255608)) { __imp__sub_83255608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255608);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255608, 0x83255608) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__13 = 0x83498C0Cu;
	if (!UseLiftedCode(143, 0x83255640)) { __imp__sub_83255640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255640);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255640, 0x83255640) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__13(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__13 = 0x83498C10u;
	if (!UseLiftedCode(143, 0x83255678)) { __imp__sub_83255678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255678);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255678, 0x83255678) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__13 = 0x83498C14u;
	if (!UseLiftedCode(143, 0x832556B0)) { __imp__sub_832556B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832556B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832556B0, 0x832556B0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__13(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__13 = 0x83498C18u;
	if (!UseLiftedCode(143, 0x832556E8)) { __imp__sub_832556E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832556E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832556E8, 0x832556E8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__13(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__13 = 0x83498C1Cu;
	if (!UseLiftedCode(143, 0x83255720)) { __imp__sub_83255720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255720);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255720, 0x83255720) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__13(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__13(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__13 = 0x83498C20u;
	if (!UseLiftedCode(143, 0x83255758)) { __imp__sub_83255758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255758);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__13, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255758, 0x83255758) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__13(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__14 = 0x83498C40u;
	if (!UseLiftedCode(143, 0x83255950)) { __imp__sub_83255950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255950);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255950, 0x83255950) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__14(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__15 = 0x83498C44u;
	if (!UseLiftedCode(143, 0x83255988)) { __imp__sub_83255988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255988);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255988, 0x83255988) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__15(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__14 = 0x83498C48u;
	if (!UseLiftedCode(143, 0x832559C0)) { __imp__sub_832559C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832559C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832559C0, 0x832559C0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__14 = 0x83498C4Cu;
	if (!UseLiftedCode(143, 0x832559F8)) { __imp__sub_832559F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832559F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832559F8, 0x832559F8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__14 = 0x83498C50u;
	if (!UseLiftedCode(143, 0x83255A30)) { __imp__sub_83255A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255A30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255A30, 0x83255A30) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__14 = 0x83498C54u;
	if (!UseLiftedCode(143, 0x83255A68)) { __imp__sub_83255A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255A68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255A68, 0x83255A68) { ctx.r3.u64 = HashName_TXT_820A2C34_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__14 = 0x83498C58u;
	if (!UseLiftedCode(143, 0x83255AA0)) { __imp__sub_83255AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255AA0, 0x83255AA0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__14 = 0x83498C5Cu;
	if (!UseLiftedCode(143, 0x83255AD8)) { __imp__sub_83255AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255AD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255AD8, 0x83255AD8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__14 = 0x83498C60u;
	if (!UseLiftedCode(143, 0x83255B10)) { __imp__sub_83255B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255B10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255B10, 0x83255B10) { ctx.r3.u64 = HashName_TXT_820A2C74_B__14(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__14 = 0x83498C64u;
	if (!UseLiftedCode(143, 0x83255B48)) { __imp__sub_83255B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255B48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255B48, 0x83255B48) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__14 = 0x83498C68u;
	if (!UseLiftedCode(143, 0x83255B80)) { __imp__sub_83255B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255B80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255B80, 0x83255B80) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__14 = 0x83498C6Cu;
	if (!UseLiftedCode(143, 0x83255BB8)) { __imp__sub_83255BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255BB8, 0x83255BB8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__14 = 0x83498C70u;
	if (!UseLiftedCode(143, 0x83255BF0)) { __imp__sub_83255BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255BF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255BF0, 0x83255BF0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__14(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__15 = 0x83498C74u;
	if (!UseLiftedCode(143, 0x83255C28)) { __imp__sub_83255C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255C28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255C28, 0x83255C28) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__15 = 0x83498C78u;
	if (!UseLiftedCode(143, 0x83255C60)) { __imp__sub_83255C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255C60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255C60, 0x83255C60) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__14 = 0x83498C7Cu;
	if (!UseLiftedCode(143, 0x83255C98)) { __imp__sub_83255C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255C98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255C98, 0x83255C98) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__14(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__14 = 0x83498C80u;
	if (!UseLiftedCode(143, 0x83255CD0)) { __imp__sub_83255CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255CD0, 0x83255CD0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__14 = 0x83498C84u;
	if (!UseLiftedCode(143, 0x83255D08)) { __imp__sub_83255D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255D08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255D08, 0x83255D08) { ctx.r3.u64 = HashName_TXT_820A2D24_B__14(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__14 = 0x83498C88u;
	if (!UseLiftedCode(143, 0x83255D40)) { __imp__sub_83255D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255D40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255D40, 0x83255D40) { ctx.r3.u64 = HashName_TXT_820A2D30_B__14(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__14 = 0x83498C8Cu;
	if (!UseLiftedCode(143, 0x83255D78)) { __imp__sub_83255D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255D78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255D78, 0x83255D78) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__14(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__14(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__14 = 0x83498C90u;
	if (!UseLiftedCode(143, 0x83255DB0)) { __imp__sub_83255DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__14, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255DB0, 0x83255DB0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__14(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__15 = 0x83498CA0u;
	if (!UseLiftedCode(143, 0x83255EA8)) { __imp__sub_83255EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255EA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255EA8, 0x83255EA8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__15(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__16 = 0x83498CA4u;
	if (!UseLiftedCode(143, 0x83255EE0)) { __imp__sub_83255EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255EE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255EE0, 0x83255EE0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__16(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__15 = 0x83498CA8u;
	if (!UseLiftedCode(143, 0x83255F18)) { __imp__sub_83255F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255F18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255F18, 0x83255F18) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__15 = 0x83498CACu;
	if (!UseLiftedCode(143, 0x83255F50)) { __imp__sub_83255F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255F50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255F50, 0x83255F50) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__15 = 0x83498CB0u;
	if (!UseLiftedCode(143, 0x83255F88)) { __imp__sub_83255F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255F88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255F88, 0x83255F88) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__15 = 0x83498CB4u;
	if (!UseLiftedCode(143, 0x83255FC0)) { __imp__sub_83255FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255FC0, 0x83255FC0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__15 = 0x83498CB8u;
	if (!UseLiftedCode(143, 0x83255FF8)) { __imp__sub_83255FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83255FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83255FF8, 0x83255FF8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__15 = 0x83498CBCu;
	if (!UseLiftedCode(143, 0x83256030)) { __imp__sub_83256030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256030);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256030, 0x83256030) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__15 = 0x83498CC0u;
	if (!UseLiftedCode(143, 0x83256068)) { __imp__sub_83256068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256068);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256068, 0x83256068) { ctx.r3.u64 = HashName_TXT_820A2C74_B__15(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__15 = 0x83498CC4u;
	if (!UseLiftedCode(143, 0x832560A0)) { __imp__sub_832560A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832560A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832560A0, 0x832560A0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__15 = 0x83498CC8u;
	if (!UseLiftedCode(143, 0x832560D8)) { __imp__sub_832560D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832560D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832560D8, 0x832560D8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__15 = 0x83498CCCu;
	if (!UseLiftedCode(143, 0x83256110)) { __imp__sub_83256110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256110);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256110, 0x83256110) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__15 = 0x83498CD0u;
	if (!UseLiftedCode(143, 0x83256148)) { __imp__sub_83256148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256148);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256148, 0x83256148) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__15(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__16 = 0x83498CD4u;
	if (!UseLiftedCode(143, 0x83256180)) { __imp__sub_83256180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256180);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256180, 0x83256180) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__16 = 0x83498CD8u;
	if (!UseLiftedCode(143, 0x832561B8)) { __imp__sub_832561B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832561B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832561B8, 0x832561B8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__15 = 0x83498CDCu;
	if (!UseLiftedCode(143, 0x832561F0)) { __imp__sub_832561F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832561F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832561F0, 0x832561F0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__15(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__15 = 0x83498CE0u;
	if (!UseLiftedCode(143, 0x83256228)) { __imp__sub_83256228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256228);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256228, 0x83256228) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__15 = 0x83498CE4u;
	if (!UseLiftedCode(143, 0x83256260)) { __imp__sub_83256260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256260);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256260, 0x83256260) { ctx.r3.u64 = HashName_TXT_820A2D24_B__15(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__15 = 0x83498CE8u;
	if (!UseLiftedCode(143, 0x83256298)) { __imp__sub_83256298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256298);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256298, 0x83256298) { ctx.r3.u64 = HashName_TXT_820A2D30_B__15(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__15 = 0x83498CECu;
	if (!UseLiftedCode(143, 0x832562D0)) { __imp__sub_832562D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832562D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832562D0, 0x832562D0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__15(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__15(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__15 = 0x83498CF0u;
	if (!UseLiftedCode(143, 0x83256308)) { __imp__sub_83256308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256308);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__15, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256308, 0x83256308) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__15(ctx, base); }

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

uint64_t HashName_TXT_820C1324_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C1324_B_ = int32_t(0x820C1324);
	constexpr uint32_t g_HashOf_TXT_820C1324_B_ = 0x83498CFCu;
	if (!UseLiftedCode(143, 0x832563C0)) { __imp__sub_832563C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832563C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C1324_B_);
	STORE32(g_HashOf_TXT_820C1324_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832563C0, 0x832563C0) { ctx.r3.u64 = HashName_TXT_820C1324_B_(ctx, base); }

uint64_t HashName_TXT_820C1680_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C1680_B_ = int32_t(0x820C1680);
	constexpr uint32_t g_HashOf_TXT_820C1680_B_ = 0x83498D00u;
	if (!UseLiftedCode(143, 0x832563F8)) { __imp__sub_832563F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832563F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C1680_B_);
	STORE32(g_HashOf_TXT_820C1680_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832563F8, 0x832563F8) { ctx.r3.u64 = HashName_TXT_820C1680_B_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__16 = 0x83498D04u;
	if (!UseLiftedCode(143, 0x83256430)) { __imp__sub_83256430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256430);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256430, 0x83256430) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__16(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__17 = 0x83498D08u;
	if (!UseLiftedCode(143, 0x83256468)) { __imp__sub_83256468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256468);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256468, 0x83256468) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__17(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__16 = 0x83498D0Cu;
	if (!UseLiftedCode(143, 0x832564A0)) { __imp__sub_832564A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832564A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832564A0, 0x832564A0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__16 = 0x83498D10u;
	if (!UseLiftedCode(143, 0x832564D8)) { __imp__sub_832564D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832564D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832564D8, 0x832564D8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__16 = 0x83498D14u;
	if (!UseLiftedCode(143, 0x83256510)) { __imp__sub_83256510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256510);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256510, 0x83256510) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__16 = 0x83498D18u;
	if (!UseLiftedCode(143, 0x83256548)) { __imp__sub_83256548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256548);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256548, 0x83256548) { ctx.r3.u64 = HashName_TXT_820A2C34_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__16 = 0x83498D1Cu;
	if (!UseLiftedCode(143, 0x83256580)) { __imp__sub_83256580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256580);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256580, 0x83256580) { ctx.r3.u64 = HashName_TXT_820A2C44_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__16 = 0x83498D20u;
	if (!UseLiftedCode(143, 0x832565B8)) { __imp__sub_832565B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832565B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832565B8, 0x832565B8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__16 = 0x83498D24u;
	if (!UseLiftedCode(143, 0x832565F0)) { __imp__sub_832565F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832565F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832565F0, 0x832565F0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__16(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__16 = 0x83498D28u;
	if (!UseLiftedCode(143, 0x83256628)) { __imp__sub_83256628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256628);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256628, 0x83256628) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__16 = 0x83498D2Cu;
	if (!UseLiftedCode(143, 0x83256660)) { __imp__sub_83256660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256660);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256660, 0x83256660) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__16 = 0x83498D30u;
	if (!UseLiftedCode(143, 0x83256698)) { __imp__sub_83256698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256698);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256698, 0x83256698) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__16 = 0x83498D34u;
	if (!UseLiftedCode(143, 0x832566D0)) { __imp__sub_832566D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832566D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832566D0, 0x832566D0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__16(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__17 = 0x83498D38u;
	if (!UseLiftedCode(143, 0x83256708)) { __imp__sub_83256708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256708);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256708, 0x83256708) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__17 = 0x83498D3Cu;
	if (!UseLiftedCode(143, 0x83256740)) { __imp__sub_83256740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256740);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256740, 0x83256740) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__16 = 0x83498D40u;
	if (!UseLiftedCode(143, 0x83256778)) { __imp__sub_83256778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256778);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256778, 0x83256778) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__16(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__16 = 0x83498D44u;
	if (!UseLiftedCode(143, 0x832567B0)) { __imp__sub_832567B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832567B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832567B0, 0x832567B0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__16 = 0x83498D48u;
	if (!UseLiftedCode(143, 0x832567E8)) { __imp__sub_832567E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832567E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832567E8, 0x832567E8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__16(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__16 = 0x83498D4Cu;
	if (!UseLiftedCode(143, 0x83256820)) { __imp__sub_83256820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256820);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256820, 0x83256820) { ctx.r3.u64 = HashName_TXT_820A2D30_B__16(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__16 = 0x83498D50u;
	if (!UseLiftedCode(143, 0x83256858)) { __imp__sub_83256858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256858);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256858, 0x83256858) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__16(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__16(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__16 = 0x83498D54u;
	if (!UseLiftedCode(143, 0x83256890)) { __imp__sub_83256890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256890);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__16, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256890, 0x83256890) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__16(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__17 = 0x83498D60u;
	if (!UseLiftedCode(143, 0x83256948)) { __imp__sub_83256948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256948);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256948, 0x83256948) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__17(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__18 = 0x83498D64u;
	if (!UseLiftedCode(143, 0x83256980)) { __imp__sub_83256980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256980);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256980, 0x83256980) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__18(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__17 = 0x83498D68u;
	if (!UseLiftedCode(143, 0x832569B8)) { __imp__sub_832569B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832569B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832569B8, 0x832569B8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__17 = 0x83498D6Cu;
	if (!UseLiftedCode(143, 0x832569F0)) { __imp__sub_832569F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832569F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832569F0, 0x832569F0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__17 = 0x83498D70u;
	if (!UseLiftedCode(143, 0x83256A28)) { __imp__sub_83256A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256A28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256A28, 0x83256A28) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__17 = 0x83498D74u;
	if (!UseLiftedCode(143, 0x83256A60)) { __imp__sub_83256A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256A60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256A60, 0x83256A60) { ctx.r3.u64 = HashName_TXT_820A2C34_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__17 = 0x83498D78u;
	if (!UseLiftedCode(143, 0x83256A98)) { __imp__sub_83256A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256A98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256A98, 0x83256A98) { ctx.r3.u64 = HashName_TXT_820A2C44_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__17 = 0x83498D7Cu;
	if (!UseLiftedCode(143, 0x83256AD0)) { __imp__sub_83256AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256AD0, 0x83256AD0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__17 = 0x83498D80u;
	if (!UseLiftedCode(143, 0x83256B08)) { __imp__sub_83256B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256B08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256B08, 0x83256B08) { ctx.r3.u64 = HashName_TXT_820A2C74_B__17(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__17 = 0x83498D84u;
	if (!UseLiftedCode(143, 0x83256B40)) { __imp__sub_83256B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256B40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256B40, 0x83256B40) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__17 = 0x83498D88u;
	if (!UseLiftedCode(143, 0x83256B78)) { __imp__sub_83256B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256B78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256B78, 0x83256B78) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__17 = 0x83498D8Cu;
	if (!UseLiftedCode(143, 0x83256BB0)) { __imp__sub_83256BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256BB0, 0x83256BB0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__17 = 0x83498D90u;
	if (!UseLiftedCode(143, 0x83256BE8)) { __imp__sub_83256BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256BE8, 0x83256BE8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__17(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__18 = 0x83498D94u;
	if (!UseLiftedCode(143, 0x83256C20)) { __imp__sub_83256C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256C20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256C20, 0x83256C20) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__18 = 0x83498D98u;
	if (!UseLiftedCode(143, 0x83256C58)) { __imp__sub_83256C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256C58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256C58, 0x83256C58) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__17 = 0x83498D9Cu;
	if (!UseLiftedCode(143, 0x83256C90)) { __imp__sub_83256C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256C90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256C90, 0x83256C90) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__17(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__17 = 0x83498DA0u;
	if (!UseLiftedCode(143, 0x83256CC8)) { __imp__sub_83256CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256CC8, 0x83256CC8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__17 = 0x83498DA4u;
	if (!UseLiftedCode(143, 0x83256D00)) { __imp__sub_83256D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256D00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256D00, 0x83256D00) { ctx.r3.u64 = HashName_TXT_820A2D24_B__17(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__17 = 0x83498DA8u;
	if (!UseLiftedCode(143, 0x83256D38)) { __imp__sub_83256D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256D38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256D38, 0x83256D38) { ctx.r3.u64 = HashName_TXT_820A2D30_B__17(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__17 = 0x83498DACu;
	if (!UseLiftedCode(143, 0x83256D70)) { __imp__sub_83256D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256D70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256D70, 0x83256D70) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__17(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__17(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__17 = 0x83498DB0u;
	if (!UseLiftedCode(143, 0x83256DA8)) { __imp__sub_83256DA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83256DA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__17, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83256DA8, 0x83256DA8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__17(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__18 = 0x83498DF0u;
	if (!UseLiftedCode(143, 0x832570C0)) { __imp__sub_832570C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832570C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832570C0, 0x832570C0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__18(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__19 = 0x83498DF4u;
	if (!UseLiftedCode(143, 0x832570F8)) { __imp__sub_832570F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832570F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832570F8, 0x832570F8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__19(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__18 = 0x83498DF8u;
	if (!UseLiftedCode(143, 0x83257130)) { __imp__sub_83257130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257130, 0x83257130) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__18 = 0x83498DFCu;
	if (!UseLiftedCode(143, 0x83257168)) { __imp__sub_83257168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257168, 0x83257168) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__18 = 0x83498E00u;
	if (!UseLiftedCode(143, 0x832571A0)) { __imp__sub_832571A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832571A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832571A0, 0x832571A0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__18 = 0x83498E04u;
	if (!UseLiftedCode(143, 0x832571D8)) { __imp__sub_832571D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832571D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832571D8, 0x832571D8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__18 = 0x83498E08u;
	if (!UseLiftedCode(143, 0x83257210)) { __imp__sub_83257210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257210, 0x83257210) { ctx.r3.u64 = HashName_TXT_820A2C44_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__18 = 0x83498E0Cu;
	if (!UseLiftedCode(143, 0x83257248)) { __imp__sub_83257248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257248, 0x83257248) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__18 = 0x83498E10u;
	if (!UseLiftedCode(143, 0x83257280)) { __imp__sub_83257280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257280, 0x83257280) { ctx.r3.u64 = HashName_TXT_820A2C74_B__18(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__18 = 0x83498E14u;
	if (!UseLiftedCode(143, 0x832572B8)) { __imp__sub_832572B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832572B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832572B8, 0x832572B8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__18 = 0x83498E18u;
	if (!UseLiftedCode(143, 0x832572F0)) { __imp__sub_832572F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832572F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832572F0, 0x832572F0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__18 = 0x83498E1Cu;
	if (!UseLiftedCode(143, 0x83257328)) { __imp__sub_83257328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257328, 0x83257328) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__18 = 0x83498E20u;
	if (!UseLiftedCode(143, 0x83257360)) { __imp__sub_83257360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257360, 0x83257360) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__18(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__19 = 0x83498E24u;
	if (!UseLiftedCode(143, 0x83257398)) { __imp__sub_83257398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257398, 0x83257398) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__19 = 0x83498E28u;
	if (!UseLiftedCode(143, 0x832573D0)) { __imp__sub_832573D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832573D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832573D0, 0x832573D0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__18 = 0x83498E2Cu;
	if (!UseLiftedCode(143, 0x83257408)) { __imp__sub_83257408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257408);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257408, 0x83257408) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__18(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__18 = 0x83498E30u;
	if (!UseLiftedCode(143, 0x83257440)) { __imp__sub_83257440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257440, 0x83257440) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__18 = 0x83498E34u;
	if (!UseLiftedCode(143, 0x83257478)) { __imp__sub_83257478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257478, 0x83257478) { ctx.r3.u64 = HashName_TXT_820A2D24_B__18(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__18 = 0x83498E38u;
	if (!UseLiftedCode(143, 0x832574B0)) { __imp__sub_832574B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832574B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832574B0, 0x832574B0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__18(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__18 = 0x83498E3Cu;
	if (!UseLiftedCode(143, 0x832574E8)) { __imp__sub_832574E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832574E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832574E8, 0x832574E8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__18(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__18 = 0x83498E40u;
	if (!UseLiftedCode(143, 0x83257520)) { __imp__sub_83257520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257520);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__18, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257520, 0x83257520) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__18(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__19 = 0x83498E84u;
	if (!UseLiftedCode(143, 0x83257958)) { __imp__sub_83257958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257958);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257958, 0x83257958) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__19(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__20 = 0x83498E88u;
	if (!UseLiftedCode(143, 0x83257990)) { __imp__sub_83257990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257990);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257990, 0x83257990) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__20(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__19 = 0x83498E8Cu;
	if (!UseLiftedCode(143, 0x832579C8)) { __imp__sub_832579C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832579C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832579C8, 0x832579C8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__19 = 0x83498E90u;
	if (!UseLiftedCode(143, 0x83257A00)) { __imp__sub_83257A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257A00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257A00, 0x83257A00) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__19 = 0x83498E94u;
	if (!UseLiftedCode(143, 0x83257A38)) { __imp__sub_83257A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257A38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257A38, 0x83257A38) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__19 = 0x83498E98u;
	if (!UseLiftedCode(143, 0x83257A70)) { __imp__sub_83257A70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257A70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257A70, 0x83257A70) { ctx.r3.u64 = HashName_TXT_820A2C34_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__19 = 0x83498E9Cu;
	if (!UseLiftedCode(143, 0x83257AA8)) { __imp__sub_83257AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257AA8, 0x83257AA8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__19 = 0x83498EA0u;
	if (!UseLiftedCode(143, 0x83257AE0)) { __imp__sub_83257AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257AE0, 0x83257AE0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__19 = 0x83498EA4u;
	if (!UseLiftedCode(143, 0x83257B18)) { __imp__sub_83257B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257B18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257B18, 0x83257B18) { ctx.r3.u64 = HashName_TXT_820A2C74_B__19(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__19 = 0x83498EA8u;
	if (!UseLiftedCode(143, 0x83257B50)) { __imp__sub_83257B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257B50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257B50, 0x83257B50) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__19 = 0x83498EACu;
	if (!UseLiftedCode(143, 0x83257B88)) { __imp__sub_83257B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257B88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257B88, 0x83257B88) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__19 = 0x83498EB0u;
	if (!UseLiftedCode(143, 0x83257BC0)) { __imp__sub_83257BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257BC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257BC0, 0x83257BC0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__19 = 0x83498EB4u;
	if (!UseLiftedCode(143, 0x83257BF8)) { __imp__sub_83257BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257BF8, 0x83257BF8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__19(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__20 = 0x83498EB8u;
	if (!UseLiftedCode(143, 0x83257C30)) { __imp__sub_83257C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257C30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257C30, 0x83257C30) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__20 = 0x83498EBCu;
	if (!UseLiftedCode(143, 0x83257C68)) { __imp__sub_83257C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257C68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257C68, 0x83257C68) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__19 = 0x83498EC0u;
	if (!UseLiftedCode(143, 0x83257CA0)) { __imp__sub_83257CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257CA0, 0x83257CA0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__19(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__19 = 0x83498EC4u;
	if (!UseLiftedCode(143, 0x83257CD8)) { __imp__sub_83257CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257CD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257CD8, 0x83257CD8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__19 = 0x83498EC8u;
	if (!UseLiftedCode(143, 0x83257D10)) { __imp__sub_83257D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257D10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257D10, 0x83257D10) { ctx.r3.u64 = HashName_TXT_820A2D24_B__19(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__19 = 0x83498ECCu;
	if (!UseLiftedCode(143, 0x83257D48)) { __imp__sub_83257D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257D48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257D48, 0x83257D48) { ctx.r3.u64 = HashName_TXT_820A2D30_B__19(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__19 = 0x83498ED0u;
	if (!UseLiftedCode(143, 0x83257D80)) { __imp__sub_83257D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257D80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257D80, 0x83257D80) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__19(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__19(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__19 = 0x83498ED4u;
	if (!UseLiftedCode(143, 0x83257DB8)) { __imp__sub_83257DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__19, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257DB8, 0x83257DB8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__19(ctx, base); }

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

uint64_t HashName_TXT_820A2BD4_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__20 = 0x83498EDCu;
	if (!UseLiftedCode(143, 0x83257E30)) { __imp__sub_83257E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257E30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257E30, 0x83257E30) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__20(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__21 = 0x83498EE0u;
	if (!UseLiftedCode(143, 0x83257E68)) { __imp__sub_83257E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257E68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257E68, 0x83257E68) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__21(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__20 = 0x83498EE4u;
	if (!UseLiftedCode(143, 0x83257EA0)) { __imp__sub_83257EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257EA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257EA0, 0x83257EA0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__20 = 0x83498EE8u;
	if (!UseLiftedCode(143, 0x83257ED8)) { __imp__sub_83257ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257ED8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257ED8, 0x83257ED8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__20 = 0x83498EECu;
	if (!UseLiftedCode(143, 0x83257F10)) { __imp__sub_83257F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257F10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257F10, 0x83257F10) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__20 = 0x83498EF0u;
	if (!UseLiftedCode(143, 0x83257F48)) { __imp__sub_83257F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257F48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257F48, 0x83257F48) { ctx.r3.u64 = HashName_TXT_820A2C34_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__20 = 0x83498EF4u;
	if (!UseLiftedCode(143, 0x83257F80)) { __imp__sub_83257F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257F80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257F80, 0x83257F80) { ctx.r3.u64 = HashName_TXT_820A2C44_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__20 = 0x83498EF8u;
	if (!UseLiftedCode(143, 0x83257FB8)) { __imp__sub_83257FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257FB8, 0x83257FB8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__20 = 0x83498EFCu;
	if (!UseLiftedCode(143, 0x83257FF0)) { __imp__sub_83257FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83257FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83257FF0, 0x83257FF0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__20(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__20 = 0x83498F00u;
	if (!UseLiftedCode(143, 0x83258028)) { __imp__sub_83258028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258028);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258028, 0x83258028) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__20 = 0x83498F04u;
	if (!UseLiftedCode(143, 0x83258060)) { __imp__sub_83258060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258060);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258060, 0x83258060) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__20 = 0x83498F08u;
	if (!UseLiftedCode(143, 0x83258098)) { __imp__sub_83258098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258098);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258098, 0x83258098) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__20 = 0x83498F0Cu;
	if (!UseLiftedCode(143, 0x832580D0)) { __imp__sub_832580D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832580D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832580D0, 0x832580D0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__20(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__21 = 0x83498F10u;
	if (!UseLiftedCode(143, 0x83258108)) { __imp__sub_83258108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258108);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258108, 0x83258108) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__21 = 0x83498F14u;
	if (!UseLiftedCode(143, 0x83258140)) { __imp__sub_83258140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258140);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258140, 0x83258140) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__20 = 0x83498F18u;
	if (!UseLiftedCode(143, 0x83258178)) { __imp__sub_83258178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258178);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258178, 0x83258178) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__20(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__20 = 0x83498F1Cu;
	if (!UseLiftedCode(143, 0x832581B0)) { __imp__sub_832581B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832581B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832581B0, 0x832581B0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__20 = 0x83498F20u;
	if (!UseLiftedCode(143, 0x832581E8)) { __imp__sub_832581E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832581E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832581E8, 0x832581E8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__20(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__20 = 0x83498F24u;
	if (!UseLiftedCode(143, 0x83258220)) { __imp__sub_83258220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258220);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258220, 0x83258220) { ctx.r3.u64 = HashName_TXT_820A2D30_B__20(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__20 = 0x83498F28u;
	if (!UseLiftedCode(143, 0x83258258)) { __imp__sub_83258258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258258);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258258, 0x83258258) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__20(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__20 = 0x83498F2Cu;
	if (!UseLiftedCode(143, 0x83258290)) { __imp__sub_83258290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258290);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__20, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258290, 0x83258290) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__20(ctx, base); }

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

// sub_83258648  [144 bytes]
uint64_t n_sub_83258648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83258648)) { __imp__sub_83258648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258648);
	// Static initialiser of a global container (head node at +4, element count at +8): a new head node whose
	// three links (+0, +4, +8) point to itself and whose flag bytes +28 and +29 are set to 1, then atexit
	// (RegisterAtExit) registers the function that releases the global.
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 32);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 29, 0);
	STORE8(head + 28, 1);
	uint64_t container = (int64_t)g_834A0000 - 28824;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 29, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 17248, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258648, 0x83258648) { ctx.r3.u64 = n_sub_83258648(ctx, base); }

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

uint64_t HashName_TXT_820C58A0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C58A0_B_ = int32_t(0x820C58A0);
	constexpr uint32_t g_HashOf_TXT_820C58A0_B_ = 0x83498FC0u;
	if (!UseLiftedCode(143, 0x83258B98)) { __imp__sub_83258B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258B98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C58A0_B_);
	STORE32(g_HashOf_TXT_820C58A0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258B98, 0x83258B98) { ctx.r3.u64 = HashName_TXT_820C58A0_B_(ctx, base); }

uint64_t HashName_TXT_820C58B0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C58B0_B_ = int32_t(0x820C58B0);
	constexpr uint32_t g_HashOf_TXT_820C58B0_B_ = 0x83498FC4u;
	if (!UseLiftedCode(143, 0x83258BD0)) { __imp__sub_83258BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258BD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C58B0_B_);
	STORE32(g_HashOf_TXT_820C58B0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83258BD0, 0x83258BD0) { ctx.r3.u64 = HashName_TXT_820C58B0_B_(ctx, base); }

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

uint64_t RegisterAtExit_832A45B0(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A45B0_address = int32_t(0x832A45B0);
	if (!UseLiftedCode(143, 0x83258D10)) { ctx.r8.u64 = exitContext; __imp__sub_83258D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258D10);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A45B0_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83258D10, 0x83258D10) { ctx.r3.u64 = RegisterAtExit_832A45B0(ctx, base, ctx.r8.u64); }

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

uint64_t RegisterAtExit_832A4610(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4610_address = int32_t(0x832A4610);
	if (!UseLiftedCode(143, 0x83258E60)) { ctx.r8.u64 = exitContext; __imp__sub_83258E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258E60);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4610_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83258E60, 0x83258E60) { ctx.r3.u64 = RegisterAtExit_832A4610(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83258F70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83258F70)) { __imp__sub_83258F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83258F70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 96);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 89, 0);
	STORE8(head + 88, 1);
	uint64_t container = (int64_t)g_834A0000 - 28372;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 89, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 18096, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83258F70, 0x83258F70) { ctx.r3.u64 = n_sub_83258F70(ctx, base); }

uint64_t n_sub_832592A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x832592A8)) { __imp__sub_832592A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832592A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 12);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 26648;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 18272, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832592A8, 0x832592A8) { ctx.r3.u64 = n_sub_832592A8(ctx, base); }

uint64_t HashName_TXT_820BD244_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BD244_B_ = int32_t(0x820BD244);
	constexpr uint32_t g_HashOf_TXT_820BD244_B_ = 0x83499D58u;
	if (!UseLiftedCode(143, 0x83259490)) { __imp__sub_83259490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259490);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BD244_B_);
	STORE32(g_HashOf_TXT_820BD244_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83259490, 0x83259490) { ctx.r3.u64 = HashName_TXT_820BD244_B_(ctx, base); }

uint64_t n_sub_832595D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x832595D0)) { __imp__sub_832595D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832595D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 112);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 97, 0);
	STORE8(head + 96, 1);
	uint64_t container = (int64_t)g_834A0000 - 24420;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 97, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 18536, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832595D0, 0x832595D0) { ctx.r3.u64 = n_sub_832595D0(ctx, base); }

uint64_t n_sub_832596F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x832596F0)) { __imp__sub_832596F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832596F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 24);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 23856;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 18616, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832596F0, 0x832596F0) { ctx.r3.u64 = n_sub_832596F0(ctx, base); }

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

uint64_t RegisterAtExit_832A4AF8(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4AF8_address = int32_t(0x832A4AF8);
	if (!UseLiftedCode(143, 0x83259B38)) { ctx.r8.u64 = exitContext; __imp__sub_83259B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B38);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4AF8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83259B38, 0x83259B38) { ctx.r3.u64 = RegisterAtExit_832A4AF8(ctx, base, ctx.r8.u64); }

uint64_t RegisterAtExit_832A4B08(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4B08_address = int32_t(0x832A4B08);
	if (!UseLiftedCode(143, 0x83259B60)) { ctx.r8.u64 = exitContext; __imp__sub_83259B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B60);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4B08_address, exitContext);
}
PROMOTED_ENTRY(143, sub_83259B60, 0x83259B60) { ctx.r3.u64 = RegisterAtExit_832A4B08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83259B70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83259B70)) { __imp__sub_83259B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259B70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 48);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 21168;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19296, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259B70, 0x83259B70) { ctx.r3.u64 = n_sub_83259B70(ctx, base); }

// sub_83259BD0  [64 bytes]
uint64_t DynamicObstacle_Init(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349AD2C_G_ = int32_t(0x8349AD2C);
	constexpr int32_t str_TXT_820C9AF8_B_ = int32_t(0x820C9AF8);
	constexpr int32_t Destroy_TXT_8349AD2C_G__address = int32_t(0x832A4BA8);
	if (!UseLiftedCode(143, 0x83259BD0)) { __imp__sub_83259BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259BD0);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (RegisterAtExit is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349AD2C_G_, str_TXT_820C9AF8_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349AD2C_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259BD0, 0x83259BD0) { ctx.r3.u64 = DynamicObstacle_Init(ctx, base); }

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

uint64_t n_sub_83259E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83259E88)) { __imp__sub_83259E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 24);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 21, 0);
	STORE8(head + 20, 1);
	uint64_t container = (int64_t)g_834A0000 - 21092;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 21, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19528, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259E88, 0x83259E88) { ctx.r3.u64 = n_sub_83259E88(ctx, base); }

uint64_t n_sub_83259F18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83259F18)) { __imp__sub_83259F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259F18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 36);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 33, 0);
	STORE8(head + 32, 1);
	uint64_t container = (int64_t)g_834A0000 - 21080;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 33, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19544, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259F18, 0x83259F18) { ctx.r3.u64 = n_sub_83259F18(ctx, base); }

uint64_t n_sub_83259FA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x83259FA8)) { __imp__sub_83259FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83259FA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 24);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 21, 0);
	STORE8(head + 20, 1);
	uint64_t container = (int64_t)g_834A0000 - 21068;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 21, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19560, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83259FA8, 0x83259FA8) { ctx.r3.u64 = n_sub_83259FA8(ctx, base); }

uint64_t n_sub_8325A038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325A038)) { __imp__sub_8325A038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 40);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 21056;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19576, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A038, 0x8325A038) { ctx.r3.u64 = n_sub_8325A038(ctx, base); }

uint64_t RegisterAtExit_832A4CC0(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4CC0_address = int32_t(0x832A4CC0);
	if (!UseLiftedCode(143, 0x8325A098)) { ctx.r8.u64 = exitContext; __imp__sub_8325A098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A098);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4CC0_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A098, 0x8325A098) { ctx.r3.u64 = RegisterAtExit_832A4CC0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8325A0C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325A0C0)) { __imp__sub_8325A0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A0C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 16);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 21008;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19736, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A0C0, 0x8325A0C0) { ctx.r3.u64 = n_sub_8325A0C0(ctx, base); }

uint64_t n_sub_8325A120(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325A120)) { __imp__sub_8325A120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A120);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 36);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 20996;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 19808, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325A120, 0x8325A120) { ctx.r3.u64 = n_sub_8325A120(ctx, base); }

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

uint64_t RegisterAtExit_832A4DB8(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4DB8_address = int32_t(0x832A4DB8);
	if (!UseLiftedCode(143, 0x8325A1C0)) { ctx.r8.u64 = exitContext; __imp__sub_8325A1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A1C0);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4DB8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A1C0, 0x8325A1C0) { ctx.r3.u64 = RegisterAtExit_832A4DB8(ctx, base, ctx.r8.u64); }

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

uint64_t RegisterAtExit_832A4DD8(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4DD8_address = int32_t(0x832A4DD8);
	if (!UseLiftedCode(143, 0x8325A210)) { ctx.r8.u64 = exitContext; __imp__sub_8325A210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A210);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4DD8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A210, 0x8325A210) { ctx.r3.u64 = RegisterAtExit_832A4DD8(ctx, base, ctx.r8.u64); }

uint64_t RegisterAtExit_832A4E40(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4E40_address = int32_t(0x832A4E40);
	if (!UseLiftedCode(143, 0x8325A220)) { ctx.r8.u64 = exitContext; __imp__sub_8325A220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A220);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4E40_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A220, 0x8325A220) { ctx.r3.u64 = RegisterAtExit_832A4E40(ctx, base, ctx.r8.u64); }

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

uint64_t RegisterAtExit_832A4F08(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A4F08_address = int32_t(0x832A4F08);
	if (!UseLiftedCode(143, 0x8325A3B0)) { ctx.r8.u64 = exitContext; __imp__sub_8325A3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325A3B0);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A4F08_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325A3B0, 0x8325A3B0) { ctx.r3.u64 = RegisterAtExit_832A4F08(ctx, base, ctx.r8.u64); }

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

uint64_t HashName_TXT_820CD0A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD0A8_B_ = int32_t(0x820CD0A8);
	constexpr uint32_t g_HashOf_TXT_820CD0A8_B_ = 0x8349AFA0u;
	if (!UseLiftedCode(143, 0x8325AE70)) { __imp__sub_8325AE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AE70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD0A8_B_);
	STORE32(g_HashOf_TXT_820CD0A8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325AE70, 0x8325AE70) { ctx.r3.u64 = HashName_TXT_820CD0A8_B_(ctx, base); }

uint64_t HashName_TXT_820CD0B4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD0B4_B_ = int32_t(0x820CD0B4);
	constexpr uint32_t g_HashOf_TXT_820CD0B4_B_ = 0x8349AFA4u;
	if (!UseLiftedCode(143, 0x8325AEA8)) { __imp__sub_8325AEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AEA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD0B4_B_);
	STORE32(g_HashOf_TXT_820CD0B4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325AEA8, 0x8325AEA8) { ctx.r3.u64 = HashName_TXT_820CD0B4_B_(ctx, base); }

uint64_t HashName_TXT_820CD0C0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD0C0_B_ = int32_t(0x820CD0C0);
	constexpr uint32_t g_HashOf_TXT_820CD0C0_B_ = 0x8349AFA8u;
	if (!UseLiftedCode(143, 0x8325AEE0)) { __imp__sub_8325AEE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325AEE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD0C0_B_);
	STORE32(g_HashOf_TXT_820CD0C0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325AEE0, 0x8325AEE0) { ctx.r3.u64 = HashName_TXT_820CD0C0_B_(ctx, base); }

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

uint64_t HashName_TXT_820CD0F4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD0F4_B_ = int32_t(0x820CD0F4);
	constexpr uint32_t g_HashOf_TXT_820CD0F4_B_ = 0x8349AFB8u;
	if (!UseLiftedCode(143, 0x8325B058)) { __imp__sub_8325B058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B058);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD0F4_B_);
	STORE32(g_HashOf_TXT_820CD0F4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B058, 0x8325B058) { ctx.r3.u64 = HashName_TXT_820CD0F4_B_(ctx, base); }

uint64_t HashName_TXT_820CD104_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD104_B_ = int32_t(0x820CD104);
	constexpr uint32_t g_HashOf_TXT_820CD104_B_ = 0x8349AFBCu;
	if (!UseLiftedCode(143, 0x8325B090)) { __imp__sub_8325B090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B090);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD104_B_);
	STORE32(g_HashOf_TXT_820CD104_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B090, 0x8325B090) { ctx.r3.u64 = HashName_TXT_820CD104_B_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__21 = 0x8349AFC0u;
	if (!UseLiftedCode(143, 0x8325B0C8)) { __imp__sub_8325B0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B0C8, 0x8325B0C8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__21(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__22 = 0x8349AFC4u;
	if (!UseLiftedCode(143, 0x8325B100)) { __imp__sub_8325B100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B100);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B100, 0x8325B100) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__22(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__21 = 0x8349AFC8u;
	if (!UseLiftedCode(143, 0x8325B138)) { __imp__sub_8325B138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B138);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B138, 0x8325B138) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__21 = 0x8349AFCCu;
	if (!UseLiftedCode(143, 0x8325B170)) { __imp__sub_8325B170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B170);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B170, 0x8325B170) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__21 = 0x8349AFD0u;
	if (!UseLiftedCode(143, 0x8325B1A8)) { __imp__sub_8325B1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B1A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B1A8, 0x8325B1A8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__21 = 0x8349AFD4u;
	if (!UseLiftedCode(143, 0x8325B1E0)) { __imp__sub_8325B1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B1E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B1E0, 0x8325B1E0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__21 = 0x8349AFD8u;
	if (!UseLiftedCode(143, 0x8325B218)) { __imp__sub_8325B218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B218);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B218, 0x8325B218) { ctx.r3.u64 = HashName_TXT_820A2C44_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__21 = 0x8349AFDCu;
	if (!UseLiftedCode(143, 0x8325B250)) { __imp__sub_8325B250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B250);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B250, 0x8325B250) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__21 = 0x8349AFE0u;
	if (!UseLiftedCode(143, 0x8325B288)) { __imp__sub_8325B288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B288);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B288, 0x8325B288) { ctx.r3.u64 = HashName_TXT_820A2C74_B__21(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__21 = 0x8349AFE4u;
	if (!UseLiftedCode(143, 0x8325B2C0)) { __imp__sub_8325B2C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B2C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B2C0, 0x8325B2C0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__21 = 0x8349AFE8u;
	if (!UseLiftedCode(143, 0x8325B2F8)) { __imp__sub_8325B2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B2F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B2F8, 0x8325B2F8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__21 = 0x8349AFECu;
	if (!UseLiftedCode(143, 0x8325B330)) { __imp__sub_8325B330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B330);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B330, 0x8325B330) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__21 = 0x8349AFF0u;
	if (!UseLiftedCode(143, 0x8325B368)) { __imp__sub_8325B368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B368);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B368, 0x8325B368) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__21(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__22 = 0x8349AFF4u;
	if (!UseLiftedCode(143, 0x8325B3A0)) { __imp__sub_8325B3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B3A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B3A0, 0x8325B3A0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__22(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__22 = 0x8349AFF8u;
	if (!UseLiftedCode(143, 0x8325B3D8)) { __imp__sub_8325B3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B3D8, 0x8325B3D8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__22(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__21 = 0x8349AFFCu;
	if (!UseLiftedCode(143, 0x8325B410)) { __imp__sub_8325B410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B410);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B410, 0x8325B410) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__21(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__21 = 0x8349B000u;
	if (!UseLiftedCode(143, 0x8325B448)) { __imp__sub_8325B448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B448);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B448, 0x8325B448) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__21 = 0x8349B004u;
	if (!UseLiftedCode(143, 0x8325B480)) { __imp__sub_8325B480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B480);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B480, 0x8325B480) { ctx.r3.u64 = HashName_TXT_820A2D24_B__21(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__21 = 0x8349B008u;
	if (!UseLiftedCode(143, 0x8325B4B8)) { __imp__sub_8325B4B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B4B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B4B8, 0x8325B4B8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__21(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__21 = 0x8349B00Cu;
	if (!UseLiftedCode(143, 0x8325B4F0)) { __imp__sub_8325B4F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B4F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B4F0, 0x8325B4F0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__21(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__21(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__21 = 0x8349B010u;
	if (!UseLiftedCode(143, 0x8325B528)) { __imp__sub_8325B528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B528);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__21, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B528, 0x8325B528) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__21(ctx, base); }

uint64_t HashName_TXT_820CD134_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD134_B_ = int32_t(0x820CD134);
	constexpr uint32_t g_HashOf_TXT_820CD134_B_ = 0x8349B014u;
	if (!UseLiftedCode(143, 0x8325B560)) { __imp__sub_8325B560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B560);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD134_B_);
	STORE32(g_HashOf_TXT_820CD134_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B560, 0x8325B560) { ctx.r3.u64 = HashName_TXT_820CD134_B_(ctx, base); }

uint64_t HashName_TXT_820CD144_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD144_B_ = int32_t(0x820CD144);
	constexpr uint32_t g_HashOf_TXT_820CD144_B_ = 0x8349B018u;
	if (!UseLiftedCode(143, 0x8325B598)) { __imp__sub_8325B598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B598);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD144_B_);
	STORE32(g_HashOf_TXT_820CD144_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B598, 0x8325B598) { ctx.r3.u64 = HashName_TXT_820CD144_B_(ctx, base); }

uint64_t HashName_TXT_820CD150_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD150_B_ = int32_t(0x820CD150);
	constexpr uint32_t g_HashOf_TXT_820CD150_B_ = 0x8349B01Cu;
	if (!UseLiftedCode(143, 0x8325B5D0)) { __imp__sub_8325B5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B5D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD150_B_);
	STORE32(g_HashOf_TXT_820CD150_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B5D0, 0x8325B5D0) { ctx.r3.u64 = HashName_TXT_820CD150_B_(ctx, base); }

uint64_t HashName_TXT_820CD15C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD15C_B_ = int32_t(0x820CD15C);
	constexpr uint32_t g_HashOf_TXT_820CD15C_B_ = 0x8349B020u;
	if (!UseLiftedCode(143, 0x8325B608)) { __imp__sub_8325B608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B608);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD15C_B_);
	STORE32(g_HashOf_TXT_820CD15C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B608, 0x8325B608) { ctx.r3.u64 = HashName_TXT_820CD15C_B_(ctx, base); }

uint64_t HashName_TXT_820CD16C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD16C_B_ = int32_t(0x820CD16C);
	constexpr uint32_t g_HashOf_TXT_820CD16C_B_ = 0x8349B024u;
	if (!UseLiftedCode(143, 0x8325B640)) { __imp__sub_8325B640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B640);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD16C_B_);
	STORE32(g_HashOf_TXT_820CD16C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B640, 0x8325B640) { ctx.r3.u64 = HashName_TXT_820CD16C_B_(ctx, base); }

uint64_t HashName_TXT_820CD17C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD17C_B_ = int32_t(0x820CD17C);
	constexpr uint32_t g_HashOf_TXT_820CD17C_B_ = 0x8349B028u;
	if (!UseLiftedCode(143, 0x8325B678)) { __imp__sub_8325B678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B678);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD17C_B_);
	STORE32(g_HashOf_TXT_820CD17C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B678, 0x8325B678) { ctx.r3.u64 = HashName_TXT_820CD17C_B_(ctx, base); }

uint64_t HashName_TXT_820CD190_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD190_B_ = int32_t(0x820CD190);
	constexpr uint32_t g_HashOf_TXT_820CD190_B_ = 0x8349B02Cu;
	if (!UseLiftedCode(143, 0x8325B6B0)) { __imp__sub_8325B6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B6B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD190_B_);
	STORE32(g_HashOf_TXT_820CD190_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B6B0, 0x8325B6B0) { ctx.r3.u64 = HashName_TXT_820CD190_B_(ctx, base); }

uint64_t HashName_TXT_820CD104_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD104_B_ = int32_t(0x820CD104);
	constexpr uint32_t g_HashOf_TXT_820CD104_B__2 = 0x8349B030u;
	if (!UseLiftedCode(143, 0x8325B6E8)) { __imp__sub_8325B6E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B6E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD104_B_);
	STORE32(g_HashOf_TXT_820CD104_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B6E8, 0x8325B6E8) { ctx.r3.u64 = HashName_TXT_820CD104_B__2(ctx, base); }

uint64_t HashName_TXT_820CD0F4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD0F4_B_ = int32_t(0x820CD0F4);
	constexpr uint32_t g_HashOf_TXT_820CD0F4_B__2 = 0x8349B034u;
	if (!UseLiftedCode(143, 0x8325B720)) { __imp__sub_8325B720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325B720);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820CD0F4_B_);
	STORE32(g_HashOf_TXT_820CD0F4_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(143, sub_8325B720, 0x8325B720) { ctx.r3.u64 = HashName_TXT_820CD0F4_B__2(ctx, base); }

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

uint64_t RegisterAtExit_832A55F8(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A55F8_address = int32_t(0x832A55F8);
	if (!UseLiftedCode(143, 0x8325C668)) { ctx.r8.u64 = exitContext; __imp__sub_8325C668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325C668);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A55F8_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325C668, 0x8325C668) { ctx.r3.u64 = RegisterAtExit_832A55F8(ctx, base, ctx.r8.u64); }

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

// sub_8325CB78  [88 bytes]
uint64_t n_sub_8325CB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB30_B_ = int32_t(0x820CEB30);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CB78)) { __imp__sub_8325CB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CB78);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string as a copy of another global string, append a C string to it
	// (CCharString_AssignCString appends to a string that is not empty), then register its release
	// to run at exit (RegisterAtExit is atexit; the value it passes to the registered function is the page base here).
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20096;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB30_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22496, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CB78, 0x8325CB78) { ctx.r3.u64 = n_sub_8325CB78(ctx, base); }

uint64_t n_sub_8325CBD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB3C_B_ = int32_t(0x820CEB3C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CBD0)) { __imp__sub_8325CBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CBD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20092;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB3C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22512, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CBD0, 0x8325CBD0) { ctx.r3.u64 = n_sub_8325CBD0(ctx, base); }

uint64_t n_sub_8325CC28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB48_B_ = int32_t(0x820CEB48);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CC28)) { __imp__sub_8325CC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CC28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20088;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB48_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22528, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CC28, 0x8325CC28) { ctx.r3.u64 = n_sub_8325CC28(ctx, base); }

uint64_t n_sub_8325CC80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB5C_B_ = int32_t(0x820CEB5C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CC80)) { __imp__sub_8325CC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CC80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20084;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB5C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22544, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CC80, 0x8325CC80) { ctx.r3.u64 = n_sub_8325CC80(ctx, base); }

uint64_t n_sub_8325CCD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB74_B_ = int32_t(0x820CEB74);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CCD8)) { __imp__sub_8325CCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CCD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20080;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB74_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22560, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CCD8, 0x8325CCD8) { ctx.r3.u64 = n_sub_8325CCD8(ctx, base); }

uint64_t n_sub_8325CD30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB88_B_ = int32_t(0x820CEB88);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CD30)) { __imp__sub_8325CD30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CD30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20076;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB88_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22576, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CD30, 0x8325CD30) { ctx.r3.u64 = n_sub_8325CD30(ctx, base); }

uint64_t n_sub_8325CD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB9C_B_ = int32_t(0x820CEB9C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B17C_G_ = int32_t(0x8349B17C);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CD88)) { __imp__sub_8325CD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20072;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B17C_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB9C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22592, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CD88, 0x8325CD88) { ctx.r3.u64 = n_sub_8325CD88(ctx, base); }

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

uint64_t n_sub_8325CE80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB9C_B_ = int32_t(0x820CEB9C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1A4_G_ = int32_t(0x8349B1A4);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CE80)) { __imp__sub_8325CE80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CE80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20056;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1A4_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB9C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22624, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CE80, 0x8325CE80) { ctx.r3.u64 = n_sub_8325CE80(ctx, base); }

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

uint64_t n_sub_8325CF18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB9C_B_ = int32_t(0x820CEB9C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CF18)) { __imp__sub_8325CF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CF18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20048;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1AC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB9C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22656, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CF18, 0x8325CF18) { ctx.r3.u64 = n_sub_8325CF18(ctx, base); }

uint64_t n_sub_8325CF70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEBCC_B_ = int32_t(0x820CEBCC);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CF70)) { __imp__sub_8325CF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CF70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20044;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1AC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEBCC_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22672, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CF70, 0x8325CF70) { ctx.r3.u64 = n_sub_8325CF70(ctx, base); }

uint64_t n_sub_8325CFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEBD8_B_ = int32_t(0x820CEBD8);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325CFC8)) { __imp__sub_8325CFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325CFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20040;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1AC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEBD8_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22688, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325CFC8, 0x8325CFC8) { ctx.r3.u64 = n_sub_8325CFC8(ctx, base); }

uint64_t n_sub_8325D020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEBE4_B_ = int32_t(0x820CEBE4);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D020)) { __imp__sub_8325D020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20036;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1AC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEBE4_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22704, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D020, 0x8325D020) { ctx.r3.u64 = n_sub_8325D020(ctx, base); }

uint64_t n_sub_8325D078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEBEC_B_ = int32_t(0x820CEBEC);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1AC_G_ = int32_t(0x8349B1AC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D078)) { __imp__sub_8325D078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20032;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1AC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEBEC_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22720, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D078, 0x8325D078) { ctx.r3.u64 = n_sub_8325D078(ctx, base); }

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

uint64_t n_sub_8325D210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC0C_B_ = int32_t(0x820CEC0C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D210)) { __imp__sub_8325D210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20012;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1C8_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC0C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22784, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D210, 0x8325D210) { ctx.r3.u64 = n_sub_8325D210(ctx, base); }

uint64_t n_sub_8325D268(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC14_B_ = int32_t(0x820CEC14);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D268)) { __imp__sub_8325D268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D268);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20008;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1C8_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC14_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22800, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D268, 0x8325D268) { ctx.r3.u64 = n_sub_8325D268(ctx, base); }

uint64_t n_sub_8325D2C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC28_B_ = int32_t(0x820CEC28);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D2C0)) { __imp__sub_8325D2C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D2C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20004;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1C8_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC28_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22816, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D2C0, 0x8325D2C0) { ctx.r3.u64 = n_sub_8325D2C0(ctx, base); }

uint64_t n_sub_8325D318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC30_B_ = int32_t(0x820CEC30);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1C8_G_ = int32_t(0x8349B1C8);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D318)) { __imp__sub_8325D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 20000;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1C8_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC30_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22832, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D318, 0x8325D318) { ctx.r3.u64 = n_sub_8325D318(ctx, base); }

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

uint64_t n_sub_8325D3B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC50_B_ = int32_t(0x820CEC50);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1E4_G_ = int32_t(0x8349B1E4);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D3B0)) { __imp__sub_8325D3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D3B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 19992;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1E4_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC50_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22864, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D3B0, 0x8325D3B0) { ctx.r3.u64 = n_sub_8325D3B0(ctx, base); }

uint64_t n_sub_8325D408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC60_B_ = int32_t(0x820CEC60);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1E4_G_ = int32_t(0x8349B1E4);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D408)) { __imp__sub_8325D408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 19988;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1E4_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC60_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22880, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D408, 0x8325D408) { ctx.r3.u64 = n_sub_8325D408(ctx, base); }

uint64_t n_sub_8325D460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEB9C_B_ = int32_t(0x820CEB9C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1E4_G_ = int32_t(0x8349B1E4);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D460)) { __imp__sub_8325D460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D460);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 19984;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1E4_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEB9C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22896, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D460, 0x8325D460) { ctx.r3.u64 = n_sub_8325D460(ctx, base); }

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

uint64_t n_sub_8325D578(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CEC9C_B_ = int32_t(0x820CEC9C);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1FC_G_ = int32_t(0x8349B1FC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D578)) { __imp__sub_8325D578(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D578);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 19968;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1FC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CEC9C_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22960, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D578, 0x8325D578) { ctx.r3.u64 = n_sub_8325D578(ctx, base); }

uint64_t n_sub_8325D5D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CECA8_B_ = int32_t(0x820CECA8);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B1FC_G_ = int32_t(0x8349B1FC);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325D5D0)) { __imp__sub_8325D5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D5D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t globalString = (int64_t)g_834A0000 - 19964;
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_834A0000;
	CCharString_CopyConstruct(ctx, base, globalString, TXT_8349B1FC_G_);
	CCharString_AssignCString(ctx, base, globalString, str_TXT_820CECA8_B_);
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 22976, g_832A0000);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325D5D0, 0x8325D5D0) { ctx.r3.u64 = n_sub_8325D5D0(ctx, base); }

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

uint64_t RegisterAtExit_832A5A40(CpuState& ctx, uint8_t* base, uint64_t exitContext) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A5A40_address = int32_t(0x832A5A40);
	if (!UseLiftedCode(143, 0x8325D7E8)) { ctx.r8.u64 = exitContext; __imp__sub_8325D7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325D7E8);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A5A40_address, exitContext);
}
PROMOTED_ENTRY(143, sub_8325D7E8, 0x8325D7E8) { ctx.r3.u64 = RegisterAtExit_832A5A40(ctx, base, ctx.r8.u64); }

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

uint64_t HashName_TXT_820A2BD4_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__22 = 0x8349B270u;
	if (!UseLiftedCode(143, 0x8325DBB8)) { __imp__sub_8325DBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DBB8, 0x8325DBB8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__22(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__23 = 0x8349B274u;
	if (!UseLiftedCode(143, 0x8325DBF0)) { __imp__sub_8325DBF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DBF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DBF0, 0x8325DBF0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__23(ctx, base); }

uint64_t HashName_TXT_820CFD78_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFD78_B_ = int32_t(0x820CFD78);
	constexpr uint32_t g_HashOf_TXT_820CFD78_B_ = 0x8349B278u;
	if (!UseLiftedCode(143, 0x8325DC28)) { __imp__sub_8325DC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DC28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFD78_B_);
	STORE32(g_HashOf_TXT_820CFD78_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DC28, 0x8325DC28) { ctx.r3.u64 = HashName_TXT_820CFD78_B_(ctx, base); }

uint64_t HashName_TXT_820CFD90_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFD90_B_ = int32_t(0x820CFD90);
	constexpr uint32_t g_HashOf_TXT_820CFD90_B_ = 0x8349B27Cu;
	if (!UseLiftedCode(143, 0x8325DC60)) { __imp__sub_8325DC60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DC60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFD90_B_);
	STORE32(g_HashOf_TXT_820CFD90_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DC60, 0x8325DC60) { ctx.r3.u64 = HashName_TXT_820CFD90_B_(ctx, base); }

uint64_t HashName_TXT_820CFDA0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFDA0_B_ = int32_t(0x820CFDA0);
	constexpr uint32_t g_HashOf_TXT_820CFDA0_B_ = 0x8349B280u;
	if (!UseLiftedCode(143, 0x8325DC98)) { __imp__sub_8325DC98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DC98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFDA0_B_);
	STORE32(g_HashOf_TXT_820CFDA0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DC98, 0x8325DC98) { ctx.r3.u64 = HashName_TXT_820CFDA0_B_(ctx, base); }

uint64_t HashName_TXT_820CFDB4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFDB4_B_ = int32_t(0x820CFDB4);
	constexpr uint32_t g_HashOf_TXT_820CFDB4_B_ = 0x8349B284u;
	if (!UseLiftedCode(143, 0x8325DCD0)) { __imp__sub_8325DCD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DCD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFDB4_B_);
	STORE32(g_HashOf_TXT_820CFDB4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DCD0, 0x8325DCD0) { ctx.r3.u64 = HashName_TXT_820CFDB4_B_(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__22 = 0x8349B288u;
	if (!UseLiftedCode(143, 0x8325DD08)) { __imp__sub_8325DD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DD08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DD08, 0x8325DD08) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__22(ctx, base); }

uint64_t HashName_TXT_820CFDCC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFDCC_B_ = int32_t(0x820CFDCC);
	constexpr uint32_t g_HashOf_TXT_820CFDCC_B_ = 0x8349B28Cu;
	if (!UseLiftedCode(143, 0x8325DD40)) { __imp__sub_8325DD40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DD40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFDCC_B_);
	STORE32(g_HashOf_TXT_820CFDCC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DD40, 0x8325DD40) { ctx.r3.u64 = HashName_TXT_820CFDCC_B_(ctx, base); }

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

uint64_t HashName_TXT_820CFE30_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFE30_B_ = int32_t(0x820CFE30);
	constexpr uint32_t g_HashOf_TXT_820CFE30_B_ = 0x8349B29Cu;
	if (!UseLiftedCode(143, 0x8325DE38)) { __imp__sub_8325DE38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DE38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFE30_B_);
	STORE32(g_HashOf_TXT_820CFE30_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DE38, 0x8325DE38) { ctx.r3.u64 = HashName_TXT_820CFE30_B_(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__22 = 0x8349B2A0u;
	if (!UseLiftedCode(143, 0x8325DE70)) { __imp__sub_8325DE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DE70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DE70, 0x8325DE70) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__22(ctx, base); }

uint64_t HashName_TXT_820CFE44_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFE44_B_ = int32_t(0x820CFE44);
	constexpr uint32_t g_HashOf_TXT_820CFE44_B_ = 0x8349B2A4u;
	if (!UseLiftedCode(143, 0x8325DEA8)) { __imp__sub_8325DEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DEA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFE44_B_);
	STORE32(g_HashOf_TXT_820CFE44_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DEA8, 0x8325DEA8) { ctx.r3.u64 = HashName_TXT_820CFE44_B_(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__23 = 0x8349B2A8u;
	if (!UseLiftedCode(143, 0x8325DEE0)) { __imp__sub_8325DEE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DEE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DEE0, 0x8325DEE0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__22 = 0x8349B2ACu;
	if (!UseLiftedCode(143, 0x8325DF18)) { __imp__sub_8325DF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325DF18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325DF18, 0x8325DF18) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__22(ctx, base); }

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

uint64_t HashName_TXT_820A2CD4_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__22 = 0x8349B2C0u;
	if (!UseLiftedCode(143, 0x8325E048)) { __imp__sub_8325E048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E048);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E048, 0x8325E048) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__22(ctx, base); }

uint64_t HashName_TXT_820CFECC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CFECC_B_ = int32_t(0x820CFECC);
	constexpr uint32_t g_HashOf_TXT_820CFECC_B_ = 0x8349B2C4u;
	if (!UseLiftedCode(143, 0x8325E080)) { __imp__sub_8325E080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E080);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CFECC_B_);
	STORE32(g_HashOf_TXT_820CFECC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E080, 0x8325E080) { ctx.r3.u64 = HashName_TXT_820CFECC_B_(ctx, base); }

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

uint64_t HashName_TXT_820A2D30_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__22 = 0x8349B2D4u;
	if (!UseLiftedCode(143, 0x8325E178)) { __imp__sub_8325E178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E178);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E178, 0x8325E178) { ctx.r3.u64 = HashName_TXT_820A2D30_B__22(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__23 = 0x8349B2D8u;
	if (!UseLiftedCode(143, 0x8325E1B0)) { __imp__sub_8325E1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E1B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E1B0, 0x8325E1B0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__22 = 0x8349B2DCu;
	if (!UseLiftedCode(143, 0x8325E1E8)) { __imp__sub_8325E1E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E1E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E1E8, 0x8325E1E8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__22(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__22 = 0x8349B2E0u;
	if (!UseLiftedCode(143, 0x8325E220)) { __imp__sub_8325E220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E220);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E220, 0x8325E220) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__22(ctx, base); }

uint64_t HashName_TXT_820D04F0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D04F0_B_ = int32_t(0x820D04F0);
	constexpr uint32_t g_HashOf_TXT_820D04F0_B_ = 0x8349B2E4u;
	if (!UseLiftedCode(143, 0x8325E258)) { __imp__sub_8325E258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E258);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D04F0_B_);
	STORE32(g_HashOf_TXT_820D04F0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E258, 0x8325E258) { ctx.r3.u64 = HashName_TXT_820D04F0_B_(ctx, base); }

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

uint64_t HashName_TXT_820D0C24_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0C24_B_ = int32_t(0x820D0C24);
	constexpr uint32_t g_HashOf_TXT_820D0C24_B_ = 0x8349B30Cu;
	if (!UseLiftedCode(143, 0x8325E4D0)) { __imp__sub_8325E4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E4D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D0C24_B_);
	STORE32(g_HashOf_TXT_820D0C24_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E4D0, 0x8325E4D0) { ctx.r3.u64 = HashName_TXT_820D0C24_B_(ctx, base); }

uint64_t HashName_TXT_820D0C30_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0C30_B_ = int32_t(0x820D0C30);
	constexpr uint32_t g_HashOf_TXT_820D0C30_B_ = 0x8349B310u;
	if (!UseLiftedCode(143, 0x8325E508)) { __imp__sub_8325E508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E508);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D0C30_B_);
	STORE32(g_HashOf_TXT_820D0C30_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E508, 0x8325E508) { ctx.r3.u64 = HashName_TXT_820D0C30_B_(ctx, base); }

uint64_t n_sub_8325E540(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325E540)) { __imp__sub_8325E540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E540);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 24);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 21, 0);
	STORE8(head + 20, 1);
	uint64_t container = (int64_t)g_834A0000 - 19692;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 21, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 23744, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E540, 0x8325E540) { ctx.r3.u64 = n_sub_8325E540(ctx, base); }

uint64_t n_sub_8325E5D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325E5D0)) { __imp__sub_8325E5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E5D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 32);
	if (head != 0) {
		STORE32(head, 0u);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, 0u);
	}
	if (head + 8 != 0) {
		STORE32(head + 8, 0u);
	}
	STORE8(head + 29, 0);
	STORE8(head + 28, 1);
	uint64_t container = (int64_t)g_834A0000 - 19680;
	STORE32((uint32_t)container + 4, head);
	STORE8(head + 29, 1);
	uint32_t linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 4, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead, linkedHead);
	linkedHead = LOAD32((uint32_t)container + 4);
	STORE32(linkedHead + 8, linkedHead);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = linkedHead;
	ctx.xer.ca = head > 4294967287;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 23760, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325E5D0, 0x8325E5D0) { ctx.r3.u64 = n_sub_8325E5D0(ctx, base); }

uint64_t HashName_TXT_820D0C3C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0C3C_B_ = int32_t(0x820D0C3C);
	constexpr uint32_t g_HashOf_TXT_820D0C3C_B_ = 0x8349B32Cu;
	if (!UseLiftedCode(143, 0x8325E660)) { __imp__sub_8325E660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E660);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D0C3C_B_);
	STORE32(g_HashOf_TXT_820D0C3C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E660, 0x8325E660) { ctx.r3.u64 = HashName_TXT_820D0C3C_B_(ctx, base); }

uint64_t HashName_TXT_820D0C50_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0C50_B_ = int32_t(0x820D0C50);
	constexpr uint32_t g_HashOf_TXT_820D0C50_B_ = 0x8349B330u;
	if (!UseLiftedCode(143, 0x8325E698)) { __imp__sub_8325E698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E698);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D0C50_B_);
	STORE32(g_HashOf_TXT_820D0C50_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325E698, 0x8325E698) { ctx.r3.u64 = HashName_TXT_820D0C50_B_(ctx, base); }

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
uint64_t InitGlobalString_ShadowNeck(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B374_G_ = int32_t(0x8349B374);
	constexpr int32_t str_TXT_820D1418_B_ = int32_t(0x820D1418);
	constexpr int32_t Destroy_TXT_8349B374_G__address = int32_t(0x832A5CF0);
	if (!UseLiftedCode(143, 0x8325E808)) { __imp__sub_8325E808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E808);
	// Construct the global string from a C string, then register its release to run at exit
	// (RegisterAtExit is atexit).
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B374_G_, str_TXT_820D1418_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349B374_G__address);
	return result;
}
PROMOTED_ENTRY(143, sub_8325E808, 0x8325E808) { ctx.r3.u64 = InitGlobalString_ShadowNeck(ctx, base); }

uint64_t InitGlobalString_ShadowNeck1(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B378_G_ = int32_t(0x8349B378);
	constexpr int32_t str_TXT_820D1424_B_ = int32_t(0x820D1424);
	constexpr int32_t Destroy_TXT_8349B378_G__address = int32_t(0x832A5D00);
	if (!UseLiftedCode(143, 0x8325E848)) { __imp__sub_8325E848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B378_G_, str_TXT_820D1424_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B378_G__address);
}
PROMOTED_ENTRY(143, sub_8325E848, 0x8325E848) { ctx.r3.u64 = InitGlobalString_ShadowNeck1(ctx, base); }

uint64_t InitGlobalString_ShadowLEye(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B37C_G_ = int32_t(0x8349B37C);
	constexpr int32_t str_TXT_820D1434_B_ = int32_t(0x820D1434);
	constexpr int32_t Destroy_TXT_8349B37C_G__address = int32_t(0x832A5D10);
	if (!UseLiftedCode(143, 0x8325E888)) { __imp__sub_8325E888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B37C_G_, str_TXT_820D1434_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B37C_G__address);
}
PROMOTED_ENTRY(143, sub_8325E888, 0x8325E888) { ctx.r3.u64 = InitGlobalString_ShadowLEye(ctx, base); }

uint64_t InitGlobalString_ShadowREye(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B380_G_ = int32_t(0x8349B380);
	constexpr int32_t str_TXT_820D1444_B_ = int32_t(0x820D1444);
	constexpr int32_t Destroy_TXT_8349B380_G__address = int32_t(0x832A5D20);
	if (!UseLiftedCode(143, 0x8325E8C8)) { __imp__sub_8325E8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325E8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B380_G_, str_TXT_820D1444_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B380_G__address);
}
PROMOTED_ENTRY(143, sub_8325E8C8, 0x8325E8C8) { ctx.r3.u64 = InitGlobalString_ShadowREye(ctx, base); }

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

uint64_t InitGlobalString_ShadowLBrowOuter(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B39C_G_ = int32_t(0x8349B39C);
	constexpr int32_t str_TXT_820D1454_B_ = int32_t(0x820D1454);
	constexpr int32_t Destroy_TXT_8349B39C_G__address = int32_t(0x832A5D90);
	if (!UseLiftedCode(143, 0x8325EA88)) { __imp__sub_8325EA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EA88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B39C_G_, str_TXT_820D1454_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B39C_G__address);
}
PROMOTED_ENTRY(143, sub_8325EA88, 0x8325EA88) { ctx.r3.u64 = InitGlobalString_ShadowLBrowOuter(ctx, base); }

uint64_t InitGlobalString_ShadowLBrowMid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A0_G_ = int32_t(0x8349B3A0);
	constexpr int32_t str_TXT_820D1468_B_ = int32_t(0x820D1468);
	constexpr int32_t Destroy_TXT_8349B3A0_G__address = int32_t(0x832A5DA0);
	if (!UseLiftedCode(143, 0x8325EAC8)) { __imp__sub_8325EAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A0_G_, str_TXT_820D1468_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EAC8, 0x8325EAC8) { ctx.r3.u64 = InitGlobalString_ShadowLBrowMid(ctx, base); }

uint64_t InitGlobalString_ShadowLBrowInner(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A4_G_ = int32_t(0x8349B3A4);
	constexpr int32_t str_TXT_820D147C_B_ = int32_t(0x820D147C);
	constexpr int32_t Destroy_TXT_8349B3A4_G__address = int32_t(0x832A5DB0);
	if (!UseLiftedCode(143, 0x8325EB08)) { __imp__sub_8325EB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A4_G_, str_TXT_820D147C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB08, 0x8325EB08) { ctx.r3.u64 = InitGlobalString_ShadowLBrowInner(ctx, base); }

uint64_t InitGlobalString_ShadowLTopEyeLid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3A8_G_ = int32_t(0x8349B3A8);
	constexpr int32_t str_TXT_820D1490_B_ = int32_t(0x820D1490);
	constexpr int32_t Destroy_TXT_8349B3A8_G__address = int32_t(0x832A5DC0);
	if (!UseLiftedCode(143, 0x8325EB48)) { __imp__sub_8325EB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3A8_G_, str_TXT_820D1490_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3A8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB48, 0x8325EB48) { ctx.r3.u64 = InitGlobalString_ShadowLTopEyeLid(ctx, base); }

uint64_t InitGlobalString_ShadowLBotEyeLid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3AC_G_ = int32_t(0x8349B3AC);
	constexpr int32_t str_TXT_820D14A4_B_ = int32_t(0x820D14A4);
	constexpr int32_t Destroy_TXT_8349B3AC_G__address = int32_t(0x832A5DD0);
	if (!UseLiftedCode(143, 0x8325EB88)) { __imp__sub_8325EB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EB88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3AC_G_, str_TXT_820D14A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3AC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EB88, 0x8325EB88) { ctx.r3.u64 = InitGlobalString_ShadowLBotEyeLid(ctx, base); }

uint64_t InitGlobalString_ShadowLSquint(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B0_G_ = int32_t(0x8349B3B0);
	constexpr int32_t str_TXT_820D14B8_B_ = int32_t(0x820D14B8);
	constexpr int32_t Destroy_TXT_8349B3B0_G__address = int32_t(0x832A5DE0);
	if (!UseLiftedCode(143, 0x8325EBC8)) { __imp__sub_8325EBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B0_G_, str_TXT_820D14B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EBC8, 0x8325EBC8) { ctx.r3.u64 = InitGlobalString_ShadowLSquint(ctx, base); }

uint64_t InitGlobalString_ShadowLCheek1(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B4_G_ = int32_t(0x8349B3B4);
	constexpr int32_t str_TXT_820D14C8_B_ = int32_t(0x820D14C8);
	constexpr int32_t Destroy_TXT_8349B3B4_G__address = int32_t(0x832A5DF0);
	if (!UseLiftedCode(143, 0x8325EC08)) { __imp__sub_8325EC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B4_G_, str_TXT_820D14C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC08, 0x8325EC08) { ctx.r3.u64 = InitGlobalString_ShadowLCheek1(ctx, base); }

uint64_t InitGlobalString_ShadowLCheek2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3B8_G_ = int32_t(0x8349B3B8);
	constexpr int32_t str_TXT_820D14D8_B_ = int32_t(0x820D14D8);
	constexpr int32_t Destroy_TXT_8349B3B8_G__address = int32_t(0x832A5E00);
	if (!UseLiftedCode(143, 0x8325EC48)) { __imp__sub_8325EC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3B8_G_, str_TXT_820D14D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3B8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC48, 0x8325EC48) { ctx.r3.u64 = InitGlobalString_ShadowLCheek2(ctx, base); }

uint64_t InitGlobalString_ShadowLJaw(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3BC_G_ = int32_t(0x8349B3BC);
	constexpr int32_t str_TXT_820D14E8_B_ = int32_t(0x820D14E8);
	constexpr int32_t Destroy_TXT_8349B3BC_G__address = int32_t(0x832A5E10);
	if (!UseLiftedCode(143, 0x8325EC88)) { __imp__sub_8325EC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EC88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3BC_G_, str_TXT_820D14E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3BC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EC88, 0x8325EC88) { ctx.r3.u64 = InitGlobalString_ShadowLJaw(ctx, base); }

uint64_t InitGlobalString_ShadowLEyeTarget(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C0_G_ = int32_t(0x8349B3C0);
	constexpr int32_t str_TXT_820D14F8_B_ = int32_t(0x820D14F8);
	constexpr int32_t Destroy_TXT_8349B3C0_G__address = int32_t(0x832A5E20);
	if (!UseLiftedCode(143, 0x8325ECC8)) { __imp__sub_8325ECC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ECC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C0_G_, str_TXT_820D14F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C0_G__address);
}
PROMOTED_ENTRY(143, sub_8325ECC8, 0x8325ECC8) { ctx.r3.u64 = InitGlobalString_ShadowLEyeTarget(ctx, base); }

uint64_t InitGlobalString_ShadowRBrowOuter(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C4_G_ = int32_t(0x8349B3C4);
	constexpr int32_t str_TXT_820D150C_B_ = int32_t(0x820D150C);
	constexpr int32_t Destroy_TXT_8349B3C4_G__address = int32_t(0x832A5E30);
	if (!UseLiftedCode(143, 0x8325ED08)) { __imp__sub_8325ED08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C4_G_, str_TXT_820D150C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C4_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED08, 0x8325ED08) { ctx.r3.u64 = InitGlobalString_ShadowRBrowOuter(ctx, base); }

uint64_t InitGlobalString_ShadowRBrowMid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3C8_G_ = int32_t(0x8349B3C8);
	constexpr int32_t str_TXT_820D1520_B_ = int32_t(0x820D1520);
	constexpr int32_t Destroy_TXT_8349B3C8_G__address = int32_t(0x832A5E40);
	if (!UseLiftedCode(143, 0x8325ED48)) { __imp__sub_8325ED48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3C8_G_, str_TXT_820D1520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3C8_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED48, 0x8325ED48) { ctx.r3.u64 = InitGlobalString_ShadowRBrowMid(ctx, base); }

uint64_t InitGlobalString_ShadowRBrowInner(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3CC_G_ = int32_t(0x8349B3CC);
	constexpr int32_t str_TXT_820D1534_B_ = int32_t(0x820D1534);
	constexpr int32_t Destroy_TXT_8349B3CC_G__address = int32_t(0x832A5E50);
	if (!UseLiftedCode(143, 0x8325ED88)) { __imp__sub_8325ED88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325ED88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3CC_G_, str_TXT_820D1534_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3CC_G__address);
}
PROMOTED_ENTRY(143, sub_8325ED88, 0x8325ED88) { ctx.r3.u64 = InitGlobalString_ShadowRBrowInner(ctx, base); }

uint64_t InitGlobalString_ShadowRTopEyeLid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D0_G_ = int32_t(0x8349B3D0);
	constexpr int32_t str_TXT_820D1548_B_ = int32_t(0x820D1548);
	constexpr int32_t Destroy_TXT_8349B3D0_G__address = int32_t(0x832A5E60);
	if (!UseLiftedCode(143, 0x8325EDC8)) { __imp__sub_8325EDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EDC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D0_G_, str_TXT_820D1548_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EDC8, 0x8325EDC8) { ctx.r3.u64 = InitGlobalString_ShadowRTopEyeLid(ctx, base); }

uint64_t InitGlobalString_ShadowRBotEyeLid(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D4_G_ = int32_t(0x8349B3D4);
	constexpr int32_t str_TXT_820D155C_B_ = int32_t(0x820D155C);
	constexpr int32_t Destroy_TXT_8349B3D4_G__address = int32_t(0x832A5E70);
	if (!UseLiftedCode(143, 0x8325EE08)) { __imp__sub_8325EE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D4_G_, str_TXT_820D155C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE08, 0x8325EE08) { ctx.r3.u64 = InitGlobalString_ShadowRBotEyeLid(ctx, base); }

uint64_t InitGlobalString_ShadowRSquint(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3D8_G_ = int32_t(0x8349B3D8);
	constexpr int32_t str_TXT_820D1570_B_ = int32_t(0x820D1570);
	constexpr int32_t Destroy_TXT_8349B3D8_G__address = int32_t(0x832A5E80);
	if (!UseLiftedCode(143, 0x8325EE48)) { __imp__sub_8325EE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3D8_G_, str_TXT_820D1570_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3D8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE48, 0x8325EE48) { ctx.r3.u64 = InitGlobalString_ShadowRSquint(ctx, base); }

uint64_t InitGlobalString_ShadowRCheek1(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3DC_G_ = int32_t(0x8349B3DC);
	constexpr int32_t str_TXT_820D1580_B_ = int32_t(0x820D1580);
	constexpr int32_t Destroy_TXT_8349B3DC_G__address = int32_t(0x832A5E90);
	if (!UseLiftedCode(143, 0x8325EE88)) { __imp__sub_8325EE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EE88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3DC_G_, str_TXT_820D1580_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3DC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EE88, 0x8325EE88) { ctx.r3.u64 = InitGlobalString_ShadowRCheek1(ctx, base); }

uint64_t InitGlobalString_ShadowRCheek2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E0_G_ = int32_t(0x8349B3E0);
	constexpr int32_t str_TXT_820D1590_B_ = int32_t(0x820D1590);
	constexpr int32_t Destroy_TXT_8349B3E0_G__address = int32_t(0x832A5EA0);
	if (!UseLiftedCode(143, 0x8325EEC8)) { __imp__sub_8325EEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E0_G_, str_TXT_820D1590_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EEC8, 0x8325EEC8) { ctx.r3.u64 = InitGlobalString_ShadowRCheek2(ctx, base); }

uint64_t InitGlobalString_ShadowRJaw(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E4_G_ = int32_t(0x8349B3E4);
	constexpr int32_t str_TXT_820D15A0_B_ = int32_t(0x820D15A0);
	constexpr int32_t Destroy_TXT_8349B3E4_G__address = int32_t(0x832A5EB0);
	if (!UseLiftedCode(143, 0x8325EF08)) { __imp__sub_8325EF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E4_G_, str_TXT_820D15A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E4_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF08, 0x8325EF08) { ctx.r3.u64 = InitGlobalString_ShadowRJaw(ctx, base); }

uint64_t InitGlobalString_ShadowREyeTarget(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3E8_G_ = int32_t(0x8349B3E8);
	constexpr int32_t str_TXT_820D15B0_B_ = int32_t(0x820D15B0);
	constexpr int32_t Destroy_TXT_8349B3E8_G__address = int32_t(0x832A5EC0);
	if (!UseLiftedCode(143, 0x8325EF48)) { __imp__sub_8325EF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3E8_G_, str_TXT_820D15B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3E8_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF48, 0x8325EF48) { ctx.r3.u64 = InitGlobalString_ShadowREyeTarget(ctx, base); }

uint64_t InitGlobalString_OnActionUseBase(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3EC_G_ = int32_t(0x8349B3EC);
	constexpr int32_t str_TXT_820D15C4_B_ = int32_t(0x820D15C4);
	constexpr int32_t Destroy_TXT_8349B3EC_G__address = int32_t(0x832A5ED0);
	if (!UseLiftedCode(143, 0x8325EF88)) { __imp__sub_8325EF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3EC_G_, str_TXT_820D15C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3EC_G__address);
}
PROMOTED_ENTRY(143, sub_8325EF88, 0x8325EF88) { ctx.r3.u64 = InitGlobalString_OnActionUseBase(ctx, base); }

uint64_t InitGlobalString_GUI_USE(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3F0_G_ = int32_t(0x8349B3F0);
	constexpr int32_t str_TXT_820D15D4_B_ = int32_t(0x820D15D4);
	constexpr int32_t Destroy_TXT_8349B3F0_G__address = int32_t(0x832A5EE0);
	if (!UseLiftedCode(143, 0x8325EFC8)) { __imp__sub_8325EFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325EFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F0_G_, str_TXT_820D15D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3F0_G__address);
}
PROMOTED_ENTRY(143, sub_8325EFC8, 0x8325EFC8) { ctx.r3.u64 = InitGlobalString_GUI_USE(ctx, base); }

uint64_t InitGlobalString_GUI_USE_STEAL(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B3F4_G_ = int32_t(0x8349B3F4);
	constexpr int32_t str_TXT_820D15DC_B_ = int32_t(0x820D15DC);
	constexpr int32_t Destroy_TXT_8349B3F4_G__address = int32_t(0x832A5EF0);
	if (!UseLiftedCode(143, 0x8325F008)) { __imp__sub_8325F008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B3F4_G_, str_TXT_820D15DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B3F4_G__address);
}
PROMOTED_ENTRY(143, sub_8325F008, 0x8325F008) { ctx.r3.u64 = InitGlobalString_GUI_USE_STEAL(ctx, base); }

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

uint64_t HashName_TXT_82000F58_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000F58_B_ = int32_t(0x82000F58);
	constexpr uint32_t g_HashOf_TXT_82000F58_B_ = 0x8349B430u;
	if (!UseLiftedCode(143, 0x8325F2C8)) { __imp__sub_8325F2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F2C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82000F58_B_);
	STORE32(g_HashOf_TXT_82000F58_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F2C8, 0x8325F2C8) { ctx.r3.u64 = HashName_TXT_82000F58_B_(ctx, base); }

uint64_t HashName_TXT_820D1798_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1798_B_ = int32_t(0x820D1798);
	constexpr uint32_t g_HashOf_TXT_820D1798_B_ = 0x8349B434u;
	if (!UseLiftedCode(143, 0x8325F300)) { __imp__sub_8325F300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F300);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1798_B_);
	STORE32(g_HashOf_TXT_820D1798_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F300, 0x8325F300) { ctx.r3.u64 = HashName_TXT_820D1798_B_(ctx, base); }

uint64_t HashName_TXT_820A90A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A90A8_B_ = int32_t(0x820A90A8);
	constexpr uint32_t g_HashOf_TXT_820A90A8_B_ = 0x8349B438u;
	if (!UseLiftedCode(143, 0x8325F338)) { __imp__sub_8325F338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F338);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A90A8_B_);
	STORE32(g_HashOf_TXT_820A90A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F338, 0x8325F338) { ctx.r3.u64 = HashName_TXT_820A90A8_B_(ctx, base); }

uint64_t HashName_TXT_820D17AC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D17AC_B_ = int32_t(0x820D17AC);
	constexpr uint32_t g_HashOf_TXT_820D17AC_B_ = 0x8349B43Cu;
	if (!UseLiftedCode(143, 0x8325F370)) { __imp__sub_8325F370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F370);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D17AC_B_);
	STORE32(g_HashOf_TXT_820D17AC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F370, 0x8325F370) { ctx.r3.u64 = HashName_TXT_820D17AC_B_(ctx, base); }

uint64_t HashName_TXT_820D17C0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D17C0_B_ = int32_t(0x820D17C0);
	constexpr uint32_t g_HashOf_TXT_820D17C0_B_ = 0x8349B440u;
	if (!UseLiftedCode(143, 0x8325F3A8)) { __imp__sub_8325F3A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F3A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D17C0_B_);
	STORE32(g_HashOf_TXT_820D17C0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F3A8, 0x8325F3A8) { ctx.r3.u64 = HashName_TXT_820D17C0_B_(ctx, base); }

uint64_t HashName_TXT_820D17CC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D17CC_B_ = int32_t(0x820D17CC);
	constexpr uint32_t g_HashOf_TXT_820D17CC_B_ = 0x8349B444u;
	if (!UseLiftedCode(143, 0x8325F3E0)) { __imp__sub_8325F3E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F3E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D17CC_B_);
	STORE32(g_HashOf_TXT_820D17CC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F3E0, 0x8325F3E0) { ctx.r3.u64 = HashName_TXT_820D17CC_B_(ctx, base); }

uint64_t HashName_TXT_820D17E8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D17E8_B_ = int32_t(0x820D17E8);
	constexpr uint32_t g_HashOf_TXT_820D17E8_B_ = 0x8349B448u;
	if (!UseLiftedCode(143, 0x8325F418)) { __imp__sub_8325F418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F418);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D17E8_B_);
	STORE32(g_HashOf_TXT_820D17E8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F418, 0x8325F418) { ctx.r3.u64 = HashName_TXT_820D17E8_B_(ctx, base); }

uint64_t HashName_TXT_820D1800_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1800_B_ = int32_t(0x820D1800);
	constexpr uint32_t g_HashOf_TXT_820D1800_B_ = 0x8349B44Cu;
	if (!UseLiftedCode(143, 0x8325F450)) { __imp__sub_8325F450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F450);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1800_B_);
	STORE32(g_HashOf_TXT_820D1800_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F450, 0x8325F450) { ctx.r3.u64 = HashName_TXT_820D1800_B_(ctx, base); }

uint64_t HashName_TXT_820A9080_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A9080_B_ = int32_t(0x820A9080);
	constexpr uint32_t g_HashOf_TXT_820A9080_B_ = 0x8349B450u;
	if (!UseLiftedCode(143, 0x8325F488)) { __imp__sub_8325F488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F488);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A9080_B_);
	STORE32(g_HashOf_TXT_820A9080_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F488, 0x8325F488) { ctx.r3.u64 = HashName_TXT_820A9080_B_(ctx, base); }

uint64_t HashName_TXT_820AF2DC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820AF2DC_B_ = int32_t(0x820AF2DC);
	constexpr uint32_t g_HashOf_TXT_820AF2DC_B_ = 0x8349B454u;
	if (!UseLiftedCode(143, 0x8325F4C0)) { __imp__sub_8325F4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F4C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820AF2DC_B_);
	STORE32(g_HashOf_TXT_820AF2DC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F4C0, 0x8325F4C0) { ctx.r3.u64 = HashName_TXT_820AF2DC_B_(ctx, base); }

uint64_t HashName_TXT_820D1808_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1808_B_ = int32_t(0x820D1808);
	constexpr uint32_t g_HashOf_TXT_820D1808_B_ = 0x8349B458u;
	if (!UseLiftedCode(143, 0x8325F4F8)) { __imp__sub_8325F4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F4F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1808_B_);
	STORE32(g_HashOf_TXT_820D1808_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F4F8, 0x8325F4F8) { ctx.r3.u64 = HashName_TXT_820D1808_B_(ctx, base); }

uint64_t HashName_TXT_820D181C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D181C_B_ = int32_t(0x820D181C);
	constexpr uint32_t g_HashOf_TXT_820D181C_B_ = 0x8349B45Cu;
	if (!UseLiftedCode(143, 0x8325F530)) { __imp__sub_8325F530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F530);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D181C_B_);
	STORE32(g_HashOf_TXT_820D181C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F530, 0x8325F530) { ctx.r3.u64 = HashName_TXT_820D181C_B_(ctx, base); }

uint64_t HashName_TXT_820A9098_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A9098_B_ = int32_t(0x820A9098);
	constexpr uint32_t g_HashOf_TXT_820A9098_B_ = 0x8349B460u;
	if (!UseLiftedCode(143, 0x8325F568)) { __imp__sub_8325F568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F568);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A9098_B_);
	STORE32(g_HashOf_TXT_820A9098_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F568, 0x8325F568) { ctx.r3.u64 = HashName_TXT_820A9098_B_(ctx, base); }

uint64_t HashName_TXT_820ADDFC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820ADDFC_B_ = int32_t(0x820ADDFC);
	constexpr uint32_t g_HashOf_TXT_820ADDFC_B_ = 0x8349B464u;
	if (!UseLiftedCode(143, 0x8325F5A0)) { __imp__sub_8325F5A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F5A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820ADDFC_B_);
	STORE32(g_HashOf_TXT_820ADDFC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F5A0, 0x8325F5A0) { ctx.r3.u64 = HashName_TXT_820ADDFC_B_(ctx, base); }

uint64_t HashName_TXT_820D1834_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1834_B_ = int32_t(0x820D1834);
	constexpr uint32_t g_HashOf_TXT_820D1834_B_ = 0x8349B468u;
	if (!UseLiftedCode(143, 0x8325F5D8)) { __imp__sub_8325F5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1834_B_);
	STORE32(g_HashOf_TXT_820D1834_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F5D8, 0x8325F5D8) { ctx.r3.u64 = HashName_TXT_820D1834_B_(ctx, base); }

uint64_t HashName_TXT_820D1840_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1840_B_ = int32_t(0x820D1840);
	constexpr uint32_t g_HashOf_TXT_820D1840_B_ = 0x8349B46Cu;
	if (!UseLiftedCode(143, 0x8325F610)) { __imp__sub_8325F610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F610);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1840_B_);
	STORE32(g_HashOf_TXT_820D1840_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F610, 0x8325F610) { ctx.r3.u64 = HashName_TXT_820D1840_B_(ctx, base); }

uint64_t HashName_TXT_820D1858_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1858_B_ = int32_t(0x820D1858);
	constexpr uint32_t g_HashOf_TXT_820D1858_B_ = 0x8349B470u;
	if (!UseLiftedCode(143, 0x8325F648)) { __imp__sub_8325F648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F648);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1858_B_);
	STORE32(g_HashOf_TXT_820D1858_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F648, 0x8325F648) { ctx.r3.u64 = HashName_TXT_820D1858_B_(ctx, base); }

uint64_t HashName_TXT_820D1870_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1870_B_ = int32_t(0x820D1870);
	constexpr uint32_t g_HashOf_TXT_820D1870_B_ = 0x8349B474u;
	if (!UseLiftedCode(143, 0x8325F680)) { __imp__sub_8325F680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F680);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1870_B_);
	STORE32(g_HashOf_TXT_820D1870_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F680, 0x8325F680) { ctx.r3.u64 = HashName_TXT_820D1870_B_(ctx, base); }

uint64_t HashName_TXT_820D188C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D188C_B_ = int32_t(0x820D188C);
	constexpr uint32_t g_HashOf_TXT_820D188C_B_ = 0x8349B478u;
	if (!UseLiftedCode(143, 0x8325F6B8)) { __imp__sub_8325F6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F6B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D188C_B_);
	STORE32(g_HashOf_TXT_820D188C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F6B8, 0x8325F6B8) { ctx.r3.u64 = HashName_TXT_820D188C_B_(ctx, base); }

uint64_t HashName_TXT_820D18A4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D18A4_B_ = int32_t(0x820D18A4);
	constexpr uint32_t g_HashOf_TXT_820D18A4_B_ = 0x8349B47Cu;
	if (!UseLiftedCode(143, 0x8325F6F0)) { __imp__sub_8325F6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F6F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D18A4_B_);
	STORE32(g_HashOf_TXT_820D18A4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F6F0, 0x8325F6F0) { ctx.r3.u64 = HashName_TXT_820D18A4_B_(ctx, base); }

uint64_t HashName_TXT_820C3EBC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C3EBC_B_ = int32_t(0x820C3EBC);
	constexpr uint32_t g_HashOf_TXT_820C3EBC_B_ = 0x8349B480u;
	if (!UseLiftedCode(143, 0x8325F728)) { __imp__sub_8325F728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F728);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C3EBC_B_);
	STORE32(g_HashOf_TXT_820C3EBC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F728, 0x8325F728) { ctx.r3.u64 = HashName_TXT_820C3EBC_B_(ctx, base); }

uint64_t HashName_TXT_820D18AC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D18AC_B_ = int32_t(0x820D18AC);
	constexpr uint32_t g_HashOf_TXT_820D18AC_B_ = 0x8349B484u;
	if (!UseLiftedCode(143, 0x8325F760)) { __imp__sub_8325F760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F760);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D18AC_B_);
	STORE32(g_HashOf_TXT_820D18AC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F760, 0x8325F760) { ctx.r3.u64 = HashName_TXT_820D18AC_B_(ctx, base); }

uint64_t HashName_TXT_820C37DC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C37DC_B_ = int32_t(0x820C37DC);
	constexpr uint32_t g_HashOf_TXT_820C37DC_B_ = 0x8349B488u;
	if (!UseLiftedCode(143, 0x8325F798)) { __imp__sub_8325F798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F798);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C37DC_B_);
	STORE32(g_HashOf_TXT_820C37DC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F798, 0x8325F798) { ctx.r3.u64 = HashName_TXT_820C37DC_B_(ctx, base); }

uint64_t HashName_TXT_820D18BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D18BC_B_ = int32_t(0x820D18BC);
	constexpr uint32_t g_HashOf_TXT_820D18BC_B_ = 0x8349B48Cu;
	if (!UseLiftedCode(143, 0x8325F7D0)) { __imp__sub_8325F7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F7D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D18BC_B_);
	STORE32(g_HashOf_TXT_820D18BC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F7D0, 0x8325F7D0) { ctx.r3.u64 = HashName_TXT_820D18BC_B_(ctx, base); }

uint64_t HashName_TXT_820D18D4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D18D4_B_ = int32_t(0x820D18D4);
	constexpr uint32_t g_HashOf_TXT_820D18D4_B_ = 0x8349B490u;
	if (!UseLiftedCode(143, 0x8325F808)) { __imp__sub_8325F808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F808);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D18D4_B_);
	STORE32(g_HashOf_TXT_820D18D4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F808, 0x8325F808) { ctx.r3.u64 = HashName_TXT_820D18D4_B_(ctx, base); }

uint64_t HashName_TXT_820BF448_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BF448_B_ = int32_t(0x820BF448);
	constexpr uint32_t g_HashOf_TXT_820BF448_B_ = 0x8349B494u;
	if (!UseLiftedCode(143, 0x8325F840)) { __imp__sub_8325F840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F840);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BF448_B_);
	STORE32(g_HashOf_TXT_820BF448_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F840, 0x8325F840) { ctx.r3.u64 = HashName_TXT_820BF448_B_(ctx, base); }

uint64_t HashName_TXT_820D18EC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D18EC_B_ = int32_t(0x820D18EC);
	constexpr uint32_t g_HashOf_TXT_820D18EC_B_ = 0x8349B498u;
	if (!UseLiftedCode(143, 0x8325F878)) { __imp__sub_8325F878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F878);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D18EC_B_);
	STORE32(g_HashOf_TXT_820D18EC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F878, 0x8325F878) { ctx.r3.u64 = HashName_TXT_820D18EC_B_(ctx, base); }

uint64_t HashName_TXT_820D1900_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1900_B_ = int32_t(0x820D1900);
	constexpr uint32_t g_HashOf_TXT_820D1900_B_ = 0x8349B49Cu;
	if (!UseLiftedCode(143, 0x8325F8B0)) { __imp__sub_8325F8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F8B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1900_B_);
	STORE32(g_HashOf_TXT_820D1900_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F8B0, 0x8325F8B0) { ctx.r3.u64 = HashName_TXT_820D1900_B_(ctx, base); }

uint64_t HashName_TXT_820D1910_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1910_B_ = int32_t(0x820D1910);
	constexpr uint32_t g_HashOf_TXT_820D1910_B_ = 0x8349B4A0u;
	if (!UseLiftedCode(143, 0x8325F8E8)) { __imp__sub_8325F8E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F8E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1910_B_);
	STORE32(g_HashOf_TXT_820D1910_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F8E8, 0x8325F8E8) { ctx.r3.u64 = HashName_TXT_820D1910_B_(ctx, base); }

uint64_t HashName_TXT_820C389C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C389C_B_ = int32_t(0x820C389C);
	constexpr uint32_t g_HashOf_TXT_820C389C_B_ = 0x8349B4A4u;
	if (!UseLiftedCode(143, 0x8325F920)) { __imp__sub_8325F920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F920);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C389C_B_);
	STORE32(g_HashOf_TXT_820C389C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F920, 0x8325F920) { ctx.r3.u64 = HashName_TXT_820C389C_B_(ctx, base); }

uint64_t HashName_TXT_820C38B4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C38B4_B_ = int32_t(0x820C38B4);
	constexpr uint32_t g_HashOf_TXT_820C38B4_B_ = 0x8349B4A8u;
	if (!UseLiftedCode(143, 0x8325F958)) { __imp__sub_8325F958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F958);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C38B4_B_);
	STORE32(g_HashOf_TXT_820C38B4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F958, 0x8325F958) { ctx.r3.u64 = HashName_TXT_820C38B4_B_(ctx, base); }

uint64_t HashName_TXT_820C38A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C38A8_B_ = int32_t(0x820C38A8);
	constexpr uint32_t g_HashOf_TXT_820C38A8_B_ = 0x8349B4ACu;
	if (!UseLiftedCode(143, 0x8325F990)) { __imp__sub_8325F990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F990);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C38A8_B_);
	STORE32(g_HashOf_TXT_820C38A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F990, 0x8325F990) { ctx.r3.u64 = HashName_TXT_820C38A8_B_(ctx, base); }

uint64_t HashName_TXT_820D1920_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1920_B_ = int32_t(0x820D1920);
	constexpr uint32_t g_HashOf_TXT_820D1920_B_ = 0x8349B4B0u;
	if (!UseLiftedCode(143, 0x8325F9C8)) { __imp__sub_8325F9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325F9C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1920_B_);
	STORE32(g_HashOf_TXT_820D1920_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325F9C8, 0x8325F9C8) { ctx.r3.u64 = HashName_TXT_820D1920_B_(ctx, base); }

uint64_t HashName_TXT_820D1930_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1930_B_ = int32_t(0x820D1930);
	constexpr uint32_t g_HashOf_TXT_820D1930_B_ = 0x8349B4B4u;
	if (!UseLiftedCode(143, 0x8325FA00)) { __imp__sub_8325FA00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FA00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1930_B_);
	STORE32(g_HashOf_TXT_820D1930_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FA00, 0x8325FA00) { ctx.r3.u64 = HashName_TXT_820D1930_B_(ctx, base); }

uint64_t HashName_TXT_820D1940_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1940_B_ = int32_t(0x820D1940);
	constexpr uint32_t g_HashOf_TXT_820D1940_B_ = 0x8349B4B8u;
	if (!UseLiftedCode(143, 0x8325FA38)) { __imp__sub_8325FA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FA38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1940_B_);
	STORE32(g_HashOf_TXT_820D1940_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FA38, 0x8325FA38) { ctx.r3.u64 = HashName_TXT_820D1940_B_(ctx, base); }

uint64_t HashName_TXT_820D1950_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1950_B_ = int32_t(0x820D1950);
	constexpr uint32_t g_HashOf_TXT_820D1950_B_ = 0x8349B4BCu;
	if (!UseLiftedCode(143, 0x8325FA70)) { __imp__sub_8325FA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FA70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1950_B_);
	STORE32(g_HashOf_TXT_820D1950_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FA70, 0x8325FA70) { ctx.r3.u64 = HashName_TXT_820D1950_B_(ctx, base); }

uint64_t HashName_TXT_820D1960_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1960_B_ = int32_t(0x820D1960);
	constexpr uint32_t g_HashOf_TXT_820D1960_B_ = 0x8349B4C0u;
	if (!UseLiftedCode(143, 0x8325FAA8)) { __imp__sub_8325FAA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FAA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1960_B_);
	STORE32(g_HashOf_TXT_820D1960_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FAA8, 0x8325FAA8) { ctx.r3.u64 = HashName_TXT_820D1960_B_(ctx, base); }

uint64_t HashName_TXT_820D1978_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D1978_B_ = int32_t(0x820D1978);
	constexpr uint32_t g_HashOf_TXT_820D1978_B_ = 0x8349B4C4u;
	if (!UseLiftedCode(143, 0x8325FAE0)) { __imp__sub_8325FAE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FAE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D1978_B_);
	STORE32(g_HashOf_TXT_820D1978_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FAE0, 0x8325FAE0) { ctx.r3.u64 = HashName_TXT_820D1978_B_(ctx, base); }

uint64_t HashName_TXT_820C7F34_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F34_B_ = int32_t(0x820C7F34);
	constexpr uint32_t g_HashOf_TXT_820C7F34_B_ = 0x8349B4C8u;
	if (!UseLiftedCode(143, 0x8325FB18)) { __imp__sub_8325FB18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FB18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F34_B_);
	STORE32(g_HashOf_TXT_820C7F34_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FB18, 0x8325FB18) { ctx.r3.u64 = HashName_TXT_820C7F34_B_(ctx, base); }

uint64_t HashName_TXT_820C7F48_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F48_B_ = int32_t(0x820C7F48);
	constexpr uint32_t g_HashOf_TXT_820C7F48_B_ = 0x8349B4CCu;
	if (!UseLiftedCode(143, 0x8325FB50)) { __imp__sub_8325FB50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FB50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F48_B_);
	STORE32(g_HashOf_TXT_820C7F48_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FB50, 0x8325FB50) { ctx.r3.u64 = HashName_TXT_820C7F48_B_(ctx, base); }

uint64_t HashName_TXT_820C7F54_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F54_B_ = int32_t(0x820C7F54);
	constexpr uint32_t g_HashOf_TXT_820C7F54_B_ = 0x8349B4D0u;
	if (!UseLiftedCode(143, 0x8325FB88)) { __imp__sub_8325FB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FB88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F54_B_);
	STORE32(g_HashOf_TXT_820C7F54_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FB88, 0x8325FB88) { ctx.r3.u64 = HashName_TXT_820C7F54_B_(ctx, base); }

uint64_t HashName_TXT_820C7F64_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F64_B_ = int32_t(0x820C7F64);
	constexpr uint32_t g_HashOf_TXT_820C7F64_B_ = 0x8349B4D4u;
	if (!UseLiftedCode(143, 0x8325FBC0)) { __imp__sub_8325FBC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FBC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F64_B_);
	STORE32(g_HashOf_TXT_820C7F64_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FBC0, 0x8325FBC0) { ctx.r3.u64 = HashName_TXT_820C7F64_B_(ctx, base); }

uint64_t HashName_TXT_820C7F70_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F70_B_ = int32_t(0x820C7F70);
	constexpr uint32_t g_HashOf_TXT_820C7F70_B_ = 0x8349B4D8u;
	if (!UseLiftedCode(143, 0x8325FBF8)) { __imp__sub_8325FBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FBF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F70_B_);
	STORE32(g_HashOf_TXT_820C7F70_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FBF8, 0x8325FBF8) { ctx.r3.u64 = HashName_TXT_820C7F70_B_(ctx, base); }

uint64_t HashName_TXT_820C7F80_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F80_B_ = int32_t(0x820C7F80);
	constexpr uint32_t g_HashOf_TXT_820C7F80_B_ = 0x8349B4DCu;
	if (!UseLiftedCode(143, 0x8325FC30)) { __imp__sub_8325FC30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FC30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F80_B_);
	STORE32(g_HashOf_TXT_820C7F80_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FC30, 0x8325FC30) { ctx.r3.u64 = HashName_TXT_820C7F80_B_(ctx, base); }

uint64_t HashName_TXT_820C7F90_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7F90_B_ = int32_t(0x820C7F90);
	constexpr uint32_t g_HashOf_TXT_820C7F90_B_ = 0x8349B4E0u;
	if (!UseLiftedCode(143, 0x8325FC68)) { __imp__sub_8325FC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FC68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7F90_B_);
	STORE32(g_HashOf_TXT_820C7F90_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_8325FC68, 0x8325FC68) { ctx.r3.u64 = HashName_TXT_820C7F90_B_(ctx, base); }

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

uint64_t n_sub_8325FD18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325FD18)) { __imp__sub_8325FD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FD18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 16);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 19224;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 24608, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FD18, 0x8325FD18) { ctx.r3.u64 = n_sub_8325FD18(ctx, base); }

uint64_t n_sub_8325FD78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(143, 0x8325FD78)) { __imp__sub_8325FD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FD78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint32_t head = operator_new(ctx, base, 20);
	if (head != 0) {
		STORE32(head, head);
	}
	if (head + 4 != 0) {
		STORE32(head + 4, head);
	}
	uint64_t container = (int64_t)g_834A0000 - 19212;
	STORE32((uint32_t)container + 4, head);
	STORE32((uint32_t)container + 8, 0u);
	ctx.r11.u64 = head;
	ctx.xer.ca = head > 4294967291;
	uint64_t result = RegisterAtExit(ctx, base, (int64_t)g_832A0000 + 24624, container);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8325FD78, 0x8325FD78) { ctx.r3.u64 = n_sub_8325FD78(ctx, base); }

uint64_t InitGlobalString_OnActionUseBase_8349B500(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B500_G_ = int32_t(0x8349B500);
	constexpr int32_t str_TXT_820D15C4_B_ = int32_t(0x820D15C4);
	constexpr int32_t Destroy_TXT_8349B500_G__address = int32_t(0x832A60F0);
	if (!UseLiftedCode(143, 0x8325FDD8)) { __imp__sub_8325FDD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FDD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B500_G_, str_TXT_820D15C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B500_G__address);
}
PROMOTED_ENTRY(143, sub_8325FDD8, 0x8325FDD8) { ctx.r3.u64 = InitGlobalString_OnActionUseBase_8349B500(ctx, base); }

uint64_t InitGlobalString_OnActionUseGamesMaster(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B504_G_ = int32_t(0x8349B504);
	constexpr int32_t str_TXT_820D5508_B_ = int32_t(0x820D5508);
	constexpr int32_t Destroy_TXT_8349B504_G__address = int32_t(0x832A6100);
	if (!UseLiftedCode(143, 0x8325FE18)) { __imp__sub_8325FE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B504_G_, str_TXT_820D5508_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B504_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE18, 0x8325FE18) { ctx.r3.u64 = InitGlobalString_OnActionUseGamesMaster(ctx, base); }

uint64_t InitGlobalString_OnActionUseTravelAgent(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B508_G_ = int32_t(0x8349B508);
	constexpr int32_t str_TXT_820D5520_B_ = int32_t(0x820D5520);
	constexpr int32_t Destroy_TXT_8349B508_G__address = int32_t(0x832A6110);
	if (!UseLiftedCode(143, 0x8325FE58)) { __imp__sub_8325FE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B508_G_, str_TXT_820D5520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B508_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE58, 0x8325FE58) { ctx.r3.u64 = InitGlobalString_OnActionUseTravelAgent(ctx, base); }

uint64_t InitGlobalString_TEXT_AI_HENCHMAN_REJECT(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B50C_G_ = int32_t(0x8349B50C);
	constexpr int32_t str_TXT_820D5538_B_ = int32_t(0x820D5538);
	constexpr int32_t Destroy_TXT_8349B50C_G__address = int32_t(0x832A6120);
	if (!UseLiftedCode(143, 0x8325FE98)) { __imp__sub_8325FE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FE98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B50C_G_, str_TXT_820D5538_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B50C_G__address);
}
PROMOTED_ENTRY(143, sub_8325FE98, 0x8325FE98) { ctx.r3.u64 = InitGlobalString_TEXT_AI_HENCHMAN_REJECT(ctx, base); }

uint64_t TextAIHenchmanGamesmasterReject_Init(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B510_G_ = int32_t(0x8349B510);
	constexpr int32_t str_TXT_820D5550_B_ = int32_t(0x820D5550);
	constexpr int32_t Destroy_TXT_8349B510_G__address = int32_t(0x832A6130);
	if (!UseLiftedCode(143, 0x8325FED8)) { __imp__sub_8325FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B510_G_, str_TXT_820D5550_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B510_G__address);
}
PROMOTED_ENTRY(143, sub_8325FED8, 0x8325FED8) { ctx.r3.u64 = TextAIHenchmanGamesmasterReject_Init(ctx, base); }

uint64_t TextDLC1ShopClosed_Init(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B514_G_ = int32_t(0x8349B514);
	constexpr int32_t str_TXT_820D5574_B_ = int32_t(0x820D5574);
	constexpr int32_t Destroy_TXT_8349B514_G__address = int32_t(0x832A6140);
	if (!UseLiftedCode(143, 0x8325FF18)) { __imp__sub_8325FF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8325FF18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B514_G_, str_TXT_820D5574_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B514_G__address);
}
PROMOTED_ENTRY(143, sub_8325FF18, 0x8325FF18) { ctx.r3.u64 = TextDLC1ShopClosed_Init(ctx, base); }
