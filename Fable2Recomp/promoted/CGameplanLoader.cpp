// CGameplanLoader (vtable 0x82002F88): methods of the class as readable C++.
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

uint64_t n_sub_821781C8(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(0, 0x821781C8)) { ctx.r3.u64 = arg1; __imp__sub_821781C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x821781C8);

	uint32_t gameplanObject = LOAD32((uint32_t)arg1 + 0x20C);
	uint32_t virtualMethod = LOAD32(LOAD32(gameplanObject) + 0xC);

	ctx.r3.u64 = gameplanObject;
	ctx.r10.u64 = virtualMethod;
	REX_CALL_INDIRECT_FUNC(virtualMethod);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(0, sub_821781C8, 0x821781C8) { ctx.r3.u64 = n_sub_821781C8(ctx, base, ctx.r3.u64); }

uint64_t n_sub_822BE580(CpuState& ctx, uint8_t* base, uint64_t loaderAddr, uint64_t flag) {
	if (!UseLiftedCode(12, 0x822BE580)) { ctx.r3.u64 = loaderAddr; ctx.r4.u64 = flag; __imp__sub_822BE580(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BE580);
	uint32_t stack = ctx.r1.u64;
	uint32_t loader = (uint32_t)loaderAddr;
	uint64_t object28 = loaderAddr + 0x28;
	// r4 as n_sub_822D0488 receives it: the flag, or what CThing_CopyState left in r4
	uint64_t r4ForD0488 = flag;

	stack = PushStackFrame(base, stack, 336);

	if ((flag & 0xFF) != 0) {
		uint32_t object208 = LOAD32(loader + 0x208);
		uint32_t vtable208 = LOAD32(object208);
		uint32_t vtable20C = LOAD32(LOAD32(loader + 0x20C));
		uint32_t method208 = LOAD32(vtable208 + 4);
		ctx.r1.u64 = stack;
		ctx.r3.u64 = object208;
		ctx.r4.u64 = flag;
		ctx.r9.u64 = method208;
		ctx.r10.u64 = vtable208;
		REX_CALL_INDIRECT_FUNC(method208);
		uint64_t result208 = ctx.r3.u64;

		// The pointer at 0x20C is read again after the call; its method comes from the vtable read before it.
		uint32_t object20C = LOAD32(loader + 0x20C);
		uint32_t method20C = LOAD32(vtable20C + 28);
		ctx.r3.u64 = stack + 80;
		ctx.r4.u64 = object20C;
		ctx.r5.u64 = object28;
		ctx.r6.u64 = result208;
		ctx.r8.u64 = method20C;
		REX_CALL_INDIRECT_FUNC(method20C);
		uint64_t result20C = ctx.r3.u64;

		CThing_CopyState(ctx, base, object28, result20C);
		r4ForD0488 = ctx.r4.u64;
	}

	uint32_t object248 = LOAD32(loader + 0x248);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForD0488;
	n_sub_822D0488(ctx, base, object248);

	uint64_t object8 = loaderAddr + 8;
	uint32_t method8 = LOAD32(LOAD32(loader + 8) + 16);
	ctx.r3.u64 = object8;
	ctx.r10.u64 = method8;
	REX_CALL_INDIRECT_FUNC(method8);
	uint64_t result8 = ctx.r3.u64;

	// Pass that result to the vtable+4 method of each object in the pointer array at 0x48 (count at 0x50). After every
	// call the end is recomputed from the current array and count; the position keeps stepping through the old one.
	uint32_t count = LOAD32(loader + 0x50);
	uint64_t position = LOAD32(loader + 0x48);
	uint64_t end = (uint64_t)(count << 2) + position;
	while ((uint32_t)position != (uint32_t)end) {
		uint32_t element = LOAD32((uint32_t)position);
		uint32_t elementMethod = LOAD32(LOAD32(element) + 4);
		ctx.r3.u64 = element;
		ctx.r4.u64 = result8;
		ctx.r8.u64 = end;
		ctx.r9.u64 = count;
		ctx.r10.u64 = elementMethod;
		REX_CALL_INDIRECT_FUNC(elementMethod);

		count = LOAD32((uint32_t)object28 + 0x28);
		position += 4;
		end = (uint64_t)(count << 2) + LOAD32((uint32_t)object28 + 0x20);
	}

	stack = PopStackFrame(stack, 336);
	ctx.r1.u64 = stack;
	return ctx.r3.u64;
}
PROMOTED_ENTRY(12, sub_822BE580, 0x822BE580) { ctx.r3.u64 = n_sub_822BE580(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CGameplanLoader_CallMemberVirtual(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(13, 0x822D13F8)) { ctx.r3.u64 = arg1; __imp__sub_822D13F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822D13F8);
	uint32_t member = LOAD32((uint32_t)arg1 + 524);
	uint32_t callTarget = LOAD32(LOAD32(member) + 16);
	ctx.r3.u64 = member;
	ctx.r10.u64 = callTarget;
	REX_CALL_INDIRECT_FUNC(callTarget);
	return ctx.r3.u64;
}
PROMOTED_ENTRY(13, sub_822D13F8, 0x822D13F8) { ctx.r3.u64 = CGameplanLoader_CallMemberVirtual(ctx, base, ctx.r3.u64); }

uint32_t CGameplanLoader_Construct(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr, uint64_t object208, uint64_t callbackArg, uint64_t r7Value) {
	constexpr int32_t g_820A0000 = int32_t(0x820A0000);
	constexpr int32_t str_TXT_820B0000_B_ = int32_t(0x820B0000);
	constexpr int32_t str_TXT_820FD748_B_ = int32_t(0x820FD748);
	constexpr int32_t g_820FE3BC = int32_t(0x820FE3BC);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BB39F8)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = object208; ctx.r5.u64 = callbackArg; ctx.r7.u64 = r7Value; __imp__sub_82BB39F8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BB39F8);
	uint32_t stack = ctx.r1.u64;
	PPCXERRegister flags{};
	flags.so = ctx.xer.so;
	flags.ov = ctx.xer.ov;
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);
	// Each allocation below starts with a 16-byte header (this magic, then the size); the object follows it.
	const uint32_t allocationMagic = 0x1337F1D0u;

	stack = PushStackFrame(base, stack, 144);
	gameplanLoader->vtable = 0x82002F88u;

	// state the callee may pass on; r7 is also read back for the next call
	ctx.r1.u64 = stack;
	ctx.r4.u64 = object208;
	ctx.r5.u64 = callbackArg;
	ctx.r7.u64 = r7Value;
	n_sub_82BBB1C8(ctx, base, gameplanLoaderAddr + 8);

	uint64_t result28 = n_sub_82BE7460(ctx, base, gameplanLoaderAddr + 40, ctx.r7.u64, ctx.r8.u64);

	gameplanLoader->m_208 = uint32_t(object208);
	gameplanLoader->m_20C = 0u;
	gameplanLoader->m_210 = 0u;

	// state the callee may pass on
	ctx.r3.u64 = result28;
	ctx.r8.s64 = str_TXT_82100000_B_;
	uint64_t allocator = Allocator_GetInstance(ctx, base);

	uint64_t block210 = n_sub_82BA8F18(ctx, base, allocator, 160,
	                                   uint64_t(int64_t(str_TXT_82100000_B_) - 7568),
	                                   uint64_t(int64_t(-2112888328)), 63);
	flags.ca = (uint32_t)block210 > 4294967279u;
	uint64_t object210Addr = block210 + 16;
	STORE32((uint32_t)block210, allocationMagic);
	STORE32((uint32_t)block210 + 4, 160u);
	uint32_t object210 = 0;
	if ((int32_t)object210Addr != 0) {
		ctx.xer.ca = flags.ca;
		object210 = n_sub_82BC0E68(ctx, base, object210Addr, block210);
		flags.ca = ctx.xer.ca;
	}
	gameplanLoader->m_210 = object210;

	uint64_t object214 = gameplanLoaderAddr + 532;
	gameplanLoader->m_214 = uint32_t(g_820FE3BC);
	gameplanLoader->m_238 = 0u;
	ctx.fpscr.disableFlushMode();
	double value244 = double(LOAD_F32((uint32_t)g_820A0000 - 16596));
	gameplanLoader->m_23C = 0u;
	gameplanLoader->m_244 = float(value244);
	gameplanLoader->m_240 = 0u;

	uint64_t object218 = object214 + 4;
	ctx.xer.ca = flags.ca;
	n_sub_82CA3EB8(ctx, base, object218, 32,
	               uint64_t(int64_t(str_TXT_820B0000_B_) - 6332),
	               uint64_t(int64_t(str_TXT_82100000_B_) - 7544),
	               str_TXT_820B0000_B_, str_TXT_82100000_B_, g_820FE3BC, g_820A0000);
	flags.ca = ctx.xer.ca;
	n_sub_82BBF648(ctx, base, object218, 0);
	flags.ca = ctx.xer.ca;

	gameplanLoader->m_248 = 0u;
	gameplanLoader->m_EventCallback = 0u;
	gameplanLoader->m_254 = 0u;
	// The pointer stored at 0x20C is returned by the function whose address is stored at 0x8331497C.
	uint32_t globalFunction = LOAD32((uint32_t)g_83310000 + 18812);
	ctx.r3.u64 = callbackArg;
	ctx.r5.u64 = globalFunction;
	ctx.r6.s64 = g_83310000;
	REX_CALL_INDIRECT_FUNC(globalFunction);
	uint32_t object20C = ctx.r3.u32;
	flags.ca = ctx.xer.ca;
	gameplanLoader->m_20C = object20C;

	ctx.r3.s64 = str_TXT_82100000_B_;
	uint64_t allocator2 = Allocator_GetInstance(ctx, base);
	flags.ca = ctx.xer.ca;
	uint64_t block248 = n_sub_82BA8F18(ctx, base, allocator2, 172,
	                                   uint64_t(int64_t(str_TXT_82100000_B_) - 10316),
	                                   uint64_t(str_TXT_820FD748_B_), 57);
	flags.ca = (uint32_t)block248 > 4294967279u;
	uint64_t object248Addr = block248 + 16;
	STORE32((uint32_t)block248, allocationMagic);
	STORE32((uint32_t)block248 + 4, 172u);
	uint32_t object248 = 0;
	if ((int32_t)object248Addr != 0) {
		ctx.xer.ca = flags.ca;
		object248 = n_sub_82BBDE60(ctx, base, object248Addr, uint32_t(gameplanLoaderAddr), uint32_t(object214), ctx.r7.u64, ctx.r8.u64);
		flags.ca = ctx.xer.ca;
	}

	// The object at 0x208 gets a pointer back to this loader at +168.
	uint32_t storedObject208 = gameplanLoader->m_208;
	gameplanLoader->m_248 = object248;
	STORE32(storedObject208 + 168, uint32_t(gameplanLoaderAddr));
	stack = PopStackFrame(stack, 144);
	ctx.r1.u64 = stack;
	ctx.xer.ca = flags.ca;
	return uint32_t(gameplanLoaderAddr);
}
PROMOTED_ENTRY(87, sub_82BB39F8, 0x82BB39F8) { ctx.r3.u64 = CGameplanLoader_Construct(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r7.u64); }

