// CECMood (vtable 0x82004460): methods of the class as readable C++.
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

uint32_t n_sub_82186418(CpuState& ctx, uint8_t* base, uint32_t moodAddr) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t str_TXT_820EA7C4_B_ = int32_t(0x820EA7C4);
	constexpr int32_t str_TXT_82000F58_B_ = int32_t(0x82000F58);
	if (!UseLiftedCode(0, 0x82186418)) { ctx.r3.u64 = moodAddr; __imp__sub_82186418(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82186418);
	uint32_t stack = ctx.r1.u64;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);
	uint64_t result = moodAddr;
	// r4, cr0 and xer.ca as callers see them after the return
	uint64_t callerR4 = ctx.r4.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 144);
	uint32_t scratch = stack + 80;  // lookup scratch, later reused as the IdRef storage
	uint32_t owner = mood->m_4;

	// Look up a component instance by type in the owner's sorted (type, instance) table, using the
	// cached index when it exists and a lower_bound search otherwise; the search sets cr0 and xer.ca.
	auto findComponent = [&](int32_t componentType) -> uint32_t {
		uint32_t cached = LOAD32(owner + 140);
		if (cached != 0) {
			uint32_t index = LOAD8(cached + componentType);
			return LOAD32(LOAD32(owner + 72) + index * 8 + 4);
		}
		uint32_t begin = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		STORE32(scratch, 0);
		STORE32(scratch + 4, begin);
		int32_t byteCount = (int32_t)(end - begin);
		int32_t count = byteCount >> 3;
		flags.ca = (byteCount < 0) & ((byteCount & 0x7) != 0);
		compare0.compare<int32_t>(count, 0, flags);
		if (count > 0) {
			do {
				int32_t half = count >> 1;
				uint32_t mid = begin + ((uint32_t)half << 3);
				if ((int32_t)LOAD32(mid) < componentType) {
					begin = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(scratch + 4, begin);
		}
		if (begin != end && (int32_t)LOAD32(begin) <= componentType) {
			STORE64(scratch, LOAD64(scratch));
			return LOAD32(LOAD32(scratch + 4) + 4);
		}
		return LOAD32(end + 4);
	};

	if (((LOAD32(owner + 40) >> 4) & 1) != 0) {
		uint32_t healthComp = findComponent(36);
		ctx.fpscr.disableFlushMode();
		double currentHealth = double(LOAD_F32(healthComp + 20));
		double maxHealth = double(LOAD_F32(healthComp + 28));
		uint32_t moodConstants = uint32_t(g_820994C0);
		double healthFloor = double(LOAD_F32(moodConstants - 12));
		if (currentHealth != maxHealth && currentHealth > healthFloor && ((LOAD32(owner + 40) >> 15) & 1) != 0) {
			uint32_t effectsComp = findComponent(47);
			ctx.fpscr.disableFlushMode();
			double healthFraction = double(float(currentHealth / maxHealth));
			double damageAmount = double(float(double(LOAD_F32(moodConstants)) - healthFraction));
			uint32_t effectsId = LOAD32(effectsComp + 736);
			callerR4 = effectsId;

			ctx.r1.u64 = stack;
			ctx.xer.ca = flags.ca;
			result = IdRef_ConstructFromId(ctx, base, scratch, effectsId);
			if (LOAD32(scratch) != 0) {
				ctx.r4.u64 = effectsId;  // state the callee may pass on
				uint64_t idRef = IdRef_Get(ctx, base, scratch);
				result = GameDB_ReadU32Field(ctx, base, idRef, str_TXT_82000F58_B_);
				callerR4 = ctx.r4.u64;
				if ((uint32_t)result != 0) {
					result = GameDB_ReadU32Field(ctx, base, result, str_TXT_820EA7C4_B_);
					callerR4 = ctx.r4.u64;
					if ((uint32_t)result != 0) {
						STORE32(scratch + 4, 0);
						STORE32(scratch + 8, 0);
						STORE32(scratch + 12, 0);
						// state the callee may pass on
						ctx.f12.f64 = healthFloor;
						ctx.f13.f64 = healthFraction;
						ctx.cr0.lt = compare0.lt;
						ctx.cr0.gt = compare0.gt;
						ctx.cr0.eq = compare0.eq;
						ctx.cr0.so = compare0.so;
						n_sub_821EEEF8(ctx, base, result, scratch);

						ctx.fpscr.disableFlushMode();
						n_sub_827E0C68(ctx, base, effectsComp + 236, scratch, damageAmount);
						double m24Delta = ctx.f1.f64;
						ctx.fpscr.disableFlushMode();
						mood->m_24 = float(m24Delta + double(mood->m_24));

						n_sub_827E0C68(ctx, base, effectsComp + 252, scratch, damageAmount);
						double m28Delta = ctx.f1.f64;
						ctx.fpscr.disableFlushMode();
						double previousM28 = double(mood->m_28);
						double newM28 = double(float(m28Delta + previousM28));
						mood->m_28 = float(newM28);

						// state the callee may pass on
						ctx.f11.f64 = newM28;
						ctx.f12.f64 = previousM28;
						result = Vector_FreeAndReset(ctx, base, scratch);
						// leave r4, cr0 and xer.ca as this call left them
						callerR4 = ctx.r4.u64;
						compare0.lt = ctx.cr0.lt;
						compare0.gt = ctx.cr0.gt;
						compare0.eq = ctx.cr0.eq;
						compare0.so = ctx.cr0.so;
						flags.ca = ctx.xer.ca;
					}
				}
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4, cr0 and xer.ca after the call
	ctx.r4.u64 = callerR4;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(0, sub_82186418, 0x82186418) { ctx.r3.u64 = n_sub_82186418(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8219CA78(CpuState& ctx, uint8_t* base, uint32_t moodAddr) {
	constexpr int32_t str_TXT_8200182C_B_ = int32_t(0x8200182C);
	constexpr int32_t str_TXT_82001D5C_B_ = int32_t(0x82001D5C);
	constexpr int32_t str_TXT_82000F58_B_ = int32_t(0x82000F58);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(1, 0x8219CA78)) { ctx.r3.u64 = moodAddr; __imp__sub_8219CA78(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8219CA78);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = moodAddr;
	// r4, cr0 and xer.ca as callers see them after the return
	uint64_t callerR4 = ctx.r4.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);

	stack = PushStackFrame(base, stack, 160);

	uint32_t startTick = mood->m_78;
	uint32_t owner = mood->m_4;
	if ((int32_t)startTick > 0 && ((LOAD32(owner + 40) >> 15) & 1) != 0) {
		// Component of type 47 from the owner's sorted (type, instance) table: the cached index when
		// it exists, otherwise a lower_bound search, which sets cr0 and xer.ca.
		uint32_t effectsComp;
		uint32_t cached = LOAD32(owner + 140);
		if (cached != 0) {
			uint32_t index = LOAD8(cached + 47);
			effectsComp = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
		} else {
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			int32_t byteCount = (int32_t)(end - begin);
			int32_t count = byteCount >> 3;
			flags.ca = (byteCount < 0) & ((byteCount & 0x7) != 0);
			compare0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t mid = begin + ((uint32_t)half << 3);
					if ((int32_t)LOAD32(mid) < 47) {
						begin = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 47) {
				STORE64(stack + 80, LOAD64(stack + 80));
				effectsComp = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				effectsComp = LOAD32(end + 4);
			}
		}

		uint32_t effectsId = LOAD32(effectsComp + 736);
		callerR4 = effectsId;
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = IdRef_ConstructFromId(ctx, base, stack + 80, effectsId);
		if (LOAD32(stack + 80) != 0) {
			ctx.r4.u64 = effectsId;  // state the callee may pass on
			uint64_t idRef = IdRef_Get(ctx, base, stack + 80);
			uint64_t TXT_82000F58_L_ = GameDB_ReadU32Field(ctx, base, idRef, str_TXT_82000F58_B_);
			result = TXT_82000F58_L_;
			callerR4 = ctx.r4.u64;
			if ((uint32_t)TXT_82000F58_L_ != 0) {
				uint64_t TXT_8200182C_L_ = GameDB_ReadU32Field(ctx, base, TXT_82000F58_L_, str_TXT_8200182C_B_);
				result = TXT_8200182C_L_;
				callerR4 = ctx.r4.u64;
				if ((uint32_t)TXT_8200182C_L_ != 0) {
					result = GameDB_GetFloatByName(ctx, base, TXT_82000F58_L_, str_TXT_82001D5C_B_);
					callerR4 = ctx.r4.u64;
					double effectSeconds = ctx.f1.f64;

					// The effect fades linearly: the counter at 0x8331950C minus the start value in m_78,
					// over the duration scaled by the double at 0x83319510.
					uint32_t moodConstants = uint32_t(g_820A0000 - 27456);  // 0x820994C0
					ctx.fpscr.disableFlushMode();
					double duration = double(float(effectSeconds * LOAD_F64(0x83319510u)));
					double lowerLimit = double(LOAD_F32(moodConstants - 12));
					if (duration > lowerLimit) {
						double fullWeight = double(LOAD_F32(moodConstants));
						// integer-to-double conversion through the stack, as the original does it
						int32_t elapsedTicks = (int32_t)(LOAD32(0x8331950Cu) - startTick);
						STORE64(stack + 80, (uint64_t)(int64_t)elapsedTicks);
						PPCRegister elapsedBits{};
						elapsedBits.f64 = LOAD_F64(stack + 80);
						double elapsed = double(elapsedBits.s64);
						double elapsedSingle = double(float(elapsed));
						double elapsedFraction = double(float(elapsedSingle / duration));
						double weight = double(float(fullWeight - elapsedFraction));
						if (weight > lowerLimit) {
							STORE32(stack + 84, 0);
							STORE32(stack + 88, 0);
							STORE32(stack + 92, 0);
							// state the callee may pass on
							ctx.f8.f64 = elapsedFraction;
							ctx.f9.f64 = elapsedSingle;
							ctx.f10.f64 = elapsed;
							ctx.f11 = elapsedBits;
							ctx.f12.f64 = fullWeight;
							ctx.f13.f64 = lowerLimit;
							ctx.cr0.lt = compare0.lt;
							ctx.cr0.gt = compare0.gt;
							ctx.cr0.eq = compare0.eq;
							ctx.cr0.so = compare0.so;
							n_sub_821EEEF8(ctx, base, TXT_8200182C_L_, stack + 80);

							ctx.fpscr.disableFlushMode();
							n_sub_827E0C68(ctx, base, effectsComp + 236, stack + 80, weight);
							double m24Delta = ctx.f1.f64;
							ctx.fpscr.disableFlushMode();
							mood->m_24 = float(m24Delta + double(mood->m_24));

							n_sub_827E0C68(ctx, base, effectsComp + 252, stack + 80, weight);
							double m28Delta = ctx.f1.f64;
							ctx.fpscr.disableFlushMode();
							double previousM28 = double(mood->m_28);
							double newM28 = double(float(m28Delta + previousM28));
							mood->m_28 = float(newM28);

							// state the callee may pass on
							ctx.f11.f64 = newM28;
							ctx.f12.f64 = previousM28;
							result = Vector_FreeAndReset(ctx, base, stack + 80);
							// leave r4, cr0 and xer.ca as this call left them
							callerR4 = ctx.r4.u64;
							compare0.lt = ctx.cr0.lt;
							compare0.gt = ctx.cr0.gt;
							compare0.eq = ctx.cr0.eq;
							compare0.so = ctx.cr0.so;
							flags.ca = ctx.xer.ca;
						}
					}
				}
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4, cr0 and xer.ca after the call
	ctx.r4.u64 = callerR4;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(1, sub_8219CA78, 0x8219CA78) { ctx.r3.u64 = n_sub_8219CA78(ctx, base, ctx.r3.u32); }

uint64_t n_sub_821F0C60(CpuState& ctx, uint8_t* base, uint64_t moodAddr, uint64_t object, uint64_t virtualArg) {
	if (!UseLiftedCode(4, 0x821F0C60)) { ctx.r3.u64 = moodAddr; ctx.r4.u64 = object; ctx.r8.u64 = virtualArg; __imp__sub_821F0C60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821F0C60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Call the object's second virtual function; a result of 8 passes on to sub_8291C680.
	uint32_t virtualFn = LOAD32(LOAD32((uint32_t)object) + 4);
	PPCRegister callTarget{};
	callTarget.u64 = virtualFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = object;
	ctx.r4.u64 = object;
	ctx.r8.u64 = virtualArg;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;

	if ((int32_t)result == 8) {
		ctx.r4.u64 = object;  // state the callee may pass on
		result = n_sub_8291C680(ctx, base, moodAddr, ctx.r8.u64);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821F0C60, 0x821F0C60) { ctx.r3.u64 = n_sub_821F0C60(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t n_sub_822B0118(CpuState& ctx, uint8_t* base, uint64_t moodAddr) {
	if (!UseLiftedCode(12, 0x822B0118)) { ctx.r3.u64 = moodAddr; __imp__sub_822B0118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B0118);
	uint32_t stack = ctx.r1.u64;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);
	stack = PushStackFrame(base, stack, 112);

	PPCXERRegister flags = ctx.xer;
	uint64_t result = moodAddr;
	if (LOAD8((uint32_t)moodAddr + 129) != 0) {
		ctx.r1.u64 = stack;
		n_sub_822A0DE8(ctx, base, moodAddr);
		CECMood_Update(ctx, base, moodAddr);
		n_sub_822AFF78(ctx, base, moodAddr);
		result = CECMood_UpdateMoodModifiers(ctx, base, moodAddr);
		flags.ca = ctx.xer.ca;

		// CECMood_UpdateCurrentMood receives r6, r8 and xer.ca as the lookup below leaves them;
		// r6 starts as what CECMood_UpdateMoodModifiers left there.
		uint64_t passedR6 = ctx.r6.u64;
		uint64_t passedR8;

		uint32_t owner = mood->m_4;
		if (((LOAD32(owner + 36) >> 26) & 1) != 0) {
			// Component of type 26 from the owner's sorted (type, instance) table: the cached index
			// when it exists, otherwise a lower_bound search.
			uint32_t component;
			uint32_t cached = LOAD32(owner + 140);
			if (cached != 0) {
				passedR8 = (uint64_t)((uint32_t)LOAD8(cached + 26) << 3) + (uint64_t)LOAD32(owner + 72);
				component = LOAD32((uint32_t)passedR8 + 4);
			} else {
				uint32_t begin = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				passedR6 = end;
				STORE32(stack + 80, 0u);
				passedR8 = (uint64_t)end - (uint64_t)begin;
				STORE32(stack + 84, begin);
				int32_t byteCount = (int32_t)(uint32_t)passedR8;
				int32_t count = byteCount >> 3;
				flags.ca = (byteCount < 0) & ((byteCount & 0x7) != 0);
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						uint32_t midOffset = (uint32_t)half << 3;
						passedR8 = midOffset;
						uint32_t mid = begin + midOffset;
						if ((int32_t)LOAD32(mid) < 26) {
							count = count - half - 1;
							begin = mid + 8;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= 26) {
					STORE64(stack + 80, LOAD64(stack + 80));
					component = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					component = LOAD32(end + 4);
				}
			}

			uint32_t componentState = LOAD32(component + 156);
			if (componentState != 5 && componentState != 25) {
				// state the callee may pass on
				ctx.r6.u64 = passedR6;
				ctx.r8.u64 = passedR8;
				ctx.xer.ca = flags.ca;
				result = CECMood_UpdateCurrentMood(ctx, base, moodAddr);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822B0118, 0x822B0118) { ctx.r3.u64 = n_sub_822B0118(ctx, base, ctx.r3.u64); }

uint64_t CECMood_UpdateCurrentMood(CpuState& ctx, uint8_t* base, uint64_t moodAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_82099334 = int32_t(0x82099334);
	constexpr int32_t str_TXT_820D95CC_B_ = int32_t(0x820D95CC);
	constexpr int32_t str_TXT_820EA864_B_ = int32_t(0x820EA864);
	constexpr int32_t str_TXT_820EA86C_B_ = int32_t(0x820EA86C);
	constexpr int32_t str_TXT_820EA874_B_ = int32_t(0x820EA874);
	if (!UseLiftedCode(12, 0x822B1428)) { ctx.r3.u64 = moodAddr; __imp__sub_822B1428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B1428);
	uint32_t stack = ctx.r1.u64;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);
	stack = PushStackFrame(base, stack, 128);

	if (LOAD8((uint32_t)moodAddr + 128) != 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return moodAddr;
	}

	// The stronger of the two drives m_24 and m_28 becomes the mood level m_C; m_10 records which.
	ctx.fpscr.disableFlushMode();
	double driveA = double(mood->m_24);
	uint32_t previousKind = mood->m_10;
	double driveB = double(mood->m_28);
	double driveBMagnitude = fabs(driveB);
	if (!(fabs(driveA) < driveBMagnitude)) {
		mood->m_C = float(driveA);
		if (previousKind != 0) mood->m_10 = 0;
	} else {
		ctx.fpscr.disableFlushMode();
		mood->m_C = float(driveB);
		if (previousKind != 1) mood->m_10 = 1;
	}

	ctx.fpscr.disableFlushMode();
	double levelMagnitude = fabs(double(mood->m_C));
	double levelThreshold = double(mood->m_4C);
	if (levelMagnitude < levelThreshold) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return moodAddr;
	}

	uint32_t moodName = stack + 80;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.f11.f64 = driveBMagnitude;
	ctx.f12.f64 = levelThreshold;
	ctx.f13.f64 = levelMagnitude;
	CCharString_ConstructFromCStr(ctx, base, moodName, g_82000C98, -1);
	// r6 and xer.ca as the constructor left them, until the component lookup below changes them
	uint64_t passedR6 = ctx.r6.u64;
	PPCXERRegister flags = ctx.xer;

	uint32_t moodTuning = uint32_t(g_82099334);
	uint32_t moodKind = mood->m_10;
	if (moodKind == 0) {
		ctx.fpscr.disableFlushMode();
		double moodLevel = double(mood->m_C);
		if (moodLevel > double(LOAD_F32(moodTuning + 384))) {
			// state the callee may pass on
			ctx.r5.u64 = uint64_t(g_82099334);
			ctx.f13.f64 = moodLevel;
			CCharString_AssignFromCStr(ctx, base, moodName, str_TXT_820EA864_B_);
			mood->m_7C = 1;
		} else {
			uint32_t owner = mood->m_4;
			uint32_t typeFlag = (LOAD32(owner + 40) >> 15) & 1;
			if (typeFlag == 0) {
				ctx.f13.f64 = moodLevel;  // state the release call may pass on
			} else {
				// Component of type 47 from the owner's sorted (type, instance) table: the cached index
				// when it exists, otherwise a lower_bound search; r6, r8 and xer.ca end up as the
				// search leaves them and go on to the next call.
				uint64_t passedR8 = typeFlag;
				uint32_t component;
				uint32_t cached = LOAD32(owner + 140);
				if (cached != 0) {
					uint32_t index = LOAD8(cached + 47);
					component = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
				} else {
					uint32_t begin = LOAD32(owner + 72);
					uint32_t end = LOAD32(owner + 76);
					passedR6 = end;
					STORE32(stack + 88, 0);
					STORE32(stack + 92, begin);
					int32_t byteCount = (int32_t)(end - begin);
					int32_t count = byteCount >> 3;
					flags.ca = (byteCount < 0) & ((byteCount & 0x7) != 0);
					if (count > 0) {
						do {
							int32_t half = count >> 1;
							uint32_t midOffset = (uint32_t)half << 3;
							passedR8 = midOffset;
							uint32_t mid = begin + midOffset;
							if ((int32_t)LOAD32(mid) < 47) {
								count = count - half - 1;
								begin = mid + 8;
							} else {
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 92, begin);
					}
					if (begin != end && (int32_t)LOAD32(begin) <= 47) {
						STORE64(stack + 88, LOAD64(stack + 88));
						component = LOAD32(LOAD32(stack + 92) + 4);
					} else {
						component = LOAD32(end + 4);
					}
				}

				ctx.fpscr.disableFlushMode();
				double componentValue = double(LOAD_F32(component + 748));
				bool TXT_820EA86C_L_ = !(componentValue < double(LOAD_F32(moodTuning)));
				// state the callee may pass on
				ctx.r5.u64 = uint64_t(g_82099334);
				ctx.r6.u64 = passedR6;
				ctx.r8.u64 = passedR8;
				ctx.f13.f64 = componentValue;
				ctx.xer.ca = flags.ca;
				if (TXT_820EA86C_L_) {
					CCharString_AssignFromCStr(ctx, base, moodName, str_TXT_820EA86C_B_);
					mood->m_7C = 2;
				} else {
					CCharString_AssignFromCStr(ctx, base, moodName, str_TXT_820EA874_B_);
					mood->m_7C = 3;
				}
			}
		}
	} else if (moodKind == 1) {
		ctx.fpscr.disableFlushMode();
		double moodLevel = double(mood->m_C);
		ctx.f13.f64 = moodLevel;  // state the callee may pass on
		if (moodLevel > double(LOAD_F32(0x820994B4u))) {
			CCharString_AssignFromCStr(ctx, base, moodName, str_TXT_820D95CC_B_);
			mood->m_7C = 4;
		} else {
			CCharString_AssignFromCStr(ctx, base, moodName, str_TXT_820EA864_B_);
			mood->m_7C = 1;
		}
	}

	uint64_t releaseResult = CCharString_ReleaseAndDecGlobalCountA(ctx, base, moodName);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(12, sub_822B1428, 0x822B1428) { ctx.r3.u64 = CECMood_UpdateCurrentMood(ctx, base, ctx.r3.u64); }

uint64_t CECMood_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C90A8_B_ = int32_t(0x820C90A8);
	if (!UseLiftedCode(65, 0x8291ABF8)) { ctx.r3.u64 = classNameString; __imp__sub_8291ABF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8291ABF8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, uint64_t(str_TXT_820C90A8_B_), -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(65, sub_8291ABF8, 0x8291ABF8) { ctx.r3.u64 = CECMood_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8291B2D0(CpuState& ctx, uint8_t* base, uint64_t moodAddr, uint64_t arg2) {
	constexpr int32_t g_820991F0 = int32_t(0x820991F0);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_8349F6B0 = int32_t(0x8349F6B0);
	if (!UseLiftedCode(65, 0x8291B2D0)) { ctx.r3.u64 = moodAddr; ctx.r8.u64 = arg2; __imp__sub_8291B2D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8291B2D0);
	uint32_t stack = ctx.r1.u64;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);
	stack = PushStackFrame(base, stack, 288);

	// Copy every handle of the mood's list (other than -1) into the ring allocator at
	// LOAD32(g_8349F6B0 + 4), then pass the list to sub_821B1DC0.
	uint64_t listAddr = moodAddr + 132;
	uint32_t list = (uint32_t)listAddr;
	uint32_t cursor = mood->m_88;
	uint32_t listEnd = mood->m_8C;
	if (cursor > listEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	uint32_t listBegin;
	for (;;) {
		uint32_t currentEnd = LOAD32(list + 8);
		listBegin = LOAD32(list + 4);
		if (listBegin > currentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (cursor == currentEnd)
			break;
		if (cursor >= listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t handle = LOAD32(cursor);
		if ((int32_t)handle != -1) {
			uint32_t ring = LOAD32(uint32_t(g_8349F6B0) + 4);
			ctx.r1.u64 = stack;
			ctx.r8.u64 = arg2;  // state the callee may pass on
			RingAllocator_PushBack(ctx, base, ring, 4);
			uint32_t slot = RingAllocator_AllocateAligned(ctx, base, ring, 4, 4);
			arg2 = ctx.r8.u64;
			if (slot != 0)
				STORE32(slot, handle);
			STORE32(LOAD32(ring + 44), LOAD32(ring + 32));
			STORE32(ring + 40, LOAD32(ring + 32));
		}
		listEnd = LOAD32(list + 8);
		if (cursor >= listEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		cursor += 4;
	}

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r9.u64 = listBegin;
	ctx.r10.u64 = listEnd;
	uint64_t result = n_sub_821B1DC0(ctx, base, list, arg2);

	if (LOAD8(0x83496BB5u) == 0) {
		stack = PopStackFrame(stack, 288);
		ctx.r1.u64 = stack;
		return result;
	}

	// The entity behind the handle at +104 of the first entry of a manager's array; a handle whose
	// entity is gone is released.
	uint32_t globals = uint32_t(g_83490000);
	uint32_t managerChild = LOAD32(LOAD32(globals + 26912) + 12);
	uint32_t entryArray = LOAD32(LOAD32(managerChild + 88) + 4);
	uint32_t firstEntry = LOAD32(entryArray);
	result = (uint64_t)firstEntry + 104;
	uint32_t entitySlot = LOAD32(firstEntry + 108);
	uint32_t entity = 0;
	if (entitySlot != 0) {
		entity = LOAD32(entitySlot);
		if (entity == 0) {
			// state the callee may pass on
			ctx.r9.u64 = entryArray;
			ctx.r10.u64 = 0;
			result = EntityHandle_Release(ctx, base, result);
		}
	}

	if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
		PPCRegister callTarget{};
		PPCVRegister ownerVec{}, laneMask{}, raisedLane{}, raisedOwnerVec{};
		PPCVRegister cameraVec{}, entityVec{}, toEntity{}, fillLane{}, flatToEntity{};
		PPCVRegister direction{}, dirShifted{}, fillShifted{}, fillLanes{}, negXLane{};
		uint32_t unalignedAddr;

		// Vector from virtual function +64 of the object at +124 of the mood's owner.
		uint32_t ownerVecAddr = stack + 112;
		uint32_t ownerObject = LOAD32((uint32_t)mood->m_4 + 124);
		uint32_t ownerVtable = LOAD32(ownerObject);
		uint32_t ownerGetVec = LOAD32(ownerVtable + 64);
		callTarget.u64 = ownerGetVec;
		ctx.r3.u64 = ownerVecAddr;
		ctx.r4.u64 = ownerObject;
		ctx.r9.u64 = ownerGetVec;
		ctx.r10.u64 = ownerVtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t constants = uint32_t(g_820A0000);
		uint32_t manager = LOAD32(globals + 26912);
		uint32_t tuning = constants - 27468;  // 0x820994B4
		uint32_t laneMaskAddr = uint32_t(g_820991F0);

		// Element 2 of that vector gets the offset at tuning + 8236 added (vperm with the mask at g_820991F0).
		SET_V8(ownerVec, VLOAD(ownerVecAddr & ~0xF));
		VSTORE((stack + 96) & ~0xF, V8(ownerVec));
		ctx.fpscr.disableFlushMode();
		double ownerElement2 = double(LOAD_F32(stack + 104));
		double raisedElement2 = double(float(ownerElement2 + double(LOAD_F32(tuning + 8236))));
		SET_V8(laneMask, VLOAD(laneMaskAddr & ~0xF));
		STORE_F32(stack + 80, float(raisedElement2));
		unalignedAddr = stack + 80;
		SET_V8(raisedLane, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		SET_V8(raisedOwnerVec, rex::ppc::simde_mm_perm_epi8_(V8(ownerVec), V8(raisedLane), V8(laneMask)));
		VSTORE(ownerVecAddr & ~0xF, V8(raisedOwnerVec));

		uint32_t player = LOAD32(LOAD32(manager + 12) + 156);
		ctx.r4.u64 = ownerVecAddr;  // state the callee may pass on
		uint64_t camera = Player_GetCameraAssociatedWithPlayer(ctx, base, player);
		// state the callee may pass on
		ctx.f12.f64 = raisedElement2;
		ctx.f13.f64 = ownerElement2;
		ctx.v7 = laneMask;
		ctx.v12 = raisedOwnerVec;
		ctx.v13 = raisedLane;
		uint32_t cameraTransform = Player_GetCameraTransform(ctx, base, stack + 160, camera);

		// Vector from virtual function +64 of the object at +124 of the entity.
		uint32_t entityObject = LOAD32(entity + 124);
		uint32_t entityVecAddr = stack + 144;
		uint32_t entityGetVec = LOAD32(LOAD32(entityObject) + 64);
		callTarget.u64 = entityGetVec;
		ctx.r3.u64 = entityVecAddr;
		ctx.r4.u64 = entityObject;
		ctx.r10.u64 = entityGetVec;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// Difference from the camera transform's first vector to the entity's vector, element 2
		// replaced by the value at tuning, normalized in place at stack + 96.
		SET_V8(cameraVec, VLOAD(cameraTransform & ~0xF));
		ctx.fpscr.disableFlushMode();
		double fillValue = double(LOAD_F32(tuning));
		SET_V8(laneMask, VLOAD(laneMaskAddr & ~0xF));
		STORE_F32(stack + 80, float(fillValue));
		uint32_t directionAddr = stack + 96;
		SET_V8(entityVec, VLOAD(entityVecAddr & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(toEntity, simde_mm_sub_ps(VF(entityVec), VF(cameraVec)));
		unalignedAddr = stack + 80;
		SET_V8(fillLane, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		ctx.fpscr.disableFlushModeUnconditional();
		double normalizeArg = double(LOAD_F32(0x82099AE0u));
		SET_V8(flatToEntity, rex::ppc::simde_mm_perm_epi8_(V8(toEntity), V8(fillLane), V8(laneMask)));
		VSTORE(directionAddr & ~0xF, V8(flatToEntity));
		Vec4_NormalizeInPlace_ReturnLength(ctx, base, directionAddr, normalizeArg);

		// Rearrange the direction's elements together with fill values and its negated element 0.
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 80, float(fillValue));
		STORE_F32(stack + 84, float(fillValue));
		double itemParam = double(LOAD_F32(tuning - 392));
		double moodDrive = double(mood->m_24);
		SET_V8(direction, VLOAD(directionAddr & ~0xF));
		VSTORE((stack + 128) & ~0xF, V8(direction));
		unalignedAddr = stack + 132;
		SET_V8(dirShifted, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		VSTORE((stack + 128) & ~0xF, V8(direction));
		double directionElement0 = double(LOAD_F32(stack + 128));
		unalignedAddr = stack + 84;
		SET_V8(fillShifted, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		unalignedAddr = stack + 80;
		SET_V8(fillLanes, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		SET_VF(fillShifted, simde_mm_blend_ps(VF(fillShifted), simde_mm_permute_ps(VF(fillLanes), 57), 4));
		double itemParamF2 = double(LOAD_F32(constants - 18828));
		STORE_F32(stack + 80, float(-directionElement0));
		unalignedAddr = stack + 80;
		SET_V8(negXLane, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(unalignedAddr & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(unalignedAddr & 0xF) * 16])));
		SET_VF(dirShifted, simde_mm_blend_ps(VF(dirShifted), simde_mm_permute_ps(VF(negXLane), 57), 4));
		SET_VF(dirShifted, simde_mm_blend_ps(VF(dirShifted), simde_mm_permute_ps(VF(fillShifted), 78), 3));
		VSTORE(directionAddr & ~0xF, V8(dirShifted));

		// Two items (kinds 1 and 2, with m_24 and m_28) are created and pushed onto the mood's list.
		// state the callee may pass on
		ctx.f2.f64 = itemParamF2;
		ctx.v3 = negXLane;
		ctx.v4 = dirShifted;
		ctx.v5 = fillShifted;
		ctx.v6 = fillLanes;
		uint32_t firstItem = n_sub_8291B128(ctx, base, ownerVecAddr, directionAddr, 1, itemParam, moodDrive);
		STORE32(stack + 84, firstItem);
		Vector_PushBackU32(ctx, base, listAddr, stack + 84);

		ctx.fpscr.disableFlushMode();
		itemParamF2 = double(LOAD_F32(constants - 18828));
		itemParam = double(LOAD_F32(tuning - 392));
		moodDrive = double(mood->m_28);
		ctx.f2.f64 = itemParamF2;  // state the callee may pass on
		uint32_t secondItem = n_sub_8291B128(ctx, base, ownerVecAddr, directionAddr, 2, itemParam, moodDrive);
		STORE32(stack + 84, secondItem);
		result = Vector_PushBackU32(ctx, base, listAddr, stack + 84);
	}

	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(65, sub_8291B2D0, 0x8291B2D0) { ctx.r3.u64 = n_sub_8291B2D0(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_8291C540(CpuState& ctx, uint8_t* base, uint64_t moodAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(65, 0x8291C540)) { ctx.r3.u64 = moodAddr; __imp__sub_8291C540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8291C540);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECMood* mood = GameObject<CECMood>(base, moodAddr);

	stack = PushStackFrame(base, stack, 144);

	// Three shared handle lists sit back to back at mood + 0x50, + 0x5C and + 0x68.
	uint64_t handleList = moodAddr + 80;
	for (int32_t remaining = 2; remaining != 0; --remaining, handleList += 12) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		SharedHandleList_Clear(ctx, base, handleList);
		flags.ca = remaining > 0;
	}
	ctx.xer.ca = flags.ca;
	SharedHandleList_Clear(ctx, base, moodAddr + 104);

	// Handle vector at mood + 0x84 (begin pointer at 0x88, end pointer at 0x8C), walked with
	// checked-iterator traps; every handle other than -1 is inserted into a list of a global object.
	uint32_t handles = (uint32_t)moodAddr + 132;
	uint32_t cursor = mood->m_88;
	uint32_t checkedEnd = mood->m_8C;
	if (cursor > checkedEnd)
		ppc_trap(ctx, base, 22);
	for (;;) {
		uint32_t end = LOAD32(handles + 8);
		if (LOAD32(handles + 4) > end)
			ppc_trap(ctx, base, 22);
		if (cursor == end)
			break;
		if (cursor >= checkedEnd)
			ppc_trap(ctx, base, 22);

		uint32_t handle = LOAD32(cursor);
		STORE32(stack + 80, handle);
		if ((int32_t)handle != -1) {
			uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t subsystem = LOAD32(globalObject + 12);
			uint32_t listOwner = LOAD32(LOAD32(subsystem + 88) + 4);
			uint32_t list = listOwner + 192;
			// Insert position: the pair (list, word at list + 4) built on the stack.
			STORE32(stack + 88, list);
			STORE32(stack + 92, LOAD32(listOwner + 196));
			uint64_t position = LOAD64(stack + 88);
			List_InsertNodeCopyWord(ctx, base, list, position, stack + 80);
		}

		checkedEnd = LOAD32(handles + 8);
		if (cursor >= checkedEnd)
			ppc_trap(ctx, base, 22);
		cursor += 4;
	}

	// Empty the vector: when it holds elements its end pointer is set back to begin.
	uint32_t begin = LOAD32(handles + 4);
	uint32_t end = LOAD32(handles + 8);
	if (begin > end) {
		ppc_trap(ctx, base, 22);
		ppc_trap(ctx, base, 22);
	}
	if (begin != end)
		STORE32(handles + 8, begin);

	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t subsystem = LOAD32(globalObject + 12);
	uint32_t listOwner = LOAD32(LOAD32(subsystem + 88) + 4);
	mood->m_74 = LOAD32(LOAD32(listOwner + 28) + 600);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return begin;
}
PROMOTED_ENTRY(65, sub_8291C540, 0x8291C540) { ctx.r3.u64 = n_sub_8291C540(ctx, base, ctx.r3.u64); }

// sub_8291C680  [236 bytes]
// forwardedArg arrives in r8 and is only handed on: to List_InsertNodeCopyWord through r8 and as the
// second argument of sub_821B1DC0.
uint64_t n_sub_8291C680(CpuState& ctx, uint8_t* base, uint64_t moodAddr, uint64_t forwardedArg) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(65, 0x8291C680)) { ctx.r3.u64 = moodAddr; ctx.r8.u64 = forwardedArg; __imp__sub_8291C680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8291C680);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECMood* mood = GameObject<CECMood>(base, moodAddr);
	stack = PushStackFrame(base, stack, 144);

	// Handle vector at mood + 0x84 (begin pointer at 0x88, end pointer at 0x8C), walked with
	// checked-iterator traps; every handle other than -1 is inserted into a list of a global object.
	uint32_t handles = moodAddr + 132;
	uint32_t cursor = mood->m_88;
	uint32_t checkedEnd = mood->m_8C;
	if (cursor > checkedEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t begin = 0;
	for (;;) {
		uint32_t end = LOAD32(handles + 8);
		begin = LOAD32(handles + 4);
		if (begin > end) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (cursor == end)
			break;
		if (cursor >= checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t handle = LOAD32(cursor);
		STORE32(stack + 80, handle);
		if ((int32_t)handle != -1) {
			uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t subsystem = LOAD32(globalObject + 12);
			uint32_t listOwner = LOAD32(LOAD32(subsystem + 88) + 4);
			uint32_t list = listOwner + 192;
			// Insert position: the pair (list, word at list + 4) built on the stack.
			STORE32(stack + 88, list);
			STORE32(stack + 92, LOAD32(listOwner + 196));
			uint64_t position = LOAD64(stack + 88);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r8.u64 = forwardedArg;
			List_InsertNodeCopyWord(ctx, base, list, position, stack + 80);
			forwardedArg = ctx.r8.u64;
		}

		checkedEnd = LOAD32(handles + 8);
		if (cursor >= checkedEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		cursor += 4;
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r9.u64 = begin;
	ctx.r10.u64 = checkedEnd;
	n_sub_821B1DC0(ctx, base, handles, forwardedArg);

	// Virtual slot 0x10 yields the component type that is removed from the entity at m_4.
	uint32_t getComponentType = LOAD32(uint32_t(mood->vtable) + 16);
	uint32_t entity = mood->m_4;
	callTarget.u64 = getComponentType;
	ctx.r3.u64 = moodAddr;
	ctx.r10.u64 = getComponentType;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t componentType = ctx.r3.u64;
	uint64_t result = Entity_RemoveComponentByType(ctx, base, entity, componentType, ctx.r8.u64);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(65, sub_8291C680, 0x8291C680) { ctx.r3.u64 = n_sub_8291C680(ctx, base, ctx.r3.u64, ctx.r8.u64); }
