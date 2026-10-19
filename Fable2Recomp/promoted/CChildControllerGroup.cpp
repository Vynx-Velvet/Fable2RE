// CChildControllerGroup (vtable 0x8200C2D8): methods of the class as readable C++.
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

uint64_t n_sub_82C39C30(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr) {
	if (!UseLiftedCode(91, 0x82C39C30)) { ctx.r3.u64 = childControllerGroupAddr; __imp__sub_82C39C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C39C30);
	CChildControllerGroup* childControllerGroup = GameObject<CChildControllerGroup>(base, childControllerGroupAddr);
	const uint32_t controllerKind = 3000;
	const uint32_t flags = 0;
	PPCRegister callTarget{};
	uint32_t virtualFunction = LOAD32(uint32_t(childControllerGroup->vtable) + 24);
	callTarget.u64 = (uint64_t)virtualFunction;
	ctx.r3.u64 = childControllerGroupAddr;
	ctx.r4.u64 = controllerKind;
	ctx.r5.u64 = flags;
	ctx.r10.u64 = virtualFunction;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(91, sub_82C39C30, 0x82C39C30) { ctx.r3.u64 = n_sub_82C39C30(ctx, base, ctx.r3.u64); }

void n_sub_82C39DF0(CpuState& ctx, uint8_t* base, uint32_t arg1, uint32_t arg2) {
	if (!UseLiftedCode(91, 0x82C39DF0)) { ctx.r4.u64 = arg1; ctx.r5.u64 = arg2; __imp__sub_82C39DF0(ctx, base); return; }
	LiftedFrame frame(0x82C39DF0);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u32;
	PPCVRegister vecA{};
	PPCVRegister vecB{};
	PPCVRegister vecC{};
	PPCVRegister vecD{};
	ctx.fpscr.disableFlushMode();
	double scalar = double(LOAD_F32(0x82000C0Cu));
	STORE_F32(stack - 16, float(scalar));
	scratch.u32 = uint32_t((int32_t)stack - 16);
	SET_V8(vecA, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE32(arg1, 6u);
	STORE_F32(stack - 12, float(scalar));
	scratch.u32 = uint32_t((int32_t)stack - 12);
	SET_V8(vecB, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE_F32(stack - 12, float(scalar));
	STORE_F32(stack - 16, float(scalar));
	SET_VF(vecB, simde_mm_blend_ps(VF(vecB), simde_mm_permute_ps(VF(vecA), 57), 4));
	scratch.u32 = uint32_t((int32_t)stack - 12);
	SET_V8(vecC, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = uint32_t((int32_t)stack - 16);
	SET_V8(vecD, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(vecD, simde_mm_blend_ps(VF(vecD), simde_mm_permute_ps(VF(vecC), 57), 4));
	SET_VF(vecD, simde_mm_blend_ps(VF(vecD), simde_mm_permute_ps(VF(vecB), 78), 3));
	VSTORE(arg2 & ~0xF, V8(vecD));
	return;
}
PROMOTED_ENTRY(91, sub_82C39DF0, 0x82C39DF0) { n_sub_82C39DF0(ctx, base, ctx.r4.u32, ctx.r5.u32); }

uint64_t CChildControllerGroup_AllChildrenReady(CpuState& ctx, uint8_t* base, uint32_t childControllerGroupAddr) {
	if (!UseLiftedCode(91, 0x82C3A200)) { ctx.r3.u64 = childControllerGroupAddr; __imp__sub_82C3A200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A200);
	uint32_t stack = ctx.r1.u64;
	CChildControllerGroup* childControllerGroup = GameObject<CChildControllerGroup>(base, childControllerGroupAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t allReady = 0;
	if (LOAD8(childControllerGroupAddr + 81) != 0) {
		allReady = 1;
		// the begin/end of the child pointer array live at +0x14 / +0x18
		uint32_t childrenVector = childControllerGroupAddr + 0x10;
		uint32_t childIterator = childControllerGroup->m_childrenA;
		uint32_t childrenEnd = childControllerGroup->m_18;
		if (childIterator > childrenEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		while (true) {
			uint32_t childrenBegin = LOAD32(childrenVector + 4);
			uint32_t currentEnd = LOAD32(childrenVector + 8);
			if (childrenBegin > currentEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (childIterator == currentEnd) break;
			if (childIterator >= childrenEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t childAddr = LOAD32(childIterator);
			bool childReady = true;
			if (childAddr != 0) {
				uint32_t readyFn = LOAD32(LOAD32(childAddr) + 28);
				PPCRegister callTarget{};
				callTarget.u64 = readyFn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = childAddr;
				ctx.r9.u64 = childrenBegin;
				ctx.r10.u64 = readyFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				childReady = (ctx.r3.u32 & 0xFF) != 0;
			}
			if (!childReady) {
				allReady = 0;
				break;
			}
			childrenEnd = LOAD32(childrenVector + 8);
			if (childIterator >= childrenEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			childIterator += 8;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return allReady;
}
PROMOTED_ENTRY(91, sub_82C3A200, 0x82C3A200) { ctx.r3.u64 = CChildControllerGroup_AllChildrenReady(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82C3A2D0(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t arg2) {
	if (!UseLiftedCode(91, 0x82C3A2D0)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = arg2; __imp__sub_82C3A2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A2D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint64_t originalArg2 = arg2;

	if (LOAD8((uint32_t)childControllerGroupAddr + 81) == 0) {
		uint32_t vectorAddr = (uint32_t)childControllerGroupAddr + 16;
		uint32_t current = LOAD32((uint32_t)childControllerGroupAddr + 20);
		uint32_t end = LOAD32((uint32_t)childControllerGroupAddr + 24);
		if (current > end) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		while (true) {
			uint32_t arrayEnd = LOAD32(vectorAddr + 8);
			uint32_t begin = LOAD32(vectorAddr + 4);
			if (begin > arrayEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (current != arrayEnd) {
				if (current >= end) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				childControllerGroupAddr = LOAD32(current);
				if ((uint32_t)childControllerGroupAddr != 0) {
					uint32_t child = (uint32_t)childControllerGroupAddr;
					uint32_t func = LOAD32(LOAD32(child) + 64);
					PPCRegister callTarget{};
					callTarget.u64 = (uint64_t)func;
					ctx.r1.u64 = stack;
					ctx.r3.u64 = child;
					ctx.r4.u64 = 0;
					ctx.r5.u64 = originalArg2;
					ctx.r9.u64 = begin;
					ctx.r10.u64 = func;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					childControllerGroupAddr = ctx.r3.u64;
					arg2 = ctx.r4.u64;
				}
				end = LOAD32(vectorAddr + 8);
				if (current >= end) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				current += 8;
				continue;
			}
			ctx.r1.u64 = stack;
			childControllerGroupAddr = n_sub_82C08DA8(ctx, base);
			arg2 = ctx.r4.u64;
			break;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return childControllerGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3A2D0, 0x82C3A2D0) { ctx.r3.u64 = n_sub_82C3A2D0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C3A380(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t arg2) {
	if (!UseLiftedCode(91, 0x82C3A380)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = arg2; __imp__sub_82C3A380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A380);
	uint32_t stack = ctx.r1.u64;
	uint32_t childList = (uint32_t)childControllerGroupAddr + 16;
	uint32_t childIter = 0;
	uint32_t childEnd = 0;
	uint32_t childBegin = 0;
	uint32_t method = 0;
	uint64_t invokeArg = arg2;
	uint64_t result = childControllerGroupAddr;
	uint64_t outR4 = arg2;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	if (LOAD8((uint32_t)childControllerGroupAddr + 81) == 0) {
		childIter = LOAD32((uint32_t)childControllerGroupAddr + 20);
		childEnd = LOAD32((uint32_t)childControllerGroupAddr + 24);
		if (childIter > childEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		for (;;) {
			uint32_t endNow = LOAD32(childList + 8);
			childBegin = LOAD32(childList + 4);
			if (childBegin > endNow) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (childIter == endNow) break;
			if (childIter >= childEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			result = LOAD32(childIter);
			if ((uint32_t)result != 0) {
				uint32_t child = (uint32_t)result;
				method = LOAD32(LOAD32(child) + 64);
				callTarget.u64 = (uint64_t)method;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = child;
				ctx.r4.u64 = 1;
				ctx.r5.u64 = invokeArg;
				ctx.r9.u64 = childBegin;
				ctx.r10.u64 = method;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
				outR4 = ctx.r4.u64;
			}
			childEnd = LOAD32(childList + 8);
			if (childIter >= childEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			childIter += 8;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = outR4;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3A380, 0x82C3A380) { ctx.r3.u64 = n_sub_82C3A380(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CChildControllerGroup_ShutdownChildren(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t shutdownContext) {
	if (!UseLiftedCode(91, 0x82C3A430)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = shutdownContext; __imp__sub_82C3A430(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A430);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Argument handed to every child's shutdown call; never updated by the read-backs.
	const uint64_t callArg = shutdownContext;

	STORE8((uint32_t)childControllerGroupAddr + 81, uint8_t(1));

	const uint32_t listBase = (uint32_t)childControllerGroupAddr + 16;
	uint32_t iter = LOAD32((uint32_t)childControllerGroupAddr + 20);
	uint32_t limit = LOAD32((uint32_t)childControllerGroupAddr + 24);
	if (iter > limit) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	while (true) {
		const uint32_t listEnd = LOAD32(listBase + 8);
		const uint32_t listBegin = LOAD32(listBase + 4);
		if (listBegin > listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (iter == listEnd) {
			break;
		}

		if (iter >= limit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		childControllerGroupAddr = LOAD32(iter);
		if ((uint32_t)childControllerGroupAddr != 0) {
			const uint32_t shutdownFunc = LOAD32(LOAD32((uint32_t)childControllerGroupAddr) + 16);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = childControllerGroupAddr;
			ctx.r4.u64 = callArg;
			ctx.r9.u64 = listBegin;
			ctx.r10.u64 = shutdownFunc;
			REX_CALL_INDIRECT_FUNC(shutdownFunc);
			childControllerGroupAddr = ctx.r3.u64;
			shutdownContext = ctx.r4.u64;
		}

		limit = LOAD32(listBase + 8);
		if (iter >= limit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		iter += 8;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = shutdownContext;
	return childControllerGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3A430, 0x82C3A430) { ctx.r3.u64 = CChildControllerGroup_ShutdownChildren(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C3A4D8(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t listener) {
	if (!UseLiftedCode(91, 0x82C3A4D8)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = listener; __imp__sub_82C3A4D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A4D8);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	uint32_t group = (uint32_t)childControllerGroupAddr;
	uint32_t callbackData = (uint32_t)listener;

	result = n_sub_82C50270(ctx, base, group + 4, listener);

	// child list: current cursor at group+20, begin pointer at list+4, end pointer at list+8
	uint32_t childList = group + 16;
	uint32_t end = LOAD32(childList + 8);
	uint32_t current = LOAD32(group + 20);
	if (current > end) {
		ppc_trap(ctx, base, 22);
	}

	for (;;) {
		uint32_t listEnd = LOAD32(childList + 8);
		uint32_t begin = LOAD32(childList + 4);
		if (begin > listEnd) {
			ppc_trap(ctx, base, 22);
		}
		if (current == listEnd) {
			break;
		}
		if (current >= end) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t child = LOAD32(current);
		result = child;
		if (child != 0) {
			uint32_t callbackValue = LOAD32(callbackData);
			uint32_t vtable = LOAD32(child);
			callTarget.u64 = LOAD32(vtable + 44);
			ctx.r3.u64 = child;
			ctx.r4.u64 = callbackValue;
			ctx.r9.u64 = begin;
			ctx.r10.u64 = callTarget.u64;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
		}
		end = LOAD32(childList + 8);
		if (current >= end) {
			ppc_trap(ctx, base, 22);
		}
		current += 8;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3A4D8, 0x82C3A4D8) { ctx.r3.u64 = n_sub_82C3A4D8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C3A580(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t listener) {
	if (!UseLiftedCode(91, 0x82C3A580)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = listener; __imp__sub_82C3A580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3A580);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	uint32_t self = (uint32_t)childControllerGroupAddr;
	uint32_t valueSource = (uint32_t)listener;   // T166816: value at +0
	uint32_t listHeader = self + 16;         // T167518: begin at +4, end at +8

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82C505E8(ctx, base, childControllerGroupAddr + 4, listener);

	uint32_t listLimit = LOAD32(listHeader + 8);
	uint32_t entry = LOAD32(self + 20);
	if (entry > listLimit) {
		ppc_trap(ctx, base, 22);
	}

	// Walk the child pointer list, invoking the virtual at vtable+48 on each child.
	while (true) {
		uint32_t currentEnd = LOAD32(listHeader + 8);
		uint32_t currentBegin = LOAD32(listHeader + 4);
		if (currentBegin > currentEnd) {
			ppc_trap(ctx, base, 22);
		}
		if (entry == currentEnd) {
			break;
		}
		if (entry >= listLimit) {
			ppc_trap(ctx, base, 22);
		}
		result = LOAD32(entry);
		if ((uint32_t)result != 0) {
			uint32_t value = LOAD32(valueSource);
			uint32_t virtualFn = LOAD32(LOAD32((uint32_t)result) + 48);
			callTarget.u64 = virtualFn;
			ctx.r3.u64 = (uint32_t)result;
			ctx.r4.u64 = value;
			ctx.r9.u64 = currentBegin;
			ctx.r10.u64 = virtualFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
		}
		listLimit = LOAD32(listHeader + 8);
		if (entry >= listLimit) {
			ppc_trap(ctx, base, 22);
		}
		entry += 8;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(91, sub_82C3A580, 0x82C3A580) { ctx.r3.u64 = n_sub_82C3A580(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CChildControllerGroup_Destructor(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr) {
	constexpr int32_t g_83330000 = int32_t(0x83330000);
	if (!UseLiftedCode(91, 0x82C3AA88)) { ctx.r3.u64 = childControllerGroupAddr; __imp__sub_82C3AA88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C3AA88);
	uint32_t stack = ctx.r1.u64;
	CChildControllerGroup* childControllerGroup = GameObject<CChildControllerGroup>(base, childControllerGroupAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t memoryBlock = childControllerGroup->m_4C;
	childControllerGroup->vtable = 0x8200C2D8u;
	if (memoryBlock != 0) {
		ctx.r1.u64 = stack;
		MemoryAllocator_Free(ctx, base, memoryBlock);
		childControllerGroup->m_4C = 0;
	}

	uint32_t globalCounterAddr = uint32_t(g_83330000);
	uint32_t m44BlockAddr = (uint32_t)((int64_t)childControllerGroupAddr + 64);
	uint32_t globalCounter = LOAD32(globalCounterAddr + 19920);
	STORE32(globalCounterAddr + 19920, globalCounter - 1);

	uint32_t m44 = childControllerGroup->m_44;
	if (m44 != 0) {
		uint32_t virtualFn = LOAD32(LOAD32(m44) + 4);
		PPCRegister callTarget{};
		callTarget.u64 = virtualFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = m44;
		ctx.r10.u64 = virtualFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	childControllerGroup->m_44 = 0;
	uint32_t childrenCBlockAddr = (uint32_t)((int64_t)childControllerGroupAddr + 48);
	STORE32(m44BlockAddr, 0);

	uint32_t childrenC = childControllerGroup->m_childrenC;
	if (childrenC != 0) {
		uint64_t rangeBase = childrenCBlockAddr;
		uint32_t stackByte = LOAD8(stack + 80);
		uint32_t count = LOAD32(childrenCBlockAddr + 8);
		ctx.r1.u64 = stack;
		ReleaseRefRange_Stride8(ctx, base, childrenC, count);
		uint32_t childPtr = LOAD32(childrenCBlockAddr + 4);
		HandleTarget_FreeThunk(ctx, base, childPtr);
	}
	STORE32(childrenCBlockAddr + 12, 0);
	uint32_t childrenBBlockAddr = (uint32_t)((int64_t)childControllerGroupAddr + 32);
	childControllerGroup->m_childrenC = 0;
	STORE32(childrenCBlockAddr + 8, 0);

	uint32_t childrenB = childControllerGroup->m_childrenB;
	if (childrenB != 0) {
		uint64_t rangeBase = childrenBBlockAddr;
		uint32_t stackByte = LOAD8(stack + 80);
		uint32_t count = LOAD32(childrenBBlockAddr + 8);
		ctx.r1.u64 = stack;
		ReleaseRefRange_Stride8(ctx, base, childrenB, count);
		uint32_t childPtr = LOAD32(childrenBBlockAddr + 4);
		HandleTarget_FreeThunk(ctx, base, childPtr);
	}
	childControllerGroup->m_childrenB = 0;
	uint32_t childrenABlockAddr = (uint32_t)((int64_t)childControllerGroupAddr + 16);
	STORE32(childrenBBlockAddr + 8, 0);
	STORE32(childrenBBlockAddr + 12, 0);

	uint32_t childrenA = childControllerGroup->m_childrenA;
	if (childrenA != 0) {
		uint64_t rangeBase = childrenABlockAddr;
		uint32_t stackByte = LOAD8(stack + 80);
		uint32_t count = LOAD32(childrenABlockAddr + 8);
		ctx.r1.u64 = stack;
		ReleaseRefRange_Stride8(ctx, base, childrenA, count);
		uint32_t childPtr = LOAD32(childrenABlockAddr + 4);
		HandleTarget_FreeThunk(ctx, base, childPtr);
	}
	childControllerGroup->m_childrenA = 0;
	uint64_t controllerAddr = (uint64_t)((int64_t)childControllerGroupAddr + 4);
	STORE32(childrenABlockAddr + 8, 0);
	STORE32(childrenABlockAddr + 12, 0);

	ctx.r1.u64 = stack;
	n_sub_82C502D8(ctx, base, controllerAddr);
	uint32_t groupAddr = (uint32_t)childControllerGroupAddr;
	C_8200A34C_Destructor(ctx, base, groupAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return groupAddr;
}
PROMOTED_ENTRY(91, sub_82C3AA88, 0x82C3AA88) { ctx.r3.u64 = CChildControllerGroup_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CChildControllerGroup_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t arg2) {
	if (!UseLiftedCode(91, 0x82C3ABA8)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = arg2; __imp__sub_82C3ABA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3ABA8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint32_t deleteFlags = arg2;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	CChildControllerGroup_Destructor(ctx, base, childControllerGroupAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, childControllerGroupAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return childControllerGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3ABA8, 0x82C3ABA8) { ctx.r3.u64 = CChildControllerGroup_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C3B298(CpuState& ctx, uint8_t* base, uint64_t childControllerGroupAddr, uint64_t updateContext) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8200C27C = int32_t(0x8200C27C);
	constexpr int32_t g_832D60B4 = int32_t(0x832D60B4);
	if (!UseLiftedCode(91, 0x82C3B298)) { ctx.r3.u64 = childControllerGroupAddr; ctx.r4.u64 = updateContext; __imp__sub_82C3B298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C3B298);
	uint32_t stack = ctx.r1.u64;
	uint64_t childResult{};
	uint32_t local35{};
	uint64_t childNameString{};
	uint64_t local37{};
	uint64_t hash{};
	uint64_t local38{};
	uint64_t local39{};
	uint32_t childControllerC{};
	uint32_t scheduleController{};
	uint64_t consumedBudget{};
	uint32_t local28{};
	uint64_t local29{};
	uint32_t local30{};
	uint64_t local31{};
	uint32_t childController{};
	uint32_t local33{};
	uint64_t childNameHash{};
	uint64_t local42{};
	uint64_t local43{};
	uint64_t local44{};
	uint64_t local45{};
	uint32_t childNameCStr{};
	int32_t local49{};
	uint64_t local50{};
	uint32_t local51{};
	uint32_t local48{};
	uint64_t local52{};
	uint64_t local53{};
	uint32_t local54{};
	uint32_t local58{};
	uint32_t local59{};
	uint32_t local60{};
	uint32_t local61{};
	uint32_t local55{};
	uint32_t local56{};
	uint64_t local57{};
	uint32_t local64{};
	uint32_t childrenA2{};
	uint32_t local62{};
	uint32_t local65{};
	uint32_t local66{};
	uint32_t local67{};
	uint32_t local63{};
	uint32_t local68{};
	uint32_t childrenA{};
	uint32_t childrenB{};
	uint32_t childrenB2{};
	uint32_t local69{};
	uint32_t childrenC{};
	uint32_t v40{};
	uint32_t v4c{};
	uint64_t local70{};
	uint32_t childNameTable{};
	uint32_t childWeightTable{};
	uint32_t childTableOffset{};
	uint64_t childrenOffset{};
	uint32_t childIndex{};
	uint32_t local75{};
	uint32_t local76{};
	uint32_t childControllerA{};
	uint64_t local78{};
	uint64_t childControllerGroupAddr2{};
	PPCRegister local1{};
	double local2 = ctx.f1.f64;
	double local3 = ctx.f9.f64;
	double local4 = ctx.f10.f64;
	double local5 = ctx.f11.f64;
	double local6 = ctx.f12.f64;
	PPCRegister local7 = ctx.f13;
	double local8{};
	double local9{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CChildControllerGroup* childControllerGroup = GameObject<CChildControllerGroup>(base, childControllerGroupAddr);
	stack = PushStackFrame(base, stack, 240);
	childControllerGroupAddr2 = childControllerGroupAddr;
	local70 = updateContext;
	if (LOAD8((uint32_t)childControllerGroupAddr2 + 81) == 0) {
		local76 = 0;
		bool scanChildren = true;
		if (LOAD8((uint32_t)childControllerGroupAddr2 + 80) == 0) {
			// ask the controller whether the schedule may run this tick
			scheduleController = LOAD32(uint32_t(childControllerGroup->m_40) + 12);
			local62 = LOAD32(scheduleController);
			local55 = LOAD32(local62 + 28);
			callTarget.u64 = (uint64_t)local55;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = scheduleController;
			ctx.r4.u64 = updateContext;
			ctx.r9.u64 = local55;
			ctx.r10.u64 = local62;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			childControllerGroupAddr = ctx.r3.u64;
			updateContext = ctx.r4.u64;
			local2 = ctx.f1.f64;
			local3 = ctx.f9.f64;
			local4 = ctx.f10.f64;
			local5 = ctx.f11.f64;
			local6 = ctx.f12.f64;
			local7 = ctx.f13;
			flags.ca = ctx.xer.ca;
			if ((int32_t)childControllerGroupAddr == 0) {
				scanChildren = false;
			} else if ((int32_t)childControllerGroupAddr == 2) {
				childControllerGroup->m_isFinished = uint8_t(1);
				scanChildren = false;
			} else {
				v40 = childControllerGroup->m_40;
				local42 = (int64_t)(uint64_t)stack + 80;
				STORE32(stack + 80, local76);
				local28 = LOAD32(v40 + 12);
				local63 = LOAD32(local28);
				local56 = LOAD32(local63);
				callTarget.u64 = (uint64_t)local56;
				ctx.r3.u64 = local28;
				ctx.r4.u64 = local42;
				ctx.r9.u64 = local56;
				ctx.r10.u64 = local63;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				local2 = ctx.f1.f64;
				local3 = ctx.f9.f64;
				local4 = ctx.f10.f64;
				local5 = ctx.f11.f64;
				local6 = ctx.f12.f64;
				local7 = ctx.f13;
				flags.ca = ctx.xer.ca;
				v4c = childControllerGroup->m_4C;
				local29 = (uint64_t)LOAD32(stack + 80) - (uint64_t)v4c;
				STORE32(stack + 80, (uint32_t)local29);
				if ((int32_t)local29 != 0) {
					consumedBudget = n_sub_82C08CE8(ctx, base, local29);
					childControllerGroup->m_4C = uint32_t(consumedBudget + (uint64_t)childControllerGroup->m_4C);
					stack = PopStackFrame(stack, 240);
					ctx.r1.u64 = stack;
					return consumedBudget;
				}
				local30 = (uint64_t)v4c;
				MemoryAllocator_Free(ctx, base, local30);
				childControllerGroup->m_4C = local76;
				local43 = local70;
				local31 = childControllerGroupAddr2;
				childControllerGroupAddr = n_sub_82C3AE60(ctx, base, local31, local43);
				updateContext = ctx.r4.u64;
				local2 = ctx.f1.f64;
				local3 = ctx.f9.f64;
				local4 = ctx.f10.f64;
				local5 = ctx.f11.f64;
				local6 = ctx.f12.f64;
				local7 = ctx.f13;
				flags.ca = ctx.xer.ca;
				if (uint32_t((uint32_t)childControllerGroupAddr & 0xFF) == 0) {
					childControllerGroup->m_isFinished = uint8_t(1);
				}
			}
		}
		if (scanChildren) {
			childIndex = (uint64_t)local76;
			if (LOAD32((uint32_t)childControllerGroupAddr2 + 72) != 0) {
				local57 = g_82000000;
				local53 = g_82000000;
				childrenOffset = (uint64_t)local76;
				ctx.fpscr.disableFlushMode();
				local8 = double(LOAD_F32((uint32_t)local57 + 3084));
				childTableOffset = (uint64_t)local76;
				local9 = double(LOAD_F32((uint32_t)local53 + 3080));
				childNameTable = uint32_t(g_832D60B4);
				childWeightTable = uint32_t(g_8200C27C);
				do {
					local68 = childControllerGroup->m_childrenA;
					bool indexOk = false;
					if (local68 != 0) {
						local57 = (uint64_t)childControllerGroup->m_18 - (uint64_t)local68;
						flags.ca = (int32_t)local57 < 0 & ((uint32_t)local57 & 0x7) != 0;
						indexOk = childIndex < uint32_t((int32_t)local57 >> 3);
					}
					if (!indexOk) {
						ctx.r1.u64 = stack;
						ppc_trap(ctx, base, 22);
					}
					local68 = LOAD32((uint32_t)childrenOffset + local68);
					if (local68 != 0) {
						childrenA = childControllerGroup->m_childrenA;
						bool indexOk2 = false;
						if (childrenA != 0) {
							local57 = (uint64_t)childControllerGroup->m_18 - (uint64_t)childrenA;
							flags.ca = (int32_t)local57 < 0 & ((uint32_t)local57 & 0x7) != 0;
							indexOk2 = childIndex < uint32_t((int32_t)local57 >> 3);
						}
						if (!indexOk2) {
							ctx.r1.u64 = stack;
							ppc_trap(ctx, base, 22);
						}
						childController = LOAD32((uint32_t)childrenOffset + childrenA);
						local44 = (int64_t)(uint64_t)stack + 96;
						local64 = LOAD32(LOAD32(childController) + 20);
						callTarget.u64 = (uint64_t)local64;
						ctx.r1.u64 = stack;
						ctx.r3.u64 = childController;
						ctx.r4.u64 = local44;
						ctx.r8.u64 = local53;
						ctx.r9.u64 = local57;
						ctx.r10.u64 = local64;
						ctx.xer.ca = flags.ca;
						REX_CALL_INDIRECT_FUNC(callTarget.u32);
						childControllerGroupAddr = ctx.r3.u64;
						updateContext = ctx.r4.u64;
						local53 = ctx.r8.u64;
						local2 = ctx.f1.f64;
						local3 = ctx.f9.f64;
						local4 = ctx.f10.f64;
						local5 = ctx.f11.f64;
						local6 = ctx.f12.f64;
						local7 = ctx.f13;
						flags.ca = ctx.xer.ca;
						local57 = LOAD32(stack + 96);
						if ((uint32_t)local57 < 2) {
							childrenB = childControllerGroup->m_childrenB;
							bool indexOk3 = false;
							if (childrenB != 0) {
								local58 = (uint64_t)childControllerGroup->m_28 - childrenB;
								flags.ca = (int32_t)local58 < 0 & (local58 & 0x7) != 0;
								indexOk3 = childIndex < uint32_t((int32_t)local58 >> 3);
							}
							if (!indexOk3) ppc_trap(ctx, base, 22);
							childrenA2 = childControllerGroup->m_childrenA;
							local33 = LOAD32((uint32_t)childrenOffset + childrenB);
							bool indexOk4 = false;
							if (childrenA2 != 0) {
								local59 = (uint64_t)childControllerGroup->m_18 - childrenA2;
								flags.ca = (int32_t)local59 < 0 & (local59 & 0x7) != 0;
								indexOk4 = childIndex < uint32_t((int32_t)local59 >> 3);
							}
							if (!indexOk4) ppc_trap(ctx, base, 22);
							childrenB2 = childControllerGroup->m_childrenB;
							childControllerA = LOAD32((uint32_t)childrenOffset + childrenA2);
							bool indexOk5 = false;
							if (childrenB2 != 0) {
								local60 = (uint64_t)childControllerGroup->m_28 - (uint64_t)childrenB2;
								flags.ca = (int32_t)local60 < 0 & (local60 & 0x7) != 0;
								indexOk5 = childIndex < uint32_t((int32_t)local60 >> 3);
							}
							if (!indexOk5) ppc_trap(ctx, base, 22);
							local65 = LOAD32(local33);
							local75 = LOAD32(childControllerA);
							local61 = LOAD32(local65 + 4);
							callTarget.u64 = (uint64_t)local61;
							ctx.r3.u64 = local33;
							ctx.r9.u64 = local61;
							ctx.r10.u64 = local65;
							ctx.xer.ca = flags.ca;
							REX_CALL_INDIRECT_FUNC(callTarget.u32);
							childResult = ctx.r3.u64;
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
							local52 = childResult;
							local54 = LOAD32(local75 + 8);
							local48 = 0;
							local45 = childrenOffset + (uint64_t)childrenB2;
							local35 = (uint64_t)childControllerA;
							callTarget.u64 = (uint64_t)local54;
							ctx.r3.u64 = local35;
							ctx.r4.u64 = local45;
							ctx.r5.u64 = local48;
							ctx.r6.u64 = local52;
							ctx.r8.u64 = local54;
							REX_CALL_INDIRECT_FUNC(callTarget.u32);
							childControllerGroupAddr = ctx.r3.u64;
							updateContext = ctx.r4.u64;
							local53 = ctx.r8.u64;
							local57 = ctx.r9.u64;
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
						}
						if (childIndex < 7) {
							local49 = -1;
							childNameCStr = LOAD32(childTableOffset + childNameTable);
							childNameString = (int64_t)(uint64_t)stack + 84;
							CCharString_ConstructFromCStr(ctx, base, childNameString, childNameCStr, local49);
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
							local37 = (int64_t)(uint64_t)stack + 84;
							hash = String_ComputeHash(ctx, base, local37);
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
							local78 = hash;
							local38 = (int64_t)(uint64_t)stack + 84;
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, local38);
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
							local69 = LOAD32((uint32_t)local70);
							ctx.fpscr.disableFlushMode();
							STORE_F32(stack + 80, float(local9));
							local50 = (int64_t)(uint64_t)stack + 80;
							childNameHash = local78;
							local39 = local70;
							local66 = LOAD32(local69 + 56);
							callTarget.u64 = (uint64_t)local66;
							ctx.r3.u64 = local39;
							ctx.r4.u64 = childNameHash;
							ctx.r5.u64 = local50;
							ctx.r10.u64 = local66;
							REX_CALL_INDIRECT_FUNC(callTarget.u32);
							childControllerGroupAddr = ctx.r3.u64;
							updateContext = ctx.r4.u64;
							local53 = ctx.r8.u64;
							local2 = ctx.f1.f64;
							local3 = ctx.f9.f64;
							local4 = ctx.f10.f64;
							local5 = ctx.f11.f64;
							local6 = ctx.f12.f64;
							local7 = ctx.f13;
							flags.ca = ctx.xer.ca;
							local57 = (uint32_t)childControllerGroupAddr & 0xFF;
							if ((uint32_t)local57 != 0) {
								ctx.fpscr.disableFlushMode();
								local1.f64 = double(LOAD_F32(stack + 80));
								childrenC = childControllerGroup->m_childrenC;
								local7.u64 = local1.u64 ^ 0x8000000000000000;
								local6 = double(LOAD_F32(childTableOffset + childWeightTable));
								local5 = local7.f64 >= 0.0 ? local8 : local1.f64;
								local4 = double(float(local9 - local5));
								local3 = local4 >= 0.0 ? local5 : local9;
								local2 = double(float(local3 * local6));
								STORE_F32(stack + 80, float(local2));
								bool indexOk6 = false;
								if (childrenC != 0) {
									local57 = (uint64_t)childControllerGroup->m_38 - (uint64_t)childrenC;
									flags.ca = (int32_t)local57 < 0 & ((uint32_t)local57 & 0x7) != 0;
									indexOk6 = childIndex < uint32_t((int32_t)local57 >> 3);
								}
								if (!indexOk6) ppc_trap(ctx, base, 22);
								childControllerC = LOAD32((uint32_t)childrenOffset + childrenC);
								local51 = 0;
								local67 = LOAD32(LOAD32(childControllerC));
								callTarget.u64 = (uint64_t)local67;
								ctx.r3.u64 = childControllerC;
								ctx.r5.u64 = local51;
								ctx.r9.u64 = local57;
								ctx.r10.u64 = local67;
								ctx.f1.f64 = local2;
								ctx.f9.f64 = local3;
								ctx.f10.f64 = local4;
								ctx.f11.f64 = local5;
								ctx.f12.f64 = local6;
								ctx.f13 = local7;
								ctx.xer.ca = flags.ca;
								REX_CALL_INDIRECT_FUNC(callTarget.u32);
								childControllerGroupAddr = ctx.r3.u64;
								updateContext = ctx.r4.u64;
								local53 = ctx.r8.u64;
								local57 = ctx.r9.u64;
								local2 = ctx.f1.f64;
								local3 = ctx.f9.f64;
								local4 = ctx.f10.f64;
								local5 = ctx.f11.f64;
								local6 = ctx.f12.f64;
								local7 = ctx.f13;
								flags.ca = ctx.xer.ca;
							}
						}
					}
					childIndex = (int32_t)childIndex + 1;
					childTableOffset = (int32_t)childTableOffset + 4;
					childrenOffset = (int64_t)childrenOffset + 8;
				} while (childIndex < LOAD32((uint32_t)childControllerGroupAddr2 + 72));
			}
		}
	}
	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = updateContext;
	return childControllerGroupAddr;
}
PROMOTED_ENTRY(91, sub_82C3B298, 0x82C3B298) { ctx.r3.u64 = n_sub_82C3B298(ctx, base, ctx.r3.u64, ctx.r4.u64); }
