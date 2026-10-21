// CSceneEntity (vtable 0x820057E0): methods of the class as readable C++.
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

// sub_821E62A8  [8 bytes]
double CSceneEntity_GetRadius(CpuState& ctx, uint8_t* base, uint32_t sceneEntityAddr) {
	if (!UseLiftedCode(4, 0x821E62A8)) { ctx.r3.u64 = sceneEntityAddr; __imp__sub_821E62A8(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x821E62A8);
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);
	ctx.fpscr.disableFlushMode();
	return double(sceneEntity->m_radius);
}
PROMOTED_ENTRY(4, sub_821E62A8, 0x821E62A8) { ctx.f1.f64 = CSceneEntity_GetRadius(ctx, base, ctx.r3.u32); }

uint64_t CSceneEntity_HandleMessage(CpuState& ctx, uint8_t* base, uint64_t sceneEntityAddr, uint64_t message, double messageFloat) {
	if (!UseLiftedCode(6, 0x82226DD8)) { ctx.r3.u64 = sceneEntityAddr; ctx.r4.u64 = message; ctx.f1.f64 = messageFloat; __imp__sub_82226DD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82226DD8);
	GameStackFrame stackFrame(ctx, base, 128);
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);

	uint64_t componentBytes = (uint64_t)sceneEntity->m_componentsEnd - (uint64_t)sceneEntity->m_componentsBegin;
	int32_t componentCount = (int32_t)componentBytes >> 2;

	// What the last component handler hands back besides its result goes on to the message's type query; before
	// any handler that is the message, the byte size of the component array and the float argument.
	uint64_t passedOnArgument = message;
	uint64_t passedOnScratch = componentBytes;
	double passedOnFloat = messageFloat;
	for (int32_t i = 0; i < componentCount; ++i) {
		ctx.fpscr.disableFlushMode();
		uint32_t component = LOAD32(uint32_t(sceneEntity->m_componentsBegin) + uint32_t(i) * 4);
		uint32_t vtable = LOAD32(component);
		uint32_t method = LOAD32(vtable + 16);
		ctx.r3.u64 = component;
		ctx.r4.u64 = message;
		ctx.r9.u64 = method;
		ctx.r10.u64 = vtable;
		ctx.f1.f64 = messageFloat;
		REX_CALL_INDIRECT_FUNC(method);
		passedOnArgument = ctx.r4.u64;
		passedOnScratch = ctx.r9.u64;
		passedOnFloat = ctx.f1.f64;
	}

	uint32_t messageVtable = LOAD32((uint32_t)message);
	uint32_t getMessageType = LOAD32(messageVtable + 4);
	ctx.r3.u64 = message;
	ctx.r4.u64 = passedOnArgument;
	ctx.r9.u64 = passedOnScratch;
	ctx.r10.u64 = getMessageType;
	ctx.f1.f64 = passedOnFloat;
	REX_CALL_INDIRECT_FUNC(getMessageType);
	uint64_t messageType = ctx.r3.u64;

	switch ((int32_t)messageType) {
	case 9:
		if (LOAD8((uint32_t)message + 10) != 0) {
			// Both aligned 16-byte blocks are read before either is written.
			PPCVRegister block64{};
			PPCVRegister block48{};
			SET_V8(block64, VLOAD(((uint32_t)message + 64) & ~0xFu));
			SET_V8(block48, VLOAD(((uint32_t)message + 48) & ~0xFu));
			uint32_t destination = (uint32_t)sceneEntityAddr + 208;
			VSTORE(destination & ~0xFu, V8(block48));
			VSTORE((destination + 16) & ~0xFu, V8(block64));
		}
		break;
	case 19: {
		uint32_t flagValue = LOAD8((uint32_t)message + 4);
		return CThing_SetFlag(ctx, base, sceneEntityAddr, 128, flagValue);
	}
	case 31: {
		uint32_t value144 = LOAD32((uint32_t)message + 4);
		sceneEntity->m_148 = uint8_t(1);
		sceneEntity->m_144 = value144;
		break;
	}
	}
	return messageType;
}
PROMOTED_ENTRY(6, sub_82226DD8, 0x82226DD8) { ctx.r3.u64 = CSceneEntity_HandleMessage(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint64_t CSceneEntity_IsBeyondRadius(CpuState& ctx, uint8_t* base, uint32_t sceneEntityAddr) {
	if (!UseLiftedCode(10, 0x8228BCD8)) { ctx.r3.u64 = sceneEntityAddr; __imp__sub_8228BCD8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x8228BCD8);
	uint32_t stack = ctx.r1.u32;
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);

	ctx.fpscr.disableFlushMode();
	double radius = double(sceneEntity->m_radius);
	double radiusSquared = double(float(radius * radius));

	PPCVRegister position;
	SET_V8(position, VLOAD((sceneEntityAddr + 240u) & ~0xF));

	ctx.fpscr.enableFlushModeUnconditional();
	PPCVRegister delta;
	SET_VF(delta, simde_mm_sub_ps(VF(position), VF(ctx.v1)));
	PPCVRegister dotProduct;
	SET_VF(dotProduct, simde_mm_dp_ps(VF(delta), VF(delta), 0xEF));
	VSTORE((stack - 16u) & 0xFFFFFFF0u, V8(dotProduct));
	ctx.fpscr.disableFlushModeUnconditional();

	return (double(LOAD_F32(stack - 16)) > radiusSquared) ? 1 : 0;
}
PROMOTED_ENTRY(10, sub_8228BCD8, 0x8228BCD8) { ctx.r3.u64 = CSceneEntity_IsBeyondRadius(ctx, base, ctx.r3.u32); }

uint64_t CSceneEntity_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t sceneEntityAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(76, 0x82A78448)) { ctx.r3.u64 = sceneEntityAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82A78448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78448);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CSceneEntity_Destruct(ctx, base, sceneEntityAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, sceneEntityAddr);
	}
	return sceneEntityAddr;
}
PROMOTED_ENTRY(76, sub_82A78448, 0x82A78448) { ctx.r3.u64 = CSceneEntity_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CSceneEntity_Destruct(CpuState& ctx, uint8_t* base, uint64_t sceneEntityAddr) {
	if (!UseLiftedCode(76, 0x82A78498)) { ctx.r3.u64 = sceneEntityAddr; __imp__sub_82A78498(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82A78498);
	constexpr uint32_t CSceneEntity_vtable = 0x820057E0;
	GameStackFrame stackFrame(ctx, base, 128);
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);

	sceneEntity->vtable = CSceneEntity_vtable;

	uint64_t component = sceneEntity->m_componentsBegin;
	uint64_t componentBytes = (uint64_t)sceneEntity->m_componentsEnd - component;
	int32_t componentCount = (int32_t)componentBytes >> 2;
	for (int32_t i = 0; i < componentCount; ++i) {
		component = LOAD32(uint32_t(sceneEntity->m_componentsBegin) + uint32_t(i) * 4);
		STORE32((uint32_t)component + 0x1E4, 0);
	}

	// The byte size and the last component read stay in the two registers the next two calls receive.
	uint32_t handleTarget = sceneEntity->m_handleTarget;
	if (handleTarget != 0) {
		ctx.r7.u64 = componentBytes;
		ctx.r8.u64 = component;
		HandleTarget_Free(ctx, base, handleTarget);
		componentBytes = ctx.r7.u64;
		component = ctx.r8.u64;
		sceneEntity->m_handleTarget = 0;
	}
	ctx.r7.u64 = componentBytes;
	ctx.r8.u64 = component;
	GlobalObject_Destroy(ctx, base, sceneEntityAddr + 304);

	uint32_t refCountedData = sceneEntity->m_refCountedData;
	if (refCountedData != 0) {
		uint64_t refCountAddr = (uint64_t)refCountedData + 4;
		uint32_t oldCount;
		uint32_t newCount;
		do {
			oldCount = LOAD32((uint32_t)refCountAddr);
			newCount = oldCount - 1;
		} while (!__sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)refCountAddr)),
		                                       __builtin_bswap32(oldCount), __builtin_bswap32(newCount)));
		if (newCount == 0) {
			uint32_t vtable = LOAD32(refCountedData);
			uint32_t method = LOAD32(vtable + 4);
			ctx.r3.u64 = refCountedData;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(method);
		}
		sceneEntity->m_refCountedData = 0;
	}

	// The arrays at +0xC4 and at +0xB4 (the components): storage freed, begin, end and capacity cleared.
	uint32_t arrayC4Begin = sceneEntity->m_C4;
	if (arrayC4Begin != 0) {
		HandleTarget_Free(ctx, base, arrayC4Begin);
	}
	sceneEntity->m_C8 = 0;
	sceneEntity->m_CC = 0;
	sceneEntity->m_C4 = 0;

	uint32_t componentsBegin = sceneEntity->m_componentsBegin;
	if (componentsBegin != 0) {
		HandleTarget_Free(ctx, base, componentsBegin);
	}
	sceneEntity->m_componentsBegin = 0;
	sceneEntity->m_componentsEnd = 0;
	sceneEntity->m_componentsCapacity = 0;

	return CThingComponent_Destruct_82B15910(ctx, base, sceneEntityAddr);
}
PROMOTED_ENTRY(76, sub_82A78498, 0x82A78498) { ctx.r3.u64 = CSceneEntity_Destruct(ctx, base, ctx.r3.u64); }

