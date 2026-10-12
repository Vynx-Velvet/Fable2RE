# Fable2Reimagined initial-commit audit

The workspace is being prepared as **Fable2RE / Fable2Reimagined**. Keep any
hosted repositories private until the outstanding checks below are resolved.

## Packaging fixes

- Removed the copied `postscriptsloaded.lua` game script from the initial-commit
  index and ignored its local mod directory. The local file is preserved.
- Stopped the C++ scaffold generator from embedding decompiler output in source.
- Included the authored `lifted/lifted.h` support header and three mod SDK headers
  that broad ignore rules previously excluded.
- Added staged-path and submodule checks in `tools/validate_commit.py`.
- Metadata validation now rejects a bundle with the wrong analysis version.

- 2026-10-08: re-exported the bundled analysis at version 7 from the cache the
  current lifter computed (`bundle.py export`); metadata validation and
  `bundle.py check` pass. Un-ignored `Fable2Recomp/src/game/debug/` (authored
  debug overlay, included by `src/main.cpp`), which the Visual Studio
  `[Dd]ebug/` rule hid: a clean clone could not have compiled.

## Data the lifter needs (commit these)

A clean checkout reproduces our readable lifted code only with the committed
research data: `research/names/*.tsv` (the naming dictionary), `research/catalog/functions.tsv`
(catalog and Lua-binding names, read by `lift.py`), `research/catalog/scope.tsv`,
`research/lift/summaries.json.gz` (the analysis bundle) and `research/symbols/func_db.json`
(read by `classes.py`, `vtables.py`, `scope.py` and `address_taken.py`; `setup_all.ps1`
does not regenerate it). They are metadata about the game (addresses, call graph,
names, string references), not game code. The model-written rewrites in
`Fable2Recomp/rewritten/` are game-derived translations and stay local, so a clean
checkout gets the lifter's readable form with our names, not those rewrites.

## State on 2026-10-12

**Layout.** One repository. `Fable2Recomp/` is a plain folder (its current files only; its earlier history, which
held generated code, is kept by the maintainers outside the repository). `rexglue-sdk/` points at the public ReXGlue
v0.8.0 release commit, and the project's SDK changes, including 14 fixes backported from later ReXGlue releases
and credited to their authors, are `patches/rexglue-sdk.patch` ([patches](../patches/README.md)), applied by
`tools/setup_all.ps1` through `tools/sdk_patch.py`. Nothing besides this repository needs hosting.

**History.** The repository starts from one initial commit of the reviewed tree. The two earlier local commits
carried a maintainer's machine path, a private model name and a personal e-mail address in their metadata and
files; they were replaced before anything was published.

**Publication review (2026-10-12).** Three independent reviews read the runtime, the SDK patch, the tools, the
research data, the documentation and the history for game-derived content, copied code, secrets and personal data,
licences, and anything that would break for a new user. No game code, scripts, text, assets or secrets were found
in the tree. Changes made from it:

- Game text: the catalog (`research/catalog/functions.tsv`) no longer carries the string literals each function
  references (about 9,600 short strings from the executable). The setup's image step recomputes them on the
  user's machine into the ignored `research/decomp/function_strings.tsv` (`tools/catalog/function_strings.py`);
  the scaffolder no longer copies strings into source files. A lifted-code excerpt in `docs/lifted-code.md` became
  an invented illustration.
- Console key: `tools/xex_decrypt.py` no longer embeds the retail XEX key; it reads it from the public ReXGlue SDK
  (from Xenia), which the setup needs anyway. The decrypted image still matches the reference hash.
- Licences and credit: upstream notices restored where files came from ReXGlue's template through Fable2Recomp
  (`src/hooks.cpp`, `src/heap.*`), project files marked MIT like the repository, Xenia credited in
  `src/gpu_sync.cpp`, Xenia's original copyright year restored in the SDK patch, a licence overview in the README,
  `Fable2Recomp/LICENSE` names both copyright holders.
