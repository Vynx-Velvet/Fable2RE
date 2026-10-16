# One command from your own Fable II disc image to the native PC build (docs/building.md, docs/installer-plan.md).
#
#   powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -Iso "D:\path\Fable 2.iso"
#   powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1          (later, e.g. after git pull: only what changed)
#
# Steps (each one is skipped when its inputs are unchanged since it last finished and its outputs are still there):
#   verify     the disc image exists and carries an Xbox 360 file system
#   extract    tools/extract-xiso -> iso/extracted/
#   stage      default.xex must be the supported executable (tools/xex_info.py); it goes to Fable2Recomp/assets/game/,
#              with a junction assets/game/data -> the extracted data
#   toolchain  Python 3.12+ (+ tools/requirements.txt), CMake, Ninja, Clang, Visual Studio; builds the ReXGlue SDK
#              (rexglue.exe) when it is missing or the SDK checkout moved
#   codegen    rexglue codegen Fable2_config.toml -> Fable2Recomp/generated/
#   image      tools/xex_decrypt.py -> research/decomp/default_image.bin (checked against the reference image hash),
#              then the local research/decomp/function_strings.tsv (tools/catalog/function_strings.py)
#   classes    the class model -> cache/classes.json, structs.json, lifted/classes.h: from the shipped model
#              (classes.py --bundle, seconds) or from this machine's facts (lift.py --facts + classes.py --facts)
#   decls      native_gen.py -> lifted/native_decls.h, lifted/native_bridges.N.cpp
#   globals    tools/naming/global_strings.py -> research/decomp/global_names.tsv: the global string objects named
#              after their text (the game's own text, so written here and never shipped)
#   promoted   tools/rewrite/promoted_text.py render: the reviewed readable modules from Fable2Recomp/promoted/
#              (published without the game's text) -> Fable2Recomp/src/game/promoted/ with the text from this copy,
#              every file checked against the SHA-256 it was published with
#   lift       apply_names.py --init (records the names the lift reads), lift.py --all, then only tested functions
#              stay lifted (see -Tested)
#   config     Fable2.toml from Fable2Recomp/config/Fable2.default.toml and assets/game beside the exe (never overwrites)
#   build      tools/build.ps1 -Preset <preset> -Target Fable2 (always runs; ninja compiles only what changed)
#   check      with -Check only: tools/autotest.py --scenario menu boots the game once, unattended (no desktop input)
#
# Options:
#   -From <step>     start at this step; earlier steps are neither run nor checked (-From X -Force X re-runs X)
#   -To <step>       stop after this step
#   -Force <steps>   re-run these steps although up to date: "lift", "classes,lift" or "all" (every step run)
#   -Tested <mode>   which lifted functions stay lifted after the whole lift:
#                      auto      status if tools/lift/difftest/results/status.json exists, else manifest (default)
#                      manifest  those that tested OK in exactly their current form according to the shipped
#                                verification manifest research/lift/verified.json.gz (difftest/make_skip.py --manifest)
#                      status    this machine's own tester results (difftest/make_skip.py -> tools/lift/skip.txt)
#                      tester    run the differential tester on what changed first (tools/lift/update.ps1; needs a
#                                built release tree)
#                      none      keep every lifted function except overridden.txt (untested; for developers)
#   -Classes <src>   where the class model comes from:
#                      auto      shipped with -Tested manifest (when it fits this executable and typeflow is off),
#                                else facts (default)
#                      shipped   research/lift/class_model.json.gz: the model the shipped verification manifest was
#                                tested with, so the lift gives the tested text
#                      facts     computed here (lift.py --facts, about 25 minutes, then classes.py --facts)
#   -Jobs <n>        worker processes for lift.py and make_skip.py (default: processors, at most 8)
#   -Check           also run the check step (boots the game; closes any running Fable2.exe first)
#   -DryRun          only report which steps would run and which of their inputs changed
#
# State: tools/.setup/<step>.json records, for the last finished run of each step, the inputs its work started
# from and the outputs it left; setup.log the output, hashes.json caches file hashes by size and modification time.
# Everything produced here is derived from your own copy of the game: it stays on this machine and is not for
# distribution.
param(
    [string]$Iso = '',
    [string]$Preset = 'win-amd64-release',
    [string]$Force = '',
    [string]$From = '',
    [string]$To = '',
    [ValidateSet('auto', 'manifest', 'status', 'tester', 'none')][string]$Tested = 'auto',
    [ValidateSet('auto', 'shipped', 'facts')][string]$Classes = 'auto',
    [int]$Jobs = 0,
    [switch]$Check,
    [switch]$DryRun
)
$ErrorActionPreference = 'Stop'
$Root = Split-Path -Parent $PSScriptRoot
$Proj = Join-Path $Root 'Fable2Recomp'
$Lift = Join-Path $PSScriptRoot 'lift'
$LiftCache = Join-Path $Lift 'cache'
$Difftest = Join-Path $Lift 'difftest'
$StampDir = Join-Path $PSScriptRoot '.setup'
$LogFile = Join-Path $StampDir 'setup.log'
$HashFile = Join-Path $StampDir 'hashes.json'
$Extracted = Join-Path $Root 'iso/extracted'
$GameDir = Join-Path $Proj 'assets/game'
$StagedXex = Join-Path $GameDir 'default.xex'
$Generated = Join-Path $Proj 'generated'
$Image = Join-Path $Root 'research/decomp/default_image.bin'
# strings each function references, from the image: local context for the naming tools (not in the catalog)
$FuncStrings = Join-Path $Root 'research/decomp/function_strings.tsv'
# names of the game's global string objects, from their text: local too (tools/naming/global_strings.py)
$GlobalNames = Join-Path $Root 'research/decomp/global_names.tsv'
$GlobalStringsTool = Join-Path $PSScriptRoot 'naming/global_strings.py'
$ScopeTsv = Join-Path $Root 'research/catalog/scope.tsv'
$Bundle = Join-Path $Root 'research/lift/summaries.json.gz'
$Manifest = Join-Path $Root 'research/lift/verified.json.gz'
$ClassModel = Join-Path $Root 'research/lift/class_model.json.gz'
$ManifestSkip = 'cache/manifest_skip.txt'   # (relative to tools/lift: lift.py --funcs splits its argument at commas)
$Status = Join-Path $Difftest 'results/status.json'
$Names = Join-Path $Root 'research/names'
$CatalogFunctions = Join-Path $Root 'research/catalog/functions.tsv'
$FuncDb = Join-Path $Root 'research/symbols/func_db.json'
$Promoted = Join-Path $Proj 'src/game/promoted'                      # rendered here (local: carries the game's text)
$PublishedPromoted = Join-Path $Proj 'promoted'                      # as the repository holds them
$PromotedText = Join-Path $PSScriptRoot 'rewrite/promoted_text.py'
$Rewritten = Join-Path $Proj 'rewritten'
$Sdk = Join-Path $Root 'rexglue-sdk'
$Rexglue = Join-Path $Sdk 'out/install/win-amd64/bin/rexglue.exe'
$SdkPatch = Join-Path $Root 'patches/rexglue-sdk.patch'
$ExeDir = Join-Path $Proj "out/build/$Preset"
$Template = Join-Path $Proj 'config/Fable2.default.toml'
$InstallConfig = Join-Path $Proj 'config/install_default_config.cmake'
$XexInfo = Join-Path $PSScriptRoot 'xex_info.py'
$XexDecrypt = Join-Path $PSScriptRoot 'xex_decrypt.py'
$FuncStringsTool = Join-Path $PSScriptRoot 'catalog/function_strings.py'
$AutoTest = Join-Path $PSScriptRoot 'autotest.py'
New-Item -ItemType Directory -Force $StampDir | Out-Null

