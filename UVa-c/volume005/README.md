# UVa Volume 005

本卷收錄 41 份 C 解答，涵蓋 40 個 UVa 題號，以下依題號排序。

<a id="uva-501_black-box"></a>

### UVa 501 — Black Box／黑盒子 (雙堆動態第k小元素)

- 原始碼：[501_black-box.c](501_black-box.c)
- 難度：Medium
- 演算法：data-structures, heap, two-heaps

**English description:** Process ADD(x) and GET commands: GET increases query index i by 1 and returns the i-th smallest element added so far.

**中文詳細描述：** 模擬黑盒子：支援添加元素 ADD(x) 與查詢 GET。每次 GET 使查詢下標 i 加 1 並返回當前第 i 小的元素。

**English approach:** Maintain two heaps: max-heap of size i (holding smallest i elements) and min-heap for remainder. Balance heaps on ADD and GET.

**中文解題思路：** 雙堆積結構：最大堆維護前 i 小的元素，最小堆維護剩餘較大元素。每次 GET 將最小堆頂移入最大堆並返回最大堆頂。 ==========================================================================


<a id="uva-507_jill-rides-again"></a>

### UVa 507 — Jill Rides Again／最佳單車騎行區段 (最大連續子序列和 Kadane)

- 原始碼：[507_jill-rides-again.c](507_jill-rides-again.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, kadane, max-subarray

**English description:** Find contiguous route segment maximizing Jill's niceness sum; break ties by longest segment, then earliest start.

**中文詳細描述：** 求單車路線中風景評價總和最大的連續區段。若有多組最大和，優先選區間長度最長者，再選起點最早者。

**English approach:** Kadane's algorithm tracking (start, end) indices. Update best if current_sum > max_sum or (current_sum == max_sum and length > best_length).

**中文解題思路：** Kadane 演算法擴展：動態維護當前起點。在數值嚴格大於最大值或數值相等且區間跨度更長時更新全局最佳解。 ==========================================================================


<a id="uva-514_rails"></a>

### UVa 514 — Rails／鐵軌調度 (堆疊排列判定)

- 原始碼：[514_rails.c](514_rails.c)
- 難度：UVa Star 1
- 演算法：stack, simulation, data-structures

**English description:** Determine if train coaches arriving in order 1..N can depart in target permutation order via station spur track (stack).

**中文詳細描述：** 判定進站順序為 1 到 N 的火車車廂，能否藉由中轉站 (後進先出堆疊) 調度成指定的出站順序。

**English approach:** Stack simulation: sequentially push incoming cars 1..N. Whenever stack top matches current target coach, pop from stack.

**中文解題思路：** 以堆疊模擬車站軌道：依序推入 1 到 N 車廂，若棧頂車廂恰等於目標排列當前車廂則持續出棧，最終檢查堆疊是否為空。 ==========================================================================


<a id="uva-516_prime-land"></a>

### UVa 516 — Prime Land／質數之國 (質因數分解與 n-1 還原反轉)

- 原始碼：[516_prime-land.c](516_prime-land.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, prime-factorization

**English description:** Given prime factor representation of x, compute x - 1 and output its prime factorization in descending prime order.

**中文詳細描述：** 給定數值 x 的質因數分解表示，計算 x - 1 並將其質因數分解結果按質數由大到小輸出。

**English approach:** Compute x = prod(p_i^e_i). Subtract 1, then factorize x - 1 up to sqrt(x-1). Output factors in descending order.

**中文解題思路：** 累乘算出原數 x，將 x - 1 進行標準質因數分解，依質因數由大到小印出底數與指數。 ==========================================================================


<a id="uva-524_prime-ring-problem"></a>

### UVa 524 — Prime Ring Problem／質數環問題 (回溯法排列搜尋)

- 原始碼：[524_prime-ring-problem.c](524_prime-ring-problem.c)
- 難度：UVa Star 2
- 演算法：backtracking, math, prime

**English description:** Arrange numbers 1..n in a circle starting with 1 such that sum of any two adjacent numbers is a prime.

**中文詳細描述：** 將 1 到 n 圍成一圈 (1 固定在第一位)，使得相鄰兩數之和皆為質數，依字典序輸出所有相異質數環。

**English approach:** Backtracking search: fix 1 at position 0, recursively try unused numbers such that ring[pos-1] + candidate is prime.

**中文解題思路：** 回溯遞迴搜尋：1 固定在位置 0，逐位枚舉未使用的整數，驗證與前一個數相加為質數；走到末位時還須驗證與首位 1 相加為質數。 ==========================================================================


<a id="uva-526_string-distance-and-transform-process"></a>

### UVa 526 — String Distance and Transform Process／字串編輯距離與轉換過程

- 原始碼：[526_string-distance-and-transform-process.c](526_string-distance-and-transform-process.c)
- 難度：Medium
- 演算法：dp, edit-distance

**English description:** Compute Levenshtein distance between two strings and output the exact sequence of Insert, Delete, and Change operations.

**中文詳細描述：** 計算兩字串間的最小編輯距離，並依序輸出具體的插入 (Insert)、刪除 (Delete) 與替換 (Change) 操作序列。

**English approach:** Standard DP table dp[i][j]. Backtrack from (len1, len2) to reconstruct operations, adjusting 1-based output indices dynamically.

**中文解題思路：** 經典編輯距離 DP：dp[i][j] 記錄狀態並記錄操作前驅，從終點回溯還原操作步驟，動態維護字串長度與下標偏移。 ==========================================================================


<a id="uva-529_addition-chains"></a>

### UVa 529 — Addition Chains／加法鏈 (迭代加深搜索 IDA*)

- 原始碼：[529_addition-chains.c](529_addition-chains.c)
- 難度：Hard
- 演算法：ida, backtracking, math

**English description:** Find the shortest addition chain starting with 1 and ending with n where each element is the sum of two previous elements.

**中文詳細描述：** 求以 1 開頭、以 n 結尾的最短加法鏈（鏈中每個數為前面兩個數之和）。

**English approach:** Iterative Deepening A* (IDA*): bound search depth d, prune if a[k] * 2^(d - k) < n.

**中文解題思路：** 迭代加深搜索 (IDA*)：枚舉鏈的長度上限 d，若當前最大數翻倍 (d-k) 次仍小於 n 則強力剪枝。 ==========================================================================


<a id="uva-530_binomial-showdown"></a>

### UVa 530 — Binomial Showdown／二項式係數精準計算

- 原始碼：[530_binomial-showdown.c](530_binomial-showdown.c)
- 演算法：組合數乘除化簡（math, combinatorics）

**English description:** Repeatedly read `n` and `k` and compute the exact binomial coefficient `C(n, k)`. Use the symmetry `C(n, k) = C(n, n-k)` and interleave multiplication with exact division so the factorials never need to be formed. Input ends with `0 0`.

**中文詳細描述：** 每筆輸入 `n`、`k`，要求精確輸出從 `n` 個元素取 `k` 個的組合數。先令 `k = min(k, n-k)`，再依序以 `答案 × (n-i+1) ÷ i` 計算，避免直接建立巨大階乘及不必要的中間值；讀到 `0 0` 時結束。

<a id="uva-531_compromise"></a>

### UVa 531 — Compromise／外交妥協 (單詞級最長共同子序列 LCS)

- 原始碼：[531_compromise.c](531_compromise.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lcs, string

**English description:** Given two texts composed of words, find the Longest Common Subsequence of words and print them.

**中文詳細描述：** 給定兩篇外交報告文字，求單詞層級的最長共同子序列 (LCS)，並輸出共同單詞序列。

**English approach:** 2D LCS dynamic programming on word arrays. Reconstruct common sequence using direction backtrack table.

**中文解題思路：** 以單詞字串作為基本元素進行二維 LCS 動態規劃，並以回溯方向陣列輸出還原的最長共同單詞清單。 ==========================================================================


<a id="uva-532_dungeon-master"></a>

### UVa 532 — Dungeon Master／地牢大師 (3D 空間 BFS 最短路徑)

- 原始碼：[532_dungeon-master.c](532_dungeon-master.c)
- 難度：UVa Star 1
- 演算法：graph, bfs, shortest-path

**English description:** Escape a 3D dungeon (L x R x C). Move in 6 directions (North, South, East, West, Up, Down). Find min minutes to exit.

**中文詳細描述：** 在 L x R x C 的 3D 立體地牢中，由起點 'S' 移動至終點 'E'，每次可沿 6 個方向移動，求逃脫最短分鐘數。

**English approach:** 3D Breadth-First Search (BFS) using queue. Explore 6 neighbor directions, marking visited cells to find shortest distance.

**中文解題思路：** 標準 3D 空間 BFS 走訪：佇列儲存 (層, 列, 行)，朝上下前後左右 6 個相鄰方向擴展，首個抵達終點即為最短步數。 ==========================================================================


<a id="uva-534_frogger"></a>

### UVa 534 — Frogger／青蛙跳石 (最小化最大跳躍距離 Minimax)

- 原始碼：[534_frogger.c](534_frogger.c)
- 難度：UVa Star 2
- 演算法：graph, shortest-path, floyd-warshall, mst

**English description:** Find path between stone 1 and 2 that minimizes the maximum single jump distance (frog distance).

**中文詳細描述：** 青蛙從 1 號石頭跳至 2 號石頭，求所有可能路徑中「單次最大跳躍跨度」的最小值 (Minimax 路徑)。

**English approach:** Floyd-Warshall minimax variant: dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j])).

