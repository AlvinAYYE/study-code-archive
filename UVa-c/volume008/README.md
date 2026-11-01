# UVa Volume 008

本卷收錄 20 份 C 解答，涵蓋 20 個 UVa 題號，以下依題號排序。

<a id="uva-815_flooded"></a>

### UVa 815 — Flooded!／淹水了！ (網格蓄水高度二分/排序)

- 原始碼：[815_flooded.c](815_flooded.c)
- 難度：Easy
- 演算法：sorting, math, binary-search

**English description:** Given grid cell elevations and total flood water volume, compute the final water level and the percentage of region submerged.

**中文詳細描述：** 給定網格各單元地形海拔高度與總洪水體積（每格底面積 100 平方公尺），求最終水位高度及淹沒區域百分比。

**English approach:** Sort elevations ascending. Successively fill up difference between adjacent levels k * 100 * (elev[i] - elev[i-1]). If water runs out, level = elev[i-1] + rem / (k * 100).

**中文解題思路：** 將各格海拔升序排序，逐層注入洪水計算水位上升高度，當水量耗盡時求得精確水位與受淹格數比例。 ==========================================================================


<a id="uva-820_internet-bandwidth"></a>

### UVa 820 — Internet Bandwidth／網際網路最大頻寬 (最大流 Edmonds-Karp)

- 原始碼：[820_internet-bandwidth.c](820_internet-bandwidth.c)
- 難度：UVa Star 2
- 演算法：graph, max-flow, edmonds-karp, network-flow

**English description:** Compute maximum network flow bandwidth from source s to destination t in undirected network graph.

**中文詳細描述：** 在無向容量網路中，求從資料來源 s 到匯點 t 能傳輸的最大頻寬流量 (經典最大流問題)。

**English approach:** Edmonds-Karp algorithm (BFS augmenting paths). Keep residual graph, accumulate bottle neck capacities.

**中文解題思路：** 以 BFS 尋找殘餘網路中的最短增廣路徑 (Edmonds-Karp 演算法)，不斷增廣直到無法抵達匯點為止。 ==========================================================================


<a id="uva-821_page-hopping"></a>

### UVa 821 — Page Hopping／網頁點擊跳躍平均距離

- 原始碼：[821_page-hopping.c](821_page-hopping.c)
- 難度：UVa Star 2
- 演算法：graph, floyd-warshall, shortest-path

**English description:** Find average shortest path length between all pairs of reachable pages.

**中文詳細描述：** 計算網路中所有相異可達網頁節點對之間的最短路徑長度平均值 (Floyd-Warshall 全點對最短路)。

**English approach:** Floyd-Warshall algorithm on up to 100 nodes. Sum all dist[i][j] where i != j and divide by total pairs.

**中文解題思路：** 對最多 100 個網頁節點執行 Floyd-Warshall 演算法，累加所有 i != j 的最短距離除以有效點對數。 ==========================================================================


<a id="uva-825_walking-on-the-safe-side"></a>

### UVa 825 — Walking on the Safe Side／安全街道漫步 (帶障礙網格路徑計數 DP)

