// Start-up initialisers of global objects (they register property and definition names) at
// 0x8328xxxx, as readable C++.
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

uint64_t Construct_TXT_8349E5DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5DC_G_ = int32_t(0x8349E5DC);
	constexpr int32_t str_TXT_8209A62C_B_ = int32_t(0x8209A62C);
	constexpr int32_t Destroy_TXT_8349E5DC_G__address = int32_t(0x832AADA0);
	if (!UseLiftedCode(144, 0x83280008)) { __imp__sub_83280008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5DC_G_, str_TXT_8209A62C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5DC_G__address);
}
PROMOTED_ENTRY(144, sub_83280008, 0x83280008) { ctx.r3.u64 = Construct_TXT_8349E5DC_G_(ctx, base); }

uint64_t Construct_TXT_8349E5E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5E0_G_ = int32_t(0x8349E5E0);
	constexpr int32_t str_TXT_8209A62C_B_ = int32_t(0x8209A660);
	constexpr int32_t Destroy_TXT_8349E5E0_G__address = int32_t(0x832AADB0);
	if (!UseLiftedCode(144, 0x83280048)) { __imp__sub_83280048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E0_G_, str_TXT_8209A62C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5E0_G__address);
}
PROMOTED_ENTRY(144, sub_83280048, 0x83280048) { ctx.r3.u64 = Construct_TXT_8349E5E0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5E4_G_ = int32_t(0x8349E5E4);
	constexpr int32_t str_TXT_8209A694_B_ = int32_t(0x8209A694);
	constexpr int32_t Destroy_TXT_8349E5E4_G__address = int32_t(0x832AADC0);
	if (!UseLiftedCode(144, 0x83280088)) { __imp__sub_83280088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E4_G_, str_TXT_8209A694_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5E4_G__address);
}
PROMOTED_ENTRY(144, sub_83280088, 0x83280088) { ctx.r3.u64 = Construct_TXT_8349E5E4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5E8_G_ = int32_t(0x8349E5E8);
	constexpr int32_t str_TXT_8209A62C_B_ = int32_t(0x8209A698);
	constexpr int32_t Destroy_TXT_8349E5E8_G__address = int32_t(0x832AADD0);
	if (!UseLiftedCode(144, 0x832800C8)) { __imp__sub_832800C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832800C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E8_G_, str_TXT_8209A62C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5E8_G__address);
}
PROMOTED_ENTRY(144, sub_832800C8, 0x832800C8) { ctx.r3.u64 = Construct_TXT_8349E5E8_G_(ctx, base); }

uint64_t Construct_TXT_8349E5EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5EC_G_ = int32_t(0x8349E5EC);
	constexpr int32_t str_TXT_8209A6C8_B_ = int32_t(0x8209A6C8);
	constexpr int32_t Destroy_TXT_8349E5EC_G__address = int32_t(0x832AADE0);
	if (!UseLiftedCode(144, 0x83280108)) { __imp__sub_83280108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5EC_G_, str_TXT_8209A6C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5EC_G__address);
}
PROMOTED_ENTRY(144, sub_83280108, 0x83280108) { ctx.r3.u64 = Construct_TXT_8349E5EC_G_(ctx, base); }

uint64_t Construct_TXT_8349E5F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5F0_G_ = int32_t(0x8349E5F0);
	constexpr int32_t str_TXT_8209A6D8_B_ = int32_t(0x8209A6D8);
	constexpr int32_t Destroy_TXT_8349E5F0_G__address = int32_t(0x832AADF0);
	if (!UseLiftedCode(144, 0x83280148)) { __imp__sub_83280148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F0_G_, str_TXT_8209A6D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5F0_G__address);
}
PROMOTED_ENTRY(144, sub_83280148, 0x83280148) { ctx.r3.u64 = Construct_TXT_8349E5F0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5F4_G_ = int32_t(0x8349E5F4);
	constexpr int32_t str_TXT_8209A6E4_B_ = int32_t(0x8209A6E4);
	constexpr int32_t Destroy_TXT_8349E5F4_G__address = int32_t(0x832AAE00);
	if (!UseLiftedCode(144, 0x83280188)) { __imp__sub_83280188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F4_G_, str_TXT_8209A6E4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5F4_G__address);
}
PROMOTED_ENTRY(144, sub_83280188, 0x83280188) { ctx.r3.u64 = Construct_TXT_8349E5F4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5F8_G_ = int32_t(0x8349E5F8);
	constexpr int32_t str_TXT_8209A6F8_B_ = int32_t(0x8209A6F8);
	constexpr int32_t Destroy_TXT_8349E5F8_G__address = int32_t(0x832AAE10);
	if (!UseLiftedCode(144, 0x832801C8)) { __imp__sub_832801C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832801C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F8_G_, str_TXT_8209A6F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5F8_G__address);
}
PROMOTED_ENTRY(144, sub_832801C8, 0x832801C8) { ctx.r3.u64 = Construct_TXT_8349E5F8_G_(ctx, base); }

uint64_t Construct_TXT_8349E5FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5FC_G_ = int32_t(0x8349E5FC);
	constexpr int32_t str_TXT_8209A704_B_ = int32_t(0x8209A704);
	constexpr int32_t Destroy_TXT_8349E5FC_G__address = int32_t(0x832AAE20);
	if (!UseLiftedCode(144, 0x83280208)) { __imp__sub_83280208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5FC_G_, str_TXT_8209A704_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5FC_G__address);
}
PROMOTED_ENTRY(144, sub_83280208, 0x83280208) { ctx.r3.u64 = Construct_TXT_8349E5FC_G_(ctx, base); }

uint64_t Construct_TXT_8349E600_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E600_G_ = int32_t(0x8349E600);
	constexpr int32_t str_TXT_8209A714_B_ = int32_t(0x8209A714);
	constexpr int32_t Destroy_TXT_8349E600_G__address = int32_t(0x832AAE30);
	if (!UseLiftedCode(144, 0x83280248)) { __imp__sub_83280248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E600_G_, str_TXT_8209A714_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E600_G__address);
}
PROMOTED_ENTRY(144, sub_83280248, 0x83280248) { ctx.r3.u64 = Construct_TXT_8349E600_G_(ctx, base); }

uint64_t Construct_TXT_8349E604_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E604_G_ = int32_t(0x8349E604);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A464);
	constexpr int32_t Destroy_TXT_8349E604_G__address = int32_t(0x832AAE40);
	if (!UseLiftedCode(144, 0x83280288)) { __imp__sub_83280288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E604_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E604_G__address);
}
PROMOTED_ENTRY(144, sub_83280288, 0x83280288) { ctx.r3.u64 = Construct_TXT_8349E604_G_(ctx, base); }

uint64_t Construct_TXT_8349E608_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E608_G_ = int32_t(0x8349E608);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A46C);
	constexpr int32_t Destroy_TXT_8349E608_G__address = int32_t(0x832AAE50);
	if (!UseLiftedCode(144, 0x832802C8)) { __imp__sub_832802C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832802C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E608_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E608_G__address);
}
PROMOTED_ENTRY(144, sub_832802C8, 0x832802C8) { ctx.r3.u64 = Construct_TXT_8349E608_G_(ctx, base); }

uint64_t Construct_TXT_8349E60C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E60C_G_ = int32_t(0x8349E60C);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A480);
	constexpr int32_t Destroy_TXT_8349E60C_G__address = int32_t(0x832AAE60);
	if (!UseLiftedCode(144, 0x83280308)) { __imp__sub_83280308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E60C_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E60C_G__address);
}
PROMOTED_ENTRY(144, sub_83280308, 0x83280308) { ctx.r3.u64 = Construct_TXT_8349E60C_G_(ctx, base); }

uint64_t Construct_TXT_8349E610_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E610_G_ = int32_t(0x8349E610);
	constexpr int32_t str_TXT_8209A494_B_ = int32_t(0x8209A494);
	constexpr int32_t Destroy_TXT_8349E610_G__address = int32_t(0x832AAE70);
	if (!UseLiftedCode(144, 0x83280348)) { __imp__sub_83280348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E610_G_, str_TXT_8209A494_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E610_G__address);
}
PROMOTED_ENTRY(144, sub_83280348, 0x83280348) { ctx.r3.u64 = Construct_TXT_8349E610_G_(ctx, base); }

uint64_t Construct_TXT_8349E614_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E614_G_ = int32_t(0x8349E614);
	constexpr int32_t str_TXT_8209A4AC_B_ = int32_t(0x8209A4AC);
	constexpr int32_t Destroy_TXT_8349E614_G__address = int32_t(0x832AAE80);
	if (!UseLiftedCode(144, 0x83280388)) { __imp__sub_83280388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E614_G_, str_TXT_8209A4AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E614_G__address);
}
PROMOTED_ENTRY(144, sub_83280388, 0x83280388) { ctx.r3.u64 = Construct_TXT_8349E614_G_(ctx, base); }

uint64_t Construct_TXT_8349E618_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E618_G_ = int32_t(0x8349E618);
	constexpr int32_t str_TXT_8209A4BC_B_ = int32_t(0x8209A4BC);
	constexpr int32_t Destroy_TXT_8349E618_G__address = int32_t(0x832AAE90);
	if (!UseLiftedCode(144, 0x832803C8)) { __imp__sub_832803C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832803C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E618_G_, str_TXT_8209A4BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E618_G__address);
}
PROMOTED_ENTRY(144, sub_832803C8, 0x832803C8) { ctx.r3.u64 = Construct_TXT_8349E618_G_(ctx, base); }

uint64_t Construct_TXT_8349E61C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E61C_G_ = int32_t(0x8349E61C);
	constexpr int32_t str_TXT_8209A4D4_B_ = int32_t(0x8209A4D4);
	constexpr int32_t Destroy_TXT_8349E61C_G__address = int32_t(0x832AAEA0);
	if (!UseLiftedCode(144, 0x83280408)) { __imp__sub_83280408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E61C_G_, str_TXT_8209A4D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E61C_G__address);
}
PROMOTED_ENTRY(144, sub_83280408, 0x83280408) { ctx.r3.u64 = Construct_TXT_8349E61C_G_(ctx, base); }

uint64_t Construct_TXT_8349E620_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E620_G_ = int32_t(0x8349E620);
	constexpr int32_t str_TXT_8209A4E8_B_ = int32_t(0x8209A4E8);
	constexpr int32_t Destroy_TXT_8349E620_G__address = int32_t(0x832AAEB0);
	if (!UseLiftedCode(144, 0x83280448)) { __imp__sub_83280448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E620_G_, str_TXT_8209A4E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E620_G__address);
}
PROMOTED_ENTRY(144, sub_83280448, 0x83280448) { ctx.r3.u64 = Construct_TXT_8349E620_G_(ctx, base); }

uint64_t Construct_TXT_8349E624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E624_G_ = int32_t(0x8349E624);
	constexpr int32_t str_TXT_8209A4FC_B_ = int32_t(0x8209A4FC);
	constexpr int32_t Destroy_TXT_8349E624_G__address = int32_t(0x832AAEC0);
	if (!UseLiftedCode(144, 0x83280488)) { __imp__sub_83280488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E624_G_, str_TXT_8209A4FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E624_G__address);
}
PROMOTED_ENTRY(144, sub_83280488, 0x83280488) { ctx.r3.u64 = Construct_TXT_8349E624_G_(ctx, base); }

uint64_t Construct_TXT_8349E628_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E628_G_ = int32_t(0x8349E628);
	constexpr int32_t str_TXT_8209A50C_B_ = int32_t(0x8209A50C);
	constexpr int32_t Destroy_TXT_8349E628_G__address = int32_t(0x832AAED0);
	if (!UseLiftedCode(144, 0x832804C8)) { __imp__sub_832804C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832804C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E628_G_, str_TXT_8209A50C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E628_G__address);
}
PROMOTED_ENTRY(144, sub_832804C8, 0x832804C8) { ctx.r3.u64 = Construct_TXT_8349E628_G_(ctx, base); }

uint64_t Construct_TXT_8349E62C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E62C_G_ = int32_t(0x8349E62C);
	constexpr int32_t str_TXT_8209A520_B_ = int32_t(0x8209A520);
	constexpr int32_t Destroy_TXT_8349E62C_G__address = int32_t(0x832AAEE0);
	if (!UseLiftedCode(144, 0x83280508)) { __imp__sub_83280508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E62C_G_, str_TXT_8209A520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E62C_G__address);
}
PROMOTED_ENTRY(144, sub_83280508, 0x83280508) { ctx.r3.u64 = Construct_TXT_8349E62C_G_(ctx, base); }

uint64_t Construct_TXT_8349E630_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E630_G_ = int32_t(0x8349E630);
	constexpr int32_t str_TXT_8209A534_B_ = int32_t(0x8209A534);
	constexpr int32_t Destroy_TXT_8349E630_G__address = int32_t(0x832AAEF0);
	if (!UseLiftedCode(144, 0x83280548)) { __imp__sub_83280548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E630_G_, str_TXT_8209A534_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E630_G__address);
}
PROMOTED_ENTRY(144, sub_83280548, 0x83280548) { ctx.r3.u64 = Construct_TXT_8349E630_G_(ctx, base); }

uint64_t Construct_TXT_8349E634_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E634_G_ = int32_t(0x8349E634);
	constexpr int32_t str_TXT_8209A54C_B_ = int32_t(0x8209A54C);
	constexpr int32_t Destroy_TXT_8349E634_G__address = int32_t(0x832AAF00);
	if (!UseLiftedCode(144, 0x83280588)) { __imp__sub_83280588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E634_G_, str_TXT_8209A54C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E634_G__address);
}
PROMOTED_ENTRY(144, sub_83280588, 0x83280588) { ctx.r3.u64 = Construct_TXT_8349E634_G_(ctx, base); }

uint64_t Construct_TXT_8349E638_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E638_G_ = int32_t(0x8349E638);
	constexpr int32_t str_TXT_8209A560_B_ = int32_t(0x8209A560);
	constexpr int32_t Destroy_TXT_8349E638_G__address = int32_t(0x832AAF10);
	if (!UseLiftedCode(144, 0x832805C8)) { __imp__sub_832805C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832805C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E638_G_, str_TXT_8209A560_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E638_G__address);
}
PROMOTED_ENTRY(144, sub_832805C8, 0x832805C8) { ctx.r3.u64 = Construct_TXT_8349E638_G_(ctx, base); }

uint64_t Construct_TXT_8349E63C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E63C_G_ = int32_t(0x8349E63C);
	constexpr int32_t str_TXT_8209A570_B_ = int32_t(0x8209A570);
	constexpr int32_t Destroy_TXT_8349E63C_G__address = int32_t(0x832AAF20);
	if (!UseLiftedCode(144, 0x83280608)) { __imp__sub_83280608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E63C_G_, str_TXT_8209A570_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E63C_G__address);
}
PROMOTED_ENTRY(144, sub_83280608, 0x83280608) { ctx.r3.u64 = Construct_TXT_8349E63C_G_(ctx, base); }

uint64_t Construct_TXT_8349E640_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E640_G_ = int32_t(0x8349E640);
	constexpr int32_t str_TXT_8209A418_B_ = int32_t(0x8209A418);
	constexpr int32_t Destroy_TXT_8349E640_G__address = int32_t(0x832AAF30);
	if (!UseLiftedCode(144, 0x83280648)) { __imp__sub_83280648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E640_G_, str_TXT_8209A418_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E640_G__address);
}
PROMOTED_ENTRY(144, sub_83280648, 0x83280648) { ctx.r3.u64 = Construct_TXT_8349E640_G_(ctx, base); }

uint64_t Construct_TXT_8349E644_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E644_G_ = int32_t(0x8349E644);
	constexpr int32_t str_TXT_8209A428_B_ = int32_t(0x8209A428);
	constexpr int32_t Destroy_TXT_8349E644_G__address = int32_t(0x832AAF40);
	if (!UseLiftedCode(144, 0x83280688)) { __imp__sub_83280688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280688);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E644_G_, str_TXT_8209A428_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E644_G__address);
}
PROMOTED_ENTRY(144, sub_83280688, 0x83280688) { ctx.r3.u64 = Construct_TXT_8349E644_G_(ctx, base); }

uint64_t Construct_TXT_8349E648_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E648_G_ = int32_t(0x8349E648);
	constexpr int32_t str_TXT_8209A694_B_ = int32_t(0x8209A438);
	constexpr int32_t Destroy_TXT_8349E648_G__address = int32_t(0x832AAF50);
	if (!UseLiftedCode(144, 0x832806C8)) { __imp__sub_832806C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832806C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E648_G_, str_TXT_8209A694_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E648_G__address);
}
PROMOTED_ENTRY(144, sub_832806C8, 0x832806C8) { ctx.r3.u64 = Construct_TXT_8349E648_G_(ctx, base); }

uint64_t Construct_TXT_8349E64C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E64C_G_ = int32_t(0x8349E64C);
	constexpr int32_t str_TXT_8209A43C_B_ = int32_t(0x8209A43C);
	constexpr int32_t Destroy_TXT_8349E64C_G__address = int32_t(0x832AAF60);
	if (!UseLiftedCode(144, 0x83280708)) { __imp__sub_83280708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E64C_G_, str_TXT_8209A43C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E64C_G__address);
}
PROMOTED_ENTRY(144, sub_83280708, 0x83280708) { ctx.r3.u64 = Construct_TXT_8349E64C_G_(ctx, base); }

uint64_t Construct_TXT_8349E650_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E650_G_ = int32_t(0x8349E650);
	constexpr int32_t str_TXT_8209A448_B_ = int32_t(0x8209A448);
	constexpr int32_t Destroy_TXT_8349E650_G__address = int32_t(0x832AAF70);
	if (!UseLiftedCode(144, 0x83280748)) { __imp__sub_83280748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280748);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E650_G_, str_TXT_8209A448_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E650_G__address);
}
PROMOTED_ENTRY(144, sub_83280748, 0x83280748) { ctx.r3.u64 = Construct_TXT_8349E650_G_(ctx, base); }

uint64_t Construct_TXT_8349E654_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E654_G_ = int32_t(0x8349E654);
	constexpr int32_t str_TXT_8209A454_B_ = int32_t(0x8209A454);
	constexpr int32_t Destroy_TXT_8349E654_G__address = int32_t(0x832AAF80);
	if (!UseLiftedCode(144, 0x83280788)) { __imp__sub_83280788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E654_G_, str_TXT_8209A454_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E654_G__address);
}
PROMOTED_ENTRY(144, sub_83280788, 0x83280788) { ctx.r3.u64 = Construct_TXT_8349E654_G_(ctx, base); }

uint64_t Construct_TXT_8349E658_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E658_G_ = int32_t(0x8349E658);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A45C);
	constexpr int32_t Destroy_TXT_8349E658_G__address = int32_t(0x832AAF90);
	if (!UseLiftedCode(144, 0x832807C8)) { __imp__sub_832807C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832807C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E658_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E658_G__address);
}
PROMOTED_ENTRY(144, sub_832807C8, 0x832807C8) { ctx.r3.u64 = Construct_TXT_8349E658_G_(ctx, base); }

uint64_t Construct_TXT_8349E65C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E65C_G_ = int32_t(0x8349E65C);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A364);
	constexpr int32_t Destroy_TXT_8349E65C_G__address = int32_t(0x832AAFA0);
	if (!UseLiftedCode(144, 0x83280808)) { __imp__sub_83280808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E65C_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E65C_G__address);
}
PROMOTED_ENTRY(144, sub_83280808, 0x83280808) { ctx.r3.u64 = Construct_TXT_8349E65C_G_(ctx, base); }

uint64_t Construct_TXT_8349E660_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E660_G_ = int32_t(0x8349E660);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A36C);
	constexpr int32_t Destroy_TXT_8349E660_G__address = int32_t(0x832AAFB0);
	if (!UseLiftedCode(144, 0x83280848)) { __imp__sub_83280848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E660_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E660_G__address);
}
PROMOTED_ENTRY(144, sub_83280848, 0x83280848) { ctx.r3.u64 = Construct_TXT_8349E660_G_(ctx, base); }

uint64_t Construct_TXT_8349E664_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E664_G_ = int32_t(0x8349E664);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A380);
	constexpr int32_t Destroy_TXT_8349E664_G__address = int32_t(0x832AAFC0);
	if (!UseLiftedCode(144, 0x83280888)) { __imp__sub_83280888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E664_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E664_G__address);
}
PROMOTED_ENTRY(144, sub_83280888, 0x83280888) { ctx.r3.u64 = Construct_TXT_8349E664_G_(ctx, base); }

uint64_t Construct_TXT_8349E668_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E668_G_ = int32_t(0x8349E668);
	constexpr int32_t str_TXT_8209A394_B_ = int32_t(0x8209A394);
	constexpr int32_t Destroy_TXT_8349E668_G__address = int32_t(0x832AAFD0);
	if (!UseLiftedCode(144, 0x832808C8)) { __imp__sub_832808C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832808C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E668_G_, str_TXT_8209A394_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E668_G__address);
}
PROMOTED_ENTRY(144, sub_832808C8, 0x832808C8) { ctx.r3.u64 = Construct_TXT_8349E668_G_(ctx, base); }

uint64_t Construct_TXT_8349E66C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E66C_G_ = int32_t(0x8349E66C);
	constexpr int32_t str_TXT_8209A4BC_B_ = int32_t(0x8209A3AC);
	constexpr int32_t Destroy_TXT_8349E66C_G__address = int32_t(0x832AAFE0);
	if (!UseLiftedCode(144, 0x83280908)) { __imp__sub_83280908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E66C_G_, str_TXT_8209A4BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E66C_G__address);
}
PROMOTED_ENTRY(144, sub_83280908, 0x83280908) { ctx.r3.u64 = Construct_TXT_8349E66C_G_(ctx, base); }

uint64_t Construct_TXT_8349E670_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E670_G_ = int32_t(0x8349E670);
	constexpr int32_t str_TXT_8209A3C4_B_ = int32_t(0x8209A3C4);
	constexpr int32_t Destroy_TXT_8349E670_G__address = int32_t(0x832AAFF0);
	if (!UseLiftedCode(144, 0x83280948)) { __imp__sub_83280948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E670_G_, str_TXT_8209A3C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E670_G__address);
}
PROMOTED_ENTRY(144, sub_83280948, 0x83280948) { ctx.r3.u64 = Construct_TXT_8349E670_G_(ctx, base); }

uint64_t Construct_TXT_8349E674_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E674_G_ = int32_t(0x8349E674);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A2C8);
	constexpr int32_t Destroy_TXT_8349E674_G__address = int32_t(0x832AB000);
	if (!UseLiftedCode(144, 0x83280988)) { __imp__sub_83280988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E674_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E674_G__address);
}
PROMOTED_ENTRY(144, sub_83280988, 0x83280988) { ctx.r3.u64 = Construct_TXT_8349E674_G_(ctx, base); }

uint64_t Construct_TXT_8349E678_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E678_G_ = int32_t(0x8349E678);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A2D0);
	constexpr int32_t Destroy_TXT_8349E678_G__address = int32_t(0x832AB010);
	if (!UseLiftedCode(144, 0x832809C8)) { __imp__sub_832809C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832809C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E678_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E678_G__address);
}
PROMOTED_ENTRY(144, sub_832809C8, 0x832809C8) { ctx.r3.u64 = Construct_TXT_8349E678_G_(ctx, base); }

uint64_t Construct_TXT_8349E67C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E67C_G_ = int32_t(0x8349E67C);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A2E4);
	constexpr int32_t Destroy_TXT_8349E67C_G__address = int32_t(0x832AB020);
	if (!UseLiftedCode(144, 0x83280A08)) { __imp__sub_83280A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E67C_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E67C_G__address);
}
PROMOTED_ENTRY(144, sub_83280A08, 0x83280A08) { ctx.r3.u64 = Construct_TXT_8349E67C_G_(ctx, base); }

uint64_t Construct_TXT_8349E680_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E680_G_ = int32_t(0x8349E680);
	constexpr int32_t str_TXT_8209A2F8_B_ = int32_t(0x8209A2F8);
	constexpr int32_t Destroy_TXT_8349E680_G__address = int32_t(0x832AB030);
	if (!UseLiftedCode(144, 0x83280A48)) { __imp__sub_83280A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E680_G_, str_TXT_8209A2F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E680_G__address);
}
PROMOTED_ENTRY(144, sub_83280A48, 0x83280A48) { ctx.r3.u64 = Construct_TXT_8349E680_G_(ctx, base); }

uint64_t Construct_TXT_8349E684_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E684_G_ = int32_t(0x8349E684);
	constexpr int32_t str_TXT_8209A4BC_B_ = int32_t(0x8209A30C);
	constexpr int32_t Destroy_TXT_8349E684_G__address = int32_t(0x832AB040);
	if (!UseLiftedCode(144, 0x83280A88)) { __imp__sub_83280A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E684_G_, str_TXT_8209A4BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E684_G__address);
}
PROMOTED_ENTRY(144, sub_83280A88, 0x83280A88) { ctx.r3.u64 = Construct_TXT_8349E684_G_(ctx, base); }

uint64_t Construct_TXT_8349E688_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E688_G_ = int32_t(0x8349E688);
	constexpr int32_t str_TXT_8209A324_B_ = int32_t(0x8209A324);
	constexpr int32_t Destroy_TXT_8349E688_G__address = int32_t(0x832AB050);
	if (!UseLiftedCode(144, 0x83280AC8)) { __imp__sub_83280AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E688_G_, str_TXT_8209A324_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E688_G__address);
}
PROMOTED_ENTRY(144, sub_83280AC8, 0x83280AC8) { ctx.r3.u64 = Construct_TXT_8349E688_G_(ctx, base); }

uint64_t Construct_TXT_8349E68C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E68C_G_ = int32_t(0x8349E68C);
	constexpr int32_t str_TXT_8209A334_B_ = int32_t(0x8209A334);
	constexpr int32_t Destroy_TXT_8349E68C_G__address = int32_t(0x832AB060);
	if (!UseLiftedCode(144, 0x83280B08)) { __imp__sub_83280B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E68C_G_, str_TXT_8209A334_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E68C_G__address);
}
PROMOTED_ENTRY(144, sub_83280B08, 0x83280B08) { ctx.r3.u64 = Construct_TXT_8349E68C_G_(ctx, base); }

uint64_t Construct_TXT_8349E690_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E690_G_ = int32_t(0x8349E690);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A24C);
	constexpr int32_t Destroy_TXT_8349E690_G__address = int32_t(0x832AB070);
	if (!UseLiftedCode(144, 0x83280B48)) { __imp__sub_83280B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E690_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E690_G__address);
}
PROMOTED_ENTRY(144, sub_83280B48, 0x83280B48) { ctx.r3.u64 = Construct_TXT_8349E690_G_(ctx, base); }

uint64_t Construct_TXT_8349E694_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E694_G_ = int32_t(0x8349E694);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A254);
	constexpr int32_t Destroy_TXT_8349E694_G__address = int32_t(0x832AB080);
	if (!UseLiftedCode(144, 0x83280B88)) { __imp__sub_83280B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E694_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E694_G__address);
}
PROMOTED_ENTRY(144, sub_83280B88, 0x83280B88) { ctx.r3.u64 = Construct_TXT_8349E694_G_(ctx, base); }

uint64_t Construct_TXT_8349E698_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E698_G_ = int32_t(0x8349E698);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A268);
	constexpr int32_t Destroy_TXT_8349E698_G__address = int32_t(0x832AB090);
	if (!UseLiftedCode(144, 0x83280BC8)) { __imp__sub_83280BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280BC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E698_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E698_G__address);
}
PROMOTED_ENTRY(144, sub_83280BC8, 0x83280BC8) { ctx.r3.u64 = Construct_TXT_8349E698_G_(ctx, base); }

uint64_t Construct_TXT_8349E69C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E69C_G_ = int32_t(0x8349E69C);
	constexpr int32_t str_TXT_8209A27C_B_ = int32_t(0x8209A27C);
	constexpr int32_t Destroy_TXT_8349E69C_G__address = int32_t(0x832AB0A0);
	if (!UseLiftedCode(144, 0x83280C08)) { __imp__sub_83280C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E69C_G_, str_TXT_8209A27C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E69C_G__address);
}
PROMOTED_ENTRY(144, sub_83280C08, 0x83280C08) { ctx.r3.u64 = Construct_TXT_8349E69C_G_(ctx, base); }

uint64_t Construct_TXT_8349E6A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6A0_G_ = int32_t(0x8349E6A0);
	constexpr int32_t str_TXT_8209A4BC_B_ = int32_t(0x8209A294);
	constexpr int32_t Destroy_TXT_8349E6A0_G__address = int32_t(0x832AB0B0);
	if (!UseLiftedCode(144, 0x83280C48)) { __imp__sub_83280C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A0_G_, str_TXT_8209A4BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6A0_G__address);
}
PROMOTED_ENTRY(144, sub_83280C48, 0x83280C48) { ctx.r3.u64 = Construct_TXT_8349E6A0_G_(ctx, base); }

uint64_t Construct_TXT_8349E6A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6A4_G_ = int32_t(0x8349E6A4);
	constexpr int32_t str_TXT_8209A2AC_B_ = int32_t(0x8209A2AC);
	constexpr int32_t Destroy_TXT_8349E6A4_G__address = int32_t(0x832AB0C0);
	if (!UseLiftedCode(144, 0x83280C88)) { __imp__sub_83280C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A4_G_, str_TXT_8209A2AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6A4_G__address);
}
PROMOTED_ENTRY(144, sub_83280C88, 0x83280C88) { ctx.r3.u64 = Construct_TXT_8349E6A4_G_(ctx, base); }

uint64_t Construct_TXT_8349E6A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6A8_G_ = int32_t(0x8349E6A8);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A1A0);
	constexpr int32_t Destroy_TXT_8349E6A8_G__address = int32_t(0x832AB0D0);
	if (!UseLiftedCode(144, 0x83280CC8)) { __imp__sub_83280CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A8_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6A8_G__address);
}
PROMOTED_ENTRY(144, sub_83280CC8, 0x83280CC8) { ctx.r3.u64 = Construct_TXT_8349E6A8_G_(ctx, base); }

uint64_t Construct_TXT_8349E6AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6AC_G_ = int32_t(0x8349E6AC);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A1A8);
	constexpr int32_t Destroy_TXT_8349E6AC_G__address = int32_t(0x832AB0E0);
	if (!UseLiftedCode(144, 0x83280D08)) { __imp__sub_83280D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6AC_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6AC_G__address);
}
PROMOTED_ENTRY(144, sub_83280D08, 0x83280D08) { ctx.r3.u64 = Construct_TXT_8349E6AC_G_(ctx, base); }

