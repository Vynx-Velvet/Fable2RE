// CPhysicsRagdollEntity (vtable 0x82005480): methods of the class as readable C++.
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

uint64_t CPhysicsRagdollEntity_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(32, 0x825214A8)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_825214A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825214A8);
	uint32_t stack = ctx.r1.u64;
	uint64_t entity = arg1;
	uint32_t deleteFlags = arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	CPhysicsRagdollEntity_Destructor(ctx, base, entity);
	entity = arg1;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, entity);
		entity = arg1;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entity;
}
PROMOTED_ENTRY(32, sub_825214A8, 0x825214A8) { ctx.r3.u64 = CPhysicsRagdollEntity_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPhysicsRagdollEntity_Destructor(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollEntityAddr) {
	constexpr int32_t g_82005480 = int32_t(0x82005480);
	if (!UseLiftedCode(32, 0x825214F8)) { ctx.r3.u64 = physicsRagdollEntityAddr; __imp__sub_825214F8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825214F8);
	uint32_t stack = ctx.r1.u64;
	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);
	uint32_t entityAddr = (uint32_t)physicsRagdollEntityAddr;
	uint32_t vtable = g_82005480;
	uint64_t owner = ctx.r4.u64;          // value threaded through the release/free calls in r4
	uint64_t sharedHandle = physicsRagdollEntity->m_30;
	uint32_t handleAddr = entityAddr + 48;
	uint32_t zero = 0;

	stack = PushStackFrame(base, stack, 128);

	STORE32(entityAddr, vtable);
	if ((uint32_t)sharedHandle != 0) {
		ctx.r1.u64 = stack;
		SharedHandle_Release(ctx, base, handleAddr);
		owner = ctx.r4.u64;
		vtable = ctx.r9.u64;
		sharedHandle = ctx.r10.u64;
		STORE32(handleAddr, zero);
	}

	if (physicsRagdollEntity->m_pRagdoll != 0) {
		owner = physicsRagdollEntity->m_pWorld;
		if ((int32_t)owner != 0) {
			ctx.r1.u64 = stack;
			CPhysicsRagdollEntity_RemoveFromWorld(ctx, base, entityAddr);
			owner = ctx.r4.u64;
		}
		uint32_t pRagdoll = physicsRagdollEntity->m_pRagdoll;
		if (LOAD16(pRagdoll + 4) != 0) {
			int32_t refCount = int16_t((int64_t)(uint64_t)LOAD16(pRagdoll + 6) - 1);
			STORE16(pRagdoll + 6, (uint16_t)refCount);
			if (refCount == 0) {
				uint32_t ragdollVTable = LOAD32(LOAD32(pRagdoll));
				PPCRegister callTarget{};
				callTarget.u64 = (uint64_t)ragdollVTable;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = pRagdoll;
				ctx.r4.u64 = 1;
				ctx.r9.s64 = refCount;
				ctx.r10.u64 = ragdollVTable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				owner = ctx.r4.u64;
			}
		}
		physicsRagdollEntity->m_pRagdoll = 0;
	}

	uint32_t handleBlock = entityAddr + 56;
	uint32_t handleTarget = physicsRagdollEntity->m_3C;
	if (handleTarget != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, handleTarget);
		owner = ctx.r4.u64;
	}
	STORE32(handleBlock + 4, zero);
	STORE32(handleBlock + 8, zero);
	STORE32(handleBlock + 12, zero);

	ctx.r1.u64 = stack;
	SharedHandle_Release(ctx, base, handleAddr);

	uint32_t result = n_sub_823EE4D0(ctx, base, physicsRagdollEntityAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_825214F8, 0x825214F8) { ctx.r3.u64 = CPhysicsRagdollEntity_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsRagdollEntity_RemoveFromWorld(CpuState& ctx, uint8_t* base, uint32_t physicsRagdollEntityAddr) {
	if (!UseLiftedCode(32, 0x825217A8)) { ctx.r3.u64 = physicsRagdollEntityAddr; __imp__sub_825217A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825217A8);
	uint32_t stack = ctx.r1.u64;
	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint8_t wasInWorld = static_cast<uint8_t>(physicsRagdollEntity->m_118);
	physicsRagdollEntity->m_pWorld = 0;
	if (wasInWorld == 0) {
		physicsRagdollEntity->m_118 = 1;
	}
	if (physicsRagdollEntity->m_119 != 0) {
		ctx.r1.u64 = stack;
		n_sub_82520E38(ctx, base, physicsRagdollEntity->m_pRagdoll, 0);
		physicsRagdollEntity->m_119 = 0;
	}
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82E66A30(ctx, base, physicsRagdollEntity->m_pRagdoll);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_825217A8, 0x825217A8) { ctx.r3.u64 = CPhysicsRagdollEntity_RemoveFromWorld(ctx, base, ctx.r3.u32); }

void n_sub_82521818(CpuState& ctx, uint8_t* base, uint32_t entity) {
	if (!UseLiftedCode(32, 0x82521818)) { ctx.r3.u64 = entity; __imp__sub_82521818(ctx, base); return; }
	LiftedFrame frame(0x82521818);
	PPCVRegister value = ctx.v1;
	VSTORE((entity + 240u) & ~0xF, V8(value));
	return;
}
PROMOTED_ENTRY(32, sub_82521818, 0x82521818) { n_sub_82521818(ctx, base, ctx.r3.u32); }

void n_sub_82521828(CpuState& ctx, uint8_t* base, uint32_t physicsRagdollEntityAddr, uint64_t quaternionLow, uint64_t quaternionHigh) {
	if (!UseLiftedCode(32, 0x82521828)) { ctx.r3.u64 = physicsRagdollEntityAddr; ctx.r4.u64 = quaternionLow; ctx.r5.u64 = quaternionHigh; __imp__sub_82521828(ctx, base); return; }
	LiftedFrame frame(0x82521828);
	uint32_t stack = ctx.r1.u32;
	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);
	STORE64(stack + 32, quaternionLow);
	STORE64(stack + 40, quaternionHigh);
	physicsRagdollEntity->m_100 = quaternionLow;
	physicsRagdollEntity->m_108 = quaternionHigh;
	return;
}
PROMOTED_ENTRY(32, sub_82521828, 0x82521828) { n_sub_82521828(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82521850(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollEntityAddr) {
	if (!UseLiftedCode(32, 0x82521850)) { ctx.r3.u64 = physicsRagdollEntityAddr; __imp__sub_82521850(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82521850);
	uint32_t stack = ctx.r1.u64;
	uint32_t smallDataBase = ctx.r13.u64;
	PPCRegister callTarget{};
	PPCVRegister vecCopy{};
	PPCVRegister vecConstant{};
	PPCVRegister vecBroadcast{};
	PPCVRegister vecSource{};
	double f84{};
	double f120{};
	double f124{};
	double f128{};

	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);

	stack = PushStackFrame(base, stack, 272);

	uint32_t buf80 = stack + 80;
	uint32_t buf96 = stack + 96;
	uint32_t buf112 = stack + 112;
	uint32_t buf128 = stack + 128;
	uint32_t buf144 = stack + 144;
	uint32_t buf160 = stack + 160;
	uint32_t buf176 = stack + 176;
	uint32_t buf192 = stack + 192;

	uint32_t vfunc24 = LOAD32(LOAD32((uint32_t)physicsRagdollEntityAddr) + 24);

	callTarget.u64 = vfunc24;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = buf112;
	ctx.r4.u64 = physicsRagdollEntityAddr;
	ctx.r10.u64 = vfunc24;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t posePtr = ctx.r3.u32;
	uint64_t poseHi = LOAD64(posePtr + 8);
	// The call above may have changed the entity, so its vtable pointer is read again.
	uint32_t vfunc20 = LOAD32(LOAD32((uint32_t)physicsRagdollEntityAddr) + 20);

	// Copy the returned 16-byte value into [80..95] and broadcast it into [112..143].
	STORE64(buf80, LOAD64(posePtr));
	STORE64(buf80 + 8, poseHi);
	SET_V8(vecCopy, VLOAD(buf80 & ~0xF));
	VSTORE(buf112 & ~0xF, V8(vecCopy));
	ctx.fpscr.disableFlushMode();
	f124 = double(LOAD_F32(stack + 124));
	VSTORE(buf128 & ~0xF, V8(vecCopy));
	VSTORE(buf112 & ~0xF, V8(vecCopy));
	f128 = double(LOAD_F32(stack + 128));
	f120 = double(LOAD_F32(stack + 120));
	VSTORE(buf80 & ~0xF, V8(vecCopy));
	f84 = double(LOAD_F32(stack + 84));
	STORE_F32(stack + 92, float(f124));
	STORE_F32(stack + 84, float(f84));
	STORE_F32(stack + 88, float(f120));
	STORE_F32(stack + 80, float(f128));

	callTarget.u64 = vfunc20;
	ctx.r3.u64 = buf112;
	ctx.r4.u64 = physicsRagdollEntityAddr;
	ctx.r5.u64 = buf128;
	ctx.r6.u64 = buf80;
	ctx.r7.u64 = buf80;
	ctx.r8.u64 = vfunc20;
	ctx.r9.u64 = buf80;
	ctx.r10.u64 = buf112;
	ctx.f11.f64 = f120;
	ctx.f12.f64 = f124;
	ctx.f13.f64 = f128;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t resultPtr = ctx.r3.u32;
	SET_V8(vecCopy, VLOAD(resultPtr & ~0xF));
	uint32_t pRagdoll = physicsRagdollEntity->m_pRagdoll;
	VSTORE(buf144 & ~0xF, V8(vecCopy));

	uint32_t one = 1;
	ctx.fpscr.disableFlushMode();
	double constValue = double(LOAD_F32(0x820994C0u));
	STORE_F32(buf176, float(constValue));
	SET_V8(vecConstant, VLOAD(buf176 & ~0xF));
	SET_V8(vecBroadcast, simde_mm_shuffle_epi32(V8(vecConstant), 0xFF));
	SET_V8(vecSource, VLOAD(buf80 & ~0xF));
	VSTORE(buf160 & ~0xF, V8(vecSource));
	VSTORE(buf176 & ~0xF, V8(vecBroadcast));

	uint32_t limbTable = LOAD32(pRagdoll + 44);
	uint32_t limbValue = LOAD32(limbTable + 24);
	STORE32(buf96, LOAD32(limbTable + 20));
	STORE32(buf96 + 4, limbValue);
	STORE32(buf96 + 8, limbValue | 0x80000000u);
	uint32_t limbTableAgain = LOAD32(pRagdoll + 44);

	ctx.v11 = vecSource;
	ctx.v12 = vecBroadcast;
	ctx.v13 = vecConstant;
	n_sub_82D5D008(ctx, base, buf192, one, limbTableAgain, buf96);

	uint32_t poseData = n_sub_82D5DB78(ctx, base, buf192);
	uint32_t poseValue = LOAD32(poseData);
	uint32_t pRagdoll2 = physicsRagdollEntity->m_pRagdoll;
	n_sub_82E67700(ctx, base, pRagdoll2, poseValue, buf144);

	uint32_t ragdollData = physicsRagdollEntity->m_30;
	n_sub_82E66200(ctx, base, ragdollData);

	uint64_t result = n_sub_821A1580(ctx, base, buf192);

	uint32_t flags = LOAD32(stack + 104);
	if (int32_t(flags & 0x80000000) == 0) {
		uint32_t index = flags & 0x3FFFFFFF;
		uint32_t tableBase = LOAD32(smallDataBase);
		uint32_t offset = (flags << 1) & 0x7FFFFFFE;
		uint32_t value = LOAD32(stack + 96);
		uint32_t stride = 4;
		uint64_t combined = (uint64_t)index + (uint64_t)offset;
		uint32_t entryIndex = 22;
		uint32_t scaled = (uint32_t)combined << 4;
		uint32_t entry = LOAD32(stride + tableBase);
		result = n_sub_82D4ECA8(ctx, base, entry, value, scaled);
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82521850, 0x82521850) { ctx.r3.u64 = n_sub_82521850(ctx, base, ctx.r3.u64); }

uint64_t n_sub_825219C8(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollEntityAddr, uint64_t arg2) {
	if (!UseLiftedCode(32, 0x825219C8)) { ctx.r3.u64 = physicsRagdollEntityAddr; ctx.r4.u64 = arg2; __imp__sub_825219C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825219C8);
	uint32_t stack = ctx.r1.u64;
	uint32_t entityAddr = (uint32_t)physicsRagdollEntityAddr;
	uint32_t transformAddr = (uint32_t)arg2;
	const uint32_t translationOffset = 0xF0;

	stack = PushStackFrame(base, stack, 112);

	// Build the entity's quaternion (entity + 0x100) from the transform's rotation matrix.
	ctx.fpscr.disableFlushMode();
	ctx.r1.u64 = stack;
	ctx.f1.f64 = double(LOAD_F32(0x82099AE0u));
	double quatValue = Quat_FromMatrix3x3(ctx, base, entityAddr + 0x100, arg2);

	// Copy the transform's translation vector into the entity (+0xF0), 16-byte aligned.
	PPCVRegister translation;
	SET_V8(translation, VLOAD((transformAddr + 0x30u) & ~0xFu));
	VSTORE((entityAddr + translationOffset & ~0xFu), V8(translation));

	ctx.f1.f64 = quatValue;
	uint64_t result = n_sub_82521850(ctx, base, physicsRagdollEntityAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_825219C8, 0x825219C8) { ctx.r3.u64 = n_sub_825219C8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82521A28  [16 bytes]
void n_sub_82521A28(CpuState& ctx, uint8_t* base, uint32_t destination, uint32_t source) {
	if (!UseLiftedCode(32, 0x82521A28)) { ctx.r3.u64 = destination; ctx.r4.u64 = source; __imp__sub_82521A28(ctx, base); return; }
	LiftedFrame frame(0x82521A28);
	PPCVRegister vec{};
	SET_V8(vec, VLOAD((source + 240u) & ~0xF));
	VSTORE(destination & ~0xF, V8(vec));
	return;
}
PROMOTED_ENTRY(32, sub_82521A28, 0x82521A28) { n_sub_82521A28(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void n_sub_82521A38(CpuState& ctx, uint8_t* base, uint32_t destination, uint32_t source) {
	if (!UseLiftedCode(32, 0x82521A38)) { ctx.r3.u64 = destination; ctx.r4.u64 = source; __imp__sub_82521A38(ctx, base); return; }
	LiftedFrame frame(0x82521A38);
	uint64_t secondHalf = LOAD64(source + 264);
	STORE64(destination, LOAD64(source + 256));
	STORE64(destination + 8, secondHalf);
	return;
}
PROMOTED_ENTRY(32, sub_82521A38, 0x82521A38) { n_sub_82521A38(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CPhysicsRagdollEntity_SetMotionType(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollEntityAddr, uint64_t motionType) {
	if (!UseLiftedCode(32, 0x82521B38)) { ctx.r3.u64 = physicsRagdollEntityAddr; ctx.r4.u64 = motionType; __imp__sub_82521B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82521B38);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t physicsMotionMode;
	if ((int32_t)motionType == 1) {
		physicsMotionMode = 7;
	} else if ((int32_t)motionType == 2) {
		physicsMotionMode = 1;
	} else if ((int32_t)motionType == 3) {
		physicsMotionMode = 6;
	} else {
		physicsMotionMode = 0;
	}

	uint32_t bodyCount = LOAD32(LOAD32(uint32_t(physicsRagdollEntity->m_pRagdoll) + 44) + 16);
	if (bodyCount != 0) {
		uint32_t bodyOffset = 0;
		uint32_t remainingBodies = bodyCount;
		do {
			uint32_t ragdollAddr = physicsRagdollEntity->m_pRagdoll;
			uint32_t bodyIndex = LOAD32(LOAD32(ragdollAddr + 32) + bodyOffset);
			if ((int32_t)bodyIndex >= 0) {
				uint32_t bodyArray = LOAD32(ragdollAddr + 8);
				physicsRagdollEntityAddr = LOAD32((bodyIndex << 2) + bodyArray);
				if (physicsRagdollEntityAddr != 0) {
					ctx.r1.u64 = stack;
					ctx.xer.ca = flags.ca;
					physicsRagdollEntityAddr = n_sub_82D7B398(ctx, base, physicsRagdollEntityAddr, physicsMotionMode, 1, 0);
					motionType = ctx.r4.u64;
				}
			}
			flags.ca = remainingBodies != 0;
			remainingBodies = remainingBodies - 1;
			bodyOffset = bodyOffset + 4;
		} while (remainingBodies != 0);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = motionType;
	return physicsRagdollEntityAddr;
}
PROMOTED_ENTRY(32, sub_82521B38, 0x82521B38) { ctx.r3.u64 = CPhysicsRagdollEntity_SetMotionType(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82523398(CpuState& ctx, uint8_t* base, uint32_t physicsRagdollEntityAddr) {
	if (!UseLiftedCode(32, 0x82523398)) { ctx.r3.u64 = physicsRagdollEntityAddr; __imp__sub_82523398(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82523398);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 128);
	CPhysicsRagdollEntity* physicsRagdollEntity = GameObject<CPhysicsRagdollEntity>(base, physicsRagdollEntityAddr);

	uint64_t boneArg = ctx.r4.u64;
	uint32_t ragdoll = physicsRagdollEntity->m_pRagdoll;
	uint32_t boneCount = LOAD32(LOAD32(ragdoll + 44) + 16);

	for (uint32_t i = 0, indexTableOffset = 0; i != boneCount; ++i, indexTableOffset += 4) {
		int32_t boneIndex = (int32_t)LOAD32(LOAD32(ragdoll + 32) + indexTableOffset);
		if (boneIndex < 0) {
			boneArg = 0;
		} else {
			boneArg = LOAD32((uint32_t)boneIndex * 4 + LOAD32(ragdoll + 8));
		}

		uint32_t boneResultAddr = stack + 80;
		ctx.r1.u64 = stack;
		n_sub_82D7C158(ctx, base, boneResultAddr, boneArg);

		if (LOAD8(boneResultAddr) != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			ctx.r4.u64 = boneArg;
			return 1;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = boneArg;
	return 0;
}
PROMOTED_ENTRY(32, sub_82523398, 0x82523398) { ctx.r3.u64 = n_sub_82523398(ctx, base, ctx.r3.u32); }
