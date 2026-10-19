// CGuiOptionsAudioScreen (vtable 0x820E4768): methods of the class as readable C++.
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

uint32_t CGuiOptionsAudioScreen_Constructor(CpuState& ctx, uint8_t* base, uint32_t guiOptionsAudioScreenAddr) {
	if (!UseLiftedCode(57, 0x828338A8)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; __imp__sub_828338A8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828338A8);
	uint32_t stack = ctx.r1.u64;
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 96);
	guiOptionsAudioScreen->m_4 = uint8_t(1);
	guiOptionsAudioScreen->vtable = 0x820AEE3Cu;
	ctx.r1.u64 = stack;
	// 16-byte list head node: both link words start out pointing at the node itself
	uint32_t listHead = operator_new(ctx, base, 16);
	if (listHead != 0) {
		STORE32(listHead, listHead);
	}
	uint32_t listHeadSecondLink = listHead + 4;
	if (listHeadSecondLink != 0) {
		STORE32(listHeadSecondLink, listHead);
	}
	guiOptionsAudioScreen->m_C = listHead;
	guiOptionsAudioScreen->m_10 = 0;
	guiOptionsAudioScreen->m_14 = 0;
	guiOptionsAudioScreen->m_18 = uint8_t(0);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// callers read the carry of the listHead + 4 address add
	ctx.xer.ca = listHead > 0xFFFFFFFBu;
	return guiOptionsAudioScreenAddr;
}
PROMOTED_ENTRY(57, sub_828338A8, 0x828338A8) { ctx.r3.u64 = CGuiOptionsAudioScreen_Constructor(ctx, base, ctx.r3.u32); }

uint32_t CGuiOptionsAudioScreen_Construct(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr) {
	if (!UseLiftedCode(63, 0x828DA1B8)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; __imp__sub_828DA1B8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828DA1B8);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	uint32_t stack = ctx.r1.u64;
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	CGuiOptionsAudioScreen_Constructor(ctx, base, guiOptionsAudioScreenAddr);

	uint64_t itemListAddr = guiOptionsAudioScreenAddr + 28;
	guiOptionsAudioScreen->vtable = 0x820E4768u;
	RbTree_InitEmptyNode28(ctx, base, itemListAddr);

	// initial field values read out of read-only constants
	ctx.fpscr.disableFlushMode();
	double initial40 = double(LOAD_F32(0x820994B4));
	double initial4C = double(LOAD_F32(0x8209B674));
	double initial54 = double(LOAD_F32(0x8209F48C));

	guiOptionsAudioScreen->m_SelectedItem = 0xFFFFFFFFu;
	guiOptionsAudioScreen->m_3C = 0;
	guiOptionsAudioScreen->m_40 = float(initial40);
	guiOptionsAudioScreen->m_44 = float(initial40);
	guiOptionsAudioScreen->m_48 = 0;
	guiOptionsAudioScreen->m_49 = 0;
	guiOptionsAudioScreen->m_4C = float(initial4C);
	guiOptionsAudioScreen->m_50 = float(initial4C);
	guiOptionsAudioScreen->m_54 = float(initial54);
	guiOptionsAudioScreen->m_58 = float(initial54);
	guiOptionsAudioScreen->m_5C = 0;
	guiOptionsAudioScreen->m_5D = 1;
	guiOptionsAudioScreen->m_60 = 1;
	guiOptionsAudioScreen->m_64 = 0;
	guiOptionsAudioScreen->m_68 = 0;

	// state the callees may pass on
	ctx.r8.s64 = g_820A0000;

	// build one menu entry and append it to the screen's item list
	auto addMenuEntry = [&](uint32_t (*entryConstructor)(CpuState&, uint8_t*, uint64_t),
	                        uint32_t entrySize, uint32_t index) {
		uint64_t entryMemory = operator_new(ctx, base, entrySize);
		uint32_t entry = 0;
		if ((uint32_t)entryMemory != 0) entry = entryConstructor(ctx, base, entryMemory);
		STORE32(stack + 80, entry);
		uint64_t entryRef;
		if (entry != 0) {
			entryRef = CGuiOptionsMenu_CreateCallback(ctx, base, stack + 80);
		} else {
			entryRef = stack + 80;
			STORE32(stack + 84, 0);
		}
		n_sub_8247BDD0(ctx, base, itemListAddr, entryRef, index);
	};

	addMenuEntry(n_sub_82885D68, 56, 0);
	addMenuEntry(n_sub_82885D68, 56, 1);
	addMenuEntry(n_sub_82885D68, 56, 2);
	addMenuEntry(n_sub_82886070, 64, 3);

	uint32_t result = (uint32_t)guiOptionsAudioScreenAddr;
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DA1B8, 0x828DA1B8) { ctx.r3.u64 = CGuiOptionsAudioScreen_Construct(ctx, base, ctx.r3.u64); }