uint64_t Construct_TXT_8349E6B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6B0_G_ = int32_t(0x8349E6B0);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A1BC);
	constexpr int32_t Destroy_TXT_8349E6B0_G__address = int32_t(0x832AB0F0);
	if (!UseLiftedCode(144, 0x83280D48)) { __imp__sub_83280D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B0_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6B0_G__address);
}
PROMOTED_ENTRY(144, sub_83280D48, 0x83280D48) { ctx.r3.u64 = Construct_TXT_8349E6B0_G_(ctx, base); }

uint64_t Construct_TXT_8349E6B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6B4_G_ = int32_t(0x8349E6B4);
	constexpr int32_t str_TXT_8209A1D0_B_ = int32_t(0x8209A1D0);
	constexpr int32_t Destroy_TXT_8349E6B4_G__address = int32_t(0x832AB100);
	if (!UseLiftedCode(144, 0x83280D88)) { __imp__sub_83280D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B4_G_, str_TXT_8209A1D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6B4_G__address);
}
PROMOTED_ENTRY(144, sub_83280D88, 0x83280D88) { ctx.r3.u64 = Construct_TXT_8349E6B4_G_(ctx, base); }

uint64_t Construct_TXT_8349E6B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6B8_G_ = int32_t(0x8349E6B8);
	constexpr int32_t str_TXT_8209A4BC_B_ = int32_t(0x8209A1E8);
	constexpr int32_t Destroy_TXT_8349E6B8_G__address = int32_t(0x832AB110);
	if (!UseLiftedCode(144, 0x83280DC8)) { __imp__sub_83280DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B8_G_, str_TXT_8209A4BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6B8_G__address);
}
PROMOTED_ENTRY(144, sub_83280DC8, 0x83280DC8) { ctx.r3.u64 = Construct_TXT_8349E6B8_G_(ctx, base); }

uint64_t Construct_TXT_8349E6BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6BC_G_ = int32_t(0x8349E6BC);
	constexpr int32_t str_TXT_8209A200_B_ = int32_t(0x8209A200);
	constexpr int32_t Destroy_TXT_8349E6BC_G__address = int32_t(0x832AB120);
	if (!UseLiftedCode(144, 0x83280E08)) { __imp__sub_83280E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6BC_G_, str_TXT_8209A200_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6BC_G__address);
}
PROMOTED_ENTRY(144, sub_83280E08, 0x83280E08) { ctx.r3.u64 = Construct_TXT_8349E6BC_G_(ctx, base); }

uint64_t Construct_TXT_8349E6C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6C0_G_ = int32_t(0x8349E6C0);
	constexpr int32_t str_TXT_8209A2AC_B_ = int32_t(0x8209A218);
	constexpr int32_t Destroy_TXT_8349E6C0_G__address = int32_t(0x832AB130);
	if (!UseLiftedCode(144, 0x83280E48)) { __imp__sub_83280E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C0_G_, str_TXT_8209A2AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6C0_G__address);
}
PROMOTED_ENTRY(144, sub_83280E48, 0x83280E48) { ctx.r3.u64 = Construct_TXT_8349E6C0_G_(ctx, base); }

uint64_t Construct_TXT_8349E6C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6C4_G_ = int32_t(0x8349E6C4);
	constexpr int32_t str_TXT_8209A228_B_ = int32_t(0x8209A228);
	constexpr int32_t Destroy_TXT_8349E6C4_G__address = int32_t(0x832AB140);
	if (!UseLiftedCode(144, 0x83280E88)) { __imp__sub_83280E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C4_G_, str_TXT_8209A228_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6C4_G__address);
}
PROMOTED_ENTRY(144, sub_83280E88, 0x83280E88) { ctx.r3.u64 = Construct_TXT_8349E6C4_G_(ctx, base); }

uint64_t Construct_TXT_8349E6C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6C8_G_ = int32_t(0x8349E6C8);
	constexpr int32_t str_TXT_8209A11C_B_ = int32_t(0x8209A11C);
	constexpr int32_t Destroy_TXT_8349E6C8_G__address = int32_t(0x832AB190);
	if (!UseLiftedCode(144, 0x83280EC8)) { __imp__sub_83280EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C8_G_, str_TXT_8209A11C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6C8_G__address);
}
PROMOTED_ENTRY(144, sub_83280EC8, 0x83280EC8) { ctx.r3.u64 = Construct_TXT_8349E6C8_G_(ctx, base); }

uint64_t Construct_TXT_8349E6CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6CC_G_ = int32_t(0x8349E6CC);
	constexpr int32_t str_TXT_8209A12C_B_ = int32_t(0x8209A12C);
	constexpr int32_t Destroy_TXT_8349E6CC_G__address = int32_t(0x832AB1A0);
	if (!UseLiftedCode(144, 0x83280F08)) { __imp__sub_83280F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6CC_G_, str_TXT_8209A12C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6CC_G__address);
}
PROMOTED_ENTRY(144, sub_83280F08, 0x83280F08) { ctx.r3.u64 = Construct_TXT_8349E6CC_G_(ctx, base); }

uint64_t Construct_TXT_8349E6D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6D0_G_ = int32_t(0x8349E6D0);
	constexpr int32_t str_TXT_8209A13C_B_ = int32_t(0x8209A13C);
	constexpr int32_t Destroy_TXT_8349E6D0_G__address = int32_t(0x832AB1B0);
	if (!UseLiftedCode(144, 0x83280F48)) { __imp__sub_83280F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D0_G_, str_TXT_8209A13C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6D0_G__address);
}
PROMOTED_ENTRY(144, sub_83280F48, 0x83280F48) { ctx.r3.u64 = Construct_TXT_8349E6D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E6D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6D4_G_ = int32_t(0x8349E6D4);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A150);
	constexpr int32_t Destroy_TXT_8349E6D4_G__address = int32_t(0x832AB1C0);
	if (!UseLiftedCode(144, 0x83280F88)) { __imp__sub_83280F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D4_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6D4_G__address);
}
PROMOTED_ENTRY(144, sub_83280F88, 0x83280F88) { ctx.r3.u64 = Construct_TXT_8349E6D4_G_(ctx, base); }

uint64_t Construct_TXT_8349E6D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6D8_G_ = int32_t(0x8349E6D8);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x8209A0CC);
	constexpr int32_t Destroy_TXT_8349E6D8_G__address = int32_t(0x832AB1D0);
	if (!UseLiftedCode(144, 0x83280FC8)) { __imp__sub_83280FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D8_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6D8_G__address);
}
PROMOTED_ENTRY(144, sub_83280FC8, 0x83280FC8) { ctx.r3.u64 = Construct_TXT_8349E6D8_G_(ctx, base); }

uint64_t Construct_TXT_8349E6DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6DC_G_ = int32_t(0x8349E6DC);
	constexpr int32_t str_TXT_8209A46C_B_ = int32_t(0x8209A0D4);
	constexpr int32_t Destroy_TXT_8349E6DC_G__address = int32_t(0x832AB1E0);
	if (!UseLiftedCode(144, 0x83281008)) { __imp__sub_83281008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6DC_G_, str_TXT_8209A46C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6DC_G__address);
}
PROMOTED_ENTRY(144, sub_83281008, 0x83281008) { ctx.r3.u64 = Construct_TXT_8349E6DC_G_(ctx, base); }

uint64_t Construct_TXT_8349E6E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6E0_G_ = int32_t(0x8349E6E0);
	constexpr int32_t str_TXT_8209A480_B_ = int32_t(0x8209A0E8);
	constexpr int32_t Destroy_TXT_8349E6E0_G__address = int32_t(0x832AB1F0);
	if (!UseLiftedCode(144, 0x83281048)) { __imp__sub_83281048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E0_G_, str_TXT_8209A480_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6E0_G__address);
}
PROMOTED_ENTRY(144, sub_83281048, 0x83281048) { ctx.r3.u64 = Construct_TXT_8349E6E0_G_(ctx, base); }

uint64_t Construct_TXT_8349E6E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6E4_G_ = int32_t(0x8349E6E4);
	constexpr int32_t str_TXT_8209A0FC_B_ = int32_t(0x8209A0FC);
	constexpr int32_t Destroy_TXT_8349E6E4_G__address = int32_t(0x832AB200);
	if (!UseLiftedCode(144, 0x83281088)) { __imp__sub_83281088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E4_G_, str_TXT_8209A0FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6E4_G__address);
}
PROMOTED_ENTRY(144, sub_83281088, 0x83281088) { ctx.r3.u64 = Construct_TXT_8349E6E4_G_(ctx, base); }

uint64_t Construct_TXT_8349E6E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E6E8_G_ = int32_t(0x8349E6E8);
	constexpr int32_t str_TXT_8209A464_B_ = int32_t(0x82099FFC);
	constexpr int32_t Destroy_TXT_8349E6E8_G__address = int32_t(0x832AB210);
	if (!UseLiftedCode(144, 0x832810C8)) { __imp__sub_832810C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832810C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E8_G_, str_TXT_8209A464_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E6E8_G__address);
}
PROMOTED_ENTRY(144, sub_832810C8, 0x832810C8) { ctx.r3.u64 = Construct_TXT_8349E6E8_G_(ctx, base); }

uint64_t n_sub_83281108(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB220_address = int32_t(0x832AB220);
	if (!UseLiftedCode(144, 0x83281108)) { ctx.r8.u64 = arg1; __imp__sub_83281108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281108);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB220_address, arg1);
}
PROMOTED_ENTRY(144, sub_83281108, 0x83281108) { ctx.r3.u64 = n_sub_83281108(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281178(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB2B8_address = int32_t(0x832AB2B8);
	if (!UseLiftedCode(144, 0x83281178)) { ctx.r8.u64 = arg1; __imp__sub_83281178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281178);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB2B8_address, arg1);
}
PROMOTED_ENTRY(144, sub_83281178, 0x83281178) { ctx.r3.u64 = n_sub_83281178(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E710 = int32_t(0x8349E710);
	constexpr int32_t n_sub_832AB310_address = int32_t(0x832AB310);
	if (!UseLiftedCode(144, 0x83281188)) { __imp__sub_83281188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E710, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB310_address);
}
PROMOTED_ENTRY(144, sub_83281188, 0x83281188) { ctx.r3.u64 = n_sub_83281188(ctx, base); }

uint64_t n_sub_832811C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E714 = int32_t(0x8349E714);
	constexpr int32_t n_sub_832AB320_address = int32_t(0x832AB320);
	if (!UseLiftedCode(144, 0x832811C8)) { __imp__sub_832811C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832811C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E714, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB320_address);
}
PROMOTED_ENTRY(144, sub_832811C8, 0x832811C8) { ctx.r3.u64 = n_sub_832811C8(ctx, base); }

uint64_t n_sub_83281208(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB330_address = int32_t(0x832AB330);
	if (!UseLiftedCode(144, 0x83281208)) { ctx.r8.u64 = arg1; __imp__sub_83281208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281208);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB330_address, arg1);
}
PROMOTED_ENTRY(144, sub_83281208, 0x83281208) { ctx.r3.u64 = n_sub_83281208(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E734 = int32_t(0x8349E734);
	constexpr int32_t n_sub_832AB388_address = int32_t(0x832AB388);
	if (!UseLiftedCode(144, 0x83281288)) { __imp__sub_83281288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E734, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB388_address);
}
PROMOTED_ENTRY(144, sub_83281288, 0x83281288) { ctx.r3.u64 = n_sub_83281288(ctx, base); }

uint64_t n_sub_832812C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E738 = int32_t(0x8349E738);
	constexpr int32_t n_sub_832AB398_address = int32_t(0x832AB398);
	if (!UseLiftedCode(144, 0x832812C8)) { __imp__sub_832812C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832812C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E738, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB398_address);
}
PROMOTED_ENTRY(144, sub_832812C8, 0x832812C8) { ctx.r3.u64 = n_sub_832812C8(ctx, base); }

uint64_t n_sub_83281368(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E750 = int32_t(0x8349E750);
	constexpr int32_t n_sub_832AB3A8_address = int32_t(0x832AB3A8);
	if (!UseLiftedCode(144, 0x83281368)) { __imp__sub_83281368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281368);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E750, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB3A8_address);
}
PROMOTED_ENTRY(144, sub_83281368, 0x83281368) { ctx.r3.u64 = n_sub_83281368(ctx, base); }

uint64_t n_sub_832813A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349E754 = int32_t(0x8349E754);
	constexpr int32_t n_sub_832AB3B8_address = int32_t(0x832AB3B8);
	if (!UseLiftedCode(144, 0x832813A8)) { __imp__sub_832813A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832813A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E754, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB3B8_address);
}
PROMOTED_ENTRY(144, sub_832813A8, 0x832813A8) { ctx.r3.u64 = n_sub_832813A8(ctx, base); }

uint64_t n_sub_83284BB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F478 = int32_t(0x8349F478);
	constexpr int32_t n_sub_832AB568_address = int32_t(0x832AB568);
	if (!UseLiftedCode(145, 0x83284BB8)) { __imp__sub_83284BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F478, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB568_address);
}
PROMOTED_ENTRY(145, sub_83284BB8, 0x83284BB8) { ctx.r3.u64 = n_sub_83284BB8(ctx, base); }

uint64_t n_sub_83284BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F47C = int32_t(0x8349F47C);
	constexpr int32_t n_sub_832AB578_address = int32_t(0x832AB578);
	if (!UseLiftedCode(145, 0x83284BF8)) { __imp__sub_83284BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F47C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB578_address);
}
PROMOTED_ENTRY(145, sub_83284BF8, 0x83284BF8) { ctx.r3.u64 = n_sub_83284BF8(ctx, base); }

uint64_t n_sub_83284C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F480 = int32_t(0x8349F480);
	constexpr int32_t n_sub_832AB588_address = int32_t(0x832AB588);
	if (!UseLiftedCode(145, 0x83284C38)) { __imp__sub_83284C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284C38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F480, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB588_address);
}
PROMOTED_ENTRY(145, sub_83284C38, 0x83284C38) { ctx.r3.u64 = n_sub_83284C38(ctx, base); }

uint64_t n_sub_83284C78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F484 = int32_t(0x8349F484);
	constexpr int32_t n_sub_832AB598_address = int32_t(0x832AB598);
	if (!UseLiftedCode(145, 0x83284C78)) { __imp__sub_83284C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284C78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F484, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB598_address);
}
PROMOTED_ENTRY(145, sub_83284C78, 0x83284C78) { ctx.r3.u64 = n_sub_83284C78(ctx, base); }

uint64_t n_sub_83284CB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F488 = int32_t(0x8349F488);
	constexpr int32_t n_sub_832AB5A8_address = int32_t(0x832AB5A8);
	if (!UseLiftedCode(145, 0x83284CB8)) { __imp__sub_83284CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284CB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F488, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB5A8_address);
}
PROMOTED_ENTRY(145, sub_83284CB8, 0x83284CB8) { ctx.r3.u64 = n_sub_83284CB8(ctx, base); }

uint64_t n_sub_83284CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F48C = int32_t(0x8349F48C);
	constexpr int32_t n_sub_832AB5B8_address = int32_t(0x832AB5B8);
	if (!UseLiftedCode(145, 0x83284CF8)) { __imp__sub_83284CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284CF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F48C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB5B8_address);
}
PROMOTED_ENTRY(145, sub_83284CF8, 0x83284CF8) { ctx.r3.u64 = n_sub_83284CF8(ctx, base); }

uint64_t n_sub_83284D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F490 = int32_t(0x8349F490);
	constexpr int32_t n_sub_832AB5C8_address = int32_t(0x832AB5C8);
	if (!UseLiftedCode(145, 0x83284D38)) { __imp__sub_83284D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284D38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F490, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB5C8_address);
}
PROMOTED_ENTRY(145, sub_83284D38, 0x83284D38) { ctx.r3.u64 = n_sub_83284D38(ctx, base); }

uint64_t n_sub_83284D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F494 = int32_t(0x8349F494);
	constexpr int32_t n_sub_832AB5D8_address = int32_t(0x832AB5D8);
	if (!UseLiftedCode(145, 0x83284D78)) { __imp__sub_83284D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284D78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F494, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AB5D8_address);
}
PROMOTED_ENTRY(145, sub_83284D78, 0x83284D78) { ctx.r3.u64 = n_sub_83284D78(ctx, base); }

