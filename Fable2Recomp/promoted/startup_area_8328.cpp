// Start-up initialisers of global objects (they register property and definition names) at
// 0x8328xxxx, as readable C++.
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

uint64_t n_sub_83280008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5DC_G_ = int32_t(0x8349E5DC);
	if (!UseLiftedCode(144, 0x83280008)) { __imp__sub_83280008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5DC_G_, (int64_t)g_820A0000 - 22996, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280008, 0x83280008) { ctx.r3.u64 = n_sub_83280008(ctx, base); }

uint64_t n_sub_83280048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5E0_G_ = int32_t(0x8349E5E0);
	if (!UseLiftedCode(144, 0x83280048)) { __imp__sub_83280048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E0_G_, (int64_t)g_820A0000 - 22944, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280048, 0x83280048) { ctx.r3.u64 = n_sub_83280048(ctx, base); }

uint64_t n_sub_83280088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5E4_G_ = int32_t(0x8349E5E4);
	if (!UseLiftedCode(144, 0x83280088)) { __imp__sub_83280088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E4_G_, (int64_t)g_820A0000 - 22892, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280088, 0x83280088) { ctx.r3.u64 = n_sub_83280088(ctx, base); }

uint64_t n_sub_832800C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5E8_G_ = int32_t(0x8349E5E8);
	if (!UseLiftedCode(144, 0x832800C8)) { __imp__sub_832800C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832800C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5E8_G_, (int64_t)g_820A0000 - 22888, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832800C8, 0x832800C8) { ctx.r3.u64 = n_sub_832800C8(ctx, base); }

uint64_t n_sub_83280108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5EC_G_ = int32_t(0x8349E5EC);
	if (!UseLiftedCode(144, 0x83280108)) { __imp__sub_83280108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5EC_G_, (int64_t)g_820A0000 - 22840, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280108, 0x83280108) { ctx.r3.u64 = n_sub_83280108(ctx, base); }

uint64_t n_sub_83280148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5F0_G_ = int32_t(0x8349E5F0);
	if (!UseLiftedCode(144, 0x83280148)) { __imp__sub_83280148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F0_G_, (int64_t)g_820A0000 - 22824, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280148, 0x83280148) { ctx.r3.u64 = n_sub_83280148(ctx, base); }

uint64_t n_sub_83280188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5F4_G_ = int32_t(0x8349E5F4);
	if (!UseLiftedCode(144, 0x83280188)) { __imp__sub_83280188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F4_G_, (int64_t)g_820A0000 - 22812, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280188, 0x83280188) { ctx.r3.u64 = n_sub_83280188(ctx, base); }

uint64_t n_sub_832801C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5F8_G_ = int32_t(0x8349E5F8);
	if (!UseLiftedCode(144, 0x832801C8)) { __imp__sub_832801C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832801C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5F8_G_, (int64_t)g_820A0000 - 22792, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832801C8, 0x832801C8) { ctx.r3.u64 = n_sub_832801C8(ctx, base); }

uint64_t n_sub_83280208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5FC_G_ = int32_t(0x8349E5FC);
	if (!UseLiftedCode(144, 0x83280208)) { __imp__sub_83280208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5FC_G_, (int64_t)g_820A0000 - 22780, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280208, 0x83280208) { ctx.r3.u64 = n_sub_83280208(ctx, base); }

uint64_t n_sub_83280248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E600_G_ = int32_t(0x8349E600);
	if (!UseLiftedCode(144, 0x83280248)) { __imp__sub_83280248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E600_G_, (int64_t)g_820A0000 - 22764, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280248, 0x83280248) { ctx.r3.u64 = n_sub_83280248(ctx, base); }

uint64_t n_sub_83280288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E604_G_ = int32_t(0x8349E604);
	if (!UseLiftedCode(144, 0x83280288)) { __imp__sub_83280288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E604_G_, (int64_t)g_820A0000 - 23452, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280288, 0x83280288) { ctx.r3.u64 = n_sub_83280288(ctx, base); }

uint64_t n_sub_832802C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E608_G_ = int32_t(0x8349E608);
	if (!UseLiftedCode(144, 0x832802C8)) { __imp__sub_832802C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832802C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E608_G_, (int64_t)g_820A0000 - 23444, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832802C8, 0x832802C8) { ctx.r3.u64 = n_sub_832802C8(ctx, base); }

uint64_t n_sub_83280308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E60C_G_ = int32_t(0x8349E60C);
	if (!UseLiftedCode(144, 0x83280308)) { __imp__sub_83280308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E60C_G_, (int64_t)g_820A0000 - 23424, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280308, 0x83280308) { ctx.r3.u64 = n_sub_83280308(ctx, base); }

uint64_t n_sub_83280348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E610_G_ = int32_t(0x8349E610);
	if (!UseLiftedCode(144, 0x83280348)) { __imp__sub_83280348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E610_G_, (int64_t)g_820A0000 - 23404, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280348, 0x83280348) { ctx.r3.u64 = n_sub_83280348(ctx, base); }

uint64_t n_sub_83280388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E614_G_ = int32_t(0x8349E614);
	if (!UseLiftedCode(144, 0x83280388)) { __imp__sub_83280388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E614_G_, (int64_t)g_820A0000 - 23380, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280388, 0x83280388) { ctx.r3.u64 = n_sub_83280388(ctx, base); }

uint64_t n_sub_832803C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E618_G_ = int32_t(0x8349E618);
	if (!UseLiftedCode(144, 0x832803C8)) { __imp__sub_832803C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832803C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E618_G_, (int64_t)g_820A0000 - 23364, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832803C8, 0x832803C8) { ctx.r3.u64 = n_sub_832803C8(ctx, base); }

uint64_t n_sub_83280408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E61C_G_ = int32_t(0x8349E61C);
	if (!UseLiftedCode(144, 0x83280408)) { __imp__sub_83280408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E61C_G_, (int64_t)g_820A0000 - 23340, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280408, 0x83280408) { ctx.r3.u64 = n_sub_83280408(ctx, base); }

uint64_t n_sub_83280448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E620_G_ = int32_t(0x8349E620);
	if (!UseLiftedCode(144, 0x83280448)) { __imp__sub_83280448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E620_G_, (int64_t)g_820A0000 - 23320, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280448, 0x83280448) { ctx.r3.u64 = n_sub_83280448(ctx, base); }

uint64_t n_sub_83280488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E624_G_ = int32_t(0x8349E624);
	if (!UseLiftedCode(144, 0x83280488)) { __imp__sub_83280488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E624_G_, (int64_t)g_820A0000 - 23300, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280488, 0x83280488) { ctx.r3.u64 = n_sub_83280488(ctx, base); }

uint64_t n_sub_832804C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E628_G_ = int32_t(0x8349E628);
	if (!UseLiftedCode(144, 0x832804C8)) { __imp__sub_832804C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832804C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E628_G_, (int64_t)g_820A0000 - 23284, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832804C8, 0x832804C8) { ctx.r3.u64 = n_sub_832804C8(ctx, base); }

uint64_t n_sub_83280508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E62C_G_ = int32_t(0x8349E62C);
	if (!UseLiftedCode(144, 0x83280508)) { __imp__sub_83280508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E62C_G_, (int64_t)g_820A0000 - 23264, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280508, 0x83280508) { ctx.r3.u64 = n_sub_83280508(ctx, base); }

uint64_t n_sub_83280548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E630_G_ = int32_t(0x8349E630);
	if (!UseLiftedCode(144, 0x83280548)) { __imp__sub_83280548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E630_G_, (int64_t)g_820A0000 - 23244, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280548, 0x83280548) { ctx.r3.u64 = n_sub_83280548(ctx, base); }

uint64_t n_sub_83280588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E634_G_ = int32_t(0x8349E634);
	if (!UseLiftedCode(144, 0x83280588)) { __imp__sub_83280588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E634_G_, (int64_t)g_820A0000 - 23220, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280588, 0x83280588) { ctx.r3.u64 = n_sub_83280588(ctx, base); }

uint64_t n_sub_832805C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E638_G_ = int32_t(0x8349E638);
	if (!UseLiftedCode(144, 0x832805C8)) { __imp__sub_832805C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832805C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E638_G_, (int64_t)g_820A0000 - 23200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832805C8, 0x832805C8) { ctx.r3.u64 = n_sub_832805C8(ctx, base); }

uint64_t n_sub_83280608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E63C_G_ = int32_t(0x8349E63C);
	if (!UseLiftedCode(144, 0x83280608)) { __imp__sub_83280608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E63C_G_, (int64_t)g_820A0000 - 23184, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280608, 0x83280608) { ctx.r3.u64 = n_sub_83280608(ctx, base); }

uint64_t n_sub_83280648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E640_G_ = int32_t(0x8349E640);
	if (!UseLiftedCode(144, 0x83280648)) { __imp__sub_83280648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E640_G_, (int64_t)g_820A0000 - 23528, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280648, 0x83280648) { ctx.r3.u64 = n_sub_83280648(ctx, base); }

uint64_t n_sub_83280688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E644_G_ = int32_t(0x8349E644);
	if (!UseLiftedCode(144, 0x83280688)) { __imp__sub_83280688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E644_G_, (int64_t)g_820A0000 - 23512, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280688, 0x83280688) { ctx.r3.u64 = n_sub_83280688(ctx, base); }

uint64_t n_sub_832806C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E648_G_ = int32_t(0x8349E648);
	if (!UseLiftedCode(144, 0x832806C8)) { __imp__sub_832806C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832806C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E648_G_, (int64_t)g_820A0000 - 23496, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832806C8, 0x832806C8) { ctx.r3.u64 = n_sub_832806C8(ctx, base); }

uint64_t n_sub_83280708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E64C_G_ = int32_t(0x8349E64C);
	if (!UseLiftedCode(144, 0x83280708)) { __imp__sub_83280708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E64C_G_, (int64_t)g_820A0000 - 23492, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280708, 0x83280708) { ctx.r3.u64 = n_sub_83280708(ctx, base); }

uint64_t n_sub_83280748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E650_G_ = int32_t(0x8349E650);
	if (!UseLiftedCode(144, 0x83280748)) { __imp__sub_83280748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E650_G_, (int64_t)g_820A0000 - 23480, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280748, 0x83280748) { ctx.r3.u64 = n_sub_83280748(ctx, base); }

uint64_t n_sub_83280788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E654_G_ = int32_t(0x8349E654);
	if (!UseLiftedCode(144, 0x83280788)) { __imp__sub_83280788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E654_G_, (int64_t)g_820A0000 - 23468, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280788, 0x83280788) { ctx.r3.u64 = n_sub_83280788(ctx, base); }

uint64_t n_sub_832807C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E658_G_ = int32_t(0x8349E658);
	if (!UseLiftedCode(144, 0x832807C8)) { __imp__sub_832807C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832807C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E658_G_, (int64_t)g_820A0000 - 23460, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832807C8, 0x832807C8) { ctx.r3.u64 = n_sub_832807C8(ctx, base); }

uint64_t n_sub_83280808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E65C_G_ = int32_t(0x8349E65C);
	if (!UseLiftedCode(144, 0x83280808)) { __imp__sub_83280808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E65C_G_, (int64_t)g_820A0000 - 23708, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280808, 0x83280808) { ctx.r3.u64 = n_sub_83280808(ctx, base); }

uint64_t n_sub_83280848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E660_G_ = int32_t(0x8349E660);
	if (!UseLiftedCode(144, 0x83280848)) { __imp__sub_83280848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E660_G_, (int64_t)g_820A0000 - 23700, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280848, 0x83280848) { ctx.r3.u64 = n_sub_83280848(ctx, base); }

uint64_t n_sub_83280888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E664_G_ = int32_t(0x8349E664);
	if (!UseLiftedCode(144, 0x83280888)) { __imp__sub_83280888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E664_G_, (int64_t)g_820A0000 - 23680, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280888, 0x83280888) { ctx.r3.u64 = n_sub_83280888(ctx, base); }

uint64_t n_sub_832808C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E668_G_ = int32_t(0x8349E668);
	if (!UseLiftedCode(144, 0x832808C8)) { __imp__sub_832808C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832808C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E668_G_, (int64_t)g_820A0000 - 23660, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832808C8, 0x832808C8) { ctx.r3.u64 = n_sub_832808C8(ctx, base); }

uint64_t n_sub_83280908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E66C_G_ = int32_t(0x8349E66C);
	if (!UseLiftedCode(144, 0x83280908)) { __imp__sub_83280908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E66C_G_, (int64_t)g_820A0000 - 23636, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280908, 0x83280908) { ctx.r3.u64 = n_sub_83280908(ctx, base); }

uint64_t n_sub_83280948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E670_G_ = int32_t(0x8349E670);
	if (!UseLiftedCode(144, 0x83280948)) { __imp__sub_83280948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E670_G_, (int64_t)g_820A0000 - 23612, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280948, 0x83280948) { ctx.r3.u64 = n_sub_83280948(ctx, base); }

uint64_t n_sub_83280988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E674_G_ = int32_t(0x8349E674);
	if (!UseLiftedCode(144, 0x83280988)) { __imp__sub_83280988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E674_G_, (int64_t)g_820A0000 - 23864, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280988, 0x83280988) { ctx.r3.u64 = n_sub_83280988(ctx, base); }

uint64_t n_sub_832809C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E678_G_ = int32_t(0x8349E678);
	if (!UseLiftedCode(144, 0x832809C8)) { __imp__sub_832809C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832809C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E678_G_, (int64_t)g_820A0000 - 23856, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832809C8, 0x832809C8) { ctx.r3.u64 = n_sub_832809C8(ctx, base); }

uint64_t n_sub_83280A08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E67C_G_ = int32_t(0x8349E67C);
	if (!UseLiftedCode(144, 0x83280A08)) { __imp__sub_83280A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E67C_G_, (int64_t)g_820A0000 - 23836, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280A08, 0x83280A08) { ctx.r3.u64 = n_sub_83280A08(ctx, base); }

uint64_t n_sub_83280A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E680_G_ = int32_t(0x8349E680);
	if (!UseLiftedCode(144, 0x83280A48)) { __imp__sub_83280A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E680_G_, (int64_t)g_820A0000 - 23816, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280A48, 0x83280A48) { ctx.r3.u64 = n_sub_83280A48(ctx, base); }

uint64_t n_sub_83280A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E684_G_ = int32_t(0x8349E684);
	if (!UseLiftedCode(144, 0x83280A88)) { __imp__sub_83280A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E684_G_, (int64_t)g_820A0000 - 23796, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280A88, 0x83280A88) { ctx.r3.u64 = n_sub_83280A88(ctx, base); }