- Removed: one-off scripts with machine paths (two of them destructive), scripts that injected desktop key and
  mouse input (replaced by the in-process `tools/autotest.py`), already-applied lifter patches, two runtime files
  that were never compiled, the Linux presets (the runtime is Windows-only), and a maintainer's session helper.
- Fixed for users: the fresh-clone test's git helper called itself forever; logs held open by a viewer no longer
  stop a setup; `kill_orphan_clang.ps1` (run by every build) only touches this repository's compilers; Ghidra and
  `llvm-symbolizer` are found through the environment instead of fixed folders; the setup checks for Git; stale
  documentation (separate checkouts, an already-fixed blocker, vcpkg-era steps) corrected; the CI also runs the
  unit tests.

**Checked:** `validate_commit.py` (0 blockers), metadata validation, `bundle.py check`, `sdk_patch.py status`,
whitespace, 91 unit tests and 13 packaging tests on Windows, and every CI step plus the unit tests on Linux
(Debian, Python 3.12) from a clone. A fresh clone of the committed state fetched its submodules from their public
URLs and ran every setup step on a real disc image, from the SDK build through codegen, the class model, the
whole-game lift and the game build to a check that reaches the title screen with sound (2.2 hours plus 3 minutes
for the disc steps, [record](../research/findings/2026-10-12-fresh-clone-end-to-end.md)). The promoted modules
(`Fable2Recomp/src/game/promoted/`) stay out until reviewed ([promoted code](promoted-code.md)).

## Hosting

1. (Done 2026-10-12.) `powershell -ExecutionPolicy Bypass -File tools/test_fresh_clone.ps1 -Iso "<disc image>"`
   (blocker 4).
2. (Done 2026-10-12.) One private GitHub repository; `main` only pushed.
3. (Done 2026-10-12.) The labels the issue forms use exist, and the CI workflow passes on GitHub's Ubuntu runner
   (whose PowerShell also runs the two PowerShell-based tests).
4. When the repository goes public: enable private vulnerability reporting, which GitHub offers only for public
   repositories (`.github/SECURITY.md` and the code of conduct point to it).

## Remaining release blockers

1. (Resolved 2026-10-08, see above.)
2. (Resolved 2026-10-11.) The runtime and SDK no longer live in local-only commits: the runtime is part of this
   repository and the SDK is the public release plus `patches/rexglue-sdk.patch`. Only this repository needs a
   host.
3. (Addressed 2026-10-10/11, verified end to end 2026-10-12.) `setup_all.ps1` reproduces the development pipeline:
   native bridges, class model, the differential-test exclusions through the verification manifest, name records,
   settings and the SDK patch. Game-derived files are still never distributed.
4. (Done 2026-10-12, [record](../research/findings/2026-10-12-fresh-clone-end-to-end.md).) Run generation,
   compilation and runtime smoke checks in an isolated checkout using only committed tooling, declared
   dependencies and the user's game copy (`tools/test_fresh_clone.ps1`). It ran on the development machine with its installed toolchain; a machine
   without one is still untested. A new setup lifts 368 fewer functions than the development tree until the
   manifest is exported again after a class-model refresh.
5. (Reviewed 2026-10-12, see above.) Provenance of the published tree and its single commit. A review is not a
   legal opinion; the promoted modules need their own review before publication.

## Validation commands

```powershell
python tools/validate_commit.py
python tools/validate_metadata.py
python tools/lift/bundle.py check
git diff --cached --check
python tools/sdk_patch.py status
```

All of these pass as of 2026-10-12 (line-ending warnings only; the patch and third-party sources are exempt from
the whitespace check in `.gitattributes`). The packaging check reads
staged paths and initialized submodules; it does not certify copyright status,
inspect every historical blob, or prove remote availability. SDK-supplied GNU
binutils binaries are recognized only when identical to the recorded baseline.