$Steps = @('verify', 'extract', 'stage', 'toolchain', 'codegen', 'image', 'classes', 'decls', 'globals', 'promoted', 'lift',
           'config', 'build', 'check')

# Supported executables by whole-file SHA-256: used only when tools/xex_info.py (which also recognises copies with
# trailing data) is not there. The shipped lifter analysis and verification manifest name the one they belong to.
$SupportedXex = @{
    '88c4ef2e18e65409444d1b068eff921d1f7e180a5ae64edc64ba6b0872372662' = 'Fable II disc executable, Game of the Year disc (media ID 716F0A0D)'
    '39f0c8cdd2ba3486ba347e8e6646a783b2b372c874b21d762e455349185627d5' = 'the same executable as a 100 MiB over-read copy (older extract)'
}
# SHA-256 of the decrypted image (tools/xex_decrypt.py) of each supported executable: both files above give this one.
$KnownImages = @{
    'bd168b4c9b9c5603aaf8e0123b23c13ec97cccf38291766f864f3b9c2f34389b' = 'Fable II disc executable 88c4ef2e... (Game of the Year disc)'
}

function Log([string]$msg) {
    $line = "$(Get-Date -Format s)  $msg"
    Write-Host $line
    # a viewer holding the log open must not stop a setup of several hours: the console still shows the line
    try { Add-Content -LiteralPath $LogFile -Value $line -ErrorAction Stop }
    catch { Write-Warning "could not write to ${LogFile}: $($_.Exception.Message)" }
}

function Step-Index([string]$name, [string]$what) {
    $i = [array]::IndexOf($Steps, $name.ToLower())
    if ($i -lt 0) { throw "unknown step '$name' for $what (steps: $($Steps -join ', '))" }
    return $i
}

$FromIndex = 0
if ($From) { $FromIndex = Step-Index $From '-From' }
$ToIndex = $Steps.Count - 1
if ($To) { $ToIndex = Step-Index $To '-To' }
if ($ToIndex -lt $FromIndex) { throw "-To $To comes before -From $From" }
$ForceAll = $false
$ForceSet = @{}
foreach ($f in ($Force -split '[,;\s]+' | Where-Object { $_ })) {
    if ($f -eq 'all') { $ForceAll = $true } else { $ForceSet[$Steps[(Step-Index $f '-Force')]] = $true }
}
if ($Jobs -le 0) { $Jobs = [Math]::Min(8, [Environment]::ProcessorCount) }
$Mode = $Tested
if ($Mode -eq 'auto') { if (Test-Path -LiteralPath $Status) { $Mode = 'status' } else { $Mode = 'manifest' } }
$IsoFull = $null
if ($Iso) {
    if (-not (Test-Path -LiteralPath $Iso -PathType Leaf)) { throw "ISO not found: $Iso" }
    $IsoFull = (Get-Item -LiteralPath $Iso).FullName
}

# The SDK and the game's CMake presets read REXSDK; tool output is read through a pipe (unbuffered, UTF-8).
$env:REXSDK = $Sdk
$env:PYTHONUNBUFFERED = '1'
if (-not $env:PYTHONIOENCODING) { $env:PYTHONIOENCODING = 'utf-8' }
# Below normal priority (inherited by the compilers and tools started from here): the machine stays usable.
try { [System.Diagnostics.Process]::GetCurrentProcess().PriorityClass = 'BelowNormal' } catch { }

# ---- hashes ----------------------------------------------------------------------------------------------------

$script:Hashes = @{}
$script:HashesDirty = $false
if (Test-Path -LiteralPath $HashFile) {
    try {
        (Get-Content -Raw -LiteralPath $HashFile | ConvertFrom-Json).PSObject.Properties |
            ForEach-Object { $script:Hashes[$_.Name] = [string]$_.Value }
    } catch { $script:Hashes = @{} }
}

function Save-Hashes {
    if ($script:HashesDirty) {
        $script:Hashes | ConvertTo-Json -Compress | Set-Content -Encoding UTF8 -LiteralPath $HashFile
        $script:HashesDirty = $false
    }
}

# SHA-256 of a file's content; reused while its size and modification time stay the same.
function Sha256([string]$path) {
    $f = Get-Item -LiteralPath $path
    $tag = '{0}|{1}|' -f $f.Length, $f.LastWriteTimeUtc.Ticks
    $c = $script:Hashes[$f.FullName]
    if ($c -and $c.StartsWith($tag)) { return $c.Substring($tag.Length) }
    $h = (Get-FileHash -Algorithm SHA256 -LiteralPath $f.FullName).Hash.ToLower()
    $script:Hashes[$f.FullName] = $tag + $h
    $script:HashesDirty = $true
    return $h
}

function Text-Sha([string]$text) {
    $sha = [System.Security.Cryptography.SHA256]::Create()
    try { return -join ($sha.ComputeHash([System.Text.Encoding]::UTF8.GetBytes($text)) | ForEach-Object { $_.ToString('x2') }) }
    finally { $sha.Dispose() }
}

function File-Id([string]$path) {
    if (Test-Path -LiteralPath $path -PathType Leaf) { return Sha256 $path }
    return 'missing'
}

