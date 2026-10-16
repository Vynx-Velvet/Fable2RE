// CCompositeComponentHost (vtable 0x82006A60): methods of the class as readable C++.
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

uint64_t CCompositeComponentHost_SendMessage(CpuState& ctx, uint8_t* base, uint32_t compositeComponentHostAddr, uint64_t message, uint64_t messageParam) {
	if (!UseLiftedCode(0, 0x82175E58)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = message; ctx.r5.u64 = messageParam; __imp__sub_82175E58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82175E58);
	uint32_t stack = ctx.r1.u64;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 144);

	// Register state of the original code: r4 is what the last call left (or the incoming message) and goes
	// back to our caller; r6/r7 as passed in or left by the main component's call reach the first child call.
	uint64_t lastCallR4 = message;
	uint64_t childCallR6 = ctx.r6.u64;
	uint64_t childCallR7 = ctx.r7.u64;

	uint32_t mainComponentAddr = compositeComponentHost->m_mainComponent;
	uint64_t result = mainComponentAddr;
	if (mainComponentAddr != 0) {
		uint32_t sendMessageFn = LOAD32(LOAD32(mainComponentAddr) + 12);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = mainComponentAddr;
		ctx.r4.u64 = message;
		ctx.r5.u64 = messageParam;
		ctx.r10.u64 = sendMessageFn;
		REX_CALL_INDIRECT_FUNC(sendMessageFn);
		result = ctx.r3.u64;
		lastCallR4 = ctx.r4.u64;
		childCallR6 = ctx.r6.u64;
		childCallR7 = ctx.r7.u64;
	}

	// Child components: 8-byte entries, component pointer first; the list is re-read after every call.
	uint32_t entriesSize = uint32_t((uint64_t)compositeComponentHost->m_componentsEnd - (uint64_t)compositeComponentHost->m_componentsBegin) & 0xFFFFFFF8u;
	if (entriesSize != 0) {
		uint64_t childCallR8 = entriesSize;
		uint32_t entryOffset = 0;
		uint32_t index = 0;
		do {
			uint32_t componentAddr = LOAD32(uint32_t(compositeComponentHost->m_componentsBegin) + entryOffset);
			uint32_t vtable = LOAD32(componentAddr);
			uint32_t sendMessageFn = LOAD32(vtable + 12);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r3.u64 = componentAddr;
			ctx.r4.u64 = message;
			ctx.r5.u64 = messageParam;
			ctx.r6.u64 = childCallR6;
			ctx.r7.u64 = childCallR7;
			ctx.r8.u64 = childCallR8;
			ctx.r9.u64 = sendMessageFn;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(sendMessageFn);
			result = ctx.r3.u64;
			lastCallR4 = ctx.r4.u64;
			uint32_t componentsEnd = compositeComponentHost->m_componentsEnd;
			uint32_t componentsBegin = compositeComponentHost->m_componentsBegin;
			index++;
			entryOffset += 8;
			childCallR6 = (uint64_t)componentsEnd - (uint64_t)componentsBegin;
			childCallR7 = componentsBegin;
			childCallR8 = componentsEnd;
		} while (index != uint32_t((int32_t)childCallR6 >> 3));
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = lastCallR4;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(0, sub_82175E58, 0x82175E58) { ctx.r3.u64 = CCompositeComponentHost_SendMessage(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_821D0820(CpuState& ctx, uint8_t* base, uint64_t resultAddr, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(3, 0x821D0820)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = compositeComponentHostAddr; __imp__sub_821D0820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D0820);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint32_t mainComponentAddr = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr)->m_mainComponent;
	uint32_t virtualFn = LOAD32(LOAD32(mainComponentAddr) + 0x1C);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = resultAddr;
	ctx.r4.u64 = mainComponentAddr;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultAddr;
}
PROMOTED_ENTRY(3, sub_821D0820, 0x821D0820) { ctx.r3.u64 = n_sub_821D0820(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CCompositeComponentHost_GetComponentValue(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(5, 0x822093C0)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_822093C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822093C0);
	uint32_t mainComponentAddr = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr)->m_mainComponent;
	if (mainComponentAddr == 0) return 0;
	// Tail call: the result of the main component's virtual slot 0x34 is returned.
	uint32_t getValueFn = LOAD32(LOAD32(mainComponentAddr) + 52);
	ctx.r3.u64 = mainComponentAddr;
	ctx.r10.u64 = getValueFn;
	REX_CALL_INDIRECT_FUNC(getValueFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(5, sub_822093C0, 0x822093C0) { ctx.r3.u64 = CCompositeComponentHost_GetComponentValue(ctx, base, ctx.r3.u64); }

uint64_t CCompositeComponentHost_GetTransform(CpuState& ctx, uint8_t* base, uint64_t outTransform, uint64_t host) {
	if (!UseLiftedCode(7, 0x82232B40)) { ctx.r3.u64 = outTransform; ctx.r4.u64 = host; __imp__sub_82232B40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82232B40);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister loaded{};
	PPCVRegister splat{};
	PPCVRegister mask{};
	PPCVRegister result{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t mainComponentAddr = GameObject<CCompositeComponentHost>(base, host)->m_mainComponent;
	if (mainComponentAddr != 0) {
		uint32_t getTransformFn = LOAD32(LOAD32(mainComponentAddr) + 24);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = outTransform;
		ctx.r4.u64 = mainComponentAddr;
		ctx.r10.u64 = getTransformFn;
		REX_CALL_INDIRECT_FUNC(getTransformFn);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return outTransform;
	}

	// No main component: write (0, 0, 0, 1), the 1.0f at 0x820994C0 splatted and masked to the last element.
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(0x820994C0u))));
	scratch.u32 = stack + 80;
	SET_V8(loaded, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_V8(splat, simde_mm_shuffle_epi32(V8(loaded), 0xFF));
	SET_V8(mask, VLOAD(0x820991C0u & ~0xF));
	SET_V8(result, simde_mm_and_si128(V8(splat), V8(mask)));
	VSTORE((uint32_t)outTransform & ~0xF, V8(result));
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = mainComponentAddr;  // callers read r4 after the call
	return outTransform;
}
PROMOTED_ENTRY(7, sub_82232B40, 0x82232B40) { ctx.r3.u64 = CCompositeComponentHost_GetTransform(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8226E918(CpuState& ctx, uint8_t* base, uint32_t compositeComponentHostAddr, uint32_t matrixAddr, double divisor) {
	if (!UseLiftedCode(9, 0x8226E918)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = matrixAddr; ctx.f1.f64 = divisor; __imp__sub_8226E918(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8226E918);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister translation{};
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t mainComponentAddr = compositeComponentHost->m_mainComponent;
	uint32_t quatAddr = stack + 80;
	uint32_t quatCopyAddr = stack + 96;
	uint32_t translationCopyAddr = stack + 112;

	ctx.r1.u64 = stack;
	ctx.f1.f64 = double(LOAD_F32(0x82099AE0u));  // state the callee may pass on (0.0001f)
	Quat_FromMatrix3x3(ctx, base, quatAddr, matrixAddr);

	uint32_t mainComponentField2C = LOAD32(mainComponentAddr + 44);
	ctx.fpscr.disableFlushMode();
	STORE64(quatCopyAddr, LOAD64(quatAddr));
	// 1.0f (0x820994C0) / divisor, rounded to single precision.
	double reciprocal = double(float(double(LOAD_F32(0x820994C0u)) / divisor));
	// Row 3 of the matrix (offset 48).
	SET_V8(translation, VLOAD((matrixAddr + 48u) & ~0xFu));
	VSTORE(translationCopyAddr & ~0xFu, V8(translation));
	STORE64(quatCopyAddr + 8, LOAD64(quatAddr + 8));

	uint64_t result = n_sub_821DC3A8(ctx, base, translationCopyAddr, quatCopyAddr, mainComponentField2C, reciprocal);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(9, sub_8226E918, 0x8226E918) { ctx.r3.u64 = n_sub_8226E918(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.f1.f64); }

uint64_t n_sub_8228AD70(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t arg2) {
	if (!UseLiftedCode(10, 0x8228AD70)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = arg2; __imp__sub_8228AD70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8228AD70);
	uint32_t stack = ctx.r1.u64;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	n_sub_821A1C60(ctx, base, compositeComponentHostAddr, arg2);

	// Pointer chain from the global at 0x83496920 through fields +0x0C, +0x58, +0x04 and +0x18; that object's
	// virtual slot 0x58 is called (r4/r5 keep what the previous call left).
	uint32_t globalObject = LOAD32(0x83496920u);
	uint32_t link0C = LOAD32(globalObject + 12);
	uint32_t link58 = LOAD32(link0C + 88);
	uint32_t link04 = LOAD32(link58 + 4);
	uint32_t chainObject = LOAD32(link04 + 24);
	uint32_t chainVtable = LOAD32(chainObject);
	uint32_t chainFn = LOAD32(chainVtable + 88);
	// state the callee may pass on
	ctx.r3.u64 = chainObject;
	ctx.r6.u64 = chainFn;
	ctx.r7.u64 = chainVtable;
	ctx.r8.u64 = link04;
	ctx.r9.u64 = link58;
	ctx.r10.u64 = link0C;
	REX_CALL_INDIRECT_FUNC(chainFn);

	// Virtual slot 0x20 of the returned object, which stays in r3, with arg2 and the main component.
	uint32_t returnedObject = uint32_t(ctx.r3.u64);
	uint32_t mainComponentAddr = compositeComponentHost->m_mainComponent;
	uint32_t returnedObjectFn = LOAD32(LOAD32(returnedObject) + 32);
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = mainComponentAddr;
	ctx.r10.u64 = returnedObjectFn;
	REX_CALL_INDIRECT_FUNC(returnedObjectFn);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(10, sub_8228AD70, 0x8228AD70) { ctx.r3.u64 = n_sub_8228AD70(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A7F30(CpuState& ctx, uint8_t* base, uint64_t outVector, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A7F30)) { ctx.r3.u64 = outVector; ctx.r4.u64 = compositeComponentHostAddr; __imp__sub_828A7F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A7F30);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	double fillValue{};
	PPCVRegister vec80{};
	PPCVRegister vec84{};
	PPCVRegister vec84b{};
	PPCVRegister resultVec{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t mainComponentAddr = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr)->m_mainComponent;
	if (mainComponentAddr != 0) {
		uint32_t method = LOAD32(LOAD32(mainComponentAddr) + 32);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = outVector;
		ctx.r4.u64 = mainComponentAddr;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return outVector;
	}

	// No main component: write the zero vector, assembled from the 0.0f at 0x820994B4 through the stack.
	ctx.fpscr.disableFlushMode();
	fillValue = double(LOAD_F32(0x820994B4u));
	STORE_F32(stack + 80, float(fillValue));
	scratch.u32 = stack + 80;
	SET_V8(vec80, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE_F32(stack + 84, float(fillValue));
	scratch.u32 = stack + 84;
	SET_V8(vec84, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE_F32(stack + 84, float(fillValue));
	STORE_F32(stack + 80, float(fillValue));
	SET_VF(vec84, simde_mm_blend_ps(VF(vec84), simde_mm_permute_ps(VF(vec80), 57), 4));
	scratch.u32 = stack + 84;
	SET_V8(vec84b, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = stack + 80;
	SET_V8(resultVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(resultVec, simde_mm_blend_ps(VF(resultVec), simde_mm_permute_ps(VF(vec84b), 57), 4));
	SET_VF(resultVec, simde_mm_blend_ps(VF(resultVec), simde_mm_permute_ps(VF(vec84), 78), 3));
	VSTORE((uint32_t)outVector & ~0xF, V8(resultVec));
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = mainComponentAddr;  // callers read r4 after the call
	return outVector;
}
PROMOTED_ENTRY(61, sub_828A7F30, 0x828A7F30) { ctx.r3.u64 = n_sub_828A7F30(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A7FD8(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A7FD8)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_828A7FD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A7FD8);
	uint32_t mainComponentAddr = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr)->m_mainComponent;
	if (mainComponentAddr == 0) return 0;
	uint32_t virtualFn = LOAD32(LOAD32(mainComponentAddr) + 76);
	ctx.r3.u64 = mainComponentAddr;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A7FD8, 0x828A7FD8) { ctx.r3.u64 = n_sub_828A7FD8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828A7FF8(CpuState& ctx, uint8_t* base, uint64_t componentHost) {
	if (!UseLiftedCode(61, 0x828A7FF8)) { ctx.r3.u64 = componentHost; __imp__sub_828A7FF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A7FF8);

	uint32_t component = LOAD32((uint32_t)componentHost + 0x38);
	if (component == 0) return component;

	uint32_t vtable = LOAD32(component);
	uint32_t method = LOAD32(vtable + 0x50);

	ctx.r3.u64 = component;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A7FF8, 0x828A7FF8) { ctx.r3.u64 = n_sub_828A7FF8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828A8018(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A8018)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_828A8018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8018);
	uint32_t stack = ctx.r1.u64;
	// MSR bits set while the global lock is held come from r13
	uint32_t lockedMsrBits = ctx.r13.u32;
	PPCXERRegister flags = ctx.xer;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);

	// Values the calls below also receive in r4 and r6..r9: what the original code left in those
	// registers (incoming values, the main component or what a call left in r4, the component
	// vector's byte size, count, begin and end, and the MSR saved by the reference-count increment).
	uint64_t reg4 = ctx.r4.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;

	stack = PushStackFrame(base, stack, 128);

	uint32_t manager = compositeComponentHost->m_14;
	if (manager != 0) {
		uint32_t mainComponent = compositeComponentHost->m_mainComponent;
		reg4 = mainComponent;
		if (mainComponent != 0) {
			uint32_t method = LOAD32(LOAD32(manager) + 40);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = manager;
			ctx.r4.u64 = mainComponent;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
			reg4 = ctx.r4.u64;
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			flags.ca = ctx.xer.ca;
		}

		uint64_t reg9 = (uint64_t)compositeComponentHost->m_componentsEnd - (uint64_t)compositeComponentHost->m_componentsBegin;
		reg8 = (uint32_t)reg9 & 0xFFFFFFF8;
		if ((int32_t)reg8 != 0) {
			uint32_t index = 0;
			uint32_t elementOffset = 0;
			do {
				// each element is a (component, shared handle) pair; a referenced copy is made on the stack
				uint32_t element = compositeComponentHost->m_componentsBegin + elementOffset;
				uint32_t sharedHandle = LOAD32(element + 4);
				uint32_t component = LOAD32(element);
				STORE32(stack + 84, sharedHandle);
				STORE32(stack + 80, component);
				if (sharedHandle != 0) {
					// atomically increment the big-endian reference count behind the handle
					uint32_t savedMsr;
					bool stored;
					do {
						std::atomic_thread_fence(std::memory_order_seq_cst);
						savedMsr = REX_CHECK_GLOBAL_LOCK();
						std::atomic_thread_fence(std::memory_order_seq_cst);
						ctx.msr = (lockedMsrBits & 0x8020) | (ctx.msr & ~0x8020);
						REX_ENTER_GLOBAL_LOCK();
						ctx.reserved.u32 = *(uint32_t*)RAW(sharedHandle);
						uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) + 1;
						stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(sharedHandle)), ctx.reserved.s32, __builtin_bswap32(newCount));
						std::atomic_thread_fence(std::memory_order_seq_cst);
						ctx.msr = (savedMsr & 0x8020) | (ctx.msr & ~0x8020);
						REX_LEAVE_GLOBAL_LOCK();
					} while (!stored);
					reg9 = savedMsr;
				}

				uint32_t currentManager = compositeComponentHost->m_14;
				uint32_t method = LOAD32(LOAD32(currentManager) + 40);
				ctx.r1.u64 = stack;
				ctx.r3.u64 = currentManager;
				ctx.r4.u64 = component;
				ctx.r6.u64 = reg6;
				ctx.r7.u64 = reg7;
				ctx.r8.u64 = reg8;
				ctx.r9.u64 = reg9;
				ctx.r10.u64 = method;
				ctx.xer.ca = flags.ca;
				REX_CALL_INDIRECT_FUNC(method);
				flags.ca = ctx.xer.ca;

				SharedHandle_Release(ctx, base, stack + 80);
				reg4 = ctx.r4.u64;

				reg9 = compositeComponentHost->m_componentsEnd;
				reg8 = compositeComponentHost->m_componentsBegin;
				index = index + 1;
				elementOffset = elementOffset + 8;
				reg7 = reg9 - reg8;
				flags.ca = ((int32_t)reg7 < 0) & (((uint32_t)reg7 & 0x7) != 0);
				reg6 = (int32_t)reg7 >> 3;
			} while (index != (uint32_t)reg6);
		}
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = reg4;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_82670098(ctx, base, compositeComponentHostAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A8018, 0x828A8018) { ctx.r3.u64 = n_sub_828A8018(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828A8100(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t visitor) {
	if (!UseLiftedCode(61, 0x828A8100)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = visitor; __imp__sub_828A8100(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8100);
	uint32_t stack = ctx.r1.u64;
	// MSR bits set while the global lock is held come from r13
	uint32_t lockedMsrBits = ctx.r13.u32;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);

	// Values the calls below also receive in r6..r9: what the original code left in those registers
	// (incoming values, the component vector's byte size, count, begin and end, and the MSR saved by
	// the reference-count increment).
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;

	stack = PushStackFrame(base, stack, 144);

	if (compositeComponentHost->m_14 == 0) {
		uint32_t mainComponent = compositeComponentHost->m_mainComponent;
		if (mainComponent != 0) {
			uint32_t visitFn = LOAD32(LOAD32((uint32_t)visitor) + 36);
			callTarget.u64 = visitFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = visitor;
			ctx.r4.u64 = mainComponent;
			ctx.r10.u64 = visitFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			flags.ca = ctx.xer.ca;

			uint64_t reg9 = compositeComponentHost->m_componentsEnd;
			reg8 = compositeComponentHost->m_componentsBegin;
			reg7 = reg9 - reg8;
			reg6 = (uint32_t)reg7 & 0xFFFFFFF8;
			if ((int32_t)reg6 != 0) {
				uint32_t index = 0;
				uint32_t componentOffset = 0;
				do {
					// each element is a (component, shared handle) pair; a referenced copy is made on the stack
					uint32_t element = compositeComponentHost->m_componentsBegin + componentOffset;
					uint32_t sharedHandle = LOAD32(element + 4);
					uint32_t component = LOAD32(element);
					STORE32(stack + 84, sharedHandle);
					STORE32(stack + 80, component);
					if (sharedHandle != 0) {
						// atomically increment the big-endian reference count behind the handle
						uint32_t savedMsr;
						bool stored;
						do {
							std::atomic_thread_fence(std::memory_order_seq_cst);
							savedMsr = REX_CHECK_GLOBAL_LOCK();
							std::atomic_thread_fence(std::memory_order_seq_cst);
							ctx.msr = (lockedMsrBits & 0x8020) | (ctx.msr & ~0x8020);
							REX_ENTER_GLOBAL_LOCK();
							ctx.reserved.u32 = *(uint32_t*)RAW(sharedHandle);
							uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) + 1;
							stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(sharedHandle)), ctx.reserved.s32, __builtin_bswap32(newCount));
							std::atomic_thread_fence(std::memory_order_seq_cst);
							ctx.msr = (savedMsr & 0x8020) | (ctx.msr & ~0x8020);
							REX_LEAVE_GLOBAL_LOCK();
						} while (!stored);
						reg9 = savedMsr;
					}

					visitFn = LOAD32(LOAD32((uint32_t)visitor) + 36);
					callTarget.u64 = visitFn;
					ctx.r3.u64 = visitor;
					ctx.r4.u64 = component;
					ctx.r6.u64 = reg6;
					ctx.r7.u64 = reg7;
					ctx.r8.u64 = reg8;
					ctx.r9.u64 = reg9;
					ctx.r10.u64 = visitFn;
					ctx.xer.ca = flags.ca;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					flags.ca = ctx.xer.ca;

					SharedHandle_Release(ctx, base, stack + 80);

					reg9 = compositeComponentHost->m_componentsEnd;
					reg8 = compositeComponentHost->m_componentsBegin;
					index = index + 1;
					componentOffset = componentOffset + 8;
					reg7 = reg9 - reg8;
					flags.ca = ((int32_t)reg7 < 0) & (((uint32_t)reg7 & 0x7) != 0);
					reg6 = (int32_t)reg7 >> 3;
				} while (index != (uint32_t)reg6);
			}
		}
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_8266FF90(ctx, base, compositeComponentHostAddr, visitor);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A8100, 0x828A8100) { ctx.r3.u64 = n_sub_828A8100(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A81F0(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t arg2) {
	if (!UseLiftedCode(61, 0x828A81F0)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = arg2; __imp__sub_828A81F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A81F0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 128);

	// Values the calls below also receive in r5..r8: what the original code left in those registers
	// (incoming values or what the main component's call left, then the component vector's count,
	// byte size, begin and end).
	uint64_t reg5 = ctx.r5.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;

	uint32_t mainComponent = compositeComponentHost->m_mainComponent;
	if (mainComponent != 0) {
		uint32_t mainComponentMethod = LOAD32(LOAD32(mainComponent) + 40);
		callTarget.u64 = mainComponentMethod;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = mainComponent;
		ctx.r4.u64 = arg2;
		ctx.r10.u64 = mainComponentMethod;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		reg5 = ctx.r5.u64;
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		flags.ca = ctx.xer.ca;
	}

	uint32_t reg8 = uint32_t((uint64_t)compositeComponentHost->m_componentsEnd - (uint64_t)compositeComponentHost->m_componentsBegin) & 0xFFFFFFF8;
	if ((int32_t)reg8 != 0) {
		uint32_t index = 0;
		uint32_t componentOffset = 0;
		do {
			uint32_t component = LOAD32(uint32_t(compositeComponentHost->m_componentsBegin) + componentOffset);
			uint32_t componentVtable = LOAD32(component);
			uint32_t componentMethod = LOAD32(componentVtable + 40);
			callTarget.u64 = componentMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = component;
			ctx.r4.u64 = arg2;
			ctx.r5.u64 = reg5;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = componentMethod;
			ctx.r10.u64 = componentVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			reg8 = compositeComponentHost->m_componentsEnd;
			reg7 = compositeComponentHost->m_componentsBegin;
			index = index + 1;
			componentOffset = componentOffset + 8;
			reg6 = (uint64_t)reg8 - reg7;
			flags.ca = ((int32_t)reg6 < 0) & (((uint32_t)reg6 & 0x7) != 0);
			reg5 = (int32_t)reg6 >> 3;
		} while (index != (uint32_t)reg5);
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = reg5;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_8266FBB0(ctx, base, compositeComponentHostAddr, arg2);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A81F0, 0x828A81F0) { ctx.r3.u64 = n_sub_828A81F0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A8298(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A8298)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_828A8298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8298);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 128);

	// Values the calls below also receive in r5..r8: what the original code left in those registers
	// (incoming values or what the main component's call left, then the component vector's count,
	// byte size, begin and end).
	uint64_t reg5 = ctx.r5.u64;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;

	uint32_t mainComponent = compositeComponentHost->m_mainComponent;
	if (mainComponent != 0) {
		uint32_t mainComponentMethod = LOAD32(LOAD32(mainComponent) + 44);
		callTarget.u64 = mainComponentMethod;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = mainComponent;
		ctx.r10.u64 = mainComponentMethod;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		reg5 = ctx.r5.u64;
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		flags.ca = ctx.xer.ca;
	}

	uint32_t reg8 = uint32_t((uint64_t)compositeComponentHost->m_componentsEnd - (uint64_t)compositeComponentHost->m_componentsBegin) & 0xFFFFFFF8;
	if ((int32_t)reg8 != 0) {
		uint32_t index = 0;
		uint32_t componentOffset = 0;
		do {
			uint32_t component = LOAD32(uint32_t(compositeComponentHost->m_componentsBegin) + componentOffset);
			uint32_t componentVtable = LOAD32(component);
			uint32_t componentMethod = LOAD32(componentVtable + 44);
			callTarget.u64 = componentMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = component;
			ctx.r5.u64 = reg5;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = componentMethod;
			ctx.r10.u64 = componentVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			reg8 = compositeComponentHost->m_componentsEnd;
			reg7 = compositeComponentHost->m_componentsBegin;
			index = index + 1;
			componentOffset = componentOffset + 8;
			reg6 = (uint64_t)reg8 - reg7;
			flags.ca = ((int32_t)reg6 < 0) & (((uint32_t)reg6 & 0x7) != 0);
			reg5 = (int32_t)reg6 >> 3;
		} while (index != (uint32_t)reg5);
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = reg5;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_8266FC80(ctx, base, compositeComponentHostAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A8298, 0x828A8298) { ctx.r3.u64 = n_sub_828A8298(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828A8330(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t arg2) {
	if (!UseLiftedCode(61, 0x828A8330)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = arg2; __imp__sub_828A8330(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8330);
	uint32_t stack = ctx.r1.u64;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_8266FD60(ctx, base, compositeComponentHostAddr, arg2);

	uint32_t memberObject = LOAD32((uint32_t)arg2 + 124);
	uint32_t memberMethod = LOAD32(LOAD32(memberObject) + 92);
	ctx.r3.u64 = memberObject;
	ctx.r10.u64 = memberMethod;
	REX_CALL_INDIRECT_FUNC(memberMethod);
	uint32_t returnedObject = (uint32_t)ctx.r3.u64;
	if (returnedObject != 0) {
		uint32_t mainComponent = compositeComponentHost->m_mainComponent;
		uint32_t returnedObjectMethod = LOAD32(LOAD32(returnedObject) + 84);
		// r3 still holds returnedObject from the previous call: it is the receiver
		ctx.r4.u64 = mainComponent;
		ctx.r10.u64 = returnedObjectMethod;
		REX_CALL_INDIRECT_FUNC(returnedObjectMethod);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A8330, 0x828A8330) { ctx.r3.u64 = n_sub_828A8330(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A8398(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t arg2) {
	if (!UseLiftedCode(61, 0x828A8398)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = arg2; __imp__sub_828A8398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8398);
	uint32_t stack = ctx.r1.u64;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CCompositeComponent_ForEachChild(ctx, base, compositeComponentHostAddr, arg2);

	uint32_t memberObject = LOAD32((uint32_t)arg2 + 124);
	uint32_t memberMethod = LOAD32(LOAD32(memberObject) + 92);
	ctx.r3.u64 = memberObject;
	ctx.r10.u64 = memberMethod;
	REX_CALL_INDIRECT_FUNC(memberMethod);
	uint32_t returnedObject = (uint32_t)ctx.r3.u64;
	if (returnedObject != 0) {
		uint32_t mainComponent = compositeComponentHost->m_mainComponent;
		uint32_t returnedObjectMethod = LOAD32(LOAD32(returnedObject) + 88);
		// r3 still holds returnedObject from the previous call: it is the receiver
		ctx.r4.u64 = mainComponent;
		ctx.r10.u64 = returnedObjectMethod;
		REX_CALL_INDIRECT_FUNC(returnedObjectMethod);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A8398, 0x828A8398) { ctx.r3.u64 = n_sub_828A8398(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_828A8400  [120 bytes]
uint64_t n_sub_828A8400(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x828A8400)) { ctx.r3.u64 = compositeComponentHostAddr; ctx.r4.u64 = arg2; __imp__sub_828A8400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A8400);
	uint32_t stack = ctx.r1.u64;
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, compositeComponentHostAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	n_sub_8266FE30(ctx, base, compositeComponentHostAddr, arg2);

	// a chain of pointers from the global at 0x83496920 leads to the object whose method is called
	uint32_t globalObject = LOAD32(g_83490000 + 26912);
	uint32_t linkA = LOAD32(globalObject + 12);
	uint32_t linkB = LOAD32(linkA + 88);
	uint32_t linkC = LOAD32(linkB + 4);
	uint32_t provider = LOAD32(linkC + 24);
	uint32_t providerVtable = LOAD32(provider);
	uint32_t providerMethod = LOAD32(providerVtable + 88);

	// state the callee may pass on
	ctx.r3.u64 = provider;
	ctx.r6.u64 = providerMethod;
	ctx.r7.u64 = providerVtable;
	ctx.r8.u64 = linkC;
	ctx.r9.u64 = linkB;
	ctx.r10.u64 = linkA;
	REX_CALL_INDIRECT_FUNC(providerMethod);

	uint32_t returnedObject = (uint32_t)ctx.r3.u64;
	uint32_t mainComponent = compositeComponentHost->m_mainComponent;
	uint32_t returnedObjectMethod = LOAD32(LOAD32(returnedObject) + 28);

	// r3 still holds returnedObject from the previous call: it is the receiver
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = mainComponent;
	ctx.r10.u64 = returnedObjectMethod;
	REX_CALL_INDIRECT_FUNC(returnedObjectMethod);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A8400, 0x828A8400) { ctx.r3.u64 = n_sub_828A8400(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828A87C8(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A87C8)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_828A87C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A87C8);
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, (uint32_t)compositeComponentHostAddr);

	uint32_t mainComponent = compositeComponentHost->m_mainComponent;
	if (mainComponent == 0) return 0;

	uint32_t method = LOAD32(LOAD32(mainComponent) + 0x38);
	ctx.r3.u64 = mainComponent;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A87C8, 0x828A87C8) { ctx.r3.u64 = n_sub_828A87C8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828A87E8(CpuState& ctx, uint8_t* base, uint64_t compositeComponentHostAddr) {
	if (!UseLiftedCode(61, 0x828A87E8)) { ctx.r3.u64 = compositeComponentHostAddr; __imp__sub_828A87E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A87E8);
	CCompositeComponentHost* compositeComponentHost = GameObject<CCompositeComponentHost>(base, (uint32_t)compositeComponentHostAddr);

	uint32_t mainComponent = compositeComponentHost->m_mainComponent;
	if (mainComponent == 0) return 0;

	uint32_t method = LOAD32(LOAD32(mainComponent) + 0x3C);
	ctx.r3.u64 = mainComponent;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(61, sub_828A87E8, 0x828A87E8) { ctx.r3.u64 = n_sub_828A87E8(ctx, base, ctx.r3.u64); }
