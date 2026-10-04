# search.ps1 -- 三層模糊搜尋 + tag 查閱 (LeetCode C 題庫, 非網頁)
# 用法 Usage:
#   .\search.ps1 two sum          模糊搜尋(英文/數字/中文/tags 均可, 多詞 AND)
#   .\search.ps1 括號             中文題目名亦可模糊
#   .\search.ps1 -tag sliding-window   依 tag 查閱 (tag 可打關鍵字, 如 heap)
#   .\search.ps1 -tags            列出所有 tags + 題數
#   .\search.ps1 -diff hard       只看 Hard
#   .\search.ps1 -all             全部列表
#   .\search.ps1 146 -edit        搜尋後用編輯器打開第一筆
param(
    [Parameter(Position = 0, ValueFromRemainingArguments = $true)]
    [string[]]$Query,
    [string]$Tag,
    [ValidateSet("", "easy", "medium", "hard")]
    [string]$Diff = "",
    [switch]$Tags,
    [switch]$All,
    [switch]$Edit
)

$ErrorActionPreference = "Stop"
try { [Console]::OutputEncoding = [System.Text.Encoding]::UTF8 } catch { }
$root = $PSScriptRoot

function Normalize([string]$s) {
    if (-not $s) { return "" }
    return ($s.ToLower() -replace '[^0-9a-z\u4e00-\u9fff]', '')
}

function FuzzyScore([string]$hay, [string]$needle) {
    if ($needle -eq "" -or $hay -eq "") { return 0 }
    if ($hay.Contains($needle)) { return 100 }
    $hi = 0; $run = 0; $best = 0
    foreach ($ch in $needle.ToCharArray()) {
        $idx = $hay.IndexOf($ch, $hi)
        if ($idx -lt 0) { return 0 }
        if ($idx -eq $hi) { $run++; if ($run -gt $best) { $best = $run } } else { $run = 1 }
        $hi = $idx + 1
    }
    return 50 + $best * 3
}

# ---- layer 1: 精選解答 (curated) ----
$curated = @()
foreach ($pdir in @("easy", "medium", "hard")) {
    $dpath = Join-Path $root $pdir
    if (-not (Test-Path $dpath)) { continue }
    foreach ($f in (Get-ChildItem $dpath -Filter *.c)) {
        $num = ""; $ttl = ""; $cn = ""; $dval = ""; $tagstr = ""
        foreach ($ln in (Get-Content $f.FullName -TotalCount 12 -Encoding UTF8)) {
            if ($ln -match '^\s*\*/') { break }
            if ($ln -match '^\s*\*\s*LeetCode\s+(\d+)\.\s*(.+?)\s*$') { $num = $Matches[1]; $ttl = $Matches[2] }
            elseif ($ln -match '^\s*\*\s*Title-CN:\s*(.+?)\s*$')      { $cn = $Matches[1] }
            elseif ($ln -match '^\s*\*\s*Difficulty:\s*(\w+)')        { $dval = $Matches[1] }
            elseif ($ln -match '^\s*\*\s*Tags:\s*(.+?)\s*$')          { $tagstr = $Matches[1] }
        }
        $curated += [pscustomobject]@{
            Num = $num.PadLeft(3, "0"); Title = $ttl; CN = $cn; Diff = $dval
            Tags = @($tagstr -split ',\s*' | Where-Object { $_ })
            File = "$pdir/$($f.Name)"; Slug = ($f.BaseName -replace '^\d+_', ''); Kind = "cur"
        }
    }
}

# ---- layer 2: 批量解答 (bulk) ----
$bulk = @()
$bulkPath = Join-Path $root "BULK_INDEX.tsv"
if (Test-Path $bulkPath) {
    foreach ($ln in (Get-Content $bulkPath -Encoding UTF8)) {
        $fl = $ln -split '\|'
        if ($fl.Count -lt 7) { continue }
        $bulk += [pscustomobject]@{
            Num = $fl[0]; Title = $fl[1]; CN = $fl[5]; Diff = $fl[2]
            Tags = @($fl[3] -split ',\s*' | Where-Object { $_ })
            File = $fl[6]; Slug = ($fl[6] -replace '^bulk/[a-z]+/\d+_', '' -replace '\.c$', ''); Kind = "bulk"
        }
    }
}

