// CKeyCodeNameTable (vtable 0x820E3958): methods of the class as readable C++.
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

uint32_t CKeyCodeNameTable_Construct(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTableAddr) {
	if (!UseLiftedCode(62, 0x828D40A8)) { ctx.r3.u64 = keyCodeNameTableAddr; __imp__sub_828D40A8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D40A8);
	constexpr uint32_t CKeyCodeNameTable_vtable = 0x820E3958u;
	constexpr uint32_t sharedCountAddress = 0x83496EB4u;
	CKeyCodeNameTable* keyCodeNameTable = GameObject<CKeyCodeNameTable>(base, keyCodeNameTableAddr);
	GameStackFrame stackFrame(ctx, base, 96);

	CGuiOptionsAudioScreen_Constructor(ctx, base, keyCodeNameTableAddr);
	keyCodeNameTable->vtable = CKeyCodeNameTable_vtable;

	// the head node of the key-code tree (28 bytes): the left, parent and right links, a colour byte and an
	// is-nil byte; each link is constructed in place, which skips a null address
	const uint32_t headNode = operator_new(ctx, base, 28);
	const uint32_t headLeft = headNode;
	const uint32_t headParent = headNode + 4;
	const uint32_t headRight = headNode + 8;
	const uint32_t headColour = headNode + 24;
	const uint32_t headIsNil = headNode + 25;
	for (uint32_t link : {headLeft, headParent, headRight}) {
		if (link != 0) {
			STORE32(link, 0);
		}
	}
	STORE8(headIsNil, 0);
	STORE8(headColour, 1);
	keyCodeNameTable->m_treeHead = headNode;
	STORE8(headIsNil, 1);
	// an empty tree: every link of the head node points back at it
	STORE32(headParent, headNode);
	STORE32(headLeft, headNode);
	STORE32(headRight, headNode);
	keyCodeNameTable->m_24 = 0;
	keyCodeNameTable->m_count = 0;

	// the shared count at 0x83496EB4 goes up by one, atomically as in the original (a reserved load and a
	// conditional store under the global lock, with the msr bits it sets around them);
	// CBufferedInputStream_ReadWideString makes the same increment after zeroing its string member
	const uint32_t msrForUpdate = uint32_t(ctx.r13.u64);
	uint32_t* sharedCount = reinterpret_cast<uint32_t*>(RAW(sharedCountAddress));
	bool stored = false;
	do {
		std::atomic_thread_fence(std::memory_order_seq_cst);
		const uint64_t savedMsr = REX_CHECK_GLOBAL_LOCK();
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = msrForUpdate & 0x8020 | ctx.msr & ~0x8020;
		REX_ENTER_GLOBAL_LOCK();
		ctx.reserved.u32 = *sharedCount;
		const uint32_t newCount = __builtin_bswap32(ctx.reserved.u32) + 1;
		stored = __sync_bool_compare_and_swap(sharedCount, ctx.reserved.u32, __builtin_bswap32(newCount));
		std::atomic_thread_fence(std::memory_order_seq_cst);
		ctx.msr = uint32_t(savedMsr) & 0x8020 | ctx.msr & ~0x8020;
		REX_LEAVE_GLOBAL_LOCK();
	} while (!stored);

	CKeyCodeNameTable_AddCombatKeyNames(ctx, base, keyCodeNameTableAddr);
	CKeyCodeNameTable_AddKillsKeyNames(ctx, base, keyCodeNameTableAddr);
	n_sub_828D4A48(ctx, base, keyCodeNameTableAddr);
	CKeyCodeNameTable_AddAdventureKeyNames(ctx, base, keyCodeNameTableAddr);
	CKeyCodeNameTable_AddGamesKeyNames(ctx, base, keyCodeNameTableAddr);
	n_sub_828D5128(ctx, base, keyCodeNameTableAddr);
	CKeyCodeNameTable_AddCrimeKeyNames(ctx, base, keyCodeNameTableAddr);
	CKeyCodeNameTable_AddOtherKeyNames(ctx, base, keyCodeNameTableAddr);
	return uint32_t(keyCodeNameTableAddr);
}
PROMOTED_ENTRY(62, sub_828D40A8, 0x828D40A8) { ctx.r3.u64 = CKeyCodeNameTable_Construct(ctx, base, ctx.r3.u64); }

