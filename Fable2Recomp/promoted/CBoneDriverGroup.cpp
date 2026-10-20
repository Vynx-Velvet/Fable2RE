// CBoneDriverGroup (vtable 0x82006438): methods of the class as readable C++.
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

// sub_821B3258  [8 bytes]
uint64_t CBoneDriverGroup_ApplyTransform(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroup, uint64_t transformAddr) {
	if (!UseLiftedCode(2, 0x821B3258)) { ctx.r3.u64 = boneDriverGroup; ctx.r5.u64 = transformAddr; __imp__sub_821B3258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821B3258);
	return CBoneDriverGroup_ApplyTransformToBoneDrivers(ctx, base, boneDriverGroup, transformAddr);
}
PROMOTED_ENTRY(2, sub_821B3258, 0x821B3258) { ctx.r3.u64 = CBoneDriverGroup_ApplyTransform(ctx, base, ctx.r3.u64, ctx.r5.u64); }

// Copies the 16 bytes at sourceAddr + 0x60 (where a CBoneDriverGroup keeps m_rotation) to the buffer
// at destAddr, as two 8-byte halves.
void CBoneDriverGroup_SetQuaternion(CpuState& ctx, uint8_t* base, uint32_t destAddr, uint32_t sourceAddr) {
	if (!UseLiftedCode(7, 0x82242518)) { ctx.r3.u64 = destAddr; ctx.r4.u64 = sourceAddr; __imp__sub_82242518(ctx, base); return; }
	LiftedFrame frame(0x82242518);
	uint64_t secondHalf = LOAD64(sourceAddr + 0x68);
	STORE64(destAddr, LOAD64(sourceAddr + 0x60));
	STORE64(destAddr + 8, secondHalf);
}
PROMOTED_ENTRY(7, sub_82242518, 0x82242518) { CBoneDriverGroup_SetQuaternion(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82272E28  [480 bytes]
// For each bone driver of the group: combines the transform at transformAddr (translation +0, rotation
// quaternion +16, scale +32) with the bone's 48-byte transform of the same layout (from the array that
// BoneData_GetTransforms provides) and hands the combined parts, with the object at +0x2C of the driver, to
// BoneDriver_Update. Then calls Skeleton_UpdateBones on m_98 when it is set.
uint64_t CBoneDriverGroup_ApplyTransformToBoneDrivers(CpuState& ctx, uint8_t* base, uint32_t boneDriverGroupAddr, uint64_t transformAddr) {
	constexpr int32_t g_82024280 = int32_t(0x82024280);
	if (!UseLiftedCode(9, 0x82272E28)) { ctx.r3.u64 = boneDriverGroupAddr; ctx.r4.u64 = transformAddr; __imp__sub_82272E28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82272E28);
	uint32_t stack = ctx.r1.u64;
	// the value the original keeps in r9: handed to callees and left for callers
	uint64_t r9Value = ctx.r9.u64;
	uint32_t r13Value = ctx.r13.u64;
	PPCVRegister local49{};
	PPCVRegister local50 = ctx.v1;
	PPCVRegister local51 = ctx.v2;
	PPCVRegister local52 = ctx.v3;
	PPCVRegister local53{};
	PPCVRegister local54{};
	PPCVRegister local55{};
	PPCVRegister local56{};
	PPCVRegister local57{};
	PPCVRegister local58{};
	PPCVRegister local59{};
	PPCVRegister local60{};
	PPCVRegister local61{};
	PPCVRegister local62{};
	PPCVRegister local63{};
	PPCVRegister local64 = ctx.v15;
	PPCVRegister local65 = ctx.v16;
	PPCVRegister local66 = ctx.v17;
	PPCVRegister local67 = ctx.v18;
	PPCVRegister local68 = ctx.v19;
	PPCVRegister local69 = ctx.v20;
	PPCVRegister local70 = ctx.v21;
	PPCVRegister local71 = ctx.v22;
	PPCVRegister local72 = ctx.v23;
	PPCVRegister local73 = ctx.v24;
	PPCVRegister local74 = ctx.v25;
	PPCVRegister local75 = ctx.v26;
	PPCVRegister local76 = ctx.v27;
	PPCVRegister local77 = ctx.v28;
	PPCVRegister local78 = ctx.v29;
	PPCVRegister local79 = ctx.v30;
	PPCVRegister local80 = ctx.v31;
	PPCVRegister local81{};
	PPCVRegister local82{};
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CBoneDriverGroup* boneDriverGroup = GameObject<CBoneDriverGroup>(base, boneDriverGroupAddr);
	stack = PushStackFrame(base, stack, 304);
	uint32_t transform = transformAddr;

	// Copy the shared handle {m_10, m_14} to stack+80 and atomically increment the count m_14 points to.
	uint32_t refCountPtr = boneDriverGroup->m_14;
	uint32_t driverData = boneDriverGroup->m_10;
	STORE32(stack + 84, refCountPtr);
	STORE32(stack + 80, driverData);
	if (refCountPtr != 0) {
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			r9Value = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = r13Value & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(refCountPtr);
			uint32_t refCount = __builtin_bswap32(ctx.reserved.u32);
			refCount = (int32_t)refCount + 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCountPtr)), ctx.reserved.s32, __builtin_bswap32((int32_t)refCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)r9Value & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
	}
	// state the callee may pass on
	ctx.r1.u64 = stack;
	uint32_t animData = BoneData_GetTransforms(ctx, base, driverData);
	uint64_t handleAddr = (int64_t)(uint64_t)stack + 80;
	SharedHandle_Release(ctx, base, handleAddr);
	r9Value = ctx.r9.u64;
	local50 = ctx.v1;
	local51 = ctx.v2;
	local52 = ctx.v3;
	flags.ca = ctx.xer.ca;

	const uint32_t constantPoolAddr = uint32_t(g_82024280);
	// Combined parts of the current bone, built on the stack.
	const uint64_t translationOutAddr = (int64_t)(uint64_t)stack + 96;
	const uint64_t rotationOutAddr = (int64_t)(uint64_t)stack + 112;
	const uint64_t scaleOutAddr = (int64_t)(uint64_t)stack + 128;
	const uint64_t rotationMatrixAddr = (int64_t)(uint64_t)stack + 144;
	uint32_t boneIndex = 0;
	uint32_t childOffset = 0;
	uint32_t boneTransformOffset = 0;
	while (true) {
		// bone drivers: 8-byte entries of [m_children, m_childrenEnd)
		uint32_t children = boneDriverGroup->m_children;
		uint32_t childCount = 0;
		if (children != 0) {
			r9Value = (uint64_t)boneDriverGroup->m_childrenEnd - children;
			flags.ca = (int32_t)r9Value < 0 & ((uint32_t)r9Value & 0x7) != 0;
			childCount = (int32_t)r9Value >> 3;
		}
		if (boneIndex == childCount) break;
		// bounds check (childCount is 0 for a null list)
		if (boneIndex >= childCount) ppc_trap(ctx, base, 22);

		uint32_t boneTransform = LOAD32(animData) + boneTransformOffset;
		SET_V8(local59, VLOAD(constantPoolAddr & ~0xF));
		SET_V8(local58, VLOAD(transform & ~0xF));
		SET_V8(local49, VLOAD(uint32_t((int32_t)transform + 16) & ~0xF));
		SET_V8(local61, simde_mm_shuffle_epi32(V8(local49), 0x0));
		SET_V8(local62, V8(local49));
		SET_V8(local57, VLOAD(boneTransform & ~0xF));
		SET_V8(local56, simde_mm_shuffle_epi32(V8(local49), 0x78));
		ctx.fpscr.enableFlushMode();
		SET_VF(local55, simde_mm_dp_ps(VF(local49), VF(local57), 0xEF));
		SET_V8(local54, simde_mm_shuffle_epi32(V8(local49), 0x9C));
		SET_V8(local53, simde_mm_shuffle_epi32(V8(local57), 0x9C));
		SET_VF(local52, simde_mm_add_ps(simde_mm_mul_ps(VF(local61), VF(local61)), VF(local59)));
		SET_V8(local51, simde_mm_shuffle_epi32(V8(local57), 0x78));
		SET_V8(local50, simde_mm_shuffle_epi32(V8(local62), 0x78));
		SET_V8(local80, simde_mm_shuffle_epi32(V8(local62), 0x9C));
		SET_VF(local79, simde_mm_mul_ps(VF(local56), VF(local53)));
		SET_V8(local60, simde_mm_shuffle_epi32(V8(local62), 0x0));
		SET_VF(local78, simde_mm_mul_ps(VF(local54), VF(local51)));
		SET_VF(local77, simde_mm_mul_ps(VF(local57), VF(local52)));
		SET_V8(local76, simde_mm_shuffle_epi32(V8(local55), 0xFF));
		SET_VF(local75, simde_mm_sub_ps(VF(local78), VF(local79)));
		SET_VF(local74, simde_mm_add_ps(simde_mm_mul_ps(VF(local76), VF(local49)), VF(local77)));
		SET_VF(local73, simde_mm_add_ps(simde_mm_mul_ps(VF(local75), VF(local61)), VF(local74)));
		SET_VF(local72, simde_mm_add_ps(VF(local73), VF(local73)));
		SET_VF(local61, simde_mm_add_ps(VF(local58), VF(local72)));
		// translation: the transform's translation plus the bone translation rotated by the transform's rotation
		VSTORE((uint32_t)translationOutAddr & ~0xF, V8(local61));
		SET_V8(local49, VLOAD(uint32_t((int32_t)boneTransform + 16) & ~0xF));
		SET_V8(local71, simde_mm_shuffle_epi32(V8(local49), 0x9C));
		SET_V8(local70, simde_mm_shuffle_epi32(V8(local49), 0x78));
		SET_VF(local69, simde_mm_dp_ps(VF(local62), VF(local49), 0xEF));
		SET_VF(local68, simde_mm_mul_ps(VF(local50), VF(local71)));
		ctx.fpscr.disableFlushModeUnconditional();
		double boneRotationW = double(LOAD_F32(boneTransform + 28));
		SET_V8(local59, simde_mm_shuffle_epi32(V8(local49), 0x0));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(local67, simde_mm_mul_ps(VF(local80), VF(local70)));
		// the dot product of the two rotations' vector parts goes through stack+80
		uint32_t dotSlotAddr = uint32_t((int64_t)(uint64_t)stack + 80) & ~0x3;
		STORE32(dotSlotAddr, local69.u32[3 - ((dotSlotAddr & 0xF) >> 2)]);
		SET_V8(local66, VLOAD((transform + 32u) & ~0xF));
		SET_VF(local65, simde_mm_sub_ps(VF(local67), VF(local68)));
		ctx.fpscr.disableFlushModeUnconditional();
		double combinedRotationW = double(float(std::fma(double(LOAD_F32(transform + 28)), boneRotationW, -double(LOAD_F32(stack + 80)))));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(local64, simde_mm_add_ps(simde_mm_mul_ps(VF(local49), VF(local60)), VF(local65)));
		SET_VF(local63, simde_mm_add_ps(simde_mm_mul_ps(VF(local62), VF(local59)), VF(local64)));
		// rotation: quaternion product of the transform's rotation and the bone rotation (w stored separately)
		VSTORE((uint32_t)rotationOutAddr & ~0xF, V8(local63));
		ctx.fpscr.disableFlushModeUnconditional();
		STORE_F32(stack + 124, float(combinedRotationW));
		SET_V8(local82, VLOAD((boneTransform + 32u) & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(local81, simde_mm_mul_ps(VF(local66), VF(local82)));
		// scale: component-wise product of the two scales
		VSTORE((uint32_t)scaleOutAddr & ~0xF, V8(local81));
		uint32_t boneDriver = LOAD32(childOffset + children);
		uint32_t driverObject = LOAD32(boneDriver + 44);
		VSTORE(uint32_t((int64_t)(uint64_t)stack + 192) & ~0xF, V8(local61));
		// state the callee may pass on
		hkRotation_SetFromQuaternion(ctx, base, (uint32_t)rotationMatrixAddr, (uint32_t)rotationOutAddr);
		// state the callee may pass on
		ctx.r4.u64 = rotationMatrixAddr;
		ctx.r5.u64 = scaleOutAddr;
		ctx.r6.u64 = rotationOutAddr;
		ctx.r7.u64 = translationOutAddr;
		ctx.r8.u64 = children;
		ctx.v1 = local50;
		ctx.v2 = local51;
		ctx.v3 = local52;
		ctx.v4 = local53;
		ctx.v5 = local54;
		ctx.v6 = local55;
		ctx.v7 = local56;
		ctx.v8 = local57;
		ctx.v9 = local58;
		ctx.v10 = local59;
		ctx.v11 = local60;
		ctx.xer.ca = flags.ca;
		BoneDriver_Update(ctx, base, driverObject);
		r9Value = ctx.r9.u64;
		local50 = ctx.v1;
		local51 = ctx.v2;
		local52 = ctx.v3;
		flags.ca = ctx.xer.ca;
		boneIndex = (int32_t)boneIndex + 1;
		boneTransformOffset = (int32_t)boneTransformOffset + 48;
		childOffset = (int32_t)childOffset + 8;
	}
	uint64_t result = boneDriverGroup->m_98;
	if ((uint32_t)result != 0) {
		// state the callee may pass on
		ctx.xer.ca = flags.ca;
		result = Skeleton_UpdateBones(ctx, base, result);
		r9Value = ctx.r9.u64;
	}
	stack = PopStackFrame(stack, 304);
	// registers callers read after the call
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Value;
	ctx.v15 = local64;
	ctx.v16 = local65;
	ctx.v17 = local66;
	ctx.v18 = local67;
	ctx.v19 = local68;
	ctx.v20 = local69;
	ctx.v21 = local70;
	ctx.v22 = local71;
	ctx.v23 = local72;
	ctx.v24 = local73;
	ctx.v25 = local74;
	ctx.v26 = local75;
	ctx.v27 = local76;
	ctx.v28 = local77;
	ctx.v29 = local78;
	ctx.v30 = local79;
	ctx.v31 = local80;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(9, sub_82272E28, 0x82272E28) { ctx.r3.u64 = CBoneDriverGroup_ApplyTransformToBoneDrivers(ctx, base, ctx.r3.u32, ctx.r4.u64); }

void CBoneDriverGroup_SetScaleVector(CpuState& ctx, uint8_t* base, uint32_t destination, uint32_t source) {
	if (!UseLiftedCode(13, 0x822D3F78)) { ctx.r3.u64 = destination; ctx.r4.u64 = source; __imp__sub_822D3F78(ctx, base); return; }
	LiftedFrame frame(0x822D3F78);
	PPCVRegister value{};
	SET_V8(value, VLOAD((source + 112u) & ~0xF));
	VSTORE(destination & ~0xF, V8(value));
	return;
}
PROMOTED_ENTRY(13, sub_822D3F78, 0x822D3F78) { CBoneDriverGroup_SetScaleVector(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CBoneDriverGroup_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(61, 0x828A16F0)) { ctx.r3.u64 = boneDriverGroupAddr; ctx.r4.u64 = deleteFlags; __imp__sub_828A16F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A16F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CBoneDriverGroup_Destructor(ctx, base, boneDriverGroupAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, boneDriverGroupAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return boneDriverGroupAddr;
}
PROMOTED_ENTRY(61, sub_828A16F0, 0x828A16F0) { ctx.r3.u64 = CBoneDriverGroup_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CBoneDriverGroup_Attach(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr, uint64_t newOwner) {
	if (!UseLiftedCode(61, 0x828A25A0)) { ctx.r3.u64 = boneDriverGroupAddr; ctx.r4.u64 = newOwner; __imp__sub_828A25A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A25A0);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CBoneDriverGroup* boneDriverGroup = GameObject<CBoneDriverGroup>(base, boneDriverGroupAddr);
	stack = PushStackFrame(base, stack, 128);
	// r3 and r4 as the last owner call left them: the return value, and r4 for callers
	uint64_t result = boneDriverGroupAddr;
	uint64_t r4AfterCall = newOwner;

	// Calls the new owner's virtual method at vtable offset 0x24 with one list entry.
	auto notifyOwner = [&](uint32_t entry) {
		uint32_t ownerVtable = LOAD32((uint32_t)newOwner);
		uint32_t notifyFn = LOAD32(ownerVtable + 0x24);
		callTarget.u64 = notifyFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = newOwner;
		ctx.r4.u64 = entry;
		ctx.r9.u64 = notifyFn;
		ctx.r10.u64 = ownerVtable;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r4AfterCall = ctx.r4.u64;
		flags.ca = ctx.xer.ca;
	};

	// Both lists hold 8-byte entries; each is re-measured before every call.
	for (uint32_t i = 0, offset = 0; ; ++i, offset += 8) {
		uint32_t children = boneDriverGroup->m_children;
		uint32_t count = 0;
		if (children != 0) {
			uint32_t size = (uint32_t)boneDriverGroup->m_childrenEnd - children;
			flags.ca = ((int32_t)size < 0) & ((size & 0x7) != 0);
			count = (uint32_t)((int32_t)size >> 3);
		}
		if (i == count) break;
		// bounds check (count is 0 for a null list)
		if (i >= count) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		notifyOwner(LOAD32(children + offset));
	}

	if (LOAD8(0x83496981u) != 0) {
		for (uint32_t i = 0, offset = 0; ; ++i, offset += 8) {
			uint32_t entries = boneDriverGroup->m_4C;
			uint32_t count = 0;
			if (entries != 0) {
				uint32_t size = (uint32_t)boneDriverGroup->m_50 - entries;
				flags.ca = ((int32_t)size < 0) & ((size & 0x7) != 0);
				count = (uint32_t)((int32_t)size >> 3);
			}
			if (i == count) break;
			// bounds check (count is 0 for a null list)
			if (i >= count) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			notifyOwner(LOAD32(entries + offset));
		}
	}

	boneDriverGroup->m_owner = (uint32_t)newOwner;
	stack = PopStackFrame(stack, 128);
	// callers read r4 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4AfterCall;
	return result;
}
PROMOTED_ENTRY(61, sub_828A25A0, 0x828A25A0) { ctx.r3.u64 = CBoneDriverGroup_Attach(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_828A2880  [4 bytes]
uint64_t CBoneDriverGroup_ResetAllDriversThunk(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroup) {
	if (!UseLiftedCode(61, 0x828A2880)) { ctx.r3.u64 = boneDriverGroup; __imp__sub_828A2880(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A2880);
	return CBoneDriverGroup_ResetAllDrivers(ctx, base, boneDriverGroup);
}
PROMOTED_ENTRY(61, sub_828A2880, 0x828A2880) { ctx.r3.u64 = CBoneDriverGroup_ResetAllDriversThunk(ctx, base, ctx.r3.u64); }

// sub_828A2888  [204 bytes]
// For each 8-byte driver entry of [m_children, m_childrenEnd), calls the driver's virtual methods at vtable
// offsets 76 and 80 with a zero vector in v1. Returns what the last call left in r3 (the group address when
// the list is empty).
uint64_t CBoneDriverGroup_ResetAllDrivers(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr) {
	if (!UseLiftedCode(61, 0x828A2888)) { ctx.r3.u64 = boneDriverGroupAddr; __imp__sub_828A2888(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A2888);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CBoneDriverGroup* boneDriverGroup = GameObject<CBoneDriverGroup>(base, boneDriverGroupAddr);
	// The original saves v127 below its frame and uses it as the zero vector; ctx.v127 itself is not changed.
	PPCVRegister savedV127 = ctx.v127;
	VSTORE((stack - 0x30u) & ~0xFu, V8(savedV127));
	stack = PushStackFrame(base, stack, 128);
	PPCVRegister zeroVector{};
	SET_V8(zeroVector, simde_mm_set1_epi32(int(0x0)));

	uint32_t driverSlot = boneDriverGroup->m_children;
	uint32_t endBound = boneDriverGroup->m_childrenEnd;
	uint32_t listEnd = boneDriverGroup->m_childrenEnd;
	if (driverSlot > endBound) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	if (driverSlot > listEnd) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint64_t result = boneDriverGroupAddr;
	// listEnd is read once; the bounds checks re-read m_childrenEnd after each call.
	for (; driverSlot != listEnd; driverSlot += 8) {
		if (driverSlot >= endBound) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		uint32_t driver = LOAD32(driverSlot);
		uint32_t vtableFn76 = LOAD32(LOAD32(driver) + 76);
		callTarget.u64 = vtableFn76;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = driver;
		ctx.r10.u64 = vtableFn76;
		ctx.v1 = zeroVector;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		endBound = boneDriverGroup->m_childrenEnd;
		if (driverSlot >= endBound) ppc_trap(ctx, base, 22);
		driver = LOAD32(driverSlot);
		uint32_t vtableFn80 = LOAD32(LOAD32(driver) + 80);
		callTarget.u64 = vtableFn80;
		ctx.r3.u64 = driver;
		ctx.r9.u64 = endBound;
		ctx.r10.u64 = vtableFn80;
		ctx.v1 = zeroVector;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;

		endBound = boneDriverGroup->m_childrenEnd;
		if (driverSlot >= endBound) ppc_trap(ctx, base, 22);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A2888, 0x828A2888) { ctx.r3.u64 = CBoneDriverGroup_ResetAllDrivers(ctx, base, ctx.r3.u64); }

// Calls the virtual function at vtable offset 0x2C on every child; children are 8-byte entries between
// m_children and m_childrenEnd. Returns r3 as the last child call left it (the group address when there are none).
uint64_t CBoneDriverGroup_ForEachChildVirtual44(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr) {
	if (!UseLiftedCode(61, 0x828A2C28)) { ctx.r3.u64 = boneDriverGroupAddr; __imp__sub_828A2C28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A2C28);
	uint32_t stack = ctx.r1.u64;
	CBoneDriverGroup* boneDriverGroup = GameObject<CBoneDriverGroup>(base, boneDriverGroupAddr);
	uint64_t result = boneDriverGroupAddr;
	uint64_t childBytes{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 112);
	uint32_t index = 0;
	uint32_t childOffset = 0;
	while (true) {
		uint32_t childCount = 0;
		uint32_t children = boneDriverGroup->m_children;
		if (children != 0) {
			childBytes = (uint64_t)(uint32_t)boneDriverGroup->m_childrenEnd - (uint64_t)children;
			flags.ca = ((int32_t)childBytes < 0) & (((uint32_t)childBytes & 0x7) != 0);
			childCount = (uint32_t)((int32_t)childBytes >> 3);
		}
		if (index == childCount) break;

		// bounds check against a fresh read of the array; on failure it traps and goes on
		children = boneDriverGroup->m_children;
		bool inBounds = false;
		if (children != 0) {
			childBytes = (uint64_t)(uint32_t)boneDriverGroup->m_childrenEnd - (uint64_t)children;
			flags.ca = ((int32_t)childBytes < 0) & (((uint32_t)childBytes & 0x7) != 0);
			inBounds = index < (uint32_t)((int32_t)childBytes >> 3);
		}
		if (!inBounds) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t child = LOAD32(childOffset + children);
		uint32_t virtualFn = LOAD32(LOAD32(child) + 44);
		callTarget.u64 = (uint64_t)virtualFn;
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r3.u64 = child;
		ctx.r9.u64 = childBytes;
		ctx.r10.u64 = virtualFn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		childBytes = ctx.r9.u64;
		flags.ca = ctx.xer.ca;
		index = index + 1;
		childOffset = childOffset + 8;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A2C28, 0x828A2C28) { ctx.r3.u64 = CBoneDriverGroup_ForEachChildVirtual44(ctx, base, ctx.r3.u64); }

// sub_828A2F68  [116 bytes]
uint64_t CBoneDriverGroup_SetBoneAnimation(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr, uint64_t boneData, uint64_t arg3, double floatArg1) {
	if (!UseLiftedCode(61, 0x828A2F68)) { ctx.r3.u64 = boneDriverGroupAddr; ctx.r4.u64 = boneData; ctx.r5.u64 = arg3; ctx.f1.f64 = floatArg1; __imp__sub_828A2F68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A2F68);
	uint32_t stack = ctx.r1.u64;
	CBoneDriverGroup* boneDriverGroup = GameObject<CBoneDriverGroup>(base, boneDriverGroupAddr);
	uint64_t result = boneDriverGroupAddr;
	uint64_t callerR4 = boneData;
	double callerF1 = floatArg1;

	stack = PushStackFrame(base, stack, 112);
	if (LOAD8(0x834BE89Bu) == 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		uint32_t sourceAddr = n_sub_82D5DB48(ctx, base, boneData);
		uint32_t value98 = boneDriverGroup->m_98;
		ctx.fpscr.disableFlushMode();
		uint32_t sourceValue = LOAD32(sourceAddr);
		result = Skeleton_ApplyBoneAnimation(ctx, base, value98, sourceValue, arg3, 0, floatArg1);
		callerR4 = ctx.r4.u64;
		callerF1 = ctx.f1.f64;
	}
	stack = PopStackFrame(stack, 112);
	// callers read r4 and f1 after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	ctx.f1.f64 = callerF1;
	return result;
}
PROMOTED_ENTRY(61, sub_828A2F68, 0x828A2F68) { ctx.r3.u64 = CBoneDriverGroup_SetBoneAnimation(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.f1.f64); }

// sub_828A2FE0  [148 bytes]
uint64_t CBoneDriverGroup_UpdateTransform(CpuState& ctx, uint8_t* base, uint64_t boneDriverGroupAddr) {
	if (!UseLiftedCode(61, 0x828A2FE0)) { ctx.r3.u64 = boneDriverGroupAddr; __imp__sub_828A2FE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A2FE0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 256);

	// Virtual function at vtable offset 0x20: receives stack+96 in r3, returns a pointer to a 16-byte vector.
	uint32_t vtable = LOAD32((uint32_t)boneDriverGroupAddr);
	callTarget.u64 = LOAD32(vtable + 0x20);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = (uint64_t)stack + 96;
	ctx.r4.u64 = boneDriverGroupAddr;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t vectorAddr = ctx.r3.u32;

	// Virtual function at vtable offset 0x24 (vtable re-read after the call): receives stack+80 in r3,
	// returns a pointer to the quaternion.
	vtable = LOAD32((uint32_t)boneDriverGroupAddr);
	callTarget.u64 = LOAD32(vtable + 0x24);
	ctx.r3.u64 = (uint64_t)stack + 80;
	ctx.r4.u64 = boneDriverGroupAddr;
	ctx.r8.u64 = callTarget.u64;
	ctx.r9.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t quatAddr = ctx.r3.u32;

	PPCVRegister vectorValue{};
	SET_V8(vectorValue, VLOAD(vectorAddr & ~0xF));
	uint64_t quatLo = LOAD64(quatAddr);
	uint64_t quatHi = LOAD64(quatAddr + 8);
	// the vector goes to Quat_ToMatrix4x4 in v1
	ctx.v1 = vectorValue;
	uint32_t matrix = stack + 112;
	double matrixF1 = Quat_ToMatrix4x4(ctx, base, matrix, quatLo, quatHi);

	// state the callee may pass on
	uint64_t converted = Matrix_ToTransform(ctx, base, (uint64_t)stack + 176, matrix);
	uint64_t result = CBoneDriverGroup_ApplyTransformToBoneDrivers(ctx, base, boneDriverGroupAddr, converted);

	stack = PopStackFrame(stack, 256);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(61, sub_828A2FE0, 0x828A2FE0) { ctx.r3.u64 = CBoneDriverGroup_UpdateTransform(ctx, base, ctx.r3.u64); }

// For each child (8-byte entries from the pointer at boneDriverGroup+0x3C to the one at boneDriverGroup+0x40) composes the parent
// transform that Transform_BuildFromSource writes at stack+112 from arg3 (translation, rotation quaternion, a third
// vector) with the child's rotation (virtual function at vtable offset 0x18) and position (offset 0x14), and
// writes a 48-byte record per child into the array whose address is the first word of what TransformBuffer_Initialize
// returns:
//   +0   parent translation + child position rotated by the parent quaternion
//        (2((q.v)q + (w*w - 0.5)v + w(q x v)); the vector at 0x82024280 holds -0.5 in every lane)
//   +16  parent quaternion * child quaternion (xyz from the vector math, w = qw*pw - q.p written at +28)
//   +32  the parent's third vector times the float at 0x820994C0 (1.0)
// The vector and float locals that start from ctx double as registers, as in the original: v1-v13 and
// f11-f13 are handed to the first virtual call on every pass, and r4, v1-v3, v16, v18-v23 and v25-v31 are
// left for callers. Returns what TransformBuffer_Initialize returned when there are no children, otherwise stack+128
// (the parent rotation in the released frame), as the original leaves r3.
uint64_t CBoneDriverGroup_ComposeChildTransforms(CpuState& ctx, uint8_t* base, uint32_t boneDriverGroup, uint64_t transformBuffer, uint64_t arg3) {
	constexpr int32_t g_82024280 = int32_t(0x82024280);
	if (!UseLiftedCode(61, 0x828A3078)) { ctx.r3.u64 = boneDriverGroup; ctx.r4.u64 = transformBuffer; ctx.r5.u64 = arg3; __imp__sub_828A3078(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828A3078);
	uint32_t stack = ctx.r1.u64;
	uint64_t result{};
	// values the first virtual call receives in r5, r6, r7 and r9; the original keeps them in those registers, so a
	// pass gets what the setup before the loop (r5 and r6 as received, r7 and r9 as TransformBuffer_Initialize left them),
	// the count check (r9) or the previous pass left there
	uint64_t passR5 = arg3;
	uint64_t passR6 = ctx.r6.u64;
	uint64_t passR7{};
	uint64_t passR9{};
	uint64_t returnR4 = transformBuffer;
	double productW = ctx.f11.f64;
	double rotationDot = ctx.f12.f64;
	double childRotW = ctx.f13.f64;
	double parentRotW{};
	PPCVRegister crossA = ctx.v1;
	PPCVRegister crossB = ctx.v2;
	PPCVRegister wSquaredMinusHalf = ctx.v3;
	PPCVRegister childRotZxy = ctx.v4;
	PPCVRegister parentRotYzx = ctx.v5;
	PPCVRegister parentRotZxy = ctx.v6;
	PPCVRegister dotRotPos = ctx.v7;
	PPCVRegister childRotYzx = ctx.v8;
	PPCVRegister childPosZxy = ctx.v9;
	PPCVRegister childPosYzx = ctx.v10;
	PPCVRegister minusHalf = ctx.v11;
	PPCVRegister childRotWSplat = ctx.v12;
	PPCVRegister parentRotWSplat = ctx.v13;
	PPCVRegister parentThird = ctx.v16;
	PPCVRegister productTerms = ctx.v18;
	PPCVRegister rotCrossA = ctx.v19;
	PPCVRegister rotCrossB = ctx.v20;
	PPCVRegister parentRotYzx2 = ctx.v21;
	PPCVRegister parentRotZxy2 = ctx.v22;
	PPCVRegister rotationDotSplat = ctx.v23;
	PPCVRegister rotatedPosition = ctx.v25;
	PPCVRegister halfRotated = ctx.v26;
	PPCVRegister rotatePartial = ctx.v27;
	PPCVRegister crossRotPos = ctx.v28;
	PPCVRegister dotRotPosSplat = ctx.v29;
	PPCVRegister scaledPosition = ctx.v30;
	PPCVRegister parentTranslation = ctx.v31;
	PPCVRegister factorVec{};
	PPCVRegister parentRotation{};
	PPCVRegister childPosition{};
	PPCVRegister thirdFactorSplat{};
	PPCVRegister childRotation{};
	PPCVRegister composedPosition{};
	PPCVRegister composedRotation{};
	PPCVRegister composedThird{};
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	// save the caller's v125-v127, which the original uses as scratch
	VSTORE((stack + 0xFFFFFF70u) & ~0xF, V8(ctx.v125));
	VSTORE((stack + 0xFFFFFF80u) & ~0xF, V8(ctx.v126));
	VSTORE((stack + 0xFFFFFF90u) & ~0xF, V8(ctx.v127));
	stack = PushStackFrame(base, stack, 384);
	uint32_t parentSource = arg3;
	ctx.r1.u64 = stack;
	result = TransformBuffer_Initialize(ctx, base, transformBuffer);
	passR7 = ctx.r7.u64;
	passR9 = ctx.r9.u64;
	uint32_t recordsHolder = result;
	uint32_t childList = (int32_t)boneDriverGroup + 56;
	ctx.fpscr.disableFlushMode();
	double thirdFactor = double(LOAD_F32(0x820994C0u));
	uint32_t index = 0;
	uint32_t childOffset = 0;
	uint32_t recordOffset = 0;
	while (true) {
		uint32_t childCount = 0;
		uint32_t children = LOAD32(childList + 4);
		if (children != 0) {
			passR9 = (uint64_t)LOAD32(childList + 8) - children;
			flags.ca = ((int32_t)passR9 < 0) & (((uint32_t)passR9 & 0x7) != 0);
			childCount = (uint32_t)((int32_t)passR9 >> 3);
		}
		if (index == childCount) break;

		// bounds check against a fresh read of the array; on failure it traps and goes on
		children = LOAD32(childList + 4);
		bool inRange = false;
		if (children != 0) {
			uint32_t childBytes = (uint64_t)LOAD32(childList + 8) - children;
			flags.ca = ((int32_t)childBytes < 0) & ((childBytes & 0x7) != 0);
			inRange = index < uint32_t((int32_t)childBytes >> 3);
		}
		if (!inRange) ppc_trap(ctx, base, 22);

		// child rotation: receives stack+208 in r3, returns a pointer to the rotation
		uint32_t child = LOAD32(childOffset + children);
		uint64_t rotationBuf = (int64_t)(uint64_t)stack + 208;
		uint32_t rotationFn = LOAD32(LOAD32(child) + 24);
		callTarget.u64 = (uint64_t)rotationFn;
		// state the callee may pass on
		ctx.r3.u64 = rotationBuf;
		ctx.r4.u64 = child;
		ctx.r5.u64 = passR5;
		ctx.r6.u64 = passR6;
		ctx.r7.u64 = passR7;
		ctx.r9.u64 = passR9;
		ctx.r10.u64 = rotationFn;
		ctx.f11.f64 = productW;
		ctx.f12.f64 = rotationDot;
		ctx.f13.f64 = childRotW;
		ctx.v1 = crossA;
		ctx.v2 = crossB;
		ctx.v3 = wSquaredMinusHalf;
		ctx.v4 = childRotZxy;
		ctx.v5 = parentRotYzx;
		ctx.v6 = parentRotZxy;
		ctx.v7 = dotRotPos;
		ctx.v8 = childRotYzx;
		ctx.v9 = childPosZxy;
		ctx.v10 = childPosYzx;
		ctx.v11 = minusHalf;
		ctx.v12 = childRotWSplat;
		ctx.v13 = parentRotWSplat;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t childRotationPtr = ctx.r3.u64;
		crossA = ctx.v1;
		crossB = ctx.v2;
		wSquaredMinusHalf = ctx.v3;
		flags.ca = ctx.xer.ca;

		// child position: the child is re-read; the call gets the rotation (also copied to stack+96),
		// receives stack+224 in r3 and returns a pointer to the position
		child = LOAD32(childOffset + children);
		uint64_t rotationCopy = (int64_t)(uint64_t)stack + 96;
		uint64_t positionBuf = (int64_t)(uint64_t)stack + 224;
		uint32_t vtable = LOAD32(child);
		uint64_t rotationLo = LOAD64((uint32_t)childRotationPtr);
		uint64_t rotationHi = LOAD64((uint32_t)childRotationPtr + 8);
		uint32_t positionFn = LOAD32(vtable + 20);
		STORE64((uint32_t)rotationCopy, rotationLo);
		STORE64((uint32_t)rotationCopy + 8, rotationHi);
		callTarget.u64 = (uint64_t)positionFn;
		// state the callee may pass on
		ctx.r3.u64 = positionBuf;
		ctx.r4.u64 = child;
		ctx.r5.u64 = rotationHi;
		ctx.r6.u64 = rotationLo;
		ctx.r7.u64 = vtable;
		ctx.r8.u64 = rotationCopy;
		ctx.r9.u64 = childRotationPtr;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t childPositionPtr = ctx.r3.u64;
		flags.ca = ctx.xer.ca;

		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 192, float(thirdFactor));
		passR7 = (int64_t)(uint64_t)stack + 192;
		passR6 = childPositionPtr;
		SET_V8(factorVec, VLOAD((stack + 192) & ~0xF));
		SET_V8(thirdFactorSplat, simde_mm_shuffle_epi32(V8(factorVec), 0xFF));
		SET_V8(childRotation, VLOAD((stack + 96) & ~0xF));
		uint32_t parentTransform = stack + 112;
		SET_V8(childPosition, VLOAD((uint32_t)childPositionPtr & ~0xF));
		uint32_t record = recordOffset + LOAD32(recordsHolder);
		VSTORE((stack + 176) & ~0xF, V8(childRotation));
		VSTORE((stack + 192) & ~0xF, V8(thirdFactorSplat));
		Transform_BuildFromSource(ctx, base, parentTransform, parentSource);

		// record +0: parent translation + child position rotated by the parent quaternion
		passR5 = (int64_t)(uint64_t)stack + 128;
		SET_V8(minusHalf, VLOAD(uint32_t(g_82024280) & ~0xF));
		SET_V8(childPosYzx, simde_mm_shuffle_epi32(V8(childPosition), 0x9C));
		returnR4 = (int64_t)(uint64_t)stack + 112;
		SET_V8(childPosZxy, simde_mm_shuffle_epi32(V8(childPosition), 0x78));
		result = (int64_t)(uint64_t)stack + 128;
		SET_V8(childRotYzx, simde_mm_shuffle_epi32(V8(childRotation), 0x9C));
		SET_V8(childRotZxy, simde_mm_shuffle_epi32(V8(childRotation), 0x78));
		passR9 = (int64_t)(uint64_t)stack + 144;
		SET_V8(parentRotation, VLOAD((stack + 128) & ~0xF));
		SET_V8(childRotWSplat, simde_mm_shuffle_epi32(V8(childRotation), 0x0));
		SET_V8(parentRotWSplat, simde_mm_shuffle_epi32(V8(parentRotation), 0x0));
		ctx.fpscr.enableFlushMode();
		SET_VF(dotRotPos, simde_mm_dp_ps(VF(parentRotation), VF(childPosition), 0xEF));
		SET_V8(parentRotZxy, simde_mm_shuffle_epi32(V8(parentRotation), 0x78));
		SET_V8(parentTranslation, VLOAD((stack + 112) & ~0xF));
		SET_V8(parentRotYzx, simde_mm_shuffle_epi32(V8(parentRotation), 0x9C));
		index = index + 1;
		SET_VF(wSquaredMinusHalf, simde_mm_add_ps(simde_mm_mul_ps(VF(parentRotWSplat), VF(parentRotWSplat)), VF(minusHalf)));
		childOffset = childOffset + 8;
		SET_VF(crossB, simde_mm_mul_ps(VF(parentRotZxy), VF(childPosYzx)));
		recordOffset = recordOffset + 48;
		SET_VF(crossA, simde_mm_mul_ps(VF(parentRotYzx), VF(childPosZxy)));
		SET_VF(scaledPosition, simde_mm_mul_ps(VF(childPosition), VF(wSquaredMinusHalf)));
		SET_V8(dotRotPosSplat, simde_mm_shuffle_epi32(V8(dotRotPos), 0xFF));
		SET_VF(crossRotPos, simde_mm_sub_ps(VF(crossA), VF(crossB)));
		SET_VF(rotatePartial, simde_mm_add_ps(simde_mm_mul_ps(VF(dotRotPosSplat), VF(parentRotation)), VF(scaledPosition)));
		SET_VF(halfRotated, simde_mm_add_ps(simde_mm_mul_ps(VF(crossRotPos), VF(parentRotWSplat)), VF(rotatePartial)));
		SET_VF(rotatedPosition, simde_mm_add_ps(VF(halfRotated), VF(halfRotated)));
		SET_VF(composedPosition, simde_mm_add_ps(VF(parentTranslation), VF(rotatedPosition)));
		VSTORE(record & ~0xF, V8(composedPosition));

		// record +16: parent quaternion * child quaternion
		ctx.fpscr.disableFlushModeUnconditional();
		parentRotW = double(LOAD_F32(stack + 140));
		SET_V8(parentRotation, VLOAD((stack + 128) & ~0xF));
		SET_V8(parentRotZxy2, simde_mm_shuffle_epi32(V8(parentRotation), 0x78));
		SET_V8(parentRotYzx2, simde_mm_shuffle_epi32(V8(parentRotation), 0x9C));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(rotCrossB, simde_mm_mul_ps(VF(parentRotZxy2), VF(childRotYzx)));
		SET_VF(rotationDotSplat, simde_mm_dp_ps(VF(parentRotation), VF(childRotation), 0xEF));
		SET_V8(parentRotWSplat, simde_mm_shuffle_epi32(V8(parentRotation), 0x0));
		SET_VF(rotCrossA, simde_mm_mul_ps(VF(parentRotYzx2), VF(childRotZxy)));
		uint32_t dotSpill = uint32_t((int64_t)(uint64_t)stack + 80) & ~0x3;
		STORE32(dotSpill, rotationDotSplat.u32[3 - ((dotSpill & 0xF) >> 2)]);
		SET_VF(productTerms, simde_mm_sub_ps(VF(rotCrossA), VF(rotCrossB)));
		ctx.fpscr.disableFlushModeUnconditional();
		childRotW = double(LOAD_F32(stack + 188));
		rotationDot = double(LOAD_F32(stack + 80));
		productW = double(float(std::fma(childRotW, parentRotW, -rotationDot)));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(productTerms, simde_mm_add_ps(simde_mm_mul_ps(VF(childRotation), VF(parentRotWSplat)), VF(productTerms)));
		SET_VF(composedRotation, simde_mm_add_ps(simde_mm_mul_ps(VF(parentRotation), VF(childRotWSplat)), VF(productTerms)));
		VSTORE(uint32_t((int32_t)record + 16) & ~0xF, V8(composedRotation));
		ctx.fpscr.disableFlushModeUnconditional();
		STORE_F32(record + 28, float(productW));

		// record +32: the parent's third vector times the constant factor
		SET_V8(parentThird, VLOAD((stack + 144) & ~0xF));
		ctx.fpscr.enableFlushModeUnconditional();
		SET_VF(composedThird, simde_mm_mul_ps(VF(parentThird), VF(thirdFactorSplat)));
		VSTORE((record + 32) & ~0xF, V8(composedThird));
	}
	stack = PopStackFrame(stack, 384);
	// callers read r4 and these vector registers after the call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = returnR4;
	ctx.v1 = crossA;
	ctx.v2 = crossB;
	ctx.v3 = wSquaredMinusHalf;
	ctx.v16 = parentThird;
	ctx.v18 = productTerms;
	ctx.v19 = rotCrossA;
	ctx.v20 = rotCrossB;
	ctx.v21 = parentRotYzx2;
	ctx.v22 = parentRotZxy2;
	ctx.v23 = rotationDotSplat;
	ctx.v25 = rotatedPosition;
	ctx.v26 = halfRotated;
	ctx.v27 = rotatePartial;
	ctx.v28 = crossRotPos;
	ctx.v29 = dotRotPosSplat;
	ctx.v30 = scaledPosition;
	ctx.v31 = parentTranslation;
	return result;
}
PROMOTED_ENTRY(61, sub_828A3078, 0x828A3078) { ctx.r3.u64 = CBoneDriverGroup_ComposeChildTransforms(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }
