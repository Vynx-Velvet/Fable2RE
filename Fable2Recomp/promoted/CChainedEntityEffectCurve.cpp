// CChainedEntityEffectCurve (vtable 0x820F1780): methods of the class as readable C++.
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

uint64_t n_sub_821D9D28(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr) {
	if (!UseLiftedCode(3, 0x821D9D28)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; __imp__sub_821D9D28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D9D28);
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffectCurve* chainedEntityEffectCurve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);
	uint32_t curveAddr = static_cast<uint32_t>(chainedEntityEffectCurveAddr);

	stack = PushStackFrame(base, stack, 160);

	bool needsRebuild = true;
	if (LOAD8(curveAddr + 176) == 0) {
		uint32_t curveData = chainedEntityEffectCurve->m_D0;
		needsRebuild = LOAD32(curveAddr + 184) != LOAD32(curveData + 176)
		            || LOAD32(curveAddr + 180) != LOAD32(curveData + 172);
	}

	if (needsRebuild) {
		uint32_t vtable = chainedEntityEffectCurve->vtable;
		ctx.fpscr.disableFlushMode();
		uint32_t updateFunc = LOAD32(vtable + 68);
		STORE_F32(stack + 80, float(double(LOAD_F32(0x820994C0u))));
		callTarget.u64 = updateFunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = chainedEntityEffectCurveAddr;
		ctx.r9.u64 = updateFunc;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t resultPointer = ctx.r3.u32;

		uint32_t tempMatrix = stack + 112;
		n_sub_83222700(ctx, base, tempMatrix, curveAddr);

		// Prepare Altivec argument registers for Math_BuildOrthonormalMatrix.
		PPCVRegister v1Reg{};
		PPCVRegister v2Reg{};
		PPCVRegister vtemp{};
		SET_V8(v1Reg, VLOAD(resultPointer & ~0xF));
		uint32_t scratchAddr = stack + 80;
		SET_V8(vtemp, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(scratchAddr & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratchAddr & 0xF) * 16])));
		SET_V8(v2Reg, simde_mm_shuffle_epi32(V8(vtemp), 0xFF));

		uint64_t matPart0 = LOAD64(tempMatrix);
		uint64_t matPart1 = LOAD64(tempMatrix + 8);
		ctx.v1 = v1Reg;
		ctx.v2 = v2Reg;
		Math_BuildOrthonormalMatrix(ctx, base, curveAddr + 112, matPart0, matPart1);

		uint32_t curveData = chainedEntityEffectCurve->m_D0;
		chainedEntityEffectCurve->m_B8 = LOAD32(curveData + 176);
		chainedEntityEffectCurve->m_B4 = LOAD32(curveData + 172);
		chainedEntityEffectCurve->m_B0 = 0;
	}

	uint64_t result = chainedEntityEffectCurveAddr + 112;
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(3, sub_821D9D28, 0x821D9D28) { ctx.r3.u64 = n_sub_821D9D28(ctx, base, ctx.r3.u64); }

