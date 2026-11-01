# UVa Volume 001

本卷收錄 102 份 C 解答，涵蓋 96 個 UVa 題號，以下依題號排序。

<a id="uva-100_the-3n-plus-1-problem"></a>

### UVa 100 — The 3n + 1 Problem／3n + 1 問題（考拉茲猜想）

- 原始碼：[100_the-3n-plus-1-problem.c](100_the-3n-plus-1-problem.c)
- 演算法：逐項模擬、數學（simulation, Collatz sequence）

**English description:** Given two integers `i` and `j`, examine every integer in the inclusive interval between them. Repeatedly replace an even value by half of itself and an odd value by `3n + 1`, count the terms through 1, and output the original pair followed by the largest cycle length found.

**中文詳細描述：** 每行輸入兩個整數 `i`、`j`；對兩者之間（含端點）的每個整數產生考拉茲數列：偶數除以 2，奇數變成 `3n + 1`，直到 1 為止。計算各數列包含起點與 1 的項數，輸出原始順序的 `i j`，以及區間內最大的循環長度。

<a id="uva-101_the-blocks-problem"></a>

### UVa 101 — The Blocks Problem／積木問題

- 原始碼：[101_the-blocks-problem.c](101_the-blocks-problem.c)
- 演算法：資料結構模擬（simulation, stacks）

**English description:** Start with block `i` alone at position `i`. Process `move` or `pile` commands combined with `onto` or `over`: blocks above selected blocks may be returned home, and either one block or an entire pile is transferred. Ignore commands involving blocks already in the same stack, stop at `quit`, and print every final stack.

**中文詳細描述：** 輸入積木數量後，每塊編號 `i` 的積木一開始單獨放在第 `i` 疊。依序執行 `move/pile` 與 `onto/over` 組成的四種指令；其中可能先把目標上方積木送回原位，再搬動單塊或整段積木。兩塊已在同一疊時忽略該指令，讀到 `quit` 後輸出每個位置的最終堆疊。

<a id="uva-101_the-blocks-problem-pr"></a>

### UVa 101 — The Blocks Problem／積木問題