# ---- layer 3: 完整題庫 (db) ----
$db = @()
$dbPath = Join-Path $root "DB_INDEX.tsv"
if (Test-Path $dbPath) {
    foreach ($ln in (Get-Content $dbPath -Encoding UTF8)) {
        $fl = $ln -split '\|'
        if ($fl.Count -lt 5) { continue }
        $db += [pscustomobject]@{
            Num = $fl[0]; Title = $fl[1]; CN = ""; Diff = $fl[2]
            Tags = @($fl[4] -split ',\s*' | Where-Object { $_ })
            File = ("problems/{0}-{1}.json" -f $fl[0], $fl[3]); Slug = $fl[3]; Kind = "db"
        }
    }
}

function ScoreOne($p, [string[]]$qq) {
    $total = 1000
    foreach ($q in $qq) {
        $qn = Normalize $q
        $s = 0
        if ($q -match '^\d+$') {
            $bare = ($q -replace '^0+', "")
            if ($bare -eq "") { $bare = "0" }
            if (($p.Num -replace '^0+', "") -eq $bare) { $s = 100 }
        }
        if ($s -eq 0) {
            $s = FuzzyScore (Normalize $p.Title) $qn
            $s = [Math]::Max($s, [double](FuzzyScore (Normalize $p.Slug) $qn) * 0.95)
            $s = [Math]::Max($s, [double](FuzzyScore (Normalize ($p.Tags -join " ")) $qn) * 0.9)
            if ($p.CN) { $s = [Math]::Max($s, [double](FuzzyScore (Normalize $p.CN) $qn)) }
            $s = [Math]::Max($s, [double](FuzzyScore (Normalize $p.Diff) $qn) * 0.8)
        }
        if ($s -le 0) { return -1 }
        if ($s -lt $total) { $total = $s }
    }
    return $total
}

function ApplyFilters($set) {
    $r = $set
    if ($Tag)  { $tn = Normalize $Tag; $r = @($r | Where-Object { (@($_.Tags | Where-Object { (FuzzyScore (Normalize $_) $tn) -ge 50 })).Count -gt 0 }) }
    if ($Diff) { $r = @($r | Where-Object { $_.Diff.ToLower() -eq $Diff.ToLower() }) }
    return $r
}

if ($Tags) {
    foreach ($layer in @(@("cur", $curated), @("bulk", $bulk), @("db", $db))) {
        if ($layer[1].Count -eq 0) { continue }
        $tagmap = @{}
        foreach ($p in $layer[1]) { foreach ($tg in $p.Tags) { if (-not $tagmap.ContainsKey($tg)) { $tagmap[$tg] = 0 }; $tagmap[$tg]++ } }
        $name = switch ($layer[0]) { "cur" { "精選解答" } "bulk" { "批量解答(社群,已驗證)" } default { "完整題庫(題面)" } }
        $shown = @($tagmap.Keys | Sort-Object { -$tagmap[$_] })
        if ($layer[0] -eq "db") { $shown = $shown | Select-Object -First 30 }
        Write-Host ("== {0} 標籤 ({1} 種 / {2} 題) ==" -f $name, $tagmap.Count, $layer[1].Count) -ForegroundColor Cyan
        foreach ($k in $shown) { Write-Host ("  {0,-30} x{1}" -f $k, $tagmap[$k]) }
        Write-Host ""
    }
    exit 0
}

if (-not $All -and -not $Query -and -not $Tag -and -not $Diff) {
    Write-Host "用法示例:" -ForegroundColor Cyan
    Write-Host "  .\search.ps1 two sum          模糊搜尋 (多詞 AND, 中英均可)"
    Write-Host "  .\search.ps1 括號             中文搜尋"
    Write-Host "  .\search.ps1 146              題號"
    Write-Host "  .\search.ps1 -tag dp          tag 查閱(三層)"
    Write-Host "  .\search.ps1 -tags            標籤一覽"
    Write-Host "  .\search.ps1 -diff hard       難度篩選"
    Write-Host ("`n精選 {0} / 批量解答 {1} / 完整題庫 {2}" -f $curated.Count, $bulk.Count, $db.Count)
    exit 0
}

