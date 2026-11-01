# UVa Volume 108

本卷收錄 26 份 C 解答，涵蓋 23 個 UVa 題號，以下依題號排序。

<a id="uva-10800_not-that-kind-of-graph"></a>

### UVa 10800 — Not That Kind of Graph／折線走勢圖 ASCII 繪製

- 原始碼：[10800_not-that-kind-of-graph.c](10800_not-that-kind-of-graph.c)
- 難度：Medium
- 演算法：simulation, string

**English description:** Plot an ASCII price trend graph using '/' for rise, '\' for fall, and '_' for flat, aligned to axes.

**中文詳細描述：** 用 ASCII 字元繪製股票走勢折線圖（'/' 上漲、'\' 下跌、'_' 持平），自動配平高度並附帶坐標軸。

**English approach:** Simulate coordinate heights for each step. Find min and max height to dimension the 2D canvas. Draw axes and trim trailing spaces.

**中文解題思路：** 先遍歷指令計算各步的 y 坐標高低，取最小 y 與最大 y 確定畫布尺寸，填充字元並加上左側垂直軸與底部水平軸。 ==========================================================================


<a id="uva-10801_lift-hopping"></a>

### UVa 10801 — Lift Hopping／大樓多電梯換乘最短時間 Dijkstra

- 原始碼：[10801_lift-hopping.c](10801_lift-hopping.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, shortest-path

**English description:** Find the minimum time to travel from floor 0 to target floor k using N elevators, with per-floor speed T_i and 60s transfer penalty.

**中文詳細描述：** 利用 N 部各具不同行駛速度的電梯自 0 樓到達目標 k 樓，跨電梯換乘需等待 60 秒，求最短抵達時間 (狀態圖 Dijkstra)。

**English approach:** Graph modeling with states (elevator_id, floor). Edges represent within-elevator movement (speed T_i * diff) and elevator transfers (cost 60s).

**中文解題思路：** 以 (電梯編號, 樓層) 作為圖節點，同電梯樓層移動代價為 T_i * 樓層差，同樓層換乘其他電梯邊權為 60 秒，執行 Dijkstra 演算法。 ==========================================================================


<a id="uva-10803_thunder-mountain"></a>

### UVa 10803 — Thunder Mountain／雷霆山 (全源最短路徑最大連通距離)

- 原始碼：[10803_thunder-mountain.c](10803_thunder-mountain.c)
- 難度：Medium
- 演算法：graph, floyd-warshall

**English description:** Towns within 10 units of distance can communicate directly. Find the maximum travel distance between any two connected towns, or report 'Send earlier teams!' if disconnected.

**中文詳細描述：** 相距不超過 10 單位距離的城鎮可直接連通，求任意兩城鎮間最短路徑的最大值；若全圖不連通則輸出警告。

**English approach:** Floyd-Warshall on Euclidean distances <= 10. Maximize dist[i][j] over all pairs. If any dist is infinity, report disconnected.

**中文解題思路：** 對距離 <= 10 的點對連邊，執行 Floyd-Warshall 求全源最短路徑，取全圖最大距離；若有不可達點對則判定為不連通。 ==========================================================================


<a id="uva-10806_dijkstra_dijkstra"></a>

### UVa 10806 — Dijkstra, Dijkstra.／去回不重複路徑之最小總長度

- 原始碼：[10806_dijkstra_dijkstra.c](10806_dijkstra_dijkstra.c)
- 難度：Hard
- 演算法：network-flow, min-cost-max-flow, mcmf

**English description:** Find two edge-disjoint paths from vertex 1 to vertex N with minimum total length (there and back).

**中文詳細描述：** 求從頂點 1 到頂點 N 的兩條邊不相交路徑（去與回走不同邊），使其總權重和最小。

**English approach:** Model as Min-Cost Max-Flow: find flow of 2 from source 1 to sink N where each edge has capacity 1.

**中文解題思路：** 轉化為最小費用最大流問題：每條無向邊容量為 1，求從頂點 1 到 N 流量為 2 的最小費用流。 ==========================================================================


<a id="uva-10810_ultra-quicksort"></a>
### UVa 10810 — Ultra-QuickSort／超快速排序

- 原始碼：[10810_ultra-quicksort.c](10810_ultra-quicksort.c)
- 演算法：合併排序、逆序對（Merge Sort, Inversion Count）

**English description:**

For each input sequence, determine the minimum number of adjacent exchanges needed to sort it. Count inversions during merge sort and output the 64-bit total for each sequence.

**中文詳細描述：**

每組輸入是一個數列，要計算透過相鄰元素交換完成排序所需的最少交換次數。此數量等於逆序對總數，在合併排序合併左右半部時累加跨區逆序對，最後輸出可能很大的計數。

<a id="uva-10812_beat-the-spread"></a>
### UVa 10812 — Beat the Spread!／破解分差

- 原始碼：[10812_beat-the-spread.c](10812_beat-the-spread.c)
- 演算法：聯立方程、奇偶判斷（Math）

**English description:**

Each test case gives the sum `s` and absolute difference `d` of two non-negative integer scores. Recover the larger and smaller scores and output them, or output `impossible` when no valid integer pair exists.

**中文詳細描述：**

每組輸入給兩個非負整數比分的總和 `s` 與差 `d`。解聯立式得到較大值 `(s+d)/2` 與較小值 `(s-d)/2`；若 `s<d` 或奇偶性使結果不是整數，則輸出 `impossible`，否則輸出兩個比分。

<a id="uva-10812_beat-the-spread-pr"></a>

### UVa 10812 — Beat the Spread!／二元一次聯立得分方程

- 原始碼：[10812_beat-the-spread-pr.c](10812_beat-the-spread-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Given sum s and difference d of two team scores, find original scores or determine impossible.

**中文詳細描述：** 給定兩隊得分之和 s 與差 d，求兩隊的原始得分 (若無整數非負解則判定不可能)。

**English approach:** x = (s + d) / 2, y = (s - d) / 2. Valid iff s >= d, (s + d) % 2 == 0, and y >= 0.

**中文解題思路：** 由 x + y = s 與 x - y = d 解得 x = (s+d)/2, y = (s-d)/2。須滿足 s >= d 且 s+d 為偶數。 ==========================================================================


<a id="uva-10813_traditional-bingo"></a>

### UVa 10813 — Traditional BINGO／傳統賓果遊戲模擬

- 原始碼：[10813_traditional-bingo.c](10813_traditional-bingo.c)
- 難度：Easy
- 演算法：simulation, grid

**English description:** Simulate calling 75 balls on a 5x5 Bingo card (center is free). Determine after how many calls a full line is completed.

**中文詳細描述：** 模擬 5x5 賓果卡（中心為已標記的免費格），依搖號序列叫號，求在第幾次叫號時最先連成一條線（行、列或對角線）。

**English approach:** Mark called numbers on 5x5 board. Check 5 rows, 5 columns, and 2 diagonals after each call.

**中文解題思路：** 維護 5x5 標記盤面，每叫一個號碼將其標記，隨即檢查 5 行、5 列與 2 條對角線是否達成 5 連線，返回叫號次數。 ==========================================================================


<a id="uva-10814_simplifying-fractions"></a>

### UVa 10814 — Simplifying Fractions／大數分數約分 (大數GCD)

- 原始碼：[10814_simplifying-fractions.c](10814_simplifying-fractions.c)
- 難度：Easy
- 演算法：math, big-integer, gcd

**English description:** Simplify a fraction P / Q with large integer numerator and denominator to lowest terms.

**中文詳細描述：** 將大整數分子 P 與大整數分母 Q 組成的分數約分為最簡分數。

**English approach:** Compute GCD(P, Q) using Euclidean algorithm for big integers. Divide P and Q by GCD.

**中文解題思路：** 使用高精度輾轉相除法求大數 GCD(P, Q)，並將分子分母同時除以該最大公因數。 ==========================================================================


<a id="uva-10815_andys-first-dictionary"></a>
### UVa 10815 — Andy's First Dictionary／安迪的第一本字典

- 原始碼：[10815_andys-first-dictionary.c](10815_andys-first-dictionary.c)
- 演算法：字串切割、排序、去重（String, Sorting）

**English description:**

Read arbitrary text, treating every maximal run of letters as a word. Convert words to lowercase, remove duplicates, sort them lexicographically, and output one distinct word per line.

**中文詳細描述：**

輸入是多行任意文字，所有連續英文字母構成一個單字，其他字元都視為分隔符。將單字轉成小寫、去除重複並按字典順序排列，最後每行輸出一個不同的單字。

<a id="uva-10815_andys-first-dictionary-pr"></a>

### UVa 10815 — Andy's First Dictionary／安迪的第一本字典 (單詞萃取與字母排序去重)

- 原始碼：[10815_andys-first-dictionary-pr.c](10815_andys-first-dictionary-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, sorting

**English description:** Extract all unique words from text, convert to lowercase, and print in alphabetical order.

**中文詳細描述：** 從文字中萃取所有單詞，轉換為小寫並去除重複，按字典序由小到大輸出。

**English approach:** Replace non-alphabetic chars with spaces, split tokens, convert to lowercase, sort and remove duplicates.

**中文解題思路：** 以 isalpha 將非字母替換為空格，分割各單詞轉為小寫，排序並去除重複項輸出。 ==========================================================================


<a id="uva-10819_trouble-of-13-dots"></a>

### UVa 10819 — Trouble of 13-Dots／購物滿額回饋背包動態規劃

- 原始碼：[10819_trouble-of-13-dots.c](10819_trouble-of-13-dots.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Buy items to maximize total favour within budget M. If total spending exceeds 2000, budget increases by a 200 credit-card bonus.

**中文詳細描述：** 在預算上限 M 內選購物品使喜愛度總和最大化；若總消費額超過 2000 元，則可額外享有 200 元的信用卡額度回饋。

**English approach:** 0/1 Knapsack with effective budget up to M + 200. Check validity: spending <= M, OR (spending > 2000 and spending <= M + 200).

**中文解題思路：** 0/1 背包動態規劃：將背包容量開至 M + 200，最後檢驗合法性 (花費 <= M 或 花費在 (2000, M+200] 區間內)，求喜愛度最大值。 ==========================================================================


<a id="uva-10820_send-a-table"></a>

### UVa 10820 — Send a Table／傳送乘法表 (歐拉函數前綴和)

- 原始碼：[10820_send-a-table.c](10820_send-a-table.c)
- 難度：Easy
- 演算法：math, number-theory, euler-totient

**English description:** Count the number of pairs (x, y) with 1 <= x, y <= N such that gcd(x, y) = 1.

**中文詳細描述：** 求滿足 1 <= x, y <= N 且 gcd(x, y) = 1 的互質數對 (x, y) 總數。

**English approach:** Count = 1 + 2 * sum_{i=2}^N phi(i) where phi is Euler's totient function.

**中文解題思路：** 互質對總數由尤拉函數給出：除了 (1,1) 外對稱分佈，公式為 1 + 2 * sum_{i=2}^N phi(i)。 ==========================================================================


<a id="uva-10827_maximum-sum-on-a-torus"></a>

### UVa 10827 — Maximum sum on a torus／環面上的最大子矩陣和

- 原始碼：[10827_maximum-sum-on-a-torus.c](10827_maximum-sum-on-a-torus.c)
- 難度：Medium
- 演算法：dp, maximum-submatrix

**English description:** Find the maximum submatrix sum on an N x N torus (wrapping both horizontally and vertically).

**中文詳細描述：** 在一個 N x N 的環面上（水平與垂直方向均循環相連），尋找最大子矩陣和。

**English approach:** Duplicate the torus to 2N x 2N. Compute 2D prefix sums and find max sum of subgrid of size at most N x N.

**中文解題思路：** 將環面擴展為 2N x 2N 網格，計算二維前綴和，枚舉高寬各不超過 N 的子矩陣最大和。 ==========================================================================


<a id="uva-10842_traffic-flow"></a>

### UVa 10842 — Traffic Flow／交通流量 (最大生成樹瓶頸邊)

- 原始碼：[10842_traffic-flow.c](10842_traffic-flow.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Find maximum minimum capacity of a subgraph connecting all n intersections (Maximum Spanning Tree minimum edge weight).

**中文詳細描述：** 求連接所有 n 個交叉路口使得全圖連通的子圖中，最小道路容量的最大值（即最大生成樹的最輕邊權重）。

**English approach:** Sort edges descending by capacity. Run Kruskal's algorithm until all n nodes are connected in a single component. The last added edge weight is the answer.

**中文解題思路：** 將邊依容量降序排序，使用 Kruskal 演算法構建最大生成樹，最後加入樹中的邊權即為瓶頸最大值。 ==========================================================================


<a id="uva-10849_move-the-bishop"></a>

### UVa 10849 — Move the bishop／移動主教

- 原始碼：[10849_move-the-bishop.c](10849_move-the-bishop.c)
- 難度：Easy
- 演算法：math, chess-simulation

**English description:** Find the minimum number of moves for a bishop on an N x N chessboard to move from (r1, c1) to (r2, c2).

**中文詳細描述：** 在 N x N 棋盤上，求主教從 (r1, c1) 移動到 (r2, c2) 的最少步數（0、1、2 或不可達）。

**English approach:** If (r1,c1)==(r2,c2) -> 0. If (r1+c1)%2 != (r2+c2)%2 -> impossible (no move). If on same diagonal |r1-r2| == |c1-c2| -> 1. Otherwise -> 2.

**中文解題思路：** 若同格為 0 步；若兩格奇偶性不同（顏色不同）則不可達；若在同一對角線上為 1 步；否則最多 2 步必可轉向抵達。 ==========================================================================


<a id="uva-10852_less-prime"></a>

### UVa 10852 — Less Prime／稍小質數

- 原始碼：[10852_less-prime.c](10852_less-prime.c)
- 難度：Easy
- 演算法：math, number-theory, prime

**English description:** Given N, find a prime p <= N such that N - p * p_mult is maximized (where p_mult is the largest multiplier such that p * p_mult <= N).

**中文詳細描述：** 給定 N，尋找質數 p <= N 使得 N - p * k 達到最大（其中 k 為滿足 p * k <= N 的最大整數）。

**English approach:** Taking k = 1 gives remainder N - p. The remainder is maximized when p is the smallest prime strictly greater than N / 2.

**中文解題思路：** 當 k = 1 時餘數為 N - p。使餘數最大的最佳質數 p 即為嚴格大於 N / 2 的最小質數（此時 k=1 且 p 越小餘數越大）。 ==========================================================================


<a id="uva-10855_rotated-square"></a>

### UVa 10855 — Rotated square／旋轉子方陣在母方陣中匹配次數

- 原始碼：[10855_rotated-square.c](10855_rotated-square.c)
- 難度：UVa Star 2
- 演算法：simulation, 2d-grid

**English description:** Count how many times a small square of size n appears in a big square of size N for rotations 0, 90, 180, and 270 degrees.

**中文詳細描述：** 給定 N x N 的大字元方陣與 n x n 的小子方陣，分別計算小子方陣旋轉 0°、90°、180° 與 270° 後在大方陣中出現的總次數。

**English approach:** Simulate 2D grid submatrix matching. Rotate small square 90 degrees 3 times, counting exact matches at each rotation.

**中文解題思路：** 二維子矩陣比對：滑動窗口枚舉所有可能左上角，旋轉小矩陣四次並分別統計比對成功次數。 ==========================================================================


<a id="uva-10878_decode-the-tape"></a>
### UVa 10878 — Decode the tape／解碼紙帶

- 原始碼：[10878_decode-the-tape.c](10878_decode-the-tape.c)
- 演算法：字元解析、二進位解碼（String, Bit Manipulation）

**English description:**

The input depicts punched paper tape between border lines. For each data row, interpret `o` positions as binary one bits and blank positions as zero bits, decode the corresponding ASCII character, and output the recovered message.

**中文詳細描述：**

輸入以文字畫出打孔紙帶，首尾邊界行不承載資料。對每一條資料列，把指定欄位中的 `o` 當作二進位 1、空白當作 0，組成 ASCII 碼後轉回字元，依序輸出完整訊息。

<a id="uva-10878_decode-the-tape-pr"></a>

### UVa 10878 — Decode the tape／解碼穿孔紙帶 (Punched Tape ASCII 解碼)

- 原始碼：[10878_decode-the-tape-pr.c](10878_decode-the-tape-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：bit-manipulation, string, simulation

**English description:** Decode 7-bit ASCII characters from punched tape visual rows ('o' is 1, space is 0).

**中文詳細描述：** 解析紙帶孔洞圖形還原 ASCII 訊息：字元 'o' 代表二進位 1，空白代表 0，點 '.' 為定位孔忽視。

**English approach:** Read row between '|' bars, convert 'o' positions to bitmask byte, print corresponding char.

**中文解題思路：** 讀取每行紙帶，將孔洞 'o' 依位元加權累加為一個位元組字元，直接輸出 ASCII 字元。 ==========================================================================


<a id="uva-10879_code-refactoring"></a>

### UVa 10879 — Code Refactoring／程式重構分解 (尋找兩組相異因數分解)

- 原始碼：[10879_code-refactoring.c](10879_code-refactoring.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Given integer N with at least 16 divisors, find two distinct factorizations: N = A * B = C * D.

**中文詳細描述：** 給定含有至少 16 個因數的整數 N，尋找兩組相異的因數乘積對：N = A * B = C * D。

**English approach:** Trial division from 2 upward: find first factor A, then next factor C. Output N = A * (N/A) = C * (N/C).

**中文解題思路：** 從 2 開始試除找出前兩個能整除 N 的因數 A 與 C，直接輸出兩組相異因數乘積。 ==========================================================================


<a id="uva-10880_colin-and-ryan"></a>

### UVa 10880 — Colin and Ryan／柯林與萊恩 (因數分解除數條件)

- 原始碼：[10880_colin-and-ryan.c](10880_colin-and-ryan.c)
- 難度：Easy
- 演算法：math, number-theory, divisors

**English description:** Given total cookies C and remaining cookies R, find all possible guest counts Q such that C % Q = R (so Q > R and Q divides C - R).

**中文詳細描述：** 已知總餅乾數 C 與剩餘餅乾數 R，求所有可能的賓客人數 Q（滿足 C % Q = R，即 Q > R 且 Q 整除 C - R）。

**English approach:** If C == R, Q = 0 is unique solution. Otherwise, find all divisors Q of (C - R) such that Q > R, and sort in ascending order.

**中文解題思路：** 若 C == R，則客人數為 0；否則在 (C - R) 的所有因數中挑選嚴格大於 R 的數值並升序輸出。 ==========================================================================


<a id="uva-10881_piotrs-ants"></a>

### UVa 10881 — Piotr's Ants／皮奧特的螞蟻碰撞模擬

- 原始碼：[10881_piotrs-ants.c](10881_piotrs-ants.c)
- 難度：Medium
- 演算法：simulation, sorting, brainteaser

**English description:** Ants move at 1 cm/s on a pole of length L. When two collide, they reverse directions. Find their positions after T seconds.

**中文詳細描述：** 螞蟻在長度為 L 的木棍上以 1 cm/s 等速移動，碰撞時各自調頭，求 T 秒後每隻螞蟻的位置與狀態。

**English approach:** Ignore collisions: ants pass through each other to reach final positions. Relative order of ants along the pole never changes, so match initial sorted ants to final sorted coordinates.

**中文解題思路：** 視碰撞為互相穿透，每隻螞蟻獨立計算 T 秒後位置；由於螞蟻相對左右順序守恆，將初始位置排序與最終位置排序一對一匹配即可。 ==========================================================================


<a id="uva-10891_game-of-sum"></a>

### UVa 10891 — Game of Sum／求和博弈

- 原始碼：[10891_game-of-sum.c](10891_game-of-sum.c)
- 難度：Medium
- 演算法：game-theory, interval-dp

**English description:** Two players take turns removing 1 to remaining elements from either end of an array. Find max score difference Player 1 can guarantee.

**中文詳細描述：** 兩人輪流從陣列任一端取走連續 1 個或多個數字，求先手能保證獲得的最大分數差值。

**English approach:** Interval DP: dp[i][j] = sum(i..j) - min(0, min_{k} dp[i+k][j], min_{k} dp[i][j-k]).

**中文解題思路：** 區間 DP：dp[i][j] = sum(i..j) - min(0, min(dp[k][j]), min(dp[i][k]))，雙方皆採取最優策略爭奪最大分差。 ==========================================================================


<a id="uva-10892_lcm-cardinality"></a>

### UVa 10892 — LCM Cardinality／最小公倍數基數

- 原始碼：[10892_lcm-cardinality.c](10892_lcm-cardinality.c)
- 難度：Medium
- 演算法：math, number-theory, gcd, lcm

**English description:** Count the number of pairs (a, b) such that 1 <= a <= b and lcm(a, b) = N.

**中文詳細描述：** 計算滿足 1 <= a <= b 且 lcm(a, b) = N 的整數對 (a, b) 的數量。

**English approach:** Both a and b must be divisors of N. Find all divisors of N, then test each pair (d1, d2) if lcm(d1, d2) == N.

**中文解題思路：** a 與 b 必為 N 的因數。先找出 N 的所有因數，雙重迴圈枚舉因數對檢查 lcm(d1, d2) 是否等於 N。 ==========================================================================


<a id="uva-10895_matrix-transpose"></a>

### UVa 10895 — Matrix Transpose／稀疏矩陣轉置

- 原始碼：[10895_matrix-transpose.c](10895_matrix-transpose.c)
- 難度：Easy
- 演算法：data-structures, sparse-matrix

**English description:** Given a sparse matrix in adjacency-list representation, output its transpose in the same format.

**中文詳細描述：** 給定以稀疏格式表示的矩陣，輸出其轉置矩陣。

**English approach:** Collect all non-zero entries (r, c, val), transpose to (c, r, val), group by new row, sort by column, and print.

**中文解題思路：** 讀取非零元素 (r, c, val) 轉置為 (c, r, val)，以轉置後的列為鍵值分組排序後輸出。 ==========================================================================
