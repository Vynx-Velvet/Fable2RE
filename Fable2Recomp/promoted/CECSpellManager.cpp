// CECSpellManager (vtable 0x82004A60): methods of the class as readable C++.
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

// Counts down the m_1A0 values in the 10-float array at +0x238 by a step derived from n_sub_82207928, stopping
// at 0. When one reaches 0 the array is rebuilt from the values still above 0, and n_sub_8271FBC8 and
// n_sub_8271F8A0 get the owner and a stack record (words +4..+12 zeroed); a non-zero word they leave at
// record+4 goes to HandleTarget_Free.
uint32_t n_sub_821E66F0(CpuState& ctx, uint8_t* base, uint32_t managerAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(4, 0x821E66F0)) { ctx.r3.u64 = managerAddr; __imp__sub_821E66F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821E66F0);
	uint32_t stack = ctx.r1.u64;
	uint64_t result = managerAddr;
	PPCXERRegister flags = ctx.xer;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, managerAddr);
	// what callers find in f1 on return
	double callerF1 = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 160);

	if (int32_t(spellManager->m_1A0) > 0) {
		uint32_t owner = spellManager->m_owner;
		result = owner;
		ctx.r1.u64 = stack;
		const double rawStep = n_sub_82207928(ctx, base, owner);
		callerF1 = rawStep;
		flags.ca = ctx.xer.ca;

		ctx.fpscr.disableFlushMode();
		const double step = double(float(rawStep / LOAD_F64(0x83319510u)));
		const double zero = double(LOAD_F32(uint32_t(g_820A0000) - 27468));

		bool anyReachedZero = false;
		double lastValue = 0.0;
		uint32_t TXT_820B1DF8_L_ = managerAddr + 0x238;
		for (int32_t i = 0; i < int32_t(spellManager->m_1A0); ++i) {
			ctx.fpscr.disableFlushMode();
			lastValue = double(LOAD_F32(TXT_820B1DF8_L_));
			if (lastValue > zero) {
				lastValue = double(float(lastValue - step));
				STORE_F32(TXT_820B1DF8_L_, float(lastValue));
				if (!(lastValue > zero)) {
					STORE_F32(TXT_820B1DF8_L_, float(zero));
					anyReachedZero = true;
				}
			}
			TXT_820B1DF8_L_ += 4;
		}

		if (anyReachedZero) {
			// Keep the values still above 0 on the stack, clear all 10 slots and copy the kept ones back.
			const uint32_t keptValues = stack + 96;
			uint32_t keptCount = 0;
			int32_t remaining = spellManager->m_1A0;
			if (remaining > 0) {
				uint32_t src = managerAddr + 0x238;
				uint32_t dst = keptValues;
				do {
					ctx.fpscr.disableFlushMode();
					lastValue = double(LOAD_F32(src));
					if (lastValue > zero) {
						STORE_F32(dst, float(lastValue));
						keptCount += 1;
						dst += 4;
					}
					// carry of the count-down, handed to n_sub_8271FBC8 below
					flags.ca = remaining > 0;
					remaining -= 1;
					src += 4;
				} while (remaining != 0);
			}

			uint32_t clearSlot = managerAddr + 0x238;
			for (int32_t k = 0; k < 10; ++k) {
				STORE32(clearSlot, 0);
				clearSlot += 4;
			}

			spellManager->m_1A0 = keptCount;
			uint32_t copiedCount = 0;
			uint32_t storedCount = keptCount;
			if (int32_t(keptCount) > 0) {
				uint32_t src = keptValues;
				uint32_t dst = managerAddr + 0x238;
				do {
					ctx.fpscr.disableFlushMode();
					const double value = double(LOAD_F32(src));
					copiedCount += 1;
					STORE_F32(dst, float(value));
					storedCount = spellManager->m_1A0;
					src += 4;
					dst += 4;
				} while (int32_t(copiedCount) < int32_t(storedCount));
			}

			STORE32(stack + 84, 0);
			STORE32(stack + 88, 0);
			STORE32(stack + 92, 0);
			const uint64_t record = uint64_t(stack) + 80;

			owner = spellManager->m_owner;
			// state the callee may pass on
			ctx.r6.s64 = g_820A0000;
			ctx.r7.u64 = storedCount;
			ctx.r8.u64 = 0;
			ctx.r9.u64 = copiedCount;
			ctx.f1.f64 = rawStep;
			ctx.f12.f64 = step;
			ctx.f13.f64 = lastValue;
			ctx.xer.ca = flags.ca;
			n_sub_8271FBC8(ctx, base, owner, record, 0);

			owner = spellManager->m_owner;
			n_sub_8271F8A0(ctx, base, owner, record);

			result = LOAD32(stack + 84);
			if (result != 0) {
				result = HandleTarget_Free(ctx, base, result);
			}
			callerF1 = ctx.f1.f64;
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = callerF1;  // callers read f1
	return (uint32_t)result;
}
PROMOTED_ENTRY(4, sub_821E66F0, 0x821E66F0) { ctx.r3.u64 = n_sub_821E66F0(ctx, base, ctx.r3.u32); }

// Gets a vector from the owner's object at +124 (virtual slot 64, filled into a stack buffer) and passes it in
// v1 to virtual slot 100 of the object at +124 of the entity the handle at +472 refers to. A handle whose
// target is gone is released instead.
uint64_t CECSpellManager_GetSpellComponent(CpuState& ctx, uint8_t* base, uint64_t managerAddr) {
	if (!UseLiftedCode(4, 0x821E6880)) { ctx.r3.u64 = managerAddr; __imp__sub_821E6880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E6880);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	PPCVRegister vectorValue = ctx.v127;

	// v127 is saved below the frame, as the original does
	VSTORE((stack + 0xFFFFFFE0u) & ~0xF, V8(vectorValue));
	stack = PushStackFrame(base, stack, 128);

	const uint64_t handleAddr = managerAddr + 472;
	const uint32_t handleEntry = LOAD32((uint32_t)managerAddr + 476);
	uint64_t result = managerAddr;

	if (handleEntry != 0) {
		const uint32_t target = LOAD32(handleEntry);
		if (target == 0) {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r10.u64 = target;
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			const uint32_t owner = LOAD32((uint32_t)managerAddr + 4);
			const uint64_t vectorBuffer = uint64_t(stack) + 80;
			const uint32_t ownerObject = LOAD32(owner + 124);
			const uint32_t ownerVtable = LOAD32(ownerObject);
			const uint32_t getVectorMethod = LOAD32(ownerVtable + 64);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = vectorBuffer;
			ctx.r4.u64 = ownerObject;
			ctx.r9.u64 = getVectorMethod;
			ctx.r10.u64 = ownerVtable;
			callTarget.u64 = getVectorMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			SET_V8(vectorValue, VLOAD((uint32_t)vectorBuffer & ~0xF));
			ctx.r8.u64 = vectorBuffer;  // state the callee may pass on
			const uint32_t targetObject = LOAD32((uint32_t)EntityHandle_Get_825575C8(ctx, base, handleAddr) + 124);
			const uint32_t targetVtable = LOAD32(targetObject);
			const uint32_t takeVectorMethod = LOAD32(targetVtable + 100);
			ctx.r3.u64 = targetObject;
			ctx.r6.u64 = takeVectorMethod;
			ctx.r7.u64 = targetVtable;
			ctx.v1 = vectorValue;
			callTarget.u64 = takeVectorMethod;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821E6880, 0x821E6880) { ctx.r3.u64 = CECSpellManager_GetSpellComponent(ctx, base, ctx.r3.u64); }

// While m_26D is set, moves the blend position m_20C by m_210 per step: rising, it stops at 1 and m_210 becomes
// negative; falling to 0 finishes. Until finished, the rotation object reached through 0x83496920 gets the angle
// blended from m_214 to m_218 by the position, then the angle m_220, eased in from m_21C the shorter way round
// while the position is below 0.2. When finished, m_26D is cleared and n_sub_82623170 is called on that object.
uint32_t n_sub_821E6930(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr) {
	constexpr int32_t g_8209BAA8 = int32_t(0x8209BAA8);
	if (!UseLiftedCode(4, 0x821E6930)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_821E6930(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821E6930);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint32_t result = spellManagerAddr;
	// what callers find in f1 on return
	double callerF1 = ctx.f1.f64;
	stack = PushStackFrame(base, stack, 144);

	if (spellManager->m_26D != 0) {
		result = spellManager->m_owner;
		ctx.r1.u64 = stack;
		const double rawStep = n_sub_82207928(ctx, base, result);
		callerF1 = rawStep;
		ctx.fpscr.disableFlushMode();

		const double zero = double(LOAD_F32(uint32_t(g_8209BAA8) - 9716));
		const double one = double(LOAD_F32(uint32_t(g_8209BAA8) - 9704));
		const double rate = double(spellManager->m_210);
		const double step = double(float(rawStep / LOAD_F64(0x83319510u)));
		const double position = double(float(std::fma(rate, step, double(spellManager->m_20C))));
		spellManager->m_20C = float(position);

		bool finished = false;
		if (rate > zero) {
			if (!(position < one)) {
				spellManager->m_20C = float(one);
				spellManager->m_210 = LOAD_F32(0x82100750u);
			}
		} else {
			ctx.fpscr.disableFlushMode();
			finished = !(position > zero);
		}

		if (!finished) {
			ctx.fpscr.disableFlushMode();
			const uint32_t rotationObject = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88) + 4) + 84);
			const double startAngle = double(spellManager->m_214);
			const double blendedAngle = double(float(std::fma(double(float(double(spellManager->m_218) - startAngle)), double(spellManager->m_20C), startAngle)));
			n_sub_82623098(ctx, base, rotationObject, blendedAngle);
			ctx.fpscr.disableFlushMode();

			const double easeEnd = double(LOAD_F32(uint32_t(g_8209BAA8) - 10108));
			const double targetAngle = double(spellManager->m_220);
			double angle = targetAngle;
			const double progress = double(spellManager->m_20C);
			if (progress < easeEnd) {
				// 1 - (easeEnd - progress) * 5: 0 at position 0, 1 at easeEnd
				const double weight = double(float(-std::fma(double(float(easeEnd - progress)), double(LOAD_F32(uint32_t(g_8209BAA8))), -one)));
				if (weight < one) {
					const double fromAngle = double(spellManager->m_21C);
					double delta = double(float(targetAngle - fromAngle));
					const double fullTurn = double(LOAD_F32(0x820990A4u));
					if (delta < zero) {
						delta = double(float(delta + fullTurn));
					}
					ctx.fpscr.disableFlushMode();
					if (delta > double(LOAD_F32(0x820990A0u))) {
						delta = double(float(delta - fullTurn));
					}
					ctx.fpscr.disableFlushMode();
					STORE_F32(stack + 80, float(std::fma(delta, weight, fromAngle)));
					n_sub_824B6808(ctx, base, stack + 80);
					ctx.fpscr.disableFlushMode();
					angle = double(LOAD_F32(stack + 80));
				}
			}

			ctx.fpscr.disableFlushMode();
			const double rotationResult = n_sub_82623108(ctx, base, rotationObject, angle, zero);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			ctx.f1.f64 = rotationResult;  // callers read f1
			return rotationObject;
		}

		if (spellManager->m_26D != 0) {
			spellManager->m_26D = 0;
			result = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88) + 4) + 84);
			ctx.f1.f64 = rawStep;  // state the callee may pass on
			callerF1 = n_sub_82623170(ctx, base, result);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = callerF1;  // callers read f1
	return result;
}
PROMOTED_ENTRY(4, sub_821E6930, 0x821E6930) { ctx.r3.u64 = n_sub_821E6930(ctx, base, ctx.r3.u32); }

// With m_26A set, searches for a spell by target: none found clears m_26A (and, if m_17C is 0, sets m_234 to the
// game-database float at 0x833191D4); m_26B is cleared either way. With m_70 set, decrements m_174 unless it is 0 and
// calls three helpers. Then lowers m_234 by one step toward 0 and runs n_sub_821E6AD0, n_sub_821E66F0, n_sub_821E6930
// and CECSpellManager_GetSpellComponent.
uint64_t n_sub_821E6FA0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(4, 0x821E6FA0)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_821E6FA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E6FA0);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	// f1 and f13 as handed to the calls at the end
	double f1Value = ctx.f1.f64;
	double f13Value = ctx.f13.f64;
	stack = PushStackFrame(base, stack, 96);

	if (spellManager->m_26A != 0) {
		const uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
		const uint32_t owner = spellManager->m_owner;
		const uint32_t container = LOAD32(LOAD32(globalObject + 12) + 88);
		const uint32_t element = LOAD32(container + 4);
		const uint32_t target = LOAD32(element + 68);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r8.u64 = element;
		ctx.r9.u64 = container;
		const uint32_t foundSpell = SpellManager_FindSpellByTarget(ctx, base, target, 2, 0, owner);
		f1Value = ctx.f1.f64;
		f13Value = ctx.f13.f64;
		if (foundSpell == 0) {
			const uint32_t value17C = spellManager->m_17C;
			spellManager->m_26A = 0;
			if (value17C == 0) {
				ctx.fpscr.disableFlushMode();
				spellManager->m_234 = LOAD_F32(0x833191D4u);
			}
		}
		spellManager->m_26B = 0;
	}

	if (spellManager->m_70 != 0) {
		const uint32_t countdown = spellManager->m_174;
		if (countdown != 0) {
			spellManager->m_174 = countdown - 1;
		}
		ctx.r1.u64 = stack;
		n_sub_82429168(ctx, base, spellManagerAddr);
		n_sub_824293D0(ctx, base, spellManagerAddr);
		n_sub_8242D7B0(ctx, base, spellManagerAddr);
		f1Value = ctx.f1.f64;
		f13Value = ctx.f13.f64;
	}

	ctx.fpscr.disableFlushMode();
	const double zero = double(LOAD_F32(0x820994B4u));
	if (double(spellManager->m_234) > zero) {
		const uint32_t owner = spellManager->m_owner;
		ctx.r1.u64 = stack;
		f1Value = n_sub_82207928(ctx, base, owner);
		ctx.fpscr.disableFlushMode();
		const double current = double(spellManager->m_234);
		const double step = double(float(f1Value / LOAD_F64(0x83319510u)));
		f13Value = step;
		if (current > zero) {
			const double lowered = double(float(current - step));
			spellManager->m_234 = float(lowered);
			if (!(lowered > zero)) {
				spellManager->m_234 = float(zero);
			}
		}
	}

	// state the callees may pass on
	ctx.r1.u64 = stack;
	ctx.f1.f64 = f1Value;
	ctx.f11.f64 = zero;
	ctx.f13.f64 = f13Value;
	n_sub_821E6AD0(ctx, base, spellManagerAddr);
	n_sub_821E66F0(ctx, base, spellManagerAddr);
	n_sub_821E6930(ctx, base, spellManagerAddr);
	const uint64_t result = CECSpellManager_GetSpellComponent(ctx, base, spellManagerAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(4, sub_821E6FA0, 0x821E6FA0) { ctx.r3.u64 = n_sub_821E6FA0(ctx, base, ctx.r3.u64); }

// sub_82427628  [60 bytes]
uint64_t CECSpellManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t charString) {
	constexpr int32_t str_TXT_820A6894_B_ = int32_t(0x820A6894);
	if (!UseLiftedCode(24, 0x82427628)) { ctx.r3.u64 = charString; __imp__sub_82427628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82427628);
	uint32_t stack = ctx.r1.u64;
	uint64_t className = str_TXT_820A6894_B_;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, charString, className, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return charString;
}
PROMOTED_ENTRY(24, sub_82427628, 0x82427628) { ctx.r3.u64 = CECSpellManager_GetClassName(ctx, base, ctx.r3.u64); }

