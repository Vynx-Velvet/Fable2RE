// CECLevelExit (vtable 0x82003408): methods of the class as readable C++.
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

uint64_t CECLevelExit_GetClassName(CpuState& ctx, uint8_t* base, uint64_t classNameString) {
	constexpr int32_t str_TXT_820C8A38_B_ = int32_t(0x820C8A38);
	if (!UseLiftedCode(55, 0x827E9860)) { ctx.r3.u64 = classNameString; __imp__sub_827E9860(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827E9860);
	uint32_t stack = ctx.r1.u64;
	uint64_t classNameCStr{};
	int32_t length{};
	stack = PushStackFrame(base, stack, 96);
	length = -1;
	classNameCStr = str_TXT_820C8A38_B_;
	ctx.r1.u64 = stack;
	CCharString_ConstructFromCStr(ctx, base, classNameString, classNameCStr, length);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return classNameString;
}
PROMOTED_ENTRY(55, sub_827E9860, 0x827E9860) { ctx.r3.u64 = CECLevelExit_GetClassName(ctx, base, ctx.r3.u64); }

void n_sub_827E98A8(CpuState& ctx, uint8_t* base, uint32_t levelExitAddr, uint32_t arg2) {
	if (!UseLiftedCode(55, 0x827E98A8)) { ctx.r3.u64 = levelExitAddr; ctx.r4.u64 = arg2; __imp__sub_827E98A8(ctx, base); return; }
	LiftedFrame frame(0x827E98A8);
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	levelExit->m_4 = arg2;
	levelExit->m_8 = 0;
	levelExit->vtable = 0x82003408u;
	levelExit->m_C = 0;

	uint32_t refCount = LOAD32(0x83496EB8u);
	STORE32(0x83496EB8u, refCount + 1);
	levelExit->m_10 = 0;

	refCount = LOAD32(0x83496EB8u);
	STORE32(0x83496EB8u, refCount + 1);
	levelExit->m_14 = 0;

	refCount = LOAD32(0x83496EB8u);
	STORE32(0x83496EB8u, refCount + 1);
	levelExit->m_18 = 0;

	refCount = LOAD32(0x83496EB8u);
	STORE32(0x83496EB8u, refCount + 1);
	levelExit->m_20 = 0;

	levelExit->m_1C = 0x820F1664u;
	levelExit->m_2C = 0;
	ctx.fpscr.disableFlushMode();
	float initialValue = LOAD_F32(0x820994B4u);
	levelExit->m_30 = 0;
	levelExit->m_24 = initialValue;
	levelExit->m_34 = 0;
	levelExit->m_28 = initialValue;
	levelExit->m_35 = 1;
	levelExit->m_36 = 1;
	levelExit->m_37 = 0;
	levelExit->m_38 = 0;
	levelExit->m_39 = 0;
	levelExit->m_3A = 0;
	levelExit->m_3B = 0;
	levelExit->m_3C = 0;
	levelExit->m_3D = 0;
	levelExit->m_3E = 0;
	return;
}
PROMOTED_ENTRY(55, sub_827E98A8, 0x827E98A8) { n_sub_827E98A8(ctx, base, ctx.r3.u32, ctx.r4.u32); }

uint64_t n_sub_827E99B0(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr, uint64_t flags) {
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	if (!UseLiftedCode(55, 0x827E99B0)) { ctx.r3.u64 = levelExitAddr; ctx.r4.u64 = flags; __imp__sub_827E99B0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827E99B0);
	uint32_t stack = ctx.r1.u64;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 112);

	levelExit->m_1C = g_820F1664;
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flags;
	ctx.r10.u64 = uint32_t(g_820F1664);
	EntityHandle_Release(ctx, base, levelExitAddr + 28);

	levelExit->m_20 = 0u;
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, levelExitAddr + 24);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, levelExitAddr + 20);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, levelExitAddr + 16);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, levelExitAddr + 12);

	levelExit->vtable = 0x820A8D10u;
	if ((uint32_t(flags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, levelExitAddr);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return levelExitAddr;
}
PROMOTED_ENTRY(55, sub_827E99B0, 0x827E99B0) { ctx.r3.u64 = n_sub_827E99B0(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827E9A48(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr, uint64_t dbHandle) {
	constexpr int32_t g_820994C0 = int32_t(0x820994C0);
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820D8528_B_ = int32_t(0x820D8528);
	constexpr int32_t str_TXT_820D853C_B_ = int32_t(0x820D853C);
	constexpr int32_t str_TXT_820D8590_B_ = int32_t(0x820D8590);
	constexpr int32_t str_TXT_820D85A0_B_ = int32_t(0x820D85A0);
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827E9A48)) { ctx.r3.u64 = levelExitAddr; ctx.r4.u64 = dbHandle; __imp__sub_827E9A48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827E9A48);
	uint32_t stack = ctx.r1.u64;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 176);

	double savedF1 = ctx.f1.f64;
	double savedF10 = ctx.f10.f64;
	double savedF11 = ctx.f11.f64;
	double savedF12 = ctx.f12.f64;
	double savedF13 = ctx.f13.f64;
	uint64_t savedR5 = 0;
	uint64_t savedR7 = 0;
	uint64_t savedR8 = 0;
	uint64_t savedR9 = 0;

	if ((uint32_t)dbHandle != 0) {
		uint64_t TXT_820D8528_L_ = str_TXT_820D8528_B_;
		uint64_t TXT_820D853C_L_ = str_TXT_820D853C_B_;
		uint64_t entityConnectingTo = (int64_t)g_820E0000 - 31408;
		uint64_t activatedOnInteraction = (int64_t)g_820E0000 - 31388;
		uint64_t radiusKey = (int64_t)str_TXT_820B0000_B_ + 14124;
		uint64_t overriddenTextTagKey = (int64_t)g_820E0000 - 31364;

		ctx.r1.u64 = stack;
		n_sub_8239CD28(ctx, base, dbHandle, TXT_820D8528_L_, levelExitAddr + 12);
		savedF1 = ctx.f1.f64;
		savedF10 = ctx.f10.f64;
		savedF11 = ctx.f11.f64;
		savedF12 = ctx.f12.f64;
		savedF13 = ctx.f13.f64;

		n_sub_8239CD28(ctx, base, dbHandle, TXT_820D853C_L_, levelExitAddr + 16);
		savedF1 = ctx.f1.f64;
		savedF10 = ctx.f10.f64;
		savedF11 = ctx.f11.f64;
		savedF12 = ctx.f12.f64;
		savedF13 = ctx.f13.f64;

		ctx.r9.u64 = (uint32_t)g_820E0000;
		n_sub_8239CD28(ctx, base, dbHandle, entityConnectingTo, levelExitAddr + 20);
		savedF1 = ctx.f1.f64;
		savedF10 = ctx.f10.f64;
		savedF11 = ctx.f11.f64;
		savedF12 = ctx.f12.f64;
		savedF13 = ctx.f13.f64;

		ctx.r8.u64 = (uint32_t)g_820E0000;
		GameDB_ReadBool(ctx, base, dbHandle, activatedOnInteraction, levelExitAddr + 60);

		ctx.r7.u64 = (uint32_t)str_TXT_820B0000_B_;
		GameDB_ReadFloatField(ctx, base, dbHandle, radiusKey, levelExitAddr + 36);

		ctx.r6.u64 = (uint32_t)g_820E0000;
		uint64_t TXT_820D857C_L_ = n_sub_82345978(ctx, base, dbHandle, overriddenTextTagKey);
		CCharString_AssignFromCStr(ctx, base, levelExitAddr + 24, TXT_820D857C_L_);
		savedF1 = ctx.f1.f64;
		savedF10 = ctx.f10.f64;
		savedF11 = ctx.f11.f64;
		savedF12 = ctx.f12.f64;
		savedF13 = ctx.f13.f64;
	}

	uint32_t entity = levelExit->m_4;
	ctx.r1.u64 = stack;
	n_sub_82392C88(ctx, base, entity, levelExitAddr);
	savedF1 = ctx.f1.f64;
	savedF10 = ctx.f10.f64;
	savedF11 = ctx.f11.f64;
	savedF12 = ctx.f12.f64;
	savedF13 = ctx.f13.f64;

	uint32_t owner = levelExit->m_4;
	uint8_t ownerFlags = LOAD8(owner + 144);
	uint64_t newOwnerFlags = (uint64_t)ownerFlags | 2;
	STORE8(owner + 144, (uint8_t)newOwnerFlags);

	// virtual call on the entity, writing a 16-byte result into a stack buffer
	uint32_t ownerObject = levelExit->m_4;
	uint32_t vtableOwner = LOAD32(ownerObject + 124);
	uint32_t vtable = LOAD32(vtableOwner);
	uint32_t method = LOAD32(vtable + 64);
	PPCRegister callTarget{};
	callTarget.u64 = method;
	ctx.r3.u64 = (uint64_t)stack + 80;
	ctx.r4.u64 = vtableOwner;
	ctx.r6.u64 = method;
	ctx.r7.u64 = vtable;
	ctx.r8.u64 = ownerObject;
	ctx.r9.u64 = newOwnerFlags;
	ctx.r10.u64 = ownerFlags;
	REX_CALL_INDIRECT_FUNC(callTarget.u32);

	savedR7 = ctx.r7.u64;
	savedR8 = ctx.r8.u64;
	savedR9 = ctx.r9.u64;
	savedF1 = ctx.f1.f64;
	savedF10 = ctx.f10.f64;
	savedF11 = ctx.f11.f64;
	savedF12 = ctx.f12.f64;
	savedF13 = ctx.f13.f64;

	ctx.fpscr.disableFlushMode();
	float defaultRadius = LOAD_F32((uint32_t)g_820994C0 - 12);
	uint32_t manager = LOAD32((uint32_t)g_83490000 + 26912);
	uint32_t playerManager = LOAD32(manager + 12);
	uint32_t trackedObject = LOAD32(playerManager + 88);
	uint32_t behaviour = LOAD32(LOAD32(LOAD32(trackedObject + 4) + 8) + 4);
	uint32_t component = LOAD32(behaviour + 36);
	if (component != 0) {
		uint32_t callback = LOAD32(component + 4);
		PPCVRegister vec{};
		SET_V8(vec, VLOAD((stack + 80) & ~0xFu));
		ctx.r4.u64 = trackedObject;
		ctx.r5.u64 = playerManager;
		ctx.v1 = vec;
		n_sub_821EEB28(ctx, base, callback);

		savedR5 = ctx.r5.u64;
		savedR7 = ctx.r7.u64;
		savedR8 = ctx.r8.u64;
		savedR9 = ctx.r9.u64;
		savedF1 = ctx.f1.f64;
		savedF10 = ctx.f10.f64;
		savedF11 = ctx.f11.f64;
		savedF12 = ctx.f12.f64;
		savedF13 = ctx.f13.f64;

		ctx.fpscr.disableFlushMode();
		double distance = savedF1;
		if (distance > (double)LOAD_F32((uint32_t)g_820A0000 - 25888)) {
			uint32_t manager2 = LOAD32((uint32_t)g_83490000 + 26912);
			uint32_t playerManager2 = LOAD32(manager2 + 12);
			uint32_t trackedObject2 = LOAD32(playerManager2 + 88);
			uint32_t level1 = LOAD32(trackedObject2 + 4);
			uint32_t level2 = LOAD32(level1 + 8);
			uint32_t level3 = LOAD32(level2 + 4);
			uint32_t component2 = LOAD32(level3 + 36);

			double targetDistance = defaultRadius;
			if (component2 != 0) {
				uint32_t callback2 = LOAD32(component2 + 4);
				PPCVRegister vec2{};
				SET_V8(vec2, VLOAD((stack + 80) & ~0xFu));
				ctx.r7.u64 = level3;
				ctx.r8.u64 = level2;
				ctx.r9.u64 = level1;
				ctx.v1 = vec2;
				n_sub_821EED10(ctx, base, callback2);

				savedR5 = ctx.r5.u64;
				savedR7 = ctx.r7.u64;
				savedR8 = ctx.r8.u64;
				savedR9 = ctx.r9.u64;
				savedF1 = ctx.f1.f64;
				savedF10 = ctx.f10.f64;
				savedF11 = ctx.f11.f64;
				savedF12 = ctx.f12.f64;
				savedF13 = ctx.f13.f64;
				targetDistance = savedF1;
			} else {
				ctx.fpscr.disableFlushMode();
				savedF1 = defaultRadius;
				targetDistance = defaultRadius;
			}

			ctx.fpscr.disableFlushMode();
			double total = (double)(float)(targetDistance + distance);
			PPCVRegister spill{};
			SET_V8(spill, VLOAD((stack + 80) & ~0xFu));
			VSTORE((stack + 96) & ~0xFu, V8(spill));
			float threshold = LOAD_F32(stack + 104);
			if (total > (double)threshold) {
				float scale = LOAD_F32((uint32_t)g_820994C0);
				levelExit->m_3B = 1;
				VSTORE((stack + 96) & ~0xFu, V8(spill));
				float threshold2 = LOAD_F32(stack + 104);
				float excess = (float)(total - (double)threshold2);
				levelExit->m_24 = (float)((double)excess + (double)scale);
			}
		}
	}

	if ((uint32_t)dbHandle != 0) {
		uint64_t messageRadiusAddr = levelExitAddr + 40;
		uint64_t messageRadiusKey = str_TXT_820D8590_B_;
		uint64_t applyTXT_820D8590_B_Key = str_TXT_820D85A0_B_;
		ctx.r7.u64 = savedR7;
		ctx.r8.u64 = savedR8;
		GameDB_ReadFloatField(ctx, base, dbHandle, messageRadiusKey, messageRadiusAddr);
		uint32_t TXT_820D85A0_L_ = (uint32_t)GameDB_ReadBoolField_82303F38(ctx, base, dbHandle, applyTXT_820D8590_B_Key) & 0xFF;
		savedR5 = ctx.r5.u64;
		savedR7 = ctx.r7.u64;
		savedR8 = ctx.r8.u64;
		savedR9 = TXT_820D85A0_L_;
		if (TXT_820D85A0_L_ == 0) {
			bool useDefaultRadius = LOAD8((uint32_t)levelExitAddr + 59) != 0 || levelExit->m_3C != 0;
			if (useDefaultRadius) {
				ctx.fpscr.disableFlushMode();
				STORE_F32((uint32_t)messageRadiusAddr, defaultRadius);
			} else {
				ctx.fpscr.disableFlushMode();
				float currentRadius = LOAD_F32((uint32_t)messageRadiusAddr);
				if (currentRadius > LOAD_F32((uint32_t)g_820A0000 - 25888) &&
				    currentRadius < LOAD_F32(0x820F6B84u)) {
					STORE_F32((uint32_t)messageRadiusAddr, LOAD_F32(0x820F6B84u));
				}
			}
		}
	}

	ctx.r5.u64 = savedR5;
	ctx.r7.u64 = savedR7;
	ctx.r8.u64 = savedR8;
	ctx.r9.u64 = savedR9;
	ctx.f1.f64 = savedF1;
	ctx.f10.f64 = savedF10;
	ctx.f11.f64 = savedF11;
	ctx.f12.f64 = savedF12;
	ctx.f13.f64 = savedF13;
	uint64_t result = n_sub_827EA258(ctx, base, levelExitAddr, 1);
	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827E9A48, 0x827E9A48) { ctx.r3.u64 = n_sub_827E9A48(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_827E9CB0  [420 bytes]
uint64_t n_sub_827E9CB0(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr, uint64_t arg2, uint32_t arg3, uint64_t arg4) {
	constexpr int32_t g_8209003F = int32_t(0x8209003F);
	constexpr int32_t str_TXT_820ADDD8_B_ = int32_t(0x820ADDD8);
	constexpr int32_t str_TXT_820B59DC_B_ = int32_t(0x820B59DC);
	constexpr int32_t str_TXT_820D857C_B_ = int32_t(0x820D857C);
	constexpr int32_t str_TXT_820D85B4_B_ = int32_t(0x820D85B4);
	constexpr int32_t str_TXT_820D85D0_B_ = int32_t(0x820D85D0);
	constexpr int32_t str_TXT_820D85F8_B_ = int32_t(0x820D85F8);
	if (!UseLiftedCode(55, 0x827E9CB0)) { ctx.r3.u64 = levelExitAddr; ctx.r4.u64 = arg2; ctx.r5.u64 = arg3; ctx.r6.u64 = arg4; __imp__sub_827E9CB0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827E9CB0);
	uint32_t stack = ctx.r1.u64;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;

	const uint64_t tagName = stack + 84;  // CCharString temporary holding the field name
	const uint32_t flagsByte = (uint32_t)(arg4 & 0xFF);

	ctx.r6.u64 = arg4;
	CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820D857C_B_, -1);
	n_sub_82A16EC0(ctx, base, tagName, arg2, levelExitAddr + 24);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);

	uint64_t r8Value = ctx.r8.u64;

	if ((int32_t)arg3 == 1) {
		CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820D85B4_B_, -1);
		const uint32_t stringData = LOAD32(tagName);
		uint64_t savedValue;
		if (stringData == 0) {
			savedValue = (uint64_t)g_8209003F;
		} else {
			savedValue = (uint64_t)LOAD32(stringData);
		}
		ctx.r4.u64 = savedValue;
		IStream_SerializeU32(ctx, base, arg2, levelExitAddr + 44);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);

		CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820D85D0_B_, -1);
		IStream_SerializeString(ctx, base, tagName, arg2, levelExitAddr + 52);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);

		CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820D85F8_B_, -1);
		IStream_SerializeString(ctx, base, tagName, arg2, levelExitAddr + 58);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);

		CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820ADDD8_B_, -1);
		IStream_SerializeString(ctx, base, tagName, arg2, levelExitAddr + 56);
		CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);

		r8Value = flagsByte;
		if (flagsByte == 0) {
			levelExit->m_35 = 0;
			levelExit->m_36 = 0;
		}
	}

	if (flagsByte != 0) {
		CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820B59DC_B_, -1);
		IStream_SerializeString(ctx, base, tagName, arg2, levelExitAddr + 55);
		uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);
		stack = PopStackFrame(stack, 144);
		ctx.r1.u64 = stack;
		return result;
	}

	STORE8(stack + 80, 0);
	ctx.r8.u64 = r8Value;
	CCharString_ConstructFromCStr(ctx, base, tagName, str_TXT_820B59DC_B_, -1);
	IStream_SerializeString(ctx, base, tagName, arg2, stack + 80);
	CCharString_ReleaseAndDecGlobalCountA(ctx, base, tagName);
	uint32_t isActive = LOAD8(stack + 80);
	uint64_t result = n_sub_827EA258(ctx, base, levelExitAddr, isActive);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827E9CB0, 0x827E9CB0) { ctx.r3.u64 = n_sub_827E9CB0(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32, ctx.r6.u64); }

