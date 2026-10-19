// Start-up initialisers of global objects (they register property and definition names) at
// 0x8324xxxx, as readable C++.
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

// sub_83240410  [64 bytes]
uint64_t n_sub_83240410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970D4_G_ = int32_t(0x834970D4);
	if (!UseLiftedCode(143, 0x83240410)) { __imp__sub_83240410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240410);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970D4_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240410, 0x83240410) { ctx.r3.u64 = n_sub_83240410(ctx, base); }

uint64_t n_sub_83240488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970E4_G_ = int32_t(0x834970E4);
	if (!UseLiftedCode(143, 0x83240488)) { __imp__sub_83240488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970E4_G_, (int64_t)g_820A0000 + 5764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240488, 0x83240488) { ctx.r3.u64 = n_sub_83240488(ctx, base); }

uint64_t n_sub_832404C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970E8_G_ = int32_t(0x834970E8);
	if (!UseLiftedCode(143, 0x832404C8)) { __imp__sub_832404C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832404C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970E8_G_, (int64_t)g_820A0000 + 5776, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832404C8, 0x832404C8) { ctx.r3.u64 = n_sub_832404C8(ctx, base); }

uint64_t n_sub_83240508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970EC_G_ = int32_t(0x834970EC);
	if (!UseLiftedCode(143, 0x83240508)) { __imp__sub_83240508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970EC_G_, (int64_t)g_820A0000 + 5792, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240508, 0x83240508) { ctx.r3.u64 = n_sub_83240508(ctx, base); }

uint64_t n_sub_83240588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970F4_G_ = int32_t(0x834970F4);
	if (!UseLiftedCode(143, 0x83240588)) { __imp__sub_83240588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970F4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240588, 0x83240588) { ctx.r3.u64 = n_sub_83240588(ctx, base); }

uint64_t n_sub_832405C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970F8_G_ = int32_t(0x834970F8);
	if (!UseLiftedCode(143, 0x832405C8)) { __imp__sub_832405C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832405C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970F8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832405C8, 0x832405C8) { ctx.r3.u64 = n_sub_832405C8(ctx, base); }

uint64_t n_sub_83240608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834970FC_G_ = int32_t(0x834970FC);
	if (!UseLiftedCode(143, 0x83240608)) { __imp__sub_83240608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970FC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240608, 0x83240608) { ctx.r3.u64 = n_sub_83240608(ctx, base); }

uint64_t n_sub_83240708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497118_G_ = int32_t(0x83497118);
	if (!UseLiftedCode(143, 0x83240708)) { __imp__sub_83240708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497118_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240708, 0x83240708) { ctx.r3.u64 = n_sub_83240708(ctx, base); }

uint64_t n_sub_83240BE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497170_G_ = int32_t(0x83497170);
	if (!UseLiftedCode(143, 0x83240BE0)) { __imp__sub_83240BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240BE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497170_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240BE0, 0x83240BE0) { ctx.r3.u64 = n_sub_83240BE0(ctx, base); }

uint64_t n_sub_83240C20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497174_G_ = int32_t(0x83497174);
	if (!UseLiftedCode(143, 0x83240C20)) { __imp__sub_83240C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240C20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497174_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240C20, 0x83240C20) { ctx.r3.u64 = n_sub_83240C20(ctx, base); }

uint64_t n_sub_83240C60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497178_G_ = int32_t(0x83497178);
	if (!UseLiftedCode(143, 0x83240C60)) { __imp__sub_83240C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240C60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497178_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240C60, 0x83240C60) { ctx.r3.u64 = n_sub_83240C60(ctx, base); }

uint64_t n_sub_83240CA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349717C_G_ = int32_t(0x8349717C);
	if (!UseLiftedCode(143, 0x83240CA0)) { __imp__sub_83240CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240CA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349717C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240CA0, 0x83240CA0) { ctx.r3.u64 = n_sub_83240CA0(ctx, base); }

uint64_t n_sub_83240CE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497180_G_ = int32_t(0x83497180);
	if (!UseLiftedCode(143, 0x83240CE0)) { __imp__sub_83240CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240CE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497180_G_, (int64_t)g_820A0000 + 11904, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240CE0, 0x83240CE0) { ctx.r3.u64 = n_sub_83240CE0(ctx, base); }

uint64_t n_sub_83240D58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497188_G_ = int32_t(0x83497188);
	if (!UseLiftedCode(143, 0x83240D58)) { __imp__sub_83240D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240D58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497188_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240D58, 0x83240D58) { ctx.r3.u64 = n_sub_83240D58(ctx, base); }

uint64_t n_sub_83240D98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349718C_G_ = int32_t(0x8349718C);
	if (!UseLiftedCode(143, 0x83240D98)) { __imp__sub_83240D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240D98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349718C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240D98, 0x83240D98) { ctx.r3.u64 = n_sub_83240D98(ctx, base); }

uint64_t n_sub_83240DD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497190_G_ = int32_t(0x83497190);
	if (!UseLiftedCode(143, 0x83240DD8)) { __imp__sub_83240DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240DD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497190_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240DD8, 0x83240DD8) { ctx.r3.u64 = n_sub_83240DD8(ctx, base); }

uint64_t n_sub_83240E18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497194_G_ = int32_t(0x83497194);
	if (!UseLiftedCode(143, 0x83240E18)) { __imp__sub_83240E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240E18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497194_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240E18, 0x83240E18) { ctx.r3.u64 = n_sub_83240E18(ctx, base); }

// sub_83240EF8  [12 bytes]
uint64_t n_sub_83240EF8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83240EF8)) { ctx.r8.u64 = arg1; __imp__sub_83240EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240EF8);
	// Register a function to run at exit (n_sub_82CA3700 is atexit); arg1 is the caller's r8,
	// passed through.
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 280, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83240EF8, 0x83240EF8) { ctx.r3.u64 = n_sub_83240EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F08(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83240F08)) { ctx.r8.u64 = arg1; __imp__sub_83240F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F08);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 264, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83240F08, 0x83240F08) { ctx.r3.u64 = n_sub_83240F08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F18(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83240F18)) { ctx.r8.u64 = arg1; __imp__sub_83240F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F18);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 160, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83240F18, 0x83240F18) { ctx.r3.u64 = n_sub_83240F18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F28(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83240F28)) { ctx.r8.u64 = arg1; __imp__sub_83240F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F28);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 - 56, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83240F28, 0x83240F28) { ctx.r3.u64 = n_sub_83240F28(ctx, base, ctx.r8.u64); }

// sub_83240F70  [64 bytes]
uint64_t n_sub_83240F70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497208_G_ = int32_t(0x83497208);
	if (!UseLiftedCode(143, 0x83240F70)) { __imp__sub_83240F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F70);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497208_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 80, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240F70, 0x83240F70) { ctx.r3.u64 = n_sub_83240F70(ctx, base); }

uint64_t n_sub_83240FB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349720C_G_ = int32_t(0x8349720C);
	if (!UseLiftedCode(143, 0x83240FB0)) { __imp__sub_83240FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240FB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349720C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 96, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240FB0, 0x83240FB0) { ctx.r3.u64 = n_sub_83240FB0(ctx, base); }

uint64_t n_sub_83240FF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497210_G_ = int32_t(0x83497210);
	if (!UseLiftedCode(143, 0x83240FF0)) { __imp__sub_83240FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240FF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497210_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240FF0, 0x83240FF0) { ctx.r3.u64 = n_sub_83240FF0(ctx, base); }

uint64_t n_sub_83241030(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497214_G_ = int32_t(0x83497214);
	if (!UseLiftedCode(143, 0x83241030)) { __imp__sub_83241030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241030);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497214_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241030, 0x83241030) { ctx.r3.u64 = n_sub_83241030(ctx, base); }

uint64_t n_sub_832413B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497254_G_ = int32_t(0x83497254);
	if (!UseLiftedCode(143, 0x832413B8)) { __imp__sub_832413B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832413B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497254_G_, (int64_t)g_820A0000 + 19800, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832413B8, 0x832413B8) { ctx.r3.u64 = n_sub_832413B8(ctx, base); }

uint64_t n_sub_832413F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497258_G_ = int32_t(0x83497258);
	if (!UseLiftedCode(143, 0x832413F8)) { __imp__sub_832413F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832413F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497258_G_, (int64_t)g_820A0000 + 19812, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832413F8, 0x832413F8) { ctx.r3.u64 = n_sub_832413F8(ctx, base); }

uint64_t n_sub_83241438(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349725C_G_ = int32_t(0x8349725C);
	if (!UseLiftedCode(143, 0x83241438)) { __imp__sub_83241438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241438);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349725C_G_, (int64_t)g_820A0000 + 19836, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241438, 0x83241438) { ctx.r3.u64 = n_sub_83241438(ctx, base); }

uint64_t n_sub_83241478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497260_G_ = int32_t(0x83497260);
	if (!UseLiftedCode(143, 0x83241478)) { __imp__sub_83241478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241478);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497260_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241478, 0x83241478) { ctx.r3.u64 = n_sub_83241478(ctx, base); }

uint64_t n_sub_83241C40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497338_G_ = int32_t(0x83497338);
	if (!UseLiftedCode(143, 0x83241C40)) { __imp__sub_83241C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241C40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497338_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241C40, 0x83241C40) { ctx.r3.u64 = n_sub_83241C40(ctx, base); }

uint64_t n_sub_83241C80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349733C_G_ = int32_t(0x8349733C);
	if (!UseLiftedCode(143, 0x83241C80)) { __imp__sub_83241C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241C80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349733C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241C80, 0x83241C80) { ctx.r3.u64 = n_sub_83241C80(ctx, base); }

uint64_t n_sub_83241CC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497340_G_ = int32_t(0x83497340);
	if (!UseLiftedCode(143, 0x83241CC0)) { __imp__sub_83241CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241CC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497340_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241CC0, 0x83241CC0) { ctx.r3.u64 = n_sub_83241CC0(ctx, base); }

uint64_t n_sub_83241D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497344_G_ = int32_t(0x83497344);
	if (!UseLiftedCode(143, 0x83241D00)) { __imp__sub_83241D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497344_G_, (int64_t)g_820A0000 + 22848, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241D00, 0x83241D00) { ctx.r3.u64 = n_sub_83241D00(ctx, base); }

uint64_t n_sub_83241D40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497348_G_ = int32_t(0x83497348);
	if (!UseLiftedCode(143, 0x83241D40)) { __imp__sub_83241D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497348_G_, (int64_t)g_820A0000 + 22864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241D40, 0x83241D40) { ctx.r3.u64 = n_sub_83241D40(ctx, base); }

uint64_t n_sub_83241D80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349734C_G_ = int32_t(0x8349734C);
	if (!UseLiftedCode(143, 0x83241D80)) { __imp__sub_83241D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349734C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241D80, 0x83241D80) { ctx.r3.u64 = n_sub_83241D80(ctx, base); }

uint64_t n_sub_83241DF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349736C_G_ = int32_t(0x8349736C);
	if (!UseLiftedCode(143, 0x83241DF8)) { __imp__sub_83241DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241DF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349736C_G_, (int64_t)g_820A0000 + 24852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241DF8, 0x83241DF8) { ctx.r3.u64 = n_sub_83241DF8(ctx, base); }

uint64_t n_sub_83241E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497370_G_ = int32_t(0x83497370);
	if (!UseLiftedCode(143, 0x83241E38)) { __imp__sub_83241E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497370_G_, (int64_t)g_820A0000 + 25144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241E38, 0x83241E38) { ctx.r3.u64 = n_sub_83241E38(ctx, base); }

uint64_t n_sub_83241E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497374_G_ = int32_t(0x83497374);
	if (!UseLiftedCode(143, 0x83241E78)) { __imp__sub_83241E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497374_G_, (int64_t)g_820A0000 + 25172, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241E78, 0x83241E78) { ctx.r3.u64 = n_sub_83241E78(ctx, base); }

uint64_t n_sub_83241EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497378_G_ = int32_t(0x83497378);
	if (!UseLiftedCode(143, 0x83241EB8)) { __imp__sub_83241EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497378_G_, (int64_t)g_820A0000 + 25192, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241EB8, 0x83241EB8) { ctx.r3.u64 = n_sub_83241EB8(ctx, base); }

uint64_t n_sub_83241EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349737C_G_ = int32_t(0x8349737C);
	if (!UseLiftedCode(143, 0x83241EF8)) { __imp__sub_83241EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349737C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241EF8, 0x83241EF8) { ctx.r3.u64 = n_sub_83241EF8(ctx, base); }

uint64_t n_sub_83241F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497380_G_ = int32_t(0x83497380);
	if (!UseLiftedCode(143, 0x83241F38)) { __imp__sub_83241F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497380_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241F38, 0x83241F38) { ctx.r3.u64 = n_sub_83241F38(ctx, base); }

uint64_t n_sub_83241F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497384_G_ = int32_t(0x83497384);
	if (!UseLiftedCode(143, 0x83241F78)) { __imp__sub_83241F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497384_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241F78, 0x83241F78) { ctx.r3.u64 = n_sub_83241F78(ctx, base); }

uint64_t n_sub_83241FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497388_G_ = int32_t(0x83497388);
	if (!UseLiftedCode(143, 0x83241FB8)) { __imp__sub_83241FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497388_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241FB8, 0x83241FB8) { ctx.r3.u64 = n_sub_83241FB8(ctx, base); }

uint64_t n_sub_83241FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349738C_G_ = int32_t(0x8349738C);
	if (!UseLiftedCode(143, 0x83241FF8)) { __imp__sub_83241FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349738C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83241FF8, 0x83241FF8) { ctx.r3.u64 = n_sub_83241FF8(ctx, base); }

uint64_t n_sub_83242038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497390_G_ = int32_t(0x83497390);
	if (!UseLiftedCode(143, 0x83242038)) { __imp__sub_83242038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497390_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242038, 0x83242038) { ctx.r3.u64 = n_sub_83242038(ctx, base); }

uint64_t n_sub_83242078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497394_G_ = int32_t(0x83497394);
	if (!UseLiftedCode(143, 0x83242078)) { __imp__sub_83242078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497394_G_, (int64_t)g_820A0000 + 26984, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242078, 0x83242078) { ctx.r3.u64 = n_sub_83242078(ctx, base); }

uint64_t n_sub_832420B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497398_G_ = int32_t(0x83497398);
	if (!UseLiftedCode(143, 0x832420B8)) { __imp__sub_832420B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832420B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497398_G_, (int64_t)g_820A0000 + 27272, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832420B8, 0x832420B8) { ctx.r3.u64 = n_sub_832420B8(ctx, base); }

uint64_t n_sub_832420F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349739C_G_ = int32_t(0x8349739C);
	if (!UseLiftedCode(143, 0x832420F8)) { __imp__sub_832420F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832420F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349739C_G_, (int64_t)g_820A0000 + 27280, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832420F8, 0x832420F8) { ctx.r3.u64 = n_sub_832420F8(ctx, base); }

uint64_t n_sub_83242138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973A0_G_ = int32_t(0x834973A0);
	if (!UseLiftedCode(143, 0x83242138)) { __imp__sub_83242138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A0_G_, (int64_t)g_820A0000 + 27300, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242138, 0x83242138) { ctx.r3.u64 = n_sub_83242138(ctx, base); }

uint64_t n_sub_83242178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973A4_G_ = int32_t(0x834973A4);
	if (!UseLiftedCode(143, 0x83242178)) { __imp__sub_83242178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A4_G_, (int64_t)g_820A0000 + 27324, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242178, 0x83242178) { ctx.r3.u64 = n_sub_83242178(ctx, base); }

uint64_t n_sub_832421B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973A8_G_ = int32_t(0x834973A8);
	if (!UseLiftedCode(143, 0x832421B8)) { __imp__sub_832421B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832421B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A8_G_, (int64_t)g_820A0000 + 27348, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832421B8, 0x832421B8) { ctx.r3.u64 = n_sub_832421B8(ctx, base); }

uint64_t n_sub_832421F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973AC_G_ = int32_t(0x834973AC);
	if (!UseLiftedCode(143, 0x832421F8)) { __imp__sub_832421F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832421F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973AC_G_, (int64_t)g_820A0000 + 27372, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832421F8, 0x832421F8) { ctx.r3.u64 = n_sub_832421F8(ctx, base); }

uint64_t n_sub_83242238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973B0_G_ = int32_t(0x834973B0);
	if (!UseLiftedCode(143, 0x83242238)) { __imp__sub_83242238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973B0_G_, (int64_t)g_820A0000 + 27384, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242238, 0x83242238) { ctx.r3.u64 = n_sub_83242238(ctx, base); }

uint64_t n_sub_83242308(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973C0_G_ = int32_t(0x834973C0);
	if (!UseLiftedCode(143, 0x83242308)) { __imp__sub_83242308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242308);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C0_G_, (int64_t)g_820A0000 + 25192, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242308, 0x83242308) { ctx.r3.u64 = n_sub_83242308(ctx, base); }

uint64_t n_sub_83242348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973C4_G_ = int32_t(0x834973C4);
	if (!UseLiftedCode(143, 0x83242348)) { __imp__sub_83242348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C4_G_, (int64_t)g_820A0000 + 27396, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242348, 0x83242348) { ctx.r3.u64 = n_sub_83242348(ctx, base); }

uint64_t n_sub_83242388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973C8_G_ = int32_t(0x834973C8);
	if (!UseLiftedCode(143, 0x83242388)) { __imp__sub_83242388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C8_G_, (int64_t)g_820A0000 + 27408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242388, 0x83242388) { ctx.r3.u64 = n_sub_83242388(ctx, base); }

uint64_t n_sub_832423C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973CC_G_ = int32_t(0x834973CC);
	if (!UseLiftedCode(143, 0x832423C8)) { __imp__sub_832423C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832423C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973CC_G_, (int64_t)g_820A0000 + 27436, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832423C8, 0x832423C8) { ctx.r3.u64 = n_sub_832423C8(ctx, base); }

uint64_t n_sub_83242408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973D0_G_ = int32_t(0x834973D0);
	if (!UseLiftedCode(143, 0x83242408)) { __imp__sub_83242408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D0_G_, (int64_t)g_820A0000 + 27452, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242408, 0x83242408) { ctx.r3.u64 = n_sub_83242408(ctx, base); }

uint64_t n_sub_83242448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973D4_G_ = int32_t(0x834973D4);
	if (!UseLiftedCode(143, 0x83242448)) { __imp__sub_83242448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D4_G_, (int64_t)g_820A0000 + 27472, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242448, 0x83242448) { ctx.r3.u64 = n_sub_83242448(ctx, base); }

uint64_t n_sub_83242488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973D8_G_ = int32_t(0x834973D8);
	if (!UseLiftedCode(143, 0x83242488)) { __imp__sub_83242488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D8_G_, (int64_t)g_820A0000 + 27508, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242488, 0x83242488) { ctx.r3.u64 = n_sub_83242488(ctx, base); }

uint64_t n_sub_832424C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973DC_G_ = int32_t(0x834973DC);
	if (!UseLiftedCode(143, 0x832424C8)) { __imp__sub_832424C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832424C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973DC_G_, (int64_t)g_820A0000 + 27472, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832424C8, 0x832424C8) { ctx.r3.u64 = n_sub_832424C8(ctx, base); }

uint64_t n_sub_83242508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973E0_G_ = int32_t(0x834973E0);
	if (!UseLiftedCode(143, 0x83242508)) { __imp__sub_83242508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973E0_G_, (int64_t)g_820A0000 + 27508, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242508, 0x83242508) { ctx.r3.u64 = n_sub_83242508(ctx, base); }

uint64_t n_sub_83242578(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834973E8_G_ = int32_t(0x834973E8);
	if (!UseLiftedCode(143, 0x83242578)) { __imp__sub_83242578(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242578);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834973E8_G_, (int64_t)g_820A0000 + 27540, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242578, 0x83242578) { ctx.r3.u64 = n_sub_83242578(ctx, base); }

// sub_832425E8  [12 bytes]
uint64_t n_sub_832425E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x832425E8)) { ctx.r8.u64 = arg1; __imp__sub_832425E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832425E8);
	// Register a function to run at exit (n_sub_82CA3700 is atexit); arg1 is the caller's r8,
	// passed through.
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1072, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_832425E8, 0x832425E8) { ctx.r3.u64 = n_sub_832425E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832425F8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x832425F8)) { ctx.r8.u64 = arg1; __imp__sub_832425F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832425F8);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1088, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_832425F8, 0x832425F8) { ctx.r3.u64 = n_sub_832425F8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83242798(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349741C_G_ = int32_t(0x8349741C);
	if (!UseLiftedCode(143, 0x83242798)) { __imp__sub_83242798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242798);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349741C_G_, (int64_t)g_820A0000 + 28812, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242798, 0x83242798) { ctx.r3.u64 = n_sub_83242798(ctx, base); }

uint64_t n_sub_832427D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497428_G_ = int32_t(0x83497428);
	if (!UseLiftedCode(143, 0x832427D8)) { __imp__sub_832427D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832427D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497428_G_, (int64_t)g_820A0000 + 27396, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832427D8, 0x832427D8) { ctx.r3.u64 = n_sub_832427D8(ctx, base); }

uint64_t n_sub_83242818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349742C_G_ = int32_t(0x8349742C);
	if (!UseLiftedCode(143, 0x83242818)) { __imp__sub_83242818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242818);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349742C_G_, (int64_t)g_820A0000 + 28836, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242818, 0x83242818) { ctx.r3.u64 = n_sub_83242818(ctx, base); }

