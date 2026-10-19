// Start-up initialisers of global objects (they register property and definition names) at
// 0x8326xxxx, as readable C++.
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

uint64_t n_sub_83260318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B52C_G_ = int32_t(0x8349B52C);
	if (!UseLiftedCode(143, 0x83260318)) { __imp__sub_83260318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B52C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260318, 0x83260318) { ctx.r3.u64 = n_sub_83260318(ctx, base); }

uint64_t n_sub_83260358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B530_G_ = int32_t(0x8349B530);
	if (!UseLiftedCode(143, 0x83260358)) { __imp__sub_83260358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B530_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260358, 0x83260358) { ctx.r3.u64 = n_sub_83260358(ctx, base); }

uint64_t n_sub_83260398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B534_G_ = int32_t(0x8349B534);
	if (!UseLiftedCode(143, 0x83260398)) { __imp__sub_83260398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B534_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 24984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260398, 0x83260398) { ctx.r3.u64 = n_sub_83260398(ctx, base); }

uint64_t n_sub_83260468(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260468)) { ctx.r8.u64 = arg1; __imp__sub_83260468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260468);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25016, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260468, 0x83260468) { ctx.r3.u64 = n_sub_83260468(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83260478(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260478)) { ctx.r8.u64 = arg1; __imp__sub_83260478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260478);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25032, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260478, 0x83260478) { ctx.r3.u64 = n_sub_83260478(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83260488(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260488)) { ctx.r8.u64 = arg1; __imp__sub_83260488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260488);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25048, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260488, 0x83260488) { ctx.r3.u64 = n_sub_83260488(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83260498(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260498)) { ctx.r8.u64 = arg1; __imp__sub_83260498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260498);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25064, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260498, 0x83260498) { ctx.r3.u64 = n_sub_83260498(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832604A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B564_G_ = int32_t(0x8349B564);
	if (!UseLiftedCode(143, 0x832604A8)) { __imp__sub_832604A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832604A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349B564_G_, (int64_t)str_TXT_820D0000_B_ + 25892, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832604A8, 0x832604A8) { ctx.r3.u64 = n_sub_832604A8(ctx, base); }

uint64_t n_sub_832609E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B608_G_ = int32_t(0x8349B608);
	if (!UseLiftedCode(143, 0x832609E8)) { __imp__sub_832609E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832609E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B608_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832609E8, 0x832609E8) { ctx.r3.u64 = n_sub_832609E8(ctx, base); }

uint64_t n_sub_83260A28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B60C_G_ = int32_t(0x8349B60C);
	if (!UseLiftedCode(143, 0x83260A28)) { __imp__sub_83260A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260A28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B60C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260A28, 0x83260A28) { ctx.r3.u64 = n_sub_83260A28(ctx, base); }

uint64_t n_sub_83260A68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B610_G_ = int32_t(0x8349B610);
	if (!UseLiftedCode(143, 0x83260A68)) { __imp__sub_83260A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260A68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B610_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260A68, 0x83260A68) { ctx.r3.u64 = n_sub_83260A68(ctx, base); }

uint64_t n_sub_83260AE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B618_G_ = int32_t(0x8349B618);
	if (!UseLiftedCode(143, 0x83260AE0)) { __imp__sub_83260AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260AE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B618_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260AE0, 0x83260AE0) { ctx.r3.u64 = n_sub_83260AE0(ctx, base); }

uint64_t n_sub_83260B20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B61C_G_ = int32_t(0x8349B61C);
	if (!UseLiftedCode(143, 0x83260B20)) { __imp__sub_83260B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260B20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B61C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260B20, 0x83260B20) { ctx.r3.u64 = n_sub_83260B20(ctx, base); }

uint64_t n_sub_83260B60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B620_G_ = int32_t(0x8349B620);
	if (!UseLiftedCode(143, 0x83260B60)) { __imp__sub_83260B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260B60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B620_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260B60, 0x83260B60) { ctx.r3.u64 = n_sub_83260B60(ctx, base); }

uint64_t n_sub_83260BA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B624_G_ = int32_t(0x8349B624);
	if (!UseLiftedCode(143, 0x83260BA0)) { __imp__sub_83260BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260BA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B624_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260BA0, 0x83260BA0) { ctx.r3.u64 = n_sub_83260BA0(ctx, base); }

uint64_t n_sub_83260BE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B628_G_ = int32_t(0x8349B628);
	if (!UseLiftedCode(143, 0x83260BE0)) { __imp__sub_83260BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260BE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B628_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260BE0, 0x83260BE0) { ctx.r3.u64 = n_sub_83260BE0(ctx, base); }

uint64_t n_sub_83260C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B62C_G_ = int32_t(0x8349B62C);
	if (!UseLiftedCode(143, 0x83260C20)) { __imp__sub_83260C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260C20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B62C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260C20, 0x83260C20) { ctx.r3.u64 = n_sub_83260C20(ctx, base); }

uint64_t n_sub_83260C80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B634_G_ = int32_t(0x8349B634);
	if (!UseLiftedCode(143, 0x83260C80)) { __imp__sub_83260C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260C80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B634_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260C80, 0x83260C80) { ctx.r3.u64 = n_sub_83260C80(ctx, base); }

uint64_t n_sub_83260CC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B638_G_ = int32_t(0x8349B638);
	if (!UseLiftedCode(143, 0x83260CC0)) { __imp__sub_83260CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260CC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B638_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260CC0, 0x83260CC0) { ctx.r3.u64 = n_sub_83260CC0(ctx, base); }

uint64_t n_sub_83260D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B63C_G_ = int32_t(0x8349B63C);
	if (!UseLiftedCode(143, 0x83260D00)) { __imp__sub_83260D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B63C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260D00, 0x83260D00) { ctx.r3.u64 = n_sub_83260D00(ctx, base); }

uint64_t n_sub_83260D40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B640_G_ = int32_t(0x8349B640);
	if (!UseLiftedCode(143, 0x83260D40)) { __imp__sub_83260D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B640_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260D40, 0x83260D40) { ctx.r3.u64 = n_sub_83260D40(ctx, base); }

uint64_t n_sub_83260D80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B644_G_ = int32_t(0x8349B644);
	if (!UseLiftedCode(143, 0x83260D80)) { __imp__sub_83260D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260D80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B644_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260D80, 0x83260D80) { ctx.r3.u64 = n_sub_83260D80(ctx, base); }

uint64_t n_sub_83260DC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349B648_G_ = int32_t(0x8349B648);
	if (!UseLiftedCode(143, 0x83260DC0)) { __imp__sub_83260DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260DC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349B648_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260DC0, 0x83260DC0) { ctx.r3.u64 = n_sub_83260DC0(ctx, base); }

uint64_t n_sub_83260E40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BB10_G_ = int32_t(0x8349BB10);
	if (!UseLiftedCode(143, 0x83260E40)) { __imp__sub_83260E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260E40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB10_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260E40, 0x83260E40) { ctx.r3.u64 = n_sub_83260E40(ctx, base); }

uint64_t n_sub_83260E80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BB14_G_ = int32_t(0x8349BB14);
	if (!UseLiftedCode(143, 0x83260E80)) { __imp__sub_83260E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260E80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB14_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260E80, 0x83260E80) { ctx.r3.u64 = n_sub_83260E80(ctx, base); }

uint64_t n_sub_83260EC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BB18_G_ = int32_t(0x8349BB18);
	if (!UseLiftedCode(143, 0x83260EC0)) { __imp__sub_83260EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260EC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB18_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260EC0, 0x83260EC0) { ctx.r3.u64 = n_sub_83260EC0(ctx, base); }

uint64_t n_sub_83260F00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260F00)) { ctx.r8.u64 = arg1; __imp__sub_83260F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F00);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25488, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260F00, 0x83260F00) { ctx.r3.u64 = n_sub_83260F00(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83260F10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BB2C_G_ = int32_t(0x8349BB2C);
	if (!UseLiftedCode(143, 0x83260F10)) { __imp__sub_83260F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB2C_G_, (int64_t)str_TXT_820B0000_B_ - 7020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260F10, 0x83260F10) { ctx.r3.u64 = n_sub_83260F10(ctx, base); }

uint64_t n_sub_83260F50(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83260F50)) { ctx.r8.u64 = arg1; __imp__sub_83260F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F50);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25608, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83260F50, 0x83260F50) { ctx.r3.u64 = n_sub_83260F50(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83260F60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BB40_G_ = int32_t(0x8349BB40);
	if (!UseLiftedCode(143, 0x83260F60)) { __imp__sub_83260F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260F60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BB40_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260F60, 0x83260F60) { ctx.r3.u64 = n_sub_83260F60(ctx, base); }

// sub_83260FA0  [60 bytes]
uint64_t n_sub_83260FA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB44 = int32_t(0x8349BB44);
	if (!UseLiftedCode(143, 0x83260FA0)) { __imp__sub_83260FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260FA0);
	// Assigns the global string from a wide string constant, then registers its release to run at exit
	// (n_sub_82CA3700 is atexit).
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB44, (int64_t)str_TXT_820D0000_B_ + 31532);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260FA0, 0x83260FA0) { ctx.r3.u64 = n_sub_83260FA0(ctx, base); }

uint64_t n_sub_83260FE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB48 = int32_t(0x8349BB48);
	if (!UseLiftedCode(143, 0x83260FE0)) { __imp__sub_83260FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83260FE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB48, (int64_t)str_TXT_820D0000_B_ + 31536);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83260FE0, 0x83260FE0) { ctx.r3.u64 = n_sub_83260FE0(ctx, base); }

uint64_t n_sub_83261020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB4C = int32_t(0x8349BB4C);
	if (!UseLiftedCode(143, 0x83261020)) { __imp__sub_83261020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB4C, (int64_t)str_TXT_820D0000_B_ + 31544);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261020, 0x83261020) { ctx.r3.u64 = n_sub_83261020(ctx, base); }

uint64_t n_sub_83261060(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB50 = int32_t(0x8349BB50);
	if (!UseLiftedCode(143, 0x83261060)) { __imp__sub_83261060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261060);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB50, (int64_t)str_TXT_820D0000_B_ + 31552);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261060, 0x83261060) { ctx.r3.u64 = n_sub_83261060(ctx, base); }

uint64_t n_sub_832610A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB54 = int32_t(0x8349BB54);
	if (!UseLiftedCode(143, 0x832610A0)) { __imp__sub_832610A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832610A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB54, (int64_t)str_TXT_820D0000_B_ + 31560);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832610A0, 0x832610A0) { ctx.r3.u64 = n_sub_832610A0(ctx, base); }

uint64_t n_sub_832610E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB58 = int32_t(0x8349BB58);
	if (!UseLiftedCode(143, 0x832610E0)) { __imp__sub_832610E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832610E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB58, (int64_t)str_TXT_820D0000_B_ + 31568);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832610E0, 0x832610E0) { ctx.r3.u64 = n_sub_832610E0(ctx, base); }

uint64_t n_sub_83261120(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB5C = int32_t(0x8349BB5C);
	if (!UseLiftedCode(143, 0x83261120)) { __imp__sub_83261120(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261120);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB5C, (int64_t)str_TXT_820D0000_B_ + 31580);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261120, 0x83261120) { ctx.r3.u64 = n_sub_83261120(ctx, base); }

uint64_t n_sub_83261160(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB60 = int32_t(0x8349BB60);
	if (!UseLiftedCode(143, 0x83261160)) { __imp__sub_83261160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261160);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB60, (int64_t)str_TXT_820D0000_B_ + 31592);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261160, 0x83261160) { ctx.r3.u64 = n_sub_83261160(ctx, base); }

uint64_t n_sub_832611A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB64 = int32_t(0x8349BB64);
	if (!UseLiftedCode(143, 0x832611A0)) { __imp__sub_832611A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832611A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB64, (int64_t)str_TXT_820D0000_B_ + 31604);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832611A0, 0x832611A0) { ctx.r3.u64 = n_sub_832611A0(ctx, base); }

uint64_t n_sub_832611E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB68 = int32_t(0x8349BB68);
	if (!UseLiftedCode(143, 0x832611E0)) { __imp__sub_832611E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832611E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB68, (int64_t)str_TXT_820D0000_B_ + 31616);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832611E0, 0x832611E0) { ctx.r3.u64 = n_sub_832611E0(ctx, base); }

uint64_t n_sub_83261220(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB6C = int32_t(0x8349BB6C);
	if (!UseLiftedCode(143, 0x83261220)) { __imp__sub_83261220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261220);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB6C, (int64_t)str_TXT_820D0000_B_ + 31636);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261220, 0x83261220) { ctx.r3.u64 = n_sub_83261220(ctx, base); }

uint64_t n_sub_83261260(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB70 = int32_t(0x8349BB70);
	if (!UseLiftedCode(143, 0x83261260)) { __imp__sub_83261260(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261260);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB70, (int64_t)str_TXT_820D0000_B_ + 31644);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261260, 0x83261260) { ctx.r3.u64 = n_sub_83261260(ctx, base); }

uint64_t n_sub_832612A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB74 = int32_t(0x8349BB74);
	if (!UseLiftedCode(143, 0x832612A0)) { __imp__sub_832612A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832612A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB74, (int64_t)str_TXT_820D0000_B_ + 31668);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832612A0, 0x832612A0) { ctx.r3.u64 = n_sub_832612A0(ctx, base); }

uint64_t n_sub_832612E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB78 = int32_t(0x8349BB78);
	if (!UseLiftedCode(143, 0x832612E0)) { __imp__sub_832612E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832612E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB78, (int64_t)str_TXT_820D0000_B_ + 31688);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832612E0, 0x832612E0) { ctx.r3.u64 = n_sub_832612E0(ctx, base); }

uint64_t n_sub_83261320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB7C = int32_t(0x8349BB7C);
	if (!UseLiftedCode(143, 0x83261320)) { __imp__sub_83261320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261320);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB7C, (int64_t)str_TXT_820D0000_B_ + 31708);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261320, 0x83261320) { ctx.r3.u64 = n_sub_83261320(ctx, base); }

uint64_t n_sub_83261360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB80 = int32_t(0x8349BB80);
	if (!UseLiftedCode(143, 0x83261360)) { __imp__sub_83261360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261360);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB80, (int64_t)str_TXT_820D0000_B_ + 31728);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 25992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261360, 0x83261360) { ctx.r3.u64 = n_sub_83261360(ctx, base); }

uint64_t n_sub_832613A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB84 = int32_t(0x8349BB84);
	if (!UseLiftedCode(143, 0x832613A0)) { __imp__sub_832613A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832613A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB84, (int64_t)str_TXT_820D0000_B_ + 31748);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832613A0, 0x832613A0) { ctx.r3.u64 = n_sub_832613A0(ctx, base); }

uint64_t n_sub_832613E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB88 = int32_t(0x8349BB88);
	if (!UseLiftedCode(143, 0x832613E0)) { __imp__sub_832613E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832613E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB88, (int64_t)str_TXT_820D0000_B_ + 31780);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832613E0, 0x832613E0) { ctx.r3.u64 = n_sub_832613E0(ctx, base); }

uint64_t n_sub_83261420(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB8C = int32_t(0x8349BB8C);
	if (!UseLiftedCode(143, 0x83261420)) { __imp__sub_83261420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261420);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB8C, (int64_t)str_TXT_820D0000_B_ + 31808);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261420, 0x83261420) { ctx.r3.u64 = n_sub_83261420(ctx, base); }

uint64_t n_sub_83261460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB90 = int32_t(0x8349BB90);
	if (!UseLiftedCode(143, 0x83261460)) { __imp__sub_83261460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261460);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB90, (int64_t)str_TXT_820D0000_B_ + 31836);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261460, 0x83261460) { ctx.r3.u64 = n_sub_83261460(ctx, base); }

uint64_t n_sub_832614A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB94 = int32_t(0x8349BB94);
	if (!UseLiftedCode(143, 0x832614A0)) { __imp__sub_832614A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832614A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB94, (int64_t)str_TXT_820D0000_B_ + 31864);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832614A0, 0x832614A0) { ctx.r3.u64 = n_sub_832614A0(ctx, base); }

uint64_t n_sub_832614E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB98 = int32_t(0x8349BB98);
	if (!UseLiftedCode(143, 0x832614E0)) { __imp__sub_832614E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832614E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB98, (int64_t)str_TXT_820D0000_B_ + 31896);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832614E0, 0x832614E0) { ctx.r3.u64 = n_sub_832614E0(ctx, base); }

uint64_t n_sub_83261520(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BB9C = int32_t(0x8349BB9C);
	if (!UseLiftedCode(143, 0x83261520)) { __imp__sub_83261520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261520);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BB9C, (int64_t)str_TXT_820D0000_B_ + 31920);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261520, 0x83261520) { ctx.r3.u64 = n_sub_83261520(ctx, base); }

uint64_t n_sub_83261560(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBA0 = int32_t(0x8349BBA0);
	if (!UseLiftedCode(143, 0x83261560)) { __imp__sub_83261560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA0, (int64_t)str_TXT_820D0000_B_ + 31940);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83261560, 0x83261560) { ctx.r3.u64 = n_sub_83261560(ctx, base); }

uint64_t n_sub_832615A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBA4 = int32_t(0x8349BBA4);
	if (!UseLiftedCode(143, 0x832615A0)) { __imp__sub_832615A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832615A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA4, (int64_t)str_TXT_820D0000_B_ + 31972);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832615A0, 0x832615A0) { ctx.r3.u64 = n_sub_832615A0(ctx, base); }

uint64_t n_sub_832615E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBA8 = int32_t(0x8349BBA8);
	if (!UseLiftedCode(144, 0x832615E0)) { __imp__sub_832615E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832615E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBA8, (int64_t)str_TXT_820D0000_B_ + 32000);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832615E0, 0x832615E0) { ctx.r3.u64 = n_sub_832615E0(ctx, base); }

uint64_t n_sub_83261620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBAC = int32_t(0x8349BBAC);
	if (!UseLiftedCode(144, 0x83261620)) { __imp__sub_83261620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261620);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBAC, (int64_t)str_TXT_820D0000_B_ + 32028);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261620, 0x83261620) { ctx.r3.u64 = n_sub_83261620(ctx, base); }

uint64_t n_sub_83261660(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBB0 = int32_t(0x8349BBB0);
	if (!UseLiftedCode(144, 0x83261660)) { __imp__sub_83261660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261660);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB0, (int64_t)str_TXT_820D0000_B_ + 32060);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261660, 0x83261660) { ctx.r3.u64 = n_sub_83261660(ctx, base); }

uint64_t n_sub_832616A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBB4 = int32_t(0x8349BBB4);
	if (!UseLiftedCode(144, 0x832616A0)) { __imp__sub_832616A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832616A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB4, (int64_t)str_TXT_820D0000_B_ + 31644);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832616A0, 0x832616A0) { ctx.r3.u64 = n_sub_832616A0(ctx, base); }

uint64_t n_sub_832616E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBB8 = int32_t(0x8349BBB8);
	if (!UseLiftedCode(144, 0x832616E0)) { __imp__sub_832616E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832616E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBB8, (int64_t)str_TXT_820D0000_B_ + 32096);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832616E0, 0x832616E0) { ctx.r3.u64 = n_sub_832616E0(ctx, base); }

uint64_t n_sub_83261720(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBBC = int32_t(0x8349BBBC);
	if (!UseLiftedCode(144, 0x83261720)) { __imp__sub_83261720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261720);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBBC, (int64_t)str_TXT_820D0000_B_ + 32120);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261720, 0x83261720) { ctx.r3.u64 = n_sub_83261720(ctx, base); }

uint64_t n_sub_83261760(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBC0 = int32_t(0x8349BBC0);
	if (!UseLiftedCode(144, 0x83261760)) { __imp__sub_83261760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261760);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC0, (int64_t)str_TXT_820D0000_B_ + 32144);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261760, 0x83261760) { ctx.r3.u64 = n_sub_83261760(ctx, base); }

uint64_t n_sub_832617A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBC4 = int32_t(0x8349BBC4);
	if (!UseLiftedCode(144, 0x832617A0)) { __imp__sub_832617A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832617A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC4, (int64_t)str_TXT_820D0000_B_ + 32168);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832617A0, 0x832617A0) { ctx.r3.u64 = n_sub_832617A0(ctx, base); }

uint64_t n_sub_832617E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBC8 = int32_t(0x8349BBC8);
	if (!UseLiftedCode(144, 0x832617E0)) { __imp__sub_832617E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832617E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBC8, (int64_t)str_TXT_820D0000_B_ + 32192);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832617E0, 0x832617E0) { ctx.r3.u64 = n_sub_832617E0(ctx, base); }

uint64_t n_sub_83261820(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBCC = int32_t(0x8349BBCC);
	if (!UseLiftedCode(144, 0x83261820)) { __imp__sub_83261820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261820);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBCC, (int64_t)str_TXT_820D0000_B_ + 32216);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261820, 0x83261820) { ctx.r3.u64 = n_sub_83261820(ctx, base); }

uint64_t n_sub_83261860(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBD0 = int32_t(0x8349BBD0);
	if (!UseLiftedCode(144, 0x83261860)) { __imp__sub_83261860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261860);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD0, (int64_t)str_TXT_820D0000_B_ + 32236);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261860, 0x83261860) { ctx.r3.u64 = n_sub_83261860(ctx, base); }