# The files of a folder whose names match `match`, as one hash over their relative names and contents.
function Tree-Id([string]$dir, [string]$match = '.', [switch]$Recurse) {
    if (-not (Test-Path -LiteralPath $dir -PathType Container)) { return 'missing' }
    $base = (Get-Item -LiteralPath $dir).FullName.TrimEnd('\') + '\'
    $files = @(Get-ChildItem -LiteralPath $dir -File -Recurse:$Recurse | Where-Object { $_.Name -match $match } |
               Sort-Object FullName)
    if ($files.Count -eq 0) { return 'empty' }
    $lines = foreach ($f in $files) { $f.FullName.Substring($base.Length) + "`t" + (Sha256 $f.FullName) }
    return '{0} ({1} files)' -f (Text-Sha ($lines -join "`n")), $files.Count
}

# The Python modules of tools/lift (and tools/lift/difftest) that these entry modules import, directly or through
# each other: a static scan of their import lines, including imports inside functions. Standard library and
# installed packages are not files there and drop out.
function Py-Sources([string[]]$entries) {
    $dirs = @($Lift, $Difftest)
    $found = [ordered]@{}
    $todo = New-Object System.Collections.Generic.Queue[string]
    foreach ($e in $entries) { $todo.Enqueue($e) }
    while ($todo.Count -gt 0) {
        $m = $todo.Dequeue()
        if ($found.Contains($m)) { continue }
        $path = $null
        foreach ($d in $dirs) {
            $p = Join-Path $d "$m.py"
            if (Test-Path -LiteralPath $p -PathType Leaf) { $path = $p; break }
        }
        if (-not $path) { continue }
        $found[$m] = $path
        foreach ($line in [System.IO.File]::ReadAllLines($path)) {
            if ($line -match '^\s*from\s+([A-Za-z_]\w*)\s+import\b') { $todo.Enqueue($Matches[1]) }
            elseif ($line -match '^\s*import\s+([A-Za-z_][\w\s,.]*?)\s*(#.*)?$') {
                foreach ($part in ($Matches[1] -split ',')) {
                    $n = (($part.Trim() -split '\s+')[0] -split '\.')[0]
                    if ($n) { $todo.Enqueue($n) }
                }
            }
            foreach ($x in [regex]::Matches($line, "__import__\('([A-Za-z_]\w*)'\)")) { $todo.Enqueue($x.Groups[1].Value) }
        }
    }
    return $found
}

function Sources-Id([string[]]$entries) {
    $found = Py-Sources $entries
    $lines = foreach ($k in ($found.Keys | Sort-Object)) { "$k`t" + (Sha256 $found[$k]) }
    return '{0} ({1} files)' -f (Text-Sha ($lines -join "`n")), $found.Count
}

# LIFT_* environment variables change what the lifter writes (lift.py, emit.py, passes.py, fields.py ...).
function Env-Id {
    $v = @(Get-ChildItem Env: | Where-Object { $_.Name -like 'LIFT_*' } | Sort-Object Name |
           ForEach-Object { "$($_.Name)=$($_.Value)" })
    if ($v.Count -eq 0) { return 'none' }
    return $v -join ';'
}

function Generated-Id { return Tree-Id $Generated '^Fable2_(recomp\.\d+\.cpp|init\.(h|cpp))$' }

function Types-On {
    if ($env:LIFT_TYPES) { return $env:LIFT_TYPES -eq '1' }
    return Test-Path -LiteralPath (Join-Path $LiftCache 'types.on')
}

# The whole-game analysis lift.py lifts with (lift.py summaries() / signatures()): this machine's own
# (tools/lift/cache/*.pkl from summarize.py and signatures.py) or the shipped bundle.
function Add-Analysis($o) {
    $pkl = Join-Path $LiftCache 'summaries.pkl'
    if (Test-Path -LiteralPath $pkl) { $o['analysis'] = 'this machine: ' + (Sha256 $pkl) }
    else { $o['analysis'] = 'shipped: ' + (File-Id $Bundle) }
    $o['signatures.pkl'] = File-Id (Join-Path $LiftCache 'signatures.pkl')
}

# ---- running tools ---------------------------------------------------------------------------------------------

# Runs a program; its output (stdout and stderr) goes to the console and to setup.log. Throws when it fails.
function Tool {
    param([string]$Exe, [string[]]$ArgList = @(), [string]$What = '', [switch]$NoThrow)
    if (-not $What) { $What = (@($Exe) + $ArgList) -join ' ' }
    if (-not (Get-Command $Exe -ErrorAction SilentlyContinue)) { throw "$Exe not found (needed for: $What)" }
    Log "  > $What"
    $eap = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'   # (native stderr lines arrive as error records through 2>&1)
    $w = New-Object System.IO.StreamWriter($LogFile, $true, (New-Object System.Text.UTF8Encoding($false)))
    try {
        $global:LASTEXITCODE = 0
        & $Exe @ArgList 2>&1 | ForEach-Object {
            if ($_ -is [System.Management.Automation.ErrorRecord]) { $s = $_.Exception.Message } else { $s = [string]$_ }
            Write-Host "    $s"
            $w.WriteLine("    $s")
        }
        $rc = $LASTEXITCODE
    } finally {
        $w.Dispose()
        $ErrorActionPreference = $eap
    }
    if ($NoThrow) { return $rc }
    if ($rc -ne 0) { throw "$What failed (exit code $rc)" }
}

# A separate PowerShell process: tools/build.ps1 ends with `exit`, which would end this script too.
function PS-Script([string]$script, [string[]]$argList = @()) {
    Tool 'powershell' (@('-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', $script) + $argList)
}

function Py-Has([string]$module) {
    $eap = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try { & python -c "import $module" 2>&1 | Out-Null; return ($LASTEXITCODE -eq 0) }
    finally { $ErrorActionPreference = $eap }
}

function Require([string]$exe, [string]$hint) {
    if (-not (Get-Command $exe -ErrorAction SilentlyContinue)) { throw "$exe not found. $hint" }
}

# Python 3.12+ that runs. On Windows 10/11 `python` can be the Microsoft Store alias (WindowsApps\python.exe): it
# only prints "Python was not found ..." and exits with 9009.
function Assert-Python {
    Require 'python' 'Install Python 3.12+ (python.org) and make sure it is on PATH.'
    $eap = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $out = @(& python -c 'import sys; print(sys.version.split()[0]); sys.exit(0 if sys.version_info >= (3, 12) else 1)' 2>&1)
        $rc = $LASTEXITCODE
    } finally { $ErrorActionPreference = $eap }
    $said = (($out | ForEach-Object { "$_".Trim() }) | Where-Object { $_ }) -join ' '
    if ($rc -eq 0) { return }
    if ($rc -eq 1) { throw "Python 3.12 or newer is needed (python on PATH is $said)" }
    throw ("python could not run (exit code $rc$(if ($said) { ": $said" })). Install Python 3.12+ from python.org " +
           'and make sure it is on PATH; the Microsoft Store alias (WindowsApps\python.exe) is not Python.')
}