uint64_t n_sub_83280AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E688_G_ = int32_t(0x8349E688);
	if (!UseLiftedCode(144, 0x83280AC8)) { __imp__sub_83280AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E688_G_, (int64_t)g_820A0000 - 23772, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280AC8, 0x83280AC8) { ctx.r3.u64 = n_sub_83280AC8(ctx, base); }

uint64_t n_sub_83280B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E68C_G_ = int32_t(0x8349E68C);
	if (!UseLiftedCode(144, 0x83280B08)) { __imp__sub_83280B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E68C_G_, (int64_t)g_820A0000 - 23756, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280B08, 0x83280B08) { ctx.r3.u64 = n_sub_83280B08(ctx, base); }

uint64_t n_sub_83280B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E690_G_ = int32_t(0x8349E690);
	if (!UseLiftedCode(144, 0x83280B48)) { __imp__sub_83280B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E690_G_, (int64_t)g_820A0000 - 23988, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280B48, 0x83280B48) { ctx.r3.u64 = n_sub_83280B48(ctx, base); }

uint64_t n_sub_83280B88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E694_G_ = int32_t(0x8349E694);
	if (!UseLiftedCode(144, 0x83280B88)) { __imp__sub_83280B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280B88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E694_G_, (int64_t)g_820A0000 - 23980, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280B88, 0x83280B88) { ctx.r3.u64 = n_sub_83280B88(ctx, base); }

uint64_t n_sub_83280BC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E698_G_ = int32_t(0x8349E698);
	if (!UseLiftedCode(144, 0x83280BC8)) { __imp__sub_83280BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280BC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E698_G_, (int64_t)g_820A0000 - 23960, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280BC8, 0x83280BC8) { ctx.r3.u64 = n_sub_83280BC8(ctx, base); }

uint64_t n_sub_83280C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E69C_G_ = int32_t(0x8349E69C);
	if (!UseLiftedCode(144, 0x83280C08)) { __imp__sub_83280C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E69C_G_, (int64_t)g_820A0000 - 23940, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280C08, 0x83280C08) { ctx.r3.u64 = n_sub_83280C08(ctx, base); }

uint64_t n_sub_83280C48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6A0_G_ = int32_t(0x8349E6A0);
	if (!UseLiftedCode(144, 0x83280C48)) { __imp__sub_83280C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A0_G_, (int64_t)g_820A0000 - 23916, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280C48, 0x83280C48) { ctx.r3.u64 = n_sub_83280C48(ctx, base); }

uint64_t n_sub_83280C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6A4_G_ = int32_t(0x8349E6A4);
	if (!UseLiftedCode(144, 0x83280C88)) { __imp__sub_83280C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A4_G_, (int64_t)g_820A0000 - 23892, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280C88, 0x83280C88) { ctx.r3.u64 = n_sub_83280C88(ctx, base); }

uint64_t n_sub_83280CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6A8_G_ = int32_t(0x8349E6A8);
	if (!UseLiftedCode(144, 0x83280CC8)) { __imp__sub_83280CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6A8_G_, (int64_t)g_820A0000 - 24160, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280CC8, 0x83280CC8) { ctx.r3.u64 = n_sub_83280CC8(ctx, base); }

uint64_t n_sub_83280D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6AC_G_ = int32_t(0x8349E6AC);
	if (!UseLiftedCode(144, 0x83280D08)) { __imp__sub_83280D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6AC_G_, (int64_t)g_820A0000 - 24152, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280D08, 0x83280D08) { ctx.r3.u64 = n_sub_83280D08(ctx, base); }

uint64_t n_sub_83280D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6B0_G_ = int32_t(0x8349E6B0);
	if (!UseLiftedCode(144, 0x83280D48)) { __imp__sub_83280D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B0_G_, (int64_t)g_820A0000 - 24132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280D48, 0x83280D48) { ctx.r3.u64 = n_sub_83280D48(ctx, base); }

uint64_t n_sub_83280D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6B4_G_ = int32_t(0x8349E6B4);
	if (!UseLiftedCode(144, 0x83280D88)) { __imp__sub_83280D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B4_G_, (int64_t)g_820A0000 - 24112, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280D88, 0x83280D88) { ctx.r3.u64 = n_sub_83280D88(ctx, base); }

uint64_t n_sub_83280DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6B8_G_ = int32_t(0x8349E6B8);
	if (!UseLiftedCode(144, 0x83280DC8)) { __imp__sub_83280DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6B8_G_, (int64_t)g_820A0000 - 24088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280DC8, 0x83280DC8) { ctx.r3.u64 = n_sub_83280DC8(ctx, base); }

uint64_t n_sub_83280E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6BC_G_ = int32_t(0x8349E6BC);
	if (!UseLiftedCode(144, 0x83280E08)) { __imp__sub_83280E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6BC_G_, (int64_t)g_820A0000 - 24064, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280E08, 0x83280E08) { ctx.r3.u64 = n_sub_83280E08(ctx, base); }

uint64_t n_sub_83280E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6C0_G_ = int32_t(0x8349E6C0);
	if (!UseLiftedCode(144, 0x83280E48)) { __imp__sub_83280E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C0_G_, (int64_t)g_820A0000 - 24040, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280E48, 0x83280E48) { ctx.r3.u64 = n_sub_83280E48(ctx, base); }

uint64_t n_sub_83280E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6C4_G_ = int32_t(0x8349E6C4);
	if (!UseLiftedCode(144, 0x83280E88)) { __imp__sub_83280E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C4_G_, (int64_t)g_820A0000 - 24024, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280E88, 0x83280E88) { ctx.r3.u64 = n_sub_83280E88(ctx, base); }

uint64_t n_sub_83280EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6C8_G_ = int32_t(0x8349E6C8);
	if (!UseLiftedCode(144, 0x83280EC8)) { __imp__sub_83280EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6C8_G_, (int64_t)g_820A0000 - 24292, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280EC8, 0x83280EC8) { ctx.r3.u64 = n_sub_83280EC8(ctx, base); }

uint64_t n_sub_83280F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6CC_G_ = int32_t(0x8349E6CC);
	if (!UseLiftedCode(144, 0x83280F08)) { __imp__sub_83280F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6CC_G_, (int64_t)g_820A0000 - 24276, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280F08, 0x83280F08) { ctx.r3.u64 = n_sub_83280F08(ctx, base); }

uint64_t n_sub_83280F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6D0_G_ = int32_t(0x8349E6D0);
	if (!UseLiftedCode(144, 0x83280F48)) { __imp__sub_83280F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D0_G_, (int64_t)g_820A0000 - 24260, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280F48, 0x83280F48) { ctx.r3.u64 = n_sub_83280F48(ctx, base); }

uint64_t n_sub_83280F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6D4_G_ = int32_t(0x8349E6D4);
	if (!UseLiftedCode(144, 0x83280F88)) { __imp__sub_83280F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D4_G_, (int64_t)g_820A0000 - 24240, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280F88, 0x83280F88) { ctx.r3.u64 = n_sub_83280F88(ctx, base); }

uint64_t n_sub_83280FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6D8_G_ = int32_t(0x8349E6D8);
	if (!UseLiftedCode(144, 0x83280FC8)) { __imp__sub_83280FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83280FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6D8_G_, (int64_t)g_820A0000 - 24372, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83280FC8, 0x83280FC8) { ctx.r3.u64 = n_sub_83280FC8(ctx, base); }

uint64_t n_sub_83281008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6DC_G_ = int32_t(0x8349E6DC);
	if (!UseLiftedCode(144, 0x83281008)) { __imp__sub_83281008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6DC_G_, (int64_t)g_820A0000 - 24364, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 20000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281008, 0x83281008) { ctx.r3.u64 = n_sub_83281008(ctx, base); }

uint64_t n_sub_83281048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6E0_G_ = int32_t(0x8349E6E0);
	if (!UseLiftedCode(144, 0x83281048)) { __imp__sub_83281048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E0_G_, (int64_t)g_820A0000 - 24344, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281048, 0x83281048) { ctx.r3.u64 = n_sub_83281048(ctx, base); }

uint64_t n_sub_83281088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6E4_G_ = int32_t(0x8349E6E4);
	if (!UseLiftedCode(144, 0x83281088)) { __imp__sub_83281088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E4_G_, (int64_t)g_820A0000 - 24324, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281088, 0x83281088) { ctx.r3.u64 = n_sub_83281088(ctx, base); }

uint64_t n_sub_832810C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E6E8_G_ = int32_t(0x8349E6E8);
	if (!UseLiftedCode(144, 0x832810C8)) { __imp__sub_832810C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832810C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E6E8_G_, (int64_t)g_820A0000 - 24580, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832810C8, 0x832810C8) { ctx.r3.u64 = n_sub_832810C8(ctx, base); }

uint64_t n_sub_83281108(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x83281108)) { ctx.r8.u64 = arg1; __imp__sub_83281108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281108);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19936, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_83281108, 0x83281108) { ctx.r3.u64 = n_sub_83281108(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281178(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x83281178)) { ctx.r8.u64 = arg1; __imp__sub_83281178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281178);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19784, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_83281178, 0x83281178) { ctx.r3.u64 = n_sub_83281178(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E710 = int32_t(0x8349E710);
	if (!UseLiftedCode(144, 0x83281188)) { __imp__sub_83281188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E710, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281188, 0x83281188) { ctx.r3.u64 = n_sub_83281188(ctx, base); }

uint64_t n_sub_832811C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E714 = int32_t(0x8349E714);
	if (!UseLiftedCode(144, 0x832811C8)) { __imp__sub_832811C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832811C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E714, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832811C8, 0x832811C8) { ctx.r3.u64 = n_sub_832811C8(ctx, base); }

uint64_t n_sub_83281208(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x83281208)) { ctx.r8.u64 = arg1; __imp__sub_83281208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281208);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19664, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_83281208, 0x83281208) { ctx.r3.u64 = n_sub_83281208(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83281288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E734 = int32_t(0x8349E734);
	if (!UseLiftedCode(144, 0x83281288)) { __imp__sub_83281288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E734, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281288, 0x83281288) { ctx.r3.u64 = n_sub_83281288(ctx, base); }

uint64_t n_sub_832812C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E738 = int32_t(0x8349E738);
	if (!UseLiftedCode(144, 0x832812C8)) { __imp__sub_832812C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832812C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E738, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832812C8, 0x832812C8) { ctx.r3.u64 = n_sub_832812C8(ctx, base); }

uint64_t n_sub_83281368(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E750 = int32_t(0x8349E750);
	if (!UseLiftedCode(144, 0x83281368)) { __imp__sub_83281368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83281368);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E750, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83281368, 0x83281368) { ctx.r3.u64 = n_sub_83281368(ctx, base); }

uint64_t n_sub_832813A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E754 = int32_t(0x8349E754);
	if (!UseLiftedCode(144, 0x832813A8)) { __imp__sub_832813A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832813A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E754, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832813A8, 0x832813A8) { ctx.r3.u64 = n_sub_832813A8(ctx, base); }

uint64_t n_sub_83284BB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F478 = int32_t(0x8349F478);
	if (!UseLiftedCode(145, 0x83284BB8)) { __imp__sub_83284BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284BB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F478, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284BB8, 0x83284BB8) { ctx.r3.u64 = n_sub_83284BB8(ctx, base); }

uint64_t n_sub_83284BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F47C = int32_t(0x8349F47C);
	if (!UseLiftedCode(145, 0x83284BF8)) { __imp__sub_83284BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284BF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F47C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284BF8, 0x83284BF8) { ctx.r3.u64 = n_sub_83284BF8(ctx, base); }

uint64_t n_sub_83284C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F480 = int32_t(0x8349F480);
	if (!UseLiftedCode(145, 0x83284C38)) { __imp__sub_83284C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284C38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F480, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284C38, 0x83284C38) { ctx.r3.u64 = n_sub_83284C38(ctx, base); }

uint64_t n_sub_83284C78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F484 = int32_t(0x8349F484);
	if (!UseLiftedCode(145, 0x83284C78)) { __imp__sub_83284C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284C78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F484, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284C78, 0x83284C78) { ctx.r3.u64 = n_sub_83284C78(ctx, base); }

uint64_t n_sub_83284CB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F488 = int32_t(0x8349F488);
	if (!UseLiftedCode(145, 0x83284CB8)) { __imp__sub_83284CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284CB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F488, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284CB8, 0x83284CB8) { ctx.r3.u64 = n_sub_83284CB8(ctx, base); }

uint64_t n_sub_83284CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F48C = int32_t(0x8349F48C);
	if (!UseLiftedCode(145, 0x83284CF8)) { __imp__sub_83284CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F48C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284CF8, 0x83284CF8) { ctx.r3.u64 = n_sub_83284CF8(ctx, base); }

uint64_t n_sub_83284D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F490 = int32_t(0x8349F490);
	if (!UseLiftedCode(145, 0x83284D38)) { __imp__sub_83284D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284D38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F490, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 19000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284D38, 0x83284D38) { ctx.r3.u64 = n_sub_83284D38(ctx, base); }

uint64_t n_sub_83284D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F494 = int32_t(0x8349F494);
	if (!UseLiftedCode(145, 0x83284D78)) { __imp__sub_83284D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F494, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83284D78, 0x83284D78) { ctx.r3.u64 = n_sub_83284D78(ctx, base); }

uint64_t n_sub_83284DB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284DB8)) { ctx.r8.u64 = arg1; __imp__sub_83284DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DB8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18968, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284DB8, 0x83284DB8) { ctx.r3.u64 = n_sub_83284DB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284DC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284DC8)) { ctx.r8.u64 = arg1; __imp__sub_83284DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DC8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18952, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284DC8, 0x83284DC8) { ctx.r3.u64 = n_sub_83284DC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284DD8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284DD8)) { ctx.r8.u64 = arg1; __imp__sub_83284DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284DD8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18864, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284DD8, 0x83284DD8) { ctx.r3.u64 = n_sub_83284DD8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284E98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284E98)) { ctx.r8.u64 = arg1; __imp__sub_83284E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284E98);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18768, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284E98, 0x83284E98) { ctx.r3.u64 = n_sub_83284E98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EA8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284EA8)) { ctx.r8.u64 = arg1; __imp__sub_83284EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EA8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18728, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284EA8, 0x83284EA8) { ctx.r3.u64 = n_sub_83284EA8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284EB8)) { ctx.r8.u64 = arg1; __imp__sub_83284EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EB8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18640, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284EB8, 0x83284EB8) { ctx.r3.u64 = n_sub_83284EB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284EC8)) { ctx.r8.u64 = arg1; __imp__sub_83284EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EC8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18552, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284EC8, 0x83284EC8) { ctx.r3.u64 = n_sub_83284EC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284ED8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284ED8)) { ctx.r8.u64 = arg1; __imp__sub_83284ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284ED8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18464, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284ED8, 0x83284ED8) { ctx.r3.u64 = n_sub_83284ED8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284EE8)) { ctx.r8.u64 = arg1; __imp__sub_83284EE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EE8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18376, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284EE8, 0x83284EE8) { ctx.r3.u64 = n_sub_83284EE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284EF8)) { ctx.r8.u64 = arg1; __imp__sub_83284EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284EF8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18288, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284EF8, 0x83284EF8) { ctx.r3.u64 = n_sub_83284EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F08(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F08)) { ctx.r8.u64 = arg1; __imp__sub_83284F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F08);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18200, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F08, 0x83284F08) { ctx.r3.u64 = n_sub_83284F08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F18)) { ctx.r8.u64 = arg1; __imp__sub_83284F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F18);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 18112, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F18, 0x83284F18) { ctx.r3.u64 = n_sub_83284F18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F60(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F60)) { ctx.r8.u64 = arg1; __imp__sub_83284F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F60);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17984, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F60, 0x83284F60) { ctx.r3.u64 = n_sub_83284F60(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F70(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F70)) { ctx.r8.u64 = arg1; __imp__sub_83284F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F70);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17968, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F70, 0x83284F70) { ctx.r3.u64 = n_sub_83284F70(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F80)) { ctx.r8.u64 = arg1; __imp__sub_83284F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F80);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17952, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F80, 0x83284F80) { ctx.r3.u64 = n_sub_83284F80(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284F90(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284F90)) { ctx.r8.u64 = arg1; __imp__sub_83284F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284F90);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17936, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284F90, 0x83284F90) { ctx.r3.u64 = n_sub_83284F90(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FA0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FA0)) { ctx.r8.u64 = arg1; __imp__sub_83284FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FA0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17920, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FA0, 0x83284FA0) { ctx.r3.u64 = n_sub_83284FA0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FB0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FB0)) { ctx.r8.u64 = arg1; __imp__sub_83284FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FB0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17904, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FB0, 0x83284FB0) { ctx.r3.u64 = n_sub_83284FB0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FC0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FC0)) { ctx.r8.u64 = arg1; __imp__sub_83284FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FC0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17888, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FC0, 0x83284FC0) { ctx.r3.u64 = n_sub_83284FC0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FD0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FD0)) { ctx.r8.u64 = arg1; __imp__sub_83284FD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FD0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17800, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FD0, 0x83284FD0) { ctx.r3.u64 = n_sub_83284FD0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FE0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FE0)) { ctx.r8.u64 = arg1; __imp__sub_83284FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FE0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17704, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FE0, 0x83284FE0) { ctx.r3.u64 = n_sub_83284FE0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83284FF0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83284FF0)) { ctx.r8.u64 = arg1; __imp__sub_83284FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83284FF0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17608, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83284FF0, 0x83284FF0) { ctx.r3.u64 = n_sub_83284FF0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285000(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285000)) { ctx.r8.u64 = arg1; __imp__sub_83285000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285000);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17512, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285000, 0x83285000) { ctx.r3.u64 = n_sub_83285000(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285010(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285010)) { ctx.r8.u64 = arg1; __imp__sub_83285010(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285010);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17424, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285010, 0x83285010) { ctx.r3.u64 = n_sub_83285010(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285020(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285020)) { ctx.r8.u64 = arg1; __imp__sub_83285020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285020);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17336, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285020, 0x83285020) { ctx.r3.u64 = n_sub_83285020(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285030(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285030)) { ctx.r8.u64 = arg1; __imp__sub_83285030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285030);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17320, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285030, 0x83285030) { ctx.r3.u64 = n_sub_83285030(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285040(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285040)) { ctx.r8.u64 = arg1; __imp__sub_83285040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285040);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17304, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285040, 0x83285040) { ctx.r3.u64 = n_sub_83285040(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285050(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285050)) { ctx.r8.u64 = arg1; __imp__sub_83285050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285050);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17288, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285050, 0x83285050) { ctx.r3.u64 = n_sub_83285050(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285060(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285060)) { ctx.r8.u64 = arg1; __imp__sub_83285060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285060);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17272, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285060, 0x83285060) { ctx.r3.u64 = n_sub_83285060(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285070(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285070)) { ctx.r8.u64 = arg1; __imp__sub_83285070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285070);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17256, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285070, 0x83285070) { ctx.r3.u64 = n_sub_83285070(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285150(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285150)) { ctx.r8.u64 = arg1; __imp__sub_83285150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285150);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 17128, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285150, 0x83285150) { ctx.r3.u64 = n_sub_83285150(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285198(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285198)) { ctx.r8.u64 = arg1; __imp__sub_83285198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285198);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16960, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285198, 0x83285198) { ctx.r3.u64 = n_sub_83285198(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832851A8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832851A8)) { ctx.r8.u64 = arg1; __imp__sub_832851A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832851A8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16832, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832851A8, 0x832851A8) { ctx.r3.u64 = n_sub_832851A8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832851B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832851B8)) { ctx.r8.u64 = arg1; __imp__sub_832851B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832851B8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16696, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832851B8, 0x832851B8) { ctx.r3.u64 = n_sub_832851B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F6D0 = int32_t(0x8349F6D0);
	if (!UseLiftedCode(145, 0x83285200)) { __imp__sub_83285200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285200);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F6D0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285200, 0x83285200) { ctx.r3.u64 = n_sub_83285200(ctx, base); }

