"""tools/progress.py and tools/rewrite/readability.py without the repository's data (seconds; no game files).

    python -m unittest discover -s tools/tests -p "test_progress.py"

Cases: the history gets a row only when a number changes, dated the day it was recorded (a second change the same
day replaces that day's row); the squares add up to about one per 100 functions and show every kind that has
functions; the README block is replaced between its markers and nothing else changes; a README differs from HEAD
"only in the block" exactly when publish.py may publish it; the headline counts only readable code with every name;
the readability levels of promoted functions (CPU state or stack frame: rewrite; an unnamed function, callee,
global, variable or field: readable; neither: named).
"""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import progress  # noqa: E402
import readability  # noqa: E402  (progress.py puts tools/rewrite on the path)

ROW = {'game_functions': '41186', 'game_bytes': '12199316', 'reviewed': '7378', 'complete': '31', 'readable': '3053',
       'rewritten': '4294', 'hand': '57', 'translated': '32714', 'recompiled': '1037', 'readable_bytes': '5504',
       'named': '5232', 'modules': '249', 'executable_functions': '60861', 'executable_readable': '88'}


def body(name, *lines, entry='sub_82000000'):
    return '\n'.join([f'uint64_t {name}(CpuState& ctx, uint8_t* base, uint32_t self) {{',
                      '\tif (!UseLiftedCode(1, 0x82000000)) { __imp__sub_82000000(ctx, base); return ctx.r3.u64; }',
                      '\tLiftedFrame frame(0x82000000);', *lines, '}',
                      f'PROMOTED_ENTRY(1, {entry}, 0x82000000) {{ ctx.r3.u64 = {name}(ctx, base); }}', ''])


class ProgressTests(unittest.TestCase):
    def test_history(self):
        h = progress.updated_history([], ROW, '2026-10-15')
        self.assertEqual([r['date'] for r in h], ['2026-10-15'])
        self.assertIs(progress.updated_history(h, dict(ROW), '2026-10-20'), h)        # nothing changed
        more = dict(ROW, readable='3100')
        same_day = progress.updated_history(h, more, '2026-10-15')
        self.assertEqual(len(same_day), 1)
        self.assertEqual(same_day[0]['readable'], '3100')
        later = progress.updated_history(h, more, '2026-10-20')
        self.assertEqual([r['date'] for r in later], ['2026-10-15', '2026-10-20'])
        text = progress.history_text(later)
        self.assertTrue(text.startswith('date\tgame_functions\t'))
        self.assertEqual(text.count('\n'), 3)

    def test_squares(self):
        row = dict(ROW, date='2026-10-19')
        cells = progress.squares(row)
        self.assertEqual(sum(cells), round(41186 / 100))
        self.assertEqual(cells[0], 1)              # 31 functions: still one square
        self.assertEqual(cells[1], 1)              # 57
        self.assertEqual(progress.squares(dict(row, hand='0', translated='32771'))[1], 0)

    def test_headline(self):
        row = dict(ROW, date='2026-10-19')
        self.assertEqual(progress.headline(row), 88)     # readable with every name and by hand, nothing else
        readme = 'intro\n\n<!-- progress:begin -->\nold\n<!-- progress:end -->\n\nrest\n'
        new = progress.BLOCK.sub(lambda _: progress.readme_block(row), readme, count=1)
        self.assertTrue(new.startswith('intro\n\n' + progress.BEGIN))
        self.assertTrue(new.endswith(progress.END + '\n\nrest\n'))
        self.assertIn('| Readable C++ with every name | 31 | 0.1% |', new)
        self.assertIn('| Rewritten, still at machine level | 4,294 | 10.4% |', new)
        self.assertIn('0.2% of Lionhead\'s game functions are readable C++ with every name (88 of 41,186)', new)
        self.assertEqual(progress.BLOCK.sub('', new), progress.BLOCK.sub('', readme))   # (what publish.py compares)

    def test_chart(self):
        svg = progress.chart(dict(ROW, date='2026-10-19'), 'dark')
        self.assertTrue(svg.startswith('<svg xmlns="http://www.w3.org/2000/svg"'))
        self.assertEqual(svg.count('<rect '), 412 + 6)   # squares and the legend's six swatches
        self.assertIn('0.2%', svg)
        self.assertIn('3,053 are readable with names still to give', svg)


class ReadabilityTests(unittest.TestCase):
    def level(self, text):
        [(n, name, lines)] = readability.functions(text)
        found = readability.issues(name, lines)
        return readability.level(found), found

    def test_rewrite(self):
        lvl, found = self.level(body('Lua_Get', '\tctx.r11.s64 = 4;', '\treturn Read(ctx, base, self);'))
        self.assertEqual(lvl, 'rewrite')
        self.assertIn('cpu state', found)
        lvl, found = self.level(body('Lua_Get', '\tuint32_t stack = PushStackFrame(base, 0, 96);', '\treturn 0;'))
        self.assertEqual(lvl, 'rewrite')

    def test_readable(self):
        for line, issue in [('\treturn n_sub_82CA3700(ctx, base, self);', 'unnamed callee'),
                            ('\treturn Read(ctx, base, g_832A0000 + 12536);', 'address'),
                            ('\treturn Read(ctx, base, str_TXT_820B0000_B_ - 28788);', 'address'),
                            ('\tobject->vtable = 0x8200E3C0u;', 'address'),
                            ('\tuint32_t local12 = self;', 'machine variable name'),
                            ('\treturn LOAD32(self + 144);', 'field offset'),
                            ('\treturn object->m_1C;', 'field offset')]:
            lvl, found = self.level(body('Lua_Get', line))
            self.assertEqual(lvl, 'readable', line)
            self.assertIn(issue, found, line)
        lvl, found = self.level(body('n_sub_82000000', '\treturn self;'))
        self.assertEqual((lvl, list(found)), ('readable', ['unnamed function']))

    def test_named(self):
        lvl, found = self.level(body('CChest_IsOpen', '\tCChest* chest = GameObject<CChest>(base, self);',
                                     '\treturn chest->isOpen;  // ctx.r3 in a comment does not count'))
        self.assertEqual((lvl, found), ('named', {}))
        lvl, _ = self.level(body('Lua_GetName', '\treturn TXT_834973A8_G_;'))   # a global named after its text
        self.assertEqual(lvl, 'named')


if __name__ == '__main__':
    unittest.main()