# A file an earlier step makes. The advice re-runs that step although its inputs are unchanged; `hint` replaces it
# when something else provides the file (a submodule checkout).
function Need([string]$path, [string]$what, [string]$step, [string]$hint = '') {
    if (Test-Path -LiteralPath $path) { return }
    if (-not $hint) { $hint = "run the $step step again: tools/setup_all.ps1 -From $step -Force $step" }
    throw "$what not found ($path): $hint"
}

# lift.py, native_gen.py and the facts use cache/summaries.pkl when this machine computed it, else the shipped
# analysis, which is valid only for the default.xex it was computed from and the current analysis rules.
function Assert-Analysis {
    if (Test-Path -LiteralPath (Join-Path $LiftCache 'summaries.pkl')) { return }
    $rc = Tool 'python' @((Join-Path $Lift 'bundle.py'), 'check') -NoThrow
    if ($rc -ne 0) {
        throw ("the shipped whole-game analysis (research/lift/summaries.json.gz) does not fit this default.xex or this " +
               "lifter (see above). Compute it on this machine instead, from tools/lift and in this order:`n" +
               "  python vtables.py         -> cache/vtables.pkl        (reads research/decomp/default_image.bin: the image step)`n" +
               "  python address_taken.py   -> cache/address_taken.pkl  (reads the image too)`n" +
               "  python summarize.py       -> cache/summaries.pkl      (about 30 minutes; reads generated/ and both files above)`n" +
               "  python signatures.py      -> cache/signatures.pkl     (reads summaries.pkl)`n" +
               "then run setup_all again. The verification manifest belongs to the shipped analysis: with your own, " +
               "the lifted functions are untested here (-Tested tester after a first build, or -Tested none).")
    }
}

# Renames in research/names that were not applied yet (a developer edited the dictionary): apply_names.py applies
# them, including the promoted source modules (promote.py sync), before the class model, the declarations or the
# lifted code are written with the new names. Nothing to do before the first whole lift records the dictionary.
function Apply-PendingNames {
    if (-not (Test-Path -LiteralPath (Join-Path $LiftCache 'applied_names.json'))) { return }
    Push-Location $Lift
    try { Tool 'python' @('apply_names.py') 'python apply_names.py (renames not applied yet, if any)' }
    finally { Pop-Location }
}

# ---- steps -----------------------------------------------------------------------------------------------------

function In-Range([string]$name) {
    $i = Step-Index $name 'a step'
    return ($i -ge $FromIndex -and $i -le $ToIndex)
}

function Not-Run([string]$name, [string]$why) { if (In-Range $name) { Log "[$name] skipped: $why" } }

function Changed-Inputs($old, $now) {
    if (-not $old -or -not $old.inputs) { return @('no record of an earlier run') }
    $out = @()
    $oldNames = @($old.inputs.PSObject.Properties | ForEach-Object { $_.Name })
    foreach ($k in $now.Keys) {
        if ($oldNames -notcontains $k) { $out += "$k (new input)" }
        elseif ([string]$old.inputs.$k -ne [string]$now[$k]) { $out += $k }
    }
    foreach ($k in $oldNames) { if (-not $now.Contains($k)) { $out += "$k (no longer an input)" } }
    return $out
}

# Runs a step when it is in the -From/-To range and its inputs changed (or it is forced). `inputs` returns an
# ordered table name -> hash/value; $null for a step that always runs. The record is written after the body:
#   * the keys named in `outputs` (what the step itself writes: its output files, the tester's results) as the step
#     leaves them, so a deleted output runs the step again
#   * every other key as it was when the work began: before the body, or at the body's Snapshot-Inputs call. A
#     change that lands while the step runs (a rename during a 20-minute lift) then still counts as a change.
function Step([string]$name, [scriptblock]$inputs, [scriptblock]$body, [string[]]$outputs = @()) {
    if (-not (In-Range $name)) { return }
    $stampPath = Join-Path $StampDir "$name.json"
    $old = $null
    if (Test-Path -LiteralPath $stampPath) {
        try { $old = Get-Content -Raw -LiteralPath $stampPath | ConvertFrom-Json } catch { $old = $null }
    }
    $forced = $ForceAll -or $ForceSet.ContainsKey($name)
    $now = $null
    if ($inputs) {
        $now = & $inputs
        $changed = @(Changed-Inputs $old $now)
        Save-Hashes
        if (-not $forced -and $changed.Count -eq 0) { Log "[$name] up to date"; return }
        $why = if ($forced) { 'forced' } else { 'changed: ' + ($changed -join ', ') }
    } else {
        $why = 'always runs'
    }
    if ($DryRun) { Log "[$name] would run ($why)"; return }
    Log "[$name] running ($why)"
    $t0 = Get-Date
    $script:OldStamp = $old
    $script:StepForced = $forced
    $script:StampExtra = [ordered]@{}
    $script:StepInputs = $inputs
    $script:StepRecord = $now
    try {
        & $body
        $record = [ordered]@{}
        if ($inputs) {
            $after = $null
            if ($outputs.Count -gt 0) { $after = & $inputs }
            foreach ($k in $script:StepRecord.Keys) {
                if ($after -and $outputs -contains $k -and $after.Contains($k)) { $record[$k] = $after[$k] }
                else { $record[$k] = $script:StepRecord[$k] }
            }
        }
    } catch {
        Save-Hashes
        Log "[$name] FAILED: $($_.Exception.Message)"
        throw
    }
    [ordered]@{ step = $name; inputs = $record; extra = $script:StampExtra; finished = (Get-Date -Format s) } |
        ConvertTo-Json -Depth 4 | Set-Content -Encoding UTF8 -LiteralPath $stampPath
    Save-Hashes
    Log ("[$name] done in {0:N0} s" -f ((Get-Date) - $t0).TotalSeconds)
}

# Called by a step body after its own preparation and before its long work (pending renames applied: they rewrite
# the class model and the promoted modules, inputs of the lift). The record keeps the inputs as they are now.
function Snapshot-Inputs {
    if ($script:StepInputs) { $script:StepRecord = & $script:StepInputs }
}

Log ("setup_all: steps {0} .. {1}, preset {2}, tested functions: {3}, {4} jobs{5}" -f $Steps[$FromIndex],
     $Steps[$ToIndex], $Preset, $Mode, $Jobs, $(if ($DryRun) { ', dry run' } else { '' }))
if ($FromIndex -gt 0) { Log "  steps before $($Steps[$FromIndex]) are not run or checked (-From)" }

# ---- verify, extract, stage --------------------------------------------------------------------------------------

function Iso-Inputs {
    $f = Get-Item -LiteralPath $IsoFull
    return [ordered]@{ iso = $f.FullName; size = [string]$f.Length; modified = [string]$f.LastWriteTimeUtc.Ticks }
}

if ($IsoFull) {
    Step 'verify' { Iso-Inputs } {
        # the XDVDFS volume descriptor, at sector 32 of the game partition (plain XISO, XGD1, XGD2, XGD3 layouts)
        $magic = [System.Text.Encoding]::ASCII.GetBytes('MICROSOFT*XBOX*MEDIA')
        $found = $null
        $fs = [System.IO.File]::OpenRead($IsoFull)
        try {
            foreach ($part in @(0, 0x18300000, 0xFD90000, 0x2080000)) {
                $at = [int64]$part + 0x10000
                if ($at + $magic.Length -gt $fs.Length) { continue }
                $buf = New-Object byte[] $magic.Length
                [void]$fs.Seek($at, 'Begin')
                [void]$fs.Read($buf, 0, $buf.Length)
                if ([System.Text.Encoding]::ASCII.GetString($buf) -ceq 'MICROSOFT*XBOX*MEDIA') { $found = $part; break }
            }
        } finally { $fs.Dispose() }
        Log ('  ISO: ' + $IsoFull + (' ({0:N2} GB)' -f ((Get-Item -LiteralPath $IsoFull).Length / 1GB)))
        if ($null -eq $found) { Log '  warning: no Xbox 360 file system found at the usual offsets; extract-xiso decides' }
        else { Log ('  Xbox 360 file system at partition offset 0x{0:X}' -f $found) }
    }
    $extractedXexKey = 'iso/extracted/default.xex present'
    Step 'extract' {
        $o = Iso-Inputs
        $o[$extractedXexKey] = [string](Test-Path -LiteralPath (Join-Path $Extracted 'default.xex'))
        $o
    } {
        $src = Join-Path $PSScriptRoot 'extract-xiso'
        $bin = Join-Path $src 'build'
        $xiso = @((Join-Path $bin 'extract-xiso.exe'), (Join-Path $bin 'Release/extract-xiso.exe')) |
            Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
        if (-not $xiso) {
            Require 'cmake' 'Install CMake 3.29+ (cmake.org) and a C compiler to build tools/extract-xiso.'
            Need (Join-Path $src 'CMakeLists.txt') 'the extract-xiso sources' 'extract' 'fetch the submodule: git submodule update --init tools/extract-xiso'
            $cfg = @('-S', $src, '-B', $bin, '-DCMAKE_BUILD_TYPE=Release')
            if (Get-Command ninja -ErrorAction SilentlyContinue) {
                $cfg += @('-G', 'Ninja')
                # extract-xiso.c takes getopt from win32/getopt.c, whose body needs WIN32. clang's GNU-style driver
                # defines only _WIN32 (gcc and cl's default flags define both).
                if (Get-Command clang -ErrorAction SilentlyContinue) { $cfg += @('-DCMAKE_C_COMPILER=clang', '-DCMAKE_C_FLAGS=-DWIN32') }
            }
            Tool 'cmake' $cfg
            Tool 'cmake' @('--build', $bin, '--config', 'Release')
            $xiso = @((Join-Path $bin 'extract-xiso.exe'), (Join-Path $bin 'Release/extract-xiso.exe')) |
                Where-Object { Test-Path -LiteralPath $_ } | Select-Object -First 1
            if (-not $xiso) { throw "extract-xiso.exe was not built (looked in $bin and $bin\Release)" }
        }
        New-Item -ItemType Directory -Force $Extracted | Out-Null
        # options before the image: extract-xiso's getopt stops at the first file name
        Tool $xiso @('-x', '-d', $Extracted, $IsoFull)
        $xex = Join-Path $Extracted 'default.xex'
        if (-not (Test-Path -LiteralPath $xex)) { throw "default.xex not found in the extracted image ($Extracted)" }
    } @($extractedXexKey)
} elseif (Test-Path -LiteralPath (Join-Path $Extracted 'default.xex')) {
    Not-Run 'verify' 'no -Iso given (the files extracted earlier in iso/extracted are used)'
    Not-Run 'extract' 'no -Iso given (the files extracted earlier in iso/extracted are used)'
} elseif ((In-Range 'verify') -or (In-Range 'extract') -or (In-Range 'stage')) {
    throw 'pass -Iso <path to your Fable II disc image>: nothing has been extracted yet (iso/extracted/default.xex)'
}

# Is this default.xex the supported executable? tools/xex_info.py also accepts a copy with trailing data (an older
# extract over-read the file to 100 MiB); without it, the whole-file hashes above decide.
function Assert-Supported([string]$xex) {
    if (Test-Path -LiteralPath $XexInfo) {
        Assert-Python   # (else a Store alias's exit code would read as an unsupported executable)
        # 0: supported; 4: supported, followed by trailing data; 3: unknown executable; 2: not a complete XEX2
        $rc = Tool 'python' @($XexInfo, $xex) -NoThrow
        if ($rc -ne 0 -and $rc -ne 4) { throw "unsupported executable (tools/xex_info.py exit code $rc, see above)" }
        return
    }
    $h = Sha256 $xex
    if (-not $SupportedXex.ContainsKey($h)) {
        throw "Unsupported executable (default.xex SHA-256 $h). Supported: $($SupportedXex.Values -join '; ')"
    }
    Log "  default.xex: $($SupportedXex[$h]) ($h)"
}

Step 'stage' {
    [ordered]@{ 'iso/extracted/default.xex' = File-Id (Join-Path $Extracted 'default.xex'); 'xex_info.py' = File-Id $XexInfo
                'staged default.xex' = File-Id $StagedXex }
} {
    $src = Join-Path $Extracted 'default.xex'
    Need $src 'the extracted default.xex' 'extract' 'extract your disc image again: tools/setup_all.ps1 -Iso <image> -Force extract'
    Assert-Supported $src
    New-Item -ItemType Directory -Force $GameDir | Out-Null
    if ((File-Id $StagedXex) -ne (Sha256 $src)) {
        Copy-Item -Force -LiteralPath $src -Destination $StagedXex
        Log "  staged $StagedXex"
    } else { Log "  $StagedXex is already this file" }
    $dataLink = Join-Path $GameDir 'data'
    if (-not (Test-Path -LiteralPath $dataLink)) {
        # a directory junction: no copy of the 7 GB of game data
        New-Item -ItemType Junction -Path $dataLink -Target (Join-Path $Extracted 'data') | Out-Null
        Log "  junction $dataLink -> $(Join-Path $Extracted 'data')"
    }
} @('staged default.xex')

