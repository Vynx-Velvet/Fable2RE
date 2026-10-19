"""tools/rewrite/promoted_text.py with a small made-up image (seconds; no game files).

    python -m unittest discover -s tools/tests -p "test_promoted_text.py"

Cases: every form of a name made from a string's text is replaced by a reference to its address and rendered back
byte for byte (the constant, a numbered copy, the local named after it, a name built around the text, a global
named after its text, a constant named after its raw text, a constant only a comment mentions); the published form
shows none of the text; a name no string explains is refused; review notes are encoded with their module's
constants.
"""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'rewrite'))
sys.path.insert(0, os.path.join(TOOLS, 'lift'))
import promoted_text as pt  # noqa: E402
import readable  # noqa: E402

BASE = readable.IMAGE_BASE
STRINGS = {0x100: 'Example Speed', 0x200: 'GreenLantern', 0x300: 'qrs', 0x400: 'OtherKeyFromElsewhere'}
GLOBALS = {0x83000010: 'g_Example_Global_Text', 0x83000020: 'g_83000020'}

MODULE = '''// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).
uint64_t Thing_Update(CpuState& ctx, uint8_t* base, uint64_t thingAddr) {
\tconstexpr int32_t str_ExampleSpeed = int32_t(0x82000100);
\tconstexpr int32_t str_ExampleSpeed2 = int32_t(0x82000100);
\tconstexpr uint64_t str_qrs = (uint64_t)(int64_t)-2113928448;
\tconstexpr int32_t g_Example_Global_Text = int32_t(0x83000010);
\tconstexpr int32_t str_GreenLantern = int32_t(0x82000200);
\tuint32_t exampleSpeed = LOAD32(str_ExampleSpeed);
\tuint32_t scaledGreenLantern = LOAD32(str_GreenLantern) + exampleSpeed;   // GreenLantern, as str_OtherKeyFromElsewhere
\treturn scaledGreenLantern + str_ExampleSpeed2 + str_qrs + g_Example_Global_Text + g_83000020;
}
PROMOTED_ENTRY(1, sub_82100000, 0x82100000) { ctx.r3.u64 = Thing_Update(ctx, base, ctx.r3.u64); }
'''


class PromotedTextTests(unittest.TestCase):
    def setUp(self):
        img = bytearray(0x1000)
        for off, s in STRINGS.items():
            img[off:off + len(s)] = s.encode()
        self.saved = (readable._IMG, readable._GLOBALS, pt._TEXT_GLOBALS, pt._INDEX, pt._NAMES)
        readable._IMG, readable._GLOBALS = bytes(img), dict(GLOBALS)
        pt._TEXT_GLOBALS = pt._INDEX = None
        pt._NAMES = {'Thing_Update'}

    def tearDown(self):
        readable._IMG, readable._GLOBALS, pt._TEXT_GLOBALS, pt._INDEX, pt._NAMES = self.saved

    def test_round_trip_without_the_text(self):
        pub = pt.encode(MODULE)
        self.assertEqual(pt.render_text(pub), MODULE)
        for text in ('ExampleSpeed', 'exampleSpeed', 'GreenLantern', 'Example_Global_Text', 'str_qrs',
                     'OtherKeyFromElsewhere'):
            self.assertNotIn(text, pub)
        self.assertIn('str_TXT_82000100_B_2', pub)          # the numbered copy keeps its number
        self.assertIn('scaledTXT_82000200_B_', pub)          # a name built around the text
        self.assertIn('TXT_83000010_G_', pub)
        self.assertIn('g_83000020', pub)                     # an address name stays as it is
        self.assertIn('Thing_Update', pub)                   # a dictionary name stays as it is
        self.assertEqual(pt.leftovers(pub), [])

    def test_leftovers_and_refusals(self):
        self.assertEqual(pt.leftovers(MODULE.replace('str_GreenLantern', 'str_TXT_82000200_B_')),
                         ['GreenLantern', 'exampleSpeed', 'g_Example_Global_Text', 'scaledGreenLantern',
                          'str_ExampleSpeed', 'str_ExampleSpeed2', 'str_OtherKeyFromElsewhere', 'str_qrs'])
        with self.assertRaises(pt.TextError):
            pt.encode(MODULE.replace('str_GreenLantern', 'str_RenamedByHand'))
        with self.assertRaises(pt.TextError):
            pt.encode(MODULE + '// TXT_82000100_B_\n')

    def test_global_inside_a_name(self):
        module = ('uint64_t Destroy_g_Example_Global_Text(CpuState& ctx, uint8_t* base) {\n'
                  '\treturn CCharString_Release(ctx, base, g_Example_Global_Text);   // Destroy_g_Example_Global_Text\n'
                  '}\nPROMOTED_ENTRY(1, sub_82100000, 0x82100000) { ctx.r3.u64 = '
                  'Destroy_g_Example_Global_Text(ctx, base); }\n')
        pub = pt.encode(module)
        self.assertNotIn('Example_Global_Text', pub)
        self.assertIn('uint64_t Destroy_TXT_83000010_G_(CpuState& ctx', pub)
        self.assertEqual(pt.render_text(pub), module)
        self.assertEqual(pt.leftovers(pub), [])
        self.assertEqual(pt.leftovers(module), ['Destroy_g_Example_Global_Text', 'g_Example_Global_Text'])

    def test_constant_inside_a_name(self):
        module = ('uint64_t HashName_qrs(CpuState& ctx, uint8_t* base) {\n'
                  '\tconstexpr int32_t str_qrs = int32_t(0x82000300);\n'
                  '\tconstexpr uint32_t g_HashOf_qrs_2 = 0x83000040u;\n'
                  '\tuint64_t hash = HashNameFnv1(ctx, base, str_qrs);\n'
                  '\tSTORE32(g_HashOf_qrs_2, (uint32_t)hash);\n\treturn hash;\n'
                  '}\nPROMOTED_ENTRY(1, sub_82100000, 0x82100000) { ctx.r3.u64 = HashName_qrs(ctx, base); }\n')
        pub = pt.encode(module)
        self.assertNotIn('qrs', pub)
        self.assertIn('uint64_t HashName_TXT_82000300_R_(CpuState& ctx', pub)
        self.assertIn('g_HashOf_TXT_82000300_R__2', pub)
        self.assertEqual(pt.render_text(pub), module)
        self.assertEqual(pt.leftovers(pub), [])
        self.assertIn('HashName_qrs', pt.leftovers(module))

    def test_review_notes(self):
        review = ('module\tfunction\tverdict\treviewer\tdate\tnote\n'
                  'Thing\tsub_82100000\tOK\tx\t2026-10-15\tfixed: str_GreenLantern holds GreenLantern; '
                  'g_Example_Global_Text kept\n')
        pub = pt.encode_review(review, {'Thing.cpp': MODULE})
        self.assertNotIn('GreenLantern', pub)
        self.assertNotIn('Example_Global_Text', pub)
        head, rows = pt.review_rows(pub)
        self.assertEqual(pt.render_text(rows[0][5]), review.split('\n')[1].split('\t')[5])


if __name__ == '__main__':
    unittest.main()