uint64_t n_sub_83284DB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB5E8_address = int32_t(0x832AB5E8);
	if (!UseLiftedCode(145, 0x83284DB8)) { ctx.r8.u64 = arg1; __imp__sub_83284DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DB8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB5E8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284DB8, 0x83284DB8) { ctx.r3.u64 = n_sub_83284DB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284DC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB5F8_address = int32_t(0x832AB5F8);
	if (!UseLiftedCode(145, 0x83284DC8)) { ctx.r8.u64 = arg1; __imp__sub_83284DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DC8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB5F8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284DC8, 0x83284DC8) { ctx.r3.u64 = n_sub_83284DC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284DD8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB650_address = int32_t(0x832AB650);
	if (!UseLiftedCode(145, 0x83284DD8)) { ctx.r8.u64 = arg1; __imp__sub_83284DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DD8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB650_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284DD8, 0x83284DD8) { ctx.r3.u64 = n_sub_83284DD8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284E98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB6B0_address = int32_t(0x832AB6B0);
	if (!UseLiftedCode(145, 0x83284E98)) { ctx.r8.u64 = arg1; __imp__sub_83284E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284E98);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB6B0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284E98, 0x83284E98) { ctx.r3.u64 = n_sub_83284E98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EA8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB6D8_address = int32_t(0x832AB6D8);
	if (!UseLiftedCode(145, 0x83284EA8)) { ctx.r8.u64 = arg1; __imp__sub_83284EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EA8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB6D8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284EA8, 0x83284EA8) { ctx.r3.u64 = n_sub_83284EA8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB730_address = int32_t(0x832AB730);
	if (!UseLiftedCode(145, 0x83284EB8)) { ctx.r8.u64 = arg1; __imp__sub_83284EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EB8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB730_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284EB8, 0x83284EB8) { ctx.r3.u64 = n_sub_83284EB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB788_address = int32_t(0x832AB788);
	if (!UseLiftedCode(145, 0x83284EC8)) { ctx.r8.u64 = arg1; __imp__sub_83284EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EC8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB788_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284EC8, 0x83284EC8) { ctx.r3.u64 = n_sub_83284EC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284ED8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB7E0_address = int32_t(0x832AB7E0);
	if (!UseLiftedCode(145, 0x83284ED8)) { ctx.r8.u64 = arg1; __imp__sub_83284ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284ED8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB7E0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284ED8, 0x83284ED8) { ctx.r3.u64 = n_sub_83284ED8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB838_address = int32_t(0x832AB838);
	if (!UseLiftedCode(145, 0x83284EE8)) { ctx.r8.u64 = arg1; __imp__sub_83284EE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EE8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB838_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284EE8, 0x83284EE8) { ctx.r3.u64 = n_sub_83284EE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB890_address = int32_t(0x832AB890);
	if (!UseLiftedCode(145, 0x83284EF8)) { ctx.r8.u64 = arg1; __imp__sub_83284EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EF8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB890_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284EF8, 0x83284EF8) { ctx.r3.u64 = n_sub_83284EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F08(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB8E8_address = int32_t(0x832AB8E8);
	if (!UseLiftedCode(145, 0x83284F08)) { ctx.r8.u64 = arg1; __imp__sub_83284F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F08);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB8E8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F08, 0x83284F08) { ctx.r3.u64 = n_sub_83284F08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB940_address = int32_t(0x832AB940);
	if (!UseLiftedCode(145, 0x83284F18)) { ctx.r8.u64 = arg1; __imp__sub_83284F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F18);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB940_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F18, 0x83284F18) { ctx.r3.u64 = n_sub_83284F18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F60(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB9C0_address = int32_t(0x832AB9C0);
	if (!UseLiftedCode(145, 0x83284F60)) { ctx.r8.u64 = arg1; __imp__sub_83284F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F60);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB9C0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F60, 0x83284F60) { ctx.r3.u64 = n_sub_83284F60(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F70(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB9D0_address = int32_t(0x832AB9D0);
	if (!UseLiftedCode(145, 0x83284F70)) { ctx.r8.u64 = arg1; __imp__sub_83284F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F70);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB9D0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F70, 0x83284F70) { ctx.r3.u64 = n_sub_83284F70(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB9E0_address = int32_t(0x832AB9E0);
	if (!UseLiftedCode(145, 0x83284F80)) { ctx.r8.u64 = arg1; __imp__sub_83284F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F80);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB9E0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F80, 0x83284F80) { ctx.r3.u64 = n_sub_83284F80(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F90(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AB9F0_address = int32_t(0x832AB9F0);
	if (!UseLiftedCode(145, 0x83284F90)) { ctx.r8.u64 = arg1; __imp__sub_83284F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F90);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AB9F0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284F90, 0x83284F90) { ctx.r3.u64 = n_sub_83284F90(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FA0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABA00_address = int32_t(0x832ABA00);
	if (!UseLiftedCode(145, 0x83284FA0)) { ctx.r8.u64 = arg1; __imp__sub_83284FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FA0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABA00_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FA0, 0x83284FA0) { ctx.r3.u64 = n_sub_83284FA0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FB0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABA10_address = int32_t(0x832ABA10);
	if (!UseLiftedCode(145, 0x83284FB0)) { ctx.r8.u64 = arg1; __imp__sub_83284FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FB0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABA10_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FB0, 0x83284FB0) { ctx.r3.u64 = n_sub_83284FB0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FC0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABA20_address = int32_t(0x832ABA20);
	if (!UseLiftedCode(145, 0x83284FC0)) { ctx.r8.u64 = arg1; __imp__sub_83284FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FC0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABA20_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FC0, 0x83284FC0) { ctx.r3.u64 = n_sub_83284FC0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FD0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABA78_address = int32_t(0x832ABA78);
	if (!UseLiftedCode(145, 0x83284FD0)) { ctx.r8.u64 = arg1; __imp__sub_83284FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FD0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABA78_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FD0, 0x83284FD0) { ctx.r3.u64 = n_sub_83284FD0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FE0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABAD8_address = int32_t(0x832ABAD8);
	if (!UseLiftedCode(145, 0x83284FE0)) { ctx.r8.u64 = arg1; __imp__sub_83284FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FE0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABAD8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FE0, 0x83284FE0) { ctx.r3.u64 = n_sub_83284FE0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FF0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABB38_address = int32_t(0x832ABB38);
	if (!UseLiftedCode(145, 0x83284FF0)) { ctx.r8.u64 = arg1; __imp__sub_83284FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FF0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABB38_address, arg1);
}
PROMOTED_ENTRY(145, sub_83284FF0, 0x83284FF0) { ctx.r3.u64 = n_sub_83284FF0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285000(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABB98_address = int32_t(0x832ABB98);
	if (!UseLiftedCode(145, 0x83285000)) { ctx.r8.u64 = arg1; __imp__sub_83285000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285000);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABB98_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285000, 0x83285000) { ctx.r3.u64 = n_sub_83285000(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285010(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABBF0_address = int32_t(0x832ABBF0);
	if (!UseLiftedCode(145, 0x83285010)) { ctx.r8.u64 = arg1; __imp__sub_83285010(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285010);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABBF0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285010, 0x83285010) { ctx.r3.u64 = n_sub_83285010(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285020(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC48_address = int32_t(0x832ABC48);
	if (!UseLiftedCode(145, 0x83285020)) { ctx.r8.u64 = arg1; __imp__sub_83285020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285020);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC48_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285020, 0x83285020) { ctx.r3.u64 = n_sub_83285020(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285030(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC58_address = int32_t(0x832ABC58);
	if (!UseLiftedCode(145, 0x83285030)) { ctx.r8.u64 = arg1; __imp__sub_83285030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285030);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC58_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285030, 0x83285030) { ctx.r3.u64 = n_sub_83285030(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285040(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC68_address = int32_t(0x832ABC68);
	if (!UseLiftedCode(145, 0x83285040)) { ctx.r8.u64 = arg1; __imp__sub_83285040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285040);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC68_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285040, 0x83285040) { ctx.r3.u64 = n_sub_83285040(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285050(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC78_address = int32_t(0x832ABC78);
	if (!UseLiftedCode(145, 0x83285050)) { ctx.r8.u64 = arg1; __imp__sub_83285050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285050);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC78_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285050, 0x83285050) { ctx.r3.u64 = n_sub_83285050(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285060(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC88_address = int32_t(0x832ABC88);
	if (!UseLiftedCode(145, 0x83285060)) { ctx.r8.u64 = arg1; __imp__sub_83285060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285060);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC88_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285060, 0x83285060) { ctx.r3.u64 = n_sub_83285060(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285070(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABC98_address = int32_t(0x832ABC98);
	if (!UseLiftedCode(145, 0x83285070)) { ctx.r8.u64 = arg1; __imp__sub_83285070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285070);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABC98_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285070, 0x83285070) { ctx.r3.u64 = n_sub_83285070(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285150(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABD18_address = int32_t(0x832ABD18);
	if (!UseLiftedCode(145, 0x83285150)) { ctx.r8.u64 = arg1; __imp__sub_83285150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285150);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABD18_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285150, 0x83285150) { ctx.r3.u64 = n_sub_83285150(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285198(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABDC0_address = int32_t(0x832ABDC0);
	if (!UseLiftedCode(145, 0x83285198)) { ctx.r8.u64 = arg1; __imp__sub_83285198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285198);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABDC0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285198, 0x83285198) { ctx.r3.u64 = n_sub_83285198(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832851A8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABE40_address = int32_t(0x832ABE40);
	if (!UseLiftedCode(145, 0x832851A8)) { ctx.r8.u64 = arg1; __imp__sub_832851A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832851A8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABE40_address, arg1);
}
PROMOTED_ENTRY(145, sub_832851A8, 0x832851A8) { ctx.r3.u64 = n_sub_832851A8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832851B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABEC8_address = int32_t(0x832ABEC8);
	if (!UseLiftedCode(145, 0x832851B8)) { ctx.r8.u64 = arg1; __imp__sub_832851B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832851B8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABEC8_address, arg1);
}
PROMOTED_ENTRY(145, sub_832851B8, 0x832851B8) { ctx.r3.u64 = n_sub_832851B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F6D0 = int32_t(0x8349F6D0);
	constexpr int32_t n_sub_832ABF48_address = int32_t(0x832ABF48);
	if (!UseLiftedCode(145, 0x83285200)) { __imp__sub_83285200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285200);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F6D0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ABF48_address);
}
PROMOTED_ENTRY(145, sub_83285200, 0x83285200) { ctx.r3.u64 = n_sub_83285200(ctx, base); }

uint64_t n_sub_83285240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F6D4 = int32_t(0x8349F6D4);
	constexpr int32_t n_sub_832ABF58_address = int32_t(0x832ABF58);
	if (!UseLiftedCode(145, 0x83285240)) { __imp__sub_83285240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285240);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F6D4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ABF58_address);
}
PROMOTED_ENTRY(145, sub_83285240, 0x83285240) { ctx.r3.u64 = n_sub_83285240(ctx, base); }

uint64_t Construct_TXT_8349F6D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F6D8_G_ = int32_t(0x8349F6D8);
	constexpr int32_t str_TXT_820F5EC8_B_ = int32_t(0x820F5EC8);
	constexpr int32_t Destroy_TXT_8349F6D8_G__address = int32_t(0x832ABF68);
	if (!UseLiftedCode(145, 0x832852A0)) { __imp__sub_832852A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832852A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6D8_G_, str_TXT_820F5EC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F6D8_G__address);
}
PROMOTED_ENTRY(145, sub_832852A0, 0x832852A0) { ctx.r3.u64 = Construct_TXT_8349F6D8_G_(ctx, base); }

uint64_t Construct_TXT_8349F6DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F6DC_G_ = int32_t(0x8349F6DC);
	constexpr int32_t str_TXT_820F5ED8_B_ = int32_t(0x820F5ED8);
	constexpr int32_t Destroy_TXT_8349F6DC_G__address = int32_t(0x832ABF78);
	if (!UseLiftedCode(145, 0x832852E0)) { __imp__sub_832852E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832852E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6DC_G_, str_TXT_820F5ED8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F6DC_G__address);
}
PROMOTED_ENTRY(145, sub_832852E0, 0x832852E0) { ctx.r3.u64 = Construct_TXT_8349F6DC_G_(ctx, base); }

uint64_t Construct_TXT_8349F6F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F6F0_G_ = int32_t(0x8349F6F0);
	constexpr int32_t str_TXT_820F5EEC_B_ = int32_t(0x820F5EEC);
	constexpr int32_t Destroy_TXT_8349F6F0_G__address = int32_t(0x832ABF88);
	if (!UseLiftedCode(145, 0x83285320)) { __imp__sub_83285320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285320);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6F0_G_, str_TXT_820F5EEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F6F0_G__address);
}
PROMOTED_ENTRY(145, sub_83285320, 0x83285320) { ctx.r3.u64 = Construct_TXT_8349F6F0_G_(ctx, base); }

uint64_t Construct_TXT_8349F6F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F6F4_G_ = int32_t(0x8349F6F4);
	constexpr int32_t str_TXT_820F5EF8_B_ = int32_t(0x820F5EF8);
	constexpr int32_t Destroy_TXT_8349F6F4_G__address = int32_t(0x832ABF98);
	if (!UseLiftedCode(145, 0x83285360)) { __imp__sub_83285360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285360);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6F4_G_, str_TXT_820F5EF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F6F4_G__address);
}
PROMOTED_ENTRY(145, sub_83285360, 0x83285360) { ctx.r3.u64 = Construct_TXT_8349F6F4_G_(ctx, base); }

uint64_t n_sub_832854A8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ABFA8_address = int32_t(0x832ABFA8);
	if (!UseLiftedCode(145, 0x832854A8)) { ctx.r8.u64 = arg1; __imp__sub_832854A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854A8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ABFA8_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854A8, 0x832854A8) { ctx.r3.u64 = n_sub_832854A8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC000_address = int32_t(0x832AC000);
	if (!UseLiftedCode(145, 0x832854B8)) { ctx.r8.u64 = arg1; __imp__sub_832854B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854B8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC000_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854B8, 0x832854B8) { ctx.r3.u64 = n_sub_832854B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC058_address = int32_t(0x832AC058);
	if (!UseLiftedCode(145, 0x832854C8)) { ctx.r8.u64 = arg1; __imp__sub_832854C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854C8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC058_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854C8, 0x832854C8) { ctx.r3.u64 = n_sub_832854C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854D8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC0B0_address = int32_t(0x832AC0B0);
	if (!UseLiftedCode(145, 0x832854D8)) { ctx.r8.u64 = arg1; __imp__sub_832854D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854D8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC0B0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854D8, 0x832854D8) { ctx.r3.u64 = n_sub_832854D8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC108_address = int32_t(0x832AC108);
	if (!UseLiftedCode(145, 0x832854E8)) { ctx.r8.u64 = arg1; __imp__sub_832854E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854E8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC108_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854E8, 0x832854E8) { ctx.r3.u64 = n_sub_832854E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854F8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC160_address = int32_t(0x832AC160);
	if (!UseLiftedCode(145, 0x832854F8)) { ctx.r8.u64 = arg1; __imp__sub_832854F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854F8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC160_address, arg1);
}
PROMOTED_ENTRY(145, sub_832854F8, 0x832854F8) { ctx.r3.u64 = n_sub_832854F8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285508(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC1B8_address = int32_t(0x832AC1B8);
	if (!UseLiftedCode(145, 0x83285508)) { ctx.r8.u64 = arg1; __imp__sub_83285508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285508);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC1B8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285508, 0x83285508) { ctx.r3.u64 = n_sub_83285508(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F7A0 = int32_t(0x8349F7A0);
	constexpr int32_t n_sub_832AC220_address = int32_t(0x832AC220);
	if (!UseLiftedCode(145, 0x83285570)) { __imp__sub_83285570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC220_address);
}
PROMOTED_ENTRY(145, sub_83285570, 0x83285570) { ctx.r3.u64 = n_sub_83285570(ctx, base); }

uint64_t n_sub_832855B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F7A4 = int32_t(0x8349F7A4);
	constexpr int32_t n_sub_832AC230_address = int32_t(0x832AC230);
	if (!UseLiftedCode(145, 0x832855B0)) { __imp__sub_832855B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832855B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC230_address);
}
PROMOTED_ENTRY(145, sub_832855B0, 0x832855B0) { ctx.r3.u64 = n_sub_832855B0(ctx, base); }

uint64_t n_sub_832855F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F7A8 = int32_t(0x8349F7A8);
	constexpr int32_t n_sub_832AC240_address = int32_t(0x832AC240);
	if (!UseLiftedCode(145, 0x832855F0)) { __imp__sub_832855F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832855F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC240_address);
}
PROMOTED_ENTRY(145, sub_832855F0, 0x832855F0) { ctx.r3.u64 = n_sub_832855F0(ctx, base); }

uint64_t n_sub_83285630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F7AC = int32_t(0x8349F7AC);
	constexpr int32_t n_sub_832AC250_address = int32_t(0x832AC250);
	if (!UseLiftedCode(145, 0x83285630)) { __imp__sub_83285630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F7AC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC250_address);
}
PROMOTED_ENTRY(145, sub_83285630, 0x83285630) { ctx.r3.u64 = n_sub_83285630(ctx, base); }

uint64_t n_sub_832857E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC390_address = int32_t(0x832AC390);
	if (!UseLiftedCode(145, 0x832857E0)) { ctx.r8.u64 = arg1; __imp__sub_832857E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832857E0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC390_address, arg1);
}
PROMOTED_ENTRY(145, sub_832857E0, 0x832857E0) { ctx.r3.u64 = n_sub_832857E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832857F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC3E8_address = int32_t(0x832AC3E8);
	if (!UseLiftedCode(145, 0x832857F0)) { ctx.r8.u64 = arg1; __imp__sub_832857F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832857F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC3E8_address, arg1);
}
PROMOTED_ENTRY(145, sub_832857F0, 0x832857F0) { ctx.r3.u64 = n_sub_832857F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285800(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC438_address = int32_t(0x832AC438);
	if (!UseLiftedCode(145, 0x83285800)) { ctx.r8.u64 = arg1; __imp__sub_83285800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285800);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC438_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285800, 0x83285800) { ctx.r3.u64 = n_sub_83285800(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285810(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC488_address = int32_t(0x832AC488);
	if (!UseLiftedCode(145, 0x83285810)) { ctx.r8.u64 = arg1; __imp__sub_83285810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285810);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC488_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285810, 0x83285810) { ctx.r3.u64 = n_sub_83285810(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285820(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC4B0_address = int32_t(0x832AC4B0);
	if (!UseLiftedCode(145, 0x83285820)) { ctx.r8.u64 = arg1; __imp__sub_83285820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285820);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC4B0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285820, 0x83285820) { ctx.r3.u64 = n_sub_83285820(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285830(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC558_address = int32_t(0x832AC558);
	if (!UseLiftedCode(145, 0x83285830)) { ctx.r8.u64 = arg1; __imp__sub_83285830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285830);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC558_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285830, 0x83285830) { ctx.r3.u64 = n_sub_83285830(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349F824_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F824_G_ = int32_t(0x8349F824);
	constexpr int32_t str_TXT_820F5FA4_B_ = int32_t(0x820F5FA4);
	constexpr int32_t Destroy_TXT_8349F824_G__address = int32_t(0x832AC560);
	if (!UseLiftedCode(145, 0x83285840)) { __imp__sub_83285840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285840);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F824_G_, str_TXT_820F5FA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F824_G__address);
}
PROMOTED_ENTRY(145, sub_83285840, 0x83285840) { ctx.r3.u64 = Construct_TXT_8349F824_G_(ctx, base); }

uint64_t n_sub_83285880(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F828 = int32_t(0x8349F828);
	constexpr int32_t n_sub_832AC570_address = int32_t(0x832AC570);
	if (!UseLiftedCode(145, 0x83285880)) { __imp__sub_83285880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285880);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F828, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC570_address);
}
PROMOTED_ENTRY(145, sub_83285880, 0x83285880) { ctx.r3.u64 = n_sub_83285880(ctx, base); }

uint64_t n_sub_832858C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F82C = int32_t(0x8349F82C);
	constexpr int32_t n_sub_832AC580_address = int32_t(0x832AC580);
	if (!UseLiftedCode(145, 0x832858C0)) { __imp__sub_832858C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832858C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F82C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC580_address);
}
PROMOTED_ENTRY(145, sub_832858C0, 0x832858C0) { ctx.r3.u64 = n_sub_832858C0(ctx, base); }

uint64_t n_sub_83285900(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC590_address = int32_t(0x832AC590);
	if (!UseLiftedCode(145, 0x83285900)) { ctx.r8.u64 = arg1; __imp__sub_83285900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285900);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC590_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285900, 0x83285900) { ctx.r3.u64 = n_sub_83285900(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F840 = int32_t(0x8349F840);
	constexpr int32_t n_sub_832AC5E8_address = int32_t(0x832AC5E8);
	if (!UseLiftedCode(145, 0x83285910)) { __imp__sub_83285910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F840, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC5E8_address);
}
PROMOTED_ENTRY(145, sub_83285910, 0x83285910) { ctx.r3.u64 = n_sub_83285910(ctx, base); }

uint64_t n_sub_83285950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F844 = int32_t(0x8349F844);
	constexpr int32_t n_sub_832AC5F8_address = int32_t(0x832AC5F8);
	if (!UseLiftedCode(145, 0x83285950)) { __imp__sub_83285950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F844, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC5F8_address);
}
PROMOTED_ENTRY(145, sub_83285950, 0x83285950) { ctx.r3.u64 = n_sub_83285950(ctx, base); }

uint64_t n_sub_83285A80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC690_address = int32_t(0x832AC690);
	if (!UseLiftedCode(145, 0x83285A80)) { ctx.r8.u64 = arg1; __imp__sub_83285A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285A80);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC690_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285A80, 0x83285A80) { ctx.r3.u64 = n_sub_83285A80(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349F870_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F870_G_ = int32_t(0x8349F870);
	constexpr int32_t str_TXT_820F6008_B_ = int32_t(0x820F6008);
	constexpr int32_t Destroy_TXT_8349F870_G__address = int32_t(0x832AC6A0);
	if (!UseLiftedCode(145, 0x83285A90)) { __imp__sub_83285A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285A90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F870_G_, str_TXT_820F6008_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F870_G__address);
}
PROMOTED_ENTRY(145, sub_83285A90, 0x83285A90) { ctx.r3.u64 = Construct_TXT_8349F870_G_(ctx, base); }

uint64_t Construct_TXT_8349F874_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349F874_G_ = int32_t(0x8349F874);
	constexpr int32_t str_TXT_820F6008_B_ = int32_t(0x820F6018);
	constexpr int32_t Destroy_TXT_8349F874_G__address = int32_t(0x832AC6B0);
	if (!UseLiftedCode(145, 0x83285AD0)) { __imp__sub_83285AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F874_G_, str_TXT_820F6008_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349F874_G__address);
}
PROMOTED_ENTRY(145, sub_83285AD0, 0x83285AD0) { ctx.r3.u64 = Construct_TXT_8349F874_G_(ctx, base); }

uint64_t n_sub_83285B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F878 = int32_t(0x8349F878);
	constexpr int32_t n_sub_832AC6C0_address = int32_t(0x832AC6C0);
	if (!UseLiftedCode(145, 0x83285B10)) { __imp__sub_83285B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285B10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F878, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC6C0_address);
}
PROMOTED_ENTRY(145, sub_83285B10, 0x83285B10) { ctx.r3.u64 = n_sub_83285B10(ctx, base); }

uint64_t n_sub_83285B50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F87C = int32_t(0x8349F87C);
	constexpr int32_t n_sub_832AC6D0_address = int32_t(0x832AC6D0);
	if (!UseLiftedCode(145, 0x83285B50)) { __imp__sub_83285B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285B50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F87C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC6D0_address);
}
PROMOTED_ENTRY(145, sub_83285B50, 0x83285B50) { ctx.r3.u64 = n_sub_83285B50(ctx, base); }

uint64_t n_sub_83285BB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F894 = int32_t(0x8349F894);
	constexpr int32_t n_sub_832AC6F8_address = int32_t(0x832AC6F8);
	if (!UseLiftedCode(145, 0x83285BB8)) { __imp__sub_83285BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F894, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC6F8_address);
}
PROMOTED_ENTRY(145, sub_83285BB8, 0x83285BB8) { ctx.r3.u64 = n_sub_83285BB8(ctx, base); }

uint64_t n_sub_83285BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8349F898 = int32_t(0x8349F898);
	constexpr int32_t n_sub_832AC708_address = int32_t(0x832AC708);
	if (!UseLiftedCode(145, 0x83285BF8)) { __imp__sub_83285BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349F898, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC708_address);
}
PROMOTED_ENTRY(145, sub_83285BF8, 0x83285BF8) { ctx.r3.u64 = n_sub_83285BF8(ctx, base); }

uint64_t n_sub_83285D00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC7B0_address = int32_t(0x832AC7B0);
	if (!UseLiftedCode(145, 0x83285D00)) { ctx.r8.u64 = arg1; __imp__sub_83285D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D00);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC7B0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285D00, 0x83285D00) { ctx.r3.u64 = n_sub_83285D00(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285D10(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC7F0_address = int32_t(0x832AC7F0);
	if (!UseLiftedCode(145, 0x83285D10)) { ctx.r8.u64 = arg1; __imp__sub_83285D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D10);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC7F0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83285D10, 0x83285D10) { ctx.r3.u64 = n_sub_83285D10(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285D70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0B9C = int32_t(0x834A0B9C);
	constexpr int32_t n_sub_832AC860_address = int32_t(0x832AC860);
	if (!UseLiftedCode(145, 0x83285D70)) { __imp__sub_83285D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0B9C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC860_address);
}
PROMOTED_ENTRY(145, sub_83285D70, 0x83285D70) { ctx.r3.u64 = n_sub_83285D70(ctx, base); }

uint64_t n_sub_83285DB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0BA0 = int32_t(0x834A0BA0);
	constexpr int32_t n_sub_832AC870_address = int32_t(0x832AC870);
	if (!UseLiftedCode(145, 0x83285DB0)) { __imp__sub_83285DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0BA0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC870_address);
}
PROMOTED_ENTRY(145, sub_83285DB0, 0x83285DB0) { ctx.r3.u64 = n_sub_83285DB0(ctx, base); }

uint64_t n_sub_83285E80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C78 = int32_t(0x834A0C78);
	constexpr int32_t n_sub_832AC930_address = int32_t(0x832AC930);
	if (!UseLiftedCode(145, 0x83285E80)) { __imp__sub_83285E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285E80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C78, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC930_address);
}
PROMOTED_ENTRY(145, sub_83285E80, 0x83285E80) { ctx.r3.u64 = n_sub_83285E80(ctx, base); }

uint64_t n_sub_83285EC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C7C = int32_t(0x834A0C7C);
	constexpr int32_t n_sub_832AC940_address = int32_t(0x832AC940);
	if (!UseLiftedCode(145, 0x83285EC0)) { __imp__sub_83285EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285EC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C7C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC940_address);
}
PROMOTED_ENTRY(145, sub_83285EC0, 0x83285EC0) { ctx.r3.u64 = n_sub_83285EC0(ctx, base); }

uint64_t n_sub_83285F00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C80 = int32_t(0x834A0C80);
	constexpr int32_t n_sub_832AC950_address = int32_t(0x832AC950);
	if (!UseLiftedCode(145, 0x83285F00)) { __imp__sub_83285F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C80, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC950_address);
}
PROMOTED_ENTRY(145, sub_83285F00, 0x83285F00) { ctx.r3.u64 = n_sub_83285F00(ctx, base); }

uint64_t n_sub_83285F40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C84 = int32_t(0x834A0C84);
	constexpr int32_t n_sub_832AC960_address = int32_t(0x832AC960);
	if (!UseLiftedCode(145, 0x83285F40)) { __imp__sub_83285F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C84, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC960_address);
}
PROMOTED_ENTRY(145, sub_83285F40, 0x83285F40) { ctx.r3.u64 = n_sub_83285F40(ctx, base); }

uint64_t n_sub_83285F80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C88 = int32_t(0x834A0C88);
	constexpr int32_t n_sub_832AC970_address = int32_t(0x832AC970);
	if (!UseLiftedCode(145, 0x83285F80)) { __imp__sub_83285F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C88, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC970_address);
}
PROMOTED_ENTRY(145, sub_83285F80, 0x83285F80) { ctx.r3.u64 = n_sub_83285F80(ctx, base); }

uint64_t n_sub_83285FC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C8C = int32_t(0x834A0C8C);
	constexpr int32_t n_sub_832AC980_address = int32_t(0x832AC980);
	if (!UseLiftedCode(145, 0x83285FC0)) { __imp__sub_83285FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C8C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC980_address);
}
PROMOTED_ENTRY(145, sub_83285FC0, 0x83285FC0) { ctx.r3.u64 = n_sub_83285FC0(ctx, base); }

uint64_t n_sub_83286000(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C90 = int32_t(0x834A0C90);
	constexpr int32_t n_sub_832AC990_address = int32_t(0x832AC990);
	if (!UseLiftedCode(145, 0x83286000)) { __imp__sub_83286000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286000);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C90, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC990_address);
}
PROMOTED_ENTRY(145, sub_83286000, 0x83286000) { ctx.r3.u64 = n_sub_83286000(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0C94(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C94 = int32_t(0x834A0C94);
	constexpr int32_t n_sub_832AC9A0_address = int32_t(0x832AC9A0);
	if (!UseLiftedCode(145, 0x83286040)) { __imp__sub_83286040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286040);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C94, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC9A0_address);
}
PROMOTED_ENTRY(145, sub_83286040, 0x83286040) { ctx.r3.u64 = InitializeGlobalCCharString_834A0C94(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0C98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C98 = int32_t(0x834A0C98);
	constexpr int32_t n_sub_832AC9B0_address = int32_t(0x832AC9B0);
	if (!UseLiftedCode(145, 0x83286080)) { __imp__sub_83286080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286080);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C98, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC9B0_address);
}
PROMOTED_ENTRY(145, sub_83286080, 0x83286080) { ctx.r3.u64 = InitializeGlobalCCharString_834A0C98(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0C9C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0C9C = int32_t(0x834A0C9C);
	constexpr int32_t n_sub_832AC9C0_address = int32_t(0x832AC9C0);
	if (!UseLiftedCode(145, 0x832860C0)) { __imp__sub_832860C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832860C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0C9C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC9C0_address);
}
PROMOTED_ENTRY(145, sub_832860C0, 0x832860C0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0C9C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0CA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0CA0 = int32_t(0x834A0CA0);
	constexpr int32_t n_sub_832AC9D0_address = int32_t(0x832AC9D0);
	if (!UseLiftedCode(145, 0x83286100)) { __imp__sub_83286100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286100);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0CA0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC9D0_address);
}
PROMOTED_ENTRY(145, sub_83286100, 0x83286100) { ctx.r3.u64 = InitializeGlobalCCharString_834A0CA0(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0CA4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0CA4 = int32_t(0x834A0CA4);
	constexpr int32_t n_sub_832AC9E0_address = int32_t(0x832AC9E0);
	if (!UseLiftedCode(145, 0x83286140)) { __imp__sub_83286140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286140);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0CA4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AC9E0_address);
}
PROMOTED_ENTRY(145, sub_83286140, 0x83286140) { ctx.r3.u64 = InitializeGlobalCCharString_834A0CA4(ctx, base); }

uint64_t n_sub_83286180(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AC9F0_address = int32_t(0x832AC9F0);
	if (!UseLiftedCode(145, 0x83286180)) { ctx.r8.u64 = arg1; __imp__sub_83286180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286180);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AC9F0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286180, 0x83286180) { ctx.r3.u64 = n_sub_83286180(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286190(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACA00_address = int32_t(0x832ACA00);
	if (!UseLiftedCode(145, 0x83286190)) { ctx.r8.u64 = arg1; __imp__sub_83286190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286190);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACA00_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286190, 0x83286190) { ctx.r3.u64 = n_sub_83286190(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalCCharString_834A0D94(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0D94 = int32_t(0x834A0D94);
	constexpr int32_t n_sub_832ACAC0_address = int32_t(0x832ACAC0);
	if (!UseLiftedCode(145, 0x832862A0)) { __imp__sub_832862A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832862A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0D94, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACAC0_address);
}
PROMOTED_ENTRY(145, sub_832862A0, 0x832862A0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0D94(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0D98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0D98 = int32_t(0x834A0D98);
	constexpr int32_t n_sub_832ACAD0_address = int32_t(0x832ACAD0);
	if (!UseLiftedCode(145, 0x832862E0)) { __imp__sub_832862E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832862E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0D98, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACAD0_address);
}
PROMOTED_ENTRY(145, sub_832862E0, 0x832862E0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0D98(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0D9C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0D9C = int32_t(0x834A0D9C);
	constexpr int32_t n_sub_832ACAE0_address = int32_t(0x832ACAE0);
	if (!UseLiftedCode(145, 0x83286320)) { __imp__sub_83286320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286320);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0D9C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACAE0_address);
}
PROMOTED_ENTRY(145, sub_83286320, 0x83286320) { ctx.r3.u64 = InitializeGlobalCCharString_834A0D9C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0DA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0DA0 = int32_t(0x834A0DA0);
	constexpr int32_t n_sub_832ACAF0_address = int32_t(0x832ACAF0);
	if (!UseLiftedCode(145, 0x83286360)) { __imp__sub_83286360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286360);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0DA0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACAF0_address);
}
PROMOTED_ENTRY(145, sub_83286360, 0x83286360) { ctx.r3.u64 = InitializeGlobalCCharString_834A0DA0(ctx, base); }

uint64_t n_sub_832863A0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACB00_address = int32_t(0x832ACB00);
	if (!UseLiftedCode(145, 0x832863A0)) { ctx.r8.u64 = arg1; __imp__sub_832863A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863A0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACB00_address, arg1);
}
PROMOTED_ENTRY(145, sub_832863A0, 0x832863A0) { ctx.r3.u64 = n_sub_832863A0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832863B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACB10_address = int32_t(0x832ACB10);
	if (!UseLiftedCode(145, 0x832863B0)) { ctx.r8.u64 = arg1; __imp__sub_832863B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863B0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACB10_address, arg1);
}
PROMOTED_ENTRY(145, sub_832863B0, 0x832863B0) { ctx.r3.u64 = n_sub_832863B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832863C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACB70_address = int32_t(0x832ACB70);
	if (!UseLiftedCode(145, 0x832863C0)) { ctx.r8.u64 = arg1; __imp__sub_832863C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863C0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACB70_address, arg1);
}
PROMOTED_ENTRY(145, sub_832863C0, 0x832863C0) { ctx.r3.u64 = n_sub_832863C0(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalCCharString_834A0DAC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0DAC = int32_t(0x834A0DAC);
	constexpr int32_t n_sub_832ACBD0_address = int32_t(0x832ACBD0);
	if (!UseLiftedCode(145, 0x832863D0)) { __imp__sub_832863D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0DAC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACBD0_address);
}
PROMOTED_ENTRY(145, sub_832863D0, 0x832863D0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0DAC(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0DB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0DB0 = int32_t(0x834A0DB0);
	constexpr int32_t n_sub_832ACBE0_address = int32_t(0x832ACBE0);
	if (!UseLiftedCode(145, 0x83286410)) { __imp__sub_83286410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACBE0_address);
}
PROMOTED_ENTRY(145, sub_83286410, 0x83286410) { ctx.r3.u64 = InitializeGlobalCCharString_834A0DB0(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0DB4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0DB4 = int32_t(0x834A0DB4);
	constexpr int32_t n_sub_832ACC00_address = int32_t(0x832ACC00);
	if (!UseLiftedCode(145, 0x83286450)) { __imp__sub_83286450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACC00_address);
}
PROMOTED_ENTRY(145, sub_83286450, 0x83286450) { ctx.r3.u64 = InitializeGlobalCCharString_834A0DB4(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0DB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0DB8 = int32_t(0x834A0DB8);
	constexpr int32_t n_sub_832ACC10_address = int32_t(0x832ACC10);
	if (!UseLiftedCode(145, 0x83286490)) { __imp__sub_83286490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ACC10_address);
}
PROMOTED_ENTRY(145, sub_83286490, 0x83286490) { ctx.r3.u64 = InitializeGlobalCCharString_834A0DB8(ctx, base); }

uint64_t n_sub_832864D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACC20_address = int32_t(0x832ACC20);
	if (!UseLiftedCode(145, 0x832864D0)) { ctx.r8.u64 = arg1; __imp__sub_832864D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864D0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACC20_address, arg1);
}
PROMOTED_ENTRY(145, sub_832864D0, 0x832864D0) { ctx.r3.u64 = n_sub_832864D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832864E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACC98_address = int32_t(0x832ACC98);
	if (!UseLiftedCode(145, 0x832864E0)) { ctx.r8.u64 = arg1; __imp__sub_832864E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864E0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACC98_address, arg1);
}
PROMOTED_ENTRY(145, sub_832864E0, 0x832864E0) { ctx.r3.u64 = n_sub_832864E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832864F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACD10_address = int32_t(0x832ACD10);
	if (!UseLiftedCode(145, 0x832864F0)) { ctx.r8.u64 = arg1; __imp__sub_832864F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACD10_address, arg1);
}
PROMOTED_ENTRY(145, sub_832864F0, 0x832864F0) { ctx.r3.u64 = n_sub_832864F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286500(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACD88_address = int32_t(0x832ACD88);
	if (!UseLiftedCode(145, 0x83286500)) { ctx.r8.u64 = arg1; __imp__sub_83286500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286500);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACD88_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286500, 0x83286500) { ctx.r3.u64 = n_sub_83286500(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286510(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACE00_address = int32_t(0x832ACE00);
	if (!UseLiftedCode(145, 0x83286510)) { ctx.r8.u64 = arg1; __imp__sub_83286510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286510);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACE00_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286510, 0x83286510) { ctx.r3.u64 = n_sub_83286510(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286520(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACE78_address = int32_t(0x832ACE78);
	if (!UseLiftedCode(145, 0x83286520)) { ctx.r8.u64 = arg1; __imp__sub_83286520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286520);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACE78_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286520, 0x83286520) { ctx.r3.u64 = n_sub_83286520(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286530(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACEF0_address = int32_t(0x832ACEF0);
	if (!UseLiftedCode(145, 0x83286530)) { ctx.r8.u64 = arg1; __imp__sub_83286530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286530);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACEF0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286530, 0x83286530) { ctx.r3.u64 = n_sub_83286530(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286540(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACF68_address = int32_t(0x832ACF68);
	if (!UseLiftedCode(145, 0x83286540)) { ctx.r8.u64 = arg1; __imp__sub_83286540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286540);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACF68_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286540, 0x83286540) { ctx.r3.u64 = n_sub_83286540(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286550(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ACFE0_address = int32_t(0x832ACFE0);
	if (!UseLiftedCode(145, 0x83286550)) { ctx.r8.u64 = arg1; __imp__sub_83286550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286550);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ACFE0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286550, 0x83286550) { ctx.r3.u64 = n_sub_83286550(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286560(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD058_address = int32_t(0x832AD058);
	if (!UseLiftedCode(145, 0x83286560)) { ctx.r8.u64 = arg1; __imp__sub_83286560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286560);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD058_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286560, 0x83286560) { ctx.r3.u64 = n_sub_83286560(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286570(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD068_address = int32_t(0x832AD068);
	if (!UseLiftedCode(145, 0x83286570)) { ctx.r8.u64 = arg1; __imp__sub_83286570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286570);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD068_address, arg1);
}
PROMOTED_ENTRY(145, sub_83286570, 0x83286570) { ctx.r3.u64 = n_sub_83286570(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalCCharString_834A0E00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E00 = int32_t(0x834A0E00);
	constexpr int32_t n_sub_832AD0E0_address = int32_t(0x832AD0E0);
	if (!UseLiftedCode(145, 0x832865E0)) { __imp__sub_832865E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832865E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E00, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD0E0_address);
}
PROMOTED_ENTRY(145, sub_832865E0, 0x832865E0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E00(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0E04(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E04 = int32_t(0x834A0E04);
	constexpr int32_t n_sub_832AD0F0_address = int32_t(0x832AD0F0);
	if (!UseLiftedCode(145, 0x83286620)) { __imp__sub_83286620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286620);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E04, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD0F0_address);
}
PROMOTED_ENTRY(145, sub_83286620, 0x83286620) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E04(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E08 = int32_t(0x834A0E08);
	constexpr int32_t n_sub_832AD100_address = int32_t(0x832AD100);
	if (!UseLiftedCode(145, 0x83286660)) { __imp__sub_83286660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286660);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E08, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD100_address);
}
PROMOTED_ENTRY(145, sub_83286660, 0x83286660) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E08(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0E0C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E0C = int32_t(0x834A0E0C);
	constexpr int32_t n_sub_832AD110_address = int32_t(0x832AD110);
	if (!UseLiftedCode(145, 0x832866A0)) { __imp__sub_832866A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832866A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E0C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD110_address);
}
PROMOTED_ENTRY(145, sub_832866A0, 0x832866A0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E0C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0E4C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E4C = int32_t(0x834A0E4C);
	constexpr int32_t n_sub_832AD168_address = int32_t(0x832AD168);
	if (!UseLiftedCode(145, 0x83286758)) { __imp__sub_83286758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E4C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD168_address);
}
PROMOTED_ENTRY(145, sub_83286758, 0x83286758) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E4C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0E50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0E50 = int32_t(0x834A0E50);
	constexpr int32_t n_sub_832AD178_address = int32_t(0x832AD178);
	if (!UseLiftedCode(145, 0x83286798)) { __imp__sub_83286798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0E50, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD178_address);
}
PROMOTED_ENTRY(145, sub_83286798, 0x83286798) { ctx.r3.u64 = InitializeGlobalCCharString_834A0E50(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0EF4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0EF4 = int32_t(0x834A0EF4);
	constexpr int32_t n_sub_832AD210_address = int32_t(0x832AD210);
	if (!UseLiftedCode(145, 0x832868B0)) { __imp__sub_832868B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832868B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0EF4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD210_address);
}
PROMOTED_ENTRY(145, sub_832868B0, 0x832868B0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0EF4(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0EF8 = int32_t(0x834A0EF8);
	constexpr int32_t n_sub_832AD220_address = int32_t(0x832AD220);
	if (!UseLiftedCode(145, 0x832868F0)) { __imp__sub_832868F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832868F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0EF8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD220_address);
}
PROMOTED_ENTRY(145, sub_832868F0, 0x832868F0) { ctx.r3.u64 = InitializeGlobalCCharString_834A0EF8(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0F60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0F60 = int32_t(0x834A0F60);
	constexpr int32_t n_sub_832AD2A0_address = int32_t(0x832AD2A0);
	if (!UseLiftedCode(145, 0x83286998)) { __imp__sub_83286998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286998);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0F60, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD2A0_address);
}
PROMOTED_ENTRY(145, sub_83286998, 0x83286998) { ctx.r3.u64 = InitializeGlobalCCharString_834A0F60(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0F64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0F64 = int32_t(0x834A0F64);
	constexpr int32_t n_sub_832AD2B0_address = int32_t(0x832AD2B0);
	if (!UseLiftedCode(145, 0x832869D8)) { __imp__sub_832869D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832869D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0F64, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD2B0_address);
}
PROMOTED_ENTRY(145, sub_832869D8, 0x832869D8) { ctx.r3.u64 = InitializeGlobalCCharString_834A0F64(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0FE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0FE8 = int32_t(0x834A0FE8);
	constexpr int32_t n_sub_832AD2D8_address = int32_t(0x832AD2D8);
	if (!UseLiftedCode(145, 0x83286BE8)) { __imp__sub_83286BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0FE8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD2D8_address);
}
PROMOTED_ENTRY(145, sub_83286BE8, 0x83286BE8) { ctx.r3.u64 = InitializeGlobalCCharString_834A0FE8(ctx, base); }

uint64_t InitializeGlobalCCharString_834A0FEC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A0FEC = int32_t(0x834A0FEC);
	constexpr int32_t n_sub_832AD2E8_address = int32_t(0x832AD2E8);
	if (!UseLiftedCode(145, 0x83286C28)) { __imp__sub_83286C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286C28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A0FEC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD2E8_address);
}
PROMOTED_ENTRY(145, sub_83286C28, 0x83286C28) { ctx.r3.u64 = InitializeGlobalCCharString_834A0FEC(ctx, base); }

uint64_t InitializeGlobalCCharString_834A3FF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A3FF0 = int32_t(0x834A3FF0);
	constexpr int32_t n_sub_832AD2F8_address = int32_t(0x832AD2F8);
	if (!UseLiftedCode(145, 0x83286C68)) { __imp__sub_83286C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286C68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A3FF0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD2F8_address);
}
PROMOTED_ENTRY(145, sub_83286C68, 0x83286C68) { ctx.r3.u64 = InitializeGlobalCCharString_834A3FF0(ctx, base); }

uint64_t InitializeGlobalCCharString_834A3FF4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A3FF4 = int32_t(0x834A3FF4);
	constexpr int32_t n_sub_832AD308_address = int32_t(0x832AD308);
	if (!UseLiftedCode(145, 0x83286CA8)) { __imp__sub_83286CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286CA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A3FF4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD308_address);
}
PROMOTED_ENTRY(145, sub_83286CA8, 0x83286CA8) { ctx.r3.u64 = InitializeGlobalCCharString_834A3FF4(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4070(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4070 = int32_t(0x834A4070);
	constexpr int32_t n_sub_832AD370_address = int32_t(0x832AD370);
	if (!UseLiftedCode(145, 0x83286D70)) { __imp__sub_83286D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286D70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4070, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD370_address);
}
PROMOTED_ENTRY(145, sub_83286D70, 0x83286D70) { ctx.r3.u64 = InitializeGlobalCCharString_834A4070(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4074(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4074 = int32_t(0x834A4074);
	constexpr int32_t n_sub_832AD380_address = int32_t(0x832AD380);
	if (!UseLiftedCode(145, 0x83286DB0)) { __imp__sub_83286DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4074, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD380_address);
}
PROMOTED_ENTRY(145, sub_83286DB0, 0x83286DB0) { ctx.r3.u64 = InitializeGlobalCCharString_834A4074(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4078 = int32_t(0x834A4078);
	constexpr int32_t n_sub_832AD410_address = int32_t(0x832AD410);
	if (!UseLiftedCode(145, 0x83286DF0)) { __imp__sub_83286DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286DF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4078, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD410_address);
}
PROMOTED_ENTRY(145, sub_83286DF0, 0x83286DF0) { ctx.r3.u64 = InitializeGlobalCCharString_834A4078(ctx, base); }

uint64_t InitializeGlobalCCharString_834A407C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A407C = int32_t(0x834A407C);
	constexpr int32_t n_sub_832AD420_address = int32_t(0x832AD420);
	if (!UseLiftedCode(145, 0x83286E30)) { __imp__sub_83286E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286E30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A407C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD420_address);
}
PROMOTED_ENTRY(145, sub_83286E30, 0x83286E30) { ctx.r3.u64 = InitializeGlobalCCharString_834A407C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4090(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4090 = int32_t(0x834A4090);
	constexpr int32_t n_sub_832AD430_address = int32_t(0x832AD430);
	if (!UseLiftedCode(145, 0x83286E98)) { __imp__sub_83286E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286E98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4090, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD430_address);
}
PROMOTED_ENTRY(145, sub_83286E98, 0x83286E98) { ctx.r3.u64 = InitializeGlobalCCharString_834A4090(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4094(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4094 = int32_t(0x834A4094);
	constexpr int32_t n_sub_832AD440_address = int32_t(0x832AD440);
	if (!UseLiftedCode(145, 0x83286ED8)) { __imp__sub_83286ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286ED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4094, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD440_address);
}
PROMOTED_ENTRY(145, sub_83286ED8, 0x83286ED8) { ctx.r3.u64 = InitializeGlobalCCharString_834A4094(ctx, base); }

uint64_t InitializeGlobalCCharString_834A4098(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4098 = int32_t(0x834A4098);
	constexpr int32_t n_sub_832AD450_address = int32_t(0x832AD450);
	if (!UseLiftedCode(145, 0x83286F18)) { __imp__sub_83286F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4098, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD450_address);
}
PROMOTED_ENTRY(145, sub_83286F18, 0x83286F18) { ctx.r3.u64 = InitializeGlobalCCharString_834A4098(ctx, base); }

uint64_t InitializeGlobalCCharString_834A409C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A409C = int32_t(0x834A409C);
	constexpr int32_t n_sub_832AD460_address = int32_t(0x832AD460);
	if (!UseLiftedCode(145, 0x83286F58)) { __imp__sub_83286F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A409C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD460_address);
}
PROMOTED_ENTRY(145, sub_83286F58, 0x83286F58) { ctx.r3.u64 = InitializeGlobalCCharString_834A409C(ctx, base); }

uint64_t InitializeGlobalCCharString_834A40A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40A0 = int32_t(0x834A40A0);
	constexpr int32_t n_sub_832AD470_address = int32_t(0x832AD470);
	if (!UseLiftedCode(145, 0x83286F98)) { __imp__sub_83286F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40A0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD470_address);
}
PROMOTED_ENTRY(145, sub_83286F98, 0x83286F98) { ctx.r3.u64 = InitializeGlobalCCharString_834A40A0(ctx, base); }

uint64_t InitializeGlobalCCharString_834A40A4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40A4 = int32_t(0x834A40A4);
	constexpr int32_t n_sub_832AD480_address = int32_t(0x832AD480);
	if (!UseLiftedCode(145, 0x83286FD8)) { __imp__sub_83286FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286FD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40A4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD480_address);
}
PROMOTED_ENTRY(145, sub_83286FD8, 0x83286FD8) { ctx.r3.u64 = InitializeGlobalCCharString_834A40A4(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40A8 = int32_t(0x834A40A8);
	constexpr int32_t n_sub_832AD490_address = int32_t(0x832AD490);
	if (!UseLiftedCode(145, 0x83287018)) { __imp__sub_83287018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287018);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40A8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD490_address);
}
PROMOTED_ENTRY(145, sub_83287018, 0x83287018) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40A8(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40AC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40AC = int32_t(0x834A40AC);
	constexpr int32_t n_sub_832AD4A0_address = int32_t(0x832AD4A0);
	if (!UseLiftedCode(145, 0x83287058)) { __imp__sub_83287058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287058);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40AC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4A0_address);
}
PROMOTED_ENTRY(145, sub_83287058, 0x83287058) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40AC(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40B0 = int32_t(0x834A40B0);
	constexpr int32_t n_sub_832AD4B0_address = int32_t(0x832AD4B0);
	if (!UseLiftedCode(145, 0x83287098)) { __imp__sub_83287098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287098);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40B0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4B0_address);
}
PROMOTED_ENTRY(145, sub_83287098, 0x83287098) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40B0(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40B4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40B4 = int32_t(0x834A40B4);
	constexpr int32_t n_sub_832AD4C0_address = int32_t(0x832AD4C0);
	if (!UseLiftedCode(145, 0x832870D8)) { __imp__sub_832870D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832870D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40B4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4C0_address);
}
PROMOTED_ENTRY(145, sub_832870D8, 0x832870D8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40B4(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40B8 = int32_t(0x834A40B8);
	constexpr int32_t n_sub_832AD4D0_address = int32_t(0x832AD4D0);
	if (!UseLiftedCode(145, 0x83287118)) { __imp__sub_83287118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287118);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40B8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4D0_address);
}
PROMOTED_ENTRY(145, sub_83287118, 0x83287118) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40B8(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40BC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40BC = int32_t(0x834A40BC);
	constexpr int32_t n_sub_832AD4E0_address = int32_t(0x832AD4E0);
	if (!UseLiftedCode(145, 0x83287158)) { __imp__sub_83287158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287158);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40BC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4E0_address);
}
PROMOTED_ENTRY(145, sub_83287158, 0x83287158) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40BC(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40C0 = int32_t(0x834A40C0);
	constexpr int32_t n_sub_832AD4F0_address = int32_t(0x832AD4F0);
	if (!UseLiftedCode(145, 0x83287198)) { __imp__sub_83287198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287198);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40C0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD4F0_address);
}
PROMOTED_ENTRY(145, sub_83287198, 0x83287198) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40C0(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40C4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40C4 = int32_t(0x834A40C4);
	constexpr int32_t n_sub_832AD500_address = int32_t(0x832AD500);
	if (!UseLiftedCode(145, 0x832871D8)) { __imp__sub_832871D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832871D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40C4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD500_address);
}
PROMOTED_ENTRY(145, sub_832871D8, 0x832871D8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40C4(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40C8 = int32_t(0x834A40C8);
	constexpr int32_t n_sub_832AD510_address = int32_t(0x832AD510);
	if (!UseLiftedCode(145, 0x83287218)) { __imp__sub_83287218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287218);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40C8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD510_address);
}
PROMOTED_ENTRY(145, sub_83287218, 0x83287218) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40C8(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40CC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40CC = int32_t(0x834A40CC);
	constexpr int32_t n_sub_832AD520_address = int32_t(0x832AD520);
	if (!UseLiftedCode(145, 0x83287258)) { __imp__sub_83287258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40CC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD520_address);
}
PROMOTED_ENTRY(145, sub_83287258, 0x83287258) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40CC(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40D0 = int32_t(0x834A40D0);
	constexpr int32_t n_sub_832AD530_address = int32_t(0x832AD530);
	if (!UseLiftedCode(145, 0x83287298)) { __imp__sub_83287298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40D0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD530_address);
}
PROMOTED_ENTRY(145, sub_83287298, 0x83287298) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40D0(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A40D4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A40D4 = int32_t(0x834A40D4);
	constexpr int32_t n_sub_832AD540_address = int32_t(0x832AD540);
	if (!UseLiftedCode(145, 0x832872D8)) { __imp__sub_832872D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832872D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A40D4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD540_address);
}
PROMOTED_ENTRY(145, sub_832872D8, 0x832872D8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A40D4(ctx, base); }

uint64_t n_sub_83287358(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD5A8_address = int32_t(0x832AD5A8);
	if (!UseLiftedCode(145, 0x83287358)) { ctx.r8.u64 = arg1; __imp__sub_83287358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287358);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD5A8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287358, 0x83287358) { ctx.r3.u64 = n_sub_83287358(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A412C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A412C = int32_t(0x834A412C);
	constexpr int32_t n_sub_832AD620_address = int32_t(0x832AD620);
	if (!UseLiftedCode(145, 0x83287368)) { __imp__sub_83287368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287368);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A412C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD620_address);
}
PROMOTED_ENTRY(145, sub_83287368, 0x83287368) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A412C(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4130(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4130 = int32_t(0x834A4130);
	constexpr int32_t n_sub_832AD630_address = int32_t(0x832AD630);
	if (!UseLiftedCode(145, 0x832873A8)) { __imp__sub_832873A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832873A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4130, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD630_address);
}
PROMOTED_ENTRY(145, sub_832873A8, 0x832873A8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4130(ctx, base); }

uint64_t n_sub_83287438(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD670_address = int32_t(0x832AD670);
	if (!UseLiftedCode(145, 0x83287438)) { ctx.r8.u64 = arg1; __imp__sub_83287438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287438);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD670_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287438, 0x83287438) { ctx.r3.u64 = n_sub_83287438(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A416C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A416C = int32_t(0x834A416C);
	constexpr int32_t n_sub_832AD6C8_address = int32_t(0x832AD6C8);
	if (!UseLiftedCode(145, 0x83287448)) { __imp__sub_83287448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A416C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD6C8_address);
}
PROMOTED_ENTRY(145, sub_83287448, 0x83287448) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A416C(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4170(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4170 = int32_t(0x834A4170);
	constexpr int32_t n_sub_832AD6D8_address = int32_t(0x832AD6D8);
	if (!UseLiftedCode(145, 0x83287488)) { __imp__sub_83287488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4170, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD6D8_address);
}
PROMOTED_ENTRY(145, sub_83287488, 0x83287488) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4170(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A419C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A419C = int32_t(0x834A419C);
	constexpr int32_t n_sub_832AD718_address = int32_t(0x832AD718);
	if (!UseLiftedCode(145, 0x83287518)) { __imp__sub_83287518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287518);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A419C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD718_address);
}
PROMOTED_ENTRY(145, sub_83287518, 0x83287518) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A419C(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A41A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A41A0 = int32_t(0x834A41A0);
	constexpr int32_t n_sub_832AD728_address = int32_t(0x832AD728);
	if (!UseLiftedCode(145, 0x83287558)) { __imp__sub_83287558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A41A0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD728_address);
}
PROMOTED_ENTRY(145, sub_83287558, 0x83287558) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A41A0(ctx, base); }

uint64_t n_sub_83287660(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD7F8_address = int32_t(0x832AD7F8);
	if (!UseLiftedCode(145, 0x83287660)) { ctx.r8.u64 = arg1; __imp__sub_83287660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287660);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD7F8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287660, 0x83287660) { ctx.r3.u64 = n_sub_83287660(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287670(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD870_address = int32_t(0x832AD870);
	if (!UseLiftedCode(145, 0x83287670)) { ctx.r8.u64 = arg1; __imp__sub_83287670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287670);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD870_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287670, 0x83287670) { ctx.r3.u64 = n_sub_83287670(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4AE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4AE0 = int32_t(0x834A4AE0);
	constexpr int32_t n_sub_832AD880_address = int32_t(0x832AD880);
	if (!UseLiftedCode(145, 0x83287680)) { __imp__sub_83287680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287680);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4AE0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD880_address);
}
PROMOTED_ENTRY(145, sub_83287680, 0x83287680) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4AE0(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4AE4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4AE4 = int32_t(0x834A4AE4);
	constexpr int32_t n_sub_832AD890_address = int32_t(0x832AD890);
	if (!UseLiftedCode(145, 0x832876C0)) { __imp__sub_832876C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832876C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4AE4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AD890_address);
}
PROMOTED_ENTRY(145, sub_832876C0, 0x832876C0) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4AE4(ctx, base); }

uint64_t n_sub_832877B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD8A0_address = int32_t(0x832AD8A0);
	if (!UseLiftedCode(145, 0x832877B8)) { ctx.r8.u64 = arg1; __imp__sub_832877B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877B8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD8A0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832877B8, 0x832877B8) { ctx.r3.u64 = n_sub_832877B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832877C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD900_address = int32_t(0x832AD900);
	if (!UseLiftedCode(145, 0x832877C8)) { ctx.r8.u64 = arg1; __imp__sub_832877C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877C8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD900_address, arg1);
}
PROMOTED_ENTRY(145, sub_832877C8, 0x832877C8) { ctx.r3.u64 = n_sub_832877C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832877D8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AD960_address = int32_t(0x832AD960);
	if (!UseLiftedCode(145, 0x832877D8)) { ctx.r8.u64 = arg1; __imp__sub_832877D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877D8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AD960_address, arg1);
}
PROMOTED_ENTRY(145, sub_832877D8, 0x832877D8) { ctx.r3.u64 = n_sub_832877D8(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4B98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4B98 = int32_t(0x834A4B98);
	constexpr int32_t n_sub_832ADA10_address = int32_t(0x832ADA10);
	if (!UseLiftedCode(145, 0x83287860)) { __imp__sub_83287860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287860);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4B98, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADA10_address);
}
PROMOTED_ENTRY(145, sub_83287860, 0x83287860) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4B98(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4B9C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4B9C = int32_t(0x834A4B9C);
	constexpr int32_t n_sub_832ADA20_address = int32_t(0x832ADA20);
	if (!UseLiftedCode(145, 0x832878A0)) { __imp__sub_832878A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4B9C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADA20_address);
}
PROMOTED_ENTRY(145, sub_832878A0, 0x832878A0) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4B9C(ctx, base); }

uint64_t n_sub_832878E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADA30_address = int32_t(0x832ADA30);
	if (!UseLiftedCode(145, 0x832878E0)) { ctx.r8.u64 = arg1; __imp__sub_832878E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878E0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADA30_address, arg1);
}
PROMOTED_ENTRY(145, sub_832878E0, 0x832878E0) { ctx.r3.u64 = n_sub_832878E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832878F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADA88_address = int32_t(0x832ADA88);
	if (!UseLiftedCode(145, 0x832878F0)) { ctx.r8.u64 = arg1; __imp__sub_832878F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADA88_address, arg1);
}
PROMOTED_ENTRY(145, sub_832878F0, 0x832878F0) { ctx.r3.u64 = n_sub_832878F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287900(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADAE0_address = int32_t(0x832ADAE0);
	if (!UseLiftedCode(145, 0x83287900)) { ctx.r8.u64 = arg1; __imp__sub_83287900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287900);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADAE0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287900, 0x83287900) { ctx.r3.u64 = n_sub_83287900(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4BD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4BD0 = int32_t(0x834A4BD0);
	constexpr int32_t n_sub_832ADB38_address = int32_t(0x832ADB38);
	if (!UseLiftedCode(145, 0x83287910)) { __imp__sub_83287910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4BD0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADB38_address);
}
PROMOTED_ENTRY(145, sub_83287910, 0x83287910) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4BD0(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4BD4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4BD4 = int32_t(0x834A4BD4);
	constexpr int32_t n_sub_832ADB48_address = int32_t(0x832ADB48);
	if (!UseLiftedCode(145, 0x83287950)) { __imp__sub_83287950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4BD4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADB48_address);
}
PROMOTED_ENTRY(145, sub_83287950, 0x83287950) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4BD4(ctx, base); }

uint64_t n_sub_83287990(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADB58_address = int32_t(0x832ADB58);
	if (!UseLiftedCode(145, 0x83287990)) { ctx.r8.u64 = arg1; __imp__sub_83287990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287990);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADB58_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287990, 0x83287990) { ctx.r3.u64 = n_sub_83287990(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4C20 = int32_t(0x834A4C20);
	constexpr int32_t n_sub_832ADCF8_address = int32_t(0x832ADCF8);
	if (!UseLiftedCode(145, 0x83287BF0)) { __imp__sub_83287BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287BF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4C20, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADCF8_address);
}
PROMOTED_ENTRY(145, sub_83287BF0, 0x83287BF0) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4C20(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4C24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4C24 = int32_t(0x834A4C24);
	constexpr int32_t n_sub_832ADD08_address = int32_t(0x832ADD08);
	if (!UseLiftedCode(145, 0x83287C30)) { __imp__sub_83287C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287C30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4C24, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADD08_address);
}
PROMOTED_ENTRY(145, sub_83287C30, 0x83287C30) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4C24(ctx, base); }

uint64_t n_sub_83287EB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADD18_address = int32_t(0x832ADD18);
	if (!UseLiftedCode(145, 0x83287EB8)) { ctx.r8.u64 = arg1; __imp__sub_83287EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EB8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADD18_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287EB8, 0x83287EB8) { ctx.r3.u64 = n_sub_83287EB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADD58_address = int32_t(0x832ADD58);
	if (!UseLiftedCode(145, 0x83287EC8)) { ctx.r8.u64 = arg1; __imp__sub_83287EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EC8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADD58_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287EC8, 0x83287EC8) { ctx.r3.u64 = n_sub_83287EC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287ED8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADD98_address = int32_t(0x832ADD98);
	if (!UseLiftedCode(145, 0x83287ED8)) { ctx.r8.u64 = arg1; __imp__sub_83287ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287ED8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADD98_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287ED8, 0x83287ED8) { ctx.r3.u64 = n_sub_83287ED8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADDD8_address = int32_t(0x832ADDD8);
	if (!UseLiftedCode(145, 0x83287EE8)) { ctx.r8.u64 = arg1; __imp__sub_83287EE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EE8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADDD8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287EE8, 0x83287EE8) { ctx.r3.u64 = n_sub_83287EE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADE18_address = int32_t(0x832ADE18);
	if (!UseLiftedCode(145, 0x83287EF8)) { ctx.r8.u64 = arg1; __imp__sub_83287EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EF8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADE18_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287EF8, 0x83287EF8) { ctx.r3.u64 = n_sub_83287EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287F30(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADE70_address = int32_t(0x832ADE70);
	if (!UseLiftedCode(145, 0x83287F30)) { ctx.r8.u64 = arg1; __imp__sub_83287F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287F30);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADE70_address, arg1);
}
PROMOTED_ENTRY(145, sub_83287F30, 0x83287F30) { ctx.r3.u64 = n_sub_83287F30(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4D34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4D34 = int32_t(0x834A4D34);
	constexpr int32_t n_sub_832ADF08_address = int32_t(0x832ADF08);
	if (!UseLiftedCode(145, 0x83288210)) { __imp__sub_83288210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288210);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4D34, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF08_address);
}
PROMOTED_ENTRY(145, sub_83288210, 0x83288210) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4D34(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4D38 = int32_t(0x834A4D38);
	constexpr int32_t n_sub_832ADF18_address = int32_t(0x832ADF18);
	if (!UseLiftedCode(145, 0x83288250)) { __imp__sub_83288250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288250);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4D38, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF18_address);
}
PROMOTED_ENTRY(145, sub_83288250, 0x83288250) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4D38(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4E30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4E30 = int32_t(0x834A4E30);
	constexpr int32_t n_sub_832ADF30_address = int32_t(0x832ADF30);
	if (!UseLiftedCode(145, 0x83288490)) { __imp__sub_83288490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4E30, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF30_address);
}
PROMOTED_ENTRY(145, sub_83288490, 0x83288490) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4E30(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A4E34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A4E34 = int32_t(0x834A4E34);
	constexpr int32_t n_sub_832ADF40_address = int32_t(0x832ADF40);
	if (!UseLiftedCode(145, 0x832884D0)) { __imp__sub_832884D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832884D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A4E34, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF40_address);
}
PROMOTED_ENTRY(145, sub_832884D0, 0x832884D0) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A4E34(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A5240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5240 = int32_t(0x834A5240);
	constexpr int32_t n_sub_832ADF70_address = int32_t(0x832ADF70);
	if (!UseLiftedCode(145, 0x83288598)) { __imp__sub_83288598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5240, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF70_address);
}
PROMOTED_ENTRY(145, sub_83288598, 0x83288598) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A5240(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A5244(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5244 = int32_t(0x834A5244);
	constexpr int32_t n_sub_832ADF80_address = int32_t(0x832ADF80);
	if (!UseLiftedCode(145, 0x832885D8)) { __imp__sub_832885D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832885D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5244, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADF80_address);
}
PROMOTED_ENTRY(145, sub_832885D8, 0x832885D8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A5244(ctx, base); }

uint64_t n_sub_83288618(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832ADF90_address = int32_t(0x832ADF90);
	if (!UseLiftedCode(145, 0x83288618)) { ctx.r8.u64 = arg1; __imp__sub_83288618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288618);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832ADF90_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288618, 0x83288618) { ctx.r3.u64 = n_sub_83288618(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalStringAndRegisterExit_834A5258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5258 = int32_t(0x834A5258);
	constexpr int32_t n_sub_832ADFE8_address = int32_t(0x832ADFE8);
	if (!UseLiftedCode(145, 0x83288628)) { __imp__sub_83288628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5258, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADFE8_address);
}
PROMOTED_ENTRY(145, sub_83288628, 0x83288628) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A5258(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A525C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A525C = int32_t(0x834A525C);
	constexpr int32_t n_sub_832ADFF8_address = int32_t(0x832ADFF8);
	if (!UseLiftedCode(145, 0x83288668)) { __imp__sub_83288668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288668);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A525C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832ADFF8_address);
}
PROMOTED_ENTRY(145, sub_83288668, 0x83288668) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A525C(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A5260(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5260 = int32_t(0x834A5260);
	constexpr int32_t n_sub_832AE008_address = int32_t(0x832AE008);
	if (!UseLiftedCode(145, 0x832886A8)) { __imp__sub_832886A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832886A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5260, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE008_address);
}
PROMOTED_ENTRY(145, sub_832886A8, 0x832886A8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A5260(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A5264(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5264 = int32_t(0x834A5264);
	constexpr int32_t n_sub_832AE018_address = int32_t(0x832AE018);
	if (!UseLiftedCode(145, 0x832886E8)) { __imp__sub_832886E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832886E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5264, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE018_address);
}
PROMOTED_ENTRY(145, sub_832886E8, 0x832886E8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A5264(ctx, base); }

uint64_t InitializeGlobalStringAndRegisterExit_834A52E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52E0 = int32_t(0x834A52E0);
	constexpr int32_t n_sub_832AE0B0_address = int32_t(0x832AE0B0);
	if (!UseLiftedCode(145, 0x832887B8)) { __imp__sub_832887B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832887B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52E0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE0B0_address);
}
PROMOTED_ENTRY(145, sub_832887B8, 0x832887B8) { ctx.r3.u64 = InitializeGlobalStringAndRegisterExit_834A52E0(ctx, base); }

uint64_t CCharString_GlobalInit_834A52E4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52E4 = int32_t(0x834A52E4);
	constexpr int32_t n_sub_832AE0C0_address = int32_t(0x832AE0C0);
	if (!UseLiftedCode(145, 0x832887F8)) { __imp__sub_832887F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832887F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52E4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE0C0_address);
}
PROMOTED_ENTRY(145, sub_832887F8, 0x832887F8) { ctx.r3.u64 = CCharString_GlobalInit_834A52E4(ctx, base); }

uint64_t CCharString_GlobalInit_834A52E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52E8 = int32_t(0x834A52E8);
	constexpr int32_t n_sub_832AE0D0_address = int32_t(0x832AE0D0);
	if (!UseLiftedCode(145, 0x83288838)) { __imp__sub_83288838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52E8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE0D0_address);
}
PROMOTED_ENTRY(145, sub_83288838, 0x83288838) { ctx.r3.u64 = CCharString_GlobalInit_834A52E8(ctx, base); }

uint64_t CCharString_GlobalInit_834A52EC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52EC = int32_t(0x834A52EC);
	constexpr int32_t n_sub_832AE0E0_address = int32_t(0x832AE0E0);
	if (!UseLiftedCode(145, 0x83288878)) { __imp__sub_83288878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288878);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52EC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE0E0_address);
}
PROMOTED_ENTRY(145, sub_83288878, 0x83288878) { ctx.r3.u64 = CCharString_GlobalInit_834A52EC(ctx, base); }

uint64_t CCharString_GlobalInit_834A52F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52F0 = int32_t(0x834A52F0);
	constexpr int32_t n_sub_832AE0F0_address = int32_t(0x832AE0F0);
	if (!UseLiftedCode(145, 0x832888B8)) { __imp__sub_832888B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832888B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52F0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE0F0_address);
}
PROMOTED_ENTRY(145, sub_832888B8, 0x832888B8) { ctx.r3.u64 = CCharString_GlobalInit_834A52F0(ctx, base); }

uint64_t CCharString_GlobalInit_834A52F4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A52F4 = int32_t(0x834A52F4);
	constexpr int32_t n_sub_832AE100_address = int32_t(0x832AE100);
	if (!UseLiftedCode(145, 0x832888F8)) { __imp__sub_832888F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832888F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A52F4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE100_address);
}
PROMOTED_ENTRY(145, sub_832888F8, 0x832888F8) { ctx.r3.u64 = CCharString_GlobalInit_834A52F4(ctx, base); }

uint64_t n_sub_83288B78(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE2C0_address = int32_t(0x832AE2C0);
	if (!UseLiftedCode(145, 0x83288B78)) { ctx.r8.u64 = arg1; __imp__sub_83288B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B78);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE2C0_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288B78, 0x83288B78) { ctx.r3.u64 = n_sub_83288B78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288B88(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE318_address = int32_t(0x832AE318);
	if (!UseLiftedCode(145, 0x83288B88)) { ctx.r8.u64 = arg1; __imp__sub_83288B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B88);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE318_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288B88, 0x83288B88) { ctx.r3.u64 = n_sub_83288B88(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288B98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE328_address = int32_t(0x832AE328);
	if (!UseLiftedCode(145, 0x83288B98)) { ctx.r8.u64 = arg1; __imp__sub_83288B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B98);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE328_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288B98, 0x83288B98) { ctx.r3.u64 = n_sub_83288B98(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A534C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A534C = int32_t(0x834A534C);
	constexpr int32_t n_sub_832AE338_address = int32_t(0x832AE338);
	if (!UseLiftedCode(145, 0x83288BA8)) { __imp__sub_83288BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288BA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A534C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE338_address);
}
PROMOTED_ENTRY(145, sub_83288BA8, 0x83288BA8) { ctx.r3.u64 = CCharString_GlobalInit_834A534C(ctx, base); }

uint64_t CCharString_GlobalInit_834A5350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5350 = int32_t(0x834A5350);
	constexpr int32_t n_sub_832AE348_address = int32_t(0x832AE348);
	if (!UseLiftedCode(145, 0x83288BE8)) { __imp__sub_83288BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5350, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE348_address);
}
PROMOTED_ENTRY(145, sub_83288BE8, 0x83288BE8) { ctx.r3.u64 = CCharString_GlobalInit_834A5350(ctx, base); }

uint64_t CCharString_GlobalInit_834A5354(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5354 = int32_t(0x834A5354);
	constexpr int32_t n_sub_832AE358_address = int32_t(0x832AE358);
	if (!UseLiftedCode(145, 0x83288C28)) { __imp__sub_83288C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288C28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5354, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE358_address);
}
PROMOTED_ENTRY(145, sub_83288C28, 0x83288C28) { ctx.r3.u64 = CCharString_GlobalInit_834A5354(ctx, base); }

uint64_t CCharString_GlobalInit_834A5358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5358 = int32_t(0x834A5358);
	constexpr int32_t n_sub_832AE368_address = int32_t(0x832AE368);
	if (!UseLiftedCode(145, 0x83288C68)) { __imp__sub_83288C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288C68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5358, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE368_address);
}
PROMOTED_ENTRY(145, sub_83288C68, 0x83288C68) { ctx.r3.u64 = CCharString_GlobalInit_834A5358(ctx, base); }

uint64_t CCharString_GlobalInit_834A535C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A535C = int32_t(0x834A535C);
	constexpr int32_t n_sub_832AE378_address = int32_t(0x832AE378);
	if (!UseLiftedCode(145, 0x83288CA8)) { __imp__sub_83288CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288CA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A535C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE378_address);
}
PROMOTED_ENTRY(145, sub_83288CA8, 0x83288CA8) { ctx.r3.u64 = CCharString_GlobalInit_834A535C(ctx, base); }

uint64_t CCharString_GlobalInit_834A5360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5360 = int32_t(0x834A5360);
	constexpr int32_t n_sub_832AE388_address = int32_t(0x832AE388);
	if (!UseLiftedCode(145, 0x83288CE8)) { __imp__sub_83288CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288CE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5360, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE388_address);
}
PROMOTED_ENTRY(145, sub_83288CE8, 0x83288CE8) { ctx.r3.u64 = CCharString_GlobalInit_834A5360(ctx, base); }

uint64_t n_sub_83288D28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE398_address = int32_t(0x832AE398);
	if (!UseLiftedCode(145, 0x83288D28)) { ctx.r8.u64 = arg1; __imp__sub_83288D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D28);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE398_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288D28, 0x83288D28) { ctx.r3.u64 = n_sub_83288D28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288D38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE3A8_address = int32_t(0x832AE3A8);
	if (!UseLiftedCode(145, 0x83288D38)) { ctx.r8.u64 = arg1; __imp__sub_83288D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D38);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE3A8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288D38, 0x83288D38) { ctx.r3.u64 = n_sub_83288D38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288D48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE3B8_address = int32_t(0x832AE3B8);
	if (!UseLiftedCode(145, 0x83288D48)) { ctx.r8.u64 = arg1; __imp__sub_83288D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D48);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE3B8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83288D48, 0x83288D48) { ctx.r3.u64 = n_sub_83288D48(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A53A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53A0 = int32_t(0x834A53A0);
	constexpr int32_t n_sub_832AE3D0_address = int32_t(0x832AE3D0);
	if (!UseLiftedCode(145, 0x83288D90)) { __imp__sub_83288D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53A0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE3D0_address);
}
PROMOTED_ENTRY(145, sub_83288D90, 0x83288D90) { ctx.r3.u64 = CCharString_GlobalInit_834A53A0(ctx, base); }

uint64_t CCharString_GlobalInit_834A53A4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53A4 = int32_t(0x834A53A4);
	constexpr int32_t n_sub_832AE3E0_address = int32_t(0x832AE3E0);
	if (!UseLiftedCode(145, 0x83288DD0)) { __imp__sub_83288DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288DD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53A4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE3E0_address);
}
PROMOTED_ENTRY(145, sub_83288DD0, 0x83288DD0) { ctx.r3.u64 = CCharString_GlobalInit_834A53A4(ctx, base); }

uint64_t CCharString_GlobalInit_834A53BC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53BC = int32_t(0x834A53BC);
	constexpr int32_t n_sub_832AE408_address = int32_t(0x832AE408);
	if (!UseLiftedCode(145, 0x83288E38)) { __imp__sub_83288E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53BC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE408_address);
}
PROMOTED_ENTRY(145, sub_83288E38, 0x83288E38) { ctx.r3.u64 = CCharString_GlobalInit_834A53BC(ctx, base); }

uint64_t CCharString_GlobalInit_834A53C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53C0 = int32_t(0x834A53C0);
	constexpr int32_t n_sub_832AE418_address = int32_t(0x832AE418);
	if (!UseLiftedCode(145, 0x83288E78)) { __imp__sub_83288E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53C0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE418_address);
}
PROMOTED_ENTRY(145, sub_83288E78, 0x83288E78) { ctx.r3.u64 = CCharString_GlobalInit_834A53C0(ctx, base); }

uint64_t CCharString_GlobalInit_834A53C4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53C4 = int32_t(0x834A53C4);
	constexpr int32_t n_sub_832AE428_address = int32_t(0x832AE428);
	if (!UseLiftedCode(145, 0x83288EB8)) { __imp__sub_83288EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53C4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE428_address);
}
PROMOTED_ENTRY(145, sub_83288EB8, 0x83288EB8) { ctx.r3.u64 = CCharString_GlobalInit_834A53C4(ctx, base); }

uint64_t CCharString_GlobalInit_834A53C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A53C8 = int32_t(0x834A53C8);
	constexpr int32_t n_sub_832AE438_address = int32_t(0x832AE438);
	if (!UseLiftedCode(145, 0x83288EF8)) { __imp__sub_83288EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A53C8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE438_address);
}
PROMOTED_ENTRY(145, sub_83288EF8, 0x83288EF8) { ctx.r3.u64 = CCharString_GlobalInit_834A53C8(ctx, base); }

uint64_t n_sub_83289088(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE628_address = int32_t(0x832AE628);
	if (!UseLiftedCode(145, 0x83289088)) { ctx.r8.u64 = arg1; __imp__sub_83289088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289088);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE628_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289088, 0x83289088) { ctx.r3.u64 = n_sub_83289088(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A5438(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5438 = int32_t(0x834A5438);
	constexpr int32_t n_sub_832AE6A8_address = int32_t(0x832AE6A8);
	if (!UseLiftedCode(145, 0x83289128)) { __imp__sub_83289128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289128);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5438, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE6A8_address);
}
PROMOTED_ENTRY(145, sub_83289128, 0x83289128) { ctx.r3.u64 = CCharString_GlobalInit_834A5438(ctx, base); }

uint64_t CCharString_GlobalInit_834A543C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A543C = int32_t(0x834A543C);
	constexpr int32_t n_sub_832AE6B8_address = int32_t(0x832AE6B8);
	if (!UseLiftedCode(145, 0x83289168)) { __imp__sub_83289168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289168);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A543C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE6B8_address);
}
PROMOTED_ENTRY(145, sub_83289168, 0x83289168) { ctx.r3.u64 = CCharString_GlobalInit_834A543C(ctx, base); }

uint64_t CCharString_GlobalInit_834A544C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A544C = int32_t(0x834A544C);
	constexpr int32_t n_sub_832AE6D8_address = int32_t(0x832AE6D8);
	if (!UseLiftedCode(145, 0x83289238)) { __imp__sub_83289238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A544C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE6D8_address);
}
PROMOTED_ENTRY(145, sub_83289238, 0x83289238) { ctx.r3.u64 = CCharString_GlobalInit_834A544C(ctx, base); }

uint64_t CCharString_GlobalInit_834A5450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5450 = int32_t(0x834A5450);
	constexpr int32_t n_sub_832AE6E8_address = int32_t(0x832AE6E8);
	if (!UseLiftedCode(145, 0x83289278)) { __imp__sub_83289278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5450, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE6E8_address);
}
PROMOTED_ENTRY(145, sub_83289278, 0x83289278) { ctx.r3.u64 = CCharString_GlobalInit_834A5450(ctx, base); }

uint64_t CCharString_GlobalInit_834A5454(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5454 = int32_t(0x834A5454);
	constexpr int32_t n_sub_832AE6F8_address = int32_t(0x832AE6F8);
	if (!UseLiftedCode(145, 0x832892B8)) { __imp__sub_832892B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832892B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5454, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE6F8_address);
}
PROMOTED_ENTRY(145, sub_832892B8, 0x832892B8) { ctx.r3.u64 = CCharString_GlobalInit_834A5454(ctx, base); }

uint64_t CCharString_GlobalInit_834A5458(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5458 = int32_t(0x834A5458);
	constexpr int32_t n_sub_832AE708_address = int32_t(0x832AE708);
	if (!UseLiftedCode(145, 0x832892F8)) { __imp__sub_832892F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832892F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5458, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE708_address);
}
PROMOTED_ENTRY(145, sub_832892F8, 0x832892F8) { ctx.r3.u64 = CCharString_GlobalInit_834A5458(ctx, base); }

uint64_t n_sub_83289338(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE718_address = int32_t(0x832AE718);
	if (!UseLiftedCode(145, 0x83289338)) { ctx.r8.u64 = arg1; __imp__sub_83289338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289338);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE718_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289338, 0x83289338) { ctx.r3.u64 = n_sub_83289338(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289348(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE770_address = int32_t(0x832AE770);
	if (!UseLiftedCode(145, 0x83289348)) { ctx.r8.u64 = arg1; __imp__sub_83289348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289348);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE770_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289348, 0x83289348) { ctx.r3.u64 = n_sub_83289348(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A547C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A547C = int32_t(0x834A547C);
	constexpr int32_t n_sub_832AE830_address = int32_t(0x832AE830);
	if (!UseLiftedCode(145, 0x83289358)) { __imp__sub_83289358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A547C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE830_address);
}
PROMOTED_ENTRY(145, sub_83289358, 0x83289358) { ctx.r3.u64 = CCharString_GlobalInit_834A547C(ctx, base); }

uint64_t CCharString_GlobalInit_834A5480(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5480 = int32_t(0x834A5480);
	constexpr int32_t n_sub_832AE840_address = int32_t(0x832AE840);
	if (!UseLiftedCode(145, 0x83289398)) { __imp__sub_83289398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5480, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE840_address);
}
PROMOTED_ENTRY(145, sub_83289398, 0x83289398) { ctx.r3.u64 = CCharString_GlobalInit_834A5480(ctx, base); }

uint64_t CCharString_GlobalInit_834A5484(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5484 = int32_t(0x834A5484);
	constexpr int32_t n_sub_832AE8A8_address = int32_t(0x832AE8A8);
	if (!UseLiftedCode(145, 0x832893D8)) { __imp__sub_832893D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832893D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5484, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE8A8_address);
}
PROMOTED_ENTRY(145, sub_832893D8, 0x832893D8) { ctx.r3.u64 = CCharString_GlobalInit_834A5484(ctx, base); }

uint64_t CCharString_GlobalInit_834A5488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5488 = int32_t(0x834A5488);
	constexpr int32_t n_sub_832AE8B8_address = int32_t(0x832AE8B8);
	if (!UseLiftedCode(145, 0x83289418)) { __imp__sub_83289418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5488, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE8B8_address);
}
PROMOTED_ENTRY(145, sub_83289418, 0x83289418) { ctx.r3.u64 = CCharString_GlobalInit_834A5488(ctx, base); }

uint64_t n_sub_83289458(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE8C8_address = int32_t(0x832AE8C8);
	if (!UseLiftedCode(145, 0x83289458)) { ctx.r8.u64 = arg1; __imp__sub_83289458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289458);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE8C8_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289458, 0x83289458) { ctx.r3.u64 = n_sub_83289458(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A5510(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5510 = int32_t(0x834A5510);
	constexpr int32_t n_sub_832AE930_address = int32_t(0x832AE930);
	if (!UseLiftedCode(145, 0x832894A0)) { __imp__sub_832894A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832894A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5510, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE930_address);
}
PROMOTED_ENTRY(145, sub_832894A0, 0x832894A0) { ctx.r3.u64 = CCharString_GlobalInit_834A5510(ctx, base); }

uint64_t CCharString_GlobalInit_834A5514(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5514 = int32_t(0x834A5514);
	constexpr int32_t n_sub_832AE940_address = int32_t(0x832AE940);
	if (!UseLiftedCode(145, 0x832894E0)) { __imp__sub_832894E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832894E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5514, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE940_address);
}
PROMOTED_ENTRY(145, sub_832894E0, 0x832894E0) { ctx.r3.u64 = CCharString_GlobalInit_834A5514(ctx, base); }

uint64_t n_sub_83289520(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE950_address = int32_t(0x832AE950);
	if (!UseLiftedCode(145, 0x83289520)) { ctx.r8.u64 = arg1; __imp__sub_83289520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289520);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE950_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289520, 0x83289520) { ctx.r3.u64 = n_sub_83289520(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A551C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A551C = int32_t(0x834A551C);
	constexpr int32_t n_sub_832AE9A0_address = int32_t(0x832AE9A0);
	if (!UseLiftedCode(145, 0x83289530)) { __imp__sub_83289530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A551C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE9A0_address);
}
PROMOTED_ENTRY(145, sub_83289530, 0x83289530) { ctx.r3.u64 = CCharString_GlobalInit_834A551C(ctx, base); }

uint64_t CCharString_GlobalInit_834A5520(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5520 = int32_t(0x834A5520);
	constexpr int32_t n_sub_832AE9B0_address = int32_t(0x832AE9B0);
	if (!UseLiftedCode(145, 0x83289570)) { __imp__sub_83289570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5520, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AE9B0_address);
}
PROMOTED_ENTRY(145, sub_83289570, 0x83289570) { ctx.r3.u64 = CCharString_GlobalInit_834A5520(ctx, base); }

uint64_t n_sub_832895B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE9C0_address = int32_t(0x832AE9C0);
	if (!UseLiftedCode(145, 0x832895B0)) { ctx.r8.u64 = arg1; __imp__sub_832895B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895B0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE9C0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832895B0, 0x832895B0) { ctx.r3.u64 = n_sub_832895B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE9D0_address = int32_t(0x832AE9D0);
	if (!UseLiftedCode(145, 0x832895C0)) { ctx.r8.u64 = arg1; __imp__sub_832895C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895C0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE9D0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832895C0, 0x832895C0) { ctx.r3.u64 = n_sub_832895C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE9E0_address = int32_t(0x832AE9E0);
	if (!UseLiftedCode(145, 0x832895D0)) { ctx.r8.u64 = arg1; __imp__sub_832895D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895D0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE9E0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832895D0, 0x832895D0) { ctx.r3.u64 = n_sub_832895D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AE9F0_address = int32_t(0x832AE9F0);
	if (!UseLiftedCode(145, 0x832895E0)) { ctx.r8.u64 = arg1; __imp__sub_832895E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895E0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AE9F0_address, arg1);
}
PROMOTED_ENTRY(145, sub_832895E0, 0x832895E0) { ctx.r3.u64 = n_sub_832895E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AEA00_address = int32_t(0x832AEA00);
	if (!UseLiftedCode(145, 0x832895F0)) { ctx.r8.u64 = arg1; __imp__sub_832895F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AEA00_address, arg1);
}
PROMOTED_ENTRY(145, sub_832895F0, 0x832895F0) { ctx.r3.u64 = n_sub_832895F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289600(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AEA10_address = int32_t(0x832AEA10);
	if (!UseLiftedCode(145, 0x83289600)) { ctx.r8.u64 = arg1; __imp__sub_83289600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289600);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AEA10_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289600, 0x83289600) { ctx.r3.u64 = n_sub_83289600(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289610(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AEA20_address = int32_t(0x832AEA20);
	if (!UseLiftedCode(145, 0x83289610)) { ctx.r8.u64 = arg1; __imp__sub_83289610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289610);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AEA20_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289610, 0x83289610) { ctx.r3.u64 = n_sub_83289610(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289620(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AEA30_address = int32_t(0x832AEA30);
	if (!UseLiftedCode(145, 0x83289620)) { ctx.r8.u64 = arg1; __imp__sub_83289620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289620);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AEA30_address, arg1);
}
PROMOTED_ENTRY(145, sub_83289620, 0x83289620) { ctx.r3.u64 = n_sub_83289620(ctx, base, ctx.r8.u64); }

uint64_t CCharString_GlobalInit_834A55C4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55C4 = int32_t(0x834A55C4);
	constexpr int32_t n_sub_832AEA40_address = int32_t(0x832AEA40);
	if (!UseLiftedCode(145, 0x83289630)) { __imp__sub_83289630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55C4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA40_address);
}
PROMOTED_ENTRY(145, sub_83289630, 0x83289630) { ctx.r3.u64 = CCharString_GlobalInit_834A55C4(ctx, base); }

uint64_t CCharString_GlobalInit_834A55C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55C8 = int32_t(0x834A55C8);
	constexpr int32_t n_sub_832AEA50_address = int32_t(0x832AEA50);
	if (!UseLiftedCode(145, 0x83289670)) { __imp__sub_83289670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55C8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA50_address);
}
PROMOTED_ENTRY(145, sub_83289670, 0x83289670) { ctx.r3.u64 = CCharString_GlobalInit_834A55C8(ctx, base); }

uint64_t CCharString_GlobalInit_834A55CC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55CC = int32_t(0x834A55CC);
	constexpr int32_t n_sub_832AEA60_address = int32_t(0x832AEA60);
	if (!UseLiftedCode(145, 0x832896B0)) { __imp__sub_832896B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832896B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55CC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA60_address);
}
PROMOTED_ENTRY(145, sub_832896B0, 0x832896B0) { ctx.r3.u64 = CCharString_GlobalInit_834A55CC(ctx, base); }

uint64_t CCharString_GlobalInit_834A55D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55D0 = int32_t(0x834A55D0);
	constexpr int32_t n_sub_832AEA70_address = int32_t(0x832AEA70);
	if (!UseLiftedCode(145, 0x832896F0)) { __imp__sub_832896F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832896F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55D0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA70_address);
}
PROMOTED_ENTRY(145, sub_832896F0, 0x832896F0) { ctx.r3.u64 = CCharString_GlobalInit_834A55D0(ctx, base); }

uint64_t CCharString_GlobalInit_834A55D4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55D4 = int32_t(0x834A55D4);
	constexpr int32_t n_sub_832AEA80_address = int32_t(0x832AEA80);
	if (!UseLiftedCode(145, 0x83289730)) { __imp__sub_83289730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55D4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA80_address);
}
PROMOTED_ENTRY(145, sub_83289730, 0x83289730) { ctx.r3.u64 = CCharString_GlobalInit_834A55D4(ctx, base); }

uint64_t CCharString_GlobalInit_834A55D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A55D8 = int32_t(0x834A55D8);
	constexpr int32_t n_sub_832AEA90_address = int32_t(0x832AEA90);
	if (!UseLiftedCode(145, 0x83289770)) { __imp__sub_83289770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A55D8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEA90_address);
}
PROMOTED_ENTRY(145, sub_83289770, 0x83289770) { ctx.r3.u64 = CCharString_GlobalInit_834A55D8(ctx, base); }

uint64_t CCharString_InitGlobal_834A5620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5620 = int32_t(0x834A5620);
	constexpr int32_t n_sub_832AEAA0_address = int32_t(0x832AEAA0);
	if (!UseLiftedCode(145, 0x832897C0)) { __imp__sub_832897C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832897C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5620, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEAA0_address);
}
PROMOTED_ENTRY(145, sub_832897C0, 0x832897C0) { ctx.r3.u64 = CCharString_InitGlobal_834A5620(ctx, base); }

uint64_t CCharString_InitGlobal_834A5624(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5624 = int32_t(0x834A5624);
	constexpr int32_t n_sub_832AEAB0_address = int32_t(0x832AEAB0);
	if (!UseLiftedCode(145, 0x83289800)) { __imp__sub_83289800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289800);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5624, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEAB0_address);
}
PROMOTED_ENTRY(145, sub_83289800, 0x83289800) { ctx.r3.u64 = CCharString_InitGlobal_834A5624(ctx, base); }

uint64_t CCharString_InitGlobal_834A5628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5628 = int32_t(0x834A5628);
	constexpr int32_t n_sub_832AEAC0_address = int32_t(0x832AEAC0);
	if (!UseLiftedCode(145, 0x83289898)) { __imp__sub_83289898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5628, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEAC0_address);
}
PROMOTED_ENTRY(145, sub_83289898, 0x83289898) { ctx.r3.u64 = CCharString_InitGlobal_834A5628(ctx, base); }

uint64_t CCharString_InitGlobal_834A562C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A562C = int32_t(0x834A562C);
	constexpr int32_t n_sub_832AEAD0_address = int32_t(0x832AEAD0);
	if (!UseLiftedCode(145, 0x832898D8)) { __imp__sub_832898D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832898D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A562C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEAD0_address);
}
PROMOTED_ENTRY(145, sub_832898D8, 0x832898D8) { ctx.r3.u64 = CCharString_InitGlobal_834A562C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5700(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5700 = int32_t(0x834A5700);
	constexpr int32_t n_sub_832AEAF8_address = int32_t(0x832AEAF8);
	if (!UseLiftedCode(145, 0x83289CF8)) { __imp__sub_83289CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289CF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5700, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEAF8_address);
}
PROMOTED_ENTRY(145, sub_83289CF8, 0x83289CF8) { ctx.r3.u64 = CCharString_InitGlobal_834A5700(ctx, base); }

uint64_t CCharString_InitGlobal_834A5704(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5704 = int32_t(0x834A5704);
	constexpr int32_t n_sub_832AEB08_address = int32_t(0x832AEB08);
	if (!UseLiftedCode(145, 0x83289D38)) { __imp__sub_83289D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289D38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5704, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB08_address);
}
PROMOTED_ENTRY(145, sub_83289D38, 0x83289D38) { ctx.r3.u64 = CCharString_InitGlobal_834A5704(ctx, base); }

uint64_t CCharString_InitGlobal_834A5708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5708 = int32_t(0x834A5708);
	constexpr int32_t n_sub_832AEB18_address = int32_t(0x832AEB18);
	if (!UseLiftedCode(145, 0x83289D78)) { __imp__sub_83289D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289D78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5708, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB18_address);
}
PROMOTED_ENTRY(145, sub_83289D78, 0x83289D78) { ctx.r3.u64 = CCharString_InitGlobal_834A5708(ctx, base); }

uint64_t CCharString_InitGlobal_834A570C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A570C = int32_t(0x834A570C);
	constexpr int32_t n_sub_832AEB28_address = int32_t(0x832AEB28);
	if (!UseLiftedCode(145, 0x83289DB8)) { __imp__sub_83289DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A570C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB28_address);
}
PROMOTED_ENTRY(145, sub_83289DB8, 0x83289DB8) { ctx.r3.u64 = CCharString_InitGlobal_834A570C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5710 = int32_t(0x834A5710);
	constexpr int32_t n_sub_832AEB38_address = int32_t(0x832AEB38);
	if (!UseLiftedCode(145, 0x83289DF8)) { __imp__sub_83289DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5710, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB38_address);
}
PROMOTED_ENTRY(145, sub_83289DF8, 0x83289DF8) { ctx.r3.u64 = CCharString_InitGlobal_834A5710(ctx, base); }

uint64_t CCharString_InitGlobal_834A5714(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5714 = int32_t(0x834A5714);
	constexpr int32_t n_sub_832AEB48_address = int32_t(0x832AEB48);
	if (!UseLiftedCode(145, 0x83289E38)) { __imp__sub_83289E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5714, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB48_address);
}
PROMOTED_ENTRY(145, sub_83289E38, 0x83289E38) { ctx.r3.u64 = CCharString_InitGlobal_834A5714(ctx, base); }

uint64_t CCharString_InitGlobal_834A5718(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5718 = int32_t(0x834A5718);
	constexpr int32_t n_sub_832AEB58_address = int32_t(0x832AEB58);
	if (!UseLiftedCode(145, 0x83289E78)) { __imp__sub_83289E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5718, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB58_address);
}
PROMOTED_ENTRY(145, sub_83289E78, 0x83289E78) { ctx.r3.u64 = CCharString_InitGlobal_834A5718(ctx, base); }

uint64_t CCharString_InitGlobal_834A571C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A571C = int32_t(0x834A571C);
	constexpr int32_t n_sub_832AEB68_address = int32_t(0x832AEB68);
	if (!UseLiftedCode(145, 0x83289EB8)) { __imp__sub_83289EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A571C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB68_address);
}
PROMOTED_ENTRY(145, sub_83289EB8, 0x83289EB8) { ctx.r3.u64 = CCharString_InitGlobal_834A571C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5720(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5720 = int32_t(0x834A5720);
	constexpr int32_t n_sub_832AEB78_address = int32_t(0x832AEB78);
	if (!UseLiftedCode(145, 0x83289EF8)) { __imp__sub_83289EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5720, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB78_address);
}
PROMOTED_ENTRY(145, sub_83289EF8, 0x83289EF8) { ctx.r3.u64 = CCharString_InitGlobal_834A5720(ctx, base); }

uint64_t CCharString_InitGlobal_834A5724(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5724 = int32_t(0x834A5724);
	constexpr int32_t n_sub_832AEB88_address = int32_t(0x832AEB88);
	if (!UseLiftedCode(145, 0x83289F38)) { __imp__sub_83289F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5724, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB88_address);
}
PROMOTED_ENTRY(145, sub_83289F38, 0x83289F38) { ctx.r3.u64 = CCharString_InitGlobal_834A5724(ctx, base); }

uint64_t CCharString_InitGlobal_834A5728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5728 = int32_t(0x834A5728);
	constexpr int32_t n_sub_832AEB98_address = int32_t(0x832AEB98);
	if (!UseLiftedCode(145, 0x83289F78)) { __imp__sub_83289F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5728, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEB98_address);
}
PROMOTED_ENTRY(145, sub_83289F78, 0x83289F78) { ctx.r3.u64 = CCharString_InitGlobal_834A5728(ctx, base); }

uint64_t CCharString_InitGlobal_834A572C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A572C = int32_t(0x834A572C);
	constexpr int32_t n_sub_832AEBA8_address = int32_t(0x832AEBA8);
	if (!UseLiftedCode(145, 0x83289FB8)) { __imp__sub_83289FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A572C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBA8_address);
}
PROMOTED_ENTRY(145, sub_83289FB8, 0x83289FB8) { ctx.r3.u64 = CCharString_InitGlobal_834A572C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5730 = int32_t(0x834A5730);
	constexpr int32_t n_sub_832AEBB8_address = int32_t(0x832AEBB8);
	if (!UseLiftedCode(145, 0x83289FF8)) { __imp__sub_83289FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5730, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBB8_address);
}
PROMOTED_ENTRY(145, sub_83289FF8, 0x83289FF8) { ctx.r3.u64 = CCharString_InitGlobal_834A5730(ctx, base); }

uint64_t CCharString_InitGlobal_834A5734(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5734 = int32_t(0x834A5734);
	constexpr int32_t n_sub_832AEBC8_address = int32_t(0x832AEBC8);
	if (!UseLiftedCode(145, 0x8328A038)) { __imp__sub_8328A038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5734, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBC8_address);
}
PROMOTED_ENTRY(145, sub_8328A038, 0x8328A038) { ctx.r3.u64 = CCharString_InitGlobal_834A5734(ctx, base); }

uint64_t CCharString_InitGlobal_834A5738(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5738 = int32_t(0x834A5738);
	constexpr int32_t n_sub_832AEBD8_address = int32_t(0x832AEBD8);
	if (!UseLiftedCode(145, 0x8328A078)) { __imp__sub_8328A078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5738, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBD8_address);
}
PROMOTED_ENTRY(145, sub_8328A078, 0x8328A078) { ctx.r3.u64 = CCharString_InitGlobal_834A5738(ctx, base); }

uint64_t CCharString_InitGlobal_834A573C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A573C = int32_t(0x834A573C);
	constexpr int32_t n_sub_832AEBE8_address = int32_t(0x832AEBE8);
	if (!UseLiftedCode(145, 0x8328A0B8)) { __imp__sub_8328A0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A0B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A573C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBE8_address);
}
PROMOTED_ENTRY(145, sub_8328A0B8, 0x8328A0B8) { ctx.r3.u64 = CCharString_InitGlobal_834A573C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5780 = int32_t(0x834A5780);
	constexpr int32_t n_sub_832AEBF8_address = int32_t(0x832AEBF8);
	if (!UseLiftedCode(145, 0x8328A1D8)) { __imp__sub_8328A1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A1D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5780, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEBF8_address);
}
PROMOTED_ENTRY(145, sub_8328A1D8, 0x8328A1D8) { ctx.r3.u64 = CCharString_InitGlobal_834A5780(ctx, base); }

uint64_t CCharString_InitGlobal_834A5784(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5784 = int32_t(0x834A5784);
	constexpr int32_t n_sub_832AEC08_address = int32_t(0x832AEC08);
	if (!UseLiftedCode(145, 0x8328A218)) { __imp__sub_8328A218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A218);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5784, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC08_address);
}
PROMOTED_ENTRY(145, sub_8328A218, 0x8328A218) { ctx.r3.u64 = CCharString_InitGlobal_834A5784(ctx, base); }

uint64_t CCharString_InitGlobal_834A5788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5788 = int32_t(0x834A5788);
	constexpr int32_t n_sub_832AEC18_address = int32_t(0x832AEC18);
	if (!UseLiftedCode(145, 0x8328A258)) { __imp__sub_8328A258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5788, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC18_address);
}
PROMOTED_ENTRY(145, sub_8328A258, 0x8328A258) { ctx.r3.u64 = CCharString_InitGlobal_834A5788(ctx, base); }

uint64_t CCharString_InitGlobal_834A578C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A578C = int32_t(0x834A578C);
	constexpr int32_t n_sub_832AEC28_address = int32_t(0x832AEC28);
	if (!UseLiftedCode(145, 0x8328A298)) { __imp__sub_8328A298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A578C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC28_address);
}
PROMOTED_ENTRY(145, sub_8328A298, 0x8328A298) { ctx.r3.u64 = CCharString_InitGlobal_834A578C(ctx, base); }

uint64_t CCharString_InitGlobal_834A5790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5790 = int32_t(0x834A5790);
	constexpr int32_t n_sub_832AEC38_address = int32_t(0x832AEC38);
	if (!UseLiftedCode(145, 0x8328A2D8)) { __imp__sub_8328A2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A2D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5790, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC38_address);
}
PROMOTED_ENTRY(145, sub_8328A2D8, 0x8328A2D8) { ctx.r3.u64 = CCharString_InitGlobal_834A5790(ctx, base); }

uint64_t CCharString_InitGlobal_834A5794(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5794 = int32_t(0x834A5794);
	constexpr int32_t n_sub_832AEC48_address = int32_t(0x832AEC48);
	if (!UseLiftedCode(145, 0x8328A318)) { __imp__sub_8328A318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A318);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5794, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC48_address);
}
PROMOTED_ENTRY(145, sub_8328A318, 0x8328A318) { ctx.r3.u64 = CCharString_InitGlobal_834A5794(ctx, base); }

uint64_t CCharString_InitGlobal_834A5798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5798 = int32_t(0x834A5798);
	constexpr int32_t n_sub_832AEC58_address = int32_t(0x832AEC58);
	if (!UseLiftedCode(145, 0x8328A358)) { __imp__sub_8328A358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5798, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC58_address);
}
PROMOTED_ENTRY(145, sub_8328A358, 0x8328A358) { ctx.r3.u64 = CCharString_InitGlobal_834A5798(ctx, base); }

uint64_t CCharString_InitGlobal_834A579C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A579C = int32_t(0x834A579C);
	constexpr int32_t n_sub_832AEC68_address = int32_t(0x832AEC68);
	if (!UseLiftedCode(145, 0x8328A398)) { __imp__sub_8328A398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A579C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC68_address);
}
PROMOTED_ENTRY(145, sub_8328A398, 0x8328A398) { ctx.r3.u64 = CCharString_InitGlobal_834A579C(ctx, base); }

uint64_t CCharString_InitGlobal_834A57A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57A0 = int32_t(0x834A57A0);
	constexpr int32_t n_sub_832AEC78_address = int32_t(0x832AEC78);
	if (!UseLiftedCode(145, 0x8328A3D8)) { __imp__sub_8328A3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57A0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC78_address);
}
PROMOTED_ENTRY(145, sub_8328A3D8, 0x8328A3D8) { ctx.r3.u64 = CCharString_InitGlobal_834A57A0(ctx, base); }

uint64_t CCharString_InitGlobal_834A57A4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57A4 = int32_t(0x834A57A4);
	constexpr int32_t n_sub_832AEC88_address = int32_t(0x832AEC88);
	if (!UseLiftedCode(145, 0x8328A418)) { __imp__sub_8328A418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57A4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC88_address);
}
PROMOTED_ENTRY(145, sub_8328A418, 0x8328A418) { ctx.r3.u64 = CCharString_InitGlobal_834A57A4(ctx, base); }

uint64_t CCharString_InitGlobal_834A57A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57A8 = int32_t(0x834A57A8);
	constexpr int32_t n_sub_832AEC98_address = int32_t(0x832AEC98);
	if (!UseLiftedCode(145, 0x8328A458)) { __imp__sub_8328A458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A458);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57A8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEC98_address);
}
PROMOTED_ENTRY(145, sub_8328A458, 0x8328A458) { ctx.r3.u64 = CCharString_InitGlobal_834A57A8(ctx, base); }

uint64_t CCharString_InitGlobal_834A57AC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57AC = int32_t(0x834A57AC);
	constexpr int32_t n_sub_832AECA8_address = int32_t(0x832AECA8);
	if (!UseLiftedCode(145, 0x8328A498)) { __imp__sub_8328A498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A498);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57AC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECA8_address);
}
PROMOTED_ENTRY(145, sub_8328A498, 0x8328A498) { ctx.r3.u64 = CCharString_InitGlobal_834A57AC(ctx, base); }

uint64_t CCharString_InitGlobal_834A57B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57B0 = int32_t(0x834A57B0);
	constexpr int32_t n_sub_832AECB8_address = int32_t(0x832AECB8);
	if (!UseLiftedCode(145, 0x8328A4D8)) { __imp__sub_8328A4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57B0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECB8_address);
}
PROMOTED_ENTRY(145, sub_8328A4D8, 0x8328A4D8) { ctx.r3.u64 = CCharString_InitGlobal_834A57B0(ctx, base); }

uint64_t CCharString_InitGlobal_834A57B4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57B4 = int32_t(0x834A57B4);
	constexpr int32_t n_sub_832AECC8_address = int32_t(0x832AECC8);
	if (!UseLiftedCode(145, 0x8328A518)) { __imp__sub_8328A518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A518);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57B4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECC8_address);
}
PROMOTED_ENTRY(145, sub_8328A518, 0x8328A518) { ctx.r3.u64 = CCharString_InitGlobal_834A57B4(ctx, base); }

uint64_t CCharString_InitGlobal_834A57B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57B8 = int32_t(0x834A57B8);
	constexpr int32_t n_sub_832AECD8_address = int32_t(0x832AECD8);
	if (!UseLiftedCode(145, 0x8328A558)) { __imp__sub_8328A558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57B8, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECD8_address);
}
PROMOTED_ENTRY(145, sub_8328A558, 0x8328A558) { ctx.r3.u64 = CCharString_InitGlobal_834A57B8(ctx, base); }

uint64_t CCharString_InitGlobal_834A57BC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57BC = int32_t(0x834A57BC);
	constexpr int32_t n_sub_832AECE8_address = int32_t(0x832AECE8);
	if (!UseLiftedCode(145, 0x8328A598)) { __imp__sub_8328A598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57BC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECE8_address);
}
PROMOTED_ENTRY(145, sub_8328A598, 0x8328A598) { ctx.r3.u64 = CCharString_InitGlobal_834A57BC(ctx, base); }

uint64_t CCharString_InitGlobal_834A57C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57C0 = int32_t(0x834A57C0);
	constexpr int32_t n_sub_832AECF8_address = int32_t(0x832AECF8);
	if (!UseLiftedCode(145, 0x8328A5D8)) { __imp__sub_8328A5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57C0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AECF8_address);
}
PROMOTED_ENTRY(145, sub_8328A5D8, 0x8328A5D8) { ctx.r3.u64 = CCharString_InitGlobal_834A57C0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A57C4 = int32_t(0x834A57C4);
	constexpr int32_t n_sub_832AED08_address = int32_t(0x832AED08);
	if (!UseLiftedCode(145, 0x8328A618)) { __imp__sub_8328A618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A618);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A57C4, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED08_address);
}
PROMOTED_ENTRY(145, sub_8328A618, 0x8328A618) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A618(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A0C = int32_t(0x834A5A0C);
	constexpr int32_t n_sub_832AED18_address = int32_t(0x832AED18);
	if (!UseLiftedCode(145, 0x8328A668)) { __imp__sub_8328A668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A668);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A0C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED18_address);
}
PROMOTED_ENTRY(145, sub_8328A668, 0x8328A668) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A668(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A6A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A10 = int32_t(0x834A5A10);
	constexpr int32_t n_sub_832AED28_address = int32_t(0x832AED28);
	if (!UseLiftedCode(145, 0x8328A6A8)) { __imp__sub_8328A6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A6A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A10, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED28_address);
}
PROMOTED_ENTRY(145, sub_8328A6A8, 0x8328A6A8) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A6A8(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A6E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A14 = int32_t(0x834A5A14);
	constexpr int32_t n_sub_832AED38_address = int32_t(0x832AED38);
	if (!UseLiftedCode(145, 0x8328A6E8)) { __imp__sub_8328A6E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A6E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A14, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED38_address);
}
PROMOTED_ENTRY(145, sub_8328A6E8, 0x8328A6E8) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A6E8(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A18 = int32_t(0x834A5A18);
	constexpr int32_t n_sub_832AED48_address = int32_t(0x832AED48);
	if (!UseLiftedCode(145, 0x8328A728)) { __imp__sub_8328A728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A728);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A18, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED48_address);
}
PROMOTED_ENTRY(145, sub_8328A728, 0x8328A728) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A728(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A1C = int32_t(0x834A5A1C);
	constexpr int32_t n_sub_832AED58_address = int32_t(0x832AED58);
	if (!UseLiftedCode(145, 0x8328A768)) { __imp__sub_8328A768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A768);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A1C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED58_address);
}
PROMOTED_ENTRY(145, sub_8328A768, 0x8328A768) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A768(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A7A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A20 = int32_t(0x834A5A20);
	constexpr int32_t n_sub_832AED68_address = int32_t(0x832AED68);
	if (!UseLiftedCode(145, 0x8328A7A8)) { __imp__sub_8328A7A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A20, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AED68_address);
}
PROMOTED_ENTRY(145, sub_8328A7A8, 0x8328A7A8) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A7A8(ctx, base); }

uint64_t n_sub_8328A7E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AED78_address = int32_t(0x832AED78);
	if (!UseLiftedCode(145, 0x8328A7E8)) { ctx.r8.u64 = arg1; __imp__sub_8328A7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7E8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AED78_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328A7E8, 0x8328A7E8) { ctx.r3.u64 = n_sub_8328A7E8(ctx, base, ctx.r8.u64); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A7F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A34 = int32_t(0x834A5A34);
	constexpr int32_t n_sub_832AEDD0_address = int32_t(0x832AEDD0);
	if (!UseLiftedCode(145, 0x8328A7F8)) { __imp__sub_8328A7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A34, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEDD0_address);
}
PROMOTED_ENTRY(145, sub_8328A7F8, 0x8328A7F8) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A7F8(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328A838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A38 = int32_t(0x834A5A38);
	constexpr int32_t n_sub_832AEDE0_address = int32_t(0x832AEDE0);
	if (!UseLiftedCode(145, 0x8328A838)) { __imp__sub_8328A838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A38, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEDE0_address);
}
PROMOTED_ENTRY(145, sub_8328A838, 0x8328A838) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328A838(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AD60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A3C = int32_t(0x834A5A3C);
	constexpr int32_t n_sub_832AEDF0_address = int32_t(0x832AEDF0);
	if (!UseLiftedCode(145, 0x8328AD60)) { __imp__sub_8328AD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AD60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A3C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEDF0_address);
}
PROMOTED_ENTRY(145, sub_8328AD60, 0x8328AD60) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AD60(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328ADA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A40 = int32_t(0x834A5A40);
	constexpr int32_t n_sub_832AEE00_address = int32_t(0x832AEE00);
	if (!UseLiftedCode(145, 0x8328ADA0)) { __imp__sub_8328ADA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ADA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A40, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE00_address);
}
PROMOTED_ENTRY(145, sub_8328ADA0, 0x8328ADA0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328ADA0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328ADE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A44 = int32_t(0x834A5A44);
	constexpr int32_t n_sub_832AEE10_address = int32_t(0x832AEE10);
	if (!UseLiftedCode(145, 0x8328ADE0)) { __imp__sub_8328ADE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ADE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A44, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE10_address);
}
PROMOTED_ENTRY(145, sub_8328ADE0, 0x8328ADE0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328ADE0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AE20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A48 = int32_t(0x834A5A48);
	constexpr int32_t n_sub_832AEE20_address = int32_t(0x832AEE20);
	if (!UseLiftedCode(145, 0x8328AE20)) { __imp__sub_8328AE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AE20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A48, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE20_address);
}
PROMOTED_ENTRY(145, sub_8328AE20, 0x8328AE20) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AE20(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AE60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A4C = int32_t(0x834A5A4C);
	constexpr int32_t n_sub_832AEE30_address = int32_t(0x832AEE30);
	if (!UseLiftedCode(145, 0x8328AE60)) { __imp__sub_8328AE60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AE60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A4C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE30_address);
}
PROMOTED_ENTRY(145, sub_8328AE60, 0x8328AE60) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AE60(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AEA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A50 = int32_t(0x834A5A50);
	constexpr int32_t n_sub_832AEE40_address = int32_t(0x832AEE40);
	if (!UseLiftedCode(145, 0x8328AEA0)) { __imp__sub_8328AEA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AEA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A50, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE40_address);
}
PROMOTED_ENTRY(145, sub_8328AEA0, 0x8328AEA0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AEA0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AEE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A54 = int32_t(0x834A5A54);
	constexpr int32_t n_sub_832AEE50_address = int32_t(0x832AEE50);
	if (!UseLiftedCode(145, 0x8328AEE0)) { __imp__sub_8328AEE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AEE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A54, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE50_address);
}
PROMOTED_ENTRY(145, sub_8328AEE0, 0x8328AEE0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AEE0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AF20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A58 = int32_t(0x834A5A58);
	constexpr int32_t n_sub_832AEE60_address = int32_t(0x832AEE60);
	if (!UseLiftedCode(145, 0x8328AF20)) { __imp__sub_8328AF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AF20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A58, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE60_address);
}
PROMOTED_ENTRY(145, sub_8328AF20, 0x8328AF20) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AF20(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AF60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A5C = int32_t(0x834A5A5C);
	constexpr int32_t n_sub_832AEE70_address = int32_t(0x832AEE70);
	if (!UseLiftedCode(145, 0x8328AF60)) { __imp__sub_8328AF60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AF60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A5C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE70_address);
}
PROMOTED_ENTRY(145, sub_8328AF60, 0x8328AF60) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AF60(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AFA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A60 = int32_t(0x834A5A60);
	constexpr int32_t n_sub_832AEE80_address = int32_t(0x832AEE80);
	if (!UseLiftedCode(145, 0x8328AFA0)) { __imp__sub_8328AFA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AFA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A60, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE80_address);
}
PROMOTED_ENTRY(145, sub_8328AFA0, 0x8328AFA0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AFA0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328AFE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A64 = int32_t(0x834A5A64);
	constexpr int32_t n_sub_832AEE90_address = int32_t(0x832AEE90);
	if (!UseLiftedCode(145, 0x8328AFE0)) { __imp__sub_8328AFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AFE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A64, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEE90_address);
}
PROMOTED_ENTRY(145, sub_8328AFE0, 0x8328AFE0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328AFE0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A68 = int32_t(0x834A5A68);
	constexpr int32_t n_sub_832AEEA0_address = int32_t(0x832AEEA0);
	if (!UseLiftedCode(145, 0x8328B020)) { __imp__sub_8328B020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B020);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A68, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEEA0_address);
}
PROMOTED_ENTRY(145, sub_8328B020, 0x8328B020) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B020(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B060(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A6C = int32_t(0x834A5A6C);
	constexpr int32_t n_sub_832AEEB0_address = int32_t(0x832AEEB0);
	if (!UseLiftedCode(145, 0x8328B060)) { __imp__sub_8328B060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B060);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A6C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEEB0_address);
}
PROMOTED_ENTRY(145, sub_8328B060, 0x8328B060) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B060(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B0A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A70 = int32_t(0x834A5A70);
	constexpr int32_t n_sub_832AEEC0_address = int32_t(0x832AEEC0);
	if (!UseLiftedCode(145, 0x8328B0A0)) { __imp__sub_8328B0A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B0A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A70, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEEC0_address);
}
PROMOTED_ENTRY(145, sub_8328B0A0, 0x8328B0A0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B0A0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A90 = int32_t(0x834A5A90);
	constexpr int32_t n_sub_832AEED0_address = int32_t(0x832AEED0);
	if (!UseLiftedCode(145, 0x8328B148)) { __imp__sub_8328B148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A90, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEED0_address);
}
PROMOTED_ENTRY(145, sub_8328B148, 0x8328B148) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B148(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5A94 = int32_t(0x834A5A94);
	constexpr int32_t n_sub_832AEEE0_address = int32_t(0x832AEEE0);
	if (!UseLiftedCode(145, 0x8328B188)) { __imp__sub_8328B188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5A94, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEEE0_address);
}
PROMOTED_ENTRY(145, sub_8328B188, 0x8328B188) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B188(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B1F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5AAC = int32_t(0x834A5AAC);
	constexpr int32_t n_sub_832AEF08_address = int32_t(0x832AEF08);
	if (!UseLiftedCode(145, 0x8328B1F0)) { __imp__sub_8328B1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B1F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5AAC, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEF08_address);
}
PROMOTED_ENTRY(145, sub_8328B1F0, 0x8328B1F0) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B1F0(ctx, base); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5AB0 = int32_t(0x834A5AB0);
	constexpr int32_t n_sub_832AEF18_address = int32_t(0x832AEF18);
	if (!UseLiftedCode(145, 0x8328B230)) { __imp__sub_8328B230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5AB0, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEF18_address);
}
PROMOTED_ENTRY(145, sub_8328B230, 0x8328B230) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B230(ctx, base); }

uint64_t n_sub_8328B430(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AEF28_address = int32_t(0x832AEF28);
	if (!UseLiftedCode(145, 0x8328B430)) { ctx.r8.u64 = arg1; __imp__sub_8328B430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B430);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AEF28_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328B430, 0x8328B430) { ctx.r3.u64 = n_sub_8328B430(ctx, base, ctx.r8.u64); }

uint64_t CCharString_InitGlobalAndRegisterAtExit_8328B558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_834A5B6C = int32_t(0x834A5B6C);
	constexpr int32_t n_sub_832AEF70_address = int32_t(0x832AEF70);
	if (!UseLiftedCode(145, 0x8328B558)) { __imp__sub_8328B558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_834A5B6C, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832AEF70_address);
}
PROMOTED_ENTRY(145, sub_8328B558, 0x8328B558) { ctx.r3.u64 = CCharString_InitGlobalAndRegisterAtExit_8328B558(ctx, base); }

uint64_t n_sub_8328BA00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF088_address = int32_t(0x832AF088);
	if (!UseLiftedCode(145, 0x8328BA00)) { ctx.r8.u64 = arg1; __imp__sub_8328BA00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA00);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF088_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BA00, 0x8328BA00) { ctx.r3.u64 = n_sub_8328BA00(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA10(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF0E8_address = int32_t(0x832AF0E8);
	if (!UseLiftedCode(145, 0x8328BA10)) { ctx.r8.u64 = arg1; __imp__sub_8328BA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA10);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF0E8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BA10, 0x8328BA10) { ctx.r3.u64 = n_sub_8328BA10(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA20(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF148_address = int32_t(0x832AF148);
	if (!UseLiftedCode(145, 0x8328BA20)) { ctx.r8.u64 = arg1; __imp__sub_8328BA20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA20);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF148_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BA20, 0x8328BA20) { ctx.r3.u64 = n_sub_8328BA20(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA30(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF1A8_address = int32_t(0x832AF1A8);
	if (!UseLiftedCode(145, 0x8328BA30)) { ctx.r8.u64 = arg1; __imp__sub_8328BA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA30);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF1A8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BA30, 0x8328BA30) { ctx.r3.u64 = n_sub_8328BA30(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA78(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF1C0_address = int32_t(0x832AF1C0);
	if (!UseLiftedCode(145, 0x8328BA78)) { ctx.r8.u64 = arg1; __imp__sub_8328BA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA78);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF1C0_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BA78, 0x8328BA78) { ctx.r3.u64 = n_sub_8328BA78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BE98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF310_address = int32_t(0x832AF310);
	if (!UseLiftedCode(145, 0x8328BE98)) { ctx.r8.u64 = arg1; __imp__sub_8328BE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BE98);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF310_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BE98, 0x8328BE98) { ctx.r3.u64 = n_sub_8328BE98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF3B8_address = int32_t(0x832AF3B8);
	if (!UseLiftedCode(145, 0x8328BF18)) { ctx.r8.u64 = arg1; __imp__sub_8328BF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF18);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF3B8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BF18, 0x8328BF18) { ctx.r3.u64 = n_sub_8328BF18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF418_address = int32_t(0x832AF418);
	if (!UseLiftedCode(145, 0x8328BF28)) { ctx.r8.u64 = arg1; __imp__sub_8328BF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF28);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF418_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BF28, 0x8328BF28) { ctx.r3.u64 = n_sub_8328BF28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF470_address = int32_t(0x832AF470);
	if (!UseLiftedCode(145, 0x8328BF38)) { ctx.r8.u64 = arg1; __imp__sub_8328BF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF38);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF470_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BF38, 0x8328BF38) { ctx.r3.u64 = n_sub_8328BF38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF4C8_address = int32_t(0x832AF4C8);
	if (!UseLiftedCode(145, 0x8328BF48)) { ctx.r8.u64 = arg1; __imp__sub_8328BF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF48);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF4C8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328BF48, 0x8328BF48) { ctx.r3.u64 = n_sub_8328BF48(ctx, base, ctx.r8.u64); }

// sub_8328C0E0  [12 bytes]
uint64_t n_sub_8328C0E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834BC0A0 = int32_t(0x834BC0A0);
	if (!UseLiftedCode(145, 0x8328C0E0)) { __imp__sub_8328C0E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C0E0);
	uint64_t object = g_834BC0A0;
	uint64_t result = n_sub_82B74CC8(ctx, base);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C0E0, 0x8328C0E0) { ctx.r3.u64 = n_sub_8328C0E0(ctx, base); }

uint64_t n_sub_8328C0F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF510_address = int32_t(0x832AF510);
	if (!UseLiftedCode(145, 0x8328C0F0)) { ctx.r8.u64 = arg1; __imp__sub_8328C0F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C0F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF510_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C0F0, 0x8328C0F0) { ctx.r3.u64 = n_sub_8328C0F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C170(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF540_address = int32_t(0x832AF540);
	if (!UseLiftedCode(145, 0x8328C170)) { ctx.r8.u64 = arg1; __imp__sub_8328C170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C170);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF540_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C170, 0x8328C170) { ctx.r3.u64 = n_sub_8328C170(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C180(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF550_address = int32_t(0x832AF550);
	if (!UseLiftedCode(145, 0x8328C180)) { ctx.r8.u64 = arg1; __imp__sub_8328C180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C180);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF550_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C180, 0x8328C180) { ctx.r3.u64 = n_sub_8328C180(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF5B8_address = int32_t(0x832AF5B8);
	if (!UseLiftedCode(145, 0x8328C1C0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1C0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF5B8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C1C0, 0x8328C1C0) { ctx.r3.u64 = n_sub_8328C1C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF610_address = int32_t(0x832AF610);
	if (!UseLiftedCode(145, 0x8328C1D0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1D0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF610_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C1D0, 0x8328C1D0) { ctx.r3.u64 = n_sub_8328C1D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF650_address = int32_t(0x832AF650);
	if (!UseLiftedCode(145, 0x8328C1E0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1E0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF650_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C1E0, 0x8328C1E0) { ctx.r3.u64 = n_sub_8328C1E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF6A8_address = int32_t(0x832AF6A8);
	if (!UseLiftedCode(145, 0x8328C1F0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1F0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF6A8_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C1F0, 0x8328C1F0) { ctx.r3.u64 = n_sub_8328C1F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C200(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF700_address = int32_t(0x832AF700);
	if (!UseLiftedCode(145, 0x8328C200)) { ctx.r8.u64 = arg1; __imp__sub_8328C200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C200);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF700_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C200, 0x8328C200) { ctx.r3.u64 = n_sub_8328C200(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C210(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF758_address = int32_t(0x832AF758);
	if (!UseLiftedCode(145, 0x8328C210)) { ctx.r8.u64 = arg1; __imp__sub_8328C210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C210);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF758_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C210, 0x8328C210) { ctx.r3.u64 = n_sub_8328C210(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C8C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF890_address = int32_t(0x832AF890);
	if (!UseLiftedCode(145, 0x8328C8C8)) { ctx.r8.u64 = arg1; __imp__sub_8328C8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C8C8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF890_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328C8C8, 0x8328C8C8) { ctx.r3.u64 = n_sub_8328C8C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF9A0_address = int32_t(0x832AF9A0);
	if (!UseLiftedCode(145, 0x8328CC18)) { ctx.r8.u64 = arg1; __imp__sub_8328CC18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC18);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF9A0_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328CC18, 0x8328CC18) { ctx.r3.u64 = n_sub_8328CC18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF9B0_address = int32_t(0x832AF9B0);
	if (!UseLiftedCode(145, 0x8328CC28)) { ctx.r8.u64 = arg1; __imp__sub_8328CC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC28);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF9B0_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328CC28, 0x8328CC28) { ctx.r3.u64 = n_sub_8328CC28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF9C0_address = int32_t(0x832AF9C0);
	if (!UseLiftedCode(145, 0x8328CC38)) { ctx.r8.u64 = arg1; __imp__sub_8328CC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC38);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF9C0_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328CC38, 0x8328CC38) { ctx.r3.u64 = n_sub_8328CC38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AF9D0_address = int32_t(0x832AF9D0);
	if (!UseLiftedCode(145, 0x8328CC48)) { ctx.r8.u64 = arg1; __imp__sub_8328CC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC48);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AF9D0_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328CC48, 0x8328CC48) { ctx.r3.u64 = n_sub_8328CC48(ctx, base, ctx.r8.u64); }

uint64_t HashName_TXT_820FC14C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC14C_B_ = int32_t(0x820FC14C);
	constexpr uint32_t g_HashOf_TXT_820FC14C_B_ = 0x834BE35Cu;
	if (!UseLiftedCode(145, 0x8328E008)) { __imp__sub_8328E008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E008);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC14C_B_);
	STORE32(g_HashOf_TXT_820FC14C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E008, 0x8328E008) { ctx.r3.u64 = HashName_TXT_820FC14C_B_(ctx, base); }

uint64_t HashName_TXT_820FC160_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC160_B_ = int32_t(0x820FC160);
	constexpr uint32_t g_HashOf_TXT_820FC160_B_ = 0x834BE360u;
	if (!UseLiftedCode(145, 0x8328E040)) { __imp__sub_8328E040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E040);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC160_B_);
	STORE32(g_HashOf_TXT_820FC160_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E040, 0x8328E040) { ctx.r3.u64 = HashName_TXT_820FC160_B_(ctx, base); }

uint64_t HashName_TXT_820FC174_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC174_B_ = int32_t(0x820FC174);
	constexpr uint32_t g_HashOf_TXT_820FC174_B_ = 0x834BE364u;
	if (!UseLiftedCode(145, 0x8328E078)) { __imp__sub_8328E078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E078);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC174_B_);
	STORE32(g_HashOf_TXT_820FC174_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E078, 0x8328E078) { ctx.r3.u64 = HashName_TXT_820FC174_B_(ctx, base); }

uint64_t HashName_TXT_820FC188_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC188_B_ = int32_t(0x820FC188);
	constexpr uint32_t g_HashOf_TXT_820FC188_B_ = 0x834BE368u;
	if (!UseLiftedCode(145, 0x8328E0B0)) { __imp__sub_8328E0B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E0B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC188_B_);
	STORE32(g_HashOf_TXT_820FC188_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E0B0, 0x8328E0B0) { ctx.r3.u64 = HashName_TXT_820FC188_B_(ctx, base); }

uint64_t HashName_TXT_820FC198_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC198_B_ = int32_t(0x820FC198);
	constexpr uint32_t g_HashOf_TXT_820FC198_B_ = 0x834BE36Cu;
	if (!UseLiftedCode(145, 0x8328E0E8)) { __imp__sub_8328E0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E0E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC198_B_);
	STORE32(g_HashOf_TXT_820FC198_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E0E8, 0x8328E0E8) { ctx.r3.u64 = HashName_TXT_820FC198_B_(ctx, base); }

uint64_t HashName_TXT_820FC1A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1A8_B_ = int32_t(0x820FC1A8);
	constexpr uint32_t g_HashOf_TXT_820FC1A8_B_ = 0x834BE370u;
	if (!UseLiftedCode(145, 0x8328E120)) { __imp__sub_8328E120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E120);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1A8_B_);
	STORE32(g_HashOf_TXT_820FC1A8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E120, 0x8328E120) { ctx.r3.u64 = HashName_TXT_820FC1A8_B_(ctx, base); }

uint64_t HashName_TXT_820FC1BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1BC_B_ = int32_t(0x820FC1BC);
	constexpr uint32_t g_HashOf_TXT_820FC1BC_B_ = 0x834BE374u;
	if (!UseLiftedCode(145, 0x8328E158)) { __imp__sub_8328E158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E158);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1BC_B_);
	STORE32(g_HashOf_TXT_820FC1BC_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E158, 0x8328E158) { ctx.r3.u64 = HashName_TXT_820FC1BC_B_(ctx, base); }

uint64_t HashName_TXT_820FC1D4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1D4_B_ = int32_t(0x820FC1D4);
	constexpr uint32_t g_HashOf_TXT_820FC1D4_B_ = 0x834BE378u;
	if (!UseLiftedCode(145, 0x8328E190)) { __imp__sub_8328E190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E190);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1D4_B_);
	STORE32(g_HashOf_TXT_820FC1D4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E190, 0x8328E190) { ctx.r3.u64 = HashName_TXT_820FC1D4_B_(ctx, base); }

uint64_t HashName_TXT_820FC1E8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1E8_B_ = int32_t(0x820FC1E8);
	constexpr uint32_t g_HashOf_TXT_820FC1E8_B_ = 0x834BE37Cu;
	if (!UseLiftedCode(145, 0x8328E1C8)) { __imp__sub_8328E1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E1C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1E8_B_);
	STORE32(g_HashOf_TXT_820FC1E8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E1C8, 0x8328E1C8) { ctx.r3.u64 = HashName_TXT_820FC1E8_B_(ctx, base); }

uint64_t HashName_TXT_820FC200_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC200_B_ = int32_t(0x820FC200);
	constexpr uint32_t g_HashOf_TXT_820FC200_B_ = 0x834BE380u;
	if (!UseLiftedCode(145, 0x8328E200)) { __imp__sub_8328E200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E200);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC200_B_);
	STORE32(g_HashOf_TXT_820FC200_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E200, 0x8328E200) { ctx.r3.u64 = HashName_TXT_820FC200_B_(ctx, base); }

uint64_t HashName_TXT_820FC218_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC218_B_ = int32_t(0x820FC218);
	constexpr uint32_t g_HashOf_TXT_820FC218_B_ = 0x834BE384u;
	if (!UseLiftedCode(145, 0x8328E238)) { __imp__sub_8328E238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E238);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC218_B_);
	STORE32(g_HashOf_TXT_820FC218_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E238, 0x8328E238) { ctx.r3.u64 = HashName_TXT_820FC218_B_(ctx, base); }

uint64_t HashName_TXT_820FC234_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC234_B_ = int32_t(0x820FC234);
	constexpr uint32_t g_HashOf_TXT_820FC234_B_ = 0x834BE388u;
	if (!UseLiftedCode(145, 0x8328E270)) { __imp__sub_8328E270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E270);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC234_B_);
	STORE32(g_HashOf_TXT_820FC234_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E270, 0x8328E270) { ctx.r3.u64 = HashName_TXT_820FC234_B_(ctx, base); }

uint64_t HashName_TXT_820FC248_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC248_B_ = int32_t(0x820FC248);
	constexpr uint32_t g_HashOf_TXT_820FC248_B_ = 0x834BE38Cu;
	if (!UseLiftedCode(145, 0x8328E2A8)) { __imp__sub_8328E2A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E2A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC248_B_);
	STORE32(g_HashOf_TXT_820FC248_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E2A8, 0x8328E2A8) { ctx.r3.u64 = HashName_TXT_820FC248_B_(ctx, base); }

uint64_t HashName_TXT_820FC260_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B_ = 0x834BE390u;
	if (!UseLiftedCode(145, 0x8328E2E0)) { __imp__sub_8328E2E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E2E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E2E0, 0x8328E2E0) { ctx.r3.u64 = HashName_TXT_820FC260_B_(ctx, base); }

uint64_t HashName_TXT_820FC270_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B_ = 0x834BE394u;
	if (!UseLiftedCode(145, 0x8328E318)) { __imp__sub_8328E318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E318);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E318, 0x8328E318) { ctx.r3.u64 = HashName_TXT_820FC270_B_(ctx, base); }

uint64_t HashName_TXT_820FC27C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC27C_B_ = int32_t(0x820FC27C);
	constexpr uint32_t g_HashOf_TXT_820FC27C_B_ = 0x834BE398u;
	if (!UseLiftedCode(145, 0x8328E350)) { __imp__sub_8328E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E350);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC27C_B_);
	STORE32(g_HashOf_TXT_820FC27C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E350, 0x8328E350) { ctx.r3.u64 = HashName_TXT_820FC27C_B_(ctx, base); }

uint64_t HashName_TXT_820FC288_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC288_B_ = int32_t(0x820FC288);
	constexpr uint32_t g_HashOf_TXT_820FC288_B_ = 0x834BE39Cu;
	if (!UseLiftedCode(145, 0x8328E388)) { __imp__sub_8328E388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E388);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC288_B_);
	STORE32(g_HashOf_TXT_820FC288_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E388, 0x8328E388) { ctx.r3.u64 = HashName_TXT_820FC288_B_(ctx, base); }

uint64_t HashName_TXT_820FC294_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC294_B_ = int32_t(0x820FC294);
	constexpr uint32_t g_HashOf_TXT_820FC294_B_ = 0x834BE3A0u;
	if (!UseLiftedCode(145, 0x8328E3C0)) { __imp__sub_8328E3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E3C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC294_B_);
	STORE32(g_HashOf_TXT_820FC294_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E3C0, 0x8328E3C0) { ctx.r3.u64 = HashName_TXT_820FC294_B_(ctx, base); }

uint64_t HashName_TXT_820FC2A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2A8_B_ = int32_t(0x820FC2A8);
	constexpr uint32_t g_HashOf_TXT_820FC2A8_B_ = 0x834BE3A4u;
	if (!UseLiftedCode(145, 0x8328E3F8)) { __imp__sub_8328E3F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E3F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2A8_B_);
	STORE32(g_HashOf_TXT_820FC2A8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E3F8, 0x8328E3F8) { ctx.r3.u64 = HashName_TXT_820FC2A8_B_(ctx, base); }

uint64_t HashName_TXT_820FC2BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2BC_B_ = int32_t(0x820FC2BC);
	constexpr uint32_t g_HashOf_TXT_820FC2BC_B_ = 0x834BE3A8u;
	if (!UseLiftedCode(145, 0x8328E430)) { __imp__sub_8328E430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E430);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2BC_B_);
	STORE32(g_HashOf_TXT_820FC2BC_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E430, 0x8328E430) { ctx.r3.u64 = HashName_TXT_820FC2BC_B_(ctx, base); }

uint64_t HashName_TXT_820FC2C8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2C8_B_ = int32_t(0x820FC2C8);
	constexpr uint32_t g_HashOf_TXT_820FC2C8_B_ = 0x834BE3ACu;
	if (!UseLiftedCode(145, 0x8328E468)) { __imp__sub_8328E468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E468);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2C8_B_);
	STORE32(g_HashOf_TXT_820FC2C8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E468, 0x8328E468) { ctx.r3.u64 = HashName_TXT_820FC2C8_B_(ctx, base); }

uint64_t HashName_TXT_820FC2D4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2D4_B_ = int32_t(0x820FC2D4);
	constexpr uint32_t g_HashOf_TXT_820FC2D4_B_ = 0x834BE3B0u;
	if (!UseLiftedCode(145, 0x8328E4A0)) { __imp__sub_8328E4A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E4A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2D4_B_);
	STORE32(g_HashOf_TXT_820FC2D4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E4A0, 0x8328E4A0) { ctx.r3.u64 = HashName_TXT_820FC2D4_B_(ctx, base); }

uint64_t HashName_TXT_820FC2E4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2E4_B_ = int32_t(0x820FC2E4);
	constexpr uint32_t g_HashOf_TXT_820FC2E4_B_ = 0x834BE3B4u;
	if (!UseLiftedCode(145, 0x8328E4D8)) { __imp__sub_8328E4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2E4_B_);
	STORE32(g_HashOf_TXT_820FC2E4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E4D8, 0x8328E4D8) { ctx.r3.u64 = HashName_TXT_820FC2E4_B_(ctx, base); }

uint64_t HashName_TXT_820FC2F4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2F4_B_ = int32_t(0x820FC2F4);
	constexpr uint32_t g_HashOf_TXT_820FC2F4_B_ = 0x834BE3B8u;
	if (!UseLiftedCode(145, 0x8328E510)) { __imp__sub_8328E510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E510);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2F4_B_);
	STORE32(g_HashOf_TXT_820FC2F4_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E510, 0x8328E510) { ctx.r3.u64 = HashName_TXT_820FC2F4_B_(ctx, base); }

uint64_t HashName_TXT_820FC308_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC308_B_ = int32_t(0x820FC308);
	constexpr uint32_t g_HashOf_TXT_820FC308_B_ = 0x834BE3BCu;
	if (!UseLiftedCode(145, 0x8328E548)) { __imp__sub_8328E548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E548);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC308_B_);
	STORE32(g_HashOf_TXT_820FC308_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E548, 0x8328E548) { ctx.r3.u64 = HashName_TXT_820FC308_B_(ctx, base); }

uint64_t HashName_TXT_820FC318_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC318_B_ = int32_t(0x820FC318);
	constexpr uint32_t g_HashOf_TXT_820FC318_B_ = 0x834BE3C0u;
	if (!UseLiftedCode(145, 0x8328E580)) { __imp__sub_8328E580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E580);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC318_B_);
	STORE32(g_HashOf_TXT_820FC318_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E580, 0x8328E580) { ctx.r3.u64 = HashName_TXT_820FC318_B_(ctx, base); }

uint64_t HashName_TXT_820FC32C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC32C_B_ = int32_t(0x820FC32C);
	constexpr uint32_t g_HashOf_TXT_820FC32C_B_ = 0x834BE3C4u;
	if (!UseLiftedCode(145, 0x8328E5B8)) { __imp__sub_8328E5B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E5B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC32C_B_);
	STORE32(g_HashOf_TXT_820FC32C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E5B8, 0x8328E5B8) { ctx.r3.u64 = HashName_TXT_820FC32C_B_(ctx, base); }

uint64_t HashName_TXT_820FC344_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC344_B_ = int32_t(0x820FC344);
	constexpr uint32_t g_HashOf_TXT_820FC344_B_ = 0x834BE3C8u;
	if (!UseLiftedCode(145, 0x8328E5F0)) { __imp__sub_8328E5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E5F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC344_B_);
	STORE32(g_HashOf_TXT_820FC344_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E5F0, 0x8328E5F0) { ctx.r3.u64 = HashName_TXT_820FC344_B_(ctx, base); }

uint64_t HashName_TXT_820FC358_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC358_B_ = int32_t(0x820FC358);
	constexpr uint32_t g_HashOf_TXT_820FC358_B_ = 0x834BE3CCu;
	if (!UseLiftedCode(145, 0x8328E628)) { __imp__sub_8328E628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E628);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC358_B_);
	STORE32(g_HashOf_TXT_820FC358_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E628, 0x8328E628) { ctx.r3.u64 = HashName_TXT_820FC358_B_(ctx, base); }

uint64_t HashName_TXT_820FC368_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC368_B_ = int32_t(0x820FC368);
	constexpr uint32_t g_HashOf_TXT_820FC368_B_ = 0x834BE3D0u;
	if (!UseLiftedCode(145, 0x8328E660)) { __imp__sub_8328E660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E660);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC368_B_);
	STORE32(g_HashOf_TXT_820FC368_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E660, 0x8328E660) { ctx.r3.u64 = HashName_TXT_820FC368_B_(ctx, base); }

uint64_t HashName_TXT_820FC37C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC37C_B_ = int32_t(0x820FC37C);
	constexpr uint32_t g_HashOf_TXT_820FC37C_B_ = 0x834BE3D4u;
	if (!UseLiftedCode(145, 0x8328E698)) { __imp__sub_8328E698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E698);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC37C_B_);
	STORE32(g_HashOf_TXT_820FC37C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E698, 0x8328E698) { ctx.r3.u64 = HashName_TXT_820FC37C_B_(ctx, base); }

uint64_t HashName_TXT_820FC394_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC394_B_ = int32_t(0x820FC394);
	constexpr uint32_t g_HashOf_TXT_820FC394_B_ = 0x834BE3D8u;
	if (!UseLiftedCode(145, 0x8328E6D0)) { __imp__sub_8328E6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E6D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC394_B_);
	STORE32(g_HashOf_TXT_820FC394_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E6D0, 0x8328E6D0) { ctx.r3.u64 = HashName_TXT_820FC394_B_(ctx, base); }

uint64_t HashName_TXT_820FC39C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC39C_B_ = int32_t(0x820FC39C);
	constexpr uint32_t g_HashOf_TXT_820FC39C_B_ = 0x834BE3DCu;
	if (!UseLiftedCode(145, 0x8328E708)) { __imp__sub_8328E708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E708);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC39C_B_);
	STORE32(g_HashOf_TXT_820FC39C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E708, 0x8328E708) { ctx.r3.u64 = HashName_TXT_820FC39C_B_(ctx, base); }

uint64_t HashName_TXT_820FC3A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3A8_B_ = int32_t(0x820FC3A8);
	constexpr uint32_t g_HashOf_TXT_820FC3A8_B_ = 0x834BE3E0u;
	if (!UseLiftedCode(145, 0x8328E740)) { __imp__sub_8328E740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E740);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3A8_B_);
	STORE32(g_HashOf_TXT_820FC3A8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E740, 0x8328E740) { ctx.r3.u64 = HashName_TXT_820FC3A8_B_(ctx, base); }

uint64_t HashName_TXT_820FC3B0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3B0_B_ = int32_t(0x820FC3B0);
	constexpr uint32_t g_HashOf_TXT_820FC3B0_B_ = 0x834BE3E4u;
	if (!UseLiftedCode(145, 0x8328E778)) { __imp__sub_8328E778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E778);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3B0_B_);
	STORE32(g_HashOf_TXT_820FC3B0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E778, 0x8328E778) { ctx.r3.u64 = HashName_TXT_820FC3B0_B_(ctx, base); }

uint64_t HashName_TXT_820FC3B8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3B8_B_ = int32_t(0x820FC3B8);
	constexpr uint32_t g_HashOf_TXT_820FC3B8_B_ = 0x834BE3E8u;
	if (!UseLiftedCode(145, 0x8328E7B0)) { __imp__sub_8328E7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3B8_B_);
	STORE32(g_HashOf_TXT_820FC3B8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E7B0, 0x8328E7B0) { ctx.r3.u64 = HashName_TXT_820FC3B8_B_(ctx, base); }

uint64_t HashName_TXT_820FC3C0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3C0_B_ = int32_t(0x820FC3C0);
	constexpr uint32_t g_HashOf_TXT_820FC3C0_B_ = 0x834BE3ECu;
	if (!UseLiftedCode(145, 0x8328E7E8)) { __imp__sub_8328E7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E7E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3C0_B_);
	STORE32(g_HashOf_TXT_820FC3C0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E7E8, 0x8328E7E8) { ctx.r3.u64 = HashName_TXT_820FC3C0_B_(ctx, base); }

uint64_t HashName_TXT_820FC3C8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3C8_B_ = int32_t(0x820FC3C8);
	constexpr uint32_t g_HashOf_TXT_820FC3C8_B_ = 0x834BE3F0u;
	if (!UseLiftedCode(145, 0x8328E820)) { __imp__sub_8328E820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E820);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3C8_B_);
	STORE32(g_HashOf_TXT_820FC3C8_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E820, 0x8328E820) { ctx.r3.u64 = HashName_TXT_820FC3C8_B_(ctx, base); }

uint64_t HashName_TXT_820FC3D0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3D0_B_ = int32_t(0x820FC3D0);
	constexpr uint32_t g_HashOf_TXT_820FC3D0_B_ = 0x834BE3F4u;
	if (!UseLiftedCode(145, 0x8328E858)) { __imp__sub_8328E858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E858);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3D0_B_);
	STORE32(g_HashOf_TXT_820FC3D0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E858, 0x8328E858) { ctx.r3.u64 = HashName_TXT_820FC3D0_B_(ctx, base); }

uint64_t n_sub_8328E8B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA08_address = int32_t(0x832AFA08);
	if (!UseLiftedCode(145, 0x8328E8B0)) { ctx.r8.u64 = arg1; __imp__sub_8328E8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E8B0);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA08_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328E8B0, 0x8328E8B0) { ctx.r3.u64 = n_sub_8328E8B0(ctx, base, ctx.r8.u64); }

uint64_t HashName_TXT_820FC14C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC14C_B_ = int32_t(0x820FC14C);
	constexpr uint32_t g_HashOf_TXT_820FC14C_B__2 = 0x834BE438u;
	if (!UseLiftedCode(145, 0x8328E8C0)) { __imp__sub_8328E8C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E8C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC14C_B_);
	STORE32(g_HashOf_TXT_820FC14C_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E8C0, 0x8328E8C0) { ctx.r3.u64 = HashName_TXT_820FC14C_B__2(ctx, base); }

uint64_t HashName_TXT_820FC160_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC160_B_ = int32_t(0x820FC160);
	constexpr uint32_t g_HashOf_TXT_820FC160_B__2 = 0x834BE43Cu;
	if (!UseLiftedCode(145, 0x8328E8F8)) { __imp__sub_8328E8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E8F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC160_B_);
	STORE32(g_HashOf_TXT_820FC160_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E8F8, 0x8328E8F8) { ctx.r3.u64 = HashName_TXT_820FC160_B__2(ctx, base); }

uint64_t HashName_TXT_820FC174_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC174_B_ = int32_t(0x820FC174);
	constexpr uint32_t g_HashOf_TXT_820FC174_B__2 = 0x834BE440u;
	if (!UseLiftedCode(145, 0x8328E930)) { __imp__sub_8328E930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E930);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC174_B_);
	STORE32(g_HashOf_TXT_820FC174_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E930, 0x8328E930) { ctx.r3.u64 = HashName_TXT_820FC174_B__2(ctx, base); }

uint64_t HashName_TXT_820FC188_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC188_B_ = int32_t(0x820FC188);
	constexpr uint32_t g_HashOf_TXT_820FC188_B__2 = 0x834BE444u;
	if (!UseLiftedCode(145, 0x8328E968)) { __imp__sub_8328E968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E968);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC188_B_);
	STORE32(g_HashOf_TXT_820FC188_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E968, 0x8328E968) { ctx.r3.u64 = HashName_TXT_820FC188_B__2(ctx, base); }

uint64_t HashName_TXT_820FC198_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC198_B_ = int32_t(0x820FC198);
	constexpr uint32_t g_HashOf_TXT_820FC198_B__2 = 0x834BE448u;
	if (!UseLiftedCode(145, 0x8328E9A0)) { __imp__sub_8328E9A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E9A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC198_B_);
	STORE32(g_HashOf_TXT_820FC198_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E9A0, 0x8328E9A0) { ctx.r3.u64 = HashName_TXT_820FC198_B__2(ctx, base); }

uint64_t HashName_TXT_820FC1A8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1A8_B_ = int32_t(0x820FC1A8);
	constexpr uint32_t g_HashOf_TXT_820FC1A8_B__2 = 0x834BE44Cu;
	if (!UseLiftedCode(145, 0x8328E9D8)) { __imp__sub_8328E9D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E9D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1A8_B_);
	STORE32(g_HashOf_TXT_820FC1A8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328E9D8, 0x8328E9D8) { ctx.r3.u64 = HashName_TXT_820FC1A8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC1BC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1BC_B_ = int32_t(0x820FC1BC);
	constexpr uint32_t g_HashOf_TXT_820FC1BC_B__2 = 0x834BE450u;
	if (!UseLiftedCode(145, 0x8328EA10)) { __imp__sub_8328EA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EA10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1BC_B_);
	STORE32(g_HashOf_TXT_820FC1BC_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EA10, 0x8328EA10) { ctx.r3.u64 = HashName_TXT_820FC1BC_B__2(ctx, base); }

uint64_t HashName_TXT_820FC1D4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1D4_B_ = int32_t(0x820FC1D4);
	constexpr uint32_t g_HashOf_TXT_820FC1D4_B__2 = 0x834BE454u;
	if (!UseLiftedCode(145, 0x8328EA48)) { __imp__sub_8328EA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EA48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1D4_B_);
	STORE32(g_HashOf_TXT_820FC1D4_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EA48, 0x8328EA48) { ctx.r3.u64 = HashName_TXT_820FC1D4_B__2(ctx, base); }

uint64_t HashName_TXT_820FC1E8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1E8_B_ = int32_t(0x820FC1E8);
	constexpr uint32_t g_HashOf_TXT_820FC1E8_B__2 = 0x834BE458u;
	if (!UseLiftedCode(145, 0x8328EA80)) { __imp__sub_8328EA80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EA80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1E8_B_);
	STORE32(g_HashOf_TXT_820FC1E8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EA80, 0x8328EA80) { ctx.r3.u64 = HashName_TXT_820FC1E8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC200_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC200_B_ = int32_t(0x820FC200);
	constexpr uint32_t g_HashOf_TXT_820FC200_B__2 = 0x834BE45Cu;
	if (!UseLiftedCode(145, 0x8328EAB8)) { __imp__sub_8328EAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC200_B_);
	STORE32(g_HashOf_TXT_820FC200_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EAB8, 0x8328EAB8) { ctx.r3.u64 = HashName_TXT_820FC200_B__2(ctx, base); }

uint64_t HashName_TXT_820FC218_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC218_B_ = int32_t(0x820FC218);
	constexpr uint32_t g_HashOf_TXT_820FC218_B__2 = 0x834BE460u;
	if (!UseLiftedCode(145, 0x8328EAF0)) { __imp__sub_8328EAF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EAF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC218_B_);
	STORE32(g_HashOf_TXT_820FC218_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EAF0, 0x8328EAF0) { ctx.r3.u64 = HashName_TXT_820FC218_B__2(ctx, base); }

uint64_t HashName_TXT_820FC234_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC234_B_ = int32_t(0x820FC234);
	constexpr uint32_t g_HashOf_TXT_820FC234_B__2 = 0x834BE464u;
	if (!UseLiftedCode(145, 0x8328EB28)) { __imp__sub_8328EB28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EB28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC234_B_);
	STORE32(g_HashOf_TXT_820FC234_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EB28, 0x8328EB28) { ctx.r3.u64 = HashName_TXT_820FC234_B__2(ctx, base); }

uint64_t HashName_TXT_820FC248_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC248_B_ = int32_t(0x820FC248);
	constexpr uint32_t g_HashOf_TXT_820FC248_B__2 = 0x834BE468u;
	if (!UseLiftedCode(145, 0x8328EB60)) { __imp__sub_8328EB60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EB60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC248_B_);
	STORE32(g_HashOf_TXT_820FC248_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EB60, 0x8328EB60) { ctx.r3.u64 = HashName_TXT_820FC248_B__2(ctx, base); }

uint64_t HashName_TXT_820FC260_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B__2 = 0x834BE46Cu;
	if (!UseLiftedCode(145, 0x8328EB98)) { __imp__sub_8328EB98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EB98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EB98, 0x8328EB98) { ctx.r3.u64 = HashName_TXT_820FC260_B__2(ctx, base); }

uint64_t HashName_TXT_820FC270_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B__2 = 0x834BE470u;
	if (!UseLiftedCode(145, 0x8328EBD0)) { __imp__sub_8328EBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EBD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EBD0, 0x8328EBD0) { ctx.r3.u64 = HashName_TXT_820FC270_B__2(ctx, base); }

uint64_t HashName_TXT_820FD2BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2BC_B_ = int32_t(0x820FD2BC);
	constexpr uint32_t g_HashOf_TXT_820FD2BC_B_ = 0x834BE474u;
	if (!UseLiftedCode(145, 0x8328EC08)) { __imp__sub_8328EC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EC08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2BC_B_);
	STORE32(g_HashOf_TXT_820FD2BC_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EC08, 0x8328EC08) { ctx.r3.u64 = HashName_TXT_820FD2BC_B_(ctx, base); }

uint64_t HashName_TXT_820FD2B0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2B0_B_ = int32_t(0x820FD2B0);
	constexpr uint32_t g_HashOf_TXT_820FD2B0_B_ = 0x834BE478u;
	if (!UseLiftedCode(145, 0x8328EC40)) { __imp__sub_8328EC40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EC40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2B0_B_);
	STORE32(g_HashOf_TXT_820FD2B0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EC40, 0x8328EC40) { ctx.r3.u64 = HashName_TXT_820FD2B0_B_(ctx, base); }

uint64_t HashName_TXT_820FD2A0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2A0_B_ = int32_t(0x820FD2A0);
	constexpr uint32_t g_HashOf_TXT_820FD2A0_B_ = 0x834BE47Cu;
	if (!UseLiftedCode(145, 0x8328EC78)) { __imp__sub_8328EC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EC78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2A0_B_);
	STORE32(g_HashOf_TXT_820FD2A0_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EC78, 0x8328EC78) { ctx.r3.u64 = HashName_TXT_820FD2A0_B_(ctx, base); }

uint64_t HashName_TXT_8200103C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8200103C_B_ = int32_t(0x8200103C);
	constexpr uint32_t g_HashOf_TXT_8200103C_B_ = 0x834BE480u;
	if (!UseLiftedCode(145, 0x8328ECB0)) { __imp__sub_8328ECB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ECB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_8200103C_B_);
	STORE32(g_HashOf_TXT_8200103C_B_, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328ECB0, 0x8328ECB0) { ctx.r3.u64 = HashName_TXT_8200103C_B_(ctx, base); }

uint64_t HashName_TXT_820FC270_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B__3 = 0x834BE484u;
	if (!UseLiftedCode(145, 0x8328ECE8)) { __imp__sub_8328ECE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ECE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328ECE8, 0x8328ECE8) { ctx.r3.u64 = HashName_TXT_820FC270_B__3(ctx, base); }

uint64_t HashName_TXT_820FC260_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B__3 = 0x834BE488u;
	if (!UseLiftedCode(145, 0x8328ED20)) { __imp__sub_8328ED20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ED20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328ED20, 0x8328ED20) { ctx.r3.u64 = HashName_TXT_820FC260_B__3(ctx, base); }

uint64_t HashName_TXT_820FD2E4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2E4_B_ = int32_t(0x820FD2E4);
	constexpr uint32_t g_HashOf_TXT_820FD2E4_B_ = 0x834BE48Cu;
	if (!UseLiftedCode(145, 0x8328ED58)) { __imp__sub_8328ED58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ED58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2E4_B_);
	STORE32(g_HashOf_TXT_820FD2E4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328ED58, 0x8328ED58) { ctx.r3.u64 = HashName_TXT_820FD2E4_B_(ctx, base); }

uint64_t HashName_TXT_820FD2EC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2EC_B_ = int32_t(0x820FD2EC);
	constexpr uint32_t g_HashOf_TXT_820FD2EC_B_ = 0x834BE490u;
	if (!UseLiftedCode(145, 0x8328ED88)) { __imp__sub_8328ED88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ED88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2EC_B_);
	STORE32(g_HashOf_TXT_820FD2EC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328ED88, 0x8328ED88) { ctx.r3.u64 = HashName_TXT_820FD2EC_B_(ctx, base); }

uint64_t HashName_TXT_820FD2F8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD2F8_B_ = int32_t(0x820FD2F8);
	constexpr uint32_t g_HashOf_TXT_820FD2F8_B_ = 0x834BE494u;
	if (!UseLiftedCode(145, 0x8328EDB8)) { __imp__sub_8328EDB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EDB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD2F8_B_);
	STORE32(g_HashOf_TXT_820FD2F8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EDB8, 0x8328EDB8) { ctx.r3.u64 = HashName_TXT_820FD2F8_B_(ctx, base); }

uint64_t HashName_TXT_820FD300_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD300_B_ = int32_t(0x820FD300);
	constexpr uint32_t g_HashOf_TXT_820FD300_B_ = 0x834BE498u;
	if (!UseLiftedCode(145, 0x8328EDE8)) { __imp__sub_8328EDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EDE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD300_B_);
	STORE32(g_HashOf_TXT_820FD300_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EDE8, 0x8328EDE8) { ctx.r3.u64 = HashName_TXT_820FD300_B_(ctx, base); }

uint64_t HashName_TXT_820FD30C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FD30C_B_ = int32_t(0x820FD30C);
	constexpr uint32_t g_HashOf_TXT_820FD30C_B_ = 0x834BE49Cu;
	if (!UseLiftedCode(145, 0x8328EE18)) { __imp__sub_8328EE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EE18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FD30C_B_);
	STORE32(g_HashOf_TXT_820FD30C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EE18, 0x8328EE18) { ctx.r3.u64 = HashName_TXT_820FD30C_B_(ctx, base); }

uint64_t HashName_TXT_82000D08_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000D08_B_ = int32_t(0x82000D08);
	constexpr uint32_t g_HashOf_TXT_82000D08_B_ = 0x834BE4A0u;
	if (!UseLiftedCode(145, 0x8328EE48)) { __imp__sub_8328EE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EE48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_82000D08_B_);
	STORE32(g_HashOf_TXT_82000D08_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EE48, 0x8328EE48) { ctx.r3.u64 = HashName_TXT_82000D08_B_(ctx, base); }

uint64_t HashName_TXT_820FC14C_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC14C_B_ = int32_t(0x820FC14C);
	constexpr uint32_t g_HashOf_TXT_820FC14C_B__3 = 0x834BE4A4u;
	if (!UseLiftedCode(145, 0x8328EE78)) { __imp__sub_8328EE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EE78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC14C_B_);
	STORE32(g_HashOf_TXT_820FC14C_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EE78, 0x8328EE78) { ctx.r3.u64 = HashName_TXT_820FC14C_B__3(ctx, base); }

uint64_t HashName_TXT_820FC160_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC160_B_ = int32_t(0x820FC160);
	constexpr uint32_t g_HashOf_TXT_820FC160_B__3 = 0x834BE4A8u;
	if (!UseLiftedCode(145, 0x8328EEB0)) { __imp__sub_8328EEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EEB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC160_B_);
	STORE32(g_HashOf_TXT_820FC160_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EEB0, 0x8328EEB0) { ctx.r3.u64 = HashName_TXT_820FC160_B__3(ctx, base); }

uint64_t HashName_TXT_820FC174_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC174_B_ = int32_t(0x820FC174);
	constexpr uint32_t g_HashOf_TXT_820FC174_B__3 = 0x834BE4ACu;
	if (!UseLiftedCode(145, 0x8328EEE8)) { __imp__sub_8328EEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EEE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC174_B_);
	STORE32(g_HashOf_TXT_820FC174_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EEE8, 0x8328EEE8) { ctx.r3.u64 = HashName_TXT_820FC174_B__3(ctx, base); }

uint64_t HashName_TXT_820FC188_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC188_B_ = int32_t(0x820FC188);
	constexpr uint32_t g_HashOf_TXT_820FC188_B__3 = 0x834BE4B0u;
	if (!UseLiftedCode(145, 0x8328EF20)) { __imp__sub_8328EF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EF20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC188_B_);
	STORE32(g_HashOf_TXT_820FC188_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EF20, 0x8328EF20) { ctx.r3.u64 = HashName_TXT_820FC188_B__3(ctx, base); }

uint64_t HashName_TXT_820FC198_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC198_B_ = int32_t(0x820FC198);
	constexpr uint32_t g_HashOf_TXT_820FC198_B__3 = 0x834BE4B4u;
	if (!UseLiftedCode(145, 0x8328EF58)) { __imp__sub_8328EF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EF58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC198_B_);
	STORE32(g_HashOf_TXT_820FC198_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EF58, 0x8328EF58) { ctx.r3.u64 = HashName_TXT_820FC198_B__3(ctx, base); }

uint64_t HashName_TXT_820FC1A8_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1A8_B_ = int32_t(0x820FC1A8);
	constexpr uint32_t g_HashOf_TXT_820FC1A8_B__3 = 0x834BE4B8u;
	if (!UseLiftedCode(145, 0x8328EF90)) { __imp__sub_8328EF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EF90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1A8_B_);
	STORE32(g_HashOf_TXT_820FC1A8_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EF90, 0x8328EF90) { ctx.r3.u64 = HashName_TXT_820FC1A8_B__3(ctx, base); }

uint64_t HashName_TXT_820FC1BC_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1BC_B_ = int32_t(0x820FC1BC);
	constexpr uint32_t g_HashOf_TXT_820FC1BC_B__3 = 0x834BE4BCu;
	if (!UseLiftedCode(145, 0x8328EFC8)) { __imp__sub_8328EFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328EFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1BC_B_);
	STORE32(g_HashOf_TXT_820FC1BC_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328EFC8, 0x8328EFC8) { ctx.r3.u64 = HashName_TXT_820FC1BC_B__3(ctx, base); }

uint64_t HashName_TXT_820FC1D4_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1D4_B_ = int32_t(0x820FC1D4);
	constexpr uint32_t g_HashOf_TXT_820FC1D4_B__3 = 0x834BE4C0u;
	if (!UseLiftedCode(145, 0x8328F000)) { __imp__sub_8328F000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F000);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1D4_B_);
	STORE32(g_HashOf_TXT_820FC1D4_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F000, 0x8328F000) { ctx.r3.u64 = HashName_TXT_820FC1D4_B__3(ctx, base); }

uint64_t HashName_TXT_820FC1E8_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1E8_B_ = int32_t(0x820FC1E8);
	constexpr uint32_t g_HashOf_TXT_820FC1E8_B__3 = 0x834BE4C4u;
	if (!UseLiftedCode(145, 0x8328F038)) { __imp__sub_8328F038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F038);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1E8_B_);
	STORE32(g_HashOf_TXT_820FC1E8_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F038, 0x8328F038) { ctx.r3.u64 = HashName_TXT_820FC1E8_B__3(ctx, base); }

uint64_t HashName_TXT_820FC200_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC200_B_ = int32_t(0x820FC200);
	constexpr uint32_t g_HashOf_TXT_820FC200_B__3 = 0x834BE4C8u;
	if (!UseLiftedCode(145, 0x8328F070)) { __imp__sub_8328F070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F070);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC200_B_);
	STORE32(g_HashOf_TXT_820FC200_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F070, 0x8328F070) { ctx.r3.u64 = HashName_TXT_820FC200_B__3(ctx, base); }

uint64_t HashName_TXT_820FC218_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC218_B_ = int32_t(0x820FC218);
	constexpr uint32_t g_HashOf_TXT_820FC218_B__3 = 0x834BE4CCu;
	if (!UseLiftedCode(145, 0x8328F0A8)) { __imp__sub_8328F0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F0A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC218_B_);
	STORE32(g_HashOf_TXT_820FC218_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F0A8, 0x8328F0A8) { ctx.r3.u64 = HashName_TXT_820FC218_B__3(ctx, base); }

uint64_t HashName_TXT_820FC234_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC234_B_ = int32_t(0x820FC234);
	constexpr uint32_t g_HashOf_TXT_820FC234_B__3 = 0x834BE4D0u;
	if (!UseLiftedCode(145, 0x8328F0E0)) { __imp__sub_8328F0E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F0E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC234_B_);
	STORE32(g_HashOf_TXT_820FC234_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F0E0, 0x8328F0E0) { ctx.r3.u64 = HashName_TXT_820FC234_B__3(ctx, base); }

uint64_t HashName_TXT_820FC248_B__3(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC248_B_ = int32_t(0x820FC248);
	constexpr uint32_t g_HashOf_TXT_820FC248_B__3 = 0x834BE4D4u;
	if (!UseLiftedCode(145, 0x8328F118)) { __imp__sub_8328F118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F118);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC248_B_);
	STORE32(g_HashOf_TXT_820FC248_B__3, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F118, 0x8328F118) { ctx.r3.u64 = HashName_TXT_820FC248_B__3(ctx, base); }

uint64_t HashName_TXT_820FC260_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B__4 = 0x834BE4D8u;
	if (!UseLiftedCode(145, 0x8328F150)) { __imp__sub_8328F150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F150);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F150, 0x8328F150) { ctx.r3.u64 = HashName_TXT_820FC260_B__4(ctx, base); }

uint64_t HashName_TXT_820FC270_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B__4 = 0x834BE4DCu;
	if (!UseLiftedCode(145, 0x8328F188)) { __imp__sub_8328F188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F188);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F188, 0x8328F188) { ctx.r3.u64 = HashName_TXT_820FC270_B__4(ctx, base); }

uint64_t HashName_TXT_82000E40_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000E40_B_ = int32_t(0x82000E40);
	constexpr uint32_t g_HashOf_TXT_82000E40_B__2 = 0x834BE520u;
	if (!UseLiftedCode(145, 0x8328F1F8)) { __imp__sub_8328F1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F1F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_82000E40_B_);
	STORE32(g_HashOf_TXT_82000E40_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F1F8, 0x8328F1F8) { ctx.r3.u64 = HashName_TXT_82000E40_B__2(ctx, base); }

uint64_t HashName_TXT_820FDAAC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FDAAC_B_ = int32_t(0x820FDAAC);
	constexpr uint32_t g_HashOf_TXT_820FDAAC_B_ = 0x834BE524u;
	if (!UseLiftedCode(145, 0x8328F228)) { __imp__sub_8328F228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F228);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FDAAC_B_);
	STORE32(g_HashOf_TXT_820FDAAC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F228, 0x8328F228) { ctx.r3.u64 = HashName_TXT_820FDAAC_B_(ctx, base); }

uint64_t HashName_TXT_820FC14C_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC14C_B_ = int32_t(0x820FC14C);
	constexpr uint32_t g_HashOf_TXT_820FC14C_B__4 = 0x834BE530u;
	if (!UseLiftedCode(145, 0x8328F2C8)) { __imp__sub_8328F2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F2C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC14C_B_);
	STORE32(g_HashOf_TXT_820FC14C_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F2C8, 0x8328F2C8) { ctx.r3.u64 = HashName_TXT_820FC14C_B__4(ctx, base); }

uint64_t HashName_TXT_820FC160_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC160_B_ = int32_t(0x820FC160);
	constexpr uint32_t g_HashOf_TXT_820FC160_B__4 = 0x834BE534u;
	if (!UseLiftedCode(145, 0x8328F300)) { __imp__sub_8328F300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F300);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC160_B_);
	STORE32(g_HashOf_TXT_820FC160_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F300, 0x8328F300) { ctx.r3.u64 = HashName_TXT_820FC160_B__4(ctx, base); }

uint64_t HashName_TXT_820FC174_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC174_B_ = int32_t(0x820FC174);
	constexpr uint32_t g_HashOf_TXT_820FC174_B__4 = 0x834BE538u;
	if (!UseLiftedCode(145, 0x8328F338)) { __imp__sub_8328F338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F338);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC174_B_);
	STORE32(g_HashOf_TXT_820FC174_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F338, 0x8328F338) { ctx.r3.u64 = HashName_TXT_820FC174_B__4(ctx, base); }

uint64_t HashName_TXT_820FC188_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC188_B_ = int32_t(0x820FC188);
	constexpr uint32_t g_HashOf_TXT_820FC188_B__4 = 0x834BE53Cu;
	if (!UseLiftedCode(145, 0x8328F370)) { __imp__sub_8328F370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F370);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC188_B_);
	STORE32(g_HashOf_TXT_820FC188_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F370, 0x8328F370) { ctx.r3.u64 = HashName_TXT_820FC188_B__4(ctx, base); }