uint64_t n_sub_83285240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F6D4 = int32_t(0x8349F6D4);
	if (!UseLiftedCode(145, 0x83285240)) { __imp__sub_83285240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285240);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F6D4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285240, 0x83285240) { ctx.r3.u64 = n_sub_83285240(ctx, base); }

uint64_t n_sub_832852A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F6D8_G_ = int32_t(0x8349F6D8);
	if (!UseLiftedCode(145, 0x832852A0)) { __imp__sub_832852A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832852A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6D8_G_, (int64_t)g_820F0000 + 24264, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832852A0, 0x832852A0) { ctx.r3.u64 = n_sub_832852A0(ctx, base); }

uint64_t n_sub_832852E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F6DC_G_ = int32_t(0x8349F6DC);
	if (!UseLiftedCode(145, 0x832852E0)) { __imp__sub_832852E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832852E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6DC_G_, (int64_t)g_820F0000 + 24280, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832852E0, 0x832852E0) { ctx.r3.u64 = n_sub_832852E0(ctx, base); }

uint64_t n_sub_83285320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F6F0_G_ = int32_t(0x8349F6F0);
	if (!UseLiftedCode(145, 0x83285320)) { __imp__sub_83285320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285320);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6F0_G_, (int64_t)g_820F0000 + 24300, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285320, 0x83285320) { ctx.r3.u64 = n_sub_83285320(ctx, base); }

uint64_t n_sub_83285360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F6F4_G_ = int32_t(0x8349F6F4);
	if (!UseLiftedCode(145, 0x83285360)) { __imp__sub_83285360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285360);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F6F4_G_, (int64_t)g_820F0000 + 24312, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285360, 0x83285360) { ctx.r3.u64 = n_sub_83285360(ctx, base); }

