// EntityHandle (vtable 0x820F1664): methods of the class as readable C++.
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

uint64_t n_sub_82195F20(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t actionManager, uint64_t hitResponseTable) {
	if (!UseLiftedCode(1, 0x82195F20)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = actionManager; ctx.r5.u64 = hitResponseTable; __imp__sub_82195F20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82195F20);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);
	uint32_t newHandleAddr = stack + 80;
	ctx.r1.u64 = stack;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);

	HitResponse_CreateActionFromTable(ctx, base, newHandleAddr, hitResponseTable);

	uint32_t action = LOAD32(stack + 80);
	if (action != 0) {
		uint32_t hook = LOAD32(0x83496BBCu);
		if (hook != 0) {
			ctx.r3.u64 = LOAD32(actionManager + 4);
			ctx.r4.u64 = hitResponseTable;
			ctx.r10.u64 = hook;
			REX_CALL_INDIRECT_FUNC(hook);
		}
		uint32_t canInterrupt = CECActionManagerSimple_CanInterruptCurrentAction(ctx, base, actionManager, LOAD32(action + 52), 0);
		uint64_t savedR9 = ctx.r9.u64;
		if ((canInterrupt & 0xFF) != 0) {
			uint32_t controlBlock = LOAD32(stack + 84);
			STORE32(stack + 88, action);
			STORE32(stack + 92, controlBlock);
			if (controlBlock != 0) {
				// take an extra reference on the shared handle's control block
				STORE32(controlBlock, LOAD32(controlBlock) + 1);
			}
			n_sub_822A4648(ctx, base, entityHandleAddr, actionManager, stack + 88, 1);
			SharedHandle_Release(ctx, base, newHandleAddr);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return entityHandleAddr;
		}
	}

	entityHandle->m_4 = 0u;
	entityHandle->vtable = 0x820F1664u;
	entityHandle->m_8 = 0xFFFFFFFFu;
	SharedHandle_Release(ctx, base, newHandleAddr);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(1, sub_82195F20, 0x82195F20) { ctx.r3.u64 = n_sub_82195F20(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t EntityHandle_CopyConstruct(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t sourceHandle) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(3, 0x821CF7C8)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = sourceHandle; __imp__sub_821CF7C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821CF7C8);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 96);

	entityHandle->m_4 = 0;
	entityHandle->vtable = (uint32_t)g_820F1664;

	uint32_t target = 0;
	uint32_t sourceRef = LOAD32((uint32_t)sourceHandle + 4);
	if (sourceRef != 0) {
		target = LOAD32(sourceRef);
		if (target == 0) {
			ctx.r1.u64 = stack;
			EntityHandle_Release(ctx, base, sourceHandle);
		}
	}

	ctx.r1.u64 = stack;
	EntityHandle_SetTarget(ctx, base, entityHandleAddr, target);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(3, sub_821CF7C8, 0x821CF7C8) { ctx.r3.u64 = EntityHandle_CopyConstruct(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t EntityHandle_SetTarget(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t targetEntity) {
	if (!UseLiftedCode(5, 0x822149C8)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = targetEntity; __imp__sub_822149C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822149C8);
	uint32_t stack = ctx.r1.u64;
	uint64_t retR9 = ctx.r9.u64;
	uint64_t retR10 = ctx.r10.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t target = (uint32_t)targetEntity;
	// entityHandle->m_4 is a shared {targetEntity, refcount} entry.
	uint32_t node = entityHandle->m_4;
	bool alreadyPointsAtTarget = node != 0 && LOAD32(node) == target && target != 0;

	if (!alreadyPointsAtTarget) {
		ctx.r1.u64 = stack;
		entityHandleAddr = EntityHandle_Release(ctx, base, entityHandleAddr);
		targetEntity = ctx.r4.u64;
		retR9 = ctx.r9.u64;
		retR10 = ctx.r10.u64;

		if (target != 0) {
			uint32_t existingNode = LOAD32(target + 4);
			if (existingNode != 0) {
				entityHandle->m_4 = existingNode;
				retR10 = (uint64_t)LOAD32(existingNode + 4) + 1;
				STORE32(existingNode + 4, (uint32_t)retR10);
			} else {
				uint32_t newNode = (uint32_t)operator_new(ctx, base, 8);
				entityHandleAddr = newNode;
				targetEntity = ctx.r4.u64;
				entityHandle->m_4 = newNode;
				STORE32(newNode, target);
				retR10 = newNode;
				STORE32(newNode + 4, 1u);
				retR9 = newNode;
				STORE32(target + 4, newNode);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = targetEntity;
	ctx.r9.u64 = retR9;
	ctx.r10.u64 = retR10;
	return entityHandleAddr;
}
PROMOTED_ENTRY(5, sub_822149C8, 0x822149C8) { ctx.r3.u64 = EntityHandle_SetTarget(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_822A4648(CpuState& ctx, uint8_t* base, uint64_t resultHandleAddr, uint64_t actionManager, uint64_t sourceHandle, uint64_t flags) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(11, 0x822A4648)) { ctx.r3.u64 = resultHandleAddr; ctx.r4.u64 = actionManager; ctx.r5.u64 = sourceHandle; ctx.r6.u64 = flags; __imp__sub_822A4648(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822A4648);

	uint32_t stack = ctx.r1.u64;
	uint64_t lockState = ctx.r9.u64;
	uint32_t savedMsr = ctx.r13.u64;
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, resultHandleAddr);

	const uint32_t manager = (uint32_t)actionManager;
	const uint32_t handleAddr = (uint32_t)(actionManager + 16);   // shared handle owned by the action manager
	const uint8_t flag = (uint8_t)(uint32_t)flags;

	stack = PushStackFrame(base, stack, 160);

	uint32_t refCount = LOAD32(manager + 20);
	uint32_t handleObject = LOAD32(manager + 16);
	STORE32(stack + 84, refCount);
	STORE32(stack + 80, handleObject);
	if (refCount != 0) {
		// atomically increase the reference count of the copy kept on the stack
		bool casDone;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = ((uint32_t)savedMsr & 0x8020) | (ctx.msr & ~0x8020);
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCount);
			uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32) + 1;
			uint32_t casAddr = refCount;
			casDone = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32(newRefCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = ((uint32_t)lockState & 0x8020) | (ctx.msr & ~0x8020);
			REX_LEAVE_GLOBAL_LOCK();
		} while (!casDone);
	}

	uint32_t prepareFn = LOAD32(LOAD32(manager) + 88);
	callTarget.u64 = (uint64_t)prepareFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = actionManager;
	ctx.r4.u64 = actionManager;
	ctx.r5.u64 = sourceHandle;
	ctx.r6.u64 = flags;
	ctx.r9.u64 = lockState;
	ctx.r10.u64 = prepareFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t isPrepared = ctx.r3.u32 & 0xFF;

	if (isPrepared != 0) {
		uint32_t currentObject = LOAD32(handleAddr);
		n_sub_826DF838(ctx, base, currentObject);
		isPrepared = ctx.r9.u64;
		uint32_t currentObject2 = LOAD32(handleAddr);
		if (currentObject2 != 0) {
			n_sub_82285D10(ctx, base, currentObject2);
			isPrepared = ctx.r9.u64;
		}
	}

	uint32_t secondaryCounter = LOAD32(handleAddr + 4);
	uint32_t secondaryHandle = (uint32_t)(actionManager + 24);
	uint32_t secondaryObject = LOAD32(handleAddr);
	if (LOAD32(manager + 28) != secondaryCounter) {
		SharedHandle_Release(ctx, base, secondaryHandle);
		isPrepared = ctx.r9.u64;
		STORE32(secondaryHandle, secondaryObject);
		STORE32(secondaryHandle + 4, secondaryCounter);
		if (secondaryCounter != 0) {
			uint32_t count = LOAD32(secondaryCounter);
			STORE32(secondaryCounter, count + 1);
		}
	}

	uint32_t sourceCounter = LOAD32((uint32_t)sourceHandle + 4);
	uint32_t sourceObject = LOAD32((uint32_t)sourceHandle);
	if (LOAD32(handleAddr + 4) != sourceCounter) {
		SharedHandle_Release(ctx, base, handleAddr);
		isPrepared = ctx.r9.u64;
		STORE32(handleAddr, sourceObject);
		STORE32(handleAddr + 4, sourceCounter);
		if (sourceCounter != 0) {
			uint32_t count = LOAD32(sourceCounter);
			STORE32(sourceCounter, count + 1);
		}
	}

	STORE8(manager + 40, flag);

	uint32_t managerCounter = LOAD32(manager + 12);
	uint32_t managerOwner = LOAD32(manager + 4);
	uint32_t targetObject = LOAD32(handleAddr);
	n_sub_821B6668(ctx, base, targetObject, managerOwner, managerCounter);

	uint32_t entityObject = LOAD32(handleAddr);
	uint32_t nextManagerCounter = LOAD32(manager + 12) + 1;
	uint32_t target = LOAD32(manager + 4);
	const uint32_t entityVtable = (uint32_t)(g_820F0000 + 5732);
	STORE32(manager + 12, nextManagerCounter);
	entityHandle->m_4 = 0;
	entityHandle->vtable = entityVtable;
	uint32_t entityExtra = LOAD32(entityObject + 60);
	ctx.r8.u64 = 0;
	EntityHandle_SetTarget(ctx, base, resultHandleAddr, target);
	entityHandle->m_8 = entityExtra;

	uint32_t stackHandle = (uint32_t)((uint64_t)stack + 80);
	SharedHandle_Release(ctx, base, stackHandle);
	SharedHandle_Release(ctx, base, sourceHandle);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return (uint32_t)resultHandleAddr;
}
PROMOTED_ENTRY(11, sub_822A4648, 0x822A4648) { ctx.r3.u64 = n_sub_822A4648(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t n_sub_822BE660(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t sourceEntity) {
	if (!UseLiftedCode(12, 0x822BE660)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = sourceEntity; __imp__sub_822BE660(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BE660);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);

	stack = PushStackFrame(base, stack, 112);

	// sourceEntity->vtable->method_0x58(sourceEntity): whether sourceEntity carries a valid source entity
	uint32_t initMethod = LOAD32(LOAD32((uint32_t)sourceEntity) + 88);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = sourceEntity;
	ctx.r4.u64 = sourceEntity;
	ctx.r10.u64 = initMethod;
	REX_CALL_INDIRECT_FUNC(initMethod);
	uint32_t hasSource = ctx.r3.u32 & 0xFF;

	if (hasSource != 0) {
		uint32_t sourceIndex = LOAD32((uint32_t)sourceEntity + 4);
		uint32_t sourceData = LOAD32(LOAD32((uint32_t)sourceEntity + 16) + 60);
		C_820F1664_Constructor(ctx, base, entityHandleAddr, sourceIndex, sourceData);
	} else {
		entityHandle->m_4 = 0u;
		entityHandle->vtable = 0x820F1664u;
		entityHandle->m_8 = 0xFFFFFFFFu;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(12, sub_822BE660, 0x822BE660) { ctx.r3.u64 = n_sub_822BE660(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t C_820F1664_Constructor(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t target, uint64_t targetId) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(18, 0x8237D2B8)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = target; ctx.r5.u64 = targetId; __imp__sub_8237D2B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8237D2B8);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 112);

	entityHandle->m_4 = 0;
	entityHandle->vtable = g_820F1664;

	ctx.r1.u64 = stack;
	ctx.r5.u64 = targetId;
	EntityHandle_SetTarget(ctx, base, entityHandleAddr, target);
	entityHandle->m_8 = uint32_t(targetId);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(18, sub_8237D2B8, 0x8237D2B8) { ctx.r3.u64 = C_820F1664_Constructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82488D18(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t deleteFlag) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(27, 0x82488D18)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = deleteFlag; __imp__sub_82488D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82488D18);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t vtable = uint32_t(g_820F1664);
	entityHandle->vtable = vtable;
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, entityHandleAddr);
	entityHandle->m_4 = 0u;
	if (uint32_t(deleteFlag & 0x1) != 0) {
		HandleTarget_Free(ctx, base, entityHandleAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(27, sub_82488D18, 0x82488D18) { ctx.r3.u64 = n_sub_82488D18(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t LookAtHandle_CopyConstruct(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t sourceHandle) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(37, 0x825BC258)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = sourceHandle; __imp__sub_825BC258(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825BC258);
	uint32_t stack = ctx.r1.u64;
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	EntityHandle_CopyConstruct(ctx, base, entityHandleAddr, sourceHandle);
	uint64_t destString = entityHandleAddr + 16;
	uint64_t sourceString = sourceHandle + 16;
	entityHandle->m_8 = LOAD32((uint32_t)sourceHandle + 8);
	entityHandle->m_C = LOAD32((uint32_t)sourceHandle + 12);
	CCharString_CopyConstruct(ctx, base, destString, sourceString);
	uint8_t flags = LOAD8((uint32_t)sourceHandle + 20);
	entityHandle->m_14 = flags;
	uint32_t copyCount = LOAD32((uint32_t)g_83490000 + 27288);
	copyCount += 1;
	STORE32((uint32_t)g_83490000 + 27288, copyCount);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = flags;
	ctx.r9.s64 = g_83490000;
	return (uint32_t)entityHandleAddr;
}
PROMOTED_ENTRY(37, sub_825BC258, 0x825BC258) { ctx.r3.u64 = LookAtHandle_CopyConstruct(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82706348(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t lookupContext, uint32_t lookupContainer, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(47, 0x82706348)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = lookupContext; ctx.r5.u64 = lookupContainer; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82706348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82706348);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsrBits = ctx.r13.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t container = lookupContainer;
	// the original reuses one register first as a lookup flag, then as a search byte offset
	uint32_t scratch = 0;
	uint32_t entryValue = 0;
	bool found = false;

	if (container != 0 && (LOAD8(container + 144) & 64) != 0) {
		scratch = (LOAD32(container + 40) >> 12) & 1;
		if (scratch != 0) {
			uint32_t indexTable = LOAD32(container + 140);
			if (indexTable != 0) {
				uint32_t byteOffset = LOAD8(indexTable + 44) << 3;
				uint32_t arrayBase = LOAD32(container + 72);
				entryValue = LOAD32(arrayBase + byteOffset + 4);
				found = true;
			} else {
				uint32_t begin = LOAD32(container + 72);
				uint32_t end = LOAD32(container + 76);
				STORE32(stack + 80, 0);
				int32_t count = (int32_t)(end - begin);
				STORE32(stack + 84, begin);
				flags.ca = count < 0 & ((uint32_t)count & 0x7) != 0;
				count >>= 3;
				if (count > 0) {
					do {
						flags.ca = count < 0 & ((uint32_t)count & 0x1) != 0;
						int32_t half = count >> 1;
						uint32_t isBelow = 1;
						scratch = half << 3;
						begin += scratch;
						if ((int32_t)LOAD32(begin) >= 44) {
							isBelow = 0;
						}
						if ((isBelow & 0xFF) != 0) {
							count = count - half;
							begin += 8;
							count = count - 1;
						} else {
							begin -= scratch;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= 44) {
					STORE64(stack + 80, LOAD64(stack + 80));
					entryValue = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					entryValue = LOAD32(end + 4);
				}
				found = true;
			}
		}
	}

	if (found) {
		uint32_t lookupFn = LOAD32((uint32_t)lookupContext + 8);
		uint64_t keyAddress = (uint64_t)LOAD32((uint32_t)lookupContext + 12) + (uint64_t)entryValue;
		callTarget.u64 = (uint64_t)lookupFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = keyAddress;
		ctx.r5.u64 = arg4;
		ctx.r6.u64 = arg5;
		ctx.r7.u64 = arg5;
		ctx.r8.u64 = scratch;
		ctx.r9.u64 = lookupFn;
		ctx.r10.u64 = entryValue;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t lookupResult = ctx.r3.u64;
		flags.ca = ctx.xer.ca;
		LookAtHandle_CopyConstruct(ctx, base, entityHandleAddr, lookupResult);
		flags.ca = ctx.xer.ca;
		entityHandle->m_18 = LOAD32((uint32_t)lookupResult + 24);
		LookAtHandle_Destruct(ctx, base, stack + 96);
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return entityHandleAddr;
	}

	entityHandle->m_4 = 0;
	uint32_t counterAddr = uint32_t(g_83496EB8);
	entityHandle->vtable = 0x820F1664u;
	entityHandle->m_8 = 0;
	entityHandle->m_C = 0;
	entityHandle->m_10 = 0;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		uint32_t savedLock = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedMsrBits & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
		int32_t incremented = __builtin_bswap32(ctx.reserved.u32) + 1;
		compare0.lt = 0;
		compare0.gt = 0;
		compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(counterAddr)), ctx.reserved.s32, __builtin_bswap32(incremented));
		compare0.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedLock & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!compare0.eq);
	uint32_t statsBase = uint32_t(g_83490000);
	entityHandle->m_14 = 0;
	entityHandle->m_18 = 0;
	uint32_t createdCount = LOAD32(statsBase + 27288);
	STORE32(statsBase + 27288, createdCount + 1);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = lookupContext;
	return entityHandleAddr;
}
PROMOTED_ENTRY(47, sub_82706348, 0x82706348) { ctx.r3.u64 = n_sub_82706348(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_82706550(CpuState& ctx, uint8_t* base, uint64_t entityHandleAddr, uint64_t lookupContext, uint32_t lookupContainer, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(47, 0x82706550)) { ctx.r3.u64 = entityHandleAddr; ctx.r4.u64 = lookupContext; ctx.r5.u64 = lookupContainer; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_82706550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82706550);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u32;
	PPCCRRegister compare0{};
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, entityHandleAddr);
	stack = PushStackFrame(base, stack, 176);

	// Look up the entry for key 44 in the lookup structure passed as lookupContainer.
	uint32_t entryValue = 0;
	bool haveEntry = false;
	if (lookupContainer != 0 && (LOAD8((uint32_t)lookupContainer + 0x90) & 0x40) != 0) {
		uint32_t container = lookupContainer;
		if ((LOAD32(container + 0x28) >> 12) & 1) {
			uint32_t table = LOAD32(container + 0x8C);
			if (table != 0) {
				uint32_t index = LOAD8(table + 0x2C);
				entryValue = LOAD32(LOAD32(container + 0x48) + index * 8 + 4);
				haveEntry = true;
			} else {
				uint32_t begin = LOAD32(container + 0x48);
				uint32_t end = LOAD32(container + 0x4C);
				uint32_t iter = begin;
				STORE32(stack + 80, 0);
				STORE32(stack + 84, iter);
				int32_t byteCount = (int32_t)(end - begin);
				flags.ca = byteCount < 0 & (byteCount & 0x7) != 0;
				int32_t count = byteCount >> 3;
				if (count > 0) {
					// lower_bound: first element whose key is not less than 44
					do {
						flags.ca = count < 0 & (count & 1) != 0;
						int32_t step = count >> 1;
						uint32_t probe = iter + uint32_t(step) * 8;
						if ((int32_t)LOAD32(probe) < 44) {
							iter = probe + 8;
							count = count - step - 1;
						} else {
							count = step;
						}
					} while (count > 0);
					STORE32(stack + 84, iter);
				}
				if (iter != end) {
					compare6.compare<int32_t>(int32_t(LOAD32(iter)), 44, flags);
					if (compare6.gt) {
						entryValue = LOAD32(end + 4);
					} else {
						STORE64(stack + 80, LOAD64(stack + 80));
						entryValue = LOAD32(LOAD32(stack + 84) + 4);
					}
				} else {
					entryValue = LOAD32(end + 4);
				}
				haveEntry = true;
			}
		}
	}

	if (!haveEntry) {
		entityHandle->m_4 = 0;
		uint32_t counterAddr = (uint32_t)g_83496EB8;
		entityHandle->vtable = 0x820F1664u;
		entityHandle->m_8 = 0;
		entityHandle->m_C = 0;
		entityHandle->m_10 = 0;
		uint32_t frameAddr{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
			uint32_t counterValue = __builtin_bswap32(ctx.reserved.u32);
			counterValue = (int32_t)counterValue + 1;
			frameAddr = counterAddr;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)counterValue));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		uint32_t refCountAddr = (uint32_t)g_83490000 + 27288;
		entityHandle->m_14 = 0;
		entityHandle->m_18 = 0;
		uint32_t refCount = LOAD32(refCountAddr);
		refCount = (int32_t)refCount + 1;
		STORE32(refCountAddr, refCount);
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = lookupContext;
		return entityHandleAddr;
	}

	uint32_t fnPtr = LOAD32((uint32_t)lookupContext + 8);
	uint64_t handleOut = (uint64_t)stack + 96;
	uint64_t entryAddr = (uint64_t)LOAD32((uint32_t)lookupContext + 12) + (uint64_t)entryValue;
	callTarget.u64 = fnPtr;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = handleOut;
	ctx.r4.u64 = entryAddr;
	ctx.r5.u64 = arg4;
	ctx.r6.u64 = arg5;
	ctx.r7.u64 = arg6;
	ctx.r8.u64 = arg6;
	ctx.r9.u64 = fnPtr;
	ctx.r10.u64 = entryValue;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t tempHandle = ctx.r3.u64;
	LookAtHandle_CopyConstruct(ctx, base, entityHandleAddr, tempHandle);
	entityHandle->m_18 = LOAD32((uint32_t)tempHandle + 24);
	LookAtHandle_Destruct(ctx, base, handleOut);
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return entityHandleAddr;
}
PROMOTED_ENTRY(47, sub_82706550, 0x82706550) { ctx.r3.u64 = n_sub_82706550(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_8279C730  [460 bytes]
uint64_t n_sub_8279C730(CpuState& ctx, uint8_t* base, uint64_t resultHandleAddr, uint64_t typeFactory, uint64_t typeMap) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(52, 0x8279C730)) { ctx.r3.u64 = resultHandleAddr; ctx.r4.u64 = typeFactory; ctx.r5.u64 = typeMap; __imp__sub_8279C730(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279C730);
	uint32_t stack = ctx.r1.u64;
	uint64_t argReg6 = ctx.r6.u64;
	uint64_t argReg7 = ctx.r7.u64;
	uint64_t argReg8 = ctx.r8.u64;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, resultHandleAddr);
	stack = PushStackFrame(base, stack, 128);

	// r6/r7/r8 are live on entry and are handed to the virtual call below; the sorted-map
	// lookup reuses r6 as the end pointer and r7/r8 as scratch.
	bool found = false;
	uint32_t mapValue = 0;
	if ((uint32_t)typeMap != 0 && (LOAD8((uint32_t)typeMap + 144) & 64) != 0) {
		if (((LOAD32((uint32_t)typeMap + 40) >> 2) & 1) != 0) {
			uint32_t cachedNode = LOAD32((uint32_t)typeMap + 140);
			if (cachedNode != 0) {
				uint32_t entry = LOAD32((uint32_t)typeMap + 72) + (uint32_t)LOAD8(cachedNode + 34) * 8;
				found = true;
				mapValue = LOAD32(entry + 4);
			} else {
				uint32_t begin = LOAD32((uint32_t)typeMap + 72);
				uint32_t end = LOAD32((uint32_t)typeMap + 76);
				argReg6 = end;
				uint32_t cursor = begin;
				STORE32(stack + 80, 0);
				int32_t remaining = (int32_t)(end - begin);
				STORE32(stack + 84, begin);
				flags.ca = (remaining < 0) & ((remaining & 0x7) != 0);
				remaining = remaining >> 3;
				if (remaining > 0) {
					do {
						flags.ca = (remaining < 0) & ((remaining & 0x1) != 0);
						int32_t half = remaining >> 1;
						argReg8 = (uint32_t)half << 3;
						cursor = (uint32_t)argReg8 + cursor;
						compare6.compare<int32_t>(int32_t(LOAD32(cursor)), 34, flags);
						argReg7 = compare6.lt ? 1 : 0;
						if (argReg7 != 0) {
							remaining = remaining - half - 1;
							cursor = cursor + 8;
						} else {
							cursor = cursor - (uint32_t)argReg8;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, cursor);
				}
				found = true;
				if (cursor != end) {
					compare6.compare<int32_t>(int32_t(LOAD32(cursor)), 34, flags);
					if (!compare6.gt) {
						STORE64(stack + 80, LOAD64(stack + 80));
						mapValue = LOAD32(LOAD32(stack + 84) + 4);
					} else {
						mapValue = LOAD32(end + 4);
					}
				} else {
					mapValue = LOAD32(end + 4);
				}
			}
		}
	}
	if (!found) {
		entityHandle->m_4 = 0;
		entityHandle->m_8 = 0xFFFFFFFFu;
		entityHandle->vtable = 0x820F1664u;
	} else {
		uint32_t valueOffset = LOAD32((uint32_t)typeFactory + 20);
		uint32_t factoryCall = LOAD32((uint32_t)typeFactory + 16);
		callTarget.u64 = factoryCall;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = (uint64_t)stack + 80;
		ctx.r4.u64 = (uint64_t)valueOffset + mapValue;
		ctx.r8.u64 = argReg8;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t created = ctx.r3.u64;
		flags.ca = ctx.xer.ca;
		EntityHandle_CopyConstruct(ctx, base, resultHandleAddr, created);
		flags.ca = ctx.xer.ca;
		uint32_t entityId = LOAD32(created + 8);
		uint32_t vtableBase = (uint32_t)g_820F0000;
		uint32_t tempVtable = vtableBase + 5732;
		STORE32(stack + 80, tempVtable);
		entityHandle->m_8 = entityId;
		EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
		typeFactory = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = typeFactory;
	return resultHandleAddr;
}
PROMOTED_ENTRY(52, sub_8279C730, 0x8279C730) { ctx.r3.u64 = n_sub_8279C730(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_8297BCA8  [148 bytes]
uint64_t n_sub_8297BCA8(CpuState& ctx, uint8_t* base, uint64_t resultHandleAddr, uint64_t actionManager, uint64_t owner, uint64_t arg4) {
	if (!UseLiftedCode(68, 0x8297BCA8)) { ctx.r3.u64 = resultHandleAddr; ctx.r4.u64 = actionManager; ctx.r5.u64 = owner; ctx.r6.u64 = arg4; __imp__sub_8297BCA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BCA8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, resultHandleAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t target = LOAD32((uint32_t)owner + 52);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	uint32_t canInterrupt = CECActionManagerSimple_CanInterruptCurrentAction(ctx, base, actionManager, target, arg4);
	if ((canInterrupt & 0xFF) != 0) {
		// Ask the owner object (virtual call, vtable slot at +0x10) to produce a handle
		// in the caller-provided return buffer at stack+80.
		uint32_t handleBuffer = (uint32_t)stack + 80;
		uint32_t virtualMethod = LOAD32(LOAD32((uint32_t)owner) + 16);
		callTarget.u64 = virtualMethod;
		ctx.r3.u64 = handleBuffer;
		ctx.r4.u64 = owner;
		ctx.r10.u64 = virtualMethod;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t returnedHandle = ctx.r3.u64;
		n_sub_822A4648(ctx, base, resultHandleAddr, actionManager, returnedHandle, 0);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return resultHandleAddr;
	}
	entityHandle->m_4 = 0u;
	entityHandle->vtable = 0x820F1664u;
	entityHandle->m_8 = 0xFFFFFFFFu;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return resultHandleAddr;
}
PROMOTED_ENTRY(68, sub_8297BCA8, 0x8297BCA8) { ctx.r3.u64 = n_sub_8297BCA8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_8297BDF8  [340 bytes]
uint64_t n_sub_8297BDF8(CpuState& ctx, uint8_t* base, uint64_t resultHandleAddr, uint64_t actionManagerAddr, uint64_t actionOwnerAddr, uint64_t arg4) {
	if (!UseLiftedCode(68, 0x8297BDF8)) { ctx.r3.u64 = resultHandleAddr; ctx.r4.u64 = actionManagerAddr; ctx.r5.u64 = actionOwnerAddr; ctx.r6.u64 = arg4; __imp__sub_8297BDF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8297BDF8);
	uint32_t casAddr{};
	uint32_t stack = ctx.r1.u64;
	uint32_t lockMsrBits = ctx.r13.u64;
	uint64_t savedR9{};
	uint32_t newRefCount{};
	PPCCRRegister compare0{};
	PPCRegister callTarget{};
	EntityHandle* entityHandle = GameObject<EntityHandle>(base, resultHandleAddr);

	stack = PushStackFrame(base, stack, 128);

	// Copy the shared handle held at stack+80 to stack+88 and take a reference on the object it refers to.
	auto copyAndAddReference = [&]() {
		uint32_t refCount = LOAD32(stack + 84);
		uint32_t objectPtr = LOAD32(stack + 80);
		STORE32(stack + 92, refCount);
		STORE32(stack + 88, objectPtr);
		if (refCount != 0) {
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				savedR9 = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockMsrBits & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(refCount);
				newRefCount = __builtin_bswap32(ctx.reserved.u32);
				newRefCount = (int32_t)newRefCount + 1;
				casAddr = refCount;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)savedR9 & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
		}
	};

	uint32_t actionOwnerDefinition = LOAD32((uint32_t)actionOwnerAddr + 0x34);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg4;
	uint32_t canInterruptCurrentAction = CECActionManagerSimple_CanInterruptCurrentAction(ctx, base, actionManagerAddr, actionOwnerDefinition, arg4);

	if ((canInterruptCurrentAction & 0xFF) == 0) {
		entityHandle->m_4 = 0u;
		entityHandle->vtable = 0x820F1664u;
		entityHandle->m_8 = 0xFFFFFFFFu;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return resultHandleAddr;
	}

	uint64_t sharedHandleAddr = (uint64_t)stack + 80;
	uint32_t getMethod = LOAD32(LOAD32((uint32_t)actionOwnerAddr) + 0x10);
	callTarget.u64 = getMethod;
	ctx.r3.u64 = sharedHandleAddr;
	ctx.r4.u64 = actionOwnerAddr;
	ctx.r10.u64 = getMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	savedR9 = ctx.r9.u64;

	bool actionHandled = false;
	uint32_t currentAction = LOAD32((uint32_t)actionManagerAddr + 0x10);
	if (currentAction != 0) {
		copyAndAddReference();
		uint64_t targetHandleAddr = (uint64_t)stack + 88;
		uint32_t handleMethod = LOAD32(LOAD32(currentAction) + 0x30);
		callTarget.u64 = handleMethod;
		ctx.r3.u64 = currentAction;
		ctx.r4.u64 = targetHandleAddr;
		ctx.r9.u64 = savedR9;
		ctx.r10.u64 = handleMethod;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t handled = ctx.r3.u32;
		savedR9 = ctx.r9.u64;
		actionHandled = handled != 0;
	}

	if (actionHandled) {
		C_820F1664_Constructor(ctx, base, resultHandleAddr, LOAD32((uint32_t)actionManagerAddr + 4), LOAD32(LOAD32((uint32_t)actionManagerAddr + 0x10) + 0x3C));
	} else {
		copyAndAddReference();
		ctx.r9.u64 = savedR9;
		n_sub_822A4648(ctx, base, resultHandleAddr, actionManagerAddr, (uint64_t)stack + 88, 0);
	}

	SharedHandle_Release(ctx, base, sharedHandleAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return resultHandleAddr;
}
PROMOTED_ENTRY(68, sub_8297BDF8, 0x8297BDF8) { ctx.r3.u64 = n_sub_8297BDF8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }
