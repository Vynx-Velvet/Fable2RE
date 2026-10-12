# Contributing to Fable2RE

Help us reconstruct Fable II as readable C++ and a fully native PC edition built from each user's own copy. The current target is the Game of the Year disc executable, media ID `716F0A0D`; `python tools/xex_info.py <default.xex>` checks yours. Useful contributions include names and types, reverse engineering, conversion tools, readable subsystem replacements, native platform and online work, debug restoration, mod and authoring tools, original examples, testing, and documentation.

Start with [project direction](docs/project-direction.md), [current status](docs/status.md), and [contributor workflows](docs/contributor-workflows.md). The workflow guide maps contribution types to public outputs, local evidence, and validation requirements. Building or running the current port also requires the [build guide](docs/building.md).

## Small contributions are useful

You do not need to convert a complete subsystem. A reviewed function name, field layout, format note, reproducible bug report, tool fixture, documentation correction, or original mod example can unblock later reconstruction. Use the naming issue template for proposed dictionary entries and the engineering or modding template for coordinated work.

Dictionary-only changes can be made without game files in the pull request and without building the runtime. Edit `research/names/*.tsv`, include a confidence and plain-language basis, then run:

```text
python tools/validate_metadata.py
```

See the [naming pipeline](tools/naming/README.md) for optional batch generation and local-model tooling.

## Code and research changes

1. Pick a bounded behavior or subsystem. Record the target executable (its media ID and canonical SHA-256 from `python tools/xex_info.py`) and your evidence.
2. Read the generated instructions as well as decompiler output. Treat inferred names, types, and AI explanations as hypotheses until checked.
3. Implement readable types and functions, preserving a comparison path where practical. Follow the [conversion guide](docs/conversion-guide.md) for rewrites.
4. Build the affected target and exercise the changed behavior. Record the configuration, scenario, result, and known limitations. A compile alone is not runtime validation.
5. Update the relevant guide or add a dated finding. Mark a function verified only after the required behavior check.

For reports, include the build/revision, the executable's media ID and canonical SHA-256 (`tools/xex_info.py`), hardware, settings, enabled mods, reproduction steps, and relevant log excerpts. Do not attach game binaries, extracted assets, full decompiler output, or saves containing material you cannot share.

## Pull requests and repository boundaries

Keep each pull request centered on one reviewable outcome. Complete the pull request template, state uncertainty, and link related source/submodule changes. CI validates public dictionaries, catalogs, and Python syntax without downloading game content.

The runtime, `Fable2Recomp/`, is part of this repository. `rexglue-sdk/` is the public ReXGlue release the project builds on (v0.8.0), pinned as a submodule; every change the project makes to it lives in `patches/rexglue-sdk.patch`, which `tools/setup_all.ps1` applies. After changing SDK sources, run `python tools/sdk_patch.py export` and commit the patch; never commit the submodule at another revision (`tools/validate_commit.py` refuses it). The detailed sequence is in [contributor workflows](docs/contributor-workflows.md).

Do not mix generated output with a source/tool change. A reviewer must be able to identify what was authored, what was observed, and what was produced locally.

## AI-assisted contributions

AI assistance is welcome and is part of the project's workflow alongside the team's FlyX experience. Review generated changes as carefully as any other contribution. Check addresses, calling conventions, object offsets, side effects, and observed behavior. Record tools/models when relevant to reproducing an analysis; no subscription is required to participate.

## What belongs in public contributions

Share project-authored tools, replacement code, documentation, factual metadata, and original mod content. Keep user-supplied ISOs/XEX files, extracted assets/scripts, generated instruction translations, lifted game output, raw decompiler exports, and build artifacts local. Never upload reference code pasted into a conversion scaffold without reviewing and removing the game-derived reference material. Model-written rewrites become publishable replacement code only through promotion and review ([promoted code](docs/promoted-code.md)); `tools/validate_commit.py` rejects a promoted module without a review record.

Local experiments may edit extracted scripts; distributable mods should contain your own content or instructions/patch tooling that operates on the user's copy, rather than bundled extracted files. Inspect staged changes explicitly: ignore rules do not remove already tracked files, and nested checkouts have their own rules.

Unless a file or subtree says otherwise, contributions to the umbrella repository are accepted under its [MIT License](LICENSE). Preserve the separate licenses and notices in submodules and third-party components, and identify newly introduced dependencies or assets in the pull request.

By participating, follow the [community standards](CODE_OF_CONDUCT.md). Do not submit third-party code or assets unless their source and compatible license are clear.