uint64_t n_sub_83242858(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497460_G_ = int32_t(0x83497460);
	if (!UseLiftedCode(143, 0x83242858)) { __imp__sub_83242858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497460_G_, (int64_t)g_820A0000 + 1080, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242858, 0x83242858) { ctx.r3.u64 = n_sub_83242858(ctx, base); }

uint64_t n_sub_83242898(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497464_G_ = int32_t(0x83497464);
	if (!UseLiftedCode(143, 0x83242898)) { __imp__sub_83242898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497464_G_, (int64_t)g_820A0000 + 28868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242898, 0x83242898) { ctx.r3.u64 = n_sub_83242898(ctx, base); }

uint64_t n_sub_832428D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497468_G_ = int32_t(0x83497468);
	if (!UseLiftedCode(143, 0x832428D8)) { __imp__sub_832428D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832428D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497468_G_, (int64_t)g_820A0000 + 28912, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832428D8, 0x832428D8) { ctx.r3.u64 = n_sub_832428D8(ctx, base); }

uint64_t n_sub_83242918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349746C_G_ = int32_t(0x8349746C);
	if (!UseLiftedCode(143, 0x83242918)) { __imp__sub_83242918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242918);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349746C_G_, (int64_t)g_820A0000 + 28952, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242918, 0x83242918) { ctx.r3.u64 = n_sub_83242918(ctx, base); }

uint64_t n_sub_83242958(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497470_G_ = int32_t(0x83497470);
	if (!UseLiftedCode(143, 0x83242958)) { __imp__sub_83242958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242958);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497470_G_, (int64_t)g_820A0000 + 28992, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242958, 0x83242958) { ctx.r3.u64 = n_sub_83242958(ctx, base); }

uint64_t n_sub_83242998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497474_G_ = int32_t(0x83497474);
	if (!UseLiftedCode(143, 0x83242998)) { __imp__sub_83242998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497474_G_, (int64_t)g_820A0000 + 29040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242998, 0x83242998) { ctx.r3.u64 = n_sub_83242998(ctx, base); }

uint64_t n_sub_832429D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497478_G_ = int32_t(0x83497478);
	if (!UseLiftedCode(143, 0x832429D8)) { __imp__sub_832429D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832429D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497478_G_, (int64_t)g_820A0000 + 29084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832429D8, 0x832429D8) { ctx.r3.u64 = n_sub_832429D8(ctx, base); }

uint64_t n_sub_83242A18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349747C_G_ = int32_t(0x8349747C);
	if (!UseLiftedCode(143, 0x83242A18)) { __imp__sub_83242A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349747C_G_, (int64_t)g_820A0000 + 29128, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242A18, 0x83242A18) { ctx.r3.u64 = n_sub_83242A18(ctx, base); }

uint64_t n_sub_83242A58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497480_G_ = int32_t(0x83497480);
	if (!UseLiftedCode(143, 0x83242A58)) { __imp__sub_83242A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497480_G_, (int64_t)g_820A0000 + 29172, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242A58, 0x83242A58) { ctx.r3.u64 = n_sub_83242A58(ctx, base); }

uint64_t n_sub_83242A98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497484_G_ = int32_t(0x83497484);
	if (!UseLiftedCode(143, 0x83242A98)) { __imp__sub_83242A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497484_G_, (int64_t)g_820A0000 + 29216, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242A98, 0x83242A98) { ctx.r3.u64 = n_sub_83242A98(ctx, base); }

uint64_t n_sub_83242AD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497488_G_ = int32_t(0x83497488);
	if (!UseLiftedCode(143, 0x83242AD8)) { __imp__sub_83242AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242AD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497488_G_, (int64_t)g_820A0000 + 29260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242AD8, 0x83242AD8) { ctx.r3.u64 = n_sub_83242AD8(ctx, base); }

uint64_t n_sub_83242B18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349748C_G_ = int32_t(0x8349748C);
	if (!UseLiftedCode(143, 0x83242B18)) { __imp__sub_83242B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242B18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349748C_G_, (int64_t)g_820A0000 + 29304, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242B18, 0x83242B18) { ctx.r3.u64 = n_sub_83242B18(ctx, base); }

uint64_t n_sub_83242C10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974B0_G_ = int32_t(0x834974B0);
	if (!UseLiftedCode(143, 0x83242C10)) { __imp__sub_83242C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242C10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974B0_G_, (int64_t)g_820A0000 + 29352, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242C10, 0x83242C10) { ctx.r3.u64 = n_sub_83242C10(ctx, base); }

uint64_t n_sub_83242C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974B4_G_ = int32_t(0x834974B4);
	if (!UseLiftedCode(143, 0x83242C50)) { __imp__sub_83242C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242C50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974B4_G_, (int64_t)g_820A0000 + 29400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242C50, 0x83242C50) { ctx.r3.u64 = n_sub_83242C50(ctx, base); }

uint64_t n_sub_83242D50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974BC_G_ = int32_t(0x834974BC);
	if (!UseLiftedCode(143, 0x83242D50)) { __imp__sub_83242D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242D50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974BC_G_, (int64_t)g_820A0000 + 26984, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242D50, 0x83242D50) { ctx.r3.u64 = n_sub_83242D50(ctx, base); }

uint64_t n_sub_83242D90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974C0_G_ = int32_t(0x834974C0);
	if (!UseLiftedCode(143, 0x83242D90)) { __imp__sub_83242D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242D90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974C0_G_, (int64_t)g_820A0000 + 29532, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242D90, 0x83242D90) { ctx.r3.u64 = n_sub_83242D90(ctx, base); }

uint64_t n_sub_83242EA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974C8_G_ = int32_t(0x834974C8);
	if (!UseLiftedCode(143, 0x83242EA0)) { __imp__sub_83242EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242EA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974C8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242EA0, 0x83242EA0) { ctx.r3.u64 = n_sub_83242EA0(ctx, base); }

uint64_t n_sub_83242EE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974CC_G_ = int32_t(0x834974CC);
	if (!UseLiftedCode(143, 0x83242EE0)) { __imp__sub_83242EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242EE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974CC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242EE0, 0x83242EE0) { ctx.r3.u64 = n_sub_83242EE0(ctx, base); }

uint64_t n_sub_83242F20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974D0_G_ = int32_t(0x834974D0);
	if (!UseLiftedCode(143, 0x83242F20)) { __imp__sub_83242F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974D0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242F20, 0x83242F20) { ctx.r3.u64 = n_sub_83242F20(ctx, base); }

uint64_t n_sub_83242F60(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83242F60)) { ctx.r8.u64 = arg1; __imp__sub_83242F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F60);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1544, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83242F60, 0x83242F60) { ctx.r3.u64 = n_sub_83242F60(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83242F70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974E4_G_ = int32_t(0x834974E4);
	if (!UseLiftedCode(143, 0x83242F70)) { __imp__sub_83242F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974E4_G_, (int64_t)g_820A0000 + 30572, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242F70, 0x83242F70) { ctx.r3.u64 = n_sub_83242F70(ctx, base); }

uint64_t n_sub_83242FB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974E8_G_ = int32_t(0x834974E8);
	if (!UseLiftedCode(143, 0x83242FB0)) { __imp__sub_83242FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242FB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974E8_G_, (int64_t)g_820A0000 + 30580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242FB0, 0x83242FB0) { ctx.r3.u64 = n_sub_83242FB0(ctx, base); }

uint64_t n_sub_83242FF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974EC_G_ = int32_t(0x834974EC);
	if (!UseLiftedCode(143, 0x83242FF0)) { __imp__sub_83242FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242FF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974EC_G_, (int64_t)g_820A0000 + 30600, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83242FF0, 0x83242FF0) { ctx.r3.u64 = n_sub_83242FF0(ctx, base); }

uint64_t n_sub_83243030(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974F0_G_ = int32_t(0x834974F0);
	if (!UseLiftedCode(143, 0x83243030)) { __imp__sub_83243030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243030);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F0_G_, (int64_t)g_820A0000 + 30612, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243030, 0x83243030) { ctx.r3.u64 = n_sub_83243030(ctx, base); }

uint64_t n_sub_83243070(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974F4_G_ = int32_t(0x834974F4);
	if (!UseLiftedCode(143, 0x83243070)) { __imp__sub_83243070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243070);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F4_G_, (int64_t)g_820A0000 + 30628, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243070, 0x83243070) { ctx.r3.u64 = n_sub_83243070(ctx, base); }

uint64_t n_sub_832430B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974F8_G_ = int32_t(0x834974F8);
	if (!UseLiftedCode(143, 0x832430B0)) { __imp__sub_832430B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832430B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F8_G_, (int64_t)g_820A0000 + 30644, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832430B0, 0x832430B0) { ctx.r3.u64 = n_sub_832430B0(ctx, base); }

uint64_t n_sub_832430F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834974FC_G_ = int32_t(0x834974FC);
	if (!UseLiftedCode(143, 0x832430F0)) { __imp__sub_832430F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832430F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834974FC_G_, (int64_t)g_820A0000 + 30656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832430F0, 0x832430F0) { ctx.r3.u64 = n_sub_832430F0(ctx, base); }

uint64_t n_sub_83243130(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497500_G_ = int32_t(0x83497500);
	if (!UseLiftedCode(143, 0x83243130)) { __imp__sub_83243130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243130);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497500_G_, (int64_t)g_820A0000 + 30672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243130, 0x83243130) { ctx.r3.u64 = n_sub_83243130(ctx, base); }

uint64_t n_sub_83243170(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497504_G_ = int32_t(0x83497504);
	if (!UseLiftedCode(143, 0x83243170)) { __imp__sub_83243170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243170);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497504_G_, (int64_t)g_820A0000 + 30688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243170, 0x83243170) { ctx.r3.u64 = n_sub_83243170(ctx, base); }

uint64_t n_sub_832431B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497508_G_ = int32_t(0x83497508);
	if (!UseLiftedCode(143, 0x832431B0)) { __imp__sub_832431B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832431B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497508_G_, (int64_t)g_820A0000 + 30712, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832431B0, 0x832431B0) { ctx.r3.u64 = n_sub_832431B0(ctx, base); }

uint64_t n_sub_832431F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349750C_G_ = int32_t(0x8349750C);
	if (!UseLiftedCode(143, 0x832431F0)) { __imp__sub_832431F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832431F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349750C_G_, (int64_t)g_820A0000 + 30736, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832431F0, 0x832431F0) { ctx.r3.u64 = n_sub_832431F0(ctx, base); }

uint64_t n_sub_83243230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497510_G_ = int32_t(0x83497510);
	if (!UseLiftedCode(143, 0x83243230)) { __imp__sub_83243230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243230);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497510_G_, (int64_t)g_820A0000 + 30752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243230, 0x83243230) { ctx.r3.u64 = n_sub_83243230(ctx, base); }

uint64_t n_sub_83243270(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497514_G_ = int32_t(0x83497514);
	if (!UseLiftedCode(143, 0x83243270)) { __imp__sub_83243270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243270);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497514_G_, (int64_t)g_820A0000 + 30772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243270, 0x83243270) { ctx.r3.u64 = n_sub_83243270(ctx, base); }

uint64_t n_sub_832432B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497518_G_ = int32_t(0x83497518);
	if (!UseLiftedCode(143, 0x832432B0)) { __imp__sub_832432B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832432B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497518_G_, (int64_t)g_820A0000 + 30784, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832432B0, 0x832432B0) { ctx.r3.u64 = n_sub_832432B0(ctx, base); }

uint64_t n_sub_832432F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349751C_G_ = int32_t(0x8349751C);
	if (!UseLiftedCode(143, 0x832432F0)) { __imp__sub_832432F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832432F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349751C_G_, (int64_t)g_820A0000 + 30808, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832432F0, 0x832432F0) { ctx.r3.u64 = n_sub_832432F0(ctx, base); }

uint64_t n_sub_83243388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497524_G_ = int32_t(0x83497524);
	if (!UseLiftedCode(143, 0x83243388)) { __imp__sub_83243388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497524_G_, (int64_t)g_820A0000 + 30856, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243388, 0x83243388) { ctx.r3.u64 = n_sub_83243388(ctx, base); }

uint64_t n_sub_832433C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497528_G_ = int32_t(0x83497528);
	if (!UseLiftedCode(143, 0x832433C8)) { __imp__sub_832433C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832433C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497528_G_, (int64_t)g_820A0000 + 30880, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832433C8, 0x832433C8) { ctx.r3.u64 = n_sub_832433C8(ctx, base); }

uint64_t n_sub_83243408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349752C_G_ = int32_t(0x8349752C);
	if (!UseLiftedCode(143, 0x83243408)) { __imp__sub_83243408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349752C_G_, (int64_t)g_820A0000 + 30900, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243408, 0x83243408) { ctx.r3.u64 = n_sub_83243408(ctx, base); }

uint64_t n_sub_83243448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497530_G_ = int32_t(0x83497530);
	if (!UseLiftedCode(143, 0x83243448)) { __imp__sub_83243448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497530_G_, (int64_t)g_820A0000 + 30908, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243448, 0x83243448) { ctx.r3.u64 = n_sub_83243448(ctx, base); }

uint64_t n_sub_832434E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497538_G_ = int32_t(0x83497538);
	if (!UseLiftedCode(143, 0x832434E0)) { __imp__sub_832434E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832434E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497538_G_, (int64_t)g_820A0000 + 30920, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 1984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832434E0, 0x832434E0) { ctx.r3.u64 = n_sub_832434E0(ctx, base); }

uint64_t n_sub_83243520(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349753C_G_ = int32_t(0x8349753C);
	if (!UseLiftedCode(143, 0x83243520)) { __imp__sub_83243520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243520);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349753C_G_, (int64_t)g_820A0000 + 30924, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243520, 0x83243520) { ctx.r3.u64 = n_sub_83243520(ctx, base); }

uint64_t n_sub_83243560(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497540_G_ = int32_t(0x83497540);
	if (!UseLiftedCode(143, 0x83243560)) { __imp__sub_83243560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497540_G_, (int64_t)g_820A0000 + 30940, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243560, 0x83243560) { ctx.r3.u64 = n_sub_83243560(ctx, base); }

uint64_t n_sub_832435A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497544_G_ = int32_t(0x83497544);
	if (!UseLiftedCode(143, 0x832435A0)) { __imp__sub_832435A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832435A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497544_G_, (int64_t)g_820A0000 + 30968, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832435A0, 0x832435A0) { ctx.r3.u64 = n_sub_832435A0(ctx, base); }

uint64_t n_sub_83243618(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83243618)) { ctx.r8.u64 = arg1; __imp__sub_83243618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243618);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2224, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83243618, 0x83243618) { ctx.r3.u64 = n_sub_83243618(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832438C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975C0_G_ = int32_t(0x834975C0);
	if (!UseLiftedCode(143, 0x832438C0)) { __imp__sub_832438C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832438C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832438C0, 0x832438C0) { ctx.r3.u64 = n_sub_832438C0(ctx, base); }

uint64_t n_sub_83243900(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975C4_G_ = int32_t(0x834975C4);
	if (!UseLiftedCode(143, 0x83243900)) { __imp__sub_83243900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243900);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243900, 0x83243900) { ctx.r3.u64 = n_sub_83243900(ctx, base); }

uint64_t n_sub_83243940(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975C8_G_ = int32_t(0x834975C8);
	if (!UseLiftedCode(143, 0x83243940)) { __imp__sub_83243940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243940);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243940, 0x83243940) { ctx.r3.u64 = n_sub_83243940(ctx, base); }

uint64_t n_sub_83243980(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975CC_G_ = int32_t(0x834975CC);
	if (!UseLiftedCode(143, 0x83243980)) { __imp__sub_83243980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243980);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975CC_G_, (int64_t)g_820A0000 + 32344, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243980, 0x83243980) { ctx.r3.u64 = n_sub_83243980(ctx, base); }

uint64_t n_sub_832439C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975D0_G_ = int32_t(0x834975D0);
	if (!UseLiftedCode(143, 0x832439C0)) { __imp__sub_832439C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832439C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D0_G_, (int64_t)g_820A0000 + 32372, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832439C0, 0x832439C0) { ctx.r3.u64 = n_sub_832439C0(ctx, base); }

uint64_t n_sub_83243A00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975D4_G_ = int32_t(0x834975D4);
	if (!UseLiftedCode(143, 0x83243A00)) { __imp__sub_83243A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D4_G_, (int64_t)g_820A0000 + 32344, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243A00, 0x83243A00) { ctx.r3.u64 = n_sub_83243A00(ctx, base); }

uint64_t n_sub_83243A40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975D8_G_ = int32_t(0x834975D8);
	if (!UseLiftedCode(143, 0x83243A40)) { __imp__sub_83243A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D8_G_, (int64_t)g_820A0000 + 32396, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243A40, 0x83243A40) { ctx.r3.u64 = n_sub_83243A40(ctx, base); }

uint64_t n_sub_83243A80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834975DC_G_ = int32_t(0x834975DC);
	if (!UseLiftedCode(143, 0x83243A80)) { __imp__sub_83243A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834975DC_G_, (int64_t)g_820A0000 + 32420, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83243A80, 0x83243A80) { ctx.r3.u64 = n_sub_83243A80(ctx, base); }

uint64_t n_sub_83244198(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497610_G_ = int32_t(0x83497610);
	if (!UseLiftedCode(143, 0x83244198)) { __imp__sub_83244198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244198);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497610_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244198, 0x83244198) { ctx.r3.u64 = n_sub_83244198(ctx, base); }

uint64_t n_sub_832441D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497614_G_ = int32_t(0x83497614);
	if (!UseLiftedCode(143, 0x832441D8)) { __imp__sub_832441D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832441D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497614_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832441D8, 0x832441D8) { ctx.r3.u64 = n_sub_832441D8(ctx, base); }

uint64_t n_sub_83244218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497618_G_ = int32_t(0x83497618);
	if (!UseLiftedCode(143, 0x83244218)) { __imp__sub_83244218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244218);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497618_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244218, 0x83244218) { ctx.r3.u64 = n_sub_83244218(ctx, base); }

uint64_t n_sub_83244258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349761C_G_ = int32_t(0x8349761C);
	if (!UseLiftedCode(143, 0x83244258)) { __imp__sub_83244258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349761C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244258, 0x83244258) { ctx.r3.u64 = n_sub_83244258(ctx, base); }

uint64_t n_sub_83244298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497620_G_ = int32_t(0x83497620);
	if (!UseLiftedCode(143, 0x83244298)) { __imp__sub_83244298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497620_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244298, 0x83244298) { ctx.r3.u64 = n_sub_83244298(ctx, base); }

uint64_t n_sub_832442D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497624_G_ = int32_t(0x83497624);
	if (!UseLiftedCode(143, 0x832442D8)) { __imp__sub_832442D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832442D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497624_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832442D8, 0x832442D8) { ctx.r3.u64 = n_sub_832442D8(ctx, base); }

uint64_t n_sub_83244448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497648_G_ = int32_t(0x83497648);
	if (!UseLiftedCode(143, 0x83244448)) { __imp__sub_83244448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497648_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244448, 0x83244448) { ctx.r3.u64 = n_sub_83244448(ctx, base); }

uint64_t n_sub_83244488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349764C_G_ = int32_t(0x8349764C);
	if (!UseLiftedCode(143, 0x83244488)) { __imp__sub_83244488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349764C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 2984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244488, 0x83244488) { ctx.r3.u64 = n_sub_83244488(ctx, base); }

uint64_t n_sub_832444C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497650_G_ = int32_t(0x83497650);
	if (!UseLiftedCode(143, 0x832444C8)) { __imp__sub_832444C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832444C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497650_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832444C8, 0x832444C8) { ctx.r3.u64 = n_sub_832444C8(ctx, base); }

uint64_t n_sub_83244508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497654_G_ = int32_t(0x83497654);
	if (!UseLiftedCode(143, 0x83244508)) { __imp__sub_83244508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497654_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244508, 0x83244508) { ctx.r3.u64 = n_sub_83244508(ctx, base); }

uint64_t n_sub_83244548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497658_G_ = int32_t(0x83497658);
	if (!UseLiftedCode(143, 0x83244548)) { __imp__sub_83244548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497658_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244548, 0x83244548) { ctx.r3.u64 = n_sub_83244548(ctx, base); }

uint64_t n_sub_83244588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349765C_G_ = int32_t(0x8349765C);
	if (!UseLiftedCode(143, 0x83244588)) { __imp__sub_83244588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349765C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244588, 0x83244588) { ctx.r3.u64 = n_sub_83244588(ctx, base); }

uint64_t n_sub_83244628(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83244628)) { ctx.r8.u64 = arg1; __imp__sub_83244628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244628);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3256, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83244628, 0x83244628) { ctx.r3.u64 = n_sub_83244628(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244638(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_83497680 = int32_t(0x83497680);
	if (!UseLiftedCode(143, 0x83244638)) { __imp__sub_83244638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244638);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_83497680, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244638, 0x83244638) { ctx.r3.u64 = n_sub_83244638(ctx, base); }

uint64_t n_sub_83244678(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t g_83497684 = int32_t(0x83497684);
	if (!UseLiftedCode(143, 0x83244678)) { __imp__sub_83244678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244678);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, g_83497684, (int64_t)g_82000000 + 3224, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244678, 0x83244678) { ctx.r3.u64 = n_sub_83244678(ctx, base); }

// sub_83244748  [64 bytes]
uint64_t n_sub_83244748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497694_G_ = int32_t(0x83497694);
	if (!UseLiftedCode(143, 0x83244748)) { __imp__sub_83244748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244748);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497694_G_, (int64_t)str_TXT_820B0000_B_ - 31528, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244748, 0x83244748) { ctx.r3.u64 = n_sub_83244748(ctx, base); }

uint64_t n_sub_83244788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497698_G_ = int32_t(0x83497698);
	if (!UseLiftedCode(143, 0x83244788)) { __imp__sub_83244788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497698_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244788, 0x83244788) { ctx.r3.u64 = n_sub_83244788(ctx, base); }

uint64_t n_sub_832447C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349769C_G_ = int32_t(0x8349769C);
	if (!UseLiftedCode(143, 0x832447C8)) { __imp__sub_832447C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832447C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349769C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832447C8, 0x832447C8) { ctx.r3.u64 = n_sub_832447C8(ctx, base); }

uint64_t n_sub_83244808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976A0_G_ = int32_t(0x834976A0);
	if (!UseLiftedCode(143, 0x83244808)) { __imp__sub_83244808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244808, 0x83244808) { ctx.r3.u64 = n_sub_83244808(ctx, base); }

uint64_t n_sub_832448A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976A4_G_ = int32_t(0x834976A4);
	if (!UseLiftedCode(143, 0x832448A8)) { __imp__sub_832448A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832448A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A4_G_, (int64_t)str_TXT_820B0000_B_ - 30828, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832448A8, 0x832448A8) { ctx.r3.u64 = n_sub_832448A8(ctx, base); }

uint64_t n_sub_832448E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976A8_G_ = int32_t(0x834976A8);
	if (!UseLiftedCode(143, 0x832448E8)) { __imp__sub_832448E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832448E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A8_G_, (int64_t)str_TXT_820B0000_B_ - 30804, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832448E8, 0x832448E8) { ctx.r3.u64 = n_sub_832448E8(ctx, base); }

uint64_t n_sub_83244928(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83244928)) { ctx.r8.u64 = arg1; __imp__sub_83244928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244928);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3488, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83244928, 0x83244928) { ctx.r3.u64 = n_sub_83244928(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244938(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83244938)) { ctx.r8.u64 = arg1; __imp__sub_83244938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244938);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3504, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83244938, 0x83244938) { ctx.r3.u64 = n_sub_83244938(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976E8_G_ = int32_t(0x834976E8);
	if (!UseLiftedCode(143, 0x83244948)) { __imp__sub_83244948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976E8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244948, 0x83244948) { ctx.r3.u64 = n_sub_83244948(ctx, base); }

uint64_t n_sub_83244988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976EC_G_ = int32_t(0x834976EC);
	if (!UseLiftedCode(143, 0x83244988)) { __imp__sub_83244988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976EC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3536, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244988, 0x83244988) { ctx.r3.u64 = n_sub_83244988(ctx, base); }

uint64_t n_sub_832449C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834976F0_G_ = int32_t(0x834976F0);
	if (!UseLiftedCode(143, 0x832449C8)) { __imp__sub_832449C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832449C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834976F0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832449C8, 0x832449C8) { ctx.r3.u64 = n_sub_832449C8(ctx, base); }

uint64_t n_sub_83244A40(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83244A40)) { ctx.r8.u64 = arg1; __imp__sub_83244A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A40);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3568, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83244A40, 0x83244A40) { ctx.r3.u64 = n_sub_83244A40(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244A50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497708_G_ = int32_t(0x83497708);
	if (!UseLiftedCode(143, 0x83244A50)) { __imp__sub_83244A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497708_G_, (int64_t)str_TXT_820B0000_B_ - 28788, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244A50, 0x83244A50) { ctx.r3.u64 = n_sub_83244A50(ctx, base); }

uint64_t n_sub_83244A90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349770C_G_ = int32_t(0x8349770C);
	if (!UseLiftedCode(143, 0x83244A90)) { __imp__sub_83244A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349770C_G_, (int64_t)str_TXT_820B0000_B_ - 28780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244A90, 0x83244A90) { ctx.r3.u64 = n_sub_83244A90(ctx, base); }

uint64_t n_sub_83244AD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497710_G_ = int32_t(0x83497710);
	if (!UseLiftedCode(143, 0x83244AD0)) { __imp__sub_83244AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244AD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497710_G_, (int64_t)str_TXT_820B0000_B_ - 28772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244AD0, 0x83244AD0) { ctx.r3.u64 = n_sub_83244AD0(ctx, base); }

uint64_t n_sub_83244B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497714_G_ = int32_t(0x83497714);
	if (!UseLiftedCode(143, 0x83244B10)) { __imp__sub_83244B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497714_G_, (int64_t)str_TXT_820B0000_B_ - 28760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244B10, 0x83244B10) { ctx.r3.u64 = n_sub_83244B10(ctx, base); }

uint64_t n_sub_83244B50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497718_G_ = int32_t(0x83497718);
	if (!UseLiftedCode(143, 0x83244B50)) { __imp__sub_83244B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497718_G_, (int64_t)str_TXT_820B0000_B_ - 28752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244B50, 0x83244B50) { ctx.r3.u64 = n_sub_83244B50(ctx, base); }

uint64_t n_sub_83244B90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349771C_G_ = int32_t(0x8349771C);
	if (!UseLiftedCode(143, 0x83244B90)) { __imp__sub_83244B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349771C_G_, (int64_t)str_TXT_820B0000_B_ - 28740, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244B90, 0x83244B90) { ctx.r3.u64 = n_sub_83244B90(ctx, base); }

uint64_t n_sub_83244BD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497720_G_ = int32_t(0x83497720);
	if (!UseLiftedCode(143, 0x83244BD0)) { __imp__sub_83244BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244BD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497720_G_, (int64_t)str_TXT_820B0000_B_ - 28724, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244BD0, 0x83244BD0) { ctx.r3.u64 = n_sub_83244BD0(ctx, base); }

uint64_t n_sub_83244C10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497724_G_ = int32_t(0x83497724);
	if (!UseLiftedCode(143, 0x83244C10)) { __imp__sub_83244C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497724_G_, (int64_t)str_TXT_820B0000_B_ - 28716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244C10, 0x83244C10) { ctx.r3.u64 = n_sub_83244C10(ctx, base); }

uint64_t n_sub_83244C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497728_G_ = int32_t(0x83497728);
	if (!UseLiftedCode(143, 0x83244C50)) { __imp__sub_83244C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497728_G_, (int64_t)str_TXT_820B0000_B_ - 28700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244C50, 0x83244C50) { ctx.r3.u64 = n_sub_83244C50(ctx, base); }

uint64_t n_sub_83244C90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349772C_G_ = int32_t(0x8349772C);
	if (!UseLiftedCode(143, 0x83244C90)) { __imp__sub_83244C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349772C_G_, (int64_t)str_TXT_820B0000_B_ - 28692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244C90, 0x83244C90) { ctx.r3.u64 = n_sub_83244C90(ctx, base); }

uint64_t n_sub_83244CD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497730_G_ = int32_t(0x83497730);
	if (!UseLiftedCode(143, 0x83244CD0)) { __imp__sub_83244CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244CD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497730_G_, (int64_t)str_TXT_820B0000_B_ - 28684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244CD0, 0x83244CD0) { ctx.r3.u64 = n_sub_83244CD0(ctx, base); }

uint64_t n_sub_83244D10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497734_G_ = int32_t(0x83497734);
	if (!UseLiftedCode(143, 0x83244D10)) { __imp__sub_83244D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497734_G_, (int64_t)str_TXT_820B0000_B_ - 28672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244D10, 0x83244D10) { ctx.r3.u64 = n_sub_83244D10(ctx, base); }

uint64_t n_sub_83244D50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497738_G_ = int32_t(0x83497738);
	if (!UseLiftedCode(143, 0x83244D50)) { __imp__sub_83244D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497738_G_, (int64_t)str_TXT_820B0000_B_ - 28664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244D50, 0x83244D50) { ctx.r3.u64 = n_sub_83244D50(ctx, base); }

uint64_t n_sub_83244D90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349773C_G_ = int32_t(0x8349773C);
	if (!UseLiftedCode(143, 0x83244D90)) { __imp__sub_83244D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349773C_G_, (int64_t)str_TXT_820B0000_B_ - 28656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244D90, 0x83244D90) { ctx.r3.u64 = n_sub_83244D90(ctx, base); }

uint64_t n_sub_83244DD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497740_G_ = int32_t(0x83497740);
	if (!UseLiftedCode(143, 0x83244DD0)) { __imp__sub_83244DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244DD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497740_G_, (int64_t)str_TXT_820B0000_B_ - 28648, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244DD0, 0x83244DD0) { ctx.r3.u64 = n_sub_83244DD0(ctx, base); }

uint64_t n_sub_83244E10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497744_G_ = int32_t(0x83497744);
	if (!UseLiftedCode(143, 0x83244E10)) { __imp__sub_83244E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497744_G_, (int64_t)str_TXT_820B0000_B_ - 28640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244E10, 0x83244E10) { ctx.r3.u64 = n_sub_83244E10(ctx, base); }

uint64_t n_sub_83244E50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497748_G_ = int32_t(0x83497748);
	if (!UseLiftedCode(143, 0x83244E50)) { __imp__sub_83244E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497748_G_, (int64_t)str_TXT_820B0000_B_ - 28632, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244E50, 0x83244E50) { ctx.r3.u64 = n_sub_83244E50(ctx, base); }

uint64_t n_sub_83244E90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349774C_G_ = int32_t(0x8349774C);
	if (!UseLiftedCode(143, 0x83244E90)) { __imp__sub_83244E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349774C_G_, (int64_t)str_TXT_820B0000_B_ - 28624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244E90, 0x83244E90) { ctx.r3.u64 = n_sub_83244E90(ctx, base); }

uint64_t n_sub_83244ED0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497750_G_ = int32_t(0x83497750);
	if (!UseLiftedCode(143, 0x83244ED0)) { __imp__sub_83244ED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244ED0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497750_G_, (int64_t)str_TXT_820B0000_B_ - 28616, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244ED0, 0x83244ED0) { ctx.r3.u64 = n_sub_83244ED0(ctx, base); }

uint64_t n_sub_83244F10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497754_G_ = int32_t(0x83497754);
	if (!UseLiftedCode(143, 0x83244F10)) { __imp__sub_83244F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497754_G_, (int64_t)str_TXT_820B0000_B_ - 28604, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244F10, 0x83244F10) { ctx.r3.u64 = n_sub_83244F10(ctx, base); }

uint64_t n_sub_83244F50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497758_G_ = int32_t(0x83497758);
	if (!UseLiftedCode(143, 0x83244F50)) { __imp__sub_83244F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497758_G_, (int64_t)g_820A0000 + 22936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244F50, 0x83244F50) { ctx.r3.u64 = n_sub_83244F50(ctx, base); }

uint64_t n_sub_83244F90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349775C_G_ = int32_t(0x8349775C);
	if (!UseLiftedCode(143, 0x83244F90)) { __imp__sub_83244F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349775C_G_, (int64_t)str_TXT_820B0000_B_ - 28596, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244F90, 0x83244F90) { ctx.r3.u64 = n_sub_83244F90(ctx, base); }

uint64_t n_sub_83245488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349777C_G_ = int32_t(0x8349777C);
	if (!UseLiftedCode(143, 0x83245488)) { __imp__sub_83245488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349777C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 3984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245488, 0x83245488) { ctx.r3.u64 = n_sub_83245488(ctx, base); }

uint64_t n_sub_832454C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497780_G_ = int32_t(0x83497780);
	if (!UseLiftedCode(143, 0x832454C8)) { __imp__sub_832454C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832454C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497780_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832454C8, 0x832454C8) { ctx.r3.u64 = n_sub_832454C8(ctx, base); }

uint64_t n_sub_83245508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497784_G_ = int32_t(0x83497784);
	if (!UseLiftedCode(143, 0x83245508)) { __imp__sub_83245508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497784_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245508, 0x83245508) { ctx.r3.u64 = n_sub_83245508(ctx, base); }

uint64_t n_sub_83245548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497788_G_ = int32_t(0x83497788);
	if (!UseLiftedCode(143, 0x83245548)) { __imp__sub_83245548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497788_G_, (int64_t)str_TXT_820B0000_B_ - 27480, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245548, 0x83245548) { ctx.r3.u64 = n_sub_83245548(ctx, base); }

uint64_t n_sub_832455E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x832455E8)) { ctx.r8.u64 = arg1; __imp__sub_832455E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832455E8);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4120, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_832455E8, 0x832455E8) { ctx.r3.u64 = n_sub_832455E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83245658(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x83245658)) { ctx.r8.u64 = arg1; __imp__sub_83245658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245658);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4240, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_83245658, 0x83245658) { ctx.r3.u64 = n_sub_83245658(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832456C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977E0_G_ = int32_t(0x834977E0);
	if (!UseLiftedCode(143, 0x832456C8)) { __imp__sub_832456C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832456C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977E0_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832456C8, 0x832456C8) { ctx.r3.u64 = n_sub_832456C8(ctx, base); }

uint64_t n_sub_83245708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977E8_G_ = int32_t(0x834977E8);
	if (!UseLiftedCode(143, 0x83245708)) { __imp__sub_83245708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977E8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245708, 0x83245708) { ctx.r3.u64 = n_sub_83245708(ctx, base); }

uint64_t n_sub_83245748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977EC_G_ = int32_t(0x834977EC);
	if (!UseLiftedCode(143, 0x83245748)) { __imp__sub_83245748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977EC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245748, 0x83245748) { ctx.r3.u64 = n_sub_83245748(ctx, base); }

uint64_t n_sub_83245788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977F0_G_ = int32_t(0x834977F0);
	if (!UseLiftedCode(143, 0x83245788)) { __imp__sub_83245788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245788, 0x83245788) { ctx.r3.u64 = n_sub_83245788(ctx, base); }

uint64_t n_sub_832457C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977F4_G_ = int32_t(0x834977F4);
	if (!UseLiftedCode(143, 0x832457C8)) { __imp__sub_832457C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832457C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832457C8, 0x832457C8) { ctx.r3.u64 = n_sub_832457C8(ctx, base); }

uint64_t n_sub_83245808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834977F8_G_ = int32_t(0x834977F8);
	if (!UseLiftedCode(143, 0x83245808)) { __imp__sub_83245808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245808, 0x83245808) { ctx.r3.u64 = n_sub_83245808(ctx, base); }

uint64_t n_sub_83245928(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349780C_G_ = int32_t(0x8349780C);
	if (!UseLiftedCode(143, 0x83245928)) { __imp__sub_83245928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245928);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349780C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245928, 0x83245928) { ctx.r3.u64 = n_sub_83245928(ctx, base); }

uint64_t n_sub_83245968(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497810_G_ = int32_t(0x83497810);
	if (!UseLiftedCode(143, 0x83245968)) { __imp__sub_83245968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245968);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497810_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245968, 0x83245968) { ctx.r3.u64 = n_sub_83245968(ctx, base); }

uint64_t n_sub_832459A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497814_G_ = int32_t(0x83497814);
	if (!UseLiftedCode(143, 0x832459A8)) { __imp__sub_832459A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832459A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497814_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832459A8, 0x832459A8) { ctx.r3.u64 = n_sub_832459A8(ctx, base); }

uint64_t n_sub_832459E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497818_G_ = int32_t(0x83497818);
	if (!UseLiftedCode(143, 0x832459E8)) { __imp__sub_832459E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832459E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497818_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832459E8, 0x832459E8) { ctx.r3.u64 = n_sub_832459E8(ctx, base); }

uint64_t n_sub_83245A28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349781C_G_ = int32_t(0x8349781C);
	if (!UseLiftedCode(143, 0x83245A28)) { __imp__sub_83245A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245A28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349781C_G_, (int64_t)g_820A0000 + 22984, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245A28, 0x83245A28) { ctx.r3.u64 = n_sub_83245A28(ctx, base); }

uint64_t n_sub_83245A68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497820_G_ = int32_t(0x83497820);
	if (!UseLiftedCode(143, 0x83245A68)) { __imp__sub_83245A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245A68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497820_G_, (int64_t)g_820A0000 + 23008, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245A68, 0x83245A68) { ctx.r3.u64 = n_sub_83245A68(ctx, base); }

uint64_t n_sub_83245AA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497824_G_ = int32_t(0x83497824);
	if (!UseLiftedCode(143, 0x83245AA8)) { __imp__sub_83245AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245AA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497824_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245AA8, 0x83245AA8) { ctx.r3.u64 = n_sub_83245AA8(ctx, base); }

uint64_t n_sub_83245AE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497828_G_ = int32_t(0x83497828);
	if (!UseLiftedCode(143, 0x83245AE8)) { __imp__sub_83245AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245AE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497828_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245AE8, 0x83245AE8) { ctx.r3.u64 = n_sub_83245AE8(ctx, base); }

uint64_t n_sub_83245B28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349782C_G_ = int32_t(0x8349782C);
	if (!UseLiftedCode(143, 0x83245B28)) { __imp__sub_83245B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245B28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349782C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245B28, 0x83245B28) { ctx.r3.u64 = n_sub_83245B28(ctx, base); }

uint64_t n_sub_83245B68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497830_G_ = int32_t(0x83497830);
	if (!UseLiftedCode(143, 0x83245B68)) { __imp__sub_83245B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245B68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497830_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245B68, 0x83245B68) { ctx.r3.u64 = n_sub_83245B68(ctx, base); }

uint64_t n_sub_83245BA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497834_G_ = int32_t(0x83497834);
	if (!UseLiftedCode(143, 0x83245BA8)) { __imp__sub_83245BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245BA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497834_G_, (int64_t)str_TXT_820B0000_B_ - 15688, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245BA8, 0x83245BA8) { ctx.r3.u64 = n_sub_83245BA8(ctx, base); }

uint64_t n_sub_83245BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497838_G_ = int32_t(0x83497838);
	if (!UseLiftedCode(143, 0x83245BE8)) { __imp__sub_83245BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245BE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497838_G_, (int64_t)str_TXT_820B0000_B_ - 15664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245BE8, 0x83245BE8) { ctx.r3.u64 = n_sub_83245BE8(ctx, base); }

uint64_t n_sub_83245C28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349783C_G_ = int32_t(0x8349783C);
	if (!UseLiftedCode(143, 0x83245C28)) { __imp__sub_83245C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349783C_G_, (int64_t)str_TXT_820B0000_B_ - 15632, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245C28, 0x83245C28) { ctx.r3.u64 = n_sub_83245C28(ctx, base); }

uint64_t n_sub_83245CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349784C_G_ = int32_t(0x8349784C);
	if (!UseLiftedCode(143, 0x83245CF8)) { __imp__sub_83245CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349784C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245CF8, 0x83245CF8) { ctx.r3.u64 = n_sub_83245CF8(ctx, base); }

uint64_t n_sub_83245D38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497850_G_ = int32_t(0x83497850);
	if (!UseLiftedCode(143, 0x83245D38)) { __imp__sub_83245D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245D38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497850_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245D38, 0x83245D38) { ctx.r3.u64 = n_sub_83245D38(ctx, base); }

uint64_t n_sub_83245D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497854_G_ = int32_t(0x83497854);
	if (!UseLiftedCode(143, 0x83245D78)) { __imp__sub_83245D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497854_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245D78, 0x83245D78) { ctx.r3.u64 = n_sub_83245D78(ctx, base); }

uint64_t n_sub_83245DB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497858_G_ = int32_t(0x83497858);
	if (!UseLiftedCode(143, 0x83245DB8)) { __imp__sub_83245DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245DB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497858_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245DB8, 0x83245DB8) { ctx.r3.u64 = n_sub_83245DB8(ctx, base); }

uint64_t n_sub_83245DF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349785C_G_ = int32_t(0x8349785C);
	if (!UseLiftedCode(143, 0x83245DF8)) { __imp__sub_83245DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245DF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349785C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245DF8, 0x83245DF8) { ctx.r3.u64 = n_sub_83245DF8(ctx, base); }

uint64_t n_sub_83245E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497860_G_ = int32_t(0x83497860);
	if (!UseLiftedCode(143, 0x83245E38)) { __imp__sub_83245E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497860_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245E38, 0x83245E38) { ctx.r3.u64 = n_sub_83245E38(ctx, base); }

uint64_t n_sub_83245E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497864_G_ = int32_t(0x83497864);
	if (!UseLiftedCode(143, 0x83245E78)) { __imp__sub_83245E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497864_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245E78, 0x83245E78) { ctx.r3.u64 = n_sub_83245E78(ctx, base); }

uint64_t n_sub_83245EF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349786C_G_ = int32_t(0x8349786C);
	if (!UseLiftedCode(143, 0x83245EF0)) { __imp__sub_83245EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245EF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349786C_G_, (int64_t)str_TXT_820B0000_B_ - 6984, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245EF0, 0x83245EF0) { ctx.r3.u64 = n_sub_83245EF0(ctx, base); }

uint64_t n_sub_83245FC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349787C_G_ = int32_t(0x8349787C);
	if (!UseLiftedCode(143, 0x83245FC0)) { __imp__sub_83245FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245FC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349787C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83245FC0, 0x83245FC0) { ctx.r3.u64 = n_sub_83245FC0(ctx, base); }

uint64_t n_sub_83246000(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497880_G_ = int32_t(0x83497880);
	if (!UseLiftedCode(143, 0x83246000)) { __imp__sub_83246000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246000);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497880_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246000, 0x83246000) { ctx.r3.u64 = n_sub_83246000(ctx, base); }

uint64_t n_sub_83246040(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497884_G_ = int32_t(0x83497884);
	if (!UseLiftedCode(143, 0x83246040)) { __imp__sub_83246040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497884_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246040, 0x83246040) { ctx.r3.u64 = n_sub_83246040(ctx, base); }

uint64_t n_sub_83246348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834978E0_G_ = int32_t(0x834978E0);
	if (!UseLiftedCode(143, 0x83246348)) { __imp__sub_83246348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246348);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E0_G_, (int64_t)str_TXT_820B0000_B_ - 5952, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246348, 0x83246348) { ctx.r3.u64 = n_sub_83246348(ctx, base); }

uint64_t n_sub_83246388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834978E4_G_ = int32_t(0x834978E4);
	if (!UseLiftedCode(143, 0x83246388)) { __imp__sub_83246388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E4_G_, (int64_t)str_TXT_820B0000_B_ - 5936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246388, 0x83246388) { ctx.r3.u64 = n_sub_83246388(ctx, base); }

uint64_t n_sub_832463C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834978E8_G_ = int32_t(0x834978E8);
	if (!UseLiftedCode(143, 0x832463C8)) { __imp__sub_832463C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832463C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E8_G_, (int64_t)str_TXT_820B0000_B_ - 5920, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832463C8, 0x832463C8) { ctx.r3.u64 = n_sub_832463C8(ctx, base); }

uint64_t n_sub_83246690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834978EC_G_ = int32_t(0x834978EC);
	if (!UseLiftedCode(143, 0x83246690)) { __imp__sub_83246690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834978EC_G_, (int64_t)str_TXT_820B0000_B_ - 5908, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246690, 0x83246690) { ctx.r3.u64 = n_sub_83246690(ctx, base); }

uint64_t n_sub_83246790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497970_G_ = int32_t(0x83497970);
	if (!UseLiftedCode(143, 0x83246790)) { __imp__sub_83246790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497970_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246790, 0x83246790) { ctx.r3.u64 = n_sub_83246790(ctx, base); }

uint64_t n_sub_83246920(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497980_G_ = int32_t(0x83497980);
	if (!UseLiftedCode(143, 0x83246920)) { __imp__sub_83246920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246920);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497980_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246920, 0x83246920) { ctx.r3.u64 = n_sub_83246920(ctx, base); }

uint64_t n_sub_83246960(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497984_G_ = int32_t(0x83497984);
	if (!UseLiftedCode(143, 0x83246960)) { __imp__sub_83246960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246960);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497984_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246960, 0x83246960) { ctx.r3.u64 = n_sub_83246960(ctx, base); }

uint64_t n_sub_832469A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497988_G_ = int32_t(0x83497988);
	if (!UseLiftedCode(143, 0x832469A0)) { __imp__sub_832469A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832469A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497988_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832469A0, 0x832469A0) { ctx.r3.u64 = n_sub_832469A0(ctx, base); }

uint64_t n_sub_83246E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979E0_G_ = int32_t(0x834979E0);
	if (!UseLiftedCode(143, 0x83246E78)) { __imp__sub_83246E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246E78, 0x83246E78) { ctx.r3.u64 = n_sub_83246E78(ctx, base); }

uint64_t n_sub_83246EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979E4_G_ = int32_t(0x834979E4);
	if (!UseLiftedCode(143, 0x83246EB8)) { __imp__sub_83246EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 4984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246EB8, 0x83246EB8) { ctx.r3.u64 = n_sub_83246EB8(ctx, base); }

uint64_t n_sub_83246EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979E8_G_ = int32_t(0x834979E8);
	if (!UseLiftedCode(143, 0x83246EF8)) { __imp__sub_83246EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246EF8, 0x83246EF8) { ctx.r3.u64 = n_sub_83246EF8(ctx, base); }

uint64_t n_sub_83246F38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979EC_G_ = int32_t(0x834979EC);
	if (!UseLiftedCode(143, 0x83246F38)) { __imp__sub_83246F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246F38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979EC_G_, (int64_t)str_TXT_820B0000_B_ - 5260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246F38, 0x83246F38) { ctx.r3.u64 = n_sub_83246F38(ctx, base); }

uint64_t n_sub_83246F78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979F0_G_ = int32_t(0x834979F0);
	if (!UseLiftedCode(143, 0x83246F78)) { __imp__sub_83246F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246F78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F0_G_, (int64_t)str_TXT_820B0000_B_ - 5228, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246F78, 0x83246F78) { ctx.r3.u64 = n_sub_83246F78(ctx, base); }

uint64_t n_sub_83246FB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979F4_G_ = int32_t(0x834979F4);
	if (!UseLiftedCode(143, 0x83246FB8)) { __imp__sub_83246FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246FB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F4_G_, (int64_t)str_TXT_820B0000_B_ - 5192, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246FB8, 0x83246FB8) { ctx.r3.u64 = n_sub_83246FB8(ctx, base); }

uint64_t n_sub_83246FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979F8_G_ = int32_t(0x834979F8);
	if (!UseLiftedCode(143, 0x83246FF8)) { __imp__sub_83246FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246FF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F8_G_, (int64_t)str_TXT_820B0000_B_ - 5176, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83246FF8, 0x83246FF8) { ctx.r3.u64 = n_sub_83246FF8(ctx, base); }

uint64_t n_sub_83247038(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834979FC_G_ = int32_t(0x834979FC);
	if (!UseLiftedCode(143, 0x83247038)) { __imp__sub_83247038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247038);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834979FC_G_, (int64_t)str_TXT_820B0000_B_ - 5144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247038, 0x83247038) { ctx.r3.u64 = n_sub_83247038(ctx, base); }

uint64_t n_sub_83247078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A00_G_ = int32_t(0x83497A00);
	if (!UseLiftedCode(143, 0x83247078)) { __imp__sub_83247078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A00_G_, (int64_t)str_TXT_820B0000_B_ - 5124, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247078, 0x83247078) { ctx.r3.u64 = n_sub_83247078(ctx, base); }

uint64_t n_sub_832470B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A04_G_ = int32_t(0x83497A04);
	if (!UseLiftedCode(143, 0x832470B8)) { __imp__sub_832470B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832470B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A04_G_, (int64_t)str_TXT_820B0000_B_ - 5104, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832470B8, 0x832470B8) { ctx.r3.u64 = n_sub_832470B8(ctx, base); }

uint64_t n_sub_832470F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A08_G_ = int32_t(0x83497A08);
	if (!UseLiftedCode(143, 0x832470F8)) { __imp__sub_832470F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832470F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A08_G_, (int64_t)str_TXT_820B0000_B_ - 5076, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832470F8, 0x832470F8) { ctx.r3.u64 = n_sub_832470F8(ctx, base); }

uint64_t n_sub_83247138(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A0C_G_ = int32_t(0x83497A0C);
	if (!UseLiftedCode(143, 0x83247138)) { __imp__sub_83247138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247138);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A0C_G_, (int64_t)str_TXT_820B0000_B_ - 5056, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247138, 0x83247138) { ctx.r3.u64 = n_sub_83247138(ctx, base); }

uint64_t n_sub_83247178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A10_G_ = int32_t(0x83497A10);
	if (!UseLiftedCode(143, 0x83247178)) { __imp__sub_83247178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A10_G_, (int64_t)str_TXT_820B0000_B_ - 5036, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247178, 0x83247178) { ctx.r3.u64 = n_sub_83247178(ctx, base); }

uint64_t n_sub_832471B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A14_G_ = int32_t(0x83497A14);
	if (!UseLiftedCode(143, 0x832471B8)) { __imp__sub_832471B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832471B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A14_G_, (int64_t)str_TXT_820B0000_B_ - 5020, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832471B8, 0x832471B8) { ctx.r3.u64 = n_sub_832471B8(ctx, base); }

uint64_t n_sub_832471F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A18_G_ = int32_t(0x83497A18);
	if (!UseLiftedCode(143, 0x832471F8)) { __imp__sub_832471F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832471F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A18_G_, (int64_t)str_TXT_820B0000_B_ - 5000, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832471F8, 0x832471F8) { ctx.r3.u64 = n_sub_832471F8(ctx, base); }

uint64_t n_sub_83247238(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A1C_G_ = int32_t(0x83497A1C);
	if (!UseLiftedCode(143, 0x83247238)) { __imp__sub_83247238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247238);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A1C_G_, (int64_t)str_TXT_820B0000_B_ - 4976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247238, 0x83247238) { ctx.r3.u64 = n_sub_83247238(ctx, base); }

uint64_t n_sub_83247278(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A20_G_ = int32_t(0x83497A20);
	if (!UseLiftedCode(143, 0x83247278)) { __imp__sub_83247278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A20_G_, (int64_t)str_TXT_820B0000_B_ - 4956, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247278, 0x83247278) { ctx.r3.u64 = n_sub_83247278(ctx, base); }

uint64_t n_sub_832472B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A24_G_ = int32_t(0x83497A24);
	if (!UseLiftedCode(143, 0x832472B8)) { __imp__sub_832472B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832472B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A24_G_, (int64_t)str_TXT_820B0000_B_ - 4936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832472B8, 0x832472B8) { ctx.r3.u64 = n_sub_832472B8(ctx, base); }

uint64_t n_sub_832472F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A28_G_ = int32_t(0x83497A28);
	if (!UseLiftedCode(143, 0x832472F8)) { __imp__sub_832472F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832472F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A28_G_, (int64_t)str_TXT_820B0000_B_ - 4912, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832472F8, 0x832472F8) { ctx.r3.u64 = n_sub_832472F8(ctx, base); }

uint64_t n_sub_83247338(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A2C_G_ = int32_t(0x83497A2C);
	if (!UseLiftedCode(143, 0x83247338)) { __imp__sub_83247338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247338);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A2C_G_, (int64_t)str_TXT_820B0000_B_ - 4892, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247338, 0x83247338) { ctx.r3.u64 = n_sub_83247338(ctx, base); }

uint64_t n_sub_832473B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A34_G_ = int32_t(0x83497A34);
	if (!UseLiftedCode(143, 0x832473B0)) { __imp__sub_832473B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832473B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A34_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832473B0, 0x832473B0) { ctx.r3.u64 = n_sub_832473B0(ctx, base); }

uint64_t n_sub_832473F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A38_G_ = int32_t(0x83497A38);
	if (!UseLiftedCode(143, 0x832473F0)) { __imp__sub_832473F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832473F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A38_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832473F0, 0x832473F0) { ctx.r3.u64 = n_sub_832473F0(ctx, base); }

uint64_t n_sub_83247430(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A3C_G_ = int32_t(0x83497A3C);
	if (!UseLiftedCode(143, 0x83247430)) { __imp__sub_83247430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247430);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A3C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247430, 0x83247430) { ctx.r3.u64 = n_sub_83247430(ctx, base); }

uint64_t n_sub_83247630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A60_G_ = int32_t(0x83497A60);
	if (!UseLiftedCode(143, 0x83247630)) { __imp__sub_83247630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A60_G_, (int64_t)str_TXT_820B0000_B_ - 4284, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247630, 0x83247630) { ctx.r3.u64 = n_sub_83247630(ctx, base); }

uint64_t n_sub_83247670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A64_G_ = int32_t(0x83497A64);
	if (!UseLiftedCode(143, 0x83247670)) { __imp__sub_83247670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A64_G_, (int64_t)str_TXT_820B0000_B_ - 4264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247670, 0x83247670) { ctx.r3.u64 = n_sub_83247670(ctx, base); }

uint64_t n_sub_832476B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A68_G_ = int32_t(0x83497A68);
	if (!UseLiftedCode(143, 0x832476B0)) { __imp__sub_832476B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832476B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A68_G_, (int64_t)g_820A0000 + 19800, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832476B0, 0x832476B0) { ctx.r3.u64 = n_sub_832476B0(ctx, base); }

uint64_t n_sub_832476F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A6C_G_ = int32_t(0x83497A6C);
	if (!UseLiftedCode(143, 0x832476F0)) { __imp__sub_832476F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832476F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A6C_G_, (int64_t)str_TXT_820B0000_B_ - 4244, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832476F0, 0x832476F0) { ctx.r3.u64 = n_sub_832476F0(ctx, base); }

uint64_t n_sub_83247730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A70_G_ = int32_t(0x83497A70);
	if (!UseLiftedCode(143, 0x83247730)) { __imp__sub_83247730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A70_G_, (int64_t)str_TXT_820B0000_B_ - 4220, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247730, 0x83247730) { ctx.r3.u64 = n_sub_83247730(ctx, base); }

uint64_t n_sub_83247770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A74_G_ = int32_t(0x83497A74);
	if (!UseLiftedCode(143, 0x83247770)) { __imp__sub_83247770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A74_G_, (int64_t)str_TXT_820B0000_B_ - 4200, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247770, 0x83247770) { ctx.r3.u64 = n_sub_83247770(ctx, base); }

uint64_t n_sub_832477B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A78_G_ = int32_t(0x83497A78);
	if (!UseLiftedCode(143, 0x832477B0)) { __imp__sub_832477B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832477B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A78_G_, (int64_t)str_TXT_820B0000_B_ - 4168, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832477B0, 0x832477B0) { ctx.r3.u64 = n_sub_832477B0(ctx, base); }

uint64_t n_sub_832477F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497A7C_G_ = int32_t(0x83497A7C);
	if (!UseLiftedCode(143, 0x832477F0)) { __imp__sub_832477F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832477F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A7C_G_, (int64_t)str_TXT_820B0000_B_ - 4136, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832477F0, 0x832477F0) { ctx.r3.u64 = n_sub_832477F0(ctx, base); }

uint64_t n_sub_83247908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AA0_G_ = int32_t(0x83497AA0);
	if (!UseLiftedCode(143, 0x83247908)) { __imp__sub_83247908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5568, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247908, 0x83247908) { ctx.r3.u64 = n_sub_83247908(ctx, base); }

uint64_t n_sub_83247948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AA4_G_ = int32_t(0x83497AA4);
	if (!UseLiftedCode(143, 0x83247948)) { __imp__sub_83247948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247948, 0x83247948) { ctx.r3.u64 = n_sub_83247948(ctx, base); }

uint64_t n_sub_83247988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AA8_G_ = int32_t(0x83497AA8);
	if (!UseLiftedCode(143, 0x83247988)) { __imp__sub_83247988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247988, 0x83247988) { ctx.r3.u64 = n_sub_83247988(ctx, base); }

uint64_t n_sub_832479C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AAC_G_ = int32_t(0x83497AAC);
	if (!UseLiftedCode(143, 0x832479C8)) { __imp__sub_832479C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832479C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AAC_G_, (int64_t)str_TXT_820B0000_B_ - 3940, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832479C8, 0x832479C8) { ctx.r3.u64 = n_sub_832479C8(ctx, base); }

uint64_t n_sub_83247A08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AB0_G_ = int32_t(0x83497AB0);
	if (!UseLiftedCode(143, 0x83247A08)) { __imp__sub_83247A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB0_G_, (int64_t)str_TXT_820B0000_B_ - 3908, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247A08, 0x83247A08) { ctx.r3.u64 = n_sub_83247A08(ctx, base); }

uint64_t n_sub_83247A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AB4_G_ = int32_t(0x83497AB4);
	if (!UseLiftedCode(143, 0x83247A48)) { __imp__sub_83247A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB4_G_, (int64_t)str_TXT_820B0000_B_ - 3872, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247A48, 0x83247A48) { ctx.r3.u64 = n_sub_83247A48(ctx, base); }

uint64_t n_sub_83247A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AB8_G_ = int32_t(0x83497AB8);
	if (!UseLiftedCode(143, 0x83247A88)) { __imp__sub_83247A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB8_G_, (int64_t)str_TXT_820B0000_B_ - 3836, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247A88, 0x83247A88) { ctx.r3.u64 = n_sub_83247A88(ctx, base); }

uint64_t n_sub_83247AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497ABC_G_ = int32_t(0x83497ABC);
	if (!UseLiftedCode(143, 0x83247AC8)) { __imp__sub_83247AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ABC_G_, (int64_t)str_TXT_820B0000_B_ - 3796, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247AC8, 0x83247AC8) { ctx.r3.u64 = n_sub_83247AC8(ctx, base); }

uint64_t n_sub_83247B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AC0_G_ = int32_t(0x83497AC0);
	if (!UseLiftedCode(143, 0x83247B08)) { __imp__sub_83247B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC0_G_, (int64_t)str_TXT_820B0000_B_ - 28788, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247B08, 0x83247B08) { ctx.r3.u64 = n_sub_83247B08(ctx, base); }

uint64_t n_sub_83247B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AC4_G_ = int32_t(0x83497AC4);
	if (!UseLiftedCode(143, 0x83247B48)) { __imp__sub_83247B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC4_G_, (int64_t)str_TXT_820B0000_B_ - 28780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247B48, 0x83247B48) { ctx.r3.u64 = n_sub_83247B48(ctx, base); }

uint64_t n_sub_83247B88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AC8_G_ = int32_t(0x83497AC8);
	if (!UseLiftedCode(143, 0x83247B88)) { __imp__sub_83247B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC8_G_, (int64_t)str_TXT_820B0000_B_ - 28772, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247B88, 0x83247B88) { ctx.r3.u64 = n_sub_83247B88(ctx, base); }

uint64_t n_sub_83247BC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497ACC_G_ = int32_t(0x83497ACC);
	if (!UseLiftedCode(143, 0x83247BC8)) { __imp__sub_83247BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247BC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ACC_G_, (int64_t)str_TXT_820B0000_B_ - 28760, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247BC8, 0x83247BC8) { ctx.r3.u64 = n_sub_83247BC8(ctx, base); }

uint64_t n_sub_83247C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AD0_G_ = int32_t(0x83497AD0);
	if (!UseLiftedCode(143, 0x83247C08)) { __imp__sub_83247C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD0_G_, (int64_t)str_TXT_820B0000_B_ - 28752, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247C08, 0x83247C08) { ctx.r3.u64 = n_sub_83247C08(ctx, base); }

uint64_t n_sub_83247C48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AD4_G_ = int32_t(0x83497AD4);
	if (!UseLiftedCode(143, 0x83247C48)) { __imp__sub_83247C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD4_G_, (int64_t)str_TXT_820B0000_B_ - 28740, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247C48, 0x83247C48) { ctx.r3.u64 = n_sub_83247C48(ctx, base); }

uint64_t n_sub_83247C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AD8_G_ = int32_t(0x83497AD8);
	if (!UseLiftedCode(143, 0x83247C88)) { __imp__sub_83247C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD8_G_, (int64_t)str_TXT_820B0000_B_ - 28724, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247C88, 0x83247C88) { ctx.r3.u64 = n_sub_83247C88(ctx, base); }

uint64_t n_sub_83247CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497ADC_G_ = int32_t(0x83497ADC);
	if (!UseLiftedCode(143, 0x83247CC8)) { __imp__sub_83247CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ADC_G_, (int64_t)str_TXT_820B0000_B_ - 28716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247CC8, 0x83247CC8) { ctx.r3.u64 = n_sub_83247CC8(ctx, base); }

uint64_t n_sub_83247D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AE0_G_ = int32_t(0x83497AE0);
	if (!UseLiftedCode(143, 0x83247D08)) { __imp__sub_83247D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE0_G_, (int64_t)str_TXT_820B0000_B_ - 28700, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247D08, 0x83247D08) { ctx.r3.u64 = n_sub_83247D08(ctx, base); }

uint64_t n_sub_83247D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AE4_G_ = int32_t(0x83497AE4);
	if (!UseLiftedCode(143, 0x83247D48)) { __imp__sub_83247D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE4_G_, (int64_t)str_TXT_820B0000_B_ - 28692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247D48, 0x83247D48) { ctx.r3.u64 = n_sub_83247D48(ctx, base); }

uint64_t n_sub_83247D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AE8_G_ = int32_t(0x83497AE8);
	if (!UseLiftedCode(143, 0x83247D88)) { __imp__sub_83247D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE8_G_, (int64_t)str_TXT_820B0000_B_ - 28684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247D88, 0x83247D88) { ctx.r3.u64 = n_sub_83247D88(ctx, base); }

uint64_t n_sub_83247DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AEC_G_ = int32_t(0x83497AEC);
	if (!UseLiftedCode(143, 0x83247DC8)) { __imp__sub_83247DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AEC_G_, (int64_t)str_TXT_820B0000_B_ - 28672, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247DC8, 0x83247DC8) { ctx.r3.u64 = n_sub_83247DC8(ctx, base); }

uint64_t n_sub_83247E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AF0_G_ = int32_t(0x83497AF0);
	if (!UseLiftedCode(143, 0x83247E08)) { __imp__sub_83247E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF0_G_, (int64_t)str_TXT_820B0000_B_ - 28664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247E08, 0x83247E08) { ctx.r3.u64 = n_sub_83247E08(ctx, base); }

uint64_t n_sub_83247E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AF4_G_ = int32_t(0x83497AF4);
	if (!UseLiftedCode(143, 0x83247E48)) { __imp__sub_83247E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF4_G_, (int64_t)str_TXT_820B0000_B_ - 28656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247E48, 0x83247E48) { ctx.r3.u64 = n_sub_83247E48(ctx, base); }

uint64_t n_sub_83247E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AF8_G_ = int32_t(0x83497AF8);
	if (!UseLiftedCode(143, 0x83247E88)) { __imp__sub_83247E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF8_G_, (int64_t)str_TXT_820B0000_B_ - 28648, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247E88, 0x83247E88) { ctx.r3.u64 = n_sub_83247E88(ctx, base); }

uint64_t n_sub_83247EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497AFC_G_ = int32_t(0x83497AFC);
	if (!UseLiftedCode(143, 0x83247EC8)) { __imp__sub_83247EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AFC_G_, (int64_t)str_TXT_820B0000_B_ - 28640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247EC8, 0x83247EC8) { ctx.r3.u64 = n_sub_83247EC8(ctx, base); }

uint64_t n_sub_83247F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B00_G_ = int32_t(0x83497B00);
	if (!UseLiftedCode(143, 0x83247F08)) { __imp__sub_83247F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B00_G_, (int64_t)str_TXT_820B0000_B_ - 28632, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247F08, 0x83247F08) { ctx.r3.u64 = n_sub_83247F08(ctx, base); }

uint64_t n_sub_83247F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B04_G_ = int32_t(0x83497B04);
	if (!UseLiftedCode(143, 0x83247F48)) { __imp__sub_83247F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B04_G_, (int64_t)str_TXT_820B0000_B_ - 28624, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247F48, 0x83247F48) { ctx.r3.u64 = n_sub_83247F48(ctx, base); }

uint64_t n_sub_83247F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B08_G_ = int32_t(0x83497B08);
	if (!UseLiftedCode(143, 0x83247F88)) { __imp__sub_83247F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B08_G_, (int64_t)str_TXT_820B0000_B_ - 28616, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 5984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247F88, 0x83247F88) { ctx.r3.u64 = n_sub_83247F88(ctx, base); }

uint64_t n_sub_83247FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B0C_G_ = int32_t(0x83497B0C);
	if (!UseLiftedCode(143, 0x83247FC8)) { __imp__sub_83247FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B0C_G_, (int64_t)str_TXT_820B0000_B_ - 28604, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83247FC8, 0x83247FC8) { ctx.r3.u64 = n_sub_83247FC8(ctx, base); }

uint64_t n_sub_83248008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B10_G_ = int32_t(0x83497B10);
	if (!UseLiftedCode(143, 0x83248008)) { __imp__sub_83248008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B10_G_, (int64_t)g_820A0000 + 22936, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248008, 0x83248008) { ctx.r3.u64 = n_sub_83248008(ctx, base); }

uint64_t n_sub_832484E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B68_G_ = int32_t(0x83497B68);
	if (!UseLiftedCode(143, 0x832484E0)) { __imp__sub_832484E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832484E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B68_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832484E0, 0x832484E0) { ctx.r3.u64 = n_sub_832484E0(ctx, base); }

uint64_t n_sub_83248520(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B6C_G_ = int32_t(0x83497B6C);
	if (!UseLiftedCode(143, 0x83248520)) { __imp__sub_83248520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248520);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B6C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248520, 0x83248520) { ctx.r3.u64 = n_sub_83248520(ctx, base); }

uint64_t n_sub_83248560(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B70_G_ = int32_t(0x83497B70);
	if (!UseLiftedCode(143, 0x83248560)) { __imp__sub_83248560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B70_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248560, 0x83248560) { ctx.r3.u64 = n_sub_83248560(ctx, base); }

uint64_t n_sub_832485A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B74_G_ = int32_t(0x83497B74);
	if (!UseLiftedCode(143, 0x832485A0)) { __imp__sub_832485A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832485A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B74_G_, (int64_t)str_TXT_820B0000_B_ - 3580, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832485A0, 0x832485A0) { ctx.r3.u64 = n_sub_832485A0(ctx, base); }

uint64_t n_sub_832485E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B78_G_ = int32_t(0x83497B78);
	if (!UseLiftedCode(143, 0x832485E0)) { __imp__sub_832485E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832485E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B78_G_, (int64_t)str_TXT_820B0000_B_ - 3548, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832485E0, 0x832485E0) { ctx.r3.u64 = n_sub_832485E0(ctx, base); }

uint64_t n_sub_83248620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497B7C_G_ = int32_t(0x83497B7C);
	if (!UseLiftedCode(143, 0x83248620)) { __imp__sub_83248620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248620);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B7C_G_, (int64_t)str_TXT_820B0000_B_ - 3532, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248620, 0x83248620) { ctx.r3.u64 = n_sub_83248620(ctx, base); }

uint64_t n_sub_83248AF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BD4_G_ = int32_t(0x83497BD4);
	if (!UseLiftedCode(143, 0x83248AF8)) { __imp__sub_83248AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248AF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BD4_G_, (int64_t)str_TXT_820B0000_B_ - 3000, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248AF8, 0x83248AF8) { ctx.r3.u64 = n_sub_83248AF8(ctx, base); }

uint64_t n_sub_83248B38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BD8_G_ = int32_t(0x83497BD8);
	if (!UseLiftedCode(143, 0x83248B38)) { __imp__sub_83248B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248B38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BD8_G_, (int64_t)str_TXT_820B0000_B_ - 2976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248B38, 0x83248B38) { ctx.r3.u64 = n_sub_83248B38(ctx, base); }

uint64_t n_sub_83248B78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BDC_G_ = int32_t(0x83497BDC);
	if (!UseLiftedCode(143, 0x83248B78)) { __imp__sub_83248B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248B78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BDC_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248B78, 0x83248B78) { ctx.r3.u64 = n_sub_83248B78(ctx, base); }

uint64_t n_sub_83248BB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BE0_G_ = int32_t(0x83497BE0);
	if (!UseLiftedCode(143, 0x83248BB8)) { __imp__sub_83248BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248BB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE0_G_, (int64_t)str_TXT_820B0000_B_ - 2756, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248BB8, 0x83248BB8) { ctx.r3.u64 = n_sub_83248BB8(ctx, base); }

uint64_t n_sub_83248BF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BE4_G_ = int32_t(0x83497BE4);
	if (!UseLiftedCode(143, 0x83248BF8)) { __imp__sub_83248BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248BF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE4_G_, (int64_t)str_TXT_820B0000_B_ - 2744, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248BF8, 0x83248BF8) { ctx.r3.u64 = n_sub_83248BF8(ctx, base); }

uint64_t n_sub_83248C38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BE8_G_ = int32_t(0x83497BE8);
	if (!UseLiftedCode(143, 0x83248C38)) { __imp__sub_83248C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248C38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE8_G_, (int64_t)str_TXT_820B0000_B_ - 2716, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248C38, 0x83248C38) { ctx.r3.u64 = n_sub_83248C38(ctx, base); }

uint64_t n_sub_83248C78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BEC_G_ = int32_t(0x83497BEC);
	if (!UseLiftedCode(143, 0x83248C78)) { __imp__sub_83248C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248C78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BEC_G_, (int64_t)str_TXT_820B0000_B_ - 2680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248C78, 0x83248C78) { ctx.r3.u64 = n_sub_83248C78(ctx, base); }

uint64_t n_sub_83248CB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BF0_G_ = int32_t(0x83497BF0);
	if (!UseLiftedCode(143, 0x83248CB8)) { __imp__sub_83248CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248CB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BF0_G_, (int64_t)str_TXT_820B0000_B_ - 2656, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248CB8, 0x83248CB8) { ctx.r3.u64 = n_sub_83248CB8(ctx, base); }

uint64_t n_sub_83248CF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BF4_G_ = int32_t(0x83497BF4);
	if (!UseLiftedCode(143, 0x83248CF8)) { __imp__sub_83248CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248CF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BF4_G_, (int64_t)str_TXT_820B0000_B_ - 2640, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248CF8, 0x83248CF8) { ctx.r3.u64 = n_sub_83248CF8(ctx, base); }

uint64_t n_sub_83248D78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497BFC_G_ = int32_t(0x83497BFC);
	if (!UseLiftedCode(143, 0x83248D78)) { __imp__sub_83248D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248D78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BFC_G_, (int64_t)str_TXT_820B0000_B_ - 2596, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248D78, 0x83248D78) { ctx.r3.u64 = n_sub_83248D78(ctx, base); }

uint64_t n_sub_83248DB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C00_G_ = int32_t(0x83497C00);
	if (!UseLiftedCode(143, 0x83248DB8)) { __imp__sub_83248DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248DB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C00_G_, (int64_t)str_TXT_820B0000_B_ - 2556, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248DB8, 0x83248DB8) { ctx.r3.u64 = n_sub_83248DB8(ctx, base); }

uint64_t n_sub_83248DF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C04_G_ = int32_t(0x83497C04);
	if (!UseLiftedCode(143, 0x83248DF8)) { __imp__sub_83248DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248DF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C04_G_, (int64_t)str_TXT_820B0000_B_ - 2516, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248DF8, 0x83248DF8) { ctx.r3.u64 = n_sub_83248DF8(ctx, base); }

uint64_t n_sub_83248E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C08_G_ = int32_t(0x83497C08);
	if (!UseLiftedCode(143, 0x83248E38)) { __imp__sub_83248E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248E38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C08_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248E38, 0x83248E38) { ctx.r3.u64 = n_sub_83248E38(ctx, base); }

uint64_t n_sub_83248E78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C0C_G_ = int32_t(0x83497C0C);
	if (!UseLiftedCode(143, 0x83248E78)) { __imp__sub_83248E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248E78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C0C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248E78, 0x83248E78) { ctx.r3.u64 = n_sub_83248E78(ctx, base); }

uint64_t n_sub_83248EB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C10_G_ = int32_t(0x83497C10);
	if (!UseLiftedCode(143, 0x83248EB8)) { __imp__sub_83248EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248EB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C10_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248EB8, 0x83248EB8) { ctx.r3.u64 = n_sub_83248EB8(ctx, base); }

uint64_t n_sub_83248EF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C14_G_ = int32_t(0x83497C14);
	if (!UseLiftedCode(143, 0x83248EF8)) { __imp__sub_83248EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248EF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C14_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83248EF8, 0x83248EF8) { ctx.r3.u64 = n_sub_83248EF8(ctx, base); }

uint64_t n_sub_832493D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C6C_G_ = int32_t(0x83497C6C);
	if (!UseLiftedCode(143, 0x832493D0)) { __imp__sub_832493D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832493D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C6C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832493D0, 0x832493D0) { ctx.r3.u64 = n_sub_832493D0(ctx, base); }

uint64_t n_sub_83249410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C70_G_ = int32_t(0x83497C70);
	if (!UseLiftedCode(143, 0x83249410)) { __imp__sub_83249410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C70_G_, (int64_t)str_TXT_820B0000_B_ - 2168, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249410, 0x83249410) { ctx.r3.u64 = n_sub_83249410(ctx, base); }

uint64_t n_sub_83249450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C74_G_ = int32_t(0x83497C74);
	if (!UseLiftedCode(143, 0x83249450)) { __imp__sub_83249450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C74_G_, (int64_t)g_820A0000 + 25284, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249450, 0x83249450) { ctx.r3.u64 = n_sub_83249450(ctx, base); }

uint64_t n_sub_83249490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C78_G_ = int32_t(0x83497C78);
	if (!UseLiftedCode(143, 0x83249490)) { __imp__sub_83249490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C78_G_, (int64_t)str_TXT_820B0000_B_ - 2144, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249490, 0x83249490) { ctx.r3.u64 = n_sub_83249490(ctx, base); }

uint64_t n_sub_832494D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C7C_G_ = int32_t(0x83497C7C);
	if (!UseLiftedCode(143, 0x832494D0)) { __imp__sub_832494D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832494D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C7C_G_, (int64_t)str_TXT_820B0000_B_ - 2104, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832494D0, 0x832494D0) { ctx.r3.u64 = n_sub_832494D0(ctx, base); }

uint64_t n_sub_83249510(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C80_G_ = int32_t(0x83497C80);
	if (!UseLiftedCode(143, 0x83249510)) { __imp__sub_83249510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249510);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C80_G_, (int64_t)str_TXT_820B0000_B_ - 2084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249510, 0x83249510) { ctx.r3.u64 = n_sub_83249510(ctx, base); }

uint64_t n_sub_83249550(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C84_G_ = int32_t(0x83497C84);
	if (!UseLiftedCode(143, 0x83249550)) { __imp__sub_83249550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249550);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C84_G_, (int64_t)str_TXT_820B0000_B_ - 2052, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249550, 0x83249550) { ctx.r3.u64 = n_sub_83249550(ctx, base); }

uint64_t n_sub_83249590(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C88_G_ = int32_t(0x83497C88);
	if (!UseLiftedCode(143, 0x83249590)) { __imp__sub_83249590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249590);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C88_G_, (int64_t)str_TXT_820B0000_B_ - 2016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249590, 0x83249590) { ctx.r3.u64 = n_sub_83249590(ctx, base); }

uint64_t n_sub_832495D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C8C_G_ = int32_t(0x83497C8C);
	if (!UseLiftedCode(143, 0x832495D0)) { __imp__sub_832495D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832495D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C8C_G_, (int64_t)str_TXT_820B0000_B_ - 1956, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832495D0, 0x832495D0) { ctx.r3.u64 = n_sub_832495D0(ctx, base); }

uint64_t n_sub_83249610(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C90_G_ = int32_t(0x83497C90);
	if (!UseLiftedCode(143, 0x83249610)) { __imp__sub_83249610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249610);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C90_G_, (int64_t)str_TXT_820B0000_B_ - 1896, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249610, 0x83249610) { ctx.r3.u64 = n_sub_83249610(ctx, base); }

uint64_t n_sub_83249650(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C94_G_ = int32_t(0x83497C94);
	if (!UseLiftedCode(143, 0x83249650)) { __imp__sub_83249650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249650);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C94_G_, (int64_t)str_TXT_820B0000_B_ - 1836, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249650, 0x83249650) { ctx.r3.u64 = n_sub_83249650(ctx, base); }

uint64_t n_sub_83249690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C98_G_ = int32_t(0x83497C98);
	if (!UseLiftedCode(143, 0x83249690)) { __imp__sub_83249690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C98_G_, (int64_t)str_TXT_820B0000_B_ - 1780, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249690, 0x83249690) { ctx.r3.u64 = n_sub_83249690(ctx, base); }

uint64_t n_sub_832496D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497C9C_G_ = int32_t(0x83497C9C);
	if (!UseLiftedCode(143, 0x832496D0)) { __imp__sub_832496D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832496D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C9C_G_, (int64_t)str_TXT_820B0000_B_ - 1740, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832496D0, 0x832496D0) { ctx.r3.u64 = n_sub_832496D0(ctx, base); }

uint64_t n_sub_83249710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CA0_G_ = int32_t(0x83497CA0);
	if (!UseLiftedCode(143, 0x83249710)) { __imp__sub_83249710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA0_G_, (int64_t)str_TXT_820B0000_B_ - 1680, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249710, 0x83249710) { ctx.r3.u64 = n_sub_83249710(ctx, base); }

uint64_t n_sub_83249750(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CA4_G_ = int32_t(0x83497CA4);
	if (!UseLiftedCode(143, 0x83249750)) { __imp__sub_83249750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA4_G_, (int64_t)str_TXT_820B0000_B_ - 1632, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249750, 0x83249750) { ctx.r3.u64 = n_sub_83249750(ctx, base); }

uint64_t n_sub_83249790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CA8_G_ = int32_t(0x83497CA8);
	if (!UseLiftedCode(143, 0x83249790)) { __imp__sub_83249790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA8_G_, (int64_t)str_TXT_820B0000_B_ - 1588, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249790, 0x83249790) { ctx.r3.u64 = n_sub_83249790(ctx, base); }

uint64_t n_sub_832497D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CAC_G_ = int32_t(0x83497CAC);
	if (!UseLiftedCode(143, 0x832497D0)) { __imp__sub_832497D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832497D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CAC_G_, (int64_t)str_TXT_820B0000_B_ - 1548, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832497D0, 0x832497D0) { ctx.r3.u64 = n_sub_832497D0(ctx, base); }

uint64_t n_sub_83249810(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CB0_G_ = int32_t(0x83497CB0);
	if (!UseLiftedCode(143, 0x83249810)) { __imp__sub_83249810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249810);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB0_G_, (int64_t)str_TXT_820B0000_B_ - 1512, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249810, 0x83249810) { ctx.r3.u64 = n_sub_83249810(ctx, base); }

uint64_t n_sub_83249850(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CB4_G_ = int32_t(0x83497CB4);
	if (!UseLiftedCode(143, 0x83249850)) { __imp__sub_83249850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249850);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB4_G_, (int64_t)str_TXT_820B0000_B_ - 1480, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249850, 0x83249850) { ctx.r3.u64 = n_sub_83249850(ctx, base); }

uint64_t n_sub_83249890(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CB8_G_ = int32_t(0x83497CB8);
	if (!UseLiftedCode(143, 0x83249890)) { __imp__sub_83249890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB8_G_, (int64_t)str_TXT_820B0000_B_ - 1444, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249890, 0x83249890) { ctx.r3.u64 = n_sub_83249890(ctx, base); }

uint64_t n_sub_832498D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CBC_G_ = int32_t(0x83497CBC);
	if (!UseLiftedCode(143, 0x832498D0)) { __imp__sub_832498D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832498D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CBC_G_, (int64_t)str_TXT_820B0000_B_ - 1404, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_832498D0, 0x832498D0) { ctx.r3.u64 = n_sub_832498D0(ctx, base); }

uint64_t n_sub_83249910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CC0_G_ = int32_t(0x83497CC0);
	if (!UseLiftedCode(143, 0x83249910)) { __imp__sub_83249910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC0_G_, (int64_t)str_TXT_820B0000_B_ - 1356, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249910, 0x83249910) { ctx.r3.u64 = n_sub_83249910(ctx, base); }

uint64_t n_sub_83249950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CC4_G_ = int32_t(0x83497CC4);
	if (!UseLiftedCode(143, 0x83249950)) { __imp__sub_83249950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC4_G_, (int64_t)str_TXT_820B0000_B_ - 1320, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249950, 0x83249950) { ctx.r3.u64 = n_sub_83249950(ctx, base); }

uint64_t n_sub_83249990(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CC8_G_ = int32_t(0x83497CC8);
	if (!UseLiftedCode(143, 0x83249990)) { __imp__sub_83249990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249990);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC8_G_, (int64_t)str_TXT_820B0000_B_ - 1264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83249990, 0x83249990) { ctx.r3.u64 = n_sub_83249990(ctx, base); }

uint64_t n_sub_8324A210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CF8_G_ = int32_t(0x83497CF8);
	if (!UseLiftedCode(143, 0x8324A210)) { __imp__sub_8324A210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CF8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A210, 0x8324A210) { ctx.r3.u64 = n_sub_8324A210(ctx, base); }

uint64_t n_sub_8324A250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497CFC_G_ = int32_t(0x83497CFC);
	if (!UseLiftedCode(143, 0x8324A250)) { __imp__sub_8324A250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CFC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A250, 0x8324A250) { ctx.r3.u64 = n_sub_8324A250(ctx, base); }

uint64_t n_sub_8324A290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D00_G_ = int32_t(0x83497D00);
	if (!UseLiftedCode(143, 0x8324A290)) { __imp__sub_8324A290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D00_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A290, 0x8324A290) { ctx.r3.u64 = n_sub_8324A290(ctx, base); }

uint64_t n_sub_8324A2D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D04_G_ = int32_t(0x83497D04);
	if (!UseLiftedCode(143, 0x8324A2D0)) { __imp__sub_8324A2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D04_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A2D0, 0x8324A2D0) { ctx.r3.u64 = n_sub_8324A2D0(ctx, base); }

// sub_8324A348  [64 bytes]
uint64_t n_sub_8324A348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D0C_G_ = int32_t(0x83497D0C);
	if (!UseLiftedCode(143, 0x8324A348)) { __imp__sub_8324A348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A348);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D0C_G_, (int64_t)str_TXT_820B0000_B_ + 2376, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A348, 0x8324A348) { ctx.r3.u64 = n_sub_8324A348(ctx, base); }

uint64_t n_sub_8324A388(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D10_G_ = int32_t(0x83497D10);
	if (!UseLiftedCode(143, 0x8324A388)) { __imp__sub_8324A388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A388);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D10_G_, (int64_t)str_TXT_820B0000_B_ + 2384, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A388, 0x8324A388) { ctx.r3.u64 = n_sub_8324A388(ctx, base); }

uint64_t n_sub_8324A3C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D14_G_ = int32_t(0x83497D14);
	if (!UseLiftedCode(143, 0x8324A3C8)) { __imp__sub_8324A3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A3C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D14_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6968, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A3C8, 0x8324A3C8) { ctx.r3.u64 = n_sub_8324A3C8(ctx, base); }

uint64_t n_sub_8324A408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D18_G_ = int32_t(0x83497D18);
	if (!UseLiftedCode(143, 0x8324A408)) { __imp__sub_8324A408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D18_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 6984, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A408, 0x8324A408) { ctx.r3.u64 = n_sub_8324A408(ctx, base); }

uint64_t n_sub_8324A448(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D1C_G_ = int32_t(0x83497D1C);
	if (!UseLiftedCode(143, 0x8324A448)) { __imp__sub_8324A448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A448);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D1C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A448, 0x8324A448) { ctx.r3.u64 = n_sub_8324A448(ctx, base); }

uint64_t n_sub_8324A488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D20_G_ = int32_t(0x83497D20);
	if (!UseLiftedCode(143, 0x8324A488)) { __imp__sub_8324A488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D20_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7016, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A488, 0x8324A488) { ctx.r3.u64 = n_sub_8324A488(ctx, base); }

uint64_t n_sub_8324A4C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D24_G_ = int32_t(0x83497D24);
	if (!UseLiftedCode(143, 0x8324A4C8)) { __imp__sub_8324A4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A4C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D24_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7032, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A4C8, 0x8324A4C8) { ctx.r3.u64 = n_sub_8324A4C8(ctx, base); }

uint64_t n_sub_8324A508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D28_G_ = int32_t(0x83497D28);
	if (!UseLiftedCode(143, 0x8324A508)) { __imp__sub_8324A508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D28_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A508, 0x8324A508) { ctx.r3.u64 = n_sub_8324A508(ctx, base); }

uint64_t n_sub_8324A6D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D48_G_ = int32_t(0x83497D48);
	if (!UseLiftedCode(143, 0x8324A6D0)) { __imp__sub_8324A6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A6D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D48_G_, (int64_t)str_TXT_820B0000_B_ + 2764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A6D0, 0x8324A6D0) { ctx.r3.u64 = n_sub_8324A6D0(ctx, base); }

uint64_t n_sub_8324A710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D4C_G_ = int32_t(0x83497D4C);
	if (!UseLiftedCode(143, 0x8324A710)) { __imp__sub_8324A710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D4C_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A710, 0x8324A710) { ctx.r3.u64 = n_sub_8324A710(ctx, base); }

uint64_t n_sub_8324A870(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D80_G_ = int32_t(0x83497D80);
	if (!UseLiftedCode(143, 0x8324A870)) { __imp__sub_8324A870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A870);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D80_G_, (int64_t)str_TXT_820B0000_B_ + 2828, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A870, 0x8324A870) { ctx.r3.u64 = n_sub_8324A870(ctx, base); }

uint64_t n_sub_8324A8B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D84_G_ = int32_t(0x83497D84);
	if (!UseLiftedCode(143, 0x8324A8B0)) { __imp__sub_8324A8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A8B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D84_G_, (int64_t)str_TXT_820B0000_B_ + 2848, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A8B0, 0x8324A8B0) { ctx.r3.u64 = n_sub_8324A8B0(ctx, base); }

uint64_t n_sub_8324A8F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D88_G_ = int32_t(0x83497D88);
	if (!UseLiftedCode(143, 0x8324A8F0)) { __imp__sub_8324A8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A8F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D88_G_, (int64_t)str_TXT_820B0000_B_ + 2860, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A8F0, 0x8324A8F0) { ctx.r3.u64 = n_sub_8324A8F0(ctx, base); }

uint64_t n_sub_8324A930(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D8C_G_ = int32_t(0x83497D8C);
	if (!UseLiftedCode(143, 0x8324A930)) { __imp__sub_8324A930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A930);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D8C_G_, (int64_t)str_TXT_820B0000_B_ + 2872, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A930, 0x8324A930) { ctx.r3.u64 = n_sub_8324A930(ctx, base); }

uint64_t n_sub_8324A970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D90_G_ = int32_t(0x83497D90);
	if (!UseLiftedCode(143, 0x8324A970)) { __imp__sub_8324A970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A970);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D90_G_, (int64_t)str_TXT_820B0000_B_ + 2880, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A970, 0x8324A970) { ctx.r3.u64 = n_sub_8324A970(ctx, base); }

uint64_t n_sub_8324A9B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D94_G_ = int32_t(0x83497D94);
	if (!UseLiftedCode(143, 0x8324A9B0)) { __imp__sub_8324A9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A9B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D94_G_, (int64_t)str_TXT_820B0000_B_ - 27440, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A9B0, 0x8324A9B0) { ctx.r3.u64 = n_sub_8324A9B0(ctx, base); }

uint64_t n_sub_8324A9F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D98_G_ = int32_t(0x83497D98);
	if (!UseLiftedCode(143, 0x8324A9F0)) { __imp__sub_8324A9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A9F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D98_G_, (int64_t)str_TXT_820B0000_B_ - 27436, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A9F0, 0x8324A9F0) { ctx.r3.u64 = n_sub_8324A9F0(ctx, base); }

uint64_t n_sub_8324AA30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497D9C_G_ = int32_t(0x83497D9C);
	if (!UseLiftedCode(143, 0x8324AA30)) { __imp__sub_8324AA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AA30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D9C_G_, (int64_t)str_TXT_820B0000_B_ - 27428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AA30, 0x8324AA30) { ctx.r3.u64 = n_sub_8324AA30(ctx, base); }

uint64_t n_sub_8324AA70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DA0_G_ = int32_t(0x83497DA0);
	if (!UseLiftedCode(143, 0x8324AA70)) { __imp__sub_8324AA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AA70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DA0_G_, (int64_t)str_TXT_820B0000_B_ + 2888, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AA70, 0x8324AA70) { ctx.r3.u64 = n_sub_8324AA70(ctx, base); }

uint64_t n_sub_8324AB40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DB0_G_ = int32_t(0x83497DB0);
	if (!UseLiftedCode(143, 0x8324AB40)) { __imp__sub_8324AB40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AB40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AB40, 0x8324AB40) { ctx.r3.u64 = n_sub_8324AB40(ctx, base); }

uint64_t n_sub_8324AB80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DB4_G_ = int32_t(0x83497DB4);
	if (!UseLiftedCode(143, 0x8324AB80)) { __imp__sub_8324AB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AB80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AB80, 0x8324AB80) { ctx.r3.u64 = n_sub_8324AB80(ctx, base); }

uint64_t n_sub_8324ABC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DB8_G_ = int32_t(0x83497DB8);
	if (!UseLiftedCode(143, 0x8324ABC0)) { __imp__sub_8324ABC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ABC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ABC0, 0x8324ABC0) { ctx.r3.u64 = n_sub_8324ABC0(ctx, base); }

uint64_t n_sub_8324AC00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DBC_G_ = int32_t(0x83497DBC);
	if (!UseLiftedCode(143, 0x8324AC00)) { __imp__sub_8324AC00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DBC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AC00, 0x8324AC00) { ctx.r3.u64 = n_sub_8324AC00(ctx, base); }

uint64_t n_sub_8324AC40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DC0_G_ = int32_t(0x83497DC0);
	if (!UseLiftedCode(143, 0x8324AC40)) { __imp__sub_8324AC40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AC40, 0x8324AC40) { ctx.r3.u64 = n_sub_8324AC40(ctx, base); }

uint64_t n_sub_8324AC80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DC4_G_ = int32_t(0x83497DC4);
	if (!UseLiftedCode(143, 0x8324AC80)) { __imp__sub_8324AC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AC80, 0x8324AC80) { ctx.r3.u64 = n_sub_8324AC80(ctx, base); }

uint64_t n_sub_8324ACC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DC8_G_ = int32_t(0x83497DC8);
	if (!UseLiftedCode(143, 0x8324ACC0)) { __imp__sub_8324ACC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ACC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC8_G_, (int64_t)str_TXT_820B0000_B_ + 3880, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ACC0, 0x8324ACC0) { ctx.r3.u64 = n_sub_8324ACC0(ctx, base); }

uint64_t n_sub_8324AD38(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324AD38)) { ctx.r8.u64 = arg1; __imp__sub_8324AD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD38);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7384, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324AD38, 0x8324AD38) { ctx.r3.u64 = n_sub_8324AD38(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324AD48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DD8_G_ = int32_t(0x83497DD8);
	if (!UseLiftedCode(143, 0x8324AD48)) { __imp__sub_8324AD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DD8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AD48, 0x8324AD48) { ctx.r3.u64 = n_sub_8324AD48(ctx, base); }

uint64_t n_sub_8324AD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DDC_G_ = int32_t(0x83497DDC);
	if (!UseLiftedCode(143, 0x8324AD88)) { __imp__sub_8324AD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DDC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AD88, 0x8324AD88) { ctx.r3.u64 = n_sub_8324AD88(ctx, base); }

uint64_t n_sub_8324ADC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DE0_G_ = int32_t(0x83497DE0);
	if (!UseLiftedCode(143, 0x8324ADC8)) { __imp__sub_8324ADC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ADC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ADC8, 0x8324ADC8) { ctx.r3.u64 = n_sub_8324ADC8(ctx, base); }

uint64_t n_sub_8324AED0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	if (!UseLiftedCode(143, 0x8324AED0)) { __imp__sub_8324AED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AED0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE4_G_, (int64_t)str_TXT_820B0000_B_ + 4404, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AED0, 0x8324AED0) { ctx.r3.u64 = n_sub_8324AED0(ctx, base); }

uint64_t n_sub_8324AF10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497DE8_G_ = int32_t(0x83497DE8);
	if (!UseLiftedCode(143, 0x8324AF10)) { __imp__sub_8324AF10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AF10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE8_G_, (int64_t)str_TXT_820B0000_B_ + 4416, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324AF10, 0x8324AF10) { ctx.r3.u64 = n_sub_8324AF10(ctx, base); }

uint64_t n_sub_8324B2F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E48_G_ = int32_t(0x83497E48);
	if (!UseLiftedCode(143, 0x8324B2F8)) { __imp__sub_8324B2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B2F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E48_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7584, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B2F8, 0x8324B2F8) { ctx.r3.u64 = n_sub_8324B2F8(ctx, base); }

uint64_t n_sub_8324B338(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E4C_G_ = int32_t(0x83497E4C);
	if (!UseLiftedCode(143, 0x8324B338)) { __imp__sub_8324B338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B338);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E4C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B338, 0x8324B338) { ctx.r3.u64 = n_sub_8324B338(ctx, base); }

uint64_t n_sub_8324B378(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E50_G_ = int32_t(0x83497E50);
	if (!UseLiftedCode(143, 0x8324B378)) { __imp__sub_8324B378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B378);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E50_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B378, 0x8324B378) { ctx.r3.u64 = n_sub_8324B378(ctx, base); }

uint64_t n_sub_8324B3B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E54_G_ = int32_t(0x83497E54);
	if (!UseLiftedCode(143, 0x8324B3B8)) { __imp__sub_8324B3B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B3B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E54_G_, (int64_t)str_TXT_820B0000_B_ + 8016, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B3B8, 0x8324B3B8) { ctx.r3.u64 = n_sub_8324B3B8(ctx, base); }

uint64_t n_sub_8324B510(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324B510)) { ctx.r8.u64 = arg1; __imp__sub_8324B510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B510);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7648, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324B510, 0x8324B510) { ctx.r3.u64 = n_sub_8324B510(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324B520(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324B520)) { ctx.r8.u64 = arg1; __imp__sub_8324B520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B520);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7768, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324B520, 0x8324B520) { ctx.r3.u64 = n_sub_8324B520(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324B530(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E84_G_ = int32_t(0x83497E84);
	if (!UseLiftedCode(143, 0x8324B530)) { __imp__sub_8324B530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B530);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E84_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B530, 0x8324B530) { ctx.r3.u64 = n_sub_8324B530(ctx, base); }

uint64_t n_sub_8324B570(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E88_G_ = int32_t(0x83497E88);
	if (!UseLiftedCode(143, 0x8324B570)) { __imp__sub_8324B570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B570);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E88_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7872, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B570, 0x8324B570) { ctx.r3.u64 = n_sub_8324B570(ctx, base); }

uint64_t n_sub_8324B5B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E8C_G_ = int32_t(0x83497E8C);
	if (!UseLiftedCode(143, 0x8324B5B0)) { __imp__sub_8324B5B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B5B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E8C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B5B0, 0x8324B5B0) { ctx.r3.u64 = n_sub_8324B5B0(ctx, base); }

uint64_t n_sub_8324B5F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E90_G_ = int32_t(0x83497E90);
	if (!UseLiftedCode(143, 0x8324B5F0)) { __imp__sub_8324B5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B5F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E90_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B5F0, 0x8324B5F0) { ctx.r3.u64 = n_sub_8324B5F0(ctx, base); }

uint64_t n_sub_8324B630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E94_G_ = int32_t(0x83497E94);
	if (!UseLiftedCode(143, 0x8324B630)) { __imp__sub_8324B630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B630);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E94_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B630, 0x8324B630) { ctx.r3.u64 = n_sub_8324B630(ctx, base); }

uint64_t n_sub_8324B670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E98_G_ = int32_t(0x83497E98);
	if (!UseLiftedCode(143, 0x8324B670)) { __imp__sub_8324B670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E98_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B670, 0x8324B670) { ctx.r3.u64 = n_sub_8324B670(ctx, base); }

uint64_t n_sub_8324B6B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497E9C_G_ = int32_t(0x83497E9C);
	if (!UseLiftedCode(143, 0x8324B6B0)) { __imp__sub_8324B6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B6B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E9C_G_, (int64_t)str_TXT_820B0000_B_ + 11696, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 7952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B6B0, 0x8324B6B0) { ctx.r3.u64 = n_sub_8324B6B0(ctx, base); }

uint64_t n_sub_8324B9A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F20_G_ = int32_t(0x83497F20);
	if (!UseLiftedCode(143, 0x8324B9A8)) { __imp__sub_8324B9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B9A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F20_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B9A8, 0x8324B9A8) { ctx.r3.u64 = n_sub_8324B9A8(ctx, base); }

uint64_t n_sub_8324B9E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F24_G_ = int32_t(0x83497F24);
	if (!UseLiftedCode(143, 0x8324B9E8)) { __imp__sub_8324B9E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B9E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F24_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324B9E8, 0x8324B9E8) { ctx.r3.u64 = n_sub_8324B9E8(ctx, base); }

uint64_t n_sub_8324BA28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F28_G_ = int32_t(0x83497F28);
	if (!UseLiftedCode(143, 0x8324BA28)) { __imp__sub_8324BA28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F28_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BA28, 0x8324BA28) { ctx.r3.u64 = n_sub_8324BA28(ctx, base); }

uint64_t n_sub_8324BA68(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324BA68)) { ctx.r8.u64 = arg1; __imp__sub_8324BA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA68);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8120, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324BA68, 0x8324BA68) { ctx.r3.u64 = n_sub_8324BA68(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324BA78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F40_G_ = int32_t(0x83497F40);
	if (!UseLiftedCode(143, 0x8324BA78)) { __imp__sub_8324BA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F40_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BA78, 0x8324BA78) { ctx.r3.u64 = n_sub_8324BA78(ctx, base); }

uint64_t n_sub_8324BAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F44_G_ = int32_t(0x83497F44);
	if (!UseLiftedCode(143, 0x8324BAB8)) { __imp__sub_8324BAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F44_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BAB8, 0x8324BAB8) { ctx.r3.u64 = n_sub_8324BAB8(ctx, base); }

uint64_t n_sub_8324BAF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F48_G_ = int32_t(0x83497F48);
	if (!UseLiftedCode(143, 0x8324BAF8)) { __imp__sub_8324BAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F48_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BAF8, 0x8324BAF8) { ctx.r3.u64 = n_sub_8324BAF8(ctx, base); }

uint64_t n_sub_8324BB38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F4C_G_ = int32_t(0x83497F4C);
	if (!UseLiftedCode(143, 0x8324BB38)) { __imp__sub_8324BB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BB38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F4C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BB38, 0x8324BB38) { ctx.r3.u64 = n_sub_8324BB38(ctx, base); }

uint64_t n_sub_8324BB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F50_G_ = int32_t(0x83497F50);
	if (!UseLiftedCode(143, 0x8324BB78)) { __imp__sub_8324BB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BB78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F50_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BB78, 0x8324BB78) { ctx.r3.u64 = n_sub_8324BB78(ctx, base); }

uint64_t n_sub_8324BBB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F54_G_ = int32_t(0x83497F54);
	if (!UseLiftedCode(143, 0x8324BBB8)) { __imp__sub_8324BBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BBB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F54_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BBB8, 0x8324BBB8) { ctx.r3.u64 = n_sub_8324BBB8(ctx, base); }

uint64_t n_sub_8324BBF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F58_G_ = int32_t(0x83497F58);
	if (!UseLiftedCode(143, 0x8324BBF8)) { __imp__sub_8324BBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BBF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F58_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BBF8, 0x8324BBF8) { ctx.r3.u64 = n_sub_8324BBF8(ctx, base); }

uint64_t n_sub_8324BC38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F5C_G_ = int32_t(0x83497F5C);
	if (!UseLiftedCode(143, 0x8324BC38)) { __imp__sub_8324BC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BC38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F5C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BC38, 0x8324BC38) { ctx.r3.u64 = n_sub_8324BC38(ctx, base); }

uint64_t n_sub_8324BC78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F60_G_ = int32_t(0x83497F60);
	if (!UseLiftedCode(143, 0x8324BC78)) { __imp__sub_8324BC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BC78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F60_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BC78, 0x8324BC78) { ctx.r3.u64 = n_sub_8324BC78(ctx, base); }

uint64_t n_sub_8324BCB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497F64_G_ = int32_t(0x83497F64);
	if (!UseLiftedCode(143, 0x8324BCB8)) { __imp__sub_8324BCB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BCB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F64_G_, (int64_t)str_TXT_820B0000_B_ + 15416, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324BCB8, 0x8324BCB8) { ctx.r3.u64 = n_sub_8324BCB8(ctx, base); }

uint64_t n_sub_8324C190(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FBC_G_ = int32_t(0x83497FBC);
	if (!UseLiftedCode(143, 0x8324C190)) { __imp__sub_8324C190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C190);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FBC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C190, 0x8324C190) { ctx.r3.u64 = n_sub_8324C190(ctx, base); }

uint64_t n_sub_8324C1D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FC0_G_ = int32_t(0x83497FC0);
	if (!UseLiftedCode(143, 0x8324C1D0)) { __imp__sub_8324C1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C1D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C1D0, 0x8324C1D0) { ctx.r3.u64 = n_sub_8324C1D0(ctx, base); }

uint64_t n_sub_8324C210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FC4_G_ = int32_t(0x83497FC4);
	if (!UseLiftedCode(143, 0x8324C210)) { __imp__sub_8324C210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C210, 0x8324C210) { ctx.r3.u64 = n_sub_8324C210(ctx, base); }

uint64_t n_sub_8324C250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FC8_G_ = int32_t(0x83497FC8);
	if (!UseLiftedCode(143, 0x8324C250)) { __imp__sub_8324C250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C250, 0x8324C250) { ctx.r3.u64 = n_sub_8324C250(ctx, base); }

uint64_t n_sub_8324C290(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FCC_G_ = int32_t(0x83497FCC);
	if (!UseLiftedCode(143, 0x8324C290)) { __imp__sub_8324C290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FCC_G_, (int64_t)str_TXT_820B0000_B_ + 16720, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C290, 0x8324C290) { ctx.r3.u64 = n_sub_8324C290(ctx, base); }

uint64_t n_sub_8324C2D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FD0_G_ = int32_t(0x83497FD0);
	if (!UseLiftedCode(143, 0x8324C2D0)) { __imp__sub_8324C2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD0_G_, (int64_t)str_TXT_820B0000_B_ + 16756, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C2D0, 0x8324C2D0) { ctx.r3.u64 = n_sub_8324C2D0(ctx, base); }

uint64_t n_sub_8324C310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FD4_G_ = int32_t(0x83497FD4);
	if (!UseLiftedCode(143, 0x8324C310)) { __imp__sub_8324C310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C310);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD4_G_, (int64_t)str_TXT_820B0000_B_ + 16792, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C310, 0x8324C310) { ctx.r3.u64 = n_sub_8324C310(ctx, base); }

uint64_t n_sub_8324C350(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FD8_G_ = int32_t(0x83497FD8);
	if (!UseLiftedCode(143, 0x8324C350)) { __imp__sub_8324C350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C350);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD8_G_, (int64_t)str_TXT_820B0000_B_ + 16824, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C350, 0x8324C350) { ctx.r3.u64 = n_sub_8324C350(ctx, base); }

uint64_t n_sub_8324C390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FDC_G_ = int32_t(0x83497FDC);
	if (!UseLiftedCode(143, 0x8324C390)) { __imp__sub_8324C390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C390);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FDC_G_, (int64_t)str_TXT_820B0000_B_ + 16864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C390, 0x8324C390) { ctx.r3.u64 = n_sub_8324C390(ctx, base); }

uint64_t n_sub_8324C3D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FE0_G_ = int32_t(0x83497FE0);
	if (!UseLiftedCode(143, 0x8324C3D0)) { __imp__sub_8324C3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C3D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE0_G_, (int64_t)str_TXT_820B0000_B_ + 16904, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C3D0, 0x8324C3D0) { ctx.r3.u64 = n_sub_8324C3D0(ctx, base); }

uint64_t n_sub_8324C410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FE4_G_ = int32_t(0x83497FE4);
	if (!UseLiftedCode(143, 0x8324C410)) { __imp__sub_8324C410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C410);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE4_G_, (int64_t)str_TXT_820B0000_B_ + 16944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C410, 0x8324C410) { ctx.r3.u64 = n_sub_8324C410(ctx, base); }

