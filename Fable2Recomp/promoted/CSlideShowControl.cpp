// CSlideShowControl (vtable 0x820030C8): methods of the class as readable C++.
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

// sub_82BAD680  [8 bytes]
uint64_t n_sub_82BAD680(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t deleteFlag) {
	if (!UseLiftedCode(86, 0x82BAD680)) { ctx.r3.u64 = arg1; ctx.r4.u64 = deleteFlag; __imp__sub_82BAD680(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAD680);
	// CSlideShowControl embeds its CAKElementBuilder at offset 0x4C.
	uint64_t elementBuilder = arg1 - 0x4C;
	return CAKElementBuilder_DeletingDestructor(ctx, base, elementBuilder, deleteFlag);
}
PROMOTED_ENTRY(86, sub_82BAD680, 0x82BAD680) { ctx.r3.u64 = n_sub_82BAD680(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CSlideShowControl_GotoSlideByIndex(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t context, uint64_t slideIndex, uint64_t preload) {
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	if (!UseLiftedCode(86, 0x82BAF540)) { ctx.r3.u64 = slideShowControlAddr; ctx.r4.u64 = context; ctx.r5.u64 = slideIndex; ctx.r6.u64 = preload; __imp__sub_82BAF540(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF540);
	uint32_t stack = ctx.r1.u64;
	uint32_t controlAddr = (uint32_t)slideShowControlAddr;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);

	stack = PushStackFrame(base, stack, 144);
	STORE32(stack + 172, (uint32_t)context);

	uint32_t prepareFn = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = prepareFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = context;
	ctx.r5.u64 = slideIndex;
	ctx.r6.u64 = preload;
	ctx.r10.u64 = prepareFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t showState = ctx.r3.u32;

	if ((int32_t)slideIndex < 1 || (int32_t)slideIndex >= (int32_t)LOAD8(showState + 42)) {

		uint64_t message = (int64_t)str_TXT_82100000_B_ - 11700;
		uint32_t logFn = LOAD32(0x83314A7Cu);
		callTarget.u64 = logFn;
		ctx.r3.u64 = 2;
		ctx.r4.u64 = message;
		ctx.r9.u64 = logFn;
		ctx.r10.s64 = str_TXT_82100000_B_;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return ctx.r3.u64;
	}

	uint32_t show;
	if ((uint32_t)preload & 0xFF) {
		show = LOAD32(controlAddr - 72);
		uint32_t preloadFn = LOAD32(LOAD32(show) + 116);
		callTarget.u64 = preloadFn;
		ctx.r3.u64 = show;
		ctx.r10.u64 = preloadFn;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		uint64_t preloadSlot = ctx.r3.u64 + 192;
		n_sub_82284810(ctx, base, preloadSlot, stack + 172);
	}

	show = LOAD32(controlAddr - 72);
	uint32_t firstSlideIndex = LOAD16(showState + 40);
	uint32_t listFn = LOAD32(LOAD32(show) + 40);
	callTarget.u64 = listFn;
	ctx.r3.u64 = show;
	ctx.r10.u64 = listFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t slideList = ctx.r3.u32;

	uint64_t targetIndex = (uint64_t)firstSlideIndex + slideIndex;
	uint32_t listVtable = LOAD32(slideList);
	uint32_t setCurrentFn = LOAD32(listVtable + 4);
	callTarget.u64 = setCurrentFn;
	ctx.r4.u64 = targetIndex;
	ctx.r8.u64 = setCurrentFn;
	ctx.r9.u64 = listVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	show = LOAD32(controlAddr - 72);
	uint32_t showVtable = LOAD32(show);
	uint32_t firstFn = LOAD32(showVtable + 40);
	callTarget.u64 = firstFn;
	ctx.r3.u64 = show;
	ctx.r6.u64 = firstFn;
	ctx.r7.u64 = showVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t firstSlot = ctx.r3.u32;
	uint32_t setFirstFn = LOAD32(LOAD32(firstSlot) + 8);
	callTarget.u64 = setFirstFn;
	ctx.r4.u64 = context;
	ctx.r5.u64 = firstSlideIndex;
	ctx.r10.u64 = setFirstFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	show = LOAD32(controlAddr - 72);
	showVtable = LOAD32(show);
	uint32_t lastFn = LOAD32(showVtable + 40);
	callTarget.u64 = lastFn;
	ctx.r3.u64 = show;
	ctx.r8.u64 = lastFn;
	ctx.r9.u64 = showVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t lastSlot = ctx.r3.u32;
	uint32_t lastVtable = LOAD32(lastSlot);
	uint32_t setLastFn = LOAD32(lastVtable + 8);
	callTarget.u64 = setLastFn;
	ctx.r4.u64 = context;
	ctx.r5.u64 = (uint32_t)targetIndex;
	ctx.r6.u64 = setLastFn;
	ctx.r7.u64 = lastVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t previousSlide = LOAD8(showState + 43);
	STORE8(showState + 43, (uint8_t)slideIndex);
	STORE8(showState + 44, (uint8_t)previousSlide);
	uint32_t flags = (uint32_t)LOAD8(showState + 64) | 16;
	STORE32(showState + 56, 0);
	STORE8(showState + 64, (uint8_t)flags);
	STORE32(showState + 48, 0);

	show = LOAD32(controlAddr - 72);
	uint32_t notifyVtable = LOAD32(show);
	uint32_t notifyFn = LOAD32(notifyVtable + 116);
	callTarget.u64 = notifyFn;
	ctx.r3.u64 = show;
	ctx.r4.u64 = previousSlide;
	ctx.r9.u64 = notifyFn;
	ctx.r10.u64 = notifyVtable;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t notifySlot = ctx.r3.u64 + 240;
	uint64_t result = n_sub_82284810(ctx, base, notifySlot, stack + 172);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(86, sub_82BAF540, 0x82BAF540) { ctx.r3.u64 = CSlideShowControl_GotoSlideByIndex(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

uint64_t CSlideShowControl_GotoSlideByName(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t contextArg, uint64_t slideName) {
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	if (!UseLiftedCode(86, 0x82BAF6B0)) { ctx.r3.u64 = slideShowControlAddr; ctx.r4.u64 = contextArg; ctx.r5.u64 = slideName; __imp__sub_82BAF6B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF6B0);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 128);

	uint32_t getSlideSet = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = (uint64_t)getSlideSet;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = contextArg;
	ctx.r5.u64 = slideName;
	ctx.r10.u64 = getSlideSet;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t slideSet = ctx.r3.u32;

	uint32_t slideShowOwner = LOAD32((uint32_t)slideShowControlAddr - 72);
	uint32_t slideShowImpl = LOAD32(slideShowOwner);
	uint32_t getSlideFinder = LOAD32(slideShowImpl + 40);
	callTarget.u64 = (uint64_t)getSlideFinder;
	ctx.r3.u64 = slideShowOwner;
	ctx.r7.u64 = getSlideFinder;
	ctx.r8.u64 = slideShowImpl;
	ctx.r9.u64 = slideShowOwner;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t slideFinder = ctx.r3.u32;

	uint16_t slideSetCapacity = LOAD16(slideSet + 40);
	uint8_t slideSetCount = LOAD8(slideSet + 42);
	uint32_t findSlideByName = LOAD32(LOAD32(slideFinder) + 12);
	callTarget.u64 = (uint64_t)findSlideByName;
	ctx.r4.u64 = slideName;
	ctx.r5.u64 = slideSetCapacity;
	ctx.r6.u64 = slideSetCount;
	ctx.r10.u64 = findSlideByName;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t slideIndex = ctx.r3.u32 & 0xFF;

	if (slideIndex >= 1 && slideIndex < LOAD8(slideSet + 42)) {
		uint32_t gotoSlide = LOAD32(uint32_t(slideShowControl->vtable) + 8);
		callTarget.u64 = (uint64_t)gotoSlide;
		ctx.r3.u64 = slideShowControlAddr;
		ctx.r4.u64 = contextArg;
		ctx.r5.u64 = slideIndex;
		ctx.r6.u64 = 1;
		ctx.r10.u64 = gotoSlide;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	} else {
		uint64_t missingSlideMessage = (int64_t)str_TXT_82100000_B_ - 11668;
		uint32_t logMessage = LOAD32(0x83314A7Cu);
		callTarget.u64 = (uint64_t)logMessage;
		ctx.r3.u64 = 2;
		ctx.r4.u64 = missingSlideMessage;
		ctx.r5.u64 = slideIndex;
		ctx.r9.u64 = logMessage;
		ctx.r10.s64 = str_TXT_82100000_B_;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAF6B0, 0x82BAF6B0) { ctx.r3.u64 = CSlideShowControl_GotoSlideByName(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

// sub_82BAF770  [48 bytes]
uint64_t CSlideShowControl_GetCurrentSlide(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr) {
	if (!UseLiftedCode(86, 0x82BAF770)) { ctx.r3.u64 = slideShowControlAddr; __imp__sub_82BAF770(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF770);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t virtualFunc = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = (uint64_t)virtualFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r10.u64 = virtualFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t slideObjectAddr = ctx.r3.u64;
	uint64_t currentSlide = LOAD8((uint32_t)slideObjectAddr + 43);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return currentSlide;
}
PROMOTED_ENTRY(86, sub_82BAF770, 0x82BAF770) { ctx.r3.u64 = CSlideShowControl_GetCurrentSlide(ctx, base, ctx.r3.u64); }

uint64_t CSlideShowControl_NextSlide(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t context, uint64_t slideOffset) {
	if (!UseLiftedCode(86, 0x82BAF7D0)) { ctx.r3.u64 = slideShowControlAddr; ctx.r4.u64 = context; ctx.r5.u64 = slideOffset; __imp__sub_82BAF7D0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF7D0);
	uint32_t stack = ctx.r1.u64;
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	PPCRegister callTarget{};

	stack = PushStackFrame(base, stack, 112);

	uint32_t vtable = slideShowControl->vtable;
	callTarget.u64 = LOAD32(vtable + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = context;
	ctx.r5.u64 = slideOffset;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t slideInfo = (uint32_t)ctx.r3.u64;
	uint32_t currentSlide = LOAD8(slideInfo + 0x2B);
	uint64_t lastSlideIndex = LOAD8(slideInfo + 0x2A) - 1;

	uint64_t targetSlide = (uint64_t)currentSlide + slideOffset;
	if ((int32_t)targetSlide <= 1) {
		targetSlide = 1;
	} else if ((int32_t)targetSlide >= (int32_t)lastSlideIndex) {
		targetSlide = lastSlideIndex;
	}

	if ((int32_t)targetSlide != (int32_t)currentSlide) {
		uint32_t vtable2 = slideShowControl->vtable;
		callTarget.u64 = LOAD32(vtable2 + 8);
		ctx.r3.u64 = slideShowControlAddr;
		ctx.r4.u64 = context;
		ctx.r5.u64 = targetSlide;
		ctx.r6.u64 = 1;
		ctx.r9.u64 = callTarget.u64;
		ctx.r10.u64 = vtable2;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAF7D0, 0x82BAF7D0) { ctx.r3.u64 = CSlideShowControl_NextSlide(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CSlideShowControl_PreviousSlide(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t context, uint64_t slideOffset) {
	if (!UseLiftedCode(86, 0x82BAF858)) { ctx.r3.u64 = slideShowControlAddr; ctx.r4.u64 = context; ctx.r5.u64 = slideOffset; __imp__sub_82BAF858(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF858);
	uint32_t stack = ctx.r1.u64;
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);

	stack = PushStackFrame(base, stack, 112);

	PPCRegister callTarget{};

	// vtable slot 1: fetch the current slide description object
	uint32_t getCurrentSlideFunc = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = getCurrentSlideFunc;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = context;
	ctx.r5.u64 = slideOffset;
	ctx.r10.u64 = getCurrentSlideFunc;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t slideInfo = (uint32_t)ctx.r3.u64;
	int32_t currentSlide = LOAD8(slideInfo + 43);
	uint64_t lastSlideIndex = (uint64_t)((int32_t)LOAD8(slideInfo + 42) - 1);

	uint64_t targetSlide = (uint64_t)(uint32_t)currentSlide - slideOffset;
	if ((int32_t)targetSlide <= 1) {
		targetSlide = 1;
	} else if ((int32_t)targetSlide >= (int32_t)lastSlideIndex) {
		targetSlide = lastSlideIndex;
	}

	if ((int32_t)targetSlide != currentSlide) {
		// vtable slot 2: move to the target slide (animated)
		uint32_t vtable = slideShowControl->vtable;
		uint32_t setCurrentSlideFunc = LOAD32(vtable + 8);
		callTarget.u64 = setCurrentSlideFunc;
		ctx.r3.u64 = slideShowControlAddr;
		ctx.r4.u64 = context;
		ctx.r5.u64 = targetSlide;
		ctx.r6.u64 = 1;
		ctx.r9.u64 = setCurrentSlideFunc;
		ctx.r10.u64 = vtable;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAF858, 0x82BAF858) { ctx.r3.u64 = CSlideShowControl_PreviousSlide(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t n_sub_82BAF8E0(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr) {
	if (!UseLiftedCode(86, 0x82BAF8E0)) { ctx.r3.u64 = slideShowControlAddr; __imp__sub_82BAF8E0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF8E0);
	uint32_t stack = ctx.r1.u64;
	uint64_t slideObj{};
	uint32_t vtable{};
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t createSlideFn = LOAD32((uint32_t)slideShowControl->vtable + 4);
	callTarget.u64 = createSlideFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r10.u64 = createSlideFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	slideObj = ctx.r3.u64;

	vtable = slideShowControl->vtable;
	uint32_t showSlideFn = LOAD32(vtable + 8);
	uint32_t typeFlag = LOAD8((uint32_t)slideObj + 44);
	callTarget.u64 = showSlideFn;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = slideObj;
	ctx.r5.u64 = typeFlag;
	ctx.r6.u64 = 1;
	ctx.r7.u64 = showSlideFn;
	ctx.r8.u64 = vtable;
	ctx.r9.u64 = slideObj;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAF8E0, 0x82BAF8E0) { ctx.r3.u64 = n_sub_82BAF8E0(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BAF940(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t slideIndex) {
	if (!UseLiftedCode(86, 0x82BAF940)) { ctx.r3.u64 = slideShowControlAddr; ctx.r5.u64 = slideIndex; __imp__sub_82BAF940(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF940);
	uint32_t stack = ctx.r1.u64;
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t getTargetFn = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	PPCRegister callTarget{};
	callTarget.u64 = getTargetFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r5.u64 = slideIndex;
	ctx.r10.u64 = getTargetFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t targetAddr = (uint32_t)(ctx.r3.u64 + 48);
	uint8_t flags = LOAD8(targetAddr + 16);
	STORE32(targetAddr + 8, (uint32_t)slideIndex);
	STORE32(targetAddr, (uint32_t)slideIndex);
	STORE8(targetAddr + 16, uint8_t(flags | 16));

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAF940, 0x82BAF940) { ctx.r3.u64 = n_sub_82BAF940(ctx, base, ctx.r3.u64, ctx.r5.u64); }

uint64_t n_sub_82BAF990(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr) {
	if (!UseLiftedCode(86, 0x82BAF990)) { ctx.r3.u64 = slideShowControlAddr; __imp__sub_82BAF990(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF990);
	uint32_t stack = ctx.r1.u64;
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);

	stack = PushStackFrame(base, stack, 96);
	uint32_t virtualMethod = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);

	uint32_t resultObjectAddr = ctx.r3.u32;
	bool flag = (LOAD8(resultObjectAddr + 0x40) >> 2) & 1;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return flag;
}
PROMOTED_ENTRY(86, sub_82BAF990, 0x82BAF990) { ctx.r3.u64 = n_sub_82BAF990(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BAF9C8(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr) {
	if (!UseLiftedCode(86, 0x82BAF9C8)) { ctx.r3.u64 = slideShowControlAddr; __imp__sub_82BAF9C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAF9C8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 96);
	callTarget.u64 = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t returnedObject = ctx.r3.u32;
	uint32_t isFlagSet = (LOAD8(returnedObject + 64) >> 1) & 1;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return isFlagSet;
}
PROMOTED_ENTRY(86, sub_82BAF9C8, 0x82BAF9C8) { ctx.r3.u64 = n_sub_82BAF9C8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BAFA00(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t context, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {
	if (!UseLiftedCode(86, 0x82BAFA00)) { ctx.r3.u64 = slideShowControlAddr; ctx.r4.u64 = context; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; ctx.r7.u64 = arg5; ctx.r8.u64 = arg6; __imp__sub_82BAFA00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAFA00);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);
	stack = PushStackFrame(base, stack, 144);

	// Virtual call on the slide show control, returns the state object to fill in.
	uint32_t getStateFn = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = getStateFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r4.u64 = context;
	ctx.r5.u64 = arg3;
	ctx.r6.u64 = arg4;
	ctx.r7.u64 = arg5;
	ctx.r8.u64 = arg6;
	ctx.r10.u64 = getStateFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t stateAddr = (uint32_t)ctx.r3.u64 + 48;

	uint32_t flags = ((uint32_t)arg4 << 1) | ((uint32_t)arg5 & 1);
	uint32_t previousLowBit = LOAD8(stateAddr + 16) & 1;

	STORE32(stateAddr, 0);
	STORE32(stateAddr + 8, 0);
	STORE32(stateAddr + 4, (uint32_t)arg3);
	STORE32(stateAddr + 12, 0xFFFFFFFFu);

	uint32_t packedFlags = (flags << 5) | previousLowBit;
	uint32_t lowByte = packedFlags & 0xFF;
	uint32_t newByte = lowByte | 10;
	STORE8(stateAddr + 16, (uint8_t)newByte);

	// Second virtual call, on the owner object located 76 bytes before the control.
	uint32_t ownerAddr = (uint32_t)slideShowControlAddr - 76;
	uint32_t owner = LOAD32(ownerAddr);
	uint32_t callbackFn = LOAD32(owner + 80);
	callTarget.u64 = callbackFn;
	ctx.r3.u64 = ownerAddr;
	ctx.r4.u64 = context;
	ctx.r5.u64 = 16384;
	ctx.r6.u64 = arg6;
	ctx.r7.u64 = owner;
	ctx.r8.u64 = newByte;
	ctx.r9.u64 = stateAddr;
	ctx.r10.u64 = lowByte;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAFA00, 0x82BAFA00) { ctx.r3.u64 = n_sub_82BAFA00(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64); }

uint64_t n_sub_82BAFA98(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr, uint64_t arg2) {
	if (!UseLiftedCode(86, 0x82BAFA98)) { ctx.r3.u64 = slideShowControlAddr; ctx.r5.u64 = arg2; __imp__sub_82BAFA98(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAFA98);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);

	stack = PushStackFrame(base, stack, 96);

	// second vtable slot: query the slideshow's current target object
	uint32_t getTarget = LOAD32(uint32_t(slideShowControl->vtable) + 4);
	callTarget.u64 = getTarget;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r5.u64 = arg2;
	ctx.r10.u64 = getTarget;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	uint32_t targetAddr = (uint32_t)ctx.r3.u64;
	uint32_t subObjectAddr = targetAddr + 48;
	uint32_t flagsAddr = subObjectAddr + 16;
	uint8_t flags = LOAD8(flagsAddr);
	flags = (uint8_t)(((arg2 & 1) << 2) | (flags & ~4u));
	STORE8(flagsAddr, flags);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAFA98, 0x82BAFA98) { ctx.r3.u64 = n_sub_82BAFA98(ctx, base, ctx.r3.u64, ctx.r5.u64); }

uint64_t n_sub_82BAFAE8(CpuState& ctx, uint8_t* base, uint64_t slideShowControlAddr) {
	if (!UseLiftedCode(86, 0x82BAFAE8)) { ctx.r3.u64 = slideShowControlAddr; __imp__sub_82BAFAE8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BAFAE8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CSlideShowControl* slideShowControl = GameObject<CSlideShowControl>(base, slideShowControlAddr);

	stack = PushStackFrame(base, stack, 96);

	// slideShowControl->vtable[1]() -> state object
	uint32_t getStateFn = LOAD32(slideShowControl->vtable + 4);
	callTarget.u64 = getStateFn;
	ctx.r1.u64 = stack;
	ctx.r3.u64 = slideShowControlAddr;
	ctx.r10.u64 = getStateFn;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint32_t state = ctx.r3.u32;

	// owner object stored just before the slide show control; owner->vtable[10]()
	uint32_t owner = LOAD32((uint32_t)slideShowControlAddr - 72);
	uint32_t ownerVtable = LOAD32(owner);
	uint32_t ownerFn = LOAD32(ownerVtable + 40);
	callTarget.u64 = ownerFn;
	ctx.r3.u64 = owner;
	ctx.r7.u64 = ownerFn;
	ctx.r8.u64 = ownerVtable;
	ctx.r9.u64 = owner;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);
	uint64_t target = ctx.r3.u64;

	// target->vtable[4](state->m_28, state->m_2B)
	uint32_t param1 = LOAD16(state + 40);
	uint32_t param2 = LOAD8(state + 43);
	callTarget.u64 = LOAD32(LOAD32((uint32_t)target) + 16);
	ctx.r4.u64 = param1;
	ctx.r5.u64 = param2;
	ctx.r10.u64 = callTarget.u64;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(86, sub_82BAFAE8, 0x82BAFAE8) { ctx.r3.u64 = n_sub_82BAFAE8(ctx, base, ctx.r3.u64); }
