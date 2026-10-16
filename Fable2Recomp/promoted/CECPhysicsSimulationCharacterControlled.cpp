// CECPhysicsSimulationCharacterControlled (vtable 0x820071C0): methods of the class as readable C++.
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

uint64_t n_sub_821E3D60(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(4, 0x821E3D60)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; __imp__sub_821E3D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E3D60);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;

	CECPhysicsSimulationCharacterControlled* character = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);

	// The original prologue saves v127 just below the incoming stack pointer.
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 144);

	PPCVRegister inputVec = ctx.v1;

	uint64_t resultBuffer = (int64_t)(uint64_t)stack + 96;
	uint32_t vtable = character->vtable;
	uint32_t getVectorFn = LOAD32(vtable + 64);
	callTarget.u64 = getVectorFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = resultBuffer;
	ctx.r4.u64 = physicsSimulationCharacterControlledAddr;
	ctx.r10.u64 = getVectorFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t vectorSrcPtr = ctx.r3.u64;
	PPCVRegister srcVec{};
	SET_V8(srcVec, VLOAD((uint32_t)vectorSrcPtr & ~0xF));
	ctx.r9.u64 = vectorSrcPtr;

	uint32_t secondaryObject = character->m_4;
	double value = n_sub_82207928(ctx, base, secondaryObject);

	int32_t f32Base = g_820A0000;
	int32_t f64Base = g_83320000;
	ctx.fpscr.enableFlushMode();
	PPCVRegister deltaVec{};
	SET_VF(deltaVec, simde_mm_sub_ps(VF(inputVec), VF(srcVec)));
	uint32_t vtable2 = character->vtable;
	uint32_t splatSource = stack + 80;
	uint32_t flag = 1;
	ctx.fpscr.disableFlushModeUnconditional();
	double denominator = LOAD_F64((uint32_t)f64Base - 27376);
	double quotient = value / denominator;
	double numerator = double(LOAD_F32((uint32_t)f32Base - 27456));
	uint32_t method128 = LOAD32(vtable2 + 128);
	double quotientF = double(float(quotient));
	double ratio = double(float(numerator / quotientF));
	STORE_F32(splatSource, float(ratio));
	scratch.u32 = splatSource;
	PPCVRegister broadcastVec{};
	SET_V8(broadcastVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	PPCVRegister broadcastLane3{};
	SET_V8(broadcastLane3, simde_mm_shuffle_epi32(V8(broadcastVec), 0xFF));
	ctx.fpscr.enableFlushModeUnconditional();
	PPCVRegister scaled{};
	SET_VF(scaled, simde_mm_mul_ps(VF(deltaVec), VF(broadcastLane3)));

	callTarget.u64 = method128;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	ctx.r4.u64 = flag;
	ctx.r5.u64 = splatSource;
	ctx.r6.u64 = vtable2;
	ctx.r7.s64 = f32Base;
	ctx.r8.s64 = f64Base;
	ctx.f1.f64 = value;
	ctx.f11.f64 = ratio;
	ctx.f12.f64 = quotientF;
	ctx.f13.f64 = quotient;
	ctx.v1 = scaled;
	ctx.v11 = broadcastLane3;
	ctx.v12 = broadcastVec;
	ctx.v13 = deltaVec;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 144);
	// callers read r0 after the call (the epilogue leaves its v127 restore offset there)
	ctx.r0.u64 = 0xFFFFFFE0;
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(4, sub_821E3D60, 0x821E3D60) { ctx.r3.u64 = n_sub_821E3D60(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82201E58(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, uint64_t vectorAddr) {
	if (!UseLiftedCode(5, 0x82201E58)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.r4.u64 = vectorAddr; __imp__sub_82201E58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82201E58);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	// Register contents passed on from call to call; the caller reads f1, f13 and v13 back.
	uint32_t carriedR3 = 0;
	uint64_t carriedR4 = vectorAddr;
	uint64_t carriedR9 = 0;
	double carriedF1 = 0.0;
	double carriedF13 = ctx.f13.f64;
	PPCVRegister carriedV13 = ctx.v13;
	PPCVRegister vec{};
	PPCRegister callTarget{};
	uint32_t isNaN = 0;

	stack = PushStackFrame(base, stack, 160);

	// Stop when x, y or z of the vector is NaN.
	SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
	VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
	carriedF1 = double(LOAD_F32(stack + 80));
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	isNaN = Math_IsNaN(ctx, base, carriedF1);
	if ((int32_t)isNaN == 0) {
		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 84));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 88));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		// Also stop when the squared length of x, y, z exceeds the limit.
		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(carriedV13, simde_mm_dp_ps(VF(vec), VF(vec), 0xEF));
		ctx.fpscr.disableFlushModeUnconditional();
		const double squaredLengthLimit = double(LOAD_F32(0x820C860Cu));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(carriedV13));
		carriedF13 = double(LOAD_F32(stack + 80));
		if (carriedF13 > squaredLengthLimit) goto done;

		carriedR3 = physicsSimulationCharacterControlled->m_4;
		// state the callee may pass on
		ctx.f1.f64 = carriedF1;
		ctx.f13.f64 = carriedF13;
		carriedF1 = n_sub_82207928(ctx, base, carriedR3);
		carriedR9 = ctx.r9.u64;
		carriedF13 = ctx.f13.f64;

		const uint32_t listAddr = uint32_t(physicsSimulationCharacterControlledAddr + 180);
		ctx.fpscr.disableFlushMode();
		const double divisor = LOAD_F64(0x83319510u);
		uint32_t node = LOAD32(uint32_t(physicsSimulationCharacterControlled->m_B8));
		const double scaledValue = double(float(carriedF1 / divisor));

		// Walk the list headed by the node at m_B8 (next pointer at +0, entity handle at +8).
		for (;;) {
			if (node == LOAD32(listAddr + 4)) break;
			if (node == LOAD32(listAddr + 4)) { ppc_trap(ctx, base, 22); }
			const uint32_t handleRecord = LOAD32(node + 12);
			const uint64_t handleAddr = uint64_t(node) + 8;
			if (handleRecord != 0) {
				const uint32_t target = LOAD32(handleRecord);
				if (target != 0) {
					const uint32_t innerObject = LOAD32(target + 8);
					const uint32_t slot1Fn = LOAD32(LOAD32(innerObject) + 4);
					callTarget.u64 = slot1Fn;
					// state the callee may pass on
					ctx.r3.u64 = innerObject;
					ctx.r4.u64 = carriedR4;
					ctx.r9.u64 = carriedR9;
					ctx.r10.u64 = slot1Fn;
					ctx.f1.f64 = carriedF1;
					ctx.v13 = carriedV13;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					carriedR3 = ctx.r3.u32;
					carriedR4 = ctx.r4.u64;
					carriedF1 = ctx.f1.f64;
					carriedF13 = ctx.f13.f64;
					carriedV13 = ctx.v13;
					carriedR9 = carriedR3 & 0xFF;
					if ((uint32_t)carriedR9 != 0) {
						// Resolve the handle again; release it when its target is gone.
						uint32_t currentTarget = 0;
						const uint32_t record = LOAD32(node + 12);
						if (record != 0) {
							currentTarget = LOAD32(record);
							if (currentTarget == 0) {
								ctx.r9.u64 = carriedR9;
								ctx.r10.u64 = currentTarget;
								EntityHandle_Release(ctx, base, handleAddr);
								carriedR9 = ctx.r9.u64;
								carriedF13 = ctx.f13.f64;
								carriedV13 = ctx.v13;
							}
						}
						const uint32_t currentInner = LOAD32(currentTarget + 8);
						ctx.fpscr.disableFlushMode();
						carriedF1 = scaledValue;
						const uint32_t slot3Fn = LOAD32(LOAD32(currentInner) + 12);
						callTarget.u64 = slot3Fn;
						ctx.r3.u64 = currentInner;
						ctx.r4.u64 = physicsSimulationCharacterControlledAddr;
						ctx.r5.u64 = vectorAddr;
						ctx.r9.u64 = carriedR9;
						ctx.r10.u64 = slot3Fn;
						ctx.f1.f64 = carriedF1;
						REX_CALL_INDIRECT_FUNC(callTarget.u32);
						carriedR3 = ctx.r3.u32;
						carriedR4 = ctx.r4.u64;
						carriedR9 = ctx.r9.u64;
						carriedF1 = ctx.f1.f64;
						carriedF13 = ctx.f13.f64;
						carriedV13 = ctx.v13;
					}
				} else {
					// The handle's target is gone: release the handle.
					ctx.r4.u64 = carriedR4;
					ctx.r9.u64 = carriedR9;
					ctx.r10.u64 = target;
					ctx.f1.f64 = carriedF1;
					ctx.v13 = carriedV13;
					carriedR3 = EntityHandle_Release(ctx, base, handleAddr);
					carriedR4 = ctx.r4.u64;
					carriedR9 = ctx.r9.u64;
					carriedF1 = ctx.f1.f64;
					carriedF13 = ctx.f13.f64;
					carriedV13 = ctx.v13;
				}
			}
			if (node == LOAD32(listAddr + 4)) { ppc_trap(ctx, base, 22); }
			node = LOAD32(node);
		}

		// Test x, y and z for NaN again after the calls.
		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 80));
		ctx.r3.u64 = carriedR3;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 84));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorAddr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 88));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
	}