- 原始碼：[101_the-blocks-problem-pr.c](101_the-blocks-problem-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：simulation, data-structures

**English description:** Simulate robotic arm moving blocks with move/onto, move/over, pile/onto, pile/over.

**中文詳細描述：** 模擬機器手臂堆疊積木（move/pile 與 onto/over 四種組合指令）。

**English approach:** 2D array representation of block stacks. Position lookup array for O(1) locate.

**中文解題思路：** 二維陣列模擬每疊積木，以 pos 陣列記錄每個積木所在柱與高度。 ==========================================================================


<a id="uva-102_ecological-bin-packing"></a>

### UVa 102 — Ecological Bin Packing／生態回收桶

- 原始碼：[102_ecological-bin-packing.c](102_ecological-bin-packing.c)
- 演算法：全排列枚舉、貪婪比較（brute force, permutation）

**English description:** Each input case gives the counts of brown, green, and clear bottles in three bins. Assign one distinct color to each bin and move all bottles of the other colors out. Output the three-letter assignment requiring the fewest moves, choosing the lexicographically earliest assignment on a tie, followed by the move count.

**中文詳細描述：** 每筆輸入給出三個箱子中棕色、綠色、透明瓶子的數量。要讓每個箱子只保留一種顏色且三色各占一箱，計算六種顏色排列所需搬走的瓶子數。輸出搬移次數最少的三字母配置與次數；若同樣少，取字典序最前的配置。

<a id="uva-103_stacking-boxes"></a>

### UVa 103 — Stacking Boxes／多維箱子巢狀堆疊

- 原始碼：[103_stacking-boxes.c](103_stacking-boxes.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, dag, sorting, lis

**English description:** Given k n-dimensional boxes, find the longest sequence of nested boxes.

**中文詳細描述：** 給定 k 個 n 維箱子，判定維度排序後能否完全嵌套，求最長嵌套序列 (DAG 最長路 / LIS)。

**English approach:** Sort dimensions of each box. Box A nests in B if each dim of A < B. Build DAG and find longest path with DP.

**中文解題思路：** 每個箱子的各維度先由小到大排序。若 A 的各維度皆小於 B 則可嵌套。建 DAG 用 DP 求最長路徑。 ==========================================================================


<a id="uva-104_arbitrage"></a>

### UVa 104 — Arbitrage／套匯獲利鏈

- 原始碼：[104_arbitrage.c](104_arbitrage.c)
- 難度：UVa Star 3
- 演算法：graph, floyd-warshall, dynamic-programming

**English description:** Find minimum length sequence of currency exchanges that yields > 1.01 profit.

**中文詳細描述：** 尋找貨幣兌換的最短交易鏈，使兌換回到原貨幣後獲利超過 1% (乘積 > 1.01)。

**English approach:** Extended Floyd-Warshall DP: dist[step][i][j] stores max profit from i to j in 'step' exchanges.

**中文解題思路：** 擴展 Floyd-Warshall：記錄在 step 次兌換下從貨幣 i 到 j 的最大匯率乘積，並記錄路徑。 ==========================================================================


<a id="uva-105_the-skyline-problem"></a>

### UVa 105 — The Skyline Problem／天際線輪廓問題

- 原始碼：[105_the-skyline-problem.c](105_the-skyline-problem.c)
- 演算法：座標高度掃描（simulation, sweep by coordinates）

**English description:** Buildings are supplied as triples `(L, H, R)` describing their left coordinate, height, and right coordinate. Combine all buildings and output the critical x-coordinates where the visible maximum height changes, alternating each coordinate with its new skyline height and ending when the height returns to zero.

**中文詳細描述：** 輸入若干棟以左界 `L`、高度 `H`、右界 `R` 表示的建築。對每個水平座標取所有覆蓋建築的最大高度，找出整體輪廓高度發生變化的位置。輸出一連串「座標、新高度」關鍵點，最後包含天際線降回 0 的位置。

<a id="uva-105_the-skyline-problem-pr"></a>

### UVa 105 — The Skyline Problem／天際線輪廓問題

- 原始碼：[105_the-skyline-problem-pr.c](105_the-skyline-problem-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, array

**English description:** Given buildings (L, H, R), output the contour skyline.

**中文詳細描述：** 給定每棟建築物的左右邊界與高度，輸出整體天際線高度變化轉折點。

**English approach:** Height array up to coordinate 10000. Mark max height at each x.

**中文解題思路：** 一維高度陣列记录各 x 座標的最大高度，線性掃描找出高度改變的關鍵點。 ==========================================================================


<a id="uva-106_fermat-vs-pythagoras"></a>

### UVa 106 — Fermat vs. Pythagoras／費馬對畢氏 (互質畢氏三元數)

- 原始碼：[106_fermat-vs-pythagoras.c](106_fermat-vs-pythagoras.c)
- 難度：UVa Star 2
- 演算法：math, number-theory, pythagorean-triples

**English description:** Count primitive Pythagorean triples with z <= N, and count numbers <= N not in any triple.

**中文詳細描述：** 計算斜邊 z <= N 的本原畢氏三元組數量，以及在 1..N 中未包含在任何畢氏三元組中的整數數量。

**English approach:** Generate triples using Euclid formula: x = m^2 - n^2, y = 2mn, z = m^2 + n^2 with gcd(m, n) = 1.

**中文解題思路：** 利用歐幾里得公式枚舉 m > n，gcd(m, n) == 1 且奇偶互異，統計本原組並標記倍數以計數未使用的數。 ==========================================================================


<a id="uva-107_the-cat-in-the-hat"></a>

### UVa 107 — The Cat in the Hat／戴帽子的貓

- 原始碼：[107_the-cat-in-the-hat.c](107_the-cat-in-the-hat.c)
- 難度：UVa Star 2
- 演算法：math, binary-search, logarithms

**English description:** Initial cat height H, final 1-height cats W. Each cat has N cats of height H/(N+1). Find non-working cats and total height.

**中文詳細描述：** 初始貓高 H，最後高度為 1 的貓有 W 隻。每隻貓帽子裡有 N 隻高 H/(N+1) 的小貓。求不工作的貓數量與總高度。

**English approach:** Solve (N+1)^k = H and N^k = W for integers N and k. Then non-working cats sum = (N^k - 1)/(N - 1).

**中文解題思路：** 求解方程 (N+1)^k = H 且 N^k = W。特判 W=1 時 N=1, k=0。等比級數求不工作貓與總高度。 ==========================================================================


<a id="uva-108_maximum-sum"></a>

### UVa 108 — Maximum Sum／最大二維子矩陣和

- 原始碼：[108_maximum-sum.c](108_maximum-sum.c)
- 演算法：動態規劃、二維 Kadane（dynamic programming, 2D Kadane）

**English description:** Given an `N × N` integer matrix, choose a nonempty axis-aligned rectangular submatrix whose entries have the greatest possible sum. Output that maximum sum, including the correct negative value when every matrix entry is negative.

**中文詳細描述：** 輸入一個 `N × N` 整數矩陣，從中選擇非空且邊界平行於矩陣的矩形區域，使區域內元素總和最大。程式枚舉上下邊界、將各欄壓成一維後套用最大子陣列演算法，最後輸出最大總和；全為負數時也要保留正確的負值答案。

<a id="uva-109_scud-busters"></a>

### UVa 109 — SCUD Busters／飛彈防禦多邊形凸包與面積計算

- 原始碼：[109_scud-busters.c](109_scud-busters.c)
- 難度：UVa Star 2
- 演算法：geometry, convex-hull

**English description:** Given kingdom missile defense sites, find convex hull polygons of each kingdom. If a missile hits inside a kingdom, its power is destroyed. Calculate total area destroyed.

**中文詳細描述：** 給定各王國的飛彈防禦基地座標，求各王國的凸包多邊形。若敵方飛彈擊中某王國凸包內部，該王國防禦網失效，計算所有失效王國之凸包總面積。

**English approach:** Compute 2D convex hull using Graham scan or monotone chain, then point-in-convex-polygon ray-casting / cross-product test, and polygon area using shoelace formula.

**中文解題思路：** 利用單調鏈或 Graham 掃描法構建各點集凸包，利用射線法或叉積檢驗導彈點是否落在凸包內部；若命中則以鞋帶公式加總該凸包面積。 ==========================================================================


<a id="uva-110_meta-loopless-sorts"></a>

### UVa 110 — Meta-Loopless Sorts／無迴圈排序程式碼生成器

- 原始碼：[110_meta-loopless-sorts.c](110_meta-loopless-sorts.c)
- 難度：UVa Star 2
- 演算法：backtracking, recursion, code-generation

**English description:** Generate a Pascal program with nested if-else to sort n variables without loops.

**中文詳細描述：** 以遞迴回溯生成包含完整 if-else 決策樹的 Pascal 無迴圈排序程式碼。

**English approach:** Recursively insert new variable into all possible positions of the currently sorted list.

**中文解題思路：** 遞迴將第 k 個變數插入前 k-1 個已排序變數的所有可能區間，構造出決策分支樹。 ==========================================================================


<a id="uva-111_history-grading"></a>

### UVa 111 — History Grading／歷史事件排序評分

- 原始碼：[111_history-grading.c](111_history-grading.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lcs, lis

**English description:** Given correct chronological rank of events and students' rankings, find length of longest valid relative order.

**中文詳細描述：** 給定歷史事件的正確年代順序與學生的排序回答，計算學生保留的相對年代順序的最長長度 (LIS / LCS)。

**English approach:** Convert student answer to actual event order sequence, then compute LIS against the standard order.

**中文解題思路：** 將輸入名次轉換為時間序列表，接著計算標準序列與學生序列的最長共同子序列 (LCS)。 ==========================================================================


<a id="uva-112_tree-summing"></a>

### UVa 112 — Tree Summing／二元樹路徑和

- 原始碼：[112_tree-summing.c](112_tree-summing.c)
- 難度：UVa Star 2
- 演算法：recursion, parsing, tree

**English description:** Given target sum and S-expression binary tree, determine if there exists root-to-leaf path with this sum.

**中文詳細描述：** 解析括號 S-expression 表達的二元樹，判定是否存在一條從根結點到葉節點的路徑和等於目標值。

**English approach:** Recursive descent parsing. If node is leaf (both subtrees empty), check current_sum == target.

**中文解題思路：** 遞迴下降解析括號樹結構。當遞迴到左右子樹皆為空的葉節點時，檢查累積路徑和是否恰等於目標值。 ==========================================================================


<a id="uva-113_power-of-cryptography"></a>

### UVa 113 — Power of Cryptography／密碼學的威力

- 原始碼：[113_power-of-cryptography.c](113_power-of-cryptography.c)
- 演算法：數學、浮點開根取整（math, nth root）

**English description:** For each pair `n` and `p`, the input guarantees that `p = k^n` for an integer `k`. Recover and output `k`, even though the decimal representation of `p` may be very large.

**中文詳細描述：** 每筆輸入先給指數 `n`，再給一個很大的整數 `p`，並保證存在整數 `k` 使 `p = k^n`。題目要求反推出這個整數底數；實作以浮點數計算 `n` 次方根並四捨五入，逐筆輸出 `k`。

<a id="uva-114_simulation-wizardry"></a>

### UVa 114 — Simulation Wizardry／彈珠檯魔法模擬

- 原始碼：[114_simulation-wizardry.c](114_simulation-wizardry.c)
- 難度：UVa Star 2
- 演算法：simulation, 2d-grid

**English description:** Simulate pinball movement with bumpers, wall rebound, lifetime decay, and score points.

**中文詳細描述：** 模擬彈珠檯上彈珠碰到緩衝障礙物、牆壁反彈、方向右轉、壽命遞減與得分的物理規則。

**English approach:** Step-by-step 2D grid simulation following exact rebound and lifetime subtraction rules.

**中文解題思路：** 照題目規則每步更新位置：遇保險桿扣壽命、獲得分並右轉 90 度；遇邊界牆反彈扣壽命。 ==========================================================================


<a id="uva-115_climbing-trees"></a>

### UVa 115 — Climbing Trees／家譜樹血緣親屬關係判定

- 原始碼：[115_climbing-trees.c](115_climbing-trees.c)
- 難度：UVa Star 2
- 演算法：tree, dfs, lca

**English description:** Given parent-child relationships, determine the relationship between two individuals: child, parent, sibling, cousin with removal, etc.

**中文詳細描述：** 給定若干對父子/母子血緣關係，判斷任意兩人之間的親屬關係：如直系尊親屬/卑親屬、兄弟姊妹或具有代差的堂表親屬。

**English approach:** Model as directed forest. Find path to root for each query node; find lowest common ancestor (LCA) and compare tree depths to determine degree of cousinship and removal.

**中文解題思路：** 構建有向樹森林，由各節點向上遍歷至根尋找最近共同祖先 (LCA)，根據兩者與祖先之深度差距判定親等與代差關係。 ==========================================================================


<a id="uva-116_unidirectional-tsp"></a>

### UVa 116 — Unidirectional TSP／單向旅行商問題 (循環網格 DP)

- 原始碼：[116_unidirectional-tsp.c](116_unidirectional-tsp.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, grid, lexicographical

**English description:** Find path from column 1 to n in a cylindrical grid with minimum weight and lexicographically smallest row sequence.

**中文詳細描述：** 在上下相通的圓柱網格中，由左至右移動，求累加權重最小且字典序最小的列移動路徑。

**English approach:** Dynamic programming from right to left (col n-1 down to 0). Sort candidate next rows for lexicographical tie-breaking.

**中文解題思路：** 從最後一列反向向左動態規劃：dp[r][c] 代表從 (r,c) 走到終點的最小成本。遇到相同最小值時優先選列號小者。 ==========================================================================


<a id="uva-117_the-postal-worker-rings-once"></a>

### UVa 117 — The Postal Worker Rings Once／郵差總按一次鈴 (中國郵差問題)

- 原始碼：[117_the-postal-worker-rings-once.c](117_the-postal-worker-rings-once.c)
- 難度：UVa Star 2
- 演算法：graph, eulerian-path, floyd-warshall, shortest-path

**English description:** Find minimum distance to traverse all edges in connected undirected graph (Chinese Postman Problem).

**中文詳細描述：** 在連通無向圖中尋找遍歷所有邊至少一次的最短閉迴路 (中國郵差問題)。

**English approach:** If all vertex degrees are even, answer is sum of all edge weights. If two odd-degree vertices exist, add shortest path between them.

**中文解題思路：** 若所有頂點度數皆為偶數，答案即所有邊權重總和；若恰有兩個奇度頂點，答案為邊權重總和加上此兩點間的最短路徑。 ==========================================================================


<a id="uva-118_mutant-flatworld-explorers"></a>

### UVa 118 — Mutant Flatworld Explorers／異變的扁平世界探險家

- 原始碼：[118_mutant-flatworld-explorers.c](118_mutant-flatworld-explorers.c)
- 演算法：網格模擬、方向向量（simulation, grid）

**English description:** A rectangular world and a sequence of robots are given. Each robot starts at a coordinate and orientation, then follows left turns, right turns, and forward moves. A robot that steps beyond the border is lost and leaves a scent at its last valid position; later robots ignore a forward command that would fall from the same scented edge. Print each robot's final state and whether it was lost.

**中文詳細描述：** 先輸入矩形世界的右上邊界，接著逐一給定機器人的起點、朝向與由 `L`、`R`、`F` 組成的指令。機器人若向前走出邊界便在最後合法位置留下氣味並標為 `LOST`；之後其他機器人在同一位置、同一掉落方向會忽略該前進指令。輸出每台機器人的最終座標、方向及是否失蹤。

<a id="uva-118_mutant-flatworld-explorers-pr"></a>

### UVa 118 — Mutant Flatworld Explorers／異變的扁平世界探險家

- 原始碼：[118_mutant-flatworld-explorers-pr.c](118_mutant-flatworld-explorers-pr.c)
- 難度：UVa Star 1 / CPE 49 顆星必考題
- 解答版本：PR 同題替代實作
- 演算法：simulation, grid

**English description:** Simulate grid robot exploration with scents dropped on edge falls.

**中文詳細描述：** 模擬網格上的機器人前進與轉彎，若掉出邊界留下標記。

**English approach:** Direction vectors with scent matrix.

**中文解題思路：** 用 dx, dy 陣列控制 4 個方向移動，維護掉落標記防止重複掉落。 ==========================================================================


<a id="uva-119_greedy-gift-givers"></a>

### UVa 119 — Greedy Gift Givers／貪婪的送禮者

- 原始碼：[119_greedy-gift-givers.c](119_greedy-gift-givers.c)
- 演算法：字串查表、收支模擬（simulation, name lookup）

**English description:** A group of named friends exchanges gifts. For each giver, divide the stated amount equally among the listed recipients; any indivisible remainder stays with the giver. Output every person's net gain or loss in the same order in which the names were introduced.

**中文詳細描述：** 每組資料先給人數與依序出現的姓名，再描述每位送禮者準備的金額及收禮名單。金額以整數平均分給收禮者，不能整除的餘額由送禮者保留；沒有人可送時也不扣款。累計每人的收入減支出，最後按原姓名順序輸出淨收支。

<a id="uva-119_greedy-gift-givers-pr"></a>

### UVa 119 — Greedy Gift Givers／貪婪的送禮者

- 原始碼：[119_greedy-gift-givers-pr.c](119_greedy-gift-givers-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, string

**English description:** Track net gain/loss for friends giving and receiving gifts evenly.

**中文詳細描述：** 朋友間送禮金錢計算：送禮者將金額平分給受禮者，餘數自己保留，求各人的淨收支。

**English approach:** Hash table or linear lookup for names, maintain net balance.

**中文解題思路：** 字串姓名查表維護淨收支金額。 ==========================================================================


<a id="uva-120_stacks-of-flapjacks"></a>

### UVa 120 — Stacks of Flapjacks／煎餅堆排序

- 原始碼：[120_stacks-of-flapjacks.c](120_stacks-of-flapjacks.c)
- 演算法：煎餅排序、貪婪模擬（sorting, pancake sort）

**English description:** Each input line lists pancake diameters from the top of a stack to the bottom. A flip inserts a spatula at some depth and reverses all pancakes above it. Echo the original stack, then output a sequence of flip positions that sorts it with the largest pancake at the bottom, terminated by `0`.

**中文詳細描述：** 每行輸入一疊煎餅的直徑，順序由頂端到最底端。一次操作可選擇某個深度，將其上方整段煎餅反轉；程式反覆把尚未定位的最大煎餅先翻到頂端，再翻到目前底部。先原樣輸入該列，再輸出完成排序的翻轉位置序列，並以 `0` 結束。

<a id="uva-120_stacks-of-flapjacks-pr"></a>

### UVa 120 — Stacks of Flapjacks／煎餅堆排序

- 原始碼：[120_stacks-of-flapjacks-pr.c](120_stacks-of-flapjacks-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：sorting, simulation, greedy

**English description:** Sort pancake stack using spatula flips from any position to top.

**中文詳細描述：** 使用鍋鏟翻轉煎餅堆（只能將某位置以上的所有煎餅翻轉），由小到大排序煎餅堆。

**English approach:** Greedy pancake sort: find max unsorted pancake, flip to top, then flip to destination.

**中文解題思路：** 貪婪法由大到小定位：先將未定位最大者翻到頂端，再整體翻至目標底端。 ==========================================================================


<a id="uva-121_pipe-fitters"></a>

### UVa 121 — Pipe Fitters／網格與交錯排管幾何堆疊

- 原始碼：[121_pipe-fitters.c](121_pipe-fitters.c)
- 難度：UVa Star 1
- 演算法：geometry, greedy

**English description:** Given grid dimensions a x b, calculate maximum number of unit pipes packed using standard grid vs skew (hexagonal) packing.

**中文詳細描述：** 給定容器長寬 a x b，計算單位圓管以標準正交網格排列與交錯蜂巢排列下最多可容納之管子數量。

**English approach:** Standard grid count is floor(a) * floor(b). Skew packing places rows at vertical spacing sqrt(3)/2, alternating between floor(a) and floor(a - 0.5) pipes per row.

**中文解題思路：** 網格排列為 floor(a)*floor(b)；交錯排列每層垂直間距為 sqrt(3)/2，相鄰層管數交替為 floor(a) 與 floor(a-0.5)，雙向計算取最大值。 ==========================================================================


<a id="uva-122_trees-on-the-level"></a>

### UVa 122 — Trees on the level／二元樹層次遍歷

- 原始碼：[122_trees-on-the-level.c](122_trees-on-the-level.c)
- 難度：UVa Star 2
- 演算法：binary-tree, bfs, parsing

**English description:** Given node values and binary tree paths (e.g. 5,LL), verify complete tree and output level-order traversal.

**中文詳細描述：** 給定二元樹各結點數值與左右路徑標記，驗證樹是否結構完整無重複無懸空結點，並輸出由上至下的層次走訪。

**English approach:** Construct tree via dynamic pointer or array mapping. Check all ancestor nodes exist, then perform BFS queue traversal.

**中文解題思路：** 以路徑動態建樹，檢查是否有未賦值結點或重複賦值，最後以 BFS 佇列輸出層序遍歷。 ==========================================================================


<a id="uva-123_searching-quickly"></a>

### UVa 123 — Searching Quickly／關鍵字上下文索引 (KWIC Index)

- 原始碼：[123_searching-quickly.c](123_searching-quickly.c)
- 難度：UVa Star 2
- 演算法：string, sorting, simulation

**English description:** Generate a Key Word In Context (KWIC) index: alphabetized list of titles rotated around capitalized non-stop words.

**中文詳細描述：** 生成關鍵字上下文索引 (KWIC)：忽略停用詞，將每個非停用詞大寫並將其排在關鍵字位置，按字典序穩定排序。

**English approach:** Store ignore list. For each title, identify keywords, generate rotation entries, and sort stably by keyword.

**中文解題思路：** 以雜湊或線性表比對停用詞，遍歷每句標題中的非停用字詞，記錄原始索引位置後進行多鍵排序。 ==========================================================================


<a id="uva-124_following-orders"></a>

### UVa 124 — Following Orders／依順序排程 (全排列拓撲排序)

- 原始碼：[124_following-orders.c](124_following-orders.c)
- 難度：UVa Star 2
- 演算法：graph, topological-sort, backtracking

**English description:** Given a set of variables and ordering constraints, print all valid topological orderings in alphabetical order.

**中文詳細描述：** 給定一組變數及其先後依序限制條件，按字母順序輸出所有合法的拓撲排序序列。

**English approach:** Backtracking with constraint verification. Sort variable characters, recursively pick unused char with 0 in-degree.

**中文解題思路：** 回溯法全排列搜尋：將變數按字典序排序，每次遞迴挑選入度為 0 且未使用的變數加入排列。 ==========================================================================


<a id="uva-125_numbering-paths"></a>

### UVa 125 — Numbering Paths／有向圖路徑計數與環路判定

- 原始碼：[125_numbering-paths.c](125_numbering-paths.c)
- 難度：UVa Star 2
- 演算法：graph, floyd-warshall

**English description:** Given directed street network, find the number of paths between all pairs of intersections, or -1 if infinitely many paths exist (via cycle).

**中文詳細描述：** 給定有向街道網路，計算所有交會點對之間的路徑數量；若兩點間存在有向環導致有無窮多條路徑，則標記為 -1。

**English approach:** Modified Floyd-Warshall: path count matrix dp[i][j] += dp[i][k] * dp[k][j]. Nodes k with dp[k][k] > 0 are on a cycle, setting affected paths to -1.

**中文解題思路：** 變形 Floyd-Warshall：更新路徑數 dp[i][j] += dp[i][k]*dp[k][j]。若發現 dp[k][k] > 0 則節點 k 在環上，所有可達該環且由該環可達的 (i, j) 均標記為 -1。 ==========================================================================


<a id="uva-126_the-pascal-library"></a>

### UVa 126 — The Pascal Library／帕斯卡多項式乘法與美觀輸出

- 原始碼：[126_the-pascal-library.c](126_the-pascal-library.c)
- 難度：UVa Star 2
- 演算法：string, simulation, math

**English description:** Multiply two multivariate polynomials in variables x and y, combine like terms, and format output with exponents on the line above.

**中文詳細描述：** 計算二元多項式乘法 (含 x, y 變數)，同類項合併化簡，並以上下兩行排版輸出多項式指數。

**English approach:** Parse terms into (coefficient, x_deg, y_deg) tuples. Multiply and collect terms by degree in descending order of x, then ascending of y. Format aligned string.

**中文解題思路：** 將多項式解析為 (係數, x指數, y指數) 陣列，雙重迴圈逐項相乘並合併同類項，依 x 指數降序排列，排版輸出指數列與基底列。 ==========================================================================


<a id="uva-127_accordian-patience"></a>

### UVa 127 — "Accordian" Patience／手風琴接龍紙牌模擬

- 原始碼：[127_accordian-patience.c](127_accordian-patience.c)
- 難度：UVa Star 2
- 演算法：simulation, stack, card-game

**English description:** Simulate 52-card Accordian patience game: move card onto left 1st or 3rd pile if same suit or rank.

**中文詳細描述：** 模擬 52 張紙牌手風琴接龍：若與左邊第 1 疊或第 3 疊花色或點數相同，優先將牌堆向左疊合。

**English approach:** Maintain 52 stacks. Greedy simulation: scan from left to right, check left 3 then left 1, move and restart from left.

**中文解題思路：** 維護牌堆串列或陣列堆疊。由左至右掃描，優先匹配左方第 3 疊，否則匹配左方第 1 疊，一旦移動即重頭掃描。 ==========================================================================


<a id="uva-128_software-crc"></a>

### UVa 128 — Software CRC／軟體循環冗餘校驗碼 (CRC-16)

- 原始碼：[128_software-crc.c](128_software-crc.c)
- 難度：UVa Star 2
- 演算法：math, bit-manipulation, crc

**English description:** Compute 2-byte CRC checksum with generator polynomial g = 34943 such that message * 2^16 + CRC == 0 (mod g).

**中文詳細描述：** 計算 2 位元組 CRC 校驗碼，使得字串 ASCII 位元流左移 16 位元加上 CRC 碼後可被 34943 整除。

**English approach:** Treat string bytes as big-endian polynomial. Compute remainder r = (msg * 2^16) % 34943. CRC = (34943 - r) % 34943.

**中文解題思路：** 將字串位元組逐一按大端序取模：rem = (rem * 256 + byte) % 34943。最後左移 16 位元，CRC = (34943 - r) % 34943。 ==========================================================================


<a id="uva-129_krypton-factor"></a>

### UVa 129 — Krypton Factor／無連續相鄰重複子字串迴溯法

- 原始碼：[129_krypton-factor.c](129_krypton-factor.c)
- 難度：UVa Star 2
- 演算法：backtracking, string

**English description:** A string is 'hard' if it contains no two adjacent identical substrings. Given n and alphabet size L, find the n-th hard string in lexicographic order.

**中文詳細描述：** 若一個字串中不存在任意兩個連續且完全相同的子字串，則稱其為「困難字串」。給定整數 n 與字元集大小 L，求字典序第 n 個困難字串。

**English approach:** Backtracking search: incrementally append characters from 'A' to 'A'+L-1. After appending, verify that suffixes of length 2k do not consist of two identical halves.

**中文解題思路：** 深度優先回溯搜尋：依字典序逐字元填入 'A' 至 'A'+L-1，每次檢驗末尾長度為 2k 的子字串前後兩半是否相同，計數至第 n 個印出。 ==========================================================================


<a id="uva-130_roman-roulette"></a>

### UVa 130 — Roman Roulette／羅馬輪盤 (約瑟夫環換位變形)

- 原始碼：[130_roman-roulette.c](130_roman-roulette.c)
- 難度：UVa Star 2
- 演算法：simulation, josephus

**English description:** Josephus variant: the k-th person eliminated is replaced by the next k-th person. Find starting position for survivor 1.

**中文詳細描述：** 約瑟夫環變形：第 k 個被數到的人被處決後，由接下來數到的第 k 個人替補其位置。求使 1 號存活的起始者位置。

**English approach:** Circular array simulation. Shift starting offset until the survivor is person 1.

**中文解題思路：** 以循環陣列模擬淘汰與遞補換位流程。由 1 到 n 嘗試起始點，直到最後存活者為 1 號。 ==========================================================================


<a id="uva-131_the-hands-of-poker"></a>

### UVa 131 — The Hands of Poker／五張換牌最佳撲克牌型評估

- 原始碼：[131_the-hands-of-poker.c](131_the-hands-of-poker.c)
- 難度：UVa Star 2
- 演算法：simulation, brute-force

**English description:** Given a hand of 5 cards and a deck of 5 cards, choose a subset of hand to discard and draw from deck in order to achieve the highest possible poker hand rank.

**中文詳細描述：** 給定手中的 5 張手牌與牌堆頂部的 5 張牌，可從手牌中選擇任意張丟棄，並從牌堆頂依序補齊至 5 張，求可組成的最高撲克牌型。

**English approach:** Enumerate all 2^5 = 32 discard subsets (preserving drawn card order), evaluate rank (straight flush, 4 of a kind, full house, etc.) and take the maximum.

**中文解題思路：** 枚舉手牌替換的 2^5 = 32 種子集，依序由抽牌堆補充不足之張數，對每一組五張牌型進行撲克牌評級，取 32 種組合中之最高階牌型。 ==========================================================================


<a id="uva-132_ashokas-capital"></a>

### UVa 132 — Ashoka's Capital／多邊形質心與穩定支撐凸包幾何

- 原始碼：[132_ashokas-capital.c](132_ashokas-capital.c)
- 難度：UVa Star 2
- 演算法：geometry, convex-hull

**English description:** Determine which vertex of a 2D polygonal pillar will act as the lowest pivot when tipped from its center of gravity.

**中文詳細描述：** 給定柱體截面多邊形與質心，計算多邊形傾倒時能穩定支撐重心的最低支點頂點編號。

**English approach:** Compute 2D convex hull. For each hull edge, check if the projection of the center of mass falls strictly within the edge; find minimum vertex index.

**中文解題思路：** 計算截面頂點之凸包，對各相鄰支撐邊檢驗質心鉛直投影是否落在線段內，輸出具備最小編號之支撐頂點。 ==========================================================================


<a id="uva-133_the-dole-queue"></a>

### UVa 133 — The Dole Queue／雙向約瑟夫失業救濟發放

- 原始碼：[133_the-dole-queue.c](133_the-dole-queue.c)
- 難度：UVa Star 2
- 演算法：simulation, josephus, circular-list

**English description:** N people in a circle. Two officials count clockwise by k and counter-clockwise by m to eliminate people.

**中文詳細描述：** N 個人圍成一圈。兩名官員分別順時針數 k 個人與逆時針數 m 個人選出淘汰者，求依序淘汰順序。

**English approach:** Circular array simulation with active count. Track dual pointers, eliminate simultaneous candidates if same.

**中文解題思路：** 維護一維環狀標記陣列與雙指標，每輪順時針移動 k 步、逆時針移動 m 步，若指向同一人則單獨出圈。 ==========================================================================


<a id="uva-134_loglan-a-logical-language"></a>

### UVa 134 — Loglan - A Logical Language／人工語言語法分析詞性判定

- 原始碼：[134_loglan-a-logical-language.c](134_loglan-a-logical-language.c)
- 難度：UVa Star 2
- 演算法：string, parsing

**English description:** Determine whether a given Loglan sentence conforms to the specified grammar rules (A, MOD, DA, PA, etc.).

**中文詳細描述：** 根據 Loglan 邏輯人工語言的詞性分類規則 (母音結尾為名詞、輔音母音分佈) 檢驗給定句子文法結構是否合法。

**English approach:** Tokenize into words, map each word to its syntactic word class via vowel/consonant suffix patterns, and check grammatical production rules.

**中文解題思路：** 依據單詞元音與輔音組合判定詞性代碼 (名詞、動詞、連接詞等)，以簡化語法狀態機驗證句子結構是否符合 Loglan 語法標準。 ==========================================================================


<a id="uva-135_no-rectangles"></a>

### UVa 135 — No Rectangles／有限射影幾何與無矩形點集構造

- 原始碼：[135_no-rectangles.c](135_no-rectangles.c)
- 難度：UVa Star 2
- 演算法：math, combinatorics

**English description:** Given k, construct a k-regular incidence structure of size k*(k-1)+1 containing no 4-cycles (rectangles in bipartite graph).

**中文詳細描述：** 給定每列包含 k 個點的要求，利用有限射影平面構造點線關聯矩陣，使得任意兩行無兩個相同的公共列 (無矩形環路)。

**English approach:** Finite projective plane construction: for prime power p = k - 1, generate p^2 + p + 1 lines with p + 1 points each using Galois field arithmetic.

**中文解題思路：** 利用階數 p = k - 1 的有限射影平面構造法，生成 p^2 + p + 1 條線段，每條線包含 p + 1 個點，使得任意兩線恰好交於一點。 ==========================================================================


<a id="uva-136_ugly-numbers"></a>

### UVa 136 — Ugly Numbers／醜數

- 原始碼：[136_ugly-numbers.c](136_ugly-numbers.c)
- 演算法：動態規劃、三指標（dynamic programming, three pointers）

**English description:** Ugly numbers are positive integers whose only prime factors are 2, 3, and 5, with 1 included as the first ugly number. Generate the sequence in increasing order and print the fixed requested value: the 1500th ugly number.

**中文詳細描述：** 醜數定義為質因數只可能含 2、3、5 的正整數，並把 1 視為第一個醜數。本題沒有一般資料輸入；程式用三個指標合併乘 2、乘 3、乘 5 形成的遞增序列，去除重複值後輸出第 1500 個醜數。

<a id="uva-137_polygons"></a>

### UVa 137 — Polygons／兩凸多邊形交集與聯集面積幾何

- 原始碼：[137_polygons.c](137_polygons.c)
- 難度：UVa Star 3
- 演算法：geometry, polygon

**English description:** Given two convex polygons, compute the total area of both polygons minus twice the area of their intersection.

**中文詳細描述：** 給定兩個凸多邊形，計算兩多邊形聯集面積扣除交集面積 (即對稱差面積)。

**English approach:** Area of symmetric difference equals Area(P1) + Area(P2) - 2 * Area(P1 intersect P2). Compute polygon intersection using Sutherland-Hodgman clipping.

**中文解題思路：** 對稱差面積等於 Area(P1) + Area(P2) - 2 * Area(P1 ∩ P2)。利用 Sutherland-Hodgman 凸多邊形裁剪演算法求得交集多邊形與面積。 ==========================================================================


<a id="uva-138_street-numbers"></a>

### UVa 138 — Street Numbers／門牌號碼平衡數 (佩爾方程)

- 原始碼：[138_street-numbers.c](138_street-numbers.c)
- 難度：UVa Star 2
- 演算法：math, number-theory, pell-equation

**English description:** Find 10 pairs (x, n) such that sum 1..(x-1) == sum (x+1)..n.

**中文詳細描述：** 求前 10 組正整數 (x, n)，滿足 1 到 x-1 的和等於 x+1 到 n 的和 (佩爾方程 8x^2 + 1 = y^2)。

**English approach:** 2*x^2 = n*(n+1). Solving gives recurrence: x_{k+1} = 3*x_k + 2*y_k, n from quadratic equation.

**中文解題思路：** 化簡為 2*x^2 = n*(n+1)，利用佩爾方程線性遞迴關係快速生成前 10 組解。 ==========================================================================


<a id="uva-139_telephone-tangles"></a>

### UVa 139 — Telephone Tangles／長途電話號碼區域代碼與費率解析

- 原始碼：[139_telephone-tangles.c](139_telephone-tangles.c)
- 難度：UVa Star 1
- 演算法：string, map

**English description:** Parse dialled telephone number into area code and subscriber number using a prefix rate table, then calculate call cost.

**中文詳細描述：** 根據區碼費率表比對撥出電話號碼之最長前綴區碼與用戶號碼，並依據通話時間計算電話總費用。

**English approach:** Match longest matching prefix against known IDD (00) and STD (0) codes. Multiply duration by rate per minute.

**中文解題思路：** 對撥出的號碼自前綴進行前綴比對 (區分 00 國際與 0 國內長途)，匹配出地區代碼與每分鐘費率後乘以通話分鐘數。 ==========================================================================


<a id="uva-140_bandwidth"></a>

### UVa 140 — Bandwidth／圖的頻寬最小化

- 原始碼：[140_bandwidth.c](140_bandwidth.c)
- 難度：UVa Star 2
- 演算法：backtracking, graph, permutation

**English description:** Find permutation of graph vertices that minimizes maximum distance between any two adjacent vertices.

**中文詳細描述：** 求圖的頂點全排列，使相鄰頂點在排列中的最大距離 (頻寬) 最小化 (剪枝回溯)。

**English approach:** Backtracking search over all vertex permutations with branch-and-bound pruning whenever current span >= best_so_far.

**中文解題思路：** 對最多 8 個相異頂點進行全排列搜尋，維護全域最小頻寬，並在搜尋中途若頻寬已超出則剪枝。 ==========================================================================


<a id="uva-141_the-spot-game"></a>

### UVa 141 — The Spot Game／黑白圍棋式翻轉盤面重複狀態判定

- 原始碼：[141_the-spot-game.c](141_the-spot-game.c)
- 難度：UVa Star 2
- 演算法：simulation, hash

**English description:** Two players place or remove stones on an N x N board. A player loses if their move restores a board configuration that occurred previously (under 4 rotations).

**中文詳細描述：** 兩位玩家在 N x N 棋盤上下棋或拔子。若玩家的走法使盤面呈現與先前盤面 (包含 4 種 90 度旋轉) 完全相同的狀態，則該玩家立即判負。

**English approach:** Maintain 2D board state. For each move, apply edit, generate all 4 rotated representations, check against hash set of historical boards, then store canonical hash.

**中文解題思路：** 維護二維盤面狀態，每次落子後生成 90°、180°、270° 及原圖共 4 種旋轉表示法，檢查是否曾在歷史紀錄中出現過。 ==========================================================================


<a id="uva-142_mouse-clicks"></a>

### UVa 142 — Mouse Clicks／滑鼠點擊判定

- 原始碼：[142_mouse-clicks.c](142_mouse-clicks.c)
- 難度：UVa Star 2
- 演算法：geometry, simulation

**English description:** Determine whether a mouse click falls inside a window (topmost visible) or nearest icons.

**中文詳細描述：** 判定滑鼠點擊是否落在視窗內 (後畫的覆蓋先畫的)，或若在視窗外則判定距離最近的圖示。

**English approach:** Check windows in reverse order (topmost first). If point is in rect, select window; else compute Euclidean distance to icons.

**中文解題思路：** 反向遍歷視窗矩形 (後加入者在最上層) 檢查點在矩形內；若皆不在則計算與所有圖示的歐幾里得距離找最近者。 ==========================================================================


<a id="uva-143_orchard-trees"></a>

### UVa 143 — Orchard Trees／果園三角形內部網格點個數幾何計數

- 原始碼：[143_orchard-trees.c](143_orchard-trees.c)
- 難度：UVa Star 2
- 演算法：geometry, lattice-points

**English description:** Given vertices of a triangle, count how many integer grid points (trees) with 1 <= x, y <= 99 fall inside or on the boundary of the triangle.

**中文詳細描述：** 給定果園內三角形邊界的頂點座標，統計有多少個座標為整數且範圍在 1 <= x, y <= 99 內的樹木 (網格點) 落在三角形內部或邊界上。

**English approach:** Compute bounding box clamped to [1, 99]. For each lattice point (x, y), use 2D cross products to verify it is on the same side of all three directed edges.

**中文解題思路：** 計算三角形外接矩形並限制在 [1, 99]，對外接框內每個整數網格點以叉積判斷點是否位於三角形三條有向邊之同一側。 ==========================================================================


<a id="uva-144_student-grants"></a>

### UVa 144 — Student Grants／學生助學金 ATM 循序發放模擬

- 原始碼：[144_student-grants.c](144_student-grants.c)
- 難度：UVa Star 1
- 演算法：simulation, queue

**English description:** N students queued at an ATM each require 40 dollars. The machine pays out 1, 2, ..., k, 1, 2, ... coins in cycles. Simulate the queue exit order.

**中文詳細描述：** N 名學生排隊領取各 40 元助學金，提款機依序吐出 1, 2, ..., k 元並循環。模擬學生領足金額離開隊列的先後順序。

**English approach:** Simulate queue with circular pointer. Maintain payout value and residual credit from current withdrawal. Record completion order when student gets 40.

**中文解題思路：** 以環形佇列模擬排隊，維護提款機目前出幣額度與當前餘額，學生累計滿 40 元時離隊並將其編號記錄於輸出陣列。 ==========================================================================


<a id="uva-145_gondwanaland-telecom"></a>

### UVa 145 — Gondwanaland Telecom／跨時段電話通話費率分段累計

- 原始碼：[145_gondwanaland-telecom.c](145_gondwanaland-telecom.c)
- 難度：UVa Star 1
- 演算法：simulation, math

**English description:** Given call start and end times and rate category, calculate minutes spent in day (8am-6pm), evening (6pm-10pm), and night (10pm-8am) bands, and total bill.

**中文詳細描述：** 給定電話通話起訖時間與費率代碼，分段統計日間 (8:00-18:00)、傍晚 (18:00-22:00) 與夜間 (22:00-8:00) 的通話分鐘數與總話費。

**English approach:** Convert times to minute-of-day offsets. Step minute by minute (or calculate overlapping intervals) modulo 1440, classifying each minute into its tariff band.

**中文解題思路：** 將通話時間轉換為以分鐘為單位的時間戳，跨日時加 1440 分鐘，逐分鐘比對落點時段區間累加三時段通話時間並計費。 ==========================================================================


<a id="uva-146_id-codes"></a>

### UVa 146 — ID Codes／識別碼字典序下一個排列

- 原始碼：[146_id-codes.c](146_id-codes.c)
- 演算法：字串、下一個排列（string, next permutation）

**English description:** For each identifier string, find the smallest permutation of its characters that is lexicographically greater than the input. Print that immediate successor, or print `No Successor` when the input is already the greatest permutation. Input ends at `#`.

**中文詳細描述：** 每行輸入一個識別碼字串，要求用相同字元重新排列，找出字典序中緊接在原字串之後的排列。由右向左找可增加的位置、交換後反轉後綴；若原字串已是最大排列則輸出 `No Successor`。讀到 `#` 時結束。

<a id="uva-147_dollars"></a>

### UVa 147 — Dollars／貨幣換幣組合數

- 原始碼：[147_dollars.c](147_dollars.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, coin-change

**English description:** Given dollar amount up to $300.00, count ways to make change using 11 predefined coin and bill values.

**中文詳細描述：** 給定最多 $300.00 的金額，計算使用 11 種特定硬幣與鈔票面額湊齊金額的方法數 (完全背包 DP)。

**English approach:** Multiply all values by 20 to convert to integers (5c = 1 unit, max 6000). Precompute 1D unbounded knapsack DP.

**中文解題思路：** 將金額乘 20 轉為整數單位避免浮點數誤差 (5分=1單位，上限6000)。預處理一維完全背包動態規劃。 ==========================================================================


<a id="uva-148_anagram-checker"></a>

### UVa 148 — Anagram Checker／字謎組合詞庫字典比對回溯

- 原始碼：[148_anagram-checker.c](148_anagram-checker.c)
- 難度：UVa Star 2
- 演算法：backtracking, string

**English description:** Given a dictionary of words and a phrase, find all anagrams of the phrase made up of words from the dictionary, excluding the phrase itself.

**中文詳細描述：** 給定英文字典與一段短語，以回溯法找出所有由字典中單詞組成的字母異位詞 (Anagram) 短語，且不得與原始短語單詞完全一致。

**English approach:** Count letter frequencies of target phrase. Filter valid dictionary words. Use recursive backtracking to match letter counts to 0.

**中文解題思路：** 統計目標短語中 26 個字母的出現頻率，挑選出字母頻率不超過目標的候選詞，進行深度優先回溯拼接直到字母全部配對完畢。 ==========================================================================


<a id="uva-149_forests"></a>

### UVa 149 — Forests／樹木重疊能見度幾何計算

- 原始碼：[149_forests.c](149_forests.c)
- 難度：UVa Star 2
- 演算法：geometry

**English description:** Given grid tree positions and circular radius, calculate the number of trees visible from an observer coordinate without occlusion.

**中文詳細描述：** 在給定半徑與圓形樹木網格中，計算站在原點的觀察者向四周望去時，不被前方樹木遮擋之可見樹木數量。

**English approach:** Calculate polar angle and angular span for each circular tree; check whether a tree's angular interval is completely subsumed by closer trees.

**中文解題思路：** 計算每棵樹相對於觀察點之極角與視角半徑張角，按距離升序排列，以區間聯集檢查後方樹木是否被前方樹木完全遮蔽。 ==========================================================================


<a id="uva-150_double-time"></a>

### UVa 150 — Double Time／儒略曆與格里高利曆雙向精準轉換

- 原始碼：[150_double-time.c](150_double-time.c)
- 難度：UVa Star 2
- 演算法：simulation, math, date

**English description:** Convert dates and weekdays between Old Style (Julian calendar) and New Style (Gregorian calendar).

**中文詳細描述：** 精確計算儒略曆 (舊曆) 與格里高利曆 (新曆) 之間的曆法轉換與星期對齊。

**English approach:** Convert input date to Julian Day Number (JDN) based on source calendar rules, then convert JDN to target calendar date.

**中文解題思路：** 將給定日期依其原曆法規則計算為絕對儒略日數 (JDN)，再將絕對天數映射回另一曆法之年月日與星期名稱。 ==========================================================================


<a id="uva-151_power-crisis"></a>

### UVa 151 — Power Crisis／電力危機

- 原始碼：[151_power-crisis.c](151_power-crisis.c)
- 演算法：約瑟夫環模擬（simulation, Josephus problem）

**English description:** Regions numbered `1` through `N` are switched off in a cyclic elimination process. Region 1 must be removed first, and every `m`-th remaining region is then removed. For each `N`, find the smallest positive `m` that leaves region 13 as the final powered region; input ends with zero.

**中文詳細描述：** 對每個輸入的地區數 `N`，編號 1 的地區先停電，之後在仍有電的地區間循環計數，每數到第 `m` 個便使其停電。枚舉正整數 `m` 並模擬約瑟夫淘汰過程，找出讓第 13 區最後才停電的最小 `m`；輸入 0 結束，逐筆輸出答案。

<a id="uva-151_power-crisis-pr"></a>

### UVa 151 — Power Crisis／約瑟夫環危機最後停電區域求解

- 原始碼：[151_power-crisis-pr.c](151_power-crisis-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, simulation

**English description:** Given N regions with region 1 shutting off first, find the minimum step m such that region 13 is the last region shut off.

**中文詳細描述：** 給定 N 個供電區域，第 1 區最先停電，求最小每步間隔 m，使得第 13 區剛好是最後一個被停電的區域。

**English approach:** Simulate Josephus elimination on N - 1 remaining elements starting after 1. Increment m until the last remaining element is 13.

**中文解題思路：** 自第 1 區停電後，對剩餘 N - 1 個區域進行約瑟夫環遞推模擬，枚舉間隔 m 直到最後勝出者編號為 13。 ==========================================================================


<a id="uva-152_trees-a-crowd"></a>

### UVa 152 — Tree's a Crowd／擁擠的樹林 (3D 歐式距離分佈)

- 原始碼：[152_trees-a-crowd.c](152_trees-a-crowd.c)
- 難度：UVa Star 1
- 演算法：geometry, math, brute-force

**English description:** Given up to 5000 3D tree coordinates, find distance to closest neighbor for each tree and build histogram.

**中文詳細描述：** 給定最多 5000 棵樹的 3D 座標，計算每棵樹與最近鄰樹的距離，並統計 0..9 距離區間的樹木數量直方圖。

**English approach:** Pairwise 3D Euclidean distance calculation. Find minimum distance per tree and increment histogram bin.

**中文解題思路：** 雙重迴圈枚舉點對計算 3D 距離平方。對每棵樹求最近鄰距離，並將結果累加至對應區間桶中。 ==========================================================================


<a id="uva-153_permalex"></a>

### UVa 153 — Permalex／字典序排列位次

- 原始碼：[153_permalex.c](153_permalex.c)
- 難度：UVa Star 2
- 演算法：combinatorics, math, string

**English description:** Given a string with potential duplicate letters, compute its 1-based lexicographical permutation rank.

**中文詳細描述：** 給定一個可能含有重複字母的字串，計算其在所有相異字母排列中的 1-based 字典序排名。

**English approach:** Combinatorics with multinomial coefficients. For each position, count valid permutations using smaller leading letters.

**中文解題思路：** 多項式排列計數：對每一位枚舉比當前字元小的字母作為開頭，累加多重集全排列數 (n! / (c1! c2!...))。 ==========================================================================


<a id="uva-154_recycling"></a>

### UVa 154 — Recycling／垃圾回收站相異屬性最少換算投票

- 原始碼：[154_recycling.c](154_recycling.c)
- 難度：UVa Star 1
- 演算法：brute-force, string

**English description:** Given recycling bin allocation schemes across multiple cities, find the city whose scheme requires the minimum total changes to match others.

**中文詳細描述：** 給定多座城市五種垃圾桶顏色與回收類型的配置，找出與其他所有城市相異配置最少 (即共識度最高) 的城市編號。

**English approach:** Represent each city as a 5-element array. For each pair of cities, count differences in bin assignments. Pick city with minimum sum of differences.

**中文解題思路：** 將各城市的 5 種顏色分配編碼，雙重迴圈計算兩兩城市間配置相異之總次數，選出相異總和最小之城市輸出。 ==========================================================================


<a id="uva-155_all-squares"></a>

### UVa 155 — All Squares／遞迴正方形覆蓋點計數

- 原始碼：[155_all-squares.c](155_all-squares.c)
- 難度：UVa Star 2
- 演算法：recursion, geometry

**English description:** Count how many nested recursive squares cover a given point (px, py).

**中文詳細描述：** 遞迴繪製四角中心的正方形，計算目標點 (px, py) 被多少個正方形所覆蓋 (遞迴幾何)。

**English approach:** Recursive geometric check: count +1 if (px, py) inside current square centered at (cx, cy) with size k; recurse on 4 corners with k/2.

**中文解題思路：** 檢查點是否在當前以 (cx, cy) 為中心、半徑為 k 的正方形內；若 k > 1 則遞迴向四個角落 (cx±k, cy±k) 擴展。 ==========================================================================


<a id="uva-156_ananagrams"></a>

### UVa 156 — Ananagrams／無同字母異序詞之單字

- 原始碼：[156_ananagrams.c](156_ananagrams.c)
- 難度：UVa Star 2
- 演算法：string, sorting, hash-table

**English description:** Find all words in a dictionary that cannot be transformed into any other word by rearranging letters.

**中文詳細描述：** 找出字典中無法透過重新排列字母得到字典中其他單字的單詞 (Ananagrams)，按字母順序輸出。

**English approach:** Normalize each word by converting to lowercase and sorting characters. Words with unique signature are ananagrams.

**中文解題思路：** 將每個單字轉小寫後做字元排序得到標準特徵。統計各特徵出現次數，次數為 1 的即為所求單字。 ==========================================================================


<a id="uva-157_route-finding"></a>

### UVa 157 — Route Finding／地鐵線路換乘最短時間與路徑 Dijkstra

- 原始碼：[157_route-finding.c](157_route-finding.c)
- 難度：UVa Star 2
- 演算法：graph, shortest-path

**English description:** Find the shortest travel route between subway stations, factoring in route segment travel times and line transfer penalties.

**中文詳細描述：** 計算地鐵網路中任意兩站之間的最短路徑與耗時，包含相鄰站間行駛時間與跨線換乘站的額外換線懲罰時間。

**English approach:** Model as graph with nodes representing (line, station) pairs. Add edges for intra-line travel and transfer edges between lines at common stations. Run Dijkstra.

**中文解題思路：** 以 (路線, 車站) 作為狀態圖節點，同路線相鄰站連線賦權行駛時間，同名換乘站間連線賦權換線懲罰時間，執行 Dijkstra 演算法求解。 ==========================================================================


<a id="uva-158_calendar"></a>

### UVa 158 — Calendar／日程提醒日曆日期間隔模擬

- 原始碼：[158_calendar.c](158_calendar.c)
- 難度：UVa Star 2
- 演算法：simulation, date

**English description:** Given yearly anniversaries and event reminders with warning windows (0 to 7 days), output today's active reminder list.

**中文詳細描述：** 給定年度紀念日與具有提前預警天數 (0 到 7 天) 的日程事件，輸出今日應觸發之提醒清單與星號提示等級。

**English approach:** Simulate day count differences across dates within the current year (and year boundary leap considerations), sorting reminders by proximity.

**中文解題思路：** 計算給定基準日與各紀念日之天數差值，若落在預警區間內則按緊迫度與星號數量排序印出提醒日程。 ==========================================================================


<a id="uva-159_word-crosses"></a>

### UVa 159 — Word Crosses／單字相交十字格排版輸出

- 原始碼：[159_word-crosses.c](159_word-crosses.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Given two pairs of intersecting words, find matching common letters and print a side-by-side 2D character grid cross.

**中文詳細描述：** 給定兩組相交的英文單字，尋找首個相同公共字母形成十字交叉，並排印出二維字元十字交叉圖形。

**English approach:** Find first matching character between horizontal and vertical words. Lay out characters onto 2D text buffer and print with spacing.

**中文解題思路：** 遍歷橫向與縱向單字尋找首個相同之相交字母，在二維字元緩衝區中填入單字並保持相對位置與空白輸出。 ==========================================================================


<a id="uva-160_factors-and-factorials"></a>

### UVa 160 — Factors and Factorials／階乘的質因數分解

- 原始碼：[160_factors-and-factorials.c](160_factors-and-factorials.c)
- 演算法：質因數計數、勒讓德公式（number theory, Legendre's formula）

**English description:** For each positive integer `N`, express `N!` by listing the exponent of every prime not exceeding `N`, in ascending prime order and in the required aligned format. Input terminates with zero.

**中文詳細描述：** 每筆輸入正整數 `N`，要將 `N!` 分解成質數冪乘積，並依質數由小到大列出每個指數。對質數 `p` 累加 `⌊N/p⌋ + ⌊N/p²⌋ + …` 即得其在階乘中的次數；按照題目欄寬格式輸出，輸入 0 時結束。

<a id="uva-161_traffic-lights"></a>

### UVa 161 — Traffic Lights／多組紅綠燈同步綠燈首刻模擬

- 原始碼：[161_traffic-lights.c](161_traffic-lights.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Given cycle times of a set of traffic lights, find the first time (after all lights have changed at least once) that all lights are green simultaneously.

**中文詳細描述：** 給定一組交通紅綠燈的週期長度，求所有號誌至少變換過一次之後，首次全部號誌同時維持綠燈之秒數 (若超過 5 小時則判定無法同步)。

**English approach:** Each light i with cycle C_i is green during [2k*C_i, 2k*C_i + C_i - 5). Iterate time t from 2 * min(C_i) up to 18000s to find simultaneous green.

**中文解題思路：** 週期為 C 的號誌在 [2kC, 2kC + C - 5) 秒為綠燈。自時間 2 * min(C) 開始向上枚舉至 18000 秒，驗證所有號誌是否同時為綠燈。 ==========================================================================


<a id="uva-162_beggar-my-neighbour"></a>

### UVa 162 — Beggar My Neighbour／乞丐鄰居紙牌遊戲模擬

- 原始碼：[162_beggar-my-neighbour.c](162_beggar-my-neighbour.c)
- 難度：UVa Star 2
- 演算法：simulation, queue

**English description:** Simulate the classic card game 'Beggar My Neighbour' with face cards requiring payments (J=1, Q=2, K=3, A=4), until one player runs out of cards.

**中文詳細描述：** 模擬經典紙牌遊戲「乞丐鄰居」：出到人頭牌時對手需支付相應張數 (J=1, Q=2, K=3, A=4)，未出人頭牌則由出牌者收走桌面底牌，直到一人無牌為止。

**English approach:** Queue-based simulation with turn alternations, penalty counts, and pile transfers.

**中文解題思路：** 以佇列維護兩位玩家手牌與桌面中央牌堆，遇人頭牌設定罰牌計數器並轉移罰牌責任，無人頭牌時收牌入隊底。 ==========================================================================


<a id="uva-163_city-directions"></a>

### UVa 163 — City Directions／城市街道網格轉彎導航模擬

- 原始碼：[163_city-directions.c](163_city-directions.c)
- 難度：UVa Star 2
- 演算法：simulation, geometry

**English description:** Given city street layout with legal turn angles and one-way restrictions, simulate path navigation following movement commands.

**中文詳細描述：** 給定城市街道網格之單行道與允許轉彎角度，依據轉彎指令模擬車輛行駛路徑與方向變化。

**English approach:** Direction orientation vector tracking (N, NE, E, SE, S, SW, W, NW) with angular arithmetic and intersection constraint checks.

**中文解題思路：** 以 8 個羅盤方位向量維護當前行進方向，配合轉向指令計算相對偏轉角度與目標路口合法性。 ==========================================================================


<a id="uva-164_string-computer"></a>

### UVa 164 — String Computer／字串編輯指令重構

- 原始碼：[164_string-computer.c](164_string-computer.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, string, edit-distance

**English description:** Find minimum number of insert, delete, change operations to transform string A into string B and print operations.

**中文詳細描述：** 求將字串 A 轉換為字串 B 的最少插入、刪除、取代操作次數，並輸出對應指令 (帶路徑回溯的編輯距離 DP)。

**English approach:** Standard Wagner-Fischer edit distance algorithm with 2D backtrack table to reconstruct formatted command string.

**中文解題思路：** 標準編輯距離動態規劃，維護操作來源陣列，自底向上回溯還原每步插入、刪除與替換指令與位置。 ==========================================================================


<a id="uva-165_frogs"></a>

### UVa 165 — Frogs／青蛙跳躍跳板連通性判斷

- 原始碼：[165_frogs.c](165_frogs.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill

**English description:** Given coordinates of lily pads and frog jump range, determine if a path exists between start and destination pads.

**中文詳細描述：** 給定荷葉座標與青蛙最大跳躍距離，判定起始荷葉與目標荷葉之間是否存在連通跳躍路徑。

**English approach:** Euclidean distance graph construction: add edge if distance <= jump range. Run BFS or DFS to test reachability.

**中文解題思路：** 計算荷葉兩兩間之歐幾里得距離，小於等於最大跳躍距者建立無向邊，以 BFS 或 DFS 判斷連通性。 ==========================================================================


<a id="uva-166_making-change"></a>

### UVa 166 — Making Change／精準找零錢 (雙向背包 DP)

- 原始碼：[166_making-change.c](166_making-change.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, knapsack

**English description:** Given limited coins of buyer and unlimited coins of seller, minimize total coins exchanged (buyer pay + seller change).

**中文詳細描述：** 買方持有有限硬幣，賣方持有無限硬幣。求完成支付使得雙方轉移的硬幣總數 (買方付出 + 賣方找零) 最小。

**English approach:** Bounded knapsack for buyer payment, unbounded knapsack for shopkeeper change. Combine and find minimum total coins.

**中文解題思路：** 對買方多重背包求湊齊某金額的最少硬幣數；對店員完全背包求找零最少硬幣數，兩者枚舉超額付款金額取總和最小值。 ==========================================================================


<a id="uva-167_the-sultans-successors"></a>

### UVa 167 — The Sultan's Successors／蘇丹的繼承人 (八皇后加權最大值)

- 原始碼：[167_the-sultans-successors.c](167_the-sultans-successors.c)
- 難度：UVa Star 1
- 演算法：backtracking, recursion, chess

**English description:** Place 8 non-attacking queens on 8x8 weighted chessboard to maximize sum of occupied square scores.

**中文詳細描述：** 在 8x8 的加權棋盤上放置 8 個互不攻擊的西洋棋皇后，求佔據方格權重和的最大值。

**English approach:** Backtracking search over 92 standard 8-queens solutions. Sum board values for each valid configuration and find max.

**中文解題思路：** 利用行、主對角線、次對角線衝突陣列回溯搜尋八皇后的 92 種合法擺法，取棋盤分數總和的最大值。 ==========================================================================


<a id="uva-168_theseus-and-the-minotaur"></a>

### UVa 168 — Theseus and the Minotaur／泰修斯與牛頭人迷宮獵捕

- 原始碼：[168_theseus-and-the-minotaur.c](168_theseus-and-the-minotaur.c)
- 難度：UVa Star 2
- 演算法：simulation, graph-traversal

**English description:** Simulate pursuit in a cavern network: Minotaur flees from Theseus, Theseus drops candles every k steps to trap Minotaur.

**中文詳細描述：** 模擬洞穴網路中的追捕行動：牛頭人逃離泰修斯，泰修斯每走 k 步留下蠟燭封路，最終將牛頭人困在死胡同。

**English approach:** Graph simulation: minotaur moves to first available adjacent node not blocked by candle or Theseus' previous location.

**中文解題思路：** 依照題目優先序走訪圖中鄰接節點。維護蠟燭放置位置，當牛頭人無路可走時輸出最後被困節點標記。 ==========================================================================


<a id="uva-169_a-new-factoring-method"></a>

### UVa 169 — A New Factoring Method／整數因數分解篩法

- 原始碼：[169_a-new-factoring-method.c](169_a-new-factoring-method.c)
- 難度：UVa Star 2
- 演算法：math, number-theory

**English description:** Factorize integers by testing small prime candidates and extracting prime factors efficiently.

**中文詳細描述：** 利用試除法與質數表高效提取整數之質因數分解。

**English approach:** Trial division with precomputed primes up to sqrt(N). Factor out each prime divisor completely.

**中文解題思路：** 預先計算 sqrt(N) 內的質數，循序試除並記錄質因數與對應冪次，剩餘大於 1 之數即為最後質因數。 ==========================================================================


<a id="uva-170_clock-patience"></a>

### UVa 170 — Clock Patience／時鐘撲克接龍翻牌遊戲模擬

- 原始碼：[170_clock-patience.c](170_clock-patience.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate 52-card Clock Patience game: 13 piles arranged like a clock face. Expose card, move to corresponding hour pile until no face-down cards left.

**中文詳細描述：** 模擬 52 張牌時鐘撲克接龍：13 個牌堆排成時鐘形狀，翻開中央牌堆頂牌，依牌面數值 (A=1..K=13) 移至相應鐘點堆底並翻開該堆頂牌，直到翻到已翻過之牌終止。

**English approach:** Maintain 13 piles as deques/arrays with card count. Track total exposed cards and rank of final card.

**中文解題思路：** 以 13 個牌堆陣列模擬，每次依牌面點數 (A-K 對應 1-13) 放置到對應堆底並翻出頂牌，統計翻開總牌數與最後一張牌面。 ==========================================================================


<a id="uva-171_car-tracking"></a>

### UVa 171 — Car Tracking／車輛指令語法分析導航狀態機

- 原始碼：[171_car-tracking.c](171_car-tracking.c)
- 難度：UVa Star 2
- 演算法：string, parsing

**English description:** Parse English driving navigation instructions into standardized turn and road commands.

**中文詳細描述：** 將英文行車導航語句 (如 'GO LEFT AT STREET', 'KEEP RIGHT') 解析為標準化轉向動作與路名指令。

**English approach:** Context-free grammar matching for direction words, street identifiers, and optional prepositional clauses.

**中文解題思路：** 以有限狀態自動機或自頂向下剖析單詞序列，匹配行進方向、路口名稱與轉彎指示。 ==========================================================================


<a id="uva-172_calculator-language"></a>

### UVa 172 — Calculator Language／算術表達式求值與變數賦值直譯器

- 原始碼：[172_calculator-language.c](172_calculator-language.c)
- 難度：UVa Star 2
- 演算法：parsing, stack

**English description:** Interpret assignments and arithmetic expressions for single-letter variables A-Z with integer arithmetic and precedence.

**中文詳細描述：** 直譯單字母變數 A-Z 的算術賦值與運算表達式，支援整數加減乘除與運算子優先順序。

**English approach:** Maintain variable environment table int vars[26]. Evaluate expressions with operator precedence using shunting-yard or recursive descent.

**中文解題思路：** 維護長度 26 的整數變數表，利用遞迴下降剖析器或雙堆疊運算式求值法執行變數更新與輸出求值結果。 ==========================================================================


<a id="uva-173_network-wars"></a>

### UVa 173 — Network Wars／電腦網路佔領搜尋追逐模擬

- 原始碼：[173_network-wars.c](173_network-wars.c)
- 難度：UVa Star 2
- 演算法：graph, simulation

**English description:** Simulate two entities moving through a graph according to local priority rules, trapping or destroying nodes until one is trapped or destroyed.

**中文詳細描述：** 模擬兩方主體在網路圖節點上依照局部優先級規則移動，沿途破壞或佔領節點，直到一方被圍困或在同節點相遇判定勝負。

**English approach:** Adjacency matrix simulation with alphabetical neighbor tie-breaking and node visitation flags.

**中文解題思路：** 維護節點鄰接矩陣與破壞標記，每回合雙方依字母序挑選最小未訪問鄰居前進，檢驗相遇或無路可走條件。 ==========================================================================


<a id="uva-174_strategy"></a>

### UVa 174 — Strategy／囚徒困境賽局策略歷史模擬

- 原始碼：[174_strategy.c](174_strategy.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate round-robin tournament of automated memory-based strategies playing iterated Prisoner's Dilemma.

**中文詳細描述：** 模擬基於記憶歷史的多個策略程式進行重複囚徒困境循環賽，統計各策略的累積得分。

**English approach:** Parse condition trees (e.g. IF LAST OPPONENT == CHEAT THEN CHEAT). Play N rounds pairwise and accumulate payoff scores.

**中文解題思路：** 解析各策略的歷史條件分支判斷樹，兩兩策略對決多回合，按得失分矩陣累加各策略之總積分。 ==========================================================================


<a id="uva-175_keywords"></a>

### UVa 175 — Keywords／文件關鍵字鄰近詞距比對

- 原始碼：[175_keywords.c](175_keywords.c)
- 難度：UVa Star 2
- 演算法：string

**English description:** Given profiles containing pairs of keywords and distance limits, find titles of documents where the keywords occur within the required word distance.

**中文詳細描述：** 給定關鍵字查詢條件 (兩關鍵字及其最大相鄰單詞距離)，找出所有在限制詞距內同時出現該兩關鍵字之文檔。

**English approach:** Tokenize document into words; record indices of occurrence for keywords; check if abs(index1 - index2) - 1 <= max_dist.

**中文解題思路：** 將文章拆解為單詞序列，記錄目標單詞出現的下標位置，檢查是否存在一對下標使其單詞間隔不超過閾值。 ==========================================================================


<a id="uva-176_ocean-currents"></a>

### UVa 176 — Ocean Currents／海流網格 0-1 BFS 最短路徑

- 原始碼：[176_ocean-currents.c](176_ocean-currents.c)
- 難度：UVa Star 2
- 演算法：graph, bfs

**English description:** Find the minimum energy path on an ocean grid where moving with the current costs 0 energy and moving in other directions costs 1 energy.

**中文詳細描述：** 在帶有海流方向的海洋網格上尋找耗能最少的航行路徑：順著海流移動能量消耗為 0，轉向其他方向移動能量消耗為 1。

**English approach:** 0-1 Breadth First Search using a double-ended queue (deque). Edges with weight 0 are pushed to front, weight 1 to back.

**中文解題思路：** 利用雙端佇列 (deque) 實現 0-1 BFS：若下一步方向與當前洋流一致則邊權為 0 (推入隊頭)，否則邊權為 1 (推入隊尾)。 ==========================================================================


<a id="uva-177_paper-folding"></a>

### UVa 177 — Paper Folding／對折紙張龍形曲線展開繪製

- 原始碼：[177_paper-folding.c](177_paper-folding.c)
- 難度：UVa Star 2
- 演算法：simulation, recursion

**English description:** Given n folds of a strip of paper, simulate unfolding at 90 degree angles (dragon curve) and render the ASCII line representation.

**中文詳細描述：** 給定紙帶連續向右對折 n 次後的展開過程，模擬每次展開 90 度的龍形曲線 (Dragon Curve)，並排版繪製出 ASCII 字元曲線。

**English approach:** Generate fold turn directions recursively or by mirroring and reversing previous sequence with inverted turns. Trace on 2D character canvas.

**中文解題思路：** 以遞迴或鏡像翻轉法生成摺痕轉向序列 (左轉/右轉)，將曲線路徑映射至二維畫布上並裁切去除多餘空白行。 ==========================================================================


<a id="uva-178_shuffling-cards"></a>

### UVa 178 — Shuffling Cards／發牌紙牌配對消除模擬

- 原始碼：[178_shuffling-cards.c](178_shuffling-cards.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate card grid game: deal cards to 16 positions, automatically covering pairs that sum to 11 (e.g. 5+6) or triplets of J-Q-K.

**中文詳細描述：** 模擬 16 格桌面紙牌發牌消除：發牌到空位上，自動配對和為 11 的兩張牌 (如 5+6) 或 J-Q-K 三張人頭牌以新牌覆蓋。

**English approach:** Maintain 16 piles. When dealing, find first available empty pile, then repeatedly search and cover matching pairs/triplets.

**中文解題思路：** 維護 16 個牌堆狀態，每次置牌於首個可用空位，檢查是否存在點數和為 11 或 J-Q-K 組合，若有則依序覆蓋。 ==========================================================================


<a id="uva-179_periodic-strings"></a>

### UVa 179 — Periodic Strings／週期密碼加密字串比對

- 原始碼：[179_periodic-strings.c](179_periodic-strings.c)
- 難度：UVa Star 2
- 演算法：string, math

**English description:** Determine the permutation cipher key length and cyclic block permutation mapping plaintext to ciphertext.

**中文詳細描述：** 分析密文與明文，推求置換密碼的塊大小週期與區塊內部字元置換置換規則。

**English approach:** Iterate candidate period lengths K; verify if character frequencies in each block match, and deduce permutation vector.

**中文解題思路：** 枚舉可能的週期長度 K，驗證各長度為 K 的區塊字元組成是否一致，推算出明文到密文之區塊置換映射。 ==========================================================================


<a id="uva-180_eeny-meeny"></a>

### UVa 180 — Eeny Meeny／幼兒數數遊戲約瑟夫安全號碼

- 原始碼：[180_eeny-meeny.c](180_eeny-meeny.c)
- 難度：UVa Star 2
- 演算法：math, simulation

**English description:** Given elimination step m and number of children N, find safe starting spots that avoid being chosen early.

**中文詳細描述：** 在 Eeny Meeny 數數遊戲中，根據報數間隔 m 與人數 N，計算可以堅持到特定輪數之後的安全起始位置。

**English approach:** Josephus recurrence simulation tracking the elimination sequence order.

**中文解題思路：** 以經典約瑟夫環動態轉移式遞推每輪被淘汰者之索引，統計各起始位置之存活輪次。 ==========================================================================


<a id="uva-181_hearts"></a>

### UVa 181 — Hearts／紅心大戰紙牌計分模擬

- 原始碼：[181_hearts.c](181_hearts.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate trick-taking rules of the card game Hearts: leading suit, trump rules, and tracking penalty points.

**中文詳細描述：** 模擬紅心大戰紙牌遊戲出牌規則：引牌花色、王牌判定、贏取墩數與紅心/黑桃黑桃皇后罰分統計。

**English approach:** Follow trick-taking logic: players must follow suit if possible; highest trump (or highest leading suit) wins trick and collects penalties.

**中文解題思路：** 依照每墩出牌規定：有同花色必須跟出，否則可墊牌或出王牌，該墩最大牌者收走全部四張牌並累加罰分。 ==========================================================================


<a id="uva-182_bonus-cards"></a>

### UVa 182 — Bonus Cards／紅利卡點數與折扣最佳兌換

- 原始碼：[182_bonus-cards.c](182_bonus-cards.c)
- 難度：UVa Star 2
- 演算法：dp, greedy

**English description:** Optimize the use of bonus discount cards across shopping transactions to minimize total payments.

**中文詳細描述：** 在多筆購物消費中規劃各類紅利卡的使用分配，使總支付現金達到最小化。

**English approach:** Dynamic programming knapsack / matching formulation: pair purchases with valid discount tiers to maximize savings.

**中文解題思路：** 將折扣卡使用轉化為背包動態規劃或二分圖匹配，在滿足每筆交易使用限制下尋求折扣金額之最大化。 ==========================================================================


<a id="uva-183_bit-maps"></a>

### UVa 183 — Bit Maps／點陣圖與四元樹遞迴互轉

- 原始碼：[183_bit-maps.c](183_bit-maps.c)
- 難度：UVa Star 2
- 演算法：recursion, string

**English description:** Convert between 2D bitmap representation ('B' format) and quadtree decomposition representation ('D' format).

**中文詳細描述：** 在二維 0/1 點陣圖 (B 格式) 與四元樹遞迴分解字串 (D 格式) 之間進行雙向轉換。

**English approach:** Recursive divide and conquer: check if subgrid is all 0s or all 1s. If homogeneous emit '0' or '1', else emit 'D' and recurse on 4 quadrants.

**中文解題思路：** 遞迴分治法：檢查當前矩形區域是否全為 0 或全為 1；若均勻則直接輸出 0 或 1，否則輸出 'D' 並依序遞迴左上、右上、左下、右下四塊。 ==========================================================================


<a id="uva-184_laser-lines"></a>

### UVa 184 — Laser Lines／共線點三點以上線段共線偵測

- 原始碼：[184_laser-lines.c](184_laser-lines.c)
- 難度：UVa Star 2
- 演算法：geometry, sorting

**English description:** Given a set of 2D points, find all maximal subsets of 3 or more collinear points.

**中文詳細描述：** 給定二維平面上一組點集，找出所有包含 3 個或更多點的最大共線點子集並依序輸出。

**English approach:** For each point P, compute slopes to all other points, sort by slope, and detect runs of equal slopes with length >= 2.

**中文解題思路：** 以每個點為基準點，計算與其餘各點之斜率並排序，檢驗斜率相同且未被先前更長線段包含之 3 點以上共線集合。 ==========================================================================


<a id="uva-185_roman-numerals"></a>

### UVa 185 — Roman Numerals／羅馬數字算式正確性與唯一解回溯

- 原始碼：[185_roman-numerals.c](185_roman-numerals.c)
- 難度：UVa Star 2
- 演算法：backtracking, string

**English description:** Given an equation in Roman numerals (A + B = C), check if it is correct as standard Roman, and check if it has a unique cryptarithm substitution.

**中文詳細描述：** 給定羅馬數字算式 A + B = C，檢驗其作為標準羅馬數字是否正確，並將各字母視為算蟲字謎 (Cryptarithm) 判定是否存在唯一解。

**English approach:** Part 1: convert Roman to integer and check A+B=C. Part 2: backtrack over digits 0-9 for distinct Roman letters and count solutions.

**中文解題思路：** 第一部分將羅馬數字轉換為整數驗證等式；第二部分將字母映射至 0-9 進行回溯窮舉，計數是否有唯一解或無解。 ==========================================================================


<a id="uva-186_trip-routing"></a>

### UVa 186 — Trip Routing／最短公路自駕路徑導航

- 原始碼：[186_trip-routing.c](186_trip-routing.c)
- 難度：UVa Star 2
- 演算法：graph, floyd-warshall

**English description:** Given a highway road network with distances and route names, find the shortest driving path between cities and print detailed driving legs.

**中文詳細描述：** 給定包含里程與公路名稱的公路網路，計算兩城市間之最短行車路徑，並依序列印各路段名稱與距離明細。

**English approach:** Map city names to vertex IDs. Run Floyd-Warshall with a next-hop predecessor matrix to reconstruct and print the optimal route.

**中文解題思路：** 以雜湊表將城市名稱映射為整數編號，執行 Floyd-Warshall 全源最短路徑並記錄轉移中繼點，以遞迴重構輸出完整路徑路段。 ==========================================================================


<a id="uva-187_transaction-processing"></a>

### UVa 187 — Transaction Processing／會計借貸平衡與交易日誌處理

- 原始碼：[187_transaction-processing.c](187_transaction-processing.c)
- 難度：UVa Star 1
- 演算法：simulation, finance

**English description:** Given account descriptions and double-entry transaction journals, detect unbalanced transactions and output balancing adjustment entries.

**中文詳細描述：** 給定會計科目表與複式簿記交易紀錄，檢驗每筆交易的借貸總額是否平衡；若不平衡則自動計算並產生懸帳調整分錄。

**English approach:** Group ledger lines by transaction ID. Accumulate signed cents; if net sum != 0, print transaction details and a balancing row to account 999.

**中文解題思路：** 依交易編號分組，以整數「分」累加借貸金額，若借貸代數和不為零，印出該筆交易清單並向 999 號科目補足差額。 ==========================================================================


<a id="uva-188_perfect-hash-cryptography"></a>

### UVa 188 — Perfect Hash: Cryptography／完美雜湊函數常數 C 搜尋

- 原始碼：[188_perfect-hash-cryptography.c](188_perfect-hash-cryptography.c)
- 難度：UVa Star 2
- 演算法：math, hash

**English description:** Find the minimum positive integer constant C for the hash function h(w) = (C / w) % n such that no two words in a given set collide.

**中文詳細描述：** 尋找最小正整數常數 C，使得雜湊函數 h(w) = (C / w) % n 對於集合中所有單詞 w 均不產生碰撞 (完美雜湊)。

**English approach:** Iterative conflict resolution: start C at min(w_i). If collision occurs between w_i and w_j, advance C to min((C/w_i + 1)*w_i, (C/w_j + 1)*w_j).

**中文解題思路：** 衝突導向常數推進法：令 C 初值為單詞編碼之最小值；若單詞 i 與 j 發生碰撞，將 C 更新為兩者向上取整之較小跳步值，直至無碰撞。 ==========================================================================


<a id="uva-189_pascal-program-count-comments"></a>

### UVa 189 — Pascal Program: Count Comments／Pascal 程式語言註解與字串提取

- 原始碼：[189_pascal-program-count-comments.c](189_pascal-program-count-comments.c)
- 難度：UVa Star 1
- 演算法：parsing, string

**English description:** Count the number of comments in a Pascal source program, ignoring comment delimiters inside quoted string literals.

**中文詳細描述：** 解析 Pascal 原始程式碼並統計註解數量，正確處理引號字串內的跳脫與假註解符號 (* 與 { } 語法)。

**English approach:** State machine scanner tracking NORMAL, STRING, and COMMENT states. Distinguish between (* *) and { } Pascal comment styles.

**中文解題思路：** 以狀態機掃描字元流，維護 NORMAL、IN_STRING、IN_COMMENT 三種狀態，遇到 { 或 (* 開啟註解並計數，字串內忽略語法關鍵字。 ==========================================================================


<a id="uva-190_circle-through-three-points"></a>

### UVa 190 — Circle Through Three Points／平面不共線三點外接圓方程式

- 原始碼：[190_circle-through-three-points.c](190_circle-through-three-points.c)
- 難度：UVa Star 2
- 演算法：geometry, math

**English description:** Given three non-collinear 2D points, calculate the circumscribed circle and format its equation in both standard (x-h)^2+(y-k)^2=r^2 and general forms.

**中文詳細描述：** 給定平面上不共線之三點，計算其外接圓圓心 (h, k) 與半徑 r，並輸出標準式與一般式圓方程式。

**English approach:** Find intersection of perpendicular bisectors of segments AB and BC to determine center (h, k), then r = distance to A. Expand general equation.

**中文解題思路：** 求兩線段中垂線之交點確定外接圓圓心 (h, k)，半徑 r 為圓心到任意頂點之距離，代入並展開成一般式 x^2+y^2+cx+dy+e=0。 ==========================================================================


<a id="uva-191_intersection"></a>

### UVa 191 — Intersection／線段與軸對齊矩形相交幾何判定

- 原始碼：[191_intersection.c](191_intersection.c)
- 難度：UVa Star 2
- 演算法：geometry

**English description:** Determine whether a given line segment intersects or lies completely inside an axis-aligned rectangle.

**中文詳細描述：** 判定給定線段是否與軸對齊矩形邊界相交，或線段完全包含在該矩形內部。

**English approach:** Check if either segment endpoint is inside rectangle. If not, test segment intersection with each of the four rectangle edges using cross products.

**中文解題思路：** 首先檢查線段兩端點是否落在矩形內部；若否，則將線段分別與矩形四條邊界線段進行跨立實驗與快速排斥實驗判斷是否相交。 ==========================================================================


<a id="uva-193_graph-coloring"></a>

### UVa 193 — Graph Coloring／無向圖最大獨立集

- 原始碼：[193_graph-coloring.c](193_graph-coloring.c)
- 難度：UVa Star 2
- 演算法：graph, backtracking

**English description:** Color graph vertices black or white such that no two adjacent vertices are both black, maximizing the count of black vertices (Maximum Independent Set).

**中文詳細描述：** 對無向圖頂點進行黑白二染色，相鄰頂點不可同為黑色，求黑色頂點數量的最大值 (最大獨立集) 並輸出其頂點集合。

**English approach:** Backtracking search: at each vertex, try coloring black (if no black neighbor), then try white. Prune if remaining vertices cannot exceed best count.

**中文解題思路：** 回溯搜尋最大獨立集：對每個節點分支嘗試著黑色 (需滿足無鄰居為黑) 與著白色，配合剩餘節點上限剪枝，記錄最大著黑數量頂點集。 ==========================================================================


<a id="uva-194_triangle"></a>

### UVa 194 — Triangle／任意三角形已知三元素解三角形

- 原始碼：[194_triangle.c](194_triangle.c)
- 難度：UVa Star 2
- 演算法：geometry, math

**English description:** Given 3 known sides/angles of a triangle, determine if a valid unique triangle exists and solve for the remaining 3 elements.

**中文詳細描述：** 給定三角形任意 3 個已知元素 (邊長或內角)，判定其能否構成唯一合法三角形並解出其餘 3 個未知元素。

**English approach:** Apply Law of Sines and Law of Cosines to solve known SSS, SAS, ASA, or AAS configurations; handle SSA ambiguous cases.

**中文解題思路：** 利用正弦定理與餘弦定理依序解析 SSS、SAS、ASA 或 AAS 構型，嚴格驗證內角和大於 0 小於 180 度及邊長正值約束。 ==========================================================================


<a id="uva-195_anagram"></a>

### UVa 195 — Anagram／自定義大小寫字母字典序全排列

- 原始碼：[195_anagram.c](195_anagram.c)
- 難度：UVa Star 1
- 演算法：string, sorting, backtracking, permutation

**English description:** Print all permutations of a string without duplicates in custom alphabetical order: 'A' < 'a' < 'B' < 'b' < ...

**中文詳細描述：** 輸出給定字串的所有不重複全排列，依題目規定的自定義字母順序：'A' < 'a' < 'B' < 'b' ... 嚴格排序。

**English approach:** Sort characters with custom comparator, then use next_permutation logic handling duplicate elements cleanly.

**中文解題思路：** 依題目特殊大小寫優先序進行字元排序，接著以遞迴回溯或字典序下一個排列 (next_permutation) 跳過重複字元輸出。 ==========================================================================


<a id="uva-196_spreadsheet"></a>

### UVa 196 — Spreadsheet／電子表格計算 (公式解析與拓撲排序求值)

- 原始碼：[196_spreadsheet.c](196_spreadsheet.c)
- 難度：Medium
- 演算法：dfs, memoization, topological-sort

**English description:** Evaluate an R x C spreadsheet with integer constants and formula cells '=A1+B2+...'.

**中文詳細描述：** 計算含整數常數與加法公式單元格（如 =A1+B2+...）的電子表格各單元格的最終數值。

**English approach:** DFS with memoization: formula evaluation recursively resolves referenced cells. No circular dependencies exist.

**中文解題思路：** 帶記憶化的 DFS：單元格為純數字直接返回；若為公式則解析各引用坐標，遞迴求解相加並記憶化。 ==========================================================================
