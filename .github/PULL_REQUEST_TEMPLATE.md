## Purpose

Describe the bounded problem and the behavior or knowledge this change adds.

## Evidence and validation

- Target executable/revision, when relevant:
- Evidence used (addresses, call sites, strings, behavior, public API, or format documentation):
- Checks run and results:
- Remaining uncertainty:

## Contribution checklist

- [ ] I did not include an ISO, XEX, extracted game asset/script, generated translation, decompiler export, save, secret, or build output.
- [ ] Naming/type claims include a confidence and a short basis in my own words.
- [ ] I distinguish compiled behavior from behavior tested in game.
- [ ] I updated documentation or a dated finding when the supported claim changed.
- [ ] I preserved upstream notices and identified new third-party code or assets.
- [ ] I ran `python tools/validate_metadata.py` when changing public metadata.
- [ ] SDK changes are in `patches/rexglue-sdk.patch` (`python tools/sdk_patch.py export`), and the `rexglue-sdk` submodule still points at the public release the patch is made for.
