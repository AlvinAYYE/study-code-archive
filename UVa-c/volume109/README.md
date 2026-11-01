# UVa Volume 109

本卷收錄 39 份 C 解答，涵蓋 34 個 UVa 題號，以下依題號排序。

<a id="uva-10901_ferry-loading-iii"></a>

### UVa 10901 — Ferry Loading III／渡輪裝載 III

- 原始碼：[10901_ferry-loading-iii.c](10901_ferry-loading-iii.c)
- 難度：Medium
- 演算法：simulation, queue

**English description:** Simulate a ferry carrying at most n cars across a river in time t, delivering them with minimum wait.

**中文詳細描述：** 模擬一次最多承載 n 輛車且單程耗時 t 的渡輪，求每輛車被運送抵達對岸的時間。

**English approach:** Two queues for left and right banks. Ferry advances time to next available car if idle, loads up to n cars, and crosses.

**中文解題思路：** 左右兩岸各維護一個隊列，渡輪若空閒則時間推進到最早到達的車輛，裝載最多 n 輛車後航向對岸。 ==========================================================================


<a id="uva-10903_rock-paper-scissors-tournament"></a>

### UVa 10903 — Rock-Paper-Scissors Tournament／剪刀石頭布錦標賽勝率計算

- 原始碼：[10903_rock-paper-scissors-tournament.c](10903_rock-paper-scissors-tournament.c)
- 難度：UVa Star 1
- 演算法：simulation, math

**English description:** Compute win rate W / (W + L) for each player in rock-paper-scissors tournament (draws ignored).

**中文詳細描述：** 計算每位選手在剪刀石頭布錦標賽中的勝率 W / (W + L)，平局忽略不計；若無有效對局輸出破折號 '-'。

**English approach:** Track wins and losses per player. Ignore draws. Output W / (W + L) rounded to 3 decimal places.

**中文解題思路：** 陣列記錄每位選手的勝場數 W 與敗場數 L。平手不計入。勝率為 (double)W / (W + L)。 ==========================================================================


<a id="uva-10905_childrens-game"></a>

### UVa 10905 — Children's Game／兒童拼數字遊戲 (自定義貪婪字串排序拼最大數)

- 原始碼：[10905_childrens-game.c](10905_childrens-game.c)
- 難度：UVa Star 1
- 演算法：sorting, greedy, string

**English description:** Concatenate numbers to form the largest possible number.

**中文詳細描述：** 將給定的多個正整數拼接組合，求能拼成的最大數值 (自定義字串比較規則 A+B vs B+A)。

**English approach:** Custom string comparator: A comes before B if concat(A, B) > concat(B, A). Sort and concatenate.

**中文解題思路：** 自定義字串比較器：若 A+B 字典序大於 B+A 則 A 排在前面，排序後依序串接輸出。 ==========================================================================


<a id="uva-10908_largest-square"></a>
### UVa 10908 — Largest Square／最大正方形

- 原始碼：[10908_largest-square.c](10908_largest-square.c)
- 演算法：二維陣列、中心擴張（2D Array, Simulation）

**English description:**

Given a character grid and several center coordinates, find for each query the largest odd-sided square centered there whose cells all equal the center character. Output the side length for every query.

**中文詳細描述：**

每組輸入包含一個字元矩陣與多個中心座標。對每個查詢，要找以該點為中心且所有格子都和中心字元相同的最大正方形；由半徑 0 向外逐圈檢查邊界，最後輸出其奇數邊長。

<a id="uva-10908_largest-square-pr"></a>

### UVa 10908 — Largest Square／網格中心擴展最大同色正方形