uint64_t n_sub_832854A8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854A8)) { ctx.r8.u64 = arg1; __imp__sub_832854A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854A8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16472, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854A8, 0x832854A8) { ctx.r3.u64 = n_sub_832854A8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854B8)) { ctx.r8.u64 = arg1; __imp__sub_832854B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854B8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16384, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854B8, 0x832854B8) { ctx.r3.u64 = n_sub_832854B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854C8)) { ctx.r8.u64 = arg1; __imp__sub_832854C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854C8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16296, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854C8, 0x832854C8) { ctx.r3.u64 = n_sub_832854C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854D8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854D8)) { ctx.r8.u64 = arg1; __imp__sub_832854D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854D8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16208, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854D8, 0x832854D8) { ctx.r3.u64 = n_sub_832854D8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854E8)) { ctx.r8.u64 = arg1; __imp__sub_832854E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854E8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16120, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854E8, 0x832854E8) { ctx.r3.u64 = n_sub_832854E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832854F8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832854F8)) { ctx.r8.u64 = arg1; __imp__sub_832854F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832854F8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 16032, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832854F8, 0x832854F8) { ctx.r3.u64 = n_sub_832854F8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285508(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285508)) { ctx.r8.u64 = arg1; __imp__sub_83285508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285508);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15944, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285508, 0x83285508) { ctx.r3.u64 = n_sub_83285508(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F7A0 = int32_t(0x8349F7A0);
	if (!UseLiftedCode(145, 0x83285570)) { __imp__sub_83285570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285570);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285570, 0x83285570) { ctx.r3.u64 = n_sub_83285570(ctx, base); }

uint64_t n_sub_832855B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F7A4 = int32_t(0x8349F7A4);
	if (!UseLiftedCode(145, 0x832855B0)) { __imp__sub_832855B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832855B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832855B0, 0x832855B0) { ctx.r3.u64 = n_sub_832855B0(ctx, base); }

uint64_t n_sub_832855F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F7A8 = int32_t(0x8349F7A8);
	if (!UseLiftedCode(145, 0x832855F0)) { __imp__sub_832855F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832855F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F7A8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832855F0, 0x832855F0) { ctx.r3.u64 = n_sub_832855F0(ctx, base); }

uint64_t n_sub_83285630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F7AC = int32_t(0x8349F7AC);
	if (!UseLiftedCode(145, 0x83285630)) { __imp__sub_83285630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F7AC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285630, 0x83285630) { ctx.r3.u64 = n_sub_83285630(ctx, base); }

uint64_t n_sub_832857E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832857E0)) { ctx.r8.u64 = arg1; __imp__sub_832857E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832857E0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15472, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832857E0, 0x832857E0) { ctx.r3.u64 = n_sub_832857E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832857F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832857F0)) { ctx.r8.u64 = arg1; __imp__sub_832857F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832857F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15384, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832857F0, 0x832857F0) { ctx.r3.u64 = n_sub_832857F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285800(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285800)) { ctx.r8.u64 = arg1; __imp__sub_83285800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285800);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15304, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285800, 0x83285800) { ctx.r3.u64 = n_sub_83285800(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285810(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285810)) { ctx.r8.u64 = arg1; __imp__sub_83285810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285810);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15224, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285810, 0x83285810) { ctx.r3.u64 = n_sub_83285810(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285820(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285820)) { ctx.r8.u64 = arg1; __imp__sub_83285820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285820);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15184, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285820, 0x83285820) { ctx.r3.u64 = n_sub_83285820(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285830(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285830)) { ctx.r8.u64 = arg1; __imp__sub_83285830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285830);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15016, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285830, 0x83285830) { ctx.r3.u64 = n_sub_83285830(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285840(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F824_G_ = int32_t(0x8349F824);
	if (!UseLiftedCode(145, 0x83285840)) { __imp__sub_83285840(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285840);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F824_G_, (int64_t)g_820F0000 + 24484, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 15008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285840, 0x83285840) { ctx.r3.u64 = n_sub_83285840(ctx, base); }

uint64_t n_sub_83285880(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F828 = int32_t(0x8349F828);
	if (!UseLiftedCode(145, 0x83285880)) { __imp__sub_83285880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285880);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F828, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285880, 0x83285880) { ctx.r3.u64 = n_sub_83285880(ctx, base); }

uint64_t n_sub_832858C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F82C = int32_t(0x8349F82C);
	if (!UseLiftedCode(145, 0x832858C0)) { __imp__sub_832858C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832858C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F82C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832858C0, 0x832858C0) { ctx.r3.u64 = n_sub_832858C0(ctx, base); }

uint64_t n_sub_83285900(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285900)) { ctx.r8.u64 = arg1; __imp__sub_83285900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285900);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14960, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285900, 0x83285900) { ctx.r3.u64 = n_sub_83285900(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F840 = int32_t(0x8349F840);
	if (!UseLiftedCode(145, 0x83285910)) { __imp__sub_83285910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F840, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285910, 0x83285910) { ctx.r3.u64 = n_sub_83285910(ctx, base); }

uint64_t n_sub_83285950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F844 = int32_t(0x8349F844);
	if (!UseLiftedCode(145, 0x83285950)) { __imp__sub_83285950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F844, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285950, 0x83285950) { ctx.r3.u64 = n_sub_83285950(ctx, base); }

uint64_t n_sub_83285A80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285A80)) { ctx.r8.u64 = arg1; __imp__sub_83285A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285A80);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14704, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285A80, 0x83285A80) { ctx.r3.u64 = n_sub_83285A80(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285A90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F870_G_ = int32_t(0x8349F870);
	if (!UseLiftedCode(145, 0x83285A90)) { __imp__sub_83285A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285A90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F870_G_, (int64_t)g_820F0000 + 24584, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285A90, 0x83285A90) { ctx.r3.u64 = n_sub_83285A90(ctx, base); }

uint64_t n_sub_83285AD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349F874_G_ = int32_t(0x8349F874);
	if (!UseLiftedCode(145, 0x83285AD0)) { __imp__sub_83285AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285AD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349F874_G_, (int64_t)g_820F0000 + 24600, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285AD0, 0x83285AD0) { ctx.r3.u64 = n_sub_83285AD0(ctx, base); }

uint64_t n_sub_83285B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F878 = int32_t(0x8349F878);
	if (!UseLiftedCode(145, 0x83285B10)) { __imp__sub_83285B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285B10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F878, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285B10, 0x83285B10) { ctx.r3.u64 = n_sub_83285B10(ctx, base); }

uint64_t n_sub_83285B50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F87C = int32_t(0x8349F87C);
	if (!UseLiftedCode(145, 0x83285B50)) { __imp__sub_83285B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285B50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F87C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285B50, 0x83285B50) { ctx.r3.u64 = n_sub_83285B50(ctx, base); }

uint64_t n_sub_83285BB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F894 = int32_t(0x8349F894);
	if (!UseLiftedCode(145, 0x83285BB8)) { __imp__sub_83285BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285BB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F894, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285BB8, 0x83285BB8) { ctx.r3.u64 = n_sub_83285BB8(ctx, base); }

uint64_t n_sub_83285BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349F898 = int32_t(0x8349F898);
	if (!UseLiftedCode(145, 0x83285BF8)) { __imp__sub_83285BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285BF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_8349F898, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285BF8, 0x83285BF8) { ctx.r3.u64 = n_sub_83285BF8(ctx, base); }

uint64_t n_sub_83285D00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285D00)) { ctx.r8.u64 = arg1; __imp__sub_83285D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D00);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14416, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285D00, 0x83285D00) { ctx.r3.u64 = n_sub_83285D00(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285D10(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83285D10)) { ctx.r8.u64 = arg1; __imp__sub_83285D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D10);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14352, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83285D10, 0x83285D10) { ctx.r3.u64 = n_sub_83285D10(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83285D70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0B9C = int32_t(0x834A0B9C);
	if (!UseLiftedCode(145, 0x83285D70)) { __imp__sub_83285D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285D70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0B9C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285D70, 0x83285D70) { ctx.r3.u64 = n_sub_83285D70(ctx, base); }

uint64_t n_sub_83285DB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0BA0 = int32_t(0x834A0BA0);
	if (!UseLiftedCode(145, 0x83285DB0)) { __imp__sub_83285DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285DB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0BA0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285DB0, 0x83285DB0) { ctx.r3.u64 = n_sub_83285DB0(ctx, base); }

uint64_t n_sub_83285E80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C78 = int32_t(0x834A0C78);
	if (!UseLiftedCode(145, 0x83285E80)) { __imp__sub_83285E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285E80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C78, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285E80, 0x83285E80) { ctx.r3.u64 = n_sub_83285E80(ctx, base); }

uint64_t n_sub_83285EC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C7C = int32_t(0x834A0C7C);
	if (!UseLiftedCode(145, 0x83285EC0)) { __imp__sub_83285EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285EC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C7C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285EC0, 0x83285EC0) { ctx.r3.u64 = n_sub_83285EC0(ctx, base); }

uint64_t n_sub_83285F00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C80 = int32_t(0x834A0C80);
	if (!UseLiftedCode(145, 0x83285F00)) { __imp__sub_83285F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C80, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 14000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285F00, 0x83285F00) { ctx.r3.u64 = n_sub_83285F00(ctx, base); }

uint64_t n_sub_83285F40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C84 = int32_t(0x834A0C84);
	if (!UseLiftedCode(145, 0x83285F40)) { __imp__sub_83285F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C84, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285F40, 0x83285F40) { ctx.r3.u64 = n_sub_83285F40(ctx, base); }

uint64_t n_sub_83285F80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C88 = int32_t(0x834A0C88);
	if (!UseLiftedCode(145, 0x83285F80)) { __imp__sub_83285F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285F80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C88, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285F80, 0x83285F80) { ctx.r3.u64 = n_sub_83285F80(ctx, base); }

uint64_t n_sub_83285FC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C8C = int32_t(0x834A0C8C);
	if (!UseLiftedCode(145, 0x83285FC0)) { __imp__sub_83285FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83285FC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C8C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83285FC0, 0x83285FC0) { ctx.r3.u64 = n_sub_83285FC0(ctx, base); }

uint64_t n_sub_83286000(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C90 = int32_t(0x834A0C90);
	if (!UseLiftedCode(145, 0x83286000)) { __imp__sub_83286000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286000);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C90, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286000, 0x83286000) { ctx.r3.u64 = n_sub_83286000(ctx, base); }

uint64_t n_sub_83286040(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C94 = int32_t(0x834A0C94);
	if (!UseLiftedCode(145, 0x83286040)) { __imp__sub_83286040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C94, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286040, 0x83286040) { ctx.r3.u64 = n_sub_83286040(ctx, base); }

uint64_t n_sub_83286080(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C98 = int32_t(0x834A0C98);
	if (!UseLiftedCode(145, 0x83286080)) { __imp__sub_83286080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286080);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C98, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286080, 0x83286080) { ctx.r3.u64 = n_sub_83286080(ctx, base); }

uint64_t n_sub_832860C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0C9C = int32_t(0x834A0C9C);
	if (!UseLiftedCode(145, 0x832860C0)) { __imp__sub_832860C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832860C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0C9C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832860C0, 0x832860C0) { ctx.r3.u64 = n_sub_832860C0(ctx, base); }

uint64_t n_sub_83286100(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0CA0 = int32_t(0x834A0CA0);
	if (!UseLiftedCode(145, 0x83286100)) { __imp__sub_83286100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286100);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0CA0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286100, 0x83286100) { ctx.r3.u64 = n_sub_83286100(ctx, base); }

uint64_t n_sub_83286140(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0CA4 = int32_t(0x834A0CA4);
	if (!UseLiftedCode(145, 0x83286140)) { __imp__sub_83286140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286140);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0CA4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286140, 0x83286140) { ctx.r3.u64 = n_sub_83286140(ctx, base); }

uint64_t n_sub_83286180(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286180)) { ctx.r8.u64 = arg1; __imp__sub_83286180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286180);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13840, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286180, 0x83286180) { ctx.r3.u64 = n_sub_83286180(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286190(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286190)) { ctx.r8.u64 = arg1; __imp__sub_83286190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286190);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13824, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286190, 0x83286190) { ctx.r3.u64 = n_sub_83286190(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832862A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0D94 = int32_t(0x834A0D94);
	if (!UseLiftedCode(145, 0x832862A0)) { __imp__sub_832862A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832862A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0D94, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832862A0, 0x832862A0) { ctx.r3.u64 = n_sub_832862A0(ctx, base); }

uint64_t n_sub_832862E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0D98 = int32_t(0x834A0D98);
	if (!UseLiftedCode(145, 0x832862E0)) { __imp__sub_832862E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832862E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0D98, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832862E0, 0x832862E0) { ctx.r3.u64 = n_sub_832862E0(ctx, base); }

uint64_t n_sub_83286320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0D9C = int32_t(0x834A0D9C);
	if (!UseLiftedCode(145, 0x83286320)) { __imp__sub_83286320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286320);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0D9C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286320, 0x83286320) { ctx.r3.u64 = n_sub_83286320(ctx, base); }

uint64_t n_sub_83286360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0DA0 = int32_t(0x834A0DA0);
	if (!UseLiftedCode(145, 0x83286360)) { __imp__sub_83286360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286360);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0DA0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286360, 0x83286360) { ctx.r3.u64 = n_sub_83286360(ctx, base); }

uint64_t n_sub_832863A0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832863A0)) { ctx.r8.u64 = arg1; __imp__sub_832863A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863A0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13568, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832863A0, 0x832863A0) { ctx.r3.u64 = n_sub_832863A0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832863B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832863B0)) { ctx.r8.u64 = arg1; __imp__sub_832863B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863B0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13552, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832863B0, 0x832863B0) { ctx.r3.u64 = n_sub_832863B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832863C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832863C0)) { ctx.r8.u64 = arg1; __imp__sub_832863C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863C0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13456, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832863C0, 0x832863C0) { ctx.r3.u64 = n_sub_832863C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832863D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0DAC = int32_t(0x834A0DAC);
	if (!UseLiftedCode(145, 0x832863D0)) { __imp__sub_832863D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832863D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0DAC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832863D0, 0x832863D0) { ctx.r3.u64 = n_sub_832863D0(ctx, base); }

uint64_t n_sub_83286410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0DB0 = int32_t(0x834A0DB0);
	if (!UseLiftedCode(145, 0x83286410)) { __imp__sub_83286410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286410, 0x83286410) { ctx.r3.u64 = n_sub_83286410(ctx, base); }

uint64_t n_sub_83286450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0DB4 = int32_t(0x834A0DB4);
	if (!UseLiftedCode(145, 0x83286450)) { __imp__sub_83286450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286450, 0x83286450) { ctx.r3.u64 = n_sub_83286450(ctx, base); }

uint64_t n_sub_83286490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0DB8 = int32_t(0x834A0DB8);
	if (!UseLiftedCode(145, 0x83286490)) { __imp__sub_83286490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0DB8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286490, 0x83286490) { ctx.r3.u64 = n_sub_83286490(ctx, base); }

uint64_t n_sub_832864D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832864D0)) { ctx.r8.u64 = arg1; __imp__sub_832864D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864D0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13280, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832864D0, 0x832864D0) { ctx.r3.u64 = n_sub_832864D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832864E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832864E0)) { ctx.r8.u64 = arg1; __imp__sub_832864E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864E0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13160, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832864E0, 0x832864E0) { ctx.r3.u64 = n_sub_832864E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832864F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832864F0)) { ctx.r8.u64 = arg1; __imp__sub_832864F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832864F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 13040, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832864F0, 0x832864F0) { ctx.r3.u64 = n_sub_832864F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286500(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286500)) { ctx.r8.u64 = arg1; __imp__sub_83286500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286500);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12920, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286500, 0x83286500) { ctx.r3.u64 = n_sub_83286500(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286510(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286510)) { ctx.r8.u64 = arg1; __imp__sub_83286510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286510);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12800, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286510, 0x83286510) { ctx.r3.u64 = n_sub_83286510(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286520(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286520)) { ctx.r8.u64 = arg1; __imp__sub_83286520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286520);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12680, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286520, 0x83286520) { ctx.r3.u64 = n_sub_83286520(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286530(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286530)) { ctx.r8.u64 = arg1; __imp__sub_83286530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286530);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12560, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286530, 0x83286530) { ctx.r3.u64 = n_sub_83286530(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286540(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286540)) { ctx.r8.u64 = arg1; __imp__sub_83286540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286540);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12440, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286540, 0x83286540) { ctx.r3.u64 = n_sub_83286540(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286550(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286550)) { ctx.r8.u64 = arg1; __imp__sub_83286550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286550);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12320, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286550, 0x83286550) { ctx.r3.u64 = n_sub_83286550(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286560(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286560)) { ctx.r8.u64 = arg1; __imp__sub_83286560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286560);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12200, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286560, 0x83286560) { ctx.r3.u64 = n_sub_83286560(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83286570(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83286570)) { ctx.r8.u64 = arg1; __imp__sub_83286570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286570);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12184, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83286570, 0x83286570) { ctx.r3.u64 = n_sub_83286570(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832865E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E00 = int32_t(0x834A0E00);
	if (!UseLiftedCode(145, 0x832865E0)) { __imp__sub_832865E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832865E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E00, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832865E0, 0x832865E0) { ctx.r3.u64 = n_sub_832865E0(ctx, base); }

uint64_t n_sub_83286620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E04 = int32_t(0x834A0E04);
	if (!UseLiftedCode(145, 0x83286620)) { __imp__sub_83286620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286620);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E04, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286620, 0x83286620) { ctx.r3.u64 = n_sub_83286620(ctx, base); }

uint64_t n_sub_83286660(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E08 = int32_t(0x834A0E08);
	if (!UseLiftedCode(145, 0x83286660)) { __imp__sub_83286660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286660);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E08, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286660, 0x83286660) { ctx.r3.u64 = n_sub_83286660(ctx, base); }

uint64_t n_sub_832866A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E0C = int32_t(0x834A0E0C);
	if (!UseLiftedCode(145, 0x832866A0)) { __imp__sub_832866A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832866A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E0C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 12016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832866A0, 0x832866A0) { ctx.r3.u64 = n_sub_832866A0(ctx, base); }

uint64_t n_sub_83286758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E4C = int32_t(0x834A0E4C);
	if (!UseLiftedCode(145, 0x83286758)) { __imp__sub_83286758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E4C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286758, 0x83286758) { ctx.r3.u64 = n_sub_83286758(ctx, base); }

uint64_t n_sub_83286798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0E50 = int32_t(0x834A0E50);
	if (!UseLiftedCode(145, 0x83286798)) { __imp__sub_83286798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0E50, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286798, 0x83286798) { ctx.r3.u64 = n_sub_83286798(ctx, base); }

uint64_t n_sub_832868B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0EF4 = int32_t(0x834A0EF4);
	if (!UseLiftedCode(145, 0x832868B0)) { __imp__sub_832868B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832868B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0EF4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832868B0, 0x832868B0) { ctx.r3.u64 = n_sub_832868B0(ctx, base); }

uint64_t n_sub_832868F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0EF8 = int32_t(0x834A0EF8);
	if (!UseLiftedCode(145, 0x832868F0)) { __imp__sub_832868F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832868F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0EF8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832868F0, 0x832868F0) { ctx.r3.u64 = n_sub_832868F0(ctx, base); }

uint64_t n_sub_83286998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0F60 = int32_t(0x834A0F60);
	if (!UseLiftedCode(145, 0x83286998)) { __imp__sub_83286998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0F60, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286998, 0x83286998) { ctx.r3.u64 = n_sub_83286998(ctx, base); }

uint64_t n_sub_832869D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0F64 = int32_t(0x834A0F64);
	if (!UseLiftedCode(145, 0x832869D8)) { __imp__sub_832869D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832869D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0F64, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832869D8, 0x832869D8) { ctx.r3.u64 = n_sub_832869D8(ctx, base); }

uint64_t n_sub_83286BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0FE8 = int32_t(0x834A0FE8);
	if (!UseLiftedCode(145, 0x83286BE8)) { __imp__sub_83286BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286BE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0FE8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286BE8, 0x83286BE8) { ctx.r3.u64 = n_sub_83286BE8(ctx, base); }

uint64_t n_sub_83286C28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A0FEC = int32_t(0x834A0FEC);
	if (!UseLiftedCode(145, 0x83286C28)) { __imp__sub_83286C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A0FEC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286C28, 0x83286C28) { ctx.r3.u64 = n_sub_83286C28(ctx, base); }

uint64_t n_sub_83286C68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A3FF0 = int32_t(0x834A3FF0);
	if (!UseLiftedCode(145, 0x83286C68)) { __imp__sub_83286C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286C68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A3FF0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286C68, 0x83286C68) { ctx.r3.u64 = n_sub_83286C68(ctx, base); }

uint64_t n_sub_83286CA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A3FF4 = int32_t(0x834A3FF4);
	if (!UseLiftedCode(145, 0x83286CA8)) { __imp__sub_83286CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286CA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A3FF4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286CA8, 0x83286CA8) { ctx.r3.u64 = n_sub_83286CA8(ctx, base); }

uint64_t n_sub_83286D70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4070 = int32_t(0x834A4070);
	if (!UseLiftedCode(145, 0x83286D70)) { __imp__sub_83286D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286D70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4070, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286D70, 0x83286D70) { ctx.r3.u64 = n_sub_83286D70(ctx, base); }

uint64_t n_sub_83286DB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4074 = int32_t(0x834A4074);
	if (!UseLiftedCode(145, 0x83286DB0)) { __imp__sub_83286DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286DB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4074, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286DB0, 0x83286DB0) { ctx.r3.u64 = n_sub_83286DB0(ctx, base); }

uint64_t n_sub_83286DF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4078 = int32_t(0x834A4078);
	if (!UseLiftedCode(145, 0x83286DF0)) { __imp__sub_83286DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286DF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4078, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286DF0, 0x83286DF0) { ctx.r3.u64 = n_sub_83286DF0(ctx, base); }

uint64_t n_sub_83286E30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A407C = int32_t(0x834A407C);
	if (!UseLiftedCode(145, 0x83286E30)) { __imp__sub_83286E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286E30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A407C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286E30, 0x83286E30) { ctx.r3.u64 = n_sub_83286E30(ctx, base); }

uint64_t n_sub_83286E98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4090 = int32_t(0x834A4090);
	if (!UseLiftedCode(145, 0x83286E98)) { __imp__sub_83286E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286E98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4090, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286E98, 0x83286E98) { ctx.r3.u64 = n_sub_83286E98(ctx, base); }

uint64_t n_sub_83286ED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4094 = int32_t(0x834A4094);
	if (!UseLiftedCode(145, 0x83286ED8)) { __imp__sub_83286ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286ED8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4094, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286ED8, 0x83286ED8) { ctx.r3.u64 = n_sub_83286ED8(ctx, base); }

uint64_t n_sub_83286F18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4098 = int32_t(0x834A4098);
	if (!UseLiftedCode(145, 0x83286F18)) { __imp__sub_83286F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4098, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286F18, 0x83286F18) { ctx.r3.u64 = n_sub_83286F18(ctx, base); }

uint64_t n_sub_83286F58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A409C = int32_t(0x834A409C);
	if (!UseLiftedCode(145, 0x83286F58)) { __imp__sub_83286F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A409C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286F58, 0x83286F58) { ctx.r3.u64 = n_sub_83286F58(ctx, base); }

uint64_t n_sub_83286F98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40A0 = int32_t(0x834A40A0);
	if (!UseLiftedCode(145, 0x83286F98)) { __imp__sub_83286F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286F98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40A0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286F98, 0x83286F98) { ctx.r3.u64 = n_sub_83286F98(ctx, base); }

uint64_t n_sub_83286FD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40A4 = int32_t(0x834A40A4);
	if (!UseLiftedCode(145, 0x83286FD8)) { __imp__sub_83286FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83286FD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40A4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83286FD8, 0x83286FD8) { ctx.r3.u64 = n_sub_83286FD8(ctx, base); }

uint64_t n_sub_83287018(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40A8 = int32_t(0x834A40A8);
	if (!UseLiftedCode(145, 0x83287018)) { __imp__sub_83287018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287018);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40A8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287018, 0x83287018) { ctx.r3.u64 = n_sub_83287018(ctx, base); }

uint64_t n_sub_83287058(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40AC = int32_t(0x834A40AC);
	if (!UseLiftedCode(145, 0x83287058)) { __imp__sub_83287058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287058);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40AC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287058, 0x83287058) { ctx.r3.u64 = n_sub_83287058(ctx, base); }

uint64_t n_sub_83287098(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40B0 = int32_t(0x834A40B0);
	if (!UseLiftedCode(145, 0x83287098)) { __imp__sub_83287098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287098);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40B0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287098, 0x83287098) { ctx.r3.u64 = n_sub_83287098(ctx, base); }

uint64_t n_sub_832870D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40B4 = int32_t(0x834A40B4);
	if (!UseLiftedCode(145, 0x832870D8)) { __imp__sub_832870D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832870D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40B4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832870D8, 0x832870D8) { ctx.r3.u64 = n_sub_832870D8(ctx, base); }

uint64_t n_sub_83287118(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40B8 = int32_t(0x834A40B8);
	if (!UseLiftedCode(145, 0x83287118)) { __imp__sub_83287118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287118);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40B8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287118, 0x83287118) { ctx.r3.u64 = n_sub_83287118(ctx, base); }

uint64_t n_sub_83287158(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40BC = int32_t(0x834A40BC);
	if (!UseLiftedCode(145, 0x83287158)) { __imp__sub_83287158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287158);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40BC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287158, 0x83287158) { ctx.r3.u64 = n_sub_83287158(ctx, base); }

uint64_t n_sub_83287198(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40C0 = int32_t(0x834A40C0);
	if (!UseLiftedCode(145, 0x83287198)) { __imp__sub_83287198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287198);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40C0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287198, 0x83287198) { ctx.r3.u64 = n_sub_83287198(ctx, base); }

uint64_t n_sub_832871D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40C4 = int32_t(0x834A40C4);
	if (!UseLiftedCode(145, 0x832871D8)) { __imp__sub_832871D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832871D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40C4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 11008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832871D8, 0x832871D8) { ctx.r3.u64 = n_sub_832871D8(ctx, base); }

uint64_t n_sub_83287218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40C8 = int32_t(0x834A40C8);
	if (!UseLiftedCode(145, 0x83287218)) { __imp__sub_83287218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287218);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40C8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287218, 0x83287218) { ctx.r3.u64 = n_sub_83287218(ctx, base); }