uint64_t HashName_TXT_820FC198_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC198_B_ = int32_t(0x820FC198);
	constexpr uint32_t g_HashOf_TXT_820FC198_B__4 = 0x834BE540u;
	if (!UseLiftedCode(145, 0x8328F3A8)) { __imp__sub_8328F3A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F3A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC198_B_);
	STORE32(g_HashOf_TXT_820FC198_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F3A8, 0x8328F3A8) { ctx.r3.u64 = HashName_TXT_820FC198_B__4(ctx, base); }

uint64_t HashName_TXT_820FC1A8_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1A8_B_ = int32_t(0x820FC1A8);
	constexpr uint32_t g_HashOf_TXT_820FC1A8_B__4 = 0x834BE544u;
	if (!UseLiftedCode(145, 0x8328F3E0)) { __imp__sub_8328F3E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F3E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1A8_B_);
	STORE32(g_HashOf_TXT_820FC1A8_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F3E0, 0x8328F3E0) { ctx.r3.u64 = HashName_TXT_820FC1A8_B__4(ctx, base); }

uint64_t HashName_TXT_820FC1BC_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1BC_B_ = int32_t(0x820FC1BC);
	constexpr uint32_t g_HashOf_TXT_820FC1BC_B__4 = 0x834BE548u;
	if (!UseLiftedCode(145, 0x8328F418)) { __imp__sub_8328F418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F418);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1BC_B_);
	STORE32(g_HashOf_TXT_820FC1BC_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F418, 0x8328F418) { ctx.r3.u64 = HashName_TXT_820FC1BC_B__4(ctx, base); }

