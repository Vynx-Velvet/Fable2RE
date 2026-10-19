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
#include "lifted/readable_support.h"

// sub_83240410  [64 bytes]
uint64_t n_sub_83240410(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970D4_G_ = int32_t(0x834970D4);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834970D4_G__address = int32_t(0x8329FD28);
	if (!UseLiftedCode(143, 0x83240410)) { __imp__sub_83240410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240410);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_834970D4_G_, str_TXT_820A047C_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_834970D4_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240410, 0x83240410) { ctx.r3.u64 = n_sub_83240410(ctx, base); }

uint64_t Construct_TXT_834970E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970E4_G_ = int32_t(0x834970E4);
	constexpr int32_t str_TXT_820A1684_B_ = int32_t(0x820A1684);
	constexpr int32_t Destroy_TXT_834970E4_G__address = int32_t(0x8329FD48);
	if (!UseLiftedCode(143, 0x83240488)) { __imp__sub_83240488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970E4_G_, str_TXT_820A1684_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970E4_G__address);
}
PROMOTED_ENTRY(143, sub_83240488, 0x83240488) { ctx.r3.u64 = Construct_TXT_834970E4_G_(ctx, base); }

uint64_t Construct_TXT_834970E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970E8_G_ = int32_t(0x834970E8);
	constexpr int32_t str_TXT_820A1690_B_ = int32_t(0x820A1690);
	constexpr int32_t Destroy_TXT_834970E8_G__address = int32_t(0x8329FD58);
	if (!UseLiftedCode(143, 0x832404C8)) { __imp__sub_832404C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832404C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970E8_G_, str_TXT_820A1690_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970E8_G__address);
}
PROMOTED_ENTRY(143, sub_832404C8, 0x832404C8) { ctx.r3.u64 = Construct_TXT_834970E8_G_(ctx, base); }

uint64_t Construct_TXT_834970EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970EC_G_ = int32_t(0x834970EC);
	constexpr int32_t str_TXT_820A16A0_B_ = int32_t(0x820A16A0);
	constexpr int32_t Destroy_TXT_834970EC_G__address = int32_t(0x8329FD68);
	if (!UseLiftedCode(143, 0x83240508)) { __imp__sub_83240508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970EC_G_, str_TXT_820A16A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970EC_G__address);
}
PROMOTED_ENTRY(143, sub_83240508, 0x83240508) { ctx.r3.u64 = Construct_TXT_834970EC_G_(ctx, base); }

uint64_t Construct_TXT_834970F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970F4_G_ = int32_t(0x834970F4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834970F4_G__address = int32_t(0x8329FD88);
	if (!UseLiftedCode(143, 0x83240588)) { __imp__sub_83240588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970F4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970F4_G__address);
}
PROMOTED_ENTRY(143, sub_83240588, 0x83240588) { ctx.r3.u64 = Construct_TXT_834970F4_G_(ctx, base); }

uint64_t Construct_TXT_834970F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970F8_G_ = int32_t(0x834970F8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834970F8_G__address = int32_t(0x8329FD98);
	if (!UseLiftedCode(143, 0x832405C8)) { __imp__sub_832405C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832405C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970F8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970F8_G__address);
}
PROMOTED_ENTRY(143, sub_832405C8, 0x832405C8) { ctx.r3.u64 = Construct_TXT_834970F8_G_(ctx, base); }

uint64_t Construct_TXT_834970FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834970FC_G_ = int32_t(0x834970FC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834970FC_G__address = int32_t(0x8329FDA8);
	if (!UseLiftedCode(143, 0x83240608)) { __imp__sub_83240608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240608);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834970FC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834970FC_G__address);
}
PROMOTED_ENTRY(143, sub_83240608, 0x83240608) { ctx.r3.u64 = Construct_TXT_834970FC_G_(ctx, base); }

uint64_t Construct_TXT_83497118_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497118_G_ = int32_t(0x83497118);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497118_G__address = int32_t(0x8329FE48);
	if (!UseLiftedCode(143, 0x83240708)) { __imp__sub_83240708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497118_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497118_G__address);
}
PROMOTED_ENTRY(143, sub_83240708, 0x83240708) { ctx.r3.u64 = Construct_TXT_83497118_G_(ctx, base); }

uint64_t Construct_TXT_83497170_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497170_G_ = int32_t(0x83497170);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497170_G__address = int32_t(0x8329FE58);
	if (!UseLiftedCode(143, 0x83240BE0)) { __imp__sub_83240BE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240BE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497170_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497170_G__address);
}
PROMOTED_ENTRY(143, sub_83240BE0, 0x83240BE0) { ctx.r3.u64 = Construct_TXT_83497170_G_(ctx, base); }

uint64_t Construct_TXT_83497174_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497174_G_ = int32_t(0x83497174);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497174_G__address = int32_t(0x8329FE68);
	if (!UseLiftedCode(143, 0x83240C20)) { __imp__sub_83240C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240C20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497174_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497174_G__address);
}
PROMOTED_ENTRY(143, sub_83240C20, 0x83240C20) { ctx.r3.u64 = Construct_TXT_83497174_G_(ctx, base); }

uint64_t Construct_TXT_83497178_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497178_G_ = int32_t(0x83497178);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497178_G__address = int32_t(0x8329FE78);
	if (!UseLiftedCode(143, 0x83240C60)) { __imp__sub_83240C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240C60);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497178_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497178_G__address);
}
PROMOTED_ENTRY(143, sub_83240C60, 0x83240C60) { ctx.r3.u64 = Construct_TXT_83497178_G_(ctx, base); }

uint64_t Construct_TXT_8349717C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349717C_G_ = int32_t(0x8349717C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349717C_G__address = int32_t(0x8329FE88);
	if (!UseLiftedCode(143, 0x83240CA0)) { __imp__sub_83240CA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240CA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349717C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349717C_G__address);
}
PROMOTED_ENTRY(143, sub_83240CA0, 0x83240CA0) { ctx.r3.u64 = Construct_TXT_8349717C_G_(ctx, base); }

uint64_t Construct_TXT_83497180_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497180_G_ = int32_t(0x83497180);
	constexpr int32_t str_TXT_820A2E80_B_ = int32_t(0x820A2E80);
	constexpr int32_t Destroy_TXT_83497180_G__address = int32_t(0x8329FE98);
	if (!UseLiftedCode(143, 0x83240CE0)) { __imp__sub_83240CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240CE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497180_G_, str_TXT_820A2E80_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497180_G__address);
}
PROMOTED_ENTRY(143, sub_83240CE0, 0x83240CE0) { ctx.r3.u64 = Construct_TXT_83497180_G_(ctx, base); }

uint64_t Construct_TXT_83497188_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497188_G_ = int32_t(0x83497188);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497188_G__address = int32_t(0x8329FEA8);
	if (!UseLiftedCode(143, 0x83240D58)) { __imp__sub_83240D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240D58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497188_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497188_G__address);
}
PROMOTED_ENTRY(143, sub_83240D58, 0x83240D58) { ctx.r3.u64 = Construct_TXT_83497188_G_(ctx, base); }

uint64_t Construct_TXT_8349718C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349718C_G_ = int32_t(0x8349718C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349718C_G__address = int32_t(0x8329FEB8);
	if (!UseLiftedCode(143, 0x83240D98)) { __imp__sub_83240D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240D98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349718C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349718C_G__address);
}
PROMOTED_ENTRY(143, sub_83240D98, 0x83240D98) { ctx.r3.u64 = Construct_TXT_8349718C_G_(ctx, base); }

uint64_t Construct_TXT_83497190_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497190_G_ = int32_t(0x83497190);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497190_G__address = int32_t(0x8329FEC8);
	if (!UseLiftedCode(143, 0x83240DD8)) { __imp__sub_83240DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240DD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497190_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497190_G__address);
}
PROMOTED_ENTRY(143, sub_83240DD8, 0x83240DD8) { ctx.r3.u64 = Construct_TXT_83497190_G_(ctx, base); }

uint64_t Construct_TXT_83497194_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497194_G_ = int32_t(0x83497194);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497194_G__address = int32_t(0x8329FED8);
	if (!UseLiftedCode(143, 0x83240E18)) { __imp__sub_83240E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240E18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497194_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497194_G__address);
}
PROMOTED_ENTRY(143, sub_83240E18, 0x83240E18) { ctx.r3.u64 = Construct_TXT_83497194_G_(ctx, base); }

// sub_83240EF8  [12 bytes]
uint64_t n_sub_83240EF8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_8329FEE8_address = int32_t(0x8329FEE8);
	if (!UseLiftedCode(143, 0x83240EF8)) { ctx.r8.u64 = callbackArgument; __imp__sub_83240EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240EF8);
	// Register a function to run at exit (n_sub_82CA3700 is atexit); callbackArgument is the caller's r8,
	// passed through.
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, n_sub_8329FEE8_address, callbackArgument);
	return result;
}
PROMOTED_ENTRY(143, sub_83240EF8, 0x83240EF8) { ctx.r3.u64 = n_sub_83240EF8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F08(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_8329FEF8_address = int32_t(0x8329FEF8);
	if (!UseLiftedCode(143, 0x83240F08)) { ctx.r8.u64 = callbackArgument; __imp__sub_83240F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F08);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_8329FEF8_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83240F08, 0x83240F08) { ctx.r3.u64 = n_sub_83240F08(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F18(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_8329FF60_address = int32_t(0x8329FF60);
	if (!UseLiftedCode(143, 0x83240F18)) { ctx.r8.u64 = callbackArgument; __imp__sub_83240F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F18);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_8329FF60_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83240F18, 0x83240F18) { ctx.r3.u64 = n_sub_83240F18(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83240F28(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_8329FFC8_address = int32_t(0x8329FFC8);
	if (!UseLiftedCode(143, 0x83240F28)) { ctx.r8.u64 = callbackArgument; __imp__sub_83240F28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F28);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_8329FFC8_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83240F28, 0x83240F28) { ctx.r3.u64 = n_sub_83240F28(ctx, base, ctx.r8.u64); }

// sub_83240F70  [64 bytes]
uint64_t n_sub_83240F70(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497208_G_ = int32_t(0x83497208);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497208_G__address = int32_t(0x832A0050);
	if (!UseLiftedCode(143, 0x83240F70)) { __imp__sub_83240F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240F70);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497208_G_, str_TXT_820A1900_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83497208_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83240F70, 0x83240F70) { ctx.r3.u64 = n_sub_83240F70(ctx, base); }

uint64_t Construct_TXT_8349720C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349720C_G_ = int32_t(0x8349720C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349720C_G__address = int32_t(0x832A0060);
	if (!UseLiftedCode(143, 0x83240FB0)) { __imp__sub_83240FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240FB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349720C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349720C_G__address);
}
PROMOTED_ENTRY(143, sub_83240FB0, 0x83240FB0) { ctx.r3.u64 = Construct_TXT_8349720C_G_(ctx, base); }

uint64_t Construct_TXT_83497210_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497210_G_ = int32_t(0x83497210);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497210_G__address = int32_t(0x832A0070);
	if (!UseLiftedCode(143, 0x83240FF0)) { __imp__sub_83240FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83240FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497210_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497210_G__address);
}
PROMOTED_ENTRY(143, sub_83240FF0, 0x83240FF0) { ctx.r3.u64 = Construct_TXT_83497210_G_(ctx, base); }

uint64_t Construct_TXT_83497214_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497214_G_ = int32_t(0x83497214);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497214_G__address = int32_t(0x832A0080);
	if (!UseLiftedCode(143, 0x83241030)) { __imp__sub_83241030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241030);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497214_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497214_G__address);
}
PROMOTED_ENTRY(143, sub_83241030, 0x83241030) { ctx.r3.u64 = Construct_TXT_83497214_G_(ctx, base); }

uint64_t Construct_TXT_83497254_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497254_G_ = int32_t(0x83497254);
	constexpr int32_t str_TXT_820A4D58_B_ = int32_t(0x820A4D58);
	constexpr int32_t Destroy_TXT_83497254_G__address = int32_t(0x832A0090);
	if (!UseLiftedCode(143, 0x832413B8)) { __imp__sub_832413B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832413B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497254_G_, str_TXT_820A4D58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497254_G__address);
}
PROMOTED_ENTRY(143, sub_832413B8, 0x832413B8) { ctx.r3.u64 = Construct_TXT_83497254_G_(ctx, base); }

uint64_t Construct_TXT_83497258_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497258_G_ = int32_t(0x83497258);
	constexpr int32_t str_TXT_820A4D64_B_ = int32_t(0x820A4D64);
	constexpr int32_t Destroy_TXT_83497258_G__address = int32_t(0x832A00A0);
	if (!UseLiftedCode(143, 0x832413F8)) { __imp__sub_832413F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832413F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497258_G_, str_TXT_820A4D64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497258_G__address);
}
PROMOTED_ENTRY(143, sub_832413F8, 0x832413F8) { ctx.r3.u64 = Construct_TXT_83497258_G_(ctx, base); }

uint64_t Construct_TXT_8349725C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349725C_G_ = int32_t(0x8349725C);
	constexpr int32_t str_TXT_820A4D7C_B_ = int32_t(0x820A4D7C);
	constexpr int32_t Destroy_TXT_8349725C_G__address = int32_t(0x832A00B0);
	if (!UseLiftedCode(143, 0x83241438)) { __imp__sub_83241438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241438);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349725C_G_, str_TXT_820A4D7C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349725C_G__address);
}
PROMOTED_ENTRY(143, sub_83241438, 0x83241438) { ctx.r3.u64 = Construct_TXT_8349725C_G_(ctx, base); }

uint64_t Construct_TXT_83497260_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497260_G_ = int32_t(0x83497260);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497260_G__address = int32_t(0x832A00C0);
	if (!UseLiftedCode(143, 0x83241478)) { __imp__sub_83241478(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241478);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497260_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497260_G__address);
}
PROMOTED_ENTRY(143, sub_83241478, 0x83241478) { ctx.r3.u64 = Construct_TXT_83497260_G_(ctx, base); }

uint64_t Construct_TXT_83497338_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497338_G_ = int32_t(0x83497338);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497338_G__address = int32_t(0x832A01A0);
	if (!UseLiftedCode(143, 0x83241C40)) { __imp__sub_83241C40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241C40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497338_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497338_G__address);
}
PROMOTED_ENTRY(143, sub_83241C40, 0x83241C40) { ctx.r3.u64 = Construct_TXT_83497338_G_(ctx, base); }

uint64_t Construct_TXT_8349733C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349733C_G_ = int32_t(0x8349733C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349733C_G__address = int32_t(0x832A01B0);
	if (!UseLiftedCode(143, 0x83241C80)) { __imp__sub_83241C80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241C80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349733C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349733C_G__address);
}
PROMOTED_ENTRY(143, sub_83241C80, 0x83241C80) { ctx.r3.u64 = Construct_TXT_8349733C_G_(ctx, base); }

uint64_t Construct_TXT_83497340_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497340_G_ = int32_t(0x83497340);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497340_G__address = int32_t(0x832A01C0);
	if (!UseLiftedCode(143, 0x83241CC0)) { __imp__sub_83241CC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241CC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497340_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497340_G__address);
}
PROMOTED_ENTRY(143, sub_83241CC0, 0x83241CC0) { ctx.r3.u64 = Construct_TXT_83497340_G_(ctx, base); }

uint64_t Construct_TXT_83497344_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497344_G_ = int32_t(0x83497344);
	constexpr int32_t str_TXT_820A5940_B_ = int32_t(0x820A5940);
	constexpr int32_t Destroy_TXT_83497344_G__address = int32_t(0x832A01D0);
	if (!UseLiftedCode(143, 0x83241D00)) { __imp__sub_83241D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497344_G_, str_TXT_820A5940_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497344_G__address);
}
PROMOTED_ENTRY(143, sub_83241D00, 0x83241D00) { ctx.r3.u64 = Construct_TXT_83497344_G_(ctx, base); }

uint64_t Construct_TXT_83497348_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497348_G_ = int32_t(0x83497348);
	constexpr int32_t str_TXT_820A5950_B_ = int32_t(0x820A5950);
	constexpr int32_t Destroy_TXT_83497348_G__address = int32_t(0x832A01E0);
	if (!UseLiftedCode(143, 0x83241D40)) { __imp__sub_83241D40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497348_G_, str_TXT_820A5950_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497348_G__address);
}
PROMOTED_ENTRY(143, sub_83241D40, 0x83241D40) { ctx.r3.u64 = Construct_TXT_83497348_G_(ctx, base); }

uint64_t Construct_TXT_8349734C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349734C_G_ = int32_t(0x8349734C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349734C_G__address = int32_t(0x832A01F8);
	if (!UseLiftedCode(143, 0x83241D80)) { __imp__sub_83241D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241D80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349734C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349734C_G__address);
}
PROMOTED_ENTRY(143, sub_83241D80, 0x83241D80) { ctx.r3.u64 = Construct_TXT_8349734C_G_(ctx, base); }

uint64_t Construct_TXT_8349736C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349736C_G_ = int32_t(0x8349736C);
	constexpr int32_t str_TXT_820A6114_B_ = int32_t(0x820A6114);
	constexpr int32_t Destroy_TXT_8349736C_G__address = int32_t(0x832A0210);
	if (!UseLiftedCode(143, 0x83241DF8)) { __imp__sub_83241DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349736C_G_, str_TXT_820A6114_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349736C_G__address);
}
PROMOTED_ENTRY(143, sub_83241DF8, 0x83241DF8) { ctx.r3.u64 = Construct_TXT_8349736C_G_(ctx, base); }

uint64_t Construct_TXT_83497370_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497370_G_ = int32_t(0x83497370);
	constexpr int32_t str_TXT_820A6238_B_ = int32_t(0x820A6238);
	constexpr int32_t Destroy_TXT_83497370_G__address = int32_t(0x832A0220);
	if (!UseLiftedCode(143, 0x83241E38)) { __imp__sub_83241E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497370_G_, str_TXT_820A6238_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497370_G__address);
}
PROMOTED_ENTRY(143, sub_83241E38, 0x83241E38) { ctx.r3.u64 = Construct_TXT_83497370_G_(ctx, base); }

uint64_t Construct_TXT_83497374_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497374_G_ = int32_t(0x83497374);
	constexpr int32_t str_TXT_820A6254_B_ = int32_t(0x820A6254);
	constexpr int32_t Destroy_TXT_83497374_G__address = int32_t(0x832A0230);
	if (!UseLiftedCode(143, 0x83241E78)) { __imp__sub_83241E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497374_G_, str_TXT_820A6254_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497374_G__address);
}
PROMOTED_ENTRY(143, sub_83241E78, 0x83241E78) { ctx.r3.u64 = Construct_TXT_83497374_G_(ctx, base); }

uint64_t Construct_TXT_83497378_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497378_G_ = int32_t(0x83497378);
	constexpr int32_t str_TXT_820A6268_B_ = int32_t(0x820A6268);
	constexpr int32_t Destroy_TXT_83497378_G__address = int32_t(0x832A0240);
	if (!UseLiftedCode(143, 0x83241EB8)) { __imp__sub_83241EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497378_G_, str_TXT_820A6268_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497378_G__address);
}
PROMOTED_ENTRY(143, sub_83241EB8, 0x83241EB8) { ctx.r3.u64 = Construct_TXT_83497378_G_(ctx, base); }

uint64_t Construct_TXT_8349737C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349737C_G_ = int32_t(0x8349737C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349737C_G__address = int32_t(0x832A0250);
	if (!UseLiftedCode(143, 0x83241EF8)) { __imp__sub_83241EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349737C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349737C_G__address);
}
PROMOTED_ENTRY(143, sub_83241EF8, 0x83241EF8) { ctx.r3.u64 = Construct_TXT_8349737C_G_(ctx, base); }

uint64_t Construct_TXT_83497380_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497380_G_ = int32_t(0x83497380);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497380_G__address = int32_t(0x832A0260);
	if (!UseLiftedCode(143, 0x83241F38)) { __imp__sub_83241F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497380_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497380_G__address);
}
PROMOTED_ENTRY(143, sub_83241F38, 0x83241F38) { ctx.r3.u64 = Construct_TXT_83497380_G_(ctx, base); }

uint64_t Construct_TXT_83497384_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497384_G_ = int32_t(0x83497384);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497384_G__address = int32_t(0x832A0270);
	if (!UseLiftedCode(143, 0x83241F78)) { __imp__sub_83241F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497384_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497384_G__address);
}
PROMOTED_ENTRY(143, sub_83241F78, 0x83241F78) { ctx.r3.u64 = Construct_TXT_83497384_G_(ctx, base); }

uint64_t Construct_TXT_83497388_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497388_G_ = int32_t(0x83497388);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497388_G__address = int32_t(0x832A0290);
	if (!UseLiftedCode(143, 0x83241FB8)) { __imp__sub_83241FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497388_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497388_G__address);
}
PROMOTED_ENTRY(143, sub_83241FB8, 0x83241FB8) { ctx.r3.u64 = Construct_TXT_83497388_G_(ctx, base); }

uint64_t Construct_TXT_8349738C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349738C_G_ = int32_t(0x8349738C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349738C_G__address = int32_t(0x832A02A0);
	if (!UseLiftedCode(143, 0x83241FF8)) { __imp__sub_83241FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83241FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349738C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349738C_G__address);
}
PROMOTED_ENTRY(143, sub_83241FF8, 0x83241FF8) { ctx.r3.u64 = Construct_TXT_8349738C_G_(ctx, base); }

uint64_t Construct_TXT_83497390_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497390_G_ = int32_t(0x83497390);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497390_G__address = int32_t(0x832A02B0);
	if (!UseLiftedCode(143, 0x83242038)) { __imp__sub_83242038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497390_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497390_G__address);
}
PROMOTED_ENTRY(143, sub_83242038, 0x83242038) { ctx.r3.u64 = Construct_TXT_83497390_G_(ctx, base); }

uint64_t Construct_TXT_83497394_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497394_G_ = int32_t(0x83497394);
	constexpr int32_t str_TXT_820A6968_B_ = int32_t(0x820A6968);
	constexpr int32_t Destroy_TXT_83497394_G__address = int32_t(0x832A02C0);
	if (!UseLiftedCode(143, 0x83242078)) { __imp__sub_83242078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497394_G_, str_TXT_820A6968_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497394_G__address);
}
PROMOTED_ENTRY(143, sub_83242078, 0x83242078) { ctx.r3.u64 = Construct_TXT_83497394_G_(ctx, base); }

uint64_t Construct_TXT_83497398_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497398_G_ = int32_t(0x83497398);
	constexpr int32_t str_TXT_820A6A88_B_ = int32_t(0x820A6A88);
	constexpr int32_t Destroy_TXT_83497398_G__address = int32_t(0x832A02D0);
	if (!UseLiftedCode(143, 0x832420B8)) { __imp__sub_832420B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832420B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497398_G_, str_TXT_820A6A88_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497398_G__address);
}
PROMOTED_ENTRY(143, sub_832420B8, 0x832420B8) { ctx.r3.u64 = Construct_TXT_83497398_G_(ctx, base); }

uint64_t Construct_TXT_8349739C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349739C_G_ = int32_t(0x8349739C);
	constexpr int32_t str_TXT_820A6A90_B_ = int32_t(0x820A6A90);
	constexpr int32_t Destroy_TXT_8349739C_G__address = int32_t(0x832A02E0);
	if (!UseLiftedCode(143, 0x832420F8)) { __imp__sub_832420F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832420F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349739C_G_, str_TXT_820A6A90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349739C_G__address);
}
PROMOTED_ENTRY(143, sub_832420F8, 0x832420F8) { ctx.r3.u64 = Construct_TXT_8349739C_G_(ctx, base); }

uint64_t Construct_TXT_834973A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A0_G_ = int32_t(0x834973A0);
	constexpr int32_t str_TXT_820A6AA4_B_ = int32_t(0x820A6AA4);
	constexpr int32_t Destroy_TXT_834973A0_G__address = int32_t(0x832A02F0);
	if (!UseLiftedCode(143, 0x83242138)) { __imp__sub_83242138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A0_G_, str_TXT_820A6AA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973A0_G__address);
}
PROMOTED_ENTRY(143, sub_83242138, 0x83242138) { ctx.r3.u64 = Construct_TXT_834973A0_G_(ctx, base); }

uint64_t Construct_TXT_834973A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A4_G_ = int32_t(0x834973A4);
	constexpr int32_t str_TXT_820A6ABC_B_ = int32_t(0x820A6ABC);
	constexpr int32_t Destroy_TXT_834973A4_G__address = int32_t(0x832A0300);
	if (!UseLiftedCode(143, 0x83242178)) { __imp__sub_83242178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242178);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A4_G_, str_TXT_820A6ABC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973A4_G__address);
}
PROMOTED_ENTRY(143, sub_83242178, 0x83242178) { ctx.r3.u64 = Construct_TXT_834973A4_G_(ctx, base); }

uint64_t Construct_TXT_834973A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973A8_G_ = int32_t(0x834973A8);
	constexpr int32_t str_TXT_820A6AD4_B_ = int32_t(0x820A6AD4);
	constexpr int32_t Destroy_TXT_834973A8_G__address = int32_t(0x832A0310);
	if (!UseLiftedCode(143, 0x832421B8)) { __imp__sub_832421B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832421B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973A8_G_, str_TXT_820A6AD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973A8_G__address);
}
PROMOTED_ENTRY(143, sub_832421B8, 0x832421B8) { ctx.r3.u64 = Construct_TXT_834973A8_G_(ctx, base); }

uint64_t Construct_TXT_834973AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973AC_G_ = int32_t(0x834973AC);
	constexpr int32_t str_TXT_820A6AEC_B_ = int32_t(0x820A6AEC);
	constexpr int32_t Destroy_TXT_834973AC_G__address = int32_t(0x832A0320);
	if (!UseLiftedCode(143, 0x832421F8)) { __imp__sub_832421F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832421F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973AC_G_, str_TXT_820A6AEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973AC_G__address);
}
PROMOTED_ENTRY(143, sub_832421F8, 0x832421F8) { ctx.r3.u64 = Construct_TXT_834973AC_G_(ctx, base); }

uint64_t Construct_TXT_834973B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973B0_G_ = int32_t(0x834973B0);
	constexpr int32_t str_TXT_820A6AF8_B_ = int32_t(0x820A6AF8);
	constexpr int32_t Destroy_TXT_834973B0_G__address = int32_t(0x832A0330);
	if (!UseLiftedCode(143, 0x83242238)) { __imp__sub_83242238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973B0_G_, str_TXT_820A6AF8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973B0_G__address);
}
PROMOTED_ENTRY(143, sub_83242238, 0x83242238) { ctx.r3.u64 = Construct_TXT_834973B0_G_(ctx, base); }

uint64_t Construct_TXT_834973C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C0_G_ = int32_t(0x834973C0);
	constexpr int32_t str_TXT_820A6268_B_ = int32_t(0x820A6268);
	constexpr int32_t Destroy_TXT_834973C0_G__address = int32_t(0x832A0370);
	if (!UseLiftedCode(143, 0x83242308)) { __imp__sub_83242308(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242308);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C0_G_, str_TXT_820A6268_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973C0_G__address);
}
PROMOTED_ENTRY(143, sub_83242308, 0x83242308) { ctx.r3.u64 = Construct_TXT_834973C0_G_(ctx, base); }

uint64_t Construct_TXT_834973C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C4_G_ = int32_t(0x834973C4);
	constexpr int32_t str_TXT_820A6B04_B_ = int32_t(0x820A6B04);
	constexpr int32_t Destroy_TXT_834973C4_G__address = int32_t(0x832A0380);
	if (!UseLiftedCode(143, 0x83242348)) { __imp__sub_83242348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C4_G_, str_TXT_820A6B04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973C4_G__address);
}
PROMOTED_ENTRY(143, sub_83242348, 0x83242348) { ctx.r3.u64 = Construct_TXT_834973C4_G_(ctx, base); }

uint64_t Construct_TXT_834973C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973C8_G_ = int32_t(0x834973C8);
	constexpr int32_t str_TXT_820A6B10_B_ = int32_t(0x820A6B10);
	constexpr int32_t Destroy_TXT_834973C8_G__address = int32_t(0x832A0390);
	if (!UseLiftedCode(143, 0x83242388)) { __imp__sub_83242388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973C8_G_, str_TXT_820A6B10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973C8_G__address);
}
PROMOTED_ENTRY(143, sub_83242388, 0x83242388) { ctx.r3.u64 = Construct_TXT_834973C8_G_(ctx, base); }

uint64_t Construct_TXT_834973CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973CC_G_ = int32_t(0x834973CC);
	constexpr int32_t str_TXT_820A6B2C_B_ = int32_t(0x820A6B2C);
	constexpr int32_t Destroy_TXT_834973CC_G__address = int32_t(0x832A03A0);
	if (!UseLiftedCode(143, 0x832423C8)) { __imp__sub_832423C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832423C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973CC_G_, str_TXT_820A6B2C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973CC_G__address);
}
PROMOTED_ENTRY(143, sub_832423C8, 0x832423C8) { ctx.r3.u64 = Construct_TXT_834973CC_G_(ctx, base); }

uint64_t Construct_TXT_834973D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D0_G_ = int32_t(0x834973D0);
	constexpr int32_t str_TXT_820A6B3C_B_ = int32_t(0x820A6B3C);
	constexpr int32_t Destroy_TXT_834973D0_G__address = int32_t(0x832A03B0);
	if (!UseLiftedCode(143, 0x83242408)) { __imp__sub_83242408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D0_G_, str_TXT_820A6B3C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973D0_G__address);
}
PROMOTED_ENTRY(143, sub_83242408, 0x83242408) { ctx.r3.u64 = Construct_TXT_834973D0_G_(ctx, base); }

uint64_t Construct_TXT_834973D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D4_G_ = int32_t(0x834973D4);
	constexpr int32_t str_TXT_820A6B50_B_ = int32_t(0x820A6B50);
	constexpr int32_t Destroy_TXT_834973D4_G__address = int32_t(0x832A03C0);
	if (!UseLiftedCode(143, 0x83242448)) { __imp__sub_83242448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D4_G_, str_TXT_820A6B50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973D4_G__address);
}
PROMOTED_ENTRY(143, sub_83242448, 0x83242448) { ctx.r3.u64 = Construct_TXT_834973D4_G_(ctx, base); }

uint64_t Construct_TXT_834973D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973D8_G_ = int32_t(0x834973D8);
	constexpr int32_t str_TXT_820A6B74_B_ = int32_t(0x820A6B74);
	constexpr int32_t Destroy_TXT_834973D8_G__address = int32_t(0x832A03D0);
	if (!UseLiftedCode(143, 0x83242488)) { __imp__sub_83242488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973D8_G_, str_TXT_820A6B74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973D8_G__address);
}
PROMOTED_ENTRY(143, sub_83242488, 0x83242488) { ctx.r3.u64 = Construct_TXT_834973D8_G_(ctx, base); }

uint64_t Construct_TXT_834973DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973DC_G_ = int32_t(0x834973DC);
	constexpr int32_t str_TXT_820A6B50_B_ = int32_t(0x820A6B50);
	constexpr int32_t Destroy_TXT_834973DC_G__address = int32_t(0x832A03E0);
	if (!UseLiftedCode(143, 0x832424C8)) { __imp__sub_832424C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832424C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973DC_G_, str_TXT_820A6B50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973DC_G__address);
}
PROMOTED_ENTRY(143, sub_832424C8, 0x832424C8) { ctx.r3.u64 = Construct_TXT_834973DC_G_(ctx, base); }

uint64_t Construct_TXT_834973E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973E0_G_ = int32_t(0x834973E0);
	constexpr int32_t str_TXT_820A6B74_B_ = int32_t(0x820A6B74);
	constexpr int32_t Destroy_TXT_834973E0_G__address = int32_t(0x832A03F0);
	if (!UseLiftedCode(143, 0x83242508)) { __imp__sub_83242508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973E0_G_, str_TXT_820A6B74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973E0_G__address);
}
PROMOTED_ENTRY(143, sub_83242508, 0x83242508) { ctx.r3.u64 = Construct_TXT_834973E0_G_(ctx, base); }

uint64_t Construct_TXT_834973E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834973E8_G_ = int32_t(0x834973E8);
	constexpr int32_t str_TXT_820A6B94_B_ = int32_t(0x820A6B94);
	constexpr int32_t Destroy_TXT_834973E8_G__address = int32_t(0x832A0410);
	if (!UseLiftedCode(143, 0x83242578)) { __imp__sub_83242578(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242578);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834973E8_G_, str_TXT_820A6B94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834973E8_G__address);
}
PROMOTED_ENTRY(143, sub_83242578, 0x83242578) { ctx.r3.u64 = Construct_TXT_834973E8_G_(ctx, base); }

// sub_832425E8  [12 bytes]
uint64_t n_sub_832425E8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0430_address = int32_t(0x832A0430);
	if (!UseLiftedCode(143, 0x832425E8)) { ctx.r8.u64 = callbackArgument; __imp__sub_832425E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832425E8);
	// Register a function to run at exit (n_sub_82CA3700 is atexit); callbackArgument is the caller's r8,
	// passed through.
	ctx.r11.s64 = g_832A0000;
	uint64_t result = n_sub_82CA3700(ctx, base, n_sub_832A0430_address, callbackArgument);
	return result;
}
PROMOTED_ENTRY(143, sub_832425E8, 0x832425E8) { ctx.r3.u64 = n_sub_832425E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_832425F8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0440_address = int32_t(0x832A0440);
	if (!UseLiftedCode(143, 0x832425F8)) { ctx.r8.u64 = callbackArgument; __imp__sub_832425F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832425F8);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0440_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_832425F8, 0x832425F8) { ctx.r3.u64 = n_sub_832425F8(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_8349741C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349741C_G_ = int32_t(0x8349741C);
	constexpr int32_t str_TXT_820A708C_B_ = int32_t(0x820A708C);
	constexpr int32_t Destroy_TXT_8349741C_G__address = int32_t(0x832A0498);
	if (!UseLiftedCode(143, 0x83242798)) { __imp__sub_83242798(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242798);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349741C_G_, str_TXT_820A708C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349741C_G__address);
}
PROMOTED_ENTRY(143, sub_83242798, 0x83242798) { ctx.r3.u64 = Construct_TXT_8349741C_G_(ctx, base); }

uint64_t Construct_TXT_83497428_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497428_G_ = int32_t(0x83497428);
	constexpr int32_t str_TXT_820A6B04_B_ = int32_t(0x820A6B04);
	constexpr int32_t Destroy_TXT_83497428_G__address = int32_t(0x832A04A8);
	if (!UseLiftedCode(143, 0x832427D8)) { __imp__sub_832427D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832427D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497428_G_, str_TXT_820A6B04_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497428_G__address);
}
PROMOTED_ENTRY(143, sub_832427D8, 0x832427D8) { ctx.r3.u64 = Construct_TXT_83497428_G_(ctx, base); }

uint64_t Construct_TXT_8349742C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349742C_G_ = int32_t(0x8349742C);
	constexpr int32_t str_TXT_820A70A4_B_ = int32_t(0x820A70A4);
	constexpr int32_t Destroy_TXT_8349742C_G__address = int32_t(0x832A04B8);
	if (!UseLiftedCode(143, 0x83242818)) { __imp__sub_83242818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242818);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349742C_G_, str_TXT_820A70A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349742C_G__address);
}
PROMOTED_ENTRY(143, sub_83242818, 0x83242818) { ctx.r3.u64 = Construct_TXT_8349742C_G_(ctx, base); }

uint64_t Construct_TXT_83497460_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497460_G_ = int32_t(0x83497460);
	constexpr int32_t str_TXT_820A0438_B_ = int32_t(0x820A0438);
	constexpr int32_t Destroy_TXT_83497460_G__address = int32_t(0x832A04C8);
	if (!UseLiftedCode(143, 0x83242858)) { __imp__sub_83242858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242858);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497460_G_, str_TXT_820A0438_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497460_G__address);
}
PROMOTED_ENTRY(143, sub_83242858, 0x83242858) { ctx.r3.u64 = Construct_TXT_83497460_G_(ctx, base); }