uint64_t n_sub_83287258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40CC = int32_t(0x834A40CC);
	if (!UseLiftedCode(145, 0x83287258)) { __imp__sub_83287258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40CC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287258, 0x83287258) { ctx.r3.u64 = n_sub_83287258(ctx, base); }

uint64_t n_sub_83287298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40D0 = int32_t(0x834A40D0);
	if (!UseLiftedCode(145, 0x83287298)) { __imp__sub_83287298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40D0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287298, 0x83287298) { ctx.r3.u64 = n_sub_83287298(ctx, base); }

uint64_t n_sub_832872D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A40D4 = int32_t(0x834A40D4);
	if (!UseLiftedCode(145, 0x832872D8)) { __imp__sub_832872D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832872D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A40D4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832872D8, 0x832872D8) { ctx.r3.u64 = n_sub_832872D8(ctx, base); }

uint64_t n_sub_83287358(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287358)) { ctx.r8.u64 = arg1; __imp__sub_83287358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287358);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10840, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287358, 0x83287358) { ctx.r3.u64 = n_sub_83287358(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287368(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A412C = int32_t(0x834A412C);
	if (!UseLiftedCode(145, 0x83287368)) { __imp__sub_83287368(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287368);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A412C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287368, 0x83287368) { ctx.r3.u64 = n_sub_83287368(ctx, base); }

uint64_t n_sub_832873A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4130 = int32_t(0x834A4130);
	if (!UseLiftedCode(145, 0x832873A8)) { __imp__sub_832873A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832873A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4130, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832873A8, 0x832873A8) { ctx.r3.u64 = n_sub_832873A8(ctx, base); }

uint64_t n_sub_83287438(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287438)) { ctx.r8.u64 = arg1; __imp__sub_83287438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287438);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10640, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287438, 0x83287438) { ctx.r3.u64 = n_sub_83287438(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A416C = int32_t(0x834A416C);
	if (!UseLiftedCode(145, 0x83287448)) { __imp__sub_83287448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A416C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287448, 0x83287448) { ctx.r3.u64 = n_sub_83287448(ctx, base); }

uint64_t n_sub_83287488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4170 = int32_t(0x834A4170);
	if (!UseLiftedCode(145, 0x83287488)) { __imp__sub_83287488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4170, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287488, 0x83287488) { ctx.r3.u64 = n_sub_83287488(ctx, base); }

uint64_t n_sub_83287518(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A419C = int32_t(0x834A419C);
	if (!UseLiftedCode(145, 0x83287518)) { __imp__sub_83287518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287518);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A419C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287518, 0x83287518) { ctx.r3.u64 = n_sub_83287518(ctx, base); }

uint64_t n_sub_83287558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A41A0 = int32_t(0x834A41A0);
	if (!UseLiftedCode(145, 0x83287558)) { __imp__sub_83287558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A41A0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287558, 0x83287558) { ctx.r3.u64 = n_sub_83287558(ctx, base); }

uint64_t n_sub_83287660(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287660)) { ctx.r8.u64 = arg1; __imp__sub_83287660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287660);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10248, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287660, 0x83287660) { ctx.r3.u64 = n_sub_83287660(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287670(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287670)) { ctx.r8.u64 = arg1; __imp__sub_83287670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287670);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10128, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287670, 0x83287670) { ctx.r3.u64 = n_sub_83287670(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287680(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4AE0 = int32_t(0x834A4AE0);
	if (!UseLiftedCode(145, 0x83287680)) { __imp__sub_83287680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287680);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4AE0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287680, 0x83287680) { ctx.r3.u64 = n_sub_83287680(ctx, base); }

uint64_t n_sub_832876C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4AE4 = int32_t(0x834A4AE4);
	if (!UseLiftedCode(145, 0x832876C0)) { __imp__sub_832876C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832876C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4AE4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832876C0, 0x832876C0) { ctx.r3.u64 = n_sub_832876C0(ctx, base); }

uint64_t n_sub_832877B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832877B8)) { ctx.r8.u64 = arg1; __imp__sub_832877B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877B8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 10080, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832877B8, 0x832877B8) { ctx.r3.u64 = n_sub_832877B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832877C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832877C8)) { ctx.r8.u64 = arg1; __imp__sub_832877C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877C8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9984, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832877C8, 0x832877C8) { ctx.r3.u64 = n_sub_832877C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832877D8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832877D8)) { ctx.r8.u64 = arg1; __imp__sub_832877D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832877D8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9888, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832877D8, 0x832877D8) { ctx.r3.u64 = n_sub_832877D8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287860(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4B98 = int32_t(0x834A4B98);
	if (!UseLiftedCode(145, 0x83287860)) { __imp__sub_83287860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287860);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4B98, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287860, 0x83287860) { ctx.r3.u64 = n_sub_83287860(ctx, base); }

uint64_t n_sub_832878A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4B9C = int32_t(0x834A4B9C);
	if (!UseLiftedCode(145, 0x832878A0)) { __imp__sub_832878A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4B9C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832878A0, 0x832878A0) { ctx.r3.u64 = n_sub_832878A0(ctx, base); }

uint64_t n_sub_832878E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832878E0)) { ctx.r8.u64 = arg1; __imp__sub_832878E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878E0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9680, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832878E0, 0x832878E0) { ctx.r3.u64 = n_sub_832878E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832878F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832878F0)) { ctx.r8.u64 = arg1; __imp__sub_832878F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832878F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9592, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832878F0, 0x832878F0) { ctx.r3.u64 = n_sub_832878F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287900(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287900)) { ctx.r8.u64 = arg1; __imp__sub_83287900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287900);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9504, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287900, 0x83287900) { ctx.r3.u64 = n_sub_83287900(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4BD0 = int32_t(0x834A4BD0);
	if (!UseLiftedCode(145, 0x83287910)) { __imp__sub_83287910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4BD0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287910, 0x83287910) { ctx.r3.u64 = n_sub_83287910(ctx, base); }

uint64_t n_sub_83287950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4BD4 = int32_t(0x834A4BD4);
	if (!UseLiftedCode(145, 0x83287950)) { __imp__sub_83287950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4BD4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287950, 0x83287950) { ctx.r3.u64 = n_sub_83287950(ctx, base); }

uint64_t n_sub_83287990(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287990)) { ctx.r8.u64 = arg1; __imp__sub_83287990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287990);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 9384, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287990, 0x83287990) { ctx.r3.u64 = n_sub_83287990(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287BF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4C20 = int32_t(0x834A4C20);
	if (!UseLiftedCode(145, 0x83287BF0)) { __imp__sub_83287BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287BF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4C20, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287BF0, 0x83287BF0) { ctx.r3.u64 = n_sub_83287BF0(ctx, base); }

uint64_t n_sub_83287C30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4C24 = int32_t(0x834A4C24);
	if (!UseLiftedCode(145, 0x83287C30)) { __imp__sub_83287C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287C30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4C24, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83287C30, 0x83287C30) { ctx.r3.u64 = n_sub_83287C30(ctx, base); }

uint64_t n_sub_83287EB8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287EB8)) { ctx.r8.u64 = arg1; __imp__sub_83287EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EB8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8936, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287EB8, 0x83287EB8) { ctx.r3.u64 = n_sub_83287EB8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287EC8)) { ctx.r8.u64 = arg1; __imp__sub_83287EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EC8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8872, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287EC8, 0x83287EC8) { ctx.r3.u64 = n_sub_83287EC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287ED8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287ED8)) { ctx.r8.u64 = arg1; __imp__sub_83287ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287ED8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8808, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287ED8, 0x83287ED8) { ctx.r3.u64 = n_sub_83287ED8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287EE8)) { ctx.r8.u64 = arg1; __imp__sub_83287EE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EE8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8744, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287EE8, 0x83287EE8) { ctx.r3.u64 = n_sub_83287EE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287EF8)) { ctx.r8.u64 = arg1; __imp__sub_83287EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287EF8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8680, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287EF8, 0x83287EF8) { ctx.r3.u64 = n_sub_83287EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83287F30(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83287F30)) { ctx.r8.u64 = arg1; __imp__sub_83287F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83287F30);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8592, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83287F30, 0x83287F30) { ctx.r3.u64 = n_sub_83287F30(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4D34 = int32_t(0x834A4D34);
	if (!UseLiftedCode(145, 0x83288210)) { __imp__sub_83288210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4D34, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288210, 0x83288210) { ctx.r3.u64 = n_sub_83288210(ctx, base); }

uint64_t n_sub_83288250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4D38 = int32_t(0x834A4D38);
	if (!UseLiftedCode(145, 0x83288250)) { __imp__sub_83288250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4D38, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288250, 0x83288250) { ctx.r3.u64 = n_sub_83288250(ctx, base); }

uint64_t n_sub_83288490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4E30 = int32_t(0x834A4E30);
	if (!UseLiftedCode(145, 0x83288490)) { __imp__sub_83288490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4E30, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288490, 0x83288490) { ctx.r3.u64 = n_sub_83288490(ctx, base); }

uint64_t n_sub_832884D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A4E34 = int32_t(0x834A4E34);
	if (!UseLiftedCode(145, 0x832884D0)) { __imp__sub_832884D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832884D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A4E34, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832884D0, 0x832884D0) { ctx.r3.u64 = n_sub_832884D0(ctx, base); }

uint64_t n_sub_83288598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5240 = int32_t(0x834A5240);
	if (!UseLiftedCode(145, 0x83288598)) { __imp__sub_83288598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5240, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288598, 0x83288598) { ctx.r3.u64 = n_sub_83288598(ctx, base); }

uint64_t n_sub_832885D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5244 = int32_t(0x834A5244);
	if (!UseLiftedCode(145, 0x832885D8)) { __imp__sub_832885D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832885D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5244, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832885D8, 0x832885D8) { ctx.r3.u64 = n_sub_832885D8(ctx, base); }

uint64_t n_sub_83288618(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288618)) { ctx.r8.u64 = arg1; __imp__sub_83288618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288618);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8304, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288618, 0x83288618) { ctx.r3.u64 = n_sub_83288618(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288628(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5258 = int32_t(0x834A5258);
	if (!UseLiftedCode(145, 0x83288628)) { __imp__sub_83288628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288628);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5258, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288628, 0x83288628) { ctx.r3.u64 = n_sub_83288628(ctx, base); }

uint64_t n_sub_83288668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A525C = int32_t(0x834A525C);
	if (!UseLiftedCode(145, 0x83288668)) { __imp__sub_83288668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A525C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288668, 0x83288668) { ctx.r3.u64 = n_sub_83288668(ctx, base); }

uint64_t n_sub_832886A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5260 = int32_t(0x834A5260);
	if (!UseLiftedCode(145, 0x832886A8)) { __imp__sub_832886A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832886A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5260, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832886A8, 0x832886A8) { ctx.r3.u64 = n_sub_832886A8(ctx, base); }

uint64_t n_sub_832886E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5264 = int32_t(0x834A5264);
	if (!UseLiftedCode(145, 0x832886E8)) { __imp__sub_832886E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832886E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5264, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832886E8, 0x832886E8) { ctx.r3.u64 = n_sub_832886E8(ctx, base); }

uint64_t n_sub_832887B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52E0 = int32_t(0x834A52E0);
	if (!UseLiftedCode(145, 0x832887B8)) { __imp__sub_832887B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832887B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52E0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832887B8, 0x832887B8) { ctx.r3.u64 = n_sub_832887B8(ctx, base); }

uint64_t n_sub_832887F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52E4 = int32_t(0x834A52E4);
	if (!UseLiftedCode(145, 0x832887F8)) { __imp__sub_832887F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832887F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52E4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 8000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832887F8, 0x832887F8) { ctx.r3.u64 = n_sub_832887F8(ctx, base); }

uint64_t n_sub_83288838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52E8 = int32_t(0x834A52E8);
	if (!UseLiftedCode(145, 0x83288838)) { __imp__sub_83288838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52E8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288838, 0x83288838) { ctx.r3.u64 = n_sub_83288838(ctx, base); }

uint64_t n_sub_83288878(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52EC = int32_t(0x834A52EC);
	if (!UseLiftedCode(145, 0x83288878)) { __imp__sub_83288878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52EC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288878, 0x83288878) { ctx.r3.u64 = n_sub_83288878(ctx, base); }

uint64_t n_sub_832888B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52F0 = int32_t(0x834A52F0);
	if (!UseLiftedCode(145, 0x832888B8)) { __imp__sub_832888B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832888B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52F0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832888B8, 0x832888B8) { ctx.r3.u64 = n_sub_832888B8(ctx, base); }

uint64_t n_sub_832888F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A52F4 = int32_t(0x834A52F4);
	if (!UseLiftedCode(145, 0x832888F8)) { __imp__sub_832888F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832888F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A52F4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832888F8, 0x832888F8) { ctx.r3.u64 = n_sub_832888F8(ctx, base); }

uint64_t n_sub_83288B78(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288B78)) { ctx.r8.u64 = arg1; __imp__sub_83288B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B78);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7488, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288B78, 0x83288B78) { ctx.r3.u64 = n_sub_83288B78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288B88(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288B88)) { ctx.r8.u64 = arg1; __imp__sub_83288B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B88);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7400, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288B88, 0x83288B88) { ctx.r3.u64 = n_sub_83288B88(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288B98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288B98)) { ctx.r8.u64 = arg1; __imp__sub_83288B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288B98);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7384, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288B98, 0x83288B98) { ctx.r3.u64 = n_sub_83288B98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288BA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A534C = int32_t(0x834A534C);
	if (!UseLiftedCode(145, 0x83288BA8)) { __imp__sub_83288BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288BA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A534C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288BA8, 0x83288BA8) { ctx.r3.u64 = n_sub_83288BA8(ctx, base); }

uint64_t n_sub_83288BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5350 = int32_t(0x834A5350);
	if (!UseLiftedCode(145, 0x83288BE8)) { __imp__sub_83288BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288BE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5350, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288BE8, 0x83288BE8) { ctx.r3.u64 = n_sub_83288BE8(ctx, base); }

uint64_t n_sub_83288C28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5354 = int32_t(0x834A5354);
	if (!UseLiftedCode(145, 0x83288C28)) { __imp__sub_83288C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5354, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288C28, 0x83288C28) { ctx.r3.u64 = n_sub_83288C28(ctx, base); }

uint64_t n_sub_83288C68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5358 = int32_t(0x834A5358);
	if (!UseLiftedCode(145, 0x83288C68)) { __imp__sub_83288C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288C68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5358, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288C68, 0x83288C68) { ctx.r3.u64 = n_sub_83288C68(ctx, base); }

uint64_t n_sub_83288CA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A535C = int32_t(0x834A535C);
	if (!UseLiftedCode(145, 0x83288CA8)) { __imp__sub_83288CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288CA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A535C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288CA8, 0x83288CA8) { ctx.r3.u64 = n_sub_83288CA8(ctx, base); }

uint64_t n_sub_83288CE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5360 = int32_t(0x834A5360);
	if (!UseLiftedCode(145, 0x83288CE8)) { __imp__sub_83288CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288CE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5360, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288CE8, 0x83288CE8) { ctx.r3.u64 = n_sub_83288CE8(ctx, base); }

uint64_t n_sub_83288D28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288D28)) { ctx.r8.u64 = arg1; __imp__sub_83288D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D28);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7272, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288D28, 0x83288D28) { ctx.r3.u64 = n_sub_83288D28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288D38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288D38)) { ctx.r8.u64 = arg1; __imp__sub_83288D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D38);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7256, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288D38, 0x83288D38) { ctx.r3.u64 = n_sub_83288D38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288D48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83288D48)) { ctx.r8.u64 = arg1; __imp__sub_83288D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D48);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7240, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83288D48, 0x83288D48) { ctx.r3.u64 = n_sub_83288D48(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83288D90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53A0 = int32_t(0x834A53A0);
	if (!UseLiftedCode(145, 0x83288D90)) { __imp__sub_83288D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288D90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53A0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288D90, 0x83288D90) { ctx.r3.u64 = n_sub_83288D90(ctx, base); }

uint64_t n_sub_83288DD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53A4 = int32_t(0x834A53A4);
	if (!UseLiftedCode(145, 0x83288DD0)) { __imp__sub_83288DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288DD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53A4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288DD0, 0x83288DD0) { ctx.r3.u64 = n_sub_83288DD0(ctx, base); }

uint64_t n_sub_83288E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53BC = int32_t(0x834A53BC);
	if (!UseLiftedCode(145, 0x83288E38)) { __imp__sub_83288E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53BC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288E38, 0x83288E38) { ctx.r3.u64 = n_sub_83288E38(ctx, base); }

uint64_t n_sub_83288E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53C0 = int32_t(0x834A53C0);
	if (!UseLiftedCode(145, 0x83288E78)) { __imp__sub_83288E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53C0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288E78, 0x83288E78) { ctx.r3.u64 = n_sub_83288E78(ctx, base); }

uint64_t n_sub_83288EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53C4 = int32_t(0x834A53C4);
	if (!UseLiftedCode(145, 0x83288EB8)) { __imp__sub_83288EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53C4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288EB8, 0x83288EB8) { ctx.r3.u64 = n_sub_83288EB8(ctx, base); }

uint64_t n_sub_83288EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A53C8 = int32_t(0x834A53C8);
	if (!UseLiftedCode(145, 0x83288EF8)) { __imp__sub_83288EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83288EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A53C8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 7112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83288EF8, 0x83288EF8) { ctx.r3.u64 = n_sub_83288EF8(ctx, base); }

uint64_t n_sub_83289088(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289088)) { ctx.r8.u64 = arg1; __imp__sub_83289088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289088);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6616, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289088, 0x83289088) { ctx.r3.u64 = n_sub_83289088(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289128(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5438 = int32_t(0x834A5438);
	if (!UseLiftedCode(145, 0x83289128)) { __imp__sub_83289128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289128);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5438, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289128, 0x83289128) { ctx.r3.u64 = n_sub_83289128(ctx, base); }

uint64_t n_sub_83289168(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A543C = int32_t(0x834A543C);
	if (!UseLiftedCode(145, 0x83289168)) { __imp__sub_83289168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289168);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A543C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289168, 0x83289168) { ctx.r3.u64 = n_sub_83289168(ctx, base); }

uint64_t n_sub_83289238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A544C = int32_t(0x834A544C);
	if (!UseLiftedCode(145, 0x83289238)) { __imp__sub_83289238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A544C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289238, 0x83289238) { ctx.r3.u64 = n_sub_83289238(ctx, base); }

uint64_t n_sub_83289278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5450 = int32_t(0x834A5450);
	if (!UseLiftedCode(145, 0x83289278)) { __imp__sub_83289278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5450, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289278, 0x83289278) { ctx.r3.u64 = n_sub_83289278(ctx, base); }

uint64_t n_sub_832892B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5454 = int32_t(0x834A5454);
	if (!UseLiftedCode(145, 0x832892B8)) { __imp__sub_832892B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832892B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5454, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832892B8, 0x832892B8) { ctx.r3.u64 = n_sub_832892B8(ctx, base); }

uint64_t n_sub_832892F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5458 = int32_t(0x834A5458);
	if (!UseLiftedCode(145, 0x832892F8)) { __imp__sub_832892F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832892F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5458, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832892F8, 0x832892F8) { ctx.r3.u64 = n_sub_832892F8(ctx, base); }

uint64_t n_sub_83289338(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289338)) { ctx.r8.u64 = arg1; __imp__sub_83289338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289338);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6376, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289338, 0x83289338) { ctx.r3.u64 = n_sub_83289338(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289348(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289348)) { ctx.r8.u64 = arg1; __imp__sub_83289348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289348);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6288, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289348, 0x83289348) { ctx.r3.u64 = n_sub_83289348(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A547C = int32_t(0x834A547C);
	if (!UseLiftedCode(145, 0x83289358)) { __imp__sub_83289358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A547C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289358, 0x83289358) { ctx.r3.u64 = n_sub_83289358(ctx, base); }

uint64_t n_sub_83289398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5480 = int32_t(0x834A5480);
	if (!UseLiftedCode(145, 0x83289398)) { __imp__sub_83289398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5480, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 6080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289398, 0x83289398) { ctx.r3.u64 = n_sub_83289398(ctx, base); }

uint64_t n_sub_832893D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5484 = int32_t(0x834A5484);
	if (!UseLiftedCode(145, 0x832893D8)) { __imp__sub_832893D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832893D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5484, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832893D8, 0x832893D8) { ctx.r3.u64 = n_sub_832893D8(ctx, base); }

uint64_t n_sub_83289418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5488 = int32_t(0x834A5488);
	if (!UseLiftedCode(145, 0x83289418)) { __imp__sub_83289418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5488, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289418, 0x83289418) { ctx.r3.u64 = n_sub_83289418(ctx, base); }

uint64_t n_sub_83289458(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289458)) { ctx.r8.u64 = arg1; __imp__sub_83289458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289458);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5944, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289458, 0x83289458) { ctx.r3.u64 = n_sub_83289458(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832894A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5510 = int32_t(0x834A5510);
	if (!UseLiftedCode(145, 0x832894A0)) { __imp__sub_832894A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832894A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5510, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832894A0, 0x832894A0) { ctx.r3.u64 = n_sub_832894A0(ctx, base); }

uint64_t n_sub_832894E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5514 = int32_t(0x834A5514);
	if (!UseLiftedCode(145, 0x832894E0)) { __imp__sub_832894E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832894E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5514, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832894E0, 0x832894E0) { ctx.r3.u64 = n_sub_832894E0(ctx, base); }

uint64_t n_sub_83289520(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289520)) { ctx.r8.u64 = arg1; __imp__sub_83289520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289520);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5808, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289520, 0x83289520) { ctx.r3.u64 = n_sub_83289520(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A551C = int32_t(0x834A551C);
	if (!UseLiftedCode(145, 0x83289530)) { __imp__sub_83289530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289530);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A551C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289530, 0x83289530) { ctx.r3.u64 = n_sub_83289530(ctx, base); }

uint64_t n_sub_83289570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5520 = int32_t(0x834A5520);
	if (!UseLiftedCode(145, 0x83289570)) { __imp__sub_83289570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289570);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5520, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289570, 0x83289570) { ctx.r3.u64 = n_sub_83289570(ctx, base); }

