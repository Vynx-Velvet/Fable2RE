"""tools/publish.py on a small made-up repository (seconds; no game files, no network, nothing pushed).

    python -m unittest discover -s tools/tests -p "test_publish.py"

Cases: which changes are published (research, docs, reviewed promoted modules), held back (a module without
review records) or left to the author (everything else); the summary of dictionary changes; private strings are
found whatever their case and slash direction; the subject stays short.
"""
import os
import shutil
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)
import publish  # noqa: E402

MODULE = '''// Promoted from verified model rewrites (tools/rewrite/promote.py).
PROMOTED_ENTRY(1, sub_82100000, 0x82100000)
void Thing_Reset(Thing* self) { self->count = 0; }
'''


@unittest.skipUnless(shutil.which('git'), 'git not found')
class PublishTests(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp(prefix='f2_publish_test_', dir=os.environ.get('F2_TEST_TMP')))
        self.git('init', '-q')
        self.git('config', 'user.name', 'Test')
        self.git('config', 'user.email', 'test@example.invalid')
        self.write('research/names/functions.tsv', 'address\tname\tconfidence\tbasis\n'
                                                   '82100000\tThing_Reset\tlow\tclears it.\n'
                                                   '82100010\tThing_Old\tlow\told name.\n')
        self.write('tools/x.py', 'print(1)\n')
        self.git('add', '.')
        self.git('commit', '-q', '-m', 'base')
        self.root = mock.patch.object(publish, 'ROOT', self.tmp)
        self.root.start()

    def tearDown(self):
        self.root.stop()
        shutil.rmtree(self.tmp, ignore_errors=True)

    def git(self, *args):
        subprocess.run(['git', '-C', str(self.tmp), *args], check=True, capture_output=True)

    def write(self, rel, text):
        p = self.tmp / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text, encoding='utf-8', newline='\n')

    def test_selection(self):
        self.write('research/names/functions.tsv', 'address\tname\tconfidence\tbasis\n'
                                                   '82100000\tThing_Reset\tlow\tclears it.\n'
                                                   '82100010\tThing_Clear\tmedium\tbetter name.\n'
                                                   '82100020\tThing_New\tlow\tnew.\n')
        self.write('docs/note.md', '# Note\n')
        self.write('tools/x.py', 'print(2)\n')
        self.write('Fable2Recomp/promoted/Thing.cpp', MODULE)
        publish_, held, other = publish.select(publish.changed_paths())
        self.assertEqual(publish_, ['docs/note.md', 'research/names/functions.tsv'])
        self.assertEqual(list(held), ['Fable2Recomp/promoted/Thing.cpp'])
        self.assertIn('no OK review record', held['Fable2Recomp/promoted/Thing.cpp'][0])
        self.assertEqual(other, ['tools/x.py'])
        parts, lines = publish.summarize(publish_)
        self.assertEqual(parts[0], 'names +1')
        self.assertIn('functions +1, 1 renamed', lines[0])

    def test_reviewed_module_is_published(self):
        self.write('Fable2Recomp/promoted/Thing.cpp', MODULE)
        self.write('Fable2Recomp/promoted/REVIEW.tsv', 'module\tfunction\tverdict\treviewer\tdate\tnote\n'
                                                                 'Thing\tsub_82100000\tOK\ttester\t2026-10-12\t\n')
        publish_, held, _ = publish.select(publish.changed_paths())
        self.assertEqual(held, {})
        self.assertEqual(publish_, ['Fable2Recomp/promoted/REVIEW.tsv',
                                    'Fable2Recomp/promoted/Thing.cpp'])
        parts, lines = publish.summarize(publish_)
        self.assertEqual(parts, ['1 module'])
        self.assertIn('1 new, 1 functions', lines[0])

    def test_rename_publishes_both_paths(self):
        self.write('research/findings/a.md', '# A\n')
        self.git('add', '.')
        self.git('commit', '-q', '-m', 'a')
        self.git('mv', 'research/findings/a.md', 'research/findings/b.md')
        try:
            self.assertEqual(publish.changed_paths(), ['research/findings/a.md', 'research/findings/b.md'])
        finally:
            self.git('reset', '-q')

    def test_new_finding_title(self):
        self.write('research/findings/2026-10-12-x.md', '# What was found\n\ntext\n')
        parts, lines = publish.summarize(['research/findings/2026-10-12-x.md'])
        self.assertEqual(parts, ['1 finding'])
        self.assertEqual(lines, ['Findings: What was found.'])


class PrivateStringTests(unittest.TestCase):
    def test_case_and_slashes(self):
        private = ['Users/Alice', 'alice@example.invalid', 'secret-name']
        name = 'alice'   # (filled in at run time: written out, the path would be a user folder in this file)
        text = f'path C:\\USERS\\{name}\\x and ALICE@example.invalid'
        self.assertEqual(publish.private_hits(private, text), ['Users/Alice', 'alice@example.invalid'])
        self.assertEqual(publish.private_hits(private, 'nothing here'), [])


class MessageTests(unittest.TestCase):
    def test_subject_is_short(self):
        subject, text = publish.message(['names +12,345', '17 modules', 'test records', 'class model', '3 findings'],
                                        ['Names: functions +12,345.'], ['A note.'],
                                        ['Co-Authored-By: Someone <x@example.invalid>'], '2026-10-12')
        self.assertLessEqual(len(subject), 72)
        self.assertTrue(text.startswith(subject + '\n\nNames: functions +12,345.\n\nA note.'))
        self.assertTrue(text.endswith('\nCo-Authored-By: Someone <x@example.invalid>\n'))


if __name__ == '__main__':
    unittest.main()
