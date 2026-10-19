// Start-up initialisers of global objects (they register property and definition names) at
// 0x8327xxxx, as readable C++.
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

uint64_t n_sub_83270420(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CDB8_G_ = int32_t(0x8349CDB8);
	if (!UseLiftedCode(144, 0x83270420)) { __imp__sub_83270420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270420);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CDB8_G_, (int64_t)g_820E0000 + 18752, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270420, 0x83270420) { ctx.r3.u64 = n_sub_83270420(ctx, base); }

uint64_t n_sub_832704A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CDC0_G_ = int32_t(0x8349CDC0);
	if (!UseLiftedCode(144, 0x832704A0)) { __imp__sub_832704A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832704A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CDC0_G_, (int64_t)g_820E0000 + 18796, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832704A0, 0x832704A0) { ctx.r3.u64 = n_sub_832704A0(ctx, base); }

uint64_t n_sub_83270978(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE18_G_ = int32_t(0x8349CE18);
	if (!UseLiftedCode(144, 0x83270978)) { __imp__sub_83270978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270978);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE18_G_, (int64_t)g_820E0000 - 12332, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 30000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270978, 0x83270978) { ctx.r3.u64 = n_sub_83270978(ctx, base); }

uint64_t n_sub_832709B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE1C_G_ = int32_t(0x8349CE1C);
	if (!UseLiftedCode(144, 0x832709B8)) { __imp__sub_832709B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832709B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE1C_G_, (int64_t)g_820E0000 + 18924, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832709B8, 0x832709B8) { ctx.r3.u64 = n_sub_832709B8(ctx, base); }

uint64_t n_sub_832709F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE20_G_ = int32_t(0x8349CE20);
	if (!UseLiftedCode(144, 0x832709F8)) { __imp__sub_832709F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832709F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE20_G_, (int64_t)g_820E0000 + 18932, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832709F8, 0x832709F8) { ctx.r3.u64 = n_sub_832709F8(ctx, base); }

uint64_t n_sub_83270A38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE24_G_ = int32_t(0x8349CE24);
	if (!UseLiftedCode(144, 0x83270A38)) { __imp__sub_83270A38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270A38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE24_G_, (int64_t)g_820E0000 + 18944, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270A38, 0x83270A38) { ctx.r3.u64 = n_sub_83270A38(ctx, base); }

uint64_t n_sub_83270A78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE28_G_ = int32_t(0x8349CE28);
	if (!UseLiftedCode(144, 0x83270A78)) { __imp__sub_83270A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270A78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE28_G_, (int64_t)g_820E0000 + 18956, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270A78, 0x83270A78) { ctx.r3.u64 = n_sub_83270A78(ctx, base); }

uint64_t n_sub_83270AB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE2C_G_ = int32_t(0x8349CE2C);
	if (!UseLiftedCode(144, 0x83270AB8)) { __imp__sub_83270AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270AB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE2C_G_, (int64_t)g_820E0000 + 18968, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270AB8, 0x83270AB8) { ctx.r3.u64 = n_sub_83270AB8(ctx, base); }

uint64_t n_sub_83270AF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE30_G_ = int32_t(0x8349CE30);
	if (!UseLiftedCode(144, 0x83270AF8)) { __imp__sub_83270AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270AF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE30_G_, (int64_t)g_820E0000 + 18980, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270AF8, 0x83270AF8) { ctx.r3.u64 = n_sub_83270AF8(ctx, base); }

uint64_t n_sub_83270B38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE34_G_ = int32_t(0x8349CE34);
	if (!UseLiftedCode(144, 0x83270B38)) { __imp__sub_83270B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83270B38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE34_G_, (int64_t)g_820E0000 + 18992, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83270B38, 0x83270B38) { ctx.r3.u64 = n_sub_83270B38(ctx, base); }

uint64_t n_sub_83271050(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE90_G_ = int32_t(0x8349CE90);
	if (!UseLiftedCode(144, 0x83271050)) { __imp__sub_83271050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271050);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE90_G_, (int64_t)g_820E0000 + 19296, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271050, 0x83271050) { ctx.r3.u64 = n_sub_83271050(ctx, base); }

uint64_t n_sub_83271090(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE94_G_ = int32_t(0x8349CE94);
	if (!UseLiftedCode(144, 0x83271090)) { __imp__sub_83271090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271090);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE94_G_, (int64_t)g_820E0000 + 19320, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271090, 0x83271090) { ctx.r3.u64 = n_sub_83271090(ctx, base); }

uint64_t n_sub_832710D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE98_G_ = int32_t(0x8349CE98);
	if (!UseLiftedCode(144, 0x832710D0)) { __imp__sub_832710D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832710D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE98_G_, (int64_t)g_820E0000 + 19360, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832710D0, 0x832710D0) { ctx.r3.u64 = n_sub_832710D0(ctx, base); }

uint64_t n_sub_83271110(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CE9C_G_ = int32_t(0x8349CE9C);
	if (!UseLiftedCode(144, 0x83271110)) { __imp__sub_83271110(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271110);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CE9C_G_, (int64_t)g_820E0000 + 19404, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271110, 0x83271110) { ctx.r3.u64 = n_sub_83271110(ctx, base); }

uint64_t n_sub_83271150(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEA0_G_ = int32_t(0x8349CEA0);
	if (!UseLiftedCode(144, 0x83271150)) { __imp__sub_83271150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271150);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA0_G_, (int64_t)g_820E0000 + 19460, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271150, 0x83271150) { ctx.r3.u64 = n_sub_83271150(ctx, base); }

uint64_t n_sub_83271190(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEA4_G_ = int32_t(0x8349CEA4);
	if (!UseLiftedCode(144, 0x83271190)) { __imp__sub_83271190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA4_G_, (int64_t)g_820E0000 + 19512, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271190, 0x83271190) { ctx.r3.u64 = n_sub_83271190(ctx, base); }

uint64_t n_sub_832711D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEA8_G_ = int32_t(0x8349CEA8);
	if (!UseLiftedCode(144, 0x832711D0)) { __imp__sub_832711D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832711D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEA8_G_, (int64_t)g_820E0000 + 19576, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832711D0, 0x832711D0) { ctx.r3.u64 = n_sub_832711D0(ctx, base); }

uint64_t n_sub_83271210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEAC_G_ = int32_t(0x8349CEAC);
	if (!UseLiftedCode(144, 0x83271210)) { __imp__sub_83271210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEAC_G_, (int64_t)g_820E0000 + 19640, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271210, 0x83271210) { ctx.r3.u64 = n_sub_83271210(ctx, base); }

uint64_t n_sub_83271250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEB0_G_ = int32_t(0x8349CEB0);
	if (!UseLiftedCode(144, 0x83271250)) { __imp__sub_83271250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB0_G_, (int64_t)g_820E0000 + 19696, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271250, 0x83271250) { ctx.r3.u64 = n_sub_83271250(ctx, base); }

uint64_t n_sub_83271290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEB4_G_ = int32_t(0x8349CEB4);
	if (!UseLiftedCode(144, 0x83271290)) { __imp__sub_83271290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB4_G_, (int64_t)g_820E0000 + 19768, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271290, 0x83271290) { ctx.r3.u64 = n_sub_83271290(ctx, base); }

uint64_t n_sub_832712D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEB8_G_ = int32_t(0x8349CEB8);
	if (!UseLiftedCode(144, 0x832712D0)) { __imp__sub_832712D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832712D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEB8_G_, (int64_t)g_820E0000 + 19840, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832712D0, 0x832712D0) { ctx.r3.u64 = n_sub_832712D0(ctx, base); }

uint64_t n_sub_83271310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEBC_G_ = int32_t(0x8349CEBC);
	if (!UseLiftedCode(144, 0x83271310)) { __imp__sub_83271310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271310);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEBC_G_, (int64_t)g_820E0000 + 19908, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271310, 0x83271310) { ctx.r3.u64 = n_sub_83271310(ctx, base); }

uint64_t n_sub_83271350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEC0_G_ = int32_t(0x8349CEC0);
	if (!UseLiftedCode(144, 0x83271350)) { __imp__sub_83271350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271350);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC0_G_, (int64_t)g_820E0000 + 19960, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271350, 0x83271350) { ctx.r3.u64 = n_sub_83271350(ctx, base); }

uint64_t n_sub_83271390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEC4_G_ = int32_t(0x8349CEC4);
	if (!UseLiftedCode(144, 0x83271390)) { __imp__sub_83271390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271390);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC4_G_, (int64_t)g_820E0000 + 20016, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271390, 0x83271390) { ctx.r3.u64 = n_sub_83271390(ctx, base); }

uint64_t n_sub_832713D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEC8_G_ = int32_t(0x8349CEC8);
	if (!UseLiftedCode(144, 0x832713D0)) { __imp__sub_832713D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832713D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEC8_G_, (int64_t)g_820E0000 + 20080, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832713D0, 0x832713D0) { ctx.r3.u64 = n_sub_832713D0(ctx, base); }

uint64_t n_sub_83271410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CECC_G_ = int32_t(0x8349CECC);
	if (!UseLiftedCode(144, 0x83271410)) { __imp__sub_83271410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CECC_G_, (int64_t)g_820E0000 + 20148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271410, 0x83271410) { ctx.r3.u64 = n_sub_83271410(ctx, base); }

uint64_t n_sub_83271450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CED0_G_ = int32_t(0x8349CED0);
	if (!UseLiftedCode(144, 0x83271450)) { __imp__sub_83271450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED0_G_, (int64_t)g_820E0000 + 20200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271450, 0x83271450) { ctx.r3.u64 = n_sub_83271450(ctx, base); }

uint64_t n_sub_83271490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CED4_G_ = int32_t(0x8349CED4);
	if (!UseLiftedCode(144, 0x83271490)) { __imp__sub_83271490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED4_G_, (int64_t)g_820E0000 + 20280, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271490, 0x83271490) { ctx.r3.u64 = n_sub_83271490(ctx, base); }

uint64_t n_sub_832714D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CED8_G_ = int32_t(0x8349CED8);
	if (!UseLiftedCode(144, 0x832714D0)) { __imp__sub_832714D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832714D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CED8_G_, (int64_t)g_820E0000 + 20336, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832714D0, 0x832714D0) { ctx.r3.u64 = n_sub_832714D0(ctx, base); }

uint64_t n_sub_83271510(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEDC_G_ = int32_t(0x8349CEDC);
	if (!UseLiftedCode(144, 0x83271510)) { __imp__sub_83271510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271510);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEDC_G_, (int64_t)g_820E0000 + 20416, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271510, 0x83271510) { ctx.r3.u64 = n_sub_83271510(ctx, base); }

uint64_t n_sub_83271550(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CEE0_G_ = int32_t(0x8349CEE0);
	if (!UseLiftedCode(144, 0x83271550)) { __imp__sub_83271550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271550);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CEE0_G_, (int64_t)g_820E0000 + 20460, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271550, 0x83271550) { ctx.r3.u64 = n_sub_83271550(ctx, base); }

uint64_t n_sub_83271A28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF38_G_ = int32_t(0x8349CF38);
	if (!UseLiftedCode(144, 0x83271A28)) { __imp__sub_83271A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271A28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF38_G_, (int64_t)g_820E0000 + 7620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271A28, 0x83271A28) { ctx.r3.u64 = n_sub_83271A28(ctx, base); }

uint64_t n_sub_83271A68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF3C_G_ = int32_t(0x8349CF3C);
	if (!UseLiftedCode(144, 0x83271A68)) { __imp__sub_83271A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271A68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF3C_G_, (int64_t)g_820E0000 + 7572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271A68, 0x83271A68) { ctx.r3.u64 = n_sub_83271A68(ctx, base); }

uint64_t n_sub_83271AA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF40_G_ = int32_t(0x8349CF40);
	if (!UseLiftedCode(144, 0x83271AA8)) { __imp__sub_83271AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271AA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF40_G_, (int64_t)g_820E0000 + 20852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271AA8, 0x83271AA8) { ctx.r3.u64 = n_sub_83271AA8(ctx, base); }

uint64_t n_sub_83271AE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF44_G_ = int32_t(0x8349CF44);
	if (!UseLiftedCode(144, 0x83271AE8)) { __imp__sub_83271AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271AE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF44_G_, (int64_t)g_820E0000 + 20900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271AE8, 0x83271AE8) { ctx.r3.u64 = n_sub_83271AE8(ctx, base); }

uint64_t n_sub_83271B28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF48_G_ = int32_t(0x8349CF48);
	if (!UseLiftedCode(144, 0x83271B28)) { __imp__sub_83271B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271B28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF48_G_, (int64_t)g_820E0000 + 20960, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271B28, 0x83271B28) { ctx.r3.u64 = n_sub_83271B28(ctx, base); }

uint64_t n_sub_83271B68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF4C_G_ = int32_t(0x8349CF4C);
	if (!UseLiftedCode(144, 0x83271B68)) { __imp__sub_83271B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271B68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF4C_G_, (int64_t)g_820E0000 + 21024, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271B68, 0x83271B68) { ctx.r3.u64 = n_sub_83271B68(ctx, base); }

uint64_t n_sub_83271BA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF50_G_ = int32_t(0x8349CF50);
	if (!UseLiftedCode(144, 0x83271BA8)) { __imp__sub_83271BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271BA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF50_G_, (int64_t)g_820E0000 + 21096, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271BA8, 0x83271BA8) { ctx.r3.u64 = n_sub_83271BA8(ctx, base); }

uint64_t n_sub_83271BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF54_G_ = int32_t(0x8349CF54);
	if (!UseLiftedCode(144, 0x83271BE8)) { __imp__sub_83271BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271BE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF54_G_, (int64_t)g_820E0000 + 21168, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271BE8, 0x83271BE8) { ctx.r3.u64 = n_sub_83271BE8(ctx, base); }

uint64_t n_sub_83271C28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF58_G_ = int32_t(0x8349CF58);
	if (!UseLiftedCode(144, 0x83271C28)) { __imp__sub_83271C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF58_G_, (int64_t)g_820E0000 + 8008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271C28, 0x83271C28) { ctx.r3.u64 = n_sub_83271C28(ctx, base); }

uint64_t n_sub_83271C68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF5C_G_ = int32_t(0x8349CF5C);
	if (!UseLiftedCode(144, 0x83271C68)) { __imp__sub_83271C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271C68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF5C_G_, (int64_t)g_820E0000 + 7712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271C68, 0x83271C68) { ctx.r3.u64 = n_sub_83271C68(ctx, base); }

uint64_t n_sub_83271CA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF60_G_ = int32_t(0x8349CF60);
	if (!UseLiftedCode(144, 0x83271CA8)) { __imp__sub_83271CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271CA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF60_G_, (int64_t)g_820E0000 + 7760, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271CA8, 0x83271CA8) { ctx.r3.u64 = n_sub_83271CA8(ctx, base); }

uint64_t n_sub_83271CE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CF64_G_ = int32_t(0x8349CF64);
	if (!UseLiftedCode(144, 0x83271CE8)) { __imp__sub_83271CE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83271CE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CF64_G_, (int64_t)g_820E0000 + 8076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83271CE8, 0x83271CE8) { ctx.r3.u64 = n_sub_83271CE8(ctx, base); }

uint64_t n_sub_83272200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFC0_G_ = int32_t(0x8349CFC0);
	if (!UseLiftedCode(144, 0x83272200)) { __imp__sub_83272200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272200);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC0_G_, (int64_t)g_820E0000 + 9052, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272200, 0x83272200) { ctx.r3.u64 = n_sub_83272200(ctx, base); }

uint64_t n_sub_83272240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFC4_G_ = int32_t(0x8349CFC4);
	if (!UseLiftedCode(144, 0x83272240)) { __imp__sub_83272240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272240);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC4_G_, (int64_t)g_820E0000 + 9100, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272240, 0x83272240) { ctx.r3.u64 = n_sub_83272240(ctx, base); }

uint64_t n_sub_83272280(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFC8_G_ = int32_t(0x8349CFC8);
	if (!UseLiftedCode(144, 0x83272280)) { __imp__sub_83272280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272280);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFC8_G_, (int64_t)g_820E0000 + 21320, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272280, 0x83272280) { ctx.r3.u64 = n_sub_83272280(ctx, base); }

uint64_t n_sub_832722C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFCC_G_ = int32_t(0x8349CFCC);
	if (!UseLiftedCode(144, 0x832722C0)) { __imp__sub_832722C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832722C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFCC_G_, (int64_t)g_820E0000 + 21392, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832722C0, 0x832722C0) { ctx.r3.u64 = n_sub_832722C0(ctx, base); }

uint64_t n_sub_83272300(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFD0_G_ = int32_t(0x8349CFD0);
	if (!UseLiftedCode(144, 0x83272300)) { __imp__sub_83272300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272300);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD0_G_, (int64_t)g_820E0000 + 21448, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272300, 0x83272300) { ctx.r3.u64 = n_sub_83272300(ctx, base); }

uint64_t n_sub_83272340(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFD4_G_ = int32_t(0x8349CFD4);
	if (!UseLiftedCode(144, 0x83272340)) { __imp__sub_83272340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272340);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD4_G_, (int64_t)g_820E0000 + 21508, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272340, 0x83272340) { ctx.r3.u64 = n_sub_83272340(ctx, base); }

uint64_t n_sub_83272380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFD8_G_ = int32_t(0x8349CFD8);
	if (!UseLiftedCode(144, 0x83272380)) { __imp__sub_83272380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272380);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFD8_G_, (int64_t)g_820E0000 + 21556, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272380, 0x83272380) { ctx.r3.u64 = n_sub_83272380(ctx, base); }

uint64_t n_sub_832723C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFDC_G_ = int32_t(0x8349CFDC);
	if (!UseLiftedCode(144, 0x832723C0)) { __imp__sub_832723C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832723C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFDC_G_, (int64_t)g_820E0000 + 21612, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832723C0, 0x832723C0) { ctx.r3.u64 = n_sub_832723C0(ctx, base); }

uint64_t n_sub_83272400(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFE0_G_ = int32_t(0x8349CFE0);
	if (!UseLiftedCode(144, 0x83272400)) { __imp__sub_83272400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272400);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE0_G_, (int64_t)g_820E0000 + 21668, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272400, 0x83272400) { ctx.r3.u64 = n_sub_83272400(ctx, base); }

uint64_t n_sub_83272440(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFE4_G_ = int32_t(0x8349CFE4);
	if (!UseLiftedCode(144, 0x83272440)) { __imp__sub_83272440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272440);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE4_G_, (int64_t)g_820E0000 + 21732, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272440, 0x83272440) { ctx.r3.u64 = n_sub_83272440(ctx, base); }

uint64_t n_sub_83272480(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFE8_G_ = int32_t(0x8349CFE8);
	if (!UseLiftedCode(144, 0x83272480)) { __imp__sub_83272480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272480);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFE8_G_, (int64_t)g_820E0000 + 21796, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272480, 0x83272480) { ctx.r3.u64 = n_sub_83272480(ctx, base); }

