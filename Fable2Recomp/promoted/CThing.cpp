// CThing (vtable 0x820F6B88): methods of the class as readable C++.
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

uint64_t n_sub_8220B7E0(CpuState& ctx, uint8_t* base, uint32_t thingAddr) {
	if (!UseLiftedCode(5, 0x8220B7E0)) { ctx.r3.u64 = thingAddr; __imp__sub_8220B7E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8220B7E0);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister row0{}, row1{}, row2{}, row3{};
	PPCVRegister tmp0{}, tmp1{}, tmp2{}, tmp3{};
	PPCVRegister out0{}, out1{}, out2{};
	CThing* thing = GameObject<CThing>(base, thingAddr);

	stack = PushStackFrame(base, stack, 224);

	uint32_t sourceTransform = thing->m_B0;
	uint32_t matrixBuffer = stack + 128;
	ctx.r1.u64 = stack;
	uint32_t matrix = Matrix4x4_FromPositionQuaternionScale(ctx, base, matrixBuffer, sourceTransform);

	uint32_t matrixA = thingAddr + 336;

	// Rearrange the 4 rows of the freshly built matrix and store them into the first output.
	SET_V8(row0, VLOAD(matrix & ~0xF));
	SET_V8(row2, VLOAD((matrix + 32) & ~0xF));
	SET_V8(row1, VLOAD((matrix + 16) & ~0xF));
	SET_V8(tmp0, simde_mm_unpackhi_epi32(V8(row2), V8(row0)));
	SET_V8(row3, VLOAD((matrix + 48u) & ~0xF));
	SET_V8(tmp1, simde_mm_unpacklo_epi32(V8(row2), V8(row0)));
	SET_V8(tmp2, simde_mm_unpackhi_epi32(V8(row3), V8(row1)));
	SET_V8(tmp3, simde_mm_unpacklo_epi32(V8(row3), V8(row1)));
	SET_V8(out0, simde_mm_unpackhi_epi32(V8(tmp2), V8(tmp0)));
	SET_V8(out1, simde_mm_unpacklo_epi32(V8(tmp2), V8(tmp0)));
	SET_V8(out2, simde_mm_unpackhi_epi32(V8(tmp3), V8(tmp1)));

	VSTORE(matrixA & ~0xF, V8(out0));
	VSTORE((matrixA + 16) & ~0xF, V8(out1));
	VSTORE((matrixA + 32) & ~0xF, V8(out2));

	uint64_t resultMatrix = n_sub_8220B698(ctx, base, stack + 80, matrixA);

	uint32_t matrixB = thingAddr + 384;
	SET_V8(out0, VLOAD((uint32_t)resultMatrix & ~0xF));
	VSTORE(matrixB & ~0xF, V8(out0));
	SET_V8(out1, VLOAD(((uint32_t)resultMatrix + 16) & ~0xF));
	VSTORE((matrixB + 16) & ~0xF, V8(out1));
	SET_V8(out2, VLOAD(((uint32_t)resultMatrix + 32) & ~0xF));
	VSTORE((matrixB + 32) & ~0xF, V8(out2));

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.v1 = out2;
	ctx.v2 = out1;
	ctx.v3 = out0;
	return resultMatrix;
}
PROMOTED_ENTRY(5, sub_8220B7E0, 0x8220B7E0) { ctx.r3.u64 = n_sub_8220B7E0(ctx, base, ctx.r3.u32); }