uint64_t n_sub_832895B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832895B0)) { ctx.r8.u64 = arg1; __imp__sub_832895B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895B0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5696, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832895B0, 0x832895B0) { ctx.r3.u64 = n_sub_832895B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832895C0)) { ctx.r8.u64 = arg1; __imp__sub_832895C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895C0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5680, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832895C0, 0x832895C0) { ctx.r3.u64 = n_sub_832895C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832895D0)) { ctx.r8.u64 = arg1; __imp__sub_832895D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895D0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5664, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832895D0, 0x832895D0) { ctx.r3.u64 = n_sub_832895D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832895E0)) { ctx.r8.u64 = arg1; __imp__sub_832895E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895E0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5648, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832895E0, 0x832895E0) { ctx.r3.u64 = n_sub_832895E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832895F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x832895F0)) { ctx.r8.u64 = arg1; __imp__sub_832895F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832895F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5632, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_832895F0, 0x832895F0) { ctx.r3.u64 = n_sub_832895F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289600(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289600)) { ctx.r8.u64 = arg1; __imp__sub_83289600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289600);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5616, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289600, 0x83289600) { ctx.r3.u64 = n_sub_83289600(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289610(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289610)) { ctx.r8.u64 = arg1; __imp__sub_83289610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289610);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5600, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289610, 0x83289610) { ctx.r3.u64 = n_sub_83289610(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289620(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83289620)) { ctx.r8.u64 = arg1; __imp__sub_83289620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289620);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5584, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83289620, 0x83289620) { ctx.r3.u64 = n_sub_83289620(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83289630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55C4 = int32_t(0x834A55C4);
	if (!UseLiftedCode(145, 0x83289630)) { __imp__sub_83289630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55C4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289630, 0x83289630) { ctx.r3.u64 = n_sub_83289630(ctx, base); }

uint64_t n_sub_83289670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55C8 = int32_t(0x834A55C8);
	if (!UseLiftedCode(145, 0x83289670)) { __imp__sub_83289670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55C8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289670, 0x83289670) { ctx.r3.u64 = n_sub_83289670(ctx, base); }

uint64_t n_sub_832896B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55CC = int32_t(0x834A55CC);
	if (!UseLiftedCode(145, 0x832896B0)) { __imp__sub_832896B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832896B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55CC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832896B0, 0x832896B0) { ctx.r3.u64 = n_sub_832896B0(ctx, base); }

uint64_t n_sub_832896F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55D0 = int32_t(0x834A55D0);
	if (!UseLiftedCode(145, 0x832896F0)) { __imp__sub_832896F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832896F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55D0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832896F0, 0x832896F0) { ctx.r3.u64 = n_sub_832896F0(ctx, base); }

uint64_t n_sub_83289730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55D4 = int32_t(0x834A55D4);
	if (!UseLiftedCode(145, 0x83289730)) { __imp__sub_83289730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55D4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289730, 0x83289730) { ctx.r3.u64 = n_sub_83289730(ctx, base); }

uint64_t n_sub_83289770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A55D8 = int32_t(0x834A55D8);
	if (!UseLiftedCode(145, 0x83289770)) { __imp__sub_83289770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A55D8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289770, 0x83289770) { ctx.r3.u64 = n_sub_83289770(ctx, base); }

uint64_t n_sub_832897C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5620 = int32_t(0x834A5620);
	if (!UseLiftedCode(145, 0x832897C0)) { __imp__sub_832897C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832897C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5620, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832897C0, 0x832897C0) { ctx.r3.u64 = n_sub_832897C0(ctx, base); }

uint64_t n_sub_83289800(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5624 = int32_t(0x834A5624);
	if (!UseLiftedCode(145, 0x83289800)) { __imp__sub_83289800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289800);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5624, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289800, 0x83289800) { ctx.r3.u64 = n_sub_83289800(ctx, base); }

uint64_t n_sub_83289898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5628 = int32_t(0x834A5628);
	if (!UseLiftedCode(145, 0x83289898)) { __imp__sub_83289898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5628, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289898, 0x83289898) { ctx.r3.u64 = n_sub_83289898(ctx, base); }

uint64_t n_sub_832898D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A562C = int32_t(0x834A562C);
	if (!UseLiftedCode(145, 0x832898D8)) { __imp__sub_832898D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832898D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A562C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832898D8, 0x832898D8) { ctx.r3.u64 = n_sub_832898D8(ctx, base); }

uint64_t n_sub_83289CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5700 = int32_t(0x834A5700);
	if (!UseLiftedCode(145, 0x83289CF8)) { __imp__sub_83289CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5700, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289CF8, 0x83289CF8) { ctx.r3.u64 = n_sub_83289CF8(ctx, base); }

uint64_t n_sub_83289D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5704 = int32_t(0x834A5704);
	if (!UseLiftedCode(145, 0x83289D38)) { __imp__sub_83289D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289D38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5704, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289D38, 0x83289D38) { ctx.r3.u64 = n_sub_83289D38(ctx, base); }

uint64_t n_sub_83289D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5708 = int32_t(0x834A5708);
	if (!UseLiftedCode(145, 0x83289D78)) { __imp__sub_83289D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5708, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289D78, 0x83289D78) { ctx.r3.u64 = n_sub_83289D78(ctx, base); }

uint64_t n_sub_83289DB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A570C = int32_t(0x834A570C);
	if (!UseLiftedCode(145, 0x83289DB8)) { __imp__sub_83289DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289DB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A570C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289DB8, 0x83289DB8) { ctx.r3.u64 = n_sub_83289DB8(ctx, base); }

uint64_t n_sub_83289DF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5710 = int32_t(0x834A5710);
	if (!UseLiftedCode(145, 0x83289DF8)) { __imp__sub_83289DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289DF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5710, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289DF8, 0x83289DF8) { ctx.r3.u64 = n_sub_83289DF8(ctx, base); }

uint64_t n_sub_83289E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5714 = int32_t(0x834A5714);
	if (!UseLiftedCode(145, 0x83289E38)) { __imp__sub_83289E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5714, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289E38, 0x83289E38) { ctx.r3.u64 = n_sub_83289E38(ctx, base); }

uint64_t n_sub_83289E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5718 = int32_t(0x834A5718);
	if (!UseLiftedCode(145, 0x83289E78)) { __imp__sub_83289E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5718, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289E78, 0x83289E78) { ctx.r3.u64 = n_sub_83289E78(ctx, base); }

uint64_t n_sub_83289EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A571C = int32_t(0x834A571C);
	if (!UseLiftedCode(145, 0x83289EB8)) { __imp__sub_83289EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A571C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289EB8, 0x83289EB8) { ctx.r3.u64 = n_sub_83289EB8(ctx, base); }

uint64_t n_sub_83289EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5720 = int32_t(0x834A5720);
	if (!UseLiftedCode(145, 0x83289EF8)) { __imp__sub_83289EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5720, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289EF8, 0x83289EF8) { ctx.r3.u64 = n_sub_83289EF8(ctx, base); }

uint64_t n_sub_83289F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5724 = int32_t(0x834A5724);
	if (!UseLiftedCode(145, 0x83289F38)) { __imp__sub_83289F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5724, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289F38, 0x83289F38) { ctx.r3.u64 = n_sub_83289F38(ctx, base); }

uint64_t n_sub_83289F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5728 = int32_t(0x834A5728);
	if (!UseLiftedCode(145, 0x83289F78)) { __imp__sub_83289F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5728, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289F78, 0x83289F78) { ctx.r3.u64 = n_sub_83289F78(ctx, base); }

uint64_t n_sub_83289FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A572C = int32_t(0x834A572C);
	if (!UseLiftedCode(145, 0x83289FB8)) { __imp__sub_83289FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A572C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289FB8, 0x83289FB8) { ctx.r3.u64 = n_sub_83289FB8(ctx, base); }

uint64_t n_sub_83289FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5730 = int32_t(0x834A5730);
	if (!UseLiftedCode(145, 0x83289FF8)) { __imp__sub_83289FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83289FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5730, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83289FF8, 0x83289FF8) { ctx.r3.u64 = n_sub_83289FF8(ctx, base); }

uint64_t n_sub_8328A038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5734 = int32_t(0x834A5734);
	if (!UseLiftedCode(145, 0x8328A038)) { __imp__sub_8328A038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5734, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A038, 0x8328A038) { ctx.r3.u64 = n_sub_8328A038(ctx, base); }

uint64_t n_sub_8328A078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5738 = int32_t(0x834A5738);
	if (!UseLiftedCode(145, 0x8328A078)) { __imp__sub_8328A078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5738, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A078, 0x8328A078) { ctx.r3.u64 = n_sub_8328A078(ctx, base); }

uint64_t n_sub_8328A0B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A573C = int32_t(0x834A573C);
	if (!UseLiftedCode(145, 0x8328A0B8)) { __imp__sub_8328A0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A0B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A573C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A0B8, 0x8328A0B8) { ctx.r3.u64 = n_sub_8328A0B8(ctx, base); }

uint64_t n_sub_8328A1D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5780 = int32_t(0x834A5780);
	if (!UseLiftedCode(145, 0x8328A1D8)) { __imp__sub_8328A1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A1D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5780, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A1D8, 0x8328A1D8) { ctx.r3.u64 = n_sub_8328A1D8(ctx, base); }

uint64_t n_sub_8328A218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5784 = int32_t(0x834A5784);
	if (!UseLiftedCode(145, 0x8328A218)) { __imp__sub_8328A218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A218);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5784, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A218, 0x8328A218) { ctx.r3.u64 = n_sub_8328A218(ctx, base); }

uint64_t n_sub_8328A258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5788 = int32_t(0x834A5788);
	if (!UseLiftedCode(145, 0x8328A258)) { __imp__sub_8328A258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5788, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A258, 0x8328A258) { ctx.r3.u64 = n_sub_8328A258(ctx, base); }

uint64_t n_sub_8328A298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A578C = int32_t(0x834A578C);
	if (!UseLiftedCode(145, 0x8328A298)) { __imp__sub_8328A298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A578C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A298, 0x8328A298) { ctx.r3.u64 = n_sub_8328A298(ctx, base); }

uint64_t n_sub_8328A2D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5790 = int32_t(0x834A5790);
	if (!UseLiftedCode(145, 0x8328A2D8)) { __imp__sub_8328A2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A2D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5790, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A2D8, 0x8328A2D8) { ctx.r3.u64 = n_sub_8328A2D8(ctx, base); }

uint64_t n_sub_8328A318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5794 = int32_t(0x834A5794);
	if (!UseLiftedCode(145, 0x8328A318)) { __imp__sub_8328A318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5794, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A318, 0x8328A318) { ctx.r3.u64 = n_sub_8328A318(ctx, base); }

uint64_t n_sub_8328A358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5798 = int32_t(0x834A5798);
	if (!UseLiftedCode(145, 0x8328A358)) { __imp__sub_8328A358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5798, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A358, 0x8328A358) { ctx.r3.u64 = n_sub_8328A358(ctx, base); }

uint64_t n_sub_8328A398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A579C = int32_t(0x834A579C);
	if (!UseLiftedCode(145, 0x8328A398)) { __imp__sub_8328A398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A579C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A398, 0x8328A398) { ctx.r3.u64 = n_sub_8328A398(ctx, base); }

uint64_t n_sub_8328A3D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57A0 = int32_t(0x834A57A0);
	if (!UseLiftedCode(145, 0x8328A3D8)) { __imp__sub_8328A3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A3D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57A0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 5000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A3D8, 0x8328A3D8) { ctx.r3.u64 = n_sub_8328A3D8(ctx, base); }

uint64_t n_sub_8328A418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57A4 = int32_t(0x834A57A4);
	if (!UseLiftedCode(145, 0x8328A418)) { __imp__sub_8328A418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57A4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A418, 0x8328A418) { ctx.r3.u64 = n_sub_8328A418(ctx, base); }

uint64_t n_sub_8328A458(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57A8 = int32_t(0x834A57A8);
	if (!UseLiftedCode(145, 0x8328A458)) { __imp__sub_8328A458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A458);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57A8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A458, 0x8328A458) { ctx.r3.u64 = n_sub_8328A458(ctx, base); }

uint64_t n_sub_8328A498(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57AC = int32_t(0x834A57AC);
	if (!UseLiftedCode(145, 0x8328A498)) { __imp__sub_8328A498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A498);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57AC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A498, 0x8328A498) { ctx.r3.u64 = n_sub_8328A498(ctx, base); }

uint64_t n_sub_8328A4D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57B0 = int32_t(0x834A57B0);
	if (!UseLiftedCode(145, 0x8328A4D8)) { __imp__sub_8328A4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A4D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57B0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A4D8, 0x8328A4D8) { ctx.r3.u64 = n_sub_8328A4D8(ctx, base); }

uint64_t n_sub_8328A518(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57B4 = int32_t(0x834A57B4);
	if (!UseLiftedCode(145, 0x8328A518)) { __imp__sub_8328A518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A518);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57B4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A518, 0x8328A518) { ctx.r3.u64 = n_sub_8328A518(ctx, base); }

uint64_t n_sub_8328A558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57B8 = int32_t(0x834A57B8);
	if (!UseLiftedCode(145, 0x8328A558)) { __imp__sub_8328A558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57B8, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A558, 0x8328A558) { ctx.r3.u64 = n_sub_8328A558(ctx, base); }

uint64_t n_sub_8328A598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57BC = int32_t(0x834A57BC);
	if (!UseLiftedCode(145, 0x8328A598)) { __imp__sub_8328A598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57BC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A598, 0x8328A598) { ctx.r3.u64 = n_sub_8328A598(ctx, base); }

uint64_t n_sub_8328A5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57C0 = int32_t(0x834A57C0);
	if (!UseLiftedCode(145, 0x8328A5D8)) { __imp__sub_8328A5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A5D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57C0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A5D8, 0x8328A5D8) { ctx.r3.u64 = n_sub_8328A5D8(ctx, base); }

uint64_t n_sub_8328A618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A57C4 = int32_t(0x834A57C4);
	if (!UseLiftedCode(145, 0x8328A618)) { __imp__sub_8328A618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A618);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A57C4, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A618, 0x8328A618) { ctx.r3.u64 = n_sub_8328A618(ctx, base); }

