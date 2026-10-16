// CECFlitSwitch (vtable 0x82003208): methods of the class as readable C++.
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

// sub_825337D8  [60 bytes]
uint64_t CECFlitSwitch_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820BD234_B_ = int32_t(0x820BD234);
	if (!UseLiftedCode(32, 0x825337D8)) { ctx.r3.u64 = classNameString; __imp__sub_825337D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825337D8);
	uint32_t stack = ctx.r1.u64;
	uint64_t className = str_TXT_820BD234_B_;
	int32_t length = -1;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, className, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(32, sub_825337D8, 0x825337D8) { ctx.r3.u64 = CECFlitSwitch_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82533DA0(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr, uint64_t destroyFlags) {
	if (!UseLiftedCode(32, 0x82533DA0)) { ctx.r3.u64 = flitSwitchAddr; ctx.r4.u64 = destroyFlags; __imp__sub_82533DA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82533DA0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = destroyFlags;  // state the callee may pass on
	n_sub_82533DF0(ctx, base, flitSwitchAddr);
	// bit 0: also free the object's memory
	if ((destroyFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, flitSwitchAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return flitSwitchAddr;
}
PROMOTED_ENTRY(32, sub_82533DA0, 0x82533DA0) { ctx.r3.u64 = n_sub_82533DA0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82533DF0(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(32, 0x82533DF0)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82533DF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82533DF0);
	uint32_t stack = ctx.r1.u64;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 128);

	// EntityHandle members get their vtable written back before they are released
	const uint32_t entityHandleVtable = uint32_t(g_820F1664);
	// the entries vector at +88: m_5C first, m_60 last; m_64 is cleared with them
	const uint32_t entriesVectorAddr = (uint32_t)flitSwitchAddr + 88;

	ctx.r1.u64 = stack;
	SharedHandle_Release(ctx, base, flitSwitchAddr + 152);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, flitSwitchAddr + 136);

	flitSwitch->m_80 = entityHandleVtable;
	EntityHandle_Release(ctx, base, flitSwitchAddr + 128);
	flitSwitch->m_84 = 0;
	flitSwitch->m_78 = entityHandleVtable;
	EntityHandle_Release(ctx, base, flitSwitchAddr + 120);
	flitSwitch->m_7C = 0;

	SharedHandle_Release(ctx, base, flitSwitchAddr + 104);

	// r4 for the EntityHandle_Release below: zero, or what HandleTarget_Free left in it
	uint64_t r4State = 0;
	uint32_t entriesBegin = flitSwitch->m_5C;
	if (entriesBegin != 0) {
		uint32_t entriesEnd = flitSwitch->m_60;
		ctx.r3.u64 = entriesVectorAddr;  // state the callee may pass on
		n_sub_82538980(ctx, base, entriesBegin, entriesEnd);
		HandleTarget_Free(ctx, base, flitSwitch->m_5C);
		r4State = ctx.r4.u64;
	}
	flitSwitch->m_5C = 0;
	flitSwitch->m_60 = 0;
	flitSwitch->m_64 = 0;

	flitSwitch->m_50 = entityHandleVtable;
	ctx.r4.u64 = r4State;  // state the callee may pass on
	EntityHandle_Release(ctx, base, flitSwitchAddr + 80);
	flitSwitch->m_54 = 0;

	uint32_t result = C_820EFB9C_Destructor(ctx, base, flitSwitchAddr + 56);

	// base-class vtables: C_820A8F74 for the subobject at +12 (address taken with the null check
	// of a pointer cast, so null stays null), C_820A8D10 for the object itself
	uint32_t subobjectAddr = 0;
	if ((uint32_t)flitSwitchAddr != 0) {
		subobjectAddr = (uint32_t)flitSwitchAddr + 12;
	}
	STORE32(subobjectAddr, 0x820A8F74u);
	flitSwitch->vtable = 0x820A8D10u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82533DF0, 0x82533DF0) { ctx.r3.u64 = n_sub_82533DF0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82534948(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	constexpr int32_t str_TXT_820BD448_B_ = int32_t(0x820BD448);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x82534948)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82534948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82534948);
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	const uint32_t entityHandleVtable = uint32_t(g_820F1664);
	const uint64_t fnvOffsetBasis = 0xFFFFFFFF811C9DC5ULL;   // 0x811C9DC5 sign-extended, as the original builds it
	const uint32_t handleBuf = stack + 80;                   // stack scratch: entity handle, lookup output, search range
	const uint64_t sharedHandleAddr = flitSwitchAddr + 152;  // CECFlitSwitch::m_98

	// The shared handle at +152 points to an id: look it up, point the entity handle at +80 at what
	// the lookup returns (through a scratch handle), then release the shared handle.
	uint32_t sharedIdPtr = flitSwitch->m_98;
	if (sharedIdPtr != 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t mapHolder = LOAD32(LOAD32(LOAD32(globalRoot + 12) + 88) + 4);
		// n_sub_82264448 searches the map at +136 of its first argument for the 64-bit id
		uint32_t idMapOwner = LOAD32(mapHolder);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = mapHolder;  // state the callee may pass on
		uint64_t target = n_sub_82264448(ctx, base, idMapOwner, sharedIdPtr);

		STORE32(handleBuf, entityHandleVtable);
		STORE32(handleBuf + 4, 0);
		EntityHandle_SetTarget(ctx, base, handleBuf, target);
		EntityHandle_Assign(ctx, base, flitSwitchAddr + 80, handleBuf);
		STORE32(handleBuf, entityHandleVtable);
		EntityHandle_Release(ctx, base, handleBuf);
		SharedHandle_Release(ctx, base, sharedHandleAddr);
		STORE32((uint32_t)sharedHandleAddr, 0);
	}

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_821D9F40(ctx, base, handleBuf, flitSwitchAddr);
	if (LOAD32(handleBuf) != 0) {
		uint64_t trailHash = String_HashFnv1(ctx, base, str_TXT_820BD448_B_, fnvOffsetBasis);
		ctx.r4.u64 = fnvOffsetBasis;  // state the callee may pass on
		uint64_t idRef = IdRef_Get(ctx, base, handleBuf);
		uint32_t fieldValue = GameDB_FindFieldValue(ctx, base, idRef, trailHash, 6);
		uint32_t TXT_820BD448_L_ = (fieldValue != 0) ? LOAD32(fieldValue) : 0;
		uint64_t trailTarget = n_sub_82537768(ctx, base, flitSwitchAddr, TXT_820BD448_L_);

		STORE32(handleBuf, entityHandleVtable);
		STORE32(handleBuf + 4, 0);
		EntityHandle_SetTarget(ctx, base, handleBuf, trailTarget);
		EntityHandle_Assign(ctx, base, flitSwitchAddr + 120, handleBuf);
		STORE32(handleBuf, entityHandleVtable);
		result = EntityHandle_Release(ctx, base, handleBuf);
	}

	// With the byte at +148 set: find the value for key 23 in the object at m_4 and clear byte +35 of it.
	if (LOAD8((uint32_t)flitSwitchAddr + 148) != 0) {
		uint32_t ownerAddr = flitSwitch->m_4;
		uint32_t entry = 0;
		bool found = false;
		if (((LOAD32(ownerAddr + 36) >> 23) & 1) != 0) {
			uint32_t indexTable = LOAD32(ownerAddr + 140);
			if (indexTable != 0) {
				// byte 23 of the index table is the position of key 23 among the 8-byte entries
				uint32_t index = LOAD8(indexTable + 23);
				uint32_t begin = LOAD32(ownerAddr + 72);
				entry = LOAD32(begin + index * 8 + 4);
				found = true;
			} else {
				// lower_bound of key 23 over the 8-byte (key, value) entries in [begin, end)
				uint32_t begin = LOAD32(ownerAddr + 72);
				uint32_t end = LOAD32(ownerAddr + 76);
				STORE32(handleBuf, 0);
				STORE32(handleBuf + 4, begin);
				int32_t count = (int32_t)(end - begin) >> 3;
				uint32_t pos = begin;
				if (count > 0) {
					do {
						uint32_t half = (uint32_t)count >> 1;
						uint32_t middle = pos + half * 8;
						if ((int32_t)LOAD32(middle) < 23) {
							pos = middle + 8;
							count = count - (int32_t)half - 1;
						} else {
							count = (int32_t)half;
						}
					} while (count > 0);
					STORE32(handleBuf + 4, pos);
				}
				if (pos == end || (int32_t)LOAD32(pos) > 23) {
					entry = LOAD32(end + 4);
				} else {
					STORE64(handleBuf, LOAD64(handleBuf));  // self-copy kept as in the original
					entry = LOAD32(pos + 4);
				}
				found = true;
			}
		}
		if (found && LOAD8(entry + 35) != 0) {
			STORE8(entry + 35, 0);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82534948, 0x82534948) { ctx.r3.u64 = n_sub_82534948(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82534B98(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	if (!UseLiftedCode(32, 0x82534B98)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82534B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82534B98);
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);

	if (flitSwitch->m_8F == 0)
		return flitSwitchAddr;

	int32_t entryIndex = flitSwitch->m_70;
	if (entryIndex < 0)
		return flitSwitchAddr;

	// m_5C..m_60: array of 80-byte entries
	uint32_t entriesStart = flitSwitch->m_5C;
	uint32_t entriesEnd = flitSwitch->m_60;
	int32_t entriesSize = (int32_t)(entriesEnd - entriesStart);
	uint32_t entryCount = (uint32_t)(entriesSize / 80);

	if ((uint32_t)entryIndex >= entryCount)
		return flitSwitchAddr;

	if (flitSwitch->m_94 != 0)
		return flitSwitchAddr;

	// a 64-bit sum as in the original (no 32-bit wrap)
	uint64_t entryAddr = (uint64_t)((uint32_t)entryIndex * 80) + entriesStart;

	ctx.r6.u64 = entryCount;  // state the callee may pass on
	ctx.r8.u64 = entriesStart;
	return n_sub_82536AF0(ctx, base, flitSwitchAddr, entryAddr, 0);
}
PROMOTED_ENTRY(32, sub_82534B98, 0x82534B98) { ctx.r3.u64 = n_sub_82534B98(ctx, base, ctx.r3.u64); }

// sub_82534BF8  [4 bytes]
uint64_t n_sub_82534BF8(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	if (!UseLiftedCode(32, 0x82534BF8)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82534BF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82534BF8);
	return n_sub_82534C00(ctx, base, flitSwitchAddr);
}
PROMOTED_ENTRY(32, sub_82534BF8, 0x82534BF8) { ctx.r3.u64 = n_sub_82534BF8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82534C00(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	if (!UseLiftedCode(32, 0x82534C00)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82534C00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82534C00);
	uint32_t stack = ctx.r1.u64;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = flitSwitchAddr;

	// One of the switch's two entity handles (handleAddr; handleRef is the handle's second word):
	// release the handle when the word handleRef points to is zero; otherwise destroy the entity the
	// handle resolves to when bit 0x40 of that entity's byte at +144 is set.
	auto checkHandle = [&](uint64_t handleAddr, uint32_t handleRef) {
		if (handleRef == 0) return;

		uint32_t target = LOAD32(handleRef);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = target;  // state the callee may pass on
		if (target == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
			return;
		}

		result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		uint32_t destroyBit = LOAD8((uint32_t)result + 144) & 64;
		if (destroyBit == 0) return;

		ctx.r1.u64 = stack;
		ctx.r10.u64 = destroyBit;  // state the callee may pass on
		uint64_t entity = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		result = Entity_DestroyImpl(ctx, base, entity);
	};

	checkHandle(flitSwitchAddr + 120, flitSwitch->m_7C);
	checkHandle(flitSwitchAddr + 128, flitSwitch->m_84);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82534C00, 0x82534C00) { ctx.r3.u64 = n_sub_82534C00(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82534EA0(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	constexpr int32_t TXT_834985C4_G_ = int32_t(0x834985C4);
	if (!UseLiftedCode(32, 0x82534EA0)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82534EA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82534EA0);
	uint32_t stack = ctx.r1.u64;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);

	stack = PushStackFrame(base, stack, 112);
	flitSwitch->m_74 = 0u;
	ctx.r1.u64 = stack;
	n_sub_82536228(ctx, base, flitSwitchAddr, TXT_834985C4_G_);  // Lua_FlitSwitch_SetMesh

	uint64_t result = n_sub_82537410(ctx, base, flitSwitchAddr);
	// r6 and r8 as this function leaves them for its callers: what n_sub_82537410 left,
	// replaced below by the entry count and array start, or by what n_sub_82536F98 left
	uint64_t outR6 = ctx.r6.u64;
	uint64_t outR8 = ctx.r8.u64;

	if (LOAD8((uint32_t)flitSwitchAddr + 143) != 0) {
		int32_t entryIndex = (int32_t)flitSwitch->m_70;
		if (entryIndex >= 0) {
			// m_5C..m_60: array of 80-byte entries
			uint64_t entriesStart = flitSwitch->m_5C;
			uint64_t entriesBytes = (uint64_t)flitSwitch->m_60 - entriesStart;
			int32_t entryCount = (int32_t)entriesBytes / 80;
			outR6 = (uint32_t)entryCount;
			outR8 = entriesStart;
			if (entryIndex < entryCount) {
				uint64_t entryAddr = entriesStart + (uint64_t)((uint32_t)entryIndex * 80u);
				if (LOAD32((uint32_t)entryAddr + 64) != 0) {
					ctx.r8.u64 = entriesStart;  // state the callee may pass on
					result = n_sub_82536F98(ctx, base, entryAddr, outR6, entriesBytes);
					outR6 = ctx.r6.u64;
					outR8 = ctx.r8.u64;
				} else {
					STORE8((uint32_t)entryAddr + 68, uint8_t(1));
				}
				flitSwitch->m_24 = LOAD32((uint32_t)entryAddr + 40);
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = outR6;  // callers read r6 and r8 after the call
	ctx.r8.u64 = outR8;
	return result;
}
PROMOTED_ENTRY(32, sub_82534EA0, 0x82534EA0) { ctx.r3.u64 = n_sub_82534EA0(ctx, base, ctx.r3.u64); }

uint32_t n_sub_82536500(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr, uint64_t nameString) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	if (!UseLiftedCode(33, 0x82536500)) { ctx.r3.u64 = flitSwitchAddr; ctx.r4.u64 = nameString; __imp__sub_82536500(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82536500);
	uint32_t stack = ctx.r1.u64;

	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint64_t handleAddr = flitSwitchAddr + 128;  // EntityHandle at offset 0x80; m_84 is its control block
	const uint32_t idRefAddr = stack + 80;

	// Release the handle when the first word of its control block is 0; otherwise destroy the
	// handle's target when bit 0x40 of the target's byte at +144 is set.
	uint64_t r4AfterGet = nameString;
	uint32_t destroyFlag = 0;
	uint32_t controlBlock = flitSwitch->m_84;
	if (controlBlock != 0) {
		uint32_t blockTarget = LOAD32(controlBlock);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r4.u64 = nameString;
		ctx.r10.u64 = blockTarget;
		if (blockTarget == 0) {
			EntityHandle_Release(ctx, base, handleAddr);
		} else {
			uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			r4AfterGet = ctx.r4.u64;
			destroyFlag = LOAD8(target + 144) & 64;
		}
	}
	if (destroyFlag != 0) {
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r4.u64 = r4AfterGet;
		ctx.r10.u64 = destroyFlag;
		uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		Entity_DestroyImpl(ctx, base, target);
	}

	ctx.r1.u64 = stack;
	uint32_t result = n_sub_821D9F40(ctx, base, idRefAddr, flitSwitchAddr);
	if (LOAD32(idRefAddr) != 0) {
		uint64_t idRef = IdRef_Get(ctx, base, idRefAddr);
		uint64_t dbEntry = GameDB_ReadU32Field(ctx, base, idRef, 0xFFFFFFFF820BD514ull);  // field-name string at 0x820BD514
		result = (uint32_t)dbEntry;
		if (result != 0) {
			// Hash the name's text (0x8209003F when the string has no data) and look it up as a type-6 field.
			uint32_t nameData = LOAD32(nameString);
			uint64_t nameText = (nameData != 0) ? uint64_t(LOAD32(nameData)) : uint64_t(int64_t(g_8209003F));
			uint64_t nameHash = String_HashFnv1(ctx, base, nameText, 0xFFFFFFFF811C9DC5ull);
			uint32_t fieldValueAddr = GameDB_FindFieldValue(ctx, base, dbEntry, nameHash, 6);
			uint32_t fieldValue = (fieldValueAddr != 0) ? LOAD32(fieldValueAddr) : 0;
			result = n_sub_82536628(ctx, base, flitSwitchAddr, fieldValue);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82536500, 0x82536500) { ctx.r3.u64 = n_sub_82536500(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82536628(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr, uint64_t arg2) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(33, 0x82536628)) { ctx.r3.u64 = flitSwitchAddr; ctx.r4.u64 = arg2; __imp__sub_82536628(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82536628);
	uint32_t stack = ctx.r1.u64;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint64_t handleAddr = flitSwitchAddr + 128;  // EntityHandle at offset 0x80; m_84 is its control block
	const uint64_t tempHandleAddr = (uint64_t)stack + 80;
	const uint32_t entityHandleVtable = uint32_t(g_820F1664);

	// Release the handle when the first word of its control block is 0; otherwise destroy the
	// handle's target when bit 0x40 of the target's byte at +144 is set.
	uint64_t r4AfterGet = arg2;
	uint32_t destroyFlag = 0;
	uint32_t controlBlock = flitSwitch->m_84;
	if (controlBlock != 0) {
		uint32_t blockTarget = LOAD32(controlBlock);
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r4.u64 = arg2;
		ctx.r10.u64 = blockTarget;
		if (blockTarget == 0) {
			EntityHandle_Release(ctx, base, handleAddr);
		} else {
			uint32_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			r4AfterGet = ctx.r4.u64;
			destroyFlag = LOAD8(target + 144) & 64;
		}
	}
	if (destroyFlag != 0) {
		ctx.r1.u64 = stack;
		// state the callee may pass on
		ctx.r4.u64 = r4AfterGet;
		ctx.r10.u64 = destroyFlag;
		uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		Entity_DestroyImpl(ctx, base, target);
	}

	// Point a temporary EntityHandle on the stack at the new target, copy it into the switch's
	// handle, then reset its vtable and release it.
	ctx.r1.u64 = stack;
	uint64_t newTarget = n_sub_82537768(ctx, base, flitSwitchAddr, arg2);
	STORE32(stack + 84, 0);
	STORE32(stack + 80, entityHandleVtable);
	ctx.r10.s64 = g_820F1664;  // state the callee may pass on
	EntityHandle_SetTarget(ctx, base, tempHandleAddr, newTarget);
	EntityHandle_Assign(ctx, base, handleAddr, tempHandleAddr);
	STORE32(stack + 80, entityHandleVtable);
	// state the callee may pass on
	ctx.r8.u64 = entityHandleVtable;
	ctx.r9.u64 = uint32_t(g_820F0000);
	EntityHandle_Release(ctx, base, tempHandleAddr);
	uint8_t carry = ctx.xer.ca;

	// When bit 27 of the owner's (m_4) word at +44 is set, find the value stored under key 91: through
	// the slot table at +140 if there is one, else by a lower-bound search of the sorted {key, value}
	// pairs at +72..+76 (when the key is missing, the value slot just past the end, end + 4, is read).
	// That value and arg2 go to n_sub_82388FD8, whose result is returned.
	uint32_t owner = flitSwitch->m_4;
	uint32_t result = 0;
	if ((LOAD32(owner + 44) >> 27) & 1) {
		uint32_t entry91;
		uint32_t slotTable = LOAD32(owner + 140);
		if (slotTable != 0) {
			entry91 = LOAD32(LOAD8(slotTable + 91) * 8 + LOAD32(owner + 72) + 4);
		} else {
			uint32_t begin = LOAD32(owner + 72);
			uint32_t end = LOAD32(owner + 76);
			STORE32(stack + 80, 0);
			uint32_t byteSpan = end - begin;
			STORE32(stack + 84, begin);
			// carry as the original's arithmetic shift leaves it (the halvings in the loop shift positive
			// counts and leave it 0)
			carry = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
			int32_t count = (int32_t)byteSpan >> 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t mid = begin + (uint32_t(half) << 3);
					if ((int32_t)LOAD32(mid) < 91) {
						begin = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entry91 = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entry91 = LOAD32(end + 4);
			}
		}
		ctx.xer.ca = carry;  // state the callee may pass on
		result = n_sub_82388FD8(ctx, base, entry91, arg2);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(33, sub_82536628, 0x82536628) { ctx.r3.u64 = n_sub_82536628(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82537120(CpuState& ctx, uint8_t* base, uint32_t flitSwitchAddr) {
	constexpr int32_t str_TXT_820BCDBC_B_ = int32_t(0x820BCDBC);
	constexpr int32_t g_820C0000 = int32_t(0x820C0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(33, 0x82537120)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82537120(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82537120);
	uint32_t stack = ctx.r1.u64;
	// r6, r8, cr0 and the carry as the original leaves them for its callees and callers
	uint64_t r6Out = ctx.r6.u64;
	uint64_t r8Out = ctx.r8.u64;
	PPCCRRegister cr0Out = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 272);

	// Value stored under `key` in the owner's map: through the slot table at +140 if there is one,
	// else by a lower-bound search of the sorted {key, value} pairs at +72..+76 (when the key is
	// missing, the value slot just past the end, end + 4, is read). The search updates r6, r8, cr0
	// and the carry the way the original does.
	auto lookup = [&](uint32_t owner, int32_t key) -> uint32_t {
		uint32_t slotTable = LOAD32(owner + 140);
		if (slotTable != 0) {
			return LOAD32(LOAD8(slotTable + key) * 8 + LOAD32(owner + 72) + 4);
		}
		uint32_t begin = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		r6Out = end;
		STORE32(stack + 80, 0);
		uint32_t byteSpan = end - begin;
		STORE32(stack + 84, begin);
		// the halvings in the loop shift positive counts and leave the carry 0
		flags.ca = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
		int32_t count = (int32_t)byteSpan >> 3;
		cr0Out.compare<int32_t>(count, 0, flags);
		if (count > 0) {
			do {
				int32_t half = count >> 1;
				uint32_t halfBytes = uint32_t(half) << 3;
				r8Out = halfBytes;
				uint32_t mid = begin + halfBytes;
				if ((int32_t)LOAD32(mid) < key) {
					begin = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, begin);
		}
		if (begin != end && (int32_t)LOAD32(begin) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	uint32_t result = flitSwitchAddr;  // returned unchanged when m_92 is already set
	if (flitSwitch->m_92 == 0) {
		uint32_t owner = flitSwitch->m_4;
		if ((LOAD32(owner + 40) >> 17) & 1) {
			uint32_t entry49 = lookup(owner, 49);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r6.u64 = r6Out;
			ctx.r8.u64 = r8Out;
			ctx.cr0 = cr0Out;
			ctx.xer.ca = flags.ca;
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820BCDBC_B_, -1);
			n_sub_827F05D0(ctx, base, stack + 112, 2, stack + 80, 0);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			const int64_t holderVtable = (int64_t)g_820C0000 - 10248;
			STORE32(stack + 112, (uint32_t)holderVtable);

			// Virtual call through slot 16 (+64) of entry49's vtable with (stack + 88, entry49,
			// the object at stack + 112, 0); r7-r10 hold what the original leaves in them.
			uint32_t entryVtable = LOAD32(entry49);
			uint32_t method = LOAD32(entryVtable + 64);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r3.u64 = stack + 88;
			ctx.r4.u64 = entry49;
			ctx.r5.u64 = stack + 112;
			ctx.r6.u64 = 0;
			ctx.r7.u64 = method;
			ctx.r8.u64 = entryVtable;
			ctx.r9.u64 = (uint64_t)holderVtable;
			ctx.r10.s64 = g_820C0000;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			// The call's r3 buffer at stack + 88 is an EntityHandle: reset its vtable, release it and
			// clear its second word.
			const uint32_t entityHandleVtable = uint32_t(g_820F0000 + 5732);
			STORE32(stack + 88, entityHandleVtable);
			// state the callee may pass on
			ctx.r5.u64 = entityHandleVtable;
			ctx.r6.s64 = g_820F0000;
			EntityHandle_Release(ctx, base, stack + 88);
			STORE32(stack + 92, 0);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 196);
			HandleHolder_Dtor(ctx, base, stack + 112);
			r6Out = ctx.r6.u64;
			cr0Out = ctx.cr0;
			flags.ca = ctx.xer.ca;
		}

		uint32_t owner2 = flitSwitch->m_4;
		result = 0;
		flitSwitch->m_92 = 1;
		const uint32_t hasKey91 = (LOAD32(owner2 + 44) >> 27) & 1;
		r8Out = hasKey91;
		if (hasKey91 != 0) {
			uint32_t entry91 = lookup(owner2, 91);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r6.u64 = r6Out;
			ctx.r8.u64 = r8Out;
			ctx.cr0 = cr0Out;
			ctx.xer.ca = flags.ca;
			result = n_sub_82388EB0(ctx, base, entry91, 1);
			r6Out = ctx.r6.u64;
			r8Out = ctx.r8.u64;
			cr0Out = ctx.cr0;
			flags.ca = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	// callers read r6, r8, cr0 and the carry after the call
	ctx.r6.u64 = r6Out;
	ctx.r8.u64 = r8Out;
	ctx.cr0 = cr0Out;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(33, sub_82537120, 0x82537120) { ctx.r3.u64 = n_sub_82537120(ctx, base, ctx.r3.u32); }

uint64_t n_sub_82537410(CpuState& ctx, uint8_t* base, uint64_t flitSwitchAddr) {
	constexpr int32_t str_TXT_820BCE3C_B_ = int32_t(0x820BCE3C);
	constexpr int32_t g_820C0000 = int32_t(0x820C0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	if (!UseLiftedCode(33, 0x82537410)) { ctx.r3.u64 = flitSwitchAddr; __imp__sub_82537410(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82537410);
	uint32_t stack = ctx.r1.u64;
	CECFlitSwitch* flitSwitch = GameObject<CECFlitSwitch>(base, flitSwitchAddr);
	stack = PushStackFrame(base, stack, 272);

	const uint64_t handleAddr = flitSwitchAddr + 128;  // EntityHandle at offset 0x80; m_84 is its control block

	// Release the handle when the first word of its control block is 0; otherwise destroy the
	// handle's target when bit 0x40 of the target's byte at +144 is set. When m_92 is clear the
	// function returns the argument or the result of the last of these calls.
	uint64_t result = flitSwitchAddr;
	uint32_t destroyFlag = 0;
	uint32_t controlBlock = flitSwitch->m_84;
	if (controlBlock != 0) {
		uint32_t blockTarget = LOAD32(controlBlock);
		ctx.r1.u64 = stack;
		ctx.r10.u64 = blockTarget;  // state the callee may pass on
		if (blockTarget == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			destroyFlag = LOAD8(result + 144) & 64;
		}
	}
	if (destroyFlag != 0) {
		ctx.r1.u64 = stack;
		ctx.r10.u64 = destroyFlag;  // state the callee may pass on
		uint64_t target = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		result = Entity_DestroyImpl(ctx, base, target);
	}
	// r6 (handed to the first string call below) and the carry (handed to later calls and left for
	// callers) as the calls above left them
	uint64_t r6Out = ctx.r6.u64;
	uint8_t carry = ctx.xer.ca;

	// Value stored under `key` in the owner's map: through the slot table at +140 if there is one,
	// else by a lower-bound search of the sorted {key, value} pairs at +72..+76 (when the key is
	// missing, the value slot just past the end, end + 4, is read). The search sets the carry the
	// way the original does and, when `endOut` is given, stores the array's end there (the original
	// keeps it in r6 for the first lookup only).
	auto lookup = [&](uint32_t owner, int32_t key, uint64_t* endOut) -> uint32_t {
		uint32_t slotTable = LOAD32(owner + 140);
		if (slotTable != 0) {
			return LOAD32(LOAD8(slotTable + key) * 8 + LOAD32(owner + 72) + 4);
		}
		uint32_t begin = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		if (endOut != nullptr) *endOut = end;
		STORE32(stack + 80, 0);
		uint32_t byteSpan = end - begin;
		STORE32(stack + 84, begin);
		// the halvings in the loop shift positive counts and leave the carry 0
		carry = (int32_t)byteSpan < 0 && (byteSpan & 0x7) != 0;
		int32_t count = (int32_t)byteSpan >> 3;
		if (count > 0) {
			do {
				int32_t half = count >> 1;
				uint32_t mid = begin + (uint32_t(half) << 3);
				if ((int32_t)LOAD32(mid) < key) {
					begin = mid + 8;
					count = count - half - 1;
				} else {
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, begin);
		}
		if (begin != end && (int32_t)LOAD32(begin) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	if (flitSwitch->m_92 != 0) {
		uint32_t owner = flitSwitch->m_4;
		if ((LOAD32(owner + 40) >> 17) & 1) {
			uint32_t entry49 = lookup(owner, 49, &r6Out);
			ctx.r1.u64 = stack;
			// state the callee may pass on
			ctx.r6.u64 = r6Out;
			ctx.xer.ca = carry;
			CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820BCE3C_B_, -1);
			n_sub_827F05D0(ctx, base, stack + 112, 4, stack + 80, 0);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
			const int64_t holderVtable = (int64_t)g_820C0000 - 10168;
			STORE32(stack + 112, (uint32_t)holderVtable);

			// Virtual call through slot 16 (+64) of entry49's vtable with (stack + 88, entry49,
			// the object at stack + 112, 0); r7-r10 hold what the original leaves in them.
			uint32_t entryVtable = LOAD32(entry49);
			uint32_t method = LOAD32(entryVtable + 64);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r3.u64 = stack + 88;
			ctx.r4.u64 = entry49;
			ctx.r5.u64 = stack + 112;
			ctx.r6.u64 = 0;
			ctx.r7.u64 = method;
			ctx.r8.u64 = entryVtable;
			ctx.r9.u64 = (uint64_t)holderVtable;
			ctx.r10.s64 = g_820C0000;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			// The call's r3 buffer at stack + 88 is an EntityHandle: reset its vtable, release it and
			// clear its second word.
			const uint32_t entityHandleVtable = uint32_t(g_820F0000 + 5732);
			STORE32(stack + 88, entityHandleVtable);
			// state the callee may pass on
			ctx.r5.u64 = entityHandleVtable;
			ctx.r6.u64 = uint32_t(g_820F0000);
			EntityHandle_Release(ctx, base, stack + 88);
			STORE32(stack + 92, 0);
			CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 196);
			HandleHolder_Dtor(ctx, base, stack + 112);
			carry = ctx.xer.ca;
		}

		uint32_t owner2 = flitSwitch->m_4;
		result = 0;
		flitSwitch->m_92 = 0;
		if ((LOAD32(owner2 + 44) >> 27) & 1) {
			uint32_t entry91 = lookup(owner2, 91, nullptr);
			ctx.r1.u64 = stack;
			ctx.xer.ca = carry;  // state the callee may pass on
			result = n_sub_82388EB0(ctx, base, entry91, 0);
			carry = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 272);
	ctx.r1.u64 = stack;
	ctx.xer.ca = carry;  // callers read the carry after the call
	return result;
}
PROMOTED_ENTRY(33, sub_82537410, 0x82537410) { ctx.r3.u64 = n_sub_82537410(ctx, base, ctx.r3.u64); }
