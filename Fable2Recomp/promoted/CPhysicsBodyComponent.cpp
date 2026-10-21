// CPhysicsBodyComponent (vtable 0x82006818): methods of the class as readable C++.
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

uint64_t CPhysicsBodyComponent_GetPosition(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint64_t targetEntity) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(2, 0x821BD650)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = targetEntity; __imp__sub_821BD650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821BD650);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);
	// walk the global manager chain down to the vtable holding the physics interface
	uint32_t physicsManager = LOAD32(uint32_t(g_83490000) + 0x6920);
	uint32_t managerSlot = LOAD32(physicsManager + 0x0C);
	uint32_t world = LOAD32(managerSlot + 0x58);
	uint32_t worldSlot = LOAD32(world + 0x04);
	uint32_t bodyInterface = LOAD32(worldSlot + 0x18);
	uint32_t bodyInterfaceVtable = LOAD32(bodyInterface);
	uint32_t getPhysicsBody = LOAD32(bodyInterfaceVtable + 0x58);
	callTarget.u64 = getPhysicsBody;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = bodyInterface;
	ctx.r4.u64 = targetEntity;
	ctx.r6.u64 = getPhysicsBody;
	ctx.r7.u64 = bodyInterfaceVtable;
	ctx.r8.u64 = worldSlot;
	ctx.r9.u64 = world;
	ctx.r10.u64 = managerSlot;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t physicsBody = ctx.r3.u32;
	uint32_t body = physicsBodyComponent->m_Body;
	uint32_t physicsBodyVtable = LOAD32(physicsBody);
	uint32_t setBody = LOAD32(physicsBodyVtable + 0x20);
	callTarget.u64 = setBody;
	ctx.r4.u64 = targetEntity;
	ctx.r5.u64 = body;
	ctx.r10.u64 = setBody;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(2, sub_821BD650, 0x821BD650) { ctx.r3.u64 = CPhysicsBodyComponent_GetPosition(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_821D9558  [40 bytes]
uint64_t CPhysicsBodyComponent_IsActive(CpuState& ctx, uint8_t* base, uint64_t component) {
	if (!UseLiftedCode(3, 0x821D9558)) { ctx.r3.u64 = component; __imp__sub_821D9558(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821D9558);
	uint32_t componentAddr = (uint32_t)component;
	if (LOAD32(componentAddr + 0x20) == 4) {
		uint32_t subObject = LOAD32(componentAddr + 0x38);
		uint32_t method = LOAD32(LOAD32(subObject) + 0x34);
		ctx.r3.u64 = subObject;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(method);
		return ctx.r3.u64;
	}
	return 1;
}
PROMOTED_ENTRY(3, sub_821D9558, 0x821D9558) { ctx.r3.u64 = CPhysicsBodyComponent_IsActive(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyComponent_GetBodyEntity(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr) {
	if (!UseLiftedCode(7, 0x82241448)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_82241448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82241448);
	uint32_t subObject = LOAD32((uint32_t)physicsBodyComponentAddr + 56);
	if (subObject == 0) return subObject;
	uint32_t virtualFn = LOAD32(LOAD32(subObject) + 8);
	ctx.r3.u64 = subObject;
	ctx.r10.u64 = virtualFn;
	REX_CALL_INDIRECT_FUNC(virtualFn);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(7, sub_82241448, 0x82241448) { ctx.r3.u64 = CPhysicsBodyComponent_GetBodyEntity(ctx, base, ctx.r3.u64); }

// sub_8227D8B8  [208 bytes]
uint32_t CPhysicsBodyComponent_RefreshAttachments(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr) {
	if (!UseLiftedCode(10, 0x8227D8B8)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_8227D8B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8227D8B8);
	uint32_t casAddr{};
	uint32_t stack = ctx.r1.u64;
	uint64_t savedLockState = ctx.r9.u64;
	uint32_t lockTls = ctx.r13.u32;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 128);
	if (physicsBodyComponent->m_18 != 0) {
		// Copy the shared handle at 0x10 (object + refcount) onto the stack, taking a reference.
		uint32_t handleAObject = physicsBodyComponent->m_10;
		uint32_t handleARefCount = physicsBodyComponent->m_14;
		STORE32(stack + 92, handleARefCount);
		STORE32(stack + 88, handleAObject);
		if (handleARefCount != 0) {
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				savedLockState = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockTls & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(handleARefCount);
				uint32_t newRefCount = __builtin_bswap32(ctx.reserved.u32);
				newRefCount = (int32_t)newRefCount + 1;
				casAddr = handleARefCount;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
				compare0.so = flags.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)savedLockState & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
		}
		ctx.r1.u64 = stack;
		uint32_t handleAObjectData = TransformBuffer_Initialize(ctx, base, handleAObject);
		// Copy the shared handle at 0x8 (object + refcount) onto the stack, taking a reference.
		uint32_t handleBRefCount = physicsBodyComponent->m_C;
		uint32_t bodyAux = physicsBodyComponent->m_1C;
		uint32_t handleBObject = physicsBodyComponent->m_8;
		uint32_t handleAObjectData0 = LOAD32(handleAObjectData);
		STORE32(stack + 84, handleBRefCount);
		uint32_t bodyAuxSub = LOAD32(bodyAux + 8);
		STORE32(stack + 80, handleBObject);
		// The value handed to the callee in r9: the incremented reference count, or the
		// value read above when no reference was taken.
		uint32_t refCountValue = bodyAux;
		if (handleBRefCount != 0) {
			do {
				std::atomic_thread_fence(std::memory_order_seq_cst);
				uint64_t savedLockState2 = REX_CHECK_GLOBAL_LOCK();
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = lockTls & 0x8020 | ctx.msr & ~0x8020;
				REX_ENTER_GLOBAL_LOCK();
				ctx.reserved.u32 = *(uint32_t*)RAW(handleBRefCount);
				refCountValue = __builtin_bswap32(ctx.reserved.u32);
				refCountValue = (int64_t)refCountValue + 1;
				casAddr = handleBRefCount;
				compare0.lt = 0;
				compare0.gt = 0;
				compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(casAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)refCountValue));
				compare0.so = flags.so;
				std::atomic_thread_fence(std::memory_order_seq_cst);
				ctx.msr = (uint32_t)savedLockState2 & 0x8020 | ctx.msr & ~0x8020;
				REX_LEAVE_GLOBAL_LOCK();
			} while (!compare0.eq);
		}
		uint32_t handleBObjectData = BoneData_GetTransforms(ctx, base, handleBObject);
		uint32_t targetType = 2;
		uint32_t bodyAuxSub14 = LOAD32(bodyAuxSub + 20);
		uint32_t handleBObjectData0 = LOAD32(handleBObjectData);
		n_sub_82D5FE98(ctx, base, physicsBodyComponent->m_18, handleBObjectData0, bodyAuxSub14, handleAObjectData0, targetType);
		SharedHandle_Release(ctx, base, stack + 80);
		physicsBodyComponentAddr = SharedHandle_Release(ctx, base, stack + 88);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return physicsBodyComponentAddr;
}
PROMOTED_ENTRY(10, sub_8227D8B8, 0x8227D8B8) { ctx.r3.u64 = CPhysicsBodyComponent_RefreshAttachments(ctx, base, ctx.r3.u32); }

uint64_t CPhysicsBodyComponent_QueryPhysicsObject(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint64_t query) {
	if (!UseLiftedCode(12, 0x822B7D80)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = query; __imp__sub_822B7D80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B7D80);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t queryTarget = LOAD32((uint32_t)query + 124);
	uint32_t queryFn = LOAD32(LOAD32(queryTarget) + 92);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)queryFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = queryTarget;
	ctx.r4.u64 = query;
	ctx.r10.u64 = queryFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t physicsObject = ctx.r3.u32;
	if (physicsObject != 0) {
		uint32_t body = physicsBodyComponent->m_Body;
		uint32_t setBodyFn = LOAD32(LOAD32(physicsObject) + 88);
		callTarget.u64 = (uint64_t)setBodyFn;
		ctx.r4.u64 = body;
		ctx.r10.u64 = setBodyFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(12, sub_822B7D80, 0x822B7D80) { ctx.r3.u64 = CPhysicsBodyComponent_QueryPhysicsObject(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsBodyComponent_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(49, 0x82738BD0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82738BD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82738BD0);
	uint32_t stack = ctx.r1.u64;
	uint64_t object = arg1;
	uint32_t deleteFlags = arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CPhysicsBodyComponent_Destructor(ctx, base, arg1);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(49, sub_82738BD0, 0x82738BD0) { ctx.r3.u64 = CPhysicsBodyComponent_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhysicsBodyComponent_Destroy(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr) {
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t g_834A0000 = int32_t(0x834A0000);
	if (!UseLiftedCode(49, 0x82739358)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_82739358(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739358);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 128);

	uint64_t componentAddr = physicsBodyComponentAddr;
	uint64_t result = componentAddr;

	if (physicsBodyComponent->m_Body != 0) {
		if (LOAD8(0x83496AC0u) != 0) {
			// Verbose path: make a temporary handle out of the component's entity handle,
			// hand it to the debug listener and release the temporary again.
			uint32_t listenerArgSlot = stack + 80;
			uint32_t handleSlot = stack + 88;
			uint64_t sourceHandle = componentAddr + 72;
			STORE32(listenerArgSlot, (uint32_t)componentAddr);
			STORE32(handleSlot, (uint32_t)g_820F1664);
			STORE32(handleSlot + 4, 0);
			ctx.r1.u64 = stack;
			EntityHandle_SetTarget(ctx, base, handleSlot, sourceHandle);

			int32_t listenerVtableBase = g_834A0000;
			uint32_t listenerId = 4;
			uint64_t listener = (int64_t)listenerVtableBase - 28824;
			STORE32(stack + 96, listenerId);
			ctx.r7.u64 = listenerId;
			uint64_t listenerHandle = n_sub_8273A3A8(ctx, base, listenerArgSlot);

			EntityHandle_Assign_827392E0(ctx, base, listenerHandle, handleSlot);

			int32_t handleVtableBase = g_820F0000;
			uint64_t handleVtable = (int64_t)handleVtableBase + 5732;
			STORE32(handleSlot, (uint32_t)handleVtable);
			uint64_t released = EntityHandle_Release(ctx, base, handleSlot);

			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return released;
		}

		uint32_t vtable = physicsBodyComponent->vtable;
		uint32_t debugListener = LOAD32((uint32_t)g_83490000 + 26912);
		uint32_t onEntityChanged = LOAD32(vtable + 20);
		uint32_t entityManager = LOAD32(debugListener + 12);
		uint32_t entityList = LOAD32(entityManager + 88);
		uint32_t entityEntry = LOAD32(entityList + 4);
		uint32_t entityHandle = LOAD32(entityEntry + 24);

		PPCRegister callTarget{};
		callTarget.u64 = (uint64_t)onEntityChanged;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = componentAddr;
		ctx.r4.u64 = entityHandle;
		ctx.r6.u64 = entityEntry;
		ctx.r7.u64 = entityList;
		ctx.r8.u64 = entityManager;
		ctx.r9.u64 = onEntityChanged;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		result = n_sub_82522A78(ctx, base, physicsBodyComponent->m_Body, physicsBodyComponent->m_51);

		if (physicsBodyComponent->m_51 != 0) {
			uint32_t itemList = LOAD32((uint32_t)physicsBodyComponent->m_18 + 8);
			uint32_t itemCount = LOAD32(itemList + 16);
			if (itemCount != 0) {
				uint32_t index = 0;
				do {
					uint32_t items = LOAD32(itemList + 12);
					uint32_t item = LOAD32(items + index * 4);
					STORE8(item + 4, 0);
					index++;
					itemCount = LOAD32(itemList + 16);
				} while (index != itemCount);
			}
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(49, sub_82739358, 0x82739358) { ctx.r3.u64 = CPhysicsBodyComponent_Destroy(ctx, base, ctx.r3.u64); }

// sub_82739620  [16 bytes]
uint64_t n_sub_82739620(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t arg2) {
	if (!UseLiftedCode(49, 0x82739620)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; __imp__sub_82739620(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739620);
	uint32_t nextBody = LOAD32((uint32_t)physicsBodyComponentAddr + 56);
	if (nextBody == 0) {
		// callers read r4 after the call
		ctx.r4.u64 = arg2;
		return 0;
	}
	return n_sub_82521DA8(ctx, base, nextBody, arg2);
}
PROMOTED_ENTRY(49, sub_82739620, 0x82739620) { ctx.r3.u64 = n_sub_82739620(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82739638  [16 bytes]
uint64_t n_sub_82739638(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t arg2, uint32_t arg3) {
	if (!UseLiftedCode(49, 0x82739638)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82739638(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739638);
	uint32_t body = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr)->m_Body;
	if (body == 0) {
		// callers read r4 after the call
		ctx.r4.u64 = arg2;
		return 0;
	}
	return n_sub_82521EA0(ctx, base, body, arg2, arg3);
}
PROMOTED_ENTRY(49, sub_82739638, 0x82739638) { ctx.r3.u64 = n_sub_82739638(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_82739650(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3, double floatArg1) {
	constexpr uint32_t g_83330000 = 0x83330000;
	if (!UseLiftedCode(49, 0x82739650)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.f1.f64 = floatArg1; __imp__sub_82739650(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739650);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	uint32_t physicsBody = (uint32_t)arg1;
	uint32_t entity = (uint32_t)arg2;
	uint32_t bodyNode = LOAD32(physicsBody + 0x38);
	uint64_t stackFlagAddr = (uint64_t)stack + 80;

	if (bodyNode != 0) {
		if (LOAD8(physicsBody + 0x50) == 0) {
			ctx.r1.u64 = stack;
			arg1 = n_sub_82522098(ctx, base, bodyNode, entity, arg3, floatArg1);
			arg2 = ctx.r4.u64;
			floatArg1 = ctx.f1.f64;
		} else if (LOAD8(bodyNode + 0x118) != 0) {

			uint32_t globalObject = LOAD32(g_83330000 + 29792);
			STORE8(stack + 80, 0);
			uint32_t vtable = LOAD32(globalObject);
			uint32_t setFlag = LOAD32(vtable + 16);
			ctx.r1.u64 = stack;
			ctx.r3.u64 = globalObject;
			ctx.r4.u64 = 0x1FF88F0E;
			ctx.r5.u64 = 0;
			ctx.r8.u64 = setFlag;
			ctx.r9.u64 = vtable;
			ctx.r10.u64 = 0;
			ctx.f1.f64 = floatArg1;
			REX_CALL_INDIRECT_FUNC(setFlag);
			floatArg1 = ctx.f1.f64;

			uint32_t someObject = (uint32_t)n_sub_82D5DB48(ctx, base, entity);
			uint32_t nodeField = LOAD32(bodyNode + 0x2C);
			uint32_t objectValue = LOAD32(someObject);
			ctx.r7.u64 = someObject;
			n_sub_82E67E98(ctx, base, nodeField, objectValue);
			floatArg1 = ctx.f1.f64;

			uint32_t globalObject2 = LOAD32(g_83330000 + 29792);
			STORE8(stack + 80, 1);
			uint32_t setFlag2 = LOAD32(LOAD32(globalObject2) + 16);
			uint32_t flagValue = LOAD8((uint32_t)stackFlagAddr);
			ctx.r3.u64 = globalObject2;
			ctx.r4.u64 = 0x1FF88F0E;
			ctx.r5.u64 = flagValue;
			ctx.r6.u64 = stackFlagAddr;
			ctx.r10.u64 = setFlag2;
			ctx.f1.f64 = floatArg1;
			REX_CALL_INDIRECT_FUNC(setFlag2);
			floatArg1 = ctx.f1.f64;

			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return ctx.r3.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	ctx.f1.f64 = floatArg1;
	return arg1;
}
PROMOTED_ENTRY(49, sub_82739650, 0x82739650) { ctx.r3.u64 = n_sub_82739650(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.f1.f64); }

uint64_t n_sub_82739718(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t arg2, uint32_t arg3) {
	if (!UseLiftedCode(49, 0x82739718)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82739718(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739718);
	uint32_t stack = ctx.r1.u64;
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = physicsBodyComponentAddr;
	uint32_t body = physicsBodyComponent->m_Body;
	if (body != 0) {
		ctx.r1.u64 = stack;
		uint32_t object = TransformBuffer_Initialize(ctx, base, arg2);
		uint32_t bodyField2C = LOAD32(body + 0x2C);
		uint32_t objectFirstWord = LOAD32(object);
		result = n_sub_82E675D8(ctx, base, bodyField2C, objectFirstWord, arg3);
		arg2 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = arg2;
	return result;
}
PROMOTED_ENTRY(49, sub_82739718, 0x82739718) { ctx.r3.u64 = n_sub_82739718(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_82739770(CpuState& ctx, uint8_t* base, uint64_t objectAddress) {
	if (!UseLiftedCode(49, 0x82739770)) { ctx.r3.u64 = objectAddress; __imp__sub_82739770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739770);
	return LOAD8((uint32_t)objectAddress + 0x52);
}
PROMOTED_ENTRY(49, sub_82739770, 0x82739770) { ctx.r3.u64 = n_sub_82739770(ctx, base, ctx.r3.u64); }

// sub_82739778  [576 bytes]
uint64_t CPhysicsBodyComponent_CreateRagdoll(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t arg2, uint64_t transform, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint32_t map) {
	constexpr int32_t str_TXT_820CA624_B_ = int32_t(0x820CA624);
	constexpr int32_t g_833375D4 = int32_t(0x833375D4);
	constexpr int32_t g_8333B4A8 = int32_t(0x8333B4A8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(49, 0x82739778)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = transform; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; ctx.r9.u64 = map; __imp__sub_82739778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739778);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	PPCVRegister vectorValue{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 288);

	// Scratch space inside the frame
	uint32_t physicsFileIdAddr = stack + 80;
	uint32_t quaternionAddr = stack + 96;
	uint32_t vectorAddr = stack + 112;
	uint32_t matrixAddr = stack + 128;

	uint64_t physicsFileName = str_TXT_820CA624_B_;
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.r8.u64 = arg6;
	GameDB_GetPropertyByName(ctx, base, physicsFileIdAddr, transform, physicsFileName);

	// m_60 = (incremented global counter << 31) + the 32-bit value the call above stored
	uint32_t counterAddr = (uint32_t)g_83490000 + 27480;
	uint64_t counter = (uint64_t)LOAD32(counterAddr) + 1;
	STORE32(counterAddr, (uint32_t)counter);
	physicsBodyComponent->m_60 = ((uint64_t)(uint32_t)counter << 31) + (uint64_t)LOAD32(physicsFileIdAddr);

	uint64_t sourceType = g_8333B4A8;
	uint64_t sourceTypeDescriptor = ReadU32(ctx, base, sourceType);
	uint64_t sourceObject = ComponentQuery_FindByHash(ctx, base, arg2, sourceTypeDescriptor, 0);

	uint64_t pairType = g_833375D4;
	uint64_t pairTypeDescriptor = ReadU32(ctx, base, pairType);
	uint32_t firstOfType = ComponentQuery_FindByHash(ctx, base, arg2, pairTypeDescriptor, 0);
	uint64_t pairTypeDescriptor2 = ReadU32(ctx, base, pairType);
	uint32_t nextOfType = ComponentQuery_FindByHash(ctx, base, arg2, pairTypeDescriptor2, firstOfType);

	uint32_t firstOfTypeWord8 = LOAD32(firstOfType + 8);
	uint32_t sourceObjectWord44 = LOAD32((uint32_t)sourceObject + 44);
	// Which one goes to CPhysicsBodyComponent_SetRagdollSource and which to CPhysicsBodyComponent_SetRagdollAttachment depends on this match.
	uint32_t argFor11B8;
	uint32_t argFor1258;
	if (firstOfTypeWord8 == sourceObjectWord44) {
		argFor11B8 = nextOfType;
		argFor1258 = firstOfType;
	} else {
		argFor11B8 = firstOfType;
		argFor1258 = nextOfType;
	}

	Transform_GetPositionAndRotation(ctx, base, vectorAddr, quaternionAddr, transform);
	Map_Find_823942A0(ctx, base, map, vectorAddr, quaternionAddr);

	uint32_t getRagdollSource = LOAD32(LOAD32((uint32_t)sourceObject) + 12);
	callTarget.u64 = getRagdollSource;
	ctx.r3.u64 = sourceObject;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = quaternionAddr;
	ctx.r10.u64 = getRagdollSource;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t ragdollSource = ctx.r3.u64;

	uint64_t ragdollEntity = 0;
	uint64_t allocated = operator_new(ctx, base, 288);
	if ((uint32_t)allocated != 0) {
		ragdollEntity = CPhysicsRagdollEntity_Construct(ctx, base, allocated, (uint32_t)ragdollSource);
	}
	// m_Body takes the new ragdoll entity
	uint64_t bodySlotAddr = physicsBodyComponentAddr + 56;
	SharedPtr_ResetWithPointerE(ctx, base, bodySlotAddr, ragdollEntity);

	STORE32(uint32_t(physicsBodyComponent->m_Body) + 272, uint32_t(physicsBodyComponent->m_6C));
	uint32_t bodyCollisionMask = physicsBodyComponent->m_70;
	STORE32(uint32_t(physicsBodyComponent->m_Body) + 276, bodyCollisionMask);

	// state the callee may pass on
	ctx.r8.u64 = bodyCollisionMask;
	CPhysicsBodyComponent_SetRagdollSource(ctx, base, physicsBodyComponentAddr, argFor11B8);
	CPhysicsBodyComponent_SetRagdollAttachment(ctx, base, physicsBodyComponentAddr, argFor1258);

	// state the callee may pass on
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = transform;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	n_sub_828A1018(ctx, base, physicsBodyComponentAddr);

	uint64_t quaternionLow = LOAD64(quaternionAddr);
	uint64_t quaternionHigh = LOAD64(quaternionAddr + 8);
	SET_V8(vectorValue, VLOAD(vectorAddr & ~0xFu));
	uint32_t body = physicsBodyComponent->m_Body;
	uint32_t bodyVtable = LOAD32(body);
	ctx.v1 = vectorValue;
	double convertF1 = Quat_ToMatrix4x4(ctx, base, matrixAddr, quaternionLow, quaternionHigh);
	uint32_t applyMatrix = LOAD32(bodyVtable + 16);
	callTarget.u64 = applyMatrix;
	ctx.r3.u64 = body;
	ctx.r4.u64 = matrixAddr;
	ctx.r6.u64 = applyMatrix;
	ctx.f1.f64 = convertF1;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// Release the reference held on ragdollSource: count at +6, counting enabled when the half-word at +4 is non-zero.
	uint32_t countsReferences = LOAD16((uint32_t)ragdollSource + 4);
	if (countsReferences != 0) {
		int32_t remaining = int16_t(LOAD16((uint32_t)ragdollSource + 6) - 1);
		STORE16((uint32_t)ragdollSource + 6, (uint16_t)remaining);
		if (remaining == 0) {
			uint32_t destroy = LOAD32(LOAD32((uint32_t)ragdollSource));
			callTarget.u64 = destroy;
			ctx.r3.u64 = ragdollSource;
			ctx.r4.u64 = 1;
			ctx.r5.u64 = countsReferences;
			ctx.r9.s64 = remaining;
			ctx.r10.u64 = destroy;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
		}
	}

	n_sub_82522790(ctx, base, LOAD32((uint32_t)bodySlotAddr), arg4, arg5);

	uint32_t ragdoll = LOAD32((uint32_t)bodySlotAddr);
	uint32_t method36 = LOAD32(LOAD32(ragdoll) + 36);
	callTarget.u64 = method36;
	ctx.r3.u64 = ragdoll;
	ctx.r4.u64 = arg6;
	ctx.r10.u64 = method36;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(49, sub_82739778, 0x82739778) { ctx.r3.u64 = CPhysicsBodyComponent_CreateRagdoll(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u32); }

uint64_t CPhysicsBodyComponent_LinkObject(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t linkedObject) {
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	if (!UseLiftedCode(49, 0x827399B8)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = linkedObject; __imp__sub_827399B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827399B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 96);

	uint64_t result = physicsBodyComponentAddr;
	uint64_t callerR4 = linkedObject;
	// Only the first object linked is kept in m_4; it is handed the body through its virtual slot 0x24.
	if (physicsBodyComponent->m_4 == 0) {
		physicsBodyComponent->m_4 = (uint32_t)linkedObject;
		uint32_t vtable = LOAD32((uint32_t)linkedObject);
		uint32_t body = physicsBodyComponent->m_Body;
		uint32_t linkBody = LOAD32(vtable + 0x24);
		callTarget.u64 = linkBody;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = linkedObject;
		ctx.r4.u64 = body;
		ctx.r10.u64 = linkBody;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		callerR4 = ctx.r4.u64;
	}

	uint32_t globalValue = LOAD32(uint32_t(g_83320000) - 27380);
	physicsBodyComponent->m_24 = uint8_t(1);
	physicsBodyComponent->m_74 = globalValue;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(49, sub_827399B8, 0x827399B8) { ctx.r3.u64 = CPhysicsBodyComponent_LinkObject(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CPhysicsBodyComponent_UnlinkObject(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr) {
	if (!UseLiftedCode(49, 0x82739B28)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_82739B28(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739B28);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);

	// The component address is handed to the callee through a stack slot.
	uint32_t componentSlot = stack + 80;
	STORE32(componentSlot, physicsBodyComponentAddr);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	n_sub_825F2208(ctx, base, componentSlot);
	uint64_t callerR4 = ctx.r4.u64;

	// The object linked in m_4 (see sub_827399B8) is handed the body through its virtual slot 0x28.
	uint64_t result = physicsBodyComponent->m_4;
	if ((uint32_t)result != 0) {
		uint32_t body = physicsBodyComponent->m_Body;
		callerR4 = body;
		if (body != 0) {
			uint32_t unlinkBody = LOAD32(LOAD32((uint32_t)result) + 40);
			callTarget.u64 = unlinkBody;
			ctx.r3.u64 = result;
			ctx.r4.u64 = body;
			ctx.r10.u64 = unlinkBody;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = ctx.r3.u64;
			callerR4 = ctx.r4.u64;
		}
	}
	physicsBodyComponent->m_4 = 0;
	physicsBodyComponent->m_24 = 0;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(49, sub_82739B28, 0x82739B28) { ctx.r3.u64 = CPhysicsBodyComponent_UnlinkObject(ctx, base, ctx.r3.u32); }

// sub_82739B98  [8 bytes]
uint64_t n_sub_82739B98(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr) {
	if (!UseLiftedCode(49, 0x82739B98)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_82739B98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739B98);
	uint32_t body = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr)->m_Body;
	return n_sub_82522598(ctx, base, body);
}
PROMOTED_ENTRY(49, sub_82739B98, 0x82739B98) { ctx.r3.u64 = n_sub_82739B98(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyComponent_SetBodyData(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint64_t bodyData) {
	if (!UseLiftedCode(49, 0x82739BA0)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = bodyData; __imp__sub_82739BA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739BA0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t sourceAddr = (uint32_t)bodyData;
	uint64_t body = physicsBodyComponent->m_Body;
	if ((uint32_t)body != 0) {
		uint32_t virtualFunc = LOAD32(LOAD32((uint32_t)body) + 40);
		callTarget.u64 = (uint64_t)virtualFunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = body;
		ctx.r4.u64 = bodyData;
		ctx.r10.u64 = virtualFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		body = ctx.r3.u64;
		bodyData = ctx.r4.u64;
	}

	uint32_t highWord = LOAD32(sourceAddr + 20);
	uint32_t lowWord = LOAD32(sourceAddr + 24);
	physicsBodyComponent->m_58 = ((uint64_t)highWord << 32) | (uint64_t)lowWord;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = bodyData;
	return body;
}
PROMOTED_ENTRY(49, sub_82739BA0, 0x82739BA0) { ctx.r3.u64 = CPhysicsBodyComponent_SetBodyData(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsBodyComponent_ReleaseBodyData(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr) {
	if (!UseLiftedCode(49, 0x82739C08)) { ctx.r3.u64 = physicsBodyComponentAddr; __imp__sub_82739C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739C08);
	uint32_t stack = ctx.r1.u64;
	uint32_t body{};
	uint32_t destroyBody{};
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 96);
	body = physicsBodyComponent->m_Body;
	if (body != 0) {
		destroyBody = LOAD32(LOAD32(body) + 44);
		callTarget.u64 = (uint64_t)destroyBody;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = body;
		ctx.r10.u64 = destroyBody;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		physicsBodyComponent->m_58 = (uint64_t)0;
		stack = PopStackFrame(stack, 96);
		ctx.r1.u64 = stack;
		return ctx.r3.u64;
	}
	physicsBodyComponent->m_58 = (uint64_t)0;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return body;
}
PROMOTED_ENTRY(49, sub_82739C08, 0x82739C08) { ctx.r3.u64 = CPhysicsBodyComponent_ReleaseBodyData(ctx, base, ctx.r3.u32); }

uint64_t CPhysicsBodyComponent_AttachBodyToComponent(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint64_t arg2) {
	if (!UseLiftedCode(49, 0x82739C70)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; __imp__sub_82739C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739C70);
	uint32_t stack = ctx.r1.u64;
	uint32_t otherComponentAddr{};
	uint32_t otherComponent{};
	uint32_t body{};
	uint32_t method{};
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);

	stack = PushStackFrame(base, stack, 96);

	otherComponentAddr = LOAD32((uint32_t)arg2 + 124);

	// otherComponent = otherComponentAddr->vtable[0x5c](otherComponentAddr, arg2)
	method = LOAD32(LOAD32(otherComponentAddr) + 92);
	callTarget.u64 = (uint64_t)method;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = otherComponentAddr;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	otherComponent = ctx.r3.u32;

	if (otherComponent != 0) {
		body = physicsBodyComponent->m_Body;
		// otherComponent->vtable[0x54](otherComponent, body)
		method = LOAD32(LOAD32(otherComponent) + 84);
		callTarget.u64 = (uint64_t)method;
		ctx.r4.u64 = body;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(49, sub_82739C70, 0x82739C70) { ctx.r3.u64 = CPhysicsBodyComponent_AttachBodyToComponent(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhysicsBodyComponent_SetState(CpuState& ctx, uint8_t* base, uint64_t physicsBodyComponentAddr, uint64_t newState) {
	if (!UseLiftedCode(49, 0x82739CC8)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = newState; __imp__sub_82739CC8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739CC8);
	uint32_t stack = ctx.r1.u64;
	uint32_t savedMsr = ctx.r13.u64;
	uint64_t scratchR9{};
	PPCCRRegister compare0{};
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t targetState = (uint32_t)newState;
	uint64_t result = physicsBodyComponentAddr;
	if ((int32_t)physicsBodyComponent->m_State != (int32_t)targetState) {
		if (targetState == 2) {
			ctx.r1.u64 = stack;
			result = CPhysicsBodyComponent_EnterState2(ctx, base, physicsBodyComponentAddr);
			newState = ctx.r4.u64;
		} else if (targetState == 3 || targetState == 4) {
			ctx.r1.u64 = stack;
			result = CPhysicsBodyComponent_Destroy(ctx, base, physicsBodyComponentAddr);
			newState = ctx.r4.u64;
		}
		if ((int32_t)physicsBodyComponent->m_State == 2) {
			ctx.r1.u64 = stack;
			CPhysicsBodyComponent_RefreshAttachments(ctx, base, physicsBodyComponentAddr);
			scratchR9 = ctx.r9.u64;

			// Build a shared handle {pointer, control block} on the stack and bump the control block refcount.
			uint32_t refCount = physicsBodyComponent->m_14;
			uint32_t handle = physicsBodyComponent->m_10;
			STORE32(stack + 84, refCount);
			STORE32(stack + 80, handle);
			if (refCount != 0) {
				do {
					std::atomic_thread_fence(std::memory_order_seq_cst);
					scratchR9 = REX_CHECK_GLOBAL_LOCK();
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
					REX_ENTER_GLOBAL_LOCK();
					ctx.reserved.u32 = *(uint32_t*)RAW(refCount);
					uint32_t newRefCount = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
					compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(refCount)), ctx.reserved.s32, __builtin_bswap32((int32_t)newRefCount));
					std::atomic_thread_fence(std::memory_order_seq_cst);
					ctx.msr = (uint32_t)scratchR9 & 0x8020 | ctx.msr & ~0x8020;
					REX_LEAVE_GLOBAL_LOCK();
				} while (!compare0.eq);
			}

			uint32_t vtableSlot = LOAD32((uint32_t)physicsBodyComponent->vtable + 96);
			callTarget.u64 = vtableSlot;
			ctx.r3.u64 = physicsBodyComponentAddr;
			ctx.r4.u64 = handle;
			ctx.r9.u64 = scratchR9;
			ctx.r10.u64 = vtableSlot;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = SharedHandle_Release(ctx, base, (uint64_t)stack + 80);
			newState = ctx.r4.u64;
		}
	}
	physicsBodyComponent->m_State = targetState;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = newState;
	return result;
}
PROMOTED_ENTRY(49, sub_82739CC8, 0x82739CC8) { ctx.r3.u64 = CPhysicsBodyComponent_SetState(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82739D98  [16 bytes]
uint64_t n_sub_82739D98(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(49, 0x82739D98)) { ctx.r3.u64 = arg1; __imp__sub_82739D98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739D98);
	uint32_t entity = LOAD32((uint32_t)arg1 + 56);
	if (entity == 0) return entity;
	return n_sub_82521CD8(ctx, base, entity);
}
PROMOTED_ENTRY(49, sub_82739D98, 0x82739D98) { ctx.r3.u64 = n_sub_82739D98(ctx, base, ctx.r3.u64); }

uint64_t CPhysicsBodyComponent_AttachBodyToActionHandler(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint64_t arg2) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(49, 0x82739DB0)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = arg2; __imp__sub_82739DB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82739DB0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);

	stack = PushStackFrame(base, stack, 112);

	// Walk down the global object chain to the action handler and its target object.
	uint32_t local17 = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t local16 = LOAD32(local17 + 88);
	uint32_t local15 = LOAD32(local16 + 4);
	uint32_t local10 = LOAD32(local15 + 24);
	uint32_t local14 = LOAD32(local10);
	uint32_t local13 = LOAD32(local14 + 88);

	callTarget.u64 = local13;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = local10;
	ctx.r4.u64 = arg2;
	ctx.r6.u64 = local13;
	ctx.r7.u64 = local14;
	ctx.r8.u64 = local15;
	ctx.r9.u64 = local16;
	ctx.r10.u64 = local17;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t handler = ctx.r3.u32;
	uint32_t body = physicsBodyComponent->m_Body;
	PPCRegister setBodyFn{};
	setBodyFn.u64 = LOAD32(LOAD32(handler) + 28);
	ctx.r4.u64 = arg2;
	ctx.r5.u64 = body;
	ctx.r10.u64 = setBodyFn.u32;
	REX_CALL_INDIRECT_FUNC(setBodyFn.u32);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(49, sub_82739DB0, 0x82739DB0) { ctx.r3.u64 = CPhysicsBodyComponent_AttachBodyToActionHandler(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CPhysicsBodyComponent_SetRagdollSource(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint32_t newRagdollSource) {
	if (!UseLiftedCode(61, 0x828A11B8)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = newRagdollSource; __imp__sub_828A11B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828A11B8);
	uint32_t stack = ctx.r1.u64;
	uint32_t oldValue{};
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);
	oldValue = physicsBodyComponent->m_18;
	if (oldValue != 0 && LOAD16(oldValue + 4) != 0) {
		int16_t refCount = int16_t(LOAD16(oldValue + 6) - 1);
		STORE16(oldValue + 6, (uint16_t)refCount);
		if (refCount == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(oldValue));
			callTarget.u64 = releaseFunc;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = oldValue;
			ctx.r4.u64 = 1;
			ctx.r9.s64 = 0;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			oldValue = ctx.r3.u64;
		}
	}
	physicsBodyComponent->m_18 = newRagdollSource;
	if (newRagdollSource != 0 && LOAD16(newRagdollSource + 4) != 0) {
		STORE16(newRagdollSource + 6, uint16_t(LOAD16(newRagdollSource + 6) + 1));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return oldValue;
}
PROMOTED_ENTRY(61, sub_828A11B8, 0x828A11B8) { ctx.r3.u64 = CPhysicsBodyComponent_SetRagdollSource(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint32_t CPhysicsBodyComponent_SetRagdollAttachment(CpuState& ctx, uint8_t* base, uint32_t physicsBodyComponentAddr, uint32_t newRagdollAttachment) {
	if (!UseLiftedCode(61, 0x828A1258)) { ctx.r3.u64 = physicsBodyComponentAddr; ctx.r4.u64 = newRagdollAttachment; __imp__sub_828A1258(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828A1258);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CPhysicsBodyComponent* physicsBodyComponent = GameObject<CPhysicsBodyComponent>(base, physicsBodyComponentAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t oldRef = physicsBodyComponent->m_1C;
	if (oldRef != 0 && LOAD16(oldRef + 4) != 0) {
		int32_t refCount = int16_t(LOAD16(oldRef + 6) - 1);
		STORE16(oldRef + 6, (uint16_t)refCount);
		if (refCount == 0) {
			uint32_t releaseFunc = LOAD32(LOAD32(oldRef));
			callTarget.u64 = releaseFunc;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = oldRef;
			ctx.r4.u64 = 1;
			ctx.r9.s64 = refCount;
			ctx.r10.u64 = releaseFunc;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			oldRef = ctx.r3.u32;
		}
	}
	physicsBodyComponent->m_1C = newRagdollAttachment;
	if (newRagdollAttachment != 0 && LOAD16(newRagdollAttachment + 4) != 0) {
		STORE16(newRagdollAttachment + 6, (uint16_t)(LOAD16(newRagdollAttachment + 6) + 1));
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return oldRef;
}
PROMOTED_ENTRY(61, sub_828A1258, 0x828A1258) { ctx.r3.u64 = CPhysicsBodyComponent_SetRagdollAttachment(ctx, base, ctx.r3.u32, ctx.r4.u32); }
