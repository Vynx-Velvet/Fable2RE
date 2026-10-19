// CLayerManager (vtable 0x8200C21C): methods of the class as readable C++.
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

uint32_t n_sub_82C37408(CpuState& ctx, uint8_t* base, uint64_t layerEntry, double lowerBound, double upperBound, double amount) {
	if (!UseLiftedCode(90, 0x82C37408)) { ctx.r4.u64 = layerEntry; ctx.f1.f64 = lowerBound; ctx.f2.f64 = upperBound; ctx.f3.f64 = amount; __imp__sub_82C37408(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C37408);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	// layerEntry points at a slot holding the target object.
	const uint32_t targetSlot = (uint32_t)layerEntry;
	ctx.fpscr.disableFlushMode();
	if (LOAD32(targetSlot) == 0) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		// callers read f1-f3 after the call
		ctx.f1.f64 = lowerBound;
		ctx.f2.f64 = upperBound;
		ctx.f3.f64 = amount;
		return ctx.r3.u32;
	}

	// Register values handed to the target's virtual call.
	double callF1 = LOAD_F32(0x82000C08u);
	double callF2 = upperBound;
	double callF3 = amount;
	double callF13 = upperBound;

	// Outside [lowerBound, upperBound]: f3 becomes the distance past the crossed bound, rounded to float.
	bool outsideRange = amount < lowerBound;
	if (outsideRange) {
		callF3 = (double)(float)(lowerBound - amount);
	} else {
		ctx.fpscr.disableFlushMode();
		outsideRange = amount > upperBound;
		if (outsideRange) {
			callF3 = (double)(float)(amount - upperBound);
		}
	}

	if (outsideRange) {
		ctx.fpscr.disableFlushMode();
		const double rangeStart = LOAD_F32(targetSlot + 12);
		const double rangeEnd = LOAD_F32(targetSlot + 16);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		n_sub_82C509A8(ctx, base, 0, rangeStart, rangeEnd, callF3);
		// the virtual call gets the registers sub_82C509A8 leaves
		layerEntry = ctx.r4.u64;
		callF1 = ctx.f1.f64;
		callF2 = ctx.f2.f64;
		callF3 = ctx.f3.f64;
		callF13 = ctx.f13.f64;
	}

	const uint32_t target = LOAD32(targetSlot);
	const uint32_t virtualFunction = LOAD32(LOAD32(target) + 12);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = target;
	ctx.r4.u64 = layerEntry;
	ctx.r5.u64 = 50;
	ctx.r10.u64 = virtualFunction;
	ctx.f1.f64 = callF1;
	ctx.f2.f64 = callF2;
	ctx.f3.f64 = callF3;
	ctx.f13.f64 = callF13;
	REX_CALL_INDIRECT_FUNC(virtualFunction);

	// f1-f3 for callers are what the virtual call left
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u32;
}
PROMOTED_ENTRY(90, sub_82C37408, 0x82C37408) { ctx.r3.u64 = n_sub_82C37408(ctx, base, ctx.r4.u64, ctx.f1.f64, ctx.f2.f64, ctx.f3.f64); }

