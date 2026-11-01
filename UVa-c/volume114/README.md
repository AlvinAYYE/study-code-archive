# UVa Volume 114

本卷收錄 30 份 C 解答，涵蓋 27 個 UVa 題號，以下依題號排序。

<a id="uva-11401_triangle-counting"></a>

### UVa 11401 — Triangle Counting／長度 1 到 N 線段構成三角形組合計數

- 原始碼：[11401_triangle-counting.c](11401_triangle-counting.c)
- 難度：UVa Star 2
- 演算法：math, combinatorics

**English description:** Given sticks of integer lengths 1, 2, ..., N, find the number of ways to pick 3 distinct sticks that can form a non-degenerate triangle.

**中文詳細描述：** 給定長度分別為 1, 2, ..., N 的木棒，求任意挑選三根相異木棒能構成非退化三角形的選法總數。

**English approach:** Recurrence / closed form: delta(n) = (n-1)*(n-2)/2 - floor((n-1)/2). Accumulate delta to compute total triangles in O(N) or closed formula.

**中文解題思路：** 最長邊為 n 時，其餘兩邊之和須大於 n，新增三角形數為 ((n-1)(n-2)/2 - floor((n-1)/2))/2，遞推前綴和求解。 ==========================================================================


<a id="uva-11402_ahoy-pirates"></a>

### UVa 11402 — Ahoy, Pirates!／海盜！ (線段樹區間賦值與反轉)

- 原始碼：[11402_ahoy-pirates.c](11402_ahoy-pirates.c)
- 難度：Hard
- 演算法：segment-tree, lazy-propagation

**English description:** Maintain a binary array up to 1,024,000 pirates supporting set-to-1, set-to-0, flip bits, and count 1s queries.

**中文詳細描述：** 在長度達 1,024,000 的海盜二進位字串上支援區間全設為 1、全設為 0、位元翻轉及求 1 的個數等查詢。

**English approach:** Segment tree with lazy propagation handling 4 lazy states: no-op, set-0, set-1, and toggle.

**中文解題思路：** 線段樹區間修改與延遲標記 (Lazy Propagation)，支援區間賦值 (0/1) 與區間反轉標記合併。 ==========================================================================


<a id="uva-11407_squares"></a>

### UVa 11407 — Squares／平方數最少和 (四平方和定理動態規劃)

- 原始碼：[11407_squares.c](11407_squares.c)
- 難度：Easy
- 演算法：dp, math

**English description:** Find the minimum number of square numbers required to sum to N.

**中文詳細描述：** 求將正整數 N 表示為完全平方數之和的最少個數（Lagrange 四平方和定理）。

**English approach:** DP state dp[i] = 1 + min(dp[i - j*j]) for all j*j <= i.

**中文解題思路：** 動態規劃：dp[i] = 1 + min(dp[i - j*j])，其中 j*j <= i，答案不超過 4。 ==========================================================================


<a id="uva-11413_fill-the-containers"></a>

### UVa 11413 — Fill the Containers／容器裝水最大容量極小化二分搜尋

- 原始碼：[11413_fill-the-containers.c](11413_fill-the-containers.c)
- 難度：UVa Star 2
- 演算法：binary-search, greedy

**English description:** Divide N milk vessels into M containers in sequential order to minimize the maximum container capacity required.

**中文詳細描述：** 將 N 杯牛奶依順序倒入 M 個容器中，求所需容器的最大容量之最小值 (二分搜尋 + 貪婪容量檢驗)。

**English approach:** Binary search on container capacity C. Greedily fill current container until vessel exceeds C, then start new container.

**中文解題思路：** 在 [最大單杯牛奶量, 總牛奶量] 區間二分搜尋容量 C，貪婪累加牛奶裝載量，超過 C 則換下一個容器，檢驗容器數 <= M。 ==========================================================================


<a id="uva-11417_gcd"></a>
### UVa 11417 — GCD／最大公因數總和

- 原始碼：[11417_gcd.c](11417_gcd.c)
- 演算法：歐幾里得算法、成對枚舉（GCD, Number Theory）

**English description:**

For each input `N` until zero, compute the sum of `gcd(i, j)` over every pair satisfying `1 ≤ i < j ≤ N`. Output the resulting total.

**中文詳細描述：**

