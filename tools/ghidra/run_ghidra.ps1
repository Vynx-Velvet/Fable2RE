# Ghidra project for Fable II, generated from the user's own copy (see tools/ghidra/README.md).
#
#   tools/ghidra/run_ghidra.ps1 -Import            # create research/decomp/ghidra/Fable2 from default_image.bin
#                                                   # and seed functions, names, strings (make_inputs.py first)
#   tools/ghidra/run_ghidra.ps1 -Export             # decompile everything to research/decomp/c/
#   tools/ghidra/run_ghidra.ps1 -Export -Limit 500  # quick test
#
# Needs Ghidra 12 ($env:GHIDRA_HOME, or its support folder on PATH) and a JDK 21+
# (default C:/Program Files/Java/jdk-23, or $env:JAVA_HOME).
param(
    [switch]$Import,
    [switch]$Export,
    [int]$Threads = 6,
    [int]$Timeout = 60,
    [int]$Limit = 0,
    [string]$MaxMem = '12G'
)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent (Split-Path -Parent $PSScriptRoot)
$ghidra = $env:GHIDRA_HOME
if (-not $ghidra) {
    $headless = Get-Command analyzeHeadless.bat -ErrorAction SilentlyContinue
    if ($headless) { $ghidra = Split-Path -Parent (Split-Path -Parent $headless.Source) }
}
if (-not $ghidra -or -not (Test-Path (Join-Path $ghidra 'support/analyzeHeadless.bat'))) {
    throw 'Ghidra 12 not found: set $env:GHIDRA_HOME to its folder (the one that contains support/analyzeHeadless.bat).'
}
if (-not $env:JAVA_HOME -or -not (Test-Path "$env:JAVA_HOME/bin/java.exe")) { $env:JAVA_HOME = 'C:/Program Files/Java/jdk-23' }
$env:PATH = "$env:JAVA_HOME/bin;$env:PATH"
$decomp = Join-Path $root 'research/decomp'
$projDir = Join-Path $decomp 'ghidra'
$scripts = Join-Path $root 'tools/ghidra'
New-Item -ItemType Directory -Force $projDir | Out-Null
$launch = Join-Path $ghidra 'support/launch.bat'
$vmargs = '-XX:ParallelGCThreads=4 -XX:CICompilerCount=2'

function Run-Headless([string[]]$headlessArgs, [string]$log) {
    $all = @('fg', 'jdk', 'Ghidra-Headless', $MaxMem, $vmargs, 'ghidra.app.util.headless.AnalyzeHeadless') + $headlessArgs
    & $launch @all *>&1 | Tee-Object -FilePath $log
}

if ($Import) {
    Run-Headless @($projDir, 'Fable2',
        '-import', (Join-Path $decomp 'default_image.bin'), '-overwrite',
        '-loader', 'BinaryLoader', '-loader-baseAddr', '0x82000000',
        '-processor', 'PowerPC:BE:64:A2ALT-32addr', '-cspec', 'default',
        '-noanalysis', '-scriptPath', $scripts,
        '-postScript', 'Fable2Prepare.java', $decomp) (Join-Path $decomp 'import.log')
}
if ($Export) {
    $out = Join-Path $decomp 'c'
    Run-Headless @($projDir, 'Fable2', '-process', 'default_image.bin', '-noanalysis', '-readOnly',
        '-scriptPath', $scripts,
        '-postScript', 'Fable2ExportDecomp.java', $out, "$Threads", "$Timeout", "$Limit") (Join-Path $decomp 'export.log')
}