uint64_t CSceneEntity_ApplyCreateInfo(CpuState& ctx, uint8_t* base, uint64_t sceneEntityAddr, uint64_t sourceObject) {
	if (!UseLiftedCode(76, 0x82A78800)) { ctx.r3.u64 = sceneEntityAddr; ctx.r4.u64 = sourceObject; __imp__sub_82A78800(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78800);
	constexpr uint32_t fill208Address = 0x82000BE0;   // (float constants)
	constexpr uint32_t fill224Address = 0x82000C10;
	constexpr int32_t matchingSourceType = 42;
	uint32_t stack = ctx.r1.u64;
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);
	uint32_t source = (uint32_t)sourceObject;
	stack = PushStackFrame(base, stack, 112);

	uint32_t createFlags = LOAD32(source + 4);
	ctx.r1.u64 = stack;
	CThing_ApplyCreateFlags(ctx, base, sceneEntityAddr, createFlags);

	uint32_t sourceVtable = LOAD32(source);
	uint32_t getSourceType = LOAD32(sourceVtable + 4);
	ctx.r3.u64 = sourceObject;
	ctx.r10.u64 = getSourceType;
	REX_CALL_INDIRECT_FUNC(getSourceType);
	uint64_t result = ctx.r3.u64;
	uint64_t secondResult = ctx.r4.u64;

	if ((int32_t)result == matchingSourceType) {
		ctx.fpscr.disableFlushMode();
		sceneEntity->m_118 = float(double(LOAD_F32(source + 12)));

		// Take the source's reference-counted object at +8 in place of the current one.
		uint32_t oldData = sceneEntity->m_refCountedData;
		if ((int32_t)oldData != int32_t(LOAD32(source + 8))) {
			if (oldData != 0) {
				uint64_t oldCountAddr = (uint64_t)oldData + 4;
				uint32_t oldCount;
				uint32_t newCount;
				do {
					oldCount = LOAD32((uint32_t)oldCountAddr);
					newCount = oldCount - 1;
				} while (!__sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)oldCountAddr)),
				                                       __builtin_bswap32(oldCount), __builtin_bswap32(newCount)));
				if (newCount == 0) {
					uint32_t vtable = LOAD32(oldData);
					uint32_t method = LOAD32(vtable + 4);
					ctx.r3.u64 = oldData;
					ctx.r9.u64 = oldCountAddr;
					ctx.r10.u64 = method;
					REX_CALL_INDIRECT_FUNC(method);
				}
				sceneEntity->m_refCountedData = 0u;
			}
			uint32_t newData = LOAD32(source + 8);
			sceneEntity->m_refCountedData = newData;
			if (newData != 0) {
				uint32_t newCountAddr = newData + 4;
				uint32_t oldCount;
				uint32_t newCount;
				do {
					oldCount = LOAD32(newCountAddr);
					newCount = oldCount + 1;
				} while (!__sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(newCountAddr)),
				                                       __builtin_bswap32(oldCount), __builtin_bswap32(newCount)));
			}
		}

		uint32_t value144 = LOAD32(source + 16);
		ctx.fpscr.disableFlushMode();
		float fill208 = float(double(LOAD_F32(fill208Address)));
		STORE_F32(stack + 80, fill208);
		float fill224 = float(double(LOAD_F32(fill224Address)));
		sceneEntity->m_144 = value144;
		STORE_F32(stack + 84, fill224);
		sceneEntity->m_148 = uint8_t(1);

		// Each constant fills one aligned 16-byte block (+208, +224); the block at +240 is cleared.
		uint32_t block208 = ((uint32_t)sceneEntityAddr + 208) & ~0xFu;
		uint32_t block240 = ((uint32_t)sceneEntityAddr + 240) & ~0xFu;
		for (uint32_t lane = 0; lane < 4; ++lane) {
			STORE_F32(block208 + lane * 4, fill208);
			STORE_F32(block208 + 16 + lane * 4, fill224);
			STORE32(block240 + lane * 4, 0);
		}

		secondResult = 240;
		result = 1;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(76, sub_82A78800, 0x82A78800) { ctx.r3.u64 = CSceneEntity_ApplyCreateInfo(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CSceneEntity_AppendSubObject(CpuState& ctx, uint8_t* base, uint32_t sceneEntity, uint64_t vector) {
	if (!UseLiftedCode(76, 0x82A78948)) { ctx.r3.u64 = sceneEntity; ctx.r5.u64 = vector; __imp__sub_82A78948(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78948);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	uint64_t entityFieldPtr = (uint64_t)stack + 80;
	STORE32(stack + 80, sceneEntity + 304);
	ctx.r1.u64 = stack;
	uint64_t result = PtrVector_PushBackGrow(ctx, base, vector, entityFieldPtr);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(76, sub_82A78948, 0x82A78948) { ctx.r3.u64 = CSceneEntity_AppendSubObject(ctx, base, ctx.r3.u32, ctx.r5.u64); }

uint64_t CSceneEntity_GetSubObject(CpuState& ctx, uint8_t* base, uint64_t sceneEntityAddr) {
	if (!UseLiftedCode(76, 0x82A78978)) { ctx.r3.u64 = sceneEntityAddr; __imp__sub_82A78978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78978);
	return sceneEntityAddr + 304;
}
PROMOTED_ENTRY(76, sub_82A78978, 0x82A78978) { ctx.r3.u64 = CSceneEntity_GetSubObject(ctx, base, ctx.r3.u64); }

uint64_t CSceneEntity_AllComponentsAccept(CpuState& ctx, uint8_t* base, uint32_t sceneEntityAddr, uint64_t visitorArg) {
	if (!UseLiftedCode(76, 0x82A78B18)) { ctx.r3.u64 = sceneEntityAddr; ctx.r4.u64 = visitorArg; __imp__sub_82A78B18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82A78B18);
	CSceneEntity* sceneEntity = GameObject<CSceneEntity>(base, sceneEntityAddr);
	// Two more values go to every component call: for the first, what the caller left in those registers; for each
	// later one, the running result before the previous call and the previous call's own result.
	uint64_t previousAllAccepted = ctx.r7.u64;
	uint64_t lastAccepted = ctx.r8.u64;
	GameStackFrame stackFrame(ctx, base, 128);

	uint64_t allAccepted = 1;
	uint64_t secondResult = visitorArg;
	int32_t componentCount = (int32_t)((uint64_t)sceneEntity->m_componentsEnd - (uint64_t)sceneEntity->m_componentsBegin) >> 2;
	for (int32_t i = 0; i < componentCount; ++i) {
		uint32_t component = LOAD32(uint32_t(sceneEntity->m_componentsBegin) + uint32_t(i) * 4);
		uint32_t vtable = LOAD32(component);
		uint32_t method = LOAD32(vtable + 64);
		ctx.r3.u64 = component;
		ctx.r4.u64 = visitorArg;
		ctx.r7.u64 = previousAllAccepted;
		ctx.r8.u64 = lastAccepted;
		ctx.r9.u64 = method;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(method);
		uint32_t accepted = ctx.r3.u32;
		secondResult = ctx.r4.u64;
		lastAccepted = accepted & 0xFF;
		previousAllAccepted = (uint32_t)allAccepted & 0xFF;
		allAccepted = lastAccepted & previousAllAccepted;
	}

	ctx.r4.u64 = secondResult;
	return allAccepted;
}
PROMOTED_ENTRY(76, sub_82A78B18, 0x82A78B18) { ctx.r3.u64 = CSceneEntity_AllComponentsAccept(ctx, base, ctx.r3.u32, ctx.r4.u64); }