uint64_t Construct_TXT_83497464_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497464_G_ = int32_t(0x83497464);
	constexpr int32_t str_TXT_820A70C4_B_ = int32_t(0x820A70C4);
	constexpr int32_t Destroy_TXT_83497464_G__address = int32_t(0x832A04D8);
	if (!UseLiftedCode(143, 0x83242898)) { __imp__sub_83242898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242898);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497464_G_, str_TXT_820A70C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497464_G__address);
}
PROMOTED_ENTRY(143, sub_83242898, 0x83242898) { ctx.r3.u64 = Construct_TXT_83497464_G_(ctx, base); }

uint64_t Construct_TXT_83497468_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497468_G_ = int32_t(0x83497468);
	constexpr int32_t str_TXT_820A70F0_B_ = int32_t(0x820A70F0);
	constexpr int32_t Destroy_TXT_83497468_G__address = int32_t(0x832A04E8);
	if (!UseLiftedCode(143, 0x832428D8)) { __imp__sub_832428D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832428D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497468_G_, str_TXT_820A70F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497468_G__address);
}
PROMOTED_ENTRY(143, sub_832428D8, 0x832428D8) { ctx.r3.u64 = Construct_TXT_83497468_G_(ctx, base); }

uint64_t Construct_TXT_8349746C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349746C_G_ = int32_t(0x8349746C);
	constexpr int32_t str_TXT_820A7118_B_ = int32_t(0x820A7118);
	constexpr int32_t Destroy_TXT_8349746C_G__address = int32_t(0x832A04F8);
	if (!UseLiftedCode(143, 0x83242918)) { __imp__sub_83242918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242918);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349746C_G_, str_TXT_820A7118_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349746C_G__address);
}
PROMOTED_ENTRY(143, sub_83242918, 0x83242918) { ctx.r3.u64 = Construct_TXT_8349746C_G_(ctx, base); }

uint64_t Construct_TXT_83497470_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497470_G_ = int32_t(0x83497470);
	constexpr int32_t str_TXT_820A7140_B_ = int32_t(0x820A7140);
	constexpr int32_t Destroy_TXT_83497470_G__address = int32_t(0x832A0508);
	if (!UseLiftedCode(143, 0x83242958)) { __imp__sub_83242958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242958);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497470_G_, str_TXT_820A7140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497470_G__address);
}
PROMOTED_ENTRY(143, sub_83242958, 0x83242958) { ctx.r3.u64 = Construct_TXT_83497470_G_(ctx, base); }

uint64_t Construct_TXT_83497474_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497474_G_ = int32_t(0x83497474);
	constexpr int32_t str_TXT_820A7170_B_ = int32_t(0x820A7170);
	constexpr int32_t Destroy_TXT_83497474_G__address = int32_t(0x832A0518);
	if (!UseLiftedCode(143, 0x83242998)) { __imp__sub_83242998(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242998);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497474_G_, str_TXT_820A7170_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497474_G__address);
}
PROMOTED_ENTRY(143, sub_83242998, 0x83242998) { ctx.r3.u64 = Construct_TXT_83497474_G_(ctx, base); }

uint64_t Construct_TXT_83497478_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497478_G_ = int32_t(0x83497478);
	constexpr int32_t str_TXT_820A719C_B_ = int32_t(0x820A719C);
	constexpr int32_t Destroy_TXT_83497478_G__address = int32_t(0x832A0528);
	if (!UseLiftedCode(143, 0x832429D8)) { __imp__sub_832429D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832429D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497478_G_, str_TXT_820A719C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497478_G__address);
}
PROMOTED_ENTRY(143, sub_832429D8, 0x832429D8) { ctx.r3.u64 = Construct_TXT_83497478_G_(ctx, base); }

uint64_t Construct_TXT_8349747C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349747C_G_ = int32_t(0x8349747C);
	constexpr int32_t str_TXT_820A71C8_B_ = int32_t(0x820A71C8);
	constexpr int32_t Destroy_TXT_8349747C_G__address = int32_t(0x832A0538);
	if (!UseLiftedCode(143, 0x83242A18)) { __imp__sub_83242A18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349747C_G_, str_TXT_820A71C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349747C_G__address);
}
PROMOTED_ENTRY(143, sub_83242A18, 0x83242A18) { ctx.r3.u64 = Construct_TXT_8349747C_G_(ctx, base); }

uint64_t Construct_TXT_83497480_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497480_G_ = int32_t(0x83497480);
	constexpr int32_t str_TXT_820A71F4_B_ = int32_t(0x820A71F4);
	constexpr int32_t Destroy_TXT_83497480_G__address = int32_t(0x832A0548);
	if (!UseLiftedCode(143, 0x83242A58)) { __imp__sub_83242A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A58);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497480_G_, str_TXT_820A71F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497480_G__address);
}
PROMOTED_ENTRY(143, sub_83242A58, 0x83242A58) { ctx.r3.u64 = Construct_TXT_83497480_G_(ctx, base); }

uint64_t Construct_TXT_83497484_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497484_G_ = int32_t(0x83497484);
	constexpr int32_t str_TXT_820A7220_B_ = int32_t(0x820A7220);
	constexpr int32_t Destroy_TXT_83497484_G__address = int32_t(0x832A0558);
	if (!UseLiftedCode(143, 0x83242A98)) { __imp__sub_83242A98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242A98);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497484_G_, str_TXT_820A7220_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497484_G__address);
}
PROMOTED_ENTRY(143, sub_83242A98, 0x83242A98) { ctx.r3.u64 = Construct_TXT_83497484_G_(ctx, base); }

uint64_t Construct_TXT_83497488_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497488_G_ = int32_t(0x83497488);
	constexpr int32_t str_TXT_820A724C_B_ = int32_t(0x820A724C);
	constexpr int32_t Destroy_TXT_83497488_G__address = int32_t(0x832A0568);
	if (!UseLiftedCode(143, 0x83242AD8)) { __imp__sub_83242AD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242AD8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497488_G_, str_TXT_820A724C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497488_G__address);
}
PROMOTED_ENTRY(143, sub_83242AD8, 0x83242AD8) { ctx.r3.u64 = Construct_TXT_83497488_G_(ctx, base); }

uint64_t Construct_TXT_8349748C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349748C_G_ = int32_t(0x8349748C);
	constexpr int32_t str_TXT_820A7278_B_ = int32_t(0x820A7278);
	constexpr int32_t Destroy_TXT_8349748C_G__address = int32_t(0x832A0578);
	if (!UseLiftedCode(143, 0x83242B18)) { __imp__sub_83242B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242B18);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349748C_G_, str_TXT_820A7278_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349748C_G__address);
}
PROMOTED_ENTRY(143, sub_83242B18, 0x83242B18) { ctx.r3.u64 = Construct_TXT_8349748C_G_(ctx, base); }

uint64_t Construct_TXT_834974B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974B0_G_ = int32_t(0x834974B0);
	constexpr int32_t str_TXT_820A72A8_B_ = int32_t(0x820A72A8);
	constexpr int32_t Destroy_TXT_834974B0_G__address = int32_t(0x832A0588);
	if (!UseLiftedCode(143, 0x83242C10)) { __imp__sub_83242C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242C10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974B0_G_, str_TXT_820A72A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974B0_G__address);
}
PROMOTED_ENTRY(143, sub_83242C10, 0x83242C10) { ctx.r3.u64 = Construct_TXT_834974B0_G_(ctx, base); }

uint64_t Construct_TXT_834974B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974B4_G_ = int32_t(0x834974B4);
	constexpr int32_t str_TXT_820A72D8_B_ = int32_t(0x820A72D8);
	constexpr int32_t Destroy_TXT_834974B4_G__address = int32_t(0x832A0598);
	if (!UseLiftedCode(143, 0x83242C50)) { __imp__sub_83242C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242C50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974B4_G_, str_TXT_820A72D8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974B4_G__address);
}
PROMOTED_ENTRY(143, sub_83242C50, 0x83242C50) { ctx.r3.u64 = Construct_TXT_834974B4_G_(ctx, base); }

uint64_t Construct_TXT_834974BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974BC_G_ = int32_t(0x834974BC);
	constexpr int32_t str_TXT_820A6968_B_ = int32_t(0x820A6968);
	constexpr int32_t Destroy_TXT_834974BC_G__address = int32_t(0x832A05B0);
	if (!UseLiftedCode(143, 0x83242D50)) { __imp__sub_83242D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242D50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974BC_G_, str_TXT_820A6968_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974BC_G__address);
}
PROMOTED_ENTRY(143, sub_83242D50, 0x83242D50) { ctx.r3.u64 = Construct_TXT_834974BC_G_(ctx, base); }

uint64_t Construct_TXT_834974C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974C0_G_ = int32_t(0x834974C0);
	constexpr int32_t str_TXT_820A735C_B_ = int32_t(0x820A735C);
	constexpr int32_t Destroy_TXT_834974C0_G__address = int32_t(0x832A05C0);
	if (!UseLiftedCode(143, 0x83242D90)) { __imp__sub_83242D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242D90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974C0_G_, str_TXT_820A735C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974C0_G__address);
}
PROMOTED_ENTRY(143, sub_83242D90, 0x83242D90) { ctx.r3.u64 = Construct_TXT_834974C0_G_(ctx, base); }

uint64_t Construct_TXT_834974C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974C8_G_ = int32_t(0x834974C8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834974C8_G__address = int32_t(0x832A05D8);
	if (!UseLiftedCode(143, 0x83242EA0)) { __imp__sub_83242EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242EA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974C8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974C8_G__address);
}
PROMOTED_ENTRY(143, sub_83242EA0, 0x83242EA0) { ctx.r3.u64 = Construct_TXT_834974C8_G_(ctx, base); }

uint64_t Construct_TXT_834974CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974CC_G_ = int32_t(0x834974CC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834974CC_G__address = int32_t(0x832A05E8);
	if (!UseLiftedCode(143, 0x83242EE0)) { __imp__sub_83242EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242EE0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974CC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974CC_G__address);
}
PROMOTED_ENTRY(143, sub_83242EE0, 0x83242EE0) { ctx.r3.u64 = Construct_TXT_834974CC_G_(ctx, base); }

uint64_t Construct_TXT_834974D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974D0_G_ = int32_t(0x834974D0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834974D0_G__address = int32_t(0x832A05F8);
	if (!UseLiftedCode(143, 0x83242F20)) { __imp__sub_83242F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F20);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974D0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974D0_G__address);
}
PROMOTED_ENTRY(143, sub_83242F20, 0x83242F20) { ctx.r3.u64 = Construct_TXT_834974D0_G_(ctx, base); }

uint64_t n_sub_83242F60(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0608_address = int32_t(0x832A0608);
	if (!UseLiftedCode(143, 0x83242F60)) { ctx.r8.u64 = callbackArgument; __imp__sub_83242F60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F60);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0608_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83242F60, 0x83242F60) { ctx.r3.u64 = n_sub_83242F60(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_834974E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974E4_G_ = int32_t(0x834974E4);
	constexpr int32_t str_TXT_820A776C_B_ = int32_t(0x820A776C);
	constexpr int32_t Destroy_TXT_834974E4_G__address = int32_t(0x832A0670);
	if (!UseLiftedCode(143, 0x83242F70)) { __imp__sub_83242F70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242F70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974E4_G_, str_TXT_820A776C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974E4_G__address);
}
PROMOTED_ENTRY(143, sub_83242F70, 0x83242F70) { ctx.r3.u64 = Construct_TXT_834974E4_G_(ctx, base); }

uint64_t Construct_TXT_834974E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974E8_G_ = int32_t(0x834974E8);
	constexpr int32_t str_TXT_820A7774_B_ = int32_t(0x820A7774);
	constexpr int32_t Destroy_TXT_834974E8_G__address = int32_t(0x832A0680);
	if (!UseLiftedCode(143, 0x83242FB0)) { __imp__sub_83242FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242FB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974E8_G_, str_TXT_820A7774_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974E8_G__address);
}
PROMOTED_ENTRY(143, sub_83242FB0, 0x83242FB0) { ctx.r3.u64 = Construct_TXT_834974E8_G_(ctx, base); }

uint64_t Construct_TXT_834974EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974EC_G_ = int32_t(0x834974EC);
	constexpr int32_t str_TXT_820A7788_B_ = int32_t(0x820A7788);
	constexpr int32_t Destroy_TXT_834974EC_G__address = int32_t(0x832A0690);
	if (!UseLiftedCode(143, 0x83242FF0)) { __imp__sub_83242FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83242FF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974EC_G_, str_TXT_820A7788_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974EC_G__address);
}
PROMOTED_ENTRY(143, sub_83242FF0, 0x83242FF0) { ctx.r3.u64 = Construct_TXT_834974EC_G_(ctx, base); }

uint64_t Construct_TXT_834974F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974F0_G_ = int32_t(0x834974F0);
	constexpr int32_t str_TXT_820A7794_B_ = int32_t(0x820A7794);
	constexpr int32_t Destroy_TXT_834974F0_G__address = int32_t(0x832A06A0);
	if (!UseLiftedCode(143, 0x83243030)) { __imp__sub_83243030(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243030);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F0_G_, str_TXT_820A7794_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974F0_G__address);
}
PROMOTED_ENTRY(143, sub_83243030, 0x83243030) { ctx.r3.u64 = Construct_TXT_834974F0_G_(ctx, base); }

uint64_t Construct_TXT_834974F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974F4_G_ = int32_t(0x834974F4);
	constexpr int32_t str_TXT_820A77A4_B_ = int32_t(0x820A77A4);
	constexpr int32_t Destroy_TXT_834974F4_G__address = int32_t(0x832A06B0);
	if (!UseLiftedCode(143, 0x83243070)) { __imp__sub_83243070(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243070);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F4_G_, str_TXT_820A77A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974F4_G__address);
}
PROMOTED_ENTRY(143, sub_83243070, 0x83243070) { ctx.r3.u64 = Construct_TXT_834974F4_G_(ctx, base); }

uint64_t Construct_TXT_834974F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974F8_G_ = int32_t(0x834974F8);
	constexpr int32_t str_TXT_820A77B4_B_ = int32_t(0x820A77B4);
	constexpr int32_t Destroy_TXT_834974F8_G__address = int32_t(0x832A06C0);
	if (!UseLiftedCode(143, 0x832430B0)) { __imp__sub_832430B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832430B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974F8_G_, str_TXT_820A77B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974F8_G__address);
}
PROMOTED_ENTRY(143, sub_832430B0, 0x832430B0) { ctx.r3.u64 = Construct_TXT_834974F8_G_(ctx, base); }

uint64_t Construct_TXT_834974FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834974FC_G_ = int32_t(0x834974FC);
	constexpr int32_t str_TXT_820A77C0_B_ = int32_t(0x820A77C0);
	constexpr int32_t Destroy_TXT_834974FC_G__address = int32_t(0x832A06D0);
	if (!UseLiftedCode(143, 0x832430F0)) { __imp__sub_832430F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832430F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834974FC_G_, str_TXT_820A77C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834974FC_G__address);
}
PROMOTED_ENTRY(143, sub_832430F0, 0x832430F0) { ctx.r3.u64 = Construct_TXT_834974FC_G_(ctx, base); }

uint64_t Construct_TXT_83497500_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497500_G_ = int32_t(0x83497500);
	constexpr int32_t str_TXT_820A77D0_B_ = int32_t(0x820A77D0);
	constexpr int32_t Destroy_TXT_83497500_G__address = int32_t(0x832A06E0);
	if (!UseLiftedCode(143, 0x83243130)) { __imp__sub_83243130(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243130);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497500_G_, str_TXT_820A77D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497500_G__address);
}
PROMOTED_ENTRY(143, sub_83243130, 0x83243130) { ctx.r3.u64 = Construct_TXT_83497500_G_(ctx, base); }

uint64_t Construct_TXT_83497504_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497504_G_ = int32_t(0x83497504);
	constexpr int32_t str_TXT_820A77E0_B_ = int32_t(0x820A77E0);
	constexpr int32_t Destroy_TXT_83497504_G__address = int32_t(0x832A06F0);
	if (!UseLiftedCode(143, 0x83243170)) { __imp__sub_83243170(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243170);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497504_G_, str_TXT_820A77E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497504_G__address);
}
PROMOTED_ENTRY(143, sub_83243170, 0x83243170) { ctx.r3.u64 = Construct_TXT_83497504_G_(ctx, base); }

uint64_t Construct_TXT_83497508_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497508_G_ = int32_t(0x83497508);
	constexpr int32_t str_TXT_820A77F8_B_ = int32_t(0x820A77F8);
	constexpr int32_t Destroy_TXT_83497508_G__address = int32_t(0x832A0700);
	if (!UseLiftedCode(143, 0x832431B0)) { __imp__sub_832431B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832431B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497508_G_, str_TXT_820A77F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497508_G__address);
}
PROMOTED_ENTRY(143, sub_832431B0, 0x832431B0) { ctx.r3.u64 = Construct_TXT_83497508_G_(ctx, base); }

uint64_t Construct_TXT_8349750C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349750C_G_ = int32_t(0x8349750C);
	constexpr int32_t str_TXT_820A7810_B_ = int32_t(0x820A7810);
	constexpr int32_t Destroy_TXT_8349750C_G__address = int32_t(0x832A0710);
	if (!UseLiftedCode(143, 0x832431F0)) { __imp__sub_832431F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832431F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349750C_G_, str_TXT_820A7810_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349750C_G__address);
}
PROMOTED_ENTRY(143, sub_832431F0, 0x832431F0) { ctx.r3.u64 = Construct_TXT_8349750C_G_(ctx, base); }

uint64_t Construct_TXT_83497510_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497510_G_ = int32_t(0x83497510);
	constexpr int32_t str_TXT_820A7820_B_ = int32_t(0x820A7820);
	constexpr int32_t Destroy_TXT_83497510_G__address = int32_t(0x832A0720);
	if (!UseLiftedCode(143, 0x83243230)) { __imp__sub_83243230(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243230);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497510_G_, str_TXT_820A7820_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497510_G__address);
}
PROMOTED_ENTRY(143, sub_83243230, 0x83243230) { ctx.r3.u64 = Construct_TXT_83497510_G_(ctx, base); }

uint64_t Construct_TXT_83497514_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497514_G_ = int32_t(0x83497514);
	constexpr int32_t str_TXT_820A7834_B_ = int32_t(0x820A7834);
	constexpr int32_t Destroy_TXT_83497514_G__address = int32_t(0x832A0730);
	if (!UseLiftedCode(143, 0x83243270)) { __imp__sub_83243270(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243270);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497514_G_, str_TXT_820A7834_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497514_G__address);
}
PROMOTED_ENTRY(143, sub_83243270, 0x83243270) { ctx.r3.u64 = Construct_TXT_83497514_G_(ctx, base); }

uint64_t Construct_TXT_83497518_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497518_G_ = int32_t(0x83497518);
	constexpr int32_t str_TXT_820A7840_B_ = int32_t(0x820A7840);
	constexpr int32_t Destroy_TXT_83497518_G__address = int32_t(0x832A0740);
	if (!UseLiftedCode(143, 0x832432B0)) { __imp__sub_832432B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832432B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497518_G_, str_TXT_820A7840_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497518_G__address);
}
PROMOTED_ENTRY(143, sub_832432B0, 0x832432B0) { ctx.r3.u64 = Construct_TXT_83497518_G_(ctx, base); }

uint64_t Construct_TXT_8349751C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349751C_G_ = int32_t(0x8349751C);
	constexpr int32_t str_TXT_820A7858_B_ = int32_t(0x820A7858);
	constexpr int32_t Destroy_TXT_8349751C_G__address = int32_t(0x832A0750);
	if (!UseLiftedCode(143, 0x832432F0)) { __imp__sub_832432F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832432F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349751C_G_, str_TXT_820A7858_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349751C_G__address);
}
PROMOTED_ENTRY(143, sub_832432F0, 0x832432F0) { ctx.r3.u64 = Construct_TXT_8349751C_G_(ctx, base); }

uint64_t Construct_TXT_83497524_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497524_G_ = int32_t(0x83497524);
	constexpr int32_t str_TXT_820A7888_B_ = int32_t(0x820A7888);
	constexpr int32_t Destroy_TXT_83497524_G__address = int32_t(0x832A0770);
	if (!UseLiftedCode(143, 0x83243388)) { __imp__sub_83243388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497524_G_, str_TXT_820A7888_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497524_G__address);
}
PROMOTED_ENTRY(143, sub_83243388, 0x83243388) { ctx.r3.u64 = Construct_TXT_83497524_G_(ctx, base); }

uint64_t Construct_TXT_83497528_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497528_G_ = int32_t(0x83497528);
	constexpr int32_t str_TXT_820A78A0_B_ = int32_t(0x820A78A0);
	constexpr int32_t Destroy_TXT_83497528_G__address = int32_t(0x832A0780);
	if (!UseLiftedCode(143, 0x832433C8)) { __imp__sub_832433C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832433C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497528_G_, str_TXT_820A78A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497528_G__address);
}
PROMOTED_ENTRY(143, sub_832433C8, 0x832433C8) { ctx.r3.u64 = Construct_TXT_83497528_G_(ctx, base); }

uint64_t Construct_TXT_8349752C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349752C_G_ = int32_t(0x8349752C);
	constexpr int32_t str_TXT_820A78B4_B_ = int32_t(0x820A78B4);
	constexpr int32_t Destroy_TXT_8349752C_G__address = int32_t(0x832A0790);
	if (!UseLiftedCode(143, 0x83243408)) { __imp__sub_83243408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349752C_G_, str_TXT_820A78B4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349752C_G__address);
}
PROMOTED_ENTRY(143, sub_83243408, 0x83243408) { ctx.r3.u64 = Construct_TXT_8349752C_G_(ctx, base); }

uint64_t Construct_TXT_83497530_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497530_G_ = int32_t(0x83497530);
	constexpr int32_t str_TXT_820A78BC_B_ = int32_t(0x820A78BC);
	constexpr int32_t Destroy_TXT_83497530_G__address = int32_t(0x832A07A0);
	if (!UseLiftedCode(143, 0x83243448)) { __imp__sub_83243448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497530_G_, str_TXT_820A78BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497530_G__address);
}
PROMOTED_ENTRY(143, sub_83243448, 0x83243448) { ctx.r3.u64 = Construct_TXT_83497530_G_(ctx, base); }

uint64_t Construct_TXT_83497538_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497538_G_ = int32_t(0x83497538);
	constexpr int32_t str_TXT_820A78C8_B_ = int32_t(0x820A78C8);
	constexpr int32_t Destroy_TXT_83497538_G__address = int32_t(0x832A07C0);
	if (!UseLiftedCode(143, 0x832434E0)) { __imp__sub_832434E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832434E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497538_G_, str_TXT_820A78C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497538_G__address);
}
PROMOTED_ENTRY(143, sub_832434E0, 0x832434E0) { ctx.r3.u64 = Construct_TXT_83497538_G_(ctx, base); }

uint64_t Construct_TXT_8349753C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349753C_G_ = int32_t(0x8349753C);
	constexpr int32_t str_TXT_820A78CC_B_ = int32_t(0x820A78CC);
	constexpr int32_t Destroy_TXT_8349753C_G__address = int32_t(0x832A07D0);
	if (!UseLiftedCode(143, 0x83243520)) { __imp__sub_83243520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243520);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349753C_G_, str_TXT_820A78CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349753C_G__address);
}
PROMOTED_ENTRY(143, sub_83243520, 0x83243520) { ctx.r3.u64 = Construct_TXT_8349753C_G_(ctx, base); }

uint64_t Construct_TXT_83497540_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497540_G_ = int32_t(0x83497540);
	constexpr int32_t str_TXT_820A78DC_B_ = int32_t(0x820A78DC);
	constexpr int32_t Destroy_TXT_83497540_G__address = int32_t(0x832A07E0);
	if (!UseLiftedCode(143, 0x83243560)) { __imp__sub_83243560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243560);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497540_G_, str_TXT_820A78DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497540_G__address);
}
PROMOTED_ENTRY(143, sub_83243560, 0x83243560) { ctx.r3.u64 = Construct_TXT_83497540_G_(ctx, base); }

uint64_t Construct_TXT_83497544_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497544_G_ = int32_t(0x83497544);
	constexpr int32_t str_TXT_820A78F8_B_ = int32_t(0x820A78F8);
	constexpr int32_t Destroy_TXT_83497544_G__address = int32_t(0x832A07F0);
	if (!UseLiftedCode(143, 0x832435A0)) { __imp__sub_832435A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832435A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497544_G_, str_TXT_820A78F8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497544_G__address);
}
PROMOTED_ENTRY(143, sub_832435A0, 0x832435A0) { ctx.r3.u64 = Construct_TXT_83497544_G_(ctx, base); }

uint64_t n_sub_83243618(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A08B0_address = int32_t(0x832A08B0);
	if (!UseLiftedCode(143, 0x83243618)) { ctx.r8.u64 = callbackArgument; __imp__sub_83243618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243618);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A08B0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83243618, 0x83243618) { ctx.r3.u64 = n_sub_83243618(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_834975C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975C0_G_ = int32_t(0x834975C0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834975C0_G__address = int32_t(0x832A0A78);
	if (!UseLiftedCode(143, 0x832438C0)) { __imp__sub_832438C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832438C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975C0_G__address);
}
PROMOTED_ENTRY(143, sub_832438C0, 0x832438C0) { ctx.r3.u64 = Construct_TXT_834975C0_G_(ctx, base); }

uint64_t Construct_TXT_834975C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975C4_G_ = int32_t(0x834975C4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834975C4_G__address = int32_t(0x832A0A88);
	if (!UseLiftedCode(143, 0x83243900)) { __imp__sub_83243900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243900);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975C4_G__address);
}
PROMOTED_ENTRY(143, sub_83243900, 0x83243900) { ctx.r3.u64 = Construct_TXT_834975C4_G_(ctx, base); }

uint64_t Construct_TXT_834975C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975C8_G_ = int32_t(0x834975C8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834975C8_G__address = int32_t(0x832A0A98);
	if (!UseLiftedCode(143, 0x83243940)) { __imp__sub_83243940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243940);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975C8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975C8_G__address);
}
PROMOTED_ENTRY(143, sub_83243940, 0x83243940) { ctx.r3.u64 = Construct_TXT_834975C8_G_(ctx, base); }

uint64_t Construct_TXT_834975CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975CC_G_ = int32_t(0x834975CC);
	constexpr int32_t str_TXT_820A7E58_B_ = int32_t(0x820A7E58);
	constexpr int32_t Destroy_TXT_834975CC_G__address = int32_t(0x832A0AA8);
	if (!UseLiftedCode(143, 0x83243980)) { __imp__sub_83243980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243980);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975CC_G_, str_TXT_820A7E58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975CC_G__address);
}
PROMOTED_ENTRY(143, sub_83243980, 0x83243980) { ctx.r3.u64 = Construct_TXT_834975CC_G_(ctx, base); }

uint64_t Construct_TXT_834975D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975D0_G_ = int32_t(0x834975D0);
	constexpr int32_t str_TXT_820A7E74_B_ = int32_t(0x820A7E74);
	constexpr int32_t Destroy_TXT_834975D0_G__address = int32_t(0x832A0AB8);
	if (!UseLiftedCode(143, 0x832439C0)) { __imp__sub_832439C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832439C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D0_G_, str_TXT_820A7E74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975D0_G__address);
}
PROMOTED_ENTRY(143, sub_832439C0, 0x832439C0) { ctx.r3.u64 = Construct_TXT_834975D0_G_(ctx, base); }

uint64_t Construct_TXT_834975D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975D4_G_ = int32_t(0x834975D4);
	constexpr int32_t str_TXT_820A7E58_B_ = int32_t(0x820A7E58);
	constexpr int32_t Destroy_TXT_834975D4_G__address = int32_t(0x832A0AC8);
	if (!UseLiftedCode(143, 0x83243A00)) { __imp__sub_83243A00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D4_G_, str_TXT_820A7E58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975D4_G__address);
}
PROMOTED_ENTRY(143, sub_83243A00, 0x83243A00) { ctx.r3.u64 = Construct_TXT_834975D4_G_(ctx, base); }

uint64_t Construct_TXT_834975D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975D8_G_ = int32_t(0x834975D8);
	constexpr int32_t str_TXT_820A7E8C_B_ = int32_t(0x820A7E8C);
	constexpr int32_t Destroy_TXT_834975D8_G__address = int32_t(0x832A0AD8);
	if (!UseLiftedCode(143, 0x83243A40)) { __imp__sub_83243A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975D8_G_, str_TXT_820A7E8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975D8_G__address);
}
PROMOTED_ENTRY(143, sub_83243A40, 0x83243A40) { ctx.r3.u64 = Construct_TXT_834975D8_G_(ctx, base); }

uint64_t Construct_TXT_834975DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834975DC_G_ = int32_t(0x834975DC);
	constexpr int32_t str_TXT_820A7EA4_B_ = int32_t(0x820A7EA4);
	constexpr int32_t Destroy_TXT_834975DC_G__address = int32_t(0x832A0AE8);
	if (!UseLiftedCode(143, 0x83243A80)) { __imp__sub_83243A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83243A80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834975DC_G_, str_TXT_820A7EA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834975DC_G__address);
}
PROMOTED_ENTRY(143, sub_83243A80, 0x83243A80) { ctx.r3.u64 = Construct_TXT_834975DC_G_(ctx, base); }

uint64_t Construct_TXT_83497610_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497610_G_ = int32_t(0x83497610);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497610_G__address = int32_t(0x832A0B18);
	if (!UseLiftedCode(143, 0x83244198)) { __imp__sub_83244198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244198);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497610_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497610_G__address);
}
PROMOTED_ENTRY(143, sub_83244198, 0x83244198) { ctx.r3.u64 = Construct_TXT_83497610_G_(ctx, base); }

uint64_t Construct_TXT_83497614_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497614_G_ = int32_t(0x83497614);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497614_G__address = int32_t(0x832A0B28);
	if (!UseLiftedCode(143, 0x832441D8)) { __imp__sub_832441D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832441D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497614_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497614_G__address);
}
PROMOTED_ENTRY(143, sub_832441D8, 0x832441D8) { ctx.r3.u64 = Construct_TXT_83497614_G_(ctx, base); }

uint64_t Construct_TXT_83497618_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497618_G_ = int32_t(0x83497618);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497618_G__address = int32_t(0x832A0B38);
	if (!UseLiftedCode(143, 0x83244218)) { __imp__sub_83244218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244218);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497618_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497618_G__address);
}
PROMOTED_ENTRY(143, sub_83244218, 0x83244218) { ctx.r3.u64 = Construct_TXT_83497618_G_(ctx, base); }

uint64_t Construct_TXT_8349761C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349761C_G_ = int32_t(0x8349761C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349761C_G__address = int32_t(0x832A0B48);
	if (!UseLiftedCode(143, 0x83244258)) { __imp__sub_83244258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349761C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349761C_G__address);
}
PROMOTED_ENTRY(143, sub_83244258, 0x83244258) { ctx.r3.u64 = Construct_TXT_8349761C_G_(ctx, base); }

uint64_t Construct_TXT_83497620_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497620_G_ = int32_t(0x83497620);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497620_G__address = int32_t(0x832A0B58);
	if (!UseLiftedCode(143, 0x83244298)) { __imp__sub_83244298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497620_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497620_G__address);
}
PROMOTED_ENTRY(143, sub_83244298, 0x83244298) { ctx.r3.u64 = Construct_TXT_83497620_G_(ctx, base); }

uint64_t Construct_TXT_83497624_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497624_G_ = int32_t(0x83497624);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497624_G__address = int32_t(0x832A0B68);
	if (!UseLiftedCode(143, 0x832442D8)) { __imp__sub_832442D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832442D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497624_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497624_G__address);
}
PROMOTED_ENTRY(143, sub_832442D8, 0x832442D8) { ctx.r3.u64 = Construct_TXT_83497624_G_(ctx, base); }

uint64_t Construct_TXT_83497648_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497648_G_ = int32_t(0x83497648);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497648_G__address = int32_t(0x832A0B98);
	if (!UseLiftedCode(143, 0x83244448)) { __imp__sub_83244448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497648_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497648_G__address);
}
PROMOTED_ENTRY(143, sub_83244448, 0x83244448) { ctx.r3.u64 = Construct_TXT_83497648_G_(ctx, base); }

uint64_t Construct_TXT_8349764C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349764C_G_ = int32_t(0x8349764C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349764C_G__address = int32_t(0x832A0BA8);
	if (!UseLiftedCode(143, 0x83244488)) { __imp__sub_83244488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349764C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349764C_G__address);
}
PROMOTED_ENTRY(143, sub_83244488, 0x83244488) { ctx.r3.u64 = Construct_TXT_8349764C_G_(ctx, base); }

uint64_t Construct_TXT_83497650_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497650_G_ = int32_t(0x83497650);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497650_G__address = int32_t(0x832A0BB8);
	if (!UseLiftedCode(143, 0x832444C8)) { __imp__sub_832444C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832444C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497650_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497650_G__address);
}
PROMOTED_ENTRY(143, sub_832444C8, 0x832444C8) { ctx.r3.u64 = Construct_TXT_83497650_G_(ctx, base); }

uint64_t Construct_TXT_83497654_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497654_G_ = int32_t(0x83497654);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497654_G__address = int32_t(0x832A0BC8);
	if (!UseLiftedCode(143, 0x83244508)) { __imp__sub_83244508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497654_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497654_G__address);
}
PROMOTED_ENTRY(143, sub_83244508, 0x83244508) { ctx.r3.u64 = Construct_TXT_83497654_G_(ctx, base); }

uint64_t Construct_TXT_83497658_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497658_G_ = int32_t(0x83497658);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497658_G__address = int32_t(0x832A0BD8);
	if (!UseLiftedCode(143, 0x83244548)) { __imp__sub_83244548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497658_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497658_G__address);
}
PROMOTED_ENTRY(143, sub_83244548, 0x83244548) { ctx.r3.u64 = Construct_TXT_83497658_G_(ctx, base); }

uint64_t Construct_TXT_8349765C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349765C_G_ = int32_t(0x8349765C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349765C_G__address = int32_t(0x832A0BE8);
	if (!UseLiftedCode(143, 0x83244588)) { __imp__sub_83244588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244588);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349765C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349765C_G__address);
}
PROMOTED_ENTRY(143, sub_83244588, 0x83244588) { ctx.r3.u64 = Construct_TXT_8349765C_G_(ctx, base); }

uint64_t n_sub_83244628(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0CB8_address = int32_t(0x832A0CB8);
	if (!UseLiftedCode(143, 0x83244628)) { ctx.r8.u64 = callbackArgument; __imp__sub_83244628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244628);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0CB8_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83244628, 0x83244628) { ctx.r3.u64 = n_sub_83244628(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244638(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_83497680 = int32_t(0x83497680);
	constexpr int32_t n_sub_832A0D10_address = int32_t(0x832A0D10);
	if (!UseLiftedCode(143, 0x83244638)) { __imp__sub_83244638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244638);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83497680, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832A0D10_address);
}
PROMOTED_ENTRY(143, sub_83244638, 0x83244638) { ctx.r3.u64 = n_sub_83244638(ctx, base); }

uint64_t n_sub_83244678(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_83497684 = int32_t(0x83497684);
	constexpr int32_t n_sub_832A0D20_address = int32_t(0x832A0D20);
	if (!UseLiftedCode(143, 0x83244678)) { __imp__sub_83244678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244678);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, g_83497684, (int64_t)g_82000000 + 3224, -1);
	return RegisterAtExit(ctx, base, n_sub_832A0D20_address);
}
PROMOTED_ENTRY(143, sub_83244678, 0x83244678) { ctx.r3.u64 = n_sub_83244678(ctx, base); }

// sub_83244748  [64 bytes]
uint64_t n_sub_83244748(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497694_G_ = int32_t(0x83497694);
	constexpr int32_t str_TXT_820A84D8_B_ = int32_t(0x820A84D8);
	constexpr int32_t Destroy_TXT_83497694_G__address = int32_t(0x832A0D40);
	if (!UseLiftedCode(143, 0x83244748)) { __imp__sub_83244748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244748);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497694_G_, str_TXT_820A84D8_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83497694_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_83244748, 0x83244748) { ctx.r3.u64 = n_sub_83244748(ctx, base); }

