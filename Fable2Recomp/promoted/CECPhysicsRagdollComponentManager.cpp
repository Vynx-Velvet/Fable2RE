// CECPhysicsRagdollComponentManager (vtable 0x820049E0): methods of the class as readable C++.
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

uint64_t CECPhysicsRagdollComponentManager_GetName(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(40, 0x82626220)) { ctx.r3.u64 = arg1; __imp__sub_82626220(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82626220);
	uint32_t stack = ctx.r1.u64;
	uint64_t className{};
	int32_t length{};
	stack = PushStackFrame(base, stack, 96);
	constexpr int32_t str_TXT_820A7644_B_ = int32_t(0x820A7644);
	length = -1;
	className = str_TXT_820A7644_B_;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, arg1, className, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return arg1;
}
PROMOTED_ENTRY(40, sub_82626220, 0x82626220) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_GetName(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsRagdollComponentManager_LoadComponents(CpuState& ctx, uint8_t* base, uint64_t manager, uint64_t entity, uint64_t param) {
	constexpr int32_t str_TXT_820C79A0_B_ = int32_t(0x820C79A0);
	if (!UseLiftedCode(40, 0x82628560)) { ctx.r3.u64 = manager; ctx.r4.u64 = entity; ctx.r8.u64 = param; __imp__sub_82628560(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82628560);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 208);
	ctx.r1.u64 = stack;

	ctx.r4.u64 = entity;
	CECPhysicsRagdollComponentManager_SetupRagdollFromSource(ctx, base, manager, param);

	uint32_t componentsName = str_TXT_820C79A0_B_;
	uint64_t componentHandle = GameDB_ReadU32Field(ctx, base, entity, componentsName);
	uint64_t result = componentHandle;
	uint64_t callerR4 = componentHandle;

	if ((uint32_t)componentHandle != 0) {
		GameDB_GetArrayField(ctx, base, stack + 88, componentHandle, ctx.r8.u64);

		uint32_t begin = LOAD32(stack + 88);
		uint32_t end = LOAD32(stack + 92);
		uint32_t idx = LOAD32(stack + 96);

		while (idx != end) {
			uint32_t elementAddr = begin + idx * 12;
			int32_t type = (int32_t)LOAD32(elementAddr);
			uint32_t componentPtr = LOAD32(elementAddr + 8);

			if (type == 4 && LOAD32(componentPtr) == LOAD32(0x8349E158)) {
				componentPtr = 0x8349E164;
			}

			uint32_t handle = LOAD32(componentPtr);
			if (handle != 0 && LOAD32((uint32_t)manager + 44) != 0) {
				constexpr uint32_t kNullHandle = 0xD6F37228u;
				uint32_t isNull = (handle == kNullHandle) ? 1u : 0u;
				STORE32(stack + 88, handle);
				STORE32(stack + 92, isNull);
				ctx.r8.u64 = isNull;

				uint64_t obj = operator_new(ctx, base, 8);
				uint64_t sharedObject = 0;
				if ((uint32_t)obj != 0) {
					STORE32((uint32_t)obj, 0x820A81F4u);
					sharedObject = obj;
					STORE32((uint32_t)obj + 4, 0);
				}
				STORE32(stack + 80, (uint32_t)sharedObject);

				if ((uint32_t)sharedObject != 0) {
					uint32_t control = operator_new(ctx, base, 12);
					if (control != 0) {
						STORE32(control + 8, (uint32_t)sharedObject);
						STORE32(stack + 84, control);
						STORE32(control, 1);
						STORE32(control + 4, 0x829681C0u);
					} else {
						STORE32(stack + 84, 0);
					}
				} else {
					STORE32(stack + 84, 0);
				}

				CECPhysicsRagdollComponentManager_CreateComponent(ctx, base, manager, sharedObject, stack + 88);
				SharedPtrVector_PushBack(ctx, base, manager + 28, stack + 80);
				SharedHandle_Release(ctx, base, stack + 80);
			}

			idx++;
		}

		result = HandleTarget_Free(ctx, base, begin);
		callerR4 = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = callerR4;
	return result;
}
PROMOTED_ENTRY(40, sub_82628560, 0x82628560) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_LoadComponents(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r8.u64); }

uint64_t CECPhysicsRagdollComponentManager_CreateRagdollBodies(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollComponentManagerAddr) {
	if (!UseLiftedCode(40, 0x826286E0)) { ctx.r3.u64 = physicsRagdollComponentManagerAddr; __imp__sub_826286E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826286E0);
	CECPhysicsRagdollComponentManager* manager = GameObject<CECPhysicsRagdollComponentManager>(base, (uint32_t)physicsRagdollComponentManagerAddr);
	uint32_t stack = ctx.r1.u64;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t returnValue = physicsRagdollComponentManagerAddr;

	stack = PushStackFrame(base, stack, 144);

	uint32_t entity = manager->m_Owner;
	if (((LOAD32(entity + 36) >> 6) & 1) != 0) {
		uint32_t matchingComponent = 0;

		uint32_t indexContainer = LOAD32(entity + 140);
		if (indexContainer != 0) {
			uint32_t index = LOAD8(indexContainer + 6);
			uint32_t begin = LOAD32(entity + 72);
			matchingComponent = LOAD32(begin + index * 8 + 4);
		} else {
			uint32_t cursor = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			r6Value = end;

			STORE32(stack + 80, 0u);
			STORE32(stack + 84, cursor);

			// lower_bound: first entry whose key is >= 6
			int32_t count = (int32_t)(end - cursor) >> 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					uint32_t halfBytes = (uint32_t)half << 3;
					cursor += halfBytes;
					if ((int32_t)LOAD32(cursor) < 6) {
						count = count - half - 1;
						cursor += 8;
					} else {
						cursor -= halfBytes;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, cursor);
			}

			if (cursor != end && (int32_t)LOAD32(cursor) <= 6) {
				matchingComponent = LOAD32(cursor + 4);
			} else {
				matchingComponent = LOAD32(end + 4);
			}
		}

		uint32_t physicsData = LOAD32(matchingComponent + 148);

		for (uint32_t i = 0;; ++i) {
			uint32_t componentCount = 0;
			if (manager->m_ComponentsBegin != 0) {
				componentCount = (uint32_t)((int32_t)(manager->m_ComponentsEnd - manager->m_ComponentsBegin) >> 3);
			}
			if (i == componentCount) break;

			uint32_t componentBase = manager->m_ComponentsBegin;
			if (componentBase == 0 ||
			    i >= (uint32_t)((int32_t)(manager->m_ComponentsEnd - componentBase) >> 3)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			uint32_t component = LOAD32(componentBase + i * 8);
			uint32_t refCount = LOAD32(componentBase + i * 8 + 4);

			STORE32(stack + 80, component);
			STORE32(stack + 84, refCount);
			if (refCount != 0) {
				STORE32(refCount, LOAD32(refCount) + 1);
			}

			uint32_t componentField = LOAD32(component + 36);
			uint32_t arg3 = LOAD32(LOAD32(component + 24) + 8);
			ctx.r1.u64 = stack;
			ctx.r6.u64 = r6Value;
			uint64_t result = CreateRagdollPhysicsHandle(ctx, base, componentField, physicsData, arg3);
			r6Value = ctx.r6.u64;
			STORE64(component + 40, result);
			returnValue = SharedHandle_Release(ctx, base, stack + 80);
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return returnValue;
}
PROMOTED_ENTRY(40, sub_826286E0, 0x826286E0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_CreateRagdollBodies(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsRagdollComponentManager_ActivateAllComponents(CpuState& ctx, uint8_t* base, uint64_t managerAddr) {
	if (!UseLiftedCode(40, 0x826288C8)) { ctx.r3.u64 = managerAddr; __imp__sub_826288C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826288C8);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsRagdollComponentManager* manager = GameObject<CECPhysicsRagdollComponentManager>(base, managerAddr);
	uint64_t result = managerAddr;

	stack = PushStackFrame(base, stack, 128);
	if (LOAD32((uint32_t)managerAddr + 0x2C) != 0) {
		uint32_t componentList = (uint32_t)managerAddr + 0x0C; // {?, begin, end}
		manager->m_4C = 2u;
		uint32_t componentIt = manager->m_ComponentsBegin;
		uint32_t componentEnd = manager->m_ComponentsEnd;
		if (componentIt > componentEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		for (;;) {
			uint32_t listEnd = LOAD32(componentList + 8);
			if (LOAD32(componentList + 4) > listEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			if (componentIt == listEnd) break;
			if (componentIt >= componentEnd) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t sharedHandle = LOAD32(componentIt + 4);
			uint32_t component = LOAD32(componentIt);
			STORE32(stack + 84, sharedHandle);
			STORE32(stack + 80, component);
			if (sharedHandle != 0) {
				// take a reference for the handle copy placed on the stack
				STORE32(sharedHandle, LOAD32(sharedHandle) + 1);
			}
			ctx.r1.u64 = stack;
			CECPhysicsRagdollComponentManager_ActivateComponent(ctx, base, managerAddr, component);
			result = SharedHandle_Release(ctx, base, stack + 80);
			componentEnd = LOAD32(componentList + 8);
			if (componentIt >= componentEnd) {
				ppc_trap(ctx, base, 22);
			}
			componentIt += 8;
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_826288C8, 0x826288C8) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_ActivateAllComponents(ctx, base, ctx.r3.u64); }

uint32_t CECPhysicsRagdollComponentManager_RetainComponents(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollComponentManagerAddr) {
	if (!UseLiftedCode(40, 0x826289A0)) { ctx.r3.u64 = physicsRagdollComponentManagerAddr; __imp__sub_826289A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826289A0);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsRagdollComponentManager* manager = GameObject<CECPhysicsRagdollComponentManager>(base, physicsRagdollComponentManagerAddr);
	uint32_t managerAddr = (uint32_t)physicsRagdollComponentManagerAddr;
	uint32_t returnValue = managerAddr;
	stack = PushStackFrame(base, stack, 144);

	uint32_t iter = manager->m_ComponentsBegin;
	uint32_t end = manager->m_ComponentsEnd;
	if (iter > end) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}
	while (true) {
		uint32_t curEnd = manager->m_ComponentsEnd;
		if (manager->m_ComponentsBegin > curEnd) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}
		if (iter == curEnd)
			break;
		if (iter >= end) {
			ctx.r1.u64 = stack;
			ppc_trap(ctx, base, 22);
		}

		uint32_t handle = LOAD32(iter + 4);
		uint32_t component = LOAD32(iter);
		STORE32(stack + 84, handle);
		STORE32(stack + 80, component);

		if (handle != 0) {
			// add-ref on the shared handle's reference count
			STORE32(handle, LOAD32(handle) + 1);
		}

		if (LOAD8(component + 52) != 0) {
			ctx.r1.u64 = stack;
			PhysicsRagdollRegistry_RemoveComponent(ctx, base, managerAddr + 44, component);
			STORE8(component + 52, 0);
		}

		ctx.r1.u64 = stack;
		returnValue = SharedHandle_Release(ctx, base, stack + 80);

		end = manager->m_ComponentsEnd;
		if (iter >= end) {
			ppc_trap(ctx, base, 22);
		}
		iter = iter + 8;
	}

	manager->m_4C = 2u;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return returnValue;
}
PROMOTED_ENTRY(40, sub_826289A0, 0x826289A0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_RetainComponents(ctx, base, ctx.r3.u64); }

uint64_t CECPhysicsRagdollComponentManager_InitializeFromSource(CpuState& ctx, uint8_t* base, uint64_t manager, uint64_t sourceInfo) {
	if (!UseLiftedCode(40, 0x82628A80)) { ctx.r3.u64 = manager; ctx.r8.u64 = sourceInfo; __imp__sub_82628A80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82628A80);
	uint32_t stack = ctx.r1.u64;
	uint64_t component{};
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CECPhysicsRagdollComponentManager_SetupRagdollFromSource(ctx, base, manager, sourceInfo);
	component = CECPhysicsRagdollComponentManager_ActivateAllComponents(ctx, base, manager);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return component;
}
PROMOTED_ENTRY(40, sub_82628A80, 0x82628A80) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_InitializeFromSource(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t CECPhysicsRagdollComponentManager_Destructor(CpuState& ctx, uint8_t* base, uint64_t componentManager) {
	if (!UseLiftedCode(40, 0x82628AB8)) { ctx.r3.u64 = componentManager; __imp__sub_82628AB8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82628AB8);
	GameStackFrame stackFrame(ctx, base, 96);
	CECPhysicsRagdollComponentManager_RetainComponents(ctx, base, componentManager);
	return PhysicsRagdollRegistry_Destroy(ctx, base, (int64_t)componentManager + 44);
}
PROMOTED_ENTRY(40, sub_82628AB8, 0x82628AB8) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_Destructor(ctx, base, ctx.r3.u64); }

uint32_t CECPhysicsRagdollComponentManager_SetupRagdollFromSource(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollComponentManagerAddr, uint64_t sourceInfo) {
	if (!UseLiftedCode(40, 0x82628AF0)) { ctx.r3.u64 = physicsRagdollComponentManagerAddr; ctx.r8.u64 = sourceInfo; __imp__sub_82628AF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82628AF0);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsRagdollComponentManager* manager = GameObject<CECPhysicsRagdollComponentManager>(base, physicsRagdollComponentManagerAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t ownerAddr = (uint32_t)manager->m_Owner;
	uint32_t entity = LOAD32(ownerAddr + 124);
	uint32_t vtable = LOAD32(entity);
	uint32_t entityFn = LOAD32(vtable + 92);

	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)entityFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = entity;
	ctx.r8.u64 = sourceInfo;
	ctx.r9.u64 = entityFn;
	ctx.r10.u64 = vtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t result = ctx.r3.u32;

	STORE32(stack + 80, 0);
	if (result != 0) {
		result = C_82006BC8_FindFirstMatching(ctx, base, result, stack + 80);
		// register-carried values handed between the helper calls below
		uint32_t reg6 = ctx.r6.u64;
		uint32_t reg7 = ctx.r7.u64;
		uint32_t reg8 = ctx.r8.u64;

		if ((result & 0xFF) != 0) {
			uint32_t root = (uint32_t)manager->m_Owner;
			uint32_t entry = 0;
			bool hasEntry = false;

			if (((LOAD32(root + 36) >> 6) & 1) != 0) {
				uint32_t slot = LOAD32(root + 140);
				if (slot != 0) {
					uint32_t index = LOAD8(slot + 6);
					uint32_t begin = LOAD32(root + 72);
					entry = LOAD32(begin + __builtin_rotateleft32(index, 3) + 4);
					hasEntry = true;
				} else {
					uint32_t begin = LOAD32(root + 72);
					uint32_t end = LOAD32(root + 76);
					STORE32(stack + 96, 0);
					int32_t remaining = (int32_t)(end - begin) >> 3;
					uint32_t candidate = begin;
					STORE32(stack + 100, candidate);
					// lower_bound: first entry whose key is not less than 6
					if (remaining > 0) {
						do {
							int32_t half = remaining >> 1;
							uint32_t offset = (uint32_t)half << 3;
							candidate += offset;
							if ((int32_t)LOAD32(candidate) < 6) {
								remaining = remaining - half - 1;
								candidate += 8;
							} else {
								candidate -= offset;
								remaining = half;
							}
						} while (remaining > 0);
						STORE32(stack + 100, candidate);
					}
					if (candidate != end && (int32_t)LOAD32(candidate) <= 6) {
						entry = LOAD32(LOAD32(stack + 100) + 4);
					} else {
						entry = LOAD32(end + 4);
					}
					hasEntry = true;
				}
			}

			uint32_t storedId = LOAD32(stack + 80);
			if (hasEntry) {
				uint32_t type = LOAD32(entry + 20);
				STORE32(stack + 100, 0);
				STORE32(stack + 104, 0);
				STORE32(stack + 108, 0);
				if (type == 2) {
					ctx.r6.u64 = reg6;
					ctx.r7.u64 = reg7;
					n_sub_82B6F5A0(ctx, base, stack + 96, entry + 44, reg8);
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
				} else if (type == 1) {
					ctx.r6.u64 = reg6;
					ctx.r7.u64 = reg7;
					n_sub_82B6F5A0(ctx, base, stack + 96, entry + 44, reg8);
					uint32_t first = LOAD32(stack + 100);
					int32_t quotient = (int32_t)(LOAD32(stack + 104) - first) / 48;
					uint32_t data = (quotient == 0) ? (stack + 96) : first;
					n_sub_82B6D400(ctx, base, data, LOAD32(entry + 148), 0, -1);
					reg7 = ctx.r7.u64;
					reg8 = ctx.r8.u64;
				}
				ctx.r6.u64 = LOAD32(entry + 148);
				ctx.r7.u64 = reg7;
				n_sub_8228F328(ctx, base, storedId, (uint32_t)physicsRagdollComponentManagerAddr + 64, stack + 96);
				Vector_FreeAndReset(ctx, base, stack + 96);
				reg6 = ctx.r6.u64;
				reg8 = ctx.r8.u64;
			}

			ctx.r6.u64 = reg6;
			ctx.r8.u64 = reg8;
			result = PhysicsRagdollRegistry_CreateEntry(ctx, base, (uint32_t)physicsRagdollComponentManagerAddr + 44, storedId);
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_82628AF0, 0x82628AF0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_SetupRagdollFromSource(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint32_t CECPhysicsRagdollComponentManager_CreateComponent(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
	if (!UseLiftedCode(40, 0x82628CF0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82628CF0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82628CF0);

	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_833375D4 = int32_t(0x833375D4);
	constexpr int32_t g_8333B4A8 = int32_t(0x8333B4A8);
	constexpr uint32_t kComponentDtor = 0x829681C0;

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 192);

	uint32_t manager = (uint32_t)arg1;
	uint32_t targetOwner = (uint32_t)arg2;
	uint32_t sourceInfo = (uint32_t)arg3;

	uint64_t r5Value = 0;   // carries the r5 value into the final cleanup call

	if (LOAD32(manager + 44) != 0) {
		STORE32(stack + 100, 0);
		STORE32(stack + 104, 0);

		ctx.r1.u64 = stack;
		ctx.r5.u64 = arg3;
		uint32_t hasQuery = GameDB_BeginComponentQuery(ctx, base, stack + 96, arg3);
		r5Value = ctx.r5.u64;
		if ((hasQuery & 0xFF) != 0) {
			uint64_t typeAId = g_8333B4A8;
			uint64_t hashA = ReadU32(ctx, base, typeAId);
			uint64_t query = LOAD32(stack + 96);

			uint64_t compA = ComponentQuery_FindByHash(ctx, base, query, hashA, 0);

			uint64_t typeBId = g_833375D4;
			uint64_t hashB1 = ReadU32(ctx, base, typeBId);
			uint64_t compB = ComponentQuery_FindByHash(ctx, base, query, hashB1, 0);

			uint64_t hashB2 = ReadU32(ctx, base, typeBId);
			r5Value = compB;
			uint64_t compC = ComponentQuery_FindByHash(ctx, base, query, hashB2, compB);

			if ((uint32_t)compA != 0 && (uint32_t)compB != 0 && (uint32_t)compC != 0) {
				PPCRegister callTarget{};

				uint32_t factoryFn = LOAD32(LOAD32((uint32_t)compA) + 12);
				callTarget.u64 = factoryFn;
				ctx.r3.u64 = compA;
				ctx.r4.u64 = 0;
				ctx.r5.u64 = compB;
				ctx.r10.u64 = factoryFn;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint64_t entityRef = ctx.r3.u64;

				uint64_t alloc = operator_new(ctx, base, 112);
				uint64_t newComponent;
				if ((uint32_t)alloc != 0) {
					CECPhysicsRagdollComponent_Construct(ctx, base, alloc, stack + 96, entityRef, compB, compC);
					newComponent = alloc;
				} else {
					newComponent = 0;
				}
				STORE32(stack + 88, (uint32_t)newComponent);

				if ((uint32_t)newComponent != 0) {
					uint32_t control = operator_new(ctx, base, 12);
					if (control != 0) {
						STORE32(control + 8, (uint32_t)newComponent);
						STORE32(stack + 92, control);
						STORE32(control, 1);
						STORE32(control + 4, kComponentDtor);
					} else {
						STORE32(stack + 92, 0);
					}
				} else {
					STORE32(stack + 92, 0);
				}

				uint32_t sourceField0 = LOAD32(sourceInfo);
				int64_t handleVtable = (int64_t)g_820F0000 + 5732;
				STORE32(stack + 84, 0);
				STORE32(stack + 80, (uint32_t)handleVtable);
				STORE32((uint32_t)newComponent + 36, sourceField0);
				uint32_t sourceField1 = LOAD32(sourceInfo + 4);
				STORE32((uint32_t)newComponent + 96, sourceField1);
				ctx.r8.u64 = sourceField1;
				ctx.r9.u64 = (uint64_t)handleVtable;
				EntityHandle_SetTarget(ctx, base, stack + 80, targetOwner);

				uint64_t r10Value = ctx.r10.u64;
				uint32_t handleTarget = LOAD32(stack + 84);
				uint64_t targetPtr;
				if (handleTarget != 0) {
					r10Value = LOAD32(handleTarget);
					if ((uint32_t)r10Value != 0) {
						targetPtr = (uint32_t)r10Value;
					} else {
						EntityHandle_Release(ctx, base, stack + 80);
						r10Value = ctx.r10.u64;
						targetPtr = 0;
					}
				} else {
					targetPtr = 0;
				}
				ctx.r10.u64 = r10Value;
				EntityHandle_SetTarget(ctx, base, (uint32_t)newComponent + 100, targetPtr);

				uint32_t vtableLow = uint32_t(0x820F1664);
				STORE32(stack + 80, vtableLow);
				EntityHandle_Release(ctx, base, stack + 80);

				CECPhysicsRagdollComponentManager_ActivateComponent(ctx, base, manager, newComponent);
				SharedPtrVector_PushBack(ctx, base, manager + 12, stack + 88);

				if (LOAD16((uint32_t)entityRef + 4) != 0) {
					int16_t remaining = (int16_t)(uint16_t)(LOAD16((uint32_t)entityRef + 6) - 1);
					STORE16((uint32_t)entityRef + 6, (uint16_t)remaining);
					if (remaining == 0) {
						callTarget.u64 = LOAD32(LOAD32((uint32_t)entityRef));
						ctx.r3.u64 = entityRef;
						ctx.r4.u64 = 1;
						ctx.r9.s64 = remaining;
						ctx.r10.u64 = callTarget.u64;
						REX_CALL_INDIRECT_FUNC(callTarget.u32);
					}
				}

				SharedHandle_Release(ctx, base, stack + 88);
				r5Value = ctx.r5.u64;
			}
		}

		ctx.r5.u64 = r5Value;
		arg1 = SharedHandle_Release(ctx, base, stack + 100);
	}

	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return (uint32_t)arg1;
}
PROMOTED_ENTRY(40, sub_82628CF0, 0x82628CF0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_CreateComponent(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t CECPhysicsRagdollComponentManager_ActivateComponent(CpuState& ctx, uint8_t* base, uint64_t physicsRagdollComponentManagerAddr, uint64_t component) {
	constexpr int32_t str_TXT_820B7768_B_ = int32_t(0x820B7768);
	if (!UseLiftedCode(40, 0x826290C0)) { ctx.r3.u64 = physicsRagdollComponentManagerAddr; ctx.r4.u64 = component; __imp__sub_826290C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x826290C0);
	uint32_t stack = ctx.r1.u64;
	CECPhysicsRagdollComponentManager* physicsRagdollComponentManager = GameObject<CECPhysicsRagdollComponentManager>(base, physicsRagdollComponentManagerAddr);

	const uint32_t manager = (uint32_t)physicsRagdollComponentManagerAddr;
	const uint32_t entity = (uint32_t)component;
	uint64_t entryEnd = ctx.r6.u64;
	uint64_t result = physicsRagdollComponentManagerAddr;

	stack = PushStackFrame(base, stack, 176);
	if (LOAD8(entity + 52) == 0) {
		if (LOAD32(manager + 44) != 0) {
			uint32_t ragdollEntry = 0;
			uint32_t owner = physicsRagdollComponentManager->m_Owner;
			if (((LOAD32(owner + 36) >> 6) & 1) != 0) {
				uint32_t indexTable = LOAD32(owner + 140);
				if (indexTable != 0) {
					uint32_t entryIndex = (uint32_t)LOAD8(indexTable + 6) << 3;
					uint32_t entries = LOAD32(owner + 72);
					ragdollEntry = LOAD32(entries + entryIndex + 4);
				} else {
					uint32_t entries = LOAD32(owner + 72);
					entryEnd = LOAD32(owner + 76);
					uint32_t entriesEnd = (uint32_t)entryEnd;
					uint32_t count = (uint32_t)((int32_t)(entriesEnd - entries) >> 3);
					STORE32(stack + 80, 0);
					STORE32(stack + 84, entries);
					if ((int32_t)count > 0) {
						uint32_t it = entries;
						do {
							int32_t half = (int32_t)count >> 1;
							uint32_t mid = it + (uint32_t)half * 8;
							if ((int32_t)LOAD32(mid) < 6) {
								count = count - (uint32_t)half - 1;
								it = mid + 8;
							} else {
								count = (uint32_t)half;
							}
						} while ((int32_t)count > 0);
						entries = it;
						STORE32(stack + 84, entries);
					}
					uint32_t found = entriesEnd;
					if (entries != entriesEnd && (int32_t)LOAD32(entries) <= 6) {
						found = entries;
						STORE64(stack + 80, LOAD64(stack + 80));
					}
					ragdollEntry = LOAD32(found + 4);
				}
			}

			uint32_t entityId = LOAD32(entity + 36);
			uint32_t nameTable = LOAD32(ragdollEntry + 148);
			uint32_t ownerRef = LOAD32(LOAD32(entity + 24) + 8);
			ctx.r1.u64 = stack;
			ctx.r6.u64 = entryEnd;
			uint64_t handle = CreateRagdollPhysicsHandle(ctx, base, entityId, nameTable, ownerRef);
			uint64_t streamArg = ctx.r5.u64;
			STORE64(entity + 40, handle);

			uint32_t stream = LOAD32(ragdollEntry + 152);
			if (stream != 0) {
				uint32_t streamNameTable = LOAD32(ragdollEntry + 148);
				CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820B7768_B_, -1);
				uint64_t index = StringPairArray_FindIndexByName(ctx, base, streamNameTable, stack + 80);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				n_sub_82B6F388(ctx, base, stack + 96, stream, index);
				streamArg = index;
				PPCVRegister vec;
				SET_V8(vec, VLOAD((stack + 112) & ~0xFu));
				VSTORE((entity + 80) & ~0xFu, V8(vec));
			}

			result = PhysicsRagdollRegistry_AddComponent(ctx, base, (uint64_t)manager + 44, component);
			component = ctx.r4.u64;
			uint32_t newest = LOAD32(entity + 48);
			if (newest > LOAD32(manager + 76)) {
				STORE32(manager + 76, newest);
			}
			STORE8(entity + 52, 1);
		}
	}
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = component;
	return (uint32_t)result;
}
PROMOTED_ENTRY(40, sub_826290C0, 0x826290C0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_ActivateComponent(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECPhysicsRagdollComponentManager_Shutdown(CpuState& ctx, uint8_t* base, uint64_t manager) {
	if (!UseLiftedCode(40, 0x826293B0)) { ctx.r3.u64 = manager; __imp__sub_826293B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826293B0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t result = manager;
	if (LOAD32((uint32_t)manager + 44) != 0) {
		ctx.r1.u64 = stack;
		CECPhysicsRagdollComponentManager_RetainComponents(ctx, base, manager);
		uint64_t fieldAddress = manager + 44;
		result = PhysicsRagdollRegistry_Destroy(ctx, base, fieldAddress);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_826293B0, 0x826293B0) { ctx.r3.u64 = CECPhysicsRagdollComponentManager_Shutdown(ctx, base, ctx.r3.u64); }

uint64_t n_sub_826293F0(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(40, 0x826293F0)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_826293F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x826293F0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	// Virtual call through the component's second vtable slot, `this` in r3.
	uint32_t componentState = LOAD32(LOAD32((uint32_t)arg2) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = arg2;
	ctx.r4.u64 = arg2;
	ctx.r10.u64 = componentState;
	REX_CALL_INDIRECT_FUNC(componentState);

	uint64_t result = ctx.r3.u64;
	if ((int32_t)result == 10 && LOAD8((uint32_t)arg2 + 4) != 0) {
		result = arg1 + 44;
		if (LOAD32((uint32_t)arg1 + 44) != 0) {
			result = n_sub_82627188(ctx, base, result);
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(40, sub_826293F0, 0x826293F0) { ctx.r3.u64 = n_sub_826293F0(ctx, base, ctx.r3.u64, ctx.r4.u64); }
