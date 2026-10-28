# UVa Volume 005

本卷收錄 11 個 C 題目檔，依 UVa 題號排序。

<a id="uva-530_binomial-showdown"></a>

### UVa 530 — Binomial Showdown／二項式係數精準計算

- 原始碼：[530_binomial-showdown.c](530_binomial-showdown.c)
- 演算法：組合數乘除化簡（math, combinatorics）

**English description:** Repeatedly read `n` and `k` and compute the exact binomial coefficient `C(n, k)`. Use the symmetry `C(n, k) = C(n, n-k)` and interleave multiplication with exact division so the factorials never need to be formed. Input ends with `0 0`.

**中文詳細描述：** 每筆輸入 `n`、`k`，要求精確輸出從 `n` 個元素取 `k` 個的組合數。先令 `k = min(k, n-k)`，再依序以 `答案 × (n-i+1) ÷ i` 計算，避免直接建立巨大階乘及不必要的中間值；讀到 `0 0` 時結束。

<a id="uva-537_artificial-intelligence"></a>

### UVa 537 — Artificial Intelligence?／物理功率、電壓、電流計算

- 原始碼：[537_artificial-intelligence.c](537_artificial-intelligence.c)
- 演算法：字串解析、公式代入（parsing, physics）

**English description:** Each problem statement embeds two known quantities among power `P`, voltage `U`, and current `I`, possibly using metric prefixes `m`, `k`, or `M`. Parse the values, derive the missing quantity from `P = U × I`, and print it with two decimal places and its proper unit.

**中文詳細描述：** 每組輸入是一段文字，其中會出現 `P`（瓦特）、`U`（伏特）、`I`（安培）三項中的兩項，數值可能帶 `m`、`k`、`M` 倍率前綴。解析並換算成基本單位後，用 `P = U × I` 求第三項；按案例格式輸出未知量、兩位小數與正確單位。

<a id="uva-541_error-correction"></a>

### UVa 541 — Error Correction／二維奇偶校驗矩陣修正

- 原始碼：[541_error-correction.c](541_error-correction.c)
- 演算法：行列奇偶統計（matrix, parity check）

**English description:** Given an `N × N` binary matrix, verify that every row and column has an even sum. Print `OK` if all parities are even, identify the one-based cell whose flip would fix the matrix when exactly one row and one column are odd, or print `Corrupt` otherwise. Input ends with `N = 0`.

**中文詳細描述：** 每組輸入 `N × N` 的 0/1 矩陣，檢查每一列與每一行的元素和是否皆為偶數。若全部通過就輸出 `OK`；若恰有一個奇數列與一個奇數行，翻轉兩者交點即可修復，輸出該一基座標；其他情況輸出 `Corrupt`。`N = 0` 結束。

<a id="uva-543_goldbachs-conjecture"></a>

### UVa 543 — Goldbach's Conjecture／哥德巴赫猜想

- 原始碼：[543_goldbachs-conjecture.c](543_goldbachs-conjecture.c)
- 演算法：埃拉托斯特尼篩法（number theory, prime sieve）

**English description:** For each even integer `n`, find two odd primes `a` and `b` with `n = a + b`. The required search starts with the smallest possible `a`, which produces the largest difference `b - a`; print the decomposition, or the failure sentence if none is found. Input ends with zero.

**中文詳細描述：** 每筆輸入一個偶數 `n`，尋找兩個奇質數 `a`、`b` 使 `n = a + b`。先用埃氏篩建立質數表，再由最小奇質數開始測試 `n-a`，因此找到的第一組同時使 `b-a` 最大；輸出等式，若找不到則輸出題目指定的失敗訊息，輸入 0 結束。

<a id="uva-568_just-the-facts"></a>

### UVa 568 — Just the Facts／階乘末尾最後一個非零數字

- 原始碼：[568_just-the-facts.c](568_just-the-facts.c)
- 演算法：階乘尾零消除、模運算（number theory, factorial）

**English description:** For each `N`, determine the rightmost nonzero decimal digit of `N!`. During repeated multiplication, remove trailing zeroes and retain only enough low digits to keep the value bounded, then print `N` and the digit in the required aligned format.

**中文詳細描述：** 每行輸入 `N`，要求 `N!` 的十進位表示中最右邊非 0 的數字。逐次乘入 1 到 `N`，每步把末尾 0 除去並保留適量低位以避免數值膨脹；最後取個位數，按題目規定對齊輸出 `N -> 答案`。

<a id="uva-572_oil-deposits"></a>

### UVa 572 — Oil Deposits／油田連通塊數量

- 原始碼：[572_oil-deposits.c](572_oil-deposits.c)
- 演算法：深度優先搜尋、洪水填充（graph, DFS, flood fill）

