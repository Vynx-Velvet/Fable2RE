// Start-up initialisers of global objects (they register property and definition names) at
// 0x8327xxxx, as readable C++.
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

uint64_t HashName_TXT_820A2C0C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__43 = 0x8349CD70u;
	if (!UseLiftedCode(144, 0x83270030)) { __imp__sub_83270030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270030);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270030, 0x83270030) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__43 = 0x8349CD74u;
	if (!UseLiftedCode(144, 0x83270068)) { __imp__sub_83270068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270068);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270068, 0x83270068) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__44 = 0x8349CD78u;
	if (!UseLiftedCode(144, 0x832700A0)) { __imp__sub_832700A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832700A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832700A0, 0x832700A0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__43 = 0x8349CD7Cu;
	if (!UseLiftedCode(144, 0x832700D8)) { __imp__sub_832700D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832700D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832700D8, 0x832700D8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__43 = 0x8349CD80u;
	if (!UseLiftedCode(144, 0x83270110)) { __imp__sub_83270110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270110);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270110, 0x83270110) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__43 = 0x8349CD84u;
	if (!UseLiftedCode(144, 0x83270148)) { __imp__sub_83270148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270148);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270148, 0x83270148) { ctx.r3.u64 = HashName_TXT_820A2C74_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__43 = 0x8349CD88u;
	if (!UseLiftedCode(144, 0x83270180)) { __imp__sub_83270180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270180);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270180, 0x83270180) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__43 = 0x8349CD8Cu;
	if (!UseLiftedCode(144, 0x832701B8)) { __imp__sub_832701B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832701B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832701B8, 0x832701B8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__43 = 0x8349CD90u;
	if (!UseLiftedCode(144, 0x832701F0)) { __imp__sub_832701F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832701F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832701F0, 0x832701F0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__46 = 0x8349CD94u;
	if (!UseLiftedCode(144, 0x83270228)) { __imp__sub_83270228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270228);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270228, 0x83270228) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__43 = 0x8349CD98u;
	if (!UseLiftedCode(144, 0x83270260)) { __imp__sub_83270260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270260);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270260, 0x83270260) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__43 = 0x8349CD9Cu;
	if (!UseLiftedCode(144, 0x83270298)) { __imp__sub_83270298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270298);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270298, 0x83270298) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__43 = 0x8349CDA0u;
	if (!UseLiftedCode(144, 0x832702D0)) { __imp__sub_832702D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832702D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832702D0, 0x832702D0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__43(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__43 = 0x8349CDA4u;
	if (!UseLiftedCode(144, 0x83270308)) { __imp__sub_83270308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270308);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270308, 0x83270308) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__44 = 0x8349CDA8u;
	if (!UseLiftedCode(144, 0x83270340)) { __imp__sub_83270340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270340);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270340, 0x83270340) { ctx.r3.u64 = HashName_TXT_820A2D24_B__44(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__43 = 0x8349CDACu;
	if (!UseLiftedCode(144, 0x83270378)) { __imp__sub_83270378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270378);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270378, 0x83270378) { ctx.r3.u64 = HashName_TXT_820A2D30_B__43(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__43 = 0x8349CDB0u;
	if (!UseLiftedCode(144, 0x832703B0)) { __imp__sub_832703B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832703B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832703B0, 0x832703B0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__43(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__43 = 0x8349CDB4u;
	if (!UseLiftedCode(144, 0x832703E8)) { __imp__sub_832703E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832703E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832703E8, 0x832703E8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__43(ctx, base); }

uint64_t Construct_TXT_8349CDB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CDB8_G_ = int32_t(0x8349CDB8);
	constexpr int32_t str_TXT_820E4940_B_ = int32_t(0x820E4940);
	constexpr int32_t Destroy_TXT_8349CDB8_G__address = int32_t(0x832A8AA0);
	if (!UseLiftedCode(144, 0x83270420)) { __imp__sub_83270420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270420);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CDB8_G_, str_TXT_820E4940_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CDB8_G__address);
}
PROMOTED_ENTRY(144, sub_83270420, 0x83270420) { ctx.r3.u64 = Construct_TXT_8349CDB8_G_(ctx, base); }

uint64_t Construct_TXT_8349CDC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CDC0_G_ = int32_t(0x8349CDC0);
	constexpr int32_t str_TXT_820E496C_B_ = int32_t(0x820E496C);
	constexpr int32_t Destroy_TXT_8349CDC0_G__address = int32_t(0x832A8AC0);
	if (!UseLiftedCode(144, 0x832704A0)) { __imp__sub_832704A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832704A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CDC0_G_, str_TXT_820E496C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CDC0_G__address);
}
PROMOTED_ENTRY(144, sub_832704A0, 0x832704A0) { ctx.r3.u64 = Construct_TXT_8349CDC0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__44 = 0x8349CDC4u;
	if (!UseLiftedCode(144, 0x832704E0)) { __imp__sub_832704E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832704E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832704E0, 0x832704E0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__44(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__46 = 0x8349CDC8u;
	if (!UseLiftedCode(144, 0x83270518)) { __imp__sub_83270518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270518);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270518, 0x83270518) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__46(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__45 = 0x8349CDCCu;
	if (!UseLiftedCode(144, 0x83270550)) { __imp__sub_83270550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270550);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270550, 0x83270550) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__44 = 0x8349CDD0u;
	if (!UseLiftedCode(144, 0x83270588)) { __imp__sub_83270588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270588);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270588, 0x83270588) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__44 = 0x8349CDD4u;
	if (!UseLiftedCode(144, 0x832705C0)) { __imp__sub_832705C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832705C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832705C0, 0x832705C0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__45 = 0x8349CDD8u;
	if (!UseLiftedCode(144, 0x832705F8)) { __imp__sub_832705F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832705F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832705F8, 0x832705F8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__44 = 0x8349CDDCu;
	if (!UseLiftedCode(144, 0x83270630)) { __imp__sub_83270630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270630);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270630, 0x83270630) { ctx.r3.u64 = HashName_TXT_820A2C44_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__44 = 0x8349CDE0u;
	if (!UseLiftedCode(144, 0x83270668)) { __imp__sub_83270668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270668, 0x83270668) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__44 = 0x8349CDE4u;
	if (!UseLiftedCode(144, 0x832706A0)) { __imp__sub_832706A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832706A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832706A0, 0x832706A0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__44(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__44 = 0x8349CDE8u;
	if (!UseLiftedCode(144, 0x832706D8)) { __imp__sub_832706D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832706D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832706D8, 0x832706D8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__44 = 0x8349CDECu;
	if (!UseLiftedCode(144, 0x83270710)) { __imp__sub_83270710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270710);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270710, 0x83270710) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__44 = 0x8349CDF0u;
	if (!UseLiftedCode(144, 0x83270748)) { __imp__sub_83270748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270748);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270748, 0x83270748) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__47 = 0x8349CDF4u;
	if (!UseLiftedCode(144, 0x83270780)) { __imp__sub_83270780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270780);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270780, 0x83270780) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__44 = 0x8349CDF8u;
	if (!UseLiftedCode(144, 0x832707B8)) { __imp__sub_832707B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832707B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832707B8, 0x832707B8) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__44 = 0x8349CDFCu;
	if (!UseLiftedCode(144, 0x832707F0)) { __imp__sub_832707F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832707F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832707F0, 0x832707F0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__44 = 0x8349CE00u;
	if (!UseLiftedCode(144, 0x83270828)) { __imp__sub_83270828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270828);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270828, 0x83270828) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__44(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__44 = 0x8349CE04u;
	if (!UseLiftedCode(144, 0x83270860)) { __imp__sub_83270860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270860);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270860, 0x83270860) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__45 = 0x8349CE08u;
	if (!UseLiftedCode(144, 0x83270898)) { __imp__sub_83270898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270898);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270898, 0x83270898) { ctx.r3.u64 = HashName_TXT_820A2D24_B__45(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__44 = 0x8349CE0Cu;
	if (!UseLiftedCode(144, 0x832708D0)) { __imp__sub_832708D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832708D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832708D0, 0x832708D0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__44(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__44 = 0x8349CE10u;
	if (!UseLiftedCode(144, 0x83270908)) { __imp__sub_83270908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270908);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270908, 0x83270908) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__44(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__44 = 0x8349CE14u;
	if (!UseLiftedCode(144, 0x83270940)) { __imp__sub_83270940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270940);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270940, 0x83270940) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__44(ctx, base); }

uint64_t Construct_TXT_8349CE18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE18_G_ = int32_t(0x8349CE18);
	constexpr int32_t str_TXT_820DCFD4_B_ = int32_t(0x820DCFD4);
	constexpr int32_t Destroy_TXT_8349CE18_G__address = int32_t(0x832A8AD0);
	if (!UseLiftedCode(144, 0x83270978)) { __imp__sub_83270978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270978);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE18_G_, str_TXT_820DCFD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE18_G__address);
}
PROMOTED_ENTRY(144, sub_83270978, 0x83270978) { ctx.r3.u64 = Construct_TXT_8349CE18_G_(ctx, base); }

uint64_t Construct_TXT_8349CE1C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE1C_G_ = int32_t(0x8349CE1C);
	constexpr int32_t str_TXT_820E49EC_B_ = int32_t(0x820E49EC);
	constexpr int32_t Destroy_TXT_8349CE1C_G__address = int32_t(0x832A8AE0);
	if (!UseLiftedCode(144, 0x832709B8)) { __imp__sub_832709B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832709B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE1C_G_, str_TXT_820E49EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE1C_G__address);
}
PROMOTED_ENTRY(144, sub_832709B8, 0x832709B8) { ctx.r3.u64 = Construct_TXT_8349CE1C_G_(ctx, base); }

uint64_t Construct_TXT_8349CE20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE20_G_ = int32_t(0x8349CE20);
	constexpr int32_t str_TXT_820E49F4_B_ = int32_t(0x820E49F4);
	constexpr int32_t Destroy_TXT_8349CE20_G__address = int32_t(0x832A8AF0);
	if (!UseLiftedCode(144, 0x832709F8)) { __imp__sub_832709F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832709F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE20_G_, str_TXT_820E49F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE20_G__address);
}
PROMOTED_ENTRY(144, sub_832709F8, 0x832709F8) { ctx.r3.u64 = Construct_TXT_8349CE20_G_(ctx, base); }

uint64_t Construct_TXT_8349CE24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE24_G_ = int32_t(0x8349CE24);
	constexpr int32_t str_TXT_820E4A00_B_ = int32_t(0x820E4A00);
	constexpr int32_t Destroy_TXT_8349CE24_G__address = int32_t(0x832A8B00);
	if (!UseLiftedCode(144, 0x83270A38)) { __imp__sub_83270A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270A38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE24_G_, str_TXT_820E4A00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE24_G__address);
}
PROMOTED_ENTRY(144, sub_83270A38, 0x83270A38) { ctx.r3.u64 = Construct_TXT_8349CE24_G_(ctx, base); }

uint64_t Construct_TXT_8349CE28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE28_G_ = int32_t(0x8349CE28);
	constexpr int32_t str_TXT_820E4A0C_B_ = int32_t(0x820E4A0C);
	constexpr int32_t Destroy_TXT_8349CE28_G__address = int32_t(0x832A8B10);
	if (!UseLiftedCode(144, 0x83270A78)) { __imp__sub_83270A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270A78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE28_G_, str_TXT_820E4A0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE28_G__address);
}
PROMOTED_ENTRY(144, sub_83270A78, 0x83270A78) { ctx.r3.u64 = Construct_TXT_8349CE28_G_(ctx, base); }

uint64_t Construct_TXT_8349CE2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE2C_G_ = int32_t(0x8349CE2C);
	constexpr int32_t str_TXT_820E4A18_B_ = int32_t(0x820E4A18);
	constexpr int32_t Destroy_TXT_8349CE2C_G__address = int32_t(0x832A8B20);
	if (!UseLiftedCode(144, 0x83270AB8)) { __imp__sub_83270AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270AB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE2C_G_, str_TXT_820E4A18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE2C_G__address);
}
PROMOTED_ENTRY(144, sub_83270AB8, 0x83270AB8) { ctx.r3.u64 = Construct_TXT_8349CE2C_G_(ctx, base); }

uint64_t Construct_TXT_8349CE30_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE30_G_ = int32_t(0x8349CE30);
	constexpr int32_t str_TXT_820E4A24_B_ = int32_t(0x820E4A24);
	constexpr int32_t Destroy_TXT_8349CE30_G__address = int32_t(0x832A8B30);
	if (!UseLiftedCode(144, 0x83270AF8)) { __imp__sub_83270AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270AF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE30_G_, str_TXT_820E4A24_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE30_G__address);
}
PROMOTED_ENTRY(144, sub_83270AF8, 0x83270AF8) { ctx.r3.u64 = Construct_TXT_8349CE30_G_(ctx, base); }

uint64_t Construct_TXT_8349CE34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE34_G_ = int32_t(0x8349CE34);
	constexpr int32_t str_TXT_820E4A30_B_ = int32_t(0x820E4A30);
	constexpr int32_t Destroy_TXT_8349CE34_G__address = int32_t(0x832A8B40);
	if (!UseLiftedCode(144, 0x83270B38)) { __imp__sub_83270B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270B38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE34_G_, str_TXT_820E4A30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE34_G__address);
}
PROMOTED_ENTRY(144, sub_83270B38, 0x83270B38) { ctx.r3.u64 = Construct_TXT_8349CE34_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__45 = 0x8349CE38u;
	if (!UseLiftedCode(144, 0x83270B78)) { __imp__sub_83270B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270B78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270B78, 0x83270B78) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__45(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__47 = 0x8349CE3Cu;
	if (!UseLiftedCode(144, 0x83270BB0)) { __imp__sub_83270BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270BB0, 0x83270BB0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__47(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__46 = 0x8349CE40u;
	if (!UseLiftedCode(144, 0x83270BE8)) { __imp__sub_83270BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270BE8, 0x83270BE8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__45 = 0x8349CE44u;
	if (!UseLiftedCode(144, 0x83270C20)) { __imp__sub_83270C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270C20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270C20, 0x83270C20) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__45 = 0x8349CE48u;
	if (!UseLiftedCode(144, 0x83270C58)) { __imp__sub_83270C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270C58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270C58, 0x83270C58) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__46 = 0x8349CE4Cu;
	if (!UseLiftedCode(144, 0x83270C90)) { __imp__sub_83270C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270C90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270C90, 0x83270C90) { ctx.r3.u64 = HashName_TXT_820A2C34_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__45 = 0x8349CE50u;
	if (!UseLiftedCode(144, 0x83270CC8)) { __imp__sub_83270CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270CC8, 0x83270CC8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__45 = 0x8349CE54u;
	if (!UseLiftedCode(144, 0x83270D00)) { __imp__sub_83270D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270D00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270D00, 0x83270D00) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__45 = 0x8349CE58u;
	if (!UseLiftedCode(144, 0x83270D38)) { __imp__sub_83270D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270D38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270D38, 0x83270D38) { ctx.r3.u64 = HashName_TXT_820A2C74_B__45(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__45 = 0x8349CE5Cu;
	if (!UseLiftedCode(144, 0x83270D70)) { __imp__sub_83270D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270D70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270D70, 0x83270D70) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__45 = 0x8349CE60u;
	if (!UseLiftedCode(144, 0x83270DA8)) { __imp__sub_83270DA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270DA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270DA8, 0x83270DA8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__45 = 0x8349CE64u;
	if (!UseLiftedCode(144, 0x83270DE0)) { __imp__sub_83270DE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270DE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270DE0, 0x83270DE0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__48 = 0x8349CE68u;
	if (!UseLiftedCode(144, 0x83270E18)) { __imp__sub_83270E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270E18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270E18, 0x83270E18) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__45 = 0x8349CE6Cu;
	if (!UseLiftedCode(144, 0x83270E50)) { __imp__sub_83270E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270E50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270E50, 0x83270E50) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__45 = 0x8349CE70u;
	if (!UseLiftedCode(144, 0x83270E88)) { __imp__sub_83270E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270E88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270E88, 0x83270E88) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__45 = 0x8349CE74u;
	if (!UseLiftedCode(144, 0x83270EC0)) { __imp__sub_83270EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270EC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270EC0, 0x83270EC0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__45(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__45 = 0x8349CE78u;
	if (!UseLiftedCode(144, 0x83270EF8)) { __imp__sub_83270EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270EF8, 0x83270EF8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__46 = 0x8349CE7Cu;
	if (!UseLiftedCode(144, 0x83270F30)) { __imp__sub_83270F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270F30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270F30, 0x83270F30) { ctx.r3.u64 = HashName_TXT_820A2D24_B__46(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__45 = 0x8349CE80u;
	if (!UseLiftedCode(144, 0x83270F68)) { __imp__sub_83270F68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270F68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270F68, 0x83270F68) { ctx.r3.u64 = HashName_TXT_820A2D30_B__45(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__45 = 0x8349CE84u;
	if (!UseLiftedCode(144, 0x83270FA0)) { __imp__sub_83270FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270FA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270FA0, 0x83270FA0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__45(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__45 = 0x8349CE88u;
	if (!UseLiftedCode(144, 0x83270FD8)) { __imp__sub_83270FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270FD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83270FD8, 0x83270FD8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__45(ctx, base); }

uint64_t Construct_TXT_8349CE90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE90_G_ = int32_t(0x8349CE90);
	constexpr int32_t str_TXT_820E4B60_B_ = int32_t(0x820E4B60);
	constexpr int32_t Destroy_TXT_8349CE90_G__address = int32_t(0x832A8B60);
	if (!UseLiftedCode(144, 0x83271050)) { __imp__sub_83271050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271050);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE90_G_, str_TXT_820E4B60_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE90_G__address);
}
PROMOTED_ENTRY(144, sub_83271050, 0x83271050) { ctx.r3.u64 = Construct_TXT_8349CE90_G_(ctx, base); }

uint64_t Construct_TXT_8349CE94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE94_G_ = int32_t(0x8349CE94);
	constexpr int32_t str_TXT_820E4B78_B_ = int32_t(0x820E4B78);
	constexpr int32_t Destroy_TXT_8349CE94_G__address = int32_t(0x832A8B70);
	if (!UseLiftedCode(144, 0x83271090)) { __imp__sub_83271090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271090);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE94_G_, str_TXT_820E4B78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE94_G__address);
}
PROMOTED_ENTRY(144, sub_83271090, 0x83271090) { ctx.r3.u64 = Construct_TXT_8349CE94_G_(ctx, base); }

uint64_t Construct_TXT_8349CE98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE98_G_ = int32_t(0x8349CE98);
	constexpr int32_t str_TXT_820E4BA0_B_ = int32_t(0x820E4BA0);
	constexpr int32_t Destroy_TXT_8349CE98_G__address = int32_t(0x832A8B80);
	if (!UseLiftedCode(144, 0x832710D0)) { __imp__sub_832710D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832710D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE98_G_, str_TXT_820E4BA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE98_G__address);
}
PROMOTED_ENTRY(144, sub_832710D0, 0x832710D0) { ctx.r3.u64 = Construct_TXT_8349CE98_G_(ctx, base); }

uint64_t Construct_TXT_8349CE9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CE9C_G_ = int32_t(0x8349CE9C);
	constexpr int32_t str_TXT_820E4BCC_B_ = int32_t(0x820E4BCC);
	constexpr int32_t Destroy_TXT_8349CE9C_G__address = int32_t(0x832A8B90);
	if (!UseLiftedCode(144, 0x83271110)) { __imp__sub_83271110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271110);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE9C_G_, str_TXT_820E4BCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CE9C_G__address);
}
PROMOTED_ENTRY(144, sub_83271110, 0x83271110) { ctx.r3.u64 = Construct_TXT_8349CE9C_G_(ctx, base); }

uint64_t Construct_TXT_8349CEA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEA0_G_ = int32_t(0x8349CEA0);
	constexpr int32_t str_TXT_820E4C04_B_ = int32_t(0x820E4C04);
	constexpr int32_t Destroy_TXT_8349CEA0_G__address = int32_t(0x832A8BA0);
	if (!UseLiftedCode(144, 0x83271150)) { __imp__sub_83271150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271150);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA0_G_, str_TXT_820E4C04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEA0_G__address);
}
PROMOTED_ENTRY(144, sub_83271150, 0x83271150) { ctx.r3.u64 = Construct_TXT_8349CEA0_G_(ctx, base); }

uint64_t Construct_TXT_8349CEA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEA4_G_ = int32_t(0x8349CEA4);
	constexpr int32_t str_TXT_820E4C38_B_ = int32_t(0x820E4C38);
	constexpr int32_t Destroy_TXT_8349CEA4_G__address = int32_t(0x832A8BB0);
	if (!UseLiftedCode(144, 0x83271190)) { __imp__sub_83271190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271190);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA4_G_, str_TXT_820E4C38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEA4_G__address);
}
PROMOTED_ENTRY(144, sub_83271190, 0x83271190) { ctx.r3.u64 = Construct_TXT_8349CEA4_G_(ctx, base); }

uint64_t Construct_TXT_8349CEA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEA8_G_ = int32_t(0x8349CEA8);
	constexpr int32_t str_TXT_820E4C38_B_ = int32_t(0x820E4C78);
	constexpr int32_t Destroy_TXT_8349CEA8_G__address = int32_t(0x832A8BC0);
	if (!UseLiftedCode(144, 0x832711D0)) { __imp__sub_832711D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832711D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA8_G_, str_TXT_820E4C38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEA8_G__address);
}
PROMOTED_ENTRY(144, sub_832711D0, 0x832711D0) { ctx.r3.u64 = Construct_TXT_8349CEA8_G_(ctx, base); }

uint64_t Construct_TXT_8349CEAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEAC_G_ = int32_t(0x8349CEAC);
	constexpr int32_t str_TXT_820E4CB8_B_ = int32_t(0x820E4CB8);
	constexpr int32_t Destroy_TXT_8349CEAC_G__address = int32_t(0x832A8BD0);
	if (!UseLiftedCode(144, 0x83271210)) { __imp__sub_83271210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271210);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEAC_G_, str_TXT_820E4CB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEAC_G__address);
}
PROMOTED_ENTRY(144, sub_83271210, 0x83271210) { ctx.r3.u64 = Construct_TXT_8349CEAC_G_(ctx, base); }

uint64_t Construct_TXT_8349CEB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEB0_G_ = int32_t(0x8349CEB0);
	constexpr int32_t str_TXT_820E4CB8_B_ = int32_t(0x820E4CF0);
	constexpr int32_t Destroy_TXT_8349CEB0_G__address = int32_t(0x832A8BE0);
	if (!UseLiftedCode(144, 0x83271250)) { __imp__sub_83271250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271250);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB0_G_, str_TXT_820E4CB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEB0_G__address);
}
PROMOTED_ENTRY(144, sub_83271250, 0x83271250) { ctx.r3.u64 = Construct_TXT_8349CEB0_G_(ctx, base); }

uint64_t Construct_TXT_8349CEB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEB4_G_ = int32_t(0x8349CEB4);
	constexpr int32_t str_TXT_820E4CB8_B_ = int32_t(0x820E4D38);
	constexpr int32_t Destroy_TXT_8349CEB4_G__address = int32_t(0x832A8BF0);
	if (!UseLiftedCode(144, 0x83271290)) { __imp__sub_83271290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271290);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB4_G_, str_TXT_820E4CB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEB4_G__address);
}
PROMOTED_ENTRY(144, sub_83271290, 0x83271290) { ctx.r3.u64 = Construct_TXT_8349CEB4_G_(ctx, base); }

uint64_t Construct_TXT_8349CEB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEB8_G_ = int32_t(0x8349CEB8);
	constexpr int32_t str_TXT_820E4CB8_B_ = int32_t(0x820E4D80);
	constexpr int32_t Destroy_TXT_8349CEB8_G__address = int32_t(0x832A8C00);
	if (!UseLiftedCode(144, 0x832712D0)) { __imp__sub_832712D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832712D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB8_G_, str_TXT_820E4CB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEB8_G__address);
}
PROMOTED_ENTRY(144, sub_832712D0, 0x832712D0) { ctx.r3.u64 = Construct_TXT_8349CEB8_G_(ctx, base); }

uint64_t Construct_TXT_8349CEBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEBC_G_ = int32_t(0x8349CEBC);
	constexpr int32_t str_TXT_820E4DC4_B_ = int32_t(0x820E4DC4);
	constexpr int32_t Destroy_TXT_8349CEBC_G__address = int32_t(0x832A8C10);
	if (!UseLiftedCode(144, 0x83271310)) { __imp__sub_83271310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271310);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEBC_G_, str_TXT_820E4DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEBC_G__address);
}
PROMOTED_ENTRY(144, sub_83271310, 0x83271310) { ctx.r3.u64 = Construct_TXT_8349CEBC_G_(ctx, base); }

uint64_t Construct_TXT_8349CEC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEC0_G_ = int32_t(0x8349CEC0);
	constexpr int32_t str_TXT_820E4DC4_B_ = int32_t(0x820E4DF8);
	constexpr int32_t Destroy_TXT_8349CEC0_G__address = int32_t(0x832A8C20);
	if (!UseLiftedCode(144, 0x83271350)) { __imp__sub_83271350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271350);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC0_G_, str_TXT_820E4DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEC0_G__address);
}
PROMOTED_ENTRY(144, sub_83271350, 0x83271350) { ctx.r3.u64 = Construct_TXT_8349CEC0_G_(ctx, base); }

uint64_t Construct_TXT_8349CEC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEC4_G_ = int32_t(0x8349CEC4);
	constexpr int32_t str_TXT_820E4DC4_B_ = int32_t(0x820E4E30);
	constexpr int32_t Destroy_TXT_8349CEC4_G__address = int32_t(0x832A8C30);
	if (!UseLiftedCode(144, 0x83271390)) { __imp__sub_83271390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271390);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC4_G_, str_TXT_820E4DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEC4_G__address);
}
PROMOTED_ENTRY(144, sub_83271390, 0x83271390) { ctx.r3.u64 = Construct_TXT_8349CEC4_G_(ctx, base); }

uint64_t Construct_TXT_8349CEC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEC8_G_ = int32_t(0x8349CEC8);
	constexpr int32_t str_TXT_820E4DC4_B_ = int32_t(0x820E4E70);
	constexpr int32_t Destroy_TXT_8349CEC8_G__address = int32_t(0x832A8C40);
	if (!UseLiftedCode(144, 0x832713D0)) { __imp__sub_832713D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832713D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC8_G_, str_TXT_820E4DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEC8_G__address);
}
PROMOTED_ENTRY(144, sub_832713D0, 0x832713D0) { ctx.r3.u64 = Construct_TXT_8349CEC8_G_(ctx, base); }

uint64_t Construct_TXT_8349CECC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CECC_G_ = int32_t(0x8349CECC);
	constexpr int32_t str_TXT_820E4EB4_B_ = int32_t(0x820E4EB4);
	constexpr int32_t Destroy_TXT_8349CECC_G__address = int32_t(0x832A8C50);
	if (!UseLiftedCode(144, 0x83271410)) { __imp__sub_83271410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CECC_G_, str_TXT_820E4EB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CECC_G__address);
}
PROMOTED_ENTRY(144, sub_83271410, 0x83271410) { ctx.r3.u64 = Construct_TXT_8349CECC_G_(ctx, base); }

uint64_t Construct_TXT_8349CED0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CED0_G_ = int32_t(0x8349CED0);
	constexpr int32_t str_TXT_820E4EB4_B_ = int32_t(0x820E4EE8);
	constexpr int32_t Destroy_TXT_8349CED0_G__address = int32_t(0x832A8C60);
	if (!UseLiftedCode(144, 0x83271450)) { __imp__sub_83271450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED0_G_, str_TXT_820E4EB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CED0_G__address);
}
PROMOTED_ENTRY(144, sub_83271450, 0x83271450) { ctx.r3.u64 = Construct_TXT_8349CED0_G_(ctx, base); }

uint64_t Construct_TXT_8349CED4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CED4_G_ = int32_t(0x8349CED4);
	constexpr int32_t str_TXT_820E4F38_B_ = int32_t(0x820E4F38);
	constexpr int32_t Destroy_TXT_8349CED4_G__address = int32_t(0x832A8C70);
	if (!UseLiftedCode(144, 0x83271490)) { __imp__sub_83271490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED4_G_, str_TXT_820E4F38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CED4_G__address);
}
PROMOTED_ENTRY(144, sub_83271490, 0x83271490) { ctx.r3.u64 = Construct_TXT_8349CED4_G_(ctx, base); }

uint64_t Construct_TXT_8349CED8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CED8_G_ = int32_t(0x8349CED8);
	constexpr int32_t str_TXT_820E4F38_B_ = int32_t(0x820E4F70);
	constexpr int32_t Destroy_TXT_8349CED8_G__address = int32_t(0x832A8C80);
	if (!UseLiftedCode(144, 0x832714D0)) { __imp__sub_832714D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832714D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED8_G_, str_TXT_820E4F38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CED8_G__address);
}
PROMOTED_ENTRY(144, sub_832714D0, 0x832714D0) { ctx.r3.u64 = Construct_TXT_8349CED8_G_(ctx, base); }

uint64_t Construct_TXT_8349CEDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEDC_G_ = int32_t(0x8349CEDC);
	constexpr int32_t str_TXT_820E4FC0_B_ = int32_t(0x820E4FC0);
	constexpr int32_t Destroy_TXT_8349CEDC_G__address = int32_t(0x832A8C90);
	if (!UseLiftedCode(144, 0x83271510)) { __imp__sub_83271510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271510);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEDC_G_, str_TXT_820E4FC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEDC_G__address);
}
PROMOTED_ENTRY(144, sub_83271510, 0x83271510) { ctx.r3.u64 = Construct_TXT_8349CEDC_G_(ctx, base); }

uint64_t Construct_TXT_8349CEE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CEE0_G_ = int32_t(0x8349CEE0);
	constexpr int32_t str_TXT_820E4FEC_B_ = int32_t(0x820E4FEC);
	constexpr int32_t Destroy_TXT_8349CEE0_G__address = int32_t(0x832A8CA0);
	if (!UseLiftedCode(144, 0x83271550)) { __imp__sub_83271550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271550);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEE0_G_, str_TXT_820E4FEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CEE0_G__address);
}
PROMOTED_ENTRY(144, sub_83271550, 0x83271550) { ctx.r3.u64 = Construct_TXT_8349CEE0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__46 = 0x8349CEE4u;
	if (!UseLiftedCode(144, 0x83271590)) { __imp__sub_83271590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271590);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271590, 0x83271590) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__46(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__48 = 0x8349CEE8u;
	if (!UseLiftedCode(144, 0x832715C8)) { __imp__sub_832715C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832715C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832715C8, 0x832715C8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__48(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__47 = 0x8349CEECu;
	if (!UseLiftedCode(144, 0x83271600)) { __imp__sub_83271600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271600);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271600, 0x83271600) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__46 = 0x8349CEF0u;
	if (!UseLiftedCode(144, 0x83271638)) { __imp__sub_83271638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271638);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271638, 0x83271638) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__46 = 0x8349CEF4u;
	if (!UseLiftedCode(144, 0x83271670)) { __imp__sub_83271670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271670);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271670, 0x83271670) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__47 = 0x8349CEF8u;
	if (!UseLiftedCode(144, 0x832716A8)) { __imp__sub_832716A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832716A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832716A8, 0x832716A8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__46 = 0x8349CEFCu;
	if (!UseLiftedCode(144, 0x832716E0)) { __imp__sub_832716E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832716E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832716E0, 0x832716E0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__46 = 0x8349CF00u;
	if (!UseLiftedCode(144, 0x83271718)) { __imp__sub_83271718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271718);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271718, 0x83271718) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__46 = 0x8349CF04u;
	if (!UseLiftedCode(144, 0x83271750)) { __imp__sub_83271750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271750);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271750, 0x83271750) { ctx.r3.u64 = HashName_TXT_820A2C74_B__46(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__46 = 0x8349CF08u;
	if (!UseLiftedCode(144, 0x83271788)) { __imp__sub_83271788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271788);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271788, 0x83271788) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__46 = 0x8349CF0Cu;
	if (!UseLiftedCode(144, 0x832717C0)) { __imp__sub_832717C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832717C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832717C0, 0x832717C0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__46 = 0x8349CF10u;
	if (!UseLiftedCode(144, 0x832717F8)) { __imp__sub_832717F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832717F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832717F8, 0x832717F8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__49 = 0x8349CF14u;
	if (!UseLiftedCode(144, 0x83271830)) { __imp__sub_83271830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271830);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271830, 0x83271830) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__46 = 0x8349CF18u;
	if (!UseLiftedCode(144, 0x83271868)) { __imp__sub_83271868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271868);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271868, 0x83271868) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__46 = 0x8349CF1Cu;
	if (!UseLiftedCode(144, 0x832718A0)) { __imp__sub_832718A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832718A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832718A0, 0x832718A0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__46(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__46 = 0x8349CF20u;
	if (!UseLiftedCode(144, 0x832718D8)) { __imp__sub_832718D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832718D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832718D8, 0x832718D8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__46(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__46 = 0x8349CF24u;
	if (!UseLiftedCode(144, 0x83271910)) { __imp__sub_83271910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271910);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271910, 0x83271910) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__47 = 0x8349CF28u;
	if (!UseLiftedCode(144, 0x83271948)) { __imp__sub_83271948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271948);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271948, 0x83271948) { ctx.r3.u64 = HashName_TXT_820A2D24_B__47(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__46 = 0x8349CF2Cu;
	if (!UseLiftedCode(144, 0x83271980)) { __imp__sub_83271980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271980);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271980, 0x83271980) { ctx.r3.u64 = HashName_TXT_820A2D30_B__46(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__46 = 0x8349CF30u;
	if (!UseLiftedCode(144, 0x832719B8)) { __imp__sub_832719B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832719B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832719B8, 0x832719B8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__46(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__46(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__46 = 0x8349CF34u;
	if (!UseLiftedCode(144, 0x832719F0)) { __imp__sub_832719F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832719F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__46, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832719F0, 0x832719F0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__46(ctx, base); }

uint64_t Construct_TXT_8349CF38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF38_G_ = int32_t(0x8349CF38);
	constexpr int32_t str_TXT_820E1DC4_B_ = int32_t(0x820E1DC4);
	constexpr int32_t Destroy_TXT_8349CF38_G__address = int32_t(0x832A8CB0);
	if (!UseLiftedCode(144, 0x83271A28)) { __imp__sub_83271A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271A28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF38_G_, str_TXT_820E1DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF38_G__address);
}
PROMOTED_ENTRY(144, sub_83271A28, 0x83271A28) { ctx.r3.u64 = Construct_TXT_8349CF38_G_(ctx, base); }

uint64_t Construct_TXT_8349CF3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF3C_G_ = int32_t(0x8349CF3C);
	constexpr int32_t str_TXT_820E1D94_B_ = int32_t(0x820E1D94);
	constexpr int32_t Destroy_TXT_8349CF3C_G__address = int32_t(0x832A8CC0);
	if (!UseLiftedCode(144, 0x83271A68)) { __imp__sub_83271A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271A68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF3C_G_, str_TXT_820E1D94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF3C_G__address);
}
PROMOTED_ENTRY(144, sub_83271A68, 0x83271A68) { ctx.r3.u64 = Construct_TXT_8349CF3C_G_(ctx, base); }

uint64_t Construct_TXT_8349CF40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF40_G_ = int32_t(0x8349CF40);
	constexpr int32_t str_TXT_820E5174_B_ = int32_t(0x820E5174);
	constexpr int32_t Destroy_TXT_8349CF40_G__address = int32_t(0x832A8CD0);
	if (!UseLiftedCode(144, 0x83271AA8)) { __imp__sub_83271AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF40_G_, str_TXT_820E5174_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF40_G__address);
}
PROMOTED_ENTRY(144, sub_83271AA8, 0x83271AA8) { ctx.r3.u64 = Construct_TXT_8349CF40_G_(ctx, base); }

uint64_t Construct_TXT_8349CF44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF44_G_ = int32_t(0x8349CF44);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E51A4);
	constexpr int32_t Destroy_TXT_8349CF44_G__address = int32_t(0x832A8CE0);
	if (!UseLiftedCode(144, 0x83271AE8)) { __imp__sub_83271AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF44_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF44_G__address);
}
PROMOTED_ENTRY(144, sub_83271AE8, 0x83271AE8) { ctx.r3.u64 = Construct_TXT_8349CF44_G_(ctx, base); }

uint64_t Construct_TXT_8349CF48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF48_G_ = int32_t(0x8349CF48);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E51E0);
	constexpr int32_t Destroy_TXT_8349CF48_G__address = int32_t(0x832A8CF0);
	if (!UseLiftedCode(144, 0x83271B28)) { __imp__sub_83271B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271B28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF48_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF48_G__address);
}
PROMOTED_ENTRY(144, sub_83271B28, 0x83271B28) { ctx.r3.u64 = Construct_TXT_8349CF48_G_(ctx, base); }

uint64_t Construct_TXT_8349CF4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF4C_G_ = int32_t(0x8349CF4C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E5220);
	constexpr int32_t Destroy_TXT_8349CF4C_G__address = int32_t(0x832A8D00);
	if (!UseLiftedCode(144, 0x83271B68)) { __imp__sub_83271B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271B68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF4C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF4C_G__address);
}
PROMOTED_ENTRY(144, sub_83271B68, 0x83271B68) { ctx.r3.u64 = Construct_TXT_8349CF4C_G_(ctx, base); }

uint64_t Construct_TXT_8349CF50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF50_G_ = int32_t(0x8349CF50);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E5268);
	constexpr int32_t Destroy_TXT_8349CF50_G__address = int32_t(0x832A8D10);
	if (!UseLiftedCode(144, 0x83271BA8)) { __imp__sub_83271BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271BA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF50_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF50_G__address);
}
PROMOTED_ENTRY(144, sub_83271BA8, 0x83271BA8) { ctx.r3.u64 = Construct_TXT_8349CF50_G_(ctx, base); }

uint64_t Construct_TXT_8349CF54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF54_G_ = int32_t(0x8349CF54);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E52B0);
	constexpr int32_t Destroy_TXT_8349CF54_G__address = int32_t(0x832A8D20);
	if (!UseLiftedCode(144, 0x83271BE8)) { __imp__sub_83271BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF54_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF54_G__address);
}
PROMOTED_ENTRY(144, sub_83271BE8, 0x83271BE8) { ctx.r3.u64 = Construct_TXT_8349CF54_G_(ctx, base); }

uint64_t Construct_TXT_8349CF58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF58_G_ = int32_t(0x8349CF58);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F48);
	constexpr int32_t Destroy_TXT_8349CF58_G__address = int32_t(0x832A8D30);
	if (!UseLiftedCode(144, 0x83271C28)) { __imp__sub_83271C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271C28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF58_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF58_G__address);
}
PROMOTED_ENTRY(144, sub_83271C28, 0x83271C28) { ctx.r3.u64 = Construct_TXT_8349CF58_G_(ctx, base); }

uint64_t Construct_TXT_8349CF5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF5C_G_ = int32_t(0x8349CF5C);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E20);
	constexpr int32_t Destroy_TXT_8349CF5C_G__address = int32_t(0x832A8D40);
	if (!UseLiftedCode(144, 0x83271C68)) { __imp__sub_83271C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271C68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF5C_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF5C_G__address);
}
PROMOTED_ENTRY(144, sub_83271C68, 0x83271C68) { ctx.r3.u64 = Construct_TXT_8349CF5C_G_(ctx, base); }

uint64_t Construct_TXT_8349CF60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF60_G_ = int32_t(0x8349CF60);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E50);
	constexpr int32_t Destroy_TXT_8349CF60_G__address = int32_t(0x832A8D50);
	if (!UseLiftedCode(144, 0x83271CA8)) { __imp__sub_83271CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271CA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF60_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF60_G__address);
}
PROMOTED_ENTRY(144, sub_83271CA8, 0x83271CA8) { ctx.r3.u64 = Construct_TXT_8349CF60_G_(ctx, base); }

uint64_t Construct_TXT_8349CF64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CF64_G_ = int32_t(0x8349CF64);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F8C);
	constexpr int32_t Destroy_TXT_8349CF64_G__address = int32_t(0x832A8D60);
	if (!UseLiftedCode(144, 0x83271CE8)) { __imp__sub_83271CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271CE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF64_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CF64_G__address);
}
PROMOTED_ENTRY(144, sub_83271CE8, 0x83271CE8) { ctx.r3.u64 = Construct_TXT_8349CF64_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__47 = 0x8349CF6Cu;
	if (!UseLiftedCode(144, 0x83271D68)) { __imp__sub_83271D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271D68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271D68, 0x83271D68) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__47(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__49 = 0x8349CF70u;
	if (!UseLiftedCode(144, 0x83271DA0)) { __imp__sub_83271DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271DA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271DA0, 0x83271DA0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__49(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__48 = 0x8349CF74u;
	if (!UseLiftedCode(144, 0x83271DD8)) { __imp__sub_83271DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271DD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271DD8, 0x83271DD8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__47 = 0x8349CF78u;
	if (!UseLiftedCode(144, 0x83271E10)) { __imp__sub_83271E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271E10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271E10, 0x83271E10) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__47 = 0x8349CF7Cu;
	if (!UseLiftedCode(144, 0x83271E48)) { __imp__sub_83271E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271E48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271E48, 0x83271E48) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__48 = 0x8349CF80u;
	if (!UseLiftedCode(144, 0x83271E80)) { __imp__sub_83271E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271E80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271E80, 0x83271E80) { ctx.r3.u64 = HashName_TXT_820A2C34_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__47 = 0x8349CF84u;
	if (!UseLiftedCode(144, 0x83271EB8)) { __imp__sub_83271EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271EB8, 0x83271EB8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__47 = 0x8349CF88u;
	if (!UseLiftedCode(144, 0x83271EF0)) { __imp__sub_83271EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271EF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271EF0, 0x83271EF0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__47 = 0x8349CF8Cu;
	if (!UseLiftedCode(144, 0x83271F28)) { __imp__sub_83271F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271F28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271F28, 0x83271F28) { ctx.r3.u64 = HashName_TXT_820A2C74_B__47(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__47 = 0x8349CF90u;
	if (!UseLiftedCode(144, 0x83271F60)) { __imp__sub_83271F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271F60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271F60, 0x83271F60) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__47 = 0x8349CF94u;
	if (!UseLiftedCode(144, 0x83271F98)) { __imp__sub_83271F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271F98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271F98, 0x83271F98) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__47 = 0x8349CF98u;
	if (!UseLiftedCode(144, 0x83271FD0)) { __imp__sub_83271FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271FD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83271FD0, 0x83271FD0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__50 = 0x8349CF9Cu;
	if (!UseLiftedCode(144, 0x83272008)) { __imp__sub_83272008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272008);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272008, 0x83272008) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__47 = 0x8349CFA0u;
	if (!UseLiftedCode(144, 0x83272040)) { __imp__sub_83272040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272040);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272040, 0x83272040) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__47 = 0x8349CFA4u;
	if (!UseLiftedCode(144, 0x83272078)) { __imp__sub_83272078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272078);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272078, 0x83272078) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__47(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__47 = 0x8349CFA8u;
	if (!UseLiftedCode(144, 0x832720B0)) { __imp__sub_832720B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832720B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832720B0, 0x832720B0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__47(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__47 = 0x8349CFACu;
	if (!UseLiftedCode(144, 0x832720E8)) { __imp__sub_832720E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832720E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832720E8, 0x832720E8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__48 = 0x8349CFB0u;
	if (!UseLiftedCode(144, 0x83272120)) { __imp__sub_83272120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272120);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272120, 0x83272120) { ctx.r3.u64 = HashName_TXT_820A2D24_B__48(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__47 = 0x8349CFB4u;
	if (!UseLiftedCode(144, 0x83272158)) { __imp__sub_83272158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272158);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272158, 0x83272158) { ctx.r3.u64 = HashName_TXT_820A2D30_B__47(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__47 = 0x8349CFB8u;
	if (!UseLiftedCode(144, 0x83272190)) { __imp__sub_83272190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272190);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272190, 0x83272190) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__47(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__47(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__47 = 0x8349CFBCu;
	if (!UseLiftedCode(144, 0x832721C8)) { __imp__sub_832721C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832721C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__47, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832721C8, 0x832721C8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__47(ctx, base); }

uint64_t Construct_TXT_8349CFC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFC0_G_ = int32_t(0x8349CFC0);
	constexpr int32_t str_TXT_820E235C_B_ = int32_t(0x820E235C);
	constexpr int32_t Destroy_TXT_8349CFC0_G__address = int32_t(0x832A8D80);
	if (!UseLiftedCode(144, 0x83272200)) { __imp__sub_83272200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272200);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC0_G_, str_TXT_820E235C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFC0_G__address);
}
PROMOTED_ENTRY(144, sub_83272200, 0x83272200) { ctx.r3.u64 = Construct_TXT_8349CFC0_G_(ctx, base); }

uint64_t Construct_TXT_8349CFC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFC4_G_ = int32_t(0x8349CFC4);
	constexpr int32_t str_TXT_820E238C_B_ = int32_t(0x820E238C);
	constexpr int32_t Destroy_TXT_8349CFC4_G__address = int32_t(0x832A8D90);
	if (!UseLiftedCode(144, 0x83272240)) { __imp__sub_83272240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272240);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC4_G_, str_TXT_820E238C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFC4_G__address);
}
PROMOTED_ENTRY(144, sub_83272240, 0x83272240) { ctx.r3.u64 = Construct_TXT_8349CFC4_G_(ctx, base); }

uint64_t Construct_TXT_8349CFC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFC8_G_ = int32_t(0x8349CFC8);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5348);
	constexpr int32_t Destroy_TXT_8349CFC8_G__address = int32_t(0x832A8DA0);
	if (!UseLiftedCode(144, 0x83272280)) { __imp__sub_83272280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272280);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC8_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFC8_G__address);
}
PROMOTED_ENTRY(144, sub_83272280, 0x83272280) { ctx.r3.u64 = Construct_TXT_8349CFC8_G_(ctx, base); }

uint64_t Construct_TXT_8349CFCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFCC_G_ = int32_t(0x8349CFCC);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5390);
	constexpr int32_t Destroy_TXT_8349CFCC_G__address = int32_t(0x832A8DB0);
	if (!UseLiftedCode(144, 0x832722C0)) { __imp__sub_832722C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832722C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFCC_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFCC_G__address);
}
PROMOTED_ENTRY(144, sub_832722C0, 0x832722C0) { ctx.r3.u64 = Construct_TXT_8349CFCC_G_(ctx, base); }

uint64_t Construct_TXT_8349CFD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFD0_G_ = int32_t(0x8349CFD0);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E53C8);
	constexpr int32_t Destroy_TXT_8349CFD0_G__address = int32_t(0x832A8DC0);
	if (!UseLiftedCode(144, 0x83272300)) { __imp__sub_83272300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272300);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD0_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFD0_G__address);
}
PROMOTED_ENTRY(144, sub_83272300, 0x83272300) { ctx.r3.u64 = Construct_TXT_8349CFD0_G_(ctx, base); }

uint64_t Construct_TXT_8349CFD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFD4_G_ = int32_t(0x8349CFD4);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5404);
	constexpr int32_t Destroy_TXT_8349CFD4_G__address = int32_t(0x832A8DD0);
	if (!UseLiftedCode(144, 0x83272340)) { __imp__sub_83272340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272340);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD4_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFD4_G__address);
}
PROMOTED_ENTRY(144, sub_83272340, 0x83272340) { ctx.r3.u64 = Construct_TXT_8349CFD4_G_(ctx, base); }

uint64_t Construct_TXT_8349CFD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFD8_G_ = int32_t(0x8349CFD8);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5434);
	constexpr int32_t Destroy_TXT_8349CFD8_G__address = int32_t(0x832A8DE0);
	if (!UseLiftedCode(144, 0x83272380)) { __imp__sub_83272380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272380);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD8_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFD8_G__address);
}
PROMOTED_ENTRY(144, sub_83272380, 0x83272380) { ctx.r3.u64 = Construct_TXT_8349CFD8_G_(ctx, base); }

uint64_t Construct_TXT_8349CFDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFDC_G_ = int32_t(0x8349CFDC);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E546C);
	constexpr int32_t Destroy_TXT_8349CFDC_G__address = int32_t(0x832A8DF0);
	if (!UseLiftedCode(144, 0x832723C0)) { __imp__sub_832723C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832723C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFDC_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFDC_G__address);
}
PROMOTED_ENTRY(144, sub_832723C0, 0x832723C0) { ctx.r3.u64 = Construct_TXT_8349CFDC_G_(ctx, base); }

uint64_t Construct_TXT_8349CFE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFE0_G_ = int32_t(0x8349CFE0);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E54A4);
	constexpr int32_t Destroy_TXT_8349CFE0_G__address = int32_t(0x832A8E00);
	if (!UseLiftedCode(144, 0x83272400)) { __imp__sub_83272400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272400);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE0_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFE0_G__address);
}
PROMOTED_ENTRY(144, sub_83272400, 0x83272400) { ctx.r3.u64 = Construct_TXT_8349CFE0_G_(ctx, base); }

uint64_t Construct_TXT_8349CFE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFE4_G_ = int32_t(0x8349CFE4);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E54E4);
	constexpr int32_t Destroy_TXT_8349CFE4_G__address = int32_t(0x832A8E10);
	if (!UseLiftedCode(144, 0x83272440)) { __imp__sub_83272440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272440);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE4_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFE4_G__address);
}
PROMOTED_ENTRY(144, sub_83272440, 0x83272440) { ctx.r3.u64 = Construct_TXT_8349CFE4_G_(ctx, base); }

uint64_t Construct_TXT_8349CFE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFE8_G_ = int32_t(0x8349CFE8);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5524);
	constexpr int32_t Destroy_TXT_8349CFE8_G__address = int32_t(0x832A8E20);
	if (!UseLiftedCode(144, 0x83272480)) { __imp__sub_83272480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272480);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE8_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFE8_G__address);
}
PROMOTED_ENTRY(144, sub_83272480, 0x83272480) { ctx.r3.u64 = Construct_TXT_8349CFE8_G_(ctx, base); }

uint64_t Construct_TXT_8349CFEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFEC_G_ = int32_t(0x8349CFEC);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E5560);
	constexpr int32_t Destroy_TXT_8349CFEC_G__address = int32_t(0x832A8E30);
	if (!UseLiftedCode(144, 0x832724C0)) { __imp__sub_832724C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832724C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFEC_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFEC_G__address);
}
PROMOTED_ENTRY(144, sub_832724C0, 0x832724C0) { ctx.r3.u64 = Construct_TXT_8349CFEC_G_(ctx, base); }

uint64_t Construct_TXT_8349CFF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFF0_G_ = int32_t(0x8349CFF0);
	constexpr int32_t str_TXT_820E5598_B_ = int32_t(0x820E5598);
	constexpr int32_t Destroy_TXT_8349CFF0_G__address = int32_t(0x832A8E40);
	if (!UseLiftedCode(144, 0x83272500)) { __imp__sub_83272500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272500);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF0_G_, str_TXT_820E5598_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFF0_G__address);
}
PROMOTED_ENTRY(144, sub_83272500, 0x83272500) { ctx.r3.u64 = Construct_TXT_8349CFF0_G_(ctx, base); }

uint64_t Construct_TXT_8349CFF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFF4_G_ = int32_t(0x8349CFF4);
	constexpr int32_t str_TXT_820E5598_B_ = int32_t(0x820E55D0);
	constexpr int32_t Destroy_TXT_8349CFF4_G__address = int32_t(0x832A8E50);
	if (!UseLiftedCode(144, 0x83272540)) { __imp__sub_83272540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272540);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF4_G_, str_TXT_820E5598_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFF4_G__address);
}
PROMOTED_ENTRY(144, sub_83272540, 0x83272540) { ctx.r3.u64 = Construct_TXT_8349CFF4_G_(ctx, base); }

uint64_t Construct_TXT_8349CFF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFF8_G_ = int32_t(0x8349CFF8);
	constexpr int32_t str_TXT_820E5598_B_ = int32_t(0x820E5610);
	constexpr int32_t Destroy_TXT_8349CFF8_G__address = int32_t(0x832A8E60);
	if (!UseLiftedCode(144, 0x83272580)) { __imp__sub_83272580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272580);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF8_G_, str_TXT_820E5598_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFF8_G__address);
}
PROMOTED_ENTRY(144, sub_83272580, 0x83272580) { ctx.r3.u64 = Construct_TXT_8349CFF8_G_(ctx, base); }

uint64_t Construct_TXT_8349CFFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CFFC_G_ = int32_t(0x8349CFFC);
	constexpr int32_t str_TXT_820E5598_B_ = int32_t(0x820E5648);
	constexpr int32_t Destroy_TXT_8349CFFC_G__address = int32_t(0x832A8E70);
	if (!UseLiftedCode(144, 0x832725C0)) { __imp__sub_832725C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832725C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFFC_G_, str_TXT_820E5598_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CFFC_G__address);
}
PROMOTED_ENTRY(144, sub_832725C0, 0x832725C0) { ctx.r3.u64 = Construct_TXT_8349CFFC_G_(ctx, base); }

uint64_t Construct_TXT_8349D000_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D000_G_ = int32_t(0x8349D000);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E2488);
	constexpr int32_t Destroy_TXT_8349D000_G__address = int32_t(0x832A8E80);
	if (!UseLiftedCode(144, 0x83272600)) { __imp__sub_83272600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272600);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D000_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D000_G__address);
}
PROMOTED_ENTRY(144, sub_83272600, 0x83272600) { ctx.r3.u64 = Construct_TXT_8349D000_G_(ctx, base); }

uint64_t Construct_TXT_8349D004_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D004_G_ = int32_t(0x8349D004);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D004_G__address = int32_t(0x832A8E90);
	if (!UseLiftedCode(144, 0x83272640)) { __imp__sub_83272640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272640);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D004_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D004_G__address);
}
PROMOTED_ENTRY(144, sub_83272640, 0x83272640) { ctx.r3.u64 = Construct_TXT_8349D004_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__48 = 0x8349D00Cu;
	if (!UseLiftedCode(144, 0x832726C0)) { __imp__sub_832726C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832726C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832726C0, 0x832726C0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__48(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__50 = 0x8349D010u;
	if (!UseLiftedCode(144, 0x832726F8)) { __imp__sub_832726F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832726F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832726F8, 0x832726F8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__50(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__49 = 0x8349D014u;
	if (!UseLiftedCode(144, 0x83272730)) { __imp__sub_83272730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272730, 0x83272730) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__48 = 0x8349D018u;
	if (!UseLiftedCode(144, 0x83272768)) { __imp__sub_83272768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272768, 0x83272768) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__48 = 0x8349D01Cu;
	if (!UseLiftedCode(144, 0x832727A0)) { __imp__sub_832727A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832727A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832727A0, 0x832727A0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__49 = 0x8349D020u;
	if (!UseLiftedCode(144, 0x832727D8)) { __imp__sub_832727D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832727D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832727D8, 0x832727D8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__48 = 0x8349D024u;
	if (!UseLiftedCode(144, 0x83272810)) { __imp__sub_83272810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272810, 0x83272810) { ctx.r3.u64 = HashName_TXT_820A2C44_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__48 = 0x8349D028u;
	if (!UseLiftedCode(144, 0x83272848)) { __imp__sub_83272848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272848, 0x83272848) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__48 = 0x8349D02Cu;
	if (!UseLiftedCode(144, 0x83272880)) { __imp__sub_83272880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272880);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272880, 0x83272880) { ctx.r3.u64 = HashName_TXT_820A2C74_B__48(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__48 = 0x8349D030u;
	if (!UseLiftedCode(144, 0x832728B8)) { __imp__sub_832728B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832728B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832728B8, 0x832728B8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__48 = 0x8349D034u;
	if (!UseLiftedCode(144, 0x832728F0)) { __imp__sub_832728F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832728F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832728F0, 0x832728F0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__48 = 0x8349D038u;
	if (!UseLiftedCode(144, 0x83272928)) { __imp__sub_83272928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272928);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272928, 0x83272928) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__51 = 0x8349D03Cu;
	if (!UseLiftedCode(144, 0x83272960)) { __imp__sub_83272960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272960, 0x83272960) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__48 = 0x8349D040u;
	if (!UseLiftedCode(144, 0x83272998)) { __imp__sub_83272998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272998, 0x83272998) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__48 = 0x8349D044u;
	if (!UseLiftedCode(144, 0x832729D0)) { __imp__sub_832729D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832729D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832729D0, 0x832729D0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__48(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__48 = 0x8349D048u;
	if (!UseLiftedCode(144, 0x83272A08)) { __imp__sub_83272A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272A08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272A08, 0x83272A08) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__48(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__48 = 0x8349D04Cu;
	if (!UseLiftedCode(144, 0x83272A40)) { __imp__sub_83272A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272A40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272A40, 0x83272A40) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__49 = 0x8349D050u;
	if (!UseLiftedCode(144, 0x83272A78)) { __imp__sub_83272A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272A78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272A78, 0x83272A78) { ctx.r3.u64 = HashName_TXT_820A2D24_B__49(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__48 = 0x8349D054u;
	if (!UseLiftedCode(144, 0x83272AB0)) { __imp__sub_83272AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272AB0, 0x83272AB0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__48(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__48 = 0x8349D058u;
	if (!UseLiftedCode(144, 0x83272AE8)) { __imp__sub_83272AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272AE8, 0x83272AE8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__48(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__48 = 0x8349D05Cu;
	if (!UseLiftedCode(144, 0x83272B20)) { __imp__sub_83272B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272B20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__48, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83272B20, 0x83272B20) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__48(ctx, base); }

uint64_t Construct_TXT_8349D064_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D064_G_ = int32_t(0x8349D064);
	constexpr int32_t str_TXT_820E5D34_B_ = int32_t(0x820E5D34);
	constexpr int32_t Destroy_TXT_8349D064_G__address = int32_t(0x832A8EC0);
	if (!UseLiftedCode(144, 0x83272B98)) { __imp__sub_83272B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272B98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D064_G_, str_TXT_820E5D34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D064_G__address);
}
PROMOTED_ENTRY(144, sub_83272B98, 0x83272B98) { ctx.r3.u64 = Construct_TXT_8349D064_G_(ctx, base); }

uint64_t Construct_TXT_8349D068_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D068_G_ = int32_t(0x8349D068);
	constexpr int32_t str_TXT_820E5D60_B_ = int32_t(0x820E5D60);
	constexpr int32_t Destroy_TXT_8349D068_G__address = int32_t(0x832A8ED0);
	if (!UseLiftedCode(144, 0x83272BD8)) { __imp__sub_83272BD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272BD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D068_G_, str_TXT_820E5D60_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D068_G__address);
}
PROMOTED_ENTRY(144, sub_83272BD8, 0x83272BD8) { ctx.r3.u64 = Construct_TXT_8349D068_G_(ctx, base); }

uint64_t Construct_TXT_8349D06C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D06C_G_ = int32_t(0x8349D06C);
	constexpr int32_t str_TXT_820E5D8C_B_ = int32_t(0x820E5D8C);
	constexpr int32_t Destroy_TXT_8349D06C_G__address = int32_t(0x832A8EE0);
	if (!UseLiftedCode(144, 0x83272C18)) { __imp__sub_83272C18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D06C_G_, str_TXT_820E5D8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D06C_G__address);
}
PROMOTED_ENTRY(144, sub_83272C18, 0x83272C18) { ctx.r3.u64 = Construct_TXT_8349D06C_G_(ctx, base); }

uint64_t Construct_TXT_8349D070_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D070_G_ = int32_t(0x8349D070);
	constexpr int32_t str_TXT_820E5DB8_B_ = int32_t(0x820E5DB8);
	constexpr int32_t Destroy_TXT_8349D070_G__address = int32_t(0x832A8EF0);
	if (!UseLiftedCode(144, 0x83272C58)) { __imp__sub_83272C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D070_G_, str_TXT_820E5DB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D070_G__address);
}
PROMOTED_ENTRY(144, sub_83272C58, 0x83272C58) { ctx.r3.u64 = Construct_TXT_8349D070_G_(ctx, base); }

uint64_t Construct_TXT_8349D074_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D074_G_ = int32_t(0x8349D074);
	constexpr int32_t str_TXT_820E5DE4_B_ = int32_t(0x820E5DE4);
	constexpr int32_t Destroy_TXT_8349D074_G__address = int32_t(0x832A8F00);
	if (!UseLiftedCode(144, 0x83272C98)) { __imp__sub_83272C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D074_G_, str_TXT_820E5DE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D074_G__address);
}
PROMOTED_ENTRY(144, sub_83272C98, 0x83272C98) { ctx.r3.u64 = Construct_TXT_8349D074_G_(ctx, base); }

uint64_t Construct_TXT_8349D078_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D078_G_ = int32_t(0x8349D078);
	constexpr int32_t str_TXT_820E5E0C_B_ = int32_t(0x820E5E0C);
	constexpr int32_t Destroy_TXT_8349D078_G__address = int32_t(0x832A8F10);
	if (!UseLiftedCode(144, 0x83272CD8)) { __imp__sub_83272CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272CD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D078_G_, str_TXT_820E5E0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D078_G__address);
}
PROMOTED_ENTRY(144, sub_83272CD8, 0x83272CD8) { ctx.r3.u64 = Construct_TXT_8349D078_G_(ctx, base); }

uint64_t Construct_TXT_8349D07C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D07C_G_ = int32_t(0x8349D07C);
	constexpr int32_t str_TXT_820E5E40_B_ = int32_t(0x820E5E40);
	constexpr int32_t Destroy_TXT_8349D07C_G__address = int32_t(0x832A8F20);
	if (!UseLiftedCode(144, 0x83272D18)) { __imp__sub_83272D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D07C_G_, str_TXT_820E5E40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D07C_G__address);
}
PROMOTED_ENTRY(144, sub_83272D18, 0x83272D18) { ctx.r3.u64 = Construct_TXT_8349D07C_G_(ctx, base); }

uint64_t Construct_TXT_8349D080_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D080_G_ = int32_t(0x8349D080);
	constexpr int32_t str_TXT_820E5E74_B_ = int32_t(0x820E5E74);
	constexpr int32_t Destroy_TXT_8349D080_G__address = int32_t(0x832A8F30);
	if (!UseLiftedCode(144, 0x83272D58)) { __imp__sub_83272D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D080_G_, str_TXT_820E5E74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D080_G__address);
}
PROMOTED_ENTRY(144, sub_83272D58, 0x83272D58) { ctx.r3.u64 = Construct_TXT_8349D080_G_(ctx, base); }

uint64_t Construct_TXT_8349D084_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D084_G_ = int32_t(0x8349D084);
	constexpr int32_t str_TXT_820E5EA4_B_ = int32_t(0x820E5EA4);
	constexpr int32_t Destroy_TXT_8349D084_G__address = int32_t(0x832A8F40);
	if (!UseLiftedCode(144, 0x83272D98)) { __imp__sub_83272D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D084_G_, str_TXT_820E5EA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D084_G__address);
}
PROMOTED_ENTRY(144, sub_83272D98, 0x83272D98) { ctx.r3.u64 = Construct_TXT_8349D084_G_(ctx, base); }

uint64_t Construct_TXT_8349D088_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D088_G_ = int32_t(0x8349D088);
	constexpr int32_t str_TXT_820E5ED8_B_ = int32_t(0x820E5ED8);
	constexpr int32_t Destroy_TXT_8349D088_G__address = int32_t(0x832A8F50);
	if (!UseLiftedCode(144, 0x83272DD8)) { __imp__sub_83272DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272DD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D088_G_, str_TXT_820E5ED8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D088_G__address);
}
PROMOTED_ENTRY(144, sub_83272DD8, 0x83272DD8) { ctx.r3.u64 = Construct_TXT_8349D088_G_(ctx, base); }

uint64_t Construct_TXT_8349D08C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D08C_G_ = int32_t(0x8349D08C);
	constexpr int32_t str_TXT_820E5F08_B_ = int32_t(0x820E5F08);
	constexpr int32_t Destroy_TXT_8349D08C_G__address = int32_t(0x832A8F60);
	if (!UseLiftedCode(144, 0x83272E18)) { __imp__sub_83272E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272E18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D08C_G_, str_TXT_820E5F08_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D08C_G__address);
}
PROMOTED_ENTRY(144, sub_83272E18, 0x83272E18) { ctx.r3.u64 = Construct_TXT_8349D08C_G_(ctx, base); }

uint64_t Construct_TXT_8349D094_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D094_G_ = int32_t(0x8349D094);
	constexpr int32_t str_TXT_820E5F34_B_ = int32_t(0x820E5F34);
	constexpr int32_t Destroy_TXT_8349D094_G__address = int32_t(0x832A8F80);
	if (!UseLiftedCode(144, 0x83272E98)) { __imp__sub_83272E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272E98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D094_G_, str_TXT_820E5F34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D094_G__address);
}
PROMOTED_ENTRY(144, sub_83272E98, 0x83272E98) { ctx.r3.u64 = Construct_TXT_8349D094_G_(ctx, base); }

uint64_t Construct_TXT_8349D098_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D098_G_ = int32_t(0x8349D098);
	constexpr int32_t str_TXT_820E4874_B_ = int32_t(0x820E4874);
	constexpr int32_t Destroy_TXT_8349D098_G__address = int32_t(0x832A8F90);
	if (!UseLiftedCode(144, 0x83272ED8)) { __imp__sub_83272ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272ED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D098_G_, str_TXT_820E4874_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D098_G__address);
}
PROMOTED_ENTRY(144, sub_83272ED8, 0x83272ED8) { ctx.r3.u64 = Construct_TXT_8349D098_G_(ctx, base); }

uint64_t Construct_TXT_8349D09C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D09C_G_ = int32_t(0x8349D09C);
	constexpr int32_t str_TXT_820E5F58_B_ = int32_t(0x820E5F58);
	constexpr int32_t Destroy_TXT_8349D09C_G__address = int32_t(0x832A8FA0);
	if (!UseLiftedCode(144, 0x83272F18)) { __imp__sub_83272F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D09C_G_, str_TXT_820E5F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D09C_G__address);
}
PROMOTED_ENTRY(144, sub_83272F18, 0x83272F18) { ctx.r3.u64 = Construct_TXT_8349D09C_G_(ctx, base); }

uint64_t Construct_TXT_8349D0A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0A0_G_ = int32_t(0x8349D0A0);
	constexpr int32_t str_TXT_820E5F84_B_ = int32_t(0x820E5F84);
	constexpr int32_t Destroy_TXT_8349D0A0_G__address = int32_t(0x832A8FB0);
	if (!UseLiftedCode(144, 0x83272F58)) { __imp__sub_83272F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A0_G_, str_TXT_820E5F84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0A0_G__address);
}
PROMOTED_ENTRY(144, sub_83272F58, 0x83272F58) { ctx.r3.u64 = Construct_TXT_8349D0A0_G_(ctx, base); }

uint64_t Construct_TXT_8349D0A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0A4_G_ = int32_t(0x8349D0A4);
	constexpr int32_t str_TXT_820E5FB0_B_ = int32_t(0x820E5FB0);
	constexpr int32_t Destroy_TXT_8349D0A4_G__address = int32_t(0x832A8FC0);
	if (!UseLiftedCode(144, 0x83272F98)) { __imp__sub_83272F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A4_G_, str_TXT_820E5FB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0A4_G__address);
}
PROMOTED_ENTRY(144, sub_83272F98, 0x83272F98) { ctx.r3.u64 = Construct_TXT_8349D0A4_G_(ctx, base); }

uint64_t Construct_TXT_8349D0A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0A8_G_ = int32_t(0x8349D0A8);
	constexpr int32_t str_TXT_820E5FDC_B_ = int32_t(0x820E5FDC);
	constexpr int32_t Destroy_TXT_8349D0A8_G__address = int32_t(0x832A8FD0);
	if (!UseLiftedCode(144, 0x83272FD8)) { __imp__sub_83272FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272FD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A8_G_, str_TXT_820E5FDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0A8_G__address);
}
PROMOTED_ENTRY(144, sub_83272FD8, 0x83272FD8) { ctx.r3.u64 = Construct_TXT_8349D0A8_G_(ctx, base); }

uint64_t Construct_TXT_8349D0AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0AC_G_ = int32_t(0x8349D0AC);
	constexpr int32_t str_TXT_820E6010_B_ = int32_t(0x820E6010);
	constexpr int32_t Destroy_TXT_8349D0AC_G__address = int32_t(0x832A8FE0);
	if (!UseLiftedCode(144, 0x83273018)) { __imp__sub_83273018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273018);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0AC_G_, str_TXT_820E6010_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0AC_G__address);
}
PROMOTED_ENTRY(144, sub_83273018, 0x83273018) { ctx.r3.u64 = Construct_TXT_8349D0AC_G_(ctx, base); }

uint64_t Construct_TXT_8349D0B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0B0_G_ = int32_t(0x8349D0B0);
	constexpr int32_t str_TXT_820E6044_B_ = int32_t(0x820E6044);
	constexpr int32_t Destroy_TXT_8349D0B0_G__address = int32_t(0x832A8FF0);
	if (!UseLiftedCode(144, 0x83273058)) { __imp__sub_83273058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273058);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B0_G_, str_TXT_820E6044_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0B0_G__address);
}
PROMOTED_ENTRY(144, sub_83273058, 0x83273058) { ctx.r3.u64 = Construct_TXT_8349D0B0_G_(ctx, base); }

uint64_t Construct_TXT_8349D0B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0B4_G_ = int32_t(0x8349D0B4);
	constexpr int32_t str_TXT_820E6078_B_ = int32_t(0x820E6078);
	constexpr int32_t Destroy_TXT_8349D0B4_G__address = int32_t(0x832A9000);
	if (!UseLiftedCode(144, 0x83273098)) { __imp__sub_83273098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273098);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B4_G_, str_TXT_820E6078_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0B4_G__address);
}
PROMOTED_ENTRY(144, sub_83273098, 0x83273098) { ctx.r3.u64 = Construct_TXT_8349D0B4_G_(ctx, base); }

uint64_t Construct_TXT_8349D0B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0B8_G_ = int32_t(0x8349D0B8);
	constexpr int32_t str_TXT_820E5F58_B_ = int32_t(0x820E5F58);
	constexpr int32_t Destroy_TXT_8349D0B8_G__address = int32_t(0x832A9010);
	if (!UseLiftedCode(144, 0x832730D8)) { __imp__sub_832730D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832730D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B8_G_, str_TXT_820E5F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0B8_G__address);
}
PROMOTED_ENTRY(144, sub_832730D8, 0x832730D8) { ctx.r3.u64 = Construct_TXT_8349D0B8_G_(ctx, base); }

uint64_t Construct_TXT_8349D0BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0BC_G_ = int32_t(0x8349D0BC);
	constexpr int32_t str_TXT_820E5F84_B_ = int32_t(0x820E5F84);
	constexpr int32_t Destroy_TXT_8349D0BC_G__address = int32_t(0x832A9020);
	if (!UseLiftedCode(144, 0x83273118)) { __imp__sub_83273118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273118);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0BC_G_, str_TXT_820E5F84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0BC_G__address);
}
PROMOTED_ENTRY(144, sub_83273118, 0x83273118) { ctx.r3.u64 = Construct_TXT_8349D0BC_G_(ctx, base); }

uint64_t Construct_TXT_8349D0C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0C0_G_ = int32_t(0x8349D0C0);
	constexpr int32_t str_TXT_820E60A4_B_ = int32_t(0x820E60A4);
	constexpr int32_t Destroy_TXT_8349D0C0_G__address = int32_t(0x832A9030);
	if (!UseLiftedCode(144, 0x83273158)) { __imp__sub_83273158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273158);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C0_G_, str_TXT_820E60A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0C0_G__address);
}
PROMOTED_ENTRY(144, sub_83273158, 0x83273158) { ctx.r3.u64 = Construct_TXT_8349D0C0_G_(ctx, base); }

uint64_t Construct_TXT_8349D0C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0C4_G_ = int32_t(0x8349D0C4);
	constexpr int32_t str_TXT_820E5FDC_B_ = int32_t(0x820E5FDC);
	constexpr int32_t Destroy_TXT_8349D0C4_G__address = int32_t(0x832A9040);
	if (!UseLiftedCode(144, 0x83273198)) { __imp__sub_83273198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273198);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C4_G_, str_TXT_820E5FDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0C4_G__address);
}
PROMOTED_ENTRY(144, sub_83273198, 0x83273198) { ctx.r3.u64 = Construct_TXT_8349D0C4_G_(ctx, base); }

uint64_t Construct_TXT_8349D0C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0C8_G_ = int32_t(0x8349D0C8);
	constexpr int32_t str_TXT_820E6010_B_ = int32_t(0x820E6010);
	constexpr int32_t Destroy_TXT_8349D0C8_G__address = int32_t(0x832A9050);
	if (!UseLiftedCode(144, 0x832731D8)) { __imp__sub_832731D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832731D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C8_G_, str_TXT_820E6010_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0C8_G__address);
}
PROMOTED_ENTRY(144, sub_832731D8, 0x832731D8) { ctx.r3.u64 = Construct_TXT_8349D0C8_G_(ctx, base); }

uint64_t Construct_TXT_8349D0CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0CC_G_ = int32_t(0x8349D0CC);
	constexpr int32_t str_TXT_820E6078_B_ = int32_t(0x820E6078);
	constexpr int32_t Destroy_TXT_8349D0CC_G__address = int32_t(0x832A9060);
	if (!UseLiftedCode(144, 0x83273218)) { __imp__sub_83273218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273218);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0CC_G_, str_TXT_820E6078_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0CC_G__address);
}
PROMOTED_ENTRY(144, sub_83273218, 0x83273218) { ctx.r3.u64 = Construct_TXT_8349D0CC_G_(ctx, base); }

uint64_t Construct_TXT_8349D0D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D0D0_G_ = int32_t(0x8349D0D0);
	constexpr int32_t str_TXT_820E60A4_B_ = int32_t(0x820E60A4);
	constexpr int32_t Destroy_TXT_8349D0D0_G__address = int32_t(0x832A9070);
	if (!UseLiftedCode(144, 0x83273258)) { __imp__sub_83273258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0D0_G_, str_TXT_820E60A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D0D0_G__address);
}
PROMOTED_ENTRY(144, sub_83273258, 0x83273258) { ctx.r3.u64 = Construct_TXT_8349D0D0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__49 = 0x8349D0D4u;
	if (!UseLiftedCode(144, 0x83273298)) { __imp__sub_83273298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273298);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273298, 0x83273298) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__49(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__51 = 0x8349D0D8u;
	if (!UseLiftedCode(144, 0x832732D0)) { __imp__sub_832732D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832732D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832732D0, 0x832732D0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__51(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__50 = 0x8349D0DCu;
	if (!UseLiftedCode(144, 0x83273308)) { __imp__sub_83273308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273308);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273308, 0x83273308) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__49 = 0x8349D0E0u;
	if (!UseLiftedCode(144, 0x83273340)) { __imp__sub_83273340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273340);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273340, 0x83273340) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__49 = 0x8349D0E4u;
	if (!UseLiftedCode(144, 0x83273378)) { __imp__sub_83273378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273378);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273378, 0x83273378) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__50 = 0x8349D0E8u;
	if (!UseLiftedCode(144, 0x832733B0)) { __imp__sub_832733B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832733B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832733B0, 0x832733B0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__49 = 0x8349D0ECu;
	if (!UseLiftedCode(144, 0x832733E8)) { __imp__sub_832733E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832733E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832733E8, 0x832733E8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__49 = 0x8349D0F0u;
	if (!UseLiftedCode(144, 0x83273420)) { __imp__sub_83273420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273420);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273420, 0x83273420) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__49 = 0x8349D0F4u;
	if (!UseLiftedCode(144, 0x83273458)) { __imp__sub_83273458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273458);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273458, 0x83273458) { ctx.r3.u64 = HashName_TXT_820A2C74_B__49(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__49 = 0x8349D0F8u;
	if (!UseLiftedCode(144, 0x83273490)) { __imp__sub_83273490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273490);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273490, 0x83273490) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__49 = 0x8349D0FCu;
	if (!UseLiftedCode(144, 0x832734C8)) { __imp__sub_832734C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832734C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832734C8, 0x832734C8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__49 = 0x8349D100u;
	if (!UseLiftedCode(144, 0x83273500)) { __imp__sub_83273500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273500);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273500, 0x83273500) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__52 = 0x8349D104u;
	if (!UseLiftedCode(144, 0x83273538)) { __imp__sub_83273538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273538);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273538, 0x83273538) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__49 = 0x8349D108u;
	if (!UseLiftedCode(144, 0x83273570)) { __imp__sub_83273570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273570);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273570, 0x83273570) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__49 = 0x8349D10Cu;
	if (!UseLiftedCode(144, 0x832735A8)) { __imp__sub_832735A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832735A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832735A8, 0x832735A8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__49(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__49 = 0x8349D110u;
	if (!UseLiftedCode(144, 0x832735E0)) { __imp__sub_832735E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832735E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832735E0, 0x832735E0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__49(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__49 = 0x8349D114u;
	if (!UseLiftedCode(144, 0x83273618)) { __imp__sub_83273618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273618);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273618, 0x83273618) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__50 = 0x8349D118u;
	if (!UseLiftedCode(144, 0x83273650)) { __imp__sub_83273650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273650, 0x83273650) { ctx.r3.u64 = HashName_TXT_820A2D24_B__50(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__49 = 0x8349D11Cu;
	if (!UseLiftedCode(144, 0x83273688)) { __imp__sub_83273688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273688, 0x83273688) { ctx.r3.u64 = HashName_TXT_820A2D30_B__49(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__49 = 0x8349D120u;
	if (!UseLiftedCode(144, 0x832736C0)) { __imp__sub_832736C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832736C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832736C0, 0x832736C0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__49(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__49(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__49 = 0x8349D124u;
	if (!UseLiftedCode(144, 0x832736F8)) { __imp__sub_832736F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832736F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__49, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832736F8, 0x832736F8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__49(ctx, base); }

uint64_t Construct_TXT_8349D128_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D128_G_ = int32_t(0x8349D128);
	constexpr int32_t str_TXT_820E6444_B_ = int32_t(0x820E6444);
	constexpr int32_t Destroy_TXT_8349D128_G__address = int32_t(0x832A9080);
	if (!UseLiftedCode(144, 0x83273730)) { __imp__sub_83273730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D128_G_, str_TXT_820E6444_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D128_G__address);
}
PROMOTED_ENTRY(144, sub_83273730, 0x83273730) { ctx.r3.u64 = Construct_TXT_8349D128_G_(ctx, base); }

uint64_t Construct_TXT_8349D12C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D12C_G_ = int32_t(0x8349D12C);
	constexpr int32_t str_TXT_820E6470_B_ = int32_t(0x820E6470);
	constexpr int32_t Destroy_TXT_8349D12C_G__address = int32_t(0x832A9090);
	if (!UseLiftedCode(144, 0x83273770)) { __imp__sub_83273770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D12C_G_, str_TXT_820E6470_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D12C_G__address);
}
PROMOTED_ENTRY(144, sub_83273770, 0x83273770) { ctx.r3.u64 = Construct_TXT_8349D12C_G_(ctx, base); }

uint64_t Construct_TXT_8349D130_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D130_G_ = int32_t(0x8349D130);
	constexpr int32_t str_TXT_820E6470_B_ = int32_t(0x820E64AC);
	constexpr int32_t Destroy_TXT_8349D130_G__address = int32_t(0x832A90A0);
	if (!UseLiftedCode(144, 0x832737B0)) { __imp__sub_832737B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832737B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D130_G_, str_TXT_820E6470_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D130_G__address);
}
PROMOTED_ENTRY(144, sub_832737B0, 0x832737B0) { ctx.r3.u64 = Construct_TXT_8349D130_G_(ctx, base); }

uint64_t Construct_TXT_8349D138_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D138_G_ = int32_t(0x8349D138);
	constexpr int32_t str_TXT_820E6470_B_ = int32_t(0x820E64E8);
	constexpr int32_t Destroy_TXT_8349D138_G__address = int32_t(0x832A90C0);
	if (!UseLiftedCode(144, 0x83273830)) { __imp__sub_83273830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D138_G_, str_TXT_820E6470_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D138_G__address);
}
PROMOTED_ENTRY(144, sub_83273830, 0x83273830) { ctx.r3.u64 = Construct_TXT_8349D138_G_(ctx, base); }

uint64_t Construct_TXT_8349D13C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D13C_G_ = int32_t(0x8349D13C);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D13C_G__address = int32_t(0x832A90D0);
	if (!UseLiftedCode(144, 0x83273870)) { __imp__sub_83273870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D13C_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D13C_G__address);
}
PROMOTED_ENTRY(144, sub_83273870, 0x83273870) { ctx.r3.u64 = Construct_TXT_8349D13C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__50 = 0x8349D140u;
	if (!UseLiftedCode(144, 0x832738B0)) { __imp__sub_832738B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832738B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832738B0, 0x832738B0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__50(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__52 = 0x8349D144u;
	if (!UseLiftedCode(144, 0x832738E8)) { __imp__sub_832738E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832738E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832738E8, 0x832738E8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__52(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__51 = 0x8349D148u;
	if (!UseLiftedCode(144, 0x83273920)) { __imp__sub_83273920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273920);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273920, 0x83273920) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__50 = 0x8349D14Cu;
	if (!UseLiftedCode(144, 0x83273958)) { __imp__sub_83273958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273958);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273958, 0x83273958) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__50 = 0x8349D150u;
	if (!UseLiftedCode(144, 0x83273990)) { __imp__sub_83273990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273990);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273990, 0x83273990) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__51 = 0x8349D154u;
	if (!UseLiftedCode(144, 0x832739C8)) { __imp__sub_832739C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832739C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832739C8, 0x832739C8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__50 = 0x8349D158u;
	if (!UseLiftedCode(144, 0x83273A00)) { __imp__sub_83273A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273A00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273A00, 0x83273A00) { ctx.r3.u64 = HashName_TXT_820A2C44_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__50 = 0x8349D15Cu;
	if (!UseLiftedCode(144, 0x83273A38)) { __imp__sub_83273A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273A38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273A38, 0x83273A38) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__50 = 0x8349D160u;
	if (!UseLiftedCode(144, 0x83273A70)) { __imp__sub_83273A70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273A70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273A70, 0x83273A70) { ctx.r3.u64 = HashName_TXT_820A2C74_B__50(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__50 = 0x8349D164u;
	if (!UseLiftedCode(144, 0x83273AA8)) { __imp__sub_83273AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273AA8, 0x83273AA8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__50 = 0x8349D168u;
	if (!UseLiftedCode(144, 0x83273AE0)) { __imp__sub_83273AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273AE0, 0x83273AE0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__50 = 0x8349D16Cu;
	if (!UseLiftedCode(144, 0x83273B18)) { __imp__sub_83273B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273B18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273B18, 0x83273B18) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__53 = 0x8349D170u;
	if (!UseLiftedCode(144, 0x83273B50)) { __imp__sub_83273B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273B50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273B50, 0x83273B50) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__50 = 0x8349D174u;
	if (!UseLiftedCode(144, 0x83273B88)) { __imp__sub_83273B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273B88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273B88, 0x83273B88) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__50 = 0x8349D178u;
	if (!UseLiftedCode(144, 0x83273BC0)) { __imp__sub_83273BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273BC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273BC0, 0x83273BC0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__50(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__50 = 0x8349D17Cu;
	if (!UseLiftedCode(144, 0x83273BF8)) { __imp__sub_83273BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273BF8, 0x83273BF8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__50(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__50 = 0x8349D180u;
	if (!UseLiftedCode(144, 0x83273C30)) { __imp__sub_83273C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273C30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273C30, 0x83273C30) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__51 = 0x8349D184u;
	if (!UseLiftedCode(144, 0x83273C68)) { __imp__sub_83273C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273C68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273C68, 0x83273C68) { ctx.r3.u64 = HashName_TXT_820A2D24_B__51(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__50 = 0x8349D188u;
	if (!UseLiftedCode(144, 0x83273CA0)) { __imp__sub_83273CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273CA0, 0x83273CA0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__50(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__50 = 0x8349D18Cu;
	if (!UseLiftedCode(144, 0x83273CD8)) { __imp__sub_83273CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273CD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273CD8, 0x83273CD8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__50(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__50 = 0x8349D190u;
	if (!UseLiftedCode(144, 0x83273D10)) { __imp__sub_83273D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273D10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__50, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83273D10, 0x83273D10) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__50(ctx, base); }

uint64_t Construct_TXT_8349D194_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D194_G_ = int32_t(0x8349D194);
	constexpr int32_t str_TXT_820E1DC4_B_ = int32_t(0x820E1DC4);
	constexpr int32_t Destroy_TXT_8349D194_G__address = int32_t(0x832A90E0);
	if (!UseLiftedCode(144, 0x83273D48)) { __imp__sub_83273D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273D48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D194_G_, str_TXT_820E1DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D194_G__address);
}
PROMOTED_ENTRY(144, sub_83273D48, 0x83273D48) { ctx.r3.u64 = Construct_TXT_8349D194_G_(ctx, base); }

uint64_t Construct_TXT_8349D198_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D198_G_ = int32_t(0x8349D198);
	constexpr int32_t str_TXT_820E1D94_B_ = int32_t(0x820E1D94);
	constexpr int32_t Destroy_TXT_8349D198_G__address = int32_t(0x832A90F0);
	if (!UseLiftedCode(144, 0x83273D88)) { __imp__sub_83273D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D198_G_, str_TXT_820E1D94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D198_G__address);
}
PROMOTED_ENTRY(144, sub_83273D88, 0x83273D88) { ctx.r3.u64 = Construct_TXT_8349D198_G_(ctx, base); }

uint64_t Construct_TXT_8349D19C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D19C_G_ = int32_t(0x8349D19C);
	constexpr int32_t str_TXT_820E6620_B_ = int32_t(0x820E6620);
	constexpr int32_t Destroy_TXT_8349D19C_G__address = int32_t(0x832A9100);
	if (!UseLiftedCode(144, 0x83273DC8)) { __imp__sub_83273DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D19C_G_, str_TXT_820E6620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D19C_G__address);
}
PROMOTED_ENTRY(144, sub_83273DC8, 0x83273DC8) { ctx.r3.u64 = Construct_TXT_8349D19C_G_(ctx, base); }

uint64_t Construct_TXT_8349D1A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1A0_G_ = int32_t(0x8349D1A0);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F48);
	constexpr int32_t Destroy_TXT_8349D1A0_G__address = int32_t(0x832A9110);
	if (!UseLiftedCode(144, 0x83273E08)) { __imp__sub_83273E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1A0_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1A0_G__address);
}
PROMOTED_ENTRY(144, sub_83273E08, 0x83273E08) { ctx.r3.u64 = Construct_TXT_8349D1A0_G_(ctx, base); }

uint64_t Construct_TXT_8349D1A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1A8_G_ = int32_t(0x8349D1A8);
	constexpr int32_t str_TXT_820E6658_B_ = int32_t(0x820E6658);
	constexpr int32_t Destroy_TXT_8349D1A8_G__address = int32_t(0x832A9130);
	if (!UseLiftedCode(144, 0x83273E88)) { __imp__sub_83273E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1A8_G_, str_TXT_820E6658_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1A8_G__address);
}
PROMOTED_ENTRY(144, sub_83273E88, 0x83273E88) { ctx.r3.u64 = Construct_TXT_8349D1A8_G_(ctx, base); }

uint64_t Construct_TXT_8349D1AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1AC_G_ = int32_t(0x8349D1AC);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F8C);
	constexpr int32_t Destroy_TXT_8349D1AC_G__address = int32_t(0x832A9140);
	if (!UseLiftedCode(144, 0x83273EC8)) { __imp__sub_83273EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1AC_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1AC_G__address);
}
PROMOTED_ENTRY(144, sub_83273EC8, 0x83273EC8) { ctx.r3.u64 = Construct_TXT_8349D1AC_G_(ctx, base); }

uint64_t Construct_TXT_8349D1B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1B0_G_ = int32_t(0x8349D1B0);
	constexpr int32_t str_TXT_820E66D4_B_ = int32_t(0x820E66D4);
	constexpr int32_t Destroy_TXT_8349D1B0_G__address = int32_t(0x832A9150);
	if (!UseLiftedCode(144, 0x83273F08)) { __imp__sub_83273F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B0_G_, str_TXT_820E66D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1B0_G__address);
}
PROMOTED_ENTRY(144, sub_83273F08, 0x83273F08) { ctx.r3.u64 = Construct_TXT_8349D1B0_G_(ctx, base); }

uint64_t Construct_TXT_8349D1B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1B4_G_ = int32_t(0x8349D1B4);
	constexpr int32_t str_TXT_820E66D4_B_ = int32_t(0x820E6708);
	constexpr int32_t Destroy_TXT_8349D1B4_G__address = int32_t(0x832A9160);
	if (!UseLiftedCode(144, 0x83273F48)) { __imp__sub_83273F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B4_G_, str_TXT_820E66D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1B4_G__address);
}
PROMOTED_ENTRY(144, sub_83273F48, 0x83273F48) { ctx.r3.u64 = Construct_TXT_8349D1B4_G_(ctx, base); }

uint64_t Construct_TXT_8349D1B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1B8_G_ = int32_t(0x8349D1B8);
	constexpr int32_t str_TXT_820E66D4_B_ = int32_t(0x820E673C);
	constexpr int32_t Destroy_TXT_8349D1B8_G__address = int32_t(0x832A9170);
	if (!UseLiftedCode(144, 0x83273F88)) { __imp__sub_83273F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B8_G_, str_TXT_820E66D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1B8_G__address);
}
PROMOTED_ENTRY(144, sub_83273F88, 0x83273F88) { ctx.r3.u64 = Construct_TXT_8349D1B8_G_(ctx, base); }

uint64_t Construct_TXT_8349D1BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1BC_G_ = int32_t(0x8349D1BC);
	constexpr int32_t str_TXT_820E66D4_B_ = int32_t(0x820E2004);
	constexpr int32_t Destroy_TXT_8349D1BC_G__address = int32_t(0x832A9180);
	if (!UseLiftedCode(144, 0x83273FC8)) { __imp__sub_83273FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1BC_G_, str_TXT_820E66D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1BC_G__address);
}
PROMOTED_ENTRY(144, sub_83273FC8, 0x83273FC8) { ctx.r3.u64 = Construct_TXT_8349D1BC_G_(ctx, base); }

uint64_t Construct_TXT_8349D1C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1C0_G_ = int32_t(0x8349D1C0);
	constexpr int32_t str_TXT_820E66D4_B_ = int32_t(0x820E6770);
	constexpr int32_t Destroy_TXT_8349D1C0_G__address = int32_t(0x832A9190);
	if (!UseLiftedCode(144, 0x83274008)) { __imp__sub_83274008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1C0_G_, str_TXT_820E66D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1C0_G__address);
}
PROMOTED_ENTRY(144, sub_83274008, 0x83274008) { ctx.r3.u64 = Construct_TXT_8349D1C0_G_(ctx, base); }

uint64_t Construct_TXT_8349D1C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D1C4_G_ = int32_t(0x8349D1C4);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E20);
	constexpr int32_t Destroy_TXT_8349D1C4_G__address = int32_t(0x832A91A0);
	if (!UseLiftedCode(144, 0x83274048)) { __imp__sub_83274048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1C4_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D1C4_G__address);
}
PROMOTED_ENTRY(144, sub_83274048, 0x83274048) { ctx.r3.u64 = Construct_TXT_8349D1C4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__51 = 0x8349D1C8u;
	if (!UseLiftedCode(144, 0x83274088)) { __imp__sub_83274088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274088);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274088, 0x83274088) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__51(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__53 = 0x8349D1CCu;
	if (!UseLiftedCode(144, 0x832740C0)) { __imp__sub_832740C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832740C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832740C0, 0x832740C0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__53(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__52 = 0x8349D1D0u;
	if (!UseLiftedCode(144, 0x832740F8)) { __imp__sub_832740F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832740F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832740F8, 0x832740F8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__51 = 0x8349D1D4u;
	if (!UseLiftedCode(144, 0x83274130)) { __imp__sub_83274130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274130, 0x83274130) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__51 = 0x8349D1D8u;
	if (!UseLiftedCode(144, 0x83274168)) { __imp__sub_83274168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274168, 0x83274168) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__52 = 0x8349D1DCu;
	if (!UseLiftedCode(144, 0x832741A0)) { __imp__sub_832741A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832741A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832741A0, 0x832741A0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__51 = 0x8349D1E0u;
	if (!UseLiftedCode(144, 0x832741D8)) { __imp__sub_832741D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832741D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832741D8, 0x832741D8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__51 = 0x8349D1E4u;
	if (!UseLiftedCode(144, 0x83274210)) { __imp__sub_83274210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274210, 0x83274210) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__51 = 0x8349D1E8u;
	if (!UseLiftedCode(144, 0x83274248)) { __imp__sub_83274248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274248, 0x83274248) { ctx.r3.u64 = HashName_TXT_820A2C74_B__51(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__51 = 0x8349D1ECu;
	if (!UseLiftedCode(144, 0x83274280)) { __imp__sub_83274280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274280, 0x83274280) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__51 = 0x8349D1F0u;
	if (!UseLiftedCode(144, 0x832742B8)) { __imp__sub_832742B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832742B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832742B8, 0x832742B8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__51 = 0x8349D1F4u;
	if (!UseLiftedCode(144, 0x832742F0)) { __imp__sub_832742F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832742F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832742F0, 0x832742F0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__54 = 0x8349D1F8u;
	if (!UseLiftedCode(144, 0x83274328)) { __imp__sub_83274328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274328, 0x83274328) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__51 = 0x8349D1FCu;
	if (!UseLiftedCode(144, 0x83274360)) { __imp__sub_83274360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274360, 0x83274360) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__51 = 0x8349D200u;
	if (!UseLiftedCode(144, 0x83274398)) { __imp__sub_83274398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274398, 0x83274398) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__51(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__51 = 0x8349D204u;
	if (!UseLiftedCode(144, 0x832743D0)) { __imp__sub_832743D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832743D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832743D0, 0x832743D0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__51(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__51 = 0x8349D208u;
	if (!UseLiftedCode(144, 0x83274408)) { __imp__sub_83274408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274408);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274408, 0x83274408) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__52 = 0x8349D20Cu;
	if (!UseLiftedCode(144, 0x83274440)) { __imp__sub_83274440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274440, 0x83274440) { ctx.r3.u64 = HashName_TXT_820A2D24_B__52(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__51 = 0x8349D210u;
	if (!UseLiftedCode(144, 0x83274478)) { __imp__sub_83274478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274478, 0x83274478) { ctx.r3.u64 = HashName_TXT_820A2D30_B__51(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__51 = 0x8349D214u;
	if (!UseLiftedCode(144, 0x832744B0)) { __imp__sub_832744B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832744B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832744B0, 0x832744B0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__51(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__51(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__51 = 0x8349D218u;
	if (!UseLiftedCode(144, 0x832744E8)) { __imp__sub_832744E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832744E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__51, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832744E8, 0x832744E8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__51(ctx, base); }

uint64_t Construct_TXT_8349D21C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D21C_G_ = int32_t(0x8349D21C);
	constexpr int32_t str_TXT_820E235C_B_ = int32_t(0x820E235C);
	constexpr int32_t Destroy_TXT_8349D21C_G__address = int32_t(0x832A91B0);
	if (!UseLiftedCode(144, 0x83274520)) { __imp__sub_83274520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274520);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D21C_G_, str_TXT_820E235C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D21C_G__address);
}
PROMOTED_ENTRY(144, sub_83274520, 0x83274520) { ctx.r3.u64 = Construct_TXT_8349D21C_G_(ctx, base); }

uint64_t Construct_TXT_8349D220_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D220_G_ = int32_t(0x8349D220);
	constexpr int32_t str_TXT_820E2420_B_ = int32_t(0x820E2420);
	constexpr int32_t Destroy_TXT_8349D220_G__address = int32_t(0x832A91C0);
	if (!UseLiftedCode(144, 0x83274560)) { __imp__sub_83274560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274560);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D220_G_, str_TXT_820E2420_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D220_G__address);
}
PROMOTED_ENTRY(144, sub_83274560, 0x83274560) { ctx.r3.u64 = Construct_TXT_8349D220_G_(ctx, base); }

uint64_t Construct_TXT_8349D224_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D224_G_ = int32_t(0x8349D224);
	constexpr int32_t str_TXT_820E6830_B_ = int32_t(0x820E6830);
	constexpr int32_t Destroy_TXT_8349D224_G__address = int32_t(0x832A91D0);
	if (!UseLiftedCode(144, 0x832745A0)) { __imp__sub_832745A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832745A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D224_G_, str_TXT_820E6830_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D224_G__address);
}
PROMOTED_ENTRY(144, sub_832745A0, 0x832745A0) { ctx.r3.u64 = Construct_TXT_8349D224_G_(ctx, base); }

uint64_t Construct_TXT_8349D228_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D228_G_ = int32_t(0x8349D228);
	constexpr int32_t str_TXT_820E67CC_B_ = int32_t(0x820E67CC);
	constexpr int32_t Destroy_TXT_8349D228_G__address = int32_t(0x832A91E0);
	if (!UseLiftedCode(144, 0x832745E0)) { __imp__sub_832745E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832745E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D228_G_, str_TXT_820E67CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D228_G__address);
}
PROMOTED_ENTRY(144, sub_832745E0, 0x832745E0) { ctx.r3.u64 = Construct_TXT_8349D228_G_(ctx, base); }

uint64_t Construct_TXT_8349D22C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D22C_G_ = int32_t(0x8349D22C);
	constexpr int32_t str_TXT_820E67AC_B_ = int32_t(0x820E67AC);
	constexpr int32_t Destroy_TXT_8349D22C_G__address = int32_t(0x832A91F0);
	if (!UseLiftedCode(144, 0x83274620)) { __imp__sub_83274620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274620);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D22C_G_, str_TXT_820E67AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D22C_G__address);
}
PROMOTED_ENTRY(144, sub_83274620, 0x83274620) { ctx.r3.u64 = Construct_TXT_8349D22C_G_(ctx, base); }

uint64_t Construct_TXT_8349D230_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D230_G_ = int32_t(0x8349D230);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D230_G__address = int32_t(0x832A9200);
	if (!UseLiftedCode(144, 0x83274660)) { __imp__sub_83274660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274660);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D230_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D230_G__address);
}
PROMOTED_ENTRY(144, sub_83274660, 0x83274660) { ctx.r3.u64 = Construct_TXT_8349D230_G_(ctx, base); }

uint64_t Construct_TXT_8349D234_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D234_G_ = int32_t(0x8349D234);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E24BC);
	constexpr int32_t Destroy_TXT_8349D234_G__address = int32_t(0x832A9210);
	if (!UseLiftedCode(144, 0x832746A0)) { __imp__sub_832746A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832746A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D234_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D234_G__address);
}
PROMOTED_ENTRY(144, sub_832746A0, 0x832746A0) { ctx.r3.u64 = Construct_TXT_8349D234_G_(ctx, base); }

uint64_t Construct_TXT_8349D238_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D238_G_ = int32_t(0x8349D238);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E6868);
	constexpr int32_t Destroy_TXT_8349D238_G__address = int32_t(0x832A9220);
	if (!UseLiftedCode(144, 0x832746E0)) { __imp__sub_832746E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832746E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D238_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D238_G__address);
}
PROMOTED_ENTRY(144, sub_832746E0, 0x832746E0) { ctx.r3.u64 = Construct_TXT_8349D238_G_(ctx, base); }

uint64_t Construct_TXT_8349D23C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D23C_G_ = int32_t(0x8349D23C);
	constexpr int32_t str_TXT_820E68B4_B_ = int32_t(0x820E68B4);
	constexpr int32_t Destroy_TXT_8349D23C_G__address = int32_t(0x832A9230);
	if (!UseLiftedCode(144, 0x83274720)) { __imp__sub_83274720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274720);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D23C_G_, str_TXT_820E68B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D23C_G__address);
}
PROMOTED_ENTRY(144, sub_83274720, 0x83274720) { ctx.r3.u64 = Construct_TXT_8349D23C_G_(ctx, base); }

uint64_t Construct_TXT_8349D240_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D240_G_ = int32_t(0x8349D240);
	constexpr int32_t str_TXT_820E68B4_B_ = int32_t(0x820E68E8);
	constexpr int32_t Destroy_TXT_8349D240_G__address = int32_t(0x832A9240);
	if (!UseLiftedCode(144, 0x83274760)) { __imp__sub_83274760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274760);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D240_G_, str_TXT_820E68B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D240_G__address);
}
PROMOTED_ENTRY(144, sub_83274760, 0x83274760) { ctx.r3.u64 = Construct_TXT_8349D240_G_(ctx, base); }

uint64_t Construct_TXT_8349D244_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D244_G_ = int32_t(0x8349D244);
	constexpr int32_t str_TXT_820E68B4_B_ = int32_t(0x820E691C);
	constexpr int32_t Destroy_TXT_8349D244_G__address = int32_t(0x832A9250);
	if (!UseLiftedCode(144, 0x832747A0)) { __imp__sub_832747A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832747A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D244_G_, str_TXT_820E68B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D244_G__address);
}
PROMOTED_ENTRY(144, sub_832747A0, 0x832747A0) { ctx.r3.u64 = Construct_TXT_8349D244_G_(ctx, base); }

uint64_t Construct_TXT_8349D248_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D248_G_ = int32_t(0x8349D248);
	constexpr int32_t str_TXT_820E68B4_B_ = int32_t(0x820E24F8);
	constexpr int32_t Destroy_TXT_8349D248_G__address = int32_t(0x832A9260);
	if (!UseLiftedCode(144, 0x832747E0)) { __imp__sub_832747E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832747E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D248_G_, str_TXT_820E68B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D248_G__address);
}
PROMOTED_ENTRY(144, sub_832747E0, 0x832747E0) { ctx.r3.u64 = Construct_TXT_8349D248_G_(ctx, base); }

uint64_t Construct_TXT_8349D24C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D24C_G_ = int32_t(0x8349D24C);
	constexpr int32_t str_TXT_820E68B4_B_ = int32_t(0x820E6950);
	constexpr int32_t Destroy_TXT_8349D24C_G__address = int32_t(0x832A9270);
	if (!UseLiftedCode(144, 0x83274820)) { __imp__sub_83274820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274820);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D24C_G_, str_TXT_820E68B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D24C_G__address);
}
PROMOTED_ENTRY(144, sub_83274820, 0x83274820) { ctx.r3.u64 = Construct_TXT_8349D24C_G_(ctx, base); }

uint64_t Construct_TXT_8349D250_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D250_G_ = int32_t(0x8349D250);
	constexpr int32_t str_TXT_820E23F0_B_ = int32_t(0x820E23F0);
	constexpr int32_t Destroy_TXT_8349D250_G__address = int32_t(0x832A9280);
	if (!UseLiftedCode(144, 0x83274860)) { __imp__sub_83274860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274860);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D250_G_, str_TXT_820E23F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D250_G__address);
}
PROMOTED_ENTRY(144, sub_83274860, 0x83274860) { ctx.r3.u64 = Construct_TXT_8349D250_G_(ctx, base); }

uint64_t Construct_TXT_8349D254_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D254_G_ = int32_t(0x8349D254);
	constexpr int32_t str_TXT_820E23BC_B_ = int32_t(0x820E23BC);
	constexpr int32_t Destroy_TXT_8349D254_G__address = int32_t(0x832A9290);
	if (!UseLiftedCode(144, 0x832748A0)) { __imp__sub_832748A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832748A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D254_G_, str_TXT_820E23BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D254_G__address);
}
PROMOTED_ENTRY(144, sub_832748A0, 0x832748A0) { ctx.r3.u64 = Construct_TXT_8349D254_G_(ctx, base); }

uint64_t Construct_TXT_8349D258_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D258_G_ = int32_t(0x8349D258);
	constexpr int32_t str_TXT_820E238C_B_ = int32_t(0x820E238C);
	constexpr int32_t Destroy_TXT_8349D258_G__address = int32_t(0x832A92A0);
	if (!UseLiftedCode(144, 0x832748E0)) { __imp__sub_832748E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832748E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D258_G_, str_TXT_820E238C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D258_G__address);
}
PROMOTED_ENTRY(144, sub_832748E0, 0x832748E0) { ctx.r3.u64 = Construct_TXT_8349D258_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__52 = 0x8349D260u;
	if (!UseLiftedCode(144, 0x83274960)) { __imp__sub_83274960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274960, 0x83274960) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__52(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__54 = 0x8349D264u;
	if (!UseLiftedCode(144, 0x83274998)) { __imp__sub_83274998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274998, 0x83274998) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__54(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__53 = 0x8349D268u;
	if (!UseLiftedCode(144, 0x832749D0)) { __imp__sub_832749D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832749D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832749D0, 0x832749D0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__52 = 0x8349D26Cu;
	if (!UseLiftedCode(144, 0x83274A08)) { __imp__sub_83274A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274A08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274A08, 0x83274A08) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__52 = 0x8349D270u;
	if (!UseLiftedCode(144, 0x83274A40)) { __imp__sub_83274A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274A40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274A40, 0x83274A40) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__53 = 0x8349D274u;
	if (!UseLiftedCode(144, 0x83274A78)) { __imp__sub_83274A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274A78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274A78, 0x83274A78) { ctx.r3.u64 = HashName_TXT_820A2C34_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__52 = 0x8349D278u;
	if (!UseLiftedCode(144, 0x83274AB0)) { __imp__sub_83274AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274AB0, 0x83274AB0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__52 = 0x8349D27Cu;
	if (!UseLiftedCode(144, 0x83274AE8)) { __imp__sub_83274AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274AE8, 0x83274AE8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__52 = 0x8349D280u;
	if (!UseLiftedCode(144, 0x83274B20)) { __imp__sub_83274B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274B20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274B20, 0x83274B20) { ctx.r3.u64 = HashName_TXT_820A2C74_B__52(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__52 = 0x8349D284u;
	if (!UseLiftedCode(144, 0x83274B58)) { __imp__sub_83274B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274B58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274B58, 0x83274B58) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__52 = 0x8349D288u;
	if (!UseLiftedCode(144, 0x83274B90)) { __imp__sub_83274B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274B90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274B90, 0x83274B90) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__52 = 0x8349D28Cu;
	if (!UseLiftedCode(144, 0x83274BC8)) { __imp__sub_83274BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274BC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274BC8, 0x83274BC8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__55 = 0x8349D290u;
	if (!UseLiftedCode(144, 0x83274C00)) { __imp__sub_83274C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274C00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274C00, 0x83274C00) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__52 = 0x8349D294u;
	if (!UseLiftedCode(144, 0x83274C38)) { __imp__sub_83274C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274C38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274C38, 0x83274C38) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__52 = 0x8349D298u;
	if (!UseLiftedCode(144, 0x83274C70)) { __imp__sub_83274C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274C70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274C70, 0x83274C70) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__52(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__52 = 0x8349D29Cu;
	if (!UseLiftedCode(144, 0x83274CA8)) { __imp__sub_83274CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274CA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274CA8, 0x83274CA8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__52(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__52 = 0x8349D2A0u;
	if (!UseLiftedCode(144, 0x83274CE0)) { __imp__sub_83274CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274CE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274CE0, 0x83274CE0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__53 = 0x8349D2A4u;
	if (!UseLiftedCode(144, 0x83274D18)) { __imp__sub_83274D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274D18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274D18, 0x83274D18) { ctx.r3.u64 = HashName_TXT_820A2D24_B__53(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__52 = 0x8349D2A8u;
	if (!UseLiftedCode(144, 0x83274D50)) { __imp__sub_83274D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274D50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274D50, 0x83274D50) { ctx.r3.u64 = HashName_TXT_820A2D30_B__52(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__52 = 0x8349D2ACu;
	if (!UseLiftedCode(144, 0x83274D88)) { __imp__sub_83274D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274D88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274D88, 0x83274D88) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__52(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__52(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__52 = 0x8349D2B0u;
	if (!UseLiftedCode(144, 0x83274DC0)) { __imp__sub_83274DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274DC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__52, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274DC0, 0x83274DC0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__52(ctx, base); }

uint64_t Construct_TXT_8349D2B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D2B8_G_ = int32_t(0x8349D2B8);
	constexpr int32_t str_TXT_820E69EC_B_ = int32_t(0x820E69EC);
	constexpr int32_t Destroy_TXT_8349D2B8_G__address = int32_t(0x832A92D0);
	if (!UseLiftedCode(144, 0x83274E38)) { __imp__sub_83274E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2B8_G_, str_TXT_820E69EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D2B8_G__address);
}
PROMOTED_ENTRY(144, sub_83274E38, 0x83274E38) { ctx.r3.u64 = Construct_TXT_8349D2B8_G_(ctx, base); }

uint64_t Construct_TXT_8349D2BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D2BC_G_ = int32_t(0x8349D2BC);
	constexpr int32_t str_TXT_820E69F4_B_ = int32_t(0x820E69F4);
	constexpr int32_t Destroy_TXT_8349D2BC_G__address = int32_t(0x832A92E0);
	if (!UseLiftedCode(144, 0x83274E78)) { __imp__sub_83274E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2BC_G_, str_TXT_820E69F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D2BC_G__address);
}
PROMOTED_ENTRY(144, sub_83274E78, 0x83274E78) { ctx.r3.u64 = Construct_TXT_8349D2BC_G_(ctx, base); }

uint64_t Construct_TXT_8349D2C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D2C0_G_ = int32_t(0x8349D2C0);
	constexpr int32_t str_TXT_820E69FC_B_ = int32_t(0x820E69FC);
	constexpr int32_t Destroy_TXT_8349D2C0_G__address = int32_t(0x832A92F0);
	if (!UseLiftedCode(144, 0x83274EB8)) { __imp__sub_83274EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2C0_G_, str_TXT_820E69FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D2C0_G__address);
}
PROMOTED_ENTRY(144, sub_83274EB8, 0x83274EB8) { ctx.r3.u64 = Construct_TXT_8349D2C0_G_(ctx, base); }

uint64_t Construct_TXT_8349D2C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D2C8_G_ = int32_t(0x8349D2C8);
	constexpr int32_t str_TXT_820DD044_B_ = int32_t(0x820DD044);
	constexpr int32_t Destroy_TXT_8349D2C8_G__address = int32_t(0x832A9310);
	if (!UseLiftedCode(144, 0x83274F38)) { __imp__sub_83274F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2C8_G_, str_TXT_820DD044_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D2C8_G__address);
}
PROMOTED_ENTRY(144, sub_83274F38, 0x83274F38) { ctx.r3.u64 = Construct_TXT_8349D2C8_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__53 = 0x8349D2CCu;
	if (!UseLiftedCode(144, 0x83274F78)) { __imp__sub_83274F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274F78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274F78, 0x83274F78) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__53(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__55 = 0x8349D2D0u;
	if (!UseLiftedCode(144, 0x83274FB0)) { __imp__sub_83274FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274FB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274FB0, 0x83274FB0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__55(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__54 = 0x8349D2D4u;
	if (!UseLiftedCode(144, 0x83274FE8)) { __imp__sub_83274FE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274FE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83274FE8, 0x83274FE8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__53 = 0x8349D2D8u;
	if (!UseLiftedCode(144, 0x83275020)) { __imp__sub_83275020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275020);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275020, 0x83275020) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__53 = 0x8349D2DCu;
	if (!UseLiftedCode(144, 0x83275058)) { __imp__sub_83275058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275058);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275058, 0x83275058) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__54 = 0x8349D2E0u;
	if (!UseLiftedCode(144, 0x83275090)) { __imp__sub_83275090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275090);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275090, 0x83275090) { ctx.r3.u64 = HashName_TXT_820A2C34_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__53 = 0x8349D2E4u;
	if (!UseLiftedCode(144, 0x832750C8)) { __imp__sub_832750C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832750C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832750C8, 0x832750C8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__53 = 0x8349D2E8u;
	if (!UseLiftedCode(144, 0x83275100)) { __imp__sub_83275100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275100);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275100, 0x83275100) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__53 = 0x8349D2ECu;
	if (!UseLiftedCode(144, 0x83275138)) { __imp__sub_83275138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275138);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275138, 0x83275138) { ctx.r3.u64 = HashName_TXT_820A2C74_B__53(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__53 = 0x8349D2F0u;
	if (!UseLiftedCode(144, 0x83275170)) { __imp__sub_83275170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275170);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275170, 0x83275170) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__53 = 0x8349D2F4u;
	if (!UseLiftedCode(144, 0x832751A8)) { __imp__sub_832751A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832751A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832751A8, 0x832751A8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__53 = 0x8349D2F8u;
	if (!UseLiftedCode(144, 0x832751E0)) { __imp__sub_832751E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832751E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832751E0, 0x832751E0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__56 = 0x8349D2FCu;
	if (!UseLiftedCode(144, 0x83275218)) { __imp__sub_83275218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275218);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275218, 0x83275218) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__53 = 0x8349D300u;
	if (!UseLiftedCode(144, 0x83275250)) { __imp__sub_83275250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275250);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275250, 0x83275250) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__53 = 0x8349D304u;
	if (!UseLiftedCode(144, 0x83275288)) { __imp__sub_83275288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275288);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275288, 0x83275288) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__53(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__53 = 0x8349D308u;
	if (!UseLiftedCode(144, 0x832752C0)) { __imp__sub_832752C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832752C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832752C0, 0x832752C0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__53(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__53 = 0x8349D30Cu;
	if (!UseLiftedCode(144, 0x832752F8)) { __imp__sub_832752F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832752F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832752F8, 0x832752F8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__54 = 0x8349D310u;
	if (!UseLiftedCode(144, 0x83275330)) { __imp__sub_83275330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275330);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275330, 0x83275330) { ctx.r3.u64 = HashName_TXT_820A2D24_B__54(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__53 = 0x8349D314u;
	if (!UseLiftedCode(144, 0x83275368)) { __imp__sub_83275368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275368);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275368, 0x83275368) { ctx.r3.u64 = HashName_TXT_820A2D30_B__53(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__53 = 0x8349D318u;
	if (!UseLiftedCode(144, 0x832753A0)) { __imp__sub_832753A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832753A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832753A0, 0x832753A0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__53(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__53 = 0x8349D31Cu;
	if (!UseLiftedCode(144, 0x832753D8)) { __imp__sub_832753D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832753D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__53, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832753D8, 0x832753D8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__53(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__54 = 0x8349D344u;
	if (!UseLiftedCode(144, 0x83275650)) { __imp__sub_83275650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275650, 0x83275650) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__54(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__56 = 0x8349D348u;
	if (!UseLiftedCode(144, 0x83275688)) { __imp__sub_83275688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275688, 0x83275688) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__56(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__55 = 0x8349D34Cu;
	if (!UseLiftedCode(144, 0x832756C0)) { __imp__sub_832756C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832756C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832756C0, 0x832756C0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__54 = 0x8349D350u;
	if (!UseLiftedCode(144, 0x832756F8)) { __imp__sub_832756F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832756F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832756F8, 0x832756F8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__54 = 0x8349D354u;
	if (!UseLiftedCode(144, 0x83275730)) { __imp__sub_83275730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275730, 0x83275730) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__55 = 0x8349D358u;
	if (!UseLiftedCode(144, 0x83275768)) { __imp__sub_83275768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275768, 0x83275768) { ctx.r3.u64 = HashName_TXT_820A2C34_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__54 = 0x8349D35Cu;
	if (!UseLiftedCode(144, 0x832757A0)) { __imp__sub_832757A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832757A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832757A0, 0x832757A0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__54 = 0x8349D360u;
	if (!UseLiftedCode(144, 0x832757D8)) { __imp__sub_832757D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832757D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832757D8, 0x832757D8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__54 = 0x8349D364u;
	if (!UseLiftedCode(144, 0x83275810)) { __imp__sub_83275810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275810, 0x83275810) { ctx.r3.u64 = HashName_TXT_820A2C74_B__54(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__54 = 0x8349D368u;
	if (!UseLiftedCode(144, 0x83275848)) { __imp__sub_83275848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275848, 0x83275848) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__54 = 0x8349D36Cu;
	if (!UseLiftedCode(144, 0x83275880)) { __imp__sub_83275880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275880);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275880, 0x83275880) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__54 = 0x8349D370u;
	if (!UseLiftedCode(144, 0x832758B8)) { __imp__sub_832758B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832758B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832758B8, 0x832758B8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__57 = 0x8349D374u;
	if (!UseLiftedCode(144, 0x832758F0)) { __imp__sub_832758F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832758F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832758F0, 0x832758F0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__54 = 0x8349D378u;
	if (!UseLiftedCode(144, 0x83275928)) { __imp__sub_83275928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275928);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275928, 0x83275928) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__54 = 0x8349D37Cu;
	if (!UseLiftedCode(144, 0x83275960)) { __imp__sub_83275960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275960, 0x83275960) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__54(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__54 = 0x8349D380u;
	if (!UseLiftedCode(144, 0x83275998)) { __imp__sub_83275998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275998, 0x83275998) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__54(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__54 = 0x8349D384u;
	if (!UseLiftedCode(144, 0x832759D0)) { __imp__sub_832759D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832759D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832759D0, 0x832759D0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__55 = 0x8349D388u;
	if (!UseLiftedCode(144, 0x83275A08)) { __imp__sub_83275A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275A08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275A08, 0x83275A08) { ctx.r3.u64 = HashName_TXT_820A2D24_B__55(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__54 = 0x8349D38Cu;
	if (!UseLiftedCode(144, 0x83275A40)) { __imp__sub_83275A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275A40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275A40, 0x83275A40) { ctx.r3.u64 = HashName_TXT_820A2D30_B__54(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__54 = 0x8349D390u;
	if (!UseLiftedCode(144, 0x83275A78)) { __imp__sub_83275A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275A78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275A78, 0x83275A78) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__54(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__54 = 0x8349D394u;
	if (!UseLiftedCode(144, 0x83275AB0)) { __imp__sub_83275AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__54, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275AB0, 0x83275AB0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__54(ctx, base); }

uint64_t Construct_TXT_8349D398_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D398_G_ = int32_t(0x8349D398);
	constexpr int32_t str_TXT_820E6BC0_B_ = int32_t(0x820E6BC0);
	constexpr int32_t Destroy_TXT_8349D398_G__address = int32_t(0x832A93B0);
	if (!UseLiftedCode(144, 0x83275AE8)) { __imp__sub_83275AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D398_G_, str_TXT_820E6BC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D398_G__address);
}
PROMOTED_ENTRY(144, sub_83275AE8, 0x83275AE8) { ctx.r3.u64 = Construct_TXT_8349D398_G_(ctx, base); }

uint64_t Construct_TXT_8349D39C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D39C_G_ = int32_t(0x8349D39C);
	constexpr int32_t str_TXT_820E6BF4_B_ = int32_t(0x820E6BF4);
	constexpr int32_t Destroy_TXT_8349D39C_G__address = int32_t(0x832A93C0);
	if (!UseLiftedCode(144, 0x83275B28)) { __imp__sub_83275B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275B28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D39C_G_, str_TXT_820E6BF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D39C_G__address);
}
PROMOTED_ENTRY(144, sub_83275B28, 0x83275B28) { ctx.r3.u64 = Construct_TXT_8349D39C_G_(ctx, base); }

uint64_t Construct_TXT_8349D3A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3A0_G_ = int32_t(0x8349D3A0);
	constexpr int32_t str_TXT_820E6C24_B_ = int32_t(0x820E6C24);
	constexpr int32_t Destroy_TXT_8349D3A0_G__address = int32_t(0x832A93D0);
	if (!UseLiftedCode(144, 0x83275B68)) { __imp__sub_83275B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275B68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A0_G_, str_TXT_820E6C24_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3A0_G__address);
}
PROMOTED_ENTRY(144, sub_83275B68, 0x83275B68) { ctx.r3.u64 = Construct_TXT_8349D3A0_G_(ctx, base); }

uint64_t Construct_TXT_8349D3A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3A4_G_ = int32_t(0x8349D3A4);
	constexpr int32_t str_TXT_820E6C60_B_ = int32_t(0x820E6C60);
	constexpr int32_t Destroy_TXT_8349D3A4_G__address = int32_t(0x832A93E0);
	if (!UseLiftedCode(144, 0x83275BA8)) { __imp__sub_83275BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275BA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A4_G_, str_TXT_820E6C60_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3A4_G__address);
}
PROMOTED_ENTRY(144, sub_83275BA8, 0x83275BA8) { ctx.r3.u64 = Construct_TXT_8349D3A4_G_(ctx, base); }

uint64_t Construct_TXT_8349D3A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3A8_G_ = int32_t(0x8349D3A8);
	constexpr int32_t str_TXT_820E6C6C_B_ = int32_t(0x820E6C6C);
	constexpr int32_t Destroy_TXT_8349D3A8_G__address = int32_t(0x832A93F0);
	if (!UseLiftedCode(144, 0x83275BE8)) { __imp__sub_83275BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A8_G_, str_TXT_820E6C6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3A8_G__address);
}
PROMOTED_ENTRY(144, sub_83275BE8, 0x83275BE8) { ctx.r3.u64 = Construct_TXT_8349D3A8_G_(ctx, base); }

uint64_t Construct_TXT_8349D3AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3AC_G_ = int32_t(0x8349D3AC);
	constexpr int32_t str_TXT_820E6C98_B_ = int32_t(0x820E6C98);
	constexpr int32_t Destroy_TXT_8349D3AC_G__address = int32_t(0x832A9400);
	if (!UseLiftedCode(144, 0x83275C28)) { __imp__sub_83275C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275C28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3AC_G_, str_TXT_820E6C98_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3AC_G__address);
}
PROMOTED_ENTRY(144, sub_83275C28, 0x83275C28) { ctx.r3.u64 = Construct_TXT_8349D3AC_G_(ctx, base); }

uint64_t Construct_TXT_8349D3B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3B0_G_ = int32_t(0x8349D3B0);
	constexpr int32_t str_TXT_820E6CCC_B_ = int32_t(0x820E6CCC);
	constexpr int32_t Destroy_TXT_8349D3B0_G__address = int32_t(0x832A9410);
	if (!UseLiftedCode(144, 0x83275C68)) { __imp__sub_83275C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275C68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3B0_G_, str_TXT_820E6CCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3B0_G__address);
}
PROMOTED_ENTRY(144, sub_83275C68, 0x83275C68) { ctx.r3.u64 = Construct_TXT_8349D3B0_G_(ctx, base); }

uint64_t Construct_TXT_8349D3B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D3B4_G_ = int32_t(0x8349D3B4);
	constexpr int32_t str_TXT_820E6CF8_B_ = int32_t(0x820E6CF8);
	constexpr int32_t Destroy_TXT_8349D3B4_G__address = int32_t(0x832A9420);
	if (!UseLiftedCode(144, 0x83275CA8)) { __imp__sub_83275CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275CA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3B4_G_, str_TXT_820E6CF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D3B4_G__address);
}
PROMOTED_ENTRY(144, sub_83275CA8, 0x83275CA8) { ctx.r3.u64 = Construct_TXT_8349D3B4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__55 = 0x8349D3B8u;
	if (!UseLiftedCode(144, 0x83275CE8)) { __imp__sub_83275CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275CE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275CE8, 0x83275CE8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__55(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__57 = 0x8349D3BCu;
	if (!UseLiftedCode(144, 0x83275D20)) { __imp__sub_83275D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275D20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275D20, 0x83275D20) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__57(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__56 = 0x8349D3C0u;
	if (!UseLiftedCode(144, 0x83275D58)) { __imp__sub_83275D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275D58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275D58, 0x83275D58) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__55 = 0x8349D3C4u;
	if (!UseLiftedCode(144, 0x83275D90)) { __imp__sub_83275D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275D90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275D90, 0x83275D90) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__55 = 0x8349D3C8u;
	if (!UseLiftedCode(144, 0x83275DC8)) { __imp__sub_83275DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275DC8, 0x83275DC8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__56 = 0x8349D3CCu;
	if (!UseLiftedCode(144, 0x83275E00)) { __imp__sub_83275E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275E00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275E00, 0x83275E00) { ctx.r3.u64 = HashName_TXT_820A2C34_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__55 = 0x8349D3D0u;
	if (!UseLiftedCode(144, 0x83275E38)) { __imp__sub_83275E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275E38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275E38, 0x83275E38) { ctx.r3.u64 = HashName_TXT_820A2C44_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__55 = 0x8349D3D4u;
	if (!UseLiftedCode(144, 0x83275E70)) { __imp__sub_83275E70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275E70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275E70, 0x83275E70) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__55 = 0x8349D3D8u;
	if (!UseLiftedCode(144, 0x83275EA8)) { __imp__sub_83275EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275EA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275EA8, 0x83275EA8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__55(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__55 = 0x8349D3DCu;
	if (!UseLiftedCode(144, 0x83275EE0)) { __imp__sub_83275EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275EE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275EE0, 0x83275EE0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__55 = 0x8349D3E0u;
	if (!UseLiftedCode(144, 0x83275F18)) { __imp__sub_83275F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275F18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275F18, 0x83275F18) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__55 = 0x8349D3E4u;
	if (!UseLiftedCode(144, 0x83275F50)) { __imp__sub_83275F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275F50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275F50, 0x83275F50) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__58 = 0x8349D3E8u;
	if (!UseLiftedCode(144, 0x83275F88)) { __imp__sub_83275F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275F88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275F88, 0x83275F88) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__55 = 0x8349D3ECu;
	if (!UseLiftedCode(144, 0x83275FC0)) { __imp__sub_83275FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275FC0, 0x83275FC0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__55 = 0x8349D3F0u;
	if (!UseLiftedCode(144, 0x83275FF8)) { __imp__sub_83275FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83275FF8, 0x83275FF8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__55(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__55 = 0x8349D3F4u;
	if (!UseLiftedCode(144, 0x83276030)) { __imp__sub_83276030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276030);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276030, 0x83276030) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__55(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__55 = 0x8349D3F8u;
	if (!UseLiftedCode(144, 0x83276068)) { __imp__sub_83276068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276068);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276068, 0x83276068) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__56 = 0x8349D3FCu;
	if (!UseLiftedCode(144, 0x832760A0)) { __imp__sub_832760A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832760A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832760A0, 0x832760A0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__56(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__55 = 0x8349D400u;
	if (!UseLiftedCode(144, 0x832760D8)) { __imp__sub_832760D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832760D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832760D8, 0x832760D8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__55(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__55 = 0x8349D404u;
	if (!UseLiftedCode(144, 0x83276110)) { __imp__sub_83276110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276110);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276110, 0x83276110) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__55(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__55(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__55 = 0x8349D408u;
	if (!UseLiftedCode(144, 0x83276148)) { __imp__sub_83276148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276148);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__55, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276148, 0x83276148) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__55(ctx, base); }

uint64_t Construct_TXT_8349D40C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D40C_G_ = int32_t(0x8349D40C);
	constexpr int32_t str_TXT_820E707C_B_ = int32_t(0x820E707C);
	constexpr int32_t Destroy_TXT_8349D40C_G__address = int32_t(0x832A9430);
	if (!UseLiftedCode(144, 0x83276180)) { __imp__sub_83276180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276180);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D40C_G_, str_TXT_820E707C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D40C_G__address);
}
PROMOTED_ENTRY(144, sub_83276180, 0x83276180) { ctx.r3.u64 = Construct_TXT_8349D40C_G_(ctx, base); }

uint64_t Construct_TXT_8349D410_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D410_G_ = int32_t(0x8349D410);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E70B0);
	constexpr int32_t Destroy_TXT_8349D410_G__address = int32_t(0x832A9440);
	if (!UseLiftedCode(144, 0x832761C0)) { __imp__sub_832761C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832761C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D410_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D410_G__address);
}
PROMOTED_ENTRY(144, sub_832761C0, 0x832761C0) { ctx.r3.u64 = Construct_TXT_8349D410_G_(ctx, base); }

uint64_t Construct_TXT_8349D414_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D414_G_ = int32_t(0x8349D414);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E70E8);
	constexpr int32_t Destroy_TXT_8349D414_G__address = int32_t(0x832A9450);
	if (!UseLiftedCode(144, 0x83276200)) { __imp__sub_83276200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276200);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D414_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D414_G__address);
}
PROMOTED_ENTRY(144, sub_83276200, 0x83276200) { ctx.r3.u64 = Construct_TXT_8349D414_G_(ctx, base); }

uint64_t Construct_TXT_8349D418_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D418_G_ = int32_t(0x8349D418);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E7118);
	constexpr int32_t Destroy_TXT_8349D418_G__address = int32_t(0x832A9460);
	if (!UseLiftedCode(144, 0x83276240)) { __imp__sub_83276240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276240);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D418_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D418_G__address);
}
PROMOTED_ENTRY(144, sub_83276240, 0x83276240) { ctx.r3.u64 = Construct_TXT_8349D418_G_(ctx, base); }

uint64_t Construct_TXT_8349D41C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D41C_G_ = int32_t(0x8349D41C);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E7150);
	constexpr int32_t Destroy_TXT_8349D41C_G__address = int32_t(0x832A9470);
	if (!UseLiftedCode(144, 0x83276280)) { __imp__sub_83276280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276280);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D41C_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D41C_G__address);
}
PROMOTED_ENTRY(144, sub_83276280, 0x83276280) { ctx.r3.u64 = Construct_TXT_8349D41C_G_(ctx, base); }

uint64_t Construct_TXT_8349D420_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D420_G_ = int32_t(0x8349D420);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E7190);
	constexpr int32_t Destroy_TXT_8349D420_G__address = int32_t(0x832A9480);
	if (!UseLiftedCode(144, 0x832762C0)) { __imp__sub_832762C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832762C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D420_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D420_G__address);
}
PROMOTED_ENTRY(144, sub_832762C0, 0x832762C0) { ctx.r3.u64 = Construct_TXT_8349D420_G_(ctx, base); }

uint64_t Construct_TXT_8349D424_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D424_G_ = int32_t(0x8349D424);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E71D8);
	constexpr int32_t Destroy_TXT_8349D424_G__address = int32_t(0x832A9490);
	if (!UseLiftedCode(144, 0x83276300)) { __imp__sub_83276300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276300);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D424_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D424_G__address);
}
PROMOTED_ENTRY(144, sub_83276300, 0x83276300) { ctx.r3.u64 = Construct_TXT_8349D424_G_(ctx, base); }

uint64_t Construct_TXT_8349D428_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D428_G_ = int32_t(0x8349D428);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E7220);
	constexpr int32_t Destroy_TXT_8349D428_G__address = int32_t(0x832A94A0);
	if (!UseLiftedCode(144, 0x83276340)) { __imp__sub_83276340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276340);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D428_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D428_G__address);
}
PROMOTED_ENTRY(144, sub_83276340, 0x83276340) { ctx.r3.u64 = Construct_TXT_8349D428_G_(ctx, base); }

uint64_t Construct_TXT_8349D42C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D42C_G_ = int32_t(0x8349D42C);
	constexpr int32_t str_TXT_820E5348_B_ = int32_t(0x820E7260);
	constexpr int32_t Destroy_TXT_8349D42C_G__address = int32_t(0x832A94B0);
	if (!UseLiftedCode(144, 0x83276380)) { __imp__sub_83276380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276380);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D42C_G_, str_TXT_820E5348_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D42C_G__address);
}
PROMOTED_ENTRY(144, sub_83276380, 0x83276380) { ctx.r3.u64 = Construct_TXT_8349D42C_G_(ctx, base); }

uint64_t Construct_TXT_8349D430_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D430_G_ = int32_t(0x8349D430);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D430_G__address = int32_t(0x832A94C0);
	if (!UseLiftedCode(144, 0x832763C0)) { __imp__sub_832763C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832763C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D430_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D430_G__address);
}
PROMOTED_ENTRY(144, sub_832763C0, 0x832763C0) { ctx.r3.u64 = Construct_TXT_8349D430_G_(ctx, base); }

uint64_t Construct_TXT_8349D434_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D434_G_ = int32_t(0x8349D434);
	constexpr int32_t str_TXT_820E750C_B_ = int32_t(0x820E750C);
	constexpr int32_t Destroy_TXT_8349D434_G__address = int32_t(0x832A94D0);
	if (!UseLiftedCode(144, 0x83276400)) { __imp__sub_83276400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276400);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D434_G_, str_TXT_820E750C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D434_G__address);
}
PROMOTED_ENTRY(144, sub_83276400, 0x83276400) { ctx.r3.u64 = Construct_TXT_8349D434_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__56 = 0x8349D438u;
	if (!UseLiftedCode(144, 0x83276440)) { __imp__sub_83276440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276440, 0x83276440) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__56(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__58 = 0x8349D43Cu;
	if (!UseLiftedCode(144, 0x83276478)) { __imp__sub_83276478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276478, 0x83276478) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__58(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__57 = 0x8349D440u;
	if (!UseLiftedCode(144, 0x832764B0)) { __imp__sub_832764B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832764B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832764B0, 0x832764B0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__56 = 0x8349D444u;
	if (!UseLiftedCode(144, 0x832764E8)) { __imp__sub_832764E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832764E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832764E8, 0x832764E8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__56 = 0x8349D448u;
	if (!UseLiftedCode(144, 0x83276520)) { __imp__sub_83276520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276520);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276520, 0x83276520) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__57 = 0x8349D44Cu;
	if (!UseLiftedCode(144, 0x83276558)) { __imp__sub_83276558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276558);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276558, 0x83276558) { ctx.r3.u64 = HashName_TXT_820A2C34_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__56 = 0x8349D450u;
	if (!UseLiftedCode(144, 0x83276590)) { __imp__sub_83276590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276590);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276590, 0x83276590) { ctx.r3.u64 = HashName_TXT_820A2C44_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__56 = 0x8349D454u;
	if (!UseLiftedCode(144, 0x832765C8)) { __imp__sub_832765C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832765C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832765C8, 0x832765C8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__56 = 0x8349D458u;
	if (!UseLiftedCode(144, 0x83276600)) { __imp__sub_83276600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276600);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276600, 0x83276600) { ctx.r3.u64 = HashName_TXT_820A2C74_B__56(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__56 = 0x8349D45Cu;
	if (!UseLiftedCode(144, 0x83276638)) { __imp__sub_83276638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276638);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276638, 0x83276638) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__56 = 0x8349D460u;
	if (!UseLiftedCode(144, 0x83276670)) { __imp__sub_83276670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276670);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276670, 0x83276670) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__56 = 0x8349D464u;
	if (!UseLiftedCode(144, 0x832766A8)) { __imp__sub_832766A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832766A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832766A8, 0x832766A8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__59 = 0x8349D468u;
	if (!UseLiftedCode(144, 0x832766E0)) { __imp__sub_832766E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832766E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832766E0, 0x832766E0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__56 = 0x8349D46Cu;
	if (!UseLiftedCode(144, 0x83276718)) { __imp__sub_83276718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276718);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276718, 0x83276718) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__56 = 0x8349D470u;
	if (!UseLiftedCode(144, 0x83276750)) { __imp__sub_83276750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276750);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276750, 0x83276750) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__56(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__56 = 0x8349D474u;
	if (!UseLiftedCode(144, 0x83276788)) { __imp__sub_83276788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276788);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276788, 0x83276788) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__56(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__56 = 0x8349D478u;
	if (!UseLiftedCode(144, 0x832767C0)) { __imp__sub_832767C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832767C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832767C0, 0x832767C0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__57 = 0x8349D47Cu;
	if (!UseLiftedCode(144, 0x832767F8)) { __imp__sub_832767F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832767F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832767F8, 0x832767F8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__57(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__56 = 0x8349D480u;
	if (!UseLiftedCode(144, 0x83276830)) { __imp__sub_83276830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276830);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276830, 0x83276830) { ctx.r3.u64 = HashName_TXT_820A2D30_B__56(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__56 = 0x8349D484u;
	if (!UseLiftedCode(144, 0x83276868)) { __imp__sub_83276868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276868);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276868, 0x83276868) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__56(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__56 = 0x8349D488u;
	if (!UseLiftedCode(144, 0x832768A0)) { __imp__sub_832768A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832768A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__56, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832768A0, 0x832768A0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__56(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__57 = 0x8349D48Cu;
	if (!UseLiftedCode(144, 0x832768D8)) { __imp__sub_832768D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832768D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832768D8, 0x832768D8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__57(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__59 = 0x8349D490u;
	if (!UseLiftedCode(144, 0x83276910)) { __imp__sub_83276910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276910);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276910, 0x83276910) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__59(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__58 = 0x8349D494u;
	if (!UseLiftedCode(144, 0x83276948)) { __imp__sub_83276948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276948);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276948, 0x83276948) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__57 = 0x8349D498u;
	if (!UseLiftedCode(144, 0x83276980)) { __imp__sub_83276980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276980);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276980, 0x83276980) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__57 = 0x8349D49Cu;
	if (!UseLiftedCode(144, 0x832769B8)) { __imp__sub_832769B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832769B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832769B8, 0x832769B8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__58 = 0x8349D4A0u;
	if (!UseLiftedCode(144, 0x832769F0)) { __imp__sub_832769F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832769F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832769F0, 0x832769F0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__57 = 0x8349D4A4u;
	if (!UseLiftedCode(144, 0x83276A28)) { __imp__sub_83276A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276A28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276A28, 0x83276A28) { ctx.r3.u64 = HashName_TXT_820A2C44_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__57 = 0x8349D4A8u;
	if (!UseLiftedCode(144, 0x83276A60)) { __imp__sub_83276A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276A60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276A60, 0x83276A60) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__57 = 0x8349D4ACu;
	if (!UseLiftedCode(144, 0x83276A98)) { __imp__sub_83276A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276A98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276A98, 0x83276A98) { ctx.r3.u64 = HashName_TXT_820A2C74_B__57(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__57 = 0x8349D4B0u;
	if (!UseLiftedCode(144, 0x83276AD0)) { __imp__sub_83276AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276AD0, 0x83276AD0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__57 = 0x8349D4B4u;
	if (!UseLiftedCode(144, 0x83276B08)) { __imp__sub_83276B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276B08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276B08, 0x83276B08) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__57 = 0x8349D4B8u;
	if (!UseLiftedCode(144, 0x83276B40)) { __imp__sub_83276B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276B40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276B40, 0x83276B40) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__60 = 0x8349D4BCu;
	if (!UseLiftedCode(144, 0x83276B78)) { __imp__sub_83276B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276B78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276B78, 0x83276B78) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__57 = 0x8349D4C0u;
	if (!UseLiftedCode(144, 0x83276BB0)) { __imp__sub_83276BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276BB0, 0x83276BB0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__57 = 0x8349D4C4u;
	if (!UseLiftedCode(144, 0x83276BE8)) { __imp__sub_83276BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276BE8, 0x83276BE8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__57(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__57 = 0x8349D4C8u;
	if (!UseLiftedCode(144, 0x83276C20)) { __imp__sub_83276C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276C20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276C20, 0x83276C20) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__57(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__57 = 0x8349D4CCu;
	if (!UseLiftedCode(144, 0x83276C58)) { __imp__sub_83276C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276C58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276C58, 0x83276C58) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__58 = 0x8349D4D0u;
	if (!UseLiftedCode(144, 0x83276C90)) { __imp__sub_83276C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276C90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276C90, 0x83276C90) { ctx.r3.u64 = HashName_TXT_820A2D24_B__58(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__57 = 0x8349D4D4u;
	if (!UseLiftedCode(144, 0x83276CC8)) { __imp__sub_83276CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276CC8, 0x83276CC8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__57(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__57 = 0x8349D4D8u;
	if (!UseLiftedCode(144, 0x83276D00)) { __imp__sub_83276D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276D00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276D00, 0x83276D00) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__57(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__57(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__57 = 0x8349D4DCu;
	if (!UseLiftedCode(144, 0x83276D38)) { __imp__sub_83276D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276D38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__57, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276D38, 0x83276D38) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__57(ctx, base); }

uint64_t Construct_TXT_8349D4E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D4E0_G_ = int32_t(0x8349D4E0);
	constexpr int32_t str_TXT_820E1DC4_B_ = int32_t(0x820E1DC4);
	constexpr int32_t Destroy_TXT_8349D4E0_G__address = int32_t(0x832A94E0);
	if (!UseLiftedCode(144, 0x83276D70)) { __imp__sub_83276D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276D70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E0_G_, str_TXT_820E1DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D4E0_G__address);
}
PROMOTED_ENTRY(144, sub_83276D70, 0x83276D70) { ctx.r3.u64 = Construct_TXT_8349D4E0_G_(ctx, base); }

uint64_t Construct_TXT_8349D4E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D4E4_G_ = int32_t(0x8349D4E4);
	constexpr int32_t str_TXT_820E1D94_B_ = int32_t(0x820E1D94);
	constexpr int32_t Destroy_TXT_8349D4E4_G__address = int32_t(0x832A94F0);
	if (!UseLiftedCode(144, 0x83276DB0)) { __imp__sub_83276DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E4_G_, str_TXT_820E1D94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D4E4_G__address);
}
PROMOTED_ENTRY(144, sub_83276DB0, 0x83276DB0) { ctx.r3.u64 = Construct_TXT_8349D4E4_G_(ctx, base); }

uint64_t Construct_TXT_8349D4E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D4E8_G_ = int32_t(0x8349D4E8);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E20);
	constexpr int32_t Destroy_TXT_8349D4E8_G__address = int32_t(0x832A9500);
	if (!UseLiftedCode(144, 0x83276DF0)) { __imp__sub_83276DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276DF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E8_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D4E8_G__address);
}
PROMOTED_ENTRY(144, sub_83276DF0, 0x83276DF0) { ctx.r3.u64 = Construct_TXT_8349D4E8_G_(ctx, base); }

uint64_t Construct_TXT_8349D4EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D4EC_G_ = int32_t(0x8349D4EC);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F48);
	constexpr int32_t Destroy_TXT_8349D4EC_G__address = int32_t(0x832A9510);
	if (!UseLiftedCode(144, 0x83276E30)) { __imp__sub_83276E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276E30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4EC_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D4EC_G__address);
}
PROMOTED_ENTRY(144, sub_83276E30, 0x83276E30) { ctx.r3.u64 = Construct_TXT_8349D4EC_G_(ctx, base); }

uint64_t Construct_TXT_8349D4F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D4F0_G_ = int32_t(0x8349D4F0);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F8C);
	constexpr int32_t Destroy_TXT_8349D4F0_G__address = int32_t(0x832A9520);
	if (!UseLiftedCode(144, 0x83276E70)) { __imp__sub_83276E70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276E70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4F0_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D4F0_G__address);
}
PROMOTED_ENTRY(144, sub_83276E70, 0x83276E70) { ctx.r3.u64 = Construct_TXT_8349D4F0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__58 = 0x8349D4F4u;
	if (!UseLiftedCode(144, 0x83276EB0)) { __imp__sub_83276EB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276EB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276EB0, 0x83276EB0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__58(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__60 = 0x8349D4F8u;
	if (!UseLiftedCode(144, 0x83276EE8)) { __imp__sub_83276EE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276EE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276EE8, 0x83276EE8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__60(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__59 = 0x8349D4FCu;
	if (!UseLiftedCode(144, 0x83276F20)) { __imp__sub_83276F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276F20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276F20, 0x83276F20) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__58 = 0x8349D500u;
	if (!UseLiftedCode(144, 0x83276F58)) { __imp__sub_83276F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276F58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276F58, 0x83276F58) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__58 = 0x8349D504u;
	if (!UseLiftedCode(144, 0x83276F90)) { __imp__sub_83276F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276F90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276F90, 0x83276F90) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__59 = 0x8349D508u;
	if (!UseLiftedCode(144, 0x83276FC8)) { __imp__sub_83276FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83276FC8, 0x83276FC8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__58 = 0x8349D50Cu;
	if (!UseLiftedCode(144, 0x83277000)) { __imp__sub_83277000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277000);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277000, 0x83277000) { ctx.r3.u64 = HashName_TXT_820A2C44_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__58 = 0x8349D510u;
	if (!UseLiftedCode(144, 0x83277038)) { __imp__sub_83277038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277038);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277038, 0x83277038) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__58 = 0x8349D514u;
	if (!UseLiftedCode(144, 0x83277070)) { __imp__sub_83277070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277070);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277070, 0x83277070) { ctx.r3.u64 = HashName_TXT_820A2C74_B__58(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__58 = 0x8349D518u;
	if (!UseLiftedCode(144, 0x832770A8)) { __imp__sub_832770A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832770A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832770A8, 0x832770A8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__58 = 0x8349D51Cu;
	if (!UseLiftedCode(144, 0x832770E0)) { __imp__sub_832770E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832770E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832770E0, 0x832770E0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__58 = 0x8349D520u;
	if (!UseLiftedCode(144, 0x83277118)) { __imp__sub_83277118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277118);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277118, 0x83277118) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__61 = 0x8349D524u;
	if (!UseLiftedCode(144, 0x83277150)) { __imp__sub_83277150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277150);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277150, 0x83277150) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__58 = 0x8349D528u;
	if (!UseLiftedCode(144, 0x83277188)) { __imp__sub_83277188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277188);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277188, 0x83277188) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__58 = 0x8349D52Cu;
	if (!UseLiftedCode(144, 0x832771C0)) { __imp__sub_832771C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832771C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832771C0, 0x832771C0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__58(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__58 = 0x8349D530u;
	if (!UseLiftedCode(144, 0x832771F8)) { __imp__sub_832771F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832771F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832771F8, 0x832771F8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__58(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__58 = 0x8349D534u;
	if (!UseLiftedCode(144, 0x83277230)) { __imp__sub_83277230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277230);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277230, 0x83277230) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__59 = 0x8349D538u;
	if (!UseLiftedCode(144, 0x83277268)) { __imp__sub_83277268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277268);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277268, 0x83277268) { ctx.r3.u64 = HashName_TXT_820A2D24_B__59(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__58 = 0x8349D53Cu;
	if (!UseLiftedCode(144, 0x832772A0)) { __imp__sub_832772A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832772A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832772A0, 0x832772A0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__58(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__58 = 0x8349D540u;
	if (!UseLiftedCode(144, 0x832772D8)) { __imp__sub_832772D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832772D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832772D8, 0x832772D8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__58(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__58 = 0x8349D544u;
	if (!UseLiftedCode(144, 0x83277310)) { __imp__sub_83277310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277310);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__58, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277310, 0x83277310) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__58(ctx, base); }

uint64_t Construct_TXT_8349D548_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D548_G_ = int32_t(0x8349D548);
	constexpr int32_t str_TXT_820E235C_B_ = int32_t(0x820E235C);
	constexpr int32_t Destroy_TXT_8349D548_G__address = int32_t(0x832A9530);
	if (!UseLiftedCode(144, 0x83277348)) { __imp__sub_83277348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D548_G_, str_TXT_820E235C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D548_G__address);
}
PROMOTED_ENTRY(144, sub_83277348, 0x83277348) { ctx.r3.u64 = Construct_TXT_8349D548_G_(ctx, base); }

uint64_t Construct_TXT_8349D54C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D54C_G_ = int32_t(0x8349D54C);
	constexpr int32_t str_TXT_820E23F0_B_ = int32_t(0x820E23F0);
	constexpr int32_t Destroy_TXT_8349D54C_G__address = int32_t(0x832A9540);
	if (!UseLiftedCode(144, 0x83277388)) { __imp__sub_83277388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D54C_G_, str_TXT_820E23F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D54C_G__address);
}
PROMOTED_ENTRY(144, sub_83277388, 0x83277388) { ctx.r3.u64 = Construct_TXT_8349D54C_G_(ctx, base); }

uint64_t Construct_TXT_8349D550_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D550_G_ = int32_t(0x8349D550);
	constexpr int32_t str_TXT_820E23BC_B_ = int32_t(0x820E23BC);
	constexpr int32_t Destroy_TXT_8349D550_G__address = int32_t(0x832A9550);
	if (!UseLiftedCode(144, 0x832773C8)) { __imp__sub_832773C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832773C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D550_G_, str_TXT_820E23BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D550_G__address);
}
PROMOTED_ENTRY(144, sub_832773C8, 0x832773C8) { ctx.r3.u64 = Construct_TXT_8349D550_G_(ctx, base); }

uint64_t Construct_TXT_8349D554_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D554_G_ = int32_t(0x8349D554);
	constexpr int32_t str_TXT_820E238C_B_ = int32_t(0x820E238C);
	constexpr int32_t Destroy_TXT_8349D554_G__address = int32_t(0x832A9560);
	if (!UseLiftedCode(144, 0x83277408)) { __imp__sub_83277408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D554_G_, str_TXT_820E238C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D554_G__address);
}
PROMOTED_ENTRY(144, sub_83277408, 0x83277408) { ctx.r3.u64 = Construct_TXT_8349D554_G_(ctx, base); }

uint64_t Construct_TXT_8349D558_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D558_G_ = int32_t(0x8349D558);
	constexpr int32_t str_TXT_820E2420_B_ = int32_t(0x820E2420);
	constexpr int32_t Destroy_TXT_8349D558_G__address = int32_t(0x832A9570);
	if (!UseLiftedCode(144, 0x83277448)) { __imp__sub_83277448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D558_G_, str_TXT_820E2420_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D558_G__address);
}
PROMOTED_ENTRY(144, sub_83277448, 0x83277448) { ctx.r3.u64 = Construct_TXT_8349D558_G_(ctx, base); }

uint64_t Construct_TXT_8349D55C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D55C_G_ = int32_t(0x8349D55C);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D55C_G__address = int32_t(0x832A9580);
	if (!UseLiftedCode(144, 0x83277488)) { __imp__sub_83277488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D55C_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D55C_G__address);
}
PROMOTED_ENTRY(144, sub_83277488, 0x83277488) { ctx.r3.u64 = Construct_TXT_8349D55C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__59 = 0x8349D560u;
	if (!UseLiftedCode(144, 0x832774C8)) { __imp__sub_832774C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832774C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832774C8, 0x832774C8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__59(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__61 = 0x8349D564u;
	if (!UseLiftedCode(144, 0x83277500)) { __imp__sub_83277500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277500);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277500, 0x83277500) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__61(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__60 = 0x8349D568u;
	if (!UseLiftedCode(144, 0x83277538)) { __imp__sub_83277538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277538);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277538, 0x83277538) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__59 = 0x8349D56Cu;
	if (!UseLiftedCode(144, 0x83277570)) { __imp__sub_83277570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277570);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277570, 0x83277570) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__59 = 0x8349D570u;
	if (!UseLiftedCode(144, 0x832775A8)) { __imp__sub_832775A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832775A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832775A8, 0x832775A8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__60 = 0x8349D574u;
	if (!UseLiftedCode(144, 0x832775E0)) { __imp__sub_832775E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832775E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832775E0, 0x832775E0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__59 = 0x8349D578u;
	if (!UseLiftedCode(144, 0x83277618)) { __imp__sub_83277618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277618);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277618, 0x83277618) { ctx.r3.u64 = HashName_TXT_820A2C44_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__59 = 0x8349D57Cu;
	if (!UseLiftedCode(144, 0x83277650)) { __imp__sub_83277650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277650, 0x83277650) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__59 = 0x8349D580u;
	if (!UseLiftedCode(144, 0x83277688)) { __imp__sub_83277688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277688, 0x83277688) { ctx.r3.u64 = HashName_TXT_820A2C74_B__59(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__59 = 0x8349D584u;
	if (!UseLiftedCode(144, 0x832776C0)) { __imp__sub_832776C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832776C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832776C0, 0x832776C0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__59 = 0x8349D588u;
	if (!UseLiftedCode(144, 0x832776F8)) { __imp__sub_832776F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832776F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832776F8, 0x832776F8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__59 = 0x8349D58Cu;
	if (!UseLiftedCode(144, 0x83277730)) { __imp__sub_83277730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277730, 0x83277730) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__62 = 0x8349D590u;
	if (!UseLiftedCode(144, 0x83277768)) { __imp__sub_83277768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277768, 0x83277768) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__59 = 0x8349D594u;
	if (!UseLiftedCode(144, 0x832777A0)) { __imp__sub_832777A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832777A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832777A0, 0x832777A0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__59 = 0x8349D598u;
	if (!UseLiftedCode(144, 0x832777D8)) { __imp__sub_832777D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832777D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832777D8, 0x832777D8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__59(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__59 = 0x8349D59Cu;
	if (!UseLiftedCode(144, 0x83277810)) { __imp__sub_83277810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277810, 0x83277810) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__59(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__59 = 0x8349D5A0u;
	if (!UseLiftedCode(144, 0x83277848)) { __imp__sub_83277848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277848, 0x83277848) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__60 = 0x8349D5A4u;
	if (!UseLiftedCode(144, 0x83277880)) { __imp__sub_83277880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277880);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277880, 0x83277880) { ctx.r3.u64 = HashName_TXT_820A2D24_B__60(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__59 = 0x8349D5A8u;
	if (!UseLiftedCode(144, 0x832778B8)) { __imp__sub_832778B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832778B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832778B8, 0x832778B8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__59(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__59 = 0x8349D5ACu;
	if (!UseLiftedCode(144, 0x832778F0)) { __imp__sub_832778F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832778F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832778F0, 0x832778F0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__59(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__59(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__59 = 0x8349D5B0u;
	if (!UseLiftedCode(144, 0x83277928)) { __imp__sub_83277928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277928);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__59, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277928, 0x83277928) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__59(ctx, base); }

uint64_t Construct_TXT_8349D5B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D5B4_G_ = int32_t(0x8349D5B4);
	constexpr int32_t str_TXT_820E7A18_B_ = int32_t(0x820E7A18);
	constexpr int32_t Destroy_TXT_8349D5B4_G__address = int32_t(0x832A9590);
	if (!UseLiftedCode(144, 0x83277960)) { __imp__sub_83277960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277960);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5B4_G_, str_TXT_820E7A18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D5B4_G__address);
}
PROMOTED_ENTRY(144, sub_83277960, 0x83277960) { ctx.r3.u64 = Construct_TXT_8349D5B4_G_(ctx, base); }

uint64_t Construct_TXT_8349D5B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D5B8_G_ = int32_t(0x8349D5B8);
	constexpr int32_t str_TXT_820E7A4C_B_ = int32_t(0x820E7A4C);
	constexpr int32_t Destroy_TXT_8349D5B8_G__address = int32_t(0x832A95A0);
	if (!UseLiftedCode(144, 0x832779A0)) { __imp__sub_832779A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832779A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5B8_G_, str_TXT_820E7A4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D5B8_G__address);
}
PROMOTED_ENTRY(144, sub_832779A0, 0x832779A0) { ctx.r3.u64 = Construct_TXT_8349D5B8_G_(ctx, base); }

uint64_t Construct_TXT_8349D5BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D5BC_G_ = int32_t(0x8349D5BC);
	constexpr int32_t str_TXT_820E7A84_B_ = int32_t(0x820E7A84);
	constexpr int32_t Destroy_TXT_8349D5BC_G__address = int32_t(0x832A95B0);
	if (!UseLiftedCode(144, 0x832779E0)) { __imp__sub_832779E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832779E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5BC_G_, str_TXT_820E7A84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D5BC_G__address);
}
PROMOTED_ENTRY(144, sub_832779E0, 0x832779E0) { ctx.r3.u64 = Construct_TXT_8349D5BC_G_(ctx, base); }

uint64_t Construct_TXT_8349D5C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D5C0_G_ = int32_t(0x8349D5C0);
	constexpr int32_t str_TXT_820E7A84_B_ = int32_t(0x820E7AB8);
	constexpr int32_t Destroy_TXT_8349D5C0_G__address = int32_t(0x832A95C0);
	if (!UseLiftedCode(144, 0x83277A20)) { __imp__sub_83277A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277A20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5C0_G_, str_TXT_820E7A84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D5C0_G__address);
}
PROMOTED_ENTRY(144, sub_83277A20, 0x83277A20) { ctx.r3.u64 = Construct_TXT_8349D5C0_G_(ctx, base); }

uint64_t Construct_TXT_8349D5C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D5C4_G_ = int32_t(0x8349D5C4);
	constexpr int32_t str_TXT_820E7AF4_B_ = int32_t(0x820E7AF4);
	constexpr int32_t Destroy_TXT_8349D5C4_G__address = int32_t(0x832A95D0);
	if (!UseLiftedCode(144, 0x83277A60)) { __imp__sub_83277A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277A60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5C4_G_, str_TXT_820E7AF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D5C4_G__address);
}
PROMOTED_ENTRY(144, sub_83277A60, 0x83277A60) { ctx.r3.u64 = Construct_TXT_8349D5C4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__60 = 0x8349D5C8u;
	if (!UseLiftedCode(144, 0x83277AA0)) { __imp__sub_83277AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277AA0, 0x83277AA0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__60(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__62 = 0x8349D5CCu;
	if (!UseLiftedCode(144, 0x83277AD8)) { __imp__sub_83277AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277AD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277AD8, 0x83277AD8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__62(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__61 = 0x8349D5D0u;
	if (!UseLiftedCode(144, 0x83277B10)) { __imp__sub_83277B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277B10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277B10, 0x83277B10) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__60 = 0x8349D5D4u;
	if (!UseLiftedCode(144, 0x83277B48)) { __imp__sub_83277B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277B48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277B48, 0x83277B48) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__60 = 0x8349D5D8u;
	if (!UseLiftedCode(144, 0x83277B80)) { __imp__sub_83277B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277B80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277B80, 0x83277B80) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__61 = 0x8349D5DCu;
	if (!UseLiftedCode(144, 0x83277BB8)) { __imp__sub_83277BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277BB8, 0x83277BB8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__60 = 0x8349D5E0u;
	if (!UseLiftedCode(144, 0x83277BF0)) { __imp__sub_83277BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277BF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277BF0, 0x83277BF0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__60 = 0x8349D5E4u;
	if (!UseLiftedCode(144, 0x83277C28)) { __imp__sub_83277C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277C28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277C28, 0x83277C28) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__60 = 0x8349D5E8u;
	if (!UseLiftedCode(144, 0x83277C60)) { __imp__sub_83277C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277C60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277C60, 0x83277C60) { ctx.r3.u64 = HashName_TXT_820A2C74_B__60(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__60 = 0x8349D5ECu;
	if (!UseLiftedCode(144, 0x83277C98)) { __imp__sub_83277C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277C98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277C98, 0x83277C98) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__60 = 0x8349D5F0u;
	if (!UseLiftedCode(144, 0x83277CD0)) { __imp__sub_83277CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277CD0, 0x83277CD0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__60 = 0x8349D5F4u;
	if (!UseLiftedCode(144, 0x83277D08)) { __imp__sub_83277D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277D08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277D08, 0x83277D08) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__63 = 0x8349D5F8u;
	if (!UseLiftedCode(144, 0x83277D40)) { __imp__sub_83277D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277D40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277D40, 0x83277D40) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__60 = 0x8349D5FCu;
	if (!UseLiftedCode(144, 0x83277D78)) { __imp__sub_83277D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277D78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277D78, 0x83277D78) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__60 = 0x8349D600u;
	if (!UseLiftedCode(144, 0x83277DB0)) { __imp__sub_83277DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277DB0, 0x83277DB0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__60(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__60 = 0x8349D604u;
	if (!UseLiftedCode(144, 0x83277DE8)) { __imp__sub_83277DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277DE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277DE8, 0x83277DE8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__60(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__60 = 0x8349D608u;
	if (!UseLiftedCode(144, 0x83277E20)) { __imp__sub_83277E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277E20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277E20, 0x83277E20) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__61 = 0x8349D60Cu;
	if (!UseLiftedCode(144, 0x83277E58)) { __imp__sub_83277E58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277E58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277E58, 0x83277E58) { ctx.r3.u64 = HashName_TXT_820A2D24_B__61(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__60 = 0x8349D610u;
	if (!UseLiftedCode(144, 0x83277E90)) { __imp__sub_83277E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277E90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277E90, 0x83277E90) { ctx.r3.u64 = HashName_TXT_820A2D30_B__60(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__60 = 0x8349D614u;
	if (!UseLiftedCode(144, 0x83277EC8)) { __imp__sub_83277EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277EC8, 0x83277EC8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__60(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__60 = 0x8349D618u;
	if (!UseLiftedCode(144, 0x83277F00)) { __imp__sub_83277F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277F00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__60, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83277F00, 0x83277F00) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__60(ctx, base); }

uint64_t Construct_TXT_8349D61C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D61C_G_ = int32_t(0x8349D61C);
	constexpr int32_t str_TXT_820E7C14_B_ = int32_t(0x820E7C14);
	constexpr int32_t Destroy_TXT_8349D61C_G__address = int32_t(0x832A95E0);
	if (!UseLiftedCode(144, 0x83277F38)) { __imp__sub_83277F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D61C_G_, str_TXT_820E7C14_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D61C_G__address);
}
PROMOTED_ENTRY(144, sub_83277F38, 0x83277F38) { ctx.r3.u64 = Construct_TXT_8349D61C_G_(ctx, base); }

uint64_t Construct_TXT_8349D620_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D620_G_ = int32_t(0x8349D620);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7C44);
	constexpr int32_t Destroy_TXT_8349D620_G__address = int32_t(0x832A95F0);
	if (!UseLiftedCode(144, 0x83277F78)) { __imp__sub_83277F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D620_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D620_G__address);
}
PROMOTED_ENTRY(144, sub_83277F78, 0x83277F78) { ctx.r3.u64 = Construct_TXT_8349D620_G_(ctx, base); }

uint64_t Construct_TXT_8349D624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D624_G_ = int32_t(0x8349D624);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7C80);
	constexpr int32_t Destroy_TXT_8349D624_G__address = int32_t(0x832A9600);
	if (!UseLiftedCode(144, 0x83277FB8)) { __imp__sub_83277FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D624_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D624_G__address);
}
PROMOTED_ENTRY(144, sub_83277FB8, 0x83277FB8) { ctx.r3.u64 = Construct_TXT_8349D624_G_(ctx, base); }

uint64_t Construct_TXT_8349D628_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D628_G_ = int32_t(0x8349D628);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7CBC);
	constexpr int32_t Destroy_TXT_8349D628_G__address = int32_t(0x832A9610);
	if (!UseLiftedCode(144, 0x83277FF8)) { __imp__sub_83277FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D628_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D628_G__address);
}
PROMOTED_ENTRY(144, sub_83277FF8, 0x83277FF8) { ctx.r3.u64 = Construct_TXT_8349D628_G_(ctx, base); }

uint64_t Construct_TXT_8349D62C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D62C_G_ = int32_t(0x8349D62C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7CF4);
	constexpr int32_t Destroy_TXT_8349D62C_G__address = int32_t(0x832A9620);
	if (!UseLiftedCode(144, 0x83278038)) { __imp__sub_83278038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D62C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D62C_G__address);
}
PROMOTED_ENTRY(144, sub_83278038, 0x83278038) { ctx.r3.u64 = Construct_TXT_8349D62C_G_(ctx, base); }

uint64_t Construct_TXT_8349D630_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D630_G_ = int32_t(0x8349D630);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7D2C);
	constexpr int32_t Destroy_TXT_8349D630_G__address = int32_t(0x832A9630);
	if (!UseLiftedCode(144, 0x83278078)) { __imp__sub_83278078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D630_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D630_G__address);
}
PROMOTED_ENTRY(144, sub_83278078, 0x83278078) { ctx.r3.u64 = Construct_TXT_8349D630_G_(ctx, base); }

uint64_t Construct_TXT_8349D634_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D634_G_ = int32_t(0x8349D634);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7D64);
	constexpr int32_t Destroy_TXT_8349D634_G__address = int32_t(0x832A9640);
	if (!UseLiftedCode(144, 0x832780B8)) { __imp__sub_832780B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832780B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D634_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D634_G__address);
}
PROMOTED_ENTRY(144, sub_832780B8, 0x832780B8) { ctx.r3.u64 = Construct_TXT_8349D634_G_(ctx, base); }

uint64_t Construct_TXT_8349D638_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D638_G_ = int32_t(0x8349D638);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7D9C);
	constexpr int32_t Destroy_TXT_8349D638_G__address = int32_t(0x832A9650);
	if (!UseLiftedCode(144, 0x832780F8)) { __imp__sub_832780F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832780F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D638_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D638_G__address);
}
PROMOTED_ENTRY(144, sub_832780F8, 0x832780F8) { ctx.r3.u64 = Construct_TXT_8349D638_G_(ctx, base); }

uint64_t Construct_TXT_8349D63C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D63C_G_ = int32_t(0x8349D63C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7DD4);
	constexpr int32_t Destroy_TXT_8349D63C_G__address = int32_t(0x832A9660);
	if (!UseLiftedCode(144, 0x83278138)) { __imp__sub_83278138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D63C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D63C_G__address);
}
PROMOTED_ENTRY(144, sub_83278138, 0x83278138) { ctx.r3.u64 = Construct_TXT_8349D63C_G_(ctx, base); }

uint64_t Construct_TXT_8349D640_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D640_G_ = int32_t(0x8349D640);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7E10);
	constexpr int32_t Destroy_TXT_8349D640_G__address = int32_t(0x832A9670);
	if (!UseLiftedCode(144, 0x83278178)) { __imp__sub_83278178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278178);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D640_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D640_G__address);
}
PROMOTED_ENTRY(144, sub_83278178, 0x83278178) { ctx.r3.u64 = Construct_TXT_8349D640_G_(ctx, base); }

uint64_t Construct_TXT_8349D644_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D644_G_ = int32_t(0x8349D644);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7E58);
	constexpr int32_t Destroy_TXT_8349D644_G__address = int32_t(0x832A9680);
	if (!UseLiftedCode(144, 0x832781B8)) { __imp__sub_832781B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832781B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D644_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D644_G__address);
}
PROMOTED_ENTRY(144, sub_832781B8, 0x832781B8) { ctx.r3.u64 = Construct_TXT_8349D644_G_(ctx, base); }

uint64_t Construct_TXT_8349D648_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D648_G_ = int32_t(0x8349D648);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7EA0);
	constexpr int32_t Destroy_TXT_8349D648_G__address = int32_t(0x832A9690);
	if (!UseLiftedCode(144, 0x832781F8)) { __imp__sub_832781F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832781F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D648_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D648_G__address);
}
PROMOTED_ENTRY(144, sub_832781F8, 0x832781F8) { ctx.r3.u64 = Construct_TXT_8349D648_G_(ctx, base); }

uint64_t Construct_TXT_8349D64C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D64C_G_ = int32_t(0x8349D64C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7EE0);
	constexpr int32_t Destroy_TXT_8349D64C_G__address = int32_t(0x832A96A0);
	if (!UseLiftedCode(144, 0x83278238)) { __imp__sub_83278238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D64C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D64C_G__address);
}
PROMOTED_ENTRY(144, sub_83278238, 0x83278238) { ctx.r3.u64 = Construct_TXT_8349D64C_G_(ctx, base); }

uint64_t Construct_TXT_8349D650_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D650_G_ = int32_t(0x8349D650);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7F1C);
	constexpr int32_t Destroy_TXT_8349D650_G__address = int32_t(0x832A96B0);
	if (!UseLiftedCode(144, 0x83278278)) { __imp__sub_83278278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D650_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D650_G__address);
}
PROMOTED_ENTRY(144, sub_83278278, 0x83278278) { ctx.r3.u64 = Construct_TXT_8349D650_G_(ctx, base); }

uint64_t Construct_TXT_8349D654_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D654_G_ = int32_t(0x8349D654);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7F54);
	constexpr int32_t Destroy_TXT_8349D654_G__address = int32_t(0x832A96C0);
	if (!UseLiftedCode(144, 0x832782B8)) { __imp__sub_832782B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832782B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D654_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D654_G__address);
}
PROMOTED_ENTRY(144, sub_832782B8, 0x832782B8) { ctx.r3.u64 = Construct_TXT_8349D654_G_(ctx, base); }

uint64_t Construct_TXT_8349D658_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D658_G_ = int32_t(0x8349D658);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7F8C);
	constexpr int32_t Destroy_TXT_8349D658_G__address = int32_t(0x832A96D0);
	if (!UseLiftedCode(144, 0x832782F8)) { __imp__sub_832782F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832782F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D658_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D658_G__address);
}
PROMOTED_ENTRY(144, sub_832782F8, 0x832782F8) { ctx.r3.u64 = Construct_TXT_8349D658_G_(ctx, base); }

uint64_t Construct_TXT_8349D65C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D65C_G_ = int32_t(0x8349D65C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7FC4);
	constexpr int32_t Destroy_TXT_8349D65C_G__address = int32_t(0x832A96E0);
	if (!UseLiftedCode(144, 0x83278338)) { __imp__sub_83278338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278338);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D65C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D65C_G__address);
}
PROMOTED_ENTRY(144, sub_83278338, 0x83278338) { ctx.r3.u64 = Construct_TXT_8349D65C_G_(ctx, base); }

uint64_t Construct_TXT_8349D660_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D660_G_ = int32_t(0x8349D660);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E7FFC);
	constexpr int32_t Destroy_TXT_8349D660_G__address = int32_t(0x832A96F0);
	if (!UseLiftedCode(144, 0x83278378)) { __imp__sub_83278378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278378);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D660_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D660_G__address);
}
PROMOTED_ENTRY(144, sub_83278378, 0x83278378) { ctx.r3.u64 = Construct_TXT_8349D660_G_(ctx, base); }

uint64_t Construct_TXT_8349D664_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D664_G_ = int32_t(0x8349D664);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E8038);
	constexpr int32_t Destroy_TXT_8349D664_G__address = int32_t(0x832A9700);
	if (!UseLiftedCode(144, 0x832783B8)) { __imp__sub_832783B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832783B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D664_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D664_G__address);
}
PROMOTED_ENTRY(144, sub_832783B8, 0x832783B8) { ctx.r3.u64 = Construct_TXT_8349D664_G_(ctx, base); }

uint64_t Construct_TXT_8349D668_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D668_G_ = int32_t(0x8349D668);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E8074);
	constexpr int32_t Destroy_TXT_8349D668_G__address = int32_t(0x832A9710);
	if (!UseLiftedCode(144, 0x832783F8)) { __imp__sub_832783F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832783F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D668_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D668_G__address);
}
PROMOTED_ENTRY(144, sub_832783F8, 0x832783F8) { ctx.r3.u64 = Construct_TXT_8349D668_G_(ctx, base); }

uint64_t Construct_TXT_8349D66C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D66C_G_ = int32_t(0x8349D66C);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E80B4);
	constexpr int32_t Destroy_TXT_8349D66C_G__address = int32_t(0x832A9720);
	if (!UseLiftedCode(144, 0x83278438)) { __imp__sub_83278438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278438);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D66C_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D66C_G__address);
}
PROMOTED_ENTRY(144, sub_83278438, 0x83278438) { ctx.r3.u64 = Construct_TXT_8349D66C_G_(ctx, base); }

uint64_t Construct_TXT_8349D670_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D670_G_ = int32_t(0x8349D670);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E80F0);
	constexpr int32_t Destroy_TXT_8349D670_G__address = int32_t(0x832A9730);
	if (!UseLiftedCode(144, 0x83278478)) { __imp__sub_83278478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278478);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D670_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D670_G__address);
}
PROMOTED_ENTRY(144, sub_83278478, 0x83278478) { ctx.r3.u64 = Construct_TXT_8349D670_G_(ctx, base); }

uint64_t Construct_TXT_8349D674_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D674_G_ = int32_t(0x8349D674);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E8128);
	constexpr int32_t Destroy_TXT_8349D674_G__address = int32_t(0x832A9740);
	if (!UseLiftedCode(144, 0x832784B8)) { __imp__sub_832784B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832784B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D674_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D674_G__address);
}
PROMOTED_ENTRY(144, sub_832784B8, 0x832784B8) { ctx.r3.u64 = Construct_TXT_8349D674_G_(ctx, base); }

uint64_t Construct_TXT_8349D678_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D678_G_ = int32_t(0x8349D678);
	constexpr int32_t str_TXT_820E51A4_B_ = int32_t(0x820E8160);
	constexpr int32_t Destroy_TXT_8349D678_G__address = int32_t(0x832A9750);
	if (!UseLiftedCode(144, 0x832784F8)) { __imp__sub_832784F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832784F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D678_G_, str_TXT_820E51A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D678_G__address);
}
PROMOTED_ENTRY(144, sub_832784F8, 0x832784F8) { ctx.r3.u64 = Construct_TXT_8349D678_G_(ctx, base); }

uint64_t Construct_TXT_8349D67C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D67C_G_ = int32_t(0x8349D67C);
	constexpr int32_t str_TXT_820E4874_B_ = int32_t(0x820E4874);
	constexpr int32_t Destroy_TXT_8349D67C_G__address = int32_t(0x832A9760);
	if (!UseLiftedCode(144, 0x83278538)) { __imp__sub_83278538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278538);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D67C_G_, str_TXT_820E4874_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D67C_G__address);
}
PROMOTED_ENTRY(144, sub_83278538, 0x83278538) { ctx.r3.u64 = Construct_TXT_8349D67C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__61 = 0x8349D680u;
	if (!UseLiftedCode(144, 0x83278578)) { __imp__sub_83278578(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278578);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278578, 0x83278578) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__61(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__63 = 0x8349D684u;
	if (!UseLiftedCode(144, 0x832785B0)) { __imp__sub_832785B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832785B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832785B0, 0x832785B0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__63(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__62 = 0x8349D688u;
	if (!UseLiftedCode(144, 0x832785E8)) { __imp__sub_832785E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832785E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832785E8, 0x832785E8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__61 = 0x8349D68Cu;
	if (!UseLiftedCode(144, 0x83278620)) { __imp__sub_83278620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278620);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278620, 0x83278620) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__61 = 0x8349D690u;
	if (!UseLiftedCode(144, 0x83278658)) { __imp__sub_83278658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278658);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278658, 0x83278658) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__62 = 0x8349D694u;
	if (!UseLiftedCode(144, 0x83278690)) { __imp__sub_83278690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278690);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278690, 0x83278690) { ctx.r3.u64 = HashName_TXT_820A2C34_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__61 = 0x8349D698u;
	if (!UseLiftedCode(144, 0x832786C8)) { __imp__sub_832786C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832786C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832786C8, 0x832786C8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__61 = 0x8349D69Cu;
	if (!UseLiftedCode(144, 0x83278700)) { __imp__sub_83278700(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278700);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278700, 0x83278700) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__61 = 0x8349D6A0u;
	if (!UseLiftedCode(144, 0x83278738)) { __imp__sub_83278738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278738);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278738, 0x83278738) { ctx.r3.u64 = HashName_TXT_820A2C74_B__61(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__61 = 0x8349D6A4u;
	if (!UseLiftedCode(144, 0x83278770)) { __imp__sub_83278770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278770);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278770, 0x83278770) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__61 = 0x8349D6A8u;
	if (!UseLiftedCode(144, 0x832787A8)) { __imp__sub_832787A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832787A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832787A8, 0x832787A8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__61 = 0x8349D6ACu;
	if (!UseLiftedCode(144, 0x832787E0)) { __imp__sub_832787E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832787E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832787E0, 0x832787E0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__64 = 0x8349D6B0u;
	if (!UseLiftedCode(144, 0x83278818)) { __imp__sub_83278818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278818);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278818, 0x83278818) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__61 = 0x8349D6B4u;
	if (!UseLiftedCode(144, 0x83278850)) { __imp__sub_83278850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278850);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278850, 0x83278850) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__61 = 0x8349D6B8u;
	if (!UseLiftedCode(144, 0x83278888)) { __imp__sub_83278888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278888);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278888, 0x83278888) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__61(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__61 = 0x8349D6BCu;
	if (!UseLiftedCode(144, 0x832788C0)) { __imp__sub_832788C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832788C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832788C0, 0x832788C0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__61(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__61 = 0x8349D6C0u;
	if (!UseLiftedCode(144, 0x832788F8)) { __imp__sub_832788F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832788F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832788F8, 0x832788F8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__62 = 0x8349D6C4u;
	if (!UseLiftedCode(144, 0x83278930)) { __imp__sub_83278930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278930);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278930, 0x83278930) { ctx.r3.u64 = HashName_TXT_820A2D24_B__62(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__61 = 0x8349D6C8u;
	if (!UseLiftedCode(144, 0x83278968)) { __imp__sub_83278968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278968);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83278968, 0x83278968) { ctx.r3.u64 = HashName_TXT_820A2D30_B__61(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__61 = 0x8349D6CCu;
	if (!UseLiftedCode(144, 0x832789A0)) { __imp__sub_832789A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832789A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832789A0, 0x832789A0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__61(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__61(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__61 = 0x8349D6D0u;
	if (!UseLiftedCode(144, 0x832789D8)) { __imp__sub_832789D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832789D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__61, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832789D8, 0x832789D8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__61(ctx, base); }

uint64_t Construct_TXT_8349D6D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D6D4_G_ = int32_t(0x8349D6D4);
	constexpr int32_t str_TXT_820E8230_B_ = int32_t(0x820E8230);
	constexpr int32_t Destroy_TXT_8349D6D4_G__address = int32_t(0x832A9770);
	if (!UseLiftedCode(144, 0x83278A10)) { __imp__sub_83278A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6D4_G_, str_TXT_820E8230_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D6D4_G__address);
}
PROMOTED_ENTRY(144, sub_83278A10, 0x83278A10) { ctx.r3.u64 = Construct_TXT_8349D6D4_G_(ctx, base); }

uint64_t Construct_TXT_8349D6D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D6D8_G_ = int32_t(0x8349D6D8);
	constexpr int32_t str_TXT_820E8260_B_ = int32_t(0x820E8260);
	constexpr int32_t Destroy_TXT_8349D6D8_G__address = int32_t(0x832A9780);
	if (!UseLiftedCode(144, 0x83278A50)) { __imp__sub_83278A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6D8_G_, str_TXT_820E8260_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D6D8_G__address);
}
PROMOTED_ENTRY(144, sub_83278A50, 0x83278A50) { ctx.r3.u64 = Construct_TXT_8349D6D8_G_(ctx, base); }

uint64_t Construct_TXT_8349D6DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D6DC_G_ = int32_t(0x8349D6DC);
	constexpr int32_t str_TXT_820E8288_B_ = int32_t(0x820E8288);
	constexpr int32_t Destroy_TXT_8349D6DC_G__address = int32_t(0x832A9790);
	if (!UseLiftedCode(144, 0x83278A90)) { __imp__sub_83278A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6DC_G_, str_TXT_820E8288_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D6DC_G__address);
}
PROMOTED_ENTRY(144, sub_83278A90, 0x83278A90) { ctx.r3.u64 = Construct_TXT_8349D6DC_G_(ctx, base); }

uint64_t Construct_TXT_8349D6E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D6E0_G_ = int32_t(0x8349D6E0);
	constexpr int32_t str_TXT_820E8288_B_ = int32_t(0x820E82BC);
	constexpr int32_t Destroy_TXT_8349D6E0_G__address = int32_t(0x832A97A0);
	if (!UseLiftedCode(144, 0x83278AD0)) { __imp__sub_83278AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6E0_G_, str_TXT_820E8288_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D6E0_G__address);
}
PROMOTED_ENTRY(144, sub_83278AD0, 0x83278AD0) { ctx.r3.u64 = Construct_TXT_8349D6E0_G_(ctx, base); }

uint64_t Construct_TXT_8349D6E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D6E4_G_ = int32_t(0x8349D6E4);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349D6E4_G__address = int32_t(0x832A97B0);
	if (!UseLiftedCode(144, 0x83278B10)) { __imp__sub_83278B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278B10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6E4_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D6E4_G__address);
}
PROMOTED_ENTRY(144, sub_83278B10, 0x83278B10) { ctx.r3.u64 = Construct_TXT_8349D6E4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__62 = 0x8349D714u;
	if (!UseLiftedCode(144, 0x83279390)) { __imp__sub_83279390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279390);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279390, 0x83279390) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__62(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__64 = 0x8349D718u;
	if (!UseLiftedCode(144, 0x832793C8)) { __imp__sub_832793C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832793C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832793C8, 0x832793C8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__64(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__63 = 0x8349D71Cu;
	if (!UseLiftedCode(144, 0x83279400)) { __imp__sub_83279400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279400);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279400, 0x83279400) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__62 = 0x8349D720u;
	if (!UseLiftedCode(144, 0x83279438)) { __imp__sub_83279438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279438);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279438, 0x83279438) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__62 = 0x8349D724u;
	if (!UseLiftedCode(144, 0x83279470)) { __imp__sub_83279470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279470);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279470, 0x83279470) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__63 = 0x8349D728u;
	if (!UseLiftedCode(144, 0x832794A8)) { __imp__sub_832794A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832794A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832794A8, 0x832794A8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__62 = 0x8349D72Cu;
	if (!UseLiftedCode(144, 0x832794E0)) { __imp__sub_832794E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832794E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832794E0, 0x832794E0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__62 = 0x8349D730u;
	if (!UseLiftedCode(144, 0x83279518)) { __imp__sub_83279518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279518);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279518, 0x83279518) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__62 = 0x8349D734u;
	if (!UseLiftedCode(144, 0x83279550)) { __imp__sub_83279550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279550);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279550, 0x83279550) { ctx.r3.u64 = HashName_TXT_820A2C74_B__62(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__62 = 0x8349D738u;
	if (!UseLiftedCode(144, 0x83279588)) { __imp__sub_83279588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279588);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279588, 0x83279588) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__62 = 0x8349D73Cu;
	if (!UseLiftedCode(144, 0x832795C0)) { __imp__sub_832795C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832795C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832795C0, 0x832795C0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__62 = 0x8349D740u;
	if (!UseLiftedCode(144, 0x832795F8)) { __imp__sub_832795F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832795F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832795F8, 0x832795F8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__65 = 0x8349D744u;
	if (!UseLiftedCode(144, 0x83279630)) { __imp__sub_83279630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279630);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279630, 0x83279630) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__62 = 0x8349D748u;
	if (!UseLiftedCode(144, 0x83279668)) { __imp__sub_83279668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279668, 0x83279668) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__62 = 0x8349D74Cu;
	if (!UseLiftedCode(144, 0x832796A0)) { __imp__sub_832796A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832796A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832796A0, 0x832796A0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__62(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__62 = 0x8349D750u;
	if (!UseLiftedCode(144, 0x832796D8)) { __imp__sub_832796D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832796D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832796D8, 0x832796D8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__62(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__62 = 0x8349D754u;
	if (!UseLiftedCode(144, 0x83279710)) { __imp__sub_83279710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279710);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279710, 0x83279710) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__63 = 0x8349D758u;
	if (!UseLiftedCode(144, 0x83279748)) { __imp__sub_83279748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279748);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279748, 0x83279748) { ctx.r3.u64 = HashName_TXT_820A2D24_B__63(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__62 = 0x8349D75Cu;
	if (!UseLiftedCode(144, 0x83279780)) { __imp__sub_83279780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279780);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279780, 0x83279780) { ctx.r3.u64 = HashName_TXT_820A2D30_B__62(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__62 = 0x8349D760u;
	if (!UseLiftedCode(144, 0x832797B8)) { __imp__sub_832797B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832797B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832797B8, 0x832797B8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__62(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__62(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__62 = 0x8349D764u;
	if (!UseLiftedCode(144, 0x832797F0)) { __imp__sub_832797F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832797F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__62, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832797F0, 0x832797F0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__62(ctx, base); }

uint64_t Construct_TXT_8349D768_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D768_G_ = int32_t(0x8349D768);
	constexpr int32_t str_TXT_820E833C_B_ = int32_t(0x820E833C);
	constexpr int32_t Destroy_TXT_8349D768_G__address = int32_t(0x832A9818);
	if (!UseLiftedCode(144, 0x83279828)) { __imp__sub_83279828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279828);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D768_G_, str_TXT_820E833C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D768_G__address);
}
PROMOTED_ENTRY(144, sub_83279828, 0x83279828) { ctx.r3.u64 = Construct_TXT_8349D768_G_(ctx, base); }

uint64_t Construct_TXT_8349D76C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D76C_G_ = int32_t(0x8349D76C);
	constexpr int32_t str_TXT_820E8370_B_ = int32_t(0x820E8370);
	constexpr int32_t Destroy_TXT_8349D76C_G__address = int32_t(0x832A9828);
	if (!UseLiftedCode(144, 0x83279868)) { __imp__sub_83279868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279868);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D76C_G_, str_TXT_820E8370_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D76C_G__address);
}
PROMOTED_ENTRY(144, sub_83279868, 0x83279868) { ctx.r3.u64 = Construct_TXT_8349D76C_G_(ctx, base); }

uint64_t Construct_TXT_8349D770_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D770_G_ = int32_t(0x8349D770);
	constexpr int32_t str_TXT_820E83A8_B_ = int32_t(0x820E83A8);
	constexpr int32_t Destroy_TXT_8349D770_G__address = int32_t(0x832A9838);
	if (!UseLiftedCode(144, 0x832798A8)) { __imp__sub_832798A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832798A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D770_G_, str_TXT_820E83A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D770_G__address);
}
PROMOTED_ENTRY(144, sub_832798A8, 0x832798A8) { ctx.r3.u64 = Construct_TXT_8349D770_G_(ctx, base); }

uint64_t Construct_TXT_8349D774_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D774_G_ = int32_t(0x8349D774);
	constexpr int32_t str_TXT_820E83A8_B_ = int32_t(0x820E83DC);
	constexpr int32_t Destroy_TXT_8349D774_G__address = int32_t(0x832A9848);
	if (!UseLiftedCode(144, 0x832798E8)) { __imp__sub_832798E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832798E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D774_G_, str_TXT_820E83A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D774_G__address);
}
PROMOTED_ENTRY(144, sub_832798E8, 0x832798E8) { ctx.r3.u64 = Construct_TXT_8349D774_G_(ctx, base); }

uint64_t Construct_TXT_8349D778_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D778_G_ = int32_t(0x8349D778);
	constexpr int32_t str_TXT_820E841C_B_ = int32_t(0x820E841C);
	constexpr int32_t Destroy_TXT_8349D778_G__address = int32_t(0x832A9858);
	if (!UseLiftedCode(144, 0x83279928)) { __imp__sub_83279928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279928);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D778_G_, str_TXT_820E841C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D778_G__address);
}
PROMOTED_ENTRY(144, sub_83279928, 0x83279928) { ctx.r3.u64 = Construct_TXT_8349D778_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__63 = 0x8349D77Cu;
	if (!UseLiftedCode(144, 0x83279968)) { __imp__sub_83279968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279968);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279968, 0x83279968) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__63(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__65 = 0x8349D780u;
	if (!UseLiftedCode(144, 0x832799A0)) { __imp__sub_832799A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832799A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832799A0, 0x832799A0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__65(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__64 = 0x8349D784u;
	if (!UseLiftedCode(144, 0x832799D8)) { __imp__sub_832799D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832799D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832799D8, 0x832799D8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__63 = 0x8349D788u;
	if (!UseLiftedCode(144, 0x83279A10)) { __imp__sub_83279A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279A10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279A10, 0x83279A10) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__63 = 0x8349D78Cu;
	if (!UseLiftedCode(144, 0x83279A48)) { __imp__sub_83279A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279A48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279A48, 0x83279A48) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__64 = 0x8349D790u;
	if (!UseLiftedCode(144, 0x83279A80)) { __imp__sub_83279A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279A80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279A80, 0x83279A80) { ctx.r3.u64 = HashName_TXT_820A2C34_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__63 = 0x8349D794u;
	if (!UseLiftedCode(144, 0x83279AB8)) { __imp__sub_83279AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279AB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279AB8, 0x83279AB8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__63 = 0x8349D798u;
	if (!UseLiftedCode(144, 0x83279AF0)) { __imp__sub_83279AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279AF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279AF0, 0x83279AF0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__63 = 0x8349D79Cu;
	if (!UseLiftedCode(144, 0x83279B28)) { __imp__sub_83279B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279B28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279B28, 0x83279B28) { ctx.r3.u64 = HashName_TXT_820A2C74_B__63(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__63 = 0x8349D7A0u;
	if (!UseLiftedCode(144, 0x83279B60)) { __imp__sub_83279B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279B60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279B60, 0x83279B60) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__63 = 0x8349D7A4u;
	if (!UseLiftedCode(144, 0x83279B98)) { __imp__sub_83279B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279B98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279B98, 0x83279B98) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__63 = 0x8349D7A8u;
	if (!UseLiftedCode(144, 0x83279BD0)) { __imp__sub_83279BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279BD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279BD0, 0x83279BD0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__66(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__66 = 0x8349D7ACu;
	if (!UseLiftedCode(144, 0x83279C08)) { __imp__sub_83279C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279C08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__66, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279C08, 0x83279C08) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__66(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__63 = 0x8349D7B0u;
	if (!UseLiftedCode(144, 0x83279C40)) { __imp__sub_83279C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279C40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279C40, 0x83279C40) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__63 = 0x8349D7B4u;
	if (!UseLiftedCode(144, 0x83279C78)) { __imp__sub_83279C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279C78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279C78, 0x83279C78) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__63(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__63 = 0x8349D7B8u;
	if (!UseLiftedCode(144, 0x83279CB0)) { __imp__sub_83279CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279CB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279CB0, 0x83279CB0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__63(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__63 = 0x8349D7BCu;
	if (!UseLiftedCode(144, 0x83279CE8)) { __imp__sub_83279CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279CE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279CE8, 0x83279CE8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__64 = 0x8349D7C0u;
	if (!UseLiftedCode(144, 0x83279D20)) { __imp__sub_83279D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279D20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279D20, 0x83279D20) { ctx.r3.u64 = HashName_TXT_820A2D24_B__64(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__63 = 0x8349D7C4u;
	if (!UseLiftedCode(144, 0x83279D58)) { __imp__sub_83279D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279D58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279D58, 0x83279D58) { ctx.r3.u64 = HashName_TXT_820A2D30_B__63(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__63 = 0x8349D7C8u;
	if (!UseLiftedCode(144, 0x83279D90)) { __imp__sub_83279D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279D90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279D90, 0x83279D90) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__63(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__63(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__63 = 0x8349D7CCu;
	if (!UseLiftedCode(144, 0x83279DC8)) { __imp__sub_83279DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__63, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83279DC8, 0x83279DC8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__63(ctx, base); }

uint64_t Construct_TXT_8349D7D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7D0_G_ = int32_t(0x8349D7D0);
	constexpr int32_t str_TXT_820E8550_B_ = int32_t(0x820E8550);
	constexpr int32_t Destroy_TXT_8349D7D0_G__address = int32_t(0x832A9868);
	if (!UseLiftedCode(144, 0x83279E00)) { __imp__sub_83279E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D0_G_, str_TXT_820E8550_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7D0_G__address);
}
PROMOTED_ENTRY(144, sub_83279E00, 0x83279E00) { ctx.r3.u64 = Construct_TXT_8349D7D0_G_(ctx, base); }

uint64_t Construct_TXT_8349D7D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7D4_G_ = int32_t(0x8349D7D4);
	constexpr int32_t str_TXT_820E8584_B_ = int32_t(0x820E8584);
	constexpr int32_t Destroy_TXT_8349D7D4_G__address = int32_t(0x832A9878);
	if (!UseLiftedCode(144, 0x83279E40)) { __imp__sub_83279E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D4_G_, str_TXT_820E8584_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7D4_G__address);
}
PROMOTED_ENTRY(144, sub_83279E40, 0x83279E40) { ctx.r3.u64 = Construct_TXT_8349D7D4_G_(ctx, base); }

uint64_t Construct_TXT_8349D7D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7D8_G_ = int32_t(0x8349D7D8);
	constexpr int32_t str_TXT_820E85B8_B_ = int32_t(0x820E85B8);
	constexpr int32_t Destroy_TXT_8349D7D8_G__address = int32_t(0x832A9888);
	if (!UseLiftedCode(144, 0x83279E80)) { __imp__sub_83279E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D8_G_, str_TXT_820E85B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7D8_G__address);
}
PROMOTED_ENTRY(144, sub_83279E80, 0x83279E80) { ctx.r3.u64 = Construct_TXT_8349D7D8_G_(ctx, base); }

uint64_t Construct_TXT_8349D7DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7DC_G_ = int32_t(0x8349D7DC);
	constexpr int32_t str_TXT_820E85EC_B_ = int32_t(0x820E85EC);
	constexpr int32_t Destroy_TXT_8349D7DC_G__address = int32_t(0x832A9898);
	if (!UseLiftedCode(144, 0x83279EC0)) { __imp__sub_83279EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279EC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7DC_G_, str_TXT_820E85EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7DC_G__address);
}
PROMOTED_ENTRY(144, sub_83279EC0, 0x83279EC0) { ctx.r3.u64 = Construct_TXT_8349D7DC_G_(ctx, base); }

uint64_t Construct_TXT_8349D7E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7E0_G_ = int32_t(0x8349D7E0);
	constexpr int32_t str_TXT_820E8620_B_ = int32_t(0x820E8620);
	constexpr int32_t Destroy_TXT_8349D7E0_G__address = int32_t(0x832A98A8);
	if (!UseLiftedCode(144, 0x83279F00)) { __imp__sub_83279F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E0_G_, str_TXT_820E8620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7E0_G__address);
}
PROMOTED_ENTRY(144, sub_83279F00, 0x83279F00) { ctx.r3.u64 = Construct_TXT_8349D7E0_G_(ctx, base); }

uint64_t Construct_TXT_8349D7E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7E4_G_ = int32_t(0x8349D7E4);
	constexpr int32_t str_TXT_820E8620_B_ = int32_t(0x820E8654);
	constexpr int32_t Destroy_TXT_8349D7E4_G__address = int32_t(0x832A98B8);
	if (!UseLiftedCode(144, 0x83279F40)) { __imp__sub_83279F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E4_G_, str_TXT_820E8620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7E4_G__address);
}
PROMOTED_ENTRY(144, sub_83279F40, 0x83279F40) { ctx.r3.u64 = Construct_TXT_8349D7E4_G_(ctx, base); }

uint64_t Construct_TXT_8349D7E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7E8_G_ = int32_t(0x8349D7E8);
	constexpr int32_t str_TXT_820E8620_B_ = int32_t(0x820E8690);
	constexpr int32_t Destroy_TXT_8349D7E8_G__address = int32_t(0x832A98C8);
	if (!UseLiftedCode(144, 0x83279F80)) { __imp__sub_83279F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E8_G_, str_TXT_820E8620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7E8_G__address);
}
PROMOTED_ENTRY(144, sub_83279F80, 0x83279F80) { ctx.r3.u64 = Construct_TXT_8349D7E8_G_(ctx, base); }

uint64_t Construct_TXT_8349D7EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7EC_G_ = int32_t(0x8349D7EC);
	constexpr int32_t str_TXT_820E8620_B_ = int32_t(0x820E86D0);
	constexpr int32_t Destroy_TXT_8349D7EC_G__address = int32_t(0x832A98D8);
	if (!UseLiftedCode(144, 0x83279FC0)) { __imp__sub_83279FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7EC_G_, str_TXT_820E8620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7EC_G__address);
}
PROMOTED_ENTRY(144, sub_83279FC0, 0x83279FC0) { ctx.r3.u64 = Construct_TXT_8349D7EC_G_(ctx, base); }

uint64_t Construct_TXT_8349D7F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7F0_G_ = int32_t(0x8349D7F0);
	constexpr int32_t str_TXT_820E8620_B_ = int32_t(0x820E870C);
	constexpr int32_t Destroy_TXT_8349D7F0_G__address = int32_t(0x832A98E8);
	if (!UseLiftedCode(144, 0x8327A000)) { __imp__sub_8327A000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A000);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F0_G_, str_TXT_820E8620_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7F0_G__address);
}
PROMOTED_ENTRY(144, sub_8327A000, 0x8327A000) { ctx.r3.u64 = Construct_TXT_8349D7F0_G_(ctx, base); }

uint64_t Construct_TXT_8349D7F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7F4_G_ = int32_t(0x8349D7F4);
	constexpr int32_t str_TXT_820E874C_B_ = int32_t(0x820E874C);
	constexpr int32_t Destroy_TXT_8349D7F4_G__address = int32_t(0x832A98F8);
	if (!UseLiftedCode(144, 0x8327A040)) { __imp__sub_8327A040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A040);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F4_G_, str_TXT_820E874C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7F4_G__address);
}
PROMOTED_ENTRY(144, sub_8327A040, 0x8327A040) { ctx.r3.u64 = Construct_TXT_8349D7F4_G_(ctx, base); }

uint64_t Construct_TXT_8349D7F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7F8_G_ = int32_t(0x8349D7F8);
	constexpr int32_t str_TXT_820E877C_B_ = int32_t(0x820E877C);
	constexpr int32_t Destroy_TXT_8349D7F8_G__address = int32_t(0x832A9908);
	if (!UseLiftedCode(144, 0x8327A080)) { __imp__sub_8327A080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A080);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F8_G_, str_TXT_820E877C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7F8_G__address);
}
PROMOTED_ENTRY(144, sub_8327A080, 0x8327A080) { ctx.r3.u64 = Construct_TXT_8349D7F8_G_(ctx, base); }

uint64_t Construct_TXT_8349D7FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D7FC_G_ = int32_t(0x8349D7FC);
	constexpr int32_t str_TXT_820E877C_B_ = int32_t(0x820E87AC);
	constexpr int32_t Destroy_TXT_8349D7FC_G__address = int32_t(0x832A9918);
	if (!UseLiftedCode(144, 0x8327A0C0)) { __imp__sub_8327A0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A0C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7FC_G_, str_TXT_820E877C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D7FC_G__address);
}
PROMOTED_ENTRY(144, sub_8327A0C0, 0x8327A0C0) { ctx.r3.u64 = Construct_TXT_8349D7FC_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__64 = 0x8349D800u;
	if (!UseLiftedCode(144, 0x8327A100)) { __imp__sub_8327A100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A100);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A100, 0x8327A100) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__64(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__66(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__66 = 0x8349D804u;
	if (!UseLiftedCode(144, 0x8327A138)) { __imp__sub_8327A138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A138);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__66, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A138, 0x8327A138) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__66(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__65 = 0x8349D808u;
	if (!UseLiftedCode(144, 0x8327A170)) { __imp__sub_8327A170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A170);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A170, 0x8327A170) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__64 = 0x8349D80Cu;
	if (!UseLiftedCode(144, 0x8327A1A8)) { __imp__sub_8327A1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A1A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A1A8, 0x8327A1A8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__64 = 0x8349D810u;
	if (!UseLiftedCode(144, 0x8327A1E0)) { __imp__sub_8327A1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A1E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A1E0, 0x8327A1E0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__65 = 0x8349D814u;
	if (!UseLiftedCode(144, 0x8327A218)) { __imp__sub_8327A218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A218);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A218, 0x8327A218) { ctx.r3.u64 = HashName_TXT_820A2C34_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__64 = 0x8349D818u;
	if (!UseLiftedCode(144, 0x8327A250)) { __imp__sub_8327A250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A250);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A250, 0x8327A250) { ctx.r3.u64 = HashName_TXT_820A2C44_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__64 = 0x8349D81Cu;
	if (!UseLiftedCode(144, 0x8327A288)) { __imp__sub_8327A288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A288);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A288, 0x8327A288) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__64 = 0x8349D820u;
	if (!UseLiftedCode(144, 0x8327A2C0)) { __imp__sub_8327A2C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A2C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A2C0, 0x8327A2C0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__64(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__64 = 0x8349D824u;
	if (!UseLiftedCode(144, 0x8327A2F8)) { __imp__sub_8327A2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A2F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A2F8, 0x8327A2F8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__64 = 0x8349D828u;
	if (!UseLiftedCode(144, 0x8327A330)) { __imp__sub_8327A330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A330);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A330, 0x8327A330) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__64 = 0x8349D82Cu;
	if (!UseLiftedCode(144, 0x8327A368)) { __imp__sub_8327A368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A368);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A368, 0x8327A368) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__67(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__67 = 0x8349D830u;
	if (!UseLiftedCode(144, 0x8327A3A0)) { __imp__sub_8327A3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A3A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__67, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A3A0, 0x8327A3A0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__67(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__64 = 0x8349D834u;
	if (!UseLiftedCode(144, 0x8327A3D8)) { __imp__sub_8327A3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A3D8, 0x8327A3D8) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__64 = 0x8349D838u;
	if (!UseLiftedCode(144, 0x8327A410)) { __imp__sub_8327A410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A410);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A410, 0x8327A410) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__64(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__64 = 0x8349D83Cu;
	if (!UseLiftedCode(144, 0x8327A448)) { __imp__sub_8327A448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A448);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A448, 0x8327A448) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__64(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__64 = 0x8349D840u;
	if (!UseLiftedCode(144, 0x8327A480)) { __imp__sub_8327A480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A480);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A480, 0x8327A480) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__65 = 0x8349D844u;
	if (!UseLiftedCode(144, 0x8327A4B8)) { __imp__sub_8327A4B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A4B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A4B8, 0x8327A4B8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__65(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__64 = 0x8349D848u;
	if (!UseLiftedCode(144, 0x8327A4F0)) { __imp__sub_8327A4F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A4F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A4F0, 0x8327A4F0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__64(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__64 = 0x8349D84Cu;
	if (!UseLiftedCode(144, 0x8327A528)) { __imp__sub_8327A528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A528);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A528, 0x8327A528) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__64(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__64 = 0x8349D850u;
	if (!UseLiftedCode(144, 0x8327A560)) { __imp__sub_8327A560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A560);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__64, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327A560, 0x8327A560) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__64(ctx, base); }

uint64_t Construct_TXT_8349D854_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D854_G_ = int32_t(0x8349D854);
	constexpr int32_t str_TXT_820E882C_B_ = int32_t(0x820E882C);
	constexpr int32_t Destroy_TXT_8349D854_G__address = int32_t(0x832A9928);
	if (!UseLiftedCode(144, 0x8327A598)) { __imp__sub_8327A598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D854_G_, str_TXT_820E882C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D854_G__address);
}
PROMOTED_ENTRY(144, sub_8327A598, 0x8327A598) { ctx.r3.u64 = Construct_TXT_8349D854_G_(ctx, base); }

uint64_t Construct_TXT_8349D858_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D858_G_ = int32_t(0x8349D858);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8860);
	constexpr int32_t Destroy_TXT_8349D858_G__address = int32_t(0x832A9938);
	if (!UseLiftedCode(144, 0x8327A5D8)) { __imp__sub_8327A5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D858_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D858_G__address);
}
PROMOTED_ENTRY(144, sub_8327A5D8, 0x8327A5D8) { ctx.r3.u64 = Construct_TXT_8349D858_G_(ctx, base); }

uint64_t Construct_TXT_8349D85C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D85C_G_ = int32_t(0x8349D85C);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E88A0);
	constexpr int32_t Destroy_TXT_8349D85C_G__address = int32_t(0x832A9948);
	if (!UseLiftedCode(144, 0x8327A618)) { __imp__sub_8327A618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A618);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D85C_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D85C_G__address);
}
PROMOTED_ENTRY(144, sub_8327A618, 0x8327A618) { ctx.r3.u64 = Construct_TXT_8349D85C_G_(ctx, base); }

uint64_t Construct_TXT_8349D860_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D860_G_ = int32_t(0x8349D860);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E88D8);
	constexpr int32_t Destroy_TXT_8349D860_G__address = int32_t(0x832A9958);
	if (!UseLiftedCode(144, 0x8327A658)) { __imp__sub_8327A658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A658);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D860_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D860_G__address);
}
PROMOTED_ENTRY(144, sub_8327A658, 0x8327A658) { ctx.r3.u64 = Construct_TXT_8349D860_G_(ctx, base); }

uint64_t Construct_TXT_8349D864_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D864_G_ = int32_t(0x8349D864);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8920);
	constexpr int32_t Destroy_TXT_8349D864_G__address = int32_t(0x832A9968);
	if (!UseLiftedCode(144, 0x8327A698)) { __imp__sub_8327A698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A698);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D864_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D864_G__address);
}
PROMOTED_ENTRY(144, sub_8327A698, 0x8327A698) { ctx.r3.u64 = Construct_TXT_8349D864_G_(ctx, base); }

uint64_t Construct_TXT_8349D868_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D868_G_ = int32_t(0x8349D868);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8968);
	constexpr int32_t Destroy_TXT_8349D868_G__address = int32_t(0x832A9978);
	if (!UseLiftedCode(144, 0x8327A6D8)) { __imp__sub_8327A6D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A6D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D868_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D868_G__address);
}
PROMOTED_ENTRY(144, sub_8327A6D8, 0x8327A6D8) { ctx.r3.u64 = Construct_TXT_8349D868_G_(ctx, base); }

uint64_t Construct_TXT_8349D86C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D86C_G_ = int32_t(0x8349D86C);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E89AC);
	constexpr int32_t Destroy_TXT_8349D86C_G__address = int32_t(0x832A9988);
	if (!UseLiftedCode(144, 0x8327A718)) { __imp__sub_8327A718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A718);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D86C_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D86C_G__address);
}
PROMOTED_ENTRY(144, sub_8327A718, 0x8327A718) { ctx.r3.u64 = Construct_TXT_8349D86C_G_(ctx, base); }

uint64_t Construct_TXT_8349D870_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D870_G_ = int32_t(0x8349D870);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E89E8);
	constexpr int32_t Destroy_TXT_8349D870_G__address = int32_t(0x832A9998);
	if (!UseLiftedCode(144, 0x8327A758)) { __imp__sub_8327A758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D870_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D870_G__address);
}
PROMOTED_ENTRY(144, sub_8327A758, 0x8327A758) { ctx.r3.u64 = Construct_TXT_8349D870_G_(ctx, base); }

uint64_t Construct_TXT_8349D874_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D874_G_ = int32_t(0x8349D874);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8A30);
	constexpr int32_t Destroy_TXT_8349D874_G__address = int32_t(0x832A99A8);
	if (!UseLiftedCode(144, 0x8327A798)) { __imp__sub_8327A798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D874_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D874_G__address);
}
PROMOTED_ENTRY(144, sub_8327A798, 0x8327A798) { ctx.r3.u64 = Construct_TXT_8349D874_G_(ctx, base); }

uint64_t Construct_TXT_8349D878_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D878_G_ = int32_t(0x8349D878);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8A78);
	constexpr int32_t Destroy_TXT_8349D878_G__address = int32_t(0x832A99B8);
	if (!UseLiftedCode(144, 0x8327A7D8)) { __imp__sub_8327A7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A7D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D878_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D878_G__address);
}
PROMOTED_ENTRY(144, sub_8327A7D8, 0x8327A7D8) { ctx.r3.u64 = Construct_TXT_8349D878_G_(ctx, base); }

uint64_t Construct_TXT_8349D87C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D87C_G_ = int32_t(0x8349D87C);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8AC8);
	constexpr int32_t Destroy_TXT_8349D87C_G__address = int32_t(0x832A99C8);
	if (!UseLiftedCode(144, 0x8327A818)) { __imp__sub_8327A818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D87C_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D87C_G__address);
}
PROMOTED_ENTRY(144, sub_8327A818, 0x8327A818) { ctx.r3.u64 = Construct_TXT_8349D87C_G_(ctx, base); }

uint64_t Construct_TXT_8349D880_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D880_G_ = int32_t(0x8349D880);
	constexpr int32_t str_TXT_820E8860_B_ = int32_t(0x820E8B18);
	constexpr int32_t Destroy_TXT_8349D880_G__address = int32_t(0x832A99D8);
	if (!UseLiftedCode(144, 0x8327A858)) { __imp__sub_8327A858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A858);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D880_G_, str_TXT_820E8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D880_G__address);
}
PROMOTED_ENTRY(144, sub_8327A858, 0x8327A858) { ctx.r3.u64 = Construct_TXT_8349D880_G_(ctx, base); }

uint64_t Construct_TXT_8349D884_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D884_G_ = int32_t(0x8349D884);
	constexpr int32_t str_TXT_820E8B64_B_ = int32_t(0x820E8B64);
	constexpr int32_t Destroy_TXT_8349D884_G__address = int32_t(0x832A99E8);
	if (!UseLiftedCode(144, 0x8327A898)) { __imp__sub_8327A898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D884_G_, str_TXT_820E8B64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D884_G__address);
}
PROMOTED_ENTRY(144, sub_8327A898, 0x8327A898) { ctx.r3.u64 = Construct_TXT_8349D884_G_(ctx, base); }

uint64_t Construct_TXT_8349D888_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D888_G_ = int32_t(0x8349D888);
	constexpr int32_t str_TXT_820E8B64_B_ = int32_t(0x820E8B98);
	constexpr int32_t Destroy_TXT_8349D888_G__address = int32_t(0x832A99F8);
	if (!UseLiftedCode(144, 0x8327A8D8)) { __imp__sub_8327A8D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A8D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D888_G_, str_TXT_820E8B64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D888_G__address);
}
PROMOTED_ENTRY(144, sub_8327A8D8, 0x8327A8D8) { ctx.r3.u64 = Construct_TXT_8349D888_G_(ctx, base); }

uint64_t Construct_TXT_8349D88C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D88C_G_ = int32_t(0x8349D88C);
	constexpr int32_t str_TXT_820E8BD8_B_ = int32_t(0x820E8BD8);
	constexpr int32_t Destroy_TXT_8349D88C_G__address = int32_t(0x832A9A08);
	if (!UseLiftedCode(144, 0x8327A918)) { __imp__sub_8327A918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A918);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D88C_G_, str_TXT_820E8BD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D88C_G__address);
}
PROMOTED_ENTRY(144, sub_8327A918, 0x8327A918) { ctx.r3.u64 = Construct_TXT_8349D88C_G_(ctx, base); }

uint64_t Construct_TXT_8349D890_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D890_G_ = int32_t(0x8349D890);
	constexpr int32_t str_TXT_820E8C6C_B_ = int32_t(0x820E8C6C);
	constexpr int32_t Destroy_TXT_8349D890_G__address = int32_t(0x832A9A18);
	if (!UseLiftedCode(144, 0x8327A958)) { __imp__sub_8327A958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A958);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D890_G_, str_TXT_820E8C6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D890_G__address);
}
PROMOTED_ENTRY(144, sub_8327A958, 0x8327A958) { ctx.r3.u64 = Construct_TXT_8349D890_G_(ctx, base); }

uint64_t Construct_TXT_8349D894_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D894_G_ = int32_t(0x8349D894);
	constexpr int32_t str_TXT_820E8C90_B_ = int32_t(0x820E8C90);
	constexpr int32_t Destroy_TXT_8349D894_G__address = int32_t(0x832A9A28);
	if (!UseLiftedCode(144, 0x8327A998)) { __imp__sub_8327A998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A998);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D894_G_, str_TXT_820E8C90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D894_G__address);
}
PROMOTED_ENTRY(144, sub_8327A998, 0x8327A998) { ctx.r3.u64 = Construct_TXT_8349D894_G_(ctx, base); }

uint64_t Construct_TXT_8349D898_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D898_G_ = int32_t(0x8349D898);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349D898_G__address = int32_t(0x832A9A38);
	if (!UseLiftedCode(144, 0x8327A9D8)) { __imp__sub_8327A9D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A9D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D898_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D898_G__address);
}
PROMOTED_ENTRY(144, sub_8327A9D8, 0x8327A9D8) { ctx.r3.u64 = Construct_TXT_8349D898_G_(ctx, base); }

uint64_t Construct_TXT_8349D89C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D89C_G_ = int32_t(0x8349D89C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349D89C_G__address = int32_t(0x832A9A48);
	if (!UseLiftedCode(144, 0x8327AA18)) { __imp__sub_8327AA18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D89C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D89C_G__address);
}
PROMOTED_ENTRY(144, sub_8327AA18, 0x8327AA18) { ctx.r3.u64 = Construct_TXT_8349D89C_G_(ctx, base); }

uint64_t Construct_TXT_8349D8A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D8A0_G_ = int32_t(0x8349D8A0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349D8A0_G__address = int32_t(0x832A9A58);
	if (!UseLiftedCode(144, 0x8327AA58)) { __imp__sub_8327AA58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D8A0_G__address);
}
PROMOTED_ENTRY(144, sub_8327AA58, 0x8327AA58) { ctx.r3.u64 = Construct_TXT_8349D8A0_G_(ctx, base); }

uint64_t Construct_TXT_8349D8A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D8A4_G_ = int32_t(0x8349D8A4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349D8A4_G__address = int32_t(0x832A9A68);
	if (!UseLiftedCode(144, 0x8327AA98)) { __imp__sub_8327AA98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D8A4_G__address);
}
PROMOTED_ENTRY(144, sub_8327AA98, 0x8327AA98) { ctx.r3.u64 = Construct_TXT_8349D8A4_G_(ctx, base); }

uint64_t Construct_TXT_8349D8A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349D8A8_G_ = int32_t(0x8349D8A8);
	constexpr int32_t str_TXT_820E9B5C_B_ = int32_t(0x820E9B5C);
	constexpr int32_t Destroy_TXT_8349D8A8_G__address = int32_t(0x832A9A88);
	if (!UseLiftedCode(144, 0x8327AAD8)) { __imp__sub_8327AAD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AAD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A8_G_, str_TXT_820E9B5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349D8A8_G__address);
}
PROMOTED_ENTRY(144, sub_8327AAD8, 0x8327AAD8) { ctx.r3.u64 = Construct_TXT_8349D8A8_G_(ctx, base); }

uint64_t HashName_TXT_820A84DC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A84DC_B_ = int32_t(0x820A84DC);
	constexpr uint32_t g_HashOf_TXT_820A84DC_B_ = 0x8349DB70u;
	if (!UseLiftedCode(144, 0x8327AB38)) { __imp__sub_8327AB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AB38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A84DC_B_);
	STORE32(g_HashOf_TXT_820A84DC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AB38, 0x8327AB38) { ctx.r3.u64 = HashName_TXT_820A84DC_B_(ctx, base); }

uint64_t HashName_TXT_82000F7C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000F7C_B_ = int32_t(0x82000F7C);
	constexpr uint32_t g_HashOf_TXT_82000F7C_B_ = 0x8349DB74u;
	if (!UseLiftedCode(144, 0x8327AB70)) { __imp__sub_8327AB70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AB70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82000F7C_B_);
	STORE32(g_HashOf_TXT_82000F7C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AB70, 0x8327AB70) { ctx.r3.u64 = HashName_TXT_82000F7C_B_(ctx, base); }

uint64_t HashName_TXT_820C2490_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C2490_B_ = int32_t(0x820C2490);
	constexpr uint32_t g_HashOf_TXT_820C2490_B_ = 0x8349DB78u;
	if (!UseLiftedCode(144, 0x8327ABA8)) { __imp__sub_8327ABA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ABA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C2490_B_);
	STORE32(g_HashOf_TXT_820C2490_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327ABA8, 0x8327ABA8) { ctx.r3.u64 = HashName_TXT_820C2490_B_(ctx, base); }

uint64_t HashName_TXT_820C24AC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C24AC_B_ = int32_t(0x820C24AC);
	constexpr uint32_t g_HashOf_TXT_820C24AC_B_ = 0x8349DB7Cu;
	if (!UseLiftedCode(144, 0x8327ABE0)) { __imp__sub_8327ABE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ABE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C24AC_B_);
	STORE32(g_HashOf_TXT_820C24AC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327ABE0, 0x8327ABE0) { ctx.r3.u64 = HashName_TXT_820C24AC_B_(ctx, base); }

uint64_t HashName_TXT_820C24B8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C24B8_B_ = int32_t(0x820C24B8);
	constexpr uint32_t g_HashOf_TXT_820C24B8_B_ = 0x8349DB80u;
	if (!UseLiftedCode(144, 0x8327AC18)) { __imp__sub_8327AC18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AC18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C24B8_B_);
	STORE32(g_HashOf_TXT_820C24B8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AC18, 0x8327AC18) { ctx.r3.u64 = HashName_TXT_820C24B8_B_(ctx, base); }

uint64_t HashName_TXT_820C24C4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C24C4_B_ = int32_t(0x820C24C4);
	constexpr uint32_t g_HashOf_TXT_820C24C4_B_ = 0x8349DB84u;
	if (!UseLiftedCode(144, 0x8327AC50)) { __imp__sub_8327AC50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AC50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C24C4_B_);
	STORE32(g_HashOf_TXT_820C24C4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AC50, 0x8327AC50) { ctx.r3.u64 = HashName_TXT_820C24C4_B_(ctx, base); }

uint64_t HashName_TXT_820C24D0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C24D0_B_ = int32_t(0x820C24D0);
	constexpr uint32_t g_HashOf_TXT_820C24D0_B_ = 0x8349DB88u;
	if (!UseLiftedCode(144, 0x8327AC88)) { __imp__sub_8327AC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AC88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C24D0_B_);
	STORE32(g_HashOf_TXT_820C24D0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AC88, 0x8327AC88) { ctx.r3.u64 = HashName_TXT_820C24D0_B_(ctx, base); }

uint64_t HashName_TXT_820C24F0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C24F0_B_ = int32_t(0x820C24F0);
	constexpr uint32_t g_HashOf_TXT_820C24F0_B_ = 0x8349DB8Cu;
	if (!UseLiftedCode(144, 0x8327ACC0)) { __imp__sub_8327ACC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ACC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C24F0_B_);
	STORE32(g_HashOf_TXT_820C24F0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327ACC0, 0x8327ACC0) { ctx.r3.u64 = HashName_TXT_820C24F0_B_(ctx, base); }

uint64_t HashName_TXT_820C251C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C251C_B_ = int32_t(0x820C251C);
	constexpr uint32_t g_HashOf_TXT_820C251C_B_ = 0x8349DB90u;
	if (!UseLiftedCode(144, 0x8327ACF8)) { __imp__sub_8327ACF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ACF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C251C_B_);
	STORE32(g_HashOf_TXT_820C251C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327ACF8, 0x8327ACF8) { ctx.r3.u64 = HashName_TXT_820C251C_B_(ctx, base); }

uint64_t HashName_TXT_820C2528_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C2528_B_ = int32_t(0x820C2528);
	constexpr uint32_t g_HashOf_TXT_820C2528_B_ = 0x8349DB94u;
	if (!UseLiftedCode(144, 0x8327AD30)) { __imp__sub_8327AD30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AD30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C2528_B_);
	STORE32(g_HashOf_TXT_820C2528_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AD30, 0x8327AD30) { ctx.r3.u64 = HashName_TXT_820C2528_B_(ctx, base); }

uint64_t HashName_TXT_820C2538_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C2538_B_ = int32_t(0x820C2538);
	constexpr uint32_t g_HashOf_TXT_820C2538_B_ = 0x8349DB98u;
	if (!UseLiftedCode(144, 0x8327AD68)) { __imp__sub_8327AD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AD68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C2538_B_);
	STORE32(g_HashOf_TXT_820C2538_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327AD68, 0x8327AD68) { ctx.r3.u64 = HashName_TXT_820C2538_B_(ctx, base); }

uint64_t HashName_TXT_820C2504_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C2504_B_ = int32_t(0x820C2504);
	constexpr uint32_t g_HashOf_TXT_820C2504_B_ = 0x8349DB9Cu;
	if (!UseLiftedCode(144, 0x8327ADA0)) { __imp__sub_8327ADA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ADA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C2504_B_);
	STORE32(g_HashOf_TXT_820C2504_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327ADA0, 0x8327ADA0) { ctx.r3.u64 = HashName_TXT_820C2504_B_(ctx, base); }

uint64_t CallIsZero_832A9B00(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9B00_address = int32_t(0x832A9B00);
	if (!UseLiftedCode(144, 0x8327B318)) { ctx.r8.u64 = value; __imp__sub_8327B318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B318);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9B00_address, value);
}
PROMOTED_ENTRY(144, sub_8327B318, 0x8327B318) { ctx.r3.u64 = CallIsZero_832A9B00(ctx, base, ctx.r8.u64); }

uint64_t CallIsZero_832A9B38(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9B38_address = int32_t(0x832A9B38);
	if (!UseLiftedCode(144, 0x8327B390)) { ctx.r8.u64 = value; __imp__sub_8327B390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B390);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9B38_address, value);
}
PROMOTED_ENTRY(144, sub_8327B390, 0x8327B390) { ctx.r3.u64 = CallIsZero_832A9B38(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349DEEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DEEC_G_ = int32_t(0x8349DEEC);
	constexpr int32_t str_TXT_820EB728_B_ = int32_t(0x820EB728);
	constexpr int32_t Destroy_TXT_8349DEEC_G__address = int32_t(0x832A9B60);
	if (!UseLiftedCode(144, 0x8327B3E8)) { __imp__sub_8327B3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B3E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DEEC_G_, str_TXT_820EB728_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DEEC_G__address);
}
PROMOTED_ENTRY(144, sub_8327B3E8, 0x8327B3E8) { ctx.r3.u64 = Construct_TXT_8349DEEC_G_(ctx, base); }

uint64_t CallIsZero_832A9B70(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9B70_address = int32_t(0x832A9B70);
	if (!UseLiftedCode(144, 0x8327B428)) { ctx.r8.u64 = value; __imp__sub_8327B428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B428);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9B70_address, value);
}
PROMOTED_ENTRY(144, sub_8327B428, 0x8327B428) { ctx.r3.u64 = CallIsZero_832A9B70(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349DF00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF00_G_ = int32_t(0x8349DF00);
	constexpr int32_t str_TXT_820EB764_B_ = int32_t(0x820EB764);
	constexpr int32_t Destroy_TXT_8349DF00_G__address = int32_t(0x832A9BC8);
	if (!UseLiftedCode(144, 0x8327B438)) { __imp__sub_8327B438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B438);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF00_G_, str_TXT_820EB764_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF00_G__address);
}
PROMOTED_ENTRY(144, sub_8327B438, 0x8327B438) { ctx.r3.u64 = Construct_TXT_8349DF00_G_(ctx, base); }

uint64_t Construct_TXT_8349DF04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF04_G_ = int32_t(0x8349DF04);
	constexpr int32_t str_TXT_820EB878_B_ = int32_t(0x820EB878);
	constexpr int32_t Destroy_TXT_8349DF04_G__address = int32_t(0x832A9BD8);
	if (!UseLiftedCode(144, 0x8327B478)) { __imp__sub_8327B478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B478);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF04_G_, str_TXT_820EB878_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF04_G__address);
}
PROMOTED_ENTRY(144, sub_8327B478, 0x8327B478) { ctx.r3.u64 = Construct_TXT_8349DF04_G_(ctx, base); }

uint64_t Construct_TXT_8349DF0C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF0C_G_ = int32_t(0x8349DF0C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349DF0C_G__address = int32_t(0x832A9BE8);
	if (!UseLiftedCode(144, 0x8327B4D8)) { __imp__sub_8327B4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF0C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF0C_G__address);
}
PROMOTED_ENTRY(144, sub_8327B4D8, 0x8327B4D8) { ctx.r3.u64 = Construct_TXT_8349DF0C_G_(ctx, base); }

uint64_t Construct_TXT_8349DF10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF10_G_ = int32_t(0x8349DF10);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349DF10_G__address = int32_t(0x832A9BF8);
	if (!UseLiftedCode(144, 0x8327B518)) { __imp__sub_8327B518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B518);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF10_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF10_G__address);
}
PROMOTED_ENTRY(144, sub_8327B518, 0x8327B518) { ctx.r3.u64 = Construct_TXT_8349DF10_G_(ctx, base); }

uint64_t Construct_TXT_8349DF14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF14_G_ = int32_t(0x8349DF14);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349DF14_G__address = int32_t(0x832A9C08);
	if (!UseLiftedCode(144, 0x8327B558)) { __imp__sub_8327B558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF14_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF14_G__address);
}
PROMOTED_ENTRY(144, sub_8327B558, 0x8327B558) { ctx.r3.u64 = Construct_TXT_8349DF14_G_(ctx, base); }

uint64_t Construct_TXT_8349DF1C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF1C_G_ = int32_t(0x8349DF1C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349DF1C_G__address = int32_t(0x832A9C28);
	if (!UseLiftedCode(144, 0x8327B5D8)) { __imp__sub_8327B5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF1C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF1C_G__address);
}
PROMOTED_ENTRY(144, sub_8327B5D8, 0x8327B5D8) { ctx.r3.u64 = Construct_TXT_8349DF1C_G_(ctx, base); }

uint64_t HashName_TXT_820EE628_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EE628_B_ = int32_t(0x820EE628);
	constexpr uint32_t g_HashOf_TXT_820EE628_B_ = 0x8349DF20u;
	if (!UseLiftedCode(144, 0x8327B618)) { __imp__sub_8327B618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B618);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EE628_B_);
	STORE32(g_HashOf_TXT_820EE628_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B618, 0x8327B618) { ctx.r3.u64 = HashName_TXT_820EE628_B_(ctx, base); }

uint64_t HashName_TXT_820EE63C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EE63C_B_ = int32_t(0x820EE63C);
	constexpr uint32_t g_HashOf_TXT_820EE63C_B_ = 0x8349DF24u;
	if (!UseLiftedCode(144, 0x8327B650)) { __imp__sub_8327B650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EE63C_B_);
	STORE32(g_HashOf_TXT_820EE63C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B650, 0x8327B650) { ctx.r3.u64 = HashName_TXT_820EE63C_B_(ctx, base); }

uint64_t HashName_TXT_820EE690_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EE690_B_ = int32_t(0x820EE690);
	constexpr uint32_t g_HashOf_TXT_820EE690_B_ = 0x8349DF28u;
	if (!UseLiftedCode(144, 0x8327B688)) { __imp__sub_8327B688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EE690_B_);
	STORE32(g_HashOf_TXT_820EE690_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B688, 0x8327B688) { ctx.r3.u64 = HashName_TXT_820EE690_B_(ctx, base); }

uint64_t HashName_TXT_820EE6A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EE6A8_B_ = int32_t(0x820EE6A8);
	constexpr uint32_t g_HashOf_TXT_820EE6A8_B_ = 0x8349DF2Cu;
	if (!UseLiftedCode(144, 0x8327B6C0)) { __imp__sub_8327B6C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B6C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EE6A8_B_);
	STORE32(g_HashOf_TXT_820EE6A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B6C0, 0x8327B6C0) { ctx.r3.u64 = HashName_TXT_820EE6A8_B_(ctx, base); }

uint64_t HashName_TXT_820EE8A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EE8A8_B_ = int32_t(0x820EE8A8);
	constexpr uint32_t g_HashOf_TXT_820EE8A8_B_ = 0x8349DF30u;
	if (!UseLiftedCode(144, 0x8327B6F8)) { __imp__sub_8327B6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B6F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EE8A8_B_);
	STORE32(g_HashOf_TXT_820EE8A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B6F8, 0x8327B6F8) { ctx.r3.u64 = HashName_TXT_820EE8A8_B_(ctx, base); }

uint64_t Construct_TXT_8349DF34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF34_G_ = int32_t(0x8349DF34);
	constexpr int32_t str_TXT_820EEDD8_B_ = int32_t(0x820EEDD8);
	constexpr int32_t Destroy_TXT_8349DF34_G__address = int32_t(0x832A9C38);
	if (!UseLiftedCode(144, 0x8327B730)) { __imp__sub_8327B730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF34_G_, str_TXT_820EEDD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF34_G__address);
}
PROMOTED_ENTRY(144, sub_8327B730, 0x8327B730) { ctx.r3.u64 = Construct_TXT_8349DF34_G_(ctx, base); }

uint64_t Construct_TXT_8349DF38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF38_G_ = int32_t(0x8349DF38);
	constexpr int32_t str_TXT_820EEDE4_B_ = int32_t(0x820EEDE4);
	constexpr int32_t Destroy_TXT_8349DF38_G__address = int32_t(0x832A9C48);
	if (!UseLiftedCode(144, 0x8327B770)) { __imp__sub_8327B770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF38_G_, str_TXT_820EEDE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF38_G__address);
}
PROMOTED_ENTRY(144, sub_8327B770, 0x8327B770) { ctx.r3.u64 = Construct_TXT_8349DF38_G_(ctx, base); }

uint64_t Construct_TXT_8349DF3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF3C_G_ = int32_t(0x8349DF3C);
	constexpr int32_t str_TXT_820EEDF0_B_ = int32_t(0x820EEDF0);
	constexpr int32_t Destroy_TXT_8349DF3C_G__address = int32_t(0x832A9C58);
	if (!UseLiftedCode(144, 0x8327B7B0)) { __imp__sub_8327B7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF3C_G_, str_TXT_820EEDF0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF3C_G__address);
}
PROMOTED_ENTRY(144, sub_8327B7B0, 0x8327B7B0) { ctx.r3.u64 = Construct_TXT_8349DF3C_G_(ctx, base); }

uint64_t Construct_TXT_8349DF40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF40_G_ = int32_t(0x8349DF40);
	constexpr int32_t str_TXT_820E4828_B_ = int32_t(0x820E4828);
	constexpr int32_t Destroy_TXT_8349DF40_G__address = int32_t(0x832A9C68);
	if (!UseLiftedCode(144, 0x8327B7F0)) { __imp__sub_8327B7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B7F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF40_G_, str_TXT_820E4828_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF40_G__address);
}
PROMOTED_ENTRY(144, sub_8327B7F0, 0x8327B7F0) { ctx.r3.u64 = Construct_TXT_8349DF40_G_(ctx, base); }

uint64_t Construct_TXT_8349DF44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF44_G_ = int32_t(0x8349DF44);
	constexpr int32_t str_TXT_820EEDFC_B_ = int32_t(0x820EEDFC);
	constexpr int32_t Destroy_TXT_8349DF44_G__address = int32_t(0x832A9C78);
	if (!UseLiftedCode(144, 0x8327B830)) { __imp__sub_8327B830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF44_G_, str_TXT_820EEDFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF44_G__address);
}
PROMOTED_ENTRY(144, sub_8327B830, 0x8327B830) { ctx.r3.u64 = Construct_TXT_8349DF44_G_(ctx, base); }

uint64_t Construct_TXT_8349DF48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF48_G_ = int32_t(0x8349DF48);
	constexpr int32_t str_TXT_820EEE08_B_ = int32_t(0x820EEE08);
	constexpr int32_t Destroy_TXT_8349DF48_G__address = int32_t(0x832A9C88);
	if (!UseLiftedCode(144, 0x8327B870)) { __imp__sub_8327B870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF48_G_, str_TXT_820EEE08_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF48_G__address);
}
PROMOTED_ENTRY(144, sub_8327B870, 0x8327B870) { ctx.r3.u64 = Construct_TXT_8349DF48_G_(ctx, base); }

uint64_t Construct_TXT_8349DF4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF4C_G_ = int32_t(0x8349DF4C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349DF4C_G__address = int32_t(0x832A9C98);
	if (!UseLiftedCode(144, 0x8327B8B0)) { __imp__sub_8327B8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B8B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF4C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF4C_G__address);
}
PROMOTED_ENTRY(144, sub_8327B8B0, 0x8327B8B0) { ctx.r3.u64 = Construct_TXT_8349DF4C_G_(ctx, base); }

uint64_t Construct_TXT_8349DF50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF50_G_ = int32_t(0x8349DF50);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349DF50_G__address = int32_t(0x832A9CA8);
	if (!UseLiftedCode(144, 0x8327B8F0)) { __imp__sub_8327B8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B8F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF50_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF50_G__address);
}
PROMOTED_ENTRY(144, sub_8327B8F0, 0x8327B8F0) { ctx.r3.u64 = Construct_TXT_8349DF50_G_(ctx, base); }

uint64_t Construct_TXT_8349DF54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349DF54_G_ = int32_t(0x8349DF54);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349DF54_G__address = int32_t(0x832A9CB8);
	if (!UseLiftedCode(144, 0x8327B930)) { __imp__sub_8327B930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B930);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF54_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349DF54_G__address);
}
PROMOTED_ENTRY(144, sub_8327B930, 0x8327B930) { ctx.r3.u64 = Construct_TXT_8349DF54_G_(ctx, base); }

uint64_t HashName_TXT_820CD954_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD954_B_ = int32_t(0x820CD954);
	constexpr uint32_t g_HashOf_TXT_820CD954_B_ = 0x8349DF58u;
	if (!UseLiftedCode(144, 0x8327B970)) { __imp__sub_8327B970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B970);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CD954_B_);
	STORE32(g_HashOf_TXT_820CD954_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B970, 0x8327B970) { ctx.r3.u64 = HashName_TXT_820CD954_B_(ctx, base); }

uint64_t HashName_TXT_820EF19C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF19C_B_ = int32_t(0x820EF19C);
	constexpr uint32_t g_HashOf_TXT_820EF19C_B_ = 0x8349DF5Cu;
	if (!UseLiftedCode(144, 0x8327B9A8)) { __imp__sub_8327B9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B9A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF19C_B_);
	STORE32(g_HashOf_TXT_820EF19C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B9A8, 0x8327B9A8) { ctx.r3.u64 = HashName_TXT_820EF19C_B_(ctx, base); }

uint64_t HashName_TXT_820EF1A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF1A8_B_ = int32_t(0x820EF1A8);
	constexpr uint32_t g_HashOf_TXT_820EF1A8_B_ = 0x8349DF60u;
	if (!UseLiftedCode(144, 0x8327B9E0)) { __imp__sub_8327B9E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B9E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF1A8_B_);
	STORE32(g_HashOf_TXT_820EF1A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327B9E0, 0x8327B9E0) { ctx.r3.u64 = HashName_TXT_820EF1A8_B_(ctx, base); }

uint64_t HashName_TXT_820EF1E4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF1E4_B_ = int32_t(0x820EF1E4);
	constexpr uint32_t g_HashOf_TXT_820EF1E4_B_ = 0x8349DF64u;
	if (!UseLiftedCode(144, 0x8327BA18)) { __imp__sub_8327BA18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BA18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF1E4_B_);
	STORE32(g_HashOf_TXT_820EF1E4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BA18, 0x8327BA18) { ctx.r3.u64 = HashName_TXT_820EF1E4_B_(ctx, base); }

uint64_t HashName_TXT_820EF1FC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF1FC_B_ = int32_t(0x820EF1FC);
	constexpr uint32_t g_HashOf_TXT_820EF1FC_B_ = 0x8349DF68u;
	if (!UseLiftedCode(144, 0x8327BA50)) { __imp__sub_8327BA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BA50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF1FC_B_);
	STORE32(g_HashOf_TXT_820EF1FC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BA50, 0x8327BA50) { ctx.r3.u64 = HashName_TXT_820EF1FC_B_(ctx, base); }

uint64_t HashName_TXT_82001034_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82001034_B_ = int32_t(0x82001034);
	constexpr uint32_t g_HashOf_TXT_82001034_B_ = 0x8349DF6Cu;
	if (!UseLiftedCode(144, 0x8327BA88)) { __imp__sub_8327BA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BA88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82001034_B_);
	STORE32(g_HashOf_TXT_82001034_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BA88, 0x8327BA88) { ctx.r3.u64 = HashName_TXT_82001034_B_(ctx, base); }

uint64_t HashName_TXT_820EF204_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF204_B_ = int32_t(0x820EF204);
	constexpr uint32_t g_HashOf_TXT_820EF204_B_ = 0x8349DF70u;
	if (!UseLiftedCode(144, 0x8327BAC0)) { __imp__sub_8327BAC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BAC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF204_B_);
	STORE32(g_HashOf_TXT_820EF204_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BAC0, 0x8327BAC0) { ctx.r3.u64 = HashName_TXT_820EF204_B_(ctx, base); }

uint64_t HashName_TXT_820EF214_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF214_B_ = int32_t(0x820EF214);
	constexpr uint32_t g_HashOf_TXT_820EF214_B_ = 0x8349DF74u;
	if (!UseLiftedCode(144, 0x8327BAF8)) { __imp__sub_8327BAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF214_B_);
	STORE32(g_HashOf_TXT_820EF214_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BAF8, 0x8327BAF8) { ctx.r3.u64 = HashName_TXT_820EF214_B_(ctx, base); }

uint64_t HashName_TXT_820EF220_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF220_B_ = int32_t(0x820EF220);
	constexpr uint32_t g_HashOf_TXT_820EF220_B_ = 0x8349DF78u;
	if (!UseLiftedCode(144, 0x8327BB30)) { __imp__sub_8327BB30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BB30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF220_B_);
	STORE32(g_HashOf_TXT_820EF220_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BB30, 0x8327BB30) { ctx.r3.u64 = HashName_TXT_820EF220_B_(ctx, base); }

uint64_t HashName_TXT_820CE7B4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CE7B4_B_ = int32_t(0x820CE7B4);
	constexpr uint32_t g_HashOf_TXT_820CE7B4_B_ = 0x8349DF7Cu;
	if (!UseLiftedCode(144, 0x8327BB68)) { __imp__sub_8327BB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BB68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CE7B4_B_);
	STORE32(g_HashOf_TXT_820CE7B4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BB68, 0x8327BB68) { ctx.r3.u64 = HashName_TXT_820CE7B4_B_(ctx, base); }

uint64_t HashName_TXT_820EF388_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF388_B_ = int32_t(0x820EF388);
	constexpr uint32_t g_HashOf_TXT_820EF388_B_ = 0x8349DF80u;
	if (!UseLiftedCode(144, 0x8327BBA0)) { __imp__sub_8327BBA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BBA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF388_B_);
	STORE32(g_HashOf_TXT_820EF388_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BBA0, 0x8327BBA0) { ctx.r3.u64 = HashName_TXT_820EF388_B_(ctx, base); }

uint64_t HashName_TXT_820EF390_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF390_B_ = int32_t(0x820EF390);
	constexpr uint32_t g_HashOf_TXT_820EF390_B_ = 0x8349DF84u;
	if (!UseLiftedCode(144, 0x8327BBD8)) { __imp__sub_8327BBD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BBD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF390_B_);
	STORE32(g_HashOf_TXT_820EF390_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BBD8, 0x8327BBD8) { ctx.r3.u64 = HashName_TXT_820EF390_B_(ctx, base); }

uint64_t HashName_TXT_820EF39C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF39C_B_ = int32_t(0x820EF39C);
	constexpr uint32_t g_HashOf_TXT_820EF39C_B_ = 0x8349DF88u;
	if (!UseLiftedCode(144, 0x8327BC10)) { __imp__sub_8327BC10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BC10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF39C_B_);
	STORE32(g_HashOf_TXT_820EF39C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BC10, 0x8327BC10) { ctx.r3.u64 = HashName_TXT_820EF39C_B_(ctx, base); }

uint64_t HashName_TXT_820CD954_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CD954_B_ = int32_t(0x820CD954);
	constexpr uint32_t g_HashOf_TXT_820CD954_B__2 = 0x8349DF8Cu;
	if (!UseLiftedCode(144, 0x8327BC48)) { __imp__sub_8327BC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BC48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CD954_B_);
	STORE32(g_HashOf_TXT_820CD954_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BC48, 0x8327BC48) { ctx.r3.u64 = HashName_TXT_820CD954_B__2(ctx, base); }

uint64_t HashName_TXT_820EF3AC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3AC_B_ = int32_t(0x820EF3AC);
	constexpr uint32_t g_HashOf_TXT_820EF3AC_B_ = 0x8349DF90u;
	if (!UseLiftedCode(144, 0x8327BC80)) { __imp__sub_8327BC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BC80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3AC_B_);
	STORE32(g_HashOf_TXT_820EF3AC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BC80, 0x8327BC80) { ctx.r3.u64 = HashName_TXT_820EF3AC_B_(ctx, base); }

uint64_t HashName_TXT_820EF3B8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3B8_B_ = int32_t(0x820EF3B8);
	constexpr uint32_t g_HashOf_TXT_820EF3B8_B_ = 0x8349DF94u;
	if (!UseLiftedCode(144, 0x8327BCB8)) { __imp__sub_8327BCB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BCB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3B8_B_);
	STORE32(g_HashOf_TXT_820EF3B8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BCB8, 0x8327BCB8) { ctx.r3.u64 = HashName_TXT_820EF3B8_B_(ctx, base); }

uint64_t HashName_TXT_820EF3C4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3C4_B_ = int32_t(0x820EF3C4);
	constexpr uint32_t g_HashOf_TXT_820EF3C4_B_ = 0x8349DF98u;
	if (!UseLiftedCode(144, 0x8327BCF0)) { __imp__sub_8327BCF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BCF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3C4_B_);
	STORE32(g_HashOf_TXT_820EF3C4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BCF0, 0x8327BCF0) { ctx.r3.u64 = HashName_TXT_820EF3C4_B_(ctx, base); }

uint64_t HashName_TXT_820EF19C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF19C_B_ = int32_t(0x820EF19C);
	constexpr uint32_t g_HashOf_TXT_820EF19C_B__2 = 0x8349DF9Cu;
	if (!UseLiftedCode(144, 0x8327BD28)) { __imp__sub_8327BD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BD28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF19C_B_);
	STORE32(g_HashOf_TXT_820EF19C_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BD28, 0x8327BD28) { ctx.r3.u64 = HashName_TXT_820EF19C_B__2(ctx, base); }

uint64_t HashName_TXT_820EF1A8_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF1A8_B_ = int32_t(0x820EF1A8);
	constexpr uint32_t g_HashOf_TXT_820EF1A8_B__2 = 0x8349DFA0u;
	if (!UseLiftedCode(144, 0x8327BD60)) { __imp__sub_8327BD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BD60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF1A8_B_);
	STORE32(g_HashOf_TXT_820EF1A8_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BD60, 0x8327BD60) { ctx.r3.u64 = HashName_TXT_820EF1A8_B__2(ctx, base); }

uint64_t HashName_TXT_820EF3D4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3D4_B_ = int32_t(0x820EF3D4);
	constexpr uint32_t g_HashOf_TXT_820EF3D4_B_ = 0x8349DFA4u;
	if (!UseLiftedCode(144, 0x8327BD98)) { __imp__sub_8327BD98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BD98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3D4_B_);
	STORE32(g_HashOf_TXT_820EF3D4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BD98, 0x8327BD98) { ctx.r3.u64 = HashName_TXT_820EF3D4_B_(ctx, base); }

uint64_t HashName_TXT_820EF3E0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3E0_B_ = int32_t(0x820EF3E0);
	constexpr uint32_t g_HashOf_TXT_820EF3E0_B_ = 0x8349DFA8u;
	if (!UseLiftedCode(144, 0x8327BDD0)) { __imp__sub_8327BDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BDD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3E0_B_);
	STORE32(g_HashOf_TXT_820EF3E0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BDD0, 0x8327BDD0) { ctx.r3.u64 = HashName_TXT_820EF3E0_B_(ctx, base); }

uint64_t HashName_TXT_820BC490_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BC490_B_ = int32_t(0x820BC490);
	constexpr uint32_t g_HashOf_TXT_820BC490_B_ = 0x8349DFACu;
	if (!UseLiftedCode(144, 0x8327BE08)) { __imp__sub_8327BE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BE08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BC490_B_);
	STORE32(g_HashOf_TXT_820BC490_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BE08, 0x8327BE08) { ctx.r3.u64 = HashName_TXT_820BC490_B_(ctx, base); }

uint64_t HashName_TXT_820EF3F0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3F0_B_ = int32_t(0x820EF3F0);
	constexpr uint32_t g_HashOf_TXT_820EF3F0_B_ = 0x8349DFB0u;
	if (!UseLiftedCode(144, 0x8327BE40)) { __imp__sub_8327BE40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BE40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3F0_B_);
	STORE32(g_HashOf_TXT_820EF3F0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BE40, 0x8327BE40) { ctx.r3.u64 = HashName_TXT_820EF3F0_B_(ctx, base); }

uint64_t HashName_TXT_820C4344_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C4344_B_ = int32_t(0x820C4344);
	constexpr uint32_t g_HashOf_TXT_820C4344_B_ = 0x8349DFB4u;
	if (!UseLiftedCode(144, 0x8327BE78)) { __imp__sub_8327BE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BE78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C4344_B_);
	STORE32(g_HashOf_TXT_820C4344_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BE78, 0x8327BE78) { ctx.r3.u64 = HashName_TXT_820C4344_B_(ctx, base); }

uint64_t HashName_TXT_820EF400_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF400_B_ = int32_t(0x820EF400);
	constexpr uint32_t g_HashOf_TXT_820EF400_B_ = 0x8349DFB8u;
	if (!UseLiftedCode(144, 0x8327BEB0)) { __imp__sub_8327BEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BEB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF400_B_);
	STORE32(g_HashOf_TXT_820EF400_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BEB0, 0x8327BEB0) { ctx.r3.u64 = HashName_TXT_820EF400_B_(ctx, base); }

uint64_t HashName_TXT_820EF418_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF418_B_ = int32_t(0x820EF418);
	constexpr uint32_t g_HashOf_TXT_820EF418_B_ = 0x8349DFBCu;
	if (!UseLiftedCode(144, 0x8327BEE8)) { __imp__sub_8327BEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BEE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF418_B_);
	STORE32(g_HashOf_TXT_820EF418_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BEE8, 0x8327BEE8) { ctx.r3.u64 = HashName_TXT_820EF418_B_(ctx, base); }

uint64_t HashName_TXT_820EF428_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF428_B_ = int32_t(0x820EF428);
	constexpr uint32_t g_HashOf_TXT_820EF428_B_ = 0x8349DFC0u;
	if (!UseLiftedCode(144, 0x8327BF20)) { __imp__sub_8327BF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BF20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF428_B_);
	STORE32(g_HashOf_TXT_820EF428_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BF20, 0x8327BF20) { ctx.r3.u64 = HashName_TXT_820EF428_B_(ctx, base); }

uint64_t HashName_TXT_820EF1FC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF1FC_B_ = int32_t(0x820EF1FC);
	constexpr uint32_t g_HashOf_TXT_820EF1FC_B__2 = 0x8349DFC4u;
	if (!UseLiftedCode(144, 0x8327BF58)) { __imp__sub_8327BF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BF58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF1FC_B_);
	STORE32(g_HashOf_TXT_820EF1FC_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BF58, 0x8327BF58) { ctx.r3.u64 = HashName_TXT_820EF1FC_B__2(ctx, base); }

uint64_t HashName_TXT_82001034_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82001034_B_ = int32_t(0x82001034);
	constexpr uint32_t g_HashOf_TXT_82001034_B__2 = 0x8349DFC8u;
	if (!UseLiftedCode(144, 0x8327BF90)) { __imp__sub_8327BF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BF90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82001034_B_);
	STORE32(g_HashOf_TXT_82001034_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BF90, 0x8327BF90) { ctx.r3.u64 = HashName_TXT_82001034_B__2(ctx, base); }

uint64_t HashName_TXT_820EF204_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF204_B_ = int32_t(0x820EF204);
	constexpr uint32_t g_HashOf_TXT_820EF204_B__2 = 0x8349DFCCu;
	if (!UseLiftedCode(144, 0x8327BFC8)) { __imp__sub_8327BFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327BFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF204_B_);
	STORE32(g_HashOf_TXT_820EF204_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327BFC8, 0x8327BFC8) { ctx.r3.u64 = HashName_TXT_820EF204_B__2(ctx, base); }

uint64_t HashName_TXT_820EF43C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF43C_B_ = int32_t(0x820EF43C);
	constexpr uint32_t g_HashOf_TXT_820EF43C_B_ = 0x8349DFD0u;
	if (!UseLiftedCode(144, 0x8327C000)) { __imp__sub_8327C000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C000);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF43C_B_);
	STORE32(g_HashOf_TXT_820EF43C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C000, 0x8327C000) { ctx.r3.u64 = HashName_TXT_820EF43C_B_(ctx, base); }

uint64_t HashName_TXT_820EF450_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF450_B_ = int32_t(0x820EF450);
	constexpr uint32_t g_HashOf_TXT_820EF450_B_ = 0x8349DFD4u;
	if (!UseLiftedCode(144, 0x8327C038)) { __imp__sub_8327C038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C038);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF450_B_);
	STORE32(g_HashOf_TXT_820EF450_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C038, 0x8327C038) { ctx.r3.u64 = HashName_TXT_820EF450_B_(ctx, base); }

uint64_t HashName_TXT_820EF45C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF45C_B_ = int32_t(0x820EF45C);
	constexpr uint32_t g_HashOf_TXT_820EF45C_B_ = 0x8349DFD8u;
	if (!UseLiftedCode(144, 0x8327C070)) { __imp__sub_8327C070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C070);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF45C_B_);
	STORE32(g_HashOf_TXT_820EF45C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C070, 0x8327C070) { ctx.r3.u64 = HashName_TXT_820EF45C_B_(ctx, base); }

uint64_t HashName_TXT_820EF468_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF468_B_ = int32_t(0x820EF468);
	constexpr uint32_t g_HashOf_TXT_820EF468_B_ = 0x8349DFDCu;
	if (!UseLiftedCode(144, 0x8327C0A8)) { __imp__sub_8327C0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C0A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF468_B_);
	STORE32(g_HashOf_TXT_820EF468_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C0A8, 0x8327C0A8) { ctx.r3.u64 = HashName_TXT_820EF468_B_(ctx, base); }

uint64_t HashName_TXT_820EF470_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF470_B_ = int32_t(0x820EF470);
	constexpr uint32_t g_HashOf_TXT_820EF470_B_ = 0x8349DFE0u;
	if (!UseLiftedCode(144, 0x8327C0E0)) { __imp__sub_8327C0E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C0E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF470_B_);
	STORE32(g_HashOf_TXT_820EF470_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C0E0, 0x8327C0E0) { ctx.r3.u64 = HashName_TXT_820EF470_B_(ctx, base); }

uint64_t HashName_TXT_820CF4F4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CF4F4_B_ = int32_t(0x820CF4F4);
	constexpr uint32_t g_HashOf_TXT_820CF4F4_B_ = 0x8349DFE4u;
	if (!UseLiftedCode(144, 0x8327C118)) { __imp__sub_8327C118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C118);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CF4F4_B_);
	STORE32(g_HashOf_TXT_820CF4F4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C118, 0x8327C118) { ctx.r3.u64 = HashName_TXT_820CF4F4_B_(ctx, base); }

uint64_t HashName_TXT_820EF550_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF550_B_ = int32_t(0x820EF550);
	constexpr uint32_t g_HashOf_TXT_820EF550_B_ = 0x8349DFE8u;
	if (!UseLiftedCode(144, 0x8327C150)) { __imp__sub_8327C150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C150);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF550_B_);
	STORE32(g_HashOf_TXT_820EF550_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C150, 0x8327C150) { ctx.r3.u64 = HashName_TXT_820EF550_B_(ctx, base); }

uint64_t HashName_TXT_820AF364_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820AF364_B_ = int32_t(0x820AF364);
	constexpr uint32_t g_HashOf_TXT_820AF364_B_ = 0x8349DFECu;
	if (!UseLiftedCode(144, 0x8327C188)) { __imp__sub_8327C188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C188);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820AF364_B_);
	STORE32(g_HashOf_TXT_820AF364_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C188, 0x8327C188) { ctx.r3.u64 = HashName_TXT_820AF364_B_(ctx, base); }

uint64_t HashName_TXT_82000F7C_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000F7C_B_ = int32_t(0x82000F7C);
	constexpr uint32_t g_HashOf_TXT_82000F7C_B__2 = 0x8349DFF0u;
	if (!UseLiftedCode(144, 0x8327C1C0)) { __imp__sub_8327C1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C1C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82000F7C_B_);
	STORE32(g_HashOf_TXT_82000F7C_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C1C0, 0x8327C1C0) { ctx.r3.u64 = HashName_TXT_82000F7C_B__2(ctx, base); }

uint64_t HashName_TXT_820EF3E0_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF3E0_B_ = int32_t(0x820EF3E0);
	constexpr uint32_t g_HashOf_TXT_820EF3E0_B__2 = 0x8349DFF4u;
	if (!UseLiftedCode(144, 0x8327C1F8)) { __imp__sub_8327C1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C1F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF3E0_B_);
	STORE32(g_HashOf_TXT_820EF3E0_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C1F8, 0x8327C1F8) { ctx.r3.u64 = HashName_TXT_820EF3E0_B__2(ctx, base); }

uint64_t HashName_TXT_820EF55C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF55C_B_ = int32_t(0x820EF55C);
	constexpr uint32_t g_HashOf_TXT_820EF55C_B_ = 0x8349DFF8u;
	if (!UseLiftedCode(144, 0x8327C230)) { __imp__sub_8327C230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C230);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF55C_B_);
	STORE32(g_HashOf_TXT_820EF55C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C230, 0x8327C230) { ctx.r3.u64 = HashName_TXT_820EF55C_B_(ctx, base); }

uint64_t HashName_TXT_820EF568_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF568_B_ = int32_t(0x820EF568);
	constexpr uint32_t g_HashOf_TXT_820EF568_B_ = 0x8349DFFCu;
	if (!UseLiftedCode(144, 0x8327C268)) { __imp__sub_8327C268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C268);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF568_B_);
	STORE32(g_HashOf_TXT_820EF568_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C268, 0x8327C268) { ctx.r3.u64 = HashName_TXT_820EF568_B_(ctx, base); }

uint64_t HashName_TXT_820BC490_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820BC490_B_ = int32_t(0x820BC490);
	constexpr uint32_t g_HashOf_TXT_820BC490_B__2 = 0x8349E000u;
	if (!UseLiftedCode(144, 0x8327C2A0)) { __imp__sub_8327C2A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C2A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820BC490_B_);
	STORE32(g_HashOf_TXT_820BC490_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C2A0, 0x8327C2A0) { ctx.r3.u64 = HashName_TXT_820BC490_B__2(ctx, base); }

uint64_t HashName_TXT_820CF4F4_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820CF4F4_B_ = int32_t(0x820CF4F4);
	constexpr uint32_t g_HashOf_TXT_820CF4F4_B__2 = 0x8349E004u;
	if (!UseLiftedCode(144, 0x8327C2D8)) { __imp__sub_8327C2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C2D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820CF4F4_B_);
	STORE32(g_HashOf_TXT_820CF4F4_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C2D8, 0x8327C2D8) { ctx.r3.u64 = HashName_TXT_820CF4F4_B__2(ctx, base); }

uint64_t HashName_TXT_820EF574_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF574_B_ = int32_t(0x820EF574);
	constexpr uint32_t g_HashOf_TXT_820EF574_B_ = 0x8349E008u;
	if (!UseLiftedCode(144, 0x8327C310)) { __imp__sub_8327C310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C310);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF574_B_);
	STORE32(g_HashOf_TXT_820EF574_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C310, 0x8327C310) { ctx.r3.u64 = HashName_TXT_820EF574_B_(ctx, base); }

uint64_t HashName_TXT_820EF584_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820EF584_B_ = int32_t(0x820EF584);
	constexpr uint32_t g_HashOf_TXT_820EF584_B_ = 0x8349E00Cu;
	if (!UseLiftedCode(144, 0x8327C348)) { __imp__sub_8327C348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C348);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820EF584_B_);
	STORE32(g_HashOf_TXT_820EF584_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C348, 0x8327C348) { ctx.r3.u64 = HashName_TXT_820EF584_B_(ctx, base); }

uint64_t Construct_TXT_8349E0B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0B4_G_ = int32_t(0x8349E0B4);
	constexpr int32_t str_TXT_820013B0_B_ = int32_t(0x820013B0);
	constexpr int32_t Destroy_TXT_8349E0B4_G__address = int32_t(0x832A9CE8);
	if (!UseLiftedCode(144, 0x8327C6F8)) { __imp__sub_8327C6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C6F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0B4_G_, str_TXT_820013B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0B4_G__address);
}
PROMOTED_ENTRY(144, sub_8327C6F8, 0x8327C6F8) { ctx.r3.u64 = Construct_TXT_8349E0B4_G_(ctx, base); }

uint64_t Construct_TXT_8349E0BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0BC_G_ = int32_t(0x8349E0BC);
	constexpr int32_t str_TXT_820013A0_B_ = int32_t(0x820013A0);
	constexpr int32_t Destroy_TXT_8349E0BC_G__address = int32_t(0x832A9D08);
	if (!UseLiftedCode(144, 0x8327C778)) { __imp__sub_8327C778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C778);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0BC_G_, str_TXT_820013A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0BC_G__address);
}
PROMOTED_ENTRY(144, sub_8327C778, 0x8327C778) { ctx.r3.u64 = Construct_TXT_8349E0BC_G_(ctx, base); }

uint64_t Construct_TXT_8349E0C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0C4_G_ = int32_t(0x8349E0C4);
	constexpr int32_t str_TXT_820F02C0_B_ = int32_t(0x820F02C0);
	constexpr int32_t Destroy_TXT_8349E0C4_G__address = int32_t(0x832A9D18);
	if (!UseLiftedCode(144, 0x8327C7E8)) { __imp__sub_8327C7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C7E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0C4_G_, str_TXT_820F02C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0C4_G__address);
}
PROMOTED_ENTRY(144, sub_8327C7E8, 0x8327C7E8) { ctx.r3.u64 = Construct_TXT_8349E0C4_G_(ctx, base); }

uint64_t Construct_TXT_8349E0C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0C8_G_ = int32_t(0x8349E0C8);
	constexpr int32_t str_TXT_820F02CC_B_ = int32_t(0x820F02CC);
	constexpr int32_t Destroy_TXT_8349E0C8_G__address = int32_t(0x832A9D28);
	if (!UseLiftedCode(144, 0x8327C828)) { __imp__sub_8327C828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C828);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0C8_G_, str_TXT_820F02CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0C8_G__address);
}
PROMOTED_ENTRY(144, sub_8327C828, 0x8327C828) { ctx.r3.u64 = Construct_TXT_8349E0C8_G_(ctx, base); }

uint64_t Construct_TXT_8349E0CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0CC_G_ = int32_t(0x8349E0CC);
	constexpr int32_t str_TXT_820F02E0_B_ = int32_t(0x820F02E0);
	constexpr int32_t Destroy_TXT_8349E0CC_G__address = int32_t(0x832A9D38);
	if (!UseLiftedCode(144, 0x8327C868)) { __imp__sub_8327C868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C868);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0CC_G_, str_TXT_820F02E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0CC_G__address);
}
PROMOTED_ENTRY(144, sub_8327C868, 0x8327C868) { ctx.r3.u64 = Construct_TXT_8349E0CC_G_(ctx, base); }

uint64_t Construct_TXT_8349E0D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0D0_G_ = int32_t(0x8349E0D0);
	constexpr int32_t str_TXT_820F02EC_B_ = int32_t(0x820F02EC);
	constexpr int32_t Destroy_TXT_8349E0D0_G__address = int32_t(0x832A9D48);
	if (!UseLiftedCode(144, 0x8327C8A8)) { __imp__sub_8327C8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C8A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0D0_G_, str_TXT_820F02EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0D0_G__address);
}
PROMOTED_ENTRY(144, sub_8327C8A8, 0x8327C8A8) { ctx.r3.u64 = Construct_TXT_8349E0D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E0E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E0E0_G_ = int32_t(0x8349E0E0);
	constexpr int32_t str_TXT_820F0698_B_ = int32_t(0x820F0698);
	constexpr int32_t Destroy_TXT_8349E0E0_G__address = int32_t(0x832A9D68);
	if (!UseLiftedCode(144, 0x8327C920)) { __imp__sub_8327C920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C920);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0E0_G_, str_TXT_820F0698_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E0E0_G__address);
}
PROMOTED_ENTRY(144, sub_8327C920, 0x8327C920) { ctx.r3.u64 = Construct_TXT_8349E0E0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__65 = 0x8349E0E4u;
	if (!UseLiftedCode(144, 0x8327C960)) { __imp__sub_8327C960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C960, 0x8327C960) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__65(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__67(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__67 = 0x8349E0E8u;
	if (!UseLiftedCode(144, 0x8327C998)) { __imp__sub_8327C998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__67, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C998, 0x8327C998) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__67(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__66(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__66 = 0x8349E0ECu;
	if (!UseLiftedCode(144, 0x8327C9D0)) { __imp__sub_8327C9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C9D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__66, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327C9D0, 0x8327C9D0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__66(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__65 = 0x8349E0F0u;
	if (!UseLiftedCode(144, 0x8327CA08)) { __imp__sub_8327CA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CA08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CA08, 0x8327CA08) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__65 = 0x8349E0F4u;
	if (!UseLiftedCode(144, 0x8327CA40)) { __imp__sub_8327CA40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CA40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CA40, 0x8327CA40) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__66(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__66 = 0x8349E0F8u;
	if (!UseLiftedCode(144, 0x8327CA78)) { __imp__sub_8327CA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CA78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__66, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CA78, 0x8327CA78) { ctx.r3.u64 = HashName_TXT_820A2C34_B__66(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__65 = 0x8349E0FCu;
	if (!UseLiftedCode(144, 0x8327CAB0)) { __imp__sub_8327CAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CAB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CAB0, 0x8327CAB0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__65 = 0x8349E100u;
	if (!UseLiftedCode(144, 0x8327CAE8)) { __imp__sub_8327CAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CAE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CAE8, 0x8327CAE8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__65 = 0x8349E104u;
	if (!UseLiftedCode(144, 0x8327CB20)) { __imp__sub_8327CB20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CB20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CB20, 0x8327CB20) { ctx.r3.u64 = HashName_TXT_820A2C74_B__65(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__65 = 0x8349E108u;
	if (!UseLiftedCode(144, 0x8327CB58)) { __imp__sub_8327CB58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CB58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CB58, 0x8327CB58) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__65 = 0x8349E10Cu;
	if (!UseLiftedCode(144, 0x8327CB90)) { __imp__sub_8327CB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CB90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CB90, 0x8327CB90) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__65 = 0x8349E110u;
	if (!UseLiftedCode(144, 0x8327CBC8)) { __imp__sub_8327CBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CBC8, 0x8327CBC8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__68 = 0x8349E114u;
	if (!UseLiftedCode(144, 0x8327CC00)) { __imp__sub_8327CC00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CC00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__68, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CC00, 0x8327CC00) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__68(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__65 = 0x8349E118u;
	if (!UseLiftedCode(144, 0x8327CC38)) { __imp__sub_8327CC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CC38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CC38, 0x8327CC38) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__65 = 0x8349E11Cu;
	if (!UseLiftedCode(144, 0x8327CC70)) { __imp__sub_8327CC70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CC70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CC70, 0x8327CC70) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__65(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__65 = 0x8349E120u;
	if (!UseLiftedCode(144, 0x8327CCA8)) { __imp__sub_8327CCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CCA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CCA8, 0x8327CCA8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__65(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__65 = 0x8349E124u;
	if (!UseLiftedCode(144, 0x8327CCE0)) { __imp__sub_8327CCE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CCE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CCE0, 0x8327CCE0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__66(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__66 = 0x8349E128u;
	if (!UseLiftedCode(144, 0x8327CD18)) { __imp__sub_8327CD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CD18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__66, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CD18, 0x8327CD18) { ctx.r3.u64 = HashName_TXT_820A2D24_B__66(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__65 = 0x8349E12Cu;
	if (!UseLiftedCode(144, 0x8327CD50)) { __imp__sub_8327CD50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CD50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CD50, 0x8327CD50) { ctx.r3.u64 = HashName_TXT_820A2D30_B__65(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__65 = 0x8349E130u;
	if (!UseLiftedCode(144, 0x8327CD88)) { __imp__sub_8327CD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CD88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CD88, 0x8327CD88) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__65(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__65(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__65 = 0x8349E134u;
	if (!UseLiftedCode(144, 0x8327CDC0)) { __imp__sub_8327CDC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CDC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__65, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CDC0, 0x8327CDC0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__65(ctx, base); }

uint64_t Construct_TXT_8349E138_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E138_G_ = int32_t(0x8349E138);
	constexpr int32_t str_TXT_820F0878_B_ = int32_t(0x820F0878);
	constexpr int32_t Destroy_TXT_8349E138_G__address = int32_t(0x832A9D78);
	if (!UseLiftedCode(144, 0x8327CDF8)) { __imp__sub_8327CDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CDF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E138_G_, str_TXT_820F0878_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E138_G__address);
}
PROMOTED_ENTRY(144, sub_8327CDF8, 0x8327CDF8) { ctx.r3.u64 = Construct_TXT_8349E138_G_(ctx, base); }

uint64_t HashName_TXT_82000E40_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82000E40_B_ = int32_t(0x82000E40);
	constexpr uint32_t g_HashOf_TXT_82000E40_B_ = 0x8349E15Cu;
	if (!UseLiftedCode(144, 0x8327CEA8)) { __imp__sub_8327CEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CEA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_82000E40_B_);
	STORE32(g_HashOf_TXT_82000E40_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8327CEA8, 0x8327CEA8) { ctx.r3.u64 = HashName_TXT_82000E40_B_(ctx, base); }

uint64_t Construct_TXT_8349E170_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E170_G_ = int32_t(0x8349E170);
	constexpr int32_t str_TXT_8209B420_B_ = int32_t(0x8209B420);
	constexpr int32_t Destroy_TXT_8349E170_G__address = int32_t(0x832A9D90);
	if (!UseLiftedCode(144, 0x8327CF60)) { __imp__sub_8327CF60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CF60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E170_G_, str_TXT_8209B420_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E170_G__address);
}
PROMOTED_ENTRY(144, sub_8327CF60, 0x8327CF60) { ctx.r3.u64 = Construct_TXT_8349E170_G_(ctx, base); }

uint64_t Construct_TXT_8349E174_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E174_G_ = int32_t(0x8349E174);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B3F0);
	constexpr int32_t Destroy_TXT_8349E174_G__address = int32_t(0x832A9DA0);
	if (!UseLiftedCode(144, 0x8327CFA0)) { __imp__sub_8327CFA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CFA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E174_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E174_G__address);
}
PROMOTED_ENTRY(144, sub_8327CFA0, 0x8327CFA0) { ctx.r3.u64 = Construct_TXT_8349E174_G_(ctx, base); }

uint64_t Construct_TXT_8349E178_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E178_G_ = int32_t(0x8349E178);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B3F8);
	constexpr int32_t Destroy_TXT_8349E178_G__address = int32_t(0x832A9DB0);
	if (!UseLiftedCode(144, 0x8327CFE0)) { __imp__sub_8327CFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CFE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E178_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E178_G__address);
}
PROMOTED_ENTRY(144, sub_8327CFE0, 0x8327CFE0) { ctx.r3.u64 = Construct_TXT_8349E178_G_(ctx, base); }

uint64_t Construct_TXT_8349E17C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E17C_G_ = int32_t(0x8349E17C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B40C);
	constexpr int32_t Destroy_TXT_8349E17C_G__address = int32_t(0x832A9DC0);
	if (!UseLiftedCode(144, 0x8327D020)) { __imp__sub_8327D020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D020);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E17C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E17C_G__address);
}
PROMOTED_ENTRY(144, sub_8327D020, 0x8327D020) { ctx.r3.u64 = Construct_TXT_8349E17C_G_(ctx, base); }

uint64_t CallIsZero_832A9DD0(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9DD0_address = int32_t(0x832A9DD0);
	if (!UseLiftedCode(144, 0x8327D060)) { ctx.r8.u64 = value; __imp__sub_8327D060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D060);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9DD0_address, value);
}
PROMOTED_ENTRY(144, sub_8327D060, 0x8327D060) { ctx.r3.u64 = CallIsZero_832A9DD0(ctx, base, ctx.r8.u64); }

uint64_t CallIsZero_832A9DE0(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9DE0_address = int32_t(0x832A9DE0);
	if (!UseLiftedCode(144, 0x8327D070)) { ctx.r8.u64 = value; __imp__sub_8327D070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D070);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9DE0_address, value);
}
PROMOTED_ENTRY(144, sub_8327D070, 0x8327D070) { ctx.r3.u64 = CallIsZero_832A9DE0(ctx, base, ctx.r8.u64); }

uint64_t CallIsZero_832A9DF0(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9DF0_address = int32_t(0x832A9DF0);
	if (!UseLiftedCode(144, 0x8327D080)) { ctx.r8.u64 = value; __imp__sub_8327D080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D080);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9DF0_address, value);
}
PROMOTED_ENTRY(144, sub_8327D080, 0x8327D080) { ctx.r3.u64 = CallIsZero_832A9DF0(ctx, base, ctx.r8.u64); }

uint64_t CallIsZero_832A9E00(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9E00_address = int32_t(0x832A9E00);
	if (!UseLiftedCode(144, 0x8327D168)) { ctx.r8.u64 = value; __imp__sub_8327D168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D168);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9E00_address, value);
}
PROMOTED_ENTRY(144, sub_8327D168, 0x8327D168) { ctx.r3.u64 = CallIsZero_832A9E00(ctx, base, ctx.r8.u64); }

uint64_t CallIsZero_832A9E10(CpuState& ctx, uint8_t* base, uint64_t value) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t n_sub_832A9E10_address = int32_t(0x832A9E10);
	if (!UseLiftedCode(144, 0x8327D178)) { ctx.r8.u64 = value; __imp__sub_8327D178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D178);
	ctx.r11.s64 = g_832B0000;
	return RegisterAtExit(ctx, base, n_sub_832A9E10_address, value);
}
PROMOTED_ENTRY(144, sub_8327D178, 0x8327D178) { ctx.r3.u64 = CallIsZero_832A9E10(ctx, base, ctx.r8.u64); }

uint64_t InitializeGlobalCCharStringAndRegisterExit(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_8349E1F0 = int32_t(0x8349E1F0);
	constexpr int32_t n_sub_832A9E20_address = int32_t(0x832A9E20);
	if (!UseLiftedCode(144, 0x8327D188)) { __imp__sub_8327D188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_8349E1F0, (int64_t)g_820A0000 - 28038, -1);
	return RegisterAtExit(ctx, base, n_sub_832A9E20_address);
}
PROMOTED_ENTRY(144, sub_8327D188, 0x8327D188) { ctx.r3.u64 = InitializeGlobalCCharStringAndRegisterExit(ctx, base); }

uint64_t Construct_TXT_8349E200_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E200_G_ = int32_t(0x8349E200);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B330);
	constexpr int32_t Destroy_TXT_8349E200_G__address = int32_t(0x832A9E50);
	if (!UseLiftedCode(144, 0x8327D258)) { __imp__sub_8327D258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E200_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E200_G__address);
}
PROMOTED_ENTRY(144, sub_8327D258, 0x8327D258) { ctx.r3.u64 = Construct_TXT_8349E200_G_(ctx, base); }

uint64_t Construct_TXT_8349E204_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E204_G_ = int32_t(0x8349E204);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B338);
	constexpr int32_t Destroy_TXT_8349E204_G__address = int32_t(0x832A9E60);
	if (!UseLiftedCode(144, 0x8327D298)) { __imp__sub_8327D298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E204_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E204_G__address);
}
PROMOTED_ENTRY(144, sub_8327D298, 0x8327D298) { ctx.r3.u64 = Construct_TXT_8349E204_G_(ctx, base); }

uint64_t Construct_TXT_8349E208_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E208_G_ = int32_t(0x8349E208);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B34C);
	constexpr int32_t Destroy_TXT_8349E208_G__address = int32_t(0x832A9E70);
	if (!UseLiftedCode(144, 0x8327D2D8)) { __imp__sub_8327D2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D2D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E208_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E208_G__address);
}
PROMOTED_ENTRY(144, sub_8327D2D8, 0x8327D2D8) { ctx.r3.u64 = Construct_TXT_8349E208_G_(ctx, base); }

uint64_t Construct_TXT_8349E20C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E20C_G_ = int32_t(0x8349E20C);
	constexpr int32_t str_TXT_8209B360_B_ = int32_t(0x8209B360);
	constexpr int32_t Destroy_TXT_8349E20C_G__address = int32_t(0x832A9E80);
	if (!UseLiftedCode(144, 0x8327D318)) { __imp__sub_8327D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D318);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E20C_G_, str_TXT_8209B360_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E20C_G__address);
}
PROMOTED_ENTRY(144, sub_8327D318, 0x8327D318) { ctx.r3.u64 = Construct_TXT_8349E20C_G_(ctx, base); }

uint64_t Construct_TXT_8349E210_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E210_G_ = int32_t(0x8349E210);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B384);
	constexpr int32_t Destroy_TXT_8349E210_G__address = int32_t(0x832A9E90);
	if (!UseLiftedCode(144, 0x8327D358)) { __imp__sub_8327D358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E210_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E210_G__address);
}
PROMOTED_ENTRY(144, sub_8327D358, 0x8327D358) { ctx.r3.u64 = Construct_TXT_8349E210_G_(ctx, base); }

uint64_t Construct_TXT_8349E214_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E214_G_ = int32_t(0x8349E214);
	constexpr int32_t str_TXT_8209B38C_B_ = int32_t(0x8209B38C);
	constexpr int32_t Destroy_TXT_8349E214_G__address = int32_t(0x832A9EA0);
	if (!UseLiftedCode(144, 0x8327D398)) { __imp__sub_8327D398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E214_G_, str_TXT_8209B38C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E214_G__address);
}
PROMOTED_ENTRY(144, sub_8327D398, 0x8327D398) { ctx.r3.u64 = Construct_TXT_8349E214_G_(ctx, base); }

uint64_t Construct_TXT_8349E218_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E218_G_ = int32_t(0x8349E218);
	constexpr int32_t str_TXT_8209B3B4_B_ = int32_t(0x8209B3B4);
	constexpr int32_t Destroy_TXT_8349E218_G__address = int32_t(0x832A9EB0);
	if (!UseLiftedCode(144, 0x8327D3D8)) { __imp__sub_8327D3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E218_G_, str_TXT_8209B3B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E218_G__address);
}
PROMOTED_ENTRY(144, sub_8327D3D8, 0x8327D3D8) { ctx.r3.u64 = Construct_TXT_8349E218_G_(ctx, base); }

uint64_t Construct_TXT_8349E21C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E21C_G_ = int32_t(0x8349E21C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B3C0);
	constexpr int32_t Destroy_TXT_8349E21C_G__address = int32_t(0x832A9EC0);
	if (!UseLiftedCode(144, 0x8327D418)) { __imp__sub_8327D418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E21C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E21C_G__address);
}
PROMOTED_ENTRY(144, sub_8327D418, 0x8327D418) { ctx.r3.u64 = Construct_TXT_8349E21C_G_(ctx, base); }

uint64_t Construct_TXT_8349E220_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E220_G_ = int32_t(0x8349E220);
	constexpr int32_t str_TXT_8209B3C8_B_ = int32_t(0x8209B3C8);
	constexpr int32_t Destroy_TXT_8349E220_G__address = int32_t(0x832A9ED0);
	if (!UseLiftedCode(144, 0x8327D458)) { __imp__sub_8327D458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D458);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E220_G_, str_TXT_8209B3C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E220_G__address);
}
PROMOTED_ENTRY(144, sub_8327D458, 0x8327D458) { ctx.r3.u64 = Construct_TXT_8349E220_G_(ctx, base); }

uint64_t Construct_TXT_8349E224_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E224_G_ = int32_t(0x8349E224);
	constexpr int32_t str_TXT_8209B3D0_B_ = int32_t(0x8209B3D0);
	constexpr int32_t Destroy_TXT_8349E224_G__address = int32_t(0x832A9EE0);
	if (!UseLiftedCode(144, 0x8327D498)) { __imp__sub_8327D498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D498);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E224_G_, str_TXT_8209B3D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E224_G__address);
}
PROMOTED_ENTRY(144, sub_8327D498, 0x8327D498) { ctx.r3.u64 = Construct_TXT_8349E224_G_(ctx, base); }

uint64_t Construct_TXT_8349E228_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E228_G_ = int32_t(0x8349E228);
	constexpr int32_t str_TXT_8209B3E0_B_ = int32_t(0x8209B3E0);
	constexpr int32_t Destroy_TXT_8349E228_G__address = int32_t(0x832A9EF0);
	if (!UseLiftedCode(144, 0x8327D4D8)) { __imp__sub_8327D4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E228_G_, str_TXT_8209B3E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E228_G__address);
}
PROMOTED_ENTRY(144, sub_8327D4D8, 0x8327D4D8) { ctx.r3.u64 = Construct_TXT_8349E228_G_(ctx, base); }

uint64_t Construct_TXT_8349E240_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E240_G_ = int32_t(0x8349E240);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B2E4);
	constexpr int32_t Destroy_TXT_8349E240_G__address = int32_t(0x832A9F00);
	if (!UseLiftedCode(144, 0x8327D530)) { __imp__sub_8327D530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E240_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E240_G__address);
}
PROMOTED_ENTRY(144, sub_8327D530, 0x8327D530) { ctx.r3.u64 = Construct_TXT_8349E240_G_(ctx, base); }

uint64_t Construct_TXT_8349E244_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E244_G_ = int32_t(0x8349E244);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B2EC);
	constexpr int32_t Destroy_TXT_8349E244_G__address = int32_t(0x832A9F10);
	if (!UseLiftedCode(144, 0x8327D570)) { __imp__sub_8327D570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E244_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E244_G__address);
}
PROMOTED_ENTRY(144, sub_8327D570, 0x8327D570) { ctx.r3.u64 = Construct_TXT_8349E244_G_(ctx, base); }

uint64_t Construct_TXT_8349E248_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E248_G_ = int32_t(0x8349E248);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B300);
	constexpr int32_t Destroy_TXT_8349E248_G__address = int32_t(0x832A9F20);
	if (!UseLiftedCode(144, 0x8327D5B0)) { __imp__sub_8327D5B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D5B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E248_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E248_G__address);
}
PROMOTED_ENTRY(144, sub_8327D5B0, 0x8327D5B0) { ctx.r3.u64 = Construct_TXT_8349E248_G_(ctx, base); }

uint64_t Construct_TXT_8349E24C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E24C_G_ = int32_t(0x8349E24C);
	constexpr int32_t str_TXT_8209B314_B_ = int32_t(0x8209B314);
	constexpr int32_t Destroy_TXT_8349E24C_G__address = int32_t(0x832A9F30);
	if (!UseLiftedCode(144, 0x8327D5F0)) { __imp__sub_8327D5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D5F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E24C_G_, str_TXT_8209B314_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E24C_G__address);
}
PROMOTED_ENTRY(144, sub_8327D5F0, 0x8327D5F0) { ctx.r3.u64 = Construct_TXT_8349E24C_G_(ctx, base); }

uint64_t Construct_TXT_8349E250_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E250_G_ = int32_t(0x8349E250);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B284);
	constexpr int32_t Destroy_TXT_8349E250_G__address = int32_t(0x832A9F40);
	if (!UseLiftedCode(144, 0x8327D630)) { __imp__sub_8327D630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E250_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E250_G__address);
}
PROMOTED_ENTRY(144, sub_8327D630, 0x8327D630) { ctx.r3.u64 = Construct_TXT_8349E250_G_(ctx, base); }

uint64_t Construct_TXT_8349E254_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E254_G_ = int32_t(0x8349E254);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B28C);
	constexpr int32_t Destroy_TXT_8349E254_G__address = int32_t(0x832A9F50);
	if (!UseLiftedCode(144, 0x8327D670)) { __imp__sub_8327D670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E254_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E254_G__address);
}
PROMOTED_ENTRY(144, sub_8327D670, 0x8327D670) { ctx.r3.u64 = Construct_TXT_8349E254_G_(ctx, base); }

uint64_t Construct_TXT_8349E258_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E258_G_ = int32_t(0x8349E258);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B2A0);
	constexpr int32_t Destroy_TXT_8349E258_G__address = int32_t(0x832A9F60);
	if (!UseLiftedCode(144, 0x8327D6B0)) { __imp__sub_8327D6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D6B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E258_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E258_G__address);
}
PROMOTED_ENTRY(144, sub_8327D6B0, 0x8327D6B0) { ctx.r3.u64 = Construct_TXT_8349E258_G_(ctx, base); }

uint64_t Construct_TXT_8349E25C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E25C_G_ = int32_t(0x8349E25C);
	constexpr int32_t str_TXT_8209B2B4_B_ = int32_t(0x8209B2B4);
	constexpr int32_t Destroy_TXT_8349E25C_G__address = int32_t(0x832A9F70);
	if (!UseLiftedCode(144, 0x8327D6F0)) { __imp__sub_8327D6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D6F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E25C_G_, str_TXT_8209B2B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E25C_G__address);
}
PROMOTED_ENTRY(144, sub_8327D6F0, 0x8327D6F0) { ctx.r3.u64 = Construct_TXT_8349E25C_G_(ctx, base); }

uint64_t Construct_TXT_8349E260_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E260_G_ = int32_t(0x8349E260);
	constexpr int32_t str_TXT_8209B2D8_B_ = int32_t(0x8209B2D8);
	constexpr int32_t Destroy_TXT_8349E260_G__address = int32_t(0x832A9F80);
	if (!UseLiftedCode(144, 0x8327D730)) { __imp__sub_8327D730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E260_G_, str_TXT_8209B2D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E260_G__address);
}
PROMOTED_ENTRY(144, sub_8327D730, 0x8327D730) { ctx.r3.u64 = Construct_TXT_8349E260_G_(ctx, base); }

uint64_t Construct_TXT_8349E2D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2D0_G_ = int32_t(0x8349E2D0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B234);
	constexpr int32_t Destroy_TXT_8349E2D0_G__address = int32_t(0x832AA0F0);
	if (!UseLiftedCode(144, 0x8327D7B0)) { __imp__sub_8327D7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2D0_G__address);
}
PROMOTED_ENTRY(144, sub_8327D7B0, 0x8327D7B0) { ctx.r3.u64 = Construct_TXT_8349E2D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E2D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2D4_G_ = int32_t(0x8349E2D4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B23C);
	constexpr int32_t Destroy_TXT_8349E2D4_G__address = int32_t(0x832AA100);
	if (!UseLiftedCode(144, 0x8327D7F0)) { __imp__sub_8327D7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D7F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2D4_G__address);
}
PROMOTED_ENTRY(144, sub_8327D7F0, 0x8327D7F0) { ctx.r3.u64 = Construct_TXT_8349E2D4_G_(ctx, base); }

uint64_t Construct_TXT_8349E2D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2D8_G_ = int32_t(0x8349E2D8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B250);
	constexpr int32_t Destroy_TXT_8349E2D8_G__address = int32_t(0x832AA110);
	if (!UseLiftedCode(144, 0x8327D830)) { __imp__sub_8327D830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2D8_G__address);
}
PROMOTED_ENTRY(144, sub_8327D830, 0x8327D830) { ctx.r3.u64 = Construct_TXT_8349E2D8_G_(ctx, base); }

uint64_t Construct_TXT_8349E2DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2DC_G_ = int32_t(0x8349E2DC);
	constexpr int32_t str_TXT_8209B264_B_ = int32_t(0x8209B264);
	constexpr int32_t Destroy_TXT_8349E2DC_G__address = int32_t(0x832AA120);
	if (!UseLiftedCode(144, 0x8327D870)) { __imp__sub_8327D870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2DC_G_, str_TXT_8209B264_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2DC_G__address);
}
PROMOTED_ENTRY(144, sub_8327D870, 0x8327D870) { ctx.r3.u64 = Construct_TXT_8349E2DC_G_(ctx, base); }

uint64_t Construct_TXT_8349E2E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2E0_G_ = int32_t(0x8349E2E0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B1B8);
	constexpr int32_t Destroy_TXT_8349E2E0_G__address = int32_t(0x832AA290);
	if (!UseLiftedCode(144, 0x8327D8B0)) { __imp__sub_8327D8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D8B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2E0_G__address);
}
PROMOTED_ENTRY(144, sub_8327D8B0, 0x8327D8B0) { ctx.r3.u64 = Construct_TXT_8349E2E0_G_(ctx, base); }

uint64_t Construct_TXT_8349E2E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2E4_G_ = int32_t(0x8349E2E4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B1C0);
	constexpr int32_t Destroy_TXT_8349E2E4_G__address = int32_t(0x832AA2A0);
	if (!UseLiftedCode(144, 0x8327D8F0)) { __imp__sub_8327D8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D8F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2E4_G__address);
}
PROMOTED_ENTRY(144, sub_8327D8F0, 0x8327D8F0) { ctx.r3.u64 = Construct_TXT_8349E2E4_G_(ctx, base); }

uint64_t Construct_TXT_8349E2E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2E8_G_ = int32_t(0x8349E2E8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B1D4);
	constexpr int32_t Destroy_TXT_8349E2E8_G__address = int32_t(0x832AA2B0);
	if (!UseLiftedCode(144, 0x8327D930)) { __imp__sub_8327D930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D930);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2E8_G__address);
}
PROMOTED_ENTRY(144, sub_8327D930, 0x8327D930) { ctx.r3.u64 = Construct_TXT_8349E2E8_G_(ctx, base); }

uint64_t Construct_TXT_8349E2EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2EC_G_ = int32_t(0x8349E2EC);
	constexpr int32_t str_TXT_8209B1E8_B_ = int32_t(0x8209B1E8);
	constexpr int32_t Destroy_TXT_8349E2EC_G__address = int32_t(0x832AA2C0);
	if (!UseLiftedCode(144, 0x8327D970)) { __imp__sub_8327D970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D970);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2EC_G_, str_TXT_8209B1E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2EC_G__address);
}
PROMOTED_ENTRY(144, sub_8327D970, 0x8327D970) { ctx.r3.u64 = Construct_TXT_8349E2EC_G_(ctx, base); }

uint64_t Construct_TXT_8349E2F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2F0_G_ = int32_t(0x8349E2F0);
	constexpr int32_t str_TXT_8209B214_B_ = int32_t(0x8209B214);
	constexpr int32_t Destroy_TXT_8349E2F0_G__address = int32_t(0x832AA2D0);
	if (!UseLiftedCode(144, 0x8327D9B0)) { __imp__sub_8327D9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D9B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2F0_G_, str_TXT_8209B214_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2F0_G__address);
}
PROMOTED_ENTRY(144, sub_8327D9B0, 0x8327D9B0) { ctx.r3.u64 = Construct_TXT_8349E2F0_G_(ctx, base); }

uint64_t Construct_TXT_8349E2F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E2F4_G_ = int32_t(0x8349E2F4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B22C);
	constexpr int32_t Destroy_TXT_8349E2F4_G__address = int32_t(0x832AA2E0);
	if (!UseLiftedCode(144, 0x8327D9F0)) { __imp__sub_8327D9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2F4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E2F4_G__address);
}
PROMOTED_ENTRY(144, sub_8327D9F0, 0x8327D9F0) { ctx.r3.u64 = Construct_TXT_8349E2F4_G_(ctx, base); }

uint64_t Construct_TXT_8349E308_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E308_G_ = int32_t(0x8349E308);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B110);
	constexpr int32_t Destroy_TXT_8349E308_G__address = int32_t(0x832AA338);
	if (!UseLiftedCode(144, 0x8327DA68)) { __imp__sub_8327DA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DA68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E308_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E308_G__address);
}
PROMOTED_ENTRY(144, sub_8327DA68, 0x8327DA68) { ctx.r3.u64 = Construct_TXT_8349E308_G_(ctx, base); }

uint64_t Construct_TXT_8349E30C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E30C_G_ = int32_t(0x8349E30C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B118);
	constexpr int32_t Destroy_TXT_8349E30C_G__address = int32_t(0x832AA348);
	if (!UseLiftedCode(144, 0x8327DAA8)) { __imp__sub_8327DAA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DAA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E30C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E30C_G__address);
}
PROMOTED_ENTRY(144, sub_8327DAA8, 0x8327DAA8) { ctx.r3.u64 = Construct_TXT_8349E30C_G_(ctx, base); }

uint64_t Construct_TXT_8349E310_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E310_G_ = int32_t(0x8349E310);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B12C);
	constexpr int32_t Destroy_TXT_8349E310_G__address = int32_t(0x832AA358);
	if (!UseLiftedCode(144, 0x8327DAE8)) { __imp__sub_8327DAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DAE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E310_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E310_G__address);
}
PROMOTED_ENTRY(144, sub_8327DAE8, 0x8327DAE8) { ctx.r3.u64 = Construct_TXT_8349E310_G_(ctx, base); }

uint64_t Construct_TXT_8349E314_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E314_G_ = int32_t(0x8349E314);
	constexpr int32_t str_TXT_8209B140_B_ = int32_t(0x8209B140);
	constexpr int32_t Destroy_TXT_8349E314_G__address = int32_t(0x832AA368);
	if (!UseLiftedCode(144, 0x8327DB28)) { __imp__sub_8327DB28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DB28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E314_G_, str_TXT_8209B140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E314_G__address);
}
PROMOTED_ENTRY(144, sub_8327DB28, 0x8327DB28) { ctx.r3.u64 = Construct_TXT_8349E314_G_(ctx, base); }

uint64_t Construct_TXT_8349E318_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E318_G_ = int32_t(0x8349E318);
	constexpr int32_t str_TXT_8209B15C_B_ = int32_t(0x8209B15C);
	constexpr int32_t Destroy_TXT_8349E318_G__address = int32_t(0x832AA378);
	if (!UseLiftedCode(144, 0x8327DB68)) { __imp__sub_8327DB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DB68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E318_G_, str_TXT_8209B15C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E318_G__address);
}
PROMOTED_ENTRY(144, sub_8327DB68, 0x8327DB68) { ctx.r3.u64 = Construct_TXT_8349E318_G_(ctx, base); }

uint64_t Construct_TXT_8349E31C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E31C_G_ = int32_t(0x8349E31C);
	constexpr int32_t str_TXT_8209B16C_B_ = int32_t(0x8209B16C);
	constexpr int32_t Destroy_TXT_8349E31C_G__address = int32_t(0x832AA388);
	if (!UseLiftedCode(144, 0x8327DBA8)) { __imp__sub_8327DBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DBA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E31C_G_, str_TXT_8209B16C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E31C_G__address);
}
PROMOTED_ENTRY(144, sub_8327DBA8, 0x8327DBA8) { ctx.r3.u64 = Construct_TXT_8349E31C_G_(ctx, base); }

uint64_t Construct_TXT_8349E320_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E320_G_ = int32_t(0x8349E320);
	constexpr int32_t str_TXT_8209B180_B_ = int32_t(0x8209B180);
	constexpr int32_t Destroy_TXT_8349E320_G__address = int32_t(0x832AA398);
	if (!UseLiftedCode(144, 0x8327DBE8)) { __imp__sub_8327DBE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DBE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E320_G_, str_TXT_8209B180_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E320_G__address);
}
PROMOTED_ENTRY(144, sub_8327DBE8, 0x8327DBE8) { ctx.r3.u64 = Construct_TXT_8349E320_G_(ctx, base); }

uint64_t Construct_TXT_8349E324_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E324_G_ = int32_t(0x8349E324);
	constexpr int32_t str_TXT_8209B188_B_ = int32_t(0x8209B188);
	constexpr int32_t Destroy_TXT_8349E324_G__address = int32_t(0x832AA3A8);
	if (!UseLiftedCode(144, 0x8327DC28)) { __imp__sub_8327DC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DC28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E324_G_, str_TXT_8209B188_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E324_G__address);
}
PROMOTED_ENTRY(144, sub_8327DC28, 0x8327DC28) { ctx.r3.u64 = Construct_TXT_8349E324_G_(ctx, base); }

uint64_t Construct_TXT_8349E328_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E328_G_ = int32_t(0x8349E328);
	constexpr int32_t str_TXT_8209B194_B_ = int32_t(0x8209B194);
	constexpr int32_t Destroy_TXT_8349E328_G__address = int32_t(0x832AA3B8);
	if (!UseLiftedCode(144, 0x8327DC68)) { __imp__sub_8327DC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DC68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E328_G_, str_TXT_8209B194_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E328_G__address);
}
PROMOTED_ENTRY(144, sub_8327DC68, 0x8327DC68) { ctx.r3.u64 = Construct_TXT_8349E328_G_(ctx, base); }

uint64_t Construct_TXT_8349E32C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E32C_G_ = int32_t(0x8349E32C);
	constexpr int32_t str_TXT_8209B1A8_B_ = int32_t(0x8209B1A8);
	constexpr int32_t Destroy_TXT_8349E32C_G__address = int32_t(0x832AA3C8);
	if (!UseLiftedCode(144, 0x8327DCA8)) { __imp__sub_8327DCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DCA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E32C_G_, str_TXT_8209B1A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E32C_G__address);
}
PROMOTED_ENTRY(144, sub_8327DCA8, 0x8327DCA8) { ctx.r3.u64 = Construct_TXT_8349E32C_G_(ctx, base); }

uint64_t Construct_TXT_8349E330_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E330_G_ = int32_t(0x8349E330);
	constexpr int32_t str_TXT_8209B0D4_B_ = int32_t(0x8209B0D4);
	constexpr int32_t Destroy_TXT_8349E330_G__address = int32_t(0x832AA3D8);
	if (!UseLiftedCode(144, 0x8327DCE8)) { __imp__sub_8327DCE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DCE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E330_G_, str_TXT_8209B0D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E330_G__address);
}
PROMOTED_ENTRY(144, sub_8327DCE8, 0x8327DCE8) { ctx.r3.u64 = Construct_TXT_8349E330_G_(ctx, base); }

uint64_t Construct_TXT_8349E334_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E334_G_ = int32_t(0x8349E334);
	constexpr int32_t str_TXT_8209B0E8_B_ = int32_t(0x8209B0E8);
	constexpr int32_t Destroy_TXT_8349E334_G__address = int32_t(0x832AA3E8);
	if (!UseLiftedCode(144, 0x8327DD28)) { __imp__sub_8327DD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DD28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E334_G_, str_TXT_8209B0E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E334_G__address);
}
PROMOTED_ENTRY(144, sub_8327DD28, 0x8327DD28) { ctx.r3.u64 = Construct_TXT_8349E334_G_(ctx, base); }

uint64_t Construct_TXT_8349E338_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E338_G_ = int32_t(0x8349E338);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B0F8);
	constexpr int32_t Destroy_TXT_8349E338_G__address = int32_t(0x832AA3F8);
	if (!UseLiftedCode(144, 0x8327DD68)) { __imp__sub_8327DD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DD68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E338_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E338_G__address);
}
PROMOTED_ENTRY(144, sub_8327DD68, 0x8327DD68) { ctx.r3.u64 = Construct_TXT_8349E338_G_(ctx, base); }

uint64_t Construct_TXT_8349E34C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E34C_G_ = int32_t(0x8349E34C);
	constexpr int32_t str_TXT_8209B098_B_ = int32_t(0x8209B098);
	constexpr int32_t Destroy_TXT_8349E34C_G__address = int32_t(0x832AA450);
	if (!UseLiftedCode(144, 0x8327DDE0)) { __imp__sub_8327DDE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DDE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E34C_G_, str_TXT_8209B098_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E34C_G__address);
}
PROMOTED_ENTRY(144, sub_8327DDE0, 0x8327DDE0) { ctx.r3.u64 = Construct_TXT_8349E34C_G_(ctx, base); }

uint64_t Construct_TXT_8349E350_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E350_G_ = int32_t(0x8349E350);
	constexpr int32_t str_TXT_8209B0B4_B_ = int32_t(0x8209B0B4);
	constexpr int32_t Destroy_TXT_8349E350_G__address = int32_t(0x832AA460);
	if (!UseLiftedCode(144, 0x8327DE20)) { __imp__sub_8327DE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DE20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E350_G_, str_TXT_8209B0B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E350_G__address);
}
PROMOTED_ENTRY(144, sub_8327DE20, 0x8327DE20) { ctx.r3.u64 = Construct_TXT_8349E350_G_(ctx, base); }

uint64_t Construct_TXT_8349E354_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E354_G_ = int32_t(0x8349E354);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B0CC);
	constexpr int32_t Destroy_TXT_8349E354_G__address = int32_t(0x832AA470);
	if (!UseLiftedCode(144, 0x8327DE60)) { __imp__sub_8327DE60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DE60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E354_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E354_G__address);
}
PROMOTED_ENTRY(144, sub_8327DE60, 0x8327DE60) { ctx.r3.u64 = Construct_TXT_8349E354_G_(ctx, base); }

uint64_t Construct_TXT_8349E368_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E368_G_ = int32_t(0x8349E368);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B00C);
	constexpr int32_t Destroy_TXT_8349E368_G__address = int32_t(0x832AA4C8);
	if (!UseLiftedCode(144, 0x8327DED8)) { __imp__sub_8327DED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DED8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E368_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E368_G__address);
}
PROMOTED_ENTRY(144, sub_8327DED8, 0x8327DED8) { ctx.r3.u64 = Construct_TXT_8349E368_G_(ctx, base); }

uint64_t Construct_TXT_8349E36C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E36C_G_ = int32_t(0x8349E36C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209B014);
	constexpr int32_t Destroy_TXT_8349E36C_G__address = int32_t(0x832AA4D8);
	if (!UseLiftedCode(144, 0x8327DF18)) { __imp__sub_8327DF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E36C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E36C_G__address);
}
PROMOTED_ENTRY(144, sub_8327DF18, 0x8327DF18) { ctx.r3.u64 = Construct_TXT_8349E36C_G_(ctx, base); }

uint64_t Construct_TXT_8349E370_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E370_G_ = int32_t(0x8349E370);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209B028);
	constexpr int32_t Destroy_TXT_8349E370_G__address = int32_t(0x832AA4E8);
	if (!UseLiftedCode(144, 0x8327DF58)) { __imp__sub_8327DF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E370_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E370_G__address);
}
PROMOTED_ENTRY(144, sub_8327DF58, 0x8327DF58) { ctx.r3.u64 = Construct_TXT_8349E370_G_(ctx, base); }

uint64_t Construct_TXT_8349E374_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E374_G_ = int32_t(0x8349E374);
	constexpr int32_t str_TXT_8209B03C_B_ = int32_t(0x8209B03C);
	constexpr int32_t Destroy_TXT_8349E374_G__address = int32_t(0x832AA4F8);
	if (!UseLiftedCode(144, 0x8327DF98)) { __imp__sub_8327DF98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E374_G_, str_TXT_8209B03C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E374_G__address);
}
PROMOTED_ENTRY(144, sub_8327DF98, 0x8327DF98) { ctx.r3.u64 = Construct_TXT_8349E374_G_(ctx, base); }

uint64_t Construct_TXT_8349E37C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E37C_G_ = int32_t(0x8349E37C);
	constexpr int32_t str_TXT_8209B054_B_ = int32_t(0x8209B054);
	constexpr int32_t Destroy_TXT_8349E37C_G__address = int32_t(0x832AA510);
	if (!UseLiftedCode(144, 0x8327E058)) { __imp__sub_8327E058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E058);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E37C_G_, str_TXT_8209B054_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E37C_G__address);
}
PROMOTED_ENTRY(144, sub_8327E058, 0x8327E058) { ctx.r3.u64 = Construct_TXT_8349E37C_G_(ctx, base); }

uint64_t Construct_TXT_8349E380_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E380_G_ = int32_t(0x8349E380);
	constexpr int32_t str_TXT_8209B214_B_ = int32_t(0x8209B078);
	constexpr int32_t Destroy_TXT_8349E380_G__address = int32_t(0x832AA520);
	if (!UseLiftedCode(144, 0x8327E098)) { __imp__sub_8327E098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E098);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E380_G_, str_TXT_8209B214_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E380_G__address);
}
PROMOTED_ENTRY(144, sub_8327E098, 0x8327E098) { ctx.r3.u64 = Construct_TXT_8349E380_G_(ctx, base); }

uint64_t Construct_TXT_8349E384_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E384_G_ = int32_t(0x8349E384);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209B090);
	constexpr int32_t Destroy_TXT_8349E384_G__address = int32_t(0x832AA530);
	if (!UseLiftedCode(144, 0x8327E0D8)) { __imp__sub_8327E0D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E0D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E384_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E384_G__address);
}
PROMOTED_ENTRY(144, sub_8327E0D8, 0x8327E0D8) { ctx.r3.u64 = Construct_TXT_8349E384_G_(ctx, base); }

uint64_t Construct_TXT_8349E398_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E398_G_ = int32_t(0x8349E398);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AEA8);
	constexpr int32_t Destroy_TXT_8349E398_G__address = int32_t(0x832AA588);
	if (!UseLiftedCode(144, 0x8327E150)) { __imp__sub_8327E150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E150);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E398_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E398_G__address);
}
PROMOTED_ENTRY(144, sub_8327E150, 0x8327E150) { ctx.r3.u64 = Construct_TXT_8349E398_G_(ctx, base); }

uint64_t Construct_TXT_8349E39C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E39C_G_ = int32_t(0x8349E39C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AEB0);
	constexpr int32_t Destroy_TXT_8349E39C_G__address = int32_t(0x832AA598);
	if (!UseLiftedCode(144, 0x8327E190)) { __imp__sub_8327E190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E190);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E39C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E39C_G__address);
}
PROMOTED_ENTRY(144, sub_8327E190, 0x8327E190) { ctx.r3.u64 = Construct_TXT_8349E39C_G_(ctx, base); }

uint64_t Construct_TXT_8349E3A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3A0_G_ = int32_t(0x8349E3A0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AEC4);
	constexpr int32_t Destroy_TXT_8349E3A0_G__address = int32_t(0x832AA5A8);
	if (!UseLiftedCode(144, 0x8327E1D0)) { __imp__sub_8327E1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E1D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3A0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E1D0, 0x8327E1D0) { ctx.r3.u64 = Construct_TXT_8349E3A0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3A4_G_ = int32_t(0x8349E3A4);
	constexpr int32_t str_TXT_8209B360_B_ = int32_t(0x8209AED8);
	constexpr int32_t Destroy_TXT_8349E3A4_G__address = int32_t(0x832AA5B8);
	if (!UseLiftedCode(144, 0x8327E210)) { __imp__sub_8327E210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E210);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A4_G_, str_TXT_8209B360_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3A4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E210, 0x8327E210) { ctx.r3.u64 = Construct_TXT_8349E3A4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3A8_G_ = int32_t(0x8349E3A8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AEFC);
	constexpr int32_t Destroy_TXT_8349E3A8_G__address = int32_t(0x832AA5C8);
	if (!UseLiftedCode(144, 0x8327E250)) { __imp__sub_8327E250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E250);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3A8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E250, 0x8327E250) { ctx.r3.u64 = Construct_TXT_8349E3A8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3AC_G_ = int32_t(0x8349E3AC);
	constexpr int32_t str_TXT_8209AF04_B_ = int32_t(0x8209AF04);
	constexpr int32_t Destroy_TXT_8349E3AC_G__address = int32_t(0x832AA5D8);
	if (!UseLiftedCode(144, 0x8327E290)) { __imp__sub_8327E290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E290);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3AC_G_, str_TXT_8209AF04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3AC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E290, 0x8327E290) { ctx.r3.u64 = Construct_TXT_8349E3AC_G_(ctx, base); }

uint64_t Construct_TXT_8349E3B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3B0_G_ = int32_t(0x8349E3B0);
	constexpr int32_t str_TXT_8209AF28_B_ = int32_t(0x8209AF28);
	constexpr int32_t Destroy_TXT_8349E3B0_G__address = int32_t(0x832AA5E8);
	if (!UseLiftedCode(144, 0x8327E2D0)) { __imp__sub_8327E2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E2D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B0_G_, str_TXT_8209AF28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3B0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E2D0, 0x8327E2D0) { ctx.r3.u64 = Construct_TXT_8349E3B0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3B4_G_ = int32_t(0x8349E3B4);
	constexpr int32_t str_TXT_8209AF4C_B_ = int32_t(0x8209AF4C);
	constexpr int32_t Destroy_TXT_8349E3B4_G__address = int32_t(0x832AA5F8);
	if (!UseLiftedCode(144, 0x8327E310)) { __imp__sub_8327E310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E310);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B4_G_, str_TXT_8209AF4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3B4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E310, 0x8327E310) { ctx.r3.u64 = Construct_TXT_8349E3B4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3B8_G_ = int32_t(0x8349E3B8);
	constexpr int32_t str_TXT_8209AF54_B_ = int32_t(0x8209AF54);
	constexpr int32_t Destroy_TXT_8349E3B8_G__address = int32_t(0x832AA608);
	if (!UseLiftedCode(144, 0x8327E350)) { __imp__sub_8327E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E350);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B8_G_, str_TXT_8209AF54_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3B8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E350, 0x8327E350) { ctx.r3.u64 = Construct_TXT_8349E3B8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3BC_G_ = int32_t(0x8349E3BC);
	constexpr int32_t str_TXT_8209B15C_B_ = int32_t(0x8209AF74);
	constexpr int32_t Destroy_TXT_8349E3BC_G__address = int32_t(0x832AA618);
	if (!UseLiftedCode(144, 0x8327E390)) { __imp__sub_8327E390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E390);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3BC_G_, str_TXT_8209B15C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3BC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E390, 0x8327E390) { ctx.r3.u64 = Construct_TXT_8349E3BC_G_(ctx, base); }

uint64_t Construct_TXT_8349E3C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3C0_G_ = int32_t(0x8349E3C0);
	constexpr int32_t str_TXT_8209AF84_B_ = int32_t(0x8209AF84);
	constexpr int32_t Destroy_TXT_8349E3C0_G__address = int32_t(0x832AA628);
	if (!UseLiftedCode(144, 0x8327E3D0)) { __imp__sub_8327E3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E3D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C0_G_, str_TXT_8209AF84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3C0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E3D0, 0x8327E3D0) { ctx.r3.u64 = Construct_TXT_8349E3C0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3C4_G_ = int32_t(0x8349E3C4);
	constexpr int32_t str_TXT_8209AF90_B_ = int32_t(0x8209AF90);
	constexpr int32_t Destroy_TXT_8349E3C4_G__address = int32_t(0x832AA638);
	if (!UseLiftedCode(144, 0x8327E410)) { __imp__sub_8327E410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C4_G_, str_TXT_8209AF90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3C4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E410, 0x8327E410) { ctx.r3.u64 = Construct_TXT_8349E3C4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3C8_G_ = int32_t(0x8349E3C8);
	constexpr int32_t str_TXT_8209AF9C_B_ = int32_t(0x8209AF9C);
	constexpr int32_t Destroy_TXT_8349E3C8_G__address = int32_t(0x832AA648);
	if (!UseLiftedCode(144, 0x8327E450)) { __imp__sub_8327E450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C8_G_, str_TXT_8209AF9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3C8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E450, 0x8327E450) { ctx.r3.u64 = Construct_TXT_8349E3C8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3CC_G_ = int32_t(0x8349E3CC);
	constexpr int32_t str_TXT_8209AFA4_B_ = int32_t(0x8209AFA4);
	constexpr int32_t Destroy_TXT_8349E3CC_G__address = int32_t(0x832AA658);
	if (!UseLiftedCode(144, 0x8327E490)) { __imp__sub_8327E490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3CC_G_, str_TXT_8209AFA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3CC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E490, 0x8327E490) { ctx.r3.u64 = Construct_TXT_8349E3CC_G_(ctx, base); }

uint64_t Construct_TXT_8349E3D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3D0_G_ = int32_t(0x8349E3D0);
	constexpr int32_t str_TXT_8209AFB4_B_ = int32_t(0x8209AFB4);
	constexpr int32_t Destroy_TXT_8349E3D0_G__address = int32_t(0x832AA668);
	if (!UseLiftedCode(144, 0x8327E4D0)) { __imp__sub_8327E4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E4D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D0_G_, str_TXT_8209AFB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3D0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E4D0, 0x8327E4D0) { ctx.r3.u64 = Construct_TXT_8349E3D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3D4_G_ = int32_t(0x8349E3D4);
	constexpr int32_t str_TXT_8209AFC0_B_ = int32_t(0x8209AFC0);
	constexpr int32_t Destroy_TXT_8349E3D4_G__address = int32_t(0x832AA678);
	if (!UseLiftedCode(144, 0x8327E510)) { __imp__sub_8327E510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E510);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D4_G_, str_TXT_8209AFC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3D4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E510, 0x8327E510) { ctx.r3.u64 = Construct_TXT_8349E3D4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3D8_G_ = int32_t(0x8349E3D8);
	constexpr int32_t str_TXT_8209AFC8_B_ = int32_t(0x8209AFC8);
	constexpr int32_t Destroy_TXT_8349E3D8_G__address = int32_t(0x832AA688);
	if (!UseLiftedCode(144, 0x8327E550)) { __imp__sub_8327E550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E550);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D8_G_, str_TXT_8209AFC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3D8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E550, 0x8327E550) { ctx.r3.u64 = Construct_TXT_8349E3D8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3DC_G_ = int32_t(0x8349E3DC);
	constexpr int32_t str_TXT_8209AFD4_B_ = int32_t(0x8209AFD4);
	constexpr int32_t Destroy_TXT_8349E3DC_G__address = int32_t(0x832AA698);
	if (!UseLiftedCode(144, 0x8327E590)) { __imp__sub_8327E590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E590);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3DC_G_, str_TXT_8209AFD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3DC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E590, 0x8327E590) { ctx.r3.u64 = Construct_TXT_8349E3DC_G_(ctx, base); }

uint64_t Construct_TXT_8349E3E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3E0_G_ = int32_t(0x8349E3E0);
	constexpr int32_t str_TXT_8209AFE0_B_ = int32_t(0x8209AFE0);
	constexpr int32_t Destroy_TXT_8349E3E0_G__address = int32_t(0x832AA6A8);
	if (!UseLiftedCode(144, 0x8327E5D0)) { __imp__sub_8327E5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E5D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E0_G_, str_TXT_8209AFE0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3E0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E5D0, 0x8327E5D0) { ctx.r3.u64 = Construct_TXT_8349E3E0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3E4_G_ = int32_t(0x8349E3E4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AE5C);
	constexpr int32_t Destroy_TXT_8349E3E4_G__address = int32_t(0x832AA6B8);
	if (!UseLiftedCode(144, 0x8327E610)) { __imp__sub_8327E610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E610);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3E4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E610, 0x8327E610) { ctx.r3.u64 = Construct_TXT_8349E3E4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3E8_G_ = int32_t(0x8349E3E8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AE64);
	constexpr int32_t Destroy_TXT_8349E3E8_G__address = int32_t(0x832AA6C8);
	if (!UseLiftedCode(144, 0x8327E650)) { __imp__sub_8327E650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E650);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3E8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E650, 0x8327E650) { ctx.r3.u64 = Construct_TXT_8349E3E8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3EC_G_ = int32_t(0x8349E3EC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AE78);
	constexpr int32_t Destroy_TXT_8349E3EC_G__address = int32_t(0x832AA6D8);
	if (!UseLiftedCode(144, 0x8327E690)) { __imp__sub_8327E690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E690);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3EC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3EC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E690, 0x8327E690) { ctx.r3.u64 = Construct_TXT_8349E3EC_G_(ctx, base); }

uint64_t Construct_TXT_8349E3F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3F0_G_ = int32_t(0x8349E3F0);
	constexpr int32_t str_TXT_8209AE8C_B_ = int32_t(0x8209AE8C);
	constexpr int32_t Destroy_TXT_8349E3F0_G__address = int32_t(0x832AA6E8);
	if (!UseLiftedCode(144, 0x8327E6D0)) { __imp__sub_8327E6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E6D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F0_G_, str_TXT_8209AE8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3F0_G__address);
}
PROMOTED_ENTRY(144, sub_8327E6D0, 0x8327E6D0) { ctx.r3.u64 = Construct_TXT_8349E3F0_G_(ctx, base); }

uint64_t Construct_TXT_8349E3F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3F4_G_ = int32_t(0x8349E3F4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AE14);
	constexpr int32_t Destroy_TXT_8349E3F4_G__address = int32_t(0x832AA6F8);
	if (!UseLiftedCode(144, 0x8327E710)) { __imp__sub_8327E710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E710);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3F4_G__address);
}
PROMOTED_ENTRY(144, sub_8327E710, 0x8327E710) { ctx.r3.u64 = Construct_TXT_8349E3F4_G_(ctx, base); }

uint64_t Construct_TXT_8349E3F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3F8_G_ = int32_t(0x8349E3F8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AE1C);
	constexpr int32_t Destroy_TXT_8349E3F8_G__address = int32_t(0x832AA708);
	if (!UseLiftedCode(144, 0x8327E750)) { __imp__sub_8327E750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E750);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3F8_G__address);
}
PROMOTED_ENTRY(144, sub_8327E750, 0x8327E750) { ctx.r3.u64 = Construct_TXT_8349E3F8_G_(ctx, base); }

uint64_t Construct_TXT_8349E3FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E3FC_G_ = int32_t(0x8349E3FC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AE30);
	constexpr int32_t Destroy_TXT_8349E3FC_G__address = int32_t(0x832AA718);
	if (!UseLiftedCode(144, 0x8327E790)) { __imp__sub_8327E790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3FC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E3FC_G__address);
}
PROMOTED_ENTRY(144, sub_8327E790, 0x8327E790) { ctx.r3.u64 = Construct_TXT_8349E3FC_G_(ctx, base); }

uint64_t Construct_TXT_8349E400_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E400_G_ = int32_t(0x8349E400);
	constexpr int32_t str_TXT_8209AE44_B_ = int32_t(0x8209AE44);
	constexpr int32_t Destroy_TXT_8349E400_G__address = int32_t(0x832AA728);
	if (!UseLiftedCode(144, 0x8327E7D0)) { __imp__sub_8327E7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E7D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E400_G_, str_TXT_8209AE44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E400_G__address);
}
PROMOTED_ENTRY(144, sub_8327E7D0, 0x8327E7D0) { ctx.r3.u64 = Construct_TXT_8349E400_G_(ctx, base); }

uint64_t Construct_TXT_8349E404_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E404_G_ = int32_t(0x8349E404);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209ADC0);
	constexpr int32_t Destroy_TXT_8349E404_G__address = int32_t(0x832AA738);
	if (!UseLiftedCode(144, 0x8327E810)) { __imp__sub_8327E810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E810);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E404_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E404_G__address);
}
PROMOTED_ENTRY(144, sub_8327E810, 0x8327E810) { ctx.r3.u64 = Construct_TXT_8349E404_G_(ctx, base); }

uint64_t Construct_TXT_8349E408_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E408_G_ = int32_t(0x8349E408);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209ADC8);
	constexpr int32_t Destroy_TXT_8349E408_G__address = int32_t(0x832AA748);
	if (!UseLiftedCode(144, 0x8327E850)) { __imp__sub_8327E850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E850);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E408_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E408_G__address);
}
PROMOTED_ENTRY(144, sub_8327E850, 0x8327E850) { ctx.r3.u64 = Construct_TXT_8349E408_G_(ctx, base); }

uint64_t Construct_TXT_8349E40C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E40C_G_ = int32_t(0x8349E40C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209ADDC);
	constexpr int32_t Destroy_TXT_8349E40C_G__address = int32_t(0x832AA758);
	if (!UseLiftedCode(144, 0x8327E890)) { __imp__sub_8327E890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E890);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E40C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E40C_G__address);
}
PROMOTED_ENTRY(144, sub_8327E890, 0x8327E890) { ctx.r3.u64 = Construct_TXT_8349E40C_G_(ctx, base); }

uint64_t Construct_TXT_8349E410_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E410_G_ = int32_t(0x8349E410);
	constexpr int32_t str_TXT_8209ADF0_B_ = int32_t(0x8209ADF0);
	constexpr int32_t Destroy_TXT_8349E410_G__address = int32_t(0x832AA768);
	if (!UseLiftedCode(144, 0x8327E8D0)) { __imp__sub_8327E8D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E8D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E410_G_, str_TXT_8209ADF0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E410_G__address);
}
PROMOTED_ENTRY(144, sub_8327E8D0, 0x8327E8D0) { ctx.r3.u64 = Construct_TXT_8349E410_G_(ctx, base); }

uint64_t Construct_TXT_8349E414_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E414_G_ = int32_t(0x8349E414);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AD6C);
	constexpr int32_t Destroy_TXT_8349E414_G__address = int32_t(0x832AA778);
	if (!UseLiftedCode(144, 0x8327E910)) { __imp__sub_8327E910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E414_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E414_G__address);
}
PROMOTED_ENTRY(144, sub_8327E910, 0x8327E910) { ctx.r3.u64 = Construct_TXT_8349E414_G_(ctx, base); }

uint64_t Construct_TXT_8349E418_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E418_G_ = int32_t(0x8349E418);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AD74);
	constexpr int32_t Destroy_TXT_8349E418_G__address = int32_t(0x832AA788);
	if (!UseLiftedCode(144, 0x8327E950)) { __imp__sub_8327E950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E418_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E418_G__address);
}
PROMOTED_ENTRY(144, sub_8327E950, 0x8327E950) { ctx.r3.u64 = Construct_TXT_8349E418_G_(ctx, base); }

uint64_t Construct_TXT_8349E41C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E41C_G_ = int32_t(0x8349E41C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AD88);
	constexpr int32_t Destroy_TXT_8349E41C_G__address = int32_t(0x832AA798);
	if (!UseLiftedCode(144, 0x8327E990)) { __imp__sub_8327E990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E990);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E41C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E41C_G__address);
}
PROMOTED_ENTRY(144, sub_8327E990, 0x8327E990) { ctx.r3.u64 = Construct_TXT_8349E41C_G_(ctx, base); }

uint64_t Construct_TXT_8349E420_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E420_G_ = int32_t(0x8349E420);
	constexpr int32_t str_TXT_8209AD9C_B_ = int32_t(0x8209AD9C);
	constexpr int32_t Destroy_TXT_8349E420_G__address = int32_t(0x832AA7A8);
	if (!UseLiftedCode(144, 0x8327E9D0)) { __imp__sub_8327E9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E9D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E420_G_, str_TXT_8209AD9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E420_G__address);
}
PROMOTED_ENTRY(144, sub_8327E9D0, 0x8327E9D0) { ctx.r3.u64 = Construct_TXT_8349E420_G_(ctx, base); }

uint64_t Construct_TXT_8349E424_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E424_G_ = int32_t(0x8349E424);
	constexpr int32_t str_TXT_8209AD00_B_ = int32_t(0x8209AD00);
	constexpr int32_t Destroy_TXT_8349E424_G__address = int32_t(0x832AA7B8);
	if (!UseLiftedCode(144, 0x8327EA10)) { __imp__sub_8327EA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E424_G_, str_TXT_8209AD00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E424_G__address);
}
PROMOTED_ENTRY(144, sub_8327EA10, 0x8327EA10) { ctx.r3.u64 = Construct_TXT_8349E424_G_(ctx, base); }

uint64_t Construct_TXT_8349E428_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E428_G_ = int32_t(0x8349E428);
	constexpr int32_t str_TXT_8209AD18_B_ = int32_t(0x8209AD18);
	constexpr int32_t Destroy_TXT_8349E428_G__address = int32_t(0x832AA7C8);
	if (!UseLiftedCode(144, 0x8327EA50)) { __imp__sub_8327EA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E428_G_, str_TXT_8209AD18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E428_G__address);
}
PROMOTED_ENTRY(144, sub_8327EA50, 0x8327EA50) { ctx.r3.u64 = Construct_TXT_8349E428_G_(ctx, base); }

uint64_t Construct_TXT_8349E42C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E42C_G_ = int32_t(0x8349E42C);
	constexpr int32_t str_TXT_8209AD28_B_ = int32_t(0x8209AD28);
	constexpr int32_t Destroy_TXT_8349E42C_G__address = int32_t(0x832AA7D8);
	if (!UseLiftedCode(144, 0x8327EA90)) { __imp__sub_8327EA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E42C_G_, str_TXT_8209AD28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E42C_G__address);
}
PROMOTED_ENTRY(144, sub_8327EA90, 0x8327EA90) { ctx.r3.u64 = Construct_TXT_8349E42C_G_(ctx, base); }

uint64_t Construct_TXT_8349E430_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E430_G_ = int32_t(0x8349E430);
	constexpr int32_t str_TXT_8209AD2C_B_ = int32_t(0x8209AD2C);
	constexpr int32_t Destroy_TXT_8349E430_G__address = int32_t(0x832AA7E8);
	if (!UseLiftedCode(144, 0x8327EAD0)) { __imp__sub_8327EAD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EAD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E430_G_, str_TXT_8209AD2C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E430_G__address);
}
PROMOTED_ENTRY(144, sub_8327EAD0, 0x8327EAD0) { ctx.r3.u64 = Construct_TXT_8349E430_G_(ctx, base); }

uint64_t Construct_TXT_8349E434_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E434_G_ = int32_t(0x8349E434);
	constexpr int32_t str_TXT_8209AD40_B_ = int32_t(0x8209AD40);
	constexpr int32_t Destroy_TXT_8349E434_G__address = int32_t(0x832AA7F8);
	if (!UseLiftedCode(144, 0x8327EB10)) { __imp__sub_8327EB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E434_G_, str_TXT_8209AD40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E434_G__address);
}
PROMOTED_ENTRY(144, sub_8327EB10, 0x8327EB10) { ctx.r3.u64 = Construct_TXT_8349E434_G_(ctx, base); }

uint64_t Construct_TXT_8349E438_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E438_G_ = int32_t(0x8349E438);
	constexpr int32_t str_TXT_8209B0E8_B_ = int32_t(0x8209AD50);
	constexpr int32_t Destroy_TXT_8349E438_G__address = int32_t(0x832AA808);
	if (!UseLiftedCode(144, 0x8327EB50)) { __imp__sub_8327EB50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E438_G_, str_TXT_8209B0E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E438_G__address);
}
PROMOTED_ENTRY(144, sub_8327EB50, 0x8327EB50) { ctx.r3.u64 = Construct_TXT_8349E438_G_(ctx, base); }

uint64_t Construct_TXT_8349E43C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E43C_G_ = int32_t(0x8349E43C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AB0C);
	constexpr int32_t Destroy_TXT_8349E43C_G__address = int32_t(0x832AA818);
	if (!UseLiftedCode(144, 0x8327EB90)) { __imp__sub_8327EB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E43C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E43C_G__address);
}
PROMOTED_ENTRY(144, sub_8327EB90, 0x8327EB90) { ctx.r3.u64 = Construct_TXT_8349E43C_G_(ctx, base); }

uint64_t Construct_TXT_8349E440_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E440_G_ = int32_t(0x8349E440);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AB14);
	constexpr int32_t Destroy_TXT_8349E440_G__address = int32_t(0x832AA828);
	if (!UseLiftedCode(144, 0x8327EBD0)) { __imp__sub_8327EBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EBD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E440_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E440_G__address);
}
PROMOTED_ENTRY(144, sub_8327EBD0, 0x8327EBD0) { ctx.r3.u64 = Construct_TXT_8349E440_G_(ctx, base); }

uint64_t Construct_TXT_8349E444_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E444_G_ = int32_t(0x8349E444);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AB28);
	constexpr int32_t Destroy_TXT_8349E444_G__address = int32_t(0x832AA838);
	if (!UseLiftedCode(144, 0x8327EC10)) { __imp__sub_8327EC10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E444_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E444_G__address);
}
PROMOTED_ENTRY(144, sub_8327EC10, 0x8327EC10) { ctx.r3.u64 = Construct_TXT_8349E444_G_(ctx, base); }

uint64_t Construct_TXT_8349E448_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E448_G_ = int32_t(0x8349E448);
	constexpr int32_t str_TXT_8209B360_B_ = int32_t(0x8209AB3C);
	constexpr int32_t Destroy_TXT_8349E448_G__address = int32_t(0x832AA848);
	if (!UseLiftedCode(144, 0x8327EC50)) { __imp__sub_8327EC50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E448_G_, str_TXT_8209B360_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E448_G__address);
}
PROMOTED_ENTRY(144, sub_8327EC50, 0x8327EC50) { ctx.r3.u64 = Construct_TXT_8349E448_G_(ctx, base); }

uint64_t Construct_TXT_8349E44C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E44C_G_ = int32_t(0x8349E44C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AB60);
	constexpr int32_t Destroy_TXT_8349E44C_G__address = int32_t(0x832AA858);
	if (!UseLiftedCode(144, 0x8327EC90)) { __imp__sub_8327EC90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E44C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E44C_G__address);
}
PROMOTED_ENTRY(144, sub_8327EC90, 0x8327EC90) { ctx.r3.u64 = Construct_TXT_8349E44C_G_(ctx, base); }

uint64_t Construct_TXT_8349E450_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E450_G_ = int32_t(0x8349E450);
	constexpr int32_t str_TXT_8209AB68_B_ = int32_t(0x8209AB68);
	constexpr int32_t Destroy_TXT_8349E450_G__address = int32_t(0x832AA868);
	if (!UseLiftedCode(144, 0x8327ECD0)) { __imp__sub_8327ECD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ECD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E450_G_, str_TXT_8209AB68_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E450_G__address);
}
PROMOTED_ENTRY(144, sub_8327ECD0, 0x8327ECD0) { ctx.r3.u64 = Construct_TXT_8349E450_G_(ctx, base); }

uint64_t Construct_TXT_8349E454_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E454_G_ = int32_t(0x8349E454);
	constexpr int32_t str_TXT_8209AB88_B_ = int32_t(0x8209AB88);
	constexpr int32_t Destroy_TXT_8349E454_G__address = int32_t(0x832AA878);
	if (!UseLiftedCode(144, 0x8327ED10)) { __imp__sub_8327ED10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E454_G_, str_TXT_8209AB88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E454_G__address);
}
PROMOTED_ENTRY(144, sub_8327ED10, 0x8327ED10) { ctx.r3.u64 = Construct_TXT_8349E454_G_(ctx, base); }

uint64_t Construct_TXT_8349E458_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E458_G_ = int32_t(0x8349E458);
	constexpr int32_t str_TXT_8209ABA8_B_ = int32_t(0x8209ABA8);
	constexpr int32_t Destroy_TXT_8349E458_G__address = int32_t(0x832AA888);
	if (!UseLiftedCode(144, 0x8327ED50)) { __imp__sub_8327ED50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E458_G_, str_TXT_8209ABA8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E458_G__address);
}
PROMOTED_ENTRY(144, sub_8327ED50, 0x8327ED50) { ctx.r3.u64 = Construct_TXT_8349E458_G_(ctx, base); }

uint64_t Construct_TXT_8349E45C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E45C_G_ = int32_t(0x8349E45C);
	constexpr int32_t str_TXT_8209AF4C_B_ = int32_t(0x8209ABB0);
	constexpr int32_t Destroy_TXT_8349E45C_G__address = int32_t(0x832AA898);
	if (!UseLiftedCode(144, 0x8327ED90)) { __imp__sub_8327ED90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E45C_G_, str_TXT_8209AF4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E45C_G__address);
}
PROMOTED_ENTRY(144, sub_8327ED90, 0x8327ED90) { ctx.r3.u64 = Construct_TXT_8349E45C_G_(ctx, base); }

uint64_t Construct_TXT_8349E460_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E460_G_ = int32_t(0x8349E460);
	constexpr int32_t str_TXT_8209ABB8_B_ = int32_t(0x8209ABB8);
	constexpr int32_t Destroy_TXT_8349E460_G__address = int32_t(0x832AA8A8);
	if (!UseLiftedCode(144, 0x8327EDD0)) { __imp__sub_8327EDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EDD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E460_G_, str_TXT_8209ABB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E460_G__address);
}
PROMOTED_ENTRY(144, sub_8327EDD0, 0x8327EDD0) { ctx.r3.u64 = Construct_TXT_8349E460_G_(ctx, base); }

uint64_t Construct_TXT_8349E464_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E464_G_ = int32_t(0x8349E464);
	constexpr int32_t str_TXT_8209ABC8_B_ = int32_t(0x8209ABC8);
	constexpr int32_t Destroy_TXT_8349E464_G__address = int32_t(0x832AA8B8);
	if (!UseLiftedCode(144, 0x8327EE10)) { __imp__sub_8327EE10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E464_G_, str_TXT_8209ABC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E464_G__address);
}
PROMOTED_ENTRY(144, sub_8327EE10, 0x8327EE10) { ctx.r3.u64 = Construct_TXT_8349E464_G_(ctx, base); }

uint64_t Construct_TXT_8349E468_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E468_G_ = int32_t(0x8349E468);
	constexpr int32_t str_TXT_8209AF84_B_ = int32_t(0x8209ABE4);
	constexpr int32_t Destroy_TXT_8349E468_G__address = int32_t(0x832AA8C8);
	if (!UseLiftedCode(144, 0x8327EE50)) { __imp__sub_8327EE50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E468_G_, str_TXT_8209AF84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E468_G__address);
}
PROMOTED_ENTRY(144, sub_8327EE50, 0x8327EE50) { ctx.r3.u64 = Construct_TXT_8349E468_G_(ctx, base); }

uint64_t Construct_TXT_8349E46C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E46C_G_ = int32_t(0x8349E46C);
	constexpr int32_t str_TXT_8209AF90_B_ = int32_t(0x8209ABF0);
	constexpr int32_t Destroy_TXT_8349E46C_G__address = int32_t(0x832AA8D8);
	if (!UseLiftedCode(144, 0x8327EE90)) { __imp__sub_8327EE90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E46C_G_, str_TXT_8209AF90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E46C_G__address);
}
PROMOTED_ENTRY(144, sub_8327EE90, 0x8327EE90) { ctx.r3.u64 = Construct_TXT_8349E46C_G_(ctx, base); }

uint64_t Construct_TXT_8349E470_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E470_G_ = int32_t(0x8349E470);
	constexpr int32_t str_TXT_8209ABFC_B_ = int32_t(0x8209ABFC);
	constexpr int32_t Destroy_TXT_8349E470_G__address = int32_t(0x832AA8E8);
	if (!UseLiftedCode(144, 0x8327EED0)) { __imp__sub_8327EED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EED0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E470_G_, str_TXT_8209ABFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E470_G__address);
}
PROMOTED_ENTRY(144, sub_8327EED0, 0x8327EED0) { ctx.r3.u64 = Construct_TXT_8349E470_G_(ctx, base); }

uint64_t Construct_TXT_8349E474_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E474_G_ = int32_t(0x8349E474);
	constexpr int32_t str_TXT_8209AC04_B_ = int32_t(0x8209AC04);
	constexpr int32_t Destroy_TXT_8349E474_G__address = int32_t(0x832AA8F8);
	if (!UseLiftedCode(144, 0x8327EF10)) { __imp__sub_8327EF10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E474_G_, str_TXT_8209AC04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E474_G__address);
}
PROMOTED_ENTRY(144, sub_8327EF10, 0x8327EF10) { ctx.r3.u64 = Construct_TXT_8349E474_G_(ctx, base); }

uint64_t Construct_TXT_8349E478_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E478_G_ = int32_t(0x8349E478);
	constexpr int32_t str_TXT_8209AC10_B_ = int32_t(0x8209AC10);
	constexpr int32_t Destroy_TXT_8349E478_G__address = int32_t(0x832AA908);
	if (!UseLiftedCode(144, 0x8327EF50)) { __imp__sub_8327EF50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E478_G_, str_TXT_8209AC10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E478_G__address);
}
PROMOTED_ENTRY(144, sub_8327EF50, 0x8327EF50) { ctx.r3.u64 = Construct_TXT_8349E478_G_(ctx, base); }

uint64_t Construct_TXT_8349E47C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E47C_G_ = int32_t(0x8349E47C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AC20);
	constexpr int32_t Destroy_TXT_8349E47C_G__address = int32_t(0x832AA918);
	if (!UseLiftedCode(144, 0x8327EF90)) { __imp__sub_8327EF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E47C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E47C_G__address);
}
PROMOTED_ENTRY(144, sub_8327EF90, 0x8327EF90) { ctx.r3.u64 = Construct_TXT_8349E47C_G_(ctx, base); }

uint64_t Construct_TXT_8349E4C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4C0_G_ = int32_t(0x8349E4C0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AAA4);
	constexpr int32_t Destroy_TXT_8349E4C0_G__address = int32_t(0x832AAA30);
	if (!UseLiftedCode(144, 0x8327F108)) { __imp__sub_8327F108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4C0_G__address);
}
PROMOTED_ENTRY(144, sub_8327F108, 0x8327F108) { ctx.r3.u64 = Construct_TXT_8349E4C0_G_(ctx, base); }

uint64_t Construct_TXT_8349E4C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4C4_G_ = int32_t(0x8349E4C4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AAAC);
	constexpr int32_t Destroy_TXT_8349E4C4_G__address = int32_t(0x832AAA40);
	if (!UseLiftedCode(144, 0x8327F148)) { __imp__sub_8327F148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4C4_G__address);
}
PROMOTED_ENTRY(144, sub_8327F148, 0x8327F148) { ctx.r3.u64 = Construct_TXT_8349E4C4_G_(ctx, base); }

uint64_t Construct_TXT_8349E4C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4C8_G_ = int32_t(0x8349E4C8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AAC0);
	constexpr int32_t Destroy_TXT_8349E4C8_G__address = int32_t(0x832AAA50);
	if (!UseLiftedCode(144, 0x8327F188)) { __imp__sub_8327F188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4C8_G__address);
}
PROMOTED_ENTRY(144, sub_8327F188, 0x8327F188) { ctx.r3.u64 = Construct_TXT_8349E4C8_G_(ctx, base); }

uint64_t Construct_TXT_8349E4CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4CC_G_ = int32_t(0x8349E4CC);
	constexpr int32_t str_TXT_8209AAD4_B_ = int32_t(0x8209AAD4);
	constexpr int32_t Destroy_TXT_8349E4CC_G__address = int32_t(0x832AAA60);
	if (!UseLiftedCode(144, 0x8327F1C8)) { __imp__sub_8327F1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F1C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4CC_G_, str_TXT_8209AAD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4CC_G__address);
}
PROMOTED_ENTRY(144, sub_8327F1C8, 0x8327F1C8) { ctx.r3.u64 = Construct_TXT_8349E4CC_G_(ctx, base); }

uint64_t Construct_TXT_8349E4D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4D0_G_ = int32_t(0x8349E4D0);
	constexpr int32_t str_TXT_8209AAE8_B_ = int32_t(0x8209AAE8);
	constexpr int32_t Destroy_TXT_8349E4D0_G__address = int32_t(0x832AAA70);
	if (!UseLiftedCode(144, 0x8327F208)) { __imp__sub_8327F208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D0_G_, str_TXT_8209AAE8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4D0_G__address);
}
PROMOTED_ENTRY(144, sub_8327F208, 0x8327F208) { ctx.r3.u64 = Construct_TXT_8349E4D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E4D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4D4_G_ = int32_t(0x8349E4D4);
	constexpr int32_t str_TXT_8209AAF8_B_ = int32_t(0x8209AAF8);
	constexpr int32_t Destroy_TXT_8349E4D4_G__address = int32_t(0x832AAA80);
	if (!UseLiftedCode(144, 0x8327F248)) { __imp__sub_8327F248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D4_G_, str_TXT_8209AAF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4D4_G__address);
}
PROMOTED_ENTRY(144, sub_8327F248, 0x8327F248) { ctx.r3.u64 = Construct_TXT_8349E4D4_G_(ctx, base); }

uint64_t Construct_TXT_8349E4D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4D8_G_ = int32_t(0x8349E4D8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209AA40);
	constexpr int32_t Destroy_TXT_8349E4D8_G__address = int32_t(0x832AAA90);
	if (!UseLiftedCode(144, 0x8327F288)) { __imp__sub_8327F288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4D8_G__address);
}
PROMOTED_ENTRY(144, sub_8327F288, 0x8327F288) { ctx.r3.u64 = Construct_TXT_8349E4D8_G_(ctx, base); }

uint64_t Construct_TXT_8349E4DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4DC_G_ = int32_t(0x8349E4DC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209AA48);
	constexpr int32_t Destroy_TXT_8349E4DC_G__address = int32_t(0x832AAAA0);
	if (!UseLiftedCode(144, 0x8327F2C8)) { __imp__sub_8327F2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F2C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4DC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4DC_G__address);
}
PROMOTED_ENTRY(144, sub_8327F2C8, 0x8327F2C8) { ctx.r3.u64 = Construct_TXT_8349E4DC_G_(ctx, base); }

uint64_t Construct_TXT_8349E4E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4E0_G_ = int32_t(0x8349E4E0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209AA5C);
	constexpr int32_t Destroy_TXT_8349E4E0_G__address = int32_t(0x832AAAB0);
	if (!UseLiftedCode(144, 0x8327F308)) { __imp__sub_8327F308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4E0_G__address);
}
PROMOTED_ENTRY(144, sub_8327F308, 0x8327F308) { ctx.r3.u64 = Construct_TXT_8349E4E0_G_(ctx, base); }

uint64_t Construct_TXT_8349E4E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4E4_G_ = int32_t(0x8349E4E4);
	constexpr int32_t str_TXT_8209AA70_B_ = int32_t(0x8209AA70);
	constexpr int32_t Destroy_TXT_8349E4E4_G__address = int32_t(0x832AAAC0);
	if (!UseLiftedCode(144, 0x8327F348)) { __imp__sub_8327F348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E4_G_, str_TXT_8209AA70_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4E4_G__address);
}
PROMOTED_ENTRY(144, sub_8327F348, 0x8327F348) { ctx.r3.u64 = Construct_TXT_8349E4E4_G_(ctx, base); }

uint64_t Construct_TXT_8349E4E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4E8_G_ = int32_t(0x8349E4E8);
	constexpr int32_t str_TXT_8209AA84_B_ = int32_t(0x8209AA84);
	constexpr int32_t Destroy_TXT_8349E4E8_G__address = int32_t(0x832AAAD0);
	if (!UseLiftedCode(144, 0x8327F388)) { __imp__sub_8327F388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E8_G_, str_TXT_8209AA84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4E8_G__address);
}
PROMOTED_ENTRY(144, sub_8327F388, 0x8327F388) { ctx.r3.u64 = Construct_TXT_8349E4E8_G_(ctx, base); }

uint64_t Construct_TXT_8349E4EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4EC_G_ = int32_t(0x8349E4EC);
	constexpr int32_t str_TXT_8209AAF8_B_ = int32_t(0x8209AA90);
	constexpr int32_t Destroy_TXT_8349E4EC_G__address = int32_t(0x832AAAE0);
	if (!UseLiftedCode(144, 0x8327F3C8)) { __imp__sub_8327F3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F3C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4EC_G_, str_TXT_8209AAF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4EC_G__address);
}
PROMOTED_ENTRY(144, sub_8327F3C8, 0x8327F3C8) { ctx.r3.u64 = Construct_TXT_8349E4EC_G_(ctx, base); }

uint64_t Construct_TXT_8349E4F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4F0_G_ = int32_t(0x8349E4F0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A9CC);
	constexpr int32_t Destroy_TXT_8349E4F0_G__address = int32_t(0x832AAAF0);
	if (!UseLiftedCode(144, 0x8327F408)) { __imp__sub_8327F408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4F0_G__address);
}
PROMOTED_ENTRY(144, sub_8327F408, 0x8327F408) { ctx.r3.u64 = Construct_TXT_8349E4F0_G_(ctx, base); }

uint64_t Construct_TXT_8349E4F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4F4_G_ = int32_t(0x8349E4F4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A9D4);
	constexpr int32_t Destroy_TXT_8349E4F4_G__address = int32_t(0x832AAB00);
	if (!UseLiftedCode(144, 0x8327F448)) { __imp__sub_8327F448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4F4_G__address);
}
PROMOTED_ENTRY(144, sub_8327F448, 0x8327F448) { ctx.r3.u64 = Construct_TXT_8349E4F4_G_(ctx, base); }

uint64_t Construct_TXT_8349E4F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4F8_G_ = int32_t(0x8349E4F8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A9E8);
	constexpr int32_t Destroy_TXT_8349E4F8_G__address = int32_t(0x832AAB10);
	if (!UseLiftedCode(144, 0x8327F488)) { __imp__sub_8327F488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4F8_G__address);
}
PROMOTED_ENTRY(144, sub_8327F488, 0x8327F488) { ctx.r3.u64 = Construct_TXT_8349E4F8_G_(ctx, base); }

uint64_t Construct_TXT_8349E4FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E4FC_G_ = int32_t(0x8349E4FC);
	constexpr int32_t str_TXT_8209A9FC_B_ = int32_t(0x8209A9FC);
	constexpr int32_t Destroy_TXT_8349E4FC_G__address = int32_t(0x832AAB20);
	if (!UseLiftedCode(144, 0x8327F4C8)) { __imp__sub_8327F4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F4C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4FC_G_, str_TXT_8209A9FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E4FC_G__address);
}
PROMOTED_ENTRY(144, sub_8327F4C8, 0x8327F4C8) { ctx.r3.u64 = Construct_TXT_8349E4FC_G_(ctx, base); }

uint64_t Construct_TXT_8349E500_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E500_G_ = int32_t(0x8349E500);
	constexpr int32_t str_TXT_8209AA10_B_ = int32_t(0x8209AA10);
	constexpr int32_t Destroy_TXT_8349E500_G__address = int32_t(0x832AAB30);
	if (!UseLiftedCode(144, 0x8327F508)) { __imp__sub_8327F508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E500_G_, str_TXT_8209AA10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E500_G__address);
}
PROMOTED_ENTRY(144, sub_8327F508, 0x8327F508) { ctx.r3.u64 = Construct_TXT_8349E500_G_(ctx, base); }

uint64_t Construct_TXT_8349E504_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E504_G_ = int32_t(0x8349E504);
	constexpr int32_t str_TXT_8209AAE8_B_ = int32_t(0x8209AA1C);
	constexpr int32_t Destroy_TXT_8349E504_G__address = int32_t(0x832AAB40);
	if (!UseLiftedCode(144, 0x8327F548)) { __imp__sub_8327F548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E504_G_, str_TXT_8209AAE8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E504_G__address);
}
PROMOTED_ENTRY(144, sub_8327F548, 0x8327F548) { ctx.r3.u64 = Construct_TXT_8349E504_G_(ctx, base); }

uint64_t Construct_TXT_8349E508_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E508_G_ = int32_t(0x8349E508);
	constexpr int32_t str_TXT_8209AAF8_B_ = int32_t(0x8209AA2C);
	constexpr int32_t Destroy_TXT_8349E508_G__address = int32_t(0x832AAB50);
	if (!UseLiftedCode(144, 0x8327F588)) { __imp__sub_8327F588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E508_G_, str_TXT_8209AAF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E508_G__address);
}
PROMOTED_ENTRY(144, sub_8327F588, 0x8327F588) { ctx.r3.u64 = Construct_TXT_8349E508_G_(ctx, base); }

uint64_t Construct_TXT_8349E50C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E50C_G_ = int32_t(0x8349E50C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A984);
	constexpr int32_t Destroy_TXT_8349E50C_G__address = int32_t(0x832AAB60);
	if (!UseLiftedCode(144, 0x8327F5C8)) { __imp__sub_8327F5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F5C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E50C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E50C_G__address);
}
PROMOTED_ENTRY(144, sub_8327F5C8, 0x8327F5C8) { ctx.r3.u64 = Construct_TXT_8349E50C_G_(ctx, base); }

uint64_t Construct_TXT_8349E510_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E510_G_ = int32_t(0x8349E510);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A98C);
	constexpr int32_t Destroy_TXT_8349E510_G__address = int32_t(0x832AAB70);
	if (!UseLiftedCode(144, 0x8327F608)) { __imp__sub_8327F608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E510_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E510_G__address);
}
PROMOTED_ENTRY(144, sub_8327F608, 0x8327F608) { ctx.r3.u64 = Construct_TXT_8349E510_G_(ctx, base); }

uint64_t Construct_TXT_8349E514_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E514_G_ = int32_t(0x8349E514);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A9A0);
	constexpr int32_t Destroy_TXT_8349E514_G__address = int32_t(0x832AAB80);
	if (!UseLiftedCode(144, 0x8327F648)) { __imp__sub_8327F648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E514_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E514_G__address);
}
PROMOTED_ENTRY(144, sub_8327F648, 0x8327F648) { ctx.r3.u64 = Construct_TXT_8349E514_G_(ctx, base); }

uint64_t Construct_TXT_8349E518_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E518_G_ = int32_t(0x8349E518);
	constexpr int32_t str_TXT_8209A9B4_B_ = int32_t(0x8209A9B4);
	constexpr int32_t Destroy_TXT_8349E518_G__address = int32_t(0x832AAB90);
	if (!UseLiftedCode(144, 0x8327F688)) { __imp__sub_8327F688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F688);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E518_G_, str_TXT_8209A9B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E518_G__address);
}
PROMOTED_ENTRY(144, sub_8327F688, 0x8327F688) { ctx.r3.u64 = Construct_TXT_8349E518_G_(ctx, base); }

uint64_t Construct_TXT_8349E51C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E51C_G_ = int32_t(0x8349E51C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A91C);
	constexpr int32_t Destroy_TXT_8349E51C_G__address = int32_t(0x832AABA0);
	if (!UseLiftedCode(144, 0x8327F6C8)) { __imp__sub_8327F6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F6C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E51C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E51C_G__address);
}
PROMOTED_ENTRY(144, sub_8327F6C8, 0x8327F6C8) { ctx.r3.u64 = Construct_TXT_8349E51C_G_(ctx, base); }

uint64_t Construct_TXT_8349E520_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E520_G_ = int32_t(0x8349E520);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A924);
	constexpr int32_t Destroy_TXT_8349E520_G__address = int32_t(0x832AABB0);
	if (!UseLiftedCode(144, 0x8327F708)) { __imp__sub_8327F708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E520_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E520_G__address);
}
PROMOTED_ENTRY(144, sub_8327F708, 0x8327F708) { ctx.r3.u64 = Construct_TXT_8349E520_G_(ctx, base); }

uint64_t Construct_TXT_8349E524_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E524_G_ = int32_t(0x8349E524);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A938);
	constexpr int32_t Destroy_TXT_8349E524_G__address = int32_t(0x832AABC0);
	if (!UseLiftedCode(144, 0x8327F748)) { __imp__sub_8327F748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F748);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E524_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E524_G__address);
}
PROMOTED_ENTRY(144, sub_8327F748, 0x8327F748) { ctx.r3.u64 = Construct_TXT_8349E524_G_(ctx, base); }

uint64_t Construct_TXT_8349E528_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E528_G_ = int32_t(0x8349E528);
	constexpr int32_t str_TXT_8209A94C_B_ = int32_t(0x8209A94C);
	constexpr int32_t Destroy_TXT_8349E528_G__address = int32_t(0x832AABD0);
	if (!UseLiftedCode(144, 0x8327F788)) { __imp__sub_8327F788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E528_G_, str_TXT_8209A94C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E528_G__address);
}
PROMOTED_ENTRY(144, sub_8327F788, 0x8327F788) { ctx.r3.u64 = Construct_TXT_8349E528_G_(ctx, base); }

uint64_t Construct_TXT_8349E52C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E52C_G_ = int32_t(0x8349E52C);
	constexpr int32_t str_TXT_8209A960_B_ = int32_t(0x8209A960);
	constexpr int32_t Destroy_TXT_8349E52C_G__address = int32_t(0x832AABE0);
	if (!UseLiftedCode(144, 0x8327F7C8)) { __imp__sub_8327F7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F7C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E52C_G_, str_TXT_8209A960_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E52C_G__address);
}
PROMOTED_ENTRY(144, sub_8327F7C8, 0x8327F7C8) { ctx.r3.u64 = Construct_TXT_8349E52C_G_(ctx, base); }

uint64_t Construct_TXT_8349E530_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E530_G_ = int32_t(0x8349E530);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A8E8);
	constexpr int32_t Destroy_TXT_8349E530_G__address = int32_t(0x832AABF0);
	if (!UseLiftedCode(144, 0x8327F808)) { __imp__sub_8327F808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E530_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E530_G__address);
}
PROMOTED_ENTRY(144, sub_8327F808, 0x8327F808) { ctx.r3.u64 = Construct_TXT_8349E530_G_(ctx, base); }

uint64_t Construct_TXT_8349E534_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E534_G_ = int32_t(0x8349E534);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A8F0);
	constexpr int32_t Destroy_TXT_8349E534_G__address = int32_t(0x832AAC00);
	if (!UseLiftedCode(144, 0x8327F848)) { __imp__sub_8327F848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E534_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E534_G__address);
}
PROMOTED_ENTRY(144, sub_8327F848, 0x8327F848) { ctx.r3.u64 = Construct_TXT_8349E534_G_(ctx, base); }

uint64_t Construct_TXT_8349E538_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E538_G_ = int32_t(0x8349E538);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A904);
	constexpr int32_t Destroy_TXT_8349E538_G__address = int32_t(0x832AAC10);
	if (!UseLiftedCode(144, 0x8327F888)) { __imp__sub_8327F888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E538_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E538_G__address);
}
PROMOTED_ENTRY(144, sub_8327F888, 0x8327F888) { ctx.r3.u64 = Construct_TXT_8349E538_G_(ctx, base); }

uint64_t Construct_TXT_8349E53C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E53C_G_ = int32_t(0x8349E53C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A808);
	constexpr int32_t Destroy_TXT_8349E53C_G__address = int32_t(0x832AAC20);
	if (!UseLiftedCode(144, 0x8327F8C8)) { __imp__sub_8327F8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E53C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E53C_G__address);
}
PROMOTED_ENTRY(144, sub_8327F8C8, 0x8327F8C8) { ctx.r3.u64 = Construct_TXT_8349E53C_G_(ctx, base); }

uint64_t Construct_TXT_8349E540_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E540_G_ = int32_t(0x8349E540);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A810);
	constexpr int32_t Destroy_TXT_8349E540_G__address = int32_t(0x832AAC30);
	if (!UseLiftedCode(144, 0x8327F908)) { __imp__sub_8327F908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E540_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E540_G__address);
}
PROMOTED_ENTRY(144, sub_8327F908, 0x8327F908) { ctx.r3.u64 = Construct_TXT_8349E540_G_(ctx, base); }

uint64_t Construct_TXT_8349E544_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E544_G_ = int32_t(0x8349E544);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A824);
	constexpr int32_t Destroy_TXT_8349E544_G__address = int32_t(0x832AAC40);
	if (!UseLiftedCode(144, 0x8327F948)) { __imp__sub_8327F948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E544_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E544_G__address);
}
PROMOTED_ENTRY(144, sub_8327F948, 0x8327F948) { ctx.r3.u64 = Construct_TXT_8349E544_G_(ctx, base); }

uint64_t Construct_TXT_8349E548_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E548_G_ = int32_t(0x8349E548);
	constexpr int32_t str_TXT_8209A838_B_ = int32_t(0x8209A838);
	constexpr int32_t Destroy_TXT_8349E548_G__address = int32_t(0x832AAC50);
	if (!UseLiftedCode(144, 0x8327FAC8)) { __imp__sub_8327FAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E548_G_, str_TXT_8209A838_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E548_G__address);
}
PROMOTED_ENTRY(144, sub_8327FAC8, 0x8327FAC8) { ctx.r3.u64 = Construct_TXT_8349E548_G_(ctx, base); }

uint64_t Construct_TXT_8349E54C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E54C_G_ = int32_t(0x8349E54C);
	constexpr int32_t str_TXT_8209ABB8_B_ = int32_t(0x8209A858);
	constexpr int32_t Destroy_TXT_8349E54C_G__address = int32_t(0x832AAC60);
	if (!UseLiftedCode(144, 0x8327FB08)) { __imp__sub_8327FB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E54C_G_, str_TXT_8209ABB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E54C_G__address);
}
PROMOTED_ENTRY(144, sub_8327FB08, 0x8327FB08) { ctx.r3.u64 = Construct_TXT_8349E54C_G_(ctx, base); }

uint64_t Construct_TXT_8349E590_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E590_G_ = int32_t(0x8349E590);
	constexpr int32_t str_TXT_8209A868_B_ = int32_t(0x8209A868);
	constexpr int32_t Destroy_TXT_8349E590_G__address = int32_t(0x832AAC70);
	if (!UseLiftedCode(144, 0x8327FB48)) { __imp__sub_8327FB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E590_G_, str_TXT_8209A868_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E590_G__address);
}
PROMOTED_ENTRY(144, sub_8327FB48, 0x8327FB48) { ctx.r3.u64 = Construct_TXT_8349E590_G_(ctx, base); }

uint64_t Construct_TXT_8349E594_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E594_G_ = int32_t(0x8349E594);
	constexpr int32_t str_TXT_8209A888_B_ = int32_t(0x8209A888);
	constexpr int32_t Destroy_TXT_8349E594_G__address = int32_t(0x832AAC80);
	if (!UseLiftedCode(144, 0x8327FB88)) { __imp__sub_8327FB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E594_G_, str_TXT_8209A888_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E594_G__address);
}
PROMOTED_ENTRY(144, sub_8327FB88, 0x8327FB88) { ctx.r3.u64 = Construct_TXT_8349E594_G_(ctx, base); }

uint64_t Construct_TXT_8349E598_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E598_G_ = int32_t(0x8349E598);
	constexpr int32_t str_TXT_8209A8A4_B_ = int32_t(0x8209A8A4);
	constexpr int32_t Destroy_TXT_8349E598_G__address = int32_t(0x832AAC90);
	if (!UseLiftedCode(144, 0x8327FBC8)) { __imp__sub_8327FBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E598_G_, str_TXT_8209A8A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E598_G__address);
}
PROMOTED_ENTRY(144, sub_8327FBC8, 0x8327FBC8) { ctx.r3.u64 = Construct_TXT_8349E598_G_(ctx, base); }

uint64_t Construct_TXT_8349E59C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E59C_G_ = int32_t(0x8349E59C);
	constexpr int32_t str_TXT_8209A8B4_B_ = int32_t(0x8209A8B4);
	constexpr int32_t Destroy_TXT_8349E59C_G__address = int32_t(0x832AACA0);
	if (!UseLiftedCode(144, 0x8327FC08)) { __imp__sub_8327FC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E59C_G_, str_TXT_8209A8B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E59C_G__address);
}
PROMOTED_ENTRY(144, sub_8327FC08, 0x8327FC08) { ctx.r3.u64 = Construct_TXT_8349E59C_G_(ctx, base); }

uint64_t Construct_TXT_8349E5A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5A0_G_ = int32_t(0x8349E5A0);
	constexpr int32_t str_TXT_8209A8C4_B_ = int32_t(0x8209A8C4);
	constexpr int32_t Destroy_TXT_8349E5A0_G__address = int32_t(0x832AACB0);
	if (!UseLiftedCode(144, 0x8327FC48)) { __imp__sub_8327FC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A0_G_, str_TXT_8209A8C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5A0_G__address);
}
PROMOTED_ENTRY(144, sub_8327FC48, 0x8327FC48) { ctx.r3.u64 = Construct_TXT_8349E5A0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5A4_G_ = int32_t(0x8349E5A4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A724);
	constexpr int32_t Destroy_TXT_8349E5A4_G__address = int32_t(0x832AACC0);
	if (!UseLiftedCode(144, 0x8327FC88)) { __imp__sub_8327FC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5A4_G__address);
}
PROMOTED_ENTRY(144, sub_8327FC88, 0x8327FC88) { ctx.r3.u64 = Construct_TXT_8349E5A4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5A8_G_ = int32_t(0x8349E5A8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A72C);
	constexpr int32_t Destroy_TXT_8349E5A8_G__address = int32_t(0x832AACD0);
	if (!UseLiftedCode(144, 0x8327FCC8)) { __imp__sub_8327FCC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FCC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5A8_G__address);
}
PROMOTED_ENTRY(144, sub_8327FCC8, 0x8327FCC8) { ctx.r3.u64 = Construct_TXT_8349E5A8_G_(ctx, base); }

uint64_t Construct_TXT_8349E5AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5AC_G_ = int32_t(0x8349E5AC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A740);
	constexpr int32_t Destroy_TXT_8349E5AC_G__address = int32_t(0x832AACE0);
	if (!UseLiftedCode(144, 0x8327FD08)) { __imp__sub_8327FD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5AC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5AC_G__address);
}
PROMOTED_ENTRY(144, sub_8327FD08, 0x8327FD08) { ctx.r3.u64 = Construct_TXT_8349E5AC_G_(ctx, base); }

uint64_t Construct_TXT_8349E5B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5B0_G_ = int32_t(0x8349E5B0);
	constexpr int32_t str_TXT_8209A754_B_ = int32_t(0x8209A754);
	constexpr int32_t Destroy_TXT_8349E5B0_G__address = int32_t(0x832AACF0);
	if (!UseLiftedCode(144, 0x8327FD48)) { __imp__sub_8327FD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B0_G_, str_TXT_8209A754_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5B0_G__address);
}
PROMOTED_ENTRY(144, sub_8327FD48, 0x8327FD48) { ctx.r3.u64 = Construct_TXT_8349E5B0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5B4_G_ = int32_t(0x8349E5B4);
	constexpr int32_t str_TXT_8209A770_B_ = int32_t(0x8209A770);
	constexpr int32_t Destroy_TXT_8349E5B4_G__address = int32_t(0x832AAD00);
	if (!UseLiftedCode(144, 0x8327FD88)) { __imp__sub_8327FD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B4_G_, str_TXT_8209A770_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5B4_G__address);
}
PROMOTED_ENTRY(144, sub_8327FD88, 0x8327FD88) { ctx.r3.u64 = Construct_TXT_8349E5B4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5B8_G_ = int32_t(0x8349E5B8);
	constexpr int32_t str_TXT_8209A780_B_ = int32_t(0x8209A780);
	constexpr int32_t Destroy_TXT_8349E5B8_G__address = int32_t(0x832AAD10);
	if (!UseLiftedCode(144, 0x8327FDC8)) { __imp__sub_8327FDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FDC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B8_G_, str_TXT_8209A780_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5B8_G__address);
}
PROMOTED_ENTRY(144, sub_8327FDC8, 0x8327FDC8) { ctx.r3.u64 = Construct_TXT_8349E5B8_G_(ctx, base); }

uint64_t Construct_TXT_8349E5BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5BC_G_ = int32_t(0x8349E5BC);
	constexpr int32_t str_TXT_8209A794_B_ = int32_t(0x8209A794);
	constexpr int32_t Destroy_TXT_8349E5BC_G__address = int32_t(0x832AAD20);
	if (!UseLiftedCode(144, 0x8327FE08)) { __imp__sub_8327FE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5BC_G_, str_TXT_8209A794_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5BC_G__address);
}
PROMOTED_ENTRY(144, sub_8327FE08, 0x8327FE08) { ctx.r3.u64 = Construct_TXT_8349E5BC_G_(ctx, base); }

uint64_t Construct_TXT_8349E5C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5C0_G_ = int32_t(0x8349E5C0);
	constexpr int32_t str_TXT_8209A7AC_B_ = int32_t(0x8209A7AC);
	constexpr int32_t Destroy_TXT_8349E5C0_G__address = int32_t(0x832AAD30);
	if (!UseLiftedCode(144, 0x8327FE48)) { __imp__sub_8327FE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C0_G_, str_TXT_8209A7AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5C0_G__address);
}
PROMOTED_ENTRY(144, sub_8327FE48, 0x8327FE48) { ctx.r3.u64 = Construct_TXT_8349E5C0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5C4_G_ = int32_t(0x8349E5C4);
	constexpr int32_t str_TXT_8209A7C0_B_ = int32_t(0x8209A7C0);
	constexpr int32_t Destroy_TXT_8349E5C4_G__address = int32_t(0x832AAD40);
	if (!UseLiftedCode(144, 0x8327FE88)) { __imp__sub_8327FE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C4_G_, str_TXT_8209A7C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5C4_G__address);
}
PROMOTED_ENTRY(144, sub_8327FE88, 0x8327FE88) { ctx.r3.u64 = Construct_TXT_8349E5C4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5C8_G_ = int32_t(0x8349E5C8);
	constexpr int32_t str_TXT_8209A7DC_B_ = int32_t(0x8209A7DC);
	constexpr int32_t Destroy_TXT_8349E5C8_G__address = int32_t(0x832AAD50);
	if (!UseLiftedCode(144, 0x8327FEC8)) { __imp__sub_8327FEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C8_G_, str_TXT_8209A7DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5C8_G__address);
}
PROMOTED_ENTRY(144, sub_8327FEC8, 0x8327FEC8) { ctx.r3.u64 = Construct_TXT_8349E5C8_G_(ctx, base); }

uint64_t Construct_TXT_8349E5CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5CC_G_ = int32_t(0x8349E5CC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A7F4);
	constexpr int32_t Destroy_TXT_8349E5CC_G__address = int32_t(0x832AAD60);
	if (!UseLiftedCode(144, 0x8327FF08)) { __imp__sub_8327FF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5CC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5CC_G__address);
}
PROMOTED_ENTRY(144, sub_8327FF08, 0x8327FF08) { ctx.r3.u64 = Construct_TXT_8349E5CC_G_(ctx, base); }

uint64_t Construct_TXT_8349E5D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5D0_G_ = int32_t(0x8349E5D0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x8209A5FC);
	constexpr int32_t Destroy_TXT_8349E5D0_G__address = int32_t(0x832AAD70);
	if (!UseLiftedCode(144, 0x8327FF48)) { __imp__sub_8327FF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5D0_G__address);
}
PROMOTED_ENTRY(144, sub_8327FF48, 0x8327FF48) { ctx.r3.u64 = Construct_TXT_8349E5D0_G_(ctx, base); }

uint64_t Construct_TXT_8349E5D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5D4_G_ = int32_t(0x8349E5D4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x8209A604);
	constexpr int32_t Destroy_TXT_8349E5D4_G__address = int32_t(0x832AAD80);
	if (!UseLiftedCode(144, 0x8327FF88)) { __imp__sub_8327FF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5D4_G__address);
}
PROMOTED_ENTRY(144, sub_8327FF88, 0x8327FF88) { ctx.r3.u64 = Construct_TXT_8349E5D4_G_(ctx, base); }

uint64_t Construct_TXT_8349E5D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349E5D8_G_ = int32_t(0x8349E5D8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x8209A618);
	constexpr int32_t Destroy_TXT_8349E5D8_G__address = int32_t(0x832AAD90);
	if (!UseLiftedCode(144, 0x8327FFC8)) { __imp__sub_8327FFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349E5D8_G__address);
}
PROMOTED_ENTRY(144, sub_8327FFC8, 0x8327FFC8) { ctx.r3.u64 = Construct_TXT_8349E5D8_G_(ctx, base); }