uint64_t n_sub_832724C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFEC_G_ = int32_t(0x8349CFEC);
	if (!UseLiftedCode(144, 0x832724C0)) { __imp__sub_832724C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832724C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFEC_G_, (int64_t)g_820E0000 + 21856, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832724C0, 0x832724C0) { ctx.r3.u64 = n_sub_832724C0(ctx, base); }

uint64_t n_sub_83272500(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFF0_G_ = int32_t(0x8349CFF0);
	if (!UseLiftedCode(144, 0x83272500)) { __imp__sub_83272500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272500);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF0_G_, (int64_t)g_820E0000 + 21912, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272500, 0x83272500) { ctx.r3.u64 = n_sub_83272500(ctx, base); }

uint64_t n_sub_83272540(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFF4_G_ = int32_t(0x8349CFF4);
	if (!UseLiftedCode(144, 0x83272540)) { __imp__sub_83272540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272540);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF4_G_, (int64_t)g_820E0000 + 21968, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272540, 0x83272540) { ctx.r3.u64 = n_sub_83272540(ctx, base); }

uint64_t n_sub_83272580(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFF8_G_ = int32_t(0x8349CFF8);
	if (!UseLiftedCode(144, 0x83272580)) { __imp__sub_83272580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272580);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFF8_G_, (int64_t)g_820E0000 + 22032, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272580, 0x83272580) { ctx.r3.u64 = n_sub_83272580(ctx, base); }

uint64_t n_sub_832725C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349CFFC_G_ = int32_t(0x8349CFFC);
	if (!UseLiftedCode(144, 0x832725C0)) { __imp__sub_832725C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832725C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349CFFC_G_, (int64_t)g_820E0000 + 22088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832725C0, 0x832725C0) { ctx.r3.u64 = n_sub_832725C0(ctx, base); }

uint64_t n_sub_83272600(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D000_G_ = int32_t(0x8349D000);
	if (!UseLiftedCode(144, 0x83272600)) { __imp__sub_83272600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272600);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D000_G_, (int64_t)g_820E0000 + 9352, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272600, 0x83272600) { ctx.r3.u64 = n_sub_83272600(ctx, base); }

uint64_t n_sub_83272640(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D004_G_ = int32_t(0x8349D004);
	if (!UseLiftedCode(144, 0x83272640)) { __imp__sub_83272640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272640);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D004_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 29040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272640, 0x83272640) { ctx.r3.u64 = n_sub_83272640(ctx, base); }

uint64_t n_sub_83272B98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D064_G_ = int32_t(0x8349D064);
	if (!UseLiftedCode(144, 0x83272B98)) { __imp__sub_83272B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272B98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D064_G_, (int64_t)g_820E0000 + 23860, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272B98, 0x83272B98) { ctx.r3.u64 = n_sub_83272B98(ctx, base); }

uint64_t n_sub_83272BD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D068_G_ = int32_t(0x8349D068);
	if (!UseLiftedCode(144, 0x83272BD8)) { __imp__sub_83272BD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272BD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D068_G_, (int64_t)g_820E0000 + 23904, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272BD8, 0x83272BD8) { ctx.r3.u64 = n_sub_83272BD8(ctx, base); }

uint64_t n_sub_83272C18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D06C_G_ = int32_t(0x8349D06C);
	if (!UseLiftedCode(144, 0x83272C18)) { __imp__sub_83272C18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D06C_G_, (int64_t)g_820E0000 + 23948, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272C18, 0x83272C18) { ctx.r3.u64 = n_sub_83272C18(ctx, base); }

uint64_t n_sub_83272C58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D070_G_ = int32_t(0x8349D070);
	if (!UseLiftedCode(144, 0x83272C58)) { __imp__sub_83272C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D070_G_, (int64_t)g_820E0000 + 23992, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272C58, 0x83272C58) { ctx.r3.u64 = n_sub_83272C58(ctx, base); }

uint64_t n_sub_83272C98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D074_G_ = int32_t(0x8349D074);
	if (!UseLiftedCode(144, 0x83272C98)) { __imp__sub_83272C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272C98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D074_G_, (int64_t)g_820E0000 + 24036, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272C98, 0x83272C98) { ctx.r3.u64 = n_sub_83272C98(ctx, base); }

uint64_t n_sub_83272CD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D078_G_ = int32_t(0x8349D078);
	if (!UseLiftedCode(144, 0x83272CD8)) { __imp__sub_83272CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272CD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D078_G_, (int64_t)g_820E0000 + 24076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272CD8, 0x83272CD8) { ctx.r3.u64 = n_sub_83272CD8(ctx, base); }

uint64_t n_sub_83272D18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D07C_G_ = int32_t(0x8349D07C);
	if (!UseLiftedCode(144, 0x83272D18)) { __imp__sub_83272D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D07C_G_, (int64_t)g_820E0000 + 24128, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272D18, 0x83272D18) { ctx.r3.u64 = n_sub_83272D18(ctx, base); }

uint64_t n_sub_83272D58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D080_G_ = int32_t(0x8349D080);
	if (!UseLiftedCode(144, 0x83272D58)) { __imp__sub_83272D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D080_G_, (int64_t)g_820E0000 + 24180, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272D58, 0x83272D58) { ctx.r3.u64 = n_sub_83272D58(ctx, base); }

uint64_t n_sub_83272D98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D084_G_ = int32_t(0x8349D084);
	if (!UseLiftedCode(144, 0x83272D98)) { __imp__sub_83272D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272D98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D084_G_, (int64_t)g_820E0000 + 24228, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272D98, 0x83272D98) { ctx.r3.u64 = n_sub_83272D98(ctx, base); }

uint64_t n_sub_83272DD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D088_G_ = int32_t(0x8349D088);
	if (!UseLiftedCode(144, 0x83272DD8)) { __imp__sub_83272DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272DD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D088_G_, (int64_t)g_820E0000 + 24280, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272DD8, 0x83272DD8) { ctx.r3.u64 = n_sub_83272DD8(ctx, base); }

uint64_t n_sub_83272E18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D08C_G_ = int32_t(0x8349D08C);
	if (!UseLiftedCode(144, 0x83272E18)) { __imp__sub_83272E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272E18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D08C_G_, (int64_t)g_820E0000 + 24328, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272E18, 0x83272E18) { ctx.r3.u64 = n_sub_83272E18(ctx, base); }

uint64_t n_sub_83272E98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D094_G_ = int32_t(0x8349D094);
	if (!UseLiftedCode(144, 0x83272E98)) { __imp__sub_83272E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272E98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D094_G_, (int64_t)g_820E0000 + 24372, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272E98, 0x83272E98) { ctx.r3.u64 = n_sub_83272E98(ctx, base); }

uint64_t n_sub_83272ED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D098_G_ = int32_t(0x8349D098);
	if (!UseLiftedCode(144, 0x83272ED8)) { __imp__sub_83272ED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272ED8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D098_G_, (int64_t)g_820E0000 + 18548, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272ED8, 0x83272ED8) { ctx.r3.u64 = n_sub_83272ED8(ctx, base); }

uint64_t n_sub_83272F18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D09C_G_ = int32_t(0x8349D09C);
	if (!UseLiftedCode(144, 0x83272F18)) { __imp__sub_83272F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D09C_G_, (int64_t)g_820E0000 + 24408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272F18, 0x83272F18) { ctx.r3.u64 = n_sub_83272F18(ctx, base); }

uint64_t n_sub_83272F58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0A0_G_ = int32_t(0x8349D0A0);
	if (!UseLiftedCode(144, 0x83272F58)) { __imp__sub_83272F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A0_G_, (int64_t)g_820E0000 + 24452, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272F58, 0x83272F58) { ctx.r3.u64 = n_sub_83272F58(ctx, base); }

uint64_t n_sub_83272F98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0A4_G_ = int32_t(0x8349D0A4);
	if (!UseLiftedCode(144, 0x83272F98)) { __imp__sub_83272F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272F98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A4_G_, (int64_t)g_820E0000 + 24496, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272F98, 0x83272F98) { ctx.r3.u64 = n_sub_83272F98(ctx, base); }

uint64_t n_sub_83272FD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0A8_G_ = int32_t(0x8349D0A8);
	if (!UseLiftedCode(144, 0x83272FD8)) { __imp__sub_83272FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83272FD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0A8_G_, (int64_t)g_820E0000 + 24540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83272FD8, 0x83272FD8) { ctx.r3.u64 = n_sub_83272FD8(ctx, base); }

uint64_t n_sub_83273018(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0AC_G_ = int32_t(0x8349D0AC);
	if (!UseLiftedCode(144, 0x83273018)) { __imp__sub_83273018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273018);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0AC_G_, (int64_t)g_820E0000 + 24592, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273018, 0x83273018) { ctx.r3.u64 = n_sub_83273018(ctx, base); }

uint64_t n_sub_83273058(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0B0_G_ = int32_t(0x8349D0B0);
	if (!UseLiftedCode(144, 0x83273058)) { __imp__sub_83273058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273058);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B0_G_, (int64_t)g_820E0000 + 24644, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273058, 0x83273058) { ctx.r3.u64 = n_sub_83273058(ctx, base); }

uint64_t n_sub_83273098(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0B4_G_ = int32_t(0x8349D0B4);
	if (!UseLiftedCode(144, 0x83273098)) { __imp__sub_83273098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273098);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B4_G_, (int64_t)g_820E0000 + 24696, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273098, 0x83273098) { ctx.r3.u64 = n_sub_83273098(ctx, base); }

uint64_t n_sub_832730D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0B8_G_ = int32_t(0x8349D0B8);
	if (!UseLiftedCode(144, 0x832730D8)) { __imp__sub_832730D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832730D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0B8_G_, (int64_t)g_820E0000 + 24408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832730D8, 0x832730D8) { ctx.r3.u64 = n_sub_832730D8(ctx, base); }

uint64_t n_sub_83273118(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0BC_G_ = int32_t(0x8349D0BC);
	if (!UseLiftedCode(144, 0x83273118)) { __imp__sub_83273118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273118);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0BC_G_, (int64_t)g_820E0000 + 24452, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273118, 0x83273118) { ctx.r3.u64 = n_sub_83273118(ctx, base); }

uint64_t n_sub_83273158(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0C0_G_ = int32_t(0x8349D0C0);
	if (!UseLiftedCode(144, 0x83273158)) { __imp__sub_83273158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273158);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C0_G_, (int64_t)g_820E0000 + 24740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273158, 0x83273158) { ctx.r3.u64 = n_sub_83273158(ctx, base); }

uint64_t n_sub_83273198(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0C4_G_ = int32_t(0x8349D0C4);
	if (!UseLiftedCode(144, 0x83273198)) { __imp__sub_83273198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273198);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C4_G_, (int64_t)g_820E0000 + 24540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273198, 0x83273198) { ctx.r3.u64 = n_sub_83273198(ctx, base); }

uint64_t n_sub_832731D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0C8_G_ = int32_t(0x8349D0C8);
	if (!UseLiftedCode(144, 0x832731D8)) { __imp__sub_832731D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832731D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0C8_G_, (int64_t)g_820E0000 + 24592, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832731D8, 0x832731D8) { ctx.r3.u64 = n_sub_832731D8(ctx, base); }

uint64_t n_sub_83273218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0CC_G_ = int32_t(0x8349D0CC);
	if (!UseLiftedCode(144, 0x83273218)) { __imp__sub_83273218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273218);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0CC_G_, (int64_t)g_820E0000 + 24696, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273218, 0x83273218) { ctx.r3.u64 = n_sub_83273218(ctx, base); }

uint64_t n_sub_83273258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D0D0_G_ = int32_t(0x8349D0D0);
	if (!UseLiftedCode(144, 0x83273258)) { __imp__sub_83273258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D0D0_G_, (int64_t)g_820E0000 + 24740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273258, 0x83273258) { ctx.r3.u64 = n_sub_83273258(ctx, base); }

uint64_t n_sub_83273730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D128_G_ = int32_t(0x8349D128);
	if (!UseLiftedCode(144, 0x83273730)) { __imp__sub_83273730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D128_G_, (int64_t)g_820E0000 + 25668, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273730, 0x83273730) { ctx.r3.u64 = n_sub_83273730(ctx, base); }

uint64_t n_sub_83273770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D12C_G_ = int32_t(0x8349D12C);
	if (!UseLiftedCode(144, 0x83273770)) { __imp__sub_83273770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D12C_G_, (int64_t)g_820E0000 + 25712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273770, 0x83273770) { ctx.r3.u64 = n_sub_83273770(ctx, base); }

uint64_t n_sub_832737B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D130_G_ = int32_t(0x8349D130);
	if (!UseLiftedCode(144, 0x832737B0)) { __imp__sub_832737B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832737B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D130_G_, (int64_t)g_820E0000 + 25772, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832737B0, 0x832737B0) { ctx.r3.u64 = n_sub_832737B0(ctx, base); }

uint64_t n_sub_83273830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D138_G_ = int32_t(0x8349D138);
	if (!UseLiftedCode(144, 0x83273830)) { __imp__sub_83273830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D138_G_, (int64_t)g_820E0000 + 25832, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273830, 0x83273830) { ctx.r3.u64 = n_sub_83273830(ctx, base); }

uint64_t n_sub_83273870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D13C_G_ = int32_t(0x8349D13C);
	if (!UseLiftedCode(144, 0x83273870)) { __imp__sub_83273870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D13C_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273870, 0x83273870) { ctx.r3.u64 = n_sub_83273870(ctx, base); }

uint64_t n_sub_83273D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D194_G_ = int32_t(0x8349D194);
	if (!UseLiftedCode(144, 0x83273D48)) { __imp__sub_83273D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D194_G_, (int64_t)g_820E0000 + 7620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273D48, 0x83273D48) { ctx.r3.u64 = n_sub_83273D48(ctx, base); }

uint64_t n_sub_83273D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D198_G_ = int32_t(0x8349D198);
	if (!UseLiftedCode(144, 0x83273D88)) { __imp__sub_83273D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D198_G_, (int64_t)g_820E0000 + 7572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273D88, 0x83273D88) { ctx.r3.u64 = n_sub_83273D88(ctx, base); }

uint64_t n_sub_83273DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D19C_G_ = int32_t(0x8349D19C);
	if (!UseLiftedCode(144, 0x83273DC8)) { __imp__sub_83273DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D19C_G_, (int64_t)g_820E0000 + 26144, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273DC8, 0x83273DC8) { ctx.r3.u64 = n_sub_83273DC8(ctx, base); }

uint64_t n_sub_83273E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1A0_G_ = int32_t(0x8349D1A0);
	if (!UseLiftedCode(144, 0x83273E08)) { __imp__sub_83273E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1A0_G_, (int64_t)g_820E0000 + 8008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273E08, 0x83273E08) { ctx.r3.u64 = n_sub_83273E08(ctx, base); }

uint64_t n_sub_83273E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1A8_G_ = int32_t(0x8349D1A8);
	if (!UseLiftedCode(144, 0x83273E88)) { __imp__sub_83273E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1A8_G_, (int64_t)g_820E0000 + 26200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273E88, 0x83273E88) { ctx.r3.u64 = n_sub_83273E88(ctx, base); }

uint64_t n_sub_83273EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1AC_G_ = int32_t(0x8349D1AC);
	if (!UseLiftedCode(144, 0x83273EC8)) { __imp__sub_83273EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1AC_G_, (int64_t)g_820E0000 + 8076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273EC8, 0x83273EC8) { ctx.r3.u64 = n_sub_83273EC8(ctx, base); }

uint64_t n_sub_83273F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1B0_G_ = int32_t(0x8349D1B0);
	if (!UseLiftedCode(144, 0x83273F08)) { __imp__sub_83273F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B0_G_, (int64_t)g_820E0000 + 26324, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273F08, 0x83273F08) { ctx.r3.u64 = n_sub_83273F08(ctx, base); }

uint64_t n_sub_83273F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1B4_G_ = int32_t(0x8349D1B4);
	if (!UseLiftedCode(144, 0x83273F48)) { __imp__sub_83273F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B4_G_, (int64_t)g_820E0000 + 26376, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273F48, 0x83273F48) { ctx.r3.u64 = n_sub_83273F48(ctx, base); }

uint64_t n_sub_83273F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1B8_G_ = int32_t(0x8349D1B8);
	if (!UseLiftedCode(144, 0x83273F88)) { __imp__sub_83273F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1B8_G_, (int64_t)g_820E0000 + 26428, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273F88, 0x83273F88) { ctx.r3.u64 = n_sub_83273F88(ctx, base); }

uint64_t n_sub_83273FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1BC_G_ = int32_t(0x8349D1BC);
	if (!UseLiftedCode(144, 0x83273FC8)) { __imp__sub_83273FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83273FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1BC_G_, (int64_t)g_820E0000 + 8196, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83273FC8, 0x83273FC8) { ctx.r3.u64 = n_sub_83273FC8(ctx, base); }

uint64_t n_sub_83274008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1C0_G_ = int32_t(0x8349D1C0);
	if (!UseLiftedCode(144, 0x83274008)) { __imp__sub_83274008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1C0_G_, (int64_t)g_820E0000 + 26480, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274008, 0x83274008) { ctx.r3.u64 = n_sub_83274008(ctx, base); }

uint64_t n_sub_83274048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D1C4_G_ = int32_t(0x8349D1C4);
	if (!UseLiftedCode(144, 0x83274048)) { __imp__sub_83274048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D1C4_G_, (int64_t)g_820E0000 + 7712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274048, 0x83274048) { ctx.r3.u64 = n_sub_83274048(ctx, base); }

uint64_t n_sub_83274520(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D21C_G_ = int32_t(0x8349D21C);
	if (!UseLiftedCode(144, 0x83274520)) { __imp__sub_83274520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274520);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D21C_G_, (int64_t)g_820E0000 + 9052, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274520, 0x83274520) { ctx.r3.u64 = n_sub_83274520(ctx, base); }

uint64_t n_sub_83274560(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D220_G_ = int32_t(0x8349D220);
	if (!UseLiftedCode(144, 0x83274560)) { __imp__sub_83274560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D220_G_, (int64_t)g_820E0000 + 9248, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274560, 0x83274560) { ctx.r3.u64 = n_sub_83274560(ctx, base); }

uint64_t n_sub_832745A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D224_G_ = int32_t(0x8349D224);
	if (!UseLiftedCode(144, 0x832745A0)) { __imp__sub_832745A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832745A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D224_G_, (int64_t)g_820E0000 + 26672, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832745A0, 0x832745A0) { ctx.r3.u64 = n_sub_832745A0(ctx, base); }

uint64_t n_sub_832745E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D228_G_ = int32_t(0x8349D228);
	if (!UseLiftedCode(144, 0x832745E0)) { __imp__sub_832745E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832745E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D228_G_, (int64_t)g_820E0000 + 26572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832745E0, 0x832745E0) { ctx.r3.u64 = n_sub_832745E0(ctx, base); }

uint64_t n_sub_83274620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D22C_G_ = int32_t(0x8349D22C);
	if (!UseLiftedCode(144, 0x83274620)) { __imp__sub_83274620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274620);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D22C_G_, (int64_t)g_820E0000 + 26540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274620, 0x83274620) { ctx.r3.u64 = n_sub_83274620(ctx, base); }

