// CECActionManagerSimple (vtable 0x82006DF8): methods of the class as readable C++.
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

uint64_t n_sub_821DAB78(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(3, 0x821DAB78)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_821DAB78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821DAB78);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	PPCRegister callTarget{};
	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	callTarget.u64 = hasCurrentActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t hasCurrentAction = ctx.r3.u32 & 0xFF;
	// callers read r4 after the call: what the check left there, or the Find argument below
	uint64_t callerR4 = ctx.r4.u64;

	uint32_t result = 0;
	if (hasCurrentAction != 0) {
		uint32_t pCurrentAction = actionManagerSimple->m_pCurrentAction;
		uint32_t actionFn = LOAD32(LOAD32(pCurrentAction) + 36);
		callTarget.u64 = actionFn;
		ctx.r3.u64 = pCurrentAction;
		ctx.r9.u64 = hasCurrentAction;
		ctx.r10.u64 = actionFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t found = C_820F11B0_Find(ctx, base, ctx.r3.u32, 3);
		callerR4 = 3;
		if ((found & 0xFF) != 0) {
			result = 1;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(3, sub_821DAB78, 0x821DAB78) { ctx.r3.u64 = n_sub_821DAB78(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8220A618(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(5, 0x8220A618)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8220A618(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8220A618);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u64;
	PPCRegister callTarget{};
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t self = (uint32_t)actionManagerSimpleAddr;
	uint32_t currentActionSlot = self + 16;
	uint32_t previousActionSlot = self + 24;
	uint32_t sharedHandle20 = self + 32;

	uint32_t heldObject = LOAD32(sharedHandle20);
	// r5 handed to the +0x18 release: the object held at +0x20, or what the +0x20 release left in r5
	uint64_t handedR5 = heldObject;
	if (heldObject != 0) {
		// vtable slot 0x40 returns an EntityHandle for the held object into a stack temporary, which is
		// destroyed at once; then the shared handle at +0x20 is released and cleared.
		uint32_t tempHandle = stack + 88;
		uint32_t makeHandleFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 64);
		callTarget.u64 = makeHandleFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = tempHandle;
		ctx.r4.u64 = actionManagerSimpleAddr;
		ctx.r5.u64 = heldObject;
		ctx.r6.u64 = 0;
		ctx.r10.u64 = makeHandleFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		STORE32(tempHandle, uint32_t(g_820F0000 + 5732));
		// state the callee may pass on
		ctx.r8.s64 = int64_t(g_820F0000) + 5732;
		ctx.r9.s64 = g_820F0000;
		EntityHandle_Release(ctx, base, tempHandle);
		STORE32(tempHandle + 4, 0);
		SharedHandle_Release(ctx, base, sharedHandle20);
		handedR5 = ctx.r5.u64;
		STORE32(sharedHandle20, 0);
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = handedR5;
	SharedHandle_Release(ctx, base, previousActionSlot);
	STORE32(previousActionSlot, 0);

	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	callTarget.u64 = hasCurrentActionFn;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	uint32_t hasCurrentAction = (uint32_t)result & 0xFF;
	if (hasCurrentAction != 0) {
		// counted copy of the current action's shared pointer (object, reference count block)
		uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
		uint32_t refCountPtr = actionManagerSimple->m_14;
		uint32_t actionRef = stack + 80;
		STORE32(actionRef + 4, refCountPtr);
		STORE32(actionRef, currentAction);
		// r9 handed to the next call: the flag above, or the lock state the increment loop leaves
		uint32_t handedR9 = hasCurrentAction;
		if (refCountPtr != 0) {
			PPCCRRegister compare0{};
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(refCountPtr);
				uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32);
				newRefCount = (int32_t)newRefCount + 1;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountPtr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
				handedR9 = lockState;
			} while (!compare0.eq);
		}
		ctx.r9.u64 = handedR9;
		n_sub_8226B5C0(ctx, base, currentAction);
		if (currentAction == LOAD32(currentActionSlot)) {
			uint32_t actionCheckFn = LOAD32(LOAD32(currentAction) + 24);
			callTarget.u64 = actionCheckFn;
			ctx.r3.u64 = currentAction;
			ctx.r10.u64 = actionCheckFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((ctx.r3.u32 & 0xFF) != 0) {
				// the action moves from +0x10 to the slot at +0x18
				SharedPtr_Assign(ctx, base, previousActionSlot, actionRef);
				SharedHandle_Release(ctx, base, currentActionSlot);
				STORE32(currentActionSlot, 0);
				n_sub_82285D10(ctx, base, LOAD32(previousActionSlot));
			}
		}
		result = SharedHandle_Release(ctx, base, actionRef);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(5, sub_8220A618, 0x8220A618) { ctx.r3.u64 = n_sub_8220A618(ctx, base, ctx.r3.u64); }

uint64_t CECActionManagerSimple_IsActionActive(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(10, 0x82290020)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_82290020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82290020);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	callTarget.u64 = hasCurrentActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t hasCurrentAction = ctx.r3.u32 & 0xFF;

	uint32_t isActionActive = 0;
	if (hasCurrentAction != 0) {
		// the current action answers through its vtable slot 0x34
		uint32_t pCurrentAction = actionManagerSimple->m_pCurrentAction;
		uint32_t isActionActiveFn = LOAD32(LOAD32(pCurrentAction) + 52);
		callTarget.u64 = isActionActiveFn;
		ctx.r3.u64 = pCurrentAction;
		ctx.r9.u64 = hasCurrentAction;  // state the callee may pass on
		ctx.r10.u64 = isActionActiveFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((ctx.r3.u32 & 0xFF) != 0) {
			isActionActive = 1;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return isActionActive;
}
PROMOTED_ENTRY(10, sub_82290020, 0x82290020) { ctx.r3.u64 = CECActionManagerSimple_IsActionActive(ctx, base, ctx.r3.u64); }

// Returns an EntityHandle by value (r3 is the result, r4 the manager): the manager's entity with the current
// action's word at +0x3C, or an empty handle (no target, -1) when the manager has no current action.
uint64_t CECActionManagerSimple_SetAction(CpuState& ctx, uint8_t* base, uint64_t outHandleAddr, uint64_t actionManagerSimpleAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(11, 0x8229EB80)) { ctx.r3.u64 = outHandleAddr; ctx.r4.u64 = actionManagerSimpleAddr; __imp__sub_8229EB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229EB80);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* outHandle = GameObject<EntityHandle>(base, outHandleAddr);
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t entityHandleVtable = uint32_t(g_820F0000 + 5732);

	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	PPCRegister callTarget{};
	callTarget.u64 = hasCurrentActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r4.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	bool hasCurrentAction = (ctx.r3.u32 & 0xFF) != 0;

	if (hasCurrentAction) {
		uint32_t entity = actionManagerSimple->m_pEntity;
		uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
		uint32_t actionWord = LOAD32(currentAction + 60);
		outHandle->m_4 = 0u;
		outHandle->vtable = entityHandleVtable;
		// state the callee may pass on
		ctx.r8.s64 = int64_t(g_820F0000) + 5732;
		ctx.r9.u64 = 0;
		ctx.r10.s64 = g_820F0000;
		EntityHandle_SetTarget(ctx, base, outHandleAddr, entity);
		outHandle->m_8 = actionWord;
	} else {
		// copy an empty handle built on the stack, then destroy the temporary
		uint32_t tempHandle = stack + 80;
		STORE32(tempHandle + 4, 0u);
		STORE32(tempHandle, entityHandleVtable);
		STORE32(tempHandle + 8, 0xFFFFFFFFu);
		// state the callee may pass on
		ctx.r8.s64 = -1;
		EntityHandle_CopyConstruct(ctx, base, outHandleAddr, tempHandle);
		uint32_t tempWord8 = LOAD32(tempHandle + 8);
		STORE32(tempHandle, entityHandleVtable);
		outHandle->m_8 = tempWord8;
		// state the callee may pass on
		ctx.r5.u64 = tempWord8;
		ctx.r6.u64 = entityHandleVtable;
		ctx.r7.u64 = uint32_t(g_820F0000);
		EntityHandle_Release(ctx, base, tempHandle);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return outHandleAddr;
}
PROMOTED_ENTRY(11, sub_8229EB80, 0x8229EB80) { ctx.r3.u64 = CECActionManagerSimple_SetAction(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_822B7078(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(12, 0x822B7078)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_822B7078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B7078);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);

	stack = PushStackFrame(base, stack, 128);

	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	PPCRegister callTarget{};
	callTarget.u64 = hasCurrentActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	if ((result & 0xFF) != 0) {
		// The current action leaves the shared slot at +0x10 for the one at +0x18.
		uint32_t refCountPtr = actionManagerSimple->m_14;
		uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
		uint32_t currentActionSlot = (uint32_t)actionManagerSimpleAddr + 16;
		uint32_t previousActionSlot = (uint32_t)actionManagerSimpleAddr + 24;
		uint32_t actionRef = stack + 80;

		// counted copy of the current action's shared pointer (object, reference count block)
		STORE32(actionRef + 4, refCountPtr);
		STORE32(actionRef, currentAction);
		if (refCountPtr != 0) {
			PPCCRRegister compare0{};
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(refCountPtr);
				uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32);
				newRefCount = (int32_t)newRefCount + 1;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountPtr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
		}

		SharedPtr_Assign(ctx, base, previousActionSlot, actionRef);
		SharedHandle_Release(ctx, base, currentActionSlot);
		STORE32(currentActionSlot, 0u);
		n_sub_826DF838(ctx, base, currentAction);
		n_sub_82285D10(ctx, base, currentAction);
		result = SharedHandle_Release(ctx, base, actionRef);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822B7078, 0x822B7078) { ctx.r3.u64 = n_sub_822B7078(ctx, base, ctx.r3.u64); }

uint64_t CECActionManagerSimple_CanInterruptCurrentAction(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr, uint64_t priority, uint64_t forceInterrupt) {
	if (!UseLiftedCode(12, 0x822CB140)) { ctx.r3.u64 = actionManagerSimpleAddr; ctx.r4.u64 = priority; ctx.r5.u64 = forceInterrupt; __imp__sub_822CB140(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822CB140);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 112);

	int32_t requestedPriority = (int32_t)(uint32_t)priority;
	uint32_t forceFlag = (uint32_t)forceInterrupt & 0xFF;

	uint32_t hasCurrentActionFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	callTarget.u64 = hasCurrentActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r4.u64 = priority;
	ctx.r5.u64 = forceInterrupt;
	ctx.r10.u64 = hasCurrentActionFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t hasCurrentAction = ctx.r3.u32 & 0xFF;
	if (hasCurrentAction == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		ctx.r9.u64 = 0;  // callers read r9 after the call
		return 1;
	}

	uint32_t pCurrentAction = actionManagerSimple->m_pCurrentAction;
	uint32_t actionCheckFn = LOAD32(LOAD32(pCurrentAction) + 24);
	callTarget.u64 = actionCheckFn;
	ctx.r3.u64 = pCurrentAction;
	ctx.r9.u64 = hasCurrentAction;
	ctx.r10.u64 = actionCheckFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t actionAllowsInterrupt = ctx.r3.u32 & 0xFF;
	if (actionAllowsInterrupt != 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		ctx.r9.u64 = actionAllowsInterrupt;  // callers read r9 after the call
		return 1;
	}

	// the call above may have replaced the current action, so it is read again
	uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
	if (LOAD8(currentAction + 76) == 0 && LOAD8(currentAction + 77) != 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		ctx.r9.u64 = 0;  // callers read r9 after the call
		return 1;
	}

	// a current action of priority 13 can only be interrupted through the checks above
	uint32_t canInterrupt = 0;
	int32_t currentPriority = (int32_t)LOAD32(currentAction + 52);
	if (currentPriority != 13) {
		if (forceFlag != 0) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			ctx.r9.u64 = forceFlag;  // callers read r9 after the call
			return 1;
		}
		if (currentPriority < requestedPriority) {
			canInterrupt = 1;
		} else if (currentPriority == requestedPriority && (LOAD32(currentAction + 56) & 0x1) != 0) {
			canInterrupt = 1;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = 0;  // callers read r9 after the call
	return canInterrupt;
}
PROMOTED_ENTRY(12, sub_822CB140, 0x822CB140) { ctx.r3.u64 = CECActionManagerSimple_CanInterruptCurrentAction(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECActionManagerSimple_GetName(CpuState& ctx, uint8_t* base, uint64_t outNameAddr) {
	constexpr int32_t str_TXT_820A7618_B_ = int32_t(0x820A7618);
	if (!UseLiftedCode(68, 0x8297B290)) { ctx.r3.u64 = outNameAddr; __imp__sub_8297B290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297B290);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, outNameAddr, str_TXT_820A7618_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return outNameAddr;
}
PROMOTED_ENTRY(68, sub_8297B290, 0x8297B290) { ctx.r3.u64 = CECActionManagerSimple_GetName(ctx, base, ctx.r3.u64); }

uint64_t CECActionManagerSimple_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(68, 0x8297BC18)) { ctx.r3.u64 = actionManagerSimpleAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8297BC18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BC18);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 112);

	// destroy the EntityHandle embedded at +0x30 (its vtable is set back first)
	const uint32_t entityHandleVtable = uint32_t(g_820F1664);
	actionManagerSimple->m_30 = entityHandleVtable;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	ctx.r10.u64 = entityHandleVtable;
	EntityHandle_Release(ctx, base, actionManagerSimpleAddr + 48);
	actionManagerSimple->m_34 = 0u;

	SharedHandle_Release(ctx, base, actionManagerSimpleAddr + 32);
	SharedHandle_Release(ctx, base, actionManagerSimpleAddr + 24);
	SharedHandle_Release(ctx, base, actionManagerSimpleAddr + 16);
	actionManagerSimple->vtable = 0x820A8D10u;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, actionManagerSimpleAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return actionManagerSimpleAddr;
}
PROMOTED_ENTRY(68, sub_8297BC18, 0x8297BC18) { ctx.r3.u64 = CECActionManagerSimple_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8297BD40(CpuState& ctx, uint8_t* base, uint64_t actionManager, uint64_t action) {
	if (!UseLiftedCode(68, 0x8297BD40)) { ctx.r3.u64 = actionManager; ctx.r4.u64 = action; __imp__sub_8297BD40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BD40);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	// Scratch shared handle the virtual call writes its result into.
	uint32_t scratchHandle = stack + 80;
	callTarget.u64 = LOAD32(LOAD32((uint32_t)action) + 16);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = scratchHandle;
	ctx.r4.u64 = action;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t newHandle = ctx.r3.u32;
	uint32_t newObject = LOAD32(newHandle);
	uint32_t newOwner = LOAD32(newHandle + 4);

	uint32_t handle = (uint32_t)actionManager + 32;
	if (LOAD32(handle + 4) != newOwner) {
		SharedHandle_Release(ctx, base, handle);
		STORE32(handle, newObject);
		STORE32(handle + 4, newOwner);
		if (newOwner != 0) {
			STORE32(newOwner, LOAD32(newOwner) + 1);
		}
	}

	uint64_t result = SharedHandle_Release(ctx, base, scratchHandle);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297BD40, 0x8297BD40) { ctx.r3.u64 = n_sub_8297BD40(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8297BDB0(CpuState& ctx, uint8_t* base, uint64_t actionManager) {
	if (!UseLiftedCode(68, 0x8297BDB0)) { ctx.r3.u64 = actionManager; __imp__sub_8297BDB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BDB0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	// Kept at full register width: the callee hands it on in r5.
	uint64_t entityHandle = actionManager + 48;

	uint64_t hasCombatComponent = 0;
	if (int32_t(LOAD32((uint32_t)entityHandle + 8)) >= 0) {
		ctx.r1.u64 = stack;
		uint32_t combatComponent = (uint32_t)Entity_GetCombatComponent(ctx, base, entityHandle);
		if (combatComponent != 0)
			hasCombatComponent = 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return hasCombatComponent;
}
PROMOTED_ENTRY(68, sub_8297BDB0, 0x8297BDB0) { ctx.r3.u64 = n_sub_8297BDB0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8297BF50(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297BF50)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297BF50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BF50);
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	if (actionManagerSimple->m_28 == 0) return actionManagerSimpleAddr;

	uint32_t virtualFunction = LOAD32(uint32_t(actionManagerSimple->vtable) + 72);
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = virtualFunction;
	REX_CALL_INDIRECT_FUNC(virtualFunction);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(68, sub_8297BF50, 0x8297BF50) { ctx.r3.u64 = n_sub_8297BF50(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8297BF70(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr, uint64_t entityHandle) {
	if (!UseLiftedCode(68, 0x8297BF70)) { ctx.r3.u64 = actionManagerSimpleAddr; ctx.r4.u64 = entityHandle; __imp__sub_8297BF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BF70);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	// State the calls below may read. Callers read r4 after the call: the entity handle,
	// or whatever the calls below leave in r4.
	ctx.r4.u64 = entityHandle;

	uint64_t result = actionManagerSimpleAddr;
	if (int32_t(LOAD32((uint32_t)entityHandle + 8)) >= 0) {
		ctx.r1.u64 = stack;
		uint64_t combatComponent = Entity_GetCombatComponent(ctx, base, entityHandle);
		result = combatComponent;
		if ((uint32_t)combatComponent != 0) {
			// r4 still holds what Entity_GetCombatComponent left in it.
			uint32_t virtualFunction = LOAD32(uint32_t(actionManagerSimple->vtable) + 72);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = actionManagerSimpleAddr;
			ctx.r10.u64 = virtualFunction;
			REX_CALL_INDIRECT_FUNC(virtualFunction);
			result = ctx.r3.u64;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297BF70, 0x8297BF70) { ctx.r3.u64 = n_sub_8297BF70(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8297BFE0(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr, uint64_t actionAddr) {
	if (!UseLiftedCode(68, 0x8297BFE0)) { ctx.r3.u64 = actionManagerSimpleAddr; ctx.r4.u64 = actionAddr; __imp__sub_8297BFE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BFE0);
	uint32_t actionPriority = LOAD32((uint32_t)actionAddr + 52);
	return CECActionManagerSimple_CanInterruptCurrentAction(ctx, base, actionManagerSimpleAddr, actionPriority, 0);
}
PROMOTED_ENTRY(68, sub_8297BFE0, 0x8297BFE0) { ctx.r3.u64 = n_sub_8297BFE0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t Lua_Talk_IsTalking(CpuState& ctx, uint8_t* base, uint32_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297BFF0)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297BFF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BFF0);
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
	return currentAction != 0;
}
PROMOTED_ENTRY(68, sub_8297BFF0, 0x8297BFF0) { ctx.r3.u64 = Lua_Talk_IsTalking(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8297C008(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297C008)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297C008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C008);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t checkFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = checkFn;
	REX_CALL_INDIRECT_FUNC(checkFn);

	uint64_t result = 0;
	if ((ctx.r3.u32 & 0xFF) != 0) {
		uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
		int32_t currentPriority = (int32_t)LOAD32(currentAction + 52);
		if (currentPriority < 9)
			result = 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297C008, 0x8297C008) { ctx.r3.u64 = n_sub_8297C008(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8297C068(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297C068)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297C068(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C068);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t checkFn = LOAD32(uint32_t(actionManagerSimple->vtable) + 88);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = checkFn;
	REX_CALL_INDIRECT_FUNC(checkFn);

	uint64_t result = 0;
	if ((ctx.r3.u32 & 0xFF) != 0) {
		uint32_t currentAction = actionManagerSimple->m_pCurrentAction;
		if (LOAD8(currentAction + 82) != 0)
			result = 1;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297C068, 0x8297C068) { ctx.r3.u64 = n_sub_8297C068(ctx, base, ctx.r3.u64); }

// sub_8297C0C8  [16 bytes]
uint64_t n_sub_8297C0C8(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297C0C8)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297C0C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C0C8);
	CECActionManagerSimple* actionManagerSimple = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	uint32_t virtualMethod = LOAD32(uint32_t(actionManagerSimple->vtable) + 72);
	ctx.r3.u64 = actionManagerSimpleAddr;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(68, sub_8297C0C8, 0x8297C0C8) { ctx.r3.u64 = n_sub_8297C0C8(ctx, base, ctx.r3.u64); }

uint64_t CECActionManagerSimple_ReleaseCurrentAction(CpuState& ctx, uint8_t* base, uint64_t manager) {
	if (!UseLiftedCode(68, 0x8297C0D8)) { ctx.r3.u64 = manager; __imp__sub_8297C0D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C0D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t currentActionSlot = manager + 16;  // m_pCurrentAction
	uint64_t result = LOAD32((uint32_t)currentActionSlot);
	if ((uint32_t)result != 0) {
		uint32_t action = (uint32_t)result;
		PPCRegister callTarget{};
		callTarget.u64 = LOAD32(LOAD32(action) + 24);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = action;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// r9 as the two calls below receive it: the low byte of the virtual call's result,
		// or what n_sub_826DF838 left there
		uint64_t r9Value = ctx.r3.u32 & 0xFF;
		if (r9Value == 0) {
			ctx.r9.u64 = r9Value;
			n_sub_826DF838(ctx, base, LOAD32((uint32_t)currentActionSlot));
			r9Value = ctx.r9.u64;
		}
		action = LOAD32((uint32_t)currentActionSlot);
		if (LOAD8(action + 73) == 0) {
			ctx.r9.u64 = r9Value;
			n_sub_82285D10(ctx, base, action);
		}
		result = SharedHandle_Release(ctx, base, currentActionSlot);
		STORE32((uint32_t)currentActionSlot, 0u);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297C0D8, 0x8297C0D8) { ctx.r3.u64 = CECActionManagerSimple_ReleaseCurrentAction(ctx, base, ctx.r3.u64); }

uint64_t CECActionManagerSimple_SerializeAlpha(CpuState& ctx, uint8_t* base, uint64_t actionManager, uint64_t stream, uint32_t version) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820CEF4C_B_ = int32_t(0x820CEF4C);
	constexpr int32_t str_TXT_820ED7D8_B_ = int32_t(0x820ED7D8);
	if (!UseLiftedCode(68, 0x8297C158)) { ctx.r3.u64 = actionManager; ctx.r4.u64 = stream; ctx.r5.u64 = version; __imp__sub_8297C158(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C158);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// the manager itself, or what the last string release returned
	uint64_t result = actionManager;
	// r4 as callers read it after the return: the stream, or what the last string release left there
	uint64_t r4Value = stream;
	if ((int32_t)version == 1) {
		uint32_t nameString = stack + 80;
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820ED7D8_B_, -1);
		IStream_SerializeString(ctx, base, nameString, stream, actionManager + 41);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820CEF4C_B_, -1);
		// the name's text, or the shared empty string when the name has no data
		uint32_t nameData = LOAD32(nameString);
		uint64_t nameText = (nameData == 0) ? (uint64_t)g_8209003F : (uint64_t)LOAD32(nameData);
		ctx.r4.u64 = nameText;  // state the callee may pass on
		IStream_SerializeFloat(ctx, base, stream, actionManager + 44);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
		r4Value = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(68, sub_8297C158, 0x8297C158) { ctx.r3.u64 = CECActionManagerSimple_SerializeAlpha(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CECActionManagerSimple_ApplyAlpha(CpuState& ctx, uint8_t* base, uint64_t actionManagerSimpleAddr) {
	if (!UseLiftedCode(68, 0x8297C208)) { ctx.r3.u64 = actionManagerSimpleAddr; __imp__sub_8297C208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C208);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManager = GameObject<CECActionManagerSimple>(base, actionManagerSimpleAddr);
	stack = PushStackFrame(base, stack, 96);

	uint64_t result = actionManagerSimpleAddr;
	if (actionManager->m_changingAlpha != 0) {
		uint32_t entityAddr = actionManager->m_pEntity;
		result = 0;
		actionManager->m_changingAlpha = 0;
		if ((LOAD32(entityAddr + 36) >> 3) & 1) {
			// r6-r9 and the carry as the alpha call receives them: the caller's values unless the
			// lookup below overwrites them (r9 starts as the flag bit just tested)
			uint64_t r6Value = ctx.r6.u64;
			uint64_t r7Value = ctx.r7.u64;
			uint64_t r8Value = ctx.r8.u64;
			uint64_t r9Value = 1;
			uint8_t carry = ctx.xer.ca;

			uint32_t node = LOAD32(entityAddr + 140);
			if (node != 0) {
				uint32_t index = LOAD8(node + 3);
				r9Value = index;
				r8Value = (uint64_t)(index << 3) + LOAD32(entityAddr + 72);
				result = LOAD32((uint32_t)r8Value + 4);
			} else {
				// look key 3 up in the sorted 8-byte (key, value) entries; a miss reads the value
				// slot at the end pointer
				uint32_t first = LOAD32(entityAddr + 72);
				uint32_t last = LOAD32(entityAddr + 76);
				r6Value = last;
				STORE32(stack + 80, 0);
				int32_t count = (int32_t)(last - first);
				STORE32(stack + 84, first);
				carry = (count < 0) & ((count & 7) != 0);  // carry of the arithmetic shift
				count >>= 3;
				if (count > 0) {
					do {
						carry = (count < 0) & ((count & 1) != 0);
						int32_t half = count >> 1;
						uint32_t halfBytes = (uint32_t)half << 3;
						uint32_t probe = first + halfBytes;
						bool below = (int32_t)LOAD32(probe) < 3;
						r7Value = below ? 1 : 0;
						r8Value = halfBytes;
						r9Value = (uint64_t)half;
						if (below) {
							first = probe + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, first);
				}
				if (first != last && (int32_t)LOAD32(first) <= 3) {
					STORE64(stack + 80, LOAD64(stack + 80));
					result = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					result = LOAD32(last + 4);
				}
			}

			ctx.fpscr.disableFlushMode();
			double alpha = double(actionManager->m_targetAlpha);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r5.u64 = actionManagerSimpleAddr;
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = r9Value;
			ctx.xer.ca = carry;
			result = n_sub_82547EC8(ctx, base, result, alpha);
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_8297C208, 0x8297C208) { ctx.r3.u64 = CECActionManagerSimple_ApplyAlpha(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8297C358(CpuState& ctx, uint8_t* base, uint64_t resultString, uint64_t actionManagerAddr, uint64_t insertLineBreaks) {
	constexpr int32_t g_82000BF4 = int32_t(0x82000BF4);
	constexpr int32_t g_820ED7E8 = int32_t(0x820ED7E8);
	constexpr int32_t g_834A5B6C = int32_t(0x834A5B6C);
	if (!UseLiftedCode(68, 0x8297C358)) { ctx.r3.u64 = resultString; ctx.r4.u64 = actionManagerAddr; ctx.r5.u64 = insertLineBreaks; __imp__sub_8297C358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297C358);
	uint32_t stack = ctx.r1.u64;
	CECActionManagerSimple* actionManager = GameObject<CECActionManagerSimple>(base, actionManagerAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	// virtual at vtable +88 (in this class it tests whether a current action is set)
	callTarget.u64 = LOAD32(uint32_t(actionManager->vtable) + 88);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManagerAddr;
	ctx.r4.u64 = actionManagerAddr;
	ctx.r5.u64 = insertLineBreaks;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t hasCurrentAction = ctx.r3.u32 & 0xFF;
	// carry handed to the first string call: what the last call left, cleared if the search below runs
	uint8_t carry = ctx.xer.ca;

	if (hasCurrentAction != 0) {
		uint32_t action = actionManager->m_pCurrentAction;
		callTarget.u64 = LOAD32(LOAD32(action) + 36);
		ctx.r3.u64 = action;
		ctx.r9.u64 = hasCurrentAction;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t table = ctx.r3.u32;
		carry = ctx.xer.ca;

		uint32_t first = LOAD32(table + 24);
		uint32_t last = LOAD32(table + 28);
		int32_t remaining = (int32_t)(last - first) / 12;
		STORE32(stack + 88, 0);
		STORE32(stack + 92, first);
		if (remaining > 0) {
			carry = 0;  // the halving shifts of a positive count clear it
			// lower_bound over the 12-byte entries: first entry with key >= 2
			do {
				int32_t half = remaining >> 1;
				uint32_t mid = first + (uint32_t)half * 12;
				if ((int32_t)LOAD32(mid) < 2) {
					first = mid + 12;
					remaining -= half + 1;
				} else {
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 92, first);
		}

		uint32_t entry = last;
		if (first != last && (int32_t)LOAD32(first) <= 2) {
			STORE64(stack + 88, LOAD64(stack + 88));
			entry = LOAD32(stack + 92);
		}
		if (entry != LOAD32(table + 28)) {
			uint32_t text = stack + 80;
			uint32_t search = stack + 84;
			uint32_t replacement = stack + 88;
			ctx.xer.ca = carry;  // state the callee may pass on
			CCharString_CopyConstruct(ctx, base, text, (uint64_t)LOAD32(entry + 4) + 20);
			if ((insertLineBreaks & 0xFF) != 0) {
				// every backslash in the copied text gets a line break after it
				CCharString_ConstructFromCStr(ctx, base, replacement, g_820ED7E8, -1);
				CCharString_ConstructFromCStr(ctx, base, search, g_82000BF4, -1);
				CCharString_ReplaceAll(ctx, base, text, search, replacement);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, search);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, replacement);
			}
			CCharString_CopyConstruct(ctx, base, resultString, text);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, text);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return resultString;
		}
	}

	ctx.xer.ca = carry;  // state the callee may pass on
	CCharString_CopyConstruct(ctx, base, resultString, g_834A5B6C);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(68, sub_8297C358, 0x8297C358) { ctx.r3.u64 = n_sub_8297C358(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }
