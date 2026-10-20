// CChainedEntityEffect (vtable 0x820F1840): methods of the class as readable C++.
//
// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).Each function was written
// by a language model from the lifter's exact code for the user's own copy and accepted by the differential
// checker on input profiles 0-5 (tools/rewrite/check.py --outputs).Review and game-check status per function:
// REVIEW.tsv in this directory and docs/status.md.A function keeps the address of the original
// (PROMOTED_ENTRY) and its fallback to the recompiled original (UseLiftedCode).
// Layouts and declarations come from the lifter, generated locally (lifted/classes.h, native_decls.h).
#include "lifted/lifted.h"
#include "lifted/classes.h"
#include "lifted/native_decls.h"
#include "lifted/readable_support.h"

uint64_t CChainedEntityEffect_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(73, 0x82A10720)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82A10720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A10720);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);
	chainedEntityEffect->vtable = 0x820F1840u;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = deleteFlags;
	CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, chainedEntityEffectAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return chainedEntityEffectAddr;
}
PROMOTED_ENTRY(73, sub_82A10720, 0x82A10720) { ctx.r3.u64 = CChainedEntityEffect_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CChainedEntityEffect_DestroyMembers(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x83222AA0)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_83222AA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83222AA0);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint32_t vtable = 0x82005938u;
	// vtable of the entity handles embedded at +236 (m_EC, m_F0) and +244 (m_F4, m_F8)
	const uint32_t entityHandleVtable = 0x820F1664u;

	chainedEntityEffect->vtable = vtable;
	chainedEntityEffect->m_F4 = entityHandleVtable;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	EntityHandle_Release(ctx, base, chainedEntityEffectAddr + 244);
	chainedEntityEffect->m_F8 = 0;

	chainedEntityEffect->m_EC = entityHandleVtable;
	EntityHandle_Release(ctx, base, chainedEntityEffectAddr + 236);
	chainedEntityEffect->m_F0 = 0;

	uint32_t targetHandle = chainedEntityEffect->m_DC;
	if (targetHandle != 0) {
		HandleTarget_Free(ctx, base, targetHandle);
	}
	chainedEntityEffect->m_DC = 0;
	chainedEntityEffect->m_E0 = 0;
	chainedEntityEffect->m_E4 = 0;

	SharedHandle_Release(ctx, base, chainedEntityEffectAddr + 208);

	uint32_t result = C_820EFB9C_Destructor(ctx, base, chainedEntityEffectAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83222AA0, 0x83222AA0) { ctx.r3.u64 = CChainedEntityEffect_DestroyMembers(ctx, base, ctx.r3.u64); }