uint64_t HashName_TXT_820FC1D4_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1D4_B_ = int32_t(0x820FC1D4);
	constexpr uint32_t g_HashOf_TXT_820FC1D4_B__4 = 0x834BE54Cu;
	if (!UseLiftedCode(145, 0x8328F450)) { __imp__sub_8328F450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F450);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1D4_B_);
	STORE32(g_HashOf_TXT_820FC1D4_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F450, 0x8328F450) { ctx.r3.u64 = HashName_TXT_820FC1D4_B__4(ctx, base); }

uint64_t HashName_TXT_820FC1E8_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1E8_B_ = int32_t(0x820FC1E8);
	constexpr uint32_t g_HashOf_TXT_820FC1E8_B__4 = 0x834BE550u;
	if (!UseLiftedCode(145, 0x8328F488)) { __imp__sub_8328F488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F488);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1E8_B_);
	STORE32(g_HashOf_TXT_820FC1E8_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F488, 0x8328F488) { ctx.r3.u64 = HashName_TXT_820FC1E8_B__4(ctx, base); }

uint64_t HashName_TXT_820FC200_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC200_B_ = int32_t(0x820FC200);
	constexpr uint32_t g_HashOf_TXT_820FC200_B__4 = 0x834BE554u;
	if (!UseLiftedCode(145, 0x8328F4C0)) { __imp__sub_8328F4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F4C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC200_B_);
	STORE32(g_HashOf_TXT_820FC200_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F4C0, 0x8328F4C0) { ctx.r3.u64 = HashName_TXT_820FC200_B__4(ctx, base); }