uint64_t CChainedEntityEffectCurve_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlagsArg) {
	if (!UseLiftedCode(72, 0x82A09F10)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlagsArg; __imp__sub_82A09F10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A09F10);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = 0;
	uint32_t deleteFlags = static_cast<uint32_t>(deleteFlagsArg);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlagsArg;
	n_sub_83238858(ctx, base, object);
	result = object;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = object;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(72, sub_82A09F10, 0x82A09F10) { ctx.r3.u64 = CChainedEntityEffectCurve_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_83238850(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(142, 0x83238850)) { ctx.r3.u64 = arg1; __imp__sub_83238850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238850);
	return n_sub_832179C0(ctx, base, arg1 + 304);
}
PROMOTED_ENTRY(142, sub_83238850, 0x83238850) { ctx.r3.u64 = n_sub_83238850(ctx, base, ctx.r3.u64); }

uint64_t n_sub_832388D0(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr, uint64_t arg2) {
	if (!UseLiftedCode(142, 0x832388D0)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; ctx.r4.u64 = arg2; __imp__sub_832388D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832388D0);
	uint32_t stack = ctx.r1.u64;
	uint64_t curveParamsAddr{};
	PPCVRegister curveParams{};
	CChainedEntityEffectCurve* curve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);

	stack = PushStackFrame(base, stack, 240);
	curveParamsAddr = (int64_t)(uint64_t)stack + 160;
	ctx.r1.u64 = stack;
	n_sub_83222D78(ctx, base, arg2, curveParamsAddr);

	SET_V8(curveParams, VLOAD(uint32_t((int64_t)(uint64_t)stack + 208) & ~0xF));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 80) & ~0xF, V8(curveParams));
	ctx.fpscr.disableFlushMode();

	float valueC = LOAD_F32(stack + 84);

	VSTORE(uint32_t((int64_t)(uint64_t)stack + 128) & ~0xF, V8(curveParams));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 96) & ~0xF, V8(curveParams));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 112) & ~0xF, V8(curveParams));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 80) & ~0xF, V8(curveParams));

	float value0 = LOAD_F32(stack + 128);
	float value10 = LOAD_F32(stack + 104);
	float value14 = LOAD_F32(stack + 120);
	float value8 = LOAD_F32(stack + 80);

	VSTORE(uint32_t((int64_t)(uint64_t)stack + 144) & ~0xF, V8(curveParams));
	float value4 = LOAD_F32(stack + 148);

	curve->m_C = valueC;
	curve->m_4 = value4;
	curve->m_8 = value8;
	curve->vtable = AS_U32(value0);
	curve->m_10 = value10;
	curve->m_14 = value14;

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return chainedEntityEffectCurveAddr;
}
PROMOTED_ENTRY(142, sub_832388D0, 0x832388D0) { ctx.r3.u64 = n_sub_832388D0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_83238970(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr, uint64_t arg2) {
	if (!UseLiftedCode(142, 0x83238970)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; ctx.r4.u64 = arg2; __imp__sub_83238970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238970);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffectCurve* chainedEntityEffectCurve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t effectAddr = LOAD32((uint32_t)arg2);
	uint32_t virtualFn = LOAD32(LOAD32(effectAddr) + 20);

	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)virtualFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = effectAddr;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result == 8) {
		n_sub_8323A3A0(ctx, base, chainedEntityEffectCurveAddr, arg2);
		uint32_t effectAddr2 = LOAD32((uint32_t)arg2);
		uint32_t v140 = chainedEntityEffectCurve->m_140;
		result = n_sub_83216568(ctx, base, v140, effectAddr2);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83238970, 0x83238970) { ctx.r3.u64 = n_sub_83238970(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CChainedEntityEffectCurve_Update(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr) {
	if (!UseLiftedCode(142, 0x832389D8)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; __imp__sub_832389D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x832389D8);

	CChainedEntityEffectCurve* curve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);

	uint32_t stack = ctx.r1.u64;
	PPCVRegister savedV127 = ctx.v127;
	VSTORE((stack + 0xFFFFFFA0u) & ~0xF, V8(savedV127));

	stack = PushStackFrame(base, stack, 448);
	ctx.r1.u64 = stack;

	uint64_t result = CChainedEntityEffect_Update(ctx, base, chainedEntityEffectCurveAddr);

	if (LOAD32((uint32_t)chainedEntityEffectCurveAddr + 316) != 0) {
		uint32_t flagAddr = (uint32_t)chainedEntityEffectCurveAddr + 304;
		ChainedEntityEffectCurve_UpdateFlag(ctx, base, flagAddr);

		ctx.fpscr.disableFlushMode();
		double frameValue = double(curve->m_FC);
		PPCRegister converted{};
		converted.s64 = std::isnan(frameValue) ? int64_t(0x80000000U)
			: frameValue > double(INT_MAX) ? INT_MAX
			: simde_mm_cvttsd_si32(simde_mm_load_sd(&frameValue));
		STORE_F64(stack + 192, converted.f64);
		uint32_t frameIndex = LOAD32(stack + 196);

		uint32_t effectAddr = curve->m_140;

		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr, 15, frameIndex);
		double eval15 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr, 17, frameIndex);
		double eval17 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr, 18, frameIndex);
		double eval18 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr, 24, frameIndex);
		double eval24 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();

		uint64_t stack208 = (uint64_t)stack + 208;
		n_sub_8321F598(ctx, base, stack208, effectAddr, 3, frameIndex);

		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr, 16, frameIndex);
		double eval16 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();

		double ratio = C_820066C8_GetRatio(ctx, base, chainedEntityEffectCurveAddr);
		ctx.fpscr.disableFlushMode();
		double scaledValue = double(float(eval16 * ratio));
		STORE_F32(stack + 192, float(scaledValue));

		uint64_t stack224 = (uint64_t)stack + 224;
		PPCRegister scratch{};
		scratch.u32 = stack + 192;
		PPCVRegister shuffled{};
		PPCVRegister broadcast{};
		PPCVRegister source{};
		PPCVRegister scaledVector{};
		SET_V8(shuffled, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(broadcast, simde_mm_shuffle_epi32(V8(shuffled), 0xFF));
		SET_V8(source, VLOAD((stack + 208) & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(scaledVector, simde_mm_mul_ps(VF(source), VF(broadcast)));
		ctx.f1.f64 = ratio;
		ctx.f7.f64 = scaledValue;
		ctx.f8.f64 = eval16;
		ctx.v12 = source;
		ctx.v13 = broadcast;
		n_sub_83222D78(ctx, base, chainedEntityEffectCurveAddr, stack224);

		ctx.fpscr.disableFlushMode();
		float defaultComponent = LOAD_F32(0x820994B4u);
		STORE_F32(stack + 160, defaultComponent);
		STORE_F32(stack + 164, defaultComponent);
		STORE_F32(stack + 168, defaultComponent);

		uint32_t effectAddr2 = curve->m_140;

		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr2, 19, frameIndex);
		double eval19 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 160, float(eval19));
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr2, 20, frameIndex);
		double eval20 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 164, float(eval20));
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr2, 21, frameIndex);
		double eval21 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 168, float(eval21));

		STORE_F32(stack + 176, defaultComponent);
		STORE32(stack + 184, 0u);
		STORE_F32(stack + 180, defaultComponent);

		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr2, 23, frameIndex);
		double eval23 = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 180, float(eval23));
		CChainedEntityEffectCurve_Evaluate(ctx, base, effectAddr2, 22, frameIndex);
		double eval22 = ctx.f1.f64;
		uint32_t effectData = effectAddr2;
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 176, float(eval22));

		constexpr int32_t g_83360000 = int32_t(0x83360000);
		int64_t globalOffset = (int64_t)g_83360000 - 4108;
		uint64_t stack288 = (uint64_t)stack + 288;

		STORE32(stack + 184, LOAD32(effectData + 200));
		STORE32(stack + 200, LOAD32(effectData + 196));
		uint32_t globalValue = LOAD32((uint32_t)globalOffset + 44);
		uint8_t effectByte = LOAD8(effectData + 204);
		ctx.r5.u64 = (uint64_t)globalOffset;
		ctx.r6.s64 = g_83360000;
		ctx.r7.u64 = effectData;
		n_sub_83222D78(ctx, base, chainedEntityEffectCurveAddr, stack288);

		uint32_t callbackObj = curve->m_13C;
		uint64_t stack176 = (uint64_t)stack + 176;

		STORE32(stack + 148, globalValue);
		ctx.fpscr.disableFlushMode();
		STORE32(stack + 140, stack + 176);

		uint32_t vtable = LOAD32(callbackObj);
		PPCVRegister v1Reg{};
		PPCVRegister v2Reg{};
		PPCVRegister v3Reg{};
		SET_V8(v2Reg, VLOAD((stack + 240) & ~0xF));
		SET_V8(v1Reg, VLOAD(((uint64_t)stack + 336) & ~0xF));
		SET_V8(v3Reg, V8(scaledVector));

		uint32_t callbackFn = LOAD32(vtable + 16);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)callbackFn;

		ctx.r3.u64 = callbackObj;
		ctx.r4.u64 = callbackFn;
		ctx.r5.u64 = vtable;
		ctx.r6.u64 = stack176;
		ctx.r7.u64 = (uint64_t)stack + 336;
		ctx.r8.u64 = effectByte;
		ctx.r9.u64 = (uint64_t)stack + 200;
		ctx.r10.u64 = (uint64_t)stack + 160;
		ctx.f1.f64 = eval24;
		ctx.f2.f64 = eval15;
		ctx.f3.f64 = eval17;
		ctx.f4.f64 = eval18;
		ctx.v1 = v1Reg;
		ctx.v2 = v2Reg;
		ctx.v3 = v3Reg;

		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 448);
	SET_V8(savedV127, VLOAD((stack + 0xFFFFFFA0u) & ~0xF));
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_832389D8, 0x832389D8) { ctx.r3.u64 = CChainedEntityEffectCurve_Update(ctx, base, ctx.r3.u64); }

uint64_t n_sub_83238BF0(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr, uint64_t arg2, uint64_t arg3, double floatArg1) {
	if (!UseLiftedCode(142, 0x83238BF0)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; ctx.r5.u64 = arg2; ctx.r6.u64 = arg3; ctx.f1.f64 = floatArg1; __imp__sub_83238BF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238BF0);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR13 = ctx.r13.u64;
	CChainedEntityEffectCurve* chainedEntityEffectCurve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);
	stack = PushStackFrame(base, stack, 160);

	// Keep the original effect addresses for field loads; the shared-handle
	// calls may overwrite the argument registers used for the next call.
	uint32_t effectAAddr = (uint32_t)arg2;
	uint32_t effectBAddr = (uint32_t)arg3;
	double originalFloatArg1 = floatArg1;
	uint64_t callArgA = arg2;
	uint64_t callArgB = arg3;

	uint32_t handleA = stack + 88;       // shared handle built from arg2
	uint32_t handleB = stack + 80;       // shared handle built from arg3
	uint32_t resultHandle = stack + 96;  // handle produced by the curve
	uint32_t curveOut = stack + 104;

	uint32_t aControlBlock = LOAD32(effectAAddr + 212);
	uint32_t aObject = LOAD32(effectAAddr + 208);

	STORE32(handleA, 0);
	STORE32(handleA + 4, 0);
	STORE32(handleB, 0);
	STORE32(handleB + 4, 0);

	if (aControlBlock != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = callArgA;
		ctx.r6.u64 = callArgB;
		ctx.f1.f64 = floatArg1;
		SharedHandle_Release(ctx, base, handleA);
		callArgA = ctx.r5.u64;
		callArgB = ctx.r6.u64;
		floatArg1 = ctx.f1.f64;
		uint32_t refCount = LOAD32(aControlBlock);
		STORE32(handleA, aObject);
		STORE32(handleA + 4, aControlBlock);
		STORE32(aControlBlock, refCount + 1);
	}

	uint32_t bControlBlock = LOAD32(effectBAddr + 212);
	uint32_t bObject = LOAD32(effectBAddr + 208);
	if (bControlBlock != 0) {
		ctx.r1.u64 = stack;
		ctx.r5.u64 = callArgA;
		ctx.r6.u64 = callArgB;
		ctx.f1.f64 = floatArg1;
		SharedHandle_Release(ctx, base, handleB);
		uint32_t refCount = LOAD32(bControlBlock);
		STORE32(handleB, bObject);
		STORE32(handleB + 4, bControlBlock);
		STORE32(bControlBlock, refCount + 1);
	}

	// blend the two effect handles through the curve into a fresh handle pair
	ctx.fpscr.disableFlushMode();
	floatArg1 = originalFloatArg1;
	ctx.r1.u64 = stack;
	uint32_t newPair = n_sub_832168D8(ctx, base, curveOut, handleA, handleB, floatArg1);
	uint32_t savedLockState = ctx.r9.u64;

	STORE32(resultHandle, LOAD32(newPair));
	uint32_t newControlBlock = LOAD32(newPair + 4);
	STORE32(resultHandle + 4, newControlBlock);

	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	uint32_t atomicTemp = 0;
	uint32_t atomicAddr = 0;

	if (newControlBlock != 0) {
		// intrusive reference count increment on the control block
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			savedLockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(newControlBlock);
			atomicTemp = __builtin_bswap32(ctx.reserved.u32);
			atomicTemp = (int32_t)atomicTemp + 1;
			atomicAddr = newControlBlock;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(atomicAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)atomicTemp));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedLockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
	}

	uint32_t callTargetAddr = LOAD32(uint32_t(chainedEntityEffectCurve->vtable) + 72);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)callTargetAddr;
	ctx.r3.u64 = chainedEntityEffectCurveAddr;
	ctx.r4.u64 = resultHandle;
	ctx.r9.u64 = savedLockState;
	ctx.r10.u64 = callTargetAddr;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	SharedHandle_Release(ctx, base, resultHandle);
	SharedHandle_Release(ctx, base, curveOut);
	SharedHandle_Release(ctx, base, handleB);
	uint64_t result = SharedHandle_Release(ctx, base, handleA);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83238BF0, 0x83238BF0) { ctx.r3.u64 = n_sub_83238BF0(ctx, base, ctx.r3.u64, ctx.r5.u64, ctx.r6.u64, ctx.f1.f64); }