uint64_t n_sub_8324C450(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FE8_G_ = int32_t(0x83497FE8);
	if (!UseLiftedCode(143, 0x8324C450)) { __imp__sub_8324C450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE8_G_, (int64_t)str_TXT_820B0000_B_ + 16976, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C450, 0x8324C450) { ctx.r3.u64 = n_sub_8324C450(ctx, base); }

uint64_t n_sub_8324C490(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FEC_G_ = int32_t(0x83497FEC);
	if (!UseLiftedCode(143, 0x8324C490)) { __imp__sub_8324C490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C490);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FEC_G_, (int64_t)str_TXT_820B0000_B_ + 17012, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C490, 0x8324C490) { ctx.r3.u64 = n_sub_8324C490(ctx, base); }

uint64_t n_sub_8324C4D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FF0_G_ = int32_t(0x83497FF0);
	if (!UseLiftedCode(143, 0x8324C4D0)) { __imp__sub_8324C4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C4D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF0_G_, (int64_t)str_TXT_820B0000_B_ + 17040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C4D0, 0x8324C4D0) { ctx.r3.u64 = n_sub_8324C4D0(ctx, base); }

uint64_t n_sub_8324C510(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FF4_G_ = int32_t(0x83497FF4);
	if (!UseLiftedCode(143, 0x8324C510)) { __imp__sub_8324C510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C510);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF4_G_, (int64_t)str_TXT_820B0000_B_ + 17072, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C510, 0x8324C510) { ctx.r3.u64 = n_sub_8324C510(ctx, base); }

uint64_t n_sub_8324C550(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FF8_G_ = int32_t(0x83497FF8);
	if (!UseLiftedCode(143, 0x8324C550)) { __imp__sub_8324C550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C550);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF8_G_, (int64_t)str_TXT_820B0000_B_ + 17088, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C550, 0x8324C550) { ctx.r3.u64 = n_sub_8324C550(ctx, base); }

uint64_t n_sub_8324C590(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83497FFC_G_ = int32_t(0x83497FFC);
	if (!UseLiftedCode(143, 0x8324C590)) { __imp__sub_8324C590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C590);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FFC_G_, (int64_t)str_TXT_820B0000_B_ + 17104, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C590, 0x8324C590) { ctx.r3.u64 = n_sub_8324C590(ctx, base); }

uint64_t n_sub_8324C5D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498000_G_ = int32_t(0x83498000);
	if (!UseLiftedCode(143, 0x8324C5D0)) { __imp__sub_8324C5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C5D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498000_G_, (int64_t)str_TXT_820B0000_B_ + 17116, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C5D0, 0x8324C5D0) { ctx.r3.u64 = n_sub_8324C5D0(ctx, base); }

uint64_t n_sub_8324C610(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498004_G_ = int32_t(0x83498004);
	if (!UseLiftedCode(143, 0x8324C610)) { __imp__sub_8324C610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C610);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498004_G_, (int64_t)str_TXT_820B0000_B_ + 17136, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C610, 0x8324C610) { ctx.r3.u64 = n_sub_8324C610(ctx, base); }

uint64_t n_sub_8324C650(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498008_G_ = int32_t(0x83498008);
	if (!UseLiftedCode(143, 0x8324C650)) { __imp__sub_8324C650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C650);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498008_G_, (int64_t)str_TXT_820B0000_B_ + 17164, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C650, 0x8324C650) { ctx.r3.u64 = n_sub_8324C650(ctx, base); }

uint64_t n_sub_8324C690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349800C_G_ = int32_t(0x8349800C);
	if (!UseLiftedCode(143, 0x8324C690)) { __imp__sub_8324C690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C690);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349800C_G_, (int64_t)str_TXT_820B0000_B_ + 17204, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C690, 0x8324C690) { ctx.r3.u64 = n_sub_8324C690(ctx, base); }

