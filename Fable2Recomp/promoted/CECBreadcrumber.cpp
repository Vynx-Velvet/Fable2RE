// CECBreadcrumber (vtable 0x82003C98): methods of the class as readable C++.
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

uint64_t CECBreadcrumber_HasMovedBeyondThreshold(CpuState& ctx, uint8_t* base, uint32_t breadcrumberAddr) {
	if (!UseLiftedCode(0, 0x82174C18)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_82174C18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174C18);
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);

	// Six pairs are compared (m_188 with m_168, m_18C-m_198 with m_178-m_184, m_1F0 with m_164); the result is 0
	// only while the absolute value of every difference, rounded to float, stays strictly below the threshold.
	ctx.fpscr.disableFlushMode();
	const double first = double(breadcrumber->m_188);
	const double second = double(breadcrumber->m_168);
	const double difference = double(float(first - second));
	const double threshold = double(LOAD_F32(0x820990B4u));
	if (!(std::fabs(difference) < threshold)) {
		// callers read f11-f13 after the call
		ctx.f11.f64 = std::fabs(difference);
		ctx.f12.f64 = difference;
		ctx.f13.f64 = second;
		return 1;
	}

	// Each further pair leaves its difference, second and first value in f11, f12 and f13 for callers.
	auto pairWithinThreshold = [&](const BigEndian<float>& firstField, const BigEndian<float>& secondField) {
		ctx.fpscr.disableFlushMode();
		const double firstValue = double(firstField);
		const double secondValue = double(secondField);
		const double pairDifference = double(float(firstValue - secondValue));
		ctx.f11.f64 = pairDifference;
		ctx.f12.f64 = secondValue;
		ctx.f13.f64 = firstValue;
		return std::fabs(pairDifference) < threshold;
	};
	const bool withinThreshold =
		pairWithinThreshold(breadcrumber->m_18C, breadcrumber->m_178) &&
		pairWithinThreshold(breadcrumber->m_190, breadcrumber->m_17C) &&
		pairWithinThreshold(breadcrumber->m_194, breadcrumber->m_180) &&
		pairWithinThreshold(breadcrumber->m_198, breadcrumber->m_184) &&
		pairWithinThreshold(breadcrumber->m_1F0, breadcrumber->m_164);
	return withinThreshold ? 0 : 1;
}
PROMOTED_ENTRY(0, sub_82174C18, 0x82174C18) { ctx.r3.u64 = CECBreadcrumber_HasMovedBeyondThreshold(ctx, base, ctx.r3.u32); }

uint32_t CECBreadcrumber_UpdateStatus(CpuState& ctx, uint8_t* base, uint32_t breadcrumberAddr, double floatArg1) {
	if (!UseLiftedCode(0, 0x82189B58)) { ctx.r3.u64 = breadcrumberAddr; ctx.f1.f64 = floatArg1; __imp__sub_82189B58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82189B58);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	stack = PushStackFrame(base, stack, 128);

	// r6-r8, cr0 and xer as the component search below leaves them (the caller's when it does not run)
	uint64_t searchR6 = ctx.r6.u64;
	uint64_t searchR7 = ctx.r7.u64;
	uint64_t searchR8 = ctx.r8.u64;
	PPCCRRegister searchCr0 = ctx.cr0;
	PPCXERRegister searchXer = ctx.xer;

	// Component 60 of the entity at m_4: bit 28 of the mask word at +40 says it has one. The byte table at +140,
	// when present, gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
	const uint32_t entity = breadcrumber->m_4;
	const bool hasComponent = ((LOAD32(entity + 40) >> 28) & 1) != 0;
	uint32_t component = 0;
	if (hasComponent) {
		const uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			const uint32_t index = LOAD8(indexTable + 60);
			component = LOAD32(LOAD32(entity + 72) + index * 8 + 4);
		} else {
			const uint32_t begin = LOAD32(entity + 72);
			const uint32_t end = LOAD32(entity + 76);
			searchR6 = end;
			STORE32(stack + 80, 0);
			const uint32_t byteCount = end - begin;
			STORE32(stack + 84, begin);
			searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			searchCr0.compare<int32_t>(count, 0, searchXer);

			// lower_bound for type 60 (keys compare signed)
			uint32_t it = begin;
			if (count > 0) {
				// halving a positive count clears the carry
				searchXer.ca = 0;
				do {
					const int32_t half = count >> 1;
					const uint32_t step = (uint32_t)half * 8;
					const uint32_t mid = it + step;
					const bool below = (int32_t)LOAD32(mid) < 60;
					searchR7 = below ? 1 : 0;
					searchR8 = step;
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
			if (it != end && (int32_t)LOAD32(it) <= 60) {
				component = LOAD32(it + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}
	}

	// Callers read these after the call, and Entity_IsComponent33ValueAboveThreshold below receives them.
	ctx.r6.u64 = searchR6;
	ctx.r7.u64 = searchR7;
	ctx.r8.u64 = searchR8;
	ctx.cr0 = searchCr0;
	ctx.xer.ca = searchXer.ca;
	ctx.f1.f64 = floatArg1;

	if (!hasComponent) {
		breadcrumber->m_19C = 5u;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return breadcrumberAddr;
	}

	// A non-zero m_1A4 gives status 4; unless it exceeds the limit at 0x8331950C, it is then cleared and the
	// globals below are set.
	const uint32_t count1A4 = breadcrumber->m_1A4;
	if (count1A4 != 0) {
		breadcrumber->m_19C = 4u;
		if ((int32_t)count1A4 > (int32_t)LOAD32(0x8331950Cu)) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return breadcrumberAddr;
		}
		breadcrumber->m_1A4 = 0;
		breadcrumber->m_152 = 1;
		ctx.fpscr.disableFlushMode();
		const double ratio = LOAD_F64(0x82100520u) / LOAD_F64(0x83319510u);
		STORE_F32(0x83319048u, LOAD_F32(0x8209BA08u));
		STORE_F32(0x83496A30u, LOAD_F32(0x820994B4u));
		STORE8(0x83319064u, 1);
		STORE8(0x83496A3Eu, 1);
		STORE8(0x83496A3Du, 1);
		STORE_F32(0x83496A34u, float(ratio));
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read these after the call: the address bases the original code built (sign-extended) and the ratio
		ctx.r4.s64 = int32_t(0x83490000);
		ctx.r6.s64 = int32_t(0x83490000);
		ctx.r7.s64 = int32_t(0x8209932C);
		ctx.r8.s64 = int32_t(0x83320000);
		ctx.f12.f64 = ratio;
		return 0x83490000u;
	}

	// state the callee may pass on
	ctx.r1.u64 = stack;
	const uint32_t aboveThreshold = Entity_IsComponent33ValueAboveThreshold(ctx, base);
	if ((aboveThreshold & 0xFF) != 0) {
		breadcrumber->m_19C = 5u;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return aboveThreshold;
	}

	if ((int32_t)breadcrumber->m_1A8 > (int32_t)LOAD32(0x8331950Cu)) {
		breadcrumber->m_19C = 2u;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return aboveThreshold;
	}

	if (breadcrumber->m_152 == 0) {
		breadcrumber->m_19C = 3u;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return aboveThreshold;
	}

	// Status 1 when the word at +608 of the component is 1 and the f1 value Navigation_GetChildValue leaves is below the
	// scaled m_1A0; otherwise 0.
	const uint32_t result = Navigation_GetChildValue(ctx, base, component);
	const double f1FromCall = ctx.f1.f64;
	uint32_t status = 0;
	if (LOAD32(component + 608) == 1) {
		ctx.fpscr.disableFlushMode();
		const double scaledLimit = double(float(double(breadcrumber->m_1A0) * double(LOAD_F32(0x8209932Cu))));
		// callers read f12 after the call
		ctx.f12.f64 = scaledLimit;
		if (f1FromCall < scaledLimit) {
			status = 1;
		}
	}
	breadcrumber->m_19C = status;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_82189B58, 0x82189B58) { ctx.r3.u64 = CECBreadcrumber_UpdateStatus(ctx, base, ctx.r3.u32, ctx.f1.f64); }

void CECBreadcrumber_Update(CpuState& ctx, uint8_t* base, uint32_t breadcrumberAddr) {
	if (!UseLiftedCode(1, 0x82192480)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_82192480(ctx, base); return; }
	LiftedFrame frame(0x82192480);
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);

	// Nothing is updated while both flag bytes at +52 and +54 of this state object are set.
	const uint32_t globalRoot = LOAD32(0x83496920u);
	const uint32_t state = LOAD32(LOAD32(globalRoot + 12) + 140);
	if (LOAD8(state + 52) != 0 && LOAD8(state + 54) != 0) {
		return;
	}

	// m_164, m_16C, m_170 and m_174 are copied to m_168, m_178, m_17C and m_180; a value below the minimum is
	// replaced by the float in a global (one per field). With m_14D set, m_168 gets the minimum itself.
	ctx.fpscr.disableFlushMode();
	const double minimum = double(LOAD_F32(0x820994B4u));
	if (breadcrumber->m_14D != 0) {
		breadcrumber->m_168 = float(minimum);
	} else {
		ctx.fpscr.disableFlushMode();
		double value = double(breadcrumber->m_164);
		if (value < minimum) {
			value = double(LOAD_F32(0x83319D94u));
		}
		ctx.fpscr.disableFlushMode();
		breadcrumber->m_168 = float(value);
	}

	ctx.fpscr.disableFlushMode();
	double value = double(breadcrumber->m_16C);
	if (value < minimum) {
		value = double(LOAD_F32(0x83319070u));
	}
	ctx.fpscr.disableFlushMode();
	breadcrumber->m_178 = float(value);

	value = double(breadcrumber->m_170);
	if (value < minimum) {
		value = double(LOAD_F32(0x83319074u));
	}
	ctx.fpscr.disableFlushMode();
	breadcrumber->m_17C = float(value);

	const double value174 = double(breadcrumber->m_174);
	value = value174;
	if (value174 < minimum) {
		ctx.fpscr.disableFlushMode();
		value = double(LOAD_F32(0x833190B4u));
	}
	breadcrumber->m_180 = float(value);
	// callers read f13 after the call: the m_174 value, even when it was replaced
	ctx.f13.f64 = value174;
}
PROMOTED_ENTRY(1, sub_82192480, 0x82192480) { CECBreadcrumber_Update(ctx, base, ctx.r3.u32); }

uint32_t CECBreadcrumber_UpdateQuestValue(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	if (!UseLiftedCode(1, 0x82192D88)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_82192D88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82192D88);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, (uint32_t)breadcrumberAddr);
	// xer.so as the caller left it: the component search's cr0 copies it
	const PPCXERRegister callerXer = ctx.xer;
	stack = PushStackFrame(base, stack, 128);

	// The float at 0x83496A4C (mirrored to 0x83496A50) becomes the one at 0x83496A48 while the handle at +12 gives
	// an entity with bit 0x40 set in its byte at +144, or the active quest's value at +68 when that quest is found
	// and its value is not below the threshold. The result is what the last of the calls returned (the argument
	// when none is made).
	const uint64_t handleAddr = breadcrumberAddr + 12;
	const uint32_t handleTarget = breadcrumber->m_10;
	double selectedValue = double(LOAD_F32(0x83496A4Cu));
	uint32_t result = (uint32_t)breadcrumberAddr;

	uint32_t entityFlag40 = 0;
	if (handleTarget != 0) {
		const uint32_t target = LOAD32(handleTarget);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = target;
		if (target == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			entityFlag40 = LOAD8(result + 144) & 64;
		}
	}

	if (entityFlag40 != 0) {
		ctx.fpscr.disableFlushMode();
		selectedValue = double(LOAD_F32(0x83496A48u));
		// state the callee may pass on
		ctx.r1.u64 = stack;
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		result = entity;

		// Component 102: bit 6 of the mask word at +48 says the entity has one. The byte table at +140, when
		// present, gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
		// stack + 80 first holds the search's (0, iterator) pair, then the quest name string.
		const uint32_t scratchAddr = stack + 80;
		if (((LOAD32(entity + 48) >> 6) & 1) != 0) {
			uint32_t component;
			const uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				const uint32_t index = LOAD8(indexTable + 102);
				component = LOAD32(index * 8 + LOAD32(entity + 72) + 4);
			} else {
				const uint32_t begin = LOAD32(entity + 72);
				const uint32_t end = LOAD32(entity + 76);
				STORE32(scratchAddr, 0u);
				const uint32_t byteCount = end - begin;
				STORE32(scratchAddr + 4, begin);
				PPCXERRegister searchXer = callerXer;
				searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				int32_t count = (int32_t)byteCount >> 3;
				PPCCRRegister searchCr0{};
				searchCr0.compare<int32_t>(count, 0, searchXer);
				uint64_t searchR7 = ctx.r7.u64;
				uint64_t searchR8 = ctx.r8.u64;

				// lower_bound for type 102 (keys compare signed)
				uint32_t it = begin;
				if (count > 0) {
					// halving a positive count clears the carry
					searchXer.ca = 0;
					do {
						const int32_t half = count >> 1;
						const uint32_t step = (uint32_t)half * 8;
						const uint32_t mid = it + step;
						const bool below = (int32_t)LOAD32(mid) < 102;
						searchR7 = below ? 1 : 0;
						searchR8 = step;
						if (below) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(scratchAddr + 4, it);
				}
				// a missing type reads the pair at `end`
				if (it != end && (int32_t)LOAD32(it) <= 102) {
					component = LOAD32(it + 4);
				} else {
					component = LOAD32(end + 4);
				}

				// r6-r8, cr0 and xer.ca as the search leaves them: CECQuestTracker_GetActiveQuestName receives them
				ctx.r6.u64 = end;
				ctx.r7.u64 = searchR7;
				ctx.r8.u64 = searchR8;
				ctx.cr0 = searchCr0;
				ctx.xer.ca = searchXer.ca;
			}

			CECQuestTracker_GetActiveQuestName(ctx, base, scratchAddr, component);
			// f13 handed to the release below: as the name lookup left it, or the threshold when a quest was found
			double f13ForRelease = ctx.f13.f64;
			// the literal's address as the original code built it, sign-extended
			const uint64_t literalAddr = 0xFFFFFFFF82000C98ull;
			if ((CCharString_NotEqualsEmptyOrLiteral(ctx, base, scratchAddr, literalAddr) & 0xFF) != 0) {
				// the first word of the name's data, or the sign-extended 0x8209003F when it has none
				const uint32_t nameData = LOAD32(scratchAddr);
				const uint64_t nameKey = nameData == 0 ? 0xFFFFFFFF8209003Full : uint64_t(LOAD32(nameData));
				const uint32_t quest = CECQuestTracker_FindQuestByNameHash(ctx, base, component, nameKey);
				if (quest != 0) {
					ctx.fpscr.disableFlushMode();
					const double questValue = double(LOAD_F32(quest + 68));
					f13ForRelease = double(LOAD_F32(0x820994B4u));
					if (!(questValue < f13ForRelease)) {
						selectedValue = questValue;
					}
				}
			}
			// state the callee may pass on
			ctx.f13.f64 = f13ForRelease;
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchAddr);
		}
	}

	ctx.fpscr.disableFlushMode();
	if (double(LOAD_F32(0x83496A4Cu)) != selectedValue) {
		STORE_F32(0x83496A4Cu, float(selectedValue));
		STORE_F32(0x83496A50u, float(selectedValue));
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// r6-r8, cr0 and xer.ca, which callers read, are as the last call left them (the caller's when none is made)
	return result;
}
PROMOTED_ENTRY(1, sub_82192D88, 0x82192D88) { ctx.r3.u64 = CECBreadcrumber_UpdateQuestValue(ctx, base, ctx.r3.u64); }

