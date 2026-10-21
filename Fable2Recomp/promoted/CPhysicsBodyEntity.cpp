// CPhysicsBodyEntity (vtable 0x82005740): methods of the class as readable C++.
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

uint64_t CPhysicsBodyEntity_ComputeBoundingSphere(CpuState& ctx, uint8_t* base, uint64_t outBoundingSphere, uint64_t sourceEntity) {
	constexpr int32_t g_8209B948 = int32_t(0x8209B948);
	if (!UseLiftedCode(3, 0x821D0758)) { ctx.r3.u64 = outBoundingSphere; ctx.r4.u64 = sourceEntity; __imp__sub_821D0758(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D0758);
	uint32_t stack = ctx.r1.u64;
	uint64_t r4Value = sourceEntity;
	uint32_t boundsHost = 0;
	uint32_t boundsSource = 0;
	uint32_t boundsBuffer = 0;
	double scale = 0.0;
	double radius = 0.0;
	PPCVRegister cornerA{};
	PPCVRegister cornerB{};
	PPCVRegister delta{};
	PPCVRegister sum{};
	PPCVRegister scaleSlotBytes{};
	PPCVRegister scaleVec{};
	PPCVRegister lengthSquared{};
	PPCVRegister center{};
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 160);

	boundsHost = LOAD32((uint32_t)sourceEntity + 44);
	if (boundsHost != 0 && LOAD32(boundsHost + 8) != 0) {
		boundsSource = LOAD32((uint32_t)sourceEntity + 44);
		boundsBuffer = stack + 112;
		uint32_t getBounds = LOAD32(LOAD32(boundsSource) + 24);
		callTarget.u64 = getBounds;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = boundsSource;
		ctx.r4.u64 = boundsBuffer;
		ctx.r10.u64 = getBounds;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// The register that carried sourceEntity is reused to address the scale constant.
		r4Value = (uint64_t)(int64_t)g_8209B948;

		SET_V8(cornerA, VLOAD(uint32_t(boundsBuffer) & ~0xF));
		SET_V8(cornerB, VLOAD(uint32_t(boundsBuffer + 16) & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(delta, simde_mm_sub_ps(VF(cornerA), VF(cornerB)));
		SET_VF(sum, simde_mm_add_ps(VF(cornerA), VF(cornerB)));
		ctx.fpscr.disableFlushModeUnconditional();

		scale = double(LOAD_F32(uint32_t(g_8209B948) - 9748));
		STORE_F32(stack + 80, float(scale));
		uint32_t scaleSlot = stack + 80;
		SET_V8(scaleSlotBytes, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scaleSlot & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scaleSlot & 0xF) * 16])));
		SET_V8(scaleVec, simde_mm_shuffle_epi32(V8(scaleSlotBytes), 0xFF));

		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(lengthSquared, simde_mm_dp_ps(VF(delta), VF(delta), 0xEF));
		SET_VF(center, simde_mm_mul_ps(VF(sum), VF(scaleVec)));
		VSTORE(uint32_t(stack + 96) & ~0xF, V8(lengthSquared));
		ctx.fpscr.disableFlushModeUnconditional();
		radius = double(float(double(float(sqrt(double(LOAD_F32(stack + 96))))) * scale));
	} else {
		SET_V8(center, simde_mm_set1_epi32(int(0x0)));
		ctx.fpscr.disableFlushMode();
		radius = double(LOAD_F32(uint32_t(g_8209B948)));
	}

	ctx.r1.u64 = stack;
	ctx.v1 = center;
	CBoundingSphere_Ctor(ctx, base, outBoundingSphere, radius);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.f1.f64 = radius;
	return outBoundingSphere;
}
PROMOTED_ENTRY(3, sub_821D0758, 0x821D0758) { ctx.r3.u64 = CPhysicsBodyEntity_ComputeBoundingSphere(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_821D98B0  [48 bytes]
uint64_t CPhysicsBodyEntity_SetOwner(CpuState& ctx, uint8_t* base, uint32_t physicsBodyEntityAddr, uint64_t ownerEntity) {
	if (!UseLiftedCode(3, 0x821D98B0)) { ctx.r3.u64 = physicsBodyEntityAddr; ctx.r4.u64 = ownerEntity; __imp__sub_821D98B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D98B0);
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	uint32_t body = physicsBodyEntity->m_body;
	physicsBodyEntity->m_owner = (uint32_t)ownerEntity;
	if (body != 0) {
		STORE32(body + 44, (uint32_t)ownerEntity);
	}
	uint32_t world = physicsBodyEntity->m_world;
	if (world == 0) {
		ctx.r4.u64 = ownerEntity;
		return 0;
	}
	uint32_t body2 = physicsBodyEntity->m_body;
	ctx.r10.u64 = body;
	uint64_t result = hkpWorld_AddEntity(ctx, base, world, body2, 1);
	return result;
}
PROMOTED_ENTRY(3, sub_821D98B0, 0x821D98B0) { ctx.r3.u64 = CPhysicsBodyEntity_SetOwner(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsBodyEntity_SetSharedPosition(CpuState& ctx, uint8_t* base, uint64_t physicsBodyEntityAddr) {
	if (!UseLiftedCode(4, 0x821F8BC8)) { ctx.r3.u64 = physicsBodyEntityAddr; __imp__sub_821F8BC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821F8BC8);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);

	stack = PushStackFrame(base, stack, 128);

	// Spill the incoming v1 vector above the frame so its components can be read back.
	VSTORE((stack + 160u) & ~0xF, V8(ctx.v1));

	if (LOAD8(0x834BE6F1u) != 0) {
		uint32_t vfunc = LOAD32(uint32_t(physicsBodyEntity->vtable) + 32);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 80;
		ctx.r4.u64 = physicsBodyEntityAddr;
		ctx.r10.u64 = vfunc;
		REX_CALL_INDIRECT_FUNC(vfunc);
	}

	ctx.fpscr.disableFlushMode();

	// Build a 4-component vector at stack+80: incoming v1.xyz plus a constant w.
	STORE_F32(stack + 80, LOAD_F32(stack + 160));
	STORE_F32(stack + 84, LOAD_F32(stack + 164));
	STORE_F32(stack + 88, LOAD_F32(stack + 168));
	STORE_F32(stack + 92, LOAD_F32(0x820994B4u));

	uint32_t sharedHandle = physicsBodyEntity->m_sharedHandle;

	// Copy that vector into the slot handed to the callee.
	uint32_t vectorArg = stack + 96;
	PPCVRegister vec;
	SET_V8(vec, VLOAD(uint32_t(stack + 80) & ~0xF));
	VSTORE(uint32_t(stack + 96) & ~0xF, V8(vec));

	ctx.r1.u64 = stack;
	RigidBodyOwnerHandle_SetPosition(ctx, base, sharedHandle, vectorArg);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = vectorArg;
	return sharedHandle;
}
PROMOTED_ENTRY(4, sub_821F8BC8, 0x821F8BC8) { ctx.r3.u64 = CPhysicsBodyEntity_SetSharedPosition(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyEntity_GetBodyPosition(CpuState& ctx, uint8_t* base, uint64_t outPosition, uint32_t owner) {
	if (!UseLiftedCode(5, 0x82202248)) { ctx.r3.u64 = outPosition; ctx.r4.u64 = owner; __imp__sub_82202248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82202248);
	PPCRegister loadAddress{};
	uint32_t stack = ctx.r1.u32;
	PPCVRegister sourceVector{};
	PPCVRegister atOffset0{};
	PPCVRegister atOffset4{};
	PPCVRegister atOffset8{};
	PPCVRegister constantVector{};

	stack = PushStackFrame(base, stack, 128);

	uint32_t sourceObject = LOAD32(owner + 48);
	ctx.r1.u64 = stack;
	uint32_t vectorAddress = RigidBodyOwnerHandle_GetPosition(ctx, base, sourceObject);

	// stash the 16 bytes the callee points at, then re-read them at the three offsets used below
	SET_V8(sourceVector, VLOAD(vectorAddress & ~0xF));
	VSTORE((stack + 96) & ~0xF, V8(sourceVector));

	loadAddress.u32 = stack + 100;
	SET_V8(atOffset4, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(loadAddress.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(loadAddress.u32 & 0xF) * 16])));
	loadAddress.u32 = stack + 96;
	SET_V8(atOffset0, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(loadAddress.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(loadAddress.u32 & 0xF) * 16])));
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(0x820994B4u))));
	loadAddress.u32 = stack + 104;
	SET_V8(atOffset8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(loadAddress.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(loadAddress.u32 & 0xF) * 16])));
	loadAddress.u32 = stack + 80;
	SET_V8(constantVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(loadAddress.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(loadAddress.u32 & 0xF) * 16])));
	SET_VF(atOffset8, simde_mm_blend_ps(VF(atOffset8), simde_mm_permute_ps(VF(constantVector), 57), 4));
	SET_VF(atOffset0, simde_mm_blend_ps(VF(atOffset0), simde_mm_permute_ps(VF(atOffset4), 57), 4));
	SET_VF(atOffset0, simde_mm_blend_ps(VF(atOffset0), simde_mm_permute_ps(VF(atOffset8), 78), 3));
	VSTORE((uint32_t)outPosition & ~0xF, V8(atOffset0));

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return outPosition;
}
PROMOTED_ENTRY(5, sub_82202248, 0x82202248) { ctx.r3.u64 = CPhysicsBodyEntity_GetBodyPosition(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CPhysicsBodyEntity_GetRotation(CpuState& ctx, uint8_t* base, uint64_t entity, uint32_t source) {
	if (!UseLiftedCode(5, 0x822110C0)) { ctx.r3.u64 = entity; ctx.r4.u64 = source; __imp__sub_822110C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822110C0);
	PPCRegister scratch{};
	uint32_t sp = ctx.r1.u32;
	uint32_t outPtr{};
	uint64_t bone{};
	float storedValue{};
	PPCVRegister load80a{};
	PPCVRegister load84a{};
	PPCVRegister load84b{};
	PPCVRegister finalVec{};

	sp = PushStackFrame(base, sp, 128);
	outPtr = (int32_t)sp + 96;
	bone = (int64_t)(uint64_t)LOAD32(source + 44) + 160;

	ctx.r1.u64 = sp;
	hkRotation_GetQuaternion(ctx, base, outPtr, bone);
	ctx.fpscr.disableFlushMode();

	STORE_F32(sp + 80, LOAD_F32(sp + 108));
	STORE_F32(sp + 84, LOAD_F32(sp + 104));
	scratch.u32 = (int32_t)sp + 80;
	SET_V8(load80a, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = (int32_t)sp + 84;
	SET_V8(load84a, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));

	storedValue = LOAD_F32(sp + 96);
	STORE_F32(sp + 84, LOAD_F32(sp + 100));
	STORE_F32(sp + 80, storedValue);
	SET_VF(load84a, simde_mm_blend_ps(VF(load84a), simde_mm_permute_ps(VF(load80a), 57), 4));

	scratch.u32 = (int32_t)sp + 84;
	SET_V8(load84b, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = (int32_t)sp + 80;
	SET_V8(finalVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(finalVec, simde_mm_blend_ps(VF(finalVec), simde_mm_permute_ps(VF(load84b), 57), 4));
	SET_VF(finalVec, simde_mm_blend_ps(VF(finalVec), simde_mm_permute_ps(VF(load84a), 78), 3));
	VSTORE((uint32_t)entity & ~0xF, V8(finalVec));

	sp = PopStackFrame(sp, 128);
	ctx.r1.u64 = sp;
	ctx.r4.u64 = bone;
	return entity;
}
PROMOTED_ENTRY(5, sub_822110C0, 0x822110C0) { ctx.r3.u64 = CPhysicsBodyEntity_GetRotation(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// sub_82213BB8  [20 bytes]
void CPhysicsBodyEntity_SetPosition(CpuState& ctx, uint8_t* base, uint32_t physicsBodyEntity, uint32_t sourcePhysicsBodyEntity) {
	if (!UseLiftedCode(5, 0x82213BB8)) { ctx.r3.u64 = physicsBodyEntity; ctx.r4.u64 = sourcePhysicsBodyEntity; __imp__sub_82213BB8(ctx, base); return; }
	LiftedFrame frame(0x82213BB8);

	uint32_t sourceAddress = (LOAD32(sourcePhysicsBodyEntity + 44) + 208u) & ~0xFu;
	uint32_t destAddress = physicsBodyEntity & ~0xFu;

	PPCVRegister position{};
	SET_V8(position, VLOAD(sourceAddress));
	VSTORE(destAddress, V8(position));
	return;
}
PROMOTED_ENTRY(5, sub_82213BB8, 0x82213BB8) { CPhysicsBodyEntity_SetPosition(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_8223B550  [100 bytes]
uint64_t CPhysicsBodyEntity_SetBodyPosition(CpuState& ctx, uint8_t* base, uint64_t entity) {
	if (!UseLiftedCode(7, 0x8223B550)) { ctx.r3.u64 = entity; __imp__sub_8223B550(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8223B550);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Spill the incoming vector register v1 into the frame's scratch slot.
	VSTORE((stack + 160u) & ~0xF, V8(ctx.v1));

	// Repack it as a float4: v1.xyz followed by a constant w component.
	float vecX = LOAD_F32(stack + 160);
	float vecY = LOAD_F32(stack + 164);
	float vecZ = LOAD_F32(stack + 168);
	float vecW = LOAD_F32(0x820994B4u);

	STORE_F32(stack + 80, vecX);
	STORE_F32(stack + 84, vecY);
	STORE_F32(stack + 88, vecZ);
	STORE_F32(stack + 92, vecW);

	uint32_t vecPtr = stack + 96;
	PPCVRegister packedVec;
	SET_V8(packedVec, VLOAD((stack + 80u) & ~0xF));
	VSTORE(vecPtr & ~0xF, V8(packedVec));

	uint32_t linkedEntity = LOAD32((uint32_t)entity + 0x30);

	ctx.r1.u64 = stack;
	ctx.r9.u64 = vecPtr;
	ctx.f12.f64 = double(vecZ);
	uint64_t result = RigidBodyOwnerHandle_SetBodyPosition(ctx, base, linkedEntity, vecPtr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_8223B550, 0x8223B550) { ctx.r3.u64 = CPhysicsBodyEntity_SetBodyPosition(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyEntity_SetRotation(CpuState& ctx, uint8_t* base, uint32_t physicsBodyEntityAddr, uint64_t quaternionLow, uint64_t quaternionHigh) {
	if (!UseLiftedCode(9, 0x82265720)) { ctx.r3.u64 = physicsBodyEntityAddr; ctx.r4.u64 = quaternionLow; ctx.r5.u64 = quaternionHigh; __imp__sub_82265720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82265720);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	stack = PushStackFrame(base, stack, 256);

	// quaternionLow/quaternionHigh carry the new local rotation as four packed floats.
	STORE64(stack + 288, quaternionLow);
	STORE64(stack + 296, quaternionHigh);
	PPCVRegister quatPacked{};
	SET_V8(quatPacked, VLOAD((stack + 288) & ~0xF));
	VSTORE((stack + 128) & ~0xF, V8(quatPacked));

	ctx.fpscr.disableFlushMode();
	float quatW = LOAD_F32(stack + 140);
	uint32_t rotationAddr = (uint32_t)physicsBodyEntity->m_body + 160;

	VSTORE((stack + 96) & ~0xF, V8(quatPacked));
	VSTORE((stack + 112) & ~0xF, V8(quatPacked));
	VSTORE((stack + 128) & ~0xF, V8(quatPacked));
	float quatX = LOAD_F32(stack + 96);
	float quatY = LOAD_F32(stack + 116);
	float quatZ = LOAD_F32(stack + 136);
	STORE_F32(stack + 96, quatX);
	STORE_F32(stack + 104, quatZ);
	STORE_F32(stack + 108, quatW);
	STORE_F32(stack + 100, quatY);

	// The body's rotation matrix goes to stack+144..207, the quaternion to stack+112.
	PPCVRegister v11{};
	SET_V8(v11, VLOAD(rotationAddr & ~0xF));
	PPCVRegister row1{};
	SET_V8(row1, VLOAD((rotationAddr + 16u) & ~0xF));
	PPCVRegister row2{};
	SET_V8(row2, VLOAD((rotationAddr + 32u) & ~0xF));
	PPCVRegister row3{};
	SET_V8(row3, VLOAD((rotationAddr + 48u) & ~0xF));
	PPCVRegister v10{};
	SET_V8(v10, VLOAD((stack + 96) & ~0xF));

	uint32_t vec7Dst = stack + 144;
	VSTORE(vec7Dst & ~0xF, V8(v11));
	VSTORE((stack + 160) & ~0xF, V8(row1));
	VSTORE((stack + 176) & ~0xF, V8(row2));
	VSTORE((stack + 192) & ~0xF, V8(row3));
	VSTORE((stack + 112) & ~0xF, V8(v10));

	ctx.r1.u64 = stack;
	uint32_t quatStatus = hkQuaternion_IsNormalized(ctx, base, stack + 80, stack + 112);
	uint8_t needsRescale = LOAD8(quatStatus);
	if (needsRescale == 0) {
		vec7Dst = stack + 112;
		PPCVRegister quat{};
		SET_V8(quat, VLOAD((stack + 112) & ~0xF));
		ctx.fpscr.enableFlushMode();
		PPCVRegister lenSqVec{};
		SET_VF(lenSqVec, simde_mm_dp_ps(VF(quat), VF(quat), 0xFF));
		ctx.fpscr.disableFlushModeUnconditional();
		VSTORE((stack + 128) & ~0xF, V8(lenSqVec));
		float lenSq = LOAD_F32(stack + 128);
		double invLength = double(LOAD_F32(0x820994C0u)) / double(float(sqrt(double(lenSq))));
		STORE_F32(stack + 128, float(invLength));
		PPCVRegister scaleVec{};
		SET_V8(scaleVec, VLOAD((stack + 128) & ~0xF));
		SET_V8(v11, simde_mm_shuffle_epi32(V8(scaleVec), 0xFF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(v10, simde_mm_mul_ps(VF(quat), VF(v11)));
		VSTORE(vec7Dst & ~0xF, V8(v10));
	}

	hkRotation_SetFromQuaternion(ctx, base, stack + 144, stack + 112);
	uint32_t bodyAddr = physicsBodyEntity->m_body;
	ctx.r5.u64 = needsRescale;
	ctx.r7.u64 = vec7Dst;
	ctx.v10 = v10;
	ctx.v11 = v11;
	uint64_t result = hkpRigidBody_SetRotation(ctx, base, bodyAddr, stack + 144);
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(9, sub_82265720, 0x82265720) { ctx.r3.u64 = CPhysicsBodyEntity_SetRotation(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

// sub_823EE480  [80 bytes]
uint64_t CPhysicsBodyEntity_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(22, 0x823EE480)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_823EE480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EE480);
	uint32_t stack = ctx.r1.u64;
	uint64_t thisEntity{};
	uint32_t deleteFlags{};
	stack = PushStackFrame(base, stack, 112);
	deleteFlags = arg2;
	thisEntity = arg1;
	ctx.r1.u64 = stack;
	CPhysicsBodyEntity_Destructor(ctx, base, arg1);
	if (uint32_t(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, thisEntity);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return thisEntity;
}
PROMOTED_ENTRY(22, sub_823EE480, 0x823EE480) { ctx.r3.u64 = CPhysicsBodyEntity_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPhysicsBodyEntity_Destructor(CpuState& ctx, uint8_t* base, uint64_t physicsBodyEntityAddr) {
	constexpr int32_t g_82005740 = int32_t(0x82005740);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(22, 0x823EE528)) { ctx.r3.u64 = physicsBodyEntityAddr; __imp__sub_823EE528(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823EE528);
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	uint32_t stack = ctx.r1.u64;
	uint64_t r9Value = ctx.r9.u64;
	uint64_t r10Value = g_82005740;
	stack = PushStackFrame(base, stack, 96);

	uint32_t world = physicsBodyEntity->m_world;
	physicsBodyEntity->vtable = (uint32_t)r10Value;
	if ((int32_t)world != 0) {
		uint32_t body = physicsBodyEntity->m_body;
		ctx.r1.u64 = stack;
		hkpWorld_RemovePhantom(ctx, base, world, body);
		r9Value = ctx.r9.u64;
		r10Value = ctx.r10.u64;
	}

	// release the shared body handle; when the last reference goes away the handle releases itself
	uint32_t sharedHandle = physicsBodyEntity->m_sharedHandle;
	if (LOAD16(sharedHandle + 4) != 0) {
		uint64_t remainingRefs = (uint64_t)LOAD16(sharedHandle + 6) - 1;
		STORE16(sharedHandle + 6, (uint16_t)remainingRefs);
		r9Value = (uint64_t)(int16_t)remainingRefs;
		r10Value = remainingRefs;
		if ((int32_t)r9Value == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(sharedHandle));
			PPCRegister callTarget;
			callTarget.u64 = releaseFunc;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = sharedHandle;
			ctx.r4.u64 = 1;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r9Value = ctx.r9.u64;
			r10Value = ctx.r10.u64;
		}
	}

	uint32_t body = physicsBodyEntity->m_body;
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Value;
	ctx.r10.u64 = r10Value;
	hkReferencedObject_RemoveReference(ctx, base, body);

	uint32_t entityHandleValue = (uint32_t)g_820F1664;
	physicsBodyEntity->m_74 = entityHandleValue;
	EntityHandle_Release(ctx, base, physicsBodyEntityAddr + 116);

	physicsBodyEntity->m_78 = 0u;
	SharedHandle_Release(ctx, base, physicsBodyEntityAddr + 52);

	uint32_t result = C_820F06D0_Destructor(ctx, base, physicsBodyEntityAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823EE528, 0x823EE528) { ctx.r3.u64 = CPhysicsBodyEntity_Destructor(ctx, base, ctx.r3.u64); }

// sub_823EE5E0  [100 bytes]
uint64_t CPhysicsBodyEntity_SetRigidBodyOwner(CpuState& ctx, uint8_t* base, uint64_t physicsBodyEntityAddr, uint64_t rigidBodyOwner) {
	if (!UseLiftedCode(22, 0x823EE5E0)) { ctx.r3.u64 = physicsBodyEntityAddr; ctx.r4.u64 = rigidBodyOwner; __imp__sub_823EE5E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EE5E0);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t sharedHandle = physicsBodyEntity->m_sharedHandle;
	if (sharedHandle != 0) {
		ctx.r1.u64 = stack;
		uint32_t handleOwner = RigidBodyOwnerHandle_GetBody(ctx, base, sharedHandle);
		if (handleOwner != 0) {
			uint32_t sharedHandle2 = physicsBodyEntity->m_sharedHandle;
			uint32_t handleOwner2 = RigidBodyOwnerHandle_GetBody(ctx, base, sharedHandle2);
			STORE32(handleOwner2 + 12, (uint32_t)rigidBodyOwner);
		}
	}
	ctx.r1.u64 = stack;
	uint64_t result = RigidBodyOwnerHandle_Set(ctx, base, physicsBodyEntityAddr, rigidBodyOwner);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823EE5E0, 0x823EE5E0) { ctx.r3.u64 = CPhysicsBodyEntity_SetRigidBodyOwner(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhysicsBodyEntity_ClearRigidBodyOwner(CpuState& ctx, uint8_t* base, uint64_t physicsBodyEntityAddr) {
	if (!UseLiftedCode(22, 0x823EE648)) { ctx.r3.u64 = physicsBodyEntityAddr; __imp__sub_823EE648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EE648);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	stack = PushStackFrame(base, stack, 96);

	if (physicsBodyEntity->m_sharedHandle != 0) {
		ctx.r1.u64 = stack;
		uint32_t sharedHandle = RigidBodyOwnerHandle_GetBody(ctx, base, physicsBodyEntity->m_sharedHandle);
		if (sharedHandle != 0) {
			uint32_t sharedHandleTarget = RigidBodyOwnerHandle_GetBody(ctx, base, physicsBodyEntity->m_sharedHandle);
			STORE32(sharedHandleTarget + 12, 0u);
		}
	}

	ctx.r1.u64 = stack;
	uint64_t result = RigidBodyOwnerHandle_Clear(ctx, base, physicsBodyEntityAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823EE648, 0x823EE648) { ctx.r3.u64 = CPhysicsBodyEntity_ClearRigidBodyOwner(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyEntity_AddToWorld(CpuState& ctx, uint8_t* base, uint32_t physicsBodyEntityAddr, uint64_t physicsWorld) {
	if (!UseLiftedCode(22, 0x823EE6A0)) { ctx.r3.u64 = physicsBodyEntityAddr; ctx.r4.u64 = physicsWorld; __imp__sub_823EE6A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EE6A0);
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	physicsBodyEntity->m_world = (uint32_t)physicsWorld;
	uint32_t body = physicsBodyEntity->m_body;
	return PhysicsWorld_AddBody(ctx, base, physicsWorld, body);
}
PROMOTED_ENTRY(22, sub_823EE6A0, 0x823EE6A0) { ctx.r3.u64 = CPhysicsBodyEntity_AddToWorld(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_823EE6B8  [24 bytes]
uint64_t CPhysicsBodyEntity_RemoveFromWorld(CpuState& ctx, uint8_t* base, uint32_t physicsBodyEntityAddr, uint64_t physicsWorld) {
	if (!UseLiftedCode(22, 0x823EE6B8)) { ctx.r3.u64 = physicsBodyEntityAddr; ctx.r4.u64 = physicsWorld; __imp__sub_823EE6B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EE6B8);
	CPhysicsBodyEntity* physicsBodyEntity = GameObject<CPhysicsBodyEntity>(base, physicsBodyEntityAddr);
	uint32_t body = physicsBodyEntity->m_body;
	physicsBodyEntity->m_world = 0u;
	return hkpWorld_RemovePhantom(ctx, base, physicsWorld, body);
}
PROMOTED_ENTRY(22, sub_823EE6B8, 0x823EE6B8) { ctx.r3.u64 = CPhysicsBodyEntity_RemoveFromWorld(ctx, base, ctx.r3.u32, ctx.r4.u64); }
