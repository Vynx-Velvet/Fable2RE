# Fable2RE shell setup for manual work (the one-command route needs none of this: tools/setup_all.ps1).
# Usage, from the repository root: . .\env_setup.ps1   (dot-source so the variables stay in your session)

$FABLE2RE_ROOT = $PSScriptRoot

# --- ReXGlue SDK (CMake configures of Fable2Recomp read REXSDK) ---
$env:REXSDK = Join-Path $FABLE2RE_ROOT 'rexglue-sdk'
Write-Host "[OK] REXSDK = $env:REXSDK" -ForegroundColor Green

# --- rexglue.exe (the codegen tool; built by: powershell -File tools/build.ps1 -Sdk) ---
$rexglueBin = Join-Path $env:REXSDK 'out\install\win-amd64\bin'
if (Test-Path (Join-Path $rexglueBin 'rexglue.exe')) {
    $env:PATH = "$rexglueBin;$env:PATH"
    Write-Host "[OK] rexglue added to PATH" -ForegroundColor Green
} else {
    Write-Host "[!] rexglue.exe not built yet: powershell -File tools/build.ps1 -Sdk" -ForegroundColor Yellow
}

# --- LLVM/Clang ---
$clang = Get-Command clang -ErrorAction SilentlyContinue
if (-not $clang -and (Test-Path 'C:\Program Files\LLVM\bin\clang.exe')) {
    $env:PATH = "C:\Program Files\LLVM\bin;$env:PATH"
    $clang = Get-Command clang -ErrorAction SilentlyContinue
}
if ($clang) { Write-Host "[OK] $(clang --version | Select-Object -First 1)" -ForegroundColor Green }
else { Write-Host "[!] LLVM/Clang not found (winget install LLVM.LLVM)" -ForegroundColor Yellow }

Write-Host ""
Write-Host "Next steps: docs/building.md. In short:" -ForegroundColor White
Write-Host "  python -m pip install -r tools/requirements.txt" -ForegroundColor White
Write-Host "  powershell -ExecutionPolicy Bypass -File tools/setup_all.ps1 -Iso <path to your Fable II disc image>" -ForegroundColor White
