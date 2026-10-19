// CCameraEffectController (vtable 0x820028E4): methods of the class as readable C++.
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

uint64_t n_sub_821C3320(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr) {
	if (!UseLiftedCode(2, 0x821C3320)) { ctx.r3.u64 = cameraEffectControllerAddr; __imp__sub_821C3320(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821C3320);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 112);

	// The f13 value handed to the callees below: the incoming one, the delay timer once read, then what the handle calls leave.
	double f13Value = ctx.f13.f64;

	// With m_34 clear, the result is 0 while the delay timer is below the threshold.
	if (cameraEffectController->m_34 == 0) {
		ctx.fpscr.disableFlushMode();
		f13Value = double(cameraEffectController->m_delayTimer);
		if (f13Value < double(LOAD_F32(0x820994B4u))) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0;
		}
	}

	// Mode 31 also needs a live target entity with bit 0x40 set in its byte at +144.
	uint32_t mode = cameraEffectController->m_mode;
	if (mode == 31) {
		uint64_t targetHandleAddr = cameraEffectControllerAddr + 24;
		uint32_t targetEntityHandle = cameraEffectController->m_targetEntityHandle;
		bool hasValidTarget = false;
		if (targetEntityHandle != 0) {
			uint32_t handleValue = LOAD32(targetEntityHandle);
			// state the callee may pass on
			ctx.r1.u64 = stack;
			ctx.r10.u64 = handleValue;
			ctx.f13.f64 = f13Value;
			if (handleValue == 0) {
				EntityHandle_Release(ctx, base, targetHandleAddr);
			} else {
				uint32_t entity = EntityHandle_Get_825575C8(ctx, base, targetHandleAddr);
				hasValidTarget = (LOAD8(entity + 144) & 64) != 0;
			}
			f13Value = ctx.f13.f64;
		}
		if (!hasValidTarget) {
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 0;
		}
	}

	// The result is 1 when the squared length of the first three components of the vector n_sub_821DE960 returns exceeds the threshold.
	uint32_t vectorBufferAddr = stack + 80;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	uint32_t vectorAddr = n_sub_821DE960(ctx, base, vectorBufferAddr, cameraEffectControllerAddr);
	PPCVRegister vector{};
	SET_V8(vector, VLOAD(vectorAddr & ~0xFu));
	ctx.fpscr.enableFlushMode();
	PPCVRegister lengthSquared{};
	SET_VF(lengthSquared, simde_mm_dp_ps(VF(vector), VF(vector), 0xEF));
	ctx.fpscr.disableFlushModeUnconditional();
	VSTORE(vectorBufferAddr & ~0xFu, V8(lengthSquared));

	uint32_t exceedsThreshold = 0;
	if (double(LOAD_F32(vectorBufferAddr)) > double(LOAD_F32(0x82099AE0u))) {
		exceedsThreshold = 1;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return exceedsThreshold;
}
PROMOTED_ENTRY(2, sub_821C3320, 0x821C3320) { ctx.r3.u64 = n_sub_821C3320(ctx, base, ctx.r3.u64); }

