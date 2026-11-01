# UVa Volume 104

本卷收錄 35 份 C 解答，涵蓋 31 個 UVa 題號，以下依題號排序。

<a id="uva-10400_game-show-math"></a>

### UVa 10400 — Game Show Math／益智遊戲算式構造

- 原始碼：[10400_game-show-math.c](10400_game-show-math.c)
- 難度：Medium
- 演算法：backtracking, dp, math

**English description:** Given n numbers and target val, insert +, -, *, / evaluated left to right (no precedence) such that result equals target, with all intermediate results in [-32000, 32000].

**中文詳細描述：** 在 n 個數字之間填入 +, -, *, /（自左至右運算無優先級），使最終等於目標值，且過程中所有中間結果均在 [-32000, 32000] 內且除法必整除。

**English approach:** DFS with memoization vis[index][val + 32000] to prune duplicate subproblem searches.

**中文解題思路：** 帶記憶化搜索的 DFS：以 vis[index][val + 32000] 避免重複狀態搜尋，順利找到解時回溯構造運算符號。 ==========================================================================


<a id="uva-10404_bachets-game"></a>

### UVa 10404 — Bachet's Game／巴切特的博弈遊戲

- 原始碼：[10404_bachets-game.c](10404_bachets-game.c)
- 難度：Medium
- 演算法：game-theory, dp

**English description:** Determine whether Stan or Ollie wins a stone-removal game given n stones and a fixed set of allowed removal counts.

**中文詳細描述：** 給定 n 顆石子與一組允許拿取的石子數量，判定在雙方均採取最優策略下是先手 Stan 或後手 Ollie 獲勝。

**English approach:** Dynamic programming game theory: win[i] is true if there exists an allowed move k such that win[i-k] is false (loss for next player).

**中文解題思路：** 博弈論 DP：若存在可選步數 k 使得 win[i-k] 為必敗態，則 win[i] 為必勝態。 ==========================================================================


<a id="uva-10405_longest-common-subsequence"></a>

### UVa 10405 — Longest Common Subsequence／最長共同子序列 (經典 LCS)

- 原始碼：[10405_longest-common-subsequence.c](10405_longest-common-subsequence.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, lcs, string

**English description:** Find length of Longest Common Subsequence between two strings.

**中文詳細描述：** 求兩字串的最長共同子序列 (LCS) 的最大長度。

**English approach:** Standard 2D DP: dp[i][j] = (s1[i-1] == s2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1])).

**中文解題思路：** 經典二維動態規劃轉移：若字元相同則由左上角 +1；否則取左方與上方最大值。 ==========================================================================


<a id="uva-10407_simple-division"></a>

### UVa 10407 — Simple division／簡單除法同餘公因數 (GCD of Differences)

