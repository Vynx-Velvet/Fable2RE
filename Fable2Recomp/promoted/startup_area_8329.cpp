// Start-up initialisers of global objects (they register property and definition names) at
// 0x8329xxxx, as readable C++.
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

uint64_t n_sub_83290198(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334AF8_G_ = int32_t(0x83334AF8);
	if (!UseLiftedCode(145, 0x83290198)) { __imp__sub_83290198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290198);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334AF8_G_, (int64_t)g_820A0000 + 25268, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 - 720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290198, 0x83290198) { ctx.r3.u64 = n_sub_83290198(ctx, base); }

uint64_t n_sub_83290488(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D38_G_ = int32_t(0x83334D38);
	if (!UseLiftedCode(145, 0x83290488)) { __imp__sub_83290488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290488);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D38_G_, (int64_t)g_82010000 - 19488, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 64, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290488, 0x83290488) { ctx.r3.u64 = n_sub_83290488(ctx, base); }

uint64_t n_sub_832904C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D3C_G_ = int32_t(0x83334D3C);
	if (!UseLiftedCode(145, 0x832904C8)) { __imp__sub_832904C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832904C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D3C_G_, (int64_t)g_82010000 - 19472, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 80, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832904C8, 0x832904C8) { ctx.r3.u64 = n_sub_832904C8(ctx, base); }

uint64_t n_sub_83290508(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D40_G_ = int32_t(0x83334D40);
	if (!UseLiftedCode(145, 0x83290508)) { __imp__sub_83290508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290508);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D40_G_, (int64_t)g_82010000 - 19140, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 96, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290508, 0x83290508) { ctx.r3.u64 = n_sub_83290508(ctx, base); }

uint64_t n_sub_83290548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D44_G_ = int32_t(0x83334D44);
	if (!UseLiftedCode(145, 0x83290548)) { __imp__sub_83290548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D44_G_, (int64_t)g_82010000 - 19128, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 112, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290548, 0x83290548) { ctx.r3.u64 = n_sub_83290548(ctx, base); }

uint64_t n_sub_83290588(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D48_G_ = int32_t(0x83334D48);
	if (!UseLiftedCode(145, 0x83290588)) { __imp__sub_83290588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D48_G_, (int64_t)g_82010000 - 18560, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 128, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290588, 0x83290588) { ctx.r3.u64 = n_sub_83290588(ctx, base); }

uint64_t n_sub_832905C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D4C_G_ = int32_t(0x83334D4C);
	if (!UseLiftedCode(145, 0x832905C8)) { __imp__sub_832905C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832905C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D4C_G_, (int64_t)g_82010000 - 18544, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 144, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832905C8, 0x832905C8) { ctx.r3.u64 = n_sub_832905C8(ctx, base); }

uint64_t n_sub_83290608(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D50_G_ = int32_t(0x83334D50);
	if (!UseLiftedCode(145, 0x83290608)) { __imp__sub_83290608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290608);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D50_G_, (int64_t)g_82010000 - 18532, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 160, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290608, 0x83290608) { ctx.r3.u64 = n_sub_83290608(ctx, base); }

uint64_t n_sub_83290648(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D54_G_ = int32_t(0x83334D54);
	if (!UseLiftedCode(145, 0x83290648)) { __imp__sub_83290648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290648);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D54_G_, (int64_t)g_82010000 - 18304, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290648, 0x83290648) { ctx.r3.u64 = n_sub_83290648(ctx, base); }

uint64_t n_sub_83290688(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D58_G_ = int32_t(0x83334D58);
	if (!UseLiftedCode(145, 0x83290688)) { __imp__sub_83290688(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290688);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D58_G_, (int64_t)g_82010000 - 18280, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 192, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290688, 0x83290688) { ctx.r3.u64 = n_sub_83290688(ctx, base); }

uint64_t n_sub_832906C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D5C_G_ = int32_t(0x83334D5C);
	if (!UseLiftedCode(145, 0x832906C8)) { __imp__sub_832906C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832906C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D5C_G_, (int64_t)g_82010000 - 18264, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 208, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832906C8, 0x832906C8) { ctx.r3.u64 = n_sub_832906C8(ctx, base); }

uint64_t n_sub_83290708(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D60_G_ = int32_t(0x83334D60);
	if (!UseLiftedCode(145, 0x83290708)) { __imp__sub_83290708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D60_G_, (int64_t)g_82010000 - 17944, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 224, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290708, 0x83290708) { ctx.r3.u64 = n_sub_83290708(ctx, base); }

uint64_t n_sub_83290748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D64_G_ = int32_t(0x83334D64);
	if (!UseLiftedCode(145, 0x83290748)) { __imp__sub_83290748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D64_G_, (int64_t)g_82010000 - 17920, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 240, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290748, 0x83290748) { ctx.r3.u64 = n_sub_83290748(ctx, base); }

uint64_t n_sub_83290788(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D68_G_ = int32_t(0x83334D68);
	if (!UseLiftedCode(145, 0x83290788)) { __imp__sub_83290788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290788);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D68_G_, (int64_t)g_82010000 - 17904, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 256, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290788, 0x83290788) { ctx.r3.u64 = n_sub_83290788(ctx, base); }

uint64_t n_sub_832907C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D6C_G_ = int32_t(0x83334D6C);
	if (!UseLiftedCode(145, 0x832907C8)) { __imp__sub_832907C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832907C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D6C_G_, (int64_t)g_82010000 - 17828, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 272, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832907C8, 0x832907C8) { ctx.r3.u64 = n_sub_832907C8(ctx, base); }

uint64_t n_sub_83290808(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D70_G_ = int32_t(0x83334D70);
	if (!UseLiftedCode(145, 0x83290808)) { __imp__sub_83290808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D70_G_, (int64_t)g_82010000 - 17804, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290808, 0x83290808) { ctx.r3.u64 = n_sub_83290808(ctx, base); }

uint64_t n_sub_83290848(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D74_G_ = int32_t(0x83334D74);
	if (!UseLiftedCode(145, 0x83290848)) { __imp__sub_83290848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290848);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D74_G_, (int64_t)g_82010000 - 17784, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 304, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290848, 0x83290848) { ctx.r3.u64 = n_sub_83290848(ctx, base); }

uint64_t n_sub_83290888(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D78_G_ = int32_t(0x83334D78);
	if (!UseLiftedCode(145, 0x83290888)) { __imp__sub_83290888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290888);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D78_G_, (int64_t)g_82010000 - 17588, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 320, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290888, 0x83290888) { ctx.r3.u64 = n_sub_83290888(ctx, base); }

uint64_t n_sub_832908C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D7C_G_ = int32_t(0x83334D7C);
	if (!UseLiftedCode(145, 0x832908C8)) { __imp__sub_832908C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832908C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D7C_G_, (int64_t)g_82010000 - 17572, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832908C8, 0x832908C8) { ctx.r3.u64 = n_sub_832908C8(ctx, base); }

uint64_t n_sub_83290908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D80_G_ = int32_t(0x83334D80);
	if (!UseLiftedCode(145, 0x83290908)) { __imp__sub_83290908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D80_G_, (int64_t)g_82010000 - 17560, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 352, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290908, 0x83290908) { ctx.r3.u64 = n_sub_83290908(ctx, base); }

uint64_t n_sub_83290948(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D84_G_ = int32_t(0x83334D84);
	if (!UseLiftedCode(145, 0x83290948)) { __imp__sub_83290948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D84_G_, (int64_t)g_82010000 - 17380, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 368, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290948, 0x83290948) { ctx.r3.u64 = n_sub_83290948(ctx, base); }

uint64_t n_sub_83290988(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D88_G_ = int32_t(0x83334D88);
	if (!UseLiftedCode(145, 0x83290988)) { __imp__sub_83290988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290988);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D88_G_, (int64_t)g_82010000 - 17360, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290988, 0x83290988) { ctx.r3.u64 = n_sub_83290988(ctx, base); }

uint64_t n_sub_832909C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D8C_G_ = int32_t(0x83334D8C);
	if (!UseLiftedCode(145, 0x832909C8)) { __imp__sub_832909C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832909C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D8C_G_, (int64_t)g_82010000 - 17344, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 400, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832909C8, 0x832909C8) { ctx.r3.u64 = n_sub_832909C8(ctx, base); }

uint64_t n_sub_83290A08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D90_G_ = int32_t(0x83334D90);
	if (!UseLiftedCode(145, 0x83290A08)) { __imp__sub_83290A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D90_G_, (int64_t)g_82010000 - 17076, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 416, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290A08, 0x83290A08) { ctx.r3.u64 = n_sub_83290A08(ctx, base); }

uint64_t n_sub_83290A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D94_G_ = int32_t(0x83334D94);
	if (!UseLiftedCode(145, 0x83290A48)) { __imp__sub_83290A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290A48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D94_G_, (int64_t)g_82010000 - 17052, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290A48, 0x83290A48) { ctx.r3.u64 = n_sub_83290A48(ctx, base); }

uint64_t n_sub_83290A88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D98_G_ = int32_t(0x83334D98);
	if (!UseLiftedCode(145, 0x83290A88)) { __imp__sub_83290A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290A88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D98_G_, (int64_t)g_82010000 - 17052, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 448, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290A88, 0x83290A88) { ctx.r3.u64 = n_sub_83290A88(ctx, base); }

uint64_t n_sub_83290AC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334D9C_G_ = int32_t(0x83334D9C);
	if (!UseLiftedCode(145, 0x83290AC8)) { __imp__sub_83290AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290AC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334D9C_G_, (int64_t)g_82010000 - 16692, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 464, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290AC8, 0x83290AC8) { ctx.r3.u64 = n_sub_83290AC8(ctx, base); }

uint64_t n_sub_83290B08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DA0_G_ = int32_t(0x83334DA0);
	if (!UseLiftedCode(145, 0x83290B08)) { __imp__sub_83290B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290B08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DA0_G_, (int64_t)g_82010000 - 16676, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290B08, 0x83290B08) { ctx.r3.u64 = n_sub_83290B08(ctx, base); }

uint64_t n_sub_83290B48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DA4_G_ = int32_t(0x83334DA4);
	if (!UseLiftedCode(145, 0x83290B48)) { __imp__sub_83290B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290B48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DA4_G_, (int64_t)g_82010000 - 16260, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290B48, 0x83290B48) { ctx.r3.u64 = n_sub_83290B48(ctx, base); }

uint64_t n_sub_83290B88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DA8_G_ = int32_t(0x83334DA8);
	if (!UseLiftedCode(145, 0x83290B88)) { __imp__sub_83290B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290B88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DA8_G_, (int64_t)g_82010000 - 16236, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 512, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290B88, 0x83290B88) { ctx.r3.u64 = n_sub_83290B88(ctx, base); }

uint64_t n_sub_83290BC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DAC_G_ = int32_t(0x83334DAC);
	if (!UseLiftedCode(145, 0x83290BC8)) { __imp__sub_83290BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290BC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DAC_G_, (int64_t)g_82010000 - 16220, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290BC8, 0x83290BC8) { ctx.r3.u64 = n_sub_83290BC8(ctx, base); }

uint64_t n_sub_83290C08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DB0_G_ = int32_t(0x83334DB0);
	if (!UseLiftedCode(145, 0x83290C08)) { __imp__sub_83290C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290C08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DB0_G_, (int64_t)g_82010000 - 15996, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290C08, 0x83290C08) { ctx.r3.u64 = n_sub_83290C08(ctx, base); }

uint64_t n_sub_83290C48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DB4_G_ = int32_t(0x83334DB4);
	if (!UseLiftedCode(145, 0x83290C48)) { __imp__sub_83290C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290C48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DB4_G_, (int64_t)g_82010000 - 15980, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 560, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290C48, 0x83290C48) { ctx.r3.u64 = n_sub_83290C48(ctx, base); }

uint64_t n_sub_83290C88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DB8_G_ = int32_t(0x83334DB8);
	if (!UseLiftedCode(145, 0x83290C88)) { __imp__sub_83290C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290C88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DB8_G_, (int64_t)g_82010000 - 15960, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290C88, 0x83290C88) { ctx.r3.u64 = n_sub_83290C88(ctx, base); }

uint64_t n_sub_83290CC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DBC_G_ = int32_t(0x83334DBC);
	if (!UseLiftedCode(145, 0x83290CC8)) { __imp__sub_83290CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290CC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DBC_G_, (int64_t)g_82010000 - 15792, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 592, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290CC8, 0x83290CC8) { ctx.r3.u64 = n_sub_83290CC8(ctx, base); }

uint64_t n_sub_83290D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DC0_G_ = int32_t(0x83334DC0);
	if (!UseLiftedCode(145, 0x83290D08)) { __imp__sub_83290D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290D08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DC0_G_, (int64_t)g_82010000 - 15780, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 608, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290D08, 0x83290D08) { ctx.r3.u64 = n_sub_83290D08(ctx, base); }

uint64_t n_sub_83290D48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DC4_G_ = int32_t(0x83334DC4);
	if (!UseLiftedCode(145, 0x83290D48)) { __imp__sub_83290D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290D48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DC4_G_, (int64_t)g_82010000 - 15760, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290D48, 0x83290D48) { ctx.r3.u64 = n_sub_83290D48(ctx, base); }

uint64_t n_sub_83290D88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DD4_G_ = int32_t(0x83334DD4);
	if (!UseLiftedCode(145, 0x83290D88)) { __imp__sub_83290D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290D88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DD4_G_, (int64_t)g_82010000 - 15584, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 640, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290D88, 0x83290D88) { ctx.r3.u64 = n_sub_83290D88(ctx, base); }

uint64_t n_sub_83290DC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DD8_G_ = int32_t(0x83334DD8);
	if (!UseLiftedCode(145, 0x83290DC8)) { __imp__sub_83290DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290DC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_820F0000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DD8_G_, (int64_t)g_820F0000 - 8256, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 656, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290DC8, 0x83290DC8) { ctx.r3.u64 = n_sub_83290DC8(ctx, base); }

uint64_t n_sub_83290E08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DDC_G_ = int32_t(0x83334DDC);
	if (!UseLiftedCode(145, 0x83290E08)) { __imp__sub_83290E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290E08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DDC_G_, (int64_t)g_82010000 - 15440, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290E08, 0x83290E08) { ctx.r3.u64 = n_sub_83290E08(ctx, base); }

uint64_t n_sub_83290E48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DE0_G_ = int32_t(0x83334DE0);
	if (!UseLiftedCode(145, 0x83290E48)) { __imp__sub_83290E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290E48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DE0_G_, (int64_t)g_82010000 - 15432, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 688, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290E48, 0x83290E48) { ctx.r3.u64 = n_sub_83290E48(ctx, base); }

uint64_t n_sub_83290E88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DE4_G_ = int32_t(0x83334DE4);
	if (!UseLiftedCode(145, 0x83290E88)) { __imp__sub_83290E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290E88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DE4_G_, (int64_t)g_82010000 - 15420, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 704, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290E88, 0x83290E88) { ctx.r3.u64 = n_sub_83290E88(ctx, base); }

uint64_t n_sub_83290EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DE8_G_ = int32_t(0x83334DE8);
	if (!UseLiftedCode(145, 0x83290EC8)) { __imp__sub_83290EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290EC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DE8_G_, (int64_t)g_82010000 - 15028, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290EC8, 0x83290EC8) { ctx.r3.u64 = n_sub_83290EC8(ctx, base); }

uint64_t n_sub_83290F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DEC_G_ = int32_t(0x83334DEC);
	if (!UseLiftedCode(145, 0x83290F08)) { __imp__sub_83290F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290F08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DEC_G_, (int64_t)g_82010000 - 15004, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 736, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290F08, 0x83290F08) { ctx.r3.u64 = n_sub_83290F08(ctx, base); }

uint64_t n_sub_83290F48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DF0_G_ = int32_t(0x83334DF0);
	if (!UseLiftedCode(145, 0x83290F48)) { __imp__sub_83290F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290F48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DF0_G_, (int64_t)g_82010000 - 14752, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 752, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290F48, 0x83290F48) { ctx.r3.u64 = n_sub_83290F48(ctx, base); }

uint64_t n_sub_83290F88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DF4_G_ = int32_t(0x83334DF4);
	if (!UseLiftedCode(145, 0x83290F88)) { __imp__sub_83290F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290F88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DF4_G_, (int64_t)g_82010000 - 14736, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290F88, 0x83290F88) { ctx.r3.u64 = n_sub_83290F88(ctx, base); }

uint64_t n_sub_83290FC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DF8_G_ = int32_t(0x83334DF8);
	if (!UseLiftedCode(145, 0x83290FC8)) { __imp__sub_83290FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83290FC8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DF8_G_, (int64_t)g_82010000 - 14404, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 784, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83290FC8, 0x83290FC8) { ctx.r3.u64 = n_sub_83290FC8(ctx, base); }

uint64_t n_sub_83291008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334DFC_G_ = int32_t(0x83334DFC);
	if (!UseLiftedCode(145, 0x83291008)) { __imp__sub_83291008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291008);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334DFC_G_, (int64_t)g_82010000 - 14384, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 800, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291008, 0x83291008) { ctx.r3.u64 = n_sub_83291008(ctx, base); }

uint64_t n_sub_83291048(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E00_G_ = int32_t(0x83334E00);
	if (!UseLiftedCode(145, 0x83291048)) { __imp__sub_83291048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291048);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E00_G_, (int64_t)g_82010000 - 14148, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291048, 0x83291048) { ctx.r3.u64 = n_sub_83291048(ctx, base); }

uint64_t n_sub_83291088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E04_G_ = int32_t(0x83334E04);
	if (!UseLiftedCode(145, 0x83291088)) { __imp__sub_83291088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E04_G_, (int64_t)g_82010000 - 14132, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 832, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291088, 0x83291088) { ctx.r3.u64 = n_sub_83291088(ctx, base); }

uint64_t n_sub_832910C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E08_G_ = int32_t(0x83334E08);
	if (!UseLiftedCode(145, 0x832910C8)) { __imp__sub_832910C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832910C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E08_G_, (int64_t)g_82010000 - 14088, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 848, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_832910C8, 0x832910C8) { ctx.r3.u64 = n_sub_832910C8(ctx, base); }

uint64_t n_sub_83291108(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E18_G_ = int32_t(0x83334E18);
	if (!UseLiftedCode(145, 0x83291108)) { __imp__sub_83291108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291108);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E18_G_, (int64_t)g_82010000 - 13900, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291108, 0x83291108) { ctx.r3.u64 = n_sub_83291108(ctx, base); }

uint64_t n_sub_83291148(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E1C_G_ = int32_t(0x83334E1C);
	if (!UseLiftedCode(145, 0x83291148)) { __imp__sub_83291148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291148);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E1C_G_, (int64_t)g_82010000 - 22240, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 880, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291148, 0x83291148) { ctx.r3.u64 = n_sub_83291148(ctx, base); }

uint64_t n_sub_83291210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E48_G_ = int32_t(0x83334E48);
	if (!UseLiftedCode(145, 0x83291210)) { __imp__sub_83291210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291210);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E48_G_, (int64_t)g_82010000 - 13764, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 912, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291210, 0x83291210) { ctx.r3.u64 = n_sub_83291210(ctx, base); }

uint64_t n_sub_83291250(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82010000 = int32_t(0x82010000);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t TXT_83334E4C_G_ = int32_t(0x83334E4C);
	if (!UseLiftedCode(145, 0x83291250)) { __imp__sub_83291250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291250);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	ctx.r11.s64 = g_82010000;
	CCharString_ConstructFromCStr(ctx, base, TXT_83334E4C_G_, (int64_t)g_82010000 - 13752, -1);
	ctx.r9.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 928, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_83291250, 0x83291250) { ctx.r3.u64 = n_sub_83291250(ctx, base); }

uint64_t n_sub_83291B90(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83291B90)) { ctx.r8.u64 = arg1; __imp__sub_83291B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291B90);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 1704, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83291B90, 0x83291B90) { ctx.r3.u64 = n_sub_83291B90(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83291BA0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83291BA0)) { ctx.r8.u64 = arg1; __imp__sub_83291BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291BA0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 1616, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83291BA0, 0x83291BA0) { ctx.r3.u64 = n_sub_83291BA0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83291BB0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83291BB0)) { ctx.r8.u64 = arg1; __imp__sub_83291BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291BB0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 1528, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83291BB0, 0x83291BB0) { ctx.r3.u64 = n_sub_83291BB0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83291BC0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83291BC0)) { ctx.r8.u64 = arg1; __imp__sub_83291BC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291BC0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 1824, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83291BC0, 0x83291BC0) { ctx.r3.u64 = n_sub_83291BC0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83291C40(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83291C40)) { ctx.r8.u64 = arg1; __imp__sub_83291C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83291C40);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 1936, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83291C40, 0x83291C40) { ctx.r3.u64 = n_sub_83291C40(ctx, base, ctx.r8.u64); }

// sub_83292230  [108 bytes]
uint64_t n_sub_83292230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202473C = int32_t(0x8202473C);
	constexpr int32_t str_TXT_8202476C_B_ = int32_t(0x8202476C);
	constexpr int32_t g_8333749C = int32_t(0x8333749C);
	if (!UseLiftedCode(145, 0x83292230)) { __imp__sub_83292230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83292230);
	// Stores the stack arguments of n_sub_82D4F620 (an address at +84, 2 at +92, zeros at +100..+116), then
	// calls it with the global object, a string constant, 0 and a size.
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202473C;
	uint64_t object = g_8333749C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202476C_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202476C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83292230, 0x83292230) { ctx.r3.u64 = n_sub_83292230(ctx, base); }

uint64_t n_sub_832923C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202500C = int32_t(0x8202500C);
	constexpr int32_t str_TXT_82025054_B_ = int32_t(0x82025054);
	constexpr int32_t g_83337538 = int32_t(0x83337538);
	if (!UseLiftedCode(145, 0x832923C0)) { __imp__sub_832923C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832923C0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202500C;
	uint64_t object = g_83337538;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82025054_B_, 0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82025054_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832923C0, 0x832923C0) { ctx.r3.u64 = n_sub_832923C0(ctx, base); }

// sub_832924E0  [112 bytes]
uint64_t n_sub_832924E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82025220 = int32_t(0x82025220);
	constexpr int32_t str_TXT_82025268_B_ = int32_t(0x82025268);
	constexpr int32_t g_833375A4 = int32_t(0x833375A4);
	constexpr int32_t g_833376C4 = int32_t(0x833376C4);
	if (!UseLiftedCode(145, 0x832924E0)) { __imp__sub_832924E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832924E0);
	// Stores the stack arguments of n_sub_82D4F620 (a constant pointer at +84, 1 at +92, zeros at +100..+116 in the stack frame), then calls it with
	// the global object, a string constant, a second global and a size.
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82025220);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_833375A4;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82025268_B_, (int64_t)g_833376C4, 40, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82025268_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832924E0, 0x832924E0) { ctx.r3.u64 = n_sub_832924E0(ctx, base); }

// sub_83292710  [100 bytes]
uint64_t n_sub_83292710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820257BC_B_ = int32_t(0x820257BC);
	constexpr int32_t g_83337694 = int32_t(0x83337694);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x83292710)) { __imp__sub_83292710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83292710);
	// Stores the stack arguments of n_sub_82D4F620 (zeros at +84..+116 in the stack frame), then calls it with
	// the global object, a string constant, a second global and a size.
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83337694;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_820257BC_B_, g_8335ACB4, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_820257BC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83292710, 0x83292710) { ctx.r3.u64 = n_sub_83292710(ctx, base); }

uint64_t n_sub_83292900(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82025A64 = int32_t(0x82025A64);
	constexpr int32_t str_TXT_82025AC4_B_ = int32_t(0x82025AC4);
	constexpr int32_t g_83337754 = int32_t(0x83337754);
	if (!UseLiftedCode(145, 0x83292900)) { __imp__sub_83292900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83292900);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82025A64;
	uint64_t object = g_83337754;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82025AC4_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82025AC4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83292900, 0x83292900) { ctx.r3.u64 = n_sub_83292900(ctx, base); }

uint64_t n_sub_83292970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82025A94 = int32_t(0x82025A94);
	constexpr int32_t str_TXT_82025AE4_B_ = int32_t(0x82025AE4);
	constexpr int32_t g_83337784 = int32_t(0x83337784);
	if (!UseLiftedCode(145, 0x83292970)) { __imp__sub_83292970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83292970);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82025A94;
	uint64_t object = g_83337784;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82025AE4_B_, 0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82025AE4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83292970, 0x83292970) { ctx.r3.u64 = n_sub_83292970(ctx, base); }

uint64_t n_sub_832929E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82025B08 = int32_t(0x82025B08);
	constexpr int32_t str_TXT_82025B38_B_ = int32_t(0x82025B38);
	constexpr int32_t g_833377B4 = int32_t(0x833377B4);
	if (!UseLiftedCode(145, 0x832929E0)) { __imp__sub_832929E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832929E0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82025B08;
	uint64_t object = g_833377B4;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82025B38_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82025B38_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832929E0, 0x832929E0) { ctx.r3.u64 = n_sub_832929E0(ctx, base); }

uint64_t n_sub_83293160(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82026E38 = int32_t(0x82026E38);
	constexpr int32_t str_TXT_82026E68_B_ = int32_t(0x82026E68);
	constexpr int32_t g_83337ABC = int32_t(0x83337ABC);
	if (!UseLiftedCode(145, 0x83293160)) { __imp__sub_83293160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293160);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82026E38;
	uint64_t object = g_83337ABC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82026E68_B_, 0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82026E68_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83293160, 0x83293160) { ctx.r3.u64 = n_sub_83293160(ctx, base); }

uint64_t n_sub_832932B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82026FA4 = int32_t(0x82026FA4);
	constexpr int32_t str_TXT_82026FD4_B_ = int32_t(0x82026FD4);
	constexpr int32_t g_83337B4C = int32_t(0x83337B4C);
	if (!UseLiftedCode(145, 0x832932B0)) { __imp__sub_832932B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832932B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82026FA4;
	uint64_t object = g_83337B4C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82026FD4_B_, 0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82026FD4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832932B0, 0x832932B0) { ctx.r3.u64 = n_sub_832932B0(ctx, base); }

uint64_t n_sub_83293320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82026FF4 = int32_t(0x82026FF4);
	constexpr int32_t str_TXT_82027024_B_ = int32_t(0x82027024);
	constexpr int32_t g_83337B7C = int32_t(0x83337B7C);
	if (!UseLiftedCode(145, 0x83293320)) { __imp__sub_83293320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293320);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82026FF4;
	uint64_t object = g_83337B7C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82027024_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82027024_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83293320, 0x83293320) { ctx.r3.u64 = n_sub_83293320(ctx, base); }

uint64_t n_sub_83293630(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82027414 = int32_t(0x82027414);
	constexpr int32_t str_TXT_8202745C_B_ = int32_t(0x8202745C);
	constexpr int32_t g_83337CCC = int32_t(0x83337CCC);
	if (!UseLiftedCode(145, 0x83293630)) { __imp__sub_83293630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293630);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82027414;
	uint64_t object = g_83337CCC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202745C_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202745C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83293630, 0x83293630) { ctx.r3.u64 = n_sub_83293630(ctx, base); }

uint64_t n_sub_832939E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82027A8C = int32_t(0x82027A8C);
	constexpr int32_t str_TXT_82027B80_B_ = int32_t(0x82027B80);
	constexpr int32_t g_83337E4C = int32_t(0x83337E4C);
	if (!UseLiftedCode(145, 0x832939E0)) { __imp__sub_832939E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832939E0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82027A8C;
	uint64_t object = g_83337E4C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82027B80_B_, 0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82027B80_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832939E0, 0x832939E0) { ctx.r3.u64 = n_sub_832939E0(ctx, base); }

// sub_83293C98  [112 bytes]
uint64_t n_sub_83293C98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82027DD8 = int32_t(0x82027DD8);
	constexpr int32_t str_TXT_82027E38_B_ = int32_t(0x82027E38);
	constexpr int32_t g_83337BAC = int32_t(0x83337BAC);
	constexpr int32_t g_83337F6C = int32_t(0x83337F6C);
	if (!UseLiftedCode(145, 0x83293C98)) { __imp__sub_83293C98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293C98);
	// Stores the stack arguments of n_sub_82D4F620 (an address at +84, 2 at +92, zeros at +100..+116), then
	// calls it with the global object, a string constant, a second global and a size.
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82027DD8;
	uint64_t object = g_83337F6C;
	uint64_t name = str_TXT_82027E38_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83337BAC, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83293C98, 0x83293C98) { ctx.r3.u64 = n_sub_83293C98(ctx, base); }

uint64_t n_sub_83293D08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82027E08 = int32_t(0x82027E08);
	constexpr int32_t str_TXT_82027E50_B_ = int32_t(0x82027E50);
	constexpr int32_t g_83337F9C = int32_t(0x83337F9C);
	if (!UseLiftedCode(145, 0x83293D08)) { __imp__sub_83293D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293D08);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82027E08;
	uint64_t object = g_83337F9C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82027E50_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82027E50_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83293D08, 0x83293D08) { ctx.r3.u64 = n_sub_83293D08(ctx, base); }

uint64_t n_sub_83293DE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82027F38 = int32_t(0x82027F38);
	constexpr int32_t str_TXT_82028010_B_ = int32_t(0x82028010);
	constexpr int32_t g_83337FFC = int32_t(0x83337FFC);
	if (!UseLiftedCode(145, 0x83293DE8)) { __imp__sub_83293DE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293DE8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82027F38;
	uint64_t object = g_83337FFC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82028010_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82028010_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83293DE8, 0x83293DE8) { ctx.r3.u64 = n_sub_83293DE8(ctx, base); }

uint64_t n_sub_83293EC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82028040 = int32_t(0x82028040);
	constexpr int32_t str_TXT_82028070_B_ = int32_t(0x82028070);
	constexpr int32_t g_83337BAC = int32_t(0x83337BAC);
	constexpr int32_t g_8333805C = int32_t(0x8333805C);
	if (!UseLiftedCode(145, 0x83293EC8)) { __imp__sub_83293EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83293EC8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82028040;
	uint64_t object = g_8333805C;
	uint64_t name = str_TXT_82028070_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83337BAC, 20, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83293EC8, 0x83293EC8) { ctx.r3.u64 = n_sub_83293EC8(ctx, base); }

uint64_t n_sub_83294018(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82028378 = int32_t(0x82028378);
	constexpr int32_t str_TXT_820283A8_B_ = int32_t(0x820283A8);
	constexpr int32_t g_833380EC = int32_t(0x833380EC);
	if (!UseLiftedCode(145, 0x83294018)) { __imp__sub_83294018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294018);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82028378;
	uint64_t object = g_833380EC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820283A8_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820283A8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294018, 0x83294018) { ctx.r3.u64 = n_sub_83294018(ctx, base); }

uint64_t n_sub_83294088(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820283C0 = int32_t(0x820283C0);
	constexpr int32_t str_TXT_820283D8_B_ = int32_t(0x820283D8);
	constexpr int32_t g_8333811C = int32_t(0x8333811C);
	constexpr int32_t g_8333814C = int32_t(0x8333814C);
	if (!UseLiftedCode(145, 0x83294088)) { __imp__sub_83294088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294088);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_820283C0);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333811C;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820283D8_B_, (int64_t)g_8333814C, 20, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820283D8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294088, 0x83294088) { ctx.r3.u64 = n_sub_83294088(ctx, base); }

uint64_t n_sub_832940F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820283F8 = int32_t(0x820283F8);
	constexpr int32_t str_TXT_82028428_B_ = int32_t(0x82028428);
	constexpr int32_t g_8333814C = int32_t(0x8333814C);
	if (!UseLiftedCode(145, 0x832940F8)) { __imp__sub_832940F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832940F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820283F8;
	uint64_t object = g_8333814C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82028428_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82028428_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832940F8, 0x832940F8) { ctx.r3.u64 = n_sub_832940F8(ctx, base); }

uint64_t n_sub_832941D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82028460 = int32_t(0x82028460);
	constexpr int32_t str_TXT_820284B4_B_ = int32_t(0x820284B4);
	constexpr int32_t g_833381AC = int32_t(0x833381AC);
	if (!UseLiftedCode(145, 0x832941D8)) { __imp__sub_832941D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832941D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82028460;
	uint64_t object = g_833381AC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820284B4_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820284B4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832941D8, 0x832941D8) { ctx.r3.u64 = n_sub_832941D8(ctx, base); }

uint64_t n_sub_83294358(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202902C = int32_t(0x8202902C);
	constexpr int32_t str_TXT_820290A8_B_ = int32_t(0x820290A8);
	constexpr int32_t g_83338240 = int32_t(0x83338240);
	if (!UseLiftedCode(145, 0x83294358)) { __imp__sub_83294358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294358);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202902C;
	uint64_t object = g_83338240;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820290A8_B_, 0, 160, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820290A8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294358, 0x83294358) { ctx.r3.u64 = n_sub_83294358(ctx, base); }

uint64_t n_sub_832943C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202905C = int32_t(0x8202905C);
	constexpr int32_t str_TXT_820290CC_B_ = int32_t(0x820290CC);
	constexpr int32_t g_83338270 = int32_t(0x83338270);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832943C8)) { __imp__sub_832943C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832943C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202905C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338270;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820290CC_B_, (int64_t)g_833390B0, 176, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820290CC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832943C8, 0x832943C8) { ctx.r3.u64 = n_sub_832943C8(ctx, base); }

uint64_t n_sub_832945F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029408 = int32_t(0x82029408);
	constexpr int32_t str_TXT_82029470_B_ = int32_t(0x82029470);
	constexpr int32_t g_83338360 = int32_t(0x83338360);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832945F8)) { __imp__sub_832945F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832945F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029408);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338360;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82029470_B_, (int64_t)g_833390B0, 176, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82029470_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832945F8, 0x832945F8) { ctx.r3.u64 = n_sub_832945F8(ctx, base); }

uint64_t n_sub_83294818(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029798 = int32_t(0x82029798);
	constexpr int32_t str_TXT_820297FC_B_ = int32_t(0x820297FC);
	constexpr int32_t g_83338430 = int32_t(0x83338430);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x83294818)) { __imp__sub_83294818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294818);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029798);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338430;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820297FC_B_, (int64_t)g_833390B0, 160, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820297FC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294818, 0x83294818) { ctx.r3.u64 = n_sub_83294818(ctx, base); }

uint64_t n_sub_832948F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029938 = int32_t(0x82029938);
	constexpr int32_t str_TXT_820299A4_B_ = int32_t(0x820299A4);
	constexpr int32_t g_83338490 = int32_t(0x83338490);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832948F8)) { __imp__sub_832948F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832948F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029938);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338490;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820299A4_B_, (int64_t)g_833390B0, 208, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820299A4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832948F8, 0x832948F8) { ctx.r3.u64 = n_sub_832948F8(ctx, base); }

