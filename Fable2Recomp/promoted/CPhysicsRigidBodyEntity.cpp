// CPhysicsRigidBodyEntity (vtable 0x82005BA0): methods of the class as readable C++.
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

uint64_t n_sub_82175EF8(CpuState& ctx, uint8_t* base, uint64_t rigidBodyEntity, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(0, 0x82175EF8)) { ctx.r3.u64 = rigidBodyEntity; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82175EF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82175EF8);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vec{};
	double fA0{}, fA2{}, fA3{};
	stack = PushStackFrame(base, stack, 144);
	STORE64(stack + 176, arg2);
	STORE64(stack + 184, arg3);
	uint32_t rigidBodyId = LOAD32((uint32_t)rigidBodyEntity + 44);
	SET_V8(vec, VLOAD((stack + 176) & ~0xF));
	VSTORE((stack + 112) & ~0xF, V8(vec));
	ctx.fpscr.disableFlushMode();
	fA0 = double(LOAD_F32(stack + 112));
	VSTORE((stack + 80) & ~0xF, V8(vec));
	VSTORE((stack + 96) & ~0xF, V8(vec));
	VSTORE((stack + 112) & ~0xF, V8(vec));
	STORE_F32(stack + 84, float(double(LOAD_F32(stack + 100))));
	fA3 = double(LOAD_F32(stack + 92));
	fA2 = double(LOAD_F32(stack + 120));
	STORE_F32(stack + 88, float(fA2));
	STORE_F32(stack + 92, float(fA3));
	STORE_F32(stack + 80, float(fA0));
	SET_V8(vec, VLOAD((stack + 80) & ~0xF));
	VSTORE((stack + 80) & ~0xF, V8(vec));
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82D7B818(ctx, base, rigidBodyId);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_82175EF8, 0x82175EF8) { ctx.r3.u64 = n_sub_82175EF8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_82198D60  [224 bytes]
uint64_t CPhysicsRigidBodyEntity_UpdateBoundingSphere(CpuState& ctx, uint8_t* base, uint64_t boundingSphere, uint32_t rigidBodyEntity) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(1, 0x82198D60)) { ctx.r3.u64 = boundingSphere; ctx.r4.u64 = rigidBodyEntity; __imp__sub_82198D60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82198D60);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	uint32_t shape{};
	uint32_t vtable{};
	uint32_t virtualFn{};
	double srcParam{};
	double halfScale{};
	double radius{};
	PPCVRegister vScratch{};
	PPCVRegister vOperand{};
	PPCVRegister vDiff{};
	PPCVRegister vSum{};
	PPCVRegister vSplat{};
	PPCVRegister vScale{};
	PPCVRegister vDot{};
	PPCVRegister vCenter{};
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 432);
	const uint64_t cinfo = uint64_t(stack) + 208;
	ctx.r1.u64 = stack;
	RigidBodyCinfo_Init(ctx, base, cinfo);

	const uint32_t rigidBody = LOAD32(rigidBodyEntity + 44);
	hkpRigidBody_GetRigidBodyCinfo(ctx, base, rigidBody, cinfo);

	const uint64_t rotationMatrix = uint64_t(stack) + 144;
	const uint64_t cinfoQuaternion = uint64_t(stack) + 240;
	SET_V8(vScratch, VLOAD((stack + 224) & ~0xF));
	VSTORE((stack + 192) & ~0xF, V8(vScratch));
	hkRotation_SetFromQuaternion(ctx, base, rotationMatrix, cinfoQuaternion);

	shape = LOAD32(stack + 212);
	const uint64_t extentInput = uint64_t(stack) + 112;
	const int64_t constantsBase = int64_t(g_820A0000) - 27852;
	const uint32_t singlePointParam = (uint32_t)constantsBase + 15372;
	vtable = LOAD32(shape);
	ctx.fpscr.disableFlushMode();
	srcParam = double(LOAD_F32(singlePointParam));
	virtualFn = LOAD32(vtable + 28);
	callTarget.u64 = (uint64_t)virtualFn;
	ctx.r3.u64 = shape;
	ctx.r4.u64 = rotationMatrix;
	ctx.r6.u64 = extentInput;
	ctx.r7.u64 = virtualFn;
	ctx.r8.u64 = vtable;
	ctx.r9.u64 = constantsBase;
	ctx.f1.f64 = srcParam;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	ctx.fpscr.disableFlushMode();
	halfScale = double(LOAD_F32((uint32_t)constantsBase));
	const uint64_t dotResult = uint64_t(stack) + 96;
	STORE_F32(stack + 80, float(halfScale));

	SET_V8(vScratch, VLOAD((uint32_t)extentInput & ~0xF));
	SET_V8(vOperand, VLOAD((stack + 128) & ~0xF));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(vDiff, simde_mm_sub_ps(VF(vScratch), VF(vOperand)));
	SET_VF(vSum, simde_mm_add_ps(VF(vScratch), VF(vOperand)));
	scratch.u32 = stack + 80;
	SET_V8(vSplat, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_V8(vScale, simde_mm_shuffle_epi32(V8(vSplat), 0xFF));
	SET_VF(vDot, simde_mm_dp_ps(VF(vDiff), VF(vDiff), 0xEF));
	SET_VF(vCenter, simde_mm_mul_ps(VF(vSum), VF(vScale)));
	VSTORE((uint32_t)dotResult & ~0xF, V8(vDot));

	ctx.fpscr.disableFlushModeUnconditional();
	radius = double(float(double(float(sqrt(double(LOAD_F32(stack + 96))))) * halfScale));
	ctx.v1 = vCenter;
	CBoundingSphere_Ctor(ctx, base, boundingSphere, radius);

	stack = PopStackFrame(stack, 432);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = dotResult;
	ctx.f1.f64 = radius;
	return boundingSphere;
}
PROMOTED_ENTRY(1, sub_82198D60, 0x82198D60) { ctx.r3.u64 = CPhysicsRigidBodyEntity_UpdateBoundingSphere(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_821C0818(CpuState& ctx, uint8_t* base, uint64_t rigidBodyEntity) {
	if (!UseLiftedCode(2, 0x821C0818)) { ctx.r3.u64 = rigidBodyEntity; __imp__sub_821C0818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C0818);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister savedVector = ctx.v1;
	stack = PushStackFrame(base, stack, 112);
	uint32_t rigidBody = LOAD32((uint32_t)rigidBodyEntity + 44);
	uint32_t saveArea = stack + 80;
	VSTORE(saveArea & ~0xF, V8(savedVector));
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82D7B7D0(ctx, base, rigidBody);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(2, sub_821C0818, 0x821C0818) { ctx.r3.u64 = n_sub_821C0818(ctx, base, ctx.r3.u64); }

// sub_8220BB00  [20 bytes]
void CPhysicsRigidBodyEntity_GetPosition(CpuState& ctx, uint8_t* base, uint32_t outPosition, uint32_t physicsRigidBodyEntity) {
	if (!UseLiftedCode(5, 0x8220BB00)) { ctx.r3.u64 = outPosition; ctx.r4.u64 = physicsRigidBodyEntity; __imp__sub_8220BB00(ctx, base); return; }
	LiftedFrame frame(0x8220BB00);

	// physicsRigidBodyEntity->m_2C points at a physics actor; its position vector sits 0x110 bytes in.
	const uint32_t sourceVector = (LOAD32(physicsRigidBodyEntity + 0x2C) + 0x110u) & ~0xFu;

	PPCVRegister position{};
	SET_V8(position, VLOAD(sourceVector));
	VSTORE(outPosition & ~0xFu, V8(position));
	return;
}
PROMOTED_ENTRY(5, sub_8220BB00, 0x8220BB00) { CPhysicsRigidBodyEntity_GetPosition(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82232B08  [56 bytes]
void CPhysicsRigidBodyEntity_GetPosition_82232B08(CpuState& ctx, uint8_t* base, uint32_t outPosition, uint32_t physicsRigidBodyEntity) {
	if (!UseLiftedCode(7, 0x82232B08)) { ctx.r3.u64 = outPosition; ctx.r4.u64 = physicsRigidBodyEntity; __imp__sub_82232B08(ctx, base); return; }
	LiftedFrame frame(0x82232B08);
	PPCRegister scratch{};
	uint32_t translation{};
	PPCVRegister lane4{};
	PPCVRegister lane8{};
	PPCVRegister lane12{};
	PPCVRegister position{};

	translation = LOAD32(physicsRigidBodyEntity + 44) + 336;

	// masked loads emulate the (possibly unaligned) AltiVec vector load at the translation address
	scratch.u32 = translation + 4u;
	SET_V8(lane4, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = translation;
	SET_V8(position, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = translation + 12u;
	SET_V8(lane12, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(position, simde_mm_blend_ps(VF(position), simde_mm_permute_ps(VF(lane4), 57), 4));
	scratch.u32 = translation + 8u;
	SET_V8(lane8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(lane8, simde_mm_blend_ps(VF(lane8), simde_mm_permute_ps(VF(lane12), 57), 4));
	SET_VF(position, simde_mm_blend_ps(VF(position), simde_mm_permute_ps(VF(lane8), 78), 3));
	VSTORE(outPosition & ~0xF, V8(position));
	return;
}
PROMOTED_ENTRY(7, sub_82232B08, 0x82232B08) { CPhysicsRigidBodyEntity_GetPosition_82232B08(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CPhysicsRigidBodyEntity_HasMotion(CpuState& ctx, uint8_t* base, uint32_t physicsRigidBodyEntityAddr) {
	if (!UseLiftedCode(9, 0x82265B58)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; __imp__sub_82265B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82265B58);
	uint32_t stack = ctx.r1.u32;
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t resultAddr = stack + 80;
	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
	ctx.r1.u64 = stack;
	RigidBody_GetMotionType(ctx, base, resultAddr, pRigidBody);
	uint8_t result = LOAD8(resultAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = pRigidBody;
	return result != 0;
}
PROMOTED_ENTRY(9, sub_82265B58, 0x82265B58) { ctx.r3.u64 = CPhysicsRigidBodyEntity_HasMotion(ctx, base, ctx.r3.u32); }

uint64_t CPhysicsRigidBodyEntity_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(43, 0x82687A50)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82687A50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687A50);
	uint32_t stack = ctx.r1.u64;
	uint32_t deleteFlags = arg2;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CPhysicsRigidBodyEntity_Destructor(ctx, base, arg1);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, arg1);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(43, sub_82687A50, 0x82687A50) { ctx.r3.u64 = CPhysicsRigidBodyEntity_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPhysicsRigidBodyEntity_Destructor(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntityAddr) {
	constexpr int32_t g_82005BA0 = int32_t(0x82005BA0);
	if (!UseLiftedCode(43, 0x82687AA0)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; __imp__sub_82687AA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82687AA0);
	uint32_t stack = ctx.r1.u64;
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t vtablePtr = g_82005BA0;
	uint64_t world = physicsRigidBodyEntity->m_pWorld;
	physicsRigidBodyEntity->vtable = (uint32_t)vtablePtr;

	if ((int32_t)world != 0) {
		uint64_t stackTemp = (uint64_t)stack + 80;
		uint32_t rigidBodyForWorldUpdate = physicsRigidBodyEntity->m_pRigidBody;
		ctx.r1.u64 = stack;
		ctx.r10.u64 = vtablePtr;
		PhysicsWorld_RemoveRigidBody(ctx, base, stackTemp, world, rigidBodyForWorldUpdate);
		world = ctx.r4.u64;
		vtablePtr = ctx.r10.u64;
	}

	uint32_t rigidBody = physicsRigidBodyEntity->m_pRigidBody;
	ctx.r1.u64 = stack;
	ctx.r10.u64 = vtablePtr;
	hkReferencedObject_RemoveReference(ctx, base, rigidBody);

	uint32_t targetHandle = physicsRigidBodyEntity->m_34;
	uint32_t handleSlot = (int64_t)physicsRigidBodyEntityAddr + 48;
	if (targetHandle != 0) {
		HandleTarget_Free(ctx, base, targetHandle);
	}
	STORE32(handleSlot + 4, 0);
	STORE32(handleSlot + 8, 0);
	STORE32(handleSlot + 12, 0);

	uint32_t result = C_820F06D0_Destructor(ctx, base, physicsRigidBodyEntityAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82687AA0, 0x82687AA0) { ctx.r3.u64 = CPhysicsRigidBodyEntity_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsRigidBodyEntity_AddToWorld(CpuState& ctx, uint8_t* base, uint32_t physicsRigidBodyEntityAddr, uint64_t physicsWorld) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82687B28)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; ctx.r4.u64 = physicsWorld; __imp__sub_82687B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687B28);
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);

	// Bit 5 of the leading-zero count tells whether the global flag byte is zero (clz 32) or not (< 32).
	uint32_t globalFlagByte = LOAD8((uint32_t)g_83320000 - 28570);
	physicsRigidBodyEntity->m_pWorld = (uint32_t)physicsWorld;
	uint32_t leadingZeros = globalFlagByte == 0 ? 32 : __builtin_clz(globalFlagByte);
	uint32_t flagIsZero = (leadingZeros >> 5) & 1;
	uint64_t addToWorldMode = (uint64_t)flagIsZero ^ 1;

	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;

	ctx.r7.u64 = flagIsZero;
	ctx.r8.u64 = leadingZeros;
	ctx.r9.u64 = globalFlagByte;
	return HavokWorld_AddRigidBody(ctx, base, physicsWorld, pRigidBody, addToWorldMode);
}
PROMOTED_ENTRY(43, sub_82687B28, 0x82687B28) { ctx.r3.u64 = CPhysicsRigidBodyEntity_AddToWorld(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsRigidBodyEntity_RemoveFromWorld(CpuState& ctx, uint8_t* base, uint32_t physicsRigidBodyEntityAddr, uint64_t arg2) {
	if (!UseLiftedCode(43, 0x82687B50)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; ctx.r4.u64 = arg2; __imp__sub_82687B50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687B50);
	uint32_t stack = ctx.r1.u64;
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);

	stack = PushStackFrame(base, stack, 96);
	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
	physicsRigidBodyEntity->m_pWorld = 0u;
	uint32_t scratchAddr = stack + 80;
	ctx.r1.u64 = stack;
	uint64_t result = PhysicsWorld_RemoveRigidBody(ctx, base, scratchAddr, arg2, pRigidBody);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82687B50, 0x82687B50) { ctx.r3.u64 = CPhysicsRigidBodyEntity_RemoveFromWorld(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsRigidBodyEntity_SetCollisionFilterInfo(CpuState& ctx, uint8_t* base, uint32_t physicsRigidBodyEntityAddr, uint64_t collisionFilterInfo) {
	if (!UseLiftedCode(43, 0x82687B80)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; ctx.r4.u64 = collisionFilterInfo; __imp__sub_82687B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687B80);
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	uint32_t filterInfo = (uint32_t)collisionFilterInfo;
	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;

	physicsRigidBodyEntity->m_collisionFilterInfo = filterInfo;
	if (pRigidBody != 0) {
		STORE32(pRigidBody + 44, filterInfo);
	}

	uint32_t pWorld = physicsRigidBodyEntity->m_pWorld;
	if (pWorld == 0) {
		ctx.r4.u64 = collisionFilterInfo;
		return 0;
	}

	ctx.r10.u64 = pRigidBody;
	return PhysicsWorld_UpdateRigidBodyCollisionFilter(ctx, base, pWorld, pRigidBody, 0, 1);
}
PROMOTED_ENTRY(43, sub_82687B80, 0x82687B80) { ctx.r3.u64 = CPhysicsRigidBodyEntity_SetCollisionFilterInfo(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsRigidBodyEntity_SetMotionType(CpuState& ctx, uint8_t* base, uint64_t rigidBodyEntity, uint32_t motionType) {
	if (!UseLiftedCode(43, 0x82687BB8)) { ctx.r3.u64 = rigidBodyEntity; ctx.r4.u64 = motionType; __imp__sub_82687BB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687BB8);

	// Translate the game's motion type into the Havok motion type.
	uint32_t havokMotionType;
	switch (motionType) {
	case 1:
		havokMotionType = 7;
		break;
	case 2:
		havokMotionType = 1;
		break;
	case 3:
		havokMotionType = 6;
		break;
	default:
		havokMotionType = 0;
		break;
	}

	uint32_t havokRigidBody = LOAD32((uint32_t)rigidBodyEntity + 44);
	uint32_t updateFlags = 1;
	uint32_t activateFlags = 0;
	return HavokRigidBody_SetMotionType(ctx, base, havokRigidBody, havokMotionType, updateFlags, activateFlags);
}
PROMOTED_ENTRY(43, sub_82687BB8, 0x82687BB8) { ctx.r3.u64 = CPhysicsRigidBodyEntity_SetMotionType(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// sub_82687BF8  [20 bytes]
uint64_t CPhysicsRigidBodyEntity_SetOwner(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntityAddr, uint64_t ownerEntity) {
	if (!UseLiftedCode(43, 0x82687BF8)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; ctx.r4.u64 = ownerEntity; __imp__sub_82687BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687BF8);
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
	if (pRigidBody != 0) {
		STORE32(pRigidBody + 12, (uint32_t)ownerEntity);
	}
	return RigidBodyOwnerHandle_Set(ctx, base, physicsRigidBodyEntityAddr, ownerEntity);
}
PROMOTED_ENTRY(43, sub_82687BF8, 0x82687BF8) { ctx.r3.u64 = CPhysicsRigidBodyEntity_SetOwner(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhysicsRigidBodyEntity_ClearOwner(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntityAddr) {
	if (!UseLiftedCode(43, 0x82687C10)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; __imp__sub_82687C10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687C10);
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
	if (pRigidBody != 0) {
		STORE32(pRigidBody + 12, 0u);
	}
	return RigidBodyOwnerHandle_Clear(ctx, base, physicsRigidBodyEntityAddr);
}
PROMOTED_ENTRY(43, sub_82687C10, 0x82687C10) { ctx.r3.u64 = CPhysicsRigidBodyEntity_ClearOwner(ctx, base, ctx.r3.u64); }

// sub_82687C28  [60 bytes]
uint64_t CPhysicsRigidBodyEntity_GetName(CpuState& ctx, uint8_t* base, uint64_t nameString, uint32_t rigidBodyEntity) {
	if (!UseLiftedCode(43, 0x82687C28)) { ctx.r3.u64 = nameString; ctx.r4.u64 = rigidBodyEntity; __imp__sub_82687C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687C28);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t rigidBody = LOAD32(rigidBodyEntity + 44);
	uint32_t nameCStr = LOAD32(rigidBody + 112);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, nameString, nameCStr, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return nameString;
}
PROMOTED_ENTRY(43, sub_82687C28, 0x82687C28) { ctx.r3.u64 = CPhysicsRigidBodyEntity_GetName(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CPhysicsRigidBodyEntity_AddLinkedObject(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntity, uint64_t linkedObjectId) {
	if (!UseLiftedCode(43, 0x82687C68)) { ctx.r3.u64 = physicsRigidBodyEntity; ctx.r4.u64 = linkedObjectId; __imp__sub_82687C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687C68);
	uint32_t linkedObject = LOAD32((uint32_t)physicsRigidBodyEntity + 44);
	return HavokRigidBody_AddLinkedObject(ctx, base, linkedObject, linkedObjectId);
}
PROMOTED_ENTRY(43, sub_82687C68, 0x82687C68) { ctx.r3.u64 = CPhysicsRigidBodyEntity_AddLinkedObject(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhysicsRigidBodyEntity_RemoveLinkedObject(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntity, uint32_t linkedObjectId) {
	if (!UseLiftedCode(43, 0x82687C70)) { ctx.r3.u64 = physicsRigidBodyEntity; ctx.r4.u64 = linkedObjectId; __imp__sub_82687C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687C70);

	uint32_t rig = LOAD32((uint32_t)physicsRigidBodyEntity + 0x2C);
	uint32_t entryCount = LOAD16(rig + 0x1F4);

	if ((int32_t)entryCount > 0) {
		uint32_t entries = LOAD32(rig + 0x1F0);
		for (uint32_t i = 0; (int32_t)i < (int32_t)entryCount; i++) {
			if (LOAD32(entries + i * 4) == linkedObjectId) {
				HavokRigidBody_RemoveLinkedObject(ctx, base, rig, linkedObjectId);
				break;
			}
		}
	}

	return rig;
}
PROMOTED_ENTRY(43, sub_82687C70, 0x82687C70) { ctx.r3.u64 = CPhysicsRigidBodyEntity_RemoveLinkedObject(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// sub_82687D30  [20 bytes]
void n_sub_82687D30(CpuState& ctx, uint8_t* base, uint32_t outVector, uint32_t physicsRigidBodyEntity) {
	if (!UseLiftedCode(43, 0x82687D30)) { ctx.r3.u64 = outVector; ctx.r4.u64 = physicsRigidBodyEntity; __imp__sub_82687D30(ctx, base); return; }
	LiftedFrame frame(0x82687D30);
	PPCVRegister value{};
	uint32_t source = (LOAD32(physicsRigidBodyEntity + 0x2C) + 416u) & ~0xFu;
	SET_V8(value, VLOAD(source));
	VSTORE(outVector & ~0xF, V8(value));
	return;
}
PROMOTED_ENTRY(43, sub_82687D30, 0x82687D30) { n_sub_82687D30(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82687D48(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntityAddr) {
	constexpr int32_t g_820014A0 = int32_t(0x820014A0);
	constexpr int32_t g_82024200 = int32_t(0x82024200);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83330000 = int32_t(0x83330000);
	if (!UseLiftedCode(43, 0x82687D48)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; __imp__sub_82687D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687D48);
	uint32_t stack = ctx.r1.u64;
	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	stack = PushStackFrame(base, stack, 112);

	PPCVRegister inputVec = ctx.v1;
	PPCVRegister allOnes;
	SET_V8(allOnes, simde_mm_set1_epi32(int(0xFFFFFFFF)));

	// Register values handed to the physics query / indirect call.
	uint32_t arg4Value = 224;
	uint64_t arg5Value = g_83330000;
	uint64_t arg6Value = (int64_t)(uint64_t)stack + 80;
	uint64_t arg7Value = g_820014A0;
	uint64_t arg8Value = g_820A0000;
	uint64_t arg9Value = g_82024200;

	PPCVRegister vecA, vecB, vecC;
	PPCVRegister diffVec, stack80Vec, broadcastLane, maskedDiff, geMask, orMask, eqMask;
	PPCCRRegister compare6{};

	SET_V8(vecA, VLOAD((uint32_t)arg9Value & ~0xF));
	ctx.fpscr.enableFlushMode();
	SET_VF(diffVec, simde_mm_sub_ps(VF(inputVec), VF(vecA)));
	ctx.fpscr.disableFlushModeUnconditional();
	SET_V8(vecB, VLOAD((uint32_t)arg7Value & ~0xF));
	STORE_F32(stack + 80, float(double(LOAD_F32((uint32_t)arg8Value - 27348))));
	SET_V8(stack80Vec, VLOAD((uint32_t)arg6Value & ~0xF));
	SET_V8(broadcastLane, simde_mm_shuffle_epi32(V8(stack80Vec), 0xFF));
	SET_V8(maskedDiff, simde_mm_and_si128(V8(diffVec), V8(vecB)));
	SET_V8(vecC, VLOAD((uint32_t((int64_t)arg5Value + 29520) + arg4Value) & ~0xF));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(geMask, simde_mm_cmpge_ps(VF(broadcastLane), VF(maskedDiff)));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 80) & ~0xF, V8(inputVec));
	SET_V8(orMask, simde_mm_or_si128(V8(geMask), V8(vecC)));
	SET_V8(eqMask, simde_mm_cmpeq_epi32(V8(orMask), V8(allOnes)));
	compare6.setFromMask(VF(eqMask), 0xF);

	uint32_t pRigidBody{};
	if (!compare6.lt) {
		pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
		ctx.r1.u64 = stack;
		ctx.r6.u64 = arg6Value;
		ctx.r7.u64 = arg7Value;
		ctx.r8.u64 = arg8Value;
		ctx.v6 = eqMask;
		ctx.v7 = orMask;
		ctx.v8 = geMask;
		ctx.v9 = maskedDiff;
		ctx.v10 = broadcastLane;
		ctx.v11 = stack80Vec;
		ctx.v12 = diffVec;
		ctx.v13 = allOnes;
		n_sub_82D7C3A8(ctx, base, pRigidBody);
		arg5Value = ctx.r5.u64;
		arg6Value = ctx.r6.u64;
		arg7Value = ctx.r7.u64;
		arg8Value = ctx.r8.u64;
		arg9Value = ctx.r9.u64;
		eqMask = ctx.v6;
		orMask = ctx.v7;
		geMask = ctx.v8;
		maskedDiff = ctx.v9;
		broadcastLane = ctx.v10;
		stack80Vec = ctx.v11;
		diffVec = ctx.v12;
		allOnes = ctx.v13;
	}

	uint32_t rigidBody = physicsRigidBodyEntity->m_pRigidBody;
	uint64_t stack80ForCall = (int64_t)(uint64_t)stack + 80;
	uint64_t subObjectAddr = (int64_t)(uint64_t)rigidBody + 208;
	uint32_t subObjectPtr = LOAD32(rigidBody + 208);
	uint32_t callFnPtr = LOAD32(subObjectPtr + 64);
	PPCRegister callTarget{};
	callTarget.u64 = callFnPtr;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = subObjectAddr;
	ctx.r4.u64 = stack80ForCall;
	ctx.r5.u64 = arg5Value;
	ctx.r6.u64 = arg6Value;
	ctx.r7.u64 = arg7Value;
	ctx.r8.u64 = arg8Value;
	ctx.r9.u64 = arg9Value;
	ctx.r10.u64 = callFnPtr;
	ctx.v6 = eqMask;
	ctx.v7 = orMask;
	ctx.v8 = geMask;
	ctx.v9 = maskedDiff;
	ctx.v10 = broadcastLane;
	ctx.v11 = stack80Vec;
	ctx.v12 = diffVec;
	ctx.v13 = allOnes;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t entityData = physicsRigidBodyEntity->m_18;
	uint64_t handle = physicsRigidBodyEntityAddr + 20;
	uint32_t refObj = 0;
	bool shouldSet = false;
	if (entityData != 0) {
		uint32_t innerPtr = LOAD32(entityData);
		if (innerPtr == 0) {
			handle = EntityHandle_Release(ctx, base, handle);
		} else {
			refObj = innerPtr;
			if ((LOAD8(refObj + 144) & 64) != 0) {
				shouldSet = true;
			}
		}
	}
	if (shouldSet) {
		STORE8(refObj + 144, uint8_t(LOAD8(refObj + 144) | 1));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return handle;
}
PROMOTED_ENTRY(43, sub_82687D48, 0x82687D48) { ctx.r3.u64 = n_sub_82687D48(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82687E60(CpuState& ctx, uint8_t* base, uint64_t physicsRigidBodyEntityAddr) {
	constexpr int32_t g_820014A0 = int32_t(0x820014A0);
	constexpr int32_t g_82024200 = int32_t(0x82024200);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83330000 = int32_t(0x83330000);
	if (!UseLiftedCode(43, 0x82687E60)) { ctx.r3.u64 = physicsRigidBodyEntityAddr; __imp__sub_82687E60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82687E60);
	uint32_t stack = ctx.r1.u64;

	// SIMD state that has to survive the first (conditional) call
	PPCVRegister inputVec = ctx.v1;
	PPCVRegister allOnes{};
	PPCVRegister tmp{};
	PPCVRegister subVec{};
	PPCVRegister memVec{};
	PPCVRegister broadcast{};
	PPCVRegister maskedSub{};
	PPCVRegister geMask{};
	PPCVRegister orMask{};
	PPCVRegister eqMask{};
	PPCCRRegister compare6{};
	PPCRegister callTarget{};

	CPhysicsRigidBodyEntity* physicsRigidBodyEntity = GameObject<CPhysicsRigidBodyEntity>(base, physicsRigidBodyEntityAddr);
	stack = PushStackFrame(base, stack, 112);

	// register arguments handed to, and updated by, the calls below
	uint32_t r4Value = 224;
	uint64_t r5Value = g_83330000;
	uint64_t r6Value = (int64_t)(uint64_t)stack + 80;
	uint64_t r7Value = g_820014A0;
	uint64_t r8Value = g_820A0000;
	uint64_t r9Value = g_82024200;

	SET_V8(allOnes, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	SET_V8(tmp, VLOAD((uint32_t)r9Value & ~0xF));
	ctx.fpscr.enableFlushMode();
	SET_VF(subVec, simde_mm_sub_ps(VF(inputVec), VF(tmp)));
	ctx.fpscr.disableFlushModeUnconditional();
	SET_V8(tmp, VLOAD((uint32_t)r7Value & ~0xF));
	STORE_F32(stack + 80, float(double(LOAD_F32((uint32_t)r8Value - 27348))));
	SET_V8(memVec, VLOAD((uint32_t)r6Value & ~0xF));
	SET_V8(broadcast, simde_mm_shuffle_epi32(V8(memVec), 0xFF));
	SET_V8(maskedSub, simde_mm_and_si128(V8(subVec), V8(tmp)));
	SET_V8(tmp, VLOAD((uint32_t((int64_t)r5Value + 29520) + r4Value) & ~0xF));
	ctx.fpscr.enableFlushModeUnconditional();
	SET_VF(geMask, simde_mm_cmpge_ps(VF(broadcast), VF(maskedSub)));
	VSTORE(uint32_t((int64_t)(uint64_t)stack + 80) & ~0xF, V8(inputVec));
	SET_V8(orMask, simde_mm_or_si128(V8(geMask), V8(tmp)));
	SET_V8(eqMask, simde_mm_cmpeq_epi32(V8(orMask), V8(allOnes)));
	compare6.setFromMask(VF(eqMask), 0xF);
	if (!compare6.lt) {
		uint32_t pRigidBody = physicsRigidBodyEntity->m_pRigidBody;
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.v6 = eqMask;
		ctx.v7 = orMask;
		ctx.v8 = geMask;
		ctx.v9 = maskedSub;
		ctx.v10 = broadcast;
		ctx.v11 = memVec;
		ctx.v12 = subVec;
		ctx.v13 = allOnes;
		n_sub_82D7C3A8(ctx, base, pRigidBody);
		r5Value = ctx.r5.u64;
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		r9Value = ctx.r9.u64;
		eqMask = ctx.v6;
		orMask = ctx.v7;
		geMask = ctx.v8;
		maskedSub = ctx.v9;
		broadcast = ctx.v10;
		memVec = ctx.v11;
		subVec = ctx.v12;
		allOnes = ctx.v13;
	}

	// virtual dispatch through the rigid body's interface at +0xD0 / +0x44
	uint32_t subObject = physicsRigidBodyEntity->m_pRigidBody;
	uint64_t scratchArg = (int64_t)(uint64_t)stack + 80;
	uint64_t interfacePtr = (int64_t)(uint64_t)subObject + 208;
	subObject = LOAD32(subObject + 208);
	uint32_t funcPtr = LOAD32(subObject + 68);
	callTarget.u64 = (uint64_t)funcPtr;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = interfacePtr;
	ctx.r4.u64 = scratchArg;
	ctx.r5.u64 = r5Value;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = r9Value;
	ctx.r10.u64 = funcPtr;
	ctx.v6 = eqMask;
	ctx.v7 = orMask;
	ctx.v8 = geMask;
	ctx.v9 = maskedSub;
	ctx.v10 = broadcast;
	ctx.v11 = memVec;
	ctx.v12 = subVec;
	ctx.v13 = allOnes;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);


	uint32_t handleOwnerPtr = physicsRigidBodyEntity->m_18;
	uint64_t result = physicsRigidBodyEntityAddr + 20;
	uint32_t flagObj = 0;
	bool shouldFlag = false;
	if (handleOwnerPtr != 0) {
		uint32_t innerPtr = LOAD32(handleOwnerPtr);
		if (innerPtr == 0) {
			result = EntityHandle_Release(ctx, base, result);
		} else {
			flagObj = innerPtr;
			shouldFlag = (LOAD8(flagObj + 144) & 64) != 0;
		}
	}
	if (shouldFlag) {
		STORE8(flagObj + 144, uint8_t(LOAD8(flagObj + 144) | 1));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82687E60, 0x82687E60) { ctx.r3.u64 = n_sub_82687E60(ctx, base, ctx.r3.u64); }
