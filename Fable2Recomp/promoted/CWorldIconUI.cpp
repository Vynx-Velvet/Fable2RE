// CWorldIconUI (vtable 0x820D69F0): methods of the class as readable C++.
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

uint64_t CWorldIconUI_DeletingDestructor(CpuState& ctx, uint8_t* base, uint64_t worldIconUIAddr, uint64_t deleteFlags) {
	if (!UseLiftedCode(54, 0x827D14C0)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = deleteFlags; __imp__sub_827D14C0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D14C0);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;
	CWorldIconUI_Destructor(ctx, base, worldIconUIAddr);
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, worldIconUIAddr);
	}
	return worldIconUIAddr;
}
PROMOTED_ENTRY(54, sub_827D14C0, 0x827D14C0) { ctx.r3.u64 = CWorldIconUI_DeletingDestructor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CWorldIconUI_Destructor(CpuState& ctx, uint8_t* base, uint64_t worldIconUIAddr) {
	constexpr int32_t CWorldIconUI_vtable = int32_t(0x820D69F0);
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	constexpr int32_t alphaConstantPage = int32_t(0x820A0000);
	constexpr uint32_t alphaConstantAddress = 0x8209BE60;
	if (!UseLiftedCode(54, 0x827D1510)) { ctx.r3.u64 = worldIconUIAddr; __imp__sub_827D1510(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827D1510);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	const uint64_t ownVtable = uint64_t(int64_t(CWorldIconUI_vtable));
	const uint32_t elements = worldIconUI->m_80;
	worldIconUI->vtable = uint32_t(ownVtable);
	const uint32_t attachedElement = LOAD32(elements + 4);
	if (attachedElement != 0) {
		const uint32_t elementManager = LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 4);
		ctx.r9.u64 = ownVtable;
		EntityHandle_Detach(ctx, base, attachedElement, elementManager, 0);
	}
	const uint32_t elementsAfterDetach = worldIconUI->m_80;
	const uint32_t gameGlobals = LOAD32(gameGlobalsPointer);
	STORE8(elementsAfterDetach + 48, 0);
	const uint32_t uiContext = LOAD32(gameGlobals + 32);
	ctx.fpscr.disableFlushMode();
	const double alpha = double(LOAD_F32(alphaConstantAddress));
	const uint32_t iconElement = LOAD32(elementsAfterDetach + 4);
	const uint32_t elementManager = LOAD32(uiContext + 4);
	ctx.r7.u64 = uiContext;
	ctx.r8.s64 = alphaConstantPage;
	ctx.r9.u64 = 0;
	GuiElement_SetAlpha(ctx, base, iconElement, elementManager, alpha);
	return CWorldIcon_Destructor(ctx, base, worldIconUIAddr);
}
PROMOTED_ENTRY(54, sub_827D1510, 0x827D1510) { ctx.r3.u64 = CWorldIconUI_Destructor(ctx, base, ctx.r3.u64); }

uint64_t CWorldIconUI_Hide(CpuState& ctx, uint8_t* base, uint32_t worldIconUIAddr) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	constexpr uint32_t member30ResetValueAddress = 0x820994C0;
	if (!UseLiftedCode(54, 0x827D1C08)) { ctx.r3.u64 = worldIconUIAddr; __imp__sub_827D1C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1C08);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	if (worldIconUI->m_34 == 0) {
		return 1;
	}
	worldIconUI->m_34 = 0;
	worldIconUI->m_64 = 1;
	ctx.fpscr.disableFlushMode();
	worldIconUI->m_30 = float(double(LOAD_F32(member30ResetValueAddress)));
	const uint32_t gameGlobals = LOAD32(gameGlobalsPointer);
	const uint32_t mainElement = LOAD32(uint32_t(worldIconUI->m_80));
	const uint32_t uiContext = LOAD32(gameGlobals + 32);
	const uint32_t elementManager = LOAD32(uiContext + 4);
	ctx.r9.u64 = uiContext;
	GuiElement_SetState(ctx, base, mainElement, elementManager, 2);
	return 0;
}
PROMOTED_ENTRY(54, sub_827D1C08, 0x827D1C08) { ctx.r3.u64 = CWorldIconUI_Hide(ctx, base, ctx.r3.u32); }