uint32_t CECBreadcrumber_UpdateScale(CpuState& ctx, uint8_t* base, uint32_t breadcrumberAddr) {
	if (!UseLiftedCode(2, 0x821AA1E8)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_821AA1E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821AA1E8);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	stack = PushStackFrame(base, stack, 128);

	// The first element of the array behind +88 of the global root's object at +12 holds an entity handle at +104
	// (its target pointer at +108). The result is the handle's address unless a call below returns one.
	const uint32_t globalRoot = LOAD32(0x83496920u);
	breadcrumber->m_1B4 = LOAD_F32(0x820994C0u);
	const uint32_t rootData = LOAD32(globalRoot + 12);
	const uint32_t arrayHolder = LOAD32(rootData + 88);
	const uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	const uint32_t firstElement = LOAD32(arrayBegin);
	const uint64_t handleAddr = uint64_t(firstElement) + 104;
	uint64_t result = handleAddr;

	// r6-r8, cr0 and xer.ca handed to n_sub_821D81C0 below
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7 = arrayBegin;
	uint64_t passR8 = arrayHolder;
	PPCCRRegister passCr0 = ctx.cr0;
	PPCXERRegister passXer = ctx.xer;

	uint32_t entity = 0;
	const uint32_t handleTarget = LOAD32(firstElement + 108);
	if (handleTarget != 0) {
		entity = LOAD32(handleTarget);
		if (entity == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			result = EntityHandle_Release(ctx, base, handleAddr);
			passR6 = ctx.r6.u64;
			passR7 = ctx.r7.u64;
			passR8 = ctx.r8.u64;
			passCr0 = ctx.cr0;
			passXer.ca = ctx.xer.ca;
		}
	}

	// Component 128: bit 0 of the mask word at +52 says the entity has one. The byte table at +140, when present,
	// gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
	if ((LOAD32(entity + 52) & 1) != 0) {
		uint32_t component;
		const uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			const uint32_t index = LOAD8(indexTable + 128);
			component = LOAD32(index * 8 + LOAD32(entity + 72) + 4);
		} else {
			const uint32_t begin = LOAD32(entity + 72);
			const uint32_t end = LOAD32(entity + 76);
			passR6 = end;
			STORE32(stack + 80, 0);
			const uint32_t byteCount = end - begin;
			STORE32(stack + 84, begin);
			passXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			passCr0.compare<int32_t>(count, 0, passXer);

			// lower_bound for type 128 (keys compare signed)
			uint32_t it = begin;
			if (count > 0) {
				// halving a positive count clears the carry
				passXer.ca = 0;
				do {
					const int32_t half = count >> 1;
					const uint32_t step = (uint32_t)half * 8;
					const uint32_t mid = it + step;
					const bool below = (int32_t)LOAD32(mid) < 128;
					passR7 = below ? 1 : 0;
					passR8 = step;
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
			if (it != end && (int32_t)LOAD32(it) <= 128) {
				component = LOAD32(it + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = passR6;
		ctx.r7.u64 = passR7;
		ctx.r8.u64 = passR8;
		ctx.cr0 = passCr0;
		ctx.xer.ca = passXer.ca;
		result = n_sub_821D81C0(ctx, base, component, 0);
		if ((uint32_t)result != 0) {
			ctx.fpscr.disableFlushMode();
			const float scaled = float(double(LOAD_F32(0x833190A4u)) * double(breadcrumber->m_1B4));
			breadcrumber->m_1B4 = scaled;
			// Math_SinApprox below receives it in f12
			ctx.f12.f64 = double(scaled);
		}
	}

	// m_1B4 is multiplied by (weight * |SinApprox(angle)| + Sin(angle)), the angle being the float at +4 of the
	// array's element 5 times a constant.
	ctx.fpscr.disableFlushMode();
	const double angleScale = double(LOAD_F32(0x820990A0u));
	const uint32_t arrayHolderNow = LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88);
	const uint32_t arrayBeginNow = LOAD32(arrayHolderNow + 4);
	const uint32_t element5 = LOAD32(arrayBeginNow + 20);
	const double angle = double(float(double(LOAD_F32(element5 + 4)) * angleScale));
	// callers read cr0 as it was before the sine calls
	const PPCCRRegister cr0BeforeSine = ctx.cr0;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	const double approxSine = Math_SinApprox(ctx, base, angle);
	ctx.fpscr.disableFlushMode();
	const double approxSineRounded = double(float(approxSine));
	// state the callee may pass on
	const double sine = Math_Sin(ctx, base, angle);
	ctx.fpscr.disableFlushMode();
	const double sineRounded = double(float(sine));
	const double oldValue = double(breadcrumber->m_1B4);
	const double weight = double(LOAD_F32(0x833190A8u));
	breadcrumber->m_1B4 = float(double(float(std::fma(weight, std::fabs(approxSineRounded), sineRounded))) * oldValue);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r6.u64 = element5;
	ctx.r7.u64 = arrayBeginNow;
	ctx.f1.f64 = sine;
	ctx.f10.f64 = oldValue;
	ctx.f11.f64 = sineRounded;
	ctx.cr0 = cr0BeforeSine;
	return (uint32_t)result;
}
PROMOTED_ENTRY(2, sub_821AA1E8, 0x821AA1E8) { ctx.r3.u64 = CECBreadcrumber_UpdateScale(ctx, base, ctx.r3.u32); }

uint64_t CECBreadcrumber_DestroyBreadcrumbs(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	if (!UseLiftedCode(4, 0x821E8EB8)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_821E8EB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E8EB8);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	// xer.so as the caller left it: the component search's cr0 copies it
	const PPCXERRegister callerXer = ctx.xer;
	stack = PushStackFrame(base, stack, 192);

	// For index 0 .. m_EC-1, CECBreadcrumber_GetBreadcrumbList (given +228 and the index's address, stack + 80) returns a list; every
	// entity in it with bit 0x40 set in its byte at +144 is destroyed, its component 85 (when it has one) first
	// going through the particle calls.
	// The nodes are linked through +0 and end at the node that +4 of the list points to; a node keeps an entity
	// handle at +8 (its target pointer at +12).
	const uint32_t indexAddr = stack + 80;
	uint32_t index = 0;
	STORE32(indexAddr, index);

	if (breadcrumber->m_EC > 0) {
		const uint64_t listsAddr = breadcrumberAddr + 228;
		const double fadeAlpha = double(LOAD_F32(0x820994B4u));
		do {
			ctx.r1.u64 = stack;
			const uint32_t list = CECBreadcrumber_GetBreadcrumbList(ctx, base, listsAddr, indexAddr);
			uint32_t node = LOAD32(LOAD32(list + 4));
			for (;;) {
				const uint32_t listAgain = CECBreadcrumber_GetBreadcrumbList(ctx, base, listsAddr, indexAddr);
				const uint32_t endNode = LOAD32(listAgain + 4);
				if (list != listAgain) {
					ppc_trap(ctx, base, 22);
				}
				if (node == endNode) {
					break;
				}
				if (node == LOAD32(list + 4)) {
					ppc_trap(ctx, base, 22);
				}

				const uint32_t handleTarget = LOAD32(node + 12);
				uint32_t entity = 0;
				if (handleTarget != 0) {
					entity = LOAD32(handleTarget);
					if (entity == 0) {
						// state the callee may pass on
						EntityHandle_Release(ctx, base, uint64_t(node) + 8);
					}
				}

				if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
					// Component 85: bit 21 of the mask word at +44 says the entity has one. The byte table at +140,
					// when present, gives its index in the (type, component) pairs at +72..+76; otherwise the
					// pairs are searched.
					if (((LOAD32(entity + 44) >> 21) & 1) != 0) {
						uint32_t particle;
						const uint32_t indexTable = LOAD32(entity + 140);
						if (indexTable != 0) {
							const uint32_t componentIndex = LOAD8(indexTable + 85);
							particle = LOAD32(componentIndex * 8 + LOAD32(entity + 72) + 4);
						} else {
							const uint32_t begin = LOAD32(entity + 72);
							const uint32_t end = LOAD32(entity + 76);
							STORE32(stack + 88, 0);
							const uint32_t byteCount = end - begin;
							STORE32(stack + 92, begin);
							PPCXERRegister searchXer = callerXer;
							searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
							int32_t count = (int32_t)byteCount >> 3;
							PPCCRRegister searchCr0{};
							searchCr0.compare<int32_t>(count, 0, searchXer);
							uint64_t searchR7 = ctx.r7.u64;
							uint64_t searchR8 = ctx.r8.u64;

							// lower_bound for type 85 (keys compare signed)
							uint32_t it = begin;
							if (count > 0) {
								// halving a positive count clears the carry
								searchXer.ca = 0;
								do {
									const int32_t half = count >> 1;
									const uint32_t step = (uint32_t)half * 8;
									const uint32_t mid = it + step;
									const bool below = (int32_t)LOAD32(mid) < 85;
									searchR7 = below ? 1 : 0;
									searchR8 = step;
									if (below) {
										it = mid + 8;
										count = count - half - 1;
									} else {
										count = half;
									}
								} while (count > 0);
								STORE32(stack + 92, it);
							}
							// a missing type reads the pair at `end`
							if (it != end && (int32_t)LOAD32(it) <= 85) {
								STORE64(stack + 96, LOAD64(stack + 88));
								particle = LOAD32(LOAD32(stack + 100) + 4);
							} else {
								particle = LOAD32(end + 4);
							}

							// r6-r8, cr0 and xer.ca as the search leaves them: the calls below receive them
							ctx.r6.u64 = end;
							ctx.r7.u64 = searchR7;
							ctx.r8.u64 = searchR8;
							ctx.cr0 = searchCr0;
							ctx.xer.ca = searchXer.ca;
						}

						if (LOAD8(0x83496A1Fu) != 0) {
							uint32_t emitter = LOAD32(particle + 16);
							if (emitter != 0) {
								ctx.fpscr.disableFlushMode();
								ParticleEmitter_ApplyAlphaToChildren(ctx, base, emitter, fadeAlpha);
							}
							emitter = LOAD32(particle + 16);
							if (emitter != 0) {
								Vector_DeletePointerElements(ctx, base, emitter);
							}
						} else {
							ctx.fpscr.disableFlushMode();
							n_sub_8247EB68(ctx, base, particle, fadeAlpha);
						}
					}
					Entity_DestroyImpl(ctx, base, entity);
				}

				if (node == LOAD32(list + 4)) {
					ppc_trap(ctx, base, 22);
				}
				node = LOAD32(node);
			}
			index = index + 1;
			STORE32(indexAddr, index);
		} while (index < breadcrumber->m_EC);
	}

	ctx.r1.u64 = stack;
	CECBreadcrumber_KillTrailEffect(ctx, base, breadcrumberAddr);
	breadcrumber->m_158 = 0;
	List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumberAddr + 240);
	const uint64_t result = List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumberAddr + 252);
	breadcrumber->m_1AC = 0;
	breadcrumber->m_1B0 = 0;
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821E8EB8, 0x821E8EB8) { ctx.r3.u64 = CECBreadcrumber_DestroyBreadcrumbs(ctx, base, ctx.r3.u64); }