# ---- toolchain, codegen ------------------------------------------------------------------------------------------

function Sdk-Revision {
    if (-not (Get-Command git -ErrorAction SilentlyContinue)) { return 'unknown (no git)' }
    $eap = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try { $r = & git -C $Sdk rev-parse HEAD 2>&1 | Select-Object -First 1 } finally { $ErrorActionPreference = $eap }
    if ($LASTEXITCODE -ne 0) { return 'unknown' }
    return [string]$r
}

Step 'toolchain' { [ordered]@{ checks = 'v2'; 'rexglue-sdk revision' = Sdk-Revision; 'SDK patch' = File-Id $SdkPatch
                             'rexglue.exe' = [string](Test-Path -LiteralPath $Rexglue) } } {
    Assert-Python
    Require 'git' 'Install Git (git-scm.com): it fetches the submodules and applies the SDK patch.'
    Require 'cmake' 'Install CMake 3.29+ (cmake.org).'
    Require 'ninja' 'Install Ninja (winget install Ninja-build.Ninja).'
    Require 'clang' 'Install LLVM/Clang 20+ (winget install LLVM.LLVM).'
    # the Python packages of tools/requirements.txt (decryption for the image step, snapshot analysis for checks)
    $missing = @('cryptography', 'PIL', 'numpy') | Where-Object { -not (Py-Has $_) }
    if ($missing) {
        throw "Python packages missing ($($missing -join ', ')): python -m pip install -r tools/requirements.txt"
    }
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (-not (Test-Path $vswhere)) { throw 'Visual Studio Build Tools not found (needed for the Windows SDK and linker).' }
    Log "  $(python --version 2>&1); $(cmake --version | Select-Object -First 1); $(clang --version | Select-Object -First 1)"
    Need (Join-Path $Sdk 'CMakeLists.txt') 'the ReXGlue SDK sources' 'toolchain' 'fetch the submodule: git submodule update --init --recursive rexglue-sdk'
    # the project's changes to the SDK: the submodule is the public ReXGlue release, patches/rexglue-sdk.patch the
    # rest (tools/sdk_patch.py; nothing to do when it is already applied)
    Tool 'python' @((Join-Path $PSScriptRoot 'sdk_patch.py'), 'apply')
    # the codegen tool; ninja rebuilds only what changed since the last SDK build (never during a codegen)
    PS-Script (Join-Path $PSScriptRoot 'build.ps1') @('-Sdk')
    if (-not (Test-Path -LiteralPath $Rexglue)) { throw "the SDK build did not produce $Rexglue" }
}

Step 'codegen' {
    [ordered]@{ 'default.xex' = File-Id $StagedXex; 'Fable2_config.toml' = File-Id (Join-Path $Proj 'Fable2_config.toml')
                'rexglue.exe' = File-Id $Rexglue; output = Generated-Id }
} {
    Need $StagedXex 'the staged default.xex' 'stage'
    Need $Rexglue 'rexglue.exe' 'toolchain'
    Push-Location $Proj
    try { Tool $Rexglue @('codegen', 'Fable2_config.toml') }
    finally { Pop-Location }
    $init = Join-Path $Generated 'Fable2_init.h'
    if (-not (Test-Path -LiteralPath $init)) { throw "rexglue codegen finished without $init (see its output above)" }
} @('output')

# ---- image, classes, decls, lift ---------------------------------------------------------------------------------

Step 'image' { [ordered]@{ 'default.xex' = File-Id $StagedXex; 'xex_decrypt.py' = File-Id $XexDecrypt
                           'function_strings.py' = File-Id $FuncStringsTool; output = File-Id $Image
                           strings = File-Id $FuncStrings } } {
    Need $StagedXex 'the staged default.xex' 'stage'
    if (-not (Py-Has 'cryptography')) { throw "the Python package 'cryptography' is needed: python -m pip install cryptography" }
    New-Item -ItemType Directory -Force (Split-Path -Parent $Image) | Out-Null
    $tmp = "$Image.new"
    Tool 'python' @($XexDecrypt, $StagedXex, $tmp)
    $h = (Get-FileHash -Algorithm SHA256 -LiteralPath $tmp).Hash.ToLower()
    if (-not $KnownImages.ContainsKey($h)) {
        Remove-Item -Force -LiteralPath $tmp
        throw "the decrypted image (SHA-256 $h) is not the reference image of a supported executable"
    }
    if ((File-Id $Image) -eq $h) {
        Remove-Item -Force -LiteralPath $tmp
        Log "  $Image is already this image"
    } else {
        Move-Item -Force -LiteralPath $tmp -Destination $Image
        Log "  wrote $Image"
    }
    Log "  image: $($KnownImages[$h]) ($h)"
    Tool 'python' @($FuncStringsTool, '--image', $Image, '--out', $FuncStrings)
} @('output', 'strings')

# What lift.py --facts reads. Names (research/names) only rename the variables in the facts, which classes.py
# does not use, so they are left out here: a rename re-runs classes.py, not the facts.
function Facts-Inputs {
    $o = [ordered]@{}
    $o['generated'] = Generated-Id
    Add-Analysis $o
    $o['image'] = File-Id $Image
    $o['lifter (lift.py and its modules)'] = Sources-Id @('lift')
    $o['LIFT_ variables'] = Env-Id
    return $o
}

# Where the class model comes from (-Classes). The shipped model is the structure the development machine's lift and
# the shipped verification manifest were made with: lifting with it gives the text that was tested. typeflow.py
# (types.on) needs the facts pass's cache/flow, so it always computes the model here.
function Class-Source {
    if ($null -eq $script:ClassSource) {
        $want = $Classes
        if ($want -eq 'auto') {
            if ($Mode -eq 'manifest' -and -not (Types-On)) { $want = 'shipped' } else { $want = 'facts' }
        }
        if ($want -eq 'shipped') {
            if (Types-On) { throw '-Classes shipped: typeflow.py (types.on / LIFT_TYPES=1) needs the facts; use -Classes facts' }
            if (-not (Test-Path -LiteralPath $StagedXex)) {
                $want = 'facts'   # (no executable to check the model against yet: the classes step stops at Need)
            } elseif ((Tool 'python' @((Join-Path $Lift 'classes.py'), '--check') -NoThrow) -ne 0) {
                if ($Classes -eq 'shipped') { throw 'the shipped class model does not fit this default.xex (see above): use -Classes facts' }
                Log '  the shipped class model does not fit (see above): the classes step computes it from the facts'
                $want = 'facts'
            }
        }
        $script:ClassSource = $want
    }
    return $script:ClassSource
}

