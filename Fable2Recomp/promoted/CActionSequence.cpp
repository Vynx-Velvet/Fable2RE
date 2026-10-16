// CActionSequence (vtable 0x82005298): methods of the class as readable C++.
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

uint64_t CActionSequence_IsAtEnd(CpuState& ctx, uint8_t* base, uint32_t actionSequenceAddr) {
	if (!UseLiftedCode(0, 0x82174800)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_82174800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174800);
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	uint32_t actionsBegin = actionSequence->m_ActionsBegin;
	// 8 bytes per action; a null begin pointer counts as no actions
	uint32_t actionCount = 0;
	if (actionsBegin != 0) {
		uint32_t actionBytes = actionSequence->m_ActionsEnd - actionsBegin;
		actionCount = (uint32_t)((int32_t)actionBytes >> 3);
	}
	uint32_t currentIndex = actionSequence->m_CurrentIndex;
	return actionCount == currentIndex;
}
PROMOTED_ENTRY(0, sub_82174800, 0x82174800) { ctx.r3.u64 = CActionSequence_IsAtEnd(ctx, base, ctx.r3.u32); }

uint64_t CActionSequence_SetCurrentIndex(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr, uint64_t newIndex) {
	constexpr int32_t g_82001D24 = int32_t(0x82001D24);
	if (!UseLiftedCode(1, 0x821A0FA8)) { ctx.r3.u64 = actionSequenceAddr; ctx.r4.u64 = newIndex; __imp__sub_821A0FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821A0FA8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	stack = PushStackFrame(base, stack, 144);

	actionSequence->m_CurrentIndex = (uint32_t)newIndex;

	const uint64_t currentActionSlot = actionSequenceAddr + 100;  // the shared handle m_CurrentAction
	uint64_t result;

	uint32_t actionsBegin = actionSequence->m_ActionsBegin;
	uint32_t actionsEnd = 0;
	bool indexInRange = false;
	if (actionsBegin != 0) {
		actionsEnd = actionSequence->m_ActionsEnd;
		uint32_t actionTableBytes = actionsEnd - actionsBegin;
		flags.ca = ((int32_t)actionTableBytes < 0) & ((actionTableBytes & 7) != 0);
		indexInRange = (uint32_t)newIndex < (uint32_t)((int32_t)actionTableBytes >> 3);
	}

	if (!indexInRange) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = newIndex;
		ctx.xer.ca = flags.ca;
		result = SharedHandle_Release(ctx, base, currentActionSlot);
		actionSequence->m_CurrentAction = 0u;
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	// bounds check of the table access, against a fresh read of the begin pointer
	actionsBegin = actionSequence->m_ActionsBegin;
	bool entryInRange = false;
	if (actionsBegin != 0) {
		uint32_t actionTableBytes = actionsEnd - actionsBegin;
		flags.ca = ((int32_t)actionTableBytes < 0) & ((actionTableBytes & 7) != 0);
		entryInRange = (uint32_t)newIndex < (uint32_t)((int32_t)actionTableBytes >> 3);
	}
	if (!entryInRange) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t actionEntryOffset = (uint32_t)newIndex << 3;
	uint32_t actionObject = LOAD32(actionEntryOffset + actionsBegin);
	uint32_t actionVtable = LOAD32(actionObject);
	uint32_t getActionFn = LOAD32(actionVtable + 16);
	uint32_t returnBuffer = stack + 80;

	// r3: the handle the call fills, r4: the action; r8-r10 and CA are state the callee may pass on
	PPCRegister callTarget{};
	callTarget.u64 = getActionFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = returnBuffer;
	ctx.r4.u64 = actionObject;
	ctx.r8.u64 = getActionFn;
	ctx.r9.u64 = actionVtable;
	ctx.r10.u64 = actionEntryOffset;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t newActionHandle = ctx.r3.u64;

	SharedPtr_Assign(ctx, base, currentActionSlot, newActionHandle);
	SharedHandle_Release(ctx, base, returnBuffer);

	uint32_t sequenceValue3C = actionSequence->m_3C;
	uint32_t currentAction = actionSequence->m_CurrentAction;
	uint64_t entity = C_820CBC88_GetEntity(ctx, base, actionSequenceAddr);
	n_sub_821B6668(ctx, base, (uint64_t)currentAction, entity, (uint64_t)sequenceValue3C);

	// 16-byte object { vtable 0x82001D24, current action, this sequence, 0 }, passed with the current action to n_sub_8226BE28
	uint64_t linkMemory = operator_new(ctx, base, 16);
	uint64_t r8Value = ctx.r8.u64;  // r8 at the RefCountedPtr_Assign call: what operator_new left, or the object's vtable
	uint64_t linkObject = 0;
	if ((uint32_t)linkMemory != 0) {
		uint32_t owningAction = LOAD32((uint32_t)currentActionSlot);
		STORE32((uint32_t)linkMemory + 8, (uint32_t)actionSequenceAddr);
		r8Value = g_82001D24;
		STORE32((uint32_t)linkMemory + 12, 0u);
		STORE32((uint32_t)linkMemory, (uint32_t)r8Value);
		STORE32((uint32_t)linkMemory + 4, owningAction);
		linkObject = linkMemory;
	}

	uint32_t linkRefSlot = stack + 88;
	uint32_t currentActionPtr = LOAD32((uint32_t)currentActionSlot);
	ctx.r8.u64 = r8Value;
	uint64_t linkRef = RefCountedPtr_Assign_821BBCB0(ctx, base, linkRefSlot, linkObject);
	n_sub_8226BE28(ctx, base, (uint64_t)currentActionPtr, linkRef);
	result = SharedHandle_Release(ctx, base, linkRefSlot);

	if (actionSequence->m_7C != 0) {
		actionSequence->m_34 = LOAD32(LOAD32((uint32_t)currentActionSlot) + 0x34);
	}
	if (actionSequence->m_50 != 0) {
		STORE8(LOAD32((uint32_t)currentActionSlot) + 0x50, uint8_t(1));
	}
	if (actionSequence->m_52 != 0 && LOAD8(LOAD32((uint32_t)currentActionSlot) + 0x52) == 0) {
		actionSequence->m_52 = uint8_t(0);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_821A0FA8, 0x821A0FA8) { ctx.r3.u64 = CActionSequence_SetCurrentIndex(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CActionSequence_IsIndexValid(CpuState& ctx, uint8_t* base, uint32_t actionSequenceAddr) {
	if (!UseLiftedCode(13, 0x822D34E8)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_822D34E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D34E8);
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	int32_t currentIndex = (int32_t)actionSequence->m_CurrentIndex;
	int32_t lastValidIndex = (int32_t)actionSequence->m_78;
	return currentIndex <= lastValidIndex ? 1 : 0;
}
PROMOTED_ENTRY(13, sub_822D34E8, 0x822D34E8) { ctx.r3.u64 = CActionSequence_IsIndexValid(ctx, base, ctx.r3.u32); }

// The first parameter is the shared handle that receives the copy (object at +0, control block at +4,
// filled by C_820F1270_Clone); it is also the return value. sub_827F1100 is the CActionSequence constructor.
uint64_t CActionSequence_Clone(CpuState& ctx, uint8_t* base, uint64_t resultHandleAddr, uint64_t sourceSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1088)) { ctx.r3.u64 = resultHandleAddr; ctx.r4.u64 = sourceSequenceAddr; __imp__sub_827F1088(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1088);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = sourceSequenceAddr;
	uint64_t sequenceMemory = operator_new(ctx, base, 128);
	uint64_t newSequence = 0;
	if ((uint32_t)sequenceMemory != 0) {
		newSequence = n_sub_827F1100(ctx, base, sequenceMemory, sourceSequenceAddr);
	}

	C_820F1270_Clone(ctx, base, resultHandleAddr, newSequence);

	uint32_t heldSequence = LOAD32((uint32_t)resultHandleAddr);
	if (heldSequence != 0) {
		n_sub_82180B28(ctx, base, heldSequence);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return resultHandleAddr;
}
PROMOTED_ENTRY(55, sub_827F1088, 0x827F1088) { ctx.r3.u64 = CActionSequence_Clone(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CActionSequence_Destruct(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(55, 0x827F11E0)) { ctx.r3.u64 = actionSequenceAddr; ctx.r4.u64 = deleteFlags; __imp__sub_827F11E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F11E0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, actionSequenceAddr + 108);
	SharedHandle_Release(ctx, base, actionSequenceAddr + 100);  // m_CurrentAction
	PtrVector8_ClearAndFree(ctx, base, actionSequenceAddr + 84); // the action table (m_ActionsBegin/m_ActionsEnd)
	HandleHolder_Dtor(ctx, base, actionSequenceAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, actionSequenceAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return actionSequenceAddr;
}
PROMOTED_ENTRY(55, sub_827F11E0, 0x827F11E0) { ctx.r3.u64 = CActionSequence_Destruct(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CActionSequence_SetActionAt(CpuState& ctx, uint8_t* base, uint32_t actionSequenceAddr, uint64_t actionIndex, uint64_t newAction) {
	if (!UseLiftedCode(55, 0x827F14E8)) { ctx.r3.u64 = actionSequenceAddr; ctx.r4.u64 = actionIndex; ctx.r5.u64 = newAction; __imp__sub_827F14E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827F14E8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);

	stack = PushStackFrame(base, stack, 112);

	uint32_t index = (uint32_t)actionIndex;
	// r4/r5/r9 handed to the final release: r4/r5 as passed in or as the action's virtual call left them,
	// r9 as passed in, then the last table size or call result computed below
	uint64_t r4Value = actionIndex;
	uint64_t r5Value = newAction;
	uint64_t r9Value = ctx.r9.u64;

	uint32_t actionsBegin = actionSequence->m_ActionsBegin;
	if (actionsBegin != 0) {
		uint64_t actionsEnd = actionSequence->m_ActionsEnd;
		r9Value = actionsEnd - (uint64_t)actionsBegin;
		flags.ca = ((int32_t)r9Value < 0) & (((uint32_t)r9Value & 0x7) != 0);

		if (index < (uint32_t)((int32_t)r9Value >> 3)) {
			// bounds check of the slot write, against a fresh read of the begin pointer
			actionsBegin = actionSequence->m_ActionsBegin;
			bool slotInRange = false;
			if (actionsBegin != 0) {
				r9Value = actionsEnd - (uint64_t)actionsBegin;
				flags.ca = ((int32_t)r9Value < 0) & (((uint32_t)r9Value & 0x7) != 0);
				slotInRange = index < (uint32_t)((int32_t)r9Value >> 3);
			}
			if (!slotInRange) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			uint64_t slotAddr = (uint64_t)(index << 3) + (uint64_t)actionsBegin;

			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r5.u64 = newAction;
			ctx.r9.u64 = r9Value;
			ctx.xer.ca = flags.ca;
			SharedPtr_Assign(ctx, base, slotAddr, newAction);

			uint32_t actionObject = LOAD32((uint32_t)newAction);
			uint32_t virtualFn = LOAD32(LOAD32(actionObject) + 52);
			PPCRegister callTarget{};
			callTarget.u64 = virtualFn;
			ctx.r3.u64 = actionObject;
			ctx.r10.u64 = virtualFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t callResult = ctx.r3.u32;
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
			flags.ca = ctx.xer.ca;
			r9Value = callResult & 0xFF;

			if ((uint32_t)r9Value != 0 && (int32_t)index > (int32_t)actionSequence->m_78) {
				actionSequence->m_78 = index;
			}
		}
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r5.u64 = r5Value;
	ctx.r9.u64 = r9Value;
	ctx.xer.ca = flags.ca;
	uint32_t released = SharedHandle_Release(ctx, base, newAction);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(55, sub_827F14E8, 0x827F14E8) { ctx.r3.u64 = CActionSequence_SetActionAt(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_827F1598(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr, uint64_t newActionHandle) {
	if (!UseLiftedCode(55, 0x827F1598)) { ctx.r3.u64 = actionSequenceAddr; ctx.r4.u64 = newActionHandle; __imp__sub_827F1598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1598);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR13 = ctx.r13.u64;
	PPCXERRegister flags = ctx.xer;
	PPCCRRegister compare0{};
	PPCRegister callTarget{};
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);

	stack = PushStackFrame(base, stack, 128);

	// virtual function at vtable +24 of the sequence, given the incoming handle; a non-zero low byte
	// means the handle is not installed (released, return 0)
	uint32_t sequenceCheckFn = LOAD32((uint32_t)actionSequence->vtable + 24);
	callTarget.u64 = sequenceCheckFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionSequenceAddr;
	ctx.r4.u64 = newActionHandle;
	ctx.r10.u64 = sequenceCheckFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t refused = ctx.r3.u32 & 0xFF;

	if (refused == 0) {
		uint32_t currentAction = actionSequence->m_CurrentAction;
		uint32_t currentIndex = actionSequence->m_CurrentIndex;
		if (currentAction != 0) {
			uint32_t actionCheckFn = LOAD32(LOAD32(currentAction) + 24);
			callTarget.u64 = actionCheckFn;
			ctx.r3.u64 = currentAction;
			ctx.r9.u64 = refused;
			ctx.r10.u64 = actionCheckFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t actionCheck = ctx.r3.u32 & 0xFF;
			if (actionCheck == 0) {
				ctx.r9.u64 = actionCheck;  // state the callee may pass on
				n_sub_826DF838(ctx, base, actionSequenceAddr);
				n_sub_82285D10(ctx, base, actionSequenceAddr);
			}
		}

		// Copy the incoming handle { object, control block } to stack+80 and add a reference
		// (atomic increment of the count in the control block's first word).
		uint32_t handleCopy = stack + 80;
		uint32_t controlBlock = LOAD32((uint32_t)newActionHandle + 4);
		uint32_t handleObject = LOAD32((uint32_t)newActionHandle);
		STORE32(handleCopy + 4, controlBlock);
		STORE32(handleCopy, handleObject);
		if (controlBlock != 0) {
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t savedLock = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(controlBlock);
				uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32);
				newRefCount += 1;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(controlBlock)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
				compare0.so = flags.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedLock & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
		}

		CActionSequence_SetActionAt(ctx, base, actionSequenceAddr, currentIndex, handleCopy);
		CActionSequence_SetCurrentIndex(ctx, base, actionSequenceAddr, currentIndex);
		SharedHandle_Release(ctx, base, newActionHandle);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return actionSequenceAddr;
	}

	SharedHandle_Release(ctx, base, newActionHandle);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(55, sub_827F1598, 0x827F1598) { ctx.r3.u64 = n_sub_827F1598(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Calls the virtual function at vtable +28 of each object in the action table (8-byte entries; begin at +88,
// end at +92, as m_ActionsBegin/m_ActionsEnd) and returns in f1 the float constant at 0x820994B4 plus their
// f1 results; returns r3 as the last call left it (the incoming value when the table is empty).
uint64_t n_sub_827F1680(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr, double floatArg1) {
	if (!UseLiftedCode(55, 0x827F1680)) { ctx.r3.u64 = actionSequenceAddr; ctx.f1.f64 = floatArg1; __imp__sub_827F1680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1680);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t actionTable = (uint32_t)actionSequenceAddr + 84;
	uint32_t entry = LOAD32((uint32_t)actionSequenceAddr + 88);
	uint32_t checkedEnd = LOAD32((uint32_t)actionSequenceAddr + 92);  // end used for the entry bounds checks
	double sum = double(LOAD_F32(0x820994B4u));
	uint64_t lastR3 = actionSequenceAddr;
	double lastF1 = floatArg1;  // f1 handed to each call: the incoming value, then the previous call's result

	if (entry > checkedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	for (;;) {
		uint32_t end = LOAD32(actionTable + 8);
		uint32_t begin = LOAD32(actionTable + 4);
		if (begin > end) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (entry == end) break;
		if (entry >= checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t object = LOAD32(entry);
		uint32_t virtualFn = LOAD32(LOAD32(object) + 28);
		callTarget.u64 = virtualFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = object;
		ctx.r9.u64 = begin;
		ctx.r10.u64 = virtualFn;
		ctx.f1.f64 = lastF1;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		lastR3 = ctx.r3.u64;
		lastF1 = ctx.f1.f64;
		checkedEnd = LOAD32(actionTable + 8);
		ctx.fpscr.disableFlushMode();
		sum = double(float(lastF1 + sum));
		if (entry >= checkedEnd) {
			ppc_trap(ctx, base, 22);
		}
		entry += 8;
	}

	ctx.fpscr.disableFlushMode();
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = sum;  // callers read the sum from f1
	return lastR3;
}
PROMOTED_ENTRY(55, sub_827F1680, 0x827F1680) { ctx.r3.u64 = n_sub_827F1680(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Calls virtual slot 8 (vtable offset 32) on the object in the first word of every 8-byte entry of
// m_ActionsBegin..m_ActionsEnd and adds the f1 each call leaves to a single-precision sum that starts at
// the float constant at 0x820994B4; the sum is left in f1 for the caller.
uint64_t n_sub_827F1740(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr, double incomingF1) {
	if (!UseLiftedCode(55, 0x827F1740)) { ctx.r3.u64 = actionSequenceAddr; ctx.f1.f64 = incomingF1; __imp__sub_827F1740(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1740);
	uint32_t stack = ctx.r1.u64;
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t entry = actionSequence->m_ActionsBegin;
	uint32_t actionsEnd = actionSequence->m_ActionsEnd;
	double sum = double(LOAD_F32(0x820994B4u));
	// the game code does not load f1 before a call: the first call gets the caller's f1, each later call
	// the f1 the previous call left
	double f1Value = incomingF1;
	// r3 is returned as the last call left it (unchanged when there is no entry)
	uint64_t lastR3 = actionSequenceAddr;
	// checked-iterator traps: the iterator must stay within the list
	if (entry > actionsEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	while (true) {
		uint32_t currentEnd = actionSequence->m_ActionsEnd;
		uint32_t currentBegin = actionSequence->m_ActionsBegin;
		if (currentBegin > currentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (entry == currentEnd) {
			break;
		}
		if (entry >= actionsEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t action = LOAD32(entry);
		uint32_t method = LOAD32(LOAD32(action) + 32);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = action;
		ctx.r9.u64 = currentBegin;
		ctx.r10.u64 = method;
		ctx.f1.f64 = f1Value;
		REX_CALL_INDIRECT_FUNC(method);
		lastR3 = ctx.r3.u64;
		f1Value = ctx.f1.f64;
		actionsEnd = actionSequence->m_ActionsEnd;
		ctx.fpscr.disableFlushMode();
		sum = double(float(f1Value + sum));
		if (entry >= actionsEnd) {
			ppc_trap(ctx, base, 22);
		}
		entry += 8;
	}
	ctx.fpscr.disableFlushMode();
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read the sum in f1
	ctx.f1.f64 = sum;
	return lastR3;
}
PROMOTED_ENTRY(55, sub_827F1740, 0x827F1740) { ctx.r3.u64 = n_sub_827F1740(ctx, base, ctx.r3.u64, ctx.f1.f64); }

uint64_t CActionSequence_Restart(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1800)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_827F1800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1800);
	return CActionSequence_SetCurrentIndex(ctx, base, actionSequenceAddr, 0);
}
PROMOTED_ENTRY(55, sub_827F1800, 0x827F1800) { ctx.r3.u64 = CActionSequence_Restart(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827F1808(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1808)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_827F1808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1808);
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	uint32_t currentAction = actionSequence->m_CurrentAction;
	return n_sub_826DF838(ctx, base, currentAction);
}
PROMOTED_ENTRY(55, sub_827F1808, 0x827F1808) { ctx.r3.u64 = n_sub_827F1808(ctx, base, ctx.r3.u64); }

uint64_t CActionSequence_ClearCurrentAction(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1810)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_827F1810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1810);
	uint32_t stack = ctx.r1.u64;
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = actionSequence->m_CurrentAction;
	if (result != 0) {
		ctx.r1.u64 = stack;
		n_sub_82285D10(ctx, base, result);
		uint64_t currentActionAddr = actionSequenceAddr + 100;
		result = SharedHandle_Release(ctx, base, currentActionAddr);
		actionSequence->m_CurrentAction = 0;
	}

	// the index moves one past the last action (entries are 8 bytes; a null begin pointer gives 0)
	uint32_t actionsBegin = actionSequence->m_ActionsBegin;
	uint32_t actionCount = 0;
	if (actionsBegin != 0) {
		actionCount = (int32_t)((uint32_t)actionSequence->m_ActionsEnd - actionsBegin) >> 3;
	}
	actionSequence->m_CurrentIndex = actionCount;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827F1810, 0x827F1810) { ctx.r3.u64 = CActionSequence_ClearCurrentAction(ctx, base, ctx.r3.u64); }

uint64_t CActionSequence_GetCurrentAction(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1880)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_827F1880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1880);
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	uint32_t currentAction = actionSequence->m_CurrentAction;
	return currentAction;
}
PROMOTED_ENTRY(55, sub_827F1880, 0x827F1880) { ctx.r3.u64 = CActionSequence_GetCurrentAction(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827F1888(CpuState& ctx, uint8_t* base, uint64_t actionSequenceAddr) {
	if (!UseLiftedCode(55, 0x827F1888)) { ctx.r3.u64 = actionSequenceAddr; __imp__sub_827F1888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F1888);
	uint32_t stack = ctx.r1.u64;
	CActionSequence* actionSequence = GameObject<CActionSequence>(base, actionSequenceAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint64_t actionByType = CPerformAction_FindActionByType(ctx, base, actionSequenceAddr);
	int32_t actionsBegin = actionSequence->m_ActionsBegin;
	if (actionsBegin == 0) {
		actionSequence->m_CurrentIndex = -1;
	} else {
		int32_t actionBytes = (int32_t)((uint32_t)actionSequence->m_ActionsEnd - (uint32_t)actionsBegin);
		actionSequence->m_CurrentIndex = (actionBytes >> 3) - 1;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return actionByType;
}
PROMOTED_ENTRY(55, sub_827F1888, 0x827F1888) { ctx.r3.u64 = n_sub_827F1888(ctx, base, ctx.r3.u64); }
