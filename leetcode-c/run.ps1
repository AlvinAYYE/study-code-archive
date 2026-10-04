# run.ps1 -- 本地編譯並執行一題 (自動偵測 gcc / Visual Studio MSVC)
# 用法: .\run.ps1 001   |  .\run.ps1 two-sum  |  .\run.ps1 146
param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Name
)
$ErrorActionPreference = "Stop"
try { [Console]::OutputEncoding = [System.Text.Encoding]::UTF8 } catch { }
$root = $PSScriptRoot

# ---- pick file ----
$files = Get-ChildItem "$root\easy\*.c", "$root\medium\*.c", "$root\hard\*.c", "$root\bulk\easy\*.c", "$root\bulk\medium\*.c", "$root\bulk\hard\*.c" -ErrorAction SilentlyContinue
if ($Name -match '^\d+$') {
    $pat = "^0*" + [regex]::Escape($Name) + "_"
    $hits = @($files | Where-Object { $_.BaseName -match $pat })
} else {
    $hits = @($files | Where-Object { $_.BaseName -like "*$Name*" })
}
if ($hits.Count -eq 0) { Write-Host "找不到題目: $Name (先用 search.ps1 查題號)" -ForegroundColor Red; exit 1 }
if ($hits.Count -gt 1) {
    # 優先級: 精選(easy/medium/hard) > bulk
    $pref = @($hits | Where-Object { $_.DirectoryName -notmatch '\\bulk$' -and $_.Directory.Parent.Name -ne "bulk" })
    if ($pref.Count -eq 1) { $hits = $pref }
    elseif ($pref.Count -gt 1) { $hits = $pref }
}
if ($hits.Count -gt 1) {
    Write-Host "多筆符合, 請用更精確名稱或題號:" -ForegroundColor Yellow
    $hits | ForEach-Object { Write-Host ("  " + $_.FullName) }
    exit 1
}
$src = $hits[0].FullName
$base = $hits[0].BaseName
Write-Host "==> $base" -ForegroundColor Cyan

# ---- build dir ----
$bd = Join-Path $env:TEMP "lcbuild_$base"
New-Item -ItemType Directory -Force -Path $bd | Out-Null
$bat = Join-Path $bd "do.bat"

if (Get-Command gcc -ErrorAction SilentlyContinue) {
    @"
@echo off
gcc -std=c11 -O2 -Wall "$src" -o "$bd\$base.exe" || exit /b 2
"$bd\$base.exe"
exit /b %errorlevel%
"@ | Out-File -Encoding ascii $bat
} else {
    $vswhere = "C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"
    $vsPath = $null
    if (Test-Path $vswhere) { $vsPath = & $vswhere -latest -products * -property installationPath | Select-Object -First 1 }
    if (-not $vsPath -or -not (Test-Path "$vsPath\VC\Auxiliary\Build\vcvars64.bat")) {
        $vsPath = "C:\Program Files\Microsoft Visual Studio\2022\Community"
    }
    $vcvars = "$vsPath\VC\Auxiliary\Build\vcvars64.bat"
    if (-not (Test-Path $vcvars)) { Write-Host "找不到編譯器 (gcc 或 Visual Studio)。安裝 MinGW-w64 或 VS 2022 後重試。" -ForegroundColor Red; exit 1 }
    @"
@echo off
call "$vcvars" >nul 2>&1
cl /nologo /std:c17 /W3 /utf-8 /D_CRT_SECURE_NO_WARNINGS /wd4267 /wd4244 "$src" /Fe:"$bd\$base.exe" /Fo:"$bd\\" || exit /b 2
"$bd\$base.exe"
exit /b %errorlevel%
"@ | Out-File -Encoding ascii $bat
}
Write-Host "(編譯中 compile...)" -ForegroundColor DarkGray
cmd /c $bat
Write-Host ("---- 結束碼 exit code = {0} ----" -f $LASTEXITCODE) -ForegroundColor DarkGray