- 原始碼：[825_walking-on-the-safe-side.c](825_walking-on-the-safe-side.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, grid

**English description:** Count number of safest paths from (1, 1) to (W, N) in a grid avoiding unsafe intersections.

**中文詳細描述：** 在 W x N 網格街道中，避開所有不安全的路口，求從左上角 (1, 1) 走到右下角 (W, N) 的最短路徑總數。

**English approach:** 2D Grid DP: dp[r][c] = (unsafe ? 0 : dp[r-1][c] + dp[r][c-1]).

**中文解題思路：** 二維網格動態規劃：dp[r][c] = (障礙格 ? 0 : dp[r-1][c] + dp[r][c-1])，起點設為 1。 ==========================================================================


<a id="uva-834_continued-fractions"></a>

### UVa 834 — Continued Fractions／連分數展開 (歐幾里得輾轉相除)

- 原始碼：[834_continued-fractions.c](834_continued-fractions.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Convert rational number a/b into continued fraction representation [b0; b1, b2, ...].

**中文詳細描述：** 將有理數 a/b 展開為連分數形式：求商數並將餘數倒數繼續輾轉相除。

**English approach:** Euclidean division: repeatedly take quotient q = a / b, replace (a, b) with (b, a % b) until remainder is 0.

**中文解題思路：** 利用輾轉相除法求整數商數 q = a / b，更新 a, b = b, a % b，重複迭代直到餘數為 0。 ==========================================================================


<a id="uva-836_largest-submatrix"></a>

### UVa 836 — Largest Submatrix／全為 1 之最大二維子矩陣面積

- 原始碼：[836_largest-submatrix.c](836_largest-submatrix.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Find the maximum area of a submatrix composed entirely of '1's in a binary grid of characters.

**中文詳細描述：** 在二維 0/1 字元矩陣中，尋找內部所有元素全為 '1' 的最大子矩陣面積。

**English approach:** 2D prefix sums: check in O(1) if submatrix (r1, c1) to (r2, c2) has sum == (r2-r1+1)*(c2-c1+1). Take maximum area.

**中文解題思路：** 二維前綴和：以 O(1) 檢驗任意子矩陣元素和是否等於其寬長乘積 (即全為 1)，枚舉維護最大面積。 ==========================================================================


<a id="uva-839_not-so-mobile"></a>

### UVa 839 — Not so Mobile／天平吊飾力矩平衡驗證

- 原始碼：[839_not-so-mobile.c](839_not-so-mobile.c)
- 難度：UVa Star 2
- 演算法：tree, recursion

**English description:** Determine if a recursive mobile scale is balanced at every sub-rod: W_L * D_L == W_R * D_R.

**中文詳細描述：** 以遞迴二元樹結構模擬懸掛的天平吊飾，驗證每個子天平是否滿足力矩平衡條件 (左重 x 左距 == 右重 x 右距)。

**English approach:** Recursive descent function returning total subtree weight or 0 if unbalanced.

**中文解題思路：** 遞迴後序檢查：若重量為 0 則遞迴解析子天平並回傳總重。任一節點力矩不平衡則標記整棵樹失衡。 ==========================================================================


<a id="uva-843_crypt-kicker"></a>

### UVa 843 — Crypt Kicker／解密者

- 原始碼：[843_crypt-kicker.c](843_crypt-kicker.c)
- 難度：Hard
- 演算法：backtracking, cryptography

**English description:** Given a dictionary of words and encrypted lines of text, find a substitution cipher that maps encrypted words to dictionary words.

**中文詳細描述：** 給定字詞字典與加密文字行，尋找單字母替換式密碼將每個加密單字映射到合法的字典單字。

**English approach:** Backtracking search over words in the encrypted line, maintaining bijective mapping between encrypted and plain characters.

**中文解題思路：** 對加密行中的單字進行回溯搜尋，維護加密字元與明文字元之間的雙射映射。 ==========================================================================


<a id="uva-846_steps"></a>

### UVa 846 — Steps／步數跨度最小化 (兩端遞增遞減步長)

- 原始碼：[846_steps.c](846_steps.c)
- 難度：UVa Star 1
- 演算法：math, greedy

**English description:** Find minimum number of steps to travel distance diff, where step length changes by at most 1 and first/last steps are 1.

**中文詳細描述：** 從座標 x 走到 y，相鄰步長變化量最多為 1，首步與尾步長度皆必須為 1，求最少總步數。

**English approach:** Pair identical step lengths: 1, 1, 2, 2, 3, 3... Count how many terms are needed to reach or exceed diff.

**中文解題思路：** 最佳策略為由兩側向中間對稱增大：步長為 1, 1, 2, 2, 3, 3... 累加步長總和直到達到或超過目標距離 diff。 ==========================================================================


<a id="uva-847_a-multiplication-game"></a>

### UVa 847 — A Multiplication Game／乘法博弈遊戲

- 原始碼：[847_a-multiplication-game.c](847_a-multiplication-game.c)
- 演算法：博弈論、勝負區間（game theory, greedy strategy）

**English description:** Starting with `p = 1`, Stan and Ollie alternate, beginning with Stan, and multiply `p` by an integer from 2 through 9. The player whose move first makes `p` at least the target `n` wins. Determine and print the winner for each input target under optimal play.

**中文詳細描述：** 每筆輸入一個目標值 `n`，遊戲從 `p = 1` 開始，由 Stan 先手，兩人輪流選擇 2 到 9 的整數乘上目前的 `p`；誰先使 `p ≥ n` 就獲勝。利用雙方最佳策略的勝負區間，依序乘 9（Stan 能強制達成的上界）與 2（Ollie 能回應的上界），判斷並輸出 `Stan wins.` 或 `Ollie wins.`。

<a id="uva-850_crypt-kicker-ii"></a>

### UVa 850 — Crypt Kicker II／龐格蘭字母全字母句置換解密

- 原始碼：[850_crypt-kicker-ii.c](850_crypt-kicker-ii.c)
- 難度：UVa Star 2
- 演算法：string

**English description:** Decrypt encrypted lines by finding a ciphertext line that matches the pangram pattern 'the quick brown fox jumps over the lazy dog'.

**中文詳細描述：** 比對密文列表中是否存在與標準英文字母全字母句 "the quick brown fox jumps over the lazy dog" 模式完全相符的句子，推算出解密對照表並解密全文。

**English approach:** Find line with identical word lengths matching the 43-character target phrase. Build 1-to-1 bijection cipher table and decrypt all lines.

**中文解題思路：** 逐行比對單詞長度與空格分佈是否與 43 字元的目標全字母句完全一致，構造單射對照表並將全篇密文字串解密還原。 ==========================================================================


<a id="uva-855_lunch-in-grid-city"></a>

### UVa 855 — Lunch in Grid City／格點城市聚餐地點 (二維曼哈頓中位數)

- 原始碼：[855_lunch-in-grid-city.c](855_lunch-in-grid-city.c)
- 難度：UVa Star 1
- 演算法：math, sorting, geometry

**English description:** Find grid intersection (street, avenue) that minimizes total Manhattan distance to F friends.

**中文詳細描述：** 在二維棋盤城市中尋找最佳集合十字路口，使所有朋友到該點的曼哈頓距離總和最小 (中位數定理)。

**English approach:** Independent coordinates: median of sorted street coordinates and median of sorted avenue coordinates.

**中文解題思路：** 曼哈頓距離 x 與 y 軸互相獨立。將所有朋友的街道與大道座標分別排序，各取中位數 (F - 1) / 2 即為最佳地點。 ==========================================================================


<a id="uva-861_little-bishops"></a>

### UVa 861 — Little Bishops／棋盤放置無衝突主教組合動態規劃

- 原始碼：[861_little-bishops.c](861_little-bishops.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, math

**English description:** Count ways to place k non-attacking bishops on an n x n chessboard.

**中文詳細描述：** 在 n x n 的西洋棋盤上放置 k 個彼此不衝突的主教 (象) 的合法擺法總數 (黑白對角線獨立計數動態規劃)。

**English approach:** Bishops on black and white diagonals are independent. Use DP to count placements on diagonals of lengths 1, 3, 5... and 2, 4, 6..., then combine.

**中文解題思路：** 主教僅在同色對角線上互相攻擊，將黑格對角線與白格對角線分開進行背包 DP 求放 i 個主教的方法數，再以卷積求和合併。 ==========================================================================


<a id="uva-865_substitution-cypher"></a>

### UVa 865 — Substitution Cypher／單表替換式密碼轉換

- 原始碼：[865_substitution-cypher.c](865_substitution-cypher.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Decode text using custom substitution alphabet mapping.

**中文詳細描述：** 給定明文字母表與密文字母表，建立單字元對應映射表進行全文替換解密。

**English approach:** Construct direct 256-entry ASCII mapping table. Unmapped characters map to themselves.

**中文解題思路：** 建立大小為 256 的 ASCII 查找陣列，將明文字元映射至密文字元，未出現的字元保持原樣。 ==========================================================================


<a id="uva-871_counting-cells-in-a-blob"></a>

### UVa 871 — Counting Cells in a Blob／計算斑點中的細胞數

- 原始碼：[871_counting-cells-in-a-blob.c](871_counting-cells-in-a-blob.c)
- 難度：Easy
- 演算法：dfs, flood-fill

**English description:** Find the maximum size of an 8-connected component of '1's in a binary grid.

**中文詳細描述：** 求二進位網格中由 '1' 構成的 8 方向最大連通塊大小。

**English approach:** Flood fill DFS in 8 directions from each unvisited '1'. Track maximum blob size.

**中文解題思路：** 對每個未訪問的 '1' 進行 8 方向 DFS 擴展著色，記錄最大斑點大小。 ==========================================================================


<a id="uva-872_ordering"></a>

### UVa 872 — Ordering／拓撲排序的所有合法排列

- 原始碼：[872_ordering.c](872_ordering.c)
- 難度：Medium
- 演算法：backtracking, topological-sort

**English description:** Find all topological sorts of a given set of variables satisfying pairwise ordering constraints.

**中文詳細描述：** 給定變數集合與兩兩先後關係約束，求所有合法的拓撲排序結果。

**English approach:** Backtracking search: at each step, find all unvisited variables with in-degree 0 in alphabetical order, pick one, recurse.

**中文解題思路：** 回溯搜尋：每一步按字母序挑選當前入度為 0 的未訪問變數推進，遞迴生成所有合法拓撲序。 ==========================================================================


<a id="uva-880_cantor-fractions"></a>

### UVa 880 — Cantor Fractions／康托分數編號 (反對角線二分)

- 原始碼：[880_cantor-fractions.c](880_cantor-fractions.c)
- 難度：Easy
- 演算法：math, binary-search

**English description:** Find the fraction at position n in Cantor's enumeration of fractions along anti-diagonals.

**中文詳細描述：** 求康托對角線枚舉序列中第 n 個位置所對應的分數 a / b。

**English approach:** Find diagonal k where k*(k+1)/2 >= n. Let offset = n - k*(k-1)/2. The fraction is (k - offset + 1) / offset.

**中文解題思路：** 以二分或解二次方程求所處對角線編號 k：k*(k+1)/2 >= n，在該對角線上推算分子與分母。 ==========================================================================


<a id="uva-884_factorial-factors"></a>

### UVa 884 — Factorial Factors／階乘質因數個數前綴和

- 原始碼：[884_factorial-factors.c](884_factorial-factors.c)
- 難度：UVa Star 2
- 演算法：math, prime-sieve, prefix-sum

**English description:** Count total number of prime factors (with multiplicity) dividing n! for n <= 1,000,000.

**中文詳細描述：** 計算大數階乘 n! 的質因數總個數 (含重複次數)，n 最大達 100 萬 (質數篩預處理加前綴和)。

**English approach:** Compute number of prime factors num_factors[i] using smallest prime factor sieve. ans[n] = prefix_sum[n].

**中文解題思路：** 線性篩預處理每個整數的質因數個數：f[i] = f[i / min_prime[i]] + 1，再做一次前綴和達成 O(1) 查詢。 ==========================================================================


<a id="uva-893_y3k-problem"></a>

### UVa 893 — Y3K Problem／西元三千年曆法推進

- 原始碼：[893_y3k-problem.c](893_y3k-problem.c)
- 難度：Easy
- 演算法：simulation, calendar, date-math

**English description:** Add N days to a given Gregorian date (day, month, year) correctly handling leap years.

**中文詳細描述：** 在給定的公曆日期上增加 N 天，正確處理閏年並輸出計算後的年月日。

**English approach:** Advance day by day or month by month, checking leap year conditions: (y%4==0 && y%100!=0) || (y%400==0).

**中文解題思路：** 模擬閏年規則：（能被 4 整除且不被 100 整除，或能被 400 整除），逐步累計天數推進日期。 ==========================================================================


<a id="uva-895_word-problem"></a>

### UVa 895 — Word Problem／猜單字遊戲 (字母子集包含計數)

- 原始碼：[895_word-problem.c](895_word-problem.c)
- 難度：Easy
- 演算法：string, frequency-count

**English description:** Given a dictionary of words and puzzles consisting of available letters, count how many dictionary words can be formed using the puzzle letters.

**中文詳細描述：** 給定字典，對每個由可用字母組成的謎題行，求字典中有多少個單字能完全由該行字母拼成（每字母使用次數不超過提供數）。

**English approach:** Count letter frequencies for each dictionary word (26 ints). For each query, count query frequencies and test if word_freq[c] <= query_freq[c] for all c.

**中文解題思路：** 統計字典各單字的 26 個字母出現頻率，對每個詢問檢查單字所需各字母數量是否皆小於等於詢問給予的字母數量。 ==========================================================================