**中文解題思路：** Floyd-Warshall 變形：距離鬆弛定義為 dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]))，初值為歐式距離。 ==========================================================================


<a id="uva-536_tree-recovery"></a>

### UVa 536 — Tree Recovery／二元樹還原 (前序與中序重構後序走訪)

- 原始碼：[536_tree-recovery.c](536_tree-recovery.c)
- 難度：UVa Star 1
- 演算法：binary-tree, recursion

**English description:** Given preorder and inorder traversals of a binary tree, reconstruct and print postorder traversal.

**中文詳細描述：** 給定二元樹的前序遍歷與中序遍歷字串，遞迴重構二元樹並輸出後序遍歷字串。

**English approach:** Root is pre[0]. Find root index in inorder to divide left and right subtrees. Recurse left, right, then print root.

**中文解題思路：** 前序首字元即為當前樹根；在中序中找到該字元位置即可分割出左子樹與右子樹範圍，遞迴走訪左、右後輸出根結點。 ==========================================================================


<a id="uva-537_artificial-intelligence"></a>

### UVa 537 — Artificial Intelligence?／物理功率、電壓、電流計算

- 原始碼：[537_artificial-intelligence.c](537_artificial-intelligence.c)
- 演算法：字串解析、公式代入（parsing, physics）

**English description:** Each problem statement embeds two known quantities among power `P`, voltage `U`, and current `I`, possibly using metric prefixes `m`, `k`, or `M`. Parse the values, derive the missing quantity from `P = U × I`, and print it with two decimal places and its proper unit.