uint64_t Construct_TXT_83497698_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497698_G_ = int32_t(0x83497698);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497698_G__address = int32_t(0x832A0D50);
	if (!UseLiftedCode(143, 0x83244788)) { __imp__sub_83244788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497698_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497698_G__address);
}
PROMOTED_ENTRY(143, sub_83244788, 0x83244788) { ctx.r3.u64 = Construct_TXT_83497698_G_(ctx, base); }

uint64_t Construct_TXT_8349769C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349769C_G_ = int32_t(0x8349769C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349769C_G__address = int32_t(0x832A0D60);
	if (!UseLiftedCode(143, 0x832447C8)) { __imp__sub_832447C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832447C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349769C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349769C_G__address);
}
PROMOTED_ENTRY(143, sub_832447C8, 0x832447C8) { ctx.r3.u64 = Construct_TXT_8349769C_G_(ctx, base); }

uint64_t Construct_TXT_834976A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976A0_G_ = int32_t(0x834976A0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834976A0_G__address = int32_t(0x832A0D70);
	if (!UseLiftedCode(143, 0x83244808)) { __imp__sub_83244808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976A0_G__address);
}
PROMOTED_ENTRY(143, sub_83244808, 0x83244808) { ctx.r3.u64 = Construct_TXT_834976A0_G_(ctx, base); }

uint64_t Construct_TXT_834976A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976A4_G_ = int32_t(0x834976A4);
	constexpr int32_t str_TXT_820A8794_B_ = int32_t(0x820A8794);
	constexpr int32_t Destroy_TXT_834976A4_G__address = int32_t(0x832A0D80);
	if (!UseLiftedCode(143, 0x832448A8)) { __imp__sub_832448A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832448A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A4_G_, str_TXT_820A8794_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976A4_G__address);
}
PROMOTED_ENTRY(143, sub_832448A8, 0x832448A8) { ctx.r3.u64 = Construct_TXT_834976A4_G_(ctx, base); }

uint64_t Construct_TXT_834976A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976A8_G_ = int32_t(0x834976A8);
	constexpr int32_t str_TXT_820A87AC_B_ = int32_t(0x820A87AC);
	constexpr int32_t Destroy_TXT_834976A8_G__address = int32_t(0x832A0D90);
	if (!UseLiftedCode(143, 0x832448E8)) { __imp__sub_832448E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832448E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976A8_G_, str_TXT_820A87AC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976A8_G__address);
}
PROMOTED_ENTRY(143, sub_832448E8, 0x832448E8) { ctx.r3.u64 = Construct_TXT_834976A8_G_(ctx, base); }

uint64_t n_sub_83244928(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0DA0_address = int32_t(0x832A0DA0);
	if (!UseLiftedCode(143, 0x83244928)) { ctx.r8.u64 = callbackArgument; __imp__sub_83244928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244928);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0DA0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83244928, 0x83244928) { ctx.r3.u64 = n_sub_83244928(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83244938(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0DB0_address = int32_t(0x832A0DB0);
	if (!UseLiftedCode(143, 0x83244938)) { ctx.r8.u64 = callbackArgument; __imp__sub_83244938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244938);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0DB0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83244938, 0x83244938) { ctx.r3.u64 = n_sub_83244938(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_834976E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976E8_G_ = int32_t(0x834976E8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834976E8_G__address = int32_t(0x832A0DC0);
	if (!UseLiftedCode(143, 0x83244948)) { __imp__sub_83244948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976E8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976E8_G__address);
}
PROMOTED_ENTRY(143, sub_83244948, 0x83244948) { ctx.r3.u64 = Construct_TXT_834976E8_G_(ctx, base); }

uint64_t Construct_TXT_834976EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976EC_G_ = int32_t(0x834976EC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834976EC_G__address = int32_t(0x832A0DD0);
	if (!UseLiftedCode(143, 0x83244988)) { __imp__sub_83244988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976EC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976EC_G__address);
}
PROMOTED_ENTRY(143, sub_83244988, 0x83244988) { ctx.r3.u64 = Construct_TXT_834976EC_G_(ctx, base); }

uint64_t Construct_TXT_834976F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834976F0_G_ = int32_t(0x834976F0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834976F0_G__address = int32_t(0x832A0DE0);
	if (!UseLiftedCode(143, 0x832449C8)) { __imp__sub_832449C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832449C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834976F0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834976F0_G__address);
}
PROMOTED_ENTRY(143, sub_832449C8, 0x832449C8) { ctx.r3.u64 = Construct_TXT_834976F0_G_(ctx, base); }

uint64_t n_sub_83244A40(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A0DF0_address = int32_t(0x832A0DF0);
	if (!UseLiftedCode(143, 0x83244A40)) { ctx.r8.u64 = callbackArgument; __imp__sub_83244A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A40);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A0DF0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83244A40, 0x83244A40) { ctx.r3.u64 = n_sub_83244A40(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83497708_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497708_G_ = int32_t(0x83497708);
	constexpr int32_t str_TXT_820A8F8C_B_ = int32_t(0x820A8F8C);
	constexpr int32_t Destroy_TXT_83497708_G__address = int32_t(0x832A0E00);
	if (!UseLiftedCode(143, 0x83244A50)) { __imp__sub_83244A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497708_G_, str_TXT_820A8F8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497708_G__address);
}
PROMOTED_ENTRY(143, sub_83244A50, 0x83244A50) { ctx.r3.u64 = Construct_TXT_83497708_G_(ctx, base); }

uint64_t Construct_TXT_8349770C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349770C_G_ = int32_t(0x8349770C);
	constexpr int32_t str_TXT_820A8F94_B_ = int32_t(0x820A8F94);
	constexpr int32_t Destroy_TXT_8349770C_G__address = int32_t(0x832A0E10);
	if (!UseLiftedCode(143, 0x83244A90)) { __imp__sub_83244A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244A90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349770C_G_, str_TXT_820A8F94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349770C_G__address);
}
PROMOTED_ENTRY(143, sub_83244A90, 0x83244A90) { ctx.r3.u64 = Construct_TXT_8349770C_G_(ctx, base); }

uint64_t Construct_TXT_83497710_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497710_G_ = int32_t(0x83497710);
	constexpr int32_t str_TXT_820A8F9C_B_ = int32_t(0x820A8F9C);
	constexpr int32_t Destroy_TXT_83497710_G__address = int32_t(0x832A0E20);
	if (!UseLiftedCode(143, 0x83244AD0)) { __imp__sub_83244AD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244AD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497710_G_, str_TXT_820A8F9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497710_G__address);
}
PROMOTED_ENTRY(143, sub_83244AD0, 0x83244AD0) { ctx.r3.u64 = Construct_TXT_83497710_G_(ctx, base); }

uint64_t Construct_TXT_83497714_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497714_G_ = int32_t(0x83497714);
	constexpr int32_t str_TXT_820A8FA8_B_ = int32_t(0x820A8FA8);
	constexpr int32_t Destroy_TXT_83497714_G__address = int32_t(0x832A0E30);
	if (!UseLiftedCode(143, 0x83244B10)) { __imp__sub_83244B10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497714_G_, str_TXT_820A8FA8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497714_G__address);
}
PROMOTED_ENTRY(143, sub_83244B10, 0x83244B10) { ctx.r3.u64 = Construct_TXT_83497714_G_(ctx, base); }

uint64_t Construct_TXT_83497718_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497718_G_ = int32_t(0x83497718);
	constexpr int32_t str_TXT_820A8FB0_B_ = int32_t(0x820A8FB0);
	constexpr int32_t Destroy_TXT_83497718_G__address = int32_t(0x832A0E40);
	if (!UseLiftedCode(143, 0x83244B50)) { __imp__sub_83244B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497718_G_, str_TXT_820A8FB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497718_G__address);
}
PROMOTED_ENTRY(143, sub_83244B50, 0x83244B50) { ctx.r3.u64 = Construct_TXT_83497718_G_(ctx, base); }

uint64_t Construct_TXT_8349771C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349771C_G_ = int32_t(0x8349771C);
	constexpr int32_t str_TXT_820A8FBC_B_ = int32_t(0x820A8FBC);
	constexpr int32_t Destroy_TXT_8349771C_G__address = int32_t(0x832A0E50);
	if (!UseLiftedCode(143, 0x83244B90)) { __imp__sub_83244B90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244B90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349771C_G_, str_TXT_820A8FBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349771C_G__address);
}
PROMOTED_ENTRY(143, sub_83244B90, 0x83244B90) { ctx.r3.u64 = Construct_TXT_8349771C_G_(ctx, base); }

uint64_t Construct_TXT_83497720_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497720_G_ = int32_t(0x83497720);
	constexpr int32_t str_TXT_820A8FCC_B_ = int32_t(0x820A8FCC);
	constexpr int32_t Destroy_TXT_83497720_G__address = int32_t(0x832A0E60);
	if (!UseLiftedCode(143, 0x83244BD0)) { __imp__sub_83244BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244BD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497720_G_, str_TXT_820A8FCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497720_G__address);
}
PROMOTED_ENTRY(143, sub_83244BD0, 0x83244BD0) { ctx.r3.u64 = Construct_TXT_83497720_G_(ctx, base); }

uint64_t Construct_TXT_83497724_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497724_G_ = int32_t(0x83497724);
	constexpr int32_t str_TXT_820A8FD4_B_ = int32_t(0x820A8FD4);
	constexpr int32_t Destroy_TXT_83497724_G__address = int32_t(0x832A0E70);
	if (!UseLiftedCode(143, 0x83244C10)) { __imp__sub_83244C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497724_G_, str_TXT_820A8FD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497724_G__address);
}
PROMOTED_ENTRY(143, sub_83244C10, 0x83244C10) { ctx.r3.u64 = Construct_TXT_83497724_G_(ctx, base); }

uint64_t Construct_TXT_83497728_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497728_G_ = int32_t(0x83497728);
	constexpr int32_t str_TXT_820A8FE4_B_ = int32_t(0x820A8FE4);
	constexpr int32_t Destroy_TXT_83497728_G__address = int32_t(0x832A0E80);
	if (!UseLiftedCode(143, 0x83244C50)) { __imp__sub_83244C50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497728_G_, str_TXT_820A8FE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497728_G__address);
}
PROMOTED_ENTRY(143, sub_83244C50, 0x83244C50) { ctx.r3.u64 = Construct_TXT_83497728_G_(ctx, base); }

uint64_t Construct_TXT_8349772C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349772C_G_ = int32_t(0x8349772C);
	constexpr int32_t str_TXT_820A8FEC_B_ = int32_t(0x820A8FEC);
	constexpr int32_t Destroy_TXT_8349772C_G__address = int32_t(0x832A0E90);
	if (!UseLiftedCode(143, 0x83244C90)) { __imp__sub_83244C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244C90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349772C_G_, str_TXT_820A8FEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349772C_G__address);
}
PROMOTED_ENTRY(143, sub_83244C90, 0x83244C90) { ctx.r3.u64 = Construct_TXT_8349772C_G_(ctx, base); }

uint64_t Construct_TXT_83497730_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497730_G_ = int32_t(0x83497730);
	constexpr int32_t str_TXT_820A8FF4_B_ = int32_t(0x820A8FF4);
	constexpr int32_t Destroy_TXT_83497730_G__address = int32_t(0x832A0EA0);
	if (!UseLiftedCode(143, 0x83244CD0)) { __imp__sub_83244CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244CD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497730_G_, str_TXT_820A8FF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497730_G__address);
}
PROMOTED_ENTRY(143, sub_83244CD0, 0x83244CD0) { ctx.r3.u64 = Construct_TXT_83497730_G_(ctx, base); }

uint64_t Construct_TXT_83497734_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497734_G_ = int32_t(0x83497734);
	constexpr int32_t str_TXT_820A9000_B_ = int32_t(0x820A9000);
	constexpr int32_t Destroy_TXT_83497734_G__address = int32_t(0x832A0EB0);
	if (!UseLiftedCode(143, 0x83244D10)) { __imp__sub_83244D10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497734_G_, str_TXT_820A9000_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497734_G__address);
}
PROMOTED_ENTRY(143, sub_83244D10, 0x83244D10) { ctx.r3.u64 = Construct_TXT_83497734_G_(ctx, base); }

uint64_t Construct_TXT_83497738_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497738_G_ = int32_t(0x83497738);
	constexpr int32_t str_TXT_820A9008_B_ = int32_t(0x820A9008);
	constexpr int32_t Destroy_TXT_83497738_G__address = int32_t(0x832A0EC0);
	if (!UseLiftedCode(143, 0x83244D50)) { __imp__sub_83244D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497738_G_, str_TXT_820A9008_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497738_G__address);
}
PROMOTED_ENTRY(143, sub_83244D50, 0x83244D50) { ctx.r3.u64 = Construct_TXT_83497738_G_(ctx, base); }

uint64_t Construct_TXT_8349773C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349773C_G_ = int32_t(0x8349773C);
	constexpr int32_t str_TXT_820A9010_B_ = int32_t(0x820A9010);
	constexpr int32_t Destroy_TXT_8349773C_G__address = int32_t(0x832A0ED0);
	if (!UseLiftedCode(143, 0x83244D90)) { __imp__sub_83244D90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244D90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349773C_G_, str_TXT_820A9010_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349773C_G__address);
}
PROMOTED_ENTRY(143, sub_83244D90, 0x83244D90) { ctx.r3.u64 = Construct_TXT_8349773C_G_(ctx, base); }

uint64_t Construct_TXT_83497740_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497740_G_ = int32_t(0x83497740);
	constexpr int32_t str_TXT_820A9018_B_ = int32_t(0x820A9018);
	constexpr int32_t Destroy_TXT_83497740_G__address = int32_t(0x832A0EE0);
	if (!UseLiftedCode(143, 0x83244DD0)) { __imp__sub_83244DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244DD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497740_G_, str_TXT_820A9018_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497740_G__address);
}
PROMOTED_ENTRY(143, sub_83244DD0, 0x83244DD0) { ctx.r3.u64 = Construct_TXT_83497740_G_(ctx, base); }

uint64_t Construct_TXT_83497744_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497744_G_ = int32_t(0x83497744);
	constexpr int32_t str_TXT_820A9020_B_ = int32_t(0x820A9020);
	constexpr int32_t Destroy_TXT_83497744_G__address = int32_t(0x832A0EF0);
	if (!UseLiftedCode(143, 0x83244E10)) { __imp__sub_83244E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497744_G_, str_TXT_820A9020_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497744_G__address);
}
PROMOTED_ENTRY(143, sub_83244E10, 0x83244E10) { ctx.r3.u64 = Construct_TXT_83497744_G_(ctx, base); }

uint64_t Construct_TXT_83497748_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497748_G_ = int32_t(0x83497748);
	constexpr int32_t str_TXT_820A9028_B_ = int32_t(0x820A9028);
	constexpr int32_t Destroy_TXT_83497748_G__address = int32_t(0x832A0F00);
	if (!UseLiftedCode(143, 0x83244E50)) { __imp__sub_83244E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497748_G_, str_TXT_820A9028_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497748_G__address);
}
PROMOTED_ENTRY(143, sub_83244E50, 0x83244E50) { ctx.r3.u64 = Construct_TXT_83497748_G_(ctx, base); }

uint64_t Construct_TXT_8349774C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349774C_G_ = int32_t(0x8349774C);
	constexpr int32_t str_TXT_820A9030_B_ = int32_t(0x820A9030);
	constexpr int32_t Destroy_TXT_8349774C_G__address = int32_t(0x832A0F10);
	if (!UseLiftedCode(143, 0x83244E90)) { __imp__sub_83244E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244E90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349774C_G_, str_TXT_820A9030_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349774C_G__address);
}
PROMOTED_ENTRY(143, sub_83244E90, 0x83244E90) { ctx.r3.u64 = Construct_TXT_8349774C_G_(ctx, base); }

uint64_t Construct_TXT_83497750_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497750_G_ = int32_t(0x83497750);
	constexpr int32_t str_TXT_820A9038_B_ = int32_t(0x820A9038);
	constexpr int32_t Destroy_TXT_83497750_G__address = int32_t(0x832A0F20);
	if (!UseLiftedCode(143, 0x83244ED0)) { __imp__sub_83244ED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244ED0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497750_G_, str_TXT_820A9038_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497750_G__address);
}
PROMOTED_ENTRY(143, sub_83244ED0, 0x83244ED0) { ctx.r3.u64 = Construct_TXT_83497750_G_(ctx, base); }

uint64_t Construct_TXT_83497754_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497754_G_ = int32_t(0x83497754);
	constexpr int32_t str_TXT_820A9044_B_ = int32_t(0x820A9044);
	constexpr int32_t Destroy_TXT_83497754_G__address = int32_t(0x832A0F30);
	if (!UseLiftedCode(143, 0x83244F10)) { __imp__sub_83244F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497754_G_, str_TXT_820A9044_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497754_G__address);
}
PROMOTED_ENTRY(143, sub_83244F10, 0x83244F10) { ctx.r3.u64 = Construct_TXT_83497754_G_(ctx, base); }

uint64_t Construct_TXT_83497758_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497758_G_ = int32_t(0x83497758);
	constexpr int32_t str_TXT_820A5998_B_ = int32_t(0x820A5998);
	constexpr int32_t Destroy_TXT_83497758_G__address = int32_t(0x832A0F40);
	if (!UseLiftedCode(143, 0x83244F50)) { __imp__sub_83244F50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497758_G_, str_TXT_820A5998_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497758_G__address);
}
PROMOTED_ENTRY(143, sub_83244F50, 0x83244F50) { ctx.r3.u64 = Construct_TXT_83497758_G_(ctx, base); }

uint64_t Construct_TXT_8349775C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349775C_G_ = int32_t(0x8349775C);
	constexpr int32_t str_TXT_820A904C_B_ = int32_t(0x820A904C);
	constexpr int32_t Destroy_TXT_8349775C_G__address = int32_t(0x832A0F50);
	if (!UseLiftedCode(143, 0x83244F90)) { __imp__sub_83244F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83244F90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349775C_G_, str_TXT_820A904C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349775C_G__address);
}
PROMOTED_ENTRY(143, sub_83244F90, 0x83244F90) { ctx.r3.u64 = Construct_TXT_8349775C_G_(ctx, base); }

uint64_t Construct_TXT_8349777C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349777C_G_ = int32_t(0x8349777C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349777C_G__address = int32_t(0x832A0F90);
	if (!UseLiftedCode(143, 0x83245488)) { __imp__sub_83245488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349777C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349777C_G__address);
}
PROMOTED_ENTRY(143, sub_83245488, 0x83245488) { ctx.r3.u64 = Construct_TXT_8349777C_G_(ctx, base); }

uint64_t Construct_TXT_83497780_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497780_G_ = int32_t(0x83497780);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497780_G__address = int32_t(0x832A0FA0);
	if (!UseLiftedCode(143, 0x832454C8)) { __imp__sub_832454C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832454C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497780_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497780_G__address);
}
PROMOTED_ENTRY(143, sub_832454C8, 0x832454C8) { ctx.r3.u64 = Construct_TXT_83497780_G_(ctx, base); }

uint64_t Construct_TXT_83497784_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497784_G_ = int32_t(0x83497784);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497784_G__address = int32_t(0x832A0FB0);
	if (!UseLiftedCode(143, 0x83245508)) { __imp__sub_83245508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497784_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497784_G__address);
}
PROMOTED_ENTRY(143, sub_83245508, 0x83245508) { ctx.r3.u64 = Construct_TXT_83497784_G_(ctx, base); }

uint64_t Construct_TXT_83497788_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497788_G_ = int32_t(0x83497788);
	constexpr int32_t str_TXT_820A94A8_B_ = int32_t(0x820A94A8);
	constexpr int32_t Destroy_TXT_83497788_G__address = int32_t(0x832A0FC0);
	if (!UseLiftedCode(143, 0x83245548)) { __imp__sub_83245548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245548);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497788_G_, str_TXT_820A94A8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497788_G__address);
}
PROMOTED_ENTRY(143, sub_83245548, 0x83245548) { ctx.r3.u64 = Construct_TXT_83497788_G_(ctx, base); }

uint64_t n_sub_832455E8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1018_address = int32_t(0x832A1018);
	if (!UseLiftedCode(143, 0x832455E8)) { ctx.r8.u64 = callbackArgument; __imp__sub_832455E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832455E8);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1018_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_832455E8, 0x832455E8) { ctx.r3.u64 = n_sub_832455E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_83245658(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1090_address = int32_t(0x832A1090);
	if (!UseLiftedCode(143, 0x83245658)) { ctx.r8.u64 = callbackArgument; __imp__sub_83245658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245658);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1090_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_83245658, 0x83245658) { ctx.r3.u64 = n_sub_83245658(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_834977E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977E0_G_ = int32_t(0x834977E0);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834977E0_G__address = int32_t(0x832A10C0);
	if (!UseLiftedCode(143, 0x832456C8)) { __imp__sub_832456C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832456C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977E0_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977E0_G__address);
}
PROMOTED_ENTRY(143, sub_832456C8, 0x832456C8) { ctx.r3.u64 = Construct_TXT_834977E0_G_(ctx, base); }

uint64_t Construct_TXT_834977E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977E8_G_ = int32_t(0x834977E8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834977E8_G__address = int32_t(0x832A10D0);
	if (!UseLiftedCode(143, 0x83245708)) { __imp__sub_83245708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245708);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977E8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977E8_G__address);
}
PROMOTED_ENTRY(143, sub_83245708, 0x83245708) { ctx.r3.u64 = Construct_TXT_834977E8_G_(ctx, base); }

uint64_t Construct_TXT_834977EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977EC_G_ = int32_t(0x834977EC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834977EC_G__address = int32_t(0x832A10E0);
	if (!UseLiftedCode(143, 0x83245748)) { __imp__sub_83245748(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245748);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977EC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977EC_G__address);
}
PROMOTED_ENTRY(143, sub_83245748, 0x83245748) { ctx.r3.u64 = Construct_TXT_834977EC_G_(ctx, base); }

uint64_t Construct_TXT_834977F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977F0_G_ = int32_t(0x834977F0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834977F0_G__address = int32_t(0x832A10F0);
	if (!UseLiftedCode(143, 0x83245788)) { __imp__sub_83245788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245788);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977F0_G__address);
}
PROMOTED_ENTRY(143, sub_83245788, 0x83245788) { ctx.r3.u64 = Construct_TXT_834977F0_G_(ctx, base); }

uint64_t Construct_TXT_834977F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977F4_G_ = int32_t(0x834977F4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834977F4_G__address = int32_t(0x832A1100);
	if (!UseLiftedCode(143, 0x832457C8)) { __imp__sub_832457C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832457C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977F4_G__address);
}
PROMOTED_ENTRY(143, sub_832457C8, 0x832457C8) { ctx.r3.u64 = Construct_TXT_834977F4_G_(ctx, base); }

uint64_t Construct_TXT_834977F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834977F8_G_ = int32_t(0x834977F8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834977F8_G__address = int32_t(0x832A1110);
	if (!UseLiftedCode(143, 0x83245808)) { __imp__sub_83245808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245808);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834977F8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834977F8_G__address);
}
PROMOTED_ENTRY(143, sub_83245808, 0x83245808) { ctx.r3.u64 = Construct_TXT_834977F8_G_(ctx, base); }

uint64_t Construct_TXT_8349780C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349780C_G_ = int32_t(0x8349780C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349780C_G__address = int32_t(0x832A1140);
	if (!UseLiftedCode(143, 0x83245928)) { __imp__sub_83245928(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245928);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349780C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349780C_G__address);
}
PROMOTED_ENTRY(143, sub_83245928, 0x83245928) { ctx.r3.u64 = Construct_TXT_8349780C_G_(ctx, base); }

uint64_t Construct_TXT_83497810_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497810_G_ = int32_t(0x83497810);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497810_G__address = int32_t(0x832A1150);
	if (!UseLiftedCode(143, 0x83245968)) { __imp__sub_83245968(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245968);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497810_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497810_G__address);
}
PROMOTED_ENTRY(143, sub_83245968, 0x83245968) { ctx.r3.u64 = Construct_TXT_83497810_G_(ctx, base); }

uint64_t Construct_TXT_83497814_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497814_G_ = int32_t(0x83497814);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497814_G__address = int32_t(0x832A1160);
	if (!UseLiftedCode(143, 0x832459A8)) { __imp__sub_832459A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832459A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497814_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497814_G__address);
}
PROMOTED_ENTRY(143, sub_832459A8, 0x832459A8) { ctx.r3.u64 = Construct_TXT_83497814_G_(ctx, base); }

uint64_t Construct_TXT_83497818_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497818_G_ = int32_t(0x83497818);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497818_G__address = int32_t(0x832A1170);
	if (!UseLiftedCode(143, 0x832459E8)) { __imp__sub_832459E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832459E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497818_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497818_G__address);
}
PROMOTED_ENTRY(143, sub_832459E8, 0x832459E8) { ctx.r3.u64 = Construct_TXT_83497818_G_(ctx, base); }

uint64_t Construct_TXT_8349781C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349781C_G_ = int32_t(0x8349781C);
	constexpr int32_t str_TXT_820A59C8_B_ = int32_t(0x820A59C8);
	constexpr int32_t Destroy_TXT_8349781C_G__address = int32_t(0x832A1180);
	if (!UseLiftedCode(143, 0x83245A28)) { __imp__sub_83245A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245A28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349781C_G_, str_TXT_820A59C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349781C_G__address);
}
PROMOTED_ENTRY(143, sub_83245A28, 0x83245A28) { ctx.r3.u64 = Construct_TXT_8349781C_G_(ctx, base); }

uint64_t Construct_TXT_83497820_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497820_G_ = int32_t(0x83497820);
	constexpr int32_t str_TXT_820A59E0_B_ = int32_t(0x820A59E0);
	constexpr int32_t Destroy_TXT_83497820_G__address = int32_t(0x832A1190);
	if (!UseLiftedCode(143, 0x83245A68)) { __imp__sub_83245A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245A68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497820_G_, str_TXT_820A59E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497820_G__address);
}
PROMOTED_ENTRY(143, sub_83245A68, 0x83245A68) { ctx.r3.u64 = Construct_TXT_83497820_G_(ctx, base); }

uint64_t Construct_TXT_83497824_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497824_G_ = int32_t(0x83497824);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497824_G__address = int32_t(0x832A11A0);
	if (!UseLiftedCode(143, 0x83245AA8)) { __imp__sub_83245AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245AA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497824_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497824_G__address);
}
PROMOTED_ENTRY(143, sub_83245AA8, 0x83245AA8) { ctx.r3.u64 = Construct_TXT_83497824_G_(ctx, base); }

uint64_t Construct_TXT_83497828_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497828_G_ = int32_t(0x83497828);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497828_G__address = int32_t(0x832A11B0);
	if (!UseLiftedCode(143, 0x83245AE8)) { __imp__sub_83245AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245AE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497828_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497828_G__address);
}
PROMOTED_ENTRY(143, sub_83245AE8, 0x83245AE8) { ctx.r3.u64 = Construct_TXT_83497828_G_(ctx, base); }

uint64_t Construct_TXT_8349782C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349782C_G_ = int32_t(0x8349782C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349782C_G__address = int32_t(0x832A11C0);
	if (!UseLiftedCode(143, 0x83245B28)) { __imp__sub_83245B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245B28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349782C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349782C_G__address);
}
PROMOTED_ENTRY(143, sub_83245B28, 0x83245B28) { ctx.r3.u64 = Construct_TXT_8349782C_G_(ctx, base); }

uint64_t Construct_TXT_83497830_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497830_G_ = int32_t(0x83497830);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497830_G__address = int32_t(0x832A11D0);
	if (!UseLiftedCode(143, 0x83245B68)) { __imp__sub_83245B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245B68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497830_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497830_G__address);
}
PROMOTED_ENTRY(143, sub_83245B68, 0x83245B68) { ctx.r3.u64 = Construct_TXT_83497830_G_(ctx, base); }

uint64_t Construct_TXT_83497834_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497834_G_ = int32_t(0x83497834);
	constexpr int32_t str_TXT_820AC2B8_B_ = int32_t(0x820AC2B8);
	constexpr int32_t Destroy_TXT_83497834_G__address = int32_t(0x832A11E0);
	if (!UseLiftedCode(143, 0x83245BA8)) { __imp__sub_83245BA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245BA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497834_G_, str_TXT_820AC2B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497834_G__address);
}
PROMOTED_ENTRY(143, sub_83245BA8, 0x83245BA8) { ctx.r3.u64 = Construct_TXT_83497834_G_(ctx, base); }

uint64_t Construct_TXT_83497838_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497838_G_ = int32_t(0x83497838);
	constexpr int32_t str_TXT_820AC2D0_B_ = int32_t(0x820AC2D0);
	constexpr int32_t Destroy_TXT_83497838_G__address = int32_t(0x832A11F0);
	if (!UseLiftedCode(143, 0x83245BE8)) { __imp__sub_83245BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245BE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497838_G_, str_TXT_820AC2D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497838_G__address);
}
PROMOTED_ENTRY(143, sub_83245BE8, 0x83245BE8) { ctx.r3.u64 = Construct_TXT_83497838_G_(ctx, base); }

uint64_t Construct_TXT_8349783C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349783C_G_ = int32_t(0x8349783C);
	constexpr int32_t str_TXT_820AC2F0_B_ = int32_t(0x820AC2F0);
	constexpr int32_t Destroy_TXT_8349783C_G__address = int32_t(0x832A1200);
	if (!UseLiftedCode(143, 0x83245C28)) { __imp__sub_83245C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245C28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349783C_G_, str_TXT_820AC2F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349783C_G__address);
}
PROMOTED_ENTRY(143, sub_83245C28, 0x83245C28) { ctx.r3.u64 = Construct_TXT_8349783C_G_(ctx, base); }

uint64_t Construct_TXT_8349784C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349784C_G_ = int32_t(0x8349784C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_8349784C_G__address = int32_t(0x832A1220);
	if (!UseLiftedCode(143, 0x83245CF8)) { __imp__sub_83245CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245CF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349784C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349784C_G__address);
}
PROMOTED_ENTRY(143, sub_83245CF8, 0x83245CF8) { ctx.r3.u64 = Construct_TXT_8349784C_G_(ctx, base); }

uint64_t Construct_TXT_83497850_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497850_G_ = int32_t(0x83497850);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497850_G__address = int32_t(0x832A1230);
	if (!UseLiftedCode(143, 0x83245D38)) { __imp__sub_83245D38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245D38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497850_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497850_G__address);
}
PROMOTED_ENTRY(143, sub_83245D38, 0x83245D38) { ctx.r3.u64 = Construct_TXT_83497850_G_(ctx, base); }

uint64_t Construct_TXT_83497854_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497854_G_ = int32_t(0x83497854);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497854_G__address = int32_t(0x832A1240);
	if (!UseLiftedCode(143, 0x83245D78)) { __imp__sub_83245D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245D78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497854_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497854_G__address);
}
PROMOTED_ENTRY(143, sub_83245D78, 0x83245D78) { ctx.r3.u64 = Construct_TXT_83497854_G_(ctx, base); }

uint64_t Construct_TXT_83497858_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497858_G_ = int32_t(0x83497858);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497858_G__address = int32_t(0x832A1250);
	if (!UseLiftedCode(143, 0x83245DB8)) { __imp__sub_83245DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497858_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497858_G__address);
}
PROMOTED_ENTRY(143, sub_83245DB8, 0x83245DB8) { ctx.r3.u64 = Construct_TXT_83497858_G_(ctx, base); }

uint64_t Construct_TXT_8349785C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349785C_G_ = int32_t(0x8349785C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349785C_G__address = int32_t(0x832A1260);
	if (!UseLiftedCode(143, 0x83245DF8)) { __imp__sub_83245DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349785C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349785C_G__address);
}
PROMOTED_ENTRY(143, sub_83245DF8, 0x83245DF8) { ctx.r3.u64 = Construct_TXT_8349785C_G_(ctx, base); }

uint64_t Construct_TXT_83497860_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497860_G_ = int32_t(0x83497860);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497860_G__address = int32_t(0x832A1270);
	if (!UseLiftedCode(143, 0x83245E38)) { __imp__sub_83245E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497860_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497860_G__address);
}
PROMOTED_ENTRY(143, sub_83245E38, 0x83245E38) { ctx.r3.u64 = Construct_TXT_83497860_G_(ctx, base); }

uint64_t Construct_TXT_83497864_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497864_G_ = int32_t(0x83497864);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497864_G__address = int32_t(0x832A1280);
	if (!UseLiftedCode(143, 0x83245E78)) { __imp__sub_83245E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497864_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497864_G__address);
}
PROMOTED_ENTRY(143, sub_83245E78, 0x83245E78) { ctx.r3.u64 = Construct_TXT_83497864_G_(ctx, base); }

uint64_t Construct_TXT_8349786C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349786C_G_ = int32_t(0x8349786C);
	constexpr int32_t str_TXT_820AE4B8_B_ = int32_t(0x820AE4B8);
	constexpr int32_t Destroy_TXT_8349786C_G__address = int32_t(0x832A1290);
	if (!UseLiftedCode(143, 0x83245EF0)) { __imp__sub_83245EF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245EF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349786C_G_, str_TXT_820AE4B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349786C_G__address);
}
PROMOTED_ENTRY(143, sub_83245EF0, 0x83245EF0) { ctx.r3.u64 = Construct_TXT_8349786C_G_(ctx, base); }

uint64_t Construct_TXT_8349787C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349787C_G_ = int32_t(0x8349787C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349787C_G__address = int32_t(0x832A12B0);
	if (!UseLiftedCode(143, 0x83245FC0)) { __imp__sub_83245FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83245FC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349787C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349787C_G__address);
}
PROMOTED_ENTRY(143, sub_83245FC0, 0x83245FC0) { ctx.r3.u64 = Construct_TXT_8349787C_G_(ctx, base); }

uint64_t Construct_TXT_83497880_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497880_G_ = int32_t(0x83497880);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497880_G__address = int32_t(0x832A12C0);
	if (!UseLiftedCode(143, 0x83246000)) { __imp__sub_83246000(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246000);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497880_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497880_G__address);
}
PROMOTED_ENTRY(143, sub_83246000, 0x83246000) { ctx.r3.u64 = Construct_TXT_83497880_G_(ctx, base); }

uint64_t Construct_TXT_83497884_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497884_G_ = int32_t(0x83497884);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497884_G__address = int32_t(0x832A12D0);
	if (!UseLiftedCode(143, 0x83246040)) { __imp__sub_83246040(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246040);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497884_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497884_G__address);
}
PROMOTED_ENTRY(143, sub_83246040, 0x83246040) { ctx.r3.u64 = Construct_TXT_83497884_G_(ctx, base); }

uint64_t Construct_TXT_834978E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834978E0_G_ = int32_t(0x834978E0);
	constexpr int32_t str_TXT_820AE8C0_B_ = int32_t(0x820AE8C0);
	constexpr int32_t Destroy_TXT_834978E0_G__address = int32_t(0x832A12E0);
	if (!UseLiftedCode(143, 0x83246348)) { __imp__sub_83246348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246348);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E0_G_, str_TXT_820AE8C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834978E0_G__address);
}
PROMOTED_ENTRY(143, sub_83246348, 0x83246348) { ctx.r3.u64 = Construct_TXT_834978E0_G_(ctx, base); }

uint64_t Construct_TXT_834978E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834978E4_G_ = int32_t(0x834978E4);
	constexpr int32_t str_TXT_820AE8D0_B_ = int32_t(0x820AE8D0);
	constexpr int32_t Destroy_TXT_834978E4_G__address = int32_t(0x832A12F0);
	if (!UseLiftedCode(143, 0x83246388)) { __imp__sub_83246388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E4_G_, str_TXT_820AE8D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834978E4_G__address);
}
PROMOTED_ENTRY(143, sub_83246388, 0x83246388) { ctx.r3.u64 = Construct_TXT_834978E4_G_(ctx, base); }