uint64_t CKeyCodeNameTable_ScalarDeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable, uint64_t deleteFlags) {
	if (!UseLiftedCode(62, 0x828D41B0)) { ctx.r3.u64 = keyCodeNameTable; ctx.r4.u64 = deleteFlags; __imp__sub_828D41B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x828D41B0);
	GameStackFrame stackFrame(ctx, base, 112);
	CGuiScrollList_DestructorWithMap(ctx, base, keyCodeNameTable);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, keyCodeNameTable);
	}
	return keyCodeNameTable;
}
PROMOTED_ENTRY(62, sub_828D41B0, 0x828D41B0) { ctx.r3.u64 = CKeyCodeNameTable_ScalarDeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CKeyCodeNameTable_AddCombatKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D4500)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D4500(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D4500);
	constexpr int32_t TXT_8349C72C_G_ = int32_t(0x8349C72C);
	constexpr int32_t TXT_8349C74C_G_ = int32_t(0x8349C74C);
	constexpr int32_t TXT_8349C750_G_ = int32_t(0x8349C750);
	constexpr int32_t TXT_8349C754_G_ = int32_t(0x8349C754);
	constexpr int32_t TXT_8349C758_G_ = int32_t(0x8349C758);
	constexpr int32_t TXT_8349C75C_G_ = int32_t(0x8349C75C);
	constexpr int32_t TXT_8349C760_G_ = int32_t(0x8349C760);
	constexpr int32_t TXT_8349C764_G_ = int32_t(0x8349C764);
	constexpr int32_t TXT_8349C768_G_ = int32_t(0x8349C768);
	constexpr int32_t TXT_8349C76C_G_ = int32_t(0x8349C76C);
	constexpr int32_t TXT_8349C770_G_ = int32_t(0x8349C770);
	constexpr int32_t TXT_8349C774_G_ = int32_t(0x8349C774);
	constexpr int32_t TXT_8349C778_G_ = int32_t(0x8349C778);
	constexpr int32_t TXT_8349C77C_G_ = int32_t(0x8349C77C);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{2, TXT_8349C74C_G_},
		{3, TXT_8349C750_G_},
		{4, TXT_8349C754_G_},
		{5, TXT_8349C758_G_},
		{6, TXT_8349C75C_G_},
		{7, TXT_8349C760_G_},
		{8, TXT_8349C764_G_},
		{9, TXT_8349C768_G_},
		{11, TXT_8349C76C_G_},
		{13, TXT_8349C770_G_},
		{14, TXT_8349C774_G_},
		{15, TXT_8349C778_G_},
		{16, TXT_8349C77C_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C72C_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D4500, 0x828D4500) { ctx.r3.u64 = CKeyCodeNameTable_AddCombatKeyNames(ctx, base, ctx.r3.u64); }

uint32_t CKeyCodeNameTable_AddKillsKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D4778)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D4778(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D4778);
	constexpr int32_t TXT_8349C730_G_ = int32_t(0x8349C730);
	constexpr int32_t TXT_8349C780_G_ = int32_t(0x8349C780);
	constexpr int32_t TXT_8349C784_G_ = int32_t(0x8349C784);
	constexpr int32_t TXT_8349C788_G_ = int32_t(0x8349C788);
	constexpr int32_t TXT_8349C78C_G_ = int32_t(0x8349C78C);
	constexpr int32_t TXT_8349C790_G_ = int32_t(0x8349C790);
	constexpr int32_t TXT_8349C794_G_ = int32_t(0x8349C794);
	constexpr int32_t TXT_8349C798_G_ = int32_t(0x8349C798);
	constexpr int32_t TXT_8349C79C_G_ = int32_t(0x8349C79C);
	constexpr int32_t TXT_8349C7A0_G_ = int32_t(0x8349C7A0);
	constexpr int32_t TXT_8349C7A4_G_ = int32_t(0x8349C7A4);
	constexpr int32_t TXT_8349C7A8_G_ = int32_t(0x8349C7A8);
	constexpr int32_t TXT_8349C7AC_G_ = int32_t(0x8349C7AC);
	constexpr int32_t TXT_8349C7B0_G_ = int32_t(0x8349C7B0);
	constexpr int32_t TXT_8349C7B4_G_ = int32_t(0x8349C7B4);
	constexpr int32_t TXT_8349C7B8_G_ = int32_t(0x8349C7B8);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{109, TXT_8349C780_G_},
		{122, TXT_8349C784_G_},
		{118, TXT_8349C788_G_},
		{121, TXT_8349C78C_G_},
		{113, TXT_8349C790_G_},
		{112, TXT_8349C794_G_},
		{117, TXT_8349C798_G_},
		{116, TXT_8349C79C_G_},
		{119, TXT_8349C7A0_G_},
		{120, TXT_8349C7A4_G_},
		{115, TXT_8349C7A8_G_},
		{114, TXT_8349C7AC_G_},
		{111, TXT_8349C7B0_G_},
		{110, TXT_8349C7B4_G_},
		{123, TXT_8349C7B8_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C730_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D4778, 0x828D4778) { ctx.r3.u64 = CKeyCodeNameTable_AddKillsKeyNames(ctx, base, ctx.r3.u64); }

