# UVa Volume 107

本卷收錄 21 份 C 解答，涵蓋 19 個 UVa 題號，以下依題號排序。

<a id="uva-10700_camel-trading"></a>

### UVa 10700 — Camel trading／駱駝交易

- 原始碼：[10700_camel-trading.c](10700_camel-trading.c)
- 難度：Easy
- 演算法：greedy, math, expression-parsing

**English description:** Given an arithmetic expression with additions and multiplications, evaluate maximum possible value (addition first) and minimum possible value (multiplication first).

**中文詳細描述：** 給定包含加法與乘法的算式，求可能的最大值（加法優先）與最小值（乘法優先）。

**English approach:** For max, perform all '+' before '*'. For min, perform all '*' before '+'.

**中文解題思路：** 最大值：先做所有加法再做乘法；最小值：先做所有乘法再做加法。 ==========================================================================


<a id="uva-10701_pre-in-and-post"></a>

### UVa 10701 — Pre, in and post／前序、中序求後序遍歷

- 原始碼：[10701_pre-in-and-post.c](10701_pre-in-and-post.c)
- 難度：Easy
- 演算法：binary-tree, tree-traversal, recursion

**English description:** Given pre-order and in-order traversals of a binary tree with distinct characters, reconstruct and output its post-order traversal.

**中文詳細描述：** 給定二元樹的前序與中序遍歷序列，重建二元樹並輸出其後序遍歷序列。

**English approach:** Root is pre[0]. Find root in inorder sequence to split into left and right subtrees. Recursively build postorder (left, right, root).

**中文解題思路：** 前序首字元為根節點，在中序序列中找到該根節點劃分左右子樹，遞迴構建左、右、根後序序列。 ==========================================================================


<a id="uva-10703_free-spots"></a>

### UVa 10703 — Free spots／空白方格計數 (二維網格覆蓋)

- 原始碼：[10703_free-spots.c](10703_free-spots.c)
- 難度：UVa Star 1
- 演算法：simulation, 2d-grid

**English description:** Given W x H board and multiple subrectangles, count number of grid spots not covered by any rectangle.

**中文詳細描述：** 在 W x H 的棋盤上標記多個子矩形區域，求未被任何矩形覆蓋的空白格總數。

**English approach:** Maintain 2D boolean array covered[w][h]. Mark cells inside each given rectangle. Count unmarked cells.

**中文解題思路：** 二維陣列標記法：對每個輸入矩形將範圍內各格子設為 1，最後統計陣列中為 0 的格子總數。 ==========================================================================


<a id="uva-10706_number-sequence"></a>

### UVa 10706 — Number Sequence／數字拼合序列第 k 位數

- 原始碼：[10706_number-sequence.c](10706_number-sequence.c)
- 難度：Medium
- 演算法：math, binary-search

**English description:** A sequence is formed by concatenating groups: '1', '12', '123', ..., '12345678910...'. Find the digit at index k.

**中文詳細描述：** 數列由遞增數字組拼接而成：1, 12, 123...，求拼接字串中的第 k 位數字。

**English approach:** Calculate lengths of each group S_i. Find which group contains index k, then determine which number within that group and which digit.

**中文解題思路：** 計算每組 S_i 的字元長度並維護前綴長度，二分找到所屬組別，再在該組內定位對應數字及其十進位位元。 ==========================================================================


<a id="uva-10714_ants"></a>

### UVa 10714 — Ants／木竿上的螞蟻 (最早與最晚掉落時間)

- 原始碼：[10714_ants.c](10714_ants.c)
- 難度：UVa Star 1
- 演算法：greedy, brain-teaser

**English description:** Ants walk along a pole of length L. When two collide, they reverse directions. Find min and max time for all ants to fall off.

**中文詳細描述：** 螞蟻在長度為 L 的木竿上移動，兩蟻碰撞時各自掉頭。求所有螞蟻全部掉落的最早時間與最晚時間。

**English approach:** Colliding ants passing through each other is physically equivalent to reversing. Min time = max(min(x, L-x)). Max time = max(max(x, L-x)).

**中文解題思路：** 思維轉換：兩蟻相撞掉頭等價於彼此穿透而過！每隻螞蟻各自走向最近端的時間最大值即為最早時間，走向最遠端的時間最大值即為最晚時間。 ==========================================================================


<a id="uva-10717_mint"></a>

### UVa 10717 — Mint／造幣廠桌腳墊片 (4幣LCM倍數逼近)