uint64_t HashName_TXT_820FC218_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC218_B_ = int32_t(0x820FC218);
	constexpr uint32_t g_HashOf_TXT_820FC218_B__4 = 0x834BE558u;
	if (!UseLiftedCode(145, 0x8328F4F8)) { __imp__sub_8328F4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F4F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC218_B_);
	STORE32(g_HashOf_TXT_820FC218_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F4F8, 0x8328F4F8) { ctx.r3.u64 = HashName_TXT_820FC218_B__4(ctx, base); }

uint64_t HashName_TXT_820FC234_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC234_B_ = int32_t(0x820FC234);
	constexpr uint32_t g_HashOf_TXT_820FC234_B__4 = 0x834BE55Cu;
	if (!UseLiftedCode(145, 0x8328F530)) { __imp__sub_8328F530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F530);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC234_B_);
	STORE32(g_HashOf_TXT_820FC234_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F530, 0x8328F530) { ctx.r3.u64 = HashName_TXT_820FC234_B__4(ctx, base); }

uint64_t HashName_TXT_820FC248_B__4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC248_B_ = int32_t(0x820FC248);
	constexpr uint32_t g_HashOf_TXT_820FC248_B__4 = 0x834BE560u;
	if (!UseLiftedCode(145, 0x8328F568)) { __imp__sub_8328F568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F568);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC248_B_);
	STORE32(g_HashOf_TXT_820FC248_B__4, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F568, 0x8328F568) { ctx.r3.u64 = HashName_TXT_820FC248_B__4(ctx, base); }