// sub_822D7EA0  [84 bytes]
double CCameraEffectController_GetModeValue(CpuState& ctx, uint8_t* base, uint32_t cameraEffectControllerAddr) {
	if (!UseLiftedCode(13, 0x822D7EA0)) { ctx.r3.u64 = cameraEffectControllerAddr; __imp__sub_822D7EA0(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x822D7EA0);
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	uint32_t mode = cameraEffectController->m_mode;

	// Modes 24..60 dispatch through the jump table at 0x822D7EC8; the table entry is left in r0 for callers.
	uint32_t jumpTableIndex = mode - 24;
	if (jumpTableIndex <= 36) {
		ctx.r0.u64 = LOAD32(0x822D7EC8u + jumpTableIndex * 4);
	}

	ctx.fpscr.disableFlushMode();
	switch (mode) {
	case 24: case 25: case 26: case 27: case 28: case 29: case 30:
	case 55: case 56: case 57: case 58:
		return double(LOAD_F32(0x8209BE50u));
	case 59:
	case 60:
		return double(LOAD_F32(0x8209BE4Cu));
	default:
		return double(LOAD_F32(0x8209BE48u));
	}
}
PROMOTED_ENTRY(13, sub_822D7EA0, 0x822D7EA0) { ctx.f1.f64 = CCameraEffectController_GetModeValue(ctx, base, ctx.r3.u32); }

// sub_827D0F48  [116 bytes]
uint64_t CCameraEffectController_Destruct(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(54, 0x827D0F48)) { ctx.r3.u64 = cameraEffectControllerAddr; ctx.r4.u64 = deleteFlags; __imp__sub_827D0F48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D0F48);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 112);
	cameraEffectController->vtable = 0x820028E4u;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	CCameraEffectController_ReleaseHandles(ctx, base, cameraEffectControllerAddr);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, cameraEffectControllerAddr + 148);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, cameraEffectControllerAddr + 140);
	CWorldIcon_Destructor(ctx, base, cameraEffectControllerAddr);
	if (uint32_t(deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, cameraEffectControllerAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return cameraEffectControllerAddr;
}
PROMOTED_ENTRY(54, sub_827D0F48, 0x827D0F48) { ctx.r3.u64 = CCameraEffectController_Destruct(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827D1090(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr, uint64_t effectDataAddr) {
	if (!UseLiftedCode(54, 0x827D1090)) { ctx.r3.u64 = cameraEffectControllerAddr; ctx.r4.u64 = effectDataAddr; __imp__sub_827D1090(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1090);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 160);

	uint32_t effectAddr = (uint32_t)effectDataAddr;
	// r4 as left for callers: the input, or what n_sub_821DECC8 leaves in it.
	uint64_t callerR4 = effectDataAddr;

	// Flag 0x2 in the word at +0x48 asks for the six values at +0x4C to be rebuilt; the flag is cleared afterwards.
	if ((LOAD32(effectAddr + 0x48) & 2) != 0) {
		ctx.fpscr.disableFlushMode();
		double valueA0 = double(LOAD_F32(effectAddr + 0xA0));
		double constantValue = double(LOAD_F32(0x820994B4u));
		uint32_t sourceAddr;
		if (valueA0 == constantValue) {
			// six copies of the constant, built on the stack
			sourceAddr = stack + 80;
			for (uint32_t i = 0; i < 6; ++i) {
				STORE_F32(sourceAddr + 4 * i, float(constantValue));
			}
		} else {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			uint64_t vec4Addr = n_sub_827D0FC0(ctx, base, stack + 80, effectDataAddr);
			sourceAddr = n_sub_821DECC8(ctx, base, stack + 112, effectDataAddr, vec4Addr);
			callerR4 = ctx.r4.u64;
		}
		for (uint32_t i = 0; i < 6; ++i) {
			STORE32(effectAddr + 0x4C + 4 * i, LOAD32(sourceAddr + 4 * i));
		}
		STORE32(effectAddr + 0x48, LOAD32(effectAddr + 0x48) & ~2u);
	}

	// Copy the six values to offsets 0x00..0x14 of the output.
	ctx.fpscr.disableFlushMode();
	float value0 = LOAD_F32(effectAddr + 0x4C);
	float value1 = LOAD_F32(effectAddr + 0x50);
	float value2 = LOAD_F32(effectAddr + 0x54);
	float value3 = LOAD_F32(effectAddr + 0x58);
	float value4 = LOAD_F32(effectAddr + 0x5C);
	float value5 = LOAD_F32(effectAddr + 0x60);
	cameraEffectController->vtable = AS_U32(value0);
	cameraEffectController->m_4 = value1;
	cameraEffectController->m_8 = value2;
	cameraEffectController->m_C = value3;
	cameraEffectController->m_10 = value4;
	cameraEffectController->m_mode = AS_U32(value5);

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	// callers read r4 after the call
	ctx.r4.u64 = callerR4;
	return cameraEffectControllerAddr;
}
PROMOTED_ENTRY(54, sub_827D1090, 0x827D1090) { ctx.r3.u64 = n_sub_827D1090(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_827D11A8  [92 bytes]
uint64_t CCameraEffectController_ResetBlend(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr, uint64_t initDataAddr) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	if (!UseLiftedCode(54, 0x827D11A8)) { ctx.r3.u64 = cameraEffectControllerAddr; ctx.r4.u64 = initDataAddr; __imp__sub_827D11A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D11A8);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	// n_sub_827D2830 copies fields of the data at initDataAddr into the object.
	uint64_t result = n_sub_827D2830(ctx, base, cameraEffectControllerAddr, initDataAddr);

	// constants at 0x820994B4 (reset value) and 0x820994C0 (blend duration)
	uint32_t constantsAddr = uint32_t(g_820A0000) - 27468;
	ctx.fpscr.disableFlushMode();
	float resetValue = LOAD_F32(constantsAddr);
	cameraEffectController->m_elapsedTime = resetValue;
	cameraEffectController->m_blendCurrent = resetValue;
	cameraEffectController->m_blendElapsed = resetValue;
	cameraEffectController->m_blendFrom = resetValue;
	cameraEffectController->m_B0 = resetValue;
	cameraEffectController->m_blendDuration = LOAD_F32(constantsAddr + 12);
	cameraEffectController->m_blendTarget = cameraEffectController->m_40;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(54, sub_827D11A8, 0x827D11A8) { ctx.r3.u64 = CCameraEffectController_ResetBlend(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CCameraEffectController_SetMode(CpuState& ctx, uint8_t* base, uint32_t cameraEffectControllerAddr, uint32_t newMode) {
	if (!UseLiftedCode(54, 0x827D1208)) { ctx.r3.u64 = cameraEffectControllerAddr; ctx.r4.u64 = newMode; __imp__sub_827D1208(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1208);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 112);
	uint32_t modeStringAddr = stack + 84;
	cameraEffectController->m_mode = newMode;
	ctx.r1.u64 = stack;
	uint32_t modeStringSource = n_sub_827D2AB8(ctx, base, modeStringAddr, cameraEffectControllerAddr);
	uint32_t nameStringAddr = stack + 80;
	CCharString_CopyTransformed(ctx, base, nameStringAddr, modeStringSource);
	uint32_t nameHash = n_sub_82BFD780(ctx, base, nameStringAddr);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, nameStringAddr);
	cameraEffectController->m_nameHash = nameHash;
	uint64_t releaseResult = CCharString_ReleaseAndDecGlobalCountA(ctx, base, modeStringAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(54, sub_827D1208, 0x827D1208) { ctx.r3.u64 = CCameraEffectController_SetMode(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_827D1278  [188 bytes]
uint64_t CCameraEffectController_ReleaseHandles(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(54, 0x827D1278)) { ctx.r3.u64 = cameraEffectControllerAddr; __imp__sub_827D1278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1278);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 128);

	constexpr uint32_t kInvalidHandle = 0xFFFFFFFF;
	uint64_t result = cameraEffectControllerAddr;

	// A valid handle is inserted into the list at manager + 144, before the node at manager + 148, and the field is invalidated.
	auto releaseHandle = [&](auto& handleField) {
		uint32_t handle = handleField;
		if (handle == kInvalidHandle) {
			return;
		}
		STORE32(stack + 80, handle);
		uint32_t manager = LOAD32(uint32_t(g_83490000) + 26788);
		uint32_t list = manager + 144;
		// the insert position goes by value as the 8-byte pair {list, node}
		STORE32(stack + 88, list);
		STORE32(stack + 92, LOAD32(manager + 148));
		uint64_t insertPosition = LOAD64(stack + 88);
		ctx.r1.u64 = stack;
		result = List_InsertNodeCopyWord(ctx, base, list, insertPosition, stack + 80);
		handleField = kInvalidHandle;
	};
	releaseHandle(cameraEffectController->m_88);
	releaseHandle(cameraEffectController->m_90);
	releaseHandle(cameraEffectController->m_98);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(54, sub_827D1278, 0x827D1278) { ctx.r3.u64 = CCameraEffectController_ReleaseHandles(ctx, base, ctx.r3.u64); }

// sub_827D1338  [4 bytes]
uint64_t CCameraEffectController_ReleaseHandlesThunk(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr) {
	if (!UseLiftedCode(54, 0x827D1338)) { ctx.r3.u64 = cameraEffectControllerAddr; __imp__sub_827D1338(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1338);
	return CCameraEffectController_ReleaseHandles(ctx, base, cameraEffectControllerAddr);
}
PROMOTED_ENTRY(54, sub_827D1338, 0x827D1338) { ctx.r3.u64 = CCameraEffectController_ReleaseHandlesThunk(ctx, base, ctx.r3.u64); }

uint64_t CCameraEffectController_SetNames(CpuState& ctx, uint8_t* base, uint64_t cameraEffectController, uint64_t firstName, uint64_t secondName) {
	if (!UseLiftedCode(54, 0x827D1340)) { ctx.r3.u64 = cameraEffectController; ctx.r4.u64 = firstName; ctx.r5.u64 = secondName; __imp__sub_827D1340(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1340);
	GameStackFrame stackFrame(ctx, base, 112);
	CCharString_AssignShared(ctx, base, cameraEffectController + 0x8C, firstName);
	return CCharString_AssignShared(ctx, base, cameraEffectController + 0x94, secondName);
}
PROMOTED_ENTRY(54, sub_827D1340, 0x827D1340) { ctx.r3.u64 = CCameraEffectController_SetNames(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint32_t n_sub_827D2EE8(CpuState& ctx, uint8_t* base, uint64_t cameraEffectControllerAddr) {
	if (!UseLiftedCode(54, 0x827D2EE8)) { ctx.r3.u64 = cameraEffectControllerAddr; __imp__sub_827D2EE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827D2EE8);
	uint32_t stack = ctx.r1.u64;
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	stack = PushStackFrame(base, stack, 112);

	// Target entity handle at +24: released when its entity is gone, otherwise the entity's flag bit is tested.
	uint64_t result = cameraEffectControllerAddr;
	uint64_t handleAddr = cameraEffectControllerAddr + 24;
	bool targetFlagged = false;
	uint32_t targetEntityHandle = cameraEffectController->m_targetEntityHandle;
	if (targetEntityHandle != 0) {
		uint32_t entity = LOAD32(targetEntityHandle);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r10.u64 = entity;
		if (entity == 0) {
			result = EntityHandle_Release(ctx, base, handleAddr);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
			targetFlagged = (LOAD8((uint32_t)result + 144) & 64) != 0;
		}
	}

	if (targetFlagged) {
		// state the callee may pass on: r10 still holds the flag bit tested above
		ctx.r1.u64 = stack;
		result = EntityHandle_Get_825575C8(ctx, base, handleAddr);
		uint32_t entityAddr = (uint32_t)result;

		if ((LOAD32(entityAddr + 40) >> 15) & 1) {
			// Value of key 47 in the entity's sorted (key, value) table at +72 / +76.
			uint32_t entryValue;
			uint32_t keyIndexTable = LOAD32(entityAddr + 140);
			if (keyIndexTable != 0) {
				// byte 47 of the index table is the entry number of key 47
				uint32_t entryAddr = (uint32_t)(LOAD8(keyIndexTable + 47) << 3) + LOAD32(entityAddr + 72);
				entryValue = LOAD32(entryAddr + 4);
			} else {
				// lower_bound over the table: first entry whose key is >= 47
				uint32_t begin = LOAD32(entityAddr + 72);
				uint32_t end = LOAD32(entityAddr + 76);
				STORE32(stack + 80, 0u);
				STORE32(stack + 84, begin);
				uint32_t byteSpan = end - begin;
				int32_t count = (int32_t)byteSpan >> 3;
				// callers read cr0 and xer.ca as the entry-count shift left them
				ctx.xer.ca = (int32_t)byteSpan < 0 && (byteSpan & 7) != 0;
				ctx.cr0.compare<int32_t>(count, 0, ctx.xer);
				uint32_t it = begin;
				if (count > 0) {
					ctx.xer.ca = 0; // the halving shifts below only see positive counts
					do {
						int32_t half = count >> 1;
						uint32_t mid = it + (uint32_t)(half << 3);
						if ((int32_t)LOAD32(mid) < 47) {
							it = mid + 8;
							count = count - half - 1;
						} else {
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, it);
				}
				if (it != end && (int32_t)LOAD32(it) <= 47) {
					STORE64(stack + 80, LOAD64(stack + 80));
					entryValue = LOAD32(it + 4);
				} else {
					entryValue = LOAD32(end + 4);
				}
			}

			// Position of the value at +44 between +112 and +116, mapped by the constants at 0x8209B76C / 0x8209B674.
			ctx.fpscr.disableFlushMode();
			double from = (double)LOAD_F32(entryValue + 112);
			double current = (double)LOAD_F32(entryValue + 44);
			double to = (double)LOAD_F32(entryValue + 116);
			double numerator = double(float(current - from));
			double denominator = double(float(to - from));
			double scale = double(LOAD_F32(0x8209B76Cu));
			double offset = double(LOAD_F32(0x8209B674u));
			cameraEffectController->m_38 = float(double(float(std::fma(double(float(numerator / denominator)), scale, offset))));
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return (uint32_t)result;
}
PROMOTED_ENTRY(54, sub_827D2EE8, 0x827D2EE8) { ctx.r3.u64 = n_sub_827D2EE8(ctx, base, ctx.r3.u64); }

void CCameraEffectController_SetColorBytes(CpuState& ctx, uint8_t* base, uint32_t cameraEffectControllerAddr, uint32_t colorBytesAddr) {
	if (!UseLiftedCode(54, 0x827D33A0)) { ctx.r3.u64 = cameraEffectControllerAddr; ctx.r4.u64 = colorBytesAddr; __imp__sub_827D33A0(ctx, base); return; }
	LiftedFrame frame(0x827D33A0);
	CCameraEffectController* cameraEffectController = GameObject<CCameraEffectController>(base, cameraEffectControllerAddr);
	cameraEffectController->m_3C = LOAD8(colorBytesAddr);
	cameraEffectController->m_3D = LOAD8(colorBytesAddr + 1);
	cameraEffectController->m_3E = LOAD8(colorBytesAddr + 2);
	cameraEffectController->m_3F = LOAD8(colorBytesAddr + 3);
}
PROMOTED_ENTRY(54, sub_827D33A0, 0x827D33A0) { CCameraEffectController_SetColorBytes(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_827D3A08(CpuState& ctx, uint8_t* base, uint64_t effectController) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(54, 0x827D3A08)) { ctx.r3.u64 = effectController; __imp__sub_827D3A08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D3A08);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 144);

	PPCRegister callTarget{};

	// Pointer chain from the global at 0x83496920 to an object with an entity handle at +104.
	// The two middle links are kept in r8/r9 for the calls below; after each call they hold what it left there.
	uint32_t globalObject = LOAD32(uint32_t(g_83490000) + 26912);
	uint64_t stateR9 = LOAD32(LOAD32(globalObject + 12) + 88);
	uint64_t stateR8 = LOAD32((uint32_t)stateR9 + 4);
	uint32_t handleOwner = LOAD32((uint32_t)stateR8);

	// Handle at handleOwner + 104: keep its entity, or release the handle when the entity is gone.
	uint64_t result = (uint64_t)handleOwner + 104;
	uint32_t ownerEntity = 0;
	uint32_t ownerHandleSlot = LOAD32(handleOwner + 108);
	if (ownerHandleSlot != 0) {
		uint32_t entity = LOAD32(ownerHandleSlot);
		if (entity != 0) {
			ownerEntity = entity;
		} else {
			// state the callee may pass on
			ctx.r1.u64 = stack;
			result = EntityHandle_Release(ctx, base, result);
			stateR8 = ctx.r8.u64;
			stateR9 = ctx.r9.u64;
		}
	}

	// The controller's own entity handle at +24: released when its entity is gone, otherwise the flag bit is tested.
	uint64_t ownHandle = effectController + 24;
	bool ownEntityFlagged = false;
	uint32_t ownHandleSlot = LOAD32((uint32_t)ownHandle + 4);
	if (ownHandleSlot != 0) {
		uint32_t entity = LOAD32(ownHandleSlot);
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r8.u64 = stateR8;
		ctx.r9.u64 = stateR9;
		ctx.r10.u64 = entity;
		if (entity == 0) {
			result = EntityHandle_Release(ctx, base, ownHandle);
		} else {
			result = EntityHandle_Get_825575C8(ctx, base, ownHandle);
			ownEntityFlagged = (LOAD8((uint32_t)result + 144) & 64) != 0;
		}
		stateR8 = ctx.r8.u64;
		stateR9 = ctx.r9.u64;
	}

	if (ownEntityFlagged && ownerEntity != 0 && (LOAD8(ownerEntity + 144) & 64) != 0) {
		// Virtual slot +64 of the object at +124 of each entity, called with a stack buffer in r3 and the object in r4.
		uint32_t ownerTarget = LOAD32(ownerEntity + 124);
		uint32_t ownerMethod = LOAD32(LOAD32(ownerTarget) + 64);
		callTarget.u64 = ownerMethod;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = stack + 80;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint64_t ownEntity = EntityHandle_Get_825575C8(ctx, base, ownHandle);
		uint32_t ownTarget = LOAD32((uint32_t)ownEntity + 124);
		uint32_t ownTargetVtable = LOAD32(ownTarget);
		uint32_t ownMethod = LOAD32(ownTargetVtable + 64);
		callTarget.u64 = ownMethod;
		ctx.r3.u64 = stack + 96;
		ctx.r4.u64 = ownTarget;
		ctx.r7.u64 = ownMethod;
		ctx.r8.u64 = ownTargetVtable;
		ctx.r9.u64 = ownEntity;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(54, sub_827D3A08, 0x827D3A08) { ctx.r3.u64 = n_sub_827D3A08(ctx, base, ctx.r3.u64); }
