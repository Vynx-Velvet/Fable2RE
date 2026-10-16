// CObjectBase (vtable 0x820F3A24): methods of the class as readable C++.
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

uint32_t CObjectBase_ReleaseHandles(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(7, 0x8223CF20)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_8223CF20(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8223CF20);
	uint32_t stack = ctx.r1.u64;
	// cr0 and xer.ca as the original loop counter leaves them: handed to the callee and read by callers
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 128);
	objectBase->vtable = 0x820F5D4Cu;

	// 15 slots of 16 bytes below +4140, last slot first: free each slot's handle and clear its first three words
	uint32_t handleSlot = objectBaseAddr + 4140;
	uint32_t lastResult = 0;
	int32_t remaining = 14;
	do {
		handleSlot -= 16;
		uint32_t handle = LOAD32(handleSlot);
		lastResult = handle;
		if (handle != 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			lastResult = HandleTarget_Free(ctx, base, handle);
		}
		flags.ca = remaining != 0;
		--remaining;
		compare0.compare<int32_t>(remaining, 0, flags);
		STORE32(handleSlot, 0);
		STORE32(handleSlot + 4, 0);
		STORE32(handleSlot + 8, 0);
	} while (remaining >= 0);

	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read cr0 and xer.ca after the call
	ctx.cr0 = compare0;
	ctx.xer.ca = flags.ca;
	return lastResult;
}
PROMOTED_ENTRY(7, sub_8223CF20, 0x8223CF20) { ctx.r3.u64 = CObjectBase_ReleaseHandles(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8241E5A0(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(24, 0x8241E5A0)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8241E5A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8241E5A0);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_82517EF0(ctx, base, objectBaseAddr + 8);
	objectBase->vtable = 0x820F3A24u;
	// bit 0: also free the object itself
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectBaseAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectBaseAddr;
}
PROMOTED_ENTRY(24, sub_8241E5A0, 0x8241E5A0) { ctx.r3.u64 = n_sub_8241E5A0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82514430(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(31, 0x82514430)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82514430(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82514430);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);

	// the block at +40 holds a range: its start pointer at +4 (m_2C, an allocation) and its end at +8.
	// Hand the range to n_sub_8243B230, free the allocation, then clear the words at +4..+12.
	uint32_t rangeRecordAddr = objectBaseAddr + 40;
	uint32_t result = objectBaseAddr;
	uint32_t rangeBegin = objectBase->m_2C;
	if (rangeBegin != 0) {
		uint32_t rangeEnd = LOAD32(rangeRecordAddr + 8);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = rangeRecordAddr;
		n_sub_8243B230(ctx, base, rangeBegin, rangeEnd);
		result = HandleTarget_Free(ctx, base, LOAD32(rangeRecordAddr + 4));
	}
	STORE32(rangeRecordAddr + 4, 0);
	STORE32(rangeRecordAddr + 8, 0);
	STORE32(rangeRecordAddr + 12, 0);
	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_82514430, 0x82514430) { ctx.r3.u64 = n_sub_82514430(ctx, base, ctx.r3.u32); }

uint32_t n_sub_82514598(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(31, 0x82514598)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82514598(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82514598);
	uint32_t stack = ctx.r1.u64;
	uint32_t lockMsrBits = ctx.r13.u32;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);

	// Atomically decrement the reference count at refCountAddr and return the new count.
	auto releaseRefCount = [&](uint32_t refCountAddr) -> uint32_t {
		uint32_t newCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsrBits & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32(newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		return newCount;
	};

	// m_1C and m_18 each point to a counted object (count at +4); when the count reaches zero its virtual
	// slot 1 is called
	uint32_t firstRef = objectBase->m_1C;
	if (firstRef != 0) {
		uint64_t refCountAddr = uint64_t(firstRef) + 4;
		if (releaseRefCount(uint32_t(refCountAddr)) == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(firstRef) + 4);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r3.u64 = firstRef;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(releaseFunc);
		}
		objectBase->m_1C = 0;
	}

	// returns m_18, or what its release call returned
	uint32_t secondRef = objectBase->m_18;
	uint32_t result = secondRef;
	if (secondRef != 0) {
		uint64_t refCountAddr = uint64_t(secondRef) + 4;
		if (releaseRefCount(uint32_t(refCountAddr)) == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(secondRef) + 4);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r3.u64 = secondRef;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(releaseFunc);
			result = ctx.r3.u32;
		}
		objectBase->m_18 = 0;
	}

	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(31, sub_82514598, 0x82514598) { ctx.r3.u64 = n_sub_82514598(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82515C60(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint32_t sourceAddr) {
	if (!UseLiftedCode(31, 0x82515C60)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = sourceAddr; __imp__sub_82515C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82515C60);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 96);

	// copy-construct from the object at sourceAddr: the base-class part (vtable 0x820F3A24, +4) first, then
	// this class's vtable, the words at +8..+36 and the part at +40
	objectBase->vtable = 0x820F3A24u;
	objectBase->m_4 = LOAD32(sourceAddr + 4);
	objectBase->vtable = 0x820BC520u;
	objectBase->m_8 = LOAD32(sourceAddr + 8);
	objectBase->m_C = LOAD32(sourceAddr + 12);
	uint32_t source10 = LOAD32(sourceAddr + 16);
	objectBase->m_10 = source10;
	uint32_t source14 = LOAD32(sourceAddr + 20);
	objectBase->m_14 = source14;
	uint32_t source18 = LOAD32(sourceAddr + 24);
	objectBase->m_18 = source18;
	uint32_t source1C = LOAD32(sourceAddr + 28);
	objectBase->m_1C = source1C;
	objectBase->m_20 = LOAD32(sourceAddr + 32);
	objectBase->m_24 = LOAD32(sourceAddr + 36);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = source1C;
	ctx.r6.u64 = source18;
	ctx.r7.u64 = source14;
	n_sub_82517FC0(ctx, base, objectBaseAddr + 40, sourceAddr + 40, source10);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return objectBaseAddr;
}
PROMOTED_ENTRY(31, sub_82515C60, 0x82515C60) { ctx.r3.u64 = n_sub_82515C60(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_8272C918(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(49, 0x8272C918)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8272C918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272C918);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_82A773E0(ctx, base, objectBaseAddr + 24);
	objectBase->vtable = 0x820F3A24u;
	// bit 0: also free the object itself
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectBaseAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectBaseAddr;
}
PROMOTED_ENTRY(49, sub_8272C918, 0x8272C918) { ctx.r3.u64 = n_sub_8272C918(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8272C978(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(49, 0x8272C978)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8272C978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8272C978);
	uint32_t stack = ctx.r1.u64;
	uint32_t lockMsrBits = ctx.r13.u32;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 128);
	// r4 as each call leaves it: handed to the next call and read by callers after the return
	uint64_t passR4 = deleteFlags;

	// the block at +32 holds an allocation at +4 (m_24): free it, then clear the words at +4..+12
	uint32_t bufferRecordAddr = uint32_t(objectBaseAddr) + 32;
	uint32_t allocation = objectBase->m_24;
	if (allocation != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = passR4;
		HandleTarget_Free(ctx, base, allocation);
		passR4 = ctx.r4.u64;
	}
	STORE32(bufferRecordAddr + 4, 0);
	STORE32(bufferRecordAddr + 8, 0);
	STORE32(bufferRecordAddr + 12, 0);

	// m_18 points to a counted object (count at +4): drop one reference atomically; at zero, call its
	// virtual slot 1
	uint32_t refObject = objectBase->m_18;
	if (refObject != 0) {
		uint64_t refCountAddr = uint64_t(refObject) + 4;
		uint32_t newCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsrBits & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)refCountAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)refCountAddr)), ctx.reserved.s32, __builtin_bswap32(newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		if (newCount == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(refObject) + 4);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r3.u64 = refObject;
			ctx.r4.u64 = passR4;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(releaseFunc);
			passR4 = ctx.r4.u64;
		}
		objectBase->m_18 = 0;
	}

	objectBase->vtable = 0x820F3A24u;
	// bit 0: also free the object itself
	if ((deleteFlags & 0x1) != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = passR4;
		HandleTarget_Free(ctx, base, objectBaseAddr);
		passR4 = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = passR4;
	return objectBaseAddr;
}
PROMOTED_ENTRY(49, sub_8272C978, 0x8272C978) { ctx.r3.u64 = n_sub_8272C978(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82A39648(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(74, 0x82A39648)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82A39648(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A39648);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t result = objectBaseAddr;
	uint32_t buffer = objectBase->m_10;
	objectBase->vtable = 0x820F37E8u;
	if (buffer != 0) {
		// the word 8 bytes before the buffer holds its offset from the start of the allocation, which is freed
		uint64_t allocationBase = (uint64_t)buffer - (uint64_t)LOAD32(buffer - 8);
		ctx.r1.u64 = stack;
		result = HandleTarget_Free(ctx, base, allocationBase);
		objectBase->m_10 = 0u;
	}
	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(74, sub_82A39648, 0x82A39648) { ctx.r3.u64 = n_sub_82A39648(ctx, base, ctx.r3.u32); }

uint64_t CObjectBase_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t flags) {
	if (!UseLiftedCode(74, 0x82A44E08)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = flags; __imp__sub_82A44E08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A44E08);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 96);
	// r4 value passed to the free call and left for callers after the return
	uint64_t passR4 = flags;
	objectBase->vtable = 0x820F3A24u;
	if ((flags & 0x1) != 0) {
		// bit 0: also free the object itself
		ctx.r1.u64 = stack;
		ctx.r4.u64 = passR4;
		HandleTarget_Free(ctx, base, objectBaseAddr);
		passR4 = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = passR4;
	return objectBaseAddr;
}
PROMOTED_ENTRY(74, sub_82A44E08, 0x82A44E08) { ctx.r3.u64 = CObjectBase_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82A49DE8(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(74, 0x82A49DE8)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82A49DE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A49DE8);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t handle2C = objectBase->m_2C;
	if (handle2C != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, handle2C);
	}

	objectBase->m_2C = 0;
	STORE32(objectBaseAddr + 0x30, 0);
	STORE32(objectBaseAddr + 0x34, 0);

	uint64_t handle1C = objectBase->m_1C;
	if ((uint32_t)handle1C != 0) {
		ctx.r1.u64 = stack;
		handle1C = HandleTarget_Free(ctx, base, handle1C);
	}

	objectBase->m_1C = 0;
	STORE32(objectBaseAddr + 0x20, 0);
	STORE32(objectBaseAddr + 0x24, 0);
	objectBase->vtable = 0x820F3A24u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)handle1C;
}
PROMOTED_ENTRY(74, sub_82A49DE8, 0x82A49DE8) { ctx.r3.u64 = n_sub_82A49DE8(ctx, base, ctx.r3.u32); }