uint64_t Construct_TXT_834978E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834978E8_G_ = int32_t(0x834978E8);
	constexpr int32_t str_TXT_820AE8E0_B_ = int32_t(0x820AE8E0);
	constexpr int32_t Destroy_TXT_834978E8_G__address = int32_t(0x832A1300);
	if (!UseLiftedCode(143, 0x832463C8)) { __imp__sub_832463C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832463C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834978E8_G_, str_TXT_820AE8E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834978E8_G__address);
}
PROMOTED_ENTRY(143, sub_832463C8, 0x832463C8) { ctx.r3.u64 = Construct_TXT_834978E8_G_(ctx, base); }

uint64_t Construct_TXT_834978EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834978EC_G_ = int32_t(0x834978EC);
	constexpr int32_t str_TXT_820AE8EC_B_ = int32_t(0x820AE8EC);
	constexpr int32_t Destroy_TXT_834978EC_G__address = int32_t(0x832A1310);
	if (!UseLiftedCode(143, 0x83246690)) { __imp__sub_83246690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246690);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834978EC_G_, str_TXT_820AE8EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834978EC_G__address);
}
PROMOTED_ENTRY(143, sub_83246690, 0x83246690) { ctx.r3.u64 = Construct_TXT_834978EC_G_(ctx, base); }

uint64_t Construct_TXT_83497970_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497970_G_ = int32_t(0x83497970);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497970_G__address = int32_t(0x832A1320);
	if (!UseLiftedCode(143, 0x83246790)) { __imp__sub_83246790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497970_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497970_G__address);
}
PROMOTED_ENTRY(143, sub_83246790, 0x83246790) { ctx.r3.u64 = Construct_TXT_83497970_G_(ctx, base); }

uint64_t Construct_TXT_83497980_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497980_G_ = int32_t(0x83497980);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497980_G__address = int32_t(0x832A1338);
	if (!UseLiftedCode(143, 0x83246920)) { __imp__sub_83246920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246920);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497980_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497980_G__address);
}
PROMOTED_ENTRY(143, sub_83246920, 0x83246920) { ctx.r3.u64 = Construct_TXT_83497980_G_(ctx, base); }

uint64_t Construct_TXT_83497984_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497984_G_ = int32_t(0x83497984);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497984_G__address = int32_t(0x832A1348);
	if (!UseLiftedCode(143, 0x83246960)) { __imp__sub_83246960(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246960);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497984_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497984_G__address);
}
PROMOTED_ENTRY(143, sub_83246960, 0x83246960) { ctx.r3.u64 = Construct_TXT_83497984_G_(ctx, base); }

uint64_t Construct_TXT_83497988_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497988_G_ = int32_t(0x83497988);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497988_G__address = int32_t(0x832A1358);
	if (!UseLiftedCode(143, 0x832469A0)) { __imp__sub_832469A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832469A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497988_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497988_G__address);
}
PROMOTED_ENTRY(143, sub_832469A0, 0x832469A0) { ctx.r3.u64 = Construct_TXT_83497988_G_(ctx, base); }

uint64_t Construct_TXT_834979E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979E0_G_ = int32_t(0x834979E0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834979E0_G__address = int32_t(0x832A1368);
	if (!UseLiftedCode(143, 0x83246E78)) { __imp__sub_83246E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979E0_G__address);
}
PROMOTED_ENTRY(143, sub_83246E78, 0x83246E78) { ctx.r3.u64 = Construct_TXT_834979E0_G_(ctx, base); }

uint64_t Construct_TXT_834979E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979E4_G_ = int32_t(0x834979E4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834979E4_G__address = int32_t(0x832A1378);
	if (!UseLiftedCode(143, 0x83246EB8)) { __imp__sub_83246EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979E4_G__address);
}
PROMOTED_ENTRY(143, sub_83246EB8, 0x83246EB8) { ctx.r3.u64 = Construct_TXT_834979E4_G_(ctx, base); }

uint64_t Construct_TXT_834979E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979E8_G_ = int32_t(0x834979E8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834979E8_G__address = int32_t(0x832A1388);
	if (!UseLiftedCode(143, 0x83246EF8)) { __imp__sub_83246EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979E8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979E8_G__address);
}
PROMOTED_ENTRY(143, sub_83246EF8, 0x83246EF8) { ctx.r3.u64 = Construct_TXT_834979E8_G_(ctx, base); }

uint64_t Construct_TXT_834979EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979EC_G_ = int32_t(0x834979EC);
	constexpr int32_t str_TXT_820AEB74_B_ = int32_t(0x820AEB74);
	constexpr int32_t Destroy_TXT_834979EC_G__address = int32_t(0x832A1398);
	if (!UseLiftedCode(143, 0x83246F38)) { __imp__sub_83246F38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246F38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979EC_G_, str_TXT_820AEB74_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979EC_G__address);
}
PROMOTED_ENTRY(143, sub_83246F38, 0x83246F38) { ctx.r3.u64 = Construct_TXT_834979EC_G_(ctx, base); }

uint64_t Construct_TXT_834979F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979F0_G_ = int32_t(0x834979F0);
	constexpr int32_t str_TXT_820AEB94_B_ = int32_t(0x820AEB94);
	constexpr int32_t Destroy_TXT_834979F0_G__address = int32_t(0x832A13A8);
	if (!UseLiftedCode(143, 0x83246F78)) { __imp__sub_83246F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246F78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F0_G_, str_TXT_820AEB94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979F0_G__address);
}
PROMOTED_ENTRY(143, sub_83246F78, 0x83246F78) { ctx.r3.u64 = Construct_TXT_834979F0_G_(ctx, base); }

uint64_t Construct_TXT_834979F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979F4_G_ = int32_t(0x834979F4);
	constexpr int32_t str_TXT_820AEBB8_B_ = int32_t(0x820AEBB8);
	constexpr int32_t Destroy_TXT_834979F4_G__address = int32_t(0x832A13B8);
	if (!UseLiftedCode(143, 0x83246FB8)) { __imp__sub_83246FB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246FB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F4_G_, str_TXT_820AEBB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979F4_G__address);
}
PROMOTED_ENTRY(143, sub_83246FB8, 0x83246FB8) { ctx.r3.u64 = Construct_TXT_834979F4_G_(ctx, base); }

uint64_t Construct_TXT_834979F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979F8_G_ = int32_t(0x834979F8);
	constexpr int32_t str_TXT_820AEBC8_B_ = int32_t(0x820AEBC8);
	constexpr int32_t Destroy_TXT_834979F8_G__address = int32_t(0x832A13C8);
	if (!UseLiftedCode(143, 0x83246FF8)) { __imp__sub_83246FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83246FF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979F8_G_, str_TXT_820AEBC8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979F8_G__address);
}
PROMOTED_ENTRY(143, sub_83246FF8, 0x83246FF8) { ctx.r3.u64 = Construct_TXT_834979F8_G_(ctx, base); }

uint64_t Construct_TXT_834979FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834979FC_G_ = int32_t(0x834979FC);
	constexpr int32_t str_TXT_820AEBE8_B_ = int32_t(0x820AEBE8);
	constexpr int32_t Destroy_TXT_834979FC_G__address = int32_t(0x832A13D8);
	if (!UseLiftedCode(143, 0x83247038)) { __imp__sub_83247038(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247038);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834979FC_G_, str_TXT_820AEBE8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834979FC_G__address);
}
PROMOTED_ENTRY(143, sub_83247038, 0x83247038) { ctx.r3.u64 = Construct_TXT_834979FC_G_(ctx, base); }

uint64_t Construct_TXT_83497A00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A00_G_ = int32_t(0x83497A00);
	constexpr int32_t str_TXT_820AEBFC_B_ = int32_t(0x820AEBFC);
	constexpr int32_t Destroy_TXT_83497A00_G__address = int32_t(0x832A13E8);
	if (!UseLiftedCode(143, 0x83247078)) { __imp__sub_83247078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247078);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A00_G_, str_TXT_820AEBFC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A00_G__address);
}
PROMOTED_ENTRY(143, sub_83247078, 0x83247078) { ctx.r3.u64 = Construct_TXT_83497A00_G_(ctx, base); }

uint64_t Construct_TXT_83497A04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A04_G_ = int32_t(0x83497A04);
	constexpr int32_t str_TXT_820AEC10_B_ = int32_t(0x820AEC10);
	constexpr int32_t Destroy_TXT_83497A04_G__address = int32_t(0x832A13F8);
	if (!UseLiftedCode(143, 0x832470B8)) { __imp__sub_832470B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832470B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A04_G_, str_TXT_820AEC10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A04_G__address);
}
PROMOTED_ENTRY(143, sub_832470B8, 0x832470B8) { ctx.r3.u64 = Construct_TXT_83497A04_G_(ctx, base); }

uint64_t Construct_TXT_83497A08_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A08_G_ = int32_t(0x83497A08);
	constexpr int32_t str_TXT_820AEC2C_B_ = int32_t(0x820AEC2C);
	constexpr int32_t Destroy_TXT_83497A08_G__address = int32_t(0x832A1408);
	if (!UseLiftedCode(143, 0x832470F8)) { __imp__sub_832470F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832470F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A08_G_, str_TXT_820AEC2C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A08_G__address);
}
PROMOTED_ENTRY(143, sub_832470F8, 0x832470F8) { ctx.r3.u64 = Construct_TXT_83497A08_G_(ctx, base); }

uint64_t Construct_TXT_83497A0C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A0C_G_ = int32_t(0x83497A0C);
	constexpr int32_t str_TXT_820AEC40_B_ = int32_t(0x820AEC40);
	constexpr int32_t Destroy_TXT_83497A0C_G__address = int32_t(0x832A1418);
	if (!UseLiftedCode(143, 0x83247138)) { __imp__sub_83247138(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247138);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A0C_G_, str_TXT_820AEC40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A0C_G__address);
}
PROMOTED_ENTRY(143, sub_83247138, 0x83247138) { ctx.r3.u64 = Construct_TXT_83497A0C_G_(ctx, base); }

uint64_t Construct_TXT_83497A10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A10_G_ = int32_t(0x83497A10);
	constexpr int32_t str_TXT_820AEC54_B_ = int32_t(0x820AEC54);
	constexpr int32_t Destroy_TXT_83497A10_G__address = int32_t(0x832A1428);
	if (!UseLiftedCode(143, 0x83247178)) { __imp__sub_83247178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247178);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A10_G_, str_TXT_820AEC54_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A10_G__address);
}
PROMOTED_ENTRY(143, sub_83247178, 0x83247178) { ctx.r3.u64 = Construct_TXT_83497A10_G_(ctx, base); }

uint64_t Construct_TXT_83497A14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A14_G_ = int32_t(0x83497A14);
	constexpr int32_t str_TXT_820AEC64_B_ = int32_t(0x820AEC64);
	constexpr int32_t Destroy_TXT_83497A14_G__address = int32_t(0x832A1438);
	if (!UseLiftedCode(143, 0x832471B8)) { __imp__sub_832471B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832471B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A14_G_, str_TXT_820AEC64_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A14_G__address);
}
PROMOTED_ENTRY(143, sub_832471B8, 0x832471B8) { ctx.r3.u64 = Construct_TXT_83497A14_G_(ctx, base); }

uint64_t Construct_TXT_83497A18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A18_G_ = int32_t(0x83497A18);
	constexpr int32_t str_TXT_820AEC78_B_ = int32_t(0x820AEC78);
	constexpr int32_t Destroy_TXT_83497A18_G__address = int32_t(0x832A1448);
	if (!UseLiftedCode(143, 0x832471F8)) { __imp__sub_832471F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832471F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A18_G_, str_TXT_820AEC78_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A18_G__address);
}
PROMOTED_ENTRY(143, sub_832471F8, 0x832471F8) { ctx.r3.u64 = Construct_TXT_83497A18_G_(ctx, base); }

uint64_t Construct_TXT_83497A1C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A1C_G_ = int32_t(0x83497A1C);
	constexpr int32_t str_TXT_820AEC90_B_ = int32_t(0x820AEC90);
	constexpr int32_t Destroy_TXT_83497A1C_G__address = int32_t(0x832A1458);
	if (!UseLiftedCode(143, 0x83247238)) { __imp__sub_83247238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247238);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A1C_G_, str_TXT_820AEC90_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A1C_G__address);
}
PROMOTED_ENTRY(143, sub_83247238, 0x83247238) { ctx.r3.u64 = Construct_TXT_83497A1C_G_(ctx, base); }

uint64_t Construct_TXT_83497A20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A20_G_ = int32_t(0x83497A20);
	constexpr int32_t str_TXT_820AECA4_B_ = int32_t(0x820AECA4);
	constexpr int32_t Destroy_TXT_83497A20_G__address = int32_t(0x832A1468);
	if (!UseLiftedCode(143, 0x83247278)) { __imp__sub_83247278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A20_G_, str_TXT_820AECA4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A20_G__address);
}
PROMOTED_ENTRY(143, sub_83247278, 0x83247278) { ctx.r3.u64 = Construct_TXT_83497A20_G_(ctx, base); }

uint64_t Construct_TXT_83497A24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A24_G_ = int32_t(0x83497A24);
	constexpr int32_t str_TXT_820AECB8_B_ = int32_t(0x820AECB8);
	constexpr int32_t Destroy_TXT_83497A24_G__address = int32_t(0x832A1478);
	if (!UseLiftedCode(143, 0x832472B8)) { __imp__sub_832472B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832472B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A24_G_, str_TXT_820AECB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A24_G__address);
}
PROMOTED_ENTRY(143, sub_832472B8, 0x832472B8) { ctx.r3.u64 = Construct_TXT_83497A24_G_(ctx, base); }

uint64_t Construct_TXT_83497A28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A28_G_ = int32_t(0x83497A28);
	constexpr int32_t str_TXT_820AECD0_B_ = int32_t(0x820AECD0);
	constexpr int32_t Destroy_TXT_83497A28_G__address = int32_t(0x832A1488);
	if (!UseLiftedCode(143, 0x832472F8)) { __imp__sub_832472F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832472F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A28_G_, str_TXT_820AECD0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A28_G__address);
}
PROMOTED_ENTRY(143, sub_832472F8, 0x832472F8) { ctx.r3.u64 = Construct_TXT_83497A28_G_(ctx, base); }

uint64_t Construct_TXT_83497A2C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A2C_G_ = int32_t(0x83497A2C);
	constexpr int32_t str_TXT_820AECE4_B_ = int32_t(0x820AECE4);
	constexpr int32_t Destroy_TXT_83497A2C_G__address = int32_t(0x832A1498);
	if (!UseLiftedCode(143, 0x83247338)) { __imp__sub_83247338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247338);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A2C_G_, str_TXT_820AECE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A2C_G__address);
}
PROMOTED_ENTRY(143, sub_83247338, 0x83247338) { ctx.r3.u64 = Construct_TXT_83497A2C_G_(ctx, base); }

uint64_t Construct_TXT_83497A34_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A34_G_ = int32_t(0x83497A34);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497A34_G__address = int32_t(0x832A14A8);
	if (!UseLiftedCode(143, 0x832473B0)) { __imp__sub_832473B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832473B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A34_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A34_G__address);
}
PROMOTED_ENTRY(143, sub_832473B0, 0x832473B0) { ctx.r3.u64 = Construct_TXT_83497A34_G_(ctx, base); }

uint64_t Construct_TXT_83497A38_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A38_G_ = int32_t(0x83497A38);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497A38_G__address = int32_t(0x832A14B8);
	if (!UseLiftedCode(143, 0x832473F0)) { __imp__sub_832473F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832473F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A38_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A38_G__address);
}
PROMOTED_ENTRY(143, sub_832473F0, 0x832473F0) { ctx.r3.u64 = Construct_TXT_83497A38_G_(ctx, base); }

uint64_t Construct_TXT_83497A3C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A3C_G_ = int32_t(0x83497A3C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497A3C_G__address = int32_t(0x832A14C8);
	if (!UseLiftedCode(143, 0x83247430)) { __imp__sub_83247430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247430);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A3C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A3C_G__address);
}
PROMOTED_ENTRY(143, sub_83247430, 0x83247430) { ctx.r3.u64 = Construct_TXT_83497A3C_G_(ctx, base); }

uint64_t Construct_TXT_83497A60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A60_G_ = int32_t(0x83497A60);
	constexpr int32_t str_TXT_820AEF44_B_ = int32_t(0x820AEF44);
	constexpr int32_t Destroy_TXT_83497A60_G__address = int32_t(0x832A14D8);
	if (!UseLiftedCode(143, 0x83247630)) { __imp__sub_83247630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A60_G_, str_TXT_820AEF44_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A60_G__address);
}
PROMOTED_ENTRY(143, sub_83247630, 0x83247630) { ctx.r3.u64 = Construct_TXT_83497A60_G_(ctx, base); }

uint64_t Construct_TXT_83497A64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A64_G_ = int32_t(0x83497A64);
	constexpr int32_t str_TXT_820AEF58_B_ = int32_t(0x820AEF58);
	constexpr int32_t Destroy_TXT_83497A64_G__address = int32_t(0x832A14E8);
	if (!UseLiftedCode(143, 0x83247670)) { __imp__sub_83247670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A64_G_, str_TXT_820AEF58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A64_G__address);
}
PROMOTED_ENTRY(143, sub_83247670, 0x83247670) { ctx.r3.u64 = Construct_TXT_83497A64_G_(ctx, base); }

uint64_t Construct_TXT_83497A68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A68_G_ = int32_t(0x83497A68);
	constexpr int32_t str_TXT_820A4D58_B_ = int32_t(0x820A4D58);
	constexpr int32_t Destroy_TXT_83497A68_G__address = int32_t(0x832A14F8);
	if (!UseLiftedCode(143, 0x832476B0)) { __imp__sub_832476B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832476B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A68_G_, str_TXT_820A4D58_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A68_G__address);
}
PROMOTED_ENTRY(143, sub_832476B0, 0x832476B0) { ctx.r3.u64 = Construct_TXT_83497A68_G_(ctx, base); }

uint64_t Construct_TXT_83497A6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A6C_G_ = int32_t(0x83497A6C);
	constexpr int32_t str_TXT_820AEF6C_B_ = int32_t(0x820AEF6C);
	constexpr int32_t Destroy_TXT_83497A6C_G__address = int32_t(0x832A1508);
	if (!UseLiftedCode(143, 0x832476F0)) { __imp__sub_832476F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832476F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A6C_G_, str_TXT_820AEF6C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A6C_G__address);
}
PROMOTED_ENTRY(143, sub_832476F0, 0x832476F0) { ctx.r3.u64 = Construct_TXT_83497A6C_G_(ctx, base); }

uint64_t Construct_TXT_83497A70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A70_G_ = int32_t(0x83497A70);
	constexpr int32_t str_TXT_820AEF84_B_ = int32_t(0x820AEF84);
	constexpr int32_t Destroy_TXT_83497A70_G__address = int32_t(0x832A1518);
	if (!UseLiftedCode(143, 0x83247730)) { __imp__sub_83247730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A70_G_, str_TXT_820AEF84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A70_G__address);
}
PROMOTED_ENTRY(143, sub_83247730, 0x83247730) { ctx.r3.u64 = Construct_TXT_83497A70_G_(ctx, base); }

uint64_t Construct_TXT_83497A74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A74_G_ = int32_t(0x83497A74);
	constexpr int32_t str_TXT_820AEF98_B_ = int32_t(0x820AEF98);
	constexpr int32_t Destroy_TXT_83497A74_G__address = int32_t(0x832A1528);
	if (!UseLiftedCode(143, 0x83247770)) { __imp__sub_83247770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A74_G_, str_TXT_820AEF98_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A74_G__address);
}
PROMOTED_ENTRY(143, sub_83247770, 0x83247770) { ctx.r3.u64 = Construct_TXT_83497A74_G_(ctx, base); }

uint64_t Construct_TXT_83497A78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A78_G_ = int32_t(0x83497A78);
	constexpr int32_t str_TXT_820AEFB8_B_ = int32_t(0x820AEFB8);
	constexpr int32_t Destroy_TXT_83497A78_G__address = int32_t(0x832A1538);
	if (!UseLiftedCode(143, 0x832477B0)) { __imp__sub_832477B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832477B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A78_G_, str_TXT_820AEFB8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A78_G__address);
}
PROMOTED_ENTRY(143, sub_832477B0, 0x832477B0) { ctx.r3.u64 = Construct_TXT_83497A78_G_(ctx, base); }

uint64_t Construct_TXT_83497A7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497A7C_G_ = int32_t(0x83497A7C);
	constexpr int32_t str_TXT_820AEFD8_B_ = int32_t(0x820AEFD8);
	constexpr int32_t Destroy_TXT_83497A7C_G__address = int32_t(0x832A1548);
	if (!UseLiftedCode(143, 0x832477F0)) { __imp__sub_832477F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832477F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497A7C_G_, str_TXT_820AEFD8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497A7C_G__address);
}
PROMOTED_ENTRY(143, sub_832477F0, 0x832477F0) { ctx.r3.u64 = Construct_TXT_83497A7C_G_(ctx, base); }

uint64_t Construct_TXT_83497AA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AA0_G_ = int32_t(0x83497AA0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497AA0_G__address = int32_t(0x832A15C0);
	if (!UseLiftedCode(143, 0x83247908)) { __imp__sub_83247908(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247908);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AA0_G__address);
}
PROMOTED_ENTRY(143, sub_83247908, 0x83247908) { ctx.r3.u64 = Construct_TXT_83497AA0_G_(ctx, base); }

uint64_t Construct_TXT_83497AA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AA4_G_ = int32_t(0x83497AA4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497AA4_G__address = int32_t(0x832A15D0);
	if (!UseLiftedCode(143, 0x83247948)) { __imp__sub_83247948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247948);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AA4_G__address);
}
PROMOTED_ENTRY(143, sub_83247948, 0x83247948) { ctx.r3.u64 = Construct_TXT_83497AA4_G_(ctx, base); }

uint64_t Construct_TXT_83497AA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AA8_G_ = int32_t(0x83497AA8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497AA8_G__address = int32_t(0x832A15E0);
	if (!UseLiftedCode(143, 0x83247988)) { __imp__sub_83247988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247988);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AA8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AA8_G__address);
}
PROMOTED_ENTRY(143, sub_83247988, 0x83247988) { ctx.r3.u64 = Construct_TXT_83497AA8_G_(ctx, base); }

uint64_t Construct_TXT_83497AAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AAC_G_ = int32_t(0x83497AAC);
	constexpr int32_t str_TXT_820AF09C_B_ = int32_t(0x820AF09C);
	constexpr int32_t Destroy_TXT_83497AAC_G__address = int32_t(0x832A15F0);
	if (!UseLiftedCode(143, 0x832479C8)) { __imp__sub_832479C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832479C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AAC_G_, str_TXT_820AF09C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AAC_G__address);
}
PROMOTED_ENTRY(143, sub_832479C8, 0x832479C8) { ctx.r3.u64 = Construct_TXT_83497AAC_G_(ctx, base); }

uint64_t Construct_TXT_83497AB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AB0_G_ = int32_t(0x83497AB0);
	constexpr int32_t str_TXT_820AF0BC_B_ = int32_t(0x820AF0BC);
	constexpr int32_t Destroy_TXT_83497AB0_G__address = int32_t(0x832A1600);
	if (!UseLiftedCode(143, 0x83247A08)) { __imp__sub_83247A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB0_G_, str_TXT_820AF0BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AB0_G__address);
}
PROMOTED_ENTRY(143, sub_83247A08, 0x83247A08) { ctx.r3.u64 = Construct_TXT_83497AB0_G_(ctx, base); }

uint64_t Construct_TXT_83497AB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AB4_G_ = int32_t(0x83497AB4);
	constexpr int32_t str_TXT_820AF0E0_B_ = int32_t(0x820AF0E0);
	constexpr int32_t Destroy_TXT_83497AB4_G__address = int32_t(0x832A1610);
	if (!UseLiftedCode(143, 0x83247A48)) { __imp__sub_83247A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB4_G_, str_TXT_820AF0E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AB4_G__address);
}
PROMOTED_ENTRY(143, sub_83247A48, 0x83247A48) { ctx.r3.u64 = Construct_TXT_83497AB4_G_(ctx, base); }

uint64_t Construct_TXT_83497AB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AB8_G_ = int32_t(0x83497AB8);
	constexpr int32_t str_TXT_820AF104_B_ = int32_t(0x820AF104);
	constexpr int32_t Destroy_TXT_83497AB8_G__address = int32_t(0x832A1620);
	if (!UseLiftedCode(143, 0x83247A88)) { __imp__sub_83247A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247A88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AB8_G_, str_TXT_820AF104_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AB8_G__address);
}
PROMOTED_ENTRY(143, sub_83247A88, 0x83247A88) { ctx.r3.u64 = Construct_TXT_83497AB8_G_(ctx, base); }

uint64_t Construct_TXT_83497ABC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497ABC_G_ = int32_t(0x83497ABC);
	constexpr int32_t str_TXT_820AF12C_B_ = int32_t(0x820AF12C);
	constexpr int32_t Destroy_TXT_83497ABC_G__address = int32_t(0x832A1630);
	if (!UseLiftedCode(143, 0x83247AC8)) { __imp__sub_83247AC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247AC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ABC_G_, str_TXT_820AF12C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497ABC_G__address);
}
PROMOTED_ENTRY(143, sub_83247AC8, 0x83247AC8) { ctx.r3.u64 = Construct_TXT_83497ABC_G_(ctx, base); }

uint64_t Construct_TXT_83497AC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AC0_G_ = int32_t(0x83497AC0);
	constexpr int32_t str_TXT_820A8F8C_B_ = int32_t(0x820A8F8C);
	constexpr int32_t Destroy_TXT_83497AC0_G__address = int32_t(0x832A1640);
	if (!UseLiftedCode(143, 0x83247B08)) { __imp__sub_83247B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC0_G_, str_TXT_820A8F8C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AC0_G__address);
}
PROMOTED_ENTRY(143, sub_83247B08, 0x83247B08) { ctx.r3.u64 = Construct_TXT_83497AC0_G_(ctx, base); }

uint64_t Construct_TXT_83497AC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AC4_G_ = int32_t(0x83497AC4);
	constexpr int32_t str_TXT_820A8F94_B_ = int32_t(0x820A8F94);
	constexpr int32_t Destroy_TXT_83497AC4_G__address = int32_t(0x832A1650);
	if (!UseLiftedCode(143, 0x83247B48)) { __imp__sub_83247B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC4_G_, str_TXT_820A8F94_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AC4_G__address);
}
PROMOTED_ENTRY(143, sub_83247B48, 0x83247B48) { ctx.r3.u64 = Construct_TXT_83497AC4_G_(ctx, base); }

uint64_t Construct_TXT_83497AC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AC8_G_ = int32_t(0x83497AC8);
	constexpr int32_t str_TXT_820A8F9C_B_ = int32_t(0x820A8F9C);
	constexpr int32_t Destroy_TXT_83497AC8_G__address = int32_t(0x832A1660);
	if (!UseLiftedCode(143, 0x83247B88)) { __imp__sub_83247B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247B88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AC8_G_, str_TXT_820A8F9C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AC8_G__address);
}
PROMOTED_ENTRY(143, sub_83247B88, 0x83247B88) { ctx.r3.u64 = Construct_TXT_83497AC8_G_(ctx, base); }

uint64_t Construct_TXT_83497ACC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497ACC_G_ = int32_t(0x83497ACC);
	constexpr int32_t str_TXT_820A8FA8_B_ = int32_t(0x820A8FA8);
	constexpr int32_t Destroy_TXT_83497ACC_G__address = int32_t(0x832A1670);
	if (!UseLiftedCode(143, 0x83247BC8)) { __imp__sub_83247BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247BC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ACC_G_, str_TXT_820A8FA8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497ACC_G__address);
}
PROMOTED_ENTRY(143, sub_83247BC8, 0x83247BC8) { ctx.r3.u64 = Construct_TXT_83497ACC_G_(ctx, base); }

uint64_t Construct_TXT_83497AD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AD0_G_ = int32_t(0x83497AD0);
	constexpr int32_t str_TXT_820A8FB0_B_ = int32_t(0x820A8FB0);
	constexpr int32_t Destroy_TXT_83497AD0_G__address = int32_t(0x832A1680);
	if (!UseLiftedCode(143, 0x83247C08)) { __imp__sub_83247C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD0_G_, str_TXT_820A8FB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AD0_G__address);
}
PROMOTED_ENTRY(143, sub_83247C08, 0x83247C08) { ctx.r3.u64 = Construct_TXT_83497AD0_G_(ctx, base); }

uint64_t Construct_TXT_83497AD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AD4_G_ = int32_t(0x83497AD4);
	constexpr int32_t str_TXT_820A8FBC_B_ = int32_t(0x820A8FBC);
	constexpr int32_t Destroy_TXT_83497AD4_G__address = int32_t(0x832A1690);
	if (!UseLiftedCode(143, 0x83247C48)) { __imp__sub_83247C48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD4_G_, str_TXT_820A8FBC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AD4_G__address);
}
PROMOTED_ENTRY(143, sub_83247C48, 0x83247C48) { ctx.r3.u64 = Construct_TXT_83497AD4_G_(ctx, base); }

uint64_t Construct_TXT_83497AD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AD8_G_ = int32_t(0x83497AD8);
	constexpr int32_t str_TXT_820A8FCC_B_ = int32_t(0x820A8FCC);
	constexpr int32_t Destroy_TXT_83497AD8_G__address = int32_t(0x832A16A0);
	if (!UseLiftedCode(143, 0x83247C88)) { __imp__sub_83247C88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247C88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AD8_G_, str_TXT_820A8FCC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AD8_G__address);
}
PROMOTED_ENTRY(143, sub_83247C88, 0x83247C88) { ctx.r3.u64 = Construct_TXT_83497AD8_G_(ctx, base); }

uint64_t Construct_TXT_83497ADC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497ADC_G_ = int32_t(0x83497ADC);
	constexpr int32_t str_TXT_820A8FD4_B_ = int32_t(0x820A8FD4);
	constexpr int32_t Destroy_TXT_83497ADC_G__address = int32_t(0x832A16B0);
	if (!UseLiftedCode(143, 0x83247CC8)) { __imp__sub_83247CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247CC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497ADC_G_, str_TXT_820A8FD4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497ADC_G__address);
}
PROMOTED_ENTRY(143, sub_83247CC8, 0x83247CC8) { ctx.r3.u64 = Construct_TXT_83497ADC_G_(ctx, base); }

uint64_t Construct_TXT_83497AE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AE0_G_ = int32_t(0x83497AE0);
	constexpr int32_t str_TXT_820A8FE4_B_ = int32_t(0x820A8FE4);
	constexpr int32_t Destroy_TXT_83497AE0_G__address = int32_t(0x832A16C0);
	if (!UseLiftedCode(143, 0x83247D08)) { __imp__sub_83247D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE0_G_, str_TXT_820A8FE4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AE0_G__address);
}
PROMOTED_ENTRY(143, sub_83247D08, 0x83247D08) { ctx.r3.u64 = Construct_TXT_83497AE0_G_(ctx, base); }

uint64_t Construct_TXT_83497AE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AE4_G_ = int32_t(0x83497AE4);
	constexpr int32_t str_TXT_820A8FEC_B_ = int32_t(0x820A8FEC);
	constexpr int32_t Destroy_TXT_83497AE4_G__address = int32_t(0x832A16D0);
	if (!UseLiftedCode(143, 0x83247D48)) { __imp__sub_83247D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE4_G_, str_TXT_820A8FEC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AE4_G__address);
}
PROMOTED_ENTRY(143, sub_83247D48, 0x83247D48) { ctx.r3.u64 = Construct_TXT_83497AE4_G_(ctx, base); }

uint64_t Construct_TXT_83497AE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AE8_G_ = int32_t(0x83497AE8);
	constexpr int32_t str_TXT_820A8FF4_B_ = int32_t(0x820A8FF4);
	constexpr int32_t Destroy_TXT_83497AE8_G__address = int32_t(0x832A16E0);
	if (!UseLiftedCode(143, 0x83247D88)) { __imp__sub_83247D88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247D88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AE8_G_, str_TXT_820A8FF4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AE8_G__address);
}
PROMOTED_ENTRY(143, sub_83247D88, 0x83247D88) { ctx.r3.u64 = Construct_TXT_83497AE8_G_(ctx, base); }

uint64_t Construct_TXT_83497AEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AEC_G_ = int32_t(0x83497AEC);
	constexpr int32_t str_TXT_820A9000_B_ = int32_t(0x820A9000);
	constexpr int32_t Destroy_TXT_83497AEC_G__address = int32_t(0x832A16F0);
	if (!UseLiftedCode(143, 0x83247DC8)) { __imp__sub_83247DC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247DC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AEC_G_, str_TXT_820A9000_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AEC_G__address);
}
PROMOTED_ENTRY(143, sub_83247DC8, 0x83247DC8) { ctx.r3.u64 = Construct_TXT_83497AEC_G_(ctx, base); }

uint64_t Construct_TXT_83497AF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AF0_G_ = int32_t(0x83497AF0);
	constexpr int32_t str_TXT_820A9008_B_ = int32_t(0x820A9008);
	constexpr int32_t Destroy_TXT_83497AF0_G__address = int32_t(0x832A1700);
	if (!UseLiftedCode(143, 0x83247E08)) { __imp__sub_83247E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF0_G_, str_TXT_820A9008_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AF0_G__address);
}
PROMOTED_ENTRY(143, sub_83247E08, 0x83247E08) { ctx.r3.u64 = Construct_TXT_83497AF0_G_(ctx, base); }

uint64_t Construct_TXT_83497AF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AF4_G_ = int32_t(0x83497AF4);
	constexpr int32_t str_TXT_820A9010_B_ = int32_t(0x820A9010);
	constexpr int32_t Destroy_TXT_83497AF4_G__address = int32_t(0x832A1710);
	if (!UseLiftedCode(143, 0x83247E48)) { __imp__sub_83247E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF4_G_, str_TXT_820A9010_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AF4_G__address);
}
PROMOTED_ENTRY(143, sub_83247E48, 0x83247E48) { ctx.r3.u64 = Construct_TXT_83497AF4_G_(ctx, base); }

uint64_t Construct_TXT_83497AF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AF8_G_ = int32_t(0x83497AF8);
	constexpr int32_t str_TXT_820A9018_B_ = int32_t(0x820A9018);
	constexpr int32_t Destroy_TXT_83497AF8_G__address = int32_t(0x832A1720);
	if (!UseLiftedCode(143, 0x83247E88)) { __imp__sub_83247E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247E88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AF8_G_, str_TXT_820A9018_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AF8_G__address);
}
PROMOTED_ENTRY(143, sub_83247E88, 0x83247E88) { ctx.r3.u64 = Construct_TXT_83497AF8_G_(ctx, base); }

uint64_t Construct_TXT_83497AFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497AFC_G_ = int32_t(0x83497AFC);
	constexpr int32_t str_TXT_820A9020_B_ = int32_t(0x820A9020);
	constexpr int32_t Destroy_TXT_83497AFC_G__address = int32_t(0x832A1730);
	if (!UseLiftedCode(143, 0x83247EC8)) { __imp__sub_83247EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247EC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497AFC_G_, str_TXT_820A9020_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497AFC_G__address);
}
PROMOTED_ENTRY(143, sub_83247EC8, 0x83247EC8) { ctx.r3.u64 = Construct_TXT_83497AFC_G_(ctx, base); }

uint64_t Construct_TXT_83497B00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B00_G_ = int32_t(0x83497B00);
	constexpr int32_t str_TXT_820A9028_B_ = int32_t(0x820A9028);
	constexpr int32_t Destroy_TXT_83497B00_G__address = int32_t(0x832A1740);
	if (!UseLiftedCode(143, 0x83247F08)) { __imp__sub_83247F08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F08);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B00_G_, str_TXT_820A9028_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B00_G__address);
}
PROMOTED_ENTRY(143, sub_83247F08, 0x83247F08) { ctx.r3.u64 = Construct_TXT_83497B00_G_(ctx, base); }