uint64_t n_sub_83238D08(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
	if (!UseLiftedCode(142, 0x83238D08)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r8.u64 = arg5; __imp__sub_83238D08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238D08);
	return n_sub_83223408(ctx, base, arg1, arg2, arg3, arg4, arg5);
}
PROMOTED_ENTRY(142, sub_83238D08, 0x83238D08) { ctx.r3.u64 = n_sub_83238D08(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t n_sub_83238D10(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
    if (!UseLiftedCode(142, 0x83238D10)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r8.u64 = arg5; __imp__sub_83238D10(ctx, base); return ctx.r3.u64; }
    LiftedFrame frame(0x83238D10);
    uint32_t stack = ctx.r1.u64;
    stack = PushStackFrame(base, stack, 128);

    constexpr int32_t kDefaultEffectValue = int32_t(0x8209003F);
    uint32_t effectValuePtr = LOAD32(0x834A0000u - 7136u);
    uint64_t effectValue = (effectValuePtr == 0) ? (uint64_t)kDefaultEffectValue : LOAD32(effectValuePtr);

    uint32_t effectObject = (uint32_t)arg2;
    uint32_t firstVirtual = LOAD32(LOAD32(effectObject) + 4);

    PPCRegister callTarget{};
    callTarget.u64 = firstVirtual;

    ctx.r1.u64 = stack;
    ctx.r3.u64 = arg2;
    ctx.r4.u64 = effectValue;
    ctx.r5.u64 = arg3;
    ctx.r6.u64 = arg4;
    ctx.r8.u64 = arg5;
    ctx.r10.u64 = firstVirtual;
    REX_CALL_INDIRECT_FUNC(callTarget.u32);

    uint32_t handled = (uint32_t)(ctx.r3.u64 & 0xFF);
    if (handled != 0) {
        ctx.r9.u64 = handled;
        n_sub_8323A658(ctx, base, arg1, arg2, arg3, arg4, ctx.r8.u64);

        uint32_t secondVirtual = LOAD32(LOAD32(effectObject) + 12);
        callTarget.u64 = secondVirtual;
        ctx.r3.u64 = arg2;
        ctx.r10.u64 = secondVirtual;
        REX_CALL_INDIRECT_FUNC(callTarget.u32);
    }

    stack = PopStackFrame(stack, 128);
    ctx.r1.u64 = stack;
    return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_83238D10, 0x83238D10) { ctx.r3.u64 = n_sub_83238D10(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r8.u64); }

uint64_t n_sub_83238F48(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(142, 0x83238F48)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_83238F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238F48);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffectCurve* chainedEntityEffectCurve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_83224818(ctx, base, chainedEntityEffectCurveAddr, arg2, arg3, arg4, arg5, arg6);
	uint32_t curveSource = chainedEntityEffectCurve->m_D0;
	uint32_t chainedCurve = chainedEntityEffectCurve->m_120;
	n_sub_8321F668(ctx, base, chainedCurve, curveSource);
	uint32_t curveSource2 = chainedEntityEffectCurve->m_D0;
	uint32_t curveDest = chainedEntityEffectCurve->m_140;
	uint64_t result = n_sub_83216568(ctx, base, curveDest, curveSource2);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(142, sub_83238F48, 0x83238F48) { ctx.r3.u64 = n_sub_83238F48(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t n_sub_83238F90(CpuState& ctx, uint8_t* base, uint64_t chainedEntityEffectCurveAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(142, 0x83238F90)) { ctx.r3.u64 = chainedEntityEffectCurveAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_83238F90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x83238F90);
	uint32_t stack = ctx.r1.u64;
	CChainedEntityEffectCurve* chainedEntityEffectCurve = GameObject<CChainedEntityEffectCurve>(base, chainedEntityEffectCurveAddr);
	stack = PushStackFrame(base, stack, 144);

	// Current effect-curve id from the global slot, or the built-in default when unset.
	uint32_t curveIdSlot = LOAD32(uint32_t(g_834A0000) - 7136);
	uint64_t curveId;
	if (curveIdSlot == 0) {
		curveId = uint64_t(int64_t(g_8209003F));
	} else {
		curveId = LOAD32(curveIdSlot);
	}

	uint32_t vtable = LOAD32(uint32_t(arg2));
	uint32_t beginFn = LOAD32(vtable + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = curveId;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r8.u64 = arg6;
	ctx.r10.u64 = beginFn;
	REX_CALL_INDIRECT_FUNC(beginFn);
	uint32_t didBegin = uint32_t(ctx.r3.u64) & 0xFF;

	if (didBegin != 0) {
		ctx.r9.u64 = didBegin;
		n_sub_8323A7C0(ctx, base, chainedEntityEffectCurveAddr, arg2, arg3, arg4, arg5, arg6);

		uint32_t curveD0 = chainedEntityEffectCurve->m_D0;
		uint32_t curve140 = chainedEntityEffectCurve->m_140;
		n_sub_83216568(ctx, base, curve140, curveD0);

		uint32_t endFn = LOAD32(LOAD32(uint32_t(arg2)) + 12);
		ctx.r3.u64 = arg2;
		ctx.r10.u64 = endFn;
		REX_CALL_INDIRECT_FUNC(endFn);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(142, sub_83238F90, 0x83238F90) { ctx.r3.u64 = n_sub_83238F90(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }
