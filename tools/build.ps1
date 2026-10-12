# Build Fable2Recomp inside a kill-on-close Job Object so an interrupted build can
# never leave zombie clang.exe processes behind.
#
# Usage:
#   tools/build.ps1                          # debug preset, all targets
#   tools/build.ps1 -Preset win-amd64-release
#   tools/build.ps1 -Target Fable2 -Jobs 6
#   tools/build.ps1 -Configure               # (re)run cmake --preset first
#   tools/build.ps1 -Sdk                     # build + install rexglue-sdk (never while a codegen runs)
#
# Output is written to the console AND to out/build/<preset>/build.log.
param(
    [string]$Preset = 'win-amd64-debug',
    [string]$Target = '',
    [int]$Jobs = 0,
    [switch]$Configure,
    [switch]$KeepGoing,  # compile every file even after failures (ninja -k 0): shows all errors at once
    [switch]$Sdk        # build rexglue-sdk (preset win-amd64, target install) instead of Fable2Recomp
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
if ($Sdk) {
    $proj = Join-Path $root 'rexglue-sdk'
    if ($Preset -eq 'win-amd64-debug') { $Preset = 'win-amd64' }
    if (-not $Target) { $Target = 'install' }
} else {
    $proj = Join-Path $root 'Fable2Recomp'
}
$buildDir = Join-Path $proj "out/build/$Preset"
$log = Join-Path $buildDir 'build.log'

Add-Type -Path (Join-Path $PSScriptRoot 'JobObject.cs')
[Fable2Job]::Create()

# Reap anything a previous interrupted build left behind before we start.
& (Join-Path $PSScriptRoot 'kill_orphan_clang.ps1')

function Run-InJob([string]$exe, [string[]]$argv, [string]$cwd) {
    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = $exe
    $psi.Arguments = ($argv | ForEach-Object { if ($_ -match '\s') { '"' + $_ + '"' } else { $_ } }) -join ' '
    $psi.WorkingDirectory = $cwd
    $psi.UseShellExecute = $false
    $psi.RedirectStandardOutput = $true
    $psi.RedirectStandardError = $true
    $p = New-Object System.Diagnostics.Process
    $p.StartInfo = $psi
    $null = $p.Start()
    if (-not [Fable2Job]::Assign($p)) { Write-Warning "could not assign pid $($p.Id) to job object" }
    # Pump both streams to console + log without deadlocking.
    $outTask = $p.StandardOutput.ReadToEndAsync()
    $errTask = $p.StandardError.ReadToEndAsync()
    $p.WaitForExit()
    $out = $outTask.Result; $err = $errTask.Result
    if ($out) { $out | Tee-Object -FilePath $log -Append | Out-Host }
    if ($err) { $err | Tee-Object -FilePath $log -Append | Out-Host }
    return $p.ExitCode
}

try {
    if (Test-Path $log) { Remove-Item $log -Force }
    New-Item -ItemType Directory -Force (Split-Path $log) | Out-Null
    "=== build started $(Get-Date -Format s) preset=$Preset target=$Target" | Tee-Object -FilePath $log -Append | Out-Host

    if ($Configure -or -not (Test-Path (Join-Path $buildDir 'build.ninja'))) {
        $rc = Run-InJob 'cmake' @('--preset', $Preset) $proj
        if ($rc -ne 0) { throw "cmake configure failed with exit code $rc" }
    }

    $argv = @('--build', $buildDir)
    if ($Target) { $argv += @('--target', $Target) }
    if ($Jobs -gt 0) { $argv += @('--parallel', "$Jobs") }
    if ($KeepGoing) { $argv += @('--', '-k', '0') }
    $rc = Run-InJob 'cmake' $argv $proj
    "=== build finished $(Get-Date -Format s) exit=$rc" | Tee-Object -FilePath $log -Append | Out-Host
    exit $rc
}
finally {
    # Whatever happened (success, failure, Ctrl+C), nothing we spawned survives us.
    [Fable2Job]::KillAll()
    [Fable2Job]::Close()
    & (Join-Path $PSScriptRoot 'kill_orphan_clang.ps1') | Out-Null
}
