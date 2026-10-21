// CGiftGivingScreen (vtable 0x820C1DF8): methods of the class as readable C++.
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

uint64_t CGiftGivingScreen_Destructor(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr, uint64_t deleteFlags) {
	constexpr int32_t vtablePage = int32_t(0x820A0000);
	constexpr int32_t C_820A5A2C_vtable = int32_t(0x820A5A2C);
	constexpr int32_t C_820A2F14_vtable = int32_t(0x820A2F14);
	constexpr int32_t CGuiScrollList_vtable = int32_t(0x820AEE3C);
	if (!UseLiftedCode(36, 0x825A0200)) { ctx.r3.u64 = giftGivingScreenAddr; ctx.r4.u64 = deleteFlags; __imp__sub_825A0200(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A0200);
	CGiftGivingScreen* giftGivingScreen = GameObject<CGiftGivingScreen>(base, giftGivingScreenAddr);
	GameStackFrame stackFrame(ctx, base, 128);

	ctx.r4.u64 = deleteFlags;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, giftGivingScreenAddr + 356);

	// Inlined destructors of the CGuiScrollList members at +320 and +96.
	giftGivingScreen->m_140 = uint32_t(CGuiScrollList_vtable);
	SharedHandleList_Clear(ctx, base, giftGivingScreenAddr + 328);
	HandleTarget_Free(ctx, base, giftGivingScreen->m_14C);
	giftGivingScreen->m_14C = 0;

	giftGivingScreen->m_60 = uint32_t(CGuiScrollList_vtable);
	SharedHandleList_Clear(ctx, base, giftGivingScreenAddr + 104);
	HandleTarget_Free(ctx, base, giftGivingScreen->m_6C);
	giftGivingScreen->m_6C = 0;

	CMenuScreen_Clear(ctx, base, giftGivingScreenAddr + 52);

	giftGivingScreen->m_18 = uint32_t(C_820A2F14_vtable);
	ctx.r8.u64 = C_820A2F14_vtable;
	PtrVector8_ClearAndFree(ctx, base, giftGivingScreenAddr + 28);

	giftGivingScreen->vtable = uint32_t(C_820A5A2C_vtable);
	ctx.r6.u64 = C_820A5A2C_vtable;
	ctx.r7.s64 = vtablePage;
	PtrVector8_ClearAndFree(ctx, base, giftGivingScreenAddr + 8);

	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, giftGivingScreenAddr);
	}
	return giftGivingScreenAddr;
}
PROMOTED_ENTRY(36, sub_825A0200, 0x825A0200) { ctx.r3.u64 = CGiftGivingScreen_Destructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGiftGivingScreen_Activate(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr, uint64_t forwardedValue1, uint64_t forwardedValue2) {
	constexpr int32_t str_TXT_820AFCF8_B_ = int32_t(0x820AFCF8);
	constexpr int32_t str_TXT_820AFD24_B_ = int32_t(0x820AFD24);
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820BFECC_B_ = int32_t(0x820BFECC);
	constexpr int32_t str_TXT_820C0000_B_ = int32_t(0x820C0000);
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A02B8)) { ctx.r3.u64 = giftGivingScreenAddr; ctx.r6.u64 = forwardedValue1; ctx.r7.u64 = forwardedValue2; __imp__sub_825A02B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A02B8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGiftGivingScreen* giftGivingScreen = GameObject<CGiftGivingScreen>(base, giftGivingScreenAddr);
	stack = PushStackFrame(base, stack, 144);

	uint32_t vtable = giftGivingScreen->vtable;
	uint32_t method = LOAD32(vtable + 4);
	callTarget.u64 = method;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = giftGivingScreenAddr;
	ctx.r6.u64 = forwardedValue1;
	ctx.r7.u64 = forwardedValue2;
	ctx.r10.u64 = method;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	// stack + 80: a CCharString, later the value pushed into the list; stack + 96: a vector of menu item addresses.
	const uint32_t scratch = stack + 80;
	const uint32_t menuItems = stack + 96;

	CCharString_ConstructFromCStr(ctx, base, scratch, str_TXT_820AFCF8_B_, -1);
	uint32_t formatterOwner = LOAD32(LOAD32(guiRootAddress) + 56);
	uint32_t formatter = LOAD32(formatterOwner + 152);
	ctx.r8.u64 = formatterOwner;
	GUIFormatter_FormatString(ctx, base, scratch, formatter, ctx.r6.u64, ctx.r7.u64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratch);

	ctx.r7.s64 = str_TXT_820B0000_B_;
	CCharString_ConstructFromCStr(ctx, base, scratch, str_TXT_820AFD24_B_, -1);
	uint32_t secondFormatterOwner = LOAD32(LOAD32(guiRootAddress) + 56);
	uint32_t secondFormatter = LOAD32(secondFormatterOwner + 152);
	GUIFormatter_FormatString(ctx, base, scratch, secondFormatter, secondFormatterOwner, ctx.r7.u64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratch);

	uint32_t giftMode = giftGivingScreen->m_30;
	if (giftMode <= 1) {
		giftGivingScreen->m_2C = giftMode == 1 ? 5 : 1;
		CGiftGivingScreen_SetupGoldMenu(ctx, base, giftGivingScreenAddr + 24);
	}

	STORE32(stack + 100, 0);
	STORE32(stack + 104, 0);
	STORE32(stack + 108, 0);
	STORE32(scratch, uint32_t(giftGivingScreenAddr + 96));
	Vector_PushBackU32(ctx, base, menuItems, scratch);
	STORE32(scratch, uint32_t(giftGivingScreenAddr + 320));
	Vector_PushBackU32(ctx, base, menuItems, scratch);

	ctx.r8.s64 = str_TXT_820C0000_B_;
	CCharString_ConstructFromCStr(ctx, base, scratch, str_TXT_820BFECC_B_, -1);
	uint32_t thirdFormatter = LOAD32(LOAD32(LOAD32(guiRootAddress) + 56) + 152);
	ctx.r7.u64 = 1;
	MenuScreen_SetMenuItems(ctx, base, giftGivingScreenAddr + 52, menuItems, scratch, thirdFormatter, ctx.r8.u64);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, scratch);

	uint64_t result = LOAD32(stack + 100);
	if (uint32_t(result) != 0) {
		result = HandleTarget_Free(ctx, base, result);
	}
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(36, sub_825A02B8, 0x825A02B8) { ctx.r3.u64 = CGiftGivingScreen_Activate(ctx, base, ctx.r3.u64, ctx.r6.u64, ctx.r7.u64); }

