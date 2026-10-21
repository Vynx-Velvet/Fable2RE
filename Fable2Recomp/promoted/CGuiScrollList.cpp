// CGuiScrollList (vtable 0x820AEE3C): methods of the class as readable C++.
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

uint32_t CGuiScrollList_Destructor(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(35, 0x82581820)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_82581820(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82581820);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t memberAt92 = guiScrollListAddr + 92;
	uint64_t memberAt36 = guiScrollListAddr + 36;
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, memberAt92 + 36);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, memberAt92 + 8);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, memberAt36 + 36);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, memberAt36 + 8);
	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);
	uint32_t handle = guiScrollList->m_C;
	uint32_t result = HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(35, sub_82581820, 0x82581820) { ctx.r3.u64 = CGuiScrollList_Destructor(ctx, base, ctx.r3.u64); }

uint32_t CGuiScrollList_BaseDestructor(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(35, 0x825818A0)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_825818A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825818A0);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, guiScrollListAddr + 72);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, guiScrollListAddr + 44);
	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);
	uint32_t targetHandle = guiScrollList->m_C;
	uint32_t result = HandleTarget_Free(ctx, base, targetHandle);
	guiScrollList->m_C = 0u;
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(35, sub_825818A0, 0x825818A0) { ctx.r3.u64 = CGuiScrollList_BaseDestructor(ctx, base, ctx.r3.u64); }

uint32_t CGuiScrollList_DestructorWithMap(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(35, 0x82581908)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_82581908(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82581908);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, guiScrollListAddr + 40);
	// StdMap_DestroyGlobal_83497DCC erases every node of the map at +28 and frees its head node.
	StdMap_DestroyGlobal_83497DCC(ctx, base, guiScrollListAddr + 28);
	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);
	uint32_t handle = guiScrollList->m_C;
	uint32_t result = HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(35, sub_82581908, 0x82581908) { ctx.r3.u64 = CGuiScrollList_DestructorWithMap(ctx, base, ctx.r3.u64); }

uint32_t CGuiScrollList_Cleanup(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(35, 0x825828F8)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_825828F8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825828F8);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 112);

	uint32_t heldObject = guiScrollList->m_68;
	if (heldObject != 0) {
		uint32_t secondVirtualFn = LOAD32(LOAD32(heldObject) + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = heldObject;
		ctx.r10.u64 = secondVirtualFn;
		REX_CALL_INDIRECT_FUNC(secondVirtualFn);
	}
	guiScrollList->m_68 = 0;
	STORE32(guiScrollListAddr + 100, 0);

	ctx.r1.u64 = stack;
	StdMap_ClearAndFree(ctx, base, guiScrollListAddr + 28);

	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);

	uint32_t handle = guiScrollList->m_C;
	uint32_t result = HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0;

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(35, sub_825828F8, 0x825828F8) { ctx.r3.u64 = CGuiScrollList_Cleanup(ctx, base, ctx.r3.u64); }

uint32_t CGuiScrollList_DestructorWithStrings(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(36, 0x8259E068)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_8259E068(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x8259E068);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 96);

	uint64_t charStringA = guiScrollListAddr + 36;
	ctx.r1.u64 = stack;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringA);

	uint64_t charStringB = guiScrollListAddr + 32;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringB);

	uint64_t sharedHandleList = guiScrollListAddr + 8;
	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, sharedHandleList);

	uint32_t handle = guiScrollList->m_C;
	uint32_t released = HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(36, sub_8259E068, 0x8259E068) { ctx.r3.u64 = CGuiScrollList_DestructorWithStrings(ctx, base, ctx.r3.u64); }