// Constructor: sets the owner and vtable, resets the cast table at +128, zeroes the strings at +424 and +428
// (each adds one to the global count at 0x83496EB8), sets up the entity handles and calls n_sub_82427848.
uint64_t n_sub_82427678(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint32_t owner) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x82427678)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = owner; __imp__sub_82427678(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82427678);
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint32_t stack = ctx.r1.u64;
	// the original's atomic increments run with the MSR bits taken from r13
	const uint32_t r13Value = ctx.r13.u64;

	stack = PushStackFrame(base, stack, 112);

	spellManager->m_owner = owner;
	spellManager->m_8 = 0;
	spellManager->vtable = 0x82004A60u;
	spellManager->m_80 = 0xFF;
	spellManager->m_81 = 0xFF;
	spellManager->m_82 = 0xFF;
	spellManager->m_83 = 0xFF;
	spellManager->m_84 = 0xFF;
	spellManager->m_85 = 0xFF;
	spellManager->m_86 = 0xFF;
	spellManager->m_87 = 0xFF;
	spellManager->m_88 = 0xFF;
	spellManager->m_89 = 0xFF;
	ctx.r1.u64 = stack;
	SpellCastTable_Reset(ctx, base, spellManagerAddr + 128);

	const int32_t globalsBase = g_83490000;
	const uint64_t stringCountAddr = (int64_t)globalsBase + 28344;

	spellManager->m_1A8 = 0;
	uint64_t firstLockState{};
	uint64_t firstCount{};
	bool stored = false;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		firstLockState = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = r13Value & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)stringCountAddr);
		firstCount = uint64_t(__builtin_bswap32(ctx.reserved.u32)) + 1;
		stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)stringCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)firstCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = (uint32_t)firstLockState & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);

	spellManager->m_1AC = 0;
	uint32_t secondLockState{};
	uint32_t secondCount{};
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		secondLockState = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = r13Value & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)stringCountAddr);
		secondCount = __builtin_bswap32(ctx.reserved.u32) + 1u;
		stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)stringCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)secondCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = secondLockState & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);

	// Each entity handle starts as {EntityHandle vtable, 0}; m_284 starts at -1.
	const uint64_t handleVtable = g_820F1664;
	spellManager->m_1B4 = 0;
	spellManager->m_1B0 = (uint32_t)handleVtable;
	spellManager->m_1BC = 0;
	spellManager->m_1B8 = (uint32_t)handleVtable;
	spellManager->m_1C4 = 0;
	spellManager->m_1C0 = (uint32_t)handleVtable;
	spellManager->m_1CC = 0;
	spellManager->m_1C8 = (uint32_t)handleVtable;
	spellManager->m_1D4 = 0;
	spellManager->m_1D0 = (uint32_t)handleVtable;
	spellManager->m_1DC = 0;
	spellManager->m_1D8 = (uint32_t)handleVtable;
	spellManager->m_280 = 0;
	spellManager->m_27C = (uint32_t)handleVtable;
	spellManager->m_284 = 0xFFFFFFFF;

	// state the callee may pass on
	ctx.r4.u64 = secondCount;
	ctx.r5.u64 = stringCountAddr;
	ctx.r6.u64 = stringCountAddr;
	ctx.r7.u64 = firstLockState;
	ctx.r8.u64 = firstCount;
	ctx.r9.s64 = globalsBase;
	ctx.r10.u64 = handleVtable;
	n_sub_82427848(ctx, base, spellManagerAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return spellManagerAddr;
}
PROMOTED_ENTRY(24, sub_82427678, 0x82427678) { ctx.r3.u64 = n_sub_82427678(ctx, base, ctx.r3.u64, ctx.r4.u32); }

// Destructor: releases the entity handles at +636 and +472 down to +432 (each gets the EntityHandle vtable,
// is released and its pointer word cleared), releases the strings at +428 and +424, sets the vtable to
// 0x820A8D10 and, when bit 0 of deleteFlags is set, frees the object.
uint64_t n_sub_82427778(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t deleteFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x82427778)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82427778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82427778);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t handleVtable = uint32_t(g_820F1664);

	spellManager->m_27C = handleVtable;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	EntityHandle_Release(ctx, base, spellManagerAddr + 636);
	spellManager->m_280 = 0;

	spellManager->m_1D8 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 472);
	spellManager->m_1DC = 0;

	spellManager->m_1D0 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 464);
	spellManager->m_1D4 = 0;

	spellManager->m_1C8 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 456);
	spellManager->m_1CC = 0;

	spellManager->m_1C0 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 448);
	spellManager->m_1C4 = 0;

	spellManager->m_1B8 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 440);
	spellManager->m_1BC = 0;

	spellManager->m_1B0 = handleVtable;
	EntityHandle_Release(ctx, base, spellManagerAddr + 432);
	spellManager->m_1B4 = 0;

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, spellManagerAddr + 428);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, spellManagerAddr + 424);

	spellManager->vtable = 0x820A8D10u;

	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, spellManagerAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return spellManagerAddr;
}
PROMOTED_ENTRY(24, sub_82427778, 0x82427778) { ctx.r3.u64 = n_sub_82427778(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Puts the manager into its initial state: clears the handles at +472 and +464 by assigning an empty
// stack handle, resets flags, counters and the blend/countdown floats, empties the string at +428, copies two
// vectors from 0x83497DF0/0x83497E00 to +48/+64 and resets the cast table at +128.
uint32_t n_sub_82427848(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x82427848)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_82427848(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82427848);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);

	stack = PushStackFrame(base, stack, 144);

	const uint32_t handleVtable = uint32_t(g_820F1664);
	const uint32_t minusOne = 0xFFFFFFFFu;
	// an empty EntityHandle {vtable, 0} on the stack
	const uint32_t tempHandle = stack + 80;
	STORE32(tempHandle, handleVtable);
	STORE32(tempHandle + 4, 0);

	spellManager->m_70 = 0;
	spellManager->m_shieldSwords = 0;
	spellManager->m_1E4 = 0;
	spellManager->m_1E8 = 0;
	spellManager->m_74 = minusOne;
	spellManager->m_188 = 2;

	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, tempHandle);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 472, tempHandle);
	STORE32(tempHandle, handleVtable);
	EntityHandle_Release(ctx, base, tempHandle);

	spellManager->m_26A = 0;
	spellManager->m_26B = 0;
	spellManager->m_26E = 0;
	spellManager->m_26D = 0;
	spellManager->m_18C = 0;
	spellManager->m_190 = 0;
	spellManager->m_magicEnabled = 1;
	spellManager->m_268 = 1;
	spellManager->m_270 = 1;
	spellManager->m_17C = minusOne;
	spellManager->m_1A4 = minusOne;

	ctx.fpscr.disableFlushMode();
	const float one = LOAD_F32((uint32_t)g_820A0000 - 27456);
	const float zero = LOAD_F32((uint32_t)g_820A0000 - 27456 - 12);
	spellManager->m_230 = one;
	spellManager->m_20C = zero;
	spellManager->m_210 = zero;
	spellManager->m_214 = zero;
	spellManager->m_218 = zero;
	spellManager->m_21C = zero;
	spellManager->m_220 = zero;
	spellManager->m_234 = zero;

	const int64_t emptyText = (int64_t)g_82000000 + 3224;
	ctx.r8.s64 = g_82000000;  // state the callee may pass on
	CCharString_AssignFromCStr(ctx, base, spellManagerAddr + 428, emptyText);

	PPCVRegister vectorValue{};
	SET_V8(vectorValue, VLOAD(0x83497DF0u & ~0xF));
	VSTORE(((uint32_t)spellManagerAddr + 48) & ~0xF, V8(vectorValue));
	SET_V8(vectorValue, VLOAD(0x83497E00u & ~0xF));
	VSTORE(((uint32_t)spellManagerAddr + 64) & ~0xF, V8(vectorValue));

	ctx.r4.u64 = 48;  // state the callee may pass on
	SpellCastTable_Reset(ctx, base, spellManagerAddr + 128);

	// no countdown values: m_1A0 = 0 and the 10 slots at +0x238 cleared
	spellManager->m_1A0 = 0;
	uint32_t countdownSlot = spellManagerAddr + 568;
	for (int i = 0; i < 10; ++i) {
		STORE32(countdownSlot, 0);
		countdownSlot += 4;
	}

	ctx.r9.u64 = 0;  // state the callee may pass on
	n_sub_824279D0(ctx, base, spellManagerAddr);

	STORE32(tempHandle, handleVtable);
	STORE32(tempHandle + 4, 0);
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, tempHandle);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 464, tempHandle);
	STORE32(tempHandle, handleVtable);
	const uint32_t result = EntityHandle_Release(ctx, base, tempHandle);

	ctx.fpscr.disableFlushMode();
	spellManager->m_228 = zero;
	spellManager->m_1EC = 0;
	spellManager->m_26F = 0;
	spellManager->m_184 = minusOne;
	spellManager->m_263 = 0;
	spellManager->m_264 = 0;

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_82427848, 0x82427848) { ctx.r3.u64 = n_sub_82427848(ctx, base, ctx.r3.u64); }