uint64_t Construct_TXT_83497B04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B04_G_ = int32_t(0x83497B04);
	constexpr int32_t str_TXT_820A9030_B_ = int32_t(0x820A9030);
	constexpr int32_t Destroy_TXT_83497B04_G__address = int32_t(0x832A1750);
	if (!UseLiftedCode(143, 0x83247F48)) { __imp__sub_83247F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B04_G_, str_TXT_820A9030_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B04_G__address);
}
PROMOTED_ENTRY(143, sub_83247F48, 0x83247F48) { ctx.r3.u64 = Construct_TXT_83497B04_G_(ctx, base); }

uint64_t Construct_TXT_83497B08_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B08_G_ = int32_t(0x83497B08);
	constexpr int32_t str_TXT_820A9038_B_ = int32_t(0x820A9038);
	constexpr int32_t Destroy_TXT_83497B08_G__address = int32_t(0x832A1760);
	if (!UseLiftedCode(143, 0x83247F88)) { __imp__sub_83247F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247F88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B08_G_, str_TXT_820A9038_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B08_G__address);
}
PROMOTED_ENTRY(143, sub_83247F88, 0x83247F88) { ctx.r3.u64 = Construct_TXT_83497B08_G_(ctx, base); }

uint64_t Construct_TXT_83497B0C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B0C_G_ = int32_t(0x83497B0C);
	constexpr int32_t str_TXT_820A9044_B_ = int32_t(0x820A9044);
	constexpr int32_t Destroy_TXT_83497B0C_G__address = int32_t(0x832A1770);
	if (!UseLiftedCode(143, 0x83247FC8)) { __imp__sub_83247FC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83247FC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B0C_G_, str_TXT_820A9044_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B0C_G__address);
}
PROMOTED_ENTRY(143, sub_83247FC8, 0x83247FC8) { ctx.r3.u64 = Construct_TXT_83497B0C_G_(ctx, base); }

uint64_t Construct_TXT_83497B10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B10_G_ = int32_t(0x83497B10);
	constexpr int32_t str_TXT_820A5998_B_ = int32_t(0x820A5998);
	constexpr int32_t Destroy_TXT_83497B10_G__address = int32_t(0x832A1780);
	if (!UseLiftedCode(143, 0x83248008)) { __imp__sub_83248008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248008);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B10_G_, str_TXT_820A5998_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B10_G__address);
}
PROMOTED_ENTRY(143, sub_83248008, 0x83248008) { ctx.r3.u64 = Construct_TXT_83497B10_G_(ctx, base); }

uint64_t Construct_TXT_83497B68_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B68_G_ = int32_t(0x83497B68);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497B68_G__address = int32_t(0x832A1790);
	if (!UseLiftedCode(143, 0x832484E0)) { __imp__sub_832484E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832484E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B68_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B68_G__address);
}
PROMOTED_ENTRY(143, sub_832484E0, 0x832484E0) { ctx.r3.u64 = Construct_TXT_83497B68_G_(ctx, base); }

uint64_t Construct_TXT_83497B6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B6C_G_ = int32_t(0x83497B6C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497B6C_G__address = int32_t(0x832A17A0);
	if (!UseLiftedCode(143, 0x83248520)) { __imp__sub_83248520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248520);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B6C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B6C_G__address);
}
PROMOTED_ENTRY(143, sub_83248520, 0x83248520) { ctx.r3.u64 = Construct_TXT_83497B6C_G_(ctx, base); }

uint64_t Construct_TXT_83497B70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B70_G_ = int32_t(0x83497B70);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497B70_G__address = int32_t(0x832A17B0);
	if (!UseLiftedCode(143, 0x83248560)) { __imp__sub_83248560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248560);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B70_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B70_G__address);
}
PROMOTED_ENTRY(143, sub_83248560, 0x83248560) { ctx.r3.u64 = Construct_TXT_83497B70_G_(ctx, base); }

uint64_t Construct_TXT_83497B74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B74_G_ = int32_t(0x83497B74);
	constexpr int32_t str_TXT_820AF204_B_ = int32_t(0x820AF204);
	constexpr int32_t Destroy_TXT_83497B74_G__address = int32_t(0x832A17C0);
	if (!UseLiftedCode(143, 0x832485A0)) { __imp__sub_832485A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832485A0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B74_G_, str_TXT_820AF204_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B74_G__address);
}
PROMOTED_ENTRY(143, sub_832485A0, 0x832485A0) { ctx.r3.u64 = Construct_TXT_83497B74_G_(ctx, base); }

uint64_t Construct_TXT_83497B78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B78_G_ = int32_t(0x83497B78);
	constexpr int32_t str_TXT_820AF224_B_ = int32_t(0x820AF224);
	constexpr int32_t Destroy_TXT_83497B78_G__address = int32_t(0x832A17D0);
	if (!UseLiftedCode(143, 0x832485E0)) { __imp__sub_832485E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832485E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B78_G_, str_TXT_820AF224_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B78_G__address);
}
PROMOTED_ENTRY(143, sub_832485E0, 0x832485E0) { ctx.r3.u64 = Construct_TXT_83497B78_G_(ctx, base); }

uint64_t Construct_TXT_83497B7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497B7C_G_ = int32_t(0x83497B7C);
	constexpr int32_t str_TXT_820AF234_B_ = int32_t(0x820AF234);
	constexpr int32_t Destroy_TXT_83497B7C_G__address = int32_t(0x832A17E0);
	if (!UseLiftedCode(143, 0x83248620)) { __imp__sub_83248620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248620);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497B7C_G_, str_TXT_820AF234_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497B7C_G__address);
}
PROMOTED_ENTRY(143, sub_83248620, 0x83248620) { ctx.r3.u64 = Construct_TXT_83497B7C_G_(ctx, base); }

uint64_t Construct_TXT_83497BD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BD4_G_ = int32_t(0x83497BD4);
	constexpr int32_t str_TXT_820AF448_B_ = int32_t(0x820AF448);
	constexpr int32_t Destroy_TXT_83497BD4_G__address = int32_t(0x832A17F0);
	if (!UseLiftedCode(143, 0x83248AF8)) { __imp__sub_83248AF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248AF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BD4_G_, str_TXT_820AF448_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BD4_G__address);
}
PROMOTED_ENTRY(143, sub_83248AF8, 0x83248AF8) { ctx.r3.u64 = Construct_TXT_83497BD4_G_(ctx, base); }

uint64_t Construct_TXT_83497BD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BD8_G_ = int32_t(0x83497BD8);
	constexpr int32_t str_TXT_820AF460_B_ = int32_t(0x820AF460);
	constexpr int32_t Destroy_TXT_83497BD8_G__address = int32_t(0x832A1800);
	if (!UseLiftedCode(143, 0x83248B38)) { __imp__sub_83248B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248B38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BD8_G_, str_TXT_820AF460_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BD8_G__address);
}
PROMOTED_ENTRY(143, sub_83248B38, 0x83248B38) { ctx.r3.u64 = Construct_TXT_83497BD8_G_(ctx, base); }

uint64_t Construct_TXT_83497BDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BDC_G_ = int32_t(0x83497BDC);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497BDC_G__address = int32_t(0x832A1810);
	if (!UseLiftedCode(143, 0x83248B78)) { __imp__sub_83248B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248B78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BDC_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BDC_G__address);
}
PROMOTED_ENTRY(143, sub_83248B78, 0x83248B78) { ctx.r3.u64 = Construct_TXT_83497BDC_G_(ctx, base); }

uint64_t Construct_TXT_83497BE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BE0_G_ = int32_t(0x83497BE0);
	constexpr int32_t str_TXT_820AF53C_B_ = int32_t(0x820AF53C);
	constexpr int32_t Destroy_TXT_83497BE0_G__address = int32_t(0x832A1820);
	if (!UseLiftedCode(143, 0x83248BB8)) { __imp__sub_83248BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248BB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE0_G_, str_TXT_820AF53C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BE0_G__address);
}
PROMOTED_ENTRY(143, sub_83248BB8, 0x83248BB8) { ctx.r3.u64 = Construct_TXT_83497BE0_G_(ctx, base); }

uint64_t Construct_TXT_83497BE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BE4_G_ = int32_t(0x83497BE4);
	constexpr int32_t str_TXT_820AF548_B_ = int32_t(0x820AF548);
	constexpr int32_t Destroy_TXT_83497BE4_G__address = int32_t(0x832A1830);
	if (!UseLiftedCode(143, 0x83248BF8)) { __imp__sub_83248BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248BF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE4_G_, str_TXT_820AF548_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BE4_G__address);
}
PROMOTED_ENTRY(143, sub_83248BF8, 0x83248BF8) { ctx.r3.u64 = Construct_TXT_83497BE4_G_(ctx, base); }

uint64_t Construct_TXT_83497BE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BE8_G_ = int32_t(0x83497BE8);
	constexpr int32_t str_TXT_820AF564_B_ = int32_t(0x820AF564);
	constexpr int32_t Destroy_TXT_83497BE8_G__address = int32_t(0x832A1840);
	if (!UseLiftedCode(143, 0x83248C38)) { __imp__sub_83248C38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248C38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BE8_G_, str_TXT_820AF564_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BE8_G__address);
}
PROMOTED_ENTRY(143, sub_83248C38, 0x83248C38) { ctx.r3.u64 = Construct_TXT_83497BE8_G_(ctx, base); }

uint64_t Construct_TXT_83497BEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BEC_G_ = int32_t(0x83497BEC);
	constexpr int32_t str_TXT_820AF588_B_ = int32_t(0x820AF588);
	constexpr int32_t Destroy_TXT_83497BEC_G__address = int32_t(0x832A1850);
	if (!UseLiftedCode(143, 0x83248C78)) { __imp__sub_83248C78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248C78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BEC_G_, str_TXT_820AF588_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BEC_G__address);
}
PROMOTED_ENTRY(143, sub_83248C78, 0x83248C78) { ctx.r3.u64 = Construct_TXT_83497BEC_G_(ctx, base); }

uint64_t Construct_TXT_83497BF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BF0_G_ = int32_t(0x83497BF0);
	constexpr int32_t str_TXT_820AF5A0_B_ = int32_t(0x820AF5A0);
	constexpr int32_t Destroy_TXT_83497BF0_G__address = int32_t(0x832A1860);
	if (!UseLiftedCode(143, 0x83248CB8)) { __imp__sub_83248CB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248CB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BF0_G_, str_TXT_820AF5A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BF0_G__address);
}
PROMOTED_ENTRY(143, sub_83248CB8, 0x83248CB8) { ctx.r3.u64 = Construct_TXT_83497BF0_G_(ctx, base); }

uint64_t Construct_TXT_83497BF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BF4_G_ = int32_t(0x83497BF4);
	constexpr int32_t str_TXT_820AF5B0_B_ = int32_t(0x820AF5B0);
	constexpr int32_t Destroy_TXT_83497BF4_G__address = int32_t(0x832A1870);
	if (!UseLiftedCode(143, 0x83248CF8)) { __imp__sub_83248CF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248CF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BF4_G_, str_TXT_820AF5B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BF4_G__address);
}
PROMOTED_ENTRY(143, sub_83248CF8, 0x83248CF8) { ctx.r3.u64 = Construct_TXT_83497BF4_G_(ctx, base); }

uint64_t Construct_TXT_83497BFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497BFC_G_ = int32_t(0x83497BFC);
	constexpr int32_t str_TXT_820AF5DC_B_ = int32_t(0x820AF5DC);
	constexpr int32_t Destroy_TXT_83497BFC_G__address = int32_t(0x832A1890);
	if (!UseLiftedCode(143, 0x83248D78)) { __imp__sub_83248D78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248D78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497BFC_G_, str_TXT_820AF5DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497BFC_G__address);
}
PROMOTED_ENTRY(143, sub_83248D78, 0x83248D78) { ctx.r3.u64 = Construct_TXT_83497BFC_G_(ctx, base); }

uint64_t Construct_TXT_83497C00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C00_G_ = int32_t(0x83497C00);
	constexpr int32_t str_TXT_820AF604_B_ = int32_t(0x820AF604);
	constexpr int32_t Destroy_TXT_83497C00_G__address = int32_t(0x832A18A0);
	if (!UseLiftedCode(143, 0x83248DB8)) { __imp__sub_83248DB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248DB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C00_G_, str_TXT_820AF604_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C00_G__address);
}
PROMOTED_ENTRY(143, sub_83248DB8, 0x83248DB8) { ctx.r3.u64 = Construct_TXT_83497C00_G_(ctx, base); }

uint64_t Construct_TXT_83497C04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C04_G_ = int32_t(0x83497C04);
	constexpr int32_t str_TXT_820AF62C_B_ = int32_t(0x820AF62C);
	constexpr int32_t Destroy_TXT_83497C04_G__address = int32_t(0x832A18B0);
	if (!UseLiftedCode(143, 0x83248DF8)) { __imp__sub_83248DF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248DF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C04_G_, str_TXT_820AF62C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C04_G__address);
}
PROMOTED_ENTRY(143, sub_83248DF8, 0x83248DF8) { ctx.r3.u64 = Construct_TXT_83497C04_G_(ctx, base); }

uint64_t Construct_TXT_83497C08_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C08_G_ = int32_t(0x83497C08);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497C08_G__address = int32_t(0x832A18C0);
	if (!UseLiftedCode(143, 0x83248E38)) { __imp__sub_83248E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248E38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C08_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C08_G__address);
}
PROMOTED_ENTRY(143, sub_83248E38, 0x83248E38) { ctx.r3.u64 = Construct_TXT_83497C08_G_(ctx, base); }

uint64_t Construct_TXT_83497C0C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C0C_G_ = int32_t(0x83497C0C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497C0C_G__address = int32_t(0x832A18D0);
	if (!UseLiftedCode(143, 0x83248E78)) { __imp__sub_83248E78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248E78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C0C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C0C_G__address);
}
PROMOTED_ENTRY(143, sub_83248E78, 0x83248E78) { ctx.r3.u64 = Construct_TXT_83497C0C_G_(ctx, base); }

uint64_t Construct_TXT_83497C10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C10_G_ = int32_t(0x83497C10);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497C10_G__address = int32_t(0x832A18E0);
	if (!UseLiftedCode(143, 0x83248EB8)) { __imp__sub_83248EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248EB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C10_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C10_G__address);
}
PROMOTED_ENTRY(143, sub_83248EB8, 0x83248EB8) { ctx.r3.u64 = Construct_TXT_83497C10_G_(ctx, base); }

uint64_t Construct_TXT_83497C14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C14_G_ = int32_t(0x83497C14);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497C14_G__address = int32_t(0x832A18F0);
	if (!UseLiftedCode(143, 0x83248EF8)) { __imp__sub_83248EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83248EF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C14_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C14_G__address);
}
PROMOTED_ENTRY(143, sub_83248EF8, 0x83248EF8) { ctx.r3.u64 = Construct_TXT_83497C14_G_(ctx, base); }

uint64_t Construct_TXT_83497C6C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C6C_G_ = int32_t(0x83497C6C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497C6C_G__address = int32_t(0x832A1900);
	if (!UseLiftedCode(143, 0x832493D0)) { __imp__sub_832493D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832493D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C6C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C6C_G__address);
}
PROMOTED_ENTRY(143, sub_832493D0, 0x832493D0) { ctx.r3.u64 = Construct_TXT_83497C6C_G_(ctx, base); }

uint64_t Construct_TXT_83497C70_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C70_G_ = int32_t(0x83497C70);
	constexpr int32_t str_TXT_820AF788_B_ = int32_t(0x820AF788);
	constexpr int32_t Destroy_TXT_83497C70_G__address = int32_t(0x832A1910);
	if (!UseLiftedCode(143, 0x83249410)) { __imp__sub_83249410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C70_G_, str_TXT_820AF788_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C70_G__address);
}
PROMOTED_ENTRY(143, sub_83249410, 0x83249410) { ctx.r3.u64 = Construct_TXT_83497C70_G_(ctx, base); }

uint64_t Construct_TXT_83497C74_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C74_G_ = int32_t(0x83497C74);
	constexpr int32_t str_TXT_820A62C4_B_ = int32_t(0x820A62C4);
	constexpr int32_t Destroy_TXT_83497C74_G__address = int32_t(0x832A1920);
	if (!UseLiftedCode(143, 0x83249450)) { __imp__sub_83249450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C74_G_, str_TXT_820A62C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C74_G__address);
}
PROMOTED_ENTRY(143, sub_83249450, 0x83249450) { ctx.r3.u64 = Construct_TXT_83497C74_G_(ctx, base); }

uint64_t Construct_TXT_83497C78_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C78_G_ = int32_t(0x83497C78);
	constexpr int32_t str_TXT_820AF7A0_B_ = int32_t(0x820AF7A0);
	constexpr int32_t Destroy_TXT_83497C78_G__address = int32_t(0x832A1930);
	if (!UseLiftedCode(143, 0x83249490)) { __imp__sub_83249490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C78_G_, str_TXT_820AF7A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C78_G__address);
}
PROMOTED_ENTRY(143, sub_83249490, 0x83249490) { ctx.r3.u64 = Construct_TXT_83497C78_G_(ctx, base); }

uint64_t Construct_TXT_83497C7C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C7C_G_ = int32_t(0x83497C7C);
	constexpr int32_t str_TXT_820AF7C8_B_ = int32_t(0x820AF7C8);
	constexpr int32_t Destroy_TXT_83497C7C_G__address = int32_t(0x832A1940);
	if (!UseLiftedCode(143, 0x832494D0)) { __imp__sub_832494D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832494D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C7C_G_, str_TXT_820AF7C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C7C_G__address);
}
PROMOTED_ENTRY(143, sub_832494D0, 0x832494D0) { ctx.r3.u64 = Construct_TXT_83497C7C_G_(ctx, base); }

uint64_t Construct_TXT_83497C80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C80_G_ = int32_t(0x83497C80);
	constexpr int32_t str_TXT_820AF7DC_B_ = int32_t(0x820AF7DC);
	constexpr int32_t Destroy_TXT_83497C80_G__address = int32_t(0x832A1950);
	if (!UseLiftedCode(143, 0x83249510)) { __imp__sub_83249510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249510);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C80_G_, str_TXT_820AF7DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C80_G__address);
}
PROMOTED_ENTRY(143, sub_83249510, 0x83249510) { ctx.r3.u64 = Construct_TXT_83497C80_G_(ctx, base); }

uint64_t Construct_TXT_83497C84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C84_G_ = int32_t(0x83497C84);
	constexpr int32_t str_TXT_820AF7FC_B_ = int32_t(0x820AF7FC);
	constexpr int32_t Destroy_TXT_83497C84_G__address = int32_t(0x832A1960);
	if (!UseLiftedCode(143, 0x83249550)) { __imp__sub_83249550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249550);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C84_G_, str_TXT_820AF7FC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C84_G__address);
}
PROMOTED_ENTRY(143, sub_83249550, 0x83249550) { ctx.r3.u64 = Construct_TXT_83497C84_G_(ctx, base); }

uint64_t Construct_TXT_83497C88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C88_G_ = int32_t(0x83497C88);
	constexpr int32_t str_TXT_820AF820_B_ = int32_t(0x820AF820);
	constexpr int32_t Destroy_TXT_83497C88_G__address = int32_t(0x832A1970);
	if (!UseLiftedCode(143, 0x83249590)) { __imp__sub_83249590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249590);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C88_G_, str_TXT_820AF820_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C88_G__address);
}
PROMOTED_ENTRY(143, sub_83249590, 0x83249590) { ctx.r3.u64 = Construct_TXT_83497C88_G_(ctx, base); }

uint64_t Construct_TXT_83497C8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C8C_G_ = int32_t(0x83497C8C);
	constexpr int32_t str_TXT_820AF85C_B_ = int32_t(0x820AF85C);
	constexpr int32_t Destroy_TXT_83497C8C_G__address = int32_t(0x832A1980);
	if (!UseLiftedCode(143, 0x832495D0)) { __imp__sub_832495D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832495D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C8C_G_, str_TXT_820AF85C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C8C_G__address);
}
PROMOTED_ENTRY(143, sub_832495D0, 0x832495D0) { ctx.r3.u64 = Construct_TXT_83497C8C_G_(ctx, base); }

uint64_t Construct_TXT_83497C90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C90_G_ = int32_t(0x83497C90);
	constexpr int32_t str_TXT_820AF898_B_ = int32_t(0x820AF898);
	constexpr int32_t Destroy_TXT_83497C90_G__address = int32_t(0x832A1990);
	if (!UseLiftedCode(143, 0x83249610)) { __imp__sub_83249610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249610);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C90_G_, str_TXT_820AF898_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C90_G__address);
}
PROMOTED_ENTRY(143, sub_83249610, 0x83249610) { ctx.r3.u64 = Construct_TXT_83497C90_G_(ctx, base); }

uint64_t Construct_TXT_83497C94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C94_G_ = int32_t(0x83497C94);
	constexpr int32_t str_TXT_820AF8D4_B_ = int32_t(0x820AF8D4);
	constexpr int32_t Destroy_TXT_83497C94_G__address = int32_t(0x832A19A0);
	if (!UseLiftedCode(143, 0x83249650)) { __imp__sub_83249650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249650);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C94_G_, str_TXT_820AF8D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C94_G__address);
}
PROMOTED_ENTRY(143, sub_83249650, 0x83249650) { ctx.r3.u64 = Construct_TXT_83497C94_G_(ctx, base); }

uint64_t Construct_TXT_83497C98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C98_G_ = int32_t(0x83497C98);
	constexpr int32_t str_TXT_820AF90C_B_ = int32_t(0x820AF90C);
	constexpr int32_t Destroy_TXT_83497C98_G__address = int32_t(0x832A19B0);
	if (!UseLiftedCode(143, 0x83249690)) { __imp__sub_83249690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249690);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C98_G_, str_TXT_820AF90C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C98_G__address);
}
PROMOTED_ENTRY(143, sub_83249690, 0x83249690) { ctx.r3.u64 = Construct_TXT_83497C98_G_(ctx, base); }

uint64_t Construct_TXT_83497C9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497C9C_G_ = int32_t(0x83497C9C);
	constexpr int32_t str_TXT_820AF934_B_ = int32_t(0x820AF934);
	constexpr int32_t Destroy_TXT_83497C9C_G__address = int32_t(0x832A19C0);
	if (!UseLiftedCode(143, 0x832496D0)) { __imp__sub_832496D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832496D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497C9C_G_, str_TXT_820AF934_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497C9C_G__address);
}
PROMOTED_ENTRY(143, sub_832496D0, 0x832496D0) { ctx.r3.u64 = Construct_TXT_83497C9C_G_(ctx, base); }

uint64_t Construct_TXT_83497CA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CA0_G_ = int32_t(0x83497CA0);
	constexpr int32_t str_TXT_820AF970_B_ = int32_t(0x820AF970);
	constexpr int32_t Destroy_TXT_83497CA0_G__address = int32_t(0x832A19D0);
	if (!UseLiftedCode(143, 0x83249710)) { __imp__sub_83249710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249710);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA0_G_, str_TXT_820AF970_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CA0_G__address);
}
PROMOTED_ENTRY(143, sub_83249710, 0x83249710) { ctx.r3.u64 = Construct_TXT_83497CA0_G_(ctx, base); }

uint64_t Construct_TXT_83497CA4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CA4_G_ = int32_t(0x83497CA4);
	constexpr int32_t str_TXT_820AF9A0_B_ = int32_t(0x820AF9A0);
	constexpr int32_t Destroy_TXT_83497CA4_G__address = int32_t(0x832A19E0);
	if (!UseLiftedCode(143, 0x83249750)) { __imp__sub_83249750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249750);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA4_G_, str_TXT_820AF9A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CA4_G__address);
}
PROMOTED_ENTRY(143, sub_83249750, 0x83249750) { ctx.r3.u64 = Construct_TXT_83497CA4_G_(ctx, base); }

uint64_t Construct_TXT_83497CA8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CA8_G_ = int32_t(0x83497CA8);
	constexpr int32_t str_TXT_820AF9CC_B_ = int32_t(0x820AF9CC);
	constexpr int32_t Destroy_TXT_83497CA8_G__address = int32_t(0x832A19F0);
	if (!UseLiftedCode(143, 0x83249790)) { __imp__sub_83249790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CA8_G_, str_TXT_820AF9CC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CA8_G__address);
}
PROMOTED_ENTRY(143, sub_83249790, 0x83249790) { ctx.r3.u64 = Construct_TXT_83497CA8_G_(ctx, base); }

uint64_t Construct_TXT_83497CAC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CAC_G_ = int32_t(0x83497CAC);
	constexpr int32_t str_TXT_820AF9F4_B_ = int32_t(0x820AF9F4);
	constexpr int32_t Destroy_TXT_83497CAC_G__address = int32_t(0x832A1A00);
	if (!UseLiftedCode(143, 0x832497D0)) { __imp__sub_832497D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832497D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CAC_G_, str_TXT_820AF9F4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CAC_G__address);
}
PROMOTED_ENTRY(143, sub_832497D0, 0x832497D0) { ctx.r3.u64 = Construct_TXT_83497CAC_G_(ctx, base); }

uint64_t Construct_TXT_83497CB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CB0_G_ = int32_t(0x83497CB0);
	constexpr int32_t str_TXT_820AFA18_B_ = int32_t(0x820AFA18);
	constexpr int32_t Destroy_TXT_83497CB0_G__address = int32_t(0x832A1A10);
	if (!UseLiftedCode(143, 0x83249810)) { __imp__sub_83249810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249810);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB0_G_, str_TXT_820AFA18_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CB0_G__address);
}
PROMOTED_ENTRY(143, sub_83249810, 0x83249810) { ctx.r3.u64 = Construct_TXT_83497CB0_G_(ctx, base); }

uint64_t Construct_TXT_83497CB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CB4_G_ = int32_t(0x83497CB4);
	constexpr int32_t str_TXT_820AFA38_B_ = int32_t(0x820AFA38);
	constexpr int32_t Destroy_TXT_83497CB4_G__address = int32_t(0x832A1A20);
	if (!UseLiftedCode(143, 0x83249850)) { __imp__sub_83249850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249850);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB4_G_, str_TXT_820AFA38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CB4_G__address);
}
PROMOTED_ENTRY(143, sub_83249850, 0x83249850) { ctx.r3.u64 = Construct_TXT_83497CB4_G_(ctx, base); }

uint64_t Construct_TXT_83497CB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CB8_G_ = int32_t(0x83497CB8);
	constexpr int32_t str_TXT_820AFA5C_B_ = int32_t(0x820AFA5C);
	constexpr int32_t Destroy_TXT_83497CB8_G__address = int32_t(0x832A1A30);
	if (!UseLiftedCode(143, 0x83249890)) { __imp__sub_83249890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249890);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CB8_G_, str_TXT_820AFA5C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CB8_G__address);
}
PROMOTED_ENTRY(143, sub_83249890, 0x83249890) { ctx.r3.u64 = Construct_TXT_83497CB8_G_(ctx, base); }

uint64_t Construct_TXT_83497CBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CBC_G_ = int32_t(0x83497CBC);
	constexpr int32_t str_TXT_820AFA84_B_ = int32_t(0x820AFA84);
	constexpr int32_t Destroy_TXT_83497CBC_G__address = int32_t(0x832A1A40);
	if (!UseLiftedCode(143, 0x832498D0)) { __imp__sub_832498D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832498D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CBC_G_, str_TXT_820AFA84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CBC_G__address);
}
PROMOTED_ENTRY(143, sub_832498D0, 0x832498D0) { ctx.r3.u64 = Construct_TXT_83497CBC_G_(ctx, base); }

uint64_t Construct_TXT_83497CC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CC0_G_ = int32_t(0x83497CC0);
	constexpr int32_t str_TXT_820AFAB4_B_ = int32_t(0x820AFAB4);
	constexpr int32_t Destroy_TXT_83497CC0_G__address = int32_t(0x832A1A50);
	if (!UseLiftedCode(143, 0x83249910)) { __imp__sub_83249910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC0_G_, str_TXT_820AFAB4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CC0_G__address);
}
PROMOTED_ENTRY(143, sub_83249910, 0x83249910) { ctx.r3.u64 = Construct_TXT_83497CC0_G_(ctx, base); }

uint64_t Construct_TXT_83497CC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CC4_G_ = int32_t(0x83497CC4);
	constexpr int32_t str_TXT_820AFA84_B_ = int32_t(0x820AFAD8);
	constexpr int32_t Destroy_TXT_83497CC4_G__address = int32_t(0x832A1A60);
	if (!UseLiftedCode(143, 0x83249950)) { __imp__sub_83249950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC4_G_, str_TXT_820AFA84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CC4_G__address);
}
PROMOTED_ENTRY(143, sub_83249950, 0x83249950) { ctx.r3.u64 = Construct_TXT_83497CC4_G_(ctx, base); }

uint64_t Construct_TXT_83497CC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CC8_G_ = int32_t(0x83497CC8);
	constexpr int32_t str_TXT_820AFA84_B_ = int32_t(0x820AFB10);
	constexpr int32_t Destroy_TXT_83497CC8_G__address = int32_t(0x832A1A70);
	if (!UseLiftedCode(143, 0x83249990)) { __imp__sub_83249990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83249990);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CC8_G_, str_TXT_820AFA84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CC8_G__address);
}
PROMOTED_ENTRY(143, sub_83249990, 0x83249990) { ctx.r3.u64 = Construct_TXT_83497CC8_G_(ctx, base); }

uint64_t Construct_TXT_83497CF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CF8_G_ = int32_t(0x83497CF8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497CF8_G__address = int32_t(0x832A1AD8);
	if (!UseLiftedCode(143, 0x8324A210)) { __imp__sub_8324A210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A210);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CF8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CF8_G__address);
}
PROMOTED_ENTRY(143, sub_8324A210, 0x8324A210) { ctx.r3.u64 = Construct_TXT_83497CF8_G_(ctx, base); }

uint64_t Construct_TXT_83497CFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497CFC_G_ = int32_t(0x83497CFC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497CFC_G__address = int32_t(0x832A1AE8);
	if (!UseLiftedCode(143, 0x8324A250)) { __imp__sub_8324A250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A250);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497CFC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497CFC_G__address);
}
PROMOTED_ENTRY(143, sub_8324A250, 0x8324A250) { ctx.r3.u64 = Construct_TXT_83497CFC_G_(ctx, base); }

uint64_t Construct_TXT_83497D00_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D00_G_ = int32_t(0x83497D00);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497D00_G__address = int32_t(0x832A1AF8);
	if (!UseLiftedCode(143, 0x8324A290)) { __imp__sub_8324A290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A290);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D00_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D00_G__address);
}
PROMOTED_ENTRY(143, sub_8324A290, 0x8324A290) { ctx.r3.u64 = Construct_TXT_83497D00_G_(ctx, base); }

uint64_t Construct_TXT_83497D04_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D04_G_ = int32_t(0x83497D04);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497D04_G__address = int32_t(0x832A1B08);
	if (!UseLiftedCode(143, 0x8324A2D0)) { __imp__sub_8324A2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A2D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D04_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D04_G__address);
}
PROMOTED_ENTRY(143, sub_8324A2D0, 0x8324A2D0) { ctx.r3.u64 = Construct_TXT_83497D04_G_(ctx, base); }

// sub_8324A348  [64 bytes]
uint64_t n_sub_8324A348(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D0C_G_ = int32_t(0x83497D0C);
	constexpr int32_t str_TXT_820B0948_B_ = int32_t(0x820B0948);
	constexpr int32_t Destroy_TXT_83497D0C_G__address = int32_t(0x832A1B18);
	if (!UseLiftedCode(143, 0x8324A348)) { __imp__sub_8324A348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A348);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D0C_G_, str_TXT_820B0948_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83497D0C_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324A348, 0x8324A348) { ctx.r3.u64 = n_sub_8324A348(ctx, base); }

uint64_t Construct_TXT_83497D10_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D10_G_ = int32_t(0x83497D10);
	constexpr int32_t str_TXT_820B0950_B_ = int32_t(0x820B0950);
	constexpr int32_t Destroy_TXT_83497D10_G__address = int32_t(0x832A1B28);
	if (!UseLiftedCode(143, 0x8324A388)) { __imp__sub_8324A388(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A388);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D10_G_, str_TXT_820B0950_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D10_G__address);
}
PROMOTED_ENTRY(143, sub_8324A388, 0x8324A388) { ctx.r3.u64 = Construct_TXT_83497D10_G_(ctx, base); }

uint64_t Construct_TXT_83497D14_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D14_G_ = int32_t(0x83497D14);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497D14_G__address = int32_t(0x832A1B38);
	if (!UseLiftedCode(143, 0x8324A3C8)) { __imp__sub_8324A3C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A3C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D14_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D14_G__address);
}
PROMOTED_ENTRY(143, sub_8324A3C8, 0x8324A3C8) { ctx.r3.u64 = Construct_TXT_83497D14_G_(ctx, base); }

uint64_t Construct_TXT_83497D18_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D18_G_ = int32_t(0x83497D18);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497D18_G__address = int32_t(0x832A1B48);
	if (!UseLiftedCode(143, 0x8324A408)) { __imp__sub_8324A408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A408);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D18_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D18_G__address);
}
PROMOTED_ENTRY(143, sub_8324A408, 0x8324A408) { ctx.r3.u64 = Construct_TXT_83497D18_G_(ctx, base); }

uint64_t Construct_TXT_83497D1C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D1C_G_ = int32_t(0x83497D1C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497D1C_G__address = int32_t(0x832A1B58);
	if (!UseLiftedCode(143, 0x8324A448)) { __imp__sub_8324A448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A448);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D1C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D1C_G__address);
}
PROMOTED_ENTRY(143, sub_8324A448, 0x8324A448) { ctx.r3.u64 = Construct_TXT_83497D1C_G_(ctx, base); }

uint64_t Construct_TXT_83497D20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D20_G_ = int32_t(0x83497D20);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497D20_G__address = int32_t(0x832A1B68);
	if (!UseLiftedCode(143, 0x8324A488)) { __imp__sub_8324A488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A488);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D20_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D20_G__address);
}
PROMOTED_ENTRY(143, sub_8324A488, 0x8324A488) { ctx.r3.u64 = Construct_TXT_83497D20_G_(ctx, base); }

uint64_t Construct_TXT_83497D24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D24_G_ = int32_t(0x83497D24);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497D24_G__address = int32_t(0x832A1B78);
	if (!UseLiftedCode(143, 0x8324A4C8)) { __imp__sub_8324A4C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A4C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D24_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D24_G__address);
}
PROMOTED_ENTRY(143, sub_8324A4C8, 0x8324A4C8) { ctx.r3.u64 = Construct_TXT_83497D24_G_(ctx, base); }

uint64_t Construct_TXT_83497D28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D28_G_ = int32_t(0x83497D28);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497D28_G__address = int32_t(0x832A1B88);
	if (!UseLiftedCode(143, 0x8324A508)) { __imp__sub_8324A508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A508);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D28_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D28_G__address);
}
PROMOTED_ENTRY(143, sub_8324A508, 0x8324A508) { ctx.r3.u64 = Construct_TXT_83497D28_G_(ctx, base); }

uint64_t Construct_TXT_83497D48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D48_G_ = int32_t(0x83497D48);
	constexpr int32_t str_TXT_820B0ACC_B_ = int32_t(0x820B0ACC);
	constexpr int32_t Destroy_TXT_83497D48_G__address = int32_t(0x832A1B98);
	if (!UseLiftedCode(143, 0x8324A6D0)) { __imp__sub_8324A6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A6D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D48_G_, str_TXT_820B0ACC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D48_G__address);
}
PROMOTED_ENTRY(143, sub_8324A6D0, 0x8324A6D0) { ctx.r3.u64 = Construct_TXT_83497D48_G_(ctx, base); }

uint64_t Construct_TXT_83497D4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D4C_G_ = int32_t(0x83497D4C);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497D4C_G__address = int32_t(0x832A1BA8);
	if (!UseLiftedCode(143, 0x8324A710)) { __imp__sub_8324A710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A710);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D4C_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D4C_G__address);
}
PROMOTED_ENTRY(143, sub_8324A710, 0x8324A710) { ctx.r3.u64 = Construct_TXT_83497D4C_G_(ctx, base); }

