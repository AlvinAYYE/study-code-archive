# UVa Volume 011 題目索引

本卷收錄 9 份 C 解答，涵蓋 9 個 UVa 題號，以下依題號排序。

<a id="uva-1103_ancient-messages"></a>

### UVa 1103 — Ancient Messages／古代象形文字識別 (拓撲孔洞計數)

- 原始碼：[1103_ancient-messages.c](1103_ancient-messages.c)
- 難度：Medium
- 演算法：flood-fill, graph, connected-components

**English description:** Recognize Egyptian hieroglyphs in a binary bitmap by counting the number of internal white holes in each connected black glyph.

**中文詳細描述：** 辨識二維點陣圖中的古埃及象形文字：透過統計每個黑色連通象形文字內部所包含的白色「孔洞」數量來唯一識別文字。

**English approach:** Flood fill outer white background from border with special value. Then for each black glyph, flood fill internal white regions and count.

**中文解題思路：** 先從邊界對外圍白色背景進行洪水填充標記；接著遍歷黑色文字連通塊，統計其所包圍的封閉白色連通塊個數（0=W, 1=A, 2=K, 3=J, 4=S, 5=D）。 ==========================================================================


<a id="uva-1112_mice-and-maze"></a>

### UVa 1112 — Mice and Maze／迷宮老鼠反向最短路徑 Dijkstra

