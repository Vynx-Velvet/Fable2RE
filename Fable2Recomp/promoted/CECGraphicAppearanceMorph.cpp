// CECGraphicAppearanceMorph (vtable 0x82004218): methods of the class as readable C++.
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

uint64_t CECGraphicAppearanceMorph_GetClassName(CpuState& ctx, uint8_t* base, uint64_t outClassName) {
	constexpr int32_t str_TXT_820A75FC_B_ = int32_t(0x820A75FC);
	if (!UseLiftedCode(26, 0x82465D68)) { ctx.r3.u64 = outClassName; __imp__sub_82465D68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82465D68);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, outClassName, str_TXT_820A75FC_B_, -1);
	return outClassName;
}
PROMOTED_ENTRY(26, sub_82465D68, 0x82465D68) { ctx.r3.u64 = CECGraphicAppearanceMorph_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECGraphicAppearanceMorph_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t morphAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(26, 0x824666E8)) { ctx.r3.u64 = morphAddr; ctx.r4.u64 = deleteFlags; __imp__sub_824666E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824666E8);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags; // state the callee may pass on
	CECGraphicAppearanceMorph_Dtor(ctx, base, morphAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, morphAddr);
	}
	return morphAddr;
}
PROMOTED_ENTRY(26, sub_824666E8, 0x824666E8) { ctx.r3.u64 = CECGraphicAppearanceMorph_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CECGraphicAppearanceMorph_Dtor(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x82466738)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_82466738(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82466738);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearanceMorph* morph = GameObject<CECGraphicAppearanceMorph>(base, graphicAppearanceMorphAddr);
	uint32_t addr = (uint32_t)graphicAppearanceMorphAddr;
	const uint32_t zero = 0;

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	SharedHandle_Release(ctx, base, addr + 188);
	HandleVector_Destroy(ctx, base, addr + 164);

	// Each block below frees a storage pointer (when set) and clears it together with the two words after it.
	uint32_t storage = morph->m_94;
	if (storage != 0) {
		HandleTarget_Free(ctx, base, storage);
	}
	STORE32(addr + 148, zero);
	STORE32(addr + 152, zero);
	STORE32(addr + 156, zero);

	storage = morph->m_80;
	if (storage != 0) {
		HandleTarget_Free(ctx, base, storage);
	}
	STORE32(addr + 128, zero);
	STORE32(addr + 132, zero);
	STORE32(addr + 136, zero);

	SharedHandle_Release(ctx, base, addr + 116);
	SharedHandleVector_Clear(ctx, base, addr + 100);

	storage = morph->m_58;
	if (storage != 0) {
		HandleTarget_Free(ctx, base, storage);
	}
	STORE32(addr + 96, zero);
	STORE32(addr + 88, zero);
	STORE32(addr + 92, zero);

	storage = morph->m_48;
	if (storage != 0) {
		HandleTarget_Free(ctx, base, storage);
	}
	STORE32(addr + 72, zero);
	STORE32(addr + 76, zero);
	STORE32(addr + 80, zero);

	storage = morph->m_38;
	if (storage != 0) {
		// the elements from storage to storageEnd are released first
		uint32_t storageEnd = LOAD32(addr + 60);
		ctx.r3.u64 = addr + 52; // the callee reads r3 from the state
		Vector_DestroyRange(ctx, base, storage, storageEnd);
		HandleTarget_Free(ctx, base, LOAD32(addr + 56));
	}
	STORE32(addr + 56, zero);
	STORE32(addr + 60, zero);
	STORE32(addr + 64, zero);

	storage = morph->m_28;
	if (storage != 0) {
		HandleTarget_Free(ctx, base, storage);
	}
	STORE32(addr + 40, zero);
	STORE32(addr + 44, zero);
	STORE32(addr + 48, zero);

	uint32_t result = morph->m_14;
	if (result != 0) {
		result = HandleTarget_Free(ctx, base, result);
	}
	STORE32(addr + 20, zero);
	STORE32(addr + 24, zero);
	STORE32(addr + 28, zero);

	// vtable pointers at +12 and +0; the +12 address is null-checked like a base-class pointer conversion
	uint32_t vtableAddr12 = zero;
	if (addr != 0) {
		vtableAddr12 = addr + 12;
	}
	STORE32(vtableAddr12, 0x820B40E8u);
	morph->vtable = 0x820A8D10u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_82466738, 0x82466738) { ctx.r3.u64 = CECGraphicAppearanceMorph_Dtor(ctx, base, ctx.r3.u64); }

uint64_t CECGraphicAppearanceMorph_Register(CpuState& ctx, uint8_t* base, uint64_t morph, uint64_t characterDefinition, uint32_t skipDefinitionLoad, uint64_t reg6) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(26, 0x82466888)) { ctx.r3.u64 = morph; ctx.r4.u64 = characterDefinition; ctx.r5.u64 = skipDefinitionLoad; ctx.r6.u64 = reg6; __imp__sub_82466888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466888);
	uint32_t stack = ctx.r1.u64;
	// incoming r6/r8, handed on to List_InsertNodeCopyWord; when the table is searched
	// r6 becomes the table end and r8 the last probe offset
	uint64_t reg8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 144);

	// entry for key 3 in the owner's table of 8-byte {key, entry} pairs: through the byte index
	// at owner+140 when present, else by binary search; 0 when bit 3 of owner+36 is clear
	uint32_t entry = 0;
	uint32_t owner = LOAD32((uint32_t)morph + 4);
	if ((LOAD32(owner + 36) >> 3) & 1) {
		uint32_t keyIndexTable = LOAD32(owner + 140);
		if (keyIndexTable != 0) {
			uint32_t entryOffset = (uint32_t)LOAD8(keyIndexTable + 3) << 3;
			uint32_t table = LOAD32(owner + 72);
			entry = LOAD32(entryOffset + table + 4);
		} else {
			uint32_t search = LOAD32(owner + 72);
			reg6 = LOAD32(owner + 76);
			STORE32(stack + 80, 0);
			STORE32(stack + 84, search);
			uint32_t span = (uint32_t)reg6 - search;
			flags.ca = (int32_t)span < 0 & (span & 0x7) != 0;
			int32_t count = (int32_t)span >> 3;
			if (count > 0) {
				// lower bound of key 3
				while (count > 0) {
					flags.ca = count < 0 & (count & 0x1) != 0;
					int32_t half = count >> 1;
					uint32_t midOffset = (uint32_t)half << 3;
					reg8 = midOffset;
					search += midOffset;
					if ((int32_t)LOAD32(search) < 3) {
						count = count - half - 1;
						search += 8;
					} else {
						search -= midOffset;
						count = half;
					}
				}
				STORE32(stack + 84, search);
			}
			uint32_t found = (uint32_t)reg6;
			if (search != (uint32_t)reg6 && (int32_t)LOAD32(search) <= 3) {
				STORE64(stack + 88, LOAD64(stack + 80));
				found = search;
			}
			entry = LOAD32(found + 4);
		}
	}

	// append morph+12 to the list at entry+12: it is inserted before the head node at entry+16,
	// which is the list's end sentinel
	uint32_t endNode = LOAD32(entry + 16);
	uint32_t listAddr = entry + 12;
	STORE32(stack + 80, (uint32_t)(morph + 12));
	uint64_t valueAddr = (uint64_t)stack + 80;
	STORE32(stack + 88, listAddr);
	STORE32(stack + 92, endNode);
	uint64_t insertPosition = LOAD64(stack + 88);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r6.u64 = reg6;
	ctx.r8.u64 = reg8;
	ctx.xer.ca = flags.ca;
	List_InsertNodeCopyWord(ctx, base, listAddr, insertPosition, valueAddr);

	if (skipDefinitionLoad == 0) {
		CECGraphicAppearanceMorph_LoadCharacterDefinition(ctx, base, morph, characterDefinition, ctx.r6.u64);
	}

	if ((CECGraphicAppearanceMorph_ShouldLoadBaseSkeletalMorph(ctx, base, morph) & 0xFF) != 0) {
		CECGraphicAppearanceMorph_LoadBaseSkeletalMorph(ctx, base, morph);
	}

	uint32_t currentOwner = LOAD32((uint32_t)morph + 4);
	uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
	uint32_t node = LOAD32(LOAD32(globalRoot + 12) + 88);
	uint32_t nodeTarget = LOAD32(node + 4);
	uint32_t handleOwner = LOAD32(nodeTarget);
	// the handle at handleOwner+104 refers to an object through its entry pointer at +108;
	// the handle's address is returned unless a dead handle is released
	uint64_t result = (uint64_t)handleOwner + 104;
	uint32_t handleEntry = LOAD32(handleOwner + 108);

	uint32_t handleTarget = 0;
	if (handleEntry != 0) {
		handleTarget = LOAD32(handleEntry);
		if (handleTarget == 0) {
			// state the callee may pass on
			result = EntityHandle_Release(ctx, base, result);
		}
	}

	if (currentOwner == handleTarget) {
		STORE32(entry + 212, 0);
	} else {
		// otherwise the entry takes a fresh value from the counter at 0x8331910C
		uint32_t counterAddr = (uint32_t)g_83320000 - 28404;
		uint32_t counter = LOAD32(counterAddr);
		STORE32(entry + 212, counter);
		STORE32(counterAddr, counter + 1);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_82466888, 0x82466888) { ctx.r3.u64 = CECGraphicAppearanceMorph_Register(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

// sub_82466A60  [4 bytes]
uint64_t n_sub_82466A60(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x82466A60)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_82466A60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466A60);
	return CECGraphicAppearanceMorph_GetOwnerComponent(ctx, base, graphicAppearanceMorphAddr);
}
PROMOTED_ENTRY(26, sub_82466A60, 0x82466A60) { ctx.r3.u64 = n_sub_82466A60(ctx, base, ctx.r3.u64); }