逐筆讀入 `N` 直到 0，枚舉所有滿足 `1 ≤ i < j ≤ N` 的整數對，利用歐幾里得算法求每對的最大公因數並累加，最後輸出總和 `G`。

<a id="uva-11417_gcd-pr"></a>

### UVa 11417 — GCD／雙重迴圈公因數總和

- 原始碼：[11417_gcd-pr.c](11417_gcd-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, number-theory, gcd

**English description:** Compute G = sum_{i=1}^{N-1} sum_{j=i+1}^N GCD(i, j) for N <= 500.

**中文詳細描述：** 計算所有數對 (i, j) (1 <= i < j <= N) 的最大公因數之和 G (N <= 500)。

**English approach:** Precompute GCD table or evaluate double loop using Euclidean GCD algorithm.

**中文解題思路：** 歐幾里得輾轉相除法：雙重迴圈枚舉 1 <= i < j <= N 累加 gcd(i, j)。 ==========================================================================


<a id="uva-11420_chest-of-drawers"></a>

### UVa 11420 — Chest of Drawers／抽屜鎖定問題 (鎖定抽屜計數DP)

- 原始碼：[11420_chest-of-drawers.c](11420_chest-of-drawers.c)
- 難度：Easy
- 演算法：dp, combinatorics

**English description:** A vertical stack of n drawers can each be locked or unlocked. A drawer is secured if it is locked AND the drawer above it is locked (top drawer is secured if locked). Count ways to have exactly s secured drawers.

**中文詳細描述：** n 層抽屜各自可上鎖或不上鎖。抽屜安全當且僅當自身上鎖且其上方抽屜亦上鎖（頂層上鎖即安全），求恰好有 s 個安全抽屜的方案數。

**English approach:** DP state dp[i][j][state]: i drawers, j secured, state = 1 if current is locked else 0. Update based on transitions.

**中文解題思路：** 動態規劃：dp[i][j][0/1] 表示前 i 個抽屜中恰有 j 個安全抽屜且當前抽屜未鎖/已鎖的方案數。 ==========================================================================


<a id="uva-11424_gcd-extreme-i"></a>

### UVa 11424 — GCD - Extreme (I)／極限最大公因數求和 I (尤拉函數倍數和)

- 原始碼：[11424_gcd-extreme-i.c](11424_gcd-extreme-i.c)
- 難度：Medium
- 演算法：math, number-theory, euler-totient

**English description:** Compute sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j) for N up to 200,000.

**中文詳細描述：** 計算 N 以內所有數對的最大公因數總和 G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j)（N <= 200,000）。

**English approach:** Precompute Euler's phi function, accumulate f[n] = sum_{d|n} d * phi(n/d), prefix sum of f gives answer.

**中文解題思路：** 預先線性篩求尤拉函數 phi，倍數法累加 f[j] += i * phi[j/i]，前綴和快速回答查詢。 ==========================================================================


<a id="uva-11426_gcd-extreme-ii"></a>

### UVa 11426 — GCD - Extreme (II)／極限最大公因數求和 (歐拉函數)

- 原始碼：[11426_gcd-extreme-ii.c](11426_gcd-extreme-ii.c)
- 難度：Medium
- 演算法：math, number-theory, euler-totient

**English description:** Compute G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j) for N up to 4000000.

**中文詳細描述：** 計算 G = sum_{i=1}^{N-1} sum_{j=i+1}^N gcd(i, j)，N 最大達 4000000。

**English approach:** Use Euler's phi function: sum_{i=1}^n gcd(i, n) = sum_{d|n} d * phi(n/d). Precompute with sieve in O(N log N).

**中文解題思路：** 利用尤拉函數性質化簡：gcd(i, n) 的和等於 sum_{d|n} d * phi(n/d)，預處理倍數累加與前綴和。 ==========================================================================


<a id="uva-11428_cubes"></a>

### UVa 11428 — Cubes／立方之差等式枚舉 (x^3 - y^3 = N)

- 原始碼：[11428_cubes.c](11428_cubes.c)
- 難度：UVa Star 1
- 演算法：math, brute-force

**English description:** Given integer N, find smallest integers x > y > 0 such that x^3 - y^3 = N.

**中文詳細描述：** 給定整數 N，尋找滿足 x^3 - y^3 = N 且 y 最小的正整數解 (x, y)。