uint32_t n_sub_82A4EE10(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(75, 0x82A4EE10)) { ctx.r3.u64 = objectBaseAddr; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82A4EE10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A4EE10);
	uint32_t stack = ctx.r1.u64;

	uint32_t objectAddr = (uint32_t)objectBaseAddr;

	stack = PushStackFrame(base, stack, 128);
	STORE32(objectAddr, 0x820F5F04u); // vtable

	ctx.r1.u64 = stack;
	n_sub_82A4EF80(ctx, base, objectBaseAddr, arg2, arg3);

	uint32_t handle = LOAD32(objectAddr + 0xE64);
	if (handle != 0) {
		n_sub_82AABF18(ctx, base, handle, ctx.r7.u64);
		HandleTarget_Free(ctx, base, handle);
	}
	STORE32(objectAddr + 0xE64, 0);

	handle = LOAD32(objectAddr + 0xE60);
	if (handle != 0) {
		n_sub_82AB0A68(ctx, base, handle, ctx.r7.u64, ctx.r8.u64);
		HandleTarget_Free(ctx, base, handle);
	}
	STORE32(objectAddr + 0xE60, 0);

	handle = LOAD32(objectAddr + 0xE5C);
	if (handle != 0) {
		uint32_t element = handle + 0x1C40;
		for (int32_t i = 15; i >= 0; --i) {
			element -= 0x1C0;
			n_sub_82AAF558(ctx, base, element);
		}
		uint32_t nested = LOAD32(handle + 28);
		if (nested != 0) {
			HandleTarget_Free(ctx, base, (uint64_t)nested - (uint64_t)LOAD32(nested - 8));
		}
		HandleTarget_Free(ctx, base, handle);
	}
	STORE32(objectAddr + 0xE5C, 0);

	n_sub_82A4F758(ctx, base, objectAddr + 0xD54 + 20);
	n_sub_82A4F758(ctx, base, objectAddr + 0xD54);

	handle = LOAD32(objectAddr + 0xD50);
	if (handle != 0) {
		n_sub_82A4BC60(ctx, base, handle);
		HandleTarget_Free(ctx, base, handle);
	}
	STORE32(objectAddr + 0xD50, 0);

	handle = LOAD32(objectAddr + 0xD4C);
	if (handle != 0) {
		n_sub_82AA9438(ctx, base, handle, ctx.r7.u64, ctx.r8.u64);

		uint32_t inner = LOAD32(handle + 20);
		if (inner != 0) {
			uint32_t destructor = LOAD32(LOAD32(inner) + 8);
			ctx.r3.u64 = inner;
			ctx.r10.u64 = destructor;
			REX_CALL_INDIRECT_FUNC(destructor);
		}
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)handle + 16);
		HandleTarget_Free(ctx, base, handle);
	}
	STORE32(objectAddr + 0xD4C, 0);

	uint64_t freedHandle = 0;
	uint32_t slot = objectAddr + 0xD20 + 4;
	for (int32_t i = 14; i >= 0; --i) {
		slot -= 16;
		freedHandle = LOAD32(slot);
		if ((uint32_t)freedHandle != 0) {
			freedHandle = HandleTarget_Free(ctx, base, freedHandle);
		}
		STORE32(slot, 0);
		STORE32(slot + 4, 0);
		STORE32(slot + 8, 0);
	}

	STORE32(objectAddr, 0x820F3A24u); // vtable
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)freedHandle;
}
PROMOTED_ENTRY(75, sub_82A4EE10, 0x82A4EE10) { ctx.r3.u64 = n_sub_82A4EE10(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t n_sub_82A4EF80(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t g_82090000 = int32_t(0x82090000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(75, 0x82A4EF80)) { ctx.r3.u64 = objectBaseAddr; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82A4EF80(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A4EF80);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 144);

	// Tear down the structure stored at 0xE60.
	uint32_t oldE60 = objectBase->m_E60;
	if (oldE60 != 0) {
		ctx.r1.u64 = stack;
		n_sub_82AB0A68(ctx, base, oldE60, arg2, arg3);
		HandleTarget_Free(ctx, base, oldE60);
		arg2 = ctx.r7.u64;
		arg3 = ctx.r8.u64;
	}
	objectBase->m_E60 = 0u;

	// Build the replacement object at 0xE5C.
	ctx.r1.u64 = stack;
	ctx.r7.u64 = arg2;
	ctx.r8.u64 = arg3;
	uint64_t newObject = operator_new(ctx, base, 7728);

	uint32_t newE5C = 0;
	if ((uint32_t)newObject != 0) {
		uint32_t constAddr = (uint32_t)g_82090000 + 24732;
		ctx.fpscr.disableFlushMode();
		double constructorValue = double(LOAD_F32(constAddr));
		STORE_F32(stack + 80, float(double(LOAD_F32(constAddr + 13336))));
		scratch.u32 = stack + 80;
		PPCVRegister vec;
		SET_V8(vec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vec, simde_mm_shuffle_epi32(V8(vec), 0xFF));
		ctx.r9.u64 = uint64_t(g_82090000 + 24732);
		ctx.f1.f64 = constructorValue;
		ctx.v1 = vec;
		newE5C = n_sub_82AAF5A0(ctx, base, newObject);
	}

	// Destroy the old structure at 0xE5C and install the new one.
	uint32_t oldE5C = objectBase->m_E5C;
	if (oldE5C != 0) {
		uint32_t element = oldE5C + 7232;
		int32_t remaining = 15;
		do {
			element -= 448;
			n_sub_82AAF558(ctx, base, element);
			remaining -= 1;
		} while (remaining >= 0);
		uint32_t allocated = LOAD32(oldE5C + 28);
		if (allocated != 0) {
			HandleTarget_Free(ctx, base, (uint64_t)allocated - (uint64_t)LOAD32(allocated - 8));
		}
		HandleTarget_Free(ctx, base, oldE5C);
	}
	objectBase->m_E5C = newE5C;

	uint32_t arrayAddr = objectBaseAddr + 3412;
	n_sub_82A4F3E0(ctx, base, objectBaseAddr, ctx.r7.u64);
	uint32_t r9Value = ctx.r9.u64;
	uint32_t loopValue = 0;

	// Walk the 48 slots of the sorted array and delete every entry they still hold.
	for (uint32_t i = 0; i < 48; ++i) {
		loopValue = i;
		uint32_t slot = SortedArray_Find(ctx, base, arrayAddr, loopValue);
		r9Value = ctx.r9.u64;

		for (;;) {
			uint32_t begin = LOAD32(slot + 8);
			if (begin == 0) break;
			uint32_t end = LOAD32(slot + 12);
			if (((int32_t)(end - begin) >> 2) == 0) break;
			uint32_t start = LOAD32(slot + 8);
			if (start == 0) ppc_trap(ctx, base, 22);
			r9Value = end - start;
			if (((int32_t)r9Value >> 2) == 0) ppc_trap(ctx, base, 22);
			uint32_t entry = LOAD32(start);
			if (entry == 0) continue;
			uint32_t destroy = LOAD32(LOAD32(entry));
			ctx.r3.u64 = entry;
			ctx.r4.u64 = 1;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = destroy;
			REX_CALL_INDIRECT_FUNC(destroy);
			loopValue = ctx.r4.u64;
			r9Value = ctx.r9.u64;
		}
	}

	ctx.r4.u64 = loopValue;
	ctx.r9.u64 = r9Value;
	uint32_t newTarget = Heap_Alloc(ctx, base, 4416);

	uint32_t target;
	if ((uint32_t)newTarget != 0) {
		target = n_sub_82AAB938(ctx, base, newTarget, objectBase->m_E5C);
	} else {
		uint32_t badAllocHandler = LOAD32(0x83496D9Cu);
		if (badAllocHandler != 0) {
			ctx.r3.u64 = newTarget;
			ctx.r4.u64 = 0;
			ctx.r10.u64 = badAllocHandler;
			REX_CALL_INDIRECT_FUNC(badAllocHandler);
			newTarget = ctx.r3.u64;
			badAllocHandler = ctx.r10.u64;
		}
		ctx.r3.u64 = newTarget;
		ctx.r10.u64 = badAllocHandler;
		ThrowBadAlloc(ctx, base);
		target = 0;
	}

	uint32_t oldE64 = objectBase->m_E64;
	if (oldE64 != 0) {
		n_sub_82AABF18(ctx, base, oldE64, ctx.r7.u64);
		HandleTarget_Free(ctx, base, oldE64);
	}
	objectBase->m_E64 = target;
	n_sub_82A7F580(ctx, base, arrayAddr);

	STORE32(stack + 80, uint32_t(objectBase->m_8));
	uint32_t mapRoot = LOAD32((uint32_t)g_834A0000 - 2364);
	uint32_t node = mapRoot + 4;
	uint32_t r4Value = node;
	uint32_t result = stack + 88;
	n_sub_82193398(ctx, base, result, r4Value, stack + 80);

	uint32_t found = LOAD32(stack + 88);
	uint32_t endMarker = LOAD32(node + 4);
	if (found == 0 || found != node) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t key = LOAD32(stack + 92);
	if (key != endMarker) {
		if (found == 0) ppc_trap(ctx, base, 22);
		if (key == LOAD32(found + 4)) ppc_trap(ctx, base, 22);
		ctx.r9.u64 = key;
		result = n_sub_82B4CDE0(ctx, base, stack + 88, node, LOAD64(stack + 88), ctx.r8.u64);
		r4Value = ctx.r4.u64;
		key = ctx.r9.u64;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r9.u64 = key;
	return result;
}
PROMOTED_ENTRY(75, sub_82A4EF80, 0x82A4EF80) { ctx.r3.u64 = n_sub_82A4EF80(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_82A76470  [96 bytes]
uint32_t n_sub_82A76470(CpuState& ctx, uint8_t* base, uint32_t objectBaseAddr) {
	if (!UseLiftedCode(76, 0x82A76470)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82A76470(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A76470);
	uint32_t stack = ctx.r1.u64;
	uint64_t handle{};
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t tailAddr = objectBaseAddr + 16;
	handle = objectBase->m_14;
	if ((uint32_t)handle != 0) {
		ctx.r1.u64 = stack;
		handle = HandleTarget_Free(ctx, base, handle);
	}
	STORE32(tailAddr + 4, 0);
	STORE32(tailAddr + 8, 0);
	STORE32(tailAddr + 12, 0);
	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return handle;
}
PROMOTED_ENTRY(76, sub_82A76470, 0x82A76470) { ctx.r3.u64 = n_sub_82A76470(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82B1F1D8(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t arg2) {
	if (!UseLiftedCode(82, 0x82B1F1D8)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = arg2; __imp__sub_82B1F1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B1F1D8);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t deleteFlags = arg2;
	uint32_t subObjectAddr = objectBaseAddr + 28;
	uint32_t handleVectorAddr = objectBaseAddr + 8;

	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	n_sub_82A99C70(ctx, base, subObjectAddr);
	SharedHandleVector_Clear(ctx, base, handleVectorAddr);
	objectBase->vtable = 0x820F3A24u;

	uint64_t result = objectBaseAddr;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = objectBaseAddr;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(82, sub_82B1F1D8, 0x82B1F1D8) { ctx.r3.u64 = n_sub_82B1F1D8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82B22600(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint32_t arg2) {
	if (!UseLiftedCode(82, 0x82B22600)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = arg2; __imp__sub_82B22600(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B22600);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 128);

	// Three tracked sub-objects sitting right before the object's tail block.
	uint32_t entryAddr = (uint32_t)objectBaseAddr + 88;
	for (int32_t slot = 2; slot >= 0; --slot) {
		entryAddr -= 16;
		if (LOAD32(entryAddr + 4) != 0) {
			ctx.r1.u64 = stack;
			n_sub_82B22C18(ctx, base, LOAD32(entryAddr + 4), LOAD32(entryAddr + 8));
			uint32_t releasedHandle = LOAD32(entryAddr + 4);
			HandleTarget_Free(ctx, base, releasedHandle);
		}
		STORE32(entryAddr + 4, 0);
		STORE32(entryAddr + 8, 0);
		STORE32(entryAddr + 12, 0);
	}

	uint32_t tailHandle = objectBase->m_1C;
	if (tailHandle != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, tailHandle);
	}
	uint32_t tailAddr = (uint32_t)objectBaseAddr + 24;
	STORE32(tailAddr + 4, 0);
	STORE32(tailAddr + 8, 0);
	STORE32(tailAddr + 12, 0);

	ctx.r1.u64 = stack;
	n_sub_8246D1F0(ctx, base, (uint32_t)objectBaseAddr + 8);
	objectBase->vtable = 0x820F3A24u;

	uint64_t result = objectBaseAddr;
	if ((arg2 & 0x1) != 0) {
		HandleTarget_Free(ctx, base, (uint32_t)result);
		result = objectBaseAddr;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(82, sub_82B22600, 0x82B22600) { ctx.r3.u64 = n_sub_82B22600(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_82B68378(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr, uint64_t flags, uint64_t arg3) {
	if (!UseLiftedCode(84, 0x82B68378)) { ctx.r3.u64 = objectBaseAddr; ctx.r4.u64 = flags; ctx.r7.u64 = arg3; __imp__sub_82B68378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82B68378);
	uint32_t stack = ctx.r1.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t memberSubobject = (uint32_t)(objectBaseAddr + 8);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	n_sub_82B5BCC0(ctx, base, memberSubobject, arg3);

	HandleTarget_Free(ctx, base, objectBase->m_C);
	objectBase->m_C = 0u;
	objectBase->vtable = 0x820F3A24u;

	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectBaseAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectBaseAddr;
}
PROMOTED_ENTRY(84, sub_82B68378, 0x82B68378) { ctx.r3.u64 = n_sub_82B68378(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64); }

uint32_t n_sub_82B6A810(CpuState& ctx, uint8_t* base, uint64_t objectBaseAddr) {
	constexpr int32_t g_834A601C = int32_t(0x834A601C);
	constexpr int32_t g_834A6028 = int32_t(0x834A6028);
	if (!UseLiftedCode(84, 0x82B6A810)) { ctx.r3.u64 = objectBaseAddr; __imp__sub_82B6A810(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82B6A810);
	uint32_t stack = ctx.r1.u64;
	uint32_t msrFromR13 = ctx.r13.u64;
	CObjectBase* objectBase = GameObject<CObjectBase>(base, objectBaseAddr);

	stack = PushStackFrame(base, stack, 160);
	objectBase->vtable = 0x820FA264u;
	uint32_t handle44 = objectBase->m_44;
	ctx.r1.u64 = stack;
	uint32_t freed44 = HandleTarget_Free(ctx, base, handle44);
	objectBase->m_44 = 0;

	// a global word read under a lock, compared with a word of the current thread block (r13 + 256 -> +332)
	ctx.r3.u64 = freed44;
	uint32_t globalWord = n_sub_82B69040(ctx, base);
	uint64_t r9Value = ctx.r9.u64;
	ctx.r3.u64 = globalWord;
	uint32_t threadWord = n_sub_8221EE38(ctx, base);

	if (threadWord != globalWord) {
		// local copy of the shared handle m_3C/m_40 at stack + 80
		uint32_t refCountAddr = objectBase->m_40;
		uint64_t r10Value = objectBase->m_3C;
		STORE32(stack + 84, refCountAddr);
		STORE32(stack + 80, (uint32_t)r10Value);
		if (refCountAddr != 0) {
			// the copy takes a reference: atomic increment of the count m_40 points to
			bool stored;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				r9Value = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrFromR13 & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
				r10Value = uint64_t(__builtin_bswap32(ctx.reserved.u32)) + 1;
				stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)r10Value));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)r9Value & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);
		}
		// lock guard at stack + 88 (String_Construct enters critical section g_834A6028; byte at +4 = held)
		ctx.r9.u64 = r9Value; // state the callee may pass on
		ctx.r10.u64 = r10Value;
		String_Construct(ctx, base, stack + 88, g_834A6028, 0);
		ctx.r4.u64 = g_834A601C; // the callee reads r4 from the state
		n_sub_82B6BF20(ctx, base, stack + 96, stack + 80, ctx.r8.u64);
		uint8_t lockHeld = LOAD8(stack + 92);
		ctx.r8.u64 = lockHeld; // state the callees below may pass on
		if (lockHeld != 0) {
			ctx.r3.u64 = LOAD32(stack + 88);
			__imp__RtlLeaveCriticalSection(ctx, base);
		}
		SharedHandle_Release(ctx, base, stack + 80);
	}

	SharedHandle_Release(ctx, base, objectBaseAddr + 60);

	uint32_t block28Addr = objectBaseAddr + 40;
	uint32_t handle2c = objectBase->m_2C;
	if (handle2c != 0) {
		HandleTarget_Free(ctx, base, handle2c);
	}
	STORE32(block28Addr + 4, 0);
	STORE32(block28Addr + 8, 0);
	STORE32(block28Addr + 12, 0);

	uint32_t block8Addr = objectBaseAddr + 8;
	uint32_t handleC = objectBase->m_C;
	uint64_t result = 0;
	if (handleC != 0) {
		result = HandleTarget_Free(ctx, base, handleC);
	}
	STORE32(block8Addr + 4, 0);
	STORE32(block8Addr + 8, 0);
	STORE32(block8Addr + 12, 0);

	objectBase->vtable = 0x820F3A24u;
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
};
PROMOTED_ENTRY(84, sub_82B6A810, 0x82B6A810) { ctx.r3.u64 = n_sub_82B6A810(ctx, base, ctx.r3.u64); }
