// CECElectrified (vtable 0x820ED440): methods of the class as readable C++.
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

uint64_t CECElectrified_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameResult) {
	if (!UseLiftedCode(67, 0x829759C0)) { ctx.r3.u64 = classNameResult; __imp__sub_829759C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829759C0);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameResult, int32_t(0x820C8E64), -1);
	return classNameResult;
}
PROMOTED_ENTRY(67, sub_829759C0, 0x829759C0) { ctx.r3.u64 = CECElectrified_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82975C20(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr, uint64_t stream, uint64_t flags) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820B59DC_B_ = int32_t(0x820B59DC);
	constexpr int32_t str_TXT_820CFD90_B_ = int32_t(0x820CFD90);
	constexpr int32_t str_TXT_820CFDA0_B_ = int32_t(0x820CFDA0);
	constexpr int32_t str_TXT_820E013C_B_ = int32_t(0x820E013C);
	constexpr int32_t str_TXT_820E01B0_B_ = int32_t(0x820E01B0);
	constexpr int32_t str_TXT_820E01C4_B_ = int32_t(0x820E01C4);
	constexpr int32_t str_TXT_820E01D8_B_ = int32_t(0x820E01D8);
	constexpr int32_t str_TXT_820ED3F8_B_ = int32_t(0x820ED3F8);
	constexpr int32_t str_TXT_820ED404_B_ = int32_t(0x820ED404);
	constexpr int32_t str_TXT_820ED414_B_ = int32_t(0x820ED414);
	if (!UseLiftedCode(67, 0x82975C20)) { ctx.r3.u64 = electrifiedAddr; ctx.r4.u64 = stream; ctx.r6.u64 = flags; __imp__sub_82975C20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82975C20);
	uint32_t stack = ctx.r1.u64;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	stack = PushStackFrame(base, stack, 128);
	uint64_t nameBuffer = (uint64_t)stack + 80;
	ctx.r1.u64 = stack;
	ctx.r6.u64 = flags;  // state the callee may pass on

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820B59DC_B_, -1);
	IStream_SerializeString(ctx, base, nameBuffer, stream, electrifiedAddr + 12);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	// The value serializers below also receive the field name's text in r4, computed the way
	// IStream_SerializeString does: the first word of the string data, or 0x8209003F when there is none.
	auto nameText = [&]() -> uint64_t {
		uint32_t stringData = LOAD32(stack + 80);
		return stringData != 0 ? uint64_t(LOAD32(stringData)) : uint64_t(int64_t(g_8209003F));
	};

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820ED3F8_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 40);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820E013C_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 48);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820ED404_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 52);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820ED414_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 60);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820CFD90_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820CFDA0_B_, -1);
	IStream_SerializeFloat(ctx, base, stream, electrifiedAddr + 68);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820E01B0_B_, -1);
	IStream_SerializeId(ctx, base, stream, electrifiedAddr + 32);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820E01C4_B_, -1);
	IStream_SerializeU32(ctx, base, stream, electrifiedAddr + 36);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	CCharString_ConstructFromCStr(ctx, base, nameBuffer, str_TXT_820E01D8_B_, -1);
	n_sub_8244DAE0(ctx, base, electrifiedAddr + 96, nameBuffer, stream);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameBuffer);

	electrified->m_F = uint8_t(((uint32_t)flags & 0xFF) == 0);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(67, sub_82975C20, 0x82975C20) { ctx.r3.u64 = n_sub_82975C20(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint64_t n_sub_82975E90(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(68, 0x82975E90)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82975E90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82975E90);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);
	stack = PushStackFrame(base, stack, 128);

	// Raise the count at +8 of the object reached from the global at 0x83496920 (sub_82976128 lowers it).
	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t counterBlock = LOAD32(LOAD32(LOAD32(LOAD32(globalObject + 12) + 88) + 4) + 56);
	uint64_t newCount = uint64_t(LOAD32(counterBlock + 8)) + 1;
	STORE32(counterBlock + 8, (uint32_t)newCount);

	electrified->m_11 = 1;
	electrified->m_12 = 0;
	electrified->m_13 = 0;
	electrified->m_14 = 1;
	electrified->m_15 = 1;

	ctx.r1.u64 = stack;
	ctx.r7.u64 = newCount;  // state the callee may pass on
	uint32_t healthState = Entity_GetHealthComponent(ctx, base, electrified->m_4);
	uint64_t r8Value = ctx.r8.u64;
	if ((int32_t)healthState == 11) {
		electrified->m_12 = 1;
		electrified->m_13 = 1;
		electrified->m_11 = 0;
	} else {
		uint32_t entity = electrified->m_4;
		uint32_t playersSlot = LOAD32(LOAD32(LOAD32(globalObject + 12) + 88) + 4);
		uint32_t players = LOAD32(playersSlot);
		ctx.r5.u64 = globalObject;  // state the callee may pass on
		uint32_t isPlayer = Players_IsPlayer(ctx, base, players, entity);
		r8Value = isPlayer & 0xFF;
		if ((uint32_t)r8Value != 0) {
			electrified->m_14 = 0;
			electrified->m_15 = 0;
			electrified->m_11 = 0;
		}
	}

	uint32_t entity = electrified->m_4;
	ctx.r8.u64 = r8Value;  // state the callee may pass on
	uint64_t result = n_sub_824BD958(ctx, base, entity);
	// r6-r9, cr0 and the carry as the original leaves them (r4 further down); n_sub_82977DB8 is handed these.
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	r8Value = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	flags.ca = ctx.xer.ca;
	if (((uint32_t)result & 0xFF) == 0)
		electrified->m_15 = 0;

	// m_70 = value stored for key 6 in the entity's keyed table: the bit for the key in the mask at
	// +36, then either the byte index table at +140 or a lower_bound search of the sorted 8-byte
	// {key, value} pairs in [+72, +76) (its iterator kept in a stack temporary at +80/+84).
	entity = electrified->m_4;
	electrified->m_70 = 0;
	uint64_t r9Value = (LOAD32(entity + 36) >> 6) & 1;
	if ((uint32_t)r9Value != 0) {
		uint32_t keyValue;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t pairIndex = LOAD8(indexTable + 6);
			uint32_t pairs = LOAD32(entity + 72);
			r9Value = uint64_t(pairIndex << 3) + pairs;
			keyValue = LOAD32((uint32_t)r9Value + 4);
		} else {
			uint32_t pair = LOAD32(entity + 72);
			r6Value = LOAD32(entity + 76);
			uint32_t end = (uint32_t)r6Value;
			STORE32(stack + 80, 0);
			uint32_t span = end - pair;
			STORE32(stack + 84, pair);
			flags.ca = (int32_t)span < 0 & (span & 0x7) != 0;
			int32_t count = (int32_t)span >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				flags.ca = 0;  // the halving shift only ever sees a positive count
				do {
					int32_t half = count >> 1;
					r9Value = (uint64_t)(int64_t)half;
					r8Value = uint32_t(half) << 3;
					pair += (uint32_t)r8Value;
					r7Value = (int32_t)LOAD32(pair) < 6;
					if (r7Value != 0) {
						count -= half + 1;
						pair += 8;
					} else {
						pair -= (uint32_t)r8Value;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pair);
			}
			if (pair != end && (int32_t)LOAD32(pair) <= 6) {
				STORE64(stack + 80, LOAD64(stack + 80));
				keyValue = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				keyValue = LOAD32(end + 4);
			}
		}
		electrified->m_70 = keyValue;
	}

	if (electrified->m_F != 0) {
		uint32_t isActive = electrified->m_C;
		electrified->m_F = 0;
		if (isActive != 0) {
			// +96 holds the two-word UID that sub_82975C20 serializes under str_TXT_820E01D8_B_.
			uint64_t originUidAddr = electrifiedAddr + 96;
			uint64_t r4Value = originUidAddr;
			bool hasOriginUid = LOAD32((uint32_t)electrifiedAddr + 96) != 0 || LOAD32((uint32_t)originUidAddr + 4) != 0;
			if (hasOriginUid) {
				uint32_t playersOwner = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88);
				uint32_t playersSlot = LOAD32(playersOwner + 4);
				uint32_t players = LOAD32(playersSlot);
				ctx.r8.u64 = playersSlot;  // state the callee may pass on
				ctx.xer.ca = flags.ca;
				uint64_t originEntity = n_sub_82264448(ctx, base, players, originUidAddr);

				// Temporary EntityHandle {vtable, target} at stack+80, copied into the handle at +104.
				uint64_t handleVtable = (int64_t)g_820F0000 + 5732;
				uint64_t tempHandle = (uint64_t)stack + 80;
				STORE32(stack + 84, 0);
				STORE32(stack + 80, (uint32_t)handleVtable);
				ctx.r6.u64 = handleVtable;  // state the callee may pass on
				ctx.cr0 = compare0;
				EntityHandle_SetTarget(ctx, base, tempHandle, originEntity);
				EntityHandle_Assign(ctx, base, electrifiedAddr + 104, tempHandle);
				STORE32(stack + 80, (uint32_t)handleVtable);
				ctx.r4.u64 = handleVtable;  // state the callee may pass on
				EntityHandle_Release(ctx, base, tempHandle);
				r4Value = ctx.r4.u64;
				r6Value = ctx.r6.u64;
				r7Value = ctx.r7.u64;
				r8Value = ctx.r8.u64;
				r9Value = ctx.r9.u64;
				compare0 = ctx.cr0;
				flags.ca = ctx.xer.ca;
			}
			// state the callee may pass on
			ctx.r8.u64 = r8Value;
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			n_sub_82977DB8(ctx, base, electrifiedAddr);
			n_sub_82976AF0(ctx, base, electrifiedAddr);
			n_sub_82977100(ctx, base, electrifiedAddr);
			if (electrified->m_15 != 0)
				n_sub_824B9528(ctx, base, electrified->m_4, 89, 89, 89);
			result = n_sub_82977C30(ctx, base, electrifiedAddr);
			ctx.fpscr.disableFlushMode();
			electrified->m_2C = float(double(electrified->m_3C));
			electrified->m_10 = 1;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_82975E90, 0x82975E90) { ctx.r3.u64 = n_sub_82975E90(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82976128(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(68, 0x82976128)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82976128(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82976128);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	n_sub_82976DD8(ctx, base, electrifiedAddr);
	n_sub_82977E68(ctx, base, electrifiedAddr);

	// The object reached from the global at 0x83496920 keeps counts at +8 (raised by sub_82975E90)
	// and +24. +24 is lowered here when m_D is set, +8 at the end; neither goes below zero.
	if (electrified->m_D != 0) {
		uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
		electrified->m_D = 0;
		uint32_t counterBlock = LOAD32(LOAD32(LOAD32(LOAD32(globalObject + 12) + 88) + 4) + 56);
		uint32_t count = LOAD32(counterBlock + 24);
		if ((int32_t)count > 0)
			STORE32(counterBlock + 24, count - 1);
	}

	uint32_t entityFlag = n_sub_824BCE78(ctx, base, electrified->m_4) & 0xFF;
	uint32_t level = entityFlag == 0 ? 64 : 255;
	uint64_t result = n_sub_82977498(ctx, base, electrifiedAddr, entityFlag == 0 ? 1 : 0);
	uint64_t r6Value = ctx.r6.u64;
	flags.ca = ctx.xer.ca;
	if (electrified->m_15 != 0) {
		result = n_sub_824B9528(ctx, base, electrified->m_4, level, level, level);
		r6Value = ctx.r6.u64;
		flags.ca = ctx.xer.ca;
	}

	// Clear byte +114 of the value stored for key 58 in the entity's keyed table: the bit for the key
	// in the mask at +40, then either the byte index table at +140 or a lower_bound search of the
	// sorted 8-byte {key, value} pairs in [+72, +76) (its iterator kept in a stack temporary at +80/+84).
	uint32_t entity = electrified->m_4;
	if (((LOAD32(entity + 40) >> 26) & 1) != 0) {
		uint32_t keyValue;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t pairIndex = LOAD8(indexTable + 58);
			keyValue = LOAD32(LOAD32(entity + 72) + (pairIndex << 3) + 4);
		} else {
			uint32_t pair = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			r6Value = end;
			STORE32(stack + 80, 0);
			uint32_t span = end - pair;
			STORE32(stack + 84, pair);
			flags.ca = (int32_t)span < 0 & (span & 0x7) != 0;
			int32_t count = (int32_t)span >> 3;
			if (count > 0) {
				flags.ca = 0;  // the halving shift only ever sees a positive count
				do {
					int32_t half = count >> 1;
					uint32_t middle = pair + (uint32_t(half) << 3);
					if ((int32_t)LOAD32(middle) < 58) {
						pair = middle + 8;
						count -= half + 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pair);
			}
			if (pair != end && (int32_t)LOAD32(pair) <= 58) {
				STORE64(stack + 80, LOAD64(stack + 80));
				keyValue = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				keyValue = LOAD32(end + 4);
			}
		}
		STORE8(keyValue + 114, 0);
	}

	if (electrified->m_12 != 0) {
		ctx.fpscr.disableFlushMode();
		double floatArg = double(LOAD_F32(0x820994C0u));
		ctx.r6.u64 = r6Value;  // state the callee may pass on
		ctx.xer.ca = flags.ca;
		result = n_sub_827CA600(ctx, base, electrified->m_4, floatArg);
	}

	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t counterBlock = LOAD32(LOAD32(LOAD32(LOAD32(globalObject + 12) + 88) + 4) + 56);
	uint32_t count = LOAD32(counterBlock + 8);
	if ((int32_t)count > 0)
		STORE32(counterBlock + 8, count - 1);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_82976128, 0x82976128) { ctx.r3.u64 = n_sub_82976128(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82976A20(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(68, 0x82976A20)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82976A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82976A20);
	uint32_t stack = ctx.r1.u64;
	// The original keeps newTimer, timerStep and timerPeriod in f9-f11; they start as the incoming
	// registers, which callers get back unchanged when the timer is not counting down.
	double newTimer = ctx.f9.f64;
	double timerStep = ctx.f10.f64;
	double timerPeriod = ctx.f11.f64;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	stack = PushStackFrame(base, stack, 144);
	uint64_t result = electrified->m_4;  // returned unless n_sub_824BB6C8 is called
	ctx.r1.u64 = stack;
	double elapsed = n_sub_82207928(ctx, base, result);
	ctx.fpscr.disableFlushMode();

	// m_30 (serialized as str_TXT_820E013C_B_) counts down by elapsed / divisor / m_38 to the floor value.
	double TXT_820E013C_L_ = double(electrified->m_30);
	double timeDivisor = LOAD_F64(uint32_t(g_83320000) - 27376);
	double scaledElapsed = double(float(elapsed / timeDivisor));
	double timerFloor = double(LOAD_F32(uint32_t(g_820994C0) - 12));

	bool timerExpired = false;
	if (TXT_820E013C_L_ > timerFloor) {
		timerPeriod = double(electrified->m_38);
		timerStep = double(float(scaledElapsed / timerPeriod));
		newTimer = double(float(TXT_820E013C_L_ - timerStep));
		electrified->m_30 = float(newTimer);
		if (!(newTimer > timerFloor)) {
			electrified->m_30 = float(timerFloor);
			timerExpired = true;
		}
	}

	if (timerExpired) {
		ctx.fpscr.disableFlushMode();
		// m_34 is serialized as str_TXT_820ED404_B_.
		double TXT_820ED404_L_ = double(electrified->m_34);
		if (TXT_820ED404_L_ > timerFloor) {
			uint64_t originHandleAddr = electrifiedAddr + 104;  // set by sub_82975E90 from the origin UID
			uint32_t entity = electrified->m_4;
			uint32_t field24 = electrified->m_24;
			uint32_t field20 = electrified->m_20;
			// state the callee may pass on
			uint64_t originEntity = EntityHandle_Get_825575C8(ctx, base, originHandleAddr);
			ctx.fpscr.disableFlushMode();
			STORE8(stack + 87, uint8_t(1));
			result = n_sub_824BB6C8(ctx, base, originEntity, entity, field20, 0, field24, 2048, 0, TXT_820ED404_L_);
			ctx.fpscr.disableFlushMode();
			double timerReset = double(LOAD_F32(uint32_t(g_820994C0)));
			electrified->m_30 = float(timerReset);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return result;  // callers get f1 and f9-f13 as the call above left them
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read f1 and f9-f13 after the call
	ctx.f1.f64 = elapsed;
	ctx.f9.f64 = newTimer;
	ctx.f10.f64 = timerStep;
	ctx.f11.f64 = timerPeriod;
	ctx.f12.f64 = scaledElapsed;
	ctx.f13.f64 = TXT_820E013C_L_;
	return result;
}
PROMOTED_ENTRY(68, sub_82976A20, 0x82976A20) { ctx.r3.u64 = n_sub_82976A20(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82976DD8(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(68, 0x82976DD8)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82976DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82976DD8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// EntityHandle {vtable, reference} at +128; the reference points at the entity pointer.
	uint64_t handleAddr = electrifiedAddr + 128;
	uint32_t reference = LOAD32((uint32_t)electrifiedAddr + 132);
	if (reference == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return electrifiedAddr;
	}

	uint32_t entity = LOAD32(reference);
	if (entity == 0) {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = 0;  // state the callee may pass on; r7 and r8 still hold their incoming values
		uint64_t result = EntityHandle_Release(ctx, base, handleAddr);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return result;
	}

	ctx.r1.u64 = stack;
	n_sub_824B8500(ctx, base, entity);

	// Clear the handle by assigning it an empty temporary handle built at stack+80.
	uint64_t emptyHandle = (uint64_t)stack + 80;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, uint32_t(g_820F1664));
	ctx.r9.s64 = g_820F1664;  // state the callee may pass on
	EntityHandle_Release(ctx, base, emptyHandle);
	EntityHandle_Assign(ctx, base, handleAddr, emptyHandle);
	uint32_t r10Low = ctx.r10.u32;
	STORE32(stack + 80, uint32_t(g_820F1664));

	ctx.r1.u64 = stack;
	// state the callee may pass on
	uint64_t result = EntityHandle_Release(ctx, base, emptyHandle);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_82976DD8, 0x82976DD8) { ctx.r3.u64 = n_sub_82976DD8(ctx, base, ctx.r3.u64); }

void n_sub_82977100(CpuState& ctx, uint8_t* base, uint32_t electrifiedAddr) {
	if (!UseLiftedCode(68, 0x82977100)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82977100(ctx, base); return; }
	LiftedFrame frame(0x82977100);
	uint32_t stack = ctx.r1.u32;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);
	if (electrified->m_14 == 0) return;

	// r7, r8, cr0 and the carry as the original leaves them; the lookups below update them.
	uint64_t r7Value = ctx.r7.u64;
	uint32_t r8Value = 0;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	// callers read r4, r7, r8, cr0 and the carry after the call
	auto leaveRegisters = [&](uint32_t r8) {
		ctx.r4.u64 = 0;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8;
		ctx.cr0 = compare0;
		ctx.xer.ca = flags.ca;
	};

	// Value stored for a key in the entity's keyed table: the byte index table at +140, when present,
	// gives the pair directly; otherwise a lower_bound search runs over the sorted 8-byte {key, value}
	// pairs in [+72, +76), keeping its iterator in the red zone below the stack pointer (-16/-12).
	auto findKeyValue = [&](uint32_t entity, int32_t key) -> uint32_t {
		uint32_t indexTable = LOAD32(entity + 140);
		uint32_t pair = LOAD32(entity + 72);
		if (indexTable != 0)
			return LOAD32(pair + (uint32_t(LOAD8(indexTable + key)) << 3) + 4);
		uint32_t end = LOAD32(entity + 76);
		STORE32(stack - 16, 0);
		uint32_t span = end - pair;
		STORE32(stack - 12, pair);
		flags.ca = (int32_t)span < 0 & (span & 0x7) != 0;
		int32_t count = (int32_t)span >> 3;
		compare0.compare<int32_t>(count, 0, flags);
		if (count > 0) {
			flags.ca = 0;  // the halving shift only ever sees a positive count
			do {
				int32_t half = count >> 1;
				r8Value = uint32_t(half) << 3;
				pair += r8Value;
				r7Value = (int32_t)LOAD32(pair) < key;
				if (r7Value != 0) {
					count -= half + 1;
					pair += 8;
				} else {
					pair -= r8Value;
					count = half;
				}
			} while (count > 0);
			STORE32(stack - 12, pair);
		}
		if (pair != end && (int32_t)LOAD32(pair) <= key) {
			STORE64(stack - 16, LOAD64(stack - 16));
			return LOAD32(LOAD32(stack - 12) + 4);
		}
		return LOAD32(end + 4);
	};

	electrified->m_E = 0;
	electrified->m_D = 0;
	electrified->m_74 = 0;
	electrified->m_18 = 0;
	electrified->m_1C = 0;

	// The mask at +36 has a bit per key present in the table.
	uint32_t entity = electrified->m_4;
	r8Value = (LOAD32(entity + 36) >> 20) & 1;
	if (r8Value == 0) { leaveRegisters(r8Value); return; }
	uint32_t entry20 = findKeyValue(entity, 20);

	uint32_t entry20Field = LOAD32(entry20 + 148);
	electrified->m_74 = entry20Field;
	if (entry20Field == 0) { leaveRegisters(r8Value); return; }

	entity = electrified->m_4;
	if (((LOAD32(entity + 36) >> 17) & 1) == 0) { leaveRegisters(r8Value); return; }
	uint32_t entry17 = findKeyValue(entity, 17);

	if (((LOAD32(entity + 36) >> 20) & 1) == 0) { leaveRegisters(r8Value); return; }
	uint32_t entry20Again = findKeyValue(entity, 20);

	// +40 of the key-20 value is what Entity_GetHealthComponent returns.
	if ((int32_t)LOAD32(entry20Again + 40) != 7) { leaveRegisters(r8Value); return; }

	// Bytes between the words at +148 and +152 of the key-17 value, in whole 32-byte units.
	uint32_t entry17Bytes = (LOAD32(entry17 + 152) - LOAD32(entry17 + 148)) & 0xFFFFFFE0;
	if ((int32_t)entry17Bytes < 1216) { leaveRegisters(entry17Bytes); return; }

	electrified->m_74 = 0;
	leaveRegisters(entry17Bytes);
}
PROMOTED_ENTRY(68, sub_82977100, 0x82977100) { n_sub_82977100(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82977C30(CpuState& ctx, uint8_t* base, uint32_t electrifiedAddr) {
	if (!UseLiftedCode(68, 0x82977C30)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82977C30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82977C30);
	uint32_t stack = ctx.r1.u64;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	stack = PushStackFrame(base, stack, 112);

	// Virtual call (slot +64) on the object at +124 of the entity; it returns a 16-byte value
	// through the buffer passed in r3.
	uint64_t resultBuffer = (uint64_t)stack + 80;
	uint32_t object = LOAD32((uint32_t)electrified->m_4 + 124);
	uint32_t vtable = LOAD32(object);
	uint32_t method = LOAD32(vtable + 64);

	ctx.r1.u64 = stack;
	ctx.r3.u64 = resultBuffer;
	ctx.r4.u64 = object;
	ctx.r9.u64 = method;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(method);

	// Copy the returned value to +80 of this CECElectrified.
	PPCVRegister value{};
	SET_V8(value, VLOAD((uint32_t)resultBuffer & ~0xF));
	VSTORE((electrifiedAddr + 80) & ~0xF, V8(value));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r7 and r8 after the call
	ctx.r7.u64 = 80;
	ctx.r8.u64 = resultBuffer;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(68, sub_82977C30, 0x82977C30) { ctx.r3.u64 = n_sub_82977C30(ctx, base, ctx.r3.u32); }

// Adds a new n_sub_824B71D8 result to each of the first three floats copied from electrified+80 and hands
// the resulting vector to the virtual method at vtable +100 of the object whose address is at m_4 + 124.
uint32_t n_sub_82977C88(CpuState& ctx, uint8_t* base, uint32_t electrifiedAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(68, 0x82977C88)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82977C88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82977C88);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister vec = ctx.v127;
	PPCVRegister vpermMask{};
	PPCVRegister lane0Loaded{};
	PPCVRegister lane1Loaded{};
	PPCVRegister lane2Loaded{};
	PPCVRegister resultVec{};
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	// save v127 just below the incoming stack pointer, in the area the new frame covers
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(vec));
	stack = PushStackFrame(base, stack, 160);

	uint32_t result = electrifiedAddr;
	if (LOAD8(electrifiedAddr + 19) != 0) {
		// vperm masks that splice a single 32-bit lane back into the vector
		constexpr uint32_t kSpliceLane0 = 0x820991D0;
		constexpr uint32_t kSpliceLane1 = 0x820991E0;
		constexpr uint32_t kSpliceLane2 = 0x820991F0;
		const double kParam1 = double(LOAD_F32(0x821005C8u));
		const double kParam2 = double(LOAD_F32(0x83320DE4u));
		const uint32_t scalarAddr = stack + 80;
		const uint32_t vectorAddr = stack + 96;

		// the four floats held at electrified+80, copied onto the frame
		SET_V8(vec, VLOAD((electrifiedAddr + 80) & ~0xF));
		VSTORE(vectorAddr & ~0xF, V8(vec));

		ctx.r1.u64 = stack;
		double delta = n_sub_824B71D8(ctx, base, kParam1, kParam2);
		ctx.fpscr.disableFlushMode();

		// lane 0; each new lane value is stored to the scalar slot and loaded back into element 0 of a vector
		double lane0Value = double(float(delta + double(LOAD_F32(stack + 96))));
		STORE_F32(stack + 80, float(lane0Value));
		scratch.u32 = scalarAddr;
		SET_V8(lane0Loaded, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vpermMask, VLOAD(kSpliceLane0 & ~0xF));
		SET_V8(vec, rex::ppc::simde_mm_perm_epi8_(V8(vec), V8(lane0Loaded), V8(vpermMask)));
		VSTORE(vectorAddr & ~0xF, V8(vec));

		delta = n_sub_824B71D8(ctx, base, kParam1, kParam2);
		ctx.fpscr.disableFlushMode();

		// lane 1
		double lane1Source = double(LOAD_F32(stack + 100));
		double lane1Value = double(float(delta + lane1Source));
		STORE_F32(stack + 80, float(lane1Value));
		scratch.u32 = scalarAddr;
		SET_V8(lane1Loaded, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vpermMask, VLOAD(kSpliceLane1 & ~0xF));
		SET_V8(vec, rex::ppc::simde_mm_perm_epi8_(V8(vec), V8(lane1Loaded), V8(vpermMask)));
		VSTORE(vectorAddr & ~0xF, V8(vec));

		delta = n_sub_824B71D8(ctx, base, kParam1, kParam2);

		// lane 2, then hand the updated vector to the virtual method at vtable +100
		uint32_t owner = electrified->m_4;
		ctx.fpscr.disableFlushMode();
		double lane2Source = double(LOAD_F32(stack + 104));
		double lane2Value = double(float(delta + lane2Source));
		STORE_F32(stack + 80, float(lane2Value));
		uint32_t targetObject = LOAD32(owner + 124);
		scratch.u32 = scalarAddr;
		SET_V8(lane2Loaded, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(vpermMask, VLOAD(kSpliceLane2 & ~0xF));
		SET_V8(resultVec, rex::ppc::simde_mm_perm_epi8_(V8(vec), V8(lane2Loaded), V8(vpermMask)));
		uint32_t vtable = LOAD32(targetObject);
		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)LOAD32(vtable + 100);

		ctx.r3.u64 = targetObject;
		ctx.r4.u64 = vtable;
		ctx.r5.s64 = int32_t(kSpliceLane2); // sign-extended, as the original computes it here
		ctx.r6.u64 = scalarAddr;
		ctx.r7.s64 = g_820A0000;
		ctx.r8.u64 = owner;
		ctx.f1.f64 = delta;
		ctx.f9.f64 = lane2Value;
		ctx.f10.f64 = lane2Source;
		ctx.f11.f64 = lane1Value;
		ctx.f12.f64 = lane1Source;
		ctx.v1 = resultVec;
		ctx.v11 = lane2Loaded;
		ctx.v12 = lane1Loaded;
		ctx.v13 = lane0Loaded;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u32;
	}

	stack = PopStackFrame(stack, 160);
	// callers read r0 as the original leaves it: the offset of the v127 save slot
	ctx.r0.u64 = 0xFFFFFFD0;
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(68, sub_82977C88, 0x82977C88) { ctx.r3.u64 = n_sub_82977C88(ctx, base, ctx.r3.u32); }

// Runs n_sub_82977E68, then creates a new object through n_sub_824C8F70 and points the EntityHandle at
// electrified+0x88 at it, going through a temporary EntityHandle on the stack.
uint32_t n_sub_82977DB8(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(68, 0x82977DB8)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82977DB8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82977DB8);
	uint32_t stack = ctx.r1.u64;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_82977E68(ctx, base, electrifiedAddr);

	uint32_t owner = electrified->m_4;
	ctx.fpscr.disableFlushMode();
	double floatConstant = double(LOAD_F32(0x8209DE04u));

	// bump the shared counter; its new value (not wrapped to 32 bits) is passed on
	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t contextObject = LOAD32(manager + 12);
	uint32_t counterAddr = LOAD32(contextObject + 132);
	uint64_t counterValue = uint64_t(LOAD32(counterAddr)) + 1;
	STORE32(counterAddr, uint32_t(counterValue));
	// manager+12 is read again after the store, as in the original
	uint32_t container = LOAD32(LOAD32(LOAD32(LOAD32(manager + 12) + 88) + 4) + 60);

	// state the callee may pass on
	uint64_t newObject = n_sub_824C8F70(ctx, base, container, counterValue, owner, 2, 0);

	// temporary EntityHandle on the stack: {vtable, null}
	const int64_t entityHandleVtable = (int64_t)g_820F0000 + 5732;
	STORE32(stack + 80, uint32_t(entityHandleVtable));
	STORE32(stack + 84, 0);
	ctx.r8.u64 = entityHandleVtable;
	EntityHandle_SetTarget(ctx, base, uint64_t(stack + 80), newObject);

	EntityHandle_Assign(ctx, base, electrifiedAddr + 136, uint64_t(stack + 80));

	// destroy the temporary: restore its vtable, then release it
	STORE32(stack + 80, uint32_t(entityHandleVtable));
	uint32_t released = EntityHandle_Release(ctx, base, uint64_t(stack + 80));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(68, sub_82977DB8, 0x82977DB8) { ctx.r3.u64 = n_sub_82977DB8(ctx, base, ctx.r3.u64); }

// Assigns a temporary {vtable, null} EntityHandle to the handle at electrified+0x88. Before that, if the handle
// has a reference (m_8C) whose target is null the handle is released, otherwise the target gets its byte at +0xD4 set.
uint32_t n_sub_82977E68(CpuState& ctx, uint8_t* base, uint64_t electrifiedAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(68, 0x82977E68)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_82977E68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82977E68);
	uint32_t stack = ctx.r1.u64;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t handleAddr = electrifiedAddr + 136;
	uint32_t handleRef = electrified->m_8C;
	if (handleRef != 0) {
		uint32_t targetEntity = LOAD32(handleRef);
		if (targetEntity == 0) {
			ctx.r1.u64 = stack;
			ctx.r10.u64 = 0; // state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
		} else {
			STORE8(targetEntity + 0xD4, uint8_t(1));
		}
	}

	// temporary EntityHandle on the stack: {vtable, null}
	const uint64_t entityHandleVtable = g_820F1664; // sign-extended, as the original keeps it
	STORE32(stack + 84, 0);
	STORE32(stack + 80, uint32_t(entityHandleVtable));
	ctx.r1.u64 = stack;
	EntityHandle_Release(ctx, base, uint64_t(stack + 80));

	EntityHandle_Assign(ctx, base, handleAddr, uint64_t(stack + 80));

	// destroy the temporary: restore its vtable, then release it
	STORE32(stack + 80, uint32_t(entityHandleVtable));
	uint32_t released = EntityHandle_Release(ctx, base, uint64_t(stack + 80));

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(68, sub_82977E68, 0x82977E68) { ctx.r3.u64 = n_sub_82977E68(ctx, base, ctx.r3.u64); }

// With m_11 set: when the id-21 component of the owner (m_4) reports mode 45 (CECEntityModeManager_HasMode),
// calls AnimationComponent_RemoveAnimation on it for 45. Clears byte +0x72 of the owner's id-58 component if it has one.
// With m_12 set: stores the float at 0x820994C0 to m_38 and passes it, with the owner, to n_sub_827CA600.
uint32_t n_sub_829781D0(CpuState& ctx, uint8_t* base, uint32_t electrifiedAddr) {
	if (!UseLiftedCode(68, 0x829781D0)) { ctx.r3.u64 = electrifiedAddr; __imp__sub_829781D0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x829781D0);
	uint32_t stack = ctx.r1.u64;
	uint32_t result = electrifiedAddr;
	CECElectrified* electrified = GameObject<CECElectrified>(base, electrifiedAddr);

	// r6-r9, cr0 and xer.ca as the original has them: handed to the callees, read back after them and left
	// for the callers at the return. The component searches below leave their scratch values in them.
	uint64_t r6 = ctx.r6.u64;
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	uint64_t r9 = 0;
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;
	auto writeRegisters = [&] {
		ctx.r6.u64 = r6;
		ctx.r7.u64 = r7;
		ctx.r8.u64 = r8;
		ctx.r9.u64 = r9;
		ctx.cr0 = cr0;
		ctx.xer.ca = xer.ca;
	};
	auto readRegisters = [&] {
		r6 = ctx.r6.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
		cr0 = ctx.cr0;
		xer.ca = ctx.xer.ca;
	};

	stack = PushStackFrame(base, stack, 128);

	// The owner's components sit in a sorted array of 8-byte {id, component} entries at +0x48..+0x4C.
	// Binary search (lower bound) for `id`; the original keeps the range in two stack slots. When the id is
	// missing it reads the word after the end pointer.
	auto searchSorted = [&](uint32_t owner, uint32_t id) -> uint32_t {
		uint32_t begin = LOAD32(owner + 0x48);
		uint32_t end = LOAD32(owner + 0x4C);
		r6 = end;
		STORE32(stack + 80, 0);
		uint32_t byteCount = end - begin;
		STORE32(stack + 84, begin);
		xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t remaining = (int32_t)byteCount >> 3;
		cr0.compare<int32_t>(remaining, 0, xer);
		if (remaining > 0) {
			do {
				xer.ca = 0; // halving a positive count carries nothing
				int32_t half = remaining >> 1;
				uint32_t offset = (uint32_t)half << 3;
				uint32_t candidate = begin + offset;
				r9 = (uint64_t)half;
				r8 = offset;
				r7 = (int32_t)LOAD32(candidate) < (int32_t)id;
				if (r7 != 0) {
					remaining -= half + 1;
					begin = candidate + 8;
				} else {
					remaining = half;
				}
			} while (remaining > 0);
			STORE32(stack + 84, begin);
		}
		if (begin != end && (int32_t)LOAD32(begin) <= (int32_t)id) {
			STORE64(stack + 80, LOAD64(stack + 80)); // the original re-stores the range here
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	if (LOAD8(electrifiedAddr + 0x11) != 0) {
		uint32_t owner = electrified->m_4;
		// presence of id 21: bit 21 of the id bitset at +0x24
		r9 = (LOAD32(owner + 0x24) >> 21) & 1;
		if (r9 != 0) {
			uint32_t component;
			uint32_t indexTable = LOAD32(owner + 0x8C);
			if (indexTable != 0) {
				// byte table: id -> index of its entry
				uint32_t entryIndex = LOAD8(indexTable + 21);
				r9 = uint64_t(entryIndex << 3) + LOAD32(owner + 0x48);
				component = LOAD32(uint32_t(r9) + 4);
			} else {
				component = searchSorted(owner, 21);
			}
			ctx.r1.u64 = stack;
			writeRegisters();
			result = CECEntityModeManager_HasMode(ctx, base, component, 45);
			readRegisters();
			if ((result & 0xFF) != 0) {
				result = AnimationComponent_RemoveAnimation(ctx, base, component, 45);
				readRegisters();
			}
		}
	}

	uint32_t owner = electrified->m_4;
	// presence of id 58: bit 26 of the second word of the id bitset, at +0x28
	r9 = LOAD32(owner + 0x28);
	r8 = ((uint32_t)r9 >> 26) & 1;
	if (r8 != 0) {
		uint32_t component;
		uint32_t indexTable = LOAD32(owner + 0x8C);
		if (indexTable != 0) {
			r9 = LOAD8(indexTable + 58);
			r8 = uint64_t((uint32_t)r9 << 3) + LOAD32(owner + 0x48);
			component = LOAD32(uint32_t(r8) + 4);
		} else {
			component = searchSorted(owner, 58);
		}
		STORE8(component + 0x72, 0);
	}

	if (LOAD8(electrifiedAddr + 0x12) != 0) {
		owner = electrified->m_4; // read again, as the original does
		ctx.fpscr.disableFlushMode();
		double temporalExperienceAmount = double(LOAD_F32(0x820994C0u));
		electrified->m_38 = float(temporalExperienceAmount);
		ctx.r1.u64 = stack;
		writeRegisters();
		result = n_sub_827CA600(ctx, base, owner, temporalExperienceAmount);
		readRegisters();
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	writeRegisters(); // callers read r6-r9, cr0 and xer.ca after the call
	return result;
}
PROMOTED_ENTRY(68, sub_829781D0, 0x829781D0) { ctx.r3.u64 = n_sub_829781D0(ctx, base, ctx.r3.u32); }