uint64_t HashName_TXT_820FC260_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B__5 = 0x834BE564u;
	if (!UseLiftedCode(145, 0x8328F5A0)) { __imp__sub_8328F5A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F5A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F5A0, 0x8328F5A0) { ctx.r3.u64 = HashName_TXT_820FC260_B__5(ctx, base); }

uint64_t HashName_TXT_820FC270_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B__5 = 0x834BE568u;
	if (!UseLiftedCode(145, 0x8328F5D8)) { __imp__sub_8328F5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F5D8, 0x8328F5D8) { ctx.r3.u64 = HashName_TXT_820FC270_B__5(ctx, base); }

uint64_t HashName_TXT_820FC14C_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC14C_B_ = int32_t(0x820FC14C);
	constexpr uint32_t g_HashOf_TXT_820FC14C_B__5 = 0x834BE56Cu;
	if (!UseLiftedCode(145, 0x8328F610)) { __imp__sub_8328F610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F610);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC14C_B_);
	STORE32(g_HashOf_TXT_820FC14C_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F610, 0x8328F610) { ctx.r3.u64 = HashName_TXT_820FC14C_B__5(ctx, base); }

uint64_t HashName_TXT_820FC160_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC160_B_ = int32_t(0x820FC160);
	constexpr uint32_t g_HashOf_TXT_820FC160_B__5 = 0x834BE570u;
	if (!UseLiftedCode(145, 0x8328F648)) { __imp__sub_8328F648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F648);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC160_B_);
	STORE32(g_HashOf_TXT_820FC160_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F648, 0x8328F648) { ctx.r3.u64 = HashName_TXT_820FC160_B__5(ctx, base); }