uint64_t n_sub_832618A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBD4 = int32_t(0x8349BBD4);
	if (!UseLiftedCode(144, 0x832618A0)) { __imp__sub_832618A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832618A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD4, (int64_t)str_TXT_820D0000_B_ + 32256);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832618A0, 0x832618A0) { ctx.r3.u64 = n_sub_832618A0(ctx, base); }

uint64_t n_sub_832618E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBD8 = int32_t(0x8349BBD8);
	if (!UseLiftedCode(144, 0x832618E0)) { __imp__sub_832618E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832618E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBD8, (int64_t)str_TXT_820D0000_B_ + 32276);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832618E0, 0x832618E0) { ctx.r3.u64 = n_sub_832618E0(ctx, base); }

uint64_t n_sub_83261920(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBDC = int32_t(0x8349BBDC);
	if (!UseLiftedCode(144, 0x83261920)) { __imp__sub_83261920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261920);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBDC, (int64_t)str_TXT_820D0000_B_ + 32296);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261920, 0x83261920) { ctx.r3.u64 = n_sub_83261920(ctx, base); }

uint64_t n_sub_83261960(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBE0 = int32_t(0x8349BBE0);
	if (!UseLiftedCode(144, 0x83261960)) { __imp__sub_83261960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261960);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE0, (int64_t)str_TXT_820D0000_B_ + 32316);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261960, 0x83261960) { ctx.r3.u64 = n_sub_83261960(ctx, base); }

uint64_t n_sub_832619A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBE4 = int32_t(0x8349BBE4);
	if (!UseLiftedCode(144, 0x832619A0)) { __imp__sub_832619A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832619A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE4, (int64_t)str_TXT_820D0000_B_ + 32336);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832619A0, 0x832619A0) { ctx.r3.u64 = n_sub_832619A0(ctx, base); }

uint64_t n_sub_832619E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBE8 = int32_t(0x8349BBE8);
	if (!UseLiftedCode(144, 0x832619E0)) { __imp__sub_832619E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832619E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBE8, (int64_t)str_TXT_820D0000_B_ + 32356);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832619E0, 0x832619E0) { ctx.r3.u64 = n_sub_832619E0(ctx, base); }

uint64_t n_sub_83261A20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBEC = int32_t(0x8349BBEC);
	if (!UseLiftedCode(144, 0x83261A20)) { __imp__sub_83261A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261A20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBEC, (int64_t)str_TXT_820D0000_B_ + 32388);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261A20, 0x83261A20) { ctx.r3.u64 = n_sub_83261A20(ctx, base); }

uint64_t n_sub_83261A60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBF0 = int32_t(0x8349BBF0);
	if (!UseLiftedCode(144, 0x83261A60)) { __imp__sub_83261A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261A60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF0, (int64_t)str_TXT_820D0000_B_ + 32412);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261A60, 0x83261A60) { ctx.r3.u64 = n_sub_83261A60(ctx, base); }

uint64_t n_sub_83261AA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBF4 = int32_t(0x8349BBF4);
	if (!UseLiftedCode(144, 0x83261AA0)) { __imp__sub_83261AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261AA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF4, (int64_t)str_TXT_820D0000_B_ + 32432);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261AA0, 0x83261AA0) { ctx.r3.u64 = n_sub_83261AA0(ctx, base); }

uint64_t n_sub_83261AE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_8349BBF8 = int32_t(0x8349BBF8);
	if (!UseLiftedCode(144, 0x83261AE0)) { __imp__sub_83261AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261AE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_AssignFromWideStr(ctx, base, (int64_t)g_8349BBF8, (int64_t)str_TXT_820D0000_B_ + 32464);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261AE0, 0x83261AE0) { ctx.r3.u64 = n_sub_83261AE0(ctx, base); }

uint64_t n_sub_83261C90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC18_G_ = int32_t(0x8349BC18);
	if (!UseLiftedCode(144, 0x83261C90)) { __imp__sub_83261C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261C90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349BC18_G_, (int64_t)str_TXT_820D0000_B_ + 6480, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261C90, 0x83261C90) { ctx.r3.u64 = n_sub_83261C90(ctx, base); }

uint64_t n_sub_83261D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC20_G_ = int32_t(0x8349BC20);
	if (!UseLiftedCode(144, 0x83261D08)) { __imp__sub_83261D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC20_G_, (int64_t)str_TXT_820C0000_B_ + 16124, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261D08, 0x83261D08) { ctx.r3.u64 = n_sub_83261D08(ctx, base); }

// sub_83261D48  [64 bytes]
uint64_t n_sub_83261D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC24_G_ = int32_t(0x8349BC24);
	if (!UseLiftedCode(144, 0x83261D48)) { __imp__sub_83261D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D48);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC24_G_, (int64_t)g_820E0000 - 32768, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261D48, 0x83261D48) { ctx.r3.u64 = n_sub_83261D48(ctx, base); }

uint64_t n_sub_83261D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC28_G_ = int32_t(0x8349BC28);
	if (!UseLiftedCode(144, 0x83261D88)) { __imp__sub_83261D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC28_G_, (int64_t)g_820E0000 - 32740, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261D88, 0x83261D88) { ctx.r3.u64 = n_sub_83261D88(ctx, base); }

uint64_t n_sub_83261DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC2C_G_ = int32_t(0x8349BC2C);
	if (!UseLiftedCode(144, 0x83261DC8)) { __imp__sub_83261DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC2C_G_, (int64_t)g_820E0000 - 32708, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261DC8, 0x83261DC8) { ctx.r3.u64 = n_sub_83261DC8(ctx, base); }

uint64_t n_sub_83261E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC30_G_ = int32_t(0x8349BC30);
	if (!UseLiftedCode(144, 0x83261E08)) { __imp__sub_83261E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC30_G_, (int64_t)g_820E0000 - 32692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261E08, 0x83261E08) { ctx.r3.u64 = n_sub_83261E08(ctx, base); }

uint64_t n_sub_83261E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC34_G_ = int32_t(0x8349BC34);
	if (!UseLiftedCode(144, 0x83261E48)) { __imp__sub_83261E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC34_G_, (int64_t)g_820E0000 - 32676, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261E48, 0x83261E48) { ctx.r3.u64 = n_sub_83261E48(ctx, base); }

uint64_t n_sub_83261E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC38_G_ = int32_t(0x8349BC38);
	if (!UseLiftedCode(144, 0x83261E88)) { __imp__sub_83261E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC38_G_, (int64_t)g_820E0000 - 32656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261E88, 0x83261E88) { ctx.r3.u64 = n_sub_83261E88(ctx, base); }

uint64_t n_sub_83261EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC3C_G_ = int32_t(0x8349BC3C);
	if (!UseLiftedCode(144, 0x83261EC8)) { __imp__sub_83261EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC3C_G_, (int64_t)g_820E0000 - 32640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261EC8, 0x83261EC8) { ctx.r3.u64 = n_sub_83261EC8(ctx, base); }

uint64_t n_sub_83261F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC40_G_ = int32_t(0x8349BC40);
	if (!UseLiftedCode(144, 0x83261F08)) { __imp__sub_83261F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC40_G_, (int64_t)g_820E0000 - 32616, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261F08, 0x83261F08) { ctx.r3.u64 = n_sub_83261F08(ctx, base); }

uint64_t n_sub_83261F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC44_G_ = int32_t(0x8349BC44);
	if (!UseLiftedCode(144, 0x83261F48)) { __imp__sub_83261F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC44_G_, (int64_t)g_820E0000 - 32596, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261F48, 0x83261F48) { ctx.r3.u64 = n_sub_83261F48(ctx, base); }

uint64_t n_sub_83261F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC48_G_ = int32_t(0x8349BC48);
	if (!UseLiftedCode(144, 0x83261F88)) { __imp__sub_83261F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC48_G_, (int64_t)g_820E0000 - 32568, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261F88, 0x83261F88) { ctx.r3.u64 = n_sub_83261F88(ctx, base); }

uint64_t n_sub_83261FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC4C_G_ = int32_t(0x8349BC4C);
	if (!UseLiftedCode(144, 0x83261FC8)) { __imp__sub_83261FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83261FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC4C_G_, (int64_t)g_820E0000 - 32548, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83261FC8, 0x83261FC8) { ctx.r3.u64 = n_sub_83261FC8(ctx, base); }

uint64_t n_sub_83262008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC50_G_ = int32_t(0x8349BC50);
	if (!UseLiftedCode(144, 0x83262008)) { __imp__sub_83262008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC50_G_, (int64_t)g_820E0000 - 32528, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262008, 0x83262008) { ctx.r3.u64 = n_sub_83262008(ctx, base); }

uint64_t n_sub_83262048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC54_G_ = int32_t(0x8349BC54);
	if (!UseLiftedCode(144, 0x83262048)) { __imp__sub_83262048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC54_G_, (int64_t)g_820E0000 - 32508, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262048, 0x83262048) { ctx.r3.u64 = n_sub_83262048(ctx, base); }

uint64_t n_sub_83262088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC58_G_ = int32_t(0x8349BC58);
	if (!UseLiftedCode(144, 0x83262088)) { __imp__sub_83262088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC58_G_, (int64_t)g_820E0000 - 32476, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262088, 0x83262088) { ctx.r3.u64 = n_sub_83262088(ctx, base); }

uint64_t n_sub_832620C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC5C_G_ = int32_t(0x8349BC5C);
	if (!UseLiftedCode(144, 0x832620C8)) { __imp__sub_832620C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832620C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC5C_G_, (int64_t)g_820E0000 - 32448, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832620C8, 0x832620C8) { ctx.r3.u64 = n_sub_832620C8(ctx, base); }

uint64_t n_sub_83262108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC60_G_ = int32_t(0x8349BC60);
	if (!UseLiftedCode(144, 0x83262108)) { __imp__sub_83262108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC60_G_, (int64_t)g_820E0000 - 32420, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262108, 0x83262108) { ctx.r3.u64 = n_sub_83262108(ctx, base); }

uint64_t n_sub_83262148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC64_G_ = int32_t(0x8349BC64);
	if (!UseLiftedCode(144, 0x83262148)) { __imp__sub_83262148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC64_G_, (int64_t)g_820E0000 - 32400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262148, 0x83262148) { ctx.r3.u64 = n_sub_83262148(ctx, base); }

uint64_t n_sub_83262188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC68_G_ = int32_t(0x8349BC68);
	if (!UseLiftedCode(144, 0x83262188)) { __imp__sub_83262188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC68_G_, (int64_t)g_820E0000 - 32372, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262188, 0x83262188) { ctx.r3.u64 = n_sub_83262188(ctx, base); }

uint64_t n_sub_832621C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC6C_G_ = int32_t(0x8349BC6C);
	if (!UseLiftedCode(144, 0x832621C8)) { __imp__sub_832621C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832621C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC6C_G_, (int64_t)g_820E0000 - 32336, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832621C8, 0x832621C8) { ctx.r3.u64 = n_sub_832621C8(ctx, base); }

uint64_t n_sub_83262208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC70_G_ = int32_t(0x8349BC70);
	if (!UseLiftedCode(144, 0x83262208)) { __imp__sub_83262208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC70_G_, (int64_t)g_820E0000 - 32316, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262208, 0x83262208) { ctx.r3.u64 = n_sub_83262208(ctx, base); }

uint64_t n_sub_83262248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC74_G_ = int32_t(0x8349BC74);
	if (!UseLiftedCode(144, 0x83262248)) { __imp__sub_83262248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC74_G_, (int64_t)g_820E0000 - 32288, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262248, 0x83262248) { ctx.r3.u64 = n_sub_83262248(ctx, base); }

uint64_t n_sub_83262288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC78_G_ = int32_t(0x8349BC78);
	if (!UseLiftedCode(144, 0x83262288)) { __imp__sub_83262288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC78_G_, (int64_t)g_820E0000 - 32272, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262288, 0x83262288) { ctx.r3.u64 = n_sub_83262288(ctx, base); }

uint64_t n_sub_832622C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC7C_G_ = int32_t(0x8349BC7C);
	if (!UseLiftedCode(144, 0x832622C8)) { __imp__sub_832622C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832622C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC7C_G_, (int64_t)g_820E0000 - 32260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832622C8, 0x832622C8) { ctx.r3.u64 = n_sub_832622C8(ctx, base); }

uint64_t n_sub_83262308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC80_G_ = int32_t(0x8349BC80);
	if (!UseLiftedCode(144, 0x83262308)) { __imp__sub_83262308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC80_G_, (int64_t)g_820E0000 - 32236, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262308, 0x83262308) { ctx.r3.u64 = n_sub_83262308(ctx, base); }

uint64_t n_sub_83262348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC84_G_ = int32_t(0x8349BC84);
	if (!UseLiftedCode(144, 0x83262348)) { __imp__sub_83262348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC84_G_, (int64_t)g_820E0000 - 32208, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262348, 0x83262348) { ctx.r3.u64 = n_sub_83262348(ctx, base); }

uint64_t n_sub_83262388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC88_G_ = int32_t(0x8349BC88);
	if (!UseLiftedCode(144, 0x83262388)) { __imp__sub_83262388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC88_G_, (int64_t)g_820E0000 - 32188, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262388, 0x83262388) { ctx.r3.u64 = n_sub_83262388(ctx, base); }

uint64_t n_sub_832623C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC8C_G_ = int32_t(0x8349BC8C);
	if (!UseLiftedCode(144, 0x832623C8)) { __imp__sub_832623C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832623C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC8C_G_, (int64_t)g_820E0000 - 32164, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832623C8, 0x832623C8) { ctx.r3.u64 = n_sub_832623C8(ctx, base); }

uint64_t n_sub_83262408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC90_G_ = int32_t(0x8349BC90);
	if (!UseLiftedCode(144, 0x83262408)) { __imp__sub_83262408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC90_G_, (int64_t)g_820E0000 - 32148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262408, 0x83262408) { ctx.r3.u64 = n_sub_83262408(ctx, base); }

uint64_t n_sub_83262448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BC94_G_ = int32_t(0x8349BC94);
	if (!UseLiftedCode(144, 0x83262448)) { __imp__sub_83262448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BC94_G_, (int64_t)g_820E0000 - 32128, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 26984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262448, 0x83262448) { ctx.r3.u64 = n_sub_83262448(ctx, base); }

uint64_t n_sub_83262568(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCA8_G_ = int32_t(0x8349BCA8);
	if (!UseLiftedCode(144, 0x83262568)) { __imp__sub_83262568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262568);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCA8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262568, 0x83262568) { ctx.r3.u64 = n_sub_83262568(ctx, base); }

uint64_t n_sub_832625A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCAC_G_ = int32_t(0x8349BCAC);
	if (!UseLiftedCode(144, 0x832625A8)) { __imp__sub_832625A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832625A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCAC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832625A8, 0x832625A8) { ctx.r3.u64 = n_sub_832625A8(ctx, base); }

uint64_t n_sub_832625E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCB0_G_ = int32_t(0x8349BCB0);
	if (!UseLiftedCode(144, 0x832625E8)) { __imp__sub_832625E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832625E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832625E8, 0x832625E8) { ctx.r3.u64 = n_sub_832625E8(ctx, base); }

uint64_t n_sub_83262628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCB4_G_ = int32_t(0x8349BCB4);
	if (!UseLiftedCode(144, 0x83262628)) { __imp__sub_83262628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262628, 0x83262628) { ctx.r3.u64 = n_sub_83262628(ctx, base); }

uint64_t n_sub_83262668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCB8_G_ = int32_t(0x8349BCB8);
	if (!UseLiftedCode(144, 0x83262668)) { __imp__sub_83262668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCB8_G_, (int64_t)str_TXT_820C0000_B_ + 2868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262668, 0x83262668) { ctx.r3.u64 = n_sub_83262668(ctx, base); }

uint64_t n_sub_832626A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCBC_G_ = int32_t(0x8349BCBC);
	if (!UseLiftedCode(144, 0x832626A8)) { __imp__sub_832626A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832626A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCBC_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832626A8, 0x832626A8) { ctx.r3.u64 = n_sub_832626A8(ctx, base); }

uint64_t n_sub_832626E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCC0_G_ = int32_t(0x8349BCC0);
	if (!UseLiftedCode(144, 0x832626E8)) { __imp__sub_832626E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832626E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC0_G_, (int64_t)g_820E0000 - 30800, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832626E8, 0x832626E8) { ctx.r3.u64 = n_sub_832626E8(ctx, base); }

uint64_t n_sub_83262728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCC4_G_ = int32_t(0x8349BCC4);
	if (!UseLiftedCode(144, 0x83262728)) { __imp__sub_83262728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262728);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC4_G_, (int64_t)g_820E0000 - 30780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262728, 0x83262728) { ctx.r3.u64 = n_sub_83262728(ctx, base); }

uint64_t n_sub_83262768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCC8_G_ = int32_t(0x8349BCC8);
	if (!UseLiftedCode(144, 0x83262768)) { __imp__sub_83262768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262768);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCC8_G_, (int64_t)g_820E0000 - 30744, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262768, 0x83262768) { ctx.r3.u64 = n_sub_83262768(ctx, base); }

uint64_t n_sub_832627A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCCC_G_ = int32_t(0x8349BCCC);
	if (!UseLiftedCode(144, 0x832627A8)) { __imp__sub_832627A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832627A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCCC_G_, (int64_t)g_820E0000 - 30716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832627A8, 0x832627A8) { ctx.r3.u64 = n_sub_832627A8(ctx, base); }

uint64_t n_sub_832627E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCD0_G_ = int32_t(0x8349BCD0);
	if (!UseLiftedCode(144, 0x832627E8)) { __imp__sub_832627E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832627E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCD0_G_, (int64_t)g_820E0000 - 30688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832627E8, 0x832627E8) { ctx.r3.u64 = n_sub_832627E8(ctx, base); }

uint64_t n_sub_83262828(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCD4_G_ = int32_t(0x8349BCD4);
	if (!UseLiftedCode(144, 0x83262828)) { __imp__sub_83262828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262828);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820D0000_B_;
	CCharString_ConstructFromCStr(ctx, base, (int64_t)TXT_8349BCD4_G_, (int64_t)str_TXT_820D0000_B_ + 25496, -1);
	ctx.r9.s64 = (int64_t)g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262828, 0x83262828) { ctx.r3.u64 = n_sub_83262828(ctx, base); }

uint64_t n_sub_83262868(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCD8_G_ = int32_t(0x8349BCD8);
	if (!UseLiftedCode(144, 0x83262868)) { __imp__sub_83262868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262868);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCD8_G_, (int64_t)g_820E0000 - 30656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262868, 0x83262868) { ctx.r3.u64 = n_sub_83262868(ctx, base); }

uint64_t n_sub_832628A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCDC_G_ = int32_t(0x8349BCDC);
	if (!UseLiftedCode(144, 0x832628A8)) { __imp__sub_832628A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832628A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCDC_G_, (int64_t)g_820E0000 - 30624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832628A8, 0x832628A8) { ctx.r3.u64 = n_sub_832628A8(ctx, base); }

uint64_t n_sub_832628E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCE0_G_ = int32_t(0x8349BCE0);
	if (!UseLiftedCode(144, 0x832628E8)) { __imp__sub_832628E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832628E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE0_G_, (int64_t)g_820E0000 - 30296, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832628E8, 0x832628E8) { ctx.r3.u64 = n_sub_832628E8(ctx, base); }

uint64_t n_sub_83262928(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCE4_G_ = int32_t(0x8349BCE4);
	if (!UseLiftedCode(144, 0x83262928)) { __imp__sub_83262928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262928);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262928, 0x83262928) { ctx.r3.u64 = n_sub_83262928(ctx, base); }

uint64_t n_sub_83262968(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCE8_G_ = int32_t(0x8349BCE8);
	if (!UseLiftedCode(144, 0x83262968)) { __imp__sub_83262968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262968);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCE8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262968, 0x83262968) { ctx.r3.u64 = n_sub_83262968(ctx, base); }

uint64_t n_sub_832629A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCEC_G_ = int32_t(0x8349BCEC);
	if (!UseLiftedCode(144, 0x832629A8)) { __imp__sub_832629A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832629A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCEC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832629A8, 0x832629A8) { ctx.r3.u64 = n_sub_832629A8(ctx, base); }

uint64_t n_sub_832629E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BCF0_G_ = int32_t(0x8349BCF0);
	if (!UseLiftedCode(144, 0x832629E8)) { __imp__sub_832629E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832629E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BCF0_G_, (int64_t)g_820E0000 - 29540, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832629E8, 0x832629E8) { ctx.r3.u64 = n_sub_832629E8(ctx, base); }

uint64_t n_sub_83262A60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD20_G_ = int32_t(0x8349BD20);
	if (!UseLiftedCode(144, 0x83262A60)) { __imp__sub_83262A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262A60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD20_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262A60, 0x83262A60) { ctx.r3.u64 = n_sub_83262A60(ctx, base); }

uint64_t n_sub_83262AA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD24_G_ = int32_t(0x8349BD24);
	if (!UseLiftedCode(144, 0x83262AA0)) { __imp__sub_83262AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262AA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD24_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262AA0, 0x83262AA0) { ctx.r3.u64 = n_sub_83262AA0(ctx, base); }

uint64_t n_sub_83262AE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD28_G_ = int32_t(0x8349BD28);
	if (!UseLiftedCode(144, 0x83262AE0)) { __imp__sub_83262AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262AE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD28_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262AE0, 0x83262AE0) { ctx.r3.u64 = n_sub_83262AE0(ctx, base); }

uint64_t n_sub_83262B20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD40_G_ = int32_t(0x8349BD40);
	if (!UseLiftedCode(144, 0x83262B20)) { __imp__sub_83262B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262B20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD40_G_, (int64_t)g_82000000 + 3608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262B20, 0x83262B20) { ctx.r3.u64 = n_sub_83262B20(ctx, base); }

uint64_t n_sub_83262B60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD44_G_ = int32_t(0x8349BD44);
	if (!UseLiftedCode(144, 0x83262B60)) { __imp__sub_83262B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262B60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD44_G_, (int64_t)str_TXT_820B0000_B_ + 11996, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262B60, 0x83262B60) { ctx.r3.u64 = n_sub_83262B60(ctx, base); }

uint64_t n_sub_83262C00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD50_G_ = int32_t(0x8349BD50);
	if (!UseLiftedCode(144, 0x83262C00)) { __imp__sub_83262C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD50_G_, (int64_t)g_820E0000 - 24860, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262C00, 0x83262C00) { ctx.r3.u64 = n_sub_83262C00(ctx, base); }

uint64_t n_sub_83262C40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD54_G_ = int32_t(0x8349BD54);
	if (!UseLiftedCode(144, 0x83262C40)) { __imp__sub_83262C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD54_G_, (int64_t)g_820E0000 - 24832, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262C40, 0x83262C40) { ctx.r3.u64 = n_sub_83262C40(ctx, base); }

uint64_t n_sub_83262C80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD58_G_ = int32_t(0x8349BD58);
	if (!UseLiftedCode(144, 0x83262C80)) { __imp__sub_83262C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262C80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD58_G_, (int64_t)str_TXT_820B0000_B_ - 544, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262C80, 0x83262C80) { ctx.r3.u64 = n_sub_83262C80(ctx, base); }

uint64_t n_sub_83262CC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD5C_G_ = int32_t(0x8349BD5C);
	if (!UseLiftedCode(144, 0x83262CC0)) { __imp__sub_83262CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262CC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD5C_G_, (int64_t)g_820E0000 - 24412, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262CC0, 0x83262CC0) { ctx.r3.u64 = n_sub_83262CC0(ctx, base); }

uint64_t n_sub_83262D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD60_G_ = int32_t(0x8349BD60);
	if (!UseLiftedCode(144, 0x83262D00)) { __imp__sub_83262D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262D00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD60_G_, (int64_t)g_820E0000 - 24400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262D00, 0x83262D00) { ctx.r3.u64 = n_sub_83262D00(ctx, base); }

uint64_t n_sub_83262D40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD64_G_ = int32_t(0x8349BD64);
	if (!UseLiftedCode(144, 0x83262D40)) { __imp__sub_83262D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262D40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD64_G_, (int64_t)g_820E0000 - 24392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262D40, 0x83262D40) { ctx.r3.u64 = n_sub_83262D40(ctx, base); }

uint64_t n_sub_83262F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD84_G_ = int32_t(0x8349BD84);
	if (!UseLiftedCode(144, 0x83262F38)) { __imp__sub_83262F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD84_G_, (int64_t)str_TXT_820C0000_B_ - 5688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262F38, 0x83262F38) { ctx.r3.u64 = n_sub_83262F38(ctx, base); }

uint64_t n_sub_83262F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD88_G_ = int32_t(0x8349BD88);
	if (!UseLiftedCode(144, 0x83262F78)) { __imp__sub_83262F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD88_G_, (int64_t)g_820E0000 - 22608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262F78, 0x83262F78) { ctx.r3.u64 = n_sub_83262F78(ctx, base); }

uint64_t n_sub_83262FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD8C_G_ = int32_t(0x8349BD8C);
	if (!UseLiftedCode(144, 0x83262FB8)) { __imp__sub_83262FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD8C_G_, (int64_t)g_820E0000 - 22584, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262FB8, 0x83262FB8) { ctx.r3.u64 = n_sub_83262FB8(ctx, base); }

uint64_t n_sub_83262FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD90_G_ = int32_t(0x8349BD90);
	if (!UseLiftedCode(144, 0x83262FF8)) { __imp__sub_83262FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83262FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD90_G_, (int64_t)g_820E0000 - 22560, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83262FF8, 0x83262FF8) { ctx.r3.u64 = n_sub_83262FF8(ctx, base); }

uint64_t n_sub_83263038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD94_G_ = int32_t(0x8349BD94);
	if (!UseLiftedCode(144, 0x83263038)) { __imp__sub_83263038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD94_G_, (int64_t)g_820E0000 - 22544, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263038, 0x83263038) { ctx.r3.u64 = n_sub_83263038(ctx, base); }

uint64_t n_sub_83263078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD98_G_ = int32_t(0x8349BD98);
	if (!UseLiftedCode(144, 0x83263078)) { __imp__sub_83263078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD98_G_, (int64_t)g_820E0000 - 22516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263078, 0x83263078) { ctx.r3.u64 = n_sub_83263078(ctx, base); }

uint64_t n_sub_832630B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BD9C_G_ = int32_t(0x8349BD9C);
	if (!UseLiftedCode(144, 0x832630B8)) { __imp__sub_832630B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832630B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BD9C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832630B8, 0x832630B8) { ctx.r3.u64 = n_sub_832630B8(ctx, base); }

uint64_t n_sub_832630F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDA0_G_ = int32_t(0x8349BDA0);
	if (!UseLiftedCode(144, 0x832630F8)) { __imp__sub_832630F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832630F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832630F8, 0x832630F8) { ctx.r3.u64 = n_sub_832630F8(ctx, base); }

uint64_t n_sub_83263138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDA4_G_ = int32_t(0x8349BDA4);
	if (!UseLiftedCode(144, 0x83263138)) { __imp__sub_83263138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263138, 0x83263138) { ctx.r3.u64 = n_sub_83263138(ctx, base); }

uint64_t n_sub_83263178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDA8_G_ = int32_t(0x8349BDA8);
	if (!UseLiftedCode(144, 0x83263178)) { __imp__sub_83263178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDA8_G_, (int64_t)g_820E0000 - 22376, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263178, 0x83263178) { ctx.r3.u64 = n_sub_83263178(ctx, base); }

uint64_t n_sub_832631B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDAC_G_ = int32_t(0x8349BDAC);
	if (!UseLiftedCode(144, 0x832631B8)) { __imp__sub_832631B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832631B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDAC_G_, (int64_t)g_820E0000 - 22352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832631B8, 0x832631B8) { ctx.r3.u64 = n_sub_832631B8(ctx, base); }

uint64_t n_sub_832631F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDB0_G_ = int32_t(0x8349BDB0);
	if (!UseLiftedCode(144, 0x832631F8)) { __imp__sub_832631F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832631F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB0_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832631F8, 0x832631F8) { ctx.r3.u64 = n_sub_832631F8(ctx, base); }

uint64_t n_sub_83263238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDB4_G_ = int32_t(0x8349BDB4);
	if (!UseLiftedCode(144, 0x83263238)) { __imp__sub_83263238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB4_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263238, 0x83263238) { ctx.r3.u64 = n_sub_83263238(ctx, base); }

uint64_t n_sub_83263278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDB8_G_ = int32_t(0x8349BDB8);
	if (!UseLiftedCode(144, 0x83263278)) { __imp__sub_83263278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDB8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263278, 0x83263278) { ctx.r3.u64 = n_sub_83263278(ctx, base); }

uint64_t n_sub_832632B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDBC_G_ = int32_t(0x8349BDBC);
	if (!UseLiftedCode(144, 0x832632B8)) { __imp__sub_832632B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832632B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDBC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832632B8, 0x832632B8) { ctx.r3.u64 = n_sub_832632B8(ctx, base); }

uint64_t n_sub_832632F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDC0_G_ = int32_t(0x8349BDC0);
	if (!UseLiftedCode(144, 0x832632F8)) { __imp__sub_832632F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832632F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832632F8, 0x832632F8) { ctx.r3.u64 = n_sub_832632F8(ctx, base); }

uint64_t n_sub_83263338(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDC4_G_ = int32_t(0x8349BDC4);
	if (!UseLiftedCode(144, 0x83263338)) { __imp__sub_83263338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263338);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC4_G_, (int64_t)g_820E0000 - 18672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263338, 0x83263338) { ctx.r3.u64 = n_sub_83263338(ctx, base); }

uint64_t n_sub_83263378(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDC8_G_ = int32_t(0x8349BDC8);
	if (!UseLiftedCode(144, 0x83263378)) { __imp__sub_83263378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263378);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDC8_G_, (int64_t)g_820E0000 - 18656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263378, 0x83263378) { ctx.r3.u64 = n_sub_83263378(ctx, base); }

uint64_t n_sub_832633B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDCC_G_ = int32_t(0x8349BDCC);
	if (!UseLiftedCode(144, 0x832633B8)) { __imp__sub_832633B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832633B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDCC_G_, (int64_t)g_820E0000 - 18628, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832633B8, 0x832633B8) { ctx.r3.u64 = n_sub_832633B8(ctx, base); }

uint64_t n_sub_832633F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDD0_G_ = int32_t(0x8349BDD0);
	if (!UseLiftedCode(144, 0x832633F8)) { __imp__sub_832633F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832633F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD0_G_, (int64_t)g_820E0000 - 18604, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832633F8, 0x832633F8) { ctx.r3.u64 = n_sub_832633F8(ctx, base); }

uint64_t n_sub_83263438(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDD4_G_ = int32_t(0x8349BDD4);
	if (!UseLiftedCode(144, 0x83263438)) { __imp__sub_83263438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263438);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD4_G_, (int64_t)g_820E0000 - 18576, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263438, 0x83263438) { ctx.r3.u64 = n_sub_83263438(ctx, base); }

uint64_t n_sub_83263478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDD8_G_ = int32_t(0x8349BDD8);
	if (!UseLiftedCode(144, 0x83263478)) { __imp__sub_83263478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDD8_G_, (int64_t)str_TXT_820C0000_B_ - 11852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263478, 0x83263478) { ctx.r3.u64 = n_sub_83263478(ctx, base); }

uint64_t n_sub_832634B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDDC_G_ = int32_t(0x8349BDDC);
	if (!UseLiftedCode(144, 0x832634B8)) { __imp__sub_832634B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832634B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDDC_G_, (int64_t)g_820E0000 - 18552, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832634B8, 0x832634B8) { ctx.r3.u64 = n_sub_832634B8(ctx, base); }

uint64_t n_sub_832634F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BDE0_G_ = int32_t(0x8349BDE0);
	if (!UseLiftedCode(144, 0x832634F8)) { __imp__sub_832634F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832634F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BDE0_G_, (int64_t)str_TXT_820C0000_B_ - 11812, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832634F8, 0x832634F8) { ctx.r3.u64 = n_sub_832634F8(ctx, base); }

uint64_t n_sub_832639D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE38_G_ = int32_t(0x8349BE38);
	if (!UseLiftedCode(144, 0x832639D0)) { __imp__sub_832639D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832639D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE38_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 27992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832639D0, 0x832639D0) { ctx.r3.u64 = n_sub_832639D0(ctx, base); }

uint64_t n_sub_83263A10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE3C_G_ = int32_t(0x8349BE3C);
	if (!UseLiftedCode(144, 0x83263A10)) { __imp__sub_83263A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE3C_G_, (int64_t)g_820E0000 - 18512, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 28008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263A10, 0x83263A10) { ctx.r3.u64 = n_sub_83263A10(ctx, base); }

uint64_t n_sub_83263A50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE40_G_ = int32_t(0x8349BE40);
	if (!UseLiftedCode(144, 0x83263A50)) { __imp__sub_83263A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE40_G_, (int64_t)g_820E0000 - 18456, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 28024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263A50, 0x83263A50) { ctx.r3.u64 = n_sub_83263A50(ctx, base); }

uint64_t n_sub_83263A90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE44_G_ = int32_t(0x8349BE44);
	if (!UseLiftedCode(144, 0x83263A90)) { __imp__sub_83263A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263A90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE44_G_, (int64_t)g_820E0000 - 18392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 28040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263A90, 0x83263A90) { ctx.r3.u64 = n_sub_83263A90(ctx, base); }

uint64_t n_sub_83263AD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE48_G_ = int32_t(0x8349BE48);
	if (!UseLiftedCode(144, 0x83263AD0)) { __imp__sub_83263AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263AD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE48_G_, (int64_t)g_820E0000 - 18336, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 28056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263AD0, 0x83263AD0) { ctx.r3.u64 = n_sub_83263AD0(ctx, base); }

uint64_t n_sub_83263B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349BE4C_G_ = int32_t(0x8349BE4C);
	if (!UseLiftedCode(144, 0x83263B10)) { __imp__sub_83263B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83263B10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349BE4C_G_, (int64_t)g_820E0000 - 18280, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 28072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83263B10, 0x83263B10) { ctx.r3.u64 = n_sub_83263B10(ctx, base); }

