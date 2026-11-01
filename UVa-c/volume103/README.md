# UVa Volume 103

本卷收錄 45 份 C 解答，涵蓋 41 個 UVa 題號，以下依題號排序。

<a id="uva-10300_ecological-premium"></a>
### UVa 10300 — Ecological Premium／生態獎金

- 原始碼：[10300_ecological-premium.c](10300_ecological-premium.c)
- 演算法：數學化簡、加總（Math）

**English description:**

For each test case, the input lists several farmers by farm size, number of animals, and an environmental rating. Compute each farmer's premium as the farm size multiplied by the rating, sum these premiums, and output the total.

**中文詳細描述：**

每組輸入會給出多位農民，以及各自的農地面積、動物數量與環保等級。題目要求把每位農民的面積乘上環保等級，再將所有補助金相加，輸出該組資料的補助總額；動物數在原公式中會互相消去。

<a id="uva-10301_rings_and_glue"></a>

### UVa 10301 — Rings and Glue／環與膠水 (圓相交最大連通塊)

- 原始碼：[10301_rings_and_glue.c](10301_rings_and_glue.c)
- 難度：Medium
- 演算法：geometry, disjoint-set, connected-components

**English description:** Given n circular rings with coordinates and radii, find the size of the largest connected set of glued rings.

**中文詳細描述：** 給定 n 個圓環的位置與半徑，判斷相交（邊界重疊）的環，求最大連通塊中包含的環數量。

**English approach:** Two circles intersect if |r1 - r2| <= dist <= r1 + r2. Build union-find set and return maximum component size.

**中文解題思路：** 兩圓相交的充要條件為圓心距離 d 滿足 |r1 - r2| <= d <= r1 + r2。使用並查集維護連通塊大小。 ==========================================================================


<a id="uva-10302_summation-of-polynomials"></a>

### UVa 10302 — Summation of Polynomials／立方和多項式級數求和

