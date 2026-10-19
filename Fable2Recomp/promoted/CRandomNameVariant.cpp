// CRandomNameVariant (vtable 0x82005A88): methods of the class as readable C++.
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

uint64_t n_sub_821916D0(CpuState& ctx, uint8_t* base, uint64_t randomNameVariant, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(1, 0x821916D0)) { ctx.r3.u64 = randomNameVariant; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_821916D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821916D0);
	uint32_t variantData = LOAD32((uint32_t)randomNameVariant + 0x14);
	uint64_t namePtr = (uint64_t)variantData + 0x44;
	return n_sub_8228E880(ctx, base, variantData, namePtr, arg2, arg3);
}
PROMOTED_ENTRY(1, sub_821916D0, 0x821916D0) { ctx.r3.u64 = n_sub_821916D0(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64); }

// sub_821966A8  [16 bytes]
uint64_t n_sub_821966A8(CpuState& ctx, uint8_t* base, uint32_t randomNameVariantAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(1, 0x821966A8)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; __imp__sub_821966A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821966A8);
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	uint32_t variantData = randomNameVariant->m_data;
	uint64_t firstNameAddr = (uint64_t)variantData + 36;
	uint64_t secondNameAddr = (uint64_t)variantData + 68;
	return n_sub_8219A800(ctx, base, firstNameAddr, secondNameAddr, arg2, arg3, arg4);
}
PROMOTED_ENTRY(1, sub_821966A8, 0x821966A8) { ctx.r3.u64 = n_sub_821966A8(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_821E1A28  [88 bytes]
uint64_t n_sub_821E1A28(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr, uint64_t nameSource, uint64_t variantFilter) {
	if (!UseLiftedCode(4, 0x821E1A28)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r4.u64 = nameSource; ctx.r5.u64 = variantFilter; __imp__sub_821E1A28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821E1A28);
	uint32_t stack = ctx.r1.u64;
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	stack = PushStackFrame(base, stack, 112);

	PPCRegister callTarget{};
	callTarget.u64 = LOAD32(uint32_t(randomNameVariant->vtable) + 88);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = randomNameVariantAddr;
	ctx.r4.u64 = nameSource;
	ctx.r5.u64 = variantFilter;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t nameVariantIndex = ctx.r3.u32;

	if ((uint32_t)variantFilter != 0) {
		uint64_t result = n_sub_827FFC10(ctx, base, nameSource, (int64_t)randomNameVariantAddr + 8, nameVariantIndex, variantFilter);
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return result;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(4, sub_821E1A28, 0x821E1A28) { ctx.r3.u64 = n_sub_821E1A28(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_8228C238(CpuState& ctx, uint8_t* base, uint32_t randomNameVariantAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(10, 0x8228C238)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; __imp__sub_8228C238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8228C238);
	uint32_t stack = ctx.r1.u64;
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	uint32_t nameData = randomNameVariant->m_data;
	stack = PushStackFrame(base, stack, 96);
	uint32_t result = LOAD32(nameData + 76);
	if (int32_t(result) == 0) {
		ctx.r1.u64 = stack;
		result = n_sub_8228E880(ctx, base, (uint64_t)nameData + 12, (uint64_t)nameData + 68, arg2, arg3);
		STORE32(nameData + 76, result);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(10, sub_8228C238, 0x8228C238) { ctx.r3.u64 = n_sub_8228C238(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_827FF4B0(CpuState& ctx, uint8_t* base, uint32_t randomNameVariantAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(56, 0x827FF4B0)) { ctx.r3.u64 = randomNameVariantAddr; __imp__sub_827FF4B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827FF4B0);
	uint32_t stack = ctx.r1.u32;
	PPCXERRegister flags = ctx.xer;
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t networkManager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t managerState = LOAD32(LOAD32(networkManager + 12) + 140);
	bool isReady = LOAD8(managerState + 52) != 0 && LOAD8(managerState + 54) != 0;
	if (!isReady) {
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return 1;
	}

	uint32_t nameTable = randomNameVariant->m_nameHash;
	uint32_t entityId = 0;
	bool haveEntityId = false;

	if ((LOAD32(nameTable + 44) >> 27) & 1) {
		uint32_t lookup = LOAD32(nameTable + 140);
		if (lookup != 0) {
			uint32_t index = LOAD8(lookup + 91) << 3;
			entityId = LOAD32(LOAD32(nameTable + 72) + index + 4);
			haveEntityId = true;
		} else {
			uint32_t begin = LOAD32(nameTable + 72);
			uint32_t end = LOAD32(nameTable + 76);
			STORE32(stack + 80, 0u);
			uint32_t byteCount = end - begin;
			STORE32(stack + 84, begin);
			flags.ca = ((int32_t)byteCount < 0) & ((byteCount & 7) != 0);
			uint32_t count = (int32_t)byteCount >> 3;
			if ((int32_t)count > 0) {
				do {
					flags.ca = ((int32_t)count < 0) & ((count & 1) != 0);
					uint32_t half = (int32_t)count >> 1;
					uint32_t offset = half << 3;
					uint32_t mid = begin + offset;
					if ((int32_t)LOAD32(mid) < 91) {
						count = count - half - 1;
						begin = mid + 8;
					} else {
						count = half;
						begin = mid - offset;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, begin);
			}
			// lower_bound for key 91: a hit needs the key to be exactly 91
			if (begin != end && (int32_t)LOAD32(begin) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entityId = LOAD32(begin + 4);
			} else {
				entityId = LOAD32(end + 4);
			}
			haveEntityId = true;
		}
	}

	if (haveEntityId) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		uint32_t shouldReplicate = CECNetwork_ShouldReplicateEntity(ctx, base, entityId);
		if ((shouldReplicate & 0xFF) != 0) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return 1;
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(56, sub_827FF4B0, 0x827FF4B0) { ctx.r3.u64 = n_sub_827FF4B0(ctx, base, ctx.r3.u32); }

uint64_t n_sub_827FF870(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr, uint64_t nameString) {
	if (!UseLiftedCode(56, 0x827FF870)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r4.u64 = nameString; __imp__sub_827FF870(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827FF870);
	uint32_t stack = ctx.r1.u64;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);

	stack = PushStackFrame(base, stack, 112);
	uint64_t nameStringAddr = randomNameVariantAddr + 8;
	ctx.r1.u64 = stack;
	CCharString_Assign(ctx, base, nameStringAddr, nameString);
	flags.ca = ctx.xer.ca;

	uint32_t nameHash = randomNameVariant->m_nameHash;
	uint64_t matchingName = 0;
	bool hasMatch = false;

	if (((LOAD32(nameHash + 0x24) >> 19) & 1) != 0) {
		uint32_t indexTable = LOAD32(nameHash + 0x8C);
		if (indexTable != 0) {
			uint32_t entryList = LOAD32(nameHash + 0x48);
			uint32_t entryIndex = LOAD8(indexTable + 0x13) * 8;
			matchingName = LOAD32(entryList + entryIndex + 4);
			hasMatch = true;
		} else {
			uint32_t iter = LOAD32(nameHash + 0x48);
			uint32_t listEnd = LOAD32(nameHash + 0x4C);
			STORE32(stack + 80, (uint32_t)matchingName);
			STORE32(stack + 84, iter);
			uint32_t byteDistance = listEnd - iter;
			flags.ca = ((int32_t)byteDistance < 0) & ((byteDistance & 7) != 0);
			int32_t count = (int32_t)byteDistance >> 3;
			// binary search for the first entry whose key is >= 19
			if (count > 0) {
				do {
					flags.ca = (count < 0) & ((count & 1) != 0);
					int32_t half = count >> 1;
					uint32_t byteOffset = (uint32_t)half << 3;
					iter += byteOffset;
					compare6.compare<int32_t>((int32_t)LOAD32(iter), 19, flags);
					if (compare6.lt) {
						count = count - half - 1;
						iter += 8;
					} else {
						iter -= byteOffset;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, iter);
			}
			bool useLastEntry = (iter == listEnd);
			if (!useLastEntry) {
				compare6.compare<int32_t>((int32_t)LOAD32(iter), 19, flags);
				useLastEntry = compare6.gt;
			}
			if (!useLastEntry) {
				STORE64(stack + 80, LOAD64(stack + 80));
				iter = LOAD32(stack + 84);
				matchingName = LOAD32(iter + 4);
			} else {
				matchingName = LOAD32(listEnd + 4);
			}
			hasMatch = true;
		}
	}

	if (hasMatch) {
		ctx.xer.ca = flags.ca;
		matchingName = n_sub_825174C8(ctx, base, matchingName, nameStringAddr);
		flags.ca = ctx.xer.ca;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return matchingName;
}
PROMOTED_ENTRY(56, sub_827FF870, 0x827FF870) { ctx.r3.u64 = n_sub_827FF870(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827FF9D0(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr, uint64_t nameSource, uint32_t nameRef, uint64_t nameId, uint64_t variantFilter) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_834C35D4 = int32_t(0x834C35D4);
	if (!UseLiftedCode(56, 0x827FF9D0)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r4.u64 = nameSource; ctx.r5.u64 = nameRef; ctx.r6.u64 = nameId; ctx.r7.u64 = variantFilter; __imp__sub_827FF9D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827FF9D0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);

	stack = PushStackFrame(base, stack, 192);

	uint32_t nameBlock = LOAD32(nameRef);
	uint64_t nameText = g_8209003F;
	if (nameBlock != 0) {
		nameText = LOAD32(nameBlock);
	}

	const uint64_t hashSeed = 0xFFFFFFFF811C9DC5ull;

	ctx.r1.u64 = stack;
	uint64_t nameHash = String_HashFnv1(ctx, base, nameText, hashSeed);
	uint64_t r9Value = ctx.r9.u64;

	uint64_t variantNameId = nameId;
	bool variantLookupFailed = false;
	if ((uint32_t)nameId != 0) {
		uint32_t nameField = LOAD32((uint32_t)nameSource + 8);
		if (nameField != 0 && (int32_t)LOAD32(nameField + 4) != 0) {
			uint64_t nameFieldText = g_8209003F;
			if (nameField != 0) {
				nameFieldText = LOAD32(nameField);
			}

			STORE32(stack + 80, 0);
			uint64_t nameFieldHash = String_HashFnv1(ctx, base, nameFieldText, hashSeed);
			GameDB_ReadMappedU32Field(ctx, base, nameId, nameFieldHash, (uint64_t)stack + 80);
			r9Value = ctx.r9.u64;

			uint32_t mappedNameId = LOAD32(stack + 80);
			if (mappedNameId != 0) {
				uint32_t matchCount = n_sub_821C9EE0(ctx, base, mappedNameId, nameHash);
				r9Value = ctx.r9.u64;
				if (matchCount != 0) {
					variantNameId = mappedNameId;
				} else {
					uint32_t getVariantFn = LOAD32(LOAD32((uint32_t)nameSource) + 88);
					callTarget.u64 = getVariantFn;
					ctx.r3.u64 = nameSource;
					ctx.r10.u64 = getVariantFn;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					r9Value = ctx.r3.u32 & 0xFF;
					if ((uint32_t)r9Value != 0) {
						variantLookupFailed = true;
					}
				}
			}
		}
	}

	if (!variantLookupFailed) {
		uint32_t numVariants = n_sub_821C9EE0(ctx, base, variantNameId, nameHash);
		r9Value = ctx.r9.u64;

		if (numVariants != 0) {
			uint32_t variantIndexArray = uint32_t(g_834C35D4);

			if ((uint32_t)variantFilter != 0) {
				uint32_t acceptedCount = 0;
				for (uint32_t i = 0; i != numVariants; i++) {
					STORE32(stack + 88, (uint32_t)variantNameId);
					STORE32(stack + 92, (uint32_t)nameHash);
					STORE32(stack + 96, i);

					uint32_t acceptFn = LOAD32(LOAD32((uint32_t)variantFilter));
					callTarget.u64 = acceptFn;
					ctx.r3.u64 = variantFilter;
					ctx.r4.u64 = (uint64_t)stack + 88;
					ctx.r9.u64 = r9Value;
					ctx.r10.u64 = acceptFn;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					r9Value = ctx.r3.u32 & 0xFF;
					if ((uint32_t)r9Value != 0) {
						STORE32((acceptedCount << 2) + variantIndexArray, i);
						acceptedCount = acceptedCount + 1;
						if (acceptedCount >= 7) {
							acceptedCount = 7;
						}
					}
				}

				if (acceptedCount != 0) {
					randomNameVariant->vtable = variantNameId;
					randomNameVariant->m_nameHash = (uint32_t)nameHash;

					uint32_t randomStateBase = LOAD32((uint32_t)g_83490000 + 26912);
					uint32_t randomStatePtr = LOAD32(LOAD32(randomStateBase + 12) + 88);
					randomStatePtr = LOAD32(randomStatePtr + 4);

					uint32_t randomValue = __builtin_rotateleft32(LOAD32(randomStatePtr + 120) * 9377u + 9439u, 19);
					STORE32(randomStatePtr + 120, randomValue);

					int64_t indexProduct = (int64_t)(int32_t)(randomValue / acceptedCount) * (int64_t)(int32_t)acceptedCount;
					randomNameVariant->m_variantIndex = LOAD32((uint32_t)((uint32_t)(randomValue - indexProduct) << 2) + variantIndexArray);

					stack = PopStackFrame(stack, 192);
					ctx.r1.u64 = stack;
					ctx.r4.u64 = (uint64_t)indexProduct;
					return randomNameVariantAddr;
				}
			} else {
				randomNameVariant->vtable = variantNameId;
				randomNameVariant->m_nameHash = (uint32_t)nameHash;

				uint32_t randomStateBase = LOAD32((uint32_t)g_83490000 + 26912);
				uint32_t randomStatePtr = LOAD32(LOAD32(randomStateBase + 12) + 88);
				randomStatePtr = LOAD32(randomStatePtr + 4);

				uint32_t randomValue = __builtin_rotateleft32(LOAD32(randomStatePtr + 120) * 9377u + 9439u, 19);
				STORE32(randomStatePtr + 120, randomValue);

				int64_t indexProduct = (int64_t)(int32_t)(randomValue / numVariants) * (int64_t)(int32_t)numVariants;
				randomNameVariant->m_variantIndex = (uint32_t)(randomValue - indexProduct);

				stack = PopStackFrame(stack, 192);
				ctx.r1.u64 = stack;
				ctx.r4.u64 = (uint64_t)indexProduct;
				return randomNameVariantAddr;
			}
		}
	}

	randomNameVariant->m_nameHash = 0;
	randomNameVariant->vtable = 0;
	randomNameVariant->m_variantIndex = 0xFFFFFFFFu;
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return randomNameVariantAddr;
}
PROMOTED_ENTRY(56, sub_827FF9D0, 0x827FF9D0) { ctx.r3.u64 = n_sub_827FF9D0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint64_t n_sub_827FFD38(CpuState& ctx, uint8_t* base, uint32_t self, uint64_t nameRef, uint64_t gameDB) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	if (!UseLiftedCode(56, 0x827FFD38)) { ctx.r3.u64 = self; ctx.r4.u64 = nameRef; ctx.r5.u64 = gameDB; __imp__sub_827FFD38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827FFD38);
	uint32_t stack = ctx.r1.u64;
	uint32_t isMatch = 0;
	uint64_t r4AtReturn = nameRef;
	stack = PushStackFrame(base, stack, 128);
	if ((uint32_t)gameDB != 0) {
		uint32_t nameHolder = LOAD32((uint32_t)nameRef);
		uint64_t referencedName = (uint64_t)(int64_t)g_8209003F;
		if (nameHolder != 0) {
			referencedName = LOAD32(nameHolder);
		}
		const uint64_t kFnvOffsetBasis = 0xFFFFFFFF811C9DC5ull;
		r4AtReturn = kFnvOffsetBasis;
		ctx.r1.u64 = stack;
		uint64_t referencedNameHash = String_HashFnv1(ctx, base, referencedName, kFnvOffsetBasis);
		uint32_t nameList = LOAD32(self + 8);
		if (nameList != 0 && LOAD32(nameList + 4) != 0) {
			uint64_t listedName = (uint64_t)(int64_t)g_8209003F;
			if (nameList != 0) {
				listedName = LOAD32(nameList);
			}
			STORE32(stack + 80, 0u);
			uint64_t listedNameHash = String_HashFnv1(ctx, base, listedName, kFnvOffsetBasis);
			GameDB_ReadMappedU32Field(ctx, base, gameDB, listedNameHash, stack + 80);
			r4AtReturn = ctx.r4.u64;
			uint32_t mappedId = LOAD32(stack + 80);
			if (mappedId != 0) {
				uint32_t matchCount = n_sub_821C9EE0(ctx, base, mappedId, referencedNameHash);
				r4AtReturn = ctx.r4.u64;
				if (matchCount != 0) {
					isMatch = 1;
				}
			}
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4AtReturn;
	return isMatch;
}
PROMOTED_ENTRY(56, sub_827FFD38, 0x827FFD38) { ctx.r3.u64 = n_sub_827FFD38(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_827FFE08(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(56, 0x827FFE08)) { ctx.r3.u64 = randomNameVariantAddr; __imp__sub_827FFE08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827FFE08);
	uint32_t stack = ctx.r1.u64;

	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	stack = PushStackFrame(base, stack, 256);

	PPCRegister callTarget{};
	uint64_t result = randomNameVariantAddr;
	uint32_t entity = 0;
	uint32_t nameInfo = randomNameVariant->m_nameHash;

	// Values riding along into the virtual call below through r6-r9.
	uint64_t regR6 = ctx.r6.u64;
	uint64_t regR7 = ctx.r7.u64;
	uint64_t regR8 = ctx.r8.u64;
	uint64_t regR9 = (LOAD32(nameInfo + 44) >> 27) & 1;
	bool hasEntity = false;

	if ((uint32_t)regR9 != 0) {
		uint32_t entityIndex = LOAD32(nameInfo + 140);
		if (entityIndex != 0) {
			uint32_t slot = LOAD8(entityIndex + 91);
			regR9 = (uint64_t)slot * 8 + LOAD32(nameInfo + 72);
			entity = LOAD32((uint32_t)regR9 + 4);
			hasEntity = true;
		} else {
			uint32_t begin = LOAD32(nameInfo + 72);
			uint32_t end = LOAD32(nameInfo + 76);
			regR6 = end;
			STORE32(stack + 80, entity);
			int32_t count = (int32_t)(end - begin) >> 3;
			STORE32(stack + 84, begin);
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					regR9 = (int64_t)half;
					regR8 = (uint32_t)half << 3;
					uint32_t mid = begin + (uint32_t)regR8;
					regR7 = (int32_t)LOAD32(mid) < 91 ? 1 : entity;
					regR7 &= 0xFF;
					if (regR7 != 0) {
						count = count - half - 1;
						begin = mid + 8;
					} else {
						begin = mid - (uint32_t)regR8;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 91) {
				STORE64(stack + 88, LOAD64(stack + 80));
				entity = LOAD32(begin + 4);
			} else {
				entity = LOAD32(end + 4);
			}
			hasEntity = true;
		}
	}

	if (hasEntity) {
		uint32_t vtable = randomNameVariant->vtable;
		uint32_t vfunc = LOAD32(vtable + 20);
		callTarget.u64 = vfunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = randomNameVariantAddr;
		ctx.r6.u64 = regR6;
		ctx.r7.u64 = regR7;
		ctx.r8.u64 = regR8;
		ctx.r9.u64 = regR9;
		ctx.r10.u64 = vfunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t hasName = ctx.r3.u32 & 0xFF;
		vtable = randomNameVariant->vtable;

		if (hasName != 0) {
			vfunc = LOAD32(vtable + 24);
			callTarget.u64 = vfunc;
			ctx.r3.u64 = stack + 80;
			ctx.r4.u64 = randomNameVariantAddr;
			ctx.r9.u64 = hasName;
			ctx.r10.u64 = vfunc;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t nameHolder = ctx.r3.u32;

			uint32_t shouldReplicate = CECNetwork_ShouldReplicateEntity(ctx, base, entity);
			if ((shouldReplicate & 0xFF) != 0) {
				STORE32(stack + 96, 0x820A40C0u);
				uint32_t nameString = LOAD32(nameHolder);
				uint64_t nameChars;
				if (nameString == 0) {
					nameChars = g_8209003F;
				} else {
					nameChars = LOAD32(nameString);
				}
				strncpy(ctx, base, stack + 100, nameChars, 128);
				uint64_t uniqueId = Entity_GetUniqueId(ctx, base, LOAD32(entity + 4));
				uint32_t network = LOAD32(LOAD32((uint32_t)g_83490000 + 26912) + 12);
				Entity_PostBytesMessageWithFlag(ctx, base, LOAD32(network + 140), stack + 96, uniqueId);
				STORE32(stack + 96, 0x820A2BB8u);
			}
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		} else {
			vfunc = LOAD32(vtable + 4);
			callTarget.u64 = vfunc;
			ctx.r3.u64 = randomNameVariantAddr;
			ctx.r9.u64 = hasName;
			ctx.r10.u64 = vfunc;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t variantId = ctx.r3.u32;

			result = CECNetwork_ShouldReplicateEntity(ctx, base, entity);
			if ((result & 0xFF) != 0) {
				STORE32(stack + 92, variantId);
				STORE32(stack + 88, 0x820A40A8u);
				uint64_t uniqueId = Entity_GetUniqueId(ctx, base, LOAD32(entity + 4));
				int32_t networkGlobal = g_83490000;
				uint32_t network = LOAD32(LOAD32((uint32_t)networkGlobal + 26912) + 12);
				result = n_sub_8238AD80(ctx, base, LOAD32(network + 140), stack + 88, uniqueId);
			}
		}
	}

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(56, sub_827FFE08, 0x827FFE08) { ctx.r3.u64 = n_sub_827FFE08(ctx, base, ctx.r3.u64); }

// sub_82803380  [4 bytes]
uint64_t n_sub_82803380(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr) {
	if (!UseLiftedCode(56, 0x82803380)) { ctx.r3.u64 = randomNameVariantAddr; __imp__sub_82803380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82803380);
	uint64_t result = n_sub_827FFE08(ctx, base, randomNameVariantAddr);
	return result;
}
PROMOTED_ENTRY(56, sub_82803380, 0x82803380) { ctx.r3.u64 = n_sub_82803380(ctx, base, ctx.r3.u64); }

uint64_t CRandomNameVariant_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t randomNameVariantAddr, uint64_t arg2) {
	if (!UseLiftedCode(56, 0x82805EA8)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r4.u64 = arg2; __imp__sub_82805EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82805EA8);
	uint32_t stack = ctx.r1.u64;
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t deleteFlags = arg2;
	uint32_t data = randomNameVariant->m_data;
	if (data != 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2;
		CRandomNameVariant_DestructMembers(ctx, base, data);
		HandleTarget_Free(ctx, base, data);
		arg2 = ctx.r4.u64;
	}
	randomNameVariant->m_data = 0;
	uint32_t vtableSlot = 0;
	if ((uint32_t)randomNameVariantAddr != 0) {
		vtableSlot = (uint32_t)randomNameVariantAddr + 16;
	}
	STORE32(vtableSlot, 0x820EFB9Cu);
	randomNameVariant->vtable = 0x820D8FB0u;
	uint64_t charStringAddr = randomNameVariantAddr + 8;
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringAddr);
	if (uint32_t(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, randomNameVariantAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return randomNameVariantAddr;
}
PROMOTED_ENTRY(56, sub_82805EA8, 0x82805EA8) { ctx.r3.u64 = CRandomNameVariant_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82805F30(CpuState& ctx, uint8_t* base, uint32_t randomNameVariantAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(56, 0x82805F30)) { ctx.r3.u64 = randomNameVariantAddr; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; __imp__sub_82805F30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82805F30);
	CRandomNameVariant* randomNameVariant = GameObject<CRandomNameVariant>(base, randomNameVariantAddr);
	uint64_t variantData = randomNameVariant->m_data;
	uint64_t descriptionPtr = variantData + 24;
	uint64_t namePtr = variantData + 68;
	return n_sub_8219A800(ctx, base, descriptionPtr, namePtr, arg2, arg3, arg4);
}
PROMOTED_ENTRY(56, sub_82805F30, 0x82805F30) { ctx.r3.u64 = n_sub_82805F30(ctx, base, ctx.r3.u32, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t n_sub_82805F40(CpuState& ctx, uint8_t* base, uint64_t randomNameVariant, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(56, 0x82805F40)) { ctx.r3.u64 = randomNameVariant; ctx.r6.u64 = arg2; ctx.r7.u64 = arg3; ctx.r8.u64 = arg4; __imp__sub_82805F40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82805F40);
	uint32_t variantData = LOAD32((uint32_t)randomNameVariant + 0x14);
	return n_sub_828047D0(ctx, base, variantData, arg2, arg3, arg4);
}
PROMOTED_ENTRY(56, sub_82805F40, 0x82805F40) { ctx.r3.u64 = n_sub_82805F40(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

// sub_82805F48  [56 bytes]
uint64_t n_sub_82805F48(CpuState& ctx, uint8_t* base, uint64_t destinationString, uint32_t sourceVariant) {
	if (!UseLiftedCode(56, 0x82805F48)) { ctx.r3.u64 = destinationString; ctx.r4.u64 = sourceVariant; __imp__sub_82805F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82805F48);
	uint32_t stack = ctx.r1.u64;
	uint64_t sourceAddress{};
	stack = PushStackFrame(base, stack, 96);
	sourceAddress = (uint64_t)LOAD32(sourceVariant + 20) + 64;
	ctx.r1.u64 = stack;
	CCharString_CopyConstruct(ctx, base, destinationString, sourceAddress);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return destinationString;
}
PROMOTED_ENTRY(56, sub_82805F48, 0x82805F48) { ctx.r3.u64 = n_sub_82805F48(ctx, base, ctx.r3.u64, ctx.r4.u32); }