uint32_t n_sub_827E9E58(CpuState& ctx, uint8_t* base, uint32_t levelExitAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827E9E58)) { ctx.r3.u64 = levelExitAddr; __imp__sub_827E9E58(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x827E9E58);

	PPCCRRegister compare0 = ctx.cr0;
	PPCXERRegister flags = ctx.xer;

	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);

	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);

	uint64_t r7 = ctx.r7.u64;

	// Follow the game-loop manager down to the entity handle slot.
	uint32_t manager = LOAD32(g_83490000 + 26912);
	uint32_t loopContext = LOAD32(LOAD32(manager + 12) + 88);
	uint64_t arg2 = LOAD32(loopContext + 4);          // address of the handle pointer, later reused as the second call argument
	uint32_t handleOwner = LOAD32((uint32_t)arg2);
	uint64_t result = (uint64_t)handleOwner + 104;
	uint32_t handleSlot = LOAD32(handleOwner + 108);

	uint32_t entity = 0;
	bool isVisible = false;

	if (handleSlot != 0) {
		uint32_t entityPtr = LOAD32(handleSlot);
		if (entityPtr == 0) {
			ctx.r1.u64 = stack;
			ctx.r8.u64 = arg2;
			ctx.r9.u64 = loopContext;
			ctx.r10.u64 = entityPtr;
			result = EntityHandle_Release(ctx, base, result);
			r7 = ctx.r7.u64;
			arg2 = ctx.r8.u64;
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
			flags.ca = ctx.xer.ca;
		} else {
			entity = entityPtr;
			isVisible = (LOAD8(entity + 144) & 64) != 0;
		}
	}

	bool haveIndex = false;
	if (isVisible) {
		result = 0;
		if (LOAD32(levelExitAddr + 48) == 0) {
			if ((LOAD32(entity + 40) >> 1 & 1) != 0) {
				uint32_t loader = LOAD32(entity + 140);
				if (loader != 0) {
					uint32_t index = LOAD8(loader + 33);
					uint32_t arrayBase = LOAD32(entity + 72);
					result = LOAD32(arrayBase + index * 8 + 4);
					haveIndex = true;
				} else {
					// Lower-bound search of the 8-byte entry array for key 33.
					uint32_t begin = LOAD32(entity + 72);
					uint32_t end = LOAD32(entity + 76);
					STORE32(stack + 80, 0u);
					arg2 = (uint64_t)end - begin;
					STORE32(stack + 84, begin);

					uint32_t it = begin;
					int32_t count = (int32_t)arg2 >> 3;
					if (count > 0) {
						do {
							int32_t half = count >> 1;
							arg2 = (uint64_t)(uint32_t(half) << 3);
							it = it + (uint32_t)arg2;
							if ((int32_t)LOAD32(it) < 33) {
								count = count - half - 1;
								it = it + 8;
							} else {
								it = it - (uint32_t)arg2;
								count = half;
							}
						} while (count > 0);
						STORE32(stack + 84, it);
					}

					if (it != end && (int32_t)LOAD32(it) <= 33) {
						STORE64(stack + 80, LOAD64(stack + 80));
						result = LOAD32(it + 4);
					} else {
						result = LOAD32(end + 4);
					}
					haveIndex = true;
				}
			}
		}
		if (haveIndex) {
			ctx.r1.u64 = stack;
			ctx.r7.u64 = r7;
			ctx.cr0.lt = compare0.lt;
			ctx.cr0.gt = compare0.gt;
			ctx.cr0.eq = compare0.eq;
			ctx.cr0.so = compare0.so;
			ctx.xer.ca = flags.ca;
			result = n_sub_823D1FE8(ctx, base, result, arg2);   // Lua_Player_DisableFullPauseMenu
			r7 = ctx.r7.u64;
			arg2 = ctx.r8.u64;
			compare0.lt = ctx.cr0.lt;
			compare0.gt = ctx.cr0.gt;
			compare0.eq = ctx.cr0.eq;
			compare0.so = ctx.cr0.so;
			flags.ca = ctx.xer.ca;
			levelExit->m_30 = (uint32_t)result;
		}
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r7.u64 = r7;
	ctx.r8.u64 = arg2;
	ctx.cr0.lt = compare0.lt;
	ctx.cr0.gt = compare0.gt;
	ctx.cr0.eq = compare0.eq;
	ctx.cr0.so = compare0.so;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(55, sub_827E9E58, 0x827E9E58) { ctx.r3.u64 = n_sub_827E9E58(ctx, base, ctx.r3.u32); }

uint64_t n_sub_827EA020(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr) {
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827EA020)) { ctx.r3.u64 = levelExitAddr; __imp__sub_827EA020(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EA020);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags = ctx.xer;
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = levelExitAddr;
	uint32_t levelExitPtr = uint32_t(levelExitAddr);
	uint64_t compareResult = 0;
	if (LOAD32(levelExitPtr + 48) != 0) {
		uint32_t manager = LOAD32(uint32_t(g_83490000) + 26912);
		uint32_t entityRef = LOAD32(LOAD32(manager + 12) + 88);
		uint32_t handleHolder = LOAD32(entityRef + 4);
		ctx.r1.u64 = stack;
		ctx.r8.u64 = handleHolder;
		ctx.r9.u64 = entityRef;
		result = EntityHandle_Get(ctx, base, LOAD32(handleHolder));
		uint32_t entity = uint32_t(result);
		compareResult = ctx.r7.u64;
		flags.ca = ctx.xer.ca;

		if (entity != 0 && (LOAD8(entity + 144) & 0x40) != 0) {
			uint32_t entryId = 0;
			bool hasEntry = false;
			if (((LOAD32(entity + 40) >> 1) & 1) != 0) {
				uint32_t indexHolder = LOAD32(entity + 140);
				if (indexHolder != 0) {
					uint32_t node = (uint32_t(LOAD8(indexHolder + 33)) << 3) + LOAD32(entity + 72);
					hasEntry = true;
					entryId = LOAD32(node + 4);
				} else {
					uint32_t begin = LOAD32(entity + 72);
					uint32_t end = LOAD32(entity + 76);
					STORE32(stack + 80, 0);
					uint32_t count = end - begin;
					STORE32(stack + 84, begin);
					flags.ca = ((int32_t)count < 0) && ((count & 7) != 0);
					count = uint32_t((int32_t)count >> 3);
					if ((int32_t)count > 0) {
						do {
							flags.ca = ((int32_t)count < 0) && ((count & 1) != 0);
							uint32_t half = uint32_t((int32_t)count >> 1);
							uint32_t offset = half << 3;
							begin += offset;
							compareResult = ((int32_t)LOAD32(begin) < 33) ? 1 : 0;
							if (compareResult != 0) {
								count = count - half - 1;
								begin += 8;
							} else {
								begin -= offset;
								count = half;
							}
						} while ((int32_t)count > 0);
						STORE32(stack + 84, begin);
					}
					if (begin != end) {
						if ((int32_t)LOAD32(begin) > 33) {
							hasEntry = true;
							entryId = LOAD32(end + 4);
						} else {
							hasEntry = true;
							STORE64(stack + 80, LOAD64(stack + 80));
							entryId = LOAD32(LOAD32(stack + 84) + 4);
						}
					} else {
						hasEntry = true;
						entryId = LOAD32(end + 4);
					}
				}
			}
			if (hasEntry) {
				STORE32(stack + 80, LOAD32(levelExitPtr + 48));
				ctx.r7.u64 = compareResult;
				ctx.xer.ca = flags.ca;
				result = n_sub_824ED8F0(ctx, base, uint64_t(entryId) + 232, uint64_t(stack + 80));
				flags.ca = ctx.xer.ca;
			}
		}
	}
	STORE32(levelExitPtr + 48, 0);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return result;
}
PROMOTED_ENTRY(55, sub_827EA020, 0x827EA020) { ctx.r3.u64 = n_sub_827EA020(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827EA1D8(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr) {
	constexpr uint32_t g_gameLoopBase = 0x83490000;
	if (!UseLiftedCode(55, 0x827EA1D8)) { ctx.r3.u64 = levelExitAddr; __imp__sub_827EA1D8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EA1D8);
	uint32_t stack = ctx.r1.u64;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 112);

	uint64_t result = levelExitAddr;
	if (levelExit->m_39 != 0) {
		uint32_t guiRoot = LOAD32(g_gameLoopBase + 26788);
		uint32_t displayBoxList = LOAD32(LOAD32(guiRoot + 32) + 28);
		uint32_t levelExitId = levelExit->m_4;
		uint64_t levelExitName = (uint64_t)levelExitAddr + 16;

		ctx.r1.u64 = stack;
		n_sub_823B7058(ctx, base, displayBoxList, levelExitId, levelExitName);

		uint32_t removeList = LOAD32(LOAD32(LOAD32(g_gameLoopBase + 26788) + 28) + 52);
		uint64_t boxName = (uint64_t)levelExit->m_4 + 128;
		result = GUIDisplayBoxLists_RemoveByName(ctx, base, removeList, boxName, ctx.r8.u64);
		levelExit->m_39 = uint8_t(0);
	}

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827EA1D8, 0x827EA1D8) { ctx.r3.u64 = n_sub_827EA1D8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827EA250(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(55, 0x827EA250)) { ctx.r3.u64 = arg1; __imp__sub_827EA250(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EA250);
	return n_sub_827EA020(ctx, base, arg1);
}
PROMOTED_ENTRY(55, sub_827EA250, 0x827EA250) { ctx.r3.u64 = n_sub_827EA250(ctx, base, ctx.r3.u64); }

uint64_t n_sub_827EA258(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr, uint64_t arg2) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820A335C_B_ = int32_t(0x820A335C);
	constexpr int32_t str_TXT_820D8614_B_ = int32_t(0x820D8614);
	constexpr int32_t str_TXT_820D8640_B_ = int32_t(0x820D8640);
	constexpr int32_t g_820E0000 = int32_t(0x820E0000);
	constexpr int32_t g_820F0000 = int32_t(0x820F0000);
	constexpr int32_t g_820F1664 = int32_t(0x820F1664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827EA258)) { ctx.r3.u64 = levelExitAddr; ctx.r4.u64 = arg2; __imp__sub_827EA258(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EA258);
	PPCRegister scratch{};
	uint32_t stack = ctx.r1.u64;
	PPCVRegister local93{};
	PPCVRegister local94 = ctx.v1;
	PPCVRegister local95{};
	PPCVRegister local96{};
	PPCVRegister local97{};
	PPCRegister callTarget{};
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 208);
	uint64_t levelExitAddr2 = levelExitAddr;

	if (uint8_t(arg2 & 0xFF) != LOAD8((uint32_t)levelExitAddr2 + 55)) {
		levelExit->m_37 = (uint8_t)arg2;
		uint64_t entityHandleAddr = levelExitAddr2 + 28;
		uint32_t handleOwner = levelExit->m_20;
		bool shouldDestroy = false;
		if (handleOwner != 0) {
			uint32_t handleTarget = LOAD32(handleOwner);
			if (handleTarget == 0) {
				ctx.r1.u64 = stack;
				ctx.r4.u64 = arg2;
				ctx.r10.u64 = handleTarget;
				levelExitAddr = EntityHandle_Release(ctx, base, entityHandleAddr);
				arg2 = ctx.r4.u64;
			} else {
				ctx.r1.u64 = stack;
				ctx.r4.u64 = arg2;
				ctx.r10.u64 = handleTarget;
				levelExitAddr = EntityHandle_Get_825575C8(ctx, base, entityHandleAddr);
				arg2 = ctx.r4.u64;
				shouldDestroy = (LOAD8((uint32_t)levelExitAddr + 144) & 64) != 0;
			}
		}
		if (shouldDestroy) {
			ctx.r1.u64 = stack;
			ctx.r4.u64 = arg2;
			ctx.r9.u64 = 1;
			ctx.r10.s64 = int32_t(0x820F0000);
			uint64_t entity = EntityHandle_Get_825575C8(ctx, base, entityHandleAddr);
			Entity_DestroyImpl(ctx, base, entity);
			STORE32(stack + 88, g_820F1664);
			STORE32(stack + 92, 0);
			EntityHandle_Release(ctx, base, stack + 88);
			EntityHandle_Assign(ctx, base, entityHandleAddr, stack + 88);
			STORE32(stack + 88, g_820F1664);
			levelExitAddr = EntityHandle_Release(ctx, base, stack + 88);
			arg2 = ctx.r4.u64;
		}

		if (levelExit->m_37 != 0) {
			uint64_t built = 0;
			ctx.r1.u64 = stack;
			built = n_sub_821D9F40(ctx, base, stack + 96, levelExitAddr2);
			uint64_t idRef = IdRef_Get(ctx, base, built);
			levelExitAddr = GameDB_ReadBoolField_82303F38(ctx, base, idRef, str_TXT_820D8640_B_);
			arg2 = ctx.r4.u64;

			if ((levelExitAddr & 0xFF) != 0) {
				// TXT_820D8640_B_ is active: spawn the inactive-teleporter FX.
				CCharString_ConstructFromCStr(ctx, base, stack + 88, str_TXT_820A335C_B_, -1);
				CCharString_ConstructFromCStr(ctx, base, stack + 80, str_TXT_820D8614_B_, -1);

				uint32_t v4 = levelExit->m_4;
				uint32_t local53 = LOAD32(v4 + 124);
				uint32_t local74 = LOAD32(local53);
				uint32_t local73 = LOAD32(local74 + 64);
				callTarget.u64 = local73;
				ctx.r3.u64 = stack + 128;
				ctx.r4.u64 = local53;
				ctx.r7.u64 = local73;
				ctx.r8.u64 = local74;
				ctx.r9.u64 = v4;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);

				SET_V8(local94, VLOAD((stack + 128) & ~0xF));
				ctx.v1 = local94;
				uint64_t fromNamedDefinition = Entity_CreateFromNamedDefinition(ctx, base, stack + 80, stack + 88, -1);
				local94 = ctx.v1;

				STORE32(stack + 96, g_820F1664);
				STORE32(stack + 100, 0);
				EntityHandle_SetTarget(ctx, base, stack + 96, fromNamedDefinition);
				EntityHandle_Assign(ctx, base, entityHandleAddr, stack + 96);
				STORE32(stack + 96, g_820F1664);
				EntityHandle_Release(ctx, base, stack + 96);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);

				stack = PopStackFrame(stack, 208);
				ctx.r1.u64 = stack;
				return result;
			}

			if (levelExit->m_3B != 0) {
				uint32_t local57 = LOAD32(levelExit->m_4 + 124);
				uint32_t local81 = LOAD32(local57);
				uint32_t local77 = LOAD32(local81 + 64);
				callTarget.u64 = local77;
				ctx.r3.u64 = stack + 112;
				ctx.r4.u64 = local57;
				ctx.r9.u64 = local77;
				ctx.r10.u64 = local81;
				REX_CALL_INDIRECT_FUNC(callTarget.u32);
				double f1Value = ctx.f1.f64;

				uint32_t local92 = uint32_t(g_83490000);
				uint32_t local84 = LOAD32(local92 + 26912);
				ctx.fpscr.disableFlushMode();
				double defaultScale = double(LOAD_F32(0x820994B4u));
				uint32_t local58 = LOAD32(LOAD32(LOAD32(LOAD32(local84 + 12) + 88) + 4) + 8);
				uint32_t local82 = LOAD32(LOAD32(local58 + 4) + 36);
				double firstScale;
				if (local82 != 0) {
					uint32_t local38 = LOAD32(local82 + 4);
					SET_V8(local94, VLOAD((stack + 112) & ~0xF));
					ctx.r4.u64 = local58;
					ctx.v1 = local94;
					n_sub_821EED10(ctx, base, local38);
					local58 = ctx.r4.u32;
					f1Value = ctx.f1.f64;
					local84 = LOAD32(local92 + 26912);
					ctx.fpscr.disableFlushMode();
					firstScale = f1Value;
				} else {
					ctx.fpscr.disableFlushMode();
					firstScale = defaultScale;
				}

				local84 = LOAD32(local84 + 12);
				uint32_t local85 = LOAD32(LOAD32(LOAD32(LOAD32(LOAD32(local84 + 88) + 4) + 8) + 4) + 36);
				if (local85 != 0) {
					uint32_t local39 = LOAD32(local85 + 4);
					SET_V8(local94, VLOAD((stack + 112) & ~0xF));
					ctx.r4.u64 = local58;
					ctx.v1 = local94;
					n_sub_821EEB28(ctx, base, local39);
					f1Value = ctx.f1.f64;
				} else {
					ctx.fpscr.disableFlushMode();
					f1Value = defaultScale;
				}
				ctx.fpscr.disableFlushMode();
				STORE_F32(stack + 88, float(double(float(f1Value + firstScale))));

				uint32_t local75 = stack + 88;
				int32_t local72 = g_820A0000;
				int32_t local59 = local72 + 13148;
				SET_V8(local97, VLOAD((stack + 112) & ~0xF));
				SET_V8(local93, VLOAD(0x820991F0u & ~0xF));
				scratch.u32 = (uint32_t)local75;
				SET_V8(local96, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)RAW(scratch.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(scratch.u32 & 0xF) * 16])));
				SET_V8(local95, rex::ppc::simde_mm_perm_epi8_(V8(local97), V8(local96), V8(local93)));
				VSTORE((stack + 112) & ~0xF, V8(local95));

				ctx.r6.s64 = local72;
				ctx.r8.u64 = local75;
				ctx.f1.f64 = f1Value;
				ctx.v11 = local95;
				ctx.v12 = local96;
				ctx.v13 = local97;
				CCharString_ConstructFromCStr(ctx, base, stack + 80, local59, -1);

				int32_t local60 = g_820E0000 - 31188;
				CCharString_ConstructFromCStr(ctx, base, stack + 88, local60, -1);

				SET_V8(local94, VLOAD((stack + 112) & ~0xF));
				ctx.v1 = local94;
				uint64_t fromNamedDefinition2 = Entity_CreateFromNamedDefinition(ctx, base, stack + 88, stack + 80, -1);
				local94 = ctx.v1;

				STORE32(stack + 96, g_820F1664);
				STORE32(stack + 100, 0);
				EntityHandle_SetTarget(ctx, base, stack + 96, fromNamedDefinition2);
				EntityHandle_Assign(ctx, base, entityHandleAddr, stack + 96);
				STORE32(stack + 96, g_820F1664);
				EntityHandle_Release(ctx, base, stack + 96);
				CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 88);
				uint64_t result2 = CCharString_ReleaseAndDecGlobalCountA(ctx, base, stack + 80);
				local94 = ctx.v1;

				stack = PopStackFrame(stack, 208);
				ctx.r1.u64 = stack;
				return result2;
			}
		} else {
			// Deactivated: tear down the display box state.
			if (levelExit->m_39 != 0) {
				uint32_t local91 = uint32_t(g_83490000);
				uint32_t v42 = levelExit->m_4;
				uint64_t local71 = levelExitAddr2 + 16;
				uint32_t local86 = LOAD32(local91 + 26788);
				local86 = LOAD32(local86 + 32);
				uint32_t local49 = LOAD32(local86 + 28);
				ctx.r1.u64 = stack;
				n_sub_823B7058(ctx, base, local49, v42, local71);
				uint64_t local64 = (uint64_t)levelExit->m_4 + 128;
				uint32_t local50 = LOAD32(LOAD32(LOAD32(local91 + 26788) + 28) + 52);
				levelExitAddr = GUIDisplayBoxLists_RemoveByName(ctx, base, local50, local64, ctx.r8.u64);
				arg2 = ctx.r4.u64;
				levelExit->m_39 = 0;
			}
			levelExit->m_35 = 0;
			levelExit->m_36 = 0;
		}
	}
	stack = PopStackFrame(stack, 208);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = arg2;
	return levelExitAddr;
}
PROMOTED_ENTRY(55, sub_827EA258, 0x827EA258) { ctx.r3.u64 = n_sub_827EA258(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t n_sub_827EB4F0(CpuState& ctx, uint8_t* base, uint32_t levelExitAddr) {
	constexpr int32_t g_833198B8 = int32_t(0x833198B8);
	constexpr int32_t g_83320000 = int32_t(0x83320000);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827EB4F0)) { ctx.r3.u64 = levelExitAddr; __imp__sub_827EB4F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EB4F0);
	uint32_t stack = ctx.r1.u32;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 112);

	ctx.fpscr.disableFlushMode();
	double triggerValue = double(LOAD_F32(0x820994B4u));

	uint32_t eventManager = LOAD32(uint32_t(g_83490000) + 26788);
	uint32_t eventHandler = LOAD32(eventManager + 64);
	STORE8(eventHandler + 44, 0);

	ctx.r1.u64 = stack;
	uint64_t result = n_sub_823B3E00(ctx, base, eventHandler, uint32_t(g_833198B8), triggerValue);

	int32_t paramA = g_83320000;
	int32_t paramB = g_83490000;
	uint32_t linkedObject = LOAD32(uint32_t(paramA) - 27380);
	uint32_t worldObject = LOAD32(uint32_t(paramB) + 26912);
	levelExit->m_34 = 0;
	levelExit->m_2C = linkedObject;

	uint32_t ownerObject = LOAD32(worldObject + 12);
	uint32_t flagObject = LOAD32(ownerObject + 148);
	STORE8(flagObject + 2090, 1);

	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = flagObject;
	ctx.r5.u64 = ownerObject;
	ctx.r7.s64 = paramB;
	ctx.r8.s64 = paramA;
	return result;
}
PROMOTED_ENTRY(55, sub_827EB4F0, 0x827EB4F0) { ctx.r3.u64 = n_sub_827EB4F0(ctx, base, ctx.r3.u32); }

