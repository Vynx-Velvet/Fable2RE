// CBlockComponent (vtable 0x8200AC34): methods of the class as readable C++.
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

// sub_824F4A78 = Lua_Block_GetLastCompletedBlockType (Lua Block.GetLastCompletedBlockType)  [8 bytes]
uint64_t Lua_Block_GetLastCompletedBlockType(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(30, 0x824F4A78)) { ctx.r3.u64 = blockComponent; __imp__sub_824F4A78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824F4A78);
	uint32_t block = (uint32_t)blockComponent;
	return LOAD32(block + 0xA0);
}
PROMOTED_ENTRY(30, sub_824F4A78, 0x824F4A78) { ctx.r3.u64 = Lua_Block_GetLastCompletedBlockType(ctx, base, ctx.r3.u64); }

// sub_824F4A80 = Lua_Block_GetLastCompletedBlockTime (Lua Block.GetLastCompletedBlockTime)  [8 bytes]
uint64_t Lua_Block_GetLastCompletedBlockTime(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(30, 0x824F4A80)) { ctx.r3.u64 = arg1; __imp__sub_824F4A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824F4A80);
	uint32_t blockComponent = (uint32_t)arg1;
	return LOAD32(blockComponent + 0xA4);
}
PROMOTED_ENTRY(30, sub_824F4A80, 0x824F4A80) { ctx.r3.u64 = Lua_Block_GetLastCompletedBlockTime(ctx, base, ctx.r3.u64); }

uint64_t Lua_Block_IsBlocking_8279DEC0(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(52, 0x8279DEC0)) { ctx.r3.u64 = arg1; __imp__sub_8279DEC0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8279DEC0);
	uint32_t blockComponent = (uint32_t)arg1;
	return LOAD8(blockComponent + 0xA8);
}
PROMOTED_ENTRY(52, sub_8279DEC0, 0x8279DEC0) { ctx.r3.u64 = Lua_Block_IsBlocking_8279DEC0(ctx, base, ctx.r3.u64); }

// sub_82C0B268  [28 bytes]
uint64_t CBlockComponent_SetEnabled(CpuState& ctx, uint8_t* base, uint64_t blockComponentAddr) {
	if (!UseLiftedCode(89, 0x82C0B268)) { ctx.r3.u64 = blockComponentAddr; __imp__sub_82C0B268(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0B268);
	if ((uint32_t)blockComponentAddr == 0) return blockComponentAddr;

	CBlockComponent* blockComponent = GameObject<CBlockComponent>(base, blockComponentAddr);
	uint32_t virtualFn = LOAD32(uint32_t(blockComponent->vtable) + 36);
	ctx.r3.u64 = blockComponentAddr;
	ctx.r4.u64 = 1;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0B268, 0x82C0B268) { ctx.r3.u64 = CBlockComponent_SetEnabled(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82C0BDD0(CpuState& ctx, uint8_t* base, uint64_t blockComponent, double value) {
	if (!UseLiftedCode(89, 0x82C0BDD0)) { ctx.r3.u64 = blockComponent; ctx.f1.f64 = value; __imp__sub_82C0BDD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BDD0);

	uint32_t targetObject = LOAD32((uint32_t)blockComponent + 0x4C);
	if (targetObject == 0) {
		ctx.f1.f64 = value; // callers read f1 after the call
		return targetObject;
	}

	ctx.fpscr.disableFlushMode();
	const double lowerBound = (double)LOAD_F32(0x82000C0Cu);
	const double upperBound = (double)LOAD_F32(0x82000C08u);
	// A NaN fails both tests and is passed on unclamped.
	if (value < lowerBound) {
		value = lowerBound;
	} else if (value > upperBound) {
		value = upperBound;
	}

	uint32_t virtualFn = LOAD32(LOAD32(targetObject) + 0x0C);
	ctx.r3.u64 = targetObject;
	ctx.r10.u64 = virtualFn;
	ctx.f1.f64 = value;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BDD0, 0x82C0BDD0) { ctx.r3.u64 = n_sub_82C0BDD0(ctx, base, ctx.r3.u64, ctx.f1.f64); }

// sub_82C0BE18  [28 bytes]
uint64_t n_sub_82C0BE18(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(89, 0x82C0BE18)) { ctx.r3.u64 = blockComponent; __imp__sub_82C0BE18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BE18);
	uint32_t targetObject = LOAD32((uint32_t)blockComponent + 0x4C);
	if (targetObject == 0) return targetObject;
	uint32_t virtualMethod = LOAD32(LOAD32(targetObject) + 0x10);
	ctx.r3.u64 = targetObject;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BE18, 0x82C0BE18) { ctx.r3.u64 = n_sub_82C0BE18(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82C0BE38(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(89, 0x82C0BE38)) { ctx.r3.u64 = blockComponent; __imp__sub_82C0BE38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BE38);
	uint32_t targetObject = LOAD32((uint32_t)blockComponent + 0x4C);
	if (targetObject == 0) return targetObject;
	uint32_t virtualMethod = LOAD32(LOAD32(targetObject) + 0x14);
	ctx.r3.u64 = targetObject;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BE38, 0x82C0BE38) { ctx.r3.u64 = n_sub_82C0BE38(ctx, base, ctx.r3.u64); }

// sub_82C0BE58  [28 bytes]
uint64_t n_sub_82C0BE58(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(89, 0x82C0BE58)) { ctx.r3.u64 = blockComponent; __imp__sub_82C0BE58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BE58);
	uint32_t targetObject = LOAD32((uint32_t)blockComponent + 0x4C);
	if (targetObject == 0) return targetObject;
	uint32_t virtualMethod = LOAD32(LOAD32(targetObject) + 0x18);
	ctx.r3.u64 = targetObject;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BE58, 0x82C0BE58) { ctx.r3.u64 = n_sub_82C0BE58(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82C0BE78(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(89, 0x82C0BE78)) { ctx.r3.u64 = blockComponent; __imp__sub_82C0BE78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BE78);

	uint32_t component = LOAD32((uint32_t)blockComponent + 76);
	if (component == 0) return 0;

	uint32_t vtable = LOAD32(component);
	uint32_t funcPtr = LOAD32(vtable + 28);

	ctx.r3.u64 = component;
	ctx.r10.u64 = funcPtr;
	REX_CALL_INDIRECT_FUNC(funcPtr);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BE78, 0x82C0BE78) { ctx.r3.u64 = n_sub_82C0BE78(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82C0BE98(CpuState& ctx, uint8_t* base, uint64_t blockComponent) {
	if (!UseLiftedCode(89, 0x82C0BE98)) { ctx.r3.u64 = blockComponent; __imp__sub_82C0BE98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0BE98);
	uint32_t target = LOAD32((uint32_t)blockComponent + 0x4C);
	if (target == 0) return target;
	uint32_t callTarget = LOAD32(LOAD32(target) + 0x20);
	ctx.r3.u64 = target;
	ctx.r10.u64 = callTarget;
	REX_CALL_INDIRECT_FUNC(callTarget);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0BE98, 0x82C0BE98) { ctx.r3.u64 = n_sub_82C0BE98(ctx, base, ctx.r3.u64); }

// sub_82C0CEC8  [160 bytes]
uint64_t CBlockComponent_Ctor(CpuState& ctx, uint8_t* base, uint64_t blockComponentAddr) {
	if (!UseLiftedCode(89, 0x82C0CEC8)) { ctx.r3.u64 = blockComponentAddr; __imp__sub_82C0CEC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0CEC8);
	uint32_t stack = ctx.r1.u64;
	CBlockComponent* blockComponent = GameObject<CBlockComponent>(base, blockComponentAddr);
	stack = PushStackFrame(base, stack, 96);

	blockComponent->vtable = 0x8200AC34u;
	ctx.r1.u64 = stack;
	CCharString_Constructor(ctx, base, blockComponentAddr + 4);

	blockComponent->m_48 = 0;
	blockComponent->m_4C = 0;
	blockComponent->m_50 = 0;
	blockComponent->m_54 = 0;
	blockComponent->m_58 = 0;
	blockComponent->m_5C = 0;
	blockComponent->m_60 = 0;
	blockComponent->m_64 = 0;
	blockComponent->m_68 = 0;
	blockComponent->m_6C = 0x8200AC10u;
	blockComponent->m_70 = 0;
	blockComponent->m_74 = 0;
	blockComponent->m_78 = 0;
	blockComponent->m_7C = 0;
	blockComponent->m_80 = 0;
	blockComponent->m_84 = 0;
	blockComponent->m_lastCompletedBlockType = 0;
	blockComponent->m_lastCompletedBlockTime = 0;
	blockComponent->m_A8 = 1;
	blockComponent->m_70 = (uint32_t)blockComponentAddr;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers may read r8 after the call: it still holds the 1 stored to m_A8
	ctx.r8.u64 = 1;
	return blockComponentAddr;
}
PROMOTED_ENTRY(89, sub_82C0CEC8, 0x82C0CEC8) { ctx.r3.u64 = CBlockComponent_Ctor(ctx, base, ctx.r3.u64); }

uint32_t CBlockComponent_Dtor(CpuState& ctx, uint8_t* base, uint64_t blockComponentAddr) {
	if (!UseLiftedCode(89, 0x82C0E6E8)) { ctx.r3.u64 = blockComponentAddr; __imp__sub_82C0E6E8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C0E6E8);
	uint32_t stack = ctx.r1.u64;
	// r4 is not a parameter: the original hands whatever r4 holds to the slot-1 calls below, so it is tracked here
	uint64_t r4Value = ctx.r4.u64;
	CBlockComponent* blockComponent = GameObject<CBlockComponent>(base, blockComponentAddr);

	stack = PushStackFrame(base, stack, 128);

	// m_84 points to a two-word block whose second word holds an object
	uint32_t holder = blockComponent->m_84;
	blockComponent->vtable = 0x8200AC34u;
	if (holder != 0) {
		uint32_t heldObject = LOAD32(holder + 4);
		if (heldObject != 0) {
			uint32_t method = LOAD32(LOAD32(heldObject) + 4);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = heldObject;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
			r4Value = ctx.r4.u64;
		}
		STORE32(holder + 4, 0);
		STORE32(holder, 0);
		blockComponent->m_84 = 0;
	}

	// The object at m_78 keeps a list at +28 that this component is unlinked from; the word at +36 is decremented first.
	uint32_t listObject = blockComponent->m_78;
	if (listObject != 0) {
		uint32_t listCount = LOAD32(listObject + 36);
		uint32_t list = listObject + 28;
		r4Value = blockComponentAddr;
		STORE32(listObject + 36, listCount - 1);
		ctx.r1.u64 = stack;
		CBlockComponent_UnlinkFromList(ctx, base, list, blockComponentAddr);
	}

	// BlockMap_ReleaseEntry looks m_48 up through the object at m_80 and may decrement a byte counter of the entry it finds.
	uint32_t object80 = blockComponent->m_80;
	if (object80 != 0) {
		uint32_t value48 = blockComponent->m_48;
		ctx.r1.u64 = stack;
		BlockMap_ReleaseEntry(ctx, base, object80, value48);
		r4Value = ctx.r4.u64;
		blockComponent->m_80 = 0;
	}

	uint32_t object7C = blockComponent->m_7C;
	if (object7C != 0) {
		uint32_t method = LOAD32(LOAD32(object7C) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = object7C;
		ctx.r4.u64 = r4Value;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		r4Value = ctx.r4.u64;
	}
	blockComponent->m_7C = 0;
	blockComponent->m_78 = 0;

	// the object embedded at 0x6C (vtable C_8200AC10 from the constructor) gets the C_8200A384 vtable
	blockComponent->m_6C = 0x8200A384u;
	uint32_t object50 = blockComponent->m_50;
	if (object50 != 0) {
		uint32_t method = LOAD32(LOAD32(object50) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = object50;
		ctx.r4.u64 = r4Value;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
	}
	blockComponent->m_50 = 0;
	blockComponent->m_4C = 0;

	ctx.r1.u64 = stack;
	uint32_t result = CCharString_ReleaseMember(ctx, base, blockComponentAddr + 4);
	blockComponent->vtable = 0x8200A390u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(89, sub_82C0E6E8, 0x82C0E6E8) { ctx.r3.u64 = CBlockComponent_Dtor(ctx, base, ctx.r3.u64); }

uint64_t CBlockComponent_DeletingDtor(CpuState& ctx, uint8_t* base, uint64_t blockComponentAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(89, 0x82C0F648)) { ctx.r3.u64 = blockComponentAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82C0F648(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0F648);
	GameStackFrame stackFrame(ctx, base, 112);
	// state the callee reads: CBlockComponent_Dtor takes r4 from ctx and passes it on
	ctx.r4.u64 = deleteFlags;
	CBlockComponent_Dtor(ctx, base, blockComponentAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_FreeThunk(ctx, base, blockComponentAddr);
	}
	return blockComponentAddr;
}
PROMOTED_ENTRY(89, sub_82C0F648, 0x82C0F648) { ctx.r3.u64 = CBlockComponent_DeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }
