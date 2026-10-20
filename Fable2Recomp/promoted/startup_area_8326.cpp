// Start-up initialisers of global objects (they register property and definition names) at
// 0x8326xxxx, as readable C++.
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

uint64_t Construct_TXT_8349B52C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B52C_G_ = int32_t(0x8349B52C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B52C_G__address = int32_t(0x832A6178);
	if (!UseLiftedCode(143, 0x83260318)) { __imp__sub_83260318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260318);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B52C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B52C_G__address);
}
PROMOTED_ENTRY(143, sub_83260318, 0x83260318) { ctx.r3.u64 = Construct_TXT_8349B52C_G_(ctx, base); }

uint64_t Construct_TXT_8349B530_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B530_G_ = int32_t(0x8349B530);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B530_G__address = int32_t(0x832A6188);
	if (!UseLiftedCode(143, 0x83260358)) { __imp__sub_83260358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B530_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B530_G__address);
}
PROMOTED_ENTRY(143, sub_83260358, 0x83260358) { ctx.r3.u64 = Construct_TXT_8349B530_G_(ctx, base); }

uint64_t Construct_TXT_8349B534_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B534_G_ = int32_t(0x8349B534);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B534_G__address = int32_t(0x832A6198);
	if (!UseLiftedCode(143, 0x83260398)) { __imp__sub_83260398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B534_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B534_G__address);
}
PROMOTED_ENTRY(143, sub_83260398, 0x83260398) { ctx.r3.u64 = Construct_TXT_8349B534_G_(ctx, base); }

uint64_t RegisterExitDestructor832A61B8(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A61B8_address = int32_t(0x832A61B8);
	if (!UseLiftedCode(143, 0x83260468)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260468);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A61B8_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260468, 0x83260468) { ctx.r3.u64 = RegisterExitDestructor832A61B8(ctx, base, ctx.r8.u64); }

uint64_t RegisterExitDestructor832A61C8(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A61C8_address = int32_t(0x832A61C8);
	if (!UseLiftedCode(143, 0x83260478)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260478);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A61C8_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260478, 0x83260478) { ctx.r3.u64 = RegisterExitDestructor832A61C8(ctx, base, ctx.r8.u64); }

uint64_t RegisterExitDestructor832A61D8(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A61D8_address = int32_t(0x832A61D8);
	if (!UseLiftedCode(143, 0x83260488)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260488);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A61D8_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260488, 0x83260488) { ctx.r3.u64 = RegisterExitDestructor832A61D8(ctx, base, ctx.r8.u64); }

uint64_t RegisterExitDestructor832A61E8(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A61E8_address = int32_t(0x832A61E8);
	if (!UseLiftedCode(143, 0x83260498)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260498);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A61E8_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260498, 0x83260498) { ctx.r3.u64 = RegisterExitDestructor832A61E8(ctx, base, ctx.r8.u64); }

uint64_t InitializeEnvThemeSlowTime2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B564_G_ = int32_t(0x8349B564);
	constexpr int32_t str_TXT_820D6524_B_ = int32_t(0x820D6524);
	constexpr int32_t Destroy_TXT_8349B564_G__address = int32_t(0x832A61F8);
	if (!UseLiftedCode(143, 0x832604A8)) { __imp__sub_832604A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832604A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B564_G_, str_TXT_820D6524_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B564_G__address);
}
PROMOTED_ENTRY(143, sub_832604A8, 0x832604A8) { ctx.r3.u64 = InitializeEnvThemeSlowTime2(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__22 = 0x8349B568u;
	if (!UseLiftedCode(143, 0x832604E8)) { __imp__sub_832604E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832604E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832604E8, 0x832604E8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__22(ctx, base); }

uint64_t HashName_TXT_820D6538_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D6538_B_ = int32_t(0x820D6538);
	constexpr uint32_t g_HashOf_TXT_820D6538_B_ = 0x8349B56Cu;
	if (!UseLiftedCode(143, 0x83260520)) { __imp__sub_83260520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260520);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D6538_B_);
	STORE32(g_HashOf_TXT_820D6538_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260520, 0x83260520) { ctx.r3.u64 = HashName_TXT_820D6538_B_(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__22 = 0x8349B570u;
	if (!UseLiftedCode(143, 0x83260558)) { __imp__sub_83260558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260558);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260558, 0x83260558) { ctx.r3.u64 = HashName_TXT_820A2C44_B__22(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__22 = 0x8349B574u;
	if (!UseLiftedCode(143, 0x83260590)) { __imp__sub_83260590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260590);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260590, 0x83260590) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__22(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__22 = 0x8349B578u;
	if (!UseLiftedCode(143, 0x832605C8)) { __imp__sub_832605C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832605C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832605C8, 0x832605C8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__22(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__24 = 0x8349B57Cu;
	if (!UseLiftedCode(143, 0x83260600)) { __imp__sub_83260600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260600);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260600, 0x83260600) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__24(ctx, base); }

uint64_t HashName_TXT_820D6550_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D6550_B_ = int32_t(0x820D6550);
	constexpr uint32_t g_HashOf_TXT_820D6550_B_ = 0x8349B580u;
	if (!UseLiftedCode(143, 0x83260638)) { __imp__sub_83260638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260638);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D6550_B_);
	STORE32(g_HashOf_TXT_820D6550_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260638, 0x83260638) { ctx.r3.u64 = HashName_TXT_820D6550_B_(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__22 = 0x8349B584u;
	if (!UseLiftedCode(143, 0x83260670)) { __imp__sub_83260670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260670);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260670, 0x83260670) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__22(ctx, base); }

uint64_t HashName_TXT_820D655C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D655C_B_ = int32_t(0x820D655C);
	constexpr uint32_t g_HashOf_TXT_820D655C_B_ = 0x8349B588u;
	if (!UseLiftedCode(143, 0x832606A8)) { __imp__sub_832606A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832606A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D655C_B_);
	STORE32(g_HashOf_TXT_820D655C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832606A8, 0x832606A8) { ctx.r3.u64 = HashName_TXT_820D655C_B_(ctx, base); }

uint64_t HashName_TXT_820D656C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D656C_B_ = int32_t(0x820D656C);
	constexpr uint32_t g_HashOf_TXT_820D656C_B_ = 0x8349B58Cu;
	if (!UseLiftedCode(143, 0x832606E0)) { __imp__sub_832606E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832606E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D656C_B_);
	STORE32(g_HashOf_TXT_820D656C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_832606E0, 0x832606E0) { ctx.r3.u64 = HashName_TXT_820D656C_B_(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__22 = 0x8349B590u;
	if (!UseLiftedCode(143, 0x83260718)) { __imp__sub_83260718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260718);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260718, 0x83260718) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__22(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__22 = 0x8349B594u;
	if (!UseLiftedCode(143, 0x83260750)) { __imp__sub_83260750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260750);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260750, 0x83260750) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__22(ctx, base); }

uint64_t Construct_TXT_8349B608_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B608_G_ = int32_t(0x8349B608);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B608_G__address = int32_t(0x832A6270);
	if (!UseLiftedCode(143, 0x832609E8)) { __imp__sub_832609E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832609E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B608_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B608_G__address);
}
PROMOTED_ENTRY(143, sub_832609E8, 0x832609E8) { ctx.r3.u64 = Construct_TXT_8349B608_G_(ctx, base); }

uint64_t Construct_TXT_8349B60C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B60C_G_ = int32_t(0x8349B60C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B60C_G__address = int32_t(0x832A6280);
	if (!UseLiftedCode(143, 0x83260A28)) { __imp__sub_83260A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260A28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B60C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B60C_G__address);
}
PROMOTED_ENTRY(143, sub_83260A28, 0x83260A28) { ctx.r3.u64 = Construct_TXT_8349B60C_G_(ctx, base); }

uint64_t Construct_TXT_8349B610_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B610_G_ = int32_t(0x8349B610);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B610_G__address = int32_t(0x832A6290);
	if (!UseLiftedCode(143, 0x83260A68)) { __imp__sub_83260A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260A68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B610_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B610_G__address);
}
PROMOTED_ENTRY(143, sub_83260A68, 0x83260A68) { ctx.r3.u64 = Construct_TXT_8349B610_G_(ctx, base); }

uint64_t HashName_TXT_820B98EC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B98EC_B_ = int32_t(0x820B98EC);
	constexpr uint32_t g_HashOf_TXT_820B98EC_B_ = 0x8349B614u;
	if (!UseLiftedCode(143, 0x83260AA8)) { __imp__sub_83260AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820B98EC_B_);
	STORE32(g_HashOf_TXT_820B98EC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(143, sub_83260AA8, 0x83260AA8) { ctx.r3.u64 = HashName_TXT_820B98EC_B_(ctx, base); }

uint64_t Construct_TXT_8349B618_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B618_G_ = int32_t(0x8349B618);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B618_G__address = int32_t(0x832A62A0);
	if (!UseLiftedCode(143, 0x83260AE0)) { __imp__sub_83260AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B618_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B618_G__address);
}
PROMOTED_ENTRY(143, sub_83260AE0, 0x83260AE0) { ctx.r3.u64 = Construct_TXT_8349B618_G_(ctx, base); }

uint64_t Construct_TXT_8349B61C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B61C_G_ = int32_t(0x8349B61C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B61C_G__address = int32_t(0x832A62B0);
	if (!UseLiftedCode(143, 0x83260B20)) { __imp__sub_83260B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260B20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B61C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B61C_G__address);
}
PROMOTED_ENTRY(143, sub_83260B20, 0x83260B20) { ctx.r3.u64 = Construct_TXT_8349B61C_G_(ctx, base); }

uint64_t Construct_TXT_8349B620_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B620_G_ = int32_t(0x8349B620);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B620_G__address = int32_t(0x832A62C0);
	if (!UseLiftedCode(143, 0x83260B60)) { __imp__sub_83260B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260B60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B620_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B620_G__address);
}
PROMOTED_ENTRY(143, sub_83260B60, 0x83260B60) { ctx.r3.u64 = Construct_TXT_8349B620_G_(ctx, base); }

uint64_t Construct_TXT_8349B624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B624_G_ = int32_t(0x8349B624);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B624_G__address = int32_t(0x832A62D0);
	if (!UseLiftedCode(143, 0x83260BA0)) { __imp__sub_83260BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260BA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B624_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B624_G__address);
}
PROMOTED_ENTRY(143, sub_83260BA0, 0x83260BA0) { ctx.r3.u64 = Construct_TXT_8349B624_G_(ctx, base); }

uint64_t Construct_TXT_8349B628_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B628_G_ = int32_t(0x8349B628);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B628_G__address = int32_t(0x832A62E0);
	if (!UseLiftedCode(143, 0x83260BE0)) { __imp__sub_83260BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260BE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B628_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B628_G__address);
}
PROMOTED_ENTRY(143, sub_83260BE0, 0x83260BE0) { ctx.r3.u64 = Construct_TXT_8349B628_G_(ctx, base); }

uint64_t Construct_TXT_8349B62C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B62C_G_ = int32_t(0x8349B62C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B62C_G__address = int32_t(0x832A62F0);
	if (!UseLiftedCode(143, 0x83260C20)) { __imp__sub_83260C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260C20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B62C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B62C_G__address);
}
PROMOTED_ENTRY(143, sub_83260C20, 0x83260C20) { ctx.r3.u64 = Construct_TXT_8349B62C_G_(ctx, base); }

uint64_t Construct_TXT_8349B634_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B634_G_ = int32_t(0x8349B634);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B634_G__address = int32_t(0x832A6300);
	if (!UseLiftedCode(143, 0x83260C80)) { __imp__sub_83260C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260C80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B634_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B634_G__address);
}
PROMOTED_ENTRY(143, sub_83260C80, 0x83260C80) { ctx.r3.u64 = Construct_TXT_8349B634_G_(ctx, base); }

uint64_t Construct_TXT_8349B638_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B638_G_ = int32_t(0x8349B638);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B638_G__address = int32_t(0x832A6310);
	if (!UseLiftedCode(143, 0x83260CC0)) { __imp__sub_83260CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260CC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B638_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B638_G__address);
}
PROMOTED_ENTRY(143, sub_83260CC0, 0x83260CC0) { ctx.r3.u64 = Construct_TXT_8349B638_G_(ctx, base); }

uint64_t Construct_TXT_8349B63C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B63C_G_ = int32_t(0x8349B63C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B63C_G__address = int32_t(0x832A6320);
	if (!UseLiftedCode(143, 0x83260D00)) { __imp__sub_83260D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B63C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B63C_G__address);
}
PROMOTED_ENTRY(143, sub_83260D00, 0x83260D00) { ctx.r3.u64 = Construct_TXT_8349B63C_G_(ctx, base); }

uint64_t Construct_TXT_8349B640_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B640_G_ = int32_t(0x8349B640);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349B640_G__address = int32_t(0x832A6330);
	if (!UseLiftedCode(143, 0x83260D40)) { __imp__sub_83260D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B640_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B640_G__address);
}
PROMOTED_ENTRY(143, sub_83260D40, 0x83260D40) { ctx.r3.u64 = Construct_TXT_8349B640_G_(ctx, base); }

uint64_t Construct_TXT_8349B644_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B644_G_ = int32_t(0x8349B644);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349B644_G__address = int32_t(0x832A6340);
	if (!UseLiftedCode(143, 0x83260D80)) { __imp__sub_83260D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B644_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B644_G__address);
}
PROMOTED_ENTRY(143, sub_83260D80, 0x83260D80) { ctx.r3.u64 = Construct_TXT_8349B644_G_(ctx, base); }

uint64_t Construct_TXT_8349B648_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349B648_G_ = int32_t(0x8349B648);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349B648_G__address = int32_t(0x832A6350);
	if (!UseLiftedCode(143, 0x83260DC0)) { __imp__sub_83260DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260DC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B648_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349B648_G__address);
}
PROMOTED_ENTRY(143, sub_83260DC0, 0x83260DC0) { ctx.r3.u64 = Construct_TXT_8349B648_G_(ctx, base); }

uint64_t Construct_TXT_8349BB10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BB10_G_ = int32_t(0x8349BB10);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BB10_G__address = int32_t(0x832A6360);
	if (!UseLiftedCode(143, 0x83260E40)) { __imp__sub_83260E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260E40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB10_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BB10_G__address);
}
PROMOTED_ENTRY(143, sub_83260E40, 0x83260E40) { ctx.r3.u64 = Construct_TXT_8349BB10_G_(ctx, base); }

uint64_t Construct_TXT_8349BB14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BB14_G_ = int32_t(0x8349BB14);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BB14_G__address = int32_t(0x832A6370);
	if (!UseLiftedCode(143, 0x83260E80)) { __imp__sub_83260E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260E80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB14_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BB14_G__address);
}
PROMOTED_ENTRY(143, sub_83260E80, 0x83260E80) { ctx.r3.u64 = Construct_TXT_8349BB14_G_(ctx, base); }

uint64_t Construct_TXT_8349BB18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BB18_G_ = int32_t(0x8349BB18);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BB18_G__address = int32_t(0x832A6380);
	if (!UseLiftedCode(143, 0x83260EC0)) { __imp__sub_83260EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260EC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB18_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BB18_G__address);
}
PROMOTED_ENTRY(143, sub_83260EC0, 0x83260EC0) { ctx.r3.u64 = Construct_TXT_8349BB18_G_(ctx, base); }

uint64_t RegisterExitDestructor832A6390(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A6390_address = int32_t(0x832A6390);
	if (!UseLiftedCode(143, 0x83260F00)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F00);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A6390_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260F00, 0x83260F00) { ctx.r3.u64 = RegisterExitDestructor832A6390(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349BB2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BB2C_G_ = int32_t(0x8349BB2C);
	constexpr int32_t str_TXT_820AE494_B_ = int32_t(0x820AE494);
	constexpr int32_t Destroy_TXT_8349BB2C_G__address = int32_t(0x832A63F8);
	if (!UseLiftedCode(143, 0x83260F10)) { __imp__sub_83260F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB2C_G_, str_TXT_820AE494_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BB2C_G__address);
}
PROMOTED_ENTRY(143, sub_83260F10, 0x83260F10) { ctx.r3.u64 = Construct_TXT_8349BB2C_G_(ctx, base); }

uint64_t RegisterExitDestructor832A6408(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A6408_address = int32_t(0x832A6408);
	if (!UseLiftedCode(143, 0x83260F50)) { ctx.r8.u64 = destructorArgument; __imp__sub_83260F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F50);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A6408_address, destructorArgument);
}
PROMOTED_ENTRY(143, sub_83260F50, 0x83260F50) { ctx.r3.u64 = RegisterExitDestructor832A6408(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349BB40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BB40_G_ = int32_t(0x8349BB40);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BB40_G__address = int32_t(0x832A6488);
	if (!UseLiftedCode(143, 0x83260F60)) { __imp__sub_83260F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB40_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BB40_G__address);
}
PROMOTED_ENTRY(143, sub_83260F60, 0x83260F60) { ctx.r3.u64 = Construct_TXT_8349BB40_G_(ctx, base); }

// sub_83260FA0  [60 bytes]
uint64_t InitStringGlobal_8349BB44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB44 = int32_t(0x8349BB44);
	constexpr int32_t n_sub_832A6498_address = int32_t(0x832A6498);
	if (!UseLiftedCode(143, 0x83260FA0)) { __imp__sub_83260FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260FA0);
	// Assigns the global string from a wide string constant, then registers its release to run at exit
	// (RegisterAtExit is atexit).
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB44, (int64_t)str_TXT_820D0000_B_ + 31532);
	uint64_t result = RegisterAtExit(ctx, base, n_sub_832A6498_address);
	return result;
}
PROMOTED_ENTRY(143, sub_83260FA0, 0x83260FA0) { ctx.r3.u64 = InitStringGlobal_8349BB44(ctx, base); }

uint64_t InitStringGlobal_8349BB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB48 = int32_t(0x8349BB48);
	constexpr int32_t n_sub_832A64A8_address = int32_t(0x832A64A8);
	if (!UseLiftedCode(143, 0x83260FE0)) { __imp__sub_83260FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260FE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB48, (int64_t)str_TXT_820D0000_B_ + 31536);
	return RegisterAtExit(ctx, base, n_sub_832A64A8_address);
}
PROMOTED_ENTRY(143, sub_83260FE0, 0x83260FE0) { ctx.r3.u64 = InitStringGlobal_8349BB48(ctx, base); }

uint64_t InitStringGlobal_8349BB4C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB4C = int32_t(0x8349BB4C);
	constexpr int32_t n_sub_832A64B8_address = int32_t(0x832A64B8);
	if (!UseLiftedCode(143, 0x83261020)) { __imp__sub_83261020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261020);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB4C, (int64_t)str_TXT_820D0000_B_ + 31544);
	return RegisterAtExit(ctx, base, n_sub_832A64B8_address);
}
PROMOTED_ENTRY(143, sub_83261020, 0x83261020) { ctx.r3.u64 = InitStringGlobal_8349BB4C(ctx, base); }

uint64_t InitStringGlobal_8349BB50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB50 = int32_t(0x8349BB50);
	constexpr int32_t n_sub_832A64C8_address = int32_t(0x832A64C8);
	if (!UseLiftedCode(143, 0x83261060)) { __imp__sub_83261060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261060);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB50, (int64_t)str_TXT_820D0000_B_ + 31552);
	return RegisterAtExit(ctx, base, n_sub_832A64C8_address);
}
PROMOTED_ENTRY(143, sub_83261060, 0x83261060) { ctx.r3.u64 = InitStringGlobal_8349BB50(ctx, base); }

uint64_t InitStringGlobal_8349BB54(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB54 = int32_t(0x8349BB54);
	constexpr int32_t n_sub_832A64D8_address = int32_t(0x832A64D8);
	if (!UseLiftedCode(143, 0x832610A0)) { __imp__sub_832610A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832610A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB54, (int64_t)str_TXT_820D0000_B_ + 31560);
	return RegisterAtExit(ctx, base, n_sub_832A64D8_address);
}
PROMOTED_ENTRY(143, sub_832610A0, 0x832610A0) { ctx.r3.u64 = InitStringGlobal_8349BB54(ctx, base); }

uint64_t InitStringGlobal_8349BB58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB58 = int32_t(0x8349BB58);
	constexpr int32_t n_sub_832A64E8_address = int32_t(0x832A64E8);
	if (!UseLiftedCode(143, 0x832610E0)) { __imp__sub_832610E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832610E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB58, (int64_t)str_TXT_820D0000_B_ + 31568);
	return RegisterAtExit(ctx, base, n_sub_832A64E8_address);
}
PROMOTED_ENTRY(143, sub_832610E0, 0x832610E0) { ctx.r3.u64 = InitStringGlobal_8349BB58(ctx, base); }

uint64_t InitStringGlobal_8349BB5C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB5C = int32_t(0x8349BB5C);
	constexpr int32_t n_sub_832A64F8_address = int32_t(0x832A64F8);
	if (!UseLiftedCode(143, 0x83261120)) { __imp__sub_83261120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261120);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB5C, (int64_t)str_TXT_820D0000_B_ + 31580);
	return RegisterAtExit(ctx, base, n_sub_832A64F8_address);
}
PROMOTED_ENTRY(143, sub_83261120, 0x83261120) { ctx.r3.u64 = InitStringGlobal_8349BB5C(ctx, base); }

uint64_t InitStringGlobal_8349BB60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB60 = int32_t(0x8349BB60);
	constexpr int32_t n_sub_832A6508_address = int32_t(0x832A6508);
	if (!UseLiftedCode(143, 0x83261160)) { __imp__sub_83261160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261160);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB60, (int64_t)str_TXT_820D0000_B_ + 31592);
	return RegisterAtExit(ctx, base, n_sub_832A6508_address);
}
PROMOTED_ENTRY(143, sub_83261160, 0x83261160) { ctx.r3.u64 = InitStringGlobal_8349BB60(ctx, base); }

uint64_t InitStringGlobal_8349BB64(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB64 = int32_t(0x8349BB64);
	constexpr int32_t n_sub_832A6518_address = int32_t(0x832A6518);
	if (!UseLiftedCode(143, 0x832611A0)) { __imp__sub_832611A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832611A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB64, (int64_t)str_TXT_820D0000_B_ + 31604);
	return RegisterAtExit(ctx, base, n_sub_832A6518_address);
}
PROMOTED_ENTRY(143, sub_832611A0, 0x832611A0) { ctx.r3.u64 = InitStringGlobal_8349BB64(ctx, base); }

uint64_t InitStringGlobal_8349BB68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB68 = int32_t(0x8349BB68);
	constexpr int32_t n_sub_832A6528_address = int32_t(0x832A6528);
	if (!UseLiftedCode(143, 0x832611E0)) { __imp__sub_832611E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832611E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB68, (int64_t)str_TXT_820D0000_B_ + 31616);
	return RegisterAtExit(ctx, base, n_sub_832A6528_address);
}
PROMOTED_ENTRY(143, sub_832611E0, 0x832611E0) { ctx.r3.u64 = InitStringGlobal_8349BB68(ctx, base); }

uint64_t InitStringGlobal_8349BB6C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB6C = int32_t(0x8349BB6C);
	constexpr int32_t n_sub_832A6538_address = int32_t(0x832A6538);
	if (!UseLiftedCode(143, 0x83261220)) { __imp__sub_83261220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261220);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB6C, (int64_t)str_TXT_820D0000_B_ + 31636);
	return RegisterAtExit(ctx, base, n_sub_832A6538_address);
}
PROMOTED_ENTRY(143, sub_83261220, 0x83261220) { ctx.r3.u64 = InitStringGlobal_8349BB6C(ctx, base); }

uint64_t InitStringGlobal_8349BB70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB70 = int32_t(0x8349BB70);
	constexpr int32_t n_sub_832A6548_address = int32_t(0x832A6548);
	if (!UseLiftedCode(143, 0x83261260)) { __imp__sub_83261260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261260);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB70, (int64_t)str_TXT_820D0000_B_ + 31644);
	return RegisterAtExit(ctx, base, n_sub_832A6548_address);
}
PROMOTED_ENTRY(143, sub_83261260, 0x83261260) { ctx.r3.u64 = InitStringGlobal_8349BB70(ctx, base); }

uint64_t InitStringGlobal_8349BB74(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB74 = int32_t(0x8349BB74);
	constexpr int32_t n_sub_832A6558_address = int32_t(0x832A6558);
	if (!UseLiftedCode(143, 0x832612A0)) { __imp__sub_832612A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832612A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB74, (int64_t)str_TXT_820D0000_B_ + 31668);
	return RegisterAtExit(ctx, base, n_sub_832A6558_address);
}
PROMOTED_ENTRY(143, sub_832612A0, 0x832612A0) { ctx.r3.u64 = InitStringGlobal_8349BB74(ctx, base); }

uint64_t InitStringGlobal_8349BB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB78 = int32_t(0x8349BB78);
	constexpr int32_t n_sub_832A6568_address = int32_t(0x832A6568);
	if (!UseLiftedCode(143, 0x832612E0)) { __imp__sub_832612E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832612E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB78, (int64_t)str_TXT_820D0000_B_ + 31688);
	return RegisterAtExit(ctx, base, n_sub_832A6568_address);
}
PROMOTED_ENTRY(143, sub_832612E0, 0x832612E0) { ctx.r3.u64 = InitStringGlobal_8349BB78(ctx, base); }

uint64_t InitStringGlobal_8349BB7C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB7C = int32_t(0x8349BB7C);
	constexpr int32_t n_sub_832A6578_address = int32_t(0x832A6578);
	if (!UseLiftedCode(143, 0x83261320)) { __imp__sub_83261320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261320);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB7C, (int64_t)str_TXT_820D0000_B_ + 31708);
	return RegisterAtExit(ctx, base, n_sub_832A6578_address);
}
PROMOTED_ENTRY(143, sub_83261320, 0x83261320) { ctx.r3.u64 = InitStringGlobal_8349BB7C(ctx, base); }

uint64_t InitStringGlobal_8349BB80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB80 = int32_t(0x8349BB80);
	constexpr int32_t n_sub_832A6588_address = int32_t(0x832A6588);
	if (!UseLiftedCode(143, 0x83261360)) { __imp__sub_83261360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261360);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB80, (int64_t)str_TXT_820D0000_B_ + 31728);
	return RegisterAtExit(ctx, base, n_sub_832A6588_address);
}
PROMOTED_ENTRY(143, sub_83261360, 0x83261360) { ctx.r3.u64 = InitStringGlobal_8349BB80(ctx, base); }

uint64_t InitStringGlobal_8349BB84(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB84 = int32_t(0x8349BB84);
	constexpr int32_t n_sub_832A6598_address = int32_t(0x832A6598);
	if (!UseLiftedCode(143, 0x832613A0)) { __imp__sub_832613A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832613A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB84, (int64_t)str_TXT_820D0000_B_ + 31748);
	return RegisterAtExit(ctx, base, n_sub_832A6598_address);
}
PROMOTED_ENTRY(143, sub_832613A0, 0x832613A0) { ctx.r3.u64 = InitStringGlobal_8349BB84(ctx, base); }

uint64_t InitStringGlobal_8349BB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB88 = int32_t(0x8349BB88);
	constexpr int32_t n_sub_832A65A8_address = int32_t(0x832A65A8);
	if (!UseLiftedCode(143, 0x832613E0)) { __imp__sub_832613E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832613E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB88, (int64_t)str_TXT_820D0000_B_ + 31780);
	return RegisterAtExit(ctx, base, n_sub_832A65A8_address);
}
PROMOTED_ENTRY(143, sub_832613E0, 0x832613E0) { ctx.r3.u64 = InitStringGlobal_8349BB88(ctx, base); }

uint64_t InitStringGlobal_8349BB8C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB8C = int32_t(0x8349BB8C);
	constexpr int32_t n_sub_832A65B8_address = int32_t(0x832A65B8);
	if (!UseLiftedCode(143, 0x83261420)) { __imp__sub_83261420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261420);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB8C, (int64_t)str_TXT_820D0000_B_ + 31808);
	return RegisterAtExit(ctx, base, n_sub_832A65B8_address);
}
PROMOTED_ENTRY(143, sub_83261420, 0x83261420) { ctx.r3.u64 = InitStringGlobal_8349BB8C(ctx, base); }

uint64_t InitStringGlobal_8349BB90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB90 = int32_t(0x8349BB90);
	constexpr int32_t n_sub_832A65C8_address = int32_t(0x832A65C8);
	if (!UseLiftedCode(143, 0x83261460)) { __imp__sub_83261460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261460);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB90, (int64_t)str_TXT_820D0000_B_ + 31836);
	return RegisterAtExit(ctx, base, n_sub_832A65C8_address);
}
PROMOTED_ENTRY(143, sub_83261460, 0x83261460) { ctx.r3.u64 = InitStringGlobal_8349BB90(ctx, base); }

uint64_t InitStringGlobal_8349BB94(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB94 = int32_t(0x8349BB94);
	constexpr int32_t n_sub_832A65D8_address = int32_t(0x832A65D8);
	if (!UseLiftedCode(143, 0x832614A0)) { __imp__sub_832614A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832614A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB94, (int64_t)str_TXT_820D0000_B_ + 31864);
	return RegisterAtExit(ctx, base, n_sub_832A65D8_address);
}
PROMOTED_ENTRY(143, sub_832614A0, 0x832614A0) { ctx.r3.u64 = InitStringGlobal_8349BB94(ctx, base); }

uint64_t InitStringGlobal_8349BB98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB98 = int32_t(0x8349BB98);
	constexpr int32_t n_sub_832A65E8_address = int32_t(0x832A65E8);
	if (!UseLiftedCode(143, 0x832614E0)) { __imp__sub_832614E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832614E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB98, (int64_t)str_TXT_820D0000_B_ + 31896);
	return RegisterAtExit(ctx, base, n_sub_832A65E8_address);
}
PROMOTED_ENTRY(143, sub_832614E0, 0x832614E0) { ctx.r3.u64 = InitStringGlobal_8349BB98(ctx, base); }

uint64_t InitStringGlobal_8349BB9C(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BB9C = int32_t(0x8349BB9C);
	constexpr int32_t n_sub_832A65F8_address = int32_t(0x832A65F8);
	if (!UseLiftedCode(143, 0x83261520)) { __imp__sub_83261520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261520);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB9C, (int64_t)str_TXT_820D0000_B_ + 31920);
	return RegisterAtExit(ctx, base, n_sub_832A65F8_address);
}
PROMOTED_ENTRY(143, sub_83261520, 0x83261520) { ctx.r3.u64 = InitStringGlobal_8349BB9C(ctx, base); }

uint64_t InitStringGlobal_8349BBA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBA0 = int32_t(0x8349BBA0);
	constexpr int32_t n_sub_832A6608_address = int32_t(0x832A6608);
	if (!UseLiftedCode(143, 0x83261560)) { __imp__sub_83261560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261560);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA0, (int64_t)str_TXT_820D0000_B_ + 31940);
	return RegisterAtExit(ctx, base, n_sub_832A6608_address);
}
PROMOTED_ENTRY(143, sub_83261560, 0x83261560) { ctx.r3.u64 = InitStringGlobal_8349BBA0(ctx, base); }

uint64_t InitStringGlobal_8349BBA4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBA4 = int32_t(0x8349BBA4);
	constexpr int32_t n_sub_832A6618_address = int32_t(0x832A6618);
	if (!UseLiftedCode(143, 0x832615A0)) { __imp__sub_832615A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832615A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA4, (int64_t)str_TXT_820D0000_B_ + 31972);
	return RegisterAtExit(ctx, base, n_sub_832A6618_address);
}
PROMOTED_ENTRY(143, sub_832615A0, 0x832615A0) { ctx.r3.u64 = InitStringGlobal_8349BBA4(ctx, base); }

uint64_t InitStringGlobal_8349BBA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBA8 = int32_t(0x8349BBA8);
	constexpr int32_t n_sub_832A6628_address = int32_t(0x832A6628);
	if (!UseLiftedCode(144, 0x832615E0)) { __imp__sub_832615E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832615E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA8, (int64_t)str_TXT_820D0000_B_ + 32000);
	return RegisterAtExit(ctx, base, n_sub_832A6628_address);
}
PROMOTED_ENTRY(144, sub_832615E0, 0x832615E0) { ctx.r3.u64 = InitStringGlobal_8349BBA8(ctx, base); }

uint64_t InitStringGlobal_8349BBAC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBAC = int32_t(0x8349BBAC);
	constexpr int32_t n_sub_832A6638_address = int32_t(0x832A6638);
	if (!UseLiftedCode(144, 0x83261620)) { __imp__sub_83261620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261620);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBAC, (int64_t)str_TXT_820D0000_B_ + 32028);
	return RegisterAtExit(ctx, base, n_sub_832A6638_address);
}
PROMOTED_ENTRY(144, sub_83261620, 0x83261620) { ctx.r3.u64 = InitStringGlobal_8349BBAC(ctx, base); }

uint64_t InitStringGlobal_8349BBB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBB0 = int32_t(0x8349BBB0);
	constexpr int32_t n_sub_832A6648_address = int32_t(0x832A6648);
	if (!UseLiftedCode(144, 0x83261660)) { __imp__sub_83261660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261660);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB0, (int64_t)str_TXT_820D0000_B_ + 32060);
	return RegisterAtExit(ctx, base, n_sub_832A6648_address);
}
PROMOTED_ENTRY(144, sub_83261660, 0x83261660) { ctx.r3.u64 = InitStringGlobal_8349BBB0(ctx, base); }

uint64_t InitStringGlobal_8349BBB4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBB4 = int32_t(0x8349BBB4);
	constexpr int32_t n_sub_832A6658_address = int32_t(0x832A6658);
	if (!UseLiftedCode(144, 0x832616A0)) { __imp__sub_832616A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832616A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB4, (int64_t)str_TXT_820D0000_B_ + 31644);
	return RegisterAtExit(ctx, base, n_sub_832A6658_address);
}
PROMOTED_ENTRY(144, sub_832616A0, 0x832616A0) { ctx.r3.u64 = InitStringGlobal_8349BBB4(ctx, base); }

uint64_t InitStringGlobal_8349BBB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBB8 = int32_t(0x8349BBB8);
	constexpr int32_t n_sub_832A6668_address = int32_t(0x832A6668);
	if (!UseLiftedCode(144, 0x832616E0)) { __imp__sub_832616E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832616E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB8, (int64_t)str_TXT_820D0000_B_ + 32096);
	return RegisterAtExit(ctx, base, n_sub_832A6668_address);
}
PROMOTED_ENTRY(144, sub_832616E0, 0x832616E0) { ctx.r3.u64 = InitStringGlobal_8349BBB8(ctx, base); }

uint64_t InitStringGlobal_8349BBBC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBBC = int32_t(0x8349BBBC);
	constexpr int32_t n_sub_832A6678_address = int32_t(0x832A6678);
	if (!UseLiftedCode(144, 0x83261720)) { __imp__sub_83261720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261720);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBBC, (int64_t)str_TXT_820D0000_B_ + 32120);
	return RegisterAtExit(ctx, base, n_sub_832A6678_address);
}
PROMOTED_ENTRY(144, sub_83261720, 0x83261720) { ctx.r3.u64 = InitStringGlobal_8349BBBC(ctx, base); }

uint64_t InitStringGlobal_8349BBC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBC0 = int32_t(0x8349BBC0);
	constexpr int32_t n_sub_832A6688_address = int32_t(0x832A6688);
	if (!UseLiftedCode(144, 0x83261760)) { __imp__sub_83261760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261760);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC0, (int64_t)str_TXT_820D0000_B_ + 32144);
	return RegisterAtExit(ctx, base, n_sub_832A6688_address);
}
PROMOTED_ENTRY(144, sub_83261760, 0x83261760) { ctx.r3.u64 = InitStringGlobal_8349BBC0(ctx, base); }

uint64_t InitStringGlobal_8349BBC4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBC4 = int32_t(0x8349BBC4);
	constexpr int32_t n_sub_832A6698_address = int32_t(0x832A6698);
	if (!UseLiftedCode(144, 0x832617A0)) { __imp__sub_832617A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832617A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC4, (int64_t)str_TXT_820D0000_B_ + 32168);
	return RegisterAtExit(ctx, base, n_sub_832A6698_address);
}
PROMOTED_ENTRY(144, sub_832617A0, 0x832617A0) { ctx.r3.u64 = InitStringGlobal_8349BBC4(ctx, base); }

uint64_t InitStringGlobal_8349BBC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBC8 = int32_t(0x8349BBC8);
	constexpr int32_t n_sub_832A66A8_address = int32_t(0x832A66A8);
	if (!UseLiftedCode(144, 0x832617E0)) { __imp__sub_832617E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832617E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC8, (int64_t)str_TXT_820D0000_B_ + 32192);
	return RegisterAtExit(ctx, base, n_sub_832A66A8_address);
}
PROMOTED_ENTRY(144, sub_832617E0, 0x832617E0) { ctx.r3.u64 = InitStringGlobal_8349BBC8(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBCC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBCC = int32_t(0x8349BBCC);
	constexpr int32_t n_sub_832A66B8_address = int32_t(0x832A66B8);
	if (!UseLiftedCode(144, 0x83261820)) { __imp__sub_83261820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261820);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBCC, (int64_t)str_TXT_820D0000_B_ + 32216);
	return RegisterAtExit(ctx, base, n_sub_832A66B8_address);
}
PROMOTED_ENTRY(144, sub_83261820, 0x83261820) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBCC(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBD0 = int32_t(0x8349BBD0);
	constexpr int32_t n_sub_832A66C8_address = int32_t(0x832A66C8);
	if (!UseLiftedCode(144, 0x83261860)) { __imp__sub_83261860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261860);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD0, (int64_t)str_TXT_820D0000_B_ + 32236);
	return RegisterAtExit(ctx, base, n_sub_832A66C8_address);
}
PROMOTED_ENTRY(144, sub_83261860, 0x83261860) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBD0(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBD4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBD4 = int32_t(0x8349BBD4);
	constexpr int32_t n_sub_832A66D8_address = int32_t(0x832A66D8);
	if (!UseLiftedCode(144, 0x832618A0)) { __imp__sub_832618A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832618A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD4, (int64_t)str_TXT_820D0000_B_ + 32256);
	return RegisterAtExit(ctx, base, n_sub_832A66D8_address);
}
PROMOTED_ENTRY(144, sub_832618A0, 0x832618A0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBD4(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBD8 = int32_t(0x8349BBD8);
	constexpr int32_t n_sub_832A66E8_address = int32_t(0x832A66E8);
	if (!UseLiftedCode(144, 0x832618E0)) { __imp__sub_832618E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832618E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD8, (int64_t)str_TXT_820D0000_B_ + 32276);
	return RegisterAtExit(ctx, base, n_sub_832A66E8_address);
}
PROMOTED_ENTRY(144, sub_832618E0, 0x832618E0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBD8(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBDC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBDC = int32_t(0x8349BBDC);
	constexpr int32_t n_sub_832A66F8_address = int32_t(0x832A66F8);
	if (!UseLiftedCode(144, 0x83261920)) { __imp__sub_83261920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261920);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBDC, (int64_t)str_TXT_820D0000_B_ + 32296);
	return RegisterAtExit(ctx, base, n_sub_832A66F8_address);
}
PROMOTED_ENTRY(144, sub_83261920, 0x83261920) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBDC(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBE0 = int32_t(0x8349BBE0);
	constexpr int32_t n_sub_832A6708_address = int32_t(0x832A6708);
	if (!UseLiftedCode(144, 0x83261960)) { __imp__sub_83261960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261960);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE0, (int64_t)str_TXT_820D0000_B_ + 32316);
	return RegisterAtExit(ctx, base, n_sub_832A6708_address);
}
PROMOTED_ENTRY(144, sub_83261960, 0x83261960) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBE0(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBE4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBE4 = int32_t(0x8349BBE4);
	constexpr int32_t n_sub_832A6718_address = int32_t(0x832A6718);
	if (!UseLiftedCode(144, 0x832619A0)) { __imp__sub_832619A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832619A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE4, (int64_t)str_TXT_820D0000_B_ + 32336);
	return RegisterAtExit(ctx, base, n_sub_832A6718_address);
}
PROMOTED_ENTRY(144, sub_832619A0, 0x832619A0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBE4(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBE8 = int32_t(0x8349BBE8);
	constexpr int32_t n_sub_832A6728_address = int32_t(0x832A6728);
	if (!UseLiftedCode(144, 0x832619E0)) { __imp__sub_832619E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832619E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE8, (int64_t)str_TXT_820D0000_B_ + 32356);
	return RegisterAtExit(ctx, base, n_sub_832A6728_address);
}
PROMOTED_ENTRY(144, sub_832619E0, 0x832619E0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBE8(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBEC(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBEC = int32_t(0x8349BBEC);
	constexpr int32_t n_sub_832A6738_address = int32_t(0x832A6738);
	if (!UseLiftedCode(144, 0x83261A20)) { __imp__sub_83261A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261A20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBEC, (int64_t)str_TXT_820D0000_B_ + 32388);
	return RegisterAtExit(ctx, base, n_sub_832A6738_address);
}
PROMOTED_ENTRY(144, sub_83261A20, 0x83261A20) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBEC(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBF0 = int32_t(0x8349BBF0);
	constexpr int32_t n_sub_832A6748_address = int32_t(0x832A6748);
	if (!UseLiftedCode(144, 0x83261A60)) { __imp__sub_83261A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261A60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF0, (int64_t)str_TXT_820D0000_B_ + 32412);
	return RegisterAtExit(ctx, base, n_sub_832A6748_address);
}
PROMOTED_ENTRY(144, sub_83261A60, 0x83261A60) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBF0(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBF4(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBF4 = int32_t(0x8349BBF4);
	constexpr int32_t n_sub_832A6758_address = int32_t(0x832A6758);
	if (!UseLiftedCode(144, 0x83261AA0)) { __imp__sub_83261AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF4, (int64_t)str_TXT_820D0000_B_ + 32432);
	return RegisterAtExit(ctx, base, n_sub_832A6758_address);
}
PROMOTED_ENTRY(144, sub_83261AA0, 0x83261AA0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBF4(ctx, base); }

uint64_t InitializeGlobalCCharString_8349BBF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_8349BBF8 = int32_t(0x8349BBF8);
	constexpr int32_t n_sub_832A6768_address = int32_t(0x832A6768);
	if (!UseLiftedCode(144, 0x83261AE0)) { __imp__sub_83261AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF8, (int64_t)str_TXT_820D0000_B_ + 32464);
	return RegisterAtExit(ctx, base, n_sub_832A6768_address);
}
PROMOTED_ENTRY(144, sub_83261AE0, 0x83261AE0) { ctx.r3.u64 = InitializeGlobalCCharString_8349BBF8(ctx, base); }

uint64_t HashName_TXT_820C7C60_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C7C60_B_ = int32_t(0x820C7C60);
	constexpr uint32_t g_HashOf_TXT_820C7C60_B_ = 0x8349BC08u;
	if (!UseLiftedCode(144, 0x83261BB0)) { __imp__sub_83261BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820C7C60_B_);
	STORE32(g_HashOf_TXT_820C7C60_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83261BB0, 0x83261BB0) { ctx.r3.u64 = HashName_TXT_820C7C60_B_(ctx, base); }

uint64_t HashName_TXT_820D7FD4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D7FD4_B_ = int32_t(0x820D7FD4);
	constexpr uint32_t g_HashOf_TXT_820D7FD4_B_ = 0x8349BC0Cu;
	if (!UseLiftedCode(144, 0x83261BE8)) { __imp__sub_83261BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D7FD4_B_);
	STORE32(g_HashOf_TXT_820D7FD4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83261BE8, 0x83261BE8) { ctx.r3.u64 = HashName_TXT_820D7FD4_B_(ctx, base); }

uint64_t HashName_TXT_820D7FE0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D7FE0_B_ = int32_t(0x820D7FE0);
	constexpr uint32_t g_HashOf_TXT_820D7FE0_B_ = 0x8349BC10u;
	if (!UseLiftedCode(144, 0x83261C20)) { __imp__sub_83261C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261C20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D7FE0_B_);
	STORE32(g_HashOf_TXT_820D7FE0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83261C20, 0x83261C20) { ctx.r3.u64 = HashName_TXT_820D7FE0_B_(ctx, base); }

uint64_t HashName_TXT_820D7FF0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D7FF0_B_ = int32_t(0x820D7FF0);
	constexpr uint32_t g_HashOf_TXT_820D7FF0_B_ = 0x8349BC14u;
	if (!UseLiftedCode(144, 0x83261C58)) { __imp__sub_83261C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261C58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D7FF0_B_);
	STORE32(g_HashOf_TXT_820D7FF0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83261C58, 0x83261C58) { ctx.r3.u64 = HashName_TXT_820D7FF0_B_(ctx, base); }

uint64_t InitializeReactionNameString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC18_G_ = int32_t(0x8349BC18);
	constexpr int32_t str_TXT_820D1950_B_ = int32_t(0x820D1950);
	constexpr int32_t Destroy_TXT_8349BC18_G__address = int32_t(0x832A6788);
	if (!UseLiftedCode(144, 0x83261C90)) { __imp__sub_83261C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261C90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349BC18_G_, str_TXT_820D1950_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC18_G__address);
}
PROMOTED_ENTRY(144, sub_83261C90, 0x83261C90) { ctx.r3.u64 = InitializeReactionNameString(ctx, base); }

uint64_t HashName_TXT_820D7EEC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D7EEC_B_ = int32_t(0x820D7EEC);
	constexpr uint32_t g_HashOf_TXT_820D7EEC_B_ = 0x8349BC1Cu;
	if (!UseLiftedCode(144, 0x83261CD0)) { __imp__sub_83261CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D7EEC_B_);
	STORE32(g_HashOf_TXT_820D7EEC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83261CD0, 0x83261CD0) { ctx.r3.u64 = HashName_TXT_820D7EEC_B_(ctx, base); }

uint64_t Construct_TXT_8349BC20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC20_G_ = int32_t(0x8349BC20);
	constexpr int32_t str_TXT_820C3EFC_B_ = int32_t(0x820C3EFC);
	constexpr int32_t Destroy_TXT_8349BC20_G__address = int32_t(0x832A6798);
	if (!UseLiftedCode(144, 0x83261D08)) { __imp__sub_83261D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC20_G_, str_TXT_820C3EFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC20_G__address);
}
PROMOTED_ENTRY(144, sub_83261D08, 0x83261D08) { ctx.r3.u64 = Construct_TXT_8349BC20_G_(ctx, base); }

// sub_83261D48  [64 bytes]
uint64_t InitRomanticInterestThresholdString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC24_G_ = int32_t(0x8349BC24);
	constexpr int32_t str_TXT_820D8000_B_ = int32_t(0x820D8000);
	constexpr int32_t Destroy_TXT_8349BC24_G__address = int32_t(0x832A67A8);
	if (!UseLiftedCode(144, 0x83261D48)) { __imp__sub_83261D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D48);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (RegisterAtExit is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC24_G_, str_TXT_820D8000_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349BC24_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261D48, 0x83261D48) { ctx.r3.u64 = InitRomanticInterestThresholdString(ctx, base); }

uint64_t Construct_TXT_8349BC28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC28_G_ = int32_t(0x8349BC28);
	constexpr int32_t str_TXT_820D801C_B_ = int32_t(0x820D801C);
	constexpr int32_t Destroy_TXT_8349BC28_G__address = int32_t(0x832A67B8);
	if (!UseLiftedCode(144, 0x83261D88)) { __imp__sub_83261D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC28_G_, str_TXT_820D801C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC28_G__address);
}
PROMOTED_ENTRY(144, sub_83261D88, 0x83261D88) { ctx.r3.u64 = Construct_TXT_8349BC28_G_(ctx, base); }

uint64_t Construct_TXT_8349BC2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC2C_G_ = int32_t(0x8349BC2C);
	constexpr int32_t str_TXT_820D803C_B_ = int32_t(0x820D803C);
	constexpr int32_t Destroy_TXT_8349BC2C_G__address = int32_t(0x832A67C8);
	if (!UseLiftedCode(144, 0x83261DC8)) { __imp__sub_83261DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC2C_G_, str_TXT_820D803C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC2C_G__address);
}
PROMOTED_ENTRY(144, sub_83261DC8, 0x83261DC8) { ctx.r3.u64 = Construct_TXT_8349BC2C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC30_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC30_G_ = int32_t(0x8349BC30);
	constexpr int32_t str_TXT_820D804C_B_ = int32_t(0x820D804C);
	constexpr int32_t Destroy_TXT_8349BC30_G__address = int32_t(0x832A67D8);
	if (!UseLiftedCode(144, 0x83261E08)) { __imp__sub_83261E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC30_G_, str_TXT_820D804C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC30_G__address);
}
PROMOTED_ENTRY(144, sub_83261E08, 0x83261E08) { ctx.r3.u64 = Construct_TXT_8349BC30_G_(ctx, base); }

uint64_t Construct_TXT_8349BC34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC34_G_ = int32_t(0x8349BC34);
	constexpr int32_t str_TXT_820D805C_B_ = int32_t(0x820D805C);
	constexpr int32_t Destroy_TXT_8349BC34_G__address = int32_t(0x832A67E8);
	if (!UseLiftedCode(144, 0x83261E48)) { __imp__sub_83261E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC34_G_, str_TXT_820D805C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC34_G__address);
}
PROMOTED_ENTRY(144, sub_83261E48, 0x83261E48) { ctx.r3.u64 = Construct_TXT_8349BC34_G_(ctx, base); }

uint64_t Construct_TXT_8349BC38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC38_G_ = int32_t(0x8349BC38);
	constexpr int32_t str_TXT_820D8070_B_ = int32_t(0x820D8070);
	constexpr int32_t Destroy_TXT_8349BC38_G__address = int32_t(0x832A67F8);
	if (!UseLiftedCode(144, 0x83261E88)) { __imp__sub_83261E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC38_G_, str_TXT_820D8070_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC38_G__address);
}
PROMOTED_ENTRY(144, sub_83261E88, 0x83261E88) { ctx.r3.u64 = Construct_TXT_8349BC38_G_(ctx, base); }

uint64_t Construct_TXT_8349BC3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC3C_G_ = int32_t(0x8349BC3C);
	constexpr int32_t str_TXT_820D8080_B_ = int32_t(0x820D8080);
	constexpr int32_t Destroy_TXT_8349BC3C_G__address = int32_t(0x832A6808);
	if (!UseLiftedCode(144, 0x83261EC8)) { __imp__sub_83261EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC3C_G_, str_TXT_820D8080_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC3C_G__address);
}
PROMOTED_ENTRY(144, sub_83261EC8, 0x83261EC8) { ctx.r3.u64 = Construct_TXT_8349BC3C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC40_G_ = int32_t(0x8349BC40);
	constexpr int32_t str_TXT_820D8098_B_ = int32_t(0x820D8098);
	constexpr int32_t Destroy_TXT_8349BC40_G__address = int32_t(0x832A6818);
	if (!UseLiftedCode(144, 0x83261F08)) { __imp__sub_83261F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC40_G_, str_TXT_820D8098_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC40_G__address);
}
PROMOTED_ENTRY(144, sub_83261F08, 0x83261F08) { ctx.r3.u64 = Construct_TXT_8349BC40_G_(ctx, base); }

uint64_t Construct_TXT_8349BC44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC44_G_ = int32_t(0x8349BC44);
	constexpr int32_t str_TXT_820D80AC_B_ = int32_t(0x820D80AC);
	constexpr int32_t Destroy_TXT_8349BC44_G__address = int32_t(0x832A6828);
	if (!UseLiftedCode(144, 0x83261F48)) { __imp__sub_83261F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC44_G_, str_TXT_820D80AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC44_G__address);
}
PROMOTED_ENTRY(144, sub_83261F48, 0x83261F48) { ctx.r3.u64 = Construct_TXT_8349BC44_G_(ctx, base); }

uint64_t Construct_TXT_8349BC48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC48_G_ = int32_t(0x8349BC48);
	constexpr int32_t str_TXT_820D80C8_B_ = int32_t(0x820D80C8);
	constexpr int32_t Destroy_TXT_8349BC48_G__address = int32_t(0x832A6838);
	if (!UseLiftedCode(144, 0x83261F88)) { __imp__sub_83261F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC48_G_, str_TXT_820D80C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC48_G__address);
}
PROMOTED_ENTRY(144, sub_83261F88, 0x83261F88) { ctx.r3.u64 = Construct_TXT_8349BC48_G_(ctx, base); }

uint64_t Construct_TXT_8349BC4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC4C_G_ = int32_t(0x8349BC4C);
	constexpr int32_t str_TXT_820D80DC_B_ = int32_t(0x820D80DC);
	constexpr int32_t Destroy_TXT_8349BC4C_G__address = int32_t(0x832A6848);
	if (!UseLiftedCode(144, 0x83261FC8)) { __imp__sub_83261FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC4C_G_, str_TXT_820D80DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC4C_G__address);
}
PROMOTED_ENTRY(144, sub_83261FC8, 0x83261FC8) { ctx.r3.u64 = Construct_TXT_8349BC4C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC50_G_ = int32_t(0x8349BC50);
	constexpr int32_t str_TXT_820D80F0_B_ = int32_t(0x820D80F0);
	constexpr int32_t Destroy_TXT_8349BC50_G__address = int32_t(0x832A6858);
	if (!UseLiftedCode(144, 0x83262008)) { __imp__sub_83262008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC50_G_, str_TXT_820D80F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC50_G__address);
}
PROMOTED_ENTRY(144, sub_83262008, 0x83262008) { ctx.r3.u64 = Construct_TXT_8349BC50_G_(ctx, base); }

uint64_t Construct_TXT_8349BC54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC54_G_ = int32_t(0x8349BC54);
	constexpr int32_t str_TXT_820D8104_B_ = int32_t(0x820D8104);
	constexpr int32_t Destroy_TXT_8349BC54_G__address = int32_t(0x832A6868);
	if (!UseLiftedCode(144, 0x83262048)) { __imp__sub_83262048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC54_G_, str_TXT_820D8104_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC54_G__address);
}
PROMOTED_ENTRY(144, sub_83262048, 0x83262048) { ctx.r3.u64 = Construct_TXT_8349BC54_G_(ctx, base); }

uint64_t Construct_TXT_8349BC58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC58_G_ = int32_t(0x8349BC58);
	constexpr int32_t str_TXT_820D8124_B_ = int32_t(0x820D8124);
	constexpr int32_t Destroy_TXT_8349BC58_G__address = int32_t(0x832A6878);
	if (!UseLiftedCode(144, 0x83262088)) { __imp__sub_83262088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC58_G_, str_TXT_820D8124_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC58_G__address);
}
PROMOTED_ENTRY(144, sub_83262088, 0x83262088) { ctx.r3.u64 = Construct_TXT_8349BC58_G_(ctx, base); }

uint64_t Construct_TXT_8349BC5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC5C_G_ = int32_t(0x8349BC5C);
	constexpr int32_t str_TXT_820D8140_B_ = int32_t(0x820D8140);
	constexpr int32_t Destroy_TXT_8349BC5C_G__address = int32_t(0x832A6888);
	if (!UseLiftedCode(144, 0x832620C8)) { __imp__sub_832620C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832620C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC5C_G_, str_TXT_820D8140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC5C_G__address);
}
PROMOTED_ENTRY(144, sub_832620C8, 0x832620C8) { ctx.r3.u64 = Construct_TXT_8349BC5C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC60_G_ = int32_t(0x8349BC60);
	constexpr int32_t str_TXT_820D815C_B_ = int32_t(0x820D815C);
	constexpr int32_t Destroy_TXT_8349BC60_G__address = int32_t(0x832A6898);
	if (!UseLiftedCode(144, 0x83262108)) { __imp__sub_83262108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC60_G_, str_TXT_820D815C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC60_G__address);
}
PROMOTED_ENTRY(144, sub_83262108, 0x83262108) { ctx.r3.u64 = Construct_TXT_8349BC60_G_(ctx, base); }

uint64_t Construct_TXT_8349BC64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC64_G_ = int32_t(0x8349BC64);
	constexpr int32_t str_TXT_820D8170_B_ = int32_t(0x820D8170);
	constexpr int32_t Destroy_TXT_8349BC64_G__address = int32_t(0x832A68A8);
	if (!UseLiftedCode(144, 0x83262148)) { __imp__sub_83262148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC64_G_, str_TXT_820D8170_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC64_G__address);
}
PROMOTED_ENTRY(144, sub_83262148, 0x83262148) { ctx.r3.u64 = Construct_TXT_8349BC64_G_(ctx, base); }

uint64_t Construct_TXT_8349BC68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC68_G_ = int32_t(0x8349BC68);
	constexpr int32_t str_TXT_820D818C_B_ = int32_t(0x820D818C);
	constexpr int32_t Destroy_TXT_8349BC68_G__address = int32_t(0x832A68B8);
	if (!UseLiftedCode(144, 0x83262188)) { __imp__sub_83262188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC68_G_, str_TXT_820D818C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC68_G__address);
}
PROMOTED_ENTRY(144, sub_83262188, 0x83262188) { ctx.r3.u64 = Construct_TXT_8349BC68_G_(ctx, base); }

uint64_t Construct_TXT_8349BC6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC6C_G_ = int32_t(0x8349BC6C);
	constexpr int32_t str_TXT_820D81B0_B_ = int32_t(0x820D81B0);
	constexpr int32_t Destroy_TXT_8349BC6C_G__address = int32_t(0x832A68C8);
	if (!UseLiftedCode(144, 0x832621C8)) { __imp__sub_832621C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832621C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC6C_G_, str_TXT_820D81B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC6C_G__address);
}
PROMOTED_ENTRY(144, sub_832621C8, 0x832621C8) { ctx.r3.u64 = Construct_TXT_8349BC6C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC70_G_ = int32_t(0x8349BC70);
	constexpr int32_t str_TXT_820D81C4_B_ = int32_t(0x820D81C4);
	constexpr int32_t Destroy_TXT_8349BC70_G__address = int32_t(0x832A68D8);
	if (!UseLiftedCode(144, 0x83262208)) { __imp__sub_83262208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC70_G_, str_TXT_820D81C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC70_G__address);
}
PROMOTED_ENTRY(144, sub_83262208, 0x83262208) { ctx.r3.u64 = Construct_TXT_8349BC70_G_(ctx, base); }

uint64_t Construct_TXT_8349BC74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC74_G_ = int32_t(0x8349BC74);
	constexpr int32_t str_TXT_820D81E0_B_ = int32_t(0x820D81E0);
	constexpr int32_t Destroy_TXT_8349BC74_G__address = int32_t(0x832A68E8);
	if (!UseLiftedCode(144, 0x83262248)) { __imp__sub_83262248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC74_G_, str_TXT_820D81E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC74_G__address);
}
PROMOTED_ENTRY(144, sub_83262248, 0x83262248) { ctx.r3.u64 = Construct_TXT_8349BC74_G_(ctx, base); }

uint64_t Construct_TXT_8349BC78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC78_G_ = int32_t(0x8349BC78);
	constexpr int32_t str_TXT_820D81F0_B_ = int32_t(0x820D81F0);
	constexpr int32_t Destroy_TXT_8349BC78_G__address = int32_t(0x832A68F8);
	if (!UseLiftedCode(144, 0x83262288)) { __imp__sub_83262288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC78_G_, str_TXT_820D81F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC78_G__address);
}
PROMOTED_ENTRY(144, sub_83262288, 0x83262288) { ctx.r3.u64 = Construct_TXT_8349BC78_G_(ctx, base); }

uint64_t Construct_TXT_8349BC7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC7C_G_ = int32_t(0x8349BC7C);
	constexpr int32_t str_TXT_820D81FC_B_ = int32_t(0x820D81FC);
	constexpr int32_t Destroy_TXT_8349BC7C_G__address = int32_t(0x832A6908);
	if (!UseLiftedCode(144, 0x832622C8)) { __imp__sub_832622C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832622C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC7C_G_, str_TXT_820D81FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC7C_G__address);
}
PROMOTED_ENTRY(144, sub_832622C8, 0x832622C8) { ctx.r3.u64 = Construct_TXT_8349BC7C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC80_G_ = int32_t(0x8349BC80);
	constexpr int32_t str_TXT_820D8214_B_ = int32_t(0x820D8214);
	constexpr int32_t Destroy_TXT_8349BC80_G__address = int32_t(0x832A6918);
	if (!UseLiftedCode(144, 0x83262308)) { __imp__sub_83262308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC80_G_, str_TXT_820D8214_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC80_G__address);
}
PROMOTED_ENTRY(144, sub_83262308, 0x83262308) { ctx.r3.u64 = Construct_TXT_8349BC80_G_(ctx, base); }

uint64_t Construct_TXT_8349BC84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC84_G_ = int32_t(0x8349BC84);
	constexpr int32_t str_TXT_820D8230_B_ = int32_t(0x820D8230);
	constexpr int32_t Destroy_TXT_8349BC84_G__address = int32_t(0x832A6928);
	if (!UseLiftedCode(144, 0x83262348)) { __imp__sub_83262348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC84_G_, str_TXT_820D8230_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC84_G__address);
}
PROMOTED_ENTRY(144, sub_83262348, 0x83262348) { ctx.r3.u64 = Construct_TXT_8349BC84_G_(ctx, base); }

uint64_t Construct_TXT_8349BC88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC88_G_ = int32_t(0x8349BC88);
	constexpr int32_t str_TXT_820D8244_B_ = int32_t(0x820D8244);
	constexpr int32_t Destroy_TXT_8349BC88_G__address = int32_t(0x832A6938);
	if (!UseLiftedCode(144, 0x83262388)) { __imp__sub_83262388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC88_G_, str_TXT_820D8244_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC88_G__address);
}
PROMOTED_ENTRY(144, sub_83262388, 0x83262388) { ctx.r3.u64 = Construct_TXT_8349BC88_G_(ctx, base); }

uint64_t Construct_TXT_8349BC8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC8C_G_ = int32_t(0x8349BC8C);
	constexpr int32_t str_TXT_820D825C_B_ = int32_t(0x820D825C);
	constexpr int32_t Destroy_TXT_8349BC8C_G__address = int32_t(0x832A6948);
	if (!UseLiftedCode(144, 0x832623C8)) { __imp__sub_832623C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832623C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC8C_G_, str_TXT_820D825C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC8C_G__address);
}
PROMOTED_ENTRY(144, sub_832623C8, 0x832623C8) { ctx.r3.u64 = Construct_TXT_8349BC8C_G_(ctx, base); }

uint64_t Construct_TXT_8349BC90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC90_G_ = int32_t(0x8349BC90);
	constexpr int32_t str_TXT_820D826C_B_ = int32_t(0x820D826C);
	constexpr int32_t Destroy_TXT_8349BC90_G__address = int32_t(0x832A6958);
	if (!UseLiftedCode(144, 0x83262408)) { __imp__sub_83262408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC90_G_, str_TXT_820D826C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC90_G__address);
}
PROMOTED_ENTRY(144, sub_83262408, 0x83262408) { ctx.r3.u64 = Construct_TXT_8349BC90_G_(ctx, base); }

uint64_t Construct_TXT_8349BC94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BC94_G_ = int32_t(0x8349BC94);
	constexpr int32_t str_TXT_820D8280_B_ = int32_t(0x820D8280);
	constexpr int32_t Destroy_TXT_8349BC94_G__address = int32_t(0x832A6968);
	if (!UseLiftedCode(144, 0x83262448)) { __imp__sub_83262448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC94_G_, str_TXT_820D8280_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BC94_G__address);
}
PROMOTED_ENTRY(144, sub_83262448, 0x83262448) { ctx.r3.u64 = Construct_TXT_8349BC94_G_(ctx, base); }

uint64_t HashName_TXT_820D8294_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D8294_B_ = int32_t(0x820D8294);
	constexpr uint32_t g_HashOf_TXT_820D8294_B_ = 0x8349BC98u;
	if (!UseLiftedCode(144, 0x83262488)) { __imp__sub_83262488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262488);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D8294_B_);
	STORE32(g_HashOf_TXT_820D8294_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83262488, 0x83262488) { ctx.r3.u64 = HashName_TXT_820D8294_B_(ctx, base); }

uint64_t HashName_TXT_820D82A8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D82A8_B_ = int32_t(0x820D82A8);
	constexpr uint32_t g_HashOf_TXT_820D82A8_B_ = 0x8349BC9Cu;
	if (!UseLiftedCode(144, 0x832624C0)) { __imp__sub_832624C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832624C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D82A8_B_);
	STORE32(g_HashOf_TXT_820D82A8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832624C0, 0x832624C0) { ctx.r3.u64 = HashName_TXT_820D82A8_B_(ctx, base); }

uint64_t HashName_TXT_820D82BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D82BC_B_ = int32_t(0x820D82BC);
	constexpr uint32_t g_HashOf_TXT_820D82BC_B_ = 0x8349BCA0u;
	if (!UseLiftedCode(144, 0x832624F8)) { __imp__sub_832624F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832624F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D82BC_B_);
	STORE32(g_HashOf_TXT_820D82BC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832624F8, 0x832624F8) { ctx.r3.u64 = HashName_TXT_820D82BC_B_(ctx, base); }

uint64_t HashName_TXT_820D82D0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D82D0_B_ = int32_t(0x820D82D0);
	constexpr uint32_t g_HashOf_TXT_820D82D0_B_ = 0x8349BCA4u;
	if (!UseLiftedCode(144, 0x83262530)) { __imp__sub_83262530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262530);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D82D0_B_);
	STORE32(g_HashOf_TXT_820D82D0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83262530, 0x83262530) { ctx.r3.u64 = HashName_TXT_820D82D0_B_(ctx, base); }

uint64_t Construct_TXT_8349BCA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCA8_G_ = int32_t(0x8349BCA8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BCA8_G__address = int32_t(0x832A6978);
	if (!UseLiftedCode(144, 0x83262568)) { __imp__sub_83262568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262568);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCA8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCA8_G__address);
}
PROMOTED_ENTRY(144, sub_83262568, 0x83262568) { ctx.r3.u64 = Construct_TXT_8349BCA8_G_(ctx, base); }

uint64_t Construct_TXT_8349BCAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCAC_G_ = int32_t(0x8349BCAC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BCAC_G__address = int32_t(0x832A6988);
	if (!UseLiftedCode(144, 0x832625A8)) { __imp__sub_832625A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832625A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCAC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCAC_G__address);
}
PROMOTED_ENTRY(144, sub_832625A8, 0x832625A8) { ctx.r3.u64 = Construct_TXT_8349BCAC_G_(ctx, base); }

uint64_t Construct_TXT_8349BCB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCB0_G_ = int32_t(0x8349BCB0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BCB0_G__address = int32_t(0x832A6998);
	if (!UseLiftedCode(144, 0x832625E8)) { __imp__sub_832625E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832625E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCB0_G__address);
}
PROMOTED_ENTRY(144, sub_832625E8, 0x832625E8) { ctx.r3.u64 = Construct_TXT_8349BCB0_G_(ctx, base); }

uint64_t Construct_TXT_8349BCB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCB4_G_ = int32_t(0x8349BCB4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BCB4_G__address = int32_t(0x832A69A8);
	if (!UseLiftedCode(144, 0x83262628)) { __imp__sub_83262628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCB4_G__address);
}
PROMOTED_ENTRY(144, sub_83262628, 0x83262628) { ctx.r3.u64 = Construct_TXT_8349BCB4_G_(ctx, base); }

uint64_t Construct_TXT_8349BCB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCB8_G_ = int32_t(0x8349BCB8);
	constexpr int32_t str_TXT_820C0B34_B_ = int32_t(0x820C0B34);
	constexpr int32_t Destroy_TXT_8349BCB8_G__address = int32_t(0x832A69B8);
	if (!UseLiftedCode(144, 0x83262668)) { __imp__sub_83262668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262668);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB8_G_, str_TXT_820C0B34_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCB8_G__address);
}
PROMOTED_ENTRY(144, sub_83262668, 0x83262668) { ctx.r3.u64 = Construct_TXT_8349BCB8_G_(ctx, base); }

uint64_t Construct_TXT_8349BCBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCBC_G_ = int32_t(0x8349BCBC);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BCBC_G__address = int32_t(0x832A69C8);
	if (!UseLiftedCode(144, 0x832626A8)) { __imp__sub_832626A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832626A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCBC_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCBC_G__address);
}
PROMOTED_ENTRY(144, sub_832626A8, 0x832626A8) { ctx.r3.u64 = Construct_TXT_8349BCBC_G_(ctx, base); }

uint64_t Construct_TXT_8349BCC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCC0_G_ = int32_t(0x8349BCC0);
	constexpr int32_t str_TXT_820D87B0_B_ = int32_t(0x820D87B0);
	constexpr int32_t Destroy_TXT_8349BCC0_G__address = int32_t(0x832A69D8);
	if (!UseLiftedCode(144, 0x832626E8)) { __imp__sub_832626E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832626E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC0_G_, str_TXT_820D87B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCC0_G__address);
}
PROMOTED_ENTRY(144, sub_832626E8, 0x832626E8) { ctx.r3.u64 = Construct_TXT_8349BCC0_G_(ctx, base); }

uint64_t Construct_TXT_8349BCC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCC4_G_ = int32_t(0x8349BCC4);
	constexpr int32_t str_TXT_820D87C4_B_ = int32_t(0x820D87C4);
	constexpr int32_t Destroy_TXT_8349BCC4_G__address = int32_t(0x832A69E8);
	if (!UseLiftedCode(144, 0x83262728)) { __imp__sub_83262728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262728);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC4_G_, str_TXT_820D87C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCC4_G__address);
}
PROMOTED_ENTRY(144, sub_83262728, 0x83262728) { ctx.r3.u64 = Construct_TXT_8349BCC4_G_(ctx, base); }

uint64_t Construct_TXT_8349BCC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCC8_G_ = int32_t(0x8349BCC8);
	constexpr int32_t str_TXT_820D87E8_B_ = int32_t(0x820D87E8);
	constexpr int32_t Destroy_TXT_8349BCC8_G__address = int32_t(0x832A69F8);
	if (!UseLiftedCode(144, 0x83262768)) { __imp__sub_83262768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262768);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC8_G_, str_TXT_820D87E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCC8_G__address);
}
PROMOTED_ENTRY(144, sub_83262768, 0x83262768) { ctx.r3.u64 = Construct_TXT_8349BCC8_G_(ctx, base); }

uint64_t Construct_TXT_8349BCCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCCC_G_ = int32_t(0x8349BCCC);
	constexpr int32_t str_TXT_820D8804_B_ = int32_t(0x820D8804);
	constexpr int32_t Destroy_TXT_8349BCCC_G__address = int32_t(0x832A6A08);
	if (!UseLiftedCode(144, 0x832627A8)) { __imp__sub_832627A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832627A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCCC_G_, str_TXT_820D8804_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCCC_G__address);
}
PROMOTED_ENTRY(144, sub_832627A8, 0x832627A8) { ctx.r3.u64 = Construct_TXT_8349BCCC_G_(ctx, base); }

uint64_t Construct_TXT_8349BCD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCD0_G_ = int32_t(0x8349BCD0);
	constexpr int32_t str_TXT_820D8820_B_ = int32_t(0x820D8820);
	constexpr int32_t Destroy_TXT_8349BCD0_G__address = int32_t(0x832A6A18);
	if (!UseLiftedCode(144, 0x832627E8)) { __imp__sub_832627E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832627E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCD0_G_, str_TXT_820D8820_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCD0_G__address);
}
PROMOTED_ENTRY(144, sub_832627E8, 0x832627E8) { ctx.r3.u64 = Construct_TXT_8349BCD0_G_(ctx, base); }

uint64_t InitializeHeroLocomotionStateIdleString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCD4_G_ = int32_t(0x8349BCD4);
	constexpr int32_t str_TXT_820D6398_B_ = int32_t(0x820D6398);
	constexpr int32_t Destroy_TXT_8349BCD4_G__address = int32_t(0x832A6A28);
	if (!UseLiftedCode(144, 0x83262828)) { __imp__sub_83262828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262828);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349BCD4_G_, str_TXT_820D6398_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCD4_G__address);
}
PROMOTED_ENTRY(144, sub_83262828, 0x83262828) { ctx.r3.u64 = InitializeHeroLocomotionStateIdleString(ctx, base); }

uint64_t Construct_TXT_8349BCD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCD8_G_ = int32_t(0x8349BCD8);
	constexpr int32_t str_TXT_820D8840_B_ = int32_t(0x820D8840);
	constexpr int32_t Destroy_TXT_8349BCD8_G__address = int32_t(0x832A6A38);
	if (!UseLiftedCode(144, 0x83262868)) { __imp__sub_83262868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262868);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCD8_G_, str_TXT_820D8840_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCD8_G__address);
}
PROMOTED_ENTRY(144, sub_83262868, 0x83262868) { ctx.r3.u64 = Construct_TXT_8349BCD8_G_(ctx, base); }

uint64_t Construct_TXT_8349BCDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCDC_G_ = int32_t(0x8349BCDC);
	constexpr int32_t str_TXT_820D8860_B_ = int32_t(0x820D8860);
	constexpr int32_t Destroy_TXT_8349BCDC_G__address = int32_t(0x832A6A48);
	if (!UseLiftedCode(144, 0x832628A8)) { __imp__sub_832628A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832628A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCDC_G_, str_TXT_820D8860_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCDC_G__address);
}
PROMOTED_ENTRY(144, sub_832628A8, 0x832628A8) { ctx.r3.u64 = Construct_TXT_8349BCDC_G_(ctx, base); }

uint64_t Construct_TXT_8349BCE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCE0_G_ = int32_t(0x8349BCE0);
	constexpr int32_t str_TXT_820D89A8_B_ = int32_t(0x820D89A8);
	constexpr int32_t Destroy_TXT_8349BCE0_G__address = int32_t(0x832A6A58);
	if (!UseLiftedCode(144, 0x832628E8)) { __imp__sub_832628E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832628E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE0_G_, str_TXT_820D89A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCE0_G__address);
}
PROMOTED_ENTRY(144, sub_832628E8, 0x832628E8) { ctx.r3.u64 = Construct_TXT_8349BCE0_G_(ctx, base); }

uint64_t Construct_TXT_8349BCE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCE4_G_ = int32_t(0x8349BCE4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BCE4_G__address = int32_t(0x832A6A68);
	if (!UseLiftedCode(144, 0x83262928)) { __imp__sub_83262928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262928);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCE4_G__address);
}
PROMOTED_ENTRY(144, sub_83262928, 0x83262928) { ctx.r3.u64 = Construct_TXT_8349BCE4_G_(ctx, base); }

uint64_t Construct_TXT_8349BCE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCE8_G_ = int32_t(0x8349BCE8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BCE8_G__address = int32_t(0x832A6A78);
	if (!UseLiftedCode(144, 0x83262968)) { __imp__sub_83262968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262968);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCE8_G__address);
}
PROMOTED_ENTRY(144, sub_83262968, 0x83262968) { ctx.r3.u64 = Construct_TXT_8349BCE8_G_(ctx, base); }

uint64_t Construct_TXT_8349BCEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCEC_G_ = int32_t(0x8349BCEC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BCEC_G__address = int32_t(0x832A6A88);
	if (!UseLiftedCode(144, 0x832629A8)) { __imp__sub_832629A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832629A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCEC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCEC_G__address);
}
PROMOTED_ENTRY(144, sub_832629A8, 0x832629A8) { ctx.r3.u64 = Construct_TXT_8349BCEC_G_(ctx, base); }

uint64_t Construct_TXT_8349BCF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BCF0_G_ = int32_t(0x8349BCF0);
	constexpr int32_t str_TXT_820D8C9C_B_ = int32_t(0x820D8C9C);
	constexpr int32_t Destroy_TXT_8349BCF0_G__address = int32_t(0x832A6B00);
	if (!UseLiftedCode(144, 0x832629E8)) { __imp__sub_832629E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832629E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCF0_G_, str_TXT_820D8C9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BCF0_G__address);
}
PROMOTED_ENTRY(144, sub_832629E8, 0x832629E8) { ctx.r3.u64 = Construct_TXT_8349BCF0_G_(ctx, base); }

uint64_t Construct_TXT_8349BD20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD20_G_ = int32_t(0x8349BD20);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BD20_G__address = int32_t(0x832A6B10);
	if (!UseLiftedCode(144, 0x83262A60)) { __imp__sub_83262A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262A60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD20_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD20_G__address);
}
PROMOTED_ENTRY(144, sub_83262A60, 0x83262A60) { ctx.r3.u64 = Construct_TXT_8349BD20_G_(ctx, base); }

uint64_t Construct_TXT_8349BD24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD24_G_ = int32_t(0x8349BD24);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BD24_G__address = int32_t(0x832A6B20);
	if (!UseLiftedCode(144, 0x83262AA0)) { __imp__sub_83262AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD24_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD24_G__address);
}
PROMOTED_ENTRY(144, sub_83262AA0, 0x83262AA0) { ctx.r3.u64 = Construct_TXT_8349BD24_G_(ctx, base); }

uint64_t Construct_TXT_8349BD28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD28_G_ = int32_t(0x8349BD28);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BD28_G__address = int32_t(0x832A6B30);
	if (!UseLiftedCode(144, 0x83262AE0)) { __imp__sub_83262AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD28_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD28_G__address);
}
PROMOTED_ENTRY(144, sub_83262AE0, 0x83262AE0) { ctx.r3.u64 = Construct_TXT_8349BD28_G_(ctx, base); }

uint64_t Construct_TXT_8349BD40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD40_G_ = int32_t(0x8349BD40);
	constexpr int32_t str_TXT_82000E18_B_ = int32_t(0x82000E18);
	constexpr int32_t Destroy_TXT_8349BD40_G__address = int32_t(0x832A6B40);
	if (!UseLiftedCode(144, 0x83262B20)) { __imp__sub_83262B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262B20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD40_G_, str_TXT_82000E18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD40_G__address);
}
PROMOTED_ENTRY(144, sub_83262B20, 0x83262B20) { ctx.r3.u64 = Construct_TXT_8349BD40_G_(ctx, base); }

uint64_t Construct_TXT_8349BD44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD44_G_ = int32_t(0x8349BD44);
	constexpr int32_t str_TXT_820B2EDC_B_ = int32_t(0x820B2EDC);
	constexpr int32_t Destroy_TXT_8349BD44_G__address = int32_t(0x832A6B50);
	if (!UseLiftedCode(144, 0x83262B60)) { __imp__sub_83262B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262B60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD44_G_, str_TXT_820B2EDC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD44_G__address);
}
PROMOTED_ENTRY(144, sub_83262B60, 0x83262B60) { ctx.r3.u64 = Construct_TXT_8349BD44_G_(ctx, base); }

uint64_t Construct_TXT_8349BD50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD50_G_ = int32_t(0x8349BD50);
	constexpr int32_t str_TXT_820D9EE4_B_ = int32_t(0x820D9EE4);
	constexpr int32_t Destroy_TXT_8349BD50_G__address = int32_t(0x832A6B60);
	if (!UseLiftedCode(144, 0x83262C00)) { __imp__sub_83262C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD50_G_, str_TXT_820D9EE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD50_G__address);
}
PROMOTED_ENTRY(144, sub_83262C00, 0x83262C00) { ctx.r3.u64 = Construct_TXT_8349BD50_G_(ctx, base); }

uint64_t Construct_TXT_8349BD54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD54_G_ = int32_t(0x8349BD54);
	constexpr int32_t str_TXT_820D9F00_B_ = int32_t(0x820D9F00);
	constexpr int32_t Destroy_TXT_8349BD54_G__address = int32_t(0x832A6B70);
	if (!UseLiftedCode(144, 0x83262C40)) { __imp__sub_83262C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD54_G_, str_TXT_820D9F00_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD54_G__address);
}
PROMOTED_ENTRY(144, sub_83262C40, 0x83262C40) { ctx.r3.u64 = Construct_TXT_8349BD54_G_(ctx, base); }

uint64_t Construct_TXT_8349BD58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD58_G_ = int32_t(0x8349BD58);
	constexpr int32_t str_TXT_820AFDE0_B_ = int32_t(0x820AFDE0);
	constexpr int32_t Destroy_TXT_8349BD58_G__address = int32_t(0x832A6B80);
	if (!UseLiftedCode(144, 0x83262C80)) { __imp__sub_83262C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD58_G_, str_TXT_820AFDE0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD58_G__address);
}
PROMOTED_ENTRY(144, sub_83262C80, 0x83262C80) { ctx.r3.u64 = Construct_TXT_8349BD58_G_(ctx, base); }

uint64_t Construct_TXT_8349BD5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD5C_G_ = int32_t(0x8349BD5C);
	constexpr int32_t str_TXT_820DA0A4_B_ = int32_t(0x820DA0A4);
	constexpr int32_t Destroy_TXT_8349BD5C_G__address = int32_t(0x832A6B90);
	if (!UseLiftedCode(144, 0x83262CC0)) { __imp__sub_83262CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262CC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD5C_G_, str_TXT_820DA0A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD5C_G__address);
}
PROMOTED_ENTRY(144, sub_83262CC0, 0x83262CC0) { ctx.r3.u64 = Construct_TXT_8349BD5C_G_(ctx, base); }

uint64_t Construct_TXT_8349BD60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD60_G_ = int32_t(0x8349BD60);
	constexpr int32_t str_TXT_820DA0B0_B_ = int32_t(0x820DA0B0);
	constexpr int32_t Destroy_TXT_8349BD60_G__address = int32_t(0x832A6BA0);
	if (!UseLiftedCode(144, 0x83262D00)) { __imp__sub_83262D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262D00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD60_G_, str_TXT_820DA0B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD60_G__address);
}
PROMOTED_ENTRY(144, sub_83262D00, 0x83262D00) { ctx.r3.u64 = Construct_TXT_8349BD60_G_(ctx, base); }

uint64_t Construct_TXT_8349BD64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD64_G_ = int32_t(0x8349BD64);
	constexpr int32_t str_TXT_820DA0B8_B_ = int32_t(0x820DA0B8);
	constexpr int32_t Destroy_TXT_8349BD64_G__address = int32_t(0x832A6BB0);
	if (!UseLiftedCode(144, 0x83262D40)) { __imp__sub_83262D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262D40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD64_G_, str_TXT_820DA0B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD64_G__address);
}
PROMOTED_ENTRY(144, sub_83262D40, 0x83262D40) { ctx.r3.u64 = Construct_TXT_8349BD64_G_(ctx, base); }

uint64_t Construct_TXT_8349BD84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD84_G_ = int32_t(0x8349BD84);
	constexpr int32_t str_TXT_820BE9C8_B_ = int32_t(0x820BE9C8);
	constexpr int32_t Destroy_TXT_8349BD84_G__address = int32_t(0x832A6BD8);
	if (!UseLiftedCode(144, 0x83262F38)) { __imp__sub_83262F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD84_G_, str_TXT_820BE9C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD84_G__address);
}
PROMOTED_ENTRY(144, sub_83262F38, 0x83262F38) { ctx.r3.u64 = Construct_TXT_8349BD84_G_(ctx, base); }

uint64_t Construct_TXT_8349BD88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD88_G_ = int32_t(0x8349BD88);
	constexpr int32_t str_TXT_820DA7B0_B_ = int32_t(0x820DA7B0);
	constexpr int32_t Destroy_TXT_8349BD88_G__address = int32_t(0x832A6BE8);
	if (!UseLiftedCode(144, 0x83262F78)) { __imp__sub_83262F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD88_G_, str_TXT_820DA7B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD88_G__address);
}
PROMOTED_ENTRY(144, sub_83262F78, 0x83262F78) { ctx.r3.u64 = Construct_TXT_8349BD88_G_(ctx, base); }

uint64_t Construct_TXT_8349BD8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD8C_G_ = int32_t(0x8349BD8C);
	constexpr int32_t str_TXT_820DA7C8_B_ = int32_t(0x820DA7C8);
	constexpr int32_t Destroy_TXT_8349BD8C_G__address = int32_t(0x832A6BF8);
	if (!UseLiftedCode(144, 0x83262FB8)) { __imp__sub_83262FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD8C_G_, str_TXT_820DA7C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD8C_G__address);
}
PROMOTED_ENTRY(144, sub_83262FB8, 0x83262FB8) { ctx.r3.u64 = Construct_TXT_8349BD8C_G_(ctx, base); }

uint64_t Construct_TXT_8349BD90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD90_G_ = int32_t(0x8349BD90);
	constexpr int32_t str_TXT_820DA7E0_B_ = int32_t(0x820DA7E0);
	constexpr int32_t Destroy_TXT_8349BD90_G__address = int32_t(0x832A6C08);
	if (!UseLiftedCode(144, 0x83262FF8)) { __imp__sub_83262FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD90_G_, str_TXT_820DA7E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD90_G__address);
}
PROMOTED_ENTRY(144, sub_83262FF8, 0x83262FF8) { ctx.r3.u64 = Construct_TXT_8349BD90_G_(ctx, base); }

uint64_t Construct_TXT_8349BD94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD94_G_ = int32_t(0x8349BD94);
	constexpr int32_t str_TXT_820DA7F0_B_ = int32_t(0x820DA7F0);
	constexpr int32_t Destroy_TXT_8349BD94_G__address = int32_t(0x832A6C18);
	if (!UseLiftedCode(144, 0x83263038)) { __imp__sub_83263038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD94_G_, str_TXT_820DA7F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD94_G__address);
}
PROMOTED_ENTRY(144, sub_83263038, 0x83263038) { ctx.r3.u64 = Construct_TXT_8349BD94_G_(ctx, base); }

uint64_t Construct_TXT_8349BD98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD98_G_ = int32_t(0x8349BD98);
	constexpr int32_t str_TXT_820DA80C_B_ = int32_t(0x820DA80C);
	constexpr int32_t Destroy_TXT_8349BD98_G__address = int32_t(0x832A6C28);
	if (!UseLiftedCode(144, 0x83263078)) { __imp__sub_83263078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD98_G_, str_TXT_820DA80C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD98_G__address);
}
PROMOTED_ENTRY(144, sub_83263078, 0x83263078) { ctx.r3.u64 = Construct_TXT_8349BD98_G_(ctx, base); }

uint64_t Construct_TXT_8349BD9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BD9C_G_ = int32_t(0x8349BD9C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BD9C_G__address = int32_t(0x832A6C38);
	if (!UseLiftedCode(144, 0x832630B8)) { __imp__sub_832630B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832630B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD9C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BD9C_G__address);
}
PROMOTED_ENTRY(144, sub_832630B8, 0x832630B8) { ctx.r3.u64 = Construct_TXT_8349BD9C_G_(ctx, base); }

uint64_t Construct_TXT_8349BDA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDA0_G_ = int32_t(0x8349BDA0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BDA0_G__address = int32_t(0x832A6C48);
	if (!UseLiftedCode(144, 0x832630F8)) { __imp__sub_832630F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832630F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDA0_G__address);
}
PROMOTED_ENTRY(144, sub_832630F8, 0x832630F8) { ctx.r3.u64 = Construct_TXT_8349BDA0_G_(ctx, base); }

uint64_t Construct_TXT_8349BDA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDA4_G_ = int32_t(0x8349BDA4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BDA4_G__address = int32_t(0x832A6C58);
	if (!UseLiftedCode(144, 0x83263138)) { __imp__sub_83263138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDA4_G__address);
}
PROMOTED_ENTRY(144, sub_83263138, 0x83263138) { ctx.r3.u64 = Construct_TXT_8349BDA4_G_(ctx, base); }

uint64_t Construct_TXT_8349BDA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDA8_G_ = int32_t(0x8349BDA8);
	constexpr int32_t str_TXT_820DA898_B_ = int32_t(0x820DA898);
	constexpr int32_t Destroy_TXT_8349BDA8_G__address = int32_t(0x832A6C68);
	if (!UseLiftedCode(144, 0x83263178)) { __imp__sub_83263178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263178);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA8_G_, str_TXT_820DA898_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDA8_G__address);
}
PROMOTED_ENTRY(144, sub_83263178, 0x83263178) { ctx.r3.u64 = Construct_TXT_8349BDA8_G_(ctx, base); }

uint64_t Construct_TXT_8349BDAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDAC_G_ = int32_t(0x8349BDAC);
	constexpr int32_t str_TXT_820DA8B0_B_ = int32_t(0x820DA8B0);
	constexpr int32_t Destroy_TXT_8349BDAC_G__address = int32_t(0x832A6C78);
	if (!UseLiftedCode(144, 0x832631B8)) { __imp__sub_832631B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832631B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDAC_G_, str_TXT_820DA8B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDAC_G__address);
}
PROMOTED_ENTRY(144, sub_832631B8, 0x832631B8) { ctx.r3.u64 = Construct_TXT_8349BDAC_G_(ctx, base); }

uint64_t Construct_TXT_8349BDB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDB0_G_ = int32_t(0x8349BDB0);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BDB0_G__address = int32_t(0x832A6C88);
	if (!UseLiftedCode(144, 0x832631F8)) { __imp__sub_832631F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832631F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB0_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDB0_G__address);
}
PROMOTED_ENTRY(144, sub_832631F8, 0x832631F8) { ctx.r3.u64 = Construct_TXT_8349BDB0_G_(ctx, base); }

uint64_t Construct_TXT_8349BDB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDB4_G_ = int32_t(0x8349BDB4);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BDB4_G__address = int32_t(0x832A6C98);
	if (!UseLiftedCode(144, 0x83263238)) { __imp__sub_83263238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB4_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDB4_G__address);
}
PROMOTED_ENTRY(144, sub_83263238, 0x83263238) { ctx.r3.u64 = Construct_TXT_8349BDB4_G_(ctx, base); }

uint64_t Construct_TXT_8349BDB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDB8_G_ = int32_t(0x8349BDB8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349BDB8_G__address = int32_t(0x832A6CA8);
	if (!UseLiftedCode(144, 0x83263278)) { __imp__sub_83263278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDB8_G__address);
}
PROMOTED_ENTRY(144, sub_83263278, 0x83263278) { ctx.r3.u64 = Construct_TXT_8349BDB8_G_(ctx, base); }

uint64_t Construct_TXT_8349BDBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDBC_G_ = int32_t(0x8349BDBC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349BDBC_G__address = int32_t(0x832A6CB8);
	if (!UseLiftedCode(144, 0x832632B8)) { __imp__sub_832632B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832632B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDBC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDBC_G__address);
}
PROMOTED_ENTRY(144, sub_832632B8, 0x832632B8) { ctx.r3.u64 = Construct_TXT_8349BDBC_G_(ctx, base); }

uint64_t Construct_TXT_8349BDC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDC0_G_ = int32_t(0x8349BDC0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349BDC0_G__address = int32_t(0x832A6CC8);
	if (!UseLiftedCode(144, 0x832632F8)) { __imp__sub_832632F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832632F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDC0_G__address);
}
PROMOTED_ENTRY(144, sub_832632F8, 0x832632F8) { ctx.r3.u64 = Construct_TXT_8349BDC0_G_(ctx, base); }

uint64_t Construct_TXT_8349BDC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDC4_G_ = int32_t(0x8349BDC4);
	constexpr int32_t str_TXT_820DB710_B_ = int32_t(0x820DB710);
	constexpr int32_t Destroy_TXT_8349BDC4_G__address = int32_t(0x832A6CD8);
	if (!UseLiftedCode(144, 0x83263338)) { __imp__sub_83263338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263338);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC4_G_, str_TXT_820DB710_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDC4_G__address);
}
PROMOTED_ENTRY(144, sub_83263338, 0x83263338) { ctx.r3.u64 = Construct_TXT_8349BDC4_G_(ctx, base); }

uint64_t Construct_TXT_8349BDC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDC8_G_ = int32_t(0x8349BDC8);
	constexpr int32_t str_TXT_820DB720_B_ = int32_t(0x820DB720);
	constexpr int32_t Destroy_TXT_8349BDC8_G__address = int32_t(0x832A6CE8);
	if (!UseLiftedCode(144, 0x83263378)) { __imp__sub_83263378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263378);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC8_G_, str_TXT_820DB720_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDC8_G__address);
}
PROMOTED_ENTRY(144, sub_83263378, 0x83263378) { ctx.r3.u64 = Construct_TXT_8349BDC8_G_(ctx, base); }

uint64_t Construct_TXT_8349BDCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDCC_G_ = int32_t(0x8349BDCC);
	constexpr int32_t str_TXT_820DB73C_B_ = int32_t(0x820DB73C);
	constexpr int32_t Destroy_TXT_8349BDCC_G__address = int32_t(0x832A6CF8);
	if (!UseLiftedCode(144, 0x832633B8)) { __imp__sub_832633B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832633B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDCC_G_, str_TXT_820DB73C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDCC_G__address);
}
PROMOTED_ENTRY(144, sub_832633B8, 0x832633B8) { ctx.r3.u64 = Construct_TXT_8349BDCC_G_(ctx, base); }

uint64_t Construct_TXT_8349BDD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDD0_G_ = int32_t(0x8349BDD0);
	constexpr int32_t str_TXT_820DB754_B_ = int32_t(0x820DB754);
	constexpr int32_t Destroy_TXT_8349BDD0_G__address = int32_t(0x832A6D08);
	if (!UseLiftedCode(144, 0x832633F8)) { __imp__sub_832633F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832633F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD0_G_, str_TXT_820DB754_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDD0_G__address);
}
PROMOTED_ENTRY(144, sub_832633F8, 0x832633F8) { ctx.r3.u64 = Construct_TXT_8349BDD0_G_(ctx, base); }

uint64_t Construct_TXT_8349BDD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDD4_G_ = int32_t(0x8349BDD4);
	constexpr int32_t str_TXT_820DB770_B_ = int32_t(0x820DB770);
	constexpr int32_t Destroy_TXT_8349BDD4_G__address = int32_t(0x832A6D18);
	if (!UseLiftedCode(144, 0x83263438)) { __imp__sub_83263438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263438);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD4_G_, str_TXT_820DB770_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDD4_G__address);
}
PROMOTED_ENTRY(144, sub_83263438, 0x83263438) { ctx.r3.u64 = Construct_TXT_8349BDD4_G_(ctx, base); }

uint64_t Construct_TXT_8349BDD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDD8_G_ = int32_t(0x8349BDD8);
	constexpr int32_t str_TXT_820BD1B4_B_ = int32_t(0x820BD1B4);
	constexpr int32_t Destroy_TXT_8349BDD8_G__address = int32_t(0x832A6D28);
	if (!UseLiftedCode(144, 0x83263478)) { __imp__sub_83263478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263478);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD8_G_, str_TXT_820BD1B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDD8_G__address);
}
PROMOTED_ENTRY(144, sub_83263478, 0x83263478) { ctx.r3.u64 = Construct_TXT_8349BDD8_G_(ctx, base); }

uint64_t Construct_TXT_8349BDDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDDC_G_ = int32_t(0x8349BDDC);
	constexpr int32_t str_TXT_820DB788_B_ = int32_t(0x820DB788);
	constexpr int32_t Destroy_TXT_8349BDDC_G__address = int32_t(0x832A6D38);
	if (!UseLiftedCode(144, 0x832634B8)) { __imp__sub_832634B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832634B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDDC_G_, str_TXT_820DB788_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDDC_G__address);
}
PROMOTED_ENTRY(144, sub_832634B8, 0x832634B8) { ctx.r3.u64 = Construct_TXT_8349BDDC_G_(ctx, base); }

uint64_t Construct_TXT_8349BDE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BDE0_G_ = int32_t(0x8349BDE0);
	constexpr int32_t str_TXT_820BD1DC_B_ = int32_t(0x820BD1DC);
	constexpr int32_t Destroy_TXT_8349BDE0_G__address = int32_t(0x832A6D48);
	if (!UseLiftedCode(144, 0x832634F8)) { __imp__sub_832634F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832634F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDE0_G_, str_TXT_820BD1DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BDE0_G__address);
}
PROMOTED_ENTRY(144, sub_832634F8, 0x832634F8) { ctx.r3.u64 = Construct_TXT_8349BDE0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__23 = 0x8349BDE4u;
	if (!UseLiftedCode(144, 0x83263538)) { __imp__sub_83263538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263538);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263538, 0x83263538) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__23(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__24 = 0x8349BDE8u;
	if (!UseLiftedCode(144, 0x83263570)) { __imp__sub_83263570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263570);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263570, 0x83263570) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__24(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__24 = 0x8349BDECu;
	if (!UseLiftedCode(144, 0x832635A8)) { __imp__sub_832635A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832635A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832635A8, 0x832635A8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__23 = 0x8349BDF0u;
	if (!UseLiftedCode(144, 0x832635E0)) { __imp__sub_832635E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832635E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832635E0, 0x832635E0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__23 = 0x8349BDF4u;
	if (!UseLiftedCode(144, 0x83263618)) { __imp__sub_83263618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263618);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263618, 0x83263618) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__23 = 0x8349BDF8u;
	if (!UseLiftedCode(144, 0x83263650)) { __imp__sub_83263650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263650);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263650, 0x83263650) { ctx.r3.u64 = HashName_TXT_820A2C34_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__23 = 0x8349BDFCu;
	if (!UseLiftedCode(144, 0x83263688)) { __imp__sub_83263688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263688, 0x83263688) { ctx.r3.u64 = HashName_TXT_820A2C44_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__23 = 0x8349BE00u;
	if (!UseLiftedCode(144, 0x832636C0)) { __imp__sub_832636C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832636C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832636C0, 0x832636C0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__23 = 0x8349BE04u;
	if (!UseLiftedCode(144, 0x832636F8)) { __imp__sub_832636F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832636F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832636F8, 0x832636F8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__23(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__23 = 0x8349BE08u;
	if (!UseLiftedCode(144, 0x83263730)) { __imp__sub_83263730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263730, 0x83263730) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__23 = 0x8349BE0Cu;
	if (!UseLiftedCode(144, 0x83263768)) { __imp__sub_83263768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263768, 0x83263768) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__23(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__23 = 0x8349BE10u;
	if (!UseLiftedCode(144, 0x832637A0)) { __imp__sub_832637A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832637A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832637A0, 0x832637A0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__23(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__25 = 0x8349BE14u;
	if (!UseLiftedCode(144, 0x832637D8)) { __imp__sub_832637D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832637D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832637D8, 0x832637D8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__23 = 0x8349BE18u;
	if (!UseLiftedCode(144, 0x83263810)) { __imp__sub_83263810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263810, 0x83263810) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__23(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__23 = 0x8349BE1Cu;
	if (!UseLiftedCode(144, 0x83263848)) { __imp__sub_83263848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263848, 0x83263848) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__23(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__22 = 0x8349BE20u;
	if (!UseLiftedCode(144, 0x83263880)) { __imp__sub_83263880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263880);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263880, 0x83263880) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__22(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__22 = 0x8349BE24u;
	if (!UseLiftedCode(144, 0x832638B8)) { __imp__sub_832638B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832638B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832638B8, 0x832638B8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__22(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__22(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__22 = 0x8349BE28u;
	if (!UseLiftedCode(144, 0x832638F0)) { __imp__sub_832638F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832638F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__22, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832638F0, 0x832638F0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__22(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__23 = 0x8349BE2Cu;
	if (!UseLiftedCode(144, 0x83263928)) { __imp__sub_83263928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263928);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263928, 0x83263928) { ctx.r3.u64 = HashName_TXT_820A2D30_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__23 = 0x8349BE30u;
	if (!UseLiftedCode(144, 0x83263960)) { __imp__sub_83263960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263960, 0x83263960) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__23 = 0x8349BE34u;
	if (!UseLiftedCode(144, 0x83263998)) { __imp__sub_83263998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83263998, 0x83263998) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__23(ctx, base); }

uint64_t Construct_TXT_8349BE38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE38_G_ = int32_t(0x8349BE38);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349BE38_G__address = int32_t(0x832A6D58);
	if (!UseLiftedCode(144, 0x832639D0)) { __imp__sub_832639D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832639D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE38_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE38_G__address);
}
PROMOTED_ENTRY(144, sub_832639D0, 0x832639D0) { ctx.r3.u64 = Construct_TXT_8349BE38_G_(ctx, base); }

uint64_t Construct_TXT_8349BE3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE3C_G_ = int32_t(0x8349BE3C);
	constexpr int32_t str_TXT_820DB7B0_B_ = int32_t(0x820DB7B0);
	constexpr int32_t Destroy_TXT_8349BE3C_G__address = int32_t(0x832A6D68);
	if (!UseLiftedCode(144, 0x83263A10)) { __imp__sub_83263A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE3C_G_, str_TXT_820DB7B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE3C_G__address);
}
PROMOTED_ENTRY(144, sub_83263A10, 0x83263A10) { ctx.r3.u64 = Construct_TXT_8349BE3C_G_(ctx, base); }

uint64_t Construct_TXT_8349BE40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE40_G_ = int32_t(0x8349BE40);
	constexpr int32_t str_TXT_820DB7E8_B_ = int32_t(0x820DB7E8);
	constexpr int32_t Destroy_TXT_8349BE40_G__address = int32_t(0x832A6D78);
	if (!UseLiftedCode(144, 0x83263A50)) { __imp__sub_83263A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE40_G_, str_TXT_820DB7E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE40_G__address);
}
PROMOTED_ENTRY(144, sub_83263A50, 0x83263A50) { ctx.r3.u64 = Construct_TXT_8349BE40_G_(ctx, base); }

uint64_t Construct_TXT_8349BE44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE44_G_ = int32_t(0x8349BE44);
	constexpr int32_t str_TXT_820DB7B0_B_ = int32_t(0x820DB828);
	constexpr int32_t Destroy_TXT_8349BE44_G__address = int32_t(0x832A6D88);
	if (!UseLiftedCode(144, 0x83263A90)) { __imp__sub_83263A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE44_G_, str_TXT_820DB7B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE44_G__address);
}
PROMOTED_ENTRY(144, sub_83263A90, 0x83263A90) { ctx.r3.u64 = Construct_TXT_8349BE44_G_(ctx, base); }

uint64_t Construct_TXT_8349BE48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE48_G_ = int32_t(0x8349BE48);
	constexpr int32_t str_TXT_820DB7B0_B_ = int32_t(0x820DB860);
	constexpr int32_t Destroy_TXT_8349BE48_G__address = int32_t(0x832A6D98);
	if (!UseLiftedCode(144, 0x83263AD0)) { __imp__sub_83263AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE48_G_, str_TXT_820DB7B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE48_G__address);
}
PROMOTED_ENTRY(144, sub_83263AD0, 0x83263AD0) { ctx.r3.u64 = Construct_TXT_8349BE48_G_(ctx, base); }

uint64_t Construct_TXT_8349BE4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349BE4C_G_ = int32_t(0x8349BE4C);
	constexpr int32_t str_TXT_820DB898_B_ = int32_t(0x820DB898);
	constexpr int32_t Destroy_TXT_8349BE4C_G__address = int32_t(0x832A6DA8);
	if (!UseLiftedCode(144, 0x83263B10)) { __imp__sub_83263B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263B10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE4C_G_, str_TXT_820DB898_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349BE4C_G__address);
}
PROMOTED_ENTRY(144, sub_83263B10, 0x83263B10) { ctx.r3.u64 = Construct_TXT_8349BE4C_G_(ctx, base); }

uint64_t RegisterExitDestructor832A7238(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A7238_address = int32_t(0x832A7238);
	if (!UseLiftedCode(144, 0x832645B0)) { ctx.r8.u64 = destructorArgument; __imp__sub_832645B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645B0);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A7238_address, destructorArgument);
}
PROMOTED_ENTRY(144, sub_832645B0, 0x832645B0) { ctx.r3.u64 = RegisterExitDestructor832A7238(ctx, base, ctx.r8.u64); }

uint64_t RegisterExitDestructor832A72A0(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A72A0_address = int32_t(0x832A72A0);
	if (!UseLiftedCode(144, 0x832645C0)) { ctx.r8.u64 = destructorArgument; __imp__sub_832645C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645C0);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A72A0_address, destructorArgument);
}
PROMOTED_ENTRY(144, sub_832645C0, 0x832645C0) { ctx.r3.u64 = RegisterExitDestructor832A72A0(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349C004_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C004_G_ = int32_t(0x8349C004);
	constexpr int32_t str_TXT_820DCDB4_B_ = int32_t(0x820DCDB4);
	constexpr int32_t Destroy_TXT_8349C004_G__address = int32_t(0x832A7308);
	if (!UseLiftedCode(144, 0x832645D0)) { __imp__sub_832645D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C004_G_, str_TXT_820DCDB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C004_G__address);
}
PROMOTED_ENTRY(144, sub_832645D0, 0x832645D0) { ctx.r3.u64 = Construct_TXT_8349C004_G_(ctx, base); }

uint64_t Construct_TXT_8349C008_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C008_G_ = int32_t(0x8349C008);
	constexpr int32_t str_TXT_820DCDB4_B_ = int32_t(0x820DCDB4);
	constexpr int32_t Destroy_TXT_8349C008_G__address = int32_t(0x832A7318);
	if (!UseLiftedCode(144, 0x83264610)) { __imp__sub_83264610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264610);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C008_G_, str_TXT_820DCDB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C008_G__address);
}
PROMOTED_ENTRY(144, sub_83264610, 0x83264610) { ctx.r3.u64 = Construct_TXT_8349C008_G_(ctx, base); }

uint64_t Construct_TXT_8349C00C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C00C_G_ = int32_t(0x8349C00C);
	constexpr int32_t str_TXT_820DCDC0_B_ = int32_t(0x820DCDC0);
	constexpr int32_t Destroy_TXT_8349C00C_G__address = int32_t(0x832A7328);
	if (!UseLiftedCode(144, 0x83264650)) { __imp__sub_83264650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264650);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C00C_G_, str_TXT_820DCDC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C00C_G__address);
}
PROMOTED_ENTRY(144, sub_83264650, 0x83264650) { ctx.r3.u64 = Construct_TXT_8349C00C_G_(ctx, base); }

uint64_t Construct_TXT_8349C010_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C010_G_ = int32_t(0x8349C010);
	constexpr int32_t str_TXT_820DCDC8_B_ = int32_t(0x820DCDC8);
	constexpr int32_t Destroy_TXT_8349C010_G__address = int32_t(0x832A7338);
	if (!UseLiftedCode(144, 0x83264690)) { __imp__sub_83264690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264690);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C010_G_, str_TXT_820DCDC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C010_G__address);
}
PROMOTED_ENTRY(144, sub_83264690, 0x83264690) { ctx.r3.u64 = Construct_TXT_8349C010_G_(ctx, base); }

uint64_t Construct_TXT_8349C014_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C014_G_ = int32_t(0x8349C014);
	constexpr int32_t str_TXT_820DCDD0_B_ = int32_t(0x820DCDD0);
	constexpr int32_t Destroy_TXT_8349C014_G__address = int32_t(0x832A7348);
	if (!UseLiftedCode(144, 0x832646D0)) { __imp__sub_832646D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832646D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C014_G_, str_TXT_820DCDD0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C014_G__address);
}
PROMOTED_ENTRY(144, sub_832646D0, 0x832646D0) { ctx.r3.u64 = Construct_TXT_8349C014_G_(ctx, base); }

uint64_t Construct_TXT_8349C018_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C018_G_ = int32_t(0x8349C018);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349C018_G__address = int32_t(0x832A7358);
	if (!UseLiftedCode(144, 0x83264710)) { __imp__sub_83264710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264710);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C018_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C018_G__address);
}
PROMOTED_ENTRY(144, sub_83264710, 0x83264710) { ctx.r3.u64 = Construct_TXT_8349C018_G_(ctx, base); }

uint64_t Construct_TXT_8349C01C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C01C_G_ = int32_t(0x8349C01C);
	constexpr int32_t str_TXT_820DCDF0_B_ = int32_t(0x820DCDF0);
	constexpr int32_t Destroy_TXT_8349C01C_G__address = int32_t(0x832A7368);
	if (!UseLiftedCode(144, 0x83264750)) { __imp__sub_83264750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264750);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C01C_G_, str_TXT_820DCDF0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C01C_G__address);
}
PROMOTED_ENTRY(144, sub_83264750, 0x83264750) { ctx.r3.u64 = Construct_TXT_8349C01C_G_(ctx, base); }

uint64_t Construct_TXT_8349C020_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C020_G_ = int32_t(0x8349C020);
	constexpr int32_t str_TXT_820DCDFC_B_ = int32_t(0x820DCDFC);
	constexpr int32_t Destroy_TXT_8349C020_G__address = int32_t(0x832A7378);
	if (!UseLiftedCode(144, 0x83264790)) { __imp__sub_83264790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C020_G_, str_TXT_820DCDFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C020_G__address);
}
PROMOTED_ENTRY(144, sub_83264790, 0x83264790) { ctx.r3.u64 = Construct_TXT_8349C020_G_(ctx, base); }

uint64_t Construct_TXT_8349C024_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C024_G_ = int32_t(0x8349C024);
	constexpr int32_t str_TXT_820DCE08_B_ = int32_t(0x820DCE08);
	constexpr int32_t Destroy_TXT_8349C024_G__address = int32_t(0x832A7388);
	if (!UseLiftedCode(144, 0x832647D0)) { __imp__sub_832647D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832647D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C024_G_, str_TXT_820DCE08_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C024_G__address);
}
PROMOTED_ENTRY(144, sub_832647D0, 0x832647D0) { ctx.r3.u64 = Construct_TXT_8349C024_G_(ctx, base); }

uint64_t Construct_TXT_8349C028_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C028_G_ = int32_t(0x8349C028);
	constexpr int32_t str_TXT_820DCE18_B_ = int32_t(0x820DCE18);
	constexpr int32_t Destroy_TXT_8349C028_G__address = int32_t(0x832A7398);
	if (!UseLiftedCode(144, 0x83264810)) { __imp__sub_83264810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264810);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C028_G_, str_TXT_820DCE18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C028_G__address);
}
PROMOTED_ENTRY(144, sub_83264810, 0x83264810) { ctx.r3.u64 = Construct_TXT_8349C028_G_(ctx, base); }

uint64_t Construct_TXT_8349C02C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C02C_G_ = int32_t(0x8349C02C);
	constexpr int32_t str_TXT_820DCE24_B_ = int32_t(0x820DCE24);
	constexpr int32_t Destroy_TXT_8349C02C_G__address = int32_t(0x832A73A8);
	if (!UseLiftedCode(144, 0x83264850)) { __imp__sub_83264850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264850);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C02C_G_, str_TXT_820DCE24_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C02C_G__address);
}
PROMOTED_ENTRY(144, sub_83264850, 0x83264850) { ctx.r3.u64 = Construct_TXT_8349C02C_G_(ctx, base); }

uint64_t Construct_TXT_8349C030_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C030_G_ = int32_t(0x8349C030);
	constexpr int32_t str_TXT_820DCE30_B_ = int32_t(0x820DCE30);
	constexpr int32_t Destroy_TXT_8349C030_G__address = int32_t(0x832A73B8);
	if (!UseLiftedCode(144, 0x83264890)) { __imp__sub_83264890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264890);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C030_G_, str_TXT_820DCE30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C030_G__address);
}
PROMOTED_ENTRY(144, sub_83264890, 0x83264890) { ctx.r3.u64 = Construct_TXT_8349C030_G_(ctx, base); }

uint64_t Construct_TXT_8349C034_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C034_G_ = int32_t(0x8349C034);
	constexpr int32_t str_TXT_820DCE44_B_ = int32_t(0x820DCE44);
	constexpr int32_t Destroy_TXT_8349C034_G__address = int32_t(0x832A73C8);
	if (!UseLiftedCode(144, 0x832648D0)) { __imp__sub_832648D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832648D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C034_G_, str_TXT_820DCE44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C034_G__address);
}
PROMOTED_ENTRY(144, sub_832648D0, 0x832648D0) { ctx.r3.u64 = Construct_TXT_8349C034_G_(ctx, base); }

uint64_t Construct_TXT_8349C038_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C038_G_ = int32_t(0x8349C038);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349C038_G__address = int32_t(0x832A73D8);
	if (!UseLiftedCode(144, 0x83264910)) { __imp__sub_83264910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C038_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C038_G__address);
}
PROMOTED_ENTRY(144, sub_83264910, 0x83264910) { ctx.r3.u64 = Construct_TXT_8349C038_G_(ctx, base); }

uint64_t Construct_TXT_8349C03C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C03C_G_ = int32_t(0x8349C03C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349C03C_G__address = int32_t(0x832A73E8);
	if (!UseLiftedCode(144, 0x83264950)) { __imp__sub_83264950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C03C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C03C_G__address);
}
PROMOTED_ENTRY(144, sub_83264950, 0x83264950) { ctx.r3.u64 = Construct_TXT_8349C03C_G_(ctx, base); }

uint64_t Construct_TXT_8349C040_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C040_G_ = int32_t(0x8349C040);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349C040_G__address = int32_t(0x832A73F8);
	if (!UseLiftedCode(144, 0x83264990)) { __imp__sub_83264990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264990);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C040_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C040_G__address);
}
PROMOTED_ENTRY(144, sub_83264990, 0x83264990) { ctx.r3.u64 = Construct_TXT_8349C040_G_(ctx, base); }

uint64_t Construct_TXT_8349C044_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C044_G_ = int32_t(0x8349C044);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349C044_G__address = int32_t(0x832A7408);
	if (!UseLiftedCode(144, 0x832649D0)) { __imp__sub_832649D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832649D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C044_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C044_G__address);
}
PROMOTED_ENTRY(144, sub_832649D0, 0x832649D0) { ctx.r3.u64 = Construct_TXT_8349C044_G_(ctx, base); }

uint64_t HashName_TXT_820B98EC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B98EC_B_ = int32_t(0x820B98EC);
	constexpr uint32_t g_HashOf_TXT_820B98EC_B__2 = 0x8349C048u;
	if (!UseLiftedCode(144, 0x83264A10)) { __imp__sub_83264A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264A10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820B98EC_B_);
	STORE32(g_HashOf_TXT_820B98EC_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264A10, 0x83264A10) { ctx.r3.u64 = HashName_TXT_820B98EC_B__2(ctx, base); }

uint64_t Construct_TXT_8349C04C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C04C_G_ = int32_t(0x8349C04C);
	constexpr int32_t str_TXT_820DCF30_B_ = int32_t(0x820DCF30);
	constexpr int32_t Destroy_TXT_8349C04C_G__address = int32_t(0x832A7418);
	if (!UseLiftedCode(144, 0x83264A48)) { __imp__sub_83264A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C04C_G_, str_TXT_820DCF30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C04C_G__address);
}
PROMOTED_ENTRY(144, sub_83264A48, 0x83264A48) { ctx.r3.u64 = Construct_TXT_8349C04C_G_(ctx, base); }

uint64_t Construct_TXT_8349C050_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C050_G_ = int32_t(0x8349C050);
	constexpr int32_t str_TXT_820B4564_B_ = int32_t(0x820B4564);
	constexpr int32_t Destroy_TXT_8349C050_G__address = int32_t(0x832A7428);
	if (!UseLiftedCode(144, 0x83264A88)) { __imp__sub_83264A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264A88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C050_G_, str_TXT_820B4564_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C050_G__address);
}
PROMOTED_ENTRY(144, sub_83264A88, 0x83264A88) { ctx.r3.u64 = Construct_TXT_8349C050_G_(ctx, base); }

uint64_t Construct_TXT_8349C054_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C054_G_ = int32_t(0x8349C054);
	constexpr int32_t str_TXT_820B05BC_B_ = int32_t(0x820B05BC);
	constexpr int32_t Destroy_TXT_8349C054_G__address = int32_t(0x832A7438);
	if (!UseLiftedCode(144, 0x83264AC8)) { __imp__sub_83264AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C054_G_, str_TXT_820B05BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C054_G__address);
}
PROMOTED_ENTRY(144, sub_83264AC8, 0x83264AC8) { ctx.r3.u64 = Construct_TXT_8349C054_G_(ctx, base); }

uint64_t Construct_TXT_8349C058_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C058_G_ = int32_t(0x8349C058);
	constexpr int32_t str_TXT_820B05C0_B_ = int32_t(0x820B05C0);
	constexpr int32_t Destroy_TXT_8349C058_G__address = int32_t(0x832A7448);
	if (!UseLiftedCode(144, 0x83264B08)) { __imp__sub_83264B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C058_G_, str_TXT_820B05C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C058_G__address);
}
PROMOTED_ENTRY(144, sub_83264B08, 0x83264B08) { ctx.r3.u64 = Construct_TXT_8349C058_G_(ctx, base); }

uint64_t Construct_TXT_8349C05C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C05C_G_ = int32_t(0x8349C05C);
	constexpr int32_t str_TXT_820A9290_B_ = int32_t(0x820A9290);
	constexpr int32_t Destroy_TXT_8349C05C_G__address = int32_t(0x832A7458);
	if (!UseLiftedCode(144, 0x83264B48)) { __imp__sub_83264B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C05C_G_, str_TXT_820A9290_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C05C_G__address);
}
PROMOTED_ENTRY(144, sub_83264B48, 0x83264B48) { ctx.r3.u64 = Construct_TXT_8349C05C_G_(ctx, base); }

uint64_t Construct_TXT_8349C060_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C060_G_ = int32_t(0x8349C060);
	constexpr int32_t str_TXT_820B05C8_B_ = int32_t(0x820B05C8);
	constexpr int32_t Destroy_TXT_8349C060_G__address = int32_t(0x832A7468);
	if (!UseLiftedCode(144, 0x83264B88)) { __imp__sub_83264B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C060_G_, str_TXT_820B05C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C060_G__address);
}
PROMOTED_ENTRY(144, sub_83264B88, 0x83264B88) { ctx.r3.u64 = Construct_TXT_8349C060_G_(ctx, base); }

uint64_t Construct_TXT_8349C064_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C064_G_ = int32_t(0x8349C064);
	constexpr int32_t str_TXT_820B05D4_B_ = int32_t(0x820B05D4);
	constexpr int32_t Destroy_TXT_8349C064_G__address = int32_t(0x832A7478);
	if (!UseLiftedCode(144, 0x83264BC8)) { __imp__sub_83264BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264BC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C064_G_, str_TXT_820B05D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C064_G__address);
}
PROMOTED_ENTRY(144, sub_83264BC8, 0x83264BC8) { ctx.r3.u64 = Construct_TXT_8349C064_G_(ctx, base); }

uint64_t Construct_TXT_8349C068_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C068_G_ = int32_t(0x8349C068);
	constexpr int32_t str_TXT_820B05E0_B_ = int32_t(0x820B05E0);
	constexpr int32_t Destroy_TXT_8349C068_G__address = int32_t(0x832A7488);
	if (!UseLiftedCode(144, 0x83264C08)) { __imp__sub_83264C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C068_G_, str_TXT_820B05E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C068_G__address);
}
PROMOTED_ENTRY(144, sub_83264C08, 0x83264C08) { ctx.r3.u64 = Construct_TXT_8349C068_G_(ctx, base); }

uint64_t Construct_TXT_8349C06C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C06C_G_ = int32_t(0x8349C06C);
	constexpr int32_t str_TXT_820DCF38_B_ = int32_t(0x820DCF38);
	constexpr int32_t Destroy_TXT_8349C06C_G__address = int32_t(0x832A7498);
	if (!UseLiftedCode(144, 0x83264C48)) { __imp__sub_83264C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C06C_G_, str_TXT_820DCF38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C06C_G__address);
}
PROMOTED_ENTRY(144, sub_83264C48, 0x83264C48) { ctx.r3.u64 = Construct_TXT_8349C06C_G_(ctx, base); }

uint64_t Construct_TXT_8349C070_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C070_G_ = int32_t(0x8349C070);
	constexpr int32_t str_TXT_820DCF5C_B_ = int32_t(0x820DCF5C);
	constexpr int32_t Destroy_TXT_8349C070_G__address = int32_t(0x832A74A8);
	if (!UseLiftedCode(144, 0x83264C88)) { __imp__sub_83264C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C070_G_, str_TXT_820DCF5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C070_G__address);
}
PROMOTED_ENTRY(144, sub_83264C88, 0x83264C88) { ctx.r3.u64 = Construct_TXT_8349C070_G_(ctx, base); }

uint64_t Construct_TXT_8349C074_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C074_G_ = int32_t(0x8349C074);
	constexpr int32_t str_TXT_820DD140_B_ = int32_t(0x820DD140);
	constexpr int32_t Destroy_TXT_8349C074_G__address = int32_t(0x832A74B8);
	if (!UseLiftedCode(144, 0x83264CC8)) { __imp__sub_83264CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C074_G_, str_TXT_820DD140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C074_G__address);
}
PROMOTED_ENTRY(144, sub_83264CC8, 0x83264CC8) { ctx.r3.u64 = Construct_TXT_8349C074_G_(ctx, base); }

uint64_t Construct_TXT_8349C084_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C084_G_ = int32_t(0x8349C084);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349C084_G__address = int32_t(0x832A7550);
	if (!UseLiftedCode(144, 0x83264D68)) { __imp__sub_83264D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264D68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C084_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C084_G__address);
}
PROMOTED_ENTRY(144, sub_83264D68, 0x83264D68) { ctx.r3.u64 = Construct_TXT_8349C084_G_(ctx, base); }

uint64_t Construct_TXT_8349C088_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C088_G_ = int32_t(0x8349C088);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349C088_G__address = int32_t(0x832A7560);
	if (!UseLiftedCode(144, 0x83264DA8)) { __imp__sub_83264DA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264DA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C088_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C088_G__address);
}
PROMOTED_ENTRY(144, sub_83264DA8, 0x83264DA8) { ctx.r3.u64 = Construct_TXT_8349C088_G_(ctx, base); }

uint64_t Construct_TXT_8349C08C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C08C_G_ = int32_t(0x8349C08C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349C08C_G__address = int32_t(0x832A7570);
	if (!UseLiftedCode(144, 0x83264DE8)) { __imp__sub_83264DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264DE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C08C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C08C_G__address);
}
PROMOTED_ENTRY(144, sub_83264DE8, 0x83264DE8) { ctx.r3.u64 = Construct_TXT_8349C08C_G_(ctx, base); }

uint64_t Construct_TXT_8349C090_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C090_G_ = int32_t(0x8349C090);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349C090_G__address = int32_t(0x832A7580);
	if (!UseLiftedCode(144, 0x83264E28)) { __imp__sub_83264E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264E28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C090_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C090_G__address);
}
PROMOTED_ENTRY(144, sub_83264E28, 0x83264E28) { ctx.r3.u64 = Construct_TXT_8349C090_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__24 = 0x8349C094u;
	if (!UseLiftedCode(144, 0x83264E68)) { __imp__sub_83264E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264E68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264E68, 0x83264E68) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__24(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__25 = 0x8349C098u;
	if (!UseLiftedCode(144, 0x83264EA0)) { __imp__sub_83264EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264EA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264EA0, 0x83264EA0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__25(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__25 = 0x8349C09Cu;
	if (!UseLiftedCode(144, 0x83264ED8)) { __imp__sub_83264ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264ED8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264ED8, 0x83264ED8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__24 = 0x8349C0A0u;
	if (!UseLiftedCode(144, 0x83264F10)) { __imp__sub_83264F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264F10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264F10, 0x83264F10) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__24 = 0x8349C0A4u;
	if (!UseLiftedCode(144, 0x83264F48)) { __imp__sub_83264F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264F48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264F48, 0x83264F48) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__24 = 0x8349C0A8u;
	if (!UseLiftedCode(144, 0x83264F80)) { __imp__sub_83264F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264F80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264F80, 0x83264F80) { ctx.r3.u64 = HashName_TXT_820A2C34_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__24 = 0x8349C0ACu;
	if (!UseLiftedCode(144, 0x83264FB8)) { __imp__sub_83264FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264FB8, 0x83264FB8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__24 = 0x8349C0B0u;
	if (!UseLiftedCode(144, 0x83264FF0)) { __imp__sub_83264FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83264FF0, 0x83264FF0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__24 = 0x8349C0B4u;
	if (!UseLiftedCode(144, 0x83265028)) { __imp__sub_83265028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265028);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265028, 0x83265028) { ctx.r3.u64 = HashName_TXT_820A2C74_B__24(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__24 = 0x8349C0B8u;
	if (!UseLiftedCode(144, 0x83265060)) { __imp__sub_83265060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265060);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265060, 0x83265060) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__24 = 0x8349C0BCu;
	if (!UseLiftedCode(144, 0x83265098)) { __imp__sub_83265098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265098);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265098, 0x83265098) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__24(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__24 = 0x8349C0C0u;
	if (!UseLiftedCode(144, 0x832650D0)) { __imp__sub_832650D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832650D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832650D0, 0x832650D0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__24(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__26 = 0x8349C0C4u;
	if (!UseLiftedCode(144, 0x83265108)) { __imp__sub_83265108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265108);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265108, 0x83265108) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__24 = 0x8349C0C8u;
	if (!UseLiftedCode(144, 0x83265140)) { __imp__sub_83265140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265140);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265140, 0x83265140) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__24(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__24 = 0x8349C0CCu;
	if (!UseLiftedCode(144, 0x83265178)) { __imp__sub_83265178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265178);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265178, 0x83265178) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__24(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__23 = 0x8349C0D0u;
	if (!UseLiftedCode(144, 0x832651B0)) { __imp__sub_832651B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832651B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832651B0, 0x832651B0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__23 = 0x8349C0D4u;
	if (!UseLiftedCode(144, 0x832651E8)) { __imp__sub_832651E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832651E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832651E8, 0x832651E8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__23(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__23 = 0x8349C0D8u;
	if (!UseLiftedCode(144, 0x83265220)) { __imp__sub_83265220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265220);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__23, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265220, 0x83265220) { ctx.r3.u64 = HashName_TXT_820A2D24_B__23(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__24 = 0x8349C0DCu;
	if (!UseLiftedCode(144, 0x83265258)) { __imp__sub_83265258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265258);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265258, 0x83265258) { ctx.r3.u64 = HashName_TXT_820A2D30_B__24(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__24 = 0x8349C0E0u;
	if (!UseLiftedCode(144, 0x83265290)) { __imp__sub_83265290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265290);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265290, 0x83265290) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__24 = 0x8349C0E4u;
	if (!UseLiftedCode(144, 0x832652C8)) { __imp__sub_832652C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832652C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832652C8, 0x832652C8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__24(ctx, base); }

uint64_t Construct_TXT_8349C0E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C0E8_G_ = int32_t(0x8349C0E8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349C0E8_G__address = int32_t(0x832A7590);
	if (!UseLiftedCode(144, 0x83265300)) { __imp__sub_83265300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265300);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0E8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C0E8_G__address);
}
PROMOTED_ENTRY(144, sub_83265300, 0x83265300) { ctx.r3.u64 = Construct_TXT_8349C0E8_G_(ctx, base); }

uint64_t Construct_TXT_8349C0EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C0EC_G_ = int32_t(0x8349C0EC);
	constexpr int32_t str_TXT_820DD260_B_ = int32_t(0x820DD260);
	constexpr int32_t Destroy_TXT_8349C0EC_G__address = int32_t(0x832A75A0);
	if (!UseLiftedCode(144, 0x83265340)) { __imp__sub_83265340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265340);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0EC_G_, str_TXT_820DD260_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C0EC_G__address);
}
PROMOTED_ENTRY(144, sub_83265340, 0x83265340) { ctx.r3.u64 = Construct_TXT_8349C0EC_G_(ctx, base); }

uint64_t Construct_TXT_8349C0F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C0F0_G_ = int32_t(0x8349C0F0);
	constexpr int32_t str_TXT_820DD274_B_ = int32_t(0x820DD274);
	constexpr int32_t Destroy_TXT_8349C0F0_G__address = int32_t(0x832A75B0);
	if (!UseLiftedCode(144, 0x83265380)) { __imp__sub_83265380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265380);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0F0_G_, str_TXT_820DD274_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C0F0_G__address);
}
PROMOTED_ENTRY(144, sub_83265380, 0x83265380) { ctx.r3.u64 = Construct_TXT_8349C0F0_G_(ctx, base); }

uint64_t HashName_TXT_820DD3BC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3BC_B_ = int32_t(0x820DD3BC);
	constexpr uint32_t g_HashOf_TXT_820DD3BC_B_ = 0x8349C0F4u;
	if (!UseLiftedCode(144, 0x832653C0)) { __imp__sub_832653C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832653C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3BC_B_);
	STORE32(g_HashOf_TXT_820DD3BC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832653C0, 0x832653C0) { ctx.r3.u64 = HashName_TXT_820DD3BC_B_(ctx, base); }

uint64_t HashName_TXT_820DD3D0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3D0_B_ = int32_t(0x820DD3D0);
	constexpr uint32_t g_HashOf_TXT_820DD3D0_B_ = 0x8349C0F8u;
	if (!UseLiftedCode(144, 0x832653F8)) { __imp__sub_832653F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832653F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3D0_B_);
	STORE32(g_HashOf_TXT_820DD3D0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832653F8, 0x832653F8) { ctx.r3.u64 = HashName_TXT_820DD3D0_B_(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__25 = 0x8349C0FCu;
	if (!UseLiftedCode(144, 0x83265430)) { __imp__sub_83265430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265430);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265430, 0x83265430) { ctx.r3.u64 = HashName_TXT_820A2C34_B__25(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__24 = 0x8349C100u;
	if (!UseLiftedCode(144, 0x83265468)) { __imp__sub_83265468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265468);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265468, 0x83265468) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__24(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__24 = 0x8349C104u;
	if (!UseLiftedCode(144, 0x832654A0)) { __imp__sub_832654A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832654A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832654A0, 0x832654A0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__24(ctx, base); }

uint64_t HashName_TXT_820DD3DC_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3DC_B_ = int32_t(0x820DD3DC);
	constexpr uint32_t g_HashOf_TXT_820DD3DC_B_ = 0x8349C108u;
	if (!UseLiftedCode(144, 0x832654D8)) { __imp__sub_832654D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832654D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3DC_B_);
	STORE32(g_HashOf_TXT_820DD3DC_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832654D8, 0x832654D8) { ctx.r3.u64 = HashName_TXT_820DD3DC_B_(ctx, base); }

uint64_t HashName_TXT_820DD3F0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3F0_B_ = int32_t(0x820DD3F0);
	constexpr uint32_t g_HashOf_TXT_820DD3F0_B_ = 0x8349C10Cu;
	if (!UseLiftedCode(144, 0x83265510)) { __imp__sub_83265510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265510);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3F0_B_);
	STORE32(g_HashOf_TXT_820DD3F0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265510, 0x83265510) { ctx.r3.u64 = HashName_TXT_820DD3F0_B_(ctx, base); }

uint64_t HashName_TXT_820DD404_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD404_B_ = int32_t(0x820DD404);
	constexpr uint32_t g_HashOf_TXT_820DD404_B_ = 0x8349C110u;
	if (!UseLiftedCode(144, 0x83265548)) { __imp__sub_83265548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265548);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD404_B_);
	STORE32(g_HashOf_TXT_820DD404_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265548, 0x83265548) { ctx.r3.u64 = HashName_TXT_820DD404_B_(ctx, base); }

uint64_t HashName_TXT_820DD418_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD418_B_ = int32_t(0x820DD418);
	constexpr uint32_t g_HashOf_TXT_820DD418_B_ = 0x8349C114u;
	if (!UseLiftedCode(144, 0x83265580)) { __imp__sub_83265580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265580);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD418_B_);
	STORE32(g_HashOf_TXT_820DD418_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265580, 0x83265580) { ctx.r3.u64 = HashName_TXT_820DD418_B_(ctx, base); }

uint64_t HashName_TXT_820DD42C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD42C_B_ = int32_t(0x820DD42C);
	constexpr uint32_t g_HashOf_TXT_820DD42C_B_ = 0x8349C118u;
	if (!UseLiftedCode(144, 0x832655B8)) { __imp__sub_832655B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832655B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD42C_B_);
	STORE32(g_HashOf_TXT_820DD42C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832655B8, 0x832655B8) { ctx.r3.u64 = HashName_TXT_820DD42C_B_(ctx, base); }

uint64_t Construct_TXT_8349C11C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C11C_G_ = int32_t(0x8349C11C);
	constexpr int32_t str_TXT_820B22FC_B_ = int32_t(0x820B22FC);
	constexpr int32_t Destroy_TXT_8349C11C_G__address = int32_t(0x832A75C0);
	if (!UseLiftedCode(144, 0x832655F0)) { __imp__sub_832655F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832655F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C11C_G_, str_TXT_820B22FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C11C_G__address);
}
PROMOTED_ENTRY(144, sub_832655F0, 0x832655F0) { ctx.r3.u64 = Construct_TXT_8349C11C_G_(ctx, base); }

uint64_t Construct_TXT_8349C120_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C120_G_ = int32_t(0x8349C120);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349C120_G__address = int32_t(0x832A75D0);
	if (!UseLiftedCode(144, 0x83265630)) { __imp__sub_83265630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C120_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C120_G__address);
}
PROMOTED_ENTRY(144, sub_83265630, 0x83265630) { ctx.r3.u64 = Construct_TXT_8349C120_G_(ctx, base); }

uint64_t Construct_TXT_8349C124_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C124_G_ = int32_t(0x8349C124);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349C124_G__address = int32_t(0x832A75E0);
	if (!UseLiftedCode(144, 0x83265670)) { __imp__sub_83265670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C124_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C124_G__address);
}
PROMOTED_ENTRY(144, sub_83265670, 0x83265670) { ctx.r3.u64 = Construct_TXT_8349C124_G_(ctx, base); }

uint64_t Construct_TXT_8349C128_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C128_G_ = int32_t(0x8349C128);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349C128_G__address = int32_t(0x832A75F0);
	if (!UseLiftedCode(144, 0x832656B0)) { __imp__sub_832656B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832656B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C128_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C128_G__address);
}
PROMOTED_ENTRY(144, sub_832656B0, 0x832656B0) { ctx.r3.u64 = Construct_TXT_8349C128_G_(ctx, base); }

uint64_t Construct_TXT_8349C12C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C12C_G_ = int32_t(0x8349C12C);
	constexpr int32_t str_TXT_820DF820_B_ = int32_t(0x820DF820);
	constexpr int32_t Destroy_TXT_8349C12C_G__address = int32_t(0x832A7610);
	if (!UseLiftedCode(144, 0x832656F0)) { __imp__sub_832656F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832656F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C12C_G_, str_TXT_820DF820_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C12C_G__address);
}
PROMOTED_ENTRY(144, sub_832656F0, 0x832656F0) { ctx.r3.u64 = Construct_TXT_8349C12C_G_(ctx, base); }

uint64_t Construct_TXT_8349C130_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C130_G_ = int32_t(0x8349C130);
	constexpr int32_t str_TXT_820DF82C_B_ = int32_t(0x820DF82C);
	constexpr int32_t Destroy_TXT_8349C130_G__address = int32_t(0x832A7620);
	if (!UseLiftedCode(144, 0x83265730)) { __imp__sub_83265730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C130_G_, str_TXT_820DF82C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C130_G__address);
}
PROMOTED_ENTRY(144, sub_83265730, 0x83265730) { ctx.r3.u64 = Construct_TXT_8349C130_G_(ctx, base); }

uint64_t Construct_TXT_8349C134_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C134_G_ = int32_t(0x8349C134);
	constexpr int32_t str_TXT_820DF838_B_ = int32_t(0x820DF838);
	constexpr int32_t Destroy_TXT_8349C134_G__address = int32_t(0x832A7630);
	if (!UseLiftedCode(144, 0x83265770)) { __imp__sub_83265770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C134_G_, str_TXT_820DF838_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C134_G__address);
}
PROMOTED_ENTRY(144, sub_83265770, 0x83265770) { ctx.r3.u64 = Construct_TXT_8349C134_G_(ctx, base); }

uint64_t Construct_TXT_8349C138_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C138_G_ = int32_t(0x8349C138);
	constexpr int32_t str_TXT_820DF844_B_ = int32_t(0x820DF844);
	constexpr int32_t Destroy_TXT_8349C138_G__address = int32_t(0x832A7640);
	if (!UseLiftedCode(144, 0x832657B0)) { __imp__sub_832657B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832657B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C138_G_, str_TXT_820DF844_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C138_G__address);
}
PROMOTED_ENTRY(144, sub_832657B0, 0x832657B0) { ctx.r3.u64 = Construct_TXT_8349C138_G_(ctx, base); }

uint64_t Construct_TXT_8349C13C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C13C_G_ = int32_t(0x8349C13C);
	constexpr int32_t str_TXT_820DF854_B_ = int32_t(0x820DF854);
	constexpr int32_t Destroy_TXT_8349C13C_G__address = int32_t(0x832A7650);
	if (!UseLiftedCode(144, 0x832657F0)) { __imp__sub_832657F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832657F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C13C_G_, str_TXT_820DF854_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C13C_G__address);
}
PROMOTED_ENTRY(144, sub_832657F0, 0x832657F0) { ctx.r3.u64 = Construct_TXT_8349C13C_G_(ctx, base); }

uint64_t Construct_TXT_8349C140_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C140_G_ = int32_t(0x8349C140);
	constexpr int32_t str_TXT_820DF820_B_ = int32_t(0x820DF820);
	constexpr int32_t Destroy_TXT_8349C140_G__address = int32_t(0x832A7660);
	if (!UseLiftedCode(144, 0x83265830)) { __imp__sub_83265830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C140_G_, str_TXT_820DF820_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C140_G__address);
}
PROMOTED_ENTRY(144, sub_83265830, 0x83265830) { ctx.r3.u64 = Construct_TXT_8349C140_G_(ctx, base); }

uint64_t Construct_TXT_8349C144_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C144_G_ = int32_t(0x8349C144);
	constexpr int32_t str_TXT_820DF838_B_ = int32_t(0x820DF838);
	constexpr int32_t Destroy_TXT_8349C144_G__address = int32_t(0x832A7670);
	if (!UseLiftedCode(144, 0x83265870)) { __imp__sub_83265870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C144_G_, str_TXT_820DF838_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C144_G__address);
}
PROMOTED_ENTRY(144, sub_83265870, 0x83265870) { ctx.r3.u64 = Construct_TXT_8349C144_G_(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__27 = 0x8349C148u;
	if (!UseLiftedCode(144, 0x832658B0)) { __imp__sub_832658B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832658B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832658B0, 0x832658B0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__25 = 0x8349C14Cu;
	if (!UseLiftedCode(144, 0x832658E8)) { __imp__sub_832658E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832658E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832658E8, 0x832658E8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__25(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__26 = 0x8349C150u;
	if (!UseLiftedCode(144, 0x83265920)) { __imp__sub_83265920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265920);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265920, 0x83265920) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__24(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__24 = 0x8349C154u;
	if (!UseLiftedCode(144, 0x83265958)) { __imp__sub_83265958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265958);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__24, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265958, 0x83265958) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__24(ctx, base); }

uint64_t HashName_TXT_820D09C8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D09C8_B_ = int32_t(0x820D09C8);
	constexpr uint32_t g_HashOf_TXT_820D09C8_B_ = 0x8349C158u;
	if (!UseLiftedCode(144, 0x83265990)) { __imp__sub_83265990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265990);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820D09C8_B_);
	STORE32(g_HashOf_TXT_820D09C8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265990, 0x83265990) { ctx.r3.u64 = HashName_TXT_820D09C8_B_(ctx, base); }

uint64_t HashName_TXT_820DFA80_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFA80_B_ = int32_t(0x820DFA80);
	constexpr uint32_t g_HashOf_TXT_820DFA80_B_ = 0x8349C15Cu;
	if (!UseLiftedCode(144, 0x832659C8)) { __imp__sub_832659C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832659C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFA80_B_);
	STORE32(g_HashOf_TXT_820DFA80_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832659C8, 0x832659C8) { ctx.r3.u64 = HashName_TXT_820DFA80_B_(ctx, base); }

uint64_t HashName_TXT_820DFE3C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE3C_B_ = int32_t(0x820DFE3C);
	constexpr uint32_t g_HashOf_TXT_820DFE3C_B_ = 0x8349C160u;
	if (!UseLiftedCode(144, 0x83265A00)) { __imp__sub_83265A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265A00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE3C_B_);
	STORE32(g_HashOf_TXT_820DFE3C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265A00, 0x83265A00) { ctx.r3.u64 = HashName_TXT_820DFE3C_B_(ctx, base); }

uint64_t HashName_TXT_820DFE4C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE4C_B_ = int32_t(0x820DFE4C);
	constexpr uint32_t g_HashOf_TXT_820DFE4C_B_ = 0x8349C164u;
	if (!UseLiftedCode(144, 0x83265A38)) { __imp__sub_83265A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265A38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE4C_B_);
	STORE32(g_HashOf_TXT_820DFE4C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265A38, 0x83265A38) { ctx.r3.u64 = HashName_TXT_820DFE4C_B_(ctx, base); }

uint64_t HashName_TXT_820DFE60_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE60_B_ = int32_t(0x820DFE60);
	constexpr uint32_t g_HashOf_TXT_820DFE60_B_ = 0x8349C168u;
	if (!UseLiftedCode(144, 0x83265A70)) { __imp__sub_83265A70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265A70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE60_B_);
	STORE32(g_HashOf_TXT_820DFE60_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265A70, 0x83265A70) { ctx.r3.u64 = HashName_TXT_820DFE60_B_(ctx, base); }

uint64_t HashName_TXT_820DFE74_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE74_B_ = int32_t(0x820DFE74);
	constexpr uint32_t g_HashOf_TXT_820DFE74_B_ = 0x8349C16Cu;
	if (!UseLiftedCode(144, 0x83265AA8)) { __imp__sub_83265AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE74_B_);
	STORE32(g_HashOf_TXT_820DFE74_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265AA8, 0x83265AA8) { ctx.r3.u64 = HashName_TXT_820DFE74_B_(ctx, base); }

uint64_t HashName_TXT_820DFE84_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE84_B_ = int32_t(0x820DFE84);
	constexpr uint32_t g_HashOf_TXT_820DFE84_B_ = 0x8349C170u;
	if (!UseLiftedCode(144, 0x83265AE0)) { __imp__sub_83265AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265AE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE84_B_);
	STORE32(g_HashOf_TXT_820DFE84_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265AE0, 0x83265AE0) { ctx.r3.u64 = HashName_TXT_820DFE84_B_(ctx, base); }

uint64_t HashName_TXT_820DFE94_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFE94_B_ = int32_t(0x820DFE94);
	constexpr uint32_t g_HashOf_TXT_820DFE94_B_ = 0x8349C174u;
	if (!UseLiftedCode(144, 0x83265B18)) { __imp__sub_83265B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265B18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFE94_B_);
	STORE32(g_HashOf_TXT_820DFE94_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265B18, 0x83265B18) { ctx.r3.u64 = HashName_TXT_820DFE94_B_(ctx, base); }

uint64_t HashName_TXT_820DFEA4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFEA4_B_ = int32_t(0x820DFEA4);
	constexpr uint32_t g_HashOf_TXT_820DFEA4_B_ = 0x8349C178u;
	if (!UseLiftedCode(144, 0x83265B50)) { __imp__sub_83265B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265B50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFEA4_B_);
	STORE32(g_HashOf_TXT_820DFEA4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265B50, 0x83265B50) { ctx.r3.u64 = HashName_TXT_820DFEA4_B_(ctx, base); }

uint64_t HashName_TXT_820DD3D0_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3D0_B_ = int32_t(0x820DD3D0);
	constexpr uint32_t g_HashOf_TXT_820DD3D0_B__2 = 0x8349C17Cu;
	if (!UseLiftedCode(144, 0x83265B88)) { __imp__sub_83265B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265B88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3D0_B_);
	STORE32(g_HashOf_TXT_820DD3D0_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265B88, 0x83265B88) { ctx.r3.u64 = HashName_TXT_820DD3D0_B__2(ctx, base); }

uint64_t HashName_TXT_820DD3DC_B__2(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DD3DC_B_ = int32_t(0x820DD3DC);
	constexpr uint32_t g_HashOf_TXT_820DD3DC_B__2 = 0x8349C180u;
	if (!UseLiftedCode(144, 0x83265BC0)) { __imp__sub_83265BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265BC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DD3DC_B_);
	STORE32(g_HashOf_TXT_820DD3DC_B__2, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265BC0, 0x83265BC0) { ctx.r3.u64 = HashName_TXT_820DD3DC_B__2(ctx, base); }

uint64_t HashName_TXT_820DFEB8_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFEB8_B_ = int32_t(0x820DFEB8);
	constexpr uint32_t g_HashOf_TXT_820DFEB8_B_ = 0x8349C184u;
	if (!UseLiftedCode(144, 0x83265BF8)) { __imp__sub_83265BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFEB8_B_);
	STORE32(g_HashOf_TXT_820DFEB8_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265BF8, 0x83265BF8) { ctx.r3.u64 = HashName_TXT_820DFEB8_B_(ctx, base); }

uint64_t HashName_TXT_820DFED0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFED0_B_ = int32_t(0x820DFED0);
	constexpr uint32_t g_HashOf_TXT_820DFED0_B_ = 0x8349C188u;
	if (!UseLiftedCode(144, 0x83265C30)) { __imp__sub_83265C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265C30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFED0_B_);
	STORE32(g_HashOf_TXT_820DFED0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265C30, 0x83265C30) { ctx.r3.u64 = HashName_TXT_820DFED0_B_(ctx, base); }

uint64_t HashName_TXT_820DFEE0_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFEE0_B_ = int32_t(0x820DFEE0);
	constexpr uint32_t g_HashOf_TXT_820DFEE0_B_ = 0x8349C18Cu;
	if (!UseLiftedCode(144, 0x83265C68)) { __imp__sub_83265C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265C68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFEE0_B_);
	STORE32(g_HashOf_TXT_820DFEE0_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265C68, 0x83265C68) { ctx.r3.u64 = HashName_TXT_820DFEE0_B_(ctx, base); }

uint64_t HashName_TXT_820DFEF4_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFEF4_B_ = int32_t(0x820DFEF4);
	constexpr uint32_t g_HashOf_TXT_820DFEF4_B_ = 0x8349C190u;
	if (!UseLiftedCode(144, 0x83265CA0)) { __imp__sub_83265CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFEF4_B_);
	STORE32(g_HashOf_TXT_820DFEF4_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265CA0, 0x83265CA0) { ctx.r3.u64 = HashName_TXT_820DFEF4_B_(ctx, base); }

uint64_t HashName_TXT_820DFF0C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFF0C_B_ = int32_t(0x820DFF0C);
	constexpr uint32_t g_HashOf_TXT_820DFF0C_B_ = 0x8349C194u;
	if (!UseLiftedCode(144, 0x83265CD8)) { __imp__sub_83265CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265CD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFF0C_B_);
	STORE32(g_HashOf_TXT_820DFF0C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265CD8, 0x83265CD8) { ctx.r3.u64 = HashName_TXT_820DFF0C_B_(ctx, base); }

uint64_t HashName_TXT_820DFF24_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFF24_B_ = int32_t(0x820DFF24);
	constexpr uint32_t g_HashOf_TXT_820DFF24_B_ = 0x8349C198u;
	if (!UseLiftedCode(144, 0x83265D10)) { __imp__sub_83265D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265D10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFF24_B_);
	STORE32(g_HashOf_TXT_820DFF24_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265D10, 0x83265D10) { ctx.r3.u64 = HashName_TXT_820DFF24_B_(ctx, base); }

uint64_t HashName_TXT_820DFF40_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFF40_B_ = int32_t(0x820DFF40);
	constexpr uint32_t g_HashOf_TXT_820DFF40_B_ = 0x8349C19Cu;
	if (!UseLiftedCode(144, 0x83265D48)) { __imp__sub_83265D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265D48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFF40_B_);
	STORE32(g_HashOf_TXT_820DFF40_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265D48, 0x83265D48) { ctx.r3.u64 = HashName_TXT_820DFF40_B_(ctx, base); }

uint64_t HashName_TXT_820DFF5C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFF5C_B_ = int32_t(0x820DFF5C);
	constexpr uint32_t g_HashOf_TXT_820DFF5C_B_ = 0x8349C1A0u;
	if (!UseLiftedCode(144, 0x83265D80)) { __imp__sub_83265D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265D80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFF5C_B_);
	STORE32(g_HashOf_TXT_820DFF5C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265D80, 0x83265D80) { ctx.r3.u64 = HashName_TXT_820DFF5C_B_(ctx, base); }

uint64_t HashName_TXT_820DFF6C_B_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820DFF6C_B_ = int32_t(0x820DFF6C);
	constexpr uint32_t g_HashOf_TXT_820DFF6C_B_ = 0x8349C1A4u;
	if (!UseLiftedCode(144, 0x83265DB8)) { __imp__sub_83265DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820DFF6C_B_);
	STORE32(g_HashOf_TXT_820DFF6C_B_, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83265DB8, 0x83265DB8) { ctx.r3.u64 = HashName_TXT_820DFF6C_B_(ctx, base); }

uint64_t RegisterExitDestructor832A76B0(CpuState& ctx, uint8_t* base, uint64_t destructorArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A76B0_address = int32_t(0x832A76B0);
	if (!UseLiftedCode(144, 0x83266008)) { ctx.r8.u64 = destructorArgument; __imp__sub_83266008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266008);
	ctx.r11.s64 = g_832A0000;
	return RegisterAtExit(ctx, base, n_sub_832A76B0_address, destructorArgument);
}
PROMOTED_ENTRY(144, sub_83266008, 0x83266008) { ctx.r3.u64 = RegisterExitDestructor832A76B0(ctx, base, ctx.r8.u64); }

uint64_t HashName_TXT_820A2BD4_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__25 = 0x8349C204u;
	if (!UseLiftedCode(144, 0x83266018)) { __imp__sub_83266018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266018);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266018, 0x83266018) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__25(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__27 = 0x8349C208u;
	if (!UseLiftedCode(144, 0x83266050)) { __imp__sub_83266050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266050);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266050, 0x83266050) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__27(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__26 = 0x8349C20Cu;
	if (!UseLiftedCode(144, 0x83266088)) { __imp__sub_83266088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266088);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266088, 0x83266088) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__25 = 0x8349C210u;
	if (!UseLiftedCode(144, 0x832660C0)) { __imp__sub_832660C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832660C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832660C0, 0x832660C0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__25 = 0x8349C214u;
	if (!UseLiftedCode(144, 0x832660F8)) { __imp__sub_832660F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832660F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832660F8, 0x832660F8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__26 = 0x8349C218u;
	if (!UseLiftedCode(144, 0x83266130)) { __imp__sub_83266130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266130, 0x83266130) { ctx.r3.u64 = HashName_TXT_820A2C34_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__25 = 0x8349C21Cu;
	if (!UseLiftedCode(144, 0x83266168)) { __imp__sub_83266168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266168, 0x83266168) { ctx.r3.u64 = HashName_TXT_820A2C44_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__25 = 0x8349C220u;
	if (!UseLiftedCode(144, 0x832661A0)) { __imp__sub_832661A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832661A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832661A0, 0x832661A0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__25 = 0x8349C224u;
	if (!UseLiftedCode(144, 0x832661D8)) { __imp__sub_832661D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832661D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832661D8, 0x832661D8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__25(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__25 = 0x8349C228u;
	if (!UseLiftedCode(144, 0x83266210)) { __imp__sub_83266210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266210, 0x83266210) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__25 = 0x8349C22Cu;
	if (!UseLiftedCode(144, 0x83266248)) { __imp__sub_83266248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266248, 0x83266248) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__25 = 0x8349C230u;
	if (!UseLiftedCode(144, 0x83266280)) { __imp__sub_83266280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266280, 0x83266280) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__28 = 0x8349C234u;
	if (!UseLiftedCode(144, 0x832662B8)) { __imp__sub_832662B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832662B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832662B8, 0x832662B8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__25 = 0x8349C238u;
	if (!UseLiftedCode(144, 0x832662F0)) { __imp__sub_832662F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832662F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832662F0, 0x832662F0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__25 = 0x8349C23Cu;
	if (!UseLiftedCode(144, 0x83266328)) { __imp__sub_83266328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266328, 0x83266328) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__25(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__25 = 0x8349C240u;
	if (!UseLiftedCode(144, 0x83266360)) { __imp__sub_83266360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266360, 0x83266360) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__25(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__25 = 0x8349C244u;
	if (!UseLiftedCode(144, 0x83266398)) { __imp__sub_83266398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266398, 0x83266398) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__26 = 0x8349C248u;
	if (!UseLiftedCode(144, 0x832663D0)) { __imp__sub_832663D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832663D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832663D0, 0x832663D0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__26(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__25 = 0x8349C24Cu;
	if (!UseLiftedCode(144, 0x83266408)) { __imp__sub_83266408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266408);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266408, 0x83266408) { ctx.r3.u64 = HashName_TXT_820A2D30_B__25(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__25 = 0x8349C250u;
	if (!UseLiftedCode(144, 0x83266440)) { __imp__sub_83266440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266440, 0x83266440) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__25(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__25(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__25 = 0x8349C254u;
	if (!UseLiftedCode(144, 0x83266478)) { __imp__sub_83266478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__25, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266478, 0x83266478) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__25(ctx, base); }

uint64_t Construct_TXT_8349C258_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C258_G_ = int32_t(0x8349C258);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349C258_G__address = int32_t(0x832A7708);
	if (!UseLiftedCode(144, 0x832664B0)) { __imp__sub_832664B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832664B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C258_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C258_G__address);
}
PROMOTED_ENTRY(144, sub_832664B0, 0x832664B0) { ctx.r3.u64 = Construct_TXT_8349C258_G_(ctx, base); }

uint64_t Construct_TXT_8349C25C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C25C_G_ = int32_t(0x8349C25C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349C25C_G__address = int32_t(0x832A7718);
	if (!UseLiftedCode(144, 0x832664F0)) { __imp__sub_832664F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832664F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C25C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C25C_G__address);
}
PROMOTED_ENTRY(144, sub_832664F0, 0x832664F0) { ctx.r3.u64 = Construct_TXT_8349C25C_G_(ctx, base); }

uint64_t Construct_TXT_8349C260_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C260_G_ = int32_t(0x8349C260);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349C260_G__address = int32_t(0x832A7728);
	if (!UseLiftedCode(144, 0x83266530)) { __imp__sub_83266530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C260_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C260_G__address);
}
PROMOTED_ENTRY(144, sub_83266530, 0x83266530) { ctx.r3.u64 = Construct_TXT_8349C260_G_(ctx, base); }

uint64_t Construct_TXT_8349C264_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C264_G_ = int32_t(0x8349C264);
	constexpr int32_t str_TXT_820A8F8C_B_ = int32_t(0x820A8F8C);
	constexpr int32_t Destroy_TXT_8349C264_G__address = int32_t(0x832A7738);
	if (!UseLiftedCode(144, 0x83266570)) { __imp__sub_83266570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C264_G_, str_TXT_820A8F8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C264_G__address);
}
PROMOTED_ENTRY(144, sub_83266570, 0x83266570) { ctx.r3.u64 = Construct_TXT_8349C264_G_(ctx, base); }

uint64_t Construct_TXT_8349C268_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C268_G_ = int32_t(0x8349C268);
	constexpr int32_t str_TXT_820A8F94_B_ = int32_t(0x820A8F94);
	constexpr int32_t Destroy_TXT_8349C268_G__address = int32_t(0x832A7748);
	if (!UseLiftedCode(144, 0x832665B0)) { __imp__sub_832665B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832665B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C268_G_, str_TXT_820A8F94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C268_G__address);
}
PROMOTED_ENTRY(144, sub_832665B0, 0x832665B0) { ctx.r3.u64 = Construct_TXT_8349C268_G_(ctx, base); }

uint64_t Construct_TXT_8349C26C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C26C_G_ = int32_t(0x8349C26C);
	constexpr int32_t str_TXT_820A8F9C_B_ = int32_t(0x820A8F9C);
	constexpr int32_t Destroy_TXT_8349C26C_G__address = int32_t(0x832A7758);
	if (!UseLiftedCode(144, 0x832665F0)) { __imp__sub_832665F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832665F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C26C_G_, str_TXT_820A8F9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C26C_G__address);
}
PROMOTED_ENTRY(144, sub_832665F0, 0x832665F0) { ctx.r3.u64 = Construct_TXT_8349C26C_G_(ctx, base); }

uint64_t Construct_TXT_8349C270_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C270_G_ = int32_t(0x8349C270);
	constexpr int32_t str_TXT_820A8FA8_B_ = int32_t(0x820A8FA8);
	constexpr int32_t Destroy_TXT_8349C270_G__address = int32_t(0x832A7768);
	if (!UseLiftedCode(144, 0x83266630)) { __imp__sub_83266630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C270_G_, str_TXT_820A8FA8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C270_G__address);
}
PROMOTED_ENTRY(144, sub_83266630, 0x83266630) { ctx.r3.u64 = Construct_TXT_8349C270_G_(ctx, base); }

uint64_t Construct_TXT_8349C274_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C274_G_ = int32_t(0x8349C274);
	constexpr int32_t str_TXT_820A8FB0_B_ = int32_t(0x820A8FB0);
	constexpr int32_t Destroy_TXT_8349C274_G__address = int32_t(0x832A7778);
	if (!UseLiftedCode(144, 0x83266670)) { __imp__sub_83266670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C274_G_, str_TXT_820A8FB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C274_G__address);
}
PROMOTED_ENTRY(144, sub_83266670, 0x83266670) { ctx.r3.u64 = Construct_TXT_8349C274_G_(ctx, base); }

uint64_t Construct_TXT_8349C278_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C278_G_ = int32_t(0x8349C278);
	constexpr int32_t str_TXT_820A8FBC_B_ = int32_t(0x820A8FBC);
	constexpr int32_t Destroy_TXT_8349C278_G__address = int32_t(0x832A7788);
	if (!UseLiftedCode(144, 0x832666B0)) { __imp__sub_832666B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832666B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C278_G_, str_TXT_820A8FBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C278_G__address);
}
PROMOTED_ENTRY(144, sub_832666B0, 0x832666B0) { ctx.r3.u64 = Construct_TXT_8349C278_G_(ctx, base); }

uint64_t Construct_TXT_8349C27C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C27C_G_ = int32_t(0x8349C27C);
	constexpr int32_t str_TXT_820A8FCC_B_ = int32_t(0x820A8FCC);
	constexpr int32_t Destroy_TXT_8349C27C_G__address = int32_t(0x832A7798);
	if (!UseLiftedCode(144, 0x832666F0)) { __imp__sub_832666F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832666F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C27C_G_, str_TXT_820A8FCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C27C_G__address);
}
PROMOTED_ENTRY(144, sub_832666F0, 0x832666F0) { ctx.r3.u64 = Construct_TXT_8349C27C_G_(ctx, base); }

uint64_t Construct_TXT_8349C280_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C280_G_ = int32_t(0x8349C280);
	constexpr int32_t str_TXT_820A8FD4_B_ = int32_t(0x820A8FD4);
	constexpr int32_t Destroy_TXT_8349C280_G__address = int32_t(0x832A77A8);
	if (!UseLiftedCode(144, 0x83266730)) { __imp__sub_83266730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C280_G_, str_TXT_820A8FD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C280_G__address);
}
PROMOTED_ENTRY(144, sub_83266730, 0x83266730) { ctx.r3.u64 = Construct_TXT_8349C280_G_(ctx, base); }

uint64_t Construct_TXT_8349C284_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C284_G_ = int32_t(0x8349C284);
	constexpr int32_t str_TXT_820A8FE4_B_ = int32_t(0x820A8FE4);
	constexpr int32_t Destroy_TXT_8349C284_G__address = int32_t(0x832A77B8);
	if (!UseLiftedCode(144, 0x83266770)) { __imp__sub_83266770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C284_G_, str_TXT_820A8FE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C284_G__address);
}
PROMOTED_ENTRY(144, sub_83266770, 0x83266770) { ctx.r3.u64 = Construct_TXT_8349C284_G_(ctx, base); }

uint64_t Construct_TXT_8349C288_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C288_G_ = int32_t(0x8349C288);
	constexpr int32_t str_TXT_820A8FEC_B_ = int32_t(0x820A8FEC);
	constexpr int32_t Destroy_TXT_8349C288_G__address = int32_t(0x832A77C8);
	if (!UseLiftedCode(144, 0x832667B0)) { __imp__sub_832667B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832667B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C288_G_, str_TXT_820A8FEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C288_G__address);
}
PROMOTED_ENTRY(144, sub_832667B0, 0x832667B0) { ctx.r3.u64 = Construct_TXT_8349C288_G_(ctx, base); }

uint64_t Construct_TXT_8349C28C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C28C_G_ = int32_t(0x8349C28C);
	constexpr int32_t str_TXT_820A8FF4_B_ = int32_t(0x820A8FF4);
	constexpr int32_t Destroy_TXT_8349C28C_G__address = int32_t(0x832A77D8);
	if (!UseLiftedCode(144, 0x832667F0)) { __imp__sub_832667F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832667F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C28C_G_, str_TXT_820A8FF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C28C_G__address);
}
PROMOTED_ENTRY(144, sub_832667F0, 0x832667F0) { ctx.r3.u64 = Construct_TXT_8349C28C_G_(ctx, base); }

uint64_t Construct_TXT_8349C290_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C290_G_ = int32_t(0x8349C290);
	constexpr int32_t str_TXT_820A9000_B_ = int32_t(0x820A9000);
	constexpr int32_t Destroy_TXT_8349C290_G__address = int32_t(0x832A77E8);
	if (!UseLiftedCode(144, 0x83266830)) { __imp__sub_83266830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C290_G_, str_TXT_820A9000_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C290_G__address);
}
PROMOTED_ENTRY(144, sub_83266830, 0x83266830) { ctx.r3.u64 = Construct_TXT_8349C290_G_(ctx, base); }

uint64_t Construct_TXT_8349C294_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C294_G_ = int32_t(0x8349C294);
	constexpr int32_t str_TXT_820A9008_B_ = int32_t(0x820A9008);
	constexpr int32_t Destroy_TXT_8349C294_G__address = int32_t(0x832A77F8);
	if (!UseLiftedCode(144, 0x83266870)) { __imp__sub_83266870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C294_G_, str_TXT_820A9008_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C294_G__address);
}
PROMOTED_ENTRY(144, sub_83266870, 0x83266870) { ctx.r3.u64 = Construct_TXT_8349C294_G_(ctx, base); }

uint64_t Construct_TXT_8349C298_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C298_G_ = int32_t(0x8349C298);
	constexpr int32_t str_TXT_820A9010_B_ = int32_t(0x820A9010);
	constexpr int32_t Destroy_TXT_8349C298_G__address = int32_t(0x832A7808);
	if (!UseLiftedCode(144, 0x832668B0)) { __imp__sub_832668B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832668B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C298_G_, str_TXT_820A9010_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C298_G__address);
}
PROMOTED_ENTRY(144, sub_832668B0, 0x832668B0) { ctx.r3.u64 = Construct_TXT_8349C298_G_(ctx, base); }

uint64_t Construct_TXT_8349C29C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C29C_G_ = int32_t(0x8349C29C);
	constexpr int32_t str_TXT_820A9018_B_ = int32_t(0x820A9018);
	constexpr int32_t Destroy_TXT_8349C29C_G__address = int32_t(0x832A7818);
	if (!UseLiftedCode(144, 0x832668F0)) { __imp__sub_832668F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832668F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C29C_G_, str_TXT_820A9018_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C29C_G__address);
}
PROMOTED_ENTRY(144, sub_832668F0, 0x832668F0) { ctx.r3.u64 = Construct_TXT_8349C29C_G_(ctx, base); }

uint64_t Construct_TXT_8349C2A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2A0_G_ = int32_t(0x8349C2A0);
	constexpr int32_t str_TXT_820A9020_B_ = int32_t(0x820A9020);
	constexpr int32_t Destroy_TXT_8349C2A0_G__address = int32_t(0x832A7828);
	if (!UseLiftedCode(144, 0x83266930)) { __imp__sub_83266930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266930);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A0_G_, str_TXT_820A9020_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2A0_G__address);
}
PROMOTED_ENTRY(144, sub_83266930, 0x83266930) { ctx.r3.u64 = Construct_TXT_8349C2A0_G_(ctx, base); }

uint64_t Construct_TXT_8349C2A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2A4_G_ = int32_t(0x8349C2A4);
	constexpr int32_t str_TXT_820A9028_B_ = int32_t(0x820A9028);
	constexpr int32_t Destroy_TXT_8349C2A4_G__address = int32_t(0x832A7838);
	if (!UseLiftedCode(144, 0x83266970)) { __imp__sub_83266970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266970);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A4_G_, str_TXT_820A9028_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2A4_G__address);
}
PROMOTED_ENTRY(144, sub_83266970, 0x83266970) { ctx.r3.u64 = Construct_TXT_8349C2A4_G_(ctx, base); }

uint64_t Construct_TXT_8349C2A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2A8_G_ = int32_t(0x8349C2A8);
	constexpr int32_t str_TXT_820A9030_B_ = int32_t(0x820A9030);
	constexpr int32_t Destroy_TXT_8349C2A8_G__address = int32_t(0x832A7848);
	if (!UseLiftedCode(144, 0x832669B0)) { __imp__sub_832669B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832669B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A8_G_, str_TXT_820A9030_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2A8_G__address);
}
PROMOTED_ENTRY(144, sub_832669B0, 0x832669B0) { ctx.r3.u64 = Construct_TXT_8349C2A8_G_(ctx, base); }

uint64_t Construct_TXT_8349C2AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2AC_G_ = int32_t(0x8349C2AC);
	constexpr int32_t str_TXT_820A9038_B_ = int32_t(0x820A9038);
	constexpr int32_t Destroy_TXT_8349C2AC_G__address = int32_t(0x832A7858);
	if (!UseLiftedCode(144, 0x832669F0)) { __imp__sub_832669F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832669F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2AC_G_, str_TXT_820A9038_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2AC_G__address);
}
PROMOTED_ENTRY(144, sub_832669F0, 0x832669F0) { ctx.r3.u64 = Construct_TXT_8349C2AC_G_(ctx, base); }

uint64_t Construct_TXT_8349C2B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2B0_G_ = int32_t(0x8349C2B0);
	constexpr int32_t str_TXT_820A9044_B_ = int32_t(0x820A9044);
	constexpr int32_t Destroy_TXT_8349C2B0_G__address = int32_t(0x832A7868);
	if (!UseLiftedCode(144, 0x83266A30)) { __imp__sub_83266A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266A30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B0_G_, str_TXT_820A9044_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2B0_G__address);
}
PROMOTED_ENTRY(144, sub_83266A30, 0x83266A30) { ctx.r3.u64 = Construct_TXT_8349C2B0_G_(ctx, base); }

uint64_t Construct_TXT_8349C2B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2B4_G_ = int32_t(0x8349C2B4);
	constexpr int32_t str_TXT_820A5998_B_ = int32_t(0x820A5998);
	constexpr int32_t Destroy_TXT_8349C2B4_G__address = int32_t(0x832A7878);
	if (!UseLiftedCode(144, 0x83266A70)) { __imp__sub_83266A70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266A70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B4_G_, str_TXT_820A5998_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2B4_G__address);
}
PROMOTED_ENTRY(144, sub_83266A70, 0x83266A70) { ctx.r3.u64 = Construct_TXT_8349C2B4_G_(ctx, base); }

uint64_t Construct_TXT_8349C2B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2B8_G_ = int32_t(0x8349C2B8);
	constexpr int32_t str_TXT_820E1C48_B_ = int32_t(0x820E1C48);
	constexpr int32_t Destroy_TXT_8349C2B8_G__address = int32_t(0x832A7888);
	if (!UseLiftedCode(144, 0x83266AB0)) { __imp__sub_83266AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B8_G_, str_TXT_820E1C48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2B8_G__address);
}
PROMOTED_ENTRY(144, sub_83266AB0, 0x83266AB0) { ctx.r3.u64 = Construct_TXT_8349C2B8_G_(ctx, base); }

uint64_t Construct_TXT_8349C2BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2BC_G_ = int32_t(0x8349C2BC);
	constexpr int32_t str_TXT_820E1C58_B_ = int32_t(0x820E1C58);
	constexpr int32_t Destroy_TXT_8349C2BC_G__address = int32_t(0x832A7898);
	if (!UseLiftedCode(144, 0x83266AF0)) { __imp__sub_83266AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266AF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2BC_G_, str_TXT_820E1C58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2BC_G__address);
}
PROMOTED_ENTRY(144, sub_83266AF0, 0x83266AF0) { ctx.r3.u64 = Construct_TXT_8349C2BC_G_(ctx, base); }

uint64_t Construct_TXT_8349C2C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2C0_G_ = int32_t(0x8349C2C0);
	constexpr int32_t str_TXT_820E1C64_B_ = int32_t(0x820E1C64);
	constexpr int32_t Destroy_TXT_8349C2C0_G__address = int32_t(0x832A78A8);
	if (!UseLiftedCode(144, 0x83266B30)) { __imp__sub_83266B30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266B30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C0_G_, str_TXT_820E1C64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2C0_G__address);
}
PROMOTED_ENTRY(144, sub_83266B30, 0x83266B30) { ctx.r3.u64 = Construct_TXT_8349C2C0_G_(ctx, base); }

uint64_t Construct_TXT_8349C2C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2C4_G_ = int32_t(0x8349C2C4);
	constexpr int32_t str_TXT_820E1C70_B_ = int32_t(0x820E1C70);
	constexpr int32_t Destroy_TXT_8349C2C4_G__address = int32_t(0x832A78B8);
	if (!UseLiftedCode(144, 0x83266B70)) { __imp__sub_83266B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266B70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C4_G_, str_TXT_820E1C70_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2C4_G__address);
}
PROMOTED_ENTRY(144, sub_83266B70, 0x83266B70) { ctx.r3.u64 = Construct_TXT_8349C2C4_G_(ctx, base); }

uint64_t Construct_TXT_8349C2C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2C8_G_ = int32_t(0x8349C2C8);
	constexpr int32_t str_TXT_820E1C78_B_ = int32_t(0x820E1C78);
	constexpr int32_t Destroy_TXT_8349C2C8_G__address = int32_t(0x832A78C8);
	if (!UseLiftedCode(144, 0x83266BB0)) { __imp__sub_83266BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C8_G_, str_TXT_820E1C78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2C8_G__address);
}
PROMOTED_ENTRY(144, sub_83266BB0, 0x83266BB0) { ctx.r3.u64 = Construct_TXT_8349C2C8_G_(ctx, base); }

uint64_t Construct_TXT_8349C2CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C2CC_G_ = int32_t(0x8349C2CC);
	constexpr int32_t str_TXT_820A90D8_B_ = int32_t(0x820A90D8);
	constexpr int32_t Destroy_TXT_8349C2CC_G__address = int32_t(0x832A78D8);
	if (!UseLiftedCode(144, 0x83266BF0)) { __imp__sub_83266BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266BF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2CC_G_, str_TXT_820A90D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C2CC_G__address);
}
PROMOTED_ENTRY(144, sub_83266BF0, 0x83266BF0) { ctx.r3.u64 = Construct_TXT_8349C2CC_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__26 = 0x8349C2D0u;
	if (!UseLiftedCode(144, 0x83266C30)) { __imp__sub_83266C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266C30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266C30, 0x83266C30) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__26(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__28 = 0x8349C2D4u;
	if (!UseLiftedCode(144, 0x83266C68)) { __imp__sub_83266C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266C68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266C68, 0x83266C68) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__28(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__27 = 0x8349C2D8u;
	if (!UseLiftedCode(144, 0x83266CA0)) { __imp__sub_83266CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266CA0, 0x83266CA0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__26 = 0x8349C2DCu;
	if (!UseLiftedCode(144, 0x83266CD8)) { __imp__sub_83266CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266CD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266CD8, 0x83266CD8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__26 = 0x8349C2E0u;
	if (!UseLiftedCode(144, 0x83266D10)) { __imp__sub_83266D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266D10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266D10, 0x83266D10) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__27 = 0x8349C2E4u;
	if (!UseLiftedCode(144, 0x83266D48)) { __imp__sub_83266D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266D48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266D48, 0x83266D48) { ctx.r3.u64 = HashName_TXT_820A2C34_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__26 = 0x8349C2E8u;
	if (!UseLiftedCode(144, 0x83266D80)) { __imp__sub_83266D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266D80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266D80, 0x83266D80) { ctx.r3.u64 = HashName_TXT_820A2C44_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__26 = 0x8349C2ECu;
	if (!UseLiftedCode(144, 0x83266DB8)) { __imp__sub_83266DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266DB8, 0x83266DB8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__26 = 0x8349C2F0u;
	if (!UseLiftedCode(144, 0x83266DF0)) { __imp__sub_83266DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266DF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266DF0, 0x83266DF0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__26(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__26 = 0x8349C2F4u;
	if (!UseLiftedCode(144, 0x83266E28)) { __imp__sub_83266E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266E28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266E28, 0x83266E28) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__26 = 0x8349C2F8u;
	if (!UseLiftedCode(144, 0x83266E60)) { __imp__sub_83266E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266E60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266E60, 0x83266E60) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__26 = 0x8349C2FCu;
	if (!UseLiftedCode(144, 0x83266E98)) { __imp__sub_83266E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266E98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266E98, 0x83266E98) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__29 = 0x8349C300u;
	if (!UseLiftedCode(144, 0x83266ED0)) { __imp__sub_83266ED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266ED0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266ED0, 0x83266ED0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__26 = 0x8349C304u;
	if (!UseLiftedCode(144, 0x83266F08)) { __imp__sub_83266F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266F08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266F08, 0x83266F08) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__26 = 0x8349C308u;
	if (!UseLiftedCode(144, 0x83266F40)) { __imp__sub_83266F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266F40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266F40, 0x83266F40) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__26(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__26 = 0x8349C30Cu;
	if (!UseLiftedCode(144, 0x83266F78)) { __imp__sub_83266F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266F78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266F78, 0x83266F78) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__26(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__26 = 0x8349C310u;
	if (!UseLiftedCode(144, 0x83266FB0)) { __imp__sub_83266FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266FB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266FB0, 0x83266FB0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__27 = 0x8349C314u;
	if (!UseLiftedCode(144, 0x83266FE8)) { __imp__sub_83266FE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266FE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83266FE8, 0x83266FE8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__26 = 0x8349C318u;
	if (!UseLiftedCode(144, 0x83267020)) { __imp__sub_83267020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267020);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267020, 0x83267020) { ctx.r3.u64 = HashName_TXT_820A2D30_B__26(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__26 = 0x8349C31Cu;
	if (!UseLiftedCode(144, 0x83267058)) { __imp__sub_83267058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267058);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267058, 0x83267058) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__26(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__26(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__26 = 0x8349C320u;
	if (!UseLiftedCode(144, 0x83267090)) { __imp__sub_83267090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267090);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__26, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267090, 0x83267090) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__26(ctx, base); }

uint64_t Construct_TXT_8349C324_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C324_G_ = int32_t(0x8349C324);
	constexpr int32_t str_TXT_820E1D94_B_ = int32_t(0x820E1D94);
	constexpr int32_t Destroy_TXT_8349C324_G__address = int32_t(0x832A78E8);
	if (!UseLiftedCode(144, 0x832670C8)) { __imp__sub_832670C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832670C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C324_G_, str_TXT_820E1D94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C324_G__address);
}
PROMOTED_ENTRY(144, sub_832670C8, 0x832670C8) { ctx.r3.u64 = Construct_TXT_8349C324_G_(ctx, base); }

uint64_t Construct_TXT_8349C328_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C328_G_ = int32_t(0x8349C328);
	constexpr int32_t str_TXT_820E1DC4_B_ = int32_t(0x820E1DC4);
	constexpr int32_t Destroy_TXT_8349C328_G__address = int32_t(0x832A78F8);
	if (!UseLiftedCode(144, 0x83267108)) { __imp__sub_83267108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C328_G_, str_TXT_820E1DC4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C328_G__address);
}
PROMOTED_ENTRY(144, sub_83267108, 0x83267108) { ctx.r3.u64 = Construct_TXT_8349C328_G_(ctx, base); }

uint64_t Construct_TXT_8349C32C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C32C_G_ = int32_t(0x8349C32C);
	constexpr int32_t str_TXT_820E1DF4_B_ = int32_t(0x820E1DF4);
	constexpr int32_t Destroy_TXT_8349C32C_G__address = int32_t(0x832A7908);
	if (!UseLiftedCode(144, 0x83267148)) { __imp__sub_83267148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C32C_G_, str_TXT_820E1DF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C32C_G__address);
}
PROMOTED_ENTRY(144, sub_83267148, 0x83267148) { ctx.r3.u64 = Construct_TXT_8349C32C_G_(ctx, base); }

uint64_t Construct_TXT_8349C330_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C330_G_ = int32_t(0x8349C330);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E20);
	constexpr int32_t Destroy_TXT_8349C330_G__address = int32_t(0x832A7918);
	if (!UseLiftedCode(144, 0x83267188)) { __imp__sub_83267188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C330_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C330_G__address);
}
PROMOTED_ENTRY(144, sub_83267188, 0x83267188) { ctx.r3.u64 = Construct_TXT_8349C330_G_(ctx, base); }

uint64_t Construct_TXT_8349C334_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C334_G_ = int32_t(0x8349C334);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E50);
	constexpr int32_t Destroy_TXT_8349C334_G__address = int32_t(0x832A7928);
	if (!UseLiftedCode(144, 0x832671C8)) { __imp__sub_832671C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832671C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C334_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C334_G__address);
}
PROMOTED_ENTRY(144, sub_832671C8, 0x832671C8) { ctx.r3.u64 = Construct_TXT_8349C334_G_(ctx, base); }

uint64_t Construct_TXT_8349C338_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C338_G_ = int32_t(0x8349C338);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E1E88);
	constexpr int32_t Destroy_TXT_8349C338_G__address = int32_t(0x832A7938);
	if (!UseLiftedCode(144, 0x83267208)) { __imp__sub_83267208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C338_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C338_G__address);
}
PROMOTED_ENTRY(144, sub_83267208, 0x83267208) { ctx.r3.u64 = Construct_TXT_8349C338_G_(ctx, base); }

uint64_t Construct_TXT_8349C33C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C33C_G_ = int32_t(0x8349C33C);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820C00F4);
	constexpr int32_t Destroy_TXT_8349C33C_G__address = int32_t(0x832A7948);
	if (!UseLiftedCode(144, 0x83267248)) { __imp__sub_83267248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C33C_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C33C_G__address);
}
PROMOTED_ENTRY(144, sub_83267248, 0x83267248) { ctx.r3.u64 = Construct_TXT_8349C33C_G_(ctx, base); }

uint64_t Construct_TXT_8349C340_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C340_G_ = int32_t(0x8349C340);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820C00B0);
	constexpr int32_t Destroy_TXT_8349C340_G__address = int32_t(0x832A7958);
	if (!UseLiftedCode(144, 0x83267288)) { __imp__sub_83267288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C340_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C340_G__address);
}
PROMOTED_ENTRY(144, sub_83267288, 0x83267288) { ctx.r3.u64 = Construct_TXT_8349C340_G_(ctx, base); }

uint64_t Construct_TXT_8349C344_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C344_G_ = int32_t(0x8349C344);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E1EC0);
	constexpr int32_t Destroy_TXT_8349C344_G__address = int32_t(0x832A7968);
	if (!UseLiftedCode(144, 0x832672C8)) { __imp__sub_832672C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832672C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C344_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C344_G__address);
}
PROMOTED_ENTRY(144, sub_832672C8, 0x832672C8) { ctx.r3.u64 = Construct_TXT_8349C344_G_(ctx, base); }

uint64_t Construct_TXT_8349C348_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C348_G_ = int32_t(0x8349C348);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E1F00);
	constexpr int32_t Destroy_TXT_8349C348_G__address = int32_t(0x832A7978);
	if (!UseLiftedCode(144, 0x83267308)) { __imp__sub_83267308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C348_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C348_G__address);
}
PROMOTED_ENTRY(144, sub_83267308, 0x83267308) { ctx.r3.u64 = Construct_TXT_8349C348_G_(ctx, base); }

uint64_t Construct_TXT_8349C34C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C34C_G_ = int32_t(0x8349C34C);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F48);
	constexpr int32_t Destroy_TXT_8349C34C_G__address = int32_t(0x832A7988);
	if (!UseLiftedCode(144, 0x83267348)) { __imp__sub_83267348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C34C_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C34C_G__address);
}
PROMOTED_ENTRY(144, sub_83267348, 0x83267348) { ctx.r3.u64 = Construct_TXT_8349C34C_G_(ctx, base); }

uint64_t Construct_TXT_8349C350_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C350_G_ = int32_t(0x8349C350);
	constexpr int32_t str_TXT_820E1F48_B_ = int32_t(0x820E1F8C);
	constexpr int32_t Destroy_TXT_8349C350_G__address = int32_t(0x832A7998);
	if (!UseLiftedCode(144, 0x83267388)) { __imp__sub_83267388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C350_G_, str_TXT_820E1F48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C350_G__address);
}
PROMOTED_ENTRY(144, sub_83267388, 0x83267388) { ctx.r3.u64 = Construct_TXT_8349C350_G_(ctx, base); }

uint64_t Construct_TXT_8349C354_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C354_G_ = int32_t(0x8349C354);
	constexpr int32_t str_TXT_820E209C_B_ = int32_t(0x820E209C);
	constexpr int32_t Destroy_TXT_8349C354_G__address = int32_t(0x832A79A8);
	if (!UseLiftedCode(144, 0x832673C8)) { __imp__sub_832673C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832673C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C354_G_, str_TXT_820E209C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C354_G__address);
}
PROMOTED_ENTRY(144, sub_832673C8, 0x832673C8) { ctx.r3.u64 = Construct_TXT_8349C354_G_(ctx, base); }

uint64_t Construct_TXT_8349C358_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C358_G_ = int32_t(0x8349C358);
	constexpr int32_t str_TXT_820E209C_B_ = int32_t(0x820E20D0);
	constexpr int32_t Destroy_TXT_8349C358_G__address = int32_t(0x832A79B8);
	if (!UseLiftedCode(144, 0x83267408)) { __imp__sub_83267408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C358_G_, str_TXT_820E209C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C358_G__address);
}
PROMOTED_ENTRY(144, sub_83267408, 0x83267408) { ctx.r3.u64 = Construct_TXT_8349C358_G_(ctx, base); }

uint64_t Construct_TXT_8349C35C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C35C_G_ = int32_t(0x8349C35C);
	constexpr int32_t str_TXT_820E209C_B_ = int32_t(0x820E210C);
	constexpr int32_t Destroy_TXT_8349C35C_G__address = int32_t(0x832A79C8);
	if (!UseLiftedCode(144, 0x83267448)) { __imp__sub_83267448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C35C_G_, str_TXT_820E209C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C35C_G__address);
}
PROMOTED_ENTRY(144, sub_83267448, 0x83267448) { ctx.r3.u64 = Construct_TXT_8349C35C_G_(ctx, base); }

uint64_t Construct_TXT_8349C360_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C360_G_ = int32_t(0x8349C360);
	constexpr int32_t str_TXT_820E209C_B_ = int32_t(0x820BFE58);
	constexpr int32_t Destroy_TXT_8349C360_G__address = int32_t(0x832A79D8);
	if (!UseLiftedCode(144, 0x83267488)) { __imp__sub_83267488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C360_G_, str_TXT_820E209C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C360_G__address);
}
PROMOTED_ENTRY(144, sub_83267488, 0x83267488) { ctx.r3.u64 = Construct_TXT_8349C360_G_(ctx, base); }

uint64_t Construct_TXT_8349C364_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C364_G_ = int32_t(0x8349C364);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E1EC0);
	constexpr int32_t Destroy_TXT_8349C364_G__address = int32_t(0x832A79E8);
	if (!UseLiftedCode(144, 0x832674C8)) { __imp__sub_832674C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832674C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C364_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C364_G__address);
}
PROMOTED_ENTRY(144, sub_832674C8, 0x832674C8) { ctx.r3.u64 = Construct_TXT_8349C364_G_(ctx, base); }

uint64_t Construct_TXT_8349C368_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C368_G_ = int32_t(0x8349C368);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E1F00);
	constexpr int32_t Destroy_TXT_8349C368_G__address = int32_t(0x832A79F8);
	if (!UseLiftedCode(144, 0x83267508)) { __imp__sub_83267508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C368_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C368_G__address);
}
PROMOTED_ENTRY(144, sub_83267508, 0x83267508) { ctx.r3.u64 = Construct_TXT_8349C368_G_(ctx, base); }

uint64_t Construct_TXT_8349C36C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C36C_G_ = int32_t(0x8349C36C);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E2144);
	constexpr int32_t Destroy_TXT_8349C36C_G__address = int32_t(0x832A7A08);
	if (!UseLiftedCode(144, 0x83267548)) { __imp__sub_83267548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C36C_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C36C_G__address);
}
PROMOTED_ENTRY(144, sub_83267548, 0x83267548) { ctx.r3.u64 = Construct_TXT_8349C36C_G_(ctx, base); }

uint64_t Construct_TXT_8349C370_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C370_G_ = int32_t(0x8349C370);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E2180);
	constexpr int32_t Destroy_TXT_8349C370_G__address = int32_t(0x832A7A18);
	if (!UseLiftedCode(144, 0x83267588)) { __imp__sub_83267588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C370_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C370_G__address);
}
PROMOTED_ENTRY(144, sub_83267588, 0x83267588) { ctx.r3.u64 = Construct_TXT_8349C370_G_(ctx, base); }

uint64_t Construct_TXT_8349C374_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C374_G_ = int32_t(0x8349C374);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E20);
	constexpr int32_t Destroy_TXT_8349C374_G__address = int32_t(0x832A7A28);
	if (!UseLiftedCode(144, 0x832675C8)) { __imp__sub_832675C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832675C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C374_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C374_G__address);
}
PROMOTED_ENTRY(144, sub_832675C8, 0x832675C8) { ctx.r3.u64 = Construct_TXT_8349C374_G_(ctx, base); }

uint64_t Construct_TXT_8349C378_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C378_G_ = int32_t(0x8349C378);
	constexpr int32_t str_TXT_820E1E20_B_ = int32_t(0x820E1E50);
	constexpr int32_t Destroy_TXT_8349C378_G__address = int32_t(0x832A7A38);
	if (!UseLiftedCode(144, 0x83267608)) { __imp__sub_83267608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C378_G_, str_TXT_820E1E20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C378_G__address);
}
PROMOTED_ENTRY(144, sub_83267608, 0x83267608) { ctx.r3.u64 = Construct_TXT_8349C378_G_(ctx, base); }

uint64_t Construct_TXT_8349C37C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C37C_G_ = int32_t(0x8349C37C);
	constexpr int32_t str_TXT_820E1E88_B_ = int32_t(0x820E21C4);
	constexpr int32_t Destroy_TXT_8349C37C_G__address = int32_t(0x832A7A48);
	if (!UseLiftedCode(144, 0x83267648)) { __imp__sub_83267648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C37C_G_, str_TXT_820E1E88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C37C_G__address);
}
PROMOTED_ENTRY(144, sub_83267648, 0x83267648) { ctx.r3.u64 = Construct_TXT_8349C37C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__27 = 0x8349C380u;
	if (!UseLiftedCode(144, 0x83267688)) { __imp__sub_83267688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267688);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267688, 0x83267688) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__27(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__29 = 0x8349C384u;
	if (!UseLiftedCode(144, 0x832676C0)) { __imp__sub_832676C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832676C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832676C0, 0x832676C0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__29(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__28 = 0x8349C388u;
	if (!UseLiftedCode(144, 0x832676F8)) { __imp__sub_832676F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832676F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832676F8, 0x832676F8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__27 = 0x8349C38Cu;
	if (!UseLiftedCode(144, 0x83267730)) { __imp__sub_83267730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267730);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267730, 0x83267730) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__27 = 0x8349C390u;
	if (!UseLiftedCode(144, 0x83267768)) { __imp__sub_83267768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267768);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267768, 0x83267768) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__28 = 0x8349C394u;
	if (!UseLiftedCode(144, 0x832677A0)) { __imp__sub_832677A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832677A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832677A0, 0x832677A0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__27 = 0x8349C398u;
	if (!UseLiftedCode(144, 0x832677D8)) { __imp__sub_832677D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832677D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832677D8, 0x832677D8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__27 = 0x8349C39Cu;
	if (!UseLiftedCode(144, 0x83267810)) { __imp__sub_83267810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267810);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267810, 0x83267810) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__27 = 0x8349C3A0u;
	if (!UseLiftedCode(144, 0x83267848)) { __imp__sub_83267848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267848);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267848, 0x83267848) { ctx.r3.u64 = HashName_TXT_820A2C74_B__27(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__27 = 0x8349C3A4u;
	if (!UseLiftedCode(144, 0x83267880)) { __imp__sub_83267880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267880);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267880, 0x83267880) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__27 = 0x8349C3A8u;
	if (!UseLiftedCode(144, 0x832678B8)) { __imp__sub_832678B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832678B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832678B8, 0x832678B8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__27(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__27 = 0x8349C3ACu;
	if (!UseLiftedCode(144, 0x832678F0)) { __imp__sub_832678F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832678F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832678F0, 0x832678F0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__27(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__30 = 0x8349C3B0u;
	if (!UseLiftedCode(144, 0x83267928)) { __imp__sub_83267928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267928);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267928, 0x83267928) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__27 = 0x8349C3B4u;
	if (!UseLiftedCode(144, 0x83267960)) { __imp__sub_83267960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267960);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267960, 0x83267960) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__27(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__27 = 0x8349C3B8u;
	if (!UseLiftedCode(144, 0x83267998)) { __imp__sub_83267998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267998);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267998, 0x83267998) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__27(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__27 = 0x8349C3BCu;
	if (!UseLiftedCode(144, 0x832679D0)) { __imp__sub_832679D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832679D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832679D0, 0x832679D0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__27 = 0x8349C3C0u;
	if (!UseLiftedCode(144, 0x83267A08)) { __imp__sub_83267A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267A08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267A08, 0x83267A08) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__28 = 0x8349C3C4u;
	if (!UseLiftedCode(144, 0x83267A40)) { __imp__sub_83267A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267A40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267A40, 0x83267A40) { ctx.r3.u64 = HashName_TXT_820A2D24_B__28(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__27 = 0x8349C3C8u;
	if (!UseLiftedCode(144, 0x83267A78)) { __imp__sub_83267A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267A78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267A78, 0x83267A78) { ctx.r3.u64 = HashName_TXT_820A2D30_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__27 = 0x8349C3CCu;
	if (!UseLiftedCode(144, 0x83267AB0)) { __imp__sub_83267AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267AB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267AB0, 0x83267AB0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__27(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__27(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__27 = 0x8349C3D0u;
	if (!UseLiftedCode(144, 0x83267AE8)) { __imp__sub_83267AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__27, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267AE8, 0x83267AE8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__27(ctx, base); }

uint64_t Construct_TXT_8349C3D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3D4_G_ = int32_t(0x8349C3D4);
	constexpr int32_t str_TXT_820E235C_B_ = int32_t(0x820E235C);
	constexpr int32_t Destroy_TXT_8349C3D4_G__address = int32_t(0x832A7A58);
	if (!UseLiftedCode(144, 0x83267B20)) { __imp__sub_83267B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267B20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3D4_G_, str_TXT_820E235C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3D4_G__address);
}
PROMOTED_ENTRY(144, sub_83267B20, 0x83267B20) { ctx.r3.u64 = Construct_TXT_8349C3D4_G_(ctx, base); }

uint64_t Construct_TXT_8349C3D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3D8_G_ = int32_t(0x8349C3D8);
	constexpr int32_t str_TXT_820E238C_B_ = int32_t(0x820E238C);
	constexpr int32_t Destroy_TXT_8349C3D8_G__address = int32_t(0x832A7A68);
	if (!UseLiftedCode(144, 0x83267B60)) { __imp__sub_83267B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267B60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3D8_G_, str_TXT_820E238C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3D8_G__address);
}
PROMOTED_ENTRY(144, sub_83267B60, 0x83267B60) { ctx.r3.u64 = Construct_TXT_8349C3D8_G_(ctx, base); }

uint64_t Construct_TXT_8349C3DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3DC_G_ = int32_t(0x8349C3DC);
	constexpr int32_t str_TXT_820E23BC_B_ = int32_t(0x820E23BC);
	constexpr int32_t Destroy_TXT_8349C3DC_G__address = int32_t(0x832A7A78);
	if (!UseLiftedCode(144, 0x83267BA0)) { __imp__sub_83267BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267BA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3DC_G_, str_TXT_820E23BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3DC_G__address);
}
PROMOTED_ENTRY(144, sub_83267BA0, 0x83267BA0) { ctx.r3.u64 = Construct_TXT_8349C3DC_G_(ctx, base); }

uint64_t Construct_TXT_8349C3E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3E0_G_ = int32_t(0x8349C3E0);
	constexpr int32_t str_TXT_820E23F0_B_ = int32_t(0x820E23F0);
	constexpr int32_t Destroy_TXT_8349C3E0_G__address = int32_t(0x832A7A88);
	if (!UseLiftedCode(144, 0x83267BE0)) { __imp__sub_83267BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267BE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E0_G_, str_TXT_820E23F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3E0_G__address);
}
PROMOTED_ENTRY(144, sub_83267BE0, 0x83267BE0) { ctx.r3.u64 = Construct_TXT_8349C3E0_G_(ctx, base); }

uint64_t Construct_TXT_8349C3E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3E4_G_ = int32_t(0x8349C3E4);
	constexpr int32_t str_TXT_820E2420_B_ = int32_t(0x820E2420);
	constexpr int32_t Destroy_TXT_8349C3E4_G__address = int32_t(0x832A7A98);
	if (!UseLiftedCode(144, 0x83267C20)) { __imp__sub_83267C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267C20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E4_G_, str_TXT_820E2420_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3E4_G__address);
}
PROMOTED_ENTRY(144, sub_83267C20, 0x83267C20) { ctx.r3.u64 = Construct_TXT_8349C3E4_G_(ctx, base); }

uint64_t Construct_TXT_8349C3E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3E8_G_ = int32_t(0x8349C3E8);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349C3E8_G__address = int32_t(0x832A7AA8);
	if (!UseLiftedCode(144, 0x83267C60)) { __imp__sub_83267C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267C60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E8_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3E8_G__address);
}
PROMOTED_ENTRY(144, sub_83267C60, 0x83267C60) { ctx.r3.u64 = Construct_TXT_8349C3E8_G_(ctx, base); }

uint64_t Construct_TXT_8349C3EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3EC_G_ = int32_t(0x8349C3EC);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E2488);
	constexpr int32_t Destroy_TXT_8349C3EC_G__address = int32_t(0x832A7AB8);
	if (!UseLiftedCode(144, 0x83267CA0)) { __imp__sub_83267CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3EC_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3EC_G__address);
}
PROMOTED_ENTRY(144, sub_83267CA0, 0x83267CA0) { ctx.r3.u64 = Construct_TXT_8349C3EC_G_(ctx, base); }

uint64_t Construct_TXT_8349C3F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3F0_G_ = int32_t(0x8349C3F0);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E24BC);
	constexpr int32_t Destroy_TXT_8349C3F0_G__address = int32_t(0x832A7AC8);
	if (!UseLiftedCode(144, 0x83267CE0)) { __imp__sub_83267CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267CE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F0_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3F0_G__address);
}
PROMOTED_ENTRY(144, sub_83267CE0, 0x83267CE0) { ctx.r3.u64 = Construct_TXT_8349C3F0_G_(ctx, base); }

uint64_t Construct_TXT_8349C3F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3F4_G_ = int32_t(0x8349C3F4);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E2488);
	constexpr int32_t Destroy_TXT_8349C3F4_G__address = int32_t(0x832A7AD8);
	if (!UseLiftedCode(144, 0x83267D20)) { __imp__sub_83267D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267D20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F4_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3F4_G__address);
}
PROMOTED_ENTRY(144, sub_83267D20, 0x83267D20) { ctx.r3.u64 = Construct_TXT_8349C3F4_G_(ctx, base); }

uint64_t Construct_TXT_8349C3F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C3F8_G_ = int32_t(0x8349C3F8);
	constexpr int32_t str_TXT_820E2488_B_ = int32_t(0x820E24BC);
	constexpr int32_t Destroy_TXT_8349C3F8_G__address = int32_t(0x832A7AE8);
	if (!UseLiftedCode(144, 0x83267D60)) { __imp__sub_83267D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267D60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F8_G_, str_TXT_820E2488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C3F8_G__address);
}
PROMOTED_ENTRY(144, sub_83267D60, 0x83267D60) { ctx.r3.u64 = Construct_TXT_8349C3F8_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__28 = 0x8349C3FCu;
	if (!UseLiftedCode(144, 0x83267DA0)) { __imp__sub_83267DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267DA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267DA0, 0x83267DA0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__28(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__30 = 0x8349C400u;
	if (!UseLiftedCode(144, 0x83267DD8)) { __imp__sub_83267DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267DD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267DD8, 0x83267DD8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__30(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__29 = 0x8349C404u;
	if (!UseLiftedCode(144, 0x83267E10)) { __imp__sub_83267E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267E10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267E10, 0x83267E10) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__28 = 0x8349C408u;
	if (!UseLiftedCode(144, 0x83267E48)) { __imp__sub_83267E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267E48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267E48, 0x83267E48) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__28 = 0x8349C40Cu;
	if (!UseLiftedCode(144, 0x83267E80)) { __imp__sub_83267E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267E80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267E80, 0x83267E80) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__29 = 0x8349C410u;
	if (!UseLiftedCode(144, 0x83267EB8)) { __imp__sub_83267EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267EB8, 0x83267EB8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__28 = 0x8349C414u;
	if (!UseLiftedCode(144, 0x83267EF0)) { __imp__sub_83267EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267EF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267EF0, 0x83267EF0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__28 = 0x8349C418u;
	if (!UseLiftedCode(144, 0x83267F28)) { __imp__sub_83267F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267F28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267F28, 0x83267F28) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__28 = 0x8349C41Cu;
	if (!UseLiftedCode(144, 0x83267F60)) { __imp__sub_83267F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267F60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267F60, 0x83267F60) { ctx.r3.u64 = HashName_TXT_820A2C74_B__28(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__28 = 0x8349C420u;
	if (!UseLiftedCode(144, 0x83267F98)) { __imp__sub_83267F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267F98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267F98, 0x83267F98) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__28 = 0x8349C424u;
	if (!UseLiftedCode(144, 0x83267FD0)) { __imp__sub_83267FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267FD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83267FD0, 0x83267FD0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__28 = 0x8349C428u;
	if (!UseLiftedCode(144, 0x83268008)) { __imp__sub_83268008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268008);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268008, 0x83268008) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__31 = 0x8349C42Cu;
	if (!UseLiftedCode(144, 0x83268040)) { __imp__sub_83268040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268040);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268040, 0x83268040) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__28 = 0x8349C430u;
	if (!UseLiftedCode(144, 0x83268078)) { __imp__sub_83268078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268078);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268078, 0x83268078) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__28 = 0x8349C434u;
	if (!UseLiftedCode(144, 0x832680B0)) { __imp__sub_832680B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832680B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832680B0, 0x832680B0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__28(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__28 = 0x8349C438u;
	if (!UseLiftedCode(144, 0x832680E8)) { __imp__sub_832680E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832680E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832680E8, 0x832680E8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__28(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__28 = 0x8349C43Cu;
	if (!UseLiftedCode(144, 0x83268120)) { __imp__sub_83268120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268120);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268120, 0x83268120) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__29 = 0x8349C440u;
	if (!UseLiftedCode(144, 0x83268158)) { __imp__sub_83268158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268158);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268158, 0x83268158) { ctx.r3.u64 = HashName_TXT_820A2D24_B__29(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__28 = 0x8349C444u;
	if (!UseLiftedCode(144, 0x83268190)) { __imp__sub_83268190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268190);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268190, 0x83268190) { ctx.r3.u64 = HashName_TXT_820A2D30_B__28(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__28 = 0x8349C448u;
	if (!UseLiftedCode(144, 0x832681C8)) { __imp__sub_832681C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832681C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832681C8, 0x832681C8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__28(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__28 = 0x8349C44Cu;
	if (!UseLiftedCode(144, 0x83268200)) { __imp__sub_83268200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268200);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__28, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268200, 0x83268200) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__28(ctx, base); }

uint64_t Construct_TXT_8349C4D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4D0_G_ = int32_t(0x8349C4D0);
	constexpr int32_t str_TXT_82000F58_B_ = int32_t(0x82000F58);
	constexpr int32_t Destroy_TXT_8349C4D0_G__address = int32_t(0x832A7BC8);
	if (!UseLiftedCode(144, 0x83268528)) { __imp__sub_83268528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268528);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D0_G_, str_TXT_82000F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4D0_G__address);
}
PROMOTED_ENTRY(144, sub_83268528, 0x83268528) { ctx.r3.u64 = Construct_TXT_8349C4D0_G_(ctx, base); }

uint64_t Construct_TXT_8349C4D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4D4_G_ = int32_t(0x8349C4D4);
	constexpr int32_t str_TXT_820E25CC_B_ = int32_t(0x820E25CC);
	constexpr int32_t Destroy_TXT_8349C4D4_G__address = int32_t(0x832A7BD8);
	if (!UseLiftedCode(144, 0x83268568)) { __imp__sub_83268568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268568);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D4_G_, str_TXT_820E25CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4D4_G__address);
}
PROMOTED_ENTRY(144, sub_83268568, 0x83268568) { ctx.r3.u64 = Construct_TXT_8349C4D4_G_(ctx, base); }

uint64_t Construct_TXT_8349C4D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4D8_G_ = int32_t(0x8349C4D8);
	constexpr int32_t str_TXT_820AF204_B_ = int32_t(0x820AF204);
	constexpr int32_t Destroy_TXT_8349C4D8_G__address = int32_t(0x832A7BE8);
	if (!UseLiftedCode(144, 0x832685A8)) { __imp__sub_832685A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832685A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D8_G_, str_TXT_820AF204_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4D8_G__address);
}
PROMOTED_ENTRY(144, sub_832685A8, 0x832685A8) { ctx.r3.u64 = Construct_TXT_8349C4D8_G_(ctx, base); }

uint64_t Construct_TXT_8349C4DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4DC_G_ = int32_t(0x8349C4DC);
	constexpr int32_t str_TXT_820C0C7C_B_ = int32_t(0x820C0C7C);
	constexpr int32_t Destroy_TXT_8349C4DC_G__address = int32_t(0x832A7BF8);
	if (!UseLiftedCode(144, 0x832685E8)) { __imp__sub_832685E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832685E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4DC_G_, str_TXT_820C0C7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4DC_G__address);
}
PROMOTED_ENTRY(144, sub_832685E8, 0x832685E8) { ctx.r3.u64 = Construct_TXT_8349C4DC_G_(ctx, base); }

uint64_t Construct_TXT_8349C4E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4E0_G_ = int32_t(0x8349C4E0);
	constexpr int32_t str_TXT_820C0C4C_B_ = int32_t(0x820C0C4C);
	constexpr int32_t Destroy_TXT_8349C4E0_G__address = int32_t(0x832A7C08);
	if (!UseLiftedCode(144, 0x83268628)) { __imp__sub_83268628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268628);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E0_G_, str_TXT_820C0C4C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4E0_G__address);
}
PROMOTED_ENTRY(144, sub_83268628, 0x83268628) { ctx.r3.u64 = Construct_TXT_8349C4E0_G_(ctx, base); }

uint64_t Construct_TXT_8349C4E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4E4_G_ = int32_t(0x8349C4E4);
	constexpr int32_t str_TXT_820C0BF0_B_ = int32_t(0x820C0BF0);
	constexpr int32_t Destroy_TXT_8349C4E4_G__address = int32_t(0x832A7C18);
	if (!UseLiftedCode(144, 0x83268668)) { __imp__sub_83268668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268668);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E4_G_, str_TXT_820C0BF0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4E4_G__address);
}
PROMOTED_ENTRY(144, sub_83268668, 0x83268668) { ctx.r3.u64 = Construct_TXT_8349C4E4_G_(ctx, base); }

uint64_t Construct_TXT_8349C4E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4E8_G_ = int32_t(0x8349C4E8);
	constexpr int32_t str_TXT_820C0CF8_B_ = int32_t(0x820C0CF8);
	constexpr int32_t Destroy_TXT_8349C4E8_G__address = int32_t(0x832A7C28);
	if (!UseLiftedCode(144, 0x832686A8)) { __imp__sub_832686A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832686A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E8_G_, str_TXT_820C0CF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4E8_G__address);
}
PROMOTED_ENTRY(144, sub_832686A8, 0x832686A8) { ctx.r3.u64 = Construct_TXT_8349C4E8_G_(ctx, base); }

uint64_t Construct_TXT_8349C4EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4EC_G_ = int32_t(0x8349C4EC);
	constexpr int32_t str_TXT_820C0CBC_B_ = int32_t(0x820C0CBC);
	constexpr int32_t Destroy_TXT_8349C4EC_G__address = int32_t(0x832A7C38);
	if (!UseLiftedCode(144, 0x832686E8)) { __imp__sub_832686E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832686E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4EC_G_, str_TXT_820C0CBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4EC_G__address);
}
PROMOTED_ENTRY(144, sub_832686E8, 0x832686E8) { ctx.r3.u64 = Construct_TXT_8349C4EC_G_(ctx, base); }

uint64_t Construct_TXT_8349C4F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4F0_G_ = int32_t(0x8349C4F0);
	constexpr int32_t str_TXT_820E25D8_B_ = int32_t(0x820E25D8);
	constexpr int32_t Destroy_TXT_8349C4F0_G__address = int32_t(0x832A7C48);
	if (!UseLiftedCode(144, 0x83268728)) { __imp__sub_83268728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268728);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F0_G_, str_TXT_820E25D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4F0_G__address);
}
PROMOTED_ENTRY(144, sub_83268728, 0x83268728) { ctx.r3.u64 = Construct_TXT_8349C4F0_G_(ctx, base); }

uint64_t Construct_TXT_8349C4F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4F4_G_ = int32_t(0x8349C4F4);
	constexpr int32_t str_TXT_820AF204_B_ = int32_t(0x820AF204);
	constexpr int32_t Destroy_TXT_8349C4F4_G__address = int32_t(0x832A7C58);
	if (!UseLiftedCode(144, 0x83268768)) { __imp__sub_83268768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268768);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F4_G_, str_TXT_820AF204_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4F4_G__address);
}
PROMOTED_ENTRY(144, sub_83268768, 0x83268768) { ctx.r3.u64 = Construct_TXT_8349C4F4_G_(ctx, base); }

uint64_t Construct_TXT_8349C4F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4F8_G_ = int32_t(0x8349C4F8);
	constexpr int32_t str_TXT_820E25E8_B_ = int32_t(0x820E25E8);
	constexpr int32_t Destroy_TXT_8349C4F8_G__address = int32_t(0x832A7C68);
	if (!UseLiftedCode(144, 0x832687A8)) { __imp__sub_832687A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832687A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F8_G_, str_TXT_820E25E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4F8_G__address);
}
PROMOTED_ENTRY(144, sub_832687A8, 0x832687A8) { ctx.r3.u64 = Construct_TXT_8349C4F8_G_(ctx, base); }

uint64_t Construct_TXT_8349C4FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C4FC_G_ = int32_t(0x8349C4FC);
	constexpr int32_t str_TXT_820E25F4_B_ = int32_t(0x820E25F4);
	constexpr int32_t Destroy_TXT_8349C4FC_G__address = int32_t(0x832A7C78);
	if (!UseLiftedCode(144, 0x832687E8)) { __imp__sub_832687E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832687E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4FC_G_, str_TXT_820E25F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C4FC_G__address);
}
PROMOTED_ENTRY(144, sub_832687E8, 0x832687E8) { ctx.r3.u64 = Construct_TXT_8349C4FC_G_(ctx, base); }

uint64_t Construct_TXT_8349C500_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C500_G_ = int32_t(0x8349C500);
	constexpr int32_t str_TXT_820E2614_B_ = int32_t(0x820E2614);
	constexpr int32_t Destroy_TXT_8349C500_G__address = int32_t(0x832A7C88);
	if (!UseLiftedCode(144, 0x83268828)) { __imp__sub_83268828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268828);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C500_G_, str_TXT_820E2614_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C500_G__address);
}
PROMOTED_ENTRY(144, sub_83268828, 0x83268828) { ctx.r3.u64 = Construct_TXT_8349C500_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__29 = 0x8349C504u;
	if (!UseLiftedCode(144, 0x83268868)) { __imp__sub_83268868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268868);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268868, 0x83268868) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__29(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__31 = 0x8349C508u;
	if (!UseLiftedCode(144, 0x832688A0)) { __imp__sub_832688A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832688A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832688A0, 0x832688A0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__31(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__30 = 0x8349C50Cu;
	if (!UseLiftedCode(144, 0x832688D8)) { __imp__sub_832688D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832688D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832688D8, 0x832688D8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__29 = 0x8349C510u;
	if (!UseLiftedCode(144, 0x83268910)) { __imp__sub_83268910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268910);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268910, 0x83268910) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__29 = 0x8349C514u;
	if (!UseLiftedCode(144, 0x83268948)) { __imp__sub_83268948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268948);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268948, 0x83268948) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__30 = 0x8349C518u;
	if (!UseLiftedCode(144, 0x83268980)) { __imp__sub_83268980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268980);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268980, 0x83268980) { ctx.r3.u64 = HashName_TXT_820A2C34_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__29 = 0x8349C51Cu;
	if (!UseLiftedCode(144, 0x832689B8)) { __imp__sub_832689B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832689B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832689B8, 0x832689B8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__29 = 0x8349C520u;
	if (!UseLiftedCode(144, 0x832689F0)) { __imp__sub_832689F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832689F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832689F0, 0x832689F0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__29 = 0x8349C524u;
	if (!UseLiftedCode(144, 0x83268A28)) { __imp__sub_83268A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268A28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268A28, 0x83268A28) { ctx.r3.u64 = HashName_TXT_820A2C74_B__29(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__29 = 0x8349C528u;
	if (!UseLiftedCode(144, 0x83268A60)) { __imp__sub_83268A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268A60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268A60, 0x83268A60) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__29 = 0x8349C52Cu;
	if (!UseLiftedCode(144, 0x83268A98)) { __imp__sub_83268A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268A98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268A98, 0x83268A98) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__29 = 0x8349C530u;
	if (!UseLiftedCode(144, 0x83268AD0)) { __imp__sub_83268AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268AD0, 0x83268AD0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__32 = 0x8349C534u;
	if (!UseLiftedCode(144, 0x83268B08)) { __imp__sub_83268B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268B08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268B08, 0x83268B08) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__29 = 0x8349C538u;
	if (!UseLiftedCode(144, 0x83268B40)) { __imp__sub_83268B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268B40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268B40, 0x83268B40) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__29 = 0x8349C53Cu;
	if (!UseLiftedCode(144, 0x83268B78)) { __imp__sub_83268B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268B78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268B78, 0x83268B78) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__29(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__29 = 0x8349C540u;
	if (!UseLiftedCode(144, 0x83268BB0)) { __imp__sub_83268BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268BB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268BB0, 0x83268BB0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__29(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__29 = 0x8349C544u;
	if (!UseLiftedCode(144, 0x83268BE8)) { __imp__sub_83268BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268BE8, 0x83268BE8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__30 = 0x8349C548u;
	if (!UseLiftedCode(144, 0x83268C20)) { __imp__sub_83268C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268C20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268C20, 0x83268C20) { ctx.r3.u64 = HashName_TXT_820A2D24_B__30(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__29 = 0x8349C54Cu;
	if (!UseLiftedCode(144, 0x83268C58)) { __imp__sub_83268C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268C58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268C58, 0x83268C58) { ctx.r3.u64 = HashName_TXT_820A2D30_B__29(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__29 = 0x8349C550u;
	if (!UseLiftedCode(144, 0x83268C90)) { __imp__sub_83268C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268C90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268C90, 0x83268C90) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__29(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__29(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__29 = 0x8349C554u;
	if (!UseLiftedCode(144, 0x83268CC8)) { __imp__sub_83268CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__29, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83268CC8, 0x83268CC8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__29(ctx, base); }

uint64_t Construct_TXT_8349C558_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C558_G_ = int32_t(0x8349C558);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E263C);
	constexpr int32_t Destroy_TXT_8349C558_G__address = int32_t(0x832A7C98);
	if (!UseLiftedCode(144, 0x83268D00)) { __imp__sub_83268D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C558_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C558_G__address);
}
PROMOTED_ENTRY(144, sub_83268D00, 0x83268D00) { ctx.r3.u64 = Construct_TXT_8349C558_G_(ctx, base); }

uint64_t Construct_TXT_8349C55C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C55C_G_ = int32_t(0x8349C55C);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349C55C_G__address = int32_t(0x832A7CA8);
	if (!UseLiftedCode(144, 0x83268D40)) { __imp__sub_83268D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C55C_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C55C_G__address);
}
PROMOTED_ENTRY(144, sub_83268D40, 0x83268D40) { ctx.r3.u64 = Construct_TXT_8349C55C_G_(ctx, base); }

uint64_t Construct_TXT_8349C560_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C560_G_ = int32_t(0x8349C560);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2690);
	constexpr int32_t Destroy_TXT_8349C560_G__address = int32_t(0x832A7CB8);
	if (!UseLiftedCode(144, 0x83268D80)) { __imp__sub_83268D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C560_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C560_G__address);
}
PROMOTED_ENTRY(144, sub_83268D80, 0x83268D80) { ctx.r3.u64 = Construct_TXT_8349C560_G_(ctx, base); }

uint64_t Construct_TXT_8349C564_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C564_G_ = int32_t(0x8349C564);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E26D8);
	constexpr int32_t Destroy_TXT_8349C564_G__address = int32_t(0x832A7CC8);
	if (!UseLiftedCode(144, 0x83268DC0)) { __imp__sub_83268DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268DC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C564_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C564_G__address);
}
PROMOTED_ENTRY(144, sub_83268DC0, 0x83268DC0) { ctx.r3.u64 = Construct_TXT_8349C564_G_(ctx, base); }

uint64_t Construct_TXT_8349C568_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C568_G_ = int32_t(0x8349C568);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2720);
	constexpr int32_t Destroy_TXT_8349C568_G__address = int32_t(0x832A7CD8);
	if (!UseLiftedCode(144, 0x83268E00)) { __imp__sub_83268E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C568_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C568_G__address);
}
PROMOTED_ENTRY(144, sub_83268E00, 0x83268E00) { ctx.r3.u64 = Construct_TXT_8349C568_G_(ctx, base); }

uint64_t Construct_TXT_8349C56C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C56C_G_ = int32_t(0x8349C56C);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2770);
	constexpr int32_t Destroy_TXT_8349C56C_G__address = int32_t(0x832A7CE8);
	if (!UseLiftedCode(144, 0x83268E40)) { __imp__sub_83268E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C56C_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C56C_G__address);
}
PROMOTED_ENTRY(144, sub_83268E40, 0x83268E40) { ctx.r3.u64 = Construct_TXT_8349C56C_G_(ctx, base); }

uint64_t Construct_TXT_8349C570_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C570_G_ = int32_t(0x8349C570);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E27B8);
	constexpr int32_t Destroy_TXT_8349C570_G__address = int32_t(0x832A7CF8);
	if (!UseLiftedCode(144, 0x83268E80)) { __imp__sub_83268E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C570_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C570_G__address);
}
PROMOTED_ENTRY(144, sub_83268E80, 0x83268E80) { ctx.r3.u64 = Construct_TXT_8349C570_G_(ctx, base); }

uint64_t Construct_TXT_8349C574_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C574_G_ = int32_t(0x8349C574);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2808);
	constexpr int32_t Destroy_TXT_8349C574_G__address = int32_t(0x832A7D08);
	if (!UseLiftedCode(144, 0x83268EC0)) { __imp__sub_83268EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268EC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C574_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C574_G__address);
}
PROMOTED_ENTRY(144, sub_83268EC0, 0x83268EC0) { ctx.r3.u64 = Construct_TXT_8349C574_G_(ctx, base); }

uint64_t Construct_TXT_8349C578_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C578_G_ = int32_t(0x8349C578);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2858);
	constexpr int32_t Destroy_TXT_8349C578_G__address = int32_t(0x832A7D18);
	if (!UseLiftedCode(144, 0x83268F00)) { __imp__sub_83268F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C578_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C578_G__address);
}
PROMOTED_ENTRY(144, sub_83268F00, 0x83268F00) { ctx.r3.u64 = Construct_TXT_8349C578_G_(ctx, base); }

uint64_t Construct_TXT_8349C57C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C57C_G_ = int32_t(0x8349C57C);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2898);
	constexpr int32_t Destroy_TXT_8349C57C_G__address = int32_t(0x832A7D28);
	if (!UseLiftedCode(144, 0x83268F40)) { __imp__sub_83268F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C57C_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C57C_G__address);
}
PROMOTED_ENTRY(144, sub_83268F40, 0x83268F40) { ctx.r3.u64 = Construct_TXT_8349C57C_G_(ctx, base); }

uint64_t Construct_TXT_8349C580_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C580_G_ = int32_t(0x8349C580);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E28E0);
	constexpr int32_t Destroy_TXT_8349C580_G__address = int32_t(0x832A7D38);
	if (!UseLiftedCode(144, 0x83268F80)) { __imp__sub_83268F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C580_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C580_G__address);
}
PROMOTED_ENTRY(144, sub_83268F80, 0x83268F80) { ctx.r3.u64 = Construct_TXT_8349C580_G_(ctx, base); }

uint64_t Construct_TXT_8349C584_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C584_G_ = int32_t(0x8349C584);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2928);
	constexpr int32_t Destroy_TXT_8349C584_G__address = int32_t(0x832A7D48);
	if (!UseLiftedCode(144, 0x83268FC0)) { __imp__sub_83268FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C584_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C584_G__address);
}
PROMOTED_ENTRY(144, sub_83268FC0, 0x83268FC0) { ctx.r3.u64 = Construct_TXT_8349C584_G_(ctx, base); }

uint64_t Construct_TXT_8349C588_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C588_G_ = int32_t(0x8349C588);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2970);
	constexpr int32_t Destroy_TXT_8349C588_G__address = int32_t(0x832A7D58);
	if (!UseLiftedCode(144, 0x83269000)) { __imp__sub_83269000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269000);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C588_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C588_G__address);
}
PROMOTED_ENTRY(144, sub_83269000, 0x83269000) { ctx.r3.u64 = Construct_TXT_8349C588_G_(ctx, base); }

uint64_t Construct_TXT_8349C58C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C58C_G_ = int32_t(0x8349C58C);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E29B8);
	constexpr int32_t Destroy_TXT_8349C58C_G__address = int32_t(0x832A7D68);
	if (!UseLiftedCode(144, 0x83269040)) { __imp__sub_83269040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269040);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C58C_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C58C_G__address);
}
PROMOTED_ENTRY(144, sub_83269040, 0x83269040) { ctx.r3.u64 = Construct_TXT_8349C58C_G_(ctx, base); }

uint64_t Construct_TXT_8349C590_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C590_G_ = int32_t(0x8349C590);
	constexpr int32_t str_TXT_820E263C_B_ = int32_t(0x820E2A00);
	constexpr int32_t Destroy_TXT_8349C590_G__address = int32_t(0x832A7D78);
	if (!UseLiftedCode(144, 0x83269080)) { __imp__sub_83269080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269080);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C590_G_, str_TXT_820E263C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C590_G__address);
}
PROMOTED_ENTRY(144, sub_83269080, 0x83269080) { ctx.r3.u64 = Construct_TXT_8349C590_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__30 = 0x8349C594u;
	if (!UseLiftedCode(144, 0x832690C0)) { __imp__sub_832690C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832690C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832690C0, 0x832690C0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__30(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__32 = 0x8349C598u;
	if (!UseLiftedCode(144, 0x832690F8)) { __imp__sub_832690F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832690F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832690F8, 0x832690F8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__32(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__31 = 0x8349C59Cu;
	if (!UseLiftedCode(144, 0x83269130)) { __imp__sub_83269130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269130, 0x83269130) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__30 = 0x8349C5A0u;
	if (!UseLiftedCode(144, 0x83269168)) { __imp__sub_83269168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269168, 0x83269168) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__30 = 0x8349C5A4u;
	if (!UseLiftedCode(144, 0x832691A0)) { __imp__sub_832691A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832691A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832691A0, 0x832691A0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__31 = 0x8349C5A8u;
	if (!UseLiftedCode(144, 0x832691D8)) { __imp__sub_832691D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832691D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832691D8, 0x832691D8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__30 = 0x8349C5ACu;
	if (!UseLiftedCode(144, 0x83269210)) { __imp__sub_83269210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269210, 0x83269210) { ctx.r3.u64 = HashName_TXT_820A2C44_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__30 = 0x8349C5B0u;
	if (!UseLiftedCode(144, 0x83269248)) { __imp__sub_83269248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269248, 0x83269248) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__30 = 0x8349C5B4u;
	if (!UseLiftedCode(144, 0x83269280)) { __imp__sub_83269280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269280, 0x83269280) { ctx.r3.u64 = HashName_TXT_820A2C74_B__30(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__30 = 0x8349C5B8u;
	if (!UseLiftedCode(144, 0x832692B8)) { __imp__sub_832692B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832692B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832692B8, 0x832692B8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__30 = 0x8349C5BCu;
	if (!UseLiftedCode(144, 0x832692F0)) { __imp__sub_832692F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832692F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832692F0, 0x832692F0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__30 = 0x8349C5C0u;
	if (!UseLiftedCode(144, 0x83269328)) { __imp__sub_83269328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269328, 0x83269328) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__33 = 0x8349C5C4u;
	if (!UseLiftedCode(144, 0x83269360)) { __imp__sub_83269360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269360, 0x83269360) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__30 = 0x8349C5C8u;
	if (!UseLiftedCode(144, 0x83269398)) { __imp__sub_83269398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269398, 0x83269398) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__30 = 0x8349C5CCu;
	if (!UseLiftedCode(144, 0x832693D0)) { __imp__sub_832693D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832693D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832693D0, 0x832693D0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__30(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__30 = 0x8349C5D0u;
	if (!UseLiftedCode(144, 0x83269408)) { __imp__sub_83269408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269408);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269408, 0x83269408) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__30(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__30 = 0x8349C5D4u;
	if (!UseLiftedCode(144, 0x83269440)) { __imp__sub_83269440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269440, 0x83269440) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__31 = 0x8349C5D8u;
	if (!UseLiftedCode(144, 0x83269478)) { __imp__sub_83269478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269478, 0x83269478) { ctx.r3.u64 = HashName_TXT_820A2D24_B__31(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__30 = 0x8349C5DCu;
	if (!UseLiftedCode(144, 0x832694B0)) { __imp__sub_832694B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832694B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832694B0, 0x832694B0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__30(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__30 = 0x8349C5E0u;
	if (!UseLiftedCode(144, 0x832694E8)) { __imp__sub_832694E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832694E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_832694E8, 0x832694E8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__30(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__30 = 0x8349C5E4u;
	if (!UseLiftedCode(144, 0x83269520)) { __imp__sub_83269520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269520);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__30, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269520, 0x83269520) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__30(ctx, base); }

uint64_t Construct_TXT_8349C5E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5E8_G_ = int32_t(0x8349C5E8);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349C5E8_G__address = int32_t(0x832A7D88);
	if (!UseLiftedCode(144, 0x83269558)) { __imp__sub_83269558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5E8_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5E8_G__address);
}
PROMOTED_ENTRY(144, sub_83269558, 0x83269558) { ctx.r3.u64 = Construct_TXT_8349C5E8_G_(ctx, base); }

uint64_t Construct_TXT_8349C5EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5EC_G_ = int32_t(0x8349C5EC);
	constexpr int32_t str_TXT_820E2B80_B_ = int32_t(0x820E2B80);
	constexpr int32_t Destroy_TXT_8349C5EC_G__address = int32_t(0x832A7D98);
	if (!UseLiftedCode(144, 0x83269598)) { __imp__sub_83269598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5EC_G_, str_TXT_820E2B80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5EC_G__address);
}
PROMOTED_ENTRY(144, sub_83269598, 0x83269598) { ctx.r3.u64 = Construct_TXT_8349C5EC_G_(ctx, base); }

uint64_t Construct_TXT_8349C5F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5F0_G_ = int32_t(0x8349C5F0);
	constexpr int32_t str_TXT_820E2B80_B_ = int32_t(0x820E2BB8);
	constexpr int32_t Destroy_TXT_8349C5F0_G__address = int32_t(0x832A7DA8);
	if (!UseLiftedCode(144, 0x832695D8)) { __imp__sub_832695D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832695D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F0_G_, str_TXT_820E2B80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5F0_G__address);
}
PROMOTED_ENTRY(144, sub_832695D8, 0x832695D8) { ctx.r3.u64 = Construct_TXT_8349C5F0_G_(ctx, base); }

uint64_t Construct_TXT_8349C5F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5F4_G_ = int32_t(0x8349C5F4);
	constexpr int32_t str_TXT_820E2BF4_B_ = int32_t(0x820E2BF4);
	constexpr int32_t Destroy_TXT_8349C5F4_G__address = int32_t(0x832A7DB8);
	if (!UseLiftedCode(144, 0x83269618)) { __imp__sub_83269618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269618);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F4_G_, str_TXT_820E2BF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5F4_G__address);
}
PROMOTED_ENTRY(144, sub_83269618, 0x83269618) { ctx.r3.u64 = Construct_TXT_8349C5F4_G_(ctx, base); }

uint64_t Construct_TXT_8349C5F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5F8_G_ = int32_t(0x8349C5F8);
	constexpr int32_t str_TXT_820E2C08_B_ = int32_t(0x820E2C08);
	constexpr int32_t Destroy_TXT_8349C5F8_G__address = int32_t(0x832A7DC8);
	if (!UseLiftedCode(144, 0x83269658)) { __imp__sub_83269658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269658);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F8_G_, str_TXT_820E2C08_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5F8_G__address);
}
PROMOTED_ENTRY(144, sub_83269658, 0x83269658) { ctx.r3.u64 = Construct_TXT_8349C5F8_G_(ctx, base); }

uint64_t Construct_TXT_8349C5FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C5FC_G_ = int32_t(0x8349C5FC);
	constexpr int32_t str_TXT_820E2C18_B_ = int32_t(0x820E2C18);
	constexpr int32_t Destroy_TXT_8349C5FC_G__address = int32_t(0x832A7DD8);
	if (!UseLiftedCode(144, 0x83269698)) { __imp__sub_83269698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269698);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5FC_G_, str_TXT_820E2C18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C5FC_G__address);
}
PROMOTED_ENTRY(144, sub_83269698, 0x83269698) { ctx.r3.u64 = Construct_TXT_8349C5FC_G_(ctx, base); }

uint64_t Construct_TXT_8349C600_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C600_G_ = int32_t(0x8349C600);
	constexpr int32_t str_TXT_820E2C28_B_ = int32_t(0x820E2C28);
	constexpr int32_t Destroy_TXT_8349C600_G__address = int32_t(0x832A7DE8);
	if (!UseLiftedCode(144, 0x832696D8)) { __imp__sub_832696D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832696D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C600_G_, str_TXT_820E2C28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C600_G__address);
}
PROMOTED_ENTRY(144, sub_832696D8, 0x832696D8) { ctx.r3.u64 = Construct_TXT_8349C600_G_(ctx, base); }

uint64_t Construct_TXT_8349C604_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C604_G_ = int32_t(0x8349C604);
	constexpr int32_t str_TXT_820E2C38_B_ = int32_t(0x820E2C38);
	constexpr int32_t Destroy_TXT_8349C604_G__address = int32_t(0x832A7DF8);
	if (!UseLiftedCode(144, 0x83269718)) { __imp__sub_83269718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269718);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C604_G_, str_TXT_820E2C38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C604_G__address);
}
PROMOTED_ENTRY(144, sub_83269718, 0x83269718) { ctx.r3.u64 = Construct_TXT_8349C604_G_(ctx, base); }

uint64_t Construct_TXT_8349C608_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C608_G_ = int32_t(0x8349C608);
	constexpr int32_t str_TXT_820E2C48_B_ = int32_t(0x820E2C48);
	constexpr int32_t Destroy_TXT_8349C608_G__address = int32_t(0x832A7E08);
	if (!UseLiftedCode(144, 0x83269758)) { __imp__sub_83269758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269758);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C608_G_, str_TXT_820E2C48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C608_G__address);
}
PROMOTED_ENTRY(144, sub_83269758, 0x83269758) { ctx.r3.u64 = Construct_TXT_8349C608_G_(ctx, base); }

uint64_t Construct_TXT_8349C60C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C60C_G_ = int32_t(0x8349C60C);
	constexpr int32_t str_TXT_820E2C58_B_ = int32_t(0x820E2C58);
	constexpr int32_t Destroy_TXT_8349C60C_G__address = int32_t(0x832A7E18);
	if (!UseLiftedCode(144, 0x83269798)) { __imp__sub_83269798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C60C_G_, str_TXT_820E2C58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C60C_G__address);
}
PROMOTED_ENTRY(144, sub_83269798, 0x83269798) { ctx.r3.u64 = Construct_TXT_8349C60C_G_(ctx, base); }

uint64_t Construct_TXT_8349C610_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C610_G_ = int32_t(0x8349C610);
	constexpr int32_t str_TXT_820E2C68_B_ = int32_t(0x820E2C68);
	constexpr int32_t Destroy_TXT_8349C610_G__address = int32_t(0x832A7E28);
	if (!UseLiftedCode(144, 0x832697D8)) { __imp__sub_832697D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832697D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C610_G_, str_TXT_820E2C68_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C610_G__address);
}
PROMOTED_ENTRY(144, sub_832697D8, 0x832697D8) { ctx.r3.u64 = Construct_TXT_8349C610_G_(ctx, base); }

uint64_t Construct_TXT_8349C614_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C614_G_ = int32_t(0x8349C614);
	constexpr int32_t str_TXT_820E2C74_B_ = int32_t(0x820E2C74);
	constexpr int32_t Destroy_TXT_8349C614_G__address = int32_t(0x832A7E38);
	if (!UseLiftedCode(144, 0x83269818)) { __imp__sub_83269818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C614_G_, str_TXT_820E2C74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C614_G__address);
}
PROMOTED_ENTRY(144, sub_83269818, 0x83269818) { ctx.r3.u64 = Construct_TXT_8349C614_G_(ctx, base); }

uint64_t Construct_TXT_8349C618_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C618_G_ = int32_t(0x8349C618);
	constexpr int32_t str_TXT_820E2C80_B_ = int32_t(0x820E2C80);
	constexpr int32_t Destroy_TXT_8349C618_G__address = int32_t(0x832A7E48);
	if (!UseLiftedCode(144, 0x83269858)) { __imp__sub_83269858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269858);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C618_G_, str_TXT_820E2C80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C618_G__address);
}
PROMOTED_ENTRY(144, sub_83269858, 0x83269858) { ctx.r3.u64 = Construct_TXT_8349C618_G_(ctx, base); }

uint64_t Construct_TXT_8349C61C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C61C_G_ = int32_t(0x8349C61C);
	constexpr int32_t str_TXT_820E2C90_B_ = int32_t(0x820E2C90);
	constexpr int32_t Destroy_TXT_8349C61C_G__address = int32_t(0x832A7E58);
	if (!UseLiftedCode(144, 0x83269898)) { __imp__sub_83269898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C61C_G_, str_TXT_820E2C90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C61C_G__address);
}
PROMOTED_ENTRY(144, sub_83269898, 0x83269898) { ctx.r3.u64 = Construct_TXT_8349C61C_G_(ctx, base); }

uint64_t Construct_TXT_8349C620_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C620_G_ = int32_t(0x8349C620);
	constexpr int32_t str_TXT_820E2CA0_B_ = int32_t(0x820E2CA0);
	constexpr int32_t Destroy_TXT_8349C620_G__address = int32_t(0x832A7E68);
	if (!UseLiftedCode(144, 0x832698D8)) { __imp__sub_832698D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832698D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C620_G_, str_TXT_820E2CA0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C620_G__address);
}
PROMOTED_ENTRY(144, sub_832698D8, 0x832698D8) { ctx.r3.u64 = Construct_TXT_8349C620_G_(ctx, base); }

uint64_t Construct_TXT_8349C624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C624_G_ = int32_t(0x8349C624);
	constexpr int32_t str_TXT_820E2B80_B_ = int32_t(0x820E2CB0);
	constexpr int32_t Destroy_TXT_8349C624_G__address = int32_t(0x832A7E78);
	if (!UseLiftedCode(144, 0x83269918)) { __imp__sub_83269918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269918);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C624_G_, str_TXT_820E2B80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C624_G__address);
}
PROMOTED_ENTRY(144, sub_83269918, 0x83269918) { ctx.r3.u64 = Construct_TXT_8349C624_G_(ctx, base); }

uint64_t Construct_TXT_8349C628_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C628_G_ = int32_t(0x8349C628);
	constexpr int32_t str_TXT_820E2CEC_B_ = int32_t(0x820E2CEC);
	constexpr int32_t Destroy_TXT_8349C628_G__address = int32_t(0x832A7E88);
	if (!UseLiftedCode(144, 0x83269958)) { __imp__sub_83269958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269958);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C628_G_, str_TXT_820E2CEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C628_G__address);
}
PROMOTED_ENTRY(144, sub_83269958, 0x83269958) { ctx.r3.u64 = Construct_TXT_8349C628_G_(ctx, base); }

uint64_t Construct_TXT_8349C62C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C62C_G_ = int32_t(0x8349C62C);
	constexpr int32_t str_TXT_820E2CFC_B_ = int32_t(0x820E2CFC);
	constexpr int32_t Destroy_TXT_8349C62C_G__address = int32_t(0x832A7E98);
	if (!UseLiftedCode(144, 0x83269998)) { __imp__sub_83269998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269998);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C62C_G_, str_TXT_820E2CFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C62C_G__address);
}
PROMOTED_ENTRY(144, sub_83269998, 0x83269998) { ctx.r3.u64 = Construct_TXT_8349C62C_G_(ctx, base); }

uint64_t Construct_TXT_8349C630_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C630_G_ = int32_t(0x8349C630);
	constexpr int32_t str_TXT_820E2D0C_B_ = int32_t(0x820E2D0C);
	constexpr int32_t Destroy_TXT_8349C630_G__address = int32_t(0x832A7EA8);
	if (!UseLiftedCode(144, 0x832699D8)) { __imp__sub_832699D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832699D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C630_G_, str_TXT_820E2D0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C630_G__address);
}
PROMOTED_ENTRY(144, sub_832699D8, 0x832699D8) { ctx.r3.u64 = Construct_TXT_8349C630_G_(ctx, base); }

uint64_t Construct_TXT_8349C634_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C634_G_ = int32_t(0x8349C634);
	constexpr int32_t str_TXT_820E2D1C_B_ = int32_t(0x820E2D1C);
	constexpr int32_t Destroy_TXT_8349C634_G__address = int32_t(0x832A7EB8);
	if (!UseLiftedCode(144, 0x83269A18)) { __imp__sub_83269A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C634_G_, str_TXT_820E2D1C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C634_G__address);
}
PROMOTED_ENTRY(144, sub_83269A18, 0x83269A18) { ctx.r3.u64 = Construct_TXT_8349C634_G_(ctx, base); }

uint64_t Construct_TXT_8349C638_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C638_G_ = int32_t(0x8349C638);
	constexpr int32_t str_TXT_820E2D2C_B_ = int32_t(0x820E2D2C);
	constexpr int32_t Destroy_TXT_8349C638_G__address = int32_t(0x832A7EC8);
	if (!UseLiftedCode(144, 0x83269A58)) { __imp__sub_83269A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C638_G_, str_TXT_820E2D2C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C638_G__address);
}
PROMOTED_ENTRY(144, sub_83269A58, 0x83269A58) { ctx.r3.u64 = Construct_TXT_8349C638_G_(ctx, base); }

uint64_t Construct_TXT_8349C63C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C63C_G_ = int32_t(0x8349C63C);
	constexpr int32_t str_TXT_820E2B80_B_ = int32_t(0x820E2D40);
	constexpr int32_t Destroy_TXT_8349C63C_G__address = int32_t(0x832A7ED8);
	if (!UseLiftedCode(144, 0x83269A98)) { __imp__sub_83269A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C63C_G_, str_TXT_820E2B80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C63C_G__address);
}
PROMOTED_ENTRY(144, sub_83269A98, 0x83269A98) { ctx.r3.u64 = Construct_TXT_8349C63C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__31 = 0x8349C640u;
	if (!UseLiftedCode(144, 0x83269AD8)) { __imp__sub_83269AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269AD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269AD8, 0x83269AD8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__31(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__33 = 0x8349C644u;
	if (!UseLiftedCode(144, 0x83269B10)) { __imp__sub_83269B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269B10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269B10, 0x83269B10) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__33(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__32 = 0x8349C648u;
	if (!UseLiftedCode(144, 0x83269B48)) { __imp__sub_83269B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269B48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269B48, 0x83269B48) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__31 = 0x8349C64Cu;
	if (!UseLiftedCode(144, 0x83269B80)) { __imp__sub_83269B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269B80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269B80, 0x83269B80) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__31 = 0x8349C650u;
	if (!UseLiftedCode(144, 0x83269BB8)) { __imp__sub_83269BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269BB8, 0x83269BB8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__32 = 0x8349C654u;
	if (!UseLiftedCode(144, 0x83269BF0)) { __imp__sub_83269BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269BF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269BF0, 0x83269BF0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__31 = 0x8349C658u;
	if (!UseLiftedCode(144, 0x83269C28)) { __imp__sub_83269C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269C28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269C28, 0x83269C28) { ctx.r3.u64 = HashName_TXT_820A2C44_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__31 = 0x8349C65Cu;
	if (!UseLiftedCode(144, 0x83269C60)) { __imp__sub_83269C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269C60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269C60, 0x83269C60) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__31 = 0x8349C660u;
	if (!UseLiftedCode(144, 0x83269C98)) { __imp__sub_83269C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269C98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269C98, 0x83269C98) { ctx.r3.u64 = HashName_TXT_820A2C74_B__31(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__31 = 0x8349C664u;
	if (!UseLiftedCode(144, 0x83269CD0)) { __imp__sub_83269CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269CD0, 0x83269CD0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__31 = 0x8349C668u;
	if (!UseLiftedCode(144, 0x83269D08)) { __imp__sub_83269D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269D08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269D08, 0x83269D08) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__31 = 0x8349C66Cu;
	if (!UseLiftedCode(144, 0x83269D40)) { __imp__sub_83269D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269D40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269D40, 0x83269D40) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__34 = 0x8349C670u;
	if (!UseLiftedCode(144, 0x83269D78)) { __imp__sub_83269D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269D78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269D78, 0x83269D78) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__31 = 0x8349C674u;
	if (!UseLiftedCode(144, 0x83269DB0)) { __imp__sub_83269DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269DB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269DB0, 0x83269DB0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__31 = 0x8349C678u;
	if (!UseLiftedCode(144, 0x83269DE8)) { __imp__sub_83269DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269DE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269DE8, 0x83269DE8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__31(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__31 = 0x8349C67Cu;
	if (!UseLiftedCode(144, 0x83269E20)) { __imp__sub_83269E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269E20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269E20, 0x83269E20) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__31(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__31 = 0x8349C680u;
	if (!UseLiftedCode(144, 0x83269E58)) { __imp__sub_83269E58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269E58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269E58, 0x83269E58) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__32 = 0x8349C684u;
	if (!UseLiftedCode(144, 0x83269E90)) { __imp__sub_83269E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269E90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269E90, 0x83269E90) { ctx.r3.u64 = HashName_TXT_820A2D24_B__32(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__31 = 0x8349C688u;
	if (!UseLiftedCode(144, 0x83269EC8)) { __imp__sub_83269EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269EC8, 0x83269EC8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__31(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__31 = 0x8349C68Cu;
	if (!UseLiftedCode(144, 0x83269F00)) { __imp__sub_83269F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269F00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269F00, 0x83269F00) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__31(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__31(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__31 = 0x8349C690u;
	if (!UseLiftedCode(144, 0x83269F38)) { __imp__sub_83269F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269F38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__31, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_83269F38, 0x83269F38) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__31(ctx, base); }

uint64_t Construct_TXT_8349C694_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C694_G_ = int32_t(0x8349C694);
	constexpr int32_t str_TXT_820E2DC0_B_ = int32_t(0x820E2DC0);
	constexpr int32_t Destroy_TXT_8349C694_G__address = int32_t(0x832A7EE8);
	if (!UseLiftedCode(144, 0x83269F70)) { __imp__sub_83269F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269F70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C694_G_, str_TXT_820E2DC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C694_G__address);
}
PROMOTED_ENTRY(144, sub_83269F70, 0x83269F70) { ctx.r3.u64 = Construct_TXT_8349C694_G_(ctx, base); }

uint64_t Construct_TXT_8349C698_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C698_G_ = int32_t(0x8349C698);
	constexpr int32_t str_TXT_820E2DC0_B_ = int32_t(0x820E2E00);
	constexpr int32_t Destroy_TXT_8349C698_G__address = int32_t(0x832A7EF8);
	if (!UseLiftedCode(144, 0x83269FB0)) { __imp__sub_83269FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269FB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C698_G_, str_TXT_820E2DC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C698_G__address);
}
PROMOTED_ENTRY(144, sub_83269FB0, 0x83269FB0) { ctx.r3.u64 = Construct_TXT_8349C698_G_(ctx, base); }

uint64_t Construct_TXT_8349C69C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C69C_G_ = int32_t(0x8349C69C);
	constexpr int32_t str_TXT_820E2DC0_B_ = int32_t(0x820E2E48);
	constexpr int32_t Destroy_TXT_8349C69C_G__address = int32_t(0x832A7F08);
	if (!UseLiftedCode(144, 0x83269FF0)) { __imp__sub_83269FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C69C_G_, str_TXT_820E2DC0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C69C_G__address);
}
PROMOTED_ENTRY(144, sub_83269FF0, 0x83269FF0) { ctx.r3.u64 = Construct_TXT_8349C69C_G_(ctx, base); }

uint64_t Construct_TXT_8349C6A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6A0_G_ = int32_t(0x8349C6A0);
	constexpr int32_t str_TXT_820E2E94_B_ = int32_t(0x820E2E94);
	constexpr int32_t Destroy_TXT_8349C6A0_G__address = int32_t(0x832A7F18);
	if (!UseLiftedCode(144, 0x8326A030)) { __imp__sub_8326A030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A030);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A0_G_, str_TXT_820E2E94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6A0_G__address);
}
PROMOTED_ENTRY(144, sub_8326A030, 0x8326A030) { ctx.r3.u64 = Construct_TXT_8349C6A0_G_(ctx, base); }

uint64_t Construct_TXT_8349C6A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6A4_G_ = int32_t(0x8349C6A4);
	constexpr int32_t str_TXT_820E2EA4_B_ = int32_t(0x820E2EA4);
	constexpr int32_t Destroy_TXT_8349C6A4_G__address = int32_t(0x832A7F28);
	if (!UseLiftedCode(144, 0x8326A070)) { __imp__sub_8326A070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A070);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A4_G_, str_TXT_820E2EA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6A4_G__address);
}
PROMOTED_ENTRY(144, sub_8326A070, 0x8326A070) { ctx.r3.u64 = Construct_TXT_8349C6A4_G_(ctx, base); }

uint64_t Construct_TXT_8349C6A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6A8_G_ = int32_t(0x8349C6A8);
	constexpr int32_t str_TXT_820E2EB0_B_ = int32_t(0x820E2EB0);
	constexpr int32_t Destroy_TXT_8349C6A8_G__address = int32_t(0x832A7F38);
	if (!UseLiftedCode(144, 0x8326A0B0)) { __imp__sub_8326A0B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A0B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A8_G_, str_TXT_820E2EB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6A8_G__address);
}
PROMOTED_ENTRY(144, sub_8326A0B0, 0x8326A0B0) { ctx.r3.u64 = Construct_TXT_8349C6A8_G_(ctx, base); }

uint64_t Construct_TXT_8349C6AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6AC_G_ = int32_t(0x8349C6AC);
	constexpr int32_t str_TXT_820E2EBC_B_ = int32_t(0x820E2EBC);
	constexpr int32_t Destroy_TXT_8349C6AC_G__address = int32_t(0x832A7F48);
	if (!UseLiftedCode(144, 0x8326A0F0)) { __imp__sub_8326A0F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A0F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6AC_G_, str_TXT_820E2EBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6AC_G__address);
}
PROMOTED_ENTRY(144, sub_8326A0F0, 0x8326A0F0) { ctx.r3.u64 = Construct_TXT_8349C6AC_G_(ctx, base); }

uint64_t Construct_TXT_8349C6B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6B0_G_ = int32_t(0x8349C6B0);
	constexpr int32_t str_TXT_820E2ECC_B_ = int32_t(0x820E2ECC);
	constexpr int32_t Destroy_TXT_8349C6B0_G__address = int32_t(0x832A7F58);
	if (!UseLiftedCode(144, 0x8326A130)) { __imp__sub_8326A130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A130);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B0_G_, str_TXT_820E2ECC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6B0_G__address);
}
PROMOTED_ENTRY(144, sub_8326A130, 0x8326A130) { ctx.r3.u64 = Construct_TXT_8349C6B0_G_(ctx, base); }

uint64_t Construct_TXT_8349C6B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6B4_G_ = int32_t(0x8349C6B4);
	constexpr int32_t str_TXT_820E2ED8_B_ = int32_t(0x820E2ED8);
	constexpr int32_t Destroy_TXT_8349C6B4_G__address = int32_t(0x832A7F68);
	if (!UseLiftedCode(144, 0x8326A170)) { __imp__sub_8326A170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A170);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B4_G_, str_TXT_820E2ED8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6B4_G__address);
}
PROMOTED_ENTRY(144, sub_8326A170, 0x8326A170) { ctx.r3.u64 = Construct_TXT_8349C6B4_G_(ctx, base); }

uint64_t Construct_TXT_8349C6B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6B8_G_ = int32_t(0x8349C6B8);
	constexpr int32_t str_TXT_820E2EE4_B_ = int32_t(0x820E2EE4);
	constexpr int32_t Destroy_TXT_8349C6B8_G__address = int32_t(0x832A7F78);
	if (!UseLiftedCode(144, 0x8326A1B0)) { __imp__sub_8326A1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A1B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B8_G_, str_TXT_820E2EE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6B8_G__address);
}
PROMOTED_ENTRY(144, sub_8326A1B0, 0x8326A1B0) { ctx.r3.u64 = Construct_TXT_8349C6B8_G_(ctx, base); }

uint64_t Construct_TXT_8349C6BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6BC_G_ = int32_t(0x8349C6BC);
	constexpr int32_t str_TXT_820E2EFC_B_ = int32_t(0x820E2EFC);
	constexpr int32_t Destroy_TXT_8349C6BC_G__address = int32_t(0x832A7F88);
	if (!UseLiftedCode(144, 0x8326A1F0)) { __imp__sub_8326A1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A1F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6BC_G_, str_TXT_820E2EFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6BC_G__address);
}
PROMOTED_ENTRY(144, sub_8326A1F0, 0x8326A1F0) { ctx.r3.u64 = Construct_TXT_8349C6BC_G_(ctx, base); }

uint64_t Construct_TXT_8349C6C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6C0_G_ = int32_t(0x8349C6C0);
	constexpr int32_t str_TXT_820E2F08_B_ = int32_t(0x820E2F08);
	constexpr int32_t Destroy_TXT_8349C6C0_G__address = int32_t(0x832A7F98);
	if (!UseLiftedCode(144, 0x8326A230)) { __imp__sub_8326A230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C0_G_, str_TXT_820E2F08_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6C0_G__address);
}
PROMOTED_ENTRY(144, sub_8326A230, 0x8326A230) { ctx.r3.u64 = Construct_TXT_8349C6C0_G_(ctx, base); }

uint64_t Construct_TXT_8349C6C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6C4_G_ = int32_t(0x8349C6C4);
	constexpr int32_t str_TXT_820E2F18_B_ = int32_t(0x820E2F18);
	constexpr int32_t Destroy_TXT_8349C6C4_G__address = int32_t(0x832A7FA8);
	if (!UseLiftedCode(144, 0x8326A270)) { __imp__sub_8326A270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A270);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C4_G_, str_TXT_820E2F18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6C4_G__address);
}
PROMOTED_ENTRY(144, sub_8326A270, 0x8326A270) { ctx.r3.u64 = Construct_TXT_8349C6C4_G_(ctx, base); }

uint64_t Construct_TXT_8349C6C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C6C8_G_ = int32_t(0x8349C6C8);
	constexpr int32_t str_TXT_820E2F24_B_ = int32_t(0x820E2F24);
	constexpr int32_t Destroy_TXT_8349C6C8_G__address = int32_t(0x832A7FB8);
	if (!UseLiftedCode(144, 0x8326A2B0)) { __imp__sub_8326A2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A2B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C8_G_, str_TXT_820E2F24_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C6C8_G__address);
}
PROMOTED_ENTRY(144, sub_8326A2B0, 0x8326A2B0) { ctx.r3.u64 = Construct_TXT_8349C6C8_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__32 = 0x8349C6CCu;
	if (!UseLiftedCode(144, 0x8326A2F0)) { __imp__sub_8326A2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A2F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A2F0, 0x8326A2F0) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__32(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__34 = 0x8349C6D0u;
	if (!UseLiftedCode(144, 0x8326A328)) { __imp__sub_8326A328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A328, 0x8326A328) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__34(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__33 = 0x8349C6D4u;
	if (!UseLiftedCode(144, 0x8326A360)) { __imp__sub_8326A360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A360, 0x8326A360) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__32 = 0x8349C6D8u;
	if (!UseLiftedCode(144, 0x8326A398)) { __imp__sub_8326A398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A398, 0x8326A398) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__32 = 0x8349C6DCu;
	if (!UseLiftedCode(144, 0x8326A3D0)) { __imp__sub_8326A3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A3D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A3D0, 0x8326A3D0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__33 = 0x8349C6E0u;
	if (!UseLiftedCode(144, 0x8326A408)) { __imp__sub_8326A408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A408);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A408, 0x8326A408) { ctx.r3.u64 = HashName_TXT_820A2C34_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__32 = 0x8349C6E4u;
	if (!UseLiftedCode(144, 0x8326A440)) { __imp__sub_8326A440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A440);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A440, 0x8326A440) { ctx.r3.u64 = HashName_TXT_820A2C44_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__32 = 0x8349C6E8u;
	if (!UseLiftedCode(144, 0x8326A478)) { __imp__sub_8326A478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A478);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A478, 0x8326A478) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__32 = 0x8349C6ECu;
	if (!UseLiftedCode(144, 0x8326A4B0)) { __imp__sub_8326A4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A4B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A4B0, 0x8326A4B0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__32(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__32 = 0x8349C6F0u;
	if (!UseLiftedCode(144, 0x8326A4E8)) { __imp__sub_8326A4E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A4E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A4E8, 0x8326A4E8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__32 = 0x8349C6F4u;
	if (!UseLiftedCode(144, 0x8326A520)) { __imp__sub_8326A520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A520);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A520, 0x8326A520) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__32 = 0x8349C6F8u;
	if (!UseLiftedCode(144, 0x8326A558)) { __imp__sub_8326A558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A558);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A558, 0x8326A558) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__35 = 0x8349C6FCu;
	if (!UseLiftedCode(144, 0x8326A590)) { __imp__sub_8326A590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A590);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A590, 0x8326A590) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__32 = 0x8349C700u;
	if (!UseLiftedCode(144, 0x8326A5C8)) { __imp__sub_8326A5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A5C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A5C8, 0x8326A5C8) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__32 = 0x8349C704u;
	if (!UseLiftedCode(144, 0x8326A600)) { __imp__sub_8326A600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A600);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A600, 0x8326A600) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__32(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__32 = 0x8349C708u;
	if (!UseLiftedCode(144, 0x8326A638)) { __imp__sub_8326A638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A638);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A638, 0x8326A638) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__32(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__32 = 0x8349C70Cu;
	if (!UseLiftedCode(144, 0x8326A670)) { __imp__sub_8326A670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A670);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A670, 0x8326A670) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__33 = 0x8349C710u;
	if (!UseLiftedCode(144, 0x8326A6A8)) { __imp__sub_8326A6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A6A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A6A8, 0x8326A6A8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__33(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__32 = 0x8349C714u;
	if (!UseLiftedCode(144, 0x8326A6E0)) { __imp__sub_8326A6E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A6E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A6E0, 0x8326A6E0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__32(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__32 = 0x8349C718u;
	if (!UseLiftedCode(144, 0x8326A718)) { __imp__sub_8326A718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A718);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A718, 0x8326A718) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__32(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__32(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__32 = 0x8349C71Cu;
	if (!UseLiftedCode(144, 0x8326A750)) { __imp__sub_8326A750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A750);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__32, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326A750, 0x8326A750) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__32(ctx, base); }

uint64_t Construct_TXT_8349C720_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C720_G_ = int32_t(0x8349C720);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349C720_G__address = int32_t(0x832A7FC8);
	if (!UseLiftedCode(144, 0x8326A788)) { __imp__sub_8326A788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C720_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C720_G__address);
}
PROMOTED_ENTRY(144, sub_8326A788, 0x8326A788) { ctx.r3.u64 = Construct_TXT_8349C720_G_(ctx, base); }

uint64_t Construct_TXT_8349C724_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C724_G_ = int32_t(0x8349C724);
	constexpr int32_t str_TXT_820E2F58_B_ = int32_t(0x820E2F58);
	constexpr int32_t Destroy_TXT_8349C724_G__address = int32_t(0x832A7FD8);
	if (!UseLiftedCode(144, 0x8326A7C8)) { __imp__sub_8326A7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A7C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C724_G_, str_TXT_820E2F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C724_G__address);
}
PROMOTED_ENTRY(144, sub_8326A7C8, 0x8326A7C8) { ctx.r3.u64 = Construct_TXT_8349C724_G_(ctx, base); }

uint64_t Construct_TXT_8349C728_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C728_G_ = int32_t(0x8349C728);
	constexpr int32_t str_TXT_820E2F58_B_ = int32_t(0x820E2F90);
	constexpr int32_t Destroy_TXT_8349C728_G__address = int32_t(0x832A7FE8);
	if (!UseLiftedCode(144, 0x8326A808)) { __imp__sub_8326A808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C728_G_, str_TXT_820E2F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C728_G__address);
}
PROMOTED_ENTRY(144, sub_8326A808, 0x8326A808) { ctx.r3.u64 = Construct_TXT_8349C728_G_(ctx, base); }

uint64_t Construct_TXT_8349C72C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C72C_G_ = int32_t(0x8349C72C);
	constexpr int32_t str_TXT_820E2FC8_B_ = int32_t(0x820E2FC8);
	constexpr int32_t Destroy_TXT_8349C72C_G__address = int32_t(0x832A7FF8);
	if (!UseLiftedCode(144, 0x8326A848)) { __imp__sub_8326A848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C72C_G_, str_TXT_820E2FC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C72C_G__address);
}
PROMOTED_ENTRY(144, sub_8326A848, 0x8326A848) { ctx.r3.u64 = Construct_TXT_8349C72C_G_(ctx, base); }

uint64_t Construct_TXT_8349C730_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C730_G_ = int32_t(0x8349C730);
	constexpr int32_t str_TXT_820E2FD0_B_ = int32_t(0x820E2FD0);
	constexpr int32_t Destroy_TXT_8349C730_G__address = int32_t(0x832A8008);
	if (!UseLiftedCode(144, 0x8326A888)) { __imp__sub_8326A888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C730_G_, str_TXT_820E2FD0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C730_G__address);
}
PROMOTED_ENTRY(144, sub_8326A888, 0x8326A888) { ctx.r3.u64 = Construct_TXT_8349C730_G_(ctx, base); }

uint64_t Construct_TXT_8349C734_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C734_G_ = int32_t(0x8349C734);
	constexpr int32_t str_TXT_820E2FD8_B_ = int32_t(0x820E2FD8);
	constexpr int32_t Destroy_TXT_8349C734_G__address = int32_t(0x832A8018);
	if (!UseLiftedCode(144, 0x8326A8C8)) { __imp__sub_8326A8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C734_G_, str_TXT_820E2FD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C734_G__address);
}
PROMOTED_ENTRY(144, sub_8326A8C8, 0x8326A8C8) { ctx.r3.u64 = Construct_TXT_8349C734_G_(ctx, base); }

uint64_t Construct_TXT_8349C738_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C738_G_ = int32_t(0x8349C738);
	constexpr int32_t str_TXT_820E2FE0_B_ = int32_t(0x820E2FE0);
	constexpr int32_t Destroy_TXT_8349C738_G__address = int32_t(0x832A8028);
	if (!UseLiftedCode(144, 0x8326A908)) { __imp__sub_8326A908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C738_G_, str_TXT_820E2FE0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C738_G__address);
}
PROMOTED_ENTRY(144, sub_8326A908, 0x8326A908) { ctx.r3.u64 = Construct_TXT_8349C738_G_(ctx, base); }

uint64_t Construct_TXT_8349C73C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C73C_G_ = int32_t(0x8349C73C);
	constexpr int32_t str_TXT_820E2FEC_B_ = int32_t(0x820E2FEC);
	constexpr int32_t Destroy_TXT_8349C73C_G__address = int32_t(0x832A8038);
	if (!UseLiftedCode(144, 0x8326A948)) { __imp__sub_8326A948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C73C_G_, str_TXT_820E2FEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C73C_G__address);
}
PROMOTED_ENTRY(144, sub_8326A948, 0x8326A948) { ctx.r3.u64 = Construct_TXT_8349C73C_G_(ctx, base); }

uint64_t Construct_TXT_8349C740_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C740_G_ = int32_t(0x8349C740);
	constexpr int32_t str_TXT_820E2FF4_B_ = int32_t(0x820E2FF4);
	constexpr int32_t Destroy_TXT_8349C740_G__address = int32_t(0x832A8048);
	if (!UseLiftedCode(144, 0x8326A988)) { __imp__sub_8326A988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C740_G_, str_TXT_820E2FF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C740_G__address);
}
PROMOTED_ENTRY(144, sub_8326A988, 0x8326A988) { ctx.r3.u64 = Construct_TXT_8349C740_G_(ctx, base); }

// sub_8326A9C8  [64 bytes]
uint64_t InitCrimeString(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C744_G_ = int32_t(0x8349C744);
	constexpr int32_t str_TXT_820DD930_B_ = int32_t(0x820DD930);
	constexpr int32_t Destroy_TXT_8349C744_G__address = int32_t(0x832A8058);
	if (!UseLiftedCode(144, 0x8326A9C8)) { __imp__sub_8326A9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A9C8);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (RegisterAtExit is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C744_G_, str_TXT_820DD930_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_8349C744_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A9C8, 0x8326A9C8) { ctx.r3.u64 = InitCrimeString(ctx, base); }

uint64_t Construct_TXT_8349C748_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C748_G_ = int32_t(0x8349C748);
	constexpr int32_t str_TXT_820E3004_B_ = int32_t(0x820E3004);
	constexpr int32_t Destroy_TXT_8349C748_G__address = int32_t(0x832A8068);
	if (!UseLiftedCode(144, 0x8326AA08)) { __imp__sub_8326AA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C748_G_, str_TXT_820E3004_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C748_G__address);
}
PROMOTED_ENTRY(144, sub_8326AA08, 0x8326AA08) { ctx.r3.u64 = Construct_TXT_8349C748_G_(ctx, base); }

uint64_t Construct_TXT_8349C74C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C74C_G_ = int32_t(0x8349C74C);
	constexpr int32_t str_TXT_820E300C_B_ = int32_t(0x820E300C);
	constexpr int32_t Destroy_TXT_8349C74C_G__address = int32_t(0x832A8078);
	if (!UseLiftedCode(144, 0x8326AA48)) { __imp__sub_8326AA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C74C_G_, str_TXT_820E300C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C74C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AA48, 0x8326AA48) { ctx.r3.u64 = Construct_TXT_8349C74C_G_(ctx, base); }

uint64_t Construct_TXT_8349C750_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C750_G_ = int32_t(0x8349C750);
	constexpr int32_t str_TXT_820E3020_B_ = int32_t(0x820E3020);
	constexpr int32_t Destroy_TXT_8349C750_G__address = int32_t(0x832A8088);
	if (!UseLiftedCode(144, 0x8326AA88)) { __imp__sub_8326AA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C750_G_, str_TXT_820E3020_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C750_G__address);
}
PROMOTED_ENTRY(144, sub_8326AA88, 0x8326AA88) { ctx.r3.u64 = Construct_TXT_8349C750_G_(ctx, base); }

uint64_t Construct_TXT_8349C754_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C754_G_ = int32_t(0x8349C754);
	constexpr int32_t str_TXT_820E3034_B_ = int32_t(0x820E3034);
	constexpr int32_t Destroy_TXT_8349C754_G__address = int32_t(0x832A8098);
	if (!UseLiftedCode(144, 0x8326AAC8)) { __imp__sub_8326AAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C754_G_, str_TXT_820E3034_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C754_G__address);
}
PROMOTED_ENTRY(144, sub_8326AAC8, 0x8326AAC8) { ctx.r3.u64 = Construct_TXT_8349C754_G_(ctx, base); }

uint64_t Construct_TXT_8349C758_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C758_G_ = int32_t(0x8349C758);
	constexpr int32_t str_TXT_820E304C_B_ = int32_t(0x820E304C);
	constexpr int32_t Destroy_TXT_8349C758_G__address = int32_t(0x832A80A8);
	if (!UseLiftedCode(144, 0x8326AB08)) { __imp__sub_8326AB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C758_G_, str_TXT_820E304C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C758_G__address);
}
PROMOTED_ENTRY(144, sub_8326AB08, 0x8326AB08) { ctx.r3.u64 = Construct_TXT_8349C758_G_(ctx, base); }

uint64_t Construct_TXT_8349C75C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C75C_G_ = int32_t(0x8349C75C);
	constexpr int32_t str_TXT_820E305C_B_ = int32_t(0x820E305C);
	constexpr int32_t Destroy_TXT_8349C75C_G__address = int32_t(0x832A80B8);
	if (!UseLiftedCode(144, 0x8326AB48)) { __imp__sub_8326AB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C75C_G_, str_TXT_820E305C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C75C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AB48, 0x8326AB48) { ctx.r3.u64 = Construct_TXT_8349C75C_G_(ctx, base); }

uint64_t Construct_TXT_8349C760_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C760_G_ = int32_t(0x8349C760);
	constexpr int32_t str_TXT_820E3070_B_ = int32_t(0x820E3070);
	constexpr int32_t Destroy_TXT_8349C760_G__address = int32_t(0x832A80C8);
	if (!UseLiftedCode(144, 0x8326AB88)) { __imp__sub_8326AB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C760_G_, str_TXT_820E3070_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C760_G__address);
}
PROMOTED_ENTRY(144, sub_8326AB88, 0x8326AB88) { ctx.r3.u64 = Construct_TXT_8349C760_G_(ctx, base); }

uint64_t Construct_TXT_8349C764_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C764_G_ = int32_t(0x8349C764);
	constexpr int32_t str_TXT_820E3088_B_ = int32_t(0x820E3088);
	constexpr int32_t Destroy_TXT_8349C764_G__address = int32_t(0x832A80D8);
	if (!UseLiftedCode(144, 0x8326ABC8)) { __imp__sub_8326ABC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ABC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C764_G_, str_TXT_820E3088_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C764_G__address);
}
PROMOTED_ENTRY(144, sub_8326ABC8, 0x8326ABC8) { ctx.r3.u64 = Construct_TXT_8349C764_G_(ctx, base); }

uint64_t Construct_TXT_8349C768_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C768_G_ = int32_t(0x8349C768);
	constexpr int32_t str_TXT_820E309C_B_ = int32_t(0x820E309C);
	constexpr int32_t Destroy_TXT_8349C768_G__address = int32_t(0x832A80E8);
	if (!UseLiftedCode(144, 0x8326AC08)) { __imp__sub_8326AC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C768_G_, str_TXT_820E309C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C768_G__address);
}
PROMOTED_ENTRY(144, sub_8326AC08, 0x8326AC08) { ctx.r3.u64 = Construct_TXT_8349C768_G_(ctx, base); }

uint64_t Construct_TXT_8349C76C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C76C_G_ = int32_t(0x8349C76C);
	constexpr int32_t str_TXT_820E30AC_B_ = int32_t(0x820E30AC);
	constexpr int32_t Destroy_TXT_8349C76C_G__address = int32_t(0x832A80F8);
	if (!UseLiftedCode(144, 0x8326AC48)) { __imp__sub_8326AC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C76C_G_, str_TXT_820E30AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C76C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AC48, 0x8326AC48) { ctx.r3.u64 = Construct_TXT_8349C76C_G_(ctx, base); }

uint64_t Construct_TXT_8349C770_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C770_G_ = int32_t(0x8349C770);
	constexpr int32_t str_TXT_820E30C8_B_ = int32_t(0x820E30C8);
	constexpr int32_t Destroy_TXT_8349C770_G__address = int32_t(0x832A8108);
	if (!UseLiftedCode(144, 0x8326AC88)) { __imp__sub_8326AC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C770_G_, str_TXT_820E30C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C770_G__address);
}
PROMOTED_ENTRY(144, sub_8326AC88, 0x8326AC88) { ctx.r3.u64 = Construct_TXT_8349C770_G_(ctx, base); }

uint64_t Construct_TXT_8349C774_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C774_G_ = int32_t(0x8349C774);
	constexpr int32_t str_TXT_820E30D8_B_ = int32_t(0x820E30D8);
	constexpr int32_t Destroy_TXT_8349C774_G__address = int32_t(0x832A8118);
	if (!UseLiftedCode(144, 0x8326ACC8)) { __imp__sub_8326ACC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ACC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C774_G_, str_TXT_820E30D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C774_G__address);
}
PROMOTED_ENTRY(144, sub_8326ACC8, 0x8326ACC8) { ctx.r3.u64 = Construct_TXT_8349C774_G_(ctx, base); }

uint64_t Construct_TXT_8349C778_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C778_G_ = int32_t(0x8349C778);
	constexpr int32_t str_TXT_820E30F0_B_ = int32_t(0x820E30F0);
	constexpr int32_t Destroy_TXT_8349C778_G__address = int32_t(0x832A8128);
	if (!UseLiftedCode(144, 0x8326AD08)) { __imp__sub_8326AD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C778_G_, str_TXT_820E30F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C778_G__address);
}
PROMOTED_ENTRY(144, sub_8326AD08, 0x8326AD08) { ctx.r3.u64 = Construct_TXT_8349C778_G_(ctx, base); }

uint64_t Construct_TXT_8349C77C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C77C_G_ = int32_t(0x8349C77C);
	constexpr int32_t str_TXT_820E3108_B_ = int32_t(0x820E3108);
	constexpr int32_t Destroy_TXT_8349C77C_G__address = int32_t(0x832A8138);
	if (!UseLiftedCode(144, 0x8326AD48)) { __imp__sub_8326AD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C77C_G_, str_TXT_820E3108_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C77C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AD48, 0x8326AD48) { ctx.r3.u64 = Construct_TXT_8349C77C_G_(ctx, base); }

uint64_t Construct_TXT_8349C780_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C780_G_ = int32_t(0x8349C780);
	constexpr int32_t str_TXT_820E311C_B_ = int32_t(0x820E311C);
	constexpr int32_t Destroy_TXT_8349C780_G__address = int32_t(0x832A8148);
	if (!UseLiftedCode(144, 0x8326AD88)) { __imp__sub_8326AD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C780_G_, str_TXT_820E311C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C780_G__address);
}
PROMOTED_ENTRY(144, sub_8326AD88, 0x8326AD88) { ctx.r3.u64 = Construct_TXT_8349C780_G_(ctx, base); }

uint64_t Construct_TXT_8349C784_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C784_G_ = int32_t(0x8349C784);
	constexpr int32_t str_TXT_820E3128_B_ = int32_t(0x820E3128);
	constexpr int32_t Destroy_TXT_8349C784_G__address = int32_t(0x832A8158);
	if (!UseLiftedCode(144, 0x8326ADC8)) { __imp__sub_8326ADC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ADC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C784_G_, str_TXT_820E3128_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C784_G__address);
}
PROMOTED_ENTRY(144, sub_8326ADC8, 0x8326ADC8) { ctx.r3.u64 = Construct_TXT_8349C784_G_(ctx, base); }

uint64_t Construct_TXT_8349C788_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C788_G_ = int32_t(0x8349C788);
	constexpr int32_t str_TXT_820E3140_B_ = int32_t(0x820E3140);
	constexpr int32_t Destroy_TXT_8349C788_G__address = int32_t(0x832A8168);
	if (!UseLiftedCode(144, 0x8326AE08)) { __imp__sub_8326AE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C788_G_, str_TXT_820E3140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C788_G__address);
}
PROMOTED_ENTRY(144, sub_8326AE08, 0x8326AE08) { ctx.r3.u64 = Construct_TXT_8349C788_G_(ctx, base); }

uint64_t Construct_TXT_8349C78C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C78C_G_ = int32_t(0x8349C78C);
	constexpr int32_t str_TXT_820E3154_B_ = int32_t(0x820E3154);
	constexpr int32_t Destroy_TXT_8349C78C_G__address = int32_t(0x832A8178);
	if (!UseLiftedCode(144, 0x8326AE48)) { __imp__sub_8326AE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C78C_G_, str_TXT_820E3154_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C78C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AE48, 0x8326AE48) { ctx.r3.u64 = Construct_TXT_8349C78C_G_(ctx, base); }

uint64_t Construct_TXT_8349C790_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C790_G_ = int32_t(0x8349C790);
	constexpr int32_t str_TXT_820E3168_B_ = int32_t(0x820E3168);
	constexpr int32_t Destroy_TXT_8349C790_G__address = int32_t(0x832A8188);
	if (!UseLiftedCode(144, 0x8326AE88)) { __imp__sub_8326AE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C790_G_, str_TXT_820E3168_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C790_G__address);
}
PROMOTED_ENTRY(144, sub_8326AE88, 0x8326AE88) { ctx.r3.u64 = Construct_TXT_8349C790_G_(ctx, base); }

uint64_t Construct_TXT_8349C794_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C794_G_ = int32_t(0x8349C794);
	constexpr int32_t str_TXT_820E317C_B_ = int32_t(0x820E317C);
	constexpr int32_t Destroy_TXT_8349C794_G__address = int32_t(0x832A8198);
	if (!UseLiftedCode(144, 0x8326AEC8)) { __imp__sub_8326AEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C794_G_, str_TXT_820E317C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C794_G__address);
}
PROMOTED_ENTRY(144, sub_8326AEC8, 0x8326AEC8) { ctx.r3.u64 = Construct_TXT_8349C794_G_(ctx, base); }

uint64_t Construct_TXT_8349C798_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C798_G_ = int32_t(0x8349C798);
	constexpr int32_t str_TXT_820E3190_B_ = int32_t(0x820E3190);
	constexpr int32_t Destroy_TXT_8349C798_G__address = int32_t(0x832A81A8);
	if (!UseLiftedCode(144, 0x8326AF08)) { __imp__sub_8326AF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C798_G_, str_TXT_820E3190_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C798_G__address);
}
PROMOTED_ENTRY(144, sub_8326AF08, 0x8326AF08) { ctx.r3.u64 = Construct_TXT_8349C798_G_(ctx, base); }

uint64_t Construct_TXT_8349C79C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C79C_G_ = int32_t(0x8349C79C);
	constexpr int32_t str_TXT_820E31A8_B_ = int32_t(0x820E31A8);
	constexpr int32_t Destroy_TXT_8349C79C_G__address = int32_t(0x832A81B8);
	if (!UseLiftedCode(144, 0x8326AF48)) { __imp__sub_8326AF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C79C_G_, str_TXT_820E31A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C79C_G__address);
}
PROMOTED_ENTRY(144, sub_8326AF48, 0x8326AF48) { ctx.r3.u64 = Construct_TXT_8349C79C_G_(ctx, base); }

uint64_t Construct_TXT_8349C7A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7A0_G_ = int32_t(0x8349C7A0);
	constexpr int32_t str_TXT_820E31BC_B_ = int32_t(0x820E31BC);
	constexpr int32_t Destroy_TXT_8349C7A0_G__address = int32_t(0x832A81C8);
	if (!UseLiftedCode(144, 0x8326AF88)) { __imp__sub_8326AF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A0_G_, str_TXT_820E31BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7A0_G__address);
}
PROMOTED_ENTRY(144, sub_8326AF88, 0x8326AF88) { ctx.r3.u64 = Construct_TXT_8349C7A0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7A4_G_ = int32_t(0x8349C7A4);
	constexpr int32_t str_TXT_820E31D8_B_ = int32_t(0x820E31D8);
	constexpr int32_t Destroy_TXT_8349C7A4_G__address = int32_t(0x832A81D8);
	if (!UseLiftedCode(144, 0x8326AFC8)) { __imp__sub_8326AFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A4_G_, str_TXT_820E31D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7A4_G__address);
}
PROMOTED_ENTRY(144, sub_8326AFC8, 0x8326AFC8) { ctx.r3.u64 = Construct_TXT_8349C7A4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7A8_G_ = int32_t(0x8349C7A8);
	constexpr int32_t str_TXT_820E31F4_B_ = int32_t(0x820E31F4);
	constexpr int32_t Destroy_TXT_8349C7A8_G__address = int32_t(0x832A81E8);
	if (!UseLiftedCode(144, 0x8326B008)) { __imp__sub_8326B008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A8_G_, str_TXT_820E31F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7A8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B008, 0x8326B008) { ctx.r3.u64 = Construct_TXT_8349C7A8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7AC_G_ = int32_t(0x8349C7AC);
	constexpr int32_t str_TXT_820E3208_B_ = int32_t(0x820E3208);
	constexpr int32_t Destroy_TXT_8349C7AC_G__address = int32_t(0x832A81F8);
	if (!UseLiftedCode(144, 0x8326B048)) { __imp__sub_8326B048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7AC_G_, str_TXT_820E3208_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7AC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B048, 0x8326B048) { ctx.r3.u64 = Construct_TXT_8349C7AC_G_(ctx, base); }

uint64_t Construct_TXT_8349C7B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7B0_G_ = int32_t(0x8349C7B0);
	constexpr int32_t str_TXT_820E321C_B_ = int32_t(0x820E321C);
	constexpr int32_t Destroy_TXT_8349C7B0_G__address = int32_t(0x832A8208);
	if (!UseLiftedCode(144, 0x8326B088)) { __imp__sub_8326B088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B0_G_, str_TXT_820E321C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7B0_G__address);
}
PROMOTED_ENTRY(144, sub_8326B088, 0x8326B088) { ctx.r3.u64 = Construct_TXT_8349C7B0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7B4_G_ = int32_t(0x8349C7B4);
	constexpr int32_t str_TXT_820E3234_B_ = int32_t(0x820E3234);
	constexpr int32_t Destroy_TXT_8349C7B4_G__address = int32_t(0x832A8218);
	if (!UseLiftedCode(144, 0x8326B0C8)) { __imp__sub_8326B0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B4_G_, str_TXT_820E3234_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7B4_G__address);
}
PROMOTED_ENTRY(144, sub_8326B0C8, 0x8326B0C8) { ctx.r3.u64 = Construct_TXT_8349C7B4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7B8_G_ = int32_t(0x8349C7B8);
	constexpr int32_t str_TXT_820E324C_B_ = int32_t(0x820E324C);
	constexpr int32_t Destroy_TXT_8349C7B8_G__address = int32_t(0x832A8228);
	if (!UseLiftedCode(144, 0x8326B108)) { __imp__sub_8326B108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B8_G_, str_TXT_820E324C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7B8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B108, 0x8326B108) { ctx.r3.u64 = Construct_TXT_8349C7B8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7BC_G_ = int32_t(0x8349C7BC);
	constexpr int32_t str_TXT_820E3264_B_ = int32_t(0x820E3264);
	constexpr int32_t Destroy_TXT_8349C7BC_G__address = int32_t(0x832A8238);
	if (!UseLiftedCode(144, 0x8326B148)) { __imp__sub_8326B148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7BC_G_, str_TXT_820E3264_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7BC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B148, 0x8326B148) { ctx.r3.u64 = Construct_TXT_8349C7BC_G_(ctx, base); }

uint64_t Construct_TXT_8349C7C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7C0_G_ = int32_t(0x8349C7C0);
	constexpr int32_t str_TXT_820E3280_B_ = int32_t(0x820E3280);
	constexpr int32_t Destroy_TXT_8349C7C0_G__address = int32_t(0x832A8248);
	if (!UseLiftedCode(144, 0x8326B188)) { __imp__sub_8326B188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C0_G_, str_TXT_820E3280_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7C0_G__address);
}
PROMOTED_ENTRY(144, sub_8326B188, 0x8326B188) { ctx.r3.u64 = Construct_TXT_8349C7C0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7C4_G_ = int32_t(0x8349C7C4);
	constexpr int32_t str_TXT_820E3294_B_ = int32_t(0x820E3294);
	constexpr int32_t Destroy_TXT_8349C7C4_G__address = int32_t(0x832A8258);
	if (!UseLiftedCode(144, 0x8326B1C8)) { __imp__sub_8326B1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B1C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C4_G_, str_TXT_820E3294_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7C4_G__address);
}
PROMOTED_ENTRY(144, sub_8326B1C8, 0x8326B1C8) { ctx.r3.u64 = Construct_TXT_8349C7C4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7C8_G_ = int32_t(0x8349C7C8);
	constexpr int32_t str_TXT_820E32A8_B_ = int32_t(0x820E32A8);
	constexpr int32_t Destroy_TXT_8349C7C8_G__address = int32_t(0x832A8268);
	if (!UseLiftedCode(144, 0x8326B208)) { __imp__sub_8326B208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B208);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C8_G_, str_TXT_820E32A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7C8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B208, 0x8326B208) { ctx.r3.u64 = Construct_TXT_8349C7C8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7CC_G_ = int32_t(0x8349C7CC);
	constexpr int32_t str_TXT_820E32BC_B_ = int32_t(0x820E32BC);
	constexpr int32_t Destroy_TXT_8349C7CC_G__address = int32_t(0x832A8278);
	if (!UseLiftedCode(144, 0x8326B248)) { __imp__sub_8326B248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B248);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7CC_G_, str_TXT_820E32BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7CC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B248, 0x8326B248) { ctx.r3.u64 = Construct_TXT_8349C7CC_G_(ctx, base); }

uint64_t Construct_TXT_8349C7D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7D0_G_ = int32_t(0x8349C7D0);
	constexpr int32_t str_TXT_820E32D8_B_ = int32_t(0x820E32D8);
	constexpr int32_t Destroy_TXT_8349C7D0_G__address = int32_t(0x832A8288);
	if (!UseLiftedCode(144, 0x8326B288)) { __imp__sub_8326B288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B288);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D0_G_, str_TXT_820E32D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7D0_G__address);
}
PROMOTED_ENTRY(144, sub_8326B288, 0x8326B288) { ctx.r3.u64 = Construct_TXT_8349C7D0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7D4_G_ = int32_t(0x8349C7D4);
	constexpr int32_t str_TXT_820E32F4_B_ = int32_t(0x820E32F4);
	constexpr int32_t Destroy_TXT_8349C7D4_G__address = int32_t(0x832A8298);
	if (!UseLiftedCode(144, 0x8326B2C8)) { __imp__sub_8326B2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B2C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D4_G_, str_TXT_820E32F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7D4_G__address);
}
PROMOTED_ENTRY(144, sub_8326B2C8, 0x8326B2C8) { ctx.r3.u64 = Construct_TXT_8349C7D4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7D8_G_ = int32_t(0x8349C7D8);
	constexpr int32_t str_TXT_820E3314_B_ = int32_t(0x820E3314);
	constexpr int32_t Destroy_TXT_8349C7D8_G__address = int32_t(0x832A82A8);
	if (!UseLiftedCode(144, 0x8326B308)) { __imp__sub_8326B308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D8_G_, str_TXT_820E3314_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7D8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B308, 0x8326B308) { ctx.r3.u64 = Construct_TXT_8349C7D8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7DC_G_ = int32_t(0x8349C7DC);
	constexpr int32_t str_TXT_820E332C_B_ = int32_t(0x820E332C);
	constexpr int32_t Destroy_TXT_8349C7DC_G__address = int32_t(0x832A82B8);
	if (!UseLiftedCode(144, 0x8326B348)) { __imp__sub_8326B348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7DC_G_, str_TXT_820E332C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7DC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B348, 0x8326B348) { ctx.r3.u64 = Construct_TXT_8349C7DC_G_(ctx, base); }

uint64_t Construct_TXT_8349C7E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7E0_G_ = int32_t(0x8349C7E0);
	constexpr int32_t str_TXT_820E3344_B_ = int32_t(0x820E3344);
	constexpr int32_t Destroy_TXT_8349C7E0_G__address = int32_t(0x832A82C8);
	if (!UseLiftedCode(144, 0x8326B388)) { __imp__sub_8326B388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E0_G_, str_TXT_820E3344_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7E0_G__address);
}
PROMOTED_ENTRY(144, sub_8326B388, 0x8326B388) { ctx.r3.u64 = Construct_TXT_8349C7E0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7E4_G_ = int32_t(0x8349C7E4);
	constexpr int32_t str_TXT_820E335C_B_ = int32_t(0x820E335C);
	constexpr int32_t Destroy_TXT_8349C7E4_G__address = int32_t(0x832A82D8);
	if (!UseLiftedCode(144, 0x8326B3C8)) { __imp__sub_8326B3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B3C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E4_G_, str_TXT_820E335C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7E4_G__address);
}
PROMOTED_ENTRY(144, sub_8326B3C8, 0x8326B3C8) { ctx.r3.u64 = Construct_TXT_8349C7E4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7E8_G_ = int32_t(0x8349C7E8);
	constexpr int32_t str_TXT_820E3378_B_ = int32_t(0x820E3378);
	constexpr int32_t Destroy_TXT_8349C7E8_G__address = int32_t(0x832A82E8);
	if (!UseLiftedCode(144, 0x8326B408)) { __imp__sub_8326B408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E8_G_, str_TXT_820E3378_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7E8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B408, 0x8326B408) { ctx.r3.u64 = Construct_TXT_8349C7E8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7EC_G_ = int32_t(0x8349C7EC);
	constexpr int32_t str_TXT_820E3394_B_ = int32_t(0x820E3394);
	constexpr int32_t Destroy_TXT_8349C7EC_G__address = int32_t(0x832A82F8);
	if (!UseLiftedCode(144, 0x8326B448)) { __imp__sub_8326B448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7EC_G_, str_TXT_820E3394_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7EC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B448, 0x8326B448) { ctx.r3.u64 = Construct_TXT_8349C7EC_G_(ctx, base); }

uint64_t Construct_TXT_8349C7F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7F0_G_ = int32_t(0x8349C7F0);
	constexpr int32_t str_TXT_820E33B4_B_ = int32_t(0x820E33B4);
	constexpr int32_t Destroy_TXT_8349C7F0_G__address = int32_t(0x832A8308);
	if (!UseLiftedCode(144, 0x8326B488)) { __imp__sub_8326B488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F0_G_, str_TXT_820E33B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7F0_G__address);
}
PROMOTED_ENTRY(144, sub_8326B488, 0x8326B488) { ctx.r3.u64 = Construct_TXT_8349C7F0_G_(ctx, base); }

uint64_t Construct_TXT_8349C7F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7F4_G_ = int32_t(0x8349C7F4);
	constexpr int32_t str_TXT_820E33D0_B_ = int32_t(0x820E33D0);
	constexpr int32_t Destroy_TXT_8349C7F4_G__address = int32_t(0x832A8318);
	if (!UseLiftedCode(144, 0x8326B4C8)) { __imp__sub_8326B4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B4C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F4_G_, str_TXT_820E33D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7F4_G__address);
}
PROMOTED_ENTRY(144, sub_8326B4C8, 0x8326B4C8) { ctx.r3.u64 = Construct_TXT_8349C7F4_G_(ctx, base); }

uint64_t Construct_TXT_8349C7F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7F8_G_ = int32_t(0x8349C7F8);
	constexpr int32_t str_TXT_820E33E8_B_ = int32_t(0x820E33E8);
	constexpr int32_t Destroy_TXT_8349C7F8_G__address = int32_t(0x832A8328);
	if (!UseLiftedCode(144, 0x8326B508)) { __imp__sub_8326B508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F8_G_, str_TXT_820E33E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7F8_G__address);
}
PROMOTED_ENTRY(144, sub_8326B508, 0x8326B508) { ctx.r3.u64 = Construct_TXT_8349C7F8_G_(ctx, base); }

uint64_t Construct_TXT_8349C7FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C7FC_G_ = int32_t(0x8349C7FC);
	constexpr int32_t str_TXT_820E33FC_B_ = int32_t(0x820E33FC);
	constexpr int32_t Destroy_TXT_8349C7FC_G__address = int32_t(0x832A8338);
	if (!UseLiftedCode(144, 0x8326B548)) { __imp__sub_8326B548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7FC_G_, str_TXT_820E33FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C7FC_G__address);
}
PROMOTED_ENTRY(144, sub_8326B548, 0x8326B548) { ctx.r3.u64 = Construct_TXT_8349C7FC_G_(ctx, base); }

uint64_t Construct_TXT_8349C800_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C800_G_ = int32_t(0x8349C800);
	constexpr int32_t str_TXT_820E3414_B_ = int32_t(0x820E3414);
	constexpr int32_t Destroy_TXT_8349C800_G__address = int32_t(0x832A8348);
	if (!UseLiftedCode(144, 0x8326B588)) { __imp__sub_8326B588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C800_G_, str_TXT_820E3414_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C800_G__address);
}
PROMOTED_ENTRY(144, sub_8326B588, 0x8326B588) { ctx.r3.u64 = Construct_TXT_8349C800_G_(ctx, base); }

uint64_t Construct_TXT_8349C804_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C804_G_ = int32_t(0x8349C804);
	constexpr int32_t str_TXT_820E3430_B_ = int32_t(0x820E3430);
	constexpr int32_t Destroy_TXT_8349C804_G__address = int32_t(0x832A8358);
	if (!UseLiftedCode(144, 0x8326B5C8)) { __imp__sub_8326B5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B5C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C804_G_, str_TXT_820E3430_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C804_G__address);
}
PROMOTED_ENTRY(144, sub_8326B5C8, 0x8326B5C8) { ctx.r3.u64 = Construct_TXT_8349C804_G_(ctx, base); }

uint64_t Construct_TXT_8349C808_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C808_G_ = int32_t(0x8349C808);
	constexpr int32_t str_TXT_820E3450_B_ = int32_t(0x820E3450);
	constexpr int32_t Destroy_TXT_8349C808_G__address = int32_t(0x832A8368);
	if (!UseLiftedCode(144, 0x8326B608)) { __imp__sub_8326B608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C808_G_, str_TXT_820E3450_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C808_G__address);
}
PROMOTED_ENTRY(144, sub_8326B608, 0x8326B608) { ctx.r3.u64 = Construct_TXT_8349C808_G_(ctx, base); }

uint64_t Construct_TXT_8349C80C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C80C_G_ = int32_t(0x8349C80C);
	constexpr int32_t str_TXT_820E3470_B_ = int32_t(0x820E3470);
	constexpr int32_t Destroy_TXT_8349C80C_G__address = int32_t(0x832A8378);
	if (!UseLiftedCode(144, 0x8326B648)) { __imp__sub_8326B648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B648);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C80C_G_, str_TXT_820E3470_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C80C_G__address);
}
PROMOTED_ENTRY(144, sub_8326B648, 0x8326B648) { ctx.r3.u64 = Construct_TXT_8349C80C_G_(ctx, base); }

uint64_t Construct_TXT_8349C810_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C810_G_ = int32_t(0x8349C810);
	constexpr int32_t str_TXT_820E3488_B_ = int32_t(0x820E3488);
	constexpr int32_t Destroy_TXT_8349C810_G__address = int32_t(0x832A8388);
	if (!UseLiftedCode(144, 0x8326B688)) { __imp__sub_8326B688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B688);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C810_G_, str_TXT_820E3488_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C810_G__address);
}
PROMOTED_ENTRY(144, sub_8326B688, 0x8326B688) { ctx.r3.u64 = Construct_TXT_8349C810_G_(ctx, base); }

uint64_t Construct_TXT_8349C814_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C814_G_ = int32_t(0x8349C814);
	constexpr int32_t str_TXT_820E349C_B_ = int32_t(0x820E349C);
	constexpr int32_t Destroy_TXT_8349C814_G__address = int32_t(0x832A8398);
	if (!UseLiftedCode(144, 0x8326B6C8)) { __imp__sub_8326B6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B6C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C814_G_, str_TXT_820E349C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C814_G__address);
}
PROMOTED_ENTRY(144, sub_8326B6C8, 0x8326B6C8) { ctx.r3.u64 = Construct_TXT_8349C814_G_(ctx, base); }

uint64_t Construct_TXT_8349C818_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C818_G_ = int32_t(0x8349C818);
	constexpr int32_t str_TXT_820E34B8_B_ = int32_t(0x820E34B8);
	constexpr int32_t Destroy_TXT_8349C818_G__address = int32_t(0x832A83A8);
	if (!UseLiftedCode(144, 0x8326B708)) { __imp__sub_8326B708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C818_G_, str_TXT_820E34B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C818_G__address);
}
PROMOTED_ENTRY(144, sub_8326B708, 0x8326B708) { ctx.r3.u64 = Construct_TXT_8349C818_G_(ctx, base); }

uint64_t Construct_TXT_8349C81C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C81C_G_ = int32_t(0x8349C81C);
	constexpr int32_t str_TXT_820E34D0_B_ = int32_t(0x820E34D0);
	constexpr int32_t Destroy_TXT_8349C81C_G__address = int32_t(0x832A83B8);
	if (!UseLiftedCode(144, 0x8326B748)) { __imp__sub_8326B748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B748);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C81C_G_, str_TXT_820E34D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C81C_G__address);
}
PROMOTED_ENTRY(144, sub_8326B748, 0x8326B748) { ctx.r3.u64 = Construct_TXT_8349C81C_G_(ctx, base); }

uint64_t Construct_TXT_8349C820_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C820_G_ = int32_t(0x8349C820);
	constexpr int32_t str_TXT_820E34E8_B_ = int32_t(0x820E34E8);
	constexpr int32_t Destroy_TXT_8349C820_G__address = int32_t(0x832A83C8);
	if (!UseLiftedCode(144, 0x8326B788)) { __imp__sub_8326B788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C820_G_, str_TXT_820E34E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C820_G__address);
}
PROMOTED_ENTRY(144, sub_8326B788, 0x8326B788) { ctx.r3.u64 = Construct_TXT_8349C820_G_(ctx, base); }

uint64_t Construct_TXT_8349C824_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C824_G_ = int32_t(0x8349C824);
	constexpr int32_t str_TXT_820E3504_B_ = int32_t(0x820E3504);
	constexpr int32_t Destroy_TXT_8349C824_G__address = int32_t(0x832A83D8);
	if (!UseLiftedCode(144, 0x8326B7C8)) { __imp__sub_8326B7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B7C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C824_G_, str_TXT_820E3504_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C824_G__address);
}
PROMOTED_ENTRY(144, sub_8326B7C8, 0x8326B7C8) { ctx.r3.u64 = Construct_TXT_8349C824_G_(ctx, base); }

uint64_t Construct_TXT_8349C828_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C828_G_ = int32_t(0x8349C828);
	constexpr int32_t str_TXT_820E3520_B_ = int32_t(0x820E3520);
	constexpr int32_t Destroy_TXT_8349C828_G__address = int32_t(0x832A83E8);
	if (!UseLiftedCode(144, 0x8326B808)) { __imp__sub_8326B808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C828_G_, str_TXT_820E3520_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C828_G__address);
}
PROMOTED_ENTRY(144, sub_8326B808, 0x8326B808) { ctx.r3.u64 = Construct_TXT_8349C828_G_(ctx, base); }

uint64_t Construct_TXT_8349C82C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C82C_G_ = int32_t(0x8349C82C);
	constexpr int32_t str_TXT_820E3538_B_ = int32_t(0x820E3538);
	constexpr int32_t Destroy_TXT_8349C82C_G__address = int32_t(0x832A83F8);
	if (!UseLiftedCode(144, 0x8326B848)) { __imp__sub_8326B848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B848);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C82C_G_, str_TXT_820E3538_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C82C_G__address);
}
PROMOTED_ENTRY(144, sub_8326B848, 0x8326B848) { ctx.r3.u64 = Construct_TXT_8349C82C_G_(ctx, base); }

uint64_t Construct_TXT_8349C830_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C830_G_ = int32_t(0x8349C830);
	constexpr int32_t str_TXT_820E3558_B_ = int32_t(0x820E3558);
	constexpr int32_t Destroy_TXT_8349C830_G__address = int32_t(0x832A8408);
	if (!UseLiftedCode(144, 0x8326B888)) { __imp__sub_8326B888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B888);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C830_G_, str_TXT_820E3558_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C830_G__address);
}
PROMOTED_ENTRY(144, sub_8326B888, 0x8326B888) { ctx.r3.u64 = Construct_TXT_8349C830_G_(ctx, base); }

uint64_t Construct_TXT_8349C834_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C834_G_ = int32_t(0x8349C834);
	constexpr int32_t str_TXT_820E3574_B_ = int32_t(0x820E3574);
	constexpr int32_t Destroy_TXT_8349C834_G__address = int32_t(0x832A8418);
	if (!UseLiftedCode(144, 0x8326B8C8)) { __imp__sub_8326B8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C834_G_, str_TXT_820E3574_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C834_G__address);
}
PROMOTED_ENTRY(144, sub_8326B8C8, 0x8326B8C8) { ctx.r3.u64 = Construct_TXT_8349C834_G_(ctx, base); }

uint64_t Construct_TXT_8349C838_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C838_G_ = int32_t(0x8349C838);
	constexpr int32_t str_TXT_820E3590_B_ = int32_t(0x820E3590);
	constexpr int32_t Destroy_TXT_8349C838_G__address = int32_t(0x832A8428);
	if (!UseLiftedCode(144, 0x8326B908)) { __imp__sub_8326B908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C838_G_, str_TXT_820E3590_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C838_G__address);
}
PROMOTED_ENTRY(144, sub_8326B908, 0x8326B908) { ctx.r3.u64 = Construct_TXT_8349C838_G_(ctx, base); }

uint64_t Construct_TXT_8349C83C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C83C_G_ = int32_t(0x8349C83C);
	constexpr int32_t str_TXT_820E35B0_B_ = int32_t(0x820E35B0);
	constexpr int32_t Destroy_TXT_8349C83C_G__address = int32_t(0x832A8438);
	if (!UseLiftedCode(144, 0x8326B948)) { __imp__sub_8326B948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C83C_G_, str_TXT_820E35B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C83C_G__address);
}
PROMOTED_ENTRY(144, sub_8326B948, 0x8326B948) { ctx.r3.u64 = Construct_TXT_8349C83C_G_(ctx, base); }

uint64_t Construct_TXT_8349C840_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C840_G_ = int32_t(0x8349C840);
	constexpr int32_t str_TXT_820E35D0_B_ = int32_t(0x820E35D0);
	constexpr int32_t Destroy_TXT_8349C840_G__address = int32_t(0x832A8448);
	if (!UseLiftedCode(144, 0x8326B988)) { __imp__sub_8326B988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C840_G_, str_TXT_820E35D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C840_G__address);
}
PROMOTED_ENTRY(144, sub_8326B988, 0x8326B988) { ctx.r3.u64 = Construct_TXT_8349C840_G_(ctx, base); }

uint64_t Construct_TXT_8349C844_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C844_G_ = int32_t(0x8349C844);
	constexpr int32_t str_TXT_820E35EC_B_ = int32_t(0x820E35EC);
	constexpr int32_t Destroy_TXT_8349C844_G__address = int32_t(0x832A8458);
	if (!UseLiftedCode(144, 0x8326B9C8)) { __imp__sub_8326B9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B9C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C844_G_, str_TXT_820E35EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C844_G__address);
}
PROMOTED_ENTRY(144, sub_8326B9C8, 0x8326B9C8) { ctx.r3.u64 = Construct_TXT_8349C844_G_(ctx, base); }

uint64_t Construct_TXT_8349C848_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C848_G_ = int32_t(0x8349C848);
	constexpr int32_t str_TXT_820E3608_B_ = int32_t(0x820E3608);
	constexpr int32_t Destroy_TXT_8349C848_G__address = int32_t(0x832A8468);
	if (!UseLiftedCode(144, 0x8326BA08)) { __imp__sub_8326BA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C848_G_, str_TXT_820E3608_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C848_G__address);
}
PROMOTED_ENTRY(144, sub_8326BA08, 0x8326BA08) { ctx.r3.u64 = Construct_TXT_8349C848_G_(ctx, base); }

uint64_t Construct_TXT_8349C84C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C84C_G_ = int32_t(0x8349C84C);
	constexpr int32_t str_TXT_820E3624_B_ = int32_t(0x820E3624);
	constexpr int32_t Destroy_TXT_8349C84C_G__address = int32_t(0x832A8478);
	if (!UseLiftedCode(144, 0x8326BA48)) { __imp__sub_8326BA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C84C_G_, str_TXT_820E3624_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C84C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BA48, 0x8326BA48) { ctx.r3.u64 = Construct_TXT_8349C84C_G_(ctx, base); }

uint64_t Construct_TXT_8349C850_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C850_G_ = int32_t(0x8349C850);
	constexpr int32_t str_TXT_820E3644_B_ = int32_t(0x820E3644);
	constexpr int32_t Destroy_TXT_8349C850_G__address = int32_t(0x832A8488);
	if (!UseLiftedCode(144, 0x8326BA88)) { __imp__sub_8326BA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C850_G_, str_TXT_820E3644_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C850_G__address);
}
PROMOTED_ENTRY(144, sub_8326BA88, 0x8326BA88) { ctx.r3.u64 = Construct_TXT_8349C850_G_(ctx, base); }

uint64_t Construct_TXT_8349C854_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C854_G_ = int32_t(0x8349C854);
	constexpr int32_t str_TXT_820E3668_B_ = int32_t(0x820E3668);
	constexpr int32_t Destroy_TXT_8349C854_G__address = int32_t(0x832A8498);
	if (!UseLiftedCode(144, 0x8326BAC8)) { __imp__sub_8326BAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C854_G_, str_TXT_820E3668_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C854_G__address);
}
PROMOTED_ENTRY(144, sub_8326BAC8, 0x8326BAC8) { ctx.r3.u64 = Construct_TXT_8349C854_G_(ctx, base); }

uint64_t Construct_TXT_8349C858_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C858_G_ = int32_t(0x8349C858);
	constexpr int32_t str_TXT_820E367C_B_ = int32_t(0x820E367C);
	constexpr int32_t Destroy_TXT_8349C858_G__address = int32_t(0x832A84A8);
	if (!UseLiftedCode(144, 0x8326BB08)) { __imp__sub_8326BB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C858_G_, str_TXT_820E367C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C858_G__address);
}
PROMOTED_ENTRY(144, sub_8326BB08, 0x8326BB08) { ctx.r3.u64 = Construct_TXT_8349C858_G_(ctx, base); }

uint64_t Construct_TXT_8349C85C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C85C_G_ = int32_t(0x8349C85C);
	constexpr int32_t str_TXT_820E3690_B_ = int32_t(0x820E3690);
	constexpr int32_t Destroy_TXT_8349C85C_G__address = int32_t(0x832A84B8);
	if (!UseLiftedCode(144, 0x8326BB48)) { __imp__sub_8326BB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C85C_G_, str_TXT_820E3690_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C85C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BB48, 0x8326BB48) { ctx.r3.u64 = Construct_TXT_8349C85C_G_(ctx, base); }

uint64_t Construct_TXT_8349C860_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C860_G_ = int32_t(0x8349C860);
	constexpr int32_t str_TXT_820E36A4_B_ = int32_t(0x820E36A4);
	constexpr int32_t Destroy_TXT_8349C860_G__address = int32_t(0x832A84C8);
	if (!UseLiftedCode(144, 0x8326BB88)) { __imp__sub_8326BB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C860_G_, str_TXT_820E36A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C860_G__address);
}
PROMOTED_ENTRY(144, sub_8326BB88, 0x8326BB88) { ctx.r3.u64 = Construct_TXT_8349C860_G_(ctx, base); }

uint64_t Construct_TXT_8349C864_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C864_G_ = int32_t(0x8349C864);
	constexpr int32_t str_TXT_820E36B8_B_ = int32_t(0x820E36B8);
	constexpr int32_t Destroy_TXT_8349C864_G__address = int32_t(0x832A84D8);
	if (!UseLiftedCode(144, 0x8326BBC8)) { __imp__sub_8326BBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BBC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C864_G_, str_TXT_820E36B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C864_G__address);
}
PROMOTED_ENTRY(144, sub_8326BBC8, 0x8326BBC8) { ctx.r3.u64 = Construct_TXT_8349C864_G_(ctx, base); }

uint64_t Construct_TXT_8349C868_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C868_G_ = int32_t(0x8349C868);
	constexpr int32_t str_TXT_820E36D0_B_ = int32_t(0x820E36D0);
	constexpr int32_t Destroy_TXT_8349C868_G__address = int32_t(0x832A84E8);
	if (!UseLiftedCode(144, 0x8326BC08)) { __imp__sub_8326BC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C868_G_, str_TXT_820E36D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C868_G__address);
}
PROMOTED_ENTRY(144, sub_8326BC08, 0x8326BC08) { ctx.r3.u64 = Construct_TXT_8349C868_G_(ctx, base); }

uint64_t Construct_TXT_8349C86C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C86C_G_ = int32_t(0x8349C86C);
	constexpr int32_t str_TXT_820E36E8_B_ = int32_t(0x820E36E8);
	constexpr int32_t Destroy_TXT_8349C86C_G__address = int32_t(0x832A84F8);
	if (!UseLiftedCode(144, 0x8326BC48)) { __imp__sub_8326BC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C86C_G_, str_TXT_820E36E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C86C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BC48, 0x8326BC48) { ctx.r3.u64 = Construct_TXT_8349C86C_G_(ctx, base); }

uint64_t Construct_TXT_8349C870_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C870_G_ = int32_t(0x8349C870);
	constexpr int32_t str_TXT_820E3700_B_ = int32_t(0x820E3700);
	constexpr int32_t Destroy_TXT_8349C870_G__address = int32_t(0x832A8508);
	if (!UseLiftedCode(144, 0x8326BC88)) { __imp__sub_8326BC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C870_G_, str_TXT_820E3700_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C870_G__address);
}
PROMOTED_ENTRY(144, sub_8326BC88, 0x8326BC88) { ctx.r3.u64 = Construct_TXT_8349C870_G_(ctx, base); }

uint64_t Construct_TXT_8349C874_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C874_G_ = int32_t(0x8349C874);
	constexpr int32_t str_TXT_820E3718_B_ = int32_t(0x820E3718);
	constexpr int32_t Destroy_TXT_8349C874_G__address = int32_t(0x832A8518);
	if (!UseLiftedCode(144, 0x8326BCC8)) { __imp__sub_8326BCC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BCC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C874_G_, str_TXT_820E3718_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C874_G__address);
}
PROMOTED_ENTRY(144, sub_8326BCC8, 0x8326BCC8) { ctx.r3.u64 = Construct_TXT_8349C874_G_(ctx, base); }

uint64_t Construct_TXT_8349C878_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C878_G_ = int32_t(0x8349C878);
	constexpr int32_t str_TXT_820E3730_B_ = int32_t(0x820E3730);
	constexpr int32_t Destroy_TXT_8349C878_G__address = int32_t(0x832A8528);
	if (!UseLiftedCode(144, 0x8326BD08)) { __imp__sub_8326BD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C878_G_, str_TXT_820E3730_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C878_G__address);
}
PROMOTED_ENTRY(144, sub_8326BD08, 0x8326BD08) { ctx.r3.u64 = Construct_TXT_8349C878_G_(ctx, base); }

uint64_t Construct_TXT_8349C87C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C87C_G_ = int32_t(0x8349C87C);
	constexpr int32_t str_TXT_820E374C_B_ = int32_t(0x820E374C);
	constexpr int32_t Destroy_TXT_8349C87C_G__address = int32_t(0x832A8538);
	if (!UseLiftedCode(144, 0x8326BD48)) { __imp__sub_8326BD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C87C_G_, str_TXT_820E374C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C87C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BD48, 0x8326BD48) { ctx.r3.u64 = Construct_TXT_8349C87C_G_(ctx, base); }

uint64_t Construct_TXT_8349C880_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C880_G_ = int32_t(0x8349C880);
	constexpr int32_t str_TXT_820E3764_B_ = int32_t(0x820E3764);
	constexpr int32_t Destroy_TXT_8349C880_G__address = int32_t(0x832A8548);
	if (!UseLiftedCode(144, 0x8326BD88)) { __imp__sub_8326BD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C880_G_, str_TXT_820E3764_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C880_G__address);
}
PROMOTED_ENTRY(144, sub_8326BD88, 0x8326BD88) { ctx.r3.u64 = Construct_TXT_8349C880_G_(ctx, base); }

uint64_t Construct_TXT_8349C884_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C884_G_ = int32_t(0x8349C884);
	constexpr int32_t str_TXT_820E3784_B_ = int32_t(0x820E3784);
	constexpr int32_t Destroy_TXT_8349C884_G__address = int32_t(0x832A8558);
	if (!UseLiftedCode(144, 0x8326BDC8)) { __imp__sub_8326BDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BDC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C884_G_, str_TXT_820E3784_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C884_G__address);
}
PROMOTED_ENTRY(144, sub_8326BDC8, 0x8326BDC8) { ctx.r3.u64 = Construct_TXT_8349C884_G_(ctx, base); }

uint64_t Construct_TXT_8349C888_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C888_G_ = int32_t(0x8349C888);
	constexpr int32_t str_TXT_820E37A4_B_ = int32_t(0x820E37A4);
	constexpr int32_t Destroy_TXT_8349C888_G__address = int32_t(0x832A8568);
	if (!UseLiftedCode(144, 0x8326BE08)) { __imp__sub_8326BE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C888_G_, str_TXT_820E37A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C888_G__address);
}
PROMOTED_ENTRY(144, sub_8326BE08, 0x8326BE08) { ctx.r3.u64 = Construct_TXT_8349C888_G_(ctx, base); }

uint64_t Construct_TXT_8349C88C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C88C_G_ = int32_t(0x8349C88C);
	constexpr int32_t str_TXT_820E37BC_B_ = int32_t(0x820E37BC);
	constexpr int32_t Destroy_TXT_8349C88C_G__address = int32_t(0x832A8578);
	if (!UseLiftedCode(144, 0x8326BE48)) { __imp__sub_8326BE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C88C_G_, str_TXT_820E37BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C88C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BE48, 0x8326BE48) { ctx.r3.u64 = Construct_TXT_8349C88C_G_(ctx, base); }

uint64_t Construct_TXT_8349C890_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C890_G_ = int32_t(0x8349C890);
	constexpr int32_t str_TXT_820E37D4_B_ = int32_t(0x820E37D4);
	constexpr int32_t Destroy_TXT_8349C890_G__address = int32_t(0x832A8588);
	if (!UseLiftedCode(144, 0x8326BE88)) { __imp__sub_8326BE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C890_G_, str_TXT_820E37D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C890_G__address);
}
PROMOTED_ENTRY(144, sub_8326BE88, 0x8326BE88) { ctx.r3.u64 = Construct_TXT_8349C890_G_(ctx, base); }

uint64_t Construct_TXT_8349C894_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C894_G_ = int32_t(0x8349C894);
	constexpr int32_t str_TXT_820E37EC_B_ = int32_t(0x820E37EC);
	constexpr int32_t Destroy_TXT_8349C894_G__address = int32_t(0x832A8598);
	if (!UseLiftedCode(144, 0x8326BEC8)) { __imp__sub_8326BEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C894_G_, str_TXT_820E37EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C894_G__address);
}
PROMOTED_ENTRY(144, sub_8326BEC8, 0x8326BEC8) { ctx.r3.u64 = Construct_TXT_8349C894_G_(ctx, base); }

uint64_t Construct_TXT_8349C898_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C898_G_ = int32_t(0x8349C898);
	constexpr int32_t str_TXT_820E3814_B_ = int32_t(0x820E3814);
	constexpr int32_t Destroy_TXT_8349C898_G__address = int32_t(0x832A85A8);
	if (!UseLiftedCode(144, 0x8326BF08)) { __imp__sub_8326BF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C898_G_, str_TXT_820E3814_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C898_G__address);
}
PROMOTED_ENTRY(144, sub_8326BF08, 0x8326BF08) { ctx.r3.u64 = Construct_TXT_8349C898_G_(ctx, base); }

uint64_t Construct_TXT_8349C89C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C89C_G_ = int32_t(0x8349C89C);
	constexpr int32_t str_TXT_820E3834_B_ = int32_t(0x820E3834);
	constexpr int32_t Destroy_TXT_8349C89C_G__address = int32_t(0x832A85B8);
	if (!UseLiftedCode(144, 0x8326BF48)) { __imp__sub_8326BF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C89C_G_, str_TXT_820E3834_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C89C_G__address);
}
PROMOTED_ENTRY(144, sub_8326BF48, 0x8326BF48) { ctx.r3.u64 = Construct_TXT_8349C89C_G_(ctx, base); }

uint64_t Construct_TXT_8349C8A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8A0_G_ = int32_t(0x8349C8A0);
	constexpr int32_t str_TXT_820E3850_B_ = int32_t(0x820E3850);
	constexpr int32_t Destroy_TXT_8349C8A0_G__address = int32_t(0x832A85C8);
	if (!UseLiftedCode(144, 0x8326BF88)) { __imp__sub_8326BF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A0_G_, str_TXT_820E3850_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8A0_G__address);
}
PROMOTED_ENTRY(144, sub_8326BF88, 0x8326BF88) { ctx.r3.u64 = Construct_TXT_8349C8A0_G_(ctx, base); }

uint64_t Construct_TXT_8349C8A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8A4_G_ = int32_t(0x8349C8A4);
	constexpr int32_t str_TXT_820E386C_B_ = int32_t(0x820E386C);
	constexpr int32_t Destroy_TXT_8349C8A4_G__address = int32_t(0x832A85D8);
	if (!UseLiftedCode(144, 0x8326BFC8)) { __imp__sub_8326BFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A4_G_, str_TXT_820E386C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8A4_G__address);
}
PROMOTED_ENTRY(144, sub_8326BFC8, 0x8326BFC8) { ctx.r3.u64 = Construct_TXT_8349C8A4_G_(ctx, base); }

uint64_t Construct_TXT_8349C8A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8A8_G_ = int32_t(0x8349C8A8);
	constexpr int32_t str_TXT_820E3884_B_ = int32_t(0x820E3884);
	constexpr int32_t Destroy_TXT_8349C8A8_G__address = int32_t(0x832A85E8);
	if (!UseLiftedCode(144, 0x8326C008)) { __imp__sub_8326C008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A8_G_, str_TXT_820E3884_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8A8_G__address);
}
PROMOTED_ENTRY(144, sub_8326C008, 0x8326C008) { ctx.r3.u64 = Construct_TXT_8349C8A8_G_(ctx, base); }

uint64_t Construct_TXT_8349C8AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8AC_G_ = int32_t(0x8349C8AC);
	constexpr int32_t str_TXT_820E3898_B_ = int32_t(0x820E3898);
	constexpr int32_t Destroy_TXT_8349C8AC_G__address = int32_t(0x832A85F8);
	if (!UseLiftedCode(144, 0x8326C048)) { __imp__sub_8326C048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8AC_G_, str_TXT_820E3898_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8AC_G__address);
}
PROMOTED_ENTRY(144, sub_8326C048, 0x8326C048) { ctx.r3.u64 = Construct_TXT_8349C8AC_G_(ctx, base); }

uint64_t Construct_TXT_8349C8B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8B0_G_ = int32_t(0x8349C8B0);
	constexpr int32_t str_TXT_820E38B4_B_ = int32_t(0x820E38B4);
	constexpr int32_t Destroy_TXT_8349C8B0_G__address = int32_t(0x832A8608);
	if (!UseLiftedCode(144, 0x8326C088)) { __imp__sub_8326C088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B0_G_, str_TXT_820E38B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8B0_G__address);
}
PROMOTED_ENTRY(144, sub_8326C088, 0x8326C088) { ctx.r3.u64 = Construct_TXT_8349C8B0_G_(ctx, base); }

uint64_t Construct_TXT_8349C8B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8B4_G_ = int32_t(0x8349C8B4);
	constexpr int32_t str_TXT_820E38CC_B_ = int32_t(0x820E38CC);
	constexpr int32_t Destroy_TXT_8349C8B4_G__address = int32_t(0x832A8618);
	if (!UseLiftedCode(144, 0x8326C0C8)) { __imp__sub_8326C0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B4_G_, str_TXT_820E38CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8B4_G__address);
}
PROMOTED_ENTRY(144, sub_8326C0C8, 0x8326C0C8) { ctx.r3.u64 = Construct_TXT_8349C8B4_G_(ctx, base); }

uint64_t Construct_TXT_8349C8B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8B8_G_ = int32_t(0x8349C8B8);
	constexpr int32_t str_TXT_820E38E8_B_ = int32_t(0x820E38E8);
	constexpr int32_t Destroy_TXT_8349C8B8_G__address = int32_t(0x832A8628);
	if (!UseLiftedCode(144, 0x8326C108)) { __imp__sub_8326C108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B8_G_, str_TXT_820E38E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8B8_G__address);
}
PROMOTED_ENTRY(144, sub_8326C108, 0x8326C108) { ctx.r3.u64 = Construct_TXT_8349C8B8_G_(ctx, base); }

uint64_t Construct_TXT_8349C8BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8BC_G_ = int32_t(0x8349C8BC);
	constexpr int32_t str_TXT_820E38FC_B_ = int32_t(0x820E38FC);
	constexpr int32_t Destroy_TXT_8349C8BC_G__address = int32_t(0x832A8638);
	if (!UseLiftedCode(144, 0x8326C148)) { __imp__sub_8326C148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8BC_G_, str_TXT_820E38FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8BC_G__address);
}
PROMOTED_ENTRY(144, sub_8326C148, 0x8326C148) { ctx.r3.u64 = Construct_TXT_8349C8BC_G_(ctx, base); }

uint64_t Construct_TXT_8349C8C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8C0_G_ = int32_t(0x8349C8C0);
	constexpr int32_t str_TXT_820E3908_B_ = int32_t(0x820E3908);
	constexpr int32_t Destroy_TXT_8349C8C0_G__address = int32_t(0x832A8648);
	if (!UseLiftedCode(144, 0x8326C188)) { __imp__sub_8326C188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8C0_G_, str_TXT_820E3908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8C0_G__address);
}
PROMOTED_ENTRY(144, sub_8326C188, 0x8326C188) { ctx.r3.u64 = Construct_TXT_8349C8C0_G_(ctx, base); }

uint64_t Construct_TXT_8349C8C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C8C4_G_ = int32_t(0x8349C8C4);
	constexpr int32_t str_TXT_820E2F58_B_ = int32_t(0x820E391C);
	constexpr int32_t Destroy_TXT_8349C8C4_G__address = int32_t(0x832A8658);
	if (!UseLiftedCode(144, 0x8326C1C8)) { __imp__sub_8326C1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C1C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8C4_G_, str_TXT_820E2F58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C8C4_G__address);
}
PROMOTED_ENTRY(144, sub_8326C1C8, 0x8326C1C8) { ctx.r3.u64 = Construct_TXT_8349C8C4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__33 = 0x8349C8C8u;
	if (!UseLiftedCode(144, 0x8326C208)) { __imp__sub_8326C208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C208);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C208, 0x8326C208) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__33(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__35 = 0x8349C8CCu;
	if (!UseLiftedCode(144, 0x8326C240)) { __imp__sub_8326C240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C240);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C240, 0x8326C240) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__35(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__34 = 0x8349C8D0u;
	if (!UseLiftedCode(144, 0x8326C278)) { __imp__sub_8326C278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C278);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C278, 0x8326C278) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__33 = 0x8349C8D4u;
	if (!UseLiftedCode(144, 0x8326C2B0)) { __imp__sub_8326C2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C2B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C2B0, 0x8326C2B0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__33 = 0x8349C8D8u;
	if (!UseLiftedCode(144, 0x8326C2E8)) { __imp__sub_8326C2E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C2E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C2E8, 0x8326C2E8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__34 = 0x8349C8DCu;
	if (!UseLiftedCode(144, 0x8326C320)) { __imp__sub_8326C320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C320);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C320, 0x8326C320) { ctx.r3.u64 = HashName_TXT_820A2C34_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__33 = 0x8349C8E0u;
	if (!UseLiftedCode(144, 0x8326C358)) { __imp__sub_8326C358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C358);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C358, 0x8326C358) { ctx.r3.u64 = HashName_TXT_820A2C44_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__33 = 0x8349C8E4u;
	if (!UseLiftedCode(144, 0x8326C390)) { __imp__sub_8326C390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C390);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C390, 0x8326C390) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__33 = 0x8349C8E8u;
	if (!UseLiftedCode(144, 0x8326C3C8)) { __imp__sub_8326C3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C3C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C3C8, 0x8326C3C8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__33(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__33 = 0x8349C8ECu;
	if (!UseLiftedCode(144, 0x8326C400)) { __imp__sub_8326C400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C400);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C400, 0x8326C400) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__33 = 0x8349C8F0u;
	if (!UseLiftedCode(144, 0x8326C438)) { __imp__sub_8326C438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C438);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C438, 0x8326C438) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__33 = 0x8349C8F4u;
	if (!UseLiftedCode(144, 0x8326C470)) { __imp__sub_8326C470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C470);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C470, 0x8326C470) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__36 = 0x8349C8F8u;
	if (!UseLiftedCode(144, 0x8326C4A8)) { __imp__sub_8326C4A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C4A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C4A8, 0x8326C4A8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__33 = 0x8349C8FCu;
	if (!UseLiftedCode(144, 0x8326C4E0)) { __imp__sub_8326C4E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C4E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C4E0, 0x8326C4E0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__33 = 0x8349C900u;
	if (!UseLiftedCode(144, 0x8326C518)) { __imp__sub_8326C518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C518);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C518, 0x8326C518) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__33(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__33 = 0x8349C904u;
	if (!UseLiftedCode(144, 0x8326C550)) { __imp__sub_8326C550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C550);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C550, 0x8326C550) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__33(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__33 = 0x8349C908u;
	if (!UseLiftedCode(144, 0x8326C588)) { __imp__sub_8326C588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C588);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C588, 0x8326C588) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__34 = 0x8349C90Cu;
	if (!UseLiftedCode(144, 0x8326C5C0)) { __imp__sub_8326C5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C5C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C5C0, 0x8326C5C0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__34(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__33 = 0x8349C910u;
	if (!UseLiftedCode(144, 0x8326C5F8)) { __imp__sub_8326C5F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C5F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C5F8, 0x8326C5F8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__33(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__33 = 0x8349C914u;
	if (!UseLiftedCode(144, 0x8326C630)) { __imp__sub_8326C630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C630);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C630, 0x8326C630) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__33(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__33(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__33 = 0x8349C918u;
	if (!UseLiftedCode(144, 0x8326C668)) { __imp__sub_8326C668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C668);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__33, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C668, 0x8326C668) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__33(ctx, base); }

uint64_t Construct_TXT_8349C91C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C91C_G_ = int32_t(0x8349C91C);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349C91C_G__address = int32_t(0x832A8668);
	if (!UseLiftedCode(144, 0x8326C6A0)) { __imp__sub_8326C6A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C6A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C91C_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C91C_G__address);
}
PROMOTED_ENTRY(144, sub_8326C6A0, 0x8326C6A0) { ctx.r3.u64 = Construct_TXT_8349C91C_G_(ctx, base); }

uint64_t Construct_TXT_8349C920_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C920_G_ = int32_t(0x8349C920);
	constexpr int32_t str_TXT_820E397C_B_ = int32_t(0x820E397C);
	constexpr int32_t Destroy_TXT_8349C920_G__address = int32_t(0x832A8678);
	if (!UseLiftedCode(144, 0x8326C6E0)) { __imp__sub_8326C6E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C6E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C920_G_, str_TXT_820E397C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C920_G__address);
}
PROMOTED_ENTRY(144, sub_8326C6E0, 0x8326C6E0) { ctx.r3.u64 = Construct_TXT_8349C920_G_(ctx, base); }

uint64_t Construct_TXT_8349C924_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C924_G_ = int32_t(0x8349C924);
	constexpr int32_t str_TXT_820E397C_B_ = int32_t(0x820E39B0);
	constexpr int32_t Destroy_TXT_8349C924_G__address = int32_t(0x832A8688);
	if (!UseLiftedCode(144, 0x8326C720)) { __imp__sub_8326C720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C720);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C924_G_, str_TXT_820E397C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C924_G__address);
}
PROMOTED_ENTRY(144, sub_8326C720, 0x8326C720) { ctx.r3.u64 = Construct_TXT_8349C924_G_(ctx, base); }

uint64_t Construct_TXT_8349C928_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C928_G_ = int32_t(0x8349C928);
	constexpr int32_t str_TXT_820E39E8_B_ = int32_t(0x820E39E8);
	constexpr int32_t Destroy_TXT_8349C928_G__address = int32_t(0x832A8698);
	if (!UseLiftedCode(144, 0x8326C760)) { __imp__sub_8326C760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C760);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C928_G_, str_TXT_820E39E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C928_G__address);
}
PROMOTED_ENTRY(144, sub_8326C760, 0x8326C760) { ctx.r3.u64 = Construct_TXT_8349C928_G_(ctx, base); }

uint64_t Construct_TXT_8349C92C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C92C_G_ = int32_t(0x8349C92C);
	constexpr int32_t str_TXT_820E39FC_B_ = int32_t(0x820E39FC);
	constexpr int32_t Destroy_TXT_8349C92C_G__address = int32_t(0x832A86A8);
	if (!UseLiftedCode(144, 0x8326C7A0)) { __imp__sub_8326C7A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C7A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C92C_G_, str_TXT_820E39FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C92C_G__address);
}
PROMOTED_ENTRY(144, sub_8326C7A0, 0x8326C7A0) { ctx.r3.u64 = Construct_TXT_8349C92C_G_(ctx, base); }

uint64_t Construct_TXT_8349C930_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C930_G_ = int32_t(0x8349C930);
	constexpr int32_t str_TXT_820E3A0C_B_ = int32_t(0x820E3A0C);
	constexpr int32_t Destroy_TXT_8349C930_G__address = int32_t(0x832A86B8);
	if (!UseLiftedCode(144, 0x8326C7E0)) { __imp__sub_8326C7E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C7E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C930_G_, str_TXT_820E3A0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C930_G__address);
}
PROMOTED_ENTRY(144, sub_8326C7E0, 0x8326C7E0) { ctx.r3.u64 = Construct_TXT_8349C930_G_(ctx, base); }

uint64_t Construct_TXT_8349C934_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C934_G_ = int32_t(0x8349C934);
	constexpr int32_t str_TXT_820E397C_B_ = int32_t(0x820E3A1C);
	constexpr int32_t Destroy_TXT_8349C934_G__address = int32_t(0x832A86C8);
	if (!UseLiftedCode(144, 0x8326C820)) { __imp__sub_8326C820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C820);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C934_G_, str_TXT_820E397C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C934_G__address);
}
PROMOTED_ENTRY(144, sub_8326C820, 0x8326C820) { ctx.r3.u64 = Construct_TXT_8349C934_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__34 = 0x8349C938u;
	if (!UseLiftedCode(144, 0x8326C860)) { __imp__sub_8326C860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C860);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C860, 0x8326C860) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__34(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__36 = 0x8349C93Cu;
	if (!UseLiftedCode(144, 0x8326C898)) { __imp__sub_8326C898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C898);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C898, 0x8326C898) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__36(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__35 = 0x8349C940u;
	if (!UseLiftedCode(144, 0x8326C8D0)) { __imp__sub_8326C8D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C8D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C8D0, 0x8326C8D0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__34 = 0x8349C944u;
	if (!UseLiftedCode(144, 0x8326C908)) { __imp__sub_8326C908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C908);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C908, 0x8326C908) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__34 = 0x8349C948u;
	if (!UseLiftedCode(144, 0x8326C940)) { __imp__sub_8326C940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C940);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C940, 0x8326C940) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__35 = 0x8349C94Cu;
	if (!UseLiftedCode(144, 0x8326C978)) { __imp__sub_8326C978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C978);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C978, 0x8326C978) { ctx.r3.u64 = HashName_TXT_820A2C34_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__34 = 0x8349C950u;
	if (!UseLiftedCode(144, 0x8326C9B0)) { __imp__sub_8326C9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C9B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C9B0, 0x8326C9B0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__34 = 0x8349C954u;
	if (!UseLiftedCode(144, 0x8326C9E8)) { __imp__sub_8326C9E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C9E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326C9E8, 0x8326C9E8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__34 = 0x8349C958u;
	if (!UseLiftedCode(144, 0x8326CA20)) { __imp__sub_8326CA20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CA20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CA20, 0x8326CA20) { ctx.r3.u64 = HashName_TXT_820A2C74_B__34(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__34 = 0x8349C95Cu;
	if (!UseLiftedCode(144, 0x8326CA58)) { __imp__sub_8326CA58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CA58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CA58, 0x8326CA58) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__34 = 0x8349C960u;
	if (!UseLiftedCode(144, 0x8326CA90)) { __imp__sub_8326CA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CA90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CA90, 0x8326CA90) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__34 = 0x8349C964u;
	if (!UseLiftedCode(144, 0x8326CAC8)) { __imp__sub_8326CAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CAC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CAC8, 0x8326CAC8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__37 = 0x8349C968u;
	if (!UseLiftedCode(144, 0x8326CB00)) { __imp__sub_8326CB00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CB00);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CB00, 0x8326CB00) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__34 = 0x8349C96Cu;
	if (!UseLiftedCode(144, 0x8326CB38)) { __imp__sub_8326CB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CB38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CB38, 0x8326CB38) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__34 = 0x8349C970u;
	if (!UseLiftedCode(144, 0x8326CB70)) { __imp__sub_8326CB70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CB70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CB70, 0x8326CB70) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__34(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__34 = 0x8349C974u;
	if (!UseLiftedCode(144, 0x8326CBA8)) { __imp__sub_8326CBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CBA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CBA8, 0x8326CBA8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__34(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__34 = 0x8349C978u;
	if (!UseLiftedCode(144, 0x8326CBE0)) { __imp__sub_8326CBE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CBE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CBE0, 0x8326CBE0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__35 = 0x8349C97Cu;
	if (!UseLiftedCode(144, 0x8326CC18)) { __imp__sub_8326CC18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CC18);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CC18, 0x8326CC18) { ctx.r3.u64 = HashName_TXT_820A2D24_B__35(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__34 = 0x8349C980u;
	if (!UseLiftedCode(144, 0x8326CC50)) { __imp__sub_8326CC50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CC50);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CC50, 0x8326CC50) { ctx.r3.u64 = HashName_TXT_820A2D30_B__34(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__34 = 0x8349C984u;
	if (!UseLiftedCode(144, 0x8326CC88)) { __imp__sub_8326CC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CC88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CC88, 0x8326CC88) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__34(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__34(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__34 = 0x8349C988u;
	if (!UseLiftedCode(144, 0x8326CCC0)) { __imp__sub_8326CCC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CCC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__34, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CCC0, 0x8326CCC0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__34(ctx, base); }

uint64_t Construct_TXT_8349C98C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C98C_G_ = int32_t(0x8349C98C);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349C98C_G__address = int32_t(0x832A86D8);
	if (!UseLiftedCode(144, 0x8326CCF8)) { __imp__sub_8326CCF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CCF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C98C_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C98C_G__address);
}
PROMOTED_ENTRY(144, sub_8326CCF8, 0x8326CCF8) { ctx.r3.u64 = Construct_TXT_8349C98C_G_(ctx, base); }

uint64_t Construct_TXT_8349C990_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C990_G_ = int32_t(0x8349C990);
	constexpr int32_t str_TXT_820E3C9C_B_ = int32_t(0x820E3C9C);
	constexpr int32_t Destroy_TXT_8349C990_G__address = int32_t(0x832A86E8);
	if (!UseLiftedCode(144, 0x8326CD38)) { __imp__sub_8326CD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CD38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C990_G_, str_TXT_820E3C9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C990_G__address);
}
PROMOTED_ENTRY(144, sub_8326CD38, 0x8326CD38) { ctx.r3.u64 = Construct_TXT_8349C990_G_(ctx, base); }

uint64_t Construct_TXT_8349C994_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C994_G_ = int32_t(0x8349C994);
	constexpr int32_t str_TXT_820E3CCC_B_ = int32_t(0x820E3CCC);
	constexpr int32_t Destroy_TXT_8349C994_G__address = int32_t(0x832A86F8);
	if (!UseLiftedCode(144, 0x8326CD78)) { __imp__sub_8326CD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CD78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C994_G_, str_TXT_820E3CCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C994_G__address);
}
PROMOTED_ENTRY(144, sub_8326CD78, 0x8326CD78) { ctx.r3.u64 = Construct_TXT_8349C994_G_(ctx, base); }

uint64_t Construct_TXT_8349C998_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C998_G_ = int32_t(0x8349C998);
	constexpr int32_t str_TXT_820E3D04_B_ = int32_t(0x820E3D04);
	constexpr int32_t Destroy_TXT_8349C998_G__address = int32_t(0x832A8708);
	if (!UseLiftedCode(144, 0x8326CDB8)) { __imp__sub_8326CDB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CDB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C998_G_, str_TXT_820E3D04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C998_G__address);
}
PROMOTED_ENTRY(144, sub_8326CDB8, 0x8326CDB8) { ctx.r3.u64 = Construct_TXT_8349C998_G_(ctx, base); }

uint64_t Construct_TXT_8349C99C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C99C_G_ = int32_t(0x8349C99C);
	constexpr int32_t str_TXT_820E3D30_B_ = int32_t(0x820E3D30);
	constexpr int32_t Destroy_TXT_8349C99C_G__address = int32_t(0x832A8718);
	if (!UseLiftedCode(144, 0x8326CDF8)) { __imp__sub_8326CDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CDF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C99C_G_, str_TXT_820E3D30_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C99C_G__address);
}
PROMOTED_ENTRY(144, sub_8326CDF8, 0x8326CDF8) { ctx.r3.u64 = Construct_TXT_8349C99C_G_(ctx, base); }

uint64_t Construct_TXT_8349C9A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C9A0_G_ = int32_t(0x8349C9A0);
	constexpr int32_t str_TXT_820E3D64_B_ = int32_t(0x820E3D64);
	constexpr int32_t Destroy_TXT_8349C9A0_G__address = int32_t(0x832A8728);
	if (!UseLiftedCode(144, 0x8326CE38)) { __imp__sub_8326CE38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CE38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A0_G_, str_TXT_820E3D64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C9A0_G__address);
}
PROMOTED_ENTRY(144, sub_8326CE38, 0x8326CE38) { ctx.r3.u64 = Construct_TXT_8349C9A0_G_(ctx, base); }

uint64_t Construct_TXT_8349C9A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C9A4_G_ = int32_t(0x8349C9A4);
	constexpr int32_t str_TXT_820E3CCC_B_ = int32_t(0x820E3DA0);
	constexpr int32_t Destroy_TXT_8349C9A4_G__address = int32_t(0x832A8738);
	if (!UseLiftedCode(144, 0x8326CE78)) { __imp__sub_8326CE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CE78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A4_G_, str_TXT_820E3CCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C9A4_G__address);
}
PROMOTED_ENTRY(144, sub_8326CE78, 0x8326CE78) { ctx.r3.u64 = Construct_TXT_8349C9A4_G_(ctx, base); }

uint64_t Construct_TXT_8349C9A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C9A8_G_ = int32_t(0x8349C9A8);
	constexpr int32_t str_TXT_820E3CCC_B_ = int32_t(0x820E3DE0);
	constexpr int32_t Destroy_TXT_8349C9A8_G__address = int32_t(0x832A8748);
	if (!UseLiftedCode(144, 0x8326CEB8)) { __imp__sub_8326CEB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CEB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A8_G_, str_TXT_820E3CCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C9A8_G__address);
}
PROMOTED_ENTRY(144, sub_8326CEB8, 0x8326CEB8) { ctx.r3.u64 = Construct_TXT_8349C9A8_G_(ctx, base); }

uint64_t Construct_TXT_8349C9AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349C9AC_G_ = int32_t(0x8349C9AC);
	constexpr int32_t str_TXT_820E3E1C_B_ = int32_t(0x820E3E1C);
	constexpr int32_t Destroy_TXT_8349C9AC_G__address = int32_t(0x832A8758);
	if (!UseLiftedCode(144, 0x8326CEF8)) { __imp__sub_8326CEF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CEF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9AC_G_, str_TXT_820E3E1C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349C9AC_G__address);
}
PROMOTED_ENTRY(144, sub_8326CEF8, 0x8326CEF8) { ctx.r3.u64 = Construct_TXT_8349C9AC_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__35 = 0x8349C9B0u;
	if (!UseLiftedCode(144, 0x8326CF38)) { __imp__sub_8326CF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CF38);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CF38, 0x8326CF38) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__35(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__37 = 0x8349C9B4u;
	if (!UseLiftedCode(144, 0x8326CF70)) { __imp__sub_8326CF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CF70);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CF70, 0x8326CF70) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__37(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__36 = 0x8349C9B8u;
	if (!UseLiftedCode(144, 0x8326CFA8)) { __imp__sub_8326CFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CFA8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CFA8, 0x8326CFA8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__35 = 0x8349C9BCu;
	if (!UseLiftedCode(144, 0x8326CFE0)) { __imp__sub_8326CFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CFE0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326CFE0, 0x8326CFE0) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__35 = 0x8349C9C0u;
	if (!UseLiftedCode(144, 0x8326D018)) { __imp__sub_8326D018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D018);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D018, 0x8326D018) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__36 = 0x8349C9C4u;
	if (!UseLiftedCode(144, 0x8326D050)) { __imp__sub_8326D050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D050);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D050, 0x8326D050) { ctx.r3.u64 = HashName_TXT_820A2C34_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__35 = 0x8349C9C8u;
	if (!UseLiftedCode(144, 0x8326D088)) { __imp__sub_8326D088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D088);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D088, 0x8326D088) { ctx.r3.u64 = HashName_TXT_820A2C44_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__35 = 0x8349C9CCu;
	if (!UseLiftedCode(144, 0x8326D0C0)) { __imp__sub_8326D0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D0C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D0C0, 0x8326D0C0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__35 = 0x8349C9D0u;
	if (!UseLiftedCode(144, 0x8326D0F8)) { __imp__sub_8326D0F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D0F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D0F8, 0x8326D0F8) { ctx.r3.u64 = HashName_TXT_820A2C74_B__35(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__35 = 0x8349C9D4u;
	if (!UseLiftedCode(144, 0x8326D130)) { __imp__sub_8326D130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D130);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D130, 0x8326D130) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__35 = 0x8349C9D8u;
	if (!UseLiftedCode(144, 0x8326D168)) { __imp__sub_8326D168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D168);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D168, 0x8326D168) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__35 = 0x8349C9DCu;
	if (!UseLiftedCode(144, 0x8326D1A0)) { __imp__sub_8326D1A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D1A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D1A0, 0x8326D1A0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__38 = 0x8349C9E0u;
	if (!UseLiftedCode(144, 0x8326D1D8)) { __imp__sub_8326D1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D1D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D1D8, 0x8326D1D8) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__35 = 0x8349C9E4u;
	if (!UseLiftedCode(144, 0x8326D210)) { __imp__sub_8326D210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D210);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D210, 0x8326D210) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__35 = 0x8349C9E8u;
	if (!UseLiftedCode(144, 0x8326D248)) { __imp__sub_8326D248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D248);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D248, 0x8326D248) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__35(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__35 = 0x8349C9ECu;
	if (!UseLiftedCode(144, 0x8326D280)) { __imp__sub_8326D280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D280);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D280, 0x8326D280) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__35(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__35 = 0x8349C9F0u;
	if (!UseLiftedCode(144, 0x8326D2B8)) { __imp__sub_8326D2B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D2B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D2B8, 0x8326D2B8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__36 = 0x8349C9F4u;
	if (!UseLiftedCode(144, 0x8326D2F0)) { __imp__sub_8326D2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D2F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D2F0, 0x8326D2F0) { ctx.r3.u64 = HashName_TXT_820A2D24_B__36(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__35 = 0x8349C9F8u;
	if (!UseLiftedCode(144, 0x8326D328)) { __imp__sub_8326D328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D328);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D328, 0x8326D328) { ctx.r3.u64 = HashName_TXT_820A2D30_B__35(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__35 = 0x8349C9FCu;
	if (!UseLiftedCode(144, 0x8326D360)) { __imp__sub_8326D360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D360);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D360, 0x8326D360) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__35(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__35(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__35 = 0x8349CA00u;
	if (!UseLiftedCode(144, 0x8326D398)) { __imp__sub_8326D398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D398);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__35, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D398, 0x8326D398) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__35(ctx, base); }

uint64_t Construct_TXT_8349CA04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CA04_G_ = int32_t(0x8349CA04);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349CA04_G__address = int32_t(0x832A8768);
	if (!UseLiftedCode(144, 0x8326D3D0)) { __imp__sub_8326D3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D3D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA04_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CA04_G__address);
}
PROMOTED_ENTRY(144, sub_8326D3D0, 0x8326D3D0) { ctx.r3.u64 = Construct_TXT_8349CA04_G_(ctx, base); }

uint64_t Construct_TXT_8349CA08_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CA08_G_ = int32_t(0x8349CA08);
	constexpr int32_t str_TXT_820E3EB8_B_ = int32_t(0x820E3EB8);
	constexpr int32_t Destroy_TXT_8349CA08_G__address = int32_t(0x832A8778);
	if (!UseLiftedCode(144, 0x8326D410)) { __imp__sub_8326D410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA08_G_, str_TXT_820E3EB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CA08_G__address);
}
PROMOTED_ENTRY(144, sub_8326D410, 0x8326D410) { ctx.r3.u64 = Construct_TXT_8349CA08_G_(ctx, base); }

uint64_t Construct_TXT_8349CA0C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CA0C_G_ = int32_t(0x8349CA0C);
	constexpr int32_t str_TXT_820E3EB8_B_ = int32_t(0x820E3EF4);
	constexpr int32_t Destroy_TXT_8349CA0C_G__address = int32_t(0x832A8788);
	if (!UseLiftedCode(144, 0x8326D450)) { __imp__sub_8326D450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA0C_G_, str_TXT_820E3EB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CA0C_G__address);
}
PROMOTED_ENTRY(144, sub_8326D450, 0x8326D450) { ctx.r3.u64 = Construct_TXT_8349CA0C_G_(ctx, base); }

uint64_t Construct_TXT_8349CA10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CA10_G_ = int32_t(0x8349CA10);
	constexpr int32_t str_TXT_820E3EB8_B_ = int32_t(0x820E3F30);
	constexpr int32_t Destroy_TXT_8349CA10_G__address = int32_t(0x832A8798);
	if (!UseLiftedCode(144, 0x8326D490)) { __imp__sub_8326D490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA10_G_, str_TXT_820E3EB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CA10_G__address);
}
PROMOTED_ENTRY(144, sub_8326D490, 0x8326D490) { ctx.r3.u64 = Construct_TXT_8349CA10_G_(ctx, base); }

uint64_t Construct_TXT_8349CA14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CA14_G_ = int32_t(0x8349CA14);
	constexpr int32_t str_TXT_820E3EB8_B_ = int32_t(0x820E3F7C);
	constexpr int32_t Destroy_TXT_8349CA14_G__address = int32_t(0x832A87A8);
	if (!UseLiftedCode(144, 0x8326D4D0)) { __imp__sub_8326D4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D4D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA14_G_, str_TXT_820E3EB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CA14_G__address);
}
PROMOTED_ENTRY(144, sub_8326D4D0, 0x8326D4D0) { ctx.r3.u64 = Construct_TXT_8349CA14_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__36 = 0x8349CA98u;
	if (!UseLiftedCode(144, 0x8326D800)) { __imp__sub_8326D800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D800);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D800, 0x8326D800) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__36(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__38 = 0x8349CA9Cu;
	if (!UseLiftedCode(144, 0x8326D838)) { __imp__sub_8326D838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D838);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D838, 0x8326D838) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__38(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__37 = 0x8349CAA0u;
	if (!UseLiftedCode(144, 0x8326D870)) { __imp__sub_8326D870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D870);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D870, 0x8326D870) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__36 = 0x8349CAA4u;
	if (!UseLiftedCode(144, 0x8326D8A8)) { __imp__sub_8326D8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D8A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D8A8, 0x8326D8A8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__36 = 0x8349CAA8u;
	if (!UseLiftedCode(144, 0x8326D8E0)) { __imp__sub_8326D8E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D8E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D8E0, 0x8326D8E0) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__37 = 0x8349CAACu;
	if (!UseLiftedCode(144, 0x8326D918)) { __imp__sub_8326D918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D918);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D918, 0x8326D918) { ctx.r3.u64 = HashName_TXT_820A2C34_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__36 = 0x8349CAB0u;
	if (!UseLiftedCode(144, 0x8326D950)) { __imp__sub_8326D950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D950);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D950, 0x8326D950) { ctx.r3.u64 = HashName_TXT_820A2C44_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__36 = 0x8349CAB4u;
	if (!UseLiftedCode(144, 0x8326D988)) { __imp__sub_8326D988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D988);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D988, 0x8326D988) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__36 = 0x8349CAB8u;
	if (!UseLiftedCode(144, 0x8326D9C0)) { __imp__sub_8326D9C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D9C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D9C0, 0x8326D9C0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__36(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__36 = 0x8349CABCu;
	if (!UseLiftedCode(144, 0x8326D9F8)) { __imp__sub_8326D9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D9F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326D9F8, 0x8326D9F8) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__36 = 0x8349CAC0u;
	if (!UseLiftedCode(144, 0x8326DA30)) { __imp__sub_8326DA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DA30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DA30, 0x8326DA30) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__36 = 0x8349CAC4u;
	if (!UseLiftedCode(144, 0x8326DA68)) { __imp__sub_8326DA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DA68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DA68, 0x8326DA68) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__39 = 0x8349CAC8u;
	if (!UseLiftedCode(144, 0x8326DAA0)) { __imp__sub_8326DAA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DAA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DAA0, 0x8326DAA0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__36 = 0x8349CACCu;
	if (!UseLiftedCode(144, 0x8326DAD8)) { __imp__sub_8326DAD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DAD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DAD8, 0x8326DAD8) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__36 = 0x8349CAD0u;
	if (!UseLiftedCode(144, 0x8326DB10)) { __imp__sub_8326DB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DB10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DB10, 0x8326DB10) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__36(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__36 = 0x8349CAD4u;
	if (!UseLiftedCode(144, 0x8326DB48)) { __imp__sub_8326DB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DB48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DB48, 0x8326DB48) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__36(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__36 = 0x8349CAD8u;
	if (!UseLiftedCode(144, 0x8326DB80)) { __imp__sub_8326DB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DB80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DB80, 0x8326DB80) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__37 = 0x8349CADCu;
	if (!UseLiftedCode(144, 0x8326DBB8)) { __imp__sub_8326DBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DBB8, 0x8326DBB8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__37(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__36 = 0x8349CAE0u;
	if (!UseLiftedCode(144, 0x8326DBF0)) { __imp__sub_8326DBF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DBF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DBF0, 0x8326DBF0) { ctx.r3.u64 = HashName_TXT_820A2D30_B__36(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__36 = 0x8349CAE4u;
	if (!UseLiftedCode(144, 0x8326DC28)) { __imp__sub_8326DC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DC28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DC28, 0x8326DC28) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__36(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__36(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__36 = 0x8349CAE8u;
	if (!UseLiftedCode(144, 0x8326DC60)) { __imp__sub_8326DC60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DC60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__36, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DC60, 0x8326DC60) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__36(ctx, base); }

uint64_t Construct_TXT_8349CAEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CAEC_G_ = int32_t(0x8349CAEC);
	constexpr int32_t str_TXT_820E40BC_B_ = int32_t(0x820E40BC);
	constexpr int32_t Destroy_TXT_8349CAEC_G__address = int32_t(0x832A8888);
	if (!UseLiftedCode(144, 0x8326DC98)) { __imp__sub_8326DC98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DC98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAEC_G_, str_TXT_820E40BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CAEC_G__address);
}
PROMOTED_ENTRY(144, sub_8326DC98, 0x8326DC98) { ctx.r3.u64 = Construct_TXT_8349CAEC_G_(ctx, base); }

uint64_t Construct_TXT_8349CAF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CAF0_G_ = int32_t(0x8349CAF0);
	constexpr int32_t str_TXT_820E40F4_B_ = int32_t(0x820E40F4);
	constexpr int32_t Destroy_TXT_8349CAF0_G__address = int32_t(0x832A8898);
	if (!UseLiftedCode(144, 0x8326DCD8)) { __imp__sub_8326DCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DCD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF0_G_, str_TXT_820E40F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CAF0_G__address);
}
PROMOTED_ENTRY(144, sub_8326DCD8, 0x8326DCD8) { ctx.r3.u64 = Construct_TXT_8349CAF0_G_(ctx, base); }

uint64_t Construct_TXT_8349CAF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CAF4_G_ = int32_t(0x8349CAF4);
	constexpr int32_t str_TXT_820E267C_B_ = int32_t(0x820E267C);
	constexpr int32_t Destroy_TXT_8349CAF4_G__address = int32_t(0x832A88A8);
	if (!UseLiftedCode(144, 0x8326DD18)) { __imp__sub_8326DD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DD18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF4_G_, str_TXT_820E267C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CAF4_G__address);
}
PROMOTED_ENTRY(144, sub_8326DD18, 0x8326DD18) { ctx.r3.u64 = Construct_TXT_8349CAF4_G_(ctx, base); }

uint64_t Construct_TXT_8349CAF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CAF8_G_ = int32_t(0x8349CAF8);
	constexpr int32_t str_TXT_820E4124_B_ = int32_t(0x820E4124);
	constexpr int32_t Destroy_TXT_8349CAF8_G__address = int32_t(0x832A88B8);
	if (!UseLiftedCode(144, 0x8326DD58)) { __imp__sub_8326DD58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DD58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF8_G_, str_TXT_820E4124_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CAF8_G__address);
}
PROMOTED_ENTRY(144, sub_8326DD58, 0x8326DD58) { ctx.r3.u64 = Construct_TXT_8349CAF8_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__37 = 0x8349CAFCu;
	if (!UseLiftedCode(144, 0x8326DD98)) { __imp__sub_8326DD98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DD98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DD98, 0x8326DD98) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__37(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__39 = 0x8349CB00u;
	if (!UseLiftedCode(144, 0x8326DDD0)) { __imp__sub_8326DDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DDD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DDD0, 0x8326DDD0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__39(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__38 = 0x8349CB04u;
	if (!UseLiftedCode(144, 0x8326DE08)) { __imp__sub_8326DE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DE08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DE08, 0x8326DE08) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__37 = 0x8349CB08u;
	if (!UseLiftedCode(144, 0x8326DE40)) { __imp__sub_8326DE40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DE40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DE40, 0x8326DE40) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__37 = 0x8349CB0Cu;
	if (!UseLiftedCode(144, 0x8326DE78)) { __imp__sub_8326DE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DE78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DE78, 0x8326DE78) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__38 = 0x8349CB10u;
	if (!UseLiftedCode(144, 0x8326DEB0)) { __imp__sub_8326DEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DEB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DEB0, 0x8326DEB0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__37 = 0x8349CB14u;
	if (!UseLiftedCode(144, 0x8326DEE8)) { __imp__sub_8326DEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DEE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DEE8, 0x8326DEE8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__37 = 0x8349CB18u;
	if (!UseLiftedCode(144, 0x8326DF20)) { __imp__sub_8326DF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DF20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DF20, 0x8326DF20) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__37 = 0x8349CB1Cu;
	if (!UseLiftedCode(144, 0x8326DF58)) { __imp__sub_8326DF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DF58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DF58, 0x8326DF58) { ctx.r3.u64 = HashName_TXT_820A2C74_B__37(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__37 = 0x8349CB20u;
	if (!UseLiftedCode(144, 0x8326DF90)) { __imp__sub_8326DF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DF90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DF90, 0x8326DF90) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__37 = 0x8349CB24u;
	if (!UseLiftedCode(144, 0x8326DFC8)) { __imp__sub_8326DFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DFC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326DFC8, 0x8326DFC8) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__37 = 0x8349CB28u;
	if (!UseLiftedCode(144, 0x8326E000)) { __imp__sub_8326E000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E000);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E000, 0x8326E000) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__40 = 0x8349CB2Cu;
	if (!UseLiftedCode(144, 0x8326E038)) { __imp__sub_8326E038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E038);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E038, 0x8326E038) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__37 = 0x8349CB30u;
	if (!UseLiftedCode(144, 0x8326E070)) { __imp__sub_8326E070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E070);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E070, 0x8326E070) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__37 = 0x8349CB34u;
	if (!UseLiftedCode(144, 0x8326E0A8)) { __imp__sub_8326E0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E0A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E0A8, 0x8326E0A8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__37(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__37 = 0x8349CB38u;
	if (!UseLiftedCode(144, 0x8326E0E0)) { __imp__sub_8326E0E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E0E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E0E0, 0x8326E0E0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__37(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__37 = 0x8349CB3Cu;
	if (!UseLiftedCode(144, 0x8326E118)) { __imp__sub_8326E118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E118);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E118, 0x8326E118) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__38 = 0x8349CB40u;
	if (!UseLiftedCode(144, 0x8326E150)) { __imp__sub_8326E150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E150);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E150, 0x8326E150) { ctx.r3.u64 = HashName_TXT_820A2D24_B__38(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__37 = 0x8349CB44u;
	if (!UseLiftedCode(144, 0x8326E188)) { __imp__sub_8326E188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E188);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E188, 0x8326E188) { ctx.r3.u64 = HashName_TXT_820A2D30_B__37(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__37 = 0x8349CB48u;
	if (!UseLiftedCode(144, 0x8326E1C0)) { __imp__sub_8326E1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E1C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E1C0, 0x8326E1C0) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__37(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__37(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__37 = 0x8349CB4Cu;
	if (!UseLiftedCode(144, 0x8326E1F8)) { __imp__sub_8326E1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E1F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__37, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E1F8, 0x8326E1F8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__37(ctx, base); }

uint64_t Construct_TXT_8349CB50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB50_G_ = int32_t(0x8349CB50);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E41AC);
	constexpr int32_t Destroy_TXT_8349CB50_G__address = int32_t(0x832A88C8);
	if (!UseLiftedCode(144, 0x8326E230)) { __imp__sub_8326E230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB50_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB50_G__address);
}
PROMOTED_ENTRY(144, sub_8326E230, 0x8326E230) { ctx.r3.u64 = Construct_TXT_8349CB50_G_(ctx, base); }

uint64_t Construct_TXT_8349CB54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB54_G_ = int32_t(0x8349CB54);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E41AC);
	constexpr int32_t Destroy_TXT_8349CB54_G__address = int32_t(0x832A88D8);
	if (!UseLiftedCode(144, 0x8326E270)) { __imp__sub_8326E270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E270);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB54_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB54_G__address);
}
PROMOTED_ENTRY(144, sub_8326E270, 0x8326E270) { ctx.r3.u64 = Construct_TXT_8349CB54_G_(ctx, base); }

uint64_t Construct_TXT_8349CB58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB58_G_ = int32_t(0x8349CB58);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E41F0);
	constexpr int32_t Destroy_TXT_8349CB58_G__address = int32_t(0x832A88E8);
	if (!UseLiftedCode(144, 0x8326E2B0)) { __imp__sub_8326E2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E2B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB58_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB58_G__address);
}
PROMOTED_ENTRY(144, sub_8326E2B0, 0x8326E2B0) { ctx.r3.u64 = Construct_TXT_8349CB58_G_(ctx, base); }

uint64_t Construct_TXT_8349CB5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB5C_G_ = int32_t(0x8349CB5C);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E4234);
	constexpr int32_t Destroy_TXT_8349CB5C_G__address = int32_t(0x832A88F8);
	if (!UseLiftedCode(144, 0x8326E2F0)) { __imp__sub_8326E2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E2F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB5C_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB5C_G__address);
}
PROMOTED_ENTRY(144, sub_8326E2F0, 0x8326E2F0) { ctx.r3.u64 = Construct_TXT_8349CB5C_G_(ctx, base); }

uint64_t Construct_TXT_8349CB60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB60_G_ = int32_t(0x8349CB60);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E4270);
	constexpr int32_t Destroy_TXT_8349CB60_G__address = int32_t(0x832A8908);
	if (!UseLiftedCode(144, 0x8326E330)) { __imp__sub_8326E330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E330);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB60_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB60_G__address);
}
PROMOTED_ENTRY(144, sub_8326E330, 0x8326E330) { ctx.r3.u64 = Construct_TXT_8349CB60_G_(ctx, base); }

uint64_t Construct_TXT_8349CB64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB64_G_ = int32_t(0x8349CB64);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E42B4);
	constexpr int32_t Destroy_TXT_8349CB64_G__address = int32_t(0x832A8918);
	if (!UseLiftedCode(144, 0x8326E370)) { __imp__sub_8326E370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E370);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB64_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB64_G__address);
}
PROMOTED_ENTRY(144, sub_8326E370, 0x8326E370) { ctx.r3.u64 = Construct_TXT_8349CB64_G_(ctx, base); }

uint64_t Construct_TXT_8349CB68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB68_G_ = int32_t(0x8349CB68);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E42F0);
	constexpr int32_t Destroy_TXT_8349CB68_G__address = int32_t(0x832A8928);
	if (!UseLiftedCode(144, 0x8326E3B0)) { __imp__sub_8326E3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E3B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB68_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB68_G__address);
}
PROMOTED_ENTRY(144, sub_8326E3B0, 0x8326E3B0) { ctx.r3.u64 = Construct_TXT_8349CB68_G_(ctx, base); }

uint64_t Construct_TXT_8349CB6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB6C_G_ = int32_t(0x8349CB6C);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E4338);
	constexpr int32_t Destroy_TXT_8349CB6C_G__address = int32_t(0x832A8938);
	if (!UseLiftedCode(144, 0x8326E3F0)) { __imp__sub_8326E3F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E3F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB6C_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB6C_G__address);
}
PROMOTED_ENTRY(144, sub_8326E3F0, 0x8326E3F0) { ctx.r3.u64 = Construct_TXT_8349CB6C_G_(ctx, base); }

uint64_t Construct_TXT_8349CB70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB70_G_ = int32_t(0x8349CB70);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E4378);
	constexpr int32_t Destroy_TXT_8349CB70_G__address = int32_t(0x832A8948);
	if (!UseLiftedCode(144, 0x8326E430)) { __imp__sub_8326E430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E430);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB70_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB70_G__address);
}
PROMOTED_ENTRY(144, sub_8326E430, 0x8326E430) { ctx.r3.u64 = Construct_TXT_8349CB70_G_(ctx, base); }

uint64_t Construct_TXT_8349CB74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB74_G_ = int32_t(0x8349CB74);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E43BC);
	constexpr int32_t Destroy_TXT_8349CB74_G__address = int32_t(0x832A8958);
	if (!UseLiftedCode(144, 0x8326E470)) { __imp__sub_8326E470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E470);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB74_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB74_G__address);
}
PROMOTED_ENTRY(144, sub_8326E470, 0x8326E470) { ctx.r3.u64 = Construct_TXT_8349CB74_G_(ctx, base); }

uint64_t Construct_TXT_8349CB78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CB78_G_ = int32_t(0x8349CB78);
	constexpr int32_t str_TXT_820E41AC_B_ = int32_t(0x820E43F8);
	constexpr int32_t Destroy_TXT_8349CB78_G__address = int32_t(0x832A8968);
	if (!UseLiftedCode(144, 0x8326E4B0)) { __imp__sub_8326E4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E4B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB78_G_, str_TXT_820E41AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CB78_G__address);
}
PROMOTED_ENTRY(144, sub_8326E4B0, 0x8326E4B0) { ctx.r3.u64 = Construct_TXT_8349CB78_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__38 = 0x8349CB90u;
	if (!UseLiftedCode(144, 0x8326E590)) { __imp__sub_8326E590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E590);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E590, 0x8326E590) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__38(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__40 = 0x8349CB94u;
	if (!UseLiftedCode(144, 0x8326E5C8)) { __imp__sub_8326E5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E5C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E5C8, 0x8326E5C8) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__40(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__39 = 0x8349CB98u;
	if (!UseLiftedCode(144, 0x8326E600)) { __imp__sub_8326E600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E600);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E600, 0x8326E600) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__38 = 0x8349CB9Cu;
	if (!UseLiftedCode(144, 0x8326E638)) { __imp__sub_8326E638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E638);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E638, 0x8326E638) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__38 = 0x8349CBA0u;
	if (!UseLiftedCode(144, 0x8326E670)) { __imp__sub_8326E670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E670);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E670, 0x8326E670) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__39 = 0x8349CBA4u;
	if (!UseLiftedCode(144, 0x8326E6A8)) { __imp__sub_8326E6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E6A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E6A8, 0x8326E6A8) { ctx.r3.u64 = HashName_TXT_820A2C34_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__38 = 0x8349CBA8u;
	if (!UseLiftedCode(144, 0x8326E6E0)) { __imp__sub_8326E6E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E6E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E6E0, 0x8326E6E0) { ctx.r3.u64 = HashName_TXT_820A2C44_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__38 = 0x8349CBACu;
	if (!UseLiftedCode(144, 0x8326E718)) { __imp__sub_8326E718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E718);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E718, 0x8326E718) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__38 = 0x8349CBB0u;
	if (!UseLiftedCode(144, 0x8326E750)) { __imp__sub_8326E750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E750);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E750, 0x8326E750) { ctx.r3.u64 = HashName_TXT_820A2C74_B__38(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__38 = 0x8349CBB4u;
	if (!UseLiftedCode(144, 0x8326E788)) { __imp__sub_8326E788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E788);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E788, 0x8326E788) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__38 = 0x8349CBB8u;
	if (!UseLiftedCode(144, 0x8326E7C0)) { __imp__sub_8326E7C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E7C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E7C0, 0x8326E7C0) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__38 = 0x8349CBBCu;
	if (!UseLiftedCode(144, 0x8326E7F8)) { __imp__sub_8326E7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E7F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E7F8, 0x8326E7F8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__41 = 0x8349CBC0u;
	if (!UseLiftedCode(144, 0x8326E830)) { __imp__sub_8326E830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E830);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E830, 0x8326E830) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__38 = 0x8349CBC4u;
	if (!UseLiftedCode(144, 0x8326E868)) { __imp__sub_8326E868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E868);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E868, 0x8326E868) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__38 = 0x8349CBC8u;
	if (!UseLiftedCode(144, 0x8326E8A0)) { __imp__sub_8326E8A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E8A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E8A0, 0x8326E8A0) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__38(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__38 = 0x8349CBCCu;
	if (!UseLiftedCode(144, 0x8326E8D8)) { __imp__sub_8326E8D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E8D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E8D8, 0x8326E8D8) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__38(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__38 = 0x8349CBD0u;
	if (!UseLiftedCode(144, 0x8326E910)) { __imp__sub_8326E910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E910);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E910, 0x8326E910) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__39 = 0x8349CBD4u;
	if (!UseLiftedCode(144, 0x8326E948)) { __imp__sub_8326E948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E948);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E948, 0x8326E948) { ctx.r3.u64 = HashName_TXT_820A2D24_B__39(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__38 = 0x8349CBD8u;
	if (!UseLiftedCode(144, 0x8326E980)) { __imp__sub_8326E980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E980);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E980, 0x8326E980) { ctx.r3.u64 = HashName_TXT_820A2D30_B__38(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__38 = 0x8349CBDCu;
	if (!UseLiftedCode(144, 0x8326E9B8)) { __imp__sub_8326E9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E9B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E9B8, 0x8326E9B8) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__38(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__38 = 0x8349CBE0u;
	if (!UseLiftedCode(144, 0x8326E9F0)) { __imp__sub_8326E9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__38, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326E9F0, 0x8326E9F0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__38(ctx, base); }

uint64_t Construct_TXT_8349CBE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CBE4_G_ = int32_t(0x8349CBE4);
	constexpr int32_t str_TXT_820E4508_B_ = int32_t(0x820E4508);
	constexpr int32_t Destroy_TXT_8349CBE4_G__address = int32_t(0x832A89E0);
	if (!UseLiftedCode(144, 0x8326EA28)) { __imp__sub_8326EA28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EA28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CBE4_G_, str_TXT_820E4508_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CBE4_G__address);
}
PROMOTED_ENTRY(144, sub_8326EA28, 0x8326EA28) { ctx.r3.u64 = Construct_TXT_8349CBE4_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__39 = 0x8349CBE8u;
	if (!UseLiftedCode(144, 0x8326EA68)) { __imp__sub_8326EA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EA68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EA68, 0x8326EA68) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__39(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__41 = 0x8349CBECu;
	if (!UseLiftedCode(144, 0x8326EAA0)) { __imp__sub_8326EAA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EAA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EAA0, 0x8326EAA0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__41(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__40 = 0x8349CBF0u;
	if (!UseLiftedCode(144, 0x8326EAD8)) { __imp__sub_8326EAD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EAD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EAD8, 0x8326EAD8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__39 = 0x8349CBF4u;
	if (!UseLiftedCode(144, 0x8326EB10)) { __imp__sub_8326EB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EB10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EB10, 0x8326EB10) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__39 = 0x8349CBF8u;
	if (!UseLiftedCode(144, 0x8326EB48)) { __imp__sub_8326EB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EB48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EB48, 0x8326EB48) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__40 = 0x8349CBFCu;
	if (!UseLiftedCode(144, 0x8326EB80)) { __imp__sub_8326EB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EB80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EB80, 0x8326EB80) { ctx.r3.u64 = HashName_TXT_820A2C34_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__39 = 0x8349CC00u;
	if (!UseLiftedCode(144, 0x8326EBB8)) { __imp__sub_8326EBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EBB8, 0x8326EBB8) { ctx.r3.u64 = HashName_TXT_820A2C44_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__39 = 0x8349CC04u;
	if (!UseLiftedCode(144, 0x8326EBF0)) { __imp__sub_8326EBF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EBF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EBF0, 0x8326EBF0) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__39 = 0x8349CC08u;
	if (!UseLiftedCode(144, 0x8326EC28)) { __imp__sub_8326EC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EC28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EC28, 0x8326EC28) { ctx.r3.u64 = HashName_TXT_820A2C74_B__39(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__39 = 0x8349CC0Cu;
	if (!UseLiftedCode(144, 0x8326EC60)) { __imp__sub_8326EC60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EC60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EC60, 0x8326EC60) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__39 = 0x8349CC10u;
	if (!UseLiftedCode(144, 0x8326EC98)) { __imp__sub_8326EC98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EC98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EC98, 0x8326EC98) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__39 = 0x8349CC14u;
	if (!UseLiftedCode(144, 0x8326ECD0)) { __imp__sub_8326ECD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ECD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326ECD0, 0x8326ECD0) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__42 = 0x8349CC18u;
	if (!UseLiftedCode(144, 0x8326ED08)) { __imp__sub_8326ED08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ED08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326ED08, 0x8326ED08) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__39 = 0x8349CC1Cu;
	if (!UseLiftedCode(144, 0x8326ED40)) { __imp__sub_8326ED40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ED40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326ED40, 0x8326ED40) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__39 = 0x8349CC20u;
	if (!UseLiftedCode(144, 0x8326ED78)) { __imp__sub_8326ED78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ED78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326ED78, 0x8326ED78) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__39(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__39 = 0x8349CC24u;
	if (!UseLiftedCode(144, 0x8326EDB0)) { __imp__sub_8326EDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EDB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EDB0, 0x8326EDB0) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__39(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__39 = 0x8349CC28u;
	if (!UseLiftedCode(144, 0x8326EDE8)) { __imp__sub_8326EDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EDE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EDE8, 0x8326EDE8) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__40 = 0x8349CC2Cu;
	if (!UseLiftedCode(144, 0x8326EE20)) { __imp__sub_8326EE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EE20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EE20, 0x8326EE20) { ctx.r3.u64 = HashName_TXT_820A2D24_B__40(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__39 = 0x8349CC30u;
	if (!UseLiftedCode(144, 0x8326EE58)) { __imp__sub_8326EE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EE58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EE58, 0x8326EE58) { ctx.r3.u64 = HashName_TXT_820A2D30_B__39(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__39 = 0x8349CC34u;
	if (!UseLiftedCode(144, 0x8326EE90)) { __imp__sub_8326EE90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EE90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EE90, 0x8326EE90) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__39(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__39(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__39 = 0x8349CC38u;
	if (!UseLiftedCode(144, 0x8326EEC8)) { __imp__sub_8326EEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__39, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EEC8, 0x8326EEC8) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__39(ctx, base); }

uint64_t Construct_TXT_8349CC3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CC3C_G_ = int32_t(0x8349CC3C);
	constexpr int32_t str_TXT_820E455C_B_ = int32_t(0x820E455C);
	constexpr int32_t Destroy_TXT_8349CC3C_G__address = int32_t(0x832A89F0);
	if (!UseLiftedCode(144, 0x8326EF00)) { __imp__sub_8326EF00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EF00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC3C_G_, str_TXT_820E455C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CC3C_G__address);
}
PROMOTED_ENTRY(144, sub_8326EF00, 0x8326EF00) { ctx.r3.u64 = Construct_TXT_8349CC3C_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__40 = 0x8349CC40u;
	if (!UseLiftedCode(144, 0x8326EF40)) { __imp__sub_8326EF40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EF40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EF40, 0x8326EF40) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__40(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__42 = 0x8349CC44u;
	if (!UseLiftedCode(144, 0x8326EF78)) { __imp__sub_8326EF78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EF78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EF78, 0x8326EF78) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__42(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__41 = 0x8349CC48u;
	if (!UseLiftedCode(144, 0x8326EFB0)) { __imp__sub_8326EFB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EFB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EFB0, 0x8326EFB0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__40 = 0x8349CC4Cu;
	if (!UseLiftedCode(144, 0x8326EFE8)) { __imp__sub_8326EFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EFE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326EFE8, 0x8326EFE8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__40 = 0x8349CC50u;
	if (!UseLiftedCode(144, 0x8326F020)) { __imp__sub_8326F020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F020);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F020, 0x8326F020) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__41 = 0x8349CC54u;
	if (!UseLiftedCode(144, 0x8326F058)) { __imp__sub_8326F058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F058);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F058, 0x8326F058) { ctx.r3.u64 = HashName_TXT_820A2C34_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__40 = 0x8349CC58u;
	if (!UseLiftedCode(144, 0x8326F090)) { __imp__sub_8326F090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F090);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F090, 0x8326F090) { ctx.r3.u64 = HashName_TXT_820A2C44_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__40 = 0x8349CC5Cu;
	if (!UseLiftedCode(144, 0x8326F0C8)) { __imp__sub_8326F0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F0C8, 0x8326F0C8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__40 = 0x8349CC60u;
	if (!UseLiftedCode(144, 0x8326F100)) { __imp__sub_8326F100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F100);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F100, 0x8326F100) { ctx.r3.u64 = HashName_TXT_820A2C74_B__40(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__40 = 0x8349CC64u;
	if (!UseLiftedCode(144, 0x8326F138)) { __imp__sub_8326F138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F138);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F138, 0x8326F138) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__40 = 0x8349CC68u;
	if (!UseLiftedCode(144, 0x8326F170)) { __imp__sub_8326F170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F170);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F170, 0x8326F170) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__40 = 0x8349CC6Cu;
	if (!UseLiftedCode(144, 0x8326F1A8)) { __imp__sub_8326F1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F1A8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F1A8, 0x8326F1A8) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__43 = 0x8349CC70u;
	if (!UseLiftedCode(144, 0x8326F1E0)) { __imp__sub_8326F1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F1E0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F1E0, 0x8326F1E0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__43(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__40 = 0x8349CC74u;
	if (!UseLiftedCode(144, 0x8326F218)) { __imp__sub_8326F218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F218);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F218, 0x8326F218) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__40 = 0x8349CC78u;
	if (!UseLiftedCode(144, 0x8326F250)) { __imp__sub_8326F250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F250);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F250, 0x8326F250) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__40(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__40 = 0x8349CC7Cu;
	if (!UseLiftedCode(144, 0x8326F288)) { __imp__sub_8326F288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F288);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F288, 0x8326F288) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__40(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__40 = 0x8349CC80u;
	if (!UseLiftedCode(144, 0x8326F2C0)) { __imp__sub_8326F2C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F2C0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F2C0, 0x8326F2C0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__41 = 0x8349CC84u;
	if (!UseLiftedCode(144, 0x8326F2F8)) { __imp__sub_8326F2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F2F8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F2F8, 0x8326F2F8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__41(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__40 = 0x8349CC88u;
	if (!UseLiftedCode(144, 0x8326F330)) { __imp__sub_8326F330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F330);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F330, 0x8326F330) { ctx.r3.u64 = HashName_TXT_820A2D30_B__40(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__40 = 0x8349CC8Cu;
	if (!UseLiftedCode(144, 0x8326F368)) { __imp__sub_8326F368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F368);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F368, 0x8326F368) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__40(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__40 = 0x8349CC90u;
	if (!UseLiftedCode(144, 0x8326F3A0)) { __imp__sub_8326F3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F3A0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__40, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F3A0, 0x8326F3A0) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__40(ctx, base); }

uint64_t Construct_TXT_8349CC94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CC94_G_ = int32_t(0x8349CC94);
	constexpr int32_t str_TXT_820E45CC_B_ = int32_t(0x820E45CC);
	constexpr int32_t Destroy_TXT_8349CC94_G__address = int32_t(0x832A8A00);
	if (!UseLiftedCode(144, 0x8326F3D8)) { __imp__sub_8326F3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC94_G_, str_TXT_820E45CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CC94_G__address);
}
PROMOTED_ENTRY(144, sub_8326F3D8, 0x8326F3D8) { ctx.r3.u64 = Construct_TXT_8349CC94_G_(ctx, base); }

uint64_t Construct_TXT_8349CC98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CC98_G_ = int32_t(0x8349CC98);
	constexpr int32_t str_TXT_820E45FC_B_ = int32_t(0x820E45FC);
	constexpr int32_t Destroy_TXT_8349CC98_G__address = int32_t(0x832A8A10);
	if (!UseLiftedCode(144, 0x8326F418)) { __imp__sub_8326F418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC98_G_, str_TXT_820E45FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CC98_G__address);
}
PROMOTED_ENTRY(144, sub_8326F418, 0x8326F418) { ctx.r3.u64 = Construct_TXT_8349CC98_G_(ctx, base); }

uint64_t Construct_TXT_8349CC9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CC9C_G_ = int32_t(0x8349CC9C);
	constexpr int32_t str_TXT_820E462C_B_ = int32_t(0x820E462C);
	constexpr int32_t Destroy_TXT_8349CC9C_G__address = int32_t(0x832A8A20);
	if (!UseLiftedCode(144, 0x8326F458)) { __imp__sub_8326F458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F458);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC9C_G_, str_TXT_820E462C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CC9C_G__address);
}
PROMOTED_ENTRY(144, sub_8326F458, 0x8326F458) { ctx.r3.u64 = Construct_TXT_8349CC9C_G_(ctx, base); }

uint64_t Construct_TXT_8349CCA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CCA0_G_ = int32_t(0x8349CCA0);
	constexpr int32_t str_TXT_820E465C_B_ = int32_t(0x820E465C);
	constexpr int32_t Destroy_TXT_8349CCA0_G__address = int32_t(0x832A8A30);
	if (!UseLiftedCode(144, 0x8326F498)) { __imp__sub_8326F498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F498);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CCA0_G_, str_TXT_820E465C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CCA0_G__address);
}
PROMOTED_ENTRY(144, sub_8326F498, 0x8326F498) { ctx.r3.u64 = Construct_TXT_8349CCA0_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__41 = 0x8349CCA4u;
	if (!UseLiftedCode(144, 0x8326F4D8)) { __imp__sub_8326F4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F4D8, 0x8326F4D8) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__41(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__43 = 0x8349CCA8u;
	if (!UseLiftedCode(144, 0x8326F510)) { __imp__sub_8326F510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F510);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F510, 0x8326F510) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__43(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__42 = 0x8349CCACu;
	if (!UseLiftedCode(144, 0x8326F548)) { __imp__sub_8326F548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F548);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F548, 0x8326F548) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__41 = 0x8349CCB0u;
	if (!UseLiftedCode(144, 0x8326F580)) { __imp__sub_8326F580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F580);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F580, 0x8326F580) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__41 = 0x8349CCB4u;
	if (!UseLiftedCode(144, 0x8326F5B8)) { __imp__sub_8326F5B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F5B8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F5B8, 0x8326F5B8) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__42 = 0x8349CCB8u;
	if (!UseLiftedCode(144, 0x8326F5F0)) { __imp__sub_8326F5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F5F0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F5F0, 0x8326F5F0) { ctx.r3.u64 = HashName_TXT_820A2C34_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__41 = 0x8349CCBCu;
	if (!UseLiftedCode(144, 0x8326F628)) { __imp__sub_8326F628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F628);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F628, 0x8326F628) { ctx.r3.u64 = HashName_TXT_820A2C44_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__41 = 0x8349CCC0u;
	if (!UseLiftedCode(144, 0x8326F660)) { __imp__sub_8326F660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F660);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F660, 0x8326F660) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__41 = 0x8349CCC4u;
	if (!UseLiftedCode(144, 0x8326F698)) { __imp__sub_8326F698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F698);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F698, 0x8326F698) { ctx.r3.u64 = HashName_TXT_820A2C74_B__41(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__41 = 0x8349CCC8u;
	if (!UseLiftedCode(144, 0x8326F6D0)) { __imp__sub_8326F6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F6D0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F6D0, 0x8326F6D0) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__41 = 0x8349CCCCu;
	if (!UseLiftedCode(144, 0x8326F708)) { __imp__sub_8326F708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F708);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F708, 0x8326F708) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__41 = 0x8349CCD0u;
	if (!UseLiftedCode(144, 0x8326F740)) { __imp__sub_8326F740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F740);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F740, 0x8326F740) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__44 = 0x8349CCD4u;
	if (!UseLiftedCode(144, 0x8326F778)) { __imp__sub_8326F778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F778);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F778, 0x8326F778) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__44(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__41 = 0x8349CCD8u;
	if (!UseLiftedCode(144, 0x8326F7B0)) { __imp__sub_8326F7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F7B0, 0x8326F7B0) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__41 = 0x8349CCDCu;
	if (!UseLiftedCode(144, 0x8326F7E8)) { __imp__sub_8326F7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F7E8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F7E8, 0x8326F7E8) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__41(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__41 = 0x8349CCE0u;
	if (!UseLiftedCode(144, 0x8326F820)) { __imp__sub_8326F820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F820);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F820, 0x8326F820) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__41(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__41 = 0x8349CCE4u;
	if (!UseLiftedCode(144, 0x8326F858)) { __imp__sub_8326F858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F858);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F858, 0x8326F858) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__42 = 0x8349CCE8u;
	if (!UseLiftedCode(144, 0x8326F890)) { __imp__sub_8326F890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F890);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F890, 0x8326F890) { ctx.r3.u64 = HashName_TXT_820A2D24_B__42(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__41 = 0x8349CCECu;
	if (!UseLiftedCode(144, 0x8326F8C8)) { __imp__sub_8326F8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F8C8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F8C8, 0x8326F8C8) { ctx.r3.u64 = HashName_TXT_820A2D30_B__41(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__41 = 0x8349CCF0u;
	if (!UseLiftedCode(144, 0x8326F900)) { __imp__sub_8326F900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F900);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F900, 0x8326F900) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__41(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__41(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__41 = 0x8349CCF4u;
	if (!UseLiftedCode(144, 0x8326F938)) { __imp__sub_8326F938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F938);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__41, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326F938, 0x8326F938) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__41(ctx, base); }

uint64_t Construct_TXT_8349CCF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CCF8_G_ = int32_t(0x8349CCF8);
	constexpr int32_t str_TXT_820E4848_B_ = int32_t(0x820E4848);
	constexpr int32_t Destroy_TXT_8349CCF8_G__address = int32_t(0x832A8A40);
	if (!UseLiftedCode(144, 0x8326F970)) { __imp__sub_8326F970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F970);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CCF8_G_, str_TXT_820E4848_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CCF8_G__address);
}
PROMOTED_ENTRY(144, sub_8326F970, 0x8326F970) { ctx.r3.u64 = Construct_TXT_8349CCF8_G_(ctx, base); }

uint64_t Construct_TXT_8349CD00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CD00_G_ = int32_t(0x8349CD00);
	constexpr int32_t str_TXT_820E4874_B_ = int32_t(0x820E4874);
	constexpr int32_t Destroy_TXT_8349CD00_G__address = int32_t(0x832A8A60);
	if (!UseLiftedCode(144, 0x8326F9F0)) { __imp__sub_8326F9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD00_G_, str_TXT_820E4874_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CD00_G__address);
}
PROMOTED_ENTRY(144, sub_8326F9F0, 0x8326F9F0) { ctx.r3.u64 = Construct_TXT_8349CD00_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__42 = 0x8349CD04u;
	if (!UseLiftedCode(144, 0x8326FA30)) { __imp__sub_8326FA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FA30);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FA30, 0x8326FA30) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__42(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__44 = 0x8349CD08u;
	if (!UseLiftedCode(144, 0x8326FA68)) { __imp__sub_8326FA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FA68);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FA68, 0x8326FA68) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__44(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__43 = 0x8349CD0Cu;
	if (!UseLiftedCode(144, 0x8326FAA0)) { __imp__sub_8326FAA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FAA0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FAA0, 0x8326FAA0) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C0C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C0C_B_ = int32_t(0x820A2C0C);
	constexpr uint32_t g_HashOf_TXT_820A2C0C_B__42 = 0x8349CD10u;
	if (!UseLiftedCode(144, 0x8326FAD8)) { __imp__sub_8326FAD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FAD8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C0C_B_);
	STORE32(g_HashOf_TXT_820A2C0C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FAD8, 0x8326FAD8) { ctx.r3.u64 = HashName_TXT_820A2C0C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C1C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C1C_B_ = int32_t(0x820A2C1C);
	constexpr uint32_t g_HashOf_TXT_820A2C1C_B__42 = 0x8349CD14u;
	if (!UseLiftedCode(144, 0x8326FB10)) { __imp__sub_8326FB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FB10);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C1C_B_);
	STORE32(g_HashOf_TXT_820A2C1C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FB10, 0x8326FB10) { ctx.r3.u64 = HashName_TXT_820A2C1C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C34_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C34_B_ = int32_t(0x820A2C34);
	constexpr uint32_t g_HashOf_TXT_820A2C34_B__43 = 0x8349CD18u;
	if (!UseLiftedCode(144, 0x8326FB48)) { __imp__sub_8326FB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FB48);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C34_B_);
	STORE32(g_HashOf_TXT_820A2C34_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FB48, 0x8326FB48) { ctx.r3.u64 = HashName_TXT_820A2C34_B__43(ctx, base); }

uint64_t HashName_TXT_820A2C44_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C44_B_ = int32_t(0x820A2C44);
	constexpr uint32_t g_HashOf_TXT_820A2C44_B__42 = 0x8349CD1Cu;
	if (!UseLiftedCode(144, 0x8326FB80)) { __imp__sub_8326FB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FB80);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C44_B_);
	STORE32(g_HashOf_TXT_820A2C44_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FB80, 0x8326FB80) { ctx.r3.u64 = HashName_TXT_820A2C44_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C5C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C5C_B_ = int32_t(0x820A2C5C);
	constexpr uint32_t g_HashOf_TXT_820A2C5C_B__42 = 0x8349CD20u;
	if (!UseLiftedCode(144, 0x8326FBB8)) { __imp__sub_8326FBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C5C_B_);
	STORE32(g_HashOf_TXT_820A2C5C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FBB8, 0x8326FBB8) { ctx.r3.u64 = HashName_TXT_820A2C5C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C74_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C74_B_ = int32_t(0x820A2C74);
	constexpr uint32_t g_HashOf_TXT_820A2C74_B__42 = 0x8349CD24u;
	if (!UseLiftedCode(144, 0x8326FBF0)) { __imp__sub_8326FBF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FBF0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C74_B_);
	STORE32(g_HashOf_TXT_820A2C74_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FBF0, 0x8326FBF0) { ctx.r3.u64 = HashName_TXT_820A2C74_B__42(ctx, base); }

uint64_t HashName_TXT_820A2C8C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2C8C_B_ = int32_t(0x820A2C8C);
	constexpr uint32_t g_HashOf_TXT_820A2C8C_B__42 = 0x8349CD28u;
	if (!UseLiftedCode(144, 0x8326FC28)) { __imp__sub_8326FC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FC28);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2C8C_B_);
	STORE32(g_HashOf_TXT_820A2C8C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FC28, 0x8326FC28) { ctx.r3.u64 = HashName_TXT_820A2C8C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CA0_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CA0_B_ = int32_t(0x820A2CA0);
	constexpr uint32_t g_HashOf_TXT_820A2CA0_B__42 = 0x8349CD2Cu;
	if (!UseLiftedCode(144, 0x8326FC60)) { __imp__sub_8326FC60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FC60);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CA0_B_);
	STORE32(g_HashOf_TXT_820A2CA0_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FC60, 0x8326FC60) { ctx.r3.u64 = HashName_TXT_820A2CA0_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CC0_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CC0_B_ = int32_t(0x820A2CC0);
	constexpr uint32_t g_HashOf_TXT_820A2CC0_B__42 = 0x8349CD30u;
	if (!UseLiftedCode(144, 0x8326FC98)) { __imp__sub_8326FC98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FC98);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CC0_B_);
	STORE32(g_HashOf_TXT_820A2CC0_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FC98, 0x8326FC98) { ctx.r3.u64 = HashName_TXT_820A2CC0_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CD4_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CD4_B_ = int32_t(0x820A2CD4);
	constexpr uint32_t g_HashOf_TXT_820A2CD4_B__45 = 0x8349CD34u;
	if (!UseLiftedCode(144, 0x8326FCD0)) { __imp__sub_8326FCD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FCD0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CD4_B_);
	STORE32(g_HashOf_TXT_820A2CD4_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FCD0, 0x8326FCD0) { ctx.r3.u64 = HashName_TXT_820A2CD4_B__45(ctx, base); }

uint64_t HashName_TXT_820A2CE0_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CE0_B_ = int32_t(0x820A2CE0);
	constexpr uint32_t g_HashOf_TXT_820A2CE0_B__42 = 0x8349CD38u;
	if (!UseLiftedCode(144, 0x8326FD08)) { __imp__sub_8326FD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FD08);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CE0_B_);
	STORE32(g_HashOf_TXT_820A2CE0_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FD08, 0x8326FD08) { ctx.r3.u64 = HashName_TXT_820A2CE0_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CEC_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CEC_B_ = int32_t(0x820A2CEC);
	constexpr uint32_t g_HashOf_TXT_820A2CEC_B__42 = 0x8349CD3Cu;
	if (!UseLiftedCode(144, 0x8326FD40)) { __imp__sub_8326FD40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FD40);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CEC_B_);
	STORE32(g_HashOf_TXT_820A2CEC_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FD40, 0x8326FD40) { ctx.r3.u64 = HashName_TXT_820A2CEC_B__42(ctx, base); }

uint64_t HashName_TXT_820A2CFC_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2CFC_B_ = int32_t(0x820A2CFC);
	constexpr uint32_t g_HashOf_TXT_820A2CFC_B__42 = 0x8349CD40u;
	if (!UseLiftedCode(144, 0x8326FD78)) { __imp__sub_8326FD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FD78);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2CFC_B_);
	STORE32(g_HashOf_TXT_820A2CFC_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FD78, 0x8326FD78) { ctx.r3.u64 = HashName_TXT_820A2CFC_B__42(ctx, base); }

uint64_t HashName_TXT_820A2D0C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D0C_B_ = int32_t(0x820A2D0C);
	constexpr uint32_t g_HashOf_TXT_820A2D0C_B__42 = 0x8349CD44u;
	if (!UseLiftedCode(144, 0x8326FDB0)) { __imp__sub_8326FDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FDB0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D0C_B_);
	STORE32(g_HashOf_TXT_820A2D0C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FDB0, 0x8326FDB0) { ctx.r3.u64 = HashName_TXT_820A2D0C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2D24_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D24_B_ = int32_t(0x820A2D24);
	constexpr uint32_t g_HashOf_TXT_820A2D24_B__43 = 0x8349CD48u;
	if (!UseLiftedCode(144, 0x8326FDE8)) { __imp__sub_8326FDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FDE8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D24_B_);
	STORE32(g_HashOf_TXT_820A2D24_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FDE8, 0x8326FDE8) { ctx.r3.u64 = HashName_TXT_820A2D24_B__43(ctx, base); }

uint64_t HashName_TXT_820A2D30_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D30_B_ = int32_t(0x820A2D30);
	constexpr uint32_t g_HashOf_TXT_820A2D30_B__42 = 0x8349CD4Cu;
	if (!UseLiftedCode(144, 0x8326FE20)) { __imp__sub_8326FE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FE20);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D30_B_);
	STORE32(g_HashOf_TXT_820A2D30_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FE20, 0x8326FE20) { ctx.r3.u64 = HashName_TXT_820A2D30_B__42(ctx, base); }

uint64_t HashName_TXT_820A2D3C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D3C_B_ = int32_t(0x820A2D3C);
	constexpr uint32_t g_HashOf_TXT_820A2D3C_B__42 = 0x8349CD50u;
	if (!UseLiftedCode(144, 0x8326FE58)) { __imp__sub_8326FE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FE58);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D3C_B_);
	STORE32(g_HashOf_TXT_820A2D3C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FE58, 0x8326FE58) { ctx.r3.u64 = HashName_TXT_820A2D3C_B__42(ctx, base); }

uint64_t HashName_TXT_820A2D4C_B__42(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2D4C_B_ = int32_t(0x820A2D4C);
	constexpr uint32_t g_HashOf_TXT_820A2D4C_B__42 = 0x8349CD54u;
	if (!UseLiftedCode(144, 0x8326FE90)) { __imp__sub_8326FE90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FE90);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2D4C_B_);
	STORE32(g_HashOf_TXT_820A2D4C_B__42, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FE90, 0x8326FE90) { ctx.r3.u64 = HashName_TXT_820A2D4C_B__42(ctx, base); }

uint64_t Construct_TXT_8349CD58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CD58_G_ = int32_t(0x8349CD58);
	constexpr int32_t str_TXT_820E48F0_B_ = int32_t(0x820E48F0);
	constexpr int32_t Destroy_TXT_8349CD58_G__address = int32_t(0x832A8A70);
	if (!UseLiftedCode(144, 0x8326FEC8)) { __imp__sub_8326FEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FEC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD58_G_, str_TXT_820E48F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CD58_G__address);
}
PROMOTED_ENTRY(144, sub_8326FEC8, 0x8326FEC8) { ctx.r3.u64 = Construct_TXT_8349CD58_G_(ctx, base); }

uint64_t Construct_TXT_8349CD60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349CD60_G_ = int32_t(0x8349CD60);
	constexpr int32_t str_TXT_820E2458_B_ = int32_t(0x820E2458);
	constexpr int32_t Destroy_TXT_8349CD60_G__address = int32_t(0x832A8A90);
	if (!UseLiftedCode(144, 0x8326FF48)) { __imp__sub_8326FF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FF48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD60_G_, str_TXT_820E2458_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349CD60_G__address);
}
PROMOTED_ENTRY(144, sub_8326FF48, 0x8326FF48) { ctx.r3.u64 = Construct_TXT_8349CD60_G_(ctx, base); }

uint64_t HashName_TXT_820A2BD4_B__43(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BD4_B_ = int32_t(0x820A2BD4);
	constexpr uint32_t g_HashOf_TXT_820A2BD4_B__43 = 0x8349CD64u;
	if (!UseLiftedCode(144, 0x8326FF88)) { __imp__sub_8326FF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FF88);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BD4_B_);
	STORE32(g_HashOf_TXT_820A2BD4_B__43, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FF88, 0x8326FF88) { ctx.r3.u64 = HashName_TXT_820A2BD4_B__43(ctx, base); }

uint64_t HashName_TXT_820A2BE8_B__45(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BE8_B_ = int32_t(0x820A2BE8);
	constexpr uint32_t g_HashOf_TXT_820A2BE8_B__45 = 0x8349CD68u;
	if (!UseLiftedCode(144, 0x8326FFC0)) { __imp__sub_8326FFC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FFC0);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BE8_B_);
	STORE32(g_HashOf_TXT_820A2BE8_B__45, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FFC0, 0x8326FFC0) { ctx.r3.u64 = HashName_TXT_820A2BE8_B__45(ctx, base); }

uint64_t HashName_TXT_820A2BF4_B__44(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820A2BF4_B_ = int32_t(0x820A2BF4);
	constexpr uint32_t g_HashOf_TXT_820A2BF4_B__44 = 0x8349CD6Cu;
	if (!UseLiftedCode(144, 0x8326FFF8)) { __imp__sub_8326FFF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FFF8);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t hash = HashNameFnv1(ctx, base, str_TXT_820A2BF4_B_);
	STORE32(g_HashOf_TXT_820A2BF4_B__44, (uint32_t)hash);
	return hash;
}
PROMOTED_ENTRY(144, sub_8326FFF8, 0x8326FFF8) { ctx.r3.u64 = HashName_TXT_820A2BF4_B__44(ctx, base); }
