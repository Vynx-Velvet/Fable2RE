// CPhasedAction (vtable 0x820054D0): methods of the class as readable C++.
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

uint32_t n_sub_821B6348(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	constexpr int32_t str_TXT_82000E50_B_ = int32_t(0x82000E50);
	if (!UseLiftedCode(2, 0x821B6348)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_821B6348(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821B6348);
	uint32_t stack = ctx.r1.u64;

	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);

	// Values the original keeps live in r6-r9 across calls.
	uint64_t liveR6 = ctx.r6.u64;
	uint64_t liveR7 = ctx.r7.u64;
	uint64_t liveR8 = ctx.r8.u64;
	uint64_t liveR9 = 0;

	uint32_t handleAddr = phasedActionAddr + 4;
	uint32_t actionValue = 0;
	uint32_t result = 0;

	stack = PushStackFrame(base, stack, 144);

	// Dereference the handle's object; release the handle if the descriptor is null.
	uint32_t searchObj = 0;
	uint32_t m8 = phasedAction->m_8;
	if (m8 != 0) {
		searchObj = LOAD32(m8);
		if (searchObj == 0) {
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, handleAddr);
			liveR6 = ctx.r6.u64;
			liveR7 = ctx.r7.u64;
			liveR8 = ctx.r8.u64;
		}
	}

	// Look up the entry keyed 19: either directly by index, or by lower_bound over a
	// sorted array of (int key, pointer value) entries.
	bool hasAction = false;
	liveR9 = (LOAD32(searchObj + 36) >> 19) & 1;
	if ((uint32_t)liveR9 != 0) {
		uint32_t indexTable = LOAD32(searchObj + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 19);
			uint32_t array = LOAD32(searchObj + 72);
			liveR9 = array + ((uint32_t)index << 3);
			actionValue = LOAD32((uint32_t)liveR9 + 4);
			hasAction = true;
		} else {
			uint32_t begin = LOAD32(searchObj + 72);
			uint32_t end = LOAD32(searchObj + 76);
			liveR6 = end;
			STORE32(stack + 80, 0);
			int32_t count = (int32_t)(end - begin);
			uint32_t pos = begin;
			STORE32(stack + 84, pos);
			count >>= 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t offset = (uint32_t)half << 3;
					liveR9 = half;
					liveR8 = offset;
					pos = offset + pos;
					bool less = (int32_t)LOAD32(pos) < 19;
					liveR7 = less ? 1 : 0;
					if (less) {
						count = count - half;
						pos = pos + 8;
						count = count - 1;
					} else {
						pos = pos - offset;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pos);
			}
			if (pos != end) {
				if ((int32_t)LOAD32(pos) > 19) {
					actionValue = LOAD32(end + 4);
				} else {
					STORE64(stack + 80, LOAD64(stack + 80));
					actionValue = LOAD32(LOAD32(stack + 84) + 4);
				}
				hasAction = true;
			} else {
				actionValue = LOAD32(end + 4);
				hasAction = true;
			}
		}
	}

	if (hasAction) {
		uint32_t actionName = stack + 80;
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, actionName, str_TXT_82000E50_B_, -1);
		n_sub_8223E410(ctx, base, actionValue, phasedActionAddr, phasedActionAddr + 40, stack + 80);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		liveR6 = ctx.r6.u64;
		liveR7 = ctx.r7.u64;
		liveR8 = ctx.r8.u64;
		liveR9 = ctx.r9.u64;
	}

	// Virtual call through vtable slot 0x3C.
	uint32_t vfn = LOAD32(uint32_t(phasedAction->vtable) + 60);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)vfn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = phasedActionAddr;
	ctx.r6.u64 = liveR6;
	ctx.r7.u64 = liveR7;
	ctx.r8.u64 = liveR8;
	ctx.r9.u64 = liveR9;
	ctx.r10.u64 = vfn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	result = ctx.r3.u32;
	uint64_t liveR6b = ctx.r6.u64;
	uint64_t liveR7b = ctx.r7.u64;
	uint64_t liveR8b = ctx.r8.u64;
	uint64_t liveR9b = ctx.r9.u64;

	// Second handle check.
	uint32_t result2 = 0;
	bool doStore = false;
	bool proceed = false;
	uint32_t m8b = LOAD32((uint32_t)handleAddr + 4);
	if (m8b != 0) {
		uint32_t obj = LOAD32(m8b);
		if (obj == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
			liveR6b = ctx.r6.u64;
			liveR7b = ctx.r7.u64;
			liveR8b = ctx.r8.u64;
			liveR9b = ctx.r9.u64;
		} else {
			proceed = (LOAD8(obj + 144) & 64) != 0;
		}
	}

	if (proceed) {
		result = C_820CBC88_GetEntity(ctx, base, phasedActionAddr);
		liveR6b = ctx.r6.u64;
		liveR7b = ctx.r7.u64;
		liveR8b = ctx.r8.u64;
		liveR9b = ctx.r9.u64;

		if (((LOAD32(result + 48) >> 14) & 1) != 0) {
			uint32_t indexTable = LOAD32(result + 140);
			uint32_t array = LOAD32(result + 72);
			if (indexTable != 0) {
				uint32_t index = LOAD8(indexTable + 110);
				array += (uint32_t)index << 3;
				result2 = LOAD32(array + 4);
				doStore = true;
			} else {
				uint32_t end = LOAD32(result + 76);
				liveR6b = end;
				STORE32(stack + 80, 0);
				int32_t count = (int32_t)(end - array);
				uint32_t pos = array;
				STORE32(stack + 84, pos);
				count >>= 3;
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						uint32_t offset = (uint32_t)half << 3;
						liveR9b = half;
						liveR8b = offset;
						pos = offset + pos;
						bool less = (int32_t)LOAD32(pos) < 110;
						liveR7b = less ? 1 : 0;
						if (less) {
							count = count - half;
							pos = pos + 8;
							count = count - 1;
						} else {
							pos = pos - offset;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, pos);
				}
				if (pos != end) {
					if ((int32_t)LOAD32(pos) > 110) {
						result2 = LOAD32(end + 4);
					} else {
						STORE64(stack + 80, LOAD64(stack + 80));
						result2 = LOAD32(LOAD32(stack + 84) + 4);
					}
					doStore = true;
				} else {
					result2 = LOAD32(end + 4);
					doStore = true;
				}
			}
		}

		if (doStore) {
			STORE8(result2 + 192, 0);
		}
	}

	phasedAction->m_48 = (uint8_t)1;

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = liveR6b;
	ctx.r7.u64 = liveR7b;
	ctx.r8.u64 = liveR8b;
	ctx.r9.u64 = liveR9b;
	return result;
}
PROMOTED_ENTRY(2, sub_821B6348, 0x821B6348) { ctx.r3.u64 = n_sub_821B6348(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_IsFinished(CpuState& ctx, uint8_t* base, uint32_t phasedAction) {
	if (!UseLiftedCode(11, 0x822A92B8)) { ctx.r3.u64 = phasedAction; __imp__sub_822A92B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822A92B8);
	uint32_t self = phasedAction;
	uint32_t phaseCount = LOAD32(self + 0x78);
	uint32_t phase = LOAD32(self + 0x70);
	if (phaseCount == phase) {
		if (phase == 0) {
			return 1;
		}
		uint32_t virtualIsFinished = LOAD32(LOAD32(phase) + 0x18);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)virtualIsFinished;
		ctx.r3.u64 = phase;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		return ctx.r3.u64;
	}
	if (phaseCount == 0) {
		return 1;
	}
	int32_t progress = (int32_t)LOAD32(self + 0x58);
	if (progress == 0) {
		return 0;
	}
	int32_t total = (int32_t)LOAD32(self + 0x54);
	return (total > progress) ? 1 : 0;
}
PROMOTED_ENTRY(11, sub_822A92B8, 0x822A92B8) { ctx.r3.u64 = CPhasedAction_IsFinished(ctx, base, ctx.r3.u32); }

uint64_t n_sub_822A9500(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	constexpr int32_t g_82001D24 = int32_t(0x82001D24);
	if (!UseLiftedCode(11, 0x822A9500)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_822A9500(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822A9500);
	uint32_t stack = ctx.r1.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);

	stack = PushStackFrame(base, stack, 128);
	uint64_t actionAddress = phasedActionAddr;

	if (phasedAction->m_CurrentPhase != 0) {
		uint32_t phase = phasedAction->m_CurrentPhase;
		uint32_t phaseValue3C = phasedAction->m_3C;
		ctx.r1.u64 = stack;
		uint64_t entity = C_820CBC88_GetEntity(ctx, base, phasedActionAddr);
		n_sub_821B6668(ctx, base, (uint64_t)phase, entity, (uint64_t)phaseValue3C);

		uint64_t wrapperStorage = operator_new(ctx, base, 16);
		uint64_t r8Value = ctx.r8.u64;
		uint64_t wrapper;
		if ((uint32_t)wrapperStorage != 0) {
			uint32_t currentPhase = phasedAction->m_CurrentPhase;
			uint32_t elapsedTime = phasedAction->m_ElapsedTime;
			wrapper = wrapperStorage;
			r8Value = (uint64_t)(int64_t)g_82001D24;
			STORE32((uint32_t)wrapperStorage + 8, actionAddress);
			STORE32((uint32_t)wrapperStorage, (uint32_t)r8Value);
			STORE32((uint32_t)wrapperStorage + 4, currentPhase);
			STORE32((uint32_t)wrapperStorage + 12, elapsedTime);
		} else {
			wrapper = 0;
		}

		uint32_t refCountedSlot = (uint32_t)stack + 80;
		uint32_t notifyPhase = phasedAction->m_CurrentPhase;
		ctx.r8.u64 = r8Value;
		uint64_t refPtr = RefCountedPtr_Assign_821BBCB0(ctx, base, refCountedSlot, wrapper);
		n_sub_8226BE28(ctx, base, (uint64_t)notifyPhase, refPtr);
		phasedActionAddr = SharedHandle_Release(ctx, base, refCountedSlot);

		if (LOAD8(actionAddress + 92) != 0) {
			phasedAction->m_34 = LOAD32(uint32_t(phasedAction->m_CurrentPhase) + 52);
		}
		if (LOAD8(actionAddress + 80) != 0) {
			STORE8(uint32_t(phasedAction->m_CurrentPhase) + 80, uint8_t(1));
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return phasedActionAddr;
}
PROMOTED_ENTRY(11, sub_822A9500, 0x822A9500) { ctx.r3.u64 = n_sub_822A9500(ctx, base, ctx.r3.u64); }

uint64_t n_sub_826DF838(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	if (!UseLiftedCode(46, 0x826DF838)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_826DF838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826DF838);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	uint64_t savedR9 = ctx.r9.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);

	stack = PushStackFrame(base, stack, 112);
	result = phasedActionAddr + 4;
	phasedAction->m_4B = uint8_t(1);

	bool canAdvance = false;
	uint32_t linkedRoot = phasedAction->m_8;
	if (linkedRoot != 0) {
		uint32_t linked = LOAD32(linkedRoot);
		if (linked == 0) {
			ctx.r1.u64 = stack;
			result = EntityHandle_Release(ctx, base, result);
			savedR9 = ctx.r9.u64;
		} else {
			canAdvance = (LOAD8(linked + 0x90) & 0x40) != 0;
		}
	}

	if (canAdvance) {
		if (LOAD8((uint32_t)phasedActionAddr + 0x48) == 0) {
			ctx.r1.u64 = stack;
			n_sub_821B6348(ctx, base, phasedActionAddr);
			savedR9 = ctx.r9.u64;
		}

		uint32_t entry = phasedAction->m_18;
		if (entry != LOAD32((uint32_t)phasedActionAddr + 0x1C)) {
			do {
				uint32_t phase = LOAD32(entry + 4);
				uint32_t advanceOne = LOAD32(LOAD32(phase) + 16);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = phase;
				ctx.r9.u64 = savedR9;
				ctx.r10.u64 = advanceOne;
				REX_CALL_INDIRECT_FUNC(advanceOne);
				savedR9 = phasedAction->m_1C;
				entry = (int32_t)entry + 12;
			} while (entry != (uint32_t)savedR9);
		}

		uint32_t advanceAll = LOAD32((uint32_t)phasedAction->vtable + 68);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = phasedActionAddr;
		ctx.r9.u64 = savedR9;
		ctx.r10.u64 = advanceAll;
		REX_CALL_INDIRECT_FUNC(advanceAll);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(46, sub_826DF838, 0x826DF838) { ctx.r3.u64 = n_sub_826DF838(ctx, base, ctx.r3.u64); }

uint32_t CPhasedAction_AssignSharedPtr96(CpuState& ctx, uint8_t* base, uint64_t phasedAction, uint64_t arg2) {
	if (!UseLiftedCode(48, 0x8270C0B8)) { ctx.r3.u64 = phasedAction; ctx.r4.u64 = arg2; __imp__sub_8270C0B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8270C0B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	uint32_t sourceHandle = (uint32_t)arg2;
	uint32_t destHandle = (uint32_t)phasedAction + 96;

	uint32_t sourceRefCount = LOAD32(sourceHandle + 4);
	uint32_t sourceData = LOAD32(sourceHandle);

	if (LOAD32((uint32_t)phasedAction + 100) != sourceRefCount) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		SharedHandle_Release(ctx, base, destHandle);
		arg2 = ctx.r4.u64;

		STORE32(destHandle, sourceData);
		STORE32(destHandle + 4, sourceRefCount);

		if (sourceRefCount != 0) {
			uint32_t refCount = LOAD32(sourceRefCount);
			STORE32(sourceRefCount, refCount + 1);
		}
	}

	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	uint32_t result = SharedHandle_Release(ctx, base, sourceHandle);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(48, sub_8270C0B8, 0x8270C0B8) { ctx.r3.u64 = CPhasedAction_AssignSharedPtr96(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8299C350  [152 bytes]
uint64_t CPhasedAction_Clone(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr, uint64_t sourceAction) {
	if (!UseLiftedCode(69, 0x8299C350)) { ctx.r3.u64 = phasedActionAddr; ctx.r4.u64 = sourceAction; __imp__sub_8299C350(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C350);
	uint32_t stack = ctx.r1.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint32_t cloneSize = 144;
	ctx.r4.u64 = sourceAction;
	uint64_t newAction = operator_new(ctx, base, cloneSize);
	if ((uint32_t)newAction != 0) {
		CLoopAction_CopyConstruct(ctx, base, newAction, sourceAction);
		STORE32((uint32_t)newAction, 0x820054D0u);
		CCharString_CopyConstruct(ctx, base, newAction + 128, sourceAction + 128);
		CCharString_CopyConstruct(ctx, base, newAction + 132, sourceAction + 132);
		CCharString_CopyConstruct(ctx, base, newAction + 136, sourceAction + 136);
		STORE8((uint32_t)newAction + 140, uint8_t(LOAD8((uint32_t)sourceAction + 140)));
	} else {
		newAction = 0;
	}
	C_820F1270_Clone(ctx, base, phasedActionAddr, newAction);
	uint32_t vtable = phasedAction->vtable;
	if (vtable != 0) {
		n_sub_82180B28(ctx, base, vtable);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return phasedActionAddr;
}
PROMOTED_ENTRY(69, sub_8299C350, 0x8299C350) { ctx.r3.u64 = CPhasedAction_Clone(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8299C3E8  [80 bytes]
uint64_t CPhasedAction_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t deleteFlags) {
	if (!UseLiftedCode(69, 0x8299C3E8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = deleteFlags; __imp__sub_8299C3E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C3E8);
	uint32_t stack = ctx.r1.u64;
	uint64_t self = arg1;
	bool freeStorage = (uint32_t(deleteFlags) & 0x1) != 0;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CPhasedAction_Destruct(ctx, base, self);
	if (freeStorage) {
		HandleTarget_Free(ctx, base, self);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return self;
}
PROMOTED_ENTRY(69, sub_8299C3E8, 0x8299C3E8) { ctx.r3.u64 = CPhasedAction_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhasedAction_Destruct(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(69, 0x8299C438)) { ctx.r3.u64 = arg1; __imp__sub_8299C438(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C438);
	uint32_t stack = ctx.r1.u64;
	uint64_t self = arg1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, self + 0x88);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, self + 0x84);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, self + 0x80);
	SharedHandle_Release(ctx, base, self + 0x78);
	SharedHandle_Release(ctx, base, self + 0x70);
	SharedHandle_Release(ctx, base, self + 0x68);
	SharedHandle_Release(ctx, base, self + 0x60);
	uint64_t result = HandleHolder_Dtor(ctx, base, self);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(69, sub_8299C438, 0x8299C438) { ctx.r3.u64 = CPhasedAction_Destruct(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_CreatePhases(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	constexpr int32_t g_82005430 = int32_t(0x82005430);
	if (!UseLiftedCode(69, 0x8299C5D0)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_8299C5D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C5D0);
	uint32_t stack = ctx.r1.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);
	stack = PushStackFrame(base, stack, 128);

	// Stack slot each new phase is wrapped into before the action takes it.
	uint64_t phaseSlot = (uint64_t)stack + 80;
	uint64_t phaseHandle = 0;
	uint64_t targetPhase = 0;

	// The byte at +140 selects the phase type. Each phase is built from one of the
	// strings at +128, +132 and +136 and becomes the start, loop and target phase.
	if (LOAD8((uint32_t)phasedActionAddr + 140) != 0) {
		ctx.r1.u64 = stack;
		uint64_t phaseAlloc = operator_new(ctx, base, 124);
		uint64_t phase = 0;
		if ((uint32_t)phaseAlloc != 0) {
			phase = n_sub_82867078(ctx, base, phaseAlloc, phasedActionAddr + 128, 0);
		}
		phaseHandle = C_820F1270_Clone(ctx, base, phaseSlot, phase);
		CPhasedAction_AssignSharedPtr96(ctx, base, phasedActionAddr, phaseHandle);

		phaseAlloc = operator_new(ctx, base, 124);
		phase = 0;
		if ((uint32_t)phaseAlloc != 0) {
			phase = n_sub_82867078(ctx, base, phaseAlloc, phasedActionAddr + 132, 0);
		}
		phaseHandle = C_820F1270_Clone(ctx, base, phaseSlot, phase);
		C_820DE818_AssignSharedPtr104(ctx, base, phasedActionAddr, phaseHandle);

		phaseAlloc = operator_new(ctx, base, 124);
		if ((uint32_t)phaseAlloc != 0) {
			targetPhase = n_sub_82867078(ctx, base, phaseAlloc, phasedActionAddr + 136, 0);
		}
	} else {
		ctx.r1.u64 = stack;
		uint64_t phaseAlloc = operator_new(ctx, base, 120);
		uint32_t phaseVtable = (uint32_t)g_82005430;
		uint64_t phase = 0;
		if ((uint32_t)phaseAlloc != 0) {
			n_sub_827F05D0(ctx, base, phaseAlloc, 1, phasedActionAddr + 128, 0);
			STORE32((uint32_t)phaseAlloc, phaseVtable);
			phase = phaseAlloc;
		}
		phaseHandle = C_820F1270_Clone(ctx, base, phaseSlot, phase);
		CPhasedAction_AssignSharedPtr96(ctx, base, phasedActionAddr, phaseHandle);

		phaseAlloc = operator_new(ctx, base, 120);
		phase = 0;
		if ((uint32_t)phaseAlloc != 0) {
			n_sub_827F05D0(ctx, base, phaseAlloc, 1, phasedActionAddr + 132, 0);
			STORE32((uint32_t)phaseAlloc, phaseVtable);
			phase = phaseAlloc;
		}
		phaseHandle = C_820F1270_Clone(ctx, base, phaseSlot, phase);
		C_820DE818_AssignSharedPtr104(ctx, base, phasedActionAddr, phaseHandle);

		phaseAlloc = operator_new(ctx, base, 120);
		if ((uint32_t)phaseAlloc != 0) {
			n_sub_827F05D0(ctx, base, phaseAlloc, 1, phasedActionAddr + 136, 0);
			STORE32((uint32_t)phaseAlloc, phaseVtable);
			targetPhase = phaseAlloc;
		}
	}

	phaseHandle = C_820F1270_Clone(ctx, base, phaseSlot, targetPhase);
	C_820DEC90_AssignSharedPtr112(ctx, base, phasedActionAddr, phaseHandle);
	phasedAction->m_Duration = 0u;
	uint64_t result = CLoopAction_StartLoop(ctx, base, phasedActionAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(69, sub_8299C5D0, 0x8299C5D0) { ctx.r3.u64 = CPhasedAction_CreatePhases(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_SetActivePhase(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr, uint64_t newPhase) {
	if (!UseLiftedCode(70, 0x829C5D80)) { ctx.r3.u64 = phasedActionAddr; ctx.r4.u64 = newPhase; __imp__sub_829C5D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5D80);
	uint32_t stack = ctx.r1.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);
	stack = PushStackFrame(base, stack, 112);

	// While the start or the target phase is current, the new phase is only released.
	uint32_t currentPhase = phasedAction->m_CurrentPhase;
	bool currentIsStartOrTarget = (int32_t)currentPhase == (int32_t)LOAD32((uint32_t)phasedActionAddr + 96)
	                           || (int32_t)currentPhase == (int32_t)LOAD32((uint32_t)phasedActionAddr + 112);
	if (!currentIsStartOrTarget) {
		if ((int32_t)currentPhase != 0) {
			ctx.r1.u64 = stack;
			ctx.r4.u64 = newPhase;  // state the callee may pass on
			n_sub_826DF838(ctx, base, phasedActionAddr);
			n_sub_82285D10(ctx, base, phasedActionAddr);
		}
		uint64_t currentPhaseField = phasedActionAddr + 120;
		ctx.r1.u64 = stack;
		SharedPtr_Assign(ctx, base, currentPhaseField, newPhase);

		uint32_t virtualFn = LOAD32(uint32_t(phasedAction->vtable) + 80);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)virtualFn;
		ctx.r3.u64 = phasedActionAddr;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		SharedHandle_Release(ctx, base, newPhase);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return phasedActionAddr;
	}

	ctx.r1.u64 = stack;
	ctx.r4.u64 = newPhase;  // state the callee may pass on
	SharedHandle_Release(ctx, base, newPhase);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(70, sub_829C5D80, 0x829C5D80) { ctx.r3.u64 = CPhasedAction_SetActivePhase(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_829C5E10  [8 bytes]
uint64_t n_sub_829C5E10(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	if (!UseLiftedCode(70, 0x829C5E10)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_829C5E10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5E10);
	uint32_t currentPhase = GameObject<CPhasedAction>(base, phasedActionAddr)->m_CurrentPhase;
	return n_sub_826DF838(ctx, base, currentPhase);
}
PROMOTED_ENTRY(70, sub_829C5E10, 0x829C5E10) { ctx.r3.u64 = n_sub_829C5E10(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_ClearActivePhase(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	if (!UseLiftedCode(70, 0x829C5E18)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_829C5E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5E18);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint64_t currentPhaseField = phasedActionAddr + 120;
	uint32_t currentPhase = LOAD32((uint32_t)currentPhaseField);

	uint64_t result = 0;
	if (currentPhase != 0) {
		ctx.r1.u64 = stack;
		n_sub_82285D10(ctx, base, currentPhase);
		result = SharedHandle_Release(ctx, base, currentPhaseField);
		STORE32((uint32_t)currentPhaseField, 0u);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(70, sub_829C5E18, 0x829C5E18) { ctx.r3.u64 = CPhasedAction_ClearActivePhase(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_GetActivePhase(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	if (!UseLiftedCode(70, 0x829C5E60)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_829C5E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5E60);
	uint32_t currentPhase = GameObject<CPhasedAction>(base, phasedActionAddr)->m_CurrentPhase;
	return currentPhase;
}
PROMOTED_ENTRY(70, sub_829C5E60, 0x829C5E60) { ctx.r3.u64 = CPhasedAction_GetActivePhase(ctx, base, ctx.r3.u64); }

uint64_t CPhasedAction_Reset(CpuState& ctx, uint8_t* base, uint64_t phasedActionAddr) {
	if (!UseLiftedCode(70, 0x829C5E68)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_829C5E68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5E68);
	uint32_t stack = ctx.r1.u64;
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint64_t actionByType = CPerformAction_FindActionByType(ctx, base, phasedActionAddr);
	phasedAction->m_Duration = 1;
	phasedAction->m_ElapsedTime = 1;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return actionByType;
}
PROMOTED_ENTRY(70, sub_829C5E68, 0x829C5E68) { ctx.r3.u64 = CPhasedAction_Reset(ctx, base, ctx.r3.u64); }

// Returns 1 when the target phase's check (vtable slot +52) passes, when the loop phase's
// check passes while the current phase is not the target phase, or when the start phase
// is current and its check passes; otherwise 0.
uint64_t n_sub_829C5EA0(CpuState& ctx, uint8_t* base, uint32_t phasedActionAddr) {
	if (!UseLiftedCode(70, 0x829C5EA0)) { ctx.r3.u64 = phasedActionAddr; __imp__sub_829C5EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829C5EA0);
	uint32_t stack = ctx.r1.u64;
	// r9 as the later checks receive it: the caller's r9, then the last check's result
	uint64_t r9Value = ctx.r9.u64;
	PPCRegister callTarget{};
	CPhasedAction* phasedAction = GameObject<CPhasedAction>(base, phasedActionAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t targetPhase = phasedAction->m_TargetPhase;
	if (targetPhase != 0) {
		uint32_t checkFn = LOAD32(LOAD32(targetPhase) + 52);
		callTarget.u32 = checkFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = targetPhase;
		ctx.r10.u64 = checkFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r9Value = ctx.r3.u32 & 0xFF;
		if (r9Value != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return 1;
		}
	}

	uint32_t loopPhase = phasedAction->m_loopPhase;
	if (loopPhase != 0) {
		uint32_t checkFn = LOAD32(LOAD32(loopPhase) + 52);
		callTarget.u32 = checkFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = loopPhase;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = checkFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r9Value = ctx.r3.u32 & 0xFF;
		// both fields are read again: the checks may have changed them
		if (r9Value != 0 && phasedAction->m_CurrentPhase != phasedAction->m_TargetPhase) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return 1;
		}
	}

	uint32_t startPhase = phasedAction->m_startPhase;
	if (startPhase != 0 && phasedAction->m_CurrentPhase == startPhase) {
		uint32_t checkFn = LOAD32(LOAD32(startPhase) + 52);
		callTarget.u32 = checkFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = startPhase;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = checkFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((ctx.r3.u32 & 0xFF) != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return 1;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(70, sub_829C5EA0, 0x829C5EA0) { ctx.r3.u64 = n_sub_829C5EA0(ctx, base, ctx.r3.u32); }