function Classes-Inputs {
    if ((Class-Source) -eq 'shipped') {
        $o = [ordered]@{}
        $o['class model'] = 'shipped: ' + (File-Id $ClassModel)
        $o['image'] = File-Id $Image   # (RTTI names of the classes the dictionary does not name)
    } else {
        $o = Facts-Inputs
        $o['class model'] = 'facts'
        $o['func_db.json'] = File-Id $FuncDb
        $o['types (typeflow.py)'] = [string](Types-On)
    }
    $o['research/names'] = Tree-Id $Names '\.tsv$'
    $entries = @('classes')
    if (Types-On) { $entries += 'typeflow' }
    $o['classes.py and its modules'] = Sources-Id $entries
    $model = @((Join-Path $LiftCache 'classes.json'), (Join-Path $LiftCache 'structs.json'), (Join-Path $Proj 'lifted/classes.h'))
    $o['class model present'] = [string](@($model | Where-Object { -not (Test-Path -LiteralPath $_) }).Count -eq 0)
    return $o
}

Step 'classes' { Classes-Inputs } {
    Need $Image 'the decrypted image' 'image'
    $shipped = (Class-Source) -eq 'shipped'
    if (-not $shipped) {
        Need (Join-Path $Generated 'Fable2_init.h') 'the generated code' 'codegen'
        Assert-Analysis
    }
    Apply-PendingNames
    Snapshot-Inputs
    Push-Location $Lift
    try {
        if ($shipped) {
            Tool 'python' @('classes.py', '--bundle')
        } else {
            $factsKey = Text-Sha (Facts-Inputs | ConvertTo-Json -Compress)
            $factsDir = Join-Path $LiftCache 'facts'
            $have = (Test-Path -LiteralPath $factsDir) -and @(Get-ChildItem -LiteralPath $factsDir -Filter '*.jsonl').Count -gt 0
            $last = $null
            if ($script:OldStamp -and $script:OldStamp.extra) { $last = $script:OldStamp.extra.facts }
            if ($script:StepForced -or -not $have -or $last -ne $factsKey) {
                Tool 'python' @('lift.py', '--facts', '--jobs', "$Jobs")
            } else { Log '  facts up to date (their inputs did not change): lift.py --facts not needed' }
            $script:StampExtra['facts'] = $factsKey
            Tool 'python' @('classes.py', '--facts')
            if (Types-On) { Tool 'python' @('typeflow.py') }
        }
    } finally { Pop-Location }
} @('class model present')

Step 'decls' {
    $o = [ordered]@{}
    Add-Analysis $o
    $o['research/names'] = Tree-Id $Names '\.tsv$'
    $o['native_gen.py and its modules'] = Sources-Id @('native_gen')
    $o['LIFT_ variables'] = Env-Id
    $o['native_decls.h present'] = [string](Test-Path -LiteralPath (Join-Path $Proj 'lifted/native_decls.h'))
    $o
} {
    Need $StagedXex 'the staged default.xex' 'stage'
    Assert-Analysis
    Apply-PendingNames
    Snapshot-Inputs
    Push-Location $Lift
    try { Tool 'python' @('native_gen.py') }
    finally { Pop-Location }
} @('native_decls.h present')

# The global string objects named after their text (research/decomp/global_names.tsv). The names are the game's
# own text, so they are written here from the user's copy, not shipped. The lift prints them, and the
# verification manifest's hashes were taken from text that carried them, so this comes before the lift.
Step 'globals' {
    $o = [ordered]@{}
    $o['generated'] = Generated-Id
    Add-Analysis $o
    $o['image'] = File-Id $Image
    $o['research/names'] = Tree-Id $Names '\.tsv$'   # (the dictionary names the string constructors)
    $o['func_db.json'] = File-Id $FuncDb
    $o['scope.tsv'] = File-Id $ScopeTsv
    $o['global_strings.py'] = File-Id $GlobalStringsTool
    $o['lifter (lift.py, readable.py and their modules)'] = Sources-Id @('lift', 'readable', 'scope', 'chunks')
    $o['LIFT_ variables'] = Env-Id
    $o['output'] = File-Id $GlobalNames
    $o
} {
    Need (Join-Path $Generated 'Fable2_init.h') 'the generated code' 'codegen'
    Need $Image 'the decrypted image' 'image'
    Assert-Analysis
    Tool 'python' @($GlobalStringsTool, '--out', $GlobalNames, '--jobs', "$Jobs")
} @('output')

# The reviewed readable modules (docs/promoted-code.md). The repository holds them without the game's text
# (Fable2Recomp/promoted/: references to the strings' addresses in the image); this writes them to
# src/game/promoted/ with the text from this copy and checks every file against the SHA-256 recorded when it was
# published. The lift leaves their functions out, so this comes before it.
Step 'promoted' {
    $o = [ordered]@{}
    $o['published'] = Tree-Id $PublishedPromoted
    $o['image'] = File-Id $Image
    $o['global names'] = File-Id $GlobalNames
    $o['promoted_text.py'] = File-Id $PromotedText
    $o['readable.py'] = Sources-Id @('readable')
    $o['rendered'] = Tree-Id $Promoted '\.(cpp|tsv)$'
    $o
} {
    Need $Image 'the decrypted image' 'image'
    Need $GlobalNames 'the global names' 'globals'
    Tool 'python' @($PromotedText, 'render')
} @('rendered')

function Lift-Inputs {
    $o = [ordered]@{}
    $o['generated'] = Generated-Id
    Add-Analysis $o
    $o['image'] = File-Id $Image
    $o['classes.json'] = File-Id (Join-Path $LiftCache 'classes.json')
    $o['structs.json'] = File-Id (Join-Path $LiftCache 'structs.json')
    if (Types-On) { $o['vartypes.json'] = File-Id (Join-Path $LiftCache 'vartypes.json') }
    $o['research/names'] = Tree-Id $Names '\.tsv$'
    $o['research/catalog/functions.tsv'] = File-Id $CatalogFunctions
    $o['global names'] = File-Id $GlobalNames
    $o['overridden.txt'] = File-Id (Join-Path $Lift 'overridden.txt')
    $o['promoted modules'] = Tree-Id $Promoted '\.cpp$'
    $o['local rewrites'] = Tree-Id $Rewritten '\.cpp$'
    $o['lifter and filter (lift.py, make_skip.py and their modules)'] = Sources-Id @('lift', 'make_skip')
    switch ($Mode) {
        'manifest' { $o['tested by'] = 'manifest ' + (File-Id $Manifest) }
        'none' { $o['tested by'] = 'nothing (-Tested none)' }
        default { $o['tested by'] = 'status.json ' + (File-Id $Status) }   # status, tester
    }
    $o['LIFT_ variables'] = Env-Id
    $lifted = Join-Path $Proj 'lifted'
    $o['lifted chunks present'] = [string]((Test-Path -LiteralPath $lifted -PathType Container) -and
        [bool](Get-ChildItem -LiteralPath $lifted -Filter 'lifted.*.cpp' -File | Select-Object -First 1))
    return $o
}