uint64_t n_sub_832949D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029A98 = int32_t(0x82029A98);
	constexpr int32_t str_TXT_82029B08_B_ = int32_t(0x82029B08);
	constexpr int32_t g_833384F0 = int32_t(0x833384F0);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832949D8)) { __imp__sub_832949D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832949D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029A98);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_833384F0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82029B08_B_, (int64_t)g_833390B0, 224, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82029B08_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832949D8, 0x832949D8) { ctx.r3.u64 = n_sub_832949D8(ctx, base); }

uint64_t n_sub_83294A48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029B40 = int32_t(0x82029B40);
	constexpr int32_t str_TXT_82029BBC_B_ = int32_t(0x82029BBC);
	constexpr int32_t g_83338520 = int32_t(0x83338520);
	if (!UseLiftedCode(145, 0x83294A48)) { __imp__sub_83294A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294A48);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82029B40;
	uint64_t object = g_83338520;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82029BBC_B_, 0, 112, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82029BBC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294A48, 0x83294A48) { ctx.r3.u64 = n_sub_83294A48(ctx, base); }

uint64_t n_sub_83294AB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029B70 = int32_t(0x82029B70);
	constexpr int32_t str_TXT_82029BDC_B_ = int32_t(0x82029BDC);
	constexpr int32_t g_83338550 = int32_t(0x83338550);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x83294AB8)) { __imp__sub_83294AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294AB8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029B70);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338550;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82029BDC_B_, (int64_t)g_833390B0, 128, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82029BDC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294AB8, 0x83294AB8) { ctx.r3.u64 = n_sub_83294AB8(ctx, base); }

uint64_t n_sub_83294D00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029F40 = int32_t(0x82029F40);
	constexpr int32_t str_TXT_82029FA8_B_ = int32_t(0x82029FA8);
	constexpr int32_t g_83338640 = int32_t(0x83338640);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x83294D00)) { __imp__sub_83294D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294D00);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029F40);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338640;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82029FA8_B_, (int64_t)g_833390B0, 192, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82029FA8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294D00, 0x83294D00) { ctx.r3.u64 = n_sub_83294D00(ctx, base); }

uint64_t n_sub_83294DD0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82028FA0_B_ = int32_t(0x82028FA0);
	constexpr int32_t g_83338680 = int32_t(0x83338680);
	constexpr int32_t g_83338E90 = int32_t(0x83338E90);
	if (!UseLiftedCode(145, 0x83294DD0)) { __imp__sub_83294DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294DD0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338680;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_82028FA0_B_, g_83338E90, 512, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_82028FA0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294DD0, 0x83294DD0) { ctx.r3.u64 = n_sub_83294DD0(ctx, base); }

uint64_t n_sub_83294E38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029FC0 = int32_t(0x82029FC0);
	constexpr int32_t str_TXT_8202A03C_B_ = int32_t(0x8202A03C);
	constexpr int32_t g_833386B0 = int32_t(0x833386B0);
	if (!UseLiftedCode(145, 0x83294E38)) { __imp__sub_83294E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294E38);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82029FC0;
	uint64_t object = g_833386B0;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A03C_B_, 0, 128, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A03C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294E38, 0x83294E38) { ctx.r3.u64 = n_sub_83294E38(ctx, base); }

uint64_t n_sub_83294EA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82029FF0 = int32_t(0x82029FF0);
	constexpr int32_t str_TXT_8202A060_B_ = int32_t(0x8202A060);
	constexpr int32_t g_833386E0 = int32_t(0x833386E0);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x83294EA8)) { __imp__sub_83294EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83294EA8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82029FF0);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_833386E0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A060_B_, (int64_t)g_833390B0, 144, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A060_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83294EA8, 0x83294EA8) { ctx.r3.u64 = n_sub_83294EA8(ctx, base); }

uint64_t n_sub_832950C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A148 = int32_t(0x8202A148);
	constexpr int32_t str_TXT_8202A188_B_ = int32_t(0x8202A188);
	constexpr int32_t g_833387B0 = int32_t(0x833387B0);
	constexpr int32_t g_83339310 = int32_t(0x83339310);
	if (!UseLiftedCode(145, 0x832950C8)) { __imp__sub_832950C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832950C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202A148);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_833387B0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A188_B_, (int64_t)g_83339310, 352, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A188_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832950C8, 0x832950C8) { ctx.r3.u64 = n_sub_832950C8(ctx, base); }

uint64_t n_sub_832951D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A4D0 = int32_t(0x8202A4D0);
	constexpr int32_t str_TXT_8202A5C4_B_ = int32_t(0x8202A5C4);
	constexpr int32_t g_83338810 = int32_t(0x83338810);
	if (!UseLiftedCode(145, 0x832951D8)) { __imp__sub_832951D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832951D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202A4D0;
	uint64_t object = g_83338810;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A5C4_B_, 0, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A5C4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832951D8, 0x832951D8) { ctx.r3.u64 = n_sub_832951D8(ctx, base); }

uint64_t n_sub_832952B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202A60C_B_ = int32_t(0x8202A60C);
	constexpr int32_t g_83338870 = int32_t(0x83338870);
	constexpr int32_t g_833391E0 = int32_t(0x833391E0);
	if (!UseLiftedCode(145, 0x832952B8)) { __imp__sub_832952B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832952B8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338870;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202A60C_B_, g_833391E0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202A60C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832952B8, 0x832952B8) { ctx.r3.u64 = n_sub_832952B8(ctx, base); }

uint64_t n_sub_83295320(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A63C = int32_t(0x8202A63C);
	constexpr int32_t str_TXT_8202A680_B_ = int32_t(0x8202A680);
	constexpr int32_t g_833388A0 = int32_t(0x833388A0);
	constexpr int32_t g_833391B0 = int32_t(0x833391B0);
	if (!UseLiftedCode(145, 0x83295320)) { __imp__sub_83295320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295320);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202A63C;
	uint64_t object = g_833388A0;
	uint64_t name = str_TXT_8202A680_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833391B0, 28, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83295320, 0x83295320) { ctx.r3.u64 = n_sub_83295320(ctx, base); }

uint64_t n_sub_83295390(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202A6A0_B_ = int32_t(0x8202A6A0);
	constexpr int32_t g_833388D0 = int32_t(0x833388D0);
	constexpr int32_t g_83338BA0 = int32_t(0x83338BA0);
	if (!UseLiftedCode(145, 0x83295390)) { __imp__sub_83295390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295390);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_833388D0;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202A6A0_B_, g_83338BA0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202A6A0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295390, 0x83295390) { ctx.r3.u64 = n_sub_83295390(ctx, base); }

uint64_t n_sub_832953F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202A6B8_B_ = int32_t(0x8202A6B8);
	constexpr int32_t g_83338870 = int32_t(0x83338870);
	constexpr int32_t g_83338900 = int32_t(0x83338900);
	if (!UseLiftedCode(145, 0x832953F8)) { __imp__sub_832953F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832953F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338900;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202A6B8_B_, g_83338870, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202A6B8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832953F8, 0x832953F8) { ctx.r3.u64 = n_sub_832953F8(ctx, base); }

uint64_t n_sub_832954C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A6F4 = int32_t(0x8202A6F4);
	constexpr int32_t str_TXT_8202A75C_B_ = int32_t(0x8202A75C);
	constexpr int32_t g_83338940 = int32_t(0x83338940);
	constexpr int32_t g_833392B0 = int32_t(0x833392B0);
	if (!UseLiftedCode(145, 0x832954C0)) { __imp__sub_832954C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832954C0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202A6F4;
	uint64_t object = g_83338940;
	uint64_t name = str_TXT_8202A75C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833392B0, 208, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_832954C0, 0x832954C0) { ctx.r3.u64 = n_sub_832954C0(ctx, base); }

uint64_t n_sub_83295670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A888 = int32_t(0x8202A888);
	constexpr int32_t str_TXT_8202A904_B_ = int32_t(0x8202A904);
	constexpr int32_t g_833389E0 = int32_t(0x833389E0);
	if (!UseLiftedCode(145, 0x83295670)) { __imp__sub_83295670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295670);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202A888;
	uint64_t object = g_833389E0;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A904_B_, 0, 64, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A904_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295670, 0x83295670) { ctx.r3.u64 = n_sub_83295670(ctx, base); }

uint64_t n_sub_832956E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A8B8 = int32_t(0x8202A8B8);
	constexpr int32_t str_TXT_8202A928_B_ = int32_t(0x8202A928);
	constexpr int32_t g_83338A10 = int32_t(0x83338A10);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832956E0)) { __imp__sub_832956E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832956E0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202A8B8);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338A10;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A928_B_, (int64_t)g_833390B0, 80, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A928_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832956E0, 0x832956E0) { ctx.r3.u64 = n_sub_832956E0(ctx, base); }

uint64_t n_sub_83295750(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A948 = int32_t(0x8202A948);
	constexpr int32_t str_TXT_8202A9C4_B_ = int32_t(0x8202A9C4);
	constexpr int32_t g_83338A40 = int32_t(0x83338A40);
	if (!UseLiftedCode(145, 0x83295750)) { __imp__sub_83295750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295750);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202A948;
	uint64_t object = g_83338A40;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A9C4_B_, 0, 64, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A9C4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295750, 0x83295750) { ctx.r3.u64 = n_sub_83295750(ctx, base); }

uint64_t n_sub_832957C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202A978 = int32_t(0x8202A978);
	constexpr int32_t str_TXT_8202A9E8_B_ = int32_t(0x8202A9E8);
	constexpr int32_t g_83338A70 = int32_t(0x83338A70);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832957C0)) { __imp__sub_832957C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832957C0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202A978);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338A70;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202A9E8_B_, (int64_t)g_833390B0, 80, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202A9E8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832957C0, 0x832957C0) { ctx.r3.u64 = n_sub_832957C0(ctx, base); }

uint64_t n_sub_83295830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202AA08 = int32_t(0x8202AA08);
	constexpr int32_t str_TXT_8202AAC8_B_ = int32_t(0x8202AAC8);
	constexpr int32_t g_83338AA0 = int32_t(0x83338AA0);
	if (!UseLiftedCode(145, 0x83295830)) { __imp__sub_83295830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295830);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202AA08;
	uint64_t object = g_83338AA0;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202AAC8_B_, 0, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202AAC8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295830, 0x83295830) { ctx.r3.u64 = n_sub_83295830(ctx, base); }

uint64_t n_sub_83295970(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202AB08_B_ = int32_t(0x8202AB08);
	constexpr int32_t g_83338B10 = int32_t(0x83338B10);
	constexpr int32_t g_83338BA0 = int32_t(0x83338BA0);
	if (!UseLiftedCode(145, 0x83295970)) { __imp__sub_83295970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295970);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338B10;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202AB08_B_, g_83338BA0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202AB08_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295970, 0x83295970) { ctx.r3.u64 = n_sub_83295970(ctx, base); }

uint64_t n_sub_83295AB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202AD50_B_ = int32_t(0x8202AD50);
	constexpr int32_t g_83338BA0 = int32_t(0x83338BA0);
	constexpr int32_t g_833391E0 = int32_t(0x833391E0);
	if (!UseLiftedCode(145, 0x83295AB8)) { __imp__sub_83295AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295AB8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338BA0;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202AD50_B_, g_833391E0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202AD50_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295AB8, 0x83295AB8) { ctx.r3.u64 = n_sub_83295AB8(ctx, base); }

uint64_t n_sub_83295CC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202AF7C = int32_t(0x8202AF7C);
	constexpr int32_t str_TXT_8202AF94_B_ = int32_t(0x8202AF94);
	constexpr int32_t g_83338C50 = int32_t(0x83338C50);
	constexpr int32_t g_83339310 = int32_t(0x83339310);
	if (!UseLiftedCode(145, 0x83295CC0)) { __imp__sub_83295CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295CC0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202AF7C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338C50;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202AF94_B_, (int64_t)g_83339310, 352, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202AF94_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295CC0, 0x83295CC0) { ctx.r3.u64 = n_sub_83295CC0(ctx, base); }

uint64_t n_sub_83295FA0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202C848_B_ = int32_t(0x8202C848);
	constexpr int32_t g_83338D30 = int32_t(0x83338D30);
	constexpr int32_t g_833391E0 = int32_t(0x833391E0);
	if (!UseLiftedCode(145, 0x83295FA0)) { __imp__sub_83295FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83295FA0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338D30;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202C848_B_, g_833391E0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202C848_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83295FA0, 0x83295FA0) { ctx.r3.u64 = n_sub_83295FA0(ctx, base); }

uint64_t n_sub_83296008(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202C874 = int32_t(0x8202C874);
	constexpr int32_t str_TXT_8202C8E4_B_ = int32_t(0x8202C8E4);
	constexpr int32_t g_83338D60 = int32_t(0x83338D60);
	constexpr int32_t g_83338DC0 = int32_t(0x83338DC0);
	if (!UseLiftedCode(145, 0x83296008)) { __imp__sub_83296008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296008);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202C874;
	uint64_t object = g_83338D60;
	uint64_t name = str_TXT_8202C8E4_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83338DC0, 60, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83296008, 0x83296008) { ctx.r3.u64 = n_sub_83296008(ctx, base); }

uint64_t n_sub_83296078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202C914 = int32_t(0x8202C914);
	constexpr int32_t str_TXT_8202C950_B_ = int32_t(0x8202C950);
	constexpr int32_t g_83338D90 = int32_t(0x83338D90);
	constexpr int32_t g_83338F50 = int32_t(0x83338F50);
	if (!UseLiftedCode(145, 0x83296078)) { __imp__sub_83296078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296078);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202C914);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338D90;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202C950_B_, (int64_t)g_83338F50, 28, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202C950_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296078, 0x83296078) { ctx.r3.u64 = n_sub_83296078(ctx, base); }

uint64_t n_sub_83296258(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202CE98 = int32_t(0x8202CE98);
	constexpr int32_t str_TXT_8202D0F4_B_ = int32_t(0x8202D0F4);
	constexpr int32_t g_83338E50 = int32_t(0x83338E50);
	if (!UseLiftedCode(145, 0x83296258)) { __imp__sub_83296258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296258);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202CE98;
	uint64_t object = g_83338E50;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202D0F4_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202D0F4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296258, 0x83296258) { ctx.r3.u64 = n_sub_83296258(ctx, base); }

uint64_t n_sub_832963A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D138_B_ = int32_t(0x8202D138);
	constexpr int32_t g_83338EC0 = int32_t(0x83338EC0);
	constexpr int32_t g_833392E0 = int32_t(0x833392E0);
	if (!UseLiftedCode(145, 0x832963A0)) { __imp__sub_832963A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832963A0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338EC0;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D138_B_, g_833392E0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D138_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832963A0, 0x832963A0) { ctx.r3.u64 = n_sub_832963A0(ctx, base); }

uint64_t n_sub_83296408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202D168 = int32_t(0x8202D168);
	constexpr int32_t str_TXT_8202D180_B_ = int32_t(0x8202D180);
	constexpr int32_t g_83338EF0 = int32_t(0x83338EF0);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x83296408)) { __imp__sub_83296408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296408);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202D168);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338EF0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202D180_B_, (int64_t)g_8335ACB4, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202D180_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296408, 0x83296408) { ctx.r3.u64 = n_sub_83296408(ctx, base); }

uint64_t n_sub_83296478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D1A0_B_ = int32_t(0x8202D1A0);
	constexpr int32_t g_83338F20 = int32_t(0x83338F20);
	constexpr int32_t g_83339050 = int32_t(0x83339050);
	if (!UseLiftedCode(145, 0x83296478)) { __imp__sub_83296478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296478);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83338F20;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D1A0_B_, g_83339050, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D1A0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296478, 0x83296478) { ctx.r3.u64 = n_sub_83296478(ctx, base); }

uint64_t n_sub_832965B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202D250 = int32_t(0x8202D250);
	constexpr int32_t str_TXT_8202D280_B_ = int32_t(0x8202D280);
	constexpr int32_t g_83338F90 = int32_t(0x83338F90);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x832965B0)) { __imp__sub_832965B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832965B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202D250;
	uint64_t object = g_83338F90;
	uint64_t name = str_TXT_8202D280_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833390B0, 88, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_832965B0, 0x832965B0) { ctx.r3.u64 = n_sub_832965B0(ctx, base); }

uint64_t n_sub_83296620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202D29C = int32_t(0x8202D29C);
	constexpr int32_t str_TXT_8202D2B4_B_ = int32_t(0x8202D2B4);
	constexpr int32_t g_83338F50 = int32_t(0x83338F50);
	constexpr int32_t g_83338FC0 = int32_t(0x83338FC0);
	if (!UseLiftedCode(145, 0x83296620)) { __imp__sub_83296620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296620);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202D29C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83338FC0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202D2B4_B_, (int64_t)g_83338F50, 36, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202D2B4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296620, 0x83296620) { ctx.r3.u64 = n_sub_83296620(ctx, base); }

uint64_t n_sub_83296690(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202D2D4 = int32_t(0x8202D2D4);
	constexpr int32_t str_TXT_8202D304_B_ = int32_t(0x8202D304);
	constexpr int32_t g_83338F50 = int32_t(0x83338F50);
	constexpr int32_t g_83338FF0 = int32_t(0x83338FF0);
	if (!UseLiftedCode(145, 0x83296690)) { __imp__sub_83296690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296690);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202D2D4;
	uint64_t object = g_83338FF0;
	uint64_t name = str_TXT_8202D304_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83338F50, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83296690, 0x83296690) { ctx.r3.u64 = n_sub_83296690(ctx, base); }

uint64_t n_sub_83296700(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D314_B_ = int32_t(0x8202D314);
	constexpr int32_t g_83339020 = int32_t(0x83339020);
	constexpr int32_t g_833390B0 = int32_t(0x833390B0);
	if (!UseLiftedCode(145, 0x83296700)) { __imp__sub_83296700(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296700);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339020;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D314_B_, g_833390B0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D314_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296700, 0x83296700) { ctx.r3.u64 = n_sub_83296700(ctx, base); }

uint64_t n_sub_83296768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D32C_B_ = int32_t(0x8202D32C);
	constexpr int32_t g_83339050 = int32_t(0x83339050);
	constexpr int32_t g_833391E0 = int32_t(0x833391E0);
	if (!UseLiftedCode(145, 0x83296768)) { __imp__sub_83296768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296768);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339050;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D32C_B_, g_833391E0, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D32C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296768, 0x83296768) { ctx.r3.u64 = n_sub_83296768(ctx, base); }

uint64_t n_sub_832967D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D344_B_ = int32_t(0x8202D344);
	constexpr int32_t g_83339050 = int32_t(0x83339050);
	constexpr int32_t g_83339080 = int32_t(0x83339080);
	if (!UseLiftedCode(145, 0x832967D0)) { __imp__sub_832967D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832967D0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339080;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D344_B_, g_83339050, 288, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D344_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832967D0, 0x832967D0) { ctx.r3.u64 = n_sub_832967D0(ctx, base); }

uint64_t n_sub_832969A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202D880_B_ = int32_t(0x8202D880);
	constexpr int32_t g_83339140 = int32_t(0x83339140);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x832969A8)) { __imp__sub_832969A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832969A8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339140;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202D880_B_, g_8335ACB4, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202D880_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832969A8, 0x832969A8) { ctx.r3.u64 = n_sub_832969A8(ctx, base); }

uint64_t n_sub_83296AE0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202D924 = int32_t(0x8202D924);
	constexpr int32_t str_TXT_8202D954_B_ = int32_t(0x8202D954);
	constexpr int32_t g_833390E0 = int32_t(0x833390E0);
	constexpr int32_t g_833391B0 = int32_t(0x833391B0);
	if (!UseLiftedCode(145, 0x83296AE0)) { __imp__sub_83296AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296AE0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202D924;
	uint64_t object = g_833391B0;
	uint64_t name = str_TXT_8202D954_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833390E0, 20, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83296AE0, 0x83296AE0) { ctx.r3.u64 = n_sub_83296AE0(ctx, base); }

uint64_t n_sub_83296C58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202DCA4_B_ = int32_t(0x8202DCA4);
	constexpr int32_t g_83339240 = int32_t(0x83339240);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x83296C58)) { __imp__sub_83296C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296C58);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339240;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202DCA4_B_, g_8335ACB4, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202DCA4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296C58, 0x83296C58) { ctx.r3.u64 = n_sub_83296C58(ctx, base); }

uint64_t n_sub_83296DC0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202DE54 = int32_t(0x8202DE54);
	constexpr int32_t str_TXT_8202DE84_B_ = int32_t(0x8202DE84);
	constexpr int32_t g_833392B0 = int32_t(0x833392B0);
	constexpr int32_t g_83339370 = int32_t(0x83339370);
	if (!UseLiftedCode(145, 0x83296DC0)) { __imp__sub_83296DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296DC0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202DE54;
	uint64_t object = g_833392B0;
	uint64_t name = str_TXT_8202DE84_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83339370, 152, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83296DC0, 0x83296DC0) { ctx.r3.u64 = n_sub_83296DC0(ctx, base); }

uint64_t n_sub_83296E98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202DF3C = int32_t(0x8202DF3C);
	constexpr int32_t str_TXT_8202DF54_B_ = int32_t(0x8202DF54);
	constexpr int32_t g_833392B0 = int32_t(0x833392B0);
	constexpr int32_t g_83339310 = int32_t(0x83339310);
	if (!UseLiftedCode(145, 0x83296E98)) { __imp__sub_83296E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296E98);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202DF3C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339310;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202DF54_B_, (int64_t)g_833392B0, 336, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202DF54_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296E98, 0x83296E98) { ctx.r3.u64 = n_sub_83296E98(ctx, base); }

uint64_t n_sub_83296F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202DF64 = int32_t(0x8202DF64);
	constexpr int32_t str_TXT_8202DF7C_B_ = int32_t(0x8202DF7C);
	constexpr int32_t g_83338F50 = int32_t(0x83338F50);
	constexpr int32_t g_83339340 = int32_t(0x83339340);
	if (!UseLiftedCode(145, 0x83296F08)) { __imp__sub_83296F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83296F08);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202DF64);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339340;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202DF7C_B_, (int64_t)g_83338F50, 28, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202DF7C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83296F08, 0x83296F08) { ctx.r3.u64 = n_sub_83296F08(ctx, base); }

uint64_t n_sub_83297078(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202EF90 = int32_t(0x8202EF90);
	constexpr int32_t str_TXT_8202F78C_B_ = int32_t(0x8202F78C);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_833393D0 = int32_t(0x833393D0);
	if (!UseLiftedCode(145, 0x83297078)) { __imp__sub_83297078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297078);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202EF90;
	uint64_t object = g_833393D0;
	uint64_t name = str_TXT_8202F78C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833393A0, 12, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83297078, 0x83297078) { ctx.r3.u64 = n_sub_83297078(ctx, base); }

uint64_t n_sub_832971C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202F7D4_B_ = int32_t(0x8202F7D4);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339460 = int32_t(0x83339460);
	if (!UseLiftedCode(145, 0x832971C8)) { __imp__sub_832971C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832971C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339460;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202F7D4_B_, g_833393A0, 2, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202F7D4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832971C8, 0x832971C8) { ctx.r3.u64 = n_sub_832971C8(ctx, base); }

uint64_t n_sub_83297230(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F098 = int32_t(0x8202F098);
	constexpr int32_t str_TXT_8202F7F0_B_ = int32_t(0x8202F7F0);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339490 = int32_t(0x83339490);
	if (!UseLiftedCode(145, 0x83297230)) { __imp__sub_83297230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297230);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202F098);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339490;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202F7F0_B_, (int64_t)g_833393A0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202F7F0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297230, 0x83297230) { ctx.r3.u64 = n_sub_83297230(ctx, base); }

uint64_t n_sub_832972A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F0B0 = int32_t(0x8202F0B0);
	constexpr int32_t str_TXT_8202F810_B_ = int32_t(0x8202F810);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_833394C0 = int32_t(0x833394C0);
	if (!UseLiftedCode(145, 0x832972A0)) { __imp__sub_832972A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832972A0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202F0B0;
	uint64_t object = g_833394C0;
	uint64_t name = str_TXT_8202F810_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833393A0, 144, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_832972A0, 0x832972A0) { ctx.r3.u64 = n_sub_832972A0(ctx, base); }

uint64_t n_sub_83297310(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F0E0 = int32_t(0x8202F0E0);
	constexpr int32_t str_TXT_8202F834_B_ = int32_t(0x8202F834);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_833394F0 = int32_t(0x833394F0);
	if (!UseLiftedCode(145, 0x83297310)) { __imp__sub_83297310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297310);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202F0E0;
	uint64_t object = g_833394F0;
	uint64_t name = str_TXT_8202F834_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833393A0, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83297310, 0x83297310) { ctx.r3.u64 = n_sub_83297310(ctx, base); }

uint64_t n_sub_83297380(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F110 = int32_t(0x8202F110);
	constexpr int32_t str_TXT_8202F85C_B_ = int32_t(0x8202F85C);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339520 = int32_t(0x83339520);
	if (!UseLiftedCode(145, 0x83297380)) { __imp__sub_83297380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297380);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202F110;
	uint64_t object = g_83339520;
	uint64_t name = str_TXT_8202F85C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833393A0, 112, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83297380, 0x83297380) { ctx.r3.u64 = n_sub_83297380(ctx, base); }

uint64_t n_sub_832973F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F140 = int32_t(0x8202F140);
	constexpr int32_t str_TXT_8202F880_B_ = int32_t(0x8202F880);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339550 = int32_t(0x83339550);
	if (!UseLiftedCode(145, 0x832973F0)) { __imp__sub_832973F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832973F0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202F140);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339550;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202F880_B_, (int64_t)g_833393A0, 4, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202F880_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832973F0, 0x832973F0) { ctx.r3.u64 = n_sub_832973F0(ctx, base); }

uint64_t n_sub_83297460(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F158 = int32_t(0x8202F158);
	constexpr int32_t str_TXT_8202F8A0_B_ = int32_t(0x8202F8A0);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339580 = int32_t(0x83339580);
	if (!UseLiftedCode(145, 0x83297460)) { __imp__sub_83297460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297460);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202F158);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339580;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202F8A0_B_, (int64_t)g_833393A0, 4, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202F8A0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297460, 0x83297460) { ctx.r3.u64 = n_sub_83297460(ctx, base); }

uint64_t n_sub_832975B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F200 = int32_t(0x8202F200);
	constexpr int32_t str_TXT_8202F8F0_B_ = int32_t(0x8202F8F0);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339610 = int32_t(0x83339610);
	if (!UseLiftedCode(145, 0x832975B0)) { __imp__sub_832975B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832975B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202F200);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339610;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202F8F0_B_, (int64_t)g_833393A0, 4, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202F8F0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832975B0, 0x832975B0) { ctx.r3.u64 = n_sub_832975B0(ctx, base); }

uint64_t n_sub_83297620(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F218 = int32_t(0x8202F218);
	constexpr int32_t str_TXT_8202F908_B_ = int32_t(0x8202F908);
	constexpr int32_t g_833393A0 = int32_t(0x833393A0);
	constexpr int32_t g_83339640 = int32_t(0x83339640);
	if (!UseLiftedCode(145, 0x83297620)) { __imp__sub_83297620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297620);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202F218;
	uint64_t object = g_83339640;
	uint64_t name = str_TXT_8202F908_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_833393A0, 4, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83297620, 0x83297620) { ctx.r3.u64 = n_sub_83297620(ctx, base); }

uint64_t n_sub_83297B10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F6E8 = int32_t(0x8202F6E8);
	constexpr int32_t str_TXT_8202FA58_B_ = int32_t(0x8202FA58);
	constexpr int32_t g_83339820 = int32_t(0x83339820);
	constexpr int32_t g_83339850 = int32_t(0x83339850);
	if (!UseLiftedCode(145, 0x83297B10)) { __imp__sub_83297B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297B10);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8202F6E8;
	uint64_t object = g_83339850;
	uint64_t name = str_TXT_8202FA58_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83339820, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83297B10, 0x83297B10) { ctx.r3.u64 = n_sub_83297B10(ctx, base); }

uint64_t n_sub_83297BF0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8202FAA8_B_ = int32_t(0x8202FAA8);
	constexpr int32_t g_83339820 = int32_t(0x83339820);
	constexpr int32_t g_833398B0 = int32_t(0x833398B0);
	if (!UseLiftedCode(145, 0x83297BF0)) { __imp__sub_83297BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297BF0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_833398B0;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_8202FAA8_B_, g_83339820, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_8202FAA8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297BF0, 0x83297BF0) { ctx.r3.u64 = n_sub_83297BF0(ctx, base); }

uint64_t n_sub_83297C58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8202F760 = int32_t(0x8202F760);
	constexpr int32_t str_TXT_8202FAD0_B_ = int32_t(0x8202FAD0);
	constexpr int32_t g_83339820 = int32_t(0x83339820);
	constexpr int32_t g_833398E0 = int32_t(0x833398E0);
	if (!UseLiftedCode(145, 0x83297C58)) { __imp__sub_83297C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297C58);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8202F760);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_833398E0;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8202FAD0_B_, (int64_t)g_83339820, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8202FAD0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297C58, 0x83297C58) { ctx.r3.u64 = n_sub_83297C58(ctx, base); }

uint64_t n_sub_83297CC8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x83297CC8)) { ctx.r8.u64 = arg1; __imp__sub_83297CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297CC8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2024, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_83297CC8, 0x83297CC8) { ctx.r3.u64 = n_sub_83297CC8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83297F28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030464 = int32_t(0x82030464);
	constexpr int32_t str_TXT_8203047C_B_ = int32_t(0x8203047C);
	constexpr int32_t g_83339A64 = int32_t(0x83339A64);
	constexpr int32_t g_8333A264 = int32_t(0x8333A264);
	if (!UseLiftedCode(145, 0x83297F28)) { __imp__sub_83297F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297F28);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82030464);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339A64;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_8203047C_B_, (int64_t)g_8333A264, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_8203047C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297F28, 0x83297F28) { ctx.r3.u64 = n_sub_83297F28(ctx, base); }

uint64_t n_sub_83297FF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030494 = int32_t(0x82030494);
	constexpr int32_t str_TXT_820304C0_B_ = int32_t(0x820304C0);
	constexpr int32_t g_83339A94 = int32_t(0x83339A94);
	constexpr int32_t g_83339AC4 = int32_t(0x83339AC4);
	if (!UseLiftedCode(145, 0x83297FF8)) { __imp__sub_83297FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83297FF8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82030494);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339AC4;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820304C0_B_, (int64_t)g_83339A94, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820304C0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83297FF8, 0x83297FF8) { ctx.r3.u64 = n_sub_83297FF8(ctx, base); }

uint64_t n_sub_83298068(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820304EC = int32_t(0x820304EC);
	constexpr int32_t str_TXT_82030544_B_ = int32_t(0x82030544);
	constexpr int32_t g_83339AF4 = int32_t(0x83339AF4);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	if (!UseLiftedCode(145, 0x83298068)) { __imp__sub_83298068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298068);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820304EC;
	uint64_t object = g_83339AF4;
	uint64_t name = str_TXT_82030544_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A564, 28, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83298068, 0x83298068) { ctx.r3.u64 = n_sub_83298068(ctx, base); }

uint64_t n_sub_832980D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030550 = int32_t(0x82030550);
	constexpr int32_t str_TXT_82030568_B_ = int32_t(0x82030568);
	constexpr int32_t g_83339B24 = int32_t(0x83339B24);
	constexpr int32_t g_8333A264 = int32_t(0x8333A264);
	if (!UseLiftedCode(145, 0x832980D8)) { __imp__sub_832980D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832980D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82030550);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339B24;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82030568_B_, (int64_t)g_8333A264, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82030568_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832980D8, 0x832980D8) { ctx.r3.u64 = n_sub_832980D8(ctx, base); }

uint64_t n_sub_83298430(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030840 = int32_t(0x82030840);
	constexpr int32_t str_TXT_820308A0_B_ = int32_t(0x820308A0);
	constexpr int32_t g_83339C44 = int32_t(0x83339C44);
	constexpr int32_t g_8333A134 = int32_t(0x8333A134);
	if (!UseLiftedCode(145, 0x83298430)) { __imp__sub_83298430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298430);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82030840);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339C44;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820308A0_B_, (int64_t)g_8333A134, 64, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820308A0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83298430, 0x83298430) { ctx.r3.u64 = n_sub_83298430(ctx, base); }

uint64_t n_sub_832986B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030B00 = int32_t(0x82030B00);
	constexpr int32_t str_TXT_82030B3C_B_ = int32_t(0x82030B3C);
	constexpr int32_t g_83339D24 = int32_t(0x83339D24);
	constexpr int32_t g_8333A374 = int32_t(0x8333A374);
	if (!UseLiftedCode(145, 0x832986B0)) { __imp__sub_832986B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832986B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82030B00);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_83339D24;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82030B3C_B_, (int64_t)g_8333A374, 112, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82030B3C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832986B0, 0x832986B0) { ctx.r3.u64 = n_sub_832986B0(ctx, base); }

uint64_t n_sub_83298800(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030CA0 = int32_t(0x82030CA0);
	constexpr int32_t str_TXT_82030D40_B_ = int32_t(0x82030D40);
	constexpr int32_t g_83339DB4 = int32_t(0x83339DB4);
	constexpr int32_t g_8333A4D4 = int32_t(0x8333A4D4);
	if (!UseLiftedCode(145, 0x83298800)) { __imp__sub_83298800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298800);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82030CA0;
	uint64_t object = g_83339DB4;
	uint64_t name = str_TXT_82030D40_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A4D4, 112, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83298800, 0x83298800) { ctx.r3.u64 = n_sub_83298800(ctx, base); }

uint64_t n_sub_83298A30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82030FB0 = int32_t(0x82030FB0);
	constexpr int32_t str_TXT_82030FF8_B_ = int32_t(0x82030FF8);
	constexpr int32_t g_83339E74 = int32_t(0x83339E74);
	constexpr int32_t g_83339EA4 = int32_t(0x83339EA4);
	if (!UseLiftedCode(145, 0x83298A30)) { __imp__sub_83298A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298A30);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82030FB0;
	uint64_t object = g_83339EA4;
	uint64_t name = str_TXT_82030FF8_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83339E74, 64, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83298A30, 0x83298A30) { ctx.r3.u64 = n_sub_83298A30(ctx, base); }

uint64_t n_sub_83298B78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82031244 = int32_t(0x82031244);
	constexpr int32_t str_TXT_82031274_B_ = int32_t(0x82031274);
	constexpr int32_t g_83339F14 = int32_t(0x83339F14);
	constexpr int32_t g_83339F44 = int32_t(0x83339F44);
	if (!UseLiftedCode(145, 0x83298B78)) { __imp__sub_83298B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298B78);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82031244;
	uint64_t object = g_83339F14;
	uint64_t name = str_TXT_82031274_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_83339F44, 28, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83298B78, 0x83298B78) { ctx.r3.u64 = n_sub_83298B78(ctx, base); }

