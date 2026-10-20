// CECShard (vtable 0x820CCBD0): methods of the class as readable C++.
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

// sub_826B20F8  [60 bytes]
uint64_t CECShard_GetClassName(CpuState& ctx, uint8_t* base, uint64_t resultString) {
	constexpr int32_t str_TXT_820C92A8_B_ = int32_t(0x820C92A8);
	if (!UseLiftedCode(45, 0x826B20F8)) { ctx.r3.u64 = resultString; __imp__sub_826B20F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B20F8);
	uint32_t stack = ctx.r1.u64;
	uint64_t nameString = static_cast<uint64_t>(str_TXT_820C92A8_B_);
	int32_t nameLength = -1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, resultString, nameString, nameLength);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return resultString;
}
PROMOTED_ENTRY(45, sub_826B20F8, 0x826B20F8) { ctx.r3.u64 = CECShard_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECShard_Delete(CpuState& ctx, uint8_t* base, uint64_t shard, uint64_t flags) {
	if (!UseLiftedCode(45, 0x826B2340)) { ctx.r3.u64 = shard; ctx.r4.u64 = flags; __imp__sub_826B2340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B2340);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = flags;  // state the callee may pass on
	CECShard_Destructor(ctx, base, shard);
	if (flags & 0x1) {
		HandleTarget_Free(ctx, base, shard);
	}
	return shard;
}
PROMOTED_ENTRY(45, sub_826B2340, 0x826B2340) { ctx.r3.u64 = CECShard_Delete(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_826B2390  [248 bytes]
uint32_t CECShard_Destructor(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(45, 0x826B2390)) { ctx.r3.u64 = shardAddr; __imp__sub_826B2390(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B2390);
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	SharedHandle_Release(ctx, base, shardAddr + 396);
	shard->m_160 = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 352);
	shard->m_164 = 0;
	C_820EFB9C_Destructor(ctx, base, shardAddr + 336);
	shard->m_13C = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 316);
	shard->m_140 = 0;
	shard->m_12C = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 300);
	shard->m_130 = 0;
	shard->m_124 = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 292);
	shard->m_128 = 0;
	SharedHandle_Release(ctx, base, shardAddr + 280);

	uint64_t handleAddr = shardAddr + 280;
	for (int32_t i = 3; i >= 0; --i) {
		handleAddr -= 8;
		SharedHandle_Release(ctx, base, handleAddr);
	}

	shard->m_F0 = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 240);
	shard->m_F4 = 0;
	shard->m_E8 = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 232);
	shard->m_EC = 0;
	shard->m_E0 = g_820F1664;
	EntityHandle_Release(ctx, base, shardAddr + 224);
	shard->m_E4 = 0;

	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, shardAddr + 20);

	uint32_t secondaryVtableAddr = 0;
	if ((uint32_t)shardAddr != 0) {
		secondaryVtableAddr = (uint32_t)(shardAddr + 12);
	}
	STORE32(secondaryVtableAddr, 0x820A8F74u);
	shard->vtable = 0x820A8D10u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B2390, 0x826B2390) { ctx.r3.u64 = CECShard_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CECShard_Update(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	if (!UseLiftedCode(45, 0x826B2FA8)) { ctx.r3.u64 = shardAddr; __imp__sub_826B2FA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B2FA8);
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	stack = PushStackFrame(base, stack, 96);

	if (shard->m_188 != 0) {
		ctx.r1.u64 = stack;
		uint64_t result = CECShard_UpdateExplosion(ctx, base, shardAddr);
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return result;
	}

	if (shard->m_40 != 0) {
		ctx.r1.u64 = stack;
		CECShard_UpdatePhysics(ctx, base, shardAddr);
	}
	if (shard->m_A5 != 0) {
		ctx.r1.u64 = stack;
		CECShard_UpdateParticles(ctx, base, shardAddr);
	}
	// m_134 is the flag Shard.IsAdjustingSpinSpeed reports
	if (shard->m_134 != 0) {
		ctx.r1.u64 = stack;
		CECShard_UpdateSpinSpeed(ctx, base, shardAddr);
	}

	// Shard.TrackTarget keeps the tracked entity's handle at +0x13C (m_140 is its reference).
	uint64_t trackedHandleAddr = shardAddr + 0x13C;
	uint32_t trackedRef = shard->m_140;
	if (trackedRef != 0) {
		uint32_t trackedEntity = LOAD32(trackedRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = trackedEntity;  // state the callee may pass on
		if (trackedEntity == 0) {
			EntityHandle_Release(ctx, base, trackedHandleAddr);
		} else {
			uint32_t entity = EntityHandle_Get_825575C8(ctx, base, trackedHandleAddr);
			uint32_t entityBit40 = LOAD8(entity + 0x90) & 0x40;
			if (entityBit40 != 0) {
				ctx.r10.u64 = entityBit40;  // state the callee may pass on
				CECShard_UpdateTargetTracking(ctx, base, shardAddr);
			}
		}
	}

	if (shard->m_118 != 0) {
		ctx.r1.u64 = stack;
		CECShard_UpdateTrail(ctx, base, shardAddr);
	}

	ctx.r1.u64 = stack;
	uint64_t result = CECShard_UpdateCombat(ctx, base, shardAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B2FA8, 0x826B2FA8) { ctx.r3.u64 = CECShard_Update(ctx, base, ctx.r3.u64); }

uint64_t CECShard_DestroyEntityList(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(45, 0x826B42F0)) { ctx.r3.u64 = shardAddr; __imp__sub_826B42F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B42F0);
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t listHandleAddr = shardAddr + 396;
	uint32_t list = LOAD32((uint32_t)listHandleAddr);
	uint64_t result = shardAddr;

	if (list != 0) {
		// 8-byte entries from begin (+4) to end (+8); the list is re-read after every entry
		uint64_t byteSize = (uint64_t)LOAD32(list + 8) - (uint64_t)LOAD32(list + 4);
		bool carry = ((int32_t)byteSize < 0) & (((uint32_t)byteSize & 0x7) != 0);
		uint32_t entryCount = (uint32_t)((int32_t)byteSize >> 3);
		uint32_t i = 0;
		uint64_t entryOffset = 0;

		while (i < entryCount) {
			uint64_t entryAddr = (uint64_t)LOAD32(list + 4) + entryOffset;
			ctx.xer.ca = carry;
			uint64_t entity = EntityManager_LookupEntity(ctx, base,
				LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(g_83490000 + 26912) + 12) + 88) + 4)),
				entryAddr);
			if ((uint32_t)entity != 0 && (LOAD8((uint32_t)entity + 144) & 64) != 0) {
				Entity_DestroyImpl(ctx, base, entity);
			}
			list = LOAD32((uint32_t)listHandleAddr);
			i++;
			entryOffset += 8;
			byteSize = (uint64_t)LOAD32(list + 8) - (uint64_t)LOAD32(list + 4);
			carry = ((int32_t)byteSize < 0) & (((uint32_t)byteSize & 0x7) != 0);
			entryCount = (uint32_t)((int32_t)byteSize >> 3);
		}
		// state the callee may pass on
		ctx.r7.u64 = (uint64_t)(int64_t)(int32_t)entryCount;
		ctx.r8.u64 = byteSize;
		ctx.xer.ca = carry;
		result = SharedHandle_Release(ctx, base, listHandleAddr);
		STORE32((uint32_t)listHandleAddr, 0u);
	}
	return result;
}
PROMOTED_ENTRY(45, sub_826B42F0, 0x826B42F0) { ctx.r3.u64 = CECShard_DestroyEntityList(ctx, base, ctx.r3.u64); }

uint32_t Shard_Kill_Impl(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(45, 0x826B5DB0)) { ctx.r3.u64 = shardAddr; __imp__sub_826B5DB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B5DB0);
	uint32_t stack = ctx.r1.u64;
	constexpr int32_t kTableKey = 85;
	PPCXERRegister xer = ctx.xer;

	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t handleAddr = shardAddr + 224;  // the shard's EntityHandle (m_E0 vtable, m_E4 reference)
	shard->m_A5 = 0;

	uint32_t handleRef = shard->m_E4;
	if (handleRef != 0) {
		uint32_t handleEntity = LOAD32(handleRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = handleEntity;  // state the callee may pass on
		if (handleEntity == 0) {
			EntityHandle_Release(ctx, base, handleAddr);
			uint32_t result = Shard_ReleaseEffectsAndSendBeamAttack(ctx, base, shardAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return result;
		}

		uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		// r6-r9, cr0 and xer.ca as the calls below receive them
		uint64_t argR6 = ctx.r6.u64;
		uint64_t argR7 = ctx.r7.u64;
		uint64_t argR8 = ctx.r8.u64;
		uint64_t argR9 = ctx.r9.u64;
		PPCCRRegister cr0 = ctx.cr0;
		xer.ca = ctx.xer.ca;

		uint64_t tempAddr = (uint64_t)stack + 80;  // stack slot: search iterator, then a temporary EntityHandle
		bool hasEmitter = false;
		uint32_t particleEmitter = 0;
		if ((LOAD32(entity + 44) & (1u << 21)) != 0) {
			uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				// byte kTableKey of the index table gives the entry's index in the {key, value} table at entity+0x48
				argR9 = (uint32_t(LOAD8(indexTable + kTableKey)) << 3) + (uint64_t)LOAD32(entity + 72);
				particleEmitter = LOAD32((uint32_t)argR9 + 4);
			} else {
				// lower_bound(kTableKey) over the sorted {key, value} table at entity+0x48
				uint32_t begin = LOAD32(entity + 72);
				uint32_t end = LOAD32(entity + 76);
				argR6 = end;
				STORE32(tempAddr, 0);
				STORE32(tempAddr + 4, begin);
				xer.ca = (int32_t)(end - begin) < 0 && ((end - begin) & 7) != 0;
				int32_t count = (int32_t)(end - begin) >> 3;
				cr0.compare<int32_t>(count, 0, xer);
				if (count > 0) {
					do {
						xer.ca = count < 0 && (count & 1) != 0;
						int32_t half = count >> 1;
						uint32_t halfOffset = (uint32_t)half << 3;
						uint32_t mid = begin + halfOffset;
						argR7 = (int32_t)LOAD32(mid) < kTableKey ? 1 : 0;
						argR8 = halfOffset;
						argR9 = (uint32_t)half;
						if (argR7 != 0) {
							count = count - half - 1;
							begin = mid + 8;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(tempAddr + 4, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= kTableKey) {
					STORE64(tempAddr, LOAD64(tempAddr));
					particleEmitter = LOAD32(LOAD32(tempAddr + 4) + 4);
				} else {
					particleEmitter = LOAD32(end + 4);
				}
			}
			hasEmitter = true;
		}

		if (hasEmitter) {
			ctx.fpscr.disableFlushMode();
			double fadeOutTime = double(LOAD_F32(0x820994C0u));
			// state the callee may pass on
			ctx.r6.u64 = argR6;
			ctx.r8.u64 = argR8;
			ctx.cr0 = cr0;
			ctx.xer.ca = xer.ca;
			n_sub_8247EB68(ctx, base, particleEmitter, fadeOutTime);  // Lua_ParticleEmitter_KillParticleWithFadeOut
			argR6 = ctx.r6.u64;
			argR7 = ctx.r7.u64;
			argR8 = ctx.r8.u64;
			argR9 = ctx.r9.u64;
			cr0 = ctx.cr0;
			xer.ca = ctx.xer.ca;
		}

		// Empty the shard's handle: assign it an empty temporary EntityHandle (vtable 0x820F1664), then release that.
		STORE32(tempAddr + 4, 0);
		STORE32(tempAddr, (uint32_t)g_820F1664);
		// state the callee may pass on
		ctx.cr0 = cr0;
		ctx.xer.ca = xer.ca;
		EntityHandle_Release(ctx, base, tempAddr);
		EntityHandle_Assign(ctx, base, handleAddr, tempAddr);
		uint64_t entityHandleVtable = (int64_t)g_820F0000 + 5732;
		STORE32(tempAddr, (uint32_t)entityHandleVtable);
		// state the callee may pass on
		EntityHandle_Release(ctx, base, tempAddr);
	}

	ctx.r1.u64 = stack;
	uint32_t result = Shard_ReleaseEffectsAndSendBeamAttack(ctx, base, shardAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B5DB0, 0x826B5DB0) { ctx.r3.u64 = Shard_Kill_Impl(ctx, base, ctx.r3.u64); }

// sub_826B5FF8  [520 bytes]
// Moves the value at entry+40 (the owner's table entry with key 29) by the change rate m_138, clamped to the
// target m_1C that Shard.SetNewSpinSpeed / StartSpinning / StopSpinning set; reaching the target, or having
// no entry, clears m_134.
uint32_t CECShard_UpdateSpinSpeed(CpuState& ctx, uint8_t* base, uint32_t shardAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	if (!UseLiftedCode(45, 0x826B5FF8)) { ctx.r3.u64 = shardAddr; __imp__sub_826B5FF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B5FF8);
	uint32_t stack = ctx.r1.u32;
	constexpr int32_t kTableKey = 29;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	PPCXERRegister flags = ctx.xer;
	// r6-r10 as the call below receives them (the caller's r6-r9 unless the lookup replaces them)
	uint64_t argR6 = ctx.r6.u64;
	uint64_t argR7 = ctx.r7.u64;
	uint64_t argR8 = ctx.r8.u64;
	uint64_t argR9 = ctx.r9.u64;
	uint64_t argR10 = 0;

	stack = PushStackFrame(base, stack, 112);

	uint32_t owner = shard->m_4;
	uint32_t entry = 0;
	bool hasEntry = false;
	if (((LOAD32(owner + 36) >> 29) & 1) != 0) {
		uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			// byte kTableKey of the index table gives the entry's index in the {key, value} table at owner+0x48
			argR10 = uint32_t(LOAD8(indexTable + kTableKey)) << 3;
			argR9 = argR10 + (uint64_t)LOAD32(owner + 72);
			entry = LOAD32((uint32_t)argR9 + 4);
		} else {
			// lower_bound(kTableKey) over the sorted {key, value} table at owner+0x48
			uint64_t it = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			argR6 = end;
			STORE32(stack + 80, 0);
			uint32_t byteCount = end - (uint32_t)it;
			STORE32(stack + 84, (uint32_t)it);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 0x7) != 0);
			int32_t count = (int32_t)byteCount >> 3;
			if (count > 0) {
				do {
					flags.ca = (count < 0) & ((count & 0x1) != 0);
					int32_t half = count >> 1;
					argR9 = (uint32_t)half;
					argR8 = (uint32_t)half << 3;
					uint64_t mid = it + argR8;
					argR7 = (int32_t)LOAD32((uint32_t)mid) < kTableKey ? 1 : 0;
					if (argR7 != 0) {
						count = count - half - 1;
						it = mid + 8;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, (uint32_t)it);
			}
			if ((uint32_t)it != end && (int32_t)LOAD32((uint32_t)it) <= kTableKey) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry = LOAD32(end + 4);
			}
			argR10 = it;
		}
		hasEntry = true;
	}

	if (hasEntry) {
		ctx.fpscr.disableFlushMode();
		double scale = LOAD_F64(0x83319510u);
		double scaledProduct = double(LOAD_F32(entry + 40)) * scale;
		double scaledValue = double(float(scaledProduct));
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.xer.ca = flags.ca;
		double callResult = Game_GetDeltaTime(ctx, base, owner);
		ctx.fpscr.disableFlushMode();
		double step = callResult / scale;
		double changeRate = double(shard->m_138);
		double floorValue = double(LOAD_F32(0x820994B4u));
		double weight = double(LOAD_F32(0x82100200u));
		double stepF = double(float(step));
		double change = double(float(changeRate * stepF));
		double speed = double(float(std::fma(scaledValue, weight, change)));
		// f11 as callers see it: scaledValue, or the target when the rate is below floorValue
		double f11Out = scaledValue;
		if (changeRate < floorValue) {
			double target = double(shard->m_1C);
			f11Out = target;
			if (speed < target) {
				speed = target;
				shard->m_134 = 0;
			}
		}
		ctx.fpscr.disableFlushMode();
		if (changeRate > floorValue) {
			double target = double(shard->m_1C);
			if (speed > target) {
				speed = target;
				shard->m_134 = 0;
			}
		}
		ctx.fpscr.disableFlushMode();
		double outputScale = double(LOAD_F32(0x821001DCu));
		speed = double(float(speed * outputScale));
		double f13Out = outputScale;
		if (speed > floorValue) {
			f13Out = double(float(speed / scale));
			STORE_F32(entry + 40, float(f13Out));
		} else {
			ctx.fpscr.disableFlushMode();
			STORE_F32(entry + 40, float(floorValue));
		}
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		// callers read r4, r5, r9, r10, f1 and f7-f13 after the call (r9/r10: bases of the constants above)
		ctx.r4.u64 = 0;
		ctx.r5.u64 = entry;
		ctx.r9.s64 = str_TXT_82100000_B_;
		ctx.r10.u64 = uint32_t(g_820A0000);
		ctx.f1.f64 = callResult;
		ctx.f7.f64 = change;
		ctx.f8.f64 = stepF;
		ctx.f9.f64 = step;
		ctx.f10.f64 = scale;
		ctx.f11.f64 = f11Out;
		ctx.f12.f64 = floorValue;
		ctx.f13.f64 = f13Out;
		return owner;
	}

	shard->m_134 = 0;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4-r10 and xer.ca after the call (r6-r9 and xer.ca are still the caller's here)
	ctx.r4.u64 = 0;
	ctx.r5.u64 = 0;
	ctx.r6.u64 = argR6;
	ctx.r7.u64 = argR7;
	ctx.r8.u64 = argR8;
	ctx.r9.u64 = argR9;
	ctx.r10.u64 = argR10;
	ctx.xer.ca = flags.ca;
	return owner;
}
PROMOTED_ENTRY(45, sub_826B5FF8, 0x826B5FF8) { ctx.r3.u64 = CECShard_UpdateSpinSpeed(ctx, base, ctx.r3.u32); }

// Turns the shard's owner (m_4) toward the entity tracked through the handle at +0x13C (Shard.TrackTarget):
// the aim point is the target's slot-64 vector plus its slot-76 vector scaled by the float at +0x144; the turn
// per call is limited by m_148, and with m_14C clear the owner's reversed facing is used. When the target is
// gone or lacks bit 0x40 of its byte +0x90, the handle is emptied instead.
uint32_t CECShard_UpdateTargetTracking(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(45, 0x826B62A0)) { ctx.r3.u64 = shardAddr; __imp__sub_826B62A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B62A0);
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);

	// The original prologue saves v126/v127 just below the incoming stack pointer.
	VSTORE((stack + 0xFFFFFFC0u) & ~0xF, V8(ctx.v126));
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 224);

	uint64_t trackedHandleAddr = shardAddr + 316;
	bool tracking = false;
	uint32_t trackedRef = shard->m_140;
	if (trackedRef != 0) {
		uint32_t trackedEntity = LOAD32(trackedRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = trackedEntity;  // state the callee may pass on
		if (trackedEntity == 0) {
			EntityHandle_Release(ctx, base, trackedHandleAddr);
		} else {
			uint32_t entity = EntityHandle_Get_825575C8(ctx, base, trackedHandleAddr);
			tracking = (LOAD8(entity + 144) & 64) != 0;
		}
	}

	uint32_t result;
	if (!tracking) {
		// Empty the tracked handle: assign it an empty temporary EntityHandle (vtable 0x820F1664), then release that.
		uint64_t tempHandle = (uint64_t)stack + 80;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)g_820F1664);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		EntityHandle_Release(ctx, base, tempHandle);
		EntityHandle_Assign(ctx, base, trackedHandleAddr, tempHandle);
		uint64_t entityHandleVtable = (int64_t)g_820F0000 + 5732;
		STORE32(stack + 80, (uint32_t)entityHandleVtable);
		// state the callee may pass on
		result = EntityHandle_Release(ctx, base, tempHandle);
	} else {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 64;  // state the callee may pass on (the bit tested above)
		uint32_t target = EntityHandle_Get_825575C8(ctx, base, trackedHandleAddr);

		// slot 64 of the target's object at +124 writes a vector to stack+96
		uint64_t targetPointAddr = (uint64_t)stack + 96;
		uint32_t targetObj = LOAD32(target + 124);
		uint32_t targetVtable = LOAD32(targetObj);
		uint32_t targetSlot64 = LOAD32(targetVtable + 64);
		callTarget.u64 = targetSlot64;
		ctx.r3.u64 = targetPointAddr;
		ctx.r4.u64 = targetObj;
		ctx.r9.u64 = targetSlot64;
		ctx.r10.u64 = targetVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// slot 76 of the same kind of object writes a vector to stack+128
		uint64_t target2 = EntityHandle_Get_825575C8(ctx, base, trackedHandleAddr);
		uint64_t targetMotionAddr = (uint64_t)stack + 128;
		uint32_t targetObj2 = LOAD32((uint32_t)target2 + 124);
		uint32_t targetVtable2 = LOAD32(targetObj2);
		uint32_t targetSlot76 = LOAD32(targetVtable2 + 76);
		callTarget.u64 = targetSlot76;
		ctx.r3.u64 = targetMotionAddr;
		ctx.r4.u64 = targetObj2;
		ctx.r6.u64 = targetSlot76;
		ctx.r7.u64 = targetVtable2;
		ctx.r8.u64 = target2;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// aim point = point + motion * lead, lead being the float at +0x144 (lvlx + splat) in every lane
		uint32_t owner = shard->m_4;
		uint64_t ownerPointAddr = (uint64_t)stack + 144;
		uint32_t leadAddr = (uint32_t)shardAddr + 324;
		PPCVRegister leadLoad{};
		SET_V8(leadLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(leadAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(leadAddr & 0xF) * 16])));
		PPCVRegister lead{};
		SET_V8(lead, simde_mm_shuffle_epi32(V8(leadLoad), 0xFF));
		PPCVRegister targetPoint{};
		SET_V8(targetPoint, VLOAD((uint32_t)targetPointAddr & ~0xF));
		PPCVRegister targetMotion{};
		SET_V8(targetMotion, VLOAD((uint32_t)targetMotionAddr & ~0xF));
		ctx.fpscr.enableFlushMode();
		PPCVRegister aimPoint{};
		SET_VF(aimPoint, simde_mm_add_ps(simde_mm_mul_ps(VF(targetMotion), VF(lead)), VF(targetPoint)));
		VSTORE((uint32_t)targetPointAddr & ~0xF, V8(aimPoint));

		// slot 64 of the owner's object at +124 writes the matching vector to stack+144
		uint32_t ownerObj = LOAD32(owner + 124);
		uint32_t ownerVtable = LOAD32(ownerObj);
		uint32_t ownerSlot64 = LOAD32(ownerVtable + 64);
		callTarget.u64 = ownerSlot64;
		ctx.r3.u64 = ownerPointAddr;
		ctx.r4.u64 = ownerObj;
		// state the callee may pass on
		ctx.r5.u64 = 324;
		ctx.r7.u64 = ownerSlot64;
		ctx.r8.u64 = ownerVtable;
		ctx.r9.u64 = owner;
		ctx.r10.u64 = targetPointAddr;
		ctx.v10 = aimPoint;
		ctx.v11 = targetMotion;
		ctx.v12 = targetPoint;
		ctx.v13 = lead;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// masked direction from the owner to the aim point, normalized in place at stack+112
		SET_V8(aimPoint, VLOAD((uint32_t)targetPointAddr & ~0xF));
		PPCVRegister ownerPoint{};
		SET_V8(ownerPoint, VLOAD((uint32_t)ownerPointAddr & ~0xF));
		uint32_t aimDirAddr = stack + 112;
		ctx.fpscr.enableFlushMode();
		PPCVRegister toAim{};
		SET_VF(toAim, simde_mm_sub_ps(VF(aimPoint), VF(ownerPoint)));
		PPCVRegister mask{};
		SET_V8(mask, VLOAD(0x82099120u & ~0xF));
		ctx.fpscr.disableFlushModeUnconditional();
		double minLength = double(LOAD_F32(0x82099AE0u));
		PPCVRegister toAimMasked{};
		SET_V8(toAimMasked, simde_mm_and_si128(V8(toAim), V8(mask)));
		VSTORE(aimDirAddr & ~0xF, V8(toAimMasked));
		double aimDistance = Vec4_NormalizeInPlace_ReturnLength(ctx, base, aimDirAddr, minLength);

		// GetFacingDirection writes the owner's current facing vector to stack+80
		owner = shard->m_4;
		uint64_t facingAddr = (uint64_t)stack + 80;
		uint32_t ownerObjForFacing = LOAD32(owner + 124);
		// state the callee may pass on
		ctx.r5.u64 = ownerPointAddr;
		ctx.r6.u64 = targetPointAddr;
		ctx.r8.u64 = owner;
		ctx.f1.f64 = aimDistance;
		ctx.v6 = toAimMasked;
		ctx.v7 = toAim;
		ctx.v8 = ownerPoint;
		ctx.v9 = aimPoint;
		GetFacingDirection(ctx, base, facingAddr, ownerObjForFacing);
		// v12/v13 as that call leaves them; the later calls receive them unless replaced below
		PPCVRegister handV12 = ctx.v12;
		PPCVRegister handV13 = ctx.v13;

		PPCVRegister signMask{};
		SET_V8(signMask, simde_mm_set1_epi32(int(0x80000000)));
		uint32_t keepFacingSign = shard->m_14C;
		PPCVRegister facing{};
		if (keepFacingSign != 0) {
			SET_V8(facing, VLOAD((uint32_t)facingAddr & ~0xF));
		} else {
			SET_V8(handV12, VLOAD((uint32_t)facingAddr & ~0xF));
			handV13 = signMask;
			SET_V8(facing, simde_mm_xor_si128(V8(handV12), V8(signMask)));
		}
		PPCVRegister aimDir{};
		SET_V8(aimDir, VLOAD(aimDirAddr & ~0xF));
		ctx.v1 = aimDir;
		ctx.v2 = facing;
		ctx.v13 = handV13;
		double angle = Vector3_AngleBetween(ctx, base);

		owner = shard->m_4;
		ctx.fpscr.disableFlushMode();
		// state the callee may pass on
		ctx.f1.f64 = angle;
		double callResult = Game_GetDeltaTime(ctx, base, owner);
		ctx.fpscr.disableFlushMode();
		double turnSpeed = double(shard->m_148);
		double step = callResult / LOAD_F64(0x83319510u);
		double scaledTurnSpeed = double(float(turnSpeed * double(LOAD_F32(0x821001DCu))));
		double stepF = double(float(step));
		double maxTurn = double(float(scaledTurnSpeed * stepF));

		uint32_t facingObj;
		PPCVRegister newFacing{};
		if (!(angle > maxTurn)) {
			// within this call's turn limit: face along the aim direction (reversed when m_14C is clear)
			facingObj = LOAD32(uint32_t(shard->m_4) + 124);
			if (shard->m_14C != 0) {
				newFacing = aimDir;
			} else {
				SET_V8(newFacing, simde_mm_xor_si128(V8(aimDir), V8(signMask)));
				ctx.v13 = signMask;  // state the callee may pass on
			}
		} else {
			// turn part of the way: facing + (aimDir - facing) * (maxTurn / angle)
			ctx.fpscr.enableFlushMode();
			PPCVRegister turn{};
			SET_VF(turn, simde_mm_sub_ps(VF(aimDir), VF(facing)));
			ctx.fpscr.disableFlushModeUnconditional();
			double fraction = double(float(maxTurn / angle));
			STORE_F32(stack + 80, float(fraction));
			uint32_t fractionAddr = stack + 80;
			PPCVRegister fractionLoad{};
			SET_V8(fractionLoad, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(fractionAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(fractionAddr & 0xF) * 16])));
			PPCVRegister fractionSplat{};
			SET_V8(fractionSplat, simde_mm_shuffle_epi32(V8(fractionLoad), 0xFF));
			facingObj = LOAD32(uint32_t(shard->m_4) + 124);
			ctx.fpscr.enableFlushModeUnconditional();
			SET_VF(newFacing, simde_mm_add_ps(simde_mm_mul_ps(VF(turn), VF(fractionSplat)), VF(facing)));
			PPCVRegister v13Out = fractionLoad;
			if (shard->m_14C == 0) {
				v13Out = signMask;
				SET_V8(newFacing, simde_mm_xor_si128(V8(newFacing), V8(signMask)));
			}
			ctx.v13 = v13Out;  // state the callee may pass on
		}
		// state the callee may pass on
		ctx.v1 = newFacing;
		ctx.v12 = handV12;
		result = Entity_SetFacingDirectionNormalized(ctx, base, facingObj);
	}

	stack = PopStackFrame(stack, 224);
	// callers read r0 after the call (the epilogue leaves its v127 restore offset there)
	ctx.r0.u64 = 0xFFFFFFD0;
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B62A0, 0x826B62A0) { ctx.r3.u64 = CECShard_UpdateTargetTracking(ctx, base, ctx.r3.u64); }