uint64_t n_sub_8324C6D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498010_G_ = int32_t(0x83498010);
	if (!UseLiftedCode(143, 0x8324C6D0)) { __imp__sub_8324C6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C6D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498010_G_, (int64_t)str_TXT_820B0000_B_ + 17232, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C6D0, 0x8324C6D0) { ctx.r3.u64 = n_sub_8324C6D0(ctx, base); }

uint64_t n_sub_8324C710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498014_G_ = int32_t(0x83498014);
	if (!UseLiftedCode(143, 0x8324C710)) { __imp__sub_8324C710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498014_G_, (int64_t)str_TXT_820B0000_B_ + 17264, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C710, 0x8324C710) { ctx.r3.u64 = n_sub_8324C710(ctx, base); }

uint64_t n_sub_8324C750(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498018_G_ = int32_t(0x83498018);
	if (!UseLiftedCode(143, 0x8324C750)) { __imp__sub_8324C750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C750);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498018_G_, (int64_t)str_TXT_820B0000_B_ + 17300, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C750, 0x8324C750) { ctx.r3.u64 = n_sub_8324C750(ctx, base); }

uint64_t n_sub_8324C790(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349801C_G_ = int32_t(0x8349801C);
	if (!UseLiftedCode(143, 0x8324C790)) { __imp__sub_8324C790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C790);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349801C_G_, (int64_t)str_TXT_820B0000_B_ + 17340, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C790, 0x8324C790) { ctx.r3.u64 = n_sub_8324C790(ctx, base); }