uint64_t n_sub_83298BE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82031298_B_ = int32_t(0x82031298);
	constexpr int32_t g_83339F44 = int32_t(0x83339F44);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	if (!UseLiftedCode(145, 0x83298BE8)) { __imp__sub_83298BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298BE8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339F44;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_82031298_B_, g_8333A564, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_82031298_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83298BE8, 0x83298BE8) { ctx.r3.u64 = n_sub_83298BE8(ctx, base); }

uint64_t n_sub_83298C50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820312A8_B_ = int32_t(0x820312A8);
	constexpr int32_t g_83339F74 = int32_t(0x83339F74);
	constexpr int32_t g_8333A204 = int32_t(0x8333A204);
	if (!UseLiftedCode(145, 0x83298C50)) { __imp__sub_83298C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298C50);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_83339F74;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_820312A8_B_, g_8333A204, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_820312A8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83298C50, 0x83298C50) { ctx.r3.u64 = n_sub_83298C50(ctx, base); }

uint64_t n_sub_83298CB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820312C4 = int32_t(0x820312C4);
	constexpr int32_t str_TXT_82031340_B_ = int32_t(0x82031340);
	constexpr int32_t g_83339FA4 = int32_t(0x83339FA4);
	constexpr int32_t g_8333A5C4 = int32_t(0x8333A5C4);
	if (!UseLiftedCode(145, 0x83298CB8)) { __imp__sub_83298CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83298CB8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820312C4;
	uint64_t object = g_83339FA4;
	uint64_t name = str_TXT_82031340_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A5C4, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83298CB8, 0x83298CB8) { ctx.r3.u64 = n_sub_83298CB8(ctx, base); }

uint64_t n_sub_83299200(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82031A0C_B_ = int32_t(0x82031A0C);
	constexpr int32_t g_8333A174 = int32_t(0x8333A174);
	constexpr int32_t g_8333A374 = int32_t(0x8333A374);
	if (!UseLiftedCode(145, 0x83299200)) { __imp__sub_83299200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299200);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_8333A174;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_82031A0C_B_, g_8333A374, 96, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_82031A0C_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83299200, 0x83299200) { ctx.r3.u64 = n_sub_83299200(ctx, base); }

uint64_t n_sub_832995E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82032098_B_ = int32_t(0x82032098);
	constexpr int32_t g_8333A304 = int32_t(0x8333A304);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	if (!UseLiftedCode(145, 0x832995E0)) { __imp__sub_832995E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832995E0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_8333A304;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_82032098_B_, g_8333A564, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_82032098_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832995E0, 0x832995E0) { ctx.r3.u64 = n_sub_832995E0(ctx, base); }

uint64_t n_sub_832997C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820321B4_B_ = int32_t(0x820321B4);
	constexpr int32_t g_8333A3A4 = int32_t(0x8333A3A4);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	if (!UseLiftedCode(145, 0x832997C8)) { __imp__sub_832997C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832997C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_8333A3A4;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_820321B4_B_, g_8333A564, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_820321B4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832997C8, 0x832997C8) { ctx.r3.u64 = n_sub_832997C8(ctx, base); }

uint64_t n_sub_832999E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203229C = int32_t(0x8203229C);
	constexpr int32_t str_TXT_82032324_B_ = int32_t(0x82032324);
	constexpr int32_t g_8333A474 = int32_t(0x8333A474);
	if (!UseLiftedCode(145, 0x832999E0)) { __imp__sub_832999E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832999E0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8203229C;
	uint64_t object = g_8333A474;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82032324_B_, 0, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82032324_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_832999E0, 0x832999E0) { ctx.r3.u64 = n_sub_832999E0(ctx, base); }

uint64_t n_sub_83299A50(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820322CC = int32_t(0x820322CC);
	constexpr int32_t str_TXT_82032338_B_ = int32_t(0x82032338);
	constexpr int32_t g_8333A4A4 = int32_t(0x8333A4A4);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	if (!UseLiftedCode(145, 0x83299A50)) { __imp__sub_83299A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299A50);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820322CC;
	uint64_t object = g_8333A4A4;
	uint64_t name = str_TXT_82032338_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A564, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83299A50, 0x83299A50) { ctx.r3.u64 = n_sub_83299A50(ctx, base); }

uint64_t n_sub_83299B30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820324D0 = int32_t(0x820324D0);
	constexpr int32_t str_TXT_82032530_B_ = int32_t(0x82032530);
	constexpr int32_t g_8333A504 = int32_t(0x8333A504);
	constexpr int32_t g_8333A6B4 = int32_t(0x8333A6B4);
	if (!UseLiftedCode(145, 0x83299B30)) { __imp__sub_83299B30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299B30);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820324D0;
	uint64_t object = g_8333A504;
	uint64_t name = str_TXT_82032530_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A6B4, 160, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83299B30, 0x83299B30) { ctx.r3.u64 = n_sub_83299B30(ctx, base); }

uint64_t n_sub_83299C10(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203256C = int32_t(0x8203256C);
	constexpr int32_t str_TXT_8203259C_B_ = int32_t(0x8203259C);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x83299C10)) { __imp__sub_83299C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299C10);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8203256C;
	uint64_t object = g_8333A564;
	uint64_t name = str_TXT_8203259C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8335ACB4, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_83299C10, 0x83299C10) { ctx.r3.u64 = n_sub_83299C10(ctx, base); }

uint64_t n_sub_83299C80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820325A8_B_ = int32_t(0x820325A8);
	constexpr int32_t g_8333A134 = int32_t(0x8333A134);
	constexpr int32_t g_8333A594 = int32_t(0x8333A594);
	if (!UseLiftedCode(145, 0x83299C80)) { __imp__sub_83299C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299C80);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_8333A594;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_820325A8_B_, g_8333A134, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_820325A8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83299C80, 0x83299C80) { ctx.r3.u64 = n_sub_83299C80(ctx, base); }

uint64_t n_sub_83299F08(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_820327E8_B_ = int32_t(0x820327E8);
	constexpr int32_t g_8333A564 = int32_t(0x8333A564);
	constexpr int32_t g_8333A6B4 = int32_t(0x8333A6B4);
	if (!UseLiftedCode(145, 0x83299F08)) { __imp__sub_83299F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83299F08);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	STORE32(stack + 92, 0u);
	STORE32(stack + 84, 0u);
	uint64_t object = g_8333A6B4;
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, str_TXT_820327E8_B_, g_8333A564, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = str_TXT_820327E8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_83299F08, 0x83299F08) { ctx.r3.u64 = n_sub_83299F08(ctx, base); }

uint64_t n_sub_8329A0B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329A0B8)) { ctx.r8.u64 = arg1; __imp__sub_8329A0B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A0B8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2048, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329A0B8, 0x8329A0B8) { ctx.r3.u64 = n_sub_8329A0B8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329A1A8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203492C = int32_t(0x8203492C);
	constexpr int32_t str_TXT_82034944_B_ = int32_t(0x82034944);
	constexpr int32_t g_8333A1D4 = int32_t(0x8333A1D4);
	constexpr int32_t g_8333ABF8 = int32_t(0x8333ABF8);
	if (!UseLiftedCode(145, 0x8329A1A8)) { __imp__sub_8329A1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A1A8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8203492C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333ABF8;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82034944_B_, (int64_t)g_8333A1D4, 88, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82034944_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A1A8, 0x8329A1A8) { ctx.r3.u64 = n_sub_8329A1A8(ctx, base); }

uint64_t n_sub_8329A218(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203497C = int32_t(0x8203497C);
	constexpr int32_t str_TXT_82034A04_B_ = int32_t(0x82034A04);
	constexpr int32_t g_8333AC28 = int32_t(0x8333AC28);
	if (!UseLiftedCode(145, 0x8329A218)) { __imp__sub_8329A218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A218);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8203497C;
	uint64_t object = g_8333AC28;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82034A04_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82034A04_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A218, 0x8329A218) { ctx.r3.u64 = n_sub_8329A218(ctx, base); }

uint64_t n_sub_8329A2F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820349C4 = int32_t(0x820349C4);
	constexpr int32_t str_TXT_82034A38_B_ = int32_t(0x82034A38);
	constexpr int32_t g_8333AC88 = int32_t(0x8333AC88);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x8329A2F8)) { __imp__sub_8329A2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A2F8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820349C4;
	uint64_t object = g_8333AC88;
	uint64_t name = str_TXT_82034A38_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8335ACB4, 48, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A2F8, 0x8329A2F8) { ctx.r3.u64 = n_sub_8329A2F8(ctx, base); }

uint64_t n_sub_8329A418(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82035CDC = int32_t(0x82035CDC);
	constexpr int32_t str_TXT_82035D1C_B_ = int32_t(0x82035D1C);
	constexpr int32_t g_8333AEA8 = int32_t(0x8333AEA8);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x8329A418)) { __imp__sub_8329A418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A418);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82035CDC;
	uint64_t object = g_8333AEA8;
	uint64_t name = str_TXT_82035D1C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8335ACB4, 24, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A418, 0x8329A418) { ctx.r3.u64 = n_sub_8329A418(ctx, base); }

uint64_t n_sub_8329A568(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82035F78 = int32_t(0x82035F78);
	constexpr int32_t str_TXT_82035FF4_B_ = int32_t(0x82035FF4);
	constexpr int32_t g_8333AF38 = int32_t(0x8333AF38);
	if (!UseLiftedCode(145, 0x8329A568)) { __imp__sub_8329A568(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A568);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82035F78;
	uint64_t object = g_8333AF38;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82035FF4_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82035FF4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A568, 0x8329A568) { ctx.r3.u64 = n_sub_8329A568(ctx, base); }

uint64_t n_sub_8329A5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82035FA8 = int32_t(0x82035FA8);
	constexpr int32_t str_TXT_82036014_B_ = int32_t(0x82036014);
	constexpr int32_t g_8333AF68 = int32_t(0x8333AF68);
	if (!UseLiftedCode(145, 0x8329A5D8)) { __imp__sub_8329A5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A5D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82035FA8;
	uint64_t object = g_8333AF68;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036014_B_, 0, 24, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036014_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A5D8, 0x8329A5D8) { ctx.r3.u64 = n_sub_8329A5D8(ctx, base); }

uint64_t n_sub_8329A6B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036130 = int32_t(0x82036130);
	constexpr int32_t str_TXT_82036200_B_ = int32_t(0x82036200);
	constexpr int32_t g_8333B028 = int32_t(0x8333B028);
	if (!UseLiftedCode(145, 0x8329A6B8)) { __imp__sub_8329A6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A6B8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82036130;
	uint64_t object = g_8333B028;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036200_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036200_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A6B8, 0x8329A6B8) { ctx.r3.u64 = n_sub_8329A6B8(ctx, base); }

uint64_t n_sub_8329A8E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820363CC = int32_t(0x820363CC);
	constexpr int32_t str_TXT_82036444_B_ = int32_t(0x82036444);
	constexpr int32_t g_8333A134 = int32_t(0x8333A134);
	constexpr int32_t g_8333B0B8 = int32_t(0x8333B0B8);
	if (!UseLiftedCode(145, 0x8329A8E8)) { __imp__sub_8329A8E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A8E8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820363CC;
	uint64_t object = g_8333B0B8;
	uint64_t name = str_TXT_82036444_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333A134, 192, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A8E8, 0x8329A8E8) { ctx.r3.u64 = n_sub_8329A8E8(ctx, base); }

uint64_t n_sub_8329A958(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203646C = int32_t(0x8203646C);
	constexpr int32_t str_TXT_820364C4_B_ = int32_t(0x820364C4);
	constexpr int32_t g_8333B118 = int32_t(0x8333B118);
	if (!UseLiftedCode(145, 0x8329A958)) { __imp__sub_8329A958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A958);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8203646C;
	uint64_t object = g_8333B118;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820364C4_B_, 0, 80, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820364C4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A958, 0x8329A958) { ctx.r3.u64 = n_sub_8329A958(ctx, base); }

uint64_t n_sub_8329A9C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8203649C = int32_t(0x8203649C);
	constexpr int32_t str_TXT_820364FC_B_ = int32_t(0x820364FC);
	constexpr int32_t g_8333B0E8 = int32_t(0x8333B0E8);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x8329A9C8)) { __imp__sub_8329A9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329A9C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_8203649C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333B0E8;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820364FC_B_, (int64_t)g_8335ACB4, 20, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820364FC_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329A9C8, 0x8329A9C8) { ctx.r3.u64 = n_sub_8329A9C8(ctx, base); }

uint64_t n_sub_8329AAA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036708 = int32_t(0x82036708);
	constexpr int32_t str_TXT_820367D4_B_ = int32_t(0x820367D4);
	constexpr int32_t g_8333B1B8 = int32_t(0x8333B1B8);
	if (!UseLiftedCode(145, 0x8329AAA8)) { __imp__sub_8329AAA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AAA8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82036708;
	uint64_t object = g_8333B1B8;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820367D4_B_, 0, 24, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820367D4_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AAA8, 0x8329AAA8) { ctx.r3.u64 = n_sub_8329AAA8(ctx, base); }

uint64_t n_sub_8329AB18(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036738 = int32_t(0x82036738);
	constexpr int32_t str_TXT_820367F0_B_ = int32_t(0x820367F0);
	constexpr int32_t g_8333B178 = int32_t(0x8333B178);
	constexpr int32_t g_8333B1B8 = int32_t(0x8333B1B8);
	if (!UseLiftedCode(145, 0x8329AB18)) { __imp__sub_8329AB18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AB18);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82036738;
	uint64_t object = g_8333B178;
	uint64_t name = str_TXT_820367F0_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8333B1B8, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AB18, 0x8329AB18) { ctx.r3.u64 = n_sub_8329AB18(ctx, base); }

uint64_t n_sub_8329AD60(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036A14 = int32_t(0x82036A14);
	constexpr int32_t str_TXT_82036AC0_B_ = int32_t(0x82036AC0);
	constexpr int32_t g_8333B258 = int32_t(0x8333B258);
	if (!UseLiftedCode(145, 0x8329AD60)) { __imp__sub_8329AD60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AD60);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82036A14;
	uint64_t object = g_8333B258;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036AC0_B_, 0, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036AC0_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AD60, 0x8329AD60) { ctx.r3.u64 = n_sub_8329AD60(ctx, base); }

uint64_t n_sub_8329AE40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036B10 = int32_t(0x82036B10);
	constexpr int32_t str_TXT_82036B40_B_ = int32_t(0x82036B40);
	constexpr int32_t g_83339210 = int32_t(0x83339210);
	constexpr int32_t g_8333B2B8 = int32_t(0x8333B2B8);
	if (!UseLiftedCode(145, 0x8329AE40)) { __imp__sub_8329AE40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AE40);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82036B10);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333B2B8;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036B40_B_, (int64_t)g_83339210, 80, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036B40_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AE40, 0x8329AE40) { ctx.r3.u64 = n_sub_8329AE40(ctx, base); }

uint64_t n_sub_8329AF20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036C10 = int32_t(0x82036C10);
	constexpr int32_t str_TXT_82036C38_B_ = int32_t(0x82036C38);
	constexpr int32_t g_8333B318 = int32_t(0x8333B318);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x8329AF20)) { __imp__sub_8329AF20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AF20);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82036C10);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333B318;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036C38_B_, (int64_t)g_8335ACB4, 80, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036C38_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AF20, 0x8329AF20) { ctx.r3.u64 = n_sub_8329AF20(ctx, base); }

uint64_t n_sub_8329AF90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82036C5C = int32_t(0x82036C5C);
	constexpr int32_t str_TXT_82036C84_B_ = int32_t(0x82036C84);
	constexpr int32_t g_8333B348 = int32_t(0x8333B348);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	if (!UseLiftedCode(145, 0x8329AF90)) { __imp__sub_8329AF90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329AF90);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 84, (uint32_t)g_82036C5C);
	STORE32(stack + 92, 1u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	uint64_t object = g_8333B348;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82036C84_B_, (int64_t)g_8335ACB4, 20, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82036C84_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329AF90, 0x8329AF90) { ctx.r3.u64 = n_sub_8329AF90(ctx, base); }

