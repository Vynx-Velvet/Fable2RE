# Contributor workflows

Fable2RE is designed so useful public work can be divided into small, reviewable changes. Most contributors do not need to understand the entire game, and dictionary/documentation work does not require committing generated game code.

## Choose a contribution lane

| Lane | Public output | Local evidence or inputs | Minimum validation |
|---|---|---|---|
| Naming dictionary | Rows in `research/names/*.tsv` | Locally generated/lifted code, strings, bindings, call relationships | Metadata validator; basis and confidence reviewed |
| Catalog and research | Factual TSV/JSON metadata or a dated finding | Local executable analysis and reproducible scripts | Schema check and documented revision/evidence |
| Conversion/lifting tools | Project-authored Python/PowerShell code | Generated code used locally as test input | Focused fixture/unit check or recorded local comparison |
| Readable C++ | Types and subsystem code in `Fable2Recomp/` | Instruction view, decompiler view, runtime observations | Build plus comparison path; runtime test when behavior is claimed |
| Native platform systems | Renderer, audio, input, storage, timing, or online interfaces | Existing runtime behavior and documented PC APIs | Interface tests and an integration scenario |
| Modding and original content | Tooling, stable APIs, examples, or original mods | User-owned extracted data used locally | Install/remove test and an original redistributable example |
| Documentation/testing | Guides, reproducible reports, compatibility results | A stated build and environment | Steps another contributor can repeat |

Use an issue template for work that needs coordination. Small dictionary corrections and documentation fixes can go directly to a pull request.

## Naming dictionary changes

The canonical public dictionary is `research/names/`. It targets the executable (media ID 716F0A0D) identified in `research/names/README.md`. Each entry needs a stable key, a valid C++ identifier, a confidence, and a short basis written in the contributor's own words.

Good evidence includes a Lua binding, an exact public-library match, repeated call-site behavior, a class-name string, consistent field use across methods, or an observed runtime effect. Visual similarity, a single weak string, and model confidence alone are not enough for `high` confidence.

The batch pipeline remains optional. A contributor may edit a few TSV rows by hand or use any local model/service:

```text
python tools/naming/make_batches.py --limit 2000
python tools/naming/run_local.py --model <name>
python tools/naming/merge.py --dry-run
python tools/naming/merge.py
python tools/validate_metadata.py
```

Generated prompts and answers remain under `build/` and are not committed. Hosted-model use requires explicit `--allow-remote` because prompts contain locally generated code. Pull requests contain only the resulting labels and plain-language basis.

## Repository layout and SDK changes

One repository holds the documentation, public metadata, tools, examples and the runtime (`Fable2Recomp/`).
Submodules hold only public third-party code: the ReXGlue SDK release (`rexglue-sdk/`), its libraries, and
`tools/extract-xiso`.

For a change to the SDK:

1. Edit the sources in `rexglue-sdk/` (its checkout stays at the public release; the patch is applied to the
   working tree).
2. `python tools/sdk_patch.py export` rewrites `patches/rexglue-sdk.patch` from that working tree;
   `python tools/sdk_patch.py status` confirms the tree matches the patch.
3. Commit the patch with the change that needs it. Do not commit the submodule at another revision:
   `tools/validate_commit.py` refuses it.

Moving to a newer ReXGlue release: check the new release out in `rexglue-sdk/`, apply the patch, resolve
conflicts, update `BASE` in `tools/sdk_patch.py`, export, then rebuild and run the game checks.

## Validation levels

Use precise language in issues and pull requests:

- **Identified:** evidence supports a name, type, boundary, or behavior hypothesis.
- **Implemented:** code or metadata exists.
- **Compiled:** the affected target builds.
- **Compared:** output or state was checked against the reference path.
- **Runtime-tested:** a stated scenario worked on a stated build.
- **Playthrough-validated:** relevant behavior survived a documented game sequence.

Higher levels include more evidence but do not erase stated limitations. CI validates public metadata and Python syntax without needing copyrighted game inputs; game-dependent checks remain local and their results belong in the pull request.

## Public-content boundary

Commit project-authored code, factual metadata, original documentation, original tests/fixtures, and original mod content. Keep ISOs, XEX files, keys, extracted assets/scripts, generated instruction translations, lifted output, raw decompiler exports, screenshots containing unreleased material, and build artifacts local. Tools should transform a user's own files on that user's machine.
