// CECNetwork (vtable 0x82004E58): methods of the class as readable C++.
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

uint64_t CECNetwork_ShouldReplicateEntity(CpuState& ctx, uint8_t* base, uint32_t object) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(5, 0x82214C28)) { ctx.r3.u64 = object; __imp__sub_82214C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82214C28);

	// manager+140 is the net message queue the senders in this module append to.
	uint32_t manager = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t messageQueue = LOAD32(manager + 140);
	// callers read r9 after the call: it holds the manager on every return
	ctx.r9.u64 = manager;

	if (LOAD8(messageQueue + 52) != 0) {
		if (LOAD8(messageQueue + 53) != 0 && LOAD8(object + 104) == 0) {
			return 1;
		}
		if (LOAD8(messageQueue + 54) != 0 && LOAD8(object + 104) != 0) {
			return 1;
		}
		if (LOAD32(manager + 284) != 2) {
			return 0;
		}
	}
	return 1;
}
PROMOTED_ENTRY(5, sub_82214C28, 0x82214C28) { ctx.r3.u64 = CECNetwork_ShouldReplicateEntity(ctx, base, ctx.r3.u32); }

uint64_t CECNetwork_TryReplicateEntity(CpuState& ctx, uint8_t* base, uint64_t networkAddr, uint64_t obj) {
	if (!UseLiftedCode(7, 0x82238290)) { ctx.r3.u64 = networkAddr; ctx.r4.u64 = obj; __imp__sub_82238290(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82238290);
	uint32_t stack = ctx.r1.u64;
	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t virtualFn = LOAD32(LOAD32((uint32_t)obj) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = obj;
	ctx.r4.u64 = obj;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	uint64_t result = ctx.r3.u64;
	if ((int32_t)result == 10) {
		result = CECNetwork_ShouldReplicateEntity(ctx, base, networkAddr);
		if ((uint32_t(result) & 0xFF) != 0) {
			uint32_t entity = network->m_4;
			result = CECDoor_UpdateOpenStateForEntity(ctx, base, entity, networkAddr);
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(7, sub_82238290, 0x82238290) { ctx.r3.u64 = CECNetwork_TryReplicateEntity(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CECNetwork_SendPositionUpdate(CpuState& ctx, uint8_t* base, uint32_t networkAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(12, 0x822BCC90)) { ctx.r3.u64 = networkAddr; __imp__sub_822BCC90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x822BCC90);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);
	stack = PushStackFrame(base, stack, 208);

	// 48-byte net message on the stack: Matrix_InitZero sets it up, then it gets its own vtable.
	uint32_t message = stack + 96;
	ctx.r1.u64 = stack;
	Matrix_InitZero(ctx, base, message);

	// The vector at +64 is spilled to the stack and re-read from byte offsets 4, 8 and 0 (lvlx).
	PPCVRegister vecAt64{};
	SET_V8(vecAt64, VLOAD((networkAddr + 64) & ~0xF));
	uint32_t spill = stack + 80;
	VSTORE(spill & ~0xF, V8(vecAt64));
	PPCVRegister from4{};
	scratch.u32 = spill + 4;
	SET_V8(from4, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	VSTORE(spill & ~0xF, V8(vecAt64));
	PPCVRegister from8{};
	scratch.u32 = spill + 8;
	SET_V8(from8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	PPCVRegister mask{};
	SET_V8(mask, VLOAD(0x820991D0u & ~0xF));
	VSTORE(spill & ~0xF, V8(vecAt64));
	STORE32(message, 0x820A410Cu);

	// Merge the re-read parts into the message's vector at +16 with the permute masks at 0x820991D0/E0/F0.
	PPCVRegister messageVec16{};
	SET_V8(messageVec16, VLOAD((message + 16) & ~0xF));
	PPCVRegister from0{};
	scratch.u32 = spill;
	SET_V8(from0, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	PPCVRegister merged0{};
	SET_V8(merged0, rex::ppc::simde_mm_perm_epi8_(V8(messageVec16), V8(from0), V8(mask)));
	SET_V8(mask, VLOAD(0x820991E0u & ~0xF));
	PPCVRegister merged1{};
	SET_V8(merged1, rex::ppc::simde_mm_perm_epi8_(V8(merged0), V8(from4), V8(mask)));
	SET_V8(mask, VLOAD(0x820991F0u & ~0xF));
	PPCVRegister merged2{};
	SET_V8(merged2, rex::ppc::simde_mm_perm_epi8_(V8(merged1), V8(from8), V8(mask)));

	uint32_t root = LOAD32(uint32_t(g_83490000) + 26912);
	PPCVRegister vecAt80{};
	SET_V8(vecAt80, VLOAD((networkAddr + 80) & ~0xF));
	VSTORE((message + 32) & ~0xF, V8(vecAt80));
	VSTORE((message + 16) & ~0xF, V8(merged2));

	uint32_t messageQueue = LOAD32(LOAD32(root + 12) + 140);
	bool sendAllowed = LOAD8(messageQueue + 221) == 0 || LOAD8(messageQueue + 241) != 0;
	if (sendAllowed) {
		uint64_t uniqueId = Entity_GetUniqueId(ctx, base, network->m_4);
		bool flag834BE6DC = LOAD8(0x834BE6DCu) != 0;
		// Loaded again: the call above may have changed it.
		messageQueue = LOAD32(LOAD32(root + 12) + 140);

		// state the callee may pass on
		ctx.v5 = merged2;
		ctx.v6 = vecAt80;
		ctx.v7 = merged1;
		ctx.v8 = merged0;
		ctx.v9 = from0;
		ctx.v10 = messageVec16;
		ctx.v11 = from8;
		ctx.v12 = from4;
		ctx.v13 = vecAt64;
		uint32_t result = flag834BE6DC
			? NetworkMessageQueue_EnqueueMessage(ctx, base, messageQueue, message, uniqueId)
			: n_sub_822D6C78(ctx, base, messageQueue, message, uniqueId);

		network->m_60 = uint8_t(0);
		stack = PopStackFrame(stack, 208);
		ctx.r1.u64 = stack;
		return result;
	}

	network->m_60 = uint8_t(0);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return 0x820991F0u;  // r3 still holds the third mask's address on this path
}
PROMOTED_ENTRY(12, sub_822BCC90, 0x822BCC90) { ctx.r3.u64 = CECNetwork_SendPositionUpdate(ctx, base, ctx.r3.u32); }

uint64_t CECNetwork_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A2F30_B_ = int32_t(0x820A2F30);
	if (!UseLiftedCode(18, 0x8237D278)) { ctx.r3.u64 = classNameString; __imp__sub_8237D278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8237D278);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820A2F30_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(18, sub_8237D278, 0x8237D278) { ctx.r3.u64 = CECNetwork_GetClassName(ctx, base, ctx.r3.u64); }

// sub_8237DBF0  [4 bytes]
uint64_t CECNetwork_ResetThunk(CpuState& ctx, uint8_t* base, uint64_t networkAddr) {
	if (!UseLiftedCode(18, 0x8237DBF0)) { ctx.r3.u64 = networkAddr; __imp__sub_8237DBF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8237DBF0);
	return CECNetwork_Reset(ctx, base, networkAddr);
}
PROMOTED_ENTRY(18, sub_8237DBF0, 0x8237DBF0) { ctx.r3.u64 = CECNetwork_ResetThunk(ctx, base, ctx.r3.u64); }

// sub_8237DBF8  [108 bytes]
uint64_t CECNetwork_ReplicateDirtyEntity(CpuState& ctx, uint8_t* base, uint64_t networkAddr) {
	if (!UseLiftedCode(18, 0x8237DBF8)) { ctx.r3.u64 = networkAddr; __imp__sub_8237DBF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8237DBF8);
	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);
	uint32_t entity = network->m_4;

	// Forwards to CECDoor_UpdateOpenStateForEntity when any of six flag bits of the entity is set. lastTested / lastBit
	// hold what the original leaves in r9 / r8 for that callee: the last tested bit or word, and the
	// last extracted bit (r8 keeps the caller's value through the first two tests).
	uint64_t lastBit = ctx.r8.u64;
	uint32_t lastTested = (LOAD32(entity + 0x24) >> 19) & 1;
	if (lastTested == 0) {
		uint32_t flags3C = LOAD32(entity + 0x3C);
		lastTested = (flags3C >> 25) & 1;
		if (lastTested == 0) {
			lastTested = LOAD32(entity + 0x38);
			lastBit = lastTested & 1;
			if (lastBit == 0) {
				lastTested = LOAD32(entity + 0x34);
				lastBit = (lastTested >> 6) & 1;
				if (lastBit == 0) {
					lastTested = LOAD32(entity + 0x30);
					lastBit = lastTested >> 31;
					if (lastBit == 0 && ((flags3C >> 10) & 1) == 0) {
						ctx.r4.u64 = networkAddr;  // callers read r4 after the call
						return networkAddr;
					}
				}
			}
		}
	}
	// state the callee may pass on
	ctx.r8.u64 = lastBit;
	ctx.r9.u64 = lastTested;
	return CECDoor_UpdateOpenStateForEntity(ctx, base, entity, networkAddr);
}
PROMOTED_ENTRY(18, sub_8237DBF8, 0x8237DBF8) { ctx.r3.u64 = CECNetwork_ReplicateDirtyEntity(ctx, base, ctx.r3.u64); }

uint32_t CECNetwork_SendMicrophonePosition(CpuState& ctx, uint8_t* base, uint32_t networkAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(19, 0x823885C8)) { ctx.r3.u64 = networkAddr; __imp__sub_823885C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823885C8);
	uint32_t stack = ctx.r1.u64;
	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);
	stack = PushStackFrame(base, stack, 144);
	uint32_t result = networkAddr;
	if (network->m_60 == 0) {
		// 48-byte net message on the stack: Matrix_InitZero sets it up, then it gets its own vtable.
		uint32_t message = stack + 80;
		ctx.r1.u64 = stack;
		Matrix_InitZero(ctx, base, message);
		STORE32(message, 0x820A4118u);
		Player_ComputeCutsceneMicrophonePosition(ctx, base, message + 16, networkAddr + 32);
		uint32_t entity = network->m_4;
		PPCVRegister vecAt48{};
		SET_V8(vecAt48, VLOAD((networkAddr + 48) & ~0xF));
		VSTORE((message + 32) & ~0xF, V8(vecAt48));
		uint64_t uniqueId = Entity_GetUniqueId(ctx, base, entity);
		uint32_t manager = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
		uint32_t messageQueue = LOAD32(manager + 140);
		// state the callee may pass on
		ctx.r6.u64 = manager;
		result = NetworkMessageQueue_EnqueueMessage(ctx, base, messageQueue, message, uniqueId);
		network->m_60 = uint8_t(1);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(19, sub_823885C8, 0x823885C8) { ctx.r3.u64 = CECNetwork_SendMicrophonePosition(ctx, base, ctx.r3.u32); }

// sub_82389190  [84 bytes]
uint64_t CECNetwork_Reset(CpuState& ctx, uint8_t* base, uint64_t networkAddr) {
	if (!UseLiftedCode(19, 0x82389190)) { ctx.r3.u64 = networkAddr; __imp__sub_82389190(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82389190);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);

	stack = PushStackFrame(base, stack, 128);

	// Free the handle targets held in the two slots at +0x98 and +0x9C, clearing each slot.
	uint32_t slotAddr = uint32_t(networkAddr + 152);
	int32_t slotsLeft = 2;
	do {
		uint32_t target = LOAD32(slotAddr);
		// state the callee may pass on (carry: the caller's first, then the counter decrement's)
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		HandleTarget_Free(ctx, base, target);
		STORE32(slotAddr, 0u);
		flags.ca = slotsLeft > 0;
		slotsLeft--;
		slotAddr += 4;
	} while (slotsLeft != 0);

	// Zero the 384 bytes just before the queue indices (+0x180..+0x2FF), then reset both indices.
	uint64_t clearAddr = networkAddr + 384;
	ctx.xer.ca = flags.ca;  // state the callee may pass on
	memset(ctx, base, clearAddr, 0, 384);
	network->m_QueueStartIndex = 0;
	network->m_QueueEndIndex = 0;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return clearAddr;
}
PROMOTED_ENTRY(19, sub_82389190, 0x82389190) { ctx.r3.u64 = CECNetwork_Reset(ctx, base, ctx.r3.u64); }

uint32_t CECNetwork_HandleEntityDeath(CpuState& ctx, uint8_t* base, uint32_t networkObj, uint64_t postEvent) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(19, 0x82389730)) { ctx.r3.u64 = networkObj; ctx.r4.u64 = postEvent; __imp__sub_82389730(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82389730);
	uint32_t stack = ctx.r1.u64;
	CECNetwork* network = GameObject<CECNetwork>(base, networkObj);
	uint32_t globals = uint32_t(g_83490000);
	uint32_t result = networkObj;
	// Register values the callees and this function's callers see, kept as the original leaves them.
	uint64_t r4 = postEvent;
	uint64_t r6 = ctx.r6.u64;
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 160);

	// Post message 80 from the entity at m_4 to itself. The event position comes from a virtual call
	// (vtable +64) on the object at entity+124, which writes it into the stack buffer.
	if ((postEvent & 0xFF) != 0) {
		uint32_t entity = network->m_4;
		uint64_t position = uint64_t(stack) + 96;
		uint32_t positionSource = LOAD32(entity + 124);
		uint32_t callTarget = LOAD32(LOAD32(positionSource) + 64);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = position;
		ctx.r4.u64 = positionSource;
		ctx.r10.u64 = callTarget;
		REX_CALL_INDIRECT_FUNC(callTarget);
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
		uint32_t messageManager = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 88) + 4) + 16);
		result = MessageEvents_PostMessageEvent(ctx, base, messageManager, 80, position, entity, entity, 101, 0);
		r4 = ctx.r4.u64;
		r6 = ctx.r6.u64; r7 = ctx.r7.u64; r8 = ctx.r8.u64;
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
	}

	// Look up key 33 in the entity's table: its presence bit is bit 1 of the word at +40. A direct
	// index table at +140 gives the pair's index when present; otherwise a binary search runs over the
	// sorted 8-byte (key, value) pairs at +72..+76 (for a missing key the value word at end+4 is read).
	uint32_t entity = network->m_4;
	uint32_t entry33 = 0;
	bool found33 = false;
	uint64_t r9 = (LOAD32(entity + 40) >> 1) & 1;
	if (r9 != 0) {
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			uint32_t pair = LOAD8(indexTable + 33) * 8u + LOAD32(entity + 72);
			r9 = pair;
			entry33 = LOAD32(pair + 4);
		} else {
			uint32_t it = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			r6 = end;
			STORE32(stack + 80, 0);
			uint32_t span = end - it;
			STORE32(stack + 84, it);
			flags.ca = (int32_t)span < 0 && (span & 7) != 0;
			int32_t count = (int32_t)span >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				do {
					flags.ca = count < 0 && (count & 1) != 0;
					int32_t half = count >> 1;
					r9 = uint32_t(half);
					r8 = uint32_t(half) << 3;
					it += uint32_t(r8);
					bool less = (int32_t)LOAD32(it) < 33;
					r7 = less ? 1 : 0;
					if (less) {
						count = count - half - 1;
						it += 8;
					} else {
						it -= uint32_t(r8);
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 33) {
				// The search result pair at stack+80 is copied onto itself, then its iterator read back.
				STORE64(stack + 80, LOAD64(stack + 80));
				entry33 = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry33 = LOAD32(end + 4);
			}
		}
		found33 = true;
	}

	// Repeat until the node at entry+20 is gone or List_ContainsKey fails on it; after each success the
	// node's +36 value goes to List_RemoveFirstKey when the pointer at 0x83496920 is non-null and the byte at
	// 0x834968C5 is set.
	if (found33) {
		for (;;) {
			uint32_t head = LOAD32(entry33 + 20);
			if (head == 0) {
				result = 0;
				break;
			}
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6; ctx.r7.u64 = r7; ctx.r8.u64 = r8; ctx.r9.u64 = r9;
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			result = List_ContainsKey(ctx, base, head, 25);
			r4 = ctx.r4.u64;
			r6 = ctx.r6.u64; r7 = ctx.r7.u64; r8 = ctx.r8.u64;
			r9 = ctx.r9.u32;
			compare0 = ctx.cr0;
			flags.ca = ctx.xer.ca;
			if ((result & 0xFF) == 0) break;
			uint32_t node = LOAD32(entry33 + 20);
			if (node == 0) continue;
			if (LOAD32(globals + 26912) == 0 || LOAD8(globals + 26821) == 0) continue;
			uint32_t nodeValue = LOAD32(node + 36);
			uint32_t target = LOAD32(LOAD32(LOAD32(globals + 26912) + 12) + 128);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6; ctx.r7.u64 = r7; ctx.r8.u64 = r8; ctx.r9.u64 = r9;
			ctx.cr0 = compare0;
			ctx.xer.ca = flags.ca;
			List_RemoveFirstKey(ctx, base, target, nodeValue, 25);
			r4 = ctx.r4.u64;
			r6 = ctx.r6.u64; r7 = ctx.r7.u64; r8 = ctx.r8.u64;
			r9 = ctx.r9.u32;
			compare0 = ctx.cr0;
			flags.ca = ctx.xer.ca;
		}
	}

	// The same lookup for key 20 (presence bit 20 of the word at +36); here r9 keeps the full
	// 64-bit pair address, as the original's add leaves it.
	entity = network->m_4;
	uint32_t entry20 = 0;
	bool found20 = false;
	r9 = (LOAD32(entity + 36) >> 20) & 1;
	if (r9 != 0) {
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			r9 = uint64_t(LOAD8(indexTable + 20) * 8u) + LOAD32(entity + 72);
			entry20 = LOAD32(uint32_t(r9) + 4);
		} else {
			uint32_t it = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			r6 = end;
			STORE32(stack + 80, 0);
			uint32_t span = end - it;
			STORE32(stack + 84, it);
			flags.ca = (int32_t)span < 0 && (span & 7) != 0;
			int32_t count = (int32_t)span >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			if (count > 0) {
				do {
					flags.ca = count < 0 && (count & 1) != 0;
					int32_t half = count >> 1;
					r9 = uint32_t(half);
					r8 = uint32_t(half) << 3;
					it += uint32_t(r8);
					bool less = (int32_t)LOAD32(it) < 20;
					r7 = less ? 1 : 0;
					if (less) {
						count = count - half - 1;
						it += 8;
					} else {
						it -= uint32_t(r8);
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, it);
			}
			if (it != end && (int32_t)LOAD32(it) <= 20) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry20 = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry20 = LOAD32(end + 4);
			}
		}
		found20 = true;
	}

	if (found20) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6; ctx.r7.u64 = r7; ctx.r8.u64 = r8; ctx.r9.u64 = r9;
		ctx.cr0 = compare0;
		ctx.xer.ca = flags.ca;
		Creature_HandleDeath(ctx, base, entry20, 0);
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
		result = n_sub_82432A88(ctx, base, entry20, 0);
		r4 = ctx.r4.u64;
		r6 = ctx.r6.u64; r7 = ctx.r7.u64; r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 160);
	// callers read these registers after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4;
	ctx.r6.u64 = r6; ctx.r7.u64 = r7; ctx.r8.u64 = r8; ctx.r9.u64 = r9;
	ctx.cr0 = compare0;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(19, sub_82389730, 0x82389730) { ctx.r3.u64 = CECNetwork_HandleEntityDeath(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CECNetwork_EnqueueEvent(CpuState& ctx, uint8_t* base, uint32_t networkAddr, uint64_t payloadA, uint64_t payloadB, uint32_t orderKey, uint32_t entryByte) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(19, 0x8238A2D8)) { ctx.r3.u64 = networkAddr; ctx.r4.u64 = payloadA; ctx.r5.u64 = payloadB; ctx.r6.u64 = orderKey; ctx.r7.u64 = entryByte; __imp__sub_8238A2D8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8238A2D8);
	uint32_t stack = ctx.r1.u32;

	CECNetwork* network = GameObject<CECNetwork>(base, networkAddr);
	stack = PushStackFrame(base, stack, 112);

	// The original spills both payload words into the caller's parameter area.
	STORE64(stack + 168, payloadB);
	STORE64(stack + 160, payloadA);

	// Eight 48-byte entries at network+0x180 form a ring: QueueEndIndex counts the entries written,
	// QueueStartIndex is the oldest one still held, and the newest sits at (QueueEndIndex-1)&7.
	uint32_t queueEnd = network->m_QueueEndIndex;
	uint32_t queueStart = network->m_QueueStartIndex;
	int32_t queued = (int32_t)(queueEnd - queueStart);
	PPCCRRegister queuedCompare{};
	queuedCompare.compare<int32_t>(queued, 0, ctx.xer);

	// An entry whose order key is below the newest entry's is not written; the newest key is returned.
	if (queued > 0) {
		uint32_t newestIndex = (queueEnd - 1) & 7;
		uint32_t newestOrderKey = LOAD32(networkAddr + (newestIndex + 8) * 48 + 36);
		if ((int32_t)orderKey < (int32_t)newestOrderKey) {
			stack = PopStackFrame(stack, 112);
			// callers read r8 and cr0 after the call
			ctx.r1.u64 = stack;
			ctx.r8.u64 = newestIndex * 3;
			ctx.cr0 = queuedCompare;
			return newestOrderKey;
		}
	}

	uint32_t slot = networkAddr + ((queueEnd & 7) + 8) * 48;

	queueEnd += 1;
	network->m_QueueEndIndex = queueEnd;
	uint32_t oldestKept = queueEnd - 8;
	if ((int32_t)queueStart < (int32_t)oldestKept) {
		network->m_QueueStartIndex = oldestKept;
	}

	uint32_t statusWord = LOAD32(LOAD32(networkAddr + 4) + 64);
	ctx.fpscr.disableFlushMode();
	double timeOffset = ((statusWord >> 10) & 1) != 0 ? double(LOAD_F32(0x834BE6D8u)) : double(LOAD_F32(0x8209B650u));

	// v1, set by the caller, is stored at the entry's 16-byte-aligned start.
	VSTORE(slot & ~0xFu, V8(ctx.v1));
	STORE32(slot + 36, orderKey);
	STORE8(slot + 40, (uint8_t)entryByte);
	STORE64(slot + 16, payloadA);
	STORE64(slot + 24, payloadB);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.cr0 = queuedCompare;
	uint32_t result = Time_QueryTimebase(ctx, base, stack + 80);

	// The entry's timestamp (+32), from the timebase value just read.
	ctx.fpscr.disableFlushMode();
	uint64_t tickBits = LOAD64(stack + 80);
	double ticks = double(int64_t(tickBits));
	double tickDivisor = LOAD_F64(0x83496EC8u);
	double elapsed = ticks - LOAD_F64(0x83496EC0u);
	double scaled = elapsed / tickDivisor;
	double timestamp = scaled + timeOffset;
	STORE_F32(slot + 32, float(timestamp));

	stack = PopStackFrame(stack, 112);
	// callers read r8 and f8-f13 after the call (r8 holds 0x83490000 sign-extended, as lis leaves it)
	ctx.r1.u64 = stack;
	ctx.r8.u64 = uint64_t(int64_t(g_83490000));
	ctx.f8.f64 = timestamp;
	ctx.f9.f64 = scaled;
	ctx.f10.f64 = elapsed;
	ctx.f11.f64 = ticks;
	ctx.f12.u64 = tickBits;
	ctx.f13.f64 = tickDivisor;
	return result;
}
PROMOTED_ENTRY(19, sub_8238A2D8, 0x8238A2D8) { ctx.r3.u64 = CECNetwork_EnqueueEvent(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32, ctx.r7.u32); }