uint64_t CGuiOptionsAudioScreen_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(63, 0x828DA380)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_828DA380(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DA380);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	n_sub_825828F8(ctx, base, object);
	if ((deleteFlags & 1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	return object;
}
PROMOTED_ENTRY(63, sub_828DA380, 0x828DA380) { ctx.r3.u64 = CGuiOptionsAudioScreen_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGuiOptionsAudioScreen_Setup(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr) {
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t str_TXT_820E468C_B_ = int32_t(0x820E468C);
	constexpr int32_t str_TXT_820E46A8_B_ = int32_t(0x820E46A8);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	constexpr uint64_t g_8349CC94 = uint64_t(int64_t(-2092315500));
	constexpr uint64_t g_8349CC98 = uint64_t(int64_t(-2092315496));
	constexpr uint64_t g_8349CC9C = uint64_t(int64_t(-2092315492));
	constexpr uint64_t g_8349CCA0 = uint64_t(int64_t(-2092315488));
	if (!UseLiftedCode(63, 0x828DA3D0)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; __imp__sub_828DA3D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DA3D0);
	uint32_t stack = ctx.r1.u64;
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 176);

	uint32_t audioSettings = LOAD32(LOAD32(uint32_t(g_83490000) + 26912) + 12);
	uint32_t flagSource = LOAD32(audioSettings + 140);
	bool bothFlagsSet = LOAD8(flagSource + 52) != 0 && LOAD8(flagSource + 53) != 0;
	uint32_t sortedArray = LOAD32(audioSettings + 156);
	ctx.r1.u64 = stack;
	uint32_t foundValue = SortedArray_FindValueByKey(ctx, base, sortedArray, bothFlagsSet ? 1 : 2);

	// fills stack+96..104 with the three volumes and stack+108 with the output mode
	uint32_t settingsArg = LOAD32(audioSettings + 148);
	uint32_t foundArg = LOAD32(foundValue + 40);
	n_sub_824E6D28(ctx, base, stack + 96, settingsArg, foundArg);

	ctx.fpscr.disableFlushMode();
	float loadedMusicVolume = LOAD_F32(stack + 100);
	float loadedVoiceVolume = LOAD_F32(stack + 104);
	guiOptionsAudioScreen->m_SoundVolume = LOAD_F32(stack + 96);
	guiOptionsAudioScreen->m_MusicVolume = loadedMusicVolume;
	guiOptionsAudioScreen->m_AudioOutputMode = LOAD32(stack + 108);
	guiOptionsAudioScreen->m_VoiceVolume = loadedVoiceVolume;

	uint32_t pageOwner = LOAD32(LOAD32(uint32_t(g_83490000) + 26788) + 56);
	uint32_t page = LOAD32(pageOwner + 152);

	// labels of the three volume items: CCharString temporaries turned into LocalisedText
	uint64_t soundsKey = str_TXT_820E468C_B_;
	uint64_t musicKey = str_TXT_820E46A8_B_;
	uint64_t voiceKey = int64_t(g_820E0000) + 18116;

	// state the callee may pass on
	uint64_t soundsString = CCharString_ConstructFromCStr(ctx, base, stack + 84, soundsKey, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 88, soundsString);
	uint64_t musicString = CCharString_ConstructFromCStr(ctx, base, stack + 80, musicKey, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 84, musicString);
	ctx.r6.s64 = g_820E0000;  // state the callee may pass on
	uint64_t voiceString = CCharString_ConstructFromCStr(ctx, base, stack + 96, voiceKey, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 80, voiceString);

	// set up the three volume items (entries 0-2 of the item list) with their label and stored volume
	uint64_t itemListAddr = guiOptionsAudioScreenAddr + 28;

	ctx.fpscr.disableFlushMode();
	double soundVolume = double(guiOptionsAudioScreen->m_SoundVolume);
	uint64_t soundEntryHandle = n_sub_828D9FE8(ctx, base, stack + 96, itemListAddr, 0);
	ctx.fpscr.disableFlushMode();
	ctx.r3.u64 = (uint32_t)guiOptionsAudioScreenAddr;  // state the callee may pass on
	n_sub_828DA770(ctx, base, soundEntryHandle, page, g_8349CC94, stack + 88, soundVolume);

	ctx.fpscr.disableFlushMode();
	double musicVolume = double(guiOptionsAudioScreen->m_MusicVolume);
	uint64_t musicEntryHandle = n_sub_828D9FE8(ctx, base, stack + 96, itemListAddr, 1);
	ctx.fpscr.disableFlushMode();
	ctx.r3.u64 = (uint32_t)guiOptionsAudioScreenAddr;  // state the callee may pass on
	n_sub_828DA770(ctx, base, musicEntryHandle, page, g_8349CC98, stack + 84, musicVolume);

	ctx.fpscr.disableFlushMode();
	double voiceVolume = double(guiOptionsAudioScreen->m_VoiceVolume);
	uint64_t voiceEntryHandle = n_sub_828D9FE8(ctx, base, stack + 96, itemListAddr, 2);
	ctx.fpscr.disableFlushMode();
	ctx.r3.u64 = (uint32_t)guiOptionsAudioScreenAddr;  // state the callee may pass on
	n_sub_828DA770(ctx, base, voiceEntryHandle, page, g_8349CC9C, stack + 80, voiceVolume);

	uint64_t outputEntryHandle = n_sub_828D9FE8(ctx, base, stack + 96, itemListAddr, 3);
	ctx.r6.u64 = g_8349CCA0;  // state the callee may pass on
	CGuiOptionsAudioScreen_SetupOutputChoices(ctx, base, guiOptionsAudioScreenAddr, outputEntryHandle, page);

	CGuiOptionsAudioScreen_SelectItem(ctx, base, guiOptionsAudioScreenAddr, 0);

	ctx.fpscr.disableFlushMode();
	guiOptionsAudioScreen->m_58 = LOAD_F32(0x8209B650u);
	guiOptionsAudioScreen->m_50 = LOAD_F32(0x8209DE38u);

	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 80);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 84);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 88);

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DA3D0, 0x828DA3D0) { ctx.r3.u64 = CGuiOptionsAudioScreen_Setup(ctx, base, ctx.r3.u64); }

