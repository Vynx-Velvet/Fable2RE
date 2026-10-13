"""tools/naming/global_strings.py on made-up lifted text (seconds; no game files).

    python -m unittest discover -s tools/tests -p "test_global_strings.py"

Cases: the global's and the text's address are read through constants, copies and additions as the lifter
prints them; a start-up function without a string construction gives nothing; names are the text as an
identifier, and a text used by several globals gets the address as well.
"""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
for p in (os.path.join(TOOLS, 'lift'), os.path.join(TOOLS, 'naming')):
    if p not in sys.path:
        sys.path.insert(0, p)
import global_strings  # noqa: E402

BLOCK = '''uint64_t n_sub_83300000(CpuState& ctx, uint8_t* base) {
\tconstexpr int32_t g_83400000 = int32_t(0x83400000);
\tconstexpr int32_t str_hi = int32_t(0x82010000);
\tr11 = str_hi;
\tr4 = (int32_t)r11 - 28788;
\tr3 = (int64_t)g_83400000 + 16;
\tCCharString_ConstructFromCStr(ctx, base, r3, r4);
\treturn 0;
}'''


class GlobalStringsTests(unittest.TestCase):
    def test_addresses_through_constants_copies_and_additions(self):
        self.assertEqual(global_strings.evaluate(BLOCK), (0x83400010, 0x82010000 - 28788))

    def test_no_string_construction(self):
        self.assertIsNone(global_strings.evaluate(BLOCK.replace('CCharString_ConstructFromCStr', 'Other_Init')))

    def test_unknown_argument(self):
        self.assertIsNone(global_strings.evaluate(BLOCK.replace('(ctx, base, r3, r4)', '(ctx, base, r3, r5)')))

    def test_rows(self):
        rows = global_strings.rows({0x83400010: ('Example Property', 'sub_83300000'),
                                    0x83400020: ('Example.Property', 'sub_83300010'),
                                    0x83400030: ('***', 'sub_83300020')})
        self.assertEqual(rows, [
            '83400010\tg_Example_Property\tExample Property\tBuilt at start-up by sub_83300000 from this text.',
            '83400020\tg_Example_Property_83400020\tExample.Property\tBuilt at start-up by sub_83300010 from this text.',
        ])


if __name__ == '__main__':
    unittest.main()