- 原始碼：[10908_largest-square-pr.c](10908_largest-square-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, 2d-grid

**English description:** Find side length of largest square with same character centered at (r, c).

**中文詳細描述：** 在二維網格中給定中心點 (r, c)，求以該點為中心且內部字元完全相同的最大正方形邊長。

**English approach:** Expand radius rad from 1 outward. Check border cells at distance rad. Stop on mismatch or grid edge.

**中文解題思路：** 中心半徑擴展：從半徑 rad = 1 開始逐圈向外驗證外邊界字元是否皆等於中心字元，最大邊長為 2*rad + 1。 ==========================================================================


<a id="uva-10910_marks-distribution"></a>

### UVa 10910 — Marks Distribution／分數分配 (隔板法與組合數)

- 原始碼：[10910_marks-distribution.c](10910_marks-distribution.c)
- 難度：Easy
- 演算法：math, combinatorics, dp

**English description:** Find the number of ways to distribute total marks T among N subjects such that each subject gets at least P marks.

**中文詳細描述：** 求將總分 T 分配給 N 門科目且每門科目至少獲得 P 分的方案數。

**English approach:** Subtract base marks: remaining T' = T - N * P. The number of ways to distribute T' among N subjects is C(T' + N - 1, N - 1).

**中文解題思路：** 先給每門課分 P 分，剩餘 T' = T - N * P 分，轉為經典隔板法非負整數解個數：C(T' + N - 1, N - 1)。 ==========================================================================


<a id="uva-10911_forming-quiz-teams"></a>

### UVa 10911 — Forming Quiz Teams／問答競賽組隊最小歐氏距離和狀態壓縮 DP

- 原始碼：[10911_forming-quiz-teams.c](10911_forming-quiz-teams.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, bitmask

**English description:** Given 2N students on a 2D plane, pair them into N teams of 2 to minimize the sum of Euclidean distances between teammates.

**中文詳細描述：** 給定平面上 2N 位學生的座標，將其兩兩配對成 N 組使所有組員間歐幾里得距離總和最小 (狀態壓縮 DP)。

**English approach:** Bitmask dynamic programming: dp[mask] represents minimum cost to pair the subset of students encoded by mask. Transition by picking lowest unset bit.

**中文解題思路：** 狀態壓縮動態規劃：dp[mask] 記錄已配對學生的集合狀態，每次挑選最小未配對學生並枚舉其隊友轉移更新。 ==========================================================================


<a id="uva-10912_simple-minded-hashing"></a>

### UVa 10912 — Simple Minded Hashing／簡單字串雜湊計數 (嚴格遞增字元DP)

- 原始碼：[10912_simple-minded-hashing.c](10912_simple-minded-hashing.c)
- 難度：Medium
- 演算法：dp, combinatorics

**English description:** Count the number of strings of length L with strictly increasing alphabetical characters whose character value sum equals S.

**中文詳細描述：** 計算長度為 L 且字元嚴格遞增的字串中，所有字母序號之和（a=1..z=26）恰好等於 S 的字串數量。

**English approach:** 3D DP state dp[len][last_char][sum]. dp[i][c][s] = sum(dp[i-1][prev_c][s - c]) for prev_c < c.

**中文解題思路：** 三維動態規劃：dp[len][last][sum] 表示當前長度為 len、最後字母為 last、權重和為 sum 的方案數，轉移保證字母嚴格遞增。 ==========================================================================


<a id="uva-10916_factstone-benchmark"></a>

### UVa 10916 — Factstone Benchmark／階乘基準測試 (字長與階乘增長率)

- 原始碼：[10916_factstone-benchmark.c](10916_factstone-benchmark.c)
- 難度：Easy
- 演算法：math, logarithms

**English description:** Given a year Y, computer word size is 2^(2 + (Y-1960)/10) bits. Find the largest n such that n! fits in an unsigned integer of that size.

**中文詳細描述：** 給定年份 Y，電腦字長為 2^(2 + (Y-1960)/10) 位元，求階乘 n! 能容納在該無號整數範圍內的最大整數 n。

**English approach:** Word bits B = 2^(2 + (Y-1960)/10). Condition is log2(n!) = sum_{i=1}^n log2(i) < B.

**中文解題思路：** 計算位元數 B = 2^(2 + (Y-1960)/10)，累加 log2(i) 直到總和大於等於 B，前一個整數即為所求最大 n。 ==========================================================================


<a id="uva-10918_tri-tiling"></a>

### UVa 10918 — Tri Tiling／3 x n 骨牌鋪滿計數

- 原始碼：[10918_tri-tiling.c](10918_tri-tiling.c)
- 難度：Medium
- 演算法：dp, recurrence-relation

**English description:** Find the number of ways to completely tile a 3 x n grid with 2 x 1 dominoes.

**中文詳細描述：** 求用 2 x 1 骨牌鋪滿 3 x n 矩形網格的方案總數（n 為奇數時為 0）。

**English approach:** When n is odd, answer is 0. Recurrence: f(n) = 4*f(n-2) - f(n-4) with f(0)=1, f(2)=3.

**中文解題思路：** n 為奇數時面積為奇數無法鋪滿（答案為 0）；偶數時滿足遞推關係式 f(n) = 4*f(n-2) - f(n-4)，初值 f(0)=1, f(2)=3。 ==========================================================================


<a id="uva-10919_prerequisites"></a>

### UVa 10919 — Prerequisites?／大學先修畢業學程選課檢驗

- 原始碼：[10919_prerequisites.c](10919_prerequisites.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Given courses taken by Freddie and category requirement rules (must take >= R_i courses from list i), determine if he can graduate.

**中文詳細描述：** 給定學生已修課程清單與各領域先修學分要求 (每個領域至少需修習 R_i 門指定課程)，判定該學生是否滿足畢業資格。

**English approach:** Store selected courses in a hash set. For each category, count how many required courses Freddie has taken. If count < R_i, graduation fails.

**中文解題思路：** 將已選課程存入雜湊集合，對各學程分類統計已修課程數，若任一類別之修課數小於其最低要求門檻則判定資格不符。 ==========================================================================


<a id="uva-10920_spiral-tap"></a>

### UVa 10920 — Spiral Tap／螺旋座標定位

- 原始碼：[10920_spiral-tap.c](10920_spiral-tap.c)
- 難度：Medium
- 演算法：math, simulation

**English description:** Given a grid size S and a cell number P in an outwards counter-clockwise spiral starting at center 1, find row and column.

**中文詳細描述：** 在邊長為 S 的網格中，從中心點 1 逆時針向外呈螺旋編號，求編號 P 所在的行與列座標。

**English approach:** Find the odd square ring k such that (k-2)^2 < P <= k^2. Center is at ((S+1)/2, (S+1)/2). Trace position along the four segments of ring k.

**中文解題思路：** 找出 P 所在的奇數外環 k：(k-2)^2 < P <= k^2，中心為 ((S+1)/2, (S+1)/2)，再根據 P 在外環四條邊上的相對位置推算座標。 ==========================================================================


<a id="uva-10921_find-the-telephone"></a>

### UVa 10921 — Find the Telephone／電話號碼英文字母按鍵轉換

- 原始碼：[10921_find-the-telephone.c](10921_find-the-telephone.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Convert letters in telephone expression to corresponding standard keypad digits.

**中文詳細描述：** 依據標準電話按鍵將文字號碼中的英文字母轉換為對應數字 (保留連字號與既有數字)。

**English approach:** Direct switch/case or table lookup mapping A-C->2, D-F->3, G-I->4, J-L->5, M-O->6, P-S->7, T-V->8, W-Z->9.

**中文解題思路：** 查表法：將 26 個英文字母映射到 2-9 按鍵數字，數字與 '-' 保持原樣輸出。 ==========================================================================


<a id="uva-10922_2-the-9s"></a>
### UVa 10922 — 2 the 9s／9 的階數

- 原始碼：[10922_2-the-9s.c](10922_2-the-9s.c)
- 演算法：數位和、整除性（Number Theory）

**English description:**

For each possibly very long decimal integer, determine whether it is a multiple of 9. If so, repeatedly sum decimal digits until reaching 9 and output how many digit-sum applications were required; otherwise report that it is not a multiple of 9.

**中文詳細描述：**

逐筆讀入可能很長的十進位整數，直到終止值。先以各位數字和判斷是否能被 9 整除；若可以，就反覆計算數字和直到得到 9，並輸出這個 9 的階數，否則輸出它不是 9 的倍數。

<a id="uva-10922_2-the-9s-pr"></a>

### UVa 10922 — 2 the 9s／9的度數 (9-degree 數位和倍數遞歸)

- 原始碼：[10922_2-the-9s-pr.c](10922_2-the-9s-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, recursion

**English description:** Determine if number is multiple of 9 by digital root and compute its 9-degree.

**中文詳細描述：** 判斷大整數是否為 9 的倍數，並計算反覆求數位和直到為個位數 9 所需的遞迴次數 (9-degree)。

**English approach:** Sum digits of string. If sum % 9 == 0, count recursive steps to reach 9.

**中文解題思路：** 初次加總字串各位數字。若總和不能被 9 整除則非 9 的倍數；否則反覆求各位和，遞增度數計數直到值為 9。 ==========================================================================


<a id="uva-10924_prime-words"></a>
### UVa 10924 — Prime Words／質數單字

- 原始碼：[10924_prime-words.c](10924_prime-words.c)
- 演算法：字元映射、質數判定（String, Prime Test）

**English description:**

Map lowercase letters to 1 through 26 and uppercase letters to 27 through 52. Sum the values in each input word, test the sum for primality under the problem's convention that 1 is prime, and output the classification.

**中文詳細描述：**

每行輸入一個英文字，將小寫 `a` 到 `z` 映射為 1 到 26，大寫 `A` 到 `Z` 映射為 27 到 52。加總所有字母值後判斷是否為質數；依題目定義 1 也算質數，最後輸出是否為 prime word。

<a id="uva-10924_prime-words-pr"></a>

### UVa 10924 — Prime Words／質數單字判定 (題目特殊定義 1 為質數)

- 原始碼：[10924_prime-words-pr.c](10924_prime-words-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, string

**English description:** Sum letter values (a=1..z=26, A=27..Z=52). Determine if sum is prime (problem defines 1 as prime!).

**中文詳細描述：** 計算單字中字母權重和 (a-z 為 1-26，A-Z 為 27-52)，判定總和是否為質數 (注意本題規定 1 視為質數)。

**English approach:** Calculate word sum. Check primality treating 1 as a prime per problem specification.

**中文解題思路：** 字元累加求和，標準質數測試判定，特判值為 1 時依題目特別約定回傳質數判定成立。 ==========================================================================


<a id="uva-10925_krakovia"></a>

### UVa 10925 — Krakovia／克拉科夫平攤帳單 (大數加法與除法)

- 原始碼：[10925_krakovia.c](10925_krakovia.c)
- 難度：Easy
- 演算法：big-integer, math

**English description:** Sum up the costs of N items (large integers) and divide equally among F friends.

**中文詳細描述：** 計算 N 個物品的大整數費用總和，並平均分攤給 F 位朋友。

**English approach:** Big integer addition to accumulate total cost, followed by big integer division by single-precision integer F.

**中文解題思路：** 高精度大數加法累計總開銷，再進行高精度除以低精度整數 F 求得每人應付金額。 ==========================================================================


<a id="uva-10926_how-many-dependencies"></a>

### UVa 10926 — How Many Dependencies?／多少依賴項？ (有向圖可達節點計數)

- 原始碼：[10926_how-many-dependencies.c](10926_how-many-dependencies.c)
- 難度：Easy
- 演算法：graph, dfs, transitive-closure

**English description:** Find the task in a dependency graph that has the maximum total number of dependencies (reachable nodes).

**中文詳細描述：** 求有向依賴圖中能夠抵達最多其他節點（依賴任務總數最多）的任務編號。

**English approach:** Run DFS from each node 1 to n to count distinct reachable descendants. Pick the node with maximum reachable count.

**中文解題思路：** 從每個節點出發進行 DFS 遍歷，統計該節點可抵達的相異子節點總數，取計數最大且編號最小的節點。 ==========================================================================


<a id="uva-10928_my-dear-neighbours"></a>

### UVa 10928 — My Dear Neighbours／親愛的鄰居

- 原始碼：[10928_my-dear-neighbours.c](10928_my-dear-neighbours.c)
- 難度：Easy
- 演算法：graph, degree

**English description:** Find all places that have the minimum number of neighbours in a neighborhood graph.

**中文詳細描述：** 求社區圖中鄰居數量最少（度數最小）的所有地點編號。

**English approach:** Parse lines to count neighbors (degrees) for each place. Find minimum degree, then print all places with that degree.

**中文解題思路：** 讀取每戶鄰居清單統計節點度數，求最小度數並升序輸出所有度數最小的節點。 ==========================================================================


<a id="uva-10929_you-can-say-11"></a>
### UVa 10929 — You can say 11／你可以說 11

- 原始碼：[10929_you-can-say-11.c](10929_you-can-say-11.c)
- 演算法：11 的整除規則（Number Theory, Divisibility）

**English description:**

Read decimal integers that may be too long for built-in numeric types. For each value, use the alternating sum of its digits to decide divisibility by 11, and output the required divisibility sentence.

**中文詳細描述：**

逐筆讀入可能超過內建整數範圍的十進位字串，直到終止值。把奇數位置與偶數位置的數字分別加總並取差；若差能被 11 整除，原數也能被 11 整除，最後按指定句型輸出判定。

<a id="uva-10929_you-can-say-11-pr"></a>

### UVa 10929 — You can say 11／11的倍數檢測 (奇偶位數交替和)

- 原始碼：[10929_you-can-say-11-pr.c](10929_you-can-say-11-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, big-integer

**English description:** Determine whether a huge integer up to 1000 digits is divisible by 11.

**中文詳細描述：** 判定最多 1000 位數的超大整數是否能被 11 整除 (奇數位與偶數位數字交替和之差為 11 的倍數)。

**English approach:** Sum alternating digits: (d_0 - d_1 + d_2 - d_3 ...) % 11 == 0.

**中文解題思路：** 利用 11 的同餘整除法則：奇數位數字和與偶數位數字和的差值若能被 11 整除，則原數能被 11 整除。 ==========================================================================


<a id="uva-10931_parity"></a>
### UVa 10931 — Parity／位元同位值

- 原始碼：[10931_parity.c](10931_parity.c)
- 演算法：二進位轉換、位元計數（Base Conversion, Bit Count）

**English description:**

For every positive integer until the terminating zero, convert it to binary and count the number of one bits. Output the binary representation and its parity count in the prescribed format.

**中文詳細描述：**

逐筆讀入正整數直到 0，將每個數反覆除以 2 取得其二進位表示，同時計算其中位元 1 的個數。最後依題目格式輸出二進位字串及其 parity 值。

<a id="uva-10931_parity-pr"></a>

### UVa 10931 — Parity／二進位奇偶校驗與位元計數

- 原始碼：[10931_parity-pr.c](10931_parity-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：bit-manipulation, math

**English description:** Print binary representation of I and its parity (count of set bits 1).

**中文詳細描述：** 印出十進位整數 I 的二進位表示法及其奇偶校驗位 (即二進位中 1 的個數)。

**English approach:** Convert integer to binary string by repeatedly dividing by 2. Count bits with value 1.

**中文解題思路：** 除以 2 取餘數構建二進位字串，統計其中字元 '1' 的總個數並格式化輸出。 ==========================================================================


<a id="uva-10935_throwing-cards-away-i"></a>

### UVa 10935 — Throwing cards away I／丟紙牌模擬 I (佇列拋牌與底牌)

- 原始碼：[10935_throwing-cards-away-i.c](10935_throwing-cards-away-i.c)
- 難度：UVa Star 1
- 演算法：data-structures, queue, simulation

**English description:** Given deck of n cards (1 on top, n on bottom). Discard top card, move next top to bottom. Output discarded sequence and last card.

**中文詳細描述：** 依序丟棄牌頂第 1 張牌，並將接下來的頂牌移至牌底，重複執行直到剩下最後 1 張牌。輸出丟棄序列與最後底牌。

**English approach:** Queue simulation: dequeue discarded, dequeue next and enqueue to back, repeat while size > 1.

**中文解題思路：** 標準環狀佇列模擬：每次出隊一張加入被棄列表，再將下一張牌出隊並壓入隊尾，直到佇列僅剩 1 張牌。 ==========================================================================


<a id="uva-10940_throwing-cards-away-ii"></a>

### UVa 10940 — Throwing cards away II／大牌組拋牌底牌最後保留紙牌 (二的冪次方)

- 原始碼：[10940_throwing-cards-away-ii.c](10940_throwing-cards-away-ii.c)
- 難度：UVa Star 2
- 演算法：math

**English description:** For a deck of N cards (up to 500,000), find the last remaining card after repeatedly discarding top and moving next to bottom.

**中文詳細描述：** 對於多達 500,000 張牌的牌堆，交替丟棄頂牌並將下一張置於牌底，求最後剩下的一張牌 (利用 2 的冪次 closed-form 公式)。

**English approach:** Josephus power-of-2 variant: if N == 1, 1. Otherwise find largest power of 2: L = 2^floor(log2(N)). If N == L, answer is N; else 2 * (N - L).

**中文解題思路：** 約瑟夫環二的次方公式：令 L 為小於等於 N 的最大 2 的冪次；若 N == L 則答案為 N；否則最後底牌為 2 * (N - L)。 ==========================================================================


<a id="uva-10943_how-do-you-add"></a>
### UVa 10943 — How do you add?／你要怎麼加？

- 原始碼：[10943_how-do-you-add.c](10943_how-do-you-add.c)
- 演算法：動態規劃、組合數（Dynamic Programming, Combinatorics）

**English description:**

Given `N` and `K`, count the ordered ways to express `N` as the sum of exactly `K` non-negative integers. Output the count modulo 1,000,000 for each pair.

**中文詳細描述：**

每筆輸入給出 `N` 與 `K`，要計算把 `N` 表示成恰好 `K` 個非負整數有序相加的方式數；不同排列視為不同方式。以動態規劃累積各總和與項數的答案，最後輸出對 1,000,000 取餘數的結果。

<a id="uva-10945_mother-bear"></a>

### UVa 10945 — Mother bear／母熊迴文語句過濾判斷

- 原始碼：[10945_mother-bear.c](10945_mother-bear.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Check if a given sentence is a palindrome, ignoring case and all non-alphabetical punctuation symbols.

**中文詳細描述：** 判斷給定句子是否為迴文，比對時忽略字母大小寫以及所有標點符號與空格。

**English approach:** Two pointers from start and end. Advance pointers while current char is not an alphabet. Compare lowercased characters.

**中文解題思路：** 雙指針分別指向字串頭尾，遇到非英文字母直接跳過，轉換為小寫後逐一比對兩端字元是否相符。 ==========================================================================


<a id="uva-10946_you-want-what-filled"></a>

### UVa 10946 — You want what filled?／你想填滿什麼？

- 原始碼：[10946_you-want-what-filled.c](10946_you-want-what-filled.c)
- 難度：Easy
- 演算法：dfs, flood-fill, sorting

**English description:** Given a grid of characters, count the size of connected components for each non-'.' character and sort descending by size, then ascending by character.

**中文詳細描述：** 給定一個字元網格，計算每個非 '.' 字元的連通分量大小，並按大小降序、字元升序排序。

**English approach:** Standard flood fill DFS on 4-neighbors for each unvisited non-'.' cell. Collect sizes and characters, then qsort.

**中文解題思路：** 對每個未訪問的非 '.' 網格點進行四方向 DFS 連通塊著色，統計大小與字元後排序。 ==========================================================================


<a id="uva-10948_the-primary-problem"></a>

### UVa 10948 — The primary problem／哥德巴赫猜想質數和分解

- 原始碼：[10948_the-primary-problem.c](10948_the-primary-problem.c)
- 難度：UVa Star 1
- 演算法：number-theory, math

**English description:** Express an even integer N as the sum of two prime numbers p1 + p2 with maximum difference (p1 <= p2).

**中文詳細描述：** 將偶數整數 N 分解為兩質數之和 p1 + p2 (滿足 p1 <= p2 且 p1 盡可能小)。

**English approach:** Precompute prime sieve. For each prime p1 starting at 2, check if N - p1 is also prime.

**中文解題思路：** 建立質數表，自 p1 = 2 開始循序檢驗 N - p1 是否亦為質數，找到首組解即為 p1 最小之最優解。 ==========================================================================


<a id="uva-10954_add-all"></a>
### UVa 10954 — Add All／全部相加

- 原始碼：[10954_add-all.c](10954_add-all.c)
- 演算法：貪心、最小堆（Greedy, Min Heap）

**English description:**

The input gives numbers that must be combined until one value remains. Combining two values costs their sum and inserts that sum back; choose the order that minimizes the total cost and output that minimum.

**中文詳細描述：**

每組輸入有多個數字，每次選兩個相加，該次成本是兩數之和，並把和放回集合，直到只剩一個數。要讓所有中間成本總和最小，因此每次從最小堆取出最小的兩個數合併，最後輸出累計成本。

<a id="uva-10959_the-party-part-i"></a>

### UVa 10959 — The Party, Part I／舞會派對 I (吉奧瓦尼號數 / 廣度優先搜尋)

- 原始碼：[10959_the-party-part-i.c](10959_the-party-part-i.c)
- 難度：Easy
- 演算法：graph, bfs, shortest-path

**English description:** Find the Giovanni number (shortest distance from host 0) for every guest at a ballroom dance party.

**中文詳細描述：** 求舞會派對中每位客人與主持人 0 號的最短舞伴距離（吉奧瓦尼號數）。

**English approach:** Standard BFS starting from host 0 on an unweighted undirected graph.

**中文解題思路：** 以 0 號主持人為起點進行無權圖 BFS，求每個節點的最短距離。 ==========================================================================


<a id="uva-10963_the-swallowing-ground"></a>

### UVa 10963 — The Swallowing Ground／地陷裂縫南北閉合一致性檢驗

- 原始碼：[10963_the-swallowing-ground.c](10963_the-swallowing-ground.c)
- 難度：UVa Star 1
- 演算法：basics, math

**English description:** Determine if ground fissure can be completely closed by checking if the gap y1 - y2 is identical across all grid columns.

**中文詳細描述：** 檢驗地震裂縫是否可藉由單向滑動完全密合：檢查每一縱行之南北裂縫間距 (y1 - y2) 是否完全一致。

**English approach:** Compute gap = y1 - y2 for first column. Check that all remaining columns have the identical gap.

**中文解題思路：** 計算首列之間距 y1 - y2，檢驗後續所有欄位的間距是否皆與第一列完全相等，全數相符則可閉合。 ==========================================================================


<a id="uva-10970_big-chocolate"></a>

### UVa 10970 — Big Chocolate／大巧克力最少分割刀數

- 原始碼：[10970_big-chocolate.c](10970_big-chocolate.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Find minimum number of cuts to break an M x N chocolate bar into 1 x 1 pieces.

**中文詳細描述：** 將 M x N 大小的巧克力塊切成 1x1 的獨立小方塊，求最少需切割的刀數。

**English approach:** Each cut increases total number of pieces by 1. To reach M*N pieces from 1, exactly M*N - 1 cuts are needed.

**中文解題思路：** 每切一刀使塊數增加 1。由 1 塊分割為 M*N 個單元塊，所需切割刀數恆等於 M*N - 1。 ==========================================================================


<a id="uva-10976_fractions-again"></a>

### UVa 10976 — Fractions Again?!／分數拆解 (1/k = 1/x + 1/y 埃及分數列舉)

- 原始碼：[10976_fractions-again.c](10976_fractions-again.c)
- 難度：UVa Star 1
- 演算法：math, brute-force

**English description:** Find all positive integer pairs x >= y such that 1/k = 1/x + 1/y.

**中文詳細描述：** 給定整數 k，求所有滿足 1/k = 1/x + 1/y 且 x >= y 的正整數對 (x, y)。

**English approach:** Since x >= y, we have y in [k + 1, 2k]. From 1/x = 1/k - 1/y = (y - k) / (k*y), x = (k*y) / (y - k). Valid if (k*y) % (y - k) == 0.

**中文解題思路：** 不等式推導：因 x >= y > k，y 的範圍嚴格落在 [k + 1, 2k]。枚舉 y，當 (k*y) % (y - k) == 0 時求出對應整數 x。 ==========================================================================


<a id="uva-10978_lets-play-magic"></a>

### UVa 10978 — Let's Play Magic!／玩魔術！ (拼詞數牌撲克牌還原)

- 原始碼：[10978_lets-play-magic.c](10978_lets-play-magic.c)
- 難度：Easy
- 演算法：simulation, array

**English description:** Reconstruct the initial deck arrangement of N cards from a sequence of (card, word) pairs where each card is placed after counting empty slots by word length.

**中文詳細描述：** 根據依單字字母長度數空卡槽放置卡片的過程，還原初始 N 張撲克牌的擺放順序。

**English approach:** Start with N empty slots. For each (card, word), advance pointer across unoccupied slots by length(word) positions circularly and place the card.

**中文解題思路：** 建立長度為 N 的空環形陣列，對每張牌依單字字母數在未佔用的空位上循環數步，停步處即為該卡牌位置。 ==========================================================================


<a id="uva-10986_sending-email"></a>

### UVa 10986 — Sending email／伺服器郵件路由最短延遲時間

- 原始碼：[10986_sending-email.c](10986_sending-email.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, shortest-path

**English description:** Find the minimum latency path to route an email from source server S to destination server T in an undirected network.

**中文詳細描述：** 在帶有權重的無向伺服器網路中，求將電子郵件自來源主機 S 傳送至目標主機 T 的最短延遲時間。

**English approach:** Dijkstra's shortest path algorithm. Return distance to T, or -1 if unreachable.

**中文解題思路：** 以標準 Dijkstra 演算法求解單源最短路徑，維護最小距離陣列，若目的地不可達則回傳 -1。 ==========================================================================


<a id="uva-10991_region"></a>

### UVa 10991 — Region／三圓相切封閉區域面積

- 原始碼：[10991_region.c](10991_region.c)
- 難度：Medium
- 演算法：geometry, trigonometry, area

**English description:** Calculate the area of the region bounded by three pairwise mutually externally tangent circles.

**中文詳細描述：** 給定三個兩兩外切圓的半徑 r1, r2, r3，計算由三圓所圍出的中央封閉區域面積。

**English approach:** Sides of triangle formed by circle centers are a=r2+r3, b=r1+r3, c=r1+r2. Area = Heron's area - sum of 3 circular sector areas.

**中文解題思路：** 以三圓心形成的三角形邊長為 a=r2+r3, b=r1+r3, c=r1+r2，用海龍公式求三角形面積，扣除三個圓心角對應的扇形面積。 ==========================================================================


<a id="uva-10994_simple-addition"></a>

### UVa 10994 — Simple Addition／簡單加法數列 (末位非零數遞歸求和)

- 原始碼：[10994_simple-addition.c](10994_simple-addition.c)
- 難度：Easy
- 演算法：math, recursion

**English description:** Function F(n) = n % 10 if n % 10 > 0, else F(n / 10). Compute sum of F(i) for i from p to q.

**中文詳細描述：** 函數 F(n)：若末位大於 0 則為末位數字，否則為 F(n/10)。求 F(i) 在區間 [p, q] 上的總和。

**English approach:** Evaluate S(n) = sum_{i=1}^n F(i). In each block of 10 numbers, sum of non-zero last digits is 45. Multiples of 10 recurse as S(n / 10). Answer = S(q) - S(p - 1).

**中文解題思路：** 求前綴和 S(n) = sum_{i=1}^n F(i)：每 10 個數產生一個 1..9 和 45，結尾為 0 的數除以 10 遞迴累加 S(n/10)。 ==========================================================================
