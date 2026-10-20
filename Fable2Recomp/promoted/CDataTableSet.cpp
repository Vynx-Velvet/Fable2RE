// CDataTableSet (vtable 0x820FE3BC): methods of the class as readable C++.
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

uint64_t CDataTableSet_ScalarDeletingDtor(CpuState& ctx, uint8_t* base, uint64_t self, uint64_t deleteFlags) {
	if (!UseLiftedCode(87, 0x82BBCA18)) { ctx.r3.u64 = self; ctx.r4.u64 = deleteFlags; __imp__sub_82BBCA18(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBCA18);
	GameStackFrame stackFrame(ctx, base, 112);
	ctx.r4.u64 = deleteFlags;  // state the callee may pass on
	CDataTableSet_Destructor(ctx, base, self);
	if ((uint32_t(deleteFlags) & 0x1) != 0) {
		HandleTarget_Free(ctx, base, self);
	}
	return self;
}
PROMOTED_ENTRY(87, sub_82BBCA18, 0x82BBCA18) { ctx.r3.u64 = CDataTableSet_ScalarDeletingDtor(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82BBD248  [128 bytes]
uint64_t CDataTableSet_FindTableIndex(CpuState& ctx, uint8_t* base, uint32_t dataTableSetAddr, uint32_t tableName) {
	if (!UseLiftedCode(87, 0x82BBD248)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableName; __imp__sub_82BBD248(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD248);
	uint32_t stack = ctx.r1.u32;
	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;

	uint32_t tableNameHash = String_HashLimited100(ctx, base, tableName);
	int32_t tableCount = dataTableSet->m_TableCount;
	uint32_t tableSlot = dataTableSet->m_Tables;

	// each table keeps the hash of its name at offset 8
	for (int32_t tableIndex = 0; tableIndex < tableCount; tableIndex++, tableSlot += 4) {
		if (LOAD32(LOAD32(tableSlot) + 8) == tableNameHash) {
			stack = PopStackFrame(stack, 96);
			ctx.r1.u64 = stack;
			return uint64_t(tableIndex);
		}
	}

	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return uint64_t(-1);
}
PROMOTED_ENTRY(87, sub_82BBD248, 0x82BBD248) { ctx.r3.u64 = CDataTableSet_FindTableIndex(ctx, base, ctx.r3.u32, ctx.r4.u32); }

// sub_82BBD2C8  [128 bytes]
uint64_t CDataTableSet_FindColumnIndex(CpuState& ctx, uint8_t* base, uint32_t tableSet, uint64_t tableIndex, uint32_t columnName) {
	if (!UseLiftedCode(87, 0x82BBD2C8)) { ctx.r3.u64 = tableSet; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnName; __imp__sub_82BBD2C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD2C8);
	GameStackFrame stackFrame(ctx, base, 112);

	uint32_t table = CDataTableSet_GetTable(ctx, base, tableSet, tableIndex);
	uint32_t columnNameHash = String_HashLimited100(ctx, base, columnName);

	// the column descriptors are 12 bytes each, with the name hash at offset 4
	int32_t columnCount = LOAD32(table + 56);
	uint64_t columnIndex = 0;
	if (columnCount > 0) {
		uint32_t columnHashAddr = LOAD32(table + 48) + 4;
		do {
			if (LOAD32(columnHashAddr) == columnNameHash) {
				return columnIndex;
			}
			columnIndex++;
			columnHashAddr += 12;
		} while ((int32_t)columnIndex < columnCount);
	}
	return (uint64_t)-1;
}
PROMOTED_ENTRY(87, sub_82BBD2C8, 0x82BBD2C8) { ctx.r3.u64 = CDataTableSet_FindColumnIndex(ctx, base, ctx.r3.u32, ctx.r4.u64, ctx.r5.u32); }

uint64_t CDataTableSet_FindRowByNumber(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex, double targetValue, double tolerance) {
	constexpr int32_t str_TXT_820ECADC_B_ = int32_t(0x820ECADC);
	constexpr int32_t str_TXT_820FE338_B_ = int32_t(0x820FE338);
	constexpr int32_t str_TXT_820FE390_B_ = int32_t(0x820FE390);
	constexpr int32_t str_TXT_82100000_B_ = int32_t(0x82100000);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BBD348)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.f1.f64 = targetValue; ctx.f2.f64 = tolerance; __imp__sub_82BBD348(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD348);
	uint32_t stack = ctx.r1.u64;
	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);
	stack = PushStackFrame(base, stack, 384);

	// state the callee may pass on
	ctx.r1.u64 = stack;
	ctx.f1.f64 = targetValue;
	ctx.f2.f64 = tolerance;
	uint32_t column = CDataTableSet_GetColumn(ctx, base, dataTableSetAddr, tableIndex, columnIndex);
	// callers read r4 after the call: GetColumn's r4, replaced by the sign-table offset of each row compared
	uint64_t r4ForCaller = ctx.r4.u64;

	uint64_t rowIndex = uint64_t(-1);
	uint32_t table = LOAD32((uint32_t(tableIndex) << 2) + dataTableSet->m_Tables);
	if (table != 0 && column != 0) {
		if (LOAD32(column + 8) != 0) {
			// the column's type is not 0 (number): format a diagnostic into the stack buffer and pass it to the handler
			uint64_t messageBuffer = uint64_t(stack) + 80;
			String_Format(ctx, base, messageBuffer, 256, str_TXT_820FE390_B_, str_TXT_820FE338_B_, tableIndex, columnIndex, 0, str_TXT_820ECADC_B_);
			int32_t logger = g_83310000;
			uint32_t logFunction = LOAD32(uint32_t(logger) + 19068);
			ctx.r3.u64 = 2;
			ctx.r4.u64 = messageBuffer;
			ctx.r6.u64 = logFunction;
			ctx.r7.s64 = logger;
			REX_CALL_INDIRECT_FUNC(logFunction);
			stack = PopStackFrame(stack, 384);
			ctx.r1.u64 = stack;
			return uint64_t(-1);
		}
		int32_t rowCount = int32_t(LOAD32(table + 12));
		if (rowCount > 0) {
			// a row holds one 4-byte cell per column (table + 56 is the column count)
			uint32_t rowStride = LOAD32(table + 56) << 2;
			uint32_t cell = LOAD32(table + 96) + ((uint32_t)columnIndex << 2);
			// two floats; the sign of the one the comparison picks decides whether the difference is negated
			uint32_t signTable = uint32_t(str_TXT_82100000_B_) + 368;
			ctx.fpscr.disableFlushMode();
			double refValue = double(LOAD_F32(0x820994B4u));
			PPCRegister difference{};
			PPCRegister negatedDifference{};
			for (int32_t row = 0; row < rowCount; row++) {
				ctx.fpscr.disableFlushMode();
				difference.f64 = double(float(double(LOAD_F32(cell)) - targetValue));
				PPCCRRegister diffCompare{};
				diffCompare.compare(difference.f64, refValue);
				uint32_t signOffset = (diffCompare.lt ? 4u : 0u) | (diffCompare.so ? 4u : 0u);
				r4ForCaller = signOffset;
				negatedDifference.u64 = difference.u64 ^ 0x8000000000000000;
				double distance = LOAD_F32(signTable + signOffset) >= 0.0 ? difference.f64 : negatedDifference.f64;
				if (distance < tolerance) {
					rowIndex = (uint64_t)row;
					break;
				}
				cell += rowStride;
			}
		}
	}
	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	return rowIndex;
}
PROMOTED_ENTRY(87, sub_82BBD348, 0x82BBD348) { ctx.r3.u64 = CDataTableSet_FindRowByNumber(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.f1.f64, ctx.f2.f64); }

uint64_t CDataTableSet_FindRowByString(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex, uint32_t searchString) {
	constexpr int32_t g_82000C98 = int32_t(0x82000C98);
	constexpr int32_t str_TXT_820FE338_B_ = int32_t(0x820FE338);
	constexpr int32_t str_TXT_820FE388_B_ = int32_t(0x820FE388);
	constexpr int32_t str_TXT_820FE390_B_ = int32_t(0x820FE390);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BBD480)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = searchString; __imp__sub_82BBD480(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD480);
	uint32_t stack = ctx.r1.u64;

	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);
	stack = PushStackFrame(base, stack, 384);
	ctx.r1.u64 = stack;

	const uint32_t column = CDataTableSet_GetColumn(ctx, base, dataTableSetAddr, tableIndex, columnIndex);
	// callers read r4 after the call: GetColumn's r4, replaced by each row-string byte compared
	uint64_t r4ForCaller = ctx.r4.u64;

	const uint32_t table = LOAD32((uint32_t(tableIndex) << 2) + dataTableSet->m_Tables);
	uint64_t rowIndex = uint64_t(-1);

	if (table != 0 && column != 0) {
		if (int32_t(LOAD32(column + 8)) != 1) {
			// the column's type is not 1 (string): format a diagnostic into the stack buffer and pass it to the handler
			const uint64_t message = (uint64_t)stack + 80;
			String_Format(ctx, base, message, 256, str_TXT_820FE390_B_, str_TXT_820FE338_B_, tableIndex, columnIndex, 0, str_TXT_820FE388_B_);

			const int32_t logManager = g_83310000;
			const uint32_t logFn = LOAD32((uint32_t)logManager + 19068);
			ctx.r3.u64 = 2;
			ctx.r4.u64 = message;
			ctx.r6.u64 = logFn;
			ctx.r7.s64 = logManager;
			REX_CALL_INDIRECT_FUNC(logFn);

			stack = PopStackFrame(stack, 384);
			ctx.r1.u64 = stack;
			return uint64_t(-1);
		}

		const int32_t rowCount = LOAD32(table + 12);
		if (rowCount > 0) {
			// a row holds one 4-byte cell per column (table + 56 is the column count)
			const uint32_t rowStrideBytes = LOAD32(table + 56) << 2;
			uint32_t cell = LOAD32(table + 96) + ((uint32_t)columnIndex << 2);
			const uint32_t emptyString = uint32_t(g_82000C98);

			for (int32_t row = 0; row < rowCount; row++) {
				uint32_t rowString = LOAD32(LOAD32(cell));
				if (rowString == 0) rowString = emptyString;

				// compare the strings up to the end of the search string
				uint32_t searchPtr = searchString;
				uint32_t searchChar;
				uint32_t rowChar;
				do {
					searchChar = LOAD8(searchPtr++);
					rowChar = LOAD8(rowString++);
					r4ForCaller = rowChar;
				} while (searchChar != 0 && searchChar == rowChar);

				if (searchChar == rowChar) {
					rowIndex = uint64_t(row);
					break;
				}
				cell += rowStrideBytes;
			}
		}
	}

	stack = PopStackFrame(stack, 384);
	ctx.r1.u64 = stack;
	ctx.r4.u64 = r4ForCaller;
	return rowIndex;
}
PROMOTED_ENTRY(87, sub_82BBD480, 0x82BBD480) { ctx.r3.u64 = CDataTableSet_FindRowByString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u32); }