uint64_t n_sub_8328A668(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A0C = int32_t(0x834A5A0C);
	if (!UseLiftedCode(145, 0x8328A668)) { __imp__sub_8328A668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A668);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A0C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A668, 0x8328A668) { ctx.r3.u64 = n_sub_8328A668(ctx, base); }

uint64_t n_sub_8328A6A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A10 = int32_t(0x834A5A10);
	if (!UseLiftedCode(145, 0x8328A6A8)) { __imp__sub_8328A6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A6A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A10, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A6A8, 0x8328A6A8) { ctx.r3.u64 = n_sub_8328A6A8(ctx, base); }

uint64_t n_sub_8328A6E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A14 = int32_t(0x834A5A14);
	if (!UseLiftedCode(145, 0x8328A6E8)) { __imp__sub_8328A6E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A6E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A14, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A6E8, 0x8328A6E8) { ctx.r3.u64 = n_sub_8328A6E8(ctx, base); }

uint64_t n_sub_8328A728(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A18 = int32_t(0x834A5A18);
	if (!UseLiftedCode(145, 0x8328A728)) { __imp__sub_8328A728(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A728);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A18, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A728, 0x8328A728) { ctx.r3.u64 = n_sub_8328A728(ctx, base); }

uint64_t n_sub_8328A768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A1C = int32_t(0x834A5A1C);
	if (!UseLiftedCode(145, 0x8328A768)) { __imp__sub_8328A768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A768);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A1C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A768, 0x8328A768) { ctx.r3.u64 = n_sub_8328A768(ctx, base); }

uint64_t n_sub_8328A7A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A20 = int32_t(0x834A5A20);
	if (!UseLiftedCode(145, 0x8328A7A8)) { __imp__sub_8328A7A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A20, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A7A8, 0x8328A7A8) { ctx.r3.u64 = n_sub_8328A7A8(ctx, base); }