uint64_t CWorldIconUI_UpdateIconState(CpuState& ctx, uint8_t* base, uint64_t worldIconUIAddr, uint64_t initData) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	if (!UseLiftedCode(54, 0x827D1C90)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = initData; __imp__sub_827D1C90(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1C90);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = CCameraEffectController_InitFromData(ctx, base, worldIconUIAddr, initData);
	uint64_t secondResult = ctx.r4.u64;
	if (LOAD32(uint32_t(worldIconUI->m_80)) != 0) {
		const uint32_t iconType = worldIconUI->m_14;
		secondResult = iconType;
		const uint32_t uiContextMember28 = LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 28);
		ctx.r3.u64 = uiContextMember28;
		result = n_sub_821AB5B8(ctx, base, iconType);
		worldIconUI->m_84 = (uint32_t(result) & 0xFF) == 0 ? 1u : 4u;
	}
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(54, sub_827D1C90, 0x827D1C90) { ctx.r3.u64 = CWorldIconUI_UpdateIconState(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CWorldIconUI_DetachAttachedEntity(CpuState& ctx, uint8_t* base, uint32_t worldIconUIAddr, uint64_t detachFlag) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	if (!UseLiftedCode(54, 0x827D1D00)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = detachFlag; __imp__sub_827D1D00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1D00);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	const uint32_t attachedElement = LOAD32(uint32_t(worldIconUI->m_80) + 4);
	if (attachedElement == 0) {
		ctx.r4.u64 = detachFlag;
		return 0;
	}
	const uint32_t elementManager = LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 4);
	return EntityHandle_Detach(ctx, base, attachedElement, elementManager, detachFlag);
}
PROMOTED_ENTRY(54, sub_827D1D00, 0x827D1D00) { ctx.r3.u64 = CWorldIconUI_DetachAttachedEntity(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CWorldIconUI_SetIconType(CpuState& ctx, uint8_t* base, uint64_t worldIconUIAddr, uint64_t iconType) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	if (!UseLiftedCode(54, 0x827D1D30)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = iconType; __imp__sub_827D1D30(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1D30);
	uint32_t stack = ctx.r1.u64;
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	stack = PushStackFrame(base, stack, 112);
	const int32_t type = int32_t(iconType);
	worldIconUI->m_14 = uint32_t(iconType);
	uint64_t result = worldIconUIAddr;
	uint64_t secondResult = iconType;
	if (type != 35) {
		// a string in the frame, filled by GetModeName and released at the end
		const uint32_t labelText = stack + 80;
		ctx.r1.u64 = stack;
		CCameraEffectController_GetModeName(ctx, base, labelText, worldIconUIAddr);
		const uint32_t labelElement = LOAD32(uint32_t(worldIconUI->m_80) + 8);
		if (labelElement != 0) {
			const uint32_t elementManager = LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 4);
			if (type == 54) {
				GuiElement_SetVisibility(ctx, base, labelElement, elementManager, 0);
			} else {
				GuiElement_SetVisibility(ctx, base, labelElement, elementManager, 1);
				GuiElement_AssignText(ctx, base, labelText, LOAD32(uint32_t(worldIconUI->m_80) + 8));
			}
		}
		result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, labelText);
		secondResult = ctx.r4.u64;
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return result;
}
PROMOTED_ENTRY(54, sub_827D1D30, 0x827D1D30) { ctx.r3.u64 = CWorldIconUI_SetIconType(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CWorldIconUI_SetText(CpuState& ctx, uint8_t* base, uint32_t worldIconUIAddr, uint64_t primaryText, uint64_t secondaryText) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	constexpr int32_t alphaConstantPage = int32_t(0x820A0000);
	constexpr uint32_t alphaConstantAddress = 0x8209BE60;
	if (!UseLiftedCode(54, 0x827D1DD0)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = primaryText; ctx.r5.u64 = secondaryText; __imp__sub_827D1DD0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1DD0);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	GameStackFrame stackFrame(ctx, base, 112);
	const uint32_t primaryTextElement = LOAD32(uint32_t(worldIconUI->m_80) + 16);
	GuiElement_SetText(ctx, base, primaryTextElement, LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 4), primaryText);
	const uint32_t secondaryTextElement = LOAD32(uint32_t(worldIconUI->m_80) + 12);
	GuiElement_SetText(ctx, base, secondaryTextElement, LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 4), secondaryText);
	const uint32_t elements = worldIconUI->m_80;
	const uint32_t uiContext = LOAD32(LOAD32(gameGlobalsPointer) + 32);
	ctx.fpscr.disableFlushMode();
	const double alpha = double(LOAD_F32(alphaConstantAddress));
	const uint32_t iconElement = LOAD32(elements + 4);
	const uint32_t elementManager = LOAD32(uiContext + 4);
	ctx.r5.u64 = elements;
	ctx.r6.s64 = alphaConstantPage;
	return GuiElement_SetAlpha(ctx, base, iconElement, elementManager, alpha);
}
PROMOTED_ENTRY(54, sub_827D1DD0, 0x827D1DD0) { ctx.r3.u64 = CWorldIconUI_SetText(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u64); }

