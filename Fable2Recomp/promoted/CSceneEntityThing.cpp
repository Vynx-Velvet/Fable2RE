// CSceneEntityThing (vtable 0x82005F60): methods of the class as readable C++.
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

uint64_t CSceneEntityThing_ProcessHit(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr, uint64_t otherAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(6, 0x822192A8)) { ctx.r3.u64 = sceneEntityThingAddr; ctx.r4.u64 = otherAddr; __imp__sub_822192A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822192A8);
	constexpr uint32_t g_8332152A = 0x8332152A;
	constexpr uint32_t CObjectBase_vtable = 0x820F3A24;
	constexpr uint32_t floatOne_address = 0x820994C0;   // 1.0f
	const uint64_t globalPage = uint64_t(int64_t(g_83320000));
	uint32_t stack = ctx.r1.u64;
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);
	stack = PushStackFrame(base, stack, 192);

	const uint32_t other = uint32_t(otherAddr);
	const uint32_t otherMode = LOAD32(other + 1788);

	// The distance from this thing's point (+320) to the point at +80 of the object at other + 4, and the
	// projection of (the pair vector at +112 minus other's point at +1680) on other's axis at +1696
	// (three-element dot products).
	PPCVRegister thingPoint{};
	PPCVRegister otherPoint{};
	PPCVRegister linkedPoint{};
	PPCVRegister transformedPair{};
	PPCVRegister toLinked{};
	PPCVRegister fromOther{};
	PPCVRegister otherAxis{};
	PPCVRegister toLinkedSquared{};
	PPCVRegister alongAxis{};
	SET_V8(thingPoint, VLOAD((uint32_t(sceneEntityThingAddr) + 320) & ~0xFu));
	SET_V8(otherPoint, VLOAD((other + 1680) & ~0xFu));
	SET_V8(linkedPoint, VLOAD((LOAD32(other + 4) + 80) & ~0xFu));
	SET_V8(transformedPair, VLOAD((uint32_t(sceneEntityThingAddr) + 112) & ~0xFu));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(toLinked, simde_mm_sub_ps(VF(linkedPoint), VF(thingPoint)));
	SET_VF(fromOther, simde_mm_sub_ps(VF(transformedPair), VF(otherPoint)));
	SET_V8(otherAxis, VLOAD((other + 1696) & ~0xFu));
	SET_VF(toLinkedSquared, simde_mm_dp_ps(VF(toLinked), VF(toLinked), 0xEF));
	SET_VF(alongAxis, simde_mm_dp_ps(VF(fromOther), VF(otherAxis), 0xEF));
	VSTORE((stack + 80) & ~0xFu, V8(toLinkedSquared));
	ctx.fpscr.disableFlushModeUnconditional();
	const double distance = double(float(sqrt(double(LOAD_F32(stack + 80)))));
	VSTORE((stack + 80) & ~0xFu, V8(alongAxis));

	// The original code keeps these vectors in v6-v12 across its calls: handed to a call, taken back after it.
	auto handOverVectors = [&]() {
		ctx.v6 = alongAxis;
		ctx.v7 = toLinkedSquared;
		ctx.v8 = otherAxis;
		ctx.v9 = fromOther;
		ctx.v10 = transformedPair;
		ctx.v11 = toLinked;
		ctx.v12 = otherPoint;
	};
	auto takeBackVectors = [&]() {
		alongAxis = ctx.v6;
		toLinkedSquared = ctx.v7;
		otherAxis = ctx.v8;
		fromOther = ctx.v9;
		transformedPair = ctx.v10;
		toLinked = ctx.v11;
		otherPoint = ctx.v12;
	};

	if (otherMode == 2) {
		const uint32_t resourceValue100 = LOAD32(uint32_t(sceneEntityThing->m_D4) + 100);
		STORE8(g_8332152A, 1);
		const uint64_t value100MinusOne = uint64_t(resourceValue100) - 1;
		const uint64_t leadingZeros = uint32_t(value100MinusOne) == 0 ? 32 : __builtin_clz(uint32_t(value100MinusOne));
		const bool value100IsOne = uint32_t(value100MinusOne) == 0;

		if (value100IsOne) {
			const uint64_t mapKey = sceneEntityThing->m_228;
			const uint32_t map = LOAD32(uint32_t(sceneEntityThing->m_14) + 3408);
			ctx.r1.u64 = stack;
			ctx.r6.u64 = 1;
			ctx.r7.u64 = leadingZeros;
			ctx.r8.u64 = value100MinusOne;
			ctx.r9.u64 = globalPage;
			ctx.v0 = thingPoint;
			handOverVectors();
			ctx.v13 = linkedPoint;
			Map_GetOrCreate(ctx, base, map, mapKey, sceneEntityThingAddr + 444);

			PPCVRegister reloadedThingPoint;
			SET_V8(reloadedThingPoint, VLOAD((uint32_t(sceneEntityThingAddr) + 320) & ~0xFu));
			ctx.v1 = reloadedThingPoint;
			n_sub_82223BD8(ctx, base, sceneEntityThingAddr);
		}

		// 1 when the counter at +7236 of the owner's object at +3676 is at most 1 past m_8C (0 without an owner).
		// The r7-r9 values are the ones the original code leaves there on each path.
		uint64_t counterWithinOne = 0;
		const uint32_t owner = sceneEntityThing->m_14;
		if (owner != 0) {
			const uint32_t counter = LOAD32(LOAD32(owner + 3676) + 7236);
			const uint64_t counterDelta = uint64_t(counter) - uint64_t(uint32_t(sceneEntityThing->m_8C));
			counterWithinOne = uint32_t(counterDelta) <= 1 ? 1 : 0;
			ctx.r7.u64 = 1 - counterDelta;
			ctx.r8.u64 = counterDelta;
			ctx.r9.u64 = counter;
		} else if (!value100IsOne) {
			ctx.r7.u64 = leadingZeros;
			ctx.r8.u64 = value100MinusOne;
			ctx.r9.u64 = globalPage;
		}
		if (!value100IsOne) {
			handOverVectors();
			ctx.v13 = linkedPoint;
		}
		ctx.r1.u64 = stack;
		n_sub_82B18B88(ctx, base, sceneEntityThingAddr + 448, other, counterWithinOne, sceneEntityThingAddr);
		n_sub_8222C7D8(ctx, base, sceneEntityThingAddr + 520, other, uint32_t(counterWithinOne));
		takeBackVectors();
	}

	// A temporary CObjectBase record at +96 of the frame: the vtable, 1 at +4 and 44 zero bytes from +8.
	const uint32_t record = stack + 96;
	STORE32(record + 4, 1);
	STORE32(record, CObjectBase_vtable);
	ctx.r1.u64 = stack;
	memset(ctx, base, record + 8, 0, 44);

	ctx.fpscr.disableFlushMode();
	const uint32_t typeId = sceneEntityThing->m_1BC;
	const double alongAxisValue = double(LOAD_F32(stack + 80));
	const double one = double(LOAD_F32(floatOne_address));
	handOverVectors();
	const uint64_t result = CSceneEntityThing_ApplyDamage(ctx, base, sceneEntityThingAddr, otherAddr, typeId, sceneEntityThingAddr + 448, record, distance, alongAxisValue, one);

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(6, sub_822192A8, 0x822192A8) { ctx.r3.u64 = CSceneEntityThing_ProcessHit(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CSceneEntityThing_UpdateChildBounds(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr) {
	if (!UseLiftedCode(7, 0x8223B608)) { ctx.r3.u64 = sceneEntityThingAddr; __imp__sub_8223B608(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223B608);
	uint32_t stack = ctx.r1.u64;
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);
	stack = PushStackFrame(base, stack, 160);

	// The resource's bounds copied into the frame: 32 bytes from +48 (the quad) and 16 bytes from +32 (the pair).
	const uint32_t boundsQuad = stack + 96;
	const uint32_t boundsPair = stack + 80;
	const uint32_t resource = sceneEntityThing->m_D4;
	const uint64_t quadWord0 = LOAD64(resource + 48);
	const uint64_t quadWord1 = LOAD64(resource + 56);
	const uint64_t quadWord2 = LOAD64(resource + 64);
	const uint64_t pairWord0 = LOAD64(resource + 32);
	const uint64_t quadWord3 = LOAD64(resource + 72);
	const uint64_t pairWord1 = LOAD64(resource + 40);
	STORE64(boundsQuad, quadWord0);
	STORE64(boundsQuad + 8, quadWord1);
	STORE64(boundsQuad + 16, quadWord2);
	STORE64(boundsPair, pairWord0);
	STORE64(boundsQuad + 24, quadWord3);
	STORE64(boundsPair + 8, pairWord1);

	ctx.r1.u64 = stack;
	CSceneEntityVisual_ComputeChildBounds(ctx, base, sceneEntityThingAddr, boundsQuad, boundsPair);
	CSceneEntityThing_TransformChildBounds(ctx, base, sceneEntityThingAddr, boundsQuad, boundsPair);
	const uint64_t result = n_sub_82B19B40(ctx, base, sceneEntityThingAddr + 520, uint32_t(sceneEntityThingAddr));

	// The transformed quad (+80..+111) goes into this thing's 32-byte entry of the slot owner's table at +196.
	const uint32_t slotOwner = sceneEntityThing->m_1E4;
	if (slotOwner != 0) {
		const uint32_t slotIndex = sceneEntityThing->m_1E8;
		const uint32_t slotTable = LOAD32(slotOwner + 196);
		const uint32_t slot = slotTable + (slotIndex << 5);
		STORE64(slot, uint64_t(sceneEntityThing->m_50));
		STORE64(slot + 8, uint64_t(sceneEntityThing->m_58));
		STORE64(slot + 16, uint64_t(sceneEntityThing->m_60));
		STORE64(slot + 24, uint64_t(sceneEntityThing->m_68));
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_8223B608, 0x8223B608) { ctx.r3.u64 = CSceneEntityThing_UpdateChildBounds(ctx, base, ctx.r3.u64); }

uint32_t CSceneEntityThing_TransformChildBounds(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr, uint32_t boundsQuad, uint32_t boundsPair) {
	constexpr int32_t g_82099200 = int32_t(0x82099200);
	if (!UseLiftedCode(7, 0x8223B6C8)) { ctx.r3.u64 = sceneEntityThingAddr; ctx.r4.u64 = boundsQuad; ctx.r5.u64 = boundsPair; __imp__sub_8223B6C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8223B6C8);
	constexpr uint32_t floatOne_address = 0x820994C0;   // 1.0f
	const uint32_t permuteControlAddr = uint32_t(g_82099200);
	uint32_t stack = ctx.r1.u64;
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);

	PPCVRegister savedVector = ctx.v127;
	VSTORE((stack - 64) & ~0xF, V8(savedVector));
	stack = PushStackFrame(base, stack, 240);
	ctx.r1.u64 = stack;

	const uint32_t entityMatrix = uint32_t(sceneEntityThingAddr) + 336;
	const uint32_t transposedMatrix = stack + 112;
	Matrix4x4_Transpose_8220B5C8(ctx, base, transposedMatrix, entityMatrix);

	PPCVRegister matrixRow0;
	SET_V8(matrixRow0, VLOAD(entityMatrix & ~0xF));
	ctx.fpscr.enableFlushMode();
	PPCVRegister row0LengthSquared;
	SET_VF(row0LengthSquared, simde_mm_dp_ps(VF(matrixRow0), VF(matrixRow0), 0xEF));
	const uint32_t thingFlags = sceneEntityThing->m_1C;

	// The transposed rows merged pairwise back into the four vectors whose dot products with the point give
	// the transformed x, y, z and w.
	PPCVRegister transposedRow0;
	SET_V8(transposedRow0, VLOAD(transposedMatrix & ~0xF));
	PPCVRegister transposedRow2;
	SET_V8(transposedRow2, VLOAD((stack + 144) & ~0xF));
	PPCVRegister transposedRow1;
	SET_V8(transposedRow1, VLOAD((stack + 128) & ~0xF));
	PPCVRegister transposedRow3;
	SET_V8(transposedRow3, VLOAD((stack + 160) & ~0xF));

	PPCVRegister rows02High;
	PPCVRegister rows02Low;
	PPCVRegister rows13High;
	PPCVRegister rows13Low;
	SET_V8(rows02High, simde_mm_unpackhi_epi32(V8(transposedRow2), V8(transposedRow0)));
	SET_V8(rows02Low, simde_mm_unpacklo_epi32(V8(transposedRow2), V8(transposedRow0)));
	SET_V8(rows13High, simde_mm_unpackhi_epi32(V8(transposedRow3), V8(transposedRow1)));
	ctx.fpscr.disableFlushModeUnconditional();
	const double one = double(LOAD_F32(floatOne_address));
	SET_V8(rows13Low, simde_mm_unpacklo_epi32(V8(transposedRow3), V8(transposedRow1)));
	PPCVRegister permuteControl;
	SET_V8(permuteControl, VLOAD(permuteControlAddr & ~0xF));

	const uint32_t floatSlot = stack + 80;
	STORE_F32(floatSlot, float(one));
	PPCVRegister oneVector;
	SET_V8(oneVector, simde_mm_shuffle_epi8(
		simde_mm_load_si128((simde__m128i*)RAW(floatSlot & ~0xF)),
		simde_mm_load_si128((simde__m128i*)&VectorMaskL[(floatSlot & 0xF) * 16])));

	PPCVRegister xWeights;
	PPCVRegister yWeights;
	PPCVRegister zWeights;
	PPCVRegister wWeights;
	SET_V8(xWeights, simde_mm_unpackhi_epi32(V8(rows13High), V8(rows02High)));
	SET_V8(yWeights, simde_mm_unpacklo_epi32(V8(rows13High), V8(rows02High)));
	SET_V8(zWeights, simde_mm_unpackhi_epi32(V8(rows13Low), V8(rows02Low)));
	SET_V8(wWeights, simde_mm_unpacklo_epi32(V8(rows13Low), V8(rows02Low)));

	PPCVRegister pairVector;
	SET_V8(pairVector, VLOAD(boundsPair & ~0xF));
	VSTORE((stack + 96) & ~0xF, V8(pairVector));
	PPCVRegister point;
	SET_V8(point, rex::ppc::simde_mm_perm_epi8_(V8(pairVector), V8(oneVector), V8(permuteControl)));

	const double pairW = double(LOAD_F32(stack + 108));
	ctx.fpscr.enableFlushModeUnconditional();
	PPCVRegister transformedX;
	PPCVRegister transformedY;
	PPCVRegister transformedZ;
	PPCVRegister transformedW;
	SET_VF(transformedX, simde_mm_dp_ps(VF(point), VF(xWeights), 0xFF));
	VSTORE((stack + 96) & ~0xF, V8(row0LengthSquared));
	SET_VF(transformedY, simde_mm_dp_ps(VF(point), VF(yWeights), 0xFF));
	SET_VF(transformedZ, simde_mm_dp_ps(VF(point), VF(zWeights), 0xFF));
	ctx.fpscr.disableFlushModeUnconditional();
	const double row0LengthSquaredScalar = double(LOAD_F32(stack + 96));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(transformedW, simde_mm_dp_ps(VF(point), VF(wWeights), 0xFF));
	ctx.fpscr.disableFlushModeUnconditional();

	const double row0Length = double(float(sqrt(row0LengthSquaredScalar)));
	PPCVRegister xzPairs;
	PPCVRegister ywPairs;
	SET_V8(xzPairs, simde_mm_unpackhi_epi32(V8(transformedZ), V8(transformedX)));
	SET_V8(ywPairs, simde_mm_unpackhi_epi32(V8(transformedW), V8(transformedY)));
	const double scaledW = double(float(row0Length * pairW));
	STORE_F32(floatSlot, float(scaledW));
	PPCVRegister transformedPoint;
	SET_V8(transformedPoint, simde_mm_unpackhi_epi32(V8(ywPairs), V8(xzPairs)));

	if ((thingFlags & 16) != 0 && scaledW < one) {
		ctx.f11.f64 = row0Length;
		ctx.f12.f64 = row0LengthSquaredScalar;
		ctx.f13.f64 = scaledW;
		ctx.v1 = xWeights;
		ctx.v2 = point;
		ctx.v3 = oneVector;
		ctx.v4 = rows13Low;
		ctx.v5 = rows13High;
		ctx.v6 = rows02Low;
		ctx.v7 = permuteControl;
		ctx.v8 = rows02High;
		ctx.v9 = row0LengthSquared;
		ctx.v10 = transposedRow3;
		ctx.v11 = transposedRow1;
		ctx.v12 = transposedRow2;
		ctx.v13 = transposedRow0;
		CThing_SetFlag(ctx, base, sceneEntityThingAddr, 16, 0);
		SET_V8(permuteControl, VLOAD(permuteControlAddr & ~0xF));
	}

	// The transformed point and the scaled w, combined through the permute control, go to +112.
	const uint32_t transformedQuad = uint32_t(sceneEntityThingAddr) + 80;
	PPCVRegister scaledWVector;
	SET_V8(scaledWVector, simde_mm_shuffle_epi8(
		simde_mm_load_si128((simde__m128i*)RAW(floatSlot & ~0xF)),
		simde_mm_load_si128((simde__m128i*)&VectorMaskL[(floatSlot & 0xF) * 16])));
	PPCVRegister transformedPair;
	SET_V8(transformedPair, rex::ppc::simde_mm_perm_epi8_(V8(transformedPoint), V8(scaledWVector), V8(permuteControl)));
	VSTORE((uint32_t(sceneEntityThingAddr) + 112) & ~0xF, V8(transformedPair));

	n_sub_82239900(ctx, base, transformedQuad, boundsQuad, transposedMatrix);
	sceneEntityThing->m_84 = 255;

	stack = PopStackFrame(stack, 240);
	SET_V8(savedVector, VLOAD((stack - 64) & ~0xF));
	ctx.r1.u64 = stack;
	ctx.v23 = ywPairs;
	ctx.v24 = xzPairs;
	ctx.v25 = transformedW;
	ctx.v26 = transformedZ;
	ctx.v27 = transformedY;
	ctx.v28 = transformedX;
	ctx.v29 = wWeights;
	ctx.v30 = zWeights;
	ctx.v31 = yWeights;
	return transformedQuad;
}
PROMOTED_ENTRY(7, sub_8223B6C8, 0x8223B6C8) { ctx.r3.u64 = CSceneEntityThing_TransformChildBounds(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32); }

uint64_t CSceneEntityThing_Construct(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr) {
	constexpr uint32_t CSceneEntityThing_vtable = 0x82005F60;
	if (!UseLiftedCode(76, 0x82A708E0)) { ctx.r3.u64 = sceneEntityThingAddr; __imp__sub_82A708E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A708E0);
	GameStackFrame stackFrame(ctx, base, 96);
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);

	CSceneEntityThing_ConstructBase(ctx, base, sceneEntityThingAddr, 2);

	sceneEntityThing->vtable = CSceneEntityThing_vtable;
	sceneEntityThing->m_208 = 0;
	sceneEntityThing->m_20C = 0;
	sceneEntityThing->m_214 = 0;
	sceneEntityThing->m_218 = 0;
	sceneEntityThing->m_21C = 0;
	sceneEntityThing->m_220 = 1;
	sceneEntityThing->m_224 = 0;
	sceneEntityThing->m_234 = 0;
	sceneEntityThing->m_238 = 0;
	sceneEntityThing->m_23C = 0;
	sceneEntityThing->m_240 = 0;

	// The linked object is unlinked as CSceneEntityThing_UnlinkLinkedObject does it.
	const uint32_t linkedObject = sceneEntityThing->m_1B0;
	sceneEntityThing->m_200 = 0;
	sceneEntityThing->m_204 = 0;
	sceneEntityThing->m_1B8 = 0;
	if (linkedObject != 0) {
		STORE32(linkedObject + 192, 0);
	}
	return sceneEntityThingAddr;
}
PROMOTED_ENTRY(76, sub_82A708E0, 0x82A708E0) { ctx.r3.u64 = CSceneEntityThing_Construct(ctx, base, ctx.r3.u64); }

uint64_t CSceneEntityThing_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr, uint64_t deleteFlags, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	if (!UseLiftedCode(76, 0x82A70978)) { ctx.r3.u64 = sceneEntityThingAddr; ctx.r4.u64 = deleteFlags; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_82A70978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A70978);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CThing_DerivedDestructor(ctx, base, sceneEntityThingAddr, forwardedArg1, forwardedArg2);
	if ((uint32_t(deleteFlags) & 1) != 0) {
		HandleTarget_Free(ctx, base, sceneEntityThingAddr);
	}
	return sceneEntityThingAddr;
}
PROMOTED_ENTRY(76, sub_82A70978, 0x82A70978) { ctx.r3.u64 = CSceneEntityThing_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }

uint32_t CSceneEntityThing_ConstructWithArg(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr, uint64_t initMode) {
	constexpr uint32_t CSceneEntityThing_vtable = 0x82005F60;
	if (!UseLiftedCode(76, 0x82A709C8)) { ctx.r3.u64 = sceneEntityThingAddr; ctx.r4.u64 = initMode; __imp__sub_82A709C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A709C8);
	GameStackFrame stackFrame(ctx, base, 96);
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);

	CSceneEntityThing_ConstructBase(ctx, base, sceneEntityThingAddr, initMode);

	sceneEntityThing->vtable = CSceneEntityThing_vtable;
	sceneEntityThing->m_208 = 0;
	sceneEntityThing->m_20C = 0;
	sceneEntityThing->m_214 = 0;
	sceneEntityThing->m_218 = 0;
	sceneEntityThing->m_21C = 0;
	sceneEntityThing->m_220 = 1;
	sceneEntityThing->m_224 = 0;
	sceneEntityThing->m_234 = 0;
	sceneEntityThing->m_238 = 0;
	sceneEntityThing->m_23C = 0;
	sceneEntityThing->m_240 = 0;

	// The linked object is unlinked as CSceneEntityThing_UnlinkLinkedObject does it.
	const uint32_t linkedObject = sceneEntityThing->m_1B0;
	sceneEntityThing->m_200 = 0;
	sceneEntityThing->m_204 = 0;
	sceneEntityThing->m_1B8 = 0;
	if (linkedObject != 0) {
		STORE32(linkedObject + 192, 0);
	}
	return uint32_t(sceneEntityThingAddr);
}
PROMOTED_ENTRY(76, sub_82A709C8, 0x82A709C8) { ctx.r3.u64 = CSceneEntityThing_ConstructWithArg(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void CSceneEntityThing_UnlinkLinkedObject(CpuState& ctx, uint8_t* base, uint32_t sceneEntityThingAddr) {
	if (!UseLiftedCode(76, 0x82A70AC8)) { ctx.r3.u64 = sceneEntityThingAddr; __imp__sub_82A70AC8(ctx, base); return; }
	LiftedFrame frame(0x82A70AC8);
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);

	uint32_t linkedObjectAddr = sceneEntityThing->m_1B0;

	sceneEntityThing->m_200 = 0;
	sceneEntityThing->m_204 = 0;
	sceneEntityThing->m_1B8 = 0;

	if (linkedObjectAddr != 0) {
		STORE32(linkedObjectAddr + 0xC0, 0);
	}
}
PROMOTED_ENTRY(76, sub_82A70AC8, 0x82A70AC8) { CSceneEntityThing_UnlinkLinkedObject(ctx, base, ctx.r3.u32); }

uint64_t CSceneEntityThing_UpdateVisual(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr, uint64_t visualDefinition, uint64_t forwardedArg, double lodDistance) {
	if (!UseLiftedCode(76, 0x82A70AF0)) { ctx.r3.u64 = sceneEntityThingAddr; ctx.r4.u64 = visualDefinition; ctx.r8.u64 = forwardedArg; ctx.f1.f64 = lodDistance; __imp__sub_82A70AF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A70AF0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t lockMsr = ctx.r13.u64;
	const uint8_t summaryOverflow = ctx.xer.so;
	PPCRegister callTarget{};
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);
	stack = PushStackFrame(base, stack, 144);

	// Adds delta to the reference count at countAddr atomically (reserved load and conditional store under the
	// global lock); returns the new count, and the MSR value saved for the lock in savedMsr.
	auto atomicAddCount = [&](uint32_t countAddr, int32_t delta, uint64_t& savedMsr) -> uint32_t {
		uint32_t newCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(countAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32) + delta;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(countAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		return newCount;
	};
	// The successful conditional store leaves cr0 = equal (with the summary-overflow bit) for the release call.
	auto setStoredCr0 = [&]() {
		ctx.cr0.lt = 0;
		ctx.cr0.gt = 0;
		ctx.cr0.eq = 1;
		ctx.cr0.so = summaryOverflow;
	};
	// Each 160-byte element from the vector's begin pointer at +532 gets the value at +544 at +148 and 1 at +152,
	// for the count at +44 of the object at +520; the last value and the last element + 128 stay in r6 and r7
	// for CSceneEntityThing_ApplyCreateParams.
	auto markElements = [&]() {
		uint32_t remaining = LOAD32(sceneEntityThing->m_208 + 44);
		uint64_t offset = 0;
		while (remaining != 0) {
			const uint32_t elementsBegin = sceneEntityThing->m_214;
			const uint32_t value = sceneEntityThing->m_220;
			const uint64_t element = offset + elementsBegin;
			offset += 160;
			remaining -= 1;
			STORE32(uint32_t(element) + 148, value);
			STORE8(uint32_t(element) + 152, 1);
			ctx.r6.u64 = value;
			ctx.r7.u64 = element + 128;
		}
	};

	// The linked object is unlinked as CSceneEntityThing_UnlinkLinkedObject does it.
	const uint32_t linkedObject = sceneEntityThing->m_1B0;
	sceneEntityThing->m_200 = 0;
	sceneEntityThing->m_204 = 0;
	sceneEntityThing->m_1B8 = 0;
	if (linkedObject != 0) {
		STORE32(linkedObject + 192, 0);
	}

	ctx.r1.u64 = stack;
	ctx.r4.u64 = visualDefinition;
	ctx.f1.f64 = lodDistance;
	n_sub_82A98B38(ctx, base, uint32_t(sceneEntityThingAddr), forwardedArg);
	CThing_RemoveFromMapC4Impl(ctx, base, sceneEntityThingAddr);
	CThing_RemoveFromMapB4(ctx, base, sceneEntityThingAddr);
	ctx.fpscr.disableFlushMode();
	CSceneEntityVisual_UpdateLOD(ctx, base, uint32_t(sceneEntityThingAddr), lodDistance);

	uint64_t modelIndex = uint64_t(-1);
	const uint32_t definitionVtable = LOAD32(uint32_t(visualDefinition));
	const uint32_t kindMethod = LOAD32(definitionVtable + 4);
	callTarget.u64 = kindMethod;
	ctx.r3.u64 = visualDefinition;
	ctx.r10.u64 = kindMethod;
	ctx.f1.f64 = lodDistance;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	const uint32_t definitionKind = ctx.r3.u32;

	if (definitionKind == 2 || definitionKind == 40) {
		// Take the resource of the definition (+112) into m_D4, counting the new reference and releasing the old one.
		const uint32_t resourceSlot = uint32_t(n_sub_82A50320(ctx, base, uint64_t(stack) + 80, visualDefinition + 112));
		const uint32_t oldResource = sceneEntityThing->m_D4;
		if (oldResource != LOAD32(resourceSlot)) {
			if (oldResource != 0) {
				const uint64_t countAddr = uint64_t(oldResource) + 4;
				uint64_t savedMsr = 0;
				const uint32_t count = atomicAddCount(uint32_t(countAddr), -1, savedMsr);
				if (count == 0) {
					const uint32_t vtable = LOAD32(oldResource);
					const uint32_t method = LOAD32(vtable + 4);
					callTarget.u64 = method;
					ctx.r3.u64 = oldResource;
					ctx.r9.u64 = countAddr;
					ctx.r10.u64 = method;
					setStoredCr0();
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
				}
				sceneEntityThing->m_D4 = 0;
			}
			const uint32_t newResource = LOAD32(resourceSlot);
			sceneEntityThing->m_D4 = newResource;
			if (newResource != 0) {
				uint64_t savedMsr = 0;
				atomicAddCount(newResource + 4, 1, savedMsr);
			}
		}

		// Release the reference held in the frame slot at +80.
		const uint32_t heldResource = LOAD32(stack + 80);
		if (heldResource != 0) {
			const uint64_t countAddr = uint64_t(heldResource) + 4;
			uint64_t savedMsr = 0;
			const uint32_t count = atomicAddCount(uint32_t(countAddr), -1, savedMsr);
			if (count == 0) {
				const uint32_t vtable = LOAD32(heldResource);
				const uint32_t method = LOAD32(vtable + 4);
				callTarget.u64 = method;
				ctx.r3.u64 = heldResource;
				ctx.r8.u64 = countAddr;
				ctx.r9.u64 = savedMsr;
				ctx.r10.u64 = method;
				setStoredCr0();
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
			}
			STORE32(stack + 80, 0);
		}

		sceneEntityThing->m_228 = LOAD64(uint32_t(visualDefinition) + 128);
		modelIndex = LOAD32(uint32_t(visualDefinition) + 52);
		sceneEntityThing->m_130 = LOAD32(uint32_t(visualDefinition) + 56);
		const uint32_t definitionValue100 = LOAD32(uint32_t(visualDefinition) + 100);
		const uint8_t hasElements = sceneEntityThing->m_20C;
		sceneEntityThing->m_220 = definitionValue100;
		ctx.r7.u64 = definitionValue100;
		if (hasElements != 0) {
			markElements();
		}
		ctx.r8.u64 = sceneEntityThingAddr + 520;
	} else if (definitionKind == 19) {
		n_sub_82B1A890(ctx, base, uint32_t(sceneEntityThingAddr) + 212, visualDefinition + 112);
		modelIndex = LOAD32(uint32_t(visualDefinition) + 52);
		sceneEntityThing->m_130 = LOAD32(uint32_t(visualDefinition) + 56);
		sceneEntityThing->m_220 = LOAD32(uint32_t(visualDefinition) + 100);
		if (sceneEntityThing->m_20C != 0) {
			markElements();
		}
		ctx.r8.u64 = sceneEntityThingAddr + 520;
	}

	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = lodDistance;
	CSceneEntityThing_ApplyCreateParams(ctx, base, sceneEntityThingAddr, visualDefinition);
	CSceneEntityThing_UpdateChildBounds(ctx, base, sceneEntityThingAddr);
	CSceneEntityVisual_SetModelIndex(ctx, base, sceneEntityThingAddr, modelIndex);
	if ((LOAD32(uint32_t(visualDefinition) + 4) & 256) != 0) {
		sceneEntityThing->m_110 = 1;
	}

	const uint32_t vtable = sceneEntityThing->vtable;
	const uint32_t method = LOAD32(vtable + 100);
	callTarget.u64 = method;
	ctx.r3.u64 = sceneEntityThingAddr;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(76, sub_82A70AF0, 0x82A70AF0) { ctx.r3.u64 = CSceneEntityThing_UpdateVisual(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64, ctx.f1.f64); }

uint64_t CSceneEntityThing_Cleanup(CpuState& ctx, uint8_t* base, uint64_t sceneEntityThingAddr) {
	if (!UseLiftedCode(76, 0x82A70E40)) { ctx.r3.u64 = sceneEntityThingAddr; __imp__sub_82A70E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A70E40);
	uint32_t stack = ctx.r1.u64;
	CSceneEntityThing* sceneEntityThing = GameObject<CSceneEntityThing>(base, sceneEntityThingAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t vtable = sceneEntityThing->vtable;
	const uint32_t method = LOAD32(vtable + 100);
	PPCRegister callTarget{};
	callTarget.u64 = method;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = sceneEntityThingAddr;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	CThing_RemoveFromMapB4(ctx, base, sceneEntityThingAddr);
	CThing_ClearChildren(ctx, base, sceneEntityThingAddr);

	sceneEntityThing->m_208 = 0;
	sceneEntityThing->m_20C = 0;

	// Erase the whole range [begin, end) of the vector at +528 (element pointers at +532 and +536): the two
	// iterators go as 8-byte values {0, element pointer} built in the frame; the begin slot is also the first argument.
	const uint32_t elementsBegin = sceneEntityThing->m_214;
	const uint32_t elementsEnd = sceneEntityThing->m_218;
	const uint32_t beginIterator = stack + 88;
	const uint32_t endIterator = stack + 80;
	STORE32(beginIterator, 0);
	STORE32(endIterator, 0);
	STORE32(endIterator + 4, elementsEnd);
	STORE32(beginIterator + 4, elementsBegin);
	n_sub_82B19D68(ctx, base, beginIterator, sceneEntityThingAddr + 528, LOAD64(beginIterator), LOAD64(endIterator));

	const uint64_t result = RefCounted_Release(ctx, base, sceneEntityThingAddr + 548);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A70E40, 0x82A70E40) { ctx.r3.u64 = CSceneEntityThing_Cleanup(ctx, base, ctx.r3.u64); }