uint64_t CECShard_KillTrackedParticle(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	if (!UseLiftedCode(45, 0x826B8098)) { ctx.r3.u64 = shardAddr; __imp__sub_826B8098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B8098);
	uint32_t stack = ctx.r1.u64;
	// xer.so as the caller left it: the search below copies it into cr0
	const PPCXERRegister callerXer = ctx.xer;
	uint64_t result = shardAddr;
	stack = PushStackFrame(base, stack, 112);

	// The entity handle at +240: its second word (+244) points at the word holding its target.
	const uint64_t handleAddr = shardAddr + 240;
	const uint32_t targetRef = LOAD32((uint32_t)shardAddr + 244);

	bool killParticle = false;
	if (targetRef != 0) {
		const uint32_t target = LOAD32(targetRef);
		if (target == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			killParticle = (LOAD8(target + 0x90) & 0x40) != 0;
		}
	}

	if (killParticle) {
		ctx.r1.u64 = stack;
		// state the callee may pass on: the flag bit just tested
		const uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		const uint32_t entityAddr = (uint32_t)entity;
		result = entity;

		// Component 85: bit 21 of the mask word at +0x2C says the entity has one. The byte table at +0x8C,
		// when present, gives its index in the (type, component) pairs at +0x48..+0x4C; otherwise the
		// pairs are searched.
		if ((LOAD32(entityAddr + 0x2C) >> 21) & 1) {
			uint32_t particleComponent;
			const uint32_t indexTable = LOAD32(entityAddr + 0x8C);
			if (indexTable != 0) {
				const uint64_t pairAddr = (uint64_t)((uint32_t)LOAD8(indexTable + 0x55) << 3) + LOAD32(entityAddr + 0x48);
				particleComponent = LOAD32((uint32_t)pairAddr + 4);
				// r9 as the lookup leaves it: the call below receives it
				ctx.r9.u64 = pairAddr;
			} else {
				const uint32_t begin = LOAD32(entityAddr + 0x48);
				const uint32_t end = LOAD32(entityAddr + 0x4C);
				STORE32(stack + 80, 0u);
				STORE32(stack + 84, begin);
				const uint64_t byteCount = (uint64_t)end - begin;
				PPCXERRegister searchXer = callerXer;
				searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				int32_t count = (int32_t)byteCount >> 3;
				PPCCRRegister searchCr0{};
				searchCr0.compare<int32_t>(count, 0, searchXer);
				uint64_t searchR7 = ctx.r7.u64;
				uint64_t searchR8 = ctx.r8.u64;
				uint64_t searchR9 = byteCount;

				// lower_bound for type 85 (keys compare signed)
				uint32_t it = begin;
				if (count > 0) {
					// halving a positive count clears the carry
					searchXer.ca = 0;
					do {
						const int32_t half = count >> 1;
						const uint32_t step = (uint32_t)half << 3;
						const uint32_t mid = it + step;
						const bool below = (int32_t)LOAD32(mid) < 85;
						searchR7 = below ? 1 : 0;
						searchR8 = step;
						searchR9 = (uint64_t)(int64_t)half;
						if (below) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				// a missing type reads the pair at `end`
				if (it != end && (int32_t)LOAD32(it) <= 85) {
					particleComponent = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					particleComponent = LOAD32(end + 4);
				}

				// r6-r9, cr0 and xer.ca as the search leaves them: the call below receives them
				ctx.r6.u64 = end;
				ctx.r7.u64 = searchR7;
				ctx.r8.u64 = searchR8;
				ctx.r9.u64 = searchR9;
				ctx.cr0 = searchCr0;
				ctx.xer.ca = searchXer.ca;
			}
			ctx.fpscr.disableFlushMode();
			const double fadeOutTime = (double)LOAD_F32(0x8209B948u);
			result = n_sub_8247EB68(ctx, base, particleComponent, fadeOutTime);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B8098, 0x826B8098) { ctx.r3.u64 = CECShard_KillTrackedParticle(ctx, base, ctx.r3.u64); }

// sub_826B8618  [476 bytes]
uint32_t CECShard_UpdateTrail(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(45, 0x826B8618)) { ctx.r3.u64 = shardAddr; __imp__sub_826B8618(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B8618);
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);

	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	PPCVRegister vectorA{};
	PPCVRegister vectorB{};

	uint32_t result{};         // r3 as the second virtual call left it, or the last call's result
	uint32_t payload{};        // second word of the table entry that was located
	bool havePayload = false;  // set once an entry has been located
	uint64_t r5Value{};        // register values handed back to the caller
	uint64_t r6Value{};
	uint64_t r7Value{};
	uint64_t r8Value{};

	stack = PushStackFrame(base, stack, 160);
	uint32_t pairOut = stack + 80;
	uint32_t vecBufA = stack + 96;
	uint32_t vecBufB = stack + 112;

	// Slot +64 of the vtable of the object at owner+124, called once for each 16-byte buffer.
	uint32_t owner = shard->m_4;
	uint32_t subObject = LOAD32(owner + 124);
	uint32_t vtable = LOAD32(subObject);
	uint32_t fillFn = LOAD32(vtable + 64);
	callTarget.u64 = fillFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = vecBufA;
	ctx.r4.u64 = subObject;
	ctx.r9.u64 = fillFn;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t owner2 = shard->m_4;
	uint32_t subObject2 = LOAD32(owner2 + 124);
	uint32_t vtable2 = LOAD32(subObject2);
	uint32_t fillFn2 = LOAD32(vtable2 + 64);
	callTarget.u64 = fillFn2;
	ctx.r3.u64 = vecBufB;
	ctx.r4.u64 = subObject2;
	ctx.r6.u64 = fillFn2;
	ctx.r7.u64 = vtable2;
	ctx.r8.u64 = owner2;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	result = ctx.r3.u32;
	r6Value = ctx.r6.u64;
	r7Value = ctx.r7.u64;
	r8Value = ctx.r8.u64;
	flags.ca = ctx.xer.ca;

	// Locate the owner's entry whose key is 3.
	uint32_t entryOwner = shard->m_4;
	payload = 0;
	r5Value = LOAD32(entryOwner + 36);
	if (((r5Value >> 3) & 1) != 0) {
		havePayload = true;
		uint32_t indexTable = LOAD32(entryOwner + 140);
		if (indexTable != 0) {
			uint32_t entry = LOAD32(entryOwner + 72) + ((uint32_t)LOAD8(indexTable + 3) << 3);
			payload = LOAD32(entry + 4);
		} else {
			uint32_t first = LOAD32(entryOwner + 72);
			uint32_t last = LOAD32(entryOwner + 76);
			STORE32(pairOut, 0);
			uint32_t byteCount = (uint32_t)last - first;
			STORE32(pairOut + 4, first);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 7) != 0);
			int32_t count = (int32_t)byteCount >> 3;
			uint32_t cursor = first;
			if (count > 0) {
				// halving a positive count clears the carry
				flags.ca = 0;
				// lower_bound: first entry whose key is not less than 3 (keys compare signed)
				do {
					int32_t half = count >> 1;
					r8Value = (uint32_t)half << 3;
					uint32_t mid = cursor + (uint32_t)r8Value;
					bool below = (int32_t)LOAD32(mid) < 3;
					r7Value = below ? 1 : 0;
					if (below) {
						cursor = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(pairOut + 4, cursor);
			}
			// a missing key reads the entry at `last`
			uint32_t matchedEntry = last;
			if (cursor != last && (int32_t)LOAD32(cursor) <= 3) {
				matchedEntry = LOAD32(pairOut + 4);
			}
			payload = LOAD32(matchedEntry + 4);
		}
	}

	if (havePayload) {
		// r7, r8 and xer.ca as the search leaves them: state the callee may pass on
		ctx.xer.ca = flags.ca;
		uint32_t lookup = CECTroll_GetWeakSpotPosition(ctx, base, pairOut, payload, shardAddr + 20, 0);

		SET_V8(vectorA, VLOAD(lookup & ~0xF));
		uint32_t slotIndex = shard->m_120;
		VSTORE(vecBufA & ~0xF, V8(vectorA));

		// state the callee may pass on
		uint64_t lookup2 = CECTroll_GetWeakSpotPosition(ctx, base, pairOut, payload,
			(uint64_t)(slotIndex << 2) + (uint64_t)((int64_t)g_834A0000 - 20760), 0);

		// the object held by the shared handle at +280
		uint32_t heldObject = shard->m_118;
		SET_V8(vectorB, VLOAD((uint32_t)lookup2 & ~0xF));
		VSTORE(vecBufB & ~0xF, V8(vectorB));
		SET_V8(vectorA, VLOAD(vecBufA & ~0xF));
		// state the callee may pass on
		ctx.r4.u64 = vecBufA;
		ctx.r5.u64 = vecBufB;
		ctx.r6.u64 = lookup2;
		ctx.v1 = vectorA;
		ctx.v2 = vectorB;
		result = ParticleEmitter_SetTransform(ctx, base, heldObject);

		r5Value = ctx.r5.u64;
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		flags.ca = ctx.xer.ca;

		uint32_t slot = shard->m_120 + 1;
		shard->m_120 = slot;
		if ((int32_t)slot >= 9) {
			shard->m_120 = 0;
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r5-r8 and xer.ca after the call
	ctx.r5.u64 = r5Value;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(45, sub_826B8618, 0x826B8618) { ctx.r3.u64 = CECShard_UpdateTrail(ctx, base, ctx.r3.u64); }

uint64_t CECShard_KillSecondaryTrackedParticle(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	if (!UseLiftedCode(45, 0x826B8AA0)) { ctx.r3.u64 = shardAddr; __imp__sub_826B8AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B8AA0);
	uint32_t stack = ctx.r1.u64;
	// xer.so as the caller left it: the search below copies it into cr0
	const PPCXERRegister callerXer = ctx.xer;
	uint64_t result = shardAddr;
	stack = PushStackFrame(base, stack, 112);

	// The entity handle at +292: its second word (+296) points at the word holding its target.
	const uint64_t handleAddr = shardAddr + 292;
	const uint32_t targetRef = LOAD32((uint32_t)shardAddr + 296);

	bool killParticle = false;
	if (targetRef != 0) {
		const uint32_t target = LOAD32(targetRef);
		if (target == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			killParticle = (LOAD8(target + 0x90) & 0x40) != 0;
		}
	}

	if (killParticle) {
		ctx.r1.u64 = stack;
		// state the callee may pass on: the flag bit just tested
		const uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		const uint32_t entityAddr = (uint32_t)entity;
		result = entity;

		// Component 85: bit 21 of the mask word at +0x2C says the entity has one. The byte table at +0x8C,
		// when present, gives its index in the (type, component) pairs at +0x48..+0x4C; otherwise the
		// pairs are searched.
		if ((LOAD32(entityAddr + 0x2C) >> 21) & 1) {
			uint32_t particleComponent;
			const uint32_t indexTable = LOAD32(entityAddr + 0x8C);
			if (indexTable != 0) {
				const uint64_t pairAddr = (uint64_t)((uint32_t)LOAD8(indexTable + 0x55) << 3) + LOAD32(entityAddr + 0x48);
				particleComponent = LOAD32((uint32_t)pairAddr + 4);
				// r9 as the lookup leaves it: the call below receives it
				ctx.r9.u64 = pairAddr;
			} else {
				const uint32_t begin = LOAD32(entityAddr + 0x48);
				const uint32_t end = LOAD32(entityAddr + 0x4C);
				STORE32(stack + 80, 0u);
				STORE32(stack + 84, begin);
				const uint64_t byteCount = (uint64_t)end - begin;
				PPCXERRegister searchXer = callerXer;
				searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				int32_t count = (int32_t)byteCount >> 3;
				PPCCRRegister searchCr0{};
				searchCr0.compare<int32_t>(count, 0, searchXer);
				uint64_t searchR7 = ctx.r7.u64;
				uint64_t searchR8 = ctx.r8.u64;
				uint64_t searchR9 = byteCount;

				// lower_bound for type 85 (keys compare signed)
				uint32_t it = begin;
				if (count > 0) {
					// halving a positive count clears the carry
					searchXer.ca = 0;
					do {
						const int32_t half = count >> 1;
						const uint32_t step = (uint32_t)half << 3;
						const uint32_t mid = it + step;
						const bool below = (int32_t)LOAD32(mid) < 85;
						searchR7 = below ? 1 : 0;
						searchR8 = step;
						searchR9 = (uint64_t)(int64_t)half;
						if (below) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				// a missing type reads the pair at `end`
				if (it != end && (int32_t)LOAD32(it) <= 85) {
					particleComponent = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					particleComponent = LOAD32(end + 4);
				}

				// r6-r9, cr0 and xer.ca as the search leaves them: the call below receives them
				ctx.r6.u64 = end;
				ctx.r7.u64 = searchR7;
				ctx.r8.u64 = searchR8;
				ctx.r9.u64 = searchR9;
				ctx.cr0 = searchCr0;
				ctx.xer.ca = searchXer.ca;
			}
			ctx.fpscr.disableFlushMode();
			const double fadeOutTime = (double)LOAD_F32(0x820994C0u);
			result = n_sub_8247EB68(ctx, base, particleComponent, fadeOutTime);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B8AA0, 0x826B8AA0) { ctx.r3.u64 = CECShard_KillSecondaryTrackedParticle(ctx, base, ctx.r3.u64); }

// sub_826B8D48  [508 bytes]
uint64_t Shard_Release(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(45, 0x826B8D48)) { ctx.r3.u64 = shardAddr; __imp__sub_826B8D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826B8D48);
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	CECShard_KillSecondaryTrackedParticle(ctx, base, shardAddr);
	CECShard_KillTrackedParticle(ctx, base, shardAddr);
	Shard_UpdateVisualEffects(ctx, base, shardAddr);
	Shard_ReleaseEffectsAndSendBeamAttack(ctx, base, shardAddr);

	// m_118 is the first word of the shared handle at +280.
	uint64_t result = shard->m_118;
	const uint64_t sharedHandleAddr = shardAddr + 280;
	if (result != 0) {
		ctx.fpscr.disableFlushMode();
		n_sub_8322B820(ctx, base, result, (double)LOAD_F32((uint32_t)g_820994B4 - 392));
		result = SharedHandle_Release(ctx, base, sharedHandleAddr);
		STORE32((uint32_t)sharedHandleAddr, 0);
	}

	// The entity handle at +224: its second word (m_E4, +228) points at the word holding its target.
	const uint64_t handleAddr = shardAddr + 224;
	const uint32_t targetRef = shard->m_E4;
	if (targetRef != 0) {
		const uint32_t target = LOAD32(targetRef);
		if (target == 0) {
			// state the callee may pass on
			const uint64_t released = EntityHandle_Release(ctx, base, handleAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return released;
		}

		// state the callee may pass on
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);

		// Component 85: bit 21 of the mask word at +0x2C says the entity has one. The byte table at +0x8C,
		// when present, gives its index in the (type, component) pairs at +0x48..+0x4C; otherwise the
		// pairs are searched.
		if ((LOAD32(entity + 0x2C) >> 21) & 1) {
			uint32_t particleComponent;
			const uint32_t indexTable = LOAD32(entity + 0x8C);
			if (indexTable != 0) {
				const uint64_t pairAddr = (uint64_t)((uint32_t)LOAD8(indexTable + 0x55) << 3) + LOAD32(entity + 0x48);
				particleComponent = LOAD32((uint32_t)pairAddr + 4);
				// r9 as the lookup leaves it: the call below receives it
				ctx.r9.u64 = pairAddr;
			} else {
				const uint32_t begin = LOAD32(entity + 0x48);
				const uint32_t end = LOAD32(entity + 0x4C);
				STORE32(stack + 80, 0);
				const uint32_t byteCount = end - begin;
				STORE32(stack + 84, begin);
				bool carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				int32_t count = (int32_t)byteCount >> 3;
				uint64_t searchR7 = ctx.r7.u64;
				uint64_t searchR8 = ctx.r8.u64;
				uint64_t searchR9 = ctx.r9.u64;

				// lower_bound for type 85 (keys compare signed)
				uint32_t it = begin;
				if (count > 0) {
					// halving a positive count clears the carry
					carry = false;
					do {
						const int32_t half = count >> 1;
						const uint32_t step = (uint32_t)half << 3;
						const uint32_t mid = it + step;
						const bool below = (int32_t)LOAD32(mid) < 85;
						searchR7 = below ? 1 : 0;
						searchR8 = step;
						searchR9 = (uint64_t)(int64_t)half;
						if (below) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				// a missing type reads the pair at `end`
				if (it != end && (int32_t)LOAD32(it) <= 85) {
					particleComponent = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					particleComponent = LOAD32(end + 4);
				}

				// r6-r9 and xer.ca as the search leaves them: the call below receives them
				ctx.r6.u64 = end;
				ctx.r7.u64 = searchR7;
				ctx.r8.u64 = searchR8;
				ctx.r9.u64 = searchR9;
				ctx.xer.ca = carry;
			}
			ctx.fpscr.disableFlushMode();
			const double fadeOutTime = (double)LOAD_F32((uint32_t)g_820994B4);
			n_sub_8247EB68(ctx, base, particleComponent, fadeOutTime);
		}

		// A temporary handle at stack+80 with no target is assigned to the handle at +224.
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)g_820F1664);
		// state the callee may pass on
		EntityHandle_Release(ctx, base, stack + 80);
		EntityHandle_Assign(ctx, base, handleAddr, stack + 80);
		const uint32_t handleWord = (uint32_t)g_820F0000 + 5732;
		STORE32(stack + 80, handleWord);
		// state the callee may pass on
		result = EntityHandle_Release(ctx, base, stack + 80);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(45, sub_826B8D48, 0x826B8D48) { ctx.r3.u64 = Shard_Release(ctx, base, ctx.r3.u64); }

uint32_t Shard_ReleaseEffectsAndSendBeamAttack(CpuState& ctx, uint8_t* base, uint64_t shardAddr) {
	constexpr int32_t g_820A86F8 = int32_t(0x820A86F8);
	if (!UseLiftedCode(45, 0x826B9698)) { ctx.r3.u64 = shardAddr; __imp__sub_826B9698(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826B9698);
	uint32_t stack = ctx.r1.u64;
	CECShard* shard = GameObject<CECShard>(base, shardAddr);
	stack = PushStackFrame(base, stack, 192);

	// Release the four shared handles at +248..+272; the object each holds goes to Vector_DeletePointerElements first.
	uint32_t result = 0;
	bool carry = ctx.xer.ca;  // xer.ca: the loop counter's decrement sets it after every pass
	uint64_t handleSlot = shardAddr + 248;
	for (int i = 0; i < 4; ++i) {
		uint32_t heldObject = LOAD32((uint32_t)handleSlot);
		result = heldObject;
		if (heldObject != 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.xer.ca = carry;
			Vector_DeletePointerElements(ctx, base, heldObject);
			result = SharedHandle_Release(ctx, base, handleSlot);
			STORE32((uint32_t)handleSlot, 0);
		}
		carry = true;
		handleSlot += 8;
	}

	uint32_t manager = LOAD32(0x83496920u);
	uint32_t world = LOAD32(manager + 12);
	uint64_t r9Value = LOAD32(world + 284);  // r9 as it is left for callers
	if ((int32_t)r9Value == 1) {
		uint32_t controller = LOAD32(world + 140);
		r9Value = LOAD8(controller + 52);
		if (r9Value != 0 && LOAD8(controller + 53) != 0) {
			PPCVRegister zeroVec{};
			SET_V8(zeroVec, simde_mm_set1_epi32(int(0x0)));
			uint32_t owner = shard->m_4;

			// The message passed to the send call is built at stack+80.
			STORE32(stack + 80, (uint32_t)g_820A86F8);
			STORE32(stack + 128, 1);
			VSTORE((stack + 96) & ~0xF, V8(zeroVec));
			STORE32(stack + 132, 15u);
			VSTORE((stack + 112) & ~0xF, V8(zeroVec));
			STORE8(stack + 136, 0);

			uint32_t sender = LOAD32(LOAD32(manager + 12) + 140);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.xer.ca = carry;
			uint64_t uniqueId = Entity_GetUniqueId(ctx, base, owner);
			result = NetMessage_SendShardBeamAttack(ctx, base, sender, (uint64_t)stack + 80, uniqueId);
			r9Value = ctx.r9.u64;
			carry = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read r9 and xer.ca after the call
	ctx.r9.u64 = r9Value;
	ctx.xer.ca = carry;
	return result;
}
PROMOTED_ENTRY(45, sub_826B9698, 0x826B9698) { ctx.r3.u64 = Shard_ReleaseEffectsAndSendBeamAttack(ctx, base, ctx.r3.u64); }