done:
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read f1, f13 and v13 after the call
	ctx.f1.f64 = carriedF1;
	ctx.f13.f64 = carriedF13;
	ctx.v13 = carriedV13;
	return isNaN;
}
PROMOTED_ENTRY(5, sub_82201E58, 0x82201E58) { ctx.r3.u64 = n_sub_82201E58(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82202B80(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, uint64_t vectorPtr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(5, 0x82202B80)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.r4.u64 = vectorPtr; __imp__sub_82202B80(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82202B80);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	// Register contents passed on from call to call; the caller reads r5, f1, f13 and v13 back.
	uint64_t carriedR3 = 0;
	uint64_t carriedR5 = ctx.r5.u64;
	double carriedF1 = 0.0;
	double carriedF13 = ctx.f13.f64;
	PPCVRegister carriedV13 = ctx.v13;
	PPCVRegister vec{};
	PPCRegister callTarget{};
	uint32_t isNaN = 0;

	stack = PushStackFrame(base, stack, 144);

	// Stop when x, y or z of the vector is NaN.
	SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
	VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
	carriedF1 = double(LOAD_F32(stack + 80));
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	isNaN = Math_IsNaN(ctx, base, carriedF1);
	if ((int32_t)isNaN == 0) {
		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 84));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 88));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		// Also stop when the squared length of x, y, z exceeds the limit.
		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(carriedV13, simde_mm_dp_ps(VF(vec), VF(vec), 0xEF));
		ctx.fpscr.disableFlushModeUnconditional();
		const double squaredLengthLimit = double(LOAD_F32(0x820C860Cu));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(carriedV13));
		carriedF13 = double(LOAD_F32(stack + 80));
		if (carriedF13 > squaredLengthLimit) goto done;

		const uint32_t root = LOAD32(uint32_t(g_83490000) + 26912);
		const uint32_t objA = LOAD32(root + 12);
		const uint32_t objB = LOAD32(objA + 88);
		const uint32_t objC = LOAD32(objB + 4);
		const uint32_t objD = LOAD32(objC + 24);
		const uint32_t objDVtable = LOAD32(objD);
		const uint32_t method64 = LOAD32(objDVtable + 64);
		callTarget.u64 = method64;
		// state the callee may pass on
		ctx.r3.u64 = objD;
		ctx.r4.u64 = vectorPtr;
		ctx.r6.u64 = method64;
		ctx.r7.u64 = objDVtable;
		ctx.r8.u64 = objC;
		ctx.r9.u64 = objB;
		ctx.r10.u64 = objA;
		ctx.f1.f64 = carriedF1;
		ctx.f13.f64 = carriedF13;
		ctx.v13 = carriedV13;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		// The call returns the object whose word at +4 is the list's head node.
		const uint32_t listOwner = ctx.r3.u32;
		carriedF1 = ctx.f1.f64;
		carriedF13 = ctx.f13.f64;
		carriedV13 = ctx.v13;

		carriedR5 = physicsSimulationCharacterControlled->m_4;
		carriedF1 = n_sub_82207928(ctx, base, uint32_t(carriedR5));
		carriedF13 = ctx.f13.f64;
		uint32_t carriedR4 = uint32_t(g_83320000);
		const uint32_t initialHead = LOAD32(listOwner + 4);
		carriedR3 = initialHead;
		ctx.fpscr.disableFlushMode();
		const double divisor = LOAD_F64(uint32_t(g_83320000) - 27376);
		const double scaledValue = double(float(carriedF1 / divisor));
		uint32_t node = LOAD32(initialHead);

		// Walk the list (next pointer at +0, entity handle at +8) until its head node comes round again.
		for (;;) {
			const uint32_t head = LOAD32(listOwner + 4);
			if (node == head) break;
			const uint32_t handleRecord = LOAD32(node + 12);
			const uint64_t handleAddr = uint64_t(node) + 8;
			carriedR3 = handleAddr;
			if (handleRecord != 0) {
				uint64_t carriedR9 = LOAD32(handleRecord);
				if ((uint32_t)carriedR9 == 0) {
					// The handle's target is gone: release the handle.
					ctx.r4.u64 = carriedR4;
					ctx.r5.u64 = carriedR5;
					ctx.r9.u64 = carriedR9;
					ctx.r10.u64 = head;
					ctx.f1.f64 = carriedF1;
					carriedR3 = EntityHandle_Release(ctx, base, handleAddr);
					carriedR4 = ctx.r4.u32;
					carriedR5 = ctx.r5.u64;
					carriedF1 = ctx.f1.f64;
					carriedF13 = ctx.f13.f64;
					carriedV13 = ctx.v13;
				} else {
					// Resolve the handle again; release it when its target is gone.
					uint32_t target = 0;
					const uint32_t record = LOAD32(node + 12);
					if (record != 0) {
						target = LOAD32(record);
						if (target == 0) {
							ctx.r4.u64 = carriedR4;
							ctx.r5.u64 = carriedR5;
							ctx.r9.u64 = carriedR9;
							ctx.r10.u64 = target;
							ctx.f1.f64 = carriedF1;
							EntityHandle_Release(ctx, base, handleAddr);
							carriedR9 = ctx.r9.u64;
							carriedF13 = ctx.f13.f64;
							carriedV13 = ctx.v13;
						}
					}
					const uint32_t innerObject = LOAD32(target + 8);
					ctx.fpscr.disableFlushMode();
					carriedF1 = scaledValue;
					const uint32_t slot3Fn = LOAD32(LOAD32(innerObject) + 12);
					callTarget.u64 = slot3Fn;
					ctx.r3.u64 = innerObject;
					ctx.r4.u64 = physicsSimulationCharacterControlledAddr;
					ctx.r5.u64 = vectorPtr;
					ctx.r9.u64 = carriedR9;
					ctx.r10.u64 = slot3Fn;
					ctx.f1.f64 = carriedF1;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					carriedR3 = ctx.r3.u64;
					carriedR4 = ctx.r4.u32;
					carriedR5 = ctx.r5.u64;
					carriedF1 = ctx.f1.f64;
					carriedF13 = ctx.f13.f64;
					carriedV13 = ctx.v13;
				}
			}
			if (node == LOAD32(listOwner + 4)) { ppc_trap(ctx, base, 22); }
			node = LOAD32(node);
		}

		// Test x, y and z for NaN again after the calls.
		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 80));
		ctx.r3.u64 = carriedR3;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 84));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
		if ((int32_t)isNaN != 0) goto done;

		SET_V8(vec, VLOAD((uint32_t)vectorPtr & ~0xF));
		VSTORE(uint32_t(stack + 80) & ~0xF, V8(vec));
		ctx.fpscr.disableFlushMode();
		carriedF1 = double(LOAD_F32(stack + 88));
		ctx.r3.u64 = isNaN;
		isNaN = Math_IsNaN(ctx, base, carriedF1);
	}