if ($All) {
    Write-Host ("【精選解答】{0} 題 (雙語+測試)" -f $curated.Count) -ForegroundColor Green
    $curated | Sort-Object Num | ForEach-Object { Write-Host ("  [{0}] {1,-6} {2} 《{3}》 -> {4}" -f $_.Num, $_.Diff.ToUpper(), $_.Title, $_.CN, $_.File) }
    Write-Host ("`n【批量解答】{0} 題 (社群+驗證)" -f $bulk.Count) -ForegroundColor Yellow
    $bulk | Sort-Object Num | Select-Object -First 30 | ForEach-Object { Write-Host ("  [{0}] {1,-6} {2} 《{3}》 -> {4}" -f $_.Num, $_.Diff.ToUpper(), $_.Title, $_.CN, $_.File) }
    if ($bulk.Count -gt 30) { Write-Host ("  ... 共 {0}" -f $bulk.Count) }
    Write-Host ("`n【完整題庫】{0} 題 -> DB_INDEX.tsv / problems\" -f $db.Count) -ForegroundColor Cyan
    exit 0
}

$curHits = @(); $bulkHits = @(); $dbHits = @()
foreach ($layer in @(@(1, $curated, "cur"), @(2, $bulk, "bulk"), @(3, $db, "db"))) {
    $idx = $layer[0]; $set = $layer[1]; $key = $layer[2]
    $cand = ApplyFilters $set
    if ($Query -and $Query.Count -gt 0) {
        $scored = @()
        foreach ($p in $cand) { $sc = ScoreOne $p $Query; if ($sc -ge 0) { $scored += [pscustomobject]@{ P = $p; S = $sc } } }
        $res = @($scored | Sort-Object -Property @{Expression="S";Descending=$true}, @{Expression={$_.P.Num}})
    } else {
        $res = @($cand | ForEach-Object { [pscustomobject]@{ P = $_; S = 100 } })
    }
    switch ($key) {
        "cur"  { $curHits  = $res }
        "bulk" { $bulkHits = $res }
        "db"   { $dbHits   = $res }
    }
}

if ($curHits.Count + $bulkHits.Count + $dbHits.Count -eq 0) { Write-Host "無符合結果 no matches" -ForegroundColor Yellow; exit 0 }

if ($curHits.Count -gt 0) {
    Write-Host ("【精選解答 C 可執行・雙語】{0} 題:" -f $curHits.Count) -ForegroundColor Green
    foreach ($h in $curHits) {
        $p = $h.P
        $color = switch ($p.Diff.ToLower()) { "easy" { "Green" } "medium" { "Yellow" } "hard" { "Red" } default { "White" } }
        Write-Host ("  [{0}] {1,-6} {2}" -f $p.Num, $p.Diff.ToUpper(), $p.Title) -ForegroundColor $color -NoNewline
        Write-Host ("  《{0}》 -> {1}" -f $p.CN, $p.File) -ForegroundColor DarkGray
    }
}
if ($bulkHits.Count -gt 0) {
    Write-Host ("【批量解答 C 可執行・社群驗證】{0} 題:" -f $bulkHits.Count) -ForegroundColor Yellow
    $shown = $bulkHits | Select-Object -First 40
    foreach ($h in $shown) {
        $p = $h.P
        $color = switch ($p.Diff.ToLower()) { "easy" { "Green" } "medium" { "Yellow" } "hard" { "Red" } default { "White" } }
        Write-Host ("  [{0}] {1,-6} {2}" -f $p.Num, $p.Diff.ToUpper(), $p.Title) -ForegroundColor $color -NoNewline
        if ($p.CN) { Write-Host ("  《{0}》" -f $p.CN) -ForegroundColor DarkGray -NoNewline }
        Write-Host ("  -> {1}" -f $p.S, $p.File) -ForegroundColor DarkGray
    }
    if ($bulkHits.Count -gt 40) { Write-Host ("  ... 其餘 {0} 題請加關鍵字或 -tag/-diff" -f ($bulkHits.Count - 40)) -ForegroundColor DarkGray }
}
if ($dbHits.Count -gt 0) {
    Write-Host ("【完整題庫(僅題面 JSON)】{0} 題:" -f $dbHits.Count) -ForegroundColor Cyan
    $shown = $dbHits | Select-Object -First 30
    foreach ($h in $shown) {
        $p = $h.P
        Write-Host ("  [{0}] {1,-6} {2}" -f $p.Num, $p.Diff.ToUpper(), $p.Title) -ForegroundColor White -NoNewline
        Write-Host ("   -> {0}" -f $p.File) -ForegroundColor DarkCyan
    }
    if ($dbHits.Count -gt 30) { Write-Host ("  ... 其餘 {0} 題請縮小關鍵字或加 -tag/-diff 過濾" -f ($dbHits.Count - 30)) -ForegroundColor DarkGray }
}
if ($Edit -and $curHits.Count -gt 0) {
    Start-Process notepad -ArgumentList (Join-Path $root $curHits[0].P.File)
    Write-Host ("opened: " + $curHits[0].P.File) -ForegroundColor Green
}
