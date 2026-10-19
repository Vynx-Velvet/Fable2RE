// CECTargeted (vtable 0x82003858): methods of the class as readable C++.
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

uint64_t n_sub_82294C68(CpuState& ctx, uint8_t* base, uint32_t targetedAddr) {
	if (!UseLiftedCode(11, 0x82294C68)) { ctx.r3.u64 = targetedAddr; __imp__sub_82294C68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82294C68);
	uint32_t stack = ctx.r1.u64;
	CECTargeted* targeted = GameObject<CECTargeted>(base, targetedAddr);

	uint64_t savedR6 = ctx.r6.u64;
	uint64_t savedR7 = ctx.r7.u64;
	uint32_t savedR8{};
	uint32_t savedR9{};
	double savedF13 = ctx.f13.f64;
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 128);

	uint32_t registry = LOAD32(LOAD32(0x83496920u) + 12);
	uint32_t handleList = LOAD32(registry + 88);
	uint32_t handleOwner = LOAD32(handleList + 4);
	savedR8 = handleOwner;
	uint32_t handleNode = LOAD32(handleOwner);
	uint32_t handleValueAddr = handleNode + 104;
	uint32_t nextNode = LOAD32(handleNode + 108);

	uint32_t entity = 0;
	bool active = false;
	if (nextNode != 0) {
		entity = LOAD32(nextNode);
		if (entity == 0) {
			ctx.r1.u64 = stack;
			ctx.r8.u64 = savedR8;
			ctx.r9.u64 = handleList;
			ctx.r10.u64 = entity;
			EntityHandle_Release(ctx, base, handleValueAddr);
			savedR6 = ctx.r6.u64;
			savedR7 = ctx.r7.u64;
			savedR8 = ctx.r8.u32;
			savedF13 = ctx.f13.f64;
			flags.ca = ctx.xer.ca;
		} else if ((LOAD8(entity + 144) & 0x40) != 0) {
			active = true;
		}
	}

	// TXT_820A87D4_B_ion table: sorted {int key; uint32_t value} pairs at +72..+76, with an
	// optional byte index at +140 that maps a key straight to the pair.
	auto lookupEntry = [&](int32_t key) -> uint32_t {
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t slot = LOAD32(entity + 72) + uint32_t(LOAD8(indexTable + uint32_t(key))) * 8;
			savedR9 = slot;
			return LOAD32(slot + 4);
		}
		uint32_t begin = LOAD32(entity + 72);
		savedR6 = LOAD32(entity + 76);
		uint32_t end = uint32_t(savedR6);
		STORE32(stack + 80, 0);
		uint32_t diff = end - begin;
		STORE32(stack + 84, begin);
		flags.ca = ((int32_t)diff < 0) & ((diff & 7) != 0);
		int32_t count = (int32_t)diff >> 3;
		uint32_t it = begin;
		if (count > 0) {
			do {
				flags.ca = (count < 0) & ((count & 1) != 0);
				int32_t half = count >> 1;
				savedR8 = uint32_t(half) << 3;
				uint32_t mid = it + savedR8;
				bool less = (int32_t)LOAD32(mid) < key;
				savedR7 = less ? 1 : 0;
				if (less) {
					it = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, it);
		}
		if (it != end && !((int32_t)LOAD32(it) > key)) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(it + 4);
		}
		return LOAD32(end + 4);
	};

	uint64_t result = 0;
	if (active && (LOAD32(entity + 44) & 0x2000) != 0) {
		savedR9 = 1;
		uint32_t interactableHandle = lookupEntry(0x4D);
		uint32_t interactableAddr = interactableHandle + 196;
		uint32_t targetValue = uint32_t(targeted->m_4);
		ctx.r1.u64 = stack;
		ctx.r6.u64 = savedR6;
		ctx.r7.u64 = savedR7;
		ctx.r8.u64 = savedR8;
		ctx.r9.u64 = savedR9;
		ctx.xer.ca = flags.ca;
		uint8_t canTXT_820A87D4_B_ = uint8_t(n_sub_82488F30(ctx, base, interactableAddr, targetValue));
		savedR6 = ctx.r6.u64;
		savedR7 = ctx.r7.u64;
		savedR8 = ctx.r8.u32;
		savedF13 = ctx.f13.f64;
		flags.ca = ctx.xer.ca;
		if (canTXT_820A87D4_B_ != 0 && (LOAD32(entity + 40) & 2) != 0) {
			uint32_t statBlock = lookupEntry(0x21);
			ctx.fpscr.disableFlushMode();
			savedF13 = double(LOAD_F32(statBlock + 136));
			result = (savedF13 > double(LOAD_F32(0x82099AE0u))) ? 0 : 1;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = savedR6;
	ctx.r7.u64 = savedR7;
	ctx.r8.u64 = savedR8;
	ctx.f13.f64 = savedF13;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(11, sub_82294C68, 0x82294C68) { ctx.r3.u64 = n_sub_82294C68(ctx, base, ctx.r3.u32); }

uint64_t n_sub_822D50B8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(13, 0x822D50B8)) { ctx.r3.u64 = arg1; __imp__sub_822D50B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D50B8);
	uint32_t stack = ctx.r1.u64;
	uint32_t sourceId{};
	uint32_t entityHandle{};
	uint32_t eraseKey{};
	uint64_t erasePos{};
	uint64_t reg6{};
	uint64_t reg7{};
	uint32_t lookupObj{};
	uint64_t reg8{};
	uint64_t outR9 = ctx.r9.u64;
	uint32_t listObj{};
	uint64_t reg9{};
	uint64_t outR10 = ctx.r10.u64;
	uint32_t level3Obj{};
	uint64_t reg10{};
	uint32_t hasHandle{};
	uint32_t searchCount{};
	uint32_t listEnd{};
	uint32_t listBegin{};
	uint32_t registry{};
	uint32_t eligible{};
	uint32_t component{};
	uint64_t container{};
	uint32_t handleValue{};
	uint32_t iterator{};
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 128);
	listBegin = LOAD32((uint32_t)arg1 + 112);
	container = (int64_t)arg1 + 108;
	uint64_t returnValue = arg1;
	if (listBegin != 0) {
		outR10 = LOAD32((uint32_t)container + 8);
		outR9 = outR10 - (uint64_t)listBegin;
		flags.ca = (int32_t)outR9 < 0 & ((uint32_t)outR9 & 0x7) != 0;
		if (int32_t((int32_t)outR9 >> 3) != 0) {
			registry = LOAD32((uint32_t)g_83490000 + 26912);
			level3Obj = LOAD32(registry + 12);
			listObj = LOAD32(level3Obj + 88);
			lookupObj = LOAD32(listObj + 4);
			sourceId = LOAD32(lookupObj);
			ctx.r1.u64 = stack;
			ctx.r8.u64 = lookupObj;
			ctx.r9.u64 = listObj;
			ctx.r10.u64 = level3Obj;
			ctx.xer.ca = flags.ca;
			entityHandle = EntityHandle_Get(ctx, base, sourceId);
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			reg10 = ctx.r10.u64;
			flags.ca = ctx.xer.ca;
			handleValue = 0;
			eligible = 0;
			if (entityHandle != 0) {
				reg10 = LOAD8(entityHandle + 144) & 64;
				if (reg10 != 0) {
					eligible = 1;
				}
			}
			eligible = eligible & 0xFF;
			if (eligible != 0) {
				reg10 = (LOAD32(entityHandle + 40) >> 1) & 1;
				if ((uint32_t)reg10 != 0) {
					component = LOAD32(entityHandle + 140);
					if (component != 0) {
						reg10 = __builtin_rotateleft32((uint32_t)LOAD8(component + 33), 3);
						reg9 = reg10 + (uint64_t)LOAD32(entityHandle + 72);
						handleValue = LOAD32((uint32_t)reg9 + 4);
						hasHandle = 1;
					} else {
						// Lower-bound search in the sorted handle table for the first key >= 33.
						reg10 = LOAD32(entityHandle + 72);
						reg6 = LOAD32(entityHandle + 76);
						STORE32(stack + 80, handleValue);
						searchCount = (uint32_t)reg6 - (uint32_t)reg10;
						STORE32(stack + 84, reg10);
						flags.ca = (int32_t)searchCount < 0 & (searchCount & 0x7) != 0;
						searchCount = (int32_t)searchCount >> 3;
						if ((int32_t)searchCount > 0) {
							do {
								flags.ca = (int32_t)searchCount < 0 & (searchCount & 0x1) != 0;
								reg9 = (int32_t)searchCount >> 1;
								reg8 = (uint32_t)reg9 << 3;
								reg10 = reg8 + reg10;
								compare6.compare<int32_t>(int32_t(LOAD32((uint32_t)reg10)), 33, flags);
								reg7 = 1;
								if (!compare6.lt) {
									reg7 = (uint64_t)handleValue;
								}
								reg7 = (uint32_t)reg7 & 0xFF;
								if ((uint32_t)reg7 != 0) {
									searchCount = searchCount - (uint32_t)reg9;
									reg10 = (int64_t)reg10 + 8;
									searchCount = (int32_t)searchCount - 1;
								} else {
									reg10 = reg10 - reg8;
									searchCount = (uint32_t)reg9;
								}
							} while ((int32_t)searchCount > 0);
							STORE32(stack + 84, (uint32_t)reg10);
						}
						bool foundExact = false;
						if ((uint32_t)reg10 != (uint32_t)reg6) {
							compare6.compare<int32_t>(int32_t(LOAD32((uint32_t)reg10)), 33, flags);
							uint32_t notGreater = 1;
							if (!compare6.gt) {
								notGreater = handleValue;
							}
							notGreater = notGreater & 0xFF;
							if (notGreater == 0) {
								STORE64(stack + 80, LOAD64(stack + 80));
								handleValue = LOAD32(LOAD32(stack + 84) + 4);
								hasHandle = 1;
								foundExact = true;
							}
						}
						if (!foundExact) {
							handleValue = LOAD32((uint32_t)reg6 + 4);
							hasHandle = 1;
						}
					}
				} else {
					hasHandle = handleValue;
				}
				hasHandle = hasHandle & 0xFF;
				if (hasHandle != 0) {
					iterator = LOAD32((uint32_t)container + 4);
					listEnd = LOAD32((uint32_t)container + 8);
					if (iterator > listEnd) {
						ppc_trap(ctx, base, 22);
					}
					for (;;) {
						reg10 = LOAD32((uint32_t)container + 8);
						reg9 = LOAD32((uint32_t)container + 4);
						if ((uint32_t)reg9 > (uint32_t)reg10) {
							ppc_trap(ctx, base, 22);
						}
						if (iterator == (uint32_t)reg10) break;
						if (iterator >= listEnd) {
							ppc_trap(ctx, base, 22);
						}
						erasePos = iterator;
						eraseKey = handleValue;
						ctx.r6.u64 = reg6;
						ctx.r7.u64 = reg7;
						ctx.r8.u64 = reg8;
						ctx.r9.u64 = reg9;
						ctx.r10.u64 = reg10;
						ctx.xer.ca = flags.ca;
						SharedHandleList_EraseMatching(ctx, base, eraseKey, erasePos);
						reg6 = ctx.r6.u64;
						reg7 = ctx.r7.u64;
						reg8 = ctx.r8.u64;
						flags.ca = ctx.xer.ca;
						listEnd = LOAD32((uint32_t)container + 8);
						if (iterator >= listEnd) {
							ppc_trap(ctx, base, 22);
						}
						iterator = iterator + 8;
					}
				}
			}
			returnValue = container;
			ctx.r6.u64 = reg6;
			ctx.r7.u64 = reg7;
			ctx.r8.u64 = reg8;
			ctx.r9.u64 = reg9;
			ctx.r10.u64 = reg10;
			ctx.xer.ca = flags.ca;
			Vector_ClearPOD(ctx, base, (uint32_t)container);
			outR9 = ctx.r9.u64;
			outR10 = ctx.r10.u64;
			flags.ca = ctx.xer.ca;
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = outR9;
	ctx.r10.u64 = outR10;
	ctx.xer.ca = flags.ca;
	return returnValue;
}
PROMOTED_ENTRY(13, sub_822D50B8, 0x822D50B8) { ctx.r3.u64 = n_sub_822D50B8(ctx, base, ctx.r3.u64); }

uint64_t CECTargeted_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A8788_B_ = int32_t(0x820A8788);
	if (!UseLiftedCode(19, 0x823974E8)) { ctx.r3.u64 = classNameString; __imp__sub_823974E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823974E8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820A8788_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(19, sub_823974E8, 0x823974E8) { ctx.r3.u64 = CECTargeted_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82397818(CpuState& ctx, uint8_t* base, uint64_t targetedAddr, uint64_t arg2) {
	constexpr int32_t str_TXT_820A87D4_B_ = int32_t(0x820A87D4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(19, 0x82397818)) { ctx.r3.u64 = targetedAddr; ctx.r8.u64 = arg2; __imp__sub_82397818(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82397818);
	uint32_t stack = ctx.r1.u64;
	CECTargeted* targeted = GameObject<CECTargeted>(base, targetedAddr);
	uint32_t targetedAddr2 = targetedAddr;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	n_sub_82399988(ctx, base, targetedAddr, arg2);

	uint32_t targetData = targeted->m_4;
	uint32_t highWord = LOAD32(targetData + 24);
	uint64_t mask = (uint64_t)LOAD32(targetData + 20) | (uint64_t)highWord;
	if (highWord != 0) {
		mask |= 0x80000000;
	}

	uint32_t gameGlobals = uint32_t(g_83490000);
	uint32_t firstHandle = LOAD32(LOAD32(LOAD32(gameGlobals + 26788) + 32) + 88);
	n_sub_822D0688(ctx, base, firstHandle, mask);

	uint32_t secondHandle = LOAD32(LOAD32(LOAD32(gameGlobals + 26788) + 32) + 88);
	uint64_t result = n_sub_82176010(ctx, base, secondHandle, mask);

	if (LOAD8(targetedAddr2 + 40) != 0) {
		uint32_t textBuffer = stack + 80;
		CCharString_ConstructFromCStr(ctx, base, textBuffer, str_TXT_820A87D4_B_, -1);
		uint32_t targetData2 = targeted->m_4;
		uint32_t interactHandle = LOAD32(LOAD32(LOAD32(gameGlobals + 26788) + 32) + 28);
		n_sub_821BD998(ctx, base, interactHandle, targetData2, textBuffer);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, textBuffer);
		targeted->m_28 = uint8_t(0);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_82397818, 0x82397818) { ctx.r3.u64 = n_sub_82397818(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82398520(CpuState& ctx, uint8_t* base, uint64_t targetedAddr, uint64_t arg2, uint64_t arg3) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820A8864_B_ = int32_t(0x820A8864);
	constexpr int32_t str_TXT_820A8958_B_ = int32_t(0x820A8958);
	constexpr int32_t str_TXT_820A8974_B_ = int32_t(0x820A8974);
	constexpr int32_t str_TXT_820A8984_B_ = int32_t(0x820A8984);
	constexpr int32_t str_TXT_820A8990_B_ = int32_t(0x820A8990);
	constexpr int32_t str_TXT_820A899C_B_ = int32_t(0x820A899C);
	constexpr int32_t str_TXT_820A89B0_B_ = int32_t(0x820A89B0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(19, 0x82398520)) { ctx.r3.u64 = targetedAddr; ctx.r4.u64 = arg2; ctx.r6.u64 = arg3; __imp__sub_82398520(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82398520);
	uint32_t stack = ctx.r1.u64;
	const uint32_t savedMsr = ctx.r13.u64;
	CECTargeted* targeted = GameObject<CECTargeted>(base, targetedAddr);
	stack = PushStackFrame(base, stack, 192);
	ctx.r1.u64 = stack;

	const uint32_t nameString = stack + 80;        // CCharString scratch for the current field name
	const uint32_t recordIdTemp = stack + 84;      // record id read back from the stream
	const uint32_t suggestionIdTemp = stack + 88;  // record id handed to the stream
	const uint32_t recordPair = stack + 96;        // { record id, value } appended to the target
	const uint32_t suggestionList = uint32_t(targetedAddr) + 108;

	uint64_t result = 0;

	auto beginName = [&](int32_t name) {
		CCharString_ConstructFromCStr(ctx, base, nameString, name, -1);
	};
	auto internedName = [&]() -> uint64_t {
		uint32_t text = LOAD32(nameString);
		return text != 0 ? uint64_t(LOAD32(text)) : uint64_t(g_8209003F);
	};

	ctx.r6.u64 = arg3;
	beginName(str_TXT_820A8958_B_);
	ctx.r4.u64 = internedName();
	IStream_SerializeFloat(ctx, base, arg2, targetedAddr + 64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

	beginName(str_TXT_820A8974_B_);
	ctx.r4.u64 = internedName();
	IStream_SerializeFloat(ctx, base, arg2, targetedAddr + 68);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

	beginName(str_TXT_820A8864_B_);
	ctx.r4.u64 = internedName();
	IStream_SerializeFloat(ctx, base, arg2, targetedAddr + 72);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

	beginName(str_TXT_820A8984_B_);
	IStream_SerializeString(ctx, base, nameString, arg2, targetedAddr + 35);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

	beginName(str_TXT_820A8990_B_);
	IStream_SerializeString(ctx, base, nameString, arg2, targetedAddr + 37);
	result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

	if ((arg3 & 0xFF) != 0) {
		// saving: write the suggestion records already stored on the target to the stream
		uint32_t begin = targeted->m_70;
		if (begin == 0) {
			stack = PopStackFrame(stack, 192);
			ctx.r1.u64 = stack;
			return result;
		}
		uint32_t end = LOAD32(suggestionList + 8);
		if ((int32_t(end - begin) >> 3) == 0) {
			stack = PopStackFrame(stack, 192);
			ctx.r1.u64 = stack;
			return result;
		}
		uint32_t element = LOAD32(suggestionList + 4);
		if (element > end) {
			ppc_trap(ctx, base, 22);
		}
		for (;;) {
			uint32_t currentEnd = LOAD32(suggestionList + 8);
			if (LOAD32(suggestionList + 4) > currentEnd) {
				ppc_trap(ctx, base, 22);
			}
			if (element == currentEnd) {
				break;
			}
			if (element >= end) {
				ppc_trap(ctx, base, 22);
			}

			uint32_t suggestionId = LOAD32(element);
			uint32_t vtable = LOAD32(uint32_t(arg2));
			uint32_t beginCallback = LOAD32(vtable + 4);
			STORE32(suggestionIdTemp, suggestionId);
			ctx.r3.u64 = arg2;
			ctx.r4.u64 = uint64_t(str_TXT_820A899C_B_);
			ctx.r9.u64 = beginCallback;
			ctx.r10.u64 = suggestionId;
			REX_CALL_INDIRECT_FUNC(beginCallback);

			beginName(str_TXT_820A89B0_B_);
			ctx.r4.u64 = internedName();
			IStream_SerializeId(ctx, base, arg2, suggestionIdTemp);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);

			uint32_t nextCallback = LOAD32(LOAD32(uint32_t(arg2)) + 12);
			ctx.r3.u64 = arg2;
			ctx.r10.u64 = nextCallback;
			REX_CALL_INDIRECT_FUNC(nextCallback);
			result = ctx.r3.u64;

			end = LOAD32(suggestionList + 8);
			if (element >= end) {
				ppc_trap(ctx, base, 22);
			}
			element += 8;
		}

		stack = PopStackFrame(stack, 192);
		ctx.r1.u64 = stack;
		return result;
	}

	// loading: read every suggestion record from the stream and append it to the target
	uint32_t vtable = LOAD32(uint32_t(arg2));
	const uint64_t savedSuggestionsName = uint64_t(str_TXT_820A899C_B_);
	uint32_t beginCallback = LOAD32(vtable + 8);
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = savedSuggestionsName;
	ctx.r9.u64 = beginCallback;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(beginCallback);
	result = ctx.r3.u64;

	if ((uint32_t(result) & 0xFF) != 0) {
		const uint32_t globalBase = uint32_t(g_83490000);
		const uint32_t refCount = uint32_t(g_83496EB8);
		do {
			STORE32(recordIdTemp, 0);
			beginName(str_TXT_820A89B0_B_);
			ctx.r4.u64 = internedName();
			IStream_SerializeId(ctx, base, arg2, recordIdTemp);
			CCharString_Release(ctx, base, nameString);

			// release the reference the record map held on the string just consumed
			for (;;) {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t globalLock = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *reinterpret_cast<uint32_t*>(RAW(refCount));
				uint32_t newCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) - 1;
				bool swapped = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCount)), ctx.reserved.s32,
				                                            __builtin_bswap32((int32_t)newCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = globalLock & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
				if (swapped) break;
			}

			uint32_t recordId = LOAD32(recordIdTemp);
			STORE32(nameString, 0);
			STORE32(recordPair + 4, 0);
			STORE32(recordPair, recordId);
			if (recordId != 0) {
				if (LOAD32(globalBase + 26912) != 0 || LOAD32(globalBase + 26920) != 0) {
					uint32_t recordTable = LOAD32(globalBase + 27600);
					uint32_t value = HashMapU32_FindValue(ctx, base, recordTable, recordId);
					STORE32(recordPair + 4, value);
				}
			}

			n_sub_8239BC88(ctx, base, suggestionList, recordPair);

			uint32_t nextCallback = LOAD32(LOAD32(uint32_t(arg2)) + 12);
			ctx.r3.u64 = arg2;
			ctx.r10.u64 = nextCallback;
			REX_CALL_INDIRECT_FUNC(nextCallback);

			uint32_t endVtable = LOAD32(uint32_t(arg2));
			uint32_t endCallback = LOAD32(endVtable + 8);
			ctx.r3.u64 = arg2;
			ctx.r4.u64 = savedSuggestionsName;
			ctx.r8.u64 = endCallback;
			ctx.r9.u64 = endVtable;
			REX_CALL_INDIRECT_FUNC(endCallback);
			result = ctx.r3.u64;
		} while ((uint32_t(result) & 0xFF) != 0);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_82398520, 0x82398520) { ctx.r3.u64 = n_sub_82398520(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r6.u64); }

uint64_t n_sub_8239B7A0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(19, 0x8239B7A0)) { ctx.r3.u64 = arg1; __imp__sub_8239B7A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239B7A0);
	return n_sub_822D50B8(ctx, base, arg1);
}
PROMOTED_ENTRY(19, sub_8239B7A0, 0x8239B7A0) { ctx.r3.u64 = n_sub_8239B7A0(ctx, base, ctx.r3.u64); }

// sub_8239B7A8
uint64_t n_sub_8239B7A8(CpuState& ctx, uint8_t* base, uint64_t targetedAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(19, 0x8239B7A8)) { ctx.r3.u64 = targetedAddr; __imp__sub_8239B7A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239B7A8);
	uint32_t stack = ctx.r1.u64;
	CECTargeted* targeted = GameObject<CECTargeted>(base, targetedAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t v4 = targeted->m_4;
	uint32_t highFlags = LOAD32(v4 + 0x18);
	uint64_t flags = (uint64_t)LOAD32(v4 + 0x14) | (uint64_t)highFlags;
	if (highFlags != 0) {
		flags = flags | 0x80000000;
	}
	uint32_t singleton = LOAD32(uint32_t(g_83490000) + 26788);
	uint32_t targetCtx = LOAD32(LOAD32(singleton + 32) + 88);
	ctx.r1.u64 = stack;
	n_sub_82176010(ctx, base, targetCtx, flags);
	uint64_t result = n_sub_822D50B8(ctx, base, targetedAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_8239B7A8, 0x8239B7A8) { ctx.r3.u64 = n_sub_8239B7A8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_8239B808(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(19, 0x8239B808)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_8239B808(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239B808);
	uint32_t stack = ctx.r1.u64;

	stack = PushStackFrame(base, stack, 112);

	// First state query through the object's virtual accessor at vtable + 4.
	uint32_t stateGetter = LOAD32(LOAD32((uint32_t)arg2) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = stateGetter;
	REX_CALL_INDIRECT_FUNC(stateGetter);

	uint64_t result;
	if ((int32_t)ctx.r3.u32 == 8) {
		result = n_sub_8239B880(ctx, base, arg1);
	} else {
		// Re-read the accessor: the previous call may have changed the vtable.
		uint32_t stateGetter2 = LOAD32(LOAD32((uint32_t)arg2) + 4);
		ctx.r3.u64 = arg2;
		ctx.r10.u64 = stateGetter2;
		REX_CALL_INDIRECT_FUNC(stateGetter2);
		result = ctx.r3.u64;
		if ((int32_t)result == 9) {
			result = n_sub_8239B880(ctx, base, arg1);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_8239B808, 0x8239B808) { ctx.r3.u64 = n_sub_8239B808(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_8239B880(CpuState& ctx, uint8_t* base, uint64_t targetedAddr) {
	if (!UseLiftedCode(19, 0x8239B880)) { ctx.r3.u64 = targetedAddr; __imp__sub_8239B880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8239B880);
	constexpr int32_t str_TXT_820A87D4_B_ = int32_t(0x820A87D4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	uint32_t stack = ctx.r1.u64;
	CECTargeted* targeted = GameObject<CECTargeted>(base, targetedAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	n_sub_822D50B8(ctx, base, targetedAddr);
	uint32_t targetData = targeted->m_4;
	uint32_t highFlag = LOAD32(targetData + 24);
	uint64_t flags = (uint64_t)LOAD32(targetData + 20) | (uint64_t)highFlag;
	if (highFlag != 0) {
		flags |= 0x80000000u;
	}
	uint32_t gameGlobalAddr = uint32_t(g_83490000);
	uint32_t fieldSet = LOAD32(gameGlobalAddr + 26788);
	fieldSet = LOAD32(fieldSet + 32);
	uint32_t handle = LOAD32(fieldSet + 88);
	n_sub_822D0688(ctx, base, handle, flags);
	uint32_t fieldSet2 = LOAD32(LOAD32(gameGlobalAddr + 26788) + 32);
	uint32_t handle2 = LOAD32(fieldSet2 + 88);
	uint64_t result = n_sub_82176010(ctx, base, handle2, flags);
	uint8_t wasTXT_820A87D4_B_ing = targeted->m_28;
	targeted->m_29 = 0;
	if (wasTXT_820A87D4_B_ing != 0) {
		int32_t nameLength = -1;
		uint64_t TXT_820A87D4_L_ = (uint64_t)str_TXT_820A87D4_B_;
		uint64_t charStringAddr = (uint64_t)stack + 80;
		CCharString_ConstructFromCStr(ctx, base, charStringAddr, TXT_820A87D4_L_, nameLength);
		uint32_t targetData2 = targeted->m_4;
		uint32_t manager = LOAD32(LOAD32(gameGlobalAddr + 26788) + 32);
		uint32_t callback = LOAD32(manager + 28);
		n_sub_821BD998(ctx, base, callback, targetData2, charStringAddr);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringAddr);
		targeted->m_28 = 0;
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_8239B880, 0x8239B880) { ctx.r3.u64 = n_sub_8239B880(ctx, base, ctx.r3.u64); }