uint64_t n_sub_832645B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(144, 0x832645B0)) { ctx.r8.u64 = arg1; __imp__sub_832645B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645B0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29240, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_832645B0, 0x832645B0) { ctx.r3.u64 = n_sub_832645B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832645C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(144, 0x832645C0)) { ctx.r8.u64 = arg1; __imp__sub_832645C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645C0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29344, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_832645C0, 0x832645C0) { ctx.r3.u64 = n_sub_832645C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832645D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C004_G_ = int32_t(0x8349C004);
	if (!UseLiftedCode(144, 0x832645D0)) { __imp__sub_832645D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832645D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C004_G_, (int64_t)g_820E0000 - 12876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832645D0, 0x832645D0) { ctx.r3.u64 = n_sub_832645D0(ctx, base); }

uint64_t n_sub_83264610(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C008_G_ = int32_t(0x8349C008);
	if (!UseLiftedCode(144, 0x83264610)) { __imp__sub_83264610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264610);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C008_G_, (int64_t)g_820E0000 - 12876, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264610, 0x83264610) { ctx.r3.u64 = n_sub_83264610(ctx, base); }

uint64_t n_sub_83264650(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C00C_G_ = int32_t(0x8349C00C);
	if (!UseLiftedCode(144, 0x83264650)) { __imp__sub_83264650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264650);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C00C_G_, (int64_t)g_820E0000 - 12864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264650, 0x83264650) { ctx.r3.u64 = n_sub_83264650(ctx, base); }

uint64_t n_sub_83264690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C010_G_ = int32_t(0x8349C010);
	if (!UseLiftedCode(144, 0x83264690)) { __imp__sub_83264690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C010_G_, (int64_t)g_820E0000 - 12856, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264690, 0x83264690) { ctx.r3.u64 = n_sub_83264690(ctx, base); }

uint64_t n_sub_832646D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C014_G_ = int32_t(0x8349C014);
	if (!UseLiftedCode(144, 0x832646D0)) { __imp__sub_832646D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832646D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C014_G_, (int64_t)g_820E0000 - 12848, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832646D0, 0x832646D0) { ctx.r3.u64 = n_sub_832646D0(ctx, base); }

uint64_t n_sub_83264710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C018_G_ = int32_t(0x8349C018);
	if (!UseLiftedCode(144, 0x83264710)) { __imp__sub_83264710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C018_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264710, 0x83264710) { ctx.r3.u64 = n_sub_83264710(ctx, base); }

uint64_t n_sub_83264750(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C01C_G_ = int32_t(0x8349C01C);
	if (!UseLiftedCode(144, 0x83264750)) { __imp__sub_83264750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C01C_G_, (int64_t)g_820E0000 - 12816, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264750, 0x83264750) { ctx.r3.u64 = n_sub_83264750(ctx, base); }

uint64_t n_sub_83264790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C020_G_ = int32_t(0x8349C020);
	if (!UseLiftedCode(144, 0x83264790)) { __imp__sub_83264790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C020_G_, (int64_t)g_820E0000 - 12804, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264790, 0x83264790) { ctx.r3.u64 = n_sub_83264790(ctx, base); }

uint64_t n_sub_832647D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C024_G_ = int32_t(0x8349C024);
	if (!UseLiftedCode(144, 0x832647D0)) { __imp__sub_832647D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832647D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C024_G_, (int64_t)g_820E0000 - 12792, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832647D0, 0x832647D0) { ctx.r3.u64 = n_sub_832647D0(ctx, base); }

uint64_t n_sub_83264810(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C028_G_ = int32_t(0x8349C028);
	if (!UseLiftedCode(144, 0x83264810)) { __imp__sub_83264810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264810);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C028_G_, (int64_t)g_820E0000 - 12776, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264810, 0x83264810) { ctx.r3.u64 = n_sub_83264810(ctx, base); }

uint64_t n_sub_83264850(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C02C_G_ = int32_t(0x8349C02C);
	if (!UseLiftedCode(144, 0x83264850)) { __imp__sub_83264850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264850);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C02C_G_, (int64_t)g_820E0000 - 12764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264850, 0x83264850) { ctx.r3.u64 = n_sub_83264850(ctx, base); }

uint64_t n_sub_83264890(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C030_G_ = int32_t(0x8349C030);
	if (!UseLiftedCode(144, 0x83264890)) { __imp__sub_83264890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C030_G_, (int64_t)g_820E0000 - 12752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264890, 0x83264890) { ctx.r3.u64 = n_sub_83264890(ctx, base); }

uint64_t n_sub_832648D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C034_G_ = int32_t(0x8349C034);
	if (!UseLiftedCode(144, 0x832648D0)) { __imp__sub_832648D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832648D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C034_G_, (int64_t)g_820E0000 - 12732, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832648D0, 0x832648D0) { ctx.r3.u64 = n_sub_832648D0(ctx, base); }

uint64_t n_sub_83264910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C038_G_ = int32_t(0x8349C038);
	if (!UseLiftedCode(144, 0x83264910)) { __imp__sub_83264910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C038_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264910, 0x83264910) { ctx.r3.u64 = n_sub_83264910(ctx, base); }

uint64_t n_sub_83264950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C03C_G_ = int32_t(0x8349C03C);
	if (!UseLiftedCode(144, 0x83264950)) { __imp__sub_83264950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C03C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264950, 0x83264950) { ctx.r3.u64 = n_sub_83264950(ctx, base); }

uint64_t n_sub_83264990(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C040_G_ = int32_t(0x8349C040);
	if (!UseLiftedCode(144, 0x83264990)) { __imp__sub_83264990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264990);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C040_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264990, 0x83264990) { ctx.r3.u64 = n_sub_83264990(ctx, base); }

uint64_t n_sub_832649D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C044_G_ = int32_t(0x8349C044);
	if (!UseLiftedCode(144, 0x832649D0)) { __imp__sub_832649D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832649D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C044_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832649D0, 0x832649D0) { ctx.r3.u64 = n_sub_832649D0(ctx, base); }

uint64_t n_sub_83264A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C04C_G_ = int32_t(0x8349C04C);
	if (!UseLiftedCode(144, 0x83264A48)) { __imp__sub_83264A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C04C_G_, (int64_t)g_820E0000 - 12496, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264A48, 0x83264A48) { ctx.r3.u64 = n_sub_83264A48(ctx, base); }

uint64_t n_sub_83264A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C050_G_ = int32_t(0x8349C050);
	if (!UseLiftedCode(144, 0x83264A88)) { __imp__sub_83264A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C050_G_, (int64_t)str_TXT_820B0000_B_ + 17764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264A88, 0x83264A88) { ctx.r3.u64 = n_sub_83264A88(ctx, base); }

uint64_t n_sub_83264AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C054_G_ = int32_t(0x8349C054);
	if (!UseLiftedCode(144, 0x83264AC8)) { __imp__sub_83264AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C054_G_, (int64_t)str_TXT_820B0000_B_ + 1468, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264AC8, 0x83264AC8) { ctx.r3.u64 = n_sub_83264AC8(ctx, base); }

uint64_t n_sub_83264B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C058_G_ = int32_t(0x8349C058);
	if (!UseLiftedCode(144, 0x83264B08)) { __imp__sub_83264B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C058_G_, (int64_t)str_TXT_820B0000_B_ + 1472, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264B08, 0x83264B08) { ctx.r3.u64 = n_sub_83264B08(ctx, base); }

uint64_t n_sub_83264B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C05C_G_ = int32_t(0x8349C05C);
	if (!UseLiftedCode(144, 0x83264B48)) { __imp__sub_83264B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C05C_G_, (int64_t)str_TXT_820B0000_B_ - 28016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264B48, 0x83264B48) { ctx.r3.u64 = n_sub_83264B48(ctx, base); }

uint64_t n_sub_83264B88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C060_G_ = int32_t(0x8349C060);
	if (!UseLiftedCode(144, 0x83264B88)) { __imp__sub_83264B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264B88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C060_G_, (int64_t)str_TXT_820B0000_B_ + 1480, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264B88, 0x83264B88) { ctx.r3.u64 = n_sub_83264B88(ctx, base); }

uint64_t n_sub_83264BC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C064_G_ = int32_t(0x8349C064);
	if (!UseLiftedCode(144, 0x83264BC8)) { __imp__sub_83264BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264BC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C064_G_, (int64_t)str_TXT_820B0000_B_ + 1492, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264BC8, 0x83264BC8) { ctx.r3.u64 = n_sub_83264BC8(ctx, base); }

uint64_t n_sub_83264C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C068_G_ = int32_t(0x8349C068);
	if (!UseLiftedCode(144, 0x83264C08)) { __imp__sub_83264C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C068_G_, (int64_t)str_TXT_820B0000_B_ + 1504, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264C08, 0x83264C08) { ctx.r3.u64 = n_sub_83264C08(ctx, base); }

uint64_t n_sub_83264C48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C06C_G_ = int32_t(0x8349C06C);
	if (!UseLiftedCode(144, 0x83264C48)) { __imp__sub_83264C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C06C_G_, (int64_t)g_820E0000 - 12488, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264C48, 0x83264C48) { ctx.r3.u64 = n_sub_83264C48(ctx, base); }

uint64_t n_sub_83264C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C070_G_ = int32_t(0x8349C070);
	if (!UseLiftedCode(144, 0x83264C88)) { __imp__sub_83264C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C070_G_, (int64_t)g_820E0000 - 12452, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264C88, 0x83264C88) { ctx.r3.u64 = n_sub_83264C88(ctx, base); }

uint64_t n_sub_83264CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C074_G_ = int32_t(0x8349C074);
	if (!UseLiftedCode(144, 0x83264CC8)) { __imp__sub_83264CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C074_G_, (int64_t)g_820E0000 - 11968, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 29880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264CC8, 0x83264CC8) { ctx.r3.u64 = n_sub_83264CC8(ctx, base); }

uint64_t n_sub_83264D68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C084_G_ = int32_t(0x8349C084);
	if (!UseLiftedCode(144, 0x83264D68)) { __imp__sub_83264D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264D68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C084_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264D68, 0x83264D68) { ctx.r3.u64 = n_sub_83264D68(ctx, base); }

uint64_t n_sub_83264DA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C088_G_ = int32_t(0x8349C088);
	if (!UseLiftedCode(144, 0x83264DA8)) { __imp__sub_83264DA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264DA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C088_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264DA8, 0x83264DA8) { ctx.r3.u64 = n_sub_83264DA8(ctx, base); }

uint64_t n_sub_83264DE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C08C_G_ = int32_t(0x8349C08C);
	if (!UseLiftedCode(144, 0x83264DE8)) { __imp__sub_83264DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264DE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C08C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264DE8, 0x83264DE8) { ctx.r3.u64 = n_sub_83264DE8(ctx, base); }

uint64_t n_sub_83264E28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C090_G_ = int32_t(0x8349C090);
	if (!UseLiftedCode(144, 0x83264E28)) { __imp__sub_83264E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83264E28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C090_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83264E28, 0x83264E28) { ctx.r3.u64 = n_sub_83264E28(ctx, base); }

uint64_t n_sub_83265300(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C0E8_G_ = int32_t(0x8349C0E8);
	if (!UseLiftedCode(144, 0x83265300)) { __imp__sub_83265300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265300);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0E8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265300, 0x83265300) { ctx.r3.u64 = n_sub_83265300(ctx, base); }

uint64_t n_sub_83265340(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C0EC_G_ = int32_t(0x8349C0EC);
	if (!UseLiftedCode(144, 0x83265340)) { __imp__sub_83265340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265340);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0EC_G_, (int64_t)g_820E0000 - 11680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265340, 0x83265340) { ctx.r3.u64 = n_sub_83265340(ctx, base); }

uint64_t n_sub_83265380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C0F0_G_ = int32_t(0x8349C0F0);
	if (!UseLiftedCode(144, 0x83265380)) { __imp__sub_83265380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265380);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C0F0_G_, (int64_t)g_820E0000 - 11660, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265380, 0x83265380) { ctx.r3.u64 = n_sub_83265380(ctx, base); }

uint64_t n_sub_832655F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C11C_G_ = int32_t(0x8349C11C);
	if (!UseLiftedCode(144, 0x832655F0)) { __imp__sub_832655F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832655F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C11C_G_, (int64_t)str_TXT_820B0000_B_ + 8956, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832655F0, 0x832655F0) { ctx.r3.u64 = n_sub_832655F0(ctx, base); }

uint64_t n_sub_83265630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C120_G_ = int32_t(0x8349C120);
	if (!UseLiftedCode(144, 0x83265630)) { __imp__sub_83265630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C120_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265630, 0x83265630) { ctx.r3.u64 = n_sub_83265630(ctx, base); }

uint64_t n_sub_83265670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C124_G_ = int32_t(0x8349C124);
	if (!UseLiftedCode(144, 0x83265670)) { __imp__sub_83265670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C124_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265670, 0x83265670) { ctx.r3.u64 = n_sub_83265670(ctx, base); }

uint64_t n_sub_832656B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C128_G_ = int32_t(0x8349C128);
	if (!UseLiftedCode(144, 0x832656B0)) { __imp__sub_832656B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832656B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C128_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832656B0, 0x832656B0) { ctx.r3.u64 = n_sub_832656B0(ctx, base); }

uint64_t n_sub_832656F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C12C_G_ = int32_t(0x8349C12C);
	if (!UseLiftedCode(144, 0x832656F0)) { __imp__sub_832656F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832656F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C12C_G_, (int64_t)g_820E0000 - 2016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832656F0, 0x832656F0) { ctx.r3.u64 = n_sub_832656F0(ctx, base); }

uint64_t n_sub_83265730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C130_G_ = int32_t(0x8349C130);
	if (!UseLiftedCode(144, 0x83265730)) { __imp__sub_83265730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C130_G_, (int64_t)g_820E0000 - 2004, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265730, 0x83265730) { ctx.r3.u64 = n_sub_83265730(ctx, base); }

uint64_t n_sub_83265770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C134_G_ = int32_t(0x8349C134);
	if (!UseLiftedCode(144, 0x83265770)) { __imp__sub_83265770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C134_G_, (int64_t)g_820E0000 - 1992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265770, 0x83265770) { ctx.r3.u64 = n_sub_83265770(ctx, base); }

uint64_t n_sub_832657B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C138_G_ = int32_t(0x8349C138);
	if (!UseLiftedCode(144, 0x832657B0)) { __imp__sub_832657B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832657B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C138_G_, (int64_t)g_820E0000 - 1980, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832657B0, 0x832657B0) { ctx.r3.u64 = n_sub_832657B0(ctx, base); }

uint64_t n_sub_832657F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C13C_G_ = int32_t(0x8349C13C);
	if (!UseLiftedCode(144, 0x832657F0)) { __imp__sub_832657F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832657F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C13C_G_, (int64_t)g_820E0000 - 1964, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832657F0, 0x832657F0) { ctx.r3.u64 = n_sub_832657F0(ctx, base); }

uint64_t n_sub_83265830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C140_G_ = int32_t(0x8349C140);
	if (!UseLiftedCode(144, 0x83265830)) { __imp__sub_83265830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C140_G_, (int64_t)g_820E0000 - 2016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265830, 0x83265830) { ctx.r3.u64 = n_sub_83265830(ctx, base); }

uint64_t n_sub_83265870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C144_G_ = int32_t(0x8349C144);
	if (!UseLiftedCode(144, 0x83265870)) { __imp__sub_83265870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83265870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C144_G_, (int64_t)g_820E0000 - 1992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83265870, 0x83265870) { ctx.r3.u64 = n_sub_83265870(ctx, base); }

uint64_t n_sub_83266008(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(144, 0x83266008)) { ctx.r8.u64 = arg1; __imp__sub_83266008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266008);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30384, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_83266008, 0x83266008) { ctx.r3.u64 = n_sub_83266008(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832664B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C258_G_ = int32_t(0x8349C258);
	if (!UseLiftedCode(144, 0x832664B0)) { __imp__sub_832664B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832664B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C258_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832664B0, 0x832664B0) { ctx.r3.u64 = n_sub_832664B0(ctx, base); }

uint64_t n_sub_832664F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C25C_G_ = int32_t(0x8349C25C);
	if (!UseLiftedCode(144, 0x832664F0)) { __imp__sub_832664F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832664F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C25C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832664F0, 0x832664F0) { ctx.r3.u64 = n_sub_832664F0(ctx, base); }

uint64_t n_sub_83266530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C260_G_ = int32_t(0x8349C260);
	if (!UseLiftedCode(144, 0x83266530)) { __imp__sub_83266530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266530);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C260_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266530, 0x83266530) { ctx.r3.u64 = n_sub_83266530(ctx, base); }

uint64_t n_sub_83266570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C264_G_ = int32_t(0x8349C264);
	if (!UseLiftedCode(144, 0x83266570)) { __imp__sub_83266570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266570);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C264_G_, (int64_t)str_TXT_820B0000_B_ - 28788, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266570, 0x83266570) { ctx.r3.u64 = n_sub_83266570(ctx, base); }

uint64_t n_sub_832665B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C268_G_ = int32_t(0x8349C268);
	if (!UseLiftedCode(144, 0x832665B0)) { __imp__sub_832665B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832665B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C268_G_, (int64_t)str_TXT_820B0000_B_ - 28780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832665B0, 0x832665B0) { ctx.r3.u64 = n_sub_832665B0(ctx, base); }

uint64_t n_sub_832665F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C26C_G_ = int32_t(0x8349C26C);
	if (!UseLiftedCode(144, 0x832665F0)) { __imp__sub_832665F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832665F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C26C_G_, (int64_t)str_TXT_820B0000_B_ - 28772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832665F0, 0x832665F0) { ctx.r3.u64 = n_sub_832665F0(ctx, base); }

uint64_t n_sub_83266630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C270_G_ = int32_t(0x8349C270);
	if (!UseLiftedCode(144, 0x83266630)) { __imp__sub_83266630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C270_G_, (int64_t)str_TXT_820B0000_B_ - 28760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266630, 0x83266630) { ctx.r3.u64 = n_sub_83266630(ctx, base); }

uint64_t n_sub_83266670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C274_G_ = int32_t(0x8349C274);
	if (!UseLiftedCode(144, 0x83266670)) { __imp__sub_83266670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C274_G_, (int64_t)str_TXT_820B0000_B_ - 28752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266670, 0x83266670) { ctx.r3.u64 = n_sub_83266670(ctx, base); }

uint64_t n_sub_832666B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C278_G_ = int32_t(0x8349C278);
	if (!UseLiftedCode(144, 0x832666B0)) { __imp__sub_832666B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832666B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C278_G_, (int64_t)str_TXT_820B0000_B_ - 28740, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832666B0, 0x832666B0) { ctx.r3.u64 = n_sub_832666B0(ctx, base); }

uint64_t n_sub_832666F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C27C_G_ = int32_t(0x8349C27C);
	if (!UseLiftedCode(144, 0x832666F0)) { __imp__sub_832666F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832666F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C27C_G_, (int64_t)str_TXT_820B0000_B_ - 28724, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832666F0, 0x832666F0) { ctx.r3.u64 = n_sub_832666F0(ctx, base); }

uint64_t n_sub_83266730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C280_G_ = int32_t(0x8349C280);
	if (!UseLiftedCode(144, 0x83266730)) { __imp__sub_83266730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C280_G_, (int64_t)str_TXT_820B0000_B_ - 28716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266730, 0x83266730) { ctx.r3.u64 = n_sub_83266730(ctx, base); }

uint64_t n_sub_83266770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C284_G_ = int32_t(0x8349C284);
	if (!UseLiftedCode(144, 0x83266770)) { __imp__sub_83266770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C284_G_, (int64_t)str_TXT_820B0000_B_ - 28700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266770, 0x83266770) { ctx.r3.u64 = n_sub_83266770(ctx, base); }

uint64_t n_sub_832667B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C288_G_ = int32_t(0x8349C288);
	if (!UseLiftedCode(144, 0x832667B0)) { __imp__sub_832667B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832667B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C288_G_, (int64_t)str_TXT_820B0000_B_ - 28692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832667B0, 0x832667B0) { ctx.r3.u64 = n_sub_832667B0(ctx, base); }

uint64_t n_sub_832667F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C28C_G_ = int32_t(0x8349C28C);
	if (!UseLiftedCode(144, 0x832667F0)) { __imp__sub_832667F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832667F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C28C_G_, (int64_t)str_TXT_820B0000_B_ - 28684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832667F0, 0x832667F0) { ctx.r3.u64 = n_sub_832667F0(ctx, base); }

uint64_t n_sub_83266830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C290_G_ = int32_t(0x8349C290);
	if (!UseLiftedCode(144, 0x83266830)) { __imp__sub_83266830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C290_G_, (int64_t)str_TXT_820B0000_B_ - 28672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266830, 0x83266830) { ctx.r3.u64 = n_sub_83266830(ctx, base); }

uint64_t n_sub_83266870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C294_G_ = int32_t(0x8349C294);
	if (!UseLiftedCode(144, 0x83266870)) { __imp__sub_83266870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C294_G_, (int64_t)str_TXT_820B0000_B_ - 28664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266870, 0x83266870) { ctx.r3.u64 = n_sub_83266870(ctx, base); }

uint64_t n_sub_832668B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C298_G_ = int32_t(0x8349C298);
	if (!UseLiftedCode(144, 0x832668B0)) { __imp__sub_832668B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832668B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C298_G_, (int64_t)str_TXT_820B0000_B_ - 28656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832668B0, 0x832668B0) { ctx.r3.u64 = n_sub_832668B0(ctx, base); }

uint64_t n_sub_832668F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C29C_G_ = int32_t(0x8349C29C);
	if (!UseLiftedCode(144, 0x832668F0)) { __imp__sub_832668F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832668F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C29C_G_, (int64_t)str_TXT_820B0000_B_ - 28648, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832668F0, 0x832668F0) { ctx.r3.u64 = n_sub_832668F0(ctx, base); }

uint64_t n_sub_83266930(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2A0_G_ = int32_t(0x8349C2A0);
	if (!UseLiftedCode(144, 0x83266930)) { __imp__sub_83266930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266930);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A0_G_, (int64_t)str_TXT_820B0000_B_ - 28640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266930, 0x83266930) { ctx.r3.u64 = n_sub_83266930(ctx, base); }

uint64_t n_sub_83266970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2A4_G_ = int32_t(0x8349C2A4);
	if (!UseLiftedCode(144, 0x83266970)) { __imp__sub_83266970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266970);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A4_G_, (int64_t)str_TXT_820B0000_B_ - 28632, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266970, 0x83266970) { ctx.r3.u64 = n_sub_83266970(ctx, base); }

uint64_t n_sub_832669B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2A8_G_ = int32_t(0x8349C2A8);
	if (!UseLiftedCode(144, 0x832669B0)) { __imp__sub_832669B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832669B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2A8_G_, (int64_t)str_TXT_820B0000_B_ - 28624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832669B0, 0x832669B0) { ctx.r3.u64 = n_sub_832669B0(ctx, base); }

uint64_t n_sub_832669F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2AC_G_ = int32_t(0x8349C2AC);
	if (!UseLiftedCode(144, 0x832669F0)) { __imp__sub_832669F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832669F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2AC_G_, (int64_t)str_TXT_820B0000_B_ - 28616, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832669F0, 0x832669F0) { ctx.r3.u64 = n_sub_832669F0(ctx, base); }

uint64_t n_sub_83266A30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2B0_G_ = int32_t(0x8349C2B0);
	if (!UseLiftedCode(144, 0x83266A30)) { __imp__sub_83266A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266A30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B0_G_, (int64_t)str_TXT_820B0000_B_ - 28604, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266A30, 0x83266A30) { ctx.r3.u64 = n_sub_83266A30(ctx, base); }

uint64_t n_sub_83266A70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2B4_G_ = int32_t(0x8349C2B4);
	if (!UseLiftedCode(144, 0x83266A70)) { __imp__sub_83266A70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266A70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B4_G_, (int64_t)g_820A0000 + 22936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266A70, 0x83266A70) { ctx.r3.u64 = n_sub_83266A70(ctx, base); }

uint64_t n_sub_83266AB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2B8_G_ = int32_t(0x8349C2B8);
	if (!UseLiftedCode(144, 0x83266AB0)) { __imp__sub_83266AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266AB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2B8_G_, (int64_t)g_820E0000 + 7240, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266AB0, 0x83266AB0) { ctx.r3.u64 = n_sub_83266AB0(ctx, base); }

uint64_t n_sub_83266AF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2BC_G_ = int32_t(0x8349C2BC);
	if (!UseLiftedCode(144, 0x83266AF0)) { __imp__sub_83266AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266AF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2BC_G_, (int64_t)g_820E0000 + 7256, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266AF0, 0x83266AF0) { ctx.r3.u64 = n_sub_83266AF0(ctx, base); }

uint64_t n_sub_83266B30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2C0_G_ = int32_t(0x8349C2C0);
	if (!UseLiftedCode(144, 0x83266B30)) { __imp__sub_83266B30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266B30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C0_G_, (int64_t)g_820E0000 + 7268, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266B30, 0x83266B30) { ctx.r3.u64 = n_sub_83266B30(ctx, base); }

uint64_t n_sub_83266B70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2C4_G_ = int32_t(0x8349C2C4);
	if (!UseLiftedCode(144, 0x83266B70)) { __imp__sub_83266B70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266B70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C4_G_, (int64_t)g_820E0000 + 7280, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266B70, 0x83266B70) { ctx.r3.u64 = n_sub_83266B70(ctx, base); }

uint64_t n_sub_83266BB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2C8_G_ = int32_t(0x8349C2C8);
	if (!UseLiftedCode(144, 0x83266BB0)) { __imp__sub_83266BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266BB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2C8_G_, (int64_t)g_820E0000 + 7288, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266BB0, 0x83266BB0) { ctx.r3.u64 = n_sub_83266BB0(ctx, base); }

uint64_t n_sub_83266BF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C2CC_G_ = int32_t(0x8349C2CC);
	if (!UseLiftedCode(144, 0x83266BF0)) { __imp__sub_83266BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83266BF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C2CC_G_, (int64_t)str_TXT_820B0000_B_ - 28456, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83266BF0, 0x83266BF0) { ctx.r3.u64 = n_sub_83266BF0(ctx, base); }

uint64_t n_sub_832670C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C324_G_ = int32_t(0x8349C324);
	if (!UseLiftedCode(144, 0x832670C8)) { __imp__sub_832670C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832670C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C324_G_, (int64_t)g_820E0000 + 7572, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832670C8, 0x832670C8) { ctx.r3.u64 = n_sub_832670C8(ctx, base); }

uint64_t n_sub_83267108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C328_G_ = int32_t(0x8349C328);
	if (!UseLiftedCode(144, 0x83267108)) { __imp__sub_83267108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C328_G_, (int64_t)g_820E0000 + 7620, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267108, 0x83267108) { ctx.r3.u64 = n_sub_83267108(ctx, base); }

uint64_t n_sub_83267148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C32C_G_ = int32_t(0x8349C32C);
	if (!UseLiftedCode(144, 0x83267148)) { __imp__sub_83267148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C32C_G_, (int64_t)g_820E0000 + 7668, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 30984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267148, 0x83267148) { ctx.r3.u64 = n_sub_83267148(ctx, base); }

uint64_t n_sub_83267188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C330_G_ = int32_t(0x8349C330);
	if (!UseLiftedCode(144, 0x83267188)) { __imp__sub_83267188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C330_G_, (int64_t)g_820E0000 + 7712, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267188, 0x83267188) { ctx.r3.u64 = n_sub_83267188(ctx, base); }

uint64_t n_sub_832671C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C334_G_ = int32_t(0x8349C334);
	if (!UseLiftedCode(144, 0x832671C8)) { __imp__sub_832671C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832671C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C334_G_, (int64_t)g_820E0000 + 7760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832671C8, 0x832671C8) { ctx.r3.u64 = n_sub_832671C8(ctx, base); }

uint64_t n_sub_83267208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C338_G_ = int32_t(0x8349C338);
	if (!UseLiftedCode(144, 0x83267208)) { __imp__sub_83267208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C338_G_, (int64_t)g_820E0000 + 7816, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267208, 0x83267208) { ctx.r3.u64 = n_sub_83267208(ctx, base); }

uint64_t n_sub_83267248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C33C_G_ = int32_t(0x8349C33C);
	if (!UseLiftedCode(144, 0x83267248)) { __imp__sub_83267248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C33C_G_, (int64_t)str_TXT_820C0000_B_ + 244, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267248, 0x83267248) { ctx.r3.u64 = n_sub_83267248(ctx, base); }

uint64_t n_sub_83267288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C340_G_ = int32_t(0x8349C340);
	if (!UseLiftedCode(144, 0x83267288)) { __imp__sub_83267288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C340_G_, (int64_t)str_TXT_820C0000_B_ + 176, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267288, 0x83267288) { ctx.r3.u64 = n_sub_83267288(ctx, base); }