uint64_t CGuiScrollList_AttachScrollTarget(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t entityId) {
	if (!UseLiftedCode(57, 0x82833920)) { ctx.r3.u64 = guiScrollListAddr; ctx.r8.u64 = entityId; __imp__sub_82833920(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82833920);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t thirdVirtualFn = LOAD32(uint32_t(guiScrollList->vtable) + 8);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = guiScrollListAddr;
	ctx.r8.u64 = entityId;
	ctx.r10.u64 = thirdVirtualFn;
	REX_CALL_INDIRECT_FUNC(thirdVirtualFn);

	// The lookup takes the r8 that the virtual call left behind, not entityId.
	uint32_t lookupSource = LOAD32(LOAD32(0x834968A4u) + 56);
	uint64_t result = GameObject_LookupByHandle(ctx, base, lookupSource, ctx.r8.u64);
	if ((uint32_t)result != 0)
		result = CGuiScrollList_AttachEntry(ctx, base, result, guiScrollListAddr + 8);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(57, sub_82833920, 0x82833920) { ctx.r3.u64 = CGuiScrollList_AttachScrollTarget(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t CGuiScrollList_Clear(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr) {
	if (!UseLiftedCode(57, 0x82833978)) { ctx.r3.u64 = guiScrollListAddr; __imp__sub_82833978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82833978);
	return SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);
}
PROMOTED_ENTRY(57, sub_82833978, 0x82833978) { ctx.r3.u64 = CGuiScrollList_Clear(ctx, base, ctx.r3.u64); }

uint64_t CGuiScrollList_ProcessEntryCountdowns(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t entityId) {
	if (!UseLiftedCode(57, 0x82833980)) { ctx.r3.u64 = guiScrollListAddr; ctx.r8.u64 = entityId; __imp__sub_82833980(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82833980);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 144);

	// The original code hands r4, cr0 and xer.ca to its callees and leaves r4, r8, cr0 and
	// xer.ca for its callers; r4Value, entityId, compare0 and flags track those registers.
	uint64_t r4Value = ctx.r4.u64;
	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;
	uint64_t result = guiScrollListAddr;

	// Circular list at +8; its sentinel node pointer is at +12 (m_C).
	uint32_t listAddr = (uint32_t)guiScrollListAddr + 8;
	uint32_t node = LOAD32(uint32_t(guiScrollList->m_C));
	while (node != LOAD32(listAddr + 4)) {
		uint32_t lookupSource = LOAD32(LOAD32(0x834968A4u) + 56);
		uint32_t entry = LOAD32(node + 8);

		ctx.r1.u64 = stack;
		ctx.cr0 = compare0;
		ctx.xer.ca = flags.ca;
		result = GameObject_LookupByHandle(ctx, base, lookupSource, entityId);
		entityId = ctx.r8.u64;
		compare0 = ctx.cr0;
		flags.ca = ctx.xer.ca;
		r4Value = result;

		uint32_t counter = LOAD32(entry + 64);
		if (counter != 0) {
			// Decrementing a nonzero value sets the carry; cr0 keeps the new value's sign.
			flags.ca = 1;
			counter = counter - 1;
			compare0.compare<int32_t>((int32_t)counter, 0, flags);
			STORE32(entry + 64, counter);
			if ((int32_t)counter <= 0) {
				STORE32(entry + 64, 0);
				ctx.cr0 = compare0;
				ctx.xer.ca = flags.ca;
				result = CGuiScrollListEntry_OnCountdownExpired(ctx, base, entry, r4Value, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64);
				r4Value = ctx.r4.u64;
				entityId = ctx.r8.u64;
				compare0 = ctx.cr0;
				flags.ca = ctx.xer.ca;
			}
		}

		if (node == LOAD32(listAddr + 4))
			ppc_trap(ctx, base, 22);
		node = LOAD32(node);
	}

	if (guiScrollList->m_18 != 0) {
		bool clearFlag = true;
		if (uint32_t(guiScrollList->m_10) != 0) {
			uint32_t sentinel = LOAD32(listAddr + 4);
			uint32_t firstNode = LOAD32(sentinel);
			if (firstNode == sentinel) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			uint32_t firstEntry = LOAD32(firstNode + 8);
			if (firstEntry == 0 || (int32_t)LOAD32(firstEntry + 64) > 0) {
				clearFlag = false;
			} else {
				ctx.r1.u64 = stack;
				ctx.cr0 = compare0;
				ctx.xer.ca = flags.ca;
				result = CGuiScrollList_UpdateArrows(ctx, base, guiScrollListAddr, entityId);
				r4Value = ctx.r4.u64;
				entityId = ctx.r8.u64;
				compare0 = ctx.cr0;
				flags.ca = ctx.xer.ca;
			}
		}
		if (clearFlag)
			guiScrollList->m_18 = 0;
	}

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4Value;
	ctx.r8.u64 = entityId;
	ctx.cr0 = compare0;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(57, sub_82833980, 0x82833980) { ctx.r3.u64 = CGuiScrollList_ProcessEntryCountdowns(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t CGuiScrollList_UpdateBladeContentsScroll(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t eventType, uint64_t bladeIndexArg, uint64_t entityId) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	constexpr int32_t g_820994B4 = int32_t(0x820994B4);
	constexpr int32_t g_82100170 = int32_t(0x82100170);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t TXT_83498764_G_ = int32_t(0x83498764);
	if (!UseLiftedCode(57, 0x82833A90)) { ctx.r3.u64 = guiScrollListAddr; ctx.r4.u64 = eventType; ctx.r5.u64 = bladeIndexArg; ctx.r8.u64 = entityId; __imp__sub_82833A90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82833A90);
	uint32_t stack = ctx.r1.u64;

	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 224);

	uint64_t scrollListBase = guiScrollListAddr;

	if ((int32_t)eventType == 27) {
		uint32_t listEndAddr = (uint32_t)scrollListBase + 8;
		uint32_t node = LOAD32(uint32_t(guiScrollList->m_C));
		uint32_t bladeIndex = (uint32_t)bladeIndexArg;
		uint64_t helperTable = g_82000000;
		bool listChanged = false;

		ctx.fpscr.disableFlushMode();
		double wrapConstant = LOAD_F64(0x82000DE8u);
		double defaultOffset = double(LOAD_F32((uint32_t)g_820994B4));
		double altOffset = double(LOAD_F32(0x821002F0u));

		while (node != LOAD32(listEndAddr + 4)) {
			uint32_t scrollState = LOAD32((uint32_t)g_83490000 + 26788);
			uint32_t animSet = LOAD32(scrollState + 56);
			uint32_t animPtr = LOAD32(scrollState + (bladeIndex == 2 ? 24 : 20));
			uint64_t anglePair = LOAD64(animPtr + 24);

			ctx.fpscr.disableFlushMode();
			STORE64(stack + 80, anglePair);
			double angleLow = double(LOAD_F32(stack + 80));

			ctx.r1.u64 = stack;
			ctx.r3.u64 = scrollListBase;
			uint64_t firstCallResult = Math_WrapAngle(ctx, base, -double(LOAD_F32(stack + 84)), wrapConstant);
			double angleY = double(float(ctx.f1.f64));

			ctx.fpscr.disableFlushMode();
			ctx.r3.u64 = firstCallResult;
			Math_WrapAngle(ctx, base, -angleLow, wrapConstant);
			uint64_t animIndexArg = ctx.r8.u64;
			uint64_t dirArg = ctx.r9.u64;
			double angleX = double(float(ctx.f1.f64));
			STORE_F32(stack + 88, float(angleX));

			double offset;
			if (angleY > defaultOffset) {
				offset = double(LOAD_F32((uint32_t)g_820994B4 + 9560));
			} else {
				ctx.fpscr.disableFlushMode();
				bool isLess = angleY < defaultOffset;
				bool isUnordered = !(angleY >= defaultOffset) && !isLess;
				dirArg = isUnordered ? 4u : 0u;
				animIndexArg = dirArg | (isLess ? 4u : 0u);
				offset = double(LOAD_F32((uint32_t)g_82100170 + uint32_t(animIndexArg)));
				offset = offset >= 0.0 ? defaultOffset : altOffset;
			}

			ctx.fpscr.disableFlushMode();
			STORE_F32(stack + 92, float(angleY + offset));
			if (node == LOAD32(listEndAddr + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}

			uint64_t nodeData = LOAD32(node + 8);
			ctx.f12.f64 = angleX;
			uint64_t animResult = GameObject_LookupByHandle(ctx, base, uint64_t(animSet), animIndexArg);
			uint64_t packedAngle = LOAD64(stack + 88);
			guiScrollListAddr = CGuiScrollListEntry_UpdateAngles(ctx, base, nodeData, packedAngle, animResult, ctx.r7.u64, ctx.r8.u64, ctx.r9.u64);
			eventType = ctx.r4.u64;
			bladeIndexArg = ctx.r5.u64;
			entityId = ctx.r8.u64;
			helperTable = ctx.r9.u64;
			if ((uint32_t(guiScrollListAddr) & 0xFF) != 0)
				listChanged = true;
			if (node == LOAD32(listEndAddr + 4)) {
				ctx.r1.u64 = stack;
				ppc_trap(ctx, base, 22);
			}
			node = LOAD32(node);
		}

		ctx.r1.u64 = stack;
		ctx.r5.u64 = bladeIndexArg;
		guiScrollListAddr = CGuiScrollList_UpdateArrows(ctx, base, scrollListBase, entityId);
		eventType = ctx.r4.u64;
		entityId = ctx.r8.u64;

		if (listChanged) {
			uint32_t scrollState = LOAD32((uint32_t)g_83490000 + 26788);
			Sound_CreateFromEvent(ctx, base, uint64_t(stack) + 96, uint64_t(scrollState), TXT_83498764_G_);
			eventType = ctx.r4.u64;
			entityId = ctx.r8.u64;
			guiScrollListAddr = LOAD32(stack + 100);
			if ((uint32_t)guiScrollListAddr != 0) {
				uint32_t vfunc = LOAD32(LOAD32((uint32_t)guiScrollListAddr) + 4);
				PPCRegister callTarget{};
				callTarget.u64 = uint64_t(vfunc);
				ctx.r3.u64 = guiScrollListAddr;
				ctx.r10.u64 = vfunc;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				guiScrollListAddr = ctx.r3.u64;
				eventType = ctx.r4.u64;
				entityId = ctx.r8.u64;
			}
		}
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = eventType;
	ctx.r8.u64 = entityId;
	return guiScrollListAddr;
}
PROMOTED_ENTRY(57, sub_82833A90, 0x82833A90) { ctx.r3.u64 = CGuiScrollList_UpdateBladeContentsScroll(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint64_t CGuiScrollList_UpdateArrows(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t arg2) {
	constexpr int32_t str_TXT_8209BAAC_B_ = int32_t(0x8209BAAC);
	constexpr int32_t str_TXT_820DB6F4_B_ = int32_t(0x820DB6F4);
	constexpr int32_t str_TXT_820DB6FC_B_ = int32_t(0x820DB6FC);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr int32_t str_TXT_820DB708_B_ = int32_t(0x820DB708);
	if (!UseLiftedCode(57, 0x82833E70)) { ctx.r3.u64 = guiScrollListAddr; ctx.r8.u64 = arg2; __imp__sub_82833E70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82833E70);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 192);
	uint32_t listAddr = (uint32_t)guiScrollListAddr;
	if (LOAD32(listAddr + 20) != 0) {
		uint32_t guiRoot = LOAD32(uint32_t(g_83490000) + 26788);
		uint32_t scrollHost = LOAD32(guiRoot + 56);
		ctx.r1.u64 = stack;
		guiScrollListAddr = GameObject_LookupByHandle(ctx, base, scrollHost, arg2);
		arg2 = ctx.r8.u64;
		uint64_t r9Value = ctx.r9.u64;
		uint64_t entity = guiScrollListAddr;
		if ((uint32_t)entity != 0) {
			uint32_t hasEntry;
			if (LOAD32(listAddr + 16) > 0) {
				uint32_t listHead = guiScrollList->m_C;
				r9Value = listHead;
				uint32_t firstNode = LOAD32(listHead);
				if (firstNode == listHead) {
					ppc_trap(ctx, base, 22);
				}
				uint32_t entry = LOAD32(firstNode + 8);
				if (entry == 0) {
					hasEntry = 0;
				} else {
					hasEntry = LOAD8(entry + 36);
				}
			} else {
				hasEntry = 0;
			}
			hasEntry &= 0xFF;

			uint32_t scrollMode;
			if (hasEntry != 0) {
				uint32_t arrowOwner = guiScrollList->m_14;
				uint64_t upArrowCStr = CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 80, str_TXT_820DB6F4_B_, -1);
				uint64_t TXT_820DB6F4_L_ = GuiLayer_CreateChild(ctx, base, upArrowCStr, (uint64_t)arrowOwner, entity, ctx.r8.u64);

				uint32_t arrowOwner2 = guiScrollList->m_14;
				uint64_t downArrowCStr = CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 84, str_TXT_820DB6FC_B_, -1);
				uint64_t TXT_820DB6FC_L_ = GuiLayer_CreateChild(ctx, base, downArrowCStr, (uint64_t)arrowOwner2, entity, ctx.r8.u64);

				uint32_t arrowOwner3 = guiScrollList->m_14;
				uint64_t iconCStr = CCharString_ConstructFromCStr(ctx, base, uint64_t(stack) + 88, str_TXT_820DB708_B_, -1);
				uint64_t r9AfterIcon = ctx.r9.u64;
				GuiLayer_CreateChild(ctx, base, iconCStr, (uint64_t)arrowOwner3, entity, ctx.r8.u64);

				uint32_t v10 = guiScrollList->m_10;
				uint32_t TXT_8209BAAC_L_ = uint32_t(str_TXT_8209BAAC_B_);
				ctx.fpscr.disableFlushMode();
				double minValue = double(LOAD_F32(TXT_8209BAAC_L_ - 9720));
				double currentValue;
				if (v10 > 0) {
					uint32_t listHead2 = guiScrollList->m_C;
					r9AfterIcon = listHead2;
					uint32_t firstNode2 = LOAD32(listHead2);
					if (firstNode2 == listHead2) {
						ppc_trap(ctx, base, 22);
					}
					uint32_t entry2 = LOAD32(firstNode2 + 8);
					if (entry2 == 0) {
						ctx.fpscr.disableFlushMode();
						currentValue = minValue;
					} else {
						ctx.fpscr.disableFlushMode();
						currentValue = double(LOAD_F32(entry2 + 32));
					}
				} else {
					ctx.fpscr.disableFlushMode();
					currentValue = minValue;
				}
				ctx.r8.u64 = v10;
				ctx.r9.u64 = r9AfterIcon;
				uint32_t upArrowState = GuiElement_GetState(ctx, base, TXT_820DB6F4_L_, entity);
				uint32_t downArrowState = GuiElement_GetState(ctx, base, TXT_820DB6FC_L_, entity);
				ctx.fpscr.disableFlushMode();
				double maxValue = double(LOAD_F32(TXT_8209BAAC_L_ - 9708));
				if (currentValue == minValue) {
					if (upArrowState != 1) {
						GuiElement_SetState(ctx, base, TXT_820DB6F4_L_, entity, 1);
					}
					if (downArrowState != 2) {
						GuiElement_SetState(ctx, base, TXT_820DB6FC_L_, entity, 2);
					}
				} else {
					ctx.fpscr.disableFlushMode();
					if (currentValue == maxValue) {
						if (upArrowState != 2) {
							GuiElement_SetState(ctx, base, TXT_820DB6F4_L_, entity, 2);
						}
						if (downArrowState != 1) {
							GuiElement_SetState(ctx, base, TXT_820DB6FC_L_, entity, 1);
						}
					} else {
						if (upArrowState != 2) {
							GuiElement_SetState(ctx, base, TXT_820DB6F4_L_, entity, 2);
						}
						if (downArrowState != 2) {
							GuiElement_SetState(ctx, base, TXT_820DB6FC_L_, entity, 2);
						}
					}
				}
				ctx.fpscr.disableFlushMode();
				double scrollDelta = double(float(maxValue - currentValue));
				double scrollAmount = double(float(scrollDelta * double(LOAD_F32(TXT_8209BAAC_L_))));
				ctx.f13.f64 = scrollDelta;
				CGuiScrollList_SetScrollPosition(ctx, base, guiScrollList->m_14, entity, scrollAmount);
				scrollMode = 1;
			} else {
				ctx.fpscr.disableFlushMode();
				double scrollAmount = double(LOAD_F32(uint32_t(str_TXT_8209BAAC_B_)));
				ctx.r9.u64 = r9Value;
				CGuiScrollList_SetScrollPosition(ctx, base, guiScrollList->m_14, entity, scrollAmount);
				scrollMode = 0;
			}
			guiScrollListAddr = GuiElement_SetVisibility(ctx, base, guiScrollList->m_14, entity, scrollMode);
			arg2 = ctx.r8.u64;
		}
	}
	stack = PopStackFrame(stack, 192);
	ctx.r1.u64 = stack;
	ctx.r8.u64 = arg2;
	return guiScrollListAddr;
}
PROMOTED_ENTRY(57, sub_82833E70, 0x82833E70) { ctx.r3.u64 = CGuiScrollList_UpdateArrows(ctx, base, ctx.r3.u64, ctx.r8.u64); }

uint64_t CGuiScrollList_DeletingDestructorWithMap(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t arg2) {
	if (!UseLiftedCode(62, 0x828D7218)) { ctx.r3.u64 = guiScrollListAddr; ctx.r4.u64 = arg2; __imp__sub_828D7218(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828D7218);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);

	stack = PushStackFrame(base, stack, 112);
	uint64_t embeddedObjectAddr = guiScrollListAddr + 28;
	uint64_t sharedHandleListAddr = guiScrollListAddr + 8;

	ctx.r1.u64 = stack;
	StdMap_ClearAndFree(ctx, base, embeddedObjectAddr);

	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, sharedHandleListAddr);

	uint32_t handle = guiScrollList->m_C;
	HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;

	uint64_t object = guiScrollListAddr;
	if ((arg2 & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
		object = guiScrollListAddr;
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(62, sub_828D7218, 0x828D7218) { ctx.r3.u64 = CGuiScrollList_DeletingDestructorWithMap(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_828FE378  [120 bytes]
uint64_t CGuiScrollList_DeletingDestructorWithList(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t flags) {
	if (!UseLiftedCode(64, 0x828FE378)) { ctx.r3.u64 = guiScrollListAddr; ctx.r4.u64 = flags; __imp__sub_828FE378(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828FE378);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.r1.u64 = stack;
	StdMap_ClearAndFreeHead(ctx, base, guiScrollListAddr + 88);

	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);

	uint32_t handle = guiScrollList->m_C;
	HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;

	if ((flags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, guiScrollListAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return guiScrollListAddr;
}
PROMOTED_ENTRY(64, sub_828FE378, 0x828FE378) { ctx.r3.u64 = CGuiScrollList_DeletingDestructorWithList(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGuiScrollList_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t arg2) {
	if (!UseLiftedCode(64, 0x829019C8)) { ctx.r3.u64 = guiScrollListAddr; ctx.r4.u64 = arg2; __imp__sub_829019C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829019C8);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t handleListAddr = guiScrollListAddr + 8;
	uint32_t deleteFlags = static_cast<uint32_t>(arg2);
	guiScrollList->vtable = 0x820AEE3Cu;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	SharedHandleList_Clear(ctx, base, handleListAddr);
	uint32_t handle = guiScrollList->m_C;
	HandleTarget_Free(ctx, base, handle);
	guiScrollList->m_C = 0u;
	if (deleteFlags & 1) {
		HandleTarget_Free(ctx, base, guiScrollListAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return guiScrollListAddr;
}
PROMOTED_ENTRY(64, sub_829019C8, 0x829019C8) { ctx.r3.u64 = CGuiScrollList_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGuiScrollList_DeletingDestructorWithPageList(CpuState& ctx, uint8_t* base, uint64_t guiScrollListAddr, uint64_t arg2) {
	if (!UseLiftedCode(64, 0x829027E0)) { ctx.r3.u64 = guiScrollListAddr; ctx.r4.u64 = arg2; __imp__sub_829027E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x829027E0);
	uint32_t stack = ctx.r1.u64;
	CGuiScrollList* guiScrollList = GameObject<CGuiScrollList>(base, guiScrollListAddr);
	uint32_t freeFlag = (uint32_t)arg2;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	GuiFamilyPageList_Clear(ctx, base, guiScrollListAddr + 28);
	guiScrollList->vtable = 0x820AEE3Cu;
	SharedHandleList_Clear(ctx, base, guiScrollListAddr + 8);
	HandleTarget_Free(ctx, base, guiScrollList->m_C);
	guiScrollList->m_C = 0u;
	uint64_t result = guiScrollListAddr;
	if ((freeFlag & 0x1) != 0) {
		HandleTarget_Free(ctx, base, guiScrollListAddr);
		result = guiScrollListAddr;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(64, sub_829027E0, 0x829027E0) { ctx.r3.u64 = CGuiScrollList_DeletingDestructorWithPageList(ctx, base, ctx.r3.u64, ctx.r4.u64); }
