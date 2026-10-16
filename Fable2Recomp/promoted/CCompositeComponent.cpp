// CCompositeComponent (vtable 0x820069E8): methods of the class as readable C++.
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

uint64_t CCompositeComponent_Update(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(1, 0x82192160)) { ctx.r3.u64 = arg1; __imp__sub_82192160(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82192160);
	uint32_t stack = ctx.r1.u64;
	const uint32_t self = (uint32_t)arg1;
	const uint32_t msrBits = ctx.r13.u32;
	// Every element call receives v1 as it was on entry.
	const PPCVRegister entryV1 = ctx.v1;
	PPCVRegister savedV127 = ctx.v127;
	PPCRegister callTarget{};

	// v127 save slot below the frame; ctx.v127 itself is never changed, so nothing is restored.
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 144);

	// First virtual call, made on the component itself (vtable slot 5).
	callTarget.u64 = LOAD32(LOAD32(self) + 20);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = arg1;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	// Walk the container of shared handles embedded at self+4 (begin at +4, end at +8 within it).
	const uint32_t handleList = self + 4;
	uint32_t cachedEnd = LOAD32(handleList + 8);
	uint32_t it = LOAD32(self + 8);
	if (it > cachedEnd) {
		ppc_trap(ctx, base, 22);
	}

	while (true) {
		uint32_t end = LOAD32(handleList + 8);
		uint32_t begin = LOAD32(handleList + 4);
		if (begin > end) {
			ppc_trap(ctx, base, 22);
		}
		if (it == end) {
			break;
		}
		if (it >= cachedEnd) {
			ppc_trap(ctx, base, 22);
		}

		// Copy the element's shared handle onto the stack, taking a reference.
		uint32_t elementRef = LOAD32(it + 4);
		uint32_t elementPtr = LOAD32(it);
		STORE32(stack + 84, elementRef);
		STORE32(stack + 80, elementPtr);
		// r9 at the element call: the list begin, or the lock state when a reference was taken
		uint64_t r9Value = begin;
		if (elementRef != 0) {
			bool stored;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				r9Value = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrBits & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(elementRef);
				uint32_t incremented = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
				stored = __sync_bool_compare_and_swap(
					reinterpret_cast<uint32_t*>(RAW(elementRef)),
					ctx.reserved.s32,
					__builtin_bswap32((int32_t)incremented));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)r9Value & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);
		}

		// Virtual call on the element (vtable slot 10), then drop the stack copy of its handle.
		callTarget.u64 = LOAD32(LOAD32(elementPtr) + 40);
		ctx.r3.u64 = elementPtr;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = callTarget.u64;
		ctx.v1 = entryV1;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = SharedHandle_Release(ctx, base, stack + 80);
		cachedEnd = LOAD32(handleList + 8);
		if (it >= cachedEnd) {
			ppc_trap(ctx, base, 22);
		}
		it += 8;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(1, sub_82192160, 0x82192160) { ctx.r3.u64 = CCompositeComponent_Update(ctx, base, ctx.r3.u64); }