uint32_t CChainedEntityEffect_GetCombinedMatrix(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint64_t outMatrixAddr) {
	if (!UseLiftedCode(142, 0x83222D78)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = outMatrixAddr; __imp__sub_83222D78(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83222D78);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	uint32_t ownMatrix = CChainedEntityEffectCurve_GetMatrix(ctx, base, chainedEntityEffectAddr);
	// r4 and r9 as the original code leaves them: handed to the callees below and read by callers.
	uint64_t r4Value = ctx.r4.u64;
	uint64_t r9Value{};

	// Copy this effect's 4x4 matrix (64 bytes) into the output buffer; r9 keeps the last 8 bytes copied.
	uint32_t src = ownMatrix;
	uint32_t dst = static_cast<uint32_t>(outMatrixAddr);
	for (int i = 0; i < 8; ++i) {
		r9Value = LOAD64(src);
		STORE64(dst, r9Value);
		src += 8;
		dst += 8;
	}

	// Each effect's entity handle at +236 (m_EC, m_F0) leads to the next effect of the chain:
	// m_F0 points at the slot holding it, and a handle whose slot is empty is released.
	// The return value is the last handle's address, or what releasing that handle returned.
	uint64_t result = chainedEntityEffectAddr + 236;
	uint64_t effectAddr = 0;
	uint32_t slot = chainedEntityEffect->m_F0;
	if (slot != 0) {
		uint32_t nextEffect = LOAD32(slot);
		if (nextEffect != 0) {
			effectAddr = nextEffect;
		} else {
			result = EntityHandle_Release(ctx, base, result);
			r4Value = ctx.r4.u64;
			r9Value = ctx.r9.u64;
		}
	}

	// Multiply the matrix of every further effect of the chain into the output buffer.
	while (static_cast<uint32_t>(effectAddr) != 0) {
		uint64_t effectMatrix = CChainedEntityEffectCurve_GetMatrix(ctx, base, effectAddr);
		r4Value = effectMatrix;
		Matrix4x4_Multiply_821C0210(ctx, base, static_cast<uint32_t>(outMatrixAddr), effectMatrix);
		r9Value = ctx.r9.u64;

		uint32_t nextSlot = LOAD32(static_cast<uint32_t>(effectAddr) + 240);
		result = effectAddr + 236;
		effectAddr = 0;
		if (nextSlot != 0) {
			uint32_t nextEffect = LOAD32(nextSlot);
			if (nextEffect != 0) {
				effectAddr = nextEffect;
			} else {
				result = EntityHandle_Release(ctx, base, result);
				r4Value = ctx.r4.u64;
				r9Value = ctx.r9.u64;
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 and r9 after the call
	ctx.r4.u64 = r4Value;
	ctx.r9.u64 = r9Value;
	return static_cast<uint32_t>(result);
}
PROMOTED_ENTRY(142, sub_83222D78, 0x83222D78) { ctx.r3.u64 = CChainedEntityEffect_GetCombinedMatrix(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CChainedEntityEffect_DestroyTargetAndMembers(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x8322A890)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_8322A890(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8322A890);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t handleAddr = chainedEntityEffectAddr + 328;

	chainedEntityEffect->vtable = 0x820058E8u;

	uint32_t targetHandle = chainedEntityEffect->m_14C;
	if (targetHandle != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, targetHandle);
	}

	STORE32(handleAddr + 4, 0);
	STORE32(handleAddr + 8, 0);
	STORE32(handleAddr + 12, 0);

	chainedEntityEffect->vtable = 0x820F1840u;

	ctx.r1.u64 = stack;
	uint32_t result = CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8322A890, 0x8322A890) { ctx.r3.u64 = CChainedEntityEffect_DestroyTargetAndMembers(ctx, base, ctx.r3.u64); }

uint32_t CChainedEntityEffect_Destructor(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x83235700)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_83235700(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83235700);
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	chainedEntityEffect->vtable = 0x820F1840u;
	return CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
}
PROMOTED_ENTRY(142, sub_83235700, 0x83235700) { ctx.r3.u64 = CChainedEntityEffect_Destructor(ctx, base, ctx.r3.u64); }

uint32_t CChainedEntityEffect_InitializeFromHandle(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint32_t handleAddr, uint64_t arg3) {
	if (!UseLiftedCode(142, 0x83235CE8)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = handleAddr; ctx.r5.u64 = arg3; __imp__sub_83235CE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83235CE8);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u32;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);

	stack = PushStackFrame(base, stack, 112);

	// Copy the caller's shared handle into a stack local and take a reference on it.
	uint32_t handleValue = LOAD32(handleAddr);
	uint32_t refCountAddr = LOAD32(handleAddr + 4);
	STORE32(stack + 80, handleValue);
	STORE32(stack + 84, refCountAddr);

	if (refCountAddr != 0) {
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t restoreMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) + 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32(newCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = restoreMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
	}

	uint32_t localHandleAddr = stack + 80;
	ctx.r1.u64 = stack;
	CChainedEntityEffect_ConstructFromHandle(ctx, base, chainedEntityEffectAddr, localHandleAddr, arg3);
	SharedHandle_Release(ctx, base, localHandleAddr);

	chainedEntityEffect->vtable = 0x820F16D8u;
	chainedEntityEffect->m_130 = LOAD32(handleAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)chainedEntityEffectAddr;
}
PROMOTED_ENTRY(142, sub_83235CE8, 0x83235CE8) { ctx.r3.u64 = CChainedEntityEffect_InitializeFromHandle(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint32_t CChainedEntityEffect_DestroyChildAndMembers(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x83238858)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_83238858(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83238858);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);

	stack = PushStackFrame(base, stack, 96);
	chainedEntityEffect->vtable = 0x820F1780u;
	ctx.r1.u64 = stack;
	CChainedEntityEffectCurve_InvokeActiveCallback(ctx, base, chainedEntityEffectAddr + 304);

	uint32_t destroyTarget = chainedEntityEffect->m_13C;
	if (destroyTarget != 0) {
		uint32_t destroyFunc = LOAD32(LOAD32(destroyTarget));
		ctx.r3.u64 = destroyTarget;
		ctx.r4.u64 = 1;
		ctx.r10.u64 = destroyFunc;
		REX_CALL_INDIRECT_FUNC(destroyFunc);
	}
	chainedEntityEffect->m_13C = 0u;
	chainedEntityEffect->vtable = 0x820F1840u;

	uint32_t result = CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83238858, 0x83238858) { ctx.r3.u64 = CChainedEntityEffect_DestroyChildAndMembers(ctx, base, ctx.r3.u64); }

// sub_83239040  [120 bytes]
uint32_t n_sub_83239040(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x83239040)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_83239040(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83239040);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 96);
	chainedEntityEffect->vtable = 0x82005988u;
	ctx.r1.u64 = stack;
	CChainedEntityEffectCurve_InvokeActiveCallback(ctx, base, chainedEntityEffectAddr + 304);
	uint32_t childObject = chainedEntityEffect->m_13C;
	if (childObject != 0) {
		uint32_t destroyFn = LOAD32(LOAD32(childObject));
		ctx.r3.u64 = childObject;
		ctx.r4.u64 = 1;
		ctx.r10.u64 = destroyFn;
		REX_CALL_INDIRECT_FUNC(destroyFn);
	}
	chainedEntityEffect->m_13C = 0u;
	chainedEntityEffect->vtable = 0x820F1840u;
	uint32_t result = CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83239040, 0x83239040) { ctx.r3.u64 = n_sub_83239040(ctx, base, ctx.r3.u64); }

