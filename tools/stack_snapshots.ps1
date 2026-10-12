# Launch Fable2.exe inside a kill-on-close Job Object and attach cdb non-invasively
# at each of the given offsets, dumping every thread's stack each time. All
# snapshots come from the SAME process, so you can see what moved and what did not.
#
# Usage:
#   tools/stack_snapshots.ps1 -At 15,45 -Tag freeze1 [-Preset win-amd64-debug] [-Frames 30]
param(
    [string]$Preset = 'win-amd64-debug',
    [int[]]$At = @(15, 45),
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
$start = Get-Date

try {
    foreach ($t in ($At | Sort-Object)) {
        $wait = $t - [int]((Get-Date) - $start).TotalSeconds
        if ($wait -gt 0 -and $p.WaitForExit($wait * 1000)) {
            Write-Host "stack_snapshots: game exited early with code $($p.ExitCode) before ${t}s"
            break
        }
        if ($p.HasExited) { Write-Host "stack_snapshots: game exited before ${t}s"; break }
        $stackFile = Join-Path $runDir "stacks_${Tag}_${t}s.txt"
        $script = Join-Path $runDir "stacks_${Tag}_${t}s.cdbscript"
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
        if (-not $cp.WaitForExit(120000)) { Write-Warning "cdb did not finish at ${t}s; killing"; try { $cp.Kill() } catch {} }
        Write-Host "stack_snapshots: ${t}s -> cdb exit $($cp.ExitCode); $stackFile"
    }
}
finally {
    [Fable2Job]::KillAll()
    $p.WaitForExit(5000) | Out-Null
    try { [IO.File]::WriteAllText($errFile, $errTask.Result) } catch {}
    [Fable2Job]::Close()
    Get-Process -Name Fable2 -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
}