uint64_t HashName_TXT_820FC174_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC174_B_ = int32_t(0x820FC174);
	constexpr uint32_t g_HashOf_TXT_820FC174_B__5 = 0x834BE574u;
	if (!UseLiftedCode(145, 0x8328F680)) { __imp__sub_8328F680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F680);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC174_B_);
	STORE32(g_HashOf_TXT_820FC174_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F680, 0x8328F680) { ctx.r3.u64 = HashName_TXT_820FC174_B__5(ctx, base); }

uint64_t HashName_TXT_820FC188_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC188_B_ = int32_t(0x820FC188);
	constexpr uint32_t g_HashOf_TXT_820FC188_B__5 = 0x834BE578u;
	if (!UseLiftedCode(145, 0x8328F6B8)) { __imp__sub_8328F6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F6B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC188_B_);
	STORE32(g_HashOf_TXT_820FC188_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F6B8, 0x8328F6B8) { ctx.r3.u64 = HashName_TXT_820FC188_B__5(ctx, base); }

uint64_t HashName_TXT_820FC198_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC198_B_ = int32_t(0x820FC198);
	constexpr uint32_t g_HashOf_TXT_820FC198_B__5 = 0x834BE57Cu;
	if (!UseLiftedCode(145, 0x8328F6F0)) { __imp__sub_8328F6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F6F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC198_B_);
	STORE32(g_HashOf_TXT_820FC198_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F6F0, 0x8328F6F0) { ctx.r3.u64 = HashName_TXT_820FC198_B__5(ctx, base); }

uint64_t HashName_TXT_820FC1A8_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1A8_B_ = int32_t(0x820FC1A8);
	constexpr uint32_t g_HashOf_TXT_820FC1A8_B__5 = 0x834BE580u;
	if (!UseLiftedCode(145, 0x8328F728)) { __imp__sub_8328F728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F728);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1A8_B_);
	STORE32(g_HashOf_TXT_820FC1A8_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F728, 0x8328F728) { ctx.r3.u64 = HashName_TXT_820FC1A8_B__5(ctx, base); }

uint64_t HashName_TXT_820FC1BC_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1BC_B_ = int32_t(0x820FC1BC);
	constexpr uint32_t g_HashOf_TXT_820FC1BC_B__5 = 0x834BE584u;
	if (!UseLiftedCode(145, 0x8328F760)) { __imp__sub_8328F760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F760);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1BC_B_);
	STORE32(g_HashOf_TXT_820FC1BC_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F760, 0x8328F760) { ctx.r3.u64 = HashName_TXT_820FC1BC_B__5(ctx, base); }

uint64_t HashName_TXT_820FC1D4_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1D4_B_ = int32_t(0x820FC1D4);
	constexpr uint32_t g_HashOf_TXT_820FC1D4_B__5 = 0x834BE588u;
	if (!UseLiftedCode(145, 0x8328F798)) { __imp__sub_8328F798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F798);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1D4_B_);
	STORE32(g_HashOf_TXT_820FC1D4_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F798, 0x8328F798) { ctx.r3.u64 = HashName_TXT_820FC1D4_B__5(ctx, base); }

uint64_t HashName_TXT_820FC1E8_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC1E8_B_ = int32_t(0x820FC1E8);
	constexpr uint32_t g_HashOf_TXT_820FC1E8_B__5 = 0x834BE58Cu;
	if (!UseLiftedCode(145, 0x8328F7D0)) { __imp__sub_8328F7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F7D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC1E8_B_);
	STORE32(g_HashOf_TXT_820FC1E8_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F7D0, 0x8328F7D0) { ctx.r3.u64 = HashName_TXT_820FC1E8_B__5(ctx, base); }

uint64_t HashName_TXT_820FC200_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC200_B_ = int32_t(0x820FC200);
	constexpr uint32_t g_HashOf_TXT_820FC200_B__5 = 0x834BE590u;
	if (!UseLiftedCode(145, 0x8328F808)) { __imp__sub_8328F808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F808);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC200_B_);
	STORE32(g_HashOf_TXT_820FC200_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F808, 0x8328F808) { ctx.r3.u64 = HashName_TXT_820FC200_B__5(ctx, base); }

uint64_t HashName_TXT_820FC218_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC218_B_ = int32_t(0x820FC218);
	constexpr uint32_t g_HashOf_TXT_820FC218_B__5 = 0x834BE594u;
	if (!UseLiftedCode(145, 0x8328F840)) { __imp__sub_8328F840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F840);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC218_B_);
	STORE32(g_HashOf_TXT_820FC218_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F840, 0x8328F840) { ctx.r3.u64 = HashName_TXT_820FC218_B__5(ctx, base); }

uint64_t HashName_TXT_820FC234_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC234_B_ = int32_t(0x820FC234);
	constexpr uint32_t g_HashOf_TXT_820FC234_B__5 = 0x834BE598u;
	if (!UseLiftedCode(145, 0x8328F878)) { __imp__sub_8328F878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F878);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC234_B_);
	STORE32(g_HashOf_TXT_820FC234_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F878, 0x8328F878) { ctx.r3.u64 = HashName_TXT_820FC234_B__5(ctx, base); }

uint64_t HashName_TXT_820FC248_B__5(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC248_B_ = int32_t(0x820FC248);
	constexpr uint32_t g_HashOf_TXT_820FC248_B__5 = 0x834BE59Cu;
	if (!UseLiftedCode(145, 0x8328F8B0)) { __imp__sub_8328F8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F8B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC248_B_);
	STORE32(g_HashOf_TXT_820FC248_B__5, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F8B0, 0x8328F8B0) { ctx.r3.u64 = HashName_TXT_820FC248_B__5(ctx, base); }

uint64_t HashName_TXT_820FC260_B__6(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC260_B_ = int32_t(0x820FC260);
	constexpr uint32_t g_HashOf_TXT_820FC260_B__6 = 0x834BE5A0u;
	if (!UseLiftedCode(145, 0x8328F8E8)) { __imp__sub_8328F8E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F8E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC260_B_);
	STORE32(g_HashOf_TXT_820FC260_B__6, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F8E8, 0x8328F8E8) { ctx.r3.u64 = HashName_TXT_820FC260_B__6(ctx, base); }

uint64_t HashName_TXT_820FC270_B__6(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC270_B_ = int32_t(0x820FC270);
	constexpr uint32_t g_HashOf_TXT_820FC270_B__6 = 0x834BE5A4u;
	if (!UseLiftedCode(145, 0x8328F920)) { __imp__sub_8328F920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F920);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC270_B_);
	STORE32(g_HashOf_TXT_820FC270_B__6, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F920, 0x8328F920) { ctx.r3.u64 = HashName_TXT_820FC270_B__6(ctx, base); }

uint64_t n_sub_8328F958(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA10_address = int32_t(0x832AFA10);
	if (!UseLiftedCode(145, 0x8328F958)) { ctx.r8.u64 = arg1; __imp__sub_8328F958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F958);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA10_address, arg1);
}
PROMOTED_ENTRY(145, sub_8328F958, 0x8328F958) { ctx.r3.u64 = n_sub_8328F958(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFA20(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA20_address = int32_t(0x832AFA20);
	if (!UseLiftedCode(145, 0x8328F968)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328F968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F968);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA20_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328F968, 0x8328F968) { ctx.r3.u64 = String_Equals_832AFA20(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFA30(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA30_address = int32_t(0x832AFA30);
	if (!UseLiftedCode(145, 0x8328F978)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328F978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F978);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA30_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328F978, 0x8328F978) { ctx.r3.u64 = String_Equals_832AFA30(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFA40(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA40_address = int32_t(0x832AFA40);
	if (!UseLiftedCode(145, 0x8328F988)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328F988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F988);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA40_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328F988, 0x8328F988) { ctx.r3.u64 = String_Equals_832AFA40(ctx, base, ctx.r8.u64); }

uint64_t HashName_TXT_820FC27C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC27C_B_ = int32_t(0x820FC27C);
	constexpr uint32_t g_HashOf_TXT_820FC27C_B__2 = 0x834BE5D0u;
	if (!UseLiftedCode(145, 0x8328F998)) { __imp__sub_8328F998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC27C_B_);
	STORE32(g_HashOf_TXT_820FC27C_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F998, 0x8328F998) { ctx.r3.u64 = HashName_TXT_820FC27C_B__2(ctx, base); }

uint64_t HashName_TXT_820FC288_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC288_B_ = int32_t(0x820FC288);
	constexpr uint32_t g_HashOf_TXT_820FC288_B__2 = 0x834BE5D4u;
	if (!UseLiftedCode(145, 0x8328F9D0)) { __imp__sub_8328F9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F9D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC288_B_);
	STORE32(g_HashOf_TXT_820FC288_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328F9D0, 0x8328F9D0) { ctx.r3.u64 = HashName_TXT_820FC288_B__2(ctx, base); }

uint64_t HashName_TXT_820FC294_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC294_B_ = int32_t(0x820FC294);
	constexpr uint32_t g_HashOf_TXT_820FC294_B__2 = 0x834BE5D8u;
	if (!UseLiftedCode(145, 0x8328FA08)) { __imp__sub_8328FA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FA08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC294_B_);
	STORE32(g_HashOf_TXT_820FC294_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FA08, 0x8328FA08) { ctx.r3.u64 = HashName_TXT_820FC294_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2A8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2A8_B_ = int32_t(0x820FC2A8);
	constexpr uint32_t g_HashOf_TXT_820FC2A8_B__2 = 0x834BE5DCu;
	if (!UseLiftedCode(145, 0x8328FA40)) { __imp__sub_8328FA40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FA40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2A8_B_);
	STORE32(g_HashOf_TXT_820FC2A8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FA40, 0x8328FA40) { ctx.r3.u64 = HashName_TXT_820FC2A8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2BC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2BC_B_ = int32_t(0x820FC2BC);
	constexpr uint32_t g_HashOf_TXT_820FC2BC_B__2 = 0x834BE5E0u;
	if (!UseLiftedCode(145, 0x8328FA78)) { __imp__sub_8328FA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FA78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2BC_B_);
	STORE32(g_HashOf_TXT_820FC2BC_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FA78, 0x8328FA78) { ctx.r3.u64 = HashName_TXT_820FC2BC_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2C8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2C8_B_ = int32_t(0x820FC2C8);
	constexpr uint32_t g_HashOf_TXT_820FC2C8_B__2 = 0x834BE5E4u;
	if (!UseLiftedCode(145, 0x8328FAB0)) { __imp__sub_8328FAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FAB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2C8_B_);
	STORE32(g_HashOf_TXT_820FC2C8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FAB0, 0x8328FAB0) { ctx.r3.u64 = HashName_TXT_820FC2C8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2D4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2D4_B_ = int32_t(0x820FC2D4);
	constexpr uint32_t g_HashOf_TXT_820FC2D4_B__2 = 0x834BE5E8u;
	if (!UseLiftedCode(145, 0x8328FAE8)) { __imp__sub_8328FAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FAE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2D4_B_);
	STORE32(g_HashOf_TXT_820FC2D4_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FAE8, 0x8328FAE8) { ctx.r3.u64 = HashName_TXT_820FC2D4_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2E4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2E4_B_ = int32_t(0x820FC2E4);
	constexpr uint32_t g_HashOf_TXT_820FC2E4_B__2 = 0x834BE5ECu;
	if (!UseLiftedCode(145, 0x8328FB20)) { __imp__sub_8328FB20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FB20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2E4_B_);
	STORE32(g_HashOf_TXT_820FC2E4_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FB20, 0x8328FB20) { ctx.r3.u64 = HashName_TXT_820FC2E4_B__2(ctx, base); }

uint64_t HashName_TXT_820FC2F4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC2F4_B_ = int32_t(0x820FC2F4);
	constexpr uint32_t g_HashOf_TXT_820FC2F4_B__2 = 0x834BE5F0u;
	if (!UseLiftedCode(145, 0x8328FB58)) { __imp__sub_8328FB58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FB58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC2F4_B_);
	STORE32(g_HashOf_TXT_820FC2F4_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FB58, 0x8328FB58) { ctx.r3.u64 = HashName_TXT_820FC2F4_B__2(ctx, base); }

uint64_t HashName_TXT_820FC308_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC308_B_ = int32_t(0x820FC308);
	constexpr uint32_t g_HashOf_TXT_820FC308_B__2 = 0x834BE5F4u;
	if (!UseLiftedCode(145, 0x8328FB90)) { __imp__sub_8328FB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FB90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC308_B_);
	STORE32(g_HashOf_TXT_820FC308_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FB90, 0x8328FB90) { ctx.r3.u64 = HashName_TXT_820FC308_B__2(ctx, base); }

uint64_t HashName_TXT_820FC318_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC318_B_ = int32_t(0x820FC318);
	constexpr uint32_t g_HashOf_TXT_820FC318_B__2 = 0x834BE5F8u;
	if (!UseLiftedCode(145, 0x8328FBC8)) { __imp__sub_8328FBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC318_B_);
	STORE32(g_HashOf_TXT_820FC318_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FBC8, 0x8328FBC8) { ctx.r3.u64 = HashName_TXT_820FC318_B__2(ctx, base); }

uint64_t HashName_TXT_820FC32C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC32C_B_ = int32_t(0x820FC32C);
	constexpr uint32_t g_HashOf_TXT_820FC32C_B__2 = 0x834BE5FCu;
	if (!UseLiftedCode(145, 0x8328FC00)) { __imp__sub_8328FC00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FC00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC32C_B_);
	STORE32(g_HashOf_TXT_820FC32C_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FC00, 0x8328FC00) { ctx.r3.u64 = HashName_TXT_820FC32C_B__2(ctx, base); }

uint64_t HashName_TXT_820FC344_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC344_B_ = int32_t(0x820FC344);
	constexpr uint32_t g_HashOf_TXT_820FC344_B__2 = 0x834BE600u;
	if (!UseLiftedCode(145, 0x8328FC38)) { __imp__sub_8328FC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FC38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC344_B_);
	STORE32(g_HashOf_TXT_820FC344_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FC38, 0x8328FC38) { ctx.r3.u64 = HashName_TXT_820FC344_B__2(ctx, base); }

uint64_t HashName_TXT_820FC358_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC358_B_ = int32_t(0x820FC358);
	constexpr uint32_t g_HashOf_TXT_820FC358_B__2 = 0x834BE604u;
	if (!UseLiftedCode(145, 0x8328FC70)) { __imp__sub_8328FC70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FC70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC358_B_);
	STORE32(g_HashOf_TXT_820FC358_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FC70, 0x8328FC70) { ctx.r3.u64 = HashName_TXT_820FC358_B__2(ctx, base); }

uint64_t HashName_TXT_820FC368_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC368_B_ = int32_t(0x820FC368);
	constexpr uint32_t g_HashOf_TXT_820FC368_B__2 = 0x834BE608u;
	if (!UseLiftedCode(145, 0x8328FCA8)) { __imp__sub_8328FCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FCA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC368_B_);
	STORE32(g_HashOf_TXT_820FC368_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FCA8, 0x8328FCA8) { ctx.r3.u64 = HashName_TXT_820FC368_B__2(ctx, base); }

uint64_t HashName_TXT_820FC37C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC37C_B_ = int32_t(0x820FC37C);
	constexpr uint32_t g_HashOf_TXT_820FC37C_B__2 = 0x834BE60Cu;
	if (!UseLiftedCode(145, 0x8328FCE0)) { __imp__sub_8328FCE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FCE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC37C_B_);
	STORE32(g_HashOf_TXT_820FC37C_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FCE0, 0x8328FCE0) { ctx.r3.u64 = HashName_TXT_820FC37C_B__2(ctx, base); }

uint64_t HashName_TXT_820FC394_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC394_B_ = int32_t(0x820FC394);
	constexpr uint32_t g_HashOf_TXT_820FC394_B__2 = 0x834BE610u;
	if (!UseLiftedCode(145, 0x8328FD18)) { __imp__sub_8328FD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FD18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC394_B_);
	STORE32(g_HashOf_TXT_820FC394_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FD18, 0x8328FD18) { ctx.r3.u64 = HashName_TXT_820FC394_B__2(ctx, base); }

uint64_t HashName_TXT_820FC39C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC39C_B_ = int32_t(0x820FC39C);
	constexpr uint32_t g_HashOf_TXT_820FC39C_B__2 = 0x834BE614u;
	if (!UseLiftedCode(145, 0x8328FD50)) { __imp__sub_8328FD50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FD50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC39C_B_);
	STORE32(g_HashOf_TXT_820FC39C_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FD50, 0x8328FD50) { ctx.r3.u64 = HashName_TXT_820FC39C_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3A8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3A8_B_ = int32_t(0x820FC3A8);
	constexpr uint32_t g_HashOf_TXT_820FC3A8_B__2 = 0x834BE618u;
	if (!UseLiftedCode(145, 0x8328FD88)) { __imp__sub_8328FD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FD88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3A8_B_);
	STORE32(g_HashOf_TXT_820FC3A8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FD88, 0x8328FD88) { ctx.r3.u64 = HashName_TXT_820FC3A8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3B0_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3B0_B_ = int32_t(0x820FC3B0);
	constexpr uint32_t g_HashOf_TXT_820FC3B0_B__2 = 0x834BE61Cu;
	if (!UseLiftedCode(145, 0x8328FDC0)) { __imp__sub_8328FDC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FDC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3B0_B_);
	STORE32(g_HashOf_TXT_820FC3B0_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FDC0, 0x8328FDC0) { ctx.r3.u64 = HashName_TXT_820FC3B0_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3B8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3B8_B_ = int32_t(0x820FC3B8);
	constexpr uint32_t g_HashOf_TXT_820FC3B8_B__2 = 0x834BE620u;
	if (!UseLiftedCode(145, 0x8328FDF8)) { __imp__sub_8328FDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FDF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3B8_B_);
	STORE32(g_HashOf_TXT_820FC3B8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FDF8, 0x8328FDF8) { ctx.r3.u64 = HashName_TXT_820FC3B8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3C0_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3C0_B_ = int32_t(0x820FC3C0);
	constexpr uint32_t g_HashOf_TXT_820FC3C0_B__2 = 0x834BE624u;
	if (!UseLiftedCode(145, 0x8328FE30)) { __imp__sub_8328FE30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FE30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3C0_B_);
	STORE32(g_HashOf_TXT_820FC3C0_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FE30, 0x8328FE30) { ctx.r3.u64 = HashName_TXT_820FC3C0_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3C8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3C8_B_ = int32_t(0x820FC3C8);
	constexpr uint32_t g_HashOf_TXT_820FC3C8_B__2 = 0x834BE628u;
	if (!UseLiftedCode(145, 0x8328FE68)) { __imp__sub_8328FE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FE68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3C8_B_);
	STORE32(g_HashOf_TXT_820FC3C8_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FE68, 0x8328FE68) { ctx.r3.u64 = HashName_TXT_820FC3C8_B__2(ctx, base); }

uint64_t HashName_TXT_820FC3D0_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820FC3D0_B_ = int32_t(0x820FC3D0);
	constexpr uint32_t g_HashOf_TXT_820FC3D0_B__2 = 0x834BE62Cu;
	if (!UseLiftedCode(145, 0x8328FEA0)) { __imp__sub_8328FEA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FEA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = String_HashLimited100(ctx, base, str_TXT_820FC3D0_B_);
	STORE32(g_HashOf_TXT_820FC3D0_B__2, uint32_t((uint32_t)hash & 0x7FFFFFFF));
	return hash;
}
PROMOTED_ENTRY(145, sub_8328FEA0, 0x8328FEA0) { ctx.r3.u64 = HashName_TXT_820FC3D0_B__2(ctx, base); }

uint64_t String_Equals_832AFA98(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFA98_address = int32_t(0x832AFA98);
	if (!UseLiftedCode(145, 0x8328FED8)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FED8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFA98_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FED8, 0x8328FED8) { ctx.r3.u64 = String_Equals_832AFA98(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFAB8(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFAB8_address = int32_t(0x832AFAB8);
	if (!UseLiftedCode(145, 0x8328FEE8)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FEE8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFAB8_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FEE8, 0x8328FEE8) { ctx.r3.u64 = String_Equals_832AFAB8(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFAA8(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFAA8_address = int32_t(0x832AFAA8);
	if (!UseLiftedCode(145, 0x8328FEF8)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FEF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FEF8);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFAA8_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FEF8, 0x8328FEF8) { ctx.r3.u64 = String_Equals_832AFAA8(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFB20(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFB20_address = int32_t(0x832AFB20);
	if (!UseLiftedCode(145, 0x8328FF08)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF08);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFB20_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FF08, 0x8328FF08) { ctx.r3.u64 = String_Equals_832AFB20(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFAC8(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFAC8_address = int32_t(0x832AFAC8);
	if (!UseLiftedCode(145, 0x8328FF18)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF18);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFAC8_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FF18, 0x8328FF18) { ctx.r3.u64 = String_Equals_832AFAC8(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFB30(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFB30_address = int32_t(0x832AFB30);
	if (!UseLiftedCode(145, 0x8328FF28)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF28);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFB30_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FF28, 0x8328FF28) { ctx.r3.u64 = String_Equals_832AFB30(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFB40(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFB40_address = int32_t(0x832AFB40);
	if (!UseLiftedCode(145, 0x8328FF38)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF38);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFB40_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FF38, 0x8328FF38) { ctx.r3.u64 = String_Equals_832AFB40(ctx, base, ctx.r8.u64); }

uint64_t String_Equals_832AFC38(CpuState& ctx, uint8_t* base, uint64_t TXT_82000D08_L_) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832AFC38_address = int32_t(0x832AFC38);
	if (!UseLiftedCode(145, 0x8328FF80)) { ctx.r8.u64 = TXT_82000D08_L_; __imp__sub_8328FF80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF80);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832AFC38_address, TXT_82000D08_L_);
}
PROMOTED_ENTRY(145, sub_8328FF80, 0x8328FF80) { ctx.r3.u64 = String_Equals_832AFC38(ctx, base, ctx.r8.u64); }
