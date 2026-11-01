# UVa Volume 116 題目索引

本卷收錄 18 份 C 解答，涵蓋 18 個 UVa 題號，以下依題號排序。

<a id="uva-11608_no-problem"></a>

### UVa 11608 — No Problem／題庫題目產出與競賽出題供給檢驗

- 原始碼：[11608_no-problem.c](11608_no-problem.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Given initial problems in stock S and arrays of 12 months' problems created and required for contests, determine if each contest can be held.

**中文詳細描述：** 初始題庫有 S 題，給定一年 12 個月每個月新增產出的題目數與該月競賽所需題目數，判定每個月是否均能如期舉辦競賽。

**English approach:** For month i: if stock >= req[i], print 'No problem! :D' and stock -= req[i], else print 'No problem. :('; then stock += created[i].

**中文解題思路：** 模擬每月出題：若題庫存量 >= 該月需求則扣減庫存並舉辦，否則跳過扣款；月末再將該月新產生的題目加入題庫庫存。 ==========================================================================


<a id="uva-11614_etruscan-warriors-never-play-chess"></a>

### UVa 11614 — Etruscan Warriors Never Play Chess／伊特魯里亞勇士三角隊形行數計算

- 原始碼：[11614_etruscan-warriors-never-play-chess.c](11614_etruscan-warriors-never-play-chess.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given N warriors standing in triangular formation (1 in row 1, 2 in row 2, etc.), find maximum completed rows k such that k*(k+1)/2 <= N.

**中文詳細描述：** 給定 N 名戰士排成三角形隊形 (第 1 排 1 人、第 2 排 2 人……)，計算最多可排滿幾行使得 k*(k+1)/2 <= N。

**English approach:** Solve quadratic inequality k^2 + k - 2N <= 0 -> k = floor((-1 + sqrt(1 + 8N)) / 2).

**中文解題思路：** 解二次不等式 k(k+1)/2 <= N，利用公式解求得 k = floor((-1 + sqrt(1 + 8N)) / 2)。 ==========================================================================


<a id="uva-11616_roman-numerals"></a>

### UVa 11616 — Roman Numerals／羅馬數字與阿拉伯數字雙向轉換

- 原始碼：[11616_roman-numerals.c](11616_roman-numerals.c)
- 難度：Easy
- 演算法：string, number-base, simulation

**English description:** Convert standard Roman numerals (I, V, X, L, C, D, M) to Arabic numbers, and vice versa.

**中文詳細描述：** 實現羅馬數字與十進位阿拉伯數字之間的雙向自動辨識與轉換。

**English approach:** If input starts with digit: convert int to Roman greedily with subtraction symbols (IV, IX, etc.). If starts with letter: parse Roman to int.

**中文解題思路：** 依首字元判斷：若為數字則貪心構造羅馬字串；若為字母則按羅馬數字符號累計數值（小數在大數前則減去）。 ==========================================================================


<a id="uva-11621_small_numbers"></a>

### UVa 11621 — Small Numbers／小數 (僅含質因數 2 與 3 的最小不小於 m 之數)

- 原始碼：[11621_small_numbers.c](11621_small_numbers.c)
- 難度：Easy
- 演算法：math, number-theory, binary-search

**English description:** Find the smallest number of the form 2^i * 3^j that is greater than or equal to m.

**中文詳細描述：** 求所有僅含質因數 2 與 3 的整數（形如 2^i * 3^j）中，大於等於給定正整數 m 的最小值。

**English approach:** Precompute all valid products 2^i * 3^j up to 2^31, sort, and binary search upper_bound/lower_bound.

**中文解題思路：** 預先計算所有小於 2^31 的 2^i * 3^j 數值並排序，二分搜尋大於等於 m 的首個數值。 ==========================================================================


<a id="uva-11624_fire"></a>

### UVa 11624 — Fire!／著火了！

- 原始碼：[11624_fire.c](11624_fire.c)
- 難度：Medium
- 演算法：bfs, multi-source-bfs

**English description:** Find the shortest time for Joe to escape a burning maze where fire spreads to 4 adjacent cells every minute.

**中文詳細描述：** 迷宮中每分鐘火勢向四方蔓延，求 Joe 逃離迷宮邊緣的最短時間。

**English approach:** Multi-source BFS for fire arrival times at each cell, then BFS for Joe escaping to boundary before fire arrives.

**中文解題思路：** 多源 BFS 先計算火焰抵達每個格子的時間，接著對 Joe 進行 BFS 尋找能否在火焰抵達前逃出邊界。 ==========================================================================


<a id="uva-11629_ballot_evaluation"></a>

### UVa 11629 — Ballot evaluation／選票百分比不等式驗證

- 原始碼：[11629_ballot_evaluation.c](11629_ballot_evaluation.c)
- 難度：Easy
- 演算法：parsing, math, precision

**English description:** Verify whether a sum of vote percentages satisfies a given comparison operator against an integer.

**中文詳細描述：** 檢驗候選人得票百分比之和是否滿足給定的比較運算子與目標數值（利用乘以 10 避免浮點誤差）。

**English approach:** Scale all percentages by 10 to operate strictly on integers, preventing floating-point precision issues.

**中文解題思路：** 將所有百分比數值乘以 10 轉為純整數運算，根據運算子 (<, >, <=, >=, =) 進行準確判斷。 ==========================================================================


<a id="uva-11631_dark-roads"></a>

### UVa 11631 — Dark roads／黑暗道路最小生成樹省電節能

- 原始碼：[11631_dark-roads.c](11631_dark-roads.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Find the maximum total electricity money saved by turning off street lights on redundant roads while keeping all junctions connected.

**中文詳細描述：** 在保證所有路口彼此連通的前提下關閉多餘道路的路燈，求最多可節省之照明總費用 (原總權重扣除最小生成樹權重)。

**English approach:** Kruskal's algorithm: compute total edge weight minus weight of Minimum Spanning Tree (MST).

**中文解題思路：** 利用 Kruskal 演算法求出最小生成樹 (MST) 的邊權和，節省費用即為總邊權減去 MST 邊權。 ==========================================================================


<a id="uva-11636_hello-world"></a>

### UVa 11636 — Hello World!／複製貼上最少次數 (倍增對數)

- 原始碼：[11636_hello-world.c](11636_hello-world.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Find minimum copy-paste operations to obtain at least N lines of 'Hello World!' starting from 1 line.

**中文詳細描述：** 從 1 行文字開始，每次可複製既有所有文字並貼上 (行數翻倍)，求產生至少 N 行所需的最少貼上次數。

**English approach:** Doubling: ceil(log2(N)). If N <= 1 return 0; else count times doubling until >= N.

**中文解題思路：** 每次操作行數翻倍 (1->2->4->8...)，即求 ceil(log2(N))。以迴圈每次乘 2 統計步數直至達到或超過 N。 ==========================================================================


<a id="uva-11650_mirror-clock"></a>

### UVa 11650 — Mirror Clock／鏡子反射時鐘真實時間還原

- 原始碼：[11650_mirror-clock.c](11650_mirror-clock.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given the time displayed by an analog clock seen in a mirror (HH:MM), compute the actual true time.

**中文詳細描述：** 在鏡子中看到的指針式時鐘時間為 HH:MM，求真實世界中的實際時間 (12 小時鏡像反射)。

**English approach:** Total minutes in 12 hours is 720. True minutes = (720 - (HH * 60 + MM)) % 720. Convert back to 12-hour clock format.

**中文解題思路：** 以 720 分鐘為一週期，真實分鐘數為 (720 - 鏡中總分鐘數) % 720，再將分鐘數換算回 12 小時制之時與分。 ==========================================================================


<a id="uva-11661_burger-time"></a>

### UVa 11661 — Burger Time?／速食漢堡餐廳與藥局最短距離

- 原始碼：[11661_burger-time.c](11661_burger-time.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Given highway string with 'R' (restaurant), 'D' (drugstore), and 'Z' (both), find minimum distance between any R and D.

**中文詳細描述：** 給定包含 'R' (餐廳)、'D' (藥局) 與 'Z' (兩者皆有) 的沿街字串，求任一餐廳與藥局之間的最短距離。

**English approach:** If 'Z' exists, distance is 0. Otherwise, track last seen indices of 'R' and 'D' and take minimum abs(last_R - last_D).

**中文解題思路：** 若存在 'Z' 則距離為 0；否則記錄最後一次遇到 'R' 與 'D' 的索引位置，動態更新其下標差值之最小值。 ==========================================================================


<a id="uva-11677_alarm-clock"></a>

### UVa 11677 — Alarm Clock／鬧鐘剩餘睡眠分鐘數

- 原始碼：[11677_alarm-clock.c](11677_alarm-clock.c)
- 難度：UVa Star 1
- 演算法：math, simulation

**English description:** Compute minutes of sleep between bedtime (H1:M1) and alarm time (H2:M2).

**中文詳細描述：** 計算從當前睡覺時間 (H1:M1) 到鬧鐘響起時間 (H2:M2) 之間相隔的睡眠分鐘數。

**English approach:** Convert both times to minutes from midnight: (t2 - t1 + 1440) % 1440.

**中文解題思路：** 將兩時間皆轉換為從午夜 0:00 起算的分鐘數，計算 (t2 - t1 + 1440) % 1440 即可正確處理跨日情形。 ==========================================================================


<a id="uva-11678_cards-exchange"></a>

### UVa 11678 — Cards' Exchange／卡片交換 (不重複集合差集比較)

- 原始碼：[11678_cards-exchange.c](11678_cards-exchange.c)
- 難度：Easy
- 演算法：set-operations, simulation

**English description:** Alice and Betty have collections of cards. They want to trade cards such that each receives cards they do not yet own. Find maximum number of traded cards.

**中文詳細描述：** 兩位小朋友各自收集卡片，希望進行一對一交換互補彼此沒有的卡片，求最多能公平交換幾張卡片。

**English approach:** Remove duplicates to get unique sets A and B. Count unique cards in A not in B, and in B not in A. Answer is min(|A - B|, |B - A|).

**中文解題思路：** 去重轉為集合 A 與 B，統計 A 中有而 B 沒有的卡片數及 B 中有而 A 沒有的卡片數，兩者取較小值即為最大交換張數。 ==========================================================================


<a id="uva-11679_sub-prime"></a>

### UVa 11679 — Sub-prime／次級房貸銀行準備金互欠清償

- 原始碼：[11679_sub-prime.c](11679_sub-prime.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Given cash reserves of B banks and N debentures between banks, determine if all debts can be settled without any bank having negative reserve.

**中文詳細描述：** 給定 B 家銀行的初始貨幣儲備金與 N 筆銀行間的借貸債權，判定經過相互債務清償後是否所有銀行的儲備金皆大於等於零。

**English approach:** Simulate transactions: reserve[debtor] -= val, reserve[creditor] += val. Check if any reserve is negative.

**中文解題思路：** 更新各銀行儲備金：借方扣款、貸方入帳，最後檢驗是否存在任何一間銀行儲備金小於 0。 ==========================================================================


<a id="uva-11683_laser-sculpture"></a>

### UVa 11683 — Laser Sculpture／雷射雕刻

- 原始碼：[11683_laser-sculpture.c](11683_laser-sculpture.c)
- 難度：Easy
- 演算法：greedy, simulation

**English description:** Count the number of laser beam sweeps needed to carve a final height profile from a block of height A and length C.

**中文詳細描述：** 求將高為 A、長度為 C 的原材料雕刻成目標高度剖面所需的最少雷射掃描次數。

**English approach:** Greedy sweep: cost = (A - height[0]) + sum(max(0, height[i-1] - height[i])).

**中文解題思路：** 貪心法：總次數 = (A - height[0]) + sum(max(0, height[i-1] - height[i]))。 ==========================================================================


<a id="uva-11686_pick-up-sticks"></a>

### UVa 11686 — Pick up sticks／撿木棒 (拓撲排序與環檢測)

- 原始碼：[11686_pick-up-sticks.c](11686_pick-up-sticks.c)
- 難度：Medium
- 演算法：graph, topological-sort, dag

**English description:** Find a valid pickup order for n sticks with given on-top-of constraints, or determine if impossible (cycle exists).

**中文詳細描述：** 給定木棒之間的壓疊先後關係，求一組可行的撿取順序；若存在環導致無法撿完則判定為不可能。

**English approach:** Kahn's topological sort algorithm using in-degree array and queue. If sorted count equals n, valid; else cycle.

**中文解題思路：** Kahn 演算法：統計入度為 0 的節點入隊，依序刪除出邊並更新鄰居入度。若拓撲排序長度為 n 則有解，否則有環。 ==========================================================================


<a id="uva-11687_digits"></a>

### UVa 11687 — Digits／數位長度遞推固定點收斂步數

- 原始碼：[11687_digits.c](11687_digits.c)
- 難度：UVa Star 1
- 演算法：math, string

**English description:** Given x_0, define x_i = length(x_{i-1}). Find the smallest index i such that x_i = x_{i-1}.

**中文詳細描述：** 給定超大正整數 x_0，令 x_i 為 x_{i-1} 轉為十進位字串後的長度，求首個滿足 x_i = x_{i-1} 的最小下標 i。

**English approach:** Compute len = strlen(s). If s == '1' return 1. Otherwise iterate: step = 1, cur = len, next = digits_of(cur), repeat until cur == next.

**中文解題思路：** 若初始字串即為 "1" 則步數為 1；否則以其長度開始迭代，計算每次長度之位數，直至數值不再變化收斂至 1 為止。 ==========================================================================


<a id="uva-11689_soda-surpler"></a>

### UVa 11689 — Soda Surpler／汽水空瓶收集兌換

- 原始碼：[11689_soda-surpler.c](11689_soda-surpler.c)
- 難度：UVa Star 1
- 演算法：simulation, math

**English description:** Given e empty bottles owned, f empty bottles found, and cost c bottles per new soda, find total sodas drank.

**中文詳細描述：** 持有 e 個空瓶，路上又收集到 f 個空瓶。每 c 個空瓶可兌換 1 瓶新汽水，求總共能喝到幾瓶汽水。

**English approach:** Total empties = e + f. While empties >= c, drink = empties / c, total += drink, empties = empties % c + drink.

**中文解題思路：** 初始空瓶總數為 e + f，迴圈模擬兌換新汽水並喝完產生新空瓶，直到空瓶數不足 c 個為止。 ==========================================================================


<a id="uva-11690_money-matters"></a>

### UVa 11690 — Money Matters／金錢糾葛 (並查集連通塊債務平衡)

- 原始碼：[11690_money-matters.c](11690_money-matters.c)
- 難度：Easy
- 演算法：disjoint-set-union, graph

**English description:** Friends owe each other money. Money can only be transferred between direct friends. Determine if all debts can be settled (sum of balances in each connected component is 0).

**中文詳細描述：** 朋友間互有債務（正值代表應收，負值代表應付），金錢只能在好友間轉移，求各連通分量內的債務是否均可平賬（各連通塊總和為 0）。

**English approach:** Union-Find connecting friends. Accumulate individual money balances onto root of each component. Settled iff balance[root] == 0 for all roots.

**中文解題思路：** 以並查集合併好友關係，並在並查集根節點累加該連通塊內所有成員的資金餘額，檢查每個連通分量餘額和是否皆為 0。 ==========================================================================
