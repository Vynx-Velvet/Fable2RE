// CECDog (vtable 0x82003108): methods of the class as readable C++.
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

// Returns the object the handle at +300 refers to; a handle whose object is gone is released and 0 returned.
uint64_t n_sub_82174238(CpuState& ctx, uint8_t* base, uint64_t ownerAddr) {
	if (!UseLiftedCode(0, 0x82174238)) { ctx.r3.u64 = ownerAddr; __imp__sub_82174238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82174238);
	uint32_t stack = ctx.r1.u64;
	const uint64_t handleAddr = ownerAddr + 300;

	stack = PushStackFrame(base, stack, 96);

	const uint32_t handleEntry = LOAD32((uint32_t)handleAddr + 4);
	if (handleEntry != 0) {
		const uint32_t target = LOAD32(handleEntry);
		// callers read r10 after the call, and the release below receives it
		ctx.r10.u64 = target;
		if (target != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return target;
		}
		ctx.r1.u64 = stack;
		EntityHandle_Release(ctx, base, handleAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(0, sub_82174238, 0x82174238) { ctx.r3.u64 = n_sub_82174238(ctx, base, ctx.r3.u64); }

// When m_11C <= 1 and the count at 0x8331950C is past m_88: passes the first two components of a vector
// (truncated to int32) to n_sub_823509C8, hands its result to n_sub_827898B8, and sets m_88 to the count
// plus the double at 0x83319510.
uint32_t n_sub_821780B8(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(0, 0x821780B8)) { ctx.r3.u64 = dogAddr; __imp__sub_821780B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821780B8);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vec{};
	PPCRegister callTarget{};
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	// (int32) conversion with the NaN / overflow clamps the original code applies.
	auto toInt32 = [](double v) -> int64_t {
		if (std::isnan(v)) return int64_t(0x80000000U);
		if (v > double(INT_MAX)) return int64_t(INT_MAX);
		return int64_t(simde_mm_cvttsd_si32(simde_mm_load_sd(&v)));
	};

	stack = PushStackFrame(base, stack, 144);

	const uint32_t mode = dog->m_11C;
	if ((int32_t)mode <= 1) {
		const uint32_t count = LOAD32(0x8331950Cu);
		const uint32_t nextCount = dog->m_88;
		if ((int32_t)count > (int32_t)nextCount) {
			// Virtual call (vtable +64) on the object at m_4 +124; it writes a vector to the buffer at stack+96.
			const uint32_t source = LOAD32(uint32_t(dog->m_4) + 124);
			const uint32_t sourceVtable = LOAD32(source);
			const uint32_t getVector = LOAD32(sourceVtable + 64);
			callTarget.u64 = getVector;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = stack + 96;
			ctx.r4.u64 = source;
			ctx.r9.u64 = getVector;
			ctx.r10.u64 = sourceVtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			// The first two components, truncated to int32 through the stack slot, become the pair at stack+80.
			SET_V8(vec, VLOAD((stack + 96) & ~0xFu));
			VSTORE((stack + 80) & ~0xFu, V8(vec));
			ctx.fpscr.disableFlushMode();
			const double x = double(LOAD_F32(stack + 80));
			PPCRegister xInt{};
			xInt.s64 = toInt32(x);
			STORE_F64(stack + 80, xInt.f64);
			const uint32_t xInt32 = LOAD32(stack + 84);
			VSTORE((stack + 80) & ~0xFu, V8(vec));
			const uint32_t chainRoot = LOAD32(LOAD32(0x83496920u) + 12);
			const double y = double(LOAD_F32(stack + 84));
			PPCRegister yInt{};
			yInt.s64 = toInt32(y);
			STORE_F64(stack + 80, yInt.f64);
			const uint32_t link1 = LOAD32(chainRoot + 88);
			const uint32_t yInt32 = LOAD32(stack + 84);
			STORE32(stack + 80, xInt32);
			STORE32(stack + 84, yInt32);

			// Pointer chain +88, +4, +8, +4, then +36 and +4 from the object at 0x83496920 +12.
			const uint32_t link2 = LOAD32(link1 + 4);
			const uint32_t link3 = LOAD32(link2 + 8);
			const uint32_t link4 = LOAD32(link3 + 4);
			const uint32_t chainEnd = LOAD32(LOAD32(link4 + 36) + 4);

			// state the callee may pass on
			ctx.r6.u64 = link4;
			ctx.r7.u64 = link3;
			ctx.r8.u64 = link2;
			ctx.r9.u64 = link1;
			ctx.f11 = yInt;
			ctx.f12.f64 = y;
			ctx.f13 = xInt;
			const uint64_t found = n_sub_823509C8(ctx, base, chainEnd, stack + 80);
			// the last argument is r8 as n_sub_823509C8 left it
			n_sub_827898B8(ctx, base, dogAddr, found, 1, ctx.r8.u64);

			// m_88 = (int32)(count + the double at 0x83319510); the count is converted through the stack slot.
			const uint64_t countWide = (uint64_t)(int64_t)(int32_t)count;
			STORE64(stack + 80, countWide);
			ctx.fpscr.disableFlushMode();
			PPCRegister countReg{};
			countReg.f64 = LOAD_F64(stack + 80);
			const double sum = double(countReg.s64) + LOAD_F64(0x83319510u);
			PPCRegister sumInt{};
			sumInt.s64 = toInt32(sum);
			dog->m_88 = sumInt.u32;

			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			// callers read r4 and f10 after the call
			ctx.r4.u64 = countWide;
			ctx.f10 = countReg;
			// the original leaves this address base in r3
			return uint32_t(g_83320000);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return (uint32_t)dogAddr;
}
PROMOTED_ENTRY(0, sub_821780B8, 0x821780B8) { ctx.r3.u64 = n_sub_821780B8(ctx, base, ctx.r3.u64); }

// Lowers m_78 and m_7C by the same step, calls n_sub_82789AA8 when state 7's watched value (m_78 in phase 0,
// m_7C in phase 5) is not above the trigger level, then selects each value against the bound at 0x820994B4.
uint32_t n_sub_82186980(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(0, 0x82186980)) { ctx.r3.u64 = dogAddr; __imp__sub_82186980(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82186980);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t constBase = uint32_t(g_820994B4);
	const uint32_t selectTable = uint32_t(g_82100170);

	ctx.fpscr.disableFlushMode();

	// step = (double constant copied through the stack slot) / (double at 0x83319510 * double at 0x82000D58),
	// rounded to single precision
	const uint32_t wordHi = LOAD32(constBase + 27428);
	const uint32_t wordLo = LOAD32(constBase + 27432);
	STORE32(stack + 80, wordHi);
	STORE32(stack + 84, wordLo);
	const double denom = LOAD_F64(0x83319510u) * LOAD_F64(uint32_t(g_82000000) + 3416);
	const double quotient = LOAD_F64(stack + 80) / denom;
	const double step = double(float(quotient));

	const double origM78 = double(dog->m_78);
	const double origM7C = double(dog->m_7C);
	const double newM78 = double(float(origM78 - step));
	const double newM7C = double(float(origM7C - step));
	dog->m_78 = float(newM78);
	dog->m_7C = float(newM7C);

	const uint32_t state = dog->m_11C;
	if ((int32_t)state == 7) {
		const uint32_t phase = dog->m_114;
		const double trigger = double(LOAD_F32(constBase - 384));
		bool reached = false;
		if ((int32_t)phase == 0 && !(newM78 > trigger)) {
			reached = true;
		} else if ((int32_t)phase == 5) {
			ctx.fpscr.disableFlushMode();
			reached = !(newM7C > trigger);
		}
		if (reached) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r6.u64 = wordLo;
			ctx.r7.u64 = wordHi;
			ctx.r9.u64 = uint32_t(g_82000000);
			ctx.f8.f64 = step;
			ctx.f9.f64 = quotient;
			ctx.f10.f64 = denom;
			ctx.f11.f64 = origM7C;
			ctx.f12.f64 = trigger;
			ctx.f13.f64 = newM7C;
			n_sub_82789AA8(ctx, base, dogAddr, state);
		}
	}


	// a value is kept or replaced by the bound.
	ctx.fpscr.disableFlushMode();
	const double bound = double(LOAD_F32(constBase));

	const double curM78 = double(dog->m_78);
	const uint32_t m78Below = curM78 < bound ? 4u : 0u;
	const uint32_t m78Unordered = (std::isnan(curM78) || std::isnan(bound)) ? 4u : 0u;
	const uint32_t m78Index = m78Below | m78Unordered;
	const double m78Select = double(LOAD_F32(selectTable + m78Index));
	const double m78Result = m78Select >= 0.0 ? curM78 : bound;
	dog->m_78 = float(m78Result);

	const double curM7C = double(dog->m_7C);
	const uint32_t m7CBelow = curM7C < bound ? 4u : 0u;
	const uint32_t m7CUnordered = (std::isnan(curM7C) || std::isnan(bound)) ? 4u : 0u;
	const double m7CSelect = double(LOAD_F32(selectTable + (m7CBelow | m7CUnordered)));
	dog->m_7C = float(m7CSelect >= 0.0 ? curM7C : bound);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these after the call (r7: the table address, sign-extended)
	ctx.r4.u64 = m7CBelow;
	ctx.r6.u64 = m78Index;
	ctx.r7.u64 = uint64_t(g_82100170);
	ctx.r8.u64 = m78Unordered;
	ctx.r9.u64 = m78Below;
	ctx.f10.f64 = curM7C;
	ctx.f11.f64 = m78Result;
	ctx.f12.f64 = m78Select;
	ctx.f13.f64 = curM78;
	return m7CUnordered;
}
PROMOTED_ENTRY(0, sub_82186980, 0x82186980) { ctx.r3.u64 = n_sub_82186980(ctx, base, ctx.r3.u64); }

// If the handle at +300 still has an object and both it and the entity at m_4 have component 2: a vector from
// each component is tested against a squared-length limit, and each component's vtable +152 method gets the
// other entity and the result (1 = both within the limit). A handle whose object is gone is released.
uint32_t CECDog_UpdateFetchTarget(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(11, 0x822AEF78)) { ctx.r3.u64 = dogAddr; __imp__sub_822AEF78(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822AEF78);
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vec{};
	PPCVRegister lengthSq{};
	PPCRegister callTarget{};
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 160);

	const uint64_t handleAddr = dogAddr + 300;
	const uint32_t entity = dog->m_4;
	const uint32_t handleEntry = LOAD32((uint32_t)handleAddr + 4);
	if (handleEntry == 0) {
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return (uint32_t)handleAddr;
	}
	const uint32_t target = LOAD32(handleEntry);
	if (target == 0) {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 0;  // state the callee may pass on (the null object pointer)
		const uint32_t released = EntityHandle_Release(ctx, base, handleAddr);
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		return released;
	}

	// r6-r9 and the carry as the component searches below leave them (the caller's where they do not run);
	// the first virtual call receives them, and callers read them when no call is made.
	uint64_t searchR6 = ctx.r6.u64;
	uint64_t searchR7 = ctx.r7.u64;
	uint64_t searchR8 = ctx.r8.u64;
	uint64_t searchR9 = ctx.r9.u64;
	uint8_t searchCarry = ctx.xer.ca;

	// Component 2 of an entity: bit 2 of the mask word at +36 says it has one. The byte table at +140, when
	// present, gives its index in the (type, component) pairs at +72..+76; otherwise the pairs are searched.
	auto findComponent2 = [&](uint32_t owner, uint32_t& component) -> bool {
		if (((LOAD32(owner + 36) >> 2) & 1) == 0) {
			return false;
		}
		const uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			searchR9 = ((uint64_t)LOAD8(indexTable + 2) << 3) + (uint64_t)LOAD32(owner + 72);
			component = LOAD32((uint32_t)searchR9 + 4);
			return true;
		}
		const uint32_t begin = LOAD32(owner + 72);
		const uint32_t end = LOAD32(owner + 76);
		searchR6 = end;
		STORE32(stack + 80, 0u);
		searchR9 = (uint64_t)end - (uint64_t)begin;
		STORE32(stack + 84, begin);
		const int32_t byteCount = (int32_t)searchR9;
		searchCarry = byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = byteCount >> 3;

		// lower_bound for type 2 (keys compare signed)
		uint32_t it = begin;
		if (count > 0) {
			// halving a positive count clears the carry
			searchCarry = 0;
			do {
				const int32_t half = count >> 1;
				const uint32_t stepBytes = (uint32_t)half << 3;
				const uint32_t mid = it + stepBytes;
				const bool below = (int32_t)LOAD32(mid) < 2;
				searchR7 = below ? 1 : 0;
				searchR8 = stepBytes;
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
		if (it != end && (int32_t)LOAD32(it) <= 2) {
			component = LOAD32(it + 4);
		} else {
			component = LOAD32(end + 4);
		}
		return true;
	};

	uint32_t entityComponent = 0;
	uint32_t targetComponent = 0;
	if (!findComponent2(entity, entityComponent) || !findComponent2(target, targetComponent)) {
		stack = PopStackFrame(stack, 160);
		ctx.r1.u64 = stack;
		// callers read these after the call
		ctx.r6.u64 = searchR6;
		ctx.r7.u64 = searchR7;
		ctx.r8.u64 = searchR8;
		ctx.r9.u64 = searchR9;
		ctx.xer.ca = searchCarry;
		return (uint32_t)handleAddr;
	}

	// Each component's vtable +76 method (given the buffer at stack+80) returns the address of a vector; the
	// squared length of its first three components is compared with the limit at 0x820A0000-19252.
	const uint32_t entityGetVector = LOAD32(LOAD32(entityComponent) + 76);
	callTarget.u64 = entityGetVector;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = stack + 80;
	ctx.r4.u64 = entityComponent;
	// state the callee may pass on
	ctx.r6.u64 = searchR6;
	ctx.r7.u64 = searchR7;
	ctx.r8.u64 = searchR8;
	ctx.r9.u64 = searchR9;
	ctx.r10.u64 = entityGetVector;
	ctx.xer.ca = searchCarry;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	SET_V8(vec, VLOAD(ctx.r3.u32 & ~0xF));
	ctx.fpscr.enableFlushMode();
	SET_VF(lengthSq, simde_mm_dp_ps(VF(vec), VF(vec), 0xEF));
	ctx.fpscr.disableFlushModeUnconditional();
	const float limit = LOAD_F32(uint32_t(g_820A0000) - 19252);
	VSTORE((stack + 80) & ~0xF, V8(lengthSq));
	const float entityLengthSq = LOAD_F32(stack + 80);

	// The sign-extended address base the original keeps in r8; the second vector call may change it.
	uint64_t passedR8 = uint64_t(g_820A0000);
	bool withinLimit = false;
	if (!(entityLengthSq > limit)) {
		const uint32_t targetGetVector = LOAD32(LOAD32(targetComponent) + 76);
		callTarget.u64 = targetGetVector;
		ctx.r3.u64 = stack + 80;
		ctx.r4.u64 = targetComponent;
		// state the callee may pass on
		ctx.r8.u64 = passedR8;
		ctx.r9.u64 = stack + 80;
		ctx.r10.u64 = targetGetVector;
		ctx.v13 = lengthSq;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		passedR8 = ctx.r8.u64;
		SET_V8(vec, VLOAD(ctx.r3.u32 & ~0xF));
		ctx.fpscr.enableFlushMode();
		SET_VF(lengthSq, simde_mm_dp_ps(VF(vec), VF(vec), 0xEF));
		VSTORE((stack + 80) & ~0xF, V8(lengthSq));
		ctx.fpscr.disableFlushModeUnconditional();
		const float targetLengthSq = LOAD_F32(stack + 80);
		withinLimit = !(targetLengthSq > limit);
	}
	const uint64_t withinFlag = withinLimit ? 1 : 0;

	const uint32_t entityMethod152 = LOAD32(LOAD32(entityComponent) + 152);
	callTarget.u64 = entityMethod152;
	ctx.r3.u64 = entityComponent;
	ctx.r4.u64 = target;
	ctx.r5.u64 = withinFlag;
	// state the callee may pass on
	ctx.r8.u64 = passedR8;
	ctx.r9.u64 = stack + 80;
	ctx.r10.u64 = entityMethod152;
	ctx.v13 = lengthSq;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	const uint32_t targetVtable = LOAD32(targetComponent);
	const uint32_t targetMethod152 = LOAD32(targetVtable + 152);
	callTarget.u64 = targetMethod152;
	ctx.r3.u64 = targetComponent;
	ctx.r4.u64 = entity;
	ctx.r5.u64 = withinFlag;
	// state the callee may pass on
	ctx.r8.u64 = targetMethod152;
	ctx.r9.u64 = targetVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	const uint32_t result = ctx.r3.u32;

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(11, sub_822AEF78, 0x822AEF78) { ctx.r3.u64 = CECDog_UpdateFetchTarget(ctx, base, ctx.r3.u64); }

// When the entity at m_4 has component 24, n_sub_82500CB0 finds through it an entity by the hash of the
// str_TXT_820019B0_B_ string. A newly found valid entity becomes m_17C, and the member at +1032 is given the
// str_TXT_820D4B1C_B_ string (or the non-empty string n_sub_82345978 returns for str_TXT_820D4B30_B_ from the
// entity's component 83); with no valid entity, n_sub_8277DC78 may run on that member and clear m_17C.
uint32_t n_sub_822B1A00(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t str_TXT_820019B0_B_ = int32_t(0x820019B0);
	constexpr int32_t str_TXT_820D4B1C_B_ = int32_t(0x820D4B1C);
	constexpr int32_t str_TXT_820D4B30_B_ = int32_t(0x820D4B30);
	constexpr int32_t TXT_8349B370_G_ = int32_t(0x8349B370);
	if (!UseLiftedCode(12, 0x822B1A00)) { ctx.r3.u64 = dogAddr; __imp__sub_822B1A00(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822B1A00);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 144);

	// r6-r9, cr0 and the carry as the component searches below leave them (the registers they start from where
	// they do not run); the next call receives them. xer.so is the caller's throughout.
	uint64_t searchR6 = ctx.r6.u64;
	uint64_t searchR7 = ctx.r7.u64;
	uint64_t searchR8 = ctx.r8.u64;
	uint64_t searchR9 = 0;  // starts as the mask bit tested below
	PPCCRRegister searchCr0 = ctx.cr0;
	PPCXERRegister searchXer = ctx.xer;

	// Component `type` of an entity whose mask bit is set: the byte table at +140, when present, gives its index
	// in the (type, component) pairs at +72..+76; otherwise the pairs are searched, with the iterator pair kept
	// at stack+scratch.
	auto findComponent = [&](uint32_t owner, int32_t type, uint32_t scratch) -> uint32_t {
		const uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			searchR9 = ((uint64_t)LOAD8(indexTable + type) << 3) + (uint64_t)LOAD32(owner + 72);
			return LOAD32((uint32_t)searchR9 + 4);
		}
		const uint32_t begin = LOAD32(owner + 72);
		const uint32_t end = LOAD32(owner + 76);
		searchR6 = end;
		STORE32(stack + scratch, 0);
		const uint32_t byteCount = end - begin;
		STORE32(stack + scratch + 4, begin);
		searchXer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = (int32_t)byteCount >> 3;
		searchCr0.compare<int32_t>(count, 0, searchXer);

		// lower_bound for `type` (keys compare signed)
		uint32_t it = begin;
		if (count > 0) {
			// halving a positive count clears the carry
			searchXer.ca = 0;
			do {
				const int32_t half = count >> 1;
				const uint32_t stepBytes = (uint32_t)half << 3;
				const uint32_t mid = it + stepBytes;
				const bool below = (int32_t)LOAD32(mid) < type;
				searchR7 = below ? 1 : 0;
				searchR8 = stepBytes;
				searchR9 = (uint64_t)(int64_t)half;
				if (below) {
					it = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + scratch + 4, it);
		}
		// a missing type reads the pair at `end`
		if (it != end && (int32_t)LOAD32(it) <= type) {
			return LOAD32(it + 4);
		}
		return LOAD32(end + 4);
	};

	// Component 24 of the entity at m_4: bit 24 of the mask word at +36 (the low bit of its first byte).
	const uint32_t entity = dog->m_4;
	searchR9 = LOAD8(entity + 36) & 1;
	if (searchR9 == 0) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		ctx.r9.u64 = 0;  // callers read r9 after the call
		return (uint32_t)dogAddr;
	}
	const uint32_t component24 = findComponent(entity, 24, 88);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r6.u64 = searchR6;
	ctx.r7.u64 = searchR7;
	ctx.r8.u64 = searchR8;
	ctx.r9.u64 = searchR9;
	ctx.cr0 = searchCr0;
	ctx.xer.ca = searchXer.ca;
	CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820019B0_B_, -1);
	const uint64_t nameHash = String_HashCrc32(ctx, base, stack + 88);
	const uint32_t carried = n_sub_82500CB0(ctx, base, component24, nameHash);
	const uint32_t releaseResult = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

	if (carried != 0 && (LOAD8(carried + 144) & 64) != 0) {
		if (carried == dog->m_17C) {
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return releaseResult;
		}
		dog->m_17C = carried;
		CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820D4B1C_B_, -1);

		// Component 83 of the carried entity: bit 19 of the mask word at +44. The search starts from the
		// registers the construction left (r7 and r8 as 32-bit values).
		searchR6 = ctx.r6.u64;
		searchR7 = ctx.r7.u32;
		searchR8 = ctx.r8.u32;
		searchCr0 = ctx.cr0;
		searchXer.ca = ctx.xer.ca;
		searchR9 = (LOAD32(carried + 44) >> 19) & 1;
		if (searchR9 != 0) {
			const uint32_t component83 = findComponent(carried, 83, 80);
			// state the callee may pass on
			ctx.r6.u64 = searchR6;
			ctx.r7.u64 = searchR7;
			ctx.r8.u64 = searchR8;
			ctx.r9.u64 = searchR9;
			ctx.cr0 = searchCr0;
			ctx.xer.ca = searchXer.ca;
			const uint64_t idSource = n_sub_821D9F40(ctx, base, stack + 96, component83);
			const uint64_t idRef = IdRef_Get(ctx, base, idSource);
			ctx.r7.u64 = uint64_t(str_TXT_820D4B30_B_);  // state the callee may pass on (sign-extended)
			const uint64_t animName = n_sub_82345978(ctx, base, idRef, str_TXT_820D4B30_B_);
			CCharString_ConstructFromCStr(ctx, base, stack + 80, animName, -1);
			// a non-empty name replaces the default
			const uint32_t nameData = LOAD32(stack + 80);
			if (nameData != 0 && LOAD32(nameData + 4) != 0) {
				CCharString_Assign(ctx, base, stack + 88, stack + 80);
			}
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		} else {
			ctx.r9.u64 = 0;  // state the next call may pass on (the clear mask bit)
		}

		const uint64_t memberAddr = dogAddr + 1032;
		n_sub_8277D2D0(ctx, base, memberAddr, dog->m_4, stack + 88, TXT_8349B370_G_, 5, 4);
		n_sub_8277D960(ctx, base, memberAddr, dog->m_4, -1, 255);
		const uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	// No valid entity: with m_41C set, n_sub_8277DC78 runs when its +24 value * c + its +20 value
	// (fused, rounded to single) exceeds c, the float at 0x820994B4.
	const uint32_t carryState = dog->m_41C;
	const uint64_t memberAddr = dogAddr + 1032;
	if (carryState != 0) {
		ctx.fpscr.disableFlushMode();
		const double value24 = double(LOAD_F32(carryState + 24));
		const double value20 = double(LOAD_F32(carryState + 20));
		const double c = double(LOAD_F32(0x820994B4u));
		const double combined = double(float(std::fma(value24, c, value20)));
		// the callee receives these and callers read them after the call
		ctx.f11.f64 = combined;
		ctx.f12.f64 = value20;
		ctx.f13.f64 = value24;
		if (combined > c) {
			const uint32_t result = n_sub_8277DC78(ctx, base, memberAddr, dog->m_4);
			dog->m_17C = 0;
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return result;
		}
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return (uint32_t)memberAddr;
}
PROMOTED_ENTRY(12, sub_822B1A00, 0x822B1A00) { ctx.r3.u64 = n_sub_822B1A00(ctx, base, ctx.r3.u64); }

// Stores at +1152 the vector from the object at m_4 +124 plus the scaled, normalized negation of what
// Quat_MultiplyAndReturn returns for that object's quaternion; returns the address of the normalized vector.
uint64_t n_sub_822BDA90(CpuState& ctx, uint8_t* base, uint32_t dogAddr) {
	if (!UseLiftedCode(12, 0x822BDA90)) { ctx.r3.u64 = dogAddr; __imp__sub_822BDA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BDA90);
	PPCRegister scratch{};
	PPCRegister callTarget{};
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	// The original saves v127 below its frame; it uses v127 for the sign mask and restores it on return.
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 160);

	const uint64_t baseVecAddr = (uint64_t)stack + 112;
	const uint64_t dirAddr = (uint64_t)stack + 96;

	// Virtual call (vtable +64) on the object at m_4 +124: writes a vector to stack+112.
	const uint32_t source = LOAD32(uint32_t(dog->m_4) + 124);
	const uint32_t sourceVtable = LOAD32(source);
	const uint32_t getVector = LOAD32(sourceVtable + 64);
	callTarget.u64 = getVector;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = baseVecAddr;
	ctx.r4.u64 = source;
	ctx.r9.u64 = getVector;
	ctx.r10.u64 = sourceVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// Virtual call (vtable +68) on the same object, reloaded through m_4, with the buffer at stack+96:
	// returns the address of a quaternion.
	const uint32_t entity = dog->m_4;
	const uint32_t source2 = LOAD32(entity + 124);
	const uint32_t source2Vtable = LOAD32(source2);
	const uint32_t getQuat = LOAD32(source2Vtable + 68);
	callTarget.u64 = getQuat;
	ctx.r3.u64 = dirAddr;
	ctx.r4.u64 = source2;
	ctx.r6.u64 = getQuat;
	ctx.r7.u64 = source2Vtable;
	ctx.r8.u64 = entity;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	const uint64_t quatAddr = ctx.r3.u64;

	// 0xFFFFFFFF << 31 in every lane: the float sign bit, used to negate the vector below.
	PPCVRegister signMask{};
	SET_V8(signMask, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	SET_V8(signMask, simde_mm_sllv_epi32(V8(signMask), simde_mm_and_si128(V8(signMask), simde_mm_set1_epi32(0x1F))));

	const uint64_t quatLow = LOAD64((uint32_t)quatAddr);
	const uint64_t quatHigh = LOAD64((uint32_t)quatAddr + 8);
	ctx.r5.u64 = quatAddr;  // state the callee may pass on
	Quat_MultiplyAndReturn(ctx, base, quatLow, quatHigh);

	// The negated result (v1) is normalized in place at stack+96.
	PPCVRegister negated{};
	SET_V8(negated, simde_mm_xor_si128(V8(ctx.v1), V8(signMask)));
	VSTORE((uint32_t)dirAddr & ~0xF, V8(negated));
	ctx.fpscr.disableFlushMode();
	const double length = Vec4_NormalizeInPlace_ReturnLength(ctx, base, dirAddr, double(LOAD_F32(0x82099AE0u)));

	// +1152 = normalized * (the float at 0x8209D04C, splatted through the stack slot) + the first vector
	ctx.fpscr.disableFlushMode();
	STORE_F32(stack + 80, float(double(LOAD_F32(0x8209D04Cu))));
	scratch.u32 = uint32_t(stack + 80);
	PPCVRegister scaleVec{};
	SET_V8(scaleVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	PPCVRegister splatScale{};
	SET_V8(splatScale, simde_mm_shuffle_epi32(V8(scaleVec), 0xFF));
	PPCVRegister baseVec{};
	SET_V8(baseVec, VLOAD((uint32_t)baseVecAddr & ~0xF));
	PPCVRegister dir{};
	SET_V8(dir, VLOAD((uint32_t)dirAddr & ~0xF));
	ctx.fpscr.enableFlushModeUnconditional();
	PPCVRegister result{};
	SET_VF(result, simde_mm_add_ps(simde_mm_mul_ps(VF(dir), VF(splatScale)), VF(baseVec)));
	VSTORE((dogAddr + 1152) & ~0xF, V8(result));

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r4.u64 = dirAddr;
	ctx.r6.u64 = 1152;
	ctx.f1.f64 = length;
	ctx.v9 = result;
	ctx.v10 = dir;
	ctx.v11 = baseVec;
	ctx.v12 = splatScale;
	ctx.v13 = scaleVec;
	return dirAddr;
}
PROMOTED_ENTRY(12, sub_822BDA90, 0x822BDA90) { ctx.r3.u64 = n_sub_822BDA90(ctx, base, ctx.r3.u32); }

// sub_822D1CB8  [1272 bytes]
uint32_t n_sub_822D1CB8(CpuState& ctx, uint8_t* base, uint64_t dogAddr, uint64_t targetAddr) {
	constexpr int32_t str_TXT_820BDC44_B_ = int32_t(0x820BDC44);
	constexpr int32_t str_TXT_820C7554_B_ = int32_t(0x820C7554);
	if (!UseLiftedCode(13, 0x822D1CB8)) { ctx.r3.u64 = dogAddr; ctx.r4.u64 = targetAddr; __imp__sub_822D1CB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822D1CB8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	const uint32_t target = (uint32_t)targetAddr;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	// Register values the original code hands to some callees and leaves for its callers.
	uint64_t regR4 = targetAddr;
	uint64_t regR6 = ctx.r6.u64;
	uint64_t regR7 = ctx.r7.u64;
	uint64_t regR8 = ctx.r8.u64;
	uint64_t regR9 = ctx.r9.u64;
	uint64_t regR10 = 0;
	PPCXERRegister xer = ctx.xer;

	// How the last findComponent reached its entry: through the index table
	// (indexOffset = table byte * 8, slotAddr = the entry) or by search (searchPos).
	bool viaIndexTable = false;
	uint64_t indexOffset = 0;
	uint64_t slotAddr = 0;
	uint64_t searchPos = 0;

	// Component `componentId` of `entity`: read through the entity's index table when it
	// has one, otherwise found by a lower-bound binary search of its sorted
	// (componentId, component) pairs, with the iterator kept at stack+80/+84.
	// The search leaves the end pointer in r6 and its last step in r7-r9 and xer.ca.
	auto findComponent = [&](uint32_t entity, uint32_t componentId) -> uint32_t {
		uint32_t indexTable = LOAD32(entity + 0x8C);
		if (indexTable != 0) {
			viaIndexTable = true;
			indexOffset = (uint32_t)LOAD8(indexTable + componentId) << 3;
			slotAddr = indexOffset + LOAD32(entity + 0x48);
			return LOAD32((uint32_t)slotAddr + 4);
		}
		viaIndexTable = false;
		uint32_t begin = LOAD32(entity + 0x48);
		uint32_t end = LOAD32(entity + 0x4C);
		regR6 = end;
		STORE32(stack + 80, 0);
		uint32_t byteSpan = end - begin;
		STORE32(stack + 84, begin);
		xer.ca = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
		int32_t remaining = (int32_t)byteSpan >> 3;
		searchPos = begin;
		if (remaining > 0) {
			xer.ca = 0;  // halving a positive count shifts no bits out
			do {
				int32_t half = remaining >> 1;
				uint32_t step = (uint32_t)half << 3;
				searchPos += step;
				regR7 = (int32_t)LOAD32((uint32_t)searchPos) < (int32_t)componentId;
				regR8 = step;
				regR9 = half;
				if (regR7 != 0) {
					remaining = remaining - half - 1;
					searchPos += 8;
				} else {
					searchPos -= step;
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 84, (uint32_t)searchPos);
		}
		if ((uint32_t)searchPos != end && (int32_t)LOAD32((uint32_t)searchPos) <= (int32_t)componentId) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	auto meetsRequirements = [&]() -> uint32_t {
		// When flagged, a silver key lock (component 40) must have both flag bytes clear,
		// and when it needs a positive number of silver keys the bombard target, when it
		// is flagged for an inventory (component 13), must hold at least that many.
		if (((LOAD32(target + 0x28) >> 8) & 1) != 0) {
			uint32_t keyLock = findComponent(target, 40);
			if (viaIndexTable) regR9 = slotAddr;
			regR10 = LOAD8(keyLock + 0x0C);
			if (regR10 != 0) return 0;
			regR10 = LOAD8(keyLock + 0x0D);
			if (regR10 != 0) return 0;
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r6.u64 = regR6;
			ctx.r7.u64 = regR7;
			ctx.r8.u64 = regR8;
			ctx.r9.u64 = regR9;
			ctx.r10.u64 = regR10;
			ctx.xer.ca = xer.ca;
			uint64_t lockRef = n_sub_821D9F40(ctx, base, stack + 80, keyLock);
			xer.ca = ctx.xer.ca;
			uint64_t lockId = IdRef_Get(ctx, base, lockRef);
			ctx.r7.u64 = str_TXT_820BDC44_B_;  // state the callee may pass on
			int32_t TXT_820BDC44_L_ = GameDB_GetIntByName(ctx, base, lockId, str_TXT_820BDC44_B_);
			regR4 = ctx.r4.u64;
			regR6 = ctx.r6.u64;
			regR7 = ctx.r7.u64;
			regR8 = ctx.r8.u64;
			if (TXT_820BDC44_L_ > 0) {
				uint32_t bombardTarget = n_sub_82174238(ctx, base, dogAddr);
				regR4 = ctx.r4.u64;
				regR6 = ctx.r6.u64;
				regR7 = ctx.r7.u64;
				regR8 = ctx.r8.u64;
				regR9 = ctx.r9.u64;
				xer.ca = ctx.xer.ca;
				if (((LOAD32(bombardTarget + 0x24) >> 13) & 1) != 0) {
					uint32_t inventory = findComponent(bombardTarget, 13);
					if (viaIndexTable) {
						regR9 = slotAddr;
						regR10 = indexOffset;
					} else {
						regR10 = searchPos;
					}
					// state the callee may pass on
					ctx.r6.u64 = regR6;
					ctx.r7.u64 = regR7;
					ctx.r8.u64 = regR8;
					ctx.r9.u64 = regR9;
					ctx.r10.u64 = regR10;
					ctx.xer.ca = xer.ca;
					CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820C7554_B_, -1);
					int32_t silverKeysHeld = ItemList_CountByTypeName(ctx, base, inventory, stack + 80);
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
					regR4 = ctx.r4.u64;
					regR6 = ctx.r6.u64;
					regR7 = ctx.r7.u64;
					regR8 = ctx.r8.u64;
					regR9 = ctx.r9.u64;
					regR10 = ctx.r10.u64;
					xer.ca = ctx.xer.ca;
					if (silverKeysHeld < TXT_820BDC44_L_) return 0;
				}
			}
		}
		// When flagged, component 95 must have its byte at +0x12 set and its value at
		// +0x0C must not exceed the dog's m_B8.
		regR9 = LOAD32(target + 0x2C) >> 31;
		if (regR9 != 0) {
			uint32_t limitComponent = findComponent(target, 95);
			if (viaIndexTable) regR9 = slotAddr;
			regR10 = LOAD8(limitComponent + 0x12);
			if (regR10 == 0) return 0;
			int32_t limit = LOAD32(limitComponent + 0x0C);
			regR10 = dog->m_B8;
			if (limit > (int32_t)regR10) return 0;
		}
		// Finally the target must be flagged for component 241 with its byte at +0x0C set.
		regR9 = (LOAD32(target + 0x40) >> 17) & 1;
		if (regR9 == 0) {
			regR10 = 0;
			return 0;
		}
		uint32_t usability = findComponent(target, 241);
		regR10 = 1;
		return LOAD8(usability + 0x0C) != 0 ? 1 : 0;
	};

	uint32_t result = meetsRequirements();

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = regR4;
	ctx.r6.u64 = regR6;
	ctx.r7.u64 = regR7;
	ctx.r8.u64 = regR8;
	ctx.r9.u64 = regR9;
	ctx.r10.u64 = regR10;
	ctx.xer.ca = xer.ca;
	return result;
}
PROMOTED_ENTRY(13, sub_822D1CB8, 0x822D1CB8) { ctx.r3.u64 = n_sub_822D1CB8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECDog_IsHealthLow(CpuState& ctx, uint8_t* base, uint32_t dogAddr) {
	if (!UseLiftedCode(13, 0x822D3240)) { ctx.r3.u64 = dogAddr; __imp__sub_822D3240(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3240);
	uint32_t stack = ctx.r1.u32;

	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	uint32_t creature = dog->m_4;
	uint32_t creatureFlags = LOAD32(creature + 40);

	// Register values the original code leaves for its callers.
	uint64_t regR6 = ctx.r6.u64;
	uint64_t regR7 = ctx.r7.u64;
	uint64_t regR8 = (creatureFlags >> 4) & 1;
	uint64_t regR9 = creatureFlags;
	double regF12 = ctx.f12.f64;
	double regF13 = ctx.f13.f64;
	PPCCRRegister regCr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;

	// Component 36 of the creature: read through its index table when it has one,
	// otherwise found by a lower-bound binary search of its sorted (id, component)
	// pairs, with the iterator kept at stack-16/-12.
	uint32_t healthRecord = 0;
	bool hasRecord = false;
	if (((creatureFlags >> 4) & 1) != 0) {
		uint32_t indexTable = LOAD32(creature + 140);
		if (indexTable != 0) {
			uint32_t slotOffset = (uint32_t)LOAD8(indexTable + 36) << 3;
			regR9 = (uint64_t)slotOffset + LOAD32(creature + 72);
			healthRecord = LOAD32((uint32_t)regR9 + 4);
		} else {
			uint32_t begin = LOAD32(creature + 72);
			uint32_t end = LOAD32(creature + 76);
			regR6 = end;
			regR9 = 0;
			STORE32(stack - 16, 0);
			regR8 = (uint64_t)end - begin;
			STORE32(stack - 12, begin);
			xer.ca = (int32_t)regR8 < 0 && ((uint32_t)regR8 & 0x7) != 0;
			int32_t count = (int32_t)regR8 >> 3;
			regCr0.compare<int32_t>(count, 0, xer);
			uint32_t entry = begin;
			if (count > 0) {
				xer.ca = 0;  // halving a positive count shifts no bits out
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					regR9 = half;
					regR8 = step;
					entry += step;
					regR7 = (int32_t)LOAD32(entry) < 36;
					if (regR7 != 0) {
						count = count - half - 1;
						entry += 8;
					} else {
						entry -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack - 12, entry);
			}
			if (entry != end && (int32_t)LOAD32(entry) <= 36) {
				STORE64(stack - 16, LOAD64(stack - 16));
				healthRecord = LOAD32(LOAD32(stack - 12) + 4);
			} else {
				healthRecord = LOAD32(end + 4);
			}
		}
		hasRecord = true;
	}

	uint64_t isLow = 0;
	if (hasRecord) {
		ctx.fpscr.disableFlushMode();
		double currentHealth = double(LOAD_F32(healthRecord + 20));
		double maxHealth = double(LOAD_F32(healthRecord + 28));
		double healthRatio = double(float(currentHealth / maxHealth));
		double lowHealthThreshold = double(LOAD_F32(0x8209B674u));
		regF12 = healthRatio;
		regF13 = maxHealth;
		if (healthRatio < lowHealthThreshold) {
			isLow = 1;
		}
	}

	// callers read these registers after the call
	ctx.r6.u64 = regR6;
	ctx.r7.u64 = regR7;
	ctx.r8.u64 = regR8;
	ctx.r9.u64 = regR9;
	ctx.f12.f64 = regF12;
	ctx.f13.f64 = regF13;
	ctx.cr0 = regCr0;
	ctx.xer.ca = xer.ca;
	return isLow;
}
PROMOTED_ENTRY(13, sub_822D3240, 0x822D3240) { ctx.r3.u64 = CECDog_IsHealthLow(ctx, base, ctx.r3.u32); }

uint64_t CECDog_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8B0C_B_ = int32_t(0x820C8B0C);
	if (!UseLiftedCode(51, 0x8277CAB0)) { ctx.r3.u64 = classNameString; __imp__sub_8277CAB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277CAB0);
	uint32_t stack = ctx.r1.u64;
	uint64_t classNameCStr = str_TXT_820C8B0C_B_;
	int32_t length = -1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(51, sub_8277CAB0, 0x8277CAB0) { ctx.r3.u64 = CECDog_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8277E558(CpuState& ctx, uint8_t* base, uint64_t objectAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(51, 0x8277E558)) { ctx.r3.u64 = objectAddr; ctx.r4.u64 = deleteFlags; __imp__sub_8277E558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277E558);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_8277E630(ctx, base, objectAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, objectAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectAddr;
}
PROMOTED_ENTRY(51, sub_8277E558, 0x8277E558) { ctx.r3.u64 = n_sub_8277E558(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8277E8A8(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t TXT_8349B4E4_G_ = int32_t(0x8349B4E4);
	if (!UseLiftedCode(51, 0x8277E8A8)) { ctx.r3.u64 = dogAddr; __imp__sub_8277E8A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8277E8A8);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;

	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 208);
	uint32_t entity = dog->m_4;
	ctx.r1.u64 = stack;
	n_sub_82392C88(ctx, base, entity, dogAddr);

	// Vector registers the call above leaves; carried on to n_sub_822BDA90.
	PPCVRegister vec9 = ctx.v9;
	PPCVRegister vec10 = ctx.v10;
	PPCVRegister vec11 = ctx.v11;
	PPCVRegister vec12 = ctx.v12;
	PPCVRegister vec13 = ctx.v13;
	PPCVRegister tmp{};
	PPCXERRegister xer = ctx.xer;

	ctx.fpscr.disableFlushMode();
	const double value1D4 = double(LOAD_F32(0x821008E0u));

	const float value1F0 = LOAD_F32(0x820994C0u);
	dog->m_1F0 = value1F0;
	dog->m_200 = value1F0;
	dog->m_210 = value1F0;
	dog->m_220 = value1F0;
	dog->m_230 = value1F0;
	dog->m_240 = value1F0;
	dog->m_250 = value1F0;
	dog->m_260 = value1F0;
	dog->m_270 = value1F0;
	dog->m_280 = value1F0;
	dog->m_290 = value1F0;
	dog->m_2A0 = value1F0;
	dog->m_2B0 = value1F0;
	dog->m_2C0 = value1F0;
	dog->m_2D0 = value1F0;

	entity = dog->m_4;  // read again: the call above may have changed it
	dog->m_1B8 = 1;
	dog->m_1D4 = (float)value1D4;
	dog->m_1B4 = LOAD_F32(0x820994B4u);

	uint32_t entityFlags = LOAD32(entity + 36);
	// Register values handed to n_sub_822BDA90 below.
	uint64_t regR6 = (entityFlags >> 6) & 1;
	uint64_t regR7 = entityFlags;
	uint64_t regR8 = 1;

	if (((entityFlags >> 6) & 1) != 0) {
		// Component 6 of the entity: read through its index table when it has one,
		// otherwise found by a lower-bound binary search of its sorted (id, component)
		// pairs, with the iterator kept at stack+80/+84.
		uint32_t component;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t slotOffset = (uint32_t)LOAD8(indexTable + 6) << 3;
			component = LOAD32(slotOffset + LOAD32(entity + 72) + 4);
		} else {
			uint32_t begin = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			STORE32(stack + 80, 0u);
			uint32_t byteSpan = end - begin;
			STORE32(stack + 84, begin);
			xer.ca = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
			int32_t count = (int32_t)byteSpan >> 3;
			uint32_t it = begin;
			if (count > 0) {
				xer.ca = 0;  // halving a positive count shifts no bits out
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					it += step;
					if ((int32_t)LOAD32(it) < 6) {
						count = count - half - 1;
						it += 8;
					} else {
						it -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 6) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		uint32_t holder = LOAD32(component + 148);
		uint32_t holderField144 = LOAD32(holder + 144);
		ctx.xer.ca = xer.ca;  // state the callee may pass on
		uint64_t index = StringPairArray_FindIndexByName(ctx, base, holder, TXT_8349B4E4_G_);
		n_sub_821F5980(ctx, base, stack + 112, index, holderField144, holder, 1);
		regR6 = ctx.r6.u64;
		regR7 = g_820A0000 - 28384;  // 0x82099120, sign-extended
		regR8 = g_820A0000;

		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 80, LOAD_F32(0x8209DE04u));
		scratch.u32 = stack + 80;
		SET_V8(tmp, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vec13, simde_mm_shuffle_epi32(V8(tmp), 0xFF));
		SET_V8(vec12, VLOAD((stack + 128) & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(vec11, simde_mm_mul_ps(VF(vec12), VF(vec13)));
		SET_V8(vec10, V8(vec11));
		VSTORE(((uint32_t)dogAddr + 1168) & ~0xF, V8(vec11));
		SET_V8(tmp, VLOAD((uint32_t)regR7 & ~0xF));
		SET_V8(vec9, simde_mm_and_si128(V8(vec10), V8(tmp)));
		VSTORE(((uint32_t)dogAddr + 1168) & ~0xF, V8(vec9));
	}

	ctx.fpscr.disableFlushMode();
	dog->m_54 = LOAD_F32(0x82096088u);
	// state the callee may pass on
	ctx.r6.u64 = regR6;
	ctx.r7.u64 = regR7;
	ctx.r8.u64 = regR8;
	ctx.f13.f64 = value1D4;
	ctx.v9 = vec9;
	ctx.v10 = vec10;
	ctx.v11 = vec11;
	ctx.v12 = vec12;
	ctx.v13 = vec13;
	n_sub_822BDA90(ctx, base, dogAddr);

	entity = dog->m_4;
	uint32_t interfaceObj = LOAD32(entity + 124);
	uint32_t vtable = LOAD32(interfaceObj);
	uint32_t method = LOAD32(vtable + 64);
	PPCRegister callTarget{};
	callTarget.u64 = method;
	ctx.r3.u64 = (uint64_t)stack + 96;
	ctx.r4.u64 = interfaceObj;
	ctx.r8.u64 = method;
	ctx.r9.u64 = vtable;
	ctx.r10.u64 = entity;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	SET_V8(tmp, VLOAD((stack + 96) & ~0xF));
	VSTORE(((uint32_t)dogAddr + 1440) & ~0xF, V8(tmp));
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(51, sub_8277E8A8, 0x8277E8A8) { ctx.r3.u64 = n_sub_8277E8A8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827818D0(CpuState& ctx, uint8_t* base, uint64_t dogAddr, double floatArg1) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(51, 0x827818D0)) { ctx.r3.u64 = dogAddr; ctx.f1.f64 = floatArg1; __imp__sub_827818D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827818D0);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 128);

	// Register values the original code leaves for its callers.
	uint64_t regR4 = ctx.r4.u64;
	double regF1 = floatArg1;
	PPCVRegister regV1 = ctx.v1;

	uint64_t result = dogAddr;
	const uint32_t timerAddr = (uint32_t)g_83320000 - 27380u;

	// Truncates toward zero to a 32-bit integer the way the original conversion does
	// (NaN gives 0x80000000, large values saturate at INT_MAX).
	auto truncToInt = [](double value) -> int64_t {
		if (std::isnan(value)) return int64_t(0x80000000u);
		if (value > double(INT_MAX)) return INT_MAX;
		return int64_t(simde_mm_cvttsd_si32(simde_mm_load_sd(&value)));
	};

	if (dog->m_28 == 0) {
		PPCVRegister zeroVec{};
		SET_V8(zeroVec, simde_mm_set1_epi32(int(0x0)));
		VSTORE(uint32_t(stack + 80) & ~0xFu, V8(zeroVec));

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = dogAddr;
		ctx.f1.f64 = floatArg1;
		uint32_t found = n_sub_82781AD0(ctx, base, stack + 80);
		regF1 = ctx.f1.f64;
		if ((found & 0xFF) == 0) {
			n_sub_82781A08(ctx, base, dogAddr, stack + 80);
			regF1 = ctx.f1.f64;
		}

		ctx.fpscr.disableFlushMode();
		double timeScale = LOAD_F64(0x83319510u);
		double scaledA = timeScale * LOAD_F64(0x821007C8u);
		// The vector the queries above left at stack+80 (also left in v1).
		SET_V8(regV1, VLOAD(uint32_t(stack + 80) & ~0xFu));
		double scaledB = timeScale * LOAD_F64(0x82100B58u);
		dog->m_1C = uint8_t(1);
		VSTORE((uint32_t)dogAddr + 1424u & ~0xFu, V8(regV1));

		uint32_t now = LOAD32(timerAddr);
		PPCRegister ticksA{};
		ticksA.s64 = truncToInt(scaledA);
		STORE_F64(stack + 80, ticksA.f64);
		regR4 = LOAD32(stack + 84);
		PPCRegister ticksB{};
		ticksB.s64 = truncToInt(scaledB);
		STORE_F64(stack + 80, ticksB.f64);
		dog->m_F0 = uint32_t(now - (uint64_t)LOAD32(stack + 84));
		uint64_t sinceTicksA = (uint64_t)LOAD32(timerAddr) - regR4;
		dog->m_E0 = 0;
		dog->m_DC = (uint32_t)sinceTicksA;

		result = CECDog_IsHealthLow(ctx, base, dogAddr);
		uint32_t isHealthLow = (uint32_t)result & 0xFF;
		if (isHealthLow != 0) {
			uint32_t nowAgain = LOAD32(timerAddr);
			dog->m_28 = uint8_t(0);
			ctx.fpscr.disableFlushMode();
			PPCRegister ticksC{};
			ticksC.s64 = truncToInt(timeScale * LOAD_F64(0x82100B50u));
			STORE_F64(stack + 80, ticksC.f64);
			dog->m_D8 = uint32_t(nowAgain - (uint64_t)LOAD32(stack + 84));
		} else {
			// state the callee may pass on
			ctx.r5.s64 = g_83320000;
			ctx.r7.u64 = isHealthLow;
			ctx.f9 = ticksB;
			ctx.f10 = ticksA;
			ctx.f11.f64 = timeScale;
			ctx.v1 = regV1;
			result = n_sub_827814D8(ctx, base, dogAddr, 0, ctx.f1.f64);
			regR4 = ctx.r4.u64;
			regF1 = ctx.f1.f64;
			regV1 = ctx.v1;
			dog->m_28 = uint8_t(0);
		}
	} else {
		dog->m_28 = uint8_t(0);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read these registers after the call
	ctx.r4.u64 = regR4;
	ctx.f1.f64 = regF1;
	ctx.v1 = regV1;
	return result;
}
PROMOTED_ENTRY(51, sub_827818D0, 0x827818D0) { ctx.r3.u64 = n_sub_827818D0(ctx, base, ctx.r3.u64, ctx.f1.f64); }

uint32_t n_sub_82781A08(CpuState& ctx, uint8_t* base, uint64_t dogAddr, uint64_t outVecAddr) {
	if (!UseLiftedCode(51, 0x82781A08)) { ctx.r3.u64 = dogAddr; ctx.r4.u64 = outVecAddr; __imp__sub_82781A08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82781A08);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	stack = PushStackFrame(base, stack, 128);

	// The entity handle at dog+300: when it points at a slot whose entity is gone the
	// handle is released; otherwise go on only when bit 0x40 of the linked entity's
	// byte at +144 is set.
	bool linkedFlagSet = false;
	uint32_t handleSlot = dog->m_130;
	if (handleSlot != 0) {
		uint32_t linkedEntity = LOAD32(handleSlot);
		if (linkedEntity == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r4.u64 = outVecAddr;
			ctx.r10.u64 = linkedEntity;
			EntityHandle_Release(ctx, base, dogAddr + 300);
		} else {
			linkedFlagSet = (LOAD8(linkedEntity + 144) & 0x40) != 0;
		}
	}

	uint32_t result = 0;
	if (linkedFlagSet) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r4.u64 = outVecAddr;
		uint32_t bombardTarget = n_sub_82174238(ctx, base, dogAddr);
		uint32_t targetObj = LOAD32(bombardTarget + 124);
		uint32_t vtable = LOAD32(targetObj);
		uint32_t method = LOAD32(vtable + 64);

		PPCRegister callTarget{};
		callTarget.u64 = method;
		ctx.r3.u64 = stack + 80;
		ctx.r4.u64 = targetObj;
		ctx.r9.u64 = method;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		result = 1;
		PPCVRegister vector{};
		SET_V8(vector, VLOAD((stack + 80) & ~0xF));
		VSTORE((uint32_t)outVecAddr & ~0xF, V8(vector));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_82781A08, 0x82781A08) { ctx.r3.u64 = n_sub_82781A08(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82781AD0(CpuState& ctx, uint8_t* base, uint32_t outVecAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(51, 0x82781AD0)) { ctx.r4.u64 = outVecAddr; __imp__sub_82781AD0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82781AD0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Pointer chain from the global manager down to the object to query.
	uint32_t globalManager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t node = LOAD32(LOAD32(LOAD32(globalManager + 12) + 88) + 4);
	uint32_t owner = LOAD32(node + 8);
	uint32_t container = LOAD32(owner + 4);
	uint32_t target = LOAD32(container + 36);

	if (target != 0) {
		uint64_t targetEntity = (uint64_t)LOAD32(target + 4) + 176;
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = container;
		ctx.r7.u64 = owner;
		uint32_t result = n_sub_8238EF38(ctx, base, targetEntity, outVecAddr, (uint64_t)stack + 80);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return result;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r6 and r7 after the call
	ctx.r6.u64 = container;
	ctx.r7.u64 = owner;
	return 0;
}
PROMOTED_ENTRY(51, sub_82781AD0, 0x82781AD0) { ctx.r3.u64 = n_sub_82781AD0(ctx, base, ctx.r4.u32); }

uint64_t n_sub_82781B38(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	if (!UseLiftedCode(51, 0x82781B38)) { ctx.r3.u64 = dogAddr; __imp__sub_82781B38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82781B38);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	uint64_t result{};
	stack = PushStackFrame(base, stack, 112);
	uint64_t owner = (uint32_t)dog->m_4;
	uint64_t entry = dogAddr + 776;
	uint32_t remaining = 10;
	do {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = n_sub_8277D770(ctx, base, entry, owner);
		flags.ca = remaining > 0;
		remaining = (uint32_t)((int32_t)remaining - 1);
		entry += 32;
	} while ((int32_t)remaining != 0);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_82781B38, 0x82781B38) { ctx.r3.u64 = n_sub_82781B38(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82781B70(CpuState& ctx, uint8_t* base, uint32_t dogAddr, uint64_t outPoint, uint64_t navigation) {
	if (!UseLiftedCode(51, 0x82781B70)) { ctx.r3.u64 = dogAddr; ctx.r4.u64 = outPoint; ctx.r5.u64 = navigation; __imp__sub_82781B70(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82781B70);
	uint32_t stack = ctx.r1.u64;
	// r6-r8, cr0 and CA as the original leaves them: handed to the callees; cr0 also goes back to the callers.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	PPCVRegister vectorScratch{};
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	stack = PushStackFrame(base, stack, 128);

	uint32_t owner = dog->m_4;
	uint32_t modeManager = 0;   // payload of the owner's entry with key 21
	bool found = false;
	uint64_t reg9 = (LOAD32(owner + 36) >> 21) & 1;
	if ((uint32_t)reg9 != 0) {
		uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 21);
			reg9 = index;
			reg8 = (uint64_t)(index << 3) + (uint64_t)LOAD32(owner + 72);
			modeManager = LOAD32((uint32_t)reg8 + 4);
		} else {
			// lower_bound(21) over the sorted 8-byte entries in [owner+72, owner+76)
			uint32_t first = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			reg6 = end;
			STORE32(stack + 80, 0u);
			uint32_t byteSpan = end - first;
			STORE32(stack + 84, first);
			flags.ca = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
			int32_t remaining = (int32_t)byteSpan >> 3;
			compare0.compare<int32_t>(remaining, 0, flags);
			if (remaining > 0) {
				do {
					int32_t half = remaining >> 1;
					uint32_t step = (uint32_t)half << 3;
					uint32_t mid = first + step;
					reg9 = half;
					reg8 = step;
					reg7 = (int32_t)LOAD32(mid) < 21 ? 1 : 0;
					if (reg7 != 0) {
						first = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				flags.ca = 0;   // halving a positive count leaves CA clear
				STORE32(stack + 84, first);
			}
			if (first != end && (int32_t)LOAD32(first) <= 21) {
				STORE64(stack + 80, LOAD64(stack + 80));
				modeManager = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				modeManager = LOAD32(end + 4);
			}
		}
		found = true;
	}

	if (found) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r5.u64 = navigation;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.r9.u64 = reg9;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		uint64_t hasMode = CECEntityModeManager_HasMode(ctx, base, modeManager, 49);
		reg9 = ctx.r9.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
		if ((hasMode & 0xFF) != 0) {
			SET_V8(vectorScratch, VLOAD((dogAddr + 1376u) & ~0xF));
			VSTORE((uint32_t)outPoint & ~0xF, V8(vectorScratch));
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return 1;
		}
	}

	ctx.r1.u64 = stack;
	ctx.r9.u64 = reg9;   // state the callee may pass on
	ctx.xer.ca = flags.ca;
	uint32_t facingResult = CECNavigation_ComputeFacingTargetPoint(ctx, base, navigation, outPoint, 3);
	uint32_t facingFailed = (facingResult & 0xFF) == 0 ? 1u : 0u;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4, r9 and cr0 after the call
	ctx.r4.u64 = outPoint;
	ctx.r9.u64 = facingFailed;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	return facingFailed ^ 1;
}
PROMOTED_ENTRY(51, sub_82781B70, 0x82781B70) { ctx.r3.u64 = n_sub_82781B70(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint32_t n_sub_82783188(CpuState& ctx, uint8_t* base, uint32_t dogAddr) {
	if (!UseLiftedCode(52, 0x82783188)) { ctx.r3.u64 = dogAddr; __imp__sub_82783188(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82783188);
	uint32_t stack = ctx.r1.u32;
	// r6, r7, cr0 and CA as the original leaves them (written back at the return)
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	uint32_t container = dog->m_4;
	uint32_t entry = 0;
	bool found = false;

	uint64_t reg8 = (LOAD32(container + 52) >> 9) & 1;
	if (reg8 != 0) {
		uint32_t indexTable = LOAD32(container + 140);
		if (indexTable != 0) {
			uint32_t index = LOAD8(indexTable + 137);
			uint32_t entries = LOAD32(container + 72);
			entry = LOAD32(entries + index * 8 + 4);
		} else {
			uint32_t begin = LOAD32(container + 72);
			uint32_t end = LOAD32(container + 76);
			reg6 = end;
			STORE32(stack - 16, 0u);
			reg8 = (uint64_t)end - (uint64_t)begin;
			STORE32(stack - 12, begin);

			// lower_bound(begin, end, 137) over sorted 8-byte entries
			uint32_t byteSpan = (uint32_t)reg8;
			flags.ca = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
			int32_t remaining = (int32_t)byteSpan >> 3;
			compare0.compare<int32_t>(remaining, 0, flags);
			uint32_t first = begin;
			if (remaining > 0) {
				do {
					int32_t half = remaining >> 1;
					uint32_t step = (uint32_t)half << 3;
					uint32_t mid = first + step;
					reg8 = step;
					reg7 = (int32_t)LOAD32(mid) < 137 ? 1 : 0;
					if (reg7 != 0) {
						first = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				flags.ca = 0;   // halving a positive count leaves CA clear
				STORE32(stack - 12, first);
			}

			if (first != end && (int32_t)LOAD32(first) <= 137) {
				STORE64(stack - 16, LOAD64(stack - 16));
				entry = LOAD32(LOAD32(stack - 12) + 4);
			} else {
				entry = LOAD32(end + 4);
			}
		}
		found = true;
	}

	uint32_t result = (found && LOAD8(entry + 73) != 0) ? 1u : 0u;
	// callers read r6-r8, cr0 and CA after the call
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(52, sub_82783188, 0x82783188) { ctx.r3.u64 = n_sub_82783188(ctx, base, ctx.r3.u32); }

double n_sub_82788BF0(CpuState& ctx, uint8_t* base, uint32_t dogAddr, double target) {
	if (!UseLiftedCode(52, 0x82788BF0)) { ctx.r3.u64 = dogAddr; ctx.f1.f64 = target; __imp__sub_82788BF0(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x82788BF0);
	constexpr uint32_t kThresholdAddr  = 0x820994B4;
	constexpr uint32_t kScaleAddr      = 0x8209DFD4;
	constexpr uint32_t kLimitAddr      = 0x820994C0;
	constexpr uint32_t kStepFactorAddr = 0x8209DDC8;
	constexpr uint32_t kSelectTable    = 0x82100170;
	constexpr uint32_t kDivisorAddr    = 0x83319510;

	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	ctx.fpscr.disableFlushMode();

	const double current = double(dog->m_48);
	const double threshold = double(LOAD_F32(kThresholdAddr));
	double delta = double(float(target - current));
	double result = target;   // f1 on return: the target, or the limited value computed below

	if (int32_t(LOAD32(dogAddr + 272)) != 0 ||
	    (LOAD8(dogAddr + 24) != 0 && delta > threshold)) {
		const double scale = double(LOAD_F32(kScaleAddr));
		const double limit = double(LOAD_F32(kLimitAddr));
		const double stepFactor = double(LOAD_F32(kStepFactorAddr));
		const double scaled = double(float(current * scale));

		// The table at kSelectTable has an entry for a >= b (offset 0) and one for a < b or unordered
		// (offset 4); a non-negative entry selects the first of the two values.
		PPCCRRegister cmp{};
		cmp.compare(scaled, threshold);
		uint32_t slot = (cmp.lt || cmp.so) ? 4u : 0u;
		const double candidate = double(LOAD_F32(kSelectTable + slot)) >= 0.0 ? scaled : threshold;

		cmp.compare(double(float(candidate - limit)), threshold);
		slot = (cmp.lt || cmp.so) ? 4u : 0u;
		result = double(LOAD_F32(kSelectTable + slot)) >= 0.0 ? limit : candidate;

		const double squared = double(float(result * result));
		const double stepBase = double(float(std::fma(squared, stepFactor, stepFactor)));
		const double step = double(float(stepBase / double(float(LOAD_F64(kDivisorAddr)))));

		if (std::fabs(delta) > step) {
			delta = delta > threshold ? step : -step;
		}
	}

	dog->m_48 = float(current + delta);
	return result;
}
PROMOTED_ENTRY(52, sub_82788BF0, 0x82788BF0) { ctx.f1.f64 = n_sub_82788BF0(ctx, base, ctx.r3.u32, ctx.f1.f64); }

uint64_t n_sub_82789A30(CpuState& ctx, uint8_t* base, uint64_t dogAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, double amount) {
	if (!UseLiftedCode(52, 0x82789A30)) { ctx.r3.u64 = dogAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r8.u64 = arg4; ctx.f1.f64 = amount; __imp__sub_82789A30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82789A30);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = amount;   // state the callee may pass on
	uint64_t result = n_sub_827898B8(ctx, base, dogAddr, arg2, arg3, arg4);
	if ((result & 0xFF) != 0) {
		const int32_t offset = (int32_t)LOAD32(0x8331950Cu);
		ctx.fpscr.disableFlushMode();
		const double scale = LOAD_F64(0x83319510u);
		// the integer reaches the FPU through the stack, as in the original
		STORE64(stack + 80, (uint64_t)(int64_t)offset);
		PPCRegister offsetBits{};
		offsetBits.f64 = LOAD_F64(stack + 80);
		const double offsetValue = double(offsetBits.s64);
		double value = std::fma(amount, scale, offsetValue);
		PPCRegister truncated{};
		truncated.s64 = std::isnan(value) ? int64_t(0x80000000U) : value > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&value));
		dog->m_E4 = truncated.u32;
		// callers read r8, r9 and f10-f13 after the call
		ctx.r8.u64 = (uint64_t)(int64_t)offset;
		ctx.r9.u64 = 228;
		ctx.f10 = truncated;
		ctx.f11.f64 = value;
		ctx.f12.f64 = offsetValue;
		ctx.f13 = offsetBits;
	} else {
		ctx.r9.u64 = ctx.r9.u32;   // callers read r9 after the call; the original keeps only its low word
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82789A30, 0x82789A30) { ctx.r3.u64 = n_sub_82789A30(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64, ctx.f1.f64); }

uint64_t n_sub_82789AA8(CpuState& ctx, uint8_t* base, uint64_t dogAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x82789AA8)) { ctx.r3.u64 = dogAddr; ctx.r8.u64 = arg2; __imp__sub_82789AA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82789AA8);
	uint32_t stack = ctx.r1.u64;
	uint64_t reg9 = ctx.r9.u64;   // r9 as the original leaves it, handed to n_sub_82789B68
	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	stack = PushStackFrame(base, stack, 96);

	int32_t currentState = dog->m_114;

	if (dog->m_27 != 0) {
		if (currentState == 5 && dog->m_118 != 5) {
			uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t actionOwner = LOAD32(LOAD32(globalRoot + 12) + 168);
			ctx.r1.u64 = stack;
			n_sub_824FDAF8(ctx, base, actionOwner, 22, arg2);
			arg2 = ctx.r8.u64;
		}
		reg9 = 6;
		int32_t nextState = dog->m_118;
		dog->m_118 = 0;
		dog->m_11C = 6;
		dog->m_27 = 0;
		dog->m_114 = nextState;
	} else {
		if (currentState == 5) {
			uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t actionOwner = LOAD32(LOAD32(globalRoot + 12) + 168);
			ctx.r1.u64 = stack;
			n_sub_824FDAF8(ctx, base, actionOwner, 22, arg2);
			arg2 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
		}
		dog->m_114 = 0;
		dog->m_11C = 0;
	}

	dog->m_E4 = 0xFFFFFFFFu;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r8.u64 = arg2;
	ctx.r9.u64 = reg9;
	uint64_t result = n_sub_82789B68(ctx, base, dogAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82789AA8, 0x82789AA8) { ctx.r3.u64 = n_sub_82789AA8(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82789B68(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_82099334 = int32_t(0x82099334);
	constexpr int32_t g_82790000 = int32_t(0x82790000);
	if (!UseLiftedCode(52, 0x82789B68)) { ctx.r3.u64 = dogAddr; __imp__sub_82789B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82789B68);
	uint64_t reg0 = ctx.r0.u64;
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	stack = PushStackFrame(base, stack, 112);

	const int64_t dataBase = g_82099334;            // kept sign-extended, as the original does
	const int64_t stateTable = dataBase + 11548;    // three floats per state
	const uint32_t state = dog->m_114;
	const uint32_t owner = dog->m_4;
	const uint32_t stateOffset = uint32_t(state + uint64_t(state << 1)) << 2;   // 12 * state

	ctx.fpscr.disableFlushMode();
	const double stateValue0 = double(LOAD_F32(stateOffset + uint32_t(stateTable)));
	dog->m_68 = float(stateValue0);
	const double stateValue1 = double(LOAD_F32(stateOffset + uint32_t(stateTable + 4)));
	dog->m_6C = float(stateValue1);
	const double stateValue2 = double(LOAD_F32(stateOffset + uint32_t(stateTable + 8)));
	dog->m_70 = float(stateValue2);

	// r5, r7 and r8 as the original leaves them; handed to the first slot call below
	uint64_t reg5 = stateTable;
	uint32_t reg7 = stateOffset;
	uint64_t reg8 = (LOAD32(owner + 40) >> 12) & 1;
	uint32_t entry = 0;   // payload of the owner's entry with key 44
	bool found = false;

	if (uint32_t(reg8) != 0) {
		const uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			reg8 = uint64_t(LOAD8(indexTable + 44)) * 8 + LOAD32(owner + 72);
			entry = LOAD32(uint32_t(reg8) + 4);
		} else {
			// lower_bound(44) over the sorted 8-byte entries in [owner+72, owner+76)
			uint64_t first = LOAD32(owner + 72);
			reg5 = LOAD32(owner + 76);
			STORE32(stack + 80, 0u);
			reg8 = reg5 - first;
			STORE32(stack + 84, uint32_t(first));
			flags.ca = int32_t(reg8) < 0 && (uint32_t(reg8) & 0x7) != 0;
			int32_t remaining = int32_t(reg8) >> 3;
			if (remaining > 0) {
				do {
					const int32_t half = remaining >> 1;
					reg8 = uint32_t(half) << 3;
					const uint64_t mid = reg8 + first;
					reg7 = int32_t(LOAD32(uint32_t(mid))) < 44 ? 1u : 0u;
					if (reg7 != 0) {
						first = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				} while (remaining > 0);
				flags.ca = 0;   // halving a positive count leaves CA clear
				STORE32(stack + 84, uint32_t(first));
			}
			if (uint32_t(first) != uint32_t(reg5) && int32_t(LOAD32(uint32_t(first))) <= 44) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry = LOAD32(uint32_t(reg5) + 4);
			}
		}
		found = true;
	}

	if (found && state <= 7) {
		reg0 = LOAD32(uint32_t(g_82790000 - 25356) + state * 4);   // the original's jump-table entry, left in r0
		switch (state) {
		case 1:
			STORE_F32(LOAD32(entry + 112) + 48, float(double(LOAD_F32(uint32_t(dataBase + 19204)))));
			break;
		case 2:
			STORE_F32(LOAD32(entry + 112) + 48, float(double(LOAD_F32(uint32_t(dataBase + 8988)))));
			break;
		case 3:
			STORE_F32(LOAD32(entry + 112) + 48, float(double(LOAD_F32(uint32_t(dataBase)))));
			break;
		default:   // 0, 4, 5, 6, 7
			STORE_F32(LOAD32(entry + 112) + 48, float(double(LOAD_F32(0x8209B674u))));
			break;
		}
	}

	// dog+904, +936 and +1064 are entries 4, 5 and 9 of the ten 32-byte slots at dog+776
	const uint32_t slotOwner = dog->m_4;
	const uint64_t slot4 = dogAddr + 904;
	// state the callees may pass on
	ctx.r0.u64 = reg0;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = reg8;
	ctx.f12.f64 = stateValue2;
	ctx.f13.f64 = stateValue1;
	ctx.xer.ca = flags.ca;
	if (state == 2 || state == 3) {
		n_sub_8277D960(ctx, base, slot4, slotOwner, -1, 31);
	} else {
		ctx.r5.u64 = reg5;
		ctx.r6.u64 = uint64_t(dataBase);
		ctx.r7.u64 = reg7;
		n_sub_8277DC78(ctx, base, slot4, slotOwner);
	}

	uint64_t result;
	if (state == 5) {
		n_sub_8277D960(ctx, base, dogAddr + 936, dog->m_4, -1, 255);
		result = n_sub_8277D960(ctx, base, dogAddr + 1064, dog->m_4, -1, 255);
	} else {
		n_sub_8277DC78(ctx, base, dogAddr + 936, dog->m_4);
		result = n_sub_8277DC78(ctx, base, dogAddr + 1064, dog->m_4);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_82789B68, 0x82789B68) { ctx.r3.u64 = n_sub_82789B68(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8278A258(CpuState& ctx, uint8_t* base, uint32_t dogAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820D4AF0_B_ = int32_t(0x820D4AF0);
	constexpr int32_t str_TXT_820D4B0C_B_ = int32_t(0x820D4B0C);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x8278A258)) { ctx.r3.u64 = dogAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_8278A258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8278A258);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 128);

	CECDog* dog = GameObject<CECDog>(base, dogAddr);
	const uint32_t globalsRef = stack + 88;     // reference to the script global table
	const uint32_t aiManagerRef = stack + 80;   // a field of that table, fetched below
	const uint32_t scriptCall = stack + 96;     // a function reference, with a CCharString at +8

	uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t scriptHost = LOAD32(LOAD32(globalRoot + 12) + 120);
	uint32_t stateHolder = LOAD32(scriptHost + 4);
	uint32_t luaState = LOAD32(stateHolder);

	ctx.r1.u64 = stack;
	ctx.r8.u64 = stateHolder;   // state the callee may pass on
	ctx.r9.u64 = scriptHost;
	LuaRef_GetGlobalTable(ctx, base, globalsRef, luaState, arg2, arg3);

	uint64_t aiManagerName = (int64_t)str_TXT_820C0000_B_ + 11796;
	ctx.r7.s64 = str_TXT_820C0000_B_;   // state the callee may pass on
	LuaTableRef_GetField(ctx, base, aiManagerRef, globalsRef, aiManagerName);

	bool mustStay = false;
	uint64_t reg6 = 0;   // r6 for the releases at the end, as the original leaves it
	if (LOAD32(aiManagerRef) != 0) {
		ctx.r5.u64 = str_TXT_820D4B0C_B_;   // state the callee may pass on
		ctx.r6.u64 = str_TXT_820D4AF0_B_;
		n_sub_82792368(ctx, base, scriptCall, aiManagerRef);

		uint64_t reg9 = LOAD32(scriptCall);
		if (reg9 != 0) {
			uint32_t owner = dog->m_4;
			ctx.r9.u64 = reg9;
			int32_t stayType = n_sub_827924E8(ctx, base, scriptCall, aiManagerRef, owner, ctx.r6.u64, ctx.r7.u64);
			reg9 = ctx.r9.u64;
			mustStay = stayType == 1 || stayType == 2 || stayType == 3;
		}
		ctx.r9.u64 = reg9;
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, scriptCall + 8);
		SharedHandle_Release(ctx, base, scriptCall);
		reg6 = ctx.r6.u64;
	}

	mustStay = mustStay || dog->m_22 != 0;
	ctx.r6.u64 = reg6;
	SharedHandle_Release(ctx, base, aiManagerRef);
	SharedHandle_Release(ctx, base, globalsRef);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return mustStay ? 1 : 0;
}
PROMOTED_ENTRY(52, sub_8278A258, 0x8278A258) { ctx.r3.u64 = n_sub_8278A258(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8278ADB8(CpuState& ctx, uint8_t* base, uint64_t dogAddr, uint64_t arg2) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(52, 0x8278ADB8)) { ctx.r3.u64 = dogAddr; ctx.r4.u64 = arg2; __imp__sub_8278ADB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8278ADB8);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	stack = PushStackFrame(base, stack, 128);
	const uint32_t tempHandle = stack + 80;

	// scratch handle holds the entity passed in, and is copied into the dog's own handle field
	STORE32(tempHandle + 4, 0);
	STORE32(tempHandle, uint32_t(g_820F1664));
	ctx.r1.u64 = stack;
	EntityHandle_SetTarget(ctx, base, tempHandle, arg2);

	EntityHandle_Assign(ctx, base, dogAddr + 300, tempHandle);

	STORE32(tempHandle, uint32_t(g_820F1664));
	EntityHandle_Release(ctx, base, tempHandle);

	// r6-r9 as the game code holds them at the calls below: leftovers of the handle calls,
	// or scratch values of the lookup; the callees may pass them on
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint32_t r8Value = ctx.r8.u32;

	const uint32_t owner = dog->m_4;
	const uint32_t flagBit = (LOAD32(owner + 36) >> 17) & 1;
	if (flagBit != 0) {
		uint32_t r9Value = flagBit;  // still the flag bit when the search loop does not run
		uint32_t component;
		const uint32_t slotIndexTable = LOAD32(owner + 140);
		if (slotIndexTable != 0) {
			const uint32_t slotIndex = LOAD8(slotIndexTable + 17);
			const uint32_t entries = LOAD32(owner + 72);
			r9Value = (slotIndex << 3) + entries;
			component = LOAD32(r9Value + 4);
		} else {
			// lower bound for key 17 over the sorted 8-byte {key, value} entries;
			// the scratch slot holds the search iterator
			uint32_t entry = LOAD32(owner + 72);
			const uint32_t mapEnd = LOAD32(owner + 76);
			r6Value = mapEnd;
			STORE32(tempHandle, 0);
			int32_t remaining = (int32_t)(mapEnd - entry) >> 3;
			STORE32(tempHandle + 4, entry);
			if (remaining > 0) {
				do {
					const int32_t half = remaining >> 1;
					const uint32_t halfOffset = uint32_t(half) << 3;
					r9Value = uint32_t(half);
					r8Value = halfOffset;
					entry += halfOffset;
					const bool keyBelow = (int32_t)LOAD32(entry) < 17;
					r7Value = keyBelow ? 1 : 0;
					if (keyBelow) {
						entry += 8;
						remaining = remaining - half - 1;
					} else {
						entry -= halfOffset;
						remaining = half;
					}
				} while (remaining > 0);
				STORE32(tempHandle + 4, entry);
			}
			if (entry != mapEnd && (int32_t)LOAD32(entry) <= 17) {
				STORE64(tempHandle, LOAD64(tempHandle));
				component = LOAD32(LOAD32(tempHandle + 4) + 4);
			} else {
				component = LOAD32(mapEnd + 4);
			}
		}

		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.r9.u64 = r9Value;
		n_sub_824686C8(ctx, base, component);
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
	}

	// the same for the owner entity, copied into the handle at +192 of the object
	// reached through the global at 0x83496920
	STORE32(tempHandle + 4, 0);
	STORE32(tempHandle, uint32_t(g_820F1664));
	const uint32_t currentOwner = dog->m_4;
	const uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	const uint32_t root = LOAD32(manager + 12);
	const uint32_t node = LOAD32(root + 88);
	const uint32_t handleOwnerSlot = LOAD32(node + 4);
	const uint32_t handleOwner = LOAD32(handleOwnerSlot);

	// state the callee may pass on
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = handleOwnerSlot;
	ctx.r9.u64 = node;
	ctx.r10.u64 = root;
	EntityHandle_SetTarget(ctx, base, tempHandle, currentOwner);

	EntityHandle_Assign(ctx, base, handleOwner + 192, tempHandle);

	STORE32(tempHandle, uint32_t(g_820F1664));
	const uint32_t result = EntityHandle_Release(ctx, base, tempHandle);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(52, sub_8278ADB8, 0x8278ADB8) { ctx.r3.u64 = n_sub_8278ADB8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8278B118(CpuState& ctx, uint8_t* base, uint64_t dogAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(52, 0x8278B118)) { ctx.r3.u64 = dogAddr; __imp__sub_8278B118(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8278B118);
	uint32_t stack = ctx.r1.u64;
	CECDog* dog = GameObject<CECDog>(base, dogAddr);

	stack = PushStackFrame(base, stack, 112);
	const uint32_t tempHandle = stack + 80;

	// a scratch handle with no target is copied into the dog's handle field at +324
	STORE32(tempHandle + 4, 0);
	STORE32(tempHandle, uint32_t(g_820F1664));
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r9.s64 = g_820F1664;
	ctx.r10.u64 = 0;
	EntityHandle_Release(ctx, base, tempHandle);

	EntityHandle_Assign(ctx, base, dogAddr + 324, tempHandle);

	STORE32(tempHandle, uint32_t(g_820F1664));
	// state the callee may pass on (g_820F1664 is g_820F0000 + 5732)
	ctx.r7.s64 = g_820F1664;
	ctx.r8.s64 = g_820F0000;
	const uint64_t result = EntityHandle_Release(ctx, base, tempHandle);

	dog->m_E8 = uint32_t(-1);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r6.s64 = -1;  // callers read r6 after the call
	return result;
}
PROMOTED_ENTRY(52, sub_8278B118, 0x8278B118) { ctx.r3.u64 = n_sub_8278B118(ctx, base, ctx.r3.u64); }
