// CECOnFire (vtable 0x820E0340): methods of the class as readable C++.
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

uint64_t CECOnFire_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8E90_B_ = int32_t(0x820C8E90);
	if (!UseLiftedCode(61, 0x8289B3A0)) { ctx.r3.u64 = classNameString; __imp__sub_8289B3A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289B3A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C8E90_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(61, sub_8289B3A0, 0x8289B3A0) { ctx.r3.u64 = CECOnFire_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8289BB08(CpuState& ctx, uint8_t* base, uint64_t onFireAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(61, 0x8289BB08)) { ctx.r3.u64 = onFireAddr; __imp__sub_8289BB08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289BB08);
	uint32_t stack = ctx.r1.u64;
	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);

	stack = PushStackFrame(base, stack, 128);

	uint32_t entity = onFire->m_4;
	ctx.r1.u64 = stack;
	uint32_t isOnFire = Entity_IsOnFire(ctx, base, entity);

	uint32_t entity2 = onFire->m_4;
	onFire->m_66 = 0;
	ctx.fpscr.disableFlushMode();
	float fireValue = LOAD_F32(0x820994B4u);
	onFire->m_54 = fireValue;
	onFire->m_58 = fireValue;
	onFire->m_5C = fireValue;

	onFire->m_68 = (uint8_t)n_sub_824BD958(ctx, base, entity2);

	uint32_t isNotOnFire = ((isOnFire & 0xFF) == 0) ? 1u : 0u;
	onFire->m_14 = isNotOnFire;
	uint32_t counterIndex = isNotOnFire << 2;

	uint32_t gameGlobal = LOAD32(0x83496920u);
	uint32_t globalChild = LOAD32(gameGlobal + 12);
	uint32_t obj88 = LOAD32(globalChild + 88);
	uint32_t obj4 = LOAD32(obj88 + 4);
	uint32_t counterArray = LOAD32(obj4 + 56);
	STORE32(counterIndex + counterArray, LOAD32(counterIndex + counterArray) + 1);

	uint64_t result = obj4;
	uint32_t endingR4 = obj88;

	uint32_t m65 = onFire->m_65;
	uint64_t savedR5 = globalChild;
	uint64_t savedR6 = isNotOnFire;
	uint64_t savedR7 = m65;
	uint64_t savedR8 = gameGlobal;

	if (m65 != 0) {
		uint32_t handleAddr = (uint32_t)onFireAddr + 108;
		uint32_t hasTarget;
		if (LOAD32(handleAddr) != 0) {
			hasTarget = 1;
		} else {
			hasTarget = (LOAD32(handleAddr + 4) > 0) ? 1u : 0u;
		}

		if (hasTarget != 0) {
			uint32_t entityPtr = LOAD32(obj4);
			uint64_t target = n_sub_82264448(ctx, base, entityPtr, handleAddr);
			int64_t handleType = (int64_t)g_820F0000 + 5732;
			STORE32(stack + 84, 0);
			STORE32(stack + 80, (uint32_t)handleType);
			ctx.r7.u64 = (uint64_t)handleType;
			ctx.r8.s64 = g_820F0000;
			EntityHandle_SetTarget(ctx, base, stack + 80, target);

			EntityHandle_Assign(ctx, base, (uint32_t)onFireAddr + 116, stack + 80);

			STORE32(stack + 80, (uint32_t)handleType);
			ctx.r5.u64 = (uint64_t)handleType;
			ctx.r6.s64 = g_820F0000;
			result = EntityHandle_Release(ctx, base, stack + 80);

			savedR5 = ctx.r5.u64;
			savedR6 = ctx.r6.u64;
			savedR7 = ctx.r7.u64;
			savedR8 = ctx.r8.u64;
		}

		uint32_t fieldC = onFire->m_C;
		endingR4 = fieldC;
		if (fieldC <= 3) {
			ctx.r5.u64 = savedR5;
			ctx.r6.u64 = savedR6;
			ctx.r7.u64 = savedR7;
			ctx.r8.u64 = savedR8;
			result = n_sub_8289CC38(ctx, base, onFireAddr, fieldC);
			endingR4 = ctx.r4.u64;
		}
	}

	uint32_t baseEntity = onFire->m_4;
	uint32_t foundElement = 0;
	uint32_t found = 0;
	if (((LOAD32(baseEntity + 56) >> 14) & 1) != 0) {
		uint32_t indexPtr = LOAD32(baseEntity + 140);
		if (indexPtr != 0) {
			uint32_t index = LOAD8(indexPtr + 174);
			uint32_t arrayBase = LOAD32(baseEntity + 72);
			uint32_t elemAddr = (index << 3) + arrayBase;
			foundElement = LOAD32(elemAddr + 4);
			found = 1;
		} else {
			uint32_t pos = LOAD32(baseEntity + 72);
			uint32_t listEnd = LOAD32(baseEntity + 76);
			STORE32(stack + 80, 0);
			int32_t count = (int32_t)(listEnd - pos) >> 3;
			STORE32(stack + 84, pos);
			if (count > 0) {
				do {
					uint32_t half = (uint32_t)(count >> 1);
					uint32_t offset = half << 3;
					pos = pos + offset;
					if ((int32_t)LOAD32(pos) < 174) {
						count = count - (int32_t)half;
						pos = pos + 8;
						count = count - 1;
					} else {
						pos = pos - offset;
						count = (int32_t)half;
					}
				} while (count > 0);
				STORE32(stack + 84, pos);
			}
			if (pos != listEnd) {
				if ((int32_t)LOAD32(pos) > 174) {
					foundElement = LOAD32(listEnd + 4);
				} else {
					STORE64(stack + 80, LOAD64(stack + 80));
					foundElement = LOAD32(LOAD32(stack + 84) + 4);
				}
			} else {
				foundElement = LOAD32(listEnd + 4);
			}
			found = 1;
		}
	}

	if (found != 0) {
		onFire->m_67 = (uint8_t)LOAD8(foundElement + 16);
		uint32_t value = LOAD32(foundElement + 12);
		onFire->m_30 = value;
		if ((int32_t)value < 0) {
			onFire->m_30 = 0;
		} else if ((int32_t)value > 15) {
			onFire->m_30 = 15;
		}
		if (LOAD8((uint32_t)(LOAD32((uint32_t)onFireAddr + 48) << 4) + 0x8335EE60u) == 0) {
			onFire->m_30 = 0;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = endingR4;
	return result;
}
PROMOTED_ENTRY(61, sub_8289BB08, 0x8289BB08) { ctx.r3.u64 = n_sub_8289BB08(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8289BD90(CpuState& ctx, uint8_t* base, uint64_t onFireAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x8289BD90)) { ctx.r3.u64 = onFireAddr; __imp__sub_8289BD90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289BD90);
	uint32_t stack = ctx.r1.u64;
	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	n_sub_8289E4B0(ctx, base, onFireAddr);

	uint64_t lastResult = 0;
	for (uint64_t i = 0; i < 3; ++i) {
		lastResult = n_sub_8289D9D8(ctx, base, onFireAddr, i, 1);
	}

	uint32_t fireFlag = onFire->m_68;
	ctx.fpscr.disableFlushMode();
	float fireValue = LOAD_F32(0x820994B4u);
	onFire->m_54 = fireValue;
	onFire->m_58 = fireValue;
	onFire->m_5C = fireValue;

	if (fireFlag != 0) {
		uint32_t attachedEntity = onFire->m_4;
		lastResult = n_sub_824B9528(ctx, base, attachedEntity, 255, 255, 255);
	}

	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t slotArray = LOAD32(LOAD32(LOAD32(LOAD32(manager + 12) + 88) + 4) + 56);
	uint32_t slotOffset = uint32_t(onFire->m_14) << 2;
	uint32_t count = LOAD32(slotOffset + slotArray);
	if (int32_t(count) > 0) {
		count = int32_t(count) - 1;
		STORE32(slotOffset + slotArray, count);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return lastResult;
}
PROMOTED_ENTRY(61, sub_8289BD90, 0x8289BD90) { ctx.r3.u64 = n_sub_8289BD90(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8289C460(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	if (!UseLiftedCode(61, 0x8289C460)) { ctx.r3.u64 = arg1; __imp__sub_8289C460(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8289C460);
	uint32_t stack = ctx.r1.u32;
	stack = PushStackFrame(base, stack, 96);

	// Per-fire-type tunables table; each entry is 28 bytes.
	const uint32_t fireParams = uint32_t(g_83360000) - 4256;
	const uint32_t fireType = LOAD32(arg1 + 36);
	const uint32_t entry = fireType * 28;
	ctx.fpscr.disableFlushMode();
	const double heat = double(LOAD_F32(arg1 + 60));

	uint64_t r7Value = ctx.r7.u64;
	uint32_t stage = 0;
	double lastThreshold = 0.0;

	lastThreshold = double(LOAD_F32(entry + fireParams + 16));
	if (heat < lastThreshold) {
		// Below the main band: only the hottest band can ignite.
		ctx.fpscr.disableFlushMode();
		lastThreshold = double(LOAD_F32(entry + fireParams + 20));
		if (!(heat < lastThreshold) && LOAD8(arg1 + 100) != 0) {
			stage = 3;
		}
	} else if (LOAD8(arg1 + 97) != 0) {
		r7Value = LOAD8(arg1 + 98);
		stage = 2;
		if (r7Value != 0) {
			lastThreshold = double(LOAD_F32(entry + fireParams + 12));
			if (!(heat < lastThreshold)) {
				ctx.r1.u64 = stack;
				const uint32_t blocked = n_sub_824BD028(ctx, base, LOAD32(arg1 + 4));
				if ((blocked & 0xFF) == 0) {
					stage = 1;
					stack = PopStackFrame(stack, 96);
					ctx.r1.u64 = stack;
					ctx.r7.u64 = r7Value;
					ctx.f13.f64 = lastThreshold;
					return stage;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r7.u64 = r7Value;
	ctx.f13.f64 = lastThreshold;
	return stage;
}
PROMOTED_ENTRY(61, sub_8289C460, 0x8289C460) { ctx.r3.u64 = n_sub_8289C460(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8289CC38(CpuState& ctx, uint8_t* base, uint64_t onFireAddr, uint32_t arg2) {
	if (!UseLiftedCode(61, 0x8289CC38)) { ctx.r3.u64 = onFireAddr; ctx.r4.u64 = arg2; __imp__sub_8289CC38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289CC38);
	uint32_t stack = ctx.r1.u64;
	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);
	stack = PushStackFrame(base, stack, 112);

	// T131660 float table lives at 0x820994CC; the per-state byte table at 0x8335EF60.
	constexpr uint32_t kFloatTable = 0x820994CC;
	constexpr uint32_t kFloatLow   = kFloatTable - 24;    // 0x820994B4
	constexpr uint32_t kFloatHigh  = kFloatTable + 9228;  // 0x8209B8D8
	constexpr uint32_t kStateByteAddr = 0x8335EF61;       // 0x83360000 - 4256 + 1

	const uint32_t jumpEntry = LOAD32((uint32_t)(0x828A0000 - 13208) + (arg2 << 2));

	uint64_t result = 0;
	uint32_t outR4 = 0;
	uint64_t outR8 = 0;
	float value = 0.0f;

	switch (arg2) {
	case 0: {
		ctx.r0.u64 = jumpEntry;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		result = n_sub_8289E4B0(ctx, base, onFireAddr);
		outR8 = ctx.r8.u64;
		uint32_t stateWord = onFire->m_18;
		outR4 = stateWord;
		if ((int32_t)stateWord == -1) {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatLow);
		} else if ((int32_t)stateWord == -2) {
			for (uint64_t i = 0; i < 3; ++i) {
				result = n_sub_8289D9D8(ctx, base, onFireAddr, i, 0);
				outR4 = ctx.r4.u64;
				outR8 = ctx.r8.u64;
			}
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatLow);
		} else {
			result = n_sub_8289D9D8(ctx, base, onFireAddr, stateWord, 0);
			outR4 = ctx.r4.u64;
			outR8 = ctx.r8.u64;
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatLow);
		}
		break;
	}
	case 1: {
		ctx.r0.u64 = jumpEntry;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		n_sub_8289E308(ctx, base, onFireAddr);
		uint32_t stateWord = onFire->m_18;
		if ((int32_t)stateWord == -2) {
			for (uint64_t i = 0; i < 3; ++i)
				n_sub_8289D9D8(ctx, base, onFireAddr, i, 0);
		} else if ((int32_t)stateWord != -1) {
			n_sub_8289D9D8(ctx, base, onFireAddr, stateWord, 0);
		}
		n_sub_8289D2E8(ctx, base, onFireAddr, 0);
		uint32_t entity = (uint32_t)onFire->m_4;
		result = n_sub_824BB560(ctx, base, entity, ctx.r8.u64);
		outR4 = ctx.r4.u64;
		uint32_t other = (uint32_t)onFire->m_4;
		if (other != 0 && (LOAD8(other + 144) & 64) != 0) {
			n_sub_827178B8(ctx, base, other);
			n_sub_8271F038(ctx, base, other, ctx.r8.u64);
			result = n_sub_824B7D48(ctx, base, 3, other, 1, 0);
			outR4 = ctx.r4.u64;
		}
		outR8 = (uint64_t)(int64_t)(int32_t)kStateByteAddr;
		uint32_t stateId = onFire->m_24;
		if (LOAD8(stateId * 28 + kStateByteAddr) == 0) {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatHigh);
		} else {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatTable);
		}
		break;
	}
	case 2: {
		ctx.r0.u64 = jumpEntry;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		n_sub_8289E4B0(ctx, base, onFireAddr);
		uint32_t stateWord = onFire->m_18;
		if ((int32_t)stateWord == -2) {
			for (uint64_t i = 0; i < 3; ++i)
				n_sub_8289D9D8(ctx, base, onFireAddr, i, 0);
		} else if ((int32_t)stateWord != -1) {
			n_sub_8289D9D8(ctx, base, onFireAddr, stateWord, 0);
		}
		result = n_sub_8289D2E8(ctx, base, onFireAddr, 1);
		outR4 = ctx.r4.u64;
		uint32_t stateId = onFire->m_24;
		outR8 = (uint64_t)stateId * 28;
		if (LOAD8(stateId * 28 + kStateByteAddr) == 0) {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatHigh);
		} else {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatLow);
		}
		break;
	}
	case 3: {
		ctx.r0.u64 = jumpEntry;
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		n_sub_8289E4B0(ctx, base, onFireAddr);
		uint32_t stateWord = onFire->m_18;
		if ((int32_t)stateWord == -2) {
			for (uint64_t i = 0; i < 3; ++i)
				n_sub_8289D9D8(ctx, base, onFireAddr, i, 0);
		} else if ((int32_t)stateWord != -1) {
			n_sub_8289D9D8(ctx, base, onFireAddr, stateWord, 0);
		}
		result = n_sub_8289D2E8(ctx, base, onFireAddr, 2);
		outR4 = ctx.r4.u64;
		uint32_t stateId = onFire->m_24;
		outR8 = (uint64_t)stateId * 28;
		if (LOAD8(stateId * 28 + kStateByteAddr) != 0) {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatLow);
		} else {
			ctx.fpscr.disableFlushMode();
			value = LOAD_F32(kFloatHigh);
		}
		break;
	}
	default:
		__builtin_trap();
	}

	ctx.fpscr.disableFlushMode();
	onFire->m_58 = value;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = outR4;
	ctx.r8.u64 = outR8;
	return result;
}
PROMOTED_ENTRY(61, sub_8289CC38, 0x8289CC38) { ctx.r3.u64 = n_sub_8289CC38(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint32_t n_sub_8289CEE8(CpuState& ctx, uint8_t* base, uint64_t onFireAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x8289CEE8)) { ctx.r3.u64 = onFireAddr; __imp__sub_8289CEE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8289CEE8);
	PPCVRegister savedV127 = ctx.v127;
	PPCRegister callTarget{};
	PPCVRegister vecSaved = ctx.v127;
	PPCVRegister vecCopy{};
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	uint32_t stack = ctx.r1.u64;
	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);

	VSTORE((stack + 0xFFFFFFA0u) & ~0xF, V8(vecSaved));
	stack = PushStackFrame(base, stack, 256);

	uint32_t result = uint32_t(onFireAddr);
	uint32_t registry = LOAD32(uint32_t(g_83490000) + 26912);
	if (int32_t(LOAD32(LOAD32(registry + 12) + 284)) != 1) {
		int32_t burnCount = int32_t(onFire->m_20);
		if (burnCount < 4) {
			uint32_t timer = onFire->m_1C;
			flags.ca = timer > 0;
			timer = uint32_t(int32_t(timer) - 1);
			compare0.compare<int32_t>(int32_t(timer), 0, flags);
			onFire->m_1C = timer;
			if (int32_t(timer) <= 0) {
				uint64_t dataBuf = uint64_t(stack) + 144;
				uint32_t effectOwner = LOAD32(uint32_t(onFire->m_4) + 124);
				uint32_t vtable = LOAD32(effectOwner);
				uint32_t method = LOAD32(vtable + 64);
				callTarget.u64 = method;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = dataBuf;
				ctx.r4.u64 = effectOwner;
				ctx.r9.u64 = method;
				ctx.r10.u64 = vtable;
				ctx.cr0.lt = compare0.lt;
				ctx.cr0.gt = compare0.gt;
				ctx.cr0.eq = compare0.eq;
				ctx.cr0.so = compare0.so;
				ctx.xer.ca = flags.ca;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				compare0.lt = ctx.cr0.lt;
				compare0.gt = ctx.cr0.gt;
				compare0.eq = ctx.cr0.eq;
				compare0.so = ctx.cr0.so;
				flags.ca = ctx.xer.ca;

				const uint32_t floatTable = uint32_t(g_820A0000) - 27444;
				ctx.fpscr.disableFlushMode();
				double fireLevel = double(onFire->m_3C);
				uint64_t handleSource = uint64_t(onFireAddr) + 116;
				uint32_t nextCount = uint32_t((int64_t)(uint64_t)onFire->m_20 + 1);
				double scaledFire = double(float(fireLevel * double(LOAD_F32(floatTable + 208))));
				uint32_t ownerEntity = onFire->m_4;
				SET_V8(vecSaved, VLOAD(uint32_t(dataBuf) & ~0xF));
				uint32_t entity2C = onFire->m_2C;
				uint32_t entity28 = onFire->m_28;
				ctx.r8.u64 = dataBuf;
				ctx.f13.f64 = fireLevel;
				uint64_t entityHandle = EntityHandle_Get_825575C8(ctx, base, handleSource);
				SET_V8(vecCopy, V8(vecSaved));
				ctx.fpscr.disableFlushMode();
				double arg1 = double(LOAD_F32(floatTable));
				double arg2 = double(LOAD_F32(floatTable + 8644));
				double arg4 = double(LOAD_F32(floatTable + 18712));
				double arg5 = double(LOAD_F32(floatTable + 9692));
				STORE32(stack + 124, nextCount);
				double arg6 = double(LOAD_F32(floatTable - 24));
				STORE8(stack + 135, uint8_t(0));
				double arg3 = scaledFire;
				ctx.v1 = vecCopy;
				ctx.v127 = vecSaved;
				result = n_sub_8271C9D8(ctx, base, entityHandle, ownerEntity, entity28, entity2C, arg1, arg2, arg3, arg4, arg5, arg6);
				onFire->m_1C = 10u;
			}
		}
	}

	stack = PopStackFrame(stack, 256);
	SET_V8(vecSaved, VLOAD((stack + 0xFFFFFFA0u) & ~0xF));
	ctx.r0.u64 = 0xFFFFFFA0;
	ctx.r1.u64 = stack;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(61, sub_8289CEE8, 0x8289CEE8) { ctx.r3.u64 = n_sub_8289CEE8(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8289CFE0(CpuState& ctx, uint8_t* base, uint64_t onFireAddr) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t g_83360000 = int32_t(0x83360000);
	if (!UseLiftedCode(61, 0x8289CFE0)) { ctx.r3.u64 = onFireAddr; __imp__sub_8289CFE0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8289CFE0);
	uint32_t stack = ctx.r1.u64;

	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);
	uint32_t result = (uint32_t)onFireAddr;
	uint64_t reg8 = ctx.r8.u64;
	double reg1 = ctx.f1.f64;
	double reg11 = ctx.f11.f64;
	double reg12 = 0.0;
	double reg13 = ctx.f13.f64;

	stack = PushStackFrame(base, stack, 144);

	if (LOAD8((uint32_t)onFireAddr + 99) != 0) {
		uint32_t burnOwnerAddr = onFire->m_4;
		result = burnOwnerAddr;

		ctx.r1.u64 = stack;
		double burnRate = n_sub_82207928(ctx, base, burnOwnerAddr);
		reg1 = burnRate;
		reg8 = ctx.r8.u64;

		ctx.fpscr.disableFlushMode();
		double temperature = (double)onFire->m_50;
		reg12 = (double)(float)(burnRate / LOAD_F64(0x83319510u));
		double minTemperature = (double)LOAD_F32(0x820994B4u);

		bool reachedMinTemperature = false;
		if (temperature > minTemperature) {
			temperature = (double)(float)(temperature - reg12);
			onFire->m_50 = (float)temperature;
			if (!(temperature > minTemperature)) {
				onFire->m_50 = (float)minTemperature;
				reachedMinTemperature = true;
			}
		}
		reg13 = temperature;

		if (reachedMinTemperature) {
			ctx.fpscr.disableFlushMode();
			double spillRatio = (double)LOAD_F32(0x82099334u);

			uint32_t typeIndex = onFire->m_24;
			uint64_t typeTableIndex = (uint64_t)(int64_t)(g_83360000 - 4256) + 1;
			uint64_t typeEntryOffset = (uint64_t)typeIndex * 28;
			uint8_t typeBurns = LOAD8((uint32_t)typeEntryOffset + (uint32_t)typeTableIndex);
			reg8 = typeTableIndex;

			bool doSpawn = true;
			if (typeBurns != 0) {
				double burnLength = (double)onFire->m_38;
				double fallbackDivisor = (double)onFire->m_44;
				double intensity = (double)onFire->m_48;
				double divisor = (burnLength != minTemperature) ? burnLength : fallbackDivisor;
				reg11 = intensity;
				reg12 = burnLength;
				reg13 = divisor;
				ctx.fpscr.disableFlushMode();
				spillRatio = (double)(float)(intensity / divisor);
				doSpawn = spillRatio > minTemperature;
			}

			if (doSpawn) {
				uint64_t sourceHandleAddr = uint64_t(uint32_t(onFireAddr)) + 116;
				uint32_t ownerField = onFire->m_4;
				uint32_t field2C = onFire->m_2C;
				uint32_t field28 = onFire->m_28;

				ctx.r5.u64 = 1;
				ctx.r7.u64 = typeBurns;
				ctx.r8.u64 = typeTableIndex;
				ctx.r9.u64 = typeEntryOffset;
				ctx.r10.u64 = typeIndex;
				ctx.f1.f64 = burnRate;
				ctx.f11.f64 = reg11;
				ctx.f12.f64 = reg12;
				ctx.f13.f64 = reg13;

				uint64_t sourceHandle = EntityHandle_Get_825575C8(ctx, base, sourceHandleAddr);
				reg13 = ctx.f13.f64;
				ctx.fpscr.disableFlushMode();
				reg1 = spillRatio;

				STORE8(stack + 87, uint8_t(1));

				result = n_sub_824BB6C8(ctx, base, sourceHandle, ownerField, field28, 1, field2C, 4096, 0, reg1);
				reg8 = ctx.r8.u64;
				reg1 = ctx.f1.f64;
				reg13 = ctx.f13.f64;
			}

			ctx.fpscr.disableFlushMode();
			onFire->m_50 = (float)(double)LOAD_F32((uint32_t)g_820994C0);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = reg8;
	ctx.f1.f64 = reg1;
	ctx.f13.f64 = reg13;
	return result;
}
PROMOTED_ENTRY(61, sub_8289CFE0, 0x8289CFE0) { ctx.r3.u64 = n_sub_8289CFE0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8289D108(CpuState& ctx, uint8_t* base, uint64_t onFireAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_8335EF60 = int32_t(0x8335EF60);
	if (!UseLiftedCode(61, 0x8289D108)) { ctx.r3.u64 = onFireAddr; __imp__sub_8289D108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289D108);
	uint32_t stack = ctx.r1.u64;

	uint64_t local11 = ctx.r4.u64;
	uint64_t local12 = ctx.r5.u64;
	uint64_t local13 = ctx.r6.u64;
	uint64_t local14 = ctx.r7.u64;
	uint64_t local15 = ctx.r8.u64;
	uint64_t local16 = ctx.r9.u64;
	double local2 = ctx.f1.f64;

	CECOnFire* onFire = GameObject<CECOnFire>(base, onFireAddr);
	uint32_t onFireBase = static_cast<uint32_t>(onFireAddr);
	stack = PushStackFrame(base, stack, 112);

	if (LOAD8(onFireBase + 104) != 0) {
		onFireAddr = onFire->m_4;
		ctx.r1.u64 = stack;
		local2 = n_sub_82207928(ctx, base, onFireAddr);

		local15 = g_83320000;
		local14 = onFire->m_24;
		uint32_t tableBase = static_cast<uint32_t>(g_820A0000) - 17700;
		local16 = g_8335EF60;
		local13 = local14 * 28;
		ctx.fpscr.disableFlushMode();
		double deltaTime = static_cast<double>(static_cast<float>(
			local2 / LOAD_F64(static_cast<uint32_t>(g_83320000) - 27376)));
		local12 = local16 + 1;
		local11 = LOAD8(static_cast<uint32_t>(local13) + static_cast<uint32_t>(local12));
		double floorValue = static_cast<double>(LOAD_F32(tableBase - 9768));

		bool shouldUpdate = false;
		if (static_cast<uint32_t>(local11) != 0) {
			double burnValue = static_cast<double>(onFire->m_5C);
			shouldUpdate = true;
			if (burnValue > floorValue) {
				shouldUpdate = false;
				burnValue = static_cast<double>(static_cast<float>(burnValue - deltaTime));
				onFire->m_5C = static_cast<float>(burnValue);
				if (!(burnValue > floorValue))
					onFire->m_5C = static_cast<float>(floorValue);
			}
		} else {
			local15 = onFire->m_67;
			if (static_cast<uint32_t>(local15) != 0)
				shouldUpdate = true;
		}

		if (shouldUpdate) {
			ctx.fpscr.disableFlushMode();
			double target = static_cast<double>(onFire->m_58);
			double current = static_cast<double>(onFire->m_54);
			if (current != target) {
				uint64_t rowIndex = onFire->m_24;
				local15 = local16 + 1;
				local14 = 1;
				double diff = static_cast<double>(static_cast<float>(target - current));
				uint32_t rowOffset = static_cast<uint32_t>(rowIndex * 28);
				onFire->m_66 = static_cast<uint8_t>(local14);
				local13 = LOAD8(rowOffset + static_cast<uint32_t>(local15));

				double rate;
				if (static_cast<uint32_t>(local13) == 0) {
					if (!(diff > floorValue)) {
						local16 = local16 + 20;
						double scale = static_cast<double>(LOAD_F32(tableBase + 8992));
						float perRow = LOAD_F32(rowOffset + static_cast<uint32_t>(local16));
						double threshold = static_cast<double>(static_cast<float>(static_cast<double>(perRow) * scale));
						if (static_cast<double>(LOAD_F32(onFireBase + 60)) < threshold)
							rate = static_cast<double>(LOAD_F32(tableBase - 10160));
						else {
							ctx.fpscr.disableFlushMode();
							rate = floorValue;
						}
					} else {
						ctx.fpscr.disableFlushMode();
						rate = static_cast<double>(LOAD_F32(tableBase - 10152));
					}
				} else {
					ctx.fpscr.disableFlushMode();
					rate = static_cast<double>(LOAD_F32(tableBase + 8048));
				}

				ctx.fpscr.disableFlushMode();
				double step = static_cast<double>(static_cast<float>(rate * deltaTime));
				if (std::fabs(diff) > step) {
					bool lessThan = diff < floorValue;
					bool unordered = std::isnan(diff) || std::isnan(floorValue);
					local16 = lessThan ? 4 : 0;
					local15 = unordered ? 4 : 0;
					local14 = str_TXT_82100000_B_;
					local13 = local16 | local15;
					local12 = static_cast<uint64_t>(static_cast<int64_t>(local14) + 368);
					double sign = static_cast<double>(LOAD_F32(static_cast<uint32_t>(local12) + static_cast<uint32_t>(local13)));
					double signedStep = (sign >= 0.0) ? step : -step;
					onFire->m_54 = static_cast<float>(signedStep + current);
				} else {
					ctx.fpscr.disableFlushMode();
					onFire->m_54 = static_cast<float>(target);
				}
			}
		}

		if (LOAD8(onFireBase + 102) != 0) {
			ctx.fpscr.disableFlushMode();
			double fromField = static_cast<double>(LOAD_F32(tableBase - 9756));
			double curFade = static_cast<double>(onFire->m_54);
			double t1 = static_cast<double>(static_cast<float>(fromField - curFade));
			double scale2 = static_cast<double>(LOAD_F32(tableBase));
			onFire->m_66 = static_cast<uint8_t>(0);
			double conv = static_cast<double>(static_cast<float>(t1 * scale2));

			int64_t storedValue;
			if (std::isnan(conv))
				storedValue = static_cast<int64_t>(0x80000000ULL);
			else if (conv > 2147483647.0)
				storedValue = 2147483647;
			else if (conv < -2147483648.0)
				storedValue = static_cast<int64_t>(static_cast<int32_t>(0x80000000u));
			else
				storedValue = static_cast<int64_t>(static_cast<int32_t>(conv));

			STORE64(stack + 80, static_cast<uint64_t>(storedValue));
			uint32_t frames = LOAD32(stack + 84);
			if (static_cast<int32_t>(frames) < 1)
				frames = 1;

			uint32_t fireObj = static_cast<uint32_t>(onFire->m_4);
			ctx.r7.u64 = 0;
			ctx.r8.u64 = local15;
			ctx.r9.u64 = local16;
			ctx.f1.f64 = local2;
			onFireAddr = n_sub_824B9528(ctx, base, fireObj, static_cast<uint64_t>(frames),
				static_cast<uint64_t>(frames), frames);
			local11 = ctx.r4.u64;
			local12 = ctx.r5.u64;
			local13 = ctx.r6.u64;
			local14 = ctx.r7.u64;
			local15 = ctx.r8.u64;
			local16 = ctx.r9.u64;
			local2 = ctx.f1.f64;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = local11;
	ctx.r5.u64 = local12;
	ctx.r6.u64 = local13;
	ctx.r7.u64 = local14;
	ctx.r8.u64 = local15;
	ctx.r9.u64 = local16;
	ctx.f1.f64 = local2;
	return onFireAddr;
}
PROMOTED_ENTRY(61, sub_8289D108, 0x8289D108) { ctx.r3.u64 = n_sub_8289D108(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8289D9D8(CpuState& ctx, uint8_t* base, uint64_t table, uint64_t slotIndex, uint64_t instant) {
	if (!UseLiftedCode(61, 0x8289D9D8)) { ctx.r3.u64 = table; ctx.r4.u64 = slotIndex; ctx.r5.u64 = instant; __imp__sub_8289D9D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289D9D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	constexpr uint32_t kNullHandle = 0x820F1664;      // 0x820F0000 + 5732
	constexpr uint32_t kGlobalBase = 0x820F0000;
	constexpr uint32_t kFadeConsts = 0x820994B4;      // 0x820A0000 - 27468

	// Values the original keeps live in r6..r10 across the calls below.
	uint64_t r6v = ctx.r6.u64;
	uint64_t r7v = ctx.r7.u64;
	uint64_t r8v = ctx.r8.u64;
	uint64_t r9v = ctx.r9.u64;
	uint32_t r10v = 0;

	// Each slot is 8 bytes: entity handle at +0x7C, particle emitter pointer at +0x80.
	const uint32_t slotIndex32 = (uint32_t)slotIndex;
	const uint32_t slotAddr = (slotIndex32 << 3) + (uint32_t)table;
	const uint32_t handleAddr = slotAddr + 124;
	const uint32_t emitter = LOAD32(slotAddr + 128);

	uint64_t result = table;

	if (emitter != 0) {
		const uint32_t emitterFlags = LOAD32(emitter);

		if (emitterFlags == 0) {
			ctx.r1.u64 = stack;
			ctx.r4.u64 = slotIndex;
			ctx.r5.u64 = instant;
			ctx.r10.u64 = emitterFlags;
			result = EntityHandle_Release(ctx, base, handleAddr);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return result;
		}

		ctx.r1.u64 = stack;
		ctx.r4.u64 = slotIndex;
		ctx.r5.u64 = instant;
		ctx.r10.u64 = emitterFlags;
		result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		r6v = ctx.r6.u64;
		r7v = ctx.r7.u64;
		r8v = ctx.r8.u64;
		r9v = ctx.r9.u64;
		const uint32_t entity = (uint32_t)result;

		uint32_t particleId = 0;
		bool hasParticle = false;

		r10v = (LOAD32(entity + 44) >> 21) & 1;
		if (r10v != 0) {
			const uint32_t particleTable = LOAD32(entity + 140);
			if (particleTable != 0) {
				r10v = (uint32_t)LOAD8(particleTable + 85) << 3;
				r9v = r10v + LOAD32(entity + 72);
				particleId = LOAD32((uint32_t)r9v + 4);
				hasParticle = true;
			} else {
				// Binary search for key 85 in the sorted (key, particle id) records.
				const uint32_t begin = LOAD32(entity + 72);
				const uint32_t end = LOAD32(entity + 76);
				r6v = end;
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				uint32_t found = begin;
				int32_t remaining = (int32_t)(end - begin) >> 3;
				if (remaining > 0) {
					do {
						const int32_t half = remaining >> 1;
						r9v = (uint64_t)(int64_t)half;
						r8v = (uint32_t)half << 3;
						const uint32_t mid = found + (uint32_t)r8v;
						r7v = (int32_t)LOAD32(mid) < 85 ? 1 : 0;
						if (r7v != 0) {
							found = mid + 8;
							remaining = remaining - half - 1;
						} else {
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 84, found);
				}
				r10v = found;
				if (found != end && (int32_t)LOAD32(found) <= 85) {
					particleId = LOAD32(found + 4);
				} else {
					particleId = LOAD32(end + 4);
				}
				hasParticle = true;
			}
		}

		if (hasParticle) {
			const bool instantKill = ((uint32_t)instant & 0xFF) != 0;
			double fadeOutTime;
			if (!instantKill) {
				ctx.fpscr.disableFlushMode();
				fadeOutTime = (double)LOAD_F32(kFadeConsts + 0x2018);
				if (slotIndex32 < 2) {
					fadeOutTime = (double)LOAD_F32(kFadeConsts + 0x240C);
				}
			} else {
				ctx.fpscr.disableFlushMode();
				fadeOutTime = (double)LOAD_F32(kFadeConsts);
			}
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6v;
			ctx.r7.u64 = r7v;
			ctx.r8.u64 = r8v;
			ctx.r9.u64 = r9v;
			ctx.r10.u64 = r10v;
			result = n_sub_8247EB68(ctx, base, particleId, fadeOutTime);  // Lua_ParticleEmitter_KillParticleWithFadeOut
			if (!instantKill) {
				stack = PopStackFrame(stack, 144);
				ctx.r1.u64 = stack;
				return result;
			}
		}

		// Destroy the emitter entity and reset the slot's handle to the null handle.
		ctx.r1.u64 = stack;
		const uint64_t entityToDestroy = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		Entity_DestroyImpl(ctx, base, entityToDestroy);

		const uint32_t tempHandle = stack + 80;
		STORE32(stack + 84, 0);
		STORE32(tempHandle, kNullHandle);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = kNullHandle;
		EntityHandle_Release(ctx, base, tempHandle);

		ctx.r1.u64 = stack;
		EntityHandle_Assign(ctx, base, handleAddr, tempHandle);

		STORE32(tempHandle, kNullHandle);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = kNullHandle;
		ctx.r9.u64 = kGlobalBase;
		result = EntityHandle_Release(ctx, base, tempHandle);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_8289D9D8, 0x8289D9D8) { ctx.r3.u64 = n_sub_8289D9D8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t n_sub_8289E308(CpuState& ctx, uint8_t* base, uint32_t arg1) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x8289E308)) { ctx.r3.u64 = arg1; __imp__sub_8289E308(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8289E308);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 112);

	uint32_t globalTable = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t settings = LOAD32(LOAD32(globalTable + 12) + 140);

	bool enabled = LOAD8(settings + 0x34) != 0 && LOAD8(settings + 0x35) != 0;

	if (enabled && LOAD8(arg1 + 0x62) != 0) {
		uint32_t entity = LOAD32(arg1 + 4);
		if ((LOAD32(entity + 36) >> 21) & 1) {
			uint32_t target;
			uint32_t indexTable = LOAD32(entity + 140);
			if (indexTable != 0) {
				uint32_t index = LOAD8(indexTable + 21);
				uint32_t itemAddr = (index << 3) + LOAD32(entity + 72);
				target = LOAD32(itemAddr + 4);
			} else {
				uint32_t begin = LOAD32(entity + 72);
				uint32_t end = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				int32_t count = (int32_t)(end - begin) >> 3;
				if (count > 0) {
					while (count > 0) {
						int32_t mid = count >> 1;
						uint32_t pos = begin + (uint32_t)mid * 8;
						if ((int32_t)LOAD32(pos) < 21) {
							begin = pos + 8;
							count = count - mid - 1;
						} else {
							count = mid;
						}
					}
					STORE32(stack + 84, begin);
				}
				if (begin != end && (int32_t)LOAD32(begin) <= 21) {
					STORE64(stack + 80, LOAD64(stack + 80));
					target = LOAD32(begin + 4);
				} else {
					target = LOAD32(end + 4);
				}
			}
			ctx.r1.u64 = stack;
			arg1 = CECEntityModeManager_HasMode(ctx, base, target, 46);
			if ((arg1 & 0xFF) == 0) {
				arg1 = n_sub_823F1EB0(ctx, base, target, 46);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(61, sub_8289E308, 0x8289E308) { ctx.r3.u64 = n_sub_8289E308(ctx, base, ctx.r3.u32); }

uint64_t n_sub_8289E4B0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr uint32_t g_83490000 = 0x83490000;
	if (!UseLiftedCode(61, 0x8289E4B0)) { ctx.r3.u64 = arg1; __imp__sub_8289E4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8289E4B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t entityModeManager = LOAD32(LOAD32(g_83490000 + 26912) + 12);
	uint32_t modeState = LOAD32(entityModeManager + 140);
	bool shouldCheck = LOAD8(modeState + 52) != 0 && LOAD8(modeState + 53) != 0;

	uint32_t animId = 0;
	bool hasAnimId = false;

	if (shouldCheck) {
		uint32_t entity = LOAD32((uint32_t)arg1 + 4);
		if ((LOAD32(entity + 36) >> 21) & 1) {
			uint32_t animComponent = LOAD32(entity + 140);
			if (animComponent != 0) {
				uint32_t index = LOAD8(animComponent + 21);
				animId = LOAD32(LOAD32(entity + 72) + index * 8 + 4);
				hasAnimId = true;
			} else {
				uint32_t begin = LOAD32(entity + 72);
				uint32_t end = LOAD32(entity + 76);
				uint32_t pos = begin;
				int32_t remaining = (int32_t)(end - begin) >> 3;

				STORE32(stack + 80, 0);
				STORE32(stack + 84, pos);

				// lower-bound search for the first entry whose key is >= 21
				while (remaining > 0) {
					int32_t half = remaining >> 1;
					uint32_t mid = pos + (uint32_t)half * 8;
					if ((int32_t)LOAD32(mid) < 21) {
						pos = mid + 8;
						remaining = remaining - half - 1;
					} else {
						remaining = half;
					}
				}
				STORE32(stack + 84, pos);

				if (pos != end && (int32_t)LOAD32(pos) <= 21) {
					STORE64(stack + 80, LOAD64(stack + 80));
					animId = LOAD32(pos + 4);
				} else {
					animId = LOAD32(end + 4);
				}
				hasAnimId = true;
			}
		}
	}

	if (!hasAnimId) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return arg1;
	}

	ctx.r1.u64 = stack;
	uint64_t result = CECEntityModeManager_HasMode(ctx, base, animId, 46);
	if (((uint32_t)result & 0xFF) != 0) {
		ctx.r1.u64 = stack;
		result = AnimationComponent_RemoveAnimation(ctx, base, animId, 46);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_8289E4B0, 0x8289E4B0) { ctx.r3.u64 = n_sub_8289E4B0(ctx, base, ctx.r3.u64); }
