// CGameHostGameImpl (vtable 0x8203CE6C): methods of the class as readable C++.
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

uint64_t CGameHostGameImpl_AddRef(CpuState& ctx, uint8_t* base, uint32_t self) {
	if (!UseLiftedCode(115, 0x82EEF3F0)) { ctx.r3.u64 = self; __imp__sub_82EEF3F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF3F0);
	uint32_t stack = ctx.r1.u32;
	STORE32(stack + 20, self);
	uint32_t refCountAddr = self + 8;
	uint32_t oldValue, newValue;
	do {
		oldValue = LOAD32(refCountAddr);
		newValue = oldValue + 1;
	} while (!__sync_bool_compare_and_swap(
		reinterpret_cast<uint32_t*>(RAW(refCountAddr)),
		__builtin_bswap32(oldValue),
		__builtin_bswap32(newValue)));
	STORE32(stack - 16, newValue);
	return LOAD32(stack - 16);
}
PROMOTED_ENTRY(115, sub_82EEF3F0, 0x82EEF3F0) { ctx.r3.u64 = CGameHostGameImpl_AddRef(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_Release(CpuState& ctx, uint8_t* base, uint32_t interfacePtr, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	constexpr int32_t str_TXT_8203C32C_B_ = int32_t(0x8203C32C);
	constexpr int32_t str_TXT_8203CF18_B_ = int32_t(0x8203CF18);
	constexpr uint32_t assertFile = 0x8203CF2C;
	constexpr uint32_t countAssertSkip_address = 0x83358DAD;
	constexpr uint32_t busyAssertSkip_address = 0x83358DAC;
	if (!UseLiftedCode(115, 0x82EEF430)) { ctx.r3.u64 = interfacePtr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; __imp__sub_82EEF430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF430);
	uint32_t stack = ctx.r1.u64;
	uint32_t lockedMsr = ctx.r13.u64;
	stack = PushStackFrame(base, stack, 144);
	STORE32(stack + 164, interfacePtr);

	// the count must be positive (reported unless the byte at countAssertSkip_address is set)
	if ((int32_t)LOAD32(LOAD32(stack + 164) + 8) <= 0 && LOAD8(countAssertSkip_address) == 0) {
		ctx.r1.u64 = stack;
		uint64_t assertInfo = AssertInfo_Init(ctx, base, stack + 88, assertFile, 25, str_TXT_8203C32C_B_);
		uint32_t assertResult = Assert_ReportFailure(ctx, base, assertInfo, countAssertSkip_address, forwardedArg1, forwardedArg2, forwardedArg3, ctx.r10.u64);
		forwardedArg1 = ctx.r7.u64;
		forwardedArg2 = ctx.r8.u64;
		if ((assertResult & 0xFF) == 0) ppc_trap(ctx, base, 22);
	}

	uint32_t refCountAddr = LOAD32(stack + 164) + 8;
	uint64_t previousMsr{};
	uint64_t newRefCount{};
	bool stored{};
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		previousMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = lockedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
		newRefCount = uint64_t(__builtin_bswap32(ctx.reserved.u32)) - 1;
		stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = (uint32_t)previousMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);
	STORE32(stack + 116, uint32_t(newRefCount));
	STORE32(stack + 80, LOAD32(stack + 116));

	if ((int32_t)LOAD32(stack + 80) == 0) {
		// the byte at +12 is set while a call through the interface runs (CGameHostGameImpl_ActivateShimMenuThunk,
		// n_sub_82EEF738): it must be clear when the last reference goes
		if (LOAD8(LOAD32(stack + 164) + 12) != 0 && LOAD8(busyAssertSkip_address) == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = newRefCount;
			uint64_t assertInfo = AssertInfo_Init(ctx, base, stack + 104, assertFile, 29, str_TXT_8203CF18_B_);
			uint32_t assertResult = Assert_ReportFailure(ctx, base, assertInfo, busyAssertSkip_address, forwardedArg1, forwardedArg2, previousMsr, ctx.r10.u64);
			forwardedArg1 = ctx.r7.u64;
			forwardedArg2 = ctx.r8.u64;
			previousMsr = ctx.r9.u64;
			newRefCount = ctx.r10.u64;
			if ((assertResult & 0xFF) == 0) ppc_trap(ctx, base, 22);
		}

		uint32_t owner = LOAD32(LOAD32(stack + 164) + 4);
		STORE32(stack + 84, owner);
		uint32_t gameImpl = LOAD32(stack + 164) - 1272;
		ctx.r1.u64 = stack;
		ctx.r10.u64 = newRefCount;
		CGameHostGameImpl_DetachCurrentGame(ctx, base, owner, gameImpl, forwardedArg1, forwardedArg2, previousMsr);

		uint32_t heldOwner = LOAD32(stack + 84);
		uint32_t ownerVtable = LOAD32(heldOwner);
		uint32_t ownerMethod = LOAD32(ownerVtable + 4);
		ctx.r3.u64 = heldOwner;
		REX_CALL_INDIRECT_FUNC(ownerMethod);
	}

	uint32_t referencesLeft = LOAD32(stack + 80);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return referencesLeft;
}
PROMOTED_ENTRY(115, sub_82EEF430, 0x82EEF430) { ctx.r3.u64 = CGameHostGameImpl_Release(ctx, base, ctx.r3.u32, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t n_sub_82EEF588(CpuState& ctx, uint8_t* base, uint32_t interfacePtr, uint32_t forwardedArg1, uint32_t forwardedArg2, uint32_t forwardedArg3, uint64_t forwardedArg4, uint64_t forwardedArg5, uint64_t forwardedArg6, double forwardedFloat1, double forwardedFloat2) {
	if (!UseLiftedCode(115, 0x82EEF588)) { ctx.r3.u64 = interfacePtr; ctx.r4.u64 = forwardedArg1; ctx.r5.u64 = forwardedArg2; ctx.r6.u64 = forwardedArg3; ctx.r7.u64 = forwardedArg4; ctx.r8.u64 = forwardedArg5; ctx.r9.u64 = forwardedArg6; ctx.f1.f64 = forwardedFloat1; ctx.f2.f64 = forwardedFloat2; __imp__sub_82EEF588(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF588);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	STORE32(stack + 124, forwardedArg1);
	STORE32(stack + 132, forwardedArg2);
	STORE32(stack + 140, forwardedArg3);
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 148, float(forwardedFloat1));
	STORE_F32(stack + 156, float(forwardedFloat2));

	// the implementation gets both floats rounded to single precision, and the CGameHostGameImpl that holds the
	// interface at +1272
	double singleFloat1 = LOAD_F32(stack + 148);
	double singleFloat2 = LOAD_F32(stack + 156);
	uint32_t gameImpl = interfacePtr - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82EEBA00(ctx, base, gameImpl, forwardedArg1, forwardedArg2, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, singleFloat1, singleFloat2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF588, 0x82EEF588) { ctx.r3.u64 = n_sub_82EEF588(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64, ctx.f1.f64, ctx.f2.f64); }

// sub_82EEF5E0  [44 bytes]
uint64_t n_sub_82EEF5E0(CpuState& ctx, uint8_t* base, uint32_t objectAddress) {
	if (!UseLiftedCode(115, 0x82EEF5E0)) { ctx.r3.u64 = objectAddress; __imp__sub_82EEF5E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF5E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, objectAddress);
	uint64_t ownerAddress = (uint64_t)objectAddress - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82EEF610(ctx, base, ownerAddress);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF5E0, 0x82EEF5E0) { ctx.r3.u64 = n_sub_82EEF5E0(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_UpdatePadAfterPauseThunk(CpuState& ctx, uint8_t* base, uint32_t interfacePtr) {
	if (!UseLiftedCode(115, 0x82EEF640)) { ctx.r3.u64 = interfacePtr; __imp__sub_82EEF640(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF640);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	uint64_t adjustedObject = (int64_t)(uint64_t)LOAD32(stack + 116) - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = CGameHostGameImpl_UpdatePadAfterPause(ctx, base, adjustedObject);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF640, 0x82EEF640) { ctx.r3.u64 = CGameHostGameImpl_UpdatePadAfterPauseThunk(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_EndGameThunk(CpuState& ctx, uint8_t* base, uint32_t interfacePtr, uint32_t endGameFlag) {
	if (!UseLiftedCode(115, 0x82EEF670)) { ctx.r3.u64 = interfacePtr; ctx.r4.u64 = endGameFlag; __imp__sub_82EEF670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF670);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	STORE8(stack + 127, (uint8_t)endGameFlag);
	uint32_t byteArg = LOAD8(stack + 127);
	uint64_t targetAddress = (uint64_t)LOAD32(stack + 116) - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = CGameHostGameImpl_EndGame(ctx, base, targetAddress, byteArg);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF670, 0x82EEF670) { ctx.r3.u64 = CGameHostGameImpl_EndGameThunk(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CGameHostGameImpl_ActivateShimMenuThunk(CpuState& ctx, uint8_t* base, uint32_t interfacePtr, uint64_t forwardedArg1, uint64_t forwardedArg2, uint64_t forwardedArg3) {
	if (!UseLiftedCode(115, 0x82EEF6A8)) { ctx.r3.u64 = interfacePtr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; ctx.r9.u64 = forwardedArg3; __imp__sub_82EEF6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF6A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);

	// the interface (at +1272 of the CGameHostGameImpl) holds a reference, and has its byte at +12 set, while
	// the implementation runs; slots 0 and 1 of its vtable are AddRef and Release
	uint32_t self = LOAD32(stack + 116);
	uint64_t gameImpl = uint64_t(self) - 1272;
	uint32_t vtable = LOAD32(self);
	uint32_t addRef = LOAD32(vtable);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = self;
	ctx.r7.u64 = forwardedArg1;
	ctx.r8.u64 = forwardedArg2;
	ctx.r9.u64 = forwardedArg3;
	ctx.r10.u64 = gameImpl;
	REX_CALL_INDIRECT_FUNC(addRef);

	STORE8(LOAD32(stack + 116) + 12, 1);
	ctx.r10.u64 = 1;
	uint32_t result = CGameHostGameImpl_ActivateShimMenu(ctx, base, LOAD32(stack + 116) - 1272, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64);
	STORE32(stack + 80, result);
	STORE8(LOAD32(stack + 116) + 12, 0);

	self = LOAD32(stack + 116);
	gameImpl = uint64_t(self) - 1272;
	vtable = LOAD32(self);
	uint32_t release = LOAD32(vtable + 4);
	ctx.r3.u64 = self;
	ctx.r10.u64 = gameImpl;
	REX_CALL_INDIRECT_FUNC(release);

	result = LOAD32(stack + 80);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF6A8, 0x82EEF6A8) { ctx.r3.u64 = CGameHostGameImpl_ActivateShimMenuThunk(ctx, base, ctx.r3.u32, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

uint64_t n_sub_82EEF738(CpuState& ctx, uint8_t* base, uint32_t interfacePtr, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	if (!UseLiftedCode(115, 0x82EEF738)) { ctx.r3.u64 = interfacePtr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82EEF738(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF738);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);

	// the interface (at +1272 of the CGameHostGameImpl) holds a reference, and has its byte at +12 set, while
	// the implementation runs; slots 0 and 1 of its vtable are AddRef and Release
	uint32_t self = LOAD32(stack + 116);
	uint64_t gameImpl = uint64_t(self) - 1272;
	uint32_t vtable = LOAD32(self);
	uint32_t addRef = LOAD32(vtable);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = self;
	ctx.r7.u64 = forwardedArg1;
	ctx.r8.u64 = forwardedArg2;
	ctx.r10.u64 = gameImpl;
	REX_CALL_INDIRECT_FUNC(addRef);

	STORE8(LOAD32(stack + 116) + 12, 1);
	ctx.r10.u64 = 1;
	uint32_t result = n_sub_82EEC410(ctx, base, LOAD32(stack + 116) - 1272, ctx.r7.u64, ctx.r8.u64);
	STORE32(stack + 80, result);
	STORE8(LOAD32(stack + 116) + 12, 0);

	self = LOAD32(stack + 116);
	gameImpl = uint64_t(self) - 1272;
	vtable = LOAD32(self);
	uint32_t release = LOAD32(vtable + 4);
	ctx.r3.u64 = self;
	ctx.r10.u64 = gameImpl;
	REX_CALL_INDIRECT_FUNC(release);

	result = LOAD32(stack + 80);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF738, 0x82EEF738) { ctx.r3.u64 = n_sub_82EEF738(ctx, base, ctx.r3.u32, ctx.r7.u64, ctx.r8.u64); }

uint64_t n_sub_82EEF7C8(CpuState& ctx, uint8_t* base, uint32_t interfacePtr) {
	if (!UseLiftedCode(115, 0x82EEF7C8)) { ctx.r3.u64 = interfacePtr; __imp__sub_82EEF7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF7C8);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	// the interface lies at +1272 of the CGameHostGameImpl, which the implementation takes
	uint32_t gameImpl = interfacePtr - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82EEF7F8(ctx, base, gameImpl);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF7C8, 0x82EEF7C8) { ctx.r3.u64 = n_sub_82EEF7C8(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_StartSaveThunk(CpuState& ctx, uint8_t* base, uint32_t interfacePtr) {
	if (!UseLiftedCode(115, 0x82EEF808)) { ctx.r3.u64 = interfacePtr; __imp__sub_82EEF808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF808);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	uint64_t adjustedThis = (uint64_t)LOAD32(stack + 116) - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = CGameHostGameImpl_StartSave(ctx, base, adjustedThis);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF808, 0x82EEF808) { ctx.r3.u64 = CGameHostGameImpl_StartSaveThunk(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_EndSaveThunk(CpuState& ctx, uint8_t* base, uint32_t interfacePtr) {
	if (!UseLiftedCode(115, 0x82EEF838)) { ctx.r3.u64 = interfacePtr; __imp__sub_82EEF838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF838);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	STORE32(stack + 116, interfacePtr);
	uint64_t objectAddress = (uint64_t)LOAD32(stack + 116) - 1272;
	ctx.r1.u64 = stack;
	uint64_t result = CGameHostGameImpl_EndSave(ctx, base, objectAddress);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(115, sub_82EEF838, 0x82EEF838) { ctx.r3.u64 = CGameHostGameImpl_EndSaveThunk(ctx, base, ctx.r3.u32); }

uint64_t CGameHostGameImpl_DeletingDestructorThunk(CpuState& ctx, uint8_t* base, uint64_t secondaryBaseThis, uint64_t deleteFlags) {
	if (!UseLiftedCode(115, 0x82EEF870)) { ctx.r3.u64 = secondaryBaseThis; ctx.r4.u64 = deleteFlags; __imp__sub_82EEF870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82EEF870);
	uint64_t adjustedThis = secondaryBaseThis - 1272;
	return CGameHostGameImpl_ScalarDeletingDestructor(ctx, base, adjustedThis, deleteFlags);
}
PROMOTED_ENTRY(115, sub_82EEF870, 0x82EEF870) { ctx.r3.u64 = CGameHostGameImpl_DeletingDestructorThunk(ctx, base, ctx.r3.u64, ctx.r4.u64); }