done:
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r5, f1, f13 and v13 after the call
	ctx.r5.u64 = carriedR5;
	ctx.f1.f64 = carriedF1;
	ctx.f13.f64 = carriedF13;
	ctx.v13 = carriedV13;
	return isNaN;
}
PROMOTED_ENTRY(5, sub_82202B80, 0x82202B80) { ctx.r3.u64 = n_sub_82202B80(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t Math_IsNaN(CpuState& ctx, uint8_t* base, double inputValue) {
	if (!UseLiftedCode(5, 0x822050E0)) { ctx.f1.f64 = inputValue; __imp__sub_822050E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822050E0);
	uint32_t stack = ctx.r1.u32;
	ctx.fpscr.disableFlushMode();
	STORE_F64(stack + 16, inputValue);

	// Exponent bits and top mantissa bit of the stored double (sign masked off).
	uint32_t highBits = LOAD16(stack + 16) & 0x7FF8;
	if (highBits == 0x7FF0) {
		// Exponent all ones with top mantissa bit clear: NaN only if some other mantissa bit is set.
		// Callers read r10 and cr0 after the call: r10 holds the mantissa word tested last,
		// cr0 the signed compare of the high mantissa bits with zero.
		uint32_t mantissaHigh = LOAD32(stack + 16) & 0x7FFFF;
		ctx.cr0.compare<int32_t>((int32_t)mantissaHigh, 0, ctx.xer);
		ctx.r10.u64 = mantissaHigh;
		if (mantissaHigh != 0) return 1;
		uint32_t mantissaLow = LOAD32(stack + 20);
		ctx.r10.u64 = mantissaLow;
		return mantissaLow != 0 ? 1 : 0;
	}
	// Exponent all ones with the top mantissa bit set: a quiet NaN.
	return highBits == 0x7FF8 ? 1 : 0;
}
PROMOTED_ENTRY(5, sub_822050E0, 0x822050E0) { ctx.r3.u64 = Math_IsNaN(ctx, base, ctx.f1.f64); }

uint32_t n_sub_8222E7D0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr) {
	if (!UseLiftedCode(6, 0x8222E7D0)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; __imp__sub_8222E7D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8222E7D0);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t getEntityFn = LOAD32(uint32_t(physicsSimulationCharacterControlled->vtable) + 96);
	PPCRegister callTarget{};
	callTarget.u64 = getEntityFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	ctx.r10.u64 = getEntityFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t entity = ctx.r3.u64;
	// r9 as left for the caller on the paths that return 1
	uint64_t r9Out = 0;
	STORE32(stack + 80, 0);
	if ((uint32_t)entity != 0) {
		uint64_t componentOut = (int64_t)(uint64_t)stack + 80;
		// state the callee may pass on
		ctx.r9.u64 = 0;
		uint32_t hasPhysicsComponent = Entity_GetPhysicsComponent(ctx, base, entity, componentOut);
		r9Out = ctx.r9.u64;
		if ((hasPhysicsComponent & 0xFF) != 0) {
			uint32_t componentByte = LOAD8(LOAD32(stack + 80) + 104);
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return componentByte;
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r9 after the call
	ctx.r9.u64 = r9Out;
	return 1;
}
PROMOTED_ENTRY(6, sub_8222E7D0, 0x8222E7D0) { ctx.r3.u64 = n_sub_8222E7D0(ctx, base, ctx.r3.u64); }

// sub_8229E5F8  [216 bytes]
uint64_t n_sub_8229E5F8(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, uint64_t targetAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(11, 0x8229E5F8)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.r4.u64 = targetAddr; __imp__sub_8229E5F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229E5F8);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationCharacterControlled* character = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	stack = PushStackFrame(base, stack, 144);

	// A list object embedded at +0x10 of this character; its begin and end pointers are at +0x14 and +0x18.
	uint32_t characterList = (uint32_t)physicsSimulationCharacterControlledAddr + 16;
	uint32_t initialListEnd = character->m_18;
	if (LOAD32(characterList + 4) > initialListEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	// Temporary entity handle on the stack, set to targetAddr and released at the end.
	uint32_t entityHandle = stack + 80;
	uint64_t entityHandleVtable = (int64_t)g_820F0000 + 5732;
	STORE32(stack + 104, characterList);
	STORE32(stack + 108, initialListEnd);
	STORE32(stack + 84, 0);
	STORE32(entityHandle, (uint32_t)entityHandleVtable);

	ctx.r1.u64 = stack;
	ctx.r8.u64 = entityHandleVtable;
	ctx.r9.u64 = 0;
	ctx.r10.s64 = g_820F0000;
	EntityHandle_SetTarget(ctx, base, entityHandle, targetAddr);

	uint32_t rangeEnd = LOAD32(characterList + 8);
	uint32_t rangeBegin = LOAD32(characterList + 4);
	if (rangeBegin > rangeEnd) {
		ppc_trap(ctx, base, 22);
	}
	STORE32(stack + 88, characterList);
	STORE32(stack + 92, rangeEnd);
	if (rangeBegin > rangeEnd) {
		ppc_trap(ctx, base, 22);
	}
	STORE32(stack + 100, rangeBegin);
	STORE32(stack + 96, characterList);

	// Iterators are (list, element pointer) pairs.
	uint64_t endIterator = LOAD64(stack + 88);
	uint64_t beginIterator = LOAD64(stack + 96);
	ctx.r7.u64 = rangeBegin;
	ctx.r9.u64 = rangeEnd;
	uint32_t foundIterAddr = n_sub_822C0268(ctx, base, stack + 112, beginIterator, endIterator, entityHandle);

	uint64_t initialEndIterator = LOAD64(stack + 104);
	uint64_t foundIterator = LOAD64(foundIterAddr);
	n_sub_8268A050(ctx, base, stack + 104, characterList, foundIterator, initialEndIterator);

	STORE32(entityHandle, (uint32_t)entityHandleVtable);
	ctx.r9.u64 = entityHandleVtable;
	ctx.r10.s64 = g_820F0000;
	uint64_t result = EntityHandle_Release(ctx, base, entityHandle);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_8229E5F8, 0x8229E5F8) { ctx.r3.u64 = n_sub_8229E5F8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_8229E6D0 = Lua_PhysicsCharacter_SetAsAbleToPushCharacters (Lua PhysicsCharacter.SetAsAbleToPushCharacters)  [128 bytes]
uint64_t n_sub_8229E6D0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, uint64_t canPushCharacters) {
	if (!UseLiftedCode(11, 0x8229E6D0)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.r4.u64 = canPushCharacters; __imp__sub_8229E6D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8229E6D0);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsSimulationCharacterControlled* character = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	uint8_t canPush = (uint8_t)canPushCharacters;
	uint64_t result = physicsSimulationCharacterControlledAddr;
	// r4 as left for the caller: the argument, or what the call below left in r4
	uint64_t r4Out = canPushCharacters;
	stack = PushStackFrame(base, stack, 112);
	if (canPush != 0) {
		if (character->m_AA == 0) {
			ctx.r1.u64 = stack;
			result = n_sub_8229E750(ctx, base, physicsSimulationCharacterControlledAddr, physicsSimulationCharacterControlledAddr + 240, physicsSimulationCharacterControlledAddr + 84);
			r4Out = ctx.r4.u64;
		}
	} else if (character->m_AA != 0) {
		ctx.r1.u64 = stack;
		result = n_sub_8229E5F8(ctx, base, physicsSimulationCharacterControlledAddr, physicsSimulationCharacterControlledAddr + 240);
		r4Out = ctx.r4.u64;
	}
	character->m_AA = canPush;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(11, sub_8229E6D0, 0x8229E6D0) { ctx.r3.u64 = n_sub_8229E6D0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPhysicsSimulationCharacterControlled_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8908_B_ = int32_t(0x820C8908);
	if (!UseLiftedCode(67, 0x82958CD0)) { ctx.r3.u64 = classNameString; __imp__sub_82958CD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82958CD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C8908_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(67, sub_82958CD0, 0x82958CD0) { ctx.r3.u64 = CECPhysicsSimulationCharacterControlled_GetClassName(ctx, base, ctx.r3.u64); }

// Stores the requested max height into the controlled-physics object (+56) of the object returned by virtual
// slot 92, when that object passes the physics-component check.
uint64_t n_sub_82959178(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, double maxHeight) {
	if (!UseLiftedCode(67, 0x82959178)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.f1.f64 = maxHeight; __imp__sub_82959178(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82959178);
	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t getObjectFn = LOAD32(uint32_t(physicsSimulationCharacterControlled->vtable) + 92);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	ctx.r10.u64 = getObjectFn;
	ctx.f1.f64 = maxHeight;
	REX_CALL_INDIRECT_FUNC(getObjectFn);
	uint64_t result = ctx.r3.u64;
	if ((uint32_t)result != 0) {
		uint32_t physicsComponentOut = stack + 80;
		result = Entity_GetPhysicsComponent(ctx, base, result, physicsComponentOut);
		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t controlledPhysics = LOAD32(LOAD32(physicsComponentOut) + 56);
			if (controlledPhysics != 0) {
				ctx.fpscr.disableFlushMode();
				STORE_F32(controlledPhysics + 64, float(maxHeight));
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82959178, 0x82959178) { ctx.r3.u64 = n_sub_82959178(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Applies the requested friction to the controlled-physics object (+56) of the object returned by virtual
// slot 92, when that object passes the physics-component check.
uint64_t n_sub_829591E0(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, double friction) {
	if (!UseLiftedCode(67, 0x829591E0)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.f1.f64 = friction; __imp__sub_829591E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829591E0);
	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t getObjectFn = LOAD32(uint32_t(physicsSimulationCharacterControlled->vtable) + 92);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = physicsSimulationCharacterControlledAddr;
	ctx.r10.u64 = getObjectFn;
	ctx.f1.f64 = friction;
	REX_CALL_INDIRECT_FUNC(getObjectFn);
	uint64_t result = ctx.r3.u64;
	if ((uint32_t)result != 0) {
		uint32_t physicsComponentOut = stack + 80;
		result = Entity_GetPhysicsComponent(ctx, base, result, physicsComponentOut);
		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t controlledPhysics = LOAD32(LOAD32(physicsComponentOut) + 56);
			result = controlledPhysics;
			if (controlledPhysics != 0) {
				ctx.fpscr.disableFlushMode();
				result = PhysicsControlled_SetFriction(ctx, base, controlledPhysics, friction);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_829591E0, 0x829591E0) { ctx.r3.u64 = n_sub_829591E0(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// Reads the character height and 2D radius from the game data (defaults 1.8 and 0.4), builds a C_82006BC8
// object from them, gives it a body component and keeps it at +32 before the remaining setup.
uint64_t n_sub_82959408(CpuState& ctx, uint8_t* base, uint64_t physicsSimulationCharacterControlledAddr, uint64_t gameDbDefinition, uint64_t arg3, double floatArg1) {
	constexpr int32_t g_82006818 = int32_t(0x82006818);
	constexpr int32_t g_820B0000 = int32_t(0x820B0000);  // base for 0x820A81F4 below, not a string pointer
	constexpr int32_t str_TXT_820CA624_B_ = int32_t(0x820CA624);
	constexpr int32_t str_TXT_820EC7D0_B_ = int32_t(0x820EC7D0);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(67, 0x82959408)) { ctx.r3.u64 = physicsSimulationCharacterControlledAddr; ctx.r4.u64 = gameDbDefinition; ctx.r5.u64 = arg3; ctx.f1.f64 = floatArg1; __imp__sub_82959408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82959408);

	CECPhysicsSimulationCharacterControlled* physicsSimulationCharacterControlled = GameObject<CECPhysicsSimulationCharacterControlled>(base, physicsSimulationCharacterControlledAddr);

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	// height (stack + 84) and 2D radius (stack + 80) start from defaults and are replaced when the game data has them
	ctx.fpscr.disableFlushMode();
	float defaultRadius = LOAD_F32(0x8209DE38u);
	STORE_F32(stack + 84, LOAD_F32(0x821001ECu));
	STORE_F32(stack + 80, defaultRadius);

	ctx.r1.u64 = stack;
	GameDB_ReadFloatField(ctx, base, gameDbDefinition, str_TXT_820EC7D0_B_, stack + 84);
	uint64_t radiusFieldName = (int64_t)g_820F0000 - 14368;  // 0x820EC7E0
	// state the callee may pass on
	ctx.r8.s64 = g_820F0000;
	GameDB_ReadFloatField(ctx, base, gameDbDefinition, radiusFieldName, stack + 80);

	// state the callee may pass on
	ctx.f1.f64 = floatArg1;
	ctx.f13.f64 = double(defaultRadius);
	uint64_t physicsObjectAlloc = operator_new(ctx, base, 132);
	uint64_t physicsObject = 0;
	if ((uint32_t)physicsObjectAlloc != 0) {
		ctx.fpscr.disableFlushMode();
		physicsObject = C_82006BC8_Construct(ctx, base, physicsObjectAlloc,
		                                     double(LOAD_F32(stack + 84)),  // character height
		                                     double(LOAD_F32(stack + 80)),  // character 2D radius
		                                     double(LOAD_F32(0x82099338u)));
	}

	// stack + 84 is reused: it receives the value read for the physics file field
	n_sub_8281BB38(ctx, base, stack + 84, gameDbDefinition, str_TXT_820CA624_B_);

	uint64_t bodyComponentAlloc = operator_new(ctx, base, 120);
	// r5..r8 handed to AddDefinition: what operator_new left in them, or the constants the original computed while building the component
	uint64_t handOverR5 = ctx.r5.u64;
	uint64_t handOverR6 = ctx.r6.u64;
	uint64_t handOverR7 = ctx.r7.u64;
	uint64_t handOverR8 = ctx.r8.u64;
	uint64_t bodyComponent = 0;
	if ((uint32_t)bodyComponentAlloc != 0) {
		uint32_t component = (uint32_t)bodyComponentAlloc;
		STORE32(component, uint32_t(g_82006818));  // vtable
		STORE32(component + 4, 0);
		STORE32(component + 8, 0);
		STORE32(component + 12, 0);
		STORE32(component + 16, 0);
		STORE32(component + 20, 0);
		STORE32(component + 24, 0);
		STORE32(component + 28, 0);
		STORE32(component + 32, 0);
		STORE8(component + 36, 1);
		STORE64(component + 40, 0);
		STORE32(component + 48, LOAD32(stack + 84));
		STORE32(component + 56, 0);
		STORE32(component + 60, 0);
		STORE32(component + 64, 0);
		STORE32(component + 68, 0);
		STORE32(component + 72, 0x820A81F4u);
		STORE32(component + 76, 0);
		STORE8(component + 80, 0);
		STORE8(component + 81, 0);
		STORE8(component + 82, 0);
		STORE64(component + 88, 0);
		STORE64(component + 96, 0);
		STORE32(component + 104, 1);
		STORE32(component + 108, 10);
		STORE32(component + 112, 11);
		STORE32(component + 116, 0xFFFFFFFFu);
		bodyComponent = bodyComponentAlloc;
		handOverR5 = (int64_t)g_820B0000 - 32268;  // 0x820A81F4, sign-extended
		handOverR6 = 10;
		handOverR7 = g_820B0000;
		handOverR8 = g_82006818;
	}
	// written even when the allocation failed (address 112), as the original does
	STORE32((uint32_t)bodyComponent + 112, 5u);

	ctx.r5.u64 = handOverR5;
	ctx.r6.u64 = handOverR6;
	ctx.r7.u64 = handOverR7;
	ctx.r8.u64 = handOverR8;
	CECPhysicsSimulationCharacterNavigator_AddDefinition(ctx, base, physicsObject, bodyComponent);

	SharedHandle_Assign_824F0958(ctx, base, physicsSimulationCharacterControlledAddr + 32, physicsObject);

	n_sub_824C4D28(ctx, base, physicsSimulationCharacterControlledAddr, gameDbDefinition, arg3, ctx.r6.u64, ctx.f1.f64);

	uint64_t sharedObjectAlloc = operator_new(ctx, base, 8);
	uint64_t sharedObject = 0;
	if ((uint32_t)sharedObjectAlloc != 0) {
		STORE32((uint32_t)sharedObjectAlloc + 4, 0);
		STORE32((uint32_t)sharedObjectAlloc, 0x820A81F4u);
		sharedObject = sharedObjectAlloc;
	}
	SharedPtr_ResetWithPointerE(ctx, base, physicsSimulationCharacterControlledAddr + 304, sharedObject);

	n_sub_821DA6D8(ctx, base, physicsObject, physicsSimulationCharacterControlled->m_130, 13);
	physicsSimulationCharacterControlled->m_B0 = 13u;

	uint64_t result = n_sub_829592C0(ctx, base, physicsSimulationCharacterControlledAddr);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82959408, 0x82959408) { ctx.r3.u64 = n_sub_82959408(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.f1.f64); }

uint64_t n_sub_829595E0(CpuState& ctx, uint8_t* base, uint64_t character) {
	if (!UseLiftedCode(67, 0x829595E0)) { ctx.r3.u64 = character; __imp__sub_829595E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829595E0);
	return n_sub_824C4F60(ctx, base, character);
}
PROMOTED_ENTRY(67, sub_829595E0, 0x829595E0) { ctx.r3.u64 = n_sub_829595E0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_829595E8(CpuState& ctx, uint8_t* base, uint64_t character) {
	if (!UseLiftedCode(67, 0x829595E8)) { ctx.r3.u64 = character; __imp__sub_829595E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829595E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_824C5290(ctx, base, character);
	uint64_t result = n_sub_829592C0(ctx, base, character);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_829595E8, 0x829595E8) { ctx.r3.u64 = n_sub_829595E8(ctx, base, ctx.r3.u64); }
