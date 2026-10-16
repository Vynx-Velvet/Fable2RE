// CECNavigation (vtable 0x82004860): methods of the class as readable C++.
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

uint32_t CECNavigation_IsActive(CpuState& ctx, uint8_t* base, uint32_t navigationAddr) {
	if (!UseLiftedCode(0, 0x821729A0)) { ctx.r3.u64 = navigationAddr; __imp__sub_821729A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821729A0);
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	if (navigation->m_B0 == 0) return 0;

	uint32_t entity = navigation->m_4;
	const uint32_t entityFlag48Bit1 = (LOAD32(entity + 48) >> 1) & 1;
	// callers read r9 after the call: it holds this bit on every return below
	ctx.r9.u64 = entityFlag48Bit1;
	if (entityFlag48Bit1 != 0) return 0;
	if (((LOAD32(entity + 56) >> 2) & 1) != 0) return 0;

	uint32_t mode = navigation->m_AC;
	if (mode == 3 || mode == 4 || mode == 5 || mode == 6) return 1;
	return 0;
}
PROMOTED_ENTRY(0, sub_821729A0, 0x821729A0) { ctx.r3.u64 = CECNavigation_IsActive(ctx, base, ctx.r3.u32); }

// Level 2 takes m_E8 as is; higher levels add (m_EC - m_E8) * (level - 2) * k1 to it, lower levels
// scale it by level * k0 (k0, k1 are game globals).
void CECNavigation_SetSpeed(CpuState& ctx, uint8_t* base, uint32_t navigationAddr, uint32_t speedLevel) {
	constexpr int32_t g_82099334 = int32_t(0x82099334);
	if (!UseLiftedCode(0, 0x82175F80)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = speedLevel; __imp__sub_82175F80(ctx, base); return; }
	LiftedFrame frame(0x82175F80);
	uint32_t stack = ctx.r1.u32;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	const int32_t level = (int32_t)speedLevel;
	ctx.fpscr.disableFlushMode();
	if (level > 2) {
		const double baseSpeed = double(navigation->m_E8);
		const double upperSpeed = double(navigation->m_EC);
		const int32_t levelsAboveTwo = level - 2;
		// the integer goes to floating point through this stack slot
		STORE64(stack - 16, (uint64_t)(int64_t)levelsAboveTwo);
		const double range = double(float(upperSpeed - baseSpeed));
		const double steps = double(float(double(levelsAboveTwo)));
		const double stepFactor = double(LOAD_F32(uint32_t(g_82099334) + 10092));
		navigation->m_F0 = float(std::fma(double(float(range * steps)), stepFactor, baseSpeed));
		// callers read these registers after the call
		ctx.r8.s64 = g_82099334;
		ctx.r9.s64 = levelsAboveTwo;
		ctx.f12.f64 = upperSpeed;
		ctx.f13.f64 = baseSpeed;
		return;
	}
	if (level < 2) {
		const double baseSpeed = double(navigation->m_E8);
		// the integer goes to floating point through this stack slot
		STORE64(stack - 16, (uint64_t)(int64_t)level);
		const double steps = double(float(double(level)));
		const double scale = double(LOAD_F32(uint32_t(g_82099334)));
		const float product = float(baseSpeed * steps);
		navigation->m_F0 = float(double(product) * scale);
		// callers read these registers after the call; f12 holds the level's 64-bit integer bits
		ctx.f12.s64 = level;
		ctx.f13.f64 = baseSpeed;
		return;
	}
	navigation->m_F0 = navigation->m_E8;
}
PROMOTED_ENTRY(0, sub_82175F80, 0x82175F80) { CECNavigation_SetSpeed(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_821E7D58(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t queryKind, uint32_t skipTargetEntity, double floatArg1) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83499170 = int32_t(0x83499170);
	if (!UseLiftedCode(4, 0x821E7D58)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = queryKind; ctx.r5.u64 = skipTargetEntity; ctx.f1.f64 = floatArg1; __imp__sub_821E7D58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E7D58);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 160);
	const uint64_t facingPointAddr = uint64_t(stack) + 96;
	const uint64_t entityPointAddr = uint64_t(stack) + 80;
	ctx.r1.u64 = stack;
	const uint64_t facingResult = CECNavigation_ComputeFacingTargetPoint(ctx, base, navigationAddr, facingPointAddr, queryKind);
	if ((facingResult & 0xFF) == 0) {
		ctx.fpscr.disableFlushMode();
		const double fallbackDistance = double(LOAD_F32(0x8209DE04u));
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		// callers read r4, r5 and f1 after the call
		ctx.r4.u64 = facingPointAddr;
		ctx.r5.u64 = queryKind;
		ctx.f1.f64 = fallbackDistance;
		return facingResult;
	}

	// the m_4 entity's component at +124 writes a point into the frame through its vtable slot +64
	const uint32_t entityComponent = LOAD32(uint32_t(navigation->m_4) + 124);
	const uint32_t entityComponentVtable = LOAD32(entityComponent);
	const uint32_t getPointFn = LOAD32(entityComponentVtable + 64);
	callTarget.u64 = getPointFn;
	ctx.r3.u64 = entityPointAddr;
	ctx.r4.u64 = entityComponent;
	ctx.r5.u64 = queryKind;
	ctx.r9.u64 = getPointFn;
	ctx.r10.u64 = entityComponentVtable;
	ctx.f1.f64 = floatArg1;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// distance between the facing point and the entity's point, over the components the mask keeps
	const uint64_t maskAddr = uint64_t(int64_t(g_820A0000) - 28336);
	PPCVRegister facingPoint{};
	PPCVRegister entityPoint{};
	PPCVRegister difference{};
	PPCVRegister mask{};
	PPCVRegister maskedDifference{};
	PPCVRegister lengthSquared{};
	SET_V8(facingPoint, VLOAD((uint32_t)facingPointAddr & ~0xF));
	SET_V8(entityPoint, VLOAD((uint32_t)entityPointAddr & ~0xF));
	ctx.fpscr.enableFlushMode();
	SET_VF(difference, simde_mm_sub_ps(VF(facingPoint), VF(entityPoint)));
	SET_V8(mask, VLOAD((uint32_t)maskAddr & ~0xF));
	SET_V8(maskedDifference, simde_mm_and_si128(V8(difference), V8(mask)));
	SET_VF(lengthSquared, simde_mm_dp_ps(VF(maskedDifference), VF(difference), 0xEF));
	VSTORE((uint32_t)facingPointAddr & ~0xF, V8(lengthSquared));
	ctx.fpscr.disableFlushModeUnconditional();
	double distance = double(float(sqrt(double(LOAD_F32(stack + 96)))));

	// state the callee may pass on
	ctx.r6.s64 = g_820A0000;
	ctx.r7.u64 = facingPointAddr;
	ctx.r8.u64 = entityPointAddr;
	uint64_t result = CECNavigation_GetNavigationData(ctx, base, (uint32_t)navigationAddr);

	// From here on v9-v13 hold these vectors: every later call is handed them and returns them, and
	// callers read them after the call.
	ctx.v9 = lengthSquared;
	ctx.v10 = maskedDifference;
	ctx.v11 = difference;
	ctx.v12 = entityPoint;
	ctx.v13 = facingPoint;

	if ((uint32_t)result != 0) {
		// state the callee may pass on
		ctx.r5.u64 = facingPointAddr;
		result = CMoveGraphController_FindChildBByType(ctx, base, LOAD32((uint32_t)result + 24), g_83499170);
		if ((uint32_t)result != 0) {
			// the child's vtable slot +68 replaces the distance
			const uint32_t childFn = LOAD32(LOAD32((uint32_t)result) + 68);
			callTarget.u64 = childFn;
			ctx.r3.u64 = result;
			ctx.r10.u64 = childFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			ctx.fpscr.disableFlushMode();
			distance = ctx.f1.f64;
		}
	} else {
		// what the original leaves in r4 and r5 on this path; r5 is also passed on to EntityHandle_IsValid
		ctx.r4.u64 = maskAddr;
		ctx.r5.u64 = facingPointAddr;
	}

	if ((skipTargetEntity & 0xFF) == 0) {
		const uint64_t targetHandleAddr = navigationAddr + 128;
		// state the callee may pass on (r5 already holds what the original passes)
		ctx.r4.u64 = 0;
		result = EntityHandle_IsValid(ctx, base, targetHandleAddr);
		if ((result & 0xFF) != 0) {
			const int32_t navigationState = (int32_t)(uint32_t)navigation->m_AC;
			// The original also compares two vectors here when (queryKind | 1) == 0, which is never
			// true, so that branch is left out.
			if (navigationState != 6 && navigationState != 2) {
				// state the callee may pass on: r7-r9 still hold what EntityHandle_IsValid left,
				// and of r10 the original passes only the low word
				ctx.r10.u64 = ctx.r10.u32;
				const uint32_t targetEntity = EntityHandle_Get_825575C8(ctx, base, targetHandleAddr);
				const uint32_t targetComponent = LOAD32(targetEntity + 124);

				// subtract what both components return from their vtable slot +72
				const uint32_t navComponent = LOAD32(uint32_t(navigation->m_4) + 124);
				const uint32_t navComponentVtable = LOAD32(navComponent);
				const uint32_t navExtentFn = LOAD32(navComponentVtable + 72);
				callTarget.u64 = navExtentFn;
				ctx.r3.u64 = navComponent;
				ctx.r9.u64 = navExtentFn;
				ctx.r10.u64 = navComponentVtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				const uint32_t targetComponentVtable = LOAD32(targetComponent);
				ctx.fpscr.disableFlushMode();
				const double navExtent = ctx.f1.f64;
				const uint32_t targetExtentFn = LOAD32(targetComponentVtable + 72);
				callTarget.u64 = targetExtentFn;
				ctx.r3.u64 = targetComponent;
				ctx.r7.u64 = targetExtentFn;
				ctx.r8.u64 = targetComponentVtable;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;
				ctx.fpscr.disableFlushMode();
				const double extentSum = double(float(navExtent + ctx.f1.f64));
				distance = double(float(distance - extentSum));
			}
		}
	}

	ctx.fpscr.disableFlushMode();
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read f1 after the call; r4-r9 and v9-v13 already hold what the original leaves there
	ctx.f1.f64 = distance;
	return result;
}
PROMOTED_ENTRY(4, sub_821E7D58, 0x821E7D58) { ctx.r3.u64 = n_sub_821E7D58(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.f1.f64); }