// Sets m_184 to the destination vertical offset: the breadcrumber tuning value at 0x83496A58
// (DestinationVerticalOffset in research/catalog/tuning.tsv), or the non-zero value at +64 of the active quest
// that the entity's quest tracker finds. When the value changed, refreshes through CECBreadcrumber_UpdateBreadcrumbPlacement.
uint32_t CECBreadcrumber_UpdateDestinationVerticalOffset(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(11, 0x822A3728)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_822A3728(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822A3728);
	uint32_t stack = ctx.r1.u64;
	// its summary-overflow bit goes into the cr0 handed to GetActiveQuestName below
	const PPCXERRegister entryXer = ctx.xer;

	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	stack = PushStackFrame(base, stack, 128);
	uint64_t handleAddr = breadcrumberAddr + 12;
	// what the last call below returned; the breadcrumber address when none runs
	uint64_t result = breadcrumberAddr;

	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t stateObject = LOAD32(LOAD32(manager + 12) + 140);
	uint32_t stateFlag52 = LOAD8(stateObject + 52);
	if (stateFlag52 != 0 && LOAD8(stateObject + 54) != 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return (uint32_t)result;
	}

	// r9/r10 as the original code leaves them for CECBreadcrumber_UpdateBreadcrumbPlacement at the end (it may pass them on)
	uint64_t r9State = stateFlag52;
	uint64_t r10State = uint64_t(int64_t(g_83490000));

	ctx.fpscr.disableFlushMode();
	double verticalOffset = double(LOAD_F32(uint32_t(g_83490000) + 27224));

	uint32_t handleLink = breadcrumber->m_10;
	bool haveEntity = false;
	if (handleLink != 0) {
		uint32_t linkTarget = LOAD32(handleLink);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r9.u64 = stateFlag52;
		ctx.r10.u64 = linkTarget;
		if (linkTarget == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
			r9State = ctx.r9.u64;
			r10State = ctx.r10.u64;
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			uint32_t entityFlag = LOAD8((uint32_t)result + 144) & 64;
			r9State = ctx.r9.u64;
			r10State = entityFlag;
			haveEntity = entityFlag != 0;
		}
	}

	if (haveEntity) {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = r10State;  // state the callee may pass on (the +144 flag bit)
		result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		uint32_t entity = (uint32_t)result;
		r9State = ctx.r9.u64;
		uint32_t tableFlag = (LOAD32(entity + 48) >> 6) & 1;
		r10State = tableFlag;
		if (tableFlag != 0) {
			// the quest tracker: the value under key 102 in the entity's sorted table of 8-byte {key, value} entries
			uint32_t questTracker;
			uint32_t slotByKey = LOAD32(entity + 140);
			if (slotByKey != 0) {
				uint64_t entryAddr = uint64_t(LOAD8(slotByKey + 102) << 3) + LOAD32(entity + 72);
				questTracker = LOAD32((uint32_t)entryAddr + 4);
				ctx.r9.u64 = entryAddr;  // state GetActiveQuestName may pass on
			} else {
				// lower_bound for key 102; when the key is missing, the word after the table end is read
				uint32_t tableBegin = LOAD32(entity + 72);
				uint32_t tableEnd = LOAD32(entity + 76);
				STORE32(stack + 80, 0u);
				STORE32(stack + 84, tableBegin);
				uint64_t spanBytes = uint64_t(tableEnd) - tableBegin;
				int32_t count = int32_t(spanBytes) >> 3;
				// r7-r9 and the carry as the search leaves them
				uint64_t r7State = ctx.r7.u64;
				uint64_t r8State = ctx.r8.u64;
				uint64_t r9Search = spanBytes;
				bool carry = int32_t(spanBytes) < 0 && (spanBytes & 0x7) != 0;
				int32_t remaining = count;
				uint32_t it = tableBegin;
				if (remaining > 0) {
					do {
						int32_t half = remaining >> 1;
						uint32_t halfBytes = uint32_t(half) << 3;
						uint32_t mid = it + halfBytes;
						bool keyBelow = (int32_t)LOAD32(mid) < 102;
						if (keyBelow) {
							remaining = remaining - half - 1;
							it = mid + 8;
						} else {
							remaining = half;
						}
						r7State = keyBelow ? 1 : 0;
						r8State = halfBytes;
						r9Search = uint64_t(half);
					} while (remaining > 0);
					carry = false;
					STORE32(stack + 84, it);
				}
				if (it != tableEnd && (int32_t)LOAD32(it) <= 102) {
					STORE64(stack + 80, LOAD64(stack + 80));  // the original copies the iterator pair onto itself
					questTracker = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					questTracker = LOAD32(tableEnd + 4);
				}
				// state GetActiveQuestName may pass on
				ctx.r6.u64 = tableEnd;
				ctx.r7.u64 = r7State;
				ctx.r8.u64 = r8State;
				ctx.r9.u64 = r9Search;
				ctx.cr0.compare<int32_t>(count, 0, entryXer);
				ctx.xer.ca = carry;
			}

			ctx.r1.u64 = stack;
			CECQuestTracker_GetActiveQuestName(ctx, base, stack + 80, questTracker);
			// f13 as the original code leaves it for the string release below
			double f13State = ctx.f13.f64;
			uint64_t nameDiffers = CCharString_NotEqualsEmptyOrLiteral(ctx, base, stack + 80, g_82000C98) & 0xFF;
			ctx.r10.u64 = nameDiffers;  // state the calls below may pass on
			if (nameDiffers != 0) {
				uint32_t nameData = LOAD32(stack + 80);
				uint64_t nameText = nameData == 0 ? uint64_t(g_8209003F) : uint64_t(LOAD32(nameData));
				uint32_t quest = CECQuestTracker_FindQuestByNameHash(ctx, base, questTracker, nameText);
				if (quest != 0) {
					ctx.fpscr.disableFlushMode();
					double questOffset = double(LOAD_F32(quest + 64));
					double zero = double(LOAD_F32(0x820994B4u));
					f13State = zero;
					if (questOffset != zero) {
						verticalOffset = questOffset;
					}
				}
			}
			ctx.f13.f64 = f13State;  // state the callee may pass on
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			r9State = ctx.r9.u64;
			r10State = ctx.r10.u64;
		}
	}

	ctx.fpscr.disableFlushMode();
	if (verticalOffset != double(breadcrumber->m_184)) {
		breadcrumber->m_184 = float(verticalOffset);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r9.u64 = r9State;
		ctx.r10.u64 = r10State;
		result = CECBreadcrumber_UpdateBreadcrumbPlacement(ctx, base, breadcrumberAddr, 0u);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(11, sub_822A3728, 0x822A3728) { ctx.r3.u64 = CECBreadcrumber_UpdateDestinationVerticalOffset(ctx, base, ctx.r3.u64); }

// Returns 1 when m_14A is set and the vector CECBreadcrumber_GetPositionVector produces has a squared length above the
// constant at 0x82099AE0, else 0.
uint64_t CECBreadcrumber_IsTrailDistanceAboveThreshold(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	if (!UseLiftedCode(13, 0x822D3508)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_822D3508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3508);
	uint32_t stack = ctx.r1.u32;
	// r5, f13 and v13 as the original code leaves them for callers (unchanged unless the vector is measured)
	uint64_t r5Out = ctx.r5.u64;
	double f13Out = ctx.f13.f64;
	PPCVRegister v13Out = ctx.v13;
	uint32_t result = 0;
	stack = PushStackFrame(base, stack, 112);
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, (uint32_t)breadcrumberAddr);
	if (breadcrumber->m_14A != 0) {
		uint32_t vectorBuffer = (int32_t)stack + 80;
		ctx.r1.u64 = stack;
		CECBreadcrumber_GetPositionVector(ctx, base, vectorBuffer, breadcrumberAddr, 0);
		PPCVRegister vec{};
		SET_V8(vec, VLOAD(vectorBuffer & ~0xF));
		PPCVRegister lengthSqVec{};
		ctx.fpscr.enableFlushMode();
		SET_VF(lengthSqVec, simde_mm_dp_ps(VF(vec), VF(vec), 0xEF));
		ctx.fpscr.disableFlushModeUnconditional();
		double minLengthSq = double(LOAD_F32(0x82099AE0u));
		VSTORE(vectorBuffer & ~0xF, V8(lengthSqVec));
		double lengthSq = double(LOAD_F32(vectorBuffer));
		if (lengthSq > minLengthSq) {
			result = 1;
		}
		r5Out = 0;
		f13Out = lengthSq;
		v13Out = lengthSqVec;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = breadcrumberAddr;
	ctx.r5.u64 = r5Out;
	ctx.f13.f64 = f13Out;
	ctx.v13 = v13Out;
	return result;
}
PROMOTED_ENTRY(13, sub_822D3508, 0x822D3508) { ctx.r3.u64 = CECBreadcrumber_IsTrailDistanceAboveThreshold(ctx, base, ctx.r3.u64); }

// Constructs the class name string into the CCharString at classNameString and returns its address.
uint64_t CECBreadcrumber_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B7CE4_B_ = int32_t(0x820B7CE4);
	if (!UseLiftedCode(29, 0x824D4570)) { ctx.r3.u64 = classNameString; __imp__sub_824D4570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824D4570);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820B7CE4_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(29, sub_824D4570, 0x824D4570) { ctx.r3.u64 = CECBreadcrumber_GetClassName(ctx, base, ctx.r3.u64); }

// Runs CECBreadcrumber_Destructor on the object and, when bit 0 of flags is set, frees it; returns the object address.
uint64_t CECBreadcrumber_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t objectAddr, uint64_t flags) {
	if (!UseLiftedCode(29, 0x824D4A68)) { ctx.r3.u64 = objectAddr; ctx.r4.u64 = flags; __imp__sub_824D4A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824D4A68);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = flags;  // state the callee may pass on
	CECBreadcrumber_Destructor(ctx, base, objectAddr);
	if ((uint32_t(flags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectAddr);
	}
	return objectAddr;
}
PROMOTED_ENTRY(29, sub_824D4A68, 0x824D4A68) { ctx.r3.u64 = CECBreadcrumber_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBreadcrumber_Reset_824D4C00(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(29, 0x824D4C00)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_824D4C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824D4C00);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	stack = PushStackFrame(base, stack, 128);

	// the shared handle at +452 (m_1C4): take it out of the piece list, release it and clear it
	uint64_t pieceHandleAddr = breadcrumberAddr + 452;
	if (breadcrumber->m_1C4 != 0) {
		uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t registry = LOAD32(manager + 12);
		uint32_t registryEntry = LOAD32(registry + 88);
		uint32_t pieceListOwner = LOAD32(registryEntry + 4);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		BreakablePieceList_RemoveById(ctx, base, pieceListOwner, pieceHandleAddr);
		SharedHandle_Release(ctx, base, pieceHandleAddr);
		breadcrumber->m_1C4 = 0;
	}

	ctx.r1.u64 = stack;
	CECBreadcrumber_UpdateBreadcrumbPlacement(ctx, base, breadcrumberAddr, 0);
	CECBreadcrumber_DestroyBreadcrumbs(ctx, base, breadcrumberAddr);

	List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumber->m_140);
	List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumber->m_144);
	List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumberAddr + 240);
	List_ClearFreeNodes(ctx, base, (uint32_t)breadcrumberAddr + 252);

	breadcrumber->m_1AC = 0;
	breadcrumber->m_1B0 = 0;

	// clears the handle at +104 by assigning it a null EntityHandle built on the stack (vtable 0x820F1664)
	uint32_t tempHandleAddr = stack + 80;
	STORE32(tempHandleAddr + 4, 0);
	STORE32(tempHandleAddr, uint32_t(g_820F1664));
	ctx.r10.s64 = g_820F1664;  // state the callee may pass on
	EntityHandle_Release(ctx, base, tempHandleAddr);
	EntityHandle_Assign(ctx, base, breadcrumberAddr + 104, tempHandleAddr);
	uint32_t handleVtable = uint32_t(g_820F0000) + 5732;
	STORE32(tempHandleAddr, handleVtable);
	// state the callee may pass on
	uint64_t result = EntityHandle_Release(ctx, base, tempHandleAddr);

	PPCVRegister zeroVec{};
	SET_V8(zeroVec, simde_mm_set1_epi32(int(0x0)));
	VSTORE(((uint32_t)breadcrumberAddr + 32u) & ~0xFu, V8(zeroVec));
	VSTORE(((uint32_t)breadcrumberAddr + 48u) & ~0xFu, V8(zeroVec));

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(29, sub_824D4C00, 0x824D4C00) { ctx.r3.u64 = CECBreadcrumber_Reset_824D4C00(ctx, base, ctx.r3.u64); }

