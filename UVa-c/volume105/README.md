# UVa Volume 105

本卷收錄 24 份 C 解答，涵蓋 22 個 UVa 題號，以下依題號排序。

<a id="uva-10502_counting-rectangles"></a>

### UVa 10502 — Counting Rectangles／計數全1矩形個數

- 原始碼：[10502_counting-rectangles.c](10502_counting-rectangles.c)
- 難度：Easy
- 演算法：math, brute-force, 2d-prefix-sums

**English description:** Count the total number of subrectangles consisting entirely of '1's in an n x m binary grid.

**中文詳細描述：** 計算 n x m 二進位網格中，完全由 '1' 組成的子矩形總數。

**English approach:** Compute 2D prefix sums. Enumerate all pairs (r1, c1) and (r2, c2). Check if subrectangle sum equals its area (r2 - r1 + 1) * (c2 - c1 + 1).

**中文解題思路：** 二維前綴和預處理，四重迴圈枚舉子矩形左上角與右下角，檢查區間和是否等於矩形面積。 ==========================================================================


<a id="uva-10503_the-dominoes-solitaire"></a>

### UVa 10503 — The dominoes solitaire／骨牌接龍

- 原始碼：[10503_the-dominoes-solitaire.c](10503_the-dominoes-solitaire.c)
- 難度：Medium
- 演算法：backtracking, dfs

**English description:** Determine if n dominoes can be placed in sequence between given start and end pieces such that adjacent halves match.

**中文詳細描述：** 在給定的起始骨牌與結束骨牌之間擺入 n 塊骨牌，使得相鄰端點點數相同，求是否存在合法擺法。

**English approach:** Backtracking search of depth n: try every unused domino in both original and flipped orientations matching the previous right number.

**中文解題思路：** 深度為 n 的回溯搜尋：枚舉每個未使用的骨牌（可正放或翻轉），其左側點數需等於前一骨牌的右側點數。 ==========================================================================


<a id="uva-10507_waking-up-brain"></a>

### UVa 10507 — Waking up brain／大腦喚醒過程

- 原始碼：[10507_waking-up-brain.c](10507_waking-up-brain.c)
- 難度：Medium
- 演算法：graph, simulation, bfs

**English description:** Direct stimulation wakes up 3 areas. A dormant area wakes up if connected to at least 3 awake areas. Find years to awaken all areas.

**中文詳細描述：** 直接刺激喚醒 3 個腦區。未醒腦區若連接至少 3 個已醒腦區則一年後甦醒，求全部甦醒所需年數。

**English approach:** Simulate round by round: find all dormant areas connected to >= 3 awake areas, awaken them simultaneously. Stop when none wake up.

**中文解題思路：** 逐輪模擬：找出所有與 >= 3 個已醒腦區相連的休眠區，同步喚醒。若無法再喚醒則結束並檢查是否全部甦醒。 ==========================================================================


<a id="uva-10509_r-u-kidding-mr-feynman"></a>

### UVa 10509 — R U Kidding Mr. Feynman?／費曼先生，你在開玩笑嗎？ (立方根一階泰勒展開)

- 原始碼：[10509_r-u-kidding-mr-feynman.c](10509_r-u-kidding-mr-feynman.c)
- 難度：Easy
- 演算法：math, approximation

**English description:** Approximate cbrt(n) using Feynman's method: find integer a such that a^3 <= n, then cbrt(n) ~ a + (n - a^3) / (3 * a^2).

**中文詳細描述：** 利用費曼近似法估算立方根：找出使 a^3 <= n 的最大整數 a，則 cbrt(n) ~ a + (n - a^3) / (3 * a^2)。

**English approach:** Direct calculation of formula: a = floor(cbrt(n)), dx = (n - a*a*a) / (3.0 * a * a). Ans = a + dx.

**中文解題思路：** 代入費曼一階泰勒展開公式：a = floor(cbrt(n))，dx = (n - a^3) / (3 * a^2)，回傳 a + dx。 ==========================================================================


<a id="uva-10515_powers-et-al"></a>

### UVa 10515 — Powers Et Al.／大數冪次末位數 (週期性循環取模)