// sub_83239970  [16 bytes]
uint32_t CChainedEntityEffect_Destructor_83239970(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x83239970)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_83239970(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x83239970);
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	chainedEntityEffect->vtable = 0x820F1840u;
	return CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
}
PROMOTED_ENTRY(142, sub_83239970, 0x83239970) { ctx.r3.u64 = CChainedEntityEffect_Destructor_83239970(ctx, base, ctx.r3.u64); }

uint32_t CChainedEntityEffect_Destructor_8323A390(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	if (!UseLiftedCode(142, 0x8323A390)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_8323A390(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323A390);
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	chainedEntityEffect->vtable = 0x820F1840u;
	return CChainedEntityEffect_DestroyMembers(ctx, base, chainedEntityEffectAddr);
}
PROMOTED_ENTRY(142, sub_8323A390, 0x8323A390) { ctx.r3.u64 = CChainedEntityEffect_Destructor_8323A390(ctx, base, ctx.r3.u64); }

uint64_t CChainedEntityEffect_TryAttachObjectFromSlot(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint64_t objectSlotAddr) {
	if (!UseLiftedCode(142, 0x8323A3A0)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = objectSlotAddr; __imp__sub_8323A3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A3A0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t object = LOAD32((uint32_t)objectSlotAddr);
	uint32_t virtualMethod = LOAD32(LOAD32(object) + 20);
	callTarget.u64 = (uint64_t)virtualMethod;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = object;
	ctx.r4.u64 = objectSlotAddr;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	if ((int32_t)result == 2) {
		CChainedEntityEffect_SetObjectHandle(ctx, base, chainedEntityEffectAddr, objectSlotAddr);
		// re-read: the call may have changed the slot
		uint32_t currentObject = LOAD32((uint32_t)objectSlotAddr);
		uint32_t pChild = chainedEntityEffect->m_pChild;
		result = n_sub_8321F668(ctx, base, pChild, currentObject);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323A3A0, 0x8323A3A0) { ctx.r3.u64 = CChainedEntityEffect_TryAttachObjectFromSlot(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CChainedEntityEffect_Update(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr) {
	constexpr int32_t g_8335EFF4 = int32_t(0x8335EFF4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(142, 0x8323A408)) { ctx.r3.u64 = chainedEntityEffectAddr; __imp__sub_8323A408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A408);
	PPCRegister truncatedIntensity{};
	PPCVRegister fieldVector{};
	PPCVRegister alignedScalar{};
	PPCVRegister broadcastScalar{};
	PPCVRegister scaledVector{};
	PPCVRegister bufferVector{};
	PPCVRegister currentVector{};
	PPCVRegister alignedScalar2{};
	PPCVRegister broadcastScalar2{};
	PPCVRegister producedVector{};
	PPCVRegister combinedVector{};
	uint32_t stack = ctx.r1.u64;

	CChainedEntityEffect* effect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 208);

	// m_intensity += table[index] * scale in one fused multiply-add; index, table and scale are globals
	ctx.fpscr.disableFlushMode();
	uint32_t tableIndex = LOAD32(uint32_t(g_83490000) + 27648);
	uint32_t tableAddr = uint32_t(g_8335EFF4) + 24;
	double scale = double(LOAD_F32(uint32_t(g_8335EFF4) + 40));
	double intensity = double(effect->m_intensity);
	double tableValue = double(LOAD_F32(tableAddr + (tableIndex << 2)));
	effect->m_intensity = float(std::fma(tableValue, scale, intensity));

	int32_t cooldownTicks = effect->m_cooldownTicks;
	if (cooldownTicks > 0) {
		effect->m_cooldownTicks = cooldownTicks - 1;
	}

	// the new intensity truncated to an integer (through the stack, as the original does)
	ctx.fpscr.disableFlushMode();
	double newIntensity = double(effect->m_intensity);
	truncatedIntensity.s64 = std::isnan(newIntensity) ? int64_t(0x80000000U) : newIntensity > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&newIntensity));
	STORE_F64(stack + 80, truncatedIntensity.f64);
	uint32_t intensityInt = LOAD32(stack + 84);
	uint32_t vectorFieldAddr = uint32_t(chainedEntityEffectAddr) + 272;
	uint32_t pChild = effect->m_pChild;
	ctx.r1.u64 = stack;
	CChainedEntityEffectCurve_Evaluate(ctx, base, pChild, 0, intensityInt);
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(ctx.f1.f64));

	// the vector at +272 is scaled by the first evaluation (f1), splatted from the stack slot
	SET_V8(fieldVector, VLOAD(vectorFieldAddr & ~0xF));
	uint32_t scalarAddr = stack + 80;
	SET_V8(alignedScalar, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scalarAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scalarAddr & 0xF) * 16])));
	SET_V8(broadcastScalar, simde_mm_shuffle_epi32(V8(alignedScalar), 0xFF));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(scaledVector, simde_mm_mul_ps(VF(fieldVector), VF(broadcastScalar)));
	VSTORE(vectorFieldAddr & ~0xF, V8(scaledVector));

	// vector state the callee may pass on
	ctx.v11 = scaledVector;
	ctx.v12 = broadcastScalar;
	ctx.v13 = alignedScalar;
	CChainedEntityEffect_GetCombinedMatrix(ctx, base, chainedEntityEffectAddr, stack + 112);
	CChainedEntityEffect_GetCombinedMatrix(ctx, base, chainedEntityEffectAddr, stack + 112);

	SET_V8(bufferVector, VLOAD((stack + 160) & ~0xF));
	ctx.v1 = bufferVector; // state the callee may pass on
	n_sub_83223220(ctx, base, stack + 96, chainedEntityEffectAddr);

	ctx.fpscr.disableFlushMode();
	double currentIntensity = double(effect->m_intensity);
	truncatedIntensity.s64 = std::isnan(currentIntensity) ? int64_t(0x80000000U) : currentIntensity > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&currentIntensity));
	STORE_F64(stack + 80, truncatedIntensity.f64);
	uint32_t pChild2 = effect->m_pChild;
	uint32_t intensityInt2 = LOAD32(stack + 84);
	uint64_t evaluateResult = CChainedEntityEffectCurve_Evaluate(ctx, base, pChild2, 1, intensityInt2);

	// the vector at +272 += (vector written at stack + 96) * (constant / second evaluation)
	SET_V8(currentVector, VLOAD(vectorFieldAddr & ~0xF));
	ctx.fpscr.disableFlushMode();
	double dividend = double(LOAD_F32(0x820994C0u));
	STORE_F32(stack + 80, float(dividend / ctx.f1.f64));
	scalarAddr = stack + 80;
	SET_V8(alignedScalar2, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scalarAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scalarAddr & 0xF) * 16])));
	SET_V8(broadcastScalar2, simde_mm_shuffle_epi32(V8(alignedScalar2), 0xFF));
	SET_V8(producedVector, VLOAD((stack + 96) & ~0xF));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(combinedVector, simde_mm_add_ps(simde_mm_mul_ps(VF(producedVector), VF(broadcastScalar2)), VF(currentVector)));
	VSTORE(vectorFieldAddr & ~0xF, V8(combinedVector));

	effect->m_B0 = uint8_t(1);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return evaluateResult;
}
PROMOTED_ENTRY(142, sub_8323A408, 0x8323A408) { ctx.r3.u64 = CChainedEntityEffect_Update(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8323A650(CpuState& ctx, uint8_t* base, uint64_t entity, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
	if (!UseLiftedCode(142, 0x8323A650)) { ctx.r3.u64 = entity; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r8.u64 = arg5; __imp__sub_8323A650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A650);
	return n_sub_83223408(ctx, base, entity, arg2, arg3, arg4, arg5);
}
PROMOTED_ENTRY(142, sub_8323A650, 0x8323A650) { ctx.r3.u64 = n_sub_8323A650(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t CChainedEntityEffect_ApplyToObject(CpuState& ctx, uint8_t* base, uint64_t curve, uint64_t effect, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(142, 0x8323A658)) { ctx.r3.u64 = curve; ctx.r4.u64 = effect; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r8.u64 = arg5; __imp__sub_8323A658(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A658);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 128);

	// pointer global at 0x8349E518 (0x834A0000 - 6888): its first word, or the sign-extended
	// constant 0x8209003F when it is null
	uint32_t globalPointer = LOAD32(uint32_t(g_834A0000) - 6888);
	uint64_t secondArg = (globalPointer == 0) ? uint64_t(g_8209003F) : uint64_t(LOAD32(globalPointer));

	// virtual method at vtable offset 4; a nonzero low byte of its result enables the rest
	uint32_t methodAt4 = LOAD32(LOAD32((uint32_t)effect) + 4);
	callTarget.u64 = methodAt4;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = effect;
	ctx.r4.u64 = secondArg;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r8.u64 = arg5;
	ctx.r10.u64 = methodAt4;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t accepted = (uint32_t)ctx.r3.u64 & 0xFF;
	if (accepted != 0) {
		ctx.r9.u64 = accepted; // state the callee may pass on
		// the last argument is r8 as the virtual call left it
		n_sub_832235D8(ctx, base, curve, effect, arg3, arg4, ctx.r8.u64);

		uint32_t methodAt12 = LOAD32(LOAD32((uint32_t)effect) + 12);
		callTarget.u64 = methodAt12;
		ctx.r3.u64 = effect;
		ctx.r10.u64 = methodAt12;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// r3 as the last call left it
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_8323A658, 0x8323A658) { ctx.r3.u64 = CChainedEntityEffect_ApplyToObject(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint32_t CChainedEntityEffect_ConstructFromHandle(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint32_t handleAddr, uint64_t arg3) {
	if (!UseLiftedCode(142, 0x8323A6E8)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = handleAddr; ctx.r5.u64 = arg3; __imp__sub_8323A6E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8323A6E8);
	uint32_t stack = ctx.r1.u64;
	// r13: the MSR bits applied while the global lock is held
	const uint32_t msrBits = ctx.r13.u32;
	PPCVRegister zeroVector{};
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 112);

	// copy the incoming shared handle onto the stack and take a reference on its count
	uint32_t handleObject = LOAD32(handleAddr);
	uint32_t refCountAddr = LOAD32(handleAddr + 4);
	STORE32(stack + 84, refCountAddr);
	STORE32(stack + 80, handleObject);
	if (refCountAddr != 0) {
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = msrBits & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			uint32_t newCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
	}

	uint32_t handleCopyAddr = stack + 80;
	ctx.r1.u64 = stack;
	CChainedEntityEffect_Construct(ctx, base, chainedEntityEffectAddr, handleCopyAddr, arg3);
	SharedHandle_Release(ctx, base, handleCopyAddr);
	SET_V8(zeroVector, simde_mm_set1_epi32(int(0x0)));
	chainedEntityEffect->vtable = 0x820F1840u;
	VSTORE((uint32_t)chainedEntityEffectAddr + 272u & ~0xF, V8(zeroVector));
	chainedEntityEffect->m_pChild = LOAD32(handleAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)chainedEntityEffectAddr;
}
PROMOTED_ENTRY(142, sub_8323A6E8, 0x8323A6E8) { ctx.r3.u64 = CChainedEntityEffect_ConstructFromHandle(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint64_t CChainedEntityEffect_InitializeAndAttachChild(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(142, 0x8323A788)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_8323A788(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A788);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CChainedEntityEffectCurve_AddEffect(ctx, base, chainedEntityEffectAddr, arg2, arg3, arg4, arg5, arg6);
	// both fields are read after the call, which may have changed them
	uint32_t d0 = chainedEntityEffect->m_D0;
	uint32_t pChild = chainedEntityEffect->m_pChild;
	uint64_t result = n_sub_8321F668(ctx, base, pChild, d0);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_8323A788, 0x8323A788) { ctx.r3.u64 = CChainedEntityEffect_InitializeAndAttachChild(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CChainedEntityEffect_ApplyToObjectAndAttachChild(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectAddr, uint64_t effect, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(142, 0x8323A7C0)) { ctx.r3.u64 = chainedEntityEffectAddr; ctx.r4.u64 = effect; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_8323A7C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8323A7C0);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffect* chainedEntityEffect = GameObject<CChainedEntityEffect>(base, chainedEntityEffectAddr);
	stack = PushStackFrame(base, stack, 144);

	// value behind the global pointer, or the sign-extended constant when the pointer is null
	uint32_t globalHolder = LOAD32(uint32_t(g_834A0000) - 6888);
	uint64_t globalValue = (globalHolder == 0) ? uint64_t(int64_t(g_8209003F)) : uint64_t(LOAD32(globalHolder));

	PPCRegister callTarget{};
	callTarget.u64 = LOAD32(LOAD32((uint32_t)effect) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = effect;
	ctx.r4.u64 = globalValue;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r8.u64 = arg6;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t proceed = ctx.r3.u32 & 0xFF;
	if (proceed != 0) {
		// state the callee may pass on
		ctx.r9.u64 = proceed;
		n_sub_83224FD0(ctx, base, chainedEntityEffectAddr, effect, arg3, arg4, arg5, arg6);
		n_sub_8321F668(ctx, base, chainedEntityEffect->m_pChild, chainedEntityEffect->m_D0);
		callTarget.u64 = LOAD32(LOAD32((uint32_t)effect) + 12);
		ctx.r3.u64 = effect;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_8323A7C0, 0x8323A7C0) { ctx.r3.u64 = CChainedEntityEffect_ApplyToObjectAndAttachChild(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }
