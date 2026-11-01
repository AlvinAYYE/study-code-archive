# UVa Volume 009 題目索引

本卷收錄 16 份 C 解答，涵蓋 16 個 UVa 題號，以下依題號排序。

<a id="uva-900_brick-wall-patterns"></a>

### UVa 900 — Brick Wall Patterns／磚牆砌法圖案數 (費氏數列 DP)

- 原始碼：[900_brick-wall-patterns.c](900_brick-wall-patterns.c)
- 難度：UVa Star 1
- 演算法：math, dynamic-programming, fibonacci

**English description:** Count ways to build a 2 x n wall using 1 x 2 and 2 x 1 bricks.

**中文詳細描述：** 用 1x2 與 2x1 的骨牌磚塊鋪滿 2 x n 的牆面，求相異排法總數 (即費氏數列 F(n))。

**English approach:** F(n) = F(n-1) + F(n-2) with F(1) = 1, F(2) = 2. Precompute up to n = 50.

**中文解題思路：** 標準骨牌鋪磚動態規劃：最後一塊直放有 F(n-1) 種，兩塊橫放有 F(n-2) 種，為費氏數列。 ==========================================================================


<a id="uva-902_password-search"></a>

### UVa 902 — Password Search／密碼搜尋 (出現頻率最高長度 N 子字串)

- 原始碼：[902_password-search.c](902_password-search.c)
- 難度：UVa Star 2
- 演算法：string, hash-table

**English description:** Find the substring of fixed length N that occurs most frequently in text.

**中文詳細描述：** 在文字中尋找出現頻率最高的指定長度 N 的子字串 (字串滑動窗口與字串雜湊 / 字典樹)。

**English approach:** Sliding window of length N. Count substring frequencies with hash map or sorted list, return argmax.

**中文解題思路：** 以長度 N 的滑動窗口擷取所有子字串，利用字串排序統計相鄰相同項頻率，輸出出現次數最多者。 ==========================================================================


<a id="uva-908_re-connecting-computer-sites"></a>

### UVa 908 — Re-connecting Computer Sites／電腦線路重建最小生成樹重算

