// CECGraphicAppearance (vtable 0x82003A18): methods of the class as readable C++.
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

uint64_t n_sub_822B7EA8(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr, uint64_t newValue) {
	constexpr int32_t g_820BE2D4 = int32_t(0x820BE2D4);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(12, 0x822B7EA8)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.r4.u64 = newValue; __imp__sub_822B7EA8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B7EA8);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);

	stack = PushStackFrame(base, stack, 112);

	uint64_t currentValue = graphicAppearance->m_C4;
	// what callers find in r3, r4 and r10 after the call
	uint64_t result = graphicAppearanceAddr;
	uint64_t resultR4 = newValue;
	uint64_t resultR10 = currentValue;

	if ((uint32_t)(newValue & 0xFF) != (uint32_t)currentValue) {
		uint32_t oldFlags = graphicAppearance->m_90;
		graphicAppearance->m_C4 = (uint8_t)newValue;
		graphicAppearance->m_90 = oldFlags | 256;

		// When m_90 had no bits set, the entity (m_4) is also appended to the global entity list.
		if ((int32_t)oldFlags == 0) {
			uint32_t entity = graphicAppearance->m_4;
			uint32_t manager = LOAD32(g_83490000 + 26912);
			uint32_t managerChild = LOAD32(manager + 12);
			uint32_t listHolder = LOAD32(managerChild + 88);
			uint32_t listSlot = LOAD32(listHolder + 4);
			uint32_t entityList = LOAD32(listSlot);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r8.u64 = listSlot;
			EntityHandleList_PushBackEntity(ctx, base, entityList, entity);
		}

		// A temporary at stack+80: its first word is one value while n_sub_82202E90 runs and another afterwards.
		uint32_t tempAddr = stack + 80;
		uint32_t entity = graphicAppearance->m_4;
		uint64_t firstWordDuringCall = g_820BE2D4;
		STORE32(tempAddr, (uint32_t)firstWordDuringCall);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		n_sub_82202E90(ctx, base, entity, tempAddr);

		int32_t firstWordAfterBase = g_820F0000;
		int64_t firstWordAfterCall = (int64_t)firstWordAfterBase - 1124;
		STORE32(tempAddr, (uint32_t)firstWordAfterCall);
		// state the callee may pass on
		result = n_sub_82547FC0(ctx, base, graphicAppearanceAddr);
		resultR4 = ctx.r4.u64;
		resultR10 = ctx.r10.u64;
	}

	stack = PopStackFrame(stack, 112);
	// callers read r4 and r10 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = resultR4;
	ctx.r10.u64 = resultR10;
	return result;
}
PROMOTED_ENTRY(12, sub_822B7EA8, 0x822B7EA8) { ctx.r3.u64 = n_sub_822B7EA8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_822D91A8  [848 bytes]
uint64_t n_sub_822D91A8(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr) {
	constexpr int32_t g_822E0000 = int32_t(0x822E0000);
	if (!UseLiftedCode(13, 0x822D91A8)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_822D91A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D91A8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCCRRegister compare6{};
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t result = graphicAppearanceAddr;
	uint32_t appearanceType = graphicAppearance->m_CC;
	graphicAppearance->m_D0 = 1u;

	if (appearanceType <= 3) {
		// address the original dispatch left in r0; the callee may still observe it
		const uint32_t caseTarget = LOAD32(uint32_t(g_822E0000) - 28188 + (appearanceType << 2));
		switch (appearanceType) {
		case 0: {
			uint32_t entity = graphicAppearance->m_4;
			result = 0;
			// r6-r8 keep their incoming values unless the binary search below replaces them
			uint64_t searchEnd = ctx.r6.u64;
			uint64_t lastLess = ctx.r7.u64;
			uint64_t stepBytes = ctx.r8.u64;
			if ((LOAD32(entity + 52) & 0x1) != 0) {
				uint32_t indexArray = LOAD32(entity + 140);
				if (indexArray != 0) {
					result = LOAD32(LOAD32(entity + 72) + (uint32_t(LOAD8(indexArray + 128)) << 3) + 4);
				} else {
					uint32_t begin = LOAD32(entity + 72);
					searchEnd = LOAD32(entity + 76);
					STORE32(stack + 80, 0u);
					stepBytes = searchEnd - begin;
					STORE32(stack + 84, begin);
					flags.ca = (int32_t)stepBytes < 0 & (stepBytes & 0x7) != 0;
					int32_t count = (int32_t)stepBytes >> 3;
					if (count > 0) {
						// lower_bound for key 0x80 over 8-byte entries
						do {
							flags.ca = count < 0 & (count & 0x1) != 0;
							int32_t half = count >> 1;
							stepBytes = uint32_t(half << 3);
							begin = uint32_t(stepBytes) + begin;
							compare6.compare<int32_t>(int32_t(LOAD32(begin)), 128, flags);
							lastLess = compare6.lt ? 1 : 0;
							if (lastLess != 0) {
								count = count - half - 1;
								begin = begin + 8;
							} else {
								begin = begin - uint32_t(stepBytes);
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, begin);
					}
					if (begin != uint32_t(searchEnd)) {
						compare6.compare<int32_t>(int32_t(LOAD32(begin)), 128, flags);
						if (compare6.gt) {
							result = LOAD32(uint32_t(searchEnd) + 4);
						} else {
							STORE64(stack + 80, LOAD64(stack + 80));
							result = LOAD32(LOAD32(stack + 84) + 4);
						}
					} else {
						result = LOAD32(uint32_t(searchEnd) + 4);
					}
				}
				// state the callee may pass on
				ctx.r0.u64 = caseTarget;
				ctx.r1.u64 = stack;
				ctx.xer.ca = flags.ca;
				uint64_t resolved = n_sub_821D81C0(ctx, base, result, 1);
				if (uint32_t(resolved) != 0 && (LOAD8(uint32_t(resolved) + 144) & 64) != 0) {
					graphicAppearance->m_D0 = LOAD32(uint32_t(resolved) + 28) & 0x7FFFFFFF;
				} else {
					graphicAppearance->m_D0 = 1u;
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return resolved;
			}
			break;
		}
		case 1:
			break;
		case 2: {
			uint32_t entity = graphicAppearance->m_4;
			uint32_t entryAddr = 0;
			if ((LOAD32(entity + 44) & 0x1) != 0) {
				uint32_t indexArray = LOAD32(entity + 140);
				if (indexArray != 0) {
					entryAddr = LOAD32(LOAD32(entity + 72) + (uint32_t(LOAD8(indexArray + 64)) << 3) + 4);
				} else {
					uint32_t begin = LOAD32(entity + 72);
					uint32_t end = LOAD32(entity + 76);
					STORE32(stack + 80, 0u);
					uint32_t byteSpan = end - begin;
					STORE32(stack + 84, begin);
					flags.ca = (int32_t)byteSpan < 0 & (byteSpan & 0x7) != 0;
					int32_t count = (int32_t)byteSpan >> 3;
					if (count > 0) {
						// lower_bound for key 0x40 over 8-byte entries
						do {
							flags.ca = count < 0 & (count & 0x1) != 0;
							int32_t half = count >> 1;
							uint32_t halfBytes = half << 3;
							begin = halfBytes + begin;
							compare6.compare<int32_t>(int32_t(LOAD32(begin)), 64, flags);
							if (compare6.lt) {
								count = count - half - 1;
								begin = begin + 8;
							} else {
								begin = begin - halfBytes;
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, begin);
					}
					if (begin != end) {
						compare6.compare<int32_t>(int32_t(LOAD32(begin)), 64, flags);
						if (compare6.gt) {
							entryAddr = LOAD32(end + 4);
						} else {
							STORE64(stack + 80, LOAD64(stack + 80));
							entryAddr = LOAD32(LOAD32(stack + 84) + 4);
						}
					} else {
						entryAddr = LOAD32(end + 4);
					}
				}
				// state the callee may pass on
				ctx.r0.u64 = caseTarget;
				ctx.r1.u64 = stack;
				ctx.xer.ca = flags.ca;
				n_sub_828ABBA0(ctx, base, uint64_t(entryAddr));
				uint64_t handle = uint64_t(entryAddr) + 12;
				uint32_t handleRef = LOAD32(entryAddr + 16);
				uint32_t object = 0;
				if (handleRef != 0) {
					object = LOAD32(handleRef);
					if (object == 0) {
						// state the callee may pass on (the zero object word)
						handle = EntityHandle_Release(ctx, base, handle);
					}
				}
				if (object != 0 && (LOAD8(object + 144) & 64) != 0) {
					graphicAppearance->m_D0 = LOAD32(object + 28) & 0x7FFFFFFF;
				} else {
					graphicAppearance->m_D0 = 1u;
				}
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return handle;
			}
			break;
		}
		case 3:
			graphicAppearance->m_D0 = 0u;
			break;
		default:
			__builtin_trap();
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(13, sub_822D91A8, 0x822D91A8) { ctx.r3.u64 = n_sub_822D91A8(ctx, base, ctx.r3.u64); }

// sub_82546958  [60 bytes]
uint64_t CECGraphicAppearance_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BDEEC_B_ = int32_t(0x820BDEEC);
	if (!UseLiftedCode(33, 0x82546958)) { ctx.r3.u64 = classNameString; __imp__sub_82546958(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82546958);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820BDEEC_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(33, sub_82546958, 0x82546958) { ctx.r3.u64 = CECGraphicAppearance_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82546D50(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr, uint64_t gameDbTable) {
	constexpr int32_t str_TXT_820BDF04_B_ = int32_t(0x820BDF04);
	constexpr int32_t str_TXT_820BDF14_B_ = int32_t(0x820BDF14);
	constexpr int32_t str_TXT_820BDF28_B_ = int32_t(0x820BDF28);
	constexpr int32_t str_TXT_820BDF3C_B_ = int32_t(0x820BDF3C);
	constexpr int32_t str_TXT_820BDF4C_B_ = int32_t(0x820BDF4C);
	constexpr int32_t str_TXT_820BDF6C_B_ = int32_t(0x820BDF6C);
	constexpr int32_t str_TXT_820BDF84_B_ = int32_t(0x820BDF84);
	constexpr int32_t str_TXT_820BDFA8_B_ = int32_t(0x820BDFA8);
	constexpr int32_t str_TXT_820BDFC0_B_ = int32_t(0x820BDFC0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x82546D50)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.r4.u64 = gameDbTable; __imp__sub_82546D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82546D50);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	DrawDistanceParams_LoadFromTable(ctx, base, graphicAppearanceAddr, gameDbTable);

	// Append the appearance's entity (m_4) to the global entity list.
	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t entityListSlot = LOAD32(LOAD32(LOAD32(manager + 12) + 88) + 4);
	uint32_t entityList = LOAD32(entityListSlot);
	uint32_t entity = graphicAppearance->m_4;
	// state the callee may pass on
	ctx.r8.u64 = entityListSlot;
	uint64_t result = EntityHandleList_PushBackEntity(ctx, base, entityList, entity);

	if (uint32_t(gameDbTable) != 0) {
		graphicAppearance->m_C6 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, gameDbTable, str_TXT_820BDF04_B_);

		GameDB_GetFloatByName(ctx, base, gameDbTable, str_TXT_820BDF14_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_78 = (float)ctx.f1.f64;

		GameDB_GetFloatByName(ctx, base, gameDbTable, str_TXT_820BDF28_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_7C = (float)ctx.f1.f64;

		// the FNV-1 offset basis, sign-extended to 64 bits
		uint64_t lightZoneModeHash = String_HashFnv1(ctx, base, str_TXT_820BDF3C_B_, 0xFFFFFFFF811C9DC5ull);
		uint32_t lightZoneModeField = GameDB_FindFieldValue(ctx, base, gameDbTable, lightZoneModeHash, 2);
		if (lightZoneModeField != 0) {
			graphicAppearance->m_CC = LOAD32(lightZoneModeField);
		}

		uint32_t enableShadowCulling = GameDB_ReadBoolField_82303F38(ctx, base, gameDbTable, str_TXT_820BDF4C_B_);
		uint32_t renderFlags = graphicAppearance->m_8C;
		if ((enableShadowCulling & 0xFF) != 0) {
			renderFlags |= 0x8000;
		} else {
			renderFlags &= ~0x8000u;
		}
		graphicAppearance->m_8C = renderFlags;

		graphicAppearance->m_C0 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, gameDbTable, str_TXT_820BDF6C_B_);
		graphicAppearance->m_C1 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, gameDbTable, str_TXT_820BDF84_B_);
		graphicAppearance->m_C2 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, gameDbTable, str_TXT_820BDFA8_B_);

		// stack slot handed to GameDB_ReadFloatField, preset to a default
		uint32_t cutoffRangeAddr = stack + 80;
		ctx.fpscr.disableFlushMode();
		STORE_F32(cutoffRangeAddr, LOAD_F32(0x8209DE04u));
		result = GameDB_ReadFloatField(ctx, base, gameDbTable, str_TXT_820BDFC0_B_, cutoffRangeAddr);
		if ((uint32_t(result) & 0xFF) != 0) {
			ctx.fpscr.disableFlushMode();
			float cutoffRange = LOAD_F32(cutoffRangeAddr);
			graphicAppearance->m_80 = cutoffRange * cutoffRange;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82546D50, 0x82546D50) { ctx.r3.u64 = n_sub_82546D50(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82546EE0  [296 bytes]
uint64_t n_sub_82546EE0(CpuState& ctx, uint8_t* base, uint64_t pAppearance, uint64_t pStream, uint32_t version) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820B0B48_B_ = int32_t(0x820B0B48);
	constexpr int32_t str_TXT_820BDFD8_B_ = int32_t(0x820BDFD8);
	constexpr int32_t str_TXT_820BDFE4_B_ = int32_t(0x820BDFE4);
	constexpr int32_t str_TXT_820BDFF4_B_ = int32_t(0x820BDFF4);
	constexpr int32_t str_TXT_820BDFFC_B_ = int32_t(0x820BDFFC);
	if (!UseLiftedCode(33, 0x82546EE0)) { ctx.r3.u64 = pAppearance; ctx.r4.u64 = pStream; ctx.r5.u64 = version; __imp__sub_82546EE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82546EE0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// what callers find in r3 and r4 after the call
	uint64_t result = pAppearance;
	uint64_t resultR4 = pStream;
	if ((int32_t)version == 1) {
		// Scratch CCharString at stack+80, rebuilt with the name of each serialized field.
		const uint64_t nameString = (uint64_t)stack + 80;
		// r4 for the float serializer: the word the name's data pointer points at, or 0x8209003F without data.
		const uint64_t noNameData = (uint64_t)(int64_t)g_8209003F;

		ctx.r1.u64 = stack;
		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820B0B48_B_, -1);
		uint32_t alphaNameData = LOAD32(nameString);
		// state the callee may pass on
		ctx.r4.u64 = (alphaNameData != 0) ? (uint64_t)LOAD32(alphaNameData) : noNameData;
		IStream_SerializeFloat(ctx, base, pStream, pAppearance + 112);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820BDFD8_B_, -1);
		n_sub_82A17140(ctx, base, nameString, pStream, pAppearance + 80);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820BDFE4_B_, -1);
		IStream_SerializeString(ctx, base, nameString, pStream, pAppearance + 196);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820BDFF4_B_, -1);
		uint32_t scaleNameData = LOAD32(nameString);
		// state the callee may pass on
		ctx.r4.u64 = (scaleNameData != 0) ? (uint64_t)LOAD32(scaleNameData) : noNameData;
		IStream_SerializeFloat(ctx, base, pStream, pAppearance + 108);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

		CCharString_ConstructFromCStr(ctx, base, nameString, str_TXT_820BDFFC_B_, -1);
		IStream_SerializeString(ctx, base, nameString, pStream, pAppearance + 202);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
		resultR4 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	// callers read r4 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = resultR4;
	return result;
}
PROMOTED_ENTRY(33, sub_82546EE0, 0x82546EE0) { ctx.r3.u64 = n_sub_82546EE0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_82547008(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x82547008)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_82547008(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82547008);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 144);

	// Walk the list at +0xD8 (its head node is in m_DC) with a checked iterator, the pair (list, node) kept at
	// stack+80: BreakablePieceList_RemoveById gets the global piece list and node + 16, then n_sub_8254A998
	// takes the iterator and returns the address of the next one.
	const uint64_t listAddr = graphicAppearanceAddr + 216;
	uint32_t iterList = uint32_t(listAddr);
	uint32_t iterNode = graphicAppearance->m_DC;

	STORE32(stack + 80, iterList);
	iterNode = LOAD32(iterNode);
	STORE32(stack + 84, iterNode);
	uint64_t iterator = LOAD64(stack + 80);

	for (;;) {
		uint32_t headNode = LOAD32(uint32_t(listAddr) + 4);
		if (iterList == 0 || iterList != uint32_t(listAddr)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (iterNode == headNode) break;

		if (iterList == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (iterNode == LOAD32(iterList + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t pieceList = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
		ctx.r1.u64 = stack;
		BreakablePieceList_RemoveById(ctx, base, pieceList, uint64_t(iterNode) + 16);

		uint32_t nextIteratorAddr = n_sub_8254A998(ctx, base, stack + 88, listAddr, iterator);
		iterator = LOAD64(nextIteratorAddr);
		STORE64(stack + 80, iterator);
		iterNode = LOAD32(stack + 84);
		iterList = LOAD32(stack + 80);
	}

	graphicAppearance->m_E4 = uint8_t(1);
	ctx.r1.u64 = stack;
	CECGraphicAppearance_ForEach(ctx, base, graphicAppearanceAddr);

	Eyes_Release(ctx, base, graphicAppearanceAddr + 28);
	uint64_t result = Eyes_Release(ctx, base, graphicAppearanceAddr + 32);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82547008, 0x82547008) { ctx.r3.u64 = n_sub_82547008(ctx, base, ctx.r3.u64); }

uint64_t n_sub_825470D8(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr) {
	if (!UseLiftedCode(33, 0x825470D8)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_825470D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825470D8);
	return n_sub_822D91A8(ctx, base, graphicAppearanceAddr);
}
PROMOTED_ENTRY(33, sub_825470D8, 0x825470D8) { ctx.r3.u64 = n_sub_825470D8(ctx, base, ctx.r3.u64); }

uint64_t DrawDistanceParams_LoadFromTable(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr, uint64_t drawDistanceTable) {
	constexpr int32_t str_TXT_820BE00C_B_ = int32_t(0x820BE00C);
	constexpr int32_t str_TXT_820BE01C_B_ = int32_t(0x820BE01C);
	constexpr int32_t str_TXT_820BE038_B_ = int32_t(0x820BE038);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820BE04C_B_ = str_TXT_820C0000_B_ - 8116;
	constexpr int32_t str_TXT_820BE060_B_ = str_TXT_820C0000_B_ - 8096;
	constexpr int32_t str_TXT_820BE06C_B_ = str_TXT_820C0000_B_ - 8084;
	constexpr int32_t str_TXT_820BE07C_B_ = str_TXT_820C0000_B_ - 8068;
	constexpr int32_t str_TXT_820BDF28_B_ = str_TXT_820C0000_B_ - 8408;
	if (!UseLiftedCode(33, 0x825470E0)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.r4.u64 = drawDistanceTable; __imp__sub_825470E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825470E0);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t entityFlags = LOAD32(graphicAppearance->m_4 + 36);

	// Bits 6, 20 and 26 of the entity's flags word pick the factor applied to TXT_820BE00C_B_.
	double distanceScale;
	if ((entityFlags >> 6) & 1) {
		if ((entityFlags >> 20) & 1) {
			if ((entityFlags >> 26) & 1) {
				distanceScale = double(LOAD_F32(0x83319370u));
			} else {
				ctx.fpscr.disableFlushMode();
				distanceScale = double(LOAD_F32(0x83319374u));
			}
		} else {
			ctx.fpscr.disableFlushMode();
			distanceScale = double(LOAD_F32(0x8331936Cu));
		}
	} else {
		ctx.fpscr.disableFlushMode();
		distanceScale = double(LOAD_F32(0x83319368u));
	}

	// what callers find in r3 and r4 after the call
	uint64_t result = graphicAppearanceAddr;
	uint64_t resultR4 = drawDistanceTable;
	if ((uint32_t)drawDistanceTable != 0) {
		ctx.r1.u64 = stack;
		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE00C_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_28 = float(ctx.f1.f64 * distanceScale);

		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE01C_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_24 = float(ctx.f1.f64);

		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE038_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_2C = float(ctx.f1.f64);

		// state the callee may pass on (the string base, left in r8, then r7, r6 and r5)
		ctx.r8.s64 = str_TXT_820C0000_B_;
		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE04C_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_30 = float(ctx.f1.f64);

		ctx.r7.s64 = str_TXT_820C0000_B_;
		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE060_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_34 = float(ctx.f1.f64);

		ctx.r6.s64 = str_TXT_820C0000_B_;
		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE06C_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_38 = float(ctx.f1.f64);

		ctx.r5.s64 = str_TXT_820C0000_B_;
		GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BE07C_B_);
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_3C = float(ctx.f1.f64);

		result = GameDB_GetFloatByName(ctx, base, drawDistanceTable, str_TXT_820BDF28_B_);
		resultR4 = ctx.r4.u64;
		ctx.fpscr.disableFlushMode();
		graphicAppearance->m_48 = float(ctx.f1.f64);
	}

	// TXT_820BE00C_B_ has a lower bound, and the billboard distance may not exceed it.
	ctx.fpscr.disableFlushMode();
	const float minTXT_820BE00C_B_ = LOAD_F32(0x820994B4u);
	if (!(graphicAppearance->m_28 > minTXT_820BE00C_B_)) {
		graphicAppearance->m_28 = minTXT_820BE00C_B_;
	}
	ctx.fpscr.disableFlushMode();
	const float TXT_820BE00C_L_ = graphicAppearance->m_28;
	if (TXT_820BE00C_L_ < graphicAppearance->m_30) {
		graphicAppearance->m_30 = TXT_820BE00C_L_;
	}

	stack = PopStackFrame(stack, 112);
	// callers read r4 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = resultR4;
	return result;
}
PROMOTED_ENTRY(33, sub_825470E0, 0x825470E0) { ctx.r3.u64 = DrawDistanceParams_LoadFromTable(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82547250(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr, uint64_t newState) {
	constexpr int32_t g_820C0000 = int32_t(0x820C0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x82547250)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.r4.u64 = newState; __imp__sub_82547250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82547250);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t oldState = graphicAppearance->m_C5;
	if (oldState == ((uint32_t)newState & 0xFF)) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r4 and r10 after the call
		ctx.r4.u64 = newState;
		ctx.r10.u64 = oldState;
		return graphicAppearanceAddr;
	}

	const uint32_t oldFlags = graphicAppearance->m_90;
	graphicAppearance->m_C5 = (uint8_t)newState;
	if ((oldFlags & 128) == 0) {
		ctx.r1.u64 = stack;
		ctx.r4.u64 = newState;
		CECGraphicAppearance_ForEach(ctx, base, graphicAppearanceAddr);
	}
	const uint32_t globalBase = (uint32_t)g_83490000;
	graphicAppearance->m_90 = graphicAppearance->m_90 | 128;
	if (oldFlags == 0) {
		const uint32_t entity = graphicAppearance->m_4;
		const uint32_t manager = LOAD32(globalBase + 26912);
		const uint32_t owner = LOAD32(manager + 12);
		const uint32_t holder = LOAD32(owner + 88);
		const uint32_t slot = LOAD32(holder + 4);
		const uint32_t entityList = LOAD32(slot);
		ctx.r1.u64 = stack;
		EntityHandleList_PushBackEntity(ctx, base, entityList, entity);
	}

	// Temporary object at stack+80: vtable 0x820BE2B0 (0x820C0000 - 7504), then the new state byte.
	const uint32_t stateByte = graphicAppearance->m_C5;
	const uint32_t targetEntity = graphicAppearance->m_4;
	const uint64_t tempObjectAddr = uint64_t(stack) + 80;
	const uint64_t tempVtable = (int64_t)g_820C0000 - 7504;
	STORE32(stack + 80, (uint32_t)tempVtable);
	STORE8(stack + 84, (uint8_t)stateByte);
	ctx.r1.u64 = stack;
	n_sub_82202E90(ctx, base, targetEntity, tempObjectAddr);

	// Back to the base vtable 0x820EFB9C once the object is done with.
	const uint32_t currentState = graphicAppearance->m_C5;
	const uint64_t baseVtable = (int64_t)g_820F0000 - 1124;
	STORE32(stack + 80, (uint32_t)baseVtable);
	// state n_sub_82547FC0 (and the push-back below) may read; after the push-back r6-r8 are what it left
	ctx.r6.u64 = currentState;
	ctx.r7.u64 = baseVtable;
	ctx.r8.s64 = g_820F0000;
	if (currentState != 0) {
		const uint32_t entity = graphicAppearance->m_4;
		const uint32_t manager = LOAD32(globalBase + 26912);
		const uint32_t owner = LOAD32(manager + 12);
		const uint32_t holder = LOAD32(owner + 88);
		const uint32_t slot = LOAD32(holder + 4);
		const uint32_t entityList = LOAD32(slot);
		EntityHandleList_PushBackEntity(ctx, base, entityList, entity);
	}
	// r4 and r10 for our callers are what this call leaves in them
	const uint64_t result = n_sub_82547FC0(ctx, base, graphicAppearanceAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82547250, 0x82547250) { ctx.r3.u64 = n_sub_82547250(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82547320(CpuState& ctx, uint8_t* base, uint32_t graphicAppearanceAddr, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(33, 0x82547320)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82547320(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82547320);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 128);

	// Left for callers: r4/r5 (the arguments until an entry is called, then what the last call left)
	// and r9 (the incoming r9, then the last call's result byte, which is also handed to the next call).
	uint64_t r4Value = arg2;
	uint64_t r5Value = arg3;
	uint64_t r9Value = ctx.r9.u64;

	// Asks each entry of the list at +12 (sentinel node pointer m_10) through its virtual method at +36
	// and stops at the first nonzero answer. Trap 22: the game's checked-iterator failure, re-tested on
	// fresh loads of m_10.
	uint32_t node = LOAD32(graphicAppearance->m_10);
	while (node != graphicAppearance->m_10) {
		if (node == graphicAppearance->m_10) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t entry = LOAD32(node + 8);
		const uint32_t method = LOAD32(LOAD32(entry) + 36);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = entry;
		ctx.r4.u64 = arg2;
		ctx.r5.u64 = arg3;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		r4Value = ctx.r4.u64;
		r5Value = ctx.r5.u64;
		r9Value = ctx.r3.u32 & 0xFF;
		if (r9Value != 0) {
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			ctx.r9.u64 = r9Value;
			return 1;
		}
		if (node == graphicAppearance->m_10) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r5.u64 = r5Value;
	ctx.r9.u64 = r9Value;
	return 0;
}
PROMOTED_ENTRY(33, sub_82547320, 0x82547320) { ctx.r3.u64 = n_sub_82547320(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_825473C0(CpuState& ctx, uint8_t* base, uint32_t graphicAppearanceAddr) {
	if (!UseLiftedCode(33, 0x825473C0)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_825473C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825473C0);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 128);

	// m_88 caches the sum of what the entries of the list at +12 (sentinel node pointer m_10) return from
	// their virtual method at +32; a negative m_88 means it is not computed yet.
	// Trap 22: the game's checked-iterator failure, re-tested on fresh loads of m_10.
	if (int32_t(graphicAppearance->m_88) < 0) {
		// r9 handed to each call: the incoming r9, then m_10 as reloaded after the previous call
		uint64_t r9Value = ctx.r9.u64;
		uint32_t total = 0;
		uint32_t node = LOAD32(graphicAppearance->m_10);
		while (node != graphicAppearance->m_10) {
			if (node == graphicAppearance->m_10) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t entry = LOAD32(node + 8);
			const uint32_t method = LOAD32(LOAD32(entry) + 32);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = entry;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
			total += ctx.r3.u32;
			r9Value = graphicAppearance->m_10;
			if (node == (uint32_t)r9Value) {
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
		}
		graphicAppearance->m_88 = total;
	}

	const uint32_t result = graphicAppearance->m_88;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_825473C0, 0x825473C0) { ctx.r3.u64 = n_sub_825473C0(ctx, base, ctx.r3.u32); }

uint64_t CECGraphicAppearance_ForEach(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr) {
	if (!UseLiftedCode(33, 0x82547590)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_82547590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82547590);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Calls the virtual method at +8 of every entry of the list at +12, whose sentinel node pointer is
	// at +16. The iterator (list, node) lives at stack+80. Trap 22: the game's checked-iterator failure.
	const uint32_t list = (uint32_t)graphicAppearanceAddr + 12;
	const uint32_t sentinel = LOAD32(list + 4);
	STORE32(stack + 80, list);
	STORE32(stack + 84, LOAD32(sentinel));
	const uint64_t iteratorPair = LOAD64(stack + 80);
	STORE64(stack + 80, iteratorPair);
	const uint32_t iteratorList = LOAD32(stack + 80);
	uint32_t node = LOAD32(stack + 84);

	// r9 handed to each call and left for callers: the iterator pair, then the sentinel pointer
	// reloaded after the previous call
	uint64_t r9Value = iteratorPair;
	uint64_t result = graphicAppearanceAddr;
	for (;;) {
		const uint32_t end = LOAD32(list + 4);
		if (iteratorList == 0 || iteratorList != list) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == end) break;
		if (iteratorList == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iteratorList + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		const uint32_t entry = LOAD32(node + 8);
		const uint32_t method = LOAD32(LOAD32(entry) + 8);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = entry;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		result = ctx.r3.u64;

		r9Value = LOAD32(iteratorList + 4);
		if (node == (uint32_t)r9Value) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Value;
	return result;
}
PROMOTED_ENTRY(33, sub_82547590, 0x82547590) { ctx.r3.u64 = CECGraphicAppearance_ForEach(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82547EC8(CpuState& ctx, uint8_t* base, uint64_t graphicAppearanceAddr, double targetAlpha) {
	constexpr int32_t g_820BE2BC = int32_t(0x820BE2BC);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x82547EC8)) { ctx.r3.u64 = graphicAppearanceAddr; ctx.f1.f64 = targetAlpha; __imp__sub_82547EC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82547EC8);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	stack = PushStackFrame(base, stack, 128);

	// m_70 is the alpha (n_sub_82546EE0 serializes it under that name).
	const double currentAlpha = double(graphicAppearance->m_70);
	if (targetAlpha == currentAlpha) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read f1 and f13 after the call
		ctx.f1.f64 = targetAlpha;
		ctx.f13.f64 = currentAlpha;
		return graphicAppearanceAddr;
	}

	// f1 and f13 reach the callees through the register state; after a call they hold what it left.
	double f1Value = targetAlpha;
	double f13Value = currentAlpha;

	const double alphaThreshold = double(LOAD_F32(0x82099AE0u));
	const uint32_t oldFlags = graphicAppearance->m_90;
	if (targetAlpha < alphaThreshold || currentAlpha < alphaThreshold) {
		if ((oldFlags & 128) == 0) {
			ctx.r1.u64 = stack;
			ctx.f1.f64 = f1Value;
			ctx.f13.f64 = f13Value;
			CECGraphicAppearance_ForEach(ctx, base, graphicAppearanceAddr);
			f1Value = ctx.f1.f64;
			f13Value = ctx.f13.f64;
		}
		graphicAppearance->m_90 = graphicAppearance->m_90 | 128;
	} else {
		graphicAppearance->m_90 = oldFlags | 16;
	}

	if (oldFlags == 0) {
		const uint32_t entity = graphicAppearance->m_4;
		const uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
		const uint32_t owner = LOAD32(manager + 12);
		const uint32_t holder = LOAD32(owner + 88);
		const uint32_t slot = LOAD32(holder + 4);
		const uint32_t entityList = LOAD32(slot);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = slot;
		ctx.r9.u64 = holder;
		ctx.r10.u64 = owner;
		ctx.f1.f64 = f1Value;
		ctx.f13.f64 = f13Value;
		EntityHandleList_PushBackEntity(ctx, base, entityList, entity);
		f1Value = ctx.f1.f64;
	}

	ctx.fpscr.disableFlushMode();
	const double scaledAlpha = double(float(double(graphicAppearance->m_74) * targetAlpha));
	graphicAppearance->m_70 = float(targetAlpha);

	// Temporary object at stack+80: vtable 0x820BE2BC, then the scaled alpha.
	const uint32_t targetEntity = graphicAppearance->m_4;
	const uint64_t tempObjectAddr = uint64_t(stack) + 80;
	const uint64_t tempVtable = g_820BE2BC;
	STORE32(stack + 80, (uint32_t)tempVtable);
	STORE_F32(stack + 84, float(scaledAlpha));
	ctx.r1.u64 = stack;
	ctx.r10.u64 = tempVtable;
	ctx.f1.f64 = f1Value;
	ctx.f13.f64 = scaledAlpha;
	n_sub_82202E90(ctx, base, targetEntity, tempObjectAddr);

	// Back to the base vtable 0x820EFB9C once the object is done with.
	const uint64_t baseVtable = (int64_t)g_820F0000 - 1124;
	STORE32(stack + 80, (uint32_t)baseVtable);
	ctx.r8.u64 = baseVtable;
	ctx.r9.s64 = g_820F0000;
	// f1 and f13 for our callers are what this call leaves in them
	const uint64_t result = n_sub_82547FC0(ctx, base, graphicAppearanceAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82547EC8, 0x82547EC8) { ctx.r3.u64 = n_sub_82547EC8(ctx, base, ctx.r3.u64, ctx.f1.f64); }

uint64_t n_sub_82547FC0(CpuState& ctx, uint8_t* base, uint32_t graphicAppearanceAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(33, 0x82547FC0)) { ctx.r3.u64 = graphicAppearanceAddr; __imp__sub_82547FC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82547FC0);
	uint32_t stack = ctx.r1.u64;
	CECGraphicAppearance* graphicAppearance = GameObject<CECGraphicAppearance>(base, graphicAppearanceAddr);
	// Left for callers in r8, cr0 and XER[CA] (and handed to the callees that read them): r8 starts as the
	// owner pointer and cr0/XER as on entry; the search below and the calls to n_sub_8254AB88 and
	// Entity_PostFloatMessageWithFlag update them.
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;
	stack = PushStackFrame(base, stack, 176);

	const uint32_t entity = graphicAppearance->m_4;
	const uint32_t owner = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	const uint32_t messageTarget = LOAD32(owner + 140);
	uint64_t r8Value = owner;
	uint64_t result = 0;

	// The entity's component of type 91 (the type Entity_GetUniqueId reads), when its presence bit is
	// set: looked up through the per-type index table at +140 when there is one, else by binary search of
	// the (type, component) pairs sorted by type in [+72, +76).
	if (((LOAD32(entity + 44) >> 27) & 1) != 0) {
		uint32_t component91;
		const uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			component91 = LOAD32(LOAD32(entity + 72) + LOAD8(indexTable + 91) * 8u + 4);
		} else {
			const uint32_t pairsEnd = LOAD32(entity + 76);
			uint32_t pair = LOAD32(entity + 72);
			STORE32(stack + 80, 0u);
			STORE32(stack + 84, pair);
			const uint32_t byteCount = pairsEnd - pair;
			xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			cr0.compare<int32_t>(count, 0, xer);
			if (count > 0) {
				do {
					const int32_t half = count >> 1;
					const uint32_t step = uint32_t(half) << 3;
					r8Value = step;
					if ((int32_t)LOAD32(pair + step) < 91) {
						pair += step + 8;
						count -= half + 1;
					} else {
						count = half;
					}
				} while (count > 0);
				xer.ca = 0;  // halving a positive count leaves CA clear
				STORE32(stack + 84, pair);
			}
			if (pair != pairsEnd && !((int32_t)LOAD32(pair) > 91)) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component91 = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				// not found: the game reads the component slot at the end pointer
				component91 = LOAD32(pairsEnd + 4);
			}
		}

		ctx.r1.u64 = stack;
		ctx.xer.ca = xer.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, component91);
		if ((result & 0xFF) != 0) {
			// Temporary object at stack+112: vtable 0x820A4808, alpha (m_70), scale (m_6C), three floats of the
			// 16-byte tint block at +80, state (m_C5) and saturation mask (m_C4). The tint goes through the stack.
			const uint8_t state = graphicAppearance->m_C5;
			const uint8_t TXT_820BDFE4_L_ = graphicAppearance->m_C4;
			ctx.fpscr.disableFlushMode();
			const float TXT_820B0B48_L_ = graphicAppearance->m_70;
			const double TXT_820BDFF4_L_ = double(graphicAppearance->m_6C);
			PPCVRegister tint{};
			STORE_F32(stack + 116, TXT_820B0B48_L_);
			SET_V8(tint, VLOAD((graphicAppearanceAddr + 80u) & ~0xF));
			STORE8(stack + 136, state);
			VSTORE(uint32_t(stack + 96) & ~0xF, V8(tint));
			const double tint0 = double(LOAD_F32(stack + 96));
			STORE8(stack + 137, TXT_820BDFE4_L_);
			VSTORE(uint32_t(stack + 96) & ~0xF, V8(tint));
			STORE32(stack + 112, 0x820A4808u);
			const double tint1 = double(LOAD_F32(stack + 100));
			VSTORE(uint32_t(stack + 80) & ~0xF, V8(tint));
			const double tint2 = double(LOAD_F32(stack + 88));
			STORE_F32(stack + 120, float(TXT_820BDFF4_L_));
			STORE_F32(stack + 124, float(tint0));
			STORE_F32(stack + 132, float(tint2));
			STORE_F32(stack + 128, float(tint1));

			ctx.cr0 = cr0;
			const uint64_t uniqueId = Entity_GetUniqueId(ctx, base, entity);
			result = n_sub_8254AB88(ctx, base, messageTarget, uint64_t(stack) + 112, uniqueId);
			r8Value = ctx.r8.u64;
			cr0 = ctx.cr0;
			xer.ca = ctx.xer.ca;
			STORE32(stack + 112, 0x820A2BB8u);
		}
	}

	if (LOAD8(messageTarget + 52) != 0 && LOAD8(messageTarget + 53) != 0) {
		// Temporary object at stack+80: vtable 0x820A4820, then m_74.
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 84, float(graphicAppearance->m_74));
		STORE32(stack + 80, 0x820A4820u);
		ctx.r1.u64 = stack;
		ctx.cr0 = cr0;
		ctx.xer.ca = xer.ca;
		const uint64_t uniqueId = Entity_GetUniqueId(ctx, base, graphicAppearance->m_4);
		result = Entity_PostFloatMessageWithFlag(ctx, base, messageTarget, uint64_t(stack) + 80, uniqueId);
		r8Value = ctx.r8.u64;
		cr0 = ctx.cr0;
		xer.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Value;
	ctx.cr0 = cr0;
	ctx.xer.ca = xer.ca;
	return result;
}
PROMOTED_ENTRY(33, sub_82547FC0, 0x82547FC0) { ctx.r3.u64 = n_sub_82547FC0(ctx, base, ctx.r3.u32); }

uint64_t n_sub_825486C0(CpuState& ctx, uint8_t* base, uint64_t appearance, uint32_t holder) {
	if (!UseLiftedCode(33, 0x825486C0)) { ctx.r3.u64 = appearance; ctx.r4.u64 = holder; __imp__sub_825486C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825486C0);
	uint32_t stack = ctx.r1.u64;
	// r6-r8 and XER[CA] reach n_sub_82547250 through the register state: the incoming values, or what
	// the binary search below leaves in them.
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	PPCXERRegister xer = ctx.xer;
	stack = PushStackFrame(base, stack, 112);

	// The component of type 3 of the entity at holder+4, when the entity has flag 0x40 at +144 and the
	// presence bit for type 3: looked up through the per-type index table at +140 when there is one, else
	// by binary search of the (type, component) pairs sorted by type in [+72, +76).
	const uint32_t entity = LOAD32(holder + 4);
	if (entity == 0 || (LOAD8(entity + 144) & 64) == 0 || ((LOAD32(entity + 36) >> 3) & 1) == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return appearance;
	}
	uint32_t sourceAddr;
	const uint32_t indexTable = LOAD32(entity + 140);
	if (indexTable != 0) {
		sourceAddr = LOAD32(LOAD32(entity + 72) + LOAD8(indexTable + 3) * 8u + 4);
	} else {
		const uint32_t pairsEnd = LOAD32(entity + 76);
		uint32_t pair = LOAD32(entity + 72);
		r6Value = pairsEnd;
		STORE32(stack + 80, 0u);
		STORE32(stack + 84, pair);
		const uint32_t byteCount = pairsEnd - pair;
		xer.ca = (int32_t)byteCount < 0 && (byteCount & 7) != 0;
		int32_t count = (int32_t)byteCount >> 3;
		if (count > 0) {
			do {
				const int32_t half = count >> 1;
				const uint32_t step = uint32_t(half) << 3;
				const bool below = (int32_t)LOAD32(pair + step) < 3;
				r7Value = below ? 1 : 0;
				r8Value = step;
				if (below) {
					pair += step + 8;
					count -= half + 1;
				} else {
					count = half;
				}
			} while (count > 0);
			xer.ca = 0;  // halving a positive count leaves CA clear
			STORE32(stack + 84, pair);
		}
		if (pair != pairsEnd && !((int32_t)LOAD32(pair) > 3)) {
			STORE64(stack + 80, LOAD64(stack + 80));
			sourceAddr = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			// not found: the game reads the component slot at the end pointer
			sourceAddr = LOAD32(pairsEnd + 4);
		}
	}

	// The component is laid out as a CECGraphicAppearance; its state (m_C5), m_74 * m_70 as the alpha,
	// the block at +96 and its saturation mask (m_C4) are applied to this appearance.
	CECGraphicAppearance* source = GameObject<CECGraphicAppearance>(base, sourceAddr);
	const uint8_t sourceState = source->m_C5;
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8Value;
	ctx.xer.ca = xer.ca;
	n_sub_82547250(ctx, base, appearance, sourceState);
	ctx.fpscr.disableFlushMode();
	const double sourceAlpha = double(float(double(source->m_74) * double(source->m_70)));
	n_sub_82547EC8(ctx, base, appearance, sourceAlpha);
	n_sub_82548598(ctx, base, appearance, uint64_t(sourceAddr) + 96);
	const uint64_t result = n_sub_822B7EA8(ctx, base, appearance, source->m_C4);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_825486C0, 0x825486C0) { ctx.r3.u64 = n_sub_825486C0(ctx, base, ctx.r3.u64, ctx.r4.u32); }
