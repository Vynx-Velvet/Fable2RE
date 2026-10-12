# The supported executable: identity, the 100 MiB over-read, and no title update (2026-10-10)

## Finding

`tools/setup_all.ps1`, the lifter analysis bundle (`research/lift/summaries.json.gz`) and the verification
manifest identified the supported game by one SHA-256, `39f0c8cd…5627d5`, labelled "Game of the Year
(USA/Europe), title update 1". That hash belongs to a **104,857,600-byte over-read copy** of the executable
(`iso/extracted/default.xex`, also copied to `Fable2Recomp/assets/game/`), not to the file on the disc.

- The disc's `default.xex` (`iso/full_extract/default.xex`) is 21,217,280 bytes, SHA-256
  `88c4ef2e18e65409444d1b068eff921d1f7e180a5ae64edc64ba6b0872372662`.
- The over-read copy's first 21,217,280 bytes are identical to it (`cmp -n 21217280`); 83,640,320 bytes of
  unrelated data follow.
- The XEX header accounts for exactly the disc file's size: header 0x4000 + four basic-compression data blocks
  of 0x1438000 bytes in total = 0x143C000.

A fresh user's extract produces the 21 MB file, so setup refused every real disc ("Unsupported executable"),
and `bundle.py check` refused the same file.

## What the executable is

From the XEX2 header (`python tools/xex_info.py <default.xex>`):

| Field | Value |
|---|---|
| Title ID | 4D5307F1 |
| Media ID | 716F0A0D (16-byte form A509A2D6D9E998327C398033716F0A0D) |
| Version / base version | 0x1A / 0x1A |
| Disc | 1 of 1 |
| Region | 0xFFFFFFFF (region-free) |
| Original PE | Fable2_xfr.exe, timestamp 2009-06-09 |

- **No title update.** Version equals base version; nothing in the project obtains or applies a `.xexp`, the
  codegen cannot apply one and the runtime's patch application is off. The "title update 1" label had no basis.
- **Edition.** "USA/Europe" has no basis either: the region field is region-free and the disc's
  `data/language` folders are en-uk, cs-cz, hu-hu, ko-kr, pl-pl, sk-sk and zh-cht. "Game of the Year" is
  consistent with the evidence (DLC2 audio banks and `DLCStartup.lua` on the disc, a 2009 build date after the
  2008 launch) but not proven by it.

## Change

- `tools/xex_info.py` (new): reads the header, reports the fields above, works out the executable's true
  extent from the compression block table or chain, hashes it, and flags trailing data. Exit codes: 0 supported,
  4 supported with trailing data, 3 unknown executable, 2 not a complete XEX2. It holds the table of supported
  executables and known aliases.
- `tools/lift/bundle.py`: the canonical identity is the true-extent hash `88c4ef2e…`; records made with the
  over-read hash stay valid through the alias table (`xex_matches`, `canonical_xex`, `check --xex PATH`).
  The shipped `.gz` files were not rewritten.
- Setup identifies the executable through `xex_info.py`; README, CONTRIBUTING, the names README, status and
  contributor docs now name the target by media ID and canonical hash.

Open: `tools/lift/difftest/make_skip.py` still compares the raw whole-file hash with the manifest's, so the
manifest filter refuses the 21 MB file until it uses `bundle.xex_matches` (prepared, applied with the setup
changes). Whether other pressings of the game ship the same `default.xex` is unknown; `xex_info.py` gives such
users a report to send.