uint64_t n_sub_8328A7E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328A7E8)) { ctx.r8.u64 = arg1; __imp__sub_8328A7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7E8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4744, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328A7E8, 0x8328A7E8) { ctx.r3.u64 = n_sub_8328A7E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328A7F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A34 = int32_t(0x834A5A34);
	if (!UseLiftedCode(145, 0x8328A7F8)) { __imp__sub_8328A7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A7F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A34, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A7F8, 0x8328A7F8) { ctx.r3.u64 = n_sub_8328A7F8(ctx, base); }

uint64_t n_sub_8328A838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A38 = int32_t(0x834A5A38);
	if (!UseLiftedCode(145, 0x8328A838)) { __imp__sub_8328A838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328A838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A38, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328A838, 0x8328A838) { ctx.r3.u64 = n_sub_8328A838(ctx, base); }

uint64_t n_sub_8328AD60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A3C = int32_t(0x834A5A3C);
	if (!UseLiftedCode(145, 0x8328AD60)) { __imp__sub_8328AD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AD60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A3C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AD60, 0x8328AD60) { ctx.r3.u64 = n_sub_8328AD60(ctx, base); }

uint64_t n_sub_8328ADA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A40 = int32_t(0x834A5A40);
	if (!UseLiftedCode(145, 0x8328ADA0)) { __imp__sub_8328ADA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ADA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A40, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328ADA0, 0x8328ADA0) { ctx.r3.u64 = n_sub_8328ADA0(ctx, base); }

uint64_t n_sub_8328ADE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A44 = int32_t(0x834A5A44);
	if (!UseLiftedCode(145, 0x8328ADE0)) { __imp__sub_8328ADE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328ADE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A44, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328ADE0, 0x8328ADE0) { ctx.r3.u64 = n_sub_8328ADE0(ctx, base); }

uint64_t n_sub_8328AE20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A48 = int32_t(0x834A5A48);
	if (!UseLiftedCode(145, 0x8328AE20)) { __imp__sub_8328AE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AE20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A48, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AE20, 0x8328AE20) { ctx.r3.u64 = n_sub_8328AE20(ctx, base); }

uint64_t n_sub_8328AE60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A4C = int32_t(0x834A5A4C);
	if (!UseLiftedCode(145, 0x8328AE60)) { __imp__sub_8328AE60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AE60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A4C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AE60, 0x8328AE60) { ctx.r3.u64 = n_sub_8328AE60(ctx, base); }

uint64_t n_sub_8328AEA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A50 = int32_t(0x834A5A50);
	if (!UseLiftedCode(145, 0x8328AEA0)) { __imp__sub_8328AEA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AEA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A50, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AEA0, 0x8328AEA0) { ctx.r3.u64 = n_sub_8328AEA0(ctx, base); }

uint64_t n_sub_8328AEE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A54 = int32_t(0x834A5A54);
	if (!UseLiftedCode(145, 0x8328AEE0)) { __imp__sub_8328AEE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AEE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A54, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AEE0, 0x8328AEE0) { ctx.r3.u64 = n_sub_8328AEE0(ctx, base); }

uint64_t n_sub_8328AF20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A58 = int32_t(0x834A5A58);
	if (!UseLiftedCode(145, 0x8328AF20)) { __imp__sub_8328AF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AF20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A58, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AF20, 0x8328AF20) { ctx.r3.u64 = n_sub_8328AF20(ctx, base); }

uint64_t n_sub_8328AF60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A5C = int32_t(0x834A5A5C);
	if (!UseLiftedCode(145, 0x8328AF60)) { __imp__sub_8328AF60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AF60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A5C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AF60, 0x8328AF60) { ctx.r3.u64 = n_sub_8328AF60(ctx, base); }

uint64_t n_sub_8328AFA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A60 = int32_t(0x834A5A60);
	if (!UseLiftedCode(145, 0x8328AFA0)) { __imp__sub_8328AFA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AFA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A60, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AFA0, 0x8328AFA0) { ctx.r3.u64 = n_sub_8328AFA0(ctx, base); }

uint64_t n_sub_8328AFE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A64 = int32_t(0x834A5A64);
	if (!UseLiftedCode(145, 0x8328AFE0)) { __imp__sub_8328AFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328AFE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A64, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328AFE0, 0x8328AFE0) { ctx.r3.u64 = n_sub_8328AFE0(ctx, base); }

uint64_t n_sub_8328B020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A68 = int32_t(0x834A5A68);
	if (!UseLiftedCode(145, 0x8328B020)) { __imp__sub_8328B020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A68, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B020, 0x8328B020) { ctx.r3.u64 = n_sub_8328B020(ctx, base); }

uint64_t n_sub_8328B060(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A6C = int32_t(0x834A5A6C);
	if (!UseLiftedCode(145, 0x8328B060)) { __imp__sub_8328B060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B060);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A6C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B060, 0x8328B060) { ctx.r3.u64 = n_sub_8328B060(ctx, base); }

uint64_t n_sub_8328B0A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A70 = int32_t(0x834A5A70);
	if (!UseLiftedCode(145, 0x8328B0A0)) { __imp__sub_8328B0A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B0A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A70, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B0A0, 0x8328B0A0) { ctx.r3.u64 = n_sub_8328B0A0(ctx, base); }

uint64_t n_sub_8328B148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A90 = int32_t(0x834A5A90);
	if (!UseLiftedCode(145, 0x8328B148)) { __imp__sub_8328B148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A90, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B148, 0x8328B148) { ctx.r3.u64 = n_sub_8328B148(ctx, base); }

uint64_t n_sub_8328B188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5A94 = int32_t(0x834A5A94);
	if (!UseLiftedCode(145, 0x8328B188)) { __imp__sub_8328B188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5A94, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B188, 0x8328B188) { ctx.r3.u64 = n_sub_8328B188(ctx, base); }

uint64_t n_sub_8328B1F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5AAC = int32_t(0x834A5AAC);
	if (!UseLiftedCode(145, 0x8328B1F0)) { __imp__sub_8328B1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B1F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5AAC, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B1F0, 0x8328B1F0) { ctx.r3.u64 = n_sub_8328B1F0(ctx, base); }

uint64_t n_sub_8328B230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5AB0 = int32_t(0x834A5AB0);
	if (!UseLiftedCode(145, 0x8328B230)) { __imp__sub_8328B230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5AB0, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B230, 0x8328B230) { ctx.r3.u64 = n_sub_8328B230(ctx, base); }

uint64_t n_sub_8328B430(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328B430)) { ctx.r8.u64 = arg1; __imp__sub_8328B430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B430);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4312, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328B430, 0x8328B430) { ctx.r3.u64 = n_sub_8328B430(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328B558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_834A5B6C = int32_t(0x834A5B6C);
	if (!UseLiftedCode(145, 0x8328B558)) { __imp__sub_8328B558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328B558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_834A5B6C, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 4240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8328B558, 0x8328B558) { ctx.r3.u64 = n_sub_8328B558(ctx, base); }

uint64_t n_sub_8328BA00(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BA00)) { ctx.r8.u64 = arg1; __imp__sub_8328BA00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA00);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3960, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BA00, 0x8328BA00) { ctx.r3.u64 = n_sub_8328BA00(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA10(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BA10)) { ctx.r8.u64 = arg1; __imp__sub_8328BA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA10);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3864, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BA10, 0x8328BA10) { ctx.r3.u64 = n_sub_8328BA10(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA20(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BA20)) { ctx.r8.u64 = arg1; __imp__sub_8328BA20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA20);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3768, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BA20, 0x8328BA20) { ctx.r3.u64 = n_sub_8328BA20(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA30(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BA30)) { ctx.r8.u64 = arg1; __imp__sub_8328BA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA30);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3672, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BA30, 0x8328BA30) { ctx.r3.u64 = n_sub_8328BA30(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BA78(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BA78)) { ctx.r8.u64 = arg1; __imp__sub_8328BA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BA78);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3648, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BA78, 0x8328BA78) { ctx.r3.u64 = n_sub_8328BA78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BE98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BE98)) { ctx.r8.u64 = arg1; __imp__sub_8328BE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BE98);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3312, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BE98, 0x8328BE98) { ctx.r3.u64 = n_sub_8328BE98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BF18)) { ctx.r8.u64 = arg1; __imp__sub_8328BF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF18);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3144, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BF18, 0x8328BF18) { ctx.r3.u64 = n_sub_8328BF18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BF28)) { ctx.r8.u64 = arg1; __imp__sub_8328BF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF28);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 3048, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BF28, 0x8328BF28) { ctx.r3.u64 = n_sub_8328BF28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BF38)) { ctx.r8.u64 = arg1; __imp__sub_8328BF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF38);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2960, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BF38, 0x8328BF38) { ctx.r3.u64 = n_sub_8328BF38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328BF48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328BF48)) { ctx.r8.u64 = arg1; __imp__sub_8328BF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328BF48);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2872, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328BF48, 0x8328BF48) { ctx.r3.u64 = n_sub_8328BF48(ctx, base, ctx.r8.u64); }

// sub_8328C0E0  [12 bytes]
uint64_t n_sub_8328C0E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834BC0A0 = int32_t(0x834BC0A0);
	if (!UseLiftedCode(145, 0x8328C0E0)) { __imp__sub_8328C0E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C0E0);
	uint64_t object = g_834BC0A0;
	ctx.r3.u64 = object;
	uint64_t result = n_sub_82B74CC8(ctx, base);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C0E0, 0x8328C0E0) { ctx.r3.u64 = n_sub_8328C0E0(ctx, base); }

uint64_t n_sub_8328C0F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C0F0)) { ctx.r8.u64 = arg1; __imp__sub_8328C0F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C0F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2800, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C0F0, 0x8328C0F0) { ctx.r3.u64 = n_sub_8328C0F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C170(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C170)) { ctx.r8.u64 = arg1; __imp__sub_8328C170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C170);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2752, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C170, 0x8328C170) { ctx.r3.u64 = n_sub_8328C170(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C180(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C180)) { ctx.r8.u64 = arg1; __imp__sub_8328C180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C180);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2736, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C180, 0x8328C180) { ctx.r3.u64 = n_sub_8328C180(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1C0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C1C0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1C0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2632, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C1C0, 0x8328C1C0) { ctx.r3.u64 = n_sub_8328C1C0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1D0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C1D0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1D0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2544, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C1D0, 0x8328C1D0) { ctx.r3.u64 = n_sub_8328C1D0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C1E0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1E0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2480, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C1E0, 0x8328C1E0) { ctx.r3.u64 = n_sub_8328C1E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C1F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C1F0)) { ctx.r8.u64 = arg1; __imp__sub_8328C1F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C1F0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2392, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C1F0, 0x8328C1F0) { ctx.r3.u64 = n_sub_8328C1F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C200(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C200)) { ctx.r8.u64 = arg1; __imp__sub_8328C200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C200);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2304, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C200, 0x8328C200) { ctx.r3.u64 = n_sub_8328C200(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C210(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C210)) { ctx.r8.u64 = arg1; __imp__sub_8328C210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C210);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 2216, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C210, 0x8328C210) { ctx.r3.u64 = n_sub_8328C210(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328C8C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328C8C8)) { ctx.r8.u64 = arg1; __imp__sub_8328C8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328C8C8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1904, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328C8C8, 0x8328C8C8) { ctx.r3.u64 = n_sub_8328C8C8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328CC18)) { ctx.r8.u64 = arg1; __imp__sub_8328CC18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC18);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1632, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328CC18, 0x8328CC18) { ctx.r3.u64 = n_sub_8328CC18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328CC28)) { ctx.r8.u64 = arg1; __imp__sub_8328CC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC28);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1616, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328CC28, 0x8328CC28) { ctx.r3.u64 = n_sub_8328CC28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328CC38)) { ctx.r8.u64 = arg1; __imp__sub_8328CC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC38);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1600, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328CC38, 0x8328CC38) { ctx.r3.u64 = n_sub_8328CC38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328CC48(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328CC48)) { ctx.r8.u64 = arg1; __imp__sub_8328CC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328CC48);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1584, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328CC48, 0x8328CC48) { ctx.r3.u64 = n_sub_8328CC48(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328E8B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328E8B0)) { ctx.r8.u64 = arg1; __imp__sub_8328E8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328E8B0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1528, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328E8B0, 0x8328E8B0) { ctx.r3.u64 = n_sub_8328E8B0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328F958(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328F958)) { ctx.r8.u64 = arg1; __imp__sub_8328F958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F958);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1520, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328F958, 0x8328F958) { ctx.r3.u64 = n_sub_8328F958(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328F968(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328F968)) { ctx.r8.u64 = arg1; __imp__sub_8328F968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F968);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1504, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328F968, 0x8328F968) { ctx.r3.u64 = n_sub_8328F968(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328F978(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328F978)) { ctx.r8.u64 = arg1; __imp__sub_8328F978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F978);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1488, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328F978, 0x8328F978) { ctx.r3.u64 = n_sub_8328F978(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328F988(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328F988)) { ctx.r8.u64 = arg1; __imp__sub_8328F988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328F988);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1472, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328F988, 0x8328F988) { ctx.r3.u64 = n_sub_8328F988(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FED8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FED8)) { ctx.r8.u64 = arg1; __imp__sub_8328FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FED8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1384, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FED8, 0x8328FED8) { ctx.r3.u64 = n_sub_8328FED8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FEE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FEE8)) { ctx.r8.u64 = arg1; __imp__sub_8328FEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FEE8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1352, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FEE8, 0x8328FEE8) { ctx.r3.u64 = n_sub_8328FEE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FEF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FEF8)) { ctx.r8.u64 = arg1; __imp__sub_8328FEF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FEF8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1368, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FEF8, 0x8328FEF8) { ctx.r3.u64 = n_sub_8328FEF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FF08(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FF08)) { ctx.r8.u64 = arg1; __imp__sub_8328FF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF08);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1248, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FF08, 0x8328FF08) { ctx.r3.u64 = n_sub_8328FF08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FF18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FF18)) { ctx.r8.u64 = arg1; __imp__sub_8328FF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF18);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1336, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FF18, 0x8328FF18) { ctx.r3.u64 = n_sub_8328FF18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FF28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FF28)) { ctx.r8.u64 = arg1; __imp__sub_8328FF28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF28);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1232, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FF28, 0x8328FF28) { ctx.r3.u64 = n_sub_8328FF28(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FF38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FF38)) { ctx.r8.u64 = arg1; __imp__sub_8328FF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF38);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 1216, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FF38, 0x8328FF38) { ctx.r3.u64 = n_sub_8328FF38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8328FF80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8328FF80)) { ctx.r8.u64 = arg1; __imp__sub_8328FF80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8328FF80);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 968, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8328FF80, 0x8328FF80) { ctx.r3.u64 = n_sub_8328FF80(ctx, base, ctx.r8.u64); }
