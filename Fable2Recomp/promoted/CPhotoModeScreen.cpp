// CPhotoModeScreen (vtable 0x820C02E8): methods of the class as readable C++.
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

// sub_82581460  [4 bytes]
uint64_t CPhotoModeScreen_ShowFailScreen(CpuState& ctx, uint8_t* base, uint64_t photoModeScreenAddr) {
	if (!UseLiftedCode(35, 0x82581460)) { ctx.r3.u64 = photoModeScreenAddr; __imp__sub_82581460(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82581460);
	return GUI_ShowPhotoModeFailScreen(ctx, base, photoModeScreenAddr);
}
PROMOTED_ENTRY(35, sub_82581460, 0x82581460) { ctx.r3.u64 = CPhotoModeScreen_ShowFailScreen(ctx, base, ctx.r3.u64); }

uint64_t CPhotoModeScreen_ShowDialog(CpuState& ctx, uint8_t* base, uint64_t dialogState) {
	constexpr uint32_t globalRootAddress = 0x834968A4;
	constexpr int32_t TXT_83498964_G_ = int32_t(0x83498964);
	if (!UseLiftedCode(35, 0x82581468)) { ctx.r4.u64 = dialogState; __imp__sub_82581468(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82581468);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 128);

	const uint32_t dialogNameAddr = stack + 80;
	const uint32_t dialogOwner = LOAD32(LOAD32(LOAD32(globalRootAddress) + 56) + 152);
	ctx.r1.u64 = stack;
	uint64_t dialogName = CCharString_CopyConstruct(ctx, base, dialogNameAddr, (uint64_t)(int64_t)TXT_83498964_G_);
	uint64_t dialog = Dialog_Create(ctx, base, dialogName, dialogOwner);
	if ((uint32_t)dialog != 0) {
		const uint32_t currentOwner = LOAD32(LOAD32(LOAD32(globalRootAddress) + 56) + 152);
		dialog = GuiElement_SetState(ctx, base, dialog, currentOwner, dialogState);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return dialog;
}
PROMOTED_ENTRY(35, sub_82581468, 0x82581468) { ctx.r3.u64 = CPhotoModeScreen_ShowDialog(ctx, base, ctx.r4.u64); }

uint64_t CPhotoModeScreen_IsActive_825814C8(CpuState& ctx, uint8_t* base, uint32_t photoModeScreenAddr) {
	if (!UseLiftedCode(35, 0x825814C8)) { ctx.r3.u64 = photoModeScreenAddr; __imp__sub_825814C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x825814C8);
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);
	uint32_t result = 0;
	if (photoModeScreen->m_1C != 0 || photoModeScreen->m_1D != 0) {
		result = 1;
	}
	return result;
}
PROMOTED_ENTRY(35, sub_825814C8, 0x825814C8) { ctx.r3.u64 = CPhotoModeScreen_IsActive_825814C8(ctx, base, ctx.r3.u32); }

uint64_t CPhotoModeScreen_Deactivate(CpuState& ctx, uint8_t* base, uint64_t photoModeScreenAddr) {
	if (!UseLiftedCode(35, 0x82581570)) { ctx.r3.u64 = photoModeScreenAddr; __imp__sub_82581570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82581570);
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);
	photoModeScreen->m_1C = uint8_t(0);
	return CPhotoModeScreen_ShowDialog(ctx, base, 5);
}
PROMOTED_ENTRY(35, sub_82581570, 0x82581570) { ctx.r3.u64 = CPhotoModeScreen_Deactivate(ctx, base, ctx.r3.u64); }

uint64_t CPhotoModeScreen_Activate(CpuState& ctx, uint8_t* base, uint64_t photoModeScreenAddr) {
	if (!UseLiftedCode(35, 0x82581580)) { ctx.r3.u64 = photoModeScreenAddr; __imp__sub_82581580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82581580);
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);
	if (photoModeScreen->m_1D != 0) return photoModeScreenAddr;
	photoModeScreen->m_1D = uint8_t(1);
	return CPhotoModeScreen_ShowDialog(ctx, base, 2);
}
PROMOTED_ENTRY(35, sub_82581580, 0x82581580) { ctx.r3.u64 = CPhotoModeScreen_Activate(ctx, base, ctx.r3.u64); }