uint64_t CGameplanLoader_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t object, uint64_t deleteFlags) {
	if (!UseLiftedCode(87, 0x82BB3B78)) { ctx.r3.u64 = object; ctx.r4.u64 = deleteFlags; __imp__sub_82BB3B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB3B78);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.r4.u64 = deleteFlags;
	CGameplanLoader_Destruct(ctx, base, object);
	if (((uint32_t)deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, object);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return object;
}
PROMOTED_ENTRY(87, sub_82BB3B78, 0x82BB3B78) { ctx.r3.u64 = CGameplanLoader_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint32_t CGameplanLoader_Destruct(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr) {
	if (!UseLiftedCode(87, 0x82BB3BC8)) { ctx.r3.u64 = gameplanLoaderAddr; __imp__sub_82BB3BC8(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82BB3BC8);
	uint32_t stack = ctx.r1.u64;
	PPCRegister callTarget{};
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);
	stack = PushStackFrame(base, stack, 96);

	uint32_t child248 = gameplanLoader->m_248;
	gameplanLoader->vtable = 0x82002F88u;
	if (child248 != 0) {
		ctx.r1.u64 = stack;
		n_sub_82BBDF38(ctx, base, child248);
		n_sub_82BAA458(ctx, base, gameplanLoader->m_248);
	}

	uint32_t child20C = gameplanLoader->m_20C;
	if (child20C != 0) {
		callTarget.u64 = LOAD32(LOAD32(child20C));
		ctx.r1.u64 = stack;
		ctx.r3.u64 = child20C;
		ctx.r4.u64 = 0;
		ctx.r10.u64 = callTarget.u64;
		REX_CALL_INDIRECT_FUNC(callTarget.u32);
		n_sub_82BAA458(ctx, base, gameplanLoader->m_20C);
	}

	ctx.r1.u64 = stack;
	n_sub_82BBCA68(ctx, base, gameplanLoaderAddr + 532);
	n_sub_82BBC8B8(ctx, base, gameplanLoaderAddr + 528);
	uint32_t result = n_sub_82BE7530(ctx, base, gameplanLoaderAddr + 40);

	gameplanLoader->m_8 = 0x820FD050u;
	gameplanLoader->vtable = 0x820B0BACu;
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BB3BC8, 0x82BB3BC8) { ctx.r3.u64 = CGameplanLoader_Destruct(ctx, base, ctx.r3.u64); }

uint64_t CGameplanLoader_LoadGameplanFile(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr, uint64_t gameplanName, uint32_t outIsBgf) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820FD7C4_B_ = int32_t(0x820FD7C4);
	constexpr int32_t str_TXT_820FD7C8_B_ = int32_t(0x820FD7C8);
	if (!UseLiftedCode(87, 0x82BB3C70)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = gameplanName; ctx.r5.u64 = outIsBgf; __imp__sub_82BB3C70(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB3C70);
	uint32_t stack = ctx.r1.u64;
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);

	stack = PushStackFrame(base, stack, 176);

	// Local CCharStrings on this frame (data pointer, then two 16-bit fields; the one at +6 plus one is the
	// size freed): the gameplan name at stack+80, the extension to compare with at stack+88, and the
	// name's extension at stack+96 (bgf test) or stack+104 (bgp test).
	uint32_t nameData = 0;
	STORE32(stack + 80, 0);
	STORE16(stack + 84, 0);
	STORE16(stack + 86, 0);
	if ((uint32_t)gameplanName != 0) {
		ctx.r1.u64 = stack;
		n_sub_82BA8850(ctx, base, stack + 80, gameplanName, -1);
		nameData = LOAD32(stack + 80);
	}

	STORE32(stack + 88, 0);
	STORE16(stack + 92, 0);
	STORE16(stack + 94, 0);
	ctx.r1.u64 = stack;
	n_sub_82BA8850(ctx, base, stack + 88, str_TXT_820FD7C4_B_, -1);

	uint64_t extension = n_sub_82BAA310(ctx, base, stack + 96, stack + 80);
	uint64_t isBgf = CCharString_Equal(ctx, base, extension, stack + 88);

	// What r3/r4 hold at each free below in the original (the last result, and stack+88 or what the
	// previous free left in r4); handed over to Allocator_GetInstance.
	uint64_t liveR3 = isBgf;
	uint32_t liveR4 = stack + 88;
	uint32_t extensionData = LOAD32(stack + 96);
	if (extensionData != 0) {
		uint64_t extensionSize = (uint64_t)LOAD16(stack + 102) + 1;
		ctx.r3.u64 = liveR3;
		ctx.r4.u64 = liveR4;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		liveR3 = n_sub_82BA9068(ctx, base, allocator, extensionData, extensionSize);
		liveR4 = ctx.r4.u32;
		STORE32(stack + 96, 0);
		STORE16(stack + 100, 0);
		STORE16(stack + 102, 0);
	}
	uint32_t bgfData = LOAD32(stack + 88);
	if (bgfData != 0) {
		uint64_t bgfSize = (uint64_t)LOAD16(stack + 94) + 1;
		ctx.r3.u64 = liveR3;
		ctx.r4.u64 = liveR4;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		n_sub_82BA9068(ctx, base, allocator, bgfData, bgfSize);
	}

	uint64_t result = 0;
	if ((isBgf & 0xFF) != 0) {
		uint64_t nameArg = (nameData == 0) ? (uint64_t)g_82000C98 : nameData;
		uint32_t loadFunction = LOAD32(uint32_t(gameplanLoader->vtable) + 28);
		ctx.r3.u64 = gameplanLoaderAddr;
		ctx.r4.u64 = nameArg;
		ctx.r10.u64 = loadFunction;
		REX_CALL_INDIRECT_FUNC(loadFunction);
		result = ctx.r3.u64;
		liveR3 = result;
		STORE8(outIsBgf, uint8_t(1));
	} else {
		STORE32(stack + 88, 0);
		STORE16(stack + 92, 0);
		STORE16(stack + 94, 0);
		n_sub_82BA8850(ctx, base, stack + 88, str_TXT_820FD7C8_B_, -1);

		uint32_t bgpExtension = n_sub_82BAA310(ctx, base, stack + 104, stack + 80);
		uint32_t isBgp = CCharString_Equal(ctx, base, bgpExtension, stack + 88);

		// state the callee may pass on
		ctx.r4.u64 = stack + 88;
		n_sub_82BA8800(ctx, base, stack + 104);
		liveR3 = n_sub_82BA8800(ctx, base, stack + 88);

		if ((isBgp & 0xFF) != 0) {
			uint64_t nameArg = (nameData == 0) ? (uint64_t)g_82000C98 : nameData;
			liveR3 = n_sub_82BBE220(ctx, base, gameplanLoader->m_248, nameArg);
			STORE8(outIsBgf, uint8_t(0));
		}
	}

	// Release the gameplan name string at stack+80.
	if (nameData != 0) {
		uint64_t nameSize = (uint64_t)LOAD16(stack + 86) + 1;
		ctx.r3.u64 = liveR3;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		n_sub_82BA9068(ctx, base, allocator, nameData, nameSize);
	}

	stack = PopStackFrame(stack, 176);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BB3C70, 0x82BB3C70) { ctx.r3.u64 = CGameplanLoader_LoadGameplanFile(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u32); }

uint64_t n_sub_82BB3E38(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2) {
	if (!UseLiftedCode(87, 0x82BB3E38)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; __imp__sub_82BB3E38(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB3E38);
	uint32_t gameplanAsset = LOAD32((uint32_t)arg1 + 584);
	return n_sub_82BBE220(ctx, base, gameplanAsset, arg2);
}
PROMOTED_ENTRY(87, sub_82BB3E38, 0x82BB3E38) { ctx.r3.u64 = n_sub_82BB3E38(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// Appends the hash of the string at stringAddr to the growable u32 array at m_248 + 104 (n_sub_82BAE368 grows it
// when full and takes the element by address); returns the address of the new element.
uint64_t n_sub_82BB3E40(CpuState& ctx, uint8_t* base, uint32_t gameplanLoaderAddr, uint32_t stringAddr) {
	if (!UseLiftedCode(87, 0x82BB3E40)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = stringAddr; __imp__sub_82BB3E40(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB3E40);
	uint32_t stack = ctx.r1.u64;
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint32_t stringHash = String_HashLimited100(ctx, base, stringAddr);
	STORE32(stack + 80, stringHash);
	uint64_t hashArray = (uint64_t)gameplanLoader->m_248 + 104;
	uint64_t newElement = n_sub_82BAE368(ctx, base, hashArray, stack + 80);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return newElement;
}
PROMOTED_ENTRY(87, sub_82BB3E40, 0x82BB3E40) { ctx.r3.u64 = n_sub_82BB3E40(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// Gets the instance for `name` from the object at gameplanLoader + 40, publishes m_248 and two C functions as Lua
// globals, then lets the handler in m_210 and the presentation source in m_20C take the instance. Returns the
// instance, or 0 when the handler declines it or no presentation is made (the loader's virtual at vtable + 32
// then receives the instance).
uint64_t n_sub_82BB3E88(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr, uint64_t name) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820FE5E8_B_ = int32_t(0x820FE5E8);
	constexpr int32_t str_TXT_820FE608_B_ = int32_t(0x820FE608);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_82BC0000 = int32_t(0x82BC0000);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	constexpr int32_t str_TXT_820FE5F4_B_ = int32_t(0x820FE5F4);
	constexpr int32_t str_TXT_820FD7CC_B_ = int32_t(0x820FD7CC);
	constexpr int32_t kLuaGlobalsIndex = -10002;
	constexpr uint32_t TXT_820FE5F4_R_Fn = 0x82BBF3F0u;
	constexpr uint32_t TXT_820FE608_R_Fn = 0x82BBF4D8u;
	if (!UseLiftedCode(87, 0x82BB3E88)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = name; __imp__sub_82BB3E88(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB3E88);
	uint32_t stack = ctx.r1.u64;
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);

	stack = PushStackFrame(base, stack, 160);

	// local CCharString at stack+88 holding a copy of the name
	STORE16(stack + 92, 0);
	STORE16(stack + 94, 0);
	STORE32(stack + 88, 0);
	uint32_t nameChars = 0;
	if ((uint32_t)name != 0) {
		ctx.r1.u64 = stack;
		n_sub_82BA8850(ctx, base, (uint64_t)stack + 88, name, -1);
		nameChars = LOAD32(stack + 88);
	}
	// the copied characters, or the empty string at 0x82000C98: never zero
	const uint64_t nameOrEmpty = (nameChars != 0) ? (uint64_t)nameChars : (uint64_t)g_82000C98;

	ctx.r1.u64 = stack;
	uint64_t instance = n_sub_82BE75D8(ctx, base, gameplanLoaderAddr + 40, nameOrEmpty, (uint32_t)gameplanLoaderAddr);
	// r3 as the last call of each path leaves it; Allocator_GetInstance receives it at the end
	uint64_t lastR3 = instance;

	if ((uint32_t)instance != 0) {
		const uint32_t instanceAddr = (uint32_t)instance;

		uint32_t instanceVfn72 = LOAD32(LOAD32(instanceAddr) + 72);
		ctx.r3.u64 = instance;
		ctx.r4.u64 = nameOrEmpty;
		ctx.r10.u64 = instanceVfn72;
		REX_CALL_INDIRECT_FUNC(instanceVfn72);

		// returns the object that holds a Lua state at +4
		uint32_t scriptContextFn = LOAD32(0x83314980u);
		ctx.r3.u64 = instance;
		ctx.r8.u64 = scriptContextFn;
		ctx.r9.s64 = g_83310000;
		REX_CALL_INDIRECT_FUNC(scriptContextFn);
		uint64_t scriptContext = ctx.r3.u64;

		uint32_t instanceVtable = LOAD32(instanceAddr);
		uint32_t instanceVfn16 = LOAD32(instanceVtable + 16);
		ctx.r3.u64 = instance;
		ctx.r4.u64 = scriptContext;
		ctx.r6.u64 = instanceVfn16;
		ctx.r7.u64 = instanceVtable;
		REX_CALL_INDIRECT_FUNC(instanceVfn16);

		uint32_t eventCallback = gameplanLoader->m_EventCallback;
		if (eventCallback != 0) {
			uint32_t eventCallbackContext = gameplanLoader->m_EventCallbackContext;
			ctx.r3.u64 = 2;
			ctx.r4.u64 = instance;
			ctx.r5.u64 = 0;
			ctx.r6.u64 = eventCallbackContext;
			REX_CALL_INDIRECT_FUNC(eventCallback);
		}

		n_sub_82BBF6D8(ctx, base, (uint32_t)gameplanLoaderAddr + 532, LOAD32((uint32_t)scriptContext + 4));

		// m_248 pushed as a light userdata (value, type tag 2, top += 8), then stored as a Lua global; the two C
		// functions are pushed and stored as globals the same way
		uint32_t gameplanValue = gameplanLoader->m_248;
		uint32_t luaState = LOAD32((uint32_t)scriptContext + 4);
		uint32_t top = LOAD32(luaState + 8);
		STORE32(top, gameplanValue);
		STORE32(top + 4, 2u);
		uint64_t newTop = (uint64_t)LOAD32(luaState + 8) + 8;
		STORE32(luaState + 8, (uint32_t)newTop);
		// state the callee may pass on
		ctx.r7.u64 = newTop;
		ctx.r8.u64 = top;
		ctx.r9.u64 = gameplanValue;
		n_sub_82BC5EB0(ctx, base, luaState, kLuaGlobalsIndex, (uint64_t)str_TXT_820FE5E8_B_);

		// r6-r8 carry the register values the original passed along
		n_sub_8227B7E0(ctx, base, luaState, TXT_820FE5F4_R_Fn, 0, g_82BC0000, ctx.r7.u64, ctx.r8.u64);
		n_sub_82BC5EB0(ctx, base, luaState, kLuaGlobalsIndex, (uint64_t)str_TXT_820FE5F4_B_);
		n_sub_8227B7E0(ctx, base, luaState, TXT_820FE608_R_Fn, 0, ctx.r6.u64, ctx.r7.u64, ctx.r8.u64);
		n_sub_82BC5EB0(ctx, base, luaState, kLuaGlobalsIndex, (uint64_t)str_TXT_820FE608_B_);

		uint32_t fnAt83314984 = LOAD32(0x83314984u);
		ctx.r3.u64 = instance;
		ctx.r10.u64 = fnAt83314984;
		REX_CALL_INDIRECT_FUNC(fnAt83314984);
		STORE32(instanceAddr + 32, ctx.r3.u32);

		// second CCharString at stack+80 with the same name, for the handler
		STORE32(stack + 80, 0);
		STORE16(stack + 84, 0);
		STORE16(stack + 86, 0);
		n_sub_82BA8850(ctx, base, (uint64_t)stack + 80, nameOrEmpty, -1);
		// r4 as the last call leaves it; n_sub_82BA8800 receives it below
		uint64_t lastR4 = ctx.r4.u64;

		uint32_t handled = 0;
		uint32_t handler = gameplanLoader->m_210;
		if (handler != 0) {
			uint32_t matched = n_sub_82BBC920(ctx, base, handler, (uint64_t)stack + 80);
			lastR4 = ctx.r4.u64;
			if ((matched & 0xFF) != 0) {
				// read again after the match call
				uint32_t matchedHandler = gameplanLoader->m_210;
				if (matchedHandler != 0) {
					uint32_t handlerVfn12 = LOAD32(LOAD32(matchedHandler) + 12);
					ctx.r3.u64 = matchedHandler;
					ctx.r4.u64 = (uint64_t)stack + 80;
					ctx.r5.u64 = instance;
					ctx.r10.u64 = handlerVfn12;
					REX_CALL_INDIRECT_FUNC(handlerVfn12);
					handled = ctx.r3.u32;
					lastR4 = ctx.r4.u64;
				}
			}
		}

		// state the callee may pass on
		ctx.r4.u64 = lastR4;
		n_sub_82BA8800(ctx, base, (uint64_t)stack + 80);

		if ((handled & 0xFF) != 0) {
			uint32_t presentationSource = gameplanLoader->m_20C;
			uint32_t sourceVfn4 = LOAD32(LOAD32(presentationSource) + 4);
			ctx.r3.u64 = presentationSource;
			ctx.r4.u64 = instance;
			ctx.r10.u64 = sourceVfn4;
			REX_CALL_INDIRECT_FUNC(sourceVfn4);
			uint32_t presentation = ctx.r3.u32;
			if (presentation != 0) {
				uint32_t instanceField476 = LOAD32(instanceAddr + 476);
				uint32_t presentationVfn8 = LOAD32(LOAD32(presentation) + 8);
				// r3 still holds the presentation
				ctx.r4.u64 = instanceField476;
				ctx.r10.u64 = presentationVfn8;
				REX_CALL_INDIRECT_FUNC(presentationVfn8);

				uint32_t object32 = LOAD32(instanceAddr + 32);
				lastR3 = object32;
				if (object32 != 0) {
					uint32_t object32Vfn8 = LOAD32(LOAD32(object32) + 8);
					ctx.r3.u64 = object32;
					ctx.r10.u64 = object32Vfn8;
					REX_CALL_INDIRECT_FUNC(object32Vfn8);
					lastR3 = ctx.r3.u64;
				}

				uint32_t eventCallback2 = gameplanLoader->m_EventCallback;
				if (eventCallback2 != 0) {
					uint32_t eventCallbackContext2 = gameplanLoader->m_EventCallbackContext;
					ctx.r3.u64 = 0;
					ctx.r4.u64 = instance;
					ctx.r5.u64 = 0;
					ctx.r6.u64 = eventCallbackContext2;
					REX_CALL_INDIRECT_FUNC(eventCallback2);
					lastR3 = ctx.r3.u64;
				}
			} else {
				uint32_t loaderVfn32 = LOAD32((uint32_t)gameplanLoader->vtable + 32);
				ctx.r3.u64 = gameplanLoaderAddr;
				ctx.r4.u64 = instance;
				ctx.r10.u64 = loaderVfn32;
				REX_CALL_INDIRECT_FUNC(loaderVfn32);

				uint32_t logFn = LOAD32(0x83314A7Cu);
				ctx.r3.u64 = 2;
				ctx.r4.u64 = (uint64_t)str_TXT_820FD7CC_B_;
				ctx.r7.u64 = logFn;
				ctx.r8.s64 = str_TXT_82100000_B_;
				ctx.r9.s64 = g_83310000;
				REX_CALL_INDIRECT_FUNC(logFn);
				lastR3 = ctx.r3.u64;
				instance = 0;
			}
		} else {
			uint32_t loaderVfn32 = LOAD32((uint32_t)gameplanLoader->vtable + 32);
			ctx.r3.u64 = gameplanLoaderAddr;
			ctx.r4.u64 = instance;
			ctx.r10.u64 = loaderVfn32;
			REX_CALL_INDIRECT_FUNC(loaderVfn32);
			lastR3 = ctx.r3.u64;
			instance = 0;
		}
	}

	// release the name CCharString at stack+88
	if (nameChars != 0) {
		uint64_t nameBufferSize = (uint64_t)LOAD16(stack + 94) + 1;
		// state the callee may pass on
		ctx.r3.u64 = lastR3;
		uint64_t allocator = Allocator_GetInstance(ctx, base);
		n_sub_82BA9068(ctx, base, allocator, nameChars, nameBufferSize);
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return instance;
}
PROMOTED_ENTRY(87, sub_82BB3E88, 0x82BB3E88) { ctx.r3.u64 = n_sub_82BB3E88(ctx, base, ctx.r3.u64, ctx.r4.u64); }

void CGameplanLoader_SetEventCallback(CpuState& ctx, uint8_t* base, uint32_t gameplanLoaderAddr, uint32_t eventCallback, uint32_t callbackContext) {
	if (!UseLiftedCode(87, 0x82BB4268)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = eventCallback; ctx.r5.u64 = callbackContext; __imp__sub_82BB4268(ctx, base); return; }
	LiftedFrame frame(0x82BB4268);
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);
	gameplanLoader->m_EventCallback = eventCallback;
	gameplanLoader->m_EventCallbackContext = callbackContext;
	return;
}
PROMOTED_ENTRY(87, sub_82BB4268, 0x82BB4268) { CGameplanLoader_SetEventCallback(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32); }

// sub_82BB4278  [8 bytes]
uint64_t n_sub_82BB4278(CpuState& ctx, uint8_t* base, uint64_t loaderAddress) {
	if (!UseLiftedCode(87, 0x82BB4278)) { ctx.r3.u64 = loaderAddress; __imp__sub_82BB4278(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB4278);
	uint32_t loader = (uint32_t)loaderAddress;
	return LOAD32(loader + 0x20C);
}
PROMOTED_ENTRY(87, sub_82BB4278, 0x82BB4278) { ctx.r3.u64 = n_sub_82BB4278(ctx, base, ctx.r3.u64); }

// sub_82BB4280  [8 bytes]
uint64_t n_sub_82BB4280(CpuState& ctx, uint8_t* base, uint64_t arg1) {
	if (!UseLiftedCode(87, 0x82BB4280)) { ctx.r3.u64 = arg1; __imp__sub_82BB4280(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB4280);
	// address of the CGameplanLoader sub-object at offset 0x214
	return arg1 + 0x214;
}
PROMOTED_ENTRY(87, sub_82BB4280, 0x82BB4280) { ctx.r3.u64 = n_sub_82BB4280(ctx, base, ctx.r3.u64); }

// sub_82BB4288  [8 bytes]
uint64_t n_sub_82BB4288(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr) {
	if (!UseLiftedCode(87, 0x82BB4288)) { ctx.r3.u64 = gameplanLoaderAddr; __imp__sub_82BB4288(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB4288);
	return GameObject<CGameplanLoader>(base, gameplanLoaderAddr)->m_208;
}
PROMOTED_ENTRY(87, sub_82BB4288, 0x82BB4288) { ctx.r3.u64 = n_sub_82BB4288(ctx, base, ctx.r3.u64); }

// sub_82BB4290  [8 bytes]
void n_sub_82BB4290(CpuState& ctx, uint8_t* base, uint32_t gameplanLoaderAddr, uint32_t arg2) {
	if (!UseLiftedCode(87, 0x82BB4290)) { ctx.r3.u64 = gameplanLoaderAddr; ctx.r4.u64 = arg2; __imp__sub_82BB4290(ctx, base); return; }
	LiftedFrame frame(0x82BB4290);
	CGameplanLoader* gameplanLoader = GameObject<CGameplanLoader>(base, gameplanLoaderAddr);
	gameplanLoader->m_254 = arg2;
	return;
}
PROMOTED_ENTRY(87, sub_82BB4290, 0x82BB4290) { n_sub_82BB4290(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82BB4298  [8 bytes]
// Returns the value n_sub_82BB4290 stores.
uint64_t n_sub_82BB4298(CpuState& ctx, uint8_t* base, uint64_t gameplanLoaderAddr) {
	if (!UseLiftedCode(87, 0x82BB4298)) { ctx.r3.u64 = gameplanLoaderAddr; __imp__sub_82BB4298(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BB4298);
	return GameObject<CGameplanLoader>(base, gameplanLoaderAddr)->m_254;
}
PROMOTED_ENTRY(87, sub_82BB4298, 0x82BB4298) { ctx.r3.u64 = n_sub_82BB4298(ctx, base, ctx.r3.u64); }