uint64_t n_sub_827EB570(CpuState& ctx, uint8_t* base, uint64_t levelExitAddr) {
	constexpr int32_t str_TXT_820D8640_B_ = int32_t(0x820D8640);
	constexpr int32_t str_TXT_820D8664_B_ = int32_t(0x820D8664);
	constexpr int32_t g_83490000 = int32_t(0x83490000);
	if (!UseLiftedCode(55, 0x827EB570)) { ctx.r3.u64 = levelExitAddr; __imp__sub_827EB570(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x827EB570);
	uint32_t stack = ctx.r1.u64;
	CECLevelExit* levelExit = GameObject<CECLevelExit>(base, levelExitAddr);
	stack = PushStackFrame(base, stack, 144);
	ctx.r1.u64 = stack;
	const uint32_t charStringBuf = stack + 80;
	const uint32_t idOut = stack + 88;
	const uint32_t levelExitField16 = levelExitAddr + 16;
	const uint32_t gameGlobal = uint32_t(g_83490000);

	n_sub_827E9E58(ctx, base, levelExitAddr);

	uint64_t idRef = IdRef_Get(ctx, base, n_sub_821D9F40(ctx, base, idOut, levelExitAddr));
	uint8_t TXT_820D8664_L_ = GameDB_ReadBoolField_82303F38(ctx, base, idRef, str_TXT_820D8664_B_);

	STORE32(charStringBuf, 0u);

	uint32_t msgEntry = n_sub_8247D010(ctx, base, LOAD32(LOAD32(gameGlobal + 26788) + 28) + 68, charStringBuf);
	STORE8(LOAD32(msgEntry) + 245, TXT_820D8664_L_);

	uint32_t exitEntity = levelExit->m_4;
	uint32_t hudBase = LOAD32(LOAD32(gameGlobal + 26788) + 32);
	ctx.r8.u64 = hudBase;
	n_sub_823B7058(ctx, base, LOAD32(hudBase + 28), exitEntity, levelExitField16);

	uint32_t boxList = LOAD32(LOAD32(gameGlobal + 26788) + 28);
	uint32_t boxLists = LOAD32(boxList + 52);
	uint32_t boxOwner = levelExit->m_4 + 128;
	if ((GUIDisplayBoxList_RemoveByName(ctx, base, boxLists + 4, boxOwner, ctx.r8.u64) & 0xFF) == 0) {
		GUIDisplayBoxList_RemoveByName(ctx, base, boxLists + 32, boxOwner, ctx.r8.u64);
	}

	uint32_t exitKind = 2;
	uint64_t idRef2 = IdRef_Get(ctx, base, n_sub_821D9F40(ctx, base, idOut, levelExitAddr));
	uint8_t isTXT_820D8640_B_ = GameDB_ReadBoolField_82303F38(ctx, base, idRef2, str_TXT_820D8640_B_);
	if (isTXT_820D8640_B_ != 0) {
		exitKind = 5;
	}

	uint32_t worldSub = LOAD32(LOAD32(gameGlobal + 26912) + 12);
	uint32_t targetObject = LOAD32(LOAD32(worldSub + 88) + 4);
	n_sub_8234AAC8(ctx, base, targetObject, levelExitAddr + 12, levelExitField16, levelExitAddr + 20, exitKind);

	uint64_t idRef3 = IdRef_Get(ctx, base, n_sub_821D9F40(ctx, base, idOut, levelExitAddr));
	uint64_t fieldText = n_sub_82345978(ctx, base, idRef3, (uint64_t)(int64_t)-2113042632);
	CCharString_ConstructFromCStr(ctx, base, charStringBuf, fieldText, -1);

	uint32_t str = LOAD32(charStringBuf);
	if (str != 0 && (int32_t)LOAD32(str + 4) != 0) {
		uint32_t worldSub2 = LOAD32(LOAD32(gameGlobal + 26912) + 12);
		uint32_t listAnchor = LOAD32(LOAD32(worldSub2 + 128) + 4);
		uint32_t node = LOAD32(listAnchor + 4);
		uint32_t nextNode = LOAD32(node + 4);
		if (nextNode == node) {
			ppc_trap(ctx, base, 22);
			ppc_trap(ctx, base, 22);
		}
		uint32_t obj = LOAD32(nextNode + 8);
		PPCRegister callTarget{};
		callTarget.u64 = LOAD32(LOAD32(obj) + 4);
		ctx.r3.u64 = obj;
		ctx.r8.u64 = node;
		ctx.r9.u64 = listAnchor;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		if ((int32_t)ctx.r3.u32 == 4) {
			CCharString_Assign(ctx, base, obj + 32, charStringBuf);
		}
	}

	n_sub_827EA020(ctx, base, levelExitAddr);
	uint64_t result = CCharString_ReleaseAndDecGlobalCountA(ctx, base, charStringBuf);
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(55, sub_827EB570, 0x827EB570) { ctx.r3.u64 = n_sub_827EB570(ctx, base, ctx.r3.u64); }
