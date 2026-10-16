// CECWorldMapInfo (vtable 0x82002F08): methods of the class as readable C++.
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

// sub_8288D708  [60 bytes]
uint64_t CECWorldMapInfo_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C954C_B_ = int32_t(0x820C954C);
	if (!UseLiftedCode(60, 0x8288D708)) { ctx.r3.u64 = classNameString; __imp__sub_8288D708(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8288D708);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820C954C_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(60, sub_8288D708, 0x8288D708) { ctx.r3.u64 = CECWorldMapInfo_GetClassName(ctx, base, ctx.r3.u64); }

// sub_828907F0  [4 bytes]
uint64_t n_sub_828907F0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(60, 0x828907F0)) { ctx.r3.u64 = arg1; __imp__sub_828907F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828907F0);
	return n_sub_82890A80(ctx, base, arg1);
}
PROMOTED_ENTRY(60, sub_828907F0, 0x828907F0) { ctx.r3.u64 = n_sub_828907F0(ctx, base, ctx.r3.u64); }

// Unless the word at +156 is set: for each record of the region-info list whose string field is not empty,
// collects the keys of its sub-region entries into a temporary list and hands that list to the entry of the
// map at +148 keyed by the record's key.
uint64_t n_sub_828907F8(CpuState& ctx, uint8_t* base, uint64_t worldMap, uint64_t incomingR8) {
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr int32_t str_TXT_820DFCD8_B_ = int32_t(0x820DFCD8);
	constexpr int32_t str_TXT_820DFCE8_B_ = int32_t(0x820DFCE8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	constexpr int32_t g_8349E164 = int32_t(0x8349E164);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(60, 0x828907F8)) { ctx.r3.u64 = worldMap; ctx.r8.u64 = incomingR8; __imp__sub_828907F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828907F8);

	uint32_t frameAddr{};
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR13 = ctx.r13.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;

	uint64_t result = worldMap;
	uint64_t r4ForCallers = ctx.r4.u64;
	uint32_t thisAddr = (uint32_t)worldMap;
	uint32_t globalMgr = uint32_t(g_83490000);

	stack = PushStackFrame(base, stack, 256);

	if (LOAD32(thisAddr + 156) == 0) {
		uint32_t objectDb = LOAD32(globalMgr + 27600);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = incomingR8;  // state the callee may pass on
		uint64_t regionInfoHash = String_HashFnv1(ctx, base, uint64_t(str_TXT_820DFCD8_B_), 0xFFFFFFFF811C9DC5ull);
		result = n_sub_829FB108(ctx, base, objectDb, regionInfoHash);
		r4ForCallers = result;
		if ((uint32_t)result != 0) {
			n_sub_829FBC40(ctx, base, stack + 120, result, ctx.r8.u64);
			uint64_t r4Value = ctx.r4.u64;
			uint32_t i = LOAD32(stack + 128);
			uint32_t endIdx = LOAD32(stack + 124);
			uint32_t arrayBase = LOAD32(stack + 120);
			if (i != endIdx) {
				uint64_t r8Value = uint64_t(str_TXT_820C0000_B_);
				const uint64_t stringFieldName = uint64_t(str_TXT_820C0000_B_) + 25724;
				const uint64_t subRegionsFieldName = uint64_t(str_TXT_820DFCE8_B_);
				const uint32_t matchKeyAddr = uint32_t(g_834A0000) - 7848;
				const uint32_t globalCountAddr = uint32_t(g_83496EB8);
				const uint32_t replacementKeyPtr = uint32_t(g_8349E164);

				do {
					uint32_t entry = arrayBase + i * 12;
					uint32_t keyPtr = LOAD32(entry + 8);
					uint32_t entryType = LOAD32(entry);
					if (entryType == 4 && LOAD32(keyPtr) == LOAD32(matchKeyAddr)) {
						keyPtr = replacementKeyPtr;
					}
					uint32_t db = LOAD32(globalMgr + 27600);
					r4Value = LOAD32(keyPtr);
					ctx.r8.u64 = r8Value;  // state the callee may pass on
					uint64_t record = HashMapU32_FindValue(ctx, base, db, r4Value);
					r8Value = ctx.r8.u64;
					if ((uint32_t)record != 0) {
						uint64_t fieldString = n_sub_82345978(ctx, base, record, stringFieldName);
						CCharString_ConstructFromCStr(ctx, base, stack + 80, fieldString, -1);
						uint32_t stringData = LOAD32(stack + 80);
						if (stringData != 0 && (int32_t)LOAD32(stringData + 4) != 0) {
							ctx.r3.u64 = thisAddr;  // state the callee may pass on
							uint32_t regionKey = n_sub_828924A8(ctx, base, stack + 80);
							STORE32(stack + 92, regionKey);
							RbTree_InitEmptyNode12(ctx, base, stack + 104);
							uint64_t TXT_820DFCE8_L_ = GameDB_ReadU32Field(ctx, base, record, subRegionsFieldName);
							if ((uint32_t)TXT_820DFCE8_L_ != 0) {
								n_sub_829FBC40(ctx, base, stack + 120, TXT_820DFCE8_L_, ctx.r8.u64);
								uint32_t subR4 = ctx.r4.u32;
								uint64_t subR6 = ctx.r6.u64;
								uint32_t j = LOAD32(stack + 128);
								uint32_t jEnd = LOAD32(stack + 124);
								uint32_t subBase = LOAD32(stack + 120);
								if (j != jEnd) {
									STORE32(stack + 96, stack + 104);
									do {
										uint32_t subEntry = subBase + j * 12;
										uint32_t subTable = LOAD32(LOAD32(LOAD32(globalMgr + 27600)) + 12);
										uint32_t subKeyPtr = LOAD32(subEntry + 8);
										uint32_t subKey = LOAD32(subKeyPtr);
										ctx.r8.u64 = subKeyPtr;  // state the callee may pass on
										uint64_t subRegionCStr = HashTable_FindValuePtr(ctx, base, subTable, subKey);
										ctx.r6.u64 = subR6;  // state the callee may pass on
										CCharString_ConstructFromCStr(ctx, base, stack + 84, subRegionCStr, -1);
										ctx.r3.u64 = thisAddr;  // state the callee may pass on
										uint32_t subRegionKey = n_sub_828924A8(ctx, base, stack + 84);
										STORE32(stack + 88, subRegionKey);
										STORE32(stack + 100, LOAD32(stack + 108));
										List_InsertAfter12(ctx, base, stack + 104, LOAD64(stack + 96), stack + 88);
										j = j + 1;
										CCharString_Release(ctx, base, stack + 84);
										// atomic decrement of the global count; r4 holds its address, r6 the new value
										subR4 = globalCountAddr;
										uint32_t lockState;
										do {
											std::atomic_thread_fence(std::memory_order_seq_cst);
											lockState = REX_CHECK_GLOBAL_LOCK();
											std::atomic_thread_fence(std::memory_order_seq_cst);
											ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
											REX_ENTER_GLOBAL_LOCK();
											ctx.reserved.u32 = *(uint32_t*)RAW(subR4);
											subR6 = uint64_t(__builtin_bswap32(ctx.reserved.u32)) - 1;
											frameAddr = subR4;
											compare0.lt = 0;
											compare0.gt = 0;
											compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)subR6));
											compare0.so = flags.so;
											std::atomic_thread_fence(std::memory_order_seq_cst);
											ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
											REX_LEAVE_GLOBAL_LOCK();
										} while (!compare0.eq);
										STORE32(stack + 84, 0);
									} while (j != jEnd);
									STORE32(stack + 128, j);
								}
								// state the callee may pass on
								ctx.r4.u64 = subR4;
								ctx.r6.u64 = subR6;
								HandleTarget_Free(ctx, base, subBase);
								STORE32(stack + 120, 0);
							}
							uint64_t listHead = n_sub_8266CFD8(ctx, base, worldMap + 148, stack + 92);
							n_sub_823434E8(ctx, base, listHead, stack + 104);
							List_ClearFreeNodes(ctx, base, stack + 104);
							HandleTarget_Free(ctx, base, LOAD32(stack + 108));
							STORE32(stack + 108, 0);
						}
						CCharString_Release(ctx, base, stack + 80);
						r4Value = ctx.r4.u64;
						r8Value = ctx.r8.u64;
						// atomic decrement of the global count
						uint32_t lockState;
						do {
							std::atomic_thread_fence(std::memory_order_seq_cst);
							lockState = REX_CHECK_GLOBAL_LOCK();
							std::atomic_thread_fence(std::memory_order_seq_cst);
							ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
							REX_ENTER_GLOBAL_LOCK();
							ctx.reserved.u32 = *(uint32_t*)RAW(globalCountAddr);
							uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
							frameAddr = globalCountAddr;
							compare0.lt = 0;
							compare0.gt = 0;
							compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
							compare0.so = flags.so;
							std::atomic_thread_fence(std::memory_order_seq_cst);
							ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
							REX_LEAVE_GLOBAL_LOCK();
						} while (!compare0.eq);
						STORE32(stack + 80, 0);
					}
					i = i + 1;
				} while (i != endIdx);
			}
			ctx.r4.u64 = r4Value;  // state the callee may pass on
			result = HandleTarget_Free(ctx, base, arrayBase);
			r4ForCallers = ctx.r4.u64;
		}
	}
	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCallers;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(60, sub_828907F8, 0x828907F8) { ctx.r3.u64 = n_sub_828907F8(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82890A80(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(60, 0x82890A80)) { ctx.r3.u64 = arg1; __imp__sub_82890A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82890A80);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_82890ED8(ctx, base, arg1);
	n_sub_82890AF8(ctx, base, arg1);
	n_sub_828914E8(ctx, base, arg1);
	n_sub_82891118(ctx, base, arg1);
	n_sub_82891898(ctx, base, arg1);
	n_sub_828919F0(ctx, base, arg1);
	n_sub_82891B48(ctx, base, arg1);
	n_sub_82891E10(ctx, base, arg1);
	n_sub_82892040(ctx, base, arg1);
	uint64_t result = n_sub_82892198(ctx, base, arg1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82890A80, 0x82890A80) { ctx.r3.u64 = n_sub_82890A80(ctx, base, ctx.r3.u64); }

// When the string copied from the object chain below is not empty: for each object n_sub_82792138 returns,
// reads the value for key 67 and the entity handle for key 66 from the object's sorted 8-byte key/value
// table; when that entity exists and has bit 0x40 set in its byte at +144, the hash of the string made from
// the key-67 value goes into a temporary list. The entry of the map at +24 keyed by the copied string's key
// is cleared and then given that list.
uint32_t n_sub_82890AF8(CpuState& ctx, uint8_t* base, uint64_t worldMapInfo) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(60, 0x82890AF8)) { ctx.r3.u64 = worldMapInfo; __imp__sub_82890AF8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82890AF8);
	uint32_t frameAddr{};
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR13 = ctx.r13.u64;
	PPCCRRegister compare0{};
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 224);

	uint32_t globalBase = uint32_t(g_83490000);
	uint32_t manager = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t subObj = LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 8);
	uint64_t sourceString = uint64_t(LOAD32(LOAD32(LOAD32(subObj + 4) + 36) + 4)) + 172;

	ctx.r1.u64 = stack;
	ctx.r8.u64 = subObj;  // state the callee may pass on
	CCharString_CopyConstruct(ctx, base, stack + 80, sourceString);

	uint32_t charData = LOAD32(stack + 80);
	if (charData != 0 && LOAD32(charData + 4) != 0) {
		ctx.r3.u64 = (uint32_t)worldMapInfo;  // state the callee may pass on
		uint32_t listKey = n_sub_828924A8(ctx, base, stack + 80);
		STORE32(stack + 84, listKey);

		RbTree_InitEmptyNode12(ctx, base, stack + 144);

		uint32_t managerHolder = LOAD32(globalBase + 26912);
		STORE32(stack + 132, 0);
		STORE32(stack + 136, 0);
		STORE32(stack + 140, 0);
		STORE32(stack + 88, 124u);

		uint32_t manager2 = LOAD32(managerHolder + 12);
		uint32_t managerField88 = LOAD32(manager2 + 88);
		uint32_t field88Item = LOAD32(managerField88 + 4);
		uint32_t queryTarget = LOAD32(field88Item + 12);
		// state the callee may pass on
		ctx.r7.u64 = field88Item;
		ctx.r9.u64 = manager2;
		n_sub_82792138(ctx, base, queryTarget, stack + 88, 1u, stack + 128, managerField88);
		flags.ca = ctx.xer.ca;

		// r5..r9 as the register file holds them; handed on to EntityHandle_GetEntity and n_sub_82892770
		uint64_t reg5 = ctx.r5.u64;
		uint64_t reg6 = ctx.r6.u64;
		uint64_t reg7 = ctx.r7.u64;
		uint64_t reg8 = ctx.r8.u64;
		uint64_t reg9 = 0;

		uint32_t arrayBegin = LOAD32(stack + 132);
		uint32_t arrayEnd = LOAD32(stack + 136);
		uint32_t cursor = arrayBegin;
		if (arrayBegin != arrayEnd) {
			do {
				uint32_t item = LOAD32(cursor);
				reg6 = item;
				uint32_t valueFor67 = 0;
				bool haveValueFor67 = false;
				if (((LOAD32(item + 44) >> 3) & 1) != 0) {
					uint32_t indexTable = LOAD32(item + 140);
					if (indexTable != 0) {
						valueFor67 = LOAD32(__builtin_rotateleft32(LOAD8(indexTable + 67), 3) + LOAD32(item + 72) + 4);
						haveValueFor67 = true;
					} else {
						// lower-bound search for key 67
						uint32_t it = LOAD32(item + 72);
						uint32_t tableEnd = LOAD32(item + 76);
						reg5 = tableEnd;
						STORE32(stack + 96, 0);
						int32_t count = tableEnd - it;
						STORE32(stack + 100, it);
						flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
						count = (int32_t)count >> 3;
						if (count > 0) {
							do {
								flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
								int32_t half = (int32_t)count >> 1;
								reg8 = (uint32_t)half << 3;
								it = reg8 + it;
								compare6.compare<int32_t>(int32_t(LOAD32(it)), 67, flags);
								reg7 = 1;
								if (!compare6.lt) reg7 = 0;
								reg7 &= 0xFF;
								if (reg7 != 0) {
									count = count - half;
									it = (int32_t)it + 8;
									count = (int32_t)count - 1;
								} else {
									it = it - reg8;
									count = half;
								}
							} while (count > 0);
							STORE32(stack + 100, it);
						}
						if (it != tableEnd) {
							compare6.compare<int32_t>(int32_t(LOAD32(it)), 67, flags);
							uint32_t greater = 1;
							if (!compare6.gt) greater = 0;
							greater &= 0xFF;
							if (greater == 0) {
								STORE64(stack + 128, LOAD64(stack + 96));
								valueFor67 = LOAD32(LOAD32(stack + 132) + 4);
								haveValueFor67 = true;
							}
						}
						if (!haveValueFor67) {
							valueFor67 = LOAD32(tableEnd + 4);
							haveValueFor67 = true;
						}
					}
				}
				if (haveValueFor67) {
					uint32_t entityHandle = 0;
					bool haveEntityHandle = false;
					reg9 = (LOAD32(item + 44) >> 2) & 1;
					if (reg9 != 0) {
						uint32_t indexTable = LOAD32(item + 140);
						uint32_t it = LOAD32(item + 72);
						if (indexTable != 0) {
							it += __builtin_rotateleft32(LOAD8(indexTable + 66), 3);
							entityHandle = LOAD32(it + 4);
							haveEntityHandle = true;
						} else {
							// lower-bound search for key 66
							uint32_t tableEnd = LOAD32(item + 76);
							reg6 = tableEnd;
							STORE32(stack + 104, 0);
							int32_t count = tableEnd - it;
							STORE32(stack + 108, it);
							flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
							count = (int32_t)count >> 3;
							if (count > 0) {
								do {
									flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
									int32_t half = (int32_t)count >> 1;
									reg9 = (uint32_t)half;
									reg8 = (uint32_t)half << 3;
									it = reg8 + it;
									compare6.compare<int32_t>(int32_t(LOAD32(it)), 66, flags);
									reg7 = 1;
									if (!compare6.lt) reg7 = 0;
									reg7 &= 0xFF;
									if (reg7 != 0) {
										count = count - half;
										it = (int32_t)it + 8;
										count = (int32_t)count - 1;
									} else {
										it = it - reg8;
										count = half;
									}
								} while (count > 0);
								STORE32(stack + 108, it);
							}
							if (it != tableEnd) {
								compare6.compare<int32_t>(int32_t(LOAD32(it)), 66, flags);
								uint32_t greater = 1;
								if (!compare6.gt) greater = 0;
								greater &= 0xFF;
								if (greater == 0) {
									STORE64(stack + 128, LOAD64(stack + 104));
									entityHandle = LOAD32(LOAD32(stack + 132) + 4);
									haveEntityHandle = true;
								}
							}
							if (!haveEntityHandle) {
								entityHandle = LOAD32(tableEnd + 4);
								haveEntityHandle = true;
							}
						}
					}
					if (haveEntityHandle) {
						// state the callee may pass on
						ctx.r5.u64 = reg5;
						ctx.r6.u64 = reg6;
						ctx.r7.u64 = reg7;
						ctx.r8.u64 = reg8;
						ctx.r9.u64 = reg9;
						ctx.xer.ca = flags.ca;
						uint32_t entity = EntityHandle_GetEntity(ctx, base, entityHandle);
						reg5 = ctx.r5.u64;
						reg6 = ctx.r6.u64;
						reg7 = ctx.r7.u64;
						reg8 = ctx.r8.u64;
						flags.ca = ctx.xer.ca;
						if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
							uint32_t str = n_sub_8274D188(ctx, base, stack + 88, valueFor67);
							StringHash_FromCharString(ctx, base, stack + 92, str, ctx.r8.u64);
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
							uint32_t listTail = LOAD32(stack + 148);
							STORE32(stack + 112, stack + 144);
							STORE32(stack + 116, listTail);
							List_InsertNodeCopyWord(ctx, base, stack + 144, LOAD64(stack + 112), stack + 92);
							reg5 = ctx.r5.u64;
							reg6 = ctx.r6.u64;
							reg7 = ctx.r7.u64;
							reg8 = ctx.r8.u64;
							flags.ca = ctx.xer.ca;
						}
					}
				}
				cursor += 4;
			} while (cursor != arrayEnd);
		}

		uint64_t mapAddr = worldMapInfo + 24;
		// state the callee may pass on
		ctx.r5.u64 = reg5;
		ctx.r6.u64 = reg6;
		ctx.xer.ca = flags.ca;
		uint32_t keyedList = n_sub_82892770(ctx, base, mapAddr, stack + 84);
		List_ClearFreeNodes(ctx, base, keyedList);
		uint64_t keyedListAgain = n_sub_82892770(ctx, base, mapAddr, stack + 84);
		n_sub_824FDF98(ctx, base, keyedListAgain, stack + 144);
		if (arrayBegin != 0) {
			HandleTarget_Free(ctx, base, arrayBegin);
		}
		List_ClearFreeNodes(ctx, base, stack + 144);
		HandleTarget_Free(ctx, base, LOAD32(stack + 148));
		STORE32(stack + 148, 0);
	}

	uint32_t releaseResult = CCharString_Release(ctx, base, stack + 80);

	// atomic decrement of the global count
	uint32_t globalCountAddr = uint32_t(g_83496EB8);
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		uint32_t oldMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(globalCountAddr);
		uint32_t newCount = __builtin_bswap32(ctx.reserved.u32);
		newCount = (int32_t)newCount - 1;
		frameAddr = globalCountAddr;
		compare0.lt = 0;
		compare0.gt = 0;
		compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
		compare0.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = oldMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!compare0.eq);

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(60, sub_82890AF8, 0x82890AF8) { ctx.r3.u64 = n_sub_82890AF8(ctx, base, ctx.r3.u64); }