uint64_t Construct_TXT_83497D80_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D80_G_ = int32_t(0x83497D80);
	constexpr int32_t str_TXT_820B0B0C_B_ = int32_t(0x820B0B0C);
	constexpr int32_t Destroy_TXT_83497D80_G__address = int32_t(0x832A1BB8);
	if (!UseLiftedCode(143, 0x8324A870)) { __imp__sub_8324A870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A870);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D80_G_, str_TXT_820B0B0C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D80_G__address);
}
PROMOTED_ENTRY(143, sub_8324A870, 0x8324A870) { ctx.r3.u64 = Construct_TXT_83497D80_G_(ctx, base); }

uint64_t Construct_TXT_83497D84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D84_G_ = int32_t(0x83497D84);
	constexpr int32_t str_TXT_820B0B20_B_ = int32_t(0x820B0B20);
	constexpr int32_t Destroy_TXT_83497D84_G__address = int32_t(0x832A1BC8);
	if (!UseLiftedCode(143, 0x8324A8B0)) { __imp__sub_8324A8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A8B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D84_G_, str_TXT_820B0B20_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D84_G__address);
}
PROMOTED_ENTRY(143, sub_8324A8B0, 0x8324A8B0) { ctx.r3.u64 = Construct_TXT_83497D84_G_(ctx, base); }

uint64_t Construct_TXT_83497D88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D88_G_ = int32_t(0x83497D88);
	constexpr int32_t str_TXT_820B0B2C_B_ = int32_t(0x820B0B2C);
	constexpr int32_t Destroy_TXT_83497D88_G__address = int32_t(0x832A1BD8);
	if (!UseLiftedCode(143, 0x8324A8F0)) { __imp__sub_8324A8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A8F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D88_G_, str_TXT_820B0B2C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D88_G__address);
}
PROMOTED_ENTRY(143, sub_8324A8F0, 0x8324A8F0) { ctx.r3.u64 = Construct_TXT_83497D88_G_(ctx, base); }

uint64_t Construct_TXT_83497D8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D8C_G_ = int32_t(0x83497D8C);
	constexpr int32_t str_TXT_820B0B38_B_ = int32_t(0x820B0B38);
	constexpr int32_t Destroy_TXT_83497D8C_G__address = int32_t(0x832A1BE8);
	if (!UseLiftedCode(143, 0x8324A930)) { __imp__sub_8324A930(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A930);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D8C_G_, str_TXT_820B0B38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D8C_G__address);
}
PROMOTED_ENTRY(143, sub_8324A930, 0x8324A930) { ctx.r3.u64 = Construct_TXT_83497D8C_G_(ctx, base); }

uint64_t Construct_TXT_83497D90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D90_G_ = int32_t(0x83497D90);
	constexpr int32_t str_TXT_820B0B40_B_ = int32_t(0x820B0B40);
	constexpr int32_t Destroy_TXT_83497D90_G__address = int32_t(0x832A1BF8);
	if (!UseLiftedCode(143, 0x8324A970)) { __imp__sub_8324A970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A970);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D90_G_, str_TXT_820B0B40_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D90_G__address);
}
PROMOTED_ENTRY(143, sub_8324A970, 0x8324A970) { ctx.r3.u64 = Construct_TXT_83497D90_G_(ctx, base); }

uint64_t Construct_TXT_83497D94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D94_G_ = int32_t(0x83497D94);
	constexpr int32_t str_TXT_820A94D0_B_ = int32_t(0x820A94D0);
	constexpr int32_t Destroy_TXT_83497D94_G__address = int32_t(0x832A1C08);
	if (!UseLiftedCode(143, 0x8324A9B0)) { __imp__sub_8324A9B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A9B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D94_G_, str_TXT_820A94D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D94_G__address);
}
PROMOTED_ENTRY(143, sub_8324A9B0, 0x8324A9B0) { ctx.r3.u64 = Construct_TXT_83497D94_G_(ctx, base); }

uint64_t Construct_TXT_83497D98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D98_G_ = int32_t(0x83497D98);
	constexpr int32_t str_TXT_820A94D4_B_ = int32_t(0x820A94D4);
	constexpr int32_t Destroy_TXT_83497D98_G__address = int32_t(0x832A1C18);
	if (!UseLiftedCode(143, 0x8324A9F0)) { __imp__sub_8324A9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324A9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D98_G_, str_TXT_820A94D4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D98_G__address);
}
PROMOTED_ENTRY(143, sub_8324A9F0, 0x8324A9F0) { ctx.r3.u64 = Construct_TXT_83497D98_G_(ctx, base); }

uint64_t Construct_TXT_83497D9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497D9C_G_ = int32_t(0x83497D9C);
	constexpr int32_t str_TXT_820A94DC_B_ = int32_t(0x820A94DC);
	constexpr int32_t Destroy_TXT_83497D9C_G__address = int32_t(0x832A1C28);
	if (!UseLiftedCode(143, 0x8324AA30)) { __imp__sub_8324AA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AA30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497D9C_G_, str_TXT_820A94DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497D9C_G__address);
}
PROMOTED_ENTRY(143, sub_8324AA30, 0x8324AA30) { ctx.r3.u64 = Construct_TXT_83497D9C_G_(ctx, base); }

uint64_t Construct_TXT_83497DA0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DA0_G_ = int32_t(0x83497DA0);
	constexpr int32_t str_TXT_820B0B48_B_ = int32_t(0x820B0B48);
	constexpr int32_t Destroy_TXT_83497DA0_G__address = int32_t(0x832A1C38);
	if (!UseLiftedCode(143, 0x8324AA70)) { __imp__sub_8324AA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AA70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DA0_G_, str_TXT_820B0B48_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DA0_G__address);
}
PROMOTED_ENTRY(143, sub_8324AA70, 0x8324AA70) { ctx.r3.u64 = Construct_TXT_83497DA0_G_(ctx, base); }

uint64_t Construct_TXT_83497DB0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DB0_G_ = int32_t(0x83497DB0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497DB0_G__address = int32_t(0x832A1C58);
	if (!UseLiftedCode(143, 0x8324AB40)) { __imp__sub_8324AB40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AB40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DB0_G__address);
}
PROMOTED_ENTRY(143, sub_8324AB40, 0x8324AB40) { ctx.r3.u64 = Construct_TXT_83497DB0_G_(ctx, base); }

uint64_t Construct_TXT_83497DB4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DB4_G_ = int32_t(0x83497DB4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497DB4_G__address = int32_t(0x832A1C68);
	if (!UseLiftedCode(143, 0x8324AB80)) { __imp__sub_8324AB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AB80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DB4_G__address);
}
PROMOTED_ENTRY(143, sub_8324AB80, 0x8324AB80) { ctx.r3.u64 = Construct_TXT_83497DB4_G_(ctx, base); }

uint64_t Construct_TXT_83497DB8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DB8_G_ = int32_t(0x83497DB8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497DB8_G__address = int32_t(0x832A1C78);
	if (!UseLiftedCode(143, 0x8324ABC0)) { __imp__sub_8324ABC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ABC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DB8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DB8_G__address);
}
PROMOTED_ENTRY(143, sub_8324ABC0, 0x8324ABC0) { ctx.r3.u64 = Construct_TXT_83497DB8_G_(ctx, base); }

uint64_t Construct_TXT_83497DBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DBC_G_ = int32_t(0x83497DBC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497DBC_G__address = int32_t(0x832A1C88);
	if (!UseLiftedCode(143, 0x8324AC00)) { __imp__sub_8324AC00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC00);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DBC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DBC_G__address);
}
PROMOTED_ENTRY(143, sub_8324AC00, 0x8324AC00) { ctx.r3.u64 = Construct_TXT_83497DBC_G_(ctx, base); }

uint64_t Construct_TXT_83497DC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DC0_G_ = int32_t(0x83497DC0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497DC0_G__address = int32_t(0x832A1C98);
	if (!UseLiftedCode(143, 0x8324AC40)) { __imp__sub_8324AC40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC40);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DC0_G__address);
}
PROMOTED_ENTRY(143, sub_8324AC40, 0x8324AC40) { ctx.r3.u64 = Construct_TXT_83497DC0_G_(ctx, base); }

uint64_t Construct_TXT_83497DC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DC4_G_ = int32_t(0x83497DC4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497DC4_G__address = int32_t(0x832A1CA8);
	if (!UseLiftedCode(143, 0x8324AC80)) { __imp__sub_8324AC80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AC80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DC4_G__address);
}
PROMOTED_ENTRY(143, sub_8324AC80, 0x8324AC80) { ctx.r3.u64 = Construct_TXT_83497DC4_G_(ctx, base); }

uint64_t Construct_TXT_83497DC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DC8_G_ = int32_t(0x83497DC8);
	constexpr int32_t str_TXT_820B0F28_B_ = int32_t(0x820B0F28);
	constexpr int32_t Destroy_TXT_83497DC8_G__address = int32_t(0x832A1CB8);
	if (!UseLiftedCode(143, 0x8324ACC0)) { __imp__sub_8324ACC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ACC0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DC8_G_, str_TXT_820B0F28_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DC8_G__address);
}
PROMOTED_ENTRY(143, sub_8324ACC0, 0x8324ACC0) { ctx.r3.u64 = Construct_TXT_83497DC8_G_(ctx, base); }

uint64_t n_sub_8324AD38(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1CD8_address = int32_t(0x832A1CD8);
	if (!UseLiftedCode(143, 0x8324AD38)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324AD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD38);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1CD8_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324AD38, 0x8324AD38) { ctx.r3.u64 = n_sub_8324AD38(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83497DD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DD8_G_ = int32_t(0x83497DD8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497DD8_G__address = int32_t(0x832A1D20);
	if (!UseLiftedCode(143, 0x8324AD48)) { __imp__sub_8324AD48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD48);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DD8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DD8_G__address);
}
PROMOTED_ENTRY(143, sub_8324AD48, 0x8324AD48) { ctx.r3.u64 = Construct_TXT_83497DD8_G_(ctx, base); }

uint64_t Construct_TXT_83497DDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DDC_G_ = int32_t(0x83497DDC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497DDC_G__address = int32_t(0x832A1D30);
	if (!UseLiftedCode(143, 0x8324AD88)) { __imp__sub_8324AD88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AD88);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DDC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DDC_G__address);
}
PROMOTED_ENTRY(143, sub_8324AD88, 0x8324AD88) { ctx.r3.u64 = Construct_TXT_83497DDC_G_(ctx, base); }

uint64_t Construct_TXT_83497DE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DE0_G_ = int32_t(0x83497DE0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497DE0_G__address = int32_t(0x832A1D40);
	if (!UseLiftedCode(143, 0x8324ADC8)) { __imp__sub_8324ADC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ADC8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DE0_G__address);
}
PROMOTED_ENTRY(143, sub_8324ADC8, 0x8324ADC8) { ctx.r3.u64 = Construct_TXT_83497DE0_G_(ctx, base); }

uint64_t Construct_TXT_83497DE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	constexpr int32_t str_TXT_820B1134_B_ = int32_t(0x820B1134);
	constexpr int32_t Destroy_TXT_83497DE4_G__address = int32_t(0x832A1D50);
	if (!UseLiftedCode(143, 0x8324AED0)) { __imp__sub_8324AED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AED0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE4_G_, str_TXT_820B1134_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DE4_G__address);
}
PROMOTED_ENTRY(143, sub_8324AED0, 0x8324AED0) { ctx.r3.u64 = Construct_TXT_83497DE4_G_(ctx, base); }

uint64_t Construct_TXT_83497DE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497DE8_G_ = int32_t(0x83497DE8);
	constexpr int32_t str_TXT_820B1140_B_ = int32_t(0x820B1140);
	constexpr int32_t Destroy_TXT_83497DE8_G__address = int32_t(0x832A1D60);
	if (!UseLiftedCode(143, 0x8324AF10)) { __imp__sub_8324AF10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324AF10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497DE8_G_, str_TXT_820B1140_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497DE8_G__address);
}
PROMOTED_ENTRY(143, sub_8324AF10, 0x8324AF10) { ctx.r3.u64 = Construct_TXT_83497DE8_G_(ctx, base); }

uint64_t Construct_TXT_83497E48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E48_G_ = int32_t(0x83497E48);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497E48_G__address = int32_t(0x832A1DA0);
	if (!UseLiftedCode(143, 0x8324B2F8)) { __imp__sub_8324B2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B2F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E48_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E48_G__address);
}
PROMOTED_ENTRY(143, sub_8324B2F8, 0x8324B2F8) { ctx.r3.u64 = Construct_TXT_83497E48_G_(ctx, base); }

uint64_t Construct_TXT_83497E4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E4C_G_ = int32_t(0x83497E4C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497E4C_G__address = int32_t(0x832A1DB0);
	if (!UseLiftedCode(143, 0x8324B338)) { __imp__sub_8324B338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B338);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E4C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E4C_G__address);
}
PROMOTED_ENTRY(143, sub_8324B338, 0x8324B338) { ctx.r3.u64 = Construct_TXT_83497E4C_G_(ctx, base); }

uint64_t Construct_TXT_83497E50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E50_G_ = int32_t(0x83497E50);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497E50_G__address = int32_t(0x832A1DC0);
	if (!UseLiftedCode(143, 0x8324B378)) { __imp__sub_8324B378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B378);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E50_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E50_G__address);
}
PROMOTED_ENTRY(143, sub_8324B378, 0x8324B378) { ctx.r3.u64 = Construct_TXT_83497E50_G_(ctx, base); }

uint64_t Construct_TXT_83497E54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E54_G_ = int32_t(0x83497E54);
	constexpr int32_t str_TXT_820B1F50_B_ = int32_t(0x820B1F50);
	constexpr int32_t Destroy_TXT_83497E54_G__address = int32_t(0x832A1DD0);
	if (!UseLiftedCode(143, 0x8324B3B8)) { __imp__sub_8324B3B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B3B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E54_G_, str_TXT_820B1F50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E54_G__address);
}
PROMOTED_ENTRY(143, sub_8324B3B8, 0x8324B3B8) { ctx.r3.u64 = Construct_TXT_83497E54_G_(ctx, base); }

uint64_t n_sub_8324B510(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1DE0_address = int32_t(0x832A1DE0);
	if (!UseLiftedCode(143, 0x8324B510)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324B510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B510);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1DE0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324B510, 0x8324B510) { ctx.r3.u64 = n_sub_8324B510(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324B520(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1E58_address = int32_t(0x832A1E58);
	if (!UseLiftedCode(143, 0x8324B520)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324B520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B520);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1E58_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324B520, 0x8324B520) { ctx.r3.u64 = n_sub_8324B520(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83497E84_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E84_G_ = int32_t(0x83497E84);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497E84_G__address = int32_t(0x832A1EB0);
	if (!UseLiftedCode(143, 0x8324B530)) { __imp__sub_8324B530(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B530);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E84_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E84_G__address);
}
PROMOTED_ENTRY(143, sub_8324B530, 0x8324B530) { ctx.r3.u64 = Construct_TXT_83497E84_G_(ctx, base); }

uint64_t Construct_TXT_83497E88_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E88_G_ = int32_t(0x83497E88);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497E88_G__address = int32_t(0x832A1EC0);
	if (!UseLiftedCode(143, 0x8324B570)) { __imp__sub_8324B570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E88_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E88_G__address);
}
PROMOTED_ENTRY(143, sub_8324B570, 0x8324B570) { ctx.r3.u64 = Construct_TXT_83497E88_G_(ctx, base); }

uint64_t Construct_TXT_83497E8C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E8C_G_ = int32_t(0x83497E8C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497E8C_G__address = int32_t(0x832A1ED0);
	if (!UseLiftedCode(143, 0x8324B5B0)) { __imp__sub_8324B5B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B5B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E8C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E8C_G__address);
}
PROMOTED_ENTRY(143, sub_8324B5B0, 0x8324B5B0) { ctx.r3.u64 = Construct_TXT_83497E8C_G_(ctx, base); }

uint64_t Construct_TXT_83497E90_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E90_G_ = int32_t(0x83497E90);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497E90_G__address = int32_t(0x832A1EE0);
	if (!UseLiftedCode(143, 0x8324B5F0)) { __imp__sub_8324B5F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B5F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E90_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E90_G__address);
}
PROMOTED_ENTRY(143, sub_8324B5F0, 0x8324B5F0) { ctx.r3.u64 = Construct_TXT_83497E90_G_(ctx, base); }

uint64_t Construct_TXT_83497E94_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E94_G_ = int32_t(0x83497E94);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497E94_G__address = int32_t(0x832A1EF0);
	if (!UseLiftedCode(143, 0x8324B630)) { __imp__sub_8324B630(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B630);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E94_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E94_G__address);
}
PROMOTED_ENTRY(143, sub_8324B630, 0x8324B630) { ctx.r3.u64 = Construct_TXT_83497E94_G_(ctx, base); }

uint64_t Construct_TXT_83497E98_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E98_G_ = int32_t(0x83497E98);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497E98_G__address = int32_t(0x832A1F00);
	if (!UseLiftedCode(143, 0x8324B670)) { __imp__sub_8324B670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B670);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E98_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E98_G__address);
}
PROMOTED_ENTRY(143, sub_8324B670, 0x8324B670) { ctx.r3.u64 = Construct_TXT_83497E98_G_(ctx, base); }

uint64_t Construct_TXT_83497E9C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497E9C_G_ = int32_t(0x83497E9C);
	constexpr int32_t str_TXT_820B2DB0_B_ = int32_t(0x820B2DB0);
	constexpr int32_t Destroy_TXT_83497E9C_G__address = int32_t(0x832A1F10);
	if (!UseLiftedCode(143, 0x8324B6B0)) { __imp__sub_8324B6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B6B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497E9C_G_, str_TXT_820B2DB0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497E9C_G__address);
}
PROMOTED_ENTRY(143, sub_8324B6B0, 0x8324B6B0) { ctx.r3.u64 = Construct_TXT_83497E9C_G_(ctx, base); }

uint64_t Construct_TXT_83497F20_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F20_G_ = int32_t(0x83497F20);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497F20_G__address = int32_t(0x832A1F88);
	if (!UseLiftedCode(143, 0x8324B9A8)) { __imp__sub_8324B9A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B9A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F20_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F20_G__address);
}
PROMOTED_ENTRY(143, sub_8324B9A8, 0x8324B9A8) { ctx.r3.u64 = Construct_TXT_83497F20_G_(ctx, base); }

uint64_t Construct_TXT_83497F24_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F24_G_ = int32_t(0x83497F24);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497F24_G__address = int32_t(0x832A1F98);
	if (!UseLiftedCode(143, 0x8324B9E8)) { __imp__sub_8324B9E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324B9E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F24_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F24_G__address);
}
PROMOTED_ENTRY(143, sub_8324B9E8, 0x8324B9E8) { ctx.r3.u64 = Construct_TXT_83497F24_G_(ctx, base); }

uint64_t Construct_TXT_83497F28_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F28_G_ = int32_t(0x83497F28);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497F28_G__address = int32_t(0x832A1FA8);
	if (!UseLiftedCode(143, 0x8324BA28)) { __imp__sub_8324BA28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F28_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F28_G__address);
}
PROMOTED_ENTRY(143, sub_8324BA28, 0x8324BA28) { ctx.r3.u64 = Construct_TXT_83497F28_G_(ctx, base); }

uint64_t n_sub_8324BA68(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A1FB8_address = int32_t(0x832A1FB8);
	if (!UseLiftedCode(143, 0x8324BA68)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324BA68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA68);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A1FB8_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324BA68, 0x8324BA68) { ctx.r3.u64 = n_sub_8324BA68(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83497F40_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F40_G_ = int32_t(0x83497F40);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497F40_G__address = int32_t(0x832A2010);
	if (!UseLiftedCode(143, 0x8324BA78)) { __imp__sub_8324BA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BA78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F40_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F40_G__address);
}
PROMOTED_ENTRY(143, sub_8324BA78, 0x8324BA78) { ctx.r3.u64 = Construct_TXT_83497F40_G_(ctx, base); }

uint64_t Construct_TXT_83497F44_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F44_G_ = int32_t(0x83497F44);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497F44_G__address = int32_t(0x832A2020);
	if (!UseLiftedCode(143, 0x8324BAB8)) { __imp__sub_8324BAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F44_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F44_G__address);
}
PROMOTED_ENTRY(143, sub_8324BAB8, 0x8324BAB8) { ctx.r3.u64 = Construct_TXT_83497F44_G_(ctx, base); }

uint64_t Construct_TXT_83497F48_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F48_G_ = int32_t(0x83497F48);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497F48_G__address = int32_t(0x832A2030);
	if (!UseLiftedCode(143, 0x8324BAF8)) { __imp__sub_8324BAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F48_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F48_G__address);
}
PROMOTED_ENTRY(143, sub_8324BAF8, 0x8324BAF8) { ctx.r3.u64 = Construct_TXT_83497F48_G_(ctx, base); }

uint64_t Construct_TXT_83497F4C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F4C_G_ = int32_t(0x83497F4C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497F4C_G__address = int32_t(0x832A2040);
	if (!UseLiftedCode(143, 0x8324BB38)) { __imp__sub_8324BB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BB38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F4C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F4C_G__address);
}
PROMOTED_ENTRY(143, sub_8324BB38, 0x8324BB38) { ctx.r3.u64 = Construct_TXT_83497F4C_G_(ctx, base); }

uint64_t Construct_TXT_83497F50_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F50_G_ = int32_t(0x83497F50);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497F50_G__address = int32_t(0x832A2050);
	if (!UseLiftedCode(143, 0x8324BB78)) { __imp__sub_8324BB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BB78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F50_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F50_G__address);
}
PROMOTED_ENTRY(143, sub_8324BB78, 0x8324BB78) { ctx.r3.u64 = Construct_TXT_83497F50_G_(ctx, base); }

uint64_t Construct_TXT_83497F54_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F54_G_ = int32_t(0x83497F54);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497F54_G__address = int32_t(0x832A2060);
	if (!UseLiftedCode(143, 0x8324BBB8)) { __imp__sub_8324BBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F54_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F54_G__address);
}
PROMOTED_ENTRY(143, sub_8324BBB8, 0x8324BBB8) { ctx.r3.u64 = Construct_TXT_83497F54_G_(ctx, base); }

uint64_t Construct_TXT_83497F58_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F58_G_ = int32_t(0x83497F58);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497F58_G__address = int32_t(0x832A2070);
	if (!UseLiftedCode(143, 0x8324BBF8)) { __imp__sub_8324BBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BBF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F58_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F58_G__address);
}
PROMOTED_ENTRY(143, sub_8324BBF8, 0x8324BBF8) { ctx.r3.u64 = Construct_TXT_83497F58_G_(ctx, base); }

uint64_t Construct_TXT_83497F5C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F5C_G_ = int32_t(0x83497F5C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497F5C_G__address = int32_t(0x832A2080);
	if (!UseLiftedCode(143, 0x8324BC38)) { __imp__sub_8324BC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BC38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F5C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F5C_G__address);
}
PROMOTED_ENTRY(143, sub_8324BC38, 0x8324BC38) { ctx.r3.u64 = Construct_TXT_83497F5C_G_(ctx, base); }

uint64_t Construct_TXT_83497F60_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F60_G_ = int32_t(0x83497F60);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497F60_G__address = int32_t(0x832A2090);
	if (!UseLiftedCode(143, 0x8324BC78)) { __imp__sub_8324BC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BC78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F60_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F60_G__address);
}
PROMOTED_ENTRY(143, sub_8324BC78, 0x8324BC78) { ctx.r3.u64 = Construct_TXT_83497F60_G_(ctx, base); }

uint64_t Construct_TXT_83497F64_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497F64_G_ = int32_t(0x83497F64);
	constexpr int32_t str_TXT_820B3C38_B_ = int32_t(0x820B3C38);
	constexpr int32_t Destroy_TXT_83497F64_G__address = int32_t(0x832A20A0);
	if (!UseLiftedCode(143, 0x8324BCB8)) { __imp__sub_8324BCB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324BCB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497F64_G_, str_TXT_820B3C38_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497F64_G__address);
}
PROMOTED_ENTRY(143, sub_8324BCB8, 0x8324BCB8) { ctx.r3.u64 = Construct_TXT_83497F64_G_(ctx, base); }

uint64_t Construct_TXT_83497FBC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FBC_G_ = int32_t(0x83497FBC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83497FBC_G__address = int32_t(0x832A20B0);
	if (!UseLiftedCode(143, 0x8324C190)) { __imp__sub_8324C190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C190);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FBC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FBC_G__address);
}
PROMOTED_ENTRY(143, sub_8324C190, 0x8324C190) { ctx.r3.u64 = Construct_TXT_83497FBC_G_(ctx, base); }

uint64_t Construct_TXT_83497FC0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FC0_G_ = int32_t(0x83497FC0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83497FC0_G__address = int32_t(0x832A20C0);
	if (!UseLiftedCode(143, 0x8324C1D0)) { __imp__sub_8324C1D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C1D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FC0_G__address);
}
PROMOTED_ENTRY(143, sub_8324C1D0, 0x8324C1D0) { ctx.r3.u64 = Construct_TXT_83497FC0_G_(ctx, base); }

uint64_t Construct_TXT_83497FC4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FC4_G_ = int32_t(0x83497FC4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83497FC4_G__address = int32_t(0x832A20D0);
	if (!UseLiftedCode(143, 0x8324C210)) { __imp__sub_8324C210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C210);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FC4_G__address);
}
PROMOTED_ENTRY(143, sub_8324C210, 0x8324C210) { ctx.r3.u64 = Construct_TXT_83497FC4_G_(ctx, base); }

uint64_t Construct_TXT_83497FC8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FC8_G_ = int32_t(0x83497FC8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83497FC8_G__address = int32_t(0x832A20E0);
	if (!UseLiftedCode(143, 0x8324C250)) { __imp__sub_8324C250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C250);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FC8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FC8_G__address);
}
PROMOTED_ENTRY(143, sub_8324C250, 0x8324C250) { ctx.r3.u64 = Construct_TXT_83497FC8_G_(ctx, base); }

uint64_t Construct_TXT_83497FCC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FCC_G_ = int32_t(0x83497FCC);
	constexpr int32_t str_TXT_820B4150_B_ = int32_t(0x820B4150);
	constexpr int32_t Destroy_TXT_83497FCC_G__address = int32_t(0x832A20F0);
	if (!UseLiftedCode(143, 0x8324C290)) { __imp__sub_8324C290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C290);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FCC_G_, str_TXT_820B4150_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FCC_G__address);
}
PROMOTED_ENTRY(143, sub_8324C290, 0x8324C290) { ctx.r3.u64 = Construct_TXT_83497FCC_G_(ctx, base); }

uint64_t Construct_TXT_83497FD0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FD0_G_ = int32_t(0x83497FD0);
	constexpr int32_t str_TXT_820B4174_B_ = int32_t(0x820B4174);
	constexpr int32_t Destroy_TXT_83497FD0_G__address = int32_t(0x832A2100);
	if (!UseLiftedCode(143, 0x8324C2D0)) { __imp__sub_8324C2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C2D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD0_G_, str_TXT_820B4174_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FD0_G__address);
}
PROMOTED_ENTRY(143, sub_8324C2D0, 0x8324C2D0) { ctx.r3.u64 = Construct_TXT_83497FD0_G_(ctx, base); }

uint64_t Construct_TXT_83497FD4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FD4_G_ = int32_t(0x83497FD4);
	constexpr int32_t str_TXT_820B4198_B_ = int32_t(0x820B4198);
	constexpr int32_t Destroy_TXT_83497FD4_G__address = int32_t(0x832A2110);
	if (!UseLiftedCode(143, 0x8324C310)) { __imp__sub_8324C310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C310);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD4_G_, str_TXT_820B4198_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FD4_G__address);
}
PROMOTED_ENTRY(143, sub_8324C310, 0x8324C310) { ctx.r3.u64 = Construct_TXT_83497FD4_G_(ctx, base); }

uint64_t Construct_TXT_83497FD8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FD8_G_ = int32_t(0x83497FD8);
	constexpr int32_t str_TXT_820B41B8_B_ = int32_t(0x820B41B8);
	constexpr int32_t Destroy_TXT_83497FD8_G__address = int32_t(0x832A2120);
	if (!UseLiftedCode(143, 0x8324C350)) { __imp__sub_8324C350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C350);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FD8_G_, str_TXT_820B41B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FD8_G__address);
}
PROMOTED_ENTRY(143, sub_8324C350, 0x8324C350) { ctx.r3.u64 = Construct_TXT_83497FD8_G_(ctx, base); }

uint64_t Construct_TXT_83497FDC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FDC_G_ = int32_t(0x83497FDC);
	constexpr int32_t str_TXT_820B41E0_B_ = int32_t(0x820B41E0);
	constexpr int32_t Destroy_TXT_83497FDC_G__address = int32_t(0x832A2130);
	if (!UseLiftedCode(143, 0x8324C390)) { __imp__sub_8324C390(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C390);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FDC_G_, str_TXT_820B41E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FDC_G__address);
}
PROMOTED_ENTRY(143, sub_8324C390, 0x8324C390) { ctx.r3.u64 = Construct_TXT_83497FDC_G_(ctx, base); }

uint64_t Construct_TXT_83497FE0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FE0_G_ = int32_t(0x83497FE0);
	constexpr int32_t str_TXT_820B4208_B_ = int32_t(0x820B4208);
	constexpr int32_t Destroy_TXT_83497FE0_G__address = int32_t(0x832A2140);
	if (!UseLiftedCode(143, 0x8324C3D0)) { __imp__sub_8324C3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C3D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE0_G_, str_TXT_820B4208_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FE0_G__address);
}
PROMOTED_ENTRY(143, sub_8324C3D0, 0x8324C3D0) { ctx.r3.u64 = Construct_TXT_83497FE0_G_(ctx, base); }

uint64_t Construct_TXT_83497FE4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FE4_G_ = int32_t(0x83497FE4);
	constexpr int32_t str_TXT_820B4230_B_ = int32_t(0x820B4230);
	constexpr int32_t Destroy_TXT_83497FE4_G__address = int32_t(0x832A2150);
	if (!UseLiftedCode(143, 0x8324C410)) { __imp__sub_8324C410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C410);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE4_G_, str_TXT_820B4230_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FE4_G__address);
}
PROMOTED_ENTRY(143, sub_8324C410, 0x8324C410) { ctx.r3.u64 = Construct_TXT_83497FE4_G_(ctx, base); }

uint64_t Construct_TXT_83497FE8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FE8_G_ = int32_t(0x83497FE8);
	constexpr int32_t str_TXT_820B4250_B_ = int32_t(0x820B4250);
	constexpr int32_t Destroy_TXT_83497FE8_G__address = int32_t(0x832A2160);
	if (!UseLiftedCode(143, 0x8324C450)) { __imp__sub_8324C450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C450);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FE8_G_, str_TXT_820B4250_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FE8_G__address);
}
PROMOTED_ENTRY(143, sub_8324C450, 0x8324C450) { ctx.r3.u64 = Construct_TXT_83497FE8_G_(ctx, base); }

uint64_t Construct_TXT_83497FEC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FEC_G_ = int32_t(0x83497FEC);
	constexpr int32_t str_TXT_820B4274_B_ = int32_t(0x820B4274);
	constexpr int32_t Destroy_TXT_83497FEC_G__address = int32_t(0x832A2170);
	if (!UseLiftedCode(143, 0x8324C490)) { __imp__sub_8324C490(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C490);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FEC_G_, str_TXT_820B4274_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FEC_G__address);
}
PROMOTED_ENTRY(143, sub_8324C490, 0x8324C490) { ctx.r3.u64 = Construct_TXT_83497FEC_G_(ctx, base); }

uint64_t Construct_TXT_83497FF0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FF0_G_ = int32_t(0x83497FF0);
	constexpr int32_t str_TXT_820B4290_B_ = int32_t(0x820B4290);
	constexpr int32_t Destroy_TXT_83497FF0_G__address = int32_t(0x832A2180);
	if (!UseLiftedCode(143, 0x8324C4D0)) { __imp__sub_8324C4D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C4D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF0_G_, str_TXT_820B4290_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FF0_G__address);
}
PROMOTED_ENTRY(143, sub_8324C4D0, 0x8324C4D0) { ctx.r3.u64 = Construct_TXT_83497FF0_G_(ctx, base); }

uint64_t Construct_TXT_83497FF4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FF4_G_ = int32_t(0x83497FF4);
	constexpr int32_t str_TXT_820B42B0_B_ = int32_t(0x820B42B0);
	constexpr int32_t Destroy_TXT_83497FF4_G__address = int32_t(0x832A2190);
	if (!UseLiftedCode(143, 0x8324C510)) { __imp__sub_8324C510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C510);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF4_G_, str_TXT_820B42B0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FF4_G__address);
}
PROMOTED_ENTRY(143, sub_8324C510, 0x8324C510) { ctx.r3.u64 = Construct_TXT_83497FF4_G_(ctx, base); }

uint64_t Construct_TXT_83497FF8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FF8_G_ = int32_t(0x83497FF8);
	constexpr int32_t str_TXT_820B42C0_B_ = int32_t(0x820B42C0);
	constexpr int32_t Destroy_TXT_83497FF8_G__address = int32_t(0x832A21A0);
	if (!UseLiftedCode(143, 0x8324C550)) { __imp__sub_8324C550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C550);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FF8_G_, str_TXT_820B42C0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FF8_G__address);
}
PROMOTED_ENTRY(143, sub_8324C550, 0x8324C550) { ctx.r3.u64 = Construct_TXT_83497FF8_G_(ctx, base); }

uint64_t Construct_TXT_83497FFC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83497FFC_G_ = int32_t(0x83497FFC);
	constexpr int32_t str_TXT_820B42D0_B_ = int32_t(0x820B42D0);
	constexpr int32_t Destroy_TXT_83497FFC_G__address = int32_t(0x832A21B0);
	if (!UseLiftedCode(143, 0x8324C590)) { __imp__sub_8324C590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C590);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83497FFC_G_, str_TXT_820B42D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83497FFC_G__address);
}
PROMOTED_ENTRY(143, sub_8324C590, 0x8324C590) { ctx.r3.u64 = Construct_TXT_83497FFC_G_(ctx, base); }

uint64_t Construct_TXT_83498000_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498000_G_ = int32_t(0x83498000);
	constexpr int32_t str_TXT_820B42DC_B_ = int32_t(0x820B42DC);
	constexpr int32_t Destroy_TXT_83498000_G__address = int32_t(0x832A21C0);
	if (!UseLiftedCode(143, 0x8324C5D0)) { __imp__sub_8324C5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C5D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498000_G_, str_TXT_820B42DC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498000_G__address);
}
PROMOTED_ENTRY(143, sub_8324C5D0, 0x8324C5D0) { ctx.r3.u64 = Construct_TXT_83498000_G_(ctx, base); }

uint64_t Construct_TXT_83498004_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498004_G_ = int32_t(0x83498004);
	constexpr int32_t str_TXT_820B42F0_B_ = int32_t(0x820B42F0);
	constexpr int32_t Destroy_TXT_83498004_G__address = int32_t(0x832A21D0);
	if (!UseLiftedCode(143, 0x8324C610)) { __imp__sub_8324C610(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C610);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498004_G_, str_TXT_820B42F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498004_G__address);
}
PROMOTED_ENTRY(143, sub_8324C610, 0x8324C610) { ctx.r3.u64 = Construct_TXT_83498004_G_(ctx, base); }

uint64_t Construct_TXT_83498008_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498008_G_ = int32_t(0x83498008);
	constexpr int32_t str_TXT_820B430C_B_ = int32_t(0x820B430C);
	constexpr int32_t Destroy_TXT_83498008_G__address = int32_t(0x832A21E0);
	if (!UseLiftedCode(143, 0x8324C650)) { __imp__sub_8324C650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C650);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498008_G_, str_TXT_820B430C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498008_G__address);
}
PROMOTED_ENTRY(143, sub_8324C650, 0x8324C650) { ctx.r3.u64 = Construct_TXT_83498008_G_(ctx, base); }