- 原始碼：[10717_mint.c](10717_mint.c)
- 難度：Medium
- 演算法：math, number-theory, lcm

**English description:** Given coin thicknesses, choose 4 coins and find table leg heights achievable by stacking 4 coins (multiples of LCM(c1,c2,c3,c4)) closest below and above target height T.

**中文詳細描述：** 給定硬幣厚度，選取 4 種硬幣求其厚度最小公倍數的整數倍，最接近目標桌腳高度 T 的不超過與不低於高度值。

**English approach:** Generate all C(n, 4) combinations of 4 coins. Compute L = lcm(c1, c2, c3, c4). Update best_below = max(L * (T / L)) and best_above = min(L * ceil(T / L)).

**中文解題思路：** 枚舉所有 4 枚硬幣組合求 LCM，用 T / L 逼近不高於 T 的最大倍數，(T + L - 1) / L 逼近不低於 T 的最小倍數。 ==========================================================================


<a id="uva-10718_bit-mask"></a>

### UVa 10718 — Bit Mask／位元遮罩貪心構造

- 原始碼：[10718_bit-mask.c](10718_bit-mask.c)
- 難度：Medium
- 演算法：greedy, bit-manipulation

**English description:** Given N, L, U, find M in range [L, U] such that (N OR M) is maximized, breaking ties by choosing smallest M.

**中文詳細描述：** 給定 N, L, U，在 [L, U] 區間內構造 M 使得 N OR M 最大，若有多個使 M 最小。

**English approach:** Bitwise greedy from bit 31 down to 0: if N has bit 0, set bit in M if M + bit <= U. If N has bit 1, set bit in M only if required so M stays >= L.

**中文解題思路：** 由最高位 31 向 0 貪心決策：若 N 的該位為 0，則在不超過 U 的前提下盡量置 1；若 N 該位為 1，則僅在防止 M 跌破 L 時才置 1。 ==========================================================================


<a id="uva-10721_bar-codes"></a>

### UVa 10721 — Bar Codes／條形碼

- 原始碼：[10721_bar-codes.c](10721_bar-codes.c)
- 難度：Medium
- 演算法：dp, combinatorics

**English description:** Count the number of barcodes of total length n, consisting of k bars, with each bar having width at most m.

**中文詳細描述：** 計算總長度為 n、由 k 個條形構成且每個條形寬度不超過 m 的條形碼數量。

**English approach:** DP state dp[i][j] = number of barcodes of length i with j bars. dp[i][j] = sum(dp[i-w][j-1]) for 1 <= w <= m.

**中文解題思路：** 動態規劃：dp[i][j] 表示長度 i 由 j 條構成的方案數。dp[i][j] = sum(dp[i-w][j-1])，其中 1 <= w <= m。 ==========================================================================


<a id="uva-10739_string-to-palindrome"></a>

### UVa 10739 — String to Palindrome／轉換為回文字串的最少操作數

- 原始碼：[10739_string-to-palindrome.c](10739_string-to-palindrome.c)
- 難度：Medium
- 演算法：dp, edit-distance, palindrome

**English description:** Find the minimum number of insertions, deletions, or substitutions needed to turn a string into a palindrome.

**中文詳細描述：** 求最少需要幾次插入、刪除或替換字元的操作，才能將字串變成回文字串。

**English approach:** Interval DP: if s[i] == s[j], dp[i][j] = dp[i+1][j-1]. Otherwise 1 + min(dp[i+1][j], dp[i][j-1], dp[i+1][j-1]).

**中文解題思路：** 區間動態規劃：若 s[i] == s[j]，則 dp[i][j] = dp[i+1][j-1]；否則為 1 + min(刪左, 刪右, 替換)。 ==========================================================================


<a id="uva-10755_garbage-heap"></a>

### UVa 10755 — Garbage Heap／三維最大子長方體和

- 原始碼：[10755_garbage-heap.c](10755_garbage-heap.c)
- 難度：Medium
- 演算法：dp, 3d-maximum-subarray

**English description:** Find the maximum sub-block sum in an A x B x C 3D array of integers.

**中文詳細描述：** 在 A x B x C 的三維整數矩陣中，尋找元素之和最大的子長方體。

**English approach:** Fix 2D bounds for dimensions 1 and 2, compress to 1D along dimension 3, and apply Kadane's algorithm in O(A^2 * B^2 * C).

**中文解題思路：** 二維前綴和枚舉長寬兩維邊界，將三維問題壓縮為 1 維數列後運行 Kadane 演算法，求最大子段和。 ==========================================================================