uint64_t n_sub_8324C7D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498020_G_ = int32_t(0x83498020);
	if (!UseLiftedCode(143, 0x8324C7D0)) { __imp__sub_8324C7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C7D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498020_G_, (int64_t)str_TXT_820B0000_B_ + 17392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C7D0, 0x8324C7D0) { ctx.r3.u64 = n_sub_8324C7D0(ctx, base); }

uint64_t n_sub_8324C810(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498024_G_ = int32_t(0x83498024);
	if (!UseLiftedCode(143, 0x8324C810)) { __imp__sub_8324C810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C810);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498024_G_, (int64_t)str_TXT_820B0000_B_ + 17452, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C810, 0x8324C810) { ctx.r3.u64 = n_sub_8324C810(ctx, base); }

uint64_t n_sub_8324C850(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498028_G_ = int32_t(0x83498028);
	if (!UseLiftedCode(143, 0x8324C850)) { __imp__sub_8324C850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C850);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498028_G_, (int64_t)str_TXT_820B0000_B_ + 17504, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C850, 0x8324C850) { ctx.r3.u64 = n_sub_8324C850(ctx, base); }

uint64_t n_sub_8324C890(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349802C_G_ = int32_t(0x8349802C);
	if (!UseLiftedCode(143, 0x8324C890)) { __imp__sub_8324C890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C890);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349802C_G_, (int64_t)str_TXT_820B0000_B_ + 17564, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C890, 0x8324C890) { ctx.r3.u64 = n_sub_8324C890(ctx, base); }