uint64_t CDataTableSet_GetRowCount(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex) {
	if (!UseLiftedCode(87, 0x82BBD5A8)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; __imp__sub_82BBD5A8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD5A8);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t table = (uint32_t)CDataTableSet_GetTable(ctx, base, dataTableSetAddr, tableIndex);
	uint32_t rowCount = (table != 0) ? LOAD32(table + 12) : 0;
	return rowCount;
}
PROMOTED_ENTRY(87, sub_82BBD5A8, 0x82BBD5A8) { ctx.r3.u64 = CDataTableSet_GetRowCount(ctx, base, ctx.r3.u64, ctx.r4.u64); }

// sub_82BBD5E8  [64 bytes]
uint64_t CDataTableSet_GetColumnCount(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex) {
	if (!UseLiftedCode(87, 0x82BBD5E8)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; __imp__sub_82BBD5E8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD5E8);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t table = (uint32_t)CDataTableSet_GetTable(ctx, base, dataTableSetAddr, tableIndex);
	uint32_t columnCount = (table != 0) ? LOAD32(table + 56) : 0;
	return columnCount;
}
PROMOTED_ENTRY(87, sub_82BBD5E8, 0x82BBD5E8) { ctx.r3.u64 = CDataTableSet_GetColumnCount(ctx, base, ctx.r3.u64, ctx.r4.u64); }