// sub_82466A68  [56 bytes]
uint64_t CECGraphicAppearanceMorph_Unregister(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x82466A68)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_82466A68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466A68);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearanceMorph* graphicAppearanceMorph = GameObject<CECGraphicAppearanceMorph>(base, graphicAppearanceMorphAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CECGraphicAppearanceMorph_EnsureTextureMorphComponent(ctx, base, graphicAppearanceMorphAddr);
	uint32_t owner = graphicAppearanceMorph->m_Owner;
	uint64_t result = Vector_RemoveByValue(ctx, base, owner, graphicAppearanceMorphAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_82466A68, 0x82466A68) { ctx.r3.u64 = CECGraphicAppearanceMorph_Unregister(ctx, base, ctx.r3.u64); }

// sub_82466AA0  [184 bytes]
uint64_t CECGraphicAppearanceMorph_LoadFromDefinition(CpuState& ctx, uint8_t* base, uint64_t appearanceMorph, uint64_t definition, uint64_t skipCharacterLoad) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820B3C54_B_ = int32_t(0x820B3C54);
	constexpr int32_t str_TXT_820B3C64_B_ = int32_t(0x820B3C64);
	if (!UseLiftedCode(26, 0x82466AA0)) { ctx.r3.u64 = appearanceMorph; ctx.r4.u64 = definition; ctx.r6.u64 = skipCharacterLoad; __imp__sub_82466AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466AA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	uint32_t stringBuffer = stack + 80;

	ctx.r1.u64 = stack;
	ctx.r6.u64 = skipCharacterLoad; // state the callees may pass on
	CCharString_ConstructFromCStr(ctx, base, stringBuffer, str_TXT_820B3C54_B_, -1);
	// the string's text pointer, or the address 0x8209003F when it has no data; IStream_SerializeId takes it in r4
	uint32_t characterUidData = LOAD32(stringBuffer);
	uint64_t characterUidText = g_8209003F;
	if (characterUidData != 0) {
		characterUidText = LOAD32(characterUidData);
	}
	ctx.r4.u64 = characterUidText;
	IStream_SerializeId(ctx, base, definition, appearanceMorph + 180);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stringBuffer);

	CCharString_ConstructFromCStr(ctx, base, stringBuffer, str_TXT_820B3C64_B_, -1);
	IStream_SerializeString(ctx, base, stringBuffer, definition, appearanceMorph + 178);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stringBuffer);

	if ((skipCharacterLoad & 0xFF) == 0) {
		uint64_t idRefHolder = Component_GetId(ctx, base, stringBuffer, appearanceMorph);
		uint64_t idRef = IdRef_Get(ctx, base, idRefHolder);
		result = CECGraphicAppearanceMorph_LoadCharacterDefinition(ctx, base, appearanceMorph, idRef, ctx.r6.u64);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_82466AA0, 0x82466AA0) { ctx.r3.u64 = CECGraphicAppearanceMorph_LoadFromDefinition(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint32_t CECGraphicAppearanceMorph_EnsureTextureMorphComponent(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x82466B58)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_82466B58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82466B58);
	uint32_t stack = ctx.r1.u64;
	// incoming r6/r8, handed on to operator_new; when the table is searched
	// r6 becomes the table end and r8 the last probe offset
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	CECGraphicAppearanceMorph* graphicAppearanceMorph = GameObject<CECGraphicAppearanceMorph>(base, graphicAppearanceMorphAddr);
	stack = PushStackFrame(base, stack, 128);
	uint32_t morphAddr = (uint32_t)graphicAppearanceMorphAddr;
	uint32_t sharedPtrAddr = morphAddr + 188;
	uint64_t result = graphicAppearanceMorphAddr;

	if ((uint32_t)graphicAppearanceMorph->m_B8 != 0 && LOAD32(sharedPtrAddr) == 0) {
		uint32_t owner = (uint32_t)graphicAppearanceMorph->m_Owner;
		if (((LOAD32(owner + 36) >> 14) & 1) != 0) {
			// entry for key 14 in the owner's table of 8-byte {key, entry} pairs: through the byte
			// index at owner+140 when present, else by binary search
			uint32_t entry;
			uint32_t keyIndexTable = LOAD32(owner + 140);
			if (keyIndexTable != 0) {
				uint32_t entryOffset = (uint32_t)LOAD8(keyIndexTable + 14) * 8;
				entry = LOAD32(LOAD32(owner + 72) + entryOffset + 4);
			} else {
				uint32_t pos = LOAD32(owner + 72);
				reg6 = LOAD32(owner + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, pos);
				int32_t count = (int32_t)((uint32_t)reg6 - pos);
				flags.ca = (count < 0) & (((uint32_t)count & 0x7) != 0);
				count >>= 3;
				// lower bound of key 14
				if (count > 0) {
					do {
						flags.ca = (count < 0) & (((uint32_t)count & 0x1) != 0);
						int32_t half = count >> 1;
						reg8 = (uint64_t)(uint32_t)(half << 3);
						pos = (uint32_t)(half << 3) + pos;
						if ((int32_t)LOAD32(pos) < 14) {
							count -= half;
							pos += 8;
							count -= 1;
						} else {
							pos -= (uint32_t)(half << 3);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, pos);
				}
				uint32_t match = (uint32_t)reg6;
				if (pos != (uint32_t)reg6 && (int32_t)LOAD32(pos) <= 14) {
					STORE64(stack + 80, LOAD64(stack + 80));
					match = LOAD32(stack + 84);
				}
				entry = LOAD32(match + 4);
			}

			if (entry != 0) {
				ctx.r1.u64 = stack;
				// state the callee may pass on
				ctx.r6.u64 = reg6;
				ctx.r8.u64 = reg8;
				ctx.xer.ca = flags.ca;
				uint64_t newObject = operator_new(ctx, base, 8);
				flags.ca = ctx.xer.ca;
				if ((uint32_t)newObject != 0) {
					STORE32((uint32_t)newObject + 4, 0);
					STORE32((uint32_t)newObject, 0x820A81F4u); // vtable
				} else {
					newObject = 0;
				}
				result = SharedPtr_ResetWithPointerE(ctx, base, sharedPtrAddr, newObject);
				flags.ca = ctx.xer.ca;
				uint32_t b8 = graphicAppearanceMorph->m_B8;
				uint32_t entryWord44 = LOAD32(entry + 44);
				STORE32(stack + 84, 0);
				STORE32(stack + 80, b8);
				if (entryWord44 != 0) {
					result = CECPhysicsRagdollComponentManager_CreateComponent(ctx, base, entry, LOAD32(sharedPtrAddr), (uint64_t)stack + 80);
					flags.ca = ctx.xer.ca;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return (uint32_t)result;
}
PROMOTED_ENTRY(26, sub_82466B58, 0x82466B58) { ctx.r3.u64 = CECGraphicAppearanceMorph_EnsureTextureMorphComponent(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82466CD8(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x82466CD8)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_82466CD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466CD8);
	return n_sub_824686C8(ctx, base, graphicAppearanceMorphAddr);
}
PROMOTED_ENTRY(26, sub_82466CD8, 0x82466CD8) { ctx.r3.u64 = n_sub_82466CD8(ctx, base, ctx.r3.u64); }

uint64_t CECGraphicAppearanceMorph_Detach(CpuState& ctx, uint8_t* base, uint64_t morphAddr) {
	if (!UseLiftedCode(26, 0x82466CE0)) { ctx.r3.u64 = morphAddr; __imp__sub_82466CE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82466CE0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 112);
	uint32_t morph = (uint32_t)morphAddr;
	STORE8(morph + 0xB3, uint8_t(1));
	ctx.r1.u64 = stack;
	uint64_t result = CECGraphicAppearanceMorph_Clear(ctx, base, morphAddr);
	// r6, r7, r8 and carry as CECGraphicAppearanceMorph_Clear left them; the lookup below overwrites some of
	// them and they are handed to CECGraphicAppearance_ForEach.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	flags.ca = ctx.xer.ca;

	// Component 3 of the owner (present when bit 3 of the mask at +0x24 is set): read through
	// the index table at +0x8C when there is one, otherwise found by a lower_bound search of the
	// sorted 8-byte (id, component) entries at +0x48..+0x4C, the iterator kept at stack+84.
	uint32_t owner = LOAD32(morph + 0x4);
	uint32_t appearance = 0;
	bool found = false;
	if (((LOAD32(owner + 0x24) >> 3) & 1) != 0) {
		uint32_t indexTable = LOAD32(owner + 0x8C);
		if (indexTable != 0) {
			reg8 = (uint64_t)(LOAD8(indexTable + 3) * 8) + (uint64_t)LOAD32(owner + 0x48);
			appearance = LOAD32((uint32_t)reg8 + 4);
		} else {
			uint32_t it = LOAD32(owner + 0x48);
			uint32_t end = LOAD32(owner + 0x4C);
			reg6 = end;
			STORE32(stack + 80, 0);
			uint32_t span = end - it;
			STORE32(stack + 84, it);
			flags.ca = ((int32_t)span < 0) & ((span & 7) != 0);
			int32_t count = (int32_t)span >> 3;
			if (count > 0) {
				flags.ca = 0;  // the carry of halving a positive count is 0
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					reg8 = step;
					it += step;
					reg7 = (int32_t)LOAD32(it) < 3;
					if (reg7 != 0) {
						count = count - half - 1;
						it += 8;
					} else {
						it -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 3) {
				STORE64(stack + 80, LOAD64(stack + 80));
				appearance = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				appearance = LOAD32(end + 4);
			}
		}
		found = true;
	}

	if (found) {
		// state the callee may pass on
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.xer.ca = flags.ca;
		CECGraphicAppearance_ForEach(ctx, base, appearance);
		// Remove every occurrence of this morph's +0xC address from the component's list at +0xC.
		STORE32(stack + 80, morph + 0xC);
		result = List_RemoveAllMatchingValue(ctx, base, (uint64_t)appearance + 12, (uint64_t)stack + 80);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(26, sub_82466CE0, 0x82466CE0) { ctx.r3.u64 = CECGraphicAppearanceMorph_Detach(ctx, base, ctx.r3.u64); }

uint64_t CECGraphicAppearanceMorph_Clear(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	if (!UseLiftedCode(26, 0x8246B3C0)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_8246B3C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8246B3C0);
	uint32_t stack = ctx.r1.u64;
	// r6, r8 and carry as the original code leaves them; they are handed to the callees below.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg8 = ctx.r8.u64;
	PPCXERRegister flags = ctx.xer;
	CECGraphicAppearanceMorph* graphicAppearanceMorph = GameObject<CECGraphicAppearanceMorph>(base, graphicAppearanceMorphAddr);
	stack = PushStackFrame(base, stack, 112);

	// Empty the (begin, end) arrays at +0x48, +0x58 and +0x28 by moving a non-empty array's end
	// back onto its begin; the storage is left alone. The compiled erase moves a zero-length
	// tail, leaving r6 = 0, r8 = the array's begin and carry clear.
	auto emptyArray = [&](uint32_t beginAddr) {
		uint32_t begin = LOAD32(beginAddr);
		uint32_t end = LOAD32(beginAddr + 4);
		if (begin != end) {
			reg6 = 0;
			reg8 = begin;
			flags.ca = 0;
			STORE32(beginAddr + 4, begin);
		}
	};
	emptyArray((uint32_t)graphicAppearanceMorphAddr + 0x48);
	emptyArray((uint32_t)graphicAppearanceMorphAddr + 0x58);
	emptyArray((uint32_t)graphicAppearanceMorphAddr + 0x28);

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r7.u64 = graphicAppearanceMorphAddr + 36;
	ctx.xer.ca = flags.ca;
	uint64_t result = n_sub_8246C330(ctx, base, graphicAppearanceMorphAddr + 52);
	reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	reg8 = ctx.r8.u64;
	PPCCRRegister cr0 = ctx.cr0;
	flags.ca = ctx.xer.ca;

	uint32_t sharedHandle = graphicAppearanceMorph->m_BC;
	uint64_t sharedHandleAddr = graphicAppearanceMorphAddr + 188;
	uint64_t reg4 = sharedHandle;
	if (sharedHandle != 0) {
		// Component 14 of the owner (present when bit 14 of the mask at +0x24 is set): read
		// through the index table at +0x8C when there is one, otherwise found by a lower_bound
		// search of the sorted 8-byte (id, component) entries at +0x48..+0x4C, the iterator kept
		// at stack+84.
		uint32_t owner = graphicAppearanceMorph->m_Owner;
		uint32_t component = 0;
		bool found = false;
		if (((LOAD32(owner + 0x24) >> 14) & 1) != 0) {
			uint32_t indexTable = LOAD32(owner + 0x8C);
			if (indexTable != 0) {
				reg8 = (uint64_t)(LOAD8(indexTable + 14) * 8) + (uint64_t)LOAD32(owner + 0x48);
				component = LOAD32((uint32_t)reg8 + 4);
			} else {
				uint32_t it = LOAD32(owner + 0x48);
				uint32_t end = LOAD32(owner + 0x4C);
				reg6 = end;
				STORE32(stack + 80, 0);
				uint32_t span = end - it;
				STORE32(stack + 84, it);
				flags.ca = ((int32_t)span < 0) & ((span & 7) != 0);
				int32_t count = (int32_t)span >> 3;
				cr0.compare<int32_t>(count, 0, flags);
				if (count > 0) {
					flags.ca = 0;  // the carry of halving a positive count is 0
					do {
						int32_t half = count >> 1;
						uint32_t step = (uint32_t)half << 3;
						reg8 = step;
						it += step;
						reg7 = (int32_t)LOAD32(it) < 14;
						if (reg7 != 0) {
							count = count - half - 1;
							it += 8;
						} else {
							it -= step;
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				if (it != end && (int32_t)LOAD32(it) <= 14) {
					STORE64(stack + 80, LOAD64(stack + 80));
					component = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					component = LOAD32(end + 4);
				}
			}
			found = true;
		}
		if (found) {
			// state the callee may pass on
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.cr0 = cr0;
			ctx.xer.ca = flags.ca;
			n_sub_82628F28(ctx, base, component, sharedHandle);
			reg4 = ctx.r4.u64;
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			cr0 = ctx.cr0;
			flags.ca = ctx.xer.ca;
		}
		// state the callee may pass on
		ctx.r4.u64 = reg4;
		ctx.r6.u64 = reg6;
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		ctx.cr0 = cr0;
		ctx.xer.ca = flags.ca;
		result = SharedHandle_Release(ctx, base, sharedHandleAddr);
		reg4 = ctx.r4.u64;
		STORE32((uint32_t)sharedHandleAddr, 0);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = reg4;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(26, sub_8246B3C0, 0x8246B3C0) { ctx.r3.u64 = CECGraphicAppearanceMorph_Clear(ctx, base, ctx.r3.u64); }

uint64_t CECGraphicAppearanceMorph_GetOwnerComponent(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceMorphAddr) {
	constexpr int32_t g_820A8734 = int32_t(0x820A8734);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(26, 0x8246BC90)) { ctx.r3.u64 = graphicAppearanceMorphAddr; __imp__sub_8246BC90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8246BC90);
	uint32_t stack = ctx.r1.u64;
	// r8, cr0 and carry as the original code leaves them for its callers.
	uint64_t reg8 = ctx.r8.u64;
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	CECGraphicAppearanceMorph* graphicAppearanceMorph = GameObject<CECGraphicAppearanceMorph>(base, graphicAppearanceMorphAddr);
	stack = PushStackFrame(base, stack, 112);

	// Component 91 of the owner (present when bit 27 of the mask word at +44, the word for ids
	// 64..95, is set): read through the index table at +140 when there is one, otherwise found by
	// a lower_bound search of the sorted 8-byte (id, component) entries at +72..+76, the iterator
	// kept at stack+84.
	uint32_t owner = graphicAppearanceMorph->m_Owner;
	uint32_t component = 0;
	bool found = false;
	if (((LOAD32(owner + 44) >> 27) & 1) != 0) {
		uint32_t indexTable = LOAD32(owner + 140);
		if (indexTable != 0) {
			uint32_t entry = ((uint32_t)LOAD8(indexTable + 91) << 3) + LOAD32(owner + 72);
			component = LOAD32(entry + 4);
		} else {
			uint32_t it = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 80, 0u);
			uint32_t span = end - it;
			STORE32(stack + 84, it);
			flags.ca = ((int32_t)span < 0) & ((span & 7) != 0);
			int32_t count = (int32_t)span >> 3;
			cr0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				flags.ca = 0;  // the carry of halving a positive count is 0
				do {
					int32_t half = count >> 1;
					uint32_t step = (uint32_t)half << 3;
					reg8 = step;
					it += step;
					if ((int32_t)LOAD32(it) < 91) {
						count = count - half - 1;
						it += 8;
					} else {
						it -= step;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}
		found = true;
	}

	uint64_t result = graphicAppearanceMorphAddr;
	if (found) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;  // state the callee may pass on
		result = CECNetwork_ShouldReplicateEntity(ctx, base, component);
		if (((uint32_t)result & 0xFF) != 0) {
			uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
			// Two-word record passed by pointer: the constant 0x820A8734, then m_B4.
			STORE32(stack + 84, uint32_t(graphicAppearanceMorph->m_B4));
			STORE32(stack + 80, uint32_t(g_820A8734));
			uint32_t receiver = LOAD32(LOAD32(globalRoot + 12) + 140);
			// state the callee may pass on (r8 holds the constant sign-extended)
			ctx.cr0 = cr0;
			uint64_t uniqueId = Entity_GetUniqueId(ctx, base, owner);
			result = MessageQueue_PostMessage(ctx, base, receiver, (uint64_t)stack + 80, uniqueId);
			reg8 = ctx.r8.u64;
			cr0 = ctx.cr0;
			flags.ca = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r8.u64 = reg8;
	ctx.cr0 = cr0;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(26, sub_8246BC90, 0x8246BC90) { ctx.r3.u64 = CECGraphicAppearanceMorph_GetOwnerComponent(ctx, base, ctx.r3.u64); }
