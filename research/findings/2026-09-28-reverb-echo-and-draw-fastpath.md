# 2026-09-28 — "cave echo" root-cause work and the identical-draw fast path

## Audio: what the raw dump says

`tools/analyze_audio_dump.py` plus the scratch scripts written today were run on the
690 s raw 5.1 dump (`runs/audio_dump.raw`, taken 16:09, driver-level, sample-exact
with the speaker output):

* The echo is **inside each channel of the game's own mix**, not something the
  stereo fold adds. Folding the rear channels at 0.707, 0.35 or 0 changes the echo
  metric by less than 0.05.
* The autocorrelation of the front and centre channels peaks at fixed lags
  (11.1, 16.5, 22.1, 28.2, 44.2, 55.5 ms) with values 0.6–0.8. A single reflection
  can never exceed 0.5; values that high mean the signal is *periodic* at those
  lags, i.e. the output is dominated by a feedback (comb) reverb tail with the dry
  signal nearly absent. That is exactly "everyone speaks inside a cave".
* The rear channels are ~17–22 ms delayed copies of the front (corr 0.6–0.75) and
  often louder than the front.
* Channel identities look sane (fl/fr, fc, bl/br pairs, LFE occasionally full band).

Conclusion: the environmental reverb effect the game runs (an XAudio2FX reverb
XAPO statically linked into the title, so recompiled code) is either fed wrong
parameters or its DSP is mistranslated. Scalar FP and every VMX builder used by
DSP code (lvlx/lvrx/stvlx/stvrx/lvsl/lvsr, vperm, vsldoi, vcfsx/vctsxs, packs,
unpacks, vmaddfp/vnmsubfp, vrfin, vexptefp, vsel, vcmpbfp, shifts) were audited
against the reversed-lane layout and are correct.

## Where the reverb lives in the recompiled code

Found by decrypting the XEX (`tools/xex_decrypt.py`) and pairing lis/addi constant
pools in the generated C++ (`tools/find_addr_refs.py`):

| Function | Role |
|---|---|
| `sub_82C161D8` | defines the zone table schema: `ZoneId, Room, RoomHF, RoomRolloffFactor, DecayHFRatio, Reflections, ReflectionsDelay, Reverb, ReverbDelay, Diffusion, HFReference, WetDryMix` (strings at 0x8200AFB8–0x8200B084, "Could not create table") |
| `sub_82CD7788` | reverb object update: flags at +188 (wet/dry), +189 (native block at +52), +190 (I3DL2 block at +136) |
| `sub_82CDF788` | `SetParameter(index, value)`: index 0 copies a 48-byte I3DL2 block, 1..12 one field |
| `sub_82CDF4F8` | `ReverbConvertI3DL2ToNative` (log10 via `sub_821B1580`, constants 1000.0f @0x820F8738, -4.0 @0x82014DD8) |
| `sub_82CDD6D0` | native parameter defaults (RearDelay 5, Position 6, PositionMatrix 27, diffusion 8, EQ 4/6, RoomSize 100) |
| `sub_82CDDB68` | wet/dry mix: obj+92 = f1 * 0.01 |
| `sub_82CDDB80` | XAPO `SetParameters`: converts the 84-byte native block into delay-line coefficients (sample rate at obj+88, delay clamp 4095) |
| `sub_82CD7960` | XAPO `LockForProcess` (6 channels, 48000 Hz) |
| `sub_822B4D70`, `sub_8234B378` | read the region property `RegionEnvironmentalReverb` (string 0x820A6718) |

Native block layout (r4 of `sub_82CDDB80`): 0 ReflectionsDelay, 4 ReverbDelay,
8/12 PositionLeft/Right, 16/20 PositionMatrixLeft/Right, 24/28 Early/LateDiffusion,
32 LowEQGain, 36 LowEQCutoff, 40 HighEQGain, 44 HighEQCutoff, 48 RearDelay,
52 RoomFilterFreq, 56 RoomFilterMain, 60 RoomFilterHF, 64 ReflectionsGain,
68 ReverbGain, 72 DecayTime, 76 Density, 80 RoomSize (all 4-byte fields).

I3DL2 block layout (r5 of `sub_82CDF788` index 0): Room, RoomHF, RoomRolloffFactor,
DecayTime, DecayHFRatio, Reflections, ReflectionsDelay, Reverb, ReverbDelay,
Diffusion, Density, HFReference (no WetDryMix; that is set separately).

## Hooks added (Fable2Recomp/src/hooks.cpp)

* `audio_reverb_log` (default true): logs every I3DL2 set, wet/dry set and native
  apply, de-duplicated by content hash.
* `audio_reverb_disable` (default false): forces ReflectionsGain/ReverbGain to
  -100 dB and the wet/dry mix to 0 at apply time. This is the kill switch for the
  echo while the real cause is fixed; it does not touch game data.

## Draw fast path status

The first measurement of `repeat_identical_draws` showed `repeated=0`: the
shared-memory invalidation generation changes on practically every CPU write, so
the check never passed. The check was replaced by "recorded draw used no
textures"; vertex buffers are trusted for the rest of the frame exactly like the
existing `vertex_buffers_in_sync_` logic already does.

The 18:00 run also showed the game already reaching 34–37 fps uncapped in town
before the fast path worked (skip of no-effect draws + earlier CP fixes), up from
17 fps in the morning.