- 原始碼：[10302_summation-of-polynomials.c](10302_summation-of-polynomials.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Compute the sum of cubes 1^3 + 2^3 + ... + x^3 for a given integer x.

**中文詳細描述：** 給定整數 x，計算前 x 個正整數的立方和 1^3 + 2^3 + ... + x^3。

**English approach:** Use the closed-form formula: Sum = (x * (x + 1) / 2)^2. Use long long to avoid overflow.

**中文解題思路：** 使用經典恆等式：1^3 + ... + x^3 = (x*(x+1)/2)^2，以 64 位元整數進行計算防止溢位。 ==========================================================================


<a id="uva-10303_how-many-trees"></a>

### UVa 10303 — How Many Trees?／多少棵二元搜尋樹？ (大數卡特蘭數)

- 原始碼：[10303_how-many-trees.c](10303_how-many-trees.c)
- 難度：Medium
- 演算法：math, catalan-numbers, big-integer

**English description:** Calculate the number of structurally unique binary search trees that can store 1..n keys: Catalan(n) = C(2n, n) / (n + 1).

**中文詳細描述：** 計算由 1..n 鍵值可構成的相異二元搜尋樹數量：即第 n 項卡特蘭數 C_n = C(2n, n) / (n+1)。

**English approach:** Big integer Catalan number evaluation using recurrence C_{n} = C_{n-1} * (4n - 2) / (n + 1).

**中文解題思路：** 使用高精度大數計算卡特蘭數遞推式 C_n = C_{n-1} * (4n - 2) / (n + 1)。 ==========================================================================


<a id="uva-10304_optimal-binary-search-tree"></a>

### UVa 10304 — Optimal Binary Search Tree／最優二元搜尋樹 (區間動態規劃)

- 原始碼：[10304_optimal-binary-search-tree.c](10304_optimal-binary-search-tree.c)
- 難度：Medium
- 演算法：dp, interval-dp, knuth-optimization

**English description:** Find the minimum search cost of an optimal binary search tree for a sequence of keys with access frequencies.

**中文詳細描述：** 給定鍵值的訪問頻率，構建最優二元搜尋樹以最小化檢索所有鍵值的總比較代價。

**English approach:** Interval DP: cost[i][j] = min_{k=i}^j (cost[i][k-1] + cost[k+1][j]) + sum(freq[i..j]) - freq[k].

**中文解題思路：** 區間動態規劃：枚舉子樹根節點 k，狀態轉移 cost[i][j] = min(cost[i][k-1] + cost[k+1][j]) + sum_{t=i}^j freq[t] - freq[k]。 ==========================================================================


<a id="uva-10305_ordering-tasks"></a>
### UVa 10305 — Ordering Tasks／工作排序

- 原始碼：[10305_ordering-tasks.c](10305_ordering-tasks.c)
- 演算法：圖論、拓撲排序（Graph, Topological Sort）

**English description:**

The input gives a set of tasks and directed precedence relations, where one task must be completed before another. Produce and output any ordering that satisfies every relation.

**中文詳細描述：**

輸入包含若干工作與有向的先後限制，每條限制表示某項工作必須在另一項工作之前完成。需要對這張有向圖做拓撲排序，輸出任一個符合全部限制的工作執行順序。

<a id="uva-10306_e-coins"></a>
### UVa 10306 — e-Coins／電子硬幣

- 原始碼：[10306_e-coins.c](10306_e-coins.c)
- 演算法：二維動態規劃、完全背包（Dynamic Programming, Unbounded Knapsack）

**English description:**

Each coin contributes a pair of integer values. From the available coin types, choose coins with repetition so that the sums of the two coordinates satisfy x² + y² = S². Output the minimum number of coins, or report that no such combination exists.

**中文詳細描述：**

輸入給出多種電子硬幣，每種硬幣具有一對整數值，且每種可以重複使用。要讓所選硬幣在兩個座標上的總和 `(x, y)` 滿足 `x² + y² = S²`，輸出需要的最少硬幣數；若無法達成則輸出題目指定的無解訊息。

<a id="uva-10310_dog-and-gopher"></a>

### UVa 10310 — Dog and Gopher／地鼠與獵犬逃生地洞距離幾何判斷

- 原始碼：[10310_dog-and-gopher.c](10310_dog-and-gopher.c)
- 難度：UVa Star 1
- 演算法：geometry

**English description:** Determine if a gopher can reach a gopher hole before a dog catches it (dog runs twice as fast as the gopher).

**中文詳細描述：** 獵犬奔跑速度為地鼠的兩倍，檢驗地鼠是否能在獵犬攔截前逃入某個地洞 (即 2 * dist(gopher, hole) <= dist(dog, hole))。

**English approach:** A gopher escapes into hole H if distance(G, H) * 2 <= distance(D, H), or 4 * dist^2(G, H) <= dist^2(D, H).

**中文解題思路：** 四倍地鼠至地洞距離平方小於等於獵犬至地洞距離平方時，地鼠可成功逃脫，輸出該地洞座標。 ==========================================================================


<a id="uva-10311_goldbach-and-euler"></a>

### UVa 10311 — Goldbach and Euler／哥德巴赫與尤拉 (嚴格兩相異質數和)

- 原始碼：[10311_goldbach-and-euler.c](10311_goldbach-and-euler.c)
- 難度：Medium
- 演算法：math, number-theory, prime

**English description:** Determine if integer n can be expressed as the sum of two distinct primes p1 < p2 such that p2 - p1 is minimized.

**中文詳細描述：** 判定整數 n 是否能表示為兩個嚴格相異質數之和 p1 + p2 = n (p1 < p2)，若有多解使 p2 - p1 最小。

**English approach:** If n is odd: can only be 2 + (n - 2). If n is even: search p1 starting downwards from (n - 1) / 2 until both p1 and n - p1 are prime.

**中文解題思路：** 若 n 為奇數，唯一的偶數質數是 2，驗證 n-2 是否為質數；若 n 為偶數，從 n/2 向下枚舉驗證 p1 與 n-p1 是否皆為質數。 ==========================================================================


<a id="uva-10313_pay-the-price"></a>

### UVa 10313 — Pay the Price／付出代價 (硬幣數目限制的整數拆分DP)

- 原始碼：[10313_pay-the-price.c](10313_pay-the-price.c)
- 難度：Medium
- 演算法：dp, integer-partition

**English description:** Count integer partitions of N using parts 1..N with constraints on the number of parts used (at most L2, or between L1 and L2).

**中文詳細描述：** 求將整數 N 拆分為不超過 N 的正整數之和的拆分數，且限制使用的硬幣/拆分數目在給定區間內。

**English approach:** DP state dp[i][j] = number of partitions of sum i using exactly j parts. Equivalently, partitions of i with largest part j. dp[i][j] = dp[i-1][j-1] + dp[i-j][j].

**中文解題思路：** 經典整數拆分動態規劃：dp[i][j] 表示和為 i 且恰好使用 j 個拆分項的方案數，轉移為 dp[i][j] = dp[i-1][j-1] + dp[i-j][j]。 ==========================================================================


<a id="uva-10315_poker-hands"></a>

### UVa 10315 — Poker Hands／撲克牌手牌牌型強弱對決評比

- 原始碼：[10315_poker-hands.c](10315_poker-hands.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Compare two 5-card poker hands (Black vs White) following standard Texas Hold'em hierarchy (High Card up to Straight Flush).

**中文詳細描述：** 評定黑白雙方各 5 張撲克牌手牌之牌型強弱 (由散牌、一對、順子、同花直到同花順)，判定勝者或平手。

**English approach:** Categorize hand rank: 8=Straight Flush, 7=Four of a Kind, 6=Full House, 5=Flush, 4=Straight, 3=Three of a Kind, 2=Two Pairs, 1=Pair, 0=High Card. Compare ranks then tie-breakers.

**中文解題思路：** 依據點數與花色判定牌型等級 (0 至 8)，階級較高者獲勝；階級相同時按排序後之關鍵牌點數依序比對大小。 ==========================================================================


<a id="uva-10323_factorial-you-must-be-kidding"></a>

### UVa 10323 — Factorial! You Must be Kidding!!!／階乘溢位範圍檢測 (Underflow / Overflow)

- 原始碼：[10323_factorial-you-must-be-kidding.c](10323_factorial-you-must-be-kidding.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Compute n! if it fits between 10,000 and 6,227,020,800. Output Underflow or Overflow otherwise.

**中文詳細描述：** 計算 n!，若結果小於 10000 輸出 Underflow!，大於 6227020800 輸出 Overflow!，在區間內輸出具體數值 (負數考慮擴展階乘)。

**English approach:** Valid range is 8 <= n <= 13. If n < 0, negative odd gives Overflow, negative even gives Underflow.

**中文解題思路：** 對於 n >= 0，僅 8 到 13 之階乘落在合法區間內；負數時利用 Gamma 函數極限，奇數為 Overflow，偶數為 Underflow。 ==========================================================================


<a id="uva-10324_zeros-and-ones"></a>

### UVa 10324 — Zeros and Ones／0與1區間一致性查詢

- 原始碼：[10324_zeros-and-ones.c](10324_zeros-and-ones.c)
- 難度：UVa Star 1
- 演算法：string, prefix-sum

**English description:** Determine whether all characters in string between indices min(i, j) and max(i, j) are identical.

**中文詳細描述：** 給定由 '0' 與 '1' 組成的字串，多次查詢區間 [min(i, j), max(i, j)] 內的所有字元是否完全相同。

**English approach:** Precompute prefix sum of differences or run-length encoding IDs. Check id[i] == id[j] in O(1).

**中文解題思路：** 預先計算同字元區塊編號 id 陣列：若兩下標所屬區塊編號相同，代表區間內字元完全一致，O(1) 回答每次查詢。 ==========================================================================


<a id="uva-10325_the-lottery"></a>

### UVa 10325 — The Lottery／彩票 (容斥原理未整除計數)

- 原始碼：[10325_the-lottery.c](10325_the-lottery.c)
- 難度：Medium
- 演算法：math, inclusion-exclusion, lcm

**English description:** Count numbers in 1..N that are not divisible by any of M given integers.

**中文詳細描述：** 計算 1 到 N 之間不能被給定 M 個整數中任何一個整除的數字數量。

**English approach:** Inclusion-Exclusion Principle over subsets of size 1 to M: subtract single multiples, add pairwise LCM multiples, etc.

**中文解題思路：** 利用排容原理：枚舉 2^M 種子集狀態，奇數個數的 LCM 倍數減去，偶數個數的 LCM 倍數加上。 ==========================================================================


<a id="uva-10327_flip-sort"></a>
### UVa 10327 — Flip Sort／翻轉排序

- 原始碼：[10327_flip-sort.c](10327_flip-sort.c)
- 演算法：逆序對計數、排序（Inversion Count）

**English description:**

Given a sequence of numbers, sorting is performed by swapping adjacent out-of-order elements. Determine and output the minimum number of such swaps needed to put the sequence in increasing order.

**中文詳細描述：**

輸入是一串數字，只允許交換相鄰且順序錯誤的元素來完成遞增排序。相鄰交換的最少次數等於序列中的逆序對數量，因此逐一計數所有前大後小的數對，並輸出交換次數。

<a id="uva-10327_flip-sort-pr"></a>

### UVa 10327 — Flip Sort／相鄰交換排序最少步數 (逆序對計數)

- 原始碼：[10327_flip-sort-pr.c](10327_flip-sort-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：sorting, inversion-number

**English description:** Find minimum number of adjacent swaps required to sort an array.

**中文詳細描述：** 求透過相鄰兩元素交換 (Bubble Sort 操作) 將陣列排成升序所需的最少交換次數 (即求陣列逆序數)。

**English approach:** O(N^2) pairwise inversion count: count pairs (i, j) with i < j and a[i] > a[j].

**中文解題思路：** 相鄰交換最少次數定理：最少操作步數嚴格等於陣列中的逆序對數量，雙層迴圈 O(N^2) 統計即可。 ==========================================================================


<a id="uva-10330_power-transmission"></a>

### UVa 10330 — Power Transmission／電力傳輸 (節點容量限制的最大流)

- 原始碼：[10330_power-transmission.c](10330_power-transmission.c)
- 難度：Medium
- 演算法：network-flow, edmonds-karp, vertex-splitting

**English description:** Find maximum power flow through a transmission network with capacities on both edges and vertices.

**中文詳細描述：** 在邊與頂點均有容量限制的傳輸網絡中求最大電力流量。

**English approach:** Split each vertex v into v_in and v_out connected by an edge with capacity cap[v]. Connect super-source and super-sink.

**中文解題思路：** 拆點法：將每個點拆為入點與出點，中間連一條容量為點容量的邊，轉為標準最大流求解。 ==========================================================================


<a id="uva-10334_ray-through-glasses"></a>

### UVa 10334 — Ray Through Glasses／光線穿透玻璃反射路徑數

- 原始碼：[10334_ray-through-glasses.c](10334_ray-through-glasses.c)
- 難度：UVa Star 2
- 演算法：math, fibonacci

**English description:** Find the number of distinct reflection paths for a ray of light bouncing inside two sheets of glass n times.

**中文詳細描述：** 計算光線在兩塊緊貼的玻璃平板之間歷經 n 次反射時的所有相異可能反射路徑總數 (費氏數列 F(n+2))。

**English approach:** The number of paths follows the Fibonacci sequence: paths(n) = F(n + 2).

**中文解題思路：** 光線反射路徑數精確對應費波那契數列：paths(0)=1, paths(1)=2, paths(2)=3, paths(n)=F(n+2)。 ==========================================================================


<a id="uva-10336_rank-the-languages"></a>

### UVa 10336 — Rank the Languages／語言地圖連通分量區域排名

- 原始碼：[10336_rank-the-languages.c](10336_rank-the-languages.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill, dfs

**English description:** Given a grid of language characters, count connected states for each language using 4-way flood fill and rank by count.

**中文詳細描述：** 給定二維語言字元網格，以四方向漫水填充 (Flood Fill) 統計各語言連通領土數量，並依數量由大到小排序。

**English approach:** Scan grid: upon seeing an unvisited cell, launch DFS/BFS to mark entire connected component, and increment count for that letter.

**中文解題思路：** 逐格掃描網格，遇未走訪格子啟動 DFS 染整塊連通分量並將該字元計數加一，最後依出現次數降序、字母序升序排序。 ==========================================================================


<a id="uva-10337_flight-planner"></a>

### UVa 10337 — Flight Planner／飛行路徑規劃

- 原始碼：[10337_flight-planner.c](10337_flight-planner.c)
- 難度：Medium
- 演算法：dp

**English description:** Plan plane altitude changes (climb, sink, hold) across miles to minimize fuel, accounting for headwinds/tailwinds at different altitudes.

**中文詳細描述：** 規劃飛機在不同航段的高度變化（爬升、下降、平飛）以最小化燃油消耗（需考慮各高度逆風/順風）。

**English approach:** DP state dp[x][alt] = min fuel to reach mile x at altitude alt (0 to 9). Base case dp[0][0] = 0, must end at dp[X][0].

**中文解題思路：** 動態規劃：dp[x][a] 表示第 x 個航段在高度 a 的最小油耗。從 (0,0) 出發，最終抵達 (X, 0)。 ==========================================================================


<a id="uva-10338_mischievous-children"></a>

### UVa 10338 — Mischievous Children／字母異位詞多項式排列計數

- 原始碼：[10338_mischievous-children.c](10338_mischievous-children.c)
- 難度：UVa Star 1
- 演算法：math, combinatorics

**English description:** Find the number of distinct word anagrams that can be formed using all letters of a given uppercase word.

**中文詳細描述：** 計算給定英文字串中所有字母能組合出的相異排列字串總數 (多項式係數 N! / (c1! * c2! * ... * ck!))。

**English approach:** Multinomial permutation formula: L! / prod(count[c]!). Precompute factorials using 64-bit unsigned integers.

**中文解題思路：** 套用多項式排列公式：總長度階乘除以各相異字母出現次數的階乘積，以 64 位元整數累乘計算。 ==========================================================================


<a id="uva-10340_all-in-all"></a>
### UVa 10340 — All in All／全都包含

- 原始碼：[10340_all-in-all.c](10340_all-in-all.c)
- 演算法：字串、雙指標、貪心（String, Two Pointers）

**English description:**

For every input pair of strings `s` and `t`, decide whether `s` is a subsequence of `t`: its characters must appear in order but need not be consecutive. Output the required affirmative or negative answer.

**中文詳細描述：**

每筆輸入包含字串 `s` 與 `t`，要判斷 `s` 是否為 `t` 的子序列，也就是 `s` 的每個字元能否依原順序在 `t` 中找到，但不必相鄰。以雙指標由左至右配對，最後輸出成功或失敗的結果。

<a id="uva-10340_all-in-all-pr"></a>

### UVa 10340 — All in All／子序列雙指標判定

- 原始碼：[10340_all-in-all-pr.c](10340_all-in-all-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：two-pointers, string, greedy

**English description:** Determine if string s is a subsequence of string t.

**中文詳細描述：** 判定字串 s 是否為字串 t 的子序列 (可透過從 t 中刪除某些字元得到 s)。

**English approach:** Two pointers: iterate through t, advancing pointer in s on matching character.

**中文解題思路：** 貪婪雙指標：遍歷字串 t，每當遇到與 s[i] 相等的字元即將 i 前移，若 i 抵達 s 尾端則判定為子序列。 ==========================================================================


<a id="uva-10341_solve-it"></a>

### UVa 10341 — Solve It／微積分方程數值求根 (二分搜尋法)

- 原始碼：[10341_solve-it.c](10341_solve-it.c)
- 難度：UVa Star 2
- 演算法：binary-search, math

**English description:** Find solution x in [0, 1] for p*e^-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 + u = 0.

**中文詳細描述：** 在 [0, 1] 區間求解連續非遞增函數 f(x) = 0 的實數根 (二分搜尋法迭代精確到 4 位小數)。

**English approach:** Bisection method: evaluate f(x). Since f(x) is monotonically decreasing in [0, 1], bisect 80 times.

**中文解題思路：** 因函數在 [0, 1] 區間單調遞減，檢驗 f(0) 與 f(1) 是否異號，若有根則執行 80 次二分逼近求得精確解。 ==========================================================================


<a id="uva-10344_23-out-of-5"></a>

### UVa 10344 — 23 out of 5／五數運算符組合湊 23 窮舉搜尋

- 原始碼：[10344_23-out-of-5.c](10344_23-out-of-5.c)
- 難度：UVa Star 2
- 演算法：backtracking, brute-force

**English description:** Given 5 numbers, determine if they can be ordered and combined with operators +, -, * to yield exactly 23.

**中文詳細描述：** 給定 5 個整數，判斷是否存在一種全排列並插入加、減、乘 (+, -, *) 運算符使得最終運算結果恰好等於 23。

**English approach:** Permute the 5 numbers (5! = 120), then evaluate all 3^4 = 81 operator combinations using depth-first search.

**中文解題思路：** 回溯搜尋全排列 120 種組合，對每組排列深度優先枚舉 4 個運算子的 3^4 種可能，檢驗運算結果是否等於 23。 ==========================================================================


<a id="uva-10346_peters-smokes"></a>
### UVa 10346 — Peter's Smokes／彼得的香菸

- 原始碼：[10346_peters-smokes.c](10346_peters-smokes.c)
- 演算法：模擬、數學（Simulation, Math）

**English description:**

Peter starts with `n` cigarettes and can exchange every `k` cigarette butts for one new cigarette. Repeatedly use all possible exchanges and output the total number of cigarettes he can smoke.

**中文詳細描述：**

輸入給出彼得一開始擁有的 `n` 根香菸，以及每 `k` 個菸蒂可換一根新香菸的規則。每抽完一根就多一個菸蒂，持續交換到不足 `k` 個為止，輸出總共能抽的香菸數。

<a id="uva-10346_peters-smokes-pr"></a>

### UVa 10346 — Peter's Smokes／彼得的香菸 (菸蒂兌換模擬)

- 原始碼：[10346_peters-smokes-pr.c](10346_peters-smokes-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, simulation

**English description:** Peter has n cigarettes. He can exchange k cigarette butts for 1 new cigarette. Find total cigarettes smoked.

**中文詳細描述：** 彼得有 n 支香菸，每抽完一支產生一個菸蒂。每收集 k 個菸蒂可兌換 1 支新香菸，求彼得總共能抽多少支菸。

**English approach:** Loop simulation: total += n, butts = n. In each step, new_cigs = butts / k, butts = butts % k + new_cigs.

**中文解題思路：** 模擬兌換流程：只要菸蒂數 butts >= k，兌換新菸 new_c = butts / k，累加抽菸總數，更新剩餘菸蒂 butts % k + new_c。 ==========================================================================


<a id="uva-10347_medians"></a>

### UVa 10347 — Medians／三角形三中線長度反求面積

- 原始碼：[10347_medians.c](10347_medians.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Given lengths of the three medians of a triangle, calculate the area of the original triangle, or return -1 if impossible.

**中文詳細描述：** 給定三角形的三條中線長度，計算該原始三角形的面積；若中線長度無法構成合法三角形則回傳 -1。

**English approach:** The area of a triangle formed by its medians is 3/4 the area of the original triangle. Thus Area = (4/3) * Heron(m1, m2, m3).

**中文解題思路：** 以三中線構成之三角形面積為原三角形面積的 3/4，故原面積 = (4/3) * 海龍公式(m1, m2, m3)。 ==========================================================================


<a id="uva-10359_tiling"></a>

### UVa 10359 — Tiling／2 x n 骨牌與正方形鋪滿計數

- 原始碼：[10359_tiling.c](10359_tiling.c)
- 難度：Easy
- 演算法：math, dp, big-integer

**English description:** Count the number of ways to tile a 2 x n rectangular board using 2 x 1 dominoes and 2 x 2 squares.

**中文詳細描述：** 求用 2 x 1 骨牌與 2 x 2 正方形完全鋪滿 2 x n 矩形網格的方案數。

**English approach:** Recurrence relation: f(n) = f(n-1) + 2*f(n-2) with f(0) = 1, f(1) = 1, f(2) = 3.

**中文解題思路：** 遞推關係式：最後一列放豎骨牌有 f(n-1) 種；放兩橫骨牌或一 2x2 正方形有 2*f(n-2) 種，故 f(n) = f(n-1) + 2*f(n-2)。 ==========================================================================


<a id="uva-10360_rat-attack"></a>
### UVa 10360 — Rat Attack／老鼠攻擊

- 原始碼：[10360_rat-attack.c](10360_rat-attack.c)
- 演算法：二維陣列、範圍累加（2D Array, Range Accumulation）

**English description:**

The input gives rat populations at grid coordinates and a bomb radius `d`. A bomb centered at `(x, y)` kills rats in the square from `x-d` to `x+d` and `y-d` to `y+d`; output the best center and the maximum population eliminated.

**中文詳細描述：**

輸入列出網格上各座標的老鼠數量，以及炸彈影響半徑 `d`。炸彈放在 `(x, y)` 時會消滅橫、縱座標各相差不超過 `d` 的正方形範圍內所有老鼠；需要找出可消滅最多老鼠的中心座標，並輸出座標與最大數量。

<a id="uva-10361_automatic-poetry"></a>

### UVa 10361 — Automatic Poetry／自動詩詞韻腳段落重排

- 原始碼：[10361_automatic-poetry.c](10361_automatic-poetry.c)
- 難度：UVa Star 1
- 演算法：string, parsing

**English description:** Given two lines of poetry with XML-like tags <s1><s2><s3><s4> in the first line and '...' in the second, rearrange to replace '...' with s4 s3 s2 s5.

**中文詳細描述：** 給定兩句詩詞，第一句包含由角括號標記的子字串，第二句以 '...' 結尾，將標記段落依 s4+s3+s2+s5 順序重排替換 '...'。

**English approach:** Parse line 1 into 5 parts based on '<' and '>'. Print cleaned line 1, then print line 2 with '...' replaced by rearranged parts.

**中文解題思路：** 以字元掃描依 '<' 與 '>' 將首行拆解為 5 個子字串，第二行將結尾 '...' 替換為第四、三、二、五部分並拼接輸出。 ==========================================================================


<a id="uva-10363_tic-tac-toe"></a>

### UVa 10363 — Tic Tac Toe／井字棋棋盤有效性驗證

- 原始碼：[10363_tic-tac-toe.c](10363_tic-tac-toe.c)
- 難度：Medium
- 演算法：game-theory, grid-simulation

**English description:** Determine if a given 3x3 Tic Tac Toe board state is valid and reachable from an empty board.

**中文詳細描述：** 判斷給定的 3x3 井字棋盤面是否合法且可由空棋盤依遊戲規則達到。

**English approach:** Count X and O. X == O or X == O + 1. If X wins, X == O + 1. If O wins, X == O. Both cannot win simultaneously.

**中文解題思路：** 統計 X 與 O 數量：X 必等於 O 或 O+1；X 獲勝時 X 必為 O+1；O 獲勝時 X 必等於 O；兩者不可同時獲勝。 ==========================================================================


<a id="uva-10364_square"></a>

### UVa 10364 — Square／拼成正方形 (回溯剪枝與子集劃分)

- 原始碼：[10364_square.c](10364_square.c)
- 難度：Medium
- 演算法：backtracking, dfs, pruning

**English description:** Determine if M stick segments can be joined end-to-end to form a square of side length sum / 4.

**中文詳細描述：** 判斷給定的 M 根木條能否剛好拼成一個正方形（劃分為 4 個長度相等的子集）。

**English approach:** Total length must be divisible by 4. Sort descending. Backtrack to fill 4 sides of length side_len.

**中文解題思路：** 總長度必為 4 的倍數且最大木條 <= side。降序排序後進行回溯搜尋，依序拼出 4 條邊。 ==========================================================================


<a id="uva-10365_blocks"></a>

### UVa 10365 — Blocks／積木長方體最小表面積

- 原始碼：[10365_blocks.c](10365_blocks.c)
- 難度：Easy
- 演算法：math, brute-force

**English description:** Find the minimum surface area of a box containing N unit cubes (A * B * C = N, minimize 2*(A*B + B*C + C*A)).

**中文詳細描述：** 求用 N 塊單位立方體拼成的長方體（A * B * C = N）的最小表面積 2*(AB + BC + CA)。

**English approach:** Brute force search A <= cbrt(N) and B <= sqrt(N/A). Let C = N / (A*B). Find min(2*(A*B + B*C + C*A)).

**中文解題思路：** 三重因數枚舉：A 跑至 cbrt(N)，B 跑至 sqrt(N/A)，令 C = N / (A*B)，取表面積最小值。 ==========================================================================


<a id="uva-10368_euclids-game"></a>

### UVa 10368 — Euclid's Game／歐幾里得博弈

- 原始碼：[10368_euclids-game.c](10368_euclids-game.c)
- 難度：Medium
- 演算法：game-theory, math, gcd

**English description:** Stan and Ollie play a game subtracting multiples of smaller number from larger. First to reach 0 wins.

**中文詳細描述：** 兩人輪流從大數中減去小數的整數倍，最先使某數變為 0 者獲勝，判定先手 Stan 是否獲勝。

**English approach:** If a % b == 0, current player wins. If a / b >= 2, current player can force a win by choosing whether to leave (b, a%b) or (a%b + b, b). Otherwise single move forced.

**中文解題思路：** 若 a % b == 0 則當前玩家勝；若 a / b >= 2 則當前玩家擁有選擇權必勝；否則只能執行唯一一步 a - b，交替輪轉局面。 ==========================================================================


<a id="uva-10369_arctic-network"></a>

### UVa 10369 — Arctic Network／北極哨所衛星通訊半徑二分生成樹

- 原始碼：[10369_arctic-network.c](10369_arctic-network.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Given S satellite channels and P outposts, find minimum transceiver power D such that all outposts can communicate.

**中文詳細描述：** 給定 S 個衛星頻道與 P 個北極哨所座標，配置無線電收發器使其覆蓋半徑 D 最小且全哨所皆能彼此連通。

**English approach:** Compute MST of all P outposts. S satellite channels can connect S largest components, so D is the weight of the (P - S)-th edge in the sorted MST edge list.

**中文解題思路：** 構建哨所間的最小生成樹 (MST)，由於 S 個衛星站可省去 (S - 1) 條最長邊，所需最小半徑即為 MST 中第 (P - S) 條邊之權重。 ==========================================================================


<a id="uva-10370_above-average"></a>
### UVa 10370 — Above Average／高於平均

- 原始碼：[10370_above-average.c](10370_above-average.c)
- 演算法：陣列統計、平均值（Array, Arithmetic）

**English description:**

For each class, the input supplies all students' grades. Compute the class average, count the grades strictly above it, and output that count as a percentage of the class with the required formatting.

**中文詳細描述：**

每組輸入包含一個班級的學生人數與所有成績。先算出全班平均分數，再統計成績嚴格高於平均的人數，最後依題目要求的格式輸出其占全班的百分比。

<a id="uva-10370_above-average-pr"></a>

### UVa 10370 — Above Average／超越平均人數百分比

- 原始碼：[10370_above-average-pr.c](10370_above-average-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, array

**English description:** Calculate percentage of students in class whose scores are strictly above class average.

**中文詳細描述：** 計算班級中成績嚴格高於班級平均分數的學生人數百分比 (輸出保留 3 位小數)。

**English approach:** Compute mean score. Count scores > mean. Percentage = count * 100.0 / N.

**中文解題思路：** 一次迴圈求總分與平均值，二次迴圈統計嚴格大於平均值的人數，計算百分比。 ==========================================================================


<a id="uva-10375_choose-and-divide"></a>

### UVa 10375 — Choose and divide／組合數相除 C(p,q) / C(r,s)

- 原始碼：[10375_choose-and-divide.c](10375_choose-and-divide.c)
- 難度：Easy
- 演算法：math, combinatorics, logarithms

**English description:** Compute the ratio of two binomial coefficients C(p, q) / C(r, s) accurately without overflow.

**中文詳細描述：** 精確計算兩個二項式組合數的商 C(p, q) / C(r, s) 避免大數溢位。

**English approach:** Interleave multiplications and divisions, or factorize into primes, or sum logs and exponentiate.

**中文解題思路：** 交替進行乘法與除法保持數值在合理浮點數範圍內，或對兩側質因數分解後計算最終乘積。 ==========================================================================


<a id="uva-10377_maze-traversal"></a>

### UVa 10377 — Maze Traversal／迷宮機器人巡航

- 原始碼：[10377_maze-traversal.c](10377_maze-traversal.c)
- 難度：Easy
- 演算法：simulation, grid

**English description:** Simulate a robot moving in a grid maze executing commands: R (turn right), L (turn left), F (move forward if not wall), Q (quit).

**中文詳細描述：** 模擬機器人在網格迷宮中根據指令序列巡航（R: 右轉, L: 左轉, F: 前進遇牆停, Q: 退出），求最終座標與朝向。

**English approach:** Track position (r, c) and orientation (N=0, E=1, S=2, W=3). Update orientation on L/R, update position on F if cell is not '*'.

**中文解題思路：** 維護機器人位置與朝向（北東南西 0..3），遇到轉向指令更新方向，前進指令遇空格才移動。 ==========================================================================


<a id="uva-10382_watering-grass"></a>

### UVa 10382 — Watering Grass／草地澆水 (區間覆蓋貪心法)

- 原始碼：[10382_watering-grass.c](10382_watering-grass.c)
- 難度：Medium
- 演算法：greedy, interval-covering

**English description:** Find the minimum number of circular sprinklers along the center of a rectangular lawn of width w and length l needed to completely water it.

**中文詳細描述：** 求在長 l 寬 w 的長方形草地中心線上，最少需開啟幾個圓形噴水器才能完全覆蓋整片草地。

**English approach:** Convert each circle into a 1D covered interval [x - dx, x + dx] along the strip using Pythagorean theorem dx = sqrt(r^2 - (w/2)^2). Run interval covering greedy algorithm.

**中文解題思路：** 利用畢氏定理 dx = sqrt(r^2 - (w/2)^2) 將圓轉化為中心線上的 1 維覆蓋區間，貪心選取能覆蓋當前左端點且向右延伸最遠的噴水器。 ==========================================================================


<a id="uva-10391_compound-words"></a>

### UVa 10391 — Compound Words／複合詞字典拆分快速比對

- 原始碼：[10391_compound-words.c](10391_compound-words.c)
- 難度：UVa Star 2
- 演算法：string, hash, sorting

**English description:** Find all compound words in a sorted dictionary that are formed by concatenating exactly two other words in the dictionary.

**中文詳細描述：** 在已排序的英文字典中，找出所有能恰好由字典內另外兩個單詞直接拼接而成的複合單詞。

**English approach:** For each word, split at all possible split positions into prefix and suffix. Check if both prefix and suffix exist in hash table / sorted list.

**中文解題思路：** 逐一走訪字典單詞，窮舉每個分割點將單詞拆為前後兩半，二分搜尋檢驗前後兩半是否均為字典中的獨立單詞。 ==========================================================================


<a id="uva-10392_factoring-large-numbers"></a>

### UVa 10392 — Factoring Large Numbers／大數質因數分解

- 原始碼：[10392_factoring-large-numbers.c](10392_factoring-large-numbers.c)
- 難度：Easy
- 演算法：math, number-theory, prime-factorization

**English description:** Factorize large 64-bit integers into prime factors in ascending order.

**中文詳細描述：** 將不超過 10^14 的大整數分解為質因數並依升序輸出。

**English approach:** Trial division by 2 and odd numbers up to sqrt(N). Print each factor.

**中文解題思路：** 試除法：先除以 2，再用奇數試除至 sqrt(N)，印出所有質因數。 ==========================================================================


<a id="uva-10394_twin-primes"></a>

### UVa 10394 — Twin Primes／孿生質數對預處理

- 原始碼：[10394_twin-primes.c](10394_twin-primes.c)
- 難度：UVa Star 1
- 演算法：math, prime-sieve

**English description:** Find the S-th pair of twin primes (primes p and p+2) for S <= 100,000.

**中文詳細描述：** 求第 S 組孿生質數 (差為 2 的一對質數 (p, p+2))，S 最大達 10 萬 (質數篩預處理至 2000 萬)。

**English approach:** Sieve of Eratosthenes up to 20,000,000. Collect pairs where is_prime[p] and is_prime[p+2].

**中文解題思路：** 埃氏篩預處理質數表，遍歷收集所有相鄰差為 2 的質數對，預先存入答案陣列支援 O(1) 查詢。 ==========================================================================


<a id="uva-10397_connect-the-campus"></a>

### UVa 10397 — Connect the Campus／大學校園既有線路擴充最小生成樹

- 原始碼：[10397_connect-the-campus.c](10397_connect-the-campus.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Given building coordinates and existing cables, find the minimum additional cable length needed to connect all buildings.

**中文詳細描述：** 給定校園建築物座標與既有電纜連接關係，求將全校所有建築物完全連通所需鋪設之最少額外電纜長度。

**English approach:** Kruskal's algorithm with pre-union of existing cables (weight 0). Compute Euclidean distance for remaining building pairs and sum MST edges.

**中文解題思路：** 在既有電纜的基礎上執行 Kruskal：先將已有連線合併，對其餘建築對計算歐氏距離並依權重排序構建最小生成樹。 ==========================================================================