uint32_t n_sub_824279D0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(24, 0x824279D0)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_824279D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824279D0);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 144);

	const uint32_t entityHandleVtable = uint32_t(g_820F0000) + 5732;   // 0x820F1664
	ctx.fpscr.disableFlushMode();
	const float zero = LOAD_F32(0x820994B4u);   // 0.0f constant
	const uint32_t entityHandleTemp = stack + 80;

	spellManager->m_1F0 = zero;
	spellManager->m_15C = 0xFFFFFFFFu;
	spellManager->m_1F4 = zero;
	spellManager->m_174 = 0;
	spellManager->m_1F8 = zero;
	spellManager->m_160 = 0xFFFFFFFFu;
	spellManager->m_1FC = zero;
	spellManager->m_164 = 0xFFFFFFFFu;
	spellManager->m_200 = zero;
	spellManager->m_168 = 0xFFFFFFFFu;
	spellManager->m_204 = zero;
	spellManager->m_180 = 0xFFFFFFFFu;
	spellManager->m_208 = zero;

	STORE32(entityHandleTemp + 4, 0);
	spellManager->m_16C = 0;
	STORE32(entityHandleTemp, entityHandleVtable);
	spellManager->m_170 = 0;
	spellManager->m_288 = 0;
	spellManager->m_194 = 0xFFFFFFFFu;
	spellManager->m_198 = 0xFFFFFFFFu;

	ctx.r1.u64 = stack;
	ctx.r10.s64 = g_820F0000;   // state the callee may pass on
	EntityHandle_Release(ctx, base, entityHandleTemp);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 432, entityHandleTemp);

	STORE32(entityHandleTemp, entityHandleVtable);
	ctx.r9.s64 = g_820F0000;   // state the callee may pass on
	EntityHandle_Release(ctx, base, entityHandleTemp);
	STORE32(entityHandleTemp, entityHandleVtable);
	STORE32(entityHandleTemp + 4, 0);
	EntityHandle_Release(ctx, base, entityHandleTemp);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 440, entityHandleTemp);

	STORE32(entityHandleTemp, entityHandleVtable);
	EntityHandle_Release(ctx, base, entityHandleTemp);
	STORE32(entityHandleTemp, entityHandleVtable);
	STORE32(entityHandleTemp + 4, 0);
	EntityHandle_Release(ctx, base, entityHandleTemp);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 448, entityHandleTemp);

	STORE32(entityHandleTemp, entityHandleVtable);
	EntityHandle_Release(ctx, base, entityHandleTemp);
	STORE32(entityHandleTemp, entityHandleVtable);
	STORE32(entityHandleTemp + 4, 0);
	EntityHandle_Release(ctx, base, entityHandleTemp);
	EntityHandle_Assign(ctx, base, spellManagerAddr + 456, entityHandleTemp);

	STORE32(entityHandleTemp, entityHandleVtable);
	uint32_t result = EntityHandle_Release(ctx, base, entityHandleTemp);

	spellManager->m_260 = 0;
	spellManager->m_261 = 0;
	spellManager->m_262 = 0;
	spellManager->m_263 = 1;
	spellManager->m_264 = 0;
	spellManager->m_265 = 1;
	spellManager->m_266 = 0;
	spellManager->m_267 = 0;
	spellManager->m_26C = 0;
	spellManager->m_74 = 0;
	spellManager->m_78 = 0xFFFFFFFFu;

	PPCVRegister zeroVector{};
	SET_V8(zeroVector, simde_mm_set1_epi32(0));
	VSTORE(((uint32_t)spellManagerAddr + 16u) & ~0xFu, V8(zeroVector));
	spellManager->m_7C = 0xFFFFFFFFu;
	VSTORE(((uint32_t)spellManagerAddr + 32u) & ~0xFu, V8(zeroVector));
	spellManager->m_178 = 0xFFFFFFFFu;

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = 16;   // callers may read r8 after the call
	return result;
}
PROMOTED_ENTRY(24, sub_824279D0, 0x824279D0) { ctx.r3.u64 = n_sub_824279D0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82428A58(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x82428A58)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_82428A58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82428A58);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);

	uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t owner = spellManager->m_owner;
	uint32_t rootChild = LOAD32(LOAD32(globalRoot + 12) + 88);
	uint32_t systemTable = LOAD32(rootChild + 4);
	uint32_t players = LOAD32(systemTable);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r8.u64 = systemTable;
	ctx.r9.u64 = rootChild;
	uint64_t isPlayer = Players_IsPlayer(ctx, base, players, owner);

	if ((isPlayer & 0xFF) != 0) {
		spellManager->m_270 = 0;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return isPlayer;
}
PROMOTED_ENTRY(24, sub_82428A58, 0x82428A58) { ctx.r3.u64 = n_sub_82428A58(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82428AB8(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x82428AB8)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_82428AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82428AB8);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	n_sub_8242EBB8(ctx, base, spellManagerAddr);
	CECSpellManager_ResetState(ctx, base, spellManagerAddr);
	// f1 as the calls above left it, or what n_sub_82623170 returns; n_sub_8242DEA0 receives it
	double f1Value = ctx.f1.f64;

	if (spellManager->m_26D != 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		spellManager->m_26D = 0;
		uint32_t rootChild = LOAD32(LOAD32(globalRoot + 12) + 88);
		uint32_t object84 = LOAD32(LOAD32(rootChild + 4) + 84);
		ctx.r8.u64 = rootChild;   // state the callee may pass on
		f1Value = n_sub_82623170(ctx, base, object84);
	}

	ctx.f1.f64 = f1Value;
	n_sub_8242DEA0(ctx, base, spellManagerAddr);

	n_sub_8242E910(ctx, base, spellManagerAddr, 1);

	uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t owner = spellManager->m_owner;
	uint32_t rootChild = LOAD32(LOAD32(globalRoot + 12) + 88);
	uint32_t systemTable = LOAD32(rootChild + 4);
	uint32_t object68 = LOAD32(systemTable + 68);
	ctx.r9.u64 = systemTable;   // state the callee may pass on
	uint64_t result = n_sub_8249C408(ctx, base, object68, owner);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_82428AB8, 0x82428AB8) { ctx.r3.u64 = n_sub_82428AB8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82428B58(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	if (!UseLiftedCode(24, 0x82428B58)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_82428B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82428B58);

	constexpr uint32_t kGlobalRootAddr = 0x83496920;   // 0x83490000 + 26912

	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	n_sub_8242EBB8(ctx, base, spellManagerAddr);

	uint32_t ownerEntity = spellManager->m_owner;
	SpellManager_ResetEntityMagicImpl(ctx, base, ownerEntity, 1, 0);

	// f1 as the calls above left it, or what n_sub_82623170 returns; n_sub_8242DEA0 receives it
	double f1Value = ctx.f1.f64;
	if (spellManager->m_26D != 0) {
		spellManager->m_26D = 0;
		uint32_t rootChild = LOAD32(LOAD32(LOAD32(kGlobalRootAddr) + 12) + 88);
		uint32_t systemTable = LOAD32(rootChild + 4);
		f1Value = n_sub_82623170(ctx, base, LOAD32(systemTable + 84));
	}

	ctx.f1.f64 = f1Value;
	n_sub_8242DEA0(ctx, base, spellManagerAddr);

	n_sub_8242E910(ctx, base, (uint32_t)spellManagerAddr, 1);

	spellManager->m_1A0 = 0;
	uint32_t clearAddr = (uint32_t)spellManagerAddr + 568;
	for (int i = 0; i < 10; ++i) {
		STORE32(clearAddr, 0);
		clearAddr += 4;
	}

	n_sub_8242D6E0(ctx, base, spellManagerAddr, 1);

	uint32_t rootChild = LOAD32(LOAD32(LOAD32(kGlobalRootAddr) + 12) + 88);
	uint32_t systemTable = LOAD32(rootChild + 4);
	uint32_t currentOwner = spellManager->m_owner;
	ctx.r9.u64 = systemTable;   // state the callee may pass on
	uint64_t result = n_sub_8249C408(ctx, base, LOAD32(systemTable + 68), currentOwner);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_82428B58, 0x82428B58) { ctx.r3.u64 = n_sub_82428B58(ctx, base, ctx.r3.u64); }

uint32_t CECSpellManager_ResetState(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	if (!UseLiftedCode(24, 0x82429098)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_82429098(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82429098);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.fpscr.disableFlushMode();
	const double zero = double(LOAD_F32(0x820994B4u));   // 0.0f constant
	ctx.r1.u64 = stack;
	n_sub_82429280(ctx, base, spellManagerAddr, 0, zero);
	n_sub_8242CD80(ctx, base, spellManagerAddr);
	n_sub_8242CF40(ctx, base, spellManagerAddr);
	CECSpellManager_UpdateSpellLight(ctx, base, spellManagerAddr);

	// Release the effect pair n_sub_8242E150 creates (its m_1E4 reference count is at +16).
	if (spellManager->m_26E != 0) {
		uint32_t effect = spellManager->m_1E4;
		if (effect != 0) {
			STORE32(effect + 16, LOAD32(effect + 16) - 1);
			spellManager->m_1E4 = 0;
		}
		uint32_t effectInstance = spellManager->m_1E8;
		if (effectInstance != 0) {
			STORE8(effectInstance + 48, uint8_t(1));
			spellManager->m_1E8 = 0;
		}
		spellManager->m_26E = 0;
	}

	n_sub_8242EA00(ctx, base, spellManagerAddr, TXT_83497DE4_G_, 200);
	n_sub_8242D6E0(ctx, base, spellManagerAddr, 0);
	uint32_t fadeResult = CECSpellManager_FadeScreenShake(ctx, base, spellManagerAddr);
	spellManager->m_263 = 0;
	spellManager->m_264 = 0;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return fadeResult;
}
PROMOTED_ENTRY(24, sub_82429098, 0x82429098) { ctx.r3.u64 = CECSpellManager_ResetState(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82429580(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t arg2) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	if (!UseLiftedCode(24, 0x82429580)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = arg2; __imp__sub_82429580(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82429580);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// r3 and r4 at the common return: as received, or as the last call left them; callers read r4 back.
	uint64_t result = spellManagerAddr;
	uint64_t returnR4 = arg2;
	// f1 as received; the original keeps call results in f1 and several callees below receive it.
	double f1Value = ctx.f1.f64;

	const uint32_t mode = (uint32_t)arg2;
	if (mode == 1) {
		if (spellManager->m_260 != 0) {
			spellManager->m_266 = uint8_t(1);
		}
		ctx.fpscr.disableFlushMode();
		const double zero = double(LOAD_F32(0x820994B4u));   // 0.0f constant
		if (spellManager->m_266 != 0) {
			spellManager->m_266 = uint8_t(0);
			ctx.r1.u64 = stack;
			ctx.r4.u64 = arg2;   // state the callee may pass on
			f1Value = n_sub_82429920(ctx, base, spellManagerAddr, zero);

			uint32_t castIndex = spellManager->m_160;
			if ((int32_t)castIndex != (int32_t)spellManager->m_198 && (int32_t)castIndex >= 0) {
				uint8_t castEntry = LOAD8(uint32_t((uint64_t)castIndex + spellManagerAddr) + 128);
				// state the callee may pass on
				ctx.r9.u64 = castEntry;
				ctx.f1.f64 = f1Value;
				n_sub_8242EA00(ctx, base, spellManagerAddr, TXT_83497DE4_G_, 200);
				n_sub_8242EC58(ctx, base, spellManagerAddr, (uint32_t)(int32_t)(int8_t)castEntry, castIndex);
				f1Value = ctx.f1.f64;
				spellManager->m_198 = castIndex;
			}

			ctx.f1.f64 = f1Value;   // state the callee may pass on
			result = n_sub_8242E150(ctx, base, spellManagerAddr, 0);
			returnR4 = ctx.r4.u64;
		}
		if (spellManager->m_261 != 0) {
			ctx.fpscr.disableFlushMode();
			ctx.r1.u64 = stack;
			uint32_t stateResult = n_sub_82429280(ctx, base, spellManagerAddr, 4, zero);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return stateResult;
		}
	} else if (mode == 0) {
		const uint32_t constantsAddr = uint32_t(g_820A0000) - 27468;   // 0x820994B4: 0.0f; +8236 holds 2.0f
		spellManager->m_265 = uint8_t(0);
		ctx.fpscr.disableFlushMode();
		const double zero = double(LOAD_F32(constantsAddr));
		spellManager->m_1FC = float(zero);
		spellManager->m_200 = float(zero);

		// m_90 when m_8C - m_90 is negative, else m_8C (the original's branch-free form, with its carry)
		uint32_t count8C = spellManager->m_8C;
		uint64_t count90 = spellManager->m_90;
		uint64_t diff = (uint64_t)count8C - count90;
		PPCXERRegister xer = ctx.xer;
		xer.ca = (int32_t)diff < 0 && ((uint32_t)diff & 0x7FFFFFFF) != 0;
		uint64_t signMask = (uint64_t)((int32_t)diff >> 31);
		uint64_t maskedDiff = signMask & diff;
		uint32_t iterations = (uint32_t)((uint64_t)count8C - maskedDiff);
		PPCCRRegister iterationsCompare{};
		iterationsCompare.compare<int32_t>((int32_t)iterations, 0, xer);

		// state n_sub_8242C4E0 may pass on; the original hands the callee's r5-r8 on from pass to pass,
		// so setting them once before the first pass is the same
		ctx.r5.u64 = maskedDiff;
		ctx.r6.u64 = signMask;
		ctx.r7.u64 = diff;
		ctx.r8.u64 = count90;
		double sum = 0.0;
		if ((int32_t)iterations > 0) {
			uint32_t i = 0;
			do {
				ctx.r1.u64 = stack;
				ctx.f1.f64 = f1Value;
				ctx.xer.ca = xer.ca;
				f1Value = n_sub_8242C4E0(ctx, base, spellManagerAddr, i);
				ctx.fpscr.disableFlushMode();
				double accumulated = double(spellManager->m_1FC);
				i++;
				sum = double(float(f1Value + accumulated));
				spellManager->m_1FC = float(sum);
			} while ((int32_t)i < (int32_t)iterations);
		}

		uint32_t pass = 0;
		do {
			ctx.r1.u64 = stack;
			ctx.f1.f64 = f1Value;
			ctx.xer.ca = xer.ca;
			f1Value = n_sub_8242C4E0(ctx, base, spellManagerAddr, pass);
			ctx.fpscr.disableFlushMode();
			double accumulated = double(spellManager->m_200);
			pass++;
			sum = double(float(f1Value + accumulated));
			spellManager->m_200 = float(sum);
		} while ((int32_t)pass < 5);

		// state the callee may pass on
		ctx.r4.u64 = pass;
		ctx.f1.f64 = f1Value;
		ctx.f13.f64 = sum;
		ctx.cr0 = iterationsCompare;
		n_sub_8242CAB0(ctx, base, spellManagerAddr);

		n_sub_8242E150(ctx, base, spellManagerAddr, 1);

		n_sub_8242DB00(ctx, base, spellManagerAddr);
		// r6, f1 and f2 as n_sub_8242DB00 left them, replaced below when n_sub_82420130 runs;
		// CCharString_AssignFromCStr receives them
		uint64_t assignR6 = ctx.r6.u64;
		f1Value = ctx.f1.f64;
		double f2Value = ctx.f2.f64;

		if (spellManager->m_268 != 0 && spellManager->m_267 == 0) {
			// m_1A8 is the block pointer of the CCharString at spellManagerAddr + 424 (0 or length at +4)
			uint32_t stringBlock = spellManager->m_1A8;
			uint64_t charStringAddr = (int64_t)spellManagerAddr + 424;
			if (stringBlock != 0 && (int32_t)LOAD32(stringBlock + 4) != 0) {
				uint64_t ownerKind = n_sub_8242DA90(ctx, base, spellManagerAddr);
				assignR6 = ownerKind;
				ctx.fpscr.disableFlushMode();
				f2Value = double(LOAD_F32(constantsAddr + 8236));
				f1Value = zero;
				uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
				uint32_t systemTable = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
				uint32_t object80 = LOAD32(systemTable + 80);
				ctx.r8.u64 = systemTable;   // state the callee may pass on
				n_sub_82420130(ctx, base, object80, ownerKind, f2Value);
			}

			spellManager->m_19C = 0xFFFFFFFFu;
			spellManager->m_267 = uint8_t(1);
			// state the callee may pass on
			ctx.r6.u64 = assignR6;
			ctx.f1.f64 = f1Value;
			ctx.f2.f64 = f2Value;
			CCharString_AssignFromCStr(ctx, base, charStringAddr, g_82000C98);   // g_82000C98 is an empty string
			ctx.fpscr.disableFlushMode();
			spellManager->m_22C = LOAD_F32(constantsAddr + 8236);
		}

		ctx.fpscr.disableFlushMode();
		const double quickCastTime = double(LOAD_F32(0x833191B4u));   // QuickCastTimeSecs tuning value
		f1Value = n_sub_82429920(ctx, base, spellManagerAddr, quickCastTime);

		ctx.fpscr.disableFlushMode();
		spellManager->m_266 = (double(spellManager->m_1F0) > zero) ? uint8_t(0) : uint8_t(1);

		uint32_t owner = spellManager->m_owner;
		ctx.f1.f64 = f1Value;   // state the callee may pass on
		result = n_sub_824C12F8(ctx, base, owner);
		returnR4 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = returnR4;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(24, sub_82429580, 0x82429580) { ctx.r3.u64 = n_sub_82429580(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_824297B8(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t arg2) {
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	if (!UseLiftedCode(24, 0x824297B8)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = arg2; __imp__sub_824297B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x824297B8);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	// r3, r4 and r7 at the return: as received, or as the last call (or the m_170 reload) left them;
	// callers read r4 and r7 back.
	uint64_t result = spellManagerAddr;
	uint64_t returnR4 = arg2;
	uint64_t returnR7 = ctx.r7.u64;

	const uint32_t mode = (uint32_t)arg2;
	if (mode == 1) {
		int32_t skipCount = (int32_t)spellManager->m_288;
		if (skipCount > 0) {
			spellManager->m_288 = (uint32_t)(skipCount - 1);
		} else {
			double timer = double(spellManager->m_1F4);
			const double zero = double(LOAD_F32(0x820994B4u));   // 0.0f constant
			if (!(timer > zero)) {
				uint32_t old164 = spellManager->m_164;
				uint64_t new164 = (uint64_t)old164 + 1;
				uint32_t castSlot = spellManager->m_74;
				uint32_t old170 = spellManager->m_170;
				uint64_t new170 = (uint64_t)old170 - 1;
				spellManager->m_164 = (uint32_t)new164;
				spellManager->m_170 = (uint32_t)new170;
				PPCVRegister block10{};
				SET_V8(block10, VLOAD(((uint32_t)spellManagerAddr + 16u) & ~0xFu));
				ctx.r1.u64 = stack;
				// state the callee may pass on
				ctx.r8.u64 = new170;
				ctx.r9.u64 = 16;
				ctx.v1 = block10;
				result = n_sub_82429A50(ctx, base, spellManagerAddr, castSlot, new164);
				returnR4 = ctx.r4.u64;
				returnR7 = spellManager->m_170;
				if ((int32_t)returnR7 > 0) {
					ctx.fpscr.disableFlushMode();
					const double castCascadeTime = double(LOAD_F32(0x833191B8u));   // CastCascadeTimeSecs tuning value
					spellManager->m_260 = uint8_t(0);
					spellManager->m_1F0 = float(castCascadeTime);
					spellManager->m_1F4 = float(castCascadeTime);
				} else {
					ctx.fpscr.disableFlushMode();
					ctx.r7.u64 = returnR7;   // state the callee may pass on
					result = n_sub_82429280(ctx, base, spellManagerAddr, 6, zero);
					returnR4 = ctx.r4.u64;
					returnR7 = ctx.r7.u64;
				}
			}
		}
	} else if (mode == 0) {
		spellManager->m_164 = (uint32_t)spellManager->m_168 - 1;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;   // state the callee may pass on
		CECSpellManager_UpdateSpellLight(ctx, base, spellManagerAddr);

		// Release the effect pair n_sub_8242E150 creates (its m_1E4 reference count is at +16).
		if (spellManager->m_26E != 0) {
			uint32_t effect = spellManager->m_1E4;
			if (effect != 0) {
				STORE32(effect + 16, LOAD32(effect + 16) - 1);
				spellManager->m_1E4 = 0;
			}
			uint32_t effectInstance = spellManager->m_1E8;
			if (effectInstance != 0) {
				STORE8(effectInstance + 48, uint8_t(1));
				spellManager->m_1E8 = 0;
			}
			spellManager->m_26E = uint8_t(0);
		}
		n_sub_8242EA00(ctx, base, spellManagerAddr, TXT_83497DE4_G_, 200);
		spellManager->m_260 = uint8_t(0);
		ctx.fpscr.disableFlushMode();
		const double zero = double(LOAD_F32(0x820994B4u));   // 0.0f constant
		spellManager->m_1F0 = float(zero);
		spellManager->m_1F4 = float(zero);
		result = n_sub_8242D6E0(ctx, base, spellManagerAddr, 0);
		returnR4 = ctx.r4.u64;
		returnR7 = ctx.r7.u64;
		spellManager->m_288 = 0;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 and r7 after the call
	ctx.r4.u64 = returnR4;
	ctx.r7.u64 = returnR7;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_824297B8, 0x824297B8) { ctx.r3.u64 = n_sub_824297B8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

double n_sub_82429920(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr, double floatArg1) {
	if (!UseLiftedCode(24, 0x82429920)) { ctx.r3.u64 = spellManagerAddr; ctx.f1.f64 = floatArg1; __imp__sub_82429920(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x82429920);
	uint32_t stack = ctx.r1.u32;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 96);

	// f13 as received unless the clamp below loads its lower bound into it; callers read f12, f13 and r9 back.
	double returnF13 = ctx.f13.f64;
	double result = floatArg1;
	uint32_t activeIndex = spellManager->m_15C;
	ctx.fpscr.disableFlushMode();
	spellManager->m_160 = activeIndex;

	if ((int32_t)activeIndex < 4) {
		uint32_t nextIndex = (int32_t)activeIndex + 1;
		uint32_t entryAddr = nextIndex + spellManagerAddr;
		if (LOAD8(entryAddr + 0x85) != 255 || LOAD8(entryAddr + 0x80) != 255) {
			spellManager->m_15C = nextIndex;
			ctx.r1.u64 = stack;
			ctx.f1.f64 = floatArg1;   // state the callee may pass on
			double nextValue = n_sub_8242C4E0(ctx, base, spellManagerAddr, nextIndex);
			ctx.fpscr.disableFlushMode();
			double delta = double(float(nextValue - floatArg1));
			returnF13 = double(LOAD_F32(0x820994B4u));   // 0.0f lower bound
			if (delta < returnF13) {
				delta = returnF13;
			}
			ctx.fpscr.disableFlushMode();
			spellManager->m_1F0 = float(delta);
			spellManager->m_260 = 0;
			spellManager->m_1F4 = float(delta);
			ctx.f1.f64 = nextValue;   // state the callee may pass on
			result = n_sub_8242C4E0(ctx, base, spellManagerAddr, nextIndex);
			ctx.fpscr.disableFlushMode();
			spellManager->m_204 = float(result);
			spellManager->m_208 = float(floatArg1);
		} else {
			spellManager->m_15C = 0xFFFFFFFFu;
		}
	} else {
		spellManager->m_15C = 0xFFFFFFFFu;
	}

	uint32_t activeSlot = spellManager->m_74;
	uint32_t previousIndex = spellManager->m_160;
	if ((int32_t)activeSlot != 0) {
		uint32_t slotOffset = activeSlot * 5;
		if ((int32_t)previousIndex >= 0) {
			slotOffset += previousIndex;
		}
		if (LOAD8(slotOffset + spellManagerAddr + 0x80) == 255) {
			spellManager->m_74 = 0;
		}
	}

	// r9 in the original: the value the scan loaded last (the 255 end byte, the m_15C limit or the new count)
	uint64_t returnR9;
	uint32_t scanAddr = spellManager->m_74 * 5 + spellManagerAddr + 0x80;
	int32_t slotIndex = 0;
	spellManager->m_16C = 0;
	for (;;) {
		uint8_t entry = LOAD8(scanAddr);
		if (entry == 255) {
			returnR9 = entry;
			break;
		}
		uint32_t maxIndex = spellManager->m_15C;
		if (slotIndex >= (int32_t)maxIndex && (int32_t)maxIndex >= 0) {
			returnR9 = maxIndex;
			break;
		}
		uint64_t newCount = (uint64_t)(uint32_t)spellManager->m_16C + 1;
		slotIndex++;
		scanAddr++;
		spellManager->m_16C = (uint32_t)newCount;
		if (slotIndex >= 5) {
			returnR9 = newCount;
			break;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r9, f12 and f13 after the call
	ctx.r9.u64 = returnR9;
	ctx.f12.f64 = floatArg1;
	ctx.f13.f64 = returnF13;
	return result;
}
PROMOTED_ENTRY(24, sub_82429920, 0x82429920) { ctx.f1.f64 = n_sub_82429920(ctx, base, ctx.r3.u32, ctx.f1.f64); }

uint32_t n_sub_82429A50(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t row, uint64_t level) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x82429A50)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = row; ctx.r5.u64 = level; __imp__sub_82429A50(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82429A50);
	PPCVRegister savedV126 = ctx.v126;
	PPCVRegister savedV127 = ctx.v127;
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	PPCRegister callTarget{};
	const uint32_t globalRootAddr = uint32_t(g_83490000) + 26912;

	// v126/v127 are saved below the caller's stack pointer; ctx gets the entry values back at the return.
	VSTORE((stack + 0xFFFFFFB0u) & ~0xF, V8(savedV126));
	VSTORE((stack + 0xFFFFFFC0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 208);
	PPCVRegister entryV1 = ctx.v1;

	// A non-negative global value overrides the requested level.
	uint64_t effectiveLevel = level;
	int32_t levelOverride = (int32_t)LOAD32(uint32_t(g_83320000) - 28196);
	if (levelOverride >= 0) {
		effectiveLevel = (uint32_t)levelOverride;
	}
	uint64_t cappedCount = effectiveLevel + 1;
	if ((int32_t)cappedCount > 4) {
		cappedCount = 4;
	}

	ctx.r1.u64 = stack;
	ctx.v126 = entryV1;
	n_sub_824BEAF8(ctx, base, spellManager->m_owner, (uint32_t)row, cappedCount, spellManager->m_265);
	// r8 (and r7 further down) is handed on to the calls below and left for the callers.
	uint64_t r8Value = ctx.r8.u64;
	// v1 as the call left it; replaced by the vector the owner's virtual method writes to stack + 112.
	PPCVRegister shotVector = ctx.v1;

	if ((int32_t)row == 0) {
		uint32_t playersRef = LOAD32(LOAD32(LOAD32(LOAD32(globalRootAddr) + 12) + 88) + 4);
		ctx.r9.u64 = playersRef;
		uint32_t isPlayer = Players_IsPlayer(ctx, base, LOAD32(playersRef), spellManager->m_owner);
		r8Value = isPlayer & 0xFF;
		if (r8Value != 0) {
			uint32_t component = LOAD32(uint32_t(spellManager->m_owner) + 124);
			uint32_t vtable = LOAD32(component);
			uint32_t method = LOAD32(vtable + 64);
			callTarget.u64 = method;
			ctx.r3.u64 = (uint64_t)stack + 112;
			ctx.r4.u64 = component;
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = method;
			ctx.r10.u64 = vtable;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r8Value = (uint64_t)stack + 112;
			SET_V8(shotVector, VLOAD((stack + 112) & ~0xF));
		}
	}

	// The cast table at +128 holds a signed spell id per (row, level), five per row.
	uint32_t castByte = LOAD8((uint32_t)row * 5 + (uint32_t)effectiveLevel + (uint32_t)spellManagerAddr + 128);
	int32_t spellId = (int8_t)castByte;

	// Entity handle at +432; m_1B4 is its reference, whose first word is the target (0 once it is gone).
	uint64_t handleAddr = spellManagerAddr + 432;
	uint32_t handleRef = spellManager->m_1B4;
	uint64_t handleTarget = 0;
	if (handleRef != 0) {
		uint32_t target = LOAD32(handleRef);
		if (target != 0) {
			handleTarget = target;
		} else {
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = castByte;
			ctx.r10.u64 = target;
			EntityHandle_Release(ctx, base, handleAddr);
			r8Value = ctx.r8.u64;
		}
	}

	uint64_t r7Value = handleTarget;
	if (spellId > -1) {
		ctx.r8.u64 = r8Value;
		ctx.v1 = shotVector;
		ctx.v2 = entryV1;
		ctx.v127 = shotVector;
		uint32_t spellShot = SpellManager_CreateSpellShot(ctx, base, spellManagerAddr, (uint64_t)(int64_t)spellId, row, effectiveLevel, handleTarget);
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		if (spellShot != 0) {
			n_sub_8242E460(ctx, base, spellManagerAddr, effectiveLevel, row);
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
		}
	}

	uint32_t playersRef = LOAD32(LOAD32(LOAD32(LOAD32(globalRootAddr) + 12) + 88) + 4);
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = playersRef;
	uint64_t result = Players_IsPlayer(ctx, base, LOAD32(playersRef), spellManager->m_owner);
	uint64_t r6Value = ctx.r6.u64;
	r7Value = ctx.r7.u64;
	r8Value = (uint32_t)result & 0xFF;

	if (r8Value != 0) {
		uint32_t owner = spellManager->m_owner;
		result = 0;
		if ((LOAD32(owner + 48) >> 3) & 1) {
			// Component 99: through the owner's index table at +140 when present, else a lower_bound
			// over the sorted 8-byte (key, value) entries between +72 and +76.
			uint32_t indexTable = LOAD32(owner + 140);
			if (indexTable != 0) {
				uint32_t index = LOAD8(indexTable + 99);
				uint32_t entries = LOAD32(owner + 72);
				result = LOAD32(index * 8 + entries + 4);
			} else {
				uint32_t it = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				r6Value = end;
				STORE32(stack + 96, 0u);
				r8Value = (uint64_t)end - it;
				STORE32(stack + 100, it);
				int32_t remaining = (int32_t)r8Value >> 3;
				if (remaining > 0) {
					do {
						int32_t half = remaining >> 1;
						r8Value = (uint32_t)half << 3;
						it += (uint32_t)r8Value;
						r7Value = ((int32_t)LOAD32(it) < 99) ? 1u : 0u;
						if (r7Value != 0) {
							remaining = remaining - half - 1;
							it += 8;
						} else {
							it -= (uint32_t)r8Value;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 100, it);
				}
				if (it != end && (int32_t)LOAD32(it) <= 99) {
					STORE64(stack + 96, LOAD64(stack + 96));
					result = LOAD32(LOAD32(stack + 100) + 4);
				} else {
					result = LOAD32(end + 4);
				}
			}
			if ((int32_t)LOAD32((uint32_t)result + 16) != 2) {
				STORE32((uint32_t)result + 16, 2u);
			}
			ctx.fpscr.disableFlushMode();
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			ctx.f1.f64 = double(LOAD_F32(0x8209B4D8u));
			result = n_sub_822B3AE8(ctx, base, result);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
		}
	}

	stack = PopStackFrame(stack, 208);
	// callers read r0, r6, r7 and r8 after the call
	ctx.r0.u64 = 0xFFFFFFC0u;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.v126 = savedV126;
	ctx.v127 = savedV127;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_82429A50, 0x82429A50) { ctx.r3.u64 = n_sub_82429A50(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

double n_sub_8242C4E0(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr, uint32_t spellIndex) {
	if (!UseLiftedCode(24, 0x8242C4E0)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = spellIndex; __imp__sub_8242C4E0(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x8242C4E0);
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	// callers read r6 and r8 after the call: the caller's values, or what the m_1A4 branch below sets
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r8Value = ctx.r8.u64;

	ctx.fpscr.disableFlushMode();
	double baseValue = double(LOAD_F32(spellIndex * 4u + 0x833191A0u));
	if ((int32_t)spellIndex <= 0) return baseValue;

	// With the global flag byte set and m_1A4 non-negative, the scale comes from a float table with
	// 11 entries per row (row m_1A4 clamped to 2, column spellIndex clamped to 5); otherwise a constant.
	int32_t row = (int32_t)spellManager->m_1A4;
	double scale = double(LOAD_F32(0x820994C0u));
	if (row >= 0) {
		r8Value = 0xFFFFFFFF83490000ull;
		if (LOAD8(0x834969DEu) != 0) {
			if (row > 2) row = 2;
			uint32_t column = (int32_t)spellIndex > 5 ? 5u : spellIndex;
			r6Value = (uint32_t)(row * 11 + column) << 2;
			r8Value = 0xFFFFFFFF83320000ull;
			ctx.fpscr.disableFlushMode();
			scale = double(LOAD_F32((uint32_t)r6Value + 0x83319250u));
		}
	}

	ctx.fpscr.disableFlushMode();
	double result = double(float(scale * baseValue));
	double minimum = double(LOAD_F32(0x8209932Cu));
	ctx.r6.u64 = r6Value;
	ctx.r8.u64 = r8Value;
	if (result < minimum) return minimum;
	return result;
}
PROMOTED_ENTRY(24, sub_8242C4E0, 0x8242C4E0) { ctx.f1.f64 = n_sub_8242C4E0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t SpellManager_SetSpellCastTableItem(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint32_t spellCastId, uint32_t slotIndex, uint64_t spellCastValue, uint64_t shouldBroadcast) {
	if (!UseLiftedCode(24, 0x8242C970)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = spellCastId; ctx.r5.u64 = slotIndex; ctx.r6.u64 = spellCastValue; ctx.r7.u64 = shouldBroadcast; __imp__sub_8242C970(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8242C970);
	uint32_t stack = ctx.r1.u64;

	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 144);

	// The value goes into both rows (five bytes apart) of the cast table at +128.
	uint64_t spellCastTable = spellManagerAddr + 128;
	uint8_t value = (uint8_t)spellCastValue;
	STORE8((uint32_t)spellCastTable + slotIndex, value);
	STORE8((uint32_t)spellCastTable + slotIndex + 5, value);

	ctx.r1.u64 = stack;
	ctx.r6.u64 = spellCastValue;  // state the callee may pass on
	SpellCastTable_Changed(ctx, base, spellCastTable);
	SpellCastTable_Changed(ctx, base, spellCastTable);

	uint64_t result = spellCastTable;
	if (((uint32_t)shouldBroadcast & 0xFF) != 0) {
		uint32_t owner = spellManager->m_owner;
		result = Entity_IsNetworked(ctx, base, owner);
		if (((uint32_t)result & 0xFF) != 0) {
			STORE32(stack + 84, spellCastId);
			STORE32(stack + 88, (uint32_t)spellCastValue);
			STORE32(stack + 92, slotIndex);
			uint32_t eventOwner = spellManager->m_owner;
			STORE32(stack + 80, 0x820A458Cu);
			uint32_t rootEntry = LOAD32(LOAD32(0x83496920u) + 12);
			uint32_t sendTarget = LOAD32(rootEntry + 140);
			ctx.r8.u64 = rootEntry;  // state the callee may pass on
			uint64_t ownerUniqueId = Entity_GetUniqueId(ctx, base, eventOwner);
			result = Network_SendEntityEvent(ctx, base, sendTarget, (uint64_t)stack + 80, ownerUniqueId);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242C970, 0x8242C970) { ctx.r3.u64 = SpellManager_SetSpellCastTableItem(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t n_sub_8242CAB0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820B1C18_B_ = int32_t(0x820B1C18);
	constexpr int32_t str_TXT_820B1C2C_B_ = int32_t(0x820B1C2C);
	constexpr int32_t str_TXT_820B1C40_B_ = int32_t(0x820B1C40);
	constexpr int32_t str_TXT_820B1C8C_B_ = int32_t(0x820B1C8C);
	constexpr int32_t str_TXT_820B1CA8_B_ = int32_t(0x820B1CA8);
	constexpr int32_t str_TXT_820B1CC4_B_ = int32_t(0x820B1CC4);
	constexpr int32_t str_TXT_820B1D28_B_ = int32_t(0x820B1D28);
	constexpr int32_t str_TXT_820B1D40_B_ = int32_t(0x820B1D40);
	constexpr int32_t g_834BE728 = int32_t(0x834BE728);
	constexpr int32_t g_834BE73C = int32_t(0x834BE73C);
	constexpr int32_t g_834BE750 = int32_t(0x834BE750);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	if (!UseLiftedCode(24, 0x8242CAB0)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242CAB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242CAB0);

	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	const uint32_t managerBase = uint32_t(spellManagerAddr);
	const uint64_t hashSeed = 0xFFFFFFFF811C9DC5ull;
	const uint32_t hashFlagsAddr = uint32_t(g_834C0000) + 14676;
	const uint32_t chargingFXHashes = uint32_t(g_834BE728);
	const uint32_t chargedScaleHashes = uint32_t(g_834BE73C);
	const uint32_t orbFXHashes = uint32_t(g_834BE750);

	// r4 and r6 are handed to sub_82622780 and sub_8242D100: the caller's values, then what the hash
	// blocks and the callees below leave in them.
	uint64_t r4Value = ctx.r4.u64;
	uint64_t r6Value = ctx.r6.u64;

	uint32_t hashFlags = LOAD32(hashFlagsAddr);

	// Static name-hash tables; each block is built once, guarded by its flag bit.
	if ((hashFlags & 1) == 0) {
		hashFlags |= 1;
		STORE32(hashFlagsAddr, hashFlags);
		ctx.r1.u64 = stack;
		STORE32(chargingFXHashes + 0, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1C40_B_), hashSeed));
		STORE32(chargingFXHashes + 4, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1C2C_B_), hashSeed));
		STORE32(chargingFXHashes + 8, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1C18_B_), hashSeed));
		ctx.r8.s64 = str_TXT_820B0000_B_;
		STORE32(chargingFXHashes + 12, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7172, hashSeed));
		ctx.r7.s64 = str_TXT_820B0000_B_;
		STORE32(chargingFXHashes + 16, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7152, hashSeed));
		r4Value = hashSeed;
	}
	if ((hashFlags & 2) == 0) {
		hashFlags |= 2;
		STORE32(hashFlagsAddr, hashFlags);
		ctx.r1.u64 = stack;
		STORE32(chargedScaleHashes + 0, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1CC4_B_), hashSeed));
		STORE32(chargedScaleHashes + 4, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1CA8_B_), hashSeed));
		STORE32(chargedScaleHashes + 8, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1C8C_B_), hashSeed));
		ctx.r8.s64 = str_TXT_820B0000_B_;
		STORE32(chargedScaleHashes + 12, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7280, hashSeed));
		ctx.r7.s64 = str_TXT_820B0000_B_;
		STORE32(chargedScaleHashes + 16, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7252, hashSeed));
		r4Value = hashSeed;
	}
	if ((hashFlags & 4) == 0) {
		STORE32(hashFlagsAddr, hashFlags | 4);
		ctx.r1.u64 = stack;
		STORE32(orbFXHashes + 0, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1D40_B_), hashSeed));
		STORE32(orbFXHashes + 4, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B1D28_B_), hashSeed));
		ctx.r8.s64 = str_TXT_820B0000_B_;
		STORE32(orbFXHashes + 8, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7440, hashSeed));
		ctx.r7.s64 = str_TXT_820B0000_B_;
		STORE32(orbFXHashes + 12, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7416, hashSeed));
		STORE32(orbFXHashes + 16, String_HashFnv1(ctx, base, uint64_t(str_TXT_820B0000_B_) + 7392, hashSeed));
		r4Value = hashSeed;
		r6Value = uint64_t(str_TXT_820B0000_B_);
	}

	spellManager->m_28C = 0;
	spellManager->m_290 = 0;
	ctx.fpscr.disableFlushMode();
	const float defaultScale = LOAD_F32(0x820994C0u);
	spellManager->m_274 = defaultScale;
	spellManager->m_278 = defaultScale;

	// The cast table at +128 has two rows of five spell ids; every entry gets a charging-FX word at +0x294,
	// an orb-FX word at +0x2BC and a charged-scale float at +0x2E4 (4 bytes per entry), filled from the
	// spell's definition fields named by the hash tables (indexed by column).
	for (uint32_t row = 0; row < 2; ++row) {
		for (uint32_t column = 0; column < 5; ++column) {
			const uint32_t entryIndex = row * 5 + column;
			const uint32_t chargedScaleAddr = managerBase + 0x2E4 + entryIndex * 4;
			const uint32_t chargingFXAddr = chargedScaleAddr - 80;
			const uint32_t orbFXAddr = chargedScaleAddr - 40;
			ctx.fpscr.disableFlushMode();
			STORE_F32(chargedScaleAddr, defaultScale);
			STORE32(chargingFXAddr, 0);
			STORE32(orbFXAddr, 0);

			const int32_t spellId = int8_t(LOAD8(managerBase + 0x80 + entryIndex));
			if (spellId == -1) continue;

			ctx.r1.u64 = stack;
			ctx.r4.u64 = r4Value;
			ctx.r6.u64 = r6Value;
			const uint64_t spellDef = n_sub_82622780(ctx, base, spellId);
			r4Value = ctx.r4.u64;
			r6Value = ctx.r6.u64;
			if (uint32_t(spellDef) == 0) continue;

			const uint32_t hashOffset = column * 4;

			const uint32_t chargingFXField = GameDB_FindFieldValue(ctx, base, spellDef, LOAD32(chargingFXHashes + hashOffset), 2);
			if (chargingFXField != 0) {
				STORE32(chargingFXAddr, LOAD32(chargingFXField));
			}

			const uint32_t chargedScaleField = GameDB_FindFieldValue(ctx, base, spellDef, LOAD32(chargedScaleHashes + hashOffset), 3);
			if (chargedScaleField != 0) {
				ctx.fpscr.disableFlushMode();
				STORE_F32(chargedScaleAddr, LOAD_F32(chargedScaleField));
			}

			const uint32_t orbFXField = GameDB_FindFieldValue(ctx, base, spellDef, LOAD32(orbFXHashes + hashOffset), 2);
			r4Value = ctx.r4.u64;
			r6Value = ctx.r6.u64;
			if (orbFXField != 0) {
				STORE32(orbFXAddr, LOAD32(orbFXField));
			} else {
				n_sub_829FB728(ctx, base, spellDef, LOAD32(orbFXHashes), orbFXAddr);
				r4Value = ctx.r4.u64;
				r6Value = ctx.r6.u64;
			}
		}
	}

	spellManager->m_180 = 0xFFFFFFFFu;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r6.u64 = r6Value;
	const uint32_t result = n_sub_8242D100(ctx, base, spellManagerAddr);
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242CAB0, 0x8242CAB0) { ctx.r3.u64 = n_sub_8242CAB0(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242CD80(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x8242CD80)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242CD80(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242CD80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Entity handle at +440: a tag word, then a reference whose first word is the entity (0 once it is gone).
	const uint64_t handleAddr = spellManagerAddr + 440;
	const uint32_t handleRef = LOAD32((uint32_t)spellManagerAddr + 444);
	uint64_t result = spellManagerAddr;

	if (handleRef != 0) {
		const uint32_t handleEntity = LOAD32(handleRef);
		if (handleEntity == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleEntity;  // state the callee may pass on
			const uint32_t released = EntityHandle_Release(ctx, base, handleAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return released;
		}

		ctx.r1.u64 = stack;
		ctx.r10.u64 = handleEntity;  // state the callee may pass on
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		// r6..r10 as this code or a callee last left them; handed on to the calls below.
		uint64_t r6Value = ctx.r6.u64;
		uint64_t r7Value = ctx.r7.u64;
		uint64_t r8Value = ctx.r8.u64;
		uint64_t r9Value = ctx.r9.u64;
		uint64_t r10Value = (LOAD32(entity + 44) >> 21) & 1;

		if (r10Value != 0) {
			// Component 85: through the entity's index table at +140 when present, else a lower_bound
			// over the sorted 8-byte (key, value) entries between +72 and +76.
			uint32_t component;
			const uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				r10Value = (uint64_t)LOAD8(indexTable + 85) << 3;
				r9Value = r10Value + LOAD32(entity + 72);
				component = LOAD32((uint32_t)r9Value + 4);
			} else {
				r10Value = LOAD32(entity + 72);
				r6Value = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, (uint32_t)r10Value);
				int32_t remaining = (int32_t)((uint32_t)r6Value - (uint32_t)r10Value) >> 3;
				if (remaining > 0) {
					do {
						const int32_t half = remaining >> 1;
						r9Value = (uint64_t)(int64_t)half;
						r8Value = (uint32_t)half << 3;
						r10Value += r8Value;
						r7Value = (int32_t)LOAD32((uint32_t)r10Value) < 85 ? 1 : 0;
						if (r7Value != 0) {
							remaining = remaining - half - 1;
							r10Value += 8;
						} else {
							r10Value -= r8Value;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, (uint32_t)r10Value);
				}
				if ((uint32_t)r10Value != (uint32_t)r6Value && (int32_t)LOAD32((uint32_t)r10Value) <= 85) {
					STORE64(stack + 80, LOAD64(stack + 80));
					component = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					component = LOAD32((uint32_t)r6Value + 4);
				}
			}

			const uint32_t subObject = LOAD32(component + 16);
			if (subObject != 0) {
				ctx.r6.u64 = r6Value;
				ctx.r7.u64 = r7Value;
				ctx.r8.u64 = r8Value;
				ctx.r9.u64 = r9Value;
				ctx.r10.u64 = r10Value;
				n_sub_8322B788(ctx, base, subObject);
				r6Value = ctx.r6.u64;
				r7Value = ctx.r7.u64;
				r8Value = ctx.r8.u64;
				r9Value = ctx.r9.u64;
				r10Value = ctx.r10.u64;
			}
		}

		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = r10Value;
		const uint64_t doomedEntity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		Entity_DestroyImpl(ctx, base, doomedEntity);

		// Reset the stored handle from an empty handle built at stack + 80, which is released before and
		// after the assignment.
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)g_820F1664);
		ctx.r10.u64 = (uint64_t)(int64_t)g_820F1664;  // state the callee may pass on
		EntityHandle_Release(ctx, base, (uint64_t)stack + 80);

		EntityHandle_Assign(ctx, base, handleAddr, (uint64_t)stack + 80);

		const uint64_t emptyHandleTag = (int64_t)g_820F0000 + 5732;
		STORE32(stack + 80, (uint32_t)emptyHandleTag);
		ctx.r8.u64 = emptyHandleTag;  // state the callee may pass on
		ctx.r9.s64 = g_820F0000;
		result = EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242CD80, 0x8242CD80) { ctx.r3.u64 = n_sub_8242CD80(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242CF40(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x8242CF40)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242CF40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242CF40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Entity handle at +448: a tag word, then a reference whose first word is the entity (0 once it is gone).
	const uint64_t handleAddr = spellManagerAddr + 448;
	const uint32_t handleRef = LOAD32((uint32_t)spellManagerAddr + 452);
	uint64_t result = spellManagerAddr;

	if (handleRef != 0) {
		const uint32_t handleEntity = LOAD32(handleRef);
		if (handleEntity == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleEntity;  // state the callee may pass on
			const uint32_t released = EntityHandle_Release(ctx, base, handleAddr);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return released;
		}

		ctx.r1.u64 = stack;
		ctx.r10.u64 = handleEntity;  // state the callee may pass on
		const uint32_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		// r6..r10 as this code or a callee last left them; handed on to the calls below.
		uint64_t r6Value = ctx.r6.u64;
		uint64_t r7Value = ctx.r7.u64;
		uint64_t r8Value = ctx.r8.u64;
		uint64_t r9Value = ctx.r9.u64;
		uint64_t r10Value = (LOAD32(entity + 44) >> 21) & 1;

		if (r10Value != 0) {
			// Component 85: through the entity's index table at +140 when present, else a lower_bound
			// over the sorted 8-byte (key, value) entries between +72 and +76.
			uint32_t component;
			const uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				r10Value = (uint64_t)LOAD8(indexTable + 85) << 3;
				r9Value = r10Value + LOAD32(entity + 72);
				component = LOAD32((uint32_t)r9Value + 4);
			} else {
				r10Value = LOAD32(entity + 72);
				r6Value = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, (uint32_t)r10Value);
				int32_t remaining = (int32_t)((uint32_t)r6Value - (uint32_t)r10Value) >> 3;
				if (remaining > 0) {
					do {
						const int32_t half = remaining >> 1;
						r9Value = (uint64_t)(int64_t)half;
						r8Value = (uint32_t)half << 3;
						r10Value += r8Value;
						r7Value = (int32_t)LOAD32((uint32_t)r10Value) < 85 ? 1 : 0;
						if (r7Value != 0) {
							remaining = remaining - half - 1;
							r10Value += 8;
						} else {
							r10Value -= r8Value;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, (uint32_t)r10Value);
				}
				if ((uint32_t)r10Value != (uint32_t)r6Value && (int32_t)LOAD32((uint32_t)r10Value) <= 85) {
					STORE64(stack + 80, LOAD64(stack + 80));
					component = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					component = LOAD32((uint32_t)r6Value + 4);
				}
			}

			const uint32_t subObject = LOAD32(component + 16);
			if (subObject != 0) {
				ctx.r6.u64 = r6Value;
				ctx.r7.u64 = r7Value;
				ctx.r8.u64 = r8Value;
				ctx.r9.u64 = r9Value;
				ctx.r10.u64 = r10Value;
				n_sub_8322B788(ctx, base, subObject);
				r6Value = ctx.r6.u64;
				r7Value = ctx.r7.u64;
				r8Value = ctx.r8.u64;
				r9Value = ctx.r9.u64;
				r10Value = ctx.r10.u64;
			}
		}

		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = r10Value;
		const uint64_t doomedEntity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		Entity_DestroyImpl(ctx, base, doomedEntity);

		// Reset the stored handle from an empty handle built at stack + 80, which is released before and
		// after the assignment.
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)g_820F1664);
		ctx.r10.u64 = (uint64_t)(int64_t)g_820F1664;  // state the callee may pass on
		EntityHandle_Release(ctx, base, (uint64_t)stack + 80);

		EntityHandle_Assign(ctx, base, handleAddr, (uint64_t)stack + 80);

		const uint64_t emptyHandleTag = (int64_t)g_820F0000 + 5732;
		STORE32(stack + 80, (uint32_t)emptyHandleTag);
		ctx.r8.u64 = emptyHandleTag;  // state the callee may pass on
		ctx.r9.s64 = g_820F0000;
		result = EntityHandle_Release(ctx, base, (uint64_t)stack + 80);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242CF40, 0x8242CF40) { ctx.r3.u64 = n_sub_8242CF40(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242D6E0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t flag) {
	if (!UseLiftedCode(24, 0x8242D6E0)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = flag; __imp__sub_8242D6E0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242D6E0);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	constexpr uint32_t kGlobalRootAddr = 0x83496920u;

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flag;  // state the callee may pass on
	const uint64_t ownerKind = n_sub_8242DA90(ctx, base, spellManagerAddr);
	// callers read f1 and f2 after the call
	double f1Value = ctx.f1.f64;
	double f2Value = ctx.f2.f64;
	uint64_t result = ownerKind;

	if ((uint32_t(flag) & 0xFF) == 0) {
		if (spellManager->m_267 != 0) {
			ctx.fpscr.disableFlushMode();
			f2Value = double(spellManager->m_22C);
			f1Value = double(LOAD_F32(0x820994B4u));
			uint32_t rootEntry = LOAD32(LOAD32(kGlobalRootAddr) + 12);
			uint32_t target = LOAD32(LOAD32(LOAD32(rootEntry + 88) + 4) + 80);
			ctx.r6.u64 = rootEntry;  // state the callee may pass on
			result = n_sub_8241FF50(ctx, base, target, spellManagerAddr + 424, ownerKind, 1u, f1Value, f2Value);
			f1Value = ctx.f1.f64;
			f2Value = ctx.f2.f64;
		}
	} else {
		ctx.fpscr.disableFlushMode();
		f2Value = double(LOAD_F32(0x82099338u));
		f1Value = double(LOAD_F32(0x820994B4u));
		result = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(kGlobalRootAddr) + 12) + 88) + 4) + 80);
		n_sub_82420130(ctx, base, (uint32_t)result, (uint32_t)ownerKind, f2Value);
	}
	spellManager->m_267 = 0;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.f1.f64 = f1Value;
	ctx.f2.f64 = f2Value;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242D6E0, 0x8242D6E0) { ctx.r3.u64 = n_sub_8242D6E0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Returns 1 when the owner is the hero entity, 2 when it is the local player's entity, else 0.
uint64_t n_sub_8242DA90(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr) {
	if (!UseLiftedCode(24, 0x8242DA90)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242DA90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8242DA90);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t ownerKind = 0;
	ctx.r1.u64 = stack;
	uint32_t isHeroEntity = Entity_IsHeroEntity(ctx, base, spellManager->m_owner);
	if ((isHeroEntity & 0xFF) != 0) {
		ownerKind = 1;
	} else {
		uint32_t isLocalPlayerEntity = SpellManager_IsLocalPlayerEntity(ctx, base, spellManager->m_owner);
		if ((isLocalPlayerEntity & 0xFF) != 0) {
			ownerKind = 2;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ownerKind;
}
PROMOTED_ENTRY(24, sub_8242DA90, 0x8242DA90) { ctx.r3.u64 = n_sub_8242DA90(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8242DB00(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t str_TXT_820B1DAC_B_ = int32_t(0x820B1DAC);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_8335C310 = int32_t(0x8335C310);
	if (!UseLiftedCode(24, 0x8242DB00)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242DB00(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242DB00);

	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint64_t result = spellManagerAddr;
	PPCRegister callTarget{};

	// the original prologue saves v127 below the frame
	VSTORE((stack + 0xFFFFFFC0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 176);
	auto leave = [&](uint64_t value) -> uint32_t {
		stack = PopStackFrame(stack, 176);
		ctx.r0.u64 = 0xFFFFFFC0u;  // callers see r0 as the original epilogue leaves it
		ctx.r1.u64 = stack;
		return (uint32_t)value;
	};

	// Entity handle at +464; m_1D4 is its reference, whose first word is the target (0 once it is gone).
	uint64_t handleAddr = spellManagerAddr + 464;
	bool hasTarget = false;
	uint32_t handleRef = spellManager->m_1D4;
	if (handleRef != 0) {
		uint32_t oldTarget = LOAD32(handleRef);
		if (oldTarget != 0) {
			hasTarget = true;
		} else {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = oldTarget;  // state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
		}
	}

	if (!hasTarget) {
		// Create the entity from its named definition and store it in the handle.
		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820B1DAC_B_, -1);
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B1DAC_B_, -1);

		// Method 16 of the owner's component at +124 is called with +96 of the frame; the vector there
		// then goes to Entity_CreateFromNamedDefinition in v1.
		uint32_t owner = spellManager->m_owner;
		uint32_t ownerComponent = LOAD32(owner + 124);
		uint32_t ownerVtable = LOAD32(ownerComponent);
		uint32_t ownerMethod = LOAD32(ownerVtable + 64);
		callTarget.u64 = ownerMethod;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = ownerComponent;
		// state the callee may pass on
		ctx.r8.u64 = ownerMethod;
		ctx.r9.u64 = ownerVtable;
		ctx.r10.u64 = owner;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		// r6 and v1 go to the callee through the state
		ctx.r6.u64 = 1;
		SET_V8(ctx.v1, VLOAD((stack + 96) & ~0xF));
		uint64_t createdEntity = Entity_CreateFromNamedDefinition(ctx, base, stack + 80, stack + 84, -1);

		// A temporary EntityHandle {vtable, 0} on the stack takes the entity, is assigned to the handle
		// and released.
		int64_t handleVtable = (int64_t)g_820F0000 + 5732;  // 0x820F1664
		uint32_t tempHandle = stack + 88;
		STORE32(stack + 92, 0);
		STORE32(tempHandle, (uint32_t)handleVtable);
		// state the callee may pass on
		ctx.r9.s64 = handleVtable;
		ctx.r10.s64 = g_820F0000;
		EntityHandle_SetTarget(ctx, base, tempHandle, createdEntity);
		EntityHandle_Assign(ctx, base, handleAddr, tempHandle);
		STORE32(tempHandle, (uint32_t)handleVtable);
		// state the callee may pass on
		ctx.r7.s64 = handleVtable;
		ctx.r8.s64 = g_820F0000;
		EntityHandle_Release(ctx, base, tempHandle);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
	}

	handleRef = spellManager->m_1D4;
	if (handleRef == 0)
		return leave(result);
	uint32_t target = LOAD32(handleRef);
	ctx.r1.u64 = stack;
	ctx.r10.u64 = target;  // state the callee may pass on
	if (target == 0)
		return leave(EntityHandle_Release(ctx, base, handleAddr));

	uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
	// r6-r8 as this call leaves them, changed below, go on to the light calls
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint32_t entityAddr = (uint32_t)entity;
	if (((LOAD32(entityAddr + 36) >> 8) & 1) != 0) {
		// Component 8 (the light) of the entity, from its sorted (type, instance) table: through the
		// cached index when there is one, otherwise with a lower_bound search.
		uint32_t light;
		uint32_t cached = LOAD32(entityAddr + 140);
		if (cached != 0) {
			uint32_t index = LOAD8(cached + 8);
			light = LOAD32(LOAD32(entityAddr + 72) + index * 8 + 4);
		} else {
			uint32_t begin = LOAD32(entityAddr + 72);
			uint32_t end = LOAD32(entityAddr + 76);
			r6Value = end;
			STORE32(stack + 88, 0);
			STORE32(stack + 92, begin);
			uint32_t byteCount = end - begin;
			int32_t count = (int32_t)byteCount >> 3;
			// the carry of this shift goes on to the light calls
			ctx.xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t mid = begin + ((uint32_t)half << 3);
					bool below = (int32_t)LOAD32(mid) < 8;
					r7Value = below ? 1 : 0;
					if (below) {
						begin = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 92, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 8) {
				STORE64(stack + 88, LOAD64(stack + 88));
				light = LOAD32(LOAD32(stack + 92) + 4);
			} else {
				light = LOAD32(end + 4);
			}
		}

		// m_80 selects one of the 220-byte light settings at 0x8335C310; the light takes each value that
		// differs and is marked for update after each change.
		auto markNeedsUpdate = [&]() {
			// state the callee may pass on, and r6-r8 as it leaves them
			ctx.r6.u64 = r6Value;
			ctx.r7.u64 = r7Value;
			ctx.r8.u64 = r8Value;
			Light_MarkNeedsUpdate(ctx, base, light);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
		};
		int8_t settingIndex = (int8_t)spellManager->m_80;
		r8Value = (uint64_t)(int64_t)settingIndex;
		uint32_t setting = (uint32_t)((int64_t)settingIndex * 220) + uint32_t(g_8335C310);
		uint32_t setting0 = LOAD32(setting);
		uint32_t setting4 = LOAD32(setting + 4);
		uint32_t setting8 = LOAD32(setting + 8);
		bool bytesMatch = false;
		if ((int32_t)LOAD8(light + 18) == (int32_t)setting0) {
			r8Value = LOAD8(light + 17);
			if ((int32_t)r8Value == (int32_t)setting4) {
				r8Value = LOAD8(light + 16);
				bytesMatch = (int32_t)r8Value == (int32_t)setting8;
			}
		}
		if (!bytesMatch) {
			STORE8(light + 18, (uint8_t)setting0);
			STORE8(light + 17, (uint8_t)setting4);
			STORE8(light + 16, (uint8_t)setting8);
			markNeedsUpdate();
		}
		// Returns the f13 value the next call receives: the light's previous value, or what the update left.
		auto copyFloat = [&](uint32_t settingOffset, uint32_t lightOffset) -> double {
			ctx.fpscr.disableFlushMode();
			double wanted = double(LOAD_F32(setting + settingOffset));
			double current = double(LOAD_F32(light + lightOffset));
			if (current == wanted)
				return current;
			STORE_F32(light + lightOffset, float(wanted));
			ctx.f13.f64 = current;  // state the callee may pass on
			markNeedsUpdate();
			return ctx.f13.f64;
		};
		copyFloat(12, 24);
		copyFloat(20, 20);
		copyFloat(28, 72);
		copyFloat(32, 64);
		double f13Value = copyFloat(36, 68);

		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Value;
		ctx.f13.f64 = f13Value;
		n_sub_8255EC08(ctx, base, light, 1);  // Lua_Light_SetAsActive
		r8Value = ctx.r8.u64;
		spellManager->m_1EC = setting;
	}

	spellManager->m_26F = 0;
	spellManager->m_184 = 0;
	ctx.fpscr.disableFlushMode();
	spellManager->m_228 = float(double(LOAD_F32(0x820994B4u)));
	ctx.r8.u64 = r8Value;  // state the callee may pass on
	n_sub_824BE7F0(ctx, base, spellManager->m_owner, 0, spellManager->m_74, spellManager->m_263);

	// The original keeps v1, as that call left it, in v127 across EntityHandle_Get and hands it to
	// method 25 of the entity's component at +124.
	PPCVRegister keptV1 = ctx.v1;
	uint64_t currentEntity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
	uint32_t entityComponent = LOAD32((uint32_t)currentEntity + 124);
	uint32_t componentVtable = LOAD32(entityComponent);
	uint32_t componentMethod = LOAD32(componentVtable + 100);
	callTarget.u64 = componentMethod;
	ctx.r3.u64 = entityComponent;
	// state the callee may pass on
	ctx.r9.u64 = componentMethod;
	ctx.r10.u64 = componentVtable;
	ctx.v1 = keptV1;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	return leave(ctx.r3.u64);
}
PROMOTED_ENTRY(24, sub_8242DB00, 0x8242DB00) { ctx.r3.u64 = n_sub_8242DB00(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242DEA0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x8242DEA0)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242DEA0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242DEA0);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// Entity handle at +464; m_1D4 is its reference, whose first word is the target (0 once it is gone).
	uint64_t handleAddr = spellManagerAddr + 464;
	uint64_t result = spellManagerAddr;
	uint32_t handleRef = spellManager->m_1D4;
	if (handleRef != 0) {
		uint32_t target = LOAD32(handleRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = target;  // state the callee may pass on
		if (target == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			Entity_DestroyImpl(ctx, base, entity);

			// Empty the handle: assign it a temporary EntityHandle {vtable, 0} built on the stack.
			uint32_t tempHandle = stack + 80;
			STORE32(stack + 84, 0);
			STORE32(tempHandle, uint32_t(g_820F1664));
			ctx.r10.s64 = g_820F1664;  // state the callee may pass on
			EntityHandle_Release(ctx, base, tempHandle);
			EntityHandle_Assign(ctx, base, handleAddr, tempHandle);

			uint32_t handleVtable = uint32_t(g_820F0000) + 5732;  // 0x820F1664
			STORE32(tempHandle, handleVtable);
			// state the callee may pass on
			ctx.r8.u64 = handleVtable;
			ctx.r9.u64 = uint32_t(g_820F0000);
			result = EntityHandle_Release(ctx, base, tempHandle);
			spellManager->m_26F = 0;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242DEA0, 0x8242DEA0) { ctx.r3.u64 = n_sub_8242DEA0(ctx, base, ctx.r3.u64); }

// sub_8242DF40  [524 bytes]
uint32_t CECSpellManager_UpdateSpellLight(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	if (!UseLiftedCode(24, 0x8242DF40)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242DF40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242DF40);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	// Entity handle at +464; m_1D4 is its reference, whose first word is the target (0 once it is gone).
	uint64_t handleAddr = spellManagerAddr + 464;
	uint64_t result = handleAddr;
	uint32_t handleRef = spellManager->m_1D4;
	if (handleRef != 0) {
		uint32_t target = LOAD32(handleRef);
		if (target == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = target;  // state the callee may pass on
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else if (spellManager->m_26F == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = target;  // state the callee may pass on
			uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			result = entity;
			// r5-r8 as this call leaves them, changed below, go on to Lua_Light_SetAsActive
			uint64_t r5Value = ctx.r5.u64;
			uint64_t r6Value = ctx.r6.u64;
			uint64_t r7Value = ctx.r7.u64;
			uint64_t r8Value = ctx.r8.u64;
			uint32_t entityAddr = (uint32_t)entity;
			if (((LOAD32(entityAddr + 36) >> 8) & 1) != 0) {
				// Component 8 (the light) of the entity, from its sorted (type, instance) table: through the
				// cached index when there is one, otherwise with a lower_bound search.
				uint32_t light;
				uint32_t cached = LOAD32(entityAddr + 140);
				if (cached != 0) {
					uint32_t index = LOAD8(cached + 8);
					light = LOAD32(LOAD32(entityAddr + 72) + index * 8 + 4);
				} else {
					uint32_t begin = LOAD32(entityAddr + 72);
					uint32_t end = LOAD32(entityAddr + 76);
					r6Value = end;
					STORE32(stack + 80, 0);
					STORE32(stack + 84, begin);
					uint32_t byteCount = end - begin;
					int32_t count = (int32_t)byteCount >> 3;
					// the carry of this shift goes on to Lua_Light_SetAsActive
					ctx.xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
					if (count > 0) {
						do {
							int32_t half = count >> 1;
							r8Value = (uint32_t)half << 3;
							uint32_t mid = begin + (uint32_t)r8Value;
							bool below = (int32_t)LOAD32(mid) < 8;
							r7Value = below ? 1 : 0;
							if (below) {
								begin = mid + 8;
								count = count - half - 1;
							} else {
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, begin);
					}
					if (begin != end && (int32_t)LOAD32(begin) <= 8) {
						STORE64(stack + 80, LOAD64(stack + 80));
						light = LOAD32(LOAD32(stack + 84) + 4);
					} else {
						light = LOAD32(end + 4);
					}
				}

				// The source value is a constant, or, when m_70 is set and m_160 is not negative, the float at +40
				// of entry m_160 + 5 * (signed byte at +128 + m_160) of the 44-byte entries at 0x8335C310.
				ctx.fpscr.disableFlushMode();
				double sourceValue = double(LOAD_F32(0x820994C0u));
				if (spellManager->m_70 != 0) {
					uint32_t row = spellManager->m_160;
					if ((int32_t)row >= 0) {
						r8Value = (uint64_t)(int64_t)g_83360000;
						r7Value = LOAD8(row + (uint32_t)spellManagerAddr + 128);
						r6Value = (uint64_t)((int64_t)g_83360000 - 15600 + 40);
						uint64_t column = (uint64_t)(int64_t)(int8_t)r7Value;
						r5Value = column + (uint32_t)((uint32_t)column << 2) + row;
						sourceValue = double(LOAD_F32((uint32_t)r5Value * 44 + (uint32_t)r6Value));
					}
				}

				// Scaled, rounded to an integer, back to float and truncated into the light's word at +52.
				ctx.fpscr.disableFlushMode();
				double scaled = sourceValue * LOAD_F64(0x83319510u);
				double rounded = double(float(scaled));
				PPCRegister roundedInt;
				roundedInt.s64 = std::isnan(rounded) ? int64_t(0x8000000000000000ULL)
					: rounded > double(LLONG_MAX) ? LLONG_MAX
					: simde_mm_cvtsd_si64(simde_mm_load_sd(&rounded));
				double widened = double(roundedInt.s64);
				double narrowed = double(float(widened));
				PPCRegister truncatedInt;
				truncatedInt.s64 = std::isnan(narrowed) ? int64_t(0x80000000U)
					: narrowed > double(INT_MAX) ? INT_MAX
					: simde_mm_cvttsd_si32(simde_mm_load_sd(&narrowed));
				STORE32(light + 52, truncatedInt.u32);

				// state the callee may pass on
				ctx.r5.u64 = r5Value;
				ctx.r6.u64 = r6Value;
				ctx.r7.u64 = r7Value;
				ctx.r8.u64 = r8Value;
				ctx.f9 = truncatedInt;
				ctx.f10.f64 = narrowed;
				ctx.f11.f64 = widened;
				ctx.f12 = roundedInt;
				ctx.f13.f64 = rounded;
				result = n_sub_8255EC08(ctx, base, light, 0);  // Lua_Light_SetAsActive
			}
			spellManager->m_26F = 1;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242DF40, 0x8242DF40) { ctx.r3.u64 = CECSpellManager_UpdateSpellLight(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242E150(CpuState& ctx, uint8_t* base, uint32_t managerAddr, uint64_t resetM224) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t str_TXT_820B1DC8_B_ = int32_t(0x820B1DC8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x8242E150)) { ctx.r3.u64 = managerAddr; ctx.r4.u64 = resetM224; __imp__sub_8242E150(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242E150);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, managerAddr);
	// r4 and r9 as callers see them after the return (not after the return that follows n_sub_824C90A0)
	uint64_t callerR4 = resetM224;
	uint64_t callerR9 = ctx.r9.u64;
	stack = PushStackFrame(base, stack, 160);

	uint32_t result = managerAddr;
	uint32_t constants = uint32_t(g_820994C0);
	if ((resetM224 & 0xFF) != 0) {
		ctx.fpscr.disableFlushMode();
		spellManager->m_224 = float(double(LOAD_F32(constants - 404)));
	}

	bool wantActive = false;
	int32_t index = (int32_t)spellManager->m_160;
	if (index > 0) {
		uint8_t indexedByte = LOAD8(managerAddr + (uint32_t)index + 128);
		callerR9 = indexedByte;
		wantActive = indexedByte == 0;
	}

	if (uint32_t(spellManager->m_26E) != uint32_t(wantActive)) {
		if (wantActive) {
			uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t container = LOAD32(LOAD32(globalObject + 12) + 88);
			uint32_t element = LOAD32(container + 4);
			uint32_t elementValue = LOAD32(element + 60);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r8.u64 = element;
			ctx.r9.u64 = container;
			uint32_t effect = (uint32_t)n_sub_824C92D8(ctx, base, elementValue, spellManager->m_owner, 0);
			callerR4 = ctx.r4.u64;
			callerR9 = ctx.r9.u64;
			result = effect;
			spellManager->m_1E4 = effect;
			if (effect != 0) {
				uint64_t refCount = (uint64_t)LOAD32(effect + 16) + 1;
				STORE32(effect + 16, (uint32_t)refCount);

				// look the effect name up through its transformed copy
				uint32_t name = stack + 100;
				uint32_t transformedName = stack + 96;
				ctx.r9.u64 = refCount;  // state the callee may pass on
				CCharString_ConstructFromCStr(ctx, base, name, str_TXT_820B1DC8_B_, -1);
				CCharString_CopyTransformed(ctx, base, transformedName, name);
				uint32_t nameKey = (uint32_t)n_sub_82BFD780(ctx, base, transformedName);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, transformedName);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, name);

				ctx.fpscr.disableFlushMode();
				double floatArg2 = double(LOAD_F32(constants));
				double floatArg1 = double(LOAD_F32(constants + 18756));
				STORE32(stack + 100, 0);
				STORE32(stack + 96, nameKey);
				STORE8(stack + 95, 0);
				STORE32(stack + 84, stack + 100);
				ctx.r8.u64 = stack + 100;  // state the callee may pass on
				uint32_t instance = n_sub_824C90A0(ctx, base, elementValue, spellManager->m_owner, spellManager->m_1E4, 0, 2, stack + 96, floatArg1, floatArg2);
				spellManager->m_1E8 = instance;
				spellManager->m_26E = 1;
				stack = PopStackFrame(stack, 160);
				ctx.r1.u64 = stack;
				return instance;
			}
		} else {
			uint32_t activeEffect = spellManager->m_1E4;
			if (activeEffect != 0) {
				STORE32(activeEffect + 16, LOAD32(activeEffect + 16) - 1);
				spellManager->m_1E4 = 0;
			}
			uint32_t activeInstance = spellManager->m_1E8;
			if (activeInstance != 0) {
				STORE8(activeInstance + 48, 1);
				spellManager->m_1E8 = 0;
			}
			spellManager->m_26E = 0;
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4 and r9 after the call
	ctx.r4.u64 = callerR4;
	ctx.r9.u64 = callerR9;
	return result;
}
PROMOTED_ENTRY(24, sub_8242E150, 0x8242E150) { ctx.r3.u64 = n_sub_8242E150(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t n_sub_8242E460(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr, uint64_t recordIndex, uint32_t enableByte) {
	constexpr uint32_t kShakeTable = 0x833191F8;
	constexpr uint32_t kShakeParams = 0x820994B4;
	if (!UseLiftedCode(24, 0x8242E460)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = recordIndex; ctx.r5.u64 = enableByte; __imp__sub_8242E460(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242E460);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	uint32_t result = CECSpellManager_FadeScreenShake(ctx, base, spellManagerAddr);
	// r6-r8, f1, f2 and xer.ca as callers see them after the return; cr0 and xer.ca also go to ScreenShake_Add
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	double f1Value = ctx.f1.f64;
	double f2Value = ctx.f2.f64;
	PPCCRRegister compare0 = ctx.cr0;
	flags.ca = ctx.xer.ca;

	if ((int32_t)recordIndex >= 0 && (int32_t)recordIndex < 5) {
		uint32_t owner = spellManager->m_owner;
		result = 0;
		if (((LOAD32(owner + 40) >> 1) & 1) != 0) {
			// Component 33 of the owner, from its sorted (type, instance) table: through the cached index
			// when there is one, otherwise with a lower_bound search (which sets cr0, xer.ca and r6; the
			// r7/r8 values it leaves are replaced below).
			uint32_t cached = LOAD32(owner + 140);
			if (cached != 0) {
				uint32_t index = LOAD8(cached + 33);
				result = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
			} else {
				uint32_t begin = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				r6Value = end;
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				uint32_t byteCount = end - begin;
				int32_t count = (int32_t)byteCount >> 3;
				flags.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
				compare0.compare<int32_t>(count, 0, flags);
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						uint32_t mid = begin + ((uint32_t)half << 3);
						if ((int32_t)LOAD32(mid) < 33) {
							begin = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= 33) {
					STORE64(stack + 80, LOAD64(stack + 80));
					result = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					result = LOAD32(end + 4);
				}
			}

			// 12-byte records at kShakeTable: enable bytes at +0 and +1 (enableByte picks one), floats at
			// +4 (must exceed the threshold at kShakeParams) and +8.
			r8Value = recordIndex + (uint32_t)((uint32_t)recordIndex << 1);
			uint32_t record = ((uint32_t)r8Value << 2) + kShakeTable;
			r7Value = (uint64_t)(int64_t)(int32_t)kShakeTable + 4;
			ctx.fpscr.disableFlushMode();
			f1Value = double(LOAD_F32(record + 4));
			f2Value = double(LOAD_F32(kShakeParams));
			if (f1Value > f2Value) {
				bool enabled = false;
				if ((int32_t)enableByte == 0) {
					r8Value = LOAD8(record);
					enabled = r8Value != 0;
				} else if ((int32_t)enableByte == 1) {
					r8Value = (uint64_t)(int64_t)(int32_t)kShakeTable + 1;
					r7Value = LOAD8(record + 1);
					enabled = r7Value != 0;
				}
				if (enabled) {
					ctx.fpscr.disableFlushMode();
					double f3Value = double(LOAD_F32(kShakeParams + 12));
					double f4Value = double(LOAD_F32(record + 8));
					// state the callee may pass on
					ctx.r3.u64 = result;
					ctx.r6.u64 = r6Value;
					ctx.r7.u64 = r7Value;
					ctx.r8.u64 = r8Value;
					ctx.cr0 = compare0;
					ctx.xer.ca = flags.ca;
					result = (uint32_t)ScreenShake_Add(ctx, base, 5, 1, f1Value, f2Value, f3Value, f4Value);
					r6Value = ctx.r6.u64;
					r7Value = ctx.r7.u64;
					r8Value = ctx.r8.u64;
					f1Value = ctx.f1.f64;
					f2Value = ctx.f2.f64;
					flags.ca = ctx.xer.ca;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r6-r8, f1, f2 and xer.ca after the call
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.f1.f64 = f1Value;
	ctx.f2.f64 = f2Value;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(24, sub_8242E460, 0x8242E460) { ctx.r3.u64 = n_sub_8242E460(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

// sub_8242E628  [324 bytes]
uint32_t CECSpellManager_FadeScreenShake(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr) {
	if (!UseLiftedCode(24, 0x8242E628)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242E628(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242E628);
	uint32_t stack = ctx.r1.u32;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	// cr0 and xer.ca, which the component search sets, go to ScreenShake_Fade
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 96);

	uint32_t result = 0;
	uint32_t owner = spellManager->m_owner;
	if (((LOAD32(owner + 40) >> 1) & 1) != 0) {
		// Component 33 of the owner, from its sorted (type, instance) table: through the cached index
		// when there is one, otherwise with a lower_bound search.
		uint32_t component;
		uint32_t cached = LOAD32(owner + 140);
		if (cached != 0) {
			uint32_t index = LOAD8(cached + 33);
			component = LOAD32(LOAD32(owner + 72) + index * 8 + 4);
		} else {
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			uint32_t byteCount = end - begin;
			int32_t count = (int32_t)byteCount >> 3;
			flags.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			compare0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t mid = begin + ((uint32_t)half << 3);
					if ((int32_t)LOAD32(mid) < 33) {
						begin = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}

		ctx.fpscr.disableFlushMode();
		double fadeAmount = double(LOAD_F32(0x8209B4E0u));
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r3.u64 = component;
		ctx.cr0 = compare0;
		ctx.xer.ca = flags.ca;
		result = (uint32_t)ScreenShake_Fade(ctx, base, 4, fadeAmount);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242E628, 0x8242E628) { ctx.r3.u64 = CECSpellManager_FadeScreenShake(ctx, base, ctx.r3.u32); }

uint32_t n_sub_8242E910(CpuState& ctx, uint8_t* base, uint32_t spellManagerAddr, uint32_t passToHandler) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(24, 0x8242E910)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = passToHandler; __imp__sub_8242E910(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242E910);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint64_t result = spellManagerAddr;
	stack = PushStackFrame(base, stack, 128);

	if (spellManager->m_26A != 0) {
		uint32_t owner = spellManager->m_owner;
		uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t container = LOAD32(LOAD32(globalObject + 12) + 88);
		uint32_t element = LOAD32(container + 4);
		uint32_t searchKey = LOAD32(element + 68);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r8.u64 = element;
		ctx.r9.u64 = container;
		uint64_t spell = SpellManager_FindSpellByTarget(ctx, base, searchKey, 2, 0, owner);
		result = spell;
		if ((uint32_t)spell != 0) {
			// with the low byte of passToHandler set, n_sub_827C9C70 takes the spell (and r8 as the search
			// left it); otherwise the spell's byte at +158 is cleared
			if ((passToHandler & 0xFF) == 0) {
				STORE8((uint32_t)spell + 158, 0);
			} else {
				result = n_sub_827C9C70(ctx, base, spell, ctx.r8.u64);
			}
			STORE8((uint32_t)spell + 72, 1);
		}
		spellManager->m_26A = 0;
		spellManager->m_26B = 0;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(24, sub_8242E910, 0x8242E910) { ctx.r3.u64 = n_sub_8242E910(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t n_sub_8242E9A0(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(24, 0x8242E9A0)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_8242E9A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242E9A0);
	uint32_t stack = ctx.r1.u64;
	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = arg3;
	n_sub_8242EA70(ctx, base, spellManagerAddr);

	// Entity handle at +472; m_1DC is its reference, whose first word is the target (0 once it is gone).
	uint32_t target = 0;
	uint32_t handleRef = spellManager->m_1DC;
	if (handleRef != 0) {
		target = LOAD32(handleRef);
		if (target == 0) {
			ctx.r10.u64 = target;  // state the callee may pass on
			EntityHandle_Release(ctx, base, spellManagerAddr + 472);
		}
	}

	uint32_t result = n_sub_824BE3B0(ctx, base, target, arg2, arg3, 1);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242E9A0, 0x8242E9A0) { ctx.r3.u64 = n_sub_8242E9A0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// Passes the entity behind the manager's EntityHandle (+472) on to n_sub_824BE5A8, or 0 when the handle is
// empty; a handle whose target was cleared is released first.
uint64_t n_sub_8242EA00(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(24, 0x8242EA00)) { ctx.r3.u64 = spellManagerAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_8242EA00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8242EA00);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	uint64_t entityHandleAddr = spellManagerAddr + 472;
	uint32_t targetRecord = LOAD32((uint32_t)entityHandleAddr + 4);  // second word of the handle
	uint64_t targetEntity = 0;
	if (targetRecord != 0) {
		targetEntity = LOAD32(targetRecord);
		if (targetEntity == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r4.u64 = arg2;
			ctx.r5.u64 = arg3;
			ctx.r10.u64 = 0;
			EntityHandle_Release(ctx, base, entityHandleAddr);
		}
	}
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_824BE5A8(ctx, base, targetEntity, arg2, arg3);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242EA00, 0x8242EA00) { ctx.r3.u64 = n_sub_8242EA00(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// Makes sure the manager's spell-audio entity exists: when its EntityHandle (+472) has no live target, creates
// the entity and stores it in the handle. Returns the manager when the entity already existed.
uint32_t n_sub_8242EA70(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t str_TXT_820B1DE4_B_ = int32_t(0x820B1DE4);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(24, 0x8242EA70)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242EA70(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242EA70);
	PPCVRegister savedV127 = ctx.v127;
	uint32_t stack = ctx.r1.u64;

	CECSpellManager* spellManager = GameObject<CECSpellManager>(base, spellManagerAddr);
	uint64_t spellAudioHandleAddr = spellManagerAddr + 472;  // EntityHandle held inside the manager

	// Save v127 in the caller's frame; restored on the way out.
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 176);

	uint32_t targetRecord = spellManager->m_1DC;  // second word of the handle
	if (targetRecord != 0) {
		if (LOAD32(targetRecord) != 0) {
			// The spell-audio entity already exists.
			stack = PopStackFrame(stack, 176);
			ctx.r1.u64 = stack;
			ctx.r0.u64 = 0xFFFFFFD0;  // callers may read r0 after the call
			ctx.v127 = savedV127;
			return spellManagerAddr;
		}
		// The handle's target was cleared: release the handle before creating a new entity.
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 0;  // state the callee may pass on
		EntityHandle_Release(ctx, base, spellAudioHandleAddr);
	}

	ctx.r1.u64 = stack;

	uint32_t entityNameCopy = stack + 84;
	CCharString_ConstructFromCStr(ctx, base, entityNameCopy, str_TXT_820B1DE4_B_, -1);
	uint32_t entityName = stack + 80;
	CCharString_ConstructFromCStr(ctx, base, entityName, str_TXT_820B1DE4_B_, -1);

	// Virtual call (vtable offset 64) on the object at owner+124; it writes a 16-byte vector to stack+112.
	uint32_t owner = spellManager->m_owner;
	uint32_t vectorBuffer = stack + 112;
	uint32_t ownerObject = LOAD32(owner + 124);
	uint32_t ownerObjectVtable = LOAD32(ownerObject);
	uint32_t virtualFn = LOAD32(ownerObjectVtable + 64);
	ctx.r3.u64 = vectorBuffer;
	ctx.r4.u64 = ownerObject;
	// state the callee may pass on
	ctx.r8.u64 = virtualFn;
	ctx.r9.u64 = ownerObjectVtable;
	ctx.r10.u64 = owner;
	REX_CALL_INDIRECT_FUNC(virtualFn);

	// The vector reaches the entity creation in v1 and v127.
	PPCVRegister ownerVector{};
	SET_V8(ownerVector, VLOAD(vectorBuffer & ~0xF));

	uint32_t fixedTextString = stack + 88;  // built by n_sub_824C1818 from a fixed text constant
	ctx.r5.u64 = 0;  // state the callee may pass on
	uint64_t fixedText = n_sub_824C1818(ctx, base, fixedTextString);

	ctx.v1 = ownerVector;
	ctx.v127 = ownerVector;
	uint64_t entity = Entity_CreateFromNamedDefinition(ctx, base, entityName, fixedText, 0xFFFFFFFF);

	// Temporary EntityHandle at stack+96: aimed at the new entity, copied into the manager's handle, released.
	uint32_t tempHandle = stack + 96;
	STORE32(stack + 100, 0);
	STORE32(tempHandle, uint32_t(int64_t(g_820F0000) + 5732));
	// state the callee may pass on
	ctx.r5.u64 = 0;
	ctx.r6.s64 = g_820F0000;
	EntityHandle_SetTarget(ctx, base, tempHandle, entity);

	EntityHandle_Assign(ctx, base, spellAudioHandleAddr, tempHandle);

	uint64_t handleVtable = uint64_t(int64_t(g_820F0000) + 5732);
	STORE32(tempHandle, uint32_t(handleVtable));
	// state the callee may pass on
	ctx.r9.u64 = handleVtable;
	ctx.r10.s64 = g_820F0000;
	EntityHandle_Release(ctx, base, tempHandle);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, fixedTextString);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, entityName);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, entityNameCopy);

	uint32_t result = EntityHandle_Get_825575C8(ctx, base, spellAudioHandleAddr);
	if (result != 0) {
		result = CECSpellManager_GetSpellComponent(ctx, base, spellManagerAddr);
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r0.u64 = 0xFFFFFFD0;  // callers may read r0 after the call
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(24, sub_8242EA70, 0x8242EA70) { ctx.r3.u64 = n_sub_8242EA70(ctx, base, ctx.r3.u64); }

// Destroys the entity behind the manager's EntityHandle (+472) when the handle has a target, and empties the handle;
// a handle whose target was already cleared is just released.
uint32_t n_sub_8242EBB8(CpuState& ctx, uint8_t* base, uint64_t spellManagerAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(24, 0x8242EBB8)) { ctx.r3.u64 = spellManagerAddr; __imp__sub_8242EBB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242EBB8);
	uint32_t stack = ctx.r1.u64;
	// r7/r8 for the final call: the values on entry, replaced on the destroy path.
	uint64_t r7HandOver = ctx.r7.u64;
	uint64_t r8HandOver = ctx.r8.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint32_t targetRecord = GameObject<CECSpellManager>(base, spellManagerAddr)->m_1DC;  // second word of the handle
	const uint64_t entityHandleAddr = spellManagerAddr + 472;
	if (targetRecord == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return (uint32_t)spellManagerAddr;
	}

	const uint32_t targetEntity = LOAD32(targetRecord);
	uint64_t handleToRelease = entityHandleAddr;
	uint32_t r10HandOver = targetEntity;  // r10 for the final call
	if (targetEntity != 0) {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = targetEntity;  // state the callee may pass on
		uint64_t entity = EntityHandle_Get_825575C8(ctx, base, entityHandleAddr);
		Entity_DestroyImpl(ctx, base, entity);

		// Empty temporary EntityHandle at stack+80: released, assigned to the manager's handle, released again below.
		const uint32_t emptyHandle = stack + 80;
		STORE32(stack + 84, 0);
		STORE32(emptyHandle, (uint32_t)g_820F1664);
		// state the callee may pass on
		ctx.r9.u64 = (uint64_t)(int64_t)g_820F1664;
		ctx.r10.u64 = 0;
		EntityHandle_Release(ctx, base, emptyHandle);
		EntityHandle_Assign(ctx, base, entityHandleAddr, emptyHandle);
		r10HandOver = ctx.r10.u32;

		handleToRelease = emptyHandle;
		r7HandOver = (uint64_t)((int64_t)g_820F0000 + 5732);
		r8HandOver = (uint64_t)(int64_t)g_820F0000;
		STORE32(emptyHandle, (uint32_t)r7HandOver);
	}

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r7.u64 = r7HandOver;
	ctx.r8.u64 = r8HandOver;
	ctx.r10.u64 = r10HandOver;
	uint32_t result = EntityHandle_Release(ctx, base, handleToRelease);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242EBB8, 0x8242EBB8) { ctx.r3.u64 = n_sub_8242EBB8(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8242EC58(CpuState& ctx, uint8_t* base, uint64_t spellManager, uint32_t spellType, uint64_t slotIndex) {
	constexpr int32_t str_TXT_820B1E00_B_ = int32_t(0x820B1E00);
	constexpr int32_t str_TXT_820B1DF8_B_ = int32_t(0x820B1DF8);
	constexpr int32_t g_StringCounter = int32_t(0x83496EB8);
	constexpr int32_t TXT_83497DE4_G_ = int32_t(0x83497DE4);
	if (!UseLiftedCode(24, 0x8242EC58)) { ctx.r3.u64 = spellManager; ctx.r4.u64 = spellType; ctx.r5.u64 = slotIndex; __imp__sub_8242EC58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242EC58);
	uint32_t stack = ctx.r1.u64;
	uint32_t msrFromR13 = ctx.r13.u64;
	uint64_t savedMsr{};
	uint64_t incremented{};
	PPCCRRegister casResult{};
	PPCXERRegister flags{};
	flags.so = ctx.xer.so;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	// CCharString temporaries living in the game stack frame
	const uint32_t prefixAndSpell = stack + 80;
	const uint32_t spellName = stack + 84;
	const uint32_t slotSuffix = stack + 88;
	const uint32_t scratch = stack + 92;  // slot number text, later the name passed to n_sub_8242E9A0

	ctx.r5.u64 = slotIndex;  // state the callee may pass on
	uint64_t slotNumberText = CCharString_ConstructFormatInt(ctx, base, scratch, slotIndex + 1);
	CCharString_ConstructFromCStr(ctx, base, slotSuffix, str_TXT_820B1DF8_B_, -1);
	RefCountedString_Assign(ctx, base, slotSuffix, slotNumberText);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratch);

	// spellName starts empty: zero its pointer and atomically increment the global string count.
	STORE32(spellName, 0);
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		savedMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = msrFromR13 & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)g_StringCounter);
		incremented = (int64_t)(uint64_t)__builtin_bswap32(ctx.reserved.u32) + 1;
		casResult.lt = 0;
		casResult.gt = 0;
		casResult.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)g_StringCounter)), ctx.reserved.s32, __builtin_bswap32((int32_t)incremented));
		casResult.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = (uint32_t)savedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!casResult.eq);
	// state the callee may pass on
	ctx.r6.s64 = g_StringCounter;
	ctx.r7.u64 = 0;
	ctx.r8.u64 = savedMsr;
	ctx.r9.u64 = incremented;
	ctx.cr0.lt = casResult.lt;
	ctx.cr0.gt = casResult.gt;
	ctx.cr0.eq = casResult.eq;
	ctx.cr0.so = casResult.so;
	SpellType_GetNameString(ctx, base, spellName, spellType);

	CCharString_ConstructFromCStr(ctx, base, prefixAndSpell, str_TXT_820B1E00_B_, -1);
	RefCountedString_Assign(ctx, base, prefixAndSpell, spellName);
	LocalisedString_Assign(ctx, base, scratch, prefixAndSpell, slotSuffix);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, prefixAndSpell);

	n_sub_8242E9A0(ctx, base, spellManager, scratch, TXT_83497DE4_G_);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratch);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, spellName);
	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, slotSuffix);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242EC58, 0x8242EC58) { ctx.r3.u64 = n_sub_8242EC58(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64); }

uint32_t CECSpellManager_PlaySpellReleaseSound(CpuState& ctx, uint8_t* base, uint64_t spellManager, uint32_t spellType, uint32_t castMode, uint64_t slotIndex) {
	constexpr int32_t str_TXT_820B1DF8_B_ = int32_t(0x820B1DF8);
	constexpr int32_t str_TXT_820B1E14_B_ = int32_t(0x820B1E14);
	constexpr int32_t str_TXT_820B1E20_B_ = int32_t(0x820B1E20);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	constexpr int32_t str_TXT_820B1E44_B_ = int32_t(0x820B1E44);
	constexpr int32_t TXT_83497DE8_G_ = int32_t(0x83497DE8);
	if (!UseLiftedCode(24, 0x8242EE88)) { ctx.r3.u64 = spellManager; ctx.r4.u64 = spellType; ctx.r5.u64 = castMode; ctx.r6.u64 = slotIndex; __imp__sub_8242EE88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8242EE88);

	uint32_t stack = ctx.r1.u64;
	uint32_t msrFromR13 = ctx.r13.u64;
	uint64_t savedMsr{};
	uint32_t incremented{};
	PPCCRRegister casResult{};
	PPCXERRegister flags{};
	flags.so = ctx.xer.so;
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	const uint32_t scratchStr = stack + 96;      // slot number string, reused for the cast mode prefix
	const uint32_t slotSuffixStr = stack + 88;
	const uint32_t prefixStr = stack + 80;
	const uint32_t spellNameStr = stack + 84;
	const uint32_t joinedStr = stack + 100;      // prefix + spell name
	const uint32_t soundNameStr = stack + 92;    // joined + slot suffix

	const uint64_t slotNumber = CCharString_ConstructFormatInt(ctx, base, scratchStr, slotIndex + 1);
	CCharString_ConstructFromCStr(ctx, base, slotSuffixStr, str_TXT_820B1DF8_B_, -1);
	RefCountedString_Assign(ctx, base, slotSuffixStr, slotNumber);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchStr);

	const int32_t castModePrefix = (castMode == 1) ? str_TXT_820B1E14_B_ : str_TXT_820B1E20_B_;
	CCharString_ConstructFromCStr(ctx, base, scratchStr, castModePrefix, -1);

	// spellNameStr starts empty: zero its pointer and atomically increment the global string count.
	STORE32(spellNameStr, 0);
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		savedMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = msrFromR13 & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)g_83496EB8);
		incremented = __builtin_bswap32(ctx.reserved.u32) + 1;
		casResult.lt = 0;
		casResult.gt = 0;
		casResult.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)g_83496EB8)), ctx.reserved.s32, __builtin_bswap32((int32_t)incremented));
		casResult.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = (uint32_t)savedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!casResult.eq);
	// state the callee may pass on
	ctx.r8.u64 = 0;
	ctx.cr0.lt = casResult.lt;
	ctx.cr0.gt = casResult.gt;
	ctx.cr0.eq = casResult.eq;
	ctx.cr0.so = casResult.so;
	SpellType_GetNameString(ctx, base, spellNameStr, spellType);

	ctx.r6.s64 = int32_t(0x820B0000);  // state the callee may pass on (upper half of the string address)
	CCharString_ConstructFromCStr(ctx, base, prefixStr, str_TXT_820B1E44_B_, -1);
	RefCountedString_Assign(ctx, base, prefixStr, scratchStr);
	const uint64_t prefixAndSpellName = LocalisedString_Assign(ctx, base, joinedStr, prefixStr, spellNameStr);
	LocalisedString_Assign(ctx, base, soundNameStr, prefixAndSpellName, slotSuffixStr);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, joinedStr);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, prefixStr);
	n_sub_8242E9A0(ctx, base, spellManager, soundNameStr, TXT_83497DE8_G_);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, soundNameStr);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, spellNameStr);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchStr);
	const uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, slotSuffixStr);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(24, sub_8242EE88, 0x8242EE88) { ctx.r3.u64 = CECSpellManager_PlaySpellReleaseSound(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32, ctx.r6.u64); }
