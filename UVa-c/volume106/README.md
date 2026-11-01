# UVa Volume 106

本卷收錄 30 份 C 解答，涵蓋 29 個 UVa 題號，以下依題號排序。

<a id="uva-10600_acm-contest-and-blackout"></a>

### UVa 10600 — ACM Contest and Blackout／次小生成樹邊權和計算

- 原始碼：[10600_acm-contest-and-blackout.c](10600_acm-contest-and-blackout.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Find the weight of the Minimum Spanning Tree (MST) and the second-best Minimum Spanning Tree.

**中文詳細描述：** 計算給定無向連通網路之最小生成樹 (MST) 邊權和，以及次小生成樹 (Second MST) 邊權和。

**English approach:** Run Kruskal's algorithm to obtain MST edges. For each edge in MST, temporarily remove it, re-run Kruskal, and take minimum among all valid spanning trees.

**中文解題思路：** 先求出最佳 MST，依序強制禁用 MST 中的每一條邊並重跑 Kruskal，在所有依然連通的生成樹中取邊權和最小者即為次小生成樹。 ==========================================================================


<a id="uva-10603_fill"></a>

### UVa 10603 — Fill／倒水杯量取目標水量 (Dijkstra最短路)

- 原始碼：[10603_fill.c](10603_fill.c)
- 難度：Medium
- 演算法：graph, dijkstra, bfs

**English description:** Given three jugs with capacities a, b, c (initially (0, 0, c)), find the minimum total amount of water poured to measure d liters in any jug (or closest d' < d).

**中文詳細描述：** 三個水杯容量 a, b, c（初態 0, 0, c），求量取 d 升水（若無法量出 d 則量取最接近的 d' < d）所需轉移的最少倒水量。

**English approach:** Dijkstra on states (jug1, jug2) with dist = total poured water. 6 transitions pouring from jug i to jug j.

**中文解題思路：** 以 (水杯1, 水杯2) 為狀態空間的 Dijkstra 演算法，邊權為每次倒出的水量，尋找達到水量 d 或最近小於 d 的最小累計倒水量。 ==========================================================================


<a id="uva-10608_friends"></a>
### UVa 10608 — Friends／朋友

- 原始碼：[10608_friends.c](10608_friends.c)
- 演算法：並查集、連通分量（Disjoint Set Union）

**English description:**

The input describes people and pairs of friends. Friendship connects people transitively, so merge every pair into groups and output the size of the largest connected group.

**中文詳細描述：**

每組輸入先給出總人數與朋友關係數，再列出每一對互為朋友的人。朋友關係具有傳遞性，因此使用並查集合併所有關係、維護各集合大小，最後輸出最大朋友圈的人數。

<a id="uva-10611_the-playboy-chimp"></a>

### UVa 10611 — The Playboy Chimp／花花公子黑猩猩身高二分查找

- 原始碼：[10611_the-playboy-chimp.c](10611_the-playboy-chimp.c)
- 難度：UVa Star 1
- 演算法：binary-search

**English description:** Given heights of N female chimps sorted in non-decreasing order, find the tallest chimp strictly shorter than Q and shortest chimp strictly taller than Q.

**中文詳細描述：** 給定由小到大排列的 N 隻母猩猩身高，對於查詢身高 Q，找出嚴格小於 Q 的最高者與嚴格大於 Q 的最矮者。

**English approach:** Binary search: find lower_bound - 1 for strictly shorter chimp, and upper_bound for strictly taller chimp.

**中文解題思路：** 利用二分搜尋查找嚴格小於 Q 的最大元素與嚴格大於 Q 的最小元素，無解時回傳 -1。 ==========================================================================


<a id="uva-10616_divisible-group-sums"></a>

### UVa 10616 — Divisible Group Sums／被 D 整除之 M 個整數子集和動態規劃

- 原始碼：[10616_divisible-group-sums.c](10616_divisible-group-sums.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Given N integers, count subsets of size M whose sum is divisible by D.

**中文詳細描述：** 給定包含 N 個整數的集合，計算大小恰好為 M 且元素總和能被 D 整除的子集個數 (背包動態規劃)。

**English approach:** 3D Dynamic Programming: dp[i][count][rem] = ways to pick count numbers with sum mod D = rem. Handle negative mod.

**中文解題思路：** 三維背包 DP：dp[cnt][rem] 表示選取 cnt 個數且餘數為 rem 的組合數，由後向前更新轉移並處理負數取模。 ==========================================================================


<a id="uva-10617_again-palindrome"></a>

### UVa 10617 — Again Palindrome／又是回文 (非連續回文子序列計數)

- 原始碼：[10617_again-palindrome.c](10617_again-palindrome.c)
- 難度：Medium
- 演算法：dp, palindrome

**English description:** Count the number of non-empty palindromic subsequences in a given string of length up to 60.

**中文詳細描述：** 計算長度不超過 60 的字串中，所有非空回文子序列的總數。

**English approach:** Interval DP: if s[i] == s[j], dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1; else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1].

**中文解題思路：** 區間動態規劃：若 s[i] == s[j]，則 dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1；否則 dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]。 ==========================================================================


<a id="uva-10622_perfect-p-th-powers"></a>

### UVa 10622 — Perfect P-th Powers／完美 P 次冪

- 原始碼：[10622_perfect-p-th-powers.c](10622_perfect-p-th-powers.c)
- 難度：Medium
- 演算法：math, number-theory, gcd

**English description:** Find the largest integer p such that x = b^p for some integer b.

**中文詳細描述：** 尋找最大的整數 p 使得 x = b^p（其中 b 為整數）。

**English approach:** Factorize |x| into prime powers. p is the gcd of all prime exponents. If x < 0, repeatedly divide p by 2 until it is odd.

**中文解題思路：** 對 |x| 進行質因數分解，各質因數指數的 gcd 即為最大可能 p；若 x 為負數，需將 p 不斷除以 2 直到為奇數。 ==========================================================================


<a id="uva-10633_rare-easy-problem"></a>

### UVa 10633 — Rare Easy Problem／稀有簡單題 (N - N/10 = M 數學還原)

- 原始碼：[10633_rare-easy-problem.c](10633_rare-easy-problem.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given M = N - floor(N/10), reconstruct all possible original integers N.

**中文詳細描述：** 已知 M = N - floor(N/10)，求所有可能的原始正整數 N (依升序輸出)。

**English approach:** N = (10*M - d) / 9 where d is the last digit 0..9. Check if (10*M - d) % 9 == 0 and satisfies formula.

**中文解題思路：** 數學推導：N - N/10 = 9*(N/10) + (N%10) = M。因此 N 約為 10*M / 9，檢驗相鄰候選數值即可精確求出所有解。 ==========================================================================


<a id="uva-10635_prince-and-princess"></a>

### UVa 10635 — Prince and Princess／王子與公主 (轉化為LIS的LCS)

- 原始碼：[10635_prince-and-princess.c](10635_prince-and-princess.c)
- 難度：Medium
- 演算法：dp, lcs, lis, binary-search

**English description:** Find length of longest common subsequence of two permutations of length up to 62500 in O(N log N) time.

**中文詳細描述：** 在兩條無重複元素的長度達 62500 的數列間求 LCS 長度，需在 O(N log N) 內解決。

**English approach:** Map elements of the first sequence to their indices 1..p. Map second sequence accordingly; the LCS becomes the LIS of the transformed sequence.

**中文解題思路：** 將第一數列的元素映射為位置索引 1..p，再將第二數列替換為相應索引，問題等價轉化為 O(N log N) 的最長遞增子序列 (LIS)。 ==========================================================================


<a id="uva-10642_can-you-solve-it"></a>
### UVa 10642 — Can You Solve It?／你能解出來嗎？

- 原始碼：[10642_can-you-solve-it.c](10642_can-you-solve-it.c)
- 演算法：座標編號、等差級數（Math, Geometry）

**English description:**

Grid points are visited in a fixed diagonal order. For each pair of coordinates, map both points to their sequence indices and output the number of steps from the first point to the second.

**中文詳細描述：**

平面上的整數座標依斜對角線順序編號，輸入每組的起點 `(x1, y1)` 與終點 `(x2, y2)`。利用 `s=x+y` 的三角數公式求出兩點編號，再輸出從起點走到終點所需的步數差。

<a id="uva-10646_what-is-the-card"></a>

### UVa 10646 — What is the Card?／洗牌魔術第 Y 張撲克牌定位

- 原始碼：[10646_what-is-the-card.c](10646_what-is-the-card.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Simulate card magic trick: 52-card deck. Top 25 cards held in hand. 3 times execute X = value(top), remove (10 - X) cards, add X to Y. Find card at Y from bottom.

**中文詳細描述：** 模擬 52 張撲克牌魔術：牌頂 25 張置於手牌，對剩餘牌堆執行三次「取頂牌點數 X，丟棄 10-X 張牌，累加 Y += X」，求牌堆底起第 Y 張牌面。

**English approach:** Follow the mechanical card movements directly. Combine pile and top 25 cards, and return the card at 1-based index Y.

**中文解題思路：** 以陣列模擬牌堆抽牌與丟牌動作，按步驟維護 Y 的總和，將手中 25 張手牌放回牌頂後，輸出自底起算第 Y 張牌。 ==========================================================================


<a id="uva-10651_pebble-solitaire"></a>

### UVa 10651 — Pebble Solitaire／卵石單人紙牌棋

- 原始碼：[10651_pebble-solitaire.c](10651_pebble-solitaire.c)
- 難度：Medium
- 演算法：bitmask-dp, dfs

**English description:** A 12-hole board has pebbles. A pebble can jump over an adjacent pebble into an empty hole, removing the jumped pebble. Find min remaining pebbles.

**中文詳細描述：** 12 個格子的棋盤上有卵石。卵石可跳過相鄰卵石進入空格並移除被跳過者，求最少剩下幾顆卵石。

**English approach:** Bitmask DFS with memoization on 2^12 states. For each pattern 'oo-' or '-oo', make the move and recurse.

**中文解題思路：** 狀態壓縮 DFS：12 位二進位遮罩配合記憶化搜索，枚舉所有 'oo-' 或 '-oo' 跳躍操作，取殘留卵石數最小值。 ==========================================================================


<a id="uva-10653_bombs-no-they-are-mines"></a>

### UVa 10653 — Bombs! NO they are Mines!!／地雷網格最短路徑 BFS

- 原始碼：[10653_bombs-no-they-are-mines.c](10653_bombs-no-they-are-mines.c)
- 難度：UVa Star 2
- 演算法：graph, bfs

**English description:** Find the minimum steps to navigate a robot across an R x C grid from start to destination, avoiding bomb-filled cells.

**中文詳細描述：** 在 R x C 網格地圖中避開佈滿地雷的格子，計算機器人從起點行進至終點所需之最短移動步數。

**English approach:** Breadth-First Search on 2D grid with 4-directional transitions, tracking visited cells and distance.

**中文解題思路：** 標準二維網格 BFS：將障礙地雷標記為不可通行，以佇列走訪四方向相鄰空格，記錄到達終點之最短距離。 ==========================================================================


<a id="uva-10656_maximum-sum-ii"></a>

### UVa 10656 — Maximum Sum (II)／最大非負子序列貪婪過濾

- 原始碼：[10656_maximum-sum-ii.c](10656_maximum-sum-ii.c)
- 難度：UVa Star 1
- 演算法：greedy

**English description:** Given a sequence of non-negative integers, output the subsequence of all strictly positive integers (or 0 if all are zeroes).

**中文詳細描述：** 給定一個非負整數序列，篩選並依序輸出所有大於 0 的正整數以形成最大和且最短的子序列 (全為 0 則印出單一 0)。

**English approach:** Filter out zeroes. If no positive integers exist, output 0.

**中文解題思路：** 遍歷序列過濾所有 0，保留所有 > 0 的元素；若結果為空則輸出單個 0。 ==========================================================================


<a id="uva-10660_citizen_attention_offices"></a>

### UVa 10660 — Citizen attention offices／市民服務處選址最佳化

- 原始碼：[10660_citizen_attention_offices.c](10660_citizen_attention_offices.c)
- 難度：Medium
- 演算法：brute-force, geometry, manhattan-distance

**English description:** Choose 5 office locations from 25 grid cells to minimize the total weighted Manhattan distance to populated areas.

**中文詳細描述：** 在 5x5 的網格中選定 5 個辦事處位置，使所有居民前往最近辦事處的曼哈頓距離加權總和最小。

**English approach:** Combinations C(25, 5) = 53130. Brute force all tuples of 5 locations, compute weighted distance, pick minimum.

**中文解題思路：** 枚舉全部 C(25, 5) = 53130 種組合，計算各居民點到 5 個辦事處的最短曼哈頓距離加權和，取最小者。 ==========================================================================


<a id="uva-10664_luggage"></a>

### UVa 10664 — Luggage／行李雙車等重平分背包判定

- 原始碼：[10664_luggage.c](10664_luggage.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Determine if a set of suitcase weights can be divided into two cars with exactly equal total weight.

**中文詳細描述：** 給定一組行李箱重量，判定是否能將行李完全均分為總重恰好相等的兩份 (子集和問題)。

**English approach:** Subset sum DP: check if sum % 2 == 0 and if target = sum / 2 is achievable using 0/1 knapsack.

**中文解題思路：** 子集和動態規劃：若總重為奇數則必無法平分；若為偶數，則以 0/1 背包判斷能否剛好湊出 target = sum / 2。 ==========================================================================


<a id="uva-10667_largest-block"></a>

### UVa 10667 — Largest Block／最大無障礙子矩陣

- 原始碼：[10667_largest-block.c](10667_largest-block.c)
- 難度：Medium
- 演算法：dp, maximum-submatrix

**English description:** Find the maximum area of a subgrid of all 1s (unblocked cells) in an S x S chessboard containing blocked rectangular areas.

**中文詳細描述：** 在含若干障礙矩形區塊的 S x S 棋盤中，求全為 1（無障礙）的最大子矩陣面積。

**English approach:** Compress rows into 1D histograms of consecutive 1s and compute largest rectangle in histogram, or 2D prefix sums.

**中文解題思路：** 將二維矩陣每行轉為連續 1 的直方圖高度，利用單調棧或枚舉上下界求最大全 1 矩形面積。 ==========================================================================


<a id="uva-10670_work_reduction"></a>

### UVa 10670 — Work Reduction／工作量化簡之最小外包成本

- 原始碼：[10670_work_reduction.c](10670_work_reduction.c)
- 難度：Medium
- 演算法：greedy, math

**English description:** Find the minimum cost to reduce work units from N to M given agency cost rates for unit reduction and halving.

**中文詳細描述：** 將工作量由 N 縮減為 M，各外包公司提供兩種收費：每減少 1 單位費用 A，或減半費用 B，求各家公司的最小成本。

**English approach:** Greedy choice: repeatedly compare cost of halving (B) with cost of doing the same reduction via unit steps (rem * A).

**中文解題思路：** 貪婪選擇：工作量大於 M 時，每次考慮減半能否節省成本，若減半成本 B 小於單步遞減成本 (N - N/2)*A 則減半，否則全用單步。 ==========================================================================


<a id="uva-10673_play-with-floor-and-ceil"></a>

### UVa 10673 — Play with Floor and Ceil／天花板與地板整數線性組合

- 原始碼：[10673_play-with-floor-and-ceil.c](10673_play-with-floor-and-ceil.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given x and k, find integers p and q such that p * floor(x / k) + q * ceil(x / k) = x.

**中文詳細描述：** 給定正整數 x 與 k，求一組整數解 (p, q) 滿足 p * floor(x / k) + q * ceil(x / k) = x。

**English approach:** Let a = floor(x/k), b = ceil(x/k). If a == b, p = 0, q = k. Otherwise rem = x % k, take p = k - rem, q = rem.

**中文解題思路：** 令 a = floor(x/k), b = ceil(x/k)。若 a == b 則 p = 0, q = k；否則令 rem = x % k，解為 p = k - rem, q = rem。 ==========================================================================


<a id="uva-10678_the-grazing-cow"></a>

### UVa 10678 — The Grazing Cow／吃草的牛橢圓幾何面積計算

- 原始碼：[10678_the-grazing-cow.c](10678_the-grazing-cow.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** A cow is tethered to a rope of length L tied between two posts distance D apart. Calculate the total grazing area (an ellipse).

**中文詳細描述：** 母牛被繩子拴在相距 D 的兩根木樁之間，繩長為 L，求母牛能吃草的最大活動範圍面積 (橢圓形面積)。

**English approach:** Foci distance 2c = D, major axis 2a = L, minor axis b = sqrt(a^2 - c^2). Ellipse area = pi * a * b.

**中文解題思路：** 兩木樁為橢圓焦點 2c = D，長軸 2a = L，短軸半長 b = sqrt(a^2 - c^2)，橢圓面積公式為 pi * a * b。 ==========================================================================


<a id="uva-10679_i-love-strings"></a>

### UVa 10679 — I Love Strings!!／字串多模式匹配 (KMP / 子字串查詢)

- 原始碼：[10679_i-love-strings.c](10679_i-love-strings.c)
- 難度：UVa Star 2
- 演算法：string, kmp, aho-corasick

**English description:** Given a large text and multiple queries, determine if each query string appears as a substring.

**中文詳細描述：** 給定主字串 S 與多筆查詢字串 Q，判定各查詢字串是否在主字串中作為子字串出現。

**English approach:** KMP search for each query string in text S or Aho-Corasick multi-pattern search.

**中文解題思路：** 以 KMP 演算法在主字串中高效搜尋目標字串，匹配成功回傳 'y'，否則回傳 'n'。 ==========================================================================


<a id="uva-10680_lcm"></a>

### UVa 10680 — LCM／前 N 個整數最小公倍數最後非零數字

- 原始碼：[10680_lcm.c](10680_lcm.c)
- 難度：Medium
- 演算法：math, number-theory, lcm

**English description:** Find the last non-zero digit of LCM(1, 2, 3, ..., N) for N up to 1,000,000.

**中文詳細描述：** 求 1 到 N 的最小公倍數 LCM(1, 2, ..., N) 的最後一個非零數字。

**English approach:** LCM is the product of highest prime powers p^k <= N. Balance factors of 2 and 5 (factor 5 appears at power floor(log5(N)), cancel equal power of 2). Multiply remaining factors mod 10.

**中文解題思路：** LCM 為所有質數最高冪次 p^k <= N 的乘積。消去所有的質因數 5 以及相同數量的 2，將剩餘各質數最高冪次在模 10 下連乘。 ==========================================================================


<a id="uva-10683_the-decadary-watch"></a>

### UVa 10683 — The decadary watch／十進位制時鐘轉換

- 原始碼：[10683_the-decadary-watch.c](10683_the-decadary-watch.c)
- 難度：Easy
- 演算法：math, time-conversion

**English description:** Convert standard time (24h 60m 60s 100cs) into French revolutionary decimal time (10h 100m 100s 100cc).

**中文詳細描述：** 將傳統時間（24小時制，1秒=100百分秒）轉換為法國大革命時期的十進位時間（1天=10小時，1小時=100分，1分=100秒，1秒=100百分秒）。

**English approach:** Total standard centiseconds = ((h*60 + m)*60 + s)*100 + cs. Decimal centiseconds = total * 10000000 / 8640000.

**中文解題思路：** 先求總毫秒/百分秒數，乘上 10000000 / 8640000 轉換為十進位制時間，格式化輸出 7 位數字。 ==========================================================================


<a id="uva-10684_the-jackpot"></a>

### UVa 10684 — The jackpot／頭彩大獎 (最大連續子序列和 Kadane)

- 原始碼：[10684_the-jackpot.c](10684_the-jackpot.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, kadane

**English description:** Find the maximum winning streak (maximum contiguous subarray sum) in a sequence of bets.

**中文詳細描述：** 在賭注下注收益序列中，尋找連續投注收益總和的最大值 (若最大和為 0 或負數則判定無獲利)。

**English approach:** Kadane's algorithm: cur_sum = max(0, cur_sum + val). Track max_sum.

**中文解題思路：** 標準 Kadane 動態規劃：累計當前和，小於 0 則重設為 0，維護全局最大連續子序列和。 ==========================================================================


<a id="uva-10685_nature"></a>

### UVa 10685 — Nature／食物鏈生物群落最大連通分支

- 原始碼：[10685_nature.c](10685_nature.c)
- 難度：UVa Star 2
- 演算法：graph, dsu

**English description:** Given predator-prey relationships between animals, find the size of the largest connected ecosystem network.

**中文詳細描述：** 給定動物之間的捕食連通關係，求出整個生態系中規模最大之連通生物群落所包含的物種數量。

**English approach:** Disjoint-Set Union (DSU) with subtree size tracking. Return max(size[root]).

**中文解題思路：** 利用帶權並查集 (DSU) 維護連通分量大小，將相連物種合併，回傳集合大小的最大值。 ==========================================================================


<a id="uva-10689_yet-another-number-sequence"></a>

### UVa 10689 — Yet another Number Sequence／斐波那契數列 Pisano 週期與矩陣快速冪

- 原始碼：[10689_yet-another-number-sequence.c](10689_yet-another-number-sequence.c)
- 難度：Medium
- 演算法：math, matrix-exponentiation, pisano-period

**English description:** Find the last m digits of the n-th generalized Fibonacci number f(n) = f(n-1) + f(n-2) with f(0)=a, f(1)=b.

**中文詳細描述：** 求廣義費氏數列 f(n) = f(n-1) + f(n-2)（初值 a, b）的後 m 位數字（m = 1..4）。

**English approach:** Pisano period for modulo 10^m: period for 10 is 60, 100 is 300, 1000 is 1500, 10000 is 15000. Take n mod period, then iterate.

**中文解題思路：** 模 10^m 的皮薩諾週期 (Pisano Period)：模 10 週期 60、模 100 週期 300、模 1000 週期 1500、模 10000 週期 15000。將 n 取模週期後線性遞推即可。 ==========================================================================


<a id="uva-10693_traffic_volume"></a>

### UVa 10693 — Traffic Volume／交通車流量最佳化

- 原始碼：[10693_traffic_volume.c](10693_traffic_volume.c)
- 難度：Easy
- 演算法：physics, math, calculus

**English description:** Find the optimal vehicle velocity and maximum traffic volume given car length L and deceleration rate f.

**中文詳細描述：** 給定車身常數 L 與煞車減速度 f，求能使交通車流量（每小時通過車輛數）最大化的最佳車速與最大流量。

**English approach:** Braking distance s = v^2 / (2*f). Volume V = v / (L + s) * 3600. Max volume occurs when v = sqrt(2 * f * L).

**中文解題思路：** 煞車安全距離為 s = v^2 / (2f)，車流量為 v / (L + s) * 3600。極值條件微分後得最佳車速 v = sqrt(2 * f * L)。 ==========================================================================


<a id="uva-10696_f91"></a>
### UVa 10696 — f91／f91 函數

- 原始碼：[10696_f91.c](10696_f91.c)
- 演算法：分段函數、數學（Recursion, Math）

**English description:**

For each positive input `n` until the terminating zero, evaluate McCarthy's recursively defined `f91` function and print the result in the specified sentence format. The recursion simplifies to 91 for `n ≤ 100`, and `n-10` otherwise.

**中文詳細描述：**

逐筆讀入正整數 `n`，直到輸入 0 結束；題目要求計算以巢狀遞迴定義的 McCarthy `f91` 函數，並按指定句型輸出結果。由函數性質可化簡為 `n ≤ 100` 時答案為 91，否則為 `n-10`。

<a id="uva-10696_f91-pr"></a>

### UVa 10696 — f91／麥卡錫 91 函數 (McCarthy 91 Function)

- 原始碼：[10696_f91-pr.c](10696_f91-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, recursion

**English description:** Compute recursive McCarthy 91 function: f91(n) = n - 10 if n > 100, else f91(f91(n + 11)).

**中文詳細描述：** 計算著名的麥卡錫 91 遞迴函數：若 n <= 100 恆等於 91；若 n >= 101 恆等於 n - 10。

**English approach:** Mathematical property: for all n <= 100, f91(n) = 91. For n >= 101, f91(n) = n - 10.

**中文解題思路：** 數論分析結論：當 n <= 100 時結果必為 91；當 n >= 101 時結果為 n - 10，直接 O(1) 輸出。 ==========================================================================


<a id="uva-10699_count-the-factors"></a>

### UVa 10699 — Count the factors／相異質因數個數統計

- 原始碼：[10699_count-the-factors.c](10699_count-the-factors.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, prime-factorization

**English description:** Count the number of different prime factors of integer n.

**中文詳細描述：** 計算整數 n 含有多少個相異的質因數 (不同於總因數個數，只算相異質數)。

**English approach:** Trial division by primes up to sqrt(n). If factor divides n, increment count and divide all occurrences out.

**中文解題思路：** 試除法質因數分解：遇整除數則相異質因數個數 +1，並將該因數完全除盡，最後若剩餘數大於 1 則再計數 +1。 ==========================================================================
