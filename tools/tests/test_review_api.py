"""tools/rewrite/review_api.py without a model or the checker (seconds; no game files, no network).

    python -m unittest discover -s tools/tests -p "test_review_api.py"

Cases: replies are read in the forms models write them (headings, bold labels, EARLIER-FIX before FIX, the
largest code block); a fix must be one function ending in the module's unchanged PROMOTED_ENTRY line; the check
takes the fix in the checker's form; which verdicts go to the second reviewer (unresolved, a demotion, a
disagreement with a single earlier verdict, a fixed sample) and which do not (confirmed earlier verdicts,
agreement); check failures get a hint.
"""
import os
import sys
import unittest
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'rewrite'))
import review_api  # noqa: E402

MODULE = '''uint64_t Thing_Reset(CpuState& ctx, uint8_t* base, uint64_t self) {
\tif (!UseLiftedCode(1, 0x82100000)) { ctx.r3.u64 = self; __imp__sub_82100000(ctx, base); return ctx.r3.u64; }
\tSTORE32((uint32_t)self + 4, 0);   // "Example text"
\treturn 0;
}
PROMOTED_ENTRY(1, sub_82100000, 0x82100000)'''

REPLY = '''Some words first.

### sub_82100000
**VERDICT:** FIX
**NOTE:** The hand-over of r8 before the return was missing.
```cpp
x
```
```cpp
''' + MODULE + '''
```

### sub_82100010
VERDICT: EARLIER-FIX
NOTE: The earlier fix is right.

### sub_82100020
VERDICT: OK
'''


def result(**kw):
    r = {'module': 'Thing', 'kind': 'review', 'earlier': '', 'verdict': 'OK', 'note': '', 'source': 'model',
         'check': 'OK', 'rounds': 0}
    r.update(kw)
    return r


class ReviewApiTests(unittest.TestCase):
    def test_parse_reply(self):
        p = review_api.parse_reply(REPLY)
        self.assertEqual(set(p), {'sub_82100000', 'sub_82100010', 'sub_82100020'})
        self.assertEqual(p['sub_82100000']['verdict'], 'FIX')
        self.assertIn('PROMOTED_ENTRY(1, sub_82100000', p['sub_82100000']['code'])
        self.assertTrue(p['sub_82100000']['note'].startswith('The hand-over of r8'))
        self.assertEqual(p['sub_82100010']['verdict'], 'EARLIER-FIX')
        self.assertIsNone(p['sub_82100010']['code'])
        self.assertEqual(p['sub_82100020']['verdict'], 'OK')

    def test_structure(self):
        self.assertIsNone(review_api.structure_problem(MODULE + '\n', MODULE))
        other = MODULE.replace('PROMOTED_ENTRY(1,', 'PROMOTED_ENTRY(2,')
        self.assertIn('unchanged line', review_api.structure_problem(other, MODULE))
        two = MODULE.replace('sub_82100000', 'sub_82100010').replace('0x82100000', '0x82100010') + '\n\n' + MODULE
        self.assertIn('exactly one function', review_api.structure_problem(two, MODULE))

    def test_check_text(self):
        t = review_api.check_text('sub_82100000', MODULE + '\r\n')
        self.assertTrue(t.endswith('CPU_STATE_ENTRY(sub_82100000, 0x82100000)'))
        self.assertIn('sub_82100000_original(ctx, base)', t)
        self.assertNotIn('Example text', t)

    def test_escalation(self):
        esc = review_api.escalation
        self.assertIsNone(esc('sub_1', result(kind='settled', source='earlier', earlier='FIX', verdict='FIX')))
        self.assertTrue(esc('sub_1', result(verdict='', unresolved='fails')).startswith('unresolved'))
        self.assertEqual(esc('sub_1', result(verdict='DEMOTE')), 'model demotes it')
        self.assertIsNone(esc('sub_1', result(kind='verify', earlier='OK', verdict='OK')))
        self.assertIsNone(esc('sub_1', result(kind='verify', earlier='FIX', verdict='FIX', source='earlier',
                                             took_earlier=True)))
        self.assertIn('disagrees', esc('sub_1', result(kind='verify', earlier='FIX', verdict='OK')))
        self.assertIn('new fix', esc('sub_1', result(kind='verify', earlier='FIX', verdict='FIX')))
        names = [f'sub_{0x82100000 + 4 * i:08X}' for i in range(200)]
        picked = [n for n in names if esc(n, result())]
        self.assertEqual(picked, [n for n in names if zlib.crc32(n.encode()) % review_api.SAMPLE == 0])
        self.assertTrue(5 <= len(picked) <= 40)

    def test_hints(self):
        self.assertIn('every return path', review_api.hint('MISMATCH sub_1: r9 after return: 0 vs 1'))
        self.assertIn('hand-over', review_api.hint('MISMATCH sub_1: call #2 (82A1CBF8): r8 passed through to the '
                                                    'callee differs: 1 vs 2'))
        self.assertIn('compile', review_api.hint('BUILD FAILED: error'))


if __name__ == '__main__':
    unittest.main()