- 原始碼：[10515_powers-et-al.c](10515_powers-et-al.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Find the last decimal digit of m^n where m and n are huge integers.

**中文詳細描述：** 求超大整數冪次 m^n 的最後一位十進位數字 (m, n 最長達 101 位數)。

**English approach:** Last digit depends only on (m % 10). Last digits of powers have periods of at most 4. Compute n % 4.

**中文解題思路：** 末位數僅取決於底數個位數 (m % 10)。任何個位數的冪次末位週期最多為 4，以指數末兩位計算 n % 4 查表即可。 ==========================================================================


<a id="uva-10523_very-easy"></a>

### UVa 10523 — Very Easy !!!／大數級數求和 (Sum_{i=1}^N i * A^i)

- 原始碼：[10523_very-easy.c](10523_very-easy.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Compute exact sum: sum_{i=1}^N i * A^i for N <= 150 and A <= 15.

**中文詳細描述：** 精確計算級數和 sum_{i=1}^N i * A^i (N <= 150, A <= 15)，需使用大數高精度加法與乘法。

**English approach:** Maintain current power A^i using BigInt multiplication by A. Multiply by i and accumulate into total sum.

**中文解題思路：** 以高精度大數陣列逐項維護 A^i，將當前項乘上 i 並累加至總和大數陣列中。 ==========================================================================


<a id="uva-10530_guessing-game"></a>

### UVa 10530 — Guessing Game／猜數字作弊檢測 (區間收縮一致性)

- 原始碼：[10530_guessing-game.c](10530_guessing-game.c)
- 難度：UVa Star 1
- 演算法：simulation, intervals

**English description:** Determine if Stan is dishonest during guessing game given sequence of guesses and responses (too high, too low, right on).

**中文詳細描述：** 猜 1 到 10 的數字：依據 'too high'、'too low' 與最終 'right on' 回應，判定回答者是否誠實無矛盾。

**English approach:** Maintain valid range [low, high] initialized to [1, 10]. 'too high' sets high = min(high, g - 1); 'too low' sets low = max(low, g + 1). Check final guess in [low, high].

**中文解題思路：** 維護合法解區間 [low, high]。太高縮小上限，太低提高下限，最終猜中數字必須落在該區間內，否則判定說謊。 ==========================================================================


<a id="uva-10533_digit-primes"></a>

### UVa 10533 — Digit Primes／數位質數區間計數 (Digit Primes 篩法前綴和)

- 原始碼：[10533_digit-primes.c](10533_digit-primes.c)
- 難度：UVa Star 2
- 演算法：math, prime-sieve, prefix-sum

**English description:** Count digit primes in [t1, t2] (primes whose sum of digits is also prime) up to 1,000,000.

**中文詳細描述：** 求區間 [t1, t2] 內數位質數的數量 (即本身為質數且其十進位各位數之和亦為質數，上限 100 萬)。

**English approach:** Linear sieve up to 10^6. Flag numbers where both x and sum_digits(x) are prime. Precompute prefix sums for O(1) query.

**中文解題思路：** 質數篩預處理至 100 萬，標記本身與數位和皆為質數的數，預處理前綴和達成 O(1) 區間查詢。 ==========================================================================


<a id="uva-10534_wavio-sequence"></a>

### UVa 10534 — Wavio Sequence／Wavio 雙向遞增遞減極值序列

- 原始碼：[10534_wavio-sequence.c](10534_wavio-sequence.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lis, binary-search

**English description:** A Wavio sequence has length 2k+1, strictly increases for k+1 elements, then strictly decreases. Find length of longest Wavio subsequence.

**中文詳細描述：** 長度為 2k+1 的 Wavio 序列前 k+1 項嚴格遞增，後 k+1 項嚴格遞減。求給定數列中最長 Wavio 子序列之長度。

**English approach:** Compute Longest Increasing Subsequence (LIS) from left, and Longest Decreasing Subsequence (LDS) from right in O(N log N). Best length = 2 * min(lis[i], lds[i]) - 1.

**中文解題思路：** 以二分搜尋分別計算正向 LIS 與逆向 LDS，以 2 * min(lis[i], lds[i]) - 1 取各點為轉折中心之最大值。 ==========================================================================


<a id="uva-10539_almost-prime-numbers"></a>

### UVa 10539 — Almost Prime Numbers／近似質數計數 (質數冪次方 p^k)

- 原始碼：[10539_almost-prime-numbers.c](10539_almost-prime-numbers.c)
- 難度：UVa Star 2
- 演算法：math, number-theory, prime-sieve, binary-search

**English description:** Count numbers in range [low, high] that have exactly one prime factor (i.e. of the form p^k for k >= 2).

**中文詳細描述：** 求區間 [low, high] 內僅含有單一質因數的整數總數 (即形如 p^k, k >= 2 的近似質數，上限 10^12)。

**English approach:** Sieve primes up to sqrt(10^12) = 10^6. Generate all p^k <= 10^12, sort array and use binary search to count in range.

**中文解題思路：** 質數篩預處理至 10^6，枚舉質數 p 的各次方 p^2, p^3... 存入陣列排序，二分搜尋 upper_bound - lower_bound 快速計數。 ==========================================================================


<a id="uva-10550_combination-lock"></a>
### UVa 10550 — Combination Lock／密碼鎖

- 原始碼：[10550_combination-lock.c](10550_combination-lock.c)
- 演算法：環狀距離、模擬（Math, Simulation）

**English description:**

The input gives the initial dial position and three combination numbers on a 40-mark lock. Following the required clockwise and counterclockwise turns, calculate and output the total angle through which the dial rotates.

**中文詳細描述：**

每筆輸入包含 40 格密碼鎖的起始位置與三個密碼數字。依規則先順時針轉兩整圈到第一個數字，再逆時針轉一整圈到第二個數字，最後順時針到第三個數字；每格為 9 度，輸出總旋轉角度。

<a id="uva-10550_combination-lock-pr"></a>

### UVa 10550 — Combination Lock／轉盤密碼鎖旋轉度數

- 原始碼：[10550_combination-lock-pr.c](10550_combination-lock-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, simulation

**English description:** Compute total degrees of rotation to open lock with 40 ticks: 2 full clockwise turns, 1 counter-clockwise, then to 3rd combo.

**中文詳細描述：** 計算開啟 40 格轉盤密碼鎖旋轉的總角度：順時針轉 2 整圈、逆時針轉 1 整圈，最後轉至第 3 個密碼刻度。

**English approach:** Base turns = 720 + 360 = 1080 deg. Each tick is 360/40 = 9 deg. Clockwise: (cur - next + 40)%40; Counter-clockwise: (next - cur + 40)%40.

**中文解題思路：** 固定旋轉角度為 2圈 + 1圈 = 1080度。每刻度 9 度。順時針步數為 (a-b+40)%40，逆時針為 (c-b+40)%40，累加總角度。 ==========================================================================


<a id="uva-10551_basic-remains"></a>

### UVa 10551 — Basic Remains／進位制大數求模

- 原始碼：[10551_basic-remains.c](10551_basic-remains.c)
- 難度：Easy
- 演算法：math, horner-s-rule, base-conversion

**English description:** Given big integer p and integer m in base b, compute (p mod m) in base b.

**中文詳細描述：** 給定以 b 進位表示的大整數 p 與模數 m，求 (p mod m) 的結果並以 b 進位輸出。

**English approach:** Convert m to decimal. Evaluate (p mod m_dec) using Horner's rule digit by digit. Convert remainder back to base b.

**中文解題思路：** 將模數 m 轉為十進位，對大數 p 使用秦九韶演算法逐位求模，最後將餘數轉回 b 進位字串。 ==========================================================================


<a id="uva-10557_xyzzy"></a>

### UVa 10557 — XYZZY／魔法迷宮冒險 (帶正權環的最長路徑/SPFA)

- 原始碼：[10557_xyzzy.c](10557_xyzzy.c)
- 難度：Medium
- 演算法：graph, bellman-ford, spfa

**English description:** Start with 100 energy. Traverse rooms with energy changes to reach exit n without energy dropping to 0 or below.

**中文詳細描述：** 初始擁有 100 點能量，穿越各房間獲得或消耗能量，在能量始終大於 0 的前提下抵達終點 n。

**English approach:** Modified Bellman-Ford. If an energy cycle can reach exit n and energy > 0, player can reach n with infinite energy.

**中文解題思路：** 變形 Bellman-Ford：若存在可無限增加能量的正環且該環能抵達終點，則必定可達終點；否則求最大能量路徑判斷是否 > 0。 ==========================================================================


<a id="uva-10559_blocks"></a>

### UVa 10559 — Blocks／消除方塊 (區間 DP)

- 原始碼：[10559_blocks.c](10559_blocks.c)
- 難度：Hard
- 演算法：dynamic-programming, interval-dp

**English description:** Find the maximum points attainable by repeatedly removing contiguous blocks of the same color (earning k^2 points for length k).

**中文詳細描述：** 每次消除相鄰相同顏色的方塊可獲得長度平方的分數，求消除所有方塊能獲得的最大分數總和。

**English approach:** Interval DP state dp[i][j][k]: max score for subarray [i..j] with k additional blocks matching color[j] concatenated to the right.

**中文解題思路：** 經典區間動態規劃：dp[i][j][k] 表示子區間 [i..j] 且右側已有 k 個與 color[j] 同色方塊時的最大分數。 ==========================================================================


<a id="uva-10566_crossed-ladders"></a>

### UVa 10566 — Crossed Ladders／交叉梯子 (二分搜尋與相似三角形)

- 原始碼：[10566_crossed-ladders.c](10566_crossed-ladders.c)
- 難度：Medium
- 演算法：geometry, binary-search, math

**English description:** Two ladders of lengths x and y cross in an alley. Their intersection is at height c. Find the alley width w.

**中文詳細描述：** 兩架長度為 x 與 y 的梯子在窄巷中交叉架在兩側牆上，交叉點距地面高度為 c，求窄巷寬度 w。

**English approach:** Height of left wall h1 = sqrt(x^2 - w^2), right wall h2 = sqrt(y^2 - w^2). Harmonic mean: 1/h1 + 1/h2 = 1/c. Binary search w in [0, min(x, y)].

**中文解題思路：** 兩側牆高分別為 h1 = sqrt(x^2 - w^2) 與 h2 = sqrt(y^2 - w^2)，由相似三角形得 1/h1 + 1/h2 = 1/c。在 [0, min(x,y)] 內對巷寬 w 進行二分搜尋。 ==========================================================================


<a id="uva-10567_helping-fill-bates"></a>

### UVa 10567 — Helping Fill Bates／序列字元子序列匹配與區間界限

- 原始碼：[10567_helping-fill-bates.c](10567_helping-fill-bates.c)
- 難度：Easy
- 演算法：binary-search, string, greedy

**English description:** Determine if a query string is a subsequence of candidates string S, and output the first and last matched indices with greedy earliest match.

**中文詳細描述：** 判斷詢問字串是否為候選字串 S 的子序列，貪心選取最早出現的位置，並輸出起始與終止匹配下標。

**English approach:** Store indices of each character 0..51. Use binary search (upper_bound) to greedily find the earliest matching position greater than the previous index.

**中文解題思路：** 預先記錄各字母在母字串中出現的位置清單，用二分搜尋 (upper_bound) 貪心取得大於前一下標的最小位置。 ==========================================================================


<a id="uva-10573_geometry-paradox"></a>

### UVa 10573 — Geometry Paradox／幾何悖論 (雙互切圓環面積)

- 原始碼：[10573_geometry-paradox.c](10573_geometry-paradox.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Two mutually tangent circles are tangent to an enclosing circle. Calculate the area between the large circle and the two small circles given either radii r1, r2 or chord length t.

**中文詳細描述：** 兩相切小圓內切於大圓，求大圓與兩小圓之間的區域面積（已知兩小圓半徑 r1, r2 或切線弦長 t）。

**English approach:** Area = pi * (r1+r2)^2 - pi*r1^2 - pi*r2^2 = 2 * pi * r1 * r2. If given t, 2*r1*r2 = t^2 / 8, so Area = pi * t^2 / 8.

**中文解題思路：** 兩圓半徑為 r1, r2 時面積為 2 * pi * r1 * r2；若僅給切線長 t 則面積為 pi * t^2 / 8。 ==========================================================================


<a id="uva-10576_y2k-accounting-bug"></a>

### UVa 10576 — Y2K Accounting Bug／Y2K 財務漏洞 (滑動窗口貪心回溯)

- 原始碼：[10576_y2k-accounting-bug.c](10576_y2k-accounting-bug.c)
- 難度：Easy
- 演算法：greedy, backtracking

**English description:** Company reports either profit s or deficit d each month. Every 5 consecutive months showed a deficit. Find maximum annual surplus, or DEFICIT.

**中文詳細描述：** 公司每月固定盈利 s 或虧損 d，且任意連續 5 個月的財務報表總和均為赤字（< 0），求全年可能的最大盈餘總額。

**English approach:** Try placing deficits d as late as possible in each 5-month block. Five possible monthly patterns: ssssd, sssdd, ssddd, sdddd, ddddd.

**中文解題思路：** 貪心法：為使總盈餘最大，在每個 5 個月窗口中盡量讓盈利 s 靠前、赤字 d 靠後。判定最多能填入多少個 s 使得 5 月和仍為負。 ==========================================================================


<a id="uva-10579_fibonacci-numbers"></a>

### UVa 10579 — Fibonacci Numbers／大數費氏數列查詢 (F(n))

- 原始碼：[10579_fibonacci-numbers.c](10579_fibonacci-numbers.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Compute the n-th Fibonacci number for n <= 5000.

**中文詳細描述：** 高精度大數計算第 n 個費氏數 (n <= 5000)。

**English approach:** Standard BigInt Fibonacci recurrence F(n) = F(n-1) + F(n-2).

**中文解題思路：** 以高精度大數陣列預先遞推費氏數列至 5000 項，支援 O(1) 查詢輸出。 ==========================================================================


<a id="uva-10583_ubiquitous-religions"></a>

### UVa 10583 — Ubiquitous Religions／普遍的宗教信仰 (並查集連通分支計數)

- 原始碼：[10583_ubiquitous-religions.c](10583_ubiquitous-religions.c)
- 難度：UVa Star 1
- 演算法：data-structures, dsu

**English description:** Given pairs of students sharing the same religion, find maximum number of distinct religions across n students.

**中文詳細描述：** 給定信仰相同宗教的學生配對，求 n 個學生中最多可能信奉多少種相異宗教 (並查集計算連通分支數)。

**English approach:** Disjoint Set Union (DSU). Start with n religions. Each successful union of two different sets decrements total by 1.

**中文解題思路：** 初始化宗教數為 n。以並查集處理信仰相同關係，每次合併不同集合時宗教總數減 1，最終剩餘集合數即為答案。 ==========================================================================


<a id="uva-10589_area"></a>

### UVa 10589 — Area／四圓交集面積 (蒙地卡羅與解析判定)

- 原始碼：[10589_area.c](10589_area.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Determine if randomly generated points in a square [0, a] x [0, a] fall within the intersection of four circular discs centered at the corners.

**中文詳細描述：** 判斷單位正方形 [0, a] x [0, a] 內的隨機點是否位於以四個角為圓心、邊長 a 為半徑的四個圓盤的交集內部。

**English approach:** Check if (x - cx)^2 + (y - cy)^2 <= a^2 for all four corners (0,0), (a,0), (0,a), (a,a).

**中文解題思路：** 驗證點 (x, y) 到四個角落頂點的歐氏距離是否均小於等於 a，即 (x-cx)^2 + (y-cy)^2 <= a^2。 ==========================================================================


<a id="uva-10591_happy-number"></a>
### UVa 10591 — Happy Number／快樂數

- 原始碼：[10591_happy-number.c](10591_happy-number.c)
- 演算法：數位運算、循環偵測（Simulation, Cycle Detection）

**English description:**

For each input integer, repeatedly replace it with the sum of the squares of its decimal digits. If the process reaches 1 the number is happy; if it enters a cycle it is unhappy. Output the classification for each case.

**中文詳細描述：**

每組輸入給一個整數，反覆將它替換成各十進位數字平方的總和。若過程最後到達 1，便是快樂數；若進入不含 1 的循環則不是，程式以到達 1 或 4 判定終止，並輸出每組的分類結果。

<a id="uva-10591_happy-number-pr"></a>

### UVa 10591 — Happy Number／快樂數判定 (數位平方和循環檢測)

- 原始碼：[10591_happy-number-pr.c](10591_happy-number-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, simulation

**English description:** Determine if a number is Happy (repeatedly summing squares of its digits terminates at 1).

**中文詳細描述：** 判定整數是否為快樂數：將各位數的平方相加形成新數，若最終收斂至 1 則為快樂數，陷入死循環則為不快樂數。

**English approach:** Simulate sum of squared digits. Cycle detection via visited array or Floyd tortoise and hare.

**中文解題思路：** 反覆計算各數位平方和，以陣列標記造訪過的中間數值以檢測是否陷入循環，若抵達 1 則回傳為快樂數。 ==========================================================================