**English approach:** Loop y from 1 upwards, then loop x > y until x^3 - y^3 >= N. Return first match.

**中文解題思路：** 雙重枚舉 y 與 x (x > y)，當立方差等於 N 時立即回傳；若立方差已大於 N 則跳出內層迴圈，以確保 y 最小。 ==========================================================================


<a id="uva-11448_who-said-crisis"></a>

### UVa 11448 — Who said crisis?／誰說有危機？ (大數減法)

- 原始碼：[11448_who-said-crisis.c](11448_who-said-crisis.c)
- 難度：Easy
- 演算法：big-integer, math

**English description:** Compute difference A - B for two large non-negative integers up to 10,000 digits.

**中文詳細描述：** 計算兩個長達 10,000 位的大整數之差 A - B（若結果為負數需輸出負號）。

**English approach:** Compare magnitude. Subtract smaller from larger digit by digit with borrowing. Prepend '-' if A < B.

**中文解題思路：** 比對大數絕對值大小，以大數減小數進行逐位借位減法，若 A < B 則在結果前補上負號。 ==========================================================================


<a id="uva-11450_wedding-shopping"></a>

### UVa 11450 — Wedding shopping／婚禮採購預算最大化動態規劃

- 原始碼：[11450_wedding-shopping.c](11450_wedding-shopping.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Given budget M and C garment categories, pick one item from each category to maximize total spend <= M, or report no solution.

**中文詳細描述：** 在預算上限 M 內，於 C 類婚禮服飾中每類各挑選一件商品，求總花費小於等於 M 的最大支出金額。

**English approach:** 2D boolean DP: dp[garment_idx][spent_money] = 1. Update layer by layer; return maximum reachable money in final layer.

**中文解題思路：** 二維布林背包動態規劃：dp[c][money] 表示前 c 類商品是否能剛好湊出 money，逐層轉移取最終層最大合法金額。 ==========================================================================


<a id="uva-11455_behold-my-quadrangle"></a>

### UVa 11455 — Behold my quadrangle／四邊形幾何形態分類判定

- 原始碼：[11455_behold-my-quadrangle.c](11455_behold-my-quadrangle.c)
- 難度：UVa Star 1
- 演算法：geometry

**English description:** Given 4 positive segment lengths, classify the quadrangle into square, rectangle, generic quadrangle, or banana (impossible).

**中文詳細描述：** 給定四條正線段長度，判斷其是否可構成正方形、長方形、普通四邊形或根本無法構成四邊形 (banana)。

**English approach:** Sort 4 lengths. Check square: all equal. Rectangle: a=b and c=d. Quadrangle: longest < sum of other three.

**中文解題思路：** 將四邊由小到大排序：四邊皆等為 square；兩兩相等為 rectangle；最大邊小於其餘三邊之和為 quadrangle；否則為 banana。 ==========================================================================


<a id="uva-11456_trainsorting"></a>

### UVa 11456 — Trainsorting／火車車廂雙向掛載最長有序序列

- 原始碼：[11456_trainsorting.c](11456_trainsorting.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lis

**English description:** Train cars arrive sequentially. Each car can be attached to front or back of train. Cars must remain strictly decreasing from front to back. Maximize cars.

**中文詳細描述：** 車廂依序到達，每節車廂可掛在列車頭部或尾部，整列火車重量必須由頭至尾嚴格遞減。求最多可掛載的車廂節數。

**English approach:** Compute LIS and LDS starting from each index i to the right. Max length is max_i(lis[i] + lds[i] - 1).

**中文解題思路：** 從後往前計算各位置向右的 LIS 與 LDS：車廂 i 作為列車首發車廂時，可形成之最大車長為 lis[i] + lds[i] - 1。 ==========================================================================


<a id="uva-11459_snakes-and-ladders"></a>

### UVa 11459 — Snakes and Ladders／蛇與梯子棋盤遊戲模擬

- 原始碼：[11459_snakes-and-ladders.c](11459_snakes-and-ladders.c)
- 難度：Easy
- 演算法：simulation

**English description:** Simulate players moving along a 100-cell board with dice rolls, climbing ladders or sliding down snakes until a player reaches 100.

**中文詳細描述：** 模擬多名玩家擲骰子在 100 格棋盤上前進，遇到梯子上升、遇到蛇下滑，最先抵達 100 格者獲勝。

**English approach:** Maintain positions of players. Advance current player's pos by roll, teleport if pos is a ladder/snake. Stop advancing if someone hits 100.

**中文解題思路：** 維護各玩家位置，按擲骰點數移動，若停在蛇或梯子起點則跳躍至終點；一旦有玩家抵達 100 格遊戲立即結束。 ==========================================================================


<a id="uva-11461_square-numbers"></a>
### UVa 11461 — Square Numbers／平方數

- 原始碼：[11461_square-numbers.c](11461_square-numbers.c)
- 演算法：平方根、區間計數（Math）

**English description:**

For each inclusive range `[a, b]` until the terminating pair, count how many integers in the range are perfect squares and output the count.

**中文詳細描述：**

每筆輸入給閉區間 `[a, b]`，直到終止資料。要統計區間內有多少完全平方數；由最小可行平方根 `ceil(sqrt(a))` 與最大平方根 `floor(sqrt(b))` 的差即可得到數量，並輸出結果。

<a id="uva-11461_square-numbers-pr"></a>

### UVa 11461 — Square Numbers／區間完全平方數個數

- 原始碼：[11461_square-numbers-pr.c](11461_square-numbers-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Count total number of square numbers between integers a and b inclusive.

**中文詳細描述：** 統計閉區間 [a, b] 內完全平方數的總個數。

**English approach:** Square numbers count in [a, b] = floor(sqrt(b)) - ceil(sqrt(a)) + 1.

**中文解題思路：** 數學公式：開根號取整，區間內完全平方數數量恰為 floor(sqrt(b)) - ceil(sqrt(a)) + 1。 ==========================================================================


<a id="uva-11462_age-sort"></a>
### UVa 11462 — Age Sort／年齡排序

- 原始碼：[11462_age-sort.c](11462_age-sort.c)
- 演算法：計數排序（Counting Sort）

**English description:**

Each data set contains many people's ages from a small fixed range. Sort all ages in nondecreasing order and output them on one line; a frequency array avoids comparison sorting for the large input.

**中文詳細描述：**

每組輸入包含大量年齡，而年齡只會落在很小的固定範圍。使用頻率陣列統計每個年齡出現次數，再由小到大依次輸出相應次數，即可在線性時間完成非遞減排序。

<a id="uva-11463_commandos"></a>

### UVa 11463 — Commandos／突擊隊

- 原始碼：[11463_commandos.c](11463_commandos.c)
- 難度：Medium
- 演算法：graph, floyd-warshall, shortest-path

**English description:** Find minimum time for commandos starting at s to visit all buildings and gather at destination d.

**中文詳細描述：** 突擊隊員從起點 s 出發炸毀所有建築物後在終點 d 集合，求所有人完成任務並會合的最短時間。

**English approach:** All-pairs shortest path with Floyd-Warshall. Maximize (dist[s][i] + dist[i][d]) over all nodes i.

**中文解題思路：** 使用 Floyd-Warshall 求全源最短路徑，遍歷所有中間節點 i，求 max(dist[s][i] + dist[i][d])。 ==========================================================================


<a id="uva-11464_even_parity"></a>

### UVa 11464 — Even Parity／偶數奇偶校驗矩陣變換

- 原始碼：[11464_even_parity.c](11464_even_parity.c)
- 難度：Hard
- 演算法：bitmask, brute-force, parity

**English description:** Given an N x N binary matrix, transform it by flipping only 0s to 1s with minimal flips so every cell has an even number of 1-neighbors.

**中文詳細描述：** 給定一個 N x N 二元矩陣，只能將 0 改為 1，求最少翻轉次數使得每個格子的四鄰居 1 之總數均為偶數。

**English approach:** Enumerate all 2^N possible states for the first row. Subsequent rows are uniquely determined by parity requirements. Return minimum valid flips.

**中文解題思路：** 二進制枚舉第一列所有可能的 2^N 種狀態；後續每一列皆由上一列及其左右鄰居的奇偶性唯一決定，檢查並取最小翻轉數。 ==========================================================================


<a id="uva-11466_largest-prime-divisor"></a>

### UVa 11466 — Largest Prime Divisor／整數最大質因數 (至少含兩個相異質因數)

- 原始碼：[11466_largest-prime-divisor.c](11466_largest-prime-divisor.c)
- 難度：UVa Star 2
- 演算法：math, number-theory

**English description:** Find the largest prime divisor of N, with the requirement that N must have at least two distinct prime divisors; otherwise return -1.

**中文詳細描述：** 求整數 N 的最大質因數，且 N 必須具有至少兩個相異質因數；若為質數或質數冪則回傳 -1。

**English approach:** Trial division by primes up to sqrt(N). Count distinct prime divisors. If distinct >= 2, return maximum prime divisor, else -1.

**中文解題思路：** 試除法質因數分解：統計相異質因數個數，若個數大於等於 2 則回傳最大質因數，否則依題意回傳 -1。 ==========================================================================


<a id="uva-11470_square-sums"></a>
### UVa 11470 — Square Sums／方框總和

- 原始碼：[11470_square-sums.c](11470_square-sums.c)
- 演算法：矩陣分層、模擬（2D Array, Simulation）

**English description:**

Given an `N × N` integer matrix, sum the values on each concentric square border, from the outside toward the center. Output all layer sums in order for every case.

**中文詳細描述：**

每組輸入是一個 `N × N` 整數矩陣，要從最外圈開始，分別計算每一層同心方框邊界上的元素總和。逐層縮小上下左右邊界，避免角落重複計算，最後依外到內的順序輸出各層總和。

<a id="uva-11475_extend-to-palindrome"></a>

### UVa 11475 — Extend to Palindrome／添加最短後綴字元形成迴文

- 原始碼：[11475_extend-to-palindrome.c](11475_extend-to-palindrome.c)
- 難度：UVa Star 2
- 演算法：string, kmp

**English description:** Find the shortest palindrome that can be formed by appending characters to the end of a given string.

**中文詳細描述：** 在給定字串末尾添加最少數量的字元，使其擴充為一個對稱迴文字串。

**English approach:** Find the longest suffix of string S that is a palindrome. Append the reverse of the remaining prefix to S.

**中文解題思路：** 尋找字串 S 中最長的回文後綴，將剩餘前綴反轉後附加至字串末尾即可構成最短回文。 ==========================================================================


<a id="uva-11479_is-this-the-easiest-problem"></a>

### UVa 11479 — Is this the easiest problem?／三角形三邊關係與種類判定

- 原始碼：[11479_is-this-the-easiest-problem.c](11479_is-this-the-easiest-problem.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Determine if three sides form a valid triangle and classify as Equilateral, Isosceles, or Scalene.

**中文詳細描述：** 檢驗三邊長能否構成合法三角形 (兩邊之和大於第三邊)，並判定為正三角形、等腰三角形或不等邊三角形。

**English approach:** Check positivity and triangle inequality (use 64-bit integers to prevent overflow). Classify by edge equality.

**中文解題思路：** 注意使用 64 位元整數相加防止溢位。先判定兩較小邊之和大於最大邊，再依三邊相等、兩邊相等或皆不相等分類。 ==========================================================================


<a id="uva-11489_integer-game"></a>

### UVa 11489 — Integer Game／整數博弈 (數位和與模3分析)

- 原始碼：[11489_integer-game.c](11489_integer-game.c)
- 難度：Easy
- 演算法：game-theory, math

**English description:** Two players take turns removing a digit such that the remaining sum of digits is divisible by 3. First unable to move loses.

**中文詳細描述：** 兩人輪流從大整數中拿走一個數位，使剩下所有數位之和能被 3 整除，無法操作者輸，判定先手 S 是否獲勝。

**English approach:** Let total sum mod 3 be R. If R == 0: player can only pick a multiple of 3 (each pick keeps sum % 3 == 0). Number of 3-multiples determines win/loss parity. If R != 0: player must pick a digit == R mod 3, leaving R=0.

**中文解題思路：** 數位總和模 3 為 R。若 R=0，只能取 3 的倍數，取 3 的倍數個數的奇偶性決定勝負；若 R!=0，先手必須且只能取走一個模 3 等於 R 的數使局面變為 R=0。 ==========================================================================


<a id="uva-11494_queen"></a>

### UVa 11494 — Queen／西洋棋皇后移動最少步數判定

- 原始碼：[11494_queen.c](11494_queen.c)
- 難度：UVa Star 1
- 演算法：basics, math

**English description:** Find minimum moves for a chess queen to move from (x1, y1) to (x2, y2) on an 8x8 board: 0 if same, 1 if aligned, else 2.

**中文詳細描述：** 計算西洋棋皇后從 (x1, y1) 移動至 (x2, y2) 的最少步數：同位置為 0 步，同行/同列/同斜線為 1 步，其餘為 2 步。

**English approach:** Check conditions: if x1==x2 and y1==y2 return 0; if x1==x2 or y1==y2 or abs(x1-x2)==abs(y1-y2) return 1; else return 2.

**中文解題思路：** 起訖點相同回傳 0；在同橫行、同縱列或兩對角斜線上回傳 1；其餘任意位置至多 2 步必可到達。 ==========================================================================


<a id="uva-11495_bubbles-and-buckets"></a>

### UVa 11495 — Bubbles and Buckets／氣泡與水桶 (逆序對與博弈判定)

- 原始碼：[11495_bubbles-and-buckets.c](11495_bubbles-and-buckets.c)
- 難度：Medium
- 演算法：sorting, inversion-count, merge-sort

**English description:** Marcelo and Carlos play a game swapping adjacent out-of-order elements in a permutation. Determine the winner based on inversion parity.

**中文詳細描述：** 兩人輪流交換相鄰逆序元素，無法操作者輸，由逆序對總數的奇偶性決定勝負（奇數先手勝，偶數後手勝）。

**English approach:** Count inversions using Merge Sort in O(N log N). If inversions is odd, Marcelo (first) wins; else Carlos wins.

**中文解題思路：** 利用歸併排序在 O(N log N) 內統計逆序對總數：若為奇數則先手 Marcelo 獲勝，偶數則後手 Carlos 獲勝。 ==========================================================================


<a id="uva-11496_musical-loop"></a>

### UVa 11496 — Musical Loop／音樂循環峰值與谷值計數

- 原始碼：[11496_musical-loop.c](11496_musical-loop.c)
- 難度：Easy
- 演算法：simulation, array

**English description:** Count the number of musical peaks and valleys (local extrema) in a cyclic musical waveform.

**中文詳細描述：** 計算循環音樂波形中的所有局部極大值（波峰）與局部極小值（波谷）的總個數。

**English approach:** Cyclic check: element i is a peak if a[i] > a[prev] and a[i] > a[next]; valley if a[i] < a[prev] and a[i] < a[next].

**中文解題思路：** 環狀相鄰比較：若當前點同時大於左右相鄰點則為峰值；若同時小於左右相鄰點則為谷值。 ==========================================================================


<a id="uva-11498_division-of-nlogonia"></a>
### UVa 11498 — Division of Nlogonia／諾格洛尼亞分界

- 原始碼：[11498_division-of-nlogonia.c](11498_division-of-nlogonia.c)
- 演算法：座標比較（Geometry, Simulation）

**English description:**

The input gives a division point followed by query coordinates. For each query, output whether it lies northeast, northwest, southeast, southwest, or on either dividing line.

**中文詳細描述：**

每組資料先給垂直與水平分界線交點，再給多個待判斷座標。比較查詢點與分界點的橫、縱座標，輸出 `NE`、`NO`、`SE` 或 `SO`；若任一座標相同、落在分界線上，則輸出 `divisa`。

<a id="uva-11498_division-of-nlogonia-pr"></a>

### UVa 11498 — Division of Nlogonia／恩羅戈尼亞國界分割象限判定

- 原始碼：[11498_division-of-nlogonia-pr.c](11498_division-of-nlogonia-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, geometry

**English description:** Given division origin (N, M), determine whether query points lie on border (divisa) or in NE, SE, NO, SO quadrants.

**中文詳細描述：** 以分割基準點 (N, M) 為原點，判定詢問點位在邊界上 (divisa) 或是落於 NE、SE、NO (西北)、SO (西南) 象限。

**English approach:** Direct coordinate comparisons: x == N or y == M is 'divisa'; otherwise check sign differences for 4 quadrants.

**中文解題思路：** 座標直接比對：若 x == N 或 y == M 輸出 divisa；否則依 x 與 y 相對於基準點的大於小於關係輸出四個象限方位。 ==========================================================================
