// CECDoor (vtable 0x82003D98): methods of the class as readable C++.
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

uint64_t n_sub_8219DBD0(CpuState& ctx, uint8_t* base, uint64_t doorAddr, uint64_t targetEntity) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(1, 0x8219DBD0)) { ctx.r3.u64 = doorAddr; ctx.r4.u64 = targetEntity; __imp__sub_8219DBD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8219DBD0);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	// Values left in r4 and r8 for callers; the handle calls below replace them.
	uint64_t callerR4 = targetEntity;
	uint64_t callerR8 = ctx.r8.u64;

	stack = PushStackFrame(base, stack, 128);
	STORE32(stack + 80, 0);

	// Only a non-null target with flag 0x40 set in its byte at +144 is looked up in the door's handle list
	// (entries m_50..m_54); a target found there makes the result 0.
	bool targetValid = (uint32_t)targetEntity != 0
	                && (LOAD8((uint32_t)targetEntity + 144) & 64) != 0;

	bool targetInList = false;
	if (targetValid) {
		STORE32(stack + 84, 0);
		STORE32(stack + 80, (uint32_t)g_820F1664);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);

		uint32_t listEnd = door->m_54;
		uint32_t foundIterator = EntityHandleList_Find(ctx, base, stack + 88, doorAddr + 76, stack + 80);
		uint32_t foundPosition = LOAD32(foundIterator + 4);
		targetInList = foundPosition != listEnd;

		STORE32(stack + 80, (uint32_t)g_820F1664);
		// state the callee may pass on; r4 still holds what the lookup left
		ctx.r1.u64 = stack;
		EntityHandle_Release(ctx, base, stack + 80);
		callerR4 = ctx.r4.u64;
		callerR8 = ctx.r8.u64;
	}

	uint32_t transitioning = targetInList ? 0 : door->m_24;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4 and r8 after the call
	ctx.r4.u64 = callerR4;
	ctx.r8.u64 = callerR8;
	return transitioning;
}
PROMOTED_ENTRY(1, sub_8219DBD0, 0x8219DBD0) { ctx.r3.u64 = n_sub_8219DBD0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_822D0940 = Lua_Door_SetLocked (Lua Door.SetLocked)  [388 bytes]
uint64_t n_sub_822D0940(CpuState& ctx, uint8_t* base, uint64_t doorObject, uint64_t isLocked) {
	constexpr int32_t g_820A43E8 = int32_t(0x820A43E8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(13, 0x822D0940)) { ctx.r3.u64 = doorObject; ctx.r4.u64 = isLocked; __imp__sub_822D0940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D0940);
	uint32_t stack = ctx.r1.u64;
	// Values the original leaves in r4, r7, r8 and r9 for callers; it also uses r7-r9 as scratch below.
	uint64_t callerR4 = isLocked;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = ctx.r8.u64;
	uint64_t reg9 = 0;
	PPCXERRegister flags = ctx.xer;

	stack = PushStackFrame(base, stack, 112);

	uint32_t doorEntity = LOAD32((uint32_t)doorObject + 4);
	STORE8((uint32_t)doorObject + 33, (uint8_t)isLocked);

	uint32_t entryObject = 0;
	bool found = false;
	reg9 = (LOAD32(doorEntity + 44) >> 27) & 1;
	if (reg9 != 0) {
		found = true;
		uint32_t slotTable = LOAD32(doorEntity + 140);
		if (slotTable != 0) {
			// The table caches the slot index for key 91: entry = begin + 8 * index (64-bit sum, as in r9).
			reg9 = (uint64_t)((uint32_t)LOAD8(slotTable + 91) << 3) + LOAD32(doorEntity + 72);
			entryObject = LOAD32((uint32_t)reg9 + 4);
		} else {
			// lower_bound over the 8-byte {key, object} entries of [begin, end) searching for key 91.
			uint32_t begin = LOAD32(doorEntity + 72);
			uint32_t end = LOAD32(doorEntity + 76);
			STORE32(stack + 80, 0u);
			reg9 = (uint64_t)end - begin;
			STORE32(stack + 84, begin);
			flags.ca = ((int32_t)reg9 < 0) & ((reg9 & 7) != 0);
			int32_t count = (int32_t)reg9 >> 3;
			if (count > 0) {
				do {
					flags.ca = (count < 0) & ((count & 1) != 0);
					int32_t step = count >> 1;
					reg9 = step;
					reg8 = (uint32_t)step << 3;
					begin += (uint32_t)reg8;
					bool keyBelow = (int32_t)LOAD32(begin) < 91;
					reg7 = keyBelow ? 1 : 0;
					if (keyBelow) {
						count -= step + 1;
						begin += 8;
					} else {
						begin -= (uint32_t)reg8;
						count = step;
					}
				} while (count > 0);
				STORE32(stack + 84, begin);
			}
			if (begin != end && (int32_t)LOAD32(begin) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entryObject = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entryObject = LOAD32(end + 4);
			}
		}
	}

	uint64_t result = doorObject;
	if (found) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, entryObject);
		reg9 = ctx.r9.u64;
		if (((uint32_t)result & 0xFF) != 0) {
			STORE8(stack + 84, (uint8_t)isLocked);
			uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
			STORE32(stack + 80, (uint32_t)g_820A43E8);
			uint32_t rootChild = LOAD32(globalRoot + 12);
			uint32_t messageTarget = LOAD32(rootChild + 140);
			// state the callee may pass on
			uint64_t uniqueId = Entity_GetUniqueId(ctx, base, doorEntity);
			flags.ca = ctx.xer.ca;
			result = Entity_PostFlagMessage(ctx, base, messageTarget, (uint64_t)stack + 80, uniqueId);
			callerR4 = ctx.r4.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			reg9 = ctx.r9.u64;
			flags.ca = ctx.xer.ca;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4, r7, r8, r9 and the carry after the call
	ctx.r4.u64 = callerR4;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = reg9;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(13, sub_822D0940, 0x822D0940) { ctx.r3.u64 = n_sub_822D0940(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_825279B8  [60 bytes]
uint64_t CECDoor_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameOut) {
	constexpr int32_t str_TXT_820BCD10_B_ = int32_t(0x820BCD10);
	if (!UseLiftedCode(32, 0x825279B8)) { ctx.r3.u64 = classNameOut; __imp__sub_825279B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825279B8);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameOut, str_TXT_820BCD10_B_, -1);
	return classNameOut;
}
PROMOTED_ENTRY(32, sub_825279B8, 0x825279B8) { ctx.r3.u64 = CECDoor_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82527A40(CpuState& ctx, uint8_t* base, uint64_t door, uint64_t deleteFlags) {
	if (!UseLiftedCode(32, 0x82527A40)) { ctx.r3.u64 = door; ctx.r4.u64 = deleteFlags; __imp__sub_82527A40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82527A40);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	n_sub_82527A90(ctx, base, door);
	// Bit 0 also frees the door object itself.
	if (deleteFlags & 0x1) {
		HandleTarget_Free(ctx, base, door);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return door;
}
PROMOTED_ENTRY(32, sub_82527A40, 0x82527A40) { ctx.r3.u64 = n_sub_82527A40(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t n_sub_82527A90(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	if (!UseLiftedCode(32, 0x82527A90)) { ctx.r3.u64 = doorAddr; __imp__sub_82527A90(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82527A90);
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	// r13 supplies the MSR bits (0x8020) set while the reference count is reserved below.
	const uint32_t msrFromR13 = ctx.r13.u32;

	GameStackFrame stackFrame(ctx, base, 112);

	SharedHandle_Release(ctx, base, doorAddr + 104);
	C_820EFB9C_Destructor(ctx, base, doorAddr + 92);

	// The handle range [m_50, m_54) of the block at +76 is released, its storage freed and the block's
	// three words after +76 cleared.
	uint32_t rangeBlock = (uint32_t)(doorAddr + 76);
	uint32_t rangeBegin = door->m_50;
	// Value r4 carries into later calls; the release calls replace it.
	uint64_t reg4 = rangeBegin;
	if (rangeBegin != 0) {
		uint32_t rangeEnd = LOAD32(rangeBlock + 8);
		// state the callee may pass on
		HandleRange_ReleaseAll(ctx, base, rangeBegin, rangeEnd);
		HandleTarget_Free(ctx, base, LOAD32(rangeBlock + 4));
		reg4 = ctx.r4.u64;
	}
	STORE32(rangeBlock + 4, 0);
	STORE32(rangeBlock + 8, 0);
	STORE32(rangeBlock + 12, 0);

	uint32_t refCounted = door->m_48;
	if (refCounted != 0) {
		// Atomic decrement of the reference count at +4 (lwarx/stwcx. under the global lock).
		uint64_t refCountAddr = (uint64_t)refCounted + 4;
		uint32_t newCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t lockState = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = msrFromR13 & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)refCountAddr);
			newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)refCountAddr)), ctx.reserved.s32, __builtin_bswap32(newCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		if (newCount == 0) {
			uint32_t destroyFn = LOAD32(LOAD32(refCounted) + 4);
			// state the callee may pass on
			ctx.r3.u64 = refCounted;
			ctx.r4.u64 = reg4;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = destroyFn;
			REX_CALL_INDIRECT_FUNC(destroyFn);
			reg4 = ctx.r4.u64;
		}
		door->m_48 = 0;
	}

	// state the callee may pass on
	SharedHandle_Release(ctx, base, doorAddr + 64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, doorAddr + 56);

	// The subobject at +28 gets the C_820A8F74 vtable back (the store goes to address 0 for a null door).
	uint32_t vtableSlot = (uint32_t)doorAddr != 0 ? (uint32_t)(doorAddr + 28) : 0;
	STORE32(vtableSlot, 0x820A8F74u);

	return CECVaultable_Dtor(ctx, base, (uint32_t)doorAddr);
}
PROMOTED_ENTRY(32, sub_82527A90, 0x82527A90) { ctx.r3.u64 = n_sub_82527A90(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82528A20(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x82528A20)) { ctx.r3.u64 = doorAddr; __imp__sub_82528A20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82528A20);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 128);

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_82392C88(ctx, base, door->m_4, doorAddr);
	// Value r4 carries into the final release; the calls below replace it.
	uint64_t reg4 = ctx.r4.u64;

	// m_68 points to a list of 8-byte entries (begin at +4, end at +8). Every entry that resolves to an
	// entity with flag 0x40 set at +144 is handed to n_sub_82529BE8; the list is released afterwards.
	uint64_t listFieldAddr = doorAddr + 104;
	uint32_t list = door->m_68;
	if (list != 0) {
		uint64_t listBytes = (uint64_t)LOAD32(list + 8) - (uint64_t)LOAD32(list + 4);
		flags.ca = ((int32_t)listBytes < 0) & (((uint32_t)listBytes & 7) != 0);
		uint64_t entryCount = (int32_t)listBytes >> 3;  // sign-extended, as it is handed over in r7
		if ((int32_t)entryCount != 0) {
			uint32_t index = 0;
			uint64_t byteOffset = 0;
			do {
				uint32_t globalRoot = LOAD32((uint32_t)g_83490000 + 26912);
				uint64_t entryAddr = (uint64_t)LOAD32(list + 4) + byteOffset;
				uint32_t container = LOAD32(LOAD32(globalRoot + 12) + 88);
				uint32_t containerFirst = LOAD32(LOAD32(container + 4));
				// state the callee may pass on
				ctx.xer.ca = flags.ca;
				uint64_t entity = n_sub_82264448(ctx, base, containerFirst, entryAddr);
				reg4 = entity;

				if ((uint32_t)entity != 0) {
					uint32_t entityFlag = LOAD8((uint32_t)entity + 144) & 64;
					if (entityFlag != 0) {
						ctx.r10.u64 = entityFlag;  // state the callee may pass on
						n_sub_82529BE8(ctx, base, doorAddr, entity, 1);  // Lua_Door_SetOpenForEntity
						reg4 = ctx.r4.u64;
					}
				}

				list = LOAD32((uint32_t)listFieldAddr);
				++index;
				byteOffset += 8;
				listBytes = (uint64_t)LOAD32(list + 8) - (uint64_t)LOAD32(list + 4);
				flags.ca = ((int32_t)listBytes < 0) & (((uint32_t)listBytes & 7) != 0);
				entryCount = (int32_t)listBytes >> 3;
			} while (index < (uint32_t)entryCount);
		}
		// state the callee may pass on
		ctx.xer.ca = flags.ca;
		result = SharedHandle_Release(ctx, base, listFieldAddr);
		STORE32((uint32_t)listFieldAddr, 0u);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82528A20, 0x82528A20) { ctx.r3.u64 = n_sub_82528A20(ctx, base, ctx.r3.u64); }

uint64_t Door_SetOpenImpl(CpuState& ctx, uint8_t* base, uint32_t doorAddr, uint64_t reg8) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x82528B08)) { ctx.r3.u64 = doorAddr; ctx.r8.u64 = reg8; __imp__sub_82528B08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82528B08);
	uint32_t stack = ctx.r1.u64;
	// r13 supplies the MSR bits (0x8020) set while the reference count is reserved below.
	const uint32_t msrFromR13 = ctx.r13.u32;
	// r6, r7 and r8 (reg8) are handed to later calls; the lookup below and several callees change them.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 208);

	// Evaluate the curve at m_40 with the float it holds at +40, then call its virtual at +28.
	uint32_t curve = door->m_40;
	if (curve != 0) {
		ctx.fpscr.disableFlushMode();
		double curvePosition = double(LOAD_F32(curve + 40));
		// state the callee may pass on
		ctx.r1.u64 = stack;
		Curve_EvaluateLinear(ctx, base, curve, curvePosition);
		uint32_t curveFn = LOAD32(LOAD32(curve) + 28);
		// state the callee may pass on
		ctx.r3.u64 = curve;
		ctx.r10.u64 = curveFn;
		REX_CALL_INDIRECT_FUNC(curveFn);
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;
	}

	// Find the value stored with key 6 in the 8-byte {key, value} entries at entity +72..+76.
	uint32_t entity = door->m_4;
	uint32_t component = 0;
	bool hasComponent = false;
	if (((LOAD32(entity + 36) >> 6) & 1) != 0) {
		hasComponent = true;
		uint32_t slotTable = LOAD32(entity + 140);
		if (slotTable != 0) {
			// The table caches the slot index for key 6.
			uint32_t slotOffset = (uint32_t)LOAD8(slotTable + 6) << 3;
			component = LOAD32(LOAD32(entity + 72) + slotOffset + 4);
		} else {
			// lower_bound(begin, end, 6); a missing key yields the word after the end.
			uint32_t entry = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			reg6 = end;
			STORE32(stack + 96, 0);
			STORE32(stack + 100, entry);
			int32_t count = (int32_t)(end - entry) >> 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					reg8 = halfBytes;
					entry += halfBytes;
					bool keyBelow = (int32_t)LOAD32(entry) < 6;
					reg7 = keyBelow ? 1 : 0;
					if (keyBelow) {
						count -= half + 1;
						entry += 8;
					} else {
						entry -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 100, entry);
			}
			if (entry != end && (int32_t)LOAD32(entry) <= 6) {
				STORE64(stack + 96, LOAD64(stack + 96));
				component = LOAD32(LOAD32(stack + 100) + 4);
			} else {
				component = LOAD32(end + 4);
			}
		}
	}

	if (hasComponent) {
		// stack + 128 holds a temporary list of 48-byte entries (begin at +132, end at +136) that
		// n_sub_821719D0 builds and the end of this block frees.
		uint32_t componentData = LOAD32(component + 148);
		uint64_t sourceBytes = (uint64_t)LOAD32(componentData + 48) - (uint64_t)LOAD32(componentData + 44);
		flags.ca = ((int32_t)sourceBytes < 0) & (((uint32_t)sourceBytes & 7) != 0);
		uint64_t sourceCount = (int32_t)sourceBytes >> 3;  // sign-extended, as the original passes it
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		n_sub_821719D0(ctx, base, stack + 128, sourceCount, reg8);
		flags.ca = ctx.xer.ca;

		uint32_t listEnd = LOAD32(stack + 136);
		uint32_t floatConsts = uint32_t(g_820994C0);
		ctx.fpscr.disableFlushMode();
		double pairSecond = double(LOAD_F32(floatConsts - 396));
		STORE_F32(stack + 112, LOAD_F32(floatConsts - 392));
		STORE_F32(stack + 116, float(pairSecond));
		uint64_t listBegin = LOAD32(stack + 132);
		uint64_t listBytes = (uint64_t)listEnd - listBegin;
		uint32_t listCount = uint32_t((int32_t)listBytes / 48);
		compare0.compare<int32_t>((int32_t)listCount, 0, flags);
		if ((int32_t)listCount == 0) listBegin = (uint64_t)stack + 128;

		// state the callee may pass on
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		uint32_t sharedSlot = n_sub_8225FB20(ctx, base, (uint64_t)stack + 104, door->m_40);
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;

		ctx.fpscr.disableFlushMode();
		double floatArg = double(LOAD_F32(floatConsts));
		uint32_t sharedObject = LOAD32(sharedSlot);
		STORE32(stack + 92, 0);
		STORE32(stack + 84, 0);
		n_sub_82208178(ctx, base, sharedObject, componentData, 3, listBegin, 0, 0, stack + 112, floatArg);
		reg8 = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;

		// Release the reference held at stack + 104: atomic decrement of its count at +4, virtual +4 at zero.
		uint32_t heldRef = LOAD32(stack + 104);
		if (heldRef != 0) {
			reg8 = (uint64_t)heldRef + 4;
			uint64_t lockState;
			uint32_t newCount;
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				lockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = msrFromR13 & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)reg8);
				newCount = __builtin_bswap32(ctx.reserved.u32) - 1;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)reg8)), ctx.reserved.s32, __builtin_bswap32(newCount));
				compare0.so = flags.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)lockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
			if (newCount == 0) {
				uint32_t destroyFn = LOAD32(LOAD32(heldRef) + 4);
				// state the callee may pass on
				ctx.r3.u64 = heldRef;
				ctx.r8.u64 = reg8;
				ctx.r9.u64 = lockState;
				ctx.r10.u64 = destroyFn;
				ctx.cr0.lt = compare0.lt;
				ctx.cr0.gt = compare0.gt;
				ctx.cr0.eq = compare0.eq;
				ctx.cr0.so = compare0.so;
				REX_CALL_INDIRECT_FUNC(destroyFn);
				reg8 = ctx.r8.u64;
				compare0.lt = ctx.cr0.lt;
				compare0.gt = ctx.cr0.gt;
				compare0.eq = ctx.cr0.eq;
				compare0.so = ctx.cr0.so;
				flags.ca = ctx.xer.ca;
			}
			STORE32(stack + 104, 0);
		}

		// state the callee may pass on
		ctx.r8.u64 = reg8;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		n_sub_8254F4E8(ctx, base, component, stack + 128);
		reg6 = ctx.r6.u64;
		reg7 = ctx.r7.u64;
		reg8 = ctx.r8.u64;
		flags.ca = ctx.xer.ca;

		uint32_t listStorage = LOAD32(stack + 132);
		if (listStorage != 0) {
			HandleTarget_Free(ctx, base, listStorage);
			reg6 = ctx.r6.u64;
			reg7 = ctx.r7.u64;
			reg8 = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
		}
		STORE32(stack + 132, 0);
		STORE32(stack + 136, 0);
		STORE32(stack + 140, 0);
	}

	// Virtual +92 of the object at m_4 + 124 returns the object handed to Door_FindActiveComponent.
	uint32_t subObject = LOAD32(uint32_t(door->m_4) + 124);
	uint32_t subVtable = LOAD32(subObject);
	uint32_t getActiveFn = LOAD32(subVtable + 92);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = subObject;
	ctx.r6.u64 = reg6;
	ctx.r7.u64 = reg7;
	ctx.r8.u64 = reg8;
	ctx.r9.u64 = getActiveFn;
	ctx.r10.u64 = subVtable;
	ctx.xer.ca = flags.ca;
	REX_CALL_INDIRECT_FUNC(getActiveFn);
	uint64_t active = ctx.r3.u64;
	if ((uint32_t)active != 0) {
		STORE32(stack + 96, 0);
		uint32_t foundActive = Door_FindActiveComponent(ctx, base, (uint32_t)active, stack + 96);
		bool useBoneDrivers = door->m_20 != 0;
		if ((foundActive & 0xFF) != 0) {
			uint32_t activeComponent = LOAD32(stack + 96);
			if (useBoneDrivers) {
				uint64_t result = CBoneDriverGroup_ResetAllDrivers(ctx, base, activeComponent);
				stack = PopStackFrame(stack, 208);
				ctx.r1.u64 = stack;
				return result;
			}
			uint32_t componentFn = LOAD32(LOAD32(activeComponent) + 84);
			// state the callee may pass on
			ctx.r3.u64 = activeComponent;
			ctx.r4.u64 = 1;
			ctx.r10.u64 = componentFn;
			REX_CALL_INDIRECT_FUNC(componentFn);
		} else if (useBoneDrivers) {
			uint32_t activeFn56 = LOAD32(LOAD32((uint32_t)active) + 56);
			// state the callee may pass on
			ctx.r3.u64 = active;
			ctx.r10.u64 = activeFn56;
			REX_CALL_INDIRECT_FUNC(activeFn56);
		} else {
			uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
			uint32_t activeVtable = LOAD32((uint32_t)active);
			uint32_t activeFn60 = LOAD32(activeVtable + 60);
			uint32_t rootChild = LOAD32(globalRoot + 12);
			uint32_t container = LOAD32(rootChild + 88);
			uint32_t containerFirst = LOAD32(container + 4);
			uint32_t containerValue = LOAD32(containerFirst + 24);
			// state the callee may pass on
			ctx.r3.u64 = active;
			ctx.r4.u64 = containerValue;
			ctx.r6.u64 = containerFirst;
			ctx.r7.u64 = container;
			ctx.r8.u64 = rootChild;
			ctx.r9.u64 = activeFn60;
			ctx.r10.u64 = activeVtable;
			REX_CALL_INDIRECT_FUNC(activeFn60);
		}
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(32, sub_82528B08, 0x82528B08) { ctx.r3.u64 = Door_SetOpenImpl(ctx, base, ctx.r3.u32, ctx.r8.u64); }

uint64_t n_sub_82528E30(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	if (!UseLiftedCode(32, 0x82528E30)) { ctx.r3.u64 = doorAddr; __imp__sub_82528E30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82528E30);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	// r6, r7, r8 and the carry as the first lookup leaves them; they are handed to Door_IsLockedForPlayer_Impl.
	uint64_t reg6 = ctx.r6.u64;
	uint64_t reg7 = ctx.r7.u64;
	uint64_t reg8 = 0;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 112);

	// Value stored with `key` in the 8-byte {key, value} entries at owner+72..+76: through the slot-index
	// table at owner+140 when present, else by lower_bound (iterator kept at stack + 84); a missing key
	// yields the word after the end.
	auto lookup = [&](uint32_t owner, int32_t key) -> uint32_t {
		uint32_t slotTable = LOAD32(owner + 140);
		if (slotTable != 0) {
			uint32_t slotOffset = (uint32_t)LOAD8(slotTable + key) << 3;
			return LOAD32(LOAD32(owner + 72) + slotOffset + 4);
		}
		uint32_t entry = LOAD32(owner + 72);
		uint32_t end = LOAD32(owner + 76);
		reg6 = end;
		STORE32(stack + 80, 0);
		STORE32(stack + 84, entry);
		uint32_t bytes = end - entry;
		flags.ca = ((int32_t)bytes < 0) & ((bytes & 7) != 0);
		int32_t count = (int32_t)bytes >> 3;
		if (count > 0) {
			do {
				flags.ca = (count < 0) & ((count & 1) != 0);
				int32_t half = count >> 1;
				uint32_t halfBytes = (uint32_t)half << 3;
				reg8 = halfBytes;
				entry += halfBytes;
				bool keyBelow = (int32_t)LOAD32(entry) < key;
				reg7 = keyBelow ? 1 : 0;
				if (keyBelow) {
					count -= half + 1;
					entry += 8;
				} else {
					entry -= halfBytes;
					count = half;
				}
			} while (count > 0);
			STORE32(stack + 84, entry);
		}
		if (entry != end && (int32_t)LOAD32(entry) <= key) {
			STORE64(stack + 80, LOAD64(stack + 80));
			return LOAD32(LOAD32(stack + 84) + 4);
		}
		return LOAD32(end + 4);
	};

	uint32_t entity = door->m_4;
	uint64_t result = 1;
	uint32_t key91Flag = (LOAD32(entity + 44) >> 27) & 1;
	reg8 = key91Flag;
	if (key91Flag != 0) {
		uint32_t key91Value = lookup(entity, 91);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, key91Value);
	}

	if ((result & 0xFF) != 0 && LOAD8((uint32_t)doorAddr + 42) == 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = Door_IsLockedForPlayer_Impl(ctx, base, doorAddr);
		if ((result & 0xFF) == 0) {
			Door_SetOpenState(ctx, base, doorAddr, 0, 1, 0);
			result = n_sub_822D0940(ctx, base, doorAddr, 1);  // Lua_Door_SetLocked
			if (LOAD8((uint32_t)doorAddr + 42) == 0) {
				entity = door->m_4;
				if ((LOAD32(entity + 36) >> 23) & 1) {
					uint32_t key23Value = lookup(entity, 23);
					if (LOAD8(key23Value + 35) != 0) STORE8(key23Value + 35, 0);
				}
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_82528E30, 0x82528E30) { ctx.r3.u64 = n_sub_82528E30(ctx, base, ctx.r3.u64); }

// sub_82529BE8 = Lua_Door_SetOpenForEntity (Lua Door.SetOpenForEntity)  [716 bytes]
uint64_t n_sub_82529BE8(CpuState& ctx, uint8_t* base, uint64_t doorAddr, uint64_t targetEntity, uint64_t shouldOpenArg) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(32, 0x82529BE8)) { ctx.r3.u64 = doorAddr; ctx.r4.u64 = targetEntity; ctx.r5.u64 = shouldOpenArg; __imp__sub_82529BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82529BE8);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 176);

	// stack+80: the entity handle built for each list operation. EntityHandleList_Find fills stack+88 and
	// returns a result whose word at +4 is the position found: the end of the list (door->m_54) when the
	// target is not in it.
	const uint32_t handleVtable = uint32_t(g_820F1664);  // EntityHandle vtable, word 0 of the handle at stack+80
	const uint32_t shouldOpen = uint32_t(shouldOpenArg) & 0xFF;
	STORE32(stack + 80, 0);

	// Opening: is the target missing from the door's handle list (door+76)?
	bool openForUnlisted = false;
	if (shouldOpen != 0) {
		STORE32(stack + 80, handleVtable);
		STORE32(stack + 84, 0);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r5.u64 = shouldOpenArg;
		EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);
		uint32_t listEnd = door->m_54;
		uint32_t searchResult = (uint32_t)EntityHandleList_Find(ctx, base, stack + 88, doorAddr + 76, stack + 80);
		openForUnlisted = LOAD32(searchResult + 4) == listEnd;
		STORE32(stack + 80, handleVtable);
		// state the callee may pass on (r4/r5 stay as the search left them)
		ctx.r1.u64 = stack;
		ctx.r9.u64 = 1;
		ctx.r10.u64 = openForUnlisted;
		EntityHandle_Release(ctx, base, stack + 80);
	}

	uint32_t openFlag = 0;
	bool listChanged = false;

	if (openForUnlisted) {
		// add the target to the list
		STORE32(stack + 80, handleVtable);
		STORE32(stack + 84, 0);
		ctx.r1.u64 = stack;
		EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);
		Vector8_PushBack(ctx, base, doorAddr + 76, stack + 80);
		STORE32(stack + 80, handleVtable);
		EntityHandle_Release(ctx, base, stack + 80);

		// The target's component of type 153 (flagged by bit 25 of +52): indexed through its component
		// table at +140, or found by a lower_bound search over its sorted (type, component) pairs at +72..+76.
		bool hasComponent = false;
		uint32_t component = 0;
		if (((LOAD32(uint32_t(targetEntity) + 52) >> 25) & 1) != 0) {
			hasComponent = true;
			uint32_t componentTable = LOAD32(uint32_t(targetEntity) + 140);
			if (componentTable != 0) {
				uint32_t pairOffset = (uint32_t)LOAD8(componentTable + 153) << 3;
				component = LOAD32(pairOffset + LOAD32(uint32_t(targetEntity) + 72) + 4);
			} else {
				uint32_t begin = LOAD32(uint32_t(targetEntity) + 72);
				uint32_t end = LOAD32(uint32_t(targetEntity) + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, begin);
				uint32_t byteSpan = end - begin;
				int32_t pairCount = (int32_t)byteSpan >> 3;
				uint8_t carry = (int32_t)byteSpan < 0 && (byteSpan & 7) != 0;  // CA of the shift
				uint32_t cursor = begin;
				if (pairCount > 0) {
					bool below = false;
					uint32_t halfBytes = 0;
					do {
						int32_t half = pairCount >> 1;
						halfBytes = (uint32_t)half << 3;
						cursor += halfBytes;
						below = (int32_t)LOAD32(cursor) < 153;
						if (below) {
							cursor += 8;
							pairCount = pairCount - half - 1;
						} else {
							cursor -= halfBytes;
							pairCount = half;
						}
					} while (pairCount > 0);
					STORE32(stack + 84, cursor);
					// r7/r8 as the last search step leaves them; the step's shift clears CA
					ctx.r7.u64 = below;
					ctx.r8.u64 = halfBytes;
					carry = 0;
				}
				// state Door_PostSetOpenForEntity may pass on
				ctx.r6.u64 = end;
				ctx.xer.ca = carry;

				uint32_t pair = end;
				if (cursor != end && (int32_t)LOAD32(cursor) <= 153) {
					STORE64(stack + 80, LOAD64(stack + 80));
					pair = LOAD32(stack + 84);
				}
				component = LOAD32(pair + 4);
			}
		}
		if (hasComponent) {
			uint32_t doorEntity = door->m_4;
			ctx.r1.u64 = stack;
			Door_PostSetOpenForEntity(ctx, base, component, doorEntity, 0);
		}
		openFlag = 1;
		listChanged = true;
	} else {
		// Closing: is the target in the list?
		bool closeForListed = false;
		if (shouldOpen == 0) {
			STORE32(stack + 80, handleVtable);
			STORE32(stack + 84, 0);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r5.u64 = shouldOpenArg;
			ctx.r9.u64 = 0;
			ctx.r10.u64 = 0;
			EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);
			uint32_t listEnd = door->m_54;
			uint32_t searchResult = (uint32_t)EntityHandleList_Find(ctx, base, stack + 88, doorAddr + 76, stack + 80);
			closeForListed = LOAD32(searchResult + 4) != listEnd;
			STORE32(stack + 80, handleVtable);
			// state the callee may pass on (r4, r5 and r9 stay as the search left them)
			ctx.r1.u64 = stack;
			ctx.r10.u64 = 2;
			EntityHandle_Release(ctx, base, stack + 80);
		}
		if (closeForListed) {
			// remove the target from the list at the position the search finds
			STORE32(stack + 80, handleVtable);
			STORE32(stack + 84, 0);
			ctx.r1.u64 = stack;
			EntityHandle_SetTarget(ctx, base, stack + 80, targetEntity);
			uint32_t searchResult = (uint32_t)EntityHandleList_Find(ctx, base, stack + 88, doorAddr + 76, stack + 80);
			HandleRange_PopBack(ctx, base, stack + 96, doorAddr + 76, LOAD64(searchResult));
			STORE32(stack + 80, handleVtable);
			EntityHandle_Release(ctx, base, stack + 80);
			openFlag = 0;
			listChanged = true;
		}
	}

	if (listChanged) {
		ctx.r1.u64 = stack;
		Door_SetOpenForEntity_Impl(ctx, base, doorAddr, targetEntity, openFlag);
	}

	ctx.r1.u64 = stack;
	uint64_t canOpenForEntity = CECDoor_CanOpenForEntity(ctx, base, doorAddr, targetEntity);
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return canOpenForEntity;
}
PROMOTED_ENTRY(32, sub_82529BE8, 0x82529BE8) { ctx.r3.u64 = n_sub_82529BE8(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t Door_IsLockedForPlayer_Impl(CpuState& ctx, uint8_t* base, uint32_t doorObject) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x8252A288)) { ctx.r3.u64 = doorObject; __imp__sub_8252A288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252A288);
	uint32_t stack = ctx.r1.u64;
	// r6-r9 and CA as callers see them after the call; written back at the return
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	uint64_t r9Value = ctx.r9.u64;
	uint8_t carry = ctx.xer.ca;
	stack = PushStackFrame(base, stack, 96);

	uint32_t isLocked = 1;

	if (LOAD8(doorObject + 0x27) == 0) {
		uint32_t globalRoot = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t handleContainer = LOAD32(LOAD32(globalRoot + 12) + 88);
		uint32_t handleArray = LOAD32(handleContainer + 4);
		uint32_t firstHandle = LOAD32(handleArray);

		// state the callee may pass on
		ctx.r1.u64 = stack;
		uint32_t playerEntity = (uint32_t)EntityHandle_Get(ctx, base, firstHandle);
		r6Value = ctx.r6.u64;
		r7Value = ctx.r7.u64;
		r8Value = ctx.r8.u64;
		r9Value = ctx.r9.u64;
		carry = ctx.xer.ca;

		// The lock state comes from the player's component of type 122, looked up only when the player
		// carries entity flag 0x40 and bit 26 of its +0x30 word (the component is present).
		if (playerEntity != 0) {
			r9Value = LOAD8(playerEntity + 0x90) & 0x40;
			if (r9Value != 0) {
				r9Value = (LOAD32(playerEntity + 0x30) >> 26) & 1;
				if (r9Value != 0) {
					uint32_t component;
					uint32_t componentTable = LOAD32(playerEntity + 0x8C);
					if (componentTable != 0) {
						// direct index: the table gives the pair's slot in the (type, component) array at +0x48
						r9Value = ((uint64_t)LOAD8(componentTable + 0x7A) << 3) + LOAD32(playerEntity + 0x48);
						component = LOAD32((uint32_t)r9Value + 4);
					} else {
						// lower_bound for type 122 over the sorted (type, component) pairs at +0x48..+0x4C
						uint32_t first = LOAD32(playerEntity + 0x48);
						uint32_t last = LOAD32(playerEntity + 0x4C);
						STORE32(stack + 80, 0);
						r8Value = (uint64_t)last - first;
						STORE32(stack + 84, first);
						r6Value = last;
						r9Value = 0;
						carry = (int32_t)r8Value < 0 && (r8Value & 7) != 0;  // CA of the shift
						int32_t count = (int32_t)r8Value >> 3;
						if (count > 0) {
							do {
								int32_t half = count >> 1;
								uint32_t halfOffset = (uint32_t)half << 3;
								uint32_t mid = first + halfOffset;
								bool below = (int32_t)LOAD32(mid) < 122;
								if (below) {
									count = count - half - 1;
									first = mid + 8;
								} else {
									first = mid - halfOffset;
									count = half;
								}
								// the last step's values stay in r7-r9
								r7Value = below;
								r8Value = halfOffset;
								r9Value = (uint32_t)half;
							} while (count > 0);
							carry = 0;  // the step's shift of a positive count
							STORE32(stack + 84, first);
						}

						if (first == last || (int32_t)LOAD32(first) > 122) {
							component = LOAD32(last + 4);
						} else {
							STORE64(stack + 80, LOAD64(stack + 80));
							component = LOAD32(LOAD32(stack + 84) + 4);
						}
					}

					uint32_t lockState = (uint32_t)n_sub_821C2C18(ctx, base, component);
					isLocked = ((int32_t)lockState < 2) ? 0 : 1;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r6-r9 and CA after the call
	ctx.r6.u64 = r6Value;
	ctx.r7.u64 = r7Value;
	ctx.r8.u64 = r8Value;
	ctx.r9.u64 = r9Value;
	ctx.xer.ca = carry;
	return isLocked;
}
PROMOTED_ENTRY(32, sub_8252A288, 0x8252A288) { ctx.r3.u64 = Door_IsLockedForPlayer_Impl(ctx, base, ctx.r3.u32); }

// sub_8252AC50  [236 bytes]
uint32_t Door_SetOpenForEntity_Impl(CpuState& ctx, uint8_t* base, uint32_t doorAddr, uint64_t targetEntity, uint64_t openFlag) {
	constexpr int32_t g_820A43DC = int32_t(0x820A43DC);
	if (!UseLiftedCode(32, 0x8252AC50)) { ctx.r3.u64 = doorAddr; ctx.r4.u64 = targetEntity; ctx.r5.u64 = openFlag; __imp__sub_8252AC50(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8252AC50);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t globalRoot = LOAD32(0x83496920u);
	uint32_t messageQueue = LOAD32(LOAD32(globalRoot + 12) + 140);
	if (LOAD8(messageQueue + 52) == 0 || LOAD8(messageQueue + 53) == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		// callers read r4/r5 after the call
		ctx.r4.u64 = targetEntity;
		ctx.r5.u64 = openFlag;
		return doorAddr;
	}

	// Message at stack+80: word g_820A43DC, the open flag, door bytes m_28 and m_21, and at +88 the
	// unique id of the target (0 unless the target is an entity carrying flag 0x40).
	uint8_t doorByte28 = door->m_28;
	uint8_t doorByte21 = door->m_21;
	STORE8(stack + 84, (uint8_t)openFlag);
	STORE64(stack + 88, 0);
	STORE32(stack + 80, uint32_t(g_820A43DC));
	STORE8(stack + 85, doorByte28);
	STORE8(stack + 86, doorByte21);

	// state the Entity_GetUniqueId calls may pass on: set for the first call, the second gets what it left
	ctx.r7.u64 = (uint64_t)(int64_t)g_820A43DC;
	ctx.r8.u64 = 0;
	if ((uint32_t)targetEntity != 0 && (LOAD8((uint32_t)targetEntity + 144) & 0x40) != 0) {
		ctx.r1.u64 = stack;
		uint64_t targetId = Entity_GetUniqueId(ctx, base, targetEntity);
		STORE64(stack + 88, targetId);
	}

	uint32_t doorEntity = door->m_4;
	messageQueue = LOAD32(LOAD32(globalRoot + 12) + 140);
	ctx.r1.u64 = stack;
	uint64_t doorEntityId = Entity_GetUniqueId(ctx, base, doorEntity);
	uint32_t result = Door_PostSetOpenMessage(ctx, base, messageQueue, (uint64_t)stack + 80, doorEntityId);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;  // r4/r5 stay as Door_PostSetOpenMessage left them
}
PROMOTED_ENTRY(32, sub_8252AC50, 0x8252AC50) { ctx.r3.u64 = Door_SetOpenForEntity_Impl(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

// sub_8252AE08  [300 bytes]
// Callers pass a CCharString in r4 (stringAddr), a vector in v1 and a float in f1 that is added to the
// vector's third lane (zOffset).
uint32_t n_sub_8252AE08(CpuState& ctx, uint8_t* base, uint64_t stringAddr, double zOffset) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x8252AE08)) { ctx.r4.u64 = stringAddr; ctx.f1.f64 = zOffset; __imp__sub_8252AE08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8252AE08);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;

	PPCVRegister inputVector = ctx.v1;
	PPCVRegister permMask{};
	PPCVRegister raisedZVector{};
	PPCVRegister raisedVector{};
	PPCVRegister lane0{};
	PPCVRegister lane1{};
	PPCVRegister lane1Again{};
	PPCVRegister constantVector{};
	PPCRegister callTarget{};

	// v127 is saved below the frame like the original does (nothing here changes it)
	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 224);

	// stack+96: the input vector, later the constant vector; stack+80: the raised z, then the reference
	// handed to n_sub_821F5B90 and the constructor and released at the end.
	const uint32_t vectorSlot = stack + 96;
	const uint32_t refSlot = stack + 80;
	const int32_t dataAnchor = g_820A0000;
	const int32_t globals = g_83490000;
	const uint64_t permMaskAddr = (int64_t)dataAnchor - 28176;

	VSTORE(vectorSlot & ~0xF, V8(inputVector));
	ctx.fpscr.disableFlushMode();
	double raisedZ = double(float(double(LOAD_F32(stack + 104)) + zOffset));
	STORE_F32(stack + 80, float(raisedZ));

	// the input vector with bytes taken from the raised z, as the mask at permMaskAddr selects
	SET_V8(permMask, VLOAD((uint32_t)permMaskAddr & ~0xF));
	scratch.u32 = refSlot;
	SET_V8(raisedZVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
	                                            simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	const uint64_t callData = (int64_t)globals + 30564;
	SET_V8(raisedVector, rex::ppc::simde_mm_perm_epi8_(V8(inputVector), V8(raisedZVector), V8(permMask)));

	uint32_t target = LOAD32(LOAD32(LOAD32(uint32_t(globals) + 26912) + 12) + 96);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r6.s64 = globals;
	ctx.r7.u64 = permMaskAddr;
	ctx.r8.u64 = refSlot;
	ctx.r9.s64 = dataAnchor;
	ctx.r10.u64 = vectorSlot;
	ctx.f1.f64 = zOffset;
	ctx.f13.f64 = raisedZ;
	ctx.v13 = raisedZVector;
	n_sub_821F5B90(ctx, base, refSlot, target, callData);

	// the float at 0x820994C0 in stack+84 and +88, gathered into a vector at stack+96
	const uint32_t constantSlot = stack + 84;
	ctx.fpscr.disableFlushMode();
	double constant = double(LOAD_F32(0x820994C0u));
	STORE_F32(stack + 84, float(constant));
	scratch.u32 = stack + 84;
	SET_V8(lane0, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
	                                    simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE_F32(stack + 88, float(constant));
	scratch.u32 = stack + 88;
	SET_V8(lane1, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
	                                    simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	STORE_F32(stack + 88, float(constant));
	STORE_F32(stack + 84, float(constant));
	SET_VF(lane1, simde_mm_blend_ps(VF(lane1), simde_mm_permute_ps(VF(lane0), 57), 4));
	scratch.u32 = stack + 88;
	SET_V8(lane1Again, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
	                                         simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	scratch.u32 = constantSlot;
	SET_V8(constantVector, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)),
	                                             simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
	SET_VF(constantVector, simde_mm_blend_ps(VF(constantVector), simde_mm_permute_ps(VF(lane1Again), 57), 4));
	SET_VF(constantVector, simde_mm_blend_ps(VF(constantVector), simde_mm_permute_ps(VF(lane1), 78), 3));
	VSTORE(vectorSlot & ~0xF, V8(constantVector));

	// v1: the raised vector; r7, v9-v12: state the callee may pass on
	ctx.r7.u64 = constantSlot;
	ctx.v1 = raisedVector;
	ctx.v9 = constantVector;
	ctx.v10 = lane1Again;
	ctx.v11 = lane1;
	ctx.v12 = lane0;
	C_820A6754_Constructor(ctx, base, stack + 112, 4, refSlot, stringAddr, vectorSlot, constant);

	// virtual function at vtable offset 20 of the object at g_83490000+26912
	uint32_t manager = LOAD32(uint32_t(globals) + 26912);
	uint32_t managerVtable = LOAD32(manager);
	uint32_t method = LOAD32(managerVtable + 20);
	callTarget.u64 = method;
	// r3: the object; r5/r6: state the callee may pass on
	ctx.r3.u64 = manager;
	ctx.r5.u64 = method;
	ctx.r6.u64 = managerVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t callResult = ctx.r3.u32;

	uint32_t inner = LOAD32(LOAD32(callResult + 4));
	n_sub_821DDE30(ctx, base, stack + 112, inner, 1);

	// tear down the C_820A6754 object built at stack+112: members at +36 and +32 released, vtable set back
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 148);
	RefCountedPtr_ReleaseAtomic(ctx, base, stack + 144);
	STORE32(stack + 112, 0x820A6754u);
	uint32_t released = RefCountedPtr_ReleaseAtomic(ctx, base, refSlot);

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	// callers read r0 after the call
	ctx.r0.u64 = 0xFFFFFFD0;
	return released;
}
PROMOTED_ENTRY(32, sub_8252AE08, 0x8252AE08) { ctx.r3.u64 = n_sub_8252AE08(ctx, base, ctx.r4.u64, ctx.f1.f64); }

// sub_8252AF38  [612 bytes]
uint64_t n_sub_8252AF38(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	constexpr int32_t g_8209B4E0 = int32_t(0x8209B4E0);
	constexpr int32_t g_820BCE44 = int32_t(0x820BCE44);
	constexpr int32_t g_820BCE50 = int32_t(0x820BCE50);
	constexpr int32_t g_820BCE68 = int32_t(0x820BCE68);
	constexpr int32_t g_820BCE78 = int32_t(0x820BCE78);
	constexpr int32_t g_820BCE8C = int32_t(0x820BCE8C);
	if (!UseLiftedCode(32, 0x8252AF38)) { ctx.r3.u64 = doorAddr; __imp__sub_8252AF38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252AF38);
	PPCVRegister savedV127 = ctx.v127;  // restored on return: the first n_sub_8252AE08 call gets v1 in v127
	const PPCVRegister inputVector = ctx.v1;  // handed on in v1 to every n_sub_8252AE08 call
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	const uint32_t floatTable = uint32_t(g_8209B4E0);

	VSTORE((stack + 0xFFFFFFD0u) & ~0xF, V8(savedV127));
	stack = PushStackFrame(base, stack, 144);

	// Strings are built in turn at stack+80 and handed to n_sub_8252AE08 with floats from g_8209B4E0: one
	// chosen by the open state, one chosen by door->m_21 and, when the door's entity has a component of
	// type 64, the narrow string at +128 of the entity it refers to (or a fixed string).
	ctx.r1.u64 = stack;
	uint32_t isOpen = (uint32_t)Door_IsOpenForEntity(ctx, base, doorAddr, 0);
	CCharString_AssignFromWideStr(ctx, base, stack + 80, (isOpen & 0xFF) ? g_820BCE44 : g_820BCE50);
	ctx.fpscr.disableFlushMode();
	double zOffset = double(LOAD_F32(floatTable + 3688));
	// state the callee may pass on
	ctx.v1 = inputVector;
	ctx.v127 = inputVector;
	n_sub_8252AE08(ctx, base, stack + 80, zOffset);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 80);

	CCharString_AssignFromWideStr(ctx, base, stack + 80, door->m_21 ? g_820BCE68 : g_820BCE78);
	ctx.fpscr.disableFlushMode();
	zOffset = double(LOAD_F32(floatTable + 17056));
	// state the callee may pass on
	ctx.v1 = inputVector;
	n_sub_8252AE08(ctx, base, stack + 80, zOffset);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 80);

	// Component of type 64 of the door's entity (door->m_4), present when bit 0 of its +44 word is set:
	// indexed through its component table at +140, or found by a lower_bound search over its sorted
	// (type, component) pairs at +72..+76.
	uint64_t result = 0;
	uint32_t doorEntity = door->m_4;
	if ((LOAD32(doorEntity + 44) & 1) != 0) {
		uint32_t component;
		uint32_t componentTable = LOAD32(doorEntity + 140);
		if (componentTable != 0) {
			uint64_t pairAddr = ((uint64_t)LOAD8(componentTable + 64) << 3) + LOAD32(doorEntity + 72);
			component = LOAD32((uint32_t)pairAddr + 4);
			// state the callee may pass on (r6-r8 and CA stay as the last release left them)
			ctx.r9.u64 = pairAddr;
		} else {
			uint32_t begin = LOAD32(doorEntity + 72);
			uint32_t end = LOAD32(doorEntity + 76);
			STORE32(stack + 80, 0);
			uint64_t byteSpan = (uint64_t)end - begin;
			STORE32(stack + 84, begin);
			uint8_t carry = (int32_t)byteSpan < 0 && (byteSpan & 7) != 0;  // CA of the shift
			int32_t pairCount = (int32_t)byteSpan >> 3;
			// r7-r9 as the search leaves them: the last step's comparison, step bytes and step count
			uint64_t lastBelow = ctx.r7.u64;
			uint64_t lastStepBytes = byteSpan;
			uint64_t lastStep = 0;
			uint32_t cursor = begin;
			if (pairCount > 0) {
				do {
					int32_t half = pairCount >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					cursor += halfBytes;
					bool below = (int32_t)LOAD32(cursor) < 64;
					if (below) {
						pairCount = pairCount - half - 1;
						cursor += 8;
					} else {
						cursor -= halfBytes;
						pairCount = half;
					}
					lastBelow = below;
					lastStepBytes = halfBytes;
					lastStep = (uint32_t)half;
				} while (pairCount > 0);
				carry = 0;  // the step's shift of a positive count
				STORE32(stack + 84, cursor);
			}
			if (cursor != end && (int32_t)LOAD32(cursor) <= 64) {
				STORE64(stack + 80, LOAD64(stack + 80));
				component = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				component = LOAD32(end + 4);
			}
			// state the callee may pass on
			ctx.r6.u64 = end;
			ctx.r7.u64 = lastBelow;
			ctx.r8.u64 = lastStepBytes;
			ctx.r9.u64 = lastStep;
			ctx.xer.ca = carry;
		}

		uint32_t entity = (uint32_t)EntityHandle_GetEntity(ctx, base, component);
		if (entity != 0 && (LOAD8(entity + 144) & 0x40) != 0) {
			WideString_ConstructFromNarrow(ctx, base, stack + 80, entity + 128);
		} else {
			CCharString_AssignFromWideStr(ctx, base, stack + 80, g_820BCE8C);
		}
		ctx.fpscr.disableFlushMode();
		zOffset = double(LOAD_F32(floatTable));
		// state the callee may pass on
		ctx.v1 = inputVector;
		n_sub_8252AE08(ctx, base, stack + 80, zOffset);
		result = CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 80);
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r0 after the call; v127 gets back its value from the entry
	ctx.r0.u64 = 0xFFFFFFD0;
	ctx.v127 = savedV127;
	return result;
}
PROMOTED_ENTRY(32, sub_8252AF38, 0x8252AF38) { ctx.r3.u64 = n_sub_8252AF38(ctx, base, ctx.r3.u64); }

// sub_8252B420  [628 bytes]
// When the byte at 0x83496A79 is set and the door's entity has a component of type 23 (bit 23 of its +36
// word): the position (vtable offset 64 of the object at +124) of the entity behind the first handle, and
// then of the owner SpellShot_GetOwner gives for that handle, is compared with the door entity's position;
// within the squared distance at 0x82099320, n_sub_8252AF38 runs with that position in v1.
uint64_t n_sub_8252B420(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(32, 0x8252B420)) { ctx.r3.u64 = doorAddr; __imp__sub_8252B420(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252B420);
	uint32_t stack = ctx.r1.u64;
	const uint32_t globals = uint32_t(g_83490000);
	PPCVRegister otherPos{};
	PPCVRegister doorPos{};
	PPCVRegister offset{};
	PPCVRegister distanceSq{};
	PPCRegister callTarget{};
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 240);

	uint64_t result = doorAddr;
	if (LOAD8(0x83496A79u) != 0) {
		uint32_t doorEntity = door->m_4;
		if (((LOAD32(doorEntity + 36) >> 23) & 1) != 0) {
			// r7/r8 and CA for EntityHandle_Get: as on entry, or as the search below leaves them
			uint64_t r7Value = ctx.r7.u64;
			uint64_t r8Value = ctx.r8.u64;
			uint8_t carry = ctx.xer.ca;
			if (LOAD32(doorEntity + 140) == 0) {
				// lower_bound for type 23 over the sorted (type, component) pairs at +72..+76; only the
				// registers it leaves are used
				uint32_t cursor = LOAD32(doorEntity + 72);
				uint32_t end = LOAD32(doorEntity + 76);
				uint32_t byteSpan = end - cursor;
				int32_t pairCount = (int32_t)byteSpan >> 3;
				carry = ((int32_t)byteSpan < 0) && ((byteSpan & 7) != 0);  // CA of the shift
				if (pairCount > 0) {
					do {
						int32_t half = pairCount >> 1;
						uint32_t halfBytes = (uint32_t)half << 3;
						uint32_t mid = cursor + halfBytes;
						bool below = (int32_t)LOAD32(mid) < 23;
						if (below) {
							pairCount = pairCount - half - 1;
							cursor = mid + 8;
						} else {
							pairCount = half;
						}
						r7Value = below;
						r8Value = halfBytes;
					} while (pairCount > 0);
					carry = 0;  // the step's shift of a positive count
				}
			}

			uint32_t world = LOAD32(LOAD32(globals + 26912) + 12);
			uint32_t handleArray = LOAD32(LOAD32(world + 88) + 4);
			uint32_t firstHandle = LOAD32(handleArray);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.xer.ca = carry;
			uint32_t entity = (uint32_t)EntityHandle_Get(ctx, base, firstHandle);

			bool entityValid = entity != 0 && (LOAD8(entity + 144) & 0x40) != 0;
			ctx.fpscr.disableFlushMode();
			double rangeSq = double(LOAD_F32(0x82099320u));

			if (entityValid) {
				uint32_t entityPosSource = LOAD32(entity + 124);
				uint32_t getEntityPos = LOAD32(LOAD32(entityPosSource) + 64);
				callTarget.u64 = getEntityPos;
				// r3/r4: the output and the object; r9/r10: state the callee may pass on
				ctx.r10.u64 = getEntityPos;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				uint32_t doorEntityNow = door->m_4;
				uint32_t doorPosSource = LOAD32(doorEntityNow + 124);
				uint32_t doorPosVtable = LOAD32(doorPosSource);
				uint32_t getDoorPos = LOAD32(doorPosVtable + 64);
				callTarget.u64 = getDoorPos;
				// r3/r4: the output and the object; r7-r9: state the callee may pass on
				ctx.r3.u64 = stack + 96;
				ctx.r4.u64 = doorPosSource;
				ctx.r7.u64 = getDoorPos;
				ctx.r8.u64 = doorPosVtable;
				ctx.r9.u64 = doorEntityNow;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				SET_V8(otherPos, VLOAD((stack + 80) & ~0xF));
				SET_V8(doorPos, VLOAD((stack + 96) & ~0xF));
				ctx.fpscr.enableFlushMode();
				SET_VF(offset, simde_mm_sub_ps(VF(otherPos), VF(doorPos)));
				SET_VF(distanceSq, simde_mm_dp_ps(VF(offset), VF(offset), 0xEF));
				VSTORE((stack + 112) & ~0xF, V8(distanceSq));
				ctx.fpscr.disableFlushModeUnconditional();
				if (double(LOAD_F32(stack + 112)) < rangeSq) {
					uint32_t entityPosSource2 = LOAD32(entity + 124);
					uint32_t getEntityPos2 = LOAD32(LOAD32(entityPosSource2) + 64);
					callTarget.u64 = getEntityPos2;
					// r3/r4: the output and the object; r5, r6, r10, v11-v13: state the callee may pass on
					ctx.r3.u64 = stack + 128;
					ctx.v11 = distanceSq;
					ctx.v12 = offset;
					ctx.v13 = doorPos;
					REX_CALL_INDIRECT_FUNC(callTarget.u32);
					// v1: the position just fetched; r9: state the callee may pass on
					SET_V8(ctx.v1, VLOAD((stack + 128) & ~0xF));
					n_sub_8252AF38(ctx, base, doorAddr);
				} else {
					// state SpellShot_GetOwner below may pass on
					ctx.r4.u64 = stack + 112;
					ctx.r5.u64 = stack + 96;
					ctx.r6.u64 = stack + 80;
					ctx.v11 = distanceSq;
					ctx.v12 = offset;
					ctx.v13 = doorPos;
				}
			}

			uint32_t world2 = LOAD32(LOAD32(globals + 26912) + 12);
			uint32_t handleArray2 = LOAD32(LOAD32(world2 + 88) + 4);
			uint32_t firstHandle2 = LOAD32(handleArray2);
			// state the callee may pass on (r4-r6 and v11-v13 as set above or as the last call left them)
			result = SpellShot_GetOwner(ctx, base, firstHandle2);

			uint32_t owner = (uint32_t)result;
			if (owner != 0 && (LOAD8(owner + 144) & 0x40) != 0) {
				uint32_t ownerPosSource = LOAD32(owner + 124);
				uint32_t getOwnerPos = LOAD32(LOAD32(ownerPosSource) + 64);
				callTarget.u64 = getOwnerPos;
				// r3/r4: the output and the object; r10: state the callee may pass on
				ctx.r10.u64 = getOwnerPos;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				uint32_t doorEntityNow = door->m_4;
				uint32_t doorPosSource = LOAD32(doorEntityNow + 124);
				uint32_t doorPosVtable = LOAD32(doorPosSource);
				uint32_t getDoorPos = LOAD32(doorPosVtable + 64);
				callTarget.u64 = getDoorPos;
				// r3/r4: the output and the object; r7-r9: state the callee may pass on
				ctx.r3.u64 = stack + 160;
				ctx.r4.u64 = doorPosSource;
				ctx.r7.u64 = getDoorPos;
				ctx.r8.u64 = doorPosVtable;
				ctx.r9.u64 = doorEntityNow;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				result = ctx.r3.u64;

				const uint32_t distanceSlot = stack + 112;
				SET_V8(otherPos, VLOAD((stack + 144) & ~0xF));
				SET_V8(doorPos, VLOAD((stack + 160) & ~0xF));
				ctx.fpscr.enableFlushMode();
				SET_VF(offset, simde_mm_sub_ps(VF(otherPos), VF(doorPos)));
				SET_VF(distanceSq, simde_mm_dp_ps(VF(offset), VF(offset), 0xEF));
				VSTORE(distanceSlot & ~0xF, V8(distanceSq));
				ctx.fpscr.disableFlushModeUnconditional();
				if (!(double(LOAD_F32(distanceSlot)) < rangeSq)) {
					stack = PopStackFrame(stack, 240);
					ctx.r1.u64 = stack;
					// callers read r4 after the call
					ctx.r4.u64 = distanceSlot;
					return result;
				}

				uint32_t ownerPosSource2 = LOAD32(owner + 124);
				uint32_t getOwnerPos2 = LOAD32(LOAD32(ownerPosSource2) + 64);
				callTarget.u64 = getOwnerPos2;
				// r3/r4: the output and the object; r5, r6, r10, v11-v13: state the callee may pass on
				ctx.r3.u64 = stack + 176;
				ctx.v11 = distanceSq;
				ctx.v12 = offset;
				ctx.v13 = doorPos;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				// v1: the position just fetched; r9: state the callee may pass on
				SET_V8(ctx.v1, VLOAD((stack + 176) & ~0xF));
				result = n_sub_8252AF38(ctx, base, doorAddr);
			}
		}
	}

	stack = PopStackFrame(stack, 240);
	ctx.r1.u64 = stack;
	return result;  // r4 stays as the last call left it (or as on entry)
}
PROMOTED_ENTRY(32, sub_8252B420, 0x8252B420) { ctx.r3.u64 = n_sub_8252B420(ctx, base, ctx.r3.u64); }

// The outline handle in door->m_3C is -1 when unset; a set one is passed to n_sub_8263A788 with 4 and
// cleared, and that call's result is returned (otherwise the unset handle).
uint64_t Lua_Door_RemoveOutlineForLineFiring(CpuState& ctx, uint8_t* base, uint32_t doorAddr) {
	if (!UseLiftedCode(32, 0x8252B6D8)) { ctx.r3.u64 = doorAddr; __imp__sub_8252B6D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252B6D8);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 96);
	const uint64_t outlineHandle = door->m_3C;
	uint64_t result = outlineHandle;
	if ((int32_t)outlineHandle != -1) {
		ctx.r1.u64 = stack;
		result = n_sub_8263A788(ctx, base, outlineHandle, 4);
		door->m_3C = 0xFFFFFFFFu;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_8252B6D8, 0x8252B6D8) { ctx.r3.u64 = Lua_Door_RemoveOutlineForLineFiring(ctx, base, ctx.r3.u32); }

// The handle in door->m_3C (-1 when unset): with door->m_20 set, a set handle is passed to n_sub_8263A788
// with 4 and unset (as Lua_Door_RemoveOutlineForLineFiring does); otherwise an unset handle becomes what
// n_sub_82639C30 returns for the door's entity.
uint64_t n_sub_8252B720(CpuState& ctx, uint8_t* base, uint64_t doorAddr) {
	if (!UseLiftedCode(32, 0x8252B720)) { ctx.r3.u64 = doorAddr; __imp__sub_8252B720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8252B720);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	stack = PushStackFrame(base, stack, 96);

	uint64_t result = doorAddr;
	if (door->m_20 != 0) {
		uint64_t outlineHandle = door->m_3C;
		result = outlineHandle;
		if ((int32_t)outlineHandle != -1) {
			ctx.r1.u64 = stack;
			result = n_sub_8263A788(ctx, base, outlineHandle, 4);
			door->m_3C = 0xFFFFFFFFu;
		}
	} else if ((int32_t)door->m_3C == -1) {
		uint32_t doorEntity = door->m_4;
		ctx.r1.u64 = stack;
		result = n_sub_82639C30(ctx, base, doorEntity);
		door->m_3C = (uint32_t)result;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(32, sub_8252B720, 0x8252B720) { ctx.r3.u64 = n_sub_8252B720(ctx, base, ctx.r3.u64); }

uint64_t Door_PruneInvalidEntityHandles(CpuState& ctx, uint8_t* base, uint32_t doorAddr) {
	if (!UseLiftedCode(61, 0x828AB598)) { ctx.r3.u64 = doorAddr; __imp__sub_828AB598(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828AB598);
	uint32_t stack = ctx.r1.u64;
	CECDoor* door = GameObject<CECDoor>(base, doorAddr);
	// r9 handed to the callees below; starts as the caller's r9
	uint64_t r9ForCallees = ctx.r9.u64;
	stack = PushStackFrame(base, stack, 112);
	STORE32(stack + 80, 0u);
	uint32_t entryAddr = door->m_10;
	STORE32(stack + 84, entryAddr);
	while (entryAddr != door->m_14) {
		uint32_t handleRef = LOAD32(entryAddr + 4);
		bool keepEntry = false;
		if (handleRef != 0) {
			uint32_t entityPtr = LOAD32(handleRef);
			if (entityPtr == 0) {
				// state the callee may pass on
				ctx.r1.u64 = stack;
				ctx.r9.u64 = r9ForCallees;
				ctx.r10.u64 = entityPtr;
				EntityHandle_Release(ctx, base, entryAddr);
				r9ForCallees = ctx.r9.u64;
			} else {
				keepEntry = (LOAD8(entityPtr + 144) & 64) != 0;
			}
		}
		if (keepEntry) {
			entryAddr += 8;
			STORE32(stack + 84, entryAddr);
		} else {
			// drop the entry, sliding the handles that follow down over it
			uint32_t rangeEnd = door->m_14;
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r9.u64 = r9ForCallees;
			EntityHandle_CopyRange(ctx, base, (uint64_t)entryAddr + 8, rangeEnd, entryAddr);
			rangeEnd = door->m_14;
			// state the callee may pass on
			ctx.r3.u64 = (uint64_t)((int32_t)doorAddr + 12);
			HandleRange_ReleaseAll(ctx, base, (uint64_t)rangeEnd - 8, rangeEnd);
			r9ForCallees = (uint64_t)door->m_14 - 8;
			STORE64(stack + 80, LOAD64(stack + 80));
			entryAddr = LOAD32(stack + 84);
			door->m_14 = (uint32_t)r9ForCallees;
		}
	}
	uint32_t remainingBytes = (uint32_t)((uint64_t)door->m_14 - (uint64_t)door->m_10) & 0xFFFFFFF8u;
	uint32_t leadingZeros = remainingBytes == 0 ? 32u : (uint32_t)__builtin_clz(remainingBytes);
	uint32_t isEmpty = (leadingZeros >> 5) & 1;
	uint64_t result = (uint64_t)(isEmpty ^ 1u);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers may read r6-r8 after the call
	ctx.r6.u64 = isEmpty;
	ctx.r7.u64 = leadingZeros;
	ctx.r8.u64 = remainingBytes;
	return result;
}
PROMOTED_ENTRY(61, sub_828AB598, 0x828AB598) { ctx.r3.u64 = Door_PruneInvalidEntityHandles(ctx, base, ctx.r3.u32); }