uint32_t n_sub_828D4A48(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D4A48)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D4A48(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D4A48);
	constexpr int32_t TXT_8349C734_G_ = int32_t(0x8349C734);
	constexpr int32_t TXT_8349C7BC_G_ = int32_t(0x8349C7BC);
	constexpr int32_t TXT_8349C7C0_G_ = int32_t(0x8349C7C0);
	constexpr int32_t TXT_8349C7C4_G_ = int32_t(0x8349C7C4);
	constexpr int32_t TXT_8349C7C8_G_ = int32_t(0x8349C7C8);
	constexpr int32_t TXT_8349C7DC_G_ = int32_t(0x8349C7DC);
	constexpr int32_t TXT_8349C7CC_G_ = int32_t(0x8349C7CC);
	constexpr int32_t TXT_8349C7D0_G_ = int32_t(0x8349C7D0);
	constexpr int32_t TXT_8349C7D4_G_ = int32_t(0x8349C7D4);
	constexpr int32_t TXT_8349C7E0_G_ = int32_t(0x8349C7E0);
	constexpr int32_t TXT_8349C7E4_G_ = int32_t(0x8349C7E4);
	constexpr int32_t TXT_8349C7E8_G_ = int32_t(0x8349C7E8);
	constexpr int32_t TXT_8349C7EC_G_ = int32_t(0x8349C7EC);
	constexpr int32_t TXT_8349C7F0_G_ = int32_t(0x8349C7F0);
	constexpr int32_t TXT_8349C7F4_G_ = int32_t(0x8349C7F4);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{17, TXT_8349C7BC_G_},
		{18, TXT_8349C7C0_G_},
		{19, TXT_8349C7C4_G_},
		{20, TXT_8349C7C8_G_},
		{22, TXT_8349C7DC_G_},
		{23, TXT_8349C7CC_G_},
		{24, TXT_8349C7D0_G_},
		{25, TXT_8349C7D4_G_},
		{27, TXT_8349C7E0_G_},
		{28, TXT_8349C7E4_G_},
		{29, TXT_8349C7E8_G_},
		{30, TXT_8349C7EC_G_},
		{31, TXT_8349C7F0_G_},
		{32, TXT_8349C7F4_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C734_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D4A48, 0x828D4A48) { ctx.r3.u64 = n_sub_828D4A48(ctx, base, ctx.r3.u64); }

uint32_t CKeyCodeNameTable_AddAdventureKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D4CE8)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D4CE8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D4CE8);
	constexpr int32_t TXT_8349C738_G_ = int32_t(0x8349C738);
	constexpr int32_t TXT_8349C7F8_G_ = int32_t(0x8349C7F8);
	constexpr int32_t TXT_8349C7FC_G_ = int32_t(0x8349C7FC);
	constexpr int32_t TXT_8349C800_G_ = int32_t(0x8349C800);
	constexpr int32_t TXT_8349C804_G_ = int32_t(0x8349C804);
	constexpr int32_t TXT_8349C808_G_ = int32_t(0x8349C808);
	constexpr int32_t TXT_8349C80C_G_ = int32_t(0x8349C80C);
	constexpr int32_t TXT_8349C810_G_ = int32_t(0x8349C810);
	constexpr int32_t TXT_8349C814_G_ = int32_t(0x8349C814);
	constexpr int32_t TXT_8349C818_G_ = int32_t(0x8349C818);
	constexpr int32_t TXT_8349C81C_G_ = int32_t(0x8349C81C);
	constexpr int32_t TXT_8349C820_G_ = int32_t(0x8349C820);
	constexpr int32_t TXT_8349C824_G_ = int32_t(0x8349C824);
	constexpr int32_t TXT_8349C828_G_ = int32_t(0x8349C828);
	constexpr int32_t TXT_8349C82C_G_ = int32_t(0x8349C82C);
	constexpr int32_t TXT_8349C830_G_ = int32_t(0x8349C830);
	constexpr int32_t TXT_8349C834_G_ = int32_t(0x8349C834);
	constexpr int32_t TXT_8349C838_G_ = int32_t(0x8349C838);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{33, TXT_8349C7F8_G_},
		{106, TXT_8349C7FC_G_},
		{35, TXT_8349C800_G_},
		{36, TXT_8349C804_G_},
		{37, TXT_8349C808_G_},
		{38, TXT_8349C80C_G_},
		{39, TXT_8349C810_G_},
		{40, TXT_8349C814_G_},
		{41, TXT_8349C818_G_},
		{42, TXT_8349C81C_G_},
		{43, TXT_8349C820_G_},
		{44, TXT_8349C824_G_},
		{45, TXT_8349C828_G_},
		{46, TXT_8349C82C_G_},
		{47, TXT_8349C830_G_},
		{48, TXT_8349C834_G_},
		{49, TXT_8349C838_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C738_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D4CE8, 0x828D4CE8) { ctx.r3.u64 = CKeyCodeNameTable_AddAdventureKeyNames(ctx, base, ctx.r3.u64); }