// When mode is 1, serializes three named values through the stream (the float at 0x83319040 and the bytes at
// +330 and +331), then an 8-byte id through UID_Serialize: with saving set the id is taken from the entity
// held by the handle at +128; otherwise the call fills it in and a non-zero id is stored in a new block held
// by the shared handle at +488.
uint64_t CECBreadcrumber_Serialize(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr, uint64_t stream, uint32_t mode, uint64_t saving) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820B0000 = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820B7D30_B_ = int32_t(0x820B7D30);
	constexpr int32_t str_TXT_820B7D48_B_ = int32_t(0x820B7D48);
	constexpr int32_t str_TXT_820B7D58_B_ = int32_t(0x820B7D58);
	constexpr int32_t g_83319040 = int32_t(0x83319040);
	constexpr int32_t str_TXT_820B59DC_B_ = int32_t(0x820B59DC);
	if (!UseLiftedCode(29, 0x824D4CE0)) { ctx.r3.u64 = breadcrumberAddr; ctx.r4.u64 = stream; ctx.r5.u64 = mode; ctx.r6.u64 = saving; __imp__sub_824D4CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824D4CE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	if ((int32_t)mode != 1) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = stream;  // callers read r4 after the call
		return breadcrumberAddr;
	}

	ctx.r1.u64 = stack;
	ctx.r6.u64 = saving;  // state the callee may pass on
	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B7D30_B_, -1);
	uint32_t nameData = LOAD32(stack + 80);
	ctx.r4.u64 = nameData == 0 ? uint64_t(g_8209003F) : uint64_t(LOAD32(nameData));  // state the callee may pass on
	IStream_SerializeFloat(ctx, base, stream, g_83319040);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	ctx.r10.s64 = g_820B0000;  // state the callee may pass on
	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B59DC_B_, -1);  // the name string at 0x820B59DC
	IStream_SerializeString(ctx, base, stack + 80, stream, breadcrumberAddr + 330);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B7D48_B_, -1);
	IStream_SerializeString(ctx, base, stack + 80, stream, breadcrumberAddr + 331);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	uint32_t savingByte = uint32_t(saving) & 0xFF;
	if (savingByte != 0) {
		// the id at +20 of the entity held by the handle at +128; zero when there is none
		uint64_t handleAddr = breadcrumberAddr + 128;
		STORE32(stack + 96, 0);
		STORE32(stack + 100, 0);
		uint32_t entityFlag = 0;
		uint32_t handleLink = LOAD32((uint32_t)handleAddr + 4);
		if (handleLink != 0) {
			uint32_t linkTarget = LOAD32(handleLink);
			// state the callee may pass on
			ctx.r8.u64 = savingByte;
			ctx.r10.u64 = linkTarget;
			if (linkTarget == 0) {
				EntityHandle_Release(ctx, base, handleAddr);
			} else {
				uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
				entityFlag = LOAD8(entity + 144) & 64;
			}
		}
		if (entityFlag != 0) {
			ctx.r10.u64 = entityFlag;  // state the callee may pass on
			uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
			STORE64(stack + 96, LOAD64(entity + 20));
		}
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B7D58_B_, -1);
		UID_Serialize(ctx, base, stack + 96, stack + 80, stream);
		uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	STORE32(stack + 88, 0);
	STORE32(stack + 92, 0);
	ctx.r8.u64 = savingByte;  // state the callee may pass on (zero here)
	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B7D58_B_, -1);
	UID_Serialize(ctx, base, stack + 88, stack + 80, stream);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	if (LOAD32(stack + 88) != 0 || LOAD32(stack + 92) != 0) {
		uint64_t idBlock = operator_new(ctx, base, 8);
		if ((uint32_t)idBlock != 0) {
			STORE32((uint32_t)idBlock, 0);
			STORE32((uint32_t)idBlock + 4, 0);
		} else {
			idBlock = 0;
		}
		result = SharedHandle_Assign(ctx, base, breadcrumberAddr + 488, idBlock);
		STORE64(LOAD32((uint32_t)breadcrumberAddr + 488), LOAD64(stack + 88));
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(29, sub_824D4CE0, 0x824D4CE0) { ctx.r3.u64 = CECBreadcrumber_Serialize(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

// Sets m_1A4 to (double at 0x83319510) * (double at 0x83321560) + (int at 0x8331950C), truncated to an int.
void n_sub_824D56C8(CpuState& ctx, uint8_t* base, uint32_t breadcrumberAddr) {
	if (!UseLiftedCode(29, 0x824D56C8)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_824D56C8(ctx, base); return; }
	LiftedFrame frame(0x824D56C8);
	uint32_t stack = ctx.r1.u32;

	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);

	int32_t addendInt = (int32_t)LOAD32(0x8331950Cu);
	ctx.fpscr.disableFlushMode();
	double scale = LOAD_F64(0x83319510u);
	double factor = LOAD_F64(0x83321560u);

	// The original code routes the signed int through the stack (below the stack pointer) to turn it into a double.
	STORE64(stack - 16, (uint64_t)(int64_t)addendInt);
	double addend = (double)(int64_t)LOAD64(stack - 16);

	double value = std::fma(scale, factor, addend);

	// truncation toward zero; NaN and values below the int range give 0x80000000, values above it INT_MAX
	int32_t converted = std::isnan(value) ? (int32_t)0x80000000U
		: value > double(INT_MAX) ? INT_MAX
		: simde_mm_cvttsd_si32(simde_mm_load_sd(&value));

	breadcrumber->m_1A4 = converted;
}
PROMOTED_ENTRY(29, sub_824D56C8, 0x824D56C8) { n_sub_824D56C8(ctx, base, ctx.r3.u32); }

// Returns 1 when Vector_DistanceToSegment gives a value above the threshold at 0x83319038 for every segment between
// consecutive points of the list (this needs a positive threshold and at least two points). Otherwise, when the
// breadcrumber tuning flag at 0x83496A1D is set, returns 1 if the vector from the entity's +124 object (the method
// at vtable offset 76), masked by the vector at 0x82099150 (it keeps the first two components), has zero length;
// else 0.
uint32_t n_sub_824D6AD0(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr, uint64_t listAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(29, 0x824D6AD0)) { ctx.r3.u64 = breadcrumberAddr; ctx.r4.u64 = listAddr; __imp__sub_824D6AD0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824D6AD0);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);

	// register state the original code hands to its calls and leaves for callers
	uint64_t reg4 = listAddr;
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = ctx.r9.u64;
	uint64_t reg10{};
	double f13Value = ctx.f13.f64;
	PPCVRegister v55{};
	PPCVRegister v59 = ctx.v11;
	PPCVRegister v60 = ctx.v12;
	PPCVRegister v61 = ctx.v13;
	PPCVRegister v62 = ctx.v126;
	PPCVRegister v63 = ctx.v127;

	VSTORE((stack + 0xFFFFFF80u) & ~0xF, V8(v62));
	VSTORE((stack + 0xFFFFFF90u) & ~0xF, V8(v63));
	stack = PushStackFrame(base, stack, 256);

	uint32_t result = 0;
	uint32_t list = uint32_t(listAddr);
	uint32_t globalBase = uint32_t(g_83320000);
	double threshold = double(LOAD_F32(globalBase - 28616));
	double zero = double(LOAD_F32(0x820994B4u));

	if (threshold > zero) {
		if (LOAD32(list + 8) <= 1) goto checkStopped;

		// two iterators over the list, {list, node} pairs at stack+80 and stack+96: prev starts at the
		// first node, cur at the second
		uint32_t headNode = LOAD32(list + 4);
		STORE32(stack + 96, list);
		STORE32(stack + 80, list);
		uint32_t firstNode = LOAD32(headNode);
		STORE32(stack + 84, firstNode);
		reg9 = LOAD64(stack + 80);
		STORE64(stack + 80, reg9);
		if (firstNode == headNode) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t secondNode = LOAD32(firstNode);
		uint32_t prevNode = LOAD32(stack + 84);
		STORE32(stack + 100, secondNode);
		reg10 = LOAD64(stack + 96);
		STORE64(stack + 96, reg10);
		uint32_t iterList = LOAD32(stack + 96);
		uint32_t curNode = LOAD32(stack + 100);

		for (;;) {
			uint32_t sentinel = LOAD32(list + 4);
			if (iterList == 0 || iterList != list) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (curNode == sentinel) break;

			if (iterList == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (curNode == LOAD32(iterList + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			ctx.fpscr.disableFlushMode();
			STORE_F32(stack + 80, float(zero));
			uint32_t curVecAddr = (int32_t)curNode + 8;
			scratch.u32 = curVecAddr;
			SET_V8(v62, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			scratch.u32 = curVecAddr + 4;
			SET_V8(v55, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			scratch.u32 = curVecAddr + 8;
			SET_V8(v61, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_VF(v62, simde_mm_blend_ps(VF(v62), simde_mm_permute_ps(VF(v55), 57), 4));
			scratch.u32 = uint32_t((int64_t)(uint64_t)stack + 80);
			SET_V8(v60, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_VF(v61, simde_mm_blend_ps(VF(v61), simde_mm_permute_ps(VF(v60), 57), 4));
			SET_VF(v62, simde_mm_blend_ps(VF(v62), simde_mm_permute_ps(VF(v61), 78), 3));

			if (iterList == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (prevNode == LOAD32(iterList + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t prevVecAddr = (int32_t)prevNode + 8;
			ctx.fpscr.disableFlushMode();
			STORE_F32(stack + 80, float(zero));
			uint64_t handleAddr = (int64_t)breadcrumberAddr + 12;
			scratch.u32 = prevVecAddr;
			SET_V8(v63, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			scratch.u32 = prevVecAddr + 4;
			SET_V8(v55, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			scratch.u32 = prevVecAddr + 8;
			SET_V8(v61, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_VF(v63, simde_mm_blend_ps(VF(v63), simde_mm_permute_ps(VF(v55), 57), 4));
			scratch.u32 = uint32_t((int64_t)(uint64_t)stack + 80);
			SET_V8(v60, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
			SET_VF(v61, simde_mm_blend_ps(VF(v61), simde_mm_permute_ps(VF(v60), 57), 4));
			uint32_t handleLink = breadcrumber->m_10;
			SET_VF(v63, simde_mm_blend_ps(VF(v63), simde_mm_permute_ps(VF(v61), 78), 3));

			uint32_t entity = 0;
			if (handleLink != 0) {
				uint32_t linkTarget = LOAD32(handleLink);
				if (linkTarget != 0) {
					entity = linkTarget;
				} else {
					ctx.r1.u64 = stack;
					// state the callee may pass on
					ctx.r4.u64 = reg4;
					ctx.r9.u64 = reg9;
					ctx.r10.u64 = linkTarget;
					ctx.v12 = v60;
					ctx.v13 = v61;
					EntityHandle_Release(ctx, base, handleAddr);
					reg9 = ctx.r9.u64;
					f13Value = ctx.f13.f64;
					v59 = ctx.v11;
					v60 = ctx.v12;
					v61 = ctx.v13;
				}
			}

			// the entity's +124 object writes a vector to stack+96 (the method at vtable offset 64)
			uint32_t subObject = LOAD32(entity + 124);
			uint64_t outBufAddr = (int64_t)(uint64_t)stack + 96;
			uint32_t method = LOAD32(LOAD32(subObject) + 64);
			callTarget.u64 = (uint64_t)method;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = outBufAddr;
			ctx.r4.u64 = subObject;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = method;
			ctx.v12 = v60;
			ctx.v13 = v61;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			f13Value = ctx.f13.f64;
			v59 = ctx.v11;
			v60 = ctx.v12;
			v61 = ctx.v13;

			// Vector_DistanceToSegment takes that vector in v1 and the segment ends (prev in v2, cur in v3); result in f1
			PPCVRegister entityVec{};
			SET_V8(entityVec, VLOAD((uint32_t)outBufAddr & ~0xF));
			ctx.r9.u64 = outBufAddr;
			ctx.v1 = entityVec;
			ctx.v2 = v63;
			ctx.v3 = v62;
			Vector_DistanceToSegment(ctx, base, uint32_t((int64_t)(uint64_t)stack + 112));
			reg4 = ctx.r4.u64;
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			reg10 = ctx.r10.u64;
			double segmentResult = ctx.f1.f64;
			f13Value = ctx.f13.f64;
			v59 = ctx.v11;
			v60 = ctx.v12;
			v61 = ctx.v13;
			ctx.fpscr.disableFlushMode();
			threshold = double(LOAD_F32(globalBase - 28616));
			if (!(segmentResult > threshold)) goto afterLoop;
			if (prevNode == LOAD32(list + 4)) {
				ppc_trap(ctx, base, 22);
			}
			prevNode = LOAD32(prevNode);
			if (curNode == LOAD32(list + 4)) {
				ppc_trap(ctx, base, 22);
			}
			curNode = LOAD32(curNode);
		}
	afterLoop:
		uint32_t endSentinel = LOAD32(list + 4);
		if (iterList == 0 || iterList != list) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (curNode != endSentinel) goto checkStopped;
		result = 1;
		goto done;
	}
checkStopped:
	// breadcrumber tuning flag (UpdateOnStopping in research/catalog/tuning.tsv)
	reg10 = LOAD8(0x83496A1Du);
	if ((uint32_t)reg10 != 0) {
		uint64_t handleAddr = (int64_t)breadcrumberAddr + 12;
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r4.u64 = reg4;
		ctx.r9.u64 = reg9;
		ctx.r10.u64 = reg10;
		uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		v60 = ctx.v12;
		v61 = ctx.v13;
		uint64_t outAddr = (int64_t)(uint64_t)stack + 112;
		uint32_t subObject = LOAD32(entity + 124);
		uint32_t vtbl = LOAD32(subObject);
		uint32_t method = LOAD32(vtbl + 76);
		callTarget.u64 = (uint64_t)method;
		ctx.r3.u64 = outAddr;
		ctx.r4.u64 = subObject;
		ctx.r9.u64 = method;
		ctx.r10.u64 = vtbl;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t vecAddr = ctx.r3.u32;
		reg4 = ctx.r4.u64;
		reg10 = ctx.r10.u64;
		reg8 = g_820A0000;
		SET_V8(v61, VLOAD(vecAddr & ~0xF));
		// r6/r7 are left holding the mask and buffer addresses for callers
		reg7 = (int64_t)(uint64_t)stack + 96;
		reg6 = (int64_t)reg8 - 28336;
		result = 1;
		SET_V8(v55, VLOAD((uint32_t)reg6 & ~0xF));
		SET_V8(v60, simde_mm_and_si128(V8(v61), V8(v55)));
		ctx.fpscr.enableFlushMode();
		SET_VF(v59, simde_mm_dp_ps(VF(v60), VF(v61), 0xEF));
		VSTORE((uint32_t)reg7 & ~0xF, V8(v59));
		ctx.fpscr.disableFlushModeUnconditional();
		double lengthSq = double(LOAD_F32(stack + 96));
		f13Value = double(float(sqrt(lengthSq)));
		if (f13Value == zero) goto done;
	}
	result = 0;
done:
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r0.u64 = 0xFFFFFF90u;
	ctx.r4.u64 = reg4;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r10.u64 = reg10;
	ctx.f13.f64 = f13Value;
	ctx.v11 = v59;
	ctx.v12 = v60;
	ctx.v13 = v61;
	return result;
}
PROMOTED_ENTRY(29, sub_824D6AD0, 0x824D6AD0) { ctx.r3.u64 = n_sub_824D6AD0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_824DA1E0  [972 bytes]
// Lists here are linked lists: +4 holds the end node, +8 the size; a node is { next, prev, value }.
uint32_t CECBreadcrumber_RemoveLastBreadcrumb(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr, uint64_t srcList) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(30, 0x824DA1E0)) { ctx.r3.u64 = breadcrumberAddr; ctx.r4.u64 = srcList; __imp__sub_824DA1E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824DA1E0);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	const uint32_t list = (uint32_t)srcList;
	const uint32_t entityHandleVtable = uint32_t(g_820F1664);
	uint32_t result;

	stack = PushStackFrame(base, stack, 208);

	// erase the last element of the caller's list through the iterator { list, node } built at stack+96
	STORE32(stack + 96, list);
	const uint32_t listEnd = LOAD32(list + 4);
	const uint32_t listLast = LOAD32(listEnd + 4);
	STORE32(stack + 100, listLast);
	if (listLast == listEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	ctx.r1.u64 = stack;
	result = PtrList_Erase(ctx, base, stack + 104, srcList, LOAD64(stack + 96));

	if (list == breadcrumber->m_140 && LOAD32(list + 8) < breadcrumber->m_104) {
		// erase the last element of the list at +0xFC, keeping its value
		uint32_t fcEnd = breadcrumber->m_100;
		uint32_t fcLast = LOAD32(fcEnd + 4);
		if (fcLast == fcEnd) {
			ppc_trap(ctx, base, 22);
			ppc_trap(ctx, base, 22);
		}
		const uint32_t droppedCount = LOAD32(fcLast + 8);
		const uint64_t listFC = breadcrumberAddr + 0xFC;
		fcEnd = breadcrumber->m_100;
		fcLast = LOAD32(fcEnd + 4);
		STORE32(stack + 96, (uint32_t)listFC);
		STORE32(stack + 100, fcLast);
		if (fcLast == fcEnd) {
			ppc_trap(ctx, base, 22);
		}
		PtrList_Erase(ctx, base, stack + 104, listFC, LOAD64(stack + 96));

		// erase the last element of the list at +0xF0
		const uint64_t listF0 = breadcrumberAddr + 0xF0;
		const uint32_t f0End = breadcrumber->m_F4;
		const uint32_t f0Last = LOAD32(f0End + 4);
		STORE32(stack + 96, (uint32_t)listF0);
		STORE32(stack + 100, f0Last);
		if (f0Last == f0End) {
			ppc_trap(ctx, base, 22);
		}
		result = PtrList_Erase(ctx, base, stack + 104, listF0, LOAD64(stack + 96));

		const uint32_t keptCount = breadcrumber->m_158 - droppedCount;
		uint32_t handleListCount = breadcrumber->m_EC;
		breadcrumber->m_158 = keptCount;
		uint32_t listIndex = 0;
		STORE32(stack + 80, listIndex);
		if (handleListCount != 0) {
			// in each of the m_EC handle lists at +0xE4, the droppedCount entries after the first m_158 get the alpha
			const uint64_t handleLists = breadcrumberAddr + 0xE4;
			ctx.fpscr.disableFlushMode();
			const double alpha = double(LOAD_F32(0x820994B4u));
			// r9 handed to the first fetch of each list: keptCount, later what the calls left there
			uint32_t r9AtFetch = keptCount;
			do {
				const uint32_t handleList = (uint32_t)CECBreadcrumber_GetBreadcrumbList(ctx, base, handleLists, stack + 80);
				r9AtFetch = ctx.r9.u32;
				result = handleList;
				uint32_t entry = LOAD32(LOAD32(handleList + 4));

				// step past the first m_158 entries, fetching the list again at each step
				if ((int32_t)breadcrumber->m_158 > 0) {
					int32_t skipped = 0;
					do {
						if (entry == LOAD32(handleList + 4)) {
							ppc_trap(ctx, base, 22);
						}
						entry = LOAD32(entry);
						result = (uint32_t)CECBreadcrumber_GetBreadcrumbList(ctx, base, handleLists, stack + 80);
						r9AtFetch = ctx.r9.u32;
						if (result != handleList) {
							ppc_trap(ctx, base, 22);
						}
						if (entry == LOAD32(result + 4)) goto finished;
						++skipped;
					} while (skipped < (int32_t)breadcrumber->m_158);
				}

				for (int32_t applied = 0; applied < (int32_t)droppedCount; ++applied) {
					result = (uint32_t)CECBreadcrumber_GetBreadcrumbList(ctx, base, handleLists, stack + 80);
					if (result != handleList) {
						ppc_trap(ctx, base, 22);
					}
					if (entry == LOAD32(result + 4)) goto finished;
					if (entry == LOAD32(handleList + 4)) {
						ppc_trap(ctx, base, 22);
					}
					EntityHandle_CopyConstruct(ctx, base, stack + 88, entry + 8);
					// r6-r10 and CA as the original holds them at the two calls below
					uint64_t r6Value = ctx.r6.u64;
					uint64_t r7Value = ctx.r7.u64;
					uint64_t r8Value = ctx.r8.u64;
					uint32_t r9Value = ctx.r9.u32;
					uint8_t carry = ctx.xer.ca;
					const uint32_t handleTarget = LOAD32(stack + 92);
					uint32_t r10Value = handleTarget;
					uint32_t entity = 0;
					bool flagged = false;
					if (handleTarget != 0) {
						entity = LOAD32(handleTarget);
						if (entity == 0) {
							// the copied handle points at no entity: release it
							EntityHandle_Release(ctx, base, stack + 88);
							r6Value = ctx.r6.u64;
							r7Value = ctx.r7.u64;
							r8Value = ctx.r8.u64;
							r9Value = ctx.r9.u32;
							carry = ctx.xer.ca;
							r10Value = LOAD32(stack + 92);
						} else {
							r9Value = LOAD8(entity + 144) & 0x40;
							flagged = r9Value != 0;
						}
					}

					if (flagged) {
						// the entity's component with key 85: through the slot table at +140 when there is one,
						// otherwise by a lower_bound over the sorted (key, component) pairs in [+72, +76)
						bool hasComponent = false;
						uint32_t component = 0;
						r10Value = LOAD32(entity + 44);
						r9Value = (r10Value >> 21) & 1;
						if (r9Value != 0) {
							hasComponent = true;
							const uint32_t slotTable = LOAD32(entity + 140);
							if (slotTable != 0) {
								r10Value = LOAD8(slotTable + 85) << 3;
								r9Value = r10Value + LOAD32(entity + 72);
								component = LOAD32(r9Value + 4);
							} else {
								uint32_t pos = LOAD32(entity + 72);
								const uint32_t end = LOAD32(entity + 76);
								r6Value = end;
								STORE32(stack + 96, 0);
								STORE32(stack + 100, pos);
								const uint32_t byteCount = end - pos;
								carry = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
								int32_t count = (int32_t)byteCount >> 3;
								if (count > 0) {
									do {
										carry = 0;
										const int32_t half = count >> 1;
										r9Value = (uint32_t)half;
										r8Value = (uint32_t)half << 3;
										pos += (uint32_t)r8Value;
										const bool keyBelow = (int32_t)LOAD32(pos) < 85;
										r7Value = keyBelow ? 1 : 0;
										if (keyBelow) {
											pos += 8;
											count = count - half - 1;
										} else {
											pos -= (uint32_t)r8Value;
											count = half;
										}
									} while (count > 0);
									STORE32(stack + 100, pos);
								}
								r10Value = pos;
								if (pos != end && (int32_t)LOAD32(pos) <= 85) {
									STORE64(stack + 104, LOAD64(stack + 96));
									component = LOAD32(LOAD32(stack + 108) + 4);
								} else {
									// key not present: the original reads the word past the last pair
									component = LOAD32(end + 4);
								}
							}
						}
						if (hasComponent) {
							const uint32_t emitter = LOAD32(component + 16);
							if (emitter != 0) {
								ctx.fpscr.disableFlushMode();
								// state the callee may pass on
								ctx.r6.u64 = r6Value;
								ctx.r7.u64 = r7Value;
								ctx.r8.u64 = r8Value;
								ctx.xer.ca = carry;
								ParticleEmitter_ApplyAlphaToChildren(ctx, base, emitter, alpha);
								r6Value = ctx.r6.u64;
								r7Value = ctx.r7.u64;
								r8Value = ctx.r8.u64;
								r9Value = ctx.r9.u32;
								r10Value = ctx.r10.u32;
								carry = ctx.xer.ca;
							}
						}
					}

					// destroy the copied handle
					STORE32(stack + 88, entityHandleVtable);
					// state the callee may pass on
					ctx.xer.ca = carry;
					result = (uint32_t)EntityHandle_Release(ctx, base, stack + 88);
					r9AtFetch = ctx.r9.u32;
					const uint32_t endNode = LOAD32(handleList + 4);
					STORE32(stack + 92, 0);
					if (entry == endNode) {
						ppc_trap(ctx, base, 22);
					}
					entry = LOAD32(entry);
				}

				handleListCount = breadcrumber->m_EC;
				++listIndex;
				STORE32(stack + 80, listIndex);
			} while (listIndex < handleListCount);
		}
	}

finished:
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(30, sub_824DA1E0, 0x824DA1E0) { ctx.r3.u64 = CECBreadcrumber_RemoveLastBreadcrumb(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECBreadcrumber_SetBreadcrumbText(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr, uint64_t sourceString, uint64_t arg3) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(30, 0x824DA7D8)) { ctx.r3.u64 = breadcrumberAddr; ctx.r4.u64 = sourceString; ctx.r5.u64 = arg3; __imp__sub_824DA7D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824DA7D8);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	const uint32_t rootAddr = uint32_t(g_83490000) + 26912;
	stack = PushStackFrame(base, stack, 128);

	const uint64_t textAddr = breadcrumberAddr + 124;  // &breadcrumber->m_BreadcrumbText
	ctx.r1.u64 = stack;
	uint64_t result = CCharString_Assign(ctx, base, textAddr, sourceString);
	// r4 as callers see it after the call
	uint64_t r4Value = ctx.r4.u64;

	const uint32_t text = breadcrumber->m_BreadcrumbText;
	if (text != 0 && (int32_t)LOAD32(text + 4) > 0) {
		// an object reached from the global at 0x83496920 through +12, +88, +4, +8, +4; the hash
		// Path_NormalizeAndHash returns for its +20 and the text is compared with its +36 -> +4 -> +180
		const uint32_t nodeA = LOAD32(LOAD32(LOAD32(rootAddr) + 12) + 88);
		const uint32_t nodeB = LOAD32(nodeA + 4);
		const uint32_t nodeC = LOAD32(nodeB + 8);
		const uint32_t subject = LOAD32(nodeC + 4);
		const uint32_t subjectInfo = LOAD32(subject + 36);
		const uint32_t subjectRecord = LOAD32(subjectInfo + 4);
		const uint32_t storedHash = LOAD32(subjectRecord + 180);

		// state the callee may pass on
		const uint64_t textHash = Path_NormalizeAndHash(ctx, base, (uint64_t)subject + 20, textAddr);
		if (storedHash == (uint32_t)textHash) {
			// state the callee may pass on
			ctx.r5.u64 = textHash;
			const uint64_t resetResult = CECBreadcrumber_Reset(ctx, base, breadcrumberAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return resetResult;
		}

		// the same chain read again after the call
		const uint32_t nodeA2 = LOAD32(LOAD32(LOAD32(rootAddr) + 12) + 88);
		const uint32_t nodeB2 = LOAD32(nodeA2 + 4);
		const uint32_t nodeC2 = LOAD32(nodeB2 + 8);
		const uint32_t subject2 = LOAD32(nodeC2 + 4);
		const uint32_t subjectTarget = LOAD32(subject2 + 8);
		// state the callee may pass on
		result = BinarySearch_FindRecordByHashes(ctx, base, subjectTarget, storedHash, textHash);
		r4Value = result;
		if ((uint32_t)result != 0) {
			result = n_sub_824DA8B8(ctx, base, breadcrumberAddr, (uint32_t)r4Value, arg3);
			r4Value = ctx.r4.u64;
			if ((result & 0xFF) != 0) {
				breadcrumber->m_14F = uint8_t(0);
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Value;
	return result;
}
PROMOTED_ENTRY(30, sub_824DA7D8, 0x824DA7D8) { ctx.r3.u64 = CECBreadcrumber_SetBreadcrumbText(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CECBreadcrumber_Reset(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(30, 0x824DB7E0)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_824DB7E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824DB7E0);
	uint32_t stack = ctx.r1.u64;
	const uint64_t defaultString = (uint64_t)(int64_t)g_82000C98;
	// the EntityHandle vtable 0x820F1664, formed (sign-extended) from 0x820F0000 as the original does
	const uint64_t entityHandleVtable = (uint64_t)((int64_t)g_820F0000 + 5732);
	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	CCharString_AssignFromCStr(ctx, base, breadcrumberAddr + 124, defaultString);

	// a null entity handle at stack+80, released once, is assigned to the handle at +0x80 and then destroyed
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)entityHandleVtable);
	// state the callee may pass on
	EntityHandle_Release(ctx, base, stack + 80);
	EntityHandle_Assign(ctx, base, breadcrumberAddr + 128, stack + 80);

	STORE32(stack + 80, (uint32_t)entityHandleVtable);
	// state the callee may pass on
	const uint64_t result = EntityHandle_Release(ctx, base, stack + 80);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(30, sub_824DB7E0, 0x824DB7E0) { ctx.r3.u64 = CECBreadcrumber_Reset(ctx, base, ctx.r3.u64); }

// Stores the value at 0x8331902C in m_E0 and a handle count derived from it in m_1B8, then resizes handle
// list [i] at +0xE4 to m_1B8 entries for each i below the count at 0x834982B8 + 8.
// Lists here are linked lists: +4 holds the end node, +8 the size; a node is { next, prev, value }.
uint64_t CECBreadcrumber_Reset_824DB8E8(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_834982B8 = int32_t(0x834982B8);
	if (!UseLiftedCode(30, 0x824DB8E8)) { ctx.r3.u64 = breadcrumberAddr; __imp__sub_824DB8E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824DB8E8);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	// CA is tracked below; SO keeps its entry value for the CR0 compares, as in the original
	PPCXERRegister xerState = ctx.xer;
	stack = PushStackFrame(base, stack, 208);

	const uint32_t rawValue = LOAD32(0x8331902Cu);
	ctx.r1.u64 = stack;
	uint64_t result = CECBreadcrumber_DestroyBreadcrumbs(ctx, base, breadcrumberAddr);
	PPCCRRegister cr0State = ctx.cr0;
	xerState.ca = ctx.xer.ca;
	breadcrumber->m_E0 = rawValue;

	// r7-r10 and f9-f13 as the original holds them at the calls below; r7, r8, f9-f13, CR0 and CA are
	// also what callers read after the call
	uint64_t r7Value = (uint64_t)(int64_t)g_83490000;
	uint64_t scaledRawValue = (uint64_t)(int64_t)(int32_t)(rawValue << 2);
	uint32_t r9Value = uint32_t(g_83320000);
	uint32_t r10Value = uint32_t(g_820F0000);

	// wanted handle count = float(rawValue * 4) * factor * factor, each product rounded to single precision;
	// the integer goes to the FPU through stack+104
	STORE64(stack + 104, scaledRawValue);
	ctx.fpscr.disableFlushMode();
	double scaledRawValueFloat = double(float((int64_t)scaledRawValue));
	const double firstScaleFactor = double(LOAD_F32(r9Value - 25200));
	double secondScaleFactor = double(LOAD_F32((uint32_t)r7Value + 27168));
	const uint32_t listCountAddr = uint32_t(g_834982B8) + 8;
	uint32_t index = 0;
	STORE32(stack + 80, index);
	double f11Value = double(float(scaledRawValueFloat * firstScaleFactor));
	double breadcrumbCountFloat = double(float(f11Value * secondScaleFactor));
	PPCRegister breadcrumbCount{};
	breadcrumbCount.s64 = std::isnan(breadcrumbCountFloat) ? int64_t(0x80000000U) : breadcrumbCountFloat > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&breadcrumbCountFloat));
	breadcrumber->m_1B8 = breadcrumbCount.u32;

	if (LOAD32(listCountAddr) != 0) {
		const uint64_t handleLists = breadcrumberAddr + 228;
		const uint32_t entityHandleVtable = uint32_t(g_820F1664);
		uint32_t listCount;
		do {
			// an empty entity handle at stack+88: released first, copied into new entries, destroyed at the end
			STORE32(stack + 88, entityHandleVtable);
			STORE32(stack + 92, 0);
			// state the callee may pass on
			ctx.f9 = breadcrumbCount;
			ctx.f10.f64 = breadcrumbCountFloat;
			ctx.f11.f64 = f11Value;
			ctx.f12.f64 = scaledRawValueFloat;
			ctx.f13.f64 = secondScaleFactor;
			ctx.cr0 = cr0State;
			ctx.xer.ca = xerState.ca;
			EntityHandle_Release(ctx, base, stack + 88);
			breadcrumbCount = ctx.f9;
			breadcrumbCountFloat = ctx.f10.f64;
			f11Value = ctx.f11.f64;
			scaledRawValueFloat = ctx.f12.f64;
			secondScaleFactor = ctx.f13.f64;
			cr0State = ctx.cr0;
			xerState.ca = ctx.xer.ca;

			const uint32_t wanted = breadcrumber->m_1B8;
			const uint64_t handleList = CECBreadcrumber_GetBreadcrumbList(ctx, base, handleLists, stack + 80);
			r7Value = ctx.r7.u64;
			scaledRawValue = ctx.r8.u64;
			r9Value = ctx.r9.u32;
			r10Value = ctx.r10.u32;
			breadcrumbCount = ctx.f9;
			breadcrumbCountFloat = ctx.f10.f64;
			f11Value = ctx.f11.f64;
			scaledRawValueFloat = ctx.f12.f64;
			secondScaleFactor = ctx.f13.f64;
			cr0State = ctx.cr0;
			xerState.ca = ctx.xer.ca;
			const uint32_t current = LOAD32((uint32_t)handleList + 8);

			if (wanted > current) {
				// append copies of the empty handle: insert before the end node through the iterator at stack+96
				r10Value = LOAD32((uint32_t)handleList + 4);
				uint32_t missing = wanted - current;
				cr0State.compare<int32_t>((int32_t)missing, 0, xerState);
				STORE32(stack + 96, (uint32_t)handleList);
				STORE32(stack + 100, r10Value);
				const uint64_t endIterator = LOAD64(stack + 96);
				do {
					// state the callee may pass on
					ctx.cr0 = cr0State;
					ctx.xer.ca = xerState.ca;
					List_InsertNodeWithCopyConstruct(ctx, base, (uint32_t)handleList, endIterator, stack + 88);
					r7Value = ctx.r7.u64;
					scaledRawValue = ctx.r8.u64;
					r9Value = ctx.r9.u32;
					r10Value = ctx.r10.u32;
					breadcrumbCount = ctx.f9;
					breadcrumbCountFloat = ctx.f10.f64;
					f11Value = ctx.f11.f64;
					scaledRawValueFloat = ctx.f12.f64;
					secondScaleFactor = ctx.f13.f64;
					xerState.ca = missing != 0;
					--missing;
					cr0State.compare<int32_t>((int32_t)missing, 0, xerState);
				} while (missing != 0);
			} else if (wanted < current) {
				// erase the last entry, through the iterator at stack+104, until the list holds `wanted` entries
				STORE32(stack + 104, (uint32_t)handleList);
				do {
					const uint32_t endNode = LOAD32((uint32_t)handleList + 4);
					const uint32_t lastNode = LOAD32(endNode + 4);
					STORE32(stack + 108, lastNode);
					if (lastNode == endNode) {
						ppc_trap(ctx, base, 22);
					}
					const uint64_t lastIterator = LOAD64(stack + 104);
					// state the callee may pass on
					EntityHandleList_EraseNode(ctx, base, stack + 112, handleList, lastIterator);
					r7Value = ctx.r7.u64;
					scaledRawValue = ctx.r8.u64;
					r9Value = ctx.r9.u32;
					r10Value = ctx.r10.u32;
					breadcrumbCount = ctx.f9;
					breadcrumbCountFloat = ctx.f10.f64;
					f11Value = ctx.f11.f64;
					scaledRawValueFloat = ctx.f12.f64;
					secondScaleFactor = ctx.f13.f64;
					cr0State = ctx.cr0;
					xerState.ca = ctx.xer.ca;
				} while (wanted < LOAD32((uint32_t)handleList + 8));
			}

			// destroy the temporary handle in place: drop the reference count at target+4 and free the
			// target once the count is zero and it holds no entity
			result = LOAD32(stack + 92);
			STORE32(stack + 88, entityHandleVtable);
			if ((uint32_t)result != 0) {
				const uint32_t oldCount = LOAD32((uint32_t)result + 4);
				const uint32_t newCount = oldCount - 1;
				xerState.ca = oldCount != 0;
				cr0State.compare<int32_t>((int32_t)newCount, 0, xerState);
				STORE32((uint32_t)result + 4, newCount);
				if (newCount == 0 && LOAD32((uint32_t)result) == 0) {
					// state the callee may pass on
					ctx.cr0 = cr0State;
					ctx.xer.ca = xerState.ca;
					result = HandleTarget_Free(ctx, base, result);
					r7Value = ctx.r7.u64;
					scaledRawValue = ctx.r8.u64;
					r9Value = ctx.r9.u32;
					r10Value = ctx.r10.u32;
					breadcrumbCount = ctx.f9;
					breadcrumbCountFloat = ctx.f10.f64;
					f11Value = ctx.f11.f64;
					scaledRawValueFloat = ctx.f12.f64;
					secondScaleFactor = ctx.f13.f64;
					cr0State = ctx.cr0;
					xerState.ca = ctx.xer.ca;
				}
			}

			listCount = LOAD32(listCountAddr);
			++index;
			STORE32(stack + 92, 0);
			STORE32(stack + 80, index);
		} while (index < listCount);
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = scaledRawValue;
	ctx.f9 = breadcrumbCount;
	ctx.f10.f64 = breadcrumbCountFloat;
	ctx.f11.f64 = f11Value;
	ctx.f12.f64 = scaledRawValueFloat;
	ctx.f13.f64 = secondScaleFactor;
	ctx.cr0 = cr0State;
	ctx.xer.ca = xerState.ca;
	return result;
}
PROMOTED_ENTRY(30, sub_824DB8E8, 0x824DB8E8) { ctx.r3.u64 = CECBreadcrumber_Reset_824DB8E8(ctx, base, ctx.r3.u64); }

// Adds the values (f1) two calls give for objects reached from the global at 0x83496920, using the float at
// 0x820994B4 (defaultValue) for a missing object; when the sum exceeds the float at byte 8 of the 16-byte
// vector at vectorAddr by more than defaultValue, the sum is merged into the vector (permute mask at
// 0x820991F0) and the function returns 1, otherwise what n_sub_8226AF00 returned.
uint64_t CECBreadcrumber_UpdateBreadcrumbValue(CpuState& ctx, uint8_t* base, uint64_t vectorAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(30, 0x824DC890)) { ctx.r4.u64 = vectorAddr; __imp__sub_824DC890(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824DC890);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	const uint32_t rootAddr = uint32_t(g_83490000) + 26912;
	const uint32_t vectorBlock = (uint32_t)vectorAddr & ~0xF;
	PPCVRegister vector{};
	stack = PushStackFrame(base, stack, 160);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	const uint64_t firstResult = n_sub_8226AF00(ctx, base, vectorAddr);

	SET_V8(vector, VLOAD(vectorBlock));
	uint32_t root = LOAD32(rootAddr);
	ctx.fpscr.disableFlushMode();
	const double defaultValue = double(LOAD_F32(0x820994B4u));

	// first value: n_sub_821EED10 on +36 -> +4 of the object at root +12, +88, +4, +8, +4
	const uint32_t nodeA = LOAD32(LOAD32(root + 12) + 88);
	const uint32_t nodeB = LOAD32(nodeA + 4);
	// r5-r8 as the original holds them at the two calls and leaves them for callers
	uint64_t r6Value = LOAD32(nodeB + 8);
	uint64_t r5Value = LOAD32((uint32_t)r6Value + 4);
	const uint32_t firstLink = LOAD32((uint32_t)r5Value + 36);
	double firstValue;
	if (firstLink != 0) {
		const uint32_t firstTarget = LOAD32(firstLink + 4);
		// state the callee may pass on
		ctx.v1 = vector;
		n_sub_821EED10(ctx, base, firstTarget);
		r5Value = ctx.r5.u64;
		r6Value = ctx.r6.u64;
		firstValue = ctx.f1.f64;
		root = LOAD32(rootAddr);
	} else {
		firstValue = defaultValue;
	}
	ctx.fpscr.disableFlushMode();

	// second value: n_sub_821EEB28 on the same chain, read again
	const uint32_t level12 = LOAD32(root + 12);
	SET_V8(vector, VLOAD(vectorBlock));
	uint64_t r8Value = LOAD32(LOAD32(LOAD32(level12 + 88) + 4) + 8);
	uint64_t r7Value = LOAD32((uint32_t)r8Value + 4);
	const uint32_t secondLink = LOAD32((uint32_t)r7Value + 36);
	double secondValue;
	if (secondLink != 0) {
		const uint32_t secondTarget = LOAD32(secondLink + 4);
		// state the callee may pass on
		ctx.v1 = vector;
		n_sub_821EEB28(ctx, base, secondTarget);
		r5Value = ctx.r5.u64;
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		secondValue = ctx.f1.f64;
	} else {
		ctx.fpscr.disableFlushMode();
		secondValue = defaultValue;
	}

	ctx.fpscr.disableFlushMode();
	const double sum = double(float(secondValue + firstValue));
	PPCVRegister current{};
	SET_V8(current, VLOAD(vectorBlock));
	VSTORE((stack + 96) & ~0xF, V8(current));
	PPCRegister difference{};
	difference.f64 = double(float(double(LOAD_F32(stack + 104)) - sum));
	PPCRegister excess{};
	excess.u64 = difference.u64 ^ 0x8000000000000000;

	if (excess.f64 > defaultValue) {
		STORE_F32(stack + 80, float(sum));
		PPCVRegister mergeMask{};
		SET_V8(mergeMask, VLOAD(0x820991F0u & ~0xF));
		PPCVRegister sumVector{};
		scratch.u32 = stack + 80;
		SET_V8(sumVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		PPCVRegister merged{};
		SET_V8(merged, rex::ppc::simde_mm_perm_epi8_(V8(current), V8(sumVector), V8(mergeMask)));
		VSTORE(vectorBlock, V8(merged));
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		// callers read these registers after the call
		ctx.r5.u64 = r5Value;
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.f1.f64 = secondValue;
		ctx.f11 = excess;
		ctx.v1 = vector;
		ctx.v11 = merged;
		ctx.v12 = sumVector;
		ctx.v13 = current;
		return 1;
	}
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r5.u64 = r5Value;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.f1.f64 = secondValue;
	ctx.f11 = excess;
	ctx.v1 = vector;
	ctx.v13 = current;
	return firstResult;
}
PROMOTED_ENTRY(30, sub_824DC890, 0x824DC890) { ctx.r3.u64 = CECBreadcrumber_UpdateBreadcrumbValue(ctx, base, ctx.r4.u64); }

// Returns 0 unless the entity handle at +0xC points at an entity flagged 0x40 at +144 and, when the low byte
// of ignoreNavigableCheck is 0, the point its +124 object gives (virtual +64) is navigable. Otherwise clears m_144's free
// nodes, hands that point to the +124 object of the owner entity m_4 (virtual +100), sets the owner's facing
// from GetFacingDirection, calls CECNavigation_ResetState with the owner's component 60, sets m_148 and returns 1.
uint64_t CECBreadcrumber_UpdateBreadcrumbPlacement(CpuState& ctx, uint8_t* base, uint64_t breadcrumberAddr, uint64_t ignoreNavigableCheck) {
	if (!UseLiftedCode(30, 0x824DCDA8)) { ctx.r3.u64 = breadcrumberAddr; ctx.r4.u64 = ignoreNavigableCheck; __imp__sub_824DCDA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824DCDA8);
	uint32_t stack = ctx.r1.u64;
	CECBreadcrumber* breadcrumber = GameObject<CECBreadcrumber>(base, breadcrumberAddr);
	// SO keeps its entry value for the CR0 compare below, as in the original
	const PPCXERRegister entryXer = ctx.xer;
	// r4, r7 and r10 as the original holds them for the calls and the early returns
	uint64_t r4Value = ignoreNavigableCheck;
	uint64_t isNavigable = ctx.r7.u64;
	uint64_t r10Value = ctx.r10.u64;
	PPCVRegister vector{};
	PPCRegister callTarget{};
	const uint64_t handleAddr = breadcrumberAddr + 12;
	stack = PushStackFrame(base, stack, 160);

	bool usable = false;
	const uint32_t handleTarget = breadcrumber->m_10;
	if (handleTarget != 0) {
		r10Value = LOAD32(handleTarget);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = r4Value;
		ctx.r10.u64 = r10Value;
		if ((uint32_t)r10Value == 0) {
			// the handle points at no entity: release it
			EntityHandle_Release(ctx, base, handleAddr);
			r4Value = ctx.r4.u64;
			isNavigable = ctx.r7.u64;
			r10Value = ctx.r10.u64;
		} else {
			const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
			r4Value = ctx.r4.u64;
			isNavigable = ctx.r7.u64;
			r10Value = LOAD8(entity + 144) & 0x40;
			usable = r10Value != 0;
		}
	}
	if (!usable) {
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		// callers read r4, r7 and r10 after the call
		ctx.r4.u64 = r4Value;
		ctx.r7.u64 = isNavigable;
		ctx.r10.u64 = r10Value;
		return 0;
	}

	if ((ignoreNavigableCheck & 0xFF) == 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = r4Value;
		const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
		// virtual +64 of the entity's +124 object writes its result to stack+96
		const uint32_t object = LOAD32(entity + 124);
		const uint32_t vtable = LOAD32(object);
		const uint32_t method = LOAD32(vtable + 64);
		callTarget.u64 = method;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = object;
		ctx.r9.u64 = method;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		SET_V8(vector, VLOAD((stack + 96) & ~0xF));
		// state the callee may pass on
		ctx.r8.u64 = stack + 96;
		ctx.v1 = vector;
		const uint64_t navigable = n_sub_821EC948(ctx, base, 0);  // Lua_Kynapse_IsPointNavigable
		r4Value = ctx.r4.u64;
		r10Value = ctx.r10.u64;
		isNavigable = navigable & 0xFF;
		if (isNavigable == 0) {
			stack = PopStackFrame(stack, 160);
			ctx.r1.u64 = stack;
			// callers read r4, r7 and r10 after the call
			ctx.r4.u64 = r4Value;
			ctx.r7.u64 = isNavigable;
			ctx.r10.u64 = r10Value;
			return 0;
		}
	}

	const uint32_t freeList = breadcrumber->m_144;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	List_ClearFreeNodes(ctx, base, freeList);

	// virtual +64 of the handle entity's +124 object writes its result to stack+112 ...
	const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
	const uint32_t object = LOAD32(entity + 124);
	const uint32_t vtable = LOAD32(object);
	const uint32_t method = LOAD32(vtable + 64);
	callTarget.u64 = method;
	ctx.r3.u64 = stack + 112;
	ctx.r4.u64 = object;
	ctx.r9.u64 = method;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// ... which virtual +100 of the owner's +124 object receives in v1
	const uint32_t owner = breadcrumber->m_4;
	const uint32_t ownerObject = LOAD32(owner + 124);
	SET_V8(vector, VLOAD((stack + 112) & ~0xF));
	const uint32_t ownerVtable = LOAD32(ownerObject);
	const uint32_t ownerMethod = LOAD32(ownerVtable + 100);
	callTarget.u64 = ownerMethod;
	// r3: the object; r5-r8 and v1 are state the callee may pass on
	ctx.r3.u64 = ownerObject;
	ctx.r5.u64 = ownerMethod;
	ctx.r6.u64 = ownerVtable;
	ctx.r7.u64 = owner;
	ctx.r8.u64 = stack + 112;
	ctx.v1 = vector;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// the owner's +124 object takes the vector GetFacingDirection gives for the handle entity's +124 object
	const uint32_t entityAgain = (uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr);
	const uint32_t facingObject = LOAD32(breadcrumber->m_4 + 124);
	const uint64_t direction = GetFacingDirection(ctx, base, stack + 80, LOAD32(entityAgain + 124));
	SET_V8(vector, VLOAD((uint32_t)direction & ~0xF));
	// state the callee may pass on
	ctx.v1 = vector;
	Entity_SetFacingDirectionNormalized(ctx, base, facingObject);
	// r6-r10, CR0 and CA handed to CECNavigation_ResetState: what the last call left, or the values of the lookup below
	uint64_t r6Value = ctx.r6.u64;
	isNavigable = ctx.r7.u64;
	r10Value = ctx.r10.u64;
	PPCCRRegister cr0State = ctx.cr0;
	uint8_t carry = ctx.xer.ca;

	// the owner's component with key 60: through the slot table at +140 when there is one, otherwise by a
	// lower_bound over the sorted (key, component) pairs in [+72, +76)
	const uint32_t ownerEntity = breadcrumber->m_4;  // m_4 read again after the calls
	uint32_t component = 0;
	uint64_t r9Value = LOAD32(ownerEntity + 40);
	uint64_t r8Value = ((uint32_t)r9Value >> 28) & 1;
	if (r8Value != 0) {
		const uint32_t slotTable = LOAD32(ownerEntity + 140);
		if (slotTable != 0) {
			r10Value = (uint32_t)(LOAD8(slotTable + 60) << 3);
			r9Value = r10Value + (uint64_t)LOAD32(ownerEntity + 72);
			component = LOAD32((uint32_t)r9Value + 4);
		} else {
			uint64_t pos = LOAD32(ownerEntity + 72);
			const uint64_t end = LOAD32(ownerEntity + 76);
			r6Value = end;
			r9Value = 0;
			STORE32(stack + 80, 0);
			r8Value = end - pos;
			STORE32(stack + 84, (uint32_t)pos);
			carry = (int32_t)r8Value < 0 && ((uint32_t)r8Value & 7) != 0;
			int32_t count = (int32_t)r8Value >> 3;
			cr0State.compare<int32_t>(count, 0, entryXer);
			if (count > 0) {
				do {
					carry = 0;
					const int32_t half = count >> 1;
					r9Value = (uint64_t)(int64_t)half;
					r8Value = (uint32_t)half << 3;
					pos += r8Value;
					const bool keyBelow = (int32_t)LOAD32((uint32_t)pos) < 60;
					isNavigable = keyBelow ? 1 : 0;
					if (keyBelow) {
						pos += 8;
						count = count - half - 1;
					} else {
						pos -= r8Value;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, (uint32_t)pos);
			}
			r10Value = pos;
			uint32_t found;
			if ((uint32_t)pos != (uint32_t)end && (int32_t)LOAD32((uint32_t)pos) <= 60) {
				STORE64(stack + 80, LOAD64(stack + 80));
				found = LOAD32(stack + 84);
			} else {
				// key not present: the original reads the word past the last pair
				found = (uint32_t)end;
			}
			component = LOAD32(found + 4);
		}
	}
	// state the callee may pass on
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = isNavigable;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = r9Value;
	ctx.cr0 = cr0State;
	ctx.xer.ca = carry;
	CECNavigation_ResetState(ctx, base, component);

	breadcrumber->m_148 = uint8_t(1);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(30, sub_824DCDA8, 0x824DCDA8) { ctx.r3.u64 = CECBreadcrumber_UpdateBreadcrumbPlacement(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Returns in f1 the float at +72 of the entity's active quest (found through its quest tracker, component
// type 102) unless that value is below the threshold at 0x820994B4; otherwise the integer at 0x83496A5C
// converted to float. r3 returns what the last call made here returned (the argument when none was made).
uint32_t CECBreadcrumber_GetActiveQuestValue(CpuState& ctx, uint8_t* base, uint64_t breadcrumber) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(30, 0x824DDF30)) { ctx.r3.u64 = breadcrumber; __imp__sub_824DDF30(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824DDF30);
	uint32_t stack = ctx.r1.u64;
	// Its summary-overflow bit goes into the cr0 handed to a callee below.
	const PPCXERRegister callerXer = ctx.xer;

	stack = PushStackFrame(base, stack, 112);
	// The entity handle at +12 points (at +16) to its target block, whose first word is the entity.
	const uint32_t handleTarget = LOAD32((uint32_t)breadcrumber + 16);
	const uint64_t entityHandleAddr = (int64_t)breadcrumber + 12;

	// The original converts the integer through the stack slot at +80.
	const int64_t globalValue = (int32_t)LOAD32(uint32_t(g_83490000) + 27228);
	STORE64(stack + 80, globalValue);
	const double globalAsDouble = double(globalValue);
	double result = double(float(globalAsDouble));

	uint32_t returnValue = (uint32_t)breadcrumber;
	// Bit 0x40 of the entity's byte at +144.
	uint32_t entityFlag = 0;
	if (handleTarget != 0) {
		const uint32_t targetEntity = LOAD32(handleTarget);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r9.u64 = globalValue;
		ctx.r10.u64 = targetEntity;
		ctx.f13.f64 = globalAsDouble;
		if (targetEntity == 0) {
			returnValue = (uint32_t)EntityHandle_Release(ctx, base, entityHandleAddr);
		} else {
			const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, entityHandleAddr);
			returnValue = entity;
			entityFlag = LOAD8(entity + 144) & 64;
		}
	}

	if (entityFlag != 0) {
		// state the callee may pass on (r9 and f13 still hold what the first call left)
		ctx.r1.u64 = stack;
		const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, entityHandleAddr);
		returnValue = entity;

		if ((LOAD32(entity + 48) >> 6) & 1) {
			// Component type 102: through the entity's index table at +140 when present, else by binary search
			// of its (type id, component) pairs at +72..+76, sorted by type id.
			uint32_t questTracker;
			const uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				const uint32_t pairOffset = (uint32_t)LOAD8(indexTable + 102) << 3;
				questTracker = LOAD32(pairOffset + LOAD32(entity + 72) + 4);
			} else {
				const uint32_t first = LOAD32(entity + 72);
				const uint32_t last = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, first);

				const uint32_t span = last - first;
				int32_t count = (int32_t)span >> 3;
				// cr0, the carry (only the first shift can set it) and r6 as this search leaves them; the next
				// callee receives them
				ctx.cr0.compare<int32_t>(count, 0, callerXer);
				ctx.xer.ca = (int32_t)span < 0 && (span & 7) != 0;
				ctx.r6.u64 = last;

				uint32_t pos = first;
				if (count > 0) {
					bool probeBelow;
					uint32_t probeStep;
					do {
						const int32_t half = count >> 1;
						probeStep = (uint32_t)half << 3;
						probeBelow = (int32_t)LOAD32(pos + probeStep) < 102;
						if (probeBelow) {
							pos = pos + probeStep + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, pos);
					// the last probe's registers, also handed to the next callee
					ctx.r7.u64 = probeBelow;
					ctx.r8.u64 = probeStep;
				}

				if (pos != last && (int32_t)LOAD32(pos) <= 102) {
					// the original copies the found position onto itself
					STORE64(stack + 80, LOAD64(stack + 80));
					questTracker = LOAD32(pos + 4);
				} else {
					questTracker = LOAD32(last + 4);
				}
			}

			const uint64_t questNameAddr = (uint64_t)stack + 80;
			CECQuestTracker_GetActiveQuestName(ctx, base, questNameAddr, questTracker);
			// f13 as the call left it, or the threshold once loaded; handed to the release call
			double f13Value = ctx.f13.f64;
			if (CCharString_NotEqualsEmptyOrLiteral(ctx, base, questNameAddr, g_82000C98) & 0xFF) {
				const uint32_t nameData = LOAD32(stack + 80);
				const uint64_t questNameText = (nameData == 0) ? (uint64_t)(int64_t)g_8209003F : (uint64_t)LOAD32(nameData);
				const uint32_t quest = (uint32_t)CECQuestTracker_FindQuestByNameHash(ctx, base, questTracker, questNameText);
				if (quest != 0) {
					ctx.fpscr.disableFlushMode();
					const double questValue = double(LOAD_F32(quest + 72));
					f13Value = double(LOAD_F32(0x820994B4u));
					// also taken when either value is NaN
					if (!(questValue < f13Value)) {
						result = questValue;
					}
				}
			}
			// state the callee may pass on
			ctx.f13.f64 = f13Value;
			returnValue = (uint32_t)CCharString_ReleaseAndDecGlobalCountA(ctx, base, questNameAddr);
		}
	}

	ctx.fpscr.disableFlushMode();
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = result;
	return returnValue;
}
PROMOTED_ENTRY(30, sub_824DDF30, 0x824DDF30) { ctx.r3.u64 = CECBreadcrumber_GetActiveQuestValue(ctx, base, ctx.r3.u64); }
