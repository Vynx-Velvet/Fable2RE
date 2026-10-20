// CECPlayerSpellManager (vtable 0x820043A0): methods of the class as readable C++.
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

uint32_t CECPlayerSpellManager_UpdateNetworked(CpuState& ctx, uint8_t* base, uint32_t playerSpellManagerAddr) {
	if (!UseLiftedCode(13, 0x822D2EE0)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_822D2EE0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822D2EE0);
	uint32_t stack = ctx.r1.u32;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t returnValue = Entity_IsNetworked(ctx, base, playerSpellManager->m_owner);

	if ((returnValue & 0xFF) != 0) {
		uint32_t spellHost = playerSpellManager->m_10;
		if (LOAD8(spellHost + 611) != 0) {
			uint32_t currentSpell = playerSpellManager->m_currentSpell;
			if (LOAD32(spellHost + 116) != currentSpell) {
				playerSpellManager->m_dirty = 1;
			}

			if (playerSpellManager->m_dirty != 0) {
				constexpr uint32_t g_820A0000 = 0x820A0000u;
				constexpr uint32_t g_82100170 = 0x82100170u;
				uint32_t constantBase = g_820A0000 - 40;

				ctx.fpscr.disableFlushMode();
				double maxCharge = double(LOAD_F32(constantBase - 27416));
				double minCharge = double(LOAD_F32(constantBase - 27428));

				double chargeTarget;
				double chargeRate;
				if (currentSpell == 0) {
					chargeTarget = minCharge;
					chargeRate = double(LOAD_F32(0x82000BE4u));
				} else {
					ctx.fpscr.disableFlushMode();
					chargeRate = double(LOAD_F32(constantBase - 17712));
					chargeTarget = maxCharge;
				}

				ctx.fpscr.disableFlushMode();
				double chargeB = double(playerSpellManager->m_chargeB);
				double chargeA = double(playerSpellManager->m_chargeA);

				bool chargeBBelowMin = chargeB < minCharge;
				bool chargeBUnordered = std::isnan(chargeB) || std::isnan(minCharge);
				uint32_t tableIndex = (chargeBBelowMin || chargeBUnordered) ? 4u : 0u;

				double chargeDiff = double(float(chargeTarget - chargeA));

				uint32_t tableBase = g_82100170;
				returnValue = tableBase;
				double floorConst = double(LOAD_F32(constantBase - 8660));
				float tableValue = LOAD_F32(tableBase + tableIndex);
				double tableChoice = (double(tableValue) >= 0.0) ? maxCharge : floorConst;
				double diffChoice = (chargeDiff > minCharge) ? maxCharge : floorConst;
				ctx.fpscr.disableFlushMode();
				if (diffChoice != tableChoice) {
					double factor = double(LOAD_F32(constantBase - 27812));
					playerSpellManager->m_chargeB = float(-std::fma(chargeB, factor, -chargeB));
				}

				ctx.fpscr.disableFlushMode();
				double timeDelta = LOAD_F64(constantBase);
				double divisor = LOAD_F64(0x83319510u);
				double incrementF = double(float(timeDelta / divisor));

				double chargeBCurrent = double(playerSpellManager->m_chargeB);
				double newChargeB = double(float(std::fma(incrementF, chargeRate, chargeBCurrent)));
				playerSpellManager->m_chargeB = float(newChargeB);

				double newChargeA = double(float(std::fma(newChargeB, incrementF, chargeA)));
				playerSpellManager->m_chargeA = float(newChargeA);

				if (!(newChargeA < maxCharge)) {
					playerSpellManager->m_chargeA = float(maxCharge);
					ctx.fpscr.disableFlushMode();
					playerSpellManager->m_chargeB = float(minCharge);
				} else {
					ctx.fpscr.disableFlushMode();
					if (!(newChargeA > minCharge)) {
						playerSpellManager->m_chargeA = float(minCharge);
						ctx.fpscr.disableFlushMode();
						playerSpellManager->m_chargeB = float(minCharge);
					}
				}

				ctx.fpscr.disableFlushMode();
				double finalChargeA = double(playerSpellManager->m_chargeA);
				bool shouldSetSpell;
				if (currentSpell == 0) {
					shouldSetSpell = !(finalChargeA > chargeTarget);
				} else {
					ctx.fpscr.disableFlushMode();
					shouldSetSpell = !(finalChargeA < chargeTarget);
				}
				if (shouldSetSpell) {
					returnValue = playerSpellManagerAddr;
					CECPlayerSpellManager_SetCurrentSpell(ctx, base, playerSpellManagerAddr, currentSpell);
				}
			}

			uint32_t spellVisual = playerSpellManager->m_14;
			if (spellVisual != 0) {
				ctx.fpscr.disableFlushMode();
				double finalChargeA = double(playerSpellManager->m_chargeA);
				if (double(LOAD_F32(spellVisual + 9380)) != finalChargeA) {
					STORE_F32(spellVisual + 9380, float(finalChargeA));
					STORE8(spellVisual + 9440, 1);
					STORE8(spellVisual + 9439, 1);
				}
			}
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return returnValue;
}
PROMOTED_ENTRY(13, sub_822D2EE0, 0x822D2EE0) { ctx.r3.u64 = CECPlayerSpellManager_UpdateNetworked(ctx, base, ctx.r3.u32); }

uint64_t CECPlayerSpellManager_Update(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
	if (!UseLiftedCode(13, 0x822D3078)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_822D3078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	if (int32_t(LOAD32(LOAD32((uint32_t)playerSpellManagerAddr + 16) + 112)) != 0) {
		ctx.r1.u64 = stack;
		Lua_PlayerSpellManager_BuildPotentialTargetEntitiesList(ctx, base, playerSpellManagerAddr);  // Lua_PlayerSpellManager_BuildPotentialTargetEntitiesList
	}
	ctx.r1.u64 = stack;
	CECPlayerSpellManager_UpdateNetworked(ctx, base, playerSpellManagerAddr);
	uint64_t result = SpellChargeState_Update(ctx, base, (int64_t)playerSpellManagerAddr + 484);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(13, sub_822D3078, 0x822D3078) { ctx.r3.u64 = CECPlayerSpellManager_Update(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A68A4_B_ = int32_t(0x820A68A4);
	if (!UseLiftedCode(39, 0x82610E30)) { ctx.r3.u64 = classNameString; __imp__sub_82610E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82610E30);
	GameStackFrame stackFrame(ctx, base, 96);

	uint64_t className = str_TXT_820A68A4_B_;
	int32_t maxLength = -1;
	CCharString_ConstructFromCStr(ctx, base, classNameString, className, maxLength);
	return classNameString;
}
PROMOTED_ENTRY(39, sub_82610E30, 0x82610E30) { ctx.r3.u64 = CECPlayerSpellManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr, uint64_t deleteFlag) {
	if (!UseLiftedCode(39, 0x82610F48)) { ctx.r3.u64 = playerSpellManagerAddr; ctx.r4.u64 = deleteFlag; __imp__sub_82610F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82610F48);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 96);

	// The embedded secondary object at +12 gets its own vtable restored.
	uint32_t secondaryVtableAddr = (uint32_t)playerSpellManagerAddr + 12;
	if ((uint32_t)playerSpellManagerAddr == 0) {
		secondaryVtableAddr = 0;
	}
	STORE32(secondaryVtableAddr, 0x820A5A58u);
	playerSpellManager->vtable = 0x820A8D10u;

	uint64_t result = playerSpellManagerAddr;
	if ((uint32_t)deleteFlag & 0x1) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, playerSpellManagerAddr);
		deleteFlag = ctx.r4.u64;
		result = playerSpellManagerAddr;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlag;
	return result;
}
PROMOTED_ENTRY(39, sub_82610F48, 0x82610F48) { ctx.r3.u64 = CECPlayerSpellManager_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPlayerSpellManager_Shutdown(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(39, 0x826111D8)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_826111D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826111D8);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t shutdownFlagAddr = (uint32_t)playerSpellManagerAddr + 0x1E8;
	if (LOAD8(shutdownFlagAddr) != 0) {
		STORE8(shutdownFlagAddr, 0);
		STORE8(shutdownFlagAddr + 2, 1);
	}

	ctx.r1.u64 = stack;
	SpellChargeState_Reset(ctx, base, (uint32_t)playerSpellManagerAddr + 0x1E4);

	uint64_t spellEntity = playerSpellManager->m_14;
	playerSpellManager->m_dirty = 0;
	playerSpellManager->m_currentSpell = 0;
	if ((uint32_t)spellEntity != 0) {
		uint32_t gameGlobals = LOAD32((uint32_t)g_83490000 + 26912);
		uint32_t spellTarget = LOAD32(LOAD32(LOAD32(gameGlobals + 12) + 88) + 4);
		spellTarget = LOAD32(spellTarget + 64);
		SpellVisual_Release(ctx, base, spellTarget, spellEntity);
		spellEntity = ctx.r4.u64;
		playerSpellManager->m_14 = 0;
	}
	uint64_t result = CECPlayerSpellManager_RefreshMagicHUD(ctx, base, playerSpellManagerAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(39, sub_826111D8, 0x826111D8) { ctx.r3.u64 = CECPlayerSpellManager_Shutdown(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_Reset(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
	if (!UseLiftedCode(39, 0x82611268)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_82611268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82611268);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t pendingSpellAddr = (uint32_t)playerSpellManagerAddr + 484;
	if (LOAD8((uint32_t)playerSpellManagerAddr + 488) != 0) {
		STORE8(pendingSpellAddr + 4, uint8_t(0));
		STORE8(pendingSpellAddr + 6, uint8_t(1));
	}
	playerSpellManager->m_dirty = 0;
	playerSpellManager->m_currentSpell = 0;
	uint32_t owner = playerSpellManager->m_owner;
	ctx.r1.u64 = stack;
	uint32_t isNetworked = Entity_IsNetworked(ctx, base, owner);
	if (uint32_t(isNetworked & 0xFF) != 0) {
		uint32_t networkController = playerSpellManager->m_14;
		if (networkController != 0) {
			SpellVisual_Reset(ctx, base, networkController);
		}
	}
	uint64_t result = CECPlayerSpellManager_RefreshMagicHUD(ctx, base, playerSpellManagerAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(39, sub_82611268, 0x82611268) { ctx.r3.u64 = CECPlayerSpellManager_Reset(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_IsOwnerNetworked(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(39, 0x826112E8)) { ctx.r3.u64 = arg1; __imp__sub_826112E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826112E8);
	uint32_t ownerEntity = LOAD32((uint32_t)arg1 + 4);
	return Entity_IsNetworked(ctx, base, ownerEntity);
}
PROMOTED_ENTRY(39, sub_826112E8, 0x826112E8) { ctx.r3.u64 = CECPlayerSpellManager_IsOwnerNetworked(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_ResetTargeting(CpuState& ctx, uint8_t* base, uint32_t playerSpellManagerAddr) {
	if (!UseLiftedCode(40, 0x82611F18)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_82611F18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82611F18);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u32;
	PPCVRegister zeroVec{};
	PPCVRegister maskVec{};
	PPCVRegister shiftedVec{};
	PPCVRegister broadcastVec{};
	PPCVRegister targetVec{};
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t owner = playerSpellManager->m_owner;
	ctx.r1.u64 = stack;
	uint64_t result = Entity_IsNetworked(ctx, base, owner);
	if (uint32_t((uint32_t)result & 0xFF) != 0) {
		SET_V8(zeroVec, simde_mm_set1_epi32(int(0x0)));
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 80, LOAD_F32(0x820994C0u));
		playerSpellManager->m_dirty = 0;
		float charge = LOAD_F32(0x820994B4u);
		playerSpellManager->m_currentSpell = 0;
		playerSpellManager->m_chargeA = charge;
		playerSpellManager->m_chargeB = charge;
		result = 64;
		SET_V8(maskVec, VLOAD(0x820991A0u & ~0xF));
		scratch.u32 = uint32_t((int32_t)stack + 80);
		SET_V8(shiftedVec, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
		SET_V8(broadcastVec, simde_mm_shuffle_epi32(V8(shiftedVec), 0xFF));
		SET_V8(targetVec, simde_mm_and_si128(V8(broadcastVec), V8(maskVec)));
		VSTORE((playerSpellManagerAddr + (uint32_t)result) & ~0xF, V8(zeroVec));
		VSTORE((playerSpellManagerAddr + 48u) & ~0xF, V8(targetVec));
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_82611F18, 0x82611F18) { ctx.r3.u64 = CECPlayerSpellManager_ResetTargeting(ctx, base, ctx.r3.u32); }

uint64_t Lua_PlayerSpellManager_BuildPotentialTargetEntitiesList(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(40, 0x82612860)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_82612860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82612860);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	const uint32_t managerAddr = uint32_t(playerSpellManagerAddr);
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 336);

	// Feature gate: the list is only built when the targeting configuration is enabled.
	uint32_t targetingConfig = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 140);
	bool buildTargets = LOAD8(targetingConfig + 52) != 0 && LOAD8(targetingConfig + 53) != 0;

	uint64_t result = playerSpellManagerAddr;

	if (buildTargets) {
		ctx.fpscr.disableFlushMode();
		double radius = LOAD_F64(0x82100520u);
		ctx.r1.u64 = stack;
		radius = ceil(ctx, base, radius);

		uint32_t owner = playerSpellManager->m_owner;
		ctx.fpscr.disableFlushMode();
		double radiusF = double(float(radius));
		uint32_t shapeOut = stack + 256;
		uint32_t shapeComp = LOAD32(owner + 124);
		uint32_t shapeTable = LOAD32(shapeComp);

		PPCRegister radiusInt64;
		radiusInt64.s64 = std::isnan(radiusF) ? int64_t(0x80000000U) : radiusF > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&radiusF));
		STORE_F64(stack + 88, radiusInt64.f64);
		const uint32_t radiusPixels = LOAD32(stack + 92);

		uint32_t getShape = LOAD32(shapeTable + 64);
		ctx.r3.u64 = shapeOut;
		ctx.r4.u64 = shapeComp;
		ctx.r8.u64 = getShape;
		ctx.r9.u64 = shapeTable;
		ctx.r10.u64 = owner;
		ctx.f1.f64 = radius;
		ctx.f13 = radiusInt64;
		REX_CALL_INDIRECT_FUNC(getShape);
		flags.ca = ctx.xer.ca;

		uint32_t owner2 = playerSpellManager->m_owner;
		PPCVRegister block4;
		SET_V8(block4, VLOAD(uint32_t(stack + 256) & ~0xFu));
		VSTORE(uint32_t(stack + 112) & ~0xFu, V8(block4));

		ctx.fpscr.disableFlushMode();
		double yF = double(LOAD_F32(stack + 116));
		PPCRegister yInt64;
		yInt64.s64 = std::isnan(yF) ? int64_t(0x80000000U) : yF > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&yF));
		VSTORE(uint32_t(stack + 112) & ~0xFu, V8(block4));
		double xF = double(LOAD_F32(stack + 112));
		STORE_F64(stack + 88, yInt64.f64);
		const uint32_t yPixels = LOAD32(stack + 92);
		PPCRegister xInt64;
		xInt64.s64 = std::isnan(xF) ? int64_t(0x80000000U) : xF > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&xF));
		STORE_F64(stack + 88, xInt64.f64);
		const uint32_t xPixels = LOAD32(stack + 92);

		// Screen-space rectangle around the shape centre, grown by the effect radius.
		STORE32(stack + 112, xPixels - radiusPixels);
		STORE32(stack + 116, yPixels - radiusPixels);
		STORE32(stack + 120, xPixels + radiusPixels);
		STORE32(stack + 124, yPixels + radiusPixels);

		uint32_t targetingType = Entity_GetTargetingType(ctx, base, owner2);
		flags.ca = ctx.xer.ca;
		uint32_t owner3 = playerSpellManager->m_owner;
		STORE32(stack + 164, targetingType);

		const uint32_t volumeOut = stack + 208;
		const uint32_t params = stack + 88;
		const uint32_t rect = stack + 112;

		STORE32(stack + 148, 0);
		STORE32(stack + 152, 0);
		STORE32(stack + 156, 0);
		STORE32(stack + 160, owner3);

		uint32_t volumeComp = LOAD32(owner3 + 124);
		uint32_t getVolume = LOAD32(LOAD32(volumeComp) + 64);
		ctx.r3.u64 = volumeOut;
		ctx.r4.u64 = volumeComp;
		ctx.r5.u64 = owner3;
		ctx.r10.u64 = getVolume;
		ctx.f9 = xInt64;
		ctx.f10.f64 = xF;
		ctx.f11 = yInt64;
		ctx.f12.f64 = yF;
		REX_CALL_INDIRECT_FUNC(getVolume);
		flags.ca = ctx.xer.ca;

		SET_V8(block4, VLOAD(uint32_t(stack + 208) & ~0xFu));
		STORE32(stack + 192, uint32_t(stack + 128));
		VSTORE(uint32_t(stack + 240) & ~0xFu, V8(block4));

		ctx.fpscr.disableFlushMode();
		float scale = LOAD_F32(0x8209BE48u);
		STORE32(stack + 196, uint32_t(stack + 80));
		STORE_F32(stack + 188, scale);
		STORE32(stack + 200, uint32_t(stack + 176));
		STORE32(stack + 88, 7u);
		STORE32(stack + 204, uint32_t(stack + 160));
		STORE32(stack + 92, uint32_t(stack + 192));
		STORE32(stack + 96, uint32_t(stack + 144));
		VSTORE(uint32_t(stack + 272) & ~0xFu, V8(block4));
		VSTORE(uint32_t(stack + 224) & ~0xFu, V8(block4));

		uint32_t managerRoot = LOAD32(uint32_t(g_83490000) + 26912);
		STORE32(stack + 128, uint32_t(playerSpellManager->m_owner));

		double f0 = double(LOAD_F32(stack + 240));
		STORE_F32(stack + 176, float(f0));
		double f2 = double(LOAD_F32(stack + 232));
		double f1 = double(LOAD_F32(stack + 276));
		STORE_F32(stack + 184, float(f2));
		STORE_F32(stack + 180, float(f1));

		uint32_t implArg = LOAD32(LOAD32(LOAD32(LOAD32(managerRoot + 12) + 88) + 4) + 12);
		ctx.f6.f64 = f1;
		ctx.f7.f64 = f0;
		ctx.f8.f64 = f2;
		PlayerSpellManager_BuildPotentialTargetEntitiesImpl(ctx, base, implArg, rect, params);
		flags.ca = ctx.xer.ca;

		uint32_t listBase = LOAD32(stack + 148);
		uint32_t listEnd = LOAD32(stack + 152);

		uint32_t targetCount;
		if (listBase == 0) {
			targetCount = 0;
		} else {
			const uint32_t listBytes = listEnd - listBase;
			flags.ca = (int32_t(listBytes) < 0) & ((listBytes & 0x3) != 0);
			targetCount = uint32_t(int32_t(listBytes) >> 2);
		}
		playerSpellManager->m_50 = targetCount;
		if (int32_t(targetCount) > 100) {
			playerSpellManager->m_50 = 100u;
		}

		if (int32_t(LOAD32(managerAddr + 80)) > 0) {
			uint32_t src = listBase;
			uint32_t dst = managerAddr + 84;
			uint32_t i = 0;
			do {
				if (listBase == 0) {
					ppc_trap(ctx, base, 22);
				} else {
					const uint32_t listBytes = listEnd - listBase;
					flags.ca = (int32_t(listBytes) < 0) & ((listBytes & 0x3) != 0);
					if (i >= uint32_t(int32_t(listBytes) >> 2)) {
						ppc_trap(ctx, base, 22);
					}
				}
				STORE32(dst, LOAD32(src));
				i++;
				src += 4;
				dst += 4;
			} while (int32_t(i) < int32_t(LOAD32(managerAddr + 80)));
		}

		if (listBase != 0) {
			ctx.xer.ca = flags.ca;
			result = HandleTarget_Free(ctx, base, listBase);
			flags.ca = ctx.xer.ca;
		} else {
			result = 0;
		}
	}

	stack = PopStackFrame(stack, 336);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(40, sub_82612860, 0x82612860) { ctx.r3.u64 = Lua_PlayerSpellManager_BuildPotentialTargetEntitiesList(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_RefreshMagicHUD(CpuState& ctx, uint8_t* base, uint32_t playerSpellManagerAddr) {
	constexpr int32_t TXT_83498FFC_G_ = int32_t(0x83498FFC);
	constexpr int32_t g_834C0000 = int32_t(0x834C0000);
	constexpr int32_t g_834C2114 = int32_t(0x834C2114);
	constexpr int32_t g_834C2120 = int32_t(0x834C2120);
	if (!UseLiftedCode(40, 0x82612B48)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_82612B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82612B48);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// One-shot init of the cached spell entry: state word at 0x834C2128, value at 0x834C2120 (+4).
	const uint32_t spellCacheStateAddr = uint32_t(g_834C0000) + 8488;
	const uint64_t spellCacheAddr = g_834C2120;
	const uint32_t spellCacheState = LOAD32(spellCacheStateAddr);
	const uint32_t spellCacheInitialised = spellCacheState & 1;
	const uint32_t ownerBeforeFirstLookup = playerSpellManager->m_owner;
	if (spellCacheInitialised == 0) {
		STORE32((uint32_t)spellCacheAddr + 4, spellCacheInitialised);
		STORE32(spellCacheStateAddr, spellCacheState | 1);
		STORE32((uint32_t)spellCacheAddr, 1u);
	}

	const uint32_t spellSourceGlobal = LOAD32(0x83496920u);
	uint32_t spellEntryPtr = LOAD32(LOAD32(LOAD32(spellSourceGlobal + 12) + 88) + 4);
	uint32_t firstSpellId = LOAD32(spellEntryPtr);
	ctx.r1.u64 = stack;
	uint64_t firstLookup = EntityManager_LookupEntity(ctx, base, firstSpellId, spellCacheAddr);
	uint32_t lookupOutput = ctx.r8.u32;

	// Second cache entry: state word at 0x834C211C, value at 0x834C2114 (+4).
	const uint32_t secondCacheStateAddr = uint32_t(g_834C0000) + 8476;
	const uint64_t secondCacheAddr = g_834C2114;
	const uint32_t ownerBeforeSecondLookup = playerSpellManager->m_owner;
	const uint32_t firstDelta = (uint32_t)(firstLookup - ownerBeforeFirstLookup);
	const uint32_t firstDeltaClz = firstDelta == 0 ? 32 : __builtin_clz(firstDelta);
	uint32_t firstMatches = (firstDeltaClz >> 5) & 1;
	const uint32_t secondCacheState = LOAD32(secondCacheStateAddr);
	if ((secondCacheState & 1) == 0) {
		lookupOutput = 2;
		STORE32(secondCacheStateAddr, secondCacheState | 1);
		STORE32((uint32_t)secondCacheAddr + 4, 0u);
		STORE32((uint32_t)secondCacheAddr, lookupOutput);
	}

	uint32_t secondSpellId = LOAD32(LOAD32(LOAD32(LOAD32(spellSourceGlobal + 12) + 88) + 4));
	uint64_t secondLookup = EntityManager_LookupEntity(ctx, base, secondSpellId, secondCacheAddr);
	uint64_t secondDelta = secondLookup - (uint64_t)ownerBeforeSecondLookup;
	uint32_t secondDeltaClz = (uint32_t)secondDelta == 0 ? 32 : __builtin_clz((uint32_t)secondDelta);
	const uint32_t secondMatches = (secondDeltaClz >> 5) & 1;

	uint64_t result = secondLookup;
	if (firstMatches != 0 || secondMatches != 0) {
		uint64_t magicHud = playerSpellManager->m_10;
		result = magicHud;
		if ((uint32_t)magicHud != 0) {
			ctx.r6.u64 = secondDeltaClz;
			ctx.r7.u64 = firstMatches;
			ctx.r8.u64 = secondDelta;
			result = EntityHandle_ForwardToTarget(ctx, base, magicHud, (uint64_t)TXT_83498FFC_G_, 200);
			secondDeltaClz = ctx.r6.u64;
			firstMatches = ctx.r7.u64;
			secondDelta = ctx.r8.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = secondDeltaClz;
	ctx.r7.u64 = firstMatches;
	ctx.r8.u64 = secondDelta;
	return result;
}
PROMOTED_ENTRY(40, sub_82612B48, 0x82612B48) { ctx.r3.u64 = CECPlayerSpellManager_RefreshMagicHUD(ctx, base, ctx.r3.u32); }