<a id="uva-10763_foreign-exchange"></a>

### UVa 10763 — Foreign Exchange／國際交換學生配對互換有效性檢驗

- 原始碼：[10763_foreign-exchange.c](10763_foreign-exchange.c)
- 難度：UVa Star 2
- 演算法：sorting, hash

**English description:** Check if every exchange student wishing to go from country A to country B can be matched with a corresponding student from B to A.

**中文詳細描述：** 檢驗國際交換學生交換計畫是否可完全配對：對每一位自 A 國前往 B 國的學生，必須存在另一位自 B 國前往 A 國的學生。

**English approach:** Store list of (A, B) pairs and canonicalized list of (B, A) pairs. Sort both lists and compare for exact element-wise equality.

**中文解題思路：** 記錄所有 (A, B) 需求，構造鏡像 (B, A) 列表，將兩者排序後比對每一項是否完全一致。 ==========================================================================


<a id="uva-10765_doves-and-bombs"></a>

### UVa 10765 — Doves and bombs／鴿子與炸彈 (割點與連通塊增加數)

- 原始碼：[10765_doves-and-bombs.c](10765_doves-and-bombs.c)
- 難度：Medium
- 演算法：graph, articulation-points, tarjan

**English description:** Find pigeon values of stations (pigeon value = number of connected components after destroying station). Output top m stations.

**中文詳細描述：** 計算各車站被摧毀後全圖連通分量增加的數量（割點割除效應），依鴿子值降序、站點編號升序輸出前 m 名。

**English approach:** Tarjan's articulation point algorithm. Pigeon value of non-cut vertex is 1; for cut vertex, it is 1 + number of DFS children where low[v] >= dfn[u].

**中文解題思路：** Tarjan 割點演算法：非割點值為 1；割點值為 1 + 滿足 low[v] >= dfn[u] 的子樹數量（若為根節點則為子樹數）。 ==========================================================================


<a id="uva-10773_back-to-intermediate-math"></a>

### UVa 10773 — Back to Intermediate Math／渡河垂直路徑與最短時間差

- 原始碼：[10773_back-to-intermediate-math.c](10773_back-to-intermediate-math.c)
- 難度：UVa Star 1
- 演算法：math, physics

**English description:** Compare time taken to cross river directly perpendicular to current vs taking shortest time path obliquely.

**中文詳細描述：** 計算小船以垂直對岸航行與以最短耗時航行渡河時的時間差距，若水流過急無法垂直渡河則標記無效。

**English approach:** Shortest path time t1 = d / sqrt(u^2 - v^2). Fastest path time t2 = d / u. Difference is t1 - t2 (valid if u > v and v > 0).

**中文解題思路：** 垂直路徑時間 t1 = d / sqrt(u^2 - v^2)，最短時間 t2 = d / u，兩者之差即為所求，若 u <= v 或 v = 0 則無有效時間差。 ==========================================================================


<a id="uva-10780_again-prime-no-time"></a>

### UVa 10780 — Again Prime? No Time.／又是質數？沒時間了！ (勒讓德定理因數冪)

- 原始碼：[10780_again-prime-no-time.c](10780_again-prime-no-time.c)
- 難度：Easy
- 演算法：math, number-theory, legendre-formula

**English description:** Find the largest integer power p such that m^p divides n!.

**中文詳細描述：** 求使 m^p 整除 n! 的最大整數冪次 p（若 p=0 則輸出 Impossible）。

**English approach:** Factorize m into prime powers q_i^k_i. For each prime factor, use Legendre's formula to count occurrences in n!: count = sum floor(n / q^j). Then p = min(count_i / k_i).

**中文解題思路：** 質因數分解 m = prod(q_i^k_i)，利用勒讓德公式計算各質數在 n! 中的總冪次，取各商數 count_i / k_i 的最小值。 ==========================================================================


<a id="uva-10783_odd-sum"></a>
### UVa 10783 — Odd Sum／奇數和

- 原始碼：[10783_odd-sum.c](10783_odd-sum.c)
- 演算法：區間加總（Math）

**English description:**

For each test case, the input gives two endpoints `a` and `b`. Sum every odd integer in the inclusive interval and output the result with its case number.

**中文詳細描述：**

每組輸入給出區間端點 `a` 與 `b`，需要把閉區間內所有奇數相加。先把起點調整到第一個奇數，再每次增加 2 累加至終點，最後連同案例編號輸出總和。

<a id="uva-10783_odd-sum-pr"></a>

### UVa 10783 — Odd Sum／區間奇數總和