uint64_t CECNavigation_GetNavigationData(CpuState& ctx, uint8_t* base, uint32_t navigationAddr) {
	if (!UseLiftedCode(4, 0x821E8750)) { ctx.r3.u64 = navigationAddr; __imp__sub_821E8750(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E8750);
	uint32_t stack = ctx.r1.u32;
	constexpr int32_t key = 59;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	const uint32_t entity = navigation->m_4;

	if (((LOAD32(entity + 40) >> 27) & 1) == 0) {
		// callers read r9 and r10 after the call
		ctx.r9.u64 = 0;
		ctx.r10.u64 = 0;
		return 0;
	}

	// find the entry for the key among the entity's 8-byte (key, data) entries, sorted by key
	uint32_t entryData;
	const uint32_t indexMap = LOAD32(entity + 140);
	if (indexMap != 0) {
		const uint32_t slot = LOAD8(indexMap + key);
		const uint64_t entryAddr = uint64_t(slot << 3) + LOAD32(entity + 72);
		entryData = LOAD32(uint32_t(entryAddr) + 4);
		// callers read r9 after the call
		ctx.r9.u64 = entryAddr;
	} else {
		uint32_t first = LOAD32(entity + 72);
		const uint32_t last = LOAD32(entity + 76);
		STORE32(stack - 16, 0);
		STORE32(stack - 12, first);

		// lower_bound for the key
		const uint64_t spanBytes = uint64_t(last) - first;
		const int32_t entryCount = int32_t(uint32_t(spanBytes)) >> 3;
		int32_t count = entryCount;
		uint64_t lastStepBelowKey = ctx.r7.u64;
		uint64_t lastStepBytes = spanBytes;
		uint64_t lastStepHalf = 0;
		if (count > 0) {
			do {
				const int32_t half = count >> 1;
				const uint32_t stepBytes = uint32_t(half) << 3;
				const uint32_t mid = first + stepBytes;
				const bool belowKey = (int32_t)LOAD32(mid) < key;
				if (belowKey) {
					count = count - half - 1;
					first = mid + 8;
				} else {
					count = half;
				}
				lastStepBelowKey = belowKey;
				lastStepBytes = stepBytes;
				lastStepHalf = uint64_t(int64_t(half));
			} while (count > 0);
			STORE32(stack - 12, first);
		}

		if (first != last && (int32_t)LOAD32(first) <= key) {
			STORE64(stack - 16, LOAD64(stack - 16));
			entryData = LOAD32(first + 4);
		} else {
			entryData = LOAD32(last + 4);
		}

		// callers read what the search leaves in r6-r9, cr0 and xer.ca after the call
		ctx.r6.u64 = last;
		ctx.r7.u64 = lastStepBelowKey;
		ctx.r8.u64 = lastStepBytes;
		ctx.r9.u64 = lastStepHalf;
		ctx.cr0.compare<int32_t>(entryCount, 0, ctx.xer);
		ctx.xer.ca = int32_t(uint32_t(spanBytes)) < 0 && (spanBytes & 7) != 0;
	}
	// callers read r10 after the call
	ctx.r10.u64 = 1;
	return LOAD32(entryData + 12);
}
PROMOTED_ENTRY(4, sub_821E8750, 0x821E8750) { ctx.r3.u64 = CECNavigation_GetNavigationData(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8225F728(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	constexpr int32_t g_82100000 = int32_t(0x82100000);
	if (!UseLiftedCode(9, 0x8225F728)) { ctx.r3.u64 = navigationAddr; __imp__sub_8225F728(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8225F728);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);

	stack = PushStackFrame(base, stack, 128);

	const uint64_t handleAddr = navigationAddr + 128;
	const uint32_t copyDestAddr = (uint32_t)navigationAddr + 32;
	const uint64_t bufferAddr = uint64_t(stack) + 80;
	uint32_t result = (uint32_t)navigationAddr;

	// When the word the handle's block points at is zero the handle is released; otherwise the copy
	// below runs only if the handled entity has bit 0x40 set in its byte at +144.
	bool shouldCopy = false;
	uint32_t entityFlag = 0;
	const uint32_t handleBlock = navigation->m_84;
	if (handleBlock != 0) {
		const uint32_t handleTarget = LOAD32(handleBlock);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = handleTarget;
		if (handleTarget == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			entityFlag = LOAD8(result + 144) & 64;
			shouldCopy = entityFlag != 0;
		}
	}

	if (shouldCopy) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = entityFlag;
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);

		// the entity's component at +124 writes a vector into the frame through its vtable slot +64
		const uint32_t component = LOAD32(entity + 124);
		const uint32_t vtable = LOAD32(component);
		const uint32_t virtualFn = LOAD32(vtable + 64);
		ctx.r3.u64 = bufferAddr;
		ctx.r4.u64 = component;
		ctx.r9.u64 = virtualFn;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(virtualFn);
		result = ctx.r3.u32;

		PPCVRegister copiedVector{};
		SET_V8(copiedVector, VLOAD((uint32_t)bufferAddr & ~0xF));
		VSTORE(copyDestAddr & ~0xF, V8(copiedVector));

		const uint32_t flag269 = navigation->m_269;
		if (flag269 == 0) {
			// callers read r7, r8 and v1 after the call
			ctx.r7.u64 = flag269;
			ctx.r8.u64 = bufferAddr;
			ctx.v1 = copiedVector;
		} else {
			const uint32_t navigationEntity = navigation->m_4;
			ctx.fpscr.disableFlushMode();
			const double floatArg1 = double(LOAD_F32((uint32_t)g_82100000 + 2000));
			const double floatArg2 = double(LOAD_F32(0x8209BAA8u));
			// state the callee may pass on
			ctx.r8.u64 = bufferAddr;
			ctx.r10.s64 = g_82100000;
			ctx.v1 = copiedVector;
			result = n_sub_82683428(ctx, base, 24, 1, navigationEntity, floatArg1, floatArg2);
			// the callee's v1 is stored again (and stays in v1 for callers)
			VSTORE(copyDestAddr & ~0xF, V8(ctx.v1));
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(9, sub_8225F728, 0x8225F728) { ctx.r3.u64 = n_sub_8225F728(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82260CF0(CpuState& ctx, uint8_t* base, uint64_t navigation) {
	if (!UseLiftedCode(9, 0x82260CF0)) { ctx.r3.u64 = navigation; __imp__sub_82260CF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82260CF0);
	uint32_t stack = ctx.r1.u64;
	constexpr int32_t key = 97;
	// r6-r9, v3, cr0 and xer.ca are handed to the callees and left for the callers; these locals
	// track what the original code holds in them.
	uint64_t stateR6 = ctx.r6.u64;
	uint64_t stateR7 = ctx.r7.u64;
	uint64_t stateR8 = 0;
	uint64_t stateR9 = 0;
	PPCVRegister stateV3 = ctx.v3;
	PPCCRRegister stateCr0 = ctx.cr0;
	uint8_t stateCarry = ctx.xer.ca;
	stack = PushStackFrame(base, stack, 112);

	// find the entry for the key among the entity's 8-byte (key, data) entries, sorted by key
	const uint32_t entity = LOAD32((uint32_t)navigation + 4);
	stateR9 = LOAD32(entity + 48);
	stateR8 = ((uint32_t)stateR9 >> 1) & 1;
	if (stateR8 != 0) {
		uint32_t entryData;
		const uint32_t indexMap = LOAD32(entity + 140);
		if (indexMap != 0) {
			const uint32_t slot = LOAD8(indexMap + key);
			stateR9 = uint64_t(slot << 3) + LOAD32(entity + 72);
			entryData = LOAD32((uint32_t)stateR9 + 4);
		} else {
			// lower_bound for the key
			uint32_t first = LOAD32(entity + 72);
			const uint32_t last = LOAD32(entity + 76);
			stateR6 = last;
			stateR9 = 0;
			STORE32(stack + 96, 0);
			stateR8 = uint64_t(last) - first;
			STORE32(stack + 100, first);
			stateCarry = (int32_t)stateR8 < 0 && ((uint32_t)stateR8 & 7) != 0;
			int32_t count = (int32_t)stateR8 >> 3;
			stateCr0.compare<int32_t>(count, 0, ctx.xer);
			if (count > 0) {
				do {
					const int32_t half = count >> 1;
					const uint32_t stepBytes = uint32_t(half) << 3;
					const uint32_t mid = first + stepBytes;
					const bool belowKey = (int32_t)LOAD32(mid) < key;
					if (belowKey) {
						count = count - half - 1;
						first = mid + 8;
					} else {
						count = half;
					}
					stateR7 = belowKey;
					stateR8 = stepBytes;
					stateR9 = uint64_t(int64_t(half));
				} while (count > 0);
				// halving a positive count leaves no carry
				stateCarry = 0;
				STORE32(stack + 100, first);
			}
			if (first != last && (int32_t)LOAD32(first) <= key) {
				// re-store the iterator pair the search left in the frame, then read the entry through it
				STORE64(stack + 96, LOAD64(stack + 96));
				entryData = LOAD32(LOAD32(stack + 100) + 4);
			} else {
				entryData = LOAD32(last + 4);
			}
		}

		stateR9 = LOAD32((uint32_t)navigation + 180);
		const int32_t mode = (int32_t)stateR9;
		SET_V8(stateV3, simde_mm_set1_epi32(int(0x0)));
		uint32_t actionId = 0;
		bool playAction = false;
		if (mode == 4) {
			actionId = 5;
			playAction = true;
		} else if (mode != 5) {
			if (LOAD8(entryData + 20) != 0) {
				stateR8 = 1184;
				SET_V8(stateV3, VLOAD((entryData + 1184) & ~0xF));
				PPCVRegister v2Value{};
				SET_V8(v2Value, VLOAD(0x8349AD70u & ~0xF));
				// state the callee may pass on
				ctx.r1.u64 = stack;
				ctx.r6.u64 = stateR6;
				ctx.r7.u64 = stateR7;
				ctx.r8.u64 = stateR8;
				ctx.r9.u64 = stateR9;
				ctx.v1 = stateV3;
				ctx.v2 = v2Value;
				ctx.v3 = stateV3;
				ctx.cr0 = stateCr0;
				ctx.xer.ca = stateCarry;
				const uint64_t result = n_sub_82675EA8(ctx, base, navigation, 2);
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return result;
			}
			if (mode == 2) {
				// state the callee may pass on
				ctx.r1.u64 = stack;
				ctx.r6.u64 = stateR6;
				ctx.r7.u64 = stateR7;
				ctx.r8.u64 = stateR8;
				ctx.r9.u64 = stateR9;
				ctx.v3 = stateV3;
				ctx.cr0 = stateCr0;
				ctx.xer.ca = stateCarry;
				const uint64_t result = n_sub_82192268(ctx, base, navigation);
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return result;
			}
			if (LOAD8((uint32_t)navigation + 184) != 0 && mode == 1) {
				actionId = 3;
				playAction = true;
			}
		}
		if (playAction) {
			PPCVRegister v1Value{};
			PPCVRegister v2Value{};
			SET_V8(stateV3, VLOAD(((uint32_t)navigation + 560u) & ~0xF));
			SET_V8(v2Value, VLOAD(((uint32_t)navigation + 544u) & ~0xF));
			SET_V8(v1Value, VLOAD(((uint32_t)navigation + 528u) & ~0xF));
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r6.u64 = stateR6;
			ctx.r7.u64 = stateR7;
			ctx.r8.u64 = stateR8;
			ctx.r9.u64 = 528;
			ctx.v1 = v1Value;
			ctx.v2 = v2Value;
			ctx.v3 = stateV3;
			ctx.cr0 = stateCr0;
			ctx.xer.ca = stateCarry;
			// what the callee leaves in r6-r9, v3, cr0 and xer.ca stays there for our callers
			const uint64_t result = n_sub_82675F20(ctx, base, navigation, actionId);
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return result;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r6.u64 = stateR6;
	ctx.r7.u64 = stateR7;
	ctx.r8.u64 = stateR8;
	ctx.r9.u64 = stateR9;
	ctx.v3 = stateV3;
	ctx.cr0 = stateCr0;
	ctx.xer.ca = stateCarry;
	return navigation;
}
PROMOTED_ENTRY(9, sub_82260CF0, 0x82260CF0) { ctx.r3.u64 = n_sub_82260CF0(ctx, base, ctx.r3.u64); }

// sub_826714D0  [60 bytes]
uint64_t CECNavigation_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A2F90_B_ = int32_t(0x820A2F90);
	if (!UseLiftedCode(43, 0x826714D0)) { ctx.r3.u64 = classNameString; __imp__sub_826714D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826714D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820A2F90_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(43, sub_826714D0, 0x826714D0) { ctx.r3.u64 = CECNavigation_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82673510(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(43, 0x82673510)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82673510(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82673510);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	// written into the first word of each entity handle right before the handle is released
	const uint32_t handleFirstWord = uint32_t(g_820F1664);

	stack = PushStackFrame(base, stack, 128);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	List_ClearRefCountedHandleNodes(ctx, base, navigationAddr + 648);

	HandleTarget_Free(ctx, base, navigation->m_28C);
	navigation->m_28C = 0;

	navigation->m_240 = handleFirstWord;
	EntityHandle_Release(ctx, base, navigationAddr + 576);
	navigation->m_244 = 0;

	n_sub_8227CC80(ctx, base, navigationAddr + 400);
	n_sub_8227CC80(ctx, base, navigationAddr + 272);

	SharedHandle_Release(ctx, base, navigationAddr + 224);

	navigation->m_80 = handleFirstWord;
	EntityHandle_Release(ctx, base, navigationAddr + 128);
	navigation->m_84 = 0;

	navigation->vtable = 0x820A8D10u;

	// bit 0 of the flags also frees the object itself
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, navigationAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return navigationAddr;
}
PROMOTED_ENTRY(43, sub_82673510, 0x82673510) { ctx.r3.u64 = n_sub_82673510(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Reads the navigation settings from the entity's database record (when there is one): turn angles are
// converted with the constant at 0x821001DC (pi/180), deceleration and acceleration are raised to at least
// the constant at 0x8209BAAC and scaled; then hands the object to sub_82392C88 together with its m_4.
uint64_t n_sub_826735A8(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t entity) {
	constexpr int32_t str_TXT_82001024_B_ = int32_t(0x82001024);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820C9BE0_B_ = int32_t(0x820C9BE0);
	constexpr int32_t str_TXT_820C9BF8_B_ = int32_t(0x820C9BF8);
	constexpr int32_t str_TXT_820C9C10_B_ = int32_t(0x820C9C10);
	constexpr int32_t str_TXT_820C9C28_B_ = int32_t(0x820C9C28);
	constexpr int32_t str_TXT_820C9C40_B_ = int32_t(0x820C9C40);
	constexpr int32_t str_TXT_820C9C58_B_ = int32_t(0x820C9C58);
	constexpr int32_t str_TXT_820C9C6C_B_ = int32_t(0x820C9C6C);
	constexpr int32_t str_TXT_820C9C7C_B_ = int32_t(0x820C9C7C);
	constexpr int32_t str_TXT_820C9C8C_B_ = int32_t(0x820C9C8C);
	constexpr int32_t str_TXT_820C9C98_B_ = int32_t(0x820C9C98);
	constexpr int32_t str_TXT_820C9CA8_B_ = int32_t(0x820C9CA8);
	constexpr int32_t g_820D0000 = int32_t(0x820D0000);
	constexpr int32_t g_82100000 = int32_t(0x82100000);
	if (!UseLiftedCode(43, 0x826735A8)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = entity; __imp__sub_826735A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826735A8);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	stack = PushStackFrame(base, stack, 208);

	if ((uint32_t)entity != 0) {
		const uint32_t maxSpeedAddr = navigationAddr + 244;
		const uint32_t turnPerSecondAddr = navigationAddr + 136;
		const uint32_t turnPerMetreAddr = navigationAddr + 140;
		const uint32_t minStaticTurnAddr = navigationAddr + 148;
		const uint32_t maxDynamicTurnAddr = navigationAddr + 152;
		const uint32_t maxDecelerationAddr = navigationAddr + 268;
		const uint32_t maxAccelerationAddr = navigationAddr + 264;

		ctx.r1.u64 = stack;
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_82001024_B_, maxSpeedAddr);
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9BE0_B_, turnPerSecondAddr);
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9BF8_B_, turnPerMetreAddr);
		ctx.r8.s64 = g_820D0000;   // state the callee may pass on
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C10_B_, minStaticTurnAddr);
		ctx.r7.s64 = g_820D0000;   // state the callee may pass on
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C28_B_, maxDynamicTurnAddr);
		ctx.r6.s64 = g_820D0000;   // state the callee may pass on
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C40_B_, navigationAddr + 144);
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C58_B_, navigationAddr + 256);
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C6C_B_, maxDecelerationAddr);
		GameDB_ReadFloatField(ctx, base, entity, str_TXT_820C9C7C_B_, maxAccelerationAddr);
		GameDB_ReadBool(ctx, base, entity, str_TXT_820C9C8C_B_, navigationAddr + 185);
		uint64_t TXT_820C9C98_L_ = GameDB_ReadU32Field(ctx, base, entity, str_TXT_820C9C98_B_);

		if ((uint32_t)TXT_820C9C98_L_ != 0) {
			// nine floats from the preferabilities record into +188 onwards; each field name is a string
			// built on the stack from the str_TXT_820C9CA8_B_ prefix and the index
			const uint32_t indexString = stack + 84;
			const uint32_t fieldNameString = stack + 80;
			uint64_t prefAddr = navigationAddr + 188;
			int32_t prefIndex = 0;
			do {
				uint64_t indexText = CCharString_ConstructFormatInt(ctx, base, indexString, (uint64_t)prefIndex);
				CCharString_ConstructFromCStr(ctx, base, fieldNameString, str_TXT_820C9CA8_B_, -1);
				RefCountedString_Assign(ctx, base, fieldNameString, indexText);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, indexString);
				uint32_t fieldNameBuffer = LOAD32(fieldNameString);
				uint64_t fieldName = g_8209003F;   // an empty string when the name has no buffer
				if (fieldNameBuffer != 0) {
					fieldName = LOAD32(fieldNameBuffer);
				}
				GameDB_ReadFloatField(ctx, base, TXT_820C9C98_L_, fieldName, prefAddr);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, fieldNameString);
				prefIndex++;
				prefAddr += 4;
			} while (prefIndex < 9);
		}

		const uint32_t scaleNumeratorAddr = uint32_t(g_820A0000) - 40;

		ctx.fpscr.disableFlushMode();
		const double minimumRate = double(LOAD_F32(scaleNumeratorAddr - 17708));
		if (double(LOAD_F32(maxDecelerationAddr)) < minimumRate) {
			STORE_F32(maxDecelerationAddr, float(minimumRate));
		}
		ctx.fpscr.disableFlushMode();
		if (double(LOAD_F32(maxAccelerationAddr)) < minimumRate) {
			STORE_F32(maxAccelerationAddr, float(minimumRate));
		}
		ctx.fpscr.disableFlushMode();
		const double rateScale = LOAD_F64(scaleNumeratorAddr) / LOAD_F64(0x83319510u);
		const double degreesToRadians = double(LOAD_F32(uint32_t(g_82100000) + 476));
		const double speedFactor = double(LOAD_F32(uint32_t(g_82100000) + 2248));
		const double TXT_82001024_L_ = double(LOAD_F32(maxSpeedAddr));
		const double turnAnglePerSecond = double(LOAD_F32(turnPerSecondAddr));
		const double turnAnglePerMetre = double(LOAD_F32(turnPerMetreAddr));
		const double minStaticTurnAngle = double(LOAD_F32(minStaticTurnAddr));
		const double maxDynamicTurnAngle = double(LOAD_F32(maxDynamicTurnAddr));
		const double TXT_820C9C6C_L_ = double(LOAD_F32(maxDecelerationAddr));
		const double TXT_820C9C7C_L_ = double(LOAD_F32(maxAccelerationAddr));

		const double turnPerSecondRadians = double(float(turnAnglePerSecond * degreesToRadians));
		const double turnPerMetreRadians = double(float(turnAnglePerMetre * degreesToRadians));
		const double minStaticTurnRadians = double(float(minStaticTurnAngle * degreesToRadians));
		const double maxDynamicTurnRadians = double(float(maxDynamicTurnAngle * degreesToRadians));
		const double scaledTXT_82001024_B_ = double(float(TXT_82001024_L_ * speedFactor));
		const double scaledTXT_820C9C6C_B_ = TXT_820C9C6C_L_ * rateScale;
		const double scaledTXT_820C9C7C_B_ = TXT_820C9C7C_L_ * rateScale;

		STORE_F32(turnPerSecondAddr, float(turnPerSecondRadians));
		STORE_F32(turnPerMetreAddr, float(turnPerMetreRadians));
		STORE_F32(minStaticTurnAddr, float(minStaticTurnRadians));
		STORE_F32(maxDynamicTurnAddr, float(maxDynamicTurnRadians));
		navigation->m_EC = float(TXT_82001024_L_);
		navigation->m_E8 = float(scaledTXT_82001024_B_);
		STORE_F32(maxDecelerationAddr, float(scaledTXT_820C9C6C_B_));
		STORE_F32(maxAccelerationAddr, float(scaledTXT_820C9C7C_B_));

		// state the callee may pass on
		ctx.r8.s64 = g_82100000;
		ctx.r9.s64 = g_82100000;
		CECNavigation_ClearCandidateData(ctx, base, (uint32_t)navigationAddr);

		// the float registers as the computation above leaves them, for the call below
		ctx.f1.f64 = maxDynamicTurnRadians;
		ctx.f2.f64 = minStaticTurnRadians;
		ctx.f3.f64 = TXT_82001024_L_;
		ctx.f4.f64 = turnPerMetreRadians;
		ctx.f5.f64 = maxDynamicTurnAngle;
		ctx.f6.f64 = turnPerSecondRadians;
		ctx.f7.f64 = minStaticTurnAngle;
		ctx.f8.f64 = rateScale;
		ctx.f9.f64 = turnAnglePerMetre;
		ctx.f10.f64 = double(float(scaledTXT_820C9C7C_B_));
		ctx.f11.f64 = double(float(scaledTXT_820C9C6C_B_));
		ctx.f12.f64 = scaledTXT_820C9C7C_B_;
		ctx.f13.f64 = scaledTXT_820C9C6C_B_;
	}

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82392C88(ctx, base, uint32_t(navigation->m_4), navigationAddr);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_826735A8, 0x826735A8) { ctx.r3.u64 = n_sub_826735A8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Runs sub_82673148 on the pairs at +272 and +400; a non-zero m_E0 is resolved into the entity handle at
// +128 (through a temporary handle on the stack), then released and cleared.
uint64_t n_sub_82674008(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(43, 0x82674008)) { ctx.r3.u64 = navigationAddr; __imp__sub_82674008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674008);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	n_sub_82673148(ctx, base, navigationAddr + 272);
	uint64_t result = n_sub_82673148(ctx, base, navigationAddr + 400);

	const uint64_t pendingHandle = navigation->m_E0;
	uint64_t callerR4 = pendingHandle;
	if ((uint32_t)pendingHandle != 0) {
		const uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
		const uint32_t lookupHolder = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
		const uint32_t lookupObject = LOAD32(lookupHolder);
		ctx.r8.u64 = lookupHolder;   // state the callee may pass on
		uint64_t entity = n_sub_82264448(ctx, base, lookupObject, pendingHandle);

		// temporary entity handle at stack+80: vtable word, then an empty target
		const int64_t handleVtable = (int64_t)g_820F0000 + 5732;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)handleVtable);
		// state the callee may pass on
		ctx.r6.u64 = handleVtable;
		ctx.r7.s64 = g_820F0000;
		EntityHandle_SetTarget(ctx, base, stack + 80, entity);
		EntityHandle_Assign(ctx, base, navigationAddr + 128, stack + 80);

		STORE32(stack + 80, (uint32_t)handleVtable);
		// state the callee may pass on
		ctx.r4.u64 = handleVtable;
		ctx.r5.s64 = g_820F0000;
		EntityHandle_Release(ctx, base, stack + 80);

		result = SharedHandle_Release(ctx, base, navigationAddr + 224);
		callerR4 = ctx.r4.u64;
		STORE32(navigationAddr + 224, 0);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(43, sub_82674008, 0x82674008) { ctx.r3.u64 = n_sub_82674008(ctx, base, ctx.r3.u64); }

// Calls the function for the current mode m_AC (1-6) with the values stored on the object (the target in
// the handle at +128, m_B0, m_9C, m_104); m_F0 is put back to the value it had before.
uint64_t n_sub_826740A8(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	constexpr int32_t g_82670000 = int32_t(0x82670000);
	if (!UseLiftedCode(43, 0x826740A8)) { ctx.r3.u64 = navigationAddr; __imp__sub_826740A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826740A8);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	stack = PushStackFrame(base, stack, 160);

	uint64_t result = navigationAddr;
	const double savedF0 = double(navigation->m_F0);

	const uint32_t mode = uint32_t(navigation->m_AC) - 1;
	if (mode <= 5) {
		ctx.r1.u64 = stack;
		// the mode's jump-table entry, still in r0 when the first call of each case is made
		ctx.r0.u64 = LOAD32(uint32_t(g_82670000) + 16632 + mode * 4);
		switch (mode) {
		case 0: {
			uint64_t target = EntityHandle_Get_825575C8(ctx, base, navigationAddr + 128);
			result = n_sub_82674AA0(ctx, base, navigationAddr, target, 2, 0);
			break;
		}
		case 1: {
			const uint64_t handleAddr = navigationAddr + 128;
			const uint32_t handleRef = navigation->m_84;
			uint32_t flagBit = 0;
			if (handleRef != 0) {
				const uint32_t referencedObject = LOAD32(handleRef);
				ctx.r10.u64 = referencedObject;   // state the callee may pass on
				if (referencedObject == 0) {
					EntityHandle_Release(ctx, base, handleAddr);
				} else {
					const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
					flagBit = LOAD8(entity + 144) & 64;
				}
			}
			if (flagBit != 0) {
				ctx.r10.u64 = flagBit;   // state the callee may pass on
				uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
				result = n_sub_82674C08(ctx, base, navigationAddr, target, 2, 0);
			} else {
				result = n_sub_82674D18(ctx, base, navigationAddr, 2);
			}
			break;
		}
		case 2: {
			const uint32_t storedB0 = navigation->m_B0;
			ctx.fpscr.disableFlushMode();
			const double stored104 = double(navigation->m_104);
			const double stored9C = double(navigation->m_9C);
			PPCVRegister storedVector{};
			SET_V8(storedVector, VLOAD((uint32_t)navigationAddr + 624u & ~0xF));
			ctx.v1 = storedVector;   // state the callee may pass on
			result = n_sub_822B41C8(ctx, base, navigationAddr, 2, 1, 0, 0, storedB0, stored9C, stored104);
			break;
		}
		case 3: {
			const uint32_t storedB0 = navigation->m_B0;
			ctx.fpscr.disableFlushMode();
			const double stored104 = double(navigation->m_104);
			const double stored9C = double(navigation->m_9C);
			uint64_t target = EntityHandle_Get_825575C8(ctx, base, navigationAddr + 128);
			ctx.fpscr.disableFlushMode();
			result = n_sub_82674568(ctx, base, navigationAddr, target, 2, 0, storedB0, stored9C, stored104);
			break;
		}
		case 4: {
			const uint32_t storedB0 = navigation->m_B0;
			ctx.fpscr.disableFlushMode();
			const double stored9C = double(navigation->m_9C);
			result = n_sub_82674F00(ctx, base, navigationAddr, 2, 0, storedB0, stored9C);
			break;
		}
		case 5: {
			const uint32_t storedB0 = navigation->m_B0;
			uint64_t target = EntityHandle_Get_825575C8(ctx, base, navigationAddr + 128);
			result = n_sub_82674D98(ctx, base, navigationAddr, target, 2, 0, storedB0);
			break;
		}
		}
	}

	ctx.fpscr.disableFlushMode();
	navigation->m_F0 = float(savedF0);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_826740A8, 0x826740A8) { ctx.r3.u64 = n_sub_826740A8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82674290(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	if (!UseLiftedCode(43, 0x82674290)) { ctx.r3.u64 = navigationAddr; __imp__sub_82674290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674290);
	return n_sub_826728C0(ctx, base, navigationAddr + 272);
}
PROMOTED_ENTRY(43, sub_82674290, 0x82674290) { ctx.r3.u64 = n_sub_82674290(ctx, base, ctx.r3.u64); }

// Sets the speed, then (unless +612 is above the limit at 0x8331950C, which returns 0) switches to mode
// m_A8 = 3 / m_AC = 1 with the target: a position obtained from the target is first checked with
// Combat_IsShootingPositionUsable, and an unusable one returns 0.
// Returns 1 when the mode is set or was already set for this target.
uint64_t n_sub_82674AA0(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t target, uint64_t speed, uint64_t reinitFlag) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82674AA0)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = target; ctx.r5.u64 = speed; ctx.r6.u64 = reinitFlag; __imp__sub_82674AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674AA0);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 144);

	// r4 and r5 start out holding the speed; the calls below may change them, and callers read r4
	uint64_t r4Value = speed;
	uint64_t r5Value = speed;
	ctx.r1.u64 = stack;
	CECNavigation_SetSpeed(ctx, base, navigationAddr, speed);

	const int32_t limit = int32_t(LOAD32(uint32_t(g_83320000) - 27380));
	if (int32_t(LOAD32((uint32_t)navigationAddr + 612)) > limit) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = r4Value;   // callers read r4 after the call
		return 0;
	}

	uint64_t navigationData = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
	if ((uint32_t)navigationData != 0) {
		callTarget.u64 = LOAD32(LOAD32((uint32_t)navigationData) + 20);
		ctx.r3.u64 = navigationData;
		ctx.r4.u64 = r4Value;
		ctx.r5.u64 = r5Value;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r4Value = ctx.r4.u64;
		r5Value = ctx.r5.u64;
	}

	bool alreadyTargeting = false;
	if (navigation->m_A8 == 3 && navigation->m_AC == 1) {
		const uint32_t currentTarget = navigation->m_280;
		alreadyTargeting = currentTarget != 0 && currentTarget == (uint32_t)target;
	}

	if (!alreadyTargeting) {
		if ((reinitFlag & 0xFF) != 0) {
			// state the callee may pass on
			ctx.r4.u64 = r4Value;
			ctx.r5.u64 = r5Value;
			InitEntityHandlePairAndVectors(ctx, base, navigationAddr + 272);
			r5Value = ctx.r5.u64;
		}

		// the virtual function at +64 of the object at target+124 writes a vector to stack+96
		const uint32_t targetObject = LOAD32((uint32_t)target + 124);
		callTarget.u64 = LOAD32(LOAD32(targetObject) + 64);
		ctx.r3.u64 = uint64_t(stack) + 96;
		ctx.r4.u64 = targetObject;
		ctx.r5.u64 = r5Value;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		PPCVRegister position{};
		SET_V8(position, VLOAD(uint32_t(uint64_t(stack) + 96) & ~0xF));
		ctx.v1 = position;   // the position the check below receives
		const uint32_t usable = uint32_t(Combat_IsShootingPositionUsable(ctx, base, navigationAddr, 1)) & 0xFF;
		r4Value = ctx.r4.u64;
		if (usable == 0) {
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			ctx.r4.u64 = r4Value;   // callers read r4 after the call
			return 0;
		}

		// temporary entity handle at stack+80: vtable word, then an empty target
		constexpr int64_t handleVtable = g_820F1664;
		STORE32(stack + 84, 0);
		STORE32(stack + 80, uint32_t(handleVtable));
		// state the callee may pass on
		ctx.r8.u64 = usable;
		ctx.r9.s64 = handleVtable;
		ctx.r10.u64 = 0;
		EntityHandle_SetTarget(ctx, base, uint64_t(stack) + 80, target);
		EntityHandle_Assign(ctx, base, navigationAddr + 128, uint64_t(stack) + 80);

		STORE32(stack + 80, uint32_t(handleVtable));
		// state the callee may pass on
		ctx.r7.s64 = handleVtable;
		ctx.r8.s64 = g_820F0000;
		EntityHandle_Release(ctx, base, uint64_t(stack) + 80);

		navigation->m_280 = (uint32_t)target;
		navigation->m_A8 = 3u;
		ctx.r6.u64 = 3;   // state the callee may pass on
		n_sub_8225F728(ctx, base, navigationAddr);
		n_sub_826772A0(ctx, base, navigationAddr);
		r4Value = 1;
		navigation->m_260 = 2u;
		navigation->m_AC = 1u;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;   // callers read r4 after the call
	return 1;
}
PROMOTED_ENTRY(43, sub_82674AA0, 0x82674AA0) { ctx.r3.u64 = n_sub_82674AA0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// Sets the speed, then (unless +612 is above the limit at 0x8331950C) switches to mode m_A8 = 3 / m_AC = 2
// with the target, unless that mode is already set for this target.
uint64_t n_sub_82674C08(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t target, uint64_t speed, uint64_t reinitFlag) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82674C08)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = target; ctx.r5.u64 = speed; ctx.r6.u64 = reinitFlag; __imp__sub_82674C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674C08);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	// r4 and r5 start out holding the speed; the calls below may change them, and callers read r4
	uint64_t r4Value = speed;
	uint64_t r5Value = speed;
	uint64_t result = navigationAddr;
	ctx.r1.u64 = stack;
	CECNavigation_SetSpeed(ctx, base, navigationAddr, speed);

	const int32_t limit = int32_t(LOAD32(uint32_t(g_83320000) - 27380));
	if (int32_t(LOAD32((uint32_t)navigationAddr + 612)) <= limit) {
		result = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
		if ((uint32_t)result != 0) {
			callTarget.u64 = LOAD32(LOAD32((uint32_t)result) + 20);
			ctx.r3.u64 = result;
			ctx.r4.u64 = r4Value;
			ctx.r5.u64 = r5Value;
			ctx.r10.u64 = callTarget.u64;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
		}

		bool alreadyTargeting = false;
		if (navigation->m_A8 == 3 && navigation->m_AC == 2) {
			const uint32_t currentTarget = navigation->m_280;
			alreadyTargeting = currentTarget != 0 && currentTarget == (uint32_t)target;
		}

		if (!alreadyTargeting) {
			if ((reinitFlag & 0xFF) != 0) {
				// state the callee may pass on
				ctx.r4.u64 = r4Value;
				ctx.r5.u64 = r5Value;
				InitEntityHandlePairAndVectors(ctx, base, navigationAddr + 272);
				r5Value = ctx.r5.u64;
			}

			// temporary entity handle at stack+80: vtable word, then an empty target
			STORE32(stack + 84, 0);
			STORE32(stack + 80, uint32_t(g_820F1664));
			// state the callee may pass on
			ctx.r5.u64 = r5Value;
			ctx.r9.s64 = g_820F1664;
			ctx.r10.u64 = 0;
			EntityHandle_SetTarget(ctx, base, uint64_t(stack) + 80, target);
			EntityHandle_Assign(ctx, base, navigationAddr + 128, uint64_t(stack) + 80);

			const uint32_t handleVtable = uint32_t(g_820F0000) + 5732;
			STORE32(stack + 80, handleVtable);
			// state the callee may pass on (zero-extended this time)
			ctx.r7.u64 = handleVtable;
			ctx.r8.u64 = uint32_t(g_820F0000);
			EntityHandle_Release(ctx, base, uint64_t(stack) + 80);

			navigation->m_280 = (uint32_t)target;
			navigation->m_A8 = 3u;
			result = n_sub_826772A0(ctx, base, navigationAddr);
			r4Value = ctx.r4.u64;
			navigation->m_AC = 2u;
			navigation->m_260 = 2u;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(43, sub_82674C08, 0x82674C08) { ctx.r3.u64 = n_sub_82674C08(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// Sets the speed, then (unless +612 is above the limit at 0x8331950C) switches to mode m_A8 = 3 / m_AC = 2
// when m_178 is non-zero.
uint64_t n_sub_82674D18(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t speed) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82674D18)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = speed; __imp__sub_82674D18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674D18);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 96);

	// r4 starts out holding the speed; the calls below may change it, and callers read it
	uint64_t r4Value = speed;
	uint64_t result = navigationAddr;
	ctx.r1.u64 = stack;
	CECNavigation_SetSpeed(ctx, base, navigationAddr, speed);

	const int32_t limit = int32_t(LOAD32(uint32_t(g_83320000) - 27380));
	if (int32_t(LOAD32((uint32_t)navigationAddr + 612)) <= limit) {
		result = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
		if ((uint32_t)result != 0) {
			callTarget.u64 = LOAD32(LOAD32((uint32_t)result) + 20);
			ctx.r3.u64 = result;
			ctx.r4.u64 = r4Value;
			ctx.r10.u64 = callTarget.u64;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
		}
		if (navigation->m_178 != 0) {
			navigation->m_A8 = 3u;
			ctx.r4.u64 = r4Value;   // state the callee may pass on
			result = n_sub_826772A0(ctx, base, navigationAddr);
			r4Value = ctx.r4.u64;
			navigation->m_AC = 2u;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(43, sub_82674D18, 0x82674D18) { ctx.r3.u64 = n_sub_82674D18(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Sets the speed, then (unless +612 is above the limit at 0x8331950C) switches to mode m_A8 = 3 / m_AC = 6
// with the target, unless that mode is already set for this target: m_9C is taken from one of two globals
// (chosen by the byte at 0x834BE801), m_B0 from stateByte, and the vector the target's object writes is
// copied to +32.
uint64_t n_sub_82674D98(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t targetEntity, uint64_t speed, uint64_t reinitFlag, uint64_t stateByte) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82674D98)) { ctx.r3.u64 = navigationAddr; ctx.r4.u64 = targetEntity; ctx.r5.u64 = speed; ctx.r6.u64 = reinitFlag; ctx.r7.u64 = stateByte; __imp__sub_82674D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674D98);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 160);

	// r4 and r5 start out holding the speed; the calls below may change them, and callers read r4
	uint64_t r4Value = speed;
	uint64_t r5Value = speed;
	uint64_t result = navigationAddr;
	ctx.r1.u64 = stack;
	CECNavigation_SetSpeed(ctx, base, navigationAddr, speed);

	const int32_t limit = int32_t(LOAD32(uint32_t(g_83320000) - 27380));
	if (int32_t(LOAD32((uint32_t)navigationAddr + 612)) <= limit) {
		result = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
		if ((uint32_t)result != 0) {
			callTarget.u64 = LOAD32(LOAD32((uint32_t)result) + 20);
			ctx.r3.u64 = result;
			ctx.r4.u64 = r4Value;
			ctx.r5.u64 = r5Value;
			ctx.r10.u64 = callTarget.u64;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
		}

		bool alreadyTargeting = false;
		if (navigation->m_A8 == 3 && navigation->m_AC == 6) {
			const uint32_t currentTarget = navigation->m_280;
			alreadyTargeting = currentTarget != 0 && currentTarget == (uint32_t)targetEntity;
		}

		if (!alreadyTargeting) {
			if ((reinitFlag & 0xFF) != 0) {
				// state the callee may pass on
				ctx.r4.u64 = r4Value;
				ctx.r5.u64 = r5Value;
				InitEntityHandlePairAndVectors(ctx, base, navigationAddr + 272);
				r5Value = ctx.r5.u64;
			}

			// temporary entity handle at stack+80: vtable word, then an empty target
			STORE32(stack + 84, 0);
			STORE32(stack + 80, uint32_t(g_820F1664));
			// state the callee may pass on
			ctx.r5.u64 = r5Value;
			ctx.r9.s64 = g_820F1664;
			ctx.r10.u64 = 0;
			EntityHandle_SetTarget(ctx, base, uint64_t(stack) + 80, targetEntity);
			EntityHandle_Assign(ctx, base, navigationAddr + 128, uint64_t(stack) + 80);

			const uint32_t handleVtable = uint32_t(g_820F0000) + 5732;
			STORE32(stack + 80, handleVtable);
			// state the callee may pass on (zero-extended this time)
			ctx.r7.u64 = handleVtable;
			ctx.r8.u64 = uint32_t(g_820F0000);
			EntityHandle_Release(ctx, base, uint64_t(stack) + 80);

			const uint32_t valuePairAddr = uint32_t(g_820A0000) - 27860;
			const uint32_t useSecondValue = LOAD8(0x834BE801u);
			ctx.fpscr.disableFlushMode();
			double value9C = double(LOAD_F32(valuePairAddr));
			if (useSecondValue != 0) {
				value9C = double(LOAD_F32(valuePairAddr + 12));
			}
			ctx.fpscr.disableFlushMode();
			navigation->m_9C = float(value9C);
			navigation->m_280 = (uint32_t)targetEntity;
			navigation->m_A8 = 3u;
			navigation->m_B0 = (uint8_t)stateByte;
			ctx.r5.u64 = useSecondValue;   // state the callee may pass on
			n_sub_826772A0(ctx, base, navigationAddr);

			// the virtual function at +64 of the object at targetEntity+124 writes a vector to stack+96
			const uint32_t targetObject = LOAD32((uint32_t)targetEntity + 124);
			const uint32_t targetVtable = LOAD32(targetObject);
			callTarget.u64 = LOAD32(targetVtable + 64);
			ctx.r3.u64 = uint64_t(stack) + 96;
			ctx.r4.u64 = targetObject;
			ctx.r9.u64 = callTarget.u64;
			ctx.r10.u64 = targetVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
			navigation->m_AC = 6u;
			PPCVRegister targetVector{};
			SET_V8(targetVector, VLOAD(uint32_t(uint64_t(stack) + 96) & ~0xF));
			navigation->m_260 = 2u;
			VSTORE((uint32_t)navigationAddr + 32u & ~0xF, V8(targetVector));
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(43, sub_82674D98, 0x82674D98) { ctx.r3.u64 = n_sub_82674D98(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_82674F00(CpuState& ctx, uint8_t* base, uint64_t navigationAddr, uint64_t arg2, uint64_t initHandlePair, uint64_t valueB0, double floatArg1) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(43, 0x82674F00)) { ctx.r3.u64 = navigationAddr; ctx.r5.u64 = arg2; ctx.r6.u64 = initHandlePair; ctx.r7.u64 = valueB0; ctx.f1.f64 = floatArg1; __imp__sub_82674F00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82674F00);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	// Register values as the lifted code tracks them: handed to callees, read back after calls; r4 and f1 are
	// left for callers.
	uint64_t r4Value = arg2;
	uint64_t r5Value = arg2;
	double f1Value = floatArg1;
	uint64_t result = navigationAddr;
	PPCRegister callTarget{};
	PPCVRegister vectorConstant{};

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	CECNavigation_SetSpeed(ctx, base, navigationAddr, arg2);
	double f13Value = ctx.f13.f64;

	const uint32_t threshold = LOAD32(uint32_t(g_83320000) - 27380);
	if ((int32_t)LOAD32(navigationAddr + 0x264) <= (int32_t)threshold) {
		result = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
		if ((uint32_t)result != 0) {
			const uint32_t virtualFn = LOAD32(LOAD32((uint32_t)result) + 20);
			callTarget.u64 = virtualFn;
			ctx.r3.u64 = result;
			ctx.r4.u64 = r4Value;
			ctx.r5.u64 = r5Value;
			ctx.r10.u64 = virtualFn;
			ctx.f1.f64 = f1Value;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;
		}

		// Nothing more to do when m_AC / m_A8 already hold the values set below (5 / 3).
		if (!(LOAD32(navigationAddr + 0xAC) == 5 && LOAD32(navigationAddr + 0xA8) == 3)) {
			if ((initHandlePair & 0xFF) != 0) {
				// state the callee may pass on
				ctx.r4.u64 = r4Value;
				ctx.r5.u64 = r5Value;
				ctx.f1.f64 = f1Value;
				InitEntityHandlePairAndVectors(ctx, base, navigationAddr + 0x110);
				r4Value = ctx.r4.u64;
				r5Value = ctx.r5.u64;
				f1Value = ctx.f1.f64;
				f13Value = ctx.f13.f64;
			}

			// An empty entity handle on the stack is released, assigned to the handle at +0x80, and released again.
			const uint64_t handleAddr = (uint64_t)stack + 80;
			STORE32(handleAddr + 4, 0u);
			STORE32(handleAddr, uint32_t(g_820F1664));
			// state the callee may pass on
			ctx.r4.u64 = r4Value;
			ctx.r5.u64 = r5Value;
			ctx.r10.u64 = (uint64_t)(int64_t)g_820F1664;
			ctx.f1.f64 = f1Value;
			EntityHandle_Release(ctx, base, handleAddr);
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;

			EntityHandle_Assign(ctx, base, navigationAddr + 0x80, handleAddr);
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;

			const uint32_t handleType = uint32_t(g_820F0000) + 5732;
			STORE32(handleAddr, handleType);
			// state the callee may pass on
			ctx.r8.u64 = handleType;
			ctx.r9.u64 = uint32_t(g_820F0000);
			EntityHandle_Release(ctx, base, handleAddr);
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;

			// m_9C gets the float argument, or the constant at 0x82099338 when the flag byte at 0x834BE801 is set
			// or the argument equals the constant at 0x820994B4.
			ctx.fpscr.disableFlushMode();
			const uint32_t matchValueAddr = uint32_t((int32_t)uint32_t(g_820A0000) - 27468);
			const uint32_t replacementAddr = matchValueAddr - 380;
			double newValue9C = floatArg1;
			if (LOAD8(0x834BE801u) != 0) {
				newValue9C = double(LOAD_F32(replacementAddr));
			} else {
				ctx.fpscr.disableFlushMode();
				f13Value = double(LOAD_F32(matchValueAddr));
				if (floatArg1 == f13Value) {
					newValue9C = double(LOAD_F32(replacementAddr));
				}
			}

			ctx.fpscr.disableFlushMode();
			navigation->m_9C = float(newValue9C);
			navigation->m_A8 = 3u;
			SET_V8(vectorConstant, VLOAD(0x8349AD70u & ~0xF));
			navigation->m_280 = 0u;
			VSTORE(((uint32_t)navigationAddr + 624u) & ~0xF, V8(vectorConstant));
			navigation->m_B0 = (uint8_t)valueB0;

			// state the callee may pass on
			ctx.f13.f64 = f13Value;
			result = n_sub_826772A0(ctx, base, navigationAddr);
			r4Value = ctx.r4.u64;
			f1Value = ctx.f1.f64;
			navigation->m_AC = 5u;
			navigation->m_260 = 2u;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 and f1 after the call
	ctx.r4.u64 = r4Value;
	ctx.f1.f64 = f1Value;
	return result;
}
PROMOTED_ENTRY(43, sub_82674F00, 0x82674F00) { ctx.r3.u64 = n_sub_82674F00(ctx, base, ctx.r3.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.f1.f64); }

uint64_t n_sub_82675048(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(43, 0x82675048)) { ctx.r3.u64 = navigationAddr; __imp__sub_82675048(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82675048);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);

	stack = PushStackFrame(base, stack, 112);
	const uint64_t scratchHandleAddr = (uint64_t)stack + 80;

	// An empty entity handle on the stack is released, assigned to the handle at +0x80, and released again.
	STORE32(scratchHandleAddr + 4, 0u);
	STORE32(scratchHandleAddr, uint32_t(g_820F1664));
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r10.u64 = (uint64_t)(int64_t)g_820F1664;
	EntityHandle_Release(ctx, base, scratchHandleAddr);

	EntityHandle_Assign(ctx, base, navigationAddr + 128, scratchHandleAddr);

	// 0x820F0000 + 5732 is 0x820F1664 again
	const uint64_t handleType = (uint64_t)((int64_t)g_820F0000 + 5732);
	STORE32(scratchHandleAddr, (uint32_t)handleType);
	// state the callee may pass on
	ctx.r8.u64 = handleType;
	ctx.r9.s64 = g_820F0000;
	EntityHandle_Release(ctx, base, scratchHandleAddr);

	const uint64_t vectorConstantAddr = (uint64_t)((int64_t)g_834A0000 - 21136);
	navigation->m_AC = 0u;
	navigation->m_A8 = 2u;
	navigation->m_260 = 3u;
	PPCVRegister vectorConstant{};
	SET_V8(vectorConstant, VLOAD((uint32_t)vectorConstantAddr & ~0xF));
	navigation->m_280 = 0u;
	VSTORE(((uint32_t)navigationAddr + 624) & ~0xF, V8(vectorConstant));

	// state the callee may pass on
	ctx.r4.u64 = 2;
	ctx.r5.u64 = vectorConstantAddr;
	ctx.r6.u64 = 624;
	ctx.r7.s64 = g_834A0000;
	n_sub_82192268(ctx, base, navigationAddr);
	n_sub_82260CF0(ctx, base, navigationAddr);
	const uint64_t result = n_sub_821820C8(ctx, base, navigationAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82675048, 0x82675048) { ctx.r3.u64 = n_sub_82675048(ctx, base, ctx.r3.u64); }

uint64_t n_sub_826772A0(CpuState& ctx, uint8_t* base, uint64_t navigationAddr) {
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(43, 0x826772A0)) { ctx.r3.u64 = navigationAddr; __imp__sub_826772A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826772A0);
	uint32_t stack = ctx.r1.u64;
	CECNavigation* navigation = GameObject<CECNavigation>(base, navigationAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t navigationData = CECNavigation_GetNavigationData(ctx, base, navigationAddr);
	if ((uint32_t)navigationData != 0) {
		ctx.fpscr.disableFlushMode();
		n_sub_821E8388(ctx, base, navigationData, double(navigation->m_F0));
	}

	n_sub_82192268(ctx, base, navigationAddr);
	n_sub_82260CF0(ctx, base, navigationAddr);
	CECNavigation_ClearCandidateData(ctx, base, navigationAddr);

	uint64_t node = n_sub_8263EE30(ctx, base, navigation->m_4);
	bool isTargetClass = false;

	if ((uint32_t)node != 0) {
		uint32_t owner = LOAD32((uint32_t)node + 4);
		uint32_t itemArray = LOAD32(owner + 0x50);
		if (itemArray != 0) {
			uint32_t byteOffset = LOAD32((uint32_t)node) << 2;
			node = LOAD32(byteOffset + itemArray);
			if ((uint32_t)node != 0) {
				uint32_t virtualFn = LOAD32(LOAD32((uint32_t)node) + 0x10);
				PPCRegister callTarget{};
				callTarget.u64 = virtualFn;
				ctx.r3.u64 = node;
				ctx.r9.u64 = byteOffset;
				ctx.r10.u64 = virtualFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				node = ctx.r3.u64;

				const uint32_t targetClass = (uint32_t)g_834A0000 - 24976;
				do {
					if ((uint32_t)node == targetClass) {
						isTargetClass = true;
						break;
					}
					node = LOAD32((uint32_t)node + 0x10C);
				} while ((uint32_t)node != 0);
			}
		}
	}

	const uint8_t notTargetClass = isTargetClass ? 0 : 1;
	navigation->m_286 = notTargetClass;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r9 after the call
	ctx.r9.u64 = notTargetClass;
	return node;
}
PROMOTED_ENTRY(43, sub_826772A0, 0x826772A0) { ctx.r3.u64 = n_sub_826772A0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82677638(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(43, 0x82677638)) { ctx.r3.u64 = arg1; __imp__sub_82677638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82677638);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_821B01D0(ctx, base, arg1);
	uint64_t result = n_sub_826728C0(ctx, base, arg1 + 272);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82677638, 0x82677638) { ctx.r3.u64 = n_sub_82677638(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82677670(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(43, 0x82677670)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82677670(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82677670);
	uint32_t stack = ctx.r1.u64;
	uint32_t interfacePtr = (uint32_t)arg2;
	PPCRegister callTarget{};
	uint64_t result{};
	stack = PushStackFrame(base, stack, 112);

	// Invoke the interface's second virtual method, passing the object itself.
	callTarget.u64 = LOAD32(LOAD32(interfacePtr) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	result = ctx.r3.u64;

	if ((int32_t)result == 10) {
		result = n_sub_826776D0(ctx, base, arg1, arg2);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_82677670, 0x82677670) { ctx.r3.u64 = n_sub_82677670(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_826776D0(CpuState& ctx, uint8_t* base, uint64_t arg1, uint32_t arg2) {
	if (!UseLiftedCode(43, 0x826776D0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_826776D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826776D0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	PPCXERRegister flags = ctx.xer;
	// r6-r8 as the lifted code tracks them; handed to the release call below
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;

	uint64_t result = arg1;
	uint32_t animationControl = 0;
	bool hasAnimationControl = false;

	if (LOAD8(arg2 + 4) != 0) {
		uint32_t component = LOAD32((uint32_t)arg1 + 4);
		if ((LOAD32(component + 40) >> 26) & 1) {
			uint32_t keyToSlot = LOAD32(component + 140);
			if (keyToSlot != 0) {
				// the byte table gives the slot index of key 58 directly
				uint32_t index = LOAD8(keyToSlot + 58);
				uint32_t slots = LOAD32(component + 72);
				animationControl = LOAD32(slots + index * 8 + 4);
				hasAnimationControl = true;
			} else {
				// lower_bound for key 58 over the sorted 8-byte (key, value) slots between the pointers at +72 and +76
				uint32_t begin = LOAD32(component + 72);
				uint32_t end = LOAD32(component + 76);
				uint32_t cursor = begin;
				STORE32(stack + 80, 0u);
				uint32_t remaining = end - begin;
				STORE32(stack + 84, begin);
				flags.ca = ((int32_t)remaining < 0) & ((remaining & 0x7) != 0);
				remaining = (int32_t)remaining >> 3;
				if ((int32_t)remaining > 0) {
					do {
						flags.ca = ((int32_t)remaining < 0) & ((remaining & 0x1) != 0);
						uint32_t half = (int32_t)remaining >> 1;
						uint32_t halfOffset = half << 3;
						cursor += halfOffset;
						bool belowKey = (int32_t)LOAD32(cursor) < 58;
						r7Value = belowKey ? 1 : 0;
						r8Value = halfOffset;
						if (belowKey) {
							remaining = remaining - half - 1;
							cursor += 8;
						} else {
							cursor -= halfOffset;
							remaining = half;
						}
					} while ((int32_t)remaining > 0);
					STORE32(stack + 84, cursor);
				}
				r6Value = end;
				// a missing key reads the value field of the slot just past the end
				if (cursor == end || (int32_t)LOAD32(cursor) > 58) {
					animationControl = LOAD32(end + 4);
				} else {
					STORE64(stack + 80, LOAD64(stack + 80));
					animationControl = LOAD32(LOAD32(stack + 84) + 4);
				}
				hasAnimationControl = true;
			}
		}
	}

	if (hasAnimationControl) {
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = flags.ca;
		result = AnimationComponent_ReleaseAnimationControl(ctx, base, animationControl);

		PPCVRegister zeroVector{};
		SET_V8(zeroVector, simde_mm_set1_epi32(int(0x0)));
		STORE8(animationControl + 80, uint8_t(1));
		VSTORE((animationControl + 64u) & ~0xF, V8(zeroVector));
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(43, sub_826776D0, 0x826776D0) { ctx.r3.u64 = n_sub_826776D0(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// Stores the float constant at 0x820994B4 to stack slots and gathers it into two vectors with lvlx loads and
// lane merges, the way the compiled code does; with a 16-byte aligned stack both vectors written to +96 and
// +112 hold four copies of the constant.
void CECNavigation_ClearCandidateData(CpuState& ctx, uint8_t* base, uint32_t navigationAddr) {
	if (!UseLiftedCode(43, 0x82677910)) { ctx.r3.u64 = navigationAddr; __imp__sub_82677910(ctx, base); return; }
	LiftedFrame frame(0x82677910);
	uint32_t stack = ctx.r1.u64;

	// lvlx: the bytes from addr to the end of its 16-byte block, moved to the start of the vector; the rest is zero.
	auto loadVectorLeft = [&](uint32_t addr) -> PPCVRegister {
		PPCVRegister loaded{};
		SET_V8(loaded, simde_mm_shuffle_epi8(
			simde_mm_load_si128((simde__m128i*)RAW(addr & ~0xF)),
			simde_mm_load_si128((simde__m128i*)&VectorMaskL[(addr & 0xF) * 16])));
		return loaded;
	};

	ctx.fpscr.disableFlushMode();
	const double fillValue = double(LOAD_F32(0x820994B4u));

	STORE_F32(stack - 8, float(fillValue));
	STORE_F32(stack - 4, float(fillValue));

	PPCVRegister vecA = loadVectorLeft(stack - 8);
	PPCVRegister vecB = loadVectorLeft(stack - 4);

	STORE_F32(stack - 16, float(fillValue));
	STORE_F32(stack - 4, float(fillValue));
	STORE_F32(stack - 8, float(fillValue));

	SET_VF(vecB, simde_mm_blend_ps(VF(vecB), simde_mm_permute_ps(VF(vecA), 57), 4));

	PPCVRegister vecC = loadVectorLeft(stack - 16);
	PPCVRegister vecD = loadVectorLeft(stack - 4);
	PPCVRegister vecE = loadVectorLeft(stack - 8);

	STORE_F32(stack - 12, float(fillValue));

	PPCVRegister vecF = loadVectorLeft(stack - 12);

	STORE_F32(stack - 12, float(fillValue));
	STORE_F32(stack - 16, float(fillValue));

	SET_VF(vecE, simde_mm_blend_ps(VF(vecE), simde_mm_permute_ps(VF(vecD), 57), 4));

	PPCVRegister vecG = loadVectorLeft(stack - 12);
	SET_VF(vecF, simde_mm_blend_ps(VF(vecF), simde_mm_permute_ps(VF(vecC), 57), 4));

	PPCVRegister vecH = loadVectorLeft(stack - 16);
	SET_VF(vecH, simde_mm_blend_ps(VF(vecH), simde_mm_permute_ps(VF(vecG), 57), 4));

	SET_VF(vecE, simde_mm_blend_ps(VF(vecE), simde_mm_permute_ps(VF(vecB), 78), 3));
	SET_VF(vecF, simde_mm_blend_ps(VF(vecF), simde_mm_permute_ps(VF(vecH), 78), 3));

	VSTORE((navigationAddr + 112u) & ~0xFu, V8(vecE));
	VSTORE((navigationAddr + 96u) & ~0xFu, V8(vecF));

	// callers read these registers after the call
	ctx.r4.u64 = (uint64_t)stack - 4;
	ctx.r5.u64 = (uint64_t)stack - 4;
	ctx.r6.u64 = (uint64_t)stack - 8;
	ctx.r7.u64 = (uint64_t)stack - 16;
	ctx.r8.u64 = (uint64_t)stack - 12;
	ctx.r9.u64 = 112;
	ctx.r10.u64 = 96;
	ctx.v7 = vecE;
	ctx.v8 = vecD;
	ctx.v9 = vecB;
	ctx.v10 = vecA;
	ctx.v11 = vecH;
	ctx.v12 = vecG;
	ctx.v13 = vecF;
}
PROMOTED_ENTRY(43, sub_82677910, 0x82677910) { CECNavigation_ClearCandidateData(ctx, base, ctx.r3.u32); }