uint64_t n_sub_832672C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C344_G_ = int32_t(0x8349C344);
	if (!UseLiftedCode(144, 0x832672C8)) { __imp__sub_832672C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832672C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C344_G_, (int64_t)g_820E0000 + 7872, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832672C8, 0x832672C8) { ctx.r3.u64 = n_sub_832672C8(ctx, base); }

uint64_t n_sub_83267308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C348_G_ = int32_t(0x8349C348);
	if (!UseLiftedCode(144, 0x83267308)) { __imp__sub_83267308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C348_G_, (int64_t)g_820E0000 + 7936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267308, 0x83267308) { ctx.r3.u64 = n_sub_83267308(ctx, base); }

uint64_t n_sub_83267348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C34C_G_ = int32_t(0x8349C34C);
	if (!UseLiftedCode(144, 0x83267348)) { __imp__sub_83267348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C34C_G_, (int64_t)g_820E0000 + 8008, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267348, 0x83267348) { ctx.r3.u64 = n_sub_83267348(ctx, base); }

uint64_t n_sub_83267388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C350_G_ = int32_t(0x8349C350);
	if (!UseLiftedCode(144, 0x83267388)) { __imp__sub_83267388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C350_G_, (int64_t)g_820E0000 + 8076, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267388, 0x83267388) { ctx.r3.u64 = n_sub_83267388(ctx, base); }

uint64_t n_sub_832673C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C354_G_ = int32_t(0x8349C354);
	if (!UseLiftedCode(144, 0x832673C8)) { __imp__sub_832673C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832673C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C354_G_, (int64_t)g_820E0000 + 8348, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832673C8, 0x832673C8) { ctx.r3.u64 = n_sub_832673C8(ctx, base); }

uint64_t n_sub_83267408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C358_G_ = int32_t(0x8349C358);
	if (!UseLiftedCode(144, 0x83267408)) { __imp__sub_83267408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C358_G_, (int64_t)g_820E0000 + 8400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267408, 0x83267408) { ctx.r3.u64 = n_sub_83267408(ctx, base); }

uint64_t n_sub_83267448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C35C_G_ = int32_t(0x8349C35C);
	if (!UseLiftedCode(144, 0x83267448)) { __imp__sub_83267448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C35C_G_, (int64_t)g_820E0000 + 8460, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267448, 0x83267448) { ctx.r3.u64 = n_sub_83267448(ctx, base); }

uint64_t n_sub_83267488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C360_G_ = int32_t(0x8349C360);
	if (!UseLiftedCode(144, 0x83267488)) { __imp__sub_83267488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C360_G_, (int64_t)str_TXT_820C0000_B_ - 424, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267488, 0x83267488) { ctx.r3.u64 = n_sub_83267488(ctx, base); }

uint64_t n_sub_832674C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C364_G_ = int32_t(0x8349C364);
	if (!UseLiftedCode(144, 0x832674C8)) { __imp__sub_832674C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832674C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C364_G_, (int64_t)g_820E0000 + 7872, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832674C8, 0x832674C8) { ctx.r3.u64 = n_sub_832674C8(ctx, base); }

uint64_t n_sub_83267508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C368_G_ = int32_t(0x8349C368);
	if (!UseLiftedCode(144, 0x83267508)) { __imp__sub_83267508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C368_G_, (int64_t)g_820E0000 + 7936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267508, 0x83267508) { ctx.r3.u64 = n_sub_83267508(ctx, base); }

uint64_t n_sub_83267548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C36C_G_ = int32_t(0x8349C36C);
	if (!UseLiftedCode(144, 0x83267548)) { __imp__sub_83267548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C36C_G_, (int64_t)g_820E0000 + 8516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267548, 0x83267548) { ctx.r3.u64 = n_sub_83267548(ctx, base); }

uint64_t n_sub_83267588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C370_G_ = int32_t(0x8349C370);
	if (!UseLiftedCode(144, 0x83267588)) { __imp__sub_83267588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C370_G_, (int64_t)g_820E0000 + 8576, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267588, 0x83267588) { ctx.r3.u64 = n_sub_83267588(ctx, base); }

uint64_t n_sub_832675C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C374_G_ = int32_t(0x8349C374);
	if (!UseLiftedCode(144, 0x832675C8)) { __imp__sub_832675C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832675C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C374_G_, (int64_t)g_820E0000 + 7712, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832675C8, 0x832675C8) { ctx.r3.u64 = n_sub_832675C8(ctx, base); }

uint64_t n_sub_83267608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C378_G_ = int32_t(0x8349C378);
	if (!UseLiftedCode(144, 0x83267608)) { __imp__sub_83267608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C378_G_, (int64_t)g_820E0000 + 7760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267608, 0x83267608) { ctx.r3.u64 = n_sub_83267608(ctx, base); }

uint64_t n_sub_83267648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C37C_G_ = int32_t(0x8349C37C);
	if (!UseLiftedCode(144, 0x83267648)) { __imp__sub_83267648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C37C_G_, (int64_t)g_820E0000 + 8644, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267648, 0x83267648) { ctx.r3.u64 = n_sub_83267648(ctx, base); }

uint64_t n_sub_83267B20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3D4_G_ = int32_t(0x8349C3D4);
	if (!UseLiftedCode(144, 0x83267B20)) { __imp__sub_83267B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267B20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3D4_G_, (int64_t)g_820E0000 + 9052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267B20, 0x83267B20) { ctx.r3.u64 = n_sub_83267B20(ctx, base); }

uint64_t n_sub_83267B60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3D8_G_ = int32_t(0x8349C3D8);
	if (!UseLiftedCode(144, 0x83267B60)) { __imp__sub_83267B60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267B60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3D8_G_, (int64_t)g_820E0000 + 9100, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267B60, 0x83267B60) { ctx.r3.u64 = n_sub_83267B60(ctx, base); }

uint64_t n_sub_83267BA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3DC_G_ = int32_t(0x8349C3DC);
	if (!UseLiftedCode(144, 0x83267BA0)) { __imp__sub_83267BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267BA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3DC_G_, (int64_t)g_820E0000 + 9148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267BA0, 0x83267BA0) { ctx.r3.u64 = n_sub_83267BA0(ctx, base); }

uint64_t n_sub_83267BE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3E0_G_ = int32_t(0x8349C3E0);
	if (!UseLiftedCode(144, 0x83267BE0)) { __imp__sub_83267BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267BE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E0_G_, (int64_t)g_820E0000 + 9200, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267BE0, 0x83267BE0) { ctx.r3.u64 = n_sub_83267BE0(ctx, base); }

uint64_t n_sub_83267C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3E4_G_ = int32_t(0x8349C3E4);
	if (!UseLiftedCode(144, 0x83267C20)) { __imp__sub_83267C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267C20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E4_G_, (int64_t)g_820E0000 + 9248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267C20, 0x83267C20) { ctx.r3.u64 = n_sub_83267C20(ctx, base); }

uint64_t n_sub_83267C60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3E8_G_ = int32_t(0x8349C3E8);
	if (!UseLiftedCode(144, 0x83267C60)) { __imp__sub_83267C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267C60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3E8_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267C60, 0x83267C60) { ctx.r3.u64 = n_sub_83267C60(ctx, base); }

uint64_t n_sub_83267CA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3EC_G_ = int32_t(0x8349C3EC);
	if (!UseLiftedCode(144, 0x83267CA0)) { __imp__sub_83267CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267CA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3EC_G_, (int64_t)g_820E0000 + 9352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267CA0, 0x83267CA0) { ctx.r3.u64 = n_sub_83267CA0(ctx, base); }

uint64_t n_sub_83267CE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3F0_G_ = int32_t(0x8349C3F0);
	if (!UseLiftedCode(144, 0x83267CE0)) { __imp__sub_83267CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267CE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F0_G_, (int64_t)g_820E0000 + 9404, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267CE0, 0x83267CE0) { ctx.r3.u64 = n_sub_83267CE0(ctx, base); }

uint64_t n_sub_83267D20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3F4_G_ = int32_t(0x8349C3F4);
	if (!UseLiftedCode(144, 0x83267D20)) { __imp__sub_83267D20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267D20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F4_G_, (int64_t)g_820E0000 + 9352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267D20, 0x83267D20) { ctx.r3.u64 = n_sub_83267D20(ctx, base); }

uint64_t n_sub_83267D60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C3F8_G_ = int32_t(0x8349C3F8);
	if (!UseLiftedCode(144, 0x83267D60)) { __imp__sub_83267D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83267D60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C3F8_G_, (int64_t)g_820E0000 + 9404, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83267D60, 0x83267D60) { ctx.r3.u64 = n_sub_83267D60(ctx, base); }

uint64_t n_sub_83268528(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4D0_G_ = int32_t(0x8349C4D0);
	if (!UseLiftedCode(144, 0x83268528)) { __imp__sub_83268528(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268528);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D0_G_, (int64_t)g_82000000 + 3928, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268528, 0x83268528) { ctx.r3.u64 = n_sub_83268528(ctx, base); }

uint64_t n_sub_83268568(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4D4_G_ = int32_t(0x8349C4D4);
	if (!UseLiftedCode(144, 0x83268568)) { __imp__sub_83268568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268568);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D4_G_, (int64_t)g_820E0000 + 9676, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268568, 0x83268568) { ctx.r3.u64 = n_sub_83268568(ctx, base); }

uint64_t n_sub_832685A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4D8_G_ = int32_t(0x8349C4D8);
	if (!UseLiftedCode(144, 0x832685A8)) { __imp__sub_832685A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832685A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4D8_G_, (int64_t)str_TXT_820B0000_B_ - 3580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832685A8, 0x832685A8) { ctx.r3.u64 = n_sub_832685A8(ctx, base); }

uint64_t n_sub_832685E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4DC_G_ = int32_t(0x8349C4DC);
	if (!UseLiftedCode(144, 0x832685E8)) { __imp__sub_832685E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832685E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4DC_G_, (int64_t)str_TXT_820C0000_B_ + 3196, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832685E8, 0x832685E8) { ctx.r3.u64 = n_sub_832685E8(ctx, base); }

uint64_t n_sub_83268628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4E0_G_ = int32_t(0x8349C4E0);
	if (!UseLiftedCode(144, 0x83268628)) { __imp__sub_83268628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E0_G_, (int64_t)str_TXT_820C0000_B_ + 3148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268628, 0x83268628) { ctx.r3.u64 = n_sub_83268628(ctx, base); }

uint64_t n_sub_83268668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4E4_G_ = int32_t(0x8349C4E4);
	if (!UseLiftedCode(144, 0x83268668)) { __imp__sub_83268668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E4_G_, (int64_t)str_TXT_820C0000_B_ + 3056, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268668, 0x83268668) { ctx.r3.u64 = n_sub_83268668(ctx, base); }

uint64_t n_sub_832686A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4E8_G_ = int32_t(0x8349C4E8);
	if (!UseLiftedCode(144, 0x832686A8)) { __imp__sub_832686A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832686A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4E8_G_, (int64_t)str_TXT_820C0000_B_ + 3320, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832686A8, 0x832686A8) { ctx.r3.u64 = n_sub_832686A8(ctx, base); }

uint64_t n_sub_832686E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4EC_G_ = int32_t(0x8349C4EC);
	if (!UseLiftedCode(144, 0x832686E8)) { __imp__sub_832686E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832686E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4EC_G_, (int64_t)str_TXT_820C0000_B_ + 3260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832686E8, 0x832686E8) { ctx.r3.u64 = n_sub_832686E8(ctx, base); }

uint64_t n_sub_83268728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4F0_G_ = int32_t(0x8349C4F0);
	if (!UseLiftedCode(144, 0x83268728)) { __imp__sub_83268728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268728);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F0_G_, (int64_t)g_820E0000 + 9688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268728, 0x83268728) { ctx.r3.u64 = n_sub_83268728(ctx, base); }

uint64_t n_sub_83268768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4F4_G_ = int32_t(0x8349C4F4);
	if (!UseLiftedCode(144, 0x83268768)) { __imp__sub_83268768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268768);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F4_G_, (int64_t)str_TXT_820B0000_B_ - 3580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268768, 0x83268768) { ctx.r3.u64 = n_sub_83268768(ctx, base); }

uint64_t n_sub_832687A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4F8_G_ = int32_t(0x8349C4F8);
	if (!UseLiftedCode(144, 0x832687A8)) { __imp__sub_832687A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832687A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4F8_G_, (int64_t)g_820E0000 + 9704, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832687A8, 0x832687A8) { ctx.r3.u64 = n_sub_832687A8(ctx, base); }

uint64_t n_sub_832687E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C4FC_G_ = int32_t(0x8349C4FC);
	if (!UseLiftedCode(144, 0x832687E8)) { __imp__sub_832687E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832687E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C4FC_G_, (int64_t)g_820E0000 + 9716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832687E8, 0x832687E8) { ctx.r3.u64 = n_sub_832687E8(ctx, base); }

uint64_t n_sub_83268828(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C500_G_ = int32_t(0x8349C500);
	if (!UseLiftedCode(144, 0x83268828)) { __imp__sub_83268828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268828);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C500_G_, (int64_t)g_820E0000 + 9748, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268828, 0x83268828) { ctx.r3.u64 = n_sub_83268828(ctx, base); }

uint64_t n_sub_83268D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C558_G_ = int32_t(0x8349C558);
	if (!UseLiftedCode(144, 0x83268D00)) { __imp__sub_83268D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C558_G_, (int64_t)g_820E0000 + 9788, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268D00, 0x83268D00) { ctx.r3.u64 = n_sub_83268D00(ctx, base); }

uint64_t n_sub_83268D40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C55C_G_ = int32_t(0x8349C55C);
	if (!UseLiftedCode(144, 0x83268D40)) { __imp__sub_83268D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C55C_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268D40, 0x83268D40) { ctx.r3.u64 = n_sub_83268D40(ctx, base); }

uint64_t n_sub_83268D80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C560_G_ = int32_t(0x8349C560);
	if (!UseLiftedCode(144, 0x83268D80)) { __imp__sub_83268D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268D80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C560_G_, (int64_t)g_820E0000 + 9872, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268D80, 0x83268D80) { ctx.r3.u64 = n_sub_83268D80(ctx, base); }

uint64_t n_sub_83268DC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C564_G_ = int32_t(0x8349C564);
	if (!UseLiftedCode(144, 0x83268DC0)) { __imp__sub_83268DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268DC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C564_G_, (int64_t)g_820E0000 + 9944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268DC0, 0x83268DC0) { ctx.r3.u64 = n_sub_83268DC0(ctx, base); }

uint64_t n_sub_83268E00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C568_G_ = int32_t(0x8349C568);
	if (!UseLiftedCode(144, 0x83268E00)) { __imp__sub_83268E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C568_G_, (int64_t)g_820E0000 + 10016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268E00, 0x83268E00) { ctx.r3.u64 = n_sub_83268E00(ctx, base); }

uint64_t n_sub_83268E40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C56C_G_ = int32_t(0x8349C56C);
	if (!UseLiftedCode(144, 0x83268E40)) { __imp__sub_83268E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C56C_G_, (int64_t)g_820E0000 + 10096, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268E40, 0x83268E40) { ctx.r3.u64 = n_sub_83268E40(ctx, base); }

uint64_t n_sub_83268E80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C570_G_ = int32_t(0x8349C570);
	if (!UseLiftedCode(144, 0x83268E80)) { __imp__sub_83268E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268E80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C570_G_, (int64_t)g_820E0000 + 10168, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 31992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268E80, 0x83268E80) { ctx.r3.u64 = n_sub_83268E80(ctx, base); }

uint64_t n_sub_83268EC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C574_G_ = int32_t(0x8349C574);
	if (!UseLiftedCode(144, 0x83268EC0)) { __imp__sub_83268EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268EC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C574_G_, (int64_t)g_820E0000 + 10248, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268EC0, 0x83268EC0) { ctx.r3.u64 = n_sub_83268EC0(ctx, base); }

uint64_t n_sub_83268F00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C578_G_ = int32_t(0x8349C578);
	if (!UseLiftedCode(144, 0x83268F00)) { __imp__sub_83268F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C578_G_, (int64_t)g_820E0000 + 10328, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268F00, 0x83268F00) { ctx.r3.u64 = n_sub_83268F00(ctx, base); }

uint64_t n_sub_83268F40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C57C_G_ = int32_t(0x8349C57C);
	if (!UseLiftedCode(144, 0x83268F40)) { __imp__sub_83268F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C57C_G_, (int64_t)g_820E0000 + 10392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268F40, 0x83268F40) { ctx.r3.u64 = n_sub_83268F40(ctx, base); }

uint64_t n_sub_83268F80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C580_G_ = int32_t(0x8349C580);
	if (!UseLiftedCode(144, 0x83268F80)) { __imp__sub_83268F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268F80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C580_G_, (int64_t)g_820E0000 + 10464, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268F80, 0x83268F80) { ctx.r3.u64 = n_sub_83268F80(ctx, base); }

uint64_t n_sub_83268FC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C584_G_ = int32_t(0x8349C584);
	if (!UseLiftedCode(144, 0x83268FC0)) { __imp__sub_83268FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83268FC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C584_G_, (int64_t)g_820E0000 + 10536, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83268FC0, 0x83268FC0) { ctx.r3.u64 = n_sub_83268FC0(ctx, base); }

uint64_t n_sub_83269000(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C588_G_ = int32_t(0x8349C588);
	if (!UseLiftedCode(144, 0x83269000)) { __imp__sub_83269000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269000);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C588_G_, (int64_t)g_820E0000 + 10608, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269000, 0x83269000) { ctx.r3.u64 = n_sub_83269000(ctx, base); }

uint64_t n_sub_83269040(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C58C_G_ = int32_t(0x8349C58C);
	if (!UseLiftedCode(144, 0x83269040)) { __imp__sub_83269040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C58C_G_, (int64_t)g_820E0000 + 10680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269040, 0x83269040) { ctx.r3.u64 = n_sub_83269040(ctx, base); }

uint64_t n_sub_83269080(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C590_G_ = int32_t(0x8349C590);
	if (!UseLiftedCode(144, 0x83269080)) { __imp__sub_83269080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269080);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C590_G_, (int64_t)g_820E0000 + 10752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269080, 0x83269080) { ctx.r3.u64 = n_sub_83269080(ctx, base); }

uint64_t n_sub_83269558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5E8_G_ = int32_t(0x8349C5E8);
	if (!UseLiftedCode(144, 0x83269558)) { __imp__sub_83269558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5E8_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269558, 0x83269558) { ctx.r3.u64 = n_sub_83269558(ctx, base); }

uint64_t n_sub_83269598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5EC_G_ = int32_t(0x8349C5EC);
	if (!UseLiftedCode(144, 0x83269598)) { __imp__sub_83269598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5EC_G_, (int64_t)g_820E0000 + 11136, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269598, 0x83269598) { ctx.r3.u64 = n_sub_83269598(ctx, base); }

uint64_t n_sub_832695D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5F0_G_ = int32_t(0x8349C5F0);
	if (!UseLiftedCode(144, 0x832695D8)) { __imp__sub_832695D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832695D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F0_G_, (int64_t)g_820E0000 + 11192, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832695D8, 0x832695D8) { ctx.r3.u64 = n_sub_832695D8(ctx, base); }

uint64_t n_sub_83269618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5F4_G_ = int32_t(0x8349C5F4);
	if (!UseLiftedCode(144, 0x83269618)) { __imp__sub_83269618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269618);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F4_G_, (int64_t)g_820E0000 + 11252, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269618, 0x83269618) { ctx.r3.u64 = n_sub_83269618(ctx, base); }

uint64_t n_sub_83269658(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5F8_G_ = int32_t(0x8349C5F8);
	if (!UseLiftedCode(144, 0x83269658)) { __imp__sub_83269658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269658);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5F8_G_, (int64_t)g_820E0000 + 11272, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269658, 0x83269658) { ctx.r3.u64 = n_sub_83269658(ctx, base); }

uint64_t n_sub_83269698(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C5FC_G_ = int32_t(0x8349C5FC);
	if (!UseLiftedCode(144, 0x83269698)) { __imp__sub_83269698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269698);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C5FC_G_, (int64_t)g_820E0000 + 11288, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269698, 0x83269698) { ctx.r3.u64 = n_sub_83269698(ctx, base); }

uint64_t n_sub_832696D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C600_G_ = int32_t(0x8349C600);
	if (!UseLiftedCode(144, 0x832696D8)) { __imp__sub_832696D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832696D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C600_G_, (int64_t)g_820E0000 + 11304, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832696D8, 0x832696D8) { ctx.r3.u64 = n_sub_832696D8(ctx, base); }

uint64_t n_sub_83269718(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C604_G_ = int32_t(0x8349C604);
	if (!UseLiftedCode(144, 0x83269718)) { __imp__sub_83269718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269718);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C604_G_, (int64_t)g_820E0000 + 11320, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269718, 0x83269718) { ctx.r3.u64 = n_sub_83269718(ctx, base); }

uint64_t n_sub_83269758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C608_G_ = int32_t(0x8349C608);
	if (!UseLiftedCode(144, 0x83269758)) { __imp__sub_83269758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C608_G_, (int64_t)g_820E0000 + 11336, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269758, 0x83269758) { ctx.r3.u64 = n_sub_83269758(ctx, base); }

