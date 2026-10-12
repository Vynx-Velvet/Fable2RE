"""The shipped class model (tools/lift/classes.py, research/lift/class_model.json.gz) on a small made-up model
(seconds; no game files, nothing written outside a temporary directory).

    python -m unittest discover -s tools/tests -p "test_class_model.py"

Cases: the shipped form round-trips; the same model gives the same bytes; a classes.json with the same structure
and other names has no differences, one with another `this` class, field layout, vtable or base class has them;
the model is refused for another executable or another format; --verify; the source a rebuild uses.
"""
import contextlib
import gzip
import io
import json
import os
import shutil
import sys
import tempfile
import unittest
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
LIFT = os.path.join(TOOLS, 'lift')
for p in (TOOLS, LIFT):   # (as the lifter scripts run: tools/lift first)
    if p not in sys.path:
        sys.path.insert(0, p)
import classes  # noqa: E402

SHA = 'ab' * 32
OTHER = 'cd' * 32
A, B, C = 0x82001000, 0x82002000, 0x82003000


def made_up_model():
    return {'tables': {A: ['sub_82100000', 'sub_82100010'], B: ['sub_82100000', 'sub_82100020', 'sub_82100028'],
                       C: ['sub_82100030']},
            'bases': {B: {A}},
            'ctors': {A: {'sub_82100040'}, B: {'sub_82100048', 'sub_82100050'}},
            'this': {'sub_82100000': A, 'sub_82100010': A, 'sub_82100020': B, 'sub_82100028': B,
                     'sub_82100030': C, 'sub_82100040': A, 'sub_82100048': B, 'sub_82100060': B},
            'fields': {A: {0: [{4}, 5, 0], 4: [{4}, 1, 3], 8: [{2, 4}, 2, 0]}, B: {12: [{8}, 0, 1], 16: [{1}, 4, 0]}},
            'seeds': 7}


def classes_json(model, names=None):
    """A cache/classes.json for the model, as classes.build() writes it (names: vtable -> class name)."""
    names = names or {}
    out = {'classes': {}, 'this': {f: f'{c:08X}' for f, c in sorted(model['this'].items())}}
    for v, entries in model['tables'].items():
        lay = classes.layout(model['fields'][v]) if model['fields'].get(v) else {}
        out['classes'][f'{v:08X}'] = {
            'name': names.get(v, f'C_{v:08X}'), 'vtable': entries,
            'bases': sorted(f'{b:08X}' for b in model['bases'].get(v, ())),
            'ctors': sorted(model['ctors'].get(v, ())), 'struct': names.get(v, f'C_{v:08X}'),
            'fields': {str(o): [n, t, s] for o, (n, t, s) in lay.items()}}
    return out


class ClassModelTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.mkdtemp(prefix='f2_class_model_', dir=os.environ.get('F2_TEST_TMP'))
        self.model_path = os.path.join(self.tmp, 'class_model.json.gz')
        self.classes_path = os.path.join(self.tmp, 'classes.json')
        self.model = made_up_model()

    def tearDown(self):
        shutil.rmtree(self.tmp, ignore_errors=True)

    def read_bytes(self):
        with open(self.model_path, 'rb') as f:
            return f.read()

    def write_classes(self, cl):
        with open(self.classes_path, 'w', encoding='utf-8') as f:
            json.dump(cl, f)

    def test_round_trip(self):
        doc = classes.model_doc(self.model, SHA)
        self.assertEqual(doc['format'], classes.MODEL_FORMAT)
        self.assertEqual(doc['xex_sha256'], SHA)
        self.assertEqual(classes.doc_model(json.loads(json.dumps(doc))), self.model)

    def test_no_names_in_the_shipped_form(self):
        text = json.dumps(classes.model_doc(self.model, SHA))
        self.assertNotIn('name', text)
        self.assertNotIn('struct', text)

    def test_same_model_same_bytes(self):
        classes.write_model(classes.model_doc(self.model, SHA), self.model_path)
        first = self.read_bytes()
        classes.write_model(classes.model_doc(made_up_model(), SHA), self.model_path)
        self.assertEqual(self.read_bytes(), first)
        self.assertEqual(first[4:8], b'\0\0\0\0')   # gzip time stamp
        self.assertEqual(classes.read_model(self.model_path), classes.model_doc(self.model, SHA))

    def test_same_structure_other_names(self):
        cl = classes_json(self.model, {A: 'CThing', B: 'CDerivedThing'})
        cl['classes'][f'{A:08X}']['fields']['4'][0] = 'm_health'   # (a dictionary field name)
        self.assertEqual(classes.differences(self.model, cl), {})

    def test_differences_are_counted(self):
        cl = classes_json(self.model)
        cl['this']['sub_82100060'] = f'{A:08X}'
        cl['this']['sub_82100070'] = f'{C:08X}'
        cl['classes'][f'{B:08X}']['fields']['12'][1] = 'BigEndian<uint64_t>'
        cl['classes'][f'{C:08X}']['vtable'] = ['sub_82100030', 'sub_82100038']
        cl['classes'][f'{B:08X}']['bases'] = []
        self.assertEqual(classes.differences(self.model, cl),
                         {'`this` classes': 2, 'field layouts': 1, 'vtables': 1, 'bases': 1})

    def test_missing_class(self):
        cl = classes_json(self.model)
        del cl['classes'][f'{C:08X}']
        self.assertEqual(classes.differences(self.model, cl), {'classes': 1})

    def test_load_for_this_executable(self):
        classes.write_model(classes.model_doc(self.model, SHA), self.model_path)
        model, why = classes.load_model(self.model_path, xex=SHA)
        self.assertEqual(model, self.model, why)

    def test_refused_for_another_executable(self):
        classes.write_model(classes.model_doc(self.model, SHA), self.model_path)
        model, why = classes.load_model(self.model_path, xex=OTHER)
        self.assertIsNone(model)
        self.assertIn('another default.xex', why)

    def test_refused_for_another_format(self):
        doc = classes.model_doc(self.model, SHA)
        doc['version'] = classes.MODEL_VERSION + 1
        classes.write_model(doc, self.model_path)
        model, why = classes.load_model(self.model_path, xex=SHA)
        self.assertIsNone(model)
        self.assertIn('version', why)

    def test_missing(self):
        model, why = classes.load_model(os.path.join(self.tmp, 'none.json.gz'), xex=SHA)
        self.assertIsNone(model)
        self.assertIn('no shipped class model', why)

    def verify(self):
        out = io.StringIO()
        with mock.patch.object(classes, 'MODEL', self.model_path), \
                mock.patch.object(classes, 'CLASSES_JSON', self.classes_path), \
                mock.patch.object(sys, 'argv', ['classes.py', '--verify']), contextlib.redirect_stdout(out):
            try:
                classes.main()
                return 0, out.getvalue()
            except SystemExit as e:
                return e.code, out.getvalue()

    def test_verify(self):
        classes.write_model(classes.model_doc(self.model, SHA), self.model_path)
        self.write_classes(classes_json(self.model, {A: 'CThing'}))
        code, text = self.verify()
        self.assertEqual(code, 0)
        self.assertIn('OK', text)
        cl = classes_json(self.model)
        cl['this']['sub_82100010'] = f'{B:08X}'
        self.write_classes(cl)
        code, _ = self.verify()
        self.assertIn('1 `this` classes differ', str(code))

    def test_rebuild_keeps_the_source(self):
        with mock.patch.object(classes, 'CLASSES_JSON', self.classes_path):
            self.assertIsNone(classes.current_source())
            cl = classes_json(self.model)
            self.write_classes(cl)
            self.assertEqual(classes.current_source(), 'facts')   # (built before the source was recorded)
            cl['source'] = 'bundle'
            self.write_classes(cl)
            self.assertEqual(classes.current_source(), 'bundle')

    def test_shipped_model_if_present(self):
        """research/lift/class_model.json.gz, when the checkout has it: the expected format, structure only."""
        if not os.path.exists(classes.MODEL):
            self.skipTest('no shipped class model in this checkout')
        with gzip.open(classes.MODEL, 'rt', encoding='utf-8') as f:
            doc = json.load(f)
        self.assertEqual((doc['format'], doc['version']), (classes.MODEL_FORMAT, classes.MODEL_VERSION))
        self.assertEqual(set(doc), {'format', 'version', 'xex_sha256', 'seeds', 'classes', 'this'})
        for c in doc['classes'].values():
            self.assertEqual(set(c), {'vtable', 'bases', 'ctors', 'fields'})


if __name__ == '__main__':
    unittest.main()
