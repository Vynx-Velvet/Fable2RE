// CCrossFadePair (vtable 0x8200B84C): methods of the class as readable C++.
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

void n_sub_82C25628(CpuState& ctx, uint8_t* base, uint32_t crossFadePairAddr, uint32_t outIntAddr, uint32_t outVectorAddr) {
	if (!UseLiftedCode(90, 0x82C25628)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = outIntAddr; ctx.r5.u64 = outVectorAddr; __imp__sub_82C25628(ctx, base); return; }
	LiftedFrame frame(0x82C25628);
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	STORE32(outIntAddr, uint32_t(crossFadePair->m_50));
	// copy the 16-byte vector at +0x40 (both addresses aligned down to 16 bytes, as the vector load/store did)
	VSTORE(outVectorAddr & ~0xF, VLOAD((crossFadePairAddr + 64u) & ~0xF));
}
PROMOTED_ENTRY(90, sub_82C25628, 0x82C25628) { n_sub_82C25628(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); }

uint64_t n_sub_82C25788(CpuState& ctx, uint8_t* base, uint64_t crossFadePairAddr, uint64_t childArg) {
	if (!UseLiftedCode(90, 0x82C25788)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = childArg; __imp__sub_82C25788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C25788);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = crossFadePairAddr;
	uint64_t r4Out = childArg;
	if (crossFadePair->m_6C == 0) {
		uint32_t childB = crossFadePair->m_childB;
		if (childB != 0) {
			uint32_t childMethod = LOAD32(LOAD32(childB) + 24);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = childB;
			ctx.r4.u64 = childArg;
			ctx.r10.u64 = childMethod;
			REX_CALL_INDIRECT_FUNC(childMethod);
			r4Out = ctx.r4.u64;
		}
		uint32_t childA = crossFadePair->m_childA;
		result = childA;
		if (childA != 0) {
			uint32_t childMethod = LOAD32(LOAD32(childA) + 24);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = childA;
			ctx.r4.u64 = childArg;
			ctx.r10.u64 = childMethod;
			REX_CALL_INDIRECT_FUNC(childMethod);
			result = ctx.r3.u64;
			r4Out = ctx.r4.u64;
		}
		crossFadePair->m_6C = 1;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out; // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(90, sub_82C25788, 0x82C25788) { ctx.r3.u64 = n_sub_82C25788(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CCrossFadePair_NotifyChildren(CpuState& ctx, uint8_t* base, uint32_t crossFadePairAddr) {
	if (!UseLiftedCode(90, 0x82C25810)) { ctx.r3.u64 = crossFadePairAddr; __imp__sub_82C25810(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C25810);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t childB = crossFadePair->m_childB;
	crossFadePair->m_6D = uint8_t(1);
	if (childB != 0) {
		uint32_t notifyChild = LOAD32(LOAD32(childB) + 28);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childB;
		ctx.r10.u64 = notifyChild;
		REX_CALL_INDIRECT_FUNC(notifyChild);
	}

	uint32_t childA = crossFadePair->m_childA;
	uint64_t result = childA;
	if (childA != 0) {
		uint32_t notifyChild = LOAD32(LOAD32(childA) + 28);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childA;
		ctx.r10.u64 = notifyChild;
		REX_CALL_INDIRECT_FUNC(notifyChild);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C25810, 0x82C25810) { ctx.r3.u64 = CCrossFadePair_NotifyChildren(ctx, base, ctx.r3.u32); }

uint64_t CCrossFadePair_ReleaseChildren(CpuState& ctx, uint8_t* base, uint32_t crossFadePairAddr, uint64_t childArg) {
	if (!UseLiftedCode(90, 0x82C25878)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = childArg; __imp__sub_82C25878(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C25878);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t r4Out = childArg;
	uint32_t childB = crossFadePair->m_childB;
	crossFadePair->m_6D = uint8_t(1);
	if (childB != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childB) + 32);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childB;
		ctx.r4.u64 = childArg;
		ctx.r5.u64 = 0;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
		r4Out = ctx.r4.u64;
		uint32_t childBRef = crossFadePair->m_1C;
		if (childBRef != 0) {
			uint32_t refMethod = LOAD32(LOAD32(childBRef) + 4);
			ctx.r3.u64 = childBRef;
			ctx.r10.u64 = refMethod;
			REX_CALL_INDIRECT_FUNC(refMethod);
			r4Out = ctx.r4.u64;
		}
		crossFadePair->m_1C = 0;
		crossFadePair->m_childB = 0;
	}

	uint32_t childA = crossFadePair->m_childA;
	uint64_t result = childA;
	if (childA != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childA) + 32);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childA;
		ctx.r4.u64 = childArg;
		ctx.r5.u64 = 0;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
		r4Out = ctx.r4.u64;
		uint32_t childARef = crossFadePair->m_14;
		result = childARef;
		if (childARef != 0) {
			uint32_t refMethod = LOAD32(LOAD32(childARef) + 4);
			ctx.r3.u64 = childARef;
			ctx.r10.u64 = refMethod;
			REX_CALL_INDIRECT_FUNC(refMethod);
			result = ctx.r3.u64;
			r4Out = ctx.r4.u64;
		}
		crossFadePair->m_14 = 0;
		crossFadePair->m_childA = 0;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out; // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(90, sub_82C25878, 0x82C25878) { ctx.r3.u64 = CCrossFadePair_ReleaseChildren(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t n_sub_82C25938(CpuState& ctx, uint8_t* base, uint64_t crossFadePairAddr, uint64_t childReference) {
	if (!UseLiftedCode(90, 0x82C25938)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = childReference; __imp__sub_82C25938(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C25938);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82C50270(ctx, base, crossFadePairAddr + 48, childReference);

	uint32_t childB = crossFadePair->m_childB;
	if (childB != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childB) + 4);
		ctx.r3.u64 = childB;
		ctx.r4.u64 = childReference;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
	}

	uint32_t childA = crossFadePair->m_childA;
	uint64_t result = childA;
	if (childA != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childA) + 4);
		ctx.r3.u64 = childA;
		ctx.r4.u64 = childReference;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C25938, 0x82C25938) { ctx.r3.u64 = n_sub_82C25938(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82C259B8(CpuState& ctx, uint8_t* base, uint64_t crossFadePairAddr, uint64_t childReference) {
	if (!UseLiftedCode(90, 0x82C259B8)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = childReference; __imp__sub_82C259B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C259B8);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82C505E8(ctx, base, crossFadePairAddr + 48, childReference);

	uint32_t childB = crossFadePair->m_childB;
	uint64_t result = childB;
	if (childB != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childB) + 8);
		ctx.r3.u64 = childB;
		ctx.r4.u64 = childReference;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
		result = ctx.r3.u64;
	}
	// The original tests m_childA here but then calls m_childB's method again (the other forwarding
	// methods call m_childA at this point); kept as the game does it.
	if (crossFadePair->m_childA != 0) {
		childB = crossFadePair->m_childB;
		uint32_t childMethod = LOAD32(LOAD32(childB) + 8);
		ctx.r3.u64 = childB;
		ctx.r4.u64 = childReference;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C259B8, 0x82C259B8) { ctx.r3.u64 = n_sub_82C259B8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C25AB0  [128 bytes]
uint64_t CCrossFadePair_SetPosition(CpuState& ctx, uint8_t* base, uint32_t crossFadePairAddr) {
	if (!UseLiftedCode(90, 0x82C25AB0)) { ctx.r3.u64 = crossFadePairAddr; __imp__sub_82C25AB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C25AB0);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	// the vector argument arrives in v1
	PPCVRegister position = ctx.v1;
	PPCVRegister v127AtEntry = ctx.v127;

	// the original saves v127 below its frame (it keeps the position in v127 across the calls)
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(v127AtEntry));
	stack = PushStackFrame(base, stack, 112);
	uint32_t childB = crossFadePair->m_childB;
	VSTORE((crossFadePairAddr + 64u) & ~0xF, V8(position));

	// childB gets the position still in v1
	if (childB != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childB) + 44);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childB;
		ctx.r10.u64 = childMethod;
		REX_CALL_INDIRECT_FUNC(childMethod);
	}

	uint32_t childA = crossFadePair->m_childA;
	uint64_t result = childA;
	if (childA != 0) {
		uint32_t childMethod = LOAD32(LOAD32(childA) + 44);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = childA;
		ctx.r10.u64 = childMethod;
		ctx.v1 = position;
		REX_CALL_INDIRECT_FUNC(childMethod);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(90, sub_82C25AB0, 0x82C25AB0) { ctx.r3.u64 = CCrossFadePair_SetPosition(ctx, base, ctx.r3.u32); }

// sub_82C26048  [272 bytes]
uint64_t n_sub_82C26048(CpuState& ctx, uint8_t* base, uint64_t crossFadePairAddr, uint64_t fadeSource) {
	if (!UseLiftedCode(90, 0x82C26048)) { ctx.r3.u64 = crossFadePairAddr; ctx.r4.u64 = fadeSource; __imp__sub_82C26048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C26048);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 128);

	// what callers find in r3 (returned), r4 and f1
	uint64_t result = crossFadePairAddr;
	uint64_t r4Out = fadeSource;
	double f1Out = ctx.f1.f64;

	if (crossFadePair->m_6D == 0) {
		uint32_t vtable = LOAD32((uint32_t)fadeSource);
		uint32_t fadeLayer = crossFadePair->m_5C;
		double fadeStartValue = double(LOAD_F32(0x82000C0Cu));
		uint32_t virtualMethod = LOAD32(vtable + 0x38);
		STORE_F32(stack + 80, float(fadeStartValue));

		ctx.r1.u64 = stack;
		ctx.r3.u64 = fadeSource;
		ctx.r4.u64 = fadeLayer;
		ctx.r5.u64 = stack + 80;
		ctx.r9.u64 = virtualMethod;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(virtualMethod);
		result = ctx.r3.u64;
		r4Out = ctx.r4.u64;
		f1Out = ctx.f1.f64;
		// registers handed on to the callees below (state they may pass on)
		double f10Value = ctx.f10.f64;
		double f11Value = ctx.f11.f64;
		double f12Value = ctx.f12.f64;
		uint64_t foundTarget = (uint32_t)result & 0xFF;

		if (foundTarget != 0) {
			ctx.fpscr.disableFlushMode();
			f1Out = double(LOAD_F32(stack + 80));
			uint64_t r6Value = stack + 88;
			STORE_F32(stack + 88, float(fadeStartValue));
			STORE32(stack + 84, 0u);
			result = n_sub_82C25EB0(ctx, base, crossFadePairAddr + 4, stack + 84, stack + 88, f1Out);
			r4Out = ctx.r4.u64;

			if (((uint32_t)result & 0xFF) != 0) {
				uint32_t newFadeId = LOAD32(stack + 84);
				if (newFadeId != crossFadePair->m_20) {
					ctx.fpscr.disableFlushMode();
					double targetFadeValue = double(LOAD_F32(stack + 88));
					double currentFadeValue = double(LOAD_F32(stack + 80));
					double fadeDistance;
					if (!(targetFadeValue < currentFadeValue)) {
						fadeDistance = float(targetFadeValue - currentFadeValue);
					} else {
						// forward from currentFadeValue up to m_64, then from m_60 on to targetFadeValue
						ctx.fpscr.disableFlushMode();
						double rangeLowerBound = double(crossFadePair->m_60);
						double rangeUpperBound = double(crossFadePair->m_64);
						f11Value = float(targetFadeValue - rangeLowerBound);
						f10Value = float(rangeUpperBound - currentFadeValue);
						f12Value = rangeUpperBound;
						fadeDistance = float(f11Value + f10Value);
					}
					ctx.fpscr.disableFlushMode();
					double maxFadeDistance = double(crossFadePair->m_68);
					if (!(fadeDistance < maxFadeDistance)) {
						fadeDistance = maxFadeDistance;
					}

					ctx.fpscr.disableFlushMode();
					// state the callee may pass on
					ctx.r8.u64 = foundTarget;
					n_sub_82C25CE0(ctx, base, crossFadePairAddr, fadeSource, newFadeId, currentFadeValue, fadeDistance);
					r6Value = ctx.r6.u64;
					foundTarget = ctx.r8.u64;
				}

				ctx.fpscr.disableFlushMode();
				f1Out = double(LOAD_F32(stack + 80));
				// state the callee may pass on
				result = CCrossFadePair_UpdateFade(ctx, base, crossFadePairAddr, f1Out);
				r4Out = ctx.r4.u64;
				f1Out = ctx.f1.f64;
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 and f1 after the call
	ctx.r4.u64 = r4Out;
	ctx.f1.f64 = f1Out;
	return result;
}
PROMOTED_ENTRY(90, sub_82C26048, 0x82C26048) { ctx.r3.u64 = n_sub_82C26048(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CCrossFadePair_Dtor(CpuState& ctx, uint8_t* base, uint64_t crossFadePairAddr) {
	if (!UseLiftedCode(90, 0x82C26158)) { ctx.r3.u64 = crossFadePairAddr; __imp__sub_82C26158(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C26158);
	uint32_t stack = ctx.r1.u64;
	CCrossFadePair* crossFadePair = GameObject<CCrossFadePair>(base, crossFadePairAddr);
	stack = PushStackFrame(base, stack, 144);

	const uint32_t objAddr = (uint32_t)crossFadePairAddr;
	// tree container at +4: m_8 is its head (sentinel) node, m_C its node count
	const uint32_t treeAddr = objAddr + 4;

	crossFadePair->vtable = 0x8200B84Cu;

	// clear the tree: erase all nodes from the root (head +4) down, then link the head node to
	// itself as root, leftmost (+0) and rightmost (+8) with a count of 0
	ctx.r1.u64 = stack;
	n_sub_82C42DC8(ctx, base, treeAddr, LOAD32(uint32_t(crossFadePair->m_8) + 4));
	uint32_t headNode = crossFadePair->m_8;
	STORE32(headNode + 4, headNode);
	crossFadePair->m_C = 0;
	STORE32(headNode, headNode);
	STORE32(headNode + 8, headNode);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, objAddr + 84);
	n_sub_82C502D8(ctx, base, objAddr + 48);

	// each child reference: call virtual slot 1 of the object in its second word, then clear both words
	PPCRegister callTarget{};
	uint32_t childBRef = crossFadePair->m_1C;
	if (childBRef != 0) {
		uint32_t releaseFn = LOAD32(LOAD32(childBRef) + 4);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = childBRef;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	crossFadePair->m_childB = 0;
	crossFadePair->m_1C = 0;

	uint32_t childARef = crossFadePair->m_14;
	if (childARef != 0) {
		uint32_t releaseFn = LOAD32(LOAD32(childARef) + 4);
		callTarget.u64 = releaseFn;
		ctx.r3.u64 = childARef;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	crossFadePair->m_14 = 0;
	crossFadePair->m_childA = 0;

	// destroy the tree: erase(begin, end) with the result iterator at stack+88, then free the head node.
	// Iterators are {container, node} pairs; begin's node is the leftmost node, end's the head node.
	headNode = crossFadePair->m_8;
	uint32_t leftmostNode = LOAD32(headNode);
	STORE32(stack + 88, treeAddr);
	STORE32(stack + 92, leftmostNode);
	STORE32(stack + 80, treeAddr);
	STORE32(stack + 84, headNode);
	uint64_t beginIter = LOAD64(stack + 88);
	uint64_t endIter = LOAD64(stack + 80);
	n_sub_82C82DC0(ctx, base, stack + 88, treeAddr, beginIter, endIter);

	HandleTarget_FreeThunk(ctx, base, uint32_t(crossFadePair->m_8));
	crossFadePair->m_8 = 0;
	crossFadePair->m_C = 0;

	C_8200A34C_Destructor(ctx, base, objAddr);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return objAddr;
}
PROMOTED_ENTRY(90, sub_82C26158, 0x82C26158) { ctx.r3.u64 = CCrossFadePair_Dtor(ctx, base, ctx.r3.u64); }

// sub_82C26258  [80 bytes]
uint64_t CCrossFadePair_DeletingDtor(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t deleteFlag) {
	if (!UseLiftedCode(90, 0x82C26258)) { ctx.r3.u64 = self; ctx.r4.u64 = deleteFlag; __imp__sub_82C26258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C26258);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlag; // state the callee may pass on
	CCrossFadePair_Dtor(ctx, base, self);
	if (uint32_t(deleteFlag & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, self);
	}
	return self;
}
PROMOTED_ENTRY(90, sub_82C26258, 0x82C26258) { ctx.r3.u64 = CCrossFadePair_DeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