uint64_t CWorldIconUI_UpdateScale(CpuState& ctx, uint8_t* base, uint64_t worldIconUIAddr) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	constexpr int32_t alphaConstantPage = int32_t(0x820A0000);
	constexpr uint32_t alphaConstantAddress = 0x8209BE60;
	if (!UseLiftedCode(54, 0x827D1E48)) { ctx.r3.u64 = worldIconUIAddr; __imp__sub_827D1E48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D1E48);
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	GameStackFrame stackFrame(ctx, base, 96);
	uint64_t result = n_sub_827D3A08(ctx, base, worldIconUIAddr);
	const uint32_t elements = worldIconUI->m_80;
	if (LOAD32(elements) != 0) {
		const uint32_t iconElement = LOAD32(elements + 4);
		ctx.fpscr.disableFlushMode();
		const double alphaScale = double(worldIconUI->m_40);
		const double alpha = double(float(alphaScale * double(LOAD_F32(alphaConstantAddress))));
		const uint32_t uiContext = LOAD32(LOAD32(gameGlobalsPointer) + 32);
		const uint32_t elementManager = LOAD32(uiContext + 4);
		ctx.r8.u64 = uiContext;
		ctx.r9.s64 = alphaConstantPage;
		ctx.f13.f64 = alphaScale;
		result = GuiElement_SetAlpha(ctx, base, iconElement, elementManager, alpha);
	}
	return result;
}
PROMOTED_ENTRY(54, sub_827D1E48, 0x827D1E48) { ctx.r3.u64 = CWorldIconUI_UpdateScale(ctx, base, ctx.r3.u64); }