uint64_t n_sub_8324C8D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498030_G_ = int32_t(0x83498030);
	if (!UseLiftedCode(143, 0x8324C8D0)) { __imp__sub_8324C8D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C8D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498030_G_, (int64_t)str_TXT_820B0000_B_ + 17604, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C8D0, 0x8324C8D0) { ctx.r3.u64 = n_sub_8324C8D0(ctx, base); }

uint64_t n_sub_8324C910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498034_G_ = int32_t(0x83498034);
	if (!UseLiftedCode(143, 0x8324C910)) { __imp__sub_8324C910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498034_G_, (int64_t)str_TXT_820B0000_B_ + 17644, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C910, 0x8324C910) { ctx.r3.u64 = n_sub_8324C910(ctx, base); }

uint64_t n_sub_8324C950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498038_G_ = int32_t(0x83498038);
	if (!UseLiftedCode(143, 0x8324C950)) { __imp__sub_8324C950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498038_G_, (int64_t)str_TXT_820B0000_B_ + 17684, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324C950, 0x8324C950) { ctx.r3.u64 = n_sub_8324C950(ctx, base); }

uint64_t n_sub_8324CA50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498040_G_ = int32_t(0x83498040);
	if (!UseLiftedCode(143, 0x8324CA50)) { __imp__sub_8324CA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CA50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498040_G_, (int64_t)str_TXT_820B0000_B_ + 17764, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8888, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CA50, 0x8324CA50) { ctx.r3.u64 = n_sub_8324CA50(ctx, base); }