// sub_8329B408  [72 bytes]
uint64_t n_sub_8329B408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038758_B_ = int32_t(0x82038758);
	constexpr int32_t g_82E693C8 = int32_t(0x82E693C8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333B4DC = int32_t(0x8333B4DC);
	if (!UseLiftedCode(145, 0x8329B408)) { __imp__sub_8329B408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B408);
	uint32_t stack = ctx.r1.u64;
	// Construct the global object (n_sub_82E86010) from a string constant, a function and 0,
	// then register its cleanup to run at exit (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E86010(ctx, base, g_8333B4DC, str_TXT_82038758_B_, g_82E693C8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B408, 0x8329B408) { ctx.r3.u64 = n_sub_8329B408(ctx, base); }

uint64_t n_sub_8329B5E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038998_B_ = int32_t(0x82038998);
	constexpr int32_t g_82E6E9A8 = int32_t(0x82E6E9A8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333BB58 = int32_t(0x8333BB58);
	if (!UseLiftedCode(145, 0x8329B5E0)) { __imp__sub_8329B5E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B5E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E86010(ctx, base, g_8333BB58, str_TXT_82038998_B_, g_82E6E9A8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2216, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B5E0, 0x8329B5E0) { ctx.r3.u64 = n_sub_8329B5E0(ctx, base); }

uint64_t n_sub_8329B6C8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038BA0_B_ = int32_t(0x82038BA0);
	constexpr int32_t g_82E72808 = int32_t(0x82E72808);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333BE94 = int32_t(0x8333BE94);
	if (!UseLiftedCode(145, 0x8329B6C8)) { __imp__sub_8329B6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B6C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333BE94, str_TXT_82038BA0_B_, g_82E72808, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2288, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B6C8, 0x8329B6C8) { ctx.r3.u64 = n_sub_8329B6C8(ctx, base); }

uint64_t n_sub_8329B710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038BC8_B_ = int32_t(0x82038BC8);
	constexpr int32_t g_82E72870 = int32_t(0x82E72870);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333BFA8 = int32_t(0x8333BFA8);
	if (!UseLiftedCode(145, 0x8329B710)) { __imp__sub_8329B710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B710);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333BFA8, str_TXT_82038BC8_B_, g_82E72870, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2312, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B710, 0x8329B710) { ctx.r3.u64 = n_sub_8329B710(ctx, base); }

uint64_t n_sub_8329B758(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038BEC_B_ = int32_t(0x82038BEC);
	constexpr int32_t g_82E728F0 = int32_t(0x82E728F0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C0BC = int32_t(0x8333C0BC);
	if (!UseLiftedCode(145, 0x8329B758)) { __imp__sub_8329B758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B758);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333C0BC, str_TXT_82038BEC_B_, g_82E728F0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B758, 0x8329B758) { ctx.r3.u64 = n_sub_8329B758(ctx, base); }

uint64_t n_sub_8329B7A0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038C10_B_ = int32_t(0x82038C10);
	constexpr int32_t g_82E729D0 = int32_t(0x82E729D0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C1D0 = int32_t(0x8333C1D0);
	if (!UseLiftedCode(145, 0x8329B7A0)) { __imp__sub_8329B7A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B7A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333C1D0, str_TXT_82038C10_B_, g_82E729D0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B7A0, 0x8329B7A0) { ctx.r3.u64 = n_sub_8329B7A0(ctx, base); }

uint64_t n_sub_8329B7E8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038C34_B_ = int32_t(0x82038C34);
	constexpr int32_t g_82E72AD8 = int32_t(0x82E72AD8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C2E4 = int32_t(0x8333C2E4);
	if (!UseLiftedCode(145, 0x8329B7E8)) { __imp__sub_8329B7E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B7E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333C2E4, str_TXT_82038C34_B_, g_82E72AD8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B7E8, 0x8329B7E8) { ctx.r3.u64 = n_sub_8329B7E8(ctx, base); }

uint64_t n_sub_8329B830(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038C60_B_ = int32_t(0x82038C60);
	constexpr int32_t g_82E72BC8 = int32_t(0x82E72BC8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C3F8 = int32_t(0x8333C3F8);
	if (!UseLiftedCode(145, 0x8329B830)) { __imp__sub_8329B830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B830);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333C3F8, str_TXT_82038C60_B_, g_82E72BC8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B830, 0x8329B830) { ctx.r3.u64 = n_sub_8329B830(ctx, base); }

uint64_t n_sub_8329B878(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038C74_B_ = int32_t(0x82038C74);
	constexpr int32_t g_82E72C38 = int32_t(0x82E72C38);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C50C = int32_t(0x8333C50C);
	if (!UseLiftedCode(145, 0x8329B878)) { __imp__sub_8329B878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B878);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333C50C, str_TXT_82038C74_B_, g_82E72C38, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B878, 0x8329B878) { ctx.r3.u64 = n_sub_8329B878(ctx, base); }

uint64_t n_sub_8329B8C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038C88_B_ = int32_t(0x82038C88);
	constexpr int32_t g_82E72C80 = int32_t(0x82E72C80);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C620 = int32_t(0x8333C620);
	if (!UseLiftedCode(145, 0x8329B8C0)) { __imp__sub_8329B8C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B8C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333C620, str_TXT_82038C88_B_, g_82E72C80, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B8C0, 0x8329B8C0) { ctx.r3.u64 = n_sub_8329B8C0(ctx, base); }

uint64_t n_sub_8329B908(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038CB0_B_ = int32_t(0x82038CB0);
	constexpr int32_t g_82E72CD8 = int32_t(0x82E72CD8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C734 = int32_t(0x8333C734);
	if (!UseLiftedCode(145, 0x8329B908)) { __imp__sub_8329B908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B908);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333C734, str_TXT_82038CB0_B_, g_82E72CD8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B908, 0x8329B908) { ctx.r3.u64 = n_sub_8329B908(ctx, base); }

uint64_t n_sub_8329B950(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038CDC_B_ = int32_t(0x82038CDC);
	constexpr int32_t g_82E72DA0 = int32_t(0x82E72DA0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C848 = int32_t(0x8333C848);
	if (!UseLiftedCode(145, 0x8329B950)) { __imp__sub_8329B950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B950);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333C848, str_TXT_82038CDC_B_, g_82E72DA0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B950, 0x8329B950) { ctx.r3.u64 = n_sub_8329B950(ctx, base); }

uint64_t n_sub_8329B998(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038D04_B_ = int32_t(0x82038D04);
	constexpr int32_t g_82E72EB0 = int32_t(0x82E72EB0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333C95C = int32_t(0x8333C95C);
	if (!UseLiftedCode(145, 0x8329B998)) { __imp__sub_8329B998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B998);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333C95C, str_TXT_82038D04_B_, g_82E72EB0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B998, 0x8329B998) { ctx.r3.u64 = n_sub_8329B998(ctx, base); }

uint64_t n_sub_8329B9E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038D28_B_ = int32_t(0x82038D28);
	constexpr int32_t g_82E72FA0 = int32_t(0x82E72FA0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CA70 = int32_t(0x8333CA70);
	if (!UseLiftedCode(145, 0x8329B9E0)) { __imp__sub_8329B9E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329B9E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333CA70, str_TXT_82038D28_B_, g_82E72FA0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329B9E0, 0x8329B9E0) { ctx.r3.u64 = n_sub_8329B9E0(ctx, base); }

uint64_t n_sub_8329BA28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038D54_B_ = int32_t(0x82038D54);
	constexpr int32_t g_82E73008 = int32_t(0x82E73008);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CB84 = int32_t(0x8333CB84);
	if (!UseLiftedCode(145, 0x8329BA28)) { __imp__sub_8329BA28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BA28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333CB84, str_TXT_82038D54_B_, g_82E73008, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BA28, 0x8329BA28) { ctx.r3.u64 = n_sub_8329BA28(ctx, base); }

uint64_t n_sub_8329BA70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038D78_B_ = int32_t(0x82038D78);
	constexpr int32_t g_82E73060 = int32_t(0x82E73060);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CC98 = int32_t(0x8333CC98);
	if (!UseLiftedCode(145, 0x8329BA70)) { __imp__sub_8329BA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BA70);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333CC98, str_TXT_82038D78_B_, g_82E73060, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BA70, 0x8329BA70) { ctx.r3.u64 = n_sub_8329BA70(ctx, base); }

uint64_t n_sub_8329BAB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038DA0_B_ = int32_t(0x82038DA0);
	constexpr int32_t g_82E730B8 = int32_t(0x82E730B8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CDAC = int32_t(0x8333CDAC);
	if (!UseLiftedCode(145, 0x8329BAB8)) { __imp__sub_8329BAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BAB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333CDAC, str_TXT_82038DA0_B_, g_82E730B8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BAB8, 0x8329BAB8) { ctx.r3.u64 = n_sub_8329BAB8(ctx, base); }

uint64_t n_sub_8329BB00(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038DD4_B_ = int32_t(0x82038DD4);
	constexpr int32_t g_82E73618 = int32_t(0x82E73618);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CEC8 = int32_t(0x8333CEC8);
	if (!UseLiftedCode(145, 0x8329BB00)) { __imp__sub_8329BB00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BB00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333CEC8, str_TXT_82038DD4_B_, g_82E73618, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BB00, 0x8329BB00) { ctx.r3.u64 = n_sub_8329BB00(ctx, base); }

uint64_t n_sub_8329BB48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038DF8_B_ = int32_t(0x82038DF8);
	constexpr int32_t g_82E737E0 = int32_t(0x82E737E0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333CFDC = int32_t(0x8333CFDC);
	if (!UseLiftedCode(145, 0x8329BB48)) { __imp__sub_8329BB48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BB48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333CFDC, str_TXT_82038DF8_B_, g_82E737E0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BB48, 0x8329BB48) { ctx.r3.u64 = n_sub_8329BB48(ctx, base); }

uint64_t n_sub_8329BB90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038E1C_B_ = int32_t(0x82038E1C);
	constexpr int32_t g_82E73898 = int32_t(0x82E73898);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D0F0 = int32_t(0x8333D0F0);
	if (!UseLiftedCode(145, 0x8329BB90)) { __imp__sub_8329BB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BB90);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333D0F0, str_TXT_82038E1C_B_, g_82E73898, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2696, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BB90, 0x8329BB90) { ctx.r3.u64 = n_sub_8329BB90(ctx, base); }

uint64_t n_sub_8329BBD8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038E48_B_ = int32_t(0x82038E48);
	constexpr int32_t g_82E73900 = int32_t(0x82E73900);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D204 = int32_t(0x8333D204);
	if (!UseLiftedCode(145, 0x8329BBD8)) { __imp__sub_8329BBD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BBD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333D204, str_TXT_82038E48_B_, g_82E73900, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BBD8, 0x8329BBD8) { ctx.r3.u64 = n_sub_8329BBD8(ctx, base); }

uint64_t n_sub_8329BC20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038E70_B_ = int32_t(0x82038E70);
	constexpr int32_t g_82E739D8 = int32_t(0x82E739D8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D318 = int32_t(0x8333D318);
	if (!UseLiftedCode(145, 0x8329BC20)) { __imp__sub_8329BC20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BC20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333D318, str_TXT_82038E70_B_, g_82E739D8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BC20, 0x8329BC20) { ctx.r3.u64 = n_sub_8329BC20(ctx, base); }

uint64_t n_sub_8329BC68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038E9C_B_ = int32_t(0x82038E9C);
	constexpr int32_t g_82E73AA8 = int32_t(0x82E73AA8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D42C = int32_t(0x8333D42C);
	if (!UseLiftedCode(145, 0x8329BC68)) { __imp__sub_8329BC68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BC68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333D42C, str_TXT_82038E9C_B_, g_82E73AA8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BC68, 0x8329BC68) { ctx.r3.u64 = n_sub_8329BC68(ctx, base); }

uint64_t n_sub_8329BCB0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038EC8_B_ = int32_t(0x82038EC8);
	constexpr int32_t g_82E73B10 = int32_t(0x82E73B10);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D540 = int32_t(0x8333D540);
	if (!UseLiftedCode(145, 0x8329BCB0)) { __imp__sub_8329BCB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BCB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333D540, str_TXT_82038EC8_B_, g_82E73B10, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BCB0, 0x8329BCB0) { ctx.r3.u64 = n_sub_8329BCB0(ctx, base); }

uint64_t n_sub_8329BCF8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038EF8_B_ = int32_t(0x82038EF8);
	constexpr int32_t g_82E73B68 = int32_t(0x82E73B68);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D654 = int32_t(0x8333D654);
	if (!UseLiftedCode(145, 0x8329BCF8)) { __imp__sub_8329BCF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BCF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333D654, str_TXT_82038EF8_B_, g_82E73B68, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2816, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BCF8, 0x8329BCF8) { ctx.r3.u64 = n_sub_8329BCF8(ctx, base); }

uint64_t n_sub_8329BD40(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038F24_B_ = int32_t(0x82038F24);
	constexpr int32_t g_82E73BC0 = int32_t(0x82E73BC0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D768 = int32_t(0x8333D768);
	if (!UseLiftedCode(145, 0x8329BD40)) { __imp__sub_8329BD40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BD40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E77618(ctx, base, g_8333D768, str_TXT_82038F24_B_, g_82E73BC0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2840, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BD40, 0x8329BD40) { ctx.r3.u64 = n_sub_8329BD40(ctx, base); }

uint64_t n_sub_8329BD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82038F48_B_ = int32_t(0x82038F48);
	constexpr int32_t g_82E73C80 = int32_t(0x82E73C80);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8333D87C = int32_t(0x8333D87C);
	if (!UseLiftedCode(145, 0x8329BD88)) { __imp__sub_8329BD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BD88);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E78EB8(ctx, base, g_8333D87C, str_TXT_82038F48_B_, g_82E73C80, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 2864, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329BD88, 0x8329BD88) { ctx.r3.u64 = n_sub_8329BD88(ctx, base); }

uint64_t n_sub_8329BEC0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329BEC0)) { ctx.r8.u64 = arg1; __imp__sub_8329BEC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329BEC0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 3152, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329BEC0, 0x8329BEC0) { ctx.r3.u64 = n_sub_8329BEC0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329C178(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039710_B_ = int32_t(0x82039710);
	constexpr int32_t g_82E84D70 = int32_t(0x82E84D70);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_83342114 = int32_t(0x83342114);
	if (!UseLiftedCode(145, 0x8329C178)) { __imp__sub_8329C178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C178);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E7FA98(ctx, base, g_83342114, str_TXT_82039710_B_, g_82E84D70, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 3496, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C178, 0x8329C178) { ctx.r3.u64 = n_sub_8329C178(ctx, base); }

uint64_t n_sub_8329C1C0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039740_B_ = int32_t(0x82039740);
	constexpr int32_t g_82E85050 = int32_t(0x82E85050);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_83342228 = int32_t(0x83342228);
	if (!UseLiftedCode(145, 0x8329C1C0)) { __imp__sub_8329C1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C1C0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E7FA98(ctx, base, g_83342228, str_TXT_82039740_B_, g_82E85050, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 3520, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C1C0, 0x8329C1C0) { ctx.r3.u64 = n_sub_8329C1C0(ctx, base); }

uint64_t n_sub_8329C208(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039794_B_ = int32_t(0x82039794);
	constexpr int32_t g_82E854E0 = int32_t(0x82E854E0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334233C = int32_t(0x8334233C);
	if (!UseLiftedCode(145, 0x8329C208)) { __imp__sub_8329C208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C208);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E7FA98(ctx, base, g_8334233C, str_TXT_82039794_B_, g_82E854E0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 3544, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C208, 0x8329C208) { ctx.r3.u64 = n_sub_8329C208(ctx, base); }

uint64_t n_sub_8329C6D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039BD8_B_ = int32_t(0x82039BD8);
	constexpr int32_t g_82E92178 = int32_t(0x82E92178);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_83345DD4 = int32_t(0x83345DD4);
	if (!UseLiftedCode(145, 0x8329C6D8)) { __imp__sub_8329C6D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C6D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E832E0(ctx, base, g_83345DD4, str_TXT_82039BD8_B_, g_82E92178, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 4000, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C6D8, 0x8329C6D8) { ctx.r3.u64 = n_sub_8329C6D8(ctx, base); }

uint64_t n_sub_8329C768(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039CF8_B_ = int32_t(0x82039CF8);
	constexpr int32_t g_82E93978 = int32_t(0x82E93978);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_83346114 = int32_t(0x83346114);
	if (!UseLiftedCode(145, 0x8329C768)) { __imp__sub_8329C768(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C768);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E9AD10(ctx, base, g_83346114, str_TXT_82039CF8_B_, g_82E93978, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 4048, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C768, 0x8329C768) { ctx.r3.u64 = n_sub_8329C768(ctx, base); }

uint64_t n_sub_8329C7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_82039D70_B_ = int32_t(0x82039D70);
	constexpr int32_t g_82E946B0 = int32_t(0x82E946B0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334622C = int32_t(0x8334622C);
	if (!UseLiftedCode(145, 0x8329C7B0)) { __imp__sub_8329C7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329C7B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82E9AD10(ctx, base, g_8334622C, str_TXT_82039D70_B_, g_82E946B0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 4072, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329C7B0, 0x8329C7B0) { ctx.r3.u64 = n_sub_8329C7B0(ctx, base); }

uint64_t n_sub_8329CBE8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329CBE8)) { ctx.r8.u64 = arg1; __imp__sub_8329CBE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329CBE8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 4520, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329CBE8, 0x8329CBE8) { ctx.r3.u64 = n_sub_8329CBE8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329D1B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203ACF4_B_ = int32_t(0x8203ACF4);
	constexpr int32_t g_82EB74B8 = int32_t(0x82EB74B8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334C9F0 = int32_t(0x8334C9F0);
	if (!UseLiftedCode(145, 0x8329D1B0)) { __imp__sub_8329D1B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D1B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBEF88(ctx, base, g_8334C9F0, str_TXT_8203ACF4_B_, g_82EB74B8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5336, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D1B0, 0x8329D1B0) { ctx.r3.u64 = n_sub_8329D1B0(ctx, base); }

uint64_t n_sub_8329D1F8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AD40_B_ = int32_t(0x8203AD40);
	constexpr int32_t g_82EB77C0 = int32_t(0x82EB77C0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334CB04 = int32_t(0x8334CB04);
	if (!UseLiftedCode(145, 0x8329D1F8)) { __imp__sub_8329D1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D1F8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF160(ctx, base, g_8334CB04, str_TXT_8203AD40_B_, g_82EB77C0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5360, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D1F8, 0x8329D1F8) { ctx.r3.u64 = n_sub_8329D1F8(ctx, base); }

uint64_t n_sub_8329D240(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AD70_B_ = int32_t(0x8203AD70);
	constexpr int32_t g_82EB79C0 = int32_t(0x82EB79C0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334CC18 = int32_t(0x8334CC18);
	if (!UseLiftedCode(145, 0x8329D240)) { __imp__sub_8329D240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D240);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF160(ctx, base, g_8334CC18, str_TXT_8203AD70_B_, g_82EB79C0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5384, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D240, 0x8329D240) { ctx.r3.u64 = n_sub_8329D240(ctx, base); }

uint64_t n_sub_8329D288(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203ADA8_B_ = int32_t(0x8203ADA8);
	constexpr int32_t g_82EB7EE0 = int32_t(0x82EB7EE0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334CD2C = int32_t(0x8334CD2C);
	if (!UseLiftedCode(145, 0x8329D288)) { __imp__sub_8329D288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D288);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF338(ctx, base, g_8334CD2C, str_TXT_8203ADA8_B_, g_82EB7EE0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5408, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D288, 0x8329D288) { ctx.r3.u64 = n_sub_8329D288(ctx, base); }

uint64_t n_sub_8329D2D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AE54_B_ = int32_t(0x8203AE54);
	constexpr int32_t g_82EB8460 = int32_t(0x82EB8460);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334CE40 = int32_t(0x8334CE40);
	if (!UseLiftedCode(145, 0x8329D2D0)) { __imp__sub_8329D2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF338(ctx, base, g_8334CE40, str_TXT_8203AE54_B_, g_82EB8460, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5432, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D2D0, 0x8329D2D0) { ctx.r3.u64 = n_sub_8329D2D0(ctx, base); }

uint64_t n_sub_8329D318(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AEB0_B_ = int32_t(0x8203AEB0);
	constexpr int32_t g_82EB9128 = int32_t(0x82EB9128);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334CF54 = int32_t(0x8334CF54);
	if (!UseLiftedCode(145, 0x8329D318)) { __imp__sub_8329D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D318);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF510(ctx, base, g_8334CF54, str_TXT_8203AEB0_B_, g_82EB9128, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5456, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D318, 0x8329D318) { ctx.r3.u64 = n_sub_8329D318(ctx, base); }

uint64_t n_sub_8329D360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AF0C_B_ = int32_t(0x8203AF0C);
	constexpr int32_t g_82EB95F8 = int32_t(0x82EB95F8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D06C = int32_t(0x8334D06C);
	if (!UseLiftedCode(145, 0x8329D360)) { __imp__sub_8329D360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D360);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF510(ctx, base, g_8334D06C, str_TXT_8203AF0C_B_, g_82EB95F8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5480, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D360, 0x8329D360) { ctx.r3.u64 = n_sub_8329D360(ctx, base); }

uint64_t n_sub_8329D3E0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AF44_B_ = int32_t(0x8203AF44);
	constexpr int32_t g_82EBA338 = int32_t(0x82EBA338);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D180 = int32_t(0x8334D180);
	if (!UseLiftedCode(145, 0x8329D3E0)) { __imp__sub_8329D3E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D3E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF510(ctx, base, g_8334D180, str_TXT_8203AF44_B_, g_82EBA338, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5504, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D3E0, 0x8329D3E0) { ctx.r3.u64 = n_sub_8329D3E0(ctx, base); }

uint64_t n_sub_8329D428(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AF88_B_ = int32_t(0x8203AF88);
	constexpr int32_t g_82EBA3C8 = int32_t(0x82EBA3C8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D2A4 = int32_t(0x8334D2A4);
	if (!UseLiftedCode(145, 0x8329D428)) { __imp__sub_8329D428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D428);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF6E8(ctx, base, g_8334D2A4, str_TXT_8203AF88_B_, g_82EBA3C8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5528, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D428, 0x8329D428) { ctx.r3.u64 = n_sub_8329D428(ctx, base); }

uint64_t n_sub_8329D470(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AFA8_B_ = int32_t(0x8203AFA8);
	constexpr int32_t g_82EBA530 = int32_t(0x82EBA530);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D3B8 = int32_t(0x8334D3B8);
	if (!UseLiftedCode(145, 0x8329D470)) { __imp__sub_8329D470(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D470);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF6E8(ctx, base, g_8334D3B8, str_TXT_8203AFA8_B_, g_82EBA530, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5552, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D470, 0x8329D470) { ctx.r3.u64 = n_sub_8329D470(ctx, base); }

uint64_t n_sub_8329D4B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AFBC_B_ = int32_t(0x8203AFBC);
	constexpr int32_t g_82EBAF40 = int32_t(0x82EBAF40);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D4CC = int32_t(0x8334D4CC);
	if (!UseLiftedCode(145, 0x8329D4B8)) { __imp__sub_8329D4B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D4B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF8C0(ctx, base, g_8334D4CC, str_TXT_8203AFBC_B_, g_82EBAF40, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5576, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D4B8, 0x8329D4B8) { ctx.r3.u64 = n_sub_8329D4B8(ctx, base); }

uint64_t n_sub_8329D500(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203AFFC_B_ = int32_t(0x8203AFFC);
	constexpr int32_t g_82EBB218 = int32_t(0x82EBB218);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D5E0 = int32_t(0x8334D5E0);
	if (!UseLiftedCode(145, 0x8329D500)) { __imp__sub_8329D500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D500);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF8C0(ctx, base, g_8334D5E0, str_TXT_8203AFFC_B_, g_82EBB218, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5600, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D500, 0x8329D500) { ctx.r3.u64 = n_sub_8329D500(ctx, base); }

uint64_t n_sub_8329D548(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B04C_B_ = int32_t(0x8203B04C);
	constexpr int32_t g_82EBB2F8 = int32_t(0x82EBB2F8);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D6F4 = int32_t(0x8334D6F4);
	if (!UseLiftedCode(145, 0x8329D548)) { __imp__sub_8329D548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D548);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBFA98(ctx, base, g_8334D6F4, str_TXT_8203B04C_B_, g_82EBB2F8, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5624, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D548, 0x8329D548) { ctx.r3.u64 = n_sub_8329D548(ctx, base); }

uint64_t n_sub_8329D590(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B088_B_ = int32_t(0x8203B088);
	constexpr int32_t g_82EBB720 = int32_t(0x82EBB720);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D808 = int32_t(0x8334D808);
	if (!UseLiftedCode(145, 0x8329D590)) { __imp__sub_8329D590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D590);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBFC70(ctx, base, g_8334D808, str_TXT_8203B088_B_, g_82EBB720, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5648, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D590, 0x8329D590) { ctx.r3.u64 = n_sub_8329D590(ctx, base); }

uint64_t n_sub_8329D5D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B0A8_B_ = int32_t(0x8203B0A8);
	constexpr int32_t g_82EBBB40 = int32_t(0x82EBBB40);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334D91C = int32_t(0x8334D91C);
	if (!UseLiftedCode(145, 0x8329D5D8)) { __imp__sub_8329D5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D5D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBFE48(ctx, base, g_8334D91C, str_TXT_8203B0A8_B_, g_82EBBB40, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5672, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D5D8, 0x8329D5D8) { ctx.r3.u64 = n_sub_8329D5D8(ctx, base); }

uint64_t n_sub_8329D670(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B108_B_ = int32_t(0x8203B108);
	constexpr int32_t g_82EBC008 = int32_t(0x82EBC008);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334DB44 = int32_t(0x8334DB44);
	if (!UseLiftedCode(145, 0x8329D670)) { __imp__sub_8329D670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EC0020(ctx, base, g_8334DB44, str_TXT_8203B108_B_, g_82EBC008, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5720, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D670, 0x8329D670) { ctx.r3.u64 = n_sub_8329D670(ctx, base); }

uint64_t n_sub_8329D6B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B144_B_ = int32_t(0x8203B144);
	constexpr int32_t g_82EBC278 = int32_t(0x82EBC278);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334DC58 = int32_t(0x8334DC58);
	if (!UseLiftedCode(145, 0x8329D6B8)) { __imp__sub_8329D6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D6B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EC0020(ctx, base, g_8334DC58, str_TXT_8203B144_B_, g_82EBC278, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5744, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D6B8, 0x8329D6B8) { ctx.r3.u64 = n_sub_8329D6B8(ctx, base); }

uint64_t n_sub_8329D700(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B188_B_ = int32_t(0x8203B188);
	constexpr int32_t g_82EBC930 = int32_t(0x82EBC930);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334DD6C = int32_t(0x8334DD6C);
	if (!UseLiftedCode(145, 0x8329D700)) { __imp__sub_8329D700(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D700);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EC01F8(ctx, base, g_8334DD6C, str_TXT_8203B188_B_, g_82EBC930, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5768, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D700, 0x8329D700) { ctx.r3.u64 = n_sub_8329D700(ctx, base); }

uint64_t n_sub_8329D748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203B1AC_B_ = int32_t(0x8203B1AC);
	constexpr int32_t g_82EBCA30 = int32_t(0x82EBCA30);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_8334DE80 = int32_t(0x8334DE80);
	if (!UseLiftedCode(145, 0x8329D748)) { __imp__sub_8329D748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329D748);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EC01F8(ctx, base, g_8334DE80, str_TXT_8203B1AC_B_, g_82EBCA30, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 5792, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329D748, 0x8329D748) { ctx.r3.u64 = n_sub_8329D748(ctx, base); }

uint64_t n_sub_8329DC38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203BC34_B_ = int32_t(0x8203BC34);
	constexpr int32_t g_82ED49F0 = int32_t(0x82ED49F0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_833587E4 = int32_t(0x833587E4);
	if (!UseLiftedCode(145, 0x8329DC38)) { __imp__sub_8329DC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DC38);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF338(ctx, base, g_833587E4, str_TXT_8203BC34_B_, g_82ED49F0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6176, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329DC38, 0x8329DC38) { ctx.r3.u64 = n_sub_8329DC38(ctx, base); }

uint64_t n_sub_8329DC80(CpuState& ctx, uint8_t* base) {
	constexpr int32_t str_TXT_8203BCF8_B_ = int32_t(0x8203BCF8);
	constexpr int32_t g_82ED5DE0 = int32_t(0x82ED5DE0);
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	constexpr int32_t g_833588F8 = int32_t(0x833588F8);
	if (!UseLiftedCode(145, 0x8329DC80)) { __imp__sub_8329DC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DC80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82EBF338(ctx, base, g_833588F8, str_TXT_8203BCF8_B_, g_82ED5DE0, 0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6200, ctx.r8.u64);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(145, sub_8329DC80, 0x8329DC80) { ctx.r3.u64 = n_sub_8329DC80(ctx, base); }

uint64_t n_sub_8329DE68(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DE68)) { ctx.r8.u64 = arg1; __imp__sub_8329DE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DE68);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6344, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DE68, 0x8329DE68) { ctx.r3.u64 = n_sub_8329DE68(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329DE78(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DE78)) { ctx.r8.u64 = arg1; __imp__sub_8329DE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DE78);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6456, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DE78, 0x8329DE78) { ctx.r3.u64 = n_sub_8329DE78(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329DE88(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DE88)) { ctx.r8.u64 = arg1; __imp__sub_8329DE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DE88);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6480, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DE88, 0x8329DE88) { ctx.r3.u64 = n_sub_8329DE88(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329DE98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DE98)) { ctx.r8.u64 = arg1; __imp__sub_8329DE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DE98);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6592, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DE98, 0x8329DE98) { ctx.r3.u64 = n_sub_8329DE98(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329DEA8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DEA8)) { ctx.r8.u64 = arg1; __imp__sub_8329DEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DEA8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6680, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DEA8, 0x8329DEA8) { ctx.r3.u64 = n_sub_8329DEA8(ctx, base, ctx.r8.u64); }

// sub_8329DF30  [12 bytes]
uint64_t n_sub_8329DF30(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83359494 = int32_t(0x83359494);
	if (!UseLiftedCode(145, 0x8329DF30)) { __imp__sub_8329DF30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DF30);
	return n_sub_82F983E0(ctx, base, g_83359494);
}
PROMOTED_ENTRY(145, sub_8329DF30, 0x8329DF30) { ctx.r3.u64 = n_sub_8329DF30(ctx, base); }

uint64_t n_sub_8329DF40(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DF40)) { ctx.r8.u64 = arg1; __imp__sub_8329DF40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DF40);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 6872, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DF40, 0x8329DF40) { ctx.r3.u64 = n_sub_8329DF40(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329DFA8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329DFA8)) { ctx.r8.u64 = arg1; __imp__sub_8329DFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329DFA8);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 7064, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329DFA8, 0x8329DFA8) { ctx.r3.u64 = n_sub_8329DFA8(ctx, base, ctx.r8.u64); }

// sub_8329E1D8  [52 bytes]
uint64_t n_sub_8329E1D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B340 = int32_t(0x8204B340);
	constexpr int32_t g_833595E8 = int32_t(0x833595E8);
	if (!UseLiftedCode(145, 0x8329E1D8)) { __imp__sub_8329E1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E1D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B340;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_833595E8, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E1D8, 0x8329E1D8) { ctx.r3.u64 = n_sub_8329E1D8(ctx, base); }

uint64_t n_sub_8329E210(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B3AC = int32_t(0x8204B3AC);
	constexpr int32_t g_833595F0 = int32_t(0x833595F0);
	if (!UseLiftedCode(145, 0x8329E210)) { __imp__sub_8329E210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E210);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B3AC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_833595F0, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E210, 0x8329E210) { ctx.r3.u64 = n_sub_8329E210(ctx, base); }

uint64_t n_sub_8329E248(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B798 = int32_t(0x8204B798);
	constexpr int32_t g_833595F8 = int32_t(0x833595F8);
	if (!UseLiftedCode(145, 0x8329E248)) { __imp__sub_8329E248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E248);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B798;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_833595F8, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E248, 0x8329E248) { ctx.r3.u64 = n_sub_8329E248(ctx, base); }

uint64_t n_sub_8329E280(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B828 = int32_t(0x8204B828);
	constexpr int32_t g_83359600 = int32_t(0x83359600);
	if (!UseLiftedCode(145, 0x8329E280)) { __imp__sub_8329E280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E280);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B828;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359600, name, 9);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E280, 0x8329E280) { ctx.r3.u64 = n_sub_8329E280(ctx, base); }

uint64_t n_sub_8329E2B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B990 = int32_t(0x8204B990);
	constexpr int32_t g_83359608 = int32_t(0x83359608);
	if (!UseLiftedCode(145, 0x8329E2B8)) { __imp__sub_8329E2B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E2B8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B990;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359608, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E2B8, 0x8329E2B8) { ctx.r3.u64 = n_sub_8329E2B8(ctx, base); }

uint64_t n_sub_8329E2F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204B9D8 = int32_t(0x8204B9D8);
	constexpr int32_t g_83359610 = int32_t(0x83359610);
	if (!UseLiftedCode(145, 0x8329E2F0)) { __imp__sub_8329E2F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E2F0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204B9D8;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359610, name, 3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E2F0, 0x8329E2F0) { ctx.r3.u64 = n_sub_8329E2F0(ctx, base); }

uint64_t n_sub_8329E328(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BA68 = int32_t(0x8204BA68);
	constexpr int32_t g_83359618 = int32_t(0x83359618);
	if (!UseLiftedCode(145, 0x8329E328)) { __imp__sub_8329E328(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E328);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BA68;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359618, name, 3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E328, 0x8329E328) { ctx.r3.u64 = n_sub_8329E328(ctx, base); }

uint64_t n_sub_8329E360(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BAF8 = int32_t(0x8204BAF8);
	constexpr int32_t g_83359620 = int32_t(0x83359620);
	if (!UseLiftedCode(145, 0x8329E360)) { __imp__sub_8329E360(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E360);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BAF8;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359620, name, 3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E360, 0x8329E360) { ctx.r3.u64 = n_sub_8329E360(ctx, base); }

uint64_t n_sub_8329E398(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BB88 = int32_t(0x8204BB88);
	constexpr int32_t g_83359628 = int32_t(0x83359628);
	if (!UseLiftedCode(145, 0x8329E398)) { __imp__sub_8329E398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E398);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BB88;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359628, name, 11);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E398, 0x8329E398) { ctx.r3.u64 = n_sub_8329E398(ctx, base); }

uint64_t n_sub_8329E3D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BD38 = int32_t(0x8204BD38);
	constexpr int32_t g_83359630 = int32_t(0x83359630);
	if (!UseLiftedCode(145, 0x8329E3D0)) { __imp__sub_8329E3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E3D0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BD38;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359630, name, 4);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E3D0, 0x8329E3D0) { ctx.r3.u64 = n_sub_8329E3D0(ctx, base); }

uint64_t n_sub_8329E408(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BE10 = int32_t(0x8204BE10);
	constexpr int32_t g_83359638 = int32_t(0x83359638);
	if (!UseLiftedCode(145, 0x8329E408)) { __imp__sub_8329E408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E408);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BE10;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359638, name, 11);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E408, 0x8329E408) { ctx.r3.u64 = n_sub_8329E408(ctx, base); }

uint64_t n_sub_8329E440(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204BF9C = int32_t(0x8204BF9C);
	constexpr int32_t g_83359640 = int32_t(0x83359640);
	if (!UseLiftedCode(145, 0x8329E440)) { __imp__sub_8329E440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E440);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204BF9C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359640, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E440, 0x8329E440) { ctx.r3.u64 = n_sub_8329E440(ctx, base); }

uint64_t n_sub_8329E478(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C008 = int32_t(0x8204C008);
	constexpr int32_t g_83359648 = int32_t(0x83359648);
	if (!UseLiftedCode(145, 0x8329E478)) { __imp__sub_8329E478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E478);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C008;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359648, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E478, 0x8329E478) { ctx.r3.u64 = n_sub_8329E478(ctx, base); }

uint64_t n_sub_8329E4B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C050 = int32_t(0x8204C050);
	constexpr int32_t g_83359650 = int32_t(0x83359650);
	if (!UseLiftedCode(145, 0x8329E4B0)) { __imp__sub_8329E4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E4B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C050;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359650, name, 8);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E4B0, 0x8329E4B0) { ctx.r3.u64 = n_sub_8329E4B0(ctx, base); }

uint64_t n_sub_8329E518(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C298 = int32_t(0x8204C298);
	constexpr int32_t g_8335965C = int32_t(0x8335965C);
	if (!UseLiftedCode(145, 0x8329E518)) { __imp__sub_8329E518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E518);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C298;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335965C, name, 10);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E518, 0x8329E518) { ctx.r3.u64 = n_sub_8329E518(ctx, base); }

uint64_t n_sub_8329E6D8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C470 = int32_t(0x8204C470);
	constexpr int32_t g_8335971C = int32_t(0x8335971C);
	if (!UseLiftedCode(145, 0x8329E6D8)) { __imp__sub_8329E6D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E6D8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C470;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335971C, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E6D8, 0x8329E6D8) { ctx.r3.u64 = n_sub_8329E6D8(ctx, base); }

uint64_t n_sub_8329E710(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C494 = int32_t(0x8204C494);
	constexpr int32_t g_83359724 = int32_t(0x83359724);
	if (!UseLiftedCode(145, 0x8329E710)) { __imp__sub_8329E710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E710);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C494;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359724, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E710, 0x8329E710) { ctx.r3.u64 = n_sub_8329E710(ctx, base); }

uint64_t n_sub_8329E748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C4B8 = int32_t(0x8204C4B8);
	constexpr int32_t g_8335972C = int32_t(0x8335972C);
	if (!UseLiftedCode(145, 0x8329E748)) { __imp__sub_8329E748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E748);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C4B8;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335972C, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E748, 0x8329E748) { ctx.r3.u64 = n_sub_8329E748(ctx, base); }

uint64_t n_sub_8329E780(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C4DC = int32_t(0x8204C4DC);
	constexpr int32_t g_83359734 = int32_t(0x83359734);
	if (!UseLiftedCode(145, 0x8329E780)) { __imp__sub_8329E780(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E780);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C4DC;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359734, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E780, 0x8329E780) { ctx.r3.u64 = n_sub_8329E780(ctx, base); }

uint64_t n_sub_8329E7B8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C500 = int32_t(0x8204C500);
	constexpr int32_t g_8335973C = int32_t(0x8335973C);
	if (!UseLiftedCode(145, 0x8329E7B8)) { __imp__sub_8329E7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E7B8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C500;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335973C, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E7B8, 0x8329E7B8) { ctx.r3.u64 = n_sub_8329E7B8(ctx, base); }

uint64_t n_sub_8329E7F0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C524 = int32_t(0x8204C524);
	constexpr int32_t g_83359744 = int32_t(0x83359744);
	if (!UseLiftedCode(145, 0x8329E7F0)) { __imp__sub_8329E7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E7F0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C524;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359744, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E7F0, 0x8329E7F0) { ctx.r3.u64 = n_sub_8329E7F0(ctx, base); }

uint64_t n_sub_8329E828(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C548 = int32_t(0x8204C548);
	constexpr int32_t g_8335974C = int32_t(0x8335974C);
	if (!UseLiftedCode(145, 0x8329E828)) { __imp__sub_8329E828(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E828);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C548;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335974C, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E828, 0x8329E828) { ctx.r3.u64 = n_sub_8329E828(ctx, base); }

uint64_t n_sub_8329E860(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204C56C = int32_t(0x8204C56C);
	constexpr int32_t g_83359754 = int32_t(0x83359754);
	if (!UseLiftedCode(145, 0x8329E860)) { __imp__sub_8329E860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329E860);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204C56C;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359754, name, 1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329E860, 0x8329E860) { ctx.r3.u64 = n_sub_8329E860(ctx, base); }

uint64_t n_sub_8329ECE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204D360 = int32_t(0x8204D360);
	constexpr int32_t g_83359924 = int32_t(0x83359924);
	if (!UseLiftedCode(145, 0x8329ECE8)) { __imp__sub_8329ECE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329ECE8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204D360;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359924, name, 3);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329ECE8, 0x8329ECE8) { ctx.r3.u64 = n_sub_8329ECE8(ctx, base); }

uint64_t n_sub_8329ED20(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204D3F0 = int32_t(0x8204D3F0);
	constexpr int32_t g_8335992C = int32_t(0x8335992C);
	if (!UseLiftedCode(145, 0x8329ED20)) { __imp__sub_8329ED20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329ED20);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204D3F0;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335992C, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329ED20, 0x8329ED20) { ctx.r3.u64 = n_sub_8329ED20(ctx, base); }

uint64_t n_sub_8329ED58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204D4E8 = int32_t(0x8204D4E8);
	constexpr int32_t g_83359934 = int32_t(0x83359934);
	if (!UseLiftedCode(145, 0x8329ED58)) { __imp__sub_8329ED58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329ED58);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204D4E8;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_83359934, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329ED58, 0x8329ED58) { ctx.r3.u64 = n_sub_8329ED58(ctx, base); }

uint64_t n_sub_8329ED90(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8204D578 = int32_t(0x8204D578);
	constexpr int32_t g_8335993C = int32_t(0x8335993C);
	if (!UseLiftedCode(145, 0x8329ED90)) { __imp__sub_8329ED90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329ED90);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	uint64_t name = g_8204D578;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82FFCAE8(ctx, base, g_8335993C, name, 2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return result;
}
PROMOTED_ENTRY(145, sub_8329ED90, 0x8329ED90) { ctx.r3.u64 = n_sub_8329ED90(ctx, base); }

uint64_t n_sub_8329EE70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_8207871C = int32_t(0x8207871C);
	constexpr int32_t str_TXT_8207874C_B_ = int32_t(0x8207874C);
	constexpr int32_t g_8335ACB4 = int32_t(0x8335ACB4);
	constexpr int32_t g_8335B0EC = int32_t(0x8335B0EC);
	if (!UseLiftedCode(145, 0x8329EE70)) { __imp__sub_8329EE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329EE70);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_8207871C;
	uint64_t object = g_8335ACB4;
	uint64_t name = str_TXT_8207874C_B_;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, name, (uint32_t)g_8335B0EC, 8, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = name;
	return object;
}
PROMOTED_ENTRY(145, sub_8329EE70, 0x8329EE70) { ctx.r3.u64 = n_sub_8329EE70(ctx, base); }

uint64_t n_sub_8329F5D0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82078F98 = int32_t(0x82078F98);
	constexpr int32_t str_TXT_82079058_B_ = int32_t(0x82079058);
	constexpr int32_t g_8335AF04 = int32_t(0x8335AF04);
	if (!UseLiftedCode(145, 0x8329F5D0)) { __imp__sub_8329F5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329F5D0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82078F98;
	uint64_t object = g_8335AF04;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82079058_B_, 0, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82079058_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329F5D0, 0x8329F5D0) { ctx.r3.u64 = n_sub_8329F5D0(ctx, base); }

uint64_t n_sub_8329F7B0(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82079434 = int32_t(0x82079434);
	constexpr int32_t str_TXT_820794A8_B_ = int32_t(0x820794A8);
	constexpr int32_t g_8335AFCC = int32_t(0x8335AFCC);
	if (!UseLiftedCode(145, 0x8329F7B0)) { __imp__sub_8329F7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329F7B0);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_82079434;
	uint64_t object = g_8335AFCC;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_820794A8_B_, 0, 16, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_820794A8_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329F7B0, 0x8329F7B0) { ctx.r3.u64 = n_sub_8329F7B0(ctx, base); }

uint64_t n_sub_8329F918(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_820797D8 = int32_t(0x820797D8);
	constexpr int32_t str_TXT_82079808_B_ = int32_t(0x82079808);
	constexpr int32_t g_8335B05C = int32_t(0x8335B05C);
	if (!UseLiftedCode(145, 0x8329F918)) { __imp__sub_8329F918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329F918);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stackArgument84 = (uint32_t)g_820797D8;
	uint64_t object = g_8335B05C;
	STORE32(stack + 84, stackArgument84);
	STORE32(stack + 92, 2u);
	STORE32(stack + 116, 0u);
	STORE32(stack + 108, 0u);
	STORE32(stack + 100, 0u);
	ctx.r1.u64 = stack;
	n_sub_82D4F620(ctx, base, object, (int64_t)str_TXT_82079808_B_, 0, 32, 0, 0, 0);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = (int64_t)str_TXT_82079808_B_;
	return object;
}
PROMOTED_ENTRY(145, sub_8329F918, 0x8329F918) { ctx.r3.u64 = n_sub_8329F918(ctx, base); }

uint64_t n_sub_8329FC80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329FC80)) { ctx.r8.u64 = arg1; __imp__sub_8329FC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FC80);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 8440, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329FC80, 0x8329FC80) { ctx.r3.u64 = n_sub_8329FC80(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329FCE0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_832B0000 = int32_t(0x832B0000);
	if (!UseLiftedCode(145, 0x8329FCE0)) { ctx.r8.u64 = arg1; __imp__sub_8329FCE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FCE0);
	ctx.r11.s64 = g_832B0000;
	uint64_t result = n_sub_82CA3700(ctx, base, (int64_t)g_832B0000 + 8672, arg1);
	return result;
}
PROMOTED_ENTRY(145, sub_8329FCE0, 0x8329FCE0) { ctx.r3.u64 = n_sub_8329FCE0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8329FD28(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970D4_G_ = int32_t(0x834970D4);
	if (!UseLiftedCode(145, 0x8329FD28)) { __imp__sub_8329FD28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD28);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970D4_G_);
}
PROMOTED_ENTRY(145, sub_8329FD28, 0x8329FD28) { ctx.r3.u64 = n_sub_8329FD28(ctx, base); }

uint64_t n_sub_8329FD38(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834970D8 = int32_t(0x834970D8);
	if (!UseLiftedCode(145, 0x8329FD38)) { __imp__sub_8329FD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD38);
	uint64_t object = g_834970D8;
	ctx.r3.u64 = object;
	uint64_t result = n_sub_822F0808(ctx, base);
	return result;
}
PROMOTED_ENTRY(145, sub_8329FD38, 0x8329FD38) { ctx.r3.u64 = n_sub_8329FD38(ctx, base); }

uint64_t n_sub_8329FD48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970E4_G_ = int32_t(0x834970E4);
	if (!UseLiftedCode(145, 0x8329FD48)) { __imp__sub_8329FD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD48);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970E4_G_);
}
PROMOTED_ENTRY(145, sub_8329FD48, 0x8329FD48) { ctx.r3.u64 = n_sub_8329FD48(ctx, base); }

uint64_t n_sub_8329FD58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970E8_G_ = int32_t(0x834970E8);
	if (!UseLiftedCode(145, 0x8329FD58)) { __imp__sub_8329FD58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD58);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970E8_G_);
}
PROMOTED_ENTRY(145, sub_8329FD58, 0x8329FD58) { ctx.r3.u64 = n_sub_8329FD58(ctx, base); }

uint64_t n_sub_8329FD68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970EC_G_ = int32_t(0x834970EC);
	if (!UseLiftedCode(145, 0x8329FD68)) { __imp__sub_8329FD68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD68);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970EC_G_);
}
PROMOTED_ENTRY(145, sub_8329FD68, 0x8329FD68) { ctx.r3.u64 = n_sub_8329FD68(ctx, base); }

uint64_t n_sub_8329FD78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834970F0 = int32_t(0x834970F0);
	if (!UseLiftedCode(145, 0x8329FD78)) { __imp__sub_8329FD78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD78);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, g_834970F0);
}
PROMOTED_ENTRY(145, sub_8329FD78, 0x8329FD78) { ctx.r3.u64 = n_sub_8329FD78(ctx, base); }

uint64_t n_sub_8329FD88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970F4_G_ = int32_t(0x834970F4);
	if (!UseLiftedCode(145, 0x8329FD88)) { __imp__sub_8329FD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD88);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970F4_G_);
}
PROMOTED_ENTRY(145, sub_8329FD88, 0x8329FD88) { ctx.r3.u64 = n_sub_8329FD88(ctx, base); }

uint64_t n_sub_8329FD98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970F8_G_ = int32_t(0x834970F8);
	if (!UseLiftedCode(145, 0x8329FD98)) { __imp__sub_8329FD98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FD98);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970F8_G_);
}
PROMOTED_ENTRY(145, sub_8329FD98, 0x8329FD98) { ctx.r3.u64 = n_sub_8329FD98(ctx, base); }

uint64_t n_sub_8329FDA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970FC_G_ = int32_t(0x834970FC);
	if (!UseLiftedCode(145, 0x8329FDA8)) { __imp__sub_8329FDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FDA8);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_834970FC_G_);
}
PROMOTED_ENTRY(145, sub_8329FDA8, 0x8329FDA8) { ctx.r3.u64 = n_sub_8329FDA8(ctx, base); }

uint64_t n_sub_8329FE48(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497118_G_ = int32_t(0x83497118);
	if (!UseLiftedCode(145, 0x8329FE48)) { __imp__sub_8329FE48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE48);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497118_G_);
}
PROMOTED_ENTRY(145, sub_8329FE48, 0x8329FE48) { ctx.r3.u64 = n_sub_8329FE48(ctx, base); }

uint64_t n_sub_8329FE58(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497170_G_ = int32_t(0x83497170);
	if (!UseLiftedCode(145, 0x8329FE58)) { __imp__sub_8329FE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE58);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497170_G_);
}
PROMOTED_ENTRY(145, sub_8329FE58, 0x8329FE58) { ctx.r3.u64 = n_sub_8329FE58(ctx, base); }

uint64_t n_sub_8329FE68(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497174_G_ = int32_t(0x83497174);
	if (!UseLiftedCode(145, 0x8329FE68)) { __imp__sub_8329FE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE68);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497174_G_);
}
PROMOTED_ENTRY(145, sub_8329FE68, 0x8329FE68) { ctx.r3.u64 = n_sub_8329FE68(ctx, base); }

uint64_t n_sub_8329FE78(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497178_G_ = int32_t(0x83497178);
	if (!UseLiftedCode(145, 0x8329FE78)) { __imp__sub_8329FE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE78);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497178_G_);
}
PROMOTED_ENTRY(145, sub_8329FE78, 0x8329FE78) { ctx.r3.u64 = n_sub_8329FE78(ctx, base); }

uint64_t n_sub_8329FE88(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349717C_G_ = int32_t(0x8349717C);
	if (!UseLiftedCode(145, 0x8329FE88)) { __imp__sub_8329FE88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE88);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_8349717C_G_);
}
PROMOTED_ENTRY(145, sub_8329FE88, 0x8329FE88) { ctx.r3.u64 = n_sub_8329FE88(ctx, base); }

uint64_t n_sub_8329FE98(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497180_G_ = int32_t(0x83497180);
	if (!UseLiftedCode(145, 0x8329FE98)) { __imp__sub_8329FE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FE98);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497180_G_);
}
PROMOTED_ENTRY(145, sub_8329FE98, 0x8329FE98) { ctx.r3.u64 = n_sub_8329FE98(ctx, base); }

uint64_t n_sub_8329FEA8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497188_G_ = int32_t(0x83497188);
	if (!UseLiftedCode(145, 0x8329FEA8)) { __imp__sub_8329FEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FEA8);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497188_G_);
}
PROMOTED_ENTRY(145, sub_8329FEA8, 0x8329FEA8) { ctx.r3.u64 = n_sub_8329FEA8(ctx, base); }

uint64_t n_sub_8329FEB8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349718C_G_ = int32_t(0x8349718C);
	if (!UseLiftedCode(145, 0x8329FEB8)) { __imp__sub_8329FEB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FEB8);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_8349718C_G_);
}
PROMOTED_ENTRY(145, sub_8329FEB8, 0x8329FEB8) { ctx.r3.u64 = n_sub_8329FEB8(ctx, base); }

uint64_t n_sub_8329FEC8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497190_G_ = int32_t(0x83497190);
	if (!UseLiftedCode(145, 0x8329FEC8)) { __imp__sub_8329FEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FEC8);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497190_G_);
}
PROMOTED_ENTRY(145, sub_8329FEC8, 0x8329FEC8) { ctx.r3.u64 = n_sub_8329FEC8(ctx, base); }

uint64_t n_sub_8329FED8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497194_G_ = int32_t(0x83497194);
	if (!UseLiftedCode(145, 0x8329FED8)) { __imp__sub_8329FED8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FED8);
	return CCharString_ReleaseAndDecGlobalCountA(ctx, base, TXT_83497194_G_);
}
PROMOTED_ENTRY(145, sub_8329FED8, 0x8329FED8) { ctx.r3.u64 = n_sub_8329FED8(ctx, base); }

uint64_t n_sub_8329FEE8(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_834971D0 = int32_t(0x834971D0);
	if (!UseLiftedCode(145, 0x8329FEE8)) { __imp__sub_8329FEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8329FEE8);
	return SharedHandle_Release(ctx, base, g_834971D0);
}
PROMOTED_ENTRY(145, sub_8329FEE8, 0x8329FEE8) { ctx.r3.u64 = n_sub_8329FEE8(ctx, base); }