uint64_t CWorldIconUI_SetColour(CpuState& ctx, uint8_t* base, uint32_t worldIconUIAddr, uint32_t colourRgba) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	if (!UseLiftedCode(54, 0x827D2400)) { ctx.r3.u64 = worldIconUIAddr; ctx.r4.u64 = colourRgba; __imp__sub_827D2400(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D2400);
	uint32_t stack = ctx.r1.u64;
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	stack = PushStackFrame(base, stack, 112);
	// a copy of the four colour bytes in the frame, handed to both elements
	const uint32_t colourCopy = stack + 80;
	uint8_t colourBytes[4];
	for (uint32_t i = 0; i < 4; ++i) {
		colourBytes[i] = LOAD8(colourRgba + i);
	}
	for (uint32_t i = 0; i < 4; ++i) {
		STORE8(colourCopy + i, colourBytes[i]);
	}
	const uint32_t gameGlobals = LOAD32(gameGlobalsPointer);
	const uint32_t elementManager = LOAD32(LOAD32(gameGlobals + 32) + 4);
	const uint32_t primaryTextElement = LOAD32(uint32_t(worldIconUI->m_80) + 16);
	ctx.r1.u64 = stack;
	GuiElement_SetColourFromBytes(ctx, base, primaryTextElement, elementManager, colourCopy);
	const uint32_t elementManagerAfterCall = LOAD32(LOAD32(gameGlobals + 32) + 4);
	const uint32_t secondaryTextElement = LOAD32(uint32_t(worldIconUI->m_80) + 12);
	const uint64_t result = GuiElement_SetColourFromBytes(ctx, base, secondaryTextElement, elementManagerAfterCall, colourCopy);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(54, sub_827D2400, 0x827D2400) { ctx.r3.u64 = CWorldIconUI_SetColour(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t CWorldIconUI_UpdateTransform(CpuState& ctx, uint8_t* base, uint64_t resultAddr, uint64_t worldIconUIAddr, uint64_t forwardedArg1, uint64_t forwardedArg2) {
	constexpr uint32_t gameGlobalsPointer = 0x834968A4;
	constexpr uint32_t fillValueAddress = 0x820994B4;
	if (!UseLiftedCode(54, 0x827D2488)) { ctx.r3.u64 = resultAddr; ctx.r4.u64 = worldIconUIAddr; ctx.r7.u64 = forwardedArg1; ctx.r8.u64 = forwardedArg2; __imp__sub_827D2488(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827D2488);
	uint32_t stack = ctx.r1.u64;
	// the method returns a six-float block through resultAddr; the object keeps the block at +76 and recomputes it
	// while bit 1 of m_48 is set
	CWorldIconUI* worldIconUI = GameObject<CWorldIconUI>(base, worldIconUIAddr);
	const uint32_t cachedResult = uint32_t(worldIconUIAddr) + 76;
	uint64_t secondResult = worldIconUIAddr;
	stack = PushStackFrame(base, stack, 224);

	// the bytes from a frame address up to the end of its 16-byte block, as the original reads them
	auto loadFromFrame = [&](uint32_t address) {
		PPCVRegister value{};
		SET_V8(value, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(address & ~0xF)),
		                                    simde_mm_load_si128((simde__m128i*)&VectorMaskL[(address & 0xF) * 16])));
		return value;
	};

	if ((worldIconUI->m_48 & 2) != 0) {
		const uint32_t uiContext = LOAD32(LOAD32(gameGlobalsPointer) + 32);
		ctx.r1.u64 = stack;
		n_sub_823F96E8(ctx, base, stack + 96, LOAD32(uint32_t(worldIconUI->m_80)), LOAD32(uiContext + 4), forwardedArg1, forwardedArg2, uiContext);

		const uint32_t uiContextAfterCall = LOAD32(LOAD32(gameGlobalsPointer) + 32);
		ctx.fpscr.disableFlushMode();
		const float fill = float(double(LOAD_F32(fillValueAddress)));
		STORE_F32(stack + 84, fill);
		STORE_F32(stack + 80, fill);
		STORE_F32(stack + 92, fill);
		STORE_F32(stack + 88, fill);

		const uint32_t firstInputOwner = LOAD32(uiContextAfterCall + 28);
		const uint32_t firstTransformInputB = LOAD32(firstInputOwner + 76);
		const uint32_t firstTransformInputA = LOAD32(firstInputOwner + 72);
		ctx.r6.u64 = firstInputOwner;
		ctx.r7.u64 = uiContextAfterCall;
		const uint32_t firstPosition = CCameraEffectController_GetPosition(ctx, base, stack + 160, worldIconUIAddr);

		// the point at frame +96 with the fill value merged in, as the original assembles the vector
		PPCVRegister fillAt80 = loadFromFrame(stack + 80);
		PPCVRegister firstPoint = loadFromFrame(stack + 96);
		PPCVRegister fillAt84 = loadFromFrame(stack + 84);
		SET_VF(firstPoint, simde_mm_blend_ps(VF(firstPoint), simde_mm_permute_ps(VF(fillAt80), 57), 4));
		PPCVRegister firstPointTail = loadFromFrame(stack + 100);
		SET_VF(firstPointTail, simde_mm_blend_ps(VF(firstPointTail), simde_mm_permute_ps(VF(fillAt84), 57), 4));
		SET_VF(firstPoint, simde_mm_blend_ps(VF(firstPoint), simde_mm_permute_ps(VF(firstPointTail), 78), 3));
		ctx.v1 = firstPoint;
		SET_V8(ctx.v2, VLOAD(firstPosition & ~0xF));
		Mesh_ComputeTransform(ctx, base, stack + 112, firstTransformInputA, firstTransformInputB);

		const uint32_t secondInputOwner = LOAD32(LOAD32(LOAD32(gameGlobalsPointer) + 32) + 28);
		const uint32_t secondTransformInputB = LOAD32(secondInputOwner + 76);
		const uint32_t secondTransformInputA = LOAD32(secondInputOwner + 72);
		ctx.r7.u64 = secondInputOwner;
		const uint32_t secondPosition = CCameraEffectController_GetPosition(ctx, base, stack + 144, worldIconUIAddr);

		// the same for the point at frame +104
		PPCVRegister fillAt88 = loadFromFrame(stack + 88);
		PPCVRegister secondPoint = loadFromFrame(stack + 104);
		PPCVRegister fillAt92 = loadFromFrame(stack + 92);
		SET_VF(secondPoint, simde_mm_blend_ps(VF(secondPoint), simde_mm_permute_ps(VF(fillAt88), 57), 4));
		PPCVRegister secondPointTail = loadFromFrame(stack + 108);
		SET_VF(secondPointTail, simde_mm_blend_ps(VF(secondPointTail), simde_mm_permute_ps(VF(fillAt92), 57), 4));
		SET_VF(secondPoint, simde_mm_blend_ps(VF(secondPoint), simde_mm_permute_ps(VF(secondPointTail), 78), 3));
		ctx.v1 = secondPoint;
		SET_V8(ctx.v2, VLOAD(secondPosition & ~0xF));
		Mesh_ComputeTransform(ctx, base, stack + 96, secondTransformInputA, secondTransformInputB);

		secondResult = stack + 96;

		// the six floats of the result from the two transformed points (first at +112, second at +96), gathered
		// through copies in the frame as the original does: first x, first y, second x, second y, first z, second z
		PPCVRegister copy{};
		SET_V8(copy, VLOAD((stack + 112) & ~0xF));
		VSTORE((stack + 112) & ~0xF, V8(copy));
		VSTORE((stack + 144) & ~0xF, V8(copy));
		VSTORE((stack + 160) & ~0xF, V8(copy));
		ctx.fpscr.disableFlushMode();
		const double firstY = double(LOAD_F32(stack + 116));
		const double firstX = double(LOAD_F32(stack + 144));
		const double firstZ = double(LOAD_F32(stack + 168));
		SET_V8(copy, VLOAD((stack + 96) & ~0xF));
		VSTORE((stack + 160) & ~0xF, V8(copy));
		const double secondZ = double(LOAD_F32(stack + 168));
		VSTORE((stack + 160) & ~0xF, V8(copy));
		const double secondX = double(LOAD_F32(stack + 160));
		VSTORE((stack + 144) & ~0xF, V8(copy));
		const double secondY = double(LOAD_F32(stack + 148));
		STORE_F32(stack + 116, float(firstY));
		STORE_F32(stack + 112, float(firstX));
		STORE_F32(stack + 128, float(firstZ));
		STORE_F32(stack + 124, float(secondY));
		STORE_F32(stack + 120, float(secondX));
		STORE_F32(stack + 132, float(secondZ));

		for (uint32_t offset = 0; offset < 24; offset += 4) {
			STORE32(cachedResult + offset, LOAD32(stack + 112 + offset));
		}
		worldIconUI->m_48 = worldIconUI->m_48 & ~2u;
	}

	ctx.fpscr.disableFlushMode();
	double values[6];
	for (uint32_t i = 0; i < 6; ++i) {
		values[i] = double(LOAD_F32(cachedResult + 4 * i));
	}
	for (uint32_t i = 0; i < 6; ++i) {
		STORE_F32(uint32_t(resultAddr) + 4 * i, float(values[i]));
	}

	stack = PopStackFrame(stack, 224);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = secondResult;
	return resultAddr;
}
PROMOTED_ENTRY(54, sub_827D2488, 0x827D2488) { ctx.r3.u64 = CWorldIconUI_UpdateTransform(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r7.u64, ctx.r8.u64); }
