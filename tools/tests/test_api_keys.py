"""tools/api_keys.py on a key store in a temporary folder (seconds; no network, the user's own store untouched).

    python -m unittest discover -s tools/tests -p "test_api_keys.py"

Cases: a key is stored, read, listed, replaced and removed; on Windows the file does not hold the key (DPAPI),
elsewhere only its owner may read it; the stored key comes before an (old) environment variable, which only
counts without one or with --api-key-env; the key's name comes
from --key, --api-key-env or the URL; a missing key or an unreadable store ends with what to do; pasted text
that cannot be a key is refused without repeating it; publish.py reports a stored key in staged text by name.
"""
import contextlib
import io
import os
import sys
import tempfile
import unittest
from unittest import mock

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)
import api_keys  # noqa: E402
import publish  # noqa: E402

KEY = 'test-key-0123456789abcdef0123'
OTHER = 'test-key-fedcba9876543210ffff'


class ApiKeysTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.path = os.path.join(self.tmp.name, 'sub', 'api_keys.json')
        clean = {k: v for k, v in os.environ.items() if not k.endswith('_API_KEY')}
        clean['FABLE2RE_KEY_STORE'] = self.path
        self.env = mock.patch.dict(os.environ, clean, clear=True)
        self.env.start()

    def tearDown(self):
        self.env.stop()
        self.tmp.cleanup()

    def run_cli(self, *argv, stdin=''):
        out = io.StringIO()
        with mock.patch.object(sys, 'stdin', io.StringIO(stdin)), contextlib.redirect_stdout(out):
            api_keys.main(list(argv))
        return out.getvalue()

    def test_store_read_replace_remove(self):
        self.assertEqual(api_keys.store_path(), self.path)
        self.assertEqual(api_keys.get('deepseek'), '')
        self.assertFalse(api_keys.store('deepseek', KEY))
        self.assertEqual(api_keys.get('deepseek'), KEY)
        self.assertTrue(api_keys.store('deepseek', OTHER))
        self.assertEqual(api_keys.get('deepseek'), OTHER)
        self.assertEqual(api_keys.stored_values(), [('deepseek', OTHER)])
        self.assertTrue(api_keys.remove('deepseek'))
        self.assertFalse(api_keys.remove('deepseek'))
        self.assertEqual(api_keys.get('deepseek'), '')

    def test_file_protection(self):
        api_keys.store('deepseek', KEY)
        with open(self.path, encoding='utf-8') as f:
            text = f.read()
        if os.name == 'nt':
            self.assertNotIn(KEY, text)
            self.assertIn('dpapi', text)
        else:
            self.assertEqual(os.stat(self.path).st_mode & 0o777, 0o600)

    @unittest.skipUnless(os.name == 'nt', 'DPAPI is Windows only')
    def test_store_of_another_account(self):
        api_keys.store('deepseek', KEY)
        doc = api_keys.load()
        doc['keys']['deepseek']['dpapi'] = 'AAAAAAAAAAAAAAAAAAAAAA=='
        api_keys.save(doc)
        with self.assertRaises(api_keys.KeyStoreError) as e:
            api_keys.get('deepseek')
        self.assertIn('api_keys.py set deepseek', str(e.exception))
        self.assertEqual(api_keys.stored_values(), [])

    def test_stored_key_before_environment(self):
        self.assertEqual(api_keys.resolve('deepseek'), ('', None))
        os.environ['DEEPSEEK_API_KEY'] = OTHER   # (an old key left in the environment)
        self.assertEqual(api_keys.resolve('deepseek'), (OTHER, 'environment variable DEEPSEEK_API_KEY'))
        api_keys.store('deepseek', KEY)
        self.assertEqual(api_keys.resolve('deepseek')[0], KEY)
        self.assertEqual(api_keys.resolve('deepseek', prefer_env=True)[0], OTHER)
        self.assertEqual(api_keys.key_for('https://api.deepseek.com'), KEY)
        self.assertEqual(api_keys.key_for('https://api.deepseek.com', api_key_env='DEEPSEEK_API_KEY'), OTHER)
        self.assertIn('not used while this key is stored', self.run_cli('list'))

    def test_names(self):
        self.assertEqual(api_keys.env_var('deepseek'), 'DEEPSEEK_API_KEY')
        self.assertEqual(api_keys.env_var('my-host'), 'MY_HOST_API_KEY')
        self.assertEqual(api_keys.name_of_env('OPENROUTER_API_KEY'), 'openrouter')
        self.assertEqual(api_keys.name_for_url('https://api.deepseek.com'), 'deepseek')
        self.assertEqual(api_keys.name_for_url('https://api.deepseek.com/anthropic'), 'deepseek')
        self.assertEqual(api_keys.name_for_url('https://openrouter.ai/api/v1'), 'openrouter')
        self.assertIsNone(api_keys.name_for_url('http://localhost:11434/v1'))
        self.assertEqual(api_keys.key_name('https://openrouter.ai/api/v1', key='deepseek'), 'deepseek')
        self.assertEqual(api_keys.key_name('https://example.invalid', api_key_env='OPENROUTER_API_KEY'), 'openrouter')

    def test_key_for(self):
        with self.assertRaises(SystemExit) as e:
            api_keys.key_for('https://api.deepseek.com')
        self.assertIn('python tools/api_keys.py set deepseek', str(e.exception.code))
        with self.assertRaises(SystemExit) as e:
            api_keys.key_for('https://models.example.invalid/v1')
        self.assertIn('--key NAME', str(e.exception.code))
        api_keys.store('deepseek', KEY)
        self.assertEqual(api_keys.key_for('https://api.deepseek.com'), KEY)
        self.assertEqual(api_keys.key_for('https://models.example.invalid/v1', key='deepseek'), KEY)
        os.environ['MY_TOKEN'] = OTHER   # (an environment variable of any name, as --api-key-env always allowed)
        self.assertEqual(api_keys.key_for('https://models.example.invalid/v1', api_key_env='MY_TOKEN'), OTHER)

    def test_not_a_key(self):
        for text, why in (('', 'nothing'), ('abc def ghi jkl mno', 'spaces'), ('short-key', 'characters long'),
                          ('test-key-0123456789abcdé', 'characters')):
            with self.assertRaises(api_keys.KeyStoreError) as e:
                api_keys.store('deepseek', text)
            self.assertIn(why, str(e.exception))
            if text:
                self.assertNotIn(text, str(e.exception))
        with self.assertRaises(api_keys.KeyStoreError):
            api_keys.store('Deep Seek', KEY)
        self.assertFalse(os.path.exists(self.path))

    def test_command_line(self):
        out = self.run_cli('set', 'deepseek', stdin=KEY + '\n')
        self.assertIn('Stored the deepseek key (...0123)', out)
        self.assertNotIn(KEY, out)
        out = self.run_cli('list')
        self.assertIn('deepseek', out)
        self.assertIn('...0123', out)
        self.assertNotIn(KEY, out)
        self.assertEqual(self.run_cli('where').strip(), self.path)
        self.assertIn('Removed', self.run_cli('remove', 'deepseek'))
        self.assertIn('No keys stored', self.run_cli('list'))

    def test_publish_names_a_stored_key(self):
        keys = [('deepseek', KEY), ('openrouter', OTHER)]
        self.assertEqual(publish.key_hits(keys, f'+api = "{KEY}"\n'), ['deepseek'])
        self.assertEqual(publish.key_hits(keys, 'nothing here'), [])


if __name__ == '__main__':
    unittest.main()