uint64_t n_sub_83274660(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D230_G_ = int32_t(0x8349D230);
	if (!UseLiftedCode(144, 0x83274660)) { __imp__sub_83274660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274660);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D230_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274660, 0x83274660) { ctx.r3.u64 = n_sub_83274660(ctx, base); }

uint64_t n_sub_832746A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D234_G_ = int32_t(0x8349D234);
	if (!UseLiftedCode(144, 0x832746A0)) { __imp__sub_832746A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832746A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D234_G_, (int64_t)g_820E0000 + 9404, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832746A0, 0x832746A0) { ctx.r3.u64 = n_sub_832746A0(ctx, base); }

uint64_t n_sub_832746E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D238_G_ = int32_t(0x8349D238);
	if (!UseLiftedCode(144, 0x832746E0)) { __imp__sub_832746E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832746E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D238_G_, (int64_t)g_820E0000 + 26728, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832746E0, 0x832746E0) { ctx.r3.u64 = n_sub_832746E0(ctx, base); }

uint64_t n_sub_83274720(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D23C_G_ = int32_t(0x8349D23C);
	if (!UseLiftedCode(144, 0x83274720)) { __imp__sub_83274720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274720);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D23C_G_, (int64_t)g_820E0000 + 26804, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274720, 0x83274720) { ctx.r3.u64 = n_sub_83274720(ctx, base); }

uint64_t n_sub_83274760(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D240_G_ = int32_t(0x8349D240);
	if (!UseLiftedCode(144, 0x83274760)) { __imp__sub_83274760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274760);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D240_G_, (int64_t)g_820E0000 + 26856, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274760, 0x83274760) { ctx.r3.u64 = n_sub_83274760(ctx, base); }

uint64_t n_sub_832747A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D244_G_ = int32_t(0x8349D244);
	if (!UseLiftedCode(144, 0x832747A0)) { __imp__sub_832747A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832747A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D244_G_, (int64_t)g_820E0000 + 26908, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832747A0, 0x832747A0) { ctx.r3.u64 = n_sub_832747A0(ctx, base); }

uint64_t n_sub_832747E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D248_G_ = int32_t(0x8349D248);
	if (!UseLiftedCode(144, 0x832747E0)) { __imp__sub_832747E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832747E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D248_G_, (int64_t)g_820E0000 + 9464, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832747E0, 0x832747E0) { ctx.r3.u64 = n_sub_832747E0(ctx, base); }

uint64_t n_sub_83274820(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D24C_G_ = int32_t(0x8349D24C);
	if (!UseLiftedCode(144, 0x83274820)) { __imp__sub_83274820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274820);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D24C_G_, (int64_t)g_820E0000 + 26960, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274820, 0x83274820) { ctx.r3.u64 = n_sub_83274820(ctx, base); }

uint64_t n_sub_83274860(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D250_G_ = int32_t(0x8349D250);
	if (!UseLiftedCode(144, 0x83274860)) { __imp__sub_83274860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274860);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D250_G_, (int64_t)g_820E0000 + 9200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274860, 0x83274860) { ctx.r3.u64 = n_sub_83274860(ctx, base); }

uint64_t n_sub_832748A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D254_G_ = int32_t(0x8349D254);
	if (!UseLiftedCode(144, 0x832748A0)) { __imp__sub_832748A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832748A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D254_G_, (int64_t)g_820E0000 + 9148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832748A0, 0x832748A0) { ctx.r3.u64 = n_sub_832748A0(ctx, base); }

uint64_t n_sub_832748E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D258_G_ = int32_t(0x8349D258);
	if (!UseLiftedCode(144, 0x832748E0)) { __imp__sub_832748E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832748E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D258_G_, (int64_t)g_820E0000 + 9100, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 28000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832748E0, 0x832748E0) { ctx.r3.u64 = n_sub_832748E0(ctx, base); }

uint64_t n_sub_83274E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D2B8_G_ = int32_t(0x8349D2B8);
	if (!UseLiftedCode(144, 0x83274E38)) { __imp__sub_83274E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2B8_G_, (int64_t)g_820E0000 + 27116, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274E38, 0x83274E38) { ctx.r3.u64 = n_sub_83274E38(ctx, base); }

uint64_t n_sub_83274E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D2BC_G_ = int32_t(0x8349D2BC);
	if (!UseLiftedCode(144, 0x83274E78)) { __imp__sub_83274E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2BC_G_, (int64_t)g_820E0000 + 27124, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274E78, 0x83274E78) { ctx.r3.u64 = n_sub_83274E78(ctx, base); }

uint64_t n_sub_83274EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D2C0_G_ = int32_t(0x8349D2C0);
	if (!UseLiftedCode(144, 0x83274EB8)) { __imp__sub_83274EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2C0_G_, (int64_t)g_820E0000 + 27132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274EB8, 0x83274EB8) { ctx.r3.u64 = n_sub_83274EB8(ctx, base); }

uint64_t n_sub_83274F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D2C8_G_ = int32_t(0x8349D2C8);
	if (!UseLiftedCode(144, 0x83274F38)) { __imp__sub_83274F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83274F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D2C8_G_, (int64_t)g_820E0000 - 12220, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83274F38, 0x83274F38) { ctx.r3.u64 = n_sub_83274F38(ctx, base); }

uint64_t n_sub_83275AE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D398_G_ = int32_t(0x8349D398);
	if (!UseLiftedCode(144, 0x83275AE8)) { __imp__sub_83275AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275AE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D398_G_, (int64_t)g_820E0000 + 27584, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275AE8, 0x83275AE8) { ctx.r3.u64 = n_sub_83275AE8(ctx, base); }

uint64_t n_sub_83275B28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D39C_G_ = int32_t(0x8349D39C);
	if (!UseLiftedCode(144, 0x83275B28)) { __imp__sub_83275B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275B28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D39C_G_, (int64_t)g_820E0000 + 27636, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275B28, 0x83275B28) { ctx.r3.u64 = n_sub_83275B28(ctx, base); }

uint64_t n_sub_83275B68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3A0_G_ = int32_t(0x8349D3A0);
	if (!UseLiftedCode(144, 0x83275B68)) { __imp__sub_83275B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275B68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A0_G_, (int64_t)g_820E0000 + 27684, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275B68, 0x83275B68) { ctx.r3.u64 = n_sub_83275B68(ctx, base); }

uint64_t n_sub_83275BA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3A4_G_ = int32_t(0x8349D3A4);
	if (!UseLiftedCode(144, 0x83275BA8)) { __imp__sub_83275BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275BA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A4_G_, (int64_t)g_820E0000 + 27744, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275BA8, 0x83275BA8) { ctx.r3.u64 = n_sub_83275BA8(ctx, base); }

uint64_t n_sub_83275BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3A8_G_ = int32_t(0x8349D3A8);
	if (!UseLiftedCode(144, 0x83275BE8)) { __imp__sub_83275BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275BE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3A8_G_, (int64_t)g_820E0000 + 27756, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275BE8, 0x83275BE8) { ctx.r3.u64 = n_sub_83275BE8(ctx, base); }

uint64_t n_sub_83275C28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3AC_G_ = int32_t(0x8349D3AC);
	if (!UseLiftedCode(144, 0x83275C28)) { __imp__sub_83275C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3AC_G_, (int64_t)g_820E0000 + 27800, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275C28, 0x83275C28) { ctx.r3.u64 = n_sub_83275C28(ctx, base); }

uint64_t n_sub_83275C68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3B0_G_ = int32_t(0x8349D3B0);
	if (!UseLiftedCode(144, 0x83275C68)) { __imp__sub_83275C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275C68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3B0_G_, (int64_t)g_820E0000 + 27852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275C68, 0x83275C68) { ctx.r3.u64 = n_sub_83275C68(ctx, base); }

uint64_t n_sub_83275CA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D3B4_G_ = int32_t(0x8349D3B4);
	if (!UseLiftedCode(144, 0x83275CA8)) { __imp__sub_83275CA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83275CA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D3B4_G_, (int64_t)g_820E0000 + 27896, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83275CA8, 0x83275CA8) { ctx.r3.u64 = n_sub_83275CA8(ctx, base); }

uint64_t n_sub_83276180(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D40C_G_ = int32_t(0x8349D40C);
	if (!UseLiftedCode(144, 0x83276180)) { __imp__sub_83276180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276180);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D40C_G_, (int64_t)g_820E0000 + 28796, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276180, 0x83276180) { ctx.r3.u64 = n_sub_83276180(ctx, base); }

uint64_t n_sub_832761C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D410_G_ = int32_t(0x8349D410);
	if (!UseLiftedCode(144, 0x832761C0)) { __imp__sub_832761C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832761C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D410_G_, (int64_t)g_820E0000 + 28848, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832761C0, 0x832761C0) { ctx.r3.u64 = n_sub_832761C0(ctx, base); }

uint64_t n_sub_83276200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D414_G_ = int32_t(0x8349D414);
	if (!UseLiftedCode(144, 0x83276200)) { __imp__sub_83276200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276200);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D414_G_, (int64_t)g_820E0000 + 28904, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276200, 0x83276200) { ctx.r3.u64 = n_sub_83276200(ctx, base); }

uint64_t n_sub_83276240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D418_G_ = int32_t(0x8349D418);
	if (!UseLiftedCode(144, 0x83276240)) { __imp__sub_83276240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276240);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D418_G_, (int64_t)g_820E0000 + 28952, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276240, 0x83276240) { ctx.r3.u64 = n_sub_83276240(ctx, base); }

uint64_t n_sub_83276280(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D41C_G_ = int32_t(0x8349D41C);
	if (!UseLiftedCode(144, 0x83276280)) { __imp__sub_83276280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276280);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D41C_G_, (int64_t)g_820E0000 + 29008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276280, 0x83276280) { ctx.r3.u64 = n_sub_83276280(ctx, base); }

uint64_t n_sub_832762C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D420_G_ = int32_t(0x8349D420);
	if (!UseLiftedCode(144, 0x832762C0)) { __imp__sub_832762C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832762C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D420_G_, (int64_t)g_820E0000 + 29072, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832762C0, 0x832762C0) { ctx.r3.u64 = n_sub_832762C0(ctx, base); }

uint64_t n_sub_83276300(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D424_G_ = int32_t(0x8349D424);
	if (!UseLiftedCode(144, 0x83276300)) { __imp__sub_83276300(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276300);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D424_G_, (int64_t)g_820E0000 + 29144, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276300, 0x83276300) { ctx.r3.u64 = n_sub_83276300(ctx, base); }

uint64_t n_sub_83276340(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D428_G_ = int32_t(0x8349D428);
	if (!UseLiftedCode(144, 0x83276340)) { __imp__sub_83276340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276340);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D428_G_, (int64_t)g_820E0000 + 29216, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276340, 0x83276340) { ctx.r3.u64 = n_sub_83276340(ctx, base); }

uint64_t n_sub_83276380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D42C_G_ = int32_t(0x8349D42C);
	if (!UseLiftedCode(144, 0x83276380)) { __imp__sub_83276380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276380);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D42C_G_, (int64_t)g_820E0000 + 29280, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276380, 0x83276380) { ctx.r3.u64 = n_sub_83276380(ctx, base); }

uint64_t n_sub_832763C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D430_G_ = int32_t(0x8349D430);
	if (!UseLiftedCode(144, 0x832763C0)) { __imp__sub_832763C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832763C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D430_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832763C0, 0x832763C0) { ctx.r3.u64 = n_sub_832763C0(ctx, base); }

uint64_t n_sub_83276400(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D434_G_ = int32_t(0x8349D434);
	if (!UseLiftedCode(144, 0x83276400)) { __imp__sub_83276400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276400);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D434_G_, (int64_t)g_820E0000 + 29964, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276400, 0x83276400) { ctx.r3.u64 = n_sub_83276400(ctx, base); }

uint64_t n_sub_83276D70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D4E0_G_ = int32_t(0x8349D4E0);
	if (!UseLiftedCode(144, 0x83276D70)) { __imp__sub_83276D70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276D70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E0_G_, (int64_t)g_820E0000 + 7620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276D70, 0x83276D70) { ctx.r3.u64 = n_sub_83276D70(ctx, base); }

uint64_t n_sub_83276DB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D4E4_G_ = int32_t(0x8349D4E4);
	if (!UseLiftedCode(144, 0x83276DB0)) { __imp__sub_83276DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276DB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E4_G_, (int64_t)g_820E0000 + 7572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276DB0, 0x83276DB0) { ctx.r3.u64 = n_sub_83276DB0(ctx, base); }

uint64_t n_sub_83276DF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D4E8_G_ = int32_t(0x8349D4E8);
	if (!UseLiftedCode(144, 0x83276DF0)) { __imp__sub_83276DF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276DF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4E8_G_, (int64_t)g_820E0000 + 7712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276DF0, 0x83276DF0) { ctx.r3.u64 = n_sub_83276DF0(ctx, base); }

uint64_t n_sub_83276E30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D4EC_G_ = int32_t(0x8349D4EC);
	if (!UseLiftedCode(144, 0x83276E30)) { __imp__sub_83276E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276E30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4EC_G_, (int64_t)g_820E0000 + 8008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276E30, 0x83276E30) { ctx.r3.u64 = n_sub_83276E30(ctx, base); }

uint64_t n_sub_83276E70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D4F0_G_ = int32_t(0x8349D4F0);
	if (!UseLiftedCode(144, 0x83276E70)) { __imp__sub_83276E70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83276E70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D4F0_G_, (int64_t)g_820E0000 + 8076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83276E70, 0x83276E70) { ctx.r3.u64 = n_sub_83276E70(ctx, base); }

uint64_t n_sub_83277348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D548_G_ = int32_t(0x8349D548);
	if (!UseLiftedCode(144, 0x83277348)) { __imp__sub_83277348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D548_G_, (int64_t)g_820E0000 + 9052, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277348, 0x83277348) { ctx.r3.u64 = n_sub_83277348(ctx, base); }

uint64_t n_sub_83277388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D54C_G_ = int32_t(0x8349D54C);
	if (!UseLiftedCode(144, 0x83277388)) { __imp__sub_83277388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D54C_G_, (int64_t)g_820E0000 + 9200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277388, 0x83277388) { ctx.r3.u64 = n_sub_83277388(ctx, base); }

uint64_t n_sub_832773C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D550_G_ = int32_t(0x8349D550);
	if (!UseLiftedCode(144, 0x832773C8)) { __imp__sub_832773C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832773C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D550_G_, (int64_t)g_820E0000 + 9148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832773C8, 0x832773C8) { ctx.r3.u64 = n_sub_832773C8(ctx, base); }

uint64_t n_sub_83277408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D554_G_ = int32_t(0x8349D554);
	if (!UseLiftedCode(144, 0x83277408)) { __imp__sub_83277408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D554_G_, (int64_t)g_820E0000 + 9100, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277408, 0x83277408) { ctx.r3.u64 = n_sub_83277408(ctx, base); }

uint64_t n_sub_83277448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D558_G_ = int32_t(0x8349D558);
	if (!UseLiftedCode(144, 0x83277448)) { __imp__sub_83277448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D558_G_, (int64_t)g_820E0000 + 9248, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277448, 0x83277448) { ctx.r3.u64 = n_sub_83277448(ctx, base); }

uint64_t n_sub_83277488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D55C_G_ = int32_t(0x8349D55C);
	if (!UseLiftedCode(144, 0x83277488)) { __imp__sub_83277488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D55C_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277488, 0x83277488) { ctx.r3.u64 = n_sub_83277488(ctx, base); }

uint64_t n_sub_83277960(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D5B4_G_ = int32_t(0x8349D5B4);
	if (!UseLiftedCode(144, 0x83277960)) { __imp__sub_83277960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277960);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5B4_G_, (int64_t)g_820E0000 + 31256, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277960, 0x83277960) { ctx.r3.u64 = n_sub_83277960(ctx, base); }

uint64_t n_sub_832779A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D5B8_G_ = int32_t(0x8349D5B8);
	if (!UseLiftedCode(144, 0x832779A0)) { __imp__sub_832779A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832779A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5B8_G_, (int64_t)g_820E0000 + 31308, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832779A0, 0x832779A0) { ctx.r3.u64 = n_sub_832779A0(ctx, base); }

uint64_t n_sub_832779E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D5BC_G_ = int32_t(0x8349D5BC);
	if (!UseLiftedCode(144, 0x832779E0)) { __imp__sub_832779E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832779E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5BC_G_, (int64_t)g_820E0000 + 31364, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832779E0, 0x832779E0) { ctx.r3.u64 = n_sub_832779E0(ctx, base); }

uint64_t n_sub_83277A20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D5C0_G_ = int32_t(0x8349D5C0);
	if (!UseLiftedCode(144, 0x83277A20)) { __imp__sub_83277A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277A20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5C0_G_, (int64_t)g_820E0000 + 31416, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277A20, 0x83277A20) { ctx.r3.u64 = n_sub_83277A20(ctx, base); }

uint64_t n_sub_83277A60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D5C4_G_ = int32_t(0x8349D5C4);
	if (!UseLiftedCode(144, 0x83277A60)) { __imp__sub_83277A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277A60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D5C4_G_, (int64_t)g_820E0000 + 31476, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277A60, 0x83277A60) { ctx.r3.u64 = n_sub_83277A60(ctx, base); }

uint64_t n_sub_83277F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D61C_G_ = int32_t(0x8349D61C);
	if (!UseLiftedCode(144, 0x83277F38)) { __imp__sub_83277F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D61C_G_, (int64_t)g_820E0000 + 31764, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277F38, 0x83277F38) { ctx.r3.u64 = n_sub_83277F38(ctx, base); }

uint64_t n_sub_83277F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D620_G_ = int32_t(0x8349D620);
	if (!UseLiftedCode(144, 0x83277F78)) { __imp__sub_83277F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D620_G_, (int64_t)g_820E0000 + 31812, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277F78, 0x83277F78) { ctx.r3.u64 = n_sub_83277F78(ctx, base); }

uint64_t n_sub_83277FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D624_G_ = int32_t(0x8349D624);
	if (!UseLiftedCode(144, 0x83277FB8)) { __imp__sub_83277FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D624_G_, (int64_t)g_820E0000 + 31872, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277FB8, 0x83277FB8) { ctx.r3.u64 = n_sub_83277FB8(ctx, base); }