uint64_t CDataTableSet_GetColumnType(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex) {
	if (!UseLiftedCode(87, 0x82BBD628)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; __imp__sub_82BBD628(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD628);
	GameStackFrame stackFrame(ctx, base, 96);

	uint32_t column = (uint32_t)CDataTableSet_GetColumn(ctx, base, dataTableSetAddr, tableIndex, columnIndex);
	uint32_t columnType = (column != 0) ? LOAD32(column + 8) : 0;
	return columnType;
}
PROMOTED_ENTRY(87, sub_82BBD628, 0x82BBD628) { ctx.r3.u64 = CDataTableSet_GetColumnType(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDataTableSet_GetColumnName(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(87, 0x82BBD668)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; __imp__sub_82BBD668(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD668);
	GameStackFrame stackFrame(ctx, base, 96);

	uint64_t columnName = 0;
	uint32_t column = CDataTableSet_GetColumn(ctx, base, dataTableSetAddr, tableIndex, columnIndex);
	if (column != 0) {
		uint32_t nameString = LOAD32(column);
		if (nameString != 0) {
			uint32_t nameText = LOAD32(nameString);
			if (nameText == 0) {
				// no text stored: return the shared fallback string at 0x82000C98 instead
				columnName = (uint64_t)((int64_t)g_82000000 + 0xC98);
			} else {
				columnName = nameText;
			}
		}
	}
	return columnName;
}
PROMOTED_ENTRY(87, sub_82BBD668, 0x82BBD668) { ctx.r3.u64 = CDataTableSet_GetColumnName(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDataTableSet_GetNumber(CpuState& ctx, uint8_t* base, uint64_t dataTableSet, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex) {
	if (!UseLiftedCode(87, 0x82BBD6C8)) { ctx.r3.u64 = dataTableSet; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = rowIndex; __imp__sub_82BBD6C8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD6C8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	// cell type 0 holds numbers (SetNumber asks for it too; the string accessors use type 1)
	uint64_t cellPtr = CDataTableSet_GetCellPtr(ctx, base, dataTableSet, tableIndex, columnIndex, rowIndex, 0);
	ctx.fpscr.disableFlushMode();
	// without a cell the value is read from the fallback constant at 0x820994B4
	uint32_t valueAddr = (uint32_t)cellPtr != 0 ? (uint32_t)cellPtr : 0x820994B4u;
	double value = double(LOAD_F32(valueAddr));
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	// the number is returned in f1; r3 keeps the cell pointer
	ctx.f1.f64 = value;
	return cellPtr;
}
PROMOTED_ENTRY(87, sub_82BBD6C8, 0x82BBD6C8) { ctx.r3.u64 = CDataTableSet_GetNumber(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82BBD710  [100 bytes]
uint64_t CDataTableSet_GetString(CpuState& ctx, uint8_t* base, uint64_t tableSet, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex) {
	constexpr int32_t g_82000000 = int32_t(0x82000000);
	if (!UseLiftedCode(87, 0x82BBD710)) { ctx.r3.u64 = tableSet; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = rowIndex; __imp__sub_82BBD710(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD710);
	GameStackFrame stackFrame(ctx, base, 96);
	// cell type 1 holds strings (SetString asks for it too)
	uint32_t cellPtr = CDataTableSet_GetCellPtr(ctx, base, tableSet, tableIndex, columnIndex, rowIndex, 1);
	uint64_t text = 0;
	if (cellPtr != 0) {
		uint32_t cellString = LOAD32(cellPtr);
		if (cellString != 0) {
			text = LOAD32(cellString);
			if ((uint32_t)text == 0) {
				// no text stored: return the shared fallback string at 0x82000C98 instead
				text = (int64_t)g_82000000 + 3224;
			}
		}
	}
	return text;
}
PROMOTED_ENTRY(87, sub_82BBD710, 0x82BBD710) { ctx.r3.u64 = CDataTableSet_GetString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64); }

// sub_82BBD778  [60 bytes]
uint64_t CDataTableSet_SetNumber(CpuState& ctx, uint8_t* base, uint64_t dataTableSet, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex, double numberValue) {
	if (!UseLiftedCode(87, 0x82BBD778)) { ctx.r3.u64 = dataTableSet; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = rowIndex; ctx.f1.f64 = numberValue; __imp__sub_82BBD778(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD778);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 96);
	ctx.r1.u64 = stack;
	// state the callee may pass on
	ctx.f1.f64 = numberValue;
	// cell type 0 holds numbers (GetNumber asks for it too)
	uint64_t cellPtr = CDataTableSet_GetCellPtr(ctx, base, dataTableSet, tableIndex, columnIndex, rowIndex, 0);
	if ((uint32_t)cellPtr != 0) {
		ctx.fpscr.disableFlushMode();
		STORE_F32((uint32_t)cellPtr, float(numberValue));
	}
	stack = PopStackFrame(stack, 96);
	ctx.r1.u64 = stack;
	return cellPtr;
}
PROMOTED_ENTRY(87, sub_82BBD778, 0x82BBD778) { ctx.r3.u64 = CDataTableSet_SetNumber(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.f1.f64); }

// sub_82BBD7B8  [140 bytes]
uint64_t CDataTableSet_SetString(CpuState& ctx, uint8_t* base, uint64_t dataTableSet, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex, uint64_t newString) {
	if (!UseLiftedCode(87, 0x82BBD7B8)) { ctx.r3.u64 = dataTableSet; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = rowIndex; ctx.r7.u64 = newString; __imp__sub_82BBD7B8(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD7B8);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 112);
	ctx.r1.u64 = stack;
	uint32_t stringTemp = stack + 80;
	uint64_t result = CDataTableSet_GetCellPtr(ctx, base, dataTableSet, tableIndex, columnIndex, rowIndex, 1);
	uint32_t cellPtr = (uint32_t)result;
	if (cellPtr != 0) {
		if (LOAD32(cellPtr) != 0) {
			STORE32(stringTemp, 0);
			STORE16(stringTemp + 4, 0);
			STORE16(stringTemp + 6, 0);
			if ((uint32_t)newString != 0) {
				CCharString_AssignCStr(ctx, base, stringTemp, newString, -1);
			}
			CCharString_Assign_82BA8AC8(ctx, base, LOAD32(cellPtr), stringTemp);
			result = CCharString_Destructor(ctx, base, stringTemp);
		}
	}
	stack = PopStackFrame(stack, 112);
	ctx.r1.u64 = stack;
	return result;
}
PROMOTED_ENTRY(87, sub_82BBD7B8, 0x82BBD7B8) { ctx.r3.u64 = CDataTableSet_SetString(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64); }

// sub_82BBD848  [164 bytes]
uint64_t CDataTableSet_GetTable(CpuState& ctx, uint8_t* base, uint32_t dataTableSetAddr, uint64_t tableIndex) {
	constexpr int32_t str_TXT_820ECADC_B_ = int32_t(0x820ECADC);
	constexpr int32_t str_TXT_820FE348_B_ = int32_t(0x820FE348);
	constexpr int32_t str_TXT_820FE390_B_ = int32_t(0x820FE390);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BBD848)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; __imp__sub_82BBD848(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD848);
	uint32_t stack = ctx.r1.u64;
	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);
	stack = PushStackFrame(base, stack, 352);

	if ((int32_t)tableIndex >= 0 && (int32_t)tableIndex < int32_t(uint32_t(dataTableSet->m_TableCount))) {
		uint32_t table = LOAD32(uint32_t(dataTableSet->m_Tables) + uint32_t((uint32_t)tableIndex << 2));
		if (table != 0) {
			stack = PopStackFrame(stack, 352);
			ctx.r1.u64 = stack;
			return table;
		}
	}

	// index out of range or empty table slot: format a message and pass it to the handler stored at 0x83314A7C
	uint64_t messageBuffer = uint64_t(stack) + 80;
	ctx.r1.u64 = stack;
	String_Format(ctx, base, messageBuffer, 256, str_TXT_820FE390_B_, str_TXT_820FE348_B_, tableIndex, 0, 0, str_TXT_820ECADC_B_);

	const int32_t handlerBase = g_83310000;
	uint32_t reportHandler = LOAD32(uint32_t(handlerBase) + 19068);
	ctx.r3.u64 = 2;
	ctx.r4.u64 = messageBuffer;
	ctx.r6.u64 = reportHandler;
	ctx.r7.s64 = handlerBase;
	REX_CALL_INDIRECT_FUNC(reportHandler);

	stack = PopStackFrame(stack, 352);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(87, sub_82BBD848, 0x82BBD848) { ctx.r3.u64 = CDataTableSet_GetTable(ctx, base, ctx.r3.u32, ctx.r4.u64); }

uint64_t CDataTableSet_GetColumn(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex) {
	constexpr int32_t str_TXT_820ECADC_B_ = int32_t(0x820ECADC);
	constexpr int32_t str_TXT_820FE35C_B_ = int32_t(0x820FE35C);
	constexpr int32_t str_TXT_820FE390_B_ = int32_t(0x820FE390);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BBD8F0)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; __imp__sub_82BBD8F0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD8F0);
	uint32_t stack = ctx.r1.u64;
	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);
	stack = PushStackFrame(base, stack, 368);
	ctx.r1.u64 = stack;
	uint64_t table = CDataTableSet_GetTable(ctx, base, dataTableSetAddr, tableIndex);
	if ((uint32_t)table == 0) {
		stack = PopStackFrame(stack, 368);
		ctx.r1.u64 = stack;
		return table;
	}

	if (int32_t(columnIndex) < 0 || int32_t(columnIndex) >= int32_t(LOAD32((uint32_t)table + 56))) {
		// column index out of range: format a message (its type argument is always str_TXT_820ECADC_B_)
		// and pass it to the handler stored at 0x83314A7C
		uint64_t messageBuffer = uint64_t(stack) + 80;
		String_Format(ctx, base, messageBuffer, 256, str_TXT_820FE390_B_, str_TXT_820FE35C_B_, tableIndex, columnIndex, 0, str_TXT_820ECADC_B_);

		const int32_t handlerBase = g_83310000;
		uint32_t reportHandler = LOAD32(uint32_t(handlerBase) + 19068);
		ctx.r3.u64 = 2;
		ctx.r4.u64 = messageBuffer;
		ctx.r6.u64 = reportHandler;
		ctx.r7.s64 = handlerBase;
		REX_CALL_INDIRECT_FUNC(reportHandler);
	}

	// the column address is computed even after a bad index was reported; each column entry is 12 bytes
	uint32_t tableAddr = LOAD32(uint32_t(dataTableSet->m_Tables) + uint32_t(tableIndex) * 4);
	uint32_t columnOffset = uint32_t(columnIndex) * 12;
	uint64_t column = uint64_t(LOAD32(tableAddr + 48)) + uint64_t(columnOffset);

	stack = PopStackFrame(stack, 368);
	ctx.r1.u64 = stack;
	return column;
}
PROMOTED_ENTRY(87, sub_82BBD8F0, 0x82BBD8F0) { ctx.r3.u64 = CDataTableSet_GetColumn(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64); }

uint64_t CDataTableSet_GetCellPtr(CpuState& ctx, uint8_t* base, uint64_t dataTableSetAddr, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex, uint32_t expectedType) {
	constexpr int32_t str_TXT_820FE338_B_ = int32_t(0x820FE338);
	constexpr int32_t str_TXT_820FE374_B_ = int32_t(0x820FE374);
	if (!UseLiftedCode(87, 0x82BBD9A0)) { ctx.r3.u64 = dataTableSetAddr; ctx.r4.u64 = tableIndex; ctx.r5.u64 = columnIndex; ctx.r6.u64 = rowIndex; ctx.r7.u64 = expectedType; __imp__sub_82BBD9A0(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBD9A0);
	uint32_t stack = ctx.r1.u64;
	CDataTableSet* dataTableSet = GameObject<CDataTableSet>(base, dataTableSetAddr);

	stack = PushStackFrame(base, stack, 128);
	ctx.r1.u64 = stack;

	uint64_t column = CDataTableSet_GetColumn(ctx, base, dataTableSetAddr, tableIndex, columnIndex);
	if ((uint32_t)column == 0) {
		stack = PopStackFrame(stack, 128);
		ctx.r1.u64 = stack;
		return column;
	}

	uint64_t errorMessage = 0;
	if ((int32_t)rowIndex < 0) {
		errorMessage = str_TXT_820FE374_B_;
	} else {
		uint32_t tableSlotOffset = (uint32_t)tableIndex << 2;
		uint32_t tableAddr = LOAD32((uint32_t)dataTableSet->m_Tables + tableSlotOffset);
		if ((int32_t)rowIndex >= (int32_t)LOAD32(tableAddr + 12)) {
			errorMessage = str_TXT_820FE374_B_;
		} else if ((int32_t)LOAD32((uint32_t)column + 8) != (int32_t)expectedType) {
			errorMessage = str_TXT_820FE338_B_;
		} else {
			// cells are stored row by row, one 4-byte cell per column
			int32_t rowStride = (int32_t)LOAD32(tableAddr + 56);
			uint32_t cellIndex = (uint32_t)((int64_t)rowStride * (int32_t)rowIndex + (int32_t)columnIndex);
			uint64_t cellPtr = (uint64_t)(cellIndex << 2) + (uint64_t)LOAD32(tableAddr + 96);
			stack = PopStackFrame(stack, 128);
			ctx.r1.u64 = stack;
			return cellPtr;
		}
	}

	// state the callee may pass on
	uint64_t errorResult = CDataTableSet_ReportCellError(ctx, base, errorMessage, tableIndex, columnIndex, rowIndex, expectedType);
	stack = PopStackFrame(stack, 128);
	ctx.r1.u64 = stack;
	return errorResult;
}
PROMOTED_ENTRY(87, sub_82BBD9A0, 0x82BBD9A0) { ctx.r3.u64 = CDataTableSet_GetCellPtr(ctx, base, ctx.r3.u64, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u32); }

uint64_t CDataTableSet_ReportCellError(CpuState& ctx, uint8_t* base, uint64_t errorMessage, uint64_t tableIndex, uint64_t columnIndex, uint64_t rowIndex, uint32_t cellType) {
	constexpr int32_t str_TXT_820FE388_B_ = int32_t(0x820FE388);
	constexpr int32_t str_TXT_820ECADC_B_ = int32_t(0x820ECADC);
	constexpr int32_t str_TXT_820FE390_B_ = int32_t(0x820FE390);
	constexpr int32_t g_83310000 = int32_t(0x83310000);
	if (!UseLiftedCode(87, 0x82BBDA60)) { ctx.r4.u64 = errorMessage; ctx.r5.u64 = tableIndex; ctx.r6.u64 = columnIndex; ctx.r7.u64 = rowIndex; ctx.r8.u64 = cellType; __imp__sub_82BBDA60(ctx, base); return ctx.r3.u64; }
	LiftedFrame frame(0x82BBDA60);
	uint32_t stack = ctx.r1.u64;
	stack = PushStackFrame(base, stack, 352);

	// name of the cell's data type
	const int32_t cellTypeName = ((int32_t)cellType == 1) ? str_TXT_820FE388_B_ : str_TXT_820ECADC_B_;

	const uint64_t messageBuffer = uint64_t(stack) + 80;
	ctx.r1.u64 = stack;
	String_Format(ctx, base, messageBuffer, 256, str_TXT_820FE390_B_,
	               errorMessage, tableIndex, columnIndex, rowIndex, (uint64_t)(int64_t)cellTypeName);

	// hand the message to the reporting handler installed at 0x83314A7C
	const uint32_t handlerFn = LOAD32(uint32_t(g_83310000) + 19068);
	// state the callee may read (r6 holds the sign-extended page address)
	ctx.r3.u64 = 2;
	ctx.r4.u64 = messageBuffer;
	ctx.r5.u64 = handlerFn;
	ctx.r6.s64 = g_83310000;
	REX_CALL_INDIRECT_FUNC(handlerFn);

	stack = PopStackFrame(stack, 352);
	ctx.r1.u64 = stack;
	return 0;
}
PROMOTED_ENTRY(87, sub_82BBDA60, 0x82BBDA60) { ctx.r3.u64 = CDataTableSet_ReportCellError(ctx, base, ctx.r4.u64, ctx.r5.u64, ctx.r6.u64, ctx.r7.u64, ctx.r8.u32); }
