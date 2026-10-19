// CECOpinionReaction (vtable 0x82004098): methods of the class as readable C++.
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

// sub_821DDFC0  [440 bytes]
// Reads no argument. Follows the entity handle at +104 of the first element of the array reached from the object
// 0x83496920 points to (+12, +88, +4) and releases the handle when its entity is gone. Returns 1 when that entity has
// flag 0x40 at +144 and a component under key 33 whose byte at +140 is non-zero, otherwise 0.
uint32_t CECOpinionReaction_HasReaction(CpuState& ctx, uint8_t* base) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(3, 0x821DDFC0)) { __imp__sub_821DDFC0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x821DDFC0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	uint32_t rootData = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t arrayHolder = LOAD32(rootData + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t firstElement = LOAD32(arrayBegin);
	uint64_t handleAddr = uint64_t(firstElement) + 104;
	uint32_t handleLink = LOAD32(firstElement + 108);

	// r8-r10 as the original code leaves them for its callers
	uint64_t r8Out = arrayBegin;
	uint64_t r9Out = arrayHolder;
	uint64_t r10Out = 0;
	uint32_t result = 0;
	if (handleLink != 0) {
		uint32_t entity = LOAD32(handleLink);
		if (entity == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
			r8Out = ctx.r8.u64;
			r9Out = ctx.r9.u64;
		} else {
			uint32_t flag40 = LOAD8(entity + 144) & 0x40;
			r9Out = flag40;
			if (flag40 != 0) {
				// bit 1 of the word at +40 is key 33 in the entity's bitset of component keys at +36
				uint32_t keyWord = LOAD32(entity + 40);
				uint32_t hasComponent = (keyWord >> 1) & 1;
				r8Out = hasComponent;
				r9Out = keyWord;
				if (hasComponent != 0) {
					// the component: its index comes from the byte table at +140 when present, otherwise the
					// sorted {key, value} pairs at +72..+76 are searched
					uint32_t component;
					uint32_t slotByKey = LOAD32(entity + 140);
					if (slotByKey != 0) {
						uint32_t slot = LOAD8(slotByKey + 33);
						uint32_t pairs = LOAD32(entity + 72);
						uint64_t entryAddr = uint64_t(slot << 3) + pairs;
						component = LOAD32((uint32_t)entryAddr + 4);
						r9Out = entryAddr;
					} else {
						// lower_bound for key 33; when the key is missing, the word at end + 4 is read
						uint32_t begin = LOAD32(entity + 72);
						uint32_t end = LOAD32(entity + 76);
						STORE32(stack + 80, 0);
						STORE32(stack + 84, begin);
						uint64_t spanBytes = uint64_t(end) - begin;
						int32_t count = int32_t(spanBytes) >> 3;
						// r7-r9 as the search leaves them
						uint64_t r7Out = ctx.r7.u64;
						r8Out = spanBytes;
						r9Out = 0;
						int32_t remaining = count;
						uint32_t it = begin;
						if (remaining > 0) {
							do {
								int32_t half = remaining >> 1;
								uint32_t halfBytes = uint32_t(half) << 3;
								uint32_t mid = it + halfBytes;
								bool keyBelow = (int32_t)LOAD32(mid) < 33;
								if (keyBelow) {
									remaining = remaining - half - 1;
									it = mid + 8;
								} else {
									remaining = half;
								}
								r7Out = keyBelow ? 1 : 0;
								r8Out = halfBytes;
								r9Out = uint64_t(int64_t(half));
							} while (remaining > 0);
							STORE32(stack + 84, it);
						}
						if (it != end && (int32_t)LOAD32(it) <= 33) {
							STORE64(stack + 80, LOAD64(stack + 80));  // the original copies the iterator pair onto itself
							component = LOAD32(LOAD32(stack + 84) + 4);
						} else {
							component = LOAD32(end + 4);
						}
						// callers read r6, r7, cr0 and the carry after the call
						ctx.r6.u64 = end;
						ctx.r7.u64 = r7Out;
						ctx.cr0.compare<int32_t>(count, 0, ctx.xer);
						ctx.xer.ca = int32_t(spanBytes) < 0 && (spanBytes & 0x7) != 0;
					}
					r10Out = component;
					if (LOAD8(component + 140) != 0) {
						result = 1;
					}
				}
			}
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r8-r10 after the call
	ctx.r8.u64 = r8Out;
	ctx.r9.u64 = r9Out;
	ctx.r10.u64 = r10Out;
	return result;
}
PROMOTED_ENTRY(3, sub_821DDFC0, 0x821DDFC0) { ctx.r3.u64 = CECOpinionReaction_HasReaction(ctx, base); }

uint64_t n_sub_822329E0(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr, uint64_t reactionEvent) {
	if (!UseLiftedCode(7, 0x822329E0)) { ctx.r3.u64 = opinionReactionAddr; ctx.r4.u64 = reactionEvent; __imp__sub_822329E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822329E0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);

	// First virtual call on reactionEvent (its vtable entry at offset +4).
	callTarget.u64 = LOAD32(LOAD32((uint32_t)reactionEvent) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = reactionEvent;
	ctx.r4.u64 = reactionEvent;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t firstResult = ctx.r3.u32;

	uint64_t result;
	if ((int32_t)firstResult == 8) {
		result = n_sub_82762F98(ctx, base, opinionReactionAddr);
	} else {
		callTarget.u64 = LOAD32(LOAD32((uint32_t)reactionEvent) + 4);
		ctx.r3.u64 = reactionEvent;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		if ((int32_t)result == 9 && LOAD8((uint32_t)reactionEvent + 4) == 0) {
			result = n_sub_82762F98(ctx, base, opinionReactionAddr);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_822329E0, 0x822329E0) { ctx.r3.u64 = n_sub_822329E0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82261710  [876 bytes]
uint64_t n_sub_82261710(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_8209C198 = int32_t(0x8209C198);
	constexpr int32_t str_TXT_820D19B8_B_ = int32_t(0x820D19B8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(9, 0x82261710)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82261710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82261710);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	// When m_30E and m_364 are both set: clears m_30E and hands the word that the table at 0x8209C198 holds for
	// m_364 to Stats_ApplyModifierIfAllowed and n_sub_82771DB0, with strings built from the owner entity's 64-bit
	// id (m_4 +20/+24).
	if (opinionReaction->m_30E != 0 && opinionReaction->m_364 != 0) {
		opinionReaction->m_30E = 0;

		uint32_t ownerEntity = opinionReaction->m_4;
		uint64_t ownerIdHigh = (uint64_t)LOAD32(ownerEntity + 20) << 32;
		uint64_t ownerId = ownerIdHigh | (uint64_t)LOAD32(ownerEntity + 24);

		ctx.r8.u64 = ownerIdHigh;  // state the callee may pass on
		CharString_ConstructFromUInt64(ctx, base, stack + 84, ownerId);

		CCharString_CopyConstruct(ctx, base, stack + 80, stack + 84);
		CCharString_AssignCString(ctx, base, stack + 80, str_TXT_820D19B8_B_);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 84);

		ctx.r6.s64 = g_82000000;  // state the callee may pass on
		CCharString_AssignFromWideStr(ctx, base, stack + 84, g_82000000 + 2804);

		uint32_t statModifier = LOAD32((uint32_t)g_8209C198 + (opinionReaction->m_364 << 2));
		uint32_t statsOwner = LOAD32(LOAD32(LOAD32(0x834968A4u) + 32) + 28);
		ctx.r8.u64 = opinionReaction->m_364 << 2;  // state the callee may pass on
		Stats_ApplyModifierIfAllowed(ctx, base, statsOwner, stack + 80, opinionReaction->m_4, stack + 84, statModifier);
		CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 84);

		uint32_t statModifierAgain = LOAD32((uint32_t)g_8209C198 + (opinionReaction->m_364 << 2));
		ctx.r3.u64 = opinionReactionAddr;  // state the callee may pass on
		n_sub_82771DB0(ctx, base, stack + 80, opinionReaction->m_4, 32767, statModifierAgain, ctx.r8.u64);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	}

	ctx.r1.u64 = stack;
	ctx.r3.u64 = opinionReactionAddr;  // state the callee may pass on
	uint32_t hasReaction = CECOpinionReaction_HasReaction(ctx, base) & 0xFF;

	if (hasReaction != 0) {
		n_sub_821F7CB0(ctx, base, opinionReactionAddr);
	}
	n_sub_8226B858(ctx, base, opinionReactionAddr);
	n_sub_8275DC90(ctx, base, opinionReactionAddr);
	n_sub_8275DE40(ctx, base, opinionReactionAddr);
	n_sub_8275DF58(ctx, base, opinionReactionAddr);
	CECOpinionReaction_Update(ctx, base, opinionReactionAddr);

	if (LOAD8(0x83318EA0u) != 0 && LOAD8(opinionReactionAddr + 779) != 0 && hasReaction == 0) {
		n_sub_82763C68(ctx, base, opinionReactionAddr);
	}
	if (LOAD8(0x83318EA1u) != 0 && LOAD8(opinionReactionAddr + 779) != 0) {
		ctx.r4.u64 = 0;  // state the callee may pass on
		n_sub_82266740(ctx, base, opinionReactionAddr);
	}
	if (LOAD8(0x83318EA2u) != 0 && hasReaction == 0) {
		n_sub_82764410(ctx, base, opinionReactionAddr);
	}

	// 0x83496B61, 0x83496B62 and 0x83496B64 are the DrawOpinions, DrawSpouse and DrawChild debug switches
	// (research/catalog/tuning.tsv).
	if (LOAD32(opinionReactionAddr + 20) == 0 && LOAD8(0x83496B61u) == 0) {
		bool skip = false;
		if (LOAD8(0x83496B62u) != 0) {
			skip = (n_sub_82268468(ctx, base, opinionReactionAddr) & 0xFF) != 0;
		}
		if (!skip && LOAD8(0x83496B64u) != 0) {
			n_sub_82268638(ctx, base, opinionReactionAddr);
		}
	}

	uint64_t result = n_sub_82268808(ctx, base, opinionReactionAddr, ctx.r8.u64);
	uint64_t r4Out = ctx.r4.u64;

	if (hasReaction == 0) {
		// Gets messages from the message-events object (element 4 of the root object's array) into the vector at
		// stack+96 and walks them in order: m_320 rises to any larger word at +32; at the first message whose id
		// (+44/+48) is the owner entity's id (+20/+24), m_3C8 goes up by one, m_3C4 is set and the walk stops.
		// Then the vector's buffer is freed.
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);
		STORE32(stack + 108, 0);

		uint32_t rootData = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		uint32_t messageEvents = LOAD32(LOAD32(LOAD32(rootData + 88) + 4) + 16);
		MessageEvents_GetAllMessages(ctx, base, messageEvents, 2, stack + 96, opinionReaction->m_320);
		r4Out = ctx.r4.u64;

		uint32_t begin = LOAD32(stack + 100);
		uint32_t end = LOAD32(stack + 104);
		if (begin > end) {
			ppc_trap(ctx, base, 22);
		}
		for (uint32_t it = begin;; it += 4) {
			if (begin > end) {
				ppc_trap(ctx, base, 22);
			}
			if (it == end) {
				break;
			}
			if (it >= end) {
				ppc_trap(ctx, base, 22);
			}
			uint32_t message = LOAD32(it);
			uint32_t value32 = LOAD32(message + 32);
			uint32_t highest = opinionReaction->m_320;
			if ((int32_t)value32 > (int32_t)highest) {
				opinionReaction->m_320 = value32;
			}
			uint32_t ownerEntity = opinionReaction->m_4;
			if (LOAD32(message + 44) == LOAD32(ownerEntity + 20) &&
			    LOAD32(message + 48) == LOAD32(ownerEntity + 24)) {
				uint32_t matchCount = opinionReaction->m_3C8 + 1;
				// the word at +8 of element 5 of the root object's array
				uint32_t element5Word =
				    LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4) + 20) + 8);
				opinionReaction->m_3C8 = matchCount;
				opinionReaction->m_3C4 = element5Word;
				break;
			}
			if (it >= end) {
				ppc_trap(ctx, base, 22);
			}
		}

		if (begin != 0) {
			result = HandleTarget_Free(ctx, base, begin);
			r4Out = ctx.r4.u64;
		} else {
			result = 0;  // the original returns the vector's begin, null here
		}
	}

	// m_3D4 counts down by one (not below 0) once the tick count at 0x8331950C is past m_3CC plus the interval at
	// 0x8349B424; m_3CC then takes the tick count, and m_3D8 is cleared when m_3D4 reaches 0.
	uint32_t countdown = opinionReaction->m_3D4;
	if ((int32_t)countdown != 0) {
		uint32_t interval = LOAD32(0x8349B424u);
		uint32_t tickCount = LOAD32(0x8331950Cu);
		uint32_t lastTick = opinionReaction->m_3CC;
		if ((int32_t)tickCount > (int32_t)(lastTick + interval)) {
			int32_t next = (int32_t)countdown - 1;
			opinionReaction->m_3D4 = (uint32_t)next;
			opinionReaction->m_3D4 = next < 0 ? 0u : (uint32_t)next;
			opinionReaction->m_3CC = tickCount;
			r4Out = opinionReaction->m_3D4;
			if ((int32_t)r4Out == 0) {
				opinionReaction->m_3D8 = 0;
			}
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;  // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(9, sub_82261710, 0x82261710) { ctx.r3.u64 = n_sub_82261710(ctx, base, ctx.r3.u64); }

// sub_82268468  [460 bytes]
// Follows the entity handle at +104 of the first element of the array reached from the object 0x83496920 points to
// (+12, +88, +4) and releases the handle when its entity is gone. When that entity has flag 0x40 at +144 and a
// component under key 136, returns 1 if IntrusiveList_ContainsKey finds the owner entity (m_4) in that component,
// otherwise 0.
uint64_t n_sub_82268468(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(9, 0x82268468)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82268468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82268468);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);

	stack = PushStackFrame(base, stack, 112);

	uint32_t rootData = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t arrayHolder = LOAD32(rootData + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t firstElement = LOAD32(arrayBegin);
	uint64_t handleAddr = uint64_t(firstElement) + 104;
	uint32_t handleLink = LOAD32(firstElement + 108);

	// r8-r10 as the original code leaves them for its callers
	uint64_t r8Out = arrayBegin;
	uint64_t r9Out = arrayHolder;
	uint64_t r10Out = 0;
	uint32_t result = 0;
	if (handleLink != 0) {
		uint32_t entity = LOAD32(handleLink);
		if (entity == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
			r8Out = ctx.r8.u64;
			r9Out = ctx.r9.u64;
		} else {
			uint32_t flag40 = LOAD8(entity + 144) & 0x40;
			r9Out = flag40;
			if (flag40 != 0) {
				// bit 8 of the word at +52 is key 136 in the entity's bitset of component keys at +36
				uint32_t keyWord = LOAD32(entity + 52);
				uint32_t hasComponent = (keyWord >> 8) & 1;
				r9Out = hasComponent;
				r10Out = keyWord;
				if (hasComponent != 0) {
					// cr0 and the carry as the original leaves them for callers; the call below may change them
					PPCCRRegister cr0Out = ctx.cr0;
					uint8_t carryOut = ctx.xer.ca;

					// the component: its index comes from the byte table at +140 when present, otherwise the
					// sorted {key, value} pairs at +72..+76 are searched
					uint32_t component;
					uint32_t slotByKey = LOAD32(entity + 140);
					if (slotByKey != 0) {
						uint32_t slotBytes = uint32_t(LOAD8(slotByKey + 136)) << 3;
						uint32_t pairs = LOAD32(entity + 72);
						uint64_t entryAddr = uint64_t(slotBytes) + pairs;
						component = LOAD32((uint32_t)entryAddr + 4);
						// state the callee may pass on
						ctx.r8.u64 = arrayBegin;
						ctx.r9.u64 = entryAddr;
						ctx.r10.u64 = slotBytes;
					} else {
						// lower_bound for key 136; when the key is missing, the word at end + 4 is read
						uint32_t begin = LOAD32(entity + 72);
						uint32_t end = LOAD32(entity + 76);
						STORE32(stack + 80, 0);
						STORE32(stack + 84, begin);
						uint64_t spanBytes = uint64_t(end) - begin;
						int32_t count = int32_t(spanBytes) >> 3;
						bool carry = int32_t(spanBytes) < 0 && (spanBytes & 0x7) != 0;
						cr0Out.compare<int32_t>(count, 0, ctx.xer);
						// r7-r9 as the search leaves them
						uint64_t r7State = ctx.r7.u64;
						uint64_t r8State = spanBytes;
						uint64_t r9State = 0;
						int32_t remaining = count;
						uint64_t it = begin;
						if (remaining > 0) {
							do {
								int32_t half = remaining >> 1;
								uint32_t halfBytes = uint32_t(half) << 3;
								uint64_t mid = it + halfBytes;
								bool keyBelow = (int32_t)LOAD32((uint32_t)mid) < 136;
								if (keyBelow) {
									remaining = remaining - half - 1;
									it = mid + 8;
								} else {
									remaining = half;
								}
								r7State = keyBelow ? 1 : 0;
								r8State = halfBytes;
								r9State = uint64_t(int64_t(half));
							} while (remaining > 0);
							STORE32(stack + 84, (uint32_t)it);
						}
						if ((uint32_t)it != end && (int32_t)LOAD32((uint32_t)it) <= 136) {
							STORE64(stack + 80, LOAD64(stack + 80));  // the original copies the iterator pair onto itself
							component = LOAD32(LOAD32(stack + 84) + 4);
						} else {
							component = LOAD32(end + 4);
						}
						carryOut = carry;
						// state the callee may pass on
						ctx.r6.u64 = end;
						ctx.r7.u64 = r7State;
						ctx.r8.u64 = r8State;
						ctx.r9.u64 = r9State;
						ctx.r10.u64 = it;
						ctx.xer.ca = carry;
					}

					uint32_t ownerEntity = opinionReaction->m_4;
					ctx.r1.u64 = stack;
					uint32_t found = IntrusiveList_ContainsKey(ctx, base, component, ownerEntity);
					if ((found & 0xFF) != 0) {
						result = 1;
					}
					r8Out = ctx.r8.u64;
					r9Out = ctx.r9.u64;
					r10Out = ctx.r10.u64;
					// callers read r4, cr0 and the carry after the call
					ctx.r4.u64 = ownerEntity;
					ctx.cr0 = cr0Out;
					ctx.xer.ca = carryOut;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r8-r10 after the call
	ctx.r8.u64 = r8Out;
	ctx.r9.u64 = r9Out;
	ctx.r10.u64 = r10Out;
	return result;
}
PROMOTED_ENTRY(9, sub_82268468, 0x82268468) { ctx.r3.u64 = n_sub_82268468(ctx, base, ctx.r3.u32); }

// sub_82268638  [460 bytes]
// Follows the entity handle at +104 of the first element of the array reached from the object 0x83496920 points to
// (+12, +88, +4) and releases the handle when its entity is gone. When that entity has flag 0x40 at +144 and a
// component under key 136, returns 1 if n_sub_82285670 accepts that component with the owner entity (m_4),
// otherwise 0.
uint32_t n_sub_82268638(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	if (!UseLiftedCode(9, 0x82268638)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82268638(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82268638);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);

	uint32_t rootData = LOAD32(LOAD32(0x83496920u) + 12);
	uint32_t arrayHolder = LOAD32(rootData + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t firstElement = LOAD32(arrayBegin);
	uint64_t handleAddr = uint64_t(firstElement) + 104;
	uint32_t handleLink = LOAD32(firstElement + 108);

	// r8-r10 as the original code leaves them for its callers
	uint64_t r8Out = arrayBegin;
	uint64_t r9Out = arrayHolder;
	uint64_t r10Out = 0;
	uint32_t result = 0;
	if (handleLink != 0) {
		uint32_t entity = LOAD32(handleLink);
		if (entity == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
			r8Out = ctx.r8.u64;
			r9Out = ctx.r9.u64;
		} else {
			uint32_t flag40 = LOAD8(entity + 144) & 0x40;
			r9Out = flag40;
			if (flag40 != 0) {
				// bit 8 of the word at +52 is key 136 in the entity's bitset of component keys at +36
				uint32_t keyWord = LOAD32(entity + 52);
				uint32_t hasComponent = (keyWord >> 8) & 1;
				r9Out = hasComponent;
				r10Out = keyWord;
				if (hasComponent != 0) {
					// cr0 and the carry as the original leaves them for callers; the call below may change them
					PPCCRRegister cr0Out = ctx.cr0;
					uint8_t carryOut = ctx.xer.ca;

					// the component: its index comes from the byte table at +140 when present, otherwise the
					// sorted {key, value} pairs at +72..+76 are searched
					uint32_t component;
					uint32_t slotByKey = LOAD32(entity + 140);
					if (slotByKey != 0) {
						uint32_t slotBytes = uint32_t(LOAD8(slotByKey + 136)) << 3;
						uint32_t pairs = LOAD32(entity + 72);
						uint64_t entryAddr = uint64_t(slotBytes) + pairs;
						component = LOAD32((uint32_t)entryAddr + 4);
						// state the callee may pass on
						ctx.r8.u64 = arrayBegin;
						ctx.r9.u64 = entryAddr;
						ctx.r10.u64 = slotBytes;
					} else {
						// lower_bound for key 136; when the key is missing, the word at end + 4 is read
						uint32_t begin = LOAD32(entity + 72);
						uint32_t end = LOAD32(entity + 76);
						STORE32(stack + 80, 0);
						STORE32(stack + 84, begin);
						uint64_t spanBytes = uint64_t(end) - begin;
						int32_t count = int32_t(spanBytes) >> 3;
						bool carry = int32_t(spanBytes) < 0 && (spanBytes & 0x7) != 0;
						cr0Out.compare<int32_t>(count, 0, ctx.xer);
						// r7-r9 as the search leaves them
						uint64_t r7State = ctx.r7.u64;
						uint64_t r8State = spanBytes;
						uint64_t r9State = 0;
						int32_t remaining = count;
						uint64_t it = begin;
						if (remaining > 0) {
							do {
								int32_t half = remaining >> 1;
								uint32_t halfBytes = uint32_t(half) << 3;
								uint64_t mid = it + halfBytes;
								bool keyBelow = (int32_t)LOAD32((uint32_t)mid) < 136;
								if (keyBelow) {
									remaining = remaining - half - 1;
									it = mid + 8;
								} else {
									remaining = half;
								}
								r7State = keyBelow ? 1 : 0;
								r8State = halfBytes;
								r9State = uint64_t(int64_t(half));
							} while (remaining > 0);
							STORE32(stack + 84, (uint32_t)it);
						}
						if ((uint32_t)it != end && (int32_t)LOAD32((uint32_t)it) <= 136) {
							STORE64(stack + 80, LOAD64(stack + 80));  // the original copies the iterator pair onto itself
							component = LOAD32(LOAD32(stack + 84) + 4);
						} else {
							component = LOAD32(end + 4);
						}
						carryOut = carry;
						// state the callee may pass on
						ctx.r6.u64 = end;
						ctx.r7.u64 = r7State;
						ctx.r8.u64 = r8State;
						ctx.r9.u64 = r9State;
						ctx.r10.u64 = it;
						ctx.xer.ca = carry;
					}

					uint32_t ownerEntity = opinionReaction->m_4;
					ctx.r1.u64 = stack;
					uint32_t accepted = n_sub_82285670(ctx, base, component, ownerEntity);
					if ((accepted & 0xFF) != 0) {
						result = 1;
					}
					r8Out = ctx.r8.u64;
					r9Out = ctx.r9.u64;
					r10Out = ctx.r10.u64;
					// callers read cr0 and the carry after the call
					ctx.cr0 = cr0Out;
					ctx.xer.ca = carryOut;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r8-r10 after the call
	ctx.r8.u64 = r8Out;
	ctx.r9.u64 = r9Out;
	ctx.r10.u64 = r10Out;
	return result;
}
PROMOTED_ENTRY(9, sub_82268638, 0x82268638) { ctx.r3.u64 = n_sub_82268638(ctx, base, ctx.r3.u32); }

// sub_8226B098  [1316 bytes]
// Compares the owner entity (m_4) with the entity behind the handle at +104 of the first element of the root
// object's array (the handle is released when its entity is gone; a missing entity reads from address 0).
// Component keys: bit (key % 32) of word (key / 32) of an entity's bitset at +36 says it has that component.
//  - entity with flag 0x40 at +144, and both have a key-122 component: 0 when n_sub_821C2C18 returns 1 for
//    either component;
//  - owner without a key-12 component: m_309 != 0;
//  - m_200 == 3: 0; m_200 == 0: 0 when the words at +12 of the two key-12 components are equal; m_200 == 1: 0 when
//    they differ; any other case: m_309 != 0.
uint64_t n_sub_8226B098(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(9, 0x8226B098)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_8226B098(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8226B098);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t rootData = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t arrayHolder = LOAD32(rootData + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t firstElement = LOAD32(arrayBegin);
	uint64_t handleAddr = uint64_t(firstElement) + 104;
	uint32_t handleLink = LOAD32(firstElement + 108);

	// r4-r10, cr0 and the carry as the original code leaves them for its callers, tracked through the code below
	const PPCXERRegister entryXer = ctx.xer;  // its summary-overflow bit goes into cr0 with each search
	uint64_t r4Out = ctx.r4.u64;
	uint64_t r5Out = ctx.r5.u64;
	uint64_t r6Out = ctx.r6.u64;
	uint64_t r7Out = ctx.r7.u64;
	uint64_t r8Out = arrayBegin;
	uint64_t r9Out = 0;
	uint64_t r10Out = 0;
	PPCCRRegister cr0Out = ctx.cr0;
	uint8_t carryOut = ctx.xer.ca;

	auto finish = [&](uint64_t result) -> uint64_t {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r4-r10, cr0 and the carry after the call
		ctx.r4.u64 = r4Out;
		ctx.r5.u64 = r5Out;
		ctx.r6.u64 = r6Out;
		ctx.r7.u64 = r7Out;
		ctx.r8.u64 = r8Out;
		ctx.r9.u64 = r9Out;
		ctx.r10.u64 = r10Out;
		ctx.cr0 = cr0Out;
		ctx.xer.ca = carryOut;
		return result;
	};
	// result m_309 != 0; r9 / r10 keep the zero test and the leading-zero count it comes from
	auto finishWithFlag309 = [&]() -> uint64_t {
		uint32_t flag309 = opinionReaction->m_309;
		uint32_t leadingZeros = flag309 == 0 ? 32 : __builtin_clz(flag309);
		uint32_t isZero = (leadingZeros >> 5) & 1;
		r9Out = isZero;
		r10Out = leadingZeros;
		return finish(isZero ^ 1);
	};
	// lower_bound for `key` in an entity's sorted {key, value} pairs [begin, end), returning the value; when the key
	// is missing, the word at `end` + 4 is read. Leaves r6-r8, cr0 and the carry as the original's search does;
	// halfOut / iterOut receive the half count / iterator where the original keeps them in r9 / r10.
	auto searchPairs = [&](uint32_t begin, uint32_t end, int32_t key, uint64_t* halfOut, uint64_t* iterOut) -> uint32_t {
		r6Out = end;
		STORE32(stack + 80, 0);
		uint64_t spanBytes = uint64_t(end) - begin;
		STORE32(stack + 84, begin);
		carryOut = int32_t(spanBytes) < 0 && (spanBytes & 0x7) != 0;
		int32_t count = int32_t(spanBytes) >> 3;
		cr0Out.compare<int32_t>(count, 0, entryXer);
		uint64_t it = begin;
		if (iterOut != nullptr) {
			*iterOut = it;
		}
		if (count > 0) {
			do {
				int32_t half = count >> 1;
				uint32_t halfBytes = uint32_t(half) << 3;
				uint64_t mid = it + halfBytes;
				bool keyBelow = (int32_t)LOAD32((uint32_t)mid) < key;
				if (keyBelow) {
					count = count - half - 1;
					it = mid + 8;
				} else {
					count = half;
				}
				r7Out = keyBelow ? 1 : 0;
				r8Out = halfBytes;
				if (halfOut != nullptr) {
					*halfOut = uint64_t(int64_t(half));
				}
			} while (count > 0);
			STORE32(stack + 84, (uint32_t)it);
			if (iterOut != nullptr) {
				*iterOut = it;
			}
		}
		if ((uint32_t)it != end && (int32_t)LOAD32((uint32_t)it) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));  // the original copies the iterator pair onto itself
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	uint32_t entity = 0;
	bool entityHasFlag40 = false;
	if (handleLink != 0) {
		uint32_t linked = LOAD32(handleLink);
		if (linked == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			EntityHandle_Release(ctx, base, handleAddr);
			r4Out = ctx.r4.u64;
			r5Out = ctx.r5.u64;
			r6Out = ctx.r6.u64;
			r7Out = ctx.r7.u64;
			r8Out = ctx.r8.u64;
			cr0Out = ctx.cr0;
			carryOut = ctx.xer.ca;
		} else {
			entity = linked;
			entityHasFlag40 = (LOAD8(linked + 144) & 0x40) != 0;
		}
	}

	if (entityHasFlag40) {
		// key 122: bit 26 of the word at +48
		uint32_t owner = opinionReaction->m_4;
		uint32_t ownerComponent122 = 0;
		r5Out = 0;
		uint32_t ownerHas122 = (LOAD32(owner + 48) >> 26) & 1;
		r9Out = ownerHas122;
		if (ownerHas122 != 0) {
			uint32_t slotByKey = LOAD32(owner + 140);
			if (slotByKey != 0) {
				uint32_t slot = LOAD8(slotByKey + 122);
				uint32_t pairs = LOAD32(owner + 72);
				uint64_t entryAddr = uint64_t(slot << 3) + pairs;
				ownerComponent122 = LOAD32((uint32_t)entryAddr + 4);
				r9Out = entryAddr;
			} else {
				uint32_t begin = LOAD32(owner + 72);
				uint32_t end = LOAD32(owner + 76);
				ownerComponent122 = searchPairs(begin, end, 122, &r9Out, nullptr);
			}

			uint32_t entityHas122 = (LOAD32(entity + 48) >> 26) & 1;
			r10Out = entityHas122;
			if (entityHas122 != 0) {
				uint32_t entityComponent122;
				uint32_t entitySlotByKey = LOAD32(entity + 140);
				if (entitySlotByKey != 0) {
					uint32_t slotBytes = uint32_t(LOAD8(entitySlotByKey + 122)) << 3;
					uint64_t entryAddr = uint64_t(slotBytes) + LOAD32(entity + 72);
					entityComponent122 = LOAD32((uint32_t)entryAddr + 4);
					r9Out = entryAddr;
					r10Out = slotBytes;
				} else {
					uint32_t begin = LOAD32(entity + 72);
					uint32_t end = LOAD32(entity + 76);
					entityComponent122 = searchPairs(begin, end, 122, &r9Out, &r10Out);
				}
				r5Out = entityComponent122;

				ctx.r1.u64 = stack;
				if ((int32_t)n_sub_821C2C18(ctx, base, ownerComponent122) == 1) {
					return finish(0);
				}
				if ((int32_t)n_sub_821C2C18(ctx, base, entityComponent122) == 1) {
					return finish(0);
				}
			}
		}
	}

	// key 12: bit 12 of the word at +36
	uint32_t owner = opinionReaction->m_4;
	r4Out = 0;
	uint32_t ownerKeyWord = LOAD32(owner + 36);
	r10Out = ownerKeyWord;
	uint32_t ownerHas12 = (ownerKeyWord >> 12) & 1;
	r9Out = ownerHas12;
	if (ownerHas12 == 0) {
		return finishWithFlag309();
	}
	uint32_t ownerComponent12;
	uint32_t ownerSlotByKey = LOAD32(owner + 140);
	if (ownerSlotByKey != 0) {
		uint32_t slot = LOAD8(ownerSlotByKey + 12);
		uint32_t pairs = LOAD32(owner + 72);
		uint64_t entryAddr = uint64_t(slot << 3) + pairs;
		ownerComponent12 = LOAD32((uint32_t)entryAddr + 4);
		r8Out = entryAddr;
		r9Out = slot;
		r10Out = pairs;
	} else {
		uint32_t begin = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		ownerComponent12 = searchPairs(begin, end, 12, &r9Out, &r10Out);
	}
	r4Out = ownerComponent12;

	uint32_t mode = opinionReaction->m_200;
	r5Out = mode;
	if ((int32_t)mode == 3) {
		return finish(0);
	}

	uint32_t entityComponent12 = 0;
	if (((LOAD32(entity + 36) >> 12) & 1) != 0) {
		uint32_t entitySlotByKey = LOAD32(entity + 140);
		uint32_t pairs = LOAD32(entity + 72);
		if (entitySlotByKey != 0) {
			uint32_t slot = LOAD8(entitySlotByKey + 12);
			entityComponent12 = LOAD32((slot << 3) + pairs + 4);
		} else {
			uint32_t end = LOAD32(entity + 76);
			entityComponent12 = searchPairs(pairs, end, 12, nullptr, nullptr);
		}
	}

	if ((int32_t)mode == 0) {
		uint32_t ownerWord12 = LOAD32(ownerComponent12 + 12);
		uint32_t entityWord12 = LOAD32(entityComponent12 + 12);
		r10Out = ownerWord12;
		r9Out = entityWord12;
		if (ownerWord12 == entityWord12) {
			return finish(0);
		}
		return finishWithFlag309();
	}
	if ((int32_t)mode == 1) {
		uint32_t ownerWord12 = LOAD32(ownerComponent12 + 12);
		uint32_t entityWord12 = LOAD32(entityComponent12 + 12);
		r10Out = ownerWord12;
		r9Out = entityWord12;
		if (ownerWord12 != entityWord12) {
			return finish(0);
		}
	}
	return finishWithFlag309();
}
PROMOTED_ENTRY(9, sub_8226B098, 0x8226B098) { ctx.r3.u64 = n_sub_8226B098(ctx, base, ctx.r3.u32); }

// sub_8226B858  [204 bytes]
// Has n_sub_8229C288 fill a vector on the stack from element 7 of the root object's array and
// opinionReactionAddr + 496, calls n_sub_82759570 for each word in it (with the first element of that array), then
// frees the vector's buffer.
uint32_t n_sub_8226B858(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(9, 0x8226B858)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_8226B858(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8226B858);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// the vector object at stack+80; its begin/end/capacity words at +84..+92 start empty
	uint64_t vectorAddr = uint64_t(stack) + 80;
	STORE32(stack + 84, 0);
	STORE32(stack + 88, 0);
	STORE32(stack + 92, 0);

	uint32_t rootData = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t element7 = LOAD32(LOAD32(LOAD32(rootData + 88) + 4) + 28);
	ctx.r1.u64 = stack;
	n_sub_8229C288(ctx, base, element7, opinionReactionAddr + 496, vectorAddr);

	uint32_t rootDataNow = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t begin = LOAD32(stack + 84);
	uint32_t end = LOAD32(stack + 88);
	uint32_t arrayHolder = LOAD32(rootDataNow + 88);
	uint32_t arrayBegin = LOAD32(arrayHolder + 4);
	uint32_t firstElement = LOAD32(arrayBegin);

	// r6-r8 handed to n_sub_82759570: the array chain at first, then what the previous call left there;
	// r8 is also left for callers
	uint64_t r6State = arrayBegin;
	uint64_t r7State = arrayHolder;
	uint64_t r8State = rootDataNow;

	if (begin > end) {
		ppc_trap(ctx, base, 22);
	}
	for (uint32_t it = begin;; it += 4) {
		if (begin > end) {
			ppc_trap(ctx, base, 22);
		}
		if (it == end) {
			break;
		}
		if (it >= end) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t entry = LOAD32(it);
		// state the callee may pass on
		ctx.r8.u64 = r8State;
		n_sub_82759570(ctx, base, opinionReactionAddr, entry, firstElement);
		r6State = ctx.r6.u64;
		r7State = ctx.r7.u64;
		r8State = ctx.r8.u64;
		end = LOAD32(stack + 88);
		if (it >= end) {
			ppc_trap(ctx, base, 22);
		}
		begin = LOAD32(stack + 84);
	}

	uint32_t result = 0;  // the original returns the vector's begin, null here
	if (begin != 0) {
		ctx.r8.u64 = r8State;  // state the callee may pass on
		result = HandleTarget_Free(ctx, base, begin);
		r8State = ctx.r8.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = r8State;  // callers read r8 after the call
	return result;
}
PROMOTED_ENTRY(9, sub_8226B858, 0x8226B858) { ctx.r3.u64 = n_sub_8226B858(ctx, base, ctx.r3.u64); }

uint64_t CECOpinionReaction_Update(CpuState& ctx, uint8_t* base, uint64_t objectAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(10, 0x82281B48)) { ctx.r3.u64 = objectAddr; __imp__sub_82281B48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82281B48);
	uint32_t stack = ctx.r1.u64;

	// Registers callers read after the return. r4: the caller's r4, then the condition-register word
	// of each upper clamp, or what an erase call left. r8: the constant base, then each entry pointer,
	// or what an erase call left. The word uses cr0/cr1/cr5/cr7 as the last erase call left them
	// (the entry values before one) and cr2-cr4 from entry.
	uint64_t callerR4 = ctx.r4.u64;
	uint64_t callerR8 = (uint64_t)(int64_t)g_820A0000;
	PPCCRRegister cr0 = ctx.cr0, cr1 = ctx.cr1, cr5 = ctx.cr5, cr7 = ctx.cr7;
	const PPCCRRegister cr2 = ctx.cr2, cr3 = ctx.cr3, cr4 = ctx.cr4;
	auto conditionWord = [&](const PPCCRRegister& cr6) -> uint32_t {
		auto field = [](const PPCCRRegister& cr) -> uint32_t {
			return (cr.lt ? 8u : 0u) | (cr.gt ? 4u : 0u) | (cr.eq ? 2u : 0u) | (cr.so ? 1u : 0u);
		};
		return field(cr0) << 28 | field(cr1) << 24 | field(cr2) << 20 | field(cr3) << 16
			| field(cr4) << 12 | field(cr5) << 8 | field(cr6) << 4 | field(cr7);
	};

	stack = PushStackFrame(base, stack, 160);

	const uint32_t iterator = stack + 80;     // checked iterator { container, node }
	const uint32_t tickScratch = stack + 88;  // integer-to-float conversion slot
	const uint32_t eraseOutSlot = stack + 96;

	const uint64_t listArg = (int64_t)objectAddr + 316;
	const uint32_t list = (uint32_t)listArg;
	uint32_t iterContainer = list;
	const uint32_t now = LOAD32(0x8331950Cu);
	uint32_t node = LOAD32(LOAD32((uint32_t)objectAddr + 320));
	STORE32(iterator, iterContainer);
	// Each entry's value is clamped to [lowerLimit, upperLimit] (0 and 1) through a two-entry sign
	// table { 1, -1 }: a comparison that fails or is unordered picks the negative entry.
	const uint32_t selectTable = uint32_t(g_82100170);
	const uint32_t limits = uint32_t(g_820A0000) - 27456;
	const double upperLimit = (double)LOAD_F32(limits);
	const double lowerLimit = (double)LOAD_F32(limits - 12);

	// The original leaves the last value written to r3 as the result.
	uint64_t result = objectAddr;

	STORE32(iterator + 4, node);
	for (;;) {
		const uint32_t listEnd = LOAD32(list + 4);
		if (iterContainer == 0 || iterContainer != list) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == listEnd) break;

		if (iterContainer == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t containerEnd = LOAD32(iterContainer + 4);
		if (node == containerEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t entry = LOAD32(node + 8);
		if (node == containerEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
			ppc_trap(ctx, base, 22);
		}

		// Decay the value by rate * elapsed ticks.
		ctx.fpscr.disableFlushMode();
		const double rate = (double)LOAD_F32(entry + 8);
		const double value = (double)LOAD_F32(entry + 4);
		const int32_t elapsedTicks = int32_t(now - LOAD32(entry + 12));
		STORE64(tickScratch, (uint64_t)(int64_t)elapsedTicks);
		const double elapsed = (double)(float)(double)(int64_t)LOAD64(tickScratch);
		STORE_F32(entry + 4, float(-std::fma(elapsed, rate, -value)));
		if (node == LOAD32(iterContainer + 4)) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		ctx.fpscr.disableFlushMode();
		const double decayed = (double)LOAD_F32(entry + 4);
		const double selectLow = (double)LOAD_F32(selectTable + (decayed >= lowerLimit ? 0u : 4u));
		const double clampedLow = (selectLow >= 0.0) ? decayed : lowerLimit;
		const double excess = (double)(float)(clampedLow - upperLimit);
		PPCCRRegister excessCompare{};
		excessCompare.compare(excess, lowerLimit);
		callerR4 = conditionWord(excessCompare);
		result = excessCompare.lt ? 4u : 0u;
		const uint32_t highIndex = (excessCompare.lt || excessCompare.un) ? 4u : 0u;
		const double selectHigh = (double)LOAD_F32(selectTable + highIndex);
		const double clamped = (selectHigh >= 0.0) ? upperLimit : clampedLow;
		STORE_F32(entry + 4, float(clamped));

		const uint32_t endBeforeStamp = LOAD32(iterContainer + 4);
		if (node == endBeforeStamp) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		STORE32(entry + 12, now);
		const uint32_t endAfterStamp = LOAD32(iterContainer + 4);
		if (node == endAfterStamp) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t entryAgain = LOAD32(node + 8);
		callerR8 = entryAgain;
		ctx.fpscr.disableFlushMode();
		if (!((double)LOAD_F32(entryAgain + 4) > lowerLimit)) {
			// Decayed to the floor: erase the node; the erase hands back the next iterator.
			ctx.r1.u64 = stack;
			// state the callee may pass on
			result = SharedHandleList_Erase(ctx, base, eraseOutSlot, listArg, LOAD64(iterator));
			callerR4 = ctx.r4.u64;
			callerR8 = ctx.r8.u64;
			cr0 = ctx.cr0;
			cr1 = ctx.cr1;
			cr5 = ctx.cr5;
			cr7 = ctx.cr7;
			STORE64(iterator, LOAD64((uint32_t)result));
			node = LOAD32(iterator + 4);
			iterContainer = LOAD32(iterator);
			continue;
		}

		if (node == endAfterStamp) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
		STORE32(iterator + 4, node);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4 and r8 after the return
	ctx.r4.u64 = callerR4;
	ctx.r8.u64 = callerR8;
	return result;
}
PROMOTED_ENTRY(10, sub_82281B48, 0x82281B48) { ctx.r3.u64 = CECOpinionReaction_Update(ctx, base, ctx.r3.u64); }

uint64_t CECOpinionReaction_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8B68_B_ = int32_t(0x820C8B68);
	if (!UseLiftedCode(50, 0x82755E50)) { ctx.r3.u64 = classNameString; __imp__sub_82755E50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82755E50);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	const uint64_t className = str_TXT_820C8B68_B_;
	const int32_t length = -1;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, className, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(50, sub_82755E50, 0x82755E50) { ctx.r3.u64 = CECOpinionReaction_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827563F0(CpuState& ctx, uint8_t* base, uint64_t objectAddr, uint64_t freeFlags) {
	if (!UseLiftedCode(50, 0x827563F0)) { ctx.r3.u64 = objectAddr; ctx.r4.u64 = freeFlags; __imp__sub_827563F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827563F0);
	uint32_t stack = ctx.r1.u64;
	const bool freeObject = (uint32_t(freeFlags) & 0x1) != 0;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = freeFlags;  // state the callee may pass on
	n_sub_82756440(ctx, base, objectAddr);
	if (freeObject) {
		HandleTarget_Free(ctx, base, objectAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectAddr;
}
PROMOTED_ENTRY(50, sub_827563F0, 0x827563F0) { ctx.r3.u64 = n_sub_827563F0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_8275D050(CpuState& ctx, uint8_t* base, uint64_t reaction, uint64_t changeKind, double changeAmount) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820D2560_B_ = int32_t(0x820D2560);
	constexpr int32_t str_TXT_820D257C_B_ = int32_t(0x820D257C);
	constexpr int32_t str_TXT_820D2594_B_ = int32_t(0x820D2594);
	constexpr int32_t str_TXT_820D25AC_B_ = int32_t(0x820D25AC);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(50, 0x8275D050)) { ctx.r3.u64 = reaction; ctx.r4.u64 = changeKind; ctx.f1.f64 = changeAmount; __imp__sub_8275D050(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8275D050);
	uint32_t stack = ctx.r1.u64;
	// r10 as the closing string release receives it
	uint32_t r10Live{};
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 160);
	ctx.r1.u64 = stack;

	const uint32_t nameString = stack + 80;
	const uint32_t recordRef = stack + 88;
	const uint32_t eventData = stack + 96;

	const uint32_t changeValue = n_sub_8275D1B8(ctx, base, reaction, changeKind, changeAmount);
	CCharString_ConstructFromCStr(ctx, base, nameString, g_82000C98, -1);
	r10Live = ctx.r10.u32;

	if ((int32_t)changeKind == 2 || (int32_t)changeKind == 1) {
		const bool positive = (int32_t)changeValue > 0;
		const uint64_t newName = (int32_t)changeKind == 2
			? (positive ? str_TXT_820D2560_B_ : str_TXT_820D257C_B_)
			: (positive ? str_TXT_820D2594_B_ : str_TXT_820D25AC_B_);
		CCharString_AssignFromCStr(ctx, base, nameString, newName);
		r10Live = ctx.r10.u32;
	}

	const uint32_t nameData = LOAD32(nameString);
	if (nameData != 0 && (int32_t)LOAD32(nameData + 4) != 0 && (int32_t)changeValue != 0) {
		GameDBRecordRef_Construct(ctx, base, recordRef, nameString);
		r10Live = ctx.r10.u32;
		const uint32_t record = LOAD32(recordRef);
		if (record != 0) {
			const uint32_t globals = uint32_t(g_83490000);
			const uint32_t entityList = LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88);
			const uint32_t entitySlot = LOAD32(entityList + 4);
			const uint32_t handleOwner = LOAD32(entitySlot);
			// state the callee may pass on
			const uint64_t entity = EntityHandle_Get(ctx, base, handleOwner);
			r10Live = ctx.r10.u32;

			bool entityFlagSet = false;
			if ((uint32_t)entity != 0) {
				r10Live = LOAD8((uint32_t)entity + 144) & 64;
				entityFlagSet = r10Live != 0;
			}
			if (entityFlagSet) {
				const uint32_t component = LOAD32((uint32_t)entity + 124);
				const uint32_t owner = LOAD32((uint32_t)reaction + 4);
				// The component's virtual at vtable +64 fills eventData.
				const uint32_t virtualFn = LOAD32(LOAD32(component) + 64);
				callTarget.u64 = (uint64_t)virtualFn;
				ctx.r3.u64 = eventData;
				ctx.r4.u64 = component;
				ctx.r10.u64 = virtualFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				// The same slot as above, read again after the calls.
				const uint32_t eventSlot = LOAD32(LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88) + 4);
				const uint32_t eventTarget = LOAD32(eventSlot + 16);
				ctx.r10.u64 = eventSlot;  // state the callee may pass on
				MessageEvents_PostMessageEvent(ctx, base, eventTarget, 50, eventData, entity, owner, 101, record);
				r10Live = ctx.r10.u32;
			}
		}
	}

	ctx.r10.u64 = r10Live;  // state the callee may pass on
	const uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(50, sub_8275D050, 0x8275D050) { ctx.r3.u64 = n_sub_8275D050(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint32_t n_sub_8275DC90(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	if (!UseLiftedCode(50, 0x8275DC90)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_8275DC90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8275DC90);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);

	// Register state the erase call receives and callers read after the return. f5-f7 carry the last
	// reaction test (or what the erase call left); cr0 and xer.ca follow the loop counter and the erase
	// call; the condition word in r7 uses cr1/cr5/cr7 as the erase call left them and cr2-cr4 from entry.
	double f5 = ctx.f5.f64, f6 = ctx.f6.f64, f7 = ctx.f7.f64;
	PPCCRRegister cr0 = ctx.cr0, cr1 = ctx.cr1, cr5 = ctx.cr5, cr7 = ctx.cr7;
	const PPCCRRegister cr2 = ctx.cr2, cr3 = ctx.cr3, cr4 = ctx.cr4;
	PPCXERRegister flags = ctx.xer;
	auto conditionWord = [&](const PPCCRRegister& cr6) -> uint32_t {
		auto field = [](const PPCCRRegister& cr) -> uint32_t {
			return (cr.lt ? 8u : 0u) | (cr.gt ? 4u : 0u) | (cr.eq ? 2u : 0u) | (cr.so ? 1u : 0u);
		};
		return field(cr0) << 28 | field(cr1) << 24 | field(cr2) << 20 | field(cr3) << 16
			| field(cr4) << 12 | field(cr5) << 8 | field(cr6) << 4 | field(cr7);
	};
	// The last belief clamp's intermediates, which callers read after the return.
	uint32_t lowIndex = 0, ltIndex = 0, highIndex = 0, clampWord = 0;
	PPCRegister lowSelect{}, belowUpper{};
	double atLeastLower = 0.0, highSelect = 0.0, clampedBelief = 0.0;

	stack = PushStackFrame(base, stack, 192);
	uint64_t result = opinionReactionAddr;
	// Beliefs are clamped to [lowerBound, upperBound] (-1 and 1) through a two-entry sign table { 1, -1 }:
	// a comparison against zero that fails or is unordered picks the negative entry.
	const uint32_t constants = uint32_t(g_820A0000) - 27456;
	uint32_t beliefAddr = (uint32_t)opinionReactionAddr + 24;
	const double upperBound = (double)LOAD_F32(constants);
	uint64_t listAddr = (int64_t)opinionReactionAddr + 176;
	uint32_t remaining = 5;
	const double lowerBound = (double)LOAD_F32(constants + 18756);
	const uint32_t selectTable = uint32_t(g_82100170);
	const double zero = (double)LOAD_F32(constants - 12);

	// Five (belief, reaction list) pairs: beliefs are floats from +24, lists 12 bytes apart from +176.
	do {
		const uint32_t list = (uint32_t)listAddr;
		const uint32_t sentinel = LOAD32(list + 4);
		uint64_t iterContainer = listAddr;  // checked iterator { container, node } at stack + 80
		STORE32(stack + 80, (uint32_t)iterContainer);
		uint32_t node = LOAD32(sentinel);
		STORE32(stack + 84, node);
		for (;;) {
			const uint32_t listEnd = LOAD32(list + 4);
			if ((uint32_t)iterContainer == 0 || (uint32_t)iterContainer != list) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == listEnd) break;
			if ((uint32_t)iterContainer == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t containerEnd = LOAD32((uint32_t)iterContainer + 4);
			if (node == containerEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t reaction = LOAD32(node + 8);
			const int32_t requiredOpinion = int32_t(opinionReaction->m_1F0);
			const int32_t reactionOpinion = (int32_t)LOAD32(reaction);
			ctx.fpscr.disableFlushMode();
			const double reactionWeight = (double)LOAD_F32(reaction + 8);
			const double reactionStrength = (double)LOAD_F32(reaction + 4);
			// The integer opinions reach the FPU through frame slots.
			STORE64(stack + 88, (uint64_t)(int64_t)requiredOpinion);
			STORE64(stack + 96, (uint64_t)(int64_t)reactionOpinion);
			const double reactionOpinionExact = (double)(int64_t)reactionOpinion;
			const double combinedWeight = (double)(float)(reactionWeight + reactionStrength);
			f7 = (double)(float)reactionOpinionExact;
			f6 = (double)(float)(double)(int64_t)requiredOpinion;
			f5 = (double)(float)(combinedWeight + f7);  // the reaction's total
			if (!(f6 < f5)) {
				// The required opinion is not below the total: fold the reaction's influence into the
				// belief and erase the reaction.
				ctx.fpscr.disableFlushMode();
				const double opinionInfluence = (double)opinionReaction->m_1EC;
				const double reactionInfluence = (double)LOAD_F32(reaction + 20);
				const double oldBelief = (double)LOAD_F32(beliefAddr);
				const uint64_t iteratorValue = LOAD64(stack + 80);
				const double newBelief = (double)(float)std::fma(opinionInfluence, reactionInfluence, oldBelief);
				STORE_F32(beliefAddr, float(newBelief));
				ctx.r1.u64 = stack;
				// state the callee may pass on
				ctx.cr0 = cr0;
				ctx.xer.ca = flags.ca;
				result = SharedHandleList_Erase(ctx, base, (uint64_t)stack + 104, listAddr, iteratorValue);
				f5 = ctx.f5.f64;
				f6 = ctx.f6.f64;
				f7 = ctx.f7.f64;
				cr0 = ctx.cr0;
				cr1 = ctx.cr1;
				cr5 = ctx.cr5;
				cr7 = ctx.cr7;
				flags.ca = ctx.xer.ca;
				STORE64(stack + 80, LOAD64((uint32_t)result));
				node = LOAD32(stack + 84);
				iterContainer = LOAD32(stack + 80);
				continue;
			}
			if (node == containerEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
			STORE32(stack + 84, node);
		}

		// Clamp the belief from below, then from above.
		ctx.fpscr.disableFlushMode();
		const double belief = (double)LOAD_F32(beliefAddr);
		flags.ca = remaining > 0;
		remaining -= 1;
		cr0.compare<int32_t>((int32_t)remaining, 0, flags);
		const double aboveLower = (double)(float)(belief - lowerBound);
		listAddr += 12;
		lowIndex = aboveLower >= zero ? 0u : 4u;
		lowSelect.f64 = (double)LOAD_F32(selectTable + lowIndex);
		atLeastLower = (lowSelect.f64 >= 0.0) ? belief : lowerBound;
		belowUpper.f64 = (double)(float)(atLeastLower - upperBound);
		PPCCRRegister upperCompare{};
		upperCompare.compare(belowUpper.f64, zero);
		clampWord = conditionWord(upperCompare);
		ltIndex = upperCompare.lt ? 4u : 0u;
		highIndex = ltIndex | (upperCompare.un ? 4u : 0u);
		highSelect = (double)LOAD_F32(selectTable + highIndex);
		clampedBelief = (highSelect >= 0.0) ? upperBound : atLeastLower;
		STORE_F32(beliefAddr, float(clampedBelief));
		beliefAddr += 4;
	} while (!cr0.eq);

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	// callers read these after the return
	ctx.r4.u64 = highIndex;
	ctx.r6.u64 = ltIndex;
	ctx.r7.u64 = clampWord;
	ctx.r8.u64 = lowIndex;
	ctx.f5.f64 = f5;
	ctx.f6.f64 = f6;
	ctx.f7.f64 = f7;
	ctx.f8.f64 = clampedBelief;
	ctx.f9.f64 = highSelect;
	ctx.f10 = belowUpper;
	ctx.f11.f64 = atLeastLower;
	ctx.f12 = lowSelect;
	ctx.cr0 = cr0;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(50, sub_8275DC90, 0x8275DC90) { ctx.r3.u64 = n_sub_8275DC90(ctx, base, ctx.r3.u64); }

uint32_t n_sub_8275DE40(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(50, 0x8275DE40)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_8275DE40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8275DE40);
	uint32_t stack = ctx.r1.u64;
	// callers read r4 after the return
	uint64_t callerR4 = ctx.r4.u64;
	const uint32_t savedMsr = ctx.r13.u32;
	const PPCXERRegister entryXer = ctx.xer;

	stack = PushStackFrame(base, stack, 144);

	// Embedded list at +12: sentinel node pointer at +4, element count at +8. It is walked with a
	// checked iterator { container, node } kept in the frame; the traps are its validity checks.
	const uint32_t list = opinionReactionAddr + 12;
	const uint32_t iterator = stack + 80;
	uint32_t iterContainer = list;
	uint32_t node = LOAD32(LOAD32(opinionReactionAddr + 16));
	const uint32_t cutoffTime = LOAD32(0x8331950Cu);
	STORE32(iterator, iterContainer);
	// A global count, decremented once for each string released here.
	const uint32_t stringCountAddr = uint32_t(g_83496EB8);
	STORE32(iterator + 4, node);
	uint64_t iteratorCopy = LOAD64(iterator);
	uint32_t result = opinionReactionAddr;

	// Drop entries until one reaches the cutoff time.
	for (;;) {
		const uint32_t sentinel = LOAD32(list + 4);
		if (iterContainer == 0 || iterContainer != list) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (node == sentinel) break;
		if (iterContainer == 0) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t containerSentinel = LOAD32(iterContainer + 4);
		if (node == containerSentinel) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (int32_t(LOAD32(node + 24)) >= (int32_t)cutoffTime) break;

		STORE64(iterator, iteratorCopy);
		if (node == containerSentinel) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t next = LOAD32(node);
		const uint32_t currentSentinel = LOAD32(list + 4);
		STORE32(iterator + 4, next);
		if (node != currentSentinel) {
			// Unlink the node, release its string, then free it.
			STORE32(LOAD32(node + 4), next);
			const uint32_t prev = LOAD32(node + 4);
			STORE32(LOAD32(node) + 4, prev);

			ctx.r1.u64 = stack;
			// state the callee may pass on
			CCharString_Release(ctx, base, (uint64_t)node + 36);

			PPCCRRegister compare0{};
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(stringCountAddr);
				uint32_t newCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) - 1;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(stringCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
				compare0.so = entryXer.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);

			STORE32(node + 36, 0);
			ctx.cr0 = compare0;  // state the callee may pass on
			result = HandleTarget_Free(ctx, base, node);
			callerR4 = (int64_t)(uint64_t)LOAD32(list + 8) - 1;
			STORE32(list + 8, (uint32_t)callerR4);
		}

		iteratorCopy = LOAD64(iterator);
		STORE64(iterator, iteratorCopy);
		iterContainer = LOAD32(iterator);
		node = LOAD32(iterator + 4);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(50, sub_8275DE40, 0x8275DE40) { ctx.r3.u64 = n_sub_8275DE40(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82762F98(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t str_TXT_820D19B8_B_ = int32_t(0x820D19B8);
	if (!UseLiftedCode(50, 0x82762F98)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82762F98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82762F98);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	// xer as the code tracks it: so from entry (the search compares record it), ca from calls and shifts
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	const uint32_t nameString = stack + 80;
	const uint32_t numberString = stack + 88;  // later the search's { 0, entry } pair

	// Name string: the owner's 64-bit value (high word at +20, low word at +24) as text, with the
	// string at str_TXT_820D0000_B_ + 6584 appended (CCharString_AssignCString appends to a
	// non-empty string; the constant only supplies the base address).
	const uint32_t valueOwner = opinionReaction->m_4;
	const uint64_t valueHigh = (uint64_t)LOAD32(valueOwner + 20) << 32;
	const uint64_t ownerValue = (uint64_t)LOAD32(valueOwner + 24) | valueHigh;
	ctx.r8.u64 = valueHigh;  // state the callee may pass on
	CharString_ConstructFromUInt64(ctx, base, numberString, ownerValue);
	CCharString_CopyConstruct(ctx, base, nameString, numberString);
	ctx.r7.s64 = str_TXT_820D0000_B_;  // state the callee may pass on
	CCharString_AssignCString(ctx, base, nameString, (uint64_t)(str_TXT_820D19B8_B_));
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, numberString);

	const uint32_t reactionManager = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26788) + 32) + 28);
	ctx.r6.s64 = g_83490000;  // state the callee may pass on
	n_sub_821BD998(ctx, base, reactionManager, opinionReaction->m_4, nameString);

	ctx.r3.u64 = opinionReactionAddr;  // state the callee may pass on
	n_sub_82771E68(ctx, base, opinionReaction->m_4, nameString, ctx.r8.u64);

	// r4, r6-r9, cr0 and xer.ca as the later calls receive them.
	uint64_t r4 = ctx.r4.u64;
	uint64_t r6 = ctx.r6.u64;
	uint64_t r7 = ctx.r7.u64;
	PPCCRRegister compare0 = ctx.cr0;
	flags.ca = ctx.xer.ca;

	// Component presence bits: type t is bit t % 32 of the word at +36 + 4 * (t / 32)
	// (type 26: +36 bit 26, type 136: +52 bit 8). The owner's word goes to r9, the bit to r8.
	const uint32_t owner = opinionReaction->m_4;
	uint64_t r9 = LOAD32(owner + 36);
	uint64_t r8 = ((uint32_t)r9 >> 26) & 1;

	// Component of the given type from a sorted (type, component) array of 8-byte entries at +72/+76.
	// With an index map at +140 the entry comes from it (its address stays in r9); otherwise a
	// lower-bound search runs (r6 = end) whose shifts set cr0/xer.ca and whose steps leave the

	auto findComponent = [&](uint32_t entity, int32_t type) -> uint32_t {
		const uint32_t indexMap = LOAD32(entity + 140);
		if (indexMap != 0) {
			const uint64_t indexOffset = (uint64_t)LOAD8(indexMap + type) << 3;
			r9 = indexOffset + LOAD32(entity + 72);
			return LOAD32((uint32_t)r9 + 4);
		}
		uint32_t node = LOAD32(entity + 72);
		const uint32_t end = LOAD32(entity + 76);
		r6 = end;
		STORE32(numberString, 0);
		const uint32_t byteCount = end - node;
		STORE32(numberString + 4, node);
		flags.ca = (int32_t)byteCount < 0 & (byteCount & 0x7) != 0;
		int32_t count = (int32_t)byteCount >> 3;
		compare0.compare<int32_t>(count, 0, flags);
		if (count > 0) {
			do {
				flags.ca = count < 0 & (count & 0x1) != 0;
				const int32_t half = count >> 1;
				r9 = (uint64_t)(int64_t)half;
				r8 = (uint32_t)half << 3;
				node += (uint32_t)r8;
				const bool below = (int32_t)LOAD32(node) < type;
				r7 = below ? 1 : 0;
				if (below) {
					count = count - half - 1;
					node += 8;
				} else {
					node -= (uint32_t)r8;
					count = half;
				}
			} while (count > 0);
			STORE32(numberString + 4, node);
		}
		if (node != end && !((int32_t)LOAD32(node) > type)) {
			STORE64(numberString, LOAD64(numberString));
			return LOAD32(LOAD32(numberString + 4) + 4);
		}
		return LOAD32(end + 4);
	};

	// The owner's type-26 component, when its bit is set.
	if (r8 != 0) {
		const uint32_t ownerComponent = findComponent(owner, 26);
		if (LOAD8(ownerComponent + 172) == 0) {
			const uint32_t entityList = LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88);
			const uint32_t entitySlot = LOAD32(entityList + 4);
			const uint32_t handleOwner = LOAD32(entitySlot);
			// state the callee may pass on
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			const uint32_t entity = EntityHandle_Get(ctx, base, handleOwner);
			r4 = ctx.r4.u64;
			r6 = ctx.r6.u64;
			r7 = ctx.r7.u64;
			r8 = ctx.r8.u64;
			r9 = ctx.r9.u64;
			compare0 = ctx.cr0;
			flags.ca = ctx.xer.ca;

			// The entity's type-136 component, when the entity has flag 0x40 at +144 and the type's bit.
			if (entity != 0 && (LOAD8(entity + 144) & 64) != 0 && ((LOAD32(entity + 52) >> 8) & 1) != 0) {
				const uint32_t entityComponent = findComponent(entity, 136);
				r4 = opinionReaction->m_4;
				// state the callee may pass on
				ctx.xer.ca = flags.ca;
				const uint64_t contains = IntrusiveList_ContainsKey(ctx, base, entityComponent, (uint32_t)r4);
				r6 = ctx.r6.u64;
				r7 = ctx.r7.u64;
				r8 = ctx.r8.u64;
				r9 = ctx.r9.u64;
				if ((contains & 0xFF) != 0) {
					const uint64_t present = n_sub_82829998(ctx, base, entityComponent, opinionReaction->m_4);
					r4 = ctx.r4.u64;
					r6 = ctx.r6.u64;
					r7 = ctx.r7.u64;
					r8 = ctx.r8.u64;
					r9 = ctx.r9.u64;
					if ((present & 0xFF) == 0) {
						const uint64_t ownerValueAddr = (int64_t)(uint64_t)opinionReaction->m_4 + 20;
						ctx.cr0 = compare0;  // state the callee may pass on
						n_sub_8282BB08(ctx, base, entityComponent, ownerValueAddr);
						r4 = ctx.r4.u64;
						r6 = ctx.r6.u64;
						r7 = ctx.r7.u64;
						r8 = ctx.r8.u64;
						r9 = ctx.r9.u64;
						flags.ca = ctx.xer.ca;
					}
				}
			}
		}
	}

	// Remove the owner's component of the type the virtual at vtable +16 returns.
	const uint32_t removalOwner = opinionReaction->m_4;
	const uint32_t typeFn = LOAD32(uint32_t(opinionReaction->vtable) + 16);
	callTarget.u64 = (uint64_t)typeFn;
	ctx.r3.u64 = opinionReactionAddr;
	ctx.r4.u64 = r4;
	ctx.r6.u64 = r6;
	ctx.r7.u64 = r7;
	ctx.r8.u64 = r8;
	ctx.r9.u64 = r9;
	ctx.r10.u64 = typeFn;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	const uint64_t componentType = ctx.r3.u64;
	Entity_RemoveComponentByType(ctx, base, removalOwner, componentType, ctx.r8.u64);

	const uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameString);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(50, sub_82762F98, 0x82762F98) { ctx.r3.u64 = n_sub_82762F98(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82764410(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(50, 0x82764410)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82764410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82764410);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	stack = PushStackFrame(base, stack, 144);

	const uint32_t globals = uint32_t(g_83490000);
	const uint32_t entityList = LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88);
	const uint32_t entitySlot = LOAD32(entityList + 4);
	// callers read r8 after the return
	uint64_t callerR8 = entitySlot;
	const uint32_t handleOwner = LOAD32(entitySlot);
	uint64_t result = (int64_t)(uint64_t)handleOwner + 104;  // the handle at +104

	// The handle's record at +108 holds the entity in its first word; when that word is zero the
	// handle is released instead.
	const uint32_t handleRecord = LOAD32(handleOwner + 108);
	uint32_t entity = 0;
	if (handleRecord != 0) {
		entity = LOAD32(handleRecord);
		if (entity == 0) {
			ctx.r1.u64 = stack;
			// state the callee may pass on
			result = EntityHandle_Release(ctx, base, result);
			callerR8 = ctx.r8.u64;
		}
	}

	const uint32_t currentTime = LOAD32(0x8331950Cu);
	if (entity != 0 && (LOAD8(entity + 144) & 64) != 0) {
		const uint32_t lastUpdateTime = opinionReaction->m_33C;
		callerR8 = str_TXT_82100000_B_;  // r8 held the constant's base address
		ctx.fpscr.disableFlushMode();
		double interval = LOAD_F64(0x83319510u) * LOAD_F64(uint32_t(str_TXT_82100000_B_) + 2344);
		// f13 as the next call receives it: the truncated interval, then what each call leaves
		PPCRegister f13State{};
		f13State.s64 = std::isnan(interval) ? int64_t(0x80000000U) : interval > double(INT_MAX) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&interval));
		STORE_F64(stack + 80, f13State.f64);
		const uint32_t intervalTicks = LOAD32(stack + 84);

		if ((int32_t)currentTime >= (int32_t)(lastUpdateTime - 6 * intervalTicks)) {
			uint64_t index = 0;
			uint32_t valueAddr = opinionReactionAddr + 84;
			do {
				const uint32_t owner = opinionReaction->m_4;
				const uint32_t slot = LOAD32(LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88) + 4);
				ctx.r1.u64 = stack;
				// state the callee may pass on
				ctx.f13 = f13State;
				result = n_sub_825D17E0(ctx, base, LOAD32(slot + 48), index, owner);
				callerR8 = ctx.r8.u64;
				const double value = ctx.f1.f64;
				f13State = ctx.f13;
				index += 1;
				ctx.fpscr.disableFlushMode();
				STORE_F32(valueAddr, float(value));
				valueAddr += 4;
			} while ((int32_t)index != 5);
			opinionReaction->m_33C = currentTime;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = callerR8;
	return result;
}
PROMOTED_ENTRY(50, sub_82764410, 0x82764410) { ctx.r3.u64 = n_sub_82764410(ctx, base, ctx.r3.u32); }

// sub_827657D0  [972 bytes]
// Looks up the owner's (m_4) value for key 94 when bit 30 of the owner's +44 word is set. After a lookup, unless
// the value's +12 word is 1 and n_sub_82457310 gives the same handle as EntityHandle_Get for the global entity
// slot, it clears the handle lists at +176 (five, 12 bytes apart) and +316, copies a word into m_1F0 and passes a
// string built from the owner's 64-bit value plus the str_TXT_820D19B8_B_ suffix to n_sub_821BD998 and n_sub_82771E68.
// Otherwise, when the value is 0 (or no lookup was made), it passes the same string without the clearing.
// Then it inserts each handle (other than -1) of the vector at +752 into the list at entity slot + 192 and
// empties the vector.
uint64_t n_sub_827657D0(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr, uint64_t r8Value) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D19B8_B_ = int32_t(0x820D19B8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(51, 0x827657D0)) { ctx.r3.u64 = opinionReactionAddr; ctx.r8.u64 = r8Value; __imp__sub_827657D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827657D0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t msrR13 = ctx.r13.u64;
	// r6/r7/r8 values the callees receive through the CPU state (r8 starts as this function's second input).
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	PPCXERRegister flags = ctx.xer;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	// Reloaded at every use: LOAD32(LOAD32(LOAD32(LOAD32(0x83496920) + 12) + 88) + 4).
	auto loadEntitySlot = [&]() -> uint32_t {
		return LOAD32(LOAD32(LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12) + 88) + 4);
	};
	stack = PushStackFrame(base, stack, 144);

	// Value stored under key 94: a direct index when the owner has a key map, otherwise a binary search
	// (lower bound) over the sorted 8-byte (key, value) pairs; a missing key reads the value slot at end + 4.
	bool found = false;
	uint32_t targetPtr = 0;
	const uint32_t ownerAddr = opinionReaction->m_4;
	if (((LOAD32(ownerAddr + 44) >> 30) & 1) != 0) {
		const uint32_t keyMap = LOAD32(ownerAddr + 140);
		if (keyMap != 0) {
			const uint32_t index = __builtin_rotateleft32(LOAD8(keyMap + 94), 3);
			targetPtr = LOAD32(index + LOAD32(ownerAddr + 72) + 4);
		} else {
			uint32_t iter = LOAD32(ownerAddr + 72);
			const uint32_t end = LOAD32(ownerAddr + 76);
			r6Value = end;
			STORE32(stack + 88, 0);
			uint32_t count = end - iter;
			STORE32(stack + 92, iter);
			flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
			count = (int32_t)count >> 3;
			if ((int32_t)count > 0) {
				do {
					flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
					const uint32_t half = (int32_t)count >> 1;
					r8Value = half << 3;
					iter = iter + (uint32_t)r8Value;
					const bool keyBelow = (int32_t)LOAD32(iter) < 94;
					r7Value = keyBelow ? 1 : 0;
					if (keyBelow) {
						count = count - half - 1;
						iter = iter + 8;
					} else {
						iter = iter - (uint32_t)r8Value;
						count = half;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 92, iter);
			}
			if (iter != end && (int32_t)LOAD32(iter) <= 94) {
				// The pair holds key 94 (the original also copies the 8-byte result onto itself).
				STORE64(stack + 88, LOAD64(stack + 88));
				targetPtr = LOAD32(LOAD32(stack + 92) + 4);
			} else {
				targetPtr = LOAD32(end + 4);
			}
		}
		found = true;
	}

	bool listsReset = false;
	if (found) {
		bool sameEntity = false;
		if ((int32_t)LOAD32(targetPtr + 12) == 1) {
			const uint32_t entitySlot = loadEntitySlot();
			ctx.r1.u64 = stack;
			// state the callees may pass on
			ctx.xer.ca = flags.ca;
			const uint32_t entityHandle = EntityHandle_Get(ctx, base, LOAD32(entitySlot));
			flags.ca = ctx.xer.ca;
			const uint32_t targetHandle = n_sub_82457310(ctx, base, targetPtr);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
			sameEntity = targetHandle == entityHandle;
		}
		if (!sameEntity) {
			uint64_t listAddr = opinionReactionAddr + 176;
			uint32_t listsLeft = 5;
			do {
				ctx.r1.u64 = stack;
				ctx.xer.ca = flags.ca;
				SharedHandleList_Clear(ctx, base, listAddr);
				r6Value = ctx.r6.u64;
				r7Value = ctx.r7.u64;
				flags.ca = listsLeft > 0;
				listsLeft = listsLeft - 1;
				listAddr = listAddr + 12;
			} while (listsLeft != 0);
			ctx.xer.ca = flags.ca;
			n_sub_82773388(ctx, base, opinionReactionAddr + 12);
			flags.ca = ctx.xer.ca;
			SharedHandleList_Clear(ctx, base, opinionReactionAddr + 316);
			flags.ca = ctx.xer.ca;

			const uint32_t owner = opinionReaction->m_4;
			const uint32_t entitySlot = loadEntitySlot();
			opinionReaction->m_1F0 = LOAD32(LOAD32(entitySlot + 28) + 600);
			const uint64_t ownerU64 = __builtin_rotateleft64((uint64_t)LOAD32(owner + 20), 32) | (uint64_t)LOAD32(owner + 24);
			ctx.r8.u64 = entitySlot;  // state the callee may pass on
			CharString_ConstructFromUInt64(ctx, base, stack + 88, ownerU64);
			flags.ca = ctx.xer.ca;
			CCharString_CopyConstruct(ctx, base, stack + 80, stack + 88);
			flags.ca = ctx.xer.ca;
			CCharString_AssignCString(ctx, base, stack + 80, str_TXT_820D19B8_B_);
			flags.ca = ctx.xer.ca;
			CCharString_Release(ctx, base, stack + 88);
			flags.ca = ctx.xer.ca;

			// Atomic decrement of the counter at 0x83496EB8.
			const uint64_t counterAddr = g_83496EB8;
			uint64_t savedMsr = 0;
			uint64_t decremented = 0;
			bool stored = false;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				savedMsr = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrR13 & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)counterAddr);
				decremented = __builtin_bswap32(ctx.reserved.u32);
				decremented = (int64_t)decremented - 1;
				stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)counterAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)decremented));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)savedMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);

			const uint32_t ownerAgain = opinionReaction->m_4;
			const uint32_t registry = LOAD32(LOAD32(LOAD32(0x834968A4u) + 32) + 28);
			// state the callee may pass on
			n_sub_821BD998(ctx, base, registry, ownerAgain, stack + 80);
			flags.ca = ctx.xer.ca;
			ctx.r3.u64 = opinionReactionAddr;  // state the callee may pass on
			n_sub_82771E68(ctx, base, opinionReaction->m_4, stack + 80, ctx.r8.u64);
			flags.ca = ctx.xer.ca;
			CCharString_Release(ctx, base, stack + 80);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			flags.ca = ctx.xer.ca;

			// Second atomic decrement of the same counter.
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				const uint32_t lockMsr = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrR13 & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)counterAddr);
				uint32_t newCount = __builtin_bswap32(ctx.reserved.u32);
				newCount = newCount - 1;
				stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)counterAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockMsr & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!stored);

			listsReset = true;
		}
	}

	if (!listsReset && targetPtr == 0) {
		const uint32_t owner = opinionReaction->m_4;
		const uint64_t ownerHigh = __builtin_rotateleft64((uint64_t)LOAD32(owner + 20), 32);
		const uint64_t ownerU64 = ownerHigh | (uint64_t)LOAD32(owner + 24);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = ownerHigh;  // state the callee may pass on
		ctx.xer.ca = flags.ca;
		CharString_ConstructFromUInt64(ctx, base, stack + 88, ownerU64);
		flags.ca = ctx.xer.ca;
		CCharString_CopyConstruct(ctx, base, stack + 80, stack + 88);
		flags.ca = ctx.xer.ca;
		// The lifted code addresses the suffix as str_TXT_820D0000_B_ + 6584, which is str_TXT_820D19B8_B_,
		// and leaves that base in r7.
		CCharString_AssignCString(ctx, base, stack + 80, str_TXT_820D19B8_B_);
		flags.ca = ctx.xer.ca;
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
		flags.ca = ctx.xer.ca;
		const uint32_t ownerAgain = opinionReaction->m_4;
		const uint32_t registry = LOAD32(LOAD32(LOAD32(0x834968A4u) + 32) + 28);
		ctx.r6.s64 = g_83490000;  // state the callee may pass on
		n_sub_821BD998(ctx, base, registry, ownerAgain, stack + 80);
		flags.ca = ctx.xer.ca;
		ctx.r3.u64 = opinionReactionAddr;  // state the callee may pass on
		n_sub_82771E68(ctx, base, opinionReaction->m_4, stack + 80, ctx.r8.u64);
		flags.ca = ctx.xer.ca;
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	// Vector at +752: begin at +4 (m_2F4), end at +8 (m_2F8). The traps are its iterator range checks.
	const uint32_t vectorAddr = opinionReactionAddr + 752;
	uint32_t cursor = opinionReaction->m_2F4;
	uint32_t limit = opinionReaction->m_2F8;
	if (cursor > limit) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	for (;;) {
		const uint32_t vectorEnd = LOAD32(vectorAddr + 8);
		if (LOAD32(vectorAddr + 4) > vectorEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (cursor == vectorEnd) break;
		if (cursor >= limit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		const uint32_t handle = LOAD32(cursor);
		STORE32(stack + 88, handle);
		if ((int32_t)handle != -1) {
			const uint32_t entitySlot = loadEntitySlot();
			const uint32_t listAddr = entitySlot + 192;
			STORE32(stack + 80, listAddr);
			STORE32(stack + 84, LOAD32(entitySlot + 196));
			const uint64_t position = LOAD64(stack + 80);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r8.u64 = r8Value;
			ctx.xer.ca = flags.ca;
			List_InsertNodeCopyWord(ctx, base, listAddr, position, stack + 88);
			r6Value = ctx.r6.u64;
			r7Value = ctx.r7.u64;
			r8Value = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
		}
		limit = LOAD32(vectorAddr + 8);
		if (cursor >= limit) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		cursor = cursor + 4;
	}

	// Empty the vector: the lifted element move after the erased range has length 0, so only the end changes.
	const uint64_t vectorBegin = LOAD32(vectorAddr + 4);
	const uint32_t vectorEnd = LOAD32(vectorAddr + 8);
	if ((uint32_t)vectorBegin > vectorEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
		ppc_trap(ctx, base, 22);
	}
	if ((uint32_t)vectorBegin != vectorEnd) {
		STORE32(vectorAddr + 8, (uint32_t)vectorBegin);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return vectorBegin;
}
PROMOTED_ENTRY(51, sub_827657D0, 0x827657D0) { ctx.r3.u64 = n_sub_827657D0(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t n_sub_82767B08(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr) {
	if (!UseLiftedCode(51, 0x82767B08)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82767B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82767B08);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	n_sub_82767DF8(ctx, base, opinionReactionAddr);

	// Both 8-byte-element vectors (begin/end m_37C/m_380 and m_36C/m_370) empty:
	// hand what IdRef_Get returns for an IdRef of m_2E0 to n_sub_82768B70.
	const uint32_t effectBytes = (uint32_t)opinionReaction->m_380 - (uint32_t)opinionReaction->m_37C;
	if ((effectBytes & 0xFFFFFFF8) == 0) {
		const uint32_t entryBytes = ((uint32_t)opinionReaction->m_370 - (uint32_t)opinionReaction->m_36C) & 0xFFFFFFF8;
		if (entryBytes == 0) {
			const uint32_t id = opinionReaction->m_2E0;
			ctx.r8.u64 = entryBytes;  // state the callee may pass on (0)
			IdRef_ConstructFromId(ctx, base, stack + 80, id);
			ctx.r4.u64 = id;  // state the callee may pass on
			const uint64_t idRef = IdRef_Get(ctx, base, stack + 80);
			n_sub_82768B70(ctx, base, opinionReactionAddr, idRef, ctx.r8.u64);
		}
	}

	// Call the virtual function at vtable offset 8 of the object in each 8-byte entry of m_36C..m_370;
	// the end is re-read after every call.
	const uint32_t entriesBegin = opinionReaction->m_36C;
	const uint32_t entriesEnd = opinionReaction->m_370;
	// r9 for each call: the byte span, then the re-read end; r8: the span rounded down to 8, then what the call left.
	uint64_t r9Value = (uint64_t)entriesEnd - (uint64_t)entriesBegin;
	uint64_t r8Value = (uint32_t)r9Value & 0xFFFFFFF8;
	if (r8Value != 0 && entriesBegin != entriesEnd) {
		uint32_t cursor = entriesBegin;
		do {
			const uint32_t object = LOAD32(cursor);
			const uint32_t method = LOAD32(LOAD32(object) + 8);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r3.u64 = object;
			ctx.r8.u64 = r8Value;
			ctx.r9.u64 = r9Value;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r8Value = ctx.r8.u64;
			r9Value = opinionReaction->m_370;
			cursor = cursor + 8;
		} while (cursor != (uint32_t)r9Value);
	}

	if (opinionReaction->m_308 != 0 && (uint32_t)opinionReaction->m_364 != 0) {
		opinionReaction->m_30E = uint8_t(1);
	}

	n_sub_8226B858(ctx, base, opinionReactionAddr);
	n_sub_8275DC90(ctx, base, opinionReactionAddr);
	n_sub_8275DE40(ctx, base, opinionReactionAddr);
	n_sub_8275DF58(ctx, base, opinionReactionAddr);
	uint64_t result = CECOpinionReaction_Update(ctx, base, opinionReactionAddr);

	if (LOAD8(0x83318EA0u) != 0 && opinionReaction->m_30B != 0) {
		result = n_sub_82763C68(ctx, base, opinionReactionAddr);
	}
	if (LOAD8(0x83318EA1u) != 0 && opinionReaction->m_30B != 0) {
		ctx.r4.u64 = 0;  // state the callee may pass on
		result = n_sub_82266740(ctx, base, opinionReactionAddr);
	}
	if (LOAD8(0x83318EA2u) != 0) {
		result = n_sub_82764410(ctx, base, opinionReactionAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_82767B08, 0x82767B08) { ctx.r3.u64 = n_sub_82767B08(ctx, base, ctx.r3.u64); }

// Reads the opinion-reaction settings from the owner's game-database record into this object; when the record
// leads through the personality-pools and pool references to a resolvable pool, stores that pool id in m_2E0.
// Returns the last object looked up (0 when a step fails).
uint32_t n_sub_82767C88(CpuState& ctx, uint8_t* base, uint32_t opinionReactionAddr) {
	constexpr int32_t str_TXT_820D0000_B_ = int32_t(0x820D0000);
	constexpr int32_t str_TXT_820D2B4C_B_ = int32_t(0x820D2B4C);
	constexpr int32_t str_TXT_820D2C44_B_ = int32_t(0x820D2C44);
	constexpr int32_t str_TXT_820D2C60_B_ = int32_t(0x820D2C60);
	constexpr int32_t str_TXT_820D2C6C_B_ = int32_t(0x820D2C6C);
	constexpr int32_t str_TXT_820D2C80_B_ = int32_t(0x820D2C80);
	constexpr int32_t str_TXT_820D2C98_B_ = int32_t(0x820D2C98);
	constexpr int32_t str_TXT_820D2CB8_B_ = int32_t(0x820D2CB8);
	constexpr int32_t str_TXT_820D2CDC_B_ = int32_t(0x820D2CDC);
	// Two more strings the code addresses as offsets from str_TXT_820D0000_B_.
	constexpr uint64_t str_TXT_820D2294_B_ = (int64_t)str_TXT_820D0000_B_ + 8852;
	constexpr uint64_t str_TXT_820D2CC8_B_ = (int64_t)str_TXT_820D0000_B_ + 11464;
	if (!UseLiftedCode(51, 0x82767C88)) { ctx.r3.u64 = opinionReactionAddr; __imp__sub_82767C88(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82767C88);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);

	stack = PushStackFrame(base, stack, 112);

	// 8-byte IdRef on the game stack: first a copy of the owner's IdRef (+28, +32), later rebuilt by IdRef_ConstructFromId.
	const uint32_t idRefBuffer = stack + 80;
	const uint32_t ownerAddr = opinionReaction->m_4;
	const uint32_t ownerRefHigh = LOAD32(ownerAddr + 32);
	STORE32(idRefBuffer, LOAD32(ownerAddr + 28));
	STORE32(idRefBuffer + 4, ownerRefHigh);

	ctx.r1.u64 = stack;
	uint64_t dbObject = IdRef_Get(ctx, base, idRefBuffer);
	do {
		if ((uint32_t)dbObject == 0) break;

		const uint64_t reactionComponent = GameDB_ReadU32Field(ctx, base, dbObject, str_TXT_820D2C44_B_);
		dbObject = reactionComponent;
		if ((uint32_t)reactionComponent == 0) break;

		GameDB_GetFloatByName(ctx, base, reactionComponent, str_TXT_820D2C60_B_);
		const double TXT_820D2C60_L_ = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		opinionReaction->m_A4 = float(TXT_820D2C60_L_);

		GameDB_GetFloatByName(ctx, base, reactionComponent, str_TXT_820D2C6C_B_);
		const double TXT_820D2C6C_L_ = ctx.f1.f64;
		ctx.fpscr.disableFlushMode();
		opinionReaction->m_A8 = float(TXT_820D2C6C_L_);

		opinionReaction->m_308 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, reactionComponent, str_TXT_820D2C80_B_);

		ctx.r8.s64 = str_TXT_820D0000_B_;  // state the callees may pass on
		opinionReaction->m_309 = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, reactionComponent, str_TXT_820D2294_B_);
		opinionReaction->m_30B = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, reactionComponent, str_TXT_820D2C98_B_);
		opinionReaction->m_30D = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, reactionComponent, str_TXT_820D2CB8_B_);
		opinionReaction->m_30F = (uint8_t)GameDB_ReadBoolField_82303F38(ctx, base, reactionComponent, str_TXT_820D2B4C_B_);

		dbObject = GameDB_ReadU32Field(ctx, base, reactionComponent, str_TXT_820D2CC8_B_);
		if ((uint32_t)dbObject == 0) break;
		dbObject = n_sub_82920FD0(ctx, base, dbObject, ctx.r8.u64);
		const uint32_t personalityPoolsId = (uint32_t)dbObject;
		if (personalityPoolsId == 0) break;

		const uint64_t idRef = IdRef_ConstructFromId(ctx, base, idRefBuffer, personalityPoolsId);
		dbObject = IdRef_Get(ctx, base, idRef);
		if ((uint32_t)dbObject == 0) break;

		dbObject = GameDB_ReadU32Field(ctx, base, dbObject, str_TXT_820D2CDC_B_);
		if ((uint32_t)dbObject == 0) break;
		dbObject = n_sub_82920FD0(ctx, base, dbObject, ctx.r8.u64);
		const uint32_t poolId = (uint32_t)dbObject;
		if (poolId == 0) break;

		const uint64_t poolIdRef = IdRef_ConstructFromId(ctx, base, idRefBuffer, poolId);
		dbObject = IdRef_Get(ctx, base, poolIdRef);
		if ((uint32_t)dbObject == 0) break;

		opinionReaction->m_2E0 = poolId;
	} while (false);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)dbObject;
}
PROMOTED_ENTRY(51, sub_82767C88, 0x82767C88) { ctx.r3.u64 = n_sub_82767C88(ctx, base, ctx.r3.u32); }

// Resolves the record recordId names and, by its TXT_820D2E70_B_ field, hands a new object to n_sub_829FD7B8 for the
// vector at +872 (begin/end m_36C/m_370): types 0 and 1 a 76-byte object built from the Place field, type 2 a
// 64-byte object holding the hash of the record's TXT_820A6304_B_/TXT_820A6310_B_ path. Returns byte +12 of the object in the
// vector's last entry, or 0 when recordId is 0 or its IdRef is empty.
uint32_t n_sub_82769248(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr, uint64_t recordId) {
	constexpr int32_t str_TXT_820A6304_B_ = int32_t(0x820A6304);
	constexpr int32_t str_TXT_820D2E70_B_ = int32_t(0x820D2E70);
	constexpr int32_t str_TXT_820D2E7C_B_ = int32_t(0x820D2E7C);
	constexpr int32_t str_TXT_820A6310_B_ = int32_t(0x820A6310);
	constexpr int32_t g_820D82E8 = int32_t(0x820D82E8);
	constexpr int32_t g_820D8300 = int32_t(0x820D8300);
	constexpr uint64_t fnvSeed = (uint64_t)-2128871424 | 40389;
	if (!UseLiftedCode(51, 0x82769248)) { ctx.r3.u64 = opinionReactionAddr; ctx.r4.u64 = recordId; __imp__sub_82769248(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82769248);
	uint32_t stack = ctx.r1.u64;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	stack = PushStackFrame(base, stack, 176);

	if ((uint32_t)recordId != 0) {
		ctx.r1.u64 = stack;
		IdRef_ConstructFromId(ctx, base, stack + 80, recordId);

		if (LOAD32(stack + 80) != 0) {
			ctx.r4.u64 = recordId;  // state the callee may pass on
			const uint64_t record = IdRef_Get(ctx, base, stack + 80);

			const uint64_t placeTypeHash = String_HashFnv1(ctx, base, str_TXT_820D2E70_B_, fnvSeed);
			const uint32_t placeTypeField = GameDB_FindFieldValue(ctx, base, record, placeTypeHash, 2);
			// A missing TXT_820D2E70_B_ field takes the type 0 branch.
			const uint32_t TXT_820D2E70_L_ = (placeTypeField != 0) ? LOAD32(placeTypeField) : 0;

			if (TXT_820D2E70_L_ == 0) {
				const uint64_t placeHash = String_HashFnv1(ctx, base, str_TXT_820D2E7C_B_, fnvSeed);
				const uint32_t placeField = GameDB_FindFieldValue(ctx, base, record, placeHash, 6);
				const uint32_t TXT_820D2E7C_L_ = (placeField != 0) ? LOAD32(placeField) : 0;

				const uint64_t memory = operator_new(ctx, base, 76);
				uint32_t object = 0;
				if ((uint32_t)memory != 0) {
					object = n_sub_827E1478(ctx, base, memory, recordId, 0, TXT_820D2E7C_L_);
				}
				STORE32(stack + 96, object);
				if (object != 0) {
					const uint64_t entry = n_sub_82773418(ctx, base, stack + 96);
					n_sub_829FD7B8(ctx, base, opinionReactionAddr + 872, entry);
				} else {
					STORE32(stack + 100, 0);
					n_sub_829FD7B8(ctx, base, opinionReactionAddr + 872, stack + 96);
				}
				SharedHandle_Release(ctx, base, stack + 96);
			} else if (TXT_820D2E70_L_ == 1) {
				const uint64_t placeHash = String_HashFnv1(ctx, base, str_TXT_820D2E7C_B_, fnvSeed);
				const uint32_t placeField = GameDB_FindFieldValue(ctx, base, record, placeHash, 6);
				const uint32_t TXT_820D2E7C_L_ = (placeField != 0) ? LOAD32(placeField) : 0;

				const uint64_t memory = operator_new(ctx, base, 76);
				// r9 for the calls below: what operator_new left there, or the word stored at +0 of the new object.
				uint32_t r9Value = ctx.r9.u32;
				uint32_t object = 0;
				if ((uint32_t)memory != 0) {
					n_sub_827E1478(ctx, base, memory, recordId, 1, TXT_820D2E7C_L_);
					object = (uint32_t)memory;
					r9Value = uint32_t(g_820D8300);
					STORE32(object, r9Value);
				}
				STORE32(stack + 104, object);
				if (object != 0) {
					ctx.r9.u64 = r9Value;  // state the callee may pass on
					const uint64_t entry = n_sub_82773418(ctx, base, stack + 104);
					n_sub_829FD7B8(ctx, base, opinionReactionAddr + 872, entry);
				} else {
					STORE32(stack + 108, 0);
					ctx.r9.u64 = r9Value;  // state the callee may pass on
					n_sub_829FD7B8(ctx, base, opinionReactionAddr + 872, stack + 104);
				}
				SharedHandle_Release(ctx, base, stack + 104);
			} else if (TXT_820D2E70_L_ == 2) {
				const uint64_t TXT_820A6304_L_ = n_sub_82345978(ctx, base, record, str_TXT_820A6304_B_);
				CCharString_ConstructFromCStr(ctx, base, stack + 88, TXT_820A6304_L_, -1);

				// The same IdRef resolved again.
				const uint64_t recordAgain = IdRef_Get(ctx, base, stack + 80);
				const uint64_t TXT_820A6310_L_ = n_sub_82345978(ctx, base, recordAgain, str_TXT_820A6310_B_);
				CCharString_ConstructFromCStr(ctx, base, stack + 80, TXT_820A6310_L_, -1);

				const uint32_t slotObject = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(0x83496920u) + 12) + 88) + 4) + 8);
				// state the callee may pass on
				ctx.r3.u64 = LOAD32(slotObject + 4);
				const uint32_t pathHash = Path_NormalizeAndHash(ctx, base, stack + 88, stack + 80);

				const uint64_t memory = operator_new(ctx, base, 64);
				const uint32_t object = (uint32_t)memory;
				if (object != 0) {
					n_sub_827E11E0(ctx, base, memory, recordId, 2);
					STORE32(object + 60, pathHash);
					const uint64_t vtable = g_820D82E8;
					STORE32(object, (uint32_t)vtable);
					const uint32_t method = LOAD32((uint32_t)vtable + 8);
					PPCRegister callTarget{};
					callTarget.u64 = method;
					ctx.r3.u64 = memory;
					ctx.r9.u64 = method;
					ctx.r10.u64 = vtable;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
				}
				STORE32(stack + 112, object);
				uint64_t entry;
				if (object != 0) {
					entry = n_sub_82773418(ctx, base, stack + 112);
				} else {
					entry = stack + 112;
					STORE32(stack + 116, 0);
				}
				n_sub_829FD7B8(ctx, base, opinionReactionAddr + 872, entry);
				SharedHandle_Release(ctx, base, stack + 112);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
			}

			const uint32_t entriesEnd = opinionReaction->m_370;
			STORE32(stack + 92, entriesEnd - 8);
			const uint32_t lastObject = LOAD32(entriesEnd - 8);
			const uint32_t result = LOAD8(lastObject + 12);
			stack = PopStackFrame(stack, 176);
			ctx.r1.u64 = stack;
			ctx.r9.u64 = lastObject;  // callers read r9 after the call
			return result;
		}
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = recordId;  // callers read r4 after the call
	return 0;
}
PROMOTED_ENTRY(51, sub_82769248, 0x82769248) { ctx.r3.u64 = n_sub_82769248(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_827696D8  [348 bytes]
// Appends a new effect for itemId, with its reference-counted node, to the vector at +904 and returns the m_like
// byte (+48) of the vector's last effect.
uint32_t n_sub_827696D8(CpuState& ctx, uint8_t* base, uint64_t opinionReactionAddr, uint64_t itemId) {
	if (!UseLiftedCode(51, 0x827696D8)) { ctx.r3.u64 = opinionReactionAddr; ctx.r4.u64 = itemId; __imp__sub_827696D8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827696D8);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u64;
	PPCXERRegister flags = ctx.xer;
	CECOpinionReaction* opinionReaction = GameObject<CECOpinionReaction>(base, opinionReactionAddr);
	stack = PushStackFrame(base, stack, 128);

	if ((uint32_t)itemId == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r4 after the call (r9 still holds the caller's value)
		ctx.r4.u64 = itemId;
		return 0;
	}

	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r4.u64 = itemId;
	uint64_t effectMemory = operator_new(ctx, base, 56);
	uint32_t effect = 0;
	if ((uint32_t)effectMemory != 0) {
		effect = CExpressionItemEffect_Construct(ctx, base, effectMemory, itemId);
	}
	STORE32(stack + 80, effect);

	// Reference-counted node {count 1, 0x82773630, effect} sharing the effect.
	uint64_t sharedHandle = 0;
	if (effect != 0) {
		uint64_t node = operator_new(ctx, base, 12);
		if ((uint32_t)node != 0) {
			STORE32((uint32_t)node + 8, effect);
			sharedHandle = node;
			STORE32((uint32_t)node, 1u);
			STORE32((uint32_t)node + 4, 0x82773630u);
		}
	}

	// Vector of 8-byte {effect, node} entries at +904: begin +908, end +912, capacity end +916.
	uint64_t vectorAddr = opinionReactionAddr + 904;
	uint32_t begin = opinionReaction->m_38C;
	STORE32(stack + 84, (uint32_t)sharedHandle);
	uint32_t capacityCount = 0;
	if (begin != 0) {
		capacityCount = (int32_t)(LOAD32((uint32_t)vectorAddr + 12) - begin) >> 3;
	}
	uint32_t end = LOAD32((uint32_t)vectorAddr + 8);
	uint64_t elementCount = (int32_t)(end - begin) >> 3;

	if ((uint32_t)elementCount < capacityCount) {
		// what the original leaves in r9 for the release below: the capacity count, or the last lock token
		uint32_t r9Value = capacityCount;
		if (end != 0) {
			STORE32(end, effect);
			STORE32(end + 4, (uint32_t)sharedHandle);
			if ((uint32_t)sharedHandle != 0) {
				// Atomic increment of the node's reference count.
				PPCCRRegister compare0{};
				do {
					std::atomic_thread_fence(std::memory_order_seq_cst);
					uint32_t lockToken = REX_CHECK_GLOBAL_LOCK();
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
					REX_ENTER_GLOBAL_LOCK();
					ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)sharedHandle);
					uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32);
					newRefCount = (int32_t)newRefCount + 1;
					uint32_t casAddr = (uint32_t)sharedHandle;
					compare0.lt = 0;
					compare0.gt = 0;
					compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
					compare0.so = flags.so;
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = lockToken & 0x8020 | ctx.msr & ~0x8020;
					REX_LEAVE_GLOBAL_LOCK();
					r9Value = lockToken;
				} while (!compare0.eq);
			}
		}
		STORE32((uint32_t)vectorAddr + 8, end + 8);
		// state SharedHandle_Release may pass on
		ctx.r7.u64 = elementCount;
		ctx.r8.u64 = sharedHandle;
		ctx.r9.u64 = r9Value;
	} else {
		STORE32(stack + 92, end);
		STORE32(stack + 88, 0u);
		uint64_t insertPosition = LOAD64(stack + 88);
		// state the callee may pass on
		ctx.r5.u64 = 1;
		ctx.r7.u64 = elementCount;
		ctx.r8.u64 = sharedHandle;
		ctx.r9.u64 = capacityCount;
		n_sub_8260B008(ctx, base, vectorAddr, insertPosition, (uint64_t)stack + 80);
		// the original passes only the low word of r9 on to the release below
		ctx.r9.u64 = ctx.r9.u32;
	}
	SharedHandle_Release(ctx, base, (uint64_t)stack + 80);

	uint32_t newEnd = opinionReaction->m_390;
	STORE32(stack + 92, newEnd - 8);
	uint32_t lastEffect = LOAD32(newEnd - 8);
	uint32_t result = LOAD8(lastEffect + 48);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r9 after the call (r4 still holds what SharedHandle_Release left)
	ctx.r9.u64 = lastEffect;
	return result;
}
PROMOTED_ENTRY(51, sub_827696D8, 0x827696D8) { ctx.r3.u64 = n_sub_827696D8(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Builds a record (entity unique id, two 16-bit values, copied text) on the game stack and hands it to
// n_sub_82777058 of the object at global +26912 -> +12 -> +140 while that object's bytes +52 and +53 are set.
// r8Value only travels on to the callees through r8.
uint32_t n_sub_82771DB0(CpuState& ctx, uint8_t* base, uint64_t textObjectAddr, uint64_t entityAddr, uint64_t value18, uint64_t value16, uint64_t r8Value) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(51, 0x82771DB0)) { ctx.r4.u64 = textObjectAddr; ctx.r5.u64 = entityAddr; ctx.r6.u64 = value18; ctx.r7.u64 = value16; ctx.r8.u64 = r8Value; __imp__sub_82771DB0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82771DB0);
	uint32_t stack = ctx.r1.u64;
	uint32_t result = ctx.r3.u32;
	stack = PushStackFrame(base, stack, 272);

	const uint32_t globalBase = uint32_t(g_83490000);
	uint32_t receiver = LOAD32(LOAD32(LOAD32(globalBase + 26912) + 12) + 140);
	if (LOAD8(receiver + 52) != 0 && LOAD8(receiver + 53) != 0) {
		// Record at stack + 80: +0 type tag, +8 entity unique id, +16 value16, +18 value18, +20 text.
		STORE32(stack + 80, 0x820A4A90u);
		ctx.r1.u64 = stack;
		// state the callee may pass on; strcpy_s below takes r8 as this call leaves it
		uint64_t entityUniqueId = Entity_GetUniqueId(ctx, base, (uint32_t)entityAddr);

		uint32_t textData = LOAD32((uint32_t)textObjectAddr);
		STORE64(stack + 88, entityUniqueId);
		STORE16(stack + 96, (uint16_t)value16);
		STORE16(stack + 98, (uint16_t)value18);
		uint64_t text = (textData == 0) ? uint64_t(g_8209003F) : LOAD32(textData);
		strcpy_s(ctx, base, stack + 100, -1, text, ctx.r8.u64);

		uint32_t currentReceiver = LOAD32(LOAD32(LOAD32(globalBase + 26912) + 12) + 140);
		// state the callee may pass on
		result = n_sub_82777058(ctx, base, currentReceiver, stack + 80);
	} else {
		// callers read r4-r8 after the call
		ctx.r4.u64 = textObjectAddr;
		ctx.r5.u64 = entityAddr;
		ctx.r6.u64 = value18;
		ctx.r7.u64 = value16;
		ctx.r8.u64 = r8Value;
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_82771DB0, 0x82771DB0) { ctx.r3.u64 = n_sub_82771DB0(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

// Builds a record (entity unique id, copied text) on the game stack and hands it to n_sub_827771A0 of the
// object at global +26912 -> +12 -> +140 while that object's bytes +52 and +53 are set.
// r8Value only travels on to strcpy_s, which passes it on through r8.
uint32_t n_sub_82771E68(CpuState& ctx, uint8_t* base, uint64_t entityAddr, uint32_t textObjectAddr, uint64_t r8Value) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(51, 0x82771E68)) { ctx.r4.u64 = entityAddr; ctx.r5.u64 = textObjectAddr; ctx.r8.u64 = r8Value; __imp__sub_82771E68(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82771E68);
	uint32_t stack = ctx.r1.u64;
	uint32_t result = ctx.r3.u32;

	const uint32_t globalBase = uint32_t(g_83490000);

	stack = PushStackFrame(base, stack, 256);

	uint32_t receiver = LOAD32(LOAD32(LOAD32(globalBase + 26912) + 12) + 140);
	if (LOAD8(receiver + 52) != 0 && LOAD8(receiver + 53) != 0) {
		// Record at stack + 80: +0 type tag, +8 entity unique id, +16 text.
		const int64_t recordTypeTag = (int64_t)g_820A0000 + 19100;
		STORE32(stack + 80, (uint32_t)recordTypeTag);

		uint32_t textData = LOAD32(textObjectAddr);
		uint64_t text = (textData == 0) ? uint64_t(g_8209003F) : LOAD32(textData);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		strcpy_s(ctx, base, (uint64_t)stack + 96, -1, text, r8Value);

		uint64_t entityUniqueId = Entity_GetUniqueId(ctx, base, entityAddr);
		STORE64(stack + 88, entityUniqueId);

		uint32_t currentReceiver = LOAD32(LOAD32(LOAD32(globalBase + 26912) + 12) + 140);
		// state the callee may pass on
		result = n_sub_827771A0(ctx, base, currentReceiver, stack + 80);
	} else {
		// callers read r4 and r8 after the call
		ctx.r4.u64 = entityAddr;
		ctx.r8.u64 = r8Value;
	}

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(51, sub_82771E68, 0x82771E68) { ctx.r3.u64 = n_sub_82771E68(ctx, base, ctx.r4.u64, ctx.r5.u32, ctx.r8.u64); }
