// CECBullet (vtable 0x820ECD70): methods of the class as readable C++.
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

uint64_t CECBullet_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameResult) {
	constexpr int32_t str_TXT_820C8D94_B_ = int32_t(0x820C8D94);
	if (!UseLiftedCode(67, 0x82961838)) { ctx.r3.u64 = classNameResult; __imp__sub_82961838(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82961838);

	// the class name literal, handed to the constructor as a 64-bit (sign-extended) value
	uint64_t classNameString = static_cast<uint64_t>(static_cast<int64_t>(str_TXT_820C8D94_B_));
	const int32_t stringLength = -1;

	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameResult, classNameString, stringLength);
	ctx.r1.u64 = PopStackFrame(stack, 96);

	return classNameResult;
}
PROMOTED_ENTRY(67, sub_82961838, 0x82961838) { ctx.r3.u64 = CECBullet_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECBullet_Destructor(CpuState& ctx, uint8_t* base, uint64_t bulletAddr, uint32_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(67, 0x82961898)) { ctx.r3.u64 = bulletAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82961898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82961898);
	uint32_t stack = ctx.r1.u64;
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 128);

	// m_74..m_80: a small linked structure hanging off the bullet
	uint32_t handleAddr = uint32_t(bulletAddr) + 116;
	uint64_t targetEntity = bullet->m_78;
	if ((uint32_t)targetEntity != 0) {
		uint32_t subHandle = LOAD32(handleAddr + 8);
		ctx.r1.u64 = stack;
		CECBullet_ReleaseTargetRange(ctx, base, targetEntity, subHandle);
		HandleTarget_Free(ctx, base, LOAD32(handleAddr + 4));
		targetEntity = ctx.r4.u64;
	}

	const uint32_t nullHandle = 0;
	const uint32_t nullSentinel = uint32_t(g_820F1664);

	STORE32(handleAddr + 4, nullHandle);
	STORE32(handleAddr + 8, nullHandle);
	STORE32(handleAddr + 12, nullHandle);

	bullet->m_24 = nullSentinel;
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, uint32_t(bulletAddr) + 36);
	bullet->m_28 = nullHandle;

	bullet->m_14 = nullSentinel;
	EntityHandle_Release(ctx, base, uint32_t(bulletAddr) + 20);
	bullet->m_18 = nullHandle;

	bullet->m_C = nullSentinel;
	EntityHandle_Release(ctx, base, uint32_t(bulletAddr) + 12);
	bullet->m_10 = nullHandle;

	bullet->vtable = 0x820A8D10u;

	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, bulletAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return bulletAddr;
}
PROMOTED_ENTRY(67, sub_82961898, 0x82961898) { ctx.r3.u64 = CECBullet_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CECBullet_SetSpeed(CpuState& ctx, uint8_t* base, uint32_t bulletAddr, uint64_t gameDbObject) {
	constexpr int32_t str_TXT_820BC8FC_B_ = int32_t(0x820BC8FC);
	if (!UseLiftedCode(67, 0x82961948)) { ctx.r3.u64 = bulletAddr; ctx.r4.u64 = gameDbObject; __imp__sub_82961948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82961948);
	uint32_t stack = ctx.r1.u64;
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint64_t floatByName = GameDB_GetFloatByName(ctx, base, gameDbObject, str_TXT_820BC8FC_B_);
	ctx.fpscr.disableFlushMode();
	bullet->m_40 = float(ctx.f1.f64);
	float speedFloor = LOAD_F32(0x83318D70u);
	if (speedFloor > LOAD_F32(0x820994B4u)) {
		bullet->m_40 = speedFloor;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return floatByName;
}
PROMOTED_ENTRY(67, sub_82961948, 0x82961948) { ctx.r3.u64 = CECBullet_SetSpeed(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECBullet_InitTrail(CpuState& ctx, uint8_t* base, uint64_t bulletAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_8349E230 = int32_t(0x8349E230);
	if (!UseLiftedCode(67, 0x829619A0)) { ctx.r3.u64 = bulletAddr; __imp__sub_829619A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829619A0);
	uint32_t stack = ctx.r1.u64;
	// Scratch registers the original just hands through to its callees.
	uint64_t r6 = ctx.r6.u64;
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	uint64_t r9 = 0;
	PPCRegister callTarget{};
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 224);

	uint32_t entryValue = 0;
	uint32_t hasEntry = 0;
	uint32_t owner = bullet->m_4;
	r9 = (LOAD32(owner + 44) >> 21) & 1;
	if (r9 != 0) {
		uint32_t slotIndex = LOAD32(owner + 140);
		if (slotIndex != 0) {
			uint32_t index = LOAD8(slotIndex + 85);
			owner = LOAD32(owner + 72);
			r9 = uint64_t(__builtin_rotateleft32(index, 3)) + uint64_t(owner);
			entryValue = LOAD32(uint32_t(r9) + 4);
			hasEntry = 1;
		} else {
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 96, 0);
			r6 = end;
			STORE32(stack + 100, begin);
			int32_t remaining = (int32_t)(end - begin) >> 3;
			if (remaining > 0) {
				// lower bound of key 85 over the sorted 8-byte {key, value} table
				do {
					uint32_t half = (uint32_t)(remaining >> 1);
					uint32_t offset = half << 3;
					r8 = offset;
					uint32_t mid = begin + offset;
					r7 = (int32_t)LOAD32(mid) < 85 ? 1 : 0;
					if (r7 != 0) {
						begin = mid + 8;
						remaining = remaining - (int32_t)half - 1;
					} else {
						remaining = (int32_t)half;
					}
					r9 = half;
				} while (remaining > 0);
				STORE32(stack + 100, begin);
			}
			if (begin != end) {
				if ((int32_t)LOAD32(begin) > 85) {
					entryValue = LOAD32(end + 4);
				} else {
					entryValue = LOAD32(LOAD32(stack + 100) + 4);
				}
			} else {
				entryValue = LOAD32(end + 4);
			}
			hasEntry = 1;
		}
	}

	if (hasEntry != 0) {
		uint32_t trailEntity = LOAD32(entryValue + 16);
		if (trailEntity != 0) {
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6;
			ctx.r7.u64 = r7;
			ctx.r8.u64 = r8;
			ctx.r9.u64 = r9;
			ShieldSwords_CleanupBlockTrail(ctx, base, trailEntity);
			r6 = ctx.r6.u64;
			r7 = ctx.r7.u64;
			r8 = ctx.r8.u64;
		}

		uint32_t trailOwner = LOAD32((uint32_t)bullet->m_4 + 124);
		uint32_t vtable = LOAD32(trailOwner);
		uint32_t target = LOAD32(vtable + 64);
		callTarget.u64 = target;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 112;
		ctx.r4.u64 = trailOwner;
		ctx.r6.u64 = r6;
		ctx.r7.u64 = r7;
		ctx.r8.u64 = r8;
		ctx.r9.u64 = target;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		trailEntity = LOAD32(entryValue + 16);
		if (trailEntity != 0) {
			SET_V8(ctx.v1, VLOAD((stack + 112) & ~0xFu));
			SET_V8(ctx.v2, VLOAD((uint32_t)g_8349E230 & ~0xFu));
			ctx.r9.u64 = static_cast<uint64_t>(static_cast<int64_t>(g_8349E230));
			ParticleEmitter_SetTransform(ctx, base, trailEntity);
		}

		CCharString_ConstructFromCStr(ctx, base, stack + 96,
		                              static_cast<uint64_t>(static_cast<int64_t>(g_82000C98)), -1);
		Matrix_ConstructIdentity(ctx, base, stack + 128);

		uint32_t attachOwner = bullet->m_4;
		STORE8(stack + 87, 0);
		ctx.fpscr.disableFlushMode();
		ParticleEmitter_AttachToEntityImpl(ctx, base, entryValue, attachOwner, stack + 96, 0, 1, 1, 1, stack + 128,
		                                   double(LOAD_F32(0x820994B4u)));
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 96);
		r6 = ctx.r6.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
	}

	uint32_t finalOwner = bullet->m_4;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = r6;
	ctx.r7.u64 = r7;
	ctx.r8.u64 = r8;
	ctx.r9.u64 = r9;
	uint64_t result = CECDoor_UpdateOpenStateForEntity(ctx, base, finalOwner, bulletAddr);
	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_829619A0, 0x829619A0) { ctx.r3.u64 = CECBullet_InitTrail(ctx, base, ctx.r3.u64); }

uint64_t CECBullet_Update(CpuState& ctx, uint8_t* base, uint64_t bulletAddr) {
	if (!UseLiftedCode(67, 0x82961B80)) { ctx.r3.u64 = bulletAddr; __imp__sub_82961B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82961B80);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 96);

	if (LOAD8((uint32_t)bulletAddr + 100) != 0) {
		bullet->m_64 = uint8_t(0);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return bulletAddr;
	}

	if (LOAD8(0x83496BB8u) != 0) {
		ctx.r1.u64 = stack;
		CECBullet_UpdateTrail(ctx, base, (uint32_t)bulletAddr);
	}

	ctx.r1.u64 = stack;
	result = CECBullet_UpdateLifetime(ctx, base, bulletAddr);
	if (uint32_t((uint32_t)result & 0xFF) == 0) {
		uint32_t entityId = bullet->m_4;
		uint64_t destroyResult = Entity_DestroyImpl(ctx, base, entityId);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return destroyResult;
	}

	if (LOAD8((uint32_t)bulletAddr + 101) == 0 && LOAD8((uint32_t)bulletAddr + 108) == 0) {
		result = n_sub_82961C38(ctx, base, bulletAddr);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82961B80, 0x82961B80) { ctx.r3.u64 = CECBullet_Update(ctx, base, ctx.r3.u64); }

uint32_t CECBullet_AddTarget(CpuState& ctx, uint8_t* base, uint64_t bulletAddr, uint64_t targetEntityId, uint64_t nameString) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(67, 0x82962170)) { ctx.r3.u64 = bulletAddr; ctx.r4.u64 = targetEntityId; ctx.r5.u64 = nameString; __imp__sub_82962170(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82962170);
	uint32_t stack = ctx.r1.u64;
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);

	// v1 ends up in the new element's trailing vector, so capture it before the calls below
	PPCVRegister incomingV1 = ctx.v1;
	VSTORE((stack + 0xFFFFFFB0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 208);
	ctx.r1.u64 = stack;

	const uint64_t targetId     = targetEntityId;
	const uint64_t sourceString = nameString;
	const uint32_t nullHandle   = uint32_t(g_820F1664);
	const uint32_t refCountAddr = uint32_t(g_83490000) + 28344;
	const uint32_t vectorObj    = uint32_t(bulletAddr) + 0x74;
	const uint64_t refCountPtr  = uint64_t(int64_t(g_83490000) + 28344);
	const uint64_t nullHandle64 = uint64_t(int64_t(g_820F1664));
	const int64_t  baseTemp     = int64_t(g_83490000);

	uint64_t curArg2 = targetEntityId;
	uint64_t curArg3 = nameString;

	uint32_t begin = bullet->m_78;
	uint32_t end   = bullet->m_7C;

	STORE32(stack + 88, 0);
	STORE32(stack + 92, begin);

	// look for an entry of the bullet's target list that already names this entity
	uint32_t elemPtr = LOAD32(stack + 92);
	if (begin != end) {
		do {
			uint32_t entryId = 0;
			uint32_t entityPtr = LOAD32(elemPtr + 4);
			if (entityPtr != 0) {
				uint32_t id = LOAD32(entityPtr);
				if (id != 0) {
					entryId = id;
				} else {
					// dead handle: drop it in place
					ctx.r1.u64 = stack;
					ctx.r4.u64 = curArg2;
					ctx.r5.u64 = curArg3;
					ctx.r10.u64 = 0;
					EntityHandle_Release(ctx, base, elemPtr);
					curArg2 = ctx.r4.u64;
					curArg3 = ctx.r5.u64;
				}
			}
			if (entryId == uint32_t(targetId)) break;
			elemPtr += 32;
		} while (elemPtr != end);
	}

	if (elemPtr == end) {
		ctx.r1.u64 = stack;
		uint64_t copiedName = CCharString_CopyConstruct(ctx, base, stack + 80, sourceString);

		STORE32(stack + 96, nullHandle);
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);

		uint64_t lockState = REX_CHECK_GLOBAL_LOCK();
		uint32_t newRefCount = LOAD32(refCountAddr) + 1;
		STORE32(refCountAddr, newRefCount);

		STORE32(stack + 88, nullHandle);
		STORE32(stack + 92, 0);
		ctx.r6.u64 = refCountPtr;
		ctx.r7.u64 = nullHandle64;
		ctx.r8.s64 = baseTemp;
		ctx.r9.u64 = lockState;
		ctx.r10.u64 = newRefCount;
		EntityHandle_SetTarget(ctx, base, stack + 88, targetId);

		EntityHandle_Assign(ctx, base, stack + 96, stack + 88);
		STORE32(stack + 88, nullHandle);
		EntityHandle_Release(ctx, base, stack + 88);

		CCharString_Assign(ctx, base, stack + 104, copiedName);
		VSTORE((stack + 112) & ~0xF, V8(incomingV1));
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, copiedName);

		uint32_t vecBegin = bullet->m_78;
		uint32_t capacity;
		if (vecBegin == 0) {
			capacity = 0;
		} else {
			capacity = uint32_t((int32_t)(LOAD32(vectorObj + 12) - vecBegin) >> 5);
		}
		uint32_t curEnd = LOAD32(vectorObj + 8);
		uint32_t used = uint32_t((int32_t)(curEnd - vecBegin) >> 5);
		if (used < capacity) {
			if (curEnd != 0) {
				EntityHandle_CopyConstruct(ctx, base, curEnd, stack + 96);
				CCharString_CopyConstruct(ctx, base, curEnd + 8, stack + 104);
				VSTORE((curEnd + 16) & ~0xF, VLOAD((stack + 112) & ~0xF));
			}
			STORE32(vectorObj + 8, curEnd + 32);
		} else {
			STORE32(stack + 92, curEnd);
			STORE32(stack + 88, 0);
			uint64_t pos = LOAD64(stack + 88);
			ctx.r5.u64 = 1;
			CECBullet_InsertTarget(ctx, base, vectorObj, pos, stack + 96);
		}

		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 104);
		STORE32(stack + 96, nullHandle);
		EntityHandle_Release(ctx, base, stack + 96);
	}

	ctx.r1.u64 = stack;
	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, sourceString);
	stack = PopStackFrame(stack, 208);
	SET_V8(ctx.v127, VLOAD((stack + 0xFFFFFFB0u) & ~0xF));
	ctx.r0.u64 = 0xFFFFFFB0u;
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82962170, 0x82962170) { ctx.r3.u64 = CECBullet_AddTarget(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t CECBullet_UpdateTrail(CpuState& ctx, uint8_t* base, uint32_t bulletAddr) {
	if (!UseLiftedCode(67, 0x82962358)) { ctx.r3.u64 = bulletAddr; __imp__sub_82962358(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82962358);
	uint32_t stack = ctx.r1.u64;
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 224);
	ctx.r1.u64 = stack;

	uint32_t bulletField = bullet->m_4;
	PPCVRegister copiedVector{};
	SET_V8(copiedVector, VLOAD((bulletAddr + 80) & ~0xFu));
	VSTORE((stack + 112) & ~0xFu, V8(copiedVector));

	uint32_t bulletSub = LOAD32(bulletField + 124);
	uint32_t bulletSubVtable = LOAD32(bulletSub);
	uint32_t bulletSubCall = LOAD32(bulletSubVtable + 64);
	PPCRegister callTarget{};
	callTarget.u64 = bulletSubCall;
	ctx.r3.u64 = stack + 96;
	ctx.r4.u64 = bulletSub;
	ctx.r7.u64 = bulletSubCall;
	ctx.r8.u64 = bulletSubVtable;
	ctx.r9.u64 = stack + 112;
	ctx.r10.u64 = 80;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	STORE8(stack + 82, 255);
	STORE8(stack + 81, 255);
	STORE8(stack + 80, 255);
	STORE8(stack + 83, 255);
	ctx.fpscr.disableFlushMode();
	double setupColor = double(LOAD_F32(0x83320000u + 5100));
	n_sub_824B5770(ctx, base, stack + 96, stack + 80, setupColor);

	STORE8(stack + 83, 255);
	STORE8(stack + 82, 128);
	STORE8(stack + 81, 128);
	STORE8(stack + 80, 128);
	n_sub_824B5648(ctx, base, stack + 112, stack + 96, stack + 80);

	uint32_t r4Value = bullet->m_7C;
	uint32_t result = bullet->m_78;
	uint32_t difference = r4Value - result;
	int32_t count = (int32_t)difference >> 5;

	bool finalLt = count < 0;
	bool finalGt = count > 0;
	bool finalEq = count == 0;
	bool finalCa = ((int32_t)difference < 0) && ((difference & 0x1F) != 0);

	if (count > 0) {
		uint32_t floatBase = 0x820A0000u - 27852u;
		ctx.fpscr.disableFlushMode();
		double f6 = double(LOAD_F32(floatBase));
		double f5 = double(LOAD_F32(floatBase + 8620));
		double f4 = double(LOAD_F32(floatBase + 384));

		uint32_t offset = 0;
		for (int32_t i = count; i != 0; --i) {
			uint32_t element = bullet->m_78 + offset;
			uint32_t elementPtr = LOAD32(element + 4);

			if (elementPtr != 0) {
				uint32_t entity = LOAD32(elementPtr);
				if (entity != 0) {
					STORE8(stack + 82, 255);
					STORE8(stack + 81, 0);
					STORE8(stack + 80, 0);
					STORE8(stack + 83, 255);

					uint32_t entitySub = LOAD32(entity + 124);
					uint32_t entitySubVtable = LOAD32(entitySub);
					uint32_t entitySubCall = LOAD32(entitySubVtable + 64);
					callTarget.u64 = entitySubCall;
					ctx.r3.u64 = stack + 128;
					ctx.r4.u64 = entitySub;
					ctx.r10.u64 = entitySubCall;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);

					ctx.fpscr.disableFlushMode();
					PPCVRegister effectVector{};
					SET_V8(effectVector, VLOAD((stack + 128) & ~0xFu));
					ctx.v1 = effectVector;

					result = n_sub_824B5D68(ctx, base, stack + 80);
					r4Value = ctx.r4.u32;
					offset += 32;
					continue;
				}

				EntityHandle_Release(ctx, base, element);
			}

			STORE8(stack + 86, 255);
			STORE8(stack + 85, 0);
			STORE8(stack + 84, 0);
			STORE8(stack + 87, 255);
			ctx.fpscr.disableFlushMode();
			result = n_sub_824B5770(ctx, base, element + 16, stack + 84, f6);
			r4Value = ctx.r4.u32;
			offset += 32;
		}

		finalLt = false;
		finalGt = false;
		finalEq = true;
		finalCa = true;
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.cr0.lt = finalLt;
	ctx.cr0.gt = finalGt;
	ctx.cr0.eq = finalEq;
	ctx.cr0.so = ctx.xer.so;
	ctx.xer.ca = finalCa;
	return result;
}
PROMOTED_ENTRY(67, sub_82962358, 0x82962358) { ctx.r3.u64 = CECBullet_UpdateTrail(ctx, base, ctx.r3.u32); }

uint32_t CECBullet_OnHit(CpuState& ctx, uint8_t* base, uint64_t bulletAddr, uint64_t impactType) {
	constexpr int32_t g_82099334 = int32_t(0x82099334);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(67, 0x82962A70)) { ctx.r3.u64 = bulletAddr; ctx.r4.u64 = impactType; __imp__sub_82962A70(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82962A70);
	PPCVRegister savedV127 = ctx.v127;
	uint32_t stack = ctx.r1.u64;
	PPCVRegister v1Reg = ctx.v1;

	uint64_t originalArg2 = impactType;
	uint32_t local5 = ctx.r6.u64;
	uint64_t local6 = ctx.r7.u64;
	uint32_t local27 = 0;
	uint64_t killValue = 0;
	bool shouldKill = false;
	uint32_t result = 0;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);

	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 144);
	uint32_t bulletComponent = bullet->m_4;
	VSTORE((stack + 176) & ~0xF, V8(v1Reg));

	local27 = (LOAD32(bulletComponent + 44) >> 21) & 1;
	if (local27 != 0) {
		uint32_t index = LOAD32(bulletComponent + 140);
		if (index != 0) {
			uint32_t index2 = LOAD8(index + 85);
			uint32_t table = LOAD32(bulletComponent + 72);
			index2 = __builtin_rotateleft32(index2, 3);
			killValue = (uint64_t)LOAD32((uint32_t)(index2 + table) + 4);
			shouldKill = true;
		} else {
			uint32_t begin = LOAD32(bulletComponent + 72);
			local5 = LOAD32(bulletComponent + 76);
			STORE32(stack + 80, 0u);
			local27 = local5 - begin;
			STORE32(stack + 84, begin);
			flags.ca = ((int32_t)local27 < 0) & ((local27 & 0x7) != 0);
			int32_t count = (int32_t)local27 >> 3;
			uint32_t ptr = begin;
			if (count > 0) {
				do {
					flags.ca = (count < 0) & ((count & 0x1) != 0);
					int32_t half = count >> 1;
					local27 = half << 3;
					ptr = local27 + ptr;
					compare6.compare<int32_t>(int32_t(LOAD32(ptr)), 85, flags);
					local6 = compare6.lt ? 1 : 0;
					if (local6 != 0) {
						count = count - half;
						ptr = ptr + 8;
						count = count - 1;
					} else {
						ptr = ptr - local27;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, ptr);
			}
			if (ptr != local5) {
				compare6.compare<int32_t>(int32_t(LOAD32(ptr)), 85, flags);
				if (!compare6.gt) {
					STORE64(stack + 80, LOAD64(stack + 80));
					uint32_t found = LOAD32(stack + 84);
					killValue = (uint64_t)LOAD32(found + 4);
					shouldKill = true;
				} else {
					killValue = (uint64_t)LOAD32(local5 + 4);
					shouldKill = true;
				}
			} else {
				killValue = (uint64_t)LOAD32(local5 + 4);
				shouldKill = true;
			}
		}
	} else {
		shouldKill = false;
	}

	if (shouldKill) {
		ctx.fpscr.disableFlushMode();
		double fadeOut = double(LOAD_F32(uint32_t(g_82099334) + 384));
		ctx.r1.u64 = stack;
		ctx.r6.u64 = local5;
		ctx.r8.u64 = local27;
		ctx.v127 = v1Reg;
		ctx.xer.ca = flags.ca;
		n_sub_8247EB68(ctx, base, killValue, fadeOut);
		impactType = ctx.r4.u64;
		local5 = ctx.r6.u64;
		local6 = ctx.r7.u64;
		local27 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	uint32_t field4 = bullet->m_4;
	uint32_t obj = LOAD32(field4 + 124);
	uint32_t vtable = LOAD32(obj);
	uint32_t fn = LOAD32(vtable + 100);
	callTarget.u64 = fn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = obj;
	ctx.r4.u64 = impactType;
	ctx.r6.u64 = local5;
	ctx.r7.u64 = local6;
	ctx.r8.u64 = local27;
	ctx.r9.u64 = fn;
	ctx.r10.u64 = vtable;
	ctx.v1 = v1Reg;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	result = ctx.r3.u32;
	v1Reg = ctx.v1;
	flags.ca = ctx.xer.ca;

	uint32_t arg2Byte = (uint32_t)(originalArg2 & 0xFF);
	double m70Value;
	if (arg2Byte != 0) {
		ctx.fpscr.disableFlushMode();
		m70Value = double(LOAD_F32(uint32_t(g_82099334)));
	} else {
		ctx.fpscr.disableFlushMode();
		m70Value = double(LOAD_F32(0x820F6B84u));
	}
	ctx.fpscr.disableFlushMode();
	bullet->m_70 = float(m70Value);
	uint64_t entityHandle = (int64_t)bulletAddr + 12;
	bullet->m_65 = uint8_t(1);
	uint32_t v10 = bullet->m_10;
	bool flag47 = false;
	if (v10 != 0) {
		uint32_t first = LOAD32(v10);
		if (first == 0) {
			result = EntityHandle_Release(ctx, base, entityHandle);
			v1Reg = ctx.v1;
			flags.ca = ctx.xer.ca;
			flag47 = false;
		} else {
			ctx.r8.u64 = arg2Byte;
			result = EntityHandle_Get_825575C8(ctx, base, entityHandle);
			v1Reg = ctx.v1;
			flags.ca = ctx.xer.ca;
			uint32_t byte144 = LOAD8(result + 144) & 64;
			flag47 = (byte144 != 0);
		}
	} else {
		flag47 = false;
	}

	if (flag47) {
		if (LOAD32(bulletAddr + 140) == 0) {
			uint32_t global = uint32_t(g_83490000);
			uint32_t a = LOAD32(global + 26912);
			uint32_t b = LOAD32(a + 12);
			uint32_t c = LOAD32(b + 88);
			uint32_t d = LOAD32(c + 4);
			uint32_t e = LOAD32(d + 16);
			ctx.r8.u64 = d;
			ctx.r9.u64 = c;
			uint32_t entity = EntityHandle_Get_825575C8(ctx, base, entityHandle);
			v1Reg = ctx.v1;
			flags.ca = ctx.xer.ca;
			uint64_t messageStack = (int64_t)(uint64_t)stack + 176;
			result = MessageEvents_PostMessageEvent(ctx, base, e, 69, messageStack, entity, 0, 101, 0);
			v1Reg = ctx.v1;
			flags.ca = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 144);
	SET_V8(v1Reg, VLOAD((stack + 0xFFFFFFD0u) & ~0xF));
	ctx.r1.u64 = stack;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(67, sub_82962A70, 0x82962A70) { ctx.r3.u64 = CECBullet_OnHit(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBullet_FindClosestBone(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t targetPosition) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(67, 0x82965358)) { ctx.r4.u64 = arg1; ctx.r5.u64 = targetPosition; __imp__sub_82965358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82965358);

	uint32_t stack = ctx.r1.u64;
	uint32_t bullet = (uint32_t)arg1;
	uint32_t target = (uint32_t)targetPosition;

	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = ctx.r9.u64;

	PPCVRegister vecTemp{};
	PPCVRegister vecResult = ctx.v11;
	PPCVRegister vecDiff = ctx.v12;
	PPCVRegister vecLoaded = ctx.v13;
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 176);

	uint64_t valuePtr = 0;
	bool haveValue = false;

	if ((LOAD32(bullet + 36) >> 23) & 1) {
		uint32_t mapPtr = LOAD32(bullet + 140);
		if (mapPtr != 0) {
			uint32_t slot = __builtin_rotateleft32((uint32_t)LOAD8(mapPtr + 23), 3);
			reg9 = (uint64_t)slot + (uint64_t)LOAD32(bullet + 72);
			valuePtr = (uint64_t)LOAD32((uint32_t)reg9 + 4);
			haveValue = true;
		} else {
			uint32_t begin = LOAD32(bullet + 72);
			uint32_t end = LOAD32(bullet + 76);
			reg6 = (uint64_t)end;

			STORE32(stack + 80, 0);
			uint32_t byteCount = end - begin;
			STORE32(stack + 84, begin);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 0x7) != 0);
			int32_t remaining = (int32_t)byteCount >> 3;
			uint32_t search = begin;

			if (remaining > 0) {
				do {
					flags.ca = ((int32_t)remaining < 0) & ((remaining & 0x1) != 0);
					int32_t half = remaining >> 1;
					reg9 = (uint64_t)half;
					reg8 = (uint64_t)((uint32_t)reg9 << 3);
					search = (uint32_t)(reg8 + search);
					reg7 = ((int32_t)LOAD32(search) < 23) ? 1 : 0;
					if ((uint32_t)reg7 != 0) {
						remaining = remaining - half;
						search = search + 8;
						remaining = remaining - 1;
					} else {
						search = (uint32_t)(search - reg8);
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, search);
			}

			if (search != end) {
				if (!((int32_t)LOAD32(search) > 23)) {
					STORE64(stack + 80, LOAD64(stack + 80));
					valuePtr = (uint64_t)LOAD32(search + 4);
					haveValue = true;
				} else {
					valuePtr = (uint64_t)LOAD32(end + 4);
					haveValue = true;
				}
			} else {
				valuePtr = (uint64_t)LOAD32(end + 4);
				haveValue = true;
			}
		}
	}

	if (haveValue) {
		uint32_t begin = LOAD32((uint32_t)valuePtr + 48);
		int32_t count = 0;
		if (begin != 0) {
			reg9 = 44;
			reg8 = (uint64_t)LOAD32((uint32_t)valuePtr + 52) - (uint64_t)begin;
			count = (int32_t)reg8 / 44;
		}

		uint32_t dataBase = (uint32_t)g_820A0000 - 27468;
		ctx.fpscr.disableFlushMode();
		double bestDistance = (double)LOAD_F32(dataBase + 18768);
		uint64_t bestIndex = 0;

		if (count > 0) {
			double maxDistance = (double)LOAD_F32(dataBase);
			for (uint64_t index = 0; (int32_t)index < count; ++index) {
				uint64_t stackTemp = (uint64_t)stack + 96;

				ctx.r1.u64 = stack;
				ctx.r7.u64 = reg7;
				ctx.r8.u64 = reg8;
				ctx.v11 = vecResult;
				ctx.v12 = vecDiff;
				ctx.v13 = vecLoaded;
				ctx.xer.ca = flags.ca;

				uint32_t resultPtr = n_sub_82399078(ctx, base, stackTemp, valuePtr, index);

				arg1 = ctx.r4.u64;
				targetPosition = ctx.r5.u64;
				reg6 = ctx.r6.u64;
				reg7 = ctx.r7.u64;
				reg8 = ctx.r8.u64;
				reg9 = ctx.r9.u64;
				flags.ca = ctx.xer.ca;

				SET_V8(vecTemp, VLOAD(target & ~0xF));
				SET_V8(vecLoaded, VLOAD(resultPtr & ~0xF));
				ctx.fpscr.enableFlushMode();
				SET_VF(vecDiff, simde_mm_sub_ps(VF(vecLoaded), VF(vecTemp)));
				ctx.fpscr.disableFlushModeUnconditional();
				ctx.fpscr.enableFlushModeUnconditional();
				SET_VF(vecResult, simde_mm_dp_ps(VF(vecDiff), VF(vecDiff), 0xEF));
				VSTORE((uint32_t)((int64_t)(uint64_t)stack + 80) & ~0xF, V8(vecResult));
				ctx.fpscr.disableFlushModeUnconditional();
				double distance = (double)LOAD_F32(stack + 80);

				bool update = false;
				if (!(bestDistance < maxDistance)) {
					if (!(distance < bestDistance)) {
						update = false;
					} else {
						update = true;
					}
				} else {
					update = true;
				}

				if (update) {
					ctx.fpscr.disableFlushMode();
					bestDistance = distance;
					bestIndex = index;
				}
			}
		}

		uint64_t result = bestIndex;
		stack = PopStackFrame(stack, 176);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg1;
		ctx.r5.u64 = targetPosition;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.v11 = vecResult;
		ctx.v12 = vecDiff;
		ctx.v13 = vecLoaded;
		ctx.xer.ca = flags.ca;
		return result;
	}

	int32_t noValue = -1;
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg1;
	ctx.r5.u64 = targetPosition;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.xer.ca = flags.ca;
	return (uint64_t)noValue;
}
PROMOTED_ENTRY(67, sub_82965358, 0x82965358) { ctx.r3.u64 = CECBullet_FindClosestBone(ctx, base, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECBullet_UpdateLifetime(CpuState& ctx, uint8_t* base, uint64_t bulletAddr) {
	constexpr int32_t g_8209FFD8 = int32_t(0x8209FFD8);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(67, 0x82965540)) { ctx.r3.u64 = bulletAddr; __imp__sub_82965540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82965540);
	uint32_t stack = ctx.r1.u64;
	CECBullet* bullet = GameObject<CECBullet>(base, bulletAddr);
	stack = PushStackFrame(base, stack, 144);

	const uint64_t handleAddr = bulletAddr + 36;
	const uint32_t constants = uint32_t(g_8209FFD8);
	const uint32_t maskTable = uint32_t(g_82100170);
	const double fullLife = double(LOAD_F32(constants - 27416));
	const double limit = double(LOAD_F32(constants - 27428));
	const uint32_t handleState = bullet->m_6C;

	// Conditional select as the compiler emits it: a sign mask read from the
	// constant table picks between the two values.
	auto select = [&](bool condition, double whenTrue, double whenFalse) -> double {
		const float mask = LOAD_F32(maskTable + (condition ? 4 : 0));
		return mask >= 0.0f ? whenFalse : whenTrue;
	};

	// A dead (or released) target handle lets the life be topped back up.
	if (handleState != 0) {
		bool targetStillActive = false;
		const uint32_t targetRef = bullet->m_28;
		if (targetRef != 0) {
			const uint32_t targetHead = LOAD32(targetRef);
			if (targetHead == 0) {
				ctx.r1.u64 = stack;
				EntityHandle_Release(ctx, base, handleAddr);
			} else {
				ctx.r1.u64 = stack;
				ctx.r9.u64 = handleState;
				const uint32_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
				targetStillActive = (LOAD8(target + 0x90) & 0x40) != 0;
			}
		}
		if (!targetStillActive) {
			ctx.fpscr.disableFlushMode();
			const double currentLife = double(bullet->m_70);
			const double overshoot = double(float(fullLife - currentLife));
			bullet->m_70 = float(select(!(overshoot >= limit), fullLife, currentLife));
		}
	}

	uint32_t result = 1;
	ctx.fpscr.disableFlushMode();
	double life = double(bullet->m_70);
	if (life > limit) {
		const double frameTime = LOAD_F64(constants) / LOAD_F64(0x83319510u);
		life = double(float(life - double(float(frameTime))));
		bullet->m_70 = float(life);

		const double clampedLife = select(!(life >= limit), limit, life);
		const double overrun = double(float(clampedLife - fullLife));
		const double cappedLife = select(!(overrun >= limit), clampedLife, fullLife);

		if (cappedLife < fullLife) {
			const uint32_t manager = bullet->m_4;
			bool hasTargetType = false;
			uint32_t targetType = 0;
			if ((LOAD32(manager + 36) >> 3) & 1) {
				const uint32_t first = LOAD32(manager + 72);
				const uint32_t hint = LOAD32(manager + 140);
				if (hint != 0) {
					const uint32_t index = LOAD8(hint + 3);
					targetType = LOAD32(first + (index << 3) + 4);
					hasTargetType = true;
				} else {
					// lower_bound over the sorted table of 8-byte (key, value) entries
					const uint32_t last = LOAD32(manager + 76);
					uint32_t found = first;
					int32_t count = int32_t(last - first) >> 3;
					STORE32(stack + 80, 0);
					STORE32(stack + 84, first);
					if (count > 0) {
						do {
							const int32_t half = count >> 1;
							const uint32_t middle = found + (uint32_t(half) << 3);
							if (int32_t(LOAD32(middle)) < 3) {
								found = middle + 8;
								count = count - half - 1;
							} else {
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, found);
					}
					if (found != last && int32_t(LOAD32(found)) <= 3) {
						STORE64(stack + 80, LOAD64(stack + 80));
						targetType = LOAD32(found + 4);
					} else {
						targetType = LOAD32(last + 4);
					}
					hasTargetType = true;
				}
			}
			if (hasTargetType) {
				ctx.fpscr.disableFlushMode();
				ctx.r1.u64 = stack;
				if (!(cappedLife > limit)) {
					CECGraphicAppearance_SetState(ctx, base, targetType, 0);
				} else {
					ctx.fpscr.disableFlushMode();
					CECGraphicAppearance_SetAlpha(ctx, base, targetType, cappedLife);
				}
			}
		}
		ctx.fpscr.disableFlushMode();
		result = (cappedLife > limit) ? 1 : 0;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82965540, 0x82965540) { ctx.r3.u64 = CECBullet_UpdateLifetime(ctx, base, ctx.r3.u64); }