uint64_t Construct_TXT_8349800C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349800C_G_ = int32_t(0x8349800C);
	constexpr int32_t str_TXT_820B4334_B_ = int32_t(0x820B4334);
	constexpr int32_t Destroy_TXT_8349800C_G__address = int32_t(0x832A21F0);
	if (!UseLiftedCode(143, 0x8324C690)) { __imp__sub_8324C690(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C690);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349800C_G_, str_TXT_820B4334_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349800C_G__address);
}
PROMOTED_ENTRY(143, sub_8324C690, 0x8324C690) { ctx.r3.u64 = Construct_TXT_8349800C_G_(ctx, base); }

uint64_t Construct_TXT_83498010_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498010_G_ = int32_t(0x83498010);
	constexpr int32_t str_TXT_820B4350_B_ = int32_t(0x820B4350);
	constexpr int32_t Destroy_TXT_83498010_G__address = int32_t(0x832A2200);
	if (!UseLiftedCode(143, 0x8324C6D0)) { __imp__sub_8324C6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C6D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498010_G_, str_TXT_820B4350_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498010_G__address);
}
PROMOTED_ENTRY(143, sub_8324C6D0, 0x8324C6D0) { ctx.r3.u64 = Construct_TXT_83498010_G_(ctx, base); }

uint64_t Construct_TXT_83498014_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498014_G_ = int32_t(0x83498014);
	constexpr int32_t str_TXT_820B4370_B_ = int32_t(0x820B4370);
	constexpr int32_t Destroy_TXT_83498014_G__address = int32_t(0x832A2210);
	if (!UseLiftedCode(143, 0x8324C710)) { __imp__sub_8324C710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C710);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498014_G_, str_TXT_820B4370_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498014_G__address);
}
PROMOTED_ENTRY(143, sub_8324C710, 0x8324C710) { ctx.r3.u64 = Construct_TXT_83498014_G_(ctx, base); }

uint64_t Construct_TXT_83498018_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498018_G_ = int32_t(0x83498018);
	constexpr int32_t str_TXT_820B4394_B_ = int32_t(0x820B4394);
	constexpr int32_t Destroy_TXT_83498018_G__address = int32_t(0x832A2220);
	if (!UseLiftedCode(143, 0x8324C750)) { __imp__sub_8324C750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C750);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498018_G_, str_TXT_820B4394_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498018_G__address);
}
PROMOTED_ENTRY(143, sub_8324C750, 0x8324C750) { ctx.r3.u64 = Construct_TXT_83498018_G_(ctx, base); }

uint64_t Construct_TXT_8349801C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349801C_G_ = int32_t(0x8349801C);
	constexpr int32_t str_TXT_820B43BC_B_ = int32_t(0x820B43BC);
	constexpr int32_t Destroy_TXT_8349801C_G__address = int32_t(0x832A2230);
	if (!UseLiftedCode(143, 0x8324C790)) { __imp__sub_8324C790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C790);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349801C_G_, str_TXT_820B43BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349801C_G__address);
}
PROMOTED_ENTRY(143, sub_8324C790, 0x8324C790) { ctx.r3.u64 = Construct_TXT_8349801C_G_(ctx, base); }

uint64_t Construct_TXT_83498020_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498020_G_ = int32_t(0x83498020);
	constexpr int32_t str_TXT_820B43F0_B_ = int32_t(0x820B43F0);
	constexpr int32_t Destroy_TXT_83498020_G__address = int32_t(0x832A2240);
	if (!UseLiftedCode(143, 0x8324C7D0)) { __imp__sub_8324C7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C7D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498020_G_, str_TXT_820B43F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498020_G__address);
}
PROMOTED_ENTRY(143, sub_8324C7D0, 0x8324C7D0) { ctx.r3.u64 = Construct_TXT_83498020_G_(ctx, base); }

uint64_t Construct_TXT_83498024_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498024_G_ = int32_t(0x83498024);
	constexpr int32_t str_TXT_820B43BC_B_ = int32_t(0x820B442C);
	constexpr int32_t Destroy_TXT_83498024_G__address = int32_t(0x832A2250);
	if (!UseLiftedCode(143, 0x8324C810)) { __imp__sub_8324C810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C810);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498024_G_, str_TXT_820B43BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498024_G__address);
}
PROMOTED_ENTRY(143, sub_8324C810, 0x8324C810) { ctx.r3.u64 = Construct_TXT_83498024_G_(ctx, base); }

uint64_t Construct_TXT_83498028_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498028_G_ = int32_t(0x83498028);
	constexpr int32_t str_TXT_820B43F0_B_ = int32_t(0x820B4460);
	constexpr int32_t Destroy_TXT_83498028_G__address = int32_t(0x832A2260);
	if (!UseLiftedCode(143, 0x8324C850)) { __imp__sub_8324C850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C850);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498028_G_, str_TXT_820B43F0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498028_G__address);
}
PROMOTED_ENTRY(143, sub_8324C850, 0x8324C850) { ctx.r3.u64 = Construct_TXT_83498028_G_(ctx, base); }

uint64_t Construct_TXT_8349802C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349802C_G_ = int32_t(0x8349802C);
	constexpr int32_t str_TXT_820B449C_B_ = int32_t(0x820B449C);
	constexpr int32_t Destroy_TXT_8349802C_G__address = int32_t(0x832A2270);
	if (!UseLiftedCode(143, 0x8324C890)) { __imp__sub_8324C890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C890);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349802C_G_, str_TXT_820B449C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349802C_G__address);
}
PROMOTED_ENTRY(143, sub_8324C890, 0x8324C890) { ctx.r3.u64 = Construct_TXT_8349802C_G_(ctx, base); }

uint64_t Construct_TXT_83498030_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498030_G_ = int32_t(0x83498030);
	constexpr int32_t str_TXT_820B44C4_B_ = int32_t(0x820B44C4);
	constexpr int32_t Destroy_TXT_83498030_G__address = int32_t(0x832A2280);
	if (!UseLiftedCode(143, 0x8324C8D0)) { __imp__sub_8324C8D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C8D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498030_G_, str_TXT_820B44C4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498030_G__address);
}
PROMOTED_ENTRY(143, sub_8324C8D0, 0x8324C8D0) { ctx.r3.u64 = Construct_TXT_83498030_G_(ctx, base); }

uint64_t Construct_TXT_83498034_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498034_G_ = int32_t(0x83498034);
	constexpr int32_t str_TXT_820B44EC_B_ = int32_t(0x820B44EC);
	constexpr int32_t Destroy_TXT_83498034_G__address = int32_t(0x832A2290);
	if (!UseLiftedCode(143, 0x8324C910)) { __imp__sub_8324C910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498034_G_, str_TXT_820B44EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498034_G__address);
}
PROMOTED_ENTRY(143, sub_8324C910, 0x8324C910) { ctx.r3.u64 = Construct_TXT_83498034_G_(ctx, base); }

uint64_t Construct_TXT_83498038_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498038_G_ = int32_t(0x83498038);
	constexpr int32_t str_TXT_820B4514_B_ = int32_t(0x820B4514);
	constexpr int32_t Destroy_TXT_83498038_G__address = int32_t(0x832A22A0);
	if (!UseLiftedCode(143, 0x8324C950)) { __imp__sub_8324C950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324C950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498038_G_, str_TXT_820B4514_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498038_G__address);
}
PROMOTED_ENTRY(143, sub_8324C950, 0x8324C950) { ctx.r3.u64 = Construct_TXT_83498038_G_(ctx, base); }

uint64_t Construct_TXT_83498040_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498040_G_ = int32_t(0x83498040);
	constexpr int32_t str_TXT_820B4564_B_ = int32_t(0x820B4564);
	constexpr int32_t Destroy_TXT_83498040_G__address = int32_t(0x832A22B8);
	if (!UseLiftedCode(143, 0x8324CA50)) { __imp__sub_8324CA50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CA50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498040_G_, str_TXT_820B4564_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498040_G__address);
}
PROMOTED_ENTRY(143, sub_8324CA50, 0x8324CA50) { ctx.r3.u64 = Construct_TXT_83498040_G_(ctx, base); }

uint64_t Construct_TXT_83498044_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498044_G_ = int32_t(0x83498044);
	constexpr int32_t str_TXT_820B4588_B_ = int32_t(0x820B4588);
	constexpr int32_t Destroy_TXT_83498044_G__address = int32_t(0x832A22C8);
	if (!UseLiftedCode(143, 0x8324CA90)) { __imp__sub_8324CA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CA90);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498044_G_, str_TXT_820B4588_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498044_G__address);
}
PROMOTED_ENTRY(143, sub_8324CA90, 0x8324CA90) { ctx.r3.u64 = Construct_TXT_83498044_G_(ctx, base); }

uint64_t Construct_TXT_83498048_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498048_G_ = int32_t(0x83498048);
	constexpr int32_t str_TXT_820B45A0_B_ = int32_t(0x820B45A0);
	constexpr int32_t Destroy_TXT_83498048_G__address = int32_t(0x832A22D8);
	if (!UseLiftedCode(143, 0x8324CAD0)) { __imp__sub_8324CAD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CAD0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498048_G_, str_TXT_820B45A0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498048_G__address);
}
PROMOTED_ENTRY(143, sub_8324CAD0, 0x8324CAD0) { ctx.r3.u64 = Construct_TXT_83498048_G_(ctx, base); }

uint64_t Construct_TXT_8349804C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349804C_G_ = int32_t(0x8349804C);
	constexpr int32_t str_TXT_820B45BC_B_ = int32_t(0x820B45BC);
	constexpr int32_t Destroy_TXT_8349804C_G__address = int32_t(0x832A22E8);
	if (!UseLiftedCode(143, 0x8324CB10)) { __imp__sub_8324CB10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CB10);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349804C_G_, str_TXT_820B45BC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349804C_G__address);
}
PROMOTED_ENTRY(143, sub_8324CB10, 0x8324CB10) { ctx.r3.u64 = Construct_TXT_8349804C_G_(ctx, base); }

uint64_t Construct_TXT_83498050_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498050_G_ = int32_t(0x83498050);
	constexpr int32_t str_TXT_820B45C8_B_ = int32_t(0x820B45C8);
	constexpr int32_t Destroy_TXT_83498050_G__address = int32_t(0x832A22F8);
	if (!UseLiftedCode(143, 0x8324CB50)) { __imp__sub_8324CB50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CB50);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498050_G_, str_TXT_820B45C8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498050_G__address);
}
PROMOTED_ENTRY(143, sub_8324CB50, 0x8324CB50) { ctx.r3.u64 = Construct_TXT_83498050_G_(ctx, base); }

uint64_t Construct_TXT_8349808C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349808C_G_ = int32_t(0x8349808C);
	constexpr int32_t str_TXT_820AE8EC_B_ = int32_t(0x820AE8EC);
	constexpr int32_t Destroy_TXT_8349808C_G__address = int32_t(0x832A23D8);
	if (!UseLiftedCode(143, 0x8324CFA8)) { __imp__sub_8324CFA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CFA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349808C_G_, str_TXT_820AE8EC_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349808C_G__address);
}
PROMOTED_ENTRY(143, sub_8324CFA8, 0x8324CFA8) { ctx.r3.u64 = Construct_TXT_8349808C_G_(ctx, base); }

uint64_t Construct_TXT_834980F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834980F0_G_ = int32_t(0x834980F0);
	constexpr int32_t str_TXT_820B4768_B_ = int32_t(0x820B4768);
	constexpr int32_t Destroy_TXT_834980F0_G__address = int32_t(0x832A23E8);
	if (!UseLiftedCode(143, 0x8324CFE8)) { __imp__sub_8324CFE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324CFE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F0_G_, str_TXT_820B4768_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834980F0_G__address);
}
PROMOTED_ENTRY(143, sub_8324CFE8, 0x8324CFE8) { ctx.r3.u64 = Construct_TXT_834980F0_G_(ctx, base); }

uint64_t Construct_TXT_834980F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834980F4_G_ = int32_t(0x834980F4);
	constexpr int32_t str_TXT_820B478C_B_ = int32_t(0x820B478C);
	constexpr int32_t Destroy_TXT_834980F4_G__address = int32_t(0x832A23F8);
	if (!UseLiftedCode(143, 0x8324D028)) { __imp__sub_8324D028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D028);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F4_G_, str_TXT_820B478C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834980F4_G__address);
}
PROMOTED_ENTRY(143, sub_8324D028, 0x8324D028) { ctx.r3.u64 = Construct_TXT_834980F4_G_(ctx, base); }

uint64_t Construct_TXT_834980F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834980F8_G_ = int32_t(0x834980F8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834980F8_G__address = int32_t(0x832A2408);
	if (!UseLiftedCode(143, 0x8324D068)) { __imp__sub_8324D068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D068);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834980F8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834980F8_G__address);
}
PROMOTED_ENTRY(143, sub_8324D068, 0x8324D068) { ctx.r3.u64 = Construct_TXT_834980F8_G_(ctx, base); }

uint64_t Construct_TXT_834980FC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834980FC_G_ = int32_t(0x834980FC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834980FC_G__address = int32_t(0x832A2418);
	if (!UseLiftedCode(143, 0x8324D0A8)) { __imp__sub_8324D0A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D0A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834980FC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834980FC_G__address);
}
PROMOTED_ENTRY(143, sub_8324D0A8, 0x8324D0A8) { ctx.r3.u64 = Construct_TXT_834980FC_G_(ctx, base); }

uint64_t Construct_TXT_83498100_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498100_G_ = int32_t(0x83498100);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498100_G__address = int32_t(0x832A2428);
	if (!UseLiftedCode(143, 0x8324D0E8)) { __imp__sub_8324D0E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D0E8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498100_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498100_G__address);
}
PROMOTED_ENTRY(143, sub_8324D0E8, 0x8324D0E8) { ctx.r3.u64 = Construct_TXT_83498100_G_(ctx, base); }

uint64_t Construct_TXT_83498104_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498104_G_ = int32_t(0x83498104);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498104_G__address = int32_t(0x832A2438);
	if (!UseLiftedCode(143, 0x8324D128)) { __imp__sub_8324D128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D128);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498104_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498104_G__address);
}
PROMOTED_ENTRY(143, sub_8324D128, 0x8324D128) { ctx.r3.u64 = Construct_TXT_83498104_G_(ctx, base); }

uint64_t Construct_TXT_83498108_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498108_G_ = int32_t(0x83498108);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498108_G__address = int32_t(0x832A2448);
	if (!UseLiftedCode(143, 0x8324D168)) { __imp__sub_8324D168(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D168);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498108_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498108_G__address);
}
PROMOTED_ENTRY(143, sub_8324D168, 0x8324D168) { ctx.r3.u64 = Construct_TXT_83498108_G_(ctx, base); }

uint64_t Construct_TXT_8349810C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349810C_G_ = int32_t(0x8349810C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349810C_G__address = int32_t(0x832A2458);
	if (!UseLiftedCode(143, 0x8324D1A8)) { __imp__sub_8324D1A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1A8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349810C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349810C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D1A8, 0x8324D1A8) { ctx.r3.u64 = Construct_TXT_8349810C_G_(ctx, base); }

uint64_t n_sub_8324D1E8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A2468_address = int32_t(0x832A2468);
	if (!UseLiftedCode(143, 0x8324D1E8)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324D1E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1E8);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A2468_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324D1E8, 0x8324D1E8) { ctx.r3.u64 = n_sub_8324D1E8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324D1F8(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A24D0_address = int32_t(0x832A24D0);
	if (!UseLiftedCode(143, 0x8324D1F8)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324D1F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D1F8);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A24D0_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324D1F8, 0x8324D1F8) { ctx.r3.u64 = n_sub_8324D1F8(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324D208(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A2538_address = int32_t(0x832A2538);
	if (!UseLiftedCode(143, 0x8324D208)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324D208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D208);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A2538_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324D208, 0x8324D208) { ctx.r3.u64 = n_sub_8324D208(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83498140_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498140_G_ = int32_t(0x83498140);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498140_G__address = int32_t(0x832A2590);
	if (!UseLiftedCode(143, 0x8324D218)) { __imp__sub_8324D218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D218);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498140_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498140_G__address);
}
PROMOTED_ENTRY(143, sub_8324D218, 0x8324D218) { ctx.r3.u64 = Construct_TXT_83498140_G_(ctx, base); }

uint64_t Construct_TXT_83498144_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498144_G_ = int32_t(0x83498144);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498144_G__address = int32_t(0x832A25A0);
	if (!UseLiftedCode(143, 0x8324D258)) { __imp__sub_8324D258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D258);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498144_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498144_G__address);
}
PROMOTED_ENTRY(143, sub_8324D258, 0x8324D258) { ctx.r3.u64 = Construct_TXT_83498144_G_(ctx, base); }

uint64_t Construct_TXT_83498148_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498148_G_ = int32_t(0x83498148);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498148_G__address = int32_t(0x832A25B0);
	if (!UseLiftedCode(143, 0x8324D298)) { __imp__sub_8324D298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D298);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498148_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498148_G__address);
}
PROMOTED_ENTRY(143, sub_8324D298, 0x8324D298) { ctx.r3.u64 = Construct_TXT_83498148_G_(ctx, base); }

uint64_t Construct_TXT_8349814C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349814C_G_ = int32_t(0x8349814C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349814C_G__address = int32_t(0x832A25C0);
	if (!UseLiftedCode(143, 0x8324D2D8)) { __imp__sub_8324D2D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D2D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349814C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349814C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D2D8, 0x8324D2D8) { ctx.r3.u64 = Construct_TXT_8349814C_G_(ctx, base); }

uint64_t Construct_TXT_83498150_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498150_G_ = int32_t(0x83498150);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498150_G__address = int32_t(0x832A25D0);
	if (!UseLiftedCode(143, 0x8324D318)) { __imp__sub_8324D318(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D318);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498150_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498150_G__address);
}
PROMOTED_ENTRY(143, sub_8324D318, 0x8324D318) { ctx.r3.u64 = Construct_TXT_83498150_G_(ctx, base); }

uint64_t Construct_TXT_83498154_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498154_G_ = int32_t(0x83498154);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498154_G__address = int32_t(0x832A25E0);
	if (!UseLiftedCode(143, 0x8324D358)) { __imp__sub_8324D358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D358);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498154_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498154_G__address);
}
PROMOTED_ENTRY(143, sub_8324D358, 0x8324D358) { ctx.r3.u64 = Construct_TXT_83498154_G_(ctx, base); }

uint64_t Construct_TXT_83498158_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498158_G_ = int32_t(0x83498158);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498158_G__address = int32_t(0x832A25F0);
	if (!UseLiftedCode(143, 0x8324D398)) { __imp__sub_8324D398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D398);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498158_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498158_G__address);
}
PROMOTED_ENTRY(143, sub_8324D398, 0x8324D398) { ctx.r3.u64 = Construct_TXT_83498158_G_(ctx, base); }

uint64_t Construct_TXT_8349815C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349815C_G_ = int32_t(0x8349815C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349815C_G__address = int32_t(0x832A2600);
	if (!UseLiftedCode(143, 0x8324D3D8)) { __imp__sub_8324D3D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D3D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349815C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349815C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D3D8, 0x8324D3D8) { ctx.r3.u64 = Construct_TXT_8349815C_G_(ctx, base); }

uint64_t Construct_TXT_83498160_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498160_G_ = int32_t(0x83498160);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498160_G__address = int32_t(0x832A2610);
	if (!UseLiftedCode(143, 0x8324D418)) { __imp__sub_8324D418(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D418);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498160_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498160_G__address);
}
PROMOTED_ENTRY(143, sub_8324D418, 0x8324D418) { ctx.r3.u64 = Construct_TXT_83498160_G_(ctx, base); }

uint64_t Construct_TXT_83498164_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498164_G_ = int32_t(0x83498164);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_83498164_G__address = int32_t(0x832A2620);
	if (!UseLiftedCode(143, 0x8324D458)) { __imp__sub_8324D458(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D458);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498164_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498164_G__address);
}
PROMOTED_ENTRY(143, sub_8324D458, 0x8324D458) { ctx.r3.u64 = Construct_TXT_83498164_G_(ctx, base); }

uint64_t Construct_TXT_83498168_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498168_G_ = int32_t(0x83498168);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498168_G__address = int32_t(0x832A2630);
	if (!UseLiftedCode(143, 0x8324D498)) { __imp__sub_8324D498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D498);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498168_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498168_G__address);
}
PROMOTED_ENTRY(143, sub_8324D498, 0x8324D498) { ctx.r3.u64 = Construct_TXT_83498168_G_(ctx, base); }

uint64_t Construct_TXT_8349816C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349816C_G_ = int32_t(0x8349816C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349816C_G__address = int32_t(0x832A2640);
	if (!UseLiftedCode(143, 0x8324D4D8)) { __imp__sub_8324D4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D4D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349816C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349816C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D4D8, 0x8324D4D8) { ctx.r3.u64 = Construct_TXT_8349816C_G_(ctx, base); }

uint64_t Construct_TXT_83498170_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498170_G_ = int32_t(0x83498170);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498170_G__address = int32_t(0x832A2650);
	if (!UseLiftedCode(143, 0x8324D518)) { __imp__sub_8324D518(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D518);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498170_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498170_G__address);
}
PROMOTED_ENTRY(143, sub_8324D518, 0x8324D518) { ctx.r3.u64 = Construct_TXT_83498170_G_(ctx, base); }

uint64_t Construct_TXT_83498174_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498174_G_ = int32_t(0x83498174);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498174_G__address = int32_t(0x832A2660);
	if (!UseLiftedCode(143, 0x8324D558)) { __imp__sub_8324D558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D558);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498174_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498174_G__address);
}
PROMOTED_ENTRY(143, sub_8324D558, 0x8324D558) { ctx.r3.u64 = Construct_TXT_83498174_G_(ctx, base); }

uint64_t Construct_TXT_83498178_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498178_G_ = int32_t(0x83498178);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498178_G__address = int32_t(0x832A2670);
	if (!UseLiftedCode(143, 0x8324D598)) { __imp__sub_8324D598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D598);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498178_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498178_G__address);
}
PROMOTED_ENTRY(143, sub_8324D598, 0x8324D598) { ctx.r3.u64 = Construct_TXT_83498178_G_(ctx, base); }

uint64_t Construct_TXT_8349817C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349817C_G_ = int32_t(0x8349817C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349817C_G__address = int32_t(0x832A2680);
	if (!UseLiftedCode(143, 0x8324D5D8)) { __imp__sub_8324D5D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D5D8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349817C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349817C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D5D8, 0x8324D5D8) { ctx.r3.u64 = Construct_TXT_8349817C_G_(ctx, base); }

uint64_t Construct_TXT_83498198_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498198_G_ = int32_t(0x83498198);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498198_G__address = int32_t(0x832A26F8);
	if (!UseLiftedCode(143, 0x8324D6F8)) { __imp__sub_8324D6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D6F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498198_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498198_G__address);
}
PROMOTED_ENTRY(143, sub_8324D6F8, 0x8324D6F8) { ctx.r3.u64 = Construct_TXT_83498198_G_(ctx, base); }

uint64_t Construct_TXT_8349819C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349819C_G_ = int32_t(0x8349819C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349819C_G__address = int32_t(0x832A2708);
	if (!UseLiftedCode(143, 0x8324D738)) { __imp__sub_8324D738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D738);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349819C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349819C_G__address);
}
PROMOTED_ENTRY(143, sub_8324D738, 0x8324D738) { ctx.r3.u64 = Construct_TXT_8349819C_G_(ctx, base); }

uint64_t Construct_TXT_834981A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981A0_G_ = int32_t(0x834981A0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834981A0_G__address = int32_t(0x832A2718);
	if (!UseLiftedCode(143, 0x8324D778)) { __imp__sub_8324D778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D778);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981A0_G__address);
}
PROMOTED_ENTRY(143, sub_8324D778, 0x8324D778) { ctx.r3.u64 = Construct_TXT_834981A0_G_(ctx, base); }

uint64_t Construct_TXT_834981A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981A4_G_ = int32_t(0x834981A4);
	constexpr int32_t str_TXT_820B7150_B_ = int32_t(0x820B7150);
	constexpr int32_t Destroy_TXT_834981A4_G__address = int32_t(0x832A2728);
	if (!UseLiftedCode(143, 0x8324D7B8)) { __imp__sub_8324D7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D7B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A4_G_, str_TXT_820B7150_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981A4_G__address);
}
PROMOTED_ENTRY(143, sub_8324D7B8, 0x8324D7B8) { ctx.r3.u64 = Construct_TXT_834981A4_G_(ctx, base); }

uint64_t Construct_TXT_834981A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981A8_G_ = int32_t(0x834981A8);
	constexpr int32_t str_TXT_820B7160_B_ = int32_t(0x820B7160);
	constexpr int32_t Destroy_TXT_834981A8_G__address = int32_t(0x832A2738);
	if (!UseLiftedCode(143, 0x8324D7F8)) { __imp__sub_8324D7F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D7F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981A8_G_, str_TXT_820B7160_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981A8_G__address);
}
PROMOTED_ENTRY(143, sub_8324D7F8, 0x8324D7F8) { ctx.r3.u64 = Construct_TXT_834981A8_G_(ctx, base); }

uint64_t Construct_TXT_834981AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981AC_G_ = int32_t(0x834981AC);
	constexpr int32_t str_TXT_820B7170_B_ = int32_t(0x820B7170);
	constexpr int32_t Destroy_TXT_834981AC_G__address = int32_t(0x832A2748);
	if (!UseLiftedCode(143, 0x8324D838)) { __imp__sub_8324D838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D838);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981AC_G_, str_TXT_820B7170_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981AC_G__address);
}
PROMOTED_ENTRY(143, sub_8324D838, 0x8324D838) { ctx.r3.u64 = Construct_TXT_834981AC_G_(ctx, base); }

uint64_t Construct_TXT_834981B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981B0_G_ = int32_t(0x834981B0);
	constexpr int32_t str_TXT_820B7184_B_ = int32_t(0x820B7184);
	constexpr int32_t Destroy_TXT_834981B0_G__address = int32_t(0x832A2758);
	if (!UseLiftedCode(143, 0x8324D878)) { __imp__sub_8324D878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D878);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B0_G_, str_TXT_820B7184_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981B0_G__address);
}
PROMOTED_ENTRY(143, sub_8324D878, 0x8324D878) { ctx.r3.u64 = Construct_TXT_834981B0_G_(ctx, base); }

uint64_t Construct_TXT_834981B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981B4_G_ = int32_t(0x834981B4);
	constexpr int32_t str_TXT_820B7190_B_ = int32_t(0x820B7190);
	constexpr int32_t Destroy_TXT_834981B4_G__address = int32_t(0x832A2768);
	if (!UseLiftedCode(143, 0x8324D8B8)) { __imp__sub_8324D8B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D8B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B4_G_, str_TXT_820B7190_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981B4_G__address);
}
PROMOTED_ENTRY(143, sub_8324D8B8, 0x8324D8B8) { ctx.r3.u64 = Construct_TXT_834981B4_G_(ctx, base); }

uint64_t Construct_TXT_834981B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981B8_G_ = int32_t(0x834981B8);
	constexpr int32_t str_TXT_820B71A4_B_ = int32_t(0x820B71A4);
	constexpr int32_t Destroy_TXT_834981B8_G__address = int32_t(0x832A2778);
	if (!UseLiftedCode(143, 0x8324D8F8)) { __imp__sub_8324D8F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D8F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981B8_G_, str_TXT_820B71A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981B8_G__address);
}
PROMOTED_ENTRY(143, sub_8324D8F8, 0x8324D8F8) { ctx.r3.u64 = Construct_TXT_834981B8_G_(ctx, base); }

uint64_t Construct_TXT_834981BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981BC_G_ = int32_t(0x834981BC);
	constexpr int32_t str_TXT_820B71B8_B_ = int32_t(0x820B71B8);
	constexpr int32_t Destroy_TXT_834981BC_G__address = int32_t(0x832A2788);
	if (!UseLiftedCode(143, 0x8324D938)) { __imp__sub_8324D938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D938);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981BC_G_, str_TXT_820B71B8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981BC_G__address);
}
PROMOTED_ENTRY(143, sub_8324D938, 0x8324D938) { ctx.r3.u64 = Construct_TXT_834981BC_G_(ctx, base); }

uint64_t Construct_TXT_834981C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981C0_G_ = int32_t(0x834981C0);
	constexpr int32_t str_TXT_820B71D0_B_ = int32_t(0x820B71D0);
	constexpr int32_t Destroy_TXT_834981C0_G__address = int32_t(0x832A2798);
	if (!UseLiftedCode(143, 0x8324D978)) { __imp__sub_8324D978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D978);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C0_G_, str_TXT_820B71D0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981C0_G__address);
}
PROMOTED_ENTRY(143, sub_8324D978, 0x8324D978) { ctx.r3.u64 = Construct_TXT_834981C0_G_(ctx, base); }

uint64_t Construct_TXT_834981C4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981C4_G_ = int32_t(0x834981C4);
	constexpr int32_t str_TXT_820B71E8_B_ = int32_t(0x820B71E8);
	constexpr int32_t Destroy_TXT_834981C4_G__address = int32_t(0x832A27A8);
	if (!UseLiftedCode(143, 0x8324D9B8)) { __imp__sub_8324D9B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D9B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C4_G_, str_TXT_820B71E8_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981C4_G__address);
}
PROMOTED_ENTRY(143, sub_8324D9B8, 0x8324D9B8) { ctx.r3.u64 = Construct_TXT_834981C4_G_(ctx, base); }

uint64_t Construct_TXT_834981C8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981C8_G_ = int32_t(0x834981C8);
	constexpr int32_t str_TXT_820B7200_B_ = int32_t(0x820B7200);
	constexpr int32_t Destroy_TXT_834981C8_G__address = int32_t(0x832A27B8);
	if (!UseLiftedCode(143, 0x8324D9F8)) { __imp__sub_8324D9F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324D9F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981C8_G_, str_TXT_820B7200_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981C8_G__address);
}
PROMOTED_ENTRY(143, sub_8324D9F8, 0x8324D9F8) { ctx.r3.u64 = Construct_TXT_834981C8_G_(ctx, base); }

uint64_t Construct_TXT_834981CC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981CC_G_ = int32_t(0x834981CC);
	constexpr int32_t str_TXT_820B7218_B_ = int32_t(0x820B7218);
	constexpr int32_t Destroy_TXT_834981CC_G__address = int32_t(0x832A27C8);
	if (!UseLiftedCode(143, 0x8324DA38)) { __imp__sub_8324DA38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DA38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981CC_G_, str_TXT_820B7218_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981CC_G__address);
}
PROMOTED_ENTRY(143, sub_8324DA38, 0x8324DA38) { ctx.r3.u64 = Construct_TXT_834981CC_G_(ctx, base); }

uint64_t Construct_TXT_834981D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981D0_G_ = int32_t(0x834981D0);
	constexpr int32_t str_TXT_820B7224_B_ = int32_t(0x820B7224);
	constexpr int32_t Destroy_TXT_834981D0_G__address = int32_t(0x832A27D8);
	if (!UseLiftedCode(143, 0x8324DA78)) { __imp__sub_8324DA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DA78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D0_G_, str_TXT_820B7224_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981D0_G__address);
}
PROMOTED_ENTRY(143, sub_8324DA78, 0x8324DA78) { ctx.r3.u64 = Construct_TXT_834981D0_G_(ctx, base); }

uint64_t Construct_TXT_834981D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981D4_G_ = int32_t(0x834981D4);
	constexpr int32_t str_TXT_820B7228_B_ = int32_t(0x820B7228);
	constexpr int32_t Destroy_TXT_834981D4_G__address = int32_t(0x832A27E8);
	if (!UseLiftedCode(143, 0x8324DAB8)) { __imp__sub_8324DAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D4_G_, str_TXT_820B7228_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981D4_G__address);
}
PROMOTED_ENTRY(143, sub_8324DAB8, 0x8324DAB8) { ctx.r3.u64 = Construct_TXT_834981D4_G_(ctx, base); }

uint64_t Construct_TXT_834981D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981D8_G_ = int32_t(0x834981D8);
	constexpr int32_t str_TXT_820B7230_B_ = int32_t(0x820B7230);
	constexpr int32_t Destroy_TXT_834981D8_G__address = int32_t(0x832A27F8);
	if (!UseLiftedCode(143, 0x8324DAF8)) { __imp__sub_8324DAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981D8_G_, str_TXT_820B7230_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981D8_G__address);
}
PROMOTED_ENTRY(143, sub_8324DAF8, 0x8324DAF8) { ctx.r3.u64 = Construct_TXT_834981D8_G_(ctx, base); }

uint64_t Construct_TXT_834981DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981DC_G_ = int32_t(0x834981DC);
	constexpr int32_t str_TXT_820B724C_B_ = int32_t(0x820B724C);
	constexpr int32_t Destroy_TXT_834981DC_G__address = int32_t(0x832A2808);
	if (!UseLiftedCode(143, 0x8324DB38)) { __imp__sub_8324DB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DB38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981DC_G_, str_TXT_820B724C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981DC_G__address);
}
PROMOTED_ENTRY(143, sub_8324DB38, 0x8324DB38) { ctx.r3.u64 = Construct_TXT_834981DC_G_(ctx, base); }

uint64_t Construct_TXT_834981E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981E0_G_ = int32_t(0x834981E0);
	constexpr int32_t str_TXT_820B7268_B_ = int32_t(0x820B7268);
	constexpr int32_t Destroy_TXT_834981E0_G__address = int32_t(0x832A2818);
	if (!UseLiftedCode(143, 0x8324DB78)) { __imp__sub_8324DB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DB78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E0_G_, str_TXT_820B7268_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981E0_G__address);
}
PROMOTED_ENTRY(143, sub_8324DB78, 0x8324DB78) { ctx.r3.u64 = Construct_TXT_834981E0_G_(ctx, base); }

uint64_t Construct_TXT_834981E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981E4_G_ = int32_t(0x834981E4);
	constexpr int32_t str_TXT_820B7274_B_ = int32_t(0x820B7274);
	constexpr int32_t Destroy_TXT_834981E4_G__address = int32_t(0x832A2828);
	if (!UseLiftedCode(143, 0x8324DBB8)) { __imp__sub_8324DBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E4_G_, str_TXT_820B7274_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981E4_G__address);
}
PROMOTED_ENTRY(143, sub_8324DBB8, 0x8324DBB8) { ctx.r3.u64 = Construct_TXT_834981E4_G_(ctx, base); }

uint64_t Construct_TXT_834981E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981E8_G_ = int32_t(0x834981E8);
	constexpr int32_t str_TXT_820B7284_B_ = int32_t(0x820B7284);
	constexpr int32_t Destroy_TXT_834981E8_G__address = int32_t(0x832A2838);
	if (!UseLiftedCode(143, 0x8324DBF8)) { __imp__sub_8324DBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DBF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981E8_G_, str_TXT_820B7284_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981E8_G__address);
}
PROMOTED_ENTRY(143, sub_8324DBF8, 0x8324DBF8) { ctx.r3.u64 = Construct_TXT_834981E8_G_(ctx, base); }

uint64_t Construct_TXT_834981EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981EC_G_ = int32_t(0x834981EC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834981EC_G__address = int32_t(0x832A2848);
	if (!UseLiftedCode(143, 0x8324DC38)) { __imp__sub_8324DC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DC38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981EC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981EC_G__address);
}
PROMOTED_ENTRY(143, sub_8324DC38, 0x8324DC38) { ctx.r3.u64 = Construct_TXT_834981EC_G_(ctx, base); }

uint64_t Construct_TXT_834981F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981F0_G_ = int32_t(0x834981F0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834981F0_G__address = int32_t(0x832A2858);
	if (!UseLiftedCode(143, 0x8324DC78)) { __imp__sub_8324DC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DC78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981F0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981F0_G__address);
}
PROMOTED_ENTRY(143, sub_8324DC78, 0x8324DC78) { ctx.r3.u64 = Construct_TXT_834981F0_G_(ctx, base); }

uint64_t Construct_TXT_834981F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834981F4_G_ = int32_t(0x834981F4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834981F4_G__address = int32_t(0x832A2868);
	if (!UseLiftedCode(143, 0x8324DCB8)) { __imp__sub_8324DCB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324DCB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834981F4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834981F4_G__address);
}
PROMOTED_ENTRY(143, sub_8324DCB8, 0x8324DCB8) { ctx.r3.u64 = Construct_TXT_834981F4_G_(ctx, base); }

