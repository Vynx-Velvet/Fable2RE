# Launch Fable2.exe inside a kill-on-close Job Object, let it run for -After seconds,
# then attach cdb non-destructively, dump every thread's stack to a file, and kill it.
# Useful when the guest goes silent (hang / spin) and we need to know where it sits.
#
# Usage:
#   tools/stack_snapshot.ps1 -After 30 -Tag hang1 [-Preset win-amd64-debug] [-Frames 30] [-GameArgs @('--x=y')]
param(
    [string]$Preset = 'win-amd64-debug',
    [int]$After = 30,
    [int]$Frames = 30,
    [string]$Tag = (Get-Date -Format 'yyyyMMdd_HHmmss'),
    [string[]]$GameArgs = @()
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$buildDir = Join-Path $root "Fable2Recomp/out/build/$Preset"
$exe = Join-Path $buildDir 'Fable2.exe'
$cdb = 'C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe'
$runDir = Join-Path $buildDir 'runs'
New-Item -ItemType Directory -Force $runDir | Out-Null
$stackFile = Join-Path $runDir "stacks_$Tag.txt"
$errFile = Join-Path $runDir "stacks_$Tag.stderr.txt"

Add-Type -Path (Join-Path $PSScriptRoot 'JobObject.cs')
[Fable2Job]::Create()
Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue

$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = $exe
$psi.Arguments = ($GameArgs -join ' ')
$psi.WorkingDirectory = $buildDir
$psi.UseShellExecute = $false
$psi.RedirectStandardError = $true
$psi.RedirectStandardOutput = $true
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $psi
$null = $p.Start()
[Fable2Job]::Assign($p) | Out-Null
$errTask = $p.StandardError.ReadToEndAsync()
$outTask = $p.StandardOutput.ReadToEndAsync()

try {
    $exited = $p.WaitForExit($After * 1000)
    if ($exited) {
        Write-Host "stack_snapshot: game exited early with code $($p.ExitCode); nothing to snapshot"
    } else {
        $script = Join-Path $runDir "stacks_$Tag.cdbscript"
        @(
            ".logopen $($stackFile -replace '\\','/')",
            "~*kb $Frames",
            ".logclose",
            "qd"
        ) | Set-Content -Path $script -Encoding ASCII
        $c = New-Object System.Diagnostics.ProcessStartInfo
        $c.FileName = $cdb
        $c.Arguments = "-p $($p.Id) -lines -cf `"$script`""
        $c.UseShellExecute = $false
        $c.RedirectStandardOutput = $true
        $c.RedirectStandardError = $true
        $cp = New-Object System.Diagnostics.Process
        $cp.StartInfo = $c
        $null = $cp.Start()
        [Fable2Job]::Assign($cp) | Out-Null
        $co = $cp.StandardOutput.ReadToEndAsync(); $ce = $cp.StandardError.ReadToEndAsync()
        if (-not $cp.WaitForExit(120000)) { Write-Warning "cdb did not finish; killing" }
        Write-Host "stack_snapshot: cdb exit $($cp.ExitCode); stacks in $stackFile"
    }
}
finally {
    [Fable2Job]::KillAll()
    $p.WaitForExit(5000) | Out-Null
    try { [IO.File]::WriteAllText($errFile, $errTask.Result) } catch {}
    [Fable2Job]::Close()
    Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
}