// Copies the 16 bytes at source+80 to the start of the component. The second half is read before the
// first half is written, as in the original, so overlapping ranges give the same result.
void CCompositeComponent_SetTransform(CpuState& ctx, uint8_t* base, uint32_t compositeComponentAddr, uint32_t source) {
	if (!UseLiftedCode(5, 0x82208430)) { ctx.r3.u64 = compositeComponentAddr; ctx.r4.u64 = source; __imp__sub_82208430(ctx, base); return; }
	LiftedFrame frame(0x82208430);
	CCompositeComponent* compositeComponent = GameObject<CCompositeComponent>(base, compositeComponentAddr);
	const uint64_t secondHalf = LOAD64(source + 88);
	compositeComponent->m_0 = LOAD64(source + 80);
	STORE64(compositeComponentAddr + 8, secondHalf);
}
PROMOTED_ENTRY(5, sub_82208430, 0x82208430) { CCompositeComponent_SetTransform(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void CCompositeComponent_SetVector(CpuState& ctx, uint8_t* base, uint32_t component, uint32_t source) {
	if (!UseLiftedCode(6, 0x8222A5B0)) { ctx.r3.u64 = component; ctx.r4.u64 = source; __imp__sub_8222A5B0(ctx, base); return; }
	LiftedFrame frame(0x8222A5B0);
	PPCVRegister vec{};
	SET_V8(vec, VLOAD((source + 64u) & ~0xF));
	VSTORE(component & ~0xF, V8(vec));
	return;
}
PROMOTED_ENTRY(6, sub_8222A5B0, 0x8222A5B0) { CCompositeComponent_SetVector(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CCompositeComponent_DestroyChildren(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(7, 0x8223E5C0)) { ctx.r3.u64 = arg1; __imp__sub_8223E5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223E5C0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t msrBits = ctx.r13.u32;
	// Every child call receives v1 as it was on entry.
	const PPCVRegister entryV1 = ctx.v1;
	PPCVRegister savedV127 = ctx.v127;
	PPCRegister callTarget{};

	// v127 save slot below the frame; ctx.v127 itself is never changed, so nothing is restored.
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 144);

	// arg1 + 4 is a vector-like container of (child, sharedHandleControl) pairs; walk it.
	uint32_t childIt = LOAD32((uint32_t)arg1 + 8);
	uint32_t cachedEnd = LOAD32((uint32_t)arg1 + 12);
	const uint32_t childList = (uint32_t)arg1 + 4;
	// arg1 is returned when the list is empty, otherwise the last release's result.
	uint64_t result = arg1;
	if (childIt > cachedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	while (true) {
		uint32_t listEnd = LOAD32(childList + 8);
		uint32_t listBegin = LOAD32(childList + 4);
		if (listBegin > listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (childIt == listEnd)
			break;
		if (childIt >= cachedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		// Copy the child's shared handle onto the stack, taking a reference.
		uint32_t sharedControl = LOAD32(childIt + 4);
		uint32_t child = LOAD32(childIt);
		STORE32(stack + 84, sharedControl);
		STORE32(stack + 80, child);
		// r9 at the child call: the list begin, or the lock state when a reference was taken
		uint64_t r9Value = listBegin;
		if (sharedControl != 0) {
			bool stored;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				r9Value = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrBits & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(sharedControl);
				uint32_t refCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
				stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(sharedControl)),
				                                      ctx.reserved.s32,
				                                      __builtin_bswap32((int32_t)refCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)r9Value & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);
		}

		// Virtual call on the child (vtable slot 10), then drop the stack copy of its handle.
		uint32_t childMethod = LOAD32(LOAD32(child) + 40);
		callTarget.u64 = (uint64_t)childMethod;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = child;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = childMethod;
		ctx.v1 = entryV1;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = SharedHandle_Release(ctx, base, stack + 80);

		cachedEnd = LOAD32(childList + 8);
		if (childIt >= cachedEnd) {
			ppc_trap(ctx, base, 22);
		}
		childIt += 8;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_8223E5C0, 0x8223E5C0) { ctx.r3.u64 = CCompositeComponent_DestroyChildren(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82670098(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(43, 0x82670098)) { ctx.r3.u64 = arg1; __imp__sub_82670098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82670098);
	uint32_t stack = ctx.r1.u64;
	const uint32_t msrBits = ctx.r13.u32;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	// arg1 + 4 is a vector-like container of (object, sharedHandleControl) pairs; walk it.
	const uint32_t owner = (uint32_t)arg1;
	const uint32_t handleList = owner + 4;
	// arg1 is returned when the list is empty, otherwise the last release's result.
	uint64_t result = arg1;

	STORE32(owner + 20, 0u);

	uint32_t it = LOAD32(owner + 8);
	uint32_t cachedEnd = LOAD32(owner + 12);
	if (it > cachedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	for (;;) {
		uint32_t listEnd = LOAD32(handleList + 8);
		uint32_t listBegin = LOAD32(handleList + 4);
		if (listBegin > listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (it == listEnd) break;
		if (it >= cachedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		// Copy the object's shared handle onto the stack, taking a reference.
		uint32_t sharedControl = LOAD32(it + 4);
		uint32_t object = LOAD32(it);
		STORE32(stack + 84, sharedControl);
		STORE32(stack + 80, object);
		// r9 at the object call: the list begin, or the lock state when a reference was taken
		uint64_t r9Value = listBegin;
		if (sharedControl != 0) {
			bool stored;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				r9Value = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrBits & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(sharedControl);
				uint32_t refCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
				stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(sharedControl)),
				                                      ctx.reserved.s32,
				                                      __builtin_bswap32((int32_t)refCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)r9Value & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);
		}

		// Virtual call on the object (vtable slot 6), then drop the stack copy of its handle.
		uint32_t objectMethod = LOAD32(LOAD32(object) + 24);
		callTarget.u64 = (uint64_t)objectMethod;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = object;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = objectMethod;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = SharedHandle_Release(ctx, base, stack + 80);

		cachedEnd = LOAD32(handleList + 8);
		if (it >= cachedEnd) {
			ppc_trap(ctx, base, 22);
		}
		it += 8;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82670098, 0x82670098) { ctx.r3.u64 = n_sub_82670098(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82670180(CpuState& ctx, uint8_t* base, uint32_t compositeComponentAddr, uint64_t childArg) {
	if (!UseLiftedCode(43, 0x82670180)) { ctx.r3.u64 = compositeComponentAddr; ctx.r4.u64 = childArg; __imp__sub_82670180(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82670180);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CCompositeComponent* compositeComponent = GameObject<CCompositeComponent>(base, compositeComponentAddr);
	stack = PushStackFrame(base, stack, 128);

	// Child-list byte length as last computed; it is handed over in r9, and each call's r9 replaces it.
	uint64_t childListByteLength = ctx.r9.u64;
	// callers read r4: childArg, or what the last child call left in r4
	uint64_t r4ForCaller = childArg;
	uint64_t childResult = 0;
	uint32_t childIndex = 0;
	uint32_t childByteOffset = 0;

	// Call vtable slot 20 on each child in turn; stop at the first that returns nonzero.
	for (;;) {
		uint32_t childListBegin = LOAD32(compositeComponentAddr + 8);
		uint32_t childCount = 0;
		if (childListBegin != 0) {
			childListByteLength = (uint64_t)compositeComponent->m_ChildListEnd - (uint64_t)childListBegin;
			flags.ca = ((int32_t)childListByteLength < 0) & (((uint32_t)childListByteLength & 0x7) != 0);
			childCount = (uint32_t)((int32_t)childListByteLength >> 3);
		}
		if (childIndex == childCount) {
			childResult = 0;
			break;
		}

		childListBegin = LOAD32(compositeComponentAddr + 8);
		bool indexInRange = false;
		if (childListBegin != 0) {
			childListByteLength = (uint64_t)compositeComponent->m_ChildListEnd - (uint64_t)childListBegin;
			flags.ca = ((int32_t)childListByteLength < 0) & (((uint32_t)childListByteLength & 0x7) != 0);
			indexInRange = childIndex < (uint32_t)((int32_t)childListByteLength >> 3);
		}
		if (!indexInRange) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t childAddr = LOAD32(childListBegin + childByteOffset);
		uint32_t childVirtualFn = LOAD32(LOAD32(childAddr) + 80);
		callTarget.u64 = childVirtualFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childAddr;
		ctx.r4.u64 = childArg;
		ctx.r9.u64 = childListByteLength;
		ctx.r10.u64 = childVirtualFn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		childResult = ctx.r3.u64;
		r4ForCaller = ctx.r4.u64;
		childListByteLength = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
		if ((uint32_t)childResult != 0) break;
		childIndex++;
		childByteOffset += 8;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	return childResult;
}
PROMOTED_ENTRY(43, sub_82670180, 0x82670180) { ctx.r3.u64 = n_sub_82670180(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_828A7778(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(61, 0x828A7778)) { ctx.r3.u64 = object; ctx.r5.u64 = arg2; ctx.r9.u64 = arg3; __imp__sub_828A7778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A7778);
	uint32_t stack = ctx.r1.u64;
	const uint64_t dataAt64 = (int64_t)object + 64;
	const uint32_t dataAt80 = (int64_t)object + 80;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82878960(ctx, base, (uint32_t)dataAt64, dataAt80, arg2);
	uint64_t result = Map_Find_823942A0(ctx, base, arg3, dataAt64, dataAt80);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = dataAt64;
	return result;
}
PROMOTED_ENTRY(61, sub_828A7778, 0x828A7778) { ctx.r3.u64 = n_sub_828A7778(ctx, base, ctx.r3.u64, ctx.r5.u64, ctx.r9.u64); }

uint64_t n_sub_828A77B8(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(61, 0x828A77B8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_828A77B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A77B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// out-parameter slot where the found component pointer is written
	uint32_t componentSlot = stack + 80;
	STORE32(componentSlot, 0u);

	uint32_t sourceObject = (uint32_t)arg2;
	ctx.r1.u64 = stack;
	uint32_t found = Door_FindActiveComponent(ctx, base, sourceObject, componentSlot);

	if ((found & 0xFF) != 0) {
		uint32_t activeComponent = LOAD32(componentSlot);
		uint32_t method = LOAD32(LOAD32(activeComponent) + 76);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)method;
		ctx.r3.u64 = arg1;
		ctx.r4.u64 = activeComponent;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	} else {
		C_820C9A80_GetBoundingSphere(ctx, base, arg1, arg2);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(61, sub_828A77B8, 0x828A77B8) { ctx.r3.u64 = n_sub_828A77B8(ctx, base, ctx.r3.u64, ctx.r4.u64); }
