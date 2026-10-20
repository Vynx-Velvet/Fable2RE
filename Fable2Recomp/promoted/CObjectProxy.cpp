// CObjectProxy (vtable 0x8200ACA0): methods of the class as readable C++.
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

// sub_82C0B590  [44 bytes]
uint64_t CObjectProxy_GetEmbeddedInterface(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr) {
	if (!UseLiftedCode(89, 0x82C0B590)) { ctx.r3.u64 = objectProxyAddr; __imp__sub_82C0B590(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0B590);
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	uint32_t target = LOAD32(objectProxy->m_refObject + 4);
	if (target == 0) {
		return 0;
	}
	// Tail call: virtual slot 1 of the object embedded at offset 12 of the target.
	uint32_t embeddedObject = target + 12;
	uint32_t embeddedVtable = LOAD32(embeddedObject);
	uint32_t method = LOAD32(embeddedVtable + 4);
	ctx.r3.u64 = embeddedObject;
	ctx.r9.u64 = method;
	ctx.r10.u64 = embeddedVtable;
	REX_CALL_INDIRECT_FUNC(method);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(89, sub_82C0B590, 0x82C0B590) { ctx.r3.u64 = CObjectProxy_GetEmbeddedInterface(ctx, base, ctx.r3.u32); }

// sub_82C0B5C0  [20 bytes]
uint64_t CObjectProxy_DispatchToTarget(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4) {
	if (!UseLiftedCode(89, 0x82C0B5C0)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_82C0B5C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0B5C0);
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	uint32_t target = LOAD32(objectProxy->m_refObject + 4);
	if (target == 0) {
		ctx.r4.u64 = arg2; // callers read r4 after the call
		return 0;
	}
	return Target_DispatchToHandler(ctx, base, target, arg2, arg3, arg4);
}
PROMOTED_ENTRY(89, sub_82C0B5C0, 0x82C0B5C0) { ctx.r3.u64 = CObjectProxy_DispatchToTarget(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82C0C990  [20 bytes]
void CObjectProxy_SetFieldA0(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint32_t value) {
	if (!UseLiftedCode(89, 0x82C0C990)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = value; __imp__sub_82C0C990(ctx, base); return; }
	LiftedFrame frame(0x82C0C990);
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	uint32_t target = objectProxy->m_C;
	if (target == 0) return;
	STORE32(target + 0xA0, value);
}
PROMOTED_ENTRY(89, sub_82C0C990, 0x82C0C990) { CObjectProxy_SetFieldA0(ctx, base, ctx.r3.u32, ctx.r4.u32); }

void CObjectProxy_SetFieldA4IfUnset(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint32_t value) {
	if (!UseLiftedCode(89, 0x82C0C9A8)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = value; __imp__sub_82C0C9A8(ctx, base); return; }
	LiftedFrame frame(0x82C0C9A8);
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	uint32_t proxyTarget = objectProxy->m_C;
	if (proxyTarget == 0) return;
	if (LOAD32(proxyTarget + 0xA4) != 0) return;
	STORE32(proxyTarget + 0xA4, value);
}
PROMOTED_ENTRY(89, sub_82C0C9A8, 0x82C0C9A8) { CObjectProxy_SetFieldA4IfUnset(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CObjectProxy_GetVectors(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint32_t outVectorA, uint32_t outVectorB, uint32_t outVectorC, uint32_t outScalar) {
	if (!UseLiftedCode(89, 0x82C0C9C8)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = outVectorA; ctx.r5.u64 = outVectorB; ctx.r6.u64 = outVectorC; ctx.r7.u64 = outScalar; __imp__sub_82C0C9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0C9C8);
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	uint32_t vectorsAddr = objectProxy->m_8;

	PPCVRegister vecA{};
	SET_V8(vecA, VLOAD((vectorsAddr + 592u) & ~0xF));
	VSTORE(outVectorA & ~0xF, V8(vecA));

	PPCVRegister vecB{};
	SET_V8(vecB, VLOAD((vectorsAddr + 608u) & ~0xF));
	VSTORE(outVectorB & ~0xF, V8(vecB));

	PPCVRegister vecC{};
	SET_V8(vecC, VLOAD((vectorsAddr + 624u) & ~0xF));
	VSTORE(outVectorC & ~0xF, V8(vecC));

	ctx.fpscr.disableFlushMode();
	STORE_F32(outScalar, float(double(LOAD_F32(vectorsAddr + 640))));

	return 1;
}
PROMOTED_ENTRY(89, sub_82C0C9C8, 0x82C0C9C8) { ctx.r3.u64 = CObjectProxy_GetVectors(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32); }

// sub_82C0E098  [112 bytes]
uint32_t CObjectProxy_Destruct(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr) {
	if (!UseLiftedCode(89, 0x82C0E098)) { ctx.r3.u64 = objectProxyAddr; __imp__sub_82C0E098(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C0E098);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 112);
	objectProxy->vtable = 0x8200ACA0u;
	uint32_t ownedRef = objectProxy->m_ownedRef;
	if (ownedRef != 0) {
		// virtual slot 1 of the owned object
		uint32_t releaseFn = LOAD32(LOAD32(ownedRef) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = ownedRef;
		ctx.r10.u64 = releaseFn;
		REX_CALL_INDIRECT_FUNC(releaseFn);
	}
	objectProxy->m_ownedRef = 0;
	objectProxy->m_C = 0;
	ctx.r1.u64 = stack;
	C_8200A32C_Destructor(ctx, base, objectProxyAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C0E098, 0x82C0E098) { ctx.r3.u64 = CObjectProxy_Destruct(ctx, base, ctx.r3.u32); }

// sub_82C0E108  [180 bytes]
uint64_t n_sub_82C0E108(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint64_t selector) {
	if (!UseLiftedCode(89, 0x82C0E108)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = selector; __imp__sub_82C0E108(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0E108);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 112);
	int32_t mode = (int32_t)(uint32_t)selector;
	uint64_t result = 0;
	uint64_t r4ForCallers = selector;

	if (mode == 0) {
		result = uint64_t(objectProxy->m_8) + 572;
	} else {
		uint32_t proxyTarget = objectProxy->m_C;
		r4ForCallers = proxyTarget;
		if (proxyTarget != 0) {
			// Temporary copy (at stack + 80) of the reference the target holds at +120, released by OwnedPtr_Reset.
			ctx.r1.u64 = stack;
			Reference_ConstructFrom(ctx, base, stack + 80, proxyTarget);
			uint32_t referenced = LOAD32(stack + 80);
			if (referenced != 0) {
				if (mode == 2) {
					result = uint64_t(referenced) + 40;
				} else {
					uint32_t linked = LOAD32(referenced + 52);
					if (linked != 0 && mode == 1) {
						result = uint64_t(linked) + 40;
					}
				}
			}
			OwnedPtr_Reset(ctx, base, stack + 80);
			r4ForCallers = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCallers; // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(89, sub_82C0E108, 0x82C0E108) { ctx.r3.u64 = n_sub_82C0E108(ctx, base, ctx.r3.u32, ctx.r4.u64); }

// sub_82C0E1C0  [76 bytes]
uint64_t CObjectProxy_CreateDerived(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5) {
	if (!UseLiftedCode(89, 0x82C0E1C0)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; __imp__sub_82C0E1C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0E1C0);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 112);

	// The proxy's virtual method at vtable offset 0x44; the original passes arg4 in r4 (not arg2) and in r6.
	uint32_t method = LOAD32(uint32_t(objectProxy->vtable) + 0x44);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = objectProxyAddr;
	ctx.r4.u64 = arg4;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(method);
	uint64_t returnedObject = ctx.r3.u64;

	uint64_t result = returnedObject;
	if ((uint32_t)returnedObject != 0) {
		result = n_sub_82C0CD48(ctx, base, returnedObject, arg2, arg3, arg5);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(89, sub_82C0E1C0, 0x82C0E1C0) { ctx.r3.u64 = CObjectProxy_CreateDerived(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

// sub_82C0E210  [108 bytes]
uint64_t CObjectProxy_AssignFromReference(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t sourceObject) {
	if (!UseLiftedCode(89, 0x82C0E210)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = sourceObject; __imp__sub_82C0E210(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0E210);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 96);
	uint64_t r4Out = sourceObject;

	// Copies the pair at +120/+124 of the object at sourceObject+12 (both zero without that object) and,
	// when the copied reference is set, calls its first virtual function.
	uint32_t refSource = LOAD32((uint32_t)sourceObject + 12);
	if (refSource == 0) {
		objectProxy->vtable = 0;
		objectProxy->m_refObject = 0;
	} else {
		objectProxy->vtable = LOAD32(refSource + 120);
		uint32_t refObject = LOAD32(refSource + 124);
		objectProxy->m_refObject = refObject;
		if (refObject != 0) {
			uint32_t firstVirtual = LOAD32(LOAD32(refObject));
			callTarget.u64 = firstVirtual;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = refObject;
			ctx.r4.u64 = sourceObject;
			ctx.r10.u64 = firstVirtual;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			r4Out = ctx.r4.u64;
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = r4Out;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C0E210, 0x82C0E210) { ctx.r3.u64 = CObjectProxy_AssignFromReference(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82C0E280  [8 bytes]
uint64_t n_sub_82C0E280(CpuState& ctx, uint8_t* base, uint64_t objectProxy, uint32_t arg2, uint32_t arg3, uint32_t arg4) {
	if (!UseLiftedCode(89, 0x82C0E280)) { ctx.r3.u64 = objectProxy; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_82C0E280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0E280);
	// forwards to the object held at +8, which the callee receives in r3
	uint64_t heldObject = LOAD32((uint32_t)objectProxy + 8);
	return n_sub_82C0CA18(ctx, base, arg2, arg3, arg4);
}
PROMOTED_ENTRY(89, sub_82C0E280, 0x82C0E280) { ctx.r3.u64 = n_sub_82C0E280(ctx, base, ctx.r3.u64, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32); }

uint32_t CObjectProxy_Initialize(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint64_t owner, uint64_t target, uint64_t key, uint64_t sourceObject, uint64_t nameString, uint64_t context) {
	constexpr int32_t g_8200AAE0 = int32_t(0x8200AAE0);
	if (!UseLiftedCode(89, 0x82C0EEC8)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = owner; ctx.r5.u64 = target; ctx.r6.u64 = key; ctx.r7.u64 = sourceObject; ctx.r8.u64 = nameString; ctx.r9.u64 = context; __imp__sub_82C0EEC8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C0EEC8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CObjectProxy* proxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 208);

	if ((uint32_t)target == 0) {
		proxy->vtable = 0;
		proxy->m_refObject = 0;
		stack = PopStackFrame(stack, 208);
		ctx.r1.u64 = stack;
		// callers read r4 after the call
		ctx.r4.u64 = owner;
		return objectProxyAddr;
	}

	// Build the new 80-byte object.
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = owner;
	ctx.r5.u64 = target;
	ctx.r6.u64 = key;
	ctx.r8.u64 = nameString;
	uint64_t raw = operator_new(ctx, base, 80);
	uint64_t impl = (uint32_t)raw != 0 ? CObjectProxyImpl_Construct(ctx, base, raw) : 0;

	// Store {sourceObject, sourceObject + 108} at impl+72/+76: the new reference's first virtual
	// function is called, then the old reference's second one.
	uint64_t sourceRef = sourceObject + 108;
	uint8_t carry = (uint32_t)sourceObject > 0xFFFFFF93u;  // carry out of the 32-bit add
	uint32_t sourceSlot = (uint32_t)impl + 72;
	if ((uint32_t)sourceRef != 0) {
		uint32_t fn = LOAD32(LOAD32((uint32_t)sourceRef));
		callTarget.u64 = fn;
		ctx.r3.u64 = sourceRef;
		ctx.r10.u64 = fn;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		carry = ctx.xer.ca;
	}
	uint32_t oldSourceRef = LOAD32(sourceSlot + 4);
	if (oldSourceRef != 0) {
		uint32_t fn = LOAD32(LOAD32(oldSourceRef) + 4);
		callTarget.u64 = fn;
		ctx.r3.u64 = oldSourceRef;
		ctx.r10.u64 = fn;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		carry = ctx.xer.ca;
	}
	STORE32(sourceSlot + 4, (uint32_t)sourceRef);
	STORE32(sourceSlot, (uint32_t)sourceObject);

	// Owner_LookupKeyedValues fills the two words at stack+88/+84 that CObjectProxyImpl_Initialize receives.
	uint32_t outB = stack + 88;
	uint32_t outA = stack + 84;
	STORE32(outB, 0);
	STORE32(outA, 0);
	ctx.xer.ca = carry;
	Owner_LookupKeyedValues(ctx, base, (uint32_t)owner, (uint32_t)key, outB, outA);
	uint32_t valueB = LOAD32(outB);
	uint32_t valueA = LOAD32(outA);
	CObjectProxyImpl_Initialize(ctx, base, impl, (uint32_t)target, valueB, valueA);

	uint32_t contextValue = LOAD32((uint32_t)context + 648);
	uint32_t ownerValue = LOAD32((uint32_t)owner + 8);
	double floatArg = n_sub_82C497C0(ctx, base, (uint32_t)context + 96, contextValue, ownerValue);

	uint32_t memberObject = LOAD32((uint32_t)impl + 28);
	{
		uint32_t fn = LOAD32(LOAD32(memberObject) + 12);
		callTarget.u64 = fn;
		ctx.r3.u64 = memberObject;
		ctx.r4.u64 = contextValue;
		ctx.r5.u64 = 0;
		ctx.r10.u64 = fn;
		ctx.f1.f64 = floatArg;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	CCharString_Assign(ctx, base, impl + 68, nameString);
	LinkedList_Insert(ctx, base, (uint32_t)owner + 20, (uint32_t)impl);

	// The object at stack+96 (vtable 0x8200AAE0, then target, context, owner) is handed to every
	// entry that matches key; MatchingEntryList_Find writes the index of the first one to stack+92 and
	// returns how many there are.
	uint32_t firstIndexSlot = stack + 92;
	uint32_t entryCallArg = stack + 96;
	STORE32(stack + 108, (uint32_t)owner);
	STORE32(stack + 100, (uint32_t)target);
	STORE32(stack + 104, (uint32_t)context);
	STORE32(entryCallArg, uint32_t(g_8200AAE0));
	STORE32(firstIndexSlot, 0);
	uint32_t count = MatchingEntryList_Find(ctx, base, LOAD32((uint32_t)owner + 4), (uint32_t)key, firstIndexSlot);

	// r4, r5 and r7-r9 as the original leaves them; handed to the two calls after the loop
	uint64_t r4 = key;
	uint64_t r5 = (uint64_t)stack + 92;
	uint64_t r7 = ctx.r7.u64;
	uint64_t r8 = ctx.r8.u64;
	uint64_t r9 = ctx.r9.u64;

	for (uint32_t i = 0; i < count; ++i) {
		uint32_t entries = LOAD32((uint32_t)owner + 4);
		uint32_t lookup = entries + 64;
		uint32_t table = LOAD32(entries + 140);
		uint32_t tableOffset = (i + LOAD32(firstIndexSlot)) << 2;
		uint32_t entry = LOAD32(tableOffset + table);
		uint32_t entryValue = LOAD32(entry + 4);
		STORE32(stack + 88, entryValue);

		// state the callee may pass on
		uint32_t foundIndex = IndexMap_Find(ctx, base, lookup, stack + 88, stack + 80);
		uint32_t element = LOAD8(stack + 80) == 0 ? 0 : LOAD32((foundIndex << 2) + LOAD32(lookup));

		uint32_t handler = LOAD32(element + 4);
		uint32_t fn = LOAD32(LOAD32(handler) + 32);
		callTarget.u64 = fn;
		ctx.r3.u64 = handler;
		ctx.r4.u64 = entryCallArg;
		ctx.r5.u64 = entryValue;
		ctx.r10.u64 = fn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t result = ctx.r3.u32;
		r4 = ctx.r4.u64;
		r5 = ctx.r5.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
		if (result == 0) continue;

		// A 24-byte node: result, next (+4), previous (+8), list (+12), handler (+16), entry value (+20).
		uint32_t node = operator_new(ctx, base, 24);
		r4 = ctx.r4.u64;
		r5 = ctx.r5.u64;
		if (node != 0) {
			STORE32(node, 0);
			STORE32(node + 4, 0);
			STORE32(node + 8, 0);
			STORE32(node + 12, 0);
			STORE32(node + 16, 0);
			STORE32(node + 20, 0);
		}
		STORE32(node, result);
		uint32_t nodeHandler = LOAD32(element + 4);
		uint32_t list = (uint32_t)impl + 36;
		r8 = nodeHandler;
		r9 = impl + 36;
		STORE32(node + 16, nodeHandler);
		STORE32(node + 20, entryValue);

		// Append the node to the list at impl+36 (head, tail) unless one of its links is set;
		// r7/r8 keep the last words read here.
		r7 = LOAD32(node + 12);
		if ((uint32_t)r7 != 0) continue;
		r8 = LOAD32(node + 8);
		if ((uint32_t)r8 != 0) continue;
		r8 = LOAD32(node + 4);
		if ((uint32_t)r8 != 0) continue;
		STORE32(node + 12, list);
		r8 = LOAD32(list);
		if ((uint32_t)r8 == 0) {
			STORE32(node + 8, 0);
			STORE32(node + 4, 0);
			STORE32(list, node);
		} else {
			uint32_t tail = LOAD32(list + 4);
			r8 = tail;
			STORE32(node + 4, 0);
			STORE32(node + 8, tail);
			r7 = LOAD32(list + 4);
			STORE32((uint32_t)r7 + 4, node);
		}
		STORE32(list + 4, node);
	}

	// The proxy takes the new object and its part at +44: that part's first virtual function is
	// called, then the second one of the reference the proxy holds after being cleared.
	uint64_t implRef = impl + 44;
	carry = (uint32_t)impl > 0xFFFFFFD3u;  // carry out of the 32-bit add
	proxy->vtable = 0;
	proxy->m_refObject = 0;
	if ((uint32_t)implRef != 0) {
		uint32_t fn = LOAD32(LOAD32((uint32_t)implRef));
		callTarget.u64 = fn;
		// state the callee may pass on
		ctx.r3.u64 = implRef;
		ctx.r4.u64 = r4;
		ctx.r5.u64 = r5;
		ctx.r7.u64 = r7;
		ctx.r8.u64 = r8;
		ctx.r9.u64 = r9;
		ctx.r10.u64 = fn;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r4 = ctx.r4.u64;
		r5 = ctx.r5.u64;
		r7 = ctx.r7.u64;
		r8 = ctx.r8.u64;
		r9 = ctx.r9.u64;
		carry = ctx.xer.ca;
	}
	uint32_t heldRef = proxy->m_refObject;
	if (heldRef != 0) {
		uint32_t fn = LOAD32(LOAD32(heldRef) + 4);
		callTarget.u64 = fn;
		// state the callee may pass on
		ctx.r3.u64 = heldRef;
		ctx.r4.u64 = r4;
		ctx.r5.u64 = r5;
		ctx.r7.u64 = r7;
		ctx.r8.u64 = r8;
		ctx.r9.u64 = r9;
		ctx.r10.u64 = fn;
		ctx.xer.ca = carry;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		r4 = ctx.r4.u64;
		carry = ctx.xer.ca;
	}
	proxy->m_refObject = (uint32_t)implRef;
	proxy->vtable = (uint32_t)impl;
	STORE32(entryCallArg, uint32_t(g_8200AAE0));
	C_8200A32C_Destructor(ctx, base, entryCallArg);
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	// callers read r4 and xer.ca after the call
	ctx.r4.u64 = r4;
	ctx.xer.ca = carry;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C0EEC8, 0x82C0EEC8) { ctx.r3.u64 = CObjectProxy_Initialize(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64); }

// sub_82C0F200  [56 bytes]
uint64_t CObjectProxy_CreateFromDescriptor(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t proxyDescriptor, uint64_t target, uint64_t key, uint64_t sourceObject, uint64_t nameString) {
	if (!UseLiftedCode(89, 0x82C0F200)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = proxyDescriptor; ctx.r5.u64 = target; ctx.r6.u64 = key; ctx.r7.u64 = sourceObject; ctx.r8.u64 = nameString; __imp__sub_82C0F200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0F200);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint32_t payload = LOAD32((uint32_t)proxyDescriptor + 4);
	uint32_t extra = LOAD32((uint32_t)proxyDescriptor + 8);
	ctx.r1.u64 = stack;
	CObjectProxy_Initialize(ctx, base, objectProxyAddr, payload, target, key, sourceObject, nameString, extra);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C0F200, 0x82C0F200) { ctx.r3.u64 = CObjectProxy_CreateFromDescriptor(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t CObjectProxy_FindByName(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t nameString, uint64_t value, uint64_t arg4) {
	if (!UseLiftedCode(89, 0x82C0F238)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = nameString; ctx.r5.u64 = value; ctx.r6.u64 = arg4; __imp__sub_82C0F238(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0F238);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t virtualFuncAddr = LOAD32(uint32_t(objectProxy->vtable) + 68);
	PPCRegister callTarget{};
	callTarget.u64 = (uint64_t)virtualFuncAddr;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = objectProxyAddr;
	ctx.r4.u64 = arg4;
	ctx.r5.u64 = value;
	ctx.r6.u64 = arg4;
	ctx.r10.u64 = virtualFuncAddr;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	if ((uint32_t)result != 0) {
		result = CObjectProxy_ConstructNamed(ctx, base, result, nameString, value);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(89, sub_82C0F238, 0x82C0F238) { ctx.r3.u64 = CObjectProxy_FindByName(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t n_sub_82C0F298(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t nameString, uint64_t value, uint64_t arg4) {
	if (!UseLiftedCode(89, 0x82C0F298)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = nameString; ctx.r5.u64 = value; ctx.r6.u64 = arg4; __imp__sub_82C0F298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0F298);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t virtualFunc = LOAD32(uint32_t(objectProxy->vtable) + 68);
	callTarget.u64 = virtualFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = objectProxyAddr;
	ctx.r4.u64 = arg4;
	ctx.r5.u64 = value;
	ctx.r6.u64 = arg4;
	ctx.r10.u64 = virtualFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t result = ctx.r3.u64;
	if ((uint32_t)result != 0) {
		result = n_sub_82C0E5D8(ctx, base, result, nameString, value);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(89, sub_82C0F298, 0x82C0F298) { ctx.r3.u64 = n_sub_82C0F298(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CObjectProxy_GetDistanceTo(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint32_t arg2) {
	if (!UseLiftedCode(89, 0x82C0F2F8)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = arg2; __imp__sub_82C0F2F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C0F2F8);
	uint32_t targetObject = LOAD32((uint32_t)objectProxyAddr + 8);
	ctx.f1.f64 = ComputeDistanceToObject(ctx, base, targetObject, arg2);
	return targetObject;
}
PROMOTED_ENTRY(89, sub_82C0F2F8, 0x82C0F2F8) { ctx.r3.u64 = CObjectProxy_GetDistanceTo(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint32_t CObjectProxy_CreateFromEntityComponent(CpuState& ctx, uint8_t* base, uint32_t objectProxyAddr, uint64_t objectRecord, uint64_t owner, uint64_t source, uint64_t keyHolder) {
	if (!UseLiftedCode(89, 0x82C0F998)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = objectRecord; ctx.r5.u64 = owner; ctx.r6.u64 = source; ctx.r7.u64 = keyHolder; __imp__sub_82C0F998(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C0F998);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 192);

	uint32_t entity = LOAD32((uint32_t)objectRecord + 4);
	if (entity != 0 && LOAD32(entity + 76) != 0) {
		uint32_t filterValue = LOAD32((uint32_t)keyHolder + 16);
		uint32_t filterKey = stack + 80;
		STORE32(filterKey, filterValue);

		ctx.r1.u64 = stack;
		uint32_t foundComponent = IndexMap_Get(ctx, base, entity + 52, filterKey);
		if (foundComponent != 0) {
			uint32_t tempProxyAddr = stack + 96;
			ctx.r1.u64 = stack;
			CObjectProxy_ConstructFrom(ctx, base, tempProxyAddr, source, objectRecord, owner);

			uint32_t factory = LOAD32(foundComponent + 4);
			uint32_t createFn = LOAD32(LOAD32(factory) + 24);
			callTarget.u64 = createFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = factory;
			ctx.r4.u64 = tempProxyAddr;
			ctx.r5.u64 = keyHolder;
			ctx.r10.u64 = createFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t created = ctx.r3.u64;

			if ((uint32_t)created == 0) {
				objectProxy->vtable = 0;
				objectProxy->m_refObject = 0;
				ctx.r1.u64 = stack;
				CObjectProxy_Destruct(ctx, base, tempProxyAddr);
				stack = PopStackFrame(stack, 192);
				ctx.r1.u64 = stack;
				return objectProxyAddr;
			}

			uint32_t nameHolder = stack + 88;
			ctx.r1.u64 = stack;
			CharStringHolder_Construct(ctx, base, nameHolder);

			uint32_t factory2 = LOAD32(foundComponent + 4);
			uint32_t nameFn = LOAD32(LOAD32(factory2) + 4);
			callTarget.u64 = nameFn;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = factory2;
			ctx.r10.u64 = nameFn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint64_t name = ctx.r3.u64;

			ctx.r1.u64 = stack;
			RefCountedStringHolder_Assign(ctx, base, nameHolder, name);

			ctx.r1.u64 = stack;
			uint64_t memberValue = C_8200E8D8_GetMember4(ctx, base, nameHolder);

			uint32_t tempRefObject = LOAD32(stack + 100);
			uint32_t tempExtra = LOAD32(stack + 104);
			ctx.r1.u64 = stack;
			CObjectProxy_Initialize(ctx, base, objectProxyAddr, tempRefObject, created, (uint64_t)filterValue, source, memberValue, tempExtra);

			ctx.r1.u64 = stack;
			CharStringHolder_Destructor(ctx, base, nameHolder);
			ctx.r1.u64 = stack;
			CObjectProxy_Destruct(ctx, base, tempProxyAddr);

			stack = PopStackFrame(stack, 192);
			ctx.r1.u64 = stack;
			return objectProxyAddr;
		}
	}

	objectProxy->m_refObject = 0;
	objectProxy->vtable = 0;
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C0F998, 0x82C0F998) { ctx.r3.u64 = CObjectProxy_CreateFromEntityComponent(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

uint32_t CObjectProxy_ConstructFromOwnerKey(CpuState& ctx, uint8_t* base, uint32_t proxyAddr, uint64_t owner, uint64_t arg3, uint64_t keyHolder) {
	if (!UseLiftedCode(89, 0x82C10A10)) { ctx.r3.u64 = proxyAddr; ctx.r4.u64 = owner; ctx.r5.u64 = arg3; ctx.r6.u64 = keyHolder; __imp__sub_82C10A10(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82C10A10);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, proxyAddr);
	stack = PushStackFrame(base, stack, 144);

	uint64_t mapAddr = owner + 12;
	uint32_t keyAddr = stack + 80;
	uint32_t findResultAddr = stack + 88;
	STORE32(keyAddr, LOAD32((uint32_t)keyHolder + 16));

	ctx.r1.u64 = stack;
	StdMap_Find_U32Key(ctx, base, findResultAddr, mapAddr, keyAddr);

	// the iterator found: its container, then its node
	uint32_t container = LOAD32(stack + 88);
	uint32_t endNode = LOAD32((uint32_t)owner + 16);
	if (container == 0 || container != (uint32_t)mapAddr) {
		ppc_trap(ctx, base, 22);
	}

	uint32_t node = LOAD32(stack + 92);
	if (node != endNode) {
		if (container == 0) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t sentinel = LOAD32(container + 4);
		if (node == sentinel) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t mappedValue = LOAD32(node + 16);
		if (mappedValue != 0) {
			if (node == sentinel) {
				ppc_trap(ctx, base, 22);
			}
			CObjectProxy_CreateFromEntityComponent(ctx, base, proxyAddr, mappedValue, owner, arg3, keyHolder);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return proxyAddr;
		}
	}

	objectProxy->vtable = 0;
	objectProxy->m_refObject = 0;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	// callers read r4 after the call: the map address when the key is absent, else the null mapped value
	ctx.r4.u64 = node == endNode ? mapAddr : 0;
	return proxyAddr;
}
PROMOTED_ENTRY(89, sub_82C10A10, 0x82C10A10) { ctx.r3.u64 = CObjectProxy_ConstructFromOwnerKey(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CObjectProxy_ConstructFromRequest(CpuState& ctx, uint8_t* base, uint64_t objectProxyAddr, uint64_t arg2, uint64_t keyHolder) {
	if (!UseLiftedCode(89, 0x82C10AE0)) { ctx.r3.u64 = objectProxyAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = keyHolder; __imp__sub_82C10AE0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C10AE0);
	uint32_t stack = ctx.r1.u64;
	CObjectProxy* objectProxy = GameObject<CObjectProxy>(base, objectProxyAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t request = arg2;
	uint32_t source = LOAD32(request + 12);
	if (source == 0) {
		objectProxy->vtable = 0;
		objectProxy->m_refObject = 0;
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		ctx.r4.u64 = arg2; // callers read r4 after the call
		return objectProxyAddr;
	}

	// proxy built on the game stack, released before returning
	uint32_t tempProxyAddr = stack + 80;
	ctx.r1.u64 = stack;
	CObjectProxy_CreateFromEntityComponent(ctx, base, tempProxyAddr, LOAD32(request + 4), LOAD32(request + 8), source, keyHolder);

	if (LOAD32(tempProxyAddr) != 0) {
		ObjectProxy_Assign(ctx, base, objectProxyAddr, tempProxyAddr);
	} else {
		// both fields are read again after the call, as the original does
		CObjectProxy_ConstructFromOwnerKey(ctx, base, objectProxyAddr, LOAD32(request + 8), LOAD32(request + 12), keyHolder);
	}
	OwnedPtr_Reset(ctx, base, tempProxyAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return objectProxyAddr;
}
PROMOTED_ENTRY(89, sub_82C10AE0, 0x82C10AE0) { ctx.r3.u64 = CObjectProxy_ConstructFromRequest(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CObjectProxy_FindMapValue(CpuState& ctx, uint8_t* base, uint64_t proxy, uint64_t arg2, uint32_t arg3) {
	if (!UseLiftedCode(89, 0x82C10B80)) { ctx.r3.u64 = proxy; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; __imp__sub_82C10B80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C10B80);
	uint32_t entity = LOAD32((uint32_t)proxy + 8);
	return Map_FindUIntKey(ctx, base, entity, arg2, arg3);
}
PROMOTED_ENTRY(89, sub_82C10B80, 0x82C10B80) { ctx.r3.u64 = CObjectProxy_FindMapValue(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t CObjectProxy_FindMapValueWithArgs(CpuState& ctx, uint8_t* base, uint64_t objectProxy, uint64_t arg2, uint32_t arg3, uint32_t arg4) {
	if (!UseLiftedCode(89, 0x82C10B88)) { ctx.r3.u64 = objectProxy; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_82C10B88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82C10B88);

	uint64_t proxiedObject = LOAD32((uint32_t)objectProxy + 8);
	return Map_FindUIntKeyWithArgs(ctx, base, proxiedObject, arg2, arg3, arg4);
}
PROMOTED_ENTRY(89, sub_82C10B88, 0x82C10B88) { ctx.r3.u64 = CObjectProxy_FindMapValueWithArgs(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u32); }