uint64_t n_sub_83269798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C60C_G_ = int32_t(0x8349C60C);
	if (!UseLiftedCode(144, 0x83269798)) { __imp__sub_83269798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C60C_G_, (int64_t)g_820E0000 + 11352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269798, 0x83269798) { ctx.r3.u64 = n_sub_83269798(ctx, base); }

uint64_t n_sub_832697D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C610_G_ = int32_t(0x8349C610);
	if (!UseLiftedCode(144, 0x832697D8)) { __imp__sub_832697D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832697D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C610_G_, (int64_t)g_820E0000 + 11368, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832697D8, 0x832697D8) { ctx.r3.u64 = n_sub_832697D8(ctx, base); }

uint64_t n_sub_83269818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C614_G_ = int32_t(0x8349C614);
	if (!UseLiftedCode(144, 0x83269818)) { __imp__sub_83269818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C614_G_, (int64_t)g_820E0000 + 11380, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269818, 0x83269818) { ctx.r3.u64 = n_sub_83269818(ctx, base); }

uint64_t n_sub_83269858(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C618_G_ = int32_t(0x8349C618);
	if (!UseLiftedCode(144, 0x83269858)) { __imp__sub_83269858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C618_G_, (int64_t)g_820E0000 + 11392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269858, 0x83269858) { ctx.r3.u64 = n_sub_83269858(ctx, base); }

uint64_t n_sub_83269898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C61C_G_ = int32_t(0x8349C61C);
	if (!UseLiftedCode(144, 0x83269898)) { __imp__sub_83269898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C61C_G_, (int64_t)g_820E0000 + 11408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269898, 0x83269898) { ctx.r3.u64 = n_sub_83269898(ctx, base); }

uint64_t n_sub_832698D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C620_G_ = int32_t(0x8349C620);
	if (!UseLiftedCode(144, 0x832698D8)) { __imp__sub_832698D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832698D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C620_G_, (int64_t)g_820E0000 + 11424, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832698D8, 0x832698D8) { ctx.r3.u64 = n_sub_832698D8(ctx, base); }

uint64_t n_sub_83269918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C624_G_ = int32_t(0x8349C624);
	if (!UseLiftedCode(144, 0x83269918)) { __imp__sub_83269918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C624_G_, (int64_t)g_820E0000 + 11440, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269918, 0x83269918) { ctx.r3.u64 = n_sub_83269918(ctx, base); }

uint64_t n_sub_83269958(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C628_G_ = int32_t(0x8349C628);
	if (!UseLiftedCode(144, 0x83269958)) { __imp__sub_83269958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269958);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C628_G_, (int64_t)g_820E0000 + 11500, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269958, 0x83269958) { ctx.r3.u64 = n_sub_83269958(ctx, base); }

uint64_t n_sub_83269998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C62C_G_ = int32_t(0x8349C62C);
	if (!UseLiftedCode(144, 0x83269998)) { __imp__sub_83269998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C62C_G_, (int64_t)g_820E0000 + 11516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269998, 0x83269998) { ctx.r3.u64 = n_sub_83269998(ctx, base); }

uint64_t n_sub_832699D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C630_G_ = int32_t(0x8349C630);
	if (!UseLiftedCode(144, 0x832699D8)) { __imp__sub_832699D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832699D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C630_G_, (int64_t)g_820E0000 + 11532, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832699D8, 0x832699D8) { ctx.r3.u64 = n_sub_832699D8(ctx, base); }

uint64_t n_sub_83269A18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C634_G_ = int32_t(0x8349C634);
	if (!UseLiftedCode(144, 0x83269A18)) { __imp__sub_83269A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C634_G_, (int64_t)g_820E0000 + 11548, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269A18, 0x83269A18) { ctx.r3.u64 = n_sub_83269A18(ctx, base); }

uint64_t n_sub_83269A58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C638_G_ = int32_t(0x8349C638);
	if (!UseLiftedCode(144, 0x83269A58)) { __imp__sub_83269A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C638_G_, (int64_t)g_820E0000 + 11564, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269A58, 0x83269A58) { ctx.r3.u64 = n_sub_83269A58(ctx, base); }

uint64_t n_sub_83269A98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C63C_G_ = int32_t(0x8349C63C);
	if (!UseLiftedCode(144, 0x83269A98)) { __imp__sub_83269A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269A98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C63C_G_, (int64_t)g_820E0000 + 11584, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269A98, 0x83269A98) { ctx.r3.u64 = n_sub_83269A98(ctx, base); }

uint64_t n_sub_83269F70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C694_G_ = int32_t(0x8349C694);
	if (!UseLiftedCode(144, 0x83269F70)) { __imp__sub_83269F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269F70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C694_G_, (int64_t)g_820E0000 + 11712, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269F70, 0x83269F70) { ctx.r3.u64 = n_sub_83269F70(ctx, base); }

uint64_t n_sub_83269FB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C698_G_ = int32_t(0x8349C698);
	if (!UseLiftedCode(144, 0x83269FB0)) { __imp__sub_83269FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269FB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C698_G_, (int64_t)g_820E0000 + 11776, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269FB0, 0x83269FB0) { ctx.r3.u64 = n_sub_83269FB0(ctx, base); }

uint64_t n_sub_83269FF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C69C_G_ = int32_t(0x8349C69C);
	if (!UseLiftedCode(144, 0x83269FF0)) { __imp__sub_83269FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83269FF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C69C_G_, (int64_t)g_820E0000 + 11848, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83269FF0, 0x83269FF0) { ctx.r3.u64 = n_sub_83269FF0(ctx, base); }

uint64_t n_sub_8326A030(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6A0_G_ = int32_t(0x8349C6A0);
	if (!UseLiftedCode(144, 0x8326A030)) { __imp__sub_8326A030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A030);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A0_G_, (int64_t)g_820E0000 + 11924, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A030, 0x8326A030) { ctx.r3.u64 = n_sub_8326A030(ctx, base); }

uint64_t n_sub_8326A070(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6A4_G_ = int32_t(0x8349C6A4);
	if (!UseLiftedCode(144, 0x8326A070)) { __imp__sub_8326A070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A070);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A4_G_, (int64_t)g_820E0000 + 11940, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A070, 0x8326A070) { ctx.r3.u64 = n_sub_8326A070(ctx, base); }

uint64_t n_sub_8326A0B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6A8_G_ = int32_t(0x8349C6A8);
	if (!UseLiftedCode(144, 0x8326A0B0)) { __imp__sub_8326A0B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A0B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6A8_G_, (int64_t)g_820E0000 + 11952, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A0B0, 0x8326A0B0) { ctx.r3.u64 = n_sub_8326A0B0(ctx, base); }

uint64_t n_sub_8326A0F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6AC_G_ = int32_t(0x8349C6AC);
	if (!UseLiftedCode(144, 0x8326A0F0)) { __imp__sub_8326A0F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A0F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6AC_G_, (int64_t)g_820E0000 + 11964, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A0F0, 0x8326A0F0) { ctx.r3.u64 = n_sub_8326A0F0(ctx, base); }

uint64_t n_sub_8326A130(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6B0_G_ = int32_t(0x8349C6B0);
	if (!UseLiftedCode(144, 0x8326A130)) { __imp__sub_8326A130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A130);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B0_G_, (int64_t)g_820E0000 + 11980, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A130, 0x8326A130) { ctx.r3.u64 = n_sub_8326A130(ctx, base); }

uint64_t n_sub_8326A170(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6B4_G_ = int32_t(0x8349C6B4);
	if (!UseLiftedCode(144, 0x8326A170)) { __imp__sub_8326A170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A170);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B4_G_, (int64_t)g_820E0000 + 11992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A170, 0x8326A170) { ctx.r3.u64 = n_sub_8326A170(ctx, base); }

uint64_t n_sub_8326A1B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6B8_G_ = int32_t(0x8349C6B8);
	if (!UseLiftedCode(144, 0x8326A1B0)) { __imp__sub_8326A1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A1B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6B8_G_, (int64_t)g_820E0000 + 12004, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A1B0, 0x8326A1B0) { ctx.r3.u64 = n_sub_8326A1B0(ctx, base); }

uint64_t n_sub_8326A1F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6BC_G_ = int32_t(0x8349C6BC);
	if (!UseLiftedCode(144, 0x8326A1F0)) { __imp__sub_8326A1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A1F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6BC_G_, (int64_t)g_820E0000 + 12028, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A1F0, 0x8326A1F0) { ctx.r3.u64 = n_sub_8326A1F0(ctx, base); }

uint64_t n_sub_8326A230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6C0_G_ = int32_t(0x8349C6C0);
	if (!UseLiftedCode(144, 0x8326A230)) { __imp__sub_8326A230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C0_G_, (int64_t)g_820E0000 + 12040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A230, 0x8326A230) { ctx.r3.u64 = n_sub_8326A230(ctx, base); }

uint64_t n_sub_8326A270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6C4_G_ = int32_t(0x8349C6C4);
	if (!UseLiftedCode(144, 0x8326A270)) { __imp__sub_8326A270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A270);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C4_G_, (int64_t)g_820E0000 + 12056, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A270, 0x8326A270) { ctx.r3.u64 = n_sub_8326A270(ctx, base); }

uint64_t n_sub_8326A2B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C6C8_G_ = int32_t(0x8349C6C8);
	if (!UseLiftedCode(144, 0x8326A2B0)) { __imp__sub_8326A2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A2B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C6C8_G_, (int64_t)g_820E0000 + 12068, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A2B0, 0x8326A2B0) { ctx.r3.u64 = n_sub_8326A2B0(ctx, base); }

uint64_t n_sub_8326A788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C720_G_ = int32_t(0x8349C720);
	if (!UseLiftedCode(144, 0x8326A788)) { __imp__sub_8326A788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C720_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A788, 0x8326A788) { ctx.r3.u64 = n_sub_8326A788(ctx, base); }

uint64_t n_sub_8326A7C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C724_G_ = int32_t(0x8349C724);
	if (!UseLiftedCode(144, 0x8326A7C8)) { __imp__sub_8326A7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A7C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C724_G_, (int64_t)g_820E0000 + 12120, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A7C8, 0x8326A7C8) { ctx.r3.u64 = n_sub_8326A7C8(ctx, base); }

uint64_t n_sub_8326A808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C728_G_ = int32_t(0x8349C728);
	if (!UseLiftedCode(144, 0x8326A808)) { __imp__sub_8326A808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C728_G_, (int64_t)g_820E0000 + 12176, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A808, 0x8326A808) { ctx.r3.u64 = n_sub_8326A808(ctx, base); }

uint64_t n_sub_8326A848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349C72C_G_ = int32_t(0x8349C72C);
	if (!UseLiftedCode(144, 0x8326A848)) { __imp__sub_8326A848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C72C_G_, (int64_t)g_820E0000 + 12232, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 32760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A848, 0x8326A848) { ctx.r3.u64 = n_sub_8326A848(ctx, base); }

uint64_t n_sub_8326A888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C730_G_ = int32_t(0x8349C730);
	if (!UseLiftedCode(144, 0x8326A888)) { __imp__sub_8326A888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C730_G_, (int64_t)g_820E0000 + 12240, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A888, 0x8326A888) { ctx.r3.u64 = n_sub_8326A888(ctx, base); }

uint64_t n_sub_8326A8C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C734_G_ = int32_t(0x8349C734);
	if (!UseLiftedCode(144, 0x8326A8C8)) { __imp__sub_8326A8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A8C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C734_G_, (int64_t)g_820E0000 + 12248, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A8C8, 0x8326A8C8) { ctx.r3.u64 = n_sub_8326A8C8(ctx, base); }

uint64_t n_sub_8326A908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C738_G_ = int32_t(0x8349C738);
	if (!UseLiftedCode(144, 0x8326A908)) { __imp__sub_8326A908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C738_G_, (int64_t)g_820E0000 + 12256, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A908, 0x8326A908) { ctx.r3.u64 = n_sub_8326A908(ctx, base); }

uint64_t n_sub_8326A948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C73C_G_ = int32_t(0x8349C73C);
	if (!UseLiftedCode(144, 0x8326A948)) { __imp__sub_8326A948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C73C_G_, (int64_t)g_820E0000 + 12268, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A948, 0x8326A948) { ctx.r3.u64 = n_sub_8326A948(ctx, base); }

uint64_t n_sub_8326A988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C740_G_ = int32_t(0x8349C740);
	if (!UseLiftedCode(144, 0x8326A988)) { __imp__sub_8326A988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C740_G_, (int64_t)g_820E0000 + 12276, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A988, 0x8326A988) { ctx.r3.u64 = n_sub_8326A988(ctx, base); }

// sub_8326A9C8  [64 bytes]
uint64_t n_sub_8326A9C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C744_G_ = int32_t(0x8349C744);
	if (!UseLiftedCode(144, 0x8326A9C8)) { __imp__sub_8326A9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326A9C8);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C744_G_, (int64_t)g_820E0000 - 9936, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326A9C8, 0x8326A9C8) { ctx.r3.u64 = n_sub_8326A9C8(ctx, base); }

uint64_t n_sub_8326AA08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C748_G_ = int32_t(0x8349C748);
	if (!UseLiftedCode(144, 0x8326AA08)) { __imp__sub_8326AA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C748_G_, (int64_t)g_820E0000 + 12292, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AA08, 0x8326AA08) { ctx.r3.u64 = n_sub_8326AA08(ctx, base); }

uint64_t n_sub_8326AA48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C74C_G_ = int32_t(0x8349C74C);
	if (!UseLiftedCode(144, 0x8326AA48)) { __imp__sub_8326AA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C74C_G_, (int64_t)g_820E0000 + 12300, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AA48, 0x8326AA48) { ctx.r3.u64 = n_sub_8326AA48(ctx, base); }

uint64_t n_sub_8326AA88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C750_G_ = int32_t(0x8349C750);
	if (!UseLiftedCode(144, 0x8326AA88)) { __imp__sub_8326AA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AA88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C750_G_, (int64_t)g_820E0000 + 12320, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AA88, 0x8326AA88) { ctx.r3.u64 = n_sub_8326AA88(ctx, base); }

uint64_t n_sub_8326AAC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C754_G_ = int32_t(0x8349C754);
	if (!UseLiftedCode(144, 0x8326AAC8)) { __imp__sub_8326AAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AAC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C754_G_, (int64_t)g_820E0000 + 12340, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AAC8, 0x8326AAC8) { ctx.r3.u64 = n_sub_8326AAC8(ctx, base); }

uint64_t n_sub_8326AB08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C758_G_ = int32_t(0x8349C758);
	if (!UseLiftedCode(144, 0x8326AB08)) { __imp__sub_8326AB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C758_G_, (int64_t)g_820E0000 + 12364, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AB08, 0x8326AB08) { ctx.r3.u64 = n_sub_8326AB08(ctx, base); }

uint64_t n_sub_8326AB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C75C_G_ = int32_t(0x8349C75C);
	if (!UseLiftedCode(144, 0x8326AB48)) { __imp__sub_8326AB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C75C_G_, (int64_t)g_820E0000 + 12380, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AB48, 0x8326AB48) { ctx.r3.u64 = n_sub_8326AB48(ctx, base); }

uint64_t n_sub_8326AB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C760_G_ = int32_t(0x8349C760);
	if (!UseLiftedCode(144, 0x8326AB88)) { __imp__sub_8326AB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AB88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C760_G_, (int64_t)g_820E0000 + 12400, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AB88, 0x8326AB88) { ctx.r3.u64 = n_sub_8326AB88(ctx, base); }

uint64_t n_sub_8326ABC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C764_G_ = int32_t(0x8349C764);
	if (!UseLiftedCode(144, 0x8326ABC8)) { __imp__sub_8326ABC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ABC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C764_G_, (int64_t)g_820E0000 + 12424, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326ABC8, 0x8326ABC8) { ctx.r3.u64 = n_sub_8326ABC8(ctx, base); }

uint64_t n_sub_8326AC08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C768_G_ = int32_t(0x8349C768);
	if (!UseLiftedCode(144, 0x8326AC08)) { __imp__sub_8326AC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C768_G_, (int64_t)g_820E0000 + 12444, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AC08, 0x8326AC08) { ctx.r3.u64 = n_sub_8326AC08(ctx, base); }

uint64_t n_sub_8326AC48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C76C_G_ = int32_t(0x8349C76C);
	if (!UseLiftedCode(144, 0x8326AC48)) { __imp__sub_8326AC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C76C_G_, (int64_t)g_820E0000 + 12460, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AC48, 0x8326AC48) { ctx.r3.u64 = n_sub_8326AC48(ctx, base); }

uint64_t n_sub_8326AC88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C770_G_ = int32_t(0x8349C770);
	if (!UseLiftedCode(144, 0x8326AC88)) { __imp__sub_8326AC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AC88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C770_G_, (int64_t)g_820E0000 + 12488, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AC88, 0x8326AC88) { ctx.r3.u64 = n_sub_8326AC88(ctx, base); }

uint64_t n_sub_8326ACC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C774_G_ = int32_t(0x8349C774);
	if (!UseLiftedCode(144, 0x8326ACC8)) { __imp__sub_8326ACC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ACC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C774_G_, (int64_t)g_820E0000 + 12504, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326ACC8, 0x8326ACC8) { ctx.r3.u64 = n_sub_8326ACC8(ctx, base); }

uint64_t n_sub_8326AD08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C778_G_ = int32_t(0x8349C778);
	if (!UseLiftedCode(144, 0x8326AD08)) { __imp__sub_8326AD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C778_G_, (int64_t)g_820E0000 + 12528, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AD08, 0x8326AD08) { ctx.r3.u64 = n_sub_8326AD08(ctx, base); }

uint64_t n_sub_8326AD48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C77C_G_ = int32_t(0x8349C77C);
	if (!UseLiftedCode(144, 0x8326AD48)) { __imp__sub_8326AD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C77C_G_, (int64_t)g_820E0000 + 12552, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AD48, 0x8326AD48) { ctx.r3.u64 = n_sub_8326AD48(ctx, base); }

uint64_t n_sub_8326AD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C780_G_ = int32_t(0x8349C780);
	if (!UseLiftedCode(144, 0x8326AD88)) { __imp__sub_8326AD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C780_G_, (int64_t)g_820E0000 + 12572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AD88, 0x8326AD88) { ctx.r3.u64 = n_sub_8326AD88(ctx, base); }

uint64_t n_sub_8326ADC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C784_G_ = int32_t(0x8349C784);
	if (!UseLiftedCode(144, 0x8326ADC8)) { __imp__sub_8326ADC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326ADC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C784_G_, (int64_t)g_820E0000 + 12584, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326ADC8, 0x8326ADC8) { ctx.r3.u64 = n_sub_8326ADC8(ctx, base); }

uint64_t n_sub_8326AE08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C788_G_ = int32_t(0x8349C788);
	if (!UseLiftedCode(144, 0x8326AE08)) { __imp__sub_8326AE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C788_G_, (int64_t)g_820E0000 + 12608, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AE08, 0x8326AE08) { ctx.r3.u64 = n_sub_8326AE08(ctx, base); }

uint64_t n_sub_8326AE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C78C_G_ = int32_t(0x8349C78C);
	if (!UseLiftedCode(144, 0x8326AE48)) { __imp__sub_8326AE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C78C_G_, (int64_t)g_820E0000 + 12628, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AE48, 0x8326AE48) { ctx.r3.u64 = n_sub_8326AE48(ctx, base); }

uint64_t n_sub_8326AE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C790_G_ = int32_t(0x8349C790);
	if (!UseLiftedCode(144, 0x8326AE88)) { __imp__sub_8326AE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AE88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C790_G_, (int64_t)g_820E0000 + 12648, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AE88, 0x8326AE88) { ctx.r3.u64 = n_sub_8326AE88(ctx, base); }

uint64_t n_sub_8326AEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C794_G_ = int32_t(0x8349C794);
	if (!UseLiftedCode(144, 0x8326AEC8)) { __imp__sub_8326AEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C794_G_, (int64_t)g_820E0000 + 12668, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AEC8, 0x8326AEC8) { ctx.r3.u64 = n_sub_8326AEC8(ctx, base); }

uint64_t n_sub_8326AF08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C798_G_ = int32_t(0x8349C798);
	if (!UseLiftedCode(144, 0x8326AF08)) { __imp__sub_8326AF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C798_G_, (int64_t)g_820E0000 + 12688, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AF08, 0x8326AF08) { ctx.r3.u64 = n_sub_8326AF08(ctx, base); }

uint64_t n_sub_8326AF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C79C_G_ = int32_t(0x8349C79C);
	if (!UseLiftedCode(144, 0x8326AF48)) { __imp__sub_8326AF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C79C_G_, (int64_t)g_820E0000 + 12712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AF48, 0x8326AF48) { ctx.r3.u64 = n_sub_8326AF48(ctx, base); }

uint64_t n_sub_8326AF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7A0_G_ = int32_t(0x8349C7A0);
	if (!UseLiftedCode(144, 0x8326AF88)) { __imp__sub_8326AF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AF88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A0_G_, (int64_t)g_820E0000 + 12732, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AF88, 0x8326AF88) { ctx.r3.u64 = n_sub_8326AF88(ctx, base); }

uint64_t n_sub_8326AFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7A4_G_ = int32_t(0x8349C7A4);
	if (!UseLiftedCode(144, 0x8326AFC8)) { __imp__sub_8326AFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326AFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A4_G_, (int64_t)g_820E0000 + 12760, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326AFC8, 0x8326AFC8) { ctx.r3.u64 = n_sub_8326AFC8(ctx, base); }

uint64_t n_sub_8326B008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7A8_G_ = int32_t(0x8349C7A8);
	if (!UseLiftedCode(144, 0x8326B008)) { __imp__sub_8326B008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7A8_G_, (int64_t)g_820E0000 + 12788, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B008, 0x8326B008) { ctx.r3.u64 = n_sub_8326B008(ctx, base); }

uint64_t n_sub_8326B048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7AC_G_ = int32_t(0x8349C7AC);
	if (!UseLiftedCode(144, 0x8326B048)) { __imp__sub_8326B048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7AC_G_, (int64_t)g_820E0000 + 12808, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B048, 0x8326B048) { ctx.r3.u64 = n_sub_8326B048(ctx, base); }

uint64_t n_sub_8326B088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7B0_G_ = int32_t(0x8349C7B0);
	if (!UseLiftedCode(144, 0x8326B088)) { __imp__sub_8326B088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B0_G_, (int64_t)g_820E0000 + 12828, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B088, 0x8326B088) { ctx.r3.u64 = n_sub_8326B088(ctx, base); }

uint64_t n_sub_8326B0C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7B4_G_ = int32_t(0x8349C7B4);
	if (!UseLiftedCode(144, 0x8326B0C8)) { __imp__sub_8326B0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B0C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B4_G_, (int64_t)g_820E0000 + 12852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B0C8, 0x8326B0C8) { ctx.r3.u64 = n_sub_8326B0C8(ctx, base); }

uint64_t n_sub_8326B108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7B8_G_ = int32_t(0x8349C7B8);
	if (!UseLiftedCode(144, 0x8326B108)) { __imp__sub_8326B108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7B8_G_, (int64_t)g_820E0000 + 12876, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B108, 0x8326B108) { ctx.r3.u64 = n_sub_8326B108(ctx, base); }

uint64_t n_sub_8326B148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7BC_G_ = int32_t(0x8349C7BC);
	if (!UseLiftedCode(144, 0x8326B148)) { __imp__sub_8326B148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7BC_G_, (int64_t)g_820E0000 + 12900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B148, 0x8326B148) { ctx.r3.u64 = n_sub_8326B148(ctx, base); }

uint64_t n_sub_8326B188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7C0_G_ = int32_t(0x8349C7C0);
	if (!UseLiftedCode(144, 0x8326B188)) { __imp__sub_8326B188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C0_G_, (int64_t)g_820E0000 + 12928, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B188, 0x8326B188) { ctx.r3.u64 = n_sub_8326B188(ctx, base); }

uint64_t n_sub_8326B1C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7C4_G_ = int32_t(0x8349C7C4);
	if (!UseLiftedCode(144, 0x8326B1C8)) { __imp__sub_8326B1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B1C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C4_G_, (int64_t)g_820E0000 + 12948, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B1C8, 0x8326B1C8) { ctx.r3.u64 = n_sub_8326B1C8(ctx, base); }

uint64_t n_sub_8326B208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7C8_G_ = int32_t(0x8349C7C8);
	if (!UseLiftedCode(144, 0x8326B208)) { __imp__sub_8326B208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7C8_G_, (int64_t)g_820E0000 + 12968, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B208, 0x8326B208) { ctx.r3.u64 = n_sub_8326B208(ctx, base); }

uint64_t n_sub_8326B248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7CC_G_ = int32_t(0x8349C7CC);
	if (!UseLiftedCode(144, 0x8326B248)) { __imp__sub_8326B248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7CC_G_, (int64_t)g_820E0000 + 12988, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B248, 0x8326B248) { ctx.r3.u64 = n_sub_8326B248(ctx, base); }

uint64_t n_sub_8326B288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7D0_G_ = int32_t(0x8349C7D0);
	if (!UseLiftedCode(144, 0x8326B288)) { __imp__sub_8326B288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D0_G_, (int64_t)g_820E0000 + 13016, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B288, 0x8326B288) { ctx.r3.u64 = n_sub_8326B288(ctx, base); }

uint64_t n_sub_8326B2C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7D4_G_ = int32_t(0x8349C7D4);
	if (!UseLiftedCode(144, 0x8326B2C8)) { __imp__sub_8326B2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B2C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D4_G_, (int64_t)g_820E0000 + 13044, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B2C8, 0x8326B2C8) { ctx.r3.u64 = n_sub_8326B2C8(ctx, base); }

uint64_t n_sub_8326B308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7D8_G_ = int32_t(0x8349C7D8);
	if (!UseLiftedCode(144, 0x8326B308)) { __imp__sub_8326B308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7D8_G_, (int64_t)g_820E0000 + 13076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B308, 0x8326B308) { ctx.r3.u64 = n_sub_8326B308(ctx, base); }

uint64_t n_sub_8326B348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7DC_G_ = int32_t(0x8349C7DC);
	if (!UseLiftedCode(144, 0x8326B348)) { __imp__sub_8326B348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7DC_G_, (int64_t)g_820E0000 + 13100, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B348, 0x8326B348) { ctx.r3.u64 = n_sub_8326B348(ctx, base); }

uint64_t n_sub_8326B388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7E0_G_ = int32_t(0x8349C7E0);
	if (!UseLiftedCode(144, 0x8326B388)) { __imp__sub_8326B388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E0_G_, (int64_t)g_820E0000 + 13124, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B388, 0x8326B388) { ctx.r3.u64 = n_sub_8326B388(ctx, base); }

uint64_t n_sub_8326B3C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7E4_G_ = int32_t(0x8349C7E4);
	if (!UseLiftedCode(144, 0x8326B3C8)) { __imp__sub_8326B3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B3C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E4_G_, (int64_t)g_820E0000 + 13148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B3C8, 0x8326B3C8) { ctx.r3.u64 = n_sub_8326B3C8(ctx, base); }

uint64_t n_sub_8326B408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7E8_G_ = int32_t(0x8349C7E8);
	if (!UseLiftedCode(144, 0x8326B408)) { __imp__sub_8326B408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7E8_G_, (int64_t)g_820E0000 + 13176, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B408, 0x8326B408) { ctx.r3.u64 = n_sub_8326B408(ctx, base); }

uint64_t n_sub_8326B448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7EC_G_ = int32_t(0x8349C7EC);
	if (!UseLiftedCode(144, 0x8326B448)) { __imp__sub_8326B448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7EC_G_, (int64_t)g_820E0000 + 13204, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 32008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B448, 0x8326B448) { ctx.r3.u64 = n_sub_8326B448(ctx, base); }

uint64_t n_sub_8326B488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7F0_G_ = int32_t(0x8349C7F0);
	if (!UseLiftedCode(144, 0x8326B488)) { __imp__sub_8326B488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F0_G_, (int64_t)g_820E0000 + 13236, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B488, 0x8326B488) { ctx.r3.u64 = n_sub_8326B488(ctx, base); }

uint64_t n_sub_8326B4C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7F4_G_ = int32_t(0x8349C7F4);
	if (!UseLiftedCode(144, 0x8326B4C8)) { __imp__sub_8326B4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B4C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F4_G_, (int64_t)g_820E0000 + 13264, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B4C8, 0x8326B4C8) { ctx.r3.u64 = n_sub_8326B4C8(ctx, base); }

uint64_t n_sub_8326B508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7F8_G_ = int32_t(0x8349C7F8);
	if (!UseLiftedCode(144, 0x8326B508)) { __imp__sub_8326B508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7F8_G_, (int64_t)g_820E0000 + 13288, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B508, 0x8326B508) { ctx.r3.u64 = n_sub_8326B508(ctx, base); }

uint64_t n_sub_8326B548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C7FC_G_ = int32_t(0x8349C7FC);
	if (!UseLiftedCode(144, 0x8326B548)) { __imp__sub_8326B548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C7FC_G_, (int64_t)g_820E0000 + 13308, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B548, 0x8326B548) { ctx.r3.u64 = n_sub_8326B548(ctx, base); }

uint64_t n_sub_8326B588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C800_G_ = int32_t(0x8349C800);
	if (!UseLiftedCode(144, 0x8326B588)) { __imp__sub_8326B588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C800_G_, (int64_t)g_820E0000 + 13332, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B588, 0x8326B588) { ctx.r3.u64 = n_sub_8326B588(ctx, base); }

uint64_t n_sub_8326B5C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C804_G_ = int32_t(0x8349C804);
	if (!UseLiftedCode(144, 0x8326B5C8)) { __imp__sub_8326B5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B5C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C804_G_, (int64_t)g_820E0000 + 13360, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B5C8, 0x8326B5C8) { ctx.r3.u64 = n_sub_8326B5C8(ctx, base); }

uint64_t n_sub_8326B608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C808_G_ = int32_t(0x8349C808);
	if (!UseLiftedCode(144, 0x8326B608)) { __imp__sub_8326B608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C808_G_, (int64_t)g_820E0000 + 13392, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B608, 0x8326B608) { ctx.r3.u64 = n_sub_8326B608(ctx, base); }

uint64_t n_sub_8326B648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C80C_G_ = int32_t(0x8349C80C);
	if (!UseLiftedCode(144, 0x8326B648)) { __imp__sub_8326B648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C80C_G_, (int64_t)g_820E0000 + 13424, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B648, 0x8326B648) { ctx.r3.u64 = n_sub_8326B648(ctx, base); }

uint64_t n_sub_8326B688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C810_G_ = int32_t(0x8349C810);
	if (!UseLiftedCode(144, 0x8326B688)) { __imp__sub_8326B688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C810_G_, (int64_t)g_820E0000 + 13448, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B688, 0x8326B688) { ctx.r3.u64 = n_sub_8326B688(ctx, base); }

uint64_t n_sub_8326B6C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C814_G_ = int32_t(0x8349C814);
	if (!UseLiftedCode(144, 0x8326B6C8)) { __imp__sub_8326B6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B6C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C814_G_, (int64_t)g_820E0000 + 13468, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B6C8, 0x8326B6C8) { ctx.r3.u64 = n_sub_8326B6C8(ctx, base); }

uint64_t n_sub_8326B708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C818_G_ = int32_t(0x8349C818);
	if (!UseLiftedCode(144, 0x8326B708)) { __imp__sub_8326B708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C818_G_, (int64_t)g_820E0000 + 13496, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B708, 0x8326B708) { ctx.r3.u64 = n_sub_8326B708(ctx, base); }

uint64_t n_sub_8326B748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C81C_G_ = int32_t(0x8349C81C);
	if (!UseLiftedCode(144, 0x8326B748)) { __imp__sub_8326B748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C81C_G_, (int64_t)g_820E0000 + 13520, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B748, 0x8326B748) { ctx.r3.u64 = n_sub_8326B748(ctx, base); }

uint64_t n_sub_8326B788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C820_G_ = int32_t(0x8349C820);
	if (!UseLiftedCode(144, 0x8326B788)) { __imp__sub_8326B788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C820_G_, (int64_t)g_820E0000 + 13544, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B788, 0x8326B788) { ctx.r3.u64 = n_sub_8326B788(ctx, base); }

uint64_t n_sub_8326B7C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C824_G_ = int32_t(0x8349C824);
	if (!UseLiftedCode(144, 0x8326B7C8)) { __imp__sub_8326B7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B7C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C824_G_, (int64_t)g_820E0000 + 13572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B7C8, 0x8326B7C8) { ctx.r3.u64 = n_sub_8326B7C8(ctx, base); }

uint64_t n_sub_8326B808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C828_G_ = int32_t(0x8349C828);
	if (!UseLiftedCode(144, 0x8326B808)) { __imp__sub_8326B808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C828_G_, (int64_t)g_820E0000 + 13600, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B808, 0x8326B808) { ctx.r3.u64 = n_sub_8326B808(ctx, base); }

uint64_t n_sub_8326B848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C82C_G_ = int32_t(0x8349C82C);
	if (!UseLiftedCode(144, 0x8326B848)) { __imp__sub_8326B848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C82C_G_, (int64_t)g_820E0000 + 13624, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B848, 0x8326B848) { ctx.r3.u64 = n_sub_8326B848(ctx, base); }

uint64_t n_sub_8326B888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C830_G_ = int32_t(0x8349C830);
	if (!UseLiftedCode(144, 0x8326B888)) { __imp__sub_8326B888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C830_G_, (int64_t)g_820E0000 + 13656, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B888, 0x8326B888) { ctx.r3.u64 = n_sub_8326B888(ctx, base); }

uint64_t n_sub_8326B8C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C834_G_ = int32_t(0x8349C834);
	if (!UseLiftedCode(144, 0x8326B8C8)) { __imp__sub_8326B8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B8C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C834_G_, (int64_t)g_820E0000 + 13684, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B8C8, 0x8326B8C8) { ctx.r3.u64 = n_sub_8326B8C8(ctx, base); }

uint64_t n_sub_8326B908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C838_G_ = int32_t(0x8349C838);
	if (!UseLiftedCode(144, 0x8326B908)) { __imp__sub_8326B908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C838_G_, (int64_t)g_820E0000 + 13712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B908, 0x8326B908) { ctx.r3.u64 = n_sub_8326B908(ctx, base); }

uint64_t n_sub_8326B948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C83C_G_ = int32_t(0x8349C83C);
	if (!UseLiftedCode(144, 0x8326B948)) { __imp__sub_8326B948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C83C_G_, (int64_t)g_820E0000 + 13744, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B948, 0x8326B948) { ctx.r3.u64 = n_sub_8326B948(ctx, base); }

uint64_t n_sub_8326B988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C840_G_ = int32_t(0x8349C840);
	if (!UseLiftedCode(144, 0x8326B988)) { __imp__sub_8326B988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C840_G_, (int64_t)g_820E0000 + 13776, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B988, 0x8326B988) { ctx.r3.u64 = n_sub_8326B988(ctx, base); }

uint64_t n_sub_8326B9C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C844_G_ = int32_t(0x8349C844);
	if (!UseLiftedCode(144, 0x8326B9C8)) { __imp__sub_8326B9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326B9C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C844_G_, (int64_t)g_820E0000 + 13804, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326B9C8, 0x8326B9C8) { ctx.r3.u64 = n_sub_8326B9C8(ctx, base); }

uint64_t n_sub_8326BA08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C848_G_ = int32_t(0x8349C848);
	if (!UseLiftedCode(144, 0x8326BA08)) { __imp__sub_8326BA08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C848_G_, (int64_t)g_820E0000 + 13832, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BA08, 0x8326BA08) { ctx.r3.u64 = n_sub_8326BA08(ctx, base); }

uint64_t n_sub_8326BA48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C84C_G_ = int32_t(0x8349C84C);
	if (!UseLiftedCode(144, 0x8326BA48)) { __imp__sub_8326BA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C84C_G_, (int64_t)g_820E0000 + 13860, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BA48, 0x8326BA48) { ctx.r3.u64 = n_sub_8326BA48(ctx, base); }

uint64_t n_sub_8326BA88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C850_G_ = int32_t(0x8349C850);
	if (!UseLiftedCode(144, 0x8326BA88)) { __imp__sub_8326BA88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BA88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C850_G_, (int64_t)g_820E0000 + 13892, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BA88, 0x8326BA88) { ctx.r3.u64 = n_sub_8326BA88(ctx, base); }

uint64_t n_sub_8326BAC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C854_G_ = int32_t(0x8349C854);
	if (!UseLiftedCode(144, 0x8326BAC8)) { __imp__sub_8326BAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BAC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C854_G_, (int64_t)g_820E0000 + 13928, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BAC8, 0x8326BAC8) { ctx.r3.u64 = n_sub_8326BAC8(ctx, base); }

uint64_t n_sub_8326BB08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C858_G_ = int32_t(0x8349C858);
	if (!UseLiftedCode(144, 0x8326BB08)) { __imp__sub_8326BB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C858_G_, (int64_t)g_820E0000 + 13948, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BB08, 0x8326BB08) { ctx.r3.u64 = n_sub_8326BB08(ctx, base); }

uint64_t n_sub_8326BB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C85C_G_ = int32_t(0x8349C85C);
	if (!UseLiftedCode(144, 0x8326BB48)) { __imp__sub_8326BB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C85C_G_, (int64_t)g_820E0000 + 13968, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BB48, 0x8326BB48) { ctx.r3.u64 = n_sub_8326BB48(ctx, base); }

uint64_t n_sub_8326BB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C860_G_ = int32_t(0x8349C860);
	if (!UseLiftedCode(144, 0x8326BB88)) { __imp__sub_8326BB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BB88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C860_G_, (int64_t)g_820E0000 + 13988, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BB88, 0x8326BB88) { ctx.r3.u64 = n_sub_8326BB88(ctx, base); }

uint64_t n_sub_8326BBC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C864_G_ = int32_t(0x8349C864);
	if (!UseLiftedCode(144, 0x8326BBC8)) { __imp__sub_8326BBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BBC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C864_G_, (int64_t)g_820E0000 + 14008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BBC8, 0x8326BBC8) { ctx.r3.u64 = n_sub_8326BBC8(ctx, base); }

uint64_t n_sub_8326BC08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C868_G_ = int32_t(0x8349C868);
	if (!UseLiftedCode(144, 0x8326BC08)) { __imp__sub_8326BC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C868_G_, (int64_t)g_820E0000 + 14032, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BC08, 0x8326BC08) { ctx.r3.u64 = n_sub_8326BC08(ctx, base); }

uint64_t n_sub_8326BC48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C86C_G_ = int32_t(0x8349C86C);
	if (!UseLiftedCode(144, 0x8326BC48)) { __imp__sub_8326BC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C86C_G_, (int64_t)g_820E0000 + 14056, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BC48, 0x8326BC48) { ctx.r3.u64 = n_sub_8326BC48(ctx, base); }

uint64_t n_sub_8326BC88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C870_G_ = int32_t(0x8349C870);
	if (!UseLiftedCode(144, 0x8326BC88)) { __imp__sub_8326BC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BC88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C870_G_, (int64_t)g_820E0000 + 14080, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BC88, 0x8326BC88) { ctx.r3.u64 = n_sub_8326BC88(ctx, base); }

uint64_t n_sub_8326BCC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C874_G_ = int32_t(0x8349C874);
	if (!UseLiftedCode(144, 0x8326BCC8)) { __imp__sub_8326BCC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BCC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C874_G_, (int64_t)g_820E0000 + 14104, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BCC8, 0x8326BCC8) { ctx.r3.u64 = n_sub_8326BCC8(ctx, base); }

uint64_t n_sub_8326BD08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C878_G_ = int32_t(0x8349C878);
	if (!UseLiftedCode(144, 0x8326BD08)) { __imp__sub_8326BD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C878_G_, (int64_t)g_820E0000 + 14128, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BD08, 0x8326BD08) { ctx.r3.u64 = n_sub_8326BD08(ctx, base); }

uint64_t n_sub_8326BD48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C87C_G_ = int32_t(0x8349C87C);
	if (!UseLiftedCode(144, 0x8326BD48)) { __imp__sub_8326BD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C87C_G_, (int64_t)g_820E0000 + 14156, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BD48, 0x8326BD48) { ctx.r3.u64 = n_sub_8326BD48(ctx, base); }

uint64_t n_sub_8326BD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C880_G_ = int32_t(0x8349C880);
	if (!UseLiftedCode(144, 0x8326BD88)) { __imp__sub_8326BD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C880_G_, (int64_t)g_820E0000 + 14180, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BD88, 0x8326BD88) { ctx.r3.u64 = n_sub_8326BD88(ctx, base); }

uint64_t n_sub_8326BDC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C884_G_ = int32_t(0x8349C884);
	if (!UseLiftedCode(144, 0x8326BDC8)) { __imp__sub_8326BDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BDC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C884_G_, (int64_t)g_820E0000 + 14212, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BDC8, 0x8326BDC8) { ctx.r3.u64 = n_sub_8326BDC8(ctx, base); }

uint64_t n_sub_8326BE08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C888_G_ = int32_t(0x8349C888);
	if (!UseLiftedCode(144, 0x8326BE08)) { __imp__sub_8326BE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C888_G_, (int64_t)g_820E0000 + 14244, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BE08, 0x8326BE08) { ctx.r3.u64 = n_sub_8326BE08(ctx, base); }

uint64_t n_sub_8326BE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C88C_G_ = int32_t(0x8349C88C);
	if (!UseLiftedCode(144, 0x8326BE48)) { __imp__sub_8326BE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C88C_G_, (int64_t)g_820E0000 + 14268, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BE48, 0x8326BE48) { ctx.r3.u64 = n_sub_8326BE48(ctx, base); }

uint64_t n_sub_8326BE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C890_G_ = int32_t(0x8349C890);
	if (!UseLiftedCode(144, 0x8326BE88)) { __imp__sub_8326BE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BE88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C890_G_, (int64_t)g_820E0000 + 14292, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BE88, 0x8326BE88) { ctx.r3.u64 = n_sub_8326BE88(ctx, base); }

uint64_t n_sub_8326BEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C894_G_ = int32_t(0x8349C894);
	if (!UseLiftedCode(144, 0x8326BEC8)) { __imp__sub_8326BEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C894_G_, (int64_t)g_820E0000 + 14316, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BEC8, 0x8326BEC8) { ctx.r3.u64 = n_sub_8326BEC8(ctx, base); }

uint64_t n_sub_8326BF08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C898_G_ = int32_t(0x8349C898);
	if (!UseLiftedCode(144, 0x8326BF08)) { __imp__sub_8326BF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C898_G_, (int64_t)g_820E0000 + 14356, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BF08, 0x8326BF08) { ctx.r3.u64 = n_sub_8326BF08(ctx, base); }

uint64_t n_sub_8326BF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C89C_G_ = int32_t(0x8349C89C);
	if (!UseLiftedCode(144, 0x8326BF48)) { __imp__sub_8326BF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C89C_G_, (int64_t)g_820E0000 + 14388, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BF48, 0x8326BF48) { ctx.r3.u64 = n_sub_8326BF48(ctx, base); }

uint64_t n_sub_8326BF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8A0_G_ = int32_t(0x8349C8A0);
	if (!UseLiftedCode(144, 0x8326BF88)) { __imp__sub_8326BF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BF88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A0_G_, (int64_t)g_820E0000 + 14416, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BF88, 0x8326BF88) { ctx.r3.u64 = n_sub_8326BF88(ctx, base); }

uint64_t n_sub_8326BFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8A4_G_ = int32_t(0x8349C8A4);
	if (!UseLiftedCode(144, 0x8326BFC8)) { __imp__sub_8326BFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326BFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A4_G_, (int64_t)g_820E0000 + 14444, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326BFC8, 0x8326BFC8) { ctx.r3.u64 = n_sub_8326BFC8(ctx, base); }

uint64_t n_sub_8326C008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8A8_G_ = int32_t(0x8349C8A8);
	if (!UseLiftedCode(144, 0x8326C008)) { __imp__sub_8326C008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8A8_G_, (int64_t)g_820E0000 + 14468, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C008, 0x8326C008) { ctx.r3.u64 = n_sub_8326C008(ctx, base); }

uint64_t n_sub_8326C048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8AC_G_ = int32_t(0x8349C8AC);
	if (!UseLiftedCode(144, 0x8326C048)) { __imp__sub_8326C048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8AC_G_, (int64_t)g_820E0000 + 14488, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C048, 0x8326C048) { ctx.r3.u64 = n_sub_8326C048(ctx, base); }

uint64_t n_sub_8326C088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8B0_G_ = int32_t(0x8349C8B0);
	if (!UseLiftedCode(144, 0x8326C088)) { __imp__sub_8326C088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B0_G_, (int64_t)g_820E0000 + 14516, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C088, 0x8326C088) { ctx.r3.u64 = n_sub_8326C088(ctx, base); }

uint64_t n_sub_8326C0C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8B4_G_ = int32_t(0x8349C8B4);
	if (!UseLiftedCode(144, 0x8326C0C8)) { __imp__sub_8326C0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C0C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B4_G_, (int64_t)g_820E0000 + 14540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C0C8, 0x8326C0C8) { ctx.r3.u64 = n_sub_8326C0C8(ctx, base); }

uint64_t n_sub_8326C108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8B8_G_ = int32_t(0x8349C8B8);
	if (!UseLiftedCode(144, 0x8326C108)) { __imp__sub_8326C108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8B8_G_, (int64_t)g_820E0000 + 14568, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C108, 0x8326C108) { ctx.r3.u64 = n_sub_8326C108(ctx, base); }

uint64_t n_sub_8326C148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8BC_G_ = int32_t(0x8349C8BC);
	if (!UseLiftedCode(144, 0x8326C148)) { __imp__sub_8326C148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8BC_G_, (int64_t)g_820E0000 + 14588, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C148, 0x8326C148) { ctx.r3.u64 = n_sub_8326C148(ctx, base); }

uint64_t n_sub_8326C188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8C0_G_ = int32_t(0x8349C8C0);
	if (!UseLiftedCode(144, 0x8326C188)) { __imp__sub_8326C188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8C0_G_, (int64_t)g_820E0000 + 14600, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C188, 0x8326C188) { ctx.r3.u64 = n_sub_8326C188(ctx, base); }

uint64_t n_sub_8326C1C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C8C4_G_ = int32_t(0x8349C8C4);
	if (!UseLiftedCode(144, 0x8326C1C8)) { __imp__sub_8326C1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C1C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C8C4_G_, (int64_t)g_820E0000 + 14620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C1C8, 0x8326C1C8) { ctx.r3.u64 = n_sub_8326C1C8(ctx, base); }

uint64_t n_sub_8326C6A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C91C_G_ = int32_t(0x8349C91C);
	if (!UseLiftedCode(144, 0x8326C6A0)) { __imp__sub_8326C6A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C6A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C91C_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C6A0, 0x8326C6A0) { ctx.r3.u64 = n_sub_8326C6A0(ctx, base); }

uint64_t n_sub_8326C6E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C920_G_ = int32_t(0x8349C920);
	if (!UseLiftedCode(144, 0x8326C6E0)) { __imp__sub_8326C6E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C6E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C920_G_, (int64_t)g_820E0000 + 14716, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C6E0, 0x8326C6E0) { ctx.r3.u64 = n_sub_8326C6E0(ctx, base); }

uint64_t n_sub_8326C720(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C924_G_ = int32_t(0x8349C924);
	if (!UseLiftedCode(144, 0x8326C720)) { __imp__sub_8326C720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C720);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C924_G_, (int64_t)g_820E0000 + 14768, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C720, 0x8326C720) { ctx.r3.u64 = n_sub_8326C720(ctx, base); }

uint64_t n_sub_8326C760(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C928_G_ = int32_t(0x8349C928);
	if (!UseLiftedCode(144, 0x8326C760)) { __imp__sub_8326C760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C760);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C928_G_, (int64_t)g_820E0000 + 14824, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C760, 0x8326C760) { ctx.r3.u64 = n_sub_8326C760(ctx, base); }

uint64_t n_sub_8326C7A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C92C_G_ = int32_t(0x8349C92C);
	if (!UseLiftedCode(144, 0x8326C7A0)) { __imp__sub_8326C7A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C7A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C92C_G_, (int64_t)g_820E0000 + 14844, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C7A0, 0x8326C7A0) { ctx.r3.u64 = n_sub_8326C7A0(ctx, base); }

uint64_t n_sub_8326C7E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C930_G_ = int32_t(0x8349C930);
	if (!UseLiftedCode(144, 0x8326C7E0)) { __imp__sub_8326C7E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C7E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C930_G_, (int64_t)g_820E0000 + 14860, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C7E0, 0x8326C7E0) { ctx.r3.u64 = n_sub_8326C7E0(ctx, base); }

uint64_t n_sub_8326C820(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C934_G_ = int32_t(0x8349C934);
	if (!UseLiftedCode(144, 0x8326C820)) { __imp__sub_8326C820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326C820);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C934_G_, (int64_t)g_820E0000 + 14876, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326C820, 0x8326C820) { ctx.r3.u64 = n_sub_8326C820(ctx, base); }

uint64_t n_sub_8326CCF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C98C_G_ = int32_t(0x8349C98C);
	if (!UseLiftedCode(144, 0x8326CCF8)) { __imp__sub_8326CCF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CCF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C98C_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CCF8, 0x8326CCF8) { ctx.r3.u64 = n_sub_8326CCF8(ctx, base); }

uint64_t n_sub_8326CD38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C990_G_ = int32_t(0x8349C990);
	if (!UseLiftedCode(144, 0x8326CD38)) { __imp__sub_8326CD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CD38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C990_G_, (int64_t)g_820E0000 + 15516, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 31000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CD38, 0x8326CD38) { ctx.r3.u64 = n_sub_8326CD38(ctx, base); }

uint64_t n_sub_8326CD78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C994_G_ = int32_t(0x8349C994);
	if (!UseLiftedCode(144, 0x8326CD78)) { __imp__sub_8326CD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CD78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C994_G_, (int64_t)g_820E0000 + 15564, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CD78, 0x8326CD78) { ctx.r3.u64 = n_sub_8326CD78(ctx, base); }

uint64_t n_sub_8326CDB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C998_G_ = int32_t(0x8349C998);
	if (!UseLiftedCode(144, 0x8326CDB8)) { __imp__sub_8326CDB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CDB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C998_G_, (int64_t)g_820E0000 + 15620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CDB8, 0x8326CDB8) { ctx.r3.u64 = n_sub_8326CDB8(ctx, base); }

uint64_t n_sub_8326CDF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C99C_G_ = int32_t(0x8349C99C);
	if (!UseLiftedCode(144, 0x8326CDF8)) { __imp__sub_8326CDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CDF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C99C_G_, (int64_t)g_820E0000 + 15664, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CDF8, 0x8326CDF8) { ctx.r3.u64 = n_sub_8326CDF8(ctx, base); }

uint64_t n_sub_8326CE38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C9A0_G_ = int32_t(0x8349C9A0);
	if (!UseLiftedCode(144, 0x8326CE38)) { __imp__sub_8326CE38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CE38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A0_G_, (int64_t)g_820E0000 + 15716, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CE38, 0x8326CE38) { ctx.r3.u64 = n_sub_8326CE38(ctx, base); }

uint64_t n_sub_8326CE78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C9A4_G_ = int32_t(0x8349C9A4);
	if (!UseLiftedCode(144, 0x8326CE78)) { __imp__sub_8326CE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CE78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A4_G_, (int64_t)g_820E0000 + 15776, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CE78, 0x8326CE78) { ctx.r3.u64 = n_sub_8326CE78(ctx, base); }

uint64_t n_sub_8326CEB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C9A8_G_ = int32_t(0x8349C9A8);
	if (!UseLiftedCode(144, 0x8326CEB8)) { __imp__sub_8326CEB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CEB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9A8_G_, (int64_t)g_820E0000 + 15840, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CEB8, 0x8326CEB8) { ctx.r3.u64 = n_sub_8326CEB8(ctx, base); }

uint64_t n_sub_8326CEF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349C9AC_G_ = int32_t(0x8349C9AC);
	if (!UseLiftedCode(144, 0x8326CEF8)) { __imp__sub_8326CEF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326CEF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349C9AC_G_, (int64_t)g_820E0000 + 15900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326CEF8, 0x8326CEF8) { ctx.r3.u64 = n_sub_8326CEF8(ctx, base); }

uint64_t n_sub_8326D3D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CA04_G_ = int32_t(0x8349CA04);
	if (!UseLiftedCode(144, 0x8326D3D0)) { __imp__sub_8326D3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D3D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA04_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326D3D0, 0x8326D3D0) { ctx.r3.u64 = n_sub_8326D3D0(ctx, base); }

uint64_t n_sub_8326D410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CA08_G_ = int32_t(0x8349CA08);
	if (!UseLiftedCode(144, 0x8326D410)) { __imp__sub_8326D410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA08_G_, (int64_t)g_820E0000 + 16056, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326D410, 0x8326D410) { ctx.r3.u64 = n_sub_8326D410(ctx, base); }

uint64_t n_sub_8326D450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CA0C_G_ = int32_t(0x8349CA0C);
	if (!UseLiftedCode(144, 0x8326D450)) { __imp__sub_8326D450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA0C_G_, (int64_t)g_820E0000 + 16116, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326D450, 0x8326D450) { ctx.r3.u64 = n_sub_8326D450(ctx, base); }

uint64_t n_sub_8326D490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CA10_G_ = int32_t(0x8349CA10);
	if (!UseLiftedCode(144, 0x8326D490)) { __imp__sub_8326D490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA10_G_, (int64_t)g_820E0000 + 16176, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326D490, 0x8326D490) { ctx.r3.u64 = n_sub_8326D490(ctx, base); }

uint64_t n_sub_8326D4D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CA14_G_ = int32_t(0x8349CA14);
	if (!UseLiftedCode(144, 0x8326D4D0)) { __imp__sub_8326D4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326D4D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CA14_G_, (int64_t)g_820E0000 + 16252, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326D4D0, 0x8326D4D0) { ctx.r3.u64 = n_sub_8326D4D0(ctx, base); }

uint64_t n_sub_8326DC98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CAEC_G_ = int32_t(0x8349CAEC);
	if (!UseLiftedCode(144, 0x8326DC98)) { __imp__sub_8326DC98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DC98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAEC_G_, (int64_t)g_820E0000 + 16572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326DC98, 0x8326DC98) { ctx.r3.u64 = n_sub_8326DC98(ctx, base); }

uint64_t n_sub_8326DCD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CAF0_G_ = int32_t(0x8349CAF0);
	if (!UseLiftedCode(144, 0x8326DCD8)) { __imp__sub_8326DCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DCD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF0_G_, (int64_t)g_820E0000 + 16628, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326DCD8, 0x8326DCD8) { ctx.r3.u64 = n_sub_8326DCD8(ctx, base); }

uint64_t n_sub_8326DD18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CAF4_G_ = int32_t(0x8349CAF4);
	if (!UseLiftedCode(144, 0x8326DD18)) { __imp__sub_8326DD18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DD18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF4_G_, (int64_t)g_820E0000 + 9852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326DD18, 0x8326DD18) { ctx.r3.u64 = n_sub_8326DD18(ctx, base); }

uint64_t n_sub_8326DD58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CAF8_G_ = int32_t(0x8349CAF8);
	if (!UseLiftedCode(144, 0x8326DD58)) { __imp__sub_8326DD58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326DD58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CAF8_G_, (int64_t)g_820E0000 + 16676, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326DD58, 0x8326DD58) { ctx.r3.u64 = n_sub_8326DD58(ctx, base); }

uint64_t n_sub_8326E230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB50_G_ = int32_t(0x8349CB50);
	if (!UseLiftedCode(144, 0x8326E230)) { __imp__sub_8326E230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB50_G_, (int64_t)g_820E0000 + 16812, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E230, 0x8326E230) { ctx.r3.u64 = n_sub_8326E230(ctx, base); }

uint64_t n_sub_8326E270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB54_G_ = int32_t(0x8349CB54);
	if (!UseLiftedCode(144, 0x8326E270)) { __imp__sub_8326E270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E270);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB54_G_, (int64_t)g_820E0000 + 16812, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E270, 0x8326E270) { ctx.r3.u64 = n_sub_8326E270(ctx, base); }

uint64_t n_sub_8326E2B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB58_G_ = int32_t(0x8349CB58);
	if (!UseLiftedCode(144, 0x8326E2B0)) { __imp__sub_8326E2B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E2B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB58_G_, (int64_t)g_820E0000 + 16880, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E2B0, 0x8326E2B0) { ctx.r3.u64 = n_sub_8326E2B0(ctx, base); }

uint64_t n_sub_8326E2F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB5C_G_ = int32_t(0x8349CB5C);
	if (!UseLiftedCode(144, 0x8326E2F0)) { __imp__sub_8326E2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E2F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB5C_G_, (int64_t)g_820E0000 + 16948, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E2F0, 0x8326E2F0) { ctx.r3.u64 = n_sub_8326E2F0(ctx, base); }

uint64_t n_sub_8326E330(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB60_G_ = int32_t(0x8349CB60);
	if (!UseLiftedCode(144, 0x8326E330)) { __imp__sub_8326E330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E330);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB60_G_, (int64_t)g_820E0000 + 17008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E330, 0x8326E330) { ctx.r3.u64 = n_sub_8326E330(ctx, base); }

uint64_t n_sub_8326E370(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB64_G_ = int32_t(0x8349CB64);
	if (!UseLiftedCode(144, 0x8326E370)) { __imp__sub_8326E370(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E370);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB64_G_, (int64_t)g_820E0000 + 17076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E370, 0x8326E370) { ctx.r3.u64 = n_sub_8326E370(ctx, base); }

uint64_t n_sub_8326E3B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB68_G_ = int32_t(0x8349CB68);
	if (!UseLiftedCode(144, 0x8326E3B0)) { __imp__sub_8326E3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E3B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB68_G_, (int64_t)g_820E0000 + 17136, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E3B0, 0x8326E3B0) { ctx.r3.u64 = n_sub_8326E3B0(ctx, base); }

uint64_t n_sub_8326E3F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB6C_G_ = int32_t(0x8349CB6C);
	if (!UseLiftedCode(144, 0x8326E3F0)) { __imp__sub_8326E3F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E3F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB6C_G_, (int64_t)g_820E0000 + 17208, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E3F0, 0x8326E3F0) { ctx.r3.u64 = n_sub_8326E3F0(ctx, base); }

uint64_t n_sub_8326E430(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB70_G_ = int32_t(0x8349CB70);
	if (!UseLiftedCode(144, 0x8326E430)) { __imp__sub_8326E430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E430);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB70_G_, (int64_t)g_820E0000 + 17272, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E430, 0x8326E430) { ctx.r3.u64 = n_sub_8326E430(ctx, base); }

uint64_t n_sub_8326E470(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB74_G_ = int32_t(0x8349CB74);
	if (!UseLiftedCode(144, 0x8326E470)) { __imp__sub_8326E470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E470);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB74_G_, (int64_t)g_820E0000 + 17340, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E470, 0x8326E470) { ctx.r3.u64 = n_sub_8326E470(ctx, base); }

uint64_t n_sub_8326E4B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CB78_G_ = int32_t(0x8349CB78);
	if (!UseLiftedCode(144, 0x8326E4B0)) { __imp__sub_8326E4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326E4B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CB78_G_, (int64_t)g_820E0000 + 17400, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326E4B0, 0x8326E4B0) { ctx.r3.u64 = n_sub_8326E4B0(ctx, base); }

uint64_t n_sub_8326EA28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CBE4_G_ = int32_t(0x8349CBE4);
	if (!UseLiftedCode(144, 0x8326EA28)) { __imp__sub_8326EA28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EA28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CBE4_G_, (int64_t)g_820E0000 + 17672, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326EA28, 0x8326EA28) { ctx.r3.u64 = n_sub_8326EA28(ctx, base); }

uint64_t n_sub_8326EF00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CC3C_G_ = int32_t(0x8349CC3C);
	if (!UseLiftedCode(144, 0x8326EF00)) { __imp__sub_8326EF00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326EF00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC3C_G_, (int64_t)g_820E0000 + 17756, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326EF00, 0x8326EF00) { ctx.r3.u64 = n_sub_8326EF00(ctx, base); }

uint64_t n_sub_8326F3D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CC94_G_ = int32_t(0x8349CC94);
	if (!UseLiftedCode(144, 0x8326F3D8)) { __imp__sub_8326F3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F3D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC94_G_, (int64_t)g_820E0000 + 17868, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F3D8, 0x8326F3D8) { ctx.r3.u64 = n_sub_8326F3D8(ctx, base); }

uint64_t n_sub_8326F418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CC98_G_ = int32_t(0x8349CC98);
	if (!UseLiftedCode(144, 0x8326F418)) { __imp__sub_8326F418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC98_G_, (int64_t)g_820E0000 + 17916, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F418, 0x8326F418) { ctx.r3.u64 = n_sub_8326F418(ctx, base); }

uint64_t n_sub_8326F458(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CC9C_G_ = int32_t(0x8349CC9C);
	if (!UseLiftedCode(144, 0x8326F458)) { __imp__sub_8326F458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F458);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CC9C_G_, (int64_t)g_820E0000 + 17964, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F458, 0x8326F458) { ctx.r3.u64 = n_sub_8326F458(ctx, base); }

uint64_t n_sub_8326F498(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CCA0_G_ = int32_t(0x8349CCA0);
	if (!UseLiftedCode(144, 0x8326F498)) { __imp__sub_8326F498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F498);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CCA0_G_, (int64_t)g_820E0000 + 18012, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F498, 0x8326F498) { ctx.r3.u64 = n_sub_8326F498(ctx, base); }

uint64_t n_sub_8326F970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CCF8_G_ = int32_t(0x8349CCF8);
	if (!UseLiftedCode(144, 0x8326F970)) { __imp__sub_8326F970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F970);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CCF8_G_, (int64_t)g_820E0000 + 18504, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F970, 0x8326F970) { ctx.r3.u64 = n_sub_8326F970(ctx, base); }

uint64_t n_sub_8326F9F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CD00_G_ = int32_t(0x8349CD00);
	if (!UseLiftedCode(144, 0x8326F9F0)) { __imp__sub_8326F9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326F9F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD00_G_, (int64_t)g_820E0000 + 18548, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326F9F0, 0x8326F9F0) { ctx.r3.u64 = n_sub_8326F9F0(ctx, base); }

uint64_t n_sub_8326FEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CD58_G_ = int32_t(0x8349CD58);
	if (!UseLiftedCode(144, 0x8326FEC8)) { __imp__sub_8326FEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD58_G_, (int64_t)g_820E0000 + 18672, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326FEC8, 0x8326FEC8) { ctx.r3.u64 = n_sub_8326FEC8(ctx, base); }

uint64_t n_sub_8326FF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CD60_G_ = int32_t(0x8349CD60);
	if (!UseLiftedCode(144, 0x8326FF48)) { __imp__sub_8326FF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8326FF48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CD60_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8326FF48, 0x8326FF48) { ctx.r3.u64 = n_sub_8326FF48(ctx, base); }
