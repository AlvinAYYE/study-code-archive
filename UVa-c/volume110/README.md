# UVa Volume 110

本卷收錄 23 份 C 解答，涵蓋 23 個 UVa 題號，以下依題號排序。

<a id="uva-11000_bee"></a>

### UVa 11000 — Bee／蜜蜂王國繁衍 (費氏數列 DP 規律)

- 原始碼：[11000_bee.c](11000_bee.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, math, fibonacci

**English description:** Compute number of male bees and total bees in year N given reproduction biology rules.

**中文詳細描述：** 公蜂生下一公一母，母蜂只生一公，母蜂不死。求第 N 年時公蜂數量與全部蜜蜂總數 (公蜂為 F(N+2) - 1)。

**English approach:** Dynamic programming: male[i] = male[i-1] + female[i-1], female[i] = male[i-1] + 1. Males sequence is Fibonacci variant.

**中文解題思路：** 動態規劃推導：第 i 年公蜂數等於前一年總蜂數，母蜂數等於前一年公蜂數 + 1。公蜂數 = F(i+2) - 1。 ==========================================================================


<a id="uva-11001_necklace"></a>

### UVa 11001 — Necklace／項鍊 (黏土製珠最大長度)

- 原始碼：[11001_necklace.c](11001_necklace.c)
- 難度：Easy
- 演算法：math, calculus, extreme-value

**English description:** Given total clay volume V and threshold volume V_0, divide into b identical beads of volume V/b. Bead diameter D = 0.3 * sqrt(V/b - V_0). Maximize total length b * D.

**中文詳細描述：** 將體積為 V 的黏土分為 b 顆珠子（每顆體積 V/b），珠子直徑 D = 0.3 * sqrt(V/b - V_0)，求使項鍊總長度 b * D 最大的劃分數 b。

**English approach:** Total length squared f(b) = b^2 * (V/b - V_0) = b*V - b^2 * V_0. Quadratic maximum occurs at b = V / (2 * V_0). Check tie/ambiguity.

**中文解題思路：** 總長度平方為二次函數 f(b) = b*V - b^2 * V_0，在 b = V / (2 * V_0) 處取極值，檢查左右整數點及相等無效解（若並列則輸出 0）。 ==========================================================================


<a id="uva-11003_boxes"></a>

### UVa 11003 — Boxes／箱子堆疊 (重量與承重極限DP)

- 原始碼：[11003_boxes.c](11003_boxes.c)
- 難度：Medium
- 演算法：dp, knapsack, lis

**English description:** Stack boxes of given weights and load capacities from top to bottom such that each box supports the total weight of all boxes above it. Maximize count.

**中文詳細描述：** 依順序自頂向下疊放箱子，每隻箱子所承載的上方箱子總重量不可超過其負重上限，求最多能疊放的箱子數量。

**English approach:** DP state dp[w] = maximum number of boxes stacked with total weight w. For each box from top to bottom, update dp[w + weight[i]] = max(dp[w] + 1) for w <= load[i].

**中文解題思路：** 動態規劃：dp[w] 表示當前上方總重為 w 時最多能堆疊的箱子數。對每隻箱子，在 w <= load 時更新 dp[w + weight] = max(dp[w] + 1)。 ==========================================================================


<a id="uva-11005_cheapest-base"></a>
### UVa 11005 — Cheapest Base／最便宜的進位制

- 原始碼：[11005_cheapest-base.c](11005_cheapest-base.c)
- 演算法：進位轉換、成本枚舉（Base Conversion, Enumeration）

**English description:**

The input assigns a printing cost to each digit value from 0 to 35, followed by query integers. For every query, evaluate its representation in each base from 2 through 36 and output all bases having the minimum total digit cost.

**中文詳細描述：**

每組資料先給數值 0 到 35 各自的印刷成本，再給若干待查整數。對每個整數枚舉 2 到 36 進位，反覆取餘數以加總每一位的成本，找出最低成本並輸出所有同樣達到最低值的進位制。

<a id="uva-11015_05-2-rendezvous"></a>

### UVa 11015 — 05-2 Rendezvous／聚會地點選址 (全源最短路徑中心點)

- 原始碼：[11015_05-2-rendezvous.c](11015_05-2-rendezvous.c)
- 難度：Easy
- 演算法：graph, floyd-warshall

**English description:** Find the person's location to hold a rendezvous party such that the sum of travel distances of all friends is minimized.

**中文詳細描述：** 求使所有朋友前往集合地點的總路程之和最小的聚會成員所在位置。

**English approach:** Floyd-Warshall all-pairs shortest path. Compute sum of distances from all friends to each candidate location, pick minimum.

**中文解題思路：** 以 Floyd-Warshall 演算法求全源最短路徑，計算各候選點到所有其他點的最短距離總和，取總和最小者。 ==========================================================================


<a id="uva-11029_leading-and-trailing"></a>

### UVa 11029 — Leading and Trailing／前三位與後三位數字 (快速冪與對數)

- 原始碼：[11029_leading-and-trailing.c](11029_leading-and-trailing.c)
- 難度：Medium
- 演算法：math, fast-exponentiation, logarithms

**English description:** Find the first 3 digits and the last 3 digits of n^k.

**中文詳細描述：** 給定底數 n 與指數 k，求 n^k 的前三位數字與後三位數字。

**English approach:** Trailing: fast modular exponentiation n^k mod 1000. Leading: k * log10(n) = int_part + frac_part, leading digits = floor(10^(frac_part + 2)).

**中文解題思路：** 後三位：快速冪計算 n^k mod 1000。前三位：利用對數取小數部分 frac = fmod(k * log10(n), 1.0)，前三位為 floor(pow(10, frac + 2))。 ==========================================================================


<a id="uva-11034_ferry-loading-iv"></a>

### UVa 11034 — Ferry Loading IV／渡輪載運雙岸排隊橫渡次數

- 原始碼：[11034_ferry-loading-iv.c](11034_ferry-loading-iv.c)
- 難度：UVa Star 2
- 演算法：queue, greedy, simulation

**English description:** Given ferry length L meters and cars queuing at left and right banks, find minimum river crossings to transport all cars.

**中文詳細描述：** 給定長度 L 公尺的渡輪與左右兩岸各自排隊的車輛長度，求運送完所有車輛所需之最少渡河次數。

**English approach:** Two FIFO queues for left and right banks. Greedily load cars from current bank until capacity L is filled. Cross river and switch bank.

**中文解題思路：** 以兩組佇列模擬左右岸等候車輛，每次在當前岸依序盡量裝載車輛直至長度接近 L，渡河至對岸並更換停靠岸。 ==========================================================================


<a id="uva-11039_building-designing"></a>

### UVa 11039 — Building designing／大樓設計

- 原始碼：[11039_building-designing.c](11039_building-designing.c)
- 難度：Easy
- 演算法：greedy, sorting

**English description:** Construct a tower of maximum floors with alternating colors (positive = blue, negative = red) of strictly decreasing absolute sizes.

**中文詳細描述：** 用大小遞減且紅藍兩色交替的樓層（正數為藍，負數為紅）堆疊出最高的大樓。

**English approach:** Sort floors by absolute value descending. Greedily take floor if its color sign differs from previous chosen floor.

**中文解題思路：** 將所有樓層按絕對值降序排序，貪心挑選與上一層顏色符號相反的樓層，計算最多樓層數。 ==========================================================================


<a id="uva-11040_add-bricks-in-the-wall"></a>

### UVa 11040 — Add bricks in the wall／牆面磚塊補全

- 原始碼：[11040_add-bricks-in-the-wall.c](11040_add-bricks-in-the-wall.c)
- 難度：Easy
- 演算法：math, simulation

**English description:** A triangular wall of 9 rows has bricks satisfying brick[r][c] = brick[r+1][c] + brick[r+1][c+1]. Fill missing bricks given odd rows.

**中文詳細描述：** 9 層三角形磚牆滿足每塊磚數值等於下方兩相鄰磚之和，已知奇數層磚塊數值，補全所有未知磚塊。

**English approach:** Using 3 known bricks in a 2-level triangle (top, bottom-left, bottom-right): bottom-mid = (top - b_left - b_right) / 2. Then propagate upwards.

**中文解題思路：** 對於頂部已知磚 A 與下方間隔已知的兩磚 B, C，中間磚為 (A - B - C) / 2，依此逐層推算並向上加總補齊。 ==========================================================================


<a id="uva-11044_searching-for-nessy"></a>

### UVa 11044 — Searching for Nessy／搜尋尼斯水怪 (聲納雷達網格覆蓋)

- 原始碼：[11044_searching-for-nessy.c](11044_searching-for-nessy.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Cover an n x m grid with 3 x 3 sonars avoiding edges. Find minimum sonars needed.

**中文詳細描述：** 在 n x m 的湖泊網格中安裝 3x3 聲納 (邊界一圈不需覆蓋)，求覆蓋全湖所需的最少聲納數量。

**English approach:** Formula: (n / 3) * (m / 3).

**中文解題思路：** 網格整除覆蓋公式：有效內部區域為 (n-2)x(m-2)，每個聲納能監控 3x3，最少所需數量為 (n / 3) * (m / 3)。 ==========================================================================


<a id="uva-11045_my-t-shirt-suits-me"></a>

### UVa 11045 — My T-shirt suits me／衣服尺碼分配 (二分圖最大匹配)

- 原始碼：[11045_my-t-shirt-suits-me.c](11045_my-t-shirt-suits-me.c)
- 難度：Medium
- 演算法：bipartite-matching, max-flow

**English description:** Distribute N shirts equally among 6 sizes (N/6 each) to M volunteers who each accept 2 specific sizes.

**中文詳細描述：** 有 6 種尺寸的 T-shirt 共 N 件（每種尺寸 N/6 件），分配給 M 位志工（每位有 2 種合身尺寸），判定是否能全員滿足。

**English approach:** Model as Maximum Bipartite Matching: create N/6 nodes for each size (or network flow), run matching for M volunteers.

**中文解題思路：** 二分圖匹配：將 6 種尺碼各自複製 N/6 份作為供給節點，對 M 名志工尋求最大二分匹配，判斷匹配數是否為 M。 ==========================================================================


<a id="uva-11054_wine-trading-in-gergovia"></a>

### UVa 11054 — Wine trading in Gergovia／格爾戈維亞葡萄酒交易最小運輸勞動量

- 原始碼：[11054_wine-trading-in-gergovia.c](11054_wine-trading-in-gergovia.c)
- 難度：UVa Star 1
- 演算法：greedy

**English description:** N inhabitants on a street want to buy (>0) or sell (<0) wine (sum = 0). Moving 1 unit of wine 1 house costs 1 work unit. Find minimum total work.

**中文詳細描述：** 一條街上 N 戶人家各自買進 (>0) 或賣出 (<0) 葡萄酒 (總需供平衡為 0)，每運送 1 桶酒 1 戶距離耗費 1 單位工作量，求最小總工作量。

**English approach:** Prefix sum tracking: moving wine between prefixes requires sum of absolute values of running net balances abs(prefix_sum).

**中文解題思路：** 貪婪前綴和法：相鄰房屋間必須流動的葡萄酒量恰等於前綴供需代數和，總勞動量即為 sum(abs(prefix_sum[i]))。 ==========================================================================


<a id="uva-11057_exact-sum"></a>

### UVa 11057 — Exact Sum／精準買書金額配對 (雙指標差值最小化)

- 原始碼：[11057_exact-sum.c](11057_exact-sum.c)
- 難度：UVa Star 1
- 演算法：two-pointers, sorting, binary-search

**English description:** Find pair of book prices summing to M with minimum difference between prices.

**中文詳細描述：** 從書籍價格清單中挑選兩本書，總價格恰等於 M，且兩本書價差最小 (排序後雙指標搜尋)。

**English approach:** Sort array. Use two pointers (left=0, right=n-1). When sum == M, update best pair and advance left.

**中文解題思路：** 將書籍價格升序排序，左右雙指標由兩端向中間逼近。和等於 M 時記錄最佳配對，逼近至相遇即保證價差最小。 ==========================================================================


<a id="uva-11059_maximum-product"></a>
### UVa 11059 — Maximum Product／最大乘積

- 原始碼：[11059_maximum-product.c](11059_maximum-product.c)
- 演算法：連續區間枚舉（Dynamic Programming, Brute Force）

**English description:**

For each sequence of integers, find the largest product among all non-empty contiguous subsequences. If no positive product is obtained, the reported result is zero; output it with the case number.

**中文詳細描述：**

每組輸入是一串整數，要在所有非空的連續子序列中找出最大乘積。實作從每個起點向右逐步累乘並更新最大值；若所有乘積皆不能使初始答案 0 變大，就輸出 0，並附上案例編號。

<a id="uva-11060_beverages"></a>

### UVa 11060 — Beverages／飲品偏好偏序關係拓撲排序

- 原始碼：[11060_beverages.c](11060_beverages.c)
- 難度：UVa Star 2
- 演算法：graph, topological-sort

**English description:** Given N beverages in original input order and precedence rules, output a legal drinking sequence respecting priority (Kahn's topological sort).

**中文詳細描述：** 給定飲料初始偏好順序與飲用先後依賴關係，輸出滿足依賴約束且優先維持原輸入順序之合法飲用序列 (Kahn 拓撲排序)。

**English approach:** Kahn's algorithm using in-degree array. Repeatedly pick the smallest-index available node with in-degree 0.

**中文解題思路：** 維護入度陣列，每輪挑選入度為 0 且在原輸入中編號最小的節點加入序列並扣減相鄰節點之入度。 ==========================================================================


<a id="uva-11062_andys-second-dictionary"></a>

### UVa 11062 — Andy's Second Dictionary／安迪的第二個字典 (連字號換行處理)

- 原始碼：[11062_andys-second-dictionary.c](11062_andys-second-dictionary.c)
- 難度：Easy
- 演算法：string, parsing, hash-set

**English description:** Extract unique words in alphabetical order from text where hyphen at end of line indicates word continuation onto next line.

**中文詳細描述：** 從文字中提取所有相異單字並按字典序輸出，行末連字號 '-' 表示單字跨行延續未結束。

**English approach:** Process characters: if hyphen followed immediately by newline, ignore both. Split by any non-alphabetic/non-internal-hyphen characters.

**中文解題思路：** 字符流處理：若連字號出現在行末（緊隨換行符）則略過兩者；其餘非字母字元作為單字分界，收集單字去重排序。 ==========================================================================


<a id="uva-11063_b2-sequence"></a>
### UVa 11063 — B2-Sequence／B2 數列

- 原始碼：[11063_b2-sequence.c](11063_b2-sequence.c)
- 演算法：序列檢查、雜湊標記（Array, Set）

**English description:**

A sequence is B2 when it begins with a positive value, is strictly increasing, and every sum `b[i] + b[j]` for `i ≤ j` is unique. Check each input sequence and output whether it satisfies these conditions.

**中文詳細描述：**

每組輸入給一個數列。B2 數列必須首項為正、整體嚴格遞增，而且所有 `i ≤ j` 的兩項和 `b[i]+b[j]` 皆不重複；逐項檢查順序並用標記集合記錄兩項和，最後依案例格式輸出是否為 B2 數列。

<a id="uva-11069_a-problem-of-back"></a>

### UVa 11069 — A Problem of Back／背包無連續相鄰選取方案數

- 原始碼：[11069_a-problem-of-back.c](11069_a-problem-of-back.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, recurrence

**English description:** Find number of subsets of {1..n} such that no two elements differ by 1, and difference between adjacent chosen elements is <= 2.

**中文詳細描述：** 從 1 到 n 中選取子集，要求任兩元素差不能為 1 (不能相鄰)，且相鄰被選元素差不能超過 2，求合法子集數。

**English approach:** Recurrence relation: dp[n] = dp[n - 2] + dp[n - 3].

**中文解題思路：** 線性遞迴動態規劃：結尾元素若為 n，前一個元素必為 n-2 或 n-3。滿足轉移方程 dp[n] = dp[n-2] + dp[n-3]。 ==========================================================================


<a id="uva-11078_open-credit-system"></a>

### UVa 11078 — Open Credit System／學長學弟成績最大差值單調掃描

- 原始碼：[11078_open-credit-system.c](11078_open-credit-system.c)
- 難度：UVa Star 1
- 演算法：greedy, array

**English description:** Given scores of N students in seniority order, find the maximum difference A[i] - A[j] where senior student i precedes junior student j (i < j).

**中文詳細描述：** 依年級高低依序給定 N 位學生的成績，求學長與學弟之間的最大分數差值 A[i] - A[j] (其中 i < j)。

**English approach:** Single pass: maintain max_so_far of A[0..j-1], and update max_diff = max(max_diff, max_so_far - A[j]). Time complexity O(N).

**中文解題思路：** 單次遍歷：維護前綴最大值 max_so_far，動態以 max_so_far - A[j] 更新全局最大差值，時間複雜度 O(N)。 ==========================================================================


<a id="uva-11080_place-the-guards"></a>

### UVa 11080 — Place the Guards／街道守衛二分圖二著色最小守衛數

- 原始碼：[11080_place-the-guards.c](11080_place-the-guards.c)
- 難度：UVa Star 2
- 演算法：graph, bipartite

**English description:** Place minimum guards on intersections such that every street has at least one guard and no two guards share a street (Bipartite graph vertex cover).

**中文詳細描述：** 在街道交會點佈置最少數量的警衛，使得每條街均受到巡查且相鄰兩點不可同時設哨 (二分圖二著色最小頂點覆蓋)。

**English approach:** Bipartite coloring using BFS/DFS. For each component, count color 0 and color 1. If not bipartite, return -1. Take sum(max(1, min(c0, c1))).

**中文解題思路：** 以 BFS 對每個連通分量進行黑白二著色：若出現同色衝突則無解回傳 -1；否則取 min(黑, 白) (獨立單點至少需 1 衛) 加總。 ==========================================================================


<a id="uva-11085_back-to-the-8-queens"></a>

### UVa 11085 — Back to the 8-Queens／回到八皇后棋盤最少移動步數

- 原始碼：[11085_back-to-the-8-queens.c](11085_back-to-the-8-queens.c)
- 難度：UVa Star 2
- 演算法：backtracking, brute-force

**English description:** Given row positions of 8 queens in columns 1..8, find minimum column-wise moves to reach any valid 8-queens solution.

**中文詳細描述：** 給定 8 個皇后在 8 縱列上的初始行位置，求將其移動至任一合法八皇后棋盤狀態所需的最少單列移動步數。

**English approach:** Precompute all 92 valid 8-queens configurations. For input configuration, find minimum differences sum(q[c] != target[c]).

**中文解題思路：** 預先回溯計算出全部 92 種標準八皇后解法，比對輸入之 8 皇后位置，取需要更動縱列數最小者輸出。 ==========================================================================


<a id="uva-11093_just-finish-it-up"></a>

### UVa 11093 — Just Finish it up／跑完全程 (環形加油站起點)

- 原始碼：[11093_just-finish-it-up.c](11093_just-finish-it-up.c)
- 難度：Easy
- 演算法：greedy, sliding-window

**English description:** Find the lowest indexed starting gas station to complete a clockwise circuit around N stations where station i provides p[i] petrol and distance to next is q[i].

**中文詳細描述：** 求能順時針繞行 N 個加油站一圈的最小起點編號（第 i 站加油 p[i]，到下一站耗油 q[i]）。

**English approach:** If total petrol < total cost, impossible. Otherwise, iterate through stations tracking tank. If tank drops below 0, reset start to next station.

**中文解題思路：** 若總油量小於總耗油量則無解；否則維護當前油量，一旦在某站油量變負，則起點必在該站之後，重設起點為下一站。 ==========================================================================


<a id="uva-11094_continents"></a>

### UVa 11094 — Continents／大陸板塊圓柱網格最大未佔領土地面積

- 原始碼：[11094_continents.c](11094_continents.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill

**English description:** Find the maximum size of a continent (connected land cells) on a cylindrical globe, excluding the continent where the king currently resides.

**中文詳細描述：** 在圓柱形東西相接的地球網格上，以漫水填充求出國王所在板塊以外之最大未佔領大陸面積。

**English approach:** Flood fill to erase king's continent. Then flood fill remaining land components, taking maximum size with cylindrical column wrapping (c = (c + C) % C).

**中文解題思路：** 首先將國王所在的大陸以 DFS 標記清除，再對其餘陸地進行漫水填充，水平行座標以取模實現東西邊界相接環形走訪。 ==========================================================================