# 'tested by': the tester (-Tested tester) updates its results while this step runs
Step 'lift' { Lift-Inputs } {
    Need (Join-Path $Generated 'Fable2_init.h') 'the generated code' 'codegen'
    Need $Image 'the decrypted image' 'image'
    Need (Join-Path $LiftCache 'classes.json') 'the class model' 'classes'
    Need (Join-Path $LiftCache 'structs.json') 'the class model' 'classes'
    Need (Join-Path $Proj 'lifted/native_decls.h') 'the native declarations' 'decls'
    Assert-Analysis
    Apply-PendingNames
    Snapshot-Inputs
    Push-Location $Lift
    try {
        Tool 'python' @('names.py') 'python names.py (the naming dictionary has no problems)'
        # the dictionary as this lift reads it (lift.py starts after this): a rename that lands while the lift runs
        # stays pending for the next apply_names.py instead of being recorded as applied
        Tool 'python' @('apply_names.py', '--init')
        Tool 'python' @('lift.py', '--all', '--skip', 'overridden.txt', '--jobs', "$Jobs")
        switch ($Mode) {
            'manifest' {
                # the list: overridden.txt, every lifted function that is not exactly a form that tested OK, and the
                # manifest's known problem functions (tools/lift/skip.txt is the tester's own list: left alone)
                $rc = Tool 'python' @('difftest/make_skip.py', '--manifest', '../../research/lift/verified.json.gz',
                                      '--out', $ManifestSkip, '--jobs', "$Jobs") -NoThrow
                if ($rc -eq 2) {
                    throw ('the verification manifest does not apply here (see above), so no lifted function counts as ' +
                           'tested on this machine. Use -Tested tester after a first build, or -Tested none to keep ' +
                           'every lifted function untested.')
                }
                if ($rc -ne 0) { throw "difftest/make_skip.py failed (exit code $rc)" }
                Tool 'python' @('lift.py', '--funcs', $ManifestSkip, '--skip', $ManifestSkip)
            }
            'status' {
                Tool 'python' @('difftest/make_skip.py')
                Tool 'python' @('lift.py', '--funcs', 'skip.txt', '--skip', 'skip.txt')
            }
            'tester' {
                # test what changed (input profiles 0, 2, 3), skip list, drop: tools/lift/update.ps1 without -Build
                PS-Script (Join-Path $Lift 'update.ps1')
            }
            'none' { Log '  -Tested none: every lifted function stays lifted (only overridden.txt is left out)' }
        }
    } finally { Pop-Location }
} @('tested by', 'lifted chunks present')

# ---- config, build, check ----------------------------------------------------------------------------------------

Step 'config' {
    [ordered]@{ template = File-Id $Template; installer = File-Id $InstallConfig; preset = $Preset
                'default.xex' = File-Id $StagedXex
                'Fable2.toml present' = [string](Test-Path -LiteralPath (Join-Path $ExeDir 'Fable2.toml'))
                'assets/game present' = [string](Test-Path -LiteralPath (Join-Path $ExeDir 'assets/game/default.xex')) }
} {
    $toml = Join-Path $ExeDir 'Fable2.toml'
    if (Test-Path -LiteralPath $toml) { Log "  kept $toml" }
    elseif (Test-Path -LiteralPath $Template) {
        Tool 'cmake' @("-DSRC=$Template", "-DDST=$toml", '-P', $InstallConfig)
    } else { Log "  no settings template ($Template): the game runs with its compiled defaults" }
    # the game looks for assets/game beside Fable2.exe when no game directory is given on its command line
    # (tools/run_game.ps1 and tools/autotest.py give none)
    $rt = Join-Path $ExeDir 'assets/game'
    if (Test-Path -LiteralPath (Join-Path $rt 'default.xex')) { Log "  kept $rt" }
    else {
        Need $StagedXex 'the staged default.xex' 'stage'
        New-Item -ItemType Directory -Force $rt | Out-Null
        New-Item -ItemType Directory -Force (Join-Path $ExeDir 'assets/update') | Out-Null
        Copy-Item -Force -LiteralPath $StagedXex -Destination (Join-Path $rt 'default.xex')
        $data = Join-Path $rt 'data'
        if (-not (Test-Path -LiteralPath $data)) {
            $target = Join-Path $Extracted 'data'
            if (-not (Test-Path -LiteralPath $target)) { $target = Join-Path $GameDir 'data' }
            New-Item -ItemType Junction -Path $data -Target $target | Out-Null
        }
        Log "  staged $rt (default.xex, data -> the extracted game data)"
    }
} @('Fable2.toml present', 'assets/game present')   # (a deleted Fable2.toml is installed again on the next run)

Step 'build' $null {
    PS-Script (Join-Path $PSScriptRoot 'build.ps1') @('-Preset', $Preset, '-Target', 'Fable2')
    $exe = Join-Path $ExeDir 'Fable2.exe'
    if (-not (Test-Path -LiteralPath $exe)) { throw "the build finished without $exe (see $ExeDir\build.log)" }
    Log "  built $exe"
}

if ($Check) {
    Step 'check' {
        [ordered]@{ 'Fable2.exe' = File-Id (Join-Path $ExeDir 'Fable2.exe'); 'Fable2.toml' = File-Id (Join-Path $ExeDir 'Fable2.toml')
                    'autotest.py' = File-Id $AutoTest; scenario = 'menu' }
    } {
        Need (Join-Path $ExeDir 'Fable2.exe') 'Fable2.exe' 'build'
        # boots to the main menu, takes a snapshot, exits: build/autotest/setup_menu/summary.txt
        $a = @($AutoTest, '--scenario', 'menu', '--tag', 'setup_menu')
        if ($Preset -ne 'win-amd64-release') { $a += @('--preset', $Preset) }
        Tool 'python' $a
    }
} else {
    Not-Run 'check' 'not requested (-Check boots the game once to the main menu)'
}

Save-Hashes
if ($DryRun) { Log 'dry run: nothing was run' } else { Log 'setup complete' }
