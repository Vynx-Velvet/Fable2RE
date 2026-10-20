// CECEntityModeManager (vtable 0x82003B58): methods of the class as readable C++.
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

uint64_t n_sub_821FEA40(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t targetObjectAddr) {
	if (!UseLiftedCode(5, 0x821FEA40)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = targetObjectAddr; __imp__sub_821FEA40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821FEA40);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t targetObject = (uint32_t)targetObjectAddr;
	uint32_t vtable = LOAD32(targetObject);
	uint32_t methodAddr = LOAD32(vtable + 4);
	callTarget.u64 = methodAddr;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = targetObjectAddr;
	ctx.r4.u64 = targetObjectAddr;
	ctx.r10.u64 = methodAddr;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t modeResult = ctx.r3.u64;
	if ((int32_t)modeResult == 8) {
		modeResult = Vector_RemoveByValue(ctx, base, entityModeManager->m_4, entityModeManagerAddr);
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return modeResult;
}
PROMOTED_ENTRY(5, sub_821FEA40, 0x821FEA40) { ctx.r3.u64 = n_sub_821FEA40(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECEntityModeManager_HasMode(CpuState& ctx, uint8_t* base, uint32_t entityModeManagerAddr, uint64_t requestedMode) {
	if (!UseLiftedCode(5, 0x821FF4E0)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = requestedMode; __imp__sub_821FF4E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821FF4E0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// Circular list of modes at +0x14; m_18 is its end node. The result compares against the end
	// read here, while the walk re-reads the end on every step.
	uint32_t listEnd = entityModeManager->m_18;
	uint32_t modeList = entityModeManagerAddr + 20;
	uint64_t r4Value = requestedMode;   // r4 as the previous getter call left it

	STORE32(stack + 80, modeList);
	uint32_t node = LOAD32(listEnd);
	STORE32(stack + 84, node);

	while (node != LOAD32(modeList + 4)) {
		uint32_t mode = LOAD32(node + 8);
		uint32_t getModeFn = LOAD32(LOAD32(mode) + 4);
		callTarget.u64 = getModeFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = mode;
		ctx.r4.u64 = r4Value;
		ctx.r10.u64 = getModeFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t modeValue = ctx.r3.u32;
		r4Value = ctx.r4.u64;
		if ((int32_t)modeValue == (int32_t)requestedMode) {
			break;
		}
		// iterator check before stepping: the node must not be the end
		if (node == LOAD32(modeList + 4)) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}
	STORE32(stack + 84, node);
	// iterator check: its list pointer must be set
	if (modeList == 0) {
		ctx.r1.u64 = stack;
		ppc_trap(ctx, base, 22);
	}

	uint32_t distance = listEnd - node;
	uint64_t leadingZeros = distance == 0 ? 32 : __builtin_clz(distance);
	uint32_t atListEnd = (uint32_t)leadingZeros >> 5 & 1;

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4, r9 and r10 after the call
	ctx.r4.u64 = r4Value;
	ctx.r9.u64 = atListEnd;
	ctx.r10.u64 = leadingZeros;
	return atListEnd ^ 1;
}
PROMOTED_ENTRY(5, sub_821FF4E0, 0x821FF4E0) { ctx.r3.u64 = CECEntityModeManager_HasMode(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CECEntityModeManager_UpdateAnimations(CpuState& ctx, uint8_t* base, uint64_t managerAddr) {
	if (!UseLiftedCode(6, 0x82218498)) { ctx.r3.u64 = managerAddr; __imp__sub_82218498(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82218498);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	uint32_t modeList = (uint32_t)managerAddr + 0x14;
	uint32_t foundIter = stack + 80;   // {list, node} written by the lookup
	uint64_t result = 0;
	// r7 and r9 are carried from call to call
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r9Value = ctx.r9.u64;

	for (uint64_t id = 0; (int32_t)id != 10; ++id) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r7.u64 = r7Value;
		ctx.r9.u64 = r9Value;
		result = AnimationComponent_FindAnimation(ctx, base, foundIter, managerAddr, id);
		r7Value = ctx.r7.u64;
		uint32_t iterList = LOAD32(foundIter);
		uint32_t listEnd = LOAD32(modeList + 4);
		r9Value = listEnd;

		// iterator check: it must belong to this list
		if (iterList == 0 || iterList != modeList) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t node = LOAD32(foundIter + 4);
		if (node == listEnd) {
			continue;   // nothing found for this id
		}
		// iterator checks before dereferencing
		if (iterList == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (node == LOAD32(iterList + 4)) {
			ppc_trap(ctx, base, 22);
		}

		uint32_t mode = LOAD32(node + 8);
		uint32_t fn40 = LOAD32(LOAD32(mode) + 0x40);
		callTarget.u64 = fn40;
		ctx.r3.u64 = mode;
		ctx.r9.u64 = r9Value;
		ctx.r10.u64 = fn40;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);

		uint32_t vtable = LOAD32(mode);
		uint32_t fn3C = LOAD32(vtable + 0x3C);
		callTarget.u64 = fn3C;
		ctx.r3.u64 = mode;
		ctx.r8.u64 = fn3C;
		ctx.r9.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r9Value = ctx.r9.u64;
		r7Value = result & 0xFF;
		if (r7Value == 0) {
			continue;
		}

		uint32_t fn4C = LOAD32(LOAD32(mode) + 0x4C);
		callTarget.u64 = fn4C;
		ctx.r3.u64 = mode;
		ctx.r7.u64 = r7Value;
		ctx.r10.u64 = fn4C;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		r7Value = ctx.r7.u64;
		r9Value = ctx.r9.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(6, sub_82218498, 0x82218498) { ctx.r3.u64 = CECEntityModeManager_UpdateAnimations(ctx, base, ctx.r3.u64); }

uint64_t CECEntityModeManager_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820A7538_B_ = int32_t(0x820A7538);
	if (!UseLiftedCode(22, 0x823EEB80)) { ctx.r3.u64 = classNameString; __imp__sub_823EEB80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823EEB80);
	GameStackFrame stackFrame(ctx, base, 96);
	CCharString_ConstructFromCStr(ctx, base, classNameString, str_TXT_820A7538_B_, -1);
	return classNameString;
}
PROMOTED_ENTRY(22, sub_823EEB80, 0x823EEB80) { ctx.r3.u64 = CECEntityModeManager_GetClassName(ctx, base, ctx.r3.u64); }

uint64_t CECEntityModeManager_CECEntityModeManager(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t owner) {
	constexpr int32_t g_83496EB8 = int32_t(0x83496EB8);
	if (!UseLiftedCode(22, 0x823F0E18)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = owner; __imp__sub_823F0E18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F0E18);
	uint32_t stack = ctx.r1.u64;
	uint32_t r13Value = ctx.r13.u64;   // its MSR bits are set around each atomic update
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);

	stack = PushStackFrame(base, stack, 112);

	entityModeManager->m_4 = (uint32_t)owner;
	entityModeManager->m_8 = 0;
	entityModeManager->vtable = 0x82003B58u;
	entityModeManager->m_C = 0;
	entityModeManager->m_10 = 0;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = owner;
	uint32_t allocation = operator_new(ctx, base, 16);
	if (allocation != 0) {
		STORE32(allocation, allocation);
	}
	if ((int32_t)(allocation + 4) != 0) {
		STORE32(allocation + 4, allocation);
	}
	entityModeManager->m_18 = allocation;
	entityModeManager->m_1C = 0;
	entityModeManager->m_20 = 0;
	entityModeManager->m_24 = 0;
	STORE32((uint32_t)entityModeManagerAddr + 40, 0);
	entityModeManager->m_2C = 0;
	entityModeManager->m_30 = 0;

	uint32_t counterAddr = (uint32_t)g_83496EB8;
	auto incrementSharedCounter = [&]() {
		bool succeeded;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			uint32_t previousMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = r13Value & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW(counterAddr);
			uint32_t newValue = (int32_t)__builtin_bswap32(ctx.reserved.u32) + 1;
			succeeded = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW(counterAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newValue));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = previousMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!succeeded);
	};

	incrementSharedCounter();
	entityModeManager->m_34 = 0;
	incrementSharedCounter();
	entityModeManager->m_38 = 0;
	entityModeManager->m_3C = 0;
	entityModeManager->m_40 = 0;
	entityModeManager->m_41 = 0;
	entityModeManager->m_42 = 1;
	entityModeManager->m_44 = 0;
	incrementSharedCounter();
	entityModeManager->m_48 = 0;
	incrementSharedCounter();

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return entityModeManagerAddr;
}
PROMOTED_ENTRY(22, sub_823F0E18, 0x823F0E18) { ctx.r3.u64 = CECEntityModeManager_CECEntityModeManager(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECEntityModeManager_Update(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(22, 0x823F1B68)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F1B68(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F1B68);
	uint32_t stack = ctx.r1.u64;
	// registers handed on to the callees (r4 also back to the caller)
	uint64_t r4Value = ctx.r4.u64;
	uint64_t r6Value = ctx.r6.u64;
	uint64_t r7Value = ctx.r7.u64;
	uint64_t r8Value = ctx.r8.u64;
	PPCCRRegister cr0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 144);

	uint64_t result = 1;
	entityModeManager->m_41 = 1;

	if (entityModeManager->m_40 != 0) {
		// Visit each 16-byte entry of the array reached through the handle at +0xC, then release the handle.
		uint64_t handleAddr = entityModeManagerAddr + 12;
		uint64_t entryOffset = 0;
		uint32_t i = 0;
		for (;;) {
			uint32_t arrayObj = LOAD32((uint32_t)handleAddr);
			uint32_t begin = LOAD32(arrayObj + 4);
			if (begin == 0) {
				break;
			}
			uint32_t end = LOAD32(arrayObj + 8);
			r8Value = (uint64_t)end - (uint64_t)begin;
			flags.ca = ((int32_t)r8Value < 0) & (((uint32_t)r8Value & 0xF) != 0);
			if (i >= (uint32_t)((int32_t)r8Value >> 4)) {
				break;
			}
			// bounds check of the indexed access (begin is read again)
			uint32_t checkedBegin = LOAD32(arrayObj + 4);
			bool inRange = false;
			if (checkedBegin != 0) {
				uint32_t span = end - checkedBegin;
				flags.ca = ((int32_t)span < 0) & ((span & 0xF) != 0);
				inRange = i < (uint32_t)((int32_t)span >> 4);
			}
			if (!inRange) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint64_t entry = entryOffset + (uint64_t)checkedBegin;
			uint64_t entryField8 = entry + 8;
			if (LOAD8((uint32_t)entry + 12) != 0) {
				ctx.r1.u64 = stack;
				ctx.r8.u64 = r8Value;
				ctx.xer.ca = flags.ca;
				CECEntityModeManager_AddModeFromElement(ctx, base, entityModeManagerAddr, entry, entryField8);
			} else {
				uint64_t entryWord4 = LOAD32((uint32_t)entry + 4);
				ctx.r1.u64 = stack;
				ctx.r8.u64 = r8Value;
				ctx.xer.ca = flags.ca;
				CECEntityModeManager_AddMode(ctx, base, entityModeManagerAddr, entryWord4, entryField8);
			}
			r8Value = ctx.r8.u64;
			flags.ca = ctx.xer.ca;
			i++;
			entryOffset += 16;
		}
		ctx.r1.u64 = stack;
		ctx.r8.u64 = r8Value;
		ctx.xer.ca = flags.ca;
		uint64_t released = SharedHandle_Release(ctx, base, handleAddr);
		STORE32((uint32_t)handleAddr, 0);
		entityModeManager->m_41 = 0;
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return released;
	}

	uint32_t linked = entityModeManager->m_4;
	uint32_t candidateEntity = 0;
	bool haveCandidate = false;
	// bit 27 of the word at +44; the same register later carries the search step and goes to CECEntityModeManager_RebuildModes in r8
	uint32_t r8Arg = (LOAD32(linked + 44) >> 27) & 1;
	if (r8Arg != 0) {
		uint32_t indexed = LOAD32(linked + 140);
		if (indexed != 0) {
			uint32_t index = LOAD8(indexed + 91);
			uint32_t table = LOAD32(linked + 72);
			candidateEntity = LOAD32(__builtin_rotateleft32(index, 3) + table + 4);
		} else {
			// lower_bound for key 91 in the sorted array of 8-byte {key, value} pairs whose begin/end pointers are at +72/+76
			uint32_t node = LOAD32(linked + 72);
			r6Value = LOAD32(linked + 76);
			STORE32(stack + 80, 0);
			uint32_t count = (uint32_t)(r6Value - node);
			STORE32(stack + 84, node);
			flags.ca = ((int32_t)count < 0) & ((count & 0x7) != 0);
			count = (uint32_t)((int32_t)count >> 3);
			cr0.compare<int32_t>((int32_t)count, 0, flags);
			if ((int32_t)count > 0) {
				do {
					flags.ca = ((int32_t)count < 0) & ((count & 0x1) != 0);
					uint32_t half = (uint32_t)((int32_t)count >> 1);
					r8Arg = half << 3;
					node += r8Arg;
					r7Value = (int32_t)LOAD32(node) < 91 ? 1 : 0;
					if (r7Value != 0) {
						node += 8;
						count = count - half - 1;
					} else {
						node -= r8Arg;
						count = half;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, node);
			}
			if (node == (uint32_t)r6Value || (int32_t)LOAD32(node) > 91) {
				candidateEntity = LOAD32((uint32_t)r6Value + 4);   // key absent: value slot at the end position
			} else {
				candidateEntity = LOAD32(node + 4);
			}
		}
		haveCandidate = true;
	}

	if (haveCandidate) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, candidateEntity);
	}
	if ((result & 0xFF) != 0) {
		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6Value;
		ctx.r7.u64 = r7Value;
		ctx.r8.u64 = r8Arg;
		ctx.cr0.lt = cr0.lt;
		ctx.cr0.gt = cr0.gt;
		ctx.cr0.eq = cr0.eq;
		ctx.cr0.so = cr0.so;
		ctx.xer.ca = flags.ca;
		CECEntityModeManager_RebuildModes(ctx, base, entityModeManagerAddr);

		uint64_t stringAddr = entityModeManagerAddr + 52;   // the string at +0x34
		uint64_t literalAddr = g_82000C98;
		result = CCharString_NotEqualsEmptyOrLiteral(ctx, base, stringAddr, literalAddr);
		if ((result & 0xFF) != 0) {
			uint64_t updated = CECEntityModeManager_CreateModeFromName(ctx, base, entityModeManagerAddr, stringAddr);
			entityModeManager->m_41 = 0;
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return updated;
		}

		r4Value = entityModeManager->m_3C;
		if ((int32_t)r4Value != 0) {
			result = CECEntityModeManager_HasMode(ctx, base, entityModeManagerAddr, r4Value);
			r4Value = ctx.r4.u64;
			if ((result & 0xFF) == 0) {
				uint32_t mode = entityModeManager->m_3C;
				result = CECEntityModeManager_AddModeById(ctx, base, entityModeManagerAddr, mode);
				r4Value = ctx.r4.u64;
			}
		}
	}

	entityModeManager->m_41 = 0;
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;   // callers read r4 after the call
	return result;
}
PROMOTED_ENTRY(22, sub_823F1B68, 0x823F1B68) { ctx.r3.u64 = CECEntityModeManager_Update(ctx, base, ctx.r3.u64); }

uint64_t CECEntityModeManager_AddModeById(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t modeId) {
	constexpr int32_t g_83497870 = int32_t(0x83497870);
	if (!UseLiftedCode(22, 0x823F1EB0)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = modeId; __imp__sub_823F1EB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F1EB0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t modeSlot = stack + 156;   // the lookup takes the modeId by address
	STORE32(modeSlot, (uint32_t)modeId);
	// global container searched by n_sub_823F4AA0; a found node holds a create function at +16
	uint64_t registryAddr = g_83497870;
	uint32_t iter = stack + 80;   // {container, node} from the lookup, later reused as a shared handle

	// result, and r4/r5 left for callers, when no node is found
	uint64_t result = iter;
	uint64_t r4Value = registryAddr;
	uint64_t r5Value = modeSlot;

	ctx.r1.u64 = stack;
	n_sub_823F4AA0(ctx, base, iter, modeSlot);

	// iterator check: it must belong to the container
	uint32_t iterContainer = LOAD32(iter);
	if (iterContainer == 0 || iterContainer != (uint32_t)registryAddr) {
		ppc_trap(ctx, base, 22);
	}
	uint32_t containerEnd = LOAD32((uint32_t)registryAddr + 4);
	uint32_t foundNode = LOAD32(iter + 4);
	if (foundNode != containerEnd) {
		ctx.r5.u64 = r5Value;   // state the callee may pass on
		result = CECEntityModeManager_HasMode(ctx, base, entityModeManagerAddr, modeId);
		r4Value = ctx.r4.u64;
		r5Value = ctx.r5.u64;
		if ((result & 0xFF) == 0) {
			uint32_t createArg = entityModeManager->m_4;
			// iterator checks before dereferencing
			if (iterContainer == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (foundNode == LOAD32(iterContainer + 4)) {
				ppc_trap(ctx, base, 22);
			}
			callTarget.u64 = LOAD32(foundNode + 16);
			ctx.r3.u64 = createArg;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			uint32_t created = ctx.r3.u32;
			STORE32(iter, created);
			if (created != 0) {
				SharedPtr_CreateControlBlock_8238A7E0(ctx, base, iter);
			} else {
				STORE32(iter + 4, 0u);
			}
			CECEntityModeManager_AddModeHandle(ctx, base, entityModeManagerAddr, iter);
			result = SharedHandle_Release(ctx, base, iter);
			r4Value = ctx.r4.u64;
			r5Value = ctx.r5.u64;
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r5.u64 = r5Value;
	return result;
}
PROMOTED_ENTRY(22, sub_823F1EB0, 0x823F1EB0) { ctx.r3.u64 = CECEntityModeManager_AddModeById(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CECEntityModeManager_CreateModeFromName(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t modeNameAddr) {
	if (!UseLiftedCode(22, 0x823F1F88)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = modeNameAddr; __imp__sub_823F1F88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F1F88);
	uint32_t stack = ctx.r1.u64;
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t handleAddr = stack + 80;   // shared handle on the stack: object, then control block

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = modeNameAddr;
	uint64_t allocation = operator_new(ctx, base, 24);

	uint32_t object = 0;
	if ((uint32_t)allocation != 0) {
		object = n_sub_82805DC0(ctx, base, allocation, entityModeManager->m_4, modeNameAddr);
	}
	STORE32(handleAddr, object);
	if (object != 0) {
		SharedPtr_CreateControlBlock_8238A7E0(ctx, base, handleAddr);
	} else {
		STORE32(handleAddr + 4, 0);
	}

	CECEntityModeManager_AddModeHandleIfAbsent(ctx, base, entityModeManagerAddr, handleAddr);
	uint64_t releaseResult = SharedHandle_Release(ctx, base, handleAddr);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return releaseResult;
}
PROMOTED_ENTRY(22, sub_823F1F88, 0x823F1F88) { ctx.r3.u64 = CECEntityModeManager_CreateModeFromName(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Builds a 24-byte object with n_sub_82805DC0 (a null pointer when the allocation fails), wraps it in a
// shared handle on the stack, passes elementData to its virtual slot +16, hands the handle to
// CECEntityModeManager_AddModeHandleIfAbsent and releases it. Returns what SharedHandle_Release returns.
uint64_t CECEntityModeManager_AddModeFromElement(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t element, uint64_t elementData) {
	if (!UseLiftedCode(22, 0x823F2018)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = element; ctx.r5.u64 = elementData; __imp__sub_823F2018(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F2018);
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	PPCRegister callTarget{};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	// Shared handle on the stack: object pointer at +0, control block at +4.
	uint32_t handle = stack + 80;

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = element;
	ctx.r5.u64 = elementData;
	uint64_t memory = operator_new(ctx, base, 24);

	uint64_t object = 0;
	if ((uint32_t)memory != 0) {
		object = n_sub_82805DC0(ctx, base, memory, entityModeManager->m_4, element);
	}
	STORE32(handle, (uint32_t)object);

	if ((uint32_t)object != 0) {
		SharedPtr_CreateControlBlock_8238A7E0(ctx, base, handle);
		object = LOAD32(handle);
	} else {
		STORE32(handle + 4, 0u);
	}

	uint32_t slot16Fn = LOAD32(LOAD32((uint32_t)object) + 16);
	callTarget.u64 = slot16Fn;
	ctx.r3.u64 = object;
	ctx.r4.u64 = elementData;
	ctx.r10.u64 = slot16Fn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	CECEntityModeManager_AddModeHandleIfAbsent(ctx, base, entityModeManagerAddr, handle);
	uint64_t result = SharedHandle_Release(ctx, base, handle);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823F2018, 0x823F2018) { ctx.r3.u64 = CECEntityModeManager_AddModeFromElement(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// Looks modeId up in the map at 0x83497870 (n_sub_823F4AA0 writes a {map, node} iterator to stack + 80).
// When the id is in the map and the manager does not have that mode yet, the function pointer stored
// in the node (+16) creates the mode object from m_4; the object is wrapped in a shared handle (reusing
// stack + 80), given modeData through its virtual slot +16, handed to CECEntityModeManager_AddModeHandle and released.
uint64_t CECEntityModeManager_AddMode(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t modeId, uint64_t modeData) {
	constexpr int32_t g_83497870 = int32_t(0x83497870);
	if (!UseLiftedCode(22, 0x823F20A8)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = modeId; ctx.r5.u64 = modeData; __imp__sub_823F20A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F20A8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);

	stack = PushStackFrame(base, stack, 144);
	// The id is stored in the caller's frame so that its address can serve as the lookup key.
	STORE32(stack + 172, (uint32_t)modeId);
	const uint64_t modeIdAddr = (uint64_t)stack + 172;
	const uint64_t iteratorAddr = (uint64_t)stack + 80;

	// callers read r4 and r5 after the call
	uint64_t r4Out = g_83497870;
	uint64_t r5Out = modeIdAddr;
	uint64_t result = iteratorAddr;

	ctx.r1.u64 = stack;
	n_sub_823F4AA0(ctx, base, iteratorAddr, modeIdAddr);

	uint32_t iteratorMap = LOAD32(iteratorAddr);
	if (iteratorMap != (uint32_t)g_83497870) {
		ppc_trap(ctx, base, 22);
	}

	uint32_t mapEnd = LOAD32((uint32_t)g_83497870 + 4);
	uint32_t node = LOAD32(iteratorAddr + 4);
	if (node != mapEnd) {
		ctx.r5.u64 = modeIdAddr;	// state the callee may pass on
		result = CECEntityModeManager_HasMode(ctx, base, entityModeManagerAddr, modeId);
		r4Out = ctx.r4.u64;
		r5Out = ctx.r5.u64;
		if (((uint32_t)result & 0xFF) == 0) {
			uint32_t owner = entityModeManager->m_4;
			if (iteratorMap == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (node == LOAD32(iteratorMap + 4)) {
				ppc_trap(ctx, base, 22);
			}
			callTarget.u64 = (uint64_t)LOAD32(node + 16);
			ctx.r3.u64 = owner;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			uint64_t mode = ctx.r3.u64;
			STORE32(iteratorAddr, (uint32_t)mode);
			if ((uint32_t)mode != 0) {
				SharedPtr_CreateControlBlock_8238A7E0(ctx, base, iteratorAddr);
				mode = LOAD32(iteratorAddr);
			} else {
				STORE32(iteratorAddr + 4, 0u);
			}

			uint32_t slot16Fn = LOAD32(LOAD32((uint32_t)mode) + 16);
			callTarget.u64 = (uint64_t)slot16Fn;
			ctx.r3.u64 = mode;
			ctx.r4.u64 = modeData;
			ctx.r10.u64 = slot16Fn;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);

			CECEntityModeManager_AddModeHandle(ctx, base, entityModeManagerAddr, iteratorAddr);
			result = SharedHandle_Release(ctx, base, iteratorAddr);
			r4Out = ctx.r4.u64;
			r5Out = ctx.r5.u64;
		}
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.r5.u64 = r5Out;
	return result;
}
PROMOTED_ENTRY(22, sub_823F20A8, 0x823F20A8) { ctx.r3.u64 = CECEntityModeManager_AddMode(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// If the shared handle at modeHandleAddr holds an object, asks the object for its mode id (virtual slot
// +4) and, when the manager does not have that mode yet, hands the handle to CECEntityModeManager_AddModeHandle.
uint32_t CECEntityModeManager_AddModeHandleIfAbsent(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t modeHandleAddr) {
	if (!UseLiftedCode(22, 0x823F2338)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = modeHandleAddr; __imp__sub_823F2338(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823F2338);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};

	// callers read r4 and r9 after the call
	uint64_t r4Out = modeHandleAddr;
	uint64_t r9Out = ctx.r9.u64;

	stack = PushStackFrame(base, stack, 112);
	uint32_t modeObject = LOAD32((uint32_t)modeHandleAddr);
	uint32_t result = modeObject;
	if (modeObject != 0) {
		uint32_t getModeIdFn = LOAD32(LOAD32(modeObject) + 4);
		callTarget.u64 = (uint64_t)getModeIdFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = modeObject;
		ctx.r4.u64 = modeHandleAddr;
		ctx.r10.u64 = getModeIdFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t modeId = ctx.r3.u64;

		result = CECEntityModeManager_HasMode(ctx, base, entityModeManagerAddr, modeId);
		r4Out = ctx.r4.u64;
		r9Out = result & 0xFF;
		if (r9Out == 0) {
			ctx.r9.u64 = 0;	// state the callee may pass on
			result = CECEntityModeManager_AddModeHandle(ctx, base, entityModeManagerAddr, modeHandleAddr);
			r4Out = ctx.r4.u64;
			r9Out = ctx.r9.u64;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	ctx.r9.u64 = r9Out;
	return result;
}
PROMOTED_ENTRY(22, sub_823F2338, 0x823F2338) { ctx.r3.u64 = CECEntityModeManager_AddModeHandleIfAbsent(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// For each key 0..9, looks the key up in the mode list at +20 (AnimationComponent_FindAnimation writes a
// {list, node} iterator to stack + 80); when the key is present, the mode object stored in the node (+8)
// is disabled and enabled again. Returns the result of the last call made: AnimationControl_Enable when
// key 9 is present, AnimationComponent_FindAnimation otherwise.
uint64_t CECEntityModeManager_ReenableAllModes(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	if (!UseLiftedCode(22, 0x823F23B0)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F23B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F23B0);
	uint32_t stack = ctx.r1.u64;
	// r9 as the original leaves it: handed to the callees and read by callers after the call
	uint64_t r9Carry = ctx.r9.u64;
	uint64_t result = 0;
	stack = PushStackFrame(base, stack, 128);

	const uint32_t list = (uint32_t)entityModeManagerAddr + 20;
	uint64_t key = 0;
	do {
		ctx.r1.u64 = stack;
		ctx.r9.u64 = r9Carry;
		result = AnimationComponent_FindAnimation(ctx, base, (uint64_t)stack + 80, entityModeManagerAddr, key);

		uint32_t iteratorList = LOAD32(stack + 80);
		uint32_t listEnd = LOAD32(list + 4);
		if (iteratorList == 0 || iteratorList != list) {
			ppc_trap(ctx, base, 22);
		}

		uint32_t node = LOAD32(stack + 84);
		r9Carry = node;
		if (node != listEnd) {
			if (iteratorList == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (node == LOAD32(iteratorList + 4)) {
				ppc_trap(ctx, base, 22);
			}
			uint32_t modeObject = LOAD32(node + 8);
			ctx.r9.u64 = r9Carry;	// state the callee may pass on
			AnimationControl_Disable(ctx, base, modeObject);
			result = AnimationControl_Enable(ctx, base, modeObject);
			r9Carry = ctx.r9.u64;
		}
		++key;
	} while ((int32_t)key != 10);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r9.u64 = r9Carry;
	return result;
}
PROMOTED_ENTRY(22, sub_823F23B0, 0x823F23B0) { ctx.r3.u64 = CECEntityModeManager_ReenableAllModes(ctx, base, ctx.r3.u64); }

// Adds the mode held by the shared handle at modeHandleAddr to the manager. Skipped only when the m_4
// table has a value under key 91, byte +65 of the manager is clear, CECNetwork_ShouldReplicateEntity
// refuses that value and byte +107 of it is clear (the function then returns the refusal).
// The mode's key (virtual slot +8) is looked up in the mode list at +20; an existing entry is disabled.
// The handle is appended to the list, CECEntityModeManager_SelectFirstAvailableMode and CECEntityModeManager_UpdateReplicatedModeName run, and then, depending on
// virtual slot +40, either the modes are refreshed (CECEntityModeManager_ReenableAllModes) and the value under key 58, when
// the table has one, is released, or the new mode is enabled. Returns what virtual slot +56 returns.
//
// The m_4 table: a presence bit per key (+40 for key 58, +44 for key 91); when the byte array at +140
// exists it gives each key's record index, otherwise the 8-byte {key, value} records from +72 to +76,
// sorted by key, are searched (lower bound); a key not found there reads the value word of the record
// the end pointer (+76) points at.
uint32_t CECEntityModeManager_AddModeHandle(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr, uint64_t modeHandleAddr) {
	if (!UseLiftedCode(22, 0x823F2448)) { ctx.r3.u64 = entityModeManagerAddr; ctx.r4.u64 = modeHandleAddr; __imp__sub_823F2448(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823F2448);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	PPCRegister callTarget{};
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 128);

	// r6-r9 and the carry as the original leaves them, handed to the callees; r4 is read by callers.
	uint64_t r4Out = modeHandleAddr;
	uint64_t r6Carry = ctx.r6.u64;
	uint64_t r7Carry = ctx.r7.u64;
	uint64_t r8Carry = 0;
	uint64_t r9Carry = 0;
	uint32_t result = 0;

	// Value under key 91.
	uint32_t entity = 0;
	bool hasEntity = false;
	uint32_t table = entityModeManager->m_4;
	r9Carry = (LOAD32(table + 44) >> 27) & 1;
	if ((uint32_t)r9Carry != 0) {
		uint32_t indexCache = LOAD32(table + 140);
		if (indexCache != 0) {
			uint32_t recordOffset = __builtin_rotateleft32(LOAD8(indexCache + 91), 3);
			r9Carry = (uint64_t)recordOffset + LOAD32(table + 72);
			entity = LOAD32((uint32_t)r9Carry + 4);
		} else {
			uint32_t record = LOAD32(table + 72);
			r6Carry = LOAD32(table + 76);
			STORE32(stack + 80, 0);
			uint32_t count = (uint32_t)r6Carry - record;
			STORE32(stack + 84, record);
			flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
			count = (int32_t)count >> 3;
			if ((int32_t)count > 0) {
				do {
					flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
					uint32_t half = (int32_t)count >> 1;
					uint32_t halfBytes = half << 3;
					r9Carry = half;
					record = halfBytes + record;
					r7Carry = (int32_t)LOAD32(record) < 91 ? 1 : 0;
					if (r7Carry != 0) {
						count = count - half - 1;
						record = record + 8;
					} else {
						record = record - halfBytes;
						count = half;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, record);
			}
			if (record != (uint32_t)r6Carry && (int32_t)LOAD32(record) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entity = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entity = LOAD32((uint32_t)r6Carry + 4);
			}
		}
		hasEntity = true;
	}

	bool addMode = true;
	if (hasEntity && LOAD8((uint32_t)entityModeManagerAddr + 65) == 0) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, entity);
		r9Carry = ctx.r9.u64;
		if ((result & 0xFF) == 0 && LOAD8(entity + 107) == 0) {
			addMode = false;
		}
	}

	if (addMode) {
		uint32_t modeObject = LOAD32((uint32_t)modeHandleAddr);
		uint32_t getKeyFn = LOAD32(LOAD32(modeObject) + 8);
		callTarget.u64 = (uint64_t)getKeyFn;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = modeObject;
		ctx.r4.u64 = modeHandleAddr;
		ctx.r6.u64 = r6Carry;
		ctx.r7.u64 = r7Carry;
		ctx.r8.u64 = entity;
		ctx.r9.u64 = r9Carry;
		ctx.r10.u64 = getKeyFn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t modeKey = ctx.r3.u64;

		// {list, node} iterator for the key at stack + 80; a node other than the end node is an existing entry.
		AnimationComponent_FindAnimation(ctx, base, (uint64_t)stack + 80, entityModeManagerAddr, modeKey);

		uint32_t iteratorList = LOAD32(stack + 80);
		uint32_t listEnd = entityModeManager->m_18;
		uint32_t list = (uint32_t)entityModeManagerAddr + 20;
		if (iteratorList == 0 || iteratorList != list) {
			ppc_trap(ctx, base, 22);
		}
		uint32_t node = LOAD32(stack + 84);
		if (node != listEnd) {
			if (iteratorList == 0) {
				ppc_trap(ctx, base, 22);
			}
			if (node == LOAD32(iteratorList + 4)) {
				ppc_trap(ctx, base, 22);
			}
			AnimationControl_Disable(ctx, base, LOAD32(node + 8));
		}

		// Insert a copy of the handle before the end iterator {list, end node}.
		uint32_t endNode = LOAD32(list + 4);
		STORE32(stack + 80, list);
		STORE32(stack + 84, endNode);
		List_InsertNodeCopyRefCountedPair(ctx, base, list, LOAD64(stack + 80), modeHandleAddr);
		CECEntityModeManager_SelectFirstAvailableMode(ctx, base, entityModeManagerAddr);
		CECEntityModeManager_UpdateReplicatedModeName(ctx, base, entityModeManagerAddr);

		modeObject = LOAD32((uint32_t)modeHandleAddr);
		uint32_t vtable = LOAD32(modeObject);
		uint32_t slot40Fn = LOAD32(vtable + 40);
		callTarget.u64 = (uint64_t)slot40Fn;
		ctx.r3.u64 = modeObject;
		ctx.r9.u64 = slot40Fn;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint32_t slot40Flag = ctx.r3.u32 & 0xFF;

		if (slot40Flag != 0) {
			ctx.r8.u64 = slot40Flag;	// state the callee may pass on
			CECEntityModeManager_ReenableAllModes(ctx, base, entityModeManagerAddr);
			r6Carry = ctx.r6.u64;
			r7Carry = ctx.r7.u64;
			r8Carry = ctx.r8.u64;
			flags.ca = ctx.xer.ca;

			// Value under key 58.
			uint32_t value58 = 0;
			bool hasValue58 = false;
			uint32_t table58 = entityModeManager->m_4;
			r9Carry = (LOAD32(table58 + 40) >> 26) & 1;
			if ((uint32_t)r9Carry != 0) {
				uint32_t indexCache = LOAD32(table58 + 140);
				if (indexCache != 0) {
					uint32_t recordOffset = __builtin_rotateleft32(LOAD8(indexCache + 58), 3);
					r9Carry = (uint64_t)recordOffset + LOAD32(table58 + 72);
					value58 = LOAD32((uint32_t)r9Carry + 4);
				} else {
					uint32_t record = LOAD32(table58 + 72);
					r6Carry = LOAD32(table58 + 76);
					STORE32(stack + 80, 0);
					uint32_t count = (uint32_t)r6Carry - record;
					STORE32(stack + 84, record);
					flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
					count = (int32_t)count >> 3;
					if ((int32_t)count > 0) {
						do {
							flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
							uint32_t half = (int32_t)count >> 1;
							r9Carry = half;
							r8Carry = half << 3;
							record = (uint32_t)r8Carry + record;
							r7Carry = (int32_t)LOAD32(record) < 58 ? 1 : 0;
							if (r7Carry != 0) {
								count = count - half - 1;
								record = record + 8;
							} else {
								record = record - (uint32_t)r8Carry;
								count = half;
							}
						} while ((int32_t)count > 0);
						STORE32(stack + 84, record);
					}
					if (record != (uint32_t)r6Carry && (int32_t)LOAD32(record) <= 58) {
						STORE64(stack + 80, LOAD64(stack + 80));
						value58 = LOAD32(LOAD32(stack + 84) + 4);
					} else {
						value58 = LOAD32((uint32_t)r6Carry + 4);
					}
				}
				hasValue58 = true;
			}
			if (hasValue58) {
				ctx.r6.u64 = r6Carry;
				ctx.r7.u64 = r7Carry;
				ctx.r8.u64 = r8Carry;
				ctx.xer.ca = flags.ca;
				AnimationComponent_ReleaseAnimationControl(ctx, base, value58);
				r6Carry = ctx.r6.u64;
				r7Carry = ctx.r7.u64;
				r8Carry = ctx.r8.u64;
				r9Carry = ctx.r9.u64;
				flags.ca = ctx.xer.ca;
			}
		} else {
			ctx.r8.u64 = 0;	// state the callee may pass on
			AnimationControl_Enable(ctx, base, LOAD32((uint32_t)modeHandleAddr));
			r6Carry = ctx.r6.u64;
			r7Carry = ctx.r7.u64;
			r8Carry = ctx.r8.u64;
			r9Carry = ctx.r9.u64;
			flags.ca = ctx.xer.ca;
		}

		modeObject = LOAD32((uint32_t)modeHandleAddr);
		uint32_t slot56Fn = LOAD32(LOAD32(modeObject) + 56);
		callTarget.u64 = (uint64_t)slot56Fn;
		ctx.r3.u64 = modeObject;
		ctx.r6.u64 = r6Carry;
		ctx.r7.u64 = r7Carry;
		ctx.r8.u64 = r8Carry;
		ctx.r9.u64 = r9Carry;
		ctx.r10.u64 = slot56Fn;
		ctx.xer.ca = flags.ca;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u32;
		r4Out = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Out;
	return result;
}
PROMOTED_ENTRY(22, sub_823F2448, 0x823F2448) { ctx.r3.u64 = CECEntityModeManager_AddModeHandle(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Until the mode list at +20 is empty (count m_1C), passes the id of its first mode (virtual slot +4) to
// AnimationComponent_RemoveAnimation; then releases the shared handle at +32 and clears its pointer word
// m_20, returning what SharedHandle_Release returns. Skipped when the m_4 table has a value under key 91
// (lookup described at CECEntityModeManager_AddModeHandle), byte +65 of the manager is clear, CECNetwork_ShouldReplicateEntity
// refuses that value and byte +107 of it is clear; the function then returns the refusal.
uint64_t CECEntityModeManager_RemoveAllModesImpl(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	if (!UseLiftedCode(22, 0x823F30D8)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F30D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F30D8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	PPCRegister callTarget{};

	// r6-r9, cr0 and the carry as the original leaves them, handed to the callees; r6-r8 and cr0 are
	// also read by callers.
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	uint64_t r6Carry = ctx.r6.u64;
	uint64_t r7Carry = ctx.r7.u64;
	uint64_t r9Carry = 0;
	uint64_t result = 0;

	// Value under key 91.
	uint32_t entity = 0;
	bool hasEntity = false;
	uint32_t table = entityModeManager->m_4;
	r9Carry = (LOAD32(table + 44) >> 27) & 1;
	if ((uint32_t)r9Carry != 0) {
		uint32_t indexCache = LOAD32(table + 140);
		if (indexCache != 0) {
			uint32_t recordOffset = __builtin_rotateleft32(LOAD8(indexCache + 91), 3);
			r9Carry = (uint64_t)recordOffset + LOAD32(table + 72);
			entity = LOAD32((uint32_t)r9Carry + 4);
		} else {
			uint32_t record = LOAD32(table + 72);
			r6Carry = LOAD32(table + 76);
			STORE32(stack + 80, 0);
			uint32_t count = (uint32_t)r6Carry - record;
			STORE32(stack + 84, record);
			flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
			count = (int32_t)count >> 3;
			compare0.compare<int32_t>((int32_t)count, 0, flags);
			if ((int32_t)count > 0) {
				do {
					flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
					uint32_t half = (int32_t)count >> 1;
					uint32_t halfBytes = half << 3;
					r9Carry = half;
					record = halfBytes + record;
					r7Carry = (int32_t)LOAD32(record) < 91 ? 1 : 0;
					if (r7Carry != 0) {
						count = count - half - 1;
						record = record + 8;
					} else {
						record = record - halfBytes;
						count = half;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, record);
			}
			if (record != (uint32_t)r6Carry && (int32_t)LOAD32(record) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entity = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entity = LOAD32((uint32_t)r6Carry + 4);
			}
		}
		hasEntity = true;
	}
	uint64_t r8Carry = entity;

	bool tearDown = true;
	if (hasEntity && LOAD8((uint32_t)entityModeManagerAddr + 65) == 0) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, entity);
		r9Carry = ctx.r9.u64;
		tearDown = ((uint32_t)result & 0xFF) != 0 || LOAD8(entity + 107) != 0;
	}

	if (tearDown) {
		if (entityModeManager->m_1C != 0) {
			uint32_t list = (uint32_t)entityModeManagerAddr + 20;
			do {
				uint32_t endNode = LOAD32(list + 4);
				uint32_t node = LOAD32(endNode);
				if (node == endNode) {
					ctx.r1.u64 = stack;
					ppc_trap(ctx, base, 22);
				}
				uint32_t modeObject = LOAD32(node + 8);
				uint32_t getModeIdFn = LOAD32(LOAD32(modeObject) + 4);
				callTarget.u64 = (uint64_t)getModeIdFn;
				ctx.r1.u64 = stack;
				ctx.r3.u64 = modeObject;
				ctx.r6.u64 = r6Carry;
				ctx.r7.u64 = r7Carry;
				ctx.r8.u64 = r8Carry;
				ctx.r9.u64 = r9Carry;
				ctx.r10.u64 = getModeIdFn;
				ctx.cr0.lt = compare0.lt;
				ctx.cr0.gt = compare0.gt;
				ctx.cr0.eq = compare0.eq;
				ctx.cr0.so = compare0.so;
				ctx.xer.ca = flags.ca;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				uint64_t modeId = ctx.r3.u64;

				AnimationComponent_RemoveAnimation(ctx, base, entityModeManagerAddr, modeId);
				r6Carry = ctx.r6.u64;
				r7Carry = ctx.r7.u64;
				r8Carry = ctx.r8.u64;
				compare0.lt = ctx.cr0.lt;
				compare0.gt = ctx.cr0.gt;
				compare0.eq = ctx.cr0.eq;
				compare0.so = ctx.cr0.so;
				flags.ca = ctx.xer.ca;
				r9Carry = entityModeManager->m_1C;
			} while ((uint32_t)r9Carry != 0);
		}

		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6Carry;
		ctx.r7.u64 = r7Carry;
		ctx.r8.u64 = r8Carry;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		result = SharedHandle_Release(ctx, base, entityModeManagerAddr + 32);
		r6Carry = ctx.r6.u64;
		r7Carry = ctx.r7.u64;
		r8Carry = ctx.r8.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		entityModeManager->m_20 = 0;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = r6Carry;
	ctx.r7.u64 = r7Carry;
	ctx.r8.u64 = r8Carry;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	return result;
}
PROMOTED_ENTRY(22, sub_823F30D8, 0x823F30D8) { ctx.r3.u64 = CECEntityModeManager_RemoveAllModesImpl(ctx, base, ctx.r3.u64); }

// Rebuilds the manager's modes: calls CECEntityModeManager_RemoveAllModesImpl (mode teardown), then builds a mode from the string
// at +48 (CECEntityModeManager_CreateModeFromName) when CCharString_NotEqualsEmptyOrLiteral reports it differs from the literal at
// 0x82000C98, or else the mode with id m_38 (CECEntityModeManager_AddModeById) when that id is not 0, and returns the last
// result. Skipped when the m_4 table has a value under key 91 (lookup described at CECEntityModeManager_AddModeHandle), byte
// +65 of the manager is clear and CECNetwork_ShouldReplicateEntity refuses that value; the function then
// returns the refusal.
uint64_t CECEntityModeManager_RebuildModes(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	if (!UseLiftedCode(22, 0x823F3298)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F3298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F3298);
	uint32_t stack = ctx.r1.u64;
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);

	// r6-r8, cr0 and the carry as the original leaves them, handed to the callees; r6-r8 and cr0 are
	// also read by callers.
	uint64_t r6Carry = ctx.r6.u64;
	uint64_t r7Carry = ctx.r7.u64;
	uint64_t r8Carry = ctx.r8.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = 0;

	// Value under key 91.
	uint32_t entity = 0;
	bool hasEntity = false;
	uint32_t table = entityModeManager->m_4;
	if (((LOAD32(table + 44) >> 27) & 1) != 0) {
		uint32_t indexCache = LOAD32(table + 140);
		if (indexCache != 0) {
			uint32_t recordOffset = __builtin_rotateleft32(LOAD8(indexCache + 91), 3);
			entity = LOAD32(recordOffset + LOAD32(table + 72) + 4);
		} else {
			uint32_t record = LOAD32(table + 72);
			r6Carry = LOAD32(table + 76);
			STORE32(stack + 80, 0);
			uint32_t count = (uint32_t)r6Carry - record;
			STORE32(stack + 84, record);
			flags.ca = (int32_t)count < 0 & (count & 0x7) != 0;
			count = (int32_t)count >> 3;
			compare0.compare<int32_t>((int32_t)count, 0, flags);
			if ((int32_t)count > 0) {
				do {
					flags.ca = (int32_t)count < 0 & (count & 0x1) != 0;
					uint32_t half = (int32_t)count >> 1;
					r8Carry = half << 3;
					record = (uint32_t)r8Carry + record;
					r7Carry = (int32_t)LOAD32(record) < 91 ? 1 : 0;
					if (r7Carry != 0) {
						count = count - half - 1;
						record = record + 8;
					} else {
						record = record - (uint32_t)r8Carry;
						count = half;
					}
				} while ((int32_t)count > 0);
				STORE32(stack + 84, record);
			}
			if (record != (uint32_t)r6Carry && (int32_t)LOAD32(record) <= 91) {
				STORE64(stack + 80, LOAD64(stack + 80));
				entity = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				entity = LOAD32((uint32_t)r6Carry + 4);
			}
		}
		hasEntity = true;
	}

	bool rebuild = true;
	if (hasEntity && LOAD8((uint32_t)entityModeManagerAddr + 65) == 0) {
		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, entity);
		rebuild = ((uint32_t)result & 0xFF) != 0;
	}

	if (rebuild) {
		ctx.r1.u64 = stack;
		ctx.r6.u64 = r6Carry;
		ctx.r7.u64 = r7Carry;
		ctx.cr0.lt = compare0.lt;
		ctx.cr0.gt = compare0.gt;
		ctx.cr0.eq = compare0.eq;
		ctx.cr0.so = compare0.so;
		ctx.xer.ca = flags.ca;
		CECEntityModeManager_RemoveAllModesImpl(ctx, base, entityModeManagerAddr);
		r6Carry = ctx.r6.u64;
		r7Carry = ctx.r7.u64;
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;

		uint64_t modeNameAddr = entityModeManagerAddr + 48;
		result = CCharString_NotEqualsEmptyOrLiteral(ctx, base, modeNameAddr, g_82000C98);
		r8Carry = ctx.r8.u64;
		if (((uint32_t)result & 0xFF) != 0) {
			result = CECEntityModeManager_CreateModeFromName(ctx, base, entityModeManagerAddr, modeNameAddr);
			r6Carry = ctx.r6.u64;
			r7Carry = ctx.r7.u64;
			r8Carry = ctx.r8.u64;
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
		} else {
			uint32_t modeId = entityModeManager->m_38;
			if (modeId != 0) {
				result = CECEntityModeManager_AddModeById(ctx, base, entityModeManagerAddr, modeId);
				r6Carry = ctx.r6.u64;
				r7Carry = ctx.r7.u64;
				r8Carry = ctx.r8.u64;
				compare0.lt = ctx.cr0.lt;
				compare0.gt = ctx.cr0.gt;
				compare0.eq = ctx.cr0.eq;
				compare0.so = ctx.cr0.so;
			}
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = r6Carry;
	ctx.r7.u64 = r7Carry;
	ctx.r8.u64 = r8Carry;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	return result;
}
PROMOTED_ENTRY(22, sub_823F3298, 0x823F3298) { ctx.r3.u64 = CECEntityModeManager_RebuildModes(ctx, base, ctx.r3.u64); }

uint64_t CECEntityModeManager_RemoveAllModes(CpuState& ctx, uint8_t* base, uint64_t entityModeManager) {
	if (!UseLiftedCode(22, 0x823F3448)) { ctx.r3.u64 = entityModeManager; __imp__sub_823F3448(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F3448);
	return CECEntityModeManager_RemoveAllModesImpl(ctx, base, entityModeManager);
}
PROMOTED_ENTRY(22, sub_823F3448, 0x823F3448) { ctx.r3.u64 = CECEntityModeManager_RemoveAllModes(ctx, base, ctx.r3.u64); }

// Looks up the ids below in order and assigns the value of the first entry found to the shared
// pointer at +0x20. Returns what SharedPtr_Assign returns, or the last lookup's result if none is found.
uint32_t CECEntityModeManager_SelectFirstAvailableMode(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	if (!UseLiftedCode(22, 0x823F37C0)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F37C0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x823F37C0);
	uint32_t stack = ctx.r1.u64;
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	// Each lookup writes a {container, entry} pair to stack + 88 and returns its address. The container
	// must be the manager's address + 0x14; an entry equal to m_18 (the container's word at +4) means
	// the id is absent.
	const uint32_t animationIds[6] = { 51, 5, 4, 8, 1, 7 };
	uint32_t expectedContainer = (uint32_t)entityModeManagerAddr + 20;
	uint32_t lookupResult = 0;
	uint32_t container = 0;
	uint32_t entry = 0;
	uint32_t absentEntry = 0;
	bool found = false;

	for (int i = 0; i < 6; ++i) {
		if (i == 0) {
			lookupResult = AnimationComponent_FindAnimation_823F1DE0(ctx, base, stack + 88, entityModeManagerAddr, animationIds[i]);
		} else {
			ctx.r9.u64 = absentEntry;  // state the callee may pass on
			lookupResult = AnimationComponent_FindAnimation(ctx, base, stack + 88, entityModeManagerAddr, animationIds[i]);
		}
		absentEntry = entityModeManager->m_18;

		STORE64(stack + 80, LOAD64(lookupResult));
		container = LOAD32(stack + 80);
		if (container == 0 || container != expectedContainer) {
			ppc_trap(ctx, base, 22);
		}
		entry = LOAD32(stack + 84);
		if (entry != absentEntry) {
			found = true;
			break;
		}
	}

	uint32_t result = lookupResult;
	if (found) {
		if (container == 0) {
			ppc_trap(ctx, base, 22);
		}
		if (entry == LOAD32(container + 4)) {
			ppc_trap(ctx, base, 22);
		}
		result = SharedPtr_Assign(ctx, base, entityModeManagerAddr + 32, (uint64_t)entry + 8);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(22, sub_823F37C0, 0x823F37C0) { ctx.r3.u64 = CECEntityModeManager_SelectFirstAvailableMode(ctx, base, ctx.r3.u64); }

// If bit 27 of the entity's word at +44 is set, looks up key 91 in the entity's 8-byte {key, value}
// entries and passes the value to CECNetwork_ShouldReplicateEntity. If its result's low byte is nonzero and
// m_20 is not null, the string at m_20 + 8 is compared with the string at +0x44; when they differ, a record built
// from the string is passed to sub_823F6BD8 and the string at +0x44 is replaced.
uint64_t CECEntityModeManager_UpdateReplicatedModeName(CpuState& ctx, uint8_t* base, uint64_t entityModeManagerAddr) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t g_820A2BB8 = int32_t(0x820A2BB8);
	constexpr int32_t g_820A4C1C = int32_t(0x820A4C1C);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(22, 0x823F3A10)) { ctx.r3.u64 = entityModeManagerAddr; __imp__sub_823F3A10(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x823F3A10);
	uint32_t stack = ctx.r1.u64;
	CECEntityModeManager* entityModeManager = GameObject<CECEntityModeManager>(base, entityModeManagerAddr);

	// cr0, the carry and r6-r8 as the original leaves them for its callers; they start as the incoming values
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	uint64_t outR6 = ctx.r6.u64;
	uint64_t outR7 = ctx.r7.u64;
	uint64_t outR8 = ctx.r8.u64;
	auto readCompareStateBack = [&] {
		compare0.lt = ctx.cr0.lt;
		compare0.gt = ctx.cr0.gt;
		compare0.eq = ctx.cr0.eq;
		compare0.so = ctx.cr0.so;
		flags.ca = ctx.xer.ca;
	};

	stack = PushStackFrame(base, stack, 224);

	uint64_t result = 0;
	uint32_t entity = entityModeManager->m_4;
	if ((LOAD32(entity + 44) >> 27) & 1) {
		uint32_t entryValue;
		uint32_t indexTable = LOAD32(entity + 140);
		if (indexTable != 0) {
			// the byte at +91 of the table at +140 is the entry's index
			entryValue = LOAD32(LOAD32(entity + 72) + LOAD8(indexTable + 91) * 8 + 4);
		} else {
			// lower bound for key 91 over the sorted entries from +72 (begin) to +76 (end)
			uint32_t begin = LOAD32(entity + 72);
			uint32_t end = LOAD32(entity + 76);
			outR6 = end;
			STORE32(stack + 80, 0);
			STORE32(stack + 84, begin);
			uint32_t byteCount = end - begin;
			flags.ca = (int32_t)byteCount < 0 & (byteCount & 0x7) != 0;
			int32_t count = (int32_t)byteCount >> 3;
			compare0.compare<int32_t>(count, 0, flags);
			uint32_t pos = begin;
			if (count > 0) {
				do {
					flags.ca = count < 0 & (count & 0x1) != 0;
					int32_t half = count >> 1;
					uint32_t halfOffset = (uint32_t)half << 3;
					uint32_t mid = pos + halfOffset;
					bool keyBelow = (int32_t)LOAD32(mid) < 91;
					outR7 = keyBelow ? 1 : 0;
					outR8 = halfOffset;
					if (keyBelow) {
						pos = mid + 8;
						count = count - half - 1;
					} else {
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, pos);
			}
			if (pos != end && (int32_t)LOAD32(pos) <= 91) {
				STORE64(stack + 88, LOAD64(stack + 80));
				entryValue = LOAD32(LOAD32(stack + 92) + 4);
			} else {
				entryValue = LOAD32(end + 4);
			}
		}

		ctx.r1.u64 = stack;
		ctx.xer.ca = flags.ca;
		result = CECNetwork_ShouldReplicateEntity(ctx, base, entryValue);
		if ((result & 0xFF) != 0) {
			uint32_t modeObject = entityModeManager->m_20;
			if (modeObject != 0) {
				// state the callee may pass on
				ctx.cr0.lt = compare0.lt;
				ctx.cr0.gt = compare0.gt;
				ctx.cr0.eq = compare0.eq;
				ctx.cr0.so = compare0.so;
				CCharString_CopyConstruct(ctx, base, stack + 80, (uint64_t)modeObject + 8);
				uint64_t r8ForRelease = ctx.r8.u64;
				readCompareStateBack();

				uint64_t storedStringAddr = entityModeManagerAddr + 68;
				if (CCharString_NotEquals_82B3A158(ctx, base, stack + 80, storedStringAddr) & 0xFF) {
					// record at stack + 112: word 0x820A4C1C, then up to 64 characters of the string
					// (stack + 116), then a flag byte (stack + 180)
					uint32_t stringData = LOAD32(stack + 80);
					STORE8(stack + 180, 0);
					STORE32(stack + 112, (uint32_t)g_820A4C1C);
					uint64_t source = (stringData == 0) ? (uint64_t)g_8209003F : (uint64_t)LOAD32(stringData);
					ctx.r9.u64 = (uint64_t)g_820A4C1C;  // state the callee may pass on
					strncpy_s(ctx, base, stack + 116, 64, source, 64, ctx.r8.u64);
					readCompareStateBack();

					uint32_t lookupResult = AnimationComponent_FindAnimation(ctx, base, stack + 96, entityModeManagerAddr, 9);
					readCompareStateBack();

					// the lookup's {container, entry} pair: the container must be the manager's address + 0x14,
					// and the flag is set when the entry differs from m_18
					uint32_t absentEntry = entityModeManager->m_18;
					STORE64(stack + 88, LOAD64(lookupResult));
					uint32_t container = LOAD32(stack + 88);
					if (container == 0 || container != (uint32_t)(entityModeManagerAddr + 20)) {
						ppc_trap(ctx, base, 22);
					}
					if (LOAD32(stack + 92) != absentEntry) {
						STORE8(stack + 180, uint8_t(1));
					}

					uint32_t currentEntity = entityModeManager->m_4;
					uint32_t globalObject = LOAD32((uint32_t)g_83490000 + 26912);
					uint32_t receiver = LOAD32(LOAD32(globalObject + 12) + 140);
					uint64_t uniqueId = Entity_GetUniqueId(ctx, base, currentEntity);
					readCompareStateBack();

					n_sub_823F6BD8(ctx, base, receiver, stack + 112, uniqueId);
					readCompareStateBack();

					CCharString_Assign(ctx, base, storedStringAddr, stack + 80);
					readCompareStateBack();

					r8ForRelease = (uint64_t)g_820A2BB8;
					STORE32(stack + 112, (uint32_t)g_820A2BB8);
				}

				ctx.r8.u64 = r8ForRelease;  // state the callee may pass on
				result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				outR6 = ctx.r6.u64;
				outR7 = ctx.r7.u64;
				outR8 = ctx.r8.u64;
				readCompareStateBack();
			}
		}
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	// callers read r6-r8, cr0 and the carry after the call
	ctx.r6.u64 = outR6;
	ctx.r7.u64 = outR7;
	ctx.r8.u64 = outR8;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(22, sub_823F3A10, 0x823F3A10) { ctx.r3.u64 = CECEntityModeManager_UpdateReplicatedModeName(ctx, base, ctx.r3.u64); }