// When the string copied from the object chain below is not empty: sums n_sub_82852A68 over the value for
// key 170 of each object n_sub_82792138 returns (objects whose bit 10 at +56 is set), and stores the sum in
// the slot of the map at +12 keyed by the copied string's key.
uint32_t n_sub_82890ED8(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(60, 0x82890ED8)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82890ED8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82890ED8);
	uint32_t frameAddr{};
	uint32_t stack = ctx.r1.u64;
	uint32_t savedR13 = ctx.r13.u64;
	PPCCRRegister compare0{};
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);

	stack = PushStackFrame(base, stack, 192);

	uint32_t globalBase = uint32_t(g_83490000);
	uint32_t manager = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t subObj = LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 8);
	uint64_t sourceString = uint64_t(LOAD32(LOAD32(LOAD32(subObj + 4) + 36) + 4)) + 172;

	ctx.r1.u64 = stack;
	CCharString_CopyConstruct(ctx, base, stack + 80, sourceString);

	uint32_t stringData = LOAD32(stack + 80);
	if (stringData != 0 && (int32_t)LOAD32(stringData + 4) != 0) {
		ctx.r3.u64 = (uint32_t)worldMapInfoAddr;  // state the callee may pass on
		uint32_t stringKey = n_sub_828924A8(ctx, base, stack + 80);

		uint32_t managerHolder = LOAD32(globalBase + 26912);
		STORE32(stack + 96, stringKey);
		STORE32(stack + 116, 0);
		STORE32(stack + 120, 0);
		STORE32(stack + 124, 0);
		STORE32(stack + 88, 65u);

		uint32_t manager2 = LOAD32(managerHolder + 12);
		uint32_t managerField88 = LOAD32(manager2 + 88);
		uint32_t field88Item = LOAD32(managerField88 + 4);
		uint32_t queryTarget = LOAD32(field88Item + 12);
		// state the callee may pass on
		ctx.r7.u64 = field88Item;
		ctx.r9.u64 = manager2;
		n_sub_82792138(ctx, base, queryTarget, stack + 88, 3, stack + 112, managerField88);
		flags.ca = ctx.xer.ca;

		// r6..r8 as the register file holds them; handed on to n_sub_82852A68
		uint32_t reg6 = ctx.r6.u32;
		uint32_t reg7 = ctx.r7.u32;
		uint32_t reg8 = ctx.r8.u32;

		uint32_t totalCount = 0;
		uint32_t listBegin = LOAD32(stack + 116);
		uint32_t listEnd = LOAD32(stack + 120);
		uint32_t it = listBegin;
		if (listBegin != listEnd) {
			do {
				uint32_t elem = LOAD32(it);
				uint32_t value = 0;
				bool haveValue = false;
				uint32_t reg9 = (LOAD32(elem + 56) >> 10) & 1;

				if (reg9 != 0) {
					uint32_t indexTable = LOAD32(elem + 140);
					if (indexTable != 0) {
						uint32_t slot = (uint32_t)LOAD8(indexTable + 170);
						uint32_t table = LOAD32(elem + 72);
						reg9 = table + (slot << 3);
						value = LOAD32(reg9 + 4);
						haveValue = true;
					} else {
						// lower-bound search for key 170 in the sorted 8-byte key/value table
						uint32_t start = LOAD32(elem + 72);
						reg6 = LOAD32(elem + 76);
						STORE32(stack + 88, 0);
						uint32_t count = reg6 - start;
						STORE32(stack + 92, start);
						flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
						count = (int32_t)count >> 3;
						if ((int32_t)count > 0) {
							do {
								flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
								uint32_t half = (int32_t)count >> 1;
								reg9 = half;
								reg8 = half << 3;
								start = reg8 + start;
								compare6.compare<int32_t>(int32_t(LOAD32(start)), 170, flags);
								reg7 = 1;
								if (!compare6.lt) {
									reg7 = 0;
								}
								reg7 = reg7 & 0xFF;
								if (reg7 != 0) {
									count = count - half;
									start = (int32_t)start + 8;
									count = (int32_t)count - 1;
								} else {
									start = start - reg8;
									count = half;
								}
							} while ((int32_t)count > 0);
							STORE32(stack + 92, start);
						}
						if (start != reg6) {
							compare6.compare<int32_t>(int32_t(LOAD32(start)), 170, flags);
							uint32_t isAbove = 1;
							if (!compare6.gt) {
								isAbove = 0;
							}
							isAbove = isAbove & 0xFF;
							if (isAbove == 0) {
								STORE64(stack + 112, LOAD64(stack + 88));
								value = LOAD32(LOAD32(stack + 116) + 4);
								haveValue = true;
							}
						}
						if (!haveValue) {
							value = LOAD32(reg6 + 4);
							haveValue = true;
						}
					}
				}

				if (haveValue) {
					uint32_t field4 = worldMapInfo->m_4;
					// state the callee may pass on
					ctx.r6.u64 = reg6;
					ctx.r7.u64 = reg7;
					ctx.r8.u64 = reg8;
					ctx.r9.u64 = reg9;
					ctx.xer.ca = flags.ca;
					uint32_t added = n_sub_82852A68(ctx, base, value, field4);
					reg6 = ctx.r6.u32;
					reg7 = ctx.r7.u32;
					reg8 = ctx.r8.u32;
					flags.ca = ctx.xer.ca;
					totalCount = added + totalCount;
				}

				it = (int32_t)it + 4;
			} while (it != listEnd);
		}

		ctx.xer.ca = flags.ca;  // state the callee may pass on
		uint32_t countSlot = n_sub_82365FF0(ctx, base, worldMapInfoAddr + 12, stack + 96);
		STORE32(countSlot, totalCount);
		if (listBegin != 0) {
			HandleTarget_Free(ctx, base, listBegin);
		}
	}

	uint32_t releaseResult = CCharString_Release(ctx, base, stack + 80);

	// atomic decrement of the global count
	uint32_t globalCountAddr = uint32_t(g_83496EB8);
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		uint32_t prevLock = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedR13 & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(globalCountAddr);
		uint32_t newValue = __builtin_bswap32(ctx.reserved.u32);
		newValue = (int32_t)newValue - 1;
		frameAddr = globalCountAddr;
		compare0.lt = 0;
		compare0.gt = 0;
		compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newValue));
		compare0.so = flags.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = prevLock & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!compare0.eq);

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(60, sub_82890ED8, 0x82890ED8) { ctx.r3.u64 = n_sub_82890ED8(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82891118(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x82891118)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82891118(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82891118);
	uint32_t stack = ctx.r1.u64;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);
	stack = PushStackFrame(base, stack, 208);

	uint32_t registry = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t holderData = LOAD32(LOAD32(LOAD32(registry + 88) + 4) + 8);
	uint32_t record = LOAD32(LOAD32(holderData + 4) + 36);

	uint32_t result = uint32_t(worldMapInfoAddr);
	if (record != 0) {
		uint32_t target = LOAD32(record + 4);
		uint32_t targetId = LOAD32(target + 180);

		ctx.r1.u64 = stack;
		ctx.r8.u64 = holderData;  // state the callee may pass on
		CCharString_CopyConstruct(ctx, base, stack + 88, uint64_t(target) + 172);

		ctx.r3.u64 = uint32_t(worldMapInfoAddr);  // state the callee may pass on
		uint32_t nameKey = n_sub_828924A8(ctx, base, stack + 88);
		STORE32(stack + 80, nameKey);

		uint64_t infoMapAddr = worldMapInfoAddr + 36;
		List_ClearFreeNodes(ctx, base, n_sub_82892770(ctx, base, infoMapAddr, stack + 80));

		RbTree_InitEmptyNode12(ctx, base, stack + 128);
		// r6, r8 and xer.ca as the lifted code tracks them from here; the callees below receive them
		uint64_t r6Value = ctx.r6.u64;
		PPCXERRegister flags = ctx.xer;

		uint32_t owner = worldMapInfo->m_4;
		if (((LOAD32(owner + 44) >> 5) & 1) != 0) {
			// Entry 69 of the owner's sorted (type, value) table: through the cached index when there is
			// one, otherwise by a lower_bound search.
			uint32_t entry;
			uint32_t cachedIndex = LOAD32(owner + 140);
			uint32_t pair = LOAD32(owner + 72);
			if (cachedIndex != 0) {
				entry = LOAD32(pair + (LOAD8(cachedIndex + 69) << 3) + 4);
			} else {
				uint32_t pairsEnd = LOAD32(owner + 76);
				r6Value = pairsEnd;
				STORE32(stack + 96, 0);
				uint32_t byteCount = pairsEnd - pair;
				STORE32(stack + 100, pair);
				flags.ca = int32_t(byteCount) < 0 && (byteCount & 7) != 0;
				int32_t remaining = int32_t(byteCount) >> 3;
				if (remaining > 0) {
					do {
						int32_t half = remaining >> 1;
						uint32_t step = uint32_t(half) << 3;
						pair += step;
						if (int32_t(LOAD32(pair)) < 69) {
							remaining = remaining - half - 1;
							pair += 8;
						} else {
							pair -= step;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 100, pair);
				}
				if (pair != pairsEnd && int32_t(LOAD32(pair)) <= 69) {
					STORE64(stack + 112, LOAD64(stack + 96));
					entry = LOAD32(pair + 4);
				} else {
					entry = LOAD32(pairsEnd + 4);
				}
			}

			uint32_t list = entry + 24;
			uint32_t node = LOAD32(LOAD32(entry + 28));
			while (node != LOAD32(list + 4)) {
				uint32_t item = LOAD32(node + 8);
				if (LOAD8(item + 12) != 0 && LOAD32(item + 20) == targetId) {
					uint32_t holder = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
					// state the callee may pass on
					ctx.r6.u64 = r6Value;
					ctx.r8.u64 = holder;
					ctx.xer.ca = flags.ca;
					uint32_t linked = n_sub_82264448(ctx, base, LOAD32(holder), item);
					r6Value = ctx.r6.u64;
					uint64_t r8Value = ctx.r8.u64;
					if (linked != 0 && (LOAD8(linked + 144) & 64) != 0 && ((LOAD32(linked + 44) >> 3) & 1) != 0) {
						// entry 67 of the linked object's table, looked up the same way
						uint32_t value;
						uint32_t linkedIndex = LOAD32(linked + 140);
						uint32_t linkedPair = LOAD32(linked + 72);
						if (linkedIndex != 0) {
							value = LOAD32(linkedPair + (LOAD8(linkedIndex + 67) << 3) + 4);
						} else {
							uint32_t linkedEnd = LOAD32(linked + 76);
							r6Value = linkedEnd;
							STORE32(stack + 104, 0);
							uint32_t byteCount = linkedEnd - linkedPair;
							STORE32(stack + 108, linkedPair);
							flags.ca = int32_t(byteCount) < 0 && (byteCount & 7) != 0;
							int32_t remaining = int32_t(byteCount) >> 3;
							if (remaining > 0) {
								do {
									int32_t half = remaining >> 1;
									uint32_t step = uint32_t(half) << 3;
									r8Value = step;
									linkedPair += step;
									if (int32_t(LOAD32(linkedPair)) < 67) {
										remaining = remaining - half - 1;
										linkedPair += 8;
									} else {
										linkedPair -= step;
										remaining = half;
									}
								} while (remaining > 0);
								STORE32(stack + 108, linkedPair);
							}
							if (linkedPair != linkedEnd && int32_t(LOAD32(linkedPair)) <= 67) {
								STORE64(stack + 120, LOAD64(stack + 104));
								value = LOAD32(linkedPair + 4);
							} else {
								value = LOAD32(linkedEnd + 4);
							}
						}

						// state the callee may pass on
						ctx.r6.u64 = r6Value;
						ctx.r8.u64 = r8Value;
						ctx.xer.ca = flags.ca;
						n_sub_8274D188(ctx, base, stack + 84, value);
						StringHash_FromCharString(ctx, base, stack + 96, stack + 84, ctx.r8.u64);
						// insert the hash at the end of the list at stack + 128
						uint32_t tempListEnd = LOAD32(stack + 132);
						STORE32(stack + 112, stack + 128);
						STORE32(stack + 116, tempListEnd);
						List_InsertNodeCopyWord(ctx, base, stack + 128, LOAD64(stack + 112), stack + 96);
						CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
						r6Value = ctx.r6.u64;
						flags.ca = ctx.xer.ca;
					}
				}
				if (node == LOAD32(list + 4)) {
					ppc_trap(ctx, base, 22);
				}
				node = LOAD32(node);
			}
		}

		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.xer.ca = flags.ca;
		List_ClearFreeNodes(ctx, base, n_sub_82892770(ctx, base, infoMapAddr, stack + 80));
		uint64_t infoEntry = n_sub_82892770(ctx, base, infoMapAddr, stack + 80);
		n_sub_824FDF98(ctx, base, infoEntry, stack + 128);
		List_ClearFreeNodes(ctx, base, stack + 128);
		HandleTarget_Free(ctx, base, LOAD32(stack + 132));
		STORE32(stack + 132, 0);
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82891118, 0x82891118) { ctx.r3.u64 = n_sub_82891118(ctx, base, ctx.r3.u64); }

uint32_t n_sub_828914E8(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x828914E8)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_828914E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828914E8);
	uint32_t stack = ctx.r1.u64;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);
	stack = PushStackFrame(base, stack, 208);

	uint32_t registry = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t holderData = LOAD32(LOAD32(LOAD32(registry + 88) + 4) + 8);
	uint32_t record = LOAD32(LOAD32(holderData + 4) + 36);

	if (record != 0) {
		uint32_t target = LOAD32(record + 4);
		uint32_t targetId = LOAD32(target + 180);

		ctx.r1.u64 = stack;
		ctx.r8.u64 = holderData;  // state the callee may pass on
		CCharString_CopyConstruct(ctx, base, stack + 88, uint64_t(target) + 172);

		ctx.r3.u64 = uint32_t(worldMapInfoAddr);  // state the callee may pass on
		uint32_t nameKey = n_sub_828924A8(ctx, base, stack + 88);
		STORE32(stack + 80, nameKey);

		uint64_t infoMapAddr = worldMapInfoAddr + 48;
		List_ClearFreeNodes(ctx, base, n_sub_82892770(ctx, base, infoMapAddr, stack + 80));

		RbTree_InitEmptyNode12(ctx, base, stack + 128);
		// r6, r8 and xer.ca as the lifted code tracks them from here; the callees below receive them
		uint64_t r6Value = ctx.r6.u64;
		PPCXERRegister flags = ctx.xer;

		uint32_t owner = worldMapInfo->m_4;
		if (((LOAD32(owner + 44) >> 5) & 1) != 0) {
			// Entry 69 of the owner's sorted (type, value) table: through the cached index when there is
			// one, otherwise by a lower_bound search.
			uint32_t entry;
			uint32_t cachedIndex = LOAD32(owner + 140);
			uint32_t pair = LOAD32(owner + 72);
			if (cachedIndex != 0) {
				entry = LOAD32(pair + (LOAD8(cachedIndex + 69) << 3) + 4);
			} else {
				uint32_t pairsEnd = LOAD32(owner + 76);
				r6Value = pairsEnd;
				STORE32(stack + 96, 0);
				uint32_t byteCount = pairsEnd - pair;
				STORE32(stack + 100, pair);
				flags.ca = int32_t(byteCount) < 0 && (byteCount & 7) != 0;
				int32_t remaining = int32_t(byteCount) >> 3;
				if (remaining > 0) {
					do {
						int32_t half = remaining >> 1;
						uint32_t step = uint32_t(half) << 3;
						pair += step;
						if (int32_t(LOAD32(pair)) < 69) {
							remaining = remaining - half - 1;
							pair += 8;
						} else {
							pair -= step;
							remaining = half;
						}
					} while (remaining > 0);
					STORE32(stack + 100, pair);
				}
				if (pair != pairsEnd && int32_t(LOAD32(pair)) <= 69) {
					STORE64(stack + 112, LOAD64(stack + 96));
					entry = LOAD32(pair + 4);
				} else {
					entry = LOAD32(pairsEnd + 4);
				}
			}

			uint32_t list = entry + 24;
			if (LOAD32(entry + 32) != 0) {
				uint32_t listEnd = LOAD32(list + 4);
				uint32_t node = LOAD32(listEnd);
				while (node != listEnd) {
					uint32_t item = LOAD32(node + 8);
					if (LOAD32(item + 20) == targetId) {
						uint32_t holder = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
						// state the callee may pass on
						ctx.r6.u64 = r6Value;
						ctx.r8.u64 = holder;
						ctx.xer.ca = flags.ca;
						uint32_t linked = n_sub_82264448(ctx, base, LOAD32(holder), item);
						r6Value = ctx.r6.u64;
						uint64_t r8Value = ctx.r8.u64;
						if (linked != 0 && (LOAD8(linked + 144) & 64) != 0 && ((LOAD32(linked + 44) >> 3) & 1) != 0) {
							// entry 67 of the linked object's table, looked up the same way
							uint32_t value;
							uint32_t linkedIndex = LOAD32(linked + 140);
							uint32_t linkedPair = LOAD32(linked + 72);
							if (linkedIndex != 0) {
								value = LOAD32(linkedPair + (LOAD8(linkedIndex + 67) << 3) + 4);
							} else {
								uint32_t linkedEnd = LOAD32(linked + 76);
								r6Value = linkedEnd;
								STORE32(stack + 104, 0);
								uint32_t byteCount = linkedEnd - linkedPair;
								STORE32(stack + 108, linkedPair);
								flags.ca = int32_t(byteCount) < 0 && (byteCount & 7) != 0;
								int32_t remaining = int32_t(byteCount) >> 3;
								if (remaining > 0) {
									do {
										int32_t half = remaining >> 1;
										uint32_t step = uint32_t(half) << 3;
										r8Value = step;
										linkedPair += step;
										if (int32_t(LOAD32(linkedPair)) < 67) {
											remaining = remaining - half - 1;
											linkedPair += 8;
										} else {
											linkedPair -= step;
											remaining = half;
										}
									} while (remaining > 0);
									STORE32(stack + 108, linkedPair);
								}
								if (linkedPair != linkedEnd && int32_t(LOAD32(linkedPair)) <= 67) {
									STORE64(stack + 120, LOAD64(stack + 104));
									value = LOAD32(linkedPair + 4);
								} else {
									value = LOAD32(linkedEnd + 4);
								}
							}

							// state the callee may pass on
							ctx.r6.u64 = r6Value;
							ctx.r8.u64 = r8Value;
							ctx.xer.ca = flags.ca;
							n_sub_8274D188(ctx, base, stack + 84, value);
							StringHash_FromCharString(ctx, base, stack + 96, stack + 84, ctx.r8.u64);
							// insert the hash at the end of the list at stack + 128
							uint32_t tempListEnd = LOAD32(stack + 132);
							STORE32(stack + 112, stack + 128);
							STORE32(stack + 116, tempListEnd);
							List_InsertNodeCopyWord(ctx, base, stack + 128, LOAD64(stack + 112), stack + 96);
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);
							r6Value = ctx.r6.u64;
							flags.ca = ctx.xer.ca;
						}
					}
					listEnd = LOAD32(list + 4);
					if (node == listEnd) {
						ppc_trap(ctx, base, 22);
					}
					node = LOAD32(node);
				}
			}
		}

		// state the callee may pass on
		ctx.r6.u64 = r6Value;
		ctx.xer.ca = flags.ca;
		List_ClearFreeNodes(ctx, base, n_sub_82892770(ctx, base, infoMapAddr, stack + 80));
		uint64_t infoEntry = n_sub_82892770(ctx, base, infoMapAddr, stack + 80);
		n_sub_824FDF98(ctx, base, infoEntry, stack + 128);
		List_ClearFreeNodes(ctx, base, stack + 128);
		HandleTarget_Free(ctx, base, LOAD32(stack + 132));
		STORE32(stack + 132, 0);
		worldMapInfoAddr = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return worldMapInfoAddr;
}
PROMOTED_ENTRY(60, sub_828914E8, 0x828914E8) { ctx.r3.u64 = n_sub_828914E8(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82891898(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x82891898)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82891898(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82891898);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	uint32_t registry = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t target = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(registry + 88) + 4) + 8) + 4) + 36) + 4);
	uint64_t targetNameAddr = uint64_t(target) + 172;
	uint32_t nameData = LOAD32(target + 172);

	uint64_t result = worldMapInfoAddr;
	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = worldMapInfoAddr;  // state the callee may pass on
		uint32_t nameKey = n_sub_828924A8(ctx, base, targetNameAddr);
		uint32_t mapValue = n_sub_828923B8(ctx, base, worldMapInfoAddr, targetNameAddr);

		// n_sub_82792138 fills the vector at stack + 96 (begin at +100, end at +104, 4-byte elements);
		// stack + 88 holds the 40 it is given.
		uint32_t registryNow = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);
		STORE32(stack + 88, 40);
		STORE32(stack + 80, mapValue);
		uint32_t holder = LOAD32(registryNow + 88);
		uint32_t collector = LOAD32(LOAD32(holder + 4) + 12);
		// state the callee may pass on
		ctx.r7.u64 = holder;
		ctx.r9.u64 = 40;
		n_sub_82792138(ctx, base, collector, stack + 88, 4, stack + 96, registryNow);

		uint64_t mapAddr = worldMapInfoAddr + 60;
		uint32_t collectedBegin = LOAD32(stack + 100);
		uint32_t mapEnd = LOAD32(uint32_t(mapAddr) + 4);
		uint32_t collectedBytes = LOAD32(stack + 104) - collectedBegin;
		uint32_t collectedCount = uint32_t(int32_t(collectedBytes) >> 2);
		ctx.xer.ca = int32_t(collectedBytes) < 0 && (collectedBytes & 3) != 0;  // state the callee may pass on

		// find mapValue in the map; the iterator lands at stack + 88
		n_sub_822F5BC8(ctx, base, stack + 88, uint32_t(mapAddr), stack + 80);
		uint32_t iteratorMap = LOAD32(stack + 88);
		if (iteratorMap == 0 || iteratorMap != uint32_t(mapAddr)) {
			ppc_trap(ctx, base, 22);
		}
		uint64_t r5Value = stack + 80;
		if (LOAD32(stack + 92) == mapEnd) {
			STORE32(stack + 112, mapValue);
			// state the callee may pass on
			ctx.r4.u64 = mapAddr;
			ctx.r5.u64 = stack + 80;
			n_sub_82A12828(ctx, base, stack + 116);
			uint64_t newEntry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
			n_sub_8288E408(ctx, base, newEntry, stack + 112);
			n_sub_8292BB38(ctx, base, stack + 116);
			r5Value = ctx.r5.u64;
		}
		ctx.r5.u64 = r5Value;  // state the callee may pass on
		uint64_t entry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
		result = n_sub_8288D810(ctx, base, entry, nameKey, collectedCount);
		if (collectedBegin != 0) {
			result = HandleTarget_Free(ctx, base, collectedBegin);
		}
	}
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82891898, 0x82891898) { ctx.r3.u64 = n_sub_82891898(ctx, base, ctx.r3.u64); }

