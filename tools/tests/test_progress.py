"""tools/progress.py without the repository's data (seconds; no game files).

    python -m unittest discover -s tools/tests -p "test_progress.py"

Cases: the history gets a row only when a number changes, dated the day it was recorded (a second change the same
day replaces that day's row); the squares add up to about one per 100 functions and show every kind that has
functions; the README block is replaced between its markers and nothing else changes; a README differs from HEAD
"only in the block" exactly when publish.py may publish it.
"""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
import progress  # noqa: E402

ROW = {'game_functions': '41186', 'game_bytes': '12199316', 'reviewed': '1206', 'hand': '57', 'translated': '38886',
       'recompiled': '1037', 'readable_bytes': '269388', 'named': '5232', 'modules': '76',
       'executable_functions': '60861', 'executable_readable': '1263'}


class ProgressTests(unittest.TestCase):
    def test_history(self):
        h = progress.updated_history([], ROW, '2026-10-15')
        self.assertEqual([r['date'] for r in h], ['2026-10-15'])
        self.assertIs(progress.updated_history(h, dict(ROW), '2026-10-20'), h)        # nothing changed
        more = dict(ROW, reviewed='1300')
        same_day = progress.updated_history(h, more, '2026-10-15')
        self.assertEqual(len(same_day), 1)
        self.assertEqual(same_day[0]['reviewed'], '1300')
        later = progress.updated_history(h, more, '2026-10-20')
        self.assertEqual([r['date'] for r in later], ['2026-10-15', '2026-10-20'])
        text = progress.history_text(later)
        self.assertTrue(text.startswith('date\tgame_functions\t'))
        self.assertEqual(text.count('\n'), 3)

    def test_squares(self):
        row = dict(ROW, date='2026-10-15')
        cells = progress.squares(row)
        self.assertEqual(sum(cells), round(41186 / 100))
        self.assertEqual(cells[1], 1)              # 57 functions: still one square
        self.assertEqual(cells[0], 12)
        self.assertEqual(progress.squares(dict(row, hand='0', translated='38943'))[1], 0)

    def test_readme_block(self):
        row = dict(ROW, date='2026-10-15')
        readme = 'intro\n\n<!-- progress:begin -->\nold\n<!-- progress:end -->\n\nrest\n'
        new = progress.BLOCK.sub(lambda _: progress.readme_block(row), readme, count=1)
        self.assertTrue(new.startswith('intro\n\n' + progress.BEGIN))
        self.assertTrue(new.endswith(progress.END + '\n\nrest\n'))
        self.assertIn('| Human-readable C++, reviewed | 1,206 | 2.9% |', new)
        self.assertIn('3.1% of Lionhead\'s game functions are human-readable C++ (1,263 of 41,186)', new)
        self.assertEqual(progress.BLOCK.sub('', new), progress.BLOCK.sub('', readme))   # (what publish.py compares)

    def test_chart(self):
        svg = progress.chart(dict(ROW, date='2026-10-15'), 'dark')
        self.assertTrue(svg.startswith('<svg xmlns="http://www.w3.org/2000/svg"'))
        self.assertEqual(svg.count('<rect '), 412 + 4)   # squares and the legend's four swatches
        self.assertIn('3.1%', svg)


if __name__ == '__main__':
    unittest.main()