uint64_t n_sub_83277FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D628_G_ = int32_t(0x8349D628);
	if (!UseLiftedCode(144, 0x83277FF8)) { __imp__sub_83277FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83277FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D628_G_, (int64_t)g_820E0000 + 31932, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83277FF8, 0x83277FF8) { ctx.r3.u64 = n_sub_83277FF8(ctx, base); }

uint64_t n_sub_83278038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D62C_G_ = int32_t(0x8349D62C);
	if (!UseLiftedCode(144, 0x83278038)) { __imp__sub_83278038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D62C_G_, (int64_t)g_820E0000 + 31988, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278038, 0x83278038) { ctx.r3.u64 = n_sub_83278038(ctx, base); }

uint64_t n_sub_83278078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D630_G_ = int32_t(0x8349D630);
	if (!UseLiftedCode(144, 0x83278078)) { __imp__sub_83278078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D630_G_, (int64_t)g_820E0000 + 32044, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278078, 0x83278078) { ctx.r3.u64 = n_sub_83278078(ctx, base); }

uint64_t n_sub_832780B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D634_G_ = int32_t(0x8349D634);
	if (!UseLiftedCode(144, 0x832780B8)) { __imp__sub_832780B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832780B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D634_G_, (int64_t)g_820E0000 + 32100, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832780B8, 0x832780B8) { ctx.r3.u64 = n_sub_832780B8(ctx, base); }

uint64_t n_sub_832780F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D638_G_ = int32_t(0x8349D638);
	if (!UseLiftedCode(144, 0x832780F8)) { __imp__sub_832780F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832780F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D638_G_, (int64_t)g_820E0000 + 32156, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832780F8, 0x832780F8) { ctx.r3.u64 = n_sub_832780F8(ctx, base); }

uint64_t n_sub_83278138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D63C_G_ = int32_t(0x8349D63C);
	if (!UseLiftedCode(144, 0x83278138)) { __imp__sub_83278138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D63C_G_, (int64_t)g_820E0000 + 32212, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278138, 0x83278138) { ctx.r3.u64 = n_sub_83278138(ctx, base); }

uint64_t n_sub_83278178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D640_G_ = int32_t(0x8349D640);
	if (!UseLiftedCode(144, 0x83278178)) { __imp__sub_83278178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D640_G_, (int64_t)g_820E0000 + 32272, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278178, 0x83278178) { ctx.r3.u64 = n_sub_83278178(ctx, base); }

uint64_t n_sub_832781B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D644_G_ = int32_t(0x8349D644);
	if (!UseLiftedCode(144, 0x832781B8)) { __imp__sub_832781B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832781B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D644_G_, (int64_t)g_820E0000 + 32344, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 27008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832781B8, 0x832781B8) { ctx.r3.u64 = n_sub_832781B8(ctx, base); }

uint64_t n_sub_832781F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D648_G_ = int32_t(0x8349D648);
	if (!UseLiftedCode(144, 0x832781F8)) { __imp__sub_832781F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832781F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D648_G_, (int64_t)g_820E0000 + 32416, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832781F8, 0x832781F8) { ctx.r3.u64 = n_sub_832781F8(ctx, base); }

uint64_t n_sub_83278238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D64C_G_ = int32_t(0x8349D64C);
	if (!UseLiftedCode(144, 0x83278238)) { __imp__sub_83278238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D64C_G_, (int64_t)g_820E0000 + 32480, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278238, 0x83278238) { ctx.r3.u64 = n_sub_83278238(ctx, base); }

uint64_t n_sub_83278278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D650_G_ = int32_t(0x8349D650);
	if (!UseLiftedCode(144, 0x83278278)) { __imp__sub_83278278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D650_G_, (int64_t)g_820E0000 + 32540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278278, 0x83278278) { ctx.r3.u64 = n_sub_83278278(ctx, base); }

uint64_t n_sub_832782B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D654_G_ = int32_t(0x8349D654);
	if (!UseLiftedCode(144, 0x832782B8)) { __imp__sub_832782B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832782B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D654_G_, (int64_t)g_820E0000 + 32596, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832782B8, 0x832782B8) { ctx.r3.u64 = n_sub_832782B8(ctx, base); }

uint64_t n_sub_832782F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D658_G_ = int32_t(0x8349D658);
	if (!UseLiftedCode(144, 0x832782F8)) { __imp__sub_832782F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832782F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D658_G_, (int64_t)g_820E0000 + 32652, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832782F8, 0x832782F8) { ctx.r3.u64 = n_sub_832782F8(ctx, base); }

uint64_t n_sub_83278338(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D65C_G_ = int32_t(0x8349D65C);
	if (!UseLiftedCode(144, 0x83278338)) { __imp__sub_83278338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278338);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D65C_G_, (int64_t)g_820E0000 + 32708, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278338, 0x83278338) { ctx.r3.u64 = n_sub_83278338(ctx, base); }

uint64_t n_sub_83278378(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D660_G_ = int32_t(0x8349D660);
	if (!UseLiftedCode(144, 0x83278378)) { __imp__sub_83278378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278378);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D660_G_, (int64_t)g_820E0000 + 32764, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278378, 0x83278378) { ctx.r3.u64 = n_sub_83278378(ctx, base); }

uint64_t n_sub_832783B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D664_G_ = int32_t(0x8349D664);
	if (!UseLiftedCode(144, 0x832783B8)) { __imp__sub_832783B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832783B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D664_G_, (int64_t)g_820F0000 - 32712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832783B8, 0x832783B8) { ctx.r3.u64 = n_sub_832783B8(ctx, base); }

uint64_t n_sub_832783F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D668_G_ = int32_t(0x8349D668);
	if (!UseLiftedCode(144, 0x832783F8)) { __imp__sub_832783F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832783F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D668_G_, (int64_t)g_820F0000 - 32652, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832783F8, 0x832783F8) { ctx.r3.u64 = n_sub_832783F8(ctx, base); }

uint64_t n_sub_83278438(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D66C_G_ = int32_t(0x8349D66C);
	if (!UseLiftedCode(144, 0x83278438)) { __imp__sub_83278438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278438);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D66C_G_, (int64_t)g_820F0000 - 32588, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278438, 0x83278438) { ctx.r3.u64 = n_sub_83278438(ctx, base); }

uint64_t n_sub_83278478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D670_G_ = int32_t(0x8349D670);
	if (!UseLiftedCode(144, 0x83278478)) { __imp__sub_83278478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D670_G_, (int64_t)g_820F0000 - 32528, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278478, 0x83278478) { ctx.r3.u64 = n_sub_83278478(ctx, base); }

uint64_t n_sub_832784B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D674_G_ = int32_t(0x8349D674);
	if (!UseLiftedCode(144, 0x832784B8)) { __imp__sub_832784B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832784B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D674_G_, (int64_t)g_820F0000 - 32472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832784B8, 0x832784B8) { ctx.r3.u64 = n_sub_832784B8(ctx, base); }

uint64_t n_sub_832784F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D678_G_ = int32_t(0x8349D678);
	if (!UseLiftedCode(144, 0x832784F8)) { __imp__sub_832784F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832784F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D678_G_, (int64_t)g_820F0000 - 32416, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832784F8, 0x832784F8) { ctx.r3.u64 = n_sub_832784F8(ctx, base); }