**English description:** A grid contains oil cells marked `@` and empty cells marked `*`. Cells belong to the same deposit when they connect horizontally, vertically, or diagonally. Count and print the number of eight-direction connected components for each grid; `0 0` ends the input.

**中文詳細描述：** 每組輸入網格列數、行數及由 `@`、`*` 組成的地圖。兩個油藏格 `@` 若在水平、垂直或斜向八個方向相鄰就屬於同一油田；每遇到尚未造訪的 `@` 就以 DFS 標記整個連通塊並將答案加一。逐組輸出油田數，`0 0` 結束。

<a id="uva-573_the-snail"></a>

### UVa 573 — The Snail／蝸牛爬井

- 原始碼：[573_the-snail.c](573_the-snail.c)
- 演算法：逐日狀態模擬（simulation）

**English description:** A snail climbs `U` feet during the first day, loses `F` percent of that original climbing distance from its daily ability after each day, and slides `D` feet each night in a well of height `H`. Simulate the day and night events in order and report the first day of success above the well or failure below zero. A zero height terminates input.

**中文詳細描述：** 每筆輸入井高 `H`、首日爬升 `U`、每夜滑落 `D` 與疲勞百分比 `F`。每天先以當日能力向上爬並立即檢查是否超過井口；若未成功，再向下滑並檢查是否低於 0，之後把次日爬升能力減少首日能力的 `F%`，最低為 0。輸出首次成功或失敗的天數，`H = 0` 結束。

<a id="uva-575_skew-binary"></a>

### UVa 575 — Skew Binary／斜二進位制轉十進位

- 原始碼：[575_skew-binary.c](575_skew-binary.c)
- 演算法：位權累加（math, base conversion）

**English description:** Convert each skew-binary numeral to decimal. Counting positions from one at the right, a digit at position `k` has weight `2^k - 1`; sum every digit times its weight and print the result. The input string `0` terminates processing.

**中文詳細描述：** 每行是一個斜二進位字串，從最右位開始編號 1，第 `k` 位權重為 `2^k - 1`。將每位數字值乘上對應權重後相加，即得十進位答案並逐行輸出；當整行只有 `0` 時結束。

<a id="uva-579_clock-hands"></a>

### UVa 579 — Clock Hands／時鐘時針與分針夾角

- 原始碼：[579_clock-hands.c](579_clock-hands.c)
- 演算法：角度計算（math, geometry）

**English description:** For each time `H:M`, compute the smaller angle between the analog clock's hour and minute hands. The hour hand advances continuously as minutes pass, so compare `30H + 0.5M` with `6M`, fold angles above 180 degrees, and print three decimal places. Input ends with `0:00`.

**中文詳細描述：** 每筆輸入格式為 `H:M` 的時間。分針角度為 `6M`，時針除了每小時 30 度外還會隨分鐘前進，因此角度為 `30H + 0.5M`；兩者差的絕對值若超過 180 度就以 360 減去它。輸出較小夾角至小數點後三位，`0:00` 結束。

<a id="uva-583_prime-factors"></a>

### UVa 583 — Prime Factors／整數質因數分解輸出

- 原始碼：[583_prime-factors.c](583_prime-factors.c)
- 演算法：試除法（number theory, prime factorization）

**English description:** Factor each nonzero signed integer into prime factors and print an equality joined by `x` symbols. For a negative input, emit `-1` as the first factor and factorize its absolute value; repeated prime factors must be printed repeatedly. Input ends with zero.

**中文詳細描述：** 每行輸入一個非 0 整數 `N`，輸出 `N = f1 x f2 x ...` 的完整質因數分解，相同質因數須依次重複列出。若 `N` 為負數，先輸出因數 `-1`，再分解其絕對值；以從小到大的試除法取出因數，最後剩餘大於 1 的值亦為質數。輸入 0 結束。

<a id="uva-591_box-of-bricks"></a>

### UVa 591 — Box of Bricks／積木柱高度平攤

- 原始碼：[591_box-of-bricks.c](591_box-of-bricks.c)
- 演算法：平均值、差額加總（math, array）

**English description:** Given the heights of several stacks containing a divisible total number of bricks, move individual bricks until every stack has the same height. Compute the minimum number of moved bricks and print it with the set number in the specified report format. A stack count of zero terminates input.

**中文詳細描述：** 每組輸入積木柱數量與各柱高度，總積木數保證能平均分配。先算目標平均高度；所有高於平均的柱子必須搬出的超額積木總數，正是達成等高所需的最少搬移次數。按案例編號輸出 `The minimum number of moves is ...`，柱數 0 時結束。
