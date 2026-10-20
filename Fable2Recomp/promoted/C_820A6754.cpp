// C_820A6754 (vtable 0x820A6754): methods of the class as readable C++.
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

// sub_822AB3B0  [72 bytes]
uint64_t C_820A6754_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(11, 0x822AB3B0)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = deleteFlags; __imp__sub_822AB3B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822AB3B0);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 96);
	c->vtable = 0x820A6754u;
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, cAddr);
		deleteFlags = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	return cAddr;
}
PROMOTED_ENTRY(11, sub_822AB3B0, 0x822AB3B0) { ctx.r3.u64 = C_820A6754_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_822B9620  [276 bytes]
double C_820A6754_CopyConstructor(CpuState& ctx, uint8_t* base, uint32_t cAddr, uint32_t source) {
	if (!UseLiftedCode(12, 0x822B9620)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = source; __imp__sub_822B9620(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x822B9620);
	C_820A6754* self = GameObject<C_820A6754>(base, cAddr);
	const uint32_t src = source;
	PPCVRegister vecBlock{};
	double value{};

	self->vtable = 0x820A6754u;
	self->m_4 = LOAD32(src + 4);
	self->vtable = 0x82001624u;

	SET_V8(vecBlock, VLOAD((src + 16) & ~0xF));
	VSTORE((cAddr + 16) & ~0xF, V8(vecBlock));

	self->m_20 = LOAD32(src + 32);
	self->m_24 = LOAD32(src + 36);
	self->m_28 = LOAD32(src + 40);
	self->m_2C = LOAD32(src + 44);

	ctx.fpscr.disableFlushMode();
	value = double(LOAD_F32(src + 48));
	self->m_30 = float(value);
	value = double(LOAD_F32(src + 52));
	self->m_34 = AS_U32(float(value));
	self->m_38 = AS_U32(float(double(LOAD_F32(src + 56))));
	self->m_3C = float(double(LOAD_F32(src + 60)));
	self->m_40 = float(double(LOAD_F32(src + 64)));
	self->m_44 = float(double(LOAD_F32(src + 68)));
	self->m_48 = float(double(LOAD_F32(src + 72)));
	self->m_4C = float(double(LOAD_F32(src + 76)));
	self->m_50 = float(double(LOAD_F32(src + 80)));
	self->m_54 = float(double(LOAD_F32(src + 84)));
	value = double(LOAD_F32(src + 88));
	self->m_58 = float(value);
	value = double(LOAD_F32(src + 92));
	self->m_5C = float(value);
	value = double(LOAD_F32(src + 96));
	self->m_60 = float(value);

	STORE8(cAddr + 100, uint8_t(LOAD8(src + 100)));
	self->m_65 = uint8_t(LOAD8(src + 101));
	self->m_66 = uint8_t(LOAD8(src + 102));
	self->m_67 = uint8_t(LOAD8(src + 103));

	value = double(LOAD_F32(src + 104));
	self->m_68 = float(value);
	value = double(LOAD_F32(src + 108));
	self->m_6C = float(value);
	value = double(LOAD_F32(src + 112));
	self->m_70 = float(value);

	self->m_74 = LOAD32(src + 116);
	self->m_78 = LOAD32(src + 120);
	self->m_7C = LOAD32(src + 124);

	ctx.f2.f64 = double(LOAD_F32(src + 96));
	ctx.f3.f64 = double(LOAD_F32(src + 92));
	ctx.f4.f64 = double(LOAD_F32(src + 88));
	return double(LOAD_F32(src + 104));
}
PROMOTED_ENTRY(12, sub_822B9620, 0x822B9620) { ctx.f1.f64 = C_820A6754_CopyConstructor(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t C_820A6754_Destructor(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(17, 0x82359028)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82359028(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82359028);
	uint32_t stack = ctx.r1.u64;
	uint64_t charStringField{};
	uint32_t refCountedField{};
	uint64_t result{};
	uint32_t deleteFlag{};
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	deleteFlag = deleteFlags;
	charStringField = cAddr + 24;
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, charStringField);
	refCountedField = cAddr + 20;
	RefCountedPtr_ReleaseAtomic(ctx, base, refCountedField);
	c->vtable = 0x820A6754u;
	result = cAddr;
	if ((deleteFlag & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
		result = cAddr;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(17, sub_82359028, 0x82359028) { ctx.r3.u64 = C_820A6754_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82390A88  [104 bytes]
uint64_t C_820A6754_Destructor_82390A88(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t destroyFlags) {
	if (!UseLiftedCode(19, 0x82390A88)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = destroyFlags; __imp__sub_82390A88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82390A88);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, cAddr + 36);
	RefCountedPtr_ReleaseAtomic(ctx, base, cAddr + 32);
	c->vtable = 0x820A6754u;
	if (uint32_t(destroyFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, cAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return cAddr;
}
PROMOTED_ENTRY(19, sub_82390A88, 0x82390A88) { ctx.r3.u64 = C_820A6754_Destructor_82390A88(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82465ED8  [96 bytes]
uint32_t C_820A6754_ClearTarget(CpuState& ctx, uint8_t* base, uint32_t entityAddr) {
	if (!UseLiftedCode(26, 0x82465ED8)) { ctx.r3.u64 = entityAddr; __imp__sub_82465ED8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82465ED8);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* entity = GameObject<C_820A6754>(base, entityAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t handle = entity->m_14;
	if ((uint32_t)handle != 0) {
		ctx.r1.u64 = stack;
		handle = HandleTarget_Free(ctx, base, handle);
	}
	entity->m_14 = 0;
	STORE32(entityAddr + 24, 0);
	STORE32(entityAddr + 28, 0);
	entity->vtable = 0x820A6754u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)handle;
}
PROMOTED_ENTRY(26, sub_82465ED8, 0x82465ED8) { ctx.r3.u64 = C_820A6754_ClearTarget(ctx, base, ctx.r3.u32); }

uint32_t C_820A6754_ReleaseRefCountedFields(CpuState& ctx, uint8_t* base, uint32_t cAddr) {
	if (!UseLiftedCode(26, 0x82469348)) { ctx.r3.u64 = cAddr; __imp__sub_82469348(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82469348);
	uint32_t stack = ctx.r1.u64;
	uint32_t controlBlock{};
	uint32_t releasedHandle{};
	uint32_t savedMsr = ctx.r13.u32;
	uint32_t newRefCount{};
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);

	controlBlock = c->m_84;
	if (controlBlock != 0) {
		uint32_t refCountAddr = controlBlock + 4;
		// Atomically release one reference on the control block.
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t savedLock = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			newRefCount = __builtin_bswap32(ctx.reserved.u32);
			newRefCount = (int32_t)newRefCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedLock & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);

		if ((int32_t)newRefCount == 0) {
			uint32_t deleter = LOAD32(LOAD32(controlBlock) + 4);
			callTarget.u64 = (uint64_t)deleter;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = controlBlock;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = deleter;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
			flags.ca = ctx.xer.ca;
		}
		c->m_84 = 0;
	}

	uint32_t refCountedPtrAddr = cAddr + 0x80;
	ctx.r1.u64 = stack;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	RefCountedPtr_ReleaseAtomic(ctx, base, refCountedPtrAddr);
	compare0.lt = ctx.cr0.lt;
	compare0.gt = ctx.cr0.gt;
	compare0.eq = ctx.cr0.eq;
	compare0.so = ctx.cr0.so;
	flags.ca = ctx.xer.ca;

	releasedHandle = c->m_74;
	uint32_t handlesAddr = cAddr + 0x70;
	if (releasedHandle != 0) {
		releasedHandle = HandleTarget_Free(ctx, base, releasedHandle);
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
	}
	STORE32(handlesAddr + 4, 0);
	STORE32(handlesAddr + 8, 0);
	STORE32(handlesAddr + 12, 0);
	c->vtable = 0x820A6754u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return releasedHandle;
}
PROMOTED_ENTRY(26, sub_82469348, 0x82469348) { ctx.r3.u64 = C_820A6754_ReleaseRefCountedFields(ctx, base, ctx.r3.u32); }

// sub_824693E0  [136 bytes]
uint64_t C_820A6754_ReleaseRefCounted78(CpuState& ctx, uint8_t* base, uint64_t cAddr) {
	if (!UseLiftedCode(26, 0x824693E0)) { ctx.r3.u64 = cAddr; __imp__sub_824693E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x824693E0);
	uint32_t frameAddr{};
	uint32_t stack = ctx.r1.u64;
	uint32_t refTarget{};
	uint64_t refCountedPtrAddr{};
	uint64_t releaseResult{};
	uint64_t refCountAddr{};
	uint32_t decrementedCount{};
	uint32_t releaseFunc{};
	uint32_t savedMsr = ctx.r13.u32;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 96);

	refTarget = c->m_78;
	if (refTarget != 0) {
		refCountAddr = (int64_t)(uint64_t)refTarget + 4;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t globalLockToken = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)refCountAddr);
			decrementedCount = __builtin_bswap32(ctx.reserved.u32);
			decrementedCount = (int32_t)decrementedCount - 1;
			frameAddr = (uint32_t)refCountAddr;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(frameAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)decrementedCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = globalLockToken & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);

		if ((int32_t)decrementedCount == 0) {
			releaseFunc = LOAD32(LOAD32(refTarget) + 4);
			callTarget.u64 = (uint64_t)releaseFunc;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = refTarget;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = releaseFunc;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
		}
		c->m_78 = 0u;
	}

	refCountedPtrAddr = (int64_t)cAddr + 116;
	ctx.r1.u64 = stack;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	releaseResult = RefCountedPtr_ReleaseAtomic(ctx, base, refCountedPtrAddr);
	compare0.lt = ctx.cr0.lt;
	compare0.gt = ctx.cr0.gt;
	compare0.eq = ctx.cr0.eq;
	compare0.so = ctx.cr0.so;
	c->vtable = 0x820A6754u;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(26, sub_824693E0, 0x824693E0) { ctx.r3.u64 = C_820A6754_ReleaseRefCounted78(ctx, base, ctx.r3.u64); }

uint64_t C_820A6754_ReleaseRefCounted8(CpuState& ctx, uint8_t* base, uint32_t cAddr) {
	if (!UseLiftedCode(33, 0x8254F8D8)) { ctx.r3.u64 = cAddr; __imp__sub_8254F8D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8254F8D8);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};

	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);

	stack = PushStackFrame(base, stack, 96);

	uint32_t refObj = (uint32_t)c->m_8;
	result = refObj;
	if (refObj != 0) {
		uint32_t refCountAddr = refObj + 4;
		uint32_t newRefCount;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = ctx.r13.u32 & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountAddr);
			newRefCount = __builtin_bswap32(ctx.reserved.u32);
			newRefCount = (int32_t)newRefCount - 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);

		// Last reference released: invoke the second virtual slot on the ref-counted object.
		if ((int32_t)newRefCount == 0) {
			callTarget.u64 = LOAD32(LOAD32(refObj) + 4);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = refObj;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = callTarget.u64;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
		}
		c->m_8 = 0u;
	}

	c->vtable = 0x820A6754u;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	return result;
}
PROMOTED_ENTRY(33, sub_8254F8D8, 0x8254F8D8) { ctx.r3.u64 = C_820A6754_ReleaseRefCounted8(ctx, base, ctx.r3.u32); }

uint64_t C_820A6754_CharStringDestructor(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(56, 0x828149D8)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = deleteFlags; __imp__sub_828149D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828149D8);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* target = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, (uint32_t)cAddr + 0x20);
	target->vtable = 0x820A6754u;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, cAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return cAddr;
}
PROMOTED_ENTRY(56, sub_828149D8, 0x828149D8) { ctx.r3.u64 = C_820A6754_CharStringDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void C_820A6754_Assign(CpuState& ctx, uint8_t* base, uint32_t cAddr, uint32_t source) {
	if (!UseLiftedCode(74, 0x82A3FEB8)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = source; __imp__sub_82A3FEB8(ctx, base); return; }
	LiftedFrame frame(0x82A3FEB8);
	C_820A6754* dest = GameObject<C_820A6754>(base, cAddr);
	dest->vtable = 0x820A6754u;
	dest->m_4 = LOAD32(source + 4);
	dest->m_10 = LOAD32(source + 16);
	dest->m_14 = LOAD32(source + 20);
	dest->m_18 = LOAD32(source + 24);
	dest->m_1C = LOAD32(source + 28);

	PPCVRegister vec16{};
	SET_V8(vec16, VLOAD((source + 32) & ~0xF));
	VSTORE((cAddr + 32) & ~0xF, V8(vec16));

	ctx.fpscr.disableFlushMode();
	dest->m_30 = float(LOAD_F32(source + 48));
	dest->m_34 = LOAD32(source + 52);
	dest->m_38 = LOAD32(source + 56);

	uint32_t src = source + 60;
	uint32_t dst = cAddr + 60;
	for (int i = 0; i < 10; ++i) {
		STORE32(dst, LOAD32(src));
		src += 4;
		dst += 4;
	}
	STORE32(cAddr + 100, LOAD32(source + 100));
	ctx.r8.u64 = 32;
}
PROMOTED_ENTRY(74, sub_82A3FEB8, 0x82A3FEB8) { C_820A6754_Assign(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t C_820A6754_SharedHandleDestructor(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(74, 0x82A448F0)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82A448F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A448F0);
	C_820A6754* obj = GameObject<C_820A6754>(base, cAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	SharedHandle_Release(ctx, base, cAddr + 32);
	obj->vtable = 0x820A6754u;
	uint64_t result = cAddr;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, result);
	}
	return result;
}
PROMOTED_ENTRY(74, sub_82A448F0, 0x82A448F0) { ctx.r3.u64 = C_820A6754_SharedHandleDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t C_820A6754_ListDestructor(CpuState& ctx, uint8_t* base, uint64_t cAddr, uint64_t destroyFlags) {
	if (!UseLiftedCode(74, 0x82A45F58)) { ctx.r3.u64 = cAddr; ctx.r4.u64 = destroyFlags; __imp__sub_82A45F58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A45F58);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* obj = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t listAddr = cAddr + 8;
	ctx.r1.u64 = stack;
	List_Destroy(ctx, base, listAddr);
	obj->vtable = 0x820A6754u;
	if ((destroyFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, cAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return cAddr;
}
PROMOTED_ENTRY(74, sub_82A45F58, 0x82A45F58) { ctx.r3.u64 = C_820A6754_ListDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82A720C0  [104 bytes]
uint64_t C_820A6754_ReleaseHandles(CpuState& ctx, uint8_t* base, uint32_t cAddr) {
	if (!UseLiftedCode(76, 0x82A720C0)) { ctx.r3.u64 = cAddr; __imp__sub_82A720C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A720C0);
	uint32_t stack = ctx.r1.u64;
	C_820A6754* c = GameObject<C_820A6754>(base, cAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t handle94Field = cAddr + 0x90;
	uint32_t handle94 = c->m_94;
	if (handle94 != 0) {
		ctx.r1.u64 = stack;
		HandleTarget_Free(ctx, base, handle94);
	}
	STORE32(handle94Field + 4, 0);
	STORE32(handle94Field + 8, 0);
	STORE32(handle94Field + 12, 0);

	uint32_t handle84Field = cAddr + 0x80;
	uint64_t handle84 = c->m_84;
	if ((uint32_t)handle84 != 0) {
		ctx.r1.u64 = stack;
		handle84 = HandleTarget_Free(ctx, base, handle84);
	}
	STORE32(handle84Field + 4, 0);
	STORE32(handle84Field + 8, 0);
	STORE32(handle84Field + 12, 0);

	c->vtable = 0x820A6754u;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return handle84;
}
PROMOTED_ENTRY(76, sub_82A720C0, 0x82A720C0) { ctx.r3.u64 = C_820A6754_ReleaseHandles(ctx, base, ctx.r3.u32); }