uint64_t Construct_TXT_834982A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982A0_G_ = int32_t(0x834982A0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834982A0_G__address = int32_t(0x832A28E0);
	if (!UseLiftedCode(143, 0x8324E048)) { __imp__sub_8324E048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E048);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982A0_G__address);
}
PROMOTED_ENTRY(143, sub_8324E048, 0x8324E048) { ctx.r3.u64 = Construct_TXT_834982A0_G_(ctx, base); }

uint64_t Construct_TXT_834982A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982A4_G_ = int32_t(0x834982A4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834982A4_G__address = int32_t(0x832A28F0);
	if (!UseLiftedCode(143, 0x8324E088)) { __imp__sub_8324E088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E088);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982A4_G__address);
}
PROMOTED_ENTRY(143, sub_8324E088, 0x8324E088) { ctx.r3.u64 = Construct_TXT_834982A4_G_(ctx, base); }

uint64_t Construct_TXT_834982A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982A8_G_ = int32_t(0x834982A8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834982A8_G__address = int32_t(0x832A2900);
	if (!UseLiftedCode(143, 0x8324E0C8)) { __imp__sub_8324E0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E0C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982A8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982A8_G__address);
}
PROMOTED_ENTRY(143, sub_8324E0C8, 0x8324E0C8) { ctx.r3.u64 = Construct_TXT_834982A8_G_(ctx, base); }

uint64_t Construct_TXT_834982AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982AC_G_ = int32_t(0x834982AC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834982AC_G__address = int32_t(0x832A2910);
	if (!UseLiftedCode(143, 0x8324E108)) { __imp__sub_8324E108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E108);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982AC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982AC_G__address);
}
PROMOTED_ENTRY(143, sub_8324E108, 0x8324E108) { ctx.r3.u64 = Construct_TXT_834982AC_G_(ctx, base); }

uint64_t Construct_TXT_834982B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982B0_G_ = int32_t(0x834982B0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834982B0_G__address = int32_t(0x832A2920);
	if (!UseLiftedCode(143, 0x8324E148)) { __imp__sub_8324E148(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E148);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982B0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982B0_G__address);
}
PROMOTED_ENTRY(143, sub_8324E148, 0x8324E148) { ctx.r3.u64 = Construct_TXT_834982B0_G_(ctx, base); }

uint64_t Construct_TXT_834982B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834982B4_G_ = int32_t(0x834982B4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834982B4_G__address = int32_t(0x832A2930);
	if (!UseLiftedCode(143, 0x8324E188)) { __imp__sub_8324E188(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E188);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834982B4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834982B4_G__address);
}
PROMOTED_ENTRY(143, sub_8324E188, 0x8324E188) { ctx.r3.u64 = Construct_TXT_834982B4_G_(ctx, base); }

uint64_t Construct_TXT_8349833C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349833C_G_ = int32_t(0x8349833C);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_8349833C_G__address = int32_t(0x832A2A90);
	if (!UseLiftedCode(143, 0x8324E3C0)) { __imp__sub_8324E3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E3C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349833C_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349833C_G__address);
}
PROMOTED_ENTRY(143, sub_8324E3C0, 0x8324E3C0) { ctx.r3.u64 = Construct_TXT_8349833C_G_(ctx, base); }

uint64_t Construct_TXT_83498340_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498340_G_ = int32_t(0x83498340);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498340_G__address = int32_t(0x832A2AA0);
	if (!UseLiftedCode(143, 0x8324E400)) { __imp__sub_8324E400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E400);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498340_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498340_G__address);
}
PROMOTED_ENTRY(143, sub_8324E400, 0x8324E400) { ctx.r3.u64 = Construct_TXT_83498340_G_(ctx, base); }

uint64_t Construct_TXT_83498344_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498344_G_ = int32_t(0x83498344);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498344_G__address = int32_t(0x832A2AB0);
	if (!UseLiftedCode(143, 0x8324E440)) { __imp__sub_8324E440(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E440);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498344_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498344_G__address);
}
PROMOTED_ENTRY(143, sub_8324E440, 0x8324E440) { ctx.r3.u64 = Construct_TXT_83498344_G_(ctx, base); }

// sub_8324E480  [64 bytes]
uint64_t n_sub_8324E480(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498348_G_ = int32_t(0x83498348);
	constexpr int32_t str_TXT_820B870C_B_ = int32_t(0x820B870C);
	constexpr int32_t Destroy_TXT_83498348_G__address = int32_t(0x832A2AC0);
	if (!UseLiftedCode(143, 0x8324E480)) { __imp__sub_8324E480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E480);
	uint32_t stack = ctx.r1.u64;
	// Construct the global string from a C string, then register its release to run at exit
	// (n_sub_82CA3700 is atexit).
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, TXT_83498348_G_, str_TXT_820B870C_B_, -1);
	uint64_t result = RegisterAtExit(ctx, base, Destroy_TXT_83498348_G__address);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(143, sub_8324E480, 0x8324E480) { ctx.r3.u64 = n_sub_8324E480(ctx, base); }

uint64_t Construct_TXT_8349834C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349834C_G_ = int32_t(0x8349834C);
	constexpr int32_t str_TXT_820B8714_B_ = int32_t(0x820B8714);
	constexpr int32_t Destroy_TXT_8349834C_G__address = int32_t(0x832A2AD0);
	if (!UseLiftedCode(143, 0x8324E4C0)) { __imp__sub_8324E4C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E4C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349834C_G_, str_TXT_820B8714_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349834C_G__address);
}
PROMOTED_ENTRY(143, sub_8324E4C0, 0x8324E4C0) { ctx.r3.u64 = Construct_TXT_8349834C_G_(ctx, base); }

uint64_t Construct_TXT_83498350_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498350_G_ = int32_t(0x83498350);
	constexpr int32_t str_TXT_820B8720_B_ = int32_t(0x820B8720);
	constexpr int32_t Destroy_TXT_83498350_G__address = int32_t(0x832A2AE0);
	if (!UseLiftedCode(143, 0x8324E500)) { __imp__sub_8324E500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E500);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498350_G_, str_TXT_820B8720_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498350_G__address);
}
PROMOTED_ENTRY(143, sub_8324E500, 0x8324E500) { ctx.r3.u64 = Construct_TXT_83498350_G_(ctx, base); }

uint64_t Construct_TXT_83498354_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498354_G_ = int32_t(0x83498354);
	constexpr int32_t str_TXT_820B872C_B_ = int32_t(0x820B872C);
	constexpr int32_t Destroy_TXT_83498354_G__address = int32_t(0x832A2AF0);
	if (!UseLiftedCode(143, 0x8324E540)) { __imp__sub_8324E540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E540);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498354_G_, str_TXT_820B872C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498354_G__address);
}
PROMOTED_ENTRY(143, sub_8324E540, 0x8324E540) { ctx.r3.u64 = Construct_TXT_83498354_G_(ctx, base); }

uint64_t Construct_TXT_83498358_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498358_G_ = int32_t(0x83498358);
	constexpr int32_t str_TXT_820B873C_B_ = int32_t(0x820B873C);
	constexpr int32_t Destroy_TXT_83498358_G__address = int32_t(0x832A2B00);
	if (!UseLiftedCode(143, 0x8324E580)) { __imp__sub_8324E580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E580);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498358_G_, str_TXT_820B873C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498358_G__address);
}
PROMOTED_ENTRY(143, sub_8324E580, 0x8324E580) { ctx.r3.u64 = Construct_TXT_83498358_G_(ctx, base); }

uint64_t Construct_TXT_8349835C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349835C_G_ = int32_t(0x8349835C);
	constexpr int32_t str_TXT_820B3F1C_B_ = int32_t(0x820B3F1C);
	constexpr int32_t Destroy_TXT_8349835C_G__address = int32_t(0x832A2B10);
	if (!UseLiftedCode(143, 0x8324E5C0)) { __imp__sub_8324E5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E5C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349835C_G_, str_TXT_820B3F1C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349835C_G__address);
}
PROMOTED_ENTRY(143, sub_8324E5C0, 0x8324E5C0) { ctx.r3.u64 = Construct_TXT_8349835C_G_(ctx, base); }

uint64_t Construct_TXT_83498360_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498360_G_ = int32_t(0x83498360);
	constexpr int32_t str_TXT_820B8748_B_ = int32_t(0x820B8748);
	constexpr int32_t Destroy_TXT_83498360_G__address = int32_t(0x832A2B20);
	if (!UseLiftedCode(143, 0x8324E600)) { __imp__sub_8324E600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E600);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498360_G_, str_TXT_820B8748_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498360_G__address);
}
PROMOTED_ENTRY(143, sub_8324E600, 0x8324E600) { ctx.r3.u64 = Construct_TXT_83498360_G_(ctx, base); }

uint64_t Construct_TXT_83498368_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498368_G_ = int32_t(0x83498368);
	constexpr int32_t str_TXT_820B876C_B_ = int32_t(0x820B876C);
	constexpr int32_t Destroy_TXT_83498368_G__address = int32_t(0x832A2B30);
	if (!UseLiftedCode(143, 0x8324E678)) { __imp__sub_8324E678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E678);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498368_G_, str_TXT_820B876C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498368_G__address);
}
PROMOTED_ENTRY(143, sub_8324E678, 0x8324E678) { ctx.r3.u64 = Construct_TXT_83498368_G_(ctx, base); }

uint64_t Construct_TXT_8349836C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349836C_G_ = int32_t(0x8349836C);
	constexpr int32_t str_TXT_820B9268_B_ = int32_t(0x820B9268);
	constexpr int32_t Destroy_TXT_8349836C_G__address = int32_t(0x832A2B40);
	if (!UseLiftedCode(143, 0x8324E6B8)) { __imp__sub_8324E6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E6B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349836C_G_, str_TXT_820B9268_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349836C_G__address);
}
PROMOTED_ENTRY(143, sub_8324E6B8, 0x8324E6B8) { ctx.r3.u64 = Construct_TXT_8349836C_G_(ctx, base); }

uint64_t Construct_TXT_83498370_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498370_G_ = int32_t(0x83498370);
	constexpr int32_t str_TXT_820B9284_B_ = int32_t(0x820B9284);
	constexpr int32_t Destroy_TXT_83498370_G__address = int32_t(0x832A2B50);
	if (!UseLiftedCode(143, 0x8324E6F8)) { __imp__sub_8324E6F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E6F8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498370_G_, str_TXT_820B9284_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498370_G__address);
}
PROMOTED_ENTRY(143, sub_8324E6F8, 0x8324E6F8) { ctx.r3.u64 = Construct_TXT_83498370_G_(ctx, base); }

uint64_t Construct_TXT_83498378_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498378_G_ = int32_t(0x83498378);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498378_G__address = int32_t(0x832A2B60);
	if (!UseLiftedCode(143, 0x8324E770)) { __imp__sub_8324E770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498378_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498378_G__address);
}
PROMOTED_ENTRY(143, sub_8324E770, 0x8324E770) { ctx.r3.u64 = Construct_TXT_83498378_G_(ctx, base); }

uint64_t Construct_TXT_8349837C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349837C_G_ = int32_t(0x8349837C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349837C_G__address = int32_t(0x832A2B70);
	if (!UseLiftedCode(143, 0x8324E7B0)) { __imp__sub_8324E7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349837C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349837C_G__address);
}
PROMOTED_ENTRY(143, sub_8324E7B0, 0x8324E7B0) { ctx.r3.u64 = Construct_TXT_8349837C_G_(ctx, base); }

uint64_t Construct_TXT_83498380_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498380_G_ = int32_t(0x83498380);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498380_G__address = int32_t(0x832A2B80);
	if (!UseLiftedCode(143, 0x8324E7F0)) { __imp__sub_8324E7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E7F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498380_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498380_G__address);
}
PROMOTED_ENTRY(143, sub_8324E7F0, 0x8324E7F0) { ctx.r3.u64 = Construct_TXT_83498380_G_(ctx, base); }

uint64_t Construct_TXT_834983A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983A4_G_ = int32_t(0x834983A4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834983A4_G__address = int32_t(0x832A2B90);
	if (!UseLiftedCode(143, 0x8324E9F0)) { __imp__sub_8324E9F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324E9F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983A4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983A4_G__address);
}
PROMOTED_ENTRY(143, sub_8324E9F0, 0x8324E9F0) { ctx.r3.u64 = Construct_TXT_834983A4_G_(ctx, base); }

uint64_t Construct_TXT_834983A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983A8_G_ = int32_t(0x834983A8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834983A8_G__address = int32_t(0x832A2BA0);
	if (!UseLiftedCode(143, 0x8324EA30)) { __imp__sub_8324EA30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EA30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983A8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983A8_G__address);
}
PROMOTED_ENTRY(143, sub_8324EA30, 0x8324EA30) { ctx.r3.u64 = Construct_TXT_834983A8_G_(ctx, base); }

uint64_t Construct_TXT_834983AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983AC_G_ = int32_t(0x834983AC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834983AC_G__address = int32_t(0x832A2BB0);
	if (!UseLiftedCode(143, 0x8324EA70)) { __imp__sub_8324EA70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EA70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983AC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983AC_G__address);
}
PROMOTED_ENTRY(143, sub_8324EA70, 0x8324EA70) { ctx.r3.u64 = Construct_TXT_834983AC_G_(ctx, base); }

uint64_t Construct_TXT_834983B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983B0_G_ = int32_t(0x834983B0);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834983B0_G__address = int32_t(0x832A2BC0);
	if (!UseLiftedCode(143, 0x8324EAB0)) { __imp__sub_8324EAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EAB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983B0_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983B0_G__address);
}
PROMOTED_ENTRY(143, sub_8324EAB0, 0x8324EAB0) { ctx.r3.u64 = Construct_TXT_834983B0_G_(ctx, base); }

uint64_t Construct_TXT_834983D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983D8_G_ = int32_t(0x834983D8);
	constexpr int32_t str_TXT_820B9634_B_ = int32_t(0x820B9634);
	constexpr int32_t Destroy_TXT_834983D8_G__address = int32_t(0x832A2BD0);
	if (!UseLiftedCode(143, 0x8324ECE8)) { __imp__sub_8324ECE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ECE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983D8_G_, str_TXT_820B9634_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983D8_G__address);
}
PROMOTED_ENTRY(143, sub_8324ECE8, 0x8324ECE8) { ctx.r3.u64 = Construct_TXT_834983D8_G_(ctx, base); }

uint64_t Construct_TXT_834983DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983DC_G_ = int32_t(0x834983DC);
	constexpr int32_t str_TXT_820B9650_B_ = int32_t(0x820B9650);
	constexpr int32_t Destroy_TXT_834983DC_G__address = int32_t(0x832A2BE0);
	if (!UseLiftedCode(143, 0x8324ED28)) { __imp__sub_8324ED28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ED28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983DC_G_, str_TXT_820B9650_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983DC_G__address);
}
PROMOTED_ENTRY(143, sub_8324ED28, 0x8324ED28) { ctx.r3.u64 = Construct_TXT_834983DC_G_(ctx, base); }

uint64_t Construct_TXT_834983E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983E0_G_ = int32_t(0x834983E0);
	constexpr int32_t str_TXT_820B966C_B_ = int32_t(0x820B966C);
	constexpr int32_t Destroy_TXT_834983E0_G__address = int32_t(0x832A2BF0);
	if (!UseLiftedCode(143, 0x8324ED68)) { __imp__sub_8324ED68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324ED68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E0_G_, str_TXT_820B966C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983E0_G__address);
}
PROMOTED_ENTRY(143, sub_8324ED68, 0x8324ED68) { ctx.r3.u64 = Construct_TXT_834983E0_G_(ctx, base); }

uint64_t Construct_TXT_834983E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983E4_G_ = int32_t(0x834983E4);
	constexpr int32_t str_TXT_820B9688_B_ = int32_t(0x820B9688);
	constexpr int32_t Destroy_TXT_834983E4_G__address = int32_t(0x832A2C00);
	if (!UseLiftedCode(143, 0x8324EDA8)) { __imp__sub_8324EDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EDA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E4_G_, str_TXT_820B9688_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983E4_G__address);
}
PROMOTED_ENTRY(143, sub_8324EDA8, 0x8324EDA8) { ctx.r3.u64 = Construct_TXT_834983E4_G_(ctx, base); }

uint64_t Construct_TXT_834983E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983E8_G_ = int32_t(0x834983E8);
	constexpr int32_t str_TXT_820B96A4_B_ = int32_t(0x820B96A4);
	constexpr int32_t Destroy_TXT_834983E8_G__address = int32_t(0x832A2C10);
	if (!UseLiftedCode(143, 0x8324EDE8)) { __imp__sub_8324EDE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EDE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983E8_G_, str_TXT_820B96A4_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983E8_G__address);
}
PROMOTED_ENTRY(143, sub_8324EDE8, 0x8324EDE8) { ctx.r3.u64 = Construct_TXT_834983E8_G_(ctx, base); }

uint64_t Construct_TXT_834983EC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983EC_G_ = int32_t(0x834983EC);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834983EC_G__address = int32_t(0x832A2C20);
	if (!UseLiftedCode(143, 0x8324EE28)) { __imp__sub_8324EE28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EE28);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983EC_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983EC_G__address);
}
PROMOTED_ENTRY(143, sub_8324EE28, 0x8324EE28) { ctx.r3.u64 = Construct_TXT_834983EC_G_(ctx, base); }

uint64_t Construct_TXT_834983F0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983F0_G_ = int32_t(0x834983F0);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834983F0_G__address = int32_t(0x832A2C30);
	if (!UseLiftedCode(143, 0x8324EE68)) { __imp__sub_8324EE68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EE68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F0_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983F0_G__address);
}
PROMOTED_ENTRY(143, sub_8324EE68, 0x8324EE68) { ctx.r3.u64 = Construct_TXT_834983F0_G_(ctx, base); }

uint64_t Construct_TXT_834983F4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983F4_G_ = int32_t(0x834983F4);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834983F4_G__address = int32_t(0x832A2C40);
	if (!UseLiftedCode(143, 0x8324EEA8)) { __imp__sub_8324EEA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EEA8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F4_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983F4_G__address);
}
PROMOTED_ENTRY(143, sub_8324EEA8, 0x8324EEA8) { ctx.r3.u64 = Construct_TXT_834983F4_G_(ctx, base); }

uint64_t Construct_TXT_834983F8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834983F8_G_ = int32_t(0x834983F8);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834983F8_G__address = int32_t(0x832A2CA8);
	if (!UseLiftedCode(143, 0x8324EEE8)) { __imp__sub_8324EEE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324EEE8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834983F8_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834983F8_G__address);
}
PROMOTED_ENTRY(143, sub_8324EEE8, 0x8324EEE8) { ctx.r3.u64 = Construct_TXT_834983F8_G_(ctx, base); }

uint64_t Construct_TXT_834984D0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984D0_G_ = int32_t(0x834984D0);
	constexpr int32_t str_TXT_820A047C_B_ = int32_t(0x820A047C);
	constexpr int32_t Destroy_TXT_834984D0_G__address = int32_t(0x832A2D88);
	if (!UseLiftedCode(143, 0x8324F6B0)) { __imp__sub_8324F6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F6B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D0_G_, str_TXT_820A047C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984D0_G__address);
}
PROMOTED_ENTRY(143, sub_8324F6B0, 0x8324F6B0) { ctx.r3.u64 = Construct_TXT_834984D0_G_(ctx, base); }

uint64_t Construct_TXT_834984D4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984D4_G_ = int32_t(0x834984D4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834984D4_G__address = int32_t(0x832A2D98);
	if (!UseLiftedCode(143, 0x8324F6F0)) { __imp__sub_8324F6F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F6F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984D4_G__address);
}
PROMOTED_ENTRY(143, sub_8324F6F0, 0x8324F6F0) { ctx.r3.u64 = Construct_TXT_834984D4_G_(ctx, base); }

uint64_t Construct_TXT_834984D8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984D8_G_ = int32_t(0x834984D8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834984D8_G__address = int32_t(0x832A2DA8);
	if (!UseLiftedCode(143, 0x8324F730)) { __imp__sub_8324F730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F730);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984D8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984D8_G__address);
}
PROMOTED_ENTRY(143, sub_8324F730, 0x8324F730) { ctx.r3.u64 = Construct_TXT_834984D8_G_(ctx, base); }

uint64_t Construct_TXT_834984DC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984DC_G_ = int32_t(0x834984DC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834984DC_G__address = int32_t(0x832A2DB8);
	if (!UseLiftedCode(143, 0x8324F770)) { __imp__sub_8324F770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F770);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984DC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984DC_G__address);
}
PROMOTED_ENTRY(143, sub_8324F770, 0x8324F770) { ctx.r3.u64 = Construct_TXT_834984DC_G_(ctx, base); }

uint64_t Construct_TXT_834984E0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984E0_G_ = int32_t(0x834984E0);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834984E0_G__address = int32_t(0x832A2DC8);
	if (!UseLiftedCode(143, 0x8324F7B0)) { __imp__sub_8324F7B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F7B0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E0_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984E0_G__address);
}
PROMOTED_ENTRY(143, sub_8324F7B0, 0x8324F7B0) { ctx.r3.u64 = Construct_TXT_834984E0_G_(ctx, base); }

uint64_t Construct_TXT_834984E4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984E4_G_ = int32_t(0x834984E4);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834984E4_G__address = int32_t(0x832A2DD8);
	if (!UseLiftedCode(143, 0x8324F7F0)) { __imp__sub_8324F7F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F7F0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E4_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984E4_G__address);
}
PROMOTED_ENTRY(143, sub_8324F7F0, 0x8324F7F0) { ctx.r3.u64 = Construct_TXT_834984E4_G_(ctx, base); }

uint64_t Construct_TXT_834984E8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834984E8_G_ = int32_t(0x834984E8);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834984E8_G__address = int32_t(0x832A2DE8);
	if (!UseLiftedCode(143, 0x8324F830)) { __imp__sub_8324F830(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F830);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834984E8_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834984E8_G__address);
}
PROMOTED_ENTRY(143, sub_8324F830, 0x8324F830) { ctx.r3.u64 = Construct_TXT_834984E8_G_(ctx, base); }

uint64_t n_sub_8324F8E0(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A2E40_address = int32_t(0x832A2E40);
	if (!UseLiftedCode(143, 0x8324F8E0)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324F8E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F8E0);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A2E40_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324F8E0, 0x8324F8E0) { ctx.r3.u64 = n_sub_8324F8E0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324F8F0(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A2E88_address = int32_t(0x832A2E88);
	if (!UseLiftedCode(143, 0x8324F8F0)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324F8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F8F0);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A2E88_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324F8F0, 0x8324F8F0) { ctx.r3.u64 = n_sub_8324F8F0(ctx, base, ctx.r8.u64); }

uint64_t n_sub_8324F900(CpuState& ctx, uint8_t* base, uint64_t callbackArgument) {
	constexpr int32_t g_832A0000 = int32_t(0x832A0000);
	constexpr int32_t n_sub_832A2E98_address = int32_t(0x832A2E98);
	if (!UseLiftedCode(143, 0x8324F900)) { ctx.r8.u64 = callbackArgument; __imp__sub_8324F900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F900);
	ctx.r11.s64 = g_832A0000;
	return n_sub_82CA3700(ctx, base, n_sub_832A2E98_address, callbackArgument);
}
PROMOTED_ENTRY(143, sub_8324F900, 0x8324F900) { ctx.r3.u64 = n_sub_8324F900(ctx, base, ctx.r8.u64); }

uint64_t Construct_TXT_83498548_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498548_G_ = int32_t(0x83498548);
	constexpr int32_t str_TXT_82000A84_B_ = int32_t(0x82000A84);
	constexpr int32_t Destroy_TXT_83498548_G__address = int32_t(0x832A2F10);
	if (!UseLiftedCode(143, 0x8324F910)) { __imp__sub_8324F910(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F910);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498548_G_, str_TXT_82000A84_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498548_G__address);
}
PROMOTED_ENTRY(143, sub_8324F910, 0x8324F910) { ctx.r3.u64 = Construct_TXT_83498548_G_(ctx, base); }

uint64_t Construct_TXT_8349854C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349854C_G_ = int32_t(0x8349854C);
	constexpr int32_t str_TXT_82000E10_B_ = int32_t(0x82000E10);
	constexpr int32_t Destroy_TXT_8349854C_G__address = int32_t(0x832A2F20);
	if (!UseLiftedCode(143, 0x8324F950)) { __imp__sub_8324F950(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F950);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349854C_G_, str_TXT_82000E10_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349854C_G__address);
}
PROMOTED_ENTRY(143, sub_8324F950, 0x8324F950) { ctx.r3.u64 = Construct_TXT_8349854C_G_(ctx, base); }

uint64_t Construct_TXT_83498550_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498550_G_ = int32_t(0x83498550);
	constexpr int32_t str_TXT_820BC3E0_B_ = int32_t(0x820BC3E0);
	constexpr int32_t Destroy_TXT_83498550_G__address = int32_t(0x832A2F30);
	if (!UseLiftedCode(143, 0x8324F990)) { __imp__sub_8324F990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F990);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498550_G_, str_TXT_820BC3E0_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498550_G__address);
}
PROMOTED_ENTRY(143, sub_8324F990, 0x8324F990) { ctx.r3.u64 = Construct_TXT_83498550_G_(ctx, base); }

uint64_t Construct_TXT_83498554_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498554_G_ = int32_t(0x83498554);
	constexpr int32_t str_TXT_82000E50_B_ = int32_t(0x82000E50);
	constexpr int32_t Destroy_TXT_83498554_G__address = int32_t(0x832A2F40);
	if (!UseLiftedCode(143, 0x8324F9D0)) { __imp__sub_8324F9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324F9D0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498554_G_, str_TXT_82000E50_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498554_G__address);
}
PROMOTED_ENTRY(143, sub_8324F9D0, 0x8324F9D0) { ctx.r3.u64 = Construct_TXT_83498554_G_(ctx, base); }

uint64_t Construct_TXT_83498568_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498568_G_ = int32_t(0x83498568);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498568_G__address = int32_t(0x832A2F60);
	if (!UseLiftedCode(143, 0x8324FA78)) { __imp__sub_8324FA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FA78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498568_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498568_G__address);
}
PROMOTED_ENTRY(143, sub_8324FA78, 0x8324FA78) { ctx.r3.u64 = Construct_TXT_83498568_G_(ctx, base); }

uint64_t Construct_TXT_8349856C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349856C_G_ = int32_t(0x8349856C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349856C_G__address = int32_t(0x832A2F70);
	if (!UseLiftedCode(143, 0x8324FAB8)) { __imp__sub_8324FAB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FAB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349856C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349856C_G__address);
}
PROMOTED_ENTRY(143, sub_8324FAB8, 0x8324FAB8) { ctx.r3.u64 = Construct_TXT_8349856C_G_(ctx, base); }

uint64_t Construct_TXT_83498570_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498570_G_ = int32_t(0x83498570);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498570_G__address = int32_t(0x832A2F80);
	if (!UseLiftedCode(143, 0x8324FAF8)) { __imp__sub_8324FAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FAF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498570_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498570_G__address);
}
PROMOTED_ENTRY(143, sub_8324FAF8, 0x8324FAF8) { ctx.r3.u64 = Construct_TXT_83498570_G_(ctx, base); }

uint64_t Construct_TXT_83498574_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498574_G_ = int32_t(0x83498574);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498574_G__address = int32_t(0x832A2F90);
	if (!UseLiftedCode(143, 0x8324FB38)) { __imp__sub_8324FB38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FB38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498574_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498574_G__address);
}
PROMOTED_ENTRY(143, sub_8324FB38, 0x8324FB38) { ctx.r3.u64 = Construct_TXT_83498574_G_(ctx, base); }

uint64_t Construct_TXT_83498578_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498578_G_ = int32_t(0x83498578);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498578_G__address = int32_t(0x832A2FA0);
	if (!UseLiftedCode(143, 0x8324FB78)) { __imp__sub_8324FB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FB78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498578_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498578_G__address);
}
PROMOTED_ENTRY(143, sub_8324FB78, 0x8324FB78) { ctx.r3.u64 = Construct_TXT_83498578_G_(ctx, base); }

uint64_t Construct_TXT_8349857C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349857C_G_ = int32_t(0x8349857C);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_8349857C_G__address = int32_t(0x832A2FB0);
	if (!UseLiftedCode(143, 0x8324FBB8)) { __imp__sub_8324FBB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FBB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349857C_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349857C_G__address);
}
PROMOTED_ENTRY(143, sub_8324FBB8, 0x8324FBB8) { ctx.r3.u64 = Construct_TXT_8349857C_G_(ctx, base); }

uint64_t Construct_TXT_83498580_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498580_G_ = int32_t(0x83498580);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498580_G__address = int32_t(0x832A2FD0);
	if (!UseLiftedCode(143, 0x8324FBF8)) { __imp__sub_8324FBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FBF8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498580_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498580_G__address);
}
PROMOTED_ENTRY(143, sub_8324FBF8, 0x8324FBF8) { ctx.r3.u64 = Construct_TXT_83498580_G_(ctx, base); }

uint64_t Construct_TXT_83498584_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498584_G_ = int32_t(0x83498584);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_83498584_G__address = int32_t(0x832A2FE0);
	if (!UseLiftedCode(143, 0x8324FC38)) { __imp__sub_8324FC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FC38);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498584_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498584_G__address);
}
PROMOTED_ENTRY(143, sub_8324FC38, 0x8324FC38) { ctx.r3.u64 = Construct_TXT_83498584_G_(ctx, base); }

uint64_t Construct_TXT_83498588_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498588_G_ = int32_t(0x83498588);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_83498588_G__address = int32_t(0x832A2FF0);
	if (!UseLiftedCode(143, 0x8324FC78)) { __imp__sub_8324FC78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FC78);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498588_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498588_G__address);
}
PROMOTED_ENTRY(143, sub_8324FC78, 0x8324FC78) { ctx.r3.u64 = Construct_TXT_83498588_G_(ctx, base); }

uint64_t Construct_TXT_83498598_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_83498598_G_ = int32_t(0x83498598);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_83498598_G__address = int32_t(0x832A3048);
	if (!UseLiftedCode(143, 0x8324FD70)) { __imp__sub_8324FD70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FD70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_83498598_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_83498598_G__address);
}
PROMOTED_ENTRY(143, sub_8324FD70, 0x8324FD70) { ctx.r3.u64 = Construct_TXT_83498598_G_(ctx, base); }

uint64_t Construct_TXT_8349859C_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_8349859C_G_ = int32_t(0x8349859C);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_8349859C_G__address = int32_t(0x832A3058);
	if (!UseLiftedCode(143, 0x8324FDB0)) { __imp__sub_8324FDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FDB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_8349859C_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_8349859C_G__address);
}
PROMOTED_ENTRY(143, sub_8324FDB0, 0x8324FDB0) { ctx.r3.u64 = Construct_TXT_8349859C_G_(ctx, base); }

uint64_t Construct_TXT_834985A0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985A0_G_ = int32_t(0x834985A0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834985A0_G__address = int32_t(0x832A3068);
	if (!UseLiftedCode(143, 0x8324FDF0)) { __imp__sub_8324FDF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FDF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985A0_G__address);
}
PROMOTED_ENTRY(143, sub_8324FDF0, 0x8324FDF0) { ctx.r3.u64 = Construct_TXT_834985A0_G_(ctx, base); }

uint64_t Construct_TXT_834985A4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985A4_G_ = int32_t(0x834985A4);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834985A4_G__address = int32_t(0x832A3078);
	if (!UseLiftedCode(143, 0x8324FE30)) { __imp__sub_8324FE30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FE30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A4_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985A4_G__address);
}
PROMOTED_ENTRY(143, sub_8324FE30, 0x8324FE30) { ctx.r3.u64 = Construct_TXT_834985A4_G_(ctx, base); }

uint64_t Construct_TXT_834985A8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985A8_G_ = int32_t(0x834985A8);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834985A8_G__address = int32_t(0x832A3088);
	if (!UseLiftedCode(143, 0x8324FE70)) { __imp__sub_8324FE70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FE70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985A8_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985A8_G__address);
}
PROMOTED_ENTRY(143, sub_8324FE70, 0x8324FE70) { ctx.r3.u64 = Construct_TXT_834985A8_G_(ctx, base); }

uint64_t Construct_TXT_834985AC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985AC_G_ = int32_t(0x834985AC);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834985AC_G__address = int32_t(0x832A3098);
	if (!UseLiftedCode(143, 0x8324FEB0)) { __imp__sub_8324FEB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FEB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985AC_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985AC_G__address);
}
PROMOTED_ENTRY(143, sub_8324FEB0, 0x8324FEB0) { ctx.r3.u64 = Construct_TXT_834985AC_G_(ctx, base); }

uint64_t Construct_TXT_834985B0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985B0_G_ = int32_t(0x834985B0);
	constexpr int32_t str_TXT_820BD078_B_ = int32_t(0x820BD078);
	constexpr int32_t Destroy_TXT_834985B0_G__address = int32_t(0x832A30A8);
	if (!UseLiftedCode(143, 0x8324FEF0)) { __imp__sub_8324FEF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FEF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B0_G_, str_TXT_820BD078_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985B0_G__address);
}
PROMOTED_ENTRY(143, sub_8324FEF0, 0x8324FEF0) { ctx.r3.u64 = Construct_TXT_834985B0_G_(ctx, base); }

uint64_t Construct_TXT_834985B4_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985B4_G_ = int32_t(0x834985B4);
	constexpr int32_t str_TXT_820BD084_B_ = int32_t(0x820BD084);
	constexpr int32_t Destroy_TXT_834985B4_G__address = int32_t(0x832A30B8);
	if (!UseLiftedCode(143, 0x8324FF30)) { __imp__sub_8324FF30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FF30);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B4_G_, str_TXT_820BD084_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985B4_G__address);
}
PROMOTED_ENTRY(143, sub_8324FF30, 0x8324FF30) { ctx.r3.u64 = Construct_TXT_834985B4_G_(ctx, base); }

uint64_t Construct_TXT_834985B8_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985B8_G_ = int32_t(0x834985B8);
	constexpr int32_t str_TXT_820A1900_B_ = int32_t(0x820A1900);
	constexpr int32_t Destroy_TXT_834985B8_G__address = int32_t(0x832A30C8);
	if (!UseLiftedCode(143, 0x8324FF70)) { __imp__sub_8324FF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FF70);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985B8_G_, str_TXT_820A1900_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985B8_G__address);
}
PROMOTED_ENTRY(143, sub_8324FF70, 0x8324FF70) { ctx.r3.u64 = Construct_TXT_834985B8_G_(ctx, base); }

uint64_t Construct_TXT_834985BC_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985BC_G_ = int32_t(0x834985BC);
	constexpr int32_t str_TXT_820A1908_B_ = int32_t(0x820A1908);
	constexpr int32_t Destroy_TXT_834985BC_G__address = int32_t(0x832A30D8);
	if (!UseLiftedCode(143, 0x8324FFB0)) { __imp__sub_8324FFB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FFB0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985BC_G_, str_TXT_820A1908_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985BC_G__address);
}
PROMOTED_ENTRY(143, sub_8324FFB0, 0x8324FFB0) { ctx.r3.u64 = Construct_TXT_834985BC_G_(ctx, base); }

uint64_t Construct_TXT_834985C0_G_(CpuState& ctx, uint8_t* base) {
	constexpr int32_t TXT_834985C0_G_ = int32_t(0x834985C0);
	constexpr int32_t str_TXT_820A191C_B_ = int32_t(0x820A191C);
	constexpr int32_t Destroy_TXT_834985C0_G__address = int32_t(0x832A30E8);
	if (!UseLiftedCode(143, 0x8324FFF0)) { __imp__sub_8324FFF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8324FFF0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, TXT_834985C0_G_, str_TXT_820A191C_B_, -1);
	return RegisterAtExit(ctx, base, Destroy_TXT_834985C0_G__address);
}
PROMOTED_ENTRY(143, sub_8324FFF0, 0x8324FFF0) { ctx.r3.u64 = Construct_TXT_834985C0_G_(ctx, base); }
