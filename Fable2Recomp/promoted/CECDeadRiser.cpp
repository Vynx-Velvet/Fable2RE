// CECDeadRiser (vtable 0x820E0098): methods of the class as readable C++.
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

uint64_t CECDeadRiser_GetClassName(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(61, 0x828987E0)) { ctx.r3.u64 = arg1; __imp__sub_828987E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828987E0);

	constexpr int32_t classNameCStr = int32_t(0x820C8E80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint64_t classNameAddress = static_cast<uint64_t>(static_cast<int64_t>(classNameCStr));
	int32_t length = -1;

	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, arg1, classNameAddress, length);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(61, sub_828987E0, 0x828987E0) { ctx.r3.u64 = CECDeadRiser_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECDeadRiser_Destructor(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(61, 0x82898820)) { ctx.r3.u64 = deadRiserAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82898820(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82898820);
	uint32_t stack = ctx.r1.u64;
	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);

	stack = PushStackFrame(base, stack, 112);
	deadRiser->m_3C = 0x820F1664u;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	ctx.r10.u64 = 0x820F1664u;
	EntityHandle_Release(ctx, base, deadRiserAddr + 60);
	deadRiser->m_40 = 0u;
	deadRiser->vtable = 0x820A8D10u;
	if ((uint32_t(deleteFlags) & 1u) != 0) {
		HandleTarget_Free(ctx, base, deadRiserAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return deadRiserAddr;
}
PROMOTED_ENTRY(61, sub_82898820, 0x82898820) { ctx.r3.u64 = CECDeadRiser_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82898898(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr) {
	if (!UseLiftedCode(61, 0x82898898)) { ctx.r3.u64 = deadRiserAddr; __imp__sub_82898898(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82898898);
	uint32_t stack = ctx.r1.u64;
	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82392C88(ctx, base, deadRiser->m_4, deadRiserAddr);
	ctx.fpscr.disableFlushMode();
	float spawnDelay = LOAD_F32(0x820994B4u);
	float spawnDelay2 = LOAD_F32(0x8209F48Cu);
	float spawnDelay3 = LOAD_F32(0x83496B8Cu);
	deadRiser->m_CurrState = 1;
	deadRiser->m_18 = spawnDelay;
	deadRiser->m_11 = 1;
	deadRiser->m_1C = spawnDelay2;
	deadRiser->m_20 = spawnDelay3;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_82898898, 0x82898898) { ctx.r3.u64 = n_sub_82898898(ctx, base, ctx.r3.u64); }

uint64_t CECDeadRiser_SerializeProperties(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr, uint64_t serializer, uint64_t arg3) {
	if (!UseLiftedCode(61, 0x82898900)) { ctx.r3.u64 = deadRiserAddr; ctx.r4.u64 = serializer; ctx.r6.u64 = arg3; __imp__sub_82898900(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82898900);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);

	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820CEF4C_B_ = int32_t(0x820CEF4C);
	constexpr int32_t str_TXT_820D0A08_B_ = int32_t(0x820D0A08);
	constexpr int32_t str_TXT_820DFD40_B_ = int32_t(0x820DFD40);
	constexpr int32_t str_TXT_820DFFEC_B_ = int32_t(0x820DFFEC);
	constexpr int32_t str_TXT_820DFFF8_B_ = int32_t(0x820DFFF8);
	constexpr int32_t str_TXT_820E0004_B_ = int32_t(0x820E0004);
	constexpr int32_t str_TXT_820E0010_B_ = int32_t(0x820E0010);
	constexpr int32_t str_TXT_820E001C_B_ = int32_t(0x820E001C);
	constexpr int32_t str_TXT_820E0028_B_ = int32_t(0x820E0028);
	constexpr int32_t str_TXT_820E0034_B_ = int32_t(0x820E0034);
	constexpr int32_t str_TXT_820E004C_B_ = int32_t(0x820E004C);

	const uint64_t emptyStringData = g_8209003F;

	// TXT_820DFFEC_B_ is serialized through a temporary because the serializer may update it.
	STORE32(stack + 84, uint32_t(deadRiser->m_CurrState));
	ctx.r1.u64 = stack;
	ctx.r6.u64 = arg3;
	CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint64_t)(int64_t)str_TXT_820DFFEC_B_, -1);
	uint32_t currStateNameObj = LOAD32(stack + 80);
	uint64_t currStateName = emptyStringData;
	if (currStateNameObj != 0) currStateName = LOAD32(currStateNameObj);
	ctx.r4.u64 = currStateName;
	IStream_SerializeU32(ctx, base, serializer, stack + 84);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	deadRiser->m_CurrState = LOAD32(stack + 84);

	auto serializeFloat = [&](int32_t nameAddr, uint64_t valueAddr) {
		CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint64_t)(int64_t)nameAddr, -1);
		uint32_t nameObj = LOAD32(stack + 80);
		uint64_t name = emptyStringData;
		if (nameObj != 0) name = LOAD32(nameObj);
		ctx.r4.u64 = name;
		IStream_SerializeFloat(ctx, base, serializer, valueAddr);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	};
	serializeFloat(str_TXT_820DFFF8_B_, deadRiserAddr + 28);
	serializeFloat(str_TXT_820E0004_B_, deadRiserAddr + 32);
	serializeFloat(str_TXT_820E0010_B_, deadRiserAddr + 36);
	serializeFloat(str_TXT_820CEF4C_B_, deadRiserAddr + 40);
	serializeFloat(str_TXT_820E001C_B_, deadRiserAddr + 24);
	serializeFloat(str_TXT_820DFD40_B_, deadRiserAddr + 20);

	auto serializeU32 = [&](int32_t nameAddr, uint64_t valueAddr) {
		CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint64_t)(int64_t)nameAddr, -1);
		uint32_t nameObj = LOAD32(stack + 80);
		uint64_t name = emptyStringData;
		if (nameObj != 0) name = LOAD32(nameObj);
		ctx.r4.u64 = name;
		IStream_SerializeU32(ctx, base, serializer, valueAddr);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	};
	serializeU32(str_TXT_820E0028_B_, deadRiserAddr + 48);

	auto serializeString = [&](int32_t nameAddr, uint64_t valueAddr) {
		CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint64_t)(int64_t)nameAddr, -1);
		IStream_SerializeString(ctx, base, stack + 80, serializer, valueAddr);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	};
	serializeString(str_TXT_820E0034_B_, deadRiserAddr + 16);
	serializeString(str_TXT_820E004C_B_, deadRiserAddr + 17);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, (uint64_t)(int64_t)str_TXT_820D0A08_B_, -1);
	n_sub_8244DAE0(ctx, base, deadRiserAddr + 52, stack + 80, serializer);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	uint32_t lowByte = (uint32_t)(arg3 & 0xFF);
	uint32_t clz = (lowByte == 0) ? 32u : (uint32_t)__builtin_clz(lowByte);
	deadRiser->m_12 = (uint8_t)((clz >> 5) & 1);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_82898900, 0x82898900) { ctx.r3.u64 = CECDeadRiser_SerializeProperties(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint64_t n_sub_82898BB0(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x82898BB0)) { ctx.r3.u64 = deadRiserAddr; __imp__sub_82898BB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82898BB0);
	uint32_t stack = ctx.r1.u64;
	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.fpscr.disableFlushMode();
	const double radius = double(deadRiser->m_20);
	ctx.f2.f64 = double(deadRiser->m_1C);
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_8289A398(ctx, base, deadRiserAddr, radius);
	uint64_t arg4 = ctx.r4.u64;

	if (LOAD8((uint32_t)deadRiserAddr + 18) != 0) {
		deadRiser->m_12 = 0;
		const uint32_t targetRangeAddr = (uint32_t)deadRiserAddr + 52;
		arg4 = deadRiserAddr + 52;
		const bool hasTargetSlots = LOAD32(targetRangeAddr) != 0 || LOAD32(targetRangeAddr + 4) != 0;
		if (hasTargetSlots) {
			const uint32_t manager = LOAD32((uint32_t)g_83490000 + 26912);
			const uint32_t entityList = LOAD32(LOAD32(LOAD32(manager + 12) + 88) + 4);
			ctx.r8.u64 = entityList;
			const uint64_t entity = n_sub_82264448(ctx, base, LOAD32(entityList), arg4);

			const uint32_t handleAddr = stack + 80;
			const uint64_t handleVtable = (int64_t)g_820F0000 + 5732;
			STORE32(handleAddr + 4, 0);
			STORE32(handleAddr, (uint32_t)handleVtable);
			ctx.r6.u64 = handleVtable;
			ctx.r7.s64 = g_820F0000;
			EntityHandle_SetTarget(ctx, base, handleAddr, entity);
			EntityHandle_Assign(ctx, base, (uint32_t)deadRiserAddr + 60, handleAddr);
			STORE32(handleAddr, (uint32_t)handleVtable);
			ctx.r4.u64 = handleVtable;
			ctx.r5.s64 = g_820F0000;
			result = EntityHandle_Release(ctx, base, handleAddr);
			arg4 = ctx.r4.u64;
		}
		if (LOAD8((uint32_t)deadRiserAddr + 16) != 0) {
			ctx.r4.u64 = arg4;
			result = EntityHandle_Get_825575C8(ctx, base, (uint32_t)deadRiserAddr + 60);
			arg4 = ctx.r4.u64;
			if ((uint32_t)result != 0) {
				result = n_sub_828993F0(ctx, base, deadRiserAddr);
				arg4 = ctx.r4.u64;
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg4;
	return result;
}
PROMOTED_ENTRY(61, sub_82898BB0, 0x82898BB0) { ctx.r3.u64 = n_sub_82898BB0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82898CB0(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr) {
	if (!UseLiftedCode(61, 0x82898CB0)) { ctx.r3.u64 = deadRiserAddr; __imp__sub_82898CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82898CB0);
	uint32_t stack = ctx.r1.u64;
	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);
	stack = PushStackFrame(base, stack, 96);
	if (deadRiser->m_10 != 0) {
		ctx.r1.u64 = stack;
		deadRiserAddr = n_sub_82899C08(ctx, base, deadRiserAddr);
		deadRiser->m_10 = uint8_t(0);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return deadRiserAddr;
}
PROMOTED_ENTRY(61, sub_82898CB0, 0x82898CB0) { ctx.r3.u64 = n_sub_82898CB0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82899DC0(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(61, 0x82899DC0)) { ctx.r3.u64 = deadRiserAddr; ctx.r4.u64 = arg2; __imp__sub_82899DC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82899DC0);
	uint32_t stack = ctx.r1.u64;
	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);
	uint64_t handleAddr = deadRiserAddr + 0x3C;

	stack = PushStackFrame(base, stack, 128);

	// The dead riser embeds an entity handle at +0x3C; m_40 points at the controlled
	// object whose first field is the entity. Fall back to releasing the handle.
	auto handleEntity = [&](bool firstCall) -> uint64_t {
		uint32_t handlePtr = deadRiser->m_40;
		if (handlePtr != 0) {
			uint64_t entity = LOAD32(handlePtr);
			if (entity != 0)
				return entity;
			if (firstCall) {
				ctx.r1.u64 = stack;
				ctx.r4.u64 = arg2;
			}
			ctx.r10.u64 = 0;
			EntityHandle_Release(ctx, base, handleAddr);
		}
		return 0;
	};

	uint64_t entity = handleEntity(true);
	ctx.r1.u64 = stack;
	n_sub_824B9E80(ctx, base, deadRiser->m_4, entity, arg2);

	uint32_t isHero = Entity_IsHeroEntity(ctx, base, handleEntity(false)) & 0xFF;
	uint64_t isLocalPlayer = SpellManager_IsLocalPlayerEntity(ctx, base, handleEntity(false));

	if (isHero == 0 && (isLocalPlayer & 0xFF) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return isLocalPlayer;
	}

	// Resolve the responsible entity: the owning spell shot for a hero, otherwise
	// the entity handle reachable from the active object.
	uint32_t gameGlobal   = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t manager      = LOAD32(gameGlobal + 12);
	uint32_t activeObj    = LOAD32(manager + 88);
	uint32_t ownerSlot    = LOAD32(activeObj + 4);
	uint32_t sourceEntity = LOAD32(ownerSlot);

	ctx.r1.u64 = stack;
	ctx.r8.u64 = ownerSlot;
	ctx.r9.u64 = activeObj;

	uint64_t owner = (isHero != 0)
		? SpellShot_GetOwner(ctx, base, sourceEntity)
		: EntityHandle_Get(ctx, base, sourceEntity);

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_824B9E80(ctx, base, deadRiser->m_4, owner, arg2);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_82899DC0, 0x82899DC0) { ctx.r3.u64 = n_sub_82899DC0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_8289A2C0(CpuState& ctx, uint8_t* base, uint64_t deadRiserAddr, double floatArg1) {
	if (!UseLiftedCode(61, 0x8289A2C0)) { ctx.r3.u64 = deadRiserAddr; ctx.f1.f64 = floatArg1; __imp__sub_8289A2C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8289A2C0);

	CECDeadRiser* deadRiser = GameObject<CECDeadRiser>(base, deadRiserAddr);

	ctx.fpscr.disableFlushMode();

	const float speedDivisor = LOAD_F32(0x83318EA8u);
	const float yawRateBase = LOAD_F32(0x820994C0u);
	const float yawRateOffset = LOAD_F32(0x83496B8Cu);
	const float pitchRateBase = LOAD_F32(0x8209B710u);

	float oldYaw = deadRiser->m_20;
	float targetYaw = deadRiser->m_28;
	float oldPitch = deadRiser->m_1C;
	float targetPitch = deadRiser->m_24;

	// Values carried in volatile registers across the call.
	double regF4 = ctx.f4.f64;
	PPCRegister regF5 = ctx.f5;
	double regF6 = ctx.f6.f64;
	PPCRegister regF7 = ctx.f7;
	double regF8 = (double)oldYaw;
	double regF9 = (double)oldPitch;
	PPCRegister regF10;
	regF10.f64 = (double)speedDivisor;
	double regF11 = ctx.f11.f64;
	PPCRegister regF12 = ctx.f12;
	double regF13 = (double)targetPitch;

	if (oldYaw != targetYaw) {
		float rateDiff = yawRateBase - yawRateOffset;
		float stepBase = (float)((double)rateDiff / (double)speedDivisor);
		float yawDelta = targetYaw - oldYaw;
		float absYawDelta = fabsf(yawDelta);
		float yawStep = (float)((double)stepBase * floatArg1);

		regF4 = (double)stepBase;
		regF5.f64 = (double)absYawDelta;
		regF6 = (double)rateDiff;
		regF7.f64 = (double)yawDelta;
		regF11 = (double)yawRateOffset;
		regF12.f64 = (double)yawStep;

		if (absYawDelta > yawStep) {
			if (!(targetYaw > oldYaw)) {
				yawStep = -yawStep;
			}
			ctx.fpscr.disableFlushMode();
			deadRiser->m_20 = (float)((double)oldYaw + (double)yawStep);
		} else {
			ctx.fpscr.disableFlushMode();
			deadRiser->m_20 = targetYaw;
		}
	}

	ctx.fpscr.disableFlushMode();

	if (oldPitch != targetPitch) {
		float stepBasePitch = (float)((double)pitchRateBase / (double)speedDivisor);
		float pitchDelta = targetPitch - oldPitch;
		float absPitchDelta = fabsf(pitchDelta);
		float pitchStep = (float)((double)stepBasePitch * floatArg1);

		regF11 = (double)stepBasePitch;
		regF10.f64 = (double)absPitchDelta;
		regF12.f64 = (double)pitchDelta;

		if (absPitchDelta > pitchStep) {
			if (!(targetPitch > oldPitch)) {
				pitchStep = -pitchStep;
			}
			ctx.fpscr.disableFlushMode();
			deadRiser->m_1C = (float)((double)oldPitch + (double)pitchStep);
		} else {
			ctx.fpscr.disableFlushMode();
			deadRiser->m_1C = targetPitch;
		}
	}

	ctx.fpscr.disableFlushMode();

	float currentYaw = deadRiser->m_20;
	float currentPitch = deadRiser->m_1C;

	if (currentYaw == oldYaw && currentPitch == oldPitch) {
		ctx.f1.f64 = (double)currentYaw;
		ctx.f4.f64 = regF4;
		ctx.f5 = regF5;
		ctx.f6.f64 = regF6;
		ctx.f7 = regF7;
		ctx.f8.f64 = regF8;
		ctx.f9.f64 = regF9;
		ctx.f10 = regF10;
		ctx.f11.f64 = regF11;
		ctx.f12 = regF12;
		ctx.f13.f64 = regF13;
		return (uint32_t)deadRiserAddr;
	}

	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = (double)currentPitch;
	ctx.f4.f64 = regF4;
	ctx.f5 = regF5;
	ctx.f6.f64 = regF6;
	ctx.f7 = regF7;
	ctx.f8.f64 = regF8;
	ctx.f9.f64 = regF9;
	ctx.f10 = regF10;
	ctx.f11.f64 = regF11;
	ctx.f12 = regF12;
	ctx.f13.f64 = regF13;

	return n_sub_8289A398(ctx, base, deadRiserAddr, (double)currentYaw);
}
PROMOTED_ENTRY(61, sub_8289A2C0, 0x8289A2C0) { ctx.r3.u64 = n_sub_8289A2C0(ctx, base, ctx.r3.u64, ctx.f1.f64); }
