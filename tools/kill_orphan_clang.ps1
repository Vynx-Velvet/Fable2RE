# Kill orphaned compiler/linker processes left behind by interrupted builds.
#
# A clang.exe whose parent (ninja.exe / cmake.exe / another clang) is gone is a
# zombie: nothing will ever collect it and it keeps burning CPU and RAM.
#
# Only compilers working on files of this repository are considered (their command line names its folder):
# compilers of other projects on the same machine are never touched.
#
# Usage:
#   tools/kill_orphan_clang.ps1          # kill only orphans (parent process gone)
#   tools/kill_orphan_clang.ps1 -All     # kill every clang/lld process of this repository, orphan or not
#   tools/kill_orphan_clang.ps1 -WhatIf  # list what would be killed
[CmdletBinding(SupportsShouldProcess = $true)]
param(
    [switch]$All
)

$names = @('clang.exe', 'clang++.exe', 'clang-cl.exe', 'lld-link.exe', 'ld.lld.exe', 'llvm-ar.exe')
# python: the differential tester (tools/lift/difftest/run.py) runs clang++ itself
$builders = @('ninja.exe', 'cmake.exe', 'make.exe', 'clang.exe', 'clang++.exe', 'clang-cl.exe', 'MSBuild.exe',
              'python.exe', 'python3.exe', 'py.exe')

# this repository's folder, with either kind of slash, as it appears in compiler command lines
$repo = (Split-Path -Parent $PSScriptRoot).TrimEnd('\', '/')
$repoForms = @($repo, ($repo -replace '\\', '/'), ($repo -replace '/', '\'))
function In-Repo($p) {
    $cmd = [string]$p.CommandLine
    foreach ($r in $repoForms) { if ($cmd.IndexOf($r, [StringComparison]::OrdinalIgnoreCase) -ge 0) { return $true } }
    return $false
}

$procs = Get-CimInstance Win32_Process | Where-Object { $names -contains $_.Name -and (In-Repo $_) }
if (-not $procs) {
    Write-Host "kill_orphan_clang: no compiler processes of this repository running."
    exit 0
}

$byPid = @{}
Get-CimInstance Win32_Process | ForEach-Object { $byPid[[int]$_.ProcessId] = $_ }

$killed = 0
$kept = 0
foreach ($p in $procs) {
    $parent = $byPid[[int]$p.ParentProcessId]
    $orphan = ($null -eq $parent) -or ($builders -notcontains $parent.Name)
    if ($All -or $orphan) {
        $why = if ($All) { 'all' } elseif ($null -eq $parent) { 'parent gone' } else { "parent is $($parent.Name)" }
        if ($PSCmdlet.ShouldProcess("$($p.Name) pid $($p.ProcessId) ($why)", 'Stop-Process')) {
            try {
                Stop-Process -Id $p.ProcessId -Force -ErrorAction Stop
                Write-Host "killed $($p.Name) pid $($p.ProcessId) ($why)"
                $killed++
            } catch {
                Write-Host "failed to kill pid $($p.ProcessId): $($_.Exception.Message)"
            }
        }
    } else {
        $kept++
    }
}
Write-Host "kill_orphan_clang: killed $killed, kept $kept (still owned by a live build)."