uint32_t CLayerManager_ClearChildFlags(CpuState& ctx, uint8_t* base, uint32_t layerManagerAddr) {
	if (!UseLiftedCode(90, 0x82C37600)) { ctx.r3.u64 = layerManagerAddr; __imp__sub_82C37600(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C37600);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 112);

	// The child map is walked with a checked STL iterator kept on the game stack as
	// {owning container, current node}; the traps are the iterator's validity checks.
	const uint32_t childMap = layerManagerAddr + 0x1C;
	const uint32_t iteratorAddr = stack + 80;
	uint32_t container = childMap;
	uint32_t node = LOAD32(GameObject<CLayerManager>(base, layerManagerAddr)->m_childMap);
	STORE32(iteratorAddr, container);
	STORE32(iteratorAddr + 4, node);
	// r3 on return: the layer manager, or the iterator address once the loop has advanced
	uint32_t result = layerManagerAddr;

	while (true) {
		const uint32_t endNode = LOAD32(childMap + 4);
		if (container == 0 || container != childMap) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) {
			break;
		}
		if (container == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(container + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		STORE8(node + 0x24, 0);
		result = iteratorAddr;
		ctx.r1.u64 = stack;
		StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
		node = LOAD32(iteratorAddr + 4);
		container = LOAD32(iteratorAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37600, 0x82C37600) { ctx.r3.u64 = CLayerManager_ClearChildFlags(ctx, base, ctx.r3.u32); }

uint64_t CLayerManager_AllChildrenReady(CpuState& ctx, uint8_t* base, uint32_t layerManagerAddr) {
	if (!UseLiftedCode(90, 0x82C376A0)) { ctx.r3.u64 = layerManagerAddr; __imp__sub_82C376A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C376A0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 112);

	if (LOAD8(layerManagerAddr + 49) == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 0;
	}

	// Checked STL iterator on the game stack: {owning container, current node}.
	const uint32_t childMap = layerManagerAddr + 28;
	const uint32_t iteratorAddr = stack + 80;
	uint32_t container = childMap;
	uint32_t node = LOAD32(layerManager->m_childMap);
	STORE32(iteratorAddr, container);
	STORE32(iteratorAddr + 4, node);

	for (;;) {
		const uint32_t endNode = LOAD32(childMap + 4);
		if (container == 0 || container != childMap) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 1;
		}
		if (container == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t headNode = LOAD32(container + 4);
		if (node == headNode) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t child = LOAD32(node + 16);
		if (child != 0) {
			if (node == headNode) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t isReadyFn = LOAD32(LOAD32(child));
			callTarget.u64 = isReadyFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = child;
			ctx.r9.u64 = child;
			ctx.r10.u64 = isReadyFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			if ((ctx.r3.u32 & 0xFF) == 0) {
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return 0;
			}
		}
		ctx.r1.u64 = stack;
		StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
		node = LOAD32(iteratorAddr + 4);
		container = LOAD32(iteratorAddr);
	}
}
PROMOTED_ENTRY(90, sub_82C376A0, 0x82C376A0) { ctx.r3.u64 = CLayerManager_AllChildrenReady(ctx, base, ctx.r3.u32); }

uint64_t CLayerManager_Resume(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t childArg) {
	if (!UseLiftedCode(90, 0x82C37790)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = childArg; __imp__sub_82C37790(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C37790);
	uint32_t stack = ctx.r1.u64;
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 128);
	// r3/r4 on return: r3 becomes the iterator address once the loop has advanced,
	// r4 is what the last child call left there
	uint64_t result = layerManagerAddr;
	uint64_t r4OnReturn = childArg;

	if (LOAD8((uint32_t)layerManagerAddr + 48) != 0) {
		// Checked STL iterator on the game stack: {owning container, current node}.
		const uint32_t childMap = (uint32_t)layerManagerAddr + 28;
		const uint32_t iteratorAddr = stack + 80;
		uint32_t container = childMap;
		uint32_t node = LOAD32(layerManager->m_childMap);
		STORE32(iteratorAddr, container);
		STORE32(iteratorAddr + 4, node);

		for (;;) {
			const uint32_t endNode = LOAD32(childMap + 4);
			if (container == 0 || container != childMap) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == endNode) break;

			if (container == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t headNode = LOAD32(container + 4);
			if (node == headNode) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t child = LOAD32(node + 16);
			if (child != 0) {
				if (node == headNode) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				const uint32_t resumeFn = LOAD32(LOAD32(child) + 20);
				PPCRegister callTarget{};
				callTarget.u64 = resumeFn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = child;
				ctx.r4.u64 = childArg;
				ctx.r9.u64 = child;
				ctx.r10.u64 = resumeFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				r4OnReturn = ctx.r4.u64;
			}
			result = iteratorAddr;
			ctx.r1.u64 = stack;
			StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
			node = LOAD32(iteratorAddr + 4);
			container = LOAD32(iteratorAddr);
		}
		layerManager->m_paused = uint8_t(0);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4OnReturn;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37790, 0x82C37790) { ctx.r3.u64 = CLayerManager_Resume(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CLayerManager_Pause(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t childArg) {
	if (!UseLiftedCode(90, 0x82C37858)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = childArg; __imp__sub_82C37858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C37858);
	uint32_t stack = ctx.r1.u64;
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 128);
	// r3/r4 on return: r3 becomes the iterator address once the loop has advanced,
	// r4 is what the last child call left there
	uint64_t result = layerManagerAddr;
	uint64_t r4OnReturn = childArg;

	if (LOAD8((uint32_t)layerManagerAddr + 48) == 0) {
		// Checked STL iterator on the game stack: {owning container, current node}.
		const uint32_t childMap = (uint32_t)layerManagerAddr + 28;
		const uint32_t iteratorAddr = stack + 80;
		uint32_t container = childMap;
		uint32_t node = LOAD32(layerManager->m_childMap);
		STORE32(iteratorAddr, container);
		STORE32(iteratorAddr + 4, node);

		for (;;) {
			const uint32_t endNode = LOAD32(childMap + 4);
			if (container == 0 || container != childMap) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == endNode) break;

			if (container == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t headNode = LOAD32(container + 4);
			if (node == headNode) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t child = LOAD32(node + 16);
			if (child != 0) {
				if (node == headNode) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				const uint32_t pauseFn = LOAD32(LOAD32(child) + 24);
				PPCRegister callTarget{};
				callTarget.u64 = pauseFn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = child;
				ctx.r4.u64 = childArg;
				ctx.r9.u64 = child;
				ctx.r10.u64 = pauseFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				r4OnReturn = ctx.r4.u64;
			}
			result = iteratorAddr;
			ctx.r1.u64 = stack;
			StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
			node = LOAD32(iteratorAddr + 4);
			container = LOAD32(iteratorAddr);
		}
		layerManager->m_paused = uint8_t(1);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4OnReturn;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37858, 0x82C37858) { ctx.r3.u64 = CLayerManager_Pause(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CLayerManager_Shutdown(CpuState& ctx, uint8_t* base, uint64_t layerManager, uint64_t childArg) {
	if (!UseLiftedCode(90, 0x82C37920)) { ctx.r3.u64 = layerManager; ctx.r4.u64 = childArg; __imp__sub_82C37920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C37920);
	uint32_t stack = ctx.r1.u64;
	// r9 is carried through the loop and handed to the iterator increment and the second child call
	uint64_t r9Value = ctx.r9.u64;
	stack = PushStackFrame(base, stack, 144);

	PPCRegister callTarget{};
	const uint32_t managerAddr = (uint32_t)layerManager;
	// r3/r4 on return: r3 becomes the iterator address once the loop has advanced,
	// r4 is what the last child call left there
	uint64_t result = layerManager;
	uint64_t r4OnReturn = childArg;

	if (LOAD8(managerAddr + 49) == 0) {
		const uint32_t childMap = managerAddr + 28;
		STORE8(managerAddr + 49, 1);

		// Checked STL iterator on the game stack: {owning container, current node}.
		const uint32_t iteratorAddr = stack + 80;
		uint32_t container = childMap;
		uint32_t node = LOAD32(LOAD32(managerAddr + 32));
		STORE32(iteratorAddr, container);
		STORE32(iteratorAddr + 4, node);

		for (;;) {
			const uint32_t endNode = LOAD32(childMap + 4);
			if (container == 0 || container != childMap) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == endNode) break;

			if (container == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t headNode = LOAD32(container + 4);
			if (node == headNode) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			// The node's value holds two object pointers, at +16 and +20.
			const uint32_t valueAddr = node + 16;
			if (LOAD32(valueAddr) != 0) {
				if (node == headNode) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				const uint32_t child = LOAD32(valueAddr);
				const uint32_t shutdownFn = LOAD32(LOAD32(child) + 32);
				callTarget.u64 = shutdownFn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = child;
				ctx.r4.u64 = childArg;
				ctx.r5.u64 = 0;
				ctx.r10.u64 = shutdownFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				r4OnReturn = ctx.r4.u64;

				r9Value = LOAD32(container + 4);
				if (node == (uint32_t)r9Value) {
					ppc_trap(ctx, base, 22);
				}

				const uint32_t secondObject = LOAD32(valueAddr + 4);
				if (secondObject != 0) {
					const uint32_t secondFn = LOAD32(LOAD32(secondObject) + 4);
					callTarget.u64 = secondFn;
					ctx.r3.u64 = secondObject;
					ctx.r9.u64 = r9Value;
					ctx.r10.u64 = secondFn;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					r4OnReturn = ctx.r4.u64;
					r9Value = ctx.r9.u64;
				}
				STORE32(valueAddr + 4, 0);
				STORE32(valueAddr, 0);
			}

			result = iteratorAddr;
			// state the callee may pass on
			ctx.r1.u64 = stack;
			StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
			r9Value = ctx.r9.u64;
			node = LOAD32(iteratorAddr + 4);
			container = LOAD32(iteratorAddr);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4OnReturn;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37920, 0x82C37920) { ctx.r3.u64 = CLayerManager_Shutdown(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CLayerManager_BroadcastUpdate(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t updateData) {
	if (!UseLiftedCode(90, 0x82C37A28)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = updateData; __imp__sub_82C37A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C37A28);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// r3 on return: this call's result, or the iterator address once the loop has advanced
	uint64_t result = n_sub_82C50270(ctx, base, layerManagerAddr + 4, updateData);

	// Checked STL iterator on the game stack: {owning container, current node}.
	const uint32_t childMap = (uint32_t)layerManagerAddr + 28;
	const uint32_t iteratorAddr = stack + 80;
	uint32_t container = childMap;
	STORE32(iteratorAddr, container);
	uint32_t node = LOAD32(layerManager->m_childMap);
	STORE32(iteratorAddr + 4, node);

	while (true) {
		const uint32_t endNode = LOAD32(childMap + 4);
		if (container == 0 || container != childMap) {
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) {
			break;
		}
		if (container == 0) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t headNode = LOAD32(container + 4);
		if (node == headNode) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t child = LOAD32(node + 16);
		if (child != 0) {
			if (node == headNode) {
				ppc_trap(ctx, base, 22);
			}
			const uint32_t updateFn = LOAD32(LOAD32(child) + 4);
			callTarget.u64 = updateFn;
			ctx.r3.u64 = child;
			ctx.r4.u64 = updateData;
			ctx.r9.u64 = child;
			ctx.r10.u64 = updateFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		result = iteratorAddr;
		StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
		node = LOAD32(iteratorAddr + 4);
		container = LOAD32(iteratorAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37A28, 0x82C37A28) { ctx.r3.u64 = CLayerManager_BroadcastUpdate(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CLayerManager_BroadcastUpdate2(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t updateData) {
	if (!UseLiftedCode(90, 0x82C37AE8)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = updateData; __imp__sub_82C37AE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C37AE8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// r3 on return: this call's result, or the iterator address once the loop has advanced
	uint64_t result = n_sub_82C505E8(ctx, base, layerManagerAddr + 4, updateData);

	// Checked STL iterator on the game stack: {owning container, current node}.
	const uint32_t childMap = (uint32_t)layerManagerAddr + 28;
	const uint32_t iteratorAddr = stack + 80;
	uint32_t container = childMap;
	STORE32(iteratorAddr, container);
	uint32_t node = LOAD32(layerManager->m_childMap);
	STORE32(iteratorAddr + 4, node);

	while (true) {
		const uint32_t endNode = LOAD32(childMap + 4);
		if (container == 0 || container != childMap) {
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) {
			break;
		}
		if (container == 0) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t headNode = LOAD32(container + 4);
		if (node == headNode) {
			ppc_trap(ctx, base, 22);
		}
		const uint32_t child = LOAD32(node + 16);
		if (child != 0) {
			if (node == headNode) {
				ppc_trap(ctx, base, 22);
			}
			const uint32_t broadcastFn = LOAD32(LOAD32(child) + 8);
			callTarget.u64 = broadcastFn;
			ctx.r3.u64 = child;
			ctx.r4.u64 = updateData;
			ctx.r9.u64 = child;
			ctx.r10.u64 = broadcastFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		result = iteratorAddr;
		StdMapIterator_Increment_Node41(ctx, base, iteratorAddr);
		node = LOAD32(iteratorAddr + 4);
		container = LOAD32(iteratorAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37AE8, 0x82C37AE8) { ctx.r3.u64 = CLayerManager_BroadcastUpdate2(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Walks the child map at +0x1C. Entries whose byte at +20 is set are kept; for every other entry the two
// objects it points to are called through their vtables and the pointers cleared, then the entry is erased.
uint32_t n_sub_82C37FE8(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t r8Value) {
	if (!UseLiftedCode(90, 0x82C37FE8)) { ctx.r3.u64 = layerManagerAddr; ctx.r8.u64 = r8Value; __imp__sub_82C37FE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C37FE8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	uint32_t result = (uint32_t)layerManagerAddr;
	stack = PushStackFrame(base, stack, 128);

	// The iterator at stack+80 is {owning map, node}; the traps are the checked-iterator tests.
	uint32_t mapAddr = (uint32_t)layerManagerAddr + 28;
	uint32_t headNode = LOAD32((uint32_t)layerManagerAddr + 32);
	uint32_t iterMap = mapAddr;
	STORE32(stack + 80, iterMap);
	uint32_t node = LOAD32(headNode);
	STORE32(stack + 84, node);

	for (;;) {
		uint32_t endNode = LOAD32(mapAddr + 4);
		if (iterMap == 0 || iterMap != mapAddr) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == endNode) break;

		if (iterMap == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iterMap + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t entry = node + 16;
		if (LOAD8(node + 36) != 0) {
			// the return value is this call's argument when the walk ends after a kept entry
			result = stack + 80;
			ctx.r1.u64 = stack;
			StdMapIterator_Increment_Node41(ctx, base, stack + 80);
			node = LOAD32(stack + 84);
			iterMap = LOAD32(stack + 80);
			continue;
		}

		uint32_t firstObject = LOAD32(entry);
		if (firstObject != 0) {
			uint32_t firstMethod = LOAD32(LOAD32(firstObject) + 32);
			callTarget.u64 = firstMethod;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = firstObject;
			ctx.r4.u64 = 1000;
			ctx.r5.u64 = 0;
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = node;
			ctx.r10.u64 = firstMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r8Value = ctx.r8.u64;

			uint32_t secondObject = LOAD32(entry + 4);
			if (secondObject != 0) {
				uint32_t secondMethod = LOAD32(LOAD32(secondObject) + 4);
				callTarget.u64 = secondMethod;
				ctx.r3.u64 = secondObject;
				ctx.r10.u64 = secondMethod;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				r8Value = ctx.r8.u64;
			}
			STORE32(entry + 4, 0);
			STORE32(entry, 0);
		}

		// erase the entry; the result holds the iterator to the next one
		uint64_t iterator = LOAD64(stack + 80);
		ctx.r1.u64 = stack;
		result = n_sub_82C360B8(ctx, base, stack + 88, layerManagerAddr + 28, iterator, r8Value);
		r8Value = ctx.r8.u64;
		STORE64(stack + 80, LOAD64(result));
		node = LOAD32(stack + 84);
		iterMap = LOAD32(stack + 80);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C37FE8, 0x82C37FE8) { ctx.r3.u64 = n_sub_82C37FE8(ctx, base, ctx.r3.u64, ctx.r8.u64); }

// Gets the child-map entry for entryKey and clears its word at +8. If the template map at +0x10 has a node
// for templateKey, factory creates the child object from it into the entry, and the template's two floats
// are copied to the entry.
uint64_t CLayerManager_CreateEntry(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint32_t entryKey, uint64_t factory, uint64_t templateKey, uint64_t r8Value) {
	if (!UseLiftedCode(90, 0x82C38548)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = entryKey; ctx.r5.u64 = factory; ctx.r6.u64 = templateKey; ctx.r8.u64 = r8Value; __imp__sub_82C38548(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C38548);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 240);
	STORE32(stack + 268, entryKey);
	STORE32(stack + 284, (uint32_t)templateKey);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r5.u64 = factory;
	ctx.r6.u64 = templateKey;
	uint64_t entry = n_sub_82C38438(ctx, base, layerManagerAddr + 28, stack + 268, r8Value);
	STORE32((uint32_t)entry + 8, 0);

	// Lower-bound search of the template map; the iterator is {owning map, node} and the traps are the
	// checked-iterator tests.
	uint32_t templateMapAddr = (uint32_t)layerManagerAddr + 16;
	Map_LowerBound_UIntKeyLargeNode(ctx, base, stack + 96, templateMapAddr, stack + 284);
	uint32_t templateMapHead = layerManager->m_templateMap;
	STORE64(stack + 88, LOAD64(stack + 96));
	uint32_t iterMap = LOAD32(stack + 88);
	if (iterMap == 0 || iterMap != templateMapAddr) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t templateNode = LOAD32(stack + 92);

	if (templateNode != templateMapHead) {
		if (iterMap == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (templateNode == LOAD32(iterMap + 4)) {
			ppc_trap(ctx, base, 22);
		}

		uint32_t layerEntry = stack + 112;
		// state the callee may pass on
		ctx.r5.u64 = stack + 284;
		n_sub_821D5BA0(ctx, base, layerEntry);
		LayerEntry_SetValues(ctx, base, layerEntry, 0, LOAD32(templateNode + 16));
		LayerEntry_SetField32(ctx, base, layerEntry, 1);
		if (layerManager->m_paused != 0) {
			LayerEntry_SetBit14(ctx, base, layerEntry);
		}

		uint32_t createFn = LOAD32(LOAD32((uint32_t)factory) + 12);
		callTarget.u64 = createFn;
		ctx.r3.u64 = stack + 80;
		ctx.r4.u64 = factory;
		ctx.r5.u64 = layerEntry;
		ctx.r10.u64 = createFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		RefPtr_Assign(ctx, base, entry, ctx.r3.u64);

		uint32_t outRef = LOAD32(stack + 84);
		if (outRef != 0) {
			uint32_t releaseFn = LOAD32(LOAD32(outRef) + 4);
			callTarget.u64 = releaseFn;
			ctx.r3.u64 = outRef;
			ctx.r10.u64 = releaseFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		STORE32(stack + 84, 0);
		STORE32(stack + 80, 0);

		if (LOAD32((uint32_t)entry) != 0) {
			n_sub_82C50130(ctx, base, layerManagerAddr + 4, entry);
			uint32_t child = LOAD32((uint32_t)entry);
			uint32_t vtable = LOAD32(child);
			uint32_t childMethod = LOAD32(vtable + 12);
			ctx.fpscr.disableFlushMode();
			callTarget.u64 = childMethod;
			ctx.r3.u64 = child;
			ctx.r5.u64 = 0;
			ctx.r9.u64 = childMethod;
			ctx.r10.u64 = vtable;
			ctx.f1.f64 = double(LOAD_F32(0x82000C0Cu));
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			ctx.fpscr.disableFlushMode();
			STORE_F32((uint32_t)entry + 12, LOAD_F32(templateNode + 20));
			double secondValue = double(LOAD_F32(templateNode + 24));
			STORE_F32((uint32_t)entry + 16, float(secondValue));
			// the release below receives f13
			ctx.f13.f64 = secondValue;
		}
		CCharString_ReleaseMember(ctx, base, stack + 112);
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return entry;
}
PROMOTED_ENTRY(90, sub_82C38548, 0x82C38548) { ctx.r3.u64 = CLayerManager_CreateEntry(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

// Returns the child-map entry for key, creating it through CLayerManager_CreateEntry when the lower-bound
// search ends at the map's head node.
uint64_t CLayerManager_FindOrCreateEntry(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint32_t key, uint64_t factory, uint64_t templateKey, uint64_t r8Value) {
	if (!UseLiftedCode(90, 0x82C386C0)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = key; ctx.r5.u64 = factory; ctx.r6.u64 = templateKey; ctx.r8.u64 = r8Value; __imp__sub_82C386C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C386C0);
	uint32_t stack = ctx.r1.u64;
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 144);
	STORE32(stack + 172, key);

	uint32_t childMapAddr = (uint32_t)layerManagerAddr + 0x1C;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	Map_LowerBound_UIntKey(ctx, base, stack + 80, childMapAddr, stack + 172);

	// The result is an iterator {owning map, node}; the traps are the checked-iterator tests.
	uint32_t iterMap = LOAD32(stack + 80);
	uint32_t childMapHead = layerManager->m_childMap;
	if (iterMap == 0 || iterMap != childMapAddr) {
		ppc_trap(ctx, base, 22);
	}

	uint32_t node = LOAD32(stack + 84);
	if (node == childMapHead) {
		uint64_t newEntry = CLayerManager_CreateEntry(ctx, base, layerManagerAddr, key, factory, templateKey, ctx.r8.u64);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return newEntry;
	}

	if (iterMap == 0) {
		ppc_trap(ctx, base, 22);
	}
	if (node == LOAD32(iterMap + 4)) {
		ppc_trap(ctx, base, 22);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return (uint64_t)node + 16;
}
PROMOTED_ENTRY(90, sub_82C386C0, 0x82C386C0) { ctx.r3.u64 = CLayerManager_FindOrCreateEntry(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

// Unless the manager is shut down, asks source (vtable slot +44) to fill the buffer at stack+128. On success
// it clears the child flags, builds a list from m_2C and the buffer's first and third floats, finds or creates
// the child entry of every list item, marks it (byte at +20) and passes it values from the item and the
// buffer, then erases the unmarked entries (n_sub_82C37FE8) and frees the list.
uint64_t n_sub_82C38760(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t source) {
	if (!UseLiftedCode(91, 0x82C38760)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = source; __imp__sub_82C38760(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C38760);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	uint64_t result = layerManagerAddr;
	uint64_t r4Value = source;
	PPCVRegister vec{};
	PPCVRegister v59{}, v60{}, v61{}, v62{}, v63{}, v64{}, v65{}, v66{}, v67{}, v68{}, v69{}, v70{}, v71{}, v72{};
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 272);
	if (layerManager->m_shutdown == 0) {
		uint32_t buffer = stack + 128;
		callTarget.u64 = LOAD32(LOAD32((uint32_t)source) + 44);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = source;
		ctx.r4.u64 = buffer;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
		if ((uint32_t(result) & 0xFF) != 0) {
			CLayerManager_ClearChildFlags(ctx, base, (uint32_t)layerManagerAddr);

			uint32_t listAddr = stack + 104;
			ctx.fpscr.disableFlushMode();
			double thirdFloat = double(LOAD_F32(stack + 136));
			STORE_F32(stack + 96, LOAD_F32(stack + 128));
			STORE_F32(stack + 100, float(thirdFloat));
			// state the callee may pass on
			n_sub_82C37C48(ctx, base, listAddr);

			n_sub_82C04B58(ctx, base, layerManager->m_2C, LOAD64(stack + 96), (uint64_t)listAddr);

			// The iterator at stack+96 is {list, node}; the traps are the checked-iterator tests.
			uint32_t listHead = LOAD32(stack + 108);
			ctx.fpscr.disableFlushMode();
			double constVal = double(LOAD_F32(0x82000C0Cu));
			STORE32(stack + 96, listAddr);
			STORE32(stack + 100, LOAD32(listHead));
			uint64_t r8Value = LOAD64(stack + 96);
			STORE64(stack + 96, r8Value);
			uint32_t iterList = LOAD32(stack + 96);
			uint32_t node = LOAD32(stack + 100);

			for (;;) {
				if (iterList == 0 || iterList != listAddr) {
					ppc_trap(ctx, base, 22);
				}
				if (node == LOAD32(stack + 108)) break;
				if (iterList == 0) {
					ppc_trap(ctx, base, 22);
				}
				if (node == LOAD32(iterList + 4)) {
					ppc_trap(ctx, base, 22);
				}

				uint32_t item = node + 8;
				uint64_t entry = CLayerManager_FindOrCreateEntry(ctx, base, layerManagerAddr, LOAD32(item), source, LOAD32(item + 4), r8Value);
				uint64_t r8ForCall = ctx.r8.u64;
				STORE8((uint32_t)entry + 20, 1);
				uint32_t entryKind = LOAD32(node + 36);
				uint64_t r9ForCall;
				uint32_t kindArg;
				if (entryKind == 0) {
					scratch.u32 = item + 16;
					SET_V8(v72, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = item + 20;
					SET_V8(v71, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					r9ForCall = stack + 148;
					ctx.fpscr.disableFlushMode();
					STORE_F32(stack + 80, float(constVal));
					r8ForCall = stack + 80;
					kindArg = 3;
					SET_V8(v70, VLOAD((stack + 128) & ~0xF));
					VSTORE((stack + 144) & ~0xF, V8(v70));
					scratch.u32 = (uint32_t)r9ForCall;
					SET_V8(v69, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					scratch.u32 = (uint32_t)r8ForCall;
					SET_V8(v68, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
					SET_VF(v71, simde_mm_blend_ps(VF(v71), simde_mm_permute_ps(VF(v68), 57), 4));
					SET_VF(v72, simde_mm_blend_ps(VF(v72), simde_mm_permute_ps(VF(v69), 57), 4));
					SET_V8(vec, V8(v72));
					SET_VF(vec, simde_mm_blend_ps(VF(vec), simde_mm_permute_ps(VF(v71), 78), 3));
				} else {
					ctx.fpscr.disableFlushMode();
					STORE_F32(stack + 84, float(constVal));
					STORE_F32(stack + 88, float(constVal));
					uint32_t addr84 = stack + 84;
					STORE_F32(stack + 96, float(constVal));
					r9ForCall = stack + 88;
					if (entryKind == 1) {
						r8ForCall = stack + 96;
						scratch.u32 = (uint32_t)r9ForCall;
						SET_V8(v65, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						scratch.u32 = addr84;
						SET_V8(v66, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						STORE_F32(stack + 80, float(constVal));
						kindArg = 1;
						scratch.u32 = (uint32_t)r8ForCall;
						SET_V8(v64, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						SET_VF(v64, simde_mm_blend_ps(VF(v64), simde_mm_permute_ps(VF(v65), 57), 4));
						scratch.u32 = stack + 80;
						SET_V8(v67, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						SET_VF(v66, simde_mm_blend_ps(VF(v66), simde_mm_permute_ps(VF(v67), 57), 4));
						SET_V8(vec, V8(v64));
						SET_VF(vec, simde_mm_blend_ps(VF(vec), simde_mm_permute_ps(VF(v66), 78), 3));
					} else {
						scratch.u32 = item + 24;
						SET_V8(v63, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						scratch.u32 = addr84;
						SET_V8(v61, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						kindArg = 2;
						SET_VF(v61, simde_mm_blend_ps(VF(v61), simde_mm_permute_ps(VF(v63), 57), 4));
						scratch.u32 = (uint32_t)r9ForCall;
						SET_V8(v60, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						scratch.u32 = stack + 96;
						SET_V8(v62, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
						SET_V8(vec, V8(v61));
						SET_VF(v62, simde_mm_blend_ps(VF(v62), simde_mm_permute_ps(VF(v60), 57), 4));
						SET_VF(vec, simde_mm_blend_ps(VF(vec), simde_mm_permute_ps(VF(v62), 78), 3));
					}
				}

				// state the callee may pass on
				ctx.v1 = vec;
				n_sub_82C37490(ctx, base, entry, kindArg);
				ctx.fpscr.disableFlushMode();
				double itemFloat1 = double(LOAD_F32(item + 8));
				double itemFloat2 = double(LOAD_F32(item + 12));
				SET_V8(v59, VLOAD((stack + 128) & ~0xF));
				VSTORE((stack + 160) & ~0xF, V8(v59));
				double bufferFloat = double(LOAD_F32(stack + 164));
				// state the callee may pass on
				n_sub_82C37408(ctx, base, entry, itemFloat1, itemFloat2, bufferFloat);
				r8Value = ctx.r8.u64;
				if (node == LOAD32(iterList + 4)) {
					ppc_trap(ctx, base, 22);
				}
				node = LOAD32(node);
			}

			n_sub_82C37FE8(ctx, base, layerManagerAddr, r8Value);
			n_sub_82C045B8(ctx, base, listAddr);
			result = HandleTarget_FreeThunk(ctx, base, LOAD32(stack + 108));
			r4Value = ctx.r4.u64;
		}
	}
	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(91, sub_82C38760, 0x82C38760) { ctx.r3.u64 = n_sub_82C38760(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CLayerManager_Destruct(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr) {
	if (!UseLiftedCode(91, 0x82C389B0)) { ctx.r3.u64 = layerManagerAddr; __imp__sub_82C389B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C389B0);
	uint32_t stack = ctx.r1.u64;
	CLayerManager* layerManager = GameObject<CLayerManager>(base, layerManagerAddr);

	stack = PushStackFrame(base, stack, 128);
	layerManager->vtable = 0x8200C21Cu;
	ctx.r1.u64 = stack;
	CLayerManager_Shutdown(ctx, base, layerManagerAddr, 0);

	// Erase all nodes of the child map at +0x1C (iterators are {map, node}, the head node is end), then free
	// its head node and clear the head pointer and the count.
	const uint64_t childMapAddr = layerManagerAddr + 0x1C;
	uint32_t childMapHead = layerManager->m_childMap;
	STORE32(stack + 88, (uint32_t)childMapAddr);
	STORE32(stack + 80, (uint32_t)childMapAddr);
	uint32_t childMapFirst = LOAD32(childMapHead);
	STORE32(stack + 84, childMapHead);
	uint64_t childMapEnd = LOAD64(stack + 80);
	STORE32(stack + 92, childMapFirst);
	uint64_t childMapBegin = LOAD64(stack + 88);
	n_sub_82C36860(ctx, base, stack + 88, childMapAddr, childMapBegin, childMapEnd);

	HandleTarget_FreeThunk(ctx, base, layerManager->m_childMap);
	layerManager->m_childMap = 0;
	layerManager->m_24 = 0;

	// The same for the template map at +0x10.
	uint32_t templateMapAddr = (uint32_t)layerManagerAddr + 0x10;
	uint32_t templateMapHead = layerManager->m_templateMap;
	uint32_t templateMapFirst = LOAD32(templateMapHead);
	STORE32(stack + 88, templateMapAddr);
	STORE32(stack + 92, templateMapHead);
	STORE32(stack + 84, templateMapFirst);
	STORE32(stack + 80, templateMapAddr);
	uint64_t templateMapEnd = LOAD64(stack + 88);
	uint64_t templateMapBegin = LOAD64(stack + 80);
	// state the callee may pass on
	n_sub_82C36EB8(ctx, base, stack + 88, templateMapAddr, templateMapBegin, templateMapEnd);

	HandleTarget_FreeThunk(ctx, base, layerManager->m_templateMap);
	layerManager->m_templateMap = 0;
	layerManager->m_18 = 0;

	n_sub_82C502D8(ctx, base, layerManagerAddr + 4);
	C_8200A34C_Destructor(ctx, base, (uint32_t)layerManagerAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)layerManagerAddr;
}
PROMOTED_ENTRY(91, sub_82C389B0, 0x82C389B0) { ctx.r3.u64 = CLayerManager_Destruct(ctx, base, ctx.r3.u64); }

uint64_t CLayerManager_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t layerManagerAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(91, 0x82C38A88)) { ctx.r3.u64 = layerManagerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C38A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C38A88);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	CLayerManager_Destruct(ctx, base, layerManagerAddr);
	if (((uint32_t)deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, layerManagerAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return layerManagerAddr;
}
PROMOTED_ENTRY(91, sub_82C38A88, 0x82C38A88) { ctx.r3.u64 = CLayerManager_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