- 原始碼：[10783_odd-sum-pr.c](10783_odd-sum-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Compute the sum of all odd integers in range [a, b].

**中文詳細描述：** 計算區間 [a, b] 內所有奇數的總和。

**English approach:** Loop through odd numbers from (a % 2 ? a : a + 1) to b with step 2.

**中文解題思路：** 將區間起點調整至奇數，每次遞增 2 累加至 b，直接輸出奇數和。 ==========================================================================


<a id="uva-10784_diagonal"></a>
### UVa 10784 — Diagonal／對角線

- 原始碼：[10784_diagonal.c](10784_diagonal.c)
- 演算法：組合計數、二次方程（Math）

**English description:**

Given a required number `N` of diagonals, find and output the smallest number of vertices of a polygon that can have at least `N` diagonals. The diagonal count for `n` vertices is `n(n-3)/2`.

**中文詳細描述：**

輸入給出所需的對角線數 `N`，要找出至少能產生 `N` 條對角線的多邊形最少頂點數。利用 `n` 邊形對角線數為 `n(n-3)/2`，解不等式後向上取整，並依案例格式輸出答案。

<a id="uva-10784_diagonal-pr"></a>

### UVa 10784 — Diagonal／凸多邊形對角線反求最少頂點數

- 原始碼：[10784_diagonal-pr.c](10784_diagonal-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Find minimum number of vertices of convex polygon that has at least N diagonals: n*(n-3)/2 >= N.

**中文詳細描述：** 凸多邊形對角線數量公式為 n*(n-3)/2。給定對角線數量下限 N，求最少頂點數 n。

**English approach:** Solve quadratic equation n^2 - 3n - 2N >= 0: n = ceil((3 + sqrt(9 + 8N)) / 2).

**中文解題思路：** 一元二次不等式求根公式：n = ceil((3 + sqrt(9 + 8N)) / 2.0)。 ==========================================================================


<a id="uva-10789_prime-frequency"></a>

### UVa 10789 — Prime Frequency／質數頻率字元篩選

- 原始碼：[10789_prime-frequency.c](10789_prime-frequency.c)
- 難度：UVa Star 1
- 演算法：string, prime, sorting

**English description:** Find all characters whose frequency in string is a prime number, in alphabetical order.

**中文詳細描述：** 找出字串中出現次數恰好為質數的所有字母與數字字元，按 ASCII 順序由小到大輸出。

**English approach:** Count character occurrences into array. Check if frequency is prime using prime test.

**中文解題思路：** 陣列統計各字元出現次數，逐一判定頻率是否為質數，依序輸出所有滿足條件的字元 (無滿足者輸出 empty)。 ==========================================================================


<a id="uva-10790_how-many-points-of-intersection"></a>

### UVa 10790 — How Many Points of Intersection?／有多少個交點？

- 原始碼：[10790_how-many-points-of-intersection.c](10790_how-many-points-of-intersection.c)
- 難度：Easy
- 演算法：math, combinatorics

**English description:** Given two parallel lines with a and b points respectively, every point on line 1 is connected to every point on line 2. Find the number of intersection points inside.

**中文詳細描述：** 兩條平行線上分別有 a 與 b 個點，線上每個點都與另一條線上的所有點相連，求兩線段之間內部交點的總數。

**English approach:** Any 2 points on line 1 and 2 points on line 2 uniquely determine 1 internal intersection: C(a,2) * C(b,2).

**中文解題思路：** 在第一條線選取 2 個點，第二條線選取 2 個點，兩兩交叉剛好產生 1 個內部交點：C(a,2) * C(b,2)。 ==========================================================================


<a id="uva-10791_minimum-sum-lcm"></a>

### UVa 10791 — Minimum Sum LCM／最小公倍數最小和

- 原始碼：[10791_minimum-sum-lcm.c](10791_minimum-sum-lcm.c)
- 難度：Medium
- 演算法：math, number-theory, prime-factorization

**English description:** Find the minimum sum of two or more positive integers whose least common multiple is N.

**中文詳細描述：** 求至少兩個正整數的最小可能和，使得它們的最小公倍數恰好為 N。

**English approach:** Prime factorize N = p1^a1 * p2^a2 * ... Minimum sum is achieved by taking each prime power p_i^a_i. If only 1 prime power, add 1.

**中文解題思路：** 對 N 進行質因數分解：N = p1^a1 * p2^a2 * ...，取各質因數冪次之和；若只有一種質因數則需加上 1。 ==========================================================================