- 原始碼：[908_re-connecting-computer-sites.c](908_re-connecting-computer-sites.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Compare original spanning tree weight with new minimum spanning tree weight after adding K new candidate lines and M available existing lines.

**中文詳細描述：** 比較原有網路生成樹總權重，與加入 K 條新線路與 M 條原有線路重新計算最小生成樹後之總權重。

**English approach:** Kruskal's algorithm: combine K new lines and M existing lines, sort by cost, and build new MST. Print old cost and new cost.

**中文解題思路：** Kruskal 演算法：將新候選邊與原邊集合併後按權重排序，重新構建最小生成樹求出最佳建置成本。 ==========================================================================


<a id="uva-913_joana-and-the-odd-numbers"></a>

### UVa 913 — Joana and the Odd Numbers／奇數金字塔第 N 行末三數之和

- 原始碼：[913_joana-and-the-odd-numbers.c](913_joana-and-the-odd-numbers.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** In pyramid of odd numbers (row 1 has 1, row 2 has 3, row k has 2k-1 odds), sum the last 3 odd numbers of row N.

**中文詳細描述：** 在奇數排列成的三角金字塔中 (第 k 行有 2k-1 個奇數)，求第 N 行最後 3 個奇數的總和。

**English approach:** Total odds up to row N is M = ((N + 1) / 2)^2. Last odd is 2*M - 1. Sum of last three is 3*(2*M - 1) - 6.

**中文解題思路：** 等差級數求出到第 N 行為止的奇數總個數 M = ((N+1)/2)^2，該行最後一個奇數為 2M-1，最後三數之和為 3*(2M-1) - 6。 ==========================================================================


<a id="uva-914_jumping-champion"></a>

### UVa 914 — Jumping Champion／跳躍冠軍 (相鄰質數差眾數)

- 原始碼：[914_jumping-champion.c](914_jumping-champion.c)
- 難度：Easy
- 演算法：math, prime, sieve, frequency

**English description:** Find the most frequent difference between adjacent primes in range [L, U]. If a tie exists, there is no jumping champion.

**中文詳細描述：** 求區間 [L, U] 內相鄰質數差值的眾數，若有並列第一則輸出無跳躍冠軍。

**English approach:** Sieve primes up to U. Collect primes in [L, U], calculate consecutive differences diff = p[i+1] - p[i], count frequencies.

**中文解題思路：** 埃氏篩預處理質數，統計 [L, U] 內相鄰質數差值出現頻率，檢查最高頻率是否嚴格唯一。 ==========================================================================


<a id="uva-920_sunny-mountains"></a>

### UVa 920 — Sunny Mountains／陽光山脈 (幾何線段投影)

- 原始碼：[920_sunny-mountains.c](920_sunny-mountains.c)
- 難度：Medium
- 演算法：geometry, sorting

**English description:** Calculate total length of mountain slopes facing sun from top-right receiving direct sunlight.

**中文詳細描述：** 計算由右側射入的陽光所能照亮的山脈迎光坡面總長度。

**English approach:** Sort peak points by x descending. Keep track of highest y seen so far. If current peak is higher, calculate illuminated segment length using similar triangles.

**中文解題思路：** 將山峰點按 x 坐標降序排序，由右至左維護已見最高高度 max_y；遇更高山峰則利用相似三角形計算受光照坡面長度。 ==========================================================================


<a id="uva-924_spreading-the-news"></a>

### UVa 924 — Spreading The News／傳播八卦消息 (BFS 單日最大傳播人數)

- 原始碼：[924_spreading-the-news.c](924_spreading-the-news.c)
- 難度：UVa Star 1
- 演算法：graph, bfs

**English description:** Find the day on which the maximum number of people hear the news (BFS distance frequency) and that max count.

**中文詳細描述：** 在社交好友網路中從某人開始傳遞消息，求消息傳播人數達到峰值的單日天數與最大傳播人數 (BFS 深度頻率統計)。

**English approach:** Breadth-First Search (BFS) tracking distance from source. Tally frequency of each distance d > 0, find maximum.

**中文解題思路：** 標準 BFS 走訪圖形，記錄每個節點到起點的最短距離 (天數)。統計每一天的造訪人數，取最大值與最早發生天數。 ==========================================================================


<a id="uva-927_integer-sequences-from-addition-of-terms"></a>

### UVa 927 — Integer Sequences from Addition of Terms／多項式序列數值求取

- 原始碼：[927_integer-sequences-from-addition-of-terms.c](927_integer-sequences-from-addition-of-terms.c)
- 難度：Easy
- 演算法：math, polynomial-evaluation

**English description:** A sequence repeats a_n d*n times. Find the k-th element of the expanded sequence where a_n is a polynomial.

**中文詳細描述：** 數列中 a_n 連續重複 d*n 次，求展開後的數列中第 k 個元素的值（a_n 為給定多項式）。

**English approach:** Sum of counts S(n) = d * n * (n + 1) / 2. Find smallest n such that S(n) >= k, then evaluate polynomial a_n.

**中文解題思路：** 前 n 項的總展開項數為 d * n * (n + 1) / 2，求使總項數 >= k 的最小整數 n，再將 n 代入多項式計算 a_n。 ==========================================================================


<a id="uva-929_number-maze"></a>

### UVa 929 — Number Maze／數字迷宮最少成本路徑 (2D 網格 Dijkstra)

- 原始碼：[929_number-maze.c](929_number-maze.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, shortest-path

**English description:** Find minimum weight path from (0, 0) to (N-1, M-1) in weighted grid (0 <= cell weight <= 9).

**中文詳細描述：** 在 N x M 的正整數加權網格中，由左上角走到右下角，求經過節點權重和的最小值 (Dijkstra 演算法)。

**English approach:** Dijkstra's shortest path algorithm on 2D grid with min-heap priority queue.

**中文解題思路：** 以優先佇列 (最小堆積) 實作 Dijkstra 最短路徑演算法，狀態為 (dist, r, c)，向上下左右 4 方向鬆弛距離。 ==========================================================================


<a id="uva-941_permutations"></a>

### UVa 941 — Permutations／字典序第 N 個排列 (康托逆展開)

- 原始碼：[941_permutations.c](941_permutations.c)
- 難度：Easy
- 演算法：math, combinatorics, permutations

**English description:** Find the N-th (0-indexed) lexicographical permutation of a given string of up to 20 distinct characters.

**中文詳細描述：** 求給定字串的所有字元依字典序排列後，第 N 個（0-indexed）排列字串（康托逆展開）。

**English approach:** Sort characters. Precompute factorials up to 20!. Compute each digit index = N / (n-1)!, N %= (n-1)!, and extract used characters.

**中文解題思路：** 將字元升序排序，利用階乘基底（康托逆展開）：商數決定當前選取的未用字元索引，餘數作為下一輪數值繼續展開。 ==========================================================================


<a id="uva-948_fibonaccimal-base"></a>

### UVa 948 — Fibonaccimal Base／齊肯多夫定理斐氏進位制表示法

- 原始碼：[948_fibonaccimal-base.c](948_fibonaccimal-base.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Express an integer in Fibonaccimal base (Zeckendorf theorem) using distinct non-consecutive Fibonacci numbers.

**中文詳細描述：** 根據齊肯多夫定理 (Zeckendorf's theorem)，將整數唯一分解為不包含相鄰項之斐波那契數之和，輸出二進位編碼。

**English approach:** Precompute Fibonacci numbers F(2)=1, F(3)=2, F(4)=3... Greedily subtract largest F_k <= N, setting bit k to 1 and preventing adjacent 1s.

**中文解題思路：** 預先計算斐氏數列，以貪婪法自大到小扣除小於等於 N 的最大斐氏數，對應位元標記為 1，直到 N 為 0。 ==========================================================================


<a id="uva-957_popes"></a>

### UVa 957 — Popes／教宗選舉 (區間滑動窗口最大值)

- 原始碼：[957_popes.c](957_popes.c)
- 難度：Easy
- 演算法：two-pointers, sliding-window, binary-search

**English description:** Given years of pope elections and period Y, find the maximum number of popes elected in any Y consecutive years, along with the first and last year.

**中文詳細描述：** 給定教宗當選年份與年限 Y，求任意連續 Y 年區間內當選教宗的最大人數，以及該區間首末教宗的當選年份。

**English approach:** Two pointers (sliding window) on sorted years array: while years[r] - years[l] >= Y, increment l. Track max(r - l + 1).

**中文解題思路：** 雙指針滑動窗口：右指針向右推進，當 years[r] - years[l] >= Y 時收縮左指針，維護窗口內教宗數量最大值。 ==========================================================================


<a id="uva-978_lemmings-battle"></a>

### UVa 978 — Lemmings Battle!／旅鼠大對決！

- 原始碼：[978_lemmings-battle.c](978_lemmings-battle.c)
- 難度：Medium
- 演算法：simulation, priority-queue, sorting

**English description:** Simulate a battle between green and blue lemmings on up to B battlefields where the highest power lemmings fight each round.

**中文詳細描述：** 在最多 B 個戰場上模擬綠色與藍色旅鼠軍團對戰，每輪雙方派出最強者決鬥，差額存活歸隊。

**English approach:** Maintain sorted armies (or max-heaps). Pop top B lemmings from both, match them, insert survivors back, until one or both sides are empty.

**中文解題思路：** 維護雙方戰力排序（或最大堆積），每輪各取前 B 隻旅鼠對決，存活者減去對手戰力後重新入列，直到一方或雙方全滅。 ==========================================================================


<a id="uva-990_diving-for-gold"></a>

### UVa 990 — Diving for Gold／潛水淘金

- 原始碼：[990_diving-for-gold.c](990_diving-for-gold.c)
- 難度：Medium
- 演算法：dp, knapsack

**English description:** Find the maximum gold a diver can retrieve given total air time t and constant w (air cost = 3 * w * depth).

**中文詳細描述：** 給定潛水總氧氣時間 t 與常數 w（下潛與上升耗氣 = 3 * w * 深度），求潛水員可取得黃金的最大總價值。

**English approach:** Standard 0/1 knapsack problem where item weight = 3 * w * depth and item value = gold. Backtrack for chosen treasures.

**中文解題思路：** 標準 0/1 背包問題：物品重量為 3 * w * depth，價值為 gold。使用 DP 求解並回溯找出選取的寶藏。 ==========================================================================


<a id="uva-991_safe-salutations"></a>

### UVa 991 — Safe Salutations／不相交握手問題 (卡特蘭數 Catalan)

- 原始碼：[991_safe-salutations.c](991_safe-salutations.c)
- 難度：UVa Star 1
- 演算法：math, combinatorics, catalan-number

**English description:** Count ways 2n people around a circular table can shake hands simultaneously in pairs without crossed hands.

**中文詳細描述：** 2n 個人圍坐在圓桌旁兩兩握手，要求握手線段互不交叉，求相異握手方案數 (即第 n 個卡特蘭數 C_n)。

**English approach:** Catalan numbers: C_0 = 1, C_n = (2*(2n-1) / (n+1)) * C_{n-1}.

**中文解題思路：** 卡特蘭數經典模型：第 n 個卡特蘭數 C_n = C(2n, n) / (n + 1)，遞推預處理建表。 ==========================================================================


<a id="uva-993_product-of-digits"></a>

### UVa 993 — Product of digits／乘積為 N 之最小正整數 (貪婪單數位因數分解)

- 原始碼：[993_product-of-digits.c](993_product-of-digits.c)
- 難度：UVa Star 1
- 演算法：greedy, math, number-theory

**English description:** Find smallest positive integer Q such that the product of its decimal digits equals N.

**中文詳細描述：** 求最小正整數 Q，使其十進位各數位之乘積恰好等於 N (若無解輸出 -1)。

**English approach:** Greedy approach: divide N by largest single digits from 9 down to 2. If N > 1 remains, no solution.

**中文解題思路：** 貪婪策略：由大到小嘗試用 9, 8, ..., 2 分解 N，將取得的因數倒序組合成位數最短且字典序最小的正整數。 ==========================================================================