**中文詳細描述：** 每組輸入是一段文字，其中會出現 `P`（瓦特）、`U`（伏特）、`I`（安培）三項中的兩項，數值可能帶 `m`、`k`、`M` 倍率前綴。解析並換算成基本單位後，用 `P = U × I` 求第三項；按案例格式輸出未知量、兩位小數與正確單位。

<a id="uva-537_artificial-intelligence-pr"></a>

### UVa 537 — Artificial Intelligence?／物理功率、電壓、電流計算

- 原始碼：[537_artificial-intelligence-pr.c](537_artificial-intelligence-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, parsing, physics

**English description:** Parse two quantities among P (power), U (voltage), I (current), and compute the third via P = U*I.

**中文詳細描述：** 解析文本中的 P, U, I 三項物理量中的兩項，由 P = U * I 求出第三項。

**English approach:** String parsing with prefix multipliers (m, k, M).

**中文解題思路：** 提取帶有單位（W, V, A）的數值與乘數後計算求解。 ==========================================================================


<a id="uva-539_the-settlers-of-catan"></a>

### UVa 539 — The Settlers of Catan／卡坦島開拓者 (圖中最長無重複邊簡單路徑)

- 原始碼：[539_the-settlers-of-catan.c](539_the-settlers-of-catan.c)
- 難度：UVa Star 1
- 演算法：graph, dfs, backtracking

**English description:** Find the length of the longest path in an undirected graph such that no edge is traversed more than once.

**中文詳細描述：** 在無向圖中尋找一條最長路徑，要求每條邊最多只能經過一次 (節點可重複造訪)，求最大路徑長度。

**English approach:** DFS backtracking from each vertex. Mark traversed edges as visited, explore unvisited adjacent edges, take maximum depth.

**中文解題思路：** 從圖中每個節點分別進行深度優先搜尋 (DFS)，遞迴走訪未造訪的邊並標記已用，搜尋結束後回溯，取最大走訪邊數。 ==========================================================================


<a id="uva-540_team-queue"></a>

### UVa 540 — Team Queue／團隊佇列 (佇列之佇列模擬)

- 原始碼：[540_team-queue.c](540_team-queue.c)
- 難度：UVa Star 2
- 演算法：data-structures, queue, simulation

**English description:** Simulate Team Queue: when an element arrives, it joins its team's sub-queue if teammates are already in queue.

**中文詳細描述：** 模擬團隊佇列：新元素進入佇列時，若其所屬團隊已有人在佇列中，則插隊排在該團隊同伴身後；否則排在隊列最末端。

**English approach:** Maintain a master queue of teams and an individual queue for each team. Lookup team ID via direct table.

**中文解題思路：** 維護主佇列 (記錄隊伍排隊順序) 與各團隊子佇列。以陣列查表得知各編號對應的隊伍 ID，完成 O(1) 插隊與出隊。 ==========================================================================


<a id="uva-541_error-correction"></a>

### UVa 541 — Error Correction／二維奇偶校驗矩陣修正

- 原始碼：[541_error-correction.c](541_error-correction.c)
- 演算法：行列奇偶統計（matrix, parity check）

**English description:** Given an `N × N` binary matrix, verify that every row and column has an even sum. Print `OK` if all parities are even, identify the one-based cell whose flip would fix the matrix when exactly one row and one column are odd, or print `Corrupt` otherwise. Input ends with `N = 0`.

**中文詳細描述：** 每組輸入 `N × N` 的 0/1 矩陣，檢查每一列與每一行的元素和是否皆為偶數。若全部通過就輸出 `OK`；若恰有一個奇數列與一個奇數行，翻轉兩者交點即可修復，輸出該一基座標；其他情況輸出 `Corrupt`。`N = 0` 結束。

<a id="uva-542_france_98"></a>

### UVa 542 — France '98／1998 世界盃淘汰賽奪冠機率

- 原始碼：[542_france_98.c](542_france_98.c)
- 難度：Medium
- 演算法：probability, dynamic-programming, tournament

**English description:** Given match winning probabilities between all pairs of 16 teams, compute each team's probability of winning the tournament.

**中文詳細描述：** 給定 16 支球隊兩兩對戰的勝率矩陣，計算每支球隊最終贏得世界盃冠軍的機率。

**English approach:** DP over tournament rounds 1 to 4. For round r, team i can play against team j iff (i >> (r-1)) ^ 1 == (j >> (r-1)).

**中文解題思路：** 樹狀錦標賽動態規劃：在第 r 輪，隊伍 i 的對手為其所屬長度 2^r 的子區間內另一半的所有可能勝出者 j，累加條件機率。 ==========================================================================


<a id="uva-543_goldbachs-conjecture"></a>

### UVa 543 — Goldbach's Conjecture／哥德巴赫猜想

- 原始碼：[543_goldbachs-conjecture.c](543_goldbachs-conjecture.c)
- 演算法：埃拉托斯特尼篩法（number theory, prime sieve）

**English description:** For each even integer `n`, find two odd primes `a` and `b` with `n = a + b`. The required search starts with the smallest possible `a`, which produces the largest difference `b - a`; print the decomposition, or the failure sentence if none is found. Input ends with zero.

**中文詳細描述：** 每筆輸入一個偶數 `n`，尋找兩個奇質數 `a`、`b` 使 `n = a + b`。先用埃氏篩建立質數表，再由最小奇質數開始測試 `n-a`，因此找到的第一組同時使 `b-a` 最大；輸出等式，若找不到則輸出題目指定的失敗訊息，輸入 0 結束。

<a id="uva-544_heavy-cargo"></a>

### UVa 544 — Heavy Cargo／重載卡車貨運 (最大負載瓶頸路徑 Maximin)

- 原始碼：[544_heavy-cargo.c](544_heavy-cargo.c)
- 難度：UVa Star 2
- 演算法：graph, mst, dijkstra, shortest-path

**English description:** Find path between city A and B that maximizes minimum bridge weight limit (bottleneck capacity).

**中文詳細描述：** 求兩城市間貨運卡車能通行的最大載重噸位 (即使得路徑上的最小承重橋樑噸位最大化，Maximin 問題)。

**English approach:** Maximum Spanning Tree via Kruskal or modified Dijkstra / Floyd-Warshall maximizing the bottleneck edge.

**中文解題思路：** 以 Kruskal 演算法求最大生成樹 (邊權由大到小排序)，或以類似 Dijkstra 演算法鬆弛更新 bottleneck 最大值。 ==========================================================================


<a id="uva-548_tree"></a>

### UVa 548 — Tree／中序與後序重構二元樹 (尋找最小權重路徑葉節點)

- 原始碼：[548_tree.c](548_tree.c)
- 難度：UVa Star 2
- 演算法：binary-tree, recursion, dfs

**English description:** Given inorder and postorder of weighted binary tree, find leaf node with minimum root-to-leaf path sum.

**中文詳細描述：** 給定二元樹的中序與後序遍歷，重構二元樹並找出從根結點到葉節點路徑權重和最小的葉節點數值。

**English approach:** Postorder last element is root. Find root in inorder to split subtrees. DFS traverse to find leaf with min cumulative sum.

**中文解題思路：** 後序遍歷末字元為根，於中序中切分左右子樹以遞迴構樹。DFS 走訪計算根到葉結點路徑和，遇平手取葉結點值較小者。 ==========================================================================


<a id="uva-555_bridge-hands"></a>

### UVa 555 — Bridge Hands／橋牌發牌模擬與手牌排序

- 原始碼：[555_bridge-hands.c](555_bridge-hands.c)
- 難度：UVa Star 1
- 演算法：simulation, card-game, sorting

**English description:** Simulate bridge card dealing starting after dealer (N, E, S, W) and sort each player's 13 cards by suit (C, D, S, H) and rank (2..A).

**中文詳細描述：** 模擬 52 張橋牌順時針發牌流程，並將四位玩家手牌按花色 (梅花 C < 方塊 D < 黑桃 S < 紅心 H) 與點數 (2..9, T, J, Q, K, A) 排序輸出。

**English approach:** Deal cards clockwise in round-robin order. Sort each hand using custom comparator according to bridge suit and rank weights.

**中文解題思路：** 依照發牌者下一位開始順時針分發 52 張牌至四位玩家，為每張牌賦予唯一整數權重後進行升序排序輸出。 ==========================================================================


<a id="uva-556_amazing"></a>

### UVa 556 — Amazing／走迷宮 (右手摸牆法則步數統計)

- 原始碼：[556_amazing.c](556_amazing.c)
- 難度：Medium
- 演算法：simulation, maze, grid

**English description:** Simulate a robot traversing a maze following the right-hand wall rule until returning to start.

**中文詳細描述：** 模擬機器人以右手貼牆法則在迷宮中行走直到返回起點與初始朝向，統計各空格被拜訪的次數分佈。

**English approach:** Robot starts at bottom-left facing East. Turn right if wall absent on right, otherwise move straight or turn left.

**中文解題思路：** 機器人初始在左下角面朝東，優先嘗試向右轉，若右方有牆則嘗試前進，受阻則左轉，統計 0..4 次拜訪格數。 ==========================================================================


<a id="uva-558_wormholes"></a>

### UVa 558 — Wormholes／蟲洞時空倒流 (負權迴路 Bellman-Ford 檢測)

- 原始碼：[558_wormholes.c](558_wormholes.c)
- 難度：UVa Star 2
- 演算法：graph, bellman-ford, negative-cycle

**English description:** Determine if directed graph with negative edge weights contains a negative-weight cycle (time travel).

**中文詳細描述：** 在含有負權邊的有向圖中，判定是否存在負權迴路使得旅行者能回到過去 (Bellman-Ford 演算法)。

**English approach:** Run Bellman-Ford algorithm for n - 1 iterations. If any edge can still be relaxed on the n-th iteration, a negative cycle exists.

**中文解題思路：** 執行 n - 1 次 Bellman-Ford 邊鬆弛操作；若在第 n 次仍能成功鬆弛，代表圖中存在負權迴路。 ==========================================================================


<a id="uva-562_dividing-coins"></a>

### UVa 562 — Dividing coins／分金幣 (0/1 背包子集和最小差劃分)

- 原始碼：[562_dividing-coins.c](562_dividing-coins.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, knapsack

**English description:** Divide m coins between two people such that the difference between the two totals is minimized.

**中文詳細描述：** 將 m 枚不同面額的金幣分給兩人，求兩人所分得金幣總價值差額的最小值 (0/1 背包容量為 Sum/2)。

**English approach:** 0/1 Knapsack: find maximum sum <= total_sum / 2. Minimal difference is total_sum - 2 * max_sub_sum.

**中文解題思路：** 計算金幣總和 S，背包容量設為 S / 2 執行 0/1 背包動態規劃，最接近半數的最佳子集和為 S'，最小差值即 S - 2*S'。 ==========================================================================


<a id="uva-567_risk"></a>

### UVa 567 — Risk／戰國風雲 (BFS 最短路徑走訪)

- 原始碼：[567_risk.c](567_risk.c)
- 難度：UVa Star 1
- 演算法：graph, bfs, shortest-path

**English description:** Given board graph of 20 countries, find minimum armies needed to move between country pairs (BFS shortest path).

**中文詳細描述：** 在 20 個國家的世界地圖圖形中，求從出發國至目的國所需經過的最少邊數 (BFS 最短路徑)。

**English approach:** Breadth-First Search (BFS) or Floyd-Warshall across 20 nodes with unit edge weights.

**中文解題思路：** 因圖中頂點僅 20 個且邊權皆為 1，直接以 BFS 走訪或 Floyd-Warshall 預先算好所有點對最短距離。 ==========================================================================


<a id="uva-568_just-the-facts"></a>

### UVa 568 — Just the Facts／階乘末尾最後一個非零數字

- 原始碼：[568_just-the-facts.c](568_just-the-facts.c)
- 演算法：階乘尾零消除、模運算（number theory, factorial）

**English description:** For each `N`, determine the rightmost nonzero decimal digit of `N!`. During repeated multiplication, remove trailing zeroes and retain only enough low digits to keep the value bounded, then print `N` and the digit in the required aligned format.

**中文詳細描述：** 每行輸入 `N`，要求 `N!` 的十進位表示中最右邊非 0 的數字。逐次乘入 1 到 `N`，每步把末尾 0 除去並保留適量低位以避免數值膨脹；最後取個位數，按題目規定對齊輸出 `N -> 答案`。

<a id="uva-571_jugs"></a>

### UVa 571 — Jugs／倒水問題

- 原始碼：[571_jugs.c](571_jugs.c)
- 難度：Medium
- 演算法：bfs, state-machine, simulation

**English description:** Given two jugs of capacity Ca and Cb and target N, output a sequence of fill, empty, and pour operations to measure N liters in jug B.

**中文詳細描述：** 給定容量為 Ca 與 Cb 的水壺及目標水量 N，求裝滿、倒空、互倒等操作序列，使 B 壺內恰有 N 升水。

**English approach:** State BFS (a, b) with 6 transitions: fill A, fill B, empty A, empty B, pour A->B, pour B->A. Trace parent pointers.

**中文解題思路：** 狀態圖 BFS：記錄 (a, b) 狀態與父節點路徑，進行 6 種水壺轉換操作，直至 b == N 時回溯操作步驟。 ==========================================================================


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

<a id="uva-574_sum-it-up"></a>

### UVa 574 — Sum It Up／子集總和全部組合列舉 (剪枝與去重回溯)

- 原始碼：[574_sum-it-up.c](574_sum-it-up.c)
- 難度：UVa Star 2
- 演算法：backtracking, recursion, subset-sum

**English description:** Find all unique combinations of a multiset of integers that sum up to target t, outputting in non-increasing order.

**中文詳細描述：** 給定目標和 t 與整數多重集，回溯列舉出所有總和恰為 t 的不重複子集，並按降序排列輸出。

**English approach:** Backtracking recursion with duplicate skipping: if adjacent elements are identical, only pick the first occurrence in the current branch.

**中文解題思路：** 對陣列由大到小排序後回溯搜尋。若遇到相鄰相同數值且未被選中，則跳過避免輸出重複相同的加法表達式。 ==========================================================================


<a id="uva-575_skew-binary"></a>

### UVa 575 — Skew Binary／斜二進位制轉十進位

- 原始碼：[575_skew-binary.c](575_skew-binary.c)
- 演算法：位權累加（math, base conversion）

**English description:** Convert each skew-binary numeral to decimal. Counting positions from one at the right, a digit at position `k` has weight `2^k - 1`; sum every digit times its weight and print the result. The input string `0` terminates processing.

**中文詳細描述：** 每行是一個斜二進位字串，從最右位開始編號 1，第 `k` 位權重為 `2^k - 1`。將每位數字值乘上對應權重後相加，即得十進位答案並逐行輸出；當整行只有 `0` 時結束。

<a id="uva-576_haiku-review"></a>

### UVa 576 — Haiku Review／日本俳句 5-7-5 音節規則審查

- 原始碼：[576_haiku-review.c](576_haiku-review.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Determine if a 3-phrase Haiku poem separated by '/' conforms to the 5-7-5 syllable structure, or report the index of the first incorrect phrase.

**中文詳細描述：** 審查以斜線 '/' 分隔的三段式日本俳句是否符合 5-7-5 音節規範；若不符合則輸出首個出錯之段落編號 (1, 2, 3)；若正確輸出 'Y'。

**English approach:** Count vowel sequences (consecutive vowels count as 1 syllable: a, e, i, o, u, y). Compare counts of the 3 phrases with 5, 7, 5.

**中文解題思路：** 以母音字母 (a, e, i, o, u, y) 計算音節數 (連續母音合併為 1 個音節)，分別檢查三段之音節是否恰為 5, 7, 5。 ==========================================================================


<a id="uva-579_clock-hands"></a>

### UVa 579 — Clock Hands／時鐘時針與分針夾角

- 原始碼：[579_clock-hands.c](579_clock-hands.c)
- 演算法：角度計算（math, geometry）

**English description:** For each time `H:M`, compute the smaller angle between the analog clock's hour and minute hands. The hour hand advances continuously as minutes pass, so compare `30H + 0.5M` with `6M`, fold angles above 180 degrees, and print three decimal places. Input ends with `0:00`.

**中文詳細描述：** 每筆輸入格式為 `H:M` 的時間。分針角度為 `6M`，時針除了每小時 30 度外還會隨分鐘前進，因此角度為 `30H + 0.5M`；兩者差的絕對值若超過 180 度就以 360 減去它。輸出較小夾角至小數點後三位，`0:00` 結束。

<a id="uva-580_critical-mass"></a>

### UVa 580 — Critical Mass／臨界質量 (禁忌模式計數DP)

- 原始碼：[580_critical-mass.c](580_critical-mass.c)
- 難度：Medium
- 演算法：dp, combinatorics

**English description:** Find the number of stacks of n uranium (U) and lead (L) cubes that contain at least 3 consecutive uranium cubes (dangerous).

**中文詳細描述：** 求長度為 n 由鈾 (U) 與鉛 (L) 方塊構成的堆疊中，包含至少 3 個連續鈾方塊的排列數。

**English approach:** Calculate safe stacks safe[n] (no 3 consecutive U): safe[n] = safe[n-1] + safe[n-2] + safe[n-3]. Dangerous = 2^n - safe[n].

**中文解題思路：** 先求安全堆疊數 safe[n]（無連續 3 個 U）：safe[n] = safe[n-1] + safe[n-2] + safe[n-3]。危險數即為 2^n - safe[n]。 ==========================================================================


<a id="uva-583_prime-factors"></a>

### UVa 583 — Prime Factors／整數質因數分解輸出

- 原始碼：[583_prime-factors.c](583_prime-factors.c)
- 演算法：試除法（number theory, prime factorization）

**English description:** Factor each nonzero signed integer into prime factors and print an equality joined by `x` symbols. For a negative input, emit `-1` as the first factor and factorize its absolute value; repeated prime factors must be printed repeatedly. Input ends with zero.

**中文詳細描述：** 每行輸入一個非 0 整數 `N`，輸出 `N = f1 x f2 x ...` 的完整質因數分解，相同質因數須依次重複列出。若 `N` 為負數，先輸出因數 `-1`，再分解其絕對值；以從小到大的試除法取出因數，最後剩餘大於 1 的值亦為質數。輸入 0 結束。

<a id="uva-584_bowling"></a>

### UVa 584 — Bowling／保齡球計分系統模擬

- 原始碼：[584_bowling.c](584_bowling.c)
- 難度：Medium
- 演算法：simulation, rule-based

**English description:** Calculate total bowling score from a roll sequence with strikes ('X'), spares ('/'), and numeric pinfall counts.

**中文詳細描述：** 依據標準保齡球 10 格規則計算全中 ('X')、補中 ('/') 與一般擲球的總得分。

**English approach:** Parse sequence into individual roll pinfall values. For each of the first 10 frames: add frame score, add next 2 rolls if strike, add next 1 roll if spare.

**中文解題思路：** 將擊球序列轉為每次擊倒瓶數數組。計算前 10 格分數：Strike 加後兩次投球分，Spare 加後一次投球分，其餘為兩球相加。 ==========================================================================


<a id="uva-587_theres-treasure-everywhere"></a>

### UVa 587 — There's treasure everywhere!／到處都是寶藏！(二維羅盤方位向量累加)

- 原始碼：[587_theres-treasure-everywhere.c](587_theres-treasure-everywhere.c)
- 難度：UVa Star 1
- 演算法：geometry, math, parsing

**English description:** Follow navigation directions (N, NE, E, SE, S, SW, W, NW) with steps to find final (x, y) coordinates and Euclidean distance.

**中文詳細描述：** 依羅盤 8 方位步數 (正向為 step，斜向各分量為 step / sqrt(2)) 累計二維位移向量，求寶藏最終座標與直線距離。

**English approach:** Vector accumulation: diagonal steps contribute step / sqrt(2) to both x and y axes.

**中文解題思路：** 解析步數與方位字串，正向直接增減座標，斜向各軸增減 step * sqrt(0.5)，最後以歐幾里得幾何距離公式求解。 ==========================================================================


<a id="uva-591_box-of-bricks"></a>

### UVa 591 — Box of Bricks／積木柱高度平攤

- 原始碼：[591_box-of-bricks.c](591_box-of-bricks.c)
- 演算法：平均值、差額加總（math, array）

**English description:** Given the heights of several stacks containing a divisible total number of bricks, move individual bricks until every stack has the same height. Compute the minimum number of moved bricks and print it with the set number in the specified report format. A stack count of zero terminates input.

**中文詳細描述：** 每組輸入積木柱數量與各柱高度，總積木數保證能平均分配。先算目標平均高度；所有高於平均的柱子必須搬出的超額積木總數，正是達成等高所需的最少搬移次數。按案例編號輸出 `The minimum number of moves is ...`，柱數 0 時結束。

<a id="uva-594_one-little-two-little-three-little-endians"></a>

### UVa 594 — One Little, Two Little, Three Little Endians／大端序與小端序 32位元整數轉換

- 原始碼：[594_one-little-two-little-three-little-endians.c](594_one-little-two-little-three-little-endians.c)
- 難度：UVa Star 1
- 演算法：bit-manipulation

**English description:** Convert 32-bit signed integer between little-endian and big-endian byte orders.

**中文詳細描述：** 將 32 位元有號整數的 4 個 Byte 順序反轉 (在小端序與大端序之間相互轉換)。

**English approach:** Bitwise masking and shifting: ((x & 0xFF) << 24) | ((x & 0xFF00) << 8) | ((x >> 8) & 0xFF00) | ((x >> 24) & 0xFF).

**中文解題思路：** 位元運算遮罩與移位：將 4 個位元組分別位移 24、8、-8、-24 位元進行 OR 組合。 ==========================================================================


<a id="uva-599_the-forrest-for-the-trees"></a>

### UVa 599 — The Forrest for the Trees／樹與橡果 (並查集連通分支與孤立點計數)

- 原始碼：[599_the-forrest-for-the-trees.c](599_the-forrest-for-the-trees.c)
- 難度：UVa Star 1
- 演算法：graph, dsu, tree

**English description:** Given edge list and isolated nodes, count how many trees (size >= 2) and how many acorns (isolated vertices) exist.

**中文詳細描述：** 給定無環森林的邊與頂點列表，計算其中由 2 個以上節點構成的「樹木」數量與單獨 1 個節點的「橡果」數量。

**English approach:** Disjoint Set Union (DSU) or formula: Trees = (Vertices with degree > 0) - Edges. Acorns = Vertices with degree == 0.

**中文解題思路：** 無環圖性質：由大於 1 個節點的樹構成的分支數 = (有邊連接的頂點數) - 邊數；橡果即度數為 0 的獨立頂點數。 ==========================================================================
