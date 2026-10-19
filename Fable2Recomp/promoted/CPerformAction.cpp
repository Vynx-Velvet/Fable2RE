// CPerformAction (vtable 0x82005248): methods of the class as readable C++.
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

uint64_t n_sub_8218C228(CpuState& ctx, uint8_t* base, uint64_t performActionAddr, uint64_t lookupData) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(0, 0x8218C228)) { ctx.r3.u64 = performActionAddr; ctx.r4.u64 = lookupData; __imp__sub_8218C228(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8218C228);
	uint32_t stack = ctx.r1.u64;
	PPCCRRegister compare6{};
	PPCXERRegister flags = ctx.xer;
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);
	uint64_t scratchR7 = ctx.r7.u64;
	uint64_t scratchR8 = 0;

	stack = PushStackFrame(base, stack, 144);

	if (LOAD8(0x83496BB9u) == 0) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = lookupData;
		return 1;
	}

	bool performNow = false;
	if (performAction->m_5C != 0 && performAction->m_60 != 0) {
		compare6.compare<int32_t>(int32_t(performAction->m_64), -1, flags);
		performNow = !compare6.eq;
	}

	if (performNow) {
		ctx.r1.u64 = stack;
		uint32_t actionRef = n_sub_821C68D0(ctx, base, performAction->m_5C, performAction->m_60, performAction->m_64);
		n_sub_827F0528(ctx, base, stack + 88, actionRef);
		ctx.r1.u64 = stack;
		uint64_t result = n_sub_827F0358(ctx, base, performActionAddr + 88);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	if (LOAD32((uint32_t)performActionAddr + 88) > 0) {
		ctx.r1.u64 = stack;
		uint64_t result = n_sub_827F0358(ctx, base, performActionAddr + 88);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	uint64_t actionNameAddr = performActionAddr + 84;
	ctx.r1.u64 = stack;
	uint32_t hasName = CCharString_NotEqualsEmptyOrLiteral(ctx, base, actionNameAddr, g_82000C98);
	scratchR8 = ctx.r8.u64;
	if ((hasName & 0xFF) == 0) {
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return 0;
	}

	uint32_t foundValue = 0;
	bool hasFoundValue = false;
	if (((LOAD32(lookupData + 36) >> 21) & 1) != 0) {
		uint32_t cachedEntry = LOAD32(lookupData + 140);
		if (cachedEntry != 0) {
			foundValue = LOAD32(LOAD32(lookupData + 72) + ((uint32_t)LOAD8(cachedEntry + 21) << 3) + 4);
		} else {
			uint32_t begin = LOAD32(lookupData + 72);
			uint32_t end = LOAD32(lookupData + 76);
			STORE32(stack + 88, 0);
			uint64_t byteSpan = (uint64_t)end - begin;
			STORE32(stack + 92, begin);
			flags.ca = (int32_t)byteSpan < 0 & (byteSpan & 0x7) != 0;
			int32_t count = (int32_t)byteSpan >> 3;
			if (count > 0) {
				// inlined lower_bound of a sorted (key, value) map, searching for key 21
				do {
					flags.ca = count < 0 & (count & 0x1) != 0;
					int32_t half = count >> 1;
					scratchR8 = (uint64_t)(uint32_t)half << 3;
					uint32_t mid = begin + (uint32_t)scratchR8;
					compare6.compare<int32_t>(int32_t(LOAD32(mid)), 21, flags);
					scratchR7 = compare6.lt ? 1 : 0;
					if (scratchR7 != 0) {
						begin = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 92, begin);
			}
			if (begin != end) {
				compare6.compare<int32_t>(int32_t(LOAD32(begin)), 21, flags);
				if (compare6.gt) {
					foundValue = LOAD32(end + 4);
				} else {
					STORE64(stack + 88, LOAD64(stack + 88));
					foundValue = LOAD32(LOAD32(stack + 92) + 4);
				}
			} else {
				foundValue = LOAD32(end + 4);
			}
		}
		hasFoundValue = true;
	}

	if (hasFoundValue) {
		STORE32(stack + 80, 0);
		ctx.xer.ca = flags.ca;
		uint32_t handle = n_sub_821D8EC0(ctx, base, foundValue, actionNameAddr, 1, stack + 80);
		n_sub_827F0528(ctx, base, stack + 88, handle);
		uint64_t result = n_sub_827F0358(ctx, base, stack + 88);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(0, sub_8218C228, 0x8218C228) { ctx.r3.u64 = n_sub_8218C228(ctx, base, ctx.r3.u64, ctx.r4.u64); }

double CPerformAction_GetParameterFloat(CpuState& ctx, uint8_t* base, uint32_t performActionAddr) {
	if (!UseLiftedCode(7, 0x82242530)) { ctx.r3.u64 = performActionAddr; __imp__sub_82242530(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x82242530);
	uint32_t stack = ctx.r1.u32;
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);
	uint32_t paramsBegin = performAction->m_paramsBegin;
	uint32_t paramsEnd = performAction->m_paramsEnd;

	// Binary search over the 12-byte parameter entries (leading int32 key) for the
	// first entry whose key is >= 1.
	int32_t remaining = (int32_t)(paramsEnd - paramsBegin) / 12;
	uint32_t pos = paramsBegin;
	STORE32(stack - 16, 0);
	STORE32(stack - 12, pos);
	if (remaining > 0) {
		do {
			int32_t half = remaining / 2;
			uint32_t mid = pos + 12 * half;
			if ((int32_t)LOAD32(mid) < 1) {
				pos = mid + 12;
				remaining = remaining - half - 1;
			} else {
				remaining = half;
			}
		} while (remaining > 0);
		STORE32(stack - 12, pos);
	}

	uint32_t entryAddr;
	if (pos != paramsEnd && (int32_t)LOAD32(pos) <= 1) {
		STORE64(stack - 16, LOAD64(stack - 16));
		entryAddr = LOAD32(stack - 12);
	} else {
		entryAddr = paramsEnd;
	}

	if (entryAddr != paramsEnd) {
		ctx.fpscr.disableFlushMode();
		return double(LOAD_F32(LOAD32(entryAddr + 4) + 16));
	}
	ctx.fpscr.disableFlushMode();
	return double(LOAD_F32(0x820994B4u));
}
PROMOTED_ENTRY(7, sub_82242530, 0x82242530) { ctx.f1.f64 = CPerformAction_GetParameterFloat(ctx, base, ctx.r3.u32); }

double CPerformAction_GetDuration(CpuState& ctx, uint8_t* base, uint32_t performActionAddr) {
	if (!UseLiftedCode(9, 0x8226D3D8)) { ctx.r3.u64 = performActionAddr; __imp__sub_8226D3D8(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x8226D3D8);
	uint32_t stack = ctx.r1.u32;
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);

	uint32_t paramsBegin = performAction->m_paramsBegin;
	uint32_t paramsEnd = performAction->m_paramsEnd;

	STORE32(stack - 16, 0);
	STORE32(stack - 12, paramsBegin);

	// Inlined map lookup: lower_bound over the 12-byte-keyed parameter table for the entry with key 1.
	uint32_t entry = paramsBegin;
	int32_t remaining = (int32_t)(paramsEnd - paramsBegin) / 12;
	if (remaining > 0) {
		do {
			int32_t half = remaining >> 1;
			uint32_t offset = (uint32_t)(half * 12);
			entry += offset;
			if ((int32_t)LOAD32(entry) < 1) {
				entry += 12;
				remaining = remaining - half - 1;
			} else {
				entry -= offset;
				remaining = half;
			}
		} while (remaining > 0);
		STORE32(stack - 12, entry);
	}

	uint32_t result = paramsEnd;
	if (entry != paramsEnd && (int32_t)LOAD32(entry) <= 1) {
		STORE64(stack - 16, LOAD64(stack - 16));
		result = entry;
	}

	if (result != performAction->m_paramsEnd) {
		uint32_t param = LOAD32(result + 4);
		ctx.fpscr.disableFlushMode();
		return (double)LOAD_F32(param + 8);
	}
	ctx.fpscr.disableFlushMode();
	return (double)LOAD_F32(0x820994B4u);
}
PROMOTED_ENTRY(9, sub_8226D3D8, 0x8226D3D8) { ctx.f1.f64 = CPerformAction_GetDuration(ctx, base, ctx.r3.u32); }

uint64_t CPerformAction_Clone(CpuState& ctx, uint8_t* base, uint64_t performActionAddr, uint64_t sourceAction) {
	if (!UseLiftedCode(12, 0x822C00F8)) { ctx.r3.u64 = performActionAddr; ctx.r4.u64 = sourceAction; __imp__sub_822C00F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822C00F8);
	GameStackFrame stackFrame(ctx, base, 112);

	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);

	uint32_t allocationSize = 140;
	ctx.r4.u64 = sourceAction;
	uint64_t newAction = operator_new(ctx, base, allocationSize);
	uint64_t actionCopy;
	if ((uint32_t)newAction != 0) {
		actionCopy = CAnimMovementDef_CopyConstructDerived(ctx, base, newAction, sourceAction);
	} else {
		actionCopy = 0;
	}
	C_820F1270_Clone(ctx, base, performActionAddr, actionCopy);

	uint32_t vtable = performAction->vtable;
	if (vtable != 0) {
		n_sub_82180B28(ctx, base, vtable);
	}
	return performActionAddr;
}
PROMOTED_ENTRY(12, sub_822C00F8, 0x822C00F8) { ctx.r3.u64 = CPerformAction_Clone(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPerformAction_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t performAction, uint64_t arg2) {
	if (!UseLiftedCode(46, 0x826D1E20)) { ctx.r3.u64 = performAction; ctx.r4.u64 = arg2; __imp__sub_826D1E20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826D1E20);
	uint32_t stack = PushStackFrame(base, ctx.r1.u64, 112);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, performAction + 0x88);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, performAction + 0x54);
	HandleHolder_Dtor(ctx, base, performAction);
	if (arg2 & 1) {
		HandleTarget_Free(ctx, base, performAction);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return performAction;
}
PROMOTED_ENTRY(46, sub_826D1E20, 0x826D1E20) { ctx.r3.u64 = CPerformAction_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CPerformAction_Construct(CpuState& ctx, uint8_t* base, uint64_t performActionAddr, uint64_t actionOwner, uint64_t arg3) {
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(46, 0x826D3A60)) { ctx.r3.u64 = performActionAddr; ctx.r4.u64 = actionOwner; ctx.r5.u64 = arg3; __imp__sub_826D3A60(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826D3A60);
	uint32_t stack = ctx.r1.u64;
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	CActionBase_ConstructWithDefaults(ctx, base, performActionAddr, 6, arg3, actionOwner);

	ctx.fpscr.disableFlushMode();
	performAction->vtable = 0x82005248u;
	performAction->m_78 = LOAD_F32(0x820990A8u);
	performAction->m_80 = 0;
	performAction->m_7C = LOAD_F32(0x820994B4u);
	performAction->m_81 = 0;
	performAction->m_82 = 0;
	performAction->m_83 = 0;
	performAction->m_84 = 0;
	performAction->m_85 = 0;
	performAction->m_88 = 0;

	// Atomically bump the shared global counter at 0x83496EB8.
	uint32_t counterAddr = uint32_t(g_83496EB8);
	uint32_t savedMsr = ctx.r13.u64;
	PPCCRRegister compare0{};
	uint32_t lockState;
	uint32_t newCount;
	uint32_t casAddr;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		lockState = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
		newCount = __builtin_bswap32(ctx.reserved.u32);
		newCount = (int32_t)newCount + 1;
		casAddr = counterAddr;
		compare0.lt = 0;
		compare0.gt = 0;
		compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
		compare0.so = ctx.xer.so;
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = lockState & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!compare0.eq);

	performAction->m_50 = 1;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return performActionAddr;
}
PROMOTED_ENTRY(46, sub_826D3A60, 0x826D3A60) { ctx.r3.u64 = CPerformAction_Construct(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t CPerformAction_ConstructVariant(CpuState& ctx, uint8_t* base, uint64_t performActionAddr, uint64_t actionOwner, uint64_t arg3) {
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(46, 0x826D3B08)) { ctx.r3.u64 = performActionAddr; ctx.r4.u64 = actionOwner; ctx.r5.u64 = arg3; __imp__sub_826D3B08(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826D3B08);
	uint32_t stack = ctx.r1.u64;
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);

	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CActionBase_ConstructWithDefaults(ctx, base, performActionAddr, 6, arg3, actionOwner);

	ctx.fpscr.disableFlushMode();
	performAction->m_78 = LOAD_F32(0x820990A8u);
	performAction->vtable = 0x82005248u;
	performAction->m_7C = LOAD_F32(0x820994B4u);
	performAction->m_80 = 0;
	performAction->m_81 = 1;
	performAction->m_82 = 0;
	performAction->m_83 = 0;
	performAction->m_84 = 0;
	performAction->m_85 = 0;
	performAction->m_88 = 0;

	// Atomically increment the big-endian global counter stored at 0x83496EB8.
	uint32_t* refCount = reinterpret_cast<uint32_t*>(RAW(uint32_t(g_83496EB8)));
	uint32_t observed;
	uint32_t updated;
	do {
		observed = *refCount;
		updated = __builtin_bswap32(__builtin_bswap32(observed) + 1);
	} while (!__sync_bool_compare_and_swap(refCount, observed, updated));

	performAction->m_50 = 1;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return (uint32_t)performActionAddr;
}
PROMOTED_ENTRY(46, sub_826D3B08, 0x826D3B08) { ctx.r3.u64 = CPerformAction_ConstructVariant(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CPerformAction_FindActionByType(CpuState& ctx, uint8_t* base, uint64_t performAction) {
	if (!UseLiftedCode(46, 0x826DFA48)) { ctx.r3.u64 = performAction; __imp__sub_826DFA48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826DFA48);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);

	PPCXERRegister flags = ctx.xer;
	uint64_t scratch = ctx.r7.u64;
	uint64_t stride = ctx.r8.u64;

	// [0x18, 0x1C) is a sorted list of 12-byte entries keyed by an int at offset 0
	uint32_t iterator = LOAD32((uint32_t)performAction + 24);
	uint32_t lastAction = LOAD32((uint32_t)performAction + 28);
	int32_t remaining = (int32_t)(lastAction - iterator) / 12;

	STORE32(stack + 80, 0);
	STORE32(stack + 84, iterator);
	if (remaining > 0) {
		do {
			flags.ca = (remaining < 0) & ((remaining & 1) != 0);
			int32_t half = remaining >> 1;
			stride = (uint32_t)half * 12;
			iterator = iterator + (uint32_t)stride;
			int32_t key = (int32_t)LOAD32(iterator);
			scratch = key < 18 ? 1 : 0;
			if (key < 18) {
				iterator = iterator + 12;
				remaining = remaining - half - 1;
			} else {
				iterator = iterator - (uint32_t)stride;
				remaining = half;
			}
		} while (remaining > 0);
		STORE32(stack + 84, iterator);
	}

	// lower bound found: only accept it if the key matches exactly
	uint32_t foundEntry = lastAction;
	if (iterator != lastAction && (int32_t)LOAD32(iterator) <= 18) {
		STORE64(stack + 80, LOAD64(stack + 80));
		foundEntry = iterator;
	}

	uint64_t result = performAction;
	if (foundEntry != lastAction) {
		uint32_t entry = LOAD32(foundEntry + 4);
		uint32_t action = LOAD32(entry + 8);
		uint32_t method = LOAD32(LOAD32(action) + 44);
		PPCRegister callTarget{};
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = action;
		ctx.r5.u64 = entry;
		ctx.r6.u64 = lastAction;
		ctx.r7.u64 = scratch;
		ctx.r8.u64 = stride;
		ctx.r9.u64 = iterator;
		ctx.r10.u64 = method;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		flags.ca = ctx.xer.ca;
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(46, sub_826DFA48, 0x826DFA48) { ctx.r3.u64 = CPerformAction_FindActionByType(ctx, base, ctx.r3.u64); }

// sub_826DFB58  [40 bytes]
// Releases the shared handle whose address arrives in r4 (r3 is not used) and returns 0.
uint64_t n_sub_826DFB58(CpuState& ctx, uint8_t* base, uint64_t handleAddr) {
	if (!UseLiftedCode(46, 0x826DFB58)) { ctx.r4.u64 = handleAddr; __imp__sub_826DFB58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826DFB58);
	GameStackFrame stackFrame(ctx, base, 96);
	ctx.r4.u64 = handleAddr; // state the callee may pass on
	SharedHandle_Release(ctx, base, handleAddr);
	return 0;
}
PROMOTED_ENTRY(46, sub_826DFB58, 0x826DFB58) { ctx.r3.u64 = n_sub_826DFB58(ctx, base, ctx.r4.u64); }

// sub_827F0358  [152 bytes]
// Looks the 32-bit key stored at keyAddr up in the tree map at 0x834A5C38 (sub_82B5D548 writes a checked
// iterator: owning map, node). Returns 1 when the key is present; otherwise passes keyAddr to sub_82B5D3A0
// and returns 0.
uint64_t n_sub_827F0358(CpuState& ctx, uint8_t* base, uint32_t keyAddr) {
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(55, 0x827F0358)) { ctx.r4.u64 = keyAddr; __imp__sub_827F0358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827F0358);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	const uint32_t keyCopy = stack + 80;
	const uint32_t iterator = stack + 88; // (owning map, node)
	STORE32(keyCopy, LOAD32(keyAddr));
	ctx.r1.u64 = stack;
	n_sub_82B5D548(ctx, base, iterator, keyCopy);

	// The iterator must belong to this map; a null owner fails the check too.
	const uint32_t lookupMap = uint32_t(g_834A0000 + 23608);
	if (LOAD32(iterator) != lookupMap) {
		ppc_trap(ctx, base, 22);
	}

	const uint32_t endNode = LOAD32(lookupMap + 4);
	const uint32_t foundNode = LOAD32(iterator + 4);
	if (foundNode != endNode) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 1;
	}

	// state the callee may pass on: what the not-found comparison leaves in r6-r10
	ctx.r6.u64 = 0;
	ctx.r7.u64 = 1;
	ctx.r8.u64 = 32;
	ctx.r9.u64 = 0;
	ctx.r10.u64 = foundNode;
	n_sub_82B5D3A0(ctx, base, keyAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(55, sub_827F0358, 0x827F0358) { ctx.r3.u64 = n_sub_827F0358(ctx, base, ctx.r4.u32); }

// sub_827F06A0  [100 bytes]
// Constructor: after the parent constructor sub_827F02C0 it installs the CAnimMovementDef vtable (0x820ADCC8)
// and resets the five movement fields; the two floats come from read-only constants at 0x820994B4 and +12.
uint32_t CActionBase_ConstructWithDefaults(CpuState& ctx, uint8_t* base, uint64_t movementDefAddr, uint32_t arg2, uint64_t arg3, uint64_t arg4) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t g_820B0000 = int32_t(0x820B0000);
	if (!UseLiftedCode(55, 0x827F06A0)) { ctx.r3.u64 = movementDefAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_827F06A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827F06A0);
	uint32_t stack = ctx.r1.u64;
	const uint32_t defaultFloatsAddr = uint32_t(g_820A0000) - 27468;
	const uint32_t movementDefVtable = uint32_t(g_820B0000) - 9016;
	CAnimMovementDef* movementDef = GameObject<CAnimMovementDef>(base, movementDefAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	n_sub_827F02C0(ctx, base, movementDefAddr, arg2, arg3, arg4);

	ctx.fpscr.disableFlushMode();
	double value = double(LOAD_F32(defaultFloatsAddr));
	movementDef->m_hasMovement = 0;
	movementDef->m_addedTotalRotation = float(value);
	movementDef->vtable = movementDefVtable;
	value = double(LOAD_F32(defaultFloatsAddr + 12));
	movementDef->m_disablePhysics = 0;
	movementDef->m_speedMultiplier = float(value);
	movementDef->m_looping = 0;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// registers the lifted callers may read after the return
	ctx.r7.s64 = int64_t(g_820B0000) - 9016;
	ctx.r8.s64 = int64_t(g_820A0000) - 27468;
	ctx.r9.s64 = g_820B0000;
	return (uint32_t)movementDefAddr;
}
PROMOTED_ENTRY(55, sub_827F06A0, 0x827F06A0) { ctx.r3.u64 = CActionBase_ConstructWithDefaults(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u64, ctx.r6.u64); }

// sub_827F07F8  [8 bytes]
void n_sub_827F07F8(CpuState& ctx, uint8_t* base, uint32_t performActionAddr, uint32_t value) {
	if (!UseLiftedCode(55, 0x827F07F8)) { ctx.r3.u64 = performActionAddr; ctx.r4.u64 = value; __imp__sub_827F07F8(ctx, base); return; }
	LiftedFrame frame(0x827F07F8);
	CPerformAction* performAction = GameObject<CPerformAction>(base, performActionAddr);
	performAction->m_76 = (uint8_t)value;
	return;
}
PROMOTED_ENTRY(55, sub_827F07F8, 0x827F07F8) { n_sub_827F07F8(ctx, base, ctx.r3.u32, ctx.r4.u32); }
