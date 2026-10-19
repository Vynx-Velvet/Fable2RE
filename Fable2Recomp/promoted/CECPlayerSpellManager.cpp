// CECPlayerSpellManager (vtable 0x820043A0): methods of the class as readable C++.
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

uint64_t CECPlayerSpellManager_Update(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(13, 0x822D3078)) { ctx.r3.u64 = arg1; __imp__sub_822D3078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D3078);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	if (int32_t(LOAD32(LOAD32((uint32_t)arg1 + 16) + 112)) != 0) {
		ctx.r1.u64 = stack;
		n_sub_82612860(ctx, base, arg1);  // Lua_PlayerSpellManager_BuildPotentialTargetEntitiesList
	}
	ctx.r1.u64 = stack;
	CECPlayerSpellManager_UpdateNetworked(ctx, base, arg1);
	uint64_t result = n_sub_822D4820(ctx, base, (int64_t)arg1 + 484);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(13, sub_822D3078, 0x822D3078) { ctx.r3.u64 = CECPlayerSpellManager_Update(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t str_TXT_820A68A4_B_ = int32_t(0x820A68A4);
	if (!UseLiftedCode(39, 0x82610E30)) { ctx.r3.u64 = arg1; __imp__sub_82610E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82610E30);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint64_t className = str_TXT_820A68A4_B_;
	int32_t maxLength = -1;
	CCharString_ConstructFromCStr(ctx, base, arg1, className, maxLength);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(39, sub_82610E30, 0x82610E30) { ctx.r3.u64 = CECPlayerSpellManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECPlayerSpellManager_Construct(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr, uint32_t ownerEntity) {
	constexpr int32_t g_820991A0 = int32_t(0x820991A0);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	if (!UseLiftedCode(39, 0x82610E70)) { ctx.r3.u64 = playerSpellManagerAddr; ctx.r4.u64 = ownerEntity; __imp__sub_82610E70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82610E70);

	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);

	stack = PushStackFrame(base, stack, 112);

	const uint32_t dataAddress = uint32_t(g_820A0000) - 27456;
	ctx.fpscr.disableFlushMode();
	const float stackValue = LOAD_F32(dataAddress);
	const int32_t ntFailedFull = str_TXT_820C0000_B_;
	const uint64_t spellManagerInitData = uint64_t(g_820991A0);
	const uint8_t zeroByte = 0;
	const uint32_t zeroWord = 0;

	PPCVRegister zeroVector{};
	PPCVRegister maskVector{};
	PPCVRegister loadedVector{};
	PPCVRegister splatVector{};
	PPCVRegister storedVector{};

	SET_V8(zeroVector, simde_mm_set1_epi32(0));

	STORE_F32(stack + 80, stackValue);

	playerSpellManager->m_owner = ownerEntity;
	playerSpellManager->m_8 = zeroByte;
	playerSpellManager->m_C = 0x820A5A58u;
	playerSpellManager->vtable = 0x820043A0u;

	const float chargeValue = LOAD_F32(dataAddress - 12);
	playerSpellManager->m_chargeA = chargeValue;
	playerSpellManager->m_chargeB = chargeValue;
	playerSpellManager->m_C = uint32_t(int64_t(ntFailedFull) + 27932);
	playerSpellManager->m_10 = zeroWord;
	playerSpellManager->m_14 = zeroWord;
	playerSpellManager->m_dirty = zeroByte;
	playerSpellManager->m_1C = zeroWord;
	playerSpellManager->m_currentSpell = zeroWord;

	const uint64_t stackValueAddress = uint64_t(stack) + 80;
	const uint32_t storeOffset1 = 48;
	const uint32_t storeOffset2 = 64;

	SET_V8(maskVector, VLOAD((uint32_t)spellManagerInitData & ~0xF));
	scratch.u32 = (uint32_t)stackValueAddress;
	SET_V8(loadedVector, simde_mm_shuffle_epi8(
		simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
		simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_V8(splatVector, simde_mm_shuffle_epi32(V8(loadedVector), 0xFF));
	SET_V8(storedVector, simde_mm_and_si128(V8(splatVector), V8(maskVector)));

	VSTORE(((uint32_t)playerSpellManagerAddr + storeOffset1) & ~0xF, V8(storedVector));
	VSTORE(((uint32_t)playerSpellManagerAddr + storeOffset2) & ~0xF, V8(zeroVector));

	playerSpellManager->m_50 = zeroWord;
	playerSpellManager->m_218 = zeroWord;
	playerSpellManager->m_240 = zeroWord;

	uint32_t owner = playerSpellManager->m_owner;

	ctx.r1.u64 = stack;
	ctx.r5.u64 = spellManagerInitData;
	ctx.r6.s64 = ntFailedFull;
	ctx.r7.u64 = storeOffset2;
	ctx.r8.u64 = storeOffset1;
	ctx.r9.u64 = stackValueAddress;
	ctx.v10 = storedVector;
	ctx.v11 = splatVector;
	ctx.v12 = loadedVector;
	ctx.v13 = zeroVector;

	n_sub_82392C88(ctx, base, owner, playerSpellManagerAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return playerSpellManagerAddr;
}
PROMOTED_ENTRY(39, sub_82610E70, 0x82610E70) { ctx.r3.u64 = CECPlayerSpellManager_Construct(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CECPlayerSpellManager_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr, uint64_t arg2) {
	if (!UseLiftedCode(39, 0x82610F48)) { ctx.r3.u64 = playerSpellManagerAddr; ctx.r4.u64 = arg2; __imp__sub_82610F48(ctx, base); return ctx.r3.u64; }
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
	if ((uint32_t)arg2 & 0x1) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		HandleTarget_Free(ctx, base, playerSpellManagerAddr);
		arg2 = ctx.r4.u64;
		result = playerSpellManagerAddr;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return result;
}
PROMOTED_ENTRY(39, sub_82610F48, 0x82610F48) { ctx.r3.u64 = CECPlayerSpellManager_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPlayerSpellManager_Initialise(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(39, 0x82610FB0)) { ctx.r3.u64 = playerSpellManagerAddr; __imp__sub_82610FB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82610FB0);
	uint32_t stack = ctx.r1.u64;
	CECPlayerSpellManager* playerSpellManager = GameObject<CECPlayerSpellManager>(base, playerSpellManagerAddr);
	const uint32_t managerAddr = (uint32_t)playerSpellManagerAddr;
	const uint32_t spellManagerGlobals = uint32_t(g_83490000);
	uint64_t pendingSpellState = 0;
	uint64_t savedR6 = ctx.r6.u64;
	uint64_t savedR8 = ctx.r8.u64;
	auto xerCa = ctx.xer.ca;

	stack = PushStackFrame(base, stack, 128);

	// Look up the spell carried by the owning entity (either from the active spell
	// container or from the sorted spell table of the entity).
	uint32_t ownerEntity = playerSpellManager->m_owner;
	if ((LOAD8(ownerEntity + 40) & 0x1) != 0) {
		uint32_t levelTable = LOAD32(ownerEntity + 140);
		uint32_t spellValue;
		if (levelTable != 0) {
			uint32_t levelIndex = LOAD8(levelTable + 56);
			uint32_t tableStart = LOAD32(ownerEntity + 72);
			spellValue = LOAD32(tableStart + levelIndex * 8 + 4);
		} else {
			uint32_t tableStart = LOAD32(ownerEntity + 72);
			uint32_t tableEnd = LOAD32(ownerEntity + 76);
			savedR6 = tableEnd;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, tableStart);

			// lower bound of the key 56 in the 8-byte entries
			uint32_t diff = tableEnd - tableStart;
			xerCa = ((int32_t)diff < 0) & ((diff & 0x7) != 0);
			int32_t remaining = (int32_t)diff >> 3;
			uint32_t iter = tableStart;
			while (remaining > 0) {
				xerCa = (remaining < 0) & ((remaining & 0x1) != 0);
				int32_t half = remaining >> 1;
				savedR8 = uint64_t(half << 3);
				uint32_t mid = iter + uint32_t(half) * 8;
				if ((int32_t)LOAD32(mid) < 56) {
					iter = mid + 8;
					remaining = remaining - half - 1;
				} else {
					remaining = half;
				}
			}
			STORE32(stack + 84, iter);

			uint32_t selectedEntry = tableEnd;
			if (iter != tableEnd && (int32_t)LOAD32(iter) <= 56) {
				selectedEntry = iter;
			}
			spellValue = LOAD32(selectedEntry + 4);
		}
		playerSpellManager->m_10 = spellValue;
	}

	uint64_t spellState = playerSpellManager->m_14;
	if ((uint32_t)spellState != 0) {
		uint32_t manager = LOAD32(spellManagerGlobals + 26912);
		manager = LOAD32(manager + 12);
		uint32_t localPlayer = LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 64);
		ctx.r1.u64 = stack;
		ctx.r6.u64 = savedR6;
		ctx.r8.u64 = savedR8;
		ctx.xer.ca = xerCa;
		n_sub_82669B50(ctx, base, localPlayer, spellState);
		pendingSpellState = ctx.r4.u64;
		savedR8 = ctx.r8.u64;
		xerCa = ctx.xer.ca;
		playerSpellManager->m_14 = 0;
	}

	ownerEntity = playerSpellManager->m_owner;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = savedR8;
	ctx.xer.ca = xerCa;
	uint32_t isNetworked = Entity_IsNetworked(ctx, base, ownerEntity);
	if ((isNetworked & 0xFF) != 0) {
		uint32_t manager = LOAD32(spellManagerGlobals + 26912);
		uint32_t networkOwner = playerSpellManager->m_owner;
		manager = LOAD32(manager + 12);
		uint32_t localPlayer = LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 64);
		uint32_t newSpellState = n_sub_82669A78(ctx, base, localPlayer, networkOwner);
		pendingSpellState = ctx.r4.u64;
		playerSpellManager->m_14 = newSpellState;
	}

	ctx.r4.u64 = pendingSpellState;
	uint64_t result = CECPlayerSpellManager_ResetTargeting(ctx, base, playerSpellManagerAddr);

	// Reset the spell charge/selection state and clear both slot tables.
	uint32_t savedSpellState = playerSpellManager->m_10;
	uint32_t spellSlot = managerAddr + 0x21C;

	uint32_t slotField0 = 0;
	uint32_t slotField1 = 0;
	uint32_t slotField2 = 0;
	uint32_t slotField3 = 0;
	STORE32(stack + 80, slotField0);
	STORE32(stack + 84, slotField1);
	STORE32(stack + 88, slotField2);
	STORE32(stack + 92, slotField3);

	ctx.fpscr.disableFlushMode();
	const float defaultCharge = LOAD_F32(0x820994B4u);
	playerSpellManager->m_1F0 = defaultCharge;
	playerSpellManager->m_1E8 = (uint8_t)0;
	playerSpellManager->m_1F4 = defaultCharge;
	playerSpellManager->m_1E9 = (uint8_t)0;
	playerSpellManager->m_1F8 = defaultCharge;
	playerSpellManager->m_1EA = (uint8_t)0;
	playerSpellManager->m_1FC = defaultCharge;
	playerSpellManager->m_1EC = 0;
	playerSpellManager->m_200 = defaultCharge;
	playerSpellManager->m_savedSpellState = savedSpellState;

	for (int slotIndex = 0; slotIndex < 2; ++slotIndex) {
		ctx.fpscr.disableFlushMode();
		STORE_F32(spellSlot, defaultCharge);
		STORE_F32(spellSlot + 4, defaultCharge);
		STORE_F32(spellSlot + 8, defaultCharge);
		STORE_F32(spellSlot + 12, defaultCharge);
		STORE32(spellSlot - 24, 0xFFFFFFFF);
		STORE32(spellSlot - 20, LOAD32(stack + 80));
		STORE32(spellSlot - 16, LOAD32(stack + 84));
		STORE32(spellSlot - 12, LOAD32(stack + 88));
		STORE32(spellSlot - 8, LOAD32(stack + 92));
		STORE32(spellSlot - 4, 0);
		spellSlot += 40;
	}

	uint32_t abilitySlot = managerAddr + 596;
	playerSpellManager->m_2D4 = 0;
	for (int slotIndex = 0; slotIndex < 16; ++slotIndex) {
		STORE32(abilitySlot, 0);
		STORE32(abilitySlot + 4, 0);
		abilitySlot += 8;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = slotField3;
	return result;
}
PROMOTED_ENTRY(39, sub_82610FB0, 0x82610FB0) { ctx.r3.u64 = CECPlayerSpellManager_Initialise(ctx, base, ctx.r3.u64); }

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
	n_sub_82612ED0(ctx, base, (uint32_t)playerSpellManagerAddr + 0x1E4);

	uint64_t spellEntity = playerSpellManager->m_14;
	playerSpellManager->m_dirty = 0;
	playerSpellManager->m_currentSpell = 0;
	if ((uint32_t)spellEntity != 0) {
		uint32_t gameGlobals = LOAD32((uint32_t)g_83490000 + 26912);
		uint32_t spellTarget = LOAD32(LOAD32(LOAD32(gameGlobals + 12) + 88) + 4);
		spellTarget = LOAD32(spellTarget + 64);
		n_sub_82669B50(ctx, base, spellTarget, spellEntity);
		spellEntity = ctx.r4.u64;
		playerSpellManager->m_14 = 0;
	}
	ctx.r4.u64 = spellEntity;
	uint64_t result = n_sub_82612B48(ctx, base, playerSpellManagerAddr);
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
			n_sub_8266A148(ctx, base, networkController);
		}
	}
	uint64_t result = n_sub_82612B48(ctx, base, playerSpellManagerAddr);
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

uint64_t n_sub_82612860(CpuState& ctx, uint8_t* base, uint64_t playerSpellManagerAddr) {
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
PROMOTED_ENTRY(40, sub_82612860, 0x82612860) { ctx.r3.u64 = n_sub_82612860(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82612B48(CpuState& ctx, uint8_t* base, uint32_t playerSpellManagerAddr) {
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
	ctx.r8.u64 = spellEntryPtr;
	uint64_t firstLookup = n_sub_82264448(ctx, base, firstSpellId, spellCacheAddr);
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
	ctx.r6.u64 = firstDeltaClz;
	ctx.r7.u64 = firstDelta;
	ctx.r8.u64 = lookupOutput;
	uint64_t secondLookup = n_sub_82264448(ctx, base, secondSpellId, secondCacheAddr);
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
			result = n_sub_8242EA00(ctx, base, magicHud, (uint64_t)TXT_83498FFC_G_, 200);
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
PROMOTED_ENTRY(40, sub_82612B48, 0x82612B48) { ctx.r3.u64 = n_sub_82612B48(ctx, base, ctx.r3.u32); }