uint32_t CGiftGivingScreen_Update(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr) {
	constexpr uint32_t guiRootAddress = 0x834968A4;
	constexpr int32_t g_globalStringCount = int32_t(0x83496EB8);
	if (!UseLiftedCode(36, 0x825A0408)) { ctx.r3.u64 = giftGivingScreenAddr; __imp__sub_825A0408(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A0408);
	uint32_t stack = ctx.r1.u64;
	uint32_t lockMsr = ctx.r13.u64;
	PPCCRRegister compare0{};
	PPCXERRegister flags = ctx.xer;
	CGiftGivingScreen* giftGivingScreen = GameObject<CGiftGivingScreen>(base, giftGivingScreenAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint64_t stringCountAddr = g_globalStringCount;
	// Inlined empty CCharString construction: one more string in the global count. Returns the MSR seen on entry.
	auto countEmptyString = [&]() -> uint64_t {
		uint64_t previousMsr;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			previousMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)stringCountAddr);
			uint32_t newCount = __builtin_bswap32(ctx.reserved.u32);
			newCount = (int32_t)newCount + 1;
			compare0.lt = 0;
			compare0.gt = 0;
			compare0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)stringCountAddr)), ctx.reserved.s32, __builtin_bswap32((int32_t)newCount));
			compare0.so = flags.so;
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = (uint32_t)previousMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!compare0.eq);
		return previousMsr;
	};

	// Highlighted item record on the stack: id at +80, value at +84, CCharStrings at +88 and +92.
	const uint32_t itemData = stack + 80;
	STORE32(stack + 80, 0);
	STORE32(stack + 84, 0);
	STORE32(stack + 88, 0);
	uint64_t firstPreviousMsr = countEmptyString();
	STORE32(stack + 92, 0);
	countEmptyString();

	uint32_t menuManager = LOAD32(LOAD32(guiRootAddress) + 28);
	uint32_t activeMenu = LOAD32(menuManager + 60);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = stringCountAddr;
	ctx.r7.u64 = stringCountAddr;
	ctx.r8.u64 = firstPreviousMsr;
	Menu_GetHighlightedMenuItemData(ctx, base, activeMenu, itemData);

	uint32_t highlightedValue = LOAD32(stack + 84);
	if (highlightedValue != giftGivingScreen->m_160) {
		GUI_RefreshGiftDisplay(ctx, base, giftGivingScreenAddr + 96);
		giftGivingScreen->m_160 = highlightedValue;
	}

	uint32_t highlightedId = LOAD32(stack + 80);
	uint32_t visible = highlightedId != 301 ? 1 : 0;
	// The original leaves these two values of its test for id 301 in its argument registers for the calls below.
	uint32_t idDelta = highlightedId - 301;
	uint64_t idDeltaBits = idDelta == 0 ? 32 : __builtin_clz(idDelta);
	uint64_t isId301 = highlightedId == 301 ? 1 : 0;
	if (highlightedId == 301) {
		ctx.r8.u64 = isId301;
		ctx.r9.u64 = idDeltaBits;
		CGiftGivingScreen_UpdateExpandableMenu(ctx, base, giftGivingScreenAddr + 128);
		isId301 = ctx.r8.u64;
		idDeltaBits = ctx.r9.u64;
	}

	uint32_t formatter = LOAD32(LOAD32(LOAD32(guiRootAddress) + 56) + 152);
	ctx.r8.u64 = isId301;
	ctx.r9.u64 = idDeltaBits;
	MenuScreen_SetVisible(ctx, base, giftGivingScreenAddr + 52, formatter, visible);

	CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 92);
	uint32_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(36, sub_825A0408, 0x825A0408) { ctx.r3.u64 = CGiftGivingScreen_Update(ctx, base, ctx.r3.u64); }