double CPhotoModeScreen_UpdateLayout(CpuState& ctx, uint8_t* base, uint32_t layoutAddr, uint64_t photoModeScreenAddr) {
	constexpr uint32_t useWidescreenSizeAddress = 0x83360164;
	constexpr uint32_t widescreenSizeAddress = 0x833199AC;
	constexpr uint32_t standardSizeAddress = 0x833199B4;
	constexpr uint32_t minusOneAddress = 0x8209DE04;
	constexpr uint32_t horizontalScaleAddress = 0x821004B8;
	constexpr uint32_t verticalScaleAddress = 0x82000BCC;
	if (!UseLiftedCode(58, 0x82846598)) { ctx.r3.u64 = layoutAddr; ctx.r4.u64 = photoModeScreenAddr; __imp__sub_82846598(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x82846598);

	// A virtual method that returns a record by value: layoutAddr is the caller's record, photoModeScreenAddr the
	// screen whose vtable the call went through (GUI_ShowPhotoModeFailScreen calls slot 7 that way).
	const uint32_t screenAddr = uint32_t(photoModeScreenAddr);

	// The display size: the pair at widescreenSizeAddress (1280 x 720 in the image) when the word at
	// useWidescreenSizeAddress is set, otherwise the pair at standardSizeAddress (1024 x 768).
	const uint32_t displaySizeAddr = LOAD32(useWidescreenSizeAddress) != 0 ? widescreenSizeAddress : standardSizeAddress;
	const int32_t displayWidth = int32_t(LOAD32(displaySizeAddr));
	const int32_t displayHeight = int32_t(LOAD32(displaySizeAddr + 4));
	const uint8_t rectDisabled = LOAD8(screenAddr + 24);

	ctx.fpscr.disableFlushMode();
	const float minusOne = LOAD_F32(minusOneAddress);
	const float screenWidth = (float)displayWidth;
	const float screenHeight = (float)displayHeight;
	STORE_F32(layoutAddr + 0x20, screenWidth);
	STORE_F32(layoutAddr + 0x24, screenHeight);
	STORE_F32(layoutAddr + 0x40, rectDisabled == 0 ? 1.0f : 0.0f);

	if (rectDisabled != 0) {
		for (uint32_t offset = 0x28; offset < 0x40; offset += 4) {
			STORE_F32(layoutAddr + offset, minusOne);
		}
		ctx.r4.u64 = photoModeScreenAddr;
		return ctx.f1.f64;
	}

	const int32_t firstX = int32_t(LOAD32(screenAddr + 8));
	const int32_t firstY = int32_t(LOAD32(screenAddr + 12));
	const int32_t secondX = int32_t(LOAD32(screenAddr + 16));
	const int32_t secondY = int32_t(LOAD32(screenAddr + 20));
	ctx.fpscr.disableFlushMode();
	const float horizontalScale = LOAD_F32(horizontalScaleAddress);   // 1/1280
	const float verticalScale = LOAD_F32(verticalScaleAddress);       // 1/720
	STORE_F32(layoutAddr + 0x38, minusOne);
	STORE_F32(layoutAddr + 0x3C, minusOne);

	// A coordinate in 1280 x 720 units scaled to the display size, in single precision, then truncated to an
	// integer (saturating; NaN gives INT_MIN).
	auto toDisplay = [](int32_t units, float scale, float displaySize) -> int32_t {
		const double fraction = (double)(float)((double)(float)units * (double)scale);
		const double scaled = (double)(float)(fraction * (double)displaySize);
		if (std::isnan(scaled)) return INT_MIN;
		if (scaled > (double)INT_MAX) return INT_MAX;
		if (scaled < (double)INT_MIN) return INT_MIN;
		return (int32_t)scaled;
	};
	const int32_t displayFirstX = toDisplay(firstX, horizontalScale, screenWidth);
	const int32_t displayFirstY = toDisplay(firstY, verticalScale, screenHeight);
	const int32_t displaySecondX = toDisplay(secondX, horizontalScale, screenWidth);
	const int32_t displaySecondY = toDisplay(secondY, verticalScale, screenHeight);

	STORE_F32(layoutAddr + 0x28, (float)displayFirstX);
	STORE_F32(layoutAddr + 0x2C, (float)displayFirstY);
	STORE_F32(layoutAddr + 0x30, (float)displaySecondX);
	STORE_F32(layoutAddr + 0x34, (float)displaySecondY);

	ctx.r4.s64 = displayFirstY;
	ctx.f2.f64 = (double)displayFirstY;
	ctx.f3.f64 = (double)displaySecondX;
	ctx.f4.f64 = (double)displayFirstX;
	return (double)displaySecondY;
}
PROMOTED_ENTRY(58, sub_82846598, 0x82846598) { ctx.f1.f64 = CPhotoModeScreen_UpdateLayout(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhotoModeScreen_ShowResultMessage(CpuState& ctx, uint8_t* base, uint32_t photoModeScreenAddr, uint64_t resultCode) {
	constexpr int32_t str_TXT_820DD2F8_B_ = int32_t(0x820DD2F8);
	constexpr int32_t str_TXT_820DD314_B_ = int32_t(0x820DD314);
	constexpr int32_t g_820DD334 = int32_t(0x820DD334);
	constexpr uint32_t globalRootAddress = 0x834968A4;
	if (!UseLiftedCode(58, 0x82846978)) { ctx.r3.u64 = photoModeScreenAddr; ctx.r4.u64 = resultCode; __imp__sub_82846978(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82846978);
	uint32_t stack = ctx.r1.u64;
	const uint32_t lockMsr = ctx.r13.u64;
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);
	stack = PushStackFrame(base, stack, 144);

	const uint32_t result = uint32_t(resultCode);
	const uint32_t keyStringAddr = stack + 88;
	const uint32_t messageAddr = stack + 84;
	const uint32_t messageCopyAddr = stack + 80;

	photoModeScreen->m_5 = 0;

	// Drop the reference held at +4 of the root's object at +72 (an atomic decrement of the referenced object's
	// count at +4; vtable slot 1 of that object is called when the count reaches 0), then clear that reference.
	uint32_t globalRoot = LOAD32(globalRootAddress);
	const uint32_t holder = LOAD32(globalRoot + 72);
	const uint32_t referenced = LOAD32(holder + 4);
	uint64_t releaseHandOver = resultCode;
	if (referenced != 0) {
		const uint64_t refCountAddr = (uint64_t)referenced + 4;
		uint32_t refCount;
		bool stored;
		do {
			std::atomic_thread_fence(std::memory_order_seq_cst);
			const uint32_t savedMsr = REX_CHECK_GLOBAL_LOCK();
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = lockMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_ENTER_GLOBAL_LOCK();
			ctx.reserved.u32 = *(uint32_t*)RAW((uint32_t)refCountAddr);
			refCount = __builtin_bswap32(ctx.reserved.u32) - 1;
			stored = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(RAW((uint32_t)refCountAddr)), ctx.reserved.s32,
			                                      __builtin_bswap32((int32_t)refCount));
			std::atomic_thread_fence(std::memory_order_seq_cst);
			ctx.msr = savedMsr & 0x8020 | ctx.msr & ~0x8020;
			REX_LEAVE_GLOBAL_LOCK();
		} while (!stored);
		// The successful store-conditional leaves cr0 = equal (with the summary-overflow bit) for the calls below.
		ctx.cr0.lt = 0;
		ctx.cr0.gt = 0;
		ctx.cr0.eq = 1;
		ctx.cr0.so = ctx.xer.so;
		if ((int32_t)refCount == 0) {
			const uint32_t vtable = LOAD32(referenced);
			const uint32_t method = LOAD32(vtable + 4);
			PPCRegister callTarget{};
			callTarget.u64 = method;
			ctx.r1.u64 = stack;
			ctx.r3.u64 = referenced;
			ctx.r4.u64 = resultCode;
			ctx.r9.u64 = refCountAddr;
			ctx.r10.u64 = method;
			REX_CALL_INDIRECT_FUNC(callTarget.u32);
			releaseHandOver = ctx.r4.u64;
		}
		globalRoot = LOAD32(globalRootAddress);
		STORE32(holder + 4, 0);
	}
	STORE32(holder + 4, 0);

	const uint32_t holderToRelease = LOAD32(globalRoot + 72);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = releaseHandOver;
	CGameObject_Release(ctx, base, holderToRelease);

	if (result == 1 || result == 2) {
		const int32_t key = result == 1 ? str_TXT_820DD314_B_ : str_TXT_820DD2F8_B_;
		uint64_t keyString = CCharString_ConstructFromCStr(ctx, base, keyStringAddr, (uint64_t)(int64_t)key, int32_t(-1));
		uint64_t message = LocalisedText_InitFromKey(ctx, base, messageAddr, keyString);
		GUI_ShowMessageBox(ctx, base, message, 0, 0, ctx.r8.u64);
		uint64_t released = CCharString_ReleaseAndDecGlobalCountB(ctx, base, messageAddr);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return released;
	}

	// Any other result: the failure text with the wide string at g_820DD334 assigned into a copy of it.
	uint64_t keyString = CCharString_ConstructFromCStr(ctx, base, keyStringAddr, (uint64_t)(int64_t)str_TXT_820DD2F8_B_, int32_t(-1));
	uint64_t message = LocalisedText_InitFromKey(ctx, base, messageAddr, keyString);
	CCharString_ConstructCopy(ctx, base, messageCopyAddr, message);
	CWideString_AssignFromWStr(ctx, base, messageCopyAddr, (uint64_t)(int64_t)g_820DD334);
	GUI_ShowMessageBox(ctx, base, messageCopyAddr, 0, 0, ctx.r8.u64);
	CCharString_ReleaseAndDecGlobalCountB(ctx, base, messageCopyAddr);
	uint64_t released = CCharString_ReleaseAndDecGlobalCountB(ctx, base, messageAddr);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return released;
}
PROMOTED_ENTRY(58, sub_82846978, 0x82846978) { ctx.r3.u64 = CPhotoModeScreen_ShowResultMessage(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CPhotoModeScreen_IsActive(CpuState& ctx, uint8_t* base, uint64_t photoModeScreenAddr) {
	constexpr uint32_t globalRootAddress = 0x834968A4;
	if (!UseLiftedCode(58, 0x82846AA0)) { ctx.r3.u64 = photoModeScreenAddr; __imp__sub_82846AA0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82846AA0);
	GameStackFrame stackFrame(ctx, base, 96);
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);

	uint64_t isActive = 1;
	if (photoModeScreen->m_5 == 0 && photoModeScreen->m_4 == 0) {
		const uint32_t vtable = photoModeScreen->vtable;
		const uint32_t method = LOAD32(vtable + 8);
		PPCRegister callTarget{};
		callTarget.u64 = method;
		ctx.r3.u64 = photoModeScreenAddr;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((ctx.r3.u32 & 0xFF) == 0) {
			const uint32_t rootMember72 = LOAD32(LOAD32(globalRootAddress) + 72);
			const uint32_t member8 = LOAD32(rootMember72 + 8);
			isActive = member8 != 0;
			// The original leaves its test of member8 in r7 and r8, and a caller (sub_8257EA18) reads r7.
			ctx.r7.u64 = member8 == 0 ? 1 : 0;
			ctx.r8.u64 = member8 == 0 ? 32 : __builtin_clz(member8);
		}
	}
	return isActive;
}
PROMOTED_ENTRY(58, sub_82846AA0, 0x82846AA0) { ctx.r3.u64 = CPhotoModeScreen_IsActive(ctx, base, ctx.r3.u64); }

uint64_t CPhotoModeScreen_HandleInput(CpuState& ctx, uint8_t* base, uint64_t photoModeScreenAddr, uint64_t inputCode) {
	constexpr uint32_t globalRootAddress = 0x834968A4;
	constexpr int32_t TXT_83498794_G_ = int32_t(0x83498794);
	if (!UseLiftedCode(58, 0x82846B20)) { ctx.r3.u64 = photoModeScreenAddr; ctx.r4.u64 = inputCode; __imp__sub_82846B20(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82846B20);
	uint32_t stack = ctx.r1.u64;
	// What CPhotoModeScreen_IsActive is handed in r4 and r9: the input code and the caller's r9, or, after the
	// vtable slot 2 call below, what that call leaves in r4 and its (zero) result.
	uint64_t forwardedCode = inputCode;
	uint64_t forwardedValue = ctx.r9.u64;
	CPhotoModeScreen* photoModeScreen = GameObject<CPhotoModeScreen>(base, photoModeScreenAddr);
	stack = PushStackFrame(base, stack, 112);

	if ((int32_t)inputCode == 36) {
		const uint32_t vtable = photoModeScreen->vtable;
		const uint32_t method = LOAD32(vtable + 8);
		PPCRegister callTarget{};
		callTarget.u64 = method;
		ctx.r1.u64 = stack;
		ctx.r3.u64 = photoModeScreenAddr;
		ctx.r4.u64 = inputCode;
		ctx.r10.u64 = method;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		const uint32_t methodResult = ctx.r3.u32 & 0xFF;
		forwardedCode = ctx.r4.u64;
		forwardedValue = methodResult;

		if (methodResult != 0) {
			if (photoModeScreen->m_4 == 0 && photoModeScreen->m_5 == 0) {
				const uint32_t soundAddr = stack + 80;
				ctx.r6.u64 = 0;
				Sound_CreateFromEvent(ctx, base, soundAddr, LOAD32(globalRootAddress), (uint64_t)(int64_t)TXT_83498794_G_);
				OwnedPtr_Reset(ctx, base, soundAddr);

				const uint32_t vtableNow = photoModeScreen->vtable;
				const uint32_t slot4Method = LOAD32(vtableNow + 16);
				callTarget.u64 = slot4Method;
				ctx.r3.u64 = photoModeScreenAddr;
				ctx.r8.u64 = slot4Method;
				ctx.r9.u64 = vtableNow;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
			}
			stack = PopStackFrame(stack, 112);
			ctx.r1.u64 = stack;
			return 1;
		}
	}

	ctx.r1.u64 = stack;
	ctx.r4.u64 = forwardedCode;
	ctx.r9.u64 = forwardedValue;
	uint64_t isActive = CPhotoModeScreen_IsActive(ctx, base, photoModeScreenAddr);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return isActive;
}
PROMOTED_ENTRY(58, sub_82846B20, 0x82846B20) { ctx.r3.u64 = CPhotoModeScreen_HandleInput(ctx, base, ctx.r3.u64, ctx.r4.u64); }