// sub_822298E0  [128 bytes]
uint64_t n_sub_822298E0(CpuState& ctx, uint8_t* base, uint64_t thingAddr) {
	if (!UseLiftedCode(6, 0x822298E0)) { ctx.r3.u64 = thingAddr; __imp__sub_822298E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822298E0);
	PPCVRegister dataLo{};
	PPCVRegister dataHi{};
	PPCVRegister sum{};
	PPCVRegister packed{};
	PPCVRegister broadcast{};
	PPCVRegister transformed{};
	uint32_t stack = ctx.r1.u32;
	CThing* thing = GameObject<CThing>(base, thingAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t resultAddr = thingAddr;
	if (LOAD8((uint32_t)thingAddr + 0x1B5) == 0) {
		uint32_t attachment = thing->m_D4;
		if (attachment != 0) {
			uint32_t src = attachment + 48;
			resultAddr = thingAddr + 336;

			SET_V8(dataLo, VLOAD(src & ~0xF));
			SET_V8(dataHi, VLOAD((src + 16u) & ~0xF));
			ctx.fpscr.enableFlushMode();
			SET_VF(sum, simde_mm_add_ps(VF(dataLo), VF(dataHi)));
			ctx.fpscr.disableFlushModeUnconditional();

			STORE_F32(stack + 80, float(double(LOAD_F32(0x82099334u))));
			uint32_t constAddr = stack + 80;
			SET_V8(packed, simde_mm_shuffle_epi8(
				simde_mm_load_si128((simde__m128i*)RAW(constAddr & ~0xF)),
				simde_mm_load_si128((simde__m128i*)&VectorMaskL[(constAddr & 0xF) * 16])));
			SET_V8(broadcast, simde_mm_shuffle_epi32(V8(packed), 0xFF));

			ctx.fpscr.enableFlushModeUnconditional();
			SET_VF(transformed, simde_mm_mul_ps(VF(sum), VF(broadcast)));

			ctx.r1.u64 = stack;
			ctx.v1 = transformed;
			n_sub_82A75ED8(ctx, base, resultAddr);
			transformed = ctx.v1;
			VSTORE(((uint32_t)thingAddr + 320u) & ~0xF, V8(transformed));
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return resultAddr;
}
PROMOTED_ENTRY(6, sub_822298E0, 0x822298E0) { ctx.r3.u64 = n_sub_822298E0(ctx, base, ctx.r3.u64); }

uint32_t CThing_SetState(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint32_t newState) {
	if (!UseLiftedCode(76, 0x82A6D060)) { ctx.r3.u64 = thingAddr; ctx.r4.u64 = newState; __imp__sub_82A6D060(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A6D060);
	uint32_t stack = ctx.r1.u64;
	CThing* thing = GameObject<CThing>(base, thingAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = thingAddr;
	if (LOAD32((uint32_t)thingAddr + 24) != newState) {
		uint32_t ownerWorld = thing->m_pOwner;
		thing->m_state = newState;
		if (ownerWorld != 0) {
			uint32_t stateField = (uint32_t)thingAddr + 32;
			ctx.r1.u64 = stack;
			n_sub_82AB20E0(ctx, base, stateField);
			result = n_sub_82A7F338(ctx, base, (uint64_t)ownerWorld + 3412, thingAddr);
			if (LOAD32((uint32_t)thingAddr + 60) != 0) {
				n_sub_822C5040(ctx, base, stateField);
				uint32_t ownerWorld2 = LOAD32(ownerWorld + 3676);
				result = n_sub_822B80A0(ctx, base, ownerWorld2, thingAddr);
			}
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A6D060, 0x82A6D060) { ctx.r3.u64 = CThing_SetState(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CThing_SetFlag(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint32_t flagMask, uint32_t setFlag) {
	if (!UseLiftedCode(76, 0x82A6D0D0)) { ctx.r3.u64 = thingAddr; ctx.r4.u64 = flagMask; ctx.r5.u64 = setFlag; __imp__sub_82A6D0D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A6D0D0);
	uint32_t stack = ctx.r1.u64;
	CThing* thing = GameObject<CThing>(base, thingAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t result = thingAddr;

	uint32_t oldFlags = thing->m_flags;
	uint32_t newFlags = ((setFlag & 0xFF) != 0) ? (oldFlags | flagMask) : (oldFlags & ~flagMask);
	thing->m_flags = newFlags;

	if (oldFlags != newFlags) {
		uint32_t owner = thing->m_pOwner;
		if (owner != 0) {
			uint32_t subObjectAddr = (uint32_t)(thingAddr + 32);
			ctx.r1.u64 = stack;
			n_sub_82AB20E0(ctx, base, subObjectAddr);
			result = n_sub_82A7F338(ctx, base, (uint64_t)owner + 3412, thingAddr);
			if (LOAD32((uint32_t)thingAddr + 60) != 0) {
				n_sub_822C5040(ctx, base, subObjectAddr);
				uint32_t ownerField = LOAD32(owner + 3676);
				result = n_sub_822B80A0(ctx, base, ownerField, thingAddr);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A6D0D0, 0x82A6D0D0) { ctx.r3.u64 = CThing_SetFlag(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32); }

uint32_t n_sub_82A70298(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t g_8335F6C8 = int32_t(0x8335F6C8);
	if (!UseLiftedCode(76, 0x82A70298)) { ctx.r3.u64 = thingAddr; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82A70298(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A70298);
	PPCRegister callTarget{};
	CThing* thing = GameObject<CThing>(base, thingAddr);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 112);

	thing->vtable = 0x82005D78u;
	uint32_t targetHandle = thing->m_274;
	ctx.r1.u64 = stack;
	ctx.r7.u64 = arg2;
	ctx.r8.u64 = arg3;
	HandleTarget_Free(ctx, base, targetHandle);
	thing->m_274 = 0;

	uint32_t entry = uint32_t(g_8335F6C8);
	uint32_t entryEnd = entry + 184;
	do {
		if ((uint32_t)thingAddr == LOAD32(entry)) {
			STORE32(entry, 0);
			STORE8(entry + 4, 0);
		}
		entry += 8;
	} while ((int32_t)entry < (int32_t)entryEnd);

	uint32_t resourceOwner = thing->m_270;
	if (resourceOwner != 0) {
		uint32_t refCountAddr = resourceOwner + 4;
		int32_t newRefCount = (int32_t)LOAD32(refCountAddr) - 1;
		STORE32(refCountAddr, (uint32_t)newRefCount);
		if (newRefCount == 0) {
			uint32_t releaseFn = LOAD32(LOAD32(resourceOwner) + 4);
			callTarget.u64 = (uint64_t)releaseFn;
			ctx.r3.u64 = resourceOwner;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = releaseFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		thing->m_270 = 0;
	}

	uint32_t result = CThing_DerivedDestructor(ctx, base, thingAddr, ctx.r7.u64, ctx.r8.u64);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A70298, 0x82A70298) { ctx.r3.u64 = n_sub_82A70298(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t CThing_DerivedDestructor(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(76, 0x82A70A58)) { ctx.r3.u64 = thingAddr; ctx.r7.u64 = arg2; ctx.r8.u64 = arg3; __imp__sub_82A70A58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A70A58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	CThing* thing = GameObject<CThing>(base, thingAddr);
	thing->vtable = 0x82005F60u;
	ctx.r1.u64 = stack;
	n_sub_82A70ED8(ctx, base, thingAddr, arg2, arg3);
	RefCountedPtr_ReleaseAtomic(ctx, base, thingAddr + 576);

	uint32_t pendingTarget = thing->m_234;
	if (pendingTarget != 0) {
		HandleTarget_Free(ctx, base, pendingTarget);
	}
	STORE32(thingAddr + 564, 0u);
	STORE32(thingAddr + 568, 0u);
	STORE32(thingAddr + 572, 0u);
	RefCountedPtr_ReleaseAtomic(ctx, base, thingAddr + 548);
	n_sub_82A71078(ctx, base, thingAddr + 528);

	uint32_t result = CThing_Destructor(ctx, base, thingAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A70A58, 0x82A70A58) { ctx.r3.u64 = CThing_DerivedDestructor(ctx, base, ctx.r3.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t n_sub_82A7F0C0(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint64_t flags, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(76, 0x82A7F0C0)) { ctx.r3.u64 = thingAddr; ctx.r4.u64 = flags; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; __imp__sub_82A7F0C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A7F0C0);
	uint32_t stack = ctx.r1.u64;
	CThing* thing = GameObject<CThing>(base, thingAddr);
	stack = PushStackFrame(base, stack, 112);
	bool deleteAfterDestruct = (flags & 0x1) != 0;
	thing->vtable = 0x82006228u;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	CThing_DerivedDestructor(ctx, base, thingAddr, arg3, arg4);
	if (deleteAfterDestruct) {
		HandleTarget_Free(ctx, base, thingAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return thingAddr;
}
PROMOTED_ENTRY(76, sub_82A7F0C0, 0x82A7F0C0) { ctx.r3.u64 = n_sub_82A7F0C0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_82A98278  [80 bytes]
uint64_t CThing_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t thisPtr, uint64_t deleteFlags) {
	if (!UseLiftedCode(77, 0x82A98278)) { ctx.r3.u64 = thisPtr; ctx.r4.u64 = deleteFlags; __imp__sub_82A98278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A98278);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CThing_Destructor(ctx, base, thisPtr);
	if (uint32_t(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thisPtr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return thisPtr;
}
PROMOTED_ENTRY(77, sub_82A98278, 0x82A98278) { ctx.r3.u64 = CThing_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CThing_Destructor(CpuState& ctx, uint8_t* base, uint64_t thingAddr) {
	if (!UseLiftedCode(77, 0x82A982C8)) { ctx.r3.u64 = thingAddr; __imp__sub_82A982C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A982C8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	uint32_t savedMsr = ctx.r13.u64;

	CThing* thing = GameObject<CThing>(base, thingAddr);

	stack = PushStackFrame(base, stack, 112);
	thing->vtable = 0x820F6B88u;

	uint32_t handle1BC = thing->m_1BC;
	ctx.r1.u64 = stack;
	HandleTarget_Free(ctx, base, handle1BC);
	thing->m_1BC = 0;

	uint32_t handle1B0 = thing->m_1B0;
	HandleTarget_Free(ctx, base, handle1B0);
	thing->m_1B0 = 0;

	CThing_ClearChildren(ctx, base, thingAddr);

	uint64_t entityArg = ctx.r4.u64;
	uint32_t visual = thing->m_1E4;
	if (visual != 0) {
		entityArg = thingAddr;
		CSceneEntityVisualManager_RemoveVisual(ctx, base, visual, entityArg);
	}

	ctx.r4.u64 = entityArg;
	List_ClearFreeNodes(ctx, base, (uint32_t)(thingAddr + 500));

	uint32_t handle1F8 = thing->m_1F8;
	HandleTarget_Free(ctx, base, handle1F8);
	thing->m_1F8 = 0;

	RefCountedPtr_ReleaseAtomic(ctx, base, (uint32_t)(thingAddr + 496));
	RefCountedPtr_ReleaseAtomic(ctx, base, (uint32_t)(thingAddr + 492));
	n_sub_82B18A20(ctx, base, (uint32_t)(thingAddr + 448));

	// The four smart-pointer fields below are released with an atomic reference
	// count decrement; when the count reaches zero the pointee's deleting
	// destructor ([vptr + 4]) is called and the field is nulled out.
	uint32_t e0 = thing->m_E0;
	if (e0 != 0) {
		uint32_t refAddr = e0 + 4;
		uint32_t lockState;
		uint32_t newCount;
		PPCCRRegister compare0{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			compare0.so = ctx.xer.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		if ((int32_t)newCount == 0) {
			uint32_t deleteFn = LOAD32(LOAD32(e0) + 4);
			callTarget.u64 = (uint64_t)deleteFn;
			ctx.r3.u64 = e0;
			ctx.r9.u64 = refAddr;
			ctx.r10.u64 = deleteFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		thing->m_E0 = 0;
	}

	uint32_t dc = thing->m_DC;
	if (dc != 0) {
		uint32_t refAddr = dc + 4;
		uint32_t lockState;
		uint32_t newCount;
		PPCCRRegister compare0{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			compare0.so = ctx.xer.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		if ((int32_t)newCount == 0) {
			uint32_t deleteFn = LOAD32(LOAD32(dc) + 4);
			callTarget.u64 = (uint64_t)deleteFn;
			ctx.r3.u64 = dc;
			ctx.r9.u64 = refAddr;
			ctx.r10.u64 = deleteFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		thing->m_DC = 0;
	}

	uint32_t d8 = thing->m_D8;
	if (d8 != 0) {
		uint32_t refAddr = d8 + 4;
		uint32_t lockState;
		uint32_t newCount;
		PPCCRRegister compare0{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			compare0.so = ctx.xer.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		if ((int32_t)newCount == 0) {
			uint32_t deleteFn = LOAD32(LOAD32(d8) + 4);
			callTarget.u64 = (uint64_t)deleteFn;
			ctx.r3.u64 = d8;
			ctx.r9.u64 = refAddr;
			ctx.r10.u64 = deleteFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		thing->m_D8 = 0;
	}

	uint32_t d4 = thing->m_D4;
	if (d4 != 0) {
		uint32_t refAddr = d4 + 4;
		uint32_t lockState;
		uint32_t newCount;
		PPCCRRegister compare0{};
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			compare0.so = ctx.xer.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		if ((int32_t)newCount == 0) {
			uint32_t deleteFn = LOAD32(LOAD32(d4) + 4);
			callTarget.u64 = (uint64_t)deleteFn;
			ctx.r3.u64 = d4;
			ctx.r9.u64 = refAddr;
			ctx.r10.u64 = deleteFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
		thing->m_D4 = 0;
	}

	n_sub_82A99AC8(ctx, base, (uint32_t)(thingAddr + 196));
	n_sub_82A773E0(ctx, base, (uint32_t)(thingAddr + 180));

	uint32_t handleB0 = thing->m_B0;
	HandleTarget_Free(ctx, base, handleB0);
	thing->m_B0 = 0;

	uint32_t result = n_sub_82B15910(ctx, base, thingAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A982C8, 0x82A982C8) { ctx.r3.u64 = CThing_Destructor(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82A98520(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint64_t createParams) {
	if (!UseLiftedCode(77, 0x82A98520)) { ctx.r3.u64 = thingAddr; ctx.r4.u64 = createParams; __imp__sub_82A98520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A98520);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	uint32_t thingField8{};
	uint32_t paramField4{};
	uint32_t vtable{};
	uint32_t vfunc{};
	uint32_t createFlags{};
	uint32_t thingE8{};
	uint32_t d4{};
	PPCVRegister savedVec{};
	PPCRegister callTarget{};

	CThing* thing = GameObject<CThing>(base, thingAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t paramBlock3C = createParams + 60;

	thingField8 = thing->m_8;
	paramField4 = LOAD32((uint32_t)createParams + 4);
	vtable = thing->vtable;
	thingField8 = (paramField4 << 1) | (thingField8 & 1);
	thing->m_8 = thingField8;

	vfunc = LOAD32(vtable + 96);
	callTarget.u64 = (uint64_t)vfunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = thingAddr;
	ctx.r4.u64 = paramBlock3C;
	ctx.r8.u64 = vfunc;
	ctx.r9.u64 = vtable;
	ctx.r10.u64 = paramField4;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	thing->m_E4 = uint8_t(254);
	thing->m_1D4 = LOAD32((uint32_t)createParams + 100);
	thing->m_1D8 = uint8_t(1);

	d4 = thing->m_D4;
	createFlags = LOAD32((uint32_t)createParams + 4);
	if (LOAD8(d4 + 129) != 0) {
		createFlags = createFlags | 1536;
	}

	thingE8 = thing->m_E8 | 16;
	thing->m_E8 = thingE8;

	SET_V8(savedVec, VLOAD((d4 + 32u) & ~0xF));
	VSTORE((stack + 80u) & ~0xFu, V8(savedVec));
	ctx.fpscr.disableFlushMode();
	if (double(LOAD_F32(stack + 92)) > double(LOAD_F32(0x8209BA08u))) {
		thing->m_E8 = thingE8 & ~16u;
	}

	n_sub_82A989F0(ctx, base, thingAddr, createParams);
	CThing_ApplyCreateFlags(ctx, base, thingAddr, createFlags);
	result = n_sub_822298E0(ctx, base, thingAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A98520, 0x82A98520) { ctx.r3.u64 = n_sub_82A98520(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82A989F0(CpuState& ctx, uint8_t* base, uint32_t thing, uint32_t source) {
	constexpr int32_t g_82099200 = int32_t(0x82099200);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(77, 0x82A989F0)) { ctx.r3.u64 = thing; ctx.r4.u64 = source; __imp__sub_82A989F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A989F0);
	uint32_t stack = ctx.r1.u64;

	// The recompiler expands the vector loads into explicit SSE sequences; these helpers keep
	// the same instruction order and lane/offset semantics as the lifted code.
	auto loadAligned = [&](uint32_t address) {
		PPCVRegister out{};
		SET_V8(out, VLOAD(address & ~0xF));
		return out;
	};
	auto loadWindow = [&](uint32_t address) {
		PPCVRegister out{};
		SET_V8(out, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(address & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(address & 0xF) * 16])));
		return out;
	};
	auto splatLastLane = [&](PPCVRegister& v) {
		PPCVRegister out{};
		SET_V8(out, simde_mm_shuffle_epi32(V8(v), 0xFF));
		return out;
	};
	auto multiplyVectors = [&](PPCVRegister& a, PPCVRegister& b) {
		PPCVRegister out{};
		SET_VF(out, simde_mm_mul_ps(VF(a), VF(b)));
		return out;
	};
	auto permuteBytes = [&](PPCVRegister& a, PPCVRegister& b, PPCVRegister& mask) {
		PPCVRegister out{};
		SET_V8(out, rex::ppc::simde_mm_perm_epi8_(V8(a), V8(b), V8(mask)));
		return out;
	};
	auto unpackHigh = [&](PPCVRegister& a, PPCVRegister& b) {
		PPCVRegister out{};
		SET_V8(out, simde_mm_unpackhi_epi32(V8(a), V8(b)));
		return out;
	};
	auto unpackLow = [&](PPCVRegister& a, PPCVRegister& b) {
		PPCVRegister out{};
		SET_V8(out, simde_mm_unpacklo_epi32(V8(a), V8(b)));
		return out;
	};

	const uint32_t stride16 = 16;
	const uint32_t stride32 = 32;

	stack = PushStackFrame(base, stack, 224);

	PPCVRegister zeroVector{};
	SET_V8(zeroVector, simde_mm_set1_epi32(int(0x0)));

	const uint32_t matrixScratch = stack + 112;
	const float scale = LOAD_F32(source + 0x30);
	const uint64_t quatLow = LOAD64(source + 0x10);
	const uint64_t quatHigh = LOAD64(source + 0x18);

	ctx.r1.u64 = stack;
	ctx.v1 = zeroVector;
	const double quatLength = Quat_ToMatrix4x4(ctx, base, matrixScratch, quatLow, quatHigh);

	ctx.fpscr.disableFlushMode();

	STORE_F32(stack + 80, scale);
	STORE_F32(stack + 84, scale);
	STORE_F32(stack + 88, scale);

	PPCVRegister window80 = loadWindow(stack + 80);
	const float constantA = LOAD_F32(uint32_t(g_820A0000) - 27456);
	PPCVRegister window84 = loadWindow(stack + 84);
	STORE_F32(stack + 84, constantA);
	const float constantB = LOAD_F32(uint32_t(g_820A0000) - 27456 - 12);
	STORE_F32(stack + 92, constantB);
	STORE_F32(stack + 80, constantB);
	STORE_F32(stack + 96, constantB);

	PPCVRegister splat80 = splatLastLane(window80);
	PPCVRegister window92 = loadWindow(stack + 92);
	PPCVRegister splat84 = splatLastLane(window84);
	PPCVRegister window84b = loadWindow(stack + 84);
	PPCVRegister window80b = loadWindow(stack + 80);
	PPCVRegister window96 = loadWindow(stack + 96);
	PPCVRegister window88 = loadWindow(stack + 88);
	PPCVRegister splat88 = splatLastLane(window88);

	PPCVRegister matrixRow2 = loadAligned(stack + 144);
	const uint32_t destMatrix = thing + 336;
	PPCVRegister matrixRow1 = loadAligned(stack + 128);
	ctx.fpscr.enableFlushModeUnconditional();
	PPCVRegister scaledRow2 = multiplyVectors(matrixRow2, splat80);
	PPCVRegister matrixRow0 = loadAligned(stack + 112);
	PPCVRegister scaledRow1 = multiplyVectors(matrixRow1, splat88);
	PPCVRegister scaledRow0 = multiplyVectors(matrixRow0, splat84);

	PPCVRegister permMask = loadAligned(uint32_t(g_82099200));
	PPCVRegister sourceRow = loadAligned(source + stride32);
	PPCVRegister insertA = permuteBytes(sourceRow, window84b, permMask);
	PPCVRegister insertRow2 = permuteBytes(scaledRow2, window96, permMask);
	PPCVRegister insertRow1 = permuteBytes(scaledRow1, window80b, permMask);
	PPCVRegister insertRow0 = permuteBytes(scaledRow0, window92, permMask);

	PPCVRegister mergeHiA = unpackHigh(insertA, insertRow1);
	PPCVRegister mergeHiB = unpackHigh(insertRow2, insertRow0);
	PPCVRegister mergeLoA = unpackLow(insertA, insertRow1);
	PPCVRegister mergeLoB = unpackLow(insertRow2, insertRow0);
	PPCVRegister outRow0 = unpackHigh(mergeHiA, mergeHiB);
	PPCVRegister outRow1 = unpackLow(mergeHiA, mergeHiB);
	PPCVRegister outRow2 = unpackHigh(mergeLoA, mergeLoB);

	VSTORE(destMatrix & ~0xF, V8(outRow0));
	VSTORE((destMatrix + stride16) & ~0xF, V8(outRow1));
	VSTORE((destMatrix + stride32) & ~0xF, V8(outRow2));

	ctx.v1 = scaledRow1;
	ctx.v2 = matrixRow0;
	ctx.v3 = matrixRow1;
	const uint32_t resultVector = n_sub_8220B698(ctx, base, matrixScratch, destMatrix);

	const uint32_t destMatrix2 = thing + 384;
	PPCVRegister resultRow0 = loadAligned(resultVector);
	VSTORE(destMatrix2 & ~0xF, V8(resultRow0));
	PPCVRegister resultRow1 = loadAligned(resultVector + stride16);
	VSTORE((destMatrix2 + stride16) & ~0xF, V8(resultRow1));
	PPCVRegister resultRow2 = loadAligned(resultVector + stride32);
	VSTORE((destMatrix2 + stride32) & ~0xF, V8(resultRow2));

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = quatLength;
	ctx.v21 = mergeLoB;
	ctx.v22 = mergeHiB;
	ctx.v23 = mergeLoA;
	ctx.v24 = mergeHiA;
	ctx.v25 = insertRow2;
	ctx.v26 = insertRow0;
	ctx.v27 = insertRow1;
	ctx.v28 = insertA;
	ctx.v29 = scaledRow2;
	ctx.v30 = sourceRow;
	ctx.v31 = scaledRow0;
	return resultVector;
}
PROMOTED_ENTRY(77, sub_82A989F0, 0x82A989F0) { ctx.r3.u64 = n_sub_82A989F0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82A98BC8(CpuState& ctx, uint8_t* base, uint64_t thingAddr) {
	if (!UseLiftedCode(77, 0x82A98BC8)) { ctx.r3.u64 = thingAddr; __imp__sub_82A98BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A98BC8);
	uint32_t stack = ctx.r1.u64;
	CThing* thing = GameObject<CThing>(base, thingAddr);

	stack = PushStackFrame(base, stack, 112);

	// 16-byte temporary holding two {0, m_XX} pairs
	STORE32(stack + 88, 0);
	STORE32(stack + 80, 0);
	STORE32(stack + 92, (uint32_t)thing->m_C8);
	STORE32(stack + 84, (uint32_t)thing->m_CC);

	uint32_t tempPtr = stack + 88;
	uint32_t thingFieldAddr = (uint32_t)thingAddr + 0xC4;
	uint64_t c8Pair = LOAD64(stack + 88);
	uint64_t ccPair = LOAD64(stack + 80);

	ctx.r1.u64 = stack;
	n_sub_82A99B28(ctx, base, tempPtr, thingFieldAddr, c8Pair, ccPair);

	uint32_t fieldAddr = (uint32_t)thingAddr + 0x1EC;
	uint64_t result = n_sub_82A70730(ctx, base, fieldAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A98BC8, 0x82A98BC8) { ctx.r3.u64 = n_sub_82A98BC8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82A98D68(CpuState& ctx, uint8_t* base, uint64_t thing) {
	if (!UseLiftedCode(77, 0x82A98D68)) { ctx.r3.u64 = thing; __imp__sub_82A98D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A98D68);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82A98C28(ctx, base, thing);
	uint64_t result = CThing_ClearChildren(ctx, base, thing);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A98D68, 0x82A98D68) { ctx.r3.u64 = n_sub_82A98D68(ctx, base, ctx.r3.u64); }

// sub_82A98DA0  [4 bytes]
uint64_t n_sub_82A98DA0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(77, 0x82A98DA0)) { ctx.r3.u64 = arg1; __imp__sub_82A98DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A98DA0);
	uint64_t local1 = n_sub_82A98BC8(ctx, base, arg1);
	return local1;
}
PROMOTED_ENTRY(77, sub_82A98DA0, 0x82A98DA0) { ctx.r3.u64 = n_sub_82A98DA0(ctx, base, ctx.r3.u64); }

uint32_t CThing_ApplyCreateFlags(CpuState& ctx, uint8_t* base, uint64_t thingAddr, uint32_t createFlags) {
	if (!UseLiftedCode(77, 0x82A99730)) { ctx.r3.u64 = thingAddr; ctx.r4.u64 = createFlags; __imp__sub_82A99730(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A99730);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	if (createFlags & 0x800) {
		ctx.r1.u64 = stack;
		CThing_SetState(ctx, base, thingAddr, 0x1000);
	} else if (createFlags & 0x1000) {
		ctx.r1.u64 = stack;
		CThing_SetState(ctx, base, thingAddr, 0x4000);
	}

	ctx.r1.u64 = stack;
	CThing_SetFlag(ctx, base, thingAddr, 8, (createFlags & 0x40) == 0 ? 1 : 0);

	ctx.r1.u64 = stack;
	CThing_SetFlag(ctx, base, thingAddr, 16, ((createFlags & 0x40) == 0 && (createFlags & 0x80) == 0) ? 1 : 0);

	ctx.r1.u64 = stack;
	CThing_SetFlag(ctx, base, thingAddr, 2, (createFlags >> 9) & 1);

	ctx.r1.u64 = stack;
	uint32_t result = CThing_SetFlag(ctx, base, thingAddr, 4, (createFlags >> 10) & 1);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A99730, 0x82A99730) { ctx.r3.u64 = CThing_ApplyCreateFlags(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CThing_ClearChildren(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(77, 0x82A997F0)) { ctx.r3.u64 = arg1; __imp__sub_82A997F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A997F0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = arg1;
	stack = PushStackFrame(base, stack, 128);
	uint64_t thing = arg1;
	uint64_t childList = thing + 500;
	if (LOAD32((uint32_t)thing + 508) != 0) {
		do {
			uint32_t listHead = LOAD32((uint32_t)childList + 4);
			uint32_t node = LOAD32(listHead);
			if (node == listHead) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t childEntity = LOAD32(node + 8);
			STORE32(stack + 80, (uint32_t)childList);
			STORE32(stack + 84, node);
			uint64_t iterator = LOAD64(stack + 80);
			uint64_t erasedNode = (uint64_t)(uint32_t)stack + 88;
			ctx.r1.u64 = stack;
			PtrList_Erase(ctx, base, erasedNode, childList, iterator);
			result = n_sub_82A5D018(ctx, base, (uint64_t)childEntity, thing);
		} while (LOAD32((uint32_t)thing + 508) != 0);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(77, sub_82A997F0, 0x82A997F0) { ctx.r3.u64 = CThing_ClearChildren(ctx, base, ctx.r3.u64); }