uint64_t n_sub_83278538(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D67C_G_ = int32_t(0x8349D67C);
	if (!UseLiftedCode(144, 0x83278538)) { __imp__sub_83278538(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278538);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D67C_G_, (int64_t)g_820E0000 + 18548, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278538, 0x83278538) { ctx.r3.u64 = n_sub_83278538(ctx, base); }

uint64_t n_sub_83278A10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D6D4_G_ = int32_t(0x8349D6D4);
	if (!UseLiftedCode(144, 0x83278A10)) { __imp__sub_83278A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6D4_G_, (int64_t)g_820F0000 - 32208, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278A10, 0x83278A10) { ctx.r3.u64 = n_sub_83278A10(ctx, base); }

uint64_t n_sub_83278A50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D6D8_G_ = int32_t(0x8349D6D8);
	if (!UseLiftedCode(144, 0x83278A50)) { __imp__sub_83278A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6D8_G_, (int64_t)g_820F0000 - 32160, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278A50, 0x83278A50) { ctx.r3.u64 = n_sub_83278A50(ctx, base); }

uint64_t n_sub_83278A90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D6DC_G_ = int32_t(0x8349D6DC);
	if (!UseLiftedCode(144, 0x83278A90)) { __imp__sub_83278A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278A90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6DC_G_, (int64_t)g_820F0000 - 32120, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278A90, 0x83278A90) { ctx.r3.u64 = n_sub_83278A90(ctx, base); }

uint64_t n_sub_83278AD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D6E0_G_ = int32_t(0x8349D6E0);
	if (!UseLiftedCode(144, 0x83278AD0)) { __imp__sub_83278AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278AD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6E0_G_, (int64_t)g_820F0000 - 32068, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278AD0, 0x83278AD0) { ctx.r3.u64 = n_sub_83278AD0(ctx, base); }

uint64_t n_sub_83278B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D6E4_G_ = int32_t(0x8349D6E4);
	if (!UseLiftedCode(144, 0x83278B10)) { __imp__sub_83278B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83278B10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D6E4_G_, (int64_t)g_820E0000 + 9304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83278B10, 0x83278B10) { ctx.r3.u64 = n_sub_83278B10(ctx, base); }

uint64_t n_sub_83279828(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D768_G_ = int32_t(0x8349D768);
	if (!UseLiftedCode(144, 0x83279828)) { __imp__sub_83279828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279828);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D768_G_, (int64_t)g_820F0000 - 31940, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279828, 0x83279828) { ctx.r3.u64 = n_sub_83279828(ctx, base); }

uint64_t n_sub_83279868(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D76C_G_ = int32_t(0x8349D76C);
	if (!UseLiftedCode(144, 0x83279868)) { __imp__sub_83279868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279868);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D76C_G_, (int64_t)g_820F0000 - 31888, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279868, 0x83279868) { ctx.r3.u64 = n_sub_83279868(ctx, base); }

uint64_t n_sub_832798A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D770_G_ = int32_t(0x8349D770);
	if (!UseLiftedCode(144, 0x832798A8)) { __imp__sub_832798A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832798A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D770_G_, (int64_t)g_820F0000 - 31832, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832798A8, 0x832798A8) { ctx.r3.u64 = n_sub_832798A8(ctx, base); }

uint64_t n_sub_832798E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D774_G_ = int32_t(0x8349D774);
	if (!UseLiftedCode(144, 0x832798E8)) { __imp__sub_832798E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832798E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D774_G_, (int64_t)g_820F0000 - 31780, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_832798E8, 0x832798E8) { ctx.r3.u64 = n_sub_832798E8(ctx, base); }

uint64_t n_sub_83279928(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D778_G_ = int32_t(0x8349D778);
	if (!UseLiftedCode(144, 0x83279928)) { __imp__sub_83279928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279928);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D778_G_, (int64_t)g_820F0000 - 31716, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279928, 0x83279928) { ctx.r3.u64 = n_sub_83279928(ctx, base); }

uint64_t n_sub_83279E00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7D0_G_ = int32_t(0x8349D7D0);
	if (!UseLiftedCode(144, 0x83279E00)) { __imp__sub_83279E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D0_G_, (int64_t)g_820F0000 - 31408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279E00, 0x83279E00) { ctx.r3.u64 = n_sub_83279E00(ctx, base); }

uint64_t n_sub_83279E40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7D4_G_ = int32_t(0x8349D7D4);
	if (!UseLiftedCode(144, 0x83279E40)) { __imp__sub_83279E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D4_G_, (int64_t)g_820F0000 - 31356, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279E40, 0x83279E40) { ctx.r3.u64 = n_sub_83279E40(ctx, base); }

uint64_t n_sub_83279E80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7D8_G_ = int32_t(0x8349D7D8);
	if (!UseLiftedCode(144, 0x83279E80)) { __imp__sub_83279E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279E80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7D8_G_, (int64_t)g_820F0000 - 31304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279E80, 0x83279E80) { ctx.r3.u64 = n_sub_83279E80(ctx, base); }

uint64_t n_sub_83279EC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7DC_G_ = int32_t(0x8349D7DC);
	if (!UseLiftedCode(144, 0x83279EC0)) { __imp__sub_83279EC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279EC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7DC_G_, (int64_t)g_820F0000 - 31252, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279EC0, 0x83279EC0) { ctx.r3.u64 = n_sub_83279EC0(ctx, base); }

uint64_t n_sub_83279F00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7E0_G_ = int32_t(0x8349D7E0);
	if (!UseLiftedCode(144, 0x83279F00)) { __imp__sub_83279F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E0_G_, (int64_t)g_820F0000 - 31200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279F00, 0x83279F00) { ctx.r3.u64 = n_sub_83279F00(ctx, base); }

uint64_t n_sub_83279F40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7E4_G_ = int32_t(0x8349D7E4);
	if (!UseLiftedCode(144, 0x83279F40)) { __imp__sub_83279F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E4_G_, (int64_t)g_820F0000 - 31148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279F40, 0x83279F40) { ctx.r3.u64 = n_sub_83279F40(ctx, base); }

uint64_t n_sub_83279F80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7E8_G_ = int32_t(0x8349D7E8);
	if (!UseLiftedCode(144, 0x83279F80)) { __imp__sub_83279F80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279F80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7E8_G_, (int64_t)g_820F0000 - 31088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279F80, 0x83279F80) { ctx.r3.u64 = n_sub_83279F80(ctx, base); }

uint64_t n_sub_83279FC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7EC_G_ = int32_t(0x8349D7EC);
	if (!UseLiftedCode(144, 0x83279FC0)) { __imp__sub_83279FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83279FC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7EC_G_, (int64_t)g_820F0000 - 31024, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_83279FC0, 0x83279FC0) { ctx.r3.u64 = n_sub_83279FC0(ctx, base); }

uint64_t n_sub_8327A000(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7F0_G_ = int32_t(0x8349D7F0);
	if (!UseLiftedCode(144, 0x8327A000)) { __imp__sub_8327A000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A000);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F0_G_, (int64_t)g_820F0000 - 30964, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A000, 0x8327A000) { ctx.r3.u64 = n_sub_8327A000(ctx, base); }

uint64_t n_sub_8327A040(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7F4_G_ = int32_t(0x8349D7F4);
	if (!UseLiftedCode(144, 0x8327A040)) { __imp__sub_8327A040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F4_G_, (int64_t)g_820F0000 - 30900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A040, 0x8327A040) { ctx.r3.u64 = n_sub_8327A040(ctx, base); }

uint64_t n_sub_8327A080(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7F8_G_ = int32_t(0x8349D7F8);
	if (!UseLiftedCode(144, 0x8327A080)) { __imp__sub_8327A080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A080);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7F8_G_, (int64_t)g_820F0000 - 30852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A080, 0x8327A080) { ctx.r3.u64 = n_sub_8327A080(ctx, base); }

uint64_t n_sub_8327A0C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D7FC_G_ = int32_t(0x8349D7FC);
	if (!UseLiftedCode(144, 0x8327A0C0)) { __imp__sub_8327A0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A0C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D7FC_G_, (int64_t)g_820F0000 - 30804, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A0C0, 0x8327A0C0) { ctx.r3.u64 = n_sub_8327A0C0(ctx, base); }

uint64_t n_sub_8327A598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D854_G_ = int32_t(0x8349D854);
	if (!UseLiftedCode(144, 0x8327A598)) { __imp__sub_8327A598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D854_G_, (int64_t)g_820F0000 - 30676, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A598, 0x8327A598) { ctx.r3.u64 = n_sub_8327A598(ctx, base); }

uint64_t n_sub_8327A5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D858_G_ = int32_t(0x8349D858);
	if (!UseLiftedCode(144, 0x8327A5D8)) { __imp__sub_8327A5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A5D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D858_G_, (int64_t)g_820F0000 - 30624, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A5D8, 0x8327A5D8) { ctx.r3.u64 = n_sub_8327A5D8(ctx, base); }

uint64_t n_sub_8327A618(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D85C_G_ = int32_t(0x8349D85C);
	if (!UseLiftedCode(144, 0x8327A618)) { __imp__sub_8327A618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A618);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D85C_G_, (int64_t)g_820F0000 - 30560, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A618, 0x8327A618) { ctx.r3.u64 = n_sub_8327A618(ctx, base); }

uint64_t n_sub_8327A658(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D860_G_ = int32_t(0x8349D860);
	if (!UseLiftedCode(144, 0x8327A658)) { __imp__sub_8327A658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A658);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D860_G_, (int64_t)g_820F0000 - 30504, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A658, 0x8327A658) { ctx.r3.u64 = n_sub_8327A658(ctx, base); }

uint64_t n_sub_8327A698(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D864_G_ = int32_t(0x8349D864);
	if (!UseLiftedCode(144, 0x8327A698)) { __imp__sub_8327A698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A698);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D864_G_, (int64_t)g_820F0000 - 30432, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A698, 0x8327A698) { ctx.r3.u64 = n_sub_8327A698(ctx, base); }

uint64_t n_sub_8327A6D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D868_G_ = int32_t(0x8349D868);
	if (!UseLiftedCode(144, 0x8327A6D8)) { __imp__sub_8327A6D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A6D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D868_G_, (int64_t)g_820F0000 - 30360, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A6D8, 0x8327A6D8) { ctx.r3.u64 = n_sub_8327A6D8(ctx, base); }

uint64_t n_sub_8327A718(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D86C_G_ = int32_t(0x8349D86C);
	if (!UseLiftedCode(144, 0x8327A718)) { __imp__sub_8327A718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A718);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D86C_G_, (int64_t)g_820F0000 - 30292, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A718, 0x8327A718) { ctx.r3.u64 = n_sub_8327A718(ctx, base); }

uint64_t n_sub_8327A758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D870_G_ = int32_t(0x8349D870);
	if (!UseLiftedCode(144, 0x8327A758)) { __imp__sub_8327A758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D870_G_, (int64_t)g_820F0000 - 30232, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A758, 0x8327A758) { ctx.r3.u64 = n_sub_8327A758(ctx, base); }

uint64_t n_sub_8327A798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D874_G_ = int32_t(0x8349D874);
	if (!UseLiftedCode(144, 0x8327A798)) { __imp__sub_8327A798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D874_G_, (int64_t)g_820F0000 - 30160, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A798, 0x8327A798) { ctx.r3.u64 = n_sub_8327A798(ctx, base); }

uint64_t n_sub_8327A7D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D878_G_ = int32_t(0x8349D878);
	if (!UseLiftedCode(144, 0x8327A7D8)) { __imp__sub_8327A7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A7D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D878_G_, (int64_t)g_820F0000 - 30088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A7D8, 0x8327A7D8) { ctx.r3.u64 = n_sub_8327A7D8(ctx, base); }

uint64_t n_sub_8327A818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D87C_G_ = int32_t(0x8349D87C);
	if (!UseLiftedCode(144, 0x8327A818)) { __imp__sub_8327A818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D87C_G_, (int64_t)g_820F0000 - 30008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A818, 0x8327A818) { ctx.r3.u64 = n_sub_8327A818(ctx, base); }

uint64_t n_sub_8327A858(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D880_G_ = int32_t(0x8349D880);
	if (!UseLiftedCode(144, 0x8327A858)) { __imp__sub_8327A858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D880_G_, (int64_t)g_820F0000 - 29928, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A858, 0x8327A858) { ctx.r3.u64 = n_sub_8327A858(ctx, base); }

uint64_t n_sub_8327A898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D884_G_ = int32_t(0x8349D884);
	if (!UseLiftedCode(144, 0x8327A898)) { __imp__sub_8327A898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D884_G_, (int64_t)g_820F0000 - 29852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A898, 0x8327A898) { ctx.r3.u64 = n_sub_8327A898(ctx, base); }

uint64_t n_sub_8327A8D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D888_G_ = int32_t(0x8349D888);
	if (!UseLiftedCode(144, 0x8327A8D8)) { __imp__sub_8327A8D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A8D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D888_G_, (int64_t)g_820F0000 - 29800, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A8D8, 0x8327A8D8) { ctx.r3.u64 = n_sub_8327A8D8(ctx, base); }

uint64_t n_sub_8327A918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D88C_G_ = int32_t(0x8349D88C);
	if (!UseLiftedCode(144, 0x8327A918)) { __imp__sub_8327A918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D88C_G_, (int64_t)g_820F0000 - 29736, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A918, 0x8327A918) { ctx.r3.u64 = n_sub_8327A918(ctx, base); }

uint64_t n_sub_8327A958(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D890_G_ = int32_t(0x8349D890);
	if (!UseLiftedCode(144, 0x8327A958)) { __imp__sub_8327A958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A958);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D890_G_, (int64_t)g_820F0000 - 29588, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A958, 0x8327A958) { ctx.r3.u64 = n_sub_8327A958(ctx, base); }

uint64_t n_sub_8327A998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D894_G_ = int32_t(0x8349D894);
	if (!UseLiftedCode(144, 0x8327A998)) { __imp__sub_8327A998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D894_G_, (int64_t)g_820F0000 - 29552, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A998, 0x8327A998) { ctx.r3.u64 = n_sub_8327A998(ctx, base); }

uint64_t n_sub_8327A9D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D898_G_ = int32_t(0x8349D898);
	if (!UseLiftedCode(144, 0x8327A9D8)) { __imp__sub_8327A9D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327A9D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D898_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327A9D8, 0x8327A9D8) { ctx.r3.u64 = n_sub_8327A9D8(ctx, base); }

uint64_t n_sub_8327AA18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D89C_G_ = int32_t(0x8349D89C);
	if (!UseLiftedCode(144, 0x8327AA18)) { __imp__sub_8327AA18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D89C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327AA18, 0x8327AA18) { ctx.r3.u64 = n_sub_8327AA18(ctx, base); }

uint64_t n_sub_8327AA58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D8A0_G_ = int32_t(0x8349D8A0);
	if (!UseLiftedCode(144, 0x8327AA58)) { __imp__sub_8327AA58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327AA58, 0x8327AA58) { ctx.r3.u64 = n_sub_8327AA58(ctx, base); }

uint64_t n_sub_8327AA98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D8A4_G_ = int32_t(0x8349D8A4);
	if (!UseLiftedCode(144, 0x8327AA98)) { __imp__sub_8327AA98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AA98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 26008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327AA98, 0x8327AA98) { ctx.r3.u64 = n_sub_8327AA98(ctx, base); }

uint64_t n_sub_8327AAD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349D8A8_G_ = int32_t(0x8349D8A8);
	if (!UseLiftedCode(144, 0x8327AAD8)) { __imp__sub_8327AAD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327AAD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349D8A8_G_, (int64_t)g_820F0000 - 25764, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327AAD8, 0x8327AAD8) { ctx.r3.u64 = n_sub_8327AAD8(ctx, base); }

uint64_t n_sub_8327B318(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327B318)) { ctx.r8.u64 = arg1; __imp__sub_8327B318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B318);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25856, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327B318, 0x8327B318) { ctx.r3.u64 = n_sub_8327B318(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327B390(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327B390)) { ctx.r8.u64 = arg1; __imp__sub_8327B390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B390);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25800, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327B390, 0x8327B390) { ctx.r3.u64 = n_sub_8327B390(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327B3E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DEEC_G_ = int32_t(0x8349DEEC);
	if (!UseLiftedCode(144, 0x8327B3E8)) { __imp__sub_8327B3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B3E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DEEC_G_, (int64_t)g_820F0000 - 18648, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B3E8, 0x8327B3E8) { ctx.r3.u64 = n_sub_8327B3E8(ctx, base); }

uint64_t n_sub_8327B428(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327B428)) { ctx.r8.u64 = arg1; __imp__sub_8327B428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B428);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25744, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327B428, 0x8327B428) { ctx.r3.u64 = n_sub_8327B428(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327B438(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF00_G_ = int32_t(0x8349DF00);
	if (!UseLiftedCode(144, 0x8327B438)) { __imp__sub_8327B438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B438);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF00_G_, (int64_t)g_820F0000 - 18588, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B438, 0x8327B438) { ctx.r3.u64 = n_sub_8327B438(ctx, base); }

uint64_t n_sub_8327B478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF04_G_ = int32_t(0x8349DF04);
	if (!UseLiftedCode(144, 0x8327B478)) { __imp__sub_8327B478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF04_G_, (int64_t)g_820F0000 - 18312, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B478, 0x8327B478) { ctx.r3.u64 = n_sub_8327B478(ctx, base); }

uint64_t n_sub_8327B4D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF0C_G_ = int32_t(0x8349DF0C);
	if (!UseLiftedCode(144, 0x8327B4D8)) { __imp__sub_8327B4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B4D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF0C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B4D8, 0x8327B4D8) { ctx.r3.u64 = n_sub_8327B4D8(ctx, base); }

uint64_t n_sub_8327B518(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF10_G_ = int32_t(0x8349DF10);
	if (!UseLiftedCode(144, 0x8327B518)) { __imp__sub_8327B518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B518);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF10_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B518, 0x8327B518) { ctx.r3.u64 = n_sub_8327B518(ctx, base); }

uint64_t n_sub_8327B558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF14_G_ = int32_t(0x8349DF14);
	if (!UseLiftedCode(144, 0x8327B558)) { __imp__sub_8327B558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF14_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B558, 0x8327B558) { ctx.r3.u64 = n_sub_8327B558(ctx, base); }

uint64_t n_sub_8327B5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF1C_G_ = int32_t(0x8349DF1C);
	if (!UseLiftedCode(144, 0x8327B5D8)) { __imp__sub_8327B5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B5D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF1C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B5D8, 0x8327B5D8) { ctx.r3.u64 = n_sub_8327B5D8(ctx, base); }

uint64_t n_sub_8327B730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF34_G_ = int32_t(0x8349DF34);
	if (!UseLiftedCode(144, 0x8327B730)) { __imp__sub_8327B730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF34_G_, (int64_t)g_820F0000 - 4648, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B730, 0x8327B730) { ctx.r3.u64 = n_sub_8327B730(ctx, base); }

uint64_t n_sub_8327B770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF38_G_ = int32_t(0x8349DF38);
	if (!UseLiftedCode(144, 0x8327B770)) { __imp__sub_8327B770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF38_G_, (int64_t)g_820F0000 - 4636, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B770, 0x8327B770) { ctx.r3.u64 = n_sub_8327B770(ctx, base); }

uint64_t n_sub_8327B7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF3C_G_ = int32_t(0x8349DF3C);
	if (!UseLiftedCode(144, 0x8327B7B0)) { __imp__sub_8327B7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF3C_G_, (int64_t)g_820F0000 - 4624, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B7B0, 0x8327B7B0) { ctx.r3.u64 = n_sub_8327B7B0(ctx, base); }

uint64_t n_sub_8327B7F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF40_G_ = int32_t(0x8349DF40);
	if (!UseLiftedCode(144, 0x8327B7F0)) { __imp__sub_8327B7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B7F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820E0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF40_G_, (int64_t)g_820E0000 + 18472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B7F0, 0x8327B7F0) { ctx.r3.u64 = n_sub_8327B7F0(ctx, base); }

uint64_t n_sub_8327B830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF44_G_ = int32_t(0x8349DF44);
	if (!UseLiftedCode(144, 0x8327B830)) { __imp__sub_8327B830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF44_G_, (int64_t)g_820F0000 - 4612, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B830, 0x8327B830) { ctx.r3.u64 = n_sub_8327B830(ctx, base); }

uint64_t n_sub_8327B870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF48_G_ = int32_t(0x8349DF48);
	if (!UseLiftedCode(144, 0x8327B870)) { __imp__sub_8327B870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF48_G_, (int64_t)g_820F0000 - 4600, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B870, 0x8327B870) { ctx.r3.u64 = n_sub_8327B870(ctx, base); }

uint64_t n_sub_8327B8B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF4C_G_ = int32_t(0x8349DF4C);
	if (!UseLiftedCode(144, 0x8327B8B0)) { __imp__sub_8327B8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B8B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF4C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B8B0, 0x8327B8B0) { ctx.r3.u64 = n_sub_8327B8B0(ctx, base); }

uint64_t n_sub_8327B8F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF50_G_ = int32_t(0x8349DF50);
	if (!UseLiftedCode(144, 0x8327B8F0)) { __imp__sub_8327B8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B8F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF50_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B8F0, 0x8327B8F0) { ctx.r3.u64 = n_sub_8327B8F0(ctx, base); }

uint64_t n_sub_8327B930(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349DF54_G_ = int32_t(0x8349DF54);
	if (!UseLiftedCode(144, 0x8327B930)) { __imp__sub_8327B930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327B930);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349DF54_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327B930, 0x8327B930) { ctx.r3.u64 = n_sub_8327B930(ctx, base); }

uint64_t n_sub_8327C6F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0B4_G_ = int32_t(0x8349E0B4);
	if (!UseLiftedCode(144, 0x8327C6F8)) { __imp__sub_8327C6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C6F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0B4_G_, (int64_t)g_82000000 + 5040, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C6F8, 0x8327C6F8) { ctx.r3.u64 = n_sub_8327C6F8(ctx, base); }

uint64_t n_sub_8327C778(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0BC_G_ = int32_t(0x8349E0BC);
	if (!UseLiftedCode(144, 0x8327C778)) { __imp__sub_8327C778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C778);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0BC_G_, (int64_t)g_82000000 + 5024, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C778, 0x8327C778) { ctx.r3.u64 = n_sub_8327C778(ctx, base); }

uint64_t n_sub_8327C7E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0C4_G_ = int32_t(0x8349E0C4);
	if (!UseLiftedCode(144, 0x8327C7E8)) { __imp__sub_8327C7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C7E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0C4_G_, (int64_t)g_820F0000 + 704, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C7E8, 0x8327C7E8) { ctx.r3.u64 = n_sub_8327C7E8(ctx, base); }

uint64_t n_sub_8327C828(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0C8_G_ = int32_t(0x8349E0C8);
	if (!UseLiftedCode(144, 0x8327C828)) { __imp__sub_8327C828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C828);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0C8_G_, (int64_t)g_820F0000 + 716, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C828, 0x8327C828) { ctx.r3.u64 = n_sub_8327C828(ctx, base); }

uint64_t n_sub_8327C868(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0CC_G_ = int32_t(0x8349E0CC);
	if (!UseLiftedCode(144, 0x8327C868)) { __imp__sub_8327C868(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C868);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0CC_G_, (int64_t)g_820F0000 + 736, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C868, 0x8327C868) { ctx.r3.u64 = n_sub_8327C868(ctx, base); }

uint64_t n_sub_8327C8A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0D0_G_ = int32_t(0x8349E0D0);
	if (!UseLiftedCode(144, 0x8327C8A8)) { __imp__sub_8327C8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C8A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0D0_G_, (int64_t)g_820F0000 + 748, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C8A8, 0x8327C8A8) { ctx.r3.u64 = n_sub_8327C8A8(ctx, base); }

uint64_t n_sub_8327C920(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E0E0_G_ = int32_t(0x8349E0E0);
	if (!UseLiftedCode(144, 0x8327C920)) { __imp__sub_8327C920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327C920);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E0E0_G_, (int64_t)g_820F0000 + 1688, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327C920, 0x8327C920) { ctx.r3.u64 = n_sub_8327C920(ctx, base); }

uint64_t n_sub_8327CDF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E138_G_ = int32_t(0x8349E138);
	if (!UseLiftedCode(144, 0x8327CDF8)) { __imp__sub_8327CDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CDF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E138_G_, (int64_t)g_820F0000 + 2168, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327CDF8, 0x8327CDF8) { ctx.r3.u64 = n_sub_8327CDF8(ctx, base); }

uint64_t n_sub_8327CF60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E170_G_ = int32_t(0x8349E170);
	if (!UseLiftedCode(144, 0x8327CF60)) { __imp__sub_8327CF60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CF60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E170_G_, (int64_t)g_820A0000 - 19424, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327CF60, 0x8327CF60) { ctx.r3.u64 = n_sub_8327CF60(ctx, base); }

uint64_t n_sub_8327CFA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E174_G_ = int32_t(0x8349E174);
	if (!UseLiftedCode(144, 0x8327CFA0)) { __imp__sub_8327CFA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CFA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E174_G_, (int64_t)g_820A0000 - 19472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327CFA0, 0x8327CFA0) { ctx.r3.u64 = n_sub_8327CFA0(ctx, base); }

uint64_t n_sub_8327CFE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E178_G_ = int32_t(0x8349E178);
	if (!UseLiftedCode(144, 0x8327CFE0)) { __imp__sub_8327CFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327CFE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E178_G_, (int64_t)g_820A0000 - 19464, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327CFE0, 0x8327CFE0) { ctx.r3.u64 = n_sub_8327CFE0(ctx, base); }

uint64_t n_sub_8327D020(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E17C_G_ = int32_t(0x8349E17C);
	if (!UseLiftedCode(144, 0x8327D020)) { __imp__sub_8327D020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D020);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E17C_G_, (int64_t)g_820A0000 - 19444, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D020, 0x8327D020) { ctx.r3.u64 = n_sub_8327D020(ctx, base); }

uint64_t n_sub_8327D060(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327D060)) { ctx.r8.u64 = arg1; __imp__sub_8327D060(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D060);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25136, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327D060, 0x8327D060) { ctx.r3.u64 = n_sub_8327D060(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327D070(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327D070)) { ctx.r8.u64 = arg1; __imp__sub_8327D070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D070);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25120, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327D070, 0x8327D070) { ctx.r3.u64 = n_sub_8327D070(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327D080(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327D080)) { ctx.r8.u64 = arg1; __imp__sub_8327D080(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D080);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25104, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327D080, 0x8327D080) { ctx.r3.u64 = n_sub_8327D080(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327D168(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327D168)) { ctx.r8.u64 = arg1; __imp__sub_8327D168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D168);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25088, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327D168, 0x8327D168) { ctx.r3.u64 = n_sub_8327D168(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327D178(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(144, 0x8327D178)) { ctx.r8.u64 = arg1; __imp__sub_8327D178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D178);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25072, arg1);
	return result;
}
PROMOTED_ENTRY(144, sub_8327D178, 0x8327D178) { ctx.r3.u64 = n_sub_8327D178(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8327D188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8349E1F0 = int32_t(0x8349E1F0);
	if (!UseLiftedCode(144, 0x8327D188)) { __imp__sub_8327D188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, g_8349E1F0, (int64_t)g_820A0000 - 28038, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D188, 0x8327D188) { ctx.r3.u64 = n_sub_8327D188(ctx, base); }

uint64_t n_sub_8327D258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E200_G_ = int32_t(0x8349E200);
	if (!UseLiftedCode(144, 0x8327D258)) { __imp__sub_8327D258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E200_G_, (int64_t)g_820A0000 - 19664, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 25008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D258, 0x8327D258) { ctx.r3.u64 = n_sub_8327D258(ctx, base); }

uint64_t n_sub_8327D298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E204_G_ = int32_t(0x8349E204);
	if (!UseLiftedCode(144, 0x8327D298)) { __imp__sub_8327D298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E204_G_, (int64_t)g_820A0000 - 19656, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D298, 0x8327D298) { ctx.r3.u64 = n_sub_8327D298(ctx, base); }

uint64_t n_sub_8327D2D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E208_G_ = int32_t(0x8349E208);
	if (!UseLiftedCode(144, 0x8327D2D8)) { __imp__sub_8327D2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D2D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E208_G_, (int64_t)g_820A0000 - 19636, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D2D8, 0x8327D2D8) { ctx.r3.u64 = n_sub_8327D2D8(ctx, base); }

uint64_t n_sub_8327D318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E20C_G_ = int32_t(0x8349E20C);
	if (!UseLiftedCode(144, 0x8327D318)) { __imp__sub_8327D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E20C_G_, (int64_t)g_820A0000 - 19616, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D318, 0x8327D318) { ctx.r3.u64 = n_sub_8327D318(ctx, base); }

uint64_t n_sub_8327D358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E210_G_ = int32_t(0x8349E210);
	if (!UseLiftedCode(144, 0x8327D358)) { __imp__sub_8327D358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E210_G_, (int64_t)g_820A0000 - 19580, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D358, 0x8327D358) { ctx.r3.u64 = n_sub_8327D358(ctx, base); }

uint64_t n_sub_8327D398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E214_G_ = int32_t(0x8349E214);
	if (!UseLiftedCode(144, 0x8327D398)) { __imp__sub_8327D398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E214_G_, (int64_t)g_820A0000 - 19572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D398, 0x8327D398) { ctx.r3.u64 = n_sub_8327D398(ctx, base); }

uint64_t n_sub_8327D3D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E218_G_ = int32_t(0x8349E218);
	if (!UseLiftedCode(144, 0x8327D3D8)) { __imp__sub_8327D3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D3D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E218_G_, (int64_t)g_820A0000 - 19532, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D3D8, 0x8327D3D8) { ctx.r3.u64 = n_sub_8327D3D8(ctx, base); }

uint64_t n_sub_8327D418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E21C_G_ = int32_t(0x8349E21C);
	if (!UseLiftedCode(144, 0x8327D418)) { __imp__sub_8327D418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E21C_G_, (int64_t)g_820A0000 - 19520, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D418, 0x8327D418) { ctx.r3.u64 = n_sub_8327D418(ctx, base); }

uint64_t n_sub_8327D458(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E220_G_ = int32_t(0x8349E220);
	if (!UseLiftedCode(144, 0x8327D458)) { __imp__sub_8327D458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D458);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E220_G_, (int64_t)g_820A0000 - 19512, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D458, 0x8327D458) { ctx.r3.u64 = n_sub_8327D458(ctx, base); }

uint64_t n_sub_8327D498(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E224_G_ = int32_t(0x8349E224);
	if (!UseLiftedCode(144, 0x8327D498)) { __imp__sub_8327D498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D498);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E224_G_, (int64_t)g_820A0000 - 19504, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D498, 0x8327D498) { ctx.r3.u64 = n_sub_8327D498(ctx, base); }

uint64_t n_sub_8327D4D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E228_G_ = int32_t(0x8349E228);
	if (!UseLiftedCode(144, 0x8327D4D8)) { __imp__sub_8327D4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D4D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E228_G_, (int64_t)g_820A0000 - 19488, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D4D8, 0x8327D4D8) { ctx.r3.u64 = n_sub_8327D4D8(ctx, base); }

uint64_t n_sub_8327D530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E240_G_ = int32_t(0x8349E240);
	if (!UseLiftedCode(144, 0x8327D530)) { __imp__sub_8327D530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D530);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E240_G_, (int64_t)g_820A0000 - 19740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D530, 0x8327D530) { ctx.r3.u64 = n_sub_8327D530(ctx, base); }

uint64_t n_sub_8327D570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E244_G_ = int32_t(0x8349E244);
	if (!UseLiftedCode(144, 0x8327D570)) { __imp__sub_8327D570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D570);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E244_G_, (int64_t)g_820A0000 - 19732, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D570, 0x8327D570) { ctx.r3.u64 = n_sub_8327D570(ctx, base); }

uint64_t n_sub_8327D5B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E248_G_ = int32_t(0x8349E248);
	if (!UseLiftedCode(144, 0x8327D5B0)) { __imp__sub_8327D5B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D5B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E248_G_, (int64_t)g_820A0000 - 19712, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D5B0, 0x8327D5B0) { ctx.r3.u64 = n_sub_8327D5B0(ctx, base); }

uint64_t n_sub_8327D5F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E24C_G_ = int32_t(0x8349E24C);
	if (!UseLiftedCode(144, 0x8327D5F0)) { __imp__sub_8327D5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D5F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E24C_G_, (int64_t)g_820A0000 - 19692, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D5F0, 0x8327D5F0) { ctx.r3.u64 = n_sub_8327D5F0(ctx, base); }

uint64_t n_sub_8327D630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E250_G_ = int32_t(0x8349E250);
	if (!UseLiftedCode(144, 0x8327D630)) { __imp__sub_8327D630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E250_G_, (int64_t)g_820A0000 - 19836, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D630, 0x8327D630) { ctx.r3.u64 = n_sub_8327D630(ctx, base); }

uint64_t n_sub_8327D670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E254_G_ = int32_t(0x8349E254);
	if (!UseLiftedCode(144, 0x8327D670)) { __imp__sub_8327D670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E254_G_, (int64_t)g_820A0000 - 19828, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D670, 0x8327D670) { ctx.r3.u64 = n_sub_8327D670(ctx, base); }

uint64_t n_sub_8327D6B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E258_G_ = int32_t(0x8349E258);
	if (!UseLiftedCode(144, 0x8327D6B0)) { __imp__sub_8327D6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D6B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E258_G_, (int64_t)g_820A0000 - 19808, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D6B0, 0x8327D6B0) { ctx.r3.u64 = n_sub_8327D6B0(ctx, base); }

uint64_t n_sub_8327D6F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E25C_G_ = int32_t(0x8349E25C);
	if (!UseLiftedCode(144, 0x8327D6F0)) { __imp__sub_8327D6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D6F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E25C_G_, (int64_t)g_820A0000 - 19788, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D6F0, 0x8327D6F0) { ctx.r3.u64 = n_sub_8327D6F0(ctx, base); }

uint64_t n_sub_8327D730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E260_G_ = int32_t(0x8349E260);
	if (!UseLiftedCode(144, 0x8327D730)) { __imp__sub_8327D730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E260_G_, (int64_t)g_820A0000 - 19752, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D730, 0x8327D730) { ctx.r3.u64 = n_sub_8327D730(ctx, base); }

uint64_t n_sub_8327D7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2D0_G_ = int32_t(0x8349E2D0);
	if (!UseLiftedCode(144, 0x8327D7B0)) { __imp__sub_8327D7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D0_G_, (int64_t)g_820A0000 - 19916, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D7B0, 0x8327D7B0) { ctx.r3.u64 = n_sub_8327D7B0(ctx, base); }

uint64_t n_sub_8327D7F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2D4_G_ = int32_t(0x8349E2D4);
	if (!UseLiftedCode(144, 0x8327D7F0)) { __imp__sub_8327D7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D7F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D4_G_, (int64_t)g_820A0000 - 19908, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D7F0, 0x8327D7F0) { ctx.r3.u64 = n_sub_8327D7F0(ctx, base); }

uint64_t n_sub_8327D830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2D8_G_ = int32_t(0x8349E2D8);
	if (!UseLiftedCode(144, 0x8327D830)) { __imp__sub_8327D830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2D8_G_, (int64_t)g_820A0000 - 19888, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D830, 0x8327D830) { ctx.r3.u64 = n_sub_8327D830(ctx, base); }

uint64_t n_sub_8327D870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2DC_G_ = int32_t(0x8349E2DC);
	if (!UseLiftedCode(144, 0x8327D870)) { __imp__sub_8327D870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2DC_G_, (int64_t)g_820A0000 - 19868, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 24288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D870, 0x8327D870) { ctx.r3.u64 = n_sub_8327D870(ctx, base); }

uint64_t n_sub_8327D8B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2E0_G_ = int32_t(0x8349E2E0);
	if (!UseLiftedCode(144, 0x8327D8B0)) { __imp__sub_8327D8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D8B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E0_G_, (int64_t)g_820A0000 - 20040, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D8B0, 0x8327D8B0) { ctx.r3.u64 = n_sub_8327D8B0(ctx, base); }

uint64_t n_sub_8327D8F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2E4_G_ = int32_t(0x8349E2E4);
	if (!UseLiftedCode(144, 0x8327D8F0)) { __imp__sub_8327D8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D8F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E4_G_, (int64_t)g_820A0000 - 20032, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D8F0, 0x8327D8F0) { ctx.r3.u64 = n_sub_8327D8F0(ctx, base); }

uint64_t n_sub_8327D930(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2E8_G_ = int32_t(0x8349E2E8);
	if (!UseLiftedCode(144, 0x8327D930)) { __imp__sub_8327D930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D930);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2E8_G_, (int64_t)g_820A0000 - 20012, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D930, 0x8327D930) { ctx.r3.u64 = n_sub_8327D930(ctx, base); }

uint64_t n_sub_8327D970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2EC_G_ = int32_t(0x8349E2EC);
	if (!UseLiftedCode(144, 0x8327D970)) { __imp__sub_8327D970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D970);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2EC_G_, (int64_t)g_820A0000 - 19992, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D970, 0x8327D970) { ctx.r3.u64 = n_sub_8327D970(ctx, base); }

uint64_t n_sub_8327D9B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2F0_G_ = int32_t(0x8349E2F0);
	if (!UseLiftedCode(144, 0x8327D9B0)) { __imp__sub_8327D9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D9B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2F0_G_, (int64_t)g_820A0000 - 19948, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D9B0, 0x8327D9B0) { ctx.r3.u64 = n_sub_8327D9B0(ctx, base); }

uint64_t n_sub_8327D9F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E2F4_G_ = int32_t(0x8349E2F4);
	if (!UseLiftedCode(144, 0x8327D9F0)) { __imp__sub_8327D9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327D9F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E2F4_G_, (int64_t)g_820A0000 - 19924, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327D9F0, 0x8327D9F0) { ctx.r3.u64 = n_sub_8327D9F0(ctx, base); }

uint64_t n_sub_8327DA68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E308_G_ = int32_t(0x8349E308);
	if (!UseLiftedCode(144, 0x8327DA68)) { __imp__sub_8327DA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DA68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E308_G_, (int64_t)g_820A0000 - 20208, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DA68, 0x8327DA68) { ctx.r3.u64 = n_sub_8327DA68(ctx, base); }

uint64_t n_sub_8327DAA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E30C_G_ = int32_t(0x8349E30C);
	if (!UseLiftedCode(144, 0x8327DAA8)) { __imp__sub_8327DAA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DAA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E30C_G_, (int64_t)g_820A0000 - 20200, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DAA8, 0x8327DAA8) { ctx.r3.u64 = n_sub_8327DAA8(ctx, base); }

uint64_t n_sub_8327DAE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E310_G_ = int32_t(0x8349E310);
	if (!UseLiftedCode(144, 0x8327DAE8)) { __imp__sub_8327DAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DAE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E310_G_, (int64_t)g_820A0000 - 20180, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DAE8, 0x8327DAE8) { ctx.r3.u64 = n_sub_8327DAE8(ctx, base); }

uint64_t n_sub_8327DB28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E314_G_ = int32_t(0x8349E314);
	if (!UseLiftedCode(144, 0x8327DB28)) { __imp__sub_8327DB28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DB28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E314_G_, (int64_t)g_820A0000 - 20160, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DB28, 0x8327DB28) { ctx.r3.u64 = n_sub_8327DB28(ctx, base); }

uint64_t n_sub_8327DB68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E318_G_ = int32_t(0x8349E318);
	if (!UseLiftedCode(144, 0x8327DB68)) { __imp__sub_8327DB68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DB68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E318_G_, (int64_t)g_820A0000 - 20132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DB68, 0x8327DB68) { ctx.r3.u64 = n_sub_8327DB68(ctx, base); }

uint64_t n_sub_8327DBA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E31C_G_ = int32_t(0x8349E31C);
	if (!UseLiftedCode(144, 0x8327DBA8)) { __imp__sub_8327DBA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DBA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E31C_G_, (int64_t)g_820A0000 - 20116, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DBA8, 0x8327DBA8) { ctx.r3.u64 = n_sub_8327DBA8(ctx, base); }

uint64_t n_sub_8327DBE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E320_G_ = int32_t(0x8349E320);
	if (!UseLiftedCode(144, 0x8327DBE8)) { __imp__sub_8327DBE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DBE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E320_G_, (int64_t)g_820A0000 - 20096, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DBE8, 0x8327DBE8) { ctx.r3.u64 = n_sub_8327DBE8(ctx, base); }

uint64_t n_sub_8327DC28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E324_G_ = int32_t(0x8349E324);
	if (!UseLiftedCode(144, 0x8327DC28)) { __imp__sub_8327DC28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DC28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E324_G_, (int64_t)g_820A0000 - 20088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DC28, 0x8327DC28) { ctx.r3.u64 = n_sub_8327DC28(ctx, base); }

uint64_t n_sub_8327DC68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E328_G_ = int32_t(0x8349E328);
	if (!UseLiftedCode(144, 0x8327DC68)) { __imp__sub_8327DC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DC68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E328_G_, (int64_t)g_820A0000 - 20076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DC68, 0x8327DC68) { ctx.r3.u64 = n_sub_8327DC68(ctx, base); }

uint64_t n_sub_8327DCA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E32C_G_ = int32_t(0x8349E32C);
	if (!UseLiftedCode(144, 0x8327DCA8)) { __imp__sub_8327DCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DCA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E32C_G_, (int64_t)g_820A0000 - 20056, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DCA8, 0x8327DCA8) { ctx.r3.u64 = n_sub_8327DCA8(ctx, base); }

uint64_t n_sub_8327DCE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E330_G_ = int32_t(0x8349E330);
	if (!UseLiftedCode(144, 0x8327DCE8)) { __imp__sub_8327DCE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DCE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E330_G_, (int64_t)g_820A0000 - 20268, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DCE8, 0x8327DCE8) { ctx.r3.u64 = n_sub_8327DCE8(ctx, base); }

uint64_t n_sub_8327DD28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E334_G_ = int32_t(0x8349E334);
	if (!UseLiftedCode(144, 0x8327DD28)) { __imp__sub_8327DD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DD28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E334_G_, (int64_t)g_820A0000 - 20248, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DD28, 0x8327DD28) { ctx.r3.u64 = n_sub_8327DD28(ctx, base); }

uint64_t n_sub_8327DD68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E338_G_ = int32_t(0x8349E338);
	if (!UseLiftedCode(144, 0x8327DD68)) { __imp__sub_8327DD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DD68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E338_G_, (int64_t)g_820A0000 - 20232, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DD68, 0x8327DD68) { ctx.r3.u64 = n_sub_8327DD68(ctx, base); }

uint64_t n_sub_8327DDE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E34C_G_ = int32_t(0x8349E34C);
	if (!UseLiftedCode(144, 0x8327DDE0)) { __imp__sub_8327DDE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DDE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E34C_G_, (int64_t)g_820A0000 - 20328, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DDE0, 0x8327DDE0) { ctx.r3.u64 = n_sub_8327DDE0(ctx, base); }

uint64_t n_sub_8327DE20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E350_G_ = int32_t(0x8349E350);
	if (!UseLiftedCode(144, 0x8327DE20)) { __imp__sub_8327DE20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DE20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E350_G_, (int64_t)g_820A0000 - 20300, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DE20, 0x8327DE20) { ctx.r3.u64 = n_sub_8327DE20(ctx, base); }

uint64_t n_sub_8327DE60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E354_G_ = int32_t(0x8349E354);
	if (!UseLiftedCode(144, 0x8327DE60)) { __imp__sub_8327DE60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DE60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E354_G_, (int64_t)g_820A0000 - 20276, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DE60, 0x8327DE60) { ctx.r3.u64 = n_sub_8327DE60(ctx, base); }

uint64_t n_sub_8327DED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E368_G_ = int32_t(0x8349E368);
	if (!UseLiftedCode(144, 0x8327DED8)) { __imp__sub_8327DED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DED8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E368_G_, (int64_t)g_820A0000 - 20468, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DED8, 0x8327DED8) { ctx.r3.u64 = n_sub_8327DED8(ctx, base); }

uint64_t n_sub_8327DF18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E36C_G_ = int32_t(0x8349E36C);
	if (!UseLiftedCode(144, 0x8327DF18)) { __imp__sub_8327DF18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E36C_G_, (int64_t)g_820A0000 - 20460, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DF18, 0x8327DF18) { ctx.r3.u64 = n_sub_8327DF18(ctx, base); }

uint64_t n_sub_8327DF58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E370_G_ = int32_t(0x8349E370);
	if (!UseLiftedCode(144, 0x8327DF58)) { __imp__sub_8327DF58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E370_G_, (int64_t)g_820A0000 - 20440, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DF58, 0x8327DF58) { ctx.r3.u64 = n_sub_8327DF58(ctx, base); }

uint64_t n_sub_8327DF98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E374_G_ = int32_t(0x8349E374);
	if (!UseLiftedCode(144, 0x8327DF98)) { __imp__sub_8327DF98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327DF98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E374_G_, (int64_t)g_820A0000 - 20420, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327DF98, 0x8327DF98) { ctx.r3.u64 = n_sub_8327DF98(ctx, base); }

uint64_t n_sub_8327E058(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E37C_G_ = int32_t(0x8349E37C);
	if (!UseLiftedCode(144, 0x8327E058)) { __imp__sub_8327E058(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E058);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E37C_G_, (int64_t)g_820A0000 - 20396, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E058, 0x8327E058) { ctx.r3.u64 = n_sub_8327E058(ctx, base); }

uint64_t n_sub_8327E098(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E380_G_ = int32_t(0x8349E380);
	if (!UseLiftedCode(144, 0x8327E098)) { __imp__sub_8327E098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E098);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E380_G_, (int64_t)g_820A0000 - 20360, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E098, 0x8327E098) { ctx.r3.u64 = n_sub_8327E098(ctx, base); }

uint64_t n_sub_8327E0D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E384_G_ = int32_t(0x8349E384);
	if (!UseLiftedCode(144, 0x8327E0D8)) { __imp__sub_8327E0D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E0D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E384_G_, (int64_t)g_820A0000 - 20336, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E0D8, 0x8327E0D8) { ctx.r3.u64 = n_sub_8327E0D8(ctx, base); }

uint64_t n_sub_8327E150(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E398_G_ = int32_t(0x8349E398);
	if (!UseLiftedCode(144, 0x8327E150)) { __imp__sub_8327E150(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E150);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E398_G_, (int64_t)g_820A0000 - 20824, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E150, 0x8327E150) { ctx.r3.u64 = n_sub_8327E150(ctx, base); }

uint64_t n_sub_8327E190(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E39C_G_ = int32_t(0x8349E39C);
	if (!UseLiftedCode(144, 0x8327E190)) { __imp__sub_8327E190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E39C_G_, (int64_t)g_820A0000 - 20816, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E190, 0x8327E190) { ctx.r3.u64 = n_sub_8327E190(ctx, base); }

uint64_t n_sub_8327E1D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3A0_G_ = int32_t(0x8349E3A0);
	if (!UseLiftedCode(144, 0x8327E1D0)) { __imp__sub_8327E1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E1D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A0_G_, (int64_t)g_820A0000 - 20796, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E1D0, 0x8327E1D0) { ctx.r3.u64 = n_sub_8327E1D0(ctx, base); }

uint64_t n_sub_8327E210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3A4_G_ = int32_t(0x8349E3A4);
	if (!UseLiftedCode(144, 0x8327E210)) { __imp__sub_8327E210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A4_G_, (int64_t)g_820A0000 - 20776, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E210, 0x8327E210) { ctx.r3.u64 = n_sub_8327E210(ctx, base); }

uint64_t n_sub_8327E250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3A8_G_ = int32_t(0x8349E3A8);
	if (!UseLiftedCode(144, 0x8327E250)) { __imp__sub_8327E250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3A8_G_, (int64_t)g_820A0000 - 20740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E250, 0x8327E250) { ctx.r3.u64 = n_sub_8327E250(ctx, base); }

uint64_t n_sub_8327E290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3AC_G_ = int32_t(0x8349E3AC);
	if (!UseLiftedCode(144, 0x8327E290)) { __imp__sub_8327E290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3AC_G_, (int64_t)g_820A0000 - 20732, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E290, 0x8327E290) { ctx.r3.u64 = n_sub_8327E290(ctx, base); }

uint64_t n_sub_8327E2D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3B0_G_ = int32_t(0x8349E3B0);
	if (!UseLiftedCode(144, 0x8327E2D0)) { __imp__sub_8327E2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B0_G_, (int64_t)g_820A0000 - 20696, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E2D0, 0x8327E2D0) { ctx.r3.u64 = n_sub_8327E2D0(ctx, base); }

uint64_t n_sub_8327E310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3B4_G_ = int32_t(0x8349E3B4);
	if (!UseLiftedCode(144, 0x8327E310)) { __imp__sub_8327E310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E310);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B4_G_, (int64_t)g_820A0000 - 20660, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E310, 0x8327E310) { ctx.r3.u64 = n_sub_8327E310(ctx, base); }

uint64_t n_sub_8327E350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3B8_G_ = int32_t(0x8349E3B8);
	if (!UseLiftedCode(144, 0x8327E350)) { __imp__sub_8327E350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E350);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3B8_G_, (int64_t)g_820A0000 - 20652, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E350, 0x8327E350) { ctx.r3.u64 = n_sub_8327E350(ctx, base); }

uint64_t n_sub_8327E390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3BC_G_ = int32_t(0x8349E3BC);
	if (!UseLiftedCode(144, 0x8327E390)) { __imp__sub_8327E390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E390);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3BC_G_, (int64_t)g_820A0000 - 20620, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E390, 0x8327E390) { ctx.r3.u64 = n_sub_8327E390(ctx, base); }

uint64_t n_sub_8327E3D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3C0_G_ = int32_t(0x8349E3C0);
	if (!UseLiftedCode(144, 0x8327E3D0)) { __imp__sub_8327E3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E3D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C0_G_, (int64_t)g_820A0000 - 20604, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 23000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E3D0, 0x8327E3D0) { ctx.r3.u64 = n_sub_8327E3D0(ctx, base); }

uint64_t n_sub_8327E410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3C4_G_ = int32_t(0x8349E3C4);
	if (!UseLiftedCode(144, 0x8327E410)) { __imp__sub_8327E410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C4_G_, (int64_t)g_820A0000 - 20592, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E410, 0x8327E410) { ctx.r3.u64 = n_sub_8327E410(ctx, base); }

uint64_t n_sub_8327E450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3C8_G_ = int32_t(0x8349E3C8);
	if (!UseLiftedCode(144, 0x8327E450)) { __imp__sub_8327E450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3C8_G_, (int64_t)g_820A0000 - 20580, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E450, 0x8327E450) { ctx.r3.u64 = n_sub_8327E450(ctx, base); }

uint64_t n_sub_8327E490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3CC_G_ = int32_t(0x8349E3CC);
	if (!UseLiftedCode(144, 0x8327E490)) { __imp__sub_8327E490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3CC_G_, (int64_t)g_820A0000 - 20572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E490, 0x8327E490) { ctx.r3.u64 = n_sub_8327E490(ctx, base); }

uint64_t n_sub_8327E4D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3D0_G_ = int32_t(0x8349E3D0);
	if (!UseLiftedCode(144, 0x8327E4D0)) { __imp__sub_8327E4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E4D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D0_G_, (int64_t)g_820A0000 - 20556, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E4D0, 0x8327E4D0) { ctx.r3.u64 = n_sub_8327E4D0(ctx, base); }

uint64_t n_sub_8327E510(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3D4_G_ = int32_t(0x8349E3D4);
	if (!UseLiftedCode(144, 0x8327E510)) { __imp__sub_8327E510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E510);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D4_G_, (int64_t)g_820A0000 - 20544, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E510, 0x8327E510) { ctx.r3.u64 = n_sub_8327E510(ctx, base); }

uint64_t n_sub_8327E550(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3D8_G_ = int32_t(0x8349E3D8);
	if (!UseLiftedCode(144, 0x8327E550)) { __imp__sub_8327E550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E550);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3D8_G_, (int64_t)g_820A0000 - 20536, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E550, 0x8327E550) { ctx.r3.u64 = n_sub_8327E550(ctx, base); }

uint64_t n_sub_8327E590(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3DC_G_ = int32_t(0x8349E3DC);
	if (!UseLiftedCode(144, 0x8327E590)) { __imp__sub_8327E590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E590);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3DC_G_, (int64_t)g_820A0000 - 20524, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E590, 0x8327E590) { ctx.r3.u64 = n_sub_8327E590(ctx, base); }

uint64_t n_sub_8327E5D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3E0_G_ = int32_t(0x8349E3E0);
	if (!UseLiftedCode(144, 0x8327E5D0)) { __imp__sub_8327E5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E5D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E0_G_, (int64_t)g_820A0000 - 20512, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E5D0, 0x8327E5D0) { ctx.r3.u64 = n_sub_8327E5D0(ctx, base); }

uint64_t n_sub_8327E610(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3E4_G_ = int32_t(0x8349E3E4);
	if (!UseLiftedCode(144, 0x8327E610)) { __imp__sub_8327E610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E610);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E4_G_, (int64_t)g_820A0000 - 20900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E610, 0x8327E610) { ctx.r3.u64 = n_sub_8327E610(ctx, base); }

uint64_t n_sub_8327E650(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3E8_G_ = int32_t(0x8349E3E8);
	if (!UseLiftedCode(144, 0x8327E650)) { __imp__sub_8327E650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E650);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3E8_G_, (int64_t)g_820A0000 - 20892, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E650, 0x8327E650) { ctx.r3.u64 = n_sub_8327E650(ctx, base); }

uint64_t n_sub_8327E690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3EC_G_ = int32_t(0x8349E3EC);
	if (!UseLiftedCode(144, 0x8327E690)) { __imp__sub_8327E690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3EC_G_, (int64_t)g_820A0000 - 20872, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E690, 0x8327E690) { ctx.r3.u64 = n_sub_8327E690(ctx, base); }

uint64_t n_sub_8327E6D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3F0_G_ = int32_t(0x8349E3F0);
	if (!UseLiftedCode(144, 0x8327E6D0)) { __imp__sub_8327E6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E6D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F0_G_, (int64_t)g_820A0000 - 20852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E6D0, 0x8327E6D0) { ctx.r3.u64 = n_sub_8327E6D0(ctx, base); }

uint64_t n_sub_8327E710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3F4_G_ = int32_t(0x8349E3F4);
	if (!UseLiftedCode(144, 0x8327E710)) { __imp__sub_8327E710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F4_G_, (int64_t)g_820A0000 - 20972, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E710, 0x8327E710) { ctx.r3.u64 = n_sub_8327E710(ctx, base); }

uint64_t n_sub_8327E750(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3F8_G_ = int32_t(0x8349E3F8);
	if (!UseLiftedCode(144, 0x8327E750)) { __imp__sub_8327E750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3F8_G_, (int64_t)g_820A0000 - 20964, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E750, 0x8327E750) { ctx.r3.u64 = n_sub_8327E750(ctx, base); }

uint64_t n_sub_8327E790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E3FC_G_ = int32_t(0x8349E3FC);
	if (!UseLiftedCode(144, 0x8327E790)) { __imp__sub_8327E790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E3FC_G_, (int64_t)g_820A0000 - 20944, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E790, 0x8327E790) { ctx.r3.u64 = n_sub_8327E790(ctx, base); }

uint64_t n_sub_8327E7D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E400_G_ = int32_t(0x8349E400);
	if (!UseLiftedCode(144, 0x8327E7D0)) { __imp__sub_8327E7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E7D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E400_G_, (int64_t)g_820A0000 - 20924, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E7D0, 0x8327E7D0) { ctx.r3.u64 = n_sub_8327E7D0(ctx, base); }

uint64_t n_sub_8327E810(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E404_G_ = int32_t(0x8349E404);
	if (!UseLiftedCode(144, 0x8327E810)) { __imp__sub_8327E810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E810);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E404_G_, (int64_t)g_820A0000 - 21056, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E810, 0x8327E810) { ctx.r3.u64 = n_sub_8327E810(ctx, base); }

uint64_t n_sub_8327E850(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E408_G_ = int32_t(0x8349E408);
	if (!UseLiftedCode(144, 0x8327E850)) { __imp__sub_8327E850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E850);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E408_G_, (int64_t)g_820A0000 - 21048, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E850, 0x8327E850) { ctx.r3.u64 = n_sub_8327E850(ctx, base); }

uint64_t n_sub_8327E890(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E40C_G_ = int32_t(0x8349E40C);
	if (!UseLiftedCode(144, 0x8327E890)) { __imp__sub_8327E890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E40C_G_, (int64_t)g_820A0000 - 21028, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E890, 0x8327E890) { ctx.r3.u64 = n_sub_8327E890(ctx, base); }

uint64_t n_sub_8327E8D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E410_G_ = int32_t(0x8349E410);
	if (!UseLiftedCode(144, 0x8327E8D0)) { __imp__sub_8327E8D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E8D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E410_G_, (int64_t)g_820A0000 - 21008, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E8D0, 0x8327E8D0) { ctx.r3.u64 = n_sub_8327E8D0(ctx, base); }

uint64_t n_sub_8327E910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E414_G_ = int32_t(0x8349E414);
	if (!UseLiftedCode(144, 0x8327E910)) { __imp__sub_8327E910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E414_G_, (int64_t)g_820A0000 - 21140, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E910, 0x8327E910) { ctx.r3.u64 = n_sub_8327E910(ctx, base); }

uint64_t n_sub_8327E950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E418_G_ = int32_t(0x8349E418);
	if (!UseLiftedCode(144, 0x8327E950)) { __imp__sub_8327E950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E418_G_, (int64_t)g_820A0000 - 21132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E950, 0x8327E950) { ctx.r3.u64 = n_sub_8327E950(ctx, base); }

uint64_t n_sub_8327E990(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E41C_G_ = int32_t(0x8349E41C);
	if (!UseLiftedCode(144, 0x8327E990)) { __imp__sub_8327E990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E990);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E41C_G_, (int64_t)g_820A0000 - 21112, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E990, 0x8327E990) { ctx.r3.u64 = n_sub_8327E990(ctx, base); }

uint64_t n_sub_8327E9D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E420_G_ = int32_t(0x8349E420);
	if (!UseLiftedCode(144, 0x8327E9D0)) { __imp__sub_8327E9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327E9D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E420_G_, (int64_t)g_820A0000 - 21092, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327E9D0, 0x8327E9D0) { ctx.r3.u64 = n_sub_8327E9D0(ctx, base); }

uint64_t n_sub_8327EA10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E424_G_ = int32_t(0x8349E424);
	if (!UseLiftedCode(144, 0x8327EA10)) { __imp__sub_8327EA10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E424_G_, (int64_t)g_820A0000 - 21248, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EA10, 0x8327EA10) { ctx.r3.u64 = n_sub_8327EA10(ctx, base); }

uint64_t n_sub_8327EA50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E428_G_ = int32_t(0x8349E428);
	if (!UseLiftedCode(144, 0x8327EA50)) { __imp__sub_8327EA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E428_G_, (int64_t)g_820A0000 - 21224, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EA50, 0x8327EA50) { ctx.r3.u64 = n_sub_8327EA50(ctx, base); }

uint64_t n_sub_8327EA90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E42C_G_ = int32_t(0x8349E42C);
	if (!UseLiftedCode(144, 0x8327EA90)) { __imp__sub_8327EA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EA90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E42C_G_, (int64_t)g_820A0000 - 21208, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EA90, 0x8327EA90) { ctx.r3.u64 = n_sub_8327EA90(ctx, base); }

uint64_t n_sub_8327EAD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E430_G_ = int32_t(0x8349E430);
	if (!UseLiftedCode(144, 0x8327EAD0)) { __imp__sub_8327EAD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EAD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E430_G_, (int64_t)g_820A0000 - 21204, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EAD0, 0x8327EAD0) { ctx.r3.u64 = n_sub_8327EAD0(ctx, base); }

uint64_t n_sub_8327EB10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E434_G_ = int32_t(0x8349E434);
	if (!UseLiftedCode(144, 0x8327EB10)) { __imp__sub_8327EB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E434_G_, (int64_t)g_820A0000 - 21184, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EB10, 0x8327EB10) { ctx.r3.u64 = n_sub_8327EB10(ctx, base); }

uint64_t n_sub_8327EB50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E438_G_ = int32_t(0x8349E438);
	if (!UseLiftedCode(144, 0x8327EB50)) { __imp__sub_8327EB50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E438_G_, (int64_t)g_820A0000 - 21168, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EB50, 0x8327EB50) { ctx.r3.u64 = n_sub_8327EB50(ctx, base); }

uint64_t n_sub_8327EB90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E43C_G_ = int32_t(0x8349E43C);
	if (!UseLiftedCode(144, 0x8327EB90)) { __imp__sub_8327EB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EB90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E43C_G_, (int64_t)g_820A0000 - 21748, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EB90, 0x8327EB90) { ctx.r3.u64 = n_sub_8327EB90(ctx, base); }

uint64_t n_sub_8327EBD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E440_G_ = int32_t(0x8349E440);
	if (!UseLiftedCode(144, 0x8327EBD0)) { __imp__sub_8327EBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EBD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E440_G_, (int64_t)g_820A0000 - 21740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EBD0, 0x8327EBD0) { ctx.r3.u64 = n_sub_8327EBD0(ctx, base); }

uint64_t n_sub_8327EC10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E444_G_ = int32_t(0x8349E444);
	if (!UseLiftedCode(144, 0x8327EC10)) { __imp__sub_8327EC10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E444_G_, (int64_t)g_820A0000 - 21720, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EC10, 0x8327EC10) { ctx.r3.u64 = n_sub_8327EC10(ctx, base); }

uint64_t n_sub_8327EC50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E448_G_ = int32_t(0x8349E448);
	if (!UseLiftedCode(144, 0x8327EC50)) { __imp__sub_8327EC50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E448_G_, (int64_t)g_820A0000 - 21700, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EC50, 0x8327EC50) { ctx.r3.u64 = n_sub_8327EC50(ctx, base); }

uint64_t n_sub_8327EC90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E44C_G_ = int32_t(0x8349E44C);
	if (!UseLiftedCode(144, 0x8327EC90)) { __imp__sub_8327EC90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EC90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E44C_G_, (int64_t)g_820A0000 - 21664, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EC90, 0x8327EC90) { ctx.r3.u64 = n_sub_8327EC90(ctx, base); }

uint64_t n_sub_8327ECD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E450_G_ = int32_t(0x8349E450);
	if (!UseLiftedCode(144, 0x8327ECD0)) { __imp__sub_8327ECD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ECD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E450_G_, (int64_t)g_820A0000 - 21656, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327ECD0, 0x8327ECD0) { ctx.r3.u64 = n_sub_8327ECD0(ctx, base); }

uint64_t n_sub_8327ED10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E454_G_ = int32_t(0x8349E454);
	if (!UseLiftedCode(144, 0x8327ED10)) { __imp__sub_8327ED10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E454_G_, (int64_t)g_820A0000 - 21624, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327ED10, 0x8327ED10) { ctx.r3.u64 = n_sub_8327ED10(ctx, base); }

uint64_t n_sub_8327ED50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E458_G_ = int32_t(0x8349E458);
	if (!UseLiftedCode(144, 0x8327ED50)) { __imp__sub_8327ED50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E458_G_, (int64_t)g_820A0000 - 21592, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327ED50, 0x8327ED50) { ctx.r3.u64 = n_sub_8327ED50(ctx, base); }

uint64_t n_sub_8327ED90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E45C_G_ = int32_t(0x8349E45C);
	if (!UseLiftedCode(144, 0x8327ED90)) { __imp__sub_8327ED90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327ED90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E45C_G_, (int64_t)g_820A0000 - 21584, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327ED90, 0x8327ED90) { ctx.r3.u64 = n_sub_8327ED90(ctx, base); }

uint64_t n_sub_8327EDD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E460_G_ = int32_t(0x8349E460);
	if (!UseLiftedCode(144, 0x8327EDD0)) { __imp__sub_8327EDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EDD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E460_G_, (int64_t)g_820A0000 - 21576, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EDD0, 0x8327EDD0) { ctx.r3.u64 = n_sub_8327EDD0(ctx, base); }

uint64_t n_sub_8327EE10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E464_G_ = int32_t(0x8349E464);
	if (!UseLiftedCode(144, 0x8327EE10)) { __imp__sub_8327EE10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E464_G_, (int64_t)g_820A0000 - 21560, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EE10, 0x8327EE10) { ctx.r3.u64 = n_sub_8327EE10(ctx, base); }

uint64_t n_sub_8327EE50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E468_G_ = int32_t(0x8349E468);
	if (!UseLiftedCode(144, 0x8327EE50)) { __imp__sub_8327EE50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E468_G_, (int64_t)g_820A0000 - 21532, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EE50, 0x8327EE50) { ctx.r3.u64 = n_sub_8327EE50(ctx, base); }

uint64_t n_sub_8327EE90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E46C_G_ = int32_t(0x8349E46C);
	if (!UseLiftedCode(144, 0x8327EE90)) { __imp__sub_8327EE90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EE90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E46C_G_, (int64_t)g_820A0000 - 21520, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EE90, 0x8327EE90) { ctx.r3.u64 = n_sub_8327EE90(ctx, base); }

uint64_t n_sub_8327EED0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E470_G_ = int32_t(0x8349E470);
	if (!UseLiftedCode(144, 0x8327EED0)) { __imp__sub_8327EED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EED0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E470_G_, (int64_t)g_820A0000 - 21508, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EED0, 0x8327EED0) { ctx.r3.u64 = n_sub_8327EED0(ctx, base); }

uint64_t n_sub_8327EF10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E474_G_ = int32_t(0x8349E474);
	if (!UseLiftedCode(144, 0x8327EF10)) { __imp__sub_8327EF10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E474_G_, (int64_t)g_820A0000 - 21500, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EF10, 0x8327EF10) { ctx.r3.u64 = n_sub_8327EF10(ctx, base); }

uint64_t n_sub_8327EF50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E478_G_ = int32_t(0x8349E478);
	if (!UseLiftedCode(144, 0x8327EF50)) { __imp__sub_8327EF50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E478_G_, (int64_t)g_820A0000 - 21488, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EF50, 0x8327EF50) { ctx.r3.u64 = n_sub_8327EF50(ctx, base); }

uint64_t n_sub_8327EF90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E47C_G_ = int32_t(0x8349E47C);
	if (!UseLiftedCode(144, 0x8327EF90)) { __imp__sub_8327EF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327EF90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E47C_G_, (int64_t)g_820A0000 - 21472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 22248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327EF90, 0x8327EF90) { ctx.r3.u64 = n_sub_8327EF90(ctx, base); }

uint64_t n_sub_8327F108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4C0_G_ = int32_t(0x8349E4C0);
	if (!UseLiftedCode(144, 0x8327F108)) { __imp__sub_8327F108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C0_G_, (int64_t)g_820A0000 - 21852, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F108, 0x8327F108) { ctx.r3.u64 = n_sub_8327F108(ctx, base); }

uint64_t n_sub_8327F148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4C4_G_ = int32_t(0x8349E4C4);
	if (!UseLiftedCode(144, 0x8327F148)) { __imp__sub_8327F148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C4_G_, (int64_t)g_820A0000 - 21844, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F148, 0x8327F148) { ctx.r3.u64 = n_sub_8327F148(ctx, base); }

uint64_t n_sub_8327F188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4C8_G_ = int32_t(0x8349E4C8);
	if (!UseLiftedCode(144, 0x8327F188)) { __imp__sub_8327F188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4C8_G_, (int64_t)g_820A0000 - 21824, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F188, 0x8327F188) { ctx.r3.u64 = n_sub_8327F188(ctx, base); }

uint64_t n_sub_8327F1C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4CC_G_ = int32_t(0x8349E4CC);
	if (!UseLiftedCode(144, 0x8327F1C8)) { __imp__sub_8327F1C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F1C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4CC_G_, (int64_t)g_820A0000 - 21804, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F1C8, 0x8327F1C8) { ctx.r3.u64 = n_sub_8327F1C8(ctx, base); }

uint64_t n_sub_8327F208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4D0_G_ = int32_t(0x8349E4D0);
	if (!UseLiftedCode(144, 0x8327F208)) { __imp__sub_8327F208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D0_G_, (int64_t)g_820A0000 - 21784, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F208, 0x8327F208) { ctx.r3.u64 = n_sub_8327F208(ctx, base); }

uint64_t n_sub_8327F248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4D4_G_ = int32_t(0x8349E4D4);
	if (!UseLiftedCode(144, 0x8327F248)) { __imp__sub_8327F248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F248);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D4_G_, (int64_t)g_820A0000 - 21768, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F248, 0x8327F248) { ctx.r3.u64 = n_sub_8327F248(ctx, base); }

uint64_t n_sub_8327F288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4D8_G_ = int32_t(0x8349E4D8);
	if (!UseLiftedCode(144, 0x8327F288)) { __imp__sub_8327F288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4D8_G_, (int64_t)g_820A0000 - 21952, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F288, 0x8327F288) { ctx.r3.u64 = n_sub_8327F288(ctx, base); }

uint64_t n_sub_8327F2C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4DC_G_ = int32_t(0x8349E4DC);
	if (!UseLiftedCode(144, 0x8327F2C8)) { __imp__sub_8327F2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F2C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4DC_G_, (int64_t)g_820A0000 - 21944, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F2C8, 0x8327F2C8) { ctx.r3.u64 = n_sub_8327F2C8(ctx, base); }

uint64_t n_sub_8327F308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4E0_G_ = int32_t(0x8349E4E0);
	if (!UseLiftedCode(144, 0x8327F308)) { __imp__sub_8327F308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E0_G_, (int64_t)g_820A0000 - 21924, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F308, 0x8327F308) { ctx.r3.u64 = n_sub_8327F308(ctx, base); }

uint64_t n_sub_8327F348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4E4_G_ = int32_t(0x8349E4E4);
	if (!UseLiftedCode(144, 0x8327F348)) { __imp__sub_8327F348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E4_G_, (int64_t)g_820A0000 - 21904, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F348, 0x8327F348) { ctx.r3.u64 = n_sub_8327F348(ctx, base); }

uint64_t n_sub_8327F388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4E8_G_ = int32_t(0x8349E4E8);
	if (!UseLiftedCode(144, 0x8327F388)) { __imp__sub_8327F388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4E8_G_, (int64_t)g_820A0000 - 21884, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F388, 0x8327F388) { ctx.r3.u64 = n_sub_8327F388(ctx, base); }

uint64_t n_sub_8327F3C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4EC_G_ = int32_t(0x8349E4EC);
	if (!UseLiftedCode(144, 0x8327F3C8)) { __imp__sub_8327F3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F3C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4EC_G_, (int64_t)g_820A0000 - 21872, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F3C8, 0x8327F3C8) { ctx.r3.u64 = n_sub_8327F3C8(ctx, base); }

uint64_t n_sub_8327F408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4F0_G_ = int32_t(0x8349E4F0);
	if (!UseLiftedCode(144, 0x8327F408)) { __imp__sub_8327F408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F0_G_, (int64_t)g_820A0000 - 22068, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F408, 0x8327F408) { ctx.r3.u64 = n_sub_8327F408(ctx, base); }

uint64_t n_sub_8327F448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4F4_G_ = int32_t(0x8349E4F4);
	if (!UseLiftedCode(144, 0x8327F448)) { __imp__sub_8327F448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F4_G_, (int64_t)g_820A0000 - 22060, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F448, 0x8327F448) { ctx.r3.u64 = n_sub_8327F448(ctx, base); }

uint64_t n_sub_8327F488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4F8_G_ = int32_t(0x8349E4F8);
	if (!UseLiftedCode(144, 0x8327F488)) { __imp__sub_8327F488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4F8_G_, (int64_t)g_820A0000 - 22040, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F488, 0x8327F488) { ctx.r3.u64 = n_sub_8327F488(ctx, base); }

uint64_t n_sub_8327F4C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E4FC_G_ = int32_t(0x8349E4FC);
	if (!UseLiftedCode(144, 0x8327F4C8)) { __imp__sub_8327F4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F4C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E4FC_G_, (int64_t)g_820A0000 - 22020, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F4C8, 0x8327F4C8) { ctx.r3.u64 = n_sub_8327F4C8(ctx, base); }

uint64_t n_sub_8327F508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E500_G_ = int32_t(0x8349E500);
	if (!UseLiftedCode(144, 0x8327F508)) { __imp__sub_8327F508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E500_G_, (int64_t)g_820A0000 - 22000, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F508, 0x8327F508) { ctx.r3.u64 = n_sub_8327F508(ctx, base); }

uint64_t n_sub_8327F548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E504_G_ = int32_t(0x8349E504);
	if (!UseLiftedCode(144, 0x8327F548)) { __imp__sub_8327F548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E504_G_, (int64_t)g_820A0000 - 21988, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F548, 0x8327F548) { ctx.r3.u64 = n_sub_8327F548(ctx, base); }

uint64_t n_sub_8327F588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E508_G_ = int32_t(0x8349E508);
	if (!UseLiftedCode(144, 0x8327F588)) { __imp__sub_8327F588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E508_G_, (int64_t)g_820A0000 - 21972, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F588, 0x8327F588) { ctx.r3.u64 = n_sub_8327F588(ctx, base); }

uint64_t n_sub_8327F5C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E50C_G_ = int32_t(0x8349E50C);
	if (!UseLiftedCode(144, 0x8327F5C8)) { __imp__sub_8327F5C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F5C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E50C_G_, (int64_t)g_820A0000 - 22140, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F5C8, 0x8327F5C8) { ctx.r3.u64 = n_sub_8327F5C8(ctx, base); }

uint64_t n_sub_8327F608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E510_G_ = int32_t(0x8349E510);
	if (!UseLiftedCode(144, 0x8327F608)) { __imp__sub_8327F608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E510_G_, (int64_t)g_820A0000 - 22132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F608, 0x8327F608) { ctx.r3.u64 = n_sub_8327F608(ctx, base); }

uint64_t n_sub_8327F648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E514_G_ = int32_t(0x8349E514);
	if (!UseLiftedCode(144, 0x8327F648)) { __imp__sub_8327F648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E514_G_, (int64_t)g_820A0000 - 22112, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F648, 0x8327F648) { ctx.r3.u64 = n_sub_8327F648(ctx, base); }

uint64_t n_sub_8327F688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E518_G_ = int32_t(0x8349E518);
	if (!UseLiftedCode(144, 0x8327F688)) { __imp__sub_8327F688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E518_G_, (int64_t)g_820A0000 - 22092, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F688, 0x8327F688) { ctx.r3.u64 = n_sub_8327F688(ctx, base); }

uint64_t n_sub_8327F6C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E51C_G_ = int32_t(0x8349E51C);
	if (!UseLiftedCode(144, 0x8327F6C8)) { __imp__sub_8327F6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F6C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E51C_G_, (int64_t)g_820A0000 - 22244, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F6C8, 0x8327F6C8) { ctx.r3.u64 = n_sub_8327F6C8(ctx, base); }

uint64_t n_sub_8327F708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E520_G_ = int32_t(0x8349E520);
	if (!UseLiftedCode(144, 0x8327F708)) { __imp__sub_8327F708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E520_G_, (int64_t)g_820A0000 - 22236, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F708, 0x8327F708) { ctx.r3.u64 = n_sub_8327F708(ctx, base); }

uint64_t n_sub_8327F748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E524_G_ = int32_t(0x8349E524);
	if (!UseLiftedCode(144, 0x8327F748)) { __imp__sub_8327F748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E524_G_, (int64_t)g_820A0000 - 22216, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F748, 0x8327F748) { ctx.r3.u64 = n_sub_8327F748(ctx, base); }

uint64_t n_sub_8327F788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E528_G_ = int32_t(0x8349E528);
	if (!UseLiftedCode(144, 0x8327F788)) { __imp__sub_8327F788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E528_G_, (int64_t)g_820A0000 - 22196, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F788, 0x8327F788) { ctx.r3.u64 = n_sub_8327F788(ctx, base); }

uint64_t n_sub_8327F7C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E52C_G_ = int32_t(0x8349E52C);
	if (!UseLiftedCode(144, 0x8327F7C8)) { __imp__sub_8327F7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F7C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E52C_G_, (int64_t)g_820A0000 - 22176, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F7C8, 0x8327F7C8) { ctx.r3.u64 = n_sub_8327F7C8(ctx, base); }

uint64_t n_sub_8327F808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E530_G_ = int32_t(0x8349E530);
	if (!UseLiftedCode(144, 0x8327F808)) { __imp__sub_8327F808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E530_G_, (int64_t)g_820A0000 - 22296, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F808, 0x8327F808) { ctx.r3.u64 = n_sub_8327F808(ctx, base); }

uint64_t n_sub_8327F848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E534_G_ = int32_t(0x8349E534);
	if (!UseLiftedCode(144, 0x8327F848)) { __imp__sub_8327F848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E534_G_, (int64_t)g_820A0000 - 22288, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F848, 0x8327F848) { ctx.r3.u64 = n_sub_8327F848(ctx, base); }

uint64_t n_sub_8327F888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E538_G_ = int32_t(0x8349E538);
	if (!UseLiftedCode(144, 0x8327F888)) { __imp__sub_8327F888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E538_G_, (int64_t)g_820A0000 - 22268, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F888, 0x8327F888) { ctx.r3.u64 = n_sub_8327F888(ctx, base); }

uint64_t n_sub_8327F8C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E53C_G_ = int32_t(0x8349E53C);
	if (!UseLiftedCode(144, 0x8327F8C8)) { __imp__sub_8327F8C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F8C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E53C_G_, (int64_t)g_820A0000 - 22520, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F8C8, 0x8327F8C8) { ctx.r3.u64 = n_sub_8327F8C8(ctx, base); }

uint64_t n_sub_8327F908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E540_G_ = int32_t(0x8349E540);
	if (!UseLiftedCode(144, 0x8327F908)) { __imp__sub_8327F908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E540_G_, (int64_t)g_820A0000 - 22512, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F908, 0x8327F908) { ctx.r3.u64 = n_sub_8327F908(ctx, base); }

uint64_t n_sub_8327F948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E544_G_ = int32_t(0x8349E544);
	if (!UseLiftedCode(144, 0x8327F948)) { __imp__sub_8327F948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327F948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E544_G_, (int64_t)g_820A0000 - 22492, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327F948, 0x8327F948) { ctx.r3.u64 = n_sub_8327F948(ctx, base); }

uint64_t n_sub_8327FAC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E548_G_ = int32_t(0x8349E548);
	if (!UseLiftedCode(144, 0x8327FAC8)) { __imp__sub_8327FAC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FAC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E548_G_, (int64_t)g_820A0000 - 22472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FAC8, 0x8327FAC8) { ctx.r3.u64 = n_sub_8327FAC8(ctx, base); }

uint64_t n_sub_8327FB08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E54C_G_ = int32_t(0x8349E54C);
	if (!UseLiftedCode(144, 0x8327FB08)) { __imp__sub_8327FB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E54C_G_, (int64_t)g_820A0000 - 22440, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FB08, 0x8327FB08) { ctx.r3.u64 = n_sub_8327FB08(ctx, base); }

uint64_t n_sub_8327FB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E590_G_ = int32_t(0x8349E590);
	if (!UseLiftedCode(144, 0x8327FB48)) { __imp__sub_8327FB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E590_G_, (int64_t)g_820A0000 - 22424, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FB48, 0x8327FB48) { ctx.r3.u64 = n_sub_8327FB48(ctx, base); }

uint64_t n_sub_8327FB88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E594_G_ = int32_t(0x8349E594);
	if (!UseLiftedCode(144, 0x8327FB88)) { __imp__sub_8327FB88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FB88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E594_G_, (int64_t)g_820A0000 - 22392, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FB88, 0x8327FB88) { ctx.r3.u64 = n_sub_8327FB88(ctx, base); }

uint64_t n_sub_8327FBC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E598_G_ = int32_t(0x8349E598);
	if (!UseLiftedCode(144, 0x8327FBC8)) { __imp__sub_8327FBC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FBC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E598_G_, (int64_t)g_820A0000 - 22364, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FBC8, 0x8327FBC8) { ctx.r3.u64 = n_sub_8327FBC8(ctx, base); }

uint64_t n_sub_8327FC08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E59C_G_ = int32_t(0x8349E59C);
	if (!UseLiftedCode(144, 0x8327FC08)) { __imp__sub_8327FC08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E59C_G_, (int64_t)g_820A0000 - 22348, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FC08, 0x8327FC08) { ctx.r3.u64 = n_sub_8327FC08(ctx, base); }

uint64_t n_sub_8327FC48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5A0_G_ = int32_t(0x8349E5A0);
	if (!UseLiftedCode(144, 0x8327FC48)) { __imp__sub_8327FC48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A0_G_, (int64_t)g_820A0000 - 22332, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FC48, 0x8327FC48) { ctx.r3.u64 = n_sub_8327FC48(ctx, base); }

uint64_t n_sub_8327FC88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5A4_G_ = int32_t(0x8349E5A4);
	if (!UseLiftedCode(144, 0x8327FC88)) { __imp__sub_8327FC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FC88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A4_G_, (int64_t)g_820A0000 - 22748, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FC88, 0x8327FC88) { ctx.r3.u64 = n_sub_8327FC88(ctx, base); }

uint64_t n_sub_8327FCC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5A8_G_ = int32_t(0x8349E5A8);
	if (!UseLiftedCode(144, 0x8327FCC8)) { __imp__sub_8327FCC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FCC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5A8_G_, (int64_t)g_820A0000 - 22740, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FCC8, 0x8327FCC8) { ctx.r3.u64 = n_sub_8327FCC8(ctx, base); }

uint64_t n_sub_8327FD08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5AC_G_ = int32_t(0x8349E5AC);
	if (!UseLiftedCode(144, 0x8327FD08)) { __imp__sub_8327FD08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5AC_G_, (int64_t)g_820A0000 - 22720, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FD08, 0x8327FD08) { ctx.r3.u64 = n_sub_8327FD08(ctx, base); }

uint64_t n_sub_8327FD48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5B0_G_ = int32_t(0x8349E5B0);
	if (!UseLiftedCode(144, 0x8327FD48)) { __imp__sub_8327FD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B0_G_, (int64_t)g_820A0000 - 22700, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FD48, 0x8327FD48) { ctx.r3.u64 = n_sub_8327FD48(ctx, base); }

uint64_t n_sub_8327FD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5B4_G_ = int32_t(0x8349E5B4);
	if (!UseLiftedCode(144, 0x8327FD88)) { __imp__sub_8327FD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B4_G_, (int64_t)g_820A0000 - 22672, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FD88, 0x8327FD88) { ctx.r3.u64 = n_sub_8327FD88(ctx, base); }

uint64_t n_sub_8327FDC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5B8_G_ = int32_t(0x8349E5B8);
	if (!UseLiftedCode(144, 0x8327FDC8)) { __imp__sub_8327FDC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FDC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5B8_G_, (int64_t)g_820A0000 - 22656, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FDC8, 0x8327FDC8) { ctx.r3.u64 = n_sub_8327FDC8(ctx, base); }

uint64_t n_sub_8327FE08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5BC_G_ = int32_t(0x8349E5BC);
	if (!UseLiftedCode(144, 0x8327FE08)) { __imp__sub_8327FE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5BC_G_, (int64_t)g_820A0000 - 22636, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FE08, 0x8327FE08) { ctx.r3.u64 = n_sub_8327FE08(ctx, base); }

uint64_t n_sub_8327FE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5C0_G_ = int32_t(0x8349E5C0);
	if (!UseLiftedCode(144, 0x8327FE48)) { __imp__sub_8327FE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C0_G_, (int64_t)g_820A0000 - 22612, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FE48, 0x8327FE48) { ctx.r3.u64 = n_sub_8327FE48(ctx, base); }

uint64_t n_sub_8327FE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5C4_G_ = int32_t(0x8349E5C4);
	if (!UseLiftedCode(144, 0x8327FE88)) { __imp__sub_8327FE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FE88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C4_G_, (int64_t)g_820A0000 - 22592, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FE88, 0x8327FE88) { ctx.r3.u64 = n_sub_8327FE88(ctx, base); }

uint64_t n_sub_8327FEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5C8_G_ = int32_t(0x8349E5C8);
	if (!UseLiftedCode(144, 0x8327FEC8)) { __imp__sub_8327FEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FEC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5C8_G_, (int64_t)g_820A0000 - 22564, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FEC8, 0x8327FEC8) { ctx.r3.u64 = n_sub_8327FEC8(ctx, base); }

uint64_t n_sub_8327FF08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5CC_G_ = int32_t(0x8349E5CC);
	if (!UseLiftedCode(144, 0x8327FF08)) { __imp__sub_8327FF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5CC_G_, (int64_t)g_820A0000 - 22540, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FF08, 0x8327FF08) { ctx.r3.u64 = n_sub_8327FF08(ctx, base); }

uint64_t n_sub_8327FF48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5D0_G_ = int32_t(0x8349E5D0);
	if (!UseLiftedCode(144, 0x8327FF48)) { __imp__sub_8327FF48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D0_G_, (int64_t)g_820A0000 - 23044, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FF48, 0x8327FF48) { ctx.r3.u64 = n_sub_8327FF48(ctx, base); }

uint64_t n_sub_8327FF88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5D4_G_ = int32_t(0x8349E5D4);
	if (!UseLiftedCode(144, 0x8327FF88)) { __imp__sub_8327FF88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FF88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D4_G_, (int64_t)g_820A0000 - 23036, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FF88, 0x8327FF88) { ctx.r3.u64 = n_sub_8327FF88(ctx, base); }

uint64_t n_sub_8327FFC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_8349E5D8_G_ = int32_t(0x8349E5D8);
	if (!UseLiftedCode(144, 0x8327FFC8)) { __imp__sub_8327FFC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8327FFC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349E5D8_G_, (int64_t)g_820A0000 - 23016, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 21104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(144, sub_8327FFC8, 0x8327FFC8) { ctx.r3.u64 = n_sub_8327FFC8(ctx, base); }