uint32_t n_sub_828919F0(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x828919F0)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_828919F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828919F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	uint32_t registry = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t target = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(registry + 88) + 4) + 8) + 4) + 36) + 4);
	uint64_t targetNameAddr = uint64_t(target) + 172;
	uint32_t nameData = LOAD32(target + 172);

	uint64_t result = worldMapInfoAddr;
	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = worldMapInfoAddr;  // state the callee may pass on
		uint32_t nameKey = n_sub_828924A8(ctx, base, targetNameAddr);
		uint32_t mapValue = n_sub_828923B8(ctx, base, worldMapInfoAddr, targetNameAddr);

		// n_sub_82792138 fills the vector at stack + 96 (begin at +100, end at +104, 4-byte elements);
		// stack + 88 holds the 95 it is given.
		uint32_t registryNow = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);
		STORE32(stack + 88, 95);
		STORE32(stack + 80, mapValue);
		uint32_t holder = LOAD32(registryNow + 88);
		uint32_t collector = LOAD32(LOAD32(holder + 4) + 12);
		// state the callee may pass on
		ctx.r7.u64 = holder;
		ctx.r9.u64 = 95;
		n_sub_82792138(ctx, base, collector, stack + 88, 3, stack + 96, registryNow);

		uint64_t mapAddr = worldMapInfoAddr + 84;
		uint32_t collectedBegin = LOAD32(stack + 100);
		uint32_t mapEnd = LOAD32(uint32_t(mapAddr) + 4);
		uint32_t collectedBytes = LOAD32(stack + 104) - collectedBegin;
		uint32_t collectedCount = uint32_t(int32_t(collectedBytes) >> 2);
		ctx.xer.ca = int32_t(collectedBytes) < 0 && (collectedBytes & 3) != 0;  // state the callee may pass on

		// find mapValue in the map; the iterator lands at stack + 88
		n_sub_822F5BC8(ctx, base, stack + 88, uint32_t(mapAddr), stack + 80);
		uint32_t iteratorMap = LOAD32(stack + 88);
		if (iteratorMap == 0 || iteratorMap != uint32_t(mapAddr)) {
			ppc_trap(ctx, base, 22);
		}
		uint64_t r5Value = stack + 80;
		if (LOAD32(stack + 92) == mapEnd) {
			STORE32(stack + 112, mapValue);
			// state the callee may pass on
			ctx.r4.u64 = mapAddr;
			ctx.r5.u64 = stack + 80;
			n_sub_82A12828(ctx, base, stack + 116);
			uint64_t newEntry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
			n_sub_8288E408(ctx, base, newEntry, stack + 112);
			n_sub_8292BB38(ctx, base, stack + 116);
			r5Value = ctx.r5.u64;
		}
		ctx.r5.u64 = r5Value;  // state the callee may pass on
		uint64_t entry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
		result = n_sub_8288D810(ctx, base, entry, nameKey, collectedCount);
		if (collectedBegin != 0) {
			result = HandleTarget_Free(ctx, base, collectedBegin);
		}
	}
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_828919F0, 0x828919F0) { ctx.r3.u64 = n_sub_828919F0(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82891B48(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x82891B48)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82891B48(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82891B48);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);
	stack = PushStackFrame(base, stack, 208);

	uint32_t registry = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t target = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(registry + 88) + 4) + 8) + 4) + 36) + 4);
	uint64_t targetNameAddr = uint64_t(target) + 172;
	uint32_t nameData = LOAD32(target + 172);

	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = worldMapInfoAddr;  // state the callee may pass on
		uint32_t nameKey = n_sub_828924A8(ctx, base, targetNameAddr);
		uint32_t mapValue = n_sub_828923B8(ctx, base, worldMapInfoAddr, targetNameAddr);

		// n_sub_82792138 fills the vector at stack + 96 (begin at +100, end at +104, 4-byte elements);
		// stack + 88 holds the 192 it is given.
		uint32_t registryNow = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);
		STORE32(stack + 88, 192);
		STORE32(stack + 80, mapValue);
		uint32_t holder = LOAD32(registryNow + 88);
		uint32_t holderInner = LOAD32(holder + 4);
		// state the callee may pass on
		ctx.r7.u64 = holderInner;
		ctx.r9.u64 = registryNow;
		n_sub_82792138(ctx, base, LOAD32(holderInner + 12), stack + 88, 4, stack + 96, holder);

		// r5, r6, r8 and xer.ca as the lifted code tracks them from here; the callees below receive them
		uint64_t r8Value = ctx.r8.u64;
		uint64_t r6Value = LOAD32(stack + 104);
		uint32_t collectedBegin = LOAD32(stack + 100);
		uint64_t r5Value = r6Value - collectedBegin;
		uint32_t collectedBytes = uint32_t(r5Value);
		flags.ca = int32_t(collectedBytes) < 0 && (collectedBytes & 3) != 0;
		uint32_t collectedCount = uint32_t(int32_t(collectedBytes) >> 2);

		// Count the collected objects (flag 0x40 at +144, bit 0 at +60) whose entry 192 n_sub_82707EB8
		// accepts; the entry comes from the object's sorted (type, value) table at +72, through the
		// cached index at +140 when there is one, otherwise by a lower_bound search.
		uint32_t acceptedCount = 0;
		if (int32_t(collectedCount) != 0) {
			uint32_t cursor = collectedBegin;
			uint32_t remaining = collectedCount;
			do {
				uint32_t object = LOAD32(cursor);
				if (object != 0 && (LOAD8(object + 144) & 64) != 0 && (LOAD32(object + 60) & 1) != 0) {
					uint32_t value;
					uint32_t cachedIndex = LOAD32(object + 140);
					if (cachedIndex != 0) {
						r8Value = uint64_t(uint32_t(LOAD8(cachedIndex + 192)) << 3) + uint64_t(LOAD32(object + 72));
						value = LOAD32(uint32_t(r8Value) + 4);
					} else {
						uint32_t pair = LOAD32(object + 72);
						uint32_t pairsEnd = LOAD32(object + 76);
						r6Value = pairsEnd;
						STORE32(stack + 88, 0);
						uint32_t byteCount = pairsEnd - pair;
						STORE32(stack + 92, pair);
						flags.ca = int32_t(byteCount) < 0 && (byteCount & 7) != 0;
						int32_t searchCount = int32_t(byteCount) >> 3;
						if (searchCount > 0) {
							do {
								int32_t half = searchCount >> 1;
								uint32_t step = uint32_t(half) << 3;
								r8Value = step;
								pair += step;
								if (int32_t(LOAD32(pair)) < 192) {
									searchCount = searchCount - half - 1;
									pair += 8;
								} else {
									pair -= step;
									searchCount = half;
								}
							} while (searchCount > 0);
							STORE32(stack + 92, pair);
						}
						if (pair != pairsEnd && int32_t(LOAD32(pair)) <= 192) {
							STORE64(stack + 96, LOAD64(stack + 88));
							value = LOAD32(pair + 4);
						} else {
							value = LOAD32(pairsEnd + 4);
						}
					}
					// state the callee may pass on
					ctx.r5.u64 = r5Value;
					ctx.r6.u64 = r6Value;
					ctx.r8.u64 = r8Value;
					ctx.xer.ca = flags.ca;
					uint32_t accepted = n_sub_82707EB8(ctx, base, value);
					r5Value = ctx.r5.u64;
					r6Value = ctx.r6.u64;
					r8Value = ctx.r8.u64;
					if ((accepted & 0xFF) != 0) {
						acceptedCount++;
					}
				}
				flags.ca = remaining > 0;  // carry of the count-down
				remaining--;
				cursor += 4;
			} while (int32_t(remaining) != 0);
		}

		uint64_t mapAddr = worldMapInfoAddr + 96;
		uint32_t mapEnd = worldMapInfo->m_64;
		// state the callee may pass on
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = flags.ca;
		// find mapValue in the map; the iterator lands at stack + 96
		n_sub_822F5BC8(ctx, base, stack + 96, uint32_t(mapAddr), stack + 80);
		uint32_t iteratorMap = LOAD32(stack + 96);
		if (iteratorMap == 0 || iteratorMap != uint32_t(mapAddr)) {
			ppc_trap(ctx, base, 22);
		}
		r5Value = stack + 80;
		if (LOAD32(stack + 100) == mapEnd) {
			STORE32(stack + 112, mapValue);
			// state the callee may pass on
			ctx.r4.u64 = mapAddr;
			ctx.r5.u64 = r5Value;
			ctx.r6.u64 = r6Value;
			n_sub_82A12828(ctx, base, stack + 116);
			uint64_t newEntry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
			n_sub_8288E408(ctx, base, newEntry, stack + 112);
			n_sub_8292BB38(ctx, base, stack + 116);
			r5Value = ctx.r5.u64;
			r6Value = ctx.r6.u64;
		}
		// state the callee may pass on
		ctx.r5.u64 = r5Value;
		ctx.r6.u64 = r6Value;
		uint64_t entry = n_sub_82892960(ctx, base, mapAddr, stack + 80);
		worldMapInfoAddr = n_sub_8288D810(ctx, base, entry, nameKey, acceptedCount);
		if (collectedBegin != 0) {
			worldMapInfoAddr = HandleTarget_Free(ctx, base, collectedBegin);
		}
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return worldMapInfoAddr;
}
PROMOTED_ENTRY(60, sub_82891B48, 0x82891B48) { ctx.r3.u64 = n_sub_82891B48(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82891E10(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t str_TXT_820C647C_B_ = int32_t(0x820C647C);
	constexpr int32_t str_TXT_820DFCD8_B_ = int32_t(0x820DFCD8);
	constexpr int32_t str_TXT_820DFCF4_B_ = int32_t(0x820DFCF4);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_8349E164 = int32_t(0x8349E164);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(60, 0x82891E10)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82891E10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82891E10);
	uint32_t stack = ctx.r1.u64;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);
	stack = PushStackFrame(base, stack, 208);

	// Returned unchanged when the name string below is empty.
	uint64_t result = worldMapInfoAddr;

	uint32_t globalRegistry = LOAD32(g_83490000 + 26912);
	uint32_t contextManager = LOAD32(LOAD32(LOAD32(globalRegistry + 12) + 88) + 4);
	uint32_t nameOwner = LOAD32(LOAD32(LOAD32(LOAD32(contextManager + 8) + 4) + 36) + 4);
	uint64_t nameString = (uint64_t)nameOwner + 172;    // a CCharString
	uint32_t nameData = LOAD32(nameOwner + 172);

	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		// state the callees may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = worldMapInfoAddr;
		ctx.r8.u64 = contextManager;
		n_sub_828924A8(ctx, base, nameString);

		uint32_t regionHash = n_sub_828923B8(ctx, base, worldMapInfoAddr, nameString);
		STORE32(stack + 92, regionHash);

		// Search the str_TXT_820DFCD8_B_ table for the record whose name hashes to regionHash.
		uint32_t gargoyleCount = 0;
		uint64_t regionInfoBaseHash = String_HashFnv1(ctx, base, str_TXT_820DFCD8_B_, 0xFFFFFFFF811C9DC5ULL);
		uint64_t regionTable = n_sub_829FB108(ctx, base, LOAD32(g_83490000 + 27600), regionInfoBaseHash);
		if ((uint32_t)regionTable != 0) {
			n_sub_829FBC40(ctx, base, stack + 80, regionTable, ctx.r8.u64);
			uint32_t i = LOAD32(stack + 88);
			uint32_t end = LOAD32(stack + 84);
			uint32_t entries = LOAD32(stack + 80);
			while (i != end) {
				uint32_t entryAddr = entries + i * 12;
				uint32_t entryObject = LOAD32(entryAddr + 8);
				uint32_t entryType = LOAD32(entryAddr);
				if (entryType == 4 && LOAD32(entryObject) == LOAD32(g_834A0000 - 7848)) {
					entryObject = uint32_t(g_8349E164);
				}
				uint32_t recordMap = LOAD32(g_83490000 + 27600);
				uint64_t record = HashMapU32_FindValue(ctx, base, recordMap, LOAD32(entryObject));
				if ((uint32_t)record != 0) {
					uint64_t name = n_sub_82345978(ctx, base, record, str_TXT_820C647C_B_);
					CCharString_ConstructFromCStr(ctx, base, stack + 80, name, -1);
					uint32_t strData = LOAD32(stack + 80);
					if (strData != 0 && LOAD32(strData + 4) != 0) {
						// state the callee may pass on
						ctx.r3.u64 = (uint32_t)worldMapInfoAddr;
						if ((uint32_t)n_sub_828924A8(ctx, base, stack + 80) == regionHash) {
							gargoyleCount = GameDB_GetIntByName(ctx, base, record, str_TXT_820DFCF4_B_);
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
							break;
						}
					}
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				}
				i = i + 1;
			}
			HandleTarget_Free(ctx, base, entries);
		}

		// Tree map at +108 (header node at +112), keyed by regionHash (stored at stack + 92).
		uint64_t regionMap = worldMapInfoAddr + 108;
		uint32_t regionMapHeader = worldMapInfo->m_70;
		uint64_t r5Value = stack + 92;
		n_sub_822F5BC8(ctx, base, stack + 80, regionMap, r5Value);
		uint32_t foundMap = LOAD32(stack + 80);
		if (foundMap == 0 || foundMap != (uint32_t)regionMap) {
			ppc_trap(ctx, base, 22);
		}
		if (LOAD32(stack + 84) == regionMapHeader) {
			// the find ended at the header: no node for the key yet
			STORE32(stack + 96, regionHash);
			// state the callee may pass on
			ctx.r4.u64 = regionMap;
			ctx.r5.u64 = r5Value;
			n_sub_82A12828(ctx, base, stack + 100);
			uint64_t newEntry = n_sub_82892960(ctx, base, regionMap, stack + 92);
			n_sub_8288E408(ctx, base, newEntry, stack + 96);
			n_sub_8292BB38(ctx, base, stack + 100);
			r5Value = ctx.r5.u64;
		}
		// state the callee may pass on
		ctx.r5.u64 = r5Value;
		uint64_t entry = n_sub_82892960(ctx, base, regionMap, stack + 92);
		result = n_sub_8288D810(ctx, base, entry, regionHash, gargoyleCount);
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(60, sub_82891E10, 0x82891E10) { ctx.r3.u64 = n_sub_82891E10(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82892040(CpuState& ctx, uint8_t* base, uint64_t worldMapInfo) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(60, 0x82892040)) { ctx.r3.u64 = worldMapInfo; __imp__sub_82892040(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82892040);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	// Returned unchanged when the name string below is empty.
	uint64_t result = worldMapInfo;

	const uint32_t globalBase = uint32_t(g_83490000);
	uint32_t manager = LOAD32(LOAD32(globalBase + 26912) + 12);
	uint32_t nameOwner = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(manager + 88) + 4) + 8) + 4) + 36) + 4);
	uint64_t nameString = (uint64_t)nameOwner + 172;    // a CCharString
	uint32_t nameData = LOAD32(nameOwner + 172);

	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = worldMapInfo;
		uint32_t nameHash = n_sub_828924A8(ctx, base, nameString);
		uint32_t mapKey = n_sub_828923B8(ctx, base, worldMapInfo, nameString);

		// n_sub_82792138 fills the array of 4-byte elements at stack + 96 (begin at +100, end at +104).
		uint32_t managerAgain = LOAD32(LOAD32(globalBase + 26912) + 12);
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);
		STORE32(stack + 88, 96);
		STORE32(stack + 80, mapKey);
		uint32_t sourceOwner = LOAD32(managerAgain + 88);
		uint32_t sourceList = LOAD32(LOAD32(sourceOwner + 4) + 12);
		// state the callee may pass on
		ctx.r7.u64 = sourceOwner;
		ctx.r9.u64 = 96;
		n_sub_82792138(ctx, base, sourceList, stack + 88, 3, stack + 96, managerAgain);

		// Tree map at +124 (header node at +128), keyed by mapKey (stored at stack + 80).
		uint64_t entryMap = worldMapInfo + 124;
		uint32_t listBegin = LOAD32(stack + 100);
		uint32_t entryMapHeader = LOAD32((uint32_t)entryMap + 4);
		uint32_t listBytes = LOAD32(stack + 104) - listBegin;
		uint32_t listCount = (int32_t)listBytes >> 2;
		// carry of the arithmetic shift, left in XER
		ctx.xer.ca = ((int32_t)listBytes < 0) & ((listBytes & 0x3) != 0);

		uint64_t r5Value = stack + 80;
		n_sub_822F5BC8(ctx, base, stack + 88, entryMap, r5Value);
		uint32_t foundMap = LOAD32(stack + 88);
		if (foundMap == 0 || foundMap != (uint32_t)entryMap) {
			ppc_trap(ctx, base, 22);
		}
		if (LOAD32(stack + 92) == entryMapHeader) {
			// the find ended at the header: no node for the key yet
			STORE32(stack + 112, mapKey);
			// state the callee may pass on
			ctx.r4.u64 = entryMap;
			ctx.r5.u64 = r5Value;
			n_sub_82A12828(ctx, base, stack + 116);
			uint64_t newEntry = n_sub_82892960(ctx, base, entryMap, stack + 80);
			n_sub_8288E408(ctx, base, newEntry, stack + 112);
			n_sub_8292BB38(ctx, base, stack + 116);
			r5Value = ctx.r5.u64;
		}
		// state the callee may pass on
		ctx.r5.u64 = r5Value;
		uint64_t mapEntry = n_sub_82892960(ctx, base, entryMap, stack + 80);
		result = n_sub_8288D810(ctx, base, mapEntry, nameHash, listCount);
		if (listBegin != 0) {
			result = HandleTarget_Free(ctx, base, listBegin);
		}
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(60, sub_82892040, 0x82892040) { ctx.r3.u64 = n_sub_82892040(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82892198(CpuState& ctx, uint8_t* base, uint64_t worldMapInfoAddr) {
	constexpr int32_t str_TXT_820C647C_B_ = int32_t(0x820C647C);
	constexpr int32_t str_TXT_820DFCD8_B_ = int32_t(0x820DFCD8);
	constexpr int32_t str_TXT_820DFD04_B_ = int32_t(0x820DFD04);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_8349E164 = int32_t(0x8349E164);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(60, 0x82892198)) { ctx.r3.u64 = worldMapInfoAddr; __imp__sub_82892198(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82892198);
	uint32_t stack = ctx.r1.u64;
	CECWorldMapInfo* worldMapInfo = GameObject<CECWorldMapInfo>(base, worldMapInfoAddr);
	stack = PushStackFrame(base, stack, 208);

	// Returned unchanged when the name string below is empty.
	uint64_t result = worldMapInfoAddr;

	uint32_t regionManager = LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
	uint32_t nameOwner = LOAD32(LOAD32(LOAD32(LOAD32(regionManager + 8) + 4) + 36) + 4);
	uint64_t nameString = (uint64_t)nameOwner + 172;    // a CCharString
	uint32_t nameData = LOAD32(nameOwner + 172);

	if (nameData != 0 && LOAD32(nameData + 4) != 0) {
		// state the callees may pass on
		ctx.r1.u64 = stack;
		ctx.r8.u64 = regionManager;
		uint32_t regionHash = n_sub_828923B8(ctx, base, worldMapInfoAddr, nameString);
		STORE32(stack + 92, regionHash);

		// Search the str_TXT_820DFCD8_B_ table for the record whose name hashes to regionHash.
		uint32_t silverKeyCount = 0;
		uint64_t regionInfoBaseHash = String_HashFnv1(ctx, base, str_TXT_820DFCD8_B_, 0xFFFFFFFF811C9DC5ULL);
		uint64_t regionTable = n_sub_829FB108(ctx, base, LOAD32(uint32_t(g_83490000) + 27600), regionInfoBaseHash);
		if ((uint32_t)regionTable != 0) {
			n_sub_829FBC40(ctx, base, stack + 80, regionTable, ctx.r8.u64);
			uint32_t index = LOAD32(stack + 88);
			uint32_t endIndex = LOAD32(stack + 84);
			uint32_t entries = LOAD32(stack + 80);
			while (index != endIndex) {
				uint32_t entry = entries + index * 12;
				uint32_t entryValue = LOAD32(entry + 8);
				uint32_t entryType = LOAD32(entry);
				if (entryType == 4 && LOAD32(entryValue) == LOAD32(uint32_t(g_834A0000) - 7848)) {
					entryValue = uint32_t(g_8349E164);
				}
				uint32_t recordMap = LOAD32(uint32_t(g_83490000) + 27600);
				uint64_t record = HashMapU32_FindValue(ctx, base, recordMap, LOAD32(entryValue));
				if ((uint32_t)record != 0) {
					uint64_t TXT_820C647C_L_ = n_sub_82345978(ctx, base, record, str_TXT_820C647C_B_);
					CCharString_ConstructFromCStr(ctx, base, stack + 80, TXT_820C647C_L_, -1);
					uint32_t strData = LOAD32(stack + 80);
					if (strData != 0 && LOAD32(strData + 4) != 0) {
						// state the callee may pass on
						ctx.r3.u64 = (uint32_t)worldMapInfoAddr;
						if ((uint32_t)n_sub_828924A8(ctx, base, stack + 80) == regionHash) {
							silverKeyCount = GameDB_GetIntByName(ctx, base, record, str_TXT_820DFD04_B_);
							CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
							break;
						}
					}
					CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				}
				index++;
			}
			HandleTarget_Free(ctx, base, entries);
		}

		// Tree map at +136 (header node at +140), keyed by regionHash (stored at stack + 92).
		uint64_t regionMap = worldMapInfoAddr + 136;
		uint32_t regionMapHeader = worldMapInfo->m_8C;
		uint64_t r5Value = stack + 92;
		n_sub_822F5BC8(ctx, base, stack + 80, regionMap, r5Value);
		uint32_t foundMap = LOAD32(stack + 80);
		if (foundMap == 0 || foundMap != (uint32_t)regionMap) {
			ppc_trap(ctx, base, 22);
		}
		if (LOAD32(stack + 84) == regionMapHeader) {
			// the find ended at the header: no node for the key yet
			STORE32(stack + 96, regionHash);
			// state the callee may pass on
			ctx.r4.u64 = regionMap;
			ctx.r5.u64 = r5Value;
			n_sub_82A12828(ctx, base, stack + 100);
			uint64_t newEntry = n_sub_82892960(ctx, base, regionMap, stack + 92);
			n_sub_8288E408(ctx, base, newEntry, stack + 96);
			n_sub_8292BB38(ctx, base, stack + 100);
			r5Value = ctx.r5.u64;
		}
		// state the callee may pass on
		ctx.r5.u64 = r5Value;
		uint64_t mapEntry = n_sub_82892960(ctx, base, regionMap, stack + 92);
		result = n_sub_8288D810(ctx, base, mapEntry, regionHash, silverKeyCount);
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(60, sub_82892198, 0x82892198) { ctx.r3.u64 = n_sub_82892198(ctx, base, ctx.r3.u64); }

// Hashes the name string, then walks the tree map at +148 (header node at +152) in order: returns the key
// (+12) of the first node whose id list (head at +20, size at +24) holds the hash, or the hash itself.
uint64_t n_sub_828923B8(CpuState& ctx, uint8_t* base, uint64_t worldMapInfo, uint64_t nameString) {
	if (!UseLiftedCode(60, 0x828923B8)) { ctx.r3.u64 = worldMapInfo; ctx.r4.u64 = nameString; __imp__sub_828923B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828923B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = worldMapInfo;
	uint64_t nameHash = n_sub_828924A8(ctx, base, nameString);

	// Iterator {tree, node} at stack + 80, starting at the header's first link.
	uint32_t header = LOAD32((uint32_t)worldMapInfo + 152);
	uint64_t tree = worldMapInfo + 148;
	uint64_t iterTree = tree;
	STORE32(stack + 80, (uint32_t)iterTree);
	uint32_t node = LOAD32(header);
	STORE32(stack + 84, node);

	for (;;) {
		uint32_t end = LOAD32((uint32_t)tree + 4);
		if ((uint32_t)iterTree == 0 || (uint32_t)iterTree != (uint32_t)tree) {
			ppc_trap(ctx, base, 22);
		}
		if (node == end) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			// callers read r9 and r10 after the call
			ctx.r9.u64 = end;
			ctx.r10.u64 = iterTree;
			return nameHash;
		}
		if ((uint32_t)iterTree == 0) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t iterEnd = LOAD32((uint32_t)iterTree + 4);
		if (node == iterEnd) {
			ppc_trap(ctx, base, 22);
		}
		uint64_t nodeKey = LOAD32(node + 12);
		if (node == iterEnd) {
			ppc_trap(ctx, base, 22);
		}

		uint32_t r9Value = end;    // r9: the tree end, then the last id compared
		uint32_t idList = 0;       // r10: the list head, or the list size (0) when the list is empty
		if (LOAD32(node + 24) != 0) {
			idList = LOAD32(node + 20);
			for (uint32_t link = LOAD32(idList); link != idList; link = LOAD32(link)) {
				r9Value = LOAD32(link + 8);
				if (r9Value == (uint32_t)nameHash) {
					stack = PopStackFrame(stack, 112);
					ctx.r1.u64 = stack;
					// callers read r9 and r10 after the call
					ctx.r9.u64 = r9Value;
					ctx.r10.u64 = idList;
					return nodeKey;
				}
				if (link == idList) {
					ppc_trap(ctx, base, 22);
				}
			}
		}
		// state the callee may pass on
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = idList;
		RbTreeIterator_Increment(ctx, base, stack + 80);
		node = LOAD32(stack + 84);
		iterTree = LOAD32(stack + 80);
	}
}
PROMOTED_ENTRY(60, sub_828923B8, 0x828923B8) { ctx.r3.u64 = n_sub_828923B8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_828924A8(CpuState& ctx, uint8_t* base, uint64_t sourceString) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_82000BF4 = int32_t(0x82000BF4);
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(60, 0x828924A8)) { ctx.r4.u64 = sourceString; __imp__sub_828924A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828924A8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint32_t nameCopy = stack + 80;    // CCharString copy of sourceString that is edited and hashed
	const uint32_t scratchA = stack + 84;
	const uint32_t scratchB = stack + 88;

	ctx.r1.u64 = stack;
	CCharString_CopyConstruct(ctx, base, nameCopy, sourceString);

	// Three replace passes over the copy, each pairing a constant string with the string at 0x82000BF4.
	CCharString_ConstructFromCStr(ctx, base, scratchB, g_82000BF4, -1);
	// state the callee may pass on
	ctx.r10.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, scratchA, g_82000000 + 3064, -1);
	CCharString_ReplaceAll(ctx, base, nameCopy, scratchA, scratchB);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchA);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchB);

	CCharString_ConstructFromCStr(ctx, base, scratchA, g_82000BF4, -1);
	// state the callee may pass on
	ctx.r9.s64 = g_820A0000;
	CCharString_ConstructFromCStr(ctx, base, scratchB, g_820A0000 + 25208, -1);
	CCharString_ReplaceAll(ctx, base, nameCopy, scratchB, scratchA);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchB);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchA);

	CCharString_ConstructFromCStr(ctx, base, scratchA, g_82000BF4, -1);
	// state the callee may pass on
	ctx.r8.s64 = g_82000000;
	CCharString_ConstructFromCStr(ctx, base, scratchB, g_82000000 + 3072, -1);
	CCharString_ReplaceAll(ctx, base, nameCopy, scratchB, scratchA);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchB);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchA);

	uint32_t transformed = CCharString_CopyTransformed(ctx, base, scratchB, nameCopy);
	uint32_t dataPtr = LOAD32(transformed);
	uint64_t charData = (dataPtr == 0) ? (uint64_t)g_8209003F : (uint64_t)LOAD32(dataPtr);

	uint64_t hashSeed = 0xFFFFFFFF811C9DC5ULL;    // the FNV-1 offset basis, sign-extended
	uint64_t hash = String_HashFnv1(ctx, base, charData, hashSeed);

	// state the callee may pass on
	ctx.r4.u64 = hashSeed;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratchB);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameCopy);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return hash;
}
PROMOTED_ENTRY(60, sub_828924A8, 0x828924A8) { ctx.r3.u64 = n_sub_828924A8(ctx, base, ctx.r4.u64); }
