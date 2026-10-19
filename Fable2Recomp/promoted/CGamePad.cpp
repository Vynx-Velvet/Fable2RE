// CGamePad (vtable 0x82002D38): methods of the class as readable C++.
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

// Turns a trigger's travel past a 5-unit dead zone into a 0..254 level. When the level changed and the trigger
// crossed between released and engaged, queues a kind-13 (engaged) or kind-15 (released) event for the button;
// while it stays engaged, rewrites the magnitude of this button's kind-14 events already in the pad's list.
uint32_t CGamePad_QueueTriggerEvents(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr, uint32_t triggerValue, uint32_t previousTriggerValue, uint32_t buttonId, uint64_t eventQueue, double timeStamp) {
	if (!UseLiftedCode(0, 0x82188D40)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = triggerValue; ctx.r5.u64 = previousTriggerValue; ctx.r6.u64 = buttonId; ctx.r7.u64 = eventQueue; ctx.f1.f64 = timeStamp; __imp__sub_82188D40(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82188D40);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	// values left in f1, f11 and XER[CA] for the caller
	double f1Value = timeStamp;
	PPCRegister f11Value = ctx.f11;
	stack = PushStackFrame(base, stack, 304);

	// Travel beyond the dead zone, negative travel counting as 0, times 256 / 251.
	int32_t travel = (int32_t)(triggerValue & 0xFF) - 5;
	int32_t previousTravel = (int32_t)(previousTriggerValue & 0xFF) - 5;
	bool carry = previousTravel < 0;
	uint32_t scaled = uint32_t(travel < 0 ? 0 : travel) << 8;
	uint32_t previousScaled = uint32_t(previousTravel < 0 ? 0 : previousTravel) << 8;
	int32_t level = (int32_t)scaled / 251;
	int32_t previousLevel = (int32_t)previousScaled / 251;

	uint32_t result;
	if (level == previousLevel) {
		// r3 still holds the scaled travel
		result = scaled;
	} else {
		// 56-byte event record built on the stack
		uint32_t event = stack + 96;
		double defaultValue = double(LOAD_F32(0x820994B4u));
		STORE32(stack + 140, 0);
		STORE32(stack + 136, 0);
		STORE_F32(stack + 144, float(defaultValue));
		STORE32(stack + 132, 0);
		STORE_F32(stack + 148, float(defaultValue));
		STORE64(event, 0);
		STORE64(event + 8, 0);
		STORE64(event + 16, 0);
		STORE64(event + 24, 0);
		STORE32(event + 32, 0);

		// state the callee may pass on
		ctx.r1.u64 = stack;
		ctx.xer.ca = carry;
		result = Time_GetElapsedSeconds(ctx, base);
		double elapsedSeconds = ctx.f1.f64;
		f1Value = elapsedSeconds;

		int32_t eventKind = level > 0 ? 13 : 15;
		// the level becomes a double through the stack; f11 keeps its integer bits
		STORE64(stack + 80, (uint64_t)(int64_t)level);
		ctx.fpscr.disableFlushMode();
		f11Value.f64 = LOAD_F64(stack + 80);
		ctx.fpscr.disableFlushMode();
		double levelValue = double(f11Value.s64);

		double elapsedF = double(float(elapsedSeconds));
		STORE_F32(stack + 144, float(elapsedF));
		STORE_F32(stack + 148, float(elapsedF));
		STORE8(stack + 104, (uint8_t)buttonId);
		STORE32(stack + 132, 1u);
		STORE32(stack + 140, eventKind);
		double levelScale = double(LOAD_F32(0x82000A8Cu));
		double magnitude = double(float(double(float(levelValue)) * levelScale));
		STORE_F32(stack + 108, float(magnitude));

		if ((level > 0) != (previousLevel > 0)) {
			uint32_t queuedEvent = stack + 160;
			STORE32(stack + 136, uint32_t(gamePad->m_PadIndex));
			memcpy(ctx, base, queuedEvent, event, 56);
			ctx.fpscr.disableFlushMode();
			STORE_F64(stack + 224, timeStamp);
			STORE8(stack + 216, 0);
			// state the callee may pass on
			ctx.f11 = f11Value;
			result = n_sub_829FA5E8(ctx, base, eventQueue, queuedEvent);
			f1Value = ctx.f1.f64;
			f11Value = ctx.f11;
			carry = ctx.xer.ca;
		} else {
			// The list object sits at +8 and its head node pointer at +12 (m_EventList). Each step re-checks
			// that the node is not the head, as the original's container checks do (ppc_trap only warns).
			uint32_t head = gamePad->m_EventList;
			ctx.fpscr.disableFlushMode();
			uint32_t node = head;
			for (;;) {
				node = LOAD32(node);
				if (node == head) break;
				uint32_t listHead = gamePad->m_EventList;
				if (node == listHead) ppc_trap(ctx, base, 22);
				if (int32_t(LOAD32(node + 52)) == 14) {
					if (node == listHead) ppc_trap(ctx, base, 22);
					if (int32_t(LOAD8(node + 16)) == (int32_t)buttonId) {
						if (node == listHead) ppc_trap(ctx, base, 22);
						ctx.fpscr.disableFlushMode();
						STORE_F32(node + 20, float(magnitude));
					}
				}
				if (node == uint32_t(gamePad->m_EventList)) ppc_trap(ctx, base, 22);
			}
		}
	}
	stack = PopStackFrame(stack, 304);
	// callers read f1, f11 and XER[CA] after the call
	ctx.r1.u64 = stack;
	ctx.f1.f64 = f1Value;
	ctx.f11 = f11Value;
	ctx.xer.ca = carry;
	return result;
}
PROMOTED_ENTRY(0, sub_82188D40, 0x82188D40) { ctx.r3.u64 = CGamePad_QueueTriggerEvents(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64, ctx.f1.f64); }

// Queues a kind-13 (pressed) or kind-15 (released) event for one button, stamped with the current time.
uint32_t CGamePad_QueueButtonEvent(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr, uint32_t padStateAddr, uint32_t buttonMask, uint32_t buttonId, uint64_t eventQueue, double timeStamp) {
	if (!UseLiftedCode(0, 0x82188F20)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = padStateAddr; ctx.r5.u64 = buttonMask; ctx.r6.u64 = buttonId; ctx.r7.u64 = eventQueue; ctx.f1.f64 = timeStamp; __imp__sub_82188F20(ctx, base); return ctx.r3.u32; }
	LiftedFrame frame(0x82188F20);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	double entryF8 = ctx.f8.f64;
	stack = PushStackFrame(base, stack, 304);

	uint32_t pressedBits = LOAD16(padStateAddr) & buttonMask;
	// 56-byte event record built on the stack
	uint32_t event = stack + 96;
	double defaultValue = double(LOAD_F32(0x820994B4u));
	STORE32(stack + 140, 0);
	STORE32(stack + 136, 0);
	STORE32(stack + 132, 0);
	STORE_F32(stack + 144, float(defaultValue));
	STORE_F32(stack + 148, float(defaultValue));
	STORE64(event, 0);
	STORE64(event + 8, 0);
	STORE64(event + 16, 0);
	STORE64(event + 24, 0);
	STORE32(event + 32, 0);

	ctx.r1.u64 = stack;
	Time_QueryTimebase(ctx, base, stack + 80);
	ctx.fpscr.disableFlushMode();
	PPCRegister timebase{};
	timebase.u64 = LOAD64(stack + 80);
	double ticks = double(timebase.s64);
	double tickDelta = ticks - LOAD_F64(0x83496EC0u);
	double tickRate = LOAD_F64(0x83496EC8u);
	double elapsed = tickDelta / tickRate;
	double elapsedF = double(float(elapsed));
	STORE_F32(stack + 148, float(elapsedF));
	STORE_F32(stack + 144, float(elapsedF));

	// The two paths left different values in f8-f12, which the queue call receives.
	uint32_t eventKind;
	double f8Value, f9Value, f10Value, f11Value;
	PPCRegister f12Value{};
	if (pressedBits != 0) {
		eventKind = 13;
		double pressedValue = double(LOAD_F32(0x820994C0u));
		STORE_F32(stack + 108, float(pressedValue));
		f8Value = entryF8;
		f9Value = elapsedF;
		f10Value = elapsed;
		f11Value = tickDelta;
		f12Value.f64 = ticks;
	} else {
		eventKind = 15;
		STORE_F32(stack + 108, float(defaultValue));
		f8Value = elapsedF;
		f9Value = elapsed;
		f10Value = tickDelta;
		f11Value = ticks;
		f12Value = timebase;
	}

	STORE8(stack + 104, (uint8_t)buttonId);
	STORE32(stack + 132, 1u);
	STORE32(stack + 140, eventKind);
	STORE32(stack + 136, uint32_t(gamePad->m_PadIndex));
	uint32_t queuedEvent = stack + 160;
	memcpy(ctx, base, queuedEvent, event, 56);
	ctx.fpscr.disableFlushMode();
	STORE_F64(stack + 224, timeStamp);
	STORE8(stack + 216, 0);
	// state the callee may pass on
	ctx.f1.f64 = timeStamp;
	ctx.f8.f64 = f8Value;
	ctx.f9.f64 = f9Value;
	ctx.f10.f64 = f10Value;
	ctx.f11.f64 = f11Value;
	ctx.f12 = f12Value;
	ctx.f13.f64 = tickRate;
	uint32_t result = n_sub_829FA5E8(ctx, base, eventQueue, queuedEvent);
	stack = PopStackFrame(stack, 304);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(0, sub_82188F20, 0x82188F20) { ctx.r3.u64 = CGamePad_QueueButtonEvent(ctx, base, ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u64, ctx.f1.f64); }

// When the pad's state can be read: passes the elapsed time to the member at +72, then clamps both motor speeds
// to 0..1 (constants at 0x820994B4 / 0x820994C0), scales them by 65535 and sends them to the pad as its vibration.
uint64_t n_sub_822B36F8(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr) {
	if (!UseLiftedCode(12, 0x822B36F8)) { ctx.r3.u64 = gamePadAddr; __imp__sub_822B36F8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B36F8);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	stack = PushStackFrame(base, stack, 128);

	// the pad index is passed in r3
	ctx.r1.u64 = stack;
	ctx.r3.u64 = gamePad->m_PadIndex;
	uint64_t result = GamePad_XamInputGetState(ctx, base, (uint64_t)stack + 96);

	if ((uint32_t)result == 0) {
		Time_QueryTimebase(ctx, base, stack + 80);
		ctx.fpscr.disableFlushMode();
		PPCRegister timebase{};
		timebase.f64 = LOAD_F64(stack + 80);
		double ticks = double(timebase.s64);
		double tickDelta = ticks - LOAD_F64(0x83496EC0u);
		double tickRate = LOAD_F64(0x83496EC8u);
		double elapsed = tickDelta / tickRate;
		// state the callee may pass on
		ctx.f12 = timebase;
		n_sub_8218C500(ctx, base, gamePadAddr + 72, double(float(elapsed)));

		// Branch-free compares: index 4 when value < limit or unordered, else 0, into the table at 0x82100170
		// (1.0, -1.0); the sign of the float read selects between two values.
		auto signTableIndex = [](double value, double limit) -> uint32_t {
			return (value < limit || std::isnan(value) || std::isnan(limit)) ? 4u : 0u;
		};
		const uint32_t signTable = 0x82100170u;

		ctx.fpscr.disableFlushMode();
		double leftSpeed = double(gamePad->m_LeftMotorSpeed);
		double rightSpeed = double(gamePad->m_RightMotorSpeed);
		uint32_t vibration = gamePad->m_VibrationState;
		double maxSpeed = double(LOAD_F32(0x820994C0u));
		double minSpeed = double(LOAD_F32(0x820994B4u));

		double leftMinSign = double(LOAD_F32(signTable + signTableIndex(leftSpeed, minSpeed)));
		double leftFloored = leftMinSign >= 0.0 ? leftSpeed : minSpeed;
		double rightMinSign = double(LOAD_F32(signTable + signTableIndex(rightSpeed, minSpeed)));
		double rightFloored = rightMinSign >= 0.0 ? rightSpeed : minSpeed;

		double leftOverMax = double(float(leftFloored - maxSpeed));
		double rightOverMax = double(float(rightFloored - maxSpeed));
		uint32_t leftMaxIndex = signTableIndex(leftOverMax, minSpeed);
		uint32_t rightMaxIndex = signTableIndex(rightOverMax, minSpeed);
		double leftMaxSign = double(LOAD_F32(signTable + leftMaxIndex));
		double leftClamped = leftMaxSign >= 0.0 ? maxSpeed : leftFloored;
		double rightMaxSign = double(LOAD_F32(signTable + rightMaxIndex));
		double rightClamped = rightMaxSign >= 0.0 ? maxSpeed : rightFloored;

		double motorScale = double(LOAD_F32(0x82000DACu));
		double leftScaled = double(float(leftClamped * motorScale));
		double rightScaled = double(float(rightClamped * motorScale));

		// Truncate to a 64-bit integer through the stack; its low 16 bits are the motor value.
		PPCRegister leftMotorBits{};
		leftMotorBits.s64 = std::isnan(leftScaled) ? int64_t(0x8000000000000000ULL) : leftScaled > double(LLONG_MAX) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&leftScaled));
		STORE_F64(stack + 80, leftMotorBits.f64);
		STORE16(vibration, uint16_t(LOAD16(stack + 86)));

		PPCRegister rightMotorBits{};
		rightMotorBits.s64 = std::isnan(rightScaled) ? int64_t(0x8000000000000000ULL) : rightScaled > double(LLONG_MAX) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&rightScaled));
		STORE_F64(stack + 80, rightMotorBits.f64);

		// m_VibrationState is read again after each store, as in the original.
		uint32_t vibrationForRight = gamePad->m_VibrationState;
		uint32_t rightMotorValue = LOAD16(stack + 86);
		STORE16(vibrationForRight + 2, (uint16_t)rightMotorValue);

		uint32_t vibrationToSend = gamePad->m_VibrationState;
		uint32_t padIndex = gamePad->m_PadIndex;
		// state the callee may pass on
		ctx.f5 = rightMotorBits;
		ctx.f6 = leftMotorBits;
		result = GamePad_XamInputSetVibration(ctx, base, padIndex, vibrationToSend);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822B36F8, 0x822B36F8) { ctx.r3.u64 = n_sub_822B36F8(ctx, base, ctx.r3.u32); }