uint64_t n_sub_8324CA90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498044_G_ = int32_t(0x83498044);
	if (!UseLiftedCode(143, 0x8324CA90)) { __imp__sub_8324CA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CA90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498044_G_, (int64_t)str_TXT_820B0000_B_ + 17800, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8904, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CA90, 0x8324CA90) { ctx.r3.u64 = n_sub_8324CA90(ctx, base); }

uint64_t n_sub_8324CAD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498048_G_ = int32_t(0x83498048);
	if (!UseLiftedCode(143, 0x8324CAD0)) { __imp__sub_8324CAD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CAD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498048_G_, (int64_t)str_TXT_820B0000_B_ + 17824, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8920, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CAD0, 0x8324CAD0) { ctx.r3.u64 = n_sub_8324CAD0(ctx, base); }

uint64_t n_sub_8324CB10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349804C_G_ = int32_t(0x8349804C);
	if (!UseLiftedCode(143, 0x8324CB10)) { __imp__sub_8324CB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CB10);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349804C_G_, (int64_t)str_TXT_820B0000_B_ + 17852, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8936, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CB10, 0x8324CB10) { ctx.r3.u64 = n_sub_8324CB10(ctx, base); }

uint64_t n_sub_8324CB50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498050_G_ = int32_t(0x83498050);
	if (!UseLiftedCode(143, 0x8324CB50)) { __imp__sub_8324CB50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CB50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498050_G_, (int64_t)str_TXT_820B0000_B_ + 17864, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 8952, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CB50, 0x8324CB50) { ctx.r3.u64 = n_sub_8324CB50(ctx, base); }

uint64_t n_sub_8324CFA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349808C_G_ = int32_t(0x8349808C);
	if (!UseLiftedCode(143, 0x8324CFA8)) { __imp__sub_8324CFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CFA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349808C_G_, (int64_t)str_TXT_820B0000_B_ - 5908, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CFA8, 0x8324CFA8) { ctx.r3.u64 = n_sub_8324CFA8(ctx, base); }

uint64_t n_sub_8324CFE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834980F0_G_ = int32_t(0x834980F0);
	if (!UseLiftedCode(143, 0x8324CFE8)) { __imp__sub_8324CFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CFE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F0_G_, (int64_t)str_TXT_820B0000_B_ + 18280, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324CFE8, 0x8324CFE8) { ctx.r3.u64 = n_sub_8324CFE8(ctx, base); }

uint64_t n_sub_8324D028(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834980F4_G_ = int32_t(0x834980F4);
	if (!UseLiftedCode(143, 0x8324D028)) { __imp__sub_8324D028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D028);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F4_G_, (int64_t)str_TXT_820B0000_B_ + 18316, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D028, 0x8324D028) { ctx.r3.u64 = n_sub_8324D028(ctx, base); }

uint64_t n_sub_8324D068(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834980F8_G_ = int32_t(0x834980F8);
	if (!UseLiftedCode(143, 0x8324D068)) { __imp__sub_8324D068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D068);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D068, 0x8324D068) { ctx.r3.u64 = n_sub_8324D068(ctx, base); }

uint64_t n_sub_8324D0A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834980FC_G_ = int32_t(0x834980FC);
	if (!UseLiftedCode(143, 0x8324D0A8)) { __imp__sub_8324D0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D0A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834980FC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D0A8, 0x8324D0A8) { ctx.r3.u64 = n_sub_8324D0A8(ctx, base); }

uint64_t n_sub_8324D0E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498100_G_ = int32_t(0x83498100);
	if (!UseLiftedCode(143, 0x8324D0E8)) { __imp__sub_8324D0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D0E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498100_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D0E8, 0x8324D0E8) { ctx.r3.u64 = n_sub_8324D0E8(ctx, base); }

uint64_t n_sub_8324D128(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498104_G_ = int32_t(0x83498104);
	if (!UseLiftedCode(143, 0x8324D128)) { __imp__sub_8324D128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D128);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498104_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D128, 0x8324D128) { ctx.r3.u64 = n_sub_8324D128(ctx, base); }

uint64_t n_sub_8324D168(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498108_G_ = int32_t(0x83498108);
	if (!UseLiftedCode(143, 0x8324D168)) { __imp__sub_8324D168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D168);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498108_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D168, 0x8324D168) { ctx.r3.u64 = n_sub_8324D168(ctx, base); }

uint64_t n_sub_8324D1A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349810C_G_ = int32_t(0x8349810C);
	if (!UseLiftedCode(143, 0x8324D1A8)) { __imp__sub_8324D1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349810C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D1A8, 0x8324D1A8) { ctx.r3.u64 = n_sub_8324D1A8(ctx, base); }

uint64_t n_sub_8324D1E8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324D1E8)) { ctx.r8.u64 = arg1; __imp__sub_8324D1E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1E8);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9320, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324D1E8, 0x8324D1E8) { ctx.r3.u64 = n_sub_8324D1E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324D1F8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324D1F8)) { ctx.r8.u64 = arg1; __imp__sub_8324D1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1F8);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9424, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324D1F8, 0x8324D1F8) { ctx.r3.u64 = n_sub_8324D1F8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324D208(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324D208)) { ctx.r8.u64 = arg1; __imp__sub_8324D208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D208);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9528, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324D208, 0x8324D208) { ctx.r3.u64 = n_sub_8324D208(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324D218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498140_G_ = int32_t(0x83498140);
	if (!UseLiftedCode(143, 0x8324D218)) { __imp__sub_8324D218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D218);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498140_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9616, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D218, 0x8324D218) { ctx.r3.u64 = n_sub_8324D218(ctx, base); }

uint64_t n_sub_8324D258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498144_G_ = int32_t(0x83498144);
	if (!UseLiftedCode(143, 0x8324D258)) { __imp__sub_8324D258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D258);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498144_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9632, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D258, 0x8324D258) { ctx.r3.u64 = n_sub_8324D258(ctx, base); }

uint64_t n_sub_8324D298(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498148_G_ = int32_t(0x83498148);
	if (!UseLiftedCode(143, 0x8324D298)) { __imp__sub_8324D298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D298);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498148_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D298, 0x8324D298) { ctx.r3.u64 = n_sub_8324D298(ctx, base); }

uint64_t n_sub_8324D2D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349814C_G_ = int32_t(0x8349814C);
	if (!UseLiftedCode(143, 0x8324D2D8)) { __imp__sub_8324D2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D2D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349814C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9664, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D2D8, 0x8324D2D8) { ctx.r3.u64 = n_sub_8324D2D8(ctx, base); }

uint64_t n_sub_8324D318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498150_G_ = int32_t(0x83498150);
	if (!UseLiftedCode(143, 0x8324D318)) { __imp__sub_8324D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498150_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9680, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D318, 0x8324D318) { ctx.r3.u64 = n_sub_8324D318(ctx, base); }

uint64_t n_sub_8324D358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498154_G_ = int32_t(0x83498154);
	if (!UseLiftedCode(143, 0x8324D358)) { __imp__sub_8324D358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498154_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D358, 0x8324D358) { ctx.r3.u64 = n_sub_8324D358(ctx, base); }

uint64_t n_sub_8324D398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498158_G_ = int32_t(0x83498158);
	if (!UseLiftedCode(143, 0x8324D398)) { __imp__sub_8324D398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D398);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498158_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9712, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D398, 0x8324D398) { ctx.r3.u64 = n_sub_8324D398(ctx, base); }

uint64_t n_sub_8324D3D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349815C_G_ = int32_t(0x8349815C);
	if (!UseLiftedCode(143, 0x8324D3D8)) { __imp__sub_8324D3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D3D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349815C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9728, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D3D8, 0x8324D3D8) { ctx.r3.u64 = n_sub_8324D3D8(ctx, base); }

uint64_t n_sub_8324D418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498160_G_ = int32_t(0x83498160);
	if (!UseLiftedCode(143, 0x8324D418)) { __imp__sub_8324D418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D418);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498160_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D418, 0x8324D418) { ctx.r3.u64 = n_sub_8324D418(ctx, base); }

uint64_t n_sub_8324D458(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498164_G_ = int32_t(0x83498164);
	if (!UseLiftedCode(143, 0x8324D458)) { __imp__sub_8324D458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D458);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498164_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9760, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D458, 0x8324D458) { ctx.r3.u64 = n_sub_8324D458(ctx, base); }

uint64_t n_sub_8324D498(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498168_G_ = int32_t(0x83498168);
	if (!UseLiftedCode(143, 0x8324D498)) { __imp__sub_8324D498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D498);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498168_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9776, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D498, 0x8324D498) { ctx.r3.u64 = n_sub_8324D498(ctx, base); }

uint64_t n_sub_8324D4D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349816C_G_ = int32_t(0x8349816C);
	if (!UseLiftedCode(143, 0x8324D4D8)) { __imp__sub_8324D4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D4D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349816C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D4D8, 0x8324D4D8) { ctx.r3.u64 = n_sub_8324D4D8(ctx, base); }

uint64_t n_sub_8324D518(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498170_G_ = int32_t(0x83498170);
	if (!UseLiftedCode(143, 0x8324D518)) { __imp__sub_8324D518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D518);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498170_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9808, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D518, 0x8324D518) { ctx.r3.u64 = n_sub_8324D518(ctx, base); }

