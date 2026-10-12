"""Synthetic regression tests; no game files or external dependencies required."""
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import validate_commit as commit
import validate_metadata as metadata


class CommitValidationTests(unittest.TestCase):
    def test_game_script_is_rejected_even_when_force_staged(self):
        index = "100644 deadbeef 0\tmods/example/gamescripts/copied.lua\0"
        with patch.object(commit, "git", return_value=index):
            self.assertTrue(commit.audit(Path("unused")))

    def _audit(self, *paths):
        index = "".join(f"100644 deadbeef 0\t{p}\0" for p in paths)
        with patch.object(commit, "git", return_value=index):
            return commit.audit(Path("unused"))

    def _content_errors(self, *paths):
        # (the synthetic indexes below do not hold the required runtime headers; that rule has its own test)
        return [e for e in self._audit(*paths) if "required authored" not in e]

    def test_bank_derived_mod_files_are_rejected(self):
        # Any bank folder, not only gamescripts: the mounted gamescripts_r, GUI scripts, case variants.
        for path in ("mods/MyQuest/gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua",
                     # (the example's make_example.py output: its .gitignore keeps it unstaged, this catches a forced add)
                     "mods/_Example_ModLoadTest/gamescripts_r/scripts/miscellaneous/saveload/postscriptsloaded.lua",
                     "mods/MyMenus/guiscripts/scripts/gameface/menu/menulib.lua",
                     "mods/_Disabled/GameScripts_R/scripts/a.lua",
                     "mods/Levels/levels/worlds/albion/x.engine_data"):
            with self.subTest(path=path):
                errors = self._content_errors(path)
                self.assertEqual(len(errors), 1)
                self.assertIn(".bnk in a mod", errors[0])

    def test_data_and_text_mod_files_are_rejected(self):
        errors = self._content_errors("mods/MyDebug/data/scripts/Startup/DebugMenu.txt", "mods/MyText/text/en-uk.txt")
        self.assertEqual(len(errors), 2)
        self.assertIn("game data file", errors[0])
        self.assertIn("exported game text", errors[1])

    def test_decompiled_and_game_data_suffixes_are_rejected_anywhere(self):
        for path in ("research/notes/menulib.src.lua", "mods/MyMod/menulib.src.lua",
                     "docs/samples/book.babel", "tools/fixtures/startup.vfsconfig"):
            with self.subTest(path=path):
                self.assertTrue(self._content_errors(path))

    def test_authored_mod_files_are_allowed(self):
        self.assertEqual(self._content_errors(
            "mods/README.md", "mods/_Example_HelloNative/hello_mod.cpp", "mods/MyTuning/tuning.toml",
            "mods/_Example_ModLoadTest/README.md", "mods/_Example_ModLoadTest/modtest.lua",
            "mods/_Example_ModLoadTest/make_example.py", "mods/_Example_ModLoadTest/.gitignore",
            "mods/MyPlugin/native/README.md"), [])

    def test_native_plugin_binary_is_rejected(self):
        self.assertTrue(self._content_errors("mods/_Example_HelloNative/native/HelloMod.dll"))

    def test_authored_lift_support_is_allowed(self):
        self.assertEqual(self._audit(*sorted(commit.REQUIRED["."])), [])

    def test_required_runtime_headers_must_be_staged(self):
        errors = self._audit("README.md")
        self.assertTrue(any("Fable2Recomp/lifted/lifted.h" in e and "required authored" in e for e in errors))

    def test_generated_runtime_material_is_rejected(self):
        for path in ("Fable2Recomp/lifted/lifted.0.0.cpp", "Fable2Recomp/lifted/native_decls.h",
                     "Fable2Recomp/generated/Fable2_recomp.1.cpp", "Fable2Recomp/rewritten/sub_82000010.cpp"):
            with self.subTest(path=path):
                self.assertTrue(any("must not be staged" in e for e in self._audit(path)))

    def test_sdk_gitlink_must_be_the_patch_base(self):
        self.assertRegex(commit.sdk_base() or "", r"^[0-9a-f]{40}$")
        other = "0" * 40

        def fake_git(repo, *args):
            if args[0] == "ls-files":
                # the repository stages the submodule at another commit; inside the submodule, an empty index
                return f"160000 {other} 0\trexglue-sdk\0" if str(repo) == "unused" else ""
            if args[:2] == ("rev-parse", "HEAD"):
                return other + "\n"
            if args[0] == "diff":
                return ""
            raise AssertionError(args)
        with patch.object(commit, "git", side_effect=fake_git), patch.object(Path, "exists", return_value=True):
            errors = commit.audit(Path("unused"))
        self.assertTrue(any("not the public ReXGlue release" in e for e in errors))

    MODULE = ("// CExample (vtable 0x82000000): methods of the class as readable C++.\n"
              "// Promoted from model rewrites (tools/rewrite/promote.py, docs/promoted-code.md).\n"
              "uint64_t Example(CpuState& ctx, uint8_t* base) {\n\treturn 0;\n}\n"
              "PROMOTED_ENTRY(3, sub_82000010, 0x82000010) { ctx.r3.u64 = Example(ctx, base); }\n")

    def _promoted_index(self, module, review):
        files = {"Fable2Recomp/src/game/promoted/CExample.cpp": module,
                 "Fable2Recomp/src/game/promoted/REVIEW.tsv": review}

        def fake_git(repo, *args):
            if args[0] == "ls-files":
                return "".join(f"100644 deadbeef 0\t{p}\0" for p in files)
            if args[0] == "show":
                return files[args[1][1:]]
            raise AssertionError(args)
        return fake_git

    def test_reviewed_promoted_module_is_allowed(self):
        review = "module\tfunction\tverdict\treviewer\tdate\nCExample\tsub_82000010\tOK\tx\t2026-10-08\n"
        # (modules written before 2026-10-11 carry the older header wording)
        for module in (self.MODULE, self.MODULE.replace("Promoted from model", "Promoted from verified model")):
            with self.subTest(header=module.split("\n")[1][:40]), \
                    patch.object(commit, "git", side_effect=self._promoted_index(module, review)):
                errors = [e for e in commit.audit(Path("unused")) if "required authored" not in e]
                self.assertEqual(errors, [])

    def test_unreviewed_or_quoting_promoted_module_is_rejected(self):
        review = "module\tfunction\tverdict\treviewer\tdate\n"
        quoting = self.MODULE.replace("return 0;", 'return 0;  // "Drone"')
        with patch.object(commit, "git", side_effect=self._promoted_index(quoting, review)):
            errors = commit.audit(Path("unused"))
            self.assertTrue(any("no OK review record" in e for e in errors))
            self.assertTrue(any("comment quotes text" in e for e in errors))

    def test_malformed_tsv_does_not_reach_field_validators(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / "names.tsv"
            path.write_text("address\tname\n12345678\n", encoding="utf-8")
            errors = []
            with patch.object(metadata, "ROOT", root):
                rows = metadata.read_tsv(path, ["address", "name"], ("address",), errors)
            self.assertEqual(rows, [])
            self.assertIn("too few columns", errors[0])


if __name__ == "__main__":
    unittest.main()