// Reads the pad's capabilities and state; when both succeed, updates the pad from the new state, keeps a copy of
// the state's 12-byte gamepad block at +60 and flushes the pad's events.
uint64_t CGamePad_ProcessState(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr, uint64_t inputManager, double timeStamp) {
	if (!UseLiftedCode(12, 0x822B3848)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = inputManager; ctx.f1.f64 = timeStamp; __imp__sub_822B3848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822B3848);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);

	stack = PushStackFrame(base, stack, 160);
	uint32_t capabilitiesAddr = stack + 96;
	uint32_t stateAddr = stack + 80;

	// the callee takes its arguments from r3-r5: pad index, 1, output buffer
	ctx.r1.u64 = stack;
	ctx.r3.u64 = gamePad->m_PadIndex;
	ctx.r4.u64 = 1;
	ctx.r5.u64 = capabilitiesAddr;
	ctx.f1.f64 = timeStamp;
	uint64_t result = GamePad_XamInputGetCapabilities(ctx, base);

	if ((uint32_t)result == 0) {
		// the pad index is passed in r3
		ctx.r3.u64 = gamePad->m_PadIndex;
		result = GamePad_XamInputGetState(ctx, base, stateAddr);

		if ((uint32_t)result == 0) {
			ctx.fpscr.disableFlushMode();
			CGamePad_UpdateFromState(ctx, base, gamePadAddr, stateAddr, inputManager, timeStamp);

			// the 12 bytes after the state's leading 32-bit word, copied 16 bits at a time
			uint32_t dst = (uint32_t)gamePadAddr + 60;
			uint32_t src = stack + 84;
			for (int i = 0; i < 6; ++i) {
				STORE16(dst, LOAD16(src));
				dst += 2;
				src += 2;
			}

			ctx.fpscr.disableFlushMode();
			result = CGamePad_FlushEvents(ctx, base, gamePadAddr, inputManager, timeStamp);
		}
	}

	stack = PopStackFrame(stack, 160);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822B3848, 0x822B3848) { ctx.r3.u64 = CGamePad_ProcessState(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

// Reads the pad's state; when that succeeds, refreshes the pad's vibration (n_sub_822B36F8).
uint64_t CGamePad_UpdateRumble(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr) {
	if (!UseLiftedCode(12, 0x822BA4A8)) { ctx.r3.u64 = gamePadAddr; __imp__sub_822BA4A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x822BA4A8);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	stack = PushStackFrame(base, stack, 112);
	uint64_t stateBuffer = (uint64_t)stack + 80;
	// the pad index is passed in r3
	ctx.r1.u64 = stack;
	ctx.r3.u64 = gamePad->m_PadIndex;
	uint64_t result = GamePad_XamInputGetState(ctx, base, stateBuffer);
	if ((uint32_t)result == 0) {
		result = n_sub_822B36F8(ctx, base, gamePadAddr);
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(12, sub_822BA4A8, 0x822BA4A8) { ctx.r3.u64 = CGamePad_UpdateRumble(ctx, base, ctx.r3.u64); }

// sub_826FCFD8  [8 bytes]
double CGamePad_GetRightStickX(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr) {
	if (!UseLiftedCode(47, 0x826FCFD8)) { ctx.r3.u64 = gamePadAddr; __imp__sub_826FCFD8(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x826FCFD8);
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	ctx.fpscr.disableFlushMode();
	return double(gamePad->m_RightStickX);
}
PROMOTED_ENTRY(47, sub_826FCFD8, 0x826FCFD8) { ctx.f1.f64 = CGamePad_GetRightStickX(ctx, base, ctx.r3.u32); }

// sub_827E98A0  [8 bytes]
double CGamePad_GetRightStickY(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr) {
	if (!UseLiftedCode(55, 0x827E98A0)) { ctx.r3.u64 = gamePadAddr; __imp__sub_827E98A0(ctx, base); return ctx.f1.f64; }
	LiftedFrame frame(0x827E98A0);
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	ctx.fpscr.disableFlushMode();
	return double(gamePad->m_RightStickY);
}
PROMOTED_ENTRY(55, sub_827E98A0, 0x827E98A0) { ctx.f1.f64 = CGamePad_GetRightStickY(ctx, base, ctx.r3.u32); }

// Stops the pad's vibration, frees its vibration buffer and its lists, and frees the pad itself when bit 0 of
// deleteFlags is set. Returns the pad's address.
uint64_t CGamePad_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr, uint32_t deleteFlags) {
	if (!UseLiftedCode(88, 0x82BE3B78)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = deleteFlags; __imp__sub_82BE3B78(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3B78);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	stack = PushStackFrame(base, stack, 128);

	const uint32_t gamePadVtable = 0x82002D38u;
	// both motor speeds zero: stop the vibration
	uint32_t stopVibration = stack + 80;
	STORE32(stopVibration, 0);
	gamePad->vtable = gamePadVtable;

	uint32_t padIndex = gamePad->m_PadIndex;
	// state the callee may pass on
	ctx.r1.u64 = stack;
	GamePad_XamInputSetVibration(ctx, base, padIndex, stopVibration);

	uint32_t vibrationState = gamePad->m_VibrationState;
	HandleTarget_Free(ctx, base, vibrationState);
	gamePad->m_VibrationState = 0;

	List_DeleteAll(ctx, base, (uint32_t)gamePadAddr + 72);
	List_ClearFreeNodes(ctx, base, (uint32_t)gamePadAddr + 8);

	uint32_t eventList = gamePad->m_EventList;
	HandleTarget_Free(ctx, base, eventList);
	gamePad->m_EventList = 0;

	gamePad->vtable = 0x820EFB9Cu;
	if ((deleteFlags & 0x1) != 0) {
		HandleTarget_Free(ctx, base, gamePadAddr);
	}

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return gamePadAddr;
}
PROMOTED_ENTRY(88, sub_82BE3B78, 0x82BE3B78) { ctx.r3.u64 = CGamePad_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u32); }

uint64_t CGamePad_ReleaseAllButtons(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr, uint64_t eventQueue, double eventTime) {
	if (!UseLiftedCode(88, 0x82BE3C08)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = eventQueue; ctx.f1.f64 = eventTime; __imp__sub_82BE3C08(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3C08);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	stack = PushStackFrame(base, stack, 288);

	uint32_t eventListAddr = uint32_t(gamePadAddr) + 8;
	uint32_t eventData = stack + 80;    // 56-byte event description
	uint32_t eventBlock = stack + 144;  // copy of the description, then a byte at +56 and the event time at +64
	const double defaultTime = double(LOAD_F32(0x820994B4u));
	// f1 as the callees see it: the event time at first, then what the last queue call left there
	double f1State = eventTime;

	// queue a release event for every event in the list; m_EventList is its sentinel node
	uint32_t node = LOAD32(uint32_t(gamePad->m_EventList));
	while (node != uint32_t(gamePad->m_EventList)) {
		ctx.fpscr.disableFlushMode();
		STORE_F32(stack + 128, float(defaultTime));
		STORE_F32(stack + 132, float(defaultTime));
		STORE32(stack + 124, 0);
		STORE32(stack + 120, 0);
		STORE32(stack + 116, 0);
		STORE64(eventData, 0);
		STORE64(eventData + 8, 0);
		STORE64(eventData + 16, 0);
		STORE64(eventData + 24, 0);
		STORE32(eventData + 32, 0);

		double queuedEventTime = double(LOAD_F32(node + 60));
		double magnitude = double(LOAD_F32(node + 20));
		uint8_t buttonId = LOAD8(node + 16);

		STORE_F32(stack + 92, float(magnitude));
		STORE32(stack + 124, 15);  // released-button event kind, as in CGamePad_QueueButtonEvent
		STORE_F32(stack + 132, float(queuedEventTime));
		STORE32(stack + 116, 1);
		STORE8(stack + 88, buttonId);
		uint32_t padIndex = LOAD32(node + 48);
		STORE_F32(stack + 128, float(eventTime));
		STORE32(stack + 120, padIndex);

		ctx.r1.u64 = stack;
		memcpy(ctx, base, eventBlock, eventData, 56);
		ctx.fpscr.disableFlushMode();
		STORE_F64(stack + 208, eventTime);
		STORE8(stack + 200, 0);

		// state the callee may pass on
		ctx.f1.f64 = f1State;
		ctx.f13.f64 = queuedEventTime;
		n_sub_829FA5E8(ctx, base, eventQueue, eventBlock);
		f1State = ctx.f1.f64;

		// the queue call may have changed the list: advancing from its end is an error
		if (node == uint32_t(gamePad->m_EventList)) {
			ppc_trap(ctx, base, 22);
		}
		node = LOAD32(node);
	}

	ctx.r1.u64 = stack;
	ctx.f1.f64 = f1State;  // state the callee may pass on
	uint64_t result = List_ClearFreeNodes(ctx, base, eventListAddr);
	stack = PopStackFrame(stack, 288);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(88, sub_82BE3C08, 0x82BE3C08) { ctx.r3.u64 = CGamePad_ReleaseAllButtons(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint64_t n_sub_82BE3D48(CpuState& ctx, uint8_t* base, uint64_t arg1, uint64_t arg2, double floatArg1) {
	if (!UseLiftedCode(88, 0x82BE3D48)) { ctx.r3.u64 = arg1; ctx.r4.u64 = arg2; ctx.f1.f64 = floatArg1; __imp__sub_82BE3D48(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3D48);
	return CGamePad_ReleaseAllButtons(ctx, base, arg1, arg2, floatArg1);
}
PROMOTED_ENTRY(88, sub_82BE3D48, 0x82BE3D48) { ctx.r3.u64 = n_sub_82BE3D48(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint64_t CGamePad_StopVibration(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr) {
	if (!UseLiftedCode(88, 0x82BE3D50)) { ctx.r3.u64 = gamePadAddr; __imp__sub_82BE3D50(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3D50);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	stack = PushStackFrame(base, stack, 96);
	uint32_t padIndex = gamePad->m_PadIndex;
	uint64_t vibrationState = (uint64_t)stack + 80;  // both 16-bit motor values zero
	STORE32((uint32_t)vibrationState, 0u);
	ctx.r1.u64 = stack;
	uint64_t result = GamePad_XamInputSetVibration(ctx, base, padIndex, vibrationState);
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(88, sub_82BE3D50, 0x82BE3D50) { ctx.r3.u64 = CGamePad_StopVibration(ctx, base, ctx.r3.u64); }

uint64_t n_sub_82BE3E00(CpuState& ctx, uint8_t* base, uint64_t gamePadAddr, uint64_t shakeType, double fadeDuration) {
	if (!UseLiftedCode(88, 0x82BE3E00)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = shakeType; ctx.f1.f64 = fadeDuration; __imp__sub_82BE3E00(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3E00);
	uint32_t stack = ctx.r1.u32;
	uint64_t shakeList = gamePadAddr + 72;

	stack = PushStackFrame(base, stack, 128);
	uint32_t timebaseSlot = stack + 80;
	ctx.r1.u64 = stack;
	Time_QueryTimebase(ctx, base, timebaseSlot);
	ctx.fpscr.disableFlushMode();

	// current time in seconds, the same conversion of the timebase as Time_GetElapsedSeconds
	int64_t timebase = (int64_t)LOAD64(stack + 80);
	double nowSeconds = double(float((double(timebase) - LOAD_F64(0x83496EC0u)) / LOAD_F64(0x83496EC8u)));
	ScreenShakeList_SetFadeByType(ctx, base, shakeList, shakeType, nowSeconds, fadeDuration);

	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	// callers read r4, f1 and f2 after the call
	ctx.r4.u64 = shakeType;
	ctx.f1.f64 = nowSeconds;
	ctx.f2.f64 = fadeDuration;
	return shakeList;
}
PROMOTED_ENTRY(88, sub_82BE3E00, 0x82BE3E00) { ctx.r3.u64 = n_sub_82BE3E00(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.f1.f64); }

uint64_t CGamePad_ResetVibration(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr) {
	if (!UseLiftedCode(88, 0x82BE3E80)) { ctx.r3.u64 = gamePadAddr; __imp__sub_82BE3E80(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BE3E80);
	uint32_t stack = ctx.r1.u64;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);

	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	List_ClearFreeNodes(ctx, base, gamePadAddr + 0x48);

	ctx.fpscr.disableFlushMode();
	float resetMotorSpeed = LOAD_F32(0x820994B4u);
	gamePad->m_LeftMotorSpeed = resetMotorSpeed;
	gamePad->m_RightMotorSpeed = resetMotorSpeed;

	// clear both 16-bit motor values; the pointer is read again after the first store
	uint32_t vibrationState = gamePad->m_VibrationState;
	STORE16(vibrationState, 0);
	uint32_t vibrationStateAgain = gamePad->m_VibrationState;
	STORE16(vibrationStateAgain + 2, 0);

	uint32_t padIndex = gamePad->m_PadIndex;
	uint32_t stateBufferAddr = stack + 80;
	// state the callee may pass on: the input query takes the pad index from r3
	ctx.r10.s64 = int32_t(0x820A0000);  // high half of the motor-speed constant's address
	uint32_t getStateResult = GamePad_XamInputGetState(ctx, base, stateBufferAddr);
	if (getStateResult != 0) {
		stack = PopStackFrame(stack, 112);
		ctx.r1.u64 = stack;
		return 1;
	}

	uint32_t currentPadIndex = gamePad->m_PadIndex;
	uint32_t currentVibrationState = gamePad->m_VibrationState;
	uint32_t setVibrationResult = GamePad_XamInputSetVibration(ctx, base, currentPadIndex, currentVibrationState);
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return setVibrationResult == 0;
}
PROMOTED_ENTRY(88, sub_82BE3E80, 0x82BE3E80) { ctx.r3.u64 = CGamePad_ResetVibration(ctx, base, ctx.r3.u32); }

void CGamePad_SetLeftStick(CpuState& ctx, uint8_t* base, uint32_t gamePadAddr, uint64_t stickPair) {
	if (!UseLiftedCode(88, 0x82BE3F18)) { ctx.r3.u64 = gamePadAddr; ctx.r4.u64 = stickPair; __imp__sub_82BE3F18(ctx, base); return; }
	LiftedFrame frame(0x82BE3F18);
	uint32_t stack = ctx.r1.u32;
	CGamePad* gamePad = GameObject<CGamePad>(base, gamePadAddr);
	// stickPair is the raw 8-byte stick pair: high half = X, low half = Y.
	STORE64(stack + 24, stickPair);
	ctx.fpscr.disableFlushMode();
	gamePad->m_LeftStickX = LOAD_F32(stack + 24);
	gamePad->m_LeftStickY = LOAD_F32(stack + 28);
	return;
}
PROMOTED_ENTRY(88, sub_82BE3F18, 0x82BE3F18) { CGamePad_SetLeftStick(ctx, base, ctx.r3.u32, ctx.r4.u64); }
