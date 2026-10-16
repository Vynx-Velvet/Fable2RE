// CECFollow (vtable 0x820048A0): methods of the class as readable C++.
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

uint64_t n_sub_82263408(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	if (!UseLiftedCode(9, 0x82263408)) { ctx.r3.u64 = followAddr; __imp__sub_82263408(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82263408);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 96);
	if (TXT_820B3774_L_->m_15 != 0) {
		TXT_820B3774_L_->m_15 = 0;
		ctx.r1.u64 = stack;
		n_sub_82456428(ctx, base, followAddr);
	}
	ctx.r1.u64 = stack;
	uint64_t result = CECFollow_Clear(ctx, base, followAddr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(9, sub_82263408, 0x82263408) { ctx.r3.u64 = n_sub_82263408(ctx, base, ctx.r3.u64); }

// Walks the entity-handle list at +0x24 and erases every node whose handle (at node+8: tag, then block) has
// no block, or whose block's target word is zero (that handle is released first); nodes whose target is
// still set stay. The iterator is a (container, node) pair at stack+80; the erase is given the slot at
// stack+88 and returns a pointer to the next iterator.
uint64_t CECFollow_Clear(CpuState& ctx, uint8_t* base, uint64_t self) {
	if (!UseLiftedCode(9, 0x82263450)) { ctx.r3.u64 = self; __imp__sub_82263450(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82263450);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint64_t list = self + 36;
	const uint32_t sentinel = LOAD32((uint32_t)list + 4);
	uint32_t container = (uint32_t)list;
	uint64_t result = self;  // returned: self, the last node's handle address or the last erase result
	STORE32(stack + 80, container);
	uint32_t node = LOAD32(sentinel);

	while (true) {
		STORE32(stack + 84, node);
		while (true) {
			const uint32_t end = LOAD32((uint32_t)list + 4);
			if (container == 0 || container != (uint32_t)list) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (node == end) {
				stack = PopStackFrame(stack, 112);
				ctx.r1.u64 = stack;
				return result;
			}
			if (container == 0) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			const uint32_t containerEnd = LOAD32(container + 4);
			if (node == containerEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			const uint32_t handleBlock = LOAD32(node + 12);
			const uint64_t handle = (uint64_t)node + 8;
			result = handle;
			if (handleBlock != 0) {
				if (LOAD32(handleBlock) != 0) {
					// Target still set: keep the node and step to the next one.
					if (node == containerEnd) {
						ctx.r1.u64 = stack;
						ppc_trap(ctx, base, 22);
					}
					node = LOAD32(node);
					break;
				}
				ctx.r1.u64 = stack;
				// state the callee may pass on (r7 is the zero target word just read)
				ctx.r7.u64 = 0;
				ctx.r8.u64 = container;
				ctx.r9.u64 = containerEnd;
				ctx.r10.u64 = node;
				EntityHandle_Release(ctx, base, handle);
			}

			ctx.r1.u64 = stack;
			result = EntityHandleList_EraseNode(ctx, base, stack + 88, list, LOAD64(stack + 80));
			STORE64(stack + 80, LOAD64((uint32_t)result));
			node = LOAD32(stack + 84);
			container = LOAD32(stack + 80);
		}
	}
}
PROMOTED_ENTRY(9, sub_82263450, 0x82263450) { ctx.r3.u64 = CECFollow_Clear(ctx, base, ctx.r3.u64); }

uint64_t CECFollow_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820B36F8_B_ = int32_t(0x820B36F8);
	if (!UseLiftedCode(25, 0x82455ED0)) { ctx.r3.u64 = classNameString; __imp__sub_82455ED0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82455ED0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820B36F8_B_, -1);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(25, sub_82455ED0, 0x82455ED0) { ctx.r3.u64 = CECFollow_GetClassName(ctx, base, ctx.r3.u64); }

// Destructor body: releases the members, puts the base vtable back and frees the object itself when bit 0 of
// freeFlags is set.
uint64_t n_sub_82455F78(CpuState& ctx, uint8_t* base, uint64_t followAddr, uint64_t freeFlags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(25, 0x82455F78)) { ctx.r3.u64 = followAddr; ctx.r4.u64 = freeFlags; __imp__sub_82455F78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82455F78);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;

	ctx.r4.u64 = freeFlags;  // state the callee may pass on
	SharedHandle_Release(ctx, base, followAddr + 52);
	List_ClearRefCountedHandleNodes(ctx, base, followAddr + 36);
	HandleTarget_Free(ctx, base, TXT_820B3774_L_->m_28);
	TXT_820B3774_L_->m_28 = 0;

	TXT_820B3774_L_->m_1C = uint32_t(g_820F1664);
	ctx.r10.u64 = uint32_t(g_820F1664);  // state the callee may pass on
	EntityHandle_Release(ctx, base, followAddr + 28);
	TXT_820B3774_L_->m_20 = 0;
	TXT_820B3774_L_->vtable = 0x820A8D10u;

	if ((freeFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, followAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return followAddr;
}
PROMOTED_ENTRY(25, sub_82455F78, 0x82455F78) { ctx.r3.u64 = n_sub_82455F78(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_82455FF0(CpuState& ctx, uint8_t* base, uint64_t followAddr, uint64_t dbRecord) {
	constexpr int32_t str_TXT_820B3704_B_ = int32_t(0x820B3704);
	if (!UseLiftedCode(25, 0x82455FF0)) { ctx.r3.u64 = followAddr; ctx.r4.u64 = dbRecord; __imp__sub_82455FF0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82455FF0);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82392C88(ctx, base, TXT_820B3774_L_->m_4, followAddr);
	if ((uint32_t)dbRecord != 0) {
		result = GameDB_ReadBoolField_82303F38(ctx, base, dbRecord, str_TXT_820B3704_B_);
		TXT_820B3774_L_->m_14 = (uint8_t)result;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82455FF0, 0x82455FF0) { ctx.r3.u64 = n_sub_82455FF0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// When mode is 1, serializes the named follow settings through the stream (the 32-bit values at +0x0C and
// +0x30, the float at +0x18, the bytes at +0x10, +0x11, +0x12 and +0x14), then the follow target's 8-byte id
// through n_sub_8244DAE0: with saving set the id is taken from the entity held by the handle at +0x1C (zero
// unless that entity is flagged, see below); otherwise a new zeroed block is put in the shared handle at
// +0x34 for the call to fill in, and m_13 is set.
uint64_t n_sub_82456050(CpuState& ctx, uint8_t* base, uint64_t followAddr, uint64_t stream, uint32_t mode, uint64_t saving) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820B3704_B_ = int32_t(0x820B3704);
	constexpr int32_t str_TXT_820B3710_B_ = int32_t(0x820B3710);
	constexpr int32_t str_TXT_820B371C_B_ = int32_t(0x820B371C);
	constexpr int32_t str_TXT_820B372C_B_ = int32_t(0x820B372C);
	constexpr int32_t str_TXT_820B3734_B_ = int32_t(0x820B3734);
	constexpr int32_t str_TXT_820B3744_B_ = int32_t(0x820B3744);
	constexpr int32_t str_TXT_820B3764_B_ = int32_t(0x820B3764);
	if (!UseLiftedCode(25, 0x82456050)) { ctx.r3.u64 = followAddr; ctx.r4.u64 = stream; ctx.r5.u64 = mode; ctx.r6.u64 = saving; __imp__sub_82456050(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82456050);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 144);

	if (mode != 1) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = stream;  // callers read r4 after the call
		return followAddr;
	}

	// stack+80 holds a temporary CCharString with the field name. The U32 and float serializers take the
	// name's C string in r4 (the fallback at 0x8209003F when the CCharString has no data).
	ctx.r1.u64 = stack;
	ctx.r6.u64 = saving;  // state the callee may pass on
	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3710_B_, -1);
	STORE32(stack + 84, TXT_820B3774_L_->m_C);
	uint32_t nameData = LOAD32(stack + 80);
	ctx.r4.u64 = nameData == 0 ? uint64_t(g_8209003F) : uint64_t(LOAD32(nameData));
	IStream_SerializeU32(ctx, base, stream, stack + 84);
	TXT_820B3774_L_->m_C = LOAD32(stack + 84);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B371C_B_, -1);
	IStream_SerializeString(ctx, base, stack + 80, stream, followAddr + 16);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B372C_B_, -1);
	nameData = LOAD32(stack + 80);
	ctx.r4.u64 = nameData == 0 ? uint64_t(g_8209003F) : uint64_t(LOAD32(nameData));
	IStream_SerializeFloat(ctx, base, stream, followAddr + 24);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3734_B_, -1);
	nameData = LOAD32(stack + 80);
	ctx.r4.u64 = nameData == 0 ? uint64_t(g_8209003F) : uint64_t(LOAD32(nameData));
	IStream_SerializeU32(ctx, base, stream, followAddr + 48);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3744_B_, -1);
	IStream_SerializeString(ctx, base, stack + 80, stream, followAddr + 17);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	// The field name for +0x12 is the string at 0x820B3754.
	ctx.r10.s64 = str_TXT_820B0000_B_;  // state the callee may pass on
	CCharString_ConstructFromCStr(ctx, base, stack + 80, (int64_t)str_TXT_820B0000_B_ + 14164, -1);
	IStream_SerializeString(ctx, base, stack + 80, stream, followAddr + 18);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3704_B_, -1);
	IStream_SerializeString(ctx, base, stack + 80, stream, followAddr + 20);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);

	const uint32_t savingByte = uint32_t(saving) & 0xFF;
	if (savingByte != 0) {
		// The id at +20 of the entity held by the handle at +0x1C (tag, then block); zero unless that
		// entity has bit 0x40 set in its byte at +144.
		const uint64_t targetHandle = followAddr + 28;
		STORE32(stack + 88, 0);
		STORE32(stack + 92, 0);
		uint32_t entityFlag = 0;
		const uint32_t handleBlock = LOAD32((uint32_t)targetHandle + 4);
		if (handleBlock != 0) {
			const uint32_t storedTarget = LOAD32(handleBlock);
			// state the callee may pass on
			ctx.r8.u64 = savingByte;
			ctx.r10.u64 = storedTarget;
			if (storedTarget == 0) {
				EntityHandle_Release(ctx, base, targetHandle);
			} else {
				const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, targetHandle);
				entityFlag = LOAD8(entity + 144) & 64;
			}
		}
		if (entityFlag != 0) {
			ctx.r10.u64 = entityFlag;  // state the callee may pass on
			const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, targetHandle);
			STORE64(stack + 88, LOAD64(entity + 20));
		}
		CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3764_B_, -1);
		n_sub_8244DAE0(ctx, base, stack + 88, stack + 80, stream);
		const uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	ctx.r8.u64 = savingByte;  // state the callee may pass on (zero here)
	uint64_t idBlock = operator_new(ctx, base, 8);
	if ((uint32_t)idBlock != 0) {
		STORE32((uint32_t)idBlock, 0);
		STORE32((uint32_t)idBlock + 4, 0);
	} else {
		idBlock = 0;
	}
	SharedHandle_Assign(ctx, base, followAddr + 52, idBlock);

	CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B3764_B_, -1);
	n_sub_8244DAE0(ctx, base, TXT_820B3774_L_->m_34, stack + 80, stream);
	const uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
	TXT_820B3774_L_->m_13 = 1;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82456050, 0x82456050) { ctx.r3.u64 = n_sub_82456050(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

// When the shared handle at +0x34 holds an id block, looks the 8-byte id up (n_sub_82264448) and points the
// entity handle at +0x1C at the result. If that handle then holds an entity (an empty one is released) whose
// byte at +144 has bit 0x40 set, calls n_sub_82457468 and sets m_15 unless m_11 is set. Finally releases and
// clears the shared handle.
uint64_t n_sub_82456310(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x82456310)) { ctx.r3.u64 = followAddr; __imp__sub_82456310(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82456310);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t idBlock = TXT_820B3774_L_->m_34;
	if (idBlock == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = 0;  // callers read r4 after the call
		return followAddr;
	}

	// The object searched for the id, reached from the global at 0x83496920.
	const uint32_t root = LOAD32((uint32_t)g_83490000 + 26912);
	const uint32_t rootChild = LOAD32(root + 12);
	const uint32_t lookupSlot = LOAD32(LOAD32(rootChild + 88) + 4);
	const uint32_t lookupObject = LOAD32(lookupSlot);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r8.u64 = lookupSlot;
	ctx.r10.u64 = rootChild;
	const uint64_t target = n_sub_82264448(ctx, base, lookupObject, idBlock);

	// A temporary entity handle at stack+80 (tag, then block) is pointed at the target and copied into +0x1C.
	constexpr int64_t handleTag = (int64_t)g_820F0000 + 5732;
	const uint64_t tempHandle = (uint64_t)stack + 80;
	STORE32(stack + 84, 0);
	STORE32(stack + 80, (uint32_t)handleTag);
	// state the callee may pass on
	ctx.r6.u64 = handleTag;
	ctx.r7.s64 = g_820F0000;
	EntityHandle_SetTarget(ctx, base, tempHandle, target);
	const uint64_t targetHandle = followAddr + 28;
	EntityHandle_Assign(ctx, base, targetHandle, tempHandle);
	STORE32(stack + 80, (uint32_t)handleTag);
	// state the callee may pass on
	ctx.r4.u64 = handleTag;
	ctx.r5.s64 = g_820F0000;
	EntityHandle_Release(ctx, base, tempHandle);

	uint32_t entityFlag = 0;
	const uint32_t handleBlock = TXT_820B3774_L_->m_20;
	if (handleBlock != 0) {
		const uint32_t storedTarget = LOAD32(handleBlock);
		ctx.r10.u64 = storedTarget;  // state the callee may pass on
		if (storedTarget == 0) {
			EntityHandle_Release(ctx, base, targetHandle);
		} else {
			const uint32_t entity = (uint32_t)EntityHandle_Get_825575C8(ctx, base, targetHandle);
			entityFlag = LOAD8(entity + 144) & 64;
		}
	}
	if (entityFlag != 0) {
		ctx.r10.u64 = entityFlag;  // state the callee may pass on
		n_sub_82457468(ctx, base, followAddr);
		if (TXT_820B3774_L_->m_11 == 0) {
			TXT_820B3774_L_->m_15 = 1;
		}
	}

	const uint64_t result = SharedHandle_Release(ctx, base, followAddr + 52);
	TXT_820B3774_L_->m_34 = 0;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82456310, 0x82456310) { ctx.r3.u64 = n_sub_82456310(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82456420(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	if (!UseLiftedCode(25, 0x82456420)) { ctx.r3.u64 = followAddr; __imp__sub_82456420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82456420);
	return n_sub_82456800(ctx, base, followAddr);
}
PROMOTED_ENTRY(25, sub_82456420, 0x82456420) { ctx.r3.u64 = n_sub_82456420(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82456428(CpuState& ctx, uint8_t* base, uint32_t followAddr) {
	constexpr int32_t g_82000AF4 = int32_t(0x82000AF4);
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820B3774_B_ = int32_t(0x820B3774);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x82456428)) { ctx.r3.u64 = followAddr; __imp__sub_82456428(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82456428);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 128);

	// Three CCharStrings live in the frame.
	const uint64_t label = (uint64_t)stack + 80;
	const uint64_t tempString = (uint64_t)stack + 84;
	const uint64_t secondString = (uint64_t)stack + 88;
	const uint32_t gameGlobal = uint32_t(g_83490000);

	// The label starts as the owner's 64-bit id (at +20) in text form. follow->m_4 is read again before each
	// later call, as the original does.
	const uint64_t ownerId = LOAD64(uint32_t(TXT_820B3774_L_->m_4) + 20);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = ownerId & 0xFFFFFFFF00000000ULL;  // state the callee may pass on
	CharString_ConstructFromUInt64(ctx, base, tempString, ownerId);
	CCharString_CopyConstruct(ctx, base, label, tempString);
	CCharString_AssignCString(ctx, base, label, str_TXT_820B3774_B_);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempString);

	uint32_t statsHolder = LOAD32(LOAD32(gameGlobal + 26788) + 32);
	ctx.r6.u64 = statsHolder;  // state the callee may pass on
	n_sub_821BD998(ctx, base, LOAD32(statsHolder + 28), TXT_820B3774_L_->m_4, label);

	CCharString_ConstructFromCStr(ctx, base, tempString, str_TXT_820B3774_B_, -1);
	ctx.r3.u64 = LOAD32(LOAD32(LOAD32(gameGlobal + 26788) + 32) + 28);  // state the callee may pass on
	n_sub_823B6CE0(ctx, base, TXT_820B3774_L_->m_4, tempString, ctx.r8.u64);  // r8 as the earlier calls left it
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempString);

	CCharString_AssignFromWideStr(ctx, base, tempString, g_82000AF4);
	Stats_ApplyModifierIfAllowed(ctx, base, LOAD32(LOAD32(LOAD32(gameGlobal + 26788) + 32) + 28), label, TXT_820B3774_L_->m_4, tempString, 29);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, tempString);

	CCharString_ConstructFromCStr(ctx, base, secondString, g_82000C98, -1);
	CCharString_ConstructFromCStr(ctx, base, tempString, str_TXT_820B3774_B_, -1);
	statsHolder = LOAD32(LOAD32(gameGlobal + 26788) + 32);
	ctx.r3.u64 = LOAD32(statsHolder + 28);  // state the callee may pass on
	n_sub_823B6C00(ctx, base, TXT_820B3774_L_->m_4, tempString, secondString, 29, statsHolder);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tempString);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, secondString);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, label);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82456428, 0x82456428) { ctx.r3.u64 = n_sub_82456428(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82456E18(CpuState& ctx, uint8_t* base, uint32_t followAddr, uint32_t enabled) {
	if (!UseLiftedCode(25, 0x82456E18)) { ctx.r3.u64 = followAddr; ctx.r4.u64 = enabled; __imp__sub_82456E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82456E18);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t registry = LOAD32(0x83496BD0u);
	uint32_t recordId = LOAD32(uint32_t(TXT_820B3774_L_->m_4) + 28);
	ctx.r1.u64 = stack;
	ctx.r5.u64 = 0;  // state the callee may pass on
	uint64_t result = GDB_RecordExists_Impl(ctx, base, registry, recordId);

	// r6-r8 as the original leaves them; callers read them after the call
	const uint64_t recordExists = ((uint32_t)result != 0) ? 1 : 0;
	uint64_t reg6 = recordExists;
	uint64_t reg7 = recordExists;
	uint64_t reg8 = recordExists ^ 1;

	if (recordExists != 0) {
		TXT_820B3774_L_->m_10 = (uint8_t)enabled;
		uint32_t isDisabled = ((enabled & 0xFF) == 0) ? 1 : 0;
		ctx.r6.u64 = reg6;  // state the callee may pass on
		ctx.r7.u64 = reg7;
		ctx.r8.u64 = reg8;
		result = n_sub_82391838(ctx, base, TXT_820B3774_L_->m_4, isDisabled);
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	return result;
}
PROMOTED_ENTRY(25, sub_82456E18, 0x82456E18) { ctx.r3.u64 = n_sub_82456E18(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_82457468(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	if (!UseLiftedCode(25, 0x82457468)) { ctx.r3.u64 = followAddr; __imp__sub_82457468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82457468);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister xer = ctx.xer;  // the carry is left for callers
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 112);

	const uint64_t handleAddr = followAddr + 28;  // the entity handle at +0x1C
	uint64_t result = followAddr;
	uint32_t reg10 = ctx.r10.u32;  // r10 as handed to the handle calls

	// A handle whose reference cell (+0x20) holds 0 is released; otherwise the target counts only with bit 0x40
	// of its byte at +144.
	bool targetFlagged = false;
	uint32_t handleRef = TXT_820B3774_L_->m_20;
	if (handleRef != 0) {
		reg10 = LOAD32(handleRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = reg10;  // state the callee may pass on
		if (reg10 == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			reg10 = LOAD8((uint32_t)result + 144) & 64;
			targetFlagged = reg10 != 0;
		}
		xer.ca = ctx.xer.ca;
	}
	if (!targetFlagged) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		ctx.xer.ca = xer.ca;
		return result;
	}

	ctx.r1.u64 = stack;
	ctx.r10.u64 = reg10;  // state the callee may pass on
	result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
	const uint32_t target = (uint32_t)result;
	// r6-r9 as the lookup below leaves them, handed to the final call
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint32_t reg9 = ctx.r9.u32;
	xer.ca = ctx.xer.ca;

	// Look up key 94 in the target's table of (key, value) pairs (begin +72, end +76); bit 0x40000000 of +44
	// says the table is there. Without a pair for the key, the value word of the end position is read.
	if (((LOAD32(target + 44) >> 30) & 1) == 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		ctx.xer.ca = xer.ca;
		return result;
	}
	uint32_t entryValue;
	uint32_t slotTable = LOAD32(target + 140);
	if (slotTable != 0) {
		// direct: byte 94 of the slot table gives the pair's slot
		reg9 = LOAD8(slotTable + 94) * 8 + LOAD32(target + 72);
		entryValue = LOAD32(reg9 + 4);
	} else {
		// lower_bound over the pairs sorted by key; the iterator pair sits at stack+80
		uint32_t first = LOAD32(target + 72);
		reg6 = LOAD32(target + 76);
		const uint32_t end = (uint32_t)reg6;
		STORE32(stack + 80, 0u);
		reg9 = end - first;
		STORE32(stack + 84, first);
		xer.ca = (int32_t)reg9 < 0 && (reg9 & 0x7) != 0;  // carry of the arithmetic shift below
		int32_t count = (int32_t)reg9 >> 3;
		if (count > 0) {
			do {
				reg9 = uint32_t(count >> 1);
				reg8 = reg9 << 3;
				first += (uint32_t)reg8;
				reg7 = ((int32_t)LOAD32(first) < 94) ? 1 : 0;
				if (reg7 != 0) {
					count = count - (int32_t)reg9 - 1;
					first += 8;
				} else {
					first -= (uint32_t)reg8;
					count = (int32_t)reg9;
				}
			} while (count > 0);
			STORE32(stack + 84, first);
		}
		if (first != end && (int32_t)LOAD32(first) <= 94) {
			STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the iterator unchanged
			entryValue = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			entryValue = LOAD32(end + 4);
		}
	}

	ctx.r6.u64 = reg6;  // state the callee may pass on
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.xer.ca = xer.ca;
	result = n_sub_82457368(ctx, base, entryValue, TXT_820B3774_L_->m_4);
	xer.ca = ctx.xer.ca;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.xer.ca = xer.ca;
	return result;
}
PROMOTED_ENTRY(25, sub_82457468, 0x82457468) { ctx.r3.u64 = n_sub_82457468(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82457628(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	if (!UseLiftedCode(25, 0x82457628)) { ctx.r3.u64 = followAddr; __imp__sub_82457628(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82457628);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister xer = ctx.xer;  // the carry is left for callers
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint64_t handleAddr = followAddr + 28;  // the entity handle at +0x1C
	uint64_t result = followAddr;
	uint32_t reg10 = ctx.r10.u32;  // r10 as handed to the handle calls

	// A handle whose reference cell (+0x20) holds 0 is released; otherwise the target counts only with bit 0x40
	// of its byte at +144.
	bool targetFlagged = false;
	uint32_t handleRef = TXT_820B3774_L_->m_20;
	if (handleRef != 0) {
		reg10 = LOAD32(handleRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = reg10;  // state the callee may pass on
		if (reg10 == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			reg10 = LOAD8((uint32_t)result + 144) & 64;
			targetFlagged = reg10 != 0;
		}
		xer.ca = ctx.xer.ca;
	}
	if (!targetFlagged) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.xer.ca = xer.ca;
		return (uint32_t)result;
	}

	ctx.r1.u64 = stack;
	ctx.r10.u64 = reg10;  // state the callee may pass on
	result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
	const uint32_t target = (uint32_t)result;
	// r6-r9 as the lookup below leaves them, handed to the handle releases in the list walk
	uint64_t reg6 = ctx.r6.u64;
	uint32_t reg7 = ctx.r7.u32;
	uint32_t reg8 = ctx.r8.u32;
	uint32_t reg9 = ctx.r9.u32;
	xer.ca = ctx.xer.ca;

	// Look up key 94 in the target's table of (key, value) pairs (begin +72, end +76); bit 0x40000000 of +44
	// says the table is there. Without a pair for the key, the value word of the end position is read.
	if (((LOAD32(target + 44) >> 30) & 1) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.xer.ca = xer.ca;
		return (uint32_t)result;
	}
	uint32_t entryValue;
	uint32_t slotTable = LOAD32(target + 140);
	if (slotTable != 0) {
		// direct: byte 94 of the slot table gives the pair's slot
		reg9 = LOAD8(slotTable + 94) * 8 + LOAD32(target + 72);
		entryValue = LOAD32(reg9 + 4);
	} else {
		// lower_bound over the pairs sorted by key; the iterator pair sits at stack+80
		uint32_t first = LOAD32(target + 72);
		reg6 = LOAD32(target + 76);
		const uint32_t end = (uint32_t)reg6;
		STORE32(stack + 80, 0u);
		reg9 = end - first;
		STORE32(stack + 84, first);
		xer.ca = (int32_t)reg9 < 0 && (reg9 & 0x7) != 0;  // carry of the arithmetic shift below
		int32_t count = (int32_t)reg9 >> 3;
		if (count > 0) {
			do {
				reg9 = uint32_t(count >> 1);
				reg8 = reg9 << 3;
				first += reg8;
				reg7 = ((int32_t)LOAD32(first) < 94) ? 1 : 0;
				if (reg7 != 0) {
					count = count - (int32_t)reg9 - 1;
					first += 8;
				} else {
					first -= reg8;
					count = (int32_t)reg9;
				}
			} while (count > 0);
			STORE32(stack + 84, first);
		}
		if (first != end && (int32_t)LOAD32(first) <= 94) {
			STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the iterator unchanged
			entryValue = LOAD32(LOAD32(stack + 84) + 4);
		} else {
			entryValue = LOAD32(end + 4);
		}
	}

	// Walk the handle list at +36 of that value (iterator pair at stack+80): a handle whose target is gone is
	// released, and the first node whose target (0 when gone) equals follow->m_4 is erased.
	const uint64_t list = uint64_t(entryValue) + 36;
	const uint32_t owner = TXT_820B3774_L_->m_4;
	STORE32(stack + 80, (uint32_t)list);
	uint32_t node = LOAD32(LOAD32((uint32_t)list + 4));
	STORE32(stack + 84, node);
	while (node != LOAD32((uint32_t)list + 4)) {
		uint32_t nodeHandleRef = LOAD32(node + 12);
		result = uint64_t(node) + 8;  // the node's entity handle
		uint32_t nodeTarget = 0;
		if (nodeHandleRef != 0) {
			nodeTarget = LOAD32(nodeHandleRef);
			if (nodeTarget == 0) {
				ctx.r6.u64 = reg6;  // state the callee may pass on
				ctx.r7.u64 = reg7;
				ctx.r8.u64 = reg8;
				ctx.r9.u64 = reg9;
				ctx.r10.u64 = 0;
				ctx.xer.ca = xer.ca;
				result = EntityHandle_Release(ctx, base, result);
				reg6 = ctx.r6.u64;
				reg7 = ctx.r7.u32;
				reg8 = ctx.r8.u32;
				reg9 = ctx.r9.u32;
				xer.ca = ctx.xer.ca;
			}
		}
		if (nodeTarget == owner) {
			STORE32(stack + 84, node);
			ctx.xer.ca = xer.ca;
			uint32_t erased = EntityHandleList_EraseNode(ctx, base, (uint64_t)stack + 88, list, LOAD64(stack + 80));
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return erased;
		}
		// stepping past the end traps (possible only if the release above changed the list)
		if (node == LOAD32((uint32_t)list + 4)) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}
	STORE32(stack + 84, node);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.xer.ca = xer.ca;
	return (uint32_t)result;
}
PROMOTED_ENTRY(25, sub_82457628, 0x82457628) { ctx.r3.u64 = n_sub_82457628(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82458698(CpuState& ctx, uint8_t* base, uint64_t followAddr) {
	constexpr int32_t str_TXT_820B3994_B_ = int32_t(0x820B3994);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x82458698)) { ctx.r3.u64 = followAddr; __imp__sub_82458698(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82458698);
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	stack = PushStackFrame(base, stack, 256);
	if (LOAD8(0x8349696Au) == 0) {
		stack = PopStackFrame(stack, 256);
		ctx.r1.u64 = stack;
		return followAddr;
	}

	// Frame: +80 label string, +96 vector copy / scratch / wide label, +112 count string, then a scratch float,
	// then a ref-counted pointer (passed to n_sub_821F5B90, released at the end), +128 the owner's vector,
	// +144 the four scaled bytes, +160 the object built by C_820A6754_Constructor.
	// The vector loads below use the guest's lvlx (load vector left) shuffle.
	auto loadVectorLeft = [&](uint32_t addr) {
		return simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(addr & ~0xF)),
		                             simde_mm_load_si128((simde__m128i*)&VectorMaskL[(addr & 0xF) * 16]));
	};

	// Label at stack+80 from str_TXT_820B3994_B_ and m_2C as text.
	ctx.r1.u64 = stack;
	uint64_t countText = CCharString_ConstructFormatInt(ctx, base, (uint64_t)stack + 112, TXT_820B3774_L_->m_2C);
	CCharString_ConstructFromCStr(ctx, base, (uint64_t)stack + 80, str_TXT_820B3994_B_, -1);
	RefCountedString_Assign(ctx, base, (uint64_t)stack + 80, countText);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)stack + 112);

	// The owner's component at +124 writes a vector to stack+128 (virtual at vtable +64).
	uint32_t owner = TXT_820B3774_L_->m_4;
	uint32_t component = LOAD32(owner + 124);
	uint32_t componentVtable = LOAD32(component);
	uint32_t getVector = LOAD32(componentVtable + 64);
	ctx.r3.u64 = (uint64_t)stack + 128;
	ctx.r4.u64 = component;
	ctx.r8.u64 = getVector;  // state the callee may pass on
	ctx.r9.u64 = componentVtable;
	ctx.r10.u64 = owner;
	REX_CALL_INDIRECT_FUNC(getVector);

	// Copy it to stack+96, add the float at 0x820994C0 to its third element and merge the sum into the vector
	// at stack+128 with the permute mask at 0x820991F0.
	PPCVRegister ownerVector{};
	SET_V8(ownerVector, VLOAD((stack + 128) & ~0xF));
	VSTORE((stack + 96) & ~0xF, V8(ownerVector));
	ctx.fpscr.disableFlushMode();
	const double zOffset = double(LOAD_F32(0x820994C0u));
	const double shiftedZ = double(float(double(LOAD_F32(stack + 104)) + zOffset));
	PPCVRegister mergeMask{};
	SET_V8(mergeMask, VLOAD(0x820991F0u & ~0xF));
	uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
	STORE_F32(stack + 112, float(shiftedZ));
	PPCVRegister shiftedZVector{};
	SET_V8(shiftedZVector, loadVectorLeft(stack + 112));
	SET_V8(ownerVector, rex::ppc::simde_mm_perm_epi8_(V8(ownerVector), V8(shiftedZVector), V8(mergeMask)));
	VSTORE((stack + 128) & ~0xF, V8(ownerVector));

	uint32_t managerChild = LOAD32(manager + 12);
	ctx.r6.u64 = (uint64_t)stack + 96;  // state the callee may pass on
	ctx.r7.u64 = (uint64_t)stack + 128;
	ctx.r8.u64 = managerChild;
	ctx.r9.s64 = g_83490000;
	ctx.r10.u64 = (uint64_t)stack + 128;
	ctx.f13.f64 = shiftedZ;
	ctx.v7 = mergeMask;
	ctx.v13 = shiftedZVector;
	n_sub_821F5B90(ctx, base, (uint64_t)stack + 112, LOAD32(managerChild + 96), (int64_t)g_83490000 + 30564);

	manager = LOAD32(uint32_t(g_83490000) + 26912);
	uint32_t managerVtable = LOAD32(manager);
	uint32_t managerMethod = LOAD32(managerVtable + 20);
	ctx.r3.u64 = manager;
	ctx.r6.u64 = managerMethod;  // state the callee may pass on
	ctx.r7.u64 = managerVtable;
	REX_CALL_INDIRECT_FUNC(managerMethod);
	uint32_t returnedInner = LOAD32(ctx.r3.u32 + 4);

	// The four bytes at 0x83319A88, each converted to double through stack+96 (stored as a 64-bit
	// integer, reloaded as the bits of a double) and scaled by the float at 0x83321514.
	const uint32_t fourBytes = uint32_t(g_83320000) - 25976;
	const uint64_t byte0 = LOAD8(fourBytes);
	const uint64_t byte3 = LOAD8(fourBytes + 3);
	const uint64_t byte2 = LOAD8(fourBytes + 2);
	const uint64_t byte1 = LOAD8(fourBytes + 1);
	STORE64(stack + 96, byte3);
	ctx.fpscr.disableFlushMode();
	STORE64(stack + 96, byte1);
	STORE64(stack + 96, byte0);
	STORE64(stack + 96, byte2);
	const double value0 = double(int64_t(byte0));
	const double value1 = double(int64_t(byte1));
	const double value2 = double(int64_t(byte2));
	const double value3 = double(int64_t(byte3));
	const double scale = double(LOAD_F32(0x83321514u));
	const double scaled1 = double(float(value1 * scale));
	const double scaled3 = double(float(value3 * scale));
	const double scaled2 = double(float(value2 * scale));
	const double scaled0 = double(float(value0 * scale));

	// Each scaled value goes through stack+96 into a vector (laneN carries scaledN); they are merged into one
	// vector stored at stack+144.
	PPCVRegister lane1{};
	PPCVRegister lane3{};
	PPCVRegister scaledBytes{};
	PPCVRegister lane0{};
	STORE_F32(stack + 96, float(scaled1));
	SET_V8(lane1, loadVectorLeft(stack + 96));
	STORE_F32(stack + 96, float(scaled3));
	SET_V8(lane3, loadVectorLeft(stack + 96));
	uint32_t innerValue = LOAD32(returnedInner);
	STORE_F32(stack + 96, float(scaled2));
	SET_V8(scaledBytes, loadVectorLeft(stack + 96));
	SET_VF(scaledBytes, simde_mm_blend_ps(VF(scaledBytes), simde_mm_permute_ps(VF(lane1), 57), 4));
	STORE_F32(stack + 96, float(scaled0));
	SET_V8(lane0, loadVectorLeft(stack + 96));
	SET_VF(lane0, simde_mm_blend_ps(VF(lane0), simde_mm_permute_ps(VF(lane3), 57), 4));
	SET_VF(scaledBytes, simde_mm_blend_ps(VF(scaledBytes), simde_mm_permute_ps(VF(lane0), 78), 3));
	VSTORE((stack + 144) & ~0xF, V8(scaledBytes));

	// The label as a wide string at stack+96.
	ctx.r5.u64 = (uint64_t)stack + 144;  // state the callee may pass on
	ctx.r6.u64 = (uint64_t)stack + 96;
	ctx.f1.f64 = value2;
	ctx.f2.f64 = scaled1;
	ctx.f3.f64 = value3;
	ctx.f4.f64 = value0;
	ctx.f5.f64 = value2;
	ctx.f6.u64 = byte2;
	ctx.f7.u64 = byte0;
	ctx.f8.f64 = value3;
	ctx.f9.f64 = value1;
	ctx.f10.f64 = scaled0;
	ctx.f11.f64 = scaled2;
	ctx.f12.f64 = scaled3;
	ctx.f13.f64 = value0;
	ctx.v10 = lane0;
	ctx.v11 = scaledBytes;
	ctx.v12 = lane3;
	ctx.v13 = lane1;
	WideString_ConstructFromNarrow(ctx, base, (uint64_t)stack + 96, stack + 80);

	ctx.fpscr.disableFlushMode();
	SET_V8(ownerVector, VLOAD((stack + 128) & ~0xF));
	ctx.v1 = ownerVector;  // state the callee may pass on
	C_820A6754_Constructor(ctx, base, (uint64_t)stack + 160, 0x10004, stack + 112, (uint64_t)stack + 96, stack + 144, zOffset);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, (uint64_t)stack + 96);
	n_sub_821DDE30(ctx, base, (uint64_t)stack + 160, innerValue, 1);

	// Release what the object at stack+160 holds (+36, +32) and reset its vtable; then the other temporaries.
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, (uint64_t)stack + 196);
	RefCountedPtr_ReleaseAtomic(ctx, base, stack + 192);
	STORE32(stack + 160, 0x820A6754u);
	RefCountedPtr_ReleaseAtomic(ctx, base, stack + 112);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint64_t)stack + 80);

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(25, sub_82458698, 0x82458698) { ctx.r3.u64 = n_sub_82458698(ctx, base, ctx.r3.u64); }

uint64_t n_sub_824596B0(CpuState& ctx, uint8_t* base, uint64_t followAddr, uint64_t target, uint64_t flag, double floatArg) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(25, 0x824596B0)) { ctx.r3.u64 = followAddr; ctx.r4.u64 = target; ctx.r5.u64 = flag; ctx.f1.f64 = floatArg; __imp__sub_824596B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824596B0);
	PPCVRegister savedV127 = ctx.v127;
	uint32_t stack = ctx.r1.u64;
	CECFollow* TXT_820B3774_L_ = GameObject<CECFollow>(base, followAddr);
	uint64_t result = followAddr;

	// What callers find in r4-r9, f1, f13, cr0 and the carry afterwards, updated wherever the original
	// changes them (call results are read back where the original reads them).
	uint64_t r4 = target;
	uint64_t r5 = flag;
	uint64_t r6 = ctx.r6.u64;
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	uint64_t r9 = ctx.r9.u64;
	double f1 = floatArg;
	double f13;
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister xer = ctx.xer;
	auto readFlagsBack = [&] {
		cr0 = ctx.cr0;
		xer.ca = ctx.xer.ca;
	};
	const uint32_t flagByte = (uint32_t)flag & 0xFF;

	// The caller's v127 goes below the frame; the zero vector is replaced by the target's vector if it has one.
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 160);
	PPCVRegister targetVector{};
	SET_V8(targetVector, simde_mm_set1_epi32(int(0x0)));

	// A target with bit 0x40 of its byte at +144 set: its component at +124 writes a vector to stack+96
	// (virtual at vtable +64).
	if ((uint32_t)target != 0 && (LOAD8((uint32_t)target + 144) & 64) != 0) {
		uint32_t component = LOAD32((uint32_t)target + 124);
		uint32_t getVector = LOAD32(LOAD32(component) + 64);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = (uint64_t)stack + 96;
		ctx.r4.u64 = component;
		ctx.r5.u64 = r5;
		ctx.r10.u64 = getVector;  // state the callee may pass on
		ctx.f1.f64 = f1;
		REX_CALL_INDIRECT_FUNC(getVector);
		result = ctx.r3.u64;
		r4 = ctx.r4.u64;
		r5 = ctx.r5.u64;
		r6 = ctx.r6.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		f1 = ctx.f1.f64;
		readFlagsBack();
		r9 = (uint64_t)stack + 96;
		SET_V8(targetVector, VLOAD((stack + 96) & ~0xF));
	}

	// Squared length (3-element dot product) against the float at 0x82099AE0.
	ctx.fpscr.enableFlushMode();
	PPCVRegister lengthSquared{};
	SET_VF(lengthSquared, simde_mm_dp_ps(VF(targetVector), VF(targetVector), 0xEF));
	ctx.fpscr.disableFlushModeUnconditional();
	const double threshold = double(LOAD_F32(0x82099AE0u));
	VSTORE((stack + 80) & ~0xF, V8(lengthSquared));
	f13 = double(LOAD_F32(stack + 80));

	if (f13 > threshold) {
		// The vector goes to stack+80 for the owner's component (virtual at vtable +72), then n_sub_8256AEC8
		// gets stack+80, and the vector found there afterwards goes (in v1) to the virtual at vtable +112.
		uint32_t ownerComponent = LOAD32(uint32_t(TXT_820B3774_L_->m_4) + 124);
		VSTORE((stack + 80) & ~0xF, V8(targetVector));
		uint32_t componentVtable = LOAD32(ownerComponent);
		uint32_t method72 = LOAD32(componentVtable + 72);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = ownerComponent;
		ctx.r4.u64 = r4;  // state the callee may pass on
		ctx.r5.u64 = r5;
		ctx.r8.u64 = method72;
		ctx.r9.u64 = componentVtable;
		ctx.r10.u64 = (uint64_t)stack + 80;
		ctx.f1.f64 = f1;
		ctx.f13.f64 = f13;
		REX_CALL_INDIRECT_FUNC(method72);
		f1 = ctx.f1.f64;
		f13 = ctx.f13.f64;
		readFlagsBack();

		ctx.fpscr.disableFlushMode();
		const double constantArg = double(LOAD_F32(uint32_t(g_820A0000) - 27468));  // passed as both last arguments
		ctx.r7.s64 = g_820A0000;  // state the callee may pass on
		ctx.v127 = targetVector;
		n_sub_8256AEC8(ctx, base, (uint64_t)stack + 80, 0, ctx.f1.f64, constantArg, constantArg);
		f1 = ctx.f1.f64;
		f13 = ctx.f13.f64;
		readFlagsBack();

		uint32_t owner = TXT_820B3774_L_->m_4;
		uint32_t component = LOAD32(owner + 124);
		PPCVRegister adjustedVector{};
		SET_V8(adjustedVector, VLOAD((stack + 80) & ~0xF));
		uint32_t vtable = LOAD32(component);
		ctx.r3.u64 = component;
		ctx.r4.u64 = vtable;  // state the callee may pass on
		ctx.r5.u64 = owner;
		ctx.r6.u64 = (uint64_t)stack + 80;
		ctx.v1 = adjustedVector;
		REX_CALL_INDIRECT_FUNC(LOAD32(vtable + 112));
		result = ctx.r3.u64;
		r5 = ctx.r5.u64;
		r6 = ctx.r6.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		f1 = ctx.f1.f64;
		f13 = ctx.f13.f64;
		readFlagsBack();

		// Look up key 1 in the owner's table of (key, value) pairs (begin +72, end +76); bit 1 of +36 says the
		// table is there. Without a pair for the key, the value word of the end position is read. The value
		// ends up in r4 (0 without a table).
		const uint32_t tableOwner = TXT_820B3774_L_->m_4;
		r4 = 0;
		r9 = (LOAD32(tableOwner + 36) >> 1) & 1;
		const bool hasTable = (uint32_t)r9 != 0;
		if (hasTable) {
			uint32_t slotTable = LOAD32(tableOwner + 140);
			if (slotTable != 0) {
				// direct: byte 1 of the slot table gives the pair's slot
				r9 = uint64_t(uint32_t(LOAD8(slotTable + 1)) << 3) + LOAD32(tableOwner + 72);
				r4 = LOAD32((uint32_t)r9 + 4);
			} else {
				// lower_bound over the pairs sorted by key; the iterator pair sits at stack+80
				uint32_t first = LOAD32(tableOwner + 72);
				r9 = 0;
				r6 = LOAD32(tableOwner + 76);
				const uint32_t end = (uint32_t)r6;
				STORE32(stack + 80, 0u);
				r8 = r6 - first;
				STORE32(stack + 84, first);
				xer.ca = (int32_t)r8 < 0 && ((uint32_t)r8 & 0x7) != 0;  // carry of the arithmetic shift below
				int32_t count = (int32_t)r8 >> 3;
				cr0.compare<int32_t>(count, 0, xer);
				if (count > 0) {
					do {
						r9 = uint64_t(int64_t(count >> 1));
						r8 = uint32_t(r9) << 3;
						first += (uint32_t)r8;
						r7 = ((int32_t)LOAD32(first) < 1) ? 1 : 0;
						if (r7 != 0) {
							count = count - (int32_t)r9 - 1;
							first += 8;
						} else {
							first -= (uint32_t)r8;
							count = (int32_t)r9;
						}
					} while (count > 0);
					STORE32(stack + 84, first);
				}
				if (first != end && (int32_t)LOAD32(first) <= 1) {
					STORE64(stack + 80, LOAD64(stack + 80));  // the original rewrites the iterator unchanged
					r4 = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					r4 = LOAD32(end + 4);
				}
			}
		}

		// With the flag byte set and byte +80 of the value clear, n_sub_822358A8 gets the value and an object
		// reached through the manager at 0x83490000 + 26912 (r6-r9 keep the links of that chain).
		if (hasTable && flagByte != 0 && LOAD8((uint32_t)r4 + 80) == 0) {
			uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
			r9 = LOAD32(LOAD32(manager + 12) + 88);
			r8 = LOAD32((uint32_t)r9 + 4);
			r7 = LOAD32((uint32_t)r8 + 8);
			r6 = LOAD32((uint32_t)r7 + 4);
			uint32_t holder = LOAD32((uint32_t)r6 + 36);
			if (holder != 0) {
				uint32_t handler = LOAD32(LOAD32(holder + 4) + 100);
				ctx.r6.u64 = r6;  // state the callee may pass on
				ctx.r7.u64 = r7;
				ctx.r8.u64 = r8;
				ctx.r9.u64 = r9;
				ctx.v1 = targetVector;
				ctx.cr0 = cr0;
				ctx.xer.ca = xer.ca;
				result = n_sub_822358A8(ctx, base, handler, r4, ctx.f1.f64);
				r4 = ctx.r4.u64;
				r5 = ctx.r5.u64;
				r6 = ctx.r6.u64;
				r7 = ctx.r7.u64;
				r8 = ctx.r8.u64;
				r9 = ctx.r9.u64;
				f1 = ctx.f1.f64;
				f13 = ctx.f13.f64;
				readFlagsBack();
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r0.u64 = 0xFFFFFFD0;  // offset of the v127 save slot, left in r0 by the original
	ctx.r1.u64 = stack;
	// callers read these after the call
	ctx.r4.u64 = r4;
	ctx.r5.u64 = r5;
	ctx.r6.u64 = r6;
	ctx.r7.u64 = r7;
	ctx.r8.u64 = r8;
	ctx.r9.u64 = r9;
	ctx.f1.f64 = f1;
	ctx.f13.f64 = f13;
	ctx.cr0 = cr0;
	ctx.xer.ca = xer.ca;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(25, sub_824596B0, 0x824596B0) { ctx.r3.u64 = n_sub_824596B0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.f1.f64); }