uint64_t CGiftGivingScreen_OnActivate(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr) {
	constexpr uint32_t guiRootAddress = 0x834968A4;
	constexpr int32_t TXT_83498ED8_G_ = int32_t(0x83498ED8);
	if (!UseLiftedCode(36, 0x825A0508)) { ctx.r3.u64 = giftGivingScreenAddr; __imp__sub_825A0508(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A0508);
	GameStackFrame stackFrame(ctx, base, 96);

	C_820A5A2C_ForEachChild(ctx, base, giftGivingScreenAddr);
	CGiftGivingScreen_Update(ctx, base, giftGivingScreenAddr);
	n_sub_828CE180(ctx, base, giftGivingScreenAddr + 52);

	uint32_t formatterOwner = LOAD32(LOAD32(guiRootAddress) + 56);
	uint32_t formatter = LOAD32(formatterOwner + 152);
	return n_sub_82837218(ctx, base, formatter, TXT_83498ED8_G_, 1);
}
PROMOTED_ENTRY(36, sub_825A0508, 0x825A0508) { ctx.r3.u64 = CGiftGivingScreen_OnActivate(ctx, base, ctx.r3.u64); }

uint64_t CGiftGivingScreen_HandleEvent(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr, uint64_t eventId, uint64_t eventType, uint64_t eventData) {
	constexpr uint32_t eventJumpTable = 0x825A0B84;
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A0B58)) { ctx.r3.u64 = giftGivingScreenAddr; ctx.r4.u64 = eventId; ctx.r5.u64 = eventType; ctx.r8.u64 = eventData; __imp__sub_825A0B58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A0B58);

	const uint32_t eventIndex = uint32_t(eventId) - 26;
	if (uint32_t(eventType) == 1 && eventIndex <= 11) {
		// The original dispatches through a jump table and leaves the table entry in r0.
		const uint32_t tableEntry = LOAD32(eventJumpTable + eventIndex * 4);
		if (eventIndex == 10) {
			ctx.r0.u64 = tableEntry;
			ctx.r3.u64 = giftGivingScreenAddr;
			ctx.r4.u64 = eventId;
			ctx.r5.u64 = eventType;
			return UIContract_TriggerOnPressA(ctx, base, eventData);
		}
		if (eventIndex == 11) {
			ctx.r0.u64 = tableEntry;
			ctx.r4.u64 = eventId;
			ctx.r8.u64 = eventData;
			return CGiftGivingScreen_HandleCancel(ctx, base, giftGivingScreenAddr);
		}
		if (eventIndex <= 1 && LOAD8(uint32_t(giftGivingScreenAddr) + 92) != 0) {
			uint32_t formatter = LOAD32(LOAD32(LOAD32(guiRootAddress) + 56) + 152);
			ctx.r0.u64 = tableEntry;
			return MenuScreen_HandleEvent(ctx, base, giftGivingScreenAddr + 52, eventId, 1, formatter);
		}
	}
	ctx.r4.u64 = eventId;
	return giftGivingScreenAddr;
}
PROMOTED_ENTRY(36, sub_825A0B58, 0x825A0B58) { ctx.r3.u64 = CGiftGivingScreen_HandleEvent(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r8.u64); }

uint64_t CGiftGivingScreen_HandleCancel(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr) {
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A0BE8)) { ctx.r3.u64 = giftGivingScreenAddr; __imp__sub_825A0BE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A0BE8);
	GameStackFrame stackFrame(ctx, base, 112);

	uint32_t menuManager = LOAD32(LOAD32(guiRootAddress) + 28);
	uint32_t activeMenu = LOAD32(menuManager + 60);
	ctx.r3.u64 = activeMenu;
	uint64_t isAtRoot = Menu_IsHighlightedItemAtRoot(ctx, base);
	if ((isAtRoot & 0xFF) != 0) {
		uint32_t currentMenuManager = LOAD32(LOAD32(guiRootAddress) + 28);
		GUI_ExitMenusReturnToGame(ctx, base, currentMenuManager, 1);
		CGiftGivingScreen_UpdateExpandableMenu(ctx, base, giftGivingScreenAddr + 128);
	}
	return MenuScreen_OnCancel(ctx, base, giftGivingScreenAddr);
}
PROMOTED_ENTRY(36, sub_825A0BE8, 0x825A0BE8) { ctx.r3.u64 = CGiftGivingScreen_HandleCancel(ctx, base, ctx.r3.u64); }

uint64_t CGiftGivingScreen_SetExpandableMenuDisabled(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr, uint64_t inputCode, uint32_t inputValue, uint64_t forwardedValue1, uint64_t forwardedValue2) {
	constexpr int32_t str_TXT_820C050C_B_ = int32_t(0x820C050C);
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A0C58)) { ctx.r3.u64 = giftGivingScreenAddr; ctx.r4.u64 = inputCode; ctx.r5.u64 = inputValue; ctx.r6.u64 = forwardedValue1; ctx.r7.u64 = forwardedValue2; __imp__sub_825A0C58(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825A0C58);
	uint32_t stack = ctx.r1.u64;
	CGiftGivingScreen* giftGivingScreen = GameObject<CGiftGivingScreen>(base, giftGivingScreenAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t inputId = uint32_t(inputCode);
	// Values the original hands back to its caller in r4 and passes on in r6/r7 to the menu switch.
	uint64_t secondResult = inputCode;
	uint64_t carriedValue1 = forwardedValue1;
	uint64_t carriedValue2 = forwardedValue2;

	uint64_t menuManager = LOAD32(LOAD32(guiRootAddress) + 28);
	int32_t menuState = int32_t(LOAD32(uint32_t(menuManager) + 40));
	uint64_t result = menuManager;
	bool switchMenu = false;
	uint32_t nextMenu = 0;

	if (menuState == 5) {
		uint64_t inputScreen = LOAD32(uint32_t(menuManager) + 64);
		ctx.r1.u64 = stack;
		ctx.r6.u64 = forwardedValue1;
		ctx.r7.u64 = forwardedValue2;
		result = MenuScreen_HandleInput(ctx, base, inputScreen, inputCode, inputValue);
		secondResult = ctx.r4.u64;
		if ((result & 0xFF) == 0) {
			const uint32_t script = stack + 80;
			CCharString_ConstructFromCStr(ctx, base, script, str_TXT_820C050C_B_, -1);
			uint32_t formatter = LOAD32(LOAD32(LOAD32(guiRootAddress) + 56) + 152);
			GUIFormatter_FormatString(ctx, base, script, formatter, ctx.r6.u64, ctx.r7.u64);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, script);
			secondResult = ctx.r4.u64;
			if (inputId == 47) {
				uint64_t currentMenuManager = LOAD32(LOAD32(guiRootAddress) + 28);
				uint64_t cancelResult = MenuManager_CancelMenu(ctx, base, currentMenuManager, 5);
				stack = PopStackFrame(stack, 128);
				ctx.r1.u64 = stack;
				return cancelResult;
			}
			if (inputId == 46) {
				uint32_t currentInputScreen = LOAD32(LOAD32(LOAD32(guiRootAddress) + 28) + 64);
				STORE8(currentInputScreen, 0);
				uint32_t amount = LOAD32(currentInputScreen + 44);
				ctx.r8.u64 = currentInputScreen;
				CGiftGivingScreen_AdjustGoldGiftAmount(ctx, base, uint32_t(giftGivingScreenAddr), amount);
				carriedValue1 = ctx.r6.u64;
				carriedValue2 = ctx.r7.u64;
				nextMenu = 5;
				switchMenu = true;
			}
		}
	} else if (menuState == 3) {
		if (inputId == 47) {
			ctx.r1.u64 = stack;
			uint64_t cancelResult = MenuManager_CancelMenu(ctx, base, menuManager, 3);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return cancelResult;
		}
		if (inputId == 46) {
			uint32_t giftMode = giftGivingScreen->m_30;
			if (giftMode == 1) {
				ctx.r1.u64 = stack;
				ctx.r4.u64 = inputCode;
				ctx.r5.u64 = inputValue;
				ctx.r6.u64 = forwardedValue1;
				ctx.r7.u64 = forwardedValue2;
				CGiftGivingScreen_GiveGold(ctx, base, giftGivingScreenAddr);
				carriedValue1 = ctx.r6.u64;
				carriedValue2 = ctx.r7.u64;
			} else if (giftMode == 0) {
				ctx.r1.u64 = stack;
				ctx.r4.u64 = inputCode;
				ctx.r6.u64 = forwardedValue1;
				ctx.r7.u64 = forwardedValue2;
				CGiftGivingScreen_GiveSelectedGift(ctx, base, giftGivingScreenAddr);
				carriedValue1 = ctx.r6.u64;
				carriedValue2 = ctx.r7.u64;
			}
			nextMenu = 3;
			switchMenu = true;
		}
	}

	if (switchMenu) {
		uint64_t switchManager = LOAD32(LOAD32(guiRootAddress) + 28);
		ctx.r1.u64 = stack;
		ctx.r6.u64 = carriedValue1;
		ctx.r7.u64 = carriedValue2;
		MenuManager_SwitchToMenu(ctx, base, switchManager, nextMenu);
		uint64_t exitManager = LOAD32(LOAD32(guiRootAddress) + 28);
		GUI_ExitMenusReturnToGame(ctx, base, exitManager, 1);
		result = CGiftGivingScreen_UpdateExpandableMenu(ctx, base, giftGivingScreenAddr + 128);
		secondResult = ctx.r4.u64;
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(36, sub_825A0C58, 0x825A0C58) { ctx.r3.u64 = CGiftGivingScreen_SetExpandableMenuDisabled(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64, ctx.r7.u64); }

uint32_t CGiftGivingScreen_UpdateDummyGoldGift(CpuState& ctx, uint8_t* base, uint64_t goldAmount) {
	constexpr uint32_t globalRootAddress = 0x83496920;
	if (!UseLiftedCode(36, 0x825A0D98)) { ctx.r4.u64 = goldAmount; __imp__sub_825A0D98(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A0D98);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	uint32_t rootData = LOAD32(LOAD32(globalRootAddress) + 12);
	uint32_t stateObject = LOAD32(rootData + 140);
	bool bothFlagsSet = LOAD8(stateObject + 52) != 0 && LOAD8(stateObject + 53) != 0;
	uint32_t handleTable = LOAD32(rootData + 156);
	uint32_t tableKey = bothFlagsSet ? 1 : 2;

	ctx.r1.u64 = stack;
	uint64_t result = SortedArray_FindValueByKey(ctx, base, handleTable, tableKey);
	// Values the original passes on in r6, r7 and r8 to the script call: what the calls leave there, or what
	// the search below leaves (array end, last comparison, last half offset).
	uint64_t carriedEnd = ctx.r6.u64;
	uint64_t carriedIsLess = ctx.r7.u64;
	uint64_t carriedOffset = ctx.r8.u64;

	result += 12;
	uint32_t entity = 0;
	uint32_t handleSlot = LOAD32(uint32_t(result) + 4);
	if (handleSlot != 0) {
		entity = LOAD32(handleSlot);
		if (entity == 0) {
			ctx.r4.u64 = tableKey;
			ctx.r10.u64 = entity;
			result = EntityHandle_Release(ctx, base, result);
			carriedEnd = ctx.r6.u64;
			carriedIsLess = ctx.r7.u64;
			carriedOffset = ctx.r8.u64;
		}
	}

	// Component type 33 of the entity.
	if (((LOAD32(entity + 40) >> 1) & 1) != 0) {
		uint32_t componentValue;
		uint32_t slotTable = LOAD32(entity + 140);
		if (slotTable != 0) {
			uint32_t entry = (uint32_t(LOAD8(slotTable + 33)) << 3) + LOAD32(entity + 72);
			componentValue = LOAD32(entry + 4);
		} else {
			uint64_t entries = LOAD32(entity + 72);
			carriedEnd = LOAD32(entity + 76);
			STORE32(stack + 80, 0);
			carriedOffset = carriedEnd - entries;
			STORE32(stack + 84, uint32_t(entries));
			int32_t count = int32_t(carriedOffset) >> 3;
			if (count > 0) {
				do {
					int32_t half = count >> 1;
					carriedOffset = uint32_t(half) << 3;
					entries = carriedOffset + entries;
					carriedIsLess = int32_t(LOAD32(uint32_t(entries))) < 33 ? 1 : 0;
					if (carriedIsLess != 0) {
						count = count - half - 1;
						entries = entries + 8;
					} else {
						entries = entries - carriedOffset;
						count = half;
					}
				} while (count > 0);
				STORE32(stack + 84, uint32_t(entries));
			}
			if (uint32_t(entries) != uint32_t(carriedEnd) && int32_t(LOAD32(uint32_t(entries))) <= 33) {
				STORE64(stack + 80, LOAD64(stack + 80));
				componentValue = LOAD32(LOAD32(stack + 84) + 4);
			} else {
				componentValue = LOAD32(uint32_t(carriedEnd) + 4);
			}
		}
		ctx.r6.u64 = carriedEnd;
		ctx.r7.u64 = carriedIsLess;
		ctx.r8.u64 = carriedOffset;
		result = Lua_Stats_DummyGoldGift(ctx, base, componentValue, goldAmount);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return uint32_t(result);
}
PROMOTED_ENTRY(36, sub_825A0D98, 0x825A0D98) { ctx.r3.u64 = CGiftGivingScreen_UpdateDummyGoldGift(ctx, base, ctx.r4.u64); }

uint32_t CGiftGivingScreen_AdjustGoldGiftAmount(CpuState& ctx, uint8_t* base, uint32_t giftGivingScreenAddr, uint64_t goldAmount) {
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A11F0)) { ctx.r3.u64 = giftGivingScreenAddr; ctx.r4.u64 = goldAmount; __imp__sub_825A11F0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A11F0);
	uint32_t stack = ctx.r1.u64;
	CGiftGivingScreen* giftGivingScreen = GameObject<CGiftGivingScreen>(base, giftGivingScreenAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t result = giftGivingScreenAddr;
	uint32_t giftMode = giftGivingScreen->m_30;
	if (giftMode == 1) {
		ctx.r1.u64 = stack;
		ctx.r3.u64 = giftGivingScreenAddr;
		result = n_sub_825A0F50(ctx, base, goldAmount);
	} else if (giftMode == 0) {
		uint32_t guiRoot = LOAD32(guiRootAddress);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = guiRoot;
		ctx.r4.u64 = goldAmount;
		uint64_t heroHandle = Player_GetHeroEntityHandle(ctx, base);
		uint32_t hero = EntityHandle_GetEntity(ctx, base, heroHandle);
		// What the original passes on in r8 to the money call: left by the call, or the search's last half offset.
		uint64_t carriedOffset = ctx.r8.u64;

		// Component type 81 of the hero, 0 when it has none.
		uint32_t componentValue = 0;
		if (((LOAD32(hero + 44) >> 17) & 1) != 0) {
			uint32_t slotTable = LOAD32(hero + 140);
			if (slotTable != 0) {
				uint32_t entry = (uint32_t(LOAD8(slotTable + 81)) << 3) + LOAD32(hero + 72);
				componentValue = LOAD32(entry + 4);
			} else {
				uint32_t entries = LOAD32(hero + 72);
				uint32_t end = LOAD32(hero + 76);
				STORE32(stack + 80, 0);
				STORE32(stack + 84, entries);
				int32_t count = int32_t(end - entries) >> 3;
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						carriedOffset = uint32_t(half) << 3;
						entries = uint32_t(carriedOffset) + entries;
						if (int32_t(LOAD32(entries)) < 81) {
							count = count - half - 1;
							entries = entries + 8;
						} else {
							entries = entries - uint32_t(carriedOffset);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, entries);
				}
				if (entries != end && int32_t(LOAD32(entries)) <= 81) {
					STORE64(stack + 80, LOAD64(stack + 80));
					componentValue = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					componentValue = LOAD32(end + 4);
				}
			}
		}

		ctx.r8.u64 = carriedOffset;
		Player_ModifyMoney(ctx, base, componentValue, 0 - goldAmount, 0, 1, 0);
		ctx.r3.u64 = giftGivingScreenAddr;
		result = CGiftGivingScreen_UpdateDummyGoldGift(ctx, base, goldAmount);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(36, sub_825A11F0, 0x825A11F0) { ctx.r3.u64 = CGiftGivingScreen_AdjustGoldGiftAmount(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint32_t CGiftGivingScreen_GiveSelectedGift(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr) {
	constexpr uint32_t guiRootAddress = 0x834968A4;
	if (!UseLiftedCode(36, 0x825A13A0)) { ctx.r3.u64 = giftGivingScreenAddr; __imp__sub_825A13A0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A13A0);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	const uint32_t giftList = stack + 96;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = giftGivingScreenAddr;
	uint64_t result = CGiftGivingScreen_GetSelectedGiftList(ctx, base, giftList);
	// Values the original passes on in r6, r7 and r8 and leaves there for its caller: what the calls leave, or
	// what the search below leaves (array end, last comparison, last half offset).
	uint64_t carriedEnd = ctx.r6.u64;
	uint64_t carriedIsLess = ctx.r7.u64;
	uint64_t carriedOffset = ctx.r8.u64;

	if (LOAD32(giftList) != 0) {
		uint32_t guiRoot = LOAD32(guiRootAddress);
		ctx.r3.u64 = guiRoot;
		uint64_t heroHandle = Player_GetHeroEntityHandle(ctx, base);
		uint32_t hero = EntityHandle_GetEntity(ctx, base, heroHandle);
		carriedEnd = ctx.r6.u64;
		carriedIsLess = ctx.r7.u64;
		carriedOffset = ctx.r8.u64;

		// Component type 33 of the hero.
		if (((LOAD32(hero + 40) >> 1) & 1) != 0) {
			uint32_t componentValue;
			uint32_t slotTable = LOAD32(hero + 140);
			if (slotTable != 0) {
				uint32_t entry = (uint32_t(LOAD8(slotTable + 33)) << 3) + LOAD32(hero + 72);
				componentValue = LOAD32(entry + 4);
			} else {
				uint32_t entries = LOAD32(hero + 72);
				carriedEnd = LOAD32(hero + 76);
				STORE32(stack + 80, 0);
				uint32_t byteSpan = uint32_t(carriedEnd) - entries;
				STORE32(stack + 84, entries);
				int32_t count = int32_t(byteSpan) >> 3;
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						carriedOffset = uint32_t(half) << 3;
						entries = uint32_t(carriedOffset) + entries;
						carriedIsLess = int32_t(LOAD32(entries)) < 33 ? 1 : 0;
						if (carriedIsLess != 0) {
							count = count - half - 1;
							entries = entries + 8;
						} else {
							entries = entries - uint32_t(carriedOffset);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, entries);
				}
				if (entries != uint32_t(carriedEnd) && int32_t(LOAD32(entries)) <= 33) {
					STORE64(stack + 80, LOAD64(stack + 80));
					componentValue = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					componentValue = LOAD32(uint32_t(carriedEnd) + 4);
				}
			}
			ctx.r6.u64 = carriedEnd;
			ctx.r7.u64 = carriedIsLess;
			ctx.r8.u64 = carriedOffset;
			n_sub_823D1140(ctx, base, componentValue, giftList);
			carriedEnd = ctx.r6.u64;
			carriedIsLess = ctx.r7.u64;
			carriedOffset = ctx.r8.u64;
		}

		result = LOAD32(giftList);
		if (uint32_t(result) != 0) {
			ctx.r6.u64 = carriedEnd;
			ctx.r7.u64 = carriedIsLess;
			ctx.r8.u64 = carriedOffset;
			result = PtrList_RemoveAll(ctx, base, result, giftList);
			carriedEnd = ctx.r6.u64;
			carriedIsLess = ctx.r7.u64;
			carriedOffset = ctx.r8.u64;
		}
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = carriedEnd;
	ctx.r7.u64 = carriedIsLess;
	ctx.r8.u64 = carriedOffset;
	return uint32_t(result);
}
PROMOTED_ENTRY(36, sub_825A13A0, 0x825A13A0) { ctx.r3.u64 = CGiftGivingScreen_GiveSelectedGift(ctx, base, ctx.r3.u64); }

uint32_t CGiftGivingScreen_GiveGold(CpuState& ctx, uint8_t* base, uint64_t giftGivingScreenAddr) {
	constexpr uint32_t globalRootAddress = 0x83496920;
	constexpr uint32_t trackedWordAddress = 0x83496FB8;
	constexpr uint32_t resetWordAddress = 0x8209FCE4;
	if (!UseLiftedCode(36, 0x825A1510)) { ctx.r3.u64 = giftGivingScreenAddr; __imp__sub_825A1510(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x825A1510);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 160);

	uint32_t rootData = LOAD32(LOAD32(globalRootAddress) + 12);
	uint32_t stateObject = LOAD32(rootData + 140);
	bool bothFlagsSet = LOAD8(stateObject + 52) != 0 && LOAD8(stateObject + 53) != 0;
	uint32_t handleTable = LOAD32(rootData + 156);
	uint32_t tableKey = bothFlagsSet ? 1 : 2;

	ctx.r1.u64 = stack;
	uint64_t result = SortedArray_FindValueByKey(ctx, base, handleTable, tableKey);
	// Values the original passes on in r7 and r8 (and r6, below) and leaves there for its caller.
	uint64_t carriedFlag = ctx.r7.u64;
	uint64_t carriedDelta = ctx.r8.u64;

	result += 12;
	uint32_t entity = 0;
	uint32_t handleSlot = LOAD32(uint32_t(result) + 4);
	if (handleSlot != 0) {
		entity = LOAD32(handleSlot);
		if (entity == 0) {
			ctx.r4.u64 = tableKey;
			ctx.r10.u64 = entity;
			result = EntityHandle_Release(ctx, base, result);
			carriedFlag = ctx.r7.u64;
			carriedDelta = ctx.r8.u64;
		}
	}
	uint64_t carriedPointer = entity;

	// Presence of component type 91 (the original also searches its array and discards what it finds).
	if (((LOAD32(entity + 44) >> 27) & 1) != 0) {
		// Compare the word at trackedWordAddress with the one at resetWordAddress, byte by byte.
		for (uint32_t i = 0; i < 4; ++i) {
			carriedFlag = LOAD8(resetWordAddress + i);
			carriedDelta = uint64_t(LOAD8(trackedWordAddress + i)) - carriedFlag;
			if (int32_t(carriedDelta) != 0) {
				break;
			}
		}

		// Component type 218 of the entity.
		if (int32_t(carriedDelta) != 0 && ((LOAD32(entity + 60) >> 26) & 1) != 0) {
			uint32_t componentValue;
			uint32_t slotTable = LOAD32(entity + 140);
			uint32_t entries = LOAD32(entity + 72);
			if (slotTable != 0) {
				uint32_t entry = (uint32_t(LOAD8(slotTable + 218)) << 3) + entries;
				componentValue = LOAD32(entry + 4);
			} else {
				carriedPointer = LOAD32(entity + 76);
				STORE32(stack + 80, 0);
				uint32_t byteSpan = uint32_t(carriedPointer) - entries;
				STORE32(stack + 84, entries);
				int32_t count = int32_t(byteSpan) >> 3;
				if (count > 0) {
					do {
						int32_t half = count >> 1;
						carriedDelta = uint32_t(half) << 3;
						entries = uint32_t(carriedDelta) + entries;
						carriedFlag = int32_t(LOAD32(entries)) < 218 ? 1 : 0;
						if (carriedFlag != 0) {
							count = count - half - 1;
							entries = entries + 8;
						} else {
							entries = entries - uint32_t(carriedDelta);
							count = half;
						}
					} while (count > 0);
					STORE32(stack + 84, entries);
				}
				if (entries != uint32_t(carriedPointer) && int32_t(LOAD32(entries)) <= 218) {
					STORE64(stack + 80, LOAD64(stack + 80));
					componentValue = LOAD32(LOAD32(stack + 84) + 4);
				} else {
					componentValue = LOAD32(uint32_t(carriedPointer) + 4);
				}
			}

			const uint32_t giftList = stack + 96;
			ctx.r6.u64 = carriedPointer;
			ctx.r7.u64 = carriedFlag;
			ctx.r8.u64 = carriedDelta;
			result = CGiftGivingScreen_GetSelectedGiftList(ctx, base, giftList);
			carriedPointer = ctx.r6.u64;
			carriedFlag = ctx.r7.u64;
			carriedDelta = ctx.r8.u64;

			uint32_t listHead = LOAD32(giftList);
			if (listHead != 0) {
				if (LOAD32(listHead + 4) != 0) {
					n_sub_8238BEB0(ctx, base, componentValue, giftList, 0);
				}
				STORE32(trackedWordAddress, LOAD32(resetWordAddress));
				CGiftGivingScreen_HandleCancel(ctx, base, giftGivingScreenAddr);
				carriedPointer = ctx.r6.u64;
				carriedFlag = ctx.r7.u64;
				carriedDelta = ctx.r8.u64;

				result = LOAD32(giftList);
				if (uint32_t(result) != 0) {
					result = PtrList_RemoveAll(ctx, base, result, giftList);
					carriedPointer = ctx.r6.u64;
					carriedFlag = ctx.r7.u64;
					carriedDelta = ctx.r8.u64;
				}
			}
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	ctx.r6.u64 = carriedPointer;
	ctx.r7.u64 = carriedFlag;
	ctx.r8.u64 = carriedDelta;
	return uint32_t(result);
}
PROMOTED_ENTRY(36, sub_825A1510, 0x825A1510) { ctx.r3.u64 = CGiftGivingScreen_GiveGold(ctx, base, ctx.r3.u64); }