uint32_t CGuiOptionsAudioScreen_SelectItem(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr, uint32_t selectedIndex) {
	if (!UseLiftedCode(63, 0x828DA600)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; ctx.r4.u64 = selectedIndex; __imp__sub_828DA600(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828DA600);
	uint32_t stack = ctx.r1.u64;
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);

	stack = PushStackFrame(base, stack, 128);
	uint64_t itemListAddr = guiOptionsAudioScreenAddr + 28;
	ctx.r1.u64 = stack;
	n_sub_828D8FF0(ctx, base, itemListAddr, selectedIndex);

	// look the selected entry up twice; each lookup fills the handle at entryHandleAddr
	uint32_t entryHandleAddr = stack + 80;
	n_sub_828D9FE8(ctx, base, entryHandleAddr, itemListAddr, guiOptionsAudioScreen->m_SelectedItem);
	ctx.fpscr.disableFlushMode();
	float entryValue = LOAD_F32(LOAD32(entryHandleAddr) + 16);
	float lowerBound = LOAD_F32(0x820994B4u);
	if (!(entryValue < lowerBound)) {
		guiOptionsAudioScreen->m_4C = entryValue;
	}
	SharedHandle_Release(ctx, base, entryHandleAddr);

	n_sub_828D9FE8(ctx, base, entryHandleAddr, itemListAddr, guiOptionsAudioScreen->m_SelectedItem);
	ctx.fpscr.disableFlushMode();
	entryValue = LOAD_F32(LOAD32(entryHandleAddr) + 20);
	if (!(entryValue < lowerBound)) {
		guiOptionsAudioScreen->m_54 = entryValue;
	}
	uint32_t result = SharedHandle_Release(ctx, base, entryHandleAddr);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DA600, 0x828DA600) { ctx.r3.u64 = CGuiOptionsAudioScreen_SelectItem(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t n_sub_828DA6A8(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr) {
	if (!UseLiftedCode(63, 0x828DA6A8)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; __imp__sub_828DA6A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DA6A8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t positionAddr = (uint32_t)guiOptionsAudioScreenAddr + 60;
	ctx.r1.u64 = stack;
	CThing_ValidatePositionAndReset(ctx, base, positionAddr);

	// m_64/m_68 form an owned pointer (OwnedPtr_Reset releases m_68 and clears both); the object is
	// dropped when its virtual at +16 returns zero
	uint32_t ownedPtrAddr = (uint32_t)guiOptionsAudioScreenAddr + 100;
	uint64_t result = guiOptionsAudioScreen->m_64;
	if ((uint32_t)result != 0) {
		uint32_t ownedObject = (uint32_t)result;
		uint32_t keepCheckFunc = LOAD32(LOAD32(ownedObject) + 16);
		callTarget.u64 = keepCheckFunc;
		ctx.r3.u64 = ownedObject;
		ctx.r8.u64 = guiOptionsAudioScreenAddr;
		ctx.r10.u64 = keepCheckFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		if (((uint32_t)result & 0xFF) == 0) {
			ownedObject = guiOptionsAudioScreen->m_64;
			uint32_t teardownFunc = LOAD32(LOAD32(ownedObject) + 28);
			callTarget.u64 = teardownFunc;
			ctx.r3.u64 = ownedObject;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			result = OwnedPtr_Reset(ctx, base, ownedPtrAddr);
		}
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DA6A8, 0x828DA6A8) { ctx.r3.u64 = n_sub_828DA6A8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_828DA720(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr) {
	if (!UseLiftedCode(63, 0x828DA720)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; __imp__sub_828DA720(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DA720);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 96);
	// m_64/m_68 form an owned pointer; OwnedPtr_Reset releases m_68 and clears both words
	uint32_t ownedPtrAddr = (uint32_t)guiOptionsAudioScreenAddr + 100;
	uint32_t ownedObject = guiOptionsAudioScreen->m_64;
	uint64_t result = ownedObject;
	if (ownedObject != 0) {
		uint32_t teardownFunc = LOAD32(LOAD32(ownedObject) + 28);
		callTarget.u64 = teardownFunc;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = ownedObject;
		ctx.r10.u64 = teardownFunc;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = OwnedPtr_Reset(ctx, base, ownedPtrAddr);
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DA720, 0x828DA720) { ctx.r3.u64 = n_sub_828DA720(ctx, base, ctx.r3.u64); }

uint32_t n_sub_828DA770(CpuState& ctx, uint8_t* base, uint64_t entryHandleAddr, uint64_t page, uint64_t controlName, uint64_t labelText, double volume) {
	if (!UseLiftedCode(63, 0x828DA770)) { ctx.r4.u64 = entryHandleAddr; ctx.r5.u64 = page; ctx.r6.u64 = controlName; ctx.r7.u64 = labelText; ctx.f1.f64 = volume; __imp__sub_828DA770(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828DA770);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	// the handle's first word is the entry object; call the first function of the entry's vtable
	uint32_t entry = LOAD32((uint32_t)entryHandleAddr);
	PPCRegister callTarget{};
	callTarget.u64 = LOAD32(LOAD32(entry));
	ctx.r1.u64 = stack;
	ctx.r3.u64 = entry;
	ctx.r4.u64 = page;
	ctx.r5.u64 = controlName;
	ctx.r6.u64 = controlName;
	ctx.r7.u64 = labelText;
	ctx.r10.u64 = callTarget.u64;
	ctx.f1.f64 = volume;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	if ((ctx.r3.u32 & 0xFF) != 0) {
		n_sub_82886008(ctx, base, entry, labelText);
		ctx.fpscr.disableFlushMode();
		n_sub_82885F50(ctx, base, entry, volume);
		SharedHandle_Release(ctx, base, entryHandleAddr);
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return 1;
	}
	SharedHandle_Release(ctx, base, entryHandleAddr);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(63, sub_828DA770, 0x828DA770) { ctx.r3.u64 = n_sub_828DA770(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.f1.f64); }

// Builds the TV / hi-fi / surround choices of the item held by the shared handle at itemHandleAddr,
// passes the screen's output mode to it and releases the handle. Returns 1 when the choices were built.
uint32_t CGuiOptionsAudioScreen_SetupOutputChoices(CpuState& ctx, uint8_t* base, uint32_t guiOptionsAudioScreenAddr, uint64_t itemHandleAddr, uint64_t audioOptionsPage) {
	constexpr int32_t str_TXT_820E46E0_B_ = int32_t(0x820E46E0);
	constexpr int32_t str_TXT_820E46FC_B_ = int32_t(0x820E46FC);
	constexpr int32_t str_TXT_820E471C_B_ = int32_t(0x820E471C);
	constexpr int32_t TXT_8349CCA0_G_ = int32_t(0x8349CCA0);
	if (!UseLiftedCode(63, 0x828DA800)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; ctx.r4.u64 = itemHandleAddr; ctx.r5.u64 = audioOptionsPage; __imp__sub_828DA800(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828DA800);
	uint32_t stack = ctx.r1.u64;

	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);
	stack = PushStackFrame(base, stack, 144);

	// The item's first virtual function decides (low byte of its result) whether the choices are built.
	uint32_t item = LOAD32((uint32_t)itemHandleAddr);
	uint32_t itemVtable = LOAD32(item);
	uint32_t firstMethod = LOAD32(itemVtable);
	PPCRegister callTarget{};
	callTarget.u64 = firstMethod;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = item;
	ctx.r4.u64 = audioOptionsPage;
	ctx.r5.u64 = TXT_8349CCA0_G_;
	ctx.r9.u64 = firstMethod;
	ctx.r10.u64 = itemVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t shouldBuildChoices = ctx.r3.u32 & 0xFF;
	// state the callees may pass on (both paths)
	ctx.r8.u64 = shouldBuildChoices;
	if (shouldBuildChoices == 0) {
		SharedHandle_Release(ctx, base, itemHandleAddr);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return 0;
	}

	// Each key goes into a stack CCharString temporary from which a LocalisedText is built.
	uint64_t tvCharString = CCharString_ConstructFromCStr(ctx, base, stack + 84, str_TXT_820E46E0_B_, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 88, tvCharString);
	uint64_t hifiCharString = CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820E46FC_B_, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 84, hifiCharString);
	uint64_t surroundCharString = CCharString_ConstructFromCStr(ctx, base, stack + 92, str_TXT_820E471C_B_, -1);
	LocalisedText_InitFromKey(ctx, base, stack + 80, surroundCharString);

	uint64_t choiceListAddr = (uint64_t)item + 44;
	n_sub_82356488(ctx, base, choiceListAddr, stack + 88);
	n_sub_82356488(ctx, base, choiceListAddr, stack + 84);
	n_sub_82356488(ctx, base, choiceListAddr, stack + 80);

	uint32_t audioOutputMode = guiOptionsAudioScreen->m_AudioOutputMode;
	n_sub_828862E8(ctx, base, item, audioOutputMode);

	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 80);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 84);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, stack + 88);
	SharedHandle_Release(ctx, base, itemHandleAddr);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return 1;
}
PROMOTED_ENTRY(63, sub_828DA800, 0x828DA800) { ctx.r3.u64 = CGuiOptionsAudioScreen_SetupOutputChoices(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

// The output mode arrives in r7. Every callee gets the audio manager singleton in r3, as in the original.
uint64_t CGuiOptionsAudioScreen_SetAudioVolumes(CpuState& ctx, uint8_t* base, uint64_t audioOutputMode, double soundVolume, double musicVolume, double voiceVolume) {
	if (!UseLiftedCode(63, 0x828DAA78)) { ctx.r7.u64 = audioOutputMode; ctx.f1.f64 = soundVolume; ctx.f2.f64 = musicVolume; ctx.f3.f64 = voiceVolume; __imp__sub_828DAA78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DAA78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	const uint32_t audioManager = LOAD32(0x83496BCCu);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r3.u64 = audioManager;
	ctx.r7.u64 = audioOutputMode;
	ctx.f2.f64 = musicVolume;
	ctx.f3.f64 = voiceVolume;
	n_sub_829F88B0(ctx, base, soundVolume);

	ctx.fpscr.disableFlushMode();
	ctx.r3.u64 = audioManager;
	n_sub_829F8AC0(ctx, base, musicVolume);

	ctx.fpscr.disableFlushMode();
	n_sub_829F8948(ctx, base, audioManager, voiceVolume);

	ctx.r3.u64 = audioManager;
	uint64_t result = n_sub_829F8B58(ctx, base, audioOutputMode);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DAA78, 0x828DAA78) { ctx.r3.u64 = CGuiOptionsAudioScreen_SetAudioVolumes(ctx, base, ctx.r7.u64, ctx.f1.f64, ctx.f2.f64, ctx.f3.f64); }

uint64_t CGuiOptionsAudioScreen_HandleInput(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr, uint64_t inputCode, uint32_t controllerIndex) {
	constexpr int32_t TXT_83498778_G_ = int32_t(0x83498778);
	constexpr int32_t TXT_8349877C_G_ = int32_t(0x8349877C);
	if (!UseLiftedCode(63, 0x828DAAF8)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; ctx.r4.u64 = inputCode; ctx.r5.u64 = controllerIndex; __imp__sub_828DAAF8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DAAF8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGuiOptionsAudioScreen* guiOptionsAudioScreen = GameObject<CGuiOptionsAudioScreen>(base, guiOptionsAudioScreenAddr);

	stack = PushStackFrame(base, stack, 144);
	guiOptionsAudioScreen->m_60 = controllerIndex;
	ctx.r1.u64 = stack;
	uint64_t inputAction = n_sub_82841730(ctx, base, guiOptionsAudioScreenAddr + 60, inputCode);

	uint32_t actionIndex = (uint32_t)inputAction - 28;
	if (actionIndex <= 9) {
		// The original switch jumps through a table (0x828DAB3C); r0 still holds its entry at each call.
		constexpr uint32_t actionJumpTable = 0x828E0000u - 21700;
		const uint32_t jumpTableEntry = LOAD32(actionJumpTable + (actionIndex << 2));
		switch (actionIndex) {
		case 0: {
			int32_t selectedItem = guiOptionsAudioScreen->m_SelectedItem;
			if (selectedItem <= 0) break;
			ctx.r0.u64 = jumpTableEntry;
			CGuiOptionsAudioScreen_SelectItem(ctx, base, guiOptionsAudioScreenAddr, (uint32_t)(selectedItem - 1));
			uint64_t selectionSound = TXT_83498778_G_;
			n_sub_82306098(ctx, base, stack + 80, LOAD32(0x834968A4u), selectionSound);
			uint64_t resetResult = OwnedPtr_Reset(ctx, base, stack + 80);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return resetResult;
		}
		case 1: {
			int32_t selectedItem = guiOptionsAudioScreen->m_SelectedItem;
			if (selectedItem >= 3) break;
			ctx.r0.u64 = jumpTableEntry;
			CGuiOptionsAudioScreen_SelectItem(ctx, base, guiOptionsAudioScreenAddr, (uint32_t)(selectedItem + 1));
			uint64_t selectionSound = TXT_8349877C_G_;
			n_sub_82306098(ctx, base, stack + 88, LOAD32(0x834968A4u), selectionSound);
			uint64_t resetResult = OwnedPtr_Reset(ctx, base, stack + 88);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return resetResult;
		}
		case 2:
		case 3: {
			// Hand the action to the selected item (vtable slot 2), then re-apply the volumes.
			uint32_t selectedItem = guiOptionsAudioScreen->m_SelectedItem;
			ctx.r0.u64 = jumpTableEntry;
			uint64_t itemHandleAddr = n_sub_828D9FE8(ctx, base, stack + 96, guiOptionsAudioScreenAddr + 28, selectedItem);
			uint32_t item = LOAD32((uint32_t)itemHandleAddr);
			uint32_t itemVtable = LOAD32(item);
			uint32_t method = LOAD32(itemVtable + 8);
			callTarget.u64 = method;
			ctx.r3.u64 = item;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			SharedHandle_Release(ctx, base, stack + 96);
			CGuiOptionsAudioScreen_ApplyVolumes(ctx, base, guiOptionsAudioScreenAddr, 0);
			uint64_t result = n_sub_828DAC88(ctx, base, guiOptionsAudioScreenAddr, selectedItem);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return result;
		}
		case 8: {
			ctx.r0.u64 = jumpTableEntry;
			uint64_t result = CGuiOptionsAudioScreen_ApplyVolumes(ctx, base, guiOptionsAudioScreenAddr, 1);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return result;
		}
		case 9: {
			uint32_t audioOutputMode = guiOptionsAudioScreen->m_AudioOutputMode;
			ctx.fpscr.disableFlushMode();
			double voiceVolume = double(guiOptionsAudioScreen->m_VoiceVolume);
			double musicVolume = double(guiOptionsAudioScreen->m_MusicVolume);
			double soundVolume = double(guiOptionsAudioScreen->m_SoundVolume);
			// state the callee may pass on
			ctx.r0.u64 = jumpTableEntry;
			CGuiOptionsAudioScreen_SetAudioVolumes(ctx, base, audioOutputMode, soundVolume, musicVolume, voiceVolume);
			uint32_t method = LOAD32((uint32_t)guiOptionsAudioScreen->vtable + 4);
			callTarget.u64 = method;
			ctx.r3.u64 = guiOptionsAudioScreenAddr;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			stack = PopStackFrame(stack, 144);
			ctx.r1.u64 = stack;
			return ctx.r3.u64;
		}
		}
	}

	// Actions without a handler (including indices 4-7) return the action code.
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return inputAction;
}
PROMOTED_ENTRY(63, sub_828DAAF8, 0x828DAAF8) { ctx.r3.u64 = CGuiOptionsAudioScreen_HandleInput(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

// Unless the sound held in m_64 handles the item index (its vtable slot 4), item 0 creates the
// SE_GUI_EAT_ITEM sound and item 2 the one named by a text key; the new sound replaces m_64.
uint64_t n_sub_828DAC88(CpuState& ctx, uint8_t* base, uint64_t guiOptionsAudioScreenAddr, uint64_t itemIndex) {
	constexpr int32_t str_TXT_820E4740_B_ = int32_t(0x820E4740);
	constexpr int32_t TXT_8349875C_G_ = int32_t(0x8349875C);
	if (!UseLiftedCode(63, 0x828DAC88)) { ctx.r3.u64 = guiOptionsAudioScreenAddr; ctx.r4.u64 = itemIndex; __imp__sub_828DAC88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828DAC88);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	stack = PushStackFrame(base, stack, 128);

	const uint32_t soundSlotAddr = (uint32_t)guiOptionsAudioScreenAddr + 100;
	const uint32_t currentSound = LOAD32(soundSlotAddr);
	const int32_t item = (int32_t)(uint32_t)itemIndex;

	uint64_t result = currentSound;
	bool handled = false;
	if (currentSound != 0) {
		uint32_t method = LOAD32(LOAD32(currentSound) + 16);
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = currentSound;
		ctx.r4.u64 = itemIndex;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		result = ctx.r3.u64;
		handled = ((uint32_t)result & 0xFF) != 0;
	}

	if (!handled) {
		if (item == 0) {
			uint64_t eatItemSound = TXT_8349875C_G_;
			uint64_t newSoundSlot = (uint64_t)stack + 96;
			uint32_t soundSource = LOAD32(0x834968A4u);
			ctx.r1.u64 = stack;
			uint64_t newSound = n_sub_82306098(ctx, base, newSoundSlot, soundSource, eatItemSound);
			RefPtr_Assign(ctx, base, soundSlotAddr, newSound);
			result = OwnedPtr_Reset(ctx, base, newSoundSlot);
		} else if (item == 2) {
			uint64_t soundKey = (uint64_t)stack + 80;
			ctx.r1.u64 = stack;
			CCharString_ConstructFromCStr(ctx, base, soundKey, str_TXT_820E4740_B_, -1);
			uint64_t newSoundSlot = (uint64_t)stack + 88;
			uint32_t soundSource = LOAD32(0x834968A4u);
			uint64_t newSound = n_sub_82306098(ctx, base, newSoundSlot, soundSource, soundKey);
			RefPtr_Assign(ctx, base, soundSlotAddr, newSound);
			OwnedPtr_Reset(ctx, base, newSoundSlot);
			result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, soundKey);
		}
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(63, sub_828DAC88, 0x828DAC88) { ctx.r3.u64 = n_sub_828DAC88(ctx, base, ctx.r3.u64, ctx.r4.u64); }