- 原始碼：[10407_simple-division.c](10407_simple-division.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, gcd

**English description:** Find largest integer d such that all numbers in list have the same remainder when divided by d.

**中文詳細描述：** 給定一組非零整數序列，求最大的整數 d 使得所有整數除以 d 具有相同的餘數。

**English approach:** If a_i = r (mod d), then d divides (a_i - a_1). Compute GCD of all absolute differences |a_i - a_1|.

**中文解題思路：** 同餘性質：兩數同餘則其差必為 d 的倍數。計算所有數與第一個數之差的絕對值的最大公因數 (GCD)。 ==========================================================================


<a id="uva-10408_farey-sequences"></a>

### UVa 10408 — Farey sequences／法里數列 (不可約分數序列)

- 原始碼：[10408_farey-sequences.c](10408_farey-sequences.c)
- 難度：Easy
- 演算法：math, farey-sequence, number-theory

**English description:** Generate the Farey sequence of order n (all irreducible fractions a/b with 1 <= a <= b <= n) and output the k-th fraction.

**中文詳細描述：** 生成 n 階法里數列（所有 1 <= a <= b <= n 且 gcd(a,b)=1 的分數依升序排列），輸出第 k 個分數。

**English approach:** Iterative generation using Farey addition: next terms x2 = floor((y0 + n) / y1) * x1 - x0, y2 = floor((y0 + n) / y1) * y1 - y0.

**中文解題思路：** 利用法里數列相鄰三項遞推公式：k = floor((y0 + n) / y1)，則 x2 = k * x1 - x0, y2 = k * y1 - y0，由 (0,1), (1,n) 迭代至第 k 項。 ==========================================================================


<a id="uva-10409_die-game"></a>
### UVa 10409 — Die Game／骰子遊戲

- 原始碼：[10409_die-game.c](10409_die-game.c)
- 演算法：狀態模擬（Simulation）

**English description:**

A standard die starts with known face values and receives a sequence of north, south, east, or west roll commands. Simulate every roll and output the value on the top face after all commands.

**中文詳細描述：**

輸入先給出擲動次數，再依序給出骰子向北、南、東或西滾動的指令；骰子的初始六面配置固定。逐次更新頂面、底面與四個側面，最後輸出所有指令執行完後的頂面點數。

<a id="uva-10415_eb-alto-saxophone-player"></a>

### UVa 10415 — Eb Alto Saxophone Player／降E調中音薩克斯風演奏家

- 原始碼：[10415_eb-alto-saxophone-player.c](10415_eb-alto-saxophone-player.c)
- 難度：Easy
- 演算法：simulation, array-mapping

**English description:** Count the number of times each finger presses a key while playing a sequence of musical notes on an Eb alto saxophone.

**中文詳細描述：** 計算演奏降 E 調薩克斯風樂譜時，每個手指被按下的次數。

**English approach:** Map each note to a bitmask of required finger presses (fingers 1 to 10). If finger is pressed in note i but not in note i-1, increment press count.

**中文解題思路：** 將每個音符對應到 1~10 號手指的狀態遮罩。若手指在第 i 個音需要按下而在第 i-1 個音未按下，則計數加 1。 ==========================================================================


<a id="uva-10420_list-of-conquests"></a>
### UVa 10420 — List of Conquests／征服名單

- 原始碼：[10420_list-of-conquests.c](10420_list-of-conquests.c)
- 演算法：字串解析、排序、頻率統計（String, Sorting）

**English description:**

Each input line begins with a country name followed by a person's name. Count how many lines belong to each country, then output every country and its count in alphabetical order.

**中文詳細描述：**

每筆輸入資料的第一個單字是國家名稱，後方則是人名。需要統計各國出現的人數，把國名依字典順序排列，並逐行輸出國名及對應的出現次數。

<a id="uva-10420_list-of-conquests-pr"></a>

### UVa 10420 — List of Conquests／唐璜的征服名冊 (國家字串排序與頻率計數)

- 原始碼：[10420_list-of-conquests-pr.c](10420_list-of-conquests-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, sorting

**English description:** Count number of women conquered in each country, output country names in alphabetical order with counts.

**中文詳細描述：** 統計各國家女性被征服的人數，依國家英文名稱字典序升序輸出各國名稱與總人數。

**English approach:** Extract first word (country) of each line. Sort country list and tally occurrences.

**中文解題思路：** 讀取每行第一個單詞作為國家名，存入字串陣列進行字典序排序，連續相同者累計次數輸出。 ==========================================================================


<a id="uva-10422_knights-in-fen"></a>

### UVa 10422 — Knights in FEN／騎士跳躍目標棋盤 (雙向BFS/IDA*)

- 原始碼：[10422_knights-in-fen.c](10422_knights-in-fen.c)
- 難度：Medium
- 演算法：ida, bfs, state-space-search

**English description:** Find the minimum number of knight moves to reach target black/white knight configuration within at most 10 moves.

**中文詳細描述：** 求在 5x5 棋盤上最少需幾步騎士跳躍（最多 10 步）才能達到目標黑白棋盤狀態。

**English approach:** IDA* or bidirectional BFS starting from the unique target state backwards up to depth 10.

**中文解題思路：** 以目標狀態為中心預先進行步數上限為 10 的雙向 BFS 或 IDA* 啟發式搜尋。 ==========================================================================


<a id="uva-10424_love-calculator"></a>

### UVa 10424 — Love Calculator／愛情契合度計算機 (數位和單數位化比例)

- 原始碼：[10424_love-calculator.c](10424_love-calculator.c)
- 難度：UVa Star 1
- 演算法：math, string, simulation

**English description:** Compute love percentage: sum letter values a=1..z=26, repeatedly sum digits to 1 digit, ratio = min/max * 100%.

**中文詳細描述：** 計算名字契合度：英文字母對應 1-26 加總，反覆計算數位和縮減為個位數，契合度為 (小數 / 大數) * 100%。

**English approach:** Sum letter values. Digits reduction function: while(s >= 10) sum digits. Ratio = (v1 < v2 ? v1/v2 : v2/v1) * 100.

**中文解題思路：** 計算姓名英文字母權重和，反覆累加數位縮至個位數，兩者取較小值除以較大值乘 100 得到百分比。 ==========================================================================


<a id="uva-10427_naughty-sleepy-boys"></a>

### UVa 10427 — Naughty Sleepy Boys／調皮的瞌睡男孩 (連續數字串第N位)

- 原始碼：[10427_naughty-sleepy-boys.c](10427_naughty-sleepy-boys.c)
- 難度：Easy
- 演算法：math, binary-search

**English description:** Find the N-th digit in the concatenated integer string '1234567891011121314...'.

**中文詳細描述：** 求正整數連續自然拼接字串 123456789101112... 中的第 N 位數位。

**English approach:** Identify digit length: 1..9 (9*1), 10..99 (90*2), 100..999 (900*3). Locate target number and exact digit within it.

**中文解題思路：** 按位數分段（1位數有9個，2位數有90個，3位數有900個），定位第 N 位所在的具體整數及該數的具體數位。 ==========================================================================


<a id="uva-10432_polygon-inside-a-circle"></a>

### UVa 10432 — Polygon Inside A Circle／圓內接正多邊形面積計算

- 原始碼：[10432_polygon-inside-a-circle.c](10432_polygon-inside-a-circle.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Given radius r and number of sides n, calculate area of regular n-sided polygon inscribed in circle.

**中文詳細描述：** 給定圓半徑 r 與邊數 n，計算內接於該圓的正 n 邊形面積。

**English approach:** Formula: Area = 0.5 * n * r^2 * sin(2*pi / n).

**中文解題思路：** 幾何三角公式：將正 n 邊形切為 n 個等腰三角形，總面積為 0.5 * n * r^2 * sin(2 * pi / n)。 ==========================================================================


<a id="uva-10440_ferry_loading_ii"></a>

### UVa 10440 — Ferry Loading II／渡輪載車 II (最小航行時間與趟數)

- 原始碼：[10440_ferry_loading_ii.c](10440_ferry_loading_ii.c)
- 難度：Medium
- 演算法：greedy, dynamic-programming

**English description:** Determine the minimum total time and trips to ferry all cars across a river with capacity n and one-way trip time t.

**中文詳細描述：** 渡輪每次最多乘載 n 輛車，單程時間 t，求運送全部 m 輛車過河所需的最小總時間與渡輪航行趟數。

**English approach:** Greedy strategy: The first trip carries m % n cars (or n if m % n == 0) to ensure remaining trips carry full loads of n cars.

**中文解題思路：** 貪心策略：第一趟運載 m % n 輛車（若為 0 則運 n 輛），使後續每一趟均載滿 n 輛車以達成最少總趟數與最短完成時間。 ==========================================================================


<a id="uva-10443_rock-scissors-paper"></a>

### UVa 10443 — Rock, Scissors, Paper／剪刀石頭布網格爭奪戰

- 原始碼：[10443_rock-scissors-paper.c](10443_rock-scissors-paper.c)
- 難度：Easy
- 演算法：grid-simulation

**English description:** Simulate daily territorial changes in an R x C grid where adjacent winning hands capture enemy cells.

**中文詳細描述：** 模擬 R x C 網格中剪刀、石頭、布的陣地爭奪戰，若相鄰格子有能克制自己的手勢則被佔領，各格同步更新。

**English approach:** Simulate d days. For each cell, check 4-neighbors; if any neighbor beats it, mark for capture in next state array.

**中文解題思路：** 模擬 d 天的變換，對每個格子檢查四鄰居是否有克制手勢（R 勝 S、S 勝 P、P 勝 R），以雙緩衝區同步更新。 ==========================================================================


<a id="uva-10450_world-cup-noise"></a>

### UVa 10450 — World Cup Noise／世界盃吶喊不相鄰二進位序列計數

- 原始碼：[10450_world-cup-noise.c](10450_world-cup-noise.c)
- 難度：UVa Star 1
- 演算法：math, dp, fibonacci

**English description:** Count binary strings of length n that do not contain two consecutive 1s.

**中文詳細描述：** 計算長度為 n 且不包含連續兩個 '1' 的二進位字串個數 (斐波那契數列 F(n+2))。

**English approach:** Recurrence matches Fibonacci: ways(n) = ways(n-1) + ways(n-2) with ways(1)=2, ways(2)=3.

**中文解題思路：** 滿足不連續 1 的二進位字串數對應費氏數列：f(1)=2, f(2)=3, f(n)=f(n-1)+f(n-2)。 ==========================================================================


<a id="uva-10451_ancient-village-sports"></a>

### UVa 10451 — Ancient Village Sports／古代村莊運動 (正多邊形外接圓與內切圓面積差)

- 原始碼：[10451_ancient-village-sports.c](10451_ancient-village-sports.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Given number of sides n and area A of a regular polygon, compute the spectator area (circumcircle - polygon) and officials area (polygon - incircle).

**中文詳細描述：** 給定正 n 邊形的邊數與面積 A，求外接圓與多邊形面積差（觀眾區）以及多邊形與內切圓面積差（官員區）。

**English approach:** Formulas: A = 0.5 * n * R^2 * sin(2*pi/n) gives circumradius R; inradius r = R * cos(pi/n). Circumcircle = pi * R^2, Incircle = pi * r^2.

**中文解題思路：** 由多邊形面積求外接圓半徑 R 與內切圓半徑 r = R * cos(pi/n)，進而求出兩面積差。 ==========================================================================


<a id="uva-10452_marcus"></a>

### UVa 10452 — Marcus／古墓印第安納瓊斯路徑字符導航

- 原始碼：[10452_marcus.c](10452_marcus.c)
- 難度：UVa Star 2
- 演算法：graph, dfs

**English description:** Navigate Marcus across a stone cobblestone grid from '@' to '#' following the exact sequence 'IEHOVA#' using steps 'forth', 'left', 'right'.

**中文詳細描述：** 在古墓石磚網格中導引瓊斯從 '@' 走到 '#'，嚴格依序踩踏 "IEHOVA#" 字元，輸出每步動作 (forth, left, right)。

**English approach:** DFS search from '@'. At each step, test 3 legal moves (forward, left, right) matching the next character in "IEHOVA#".

**中文解題思路：** 自 '@' 出發 DFS 搜尋：每次向正前方、左方、右方尋找與 "IEHOVA#" 當前字元吻合之相鄰格子推進並記錄指令清單。 ==========================================================================


<a id="uva-10453_make-palindrome"></a>

### UVa 10453 — Make Palindrome／構造回文 (最少插入次數與字串還原)

- 原始碼：[10453_make-palindrome.c](10453_make-palindrome.c)
- 難度：Medium
- 演算法：dp, palindrome, lcs

**English description:** Find the minimum number of character insertions to make a string a palindrome, and reconstruct the resulting palindrome.

**中文詳細描述：** 求最少需要插入多少個字元才能將給定字串變為回文字串，並輸出構造後的回文字串。

**English approach:** Interval DP: dp[i][j] = 0 if i >= j. If s[i] == s[j], dp[i][j] = dp[i+1][j-1]; else 1 + min(dp[i+1][j], dp[i][j-1]). Backtrack to build string.

**中文解題思路：** 區間動態規劃：若 s[i] == s[j] 則兩端保留向內遞推；否則取兩側插入代價較小者加 1，回溯遞迴構建對稱回文字串。 ==========================================================================


<a id="uva-10462_is-there-a-second-way-left"></a>

### UVa 10462 — Is There A Second Way Left?／次小生成樹

- 原始碼：[10462_is-there-a-second-way-left.c](10462_is-there-a-second-way-left.c)
- 難度：Medium
- 演算法：graph, mst, second-best-mst

**English description:** Find the second minimum spanning tree weight. If no spanning tree exists, print 'No way'; if no second spanning tree exists, print 'No second way'.

**中文詳細描述：** 求圖的次小生成樹權重。若連通無生成樹輸出 No way，若不存在嚴格不同的第二棵生成樹輸出 No second way。

**English approach:** Find primary MST. For each edge in the primary MST, temporarily remove it and run Kruskal again to find the minimum alternate spanning tree.

**中文解題思路：** 先求最小生成樹並記錄其所有樹邊，依序強制禁用一條樹邊重新執行 Kruskal 演算法，在所有合法的替換生成樹中取權重最小值。 ==========================================================================


<a id="uva-10465_homer-simpson"></a>

### UVa 10465 — Homer Simpson／辛普森吃漢堡完全背包最優化

- 原始碼：[10465_homer-simpson.c](10465_homer-simpson.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, greedy

**English description:** Two types of burgers take m and n minutes to eat. Homer has t minutes. Maximize burgers eaten; minimize wasted beer time.

**中文詳細描述：** 兩種漢堡吃一個分別耗時 m 與 n 分鐘，在總時間 t 分鐘內盡可能多吃漢堡，使剩餘喝啤酒的時間最小化。

**English approach:** Enumerate number of m-burgers: find non-negative integers i, j such that i*m + j*n <= t minimizing remainder t - (i*m + j*n), maximizing i + j.

**中文解題思路：** 枚舉吃 m 漢堡的個數 i，計算最多可吃 n 漢堡個數 j，先使剩餘時間最小，剩餘時間相同時使漢堡總個數最大。 ==========================================================================


<a id="uva-10469_to-carry-or-not-to-carry"></a>
### UVa 10469 — To Carry or not to Carry／要不要進位

- 原始碼：[10469_to-carry-or-not-to-carry.c](10469_to-carry-or-not-to-carry.c)
- 演算法：位元運算（Bit Manipulation, XOR）

**English description:**

For each pair of non-negative integers, add their binary representations without carrying between bit positions. Output the resulting integer, which is exactly the bitwise exclusive OR of the two inputs.

**中文詳細描述：**

每筆輸入包含兩個非負整數，要把它們視為二進位數相加，但任何位元都不產生進位。各位的結果等同兩數做 XOR，計算後以十進位輸出所得整數。

<a id="uva-10469_to-carry-or-not-to-carry-pr"></a>

### UVa 10469 — To Carry or not to Carry／無進位加法器 (位元互斥或 XOR)

- 原始碼：[10469_to-carry-or-not-to-carry-pr.c](10469_to-carry-or-not-to-carry-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：bit-manipulation, math

**English description:** Add two 32-bit unsigned integers without carrying to the next bit (bitwise XOR).

**中文詳細描述：** 計算二進位無進位加法運算結果 (即位元運算 XOR: a ^ b)。

**English approach:** Addition without carry in binary arithmetic is mathematically equivalent to bitwise XOR: a ^ b.

**中文解題思路：** 二進位無進位加法完全等價於位元互斥或 (XOR) 運算：直接回傳 a ^ b。 ==========================================================================


<a id="uva-10473_simple-base-conversion"></a>
### UVa 10473 — Simple Base Conversion／簡易進位轉換

- 原始碼：[10473_simple-base-conversion.c](10473_simple-base-conversion.c)
- 演算法：字串解析、進位轉換（String, Base Conversion）

**English description:**

Read numbers until the terminating input. A value prefixed by `0x` is hexadecimal and must be printed in decimal; any other value is decimal and must be printed in uppercase hexadecimal with the `0x` prefix.

**中文詳細描述：**

逐筆讀入數字直到終止值。若字串以 `0x` 開頭，就把十六進位值轉成十進位輸出；否則把輸入視為十進位，轉成大寫十六進位並加上 `0x` 前綴後輸出。

<a id="uva-10473_simple-base-conversion-pr"></a>

### UVa 10473 — Simple Base Conversion／簡單十進位與十六進位相互轉換

- 原始碼：[10473_simple-base-conversion-pr.c](10473_simple-base-conversion-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：base-conversion, formatting, string

**English description:** Convert hex numbers (prefixed with 0x) to decimal, and decimal numbers to hex prefixed with 0x.

**中文詳細描述：** 若輸入帶有 '0x' 前綴則轉換為十進位輸出；若輸入為十進位則轉換為十六進位大寫輸出。

**English approach:** Check if s starts with '0x' or '0X'. If so, sscanf with %x and print %d; else sscanf with %d and print 0x%X.

**中文解題思路：** 檢查字串前綴是否為 "0x"，若是則以 %x 讀取轉為十進位；否則以十進位讀取轉為 0x%X。 ==========================================================================


<a id="uva-10474_where-is-the-marble"></a>

### UVa 10474 — Where is the Marble?／大理石在哪裡？(排序與二分搜尋 lower_bound)

- 原始碼：[10474_where-is-the-marble.c](10474_where-is-the-marble.c)
- 難度：UVa Star 1
- 演算法：sorting, binary-search

**English description:** Sort marbles and answer queries finding the 1-based index of the first occurrence of query number.

**中文詳細描述：** 將大理石上的編號排序，回答多筆詢問：某編號大理石第一次出現的 1-based 位置 (若不存在輸出 not found)。

**English approach:** Sort array in ascending order. Use binary search (lower_bound) to find first occurrence in O(log N).

**中文解題思路：** 整數陣列快速排序，利用二分搜尋 lower_bound 尋找目標值首度出現的下標，匹配成功輸出 index + 1。 ==========================================================================


<a id="uva-10480_sabotage"></a>

### UVa 10480 — Sabotage／破壞通訊 (最小割與最大流)

- 原始碼：[10480_sabotage.c](10480_sabotage.c)
- 難度：Hard
- 演算法：network-flow, min-cut, dinic

**English description:** Find a minimum cut separating capital city 1 and rebel city 2 with minimum total edge capacity.

**中文詳細描述：** 求分隔首都 1 號城市與叛軍 2 號城市的最小割邊集（使兩城市斷開所需的最小邊權和）。

**English approach:** Run Edmonds-Karp or Dinic to compute max flow from 1 to 2. Residual graph reachable component from 1 identifies cut edges (u reachable, v unreachable).

**中文解題思路：** 計算從 1 到 2 的最大網絡流。在殘餘網絡中從 1 出發 DFS 標記可達頂點集合 S，所有起點在 S 且終點在 V-S 的原圖邊即為最小割邊。 ==========================================================================


<a id="uva-10487_closest-sums"></a>

### UVa 10487 — Closest Sums／最接近目標之兩數之和

- 原始碼：[10487_closest-sums.c](10487_closest-sums.c)
- 難度：UVa Star 1
- 演算法：brute-force, two-pointers

**English description:** Given set of integers, find the pair sum closest to query value.

**中文詳細描述：** 給定一組相異整數，尋找任選兩數相加之和，使其與詢問值之絕對差最小。

**English approach:** Since n <= 1000, compute pairwise sums in O(N^2) or sort and use two pointers to find closest sum.

**中文解題思路：** 因 n <= 1000，可雙重迴圈枚舉所有數對和，維護與詢問值的最小絕對差，輸出最接近的和。 ==========================================================================


<a id="uva-10489_boxes-of-chocolates"></a>

### UVa 10489 — Boxes of Chocolates／巧克力分盒 (連續模算)

- 原始碼：[10489_boxes-of-chocolates.c](10489_boxes-of-chocolates.c)
- 難度：Easy
- 演算法：math, modulo-arithmetic

**English description:** Given nested boxes of chocolates, find the leftover chocolates when distributed evenly among N friends.

**中文詳細描述：** 巧克力被多層嵌套包裝在箱子中，求全部拆開後平均分給 N 位朋友所剩餘的巧克力數量。

**English approach:** For each box type, multiply inner multipliers modulo N: boxes = (boxes * factor) % N. Sum modulo N.

**中文解題思路：** 每組大盒內的總巧克力數為各層容量的連乘積，對 N 取模並累加，求最終總和對 N 取模。 ==========================================================================


<a id="uva-10490_mr-azad-and-his-son"></a>

### UVa 10490 — Mr. Azad and his Son!!!!!／阿扎德先生與他的兒子 (完全數)

- 原始碼：[10490_mr-azad-and-his-son.c](10490_mr-azad-and-his-son.c)
- 難度：Easy
- 演算法：math, number-theory, mersenne-primes

**English description:** Determine if 2^(p-1) * (2^p - 1) is a perfect number using Euclid-Euler theorem.

**中文詳細描述：** 利用歐幾里得-歐拉定理，判斷 2^(p-1) * (2^p - 1) 是否為完全數。

**English approach:** If 2^p - 1 is prime, then 2^(p-1) * (2^p - 1) is a perfect number. If p is prime but 2^p - 1 is not, it's not perfect. If p is not prime, neither.

**中文解題思路：** 若 2^p - 1 為質數（梅森質數），則其構成完全數；若 p 是質數但 2^p - 1 不是，則非完全數；若 p 本身不是質數則兩者皆非。 ==========================================================================


<a id="uva-10491_cows-and-cars"></a>

### UVa 10491 — Cows and Cars／蒙提霍爾三門問題廣義機率公式

- 原始碼：[10491_cows-and-cars.c](10491_cows-and-cars.c)
- 難度：UVa Star 1
- 演算法：math, probability

**English description:** Generalize the Monty Hall problem: N doors with COWS cows and CARS cars. Host opens SHOW cows. You switch doors. Find probability of winning a car.

**中文詳細描述：** 廣義蒙提霍爾三門問題：共 N 扇門包含 COW 隻牛與 CAR 輛跑車，主持人開啟 SHOW 扇有牛的門，玩家換門後贏得跑車的機率。

**English approach:** P(win) = P(pick cow initially)*P(switch to car) + P(pick car initially)*P(switch to car) = (COW/(COW+CAR))*(CAR/(TOTAL-SHOW-1)) + (CAR/TOTAL)*((CAR-1)/(TOTAL-SHOW-1)).

**中文解題思路：** 全機率公式：初選選中牛後換門中車 + 初選選中車後換門中車，兩條件機率加權求和。 ==========================================================================


<a id="uva-10494_if-we-were-a-child-again"></a>

### UVa 10494 — If We Were a Child Again／大數除以單精度整數之商與餘數

- 原始碼：[10494_if-we-were-a-child-again.c](10494_if-we-were-a-child-again.c)
- 難度：UVa Star 1
- 演算法：bigint, math

**English description:** Perform integer division or modulo between a large integer (up to 1000 digits) and a regular integer.

**中文詳細描述：** 計算大整數 (長達 1000 位) 除以一般整數的除法商數或餘數運算。

**English approach:** Simulate elementary school long division: maintain remainder rem = rem * 10 + digit, append rem / div to quotient, rem = rem % div.

**中文解題思路：** 模擬長除法：維護當前餘數 rem = rem * 10 + d，計算每一步商數 rem / div 並記錄，餘數更新為 rem % div。 ==========================================================================


<a id="uva-10496_collecting-beepers"></a>

### UVa 10496 — Collecting Beepers／網格尋呼機收集最短巡迴路徑 TSP

- 原始碼：[10496_collecting-beepers.c](10496_collecting-beepers.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, bitmask, tsp

**English description:** Find the shortest route starting and ending at home position that visits all N beepers in a grid (Manhattan distance).

**中文詳細描述：** 以曼哈頓距離為代價，求從家出發收集完地圖上所有 N 個尋呼機 (Beeper) 並返回起點的最短巡迴路徑長度 (旅行商問題 TSP)。

**English approach:** TSP with Bitmask DP: dp[mask][cur_node] stores shortest distance to visit subset of beepers ending at cur_node.

**中文解題思路：** 狀態壓縮 DP 求解 TSP：dp[mask][u] 記錄當前拜訪狀態為 mask 且最後停在點 u 的最短路徑，最後回到原點求最小值。 ==========================================================================


<a id="uva-10499_the-land-of-justice"></a>
### UVa 10499 — The Land of Justice／正義之地

- 原始碼：[10499_the-land-of-justice.c](10499_the-land-of-justice.c)
- 演算法：數學公式（Math）

**English description:**

For each given number `n` of pieces, determine the percentage increase in surface area caused by cutting a sphere into that many parts. Output zero for the single-piece case; otherwise output `25 × n` percent.

**中文詳細描述：**

輸入給出球體被切成的份數 `n`，要計算切割後表面積相對原表面積增加的百分比。當只有一份時沒有切割，輸出 `0%`；其餘情況依推導結果輸出 `25 × n%`。

<a id="uva-10499_the-land-of-justice-pr"></a>

### UVa 10499 — The Land of Justice／正義之國的球體切割獲利

- 原始碼：[10499_the-land-of-justice-pr.c](10499_the-land-of-justice-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, geometry

**English description:** A solid sphere is cut into N equal parts. Compute percentage profit based on surface area increase.

**中文詳細描述：** 將實心均勻球體切成 N 等分 (瓜瓣形)，表面積增加部分為獲利，求利潤百分比 (N=1 時利潤為 0%)。

**English approach:** Sphere area = 4*pi*r^2. N slices add N great circle areas = N * pi * r^2. Profit ratio = N * pi * r^2 / (4 * pi * r^2) = N / 4 = 25 * N %.

**中文解題思路：** 球體原本表面積 4*pi*r^2，切成 N 等分增加 N 個大圓半圓面 (面積為 N*pi*r^2)，獲利為 25 * N % (特判 N=1 為 0%)。 ==========================================================================