uint64_t n_sub_8324D558(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498174_G_ = int32_t(0x83498174);
	if (!UseLiftedCode(143, 0x8324D558)) { __imp__sub_8324D558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498174_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9824, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D558, 0x8324D558) { ctx.r3.u64 = n_sub_8324D558(ctx, base); }

uint64_t n_sub_8324D598(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498178_G_ = int32_t(0x83498178);
	if (!UseLiftedCode(143, 0x8324D598)) { __imp__sub_8324D598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D598);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498178_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D598, 0x8324D598) { ctx.r3.u64 = n_sub_8324D598(ctx, base); }

uint64_t n_sub_8324D5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349817C_G_ = int32_t(0x8349817C);
	if (!UseLiftedCode(143, 0x8324D5D8)) { __imp__sub_8324D5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D5D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349817C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9856, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D5D8, 0x8324D5D8) { ctx.r3.u64 = n_sub_8324D5D8(ctx, base); }

uint64_t n_sub_8324D6F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498198_G_ = int32_t(0x83498198);
	if (!UseLiftedCode(143, 0x8324D6F8)) { __imp__sub_8324D6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D6F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498198_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D6F8, 0x8324D6F8) { ctx.r3.u64 = n_sub_8324D6F8(ctx, base); }

uint64_t n_sub_8324D738(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349819C_G_ = int32_t(0x8349819C);
	if (!UseLiftedCode(143, 0x8324D738)) { __imp__sub_8324D738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D738);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349819C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 9992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D738, 0x8324D738) { ctx.r3.u64 = n_sub_8324D738(ctx, base); }

uint64_t n_sub_8324D778(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981A0_G_ = int32_t(0x834981A0);
	if (!UseLiftedCode(143, 0x8324D778)) { __imp__sub_8324D778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D778);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D778, 0x8324D778) { ctx.r3.u64 = n_sub_8324D778(ctx, base); }

uint64_t n_sub_8324D7B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981A4_G_ = int32_t(0x834981A4);
	if (!UseLiftedCode(143, 0x8324D7B8)) { __imp__sub_8324D7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D7B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A4_G_, (int64_t)str_TXT_820B0000_B_ + 29008, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D7B8, 0x8324D7B8) { ctx.r3.u64 = n_sub_8324D7B8(ctx, base); }

uint64_t n_sub_8324D7F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981A8_G_ = int32_t(0x834981A8);
	if (!UseLiftedCode(143, 0x8324D7F8)) { __imp__sub_8324D7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D7F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A8_G_, (int64_t)str_TXT_820B0000_B_ + 29024, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D7F8, 0x8324D7F8) { ctx.r3.u64 = n_sub_8324D7F8(ctx, base); }

uint64_t n_sub_8324D838(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981AC_G_ = int32_t(0x834981AC);
	if (!UseLiftedCode(143, 0x8324D838)) { __imp__sub_8324D838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981AC_G_, (int64_t)str_TXT_820B0000_B_ + 29040, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D838, 0x8324D838) { ctx.r3.u64 = n_sub_8324D838(ctx, base); }

uint64_t n_sub_8324D878(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981B0_G_ = int32_t(0x834981B0);
	if (!UseLiftedCode(143, 0x8324D878)) { __imp__sub_8324D878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B0_G_, (int64_t)str_TXT_820B0000_B_ + 29060, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D878, 0x8324D878) { ctx.r3.u64 = n_sub_8324D878(ctx, base); }

uint64_t n_sub_8324D8B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981B4_G_ = int32_t(0x834981B4);
	if (!UseLiftedCode(143, 0x8324D8B8)) { __imp__sub_8324D8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D8B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B4_G_, (int64_t)str_TXT_820B0000_B_ + 29072, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D8B8, 0x8324D8B8) { ctx.r3.u64 = n_sub_8324D8B8(ctx, base); }

uint64_t n_sub_8324D8F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981B8_G_ = int32_t(0x834981B8);
	if (!UseLiftedCode(143, 0x8324D8F8)) { __imp__sub_8324D8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D8F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B8_G_, (int64_t)str_TXT_820B0000_B_ + 29092, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D8F8, 0x8324D8F8) { ctx.r3.u64 = n_sub_8324D8F8(ctx, base); }

uint64_t n_sub_8324D938(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981BC_G_ = int32_t(0x834981BC);
	if (!UseLiftedCode(143, 0x8324D938)) { __imp__sub_8324D938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D938);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981BC_G_, (int64_t)str_TXT_820B0000_B_ + 29112, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D938, 0x8324D938) { ctx.r3.u64 = n_sub_8324D938(ctx, base); }

uint64_t n_sub_8324D978(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981C0_G_ = int32_t(0x834981C0);
	if (!UseLiftedCode(143, 0x8324D978)) { __imp__sub_8324D978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D978);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C0_G_, (int64_t)str_TXT_820B0000_B_ + 29136, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D978, 0x8324D978) { ctx.r3.u64 = n_sub_8324D978(ctx, base); }

uint64_t n_sub_8324D9B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981C4_G_ = int32_t(0x834981C4);
	if (!UseLiftedCode(143, 0x8324D9B8)) { __imp__sub_8324D9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D9B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C4_G_, (int64_t)str_TXT_820B0000_B_ + 29160, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D9B8, 0x8324D9B8) { ctx.r3.u64 = n_sub_8324D9B8(ctx, base); }

uint64_t n_sub_8324D9F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981C8_G_ = int32_t(0x834981C8);
	if (!UseLiftedCode(143, 0x8324D9F8)) { __imp__sub_8324D9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D9F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C8_G_, (int64_t)str_TXT_820B0000_B_ + 29184, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324D9F8, 0x8324D9F8) { ctx.r3.u64 = n_sub_8324D9F8(ctx, base); }

uint64_t n_sub_8324DA38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981CC_G_ = int32_t(0x834981CC);
	if (!UseLiftedCode(143, 0x8324DA38)) { __imp__sub_8324DA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DA38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981CC_G_, (int64_t)str_TXT_820B0000_B_ + 29208, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DA38, 0x8324DA38) { ctx.r3.u64 = n_sub_8324DA38(ctx, base); }

uint64_t n_sub_8324DA78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981D0_G_ = int32_t(0x834981D0);
	if (!UseLiftedCode(143, 0x8324DA78)) { __imp__sub_8324DA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D0_G_, (int64_t)str_TXT_820B0000_B_ + 29220, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DA78, 0x8324DA78) { ctx.r3.u64 = n_sub_8324DA78(ctx, base); }

uint64_t n_sub_8324DAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981D4_G_ = int32_t(0x834981D4);
	if (!UseLiftedCode(143, 0x8324DAB8)) { __imp__sub_8324DAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D4_G_, (int64_t)str_TXT_820B0000_B_ + 29224, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DAB8, 0x8324DAB8) { ctx.r3.u64 = n_sub_8324DAB8(ctx, base); }

uint64_t n_sub_8324DAF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981D8_G_ = int32_t(0x834981D8);
	if (!UseLiftedCode(143, 0x8324DAF8)) { __imp__sub_8324DAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D8_G_, (int64_t)str_TXT_820B0000_B_ + 29232, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DAF8, 0x8324DAF8) { ctx.r3.u64 = n_sub_8324DAF8(ctx, base); }

uint64_t n_sub_8324DB38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981DC_G_ = int32_t(0x834981DC);
	if (!UseLiftedCode(143, 0x8324DB38)) { __imp__sub_8324DB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DB38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981DC_G_, (int64_t)str_TXT_820B0000_B_ + 29260, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DB38, 0x8324DB38) { ctx.r3.u64 = n_sub_8324DB38(ctx, base); }

uint64_t n_sub_8324DB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981E0_G_ = int32_t(0x834981E0);
	if (!UseLiftedCode(143, 0x8324DB78)) { __imp__sub_8324DB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DB78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E0_G_, (int64_t)str_TXT_820B0000_B_ + 29288, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DB78, 0x8324DB78) { ctx.r3.u64 = n_sub_8324DB78(ctx, base); }

uint64_t n_sub_8324DBB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981E4_G_ = int32_t(0x834981E4);
	if (!UseLiftedCode(143, 0x8324DBB8)) { __imp__sub_8324DBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DBB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E4_G_, (int64_t)str_TXT_820B0000_B_ + 29300, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DBB8, 0x8324DBB8) { ctx.r3.u64 = n_sub_8324DBB8(ctx, base); }

uint64_t n_sub_8324DBF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981E8_G_ = int32_t(0x834981E8);
	if (!UseLiftedCode(143, 0x8324DBF8)) { __imp__sub_8324DBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DBF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E8_G_, (int64_t)str_TXT_820B0000_B_ + 29316, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DBF8, 0x8324DBF8) { ctx.r3.u64 = n_sub_8324DBF8(ctx, base); }

uint64_t n_sub_8324DC38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981EC_G_ = int32_t(0x834981EC);
	if (!UseLiftedCode(143, 0x8324DC38)) { __imp__sub_8324DC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DC38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981EC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DC38, 0x8324DC38) { ctx.r3.u64 = n_sub_8324DC38(ctx, base); }

uint64_t n_sub_8324DC78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981F0_G_ = int32_t(0x834981F0);
	if (!UseLiftedCode(143, 0x8324DC78)) { __imp__sub_8324DC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DC78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981F0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DC78, 0x8324DC78) { ctx.r3.u64 = n_sub_8324DC78(ctx, base); }

uint64_t n_sub_8324DCB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834981F4_G_ = int32_t(0x834981F4);
	if (!UseLiftedCode(143, 0x8324DCB8)) { __imp__sub_8324DCB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DCB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834981F4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10344, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324DCB8, 0x8324DCB8) { ctx.r3.u64 = n_sub_8324DCB8(ctx, base); }

uint64_t n_sub_8324E048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982A0_G_ = int32_t(0x834982A0);
	if (!UseLiftedCode(143, 0x8324E048)) { __imp__sub_8324E048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E048, 0x8324E048) { ctx.r3.u64 = n_sub_8324E048(ctx, base); }

uint64_t n_sub_8324E088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982A4_G_ = int32_t(0x834982A4);
	if (!UseLiftedCode(143, 0x8324E088)) { __imp__sub_8324E088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E088, 0x8324E088) { ctx.r3.u64 = n_sub_8324E088(ctx, base); }

uint64_t n_sub_8324E0C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982A8_G_ = int32_t(0x834982A8);
	if (!UseLiftedCode(143, 0x8324E0C8)) { __imp__sub_8324E0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E0C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E0C8, 0x8324E0C8) { ctx.r3.u64 = n_sub_8324E0C8(ctx, base); }

uint64_t n_sub_8324E108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982AC_G_ = int32_t(0x834982AC);
	if (!UseLiftedCode(143, 0x8324E108)) { __imp__sub_8324E108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982AC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E108, 0x8324E108) { ctx.r3.u64 = n_sub_8324E108(ctx, base); }

uint64_t n_sub_8324E148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982B0_G_ = int32_t(0x834982B0);
	if (!UseLiftedCode(143, 0x8324E148)) { __imp__sub_8324E148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982B0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E148, 0x8324E148) { ctx.r3.u64 = n_sub_8324E148(ctx, base); }

uint64_t n_sub_8324E188(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834982B4_G_ = int32_t(0x834982B4);
	if (!UseLiftedCode(143, 0x8324E188)) { __imp__sub_8324E188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E188);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834982B4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E188, 0x8324E188) { ctx.r3.u64 = n_sub_8324E188(ctx, base); }

uint64_t n_sub_8324E3C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349833C_G_ = int32_t(0x8349833C);
	if (!UseLiftedCode(143, 0x8324E3C0)) { __imp__sub_8324E3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E3C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349833C_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10896, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E3C0, 0x8324E3C0) { ctx.r3.u64 = n_sub_8324E3C0(ctx, base); }

uint64_t n_sub_8324E400(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498340_G_ = int32_t(0x83498340);
	if (!UseLiftedCode(143, 0x8324E400)) { __imp__sub_8324E400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E400);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498340_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E400, 0x8324E400) { ctx.r3.u64 = n_sub_8324E400(ctx, base); }

uint64_t n_sub_8324E440(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498344_G_ = int32_t(0x83498344);
	if (!UseLiftedCode(143, 0x8324E440)) { __imp__sub_8324E440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E440);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498344_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E440, 0x8324E440) { ctx.r3.u64 = n_sub_8324E440(ctx, base); }

// sub_8324E480  [64 bytes]
uint64_t n_sub_8324E480(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498348_G_ = int32_t(0x83498348);
	if (!UseLiftedCode(143, 0x8324E480)) { __imp__sub_8324E480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E480);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498348_G_, (int64_t)str_TXT_820C0000_B_ - 30964, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10944, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E480, 0x8324E480) { ctx.r3.u64 = n_sub_8324E480(ctx, base); }

uint64_t n_sub_8324E4C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349834C_G_ = int32_t(0x8349834C);
	if (!UseLiftedCode(143, 0x8324E4C0)) { __imp__sub_8324E4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E4C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349834C_G_, (int64_t)str_TXT_820C0000_B_ - 30956, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10960, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E4C0, 0x8324E4C0) { ctx.r3.u64 = n_sub_8324E4C0(ctx, base); }

uint64_t n_sub_8324E500(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498350_G_ = int32_t(0x83498350);
	if (!UseLiftedCode(143, 0x8324E500)) { __imp__sub_8324E500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E500);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498350_G_, (int64_t)str_TXT_820C0000_B_ - 30944, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10976, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E500, 0x8324E500) { ctx.r3.u64 = n_sub_8324E500(ctx, base); }

uint64_t n_sub_8324E540(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498354_G_ = int32_t(0x83498354);
	if (!UseLiftedCode(143, 0x8324E540)) { __imp__sub_8324E540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E540);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498354_G_, (int64_t)str_TXT_820C0000_B_ - 30932, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 10992, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E540, 0x8324E540) { ctx.r3.u64 = n_sub_8324E540(ctx, base); }

uint64_t n_sub_8324E580(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498358_G_ = int32_t(0x83498358);
	if (!UseLiftedCode(143, 0x8324E580)) { __imp__sub_8324E580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E580);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498358_G_, (int64_t)str_TXT_820C0000_B_ - 30916, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11008, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E580, 0x8324E580) { ctx.r3.u64 = n_sub_8324E580(ctx, base); }

uint64_t n_sub_8324E5C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349835C_G_ = int32_t(0x8349835C);
	if (!UseLiftedCode(143, 0x8324E5C0)) { __imp__sub_8324E5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E5C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349835C_G_, (int64_t)str_TXT_820B0000_B_ + 16156, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11024, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E5C0, 0x8324E5C0) { ctx.r3.u64 = n_sub_8324E5C0(ctx, base); }

uint64_t n_sub_8324E600(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498360_G_ = int32_t(0x83498360);
	if (!UseLiftedCode(143, 0x8324E600)) { __imp__sub_8324E600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E600);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498360_G_, (int64_t)str_TXT_820C0000_B_ - 30904, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11040, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E600, 0x8324E600) { ctx.r3.u64 = n_sub_8324E600(ctx, base); }

uint64_t n_sub_8324E678(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498368_G_ = int32_t(0x83498368);
	if (!UseLiftedCode(143, 0x8324E678)) { __imp__sub_8324E678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E678);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498368_G_, (int64_t)str_TXT_820C0000_B_ - 30868, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11056, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E678, 0x8324E678) { ctx.r3.u64 = n_sub_8324E678(ctx, base); }

uint64_t n_sub_8324E6B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349836C_G_ = int32_t(0x8349836C);
	if (!UseLiftedCode(143, 0x8324E6B8)) { __imp__sub_8324E6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E6B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349836C_G_, (int64_t)str_TXT_820C0000_B_ - 28056, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E6B8, 0x8324E6B8) { ctx.r3.u64 = n_sub_8324E6B8(ctx, base); }

uint64_t n_sub_8324E6F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498370_G_ = int32_t(0x83498370);
	if (!UseLiftedCode(143, 0x8324E6F8)) { __imp__sub_8324E6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E6F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498370_G_, (int64_t)str_TXT_820C0000_B_ - 28028, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11088, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E6F8, 0x8324E6F8) { ctx.r3.u64 = n_sub_8324E6F8(ctx, base); }

uint64_t n_sub_8324E770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498378_G_ = int32_t(0x83498378);
	if (!UseLiftedCode(143, 0x8324E770)) { __imp__sub_8324E770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498378_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11104, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E770, 0x8324E770) { ctx.r3.u64 = n_sub_8324E770(ctx, base); }

uint64_t n_sub_8324E7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349837C_G_ = int32_t(0x8349837C);
	if (!UseLiftedCode(143, 0x8324E7B0)) { __imp__sub_8324E7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349837C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11120, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E7B0, 0x8324E7B0) { ctx.r3.u64 = n_sub_8324E7B0(ctx, base); }

uint64_t n_sub_8324E7F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498380_G_ = int32_t(0x83498380);
	if (!UseLiftedCode(143, 0x8324E7F0)) { __imp__sub_8324E7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E7F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498380_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11136, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E7F0, 0x8324E7F0) { ctx.r3.u64 = n_sub_8324E7F0(ctx, base); }

uint64_t n_sub_8324E9F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983A4_G_ = int32_t(0x834983A4);
	if (!UseLiftedCode(143, 0x8324E9F0)) { __imp__sub_8324E9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E9F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983A4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11152, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E9F0, 0x8324E9F0) { ctx.r3.u64 = n_sub_8324E9F0(ctx, base); }

uint64_t n_sub_8324EA30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983A8_G_ = int32_t(0x834983A8);
	if (!UseLiftedCode(143, 0x8324EA30)) { __imp__sub_8324EA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EA30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983A8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11168, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EA30, 0x8324EA30) { ctx.r3.u64 = n_sub_8324EA30(ctx, base); }

uint64_t n_sub_8324EA70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983AC_G_ = int32_t(0x834983AC);
	if (!UseLiftedCode(143, 0x8324EA70)) { __imp__sub_8324EA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EA70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983AC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11184, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EA70, 0x8324EA70) { ctx.r3.u64 = n_sub_8324EA70(ctx, base); }

uint64_t n_sub_8324EAB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983B0_G_ = int32_t(0x834983B0);
	if (!UseLiftedCode(143, 0x8324EAB0)) { __imp__sub_8324EAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EAB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983B0_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EAB0, 0x8324EAB0) { ctx.r3.u64 = n_sub_8324EAB0(ctx, base); }

uint64_t n_sub_8324ECE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983D8_G_ = int32_t(0x834983D8);
	if (!UseLiftedCode(143, 0x8324ECE8)) { __imp__sub_8324ECE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ECE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983D8_G_, (int64_t)str_TXT_820C0000_B_ - 27084, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ECE8, 0x8324ECE8) { ctx.r3.u64 = n_sub_8324ECE8(ctx, base); }

uint64_t n_sub_8324ED28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983DC_G_ = int32_t(0x834983DC);
	if (!UseLiftedCode(143, 0x8324ED28)) { __imp__sub_8324ED28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ED28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983DC_G_, (int64_t)str_TXT_820C0000_B_ - 27056, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11232, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ED28, 0x8324ED28) { ctx.r3.u64 = n_sub_8324ED28(ctx, base); }

uint64_t n_sub_8324ED68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983E0_G_ = int32_t(0x834983E0);
	if (!UseLiftedCode(143, 0x8324ED68)) { __imp__sub_8324ED68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ED68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E0_G_, (int64_t)str_TXT_820C0000_B_ - 27028, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11248, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324ED68, 0x8324ED68) { ctx.r3.u64 = n_sub_8324ED68(ctx, base); }

uint64_t n_sub_8324EDA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983E4_G_ = int32_t(0x834983E4);
	if (!UseLiftedCode(143, 0x8324EDA8)) { __imp__sub_8324EDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EDA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E4_G_, (int64_t)str_TXT_820C0000_B_ - 27000, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11264, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EDA8, 0x8324EDA8) { ctx.r3.u64 = n_sub_8324EDA8(ctx, base); }

uint64_t n_sub_8324EDE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983E8_G_ = int32_t(0x834983E8);
	if (!UseLiftedCode(143, 0x8324EDE8)) { __imp__sub_8324EDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EDE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E8_G_, (int64_t)str_TXT_820C0000_B_ - 26972, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11280, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EDE8, 0x8324EDE8) { ctx.r3.u64 = n_sub_8324EDE8(ctx, base); }

uint64_t n_sub_8324EE28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983EC_G_ = int32_t(0x834983EC);
	if (!UseLiftedCode(143, 0x8324EE28)) { __imp__sub_8324EE28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EE28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983EC_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11296, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EE28, 0x8324EE28) { ctx.r3.u64 = n_sub_8324EE28(ctx, base); }

uint64_t n_sub_8324EE68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983F0_G_ = int32_t(0x834983F0);
	if (!UseLiftedCode(143, 0x8324EE68)) { __imp__sub_8324EE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EE68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F0_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EE68, 0x8324EE68) { ctx.r3.u64 = n_sub_8324EE68(ctx, base); }

uint64_t n_sub_8324EEA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983F4_G_ = int32_t(0x834983F4);
	if (!UseLiftedCode(143, 0x8324EEA8)) { __imp__sub_8324EEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EEA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F4_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11328, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EEA8, 0x8324EEA8) { ctx.r3.u64 = n_sub_8324EEA8(ctx, base); }

uint64_t n_sub_8324EEE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834983F8_G_ = int32_t(0x834983F8);
	if (!UseLiftedCode(143, 0x8324EEE8)) { __imp__sub_8324EEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EEE8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F8_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324EEE8, 0x8324EEE8) { ctx.r3.u64 = n_sub_8324EEE8(ctx, base); }

uint64_t n_sub_8324F6B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984D0_G_ = int32_t(0x834984D0);
	if (!UseLiftedCode(143, 0x8324F6B0)) { __imp__sub_8324F6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F6B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D0_G_, (int64_t)g_820A0000 + 1148, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F6B0, 0x8324F6B0) { ctx.r3.u64 = n_sub_8324F6B0(ctx, base); }

uint64_t n_sub_8324F6F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984D4_G_ = int32_t(0x834984D4);
	if (!UseLiftedCode(143, 0x8324F6F0)) { __imp__sub_8324F6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F6F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F6F0, 0x8324F6F0) { ctx.r3.u64 = n_sub_8324F6F0(ctx, base); }

uint64_t n_sub_8324F730(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984D8_G_ = int32_t(0x834984D8);
	if (!UseLiftedCode(143, 0x8324F730)) { __imp__sub_8324F730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F730, 0x8324F730) { ctx.r3.u64 = n_sub_8324F730(ctx, base); }

uint64_t n_sub_8324F770(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984DC_G_ = int32_t(0x834984DC);
	if (!UseLiftedCode(143, 0x8324F770)) { __imp__sub_8324F770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984DC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F770, 0x8324F770) { ctx.r3.u64 = n_sub_8324F770(ctx, base); }

uint64_t n_sub_8324F7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984E0_G_ = int32_t(0x834984E0);
	if (!UseLiftedCode(143, 0x8324F7B0)) { __imp__sub_8324F7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E0_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F7B0, 0x8324F7B0) { ctx.r3.u64 = n_sub_8324F7B0(ctx, base); }

uint64_t n_sub_8324F7F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984E4_G_ = int32_t(0x834984E4);
	if (!UseLiftedCode(143, 0x8324F7F0)) { __imp__sub_8324F7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F7F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E4_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F7F0, 0x8324F7F0) { ctx.r3.u64 = n_sub_8324F7F0(ctx, base); }

uint64_t n_sub_8324F830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834984E8_G_ = int32_t(0x834984E8);
	if (!UseLiftedCode(143, 0x8324F830)) { __imp__sub_8324F830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E8_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F830, 0x8324F830) { ctx.r3.u64 = n_sub_8324F830(ctx, base); }

uint64_t n_sub_8324F8E0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324F8E0)) { ctx.r8.u64 = arg1; __imp__sub_8324F8E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F8E0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11840, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324F8E0, 0x8324F8E0) { ctx.r3.u64 = n_sub_8324F8E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324F8F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324F8F0)) { ctx.r8.u64 = arg1; __imp__sub_8324F8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F8F0);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11912, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324F8F0, 0x8324F8F0) { ctx.r3.u64 = n_sub_8324F8F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324F900(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	if (!UseLiftedCode(143, 0x8324F900)) { ctx.r8.u64 = arg1; __imp__sub_8324F900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F900);
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 11928, arg1);
	return result;
}
PROMOTED_ENTRY(143, sub_8324F900, 0x8324F900) { ctx.r3.u64 = n_sub_8324F900(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324F910(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498548_G_ = int32_t(0x83498548);
	if (!UseLiftedCode(143, 0x8324F910)) { __imp__sub_8324F910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F910);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498548_G_, (int64_t)g_82000000 + 2692, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F910, 0x8324F910) { ctx.r3.u64 = n_sub_8324F910(ctx, base); }

uint64_t n_sub_8324F950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349854C_G_ = int32_t(0x8349854C);
	if (!UseLiftedCode(143, 0x8324F950)) { __imp__sub_8324F950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349854C_G_, (int64_t)g_82000000 + 3600, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12064, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F950, 0x8324F950) { ctx.r3.u64 = n_sub_8324F950(ctx, base); }

uint64_t n_sub_8324F990(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498550_G_ = int32_t(0x83498550);
	if (!UseLiftedCode(143, 0x8324F990)) { __imp__sub_8324F990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F990);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498550_G_, (int64_t)str_TXT_820C0000_B_ - 15392, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12080, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F990, 0x8324F990) { ctx.r3.u64 = n_sub_8324F990(ctx, base); }

uint64_t n_sub_8324F9D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498554_G_ = int32_t(0x83498554);
	if (!UseLiftedCode(143, 0x8324F9D0)) { __imp__sub_8324F9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F9D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498554_G_, (int64_t)g_82000000 + 3664, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12096, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324F9D0, 0x8324F9D0) { ctx.r3.u64 = n_sub_8324F9D0(ctx, base); }

uint64_t n_sub_8324FA78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498568_G_ = int32_t(0x83498568);
	if (!UseLiftedCode(143, 0x8324FA78)) { __imp__sub_8324FA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498568_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FA78, 0x8324FA78) { ctx.r3.u64 = n_sub_8324FA78(ctx, base); }

uint64_t n_sub_8324FAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349856C_G_ = int32_t(0x8349856C);
	if (!UseLiftedCode(143, 0x8324FAB8)) { __imp__sub_8324FAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349856C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FAB8, 0x8324FAB8) { ctx.r3.u64 = n_sub_8324FAB8(ctx, base); }

uint64_t n_sub_8324FAF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498570_G_ = int32_t(0x83498570);
	if (!UseLiftedCode(143, 0x8324FAF8)) { __imp__sub_8324FAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FAF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498570_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FAF8, 0x8324FAF8) { ctx.r3.u64 = n_sub_8324FAF8(ctx, base); }

uint64_t n_sub_8324FB38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498574_G_ = int32_t(0x83498574);
	if (!UseLiftedCode(143, 0x8324FB38)) { __imp__sub_8324FB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FB38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498574_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FB38, 0x8324FB38) { ctx.r3.u64 = n_sub_8324FB38(ctx, base); }

uint64_t n_sub_8324FB78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498578_G_ = int32_t(0x83498578);
	if (!UseLiftedCode(143, 0x8324FB78)) { __imp__sub_8324FB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FB78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498578_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FB78, 0x8324FB78) { ctx.r3.u64 = n_sub_8324FB78(ctx, base); }

uint64_t n_sub_8324FBB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349857C_G_ = int32_t(0x8349857C);
	if (!UseLiftedCode(143, 0x8324FBB8)) { __imp__sub_8324FBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FBB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349857C_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FBB8, 0x8324FBB8) { ctx.r3.u64 = n_sub_8324FBB8(ctx, base); }

uint64_t n_sub_8324FBF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498580_G_ = int32_t(0x83498580);
	if (!UseLiftedCode(143, 0x8324FBF8)) { __imp__sub_8324FBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FBF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498580_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FBF8, 0x8324FBF8) { ctx.r3.u64 = n_sub_8324FBF8(ctx, base); }

uint64_t n_sub_8324FC38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498584_G_ = int32_t(0x83498584);
	if (!UseLiftedCode(143, 0x8324FC38)) { __imp__sub_8324FC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FC38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498584_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FC38, 0x8324FC38) { ctx.r3.u64 = n_sub_8324FC38(ctx, base); }

uint64_t n_sub_8324FC78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498588_G_ = int32_t(0x83498588);
	if (!UseLiftedCode(143, 0x8324FC78)) { __imp__sub_8324FC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FC78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498588_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FC78, 0x8324FC78) { ctx.r3.u64 = n_sub_8324FC78(ctx, base); }

uint64_t n_sub_8324FD70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_83498598_G_ = int32_t(0x83498598);
	if (!UseLiftedCode(143, 0x8324FD70)) { __imp__sub_8324FD70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FD70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498598_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FD70, 0x8324FD70) { ctx.r3.u64 = n_sub_8324FD70(ctx, base); }

uint64_t n_sub_8324FDB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_8349859C_G_ = int32_t(0x8349859C);
	if (!UseLiftedCode(143, 0x8324FDB0)) { __imp__sub_8324FDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FDB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_8349859C_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12376, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FDB0, 0x8324FDB0) { ctx.r3.u64 = n_sub_8324FDB0(ctx, base); }

uint64_t n_sub_8324FDF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985A0_G_ = int32_t(0x834985A0);
	if (!UseLiftedCode(143, 0x8324FDF0)) { __imp__sub_8324FDF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FDF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12392, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FDF0, 0x8324FDF0) { ctx.r3.u64 = n_sub_8324FDF0(ctx, base); }

uint64_t n_sub_8324FE30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985A4_G_ = int32_t(0x834985A4);
	if (!UseLiftedCode(143, 0x8324FE30)) { __imp__sub_8324FE30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FE30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A4_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FE30, 0x8324FE30) { ctx.r3.u64 = n_sub_8324FE30(ctx, base); }

uint64_t n_sub_8324FE70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985A8_G_ = int32_t(0x834985A8);
	if (!UseLiftedCode(143, 0x8324FE70)) { __imp__sub_8324FE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FE70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A8_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12424, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FE70, 0x8324FE70) { ctx.r3.u64 = n_sub_8324FE70(ctx, base); }

uint64_t n_sub_8324FEB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985AC_G_ = int32_t(0x834985AC);
	if (!UseLiftedCode(143, 0x8324FEB0)) { __imp__sub_8324FEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FEB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985AC_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12440, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FEB0, 0x8324FEB0) { ctx.r3.u64 = n_sub_8324FEB0(ctx, base); }

uint64_t n_sub_8324FEF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985B0_G_ = int32_t(0x834985B0);
	if (!UseLiftedCode(143, 0x8324FEF0)) { __imp__sub_8324FEF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FEF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B0_G_, (int64_t)str_TXT_820C0000_B_ - 12168, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FEF0, 0x8324FEF0) { ctx.r3.u64 = n_sub_8324FEF0(ctx, base); }

uint64_t n_sub_8324FF30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985B4_G_ = int32_t(0x834985B4);
	if (!UseLiftedCode(143, 0x8324FF30)) { __imp__sub_8324FF30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FF30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B4_G_, (int64_t)str_TXT_820C0000_B_ - 12156, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12472, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FF30, 0x8324FF30) { ctx.r3.u64 = n_sub_8324FF30(ctx, base); }

uint64_t n_sub_8324FF70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985B8_G_ = int32_t(0x834985B8);
	if (!UseLiftedCode(143, 0x8324FF70)) { __imp__sub_8324FF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FF70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B8_G_, (int64_t)g_820A0000 + 6400, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12488, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FF70, 0x8324FF70) { ctx.r3.u64 = n_sub_8324FF70(ctx, base); }

uint64_t n_sub_8324FFB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985BC_G_ = int32_t(0x834985BC);
	if (!UseLiftedCode(143, 0x8324FFB0)) { __imp__sub_8324FFB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FFB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985BC_G_, (int64_t)g_820A0000 + 6408, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FFB0, 0x8324FFB0) { ctx.r3.u64 = n_sub_8324FFB0(ctx, base); }

uint64_t n_sub_8324FFF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t TXT_834985C0_G_ = int32_t(0x834985C0);
	if (!UseLiftedCode(143, 0x8324FFF0)) { __imp__sub_8324FFF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FFF0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C0_G_, (int64_t)g_820A0000 + 6428, -1);
	ctx.r9.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832A0000 + 12520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324FFF0, 0x8324FFF0) { ctx.r3.u64 = n_sub_8324FFF0(ctx, base); }