- 原始碼：[1112_mice-and-maze.c](1112_mice-and-maze.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, shortest-path

**English description:** Find how many mice starting at different maze cells can reach the designated exit cell within countdown timer T.

**中文詳細描述：** 在有向迷宮中，統計有多少隻老鼠能在倒數計時 T 內自各自的起點抵達指定出口 (反向邊建圖 Dijkstra 最短路)。

**English approach:** Reverse all directed edges and run single-source Dijkstra from the exit node. Count nodes with shortest distance <= T.

**中文解題思路：** 將所有有向邊反向，以出口為單源起點執行 Dijkstra 最短路徑演算法，統計最短距離小於等於 T 的節點總數。 ==========================================================================


<a id="uva-1121_subsequence"></a>

### UVa 1121 — Subsequence／連續子數組最小長度

- 原始碼：[1121_subsequence.c](1121_subsequence.c)
- 難度：Medium
- 演算法：two-pointers, sliding-window

**English description:** Find the minimal length of a contiguous subarray of positive integers whose sum is greater than or equal to S.

**中文詳細描述：** 求和不小於 S 的連續正整數子數組的最短長度。

**English approach:** Two pointers (sliding window): expand right pointer to increase sum; shrink left pointer while sum >= S.

**中文解題思路：** 雙指針滑動窗口：右指針向右擴展累計和，當總和 >= S 時嘗試向右收縮左指針以尋找最小窗口長度。 ==========================================================================


<a id="uva-1124_celebrity-jeopardy"></a>

### UVa 1124 — Celebrity jeopardy／原樣字元流回顯輸出

- 原始碼：[1124_celebrity-jeopardy.c](1124_celebrity-jeopardy.c)
- 難度：UVa Star 1
- 演算法：simulation, basic-io

**English description:** Echo all input lines verbatim to stdout.

**中文詳細描述：** 讀取標準輸入的每一行字元，完整原樣回顯輸出至標準輸出。

**English approach:** Direct line buffering with gets/fgets or getchar loop echoing until EOF.

**中文解題思路：** 使用 fgets 逐行讀入並使用 fputs 原樣印出，直到標準輸入流結束。 ==========================================================================


<a id="uva-1152_four_values_whose_sum_is_0"></a>

### UVa 1152 — 4 Values whose Sum is 0／四數之和為零的元組數

- 原始碼：[1152_four_values_whose_sum_is_0.c](1152_four_values_whose_sum_is_0.c)
- 難度：Medium
- 演算法：hash-table, two-pointers, binary-search

**English description:** Count quadruples (a, b, c, d) chosen from four lists of integers such that a + b + c + d = 0.

**中文詳細描述：** 給定四個整數列表 A, B, C, D，求有多少個四元組 (a, b, c, d) 滿足 a + b + c + d = 0。

**English approach:** Compute all sums of A[i] + B[j], sort the array, and binary search count of -(C[k] + D[l]).

**中文解題思路：** 雙向枚舉：計算 A 與 B 的所有兩兩和並排序，遍歷 C 與 D 的和並在排序陣列中二分搜尋 -(c+d) 的出現次數。 ==========================================================================


<a id="uva-1174_ip_tv"></a>

### UVa 1174 — IP-TV／IP 電視網路最小生成樹

- 原始碼：[1174_ip_tv.c](1174_ip_tv.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Connect all cities in an IP-TV network with the minimum total cost of optical fiber cables.

**中文詳細描述：** 給定城市之間的連接成本，求將所有城市連接起來的最小光纖電纜總成本（最小生成樹）。

**English approach:** Apply Kruskal's algorithm with Disjoint-Set Union to find the Minimum Spanning Tree weight.

**中文解題思路：** 使用 Kruskal 演算法搭配並查集計算圖的最小生成樹權重總和。 ==========================================================================


<a id="uva-1185_big-number"></a>

### UVa 1185 — Big Number／大數階乘位數計算 (Kamenetsky公式/對數)

- 原始碼：[1185_big-number.c](1185_big-number.c)
- 難度：Easy
- 演算法：math, stirling-approximation, logarithms

**English description:** Find the number of decimal digits in N! for N up to 10,000,000.

**中文詳細描述：** 計算 N! 在十進位表示下的位數長度（N 最大達 10,000,000）。

**English approach:** Use Kamenetsky's formula: digits = floor(log10(sqrt(2*pi*n)) + n*log10(n/e)) + 1, or precompute sum of log10.

**中文解題思路：** 利用史特靈/卡梅涅茨基近似公式：位數 = floor(log10(sqrt(2*pi*n)) + n*log10(n/e)) + 1（n <= 3 時直接查表）。 ==========================================================================


<a id="uva-1193_radar-installation"></a>

### UVa 1193 — Radar Installation／雷達安裝 (區間選點貪心法)

- 原始碼：[1193_radar-installation.c](1193_radar-installation.c)
- 難度：Medium
- 演算法：greedy, geometry, interval-scheduling

**English description:** Given islands in the ocean and radar range d on coastline (x-axis), find minimum number of radar stations to cover all islands.

**中文詳細描述：** 海岸線為 x 軸，海中有若干島嶼點，雷達半徑為 d，求最少需在海岸線上設立幾座雷達以覆蓋所有島嶼。

**English approach:** Convert each island (x, y) into a valid x-interval [x - dx, x + dx] on coastline where dx = sqrt(d^2 - y^2). Sort by right endpoint, greedy interval point cover.

**中文解題思路：** 利用 dx = sqrt(d^2 - y^2) 將各島嶼轉化為海岸線上的有效雷達放置區間，依區間右端點升序排序，貪心在右端點設雷達。 ==========================================================================


<a id="uva-1197_the-suspects"></a>

### UVa 1197 — The Suspects／嫌疑犯 (並查集連通塊大小)

- 原始碼：[1197_the-suspects.c](1197_the-suspects.c)
- 難度：Easy
- 演算法：disjoint-set-union

**English description:** Find the number of suspects infected with SARS if person 0 is infected, given student club memberships.

**中文詳細描述：** 0 號學生確診 SARS，若同社團成員互相接觸，求受感染的潛在嫌疑犯總人數。

**English approach:** Union-Find tracking component sizes. Union members of each club together. Return size of component containing 0.

**中文解題思路：** 使用維護集合大小的並查集將同社團成員合併，查詢 0 號所在連通塊的大小。 ==========================================================================
