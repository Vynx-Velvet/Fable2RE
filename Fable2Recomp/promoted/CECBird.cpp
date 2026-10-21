// CECBird (vtable 0x82003690): methods of the class as readable C++.
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

uint64_t CECBird_OnDeath(CpuState& ctx, uint8_t* base, uint64_t birdAddr, uint64_t eventData) {
	if (!UseLiftedCode(3, 0x821C7E18)) { ctx.r3.u64 = birdAddr; ctx.r4.u64 = eventData; __imp__sub_821C7E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C7E18);
	uint32_t stack = ctx.r1.u64;
	uint32_t callTarget;
	uint64_t result;

	stack = PushStackFrame(base, stack, 96);
	callTarget = LOAD32(LOAD32((uint32_t)eventData) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = eventData;
	ctx.r4.u64 = eventData;
	ctx.r10.u64 = callTarget;
	REX_CALL_INDIRECT_FUNC(callTarget);
	result = ctx.r3.u64;
	if ((int32_t)result == 8 && LOAD8((uint32_t)birdAddr + 104) != 0) {
		result = CECBird_SpawnDeathEffects(ctx, base, birdAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(3, sub_821C7E18, 0x821C7E18) { ctx.r3.u64 = CECBird_OnDeath(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBird_Update(CpuState& ctx, uint8_t* base, uint64_t birdAddr) {
	if (!UseLiftedCode(3, 0x821D7E98)) { ctx.r3.u64 = birdAddr; __imp__sub_821D7E98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D7E98);
	uint32_t stack = ctx.r1.u64;
	uint64_t reg6Value = ctx.r6.u64;
	uint64_t reg7Value = ctx.r7.u64;
	bool carry = ctx.xer.ca;

	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	const uint32_t birdPtr = (uint32_t)birdAddr;
	stack = PushStackFrame(base, stack, 112);

	if (LOAD32(birdPtr + 16) == 2) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return birdAddr;
	}

	uint32_t statPtr = 0;
	uint32_t birdStats = bird->m_4;
	if ((LOAD32(birdStats + 36) >> 3) & 1) {
		uint32_t tablePtr = LOAD32(birdStats + 140);
		if (tablePtr != 0) {
			uint32_t index = LOAD8(tablePtr + 3);
			uint32_t start = LOAD32(birdStats + 72);
			statPtr = LOAD32(start + index * 8 + 4);
		} else {
			uint32_t begin = LOAD32(birdStats + 72);
			uint32_t end = LOAD32(birdStats + 76);
			reg6Value = end;
			STORE32(stack + 80, 0u);
			STORE32(stack + 84, begin);
			uint32_t low = begin;
			uint32_t span = end - begin;
			carry = ((int32_t)span < 0) & ((span & 7) != 0);
			int32_t count = (int32_t)span >> 3;
			if (count > 0) {
				// lower_bound over 8-byte entries comparing their first int against 3
				do {
					carry = ((int32_t)count < 0) & ((count & 1) != 0);
					int32_t half = count >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					low += halfBytes;
					if ((int32_t)LOAD32(low) < 3) {
						reg7Value = 1;
						count = count - half - 1;
						low += 8;
					} else {
						reg7Value = 0;
						low -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, low);
			}

			uint32_t elementPtr;
			if (low == end) {
				elementPtr = end;
			} else if ((int32_t)LOAD32(low) > 3) {
				elementPtr = end;
			} else {
				STORE64(stack + 80, LOAD64(stack + 80));
				elementPtr = LOAD32(stack + 84);
			}
			statPtr = LOAD32(elementPtr + 4);
		}
	}

	double distance = double(LOAD_F32(statPtr + 40));
	ctx.fpscr.disableFlushMode();
	ctx.r1.u64 = stack;
	ctx.r6.u64 = reg6Value;
	ctx.r7.u64 = reg7Value;
	ctx.xer.ca = carry;
	uint64_t result = CECBird_IsPlayerWithinDistance(ctx, base, birdPtr, distance);

	if ((result & 0xFF) != 0) {
		uint32_t state = bird->m_C;
		if (state == 0) {
			result = CECBird_UpdateWalkState(ctx, base, birdPtr);
		} else if (state == 1) {
			result = CECBird_UpdateIdle(ctx, base, birdPtr);
		} else if (state == 2) {
			result = CECBird_UpdateFlying(ctx, base, birdPtr);
		}
	}

	uint32_t state2 = bird->m_C;
	if (state2 == 3) {
		result = CECBird_UpdateGliding(ctx, base, birdPtr);
	} else if (state2 == 2) {
		result = CECBird_UpdateFlying(ctx, base, birdPtr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(3, sub_821D7E98, 0x821D7E98) { ctx.r3.u64 = CECBird_Update(ctx, base, ctx.r3.u64); }

uint64_t CECBird_IsPlayerWithinDistance(CpuState& ctx, uint8_t* base, uint32_t birdAddr, double maxDistance) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(4, 0x821EFF08)) { ctx.r3.u64 = birdAddr; ctx.f1.f64 = maxDistance; __imp__sub_821EFF08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821EFF08);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vecTarget{}, vecSelf{}, vecDiff{}, vecAbsMask{}, vecAbsDiff{}, vecDot{};
	PPCRegister callTarget{};
	double originalArg1 = maxDistance;
	uint64_t r4Out = ctx.r4.u64;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 144);

	// Entity the bird belongs to, reached through the global entity manager.
	uint32_t entityManager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t worldNode = LOAD32(LOAD32(entityManager + 12) + 88);
	uint32_t managerEntry = LOAD32(worldNode + 4);
	uint32_t owner = LOAD32(managerEntry);
	uint32_t ownerHandle = owner + 104;
	uint32_t trackerLink = LOAD32(owner + 108);

	uint32_t trackedEntity = 0;
	bool canMeasure = false;
	if (trackerLink != 0) {
		trackedEntity = LOAD32(trackerLink);
		if (trackedEntity == 0) {
			ctx.r1.u64 = stack;
			ctx.f1.f64 = maxDistance;
			EntityHandle_Release(ctx, base, ownerHandle);
			r4Out = ctx.r4.u64;
			maxDistance = ctx.f1.f64;
		} else if ((LOAD8(trackedEntity + 144) & 64) != 0) {
			canMeasure = true;
		}
	}

	uint32_t isWithinDistance = 0;
	if (canMeasure) {
		uint32_t selfPosition = stack + 80;
		uint32_t trackedPosition = stack + 96;

		uint32_t selfSource = LOAD32(uint32_t(bird->m_4) + 124);
		uint32_t selfVtable = LOAD32(selfSource);
		uint32_t selfGetter = LOAD32(selfVtable + 64);
		callTarget.u64 = (uint64_t)selfGetter;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = selfPosition;
		ctx.r4.u64 = selfSource;
		ctx.r8.u64 = managerEntry;
		ctx.r9.u64 = selfGetter;
		ctx.r10.u64 = selfVtable;
		ctx.f1.f64 = maxDistance;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		maxDistance = ctx.f1.f64;

		uint32_t trackedSource = LOAD32(trackedEntity + 124);
		uint32_t trackedVtable = LOAD32(trackedSource);
		uint32_t trackedGetter = LOAD32(trackedVtable + 64);
		callTarget.u64 = (uint64_t)trackedGetter;
		ctx.r3.u64 = trackedPosition;
		ctx.r4.u64 = trackedSource;
		ctx.r7.u64 = trackedGetter;
		ctx.r8.u64 = trackedVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		maxDistance = ctx.f1.f64;

		ctx.fpscr.disableFlushMode();
		double radiusSquared = double(float(originalArg1 * originalArg1));
		r4Out = (uint64_t)(int64_t)g_820A0000;

		// Squared distance between the two positions (lanes 1..3 of the vectors).
		uint32_t alignedTracked = trackedPosition & ~0xF;
		uint32_t alignedSelf = selfPosition & ~0xF;
		uint32_t absMaskAddr = uint32_t(g_820A0000 - 28336) & ~0xF;
		SET_V8(vecTarget, VLOAD(alignedTracked));
		SET_V8(vecSelf, VLOAD(alignedSelf));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(vecDiff, simde_mm_sub_ps(VF(vecTarget), VF(vecSelf)));
		SET_V8(vecAbsMask, VLOAD(absMaskAddr));
		SET_V8(vecAbsDiff, simde_mm_and_si128(V8(vecDiff), V8(vecAbsMask)));
		SET_VF(vecDot, simde_mm_dp_ps(VF(vecAbsDiff), VF(vecDiff), 0xEF));
		VSTORE(alignedTracked, V8(vecDot));

		isWithinDistance = 1;
		ctx.fpscr.disableFlushModeUnconditional();
		if (double(LOAD_F32(trackedPosition)) > radiusSquared) {
			isWithinDistance = 0;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.f1.f64 = maxDistance;
	return isWithinDistance;
}
PROMOTED_ENTRY(4, sub_821EFF08, 0x821EFF08) { ctx.r3.u64 = CECBird_IsPlayerWithinDistance(ctx, base, ctx.r3.u32, ctx.f1.f64); }

uint64_t CECBird_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameResult) {
	constexpr int32_t str_TXT_820C91DC_B_ = int32_t(0x820C91DC);
	if (!UseLiftedCode(69, 0x8299C520)) { ctx.r3.u64 = classNameResult; __imp__sub_8299C520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C520);
	uint32_t stack = ctx.r1.u64;
	const int32_t stringLength = -1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameResult, str_TXT_820C91DC_B_, stringLength);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameResult;
}
PROMOTED_ENTRY(69, sub_8299C520, 0x8299C520) { ctx.r3.u64 = CECBird_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECBird_ApplyDefinition(CpuState& ctx, uint8_t* base, uint64_t birdAddr, uint64_t definition) {
	constexpr int32_t str_TXT_82000EB4_B_ = int32_t(0x82000EB4);
	constexpr int32_t g_8209B650 = int32_t(0x8209B650);
	constexpr int32_t str_TXT_820EEE14_B_ = int32_t(0x820EEE14);
	constexpr int32_t str_TXT_820EEE28_B_ = int32_t(0x820EEE28);
	constexpr int32_t str_TXT_820EEE38_B_ = int32_t(0x820EEE38);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	if (!UseLiftedCode(69, 0x8299C988)) { ctx.r3.u64 = birdAddr; ctx.r4.u64 = definition; __imp__sub_8299C988(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299C988);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = birdAddr;
	uint64_t r4Value = definition;
	uint32_t birdBase = (uint32_t)birdAddr;
	uint64_t birdAddr2 = birdAddr;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 176);
	if ((uint32_t)definition != 0) {
		const uint64_t fnvBasis = 0xFFFFFFFF811C9DC5ULL;
		uint64_t typeString = str_TXT_82000EB4_B_;
		ctx.r1.u64 = stack;
		uint64_t typeHash = String_HashFnv1(ctx, base, typeString, fnvBasis);
		uint32_t fieldValue = GameDB_FindFieldValue(ctx, base, definition, typeHash, 2);
		if (fieldValue != 0) {
			bird->m_C = LOAD32(fieldValue);
		}
		uint64_t maxMovementRadiusString = str_TXT_820EEE14_B_;
		uint64_t maxMovementHash = String_HashFnv1(ctx, base, maxMovementRadiusString, fnvBasis);
		uint32_t maxMovementRadiusAddr = birdBase + 20;
		GameDB_ReadU32FieldByHash(ctx, base, definition, maxMovementHash, maxMovementRadiusAddr);
		uint64_t flyAwayRadiusString = str_TXT_820EEE28_B_;
		uint32_t flyAwayRadiusAddr = birdBase + 28;
		uint64_t flyAwayRadiusHash = String_HashFnv1(ctx, base, flyAwayRadiusString, fnvBasis);
		GameDB_ReadFloatFieldByHash(ctx, base, definition, flyAwayRadiusHash, flyAwayRadiusAddr);
		STORE32(stack + 80, 0);
		uint32_t globalBase = uint32_t(g_8209B650);
		const int32_t TXT_82100000_L_ = str_TXT_82100000_B_;
		ctx.fpscr.disableFlushMode();
		bird->m_20 = LOAD_F32(globalBase - 9036);
		uint64_t takeOffAngleString = str_TXT_820EEE38_B_;
		uint64_t takeOffAngleHash = String_HashFnv1(ctx, base, takeOffAngleString, fnvBasis);
		GameDB_ReadU32FieldByHash(ctx, base, definition, takeOffAngleHash, stack + 80);
		uint32_t takeOffAngleU32 = LOAD32(stack + 80);
		uint32_t v4 = bird->m_4;
		int32_t TXT_820EEE38_L_ = (int32_t)takeOffAngleU32;
		uint32_t local28 = stack + 96;
		STORE64(stack + 80, (uint64_t)(int64_t)TXT_820EEE38_L_);
		ctx.fpscr.disableFlushMode();
		PPCRegister local5{};
		local5.f64 = LOAD_F64(stack + 80);
		double takeOffAngleDouble = double(local5.s64);
		double takeOffAngleFloat = double(float(takeOffAngleDouble));
		double scale = double(LOAD_F32((uint32_t)TXT_82100000_L_ + 476));
		double turnAngle = double(float(takeOffAngleFloat * scale));
		bird->m_18 = float(turnAngle);
		uint32_t component = LOAD32(v4 + 124);
		uint32_t vtable = LOAD32(component);
		uint32_t callAddr = LOAD32(vtable + 64);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)callAddr;
		ctx.r3.u64 = local28;
		ctx.r4.u64 = component;
		ctx.r5.s64 = TXT_820EEE38_L_;
		ctx.r6.u64 = v4;
		ctx.r7.u64 = takeOffAngleU32;
		ctx.r8.s64 = TXT_82100000_L_;
		ctx.r10.u64 = callAddr;
		ctx.f10.f64 = turnAngle;
		ctx.f11.f64 = takeOffAngleFloat;
		ctx.f12.f64 = takeOffAngleDouble;
		ctx.f13 = local5;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4Value = ctx.r4.u64;
		uint32_t local47 = 48;
		uint32_t c = bird->m_C;
		PPCVRegister local58{};
		SET_V8(local58, VLOAD((stack + 96) & ~0xF));
		VSTORE(((uint32_t)birdAddr2 + local47) & ~0xF, V8(local58));
		if (c == 0) {
			uint32_t local29 = LOAD32((uint32_t)bird->m_4 + 124);
			uint32_t local51 = LOAD32(local29);
			uint32_t local48 = LOAD32(local51 + 92);
			callTarget.u64 = (uint64_t)local48;
			ctx.r3.u64 = local29;
			ctx.r7.u64 = c;
			ctx.r8.u64 = local47;
			ctx.r9.u64 = local48;
			ctx.r10.u64 = local51;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
			STORE32(stack + 80, 0);
			bool physicsFound = false;
			if ((uint32_t)result != 0) {
				uint32_t physicsOut = stack + 80;
				uint64_t entity = result;
				result = Entity_GetPhysicsComponent(ctx, base, entity, physicsOut);
				r4Value = ctx.r4.u64;
				physicsFound = ((uint32_t)(result & 0xFF) != 0);
			}
			if (!physicsFound) {
				bird->m_C = 1u;
			}
		}
		if ((int32_t)bird->m_C == 1) {
			ctx.fpscr.disableFlushMode();
			float TXT_820EEE28_L_ = LOAD_F32(flyAwayRadiusAddr);
			float defaultTXT_820EEE28_B_ = LOAD_F32(globalBase - 8604);
			if (TXT_820EEE28_L_ == defaultTXT_820EEE28_B_) {
				result = Vector_RemoveByValue(ctx, base, bird->m_4, birdAddr2);
				r4Value = ctx.r4.u64;
			}
		}
		uint32_t c2 = bird->m_C;
		if (c2 != 0) {
			if (c2 == 2) {
				ctx.fpscr.disableFlushMode();
				bird->m_64 = LOAD_F32(globalBase + 760);
				stack = PopStackFrame(stack, 176);
				ctx.r1.u64 = stack;
				return result;
			}
			if (c2 == 3) {
				ctx.fpscr.disableFlushMode();
				bird->m_64 = LOAD_F32(globalBase - 8580);
				stack = PopStackFrame(stack, 176);
				ctx.r1.u64 = stack;
				return result;
			}
		} else {
			ctx.fpscr.disableFlushMode();
			bird->m_64 = LOAD_F32(globalBase);
		}
	}
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(69, sub_8299C988, 0x8299C988) { ctx.r3.u64 = CECBird_ApplyDefinition(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBird_SetupSpline(CpuState& ctx, uint8_t* base, uint64_t birdAddr) {
	constexpr int32_t str_TXT_820D9104_B_ = int32_t(0x820D9104);
	constexpr int32_t str_TXT_820EEE58_B_ = int32_t(0x820EEE58);
	if (!UseLiftedCode(69, 0x8299CB90)) { ctx.r3.u64 = birdAddr; __imp__sub_8299CB90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299CB90);
	uint32_t stack = ctx.r1.u64;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	uint64_t result = 0;
	int32_t modeState = bird->m_C;

	if (modeState == 2 || modeState == 3) {
		uint32_t modeObj = bird->m_4;
		uint32_t modeValue = 0;
		bool hasModeValue = false;
		if ((LOAD32(modeObj + 36) >> 21) & 1) {
			uint32_t indexTable = LOAD32(modeObj + 140);
			if (indexTable != 0) {
				uint32_t slot = LOAD8(indexTable + 21);
				modeValue = LOAD32(LOAD32(modeObj + 72) + slot * 8 + 4);
			} else {
				uint32_t lo = LOAD32(modeObj + 72);
				uint32_t end = LOAD32(modeObj + 76);
				int32_t count = (int32_t)(end - lo) >> 3;
				while (count > 0) {
					int32_t half = count >> 1;
					uint32_t mid = lo + (uint32_t)half * 8;
					if ((int32_t)LOAD32(mid) < 21) {
						lo = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				}
				if (lo != end && (int32_t)LOAD32(lo) <= 21) {
					modeValue = LOAD32(lo + 4);
				} else {
					modeValue = LOAD32(end + 4);
				}
			}
			hasModeValue = true;
		}
		if (hasModeValue && (CECEntityModeManager_HasMode(ctx, base, modeValue, 32) & 0xFF) == 0) {
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820D9104_B_, -1);
			CECEntityModeManager_AddMode(ctx, base, modeValue, 32, stack + 80);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		}
	}

	uint32_t idObj = bird->m_4;
	STORE32(stack + 80, LOAD32(idObj + 28));
	STORE32(stack + 84, LOAD32(idObj + 32));
	uint64_t idRef = IdRef_Get(ctx, base, stack + 80);
	result = GameDB_ReadU32Field(ctx, base, idRef, 0xFFFFFFFF820EEE48ull);

	if ((uint32_t)result != 0) {
		uint64_t nameHash = String_HashFnv1(ctx, base, str_TXT_820EEE58_B_, 0xFFFFFFFF811C9DC5ull);
		uint64_t field = GameDB_FindFieldValue(ctx, base, result, nameHash, 6);
		result = field;
		uint32_t splineRef = (field != 0) ? LOAD32((uint32_t)field) : 0;
		if (splineRef != 0) {
			STORE32(stack + 84, splineRef);
			STORE32(stack + 80, 0);
			uint32_t manager = LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88);
			uint32_t subObj = LOAD32(manager + 4);
			uint32_t entityId = LOAD32(subObj);
			uint64_t splineEntity = EntityManager_LookupEntity(ctx, base, entityId, stack + 80);
			result = splineEntity;
			uint32_t splinePtr = (uint32_t)splineEntity;
			if (splinePtr != 0 &&
			    (LOAD8(splinePtr + 144) & 64) != 0 &&
			    ((LOAD32(splinePtr + 64) >> 14) & 1) != 0) {
				uint32_t handle = 0;
				uint32_t indexTable = LOAD32(splinePtr + 140);
				if (indexTable != 0) {
					uint32_t slot = LOAD8(indexTable + 238);
					handle = LOAD32(LOAD32(splinePtr + 72) + slot * 8 + 4);
				} else {
					uint32_t lo = LOAD32(splinePtr + 72);
					uint32_t end = LOAD32(splinePtr + 76);
					int32_t count = (int32_t)(end - lo) >> 3;
					while (count > 0) {
						int32_t half = count >> 1;
						uint32_t mid = lo + (uint32_t)half * 8;
						if ((int32_t)LOAD32(mid) < 238) {
							lo = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					}
					if (lo != end && (int32_t)LOAD32(lo) <= 238) {
						handle = LOAD32(lo + 4);
					} else {
						handle = LOAD32(end + 4);
					}
				}
				uint32_t handleObj = LOAD32(handle + 12);
				uint32_t handleRef = LOAD32(handle + 16);
				STORE32(stack + 80, handleObj);
				STORE32(stack + 84, handleRef);
				if (handleRef != 0) {
					STORE32(handleRef, LOAD32(handleRef) + 1);
				}
				uint32_t birdHandle = (uint32_t)birdAddr + 108;
				if (LOAD32((uint32_t)birdAddr + 112) != handleRef) {
					SharedHandle_Release(ctx, base, birdHandle);
					STORE32(birdHandle, handleObj);
					STORE32(birdHandle + 4, handleRef);
					if (handleRef != 0) {
						STORE32(handleRef, LOAD32(handleRef) + 1);
					}
				}
				SharedHandle_Release(ctx, base, stack + 80);
				uint32_t currentObj = LOAD32(birdHandle);
				result = Spline_GetLength(ctx, base, currentObj);
				double value = ctx.f1.f64;
				ctx.fpscr.disableFlushMode();
				bird->m_78 = (float)value;
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(69, sub_8299CB90, 0x8299CB90) { ctx.r3.u64 = CECBird_SetupSpline(ctx, base, ctx.r3.u64); }

uint64_t CECBird_UpdateIdle(CpuState& ctx, uint8_t* base, uint64_t birdAddr) {
	constexpr int32_t g_82005430 = int32_t(0x82005430);
	constexpr int32_t str_TXT_820AE654_B_ = int32_t(0x820AE654);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(69, 0x8299CF70)) { ctx.r3.u64 = birdAddr; __imp__sub_8299CF70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299CF70);
	uint32_t stack = ctx.r1.u64;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 272);

	const uint64_t entity = birdAddr;
	const uint32_t entityAddr = uint32_t(birdAddr);
	uint64_t result = birdAddr;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCRegister callTarget{};

	// Make sure the bird is initialised before anything else touches it.
	if (LOAD32(entityAddr + 16) != 1) {
		ctx.r1.u64 = stack;
		result = CECBird_Initialize(ctx, base, entity);
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
	}

	if (LOAD32(entityAddr + 16) == 1) {
		ctx.r1.u64 = stack;
		result = CECBird_TakeOff(ctx, base, entity);
		stack = PopStackFrame(stack, 272);
		ctx.r1.u64 = stack;
		return result;
	}

	if (int32_t(LOAD32(uint32_t(g_83320000) - 27380)) > int32_t(LOAD32(entityAddr + 88))) {
		const uint32_t owner = bird->m_4;
		uint32_t element = 0;
		uint64_t slot = 0;
		bool hasElement = false;

		if ((LOAD32(owner + 40) >> 17) & 1) {
			const uint32_t node = LOAD32(owner + 140);
			if (node != 0) {
				const uint32_t arrayBase = LOAD32(owner + 72);
				const uint32_t index = LOAD8(node + 49);
				slot = uint64_t(arrayBase) + uint64_t(uint32_t(index << 3));
				element = LOAD32(uint32_t(slot) + 4);
				hasElement = true;
			} else {
				// Lower bound search for the first entry whose key is >= 49.
				const uint32_t begin = LOAD32(owner + 72);
				reg8 = LOAD32(owner + 76);
				STORE32(stack + 80, 0);
				uint32_t cursor = begin;
				STORE32(stack + 84, cursor);
				int32_t count = (int32_t)(uint32_t(reg8) - begin) >> 3;
				if (count > 0) {
					do {
						const int32_t half = count >> 1;
						slot = uint64_t(int64_t(half));
						reg8 = uint64_t(uint32_t(half) << 3);
						cursor += uint32_t(reg8);
						reg7 = (int32_t(LOAD32(cursor)) < 49) ? 1 : 0;
						reg7 &= 0xFF;
						if (uint32_t(reg7) != 0) {
							count = count - half - 1;
							cursor += 8;
						} else {
							cursor -= uint32_t(reg8);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, cursor);
				}
				if (cursor != uint32_t(reg8)) {
					reg7 = (int32_t(LOAD32(cursor)) > 49) ? 1 : 0;
					reg7 &= 0xFF;
					if (uint32_t(reg7) != 0) {
						element = LOAD32(uint32_t(reg8) + 4);
					} else {
						STORE64(stack + 80, LOAD64(stack + 80));
						element = LOAD32(LOAD32(stack + 84) + 4);
					}
				} else {
					element = LOAD32(uint32_t(reg8) + 4);
				}
				hasElement = true;
			}
		}

		if (hasElement) {
			const uint32_t handler = LOAD32(LOAD32(element) + 88);
			callTarget.u64 = uint64_t(handler);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = element;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = slot;
			ctx.r10.u64 = uint64_t(handler);
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;

			if ((uint32_t(result) & 0xFF) == 0) {
				// Behaviour finished: schedule the next idle evaluation.
				const int32_t currentTime = int32_t(LOAD32(uint32_t(g_83320000) - 27380));
				STORE64(stack + 80, uint64_t(int64_t(currentTime)));
				ctx.fpscr.disableFlushMode();
				const double now = double(int64_t(currentTime));
				const double rate = LOAD_F64(0x83319510u);
				const double span = LOAD_F64(0x82100A10u);
				double nextTime = std::fma(rate, span, now);
				const int32_t nextTimeInt = std::isnan(nextTime)
					? int32_t(0x80000000)
					: (nextTime > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&nextTime)));
				bird->m_58 = nextTimeInt;
				ctx.f10.s64 = int64_t(nextTimeInt);
				ctx.f11.f64 = nextTime;
				ctx.f12.f64 = now;
				ctx.f13.f64 = span;

				const uint64_t idleString = uint64_t(int64_t(str_TXT_820AE654_B_));
				CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, idleString, -1);
				C_820F0D08_Construct(ctx, base, uint64_t(stack) + 112, 1, uint64_t(stack) + 80, 0);

				STORE32(stack + 112, uint32_t(g_82005430));
				const uint32_t action = LOAD32(LOAD32(element) + 64);
				callTarget.u64 = uint64_t(action);
				ctx.r3.u64 = uint64_t(stack) + 88;
				ctx.r4.u64 = element;
				ctx.r5.u64 = uint64_t(stack) + 112;
				ctx.r6.u64 = 0;
				ctx.r10.u64 = uint64_t(action);
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				STORE32(stack + 88, uint32_t(g_820F0000) + 5732);
				EntityHandle_Release(ctx, base, uint64_t(stack) + 88);
				STORE32(stack + 92, 0);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 196);
				HandleHolder_Dtor(ctx, base, uint64_t(stack) + 112);
				result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, uint64_t(stack) + 80);
			}
		}
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(69, sub_8299CF70, 0x8299CF70) { ctx.r3.u64 = CECBird_UpdateIdle(ctx, base, ctx.r3.u64); }

uint64_t CECBird_TakeOff(CpuState& ctx, uint8_t* base, uint64_t birdAddr) {
	constexpr int32_t str_TXT_820C8324_B_ = int32_t(0x820C8324);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr uint32_t counterAddr = uint32_t(g_83490000) + 28344;  // 0x83496EB8
	if (!UseLiftedCode(69, 0x8299D4F8)) { ctx.r3.u64 = birdAddr; __imp__sub_8299D4F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299D4F8);
	uint32_t stack = ctx.r1.u64;
	uint32_t stackReg = ctx.r13.u64;
	PPCXERRegister flags = ctx.xer;
	PPCCRRegister compare0{};
	uint64_t lockState{};
	uint64_t lockValue{};

	CECBird* bird = GameObject<CECBird>(base, birdAddr);

	// Values the original keeps in the register file across the virtual calls.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;

	uint32_t foundEntity = 0;
	uint32_t hasEntity = 0;

	stack = PushStackFrame(base, stack, 272);

	uint32_t component = bird->m_4;
	reg9 = (LOAD32(component + 0x28) >> 17) & 1;
	if ((uint32_t)reg9 != 0) {
		uint32_t indexHolder = LOAD32(component + 0x8C);
		if (indexHolder != 0) {
			uint32_t index = LOAD8(indexHolder + 0x31);
			uint32_t beginPtr = LOAD32(component + 0x48);
			reg9 = (uint32_t)(index << 3) + beginPtr;
			hasEntity = 1;
			foundEntity = LOAD32((uint32_t)reg9 + 4);
		} else {
			uint32_t beginPtr = LOAD32(component + 0x48);
			uint32_t endPtr = LOAD32(component + 0x4C);
			reg6 = endPtr;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, beginPtr);
			int32_t remaining = ((int32_t)(endPtr - beginPtr)) >> 3;
			if (remaining > 0) {
				// lower_bound of key 49 over the sorted {key, pointer} table
				do {
					uint32_t half = (uint32_t)(remaining >> 1);
					reg9 = half;
					reg8 = (uint64_t)(half << 3);
					uint32_t mid = (uint32_t)reg8 + beginPtr;
					reg7 = ((int32_t)LOAD32(mid) < 49) ? 1 : 0;
					if ((uint32_t)reg7 != 0) {
						remaining = remaining - (int32_t)half - 1;
						beginPtr = mid + 8;
					} else {
						beginPtr = mid - (uint32_t)reg8;
						remaining = (int32_t)half;
					}
				} while (remaining > 0);
				STORE32(stack + 84, beginPtr);
			}

			if (beginPtr != endPtr && (int32_t)LOAD32(beginPtr) <= 49) {
				STORE64(stack + 80, LOAD64(stack + 80));
				foundEntity = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				foundEntity = LOAD32(endPtr + 4);
			}
			hasEntity = 1;
		}
	}

	if (hasEntity != 0) {
		if (bird->m_10 != 2) {
			uint32_t entity = foundEntity;
			uint32_t canTakeOffFn = LOAD32(LOAD32(entity) + 88);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = entity;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = canTakeOffFn;
			REX_CALL_INDIRECT_FUNC(canTakeOffFn);
			uint32_t canFlag = ctx.r3.u32 & 0xFF;
			if (canFlag != 0) {
				uint32_t takeOffFn = LOAD32(LOAD32(entity) + 72);
				ctx.r3.u64 = entity;
				ctx.r9.u64 = canFlag;
				ctx.r10.u64 = takeOffFn;
				REX_CALL_INDIRECT_FUNC(takeOffFn);
			}

			CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint32_t)str_TXT_820C8324_B_, -1);
			C_820F0D08_Construct(ctx, base, stack + 112, 1, stack + 80, 0);

			STORE32(stack + 232, 0);
			STORE32(stack + 112, 0x820EEE80u);
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				lockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = stackReg & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
				lockValue = __builtin_bswap32(ctx.reserved.u32);
				lockValue = (int64_t)lockValue + 1;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(counterAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)lockValue));
				compare0.so = flags.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)lockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);

			uint32_t spawnFn = LOAD32(LOAD32(entity) + 64);
			ctx.r3.u64 = stack + 88;
			ctx.r4.u64 = entity;
			ctx.r5.u64 = stack + 112;
			ctx.r6.u64 = 0;
			ctx.r7.s64 = g_83490000;
			ctx.r8.u64 = lockState;
			ctx.r9.u64 = lockValue;
			ctx.r10.u64 = spawnFn;
			REX_CALL_INDIRECT_FUNC(spawnFn);

			uint32_t gcBase = uint32_t(g_820F0000);
			uint32_t handleVtbl = (int32_t)gcBase + 5732;
			STORE32(stack + 88, handleVtbl);
			EntityHandle_Release(ctx, base, stack + 88);

			STORE32(stack + 92, 0);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 232);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 196);
			HandleHolder_Dtor(ctx, base, stack + 112);
			birdAddr = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			bird->m_10 = 2u;
		}
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return birdAddr;
}
PROMOTED_ENTRY(69, sub_8299D4F8, 0x8299D4F8) { ctx.r3.u64 = CECBird_TakeOff(ctx, base, ctx.r3.u64); }

uint64_t CECBird_UpdateFlightPosition(CpuState& ctx, uint8_t* base, uint32_t birdAddr) {
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	if (!UseLiftedCode(69, 0x8299D720)) { ctx.r3.u64 = birdAddr; __imp__sub_8299D720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299D720);
	uint32_t stack = ctx.r1.u64;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 176);
	uint32_t frameBase = stack;

	int32_t field14 = bird->m_14;
	uint32_t divisor = (uint32_t)(field14 / 2);

	uint32_t rngGlobal = LOAD32(0x83496920u);
	uint32_t rngA = LOAD32(rngGlobal + 12);
	uint32_t rngB = LOAD32(rngA + 88);
	uint32_t rngObj = LOAD32(rngB + 4);

	uint32_t rngValue = LOAD32(rngObj + 120);
	uint64_t newRng = __builtin_rotateleft32((uint32_t)((uint64_t)rngValue * 9377u + 9439u), 19);
	STORE32(rngObj + 120, (uint32_t)newRng);

	uint64_t remainder = 0;
	if (divisor != 0) {
		uint32_t quotient = (uint32_t)newRng / divisor;
		remainder = newRng - (uint64_t)((int64_t)(int32_t)quotient * (int64_t)(int32_t)divisor);
	}

	STORE64(stack + 96, remainder & 0xFFFFFFFF);
	ctx.fpscr.disableFlushMode();
	STORE64(stack + 96, (uint64_t)(int64_t)field14);
	double field14Scaled = (double)(float)field14;
	double remainderScaled = (double)(float)(uint32_t)remainder;
	double radiusFactor = (double)LOAD_F32(0x82099334u);
	double radius = (double)(float)std::fma(field14Scaled, radiusFactor, remainderScaled);

	uint32_t rngStateAddr = rngObj + 120;
	double rngMax = (double)LOAD_F32(0x8209F78Cu);
	ctx.r1.u64 = stack;
	double rngScaled = Rng_NextScaledFloat(ctx, base, rngStateAddr, rngMax);

	ctx.fpscr.disableFlushMode();
	double angleIncrement = (double)(float)(rngScaled + (double)LOAD_F32(0x8209BE4Cu));
	double prevAngle = (double)bird->m_60;
	double twoPi = (double)LOAD_F32(0x8209DA24u);
	double newAngle = (double)(float)(angleIncrement + prevAngle);
	if (!(newAngle < twoPi)) {
		newAngle = (double)(float)(newAngle - twoPi);
	}
	ctx.fpscr.disableFlushMode();
	bird->m_60 = (float)newAngle;

	double angleScale = (double)LOAD_F32(0x821001DCu);
	double scaledAngle = (double)(float)(newAngle * angleScale);

	uint32_t copySrc = birdAddr + 48;
	PPCVRegister vec40{}, vec41{}, vec42{}, vec43{}, vec44{}, vec45{}, vec46{};
	uint32_t shuffleAddr;

	SET_V8(vec40, VLOAD(copySrc & ~0xF));
	VSTORE((stack + 96) & ~0xF, V8(vec40));

	ctx.r1.u64 = stack;
	double sinApprox = Math_SinApprox(ctx, base, scaledAngle);
	ctx.fpscr.disableFlushMode();
	double birdX = (double)LOAD_F32(stack + 96);

	SET_V8(vec46, VLOAD(copySrc & ~0xF));
	VSTORE((stack + 112) & ~0xF, V8(vec46));

	double y = (double)(float)std::fma((double)(float)sinApprox, radius, birdX);
	STORE_F32(stack + 80, (float)y);

	ctx.r1.u64 = stack;
	double sinResult = Math_Sin(ctx, base, scaledAngle);
	ctx.fpscr.disableFlushMode();
	double birdY = (double)LOAD_F32(stack + 116);

	double fixedValue = (double)LOAD_F32((uint32_t)g_820994B4);
	STORE_F32(stack + 96, (float)fixedValue);

	SET_V8(vec45, VLOAD(copySrc & ~0xF));
	shuffleAddr = stack + 96;
	SET_V8(vec43, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(shuffleAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(shuffleAddr & 0xF) * 16])));
	VSTORE((stack + 112) & ~0xF, V8(vec45));

	shuffleAddr = stack + 80;
	SET_V8(vec44, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(shuffleAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(shuffleAddr & 0xF) * 16])));

	double x = (double)(float)std::fma((double)(float)sinResult, radius, birdY);
	STORE_F32(stack + 96, (float)x);

	shuffleAddr = stack + 96;
	SET_V8(vec42, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(shuffleAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(shuffleAddr & 0xF) * 16])));
	shuffleAddr = stack + 120;
	SET_V8(vec41, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(shuffleAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(shuffleAddr & 0xF) * 16])));

	SET_VF(vec41, simde_mm_blend_ps(VF(vec41), simde_mm_permute_ps(VF(vec43), 57), 4));
	SET_VF(vec44, simde_mm_blend_ps(VF(vec44), simde_mm_permute_ps(VF(vec42), 57), 4));
	SET_VF(vec44, simde_mm_blend_ps(VF(vec44), simde_mm_permute_ps(VF(vec41), 78), 3));
	VSTORE((birdAddr + 64) & ~0xF, V8(vec44));

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r5.u64 = frameBase + 96;
	ctx.r6.u64 = frameBase + 112;
	ctx.r7.u64 = frameBase + 80;
	ctx.r8.u64 = frameBase + 96;
	ctx.f1.f64 = sinResult;
	ctx.f9.f64 = (double)(float)x;
	ctx.f10.f64 = birdY;
	ctx.f11.f64 = (double)(float)sinResult;
	return 64;
}
PROMOTED_ENTRY(69, sub_8299D720, 0x8299D720) { ctx.r3.u64 = CECBird_UpdateFlightPosition(ctx, base, ctx.r3.u32); }

uint64_t CECBird_SpawnDeathEffects(CpuState& ctx, uint8_t* base, uint32_t birdAddr) {
	constexpr int32_t str_TXT_820ECB54_B_ = int32_t(0x820ECB54);
	constexpr int32_t str_TXT_820ECB5C_B_ = int32_t(0x820ECB5C);
	constexpr int32_t str_TXT_820EEE6C_B_ = int32_t(0x820EEE6C);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t TXT_8349B390_G_ = int32_t(0x8349B390);
	if (!UseLiftedCode(69, 0x8299D8B0)) { ctx.r3.u64 = birdAddr; __imp__sub_8299D8B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8299D8B0);
	uint32_t stack = ctx.r1.u64;
	CECBird* bird = GameObject<CECBird>(base, birdAddr);
	stack = PushStackFrame(base, stack, 144);

	PPCRegister callTarget{};
	PPCVRegister vec{};

	// Virtual call: fills the 16-byte matrix at stack+112 from the bird's attachment.
	uint32_t attachment = LOAD32(uint32_t(bird->m_4) + 124);
	uint32_t vtable = LOAD32(attachment);
	callTarget.u64 = LOAD32(vtable + 64);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = stack + 112;
	ctx.r4.u64 = attachment;
	ctx.r9.u64 = callTarget.u64;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint64_t reg6 = ctx.r6.u64;
	uint32_t attachmentData = bird->m_4;
	uint32_t boneValue = 0;
	uint64_t reg8 = LOAD32(attachmentData + 36);
	bool haveBone = false;
	if ((reg8 >> 3) & 1) {
		uint32_t explicitIndex = LOAD32(attachmentData + 140);
		if (explicitIndex != 0) {
			uint32_t index = __builtin_rotateleft32(LOAD8(explicitIndex + 3), 3);
			uint32_t bones = LOAD32(attachmentData + 72);
			boneValue = LOAD32(bones + index + 4);
			haveBone = true;
		} else {
			uint32_t bones = LOAD32(attachmentData + 72);
			uint32_t bonesEnd = LOAD32(attachmentData + 76);
			reg6 = bonesEnd;
			STORE32(stack + 96, 0);
			STORE32(stack + 100, bones);
			int32_t count = (int32_t)(bonesEnd - bones) >> 3;
			uint32_t first = bones;
			// Lower bound of the first bone whose id is >= 3.
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t offset = uint32_t(half) << 3;
					reg8 = offset;
					uint32_t mid = first + offset;
					if ((int32_t)LOAD32(mid) < 3) {
						count = count - half - 1;
						first = mid + 8;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 100, first);
			}
			if (first != bonesEnd && (int32_t)LOAD32(first) <= 3) {
				STORE64(stack + 96, LOAD64(stack + 96));
				boneValue = LOAD32(LOAD32(stack + 100) + 4);
			} else {
				boneValue = LOAD32(bonesEnd + 4);
			}
			haveBone = true;
		}
	}

	if (haveBone) {
		uint64_t shadowHipBone = TXT_8349B390_G_;
		uint32_t placement = CECTroll_GetWeakSpotPosition(ctx, base, stack + 96, boneValue, shadowHipBone, 0);
		reg6 = ctx.r6.u64;
		reg8 = ctx.r8.u64;
		SET_V8(vec, VLOAD(placement & ~0xF));
		VSTORE((stack + 112) & ~0xF, V8(vec));
	}

	ctx.r6.u64 = reg6;

	uint64_t bloodName = str_TXT_820ECB54_B_;
	CCharString_ConstructFromCStr(ctx, base, stack + 96, bloodName, -1);

	uint64_t splatEffect = str_TXT_820ECB5C_B_;
	CCharString_ConstructFromCStr(ctx, base, stack + 80, splatEffect, -1);

	SET_V8(vec, VLOAD((stack + 112) & ~0xF));
	ctx.v1 = vec;
	Entity_CreateFromNamedDefinition(ctx, base, stack + 80, stack + 96, 0xFFFFFFFF);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 96);

	uint64_t unnamedName = (int64_t)g_820F0000 - 4512;
	CCharString_ConstructFromCStr(ctx, base, stack + 80, unnamedName, -1);

	uint64_t featherEffect = str_TXT_820EEE6C_B_;
	CCharString_ConstructFromCStr(ctx, base, stack + 96, featherEffect, -1);

	SET_V8(vec, VLOAD((stack + 112) & ~0xF));
	ctx.v1 = vec;
	Entity_CreateFromNamedDefinition(ctx, base, stack + 96, stack + 80, 0xFFFFFFFF);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 96);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(69, sub_8299D8B0, 0x8299D8B0) { ctx.r3.u64 = CECBird_SpawnDeathEffects(ctx, base, ctx.r3.u32); }