uint32_t CKeyCodeNameTable_AddGamesKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D5010)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D5010(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D5010);
	constexpr int32_t TXT_8349C73C_G_ = int32_t(0x8349C73C);
	constexpr int32_t TXT_8349C83C_G_ = int32_t(0x8349C83C);
	constexpr int32_t TXT_8349C844_G_ = int32_t(0x8349C844);
	constexpr int32_t TXT_8349C848_G_ = int32_t(0x8349C848);
	constexpr int32_t TXT_8349C84C_G_ = int32_t(0x8349C84C);
	constexpr int32_t TXT_8349C840_G_ = int32_t(0x8349C840);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{50, TXT_8349C83C_G_},
		{96, TXT_8349C844_G_},
		{97, TXT_8349C848_G_},
		{98, TXT_8349C84C_G_},
		{83, TXT_8349C840_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C73C_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D5010, 0x828D5010) { ctx.r3.u64 = CKeyCodeNameTable_AddGamesKeyNames(ctx, base, ctx.r3.u64); }

uint32_t n_sub_828D5128(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D5128)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D5128(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D5128);
	constexpr int32_t TXT_8349C740_G_ = int32_t(0x8349C740);
	constexpr int32_t TXT_8349C850_G_ = int32_t(0x8349C850);
	constexpr int32_t TXT_8349C854_G_ = int32_t(0x8349C854);
	constexpr int32_t TXT_8349C858_G_ = int32_t(0x8349C858);
	constexpr int32_t TXT_8349C85C_G_ = int32_t(0x8349C85C);
	constexpr int32_t TXT_8349C860_G_ = int32_t(0x8349C860);
	constexpr int32_t TXT_8349C864_G_ = int32_t(0x8349C864);
	constexpr int32_t TXT_8349C868_G_ = int32_t(0x8349C868);
	constexpr int32_t TXT_8349C86C_G_ = int32_t(0x8349C86C);
	constexpr int32_t TXT_8349C870_G_ = int32_t(0x8349C870);
	constexpr int32_t TXT_8349C874_G_ = int32_t(0x8349C874);
	constexpr int32_t TXT_8349C878_G_ = int32_t(0x8349C878);
	constexpr int32_t TXT_8349C87C_G_ = int32_t(0x8349C87C);
	constexpr int32_t TXT_8349C880_G_ = int32_t(0x8349C880);
	constexpr int32_t TXT_8349C884_G_ = int32_t(0x8349C884);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{54, TXT_8349C850_G_},
		{55, TXT_8349C854_G_},
		{56, TXT_8349C858_G_},
		{57, TXT_8349C85C_G_},
		{58, TXT_8349C860_G_},
		{59, TXT_8349C864_G_},
		{60, TXT_8349C868_G_},
		{61, TXT_8349C86C_G_},
		{62, TXT_8349C870_G_},
		{63, TXT_8349C874_G_},
		{64, TXT_8349C878_G_},
		{65, TXT_8349C87C_G_},
		{66, TXT_8349C880_G_},
		{67, TXT_8349C884_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C740_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D5128, 0x828D5128) { ctx.r3.u64 = n_sub_828D5128(ctx, base, ctx.r3.u64); }

uint32_t CKeyCodeNameTable_AddCrimeKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D53C8)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D53C8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D53C8);
	constexpr int32_t TXT_8349C744_G_ = int32_t(0x8349C744);
	constexpr int32_t TXT_8349C888_G_ = int32_t(0x8349C888);
	constexpr int32_t TXT_8349C88C_G_ = int32_t(0x8349C88C);
	constexpr int32_t TXT_8349C890_G_ = int32_t(0x8349C890);
	constexpr int32_t TXT_8349C894_G_ = int32_t(0x8349C894);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{69, TXT_8349C888_G_},
		{70, TXT_8349C88C_G_},
		{71, TXT_8349C890_G_},
		{72, TXT_8349C894_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C744_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D53C8, 0x828D53C8) { ctx.r3.u64 = CKeyCodeNameTable_AddCrimeKeyNames(ctx, base, ctx.r3.u64); }

uint32_t CKeyCodeNameTable_AddOtherKeyNames(CpuState& ctx, uint8_t* base, uint64_t keyCodeNameTable) {
	if (!UseLiftedCode(62, 0x828D54B0)) { ctx.r3.u64 = keyCodeNameTable; __imp__sub_828D54B0(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x828D54B0);
	constexpr int32_t TXT_8349C748_G_ = int32_t(0x8349C748);
	constexpr int32_t TXT_8349C898_G_ = int32_t(0x8349C898);
	constexpr int32_t TXT_8349C89C_G_ = int32_t(0x8349C89C);
	constexpr int32_t TXT_8349C8A0_G_ = int32_t(0x8349C8A0);
	constexpr int32_t TXT_8349C8A4_G_ = int32_t(0x8349C8A4);
	constexpr int32_t TXT_8349C8A8_G_ = int32_t(0x8349C8A8);
	constexpr int32_t TXT_8349C8AC_G_ = int32_t(0x8349C8AC);
	constexpr int32_t TXT_8349C8B0_G_ = int32_t(0x8349C8B0);
	constexpr int32_t TXT_8349C8B4_G_ = int32_t(0x8349C8B4);
	constexpr int32_t TXT_8349C8B8_G_ = int32_t(0x8349C8B8);
	constexpr int32_t TXT_8349C8BC_G_ = int32_t(0x8349C8BC);
	constexpr int32_t TXT_8349C8C0_G_ = int32_t(0x8349C8C0);
	// each key code with the string global it is named by; the group string global above is the same for
	// every key this function adds
	struct KeyCodeName {
		uint32_t keyCode;
		int32_t name;
	};
	static constexpr KeyCodeName keyCodeNames[] = {
		{74, TXT_8349C898_G_},
		{75, TXT_8349C89C_G_},
		{76, TXT_8349C8A0_G_},
		{77, TXT_8349C8A4_G_},
		{78, TXT_8349C8A8_G_},
		{79, TXT_8349C8AC_G_},
		{80, TXT_8349C8B0_G_},
		{81, TXT_8349C8B4_G_},
		{0, TXT_8349C8B8_G_},
		{84, TXT_8349C8BC_G_},
		{1, TXT_8349C8C0_G_},
	};

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;
	// the key-code map at +0x1C (its head node is m_treeHead): n_sub_828D56D0 takes the address of a key code
	// and returns the address of that key's 8-byte value
	const uint64_t keyCodeMap = keyCodeNameTable + 28;
	// stack temporaries: the key code, whose address goes to the lookup, and the 8-byte value (the group's and
	// the key's string globals) copied into the entry, read back after the call
	const uint32_t keyCodeTemp = stack + 80;
	const uint32_t valueTemp = stack + 88;
	const uint32_t valueGroupTemp = stack + 88;
	const uint32_t valueNameTemp = stack + 92;
	uint32_t entryValue = 0;
	for (const KeyCodeName& keyCodeName : keyCodeNames) {
		STORE32(keyCodeTemp, keyCodeName.keyCode);
		STORE32(valueGroupTemp, uint32_t(TXT_8349C748_G_));
		STORE32(valueNameTemp, uint32_t(keyCodeName.name));
		entryValue = n_sub_828D56D0(ctx, base, keyCodeMap, keyCodeTemp);
		STORE64(entryValue, LOAD64(valueTemp));
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return entryValue;
}
PROMOTED_ENTRY(62, sub_828D54B0, 0x828D54B0) { ctx.r3.u64 = CKeyCodeNameTable_AddOtherKeyNames(ctx, base, ctx.r3.u64); }
