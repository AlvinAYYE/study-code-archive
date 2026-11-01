# UVa Volume 003

本卷收錄 38 份 C 解答，涵蓋 38 個 UVa 題號，以下依題號排序。

<a id="uva-300_maya-calendar"></a>

### UVa 300 — Maya Calendar／瑪雅曆法轉換

- 原始碼：[300_maya-calendar.c](300_maya-calendar.c)
- 難度：Easy
- 演算法：math, simulation, calendar

**English description:** Convert dates from the Haab solar calendar (365 days) to the Tzolkin religious calendar (260 days).

**中文詳細描述：** 將日期由 365 天的哈布曆 (Haab) 轉換為 260 天的卓爾金曆 (Tzolkin)。

**English approach:** Compute total days = year * 365 + month_index * 20 + day. Then Tzolkin year = total / 260, number = (total % 13) + 1, name = name_list[total % 20].

**中文解題思路：** 先算出從曆元起的總天數，再以 260 模算求得卓爾金曆年份、(total%13)+1 數字及 total%20 守護神名稱。 ==========================================================================


<a id="uva-301_transportation"></a>

### UVa 301 — Transportation／客運訂單最大收益 (回溯搜索剪枝)

- 原始碼：[301_transportation.c](301_transportation.c)
- 難度：Medium
- 演算法：backtracking, dfs, pruning

**English description:** A train of capacity B travels stations 0..B. Choose subset of passenger orders to maximize ticket revenue without exceeding capacity.

**中文詳細描述：** 容量為 B 的列車沿 0 到 B 站行駛，從眾多客運訂單中選取子集使得各站乘客數均不超載，並最大化總客票收入。

**English approach:** DFS backtrack over orders: either accept order (if all stations along [start, end) have remaining capacity >= passengers) or reject it. Branch and bound pruning.

**中文解題思路：** 對各訂單進行回溯決策（選或不選）：選取時扣減沿途各區間容量，若後續剩餘所有訂單價值全加仍不超過已知最優解則強力剪枝。 ==========================================================================


<a id="uva-305_joseph"></a>

### UVa 305 — Joseph／約瑟夫的倖存計謀 (前 k 名好人保全)

- 原始碼：[305_joseph.c](305_joseph.c)
- 難度：UVa Star 2
- 演算法：math, simulation, josephus

**English description:** Find smallest step m such that among 2k people (k good then k bad), all k bad people are executed before any good person.

**中文詳細描述：** 2k 個人圍成一圈 (前 k 個好人，後 k 個壞人)，求最小報數間隔 m 使得所有壞人都在好人之前被處決。

**English approach:** Math cycle simulation. Since k < 14, m must be congruent to 0 or 1 mod (k+1). Precompute answers for 1 <= k < 14.

**中文解題思路：** 以約瑟夫位置公式模擬淘汰過程。因 k < 14，直接枚舉 m 進行驗證，或預先計算打表可在 O(1) 輸出。 ==========================================================================


<a id="uva-307_sticks"></a>

### UVa 307 — Sticks／小木棍拼接

- 原始碼：[307_sticks.c](307_sticks.c)
- 難度：Hard
- 演算法：backtracking, dfs, pruning

**English description:** Given several cut stick segments, find the minimum possible original length of the uncut sticks such that all sticks were initially of equal length.

**中文詳細描述：** 給定若干被切斷的小木棍長度，求原始小木棍在長度均相等的情況下的最小可能原長度。

**English approach:** Sort descending. Candidate original length L must divide total length and L >= max_len. Backtrack with aggressive pruning.

**中文解題思路：** 降序排序，原始長度 L 必為總和的因數且 L >= 最大長度。進行強力剪枝的回溯搜尋。 ==========================================================================


<a id="uva-311_packets"></a>

### UVa 311 — Packets／裝箱問題 (貪婪裝入 6x6 箱子)

- 原始碼：[311_packets.c](311_packets.c)
- 難度：UVa Star 2
- 演算法：greedy, math

**English description:** Given quantities of 1x1 through 6x6 items, find minimum number of 6x6 parcels needed to pack them.

**中文詳細描述：** 給定尺寸 1x1 至 6x6 的六種包裹數量，求最少需要多少個 6x6 的大箱子才能全部裝下。

**English approach:** Greedy strategy from largest (6x6) to smallest (1x1). Fill leftover gaps with smaller items.

**中文解題思路：** 由大到小貪婪裝箱：6x6 各自一箱；5x5 剩餘空間填 1x1；4x4 剩餘填 2x2 再填 1x1；3x3 每 4 個一箱，餘數用 2x2 與 1x1 填滿。 ==========================================================================


<a id="uva-314_robot"></a>

### UVa 314 — Robot／機器人網格最短路徑

- 原始碼：[314_robot.c](314_robot.c)
- 難度：Medium
- 演算法：graph, bfs, shortest-path

**English description:** Find the minimum time for a robot to navigate a grid with obstacle blocks by moving forward 1-3 steps or turning.

**中文詳細描述：** 在帶障礙物的方格網中，求機器人從起點沿格線行走到終點所需的最少時間（可前進 1~3 格，或左右轉 90 度）。

**English approach:** BFS with state (r, c, dir). Robot is located on intersections of grid lines; blocks occupy grid squares.

**中文解題思路：** 以 (r, c, 方向) 為狀態進行 BFS，注意機器人是在頂點行進，若相鄰的 4 個格子中有障礙物則該交點不可通行。 ==========================================================================


<a id="uva-315_network"></a>

### UVa 315 — Network／關鍵伺服器頂點 (Tarjan 割點演算法)

- 原始碼：[315_network.c](315_network.c)
- 難度：UVa Star 2
- 演算法：graph, tarjan, articulation-points

**English description:** Find number of articulation points (critical nodes whose removal disconnects the network).

**中文詳細描述：** 在無向連通網路中求割點 (關節點) 的總數量，即移除該點會導致網路分裂不連通的伺服器個數。

**English approach:** Tarjan's DFS articulation points algorithm tracking discovery time dfn[u] and lowest reachable time low[u].

**中文解題思路：** 以 Tarjan 演算法深度優先遍歷圖，維護時間戳 dfn 與追溯值 low。若非根節點存在 low[v] >= dfn[u] 則 u 為割點。 ==========================================================================


<a id="uva-320_border"></a>

### UVa 320 — Border／走邊界圖案繪製

- 原始碼：[320_border.c](320_border.c)
- 難度：Medium
- 演算法：simulation, grid, bitmap

**English description:** Given a start point and direction moves along the border of an object on a 32x32 grid, mark the boundary cells and output the bitmap.

**中文詳細描述：** 給定在 32x32 網格上的起點與沿著物體外框走的移動指令（E, W, N, S），標記所有相鄰邊界的單元格並繪製點陣圖。

**English approach:** Simulate the border walk. Moving E fills cell (x, y-1); N fills (x, y); W fills (x-1, y); S fills (x-1, y-1).

**中文解題思路：** 模擬邊界行走路徑：向東走標記 (x, y-1)，向北走標記 (x, y)，向西走標記 (x-1, y)，向南走標記 (x-1, y-1)。 ==========================================================================


<a id="uva-324_factorial-frequencies"></a>

### UVa 324 — Factorial Frequencies／階乘數字頻率統計

- 原始碼：[324_factorial-frequencies.c](324_factorial-frequencies.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Compute n! (up to 366!) using high precision and count frequency of each digit 0-9.

**中文詳細描述：** 計算大數階乘 n! (最大 366!)，並統計結果中數字 0 到 9 各自出現的次數。

**English approach:** BigInt multiplication simulation using base-10 array. Count digits in resulting big integer.

**中文解題思路：** 以陣列模擬大數高精度乘法，由 1 連乘到 n。最後線性巡訪每一位數累積統計各數字出現頻率。 ==========================================================================


<a id="uva-325_identifying_legal_pascal_real_constants"></a>

### UVa 325 — Identifying Legal Pascal Real Constants／判斷合法的 Pascal 實數常數

- 原始碼：[325_identifying_legal_pascal_real_constants.c](325_identifying_legal_pascal_real_constants.c)
- 難度：Medium
- 演算法：string, parser, regex

**English description:** Determine whether a given string is a syntactically valid Pascal real number constant.

**中文詳細描述：** 判斷給定字串是否為語法正確的 Pascal 實數常數（必須包含小數點且前後均有數字，或包含指數 E/e 且指數為整數）。

**English approach:** Trim whitespace, parse optional sign, digits, decimal part (must have digits before and after '.'), and optional exponent 'e'/'E' with optional sign and digits.

**中文解題思路：** 解析符號、前導數字、小數點（小數點前後皆必須有數字）以及可選的指數部分（E/e 及其整數指數）。 ==========================================================================


<a id="uva-326_extrapolation_using_a_difference_table"></a>

### UVa 326 — Extrapolation Using a Difference Table／差分表外插預測

- 原始碼：[326_extrapolation_using_a_difference_table.c](326_extrapolation_using_a_difference_table.c)
- 難度：Easy
- 演算法：math, polynomials, difference-table

**English description:** Use forward differences table to extrapolate a sequence of n values by k steps.

**中文詳細描述：** 利用階差分表（差分三角陣列）將給定的 n 項數列向前外推 k 個新數值。

**English approach:** Construct table diff[i] = diff[i+1] - diff[i]. For each of the k steps, accumulate differences upwards from the last level.

**中文解題思路：** 構建差分表直到頂層階差，外推時自下而上進行 k 次累加，更新末端元素得到外推值。 ==========================================================================


<a id="uva-331_mapping_the_swaps"></a>

### UVa 331 — Mapping the Swaps／氣泡排序最小相鄰交換序列數

- 原始碼：[331_mapping_the_swaps.c](331_mapping_the_swaps.c)
- 難度：Medium
- 演算法：backtracking, bubble-sort, permutation

**English description:** Count the number of distinct minimal sequences of adjacent swaps that sort a given array.

**中文詳細描述：** 計算將給定數列透過最小次數的相鄰元素交換（如同氣泡排序）排成升序的不同交換序列總數。若原數列已有序則為 0。

**English approach:** Use backtracking to find all sequences of adjacent inversions. If array already sorted, output 0. Otherwise, branch on any adjacent inverted pair.

**中文解題思路：** 回溯搜尋相鄰逆序對進行交換。若初始即有序輸出 0；否則每次枚舉相鄰逆序位置 a[i] > a[i+1] 交換並遞歸。 ==========================================================================


<a id="uva-332_rational-numbers-from-repeating-fractions"></a>

### UVa 332 — Rational Numbers from Repeating Fractions／循環小數化分數

- 原始碼：[332_rational-numbers-from-repeating-fractions.c](332_rational-numbers-from-repeating-fractions.c)
- 難度：Easy
- 演算法：math, number-theory, gcd

**English description:** Convert a decimal fraction with k repeating digits and (d - k) non-repeating digits into an irreducible fraction p / q.

**中文詳細描述：** 將末尾含 k 位循環節的十進位小數（前含 d-k 位非循環節）化為最簡分數 p / q。

**English approach:** Numerator = floor(X * 10^d) - floor(X * 10^(d-k)). Denominator = 10^d - 10^(d-k). If k == 0: X * 10^d / 10^d. Simplify by gcd.

**中文解題思路：** 分子為乘以 10^d 與乘以 10^(d-k) 的整數部分之差，分母為 10^d - 10^(d-k)（k=0 時分母為 10^d），以 gcd 約分。 ==========================================================================


<a id="uva-333_recognizing-good-isbns"></a>

### UVa 333 — Recognizing Good ISBNs／辨識合法 ISBN 書號

- 原始碼：[333_recognizing-good-isbns.c](333_recognizing-good-isbns.c)
- 難度：Easy
- 演算法：string, validation, checksum

**English description:** Determine if a string represents a valid 10-character ISBN according to cumulative prefix sum checksum.

**中文詳細描述：** 依據兩次前綴和累加校驗規則（s2[9] mod 11 == 0），檢驗字串是否為合法的 10 位 ISBN 書號。

**English approach:** Trim whitespace. Extract exactly 10 digits/letters. 'X' is only valid as the 10th digit with value 10. Compute s1 then s2; valid iff s2[9] % 11 == 0.

**中文解題思路：** 去除頭尾空格，驗證剛好含 10 個有效位元（數字或末位 'X'=10），計算兩次前綴和檢驗最終模 11 是否為 0。 ==========================================================================


<a id="uva-336_a-node-too-far"></a>

### UVa 336 — A Node Too Far／網路跳步不可達節點計數

- 原始碼：[336_a-node-too-far.c](336_a-node-too-far.c)
- 難度：UVa Star 1
- 演算法：graph, bfs, shortest-path

**English description:** Given network graph, starting node and TTL, count how many nodes cannot be reached within TTL steps.

**中文詳細描述：** 給定網路拓撲圖，在給定起點與 TTL 步數限制下，計算有多少個網路節點無法在 TTL 步內到達。

**English approach:** Breadth-First Search (BFS) from source node up to depth TTL. Answer is total nodes minus visited nodes.

**中文解題思路：** 以起點進行 BFS 走訪，記錄各節點最短距離。不可達節點數即為圖中頂點總數扣除距離小於等於 TTL 的節點數。 ==========================================================================


<a id="uva-340_master-mind-hints"></a>

### UVa 340 — Master-Mind Hints／猜數字密碼提示 (幾A幾B)

- 原始碼：[340_master-mind-hints.c](340_master-mind-hints.c)
- 難度：UVa Star 1
- 演算法：simulation, array, game

**English description:** Given secret code and guesses, determine (A, B) hints: A = correct position and digit, B = correct digit but wrong position.

**中文詳細描述：** 經典 Master-Mind 幾 A 幾 B 遊戲：A 表示數字與位置皆正確；B 表示數字正確但位置不對。

**English approach:** First pass: match exact positions (A). Second pass: count frequency of remaining digits to compute B.

**中文解題思路：** 第一輪先比對位置與數值皆相等的個數計為 A，並標記已匹配；第二輪統計未匹配剩餘數字的頻率交集計為 B。 ==========================================================================


<a id="uva-341_non-stop-travel"></a>

### UVa 341 — Non-Stop Travel／最快暢行路徑 (Dijkstra 最短路徑與路徑重構)

- 原始碼：[341_non-stop-travel.c](341_non-stop-travel.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, shortest-path

**English description:** Find shortest path and path sequence between two intersections in traffic network.

**中文詳細描述：** 在街道交通網路中尋找兩十字路口間的最短時間路徑，並輸出完整經過路徑與總耗時。

**English approach:** Dijkstra's shortest path algorithm maintaining parent pointers for path reconstruction.

**中文解題思路：** 標準 Dijkstra 最短路徑演算法，以 parent 陣列記錄前驅節點，最後遞迴輸出路徑序列。 ==========================================================================


<a id="uva-343_what-base-is-this"></a>

### UVa 343 — What Base Is This?／這是幾進位？(任意進位等值搜尋)

- 原始碼：[343_what-base-is-this.c](343_what-base-is-this.c)
- 難度：UVa Star 2
- 演算法：math, base-conversion, brute-force

**English description:** Find smallest bases B1 and B2 (2 <= B <= 36) such that string X in base B1 equals string Y in base B2.

**中文詳細描述：** 尋找最小進位 B1 與 B2 (2 <= B <= 36)，使得字串 X 在 B1 進位下的數值等於字串 Y 在 B2 進位下的數值。

**English approach:** Determine min valid base for both strings. Loop B1 and B2 from min base to 36, parse to base 10 and compare.

**中文解題思路：** 找出兩字串字元決定的最小合法基底，雙層迴圈枚舉 B1 與 B2 (2..36)，轉為十進位比對數值是否相等。 ==========================================================================


<a id="uva-344_roman-digititis"></a>

### UVa 344 — Roman Digititis／羅馬數字字母頻率統計

- 原始碼：[344_roman-digititis.c](344_roman-digititis.c)
- 難度：UVa Star 1
- 演算法：simulation, string, math

**English description:** Count cumulative total occurrences of i, v, x, l, c across all page numbers 1 through N written in Roman numerals.

**中文詳細描述：** 統計 1 到 N 所有頁碼寫成羅馬數字時，字母 i, v, x, l, c 累計出現的總次數 (N <= 100)。

**English approach:** Convert integer to Roman numeral by greedy subtraction of standard values, then tally character frequencies.

**中文解題思路：** 將整數依貪婪減法規則轉為羅馬數字字串，統計每個數的字元個數並建立前綴和陣列以快速回答。 ==========================================================================


<a id="uva-348_optimal-array-multiplication-sequence"></a>

### UVa 348 — Optimal Array Multiplication Sequence／最佳矩陣鏈乘積括號化

- 原始碼：[348_optimal-array-multiplication-sequence.c](348_optimal-array-multiplication-sequence.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, matrix-chain-multiplication

**English description:** Find optimal parenthesization of matrix chain multiplication to minimize scalar multiplications.

**中文詳細描述：** 求矩陣鏈相乘的最佳括號化方案，使純量乘法運算次數最小 (經典矩陣鏈乘積區間 DP)。

**English approach:** Interval dynamic programming: dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]). Store split points k.

**中文解題思路：** 經典區間動態規劃：枚舉長度與分割點 k，記錄最佳分割位置以遞迴印出完整括號表達式。 ==========================================================================


<a id="uva-350_pseudo-random-numbers"></a>

### UVa 350 — Pseudo-Random Numbers／偽隨機數生成週期

- 原始碼：[350_pseudo-random-numbers.c](350_pseudo-random-numbers.c)
- 演算法：循環偵測、模擬（cycle detection, simulation）

**English description:** A linear congruential generator produces `x(next) = (Z × x + I) mod M` from an initial value `L`. For each quadruple `Z I M L`, determine the length of the repeating cycle and print it with the case number. Four zeroes terminate the input.

**中文詳細描述：** 每筆輸入乘數 `Z`、增量 `I`、模數 `M` 與初值 `L`，依 `下一項 = (Z × 當前項 + I) mod M` 產生序列。記錄每個值第一次出現的步數，某值再次出現時，兩次步數差就是循環節長度；輸出案例編號與長度，四個 0 結束。

<a id="uva-352_the-seasonal-war"></a>

### UVa 352 — The Seasonal War／季節戰爭 (八方向連通鷹眼連通塊)

- 原始碼：[352_the-seasonal-war.c](352_the-seasonal-war.c)
- 難度：UVa Star 1
- 演算法：graph, flood-fill, dfs

**English description:** Count number of war eagles (connected components of 1s in 8 directions) in n x n binary image.

**中文詳細描述：** 在 n x n 的二值圖像中，計算 8 方向連通的作戰鷹群 (數值 1 形成的連通塊) 總數量。

**English approach:** Flood fill (DFS or BFS) in 8 directions. Mark visited pixels and count initiated traversals.

**中文解題思路：** 對地圖進行 8 方向深度優先搜尋 (DFS)，將已造訪的 '1' 淹沒標記，統計連通塊總數。 ==========================================================================


<a id="uva-353_pesky-palindromes"></a>

### UVa 353 — Pesky Palindromes／討厭的回文 (相異回文子字串計數)

- 原始碼：[353_pesky-palindromes.c](353_pesky-palindromes.c)
- 難度：UVa Star 1
- 演算法：string, palindrome, brute-force

**English description:** Count total number of unique palindromic substrings in a given string.

**中文詳細描述：** 計算給定字串中所有不重複的相異回文子字串總數。

**English approach:** Enumerate all substrings, check palindrome, insert into a unique set or sorted string array to count distinct matches.

**中文解題思路：** 枚舉所有可能子字串，判定是否為回文，並加入去重集合或以字串排序去重計算相異回文個數。 ==========================================================================


<a id="uva-355_the-bases-are-loaded"></a>

### UVa 355 — The Bases Are Loaded／基底全滿 (進位轉換驗證)

- 原始碼：[355_the-bases-are-loaded.c](355_the-bases-are-loaded.c)
- 難度：UVa Star 1
- 演算法：math, base-conversion, string

**English description:** Convert a number from base B1 to base B2 (2 <= B1, B2 <= 16), detecting invalid input digits.

**中文詳細描述：** 驗證字串是否為合法 B1 進位數，並將其正確轉換為 B2 進位表示法 (2 <= B1, B2 <= 16)。

**English approach:** Validate digits against base B1, convert to base 10 (using 64-bit integer), then convert to base B2 digits.

**中文解題思路：** 逐字元檢查是否小於進位 B1，以 64 位元整數算出十進位值，再反覆除以 B2 取餘數構建目標字串。 ==========================================================================


<a id="uva-356_square-pegs-and-round-holes"></a>

### UVa 356 — Square Pegs And Round Holes／方釘圓孔 (圓與網格完全包含及穿過計數)

- 原始碼：[356_square-pegs-and-round-holes.c](356_square-pegs-and-round-holes.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Given radius R = (2n - 1) / 2, count the number of 1x1 cells completely inside the circle and cells intersected by circle boundary.

**中文詳細描述：** 半徑為 R = (2n - 1) / 2 的圓覆蓋網格，求完全落在圓內的 1x1 網格數以及被圓周切割的網格數。

**English approach:** Symmetry across 4 quadrants. A 1x1 cell [x, x+1] x [y, y+1] is completely inside if outer corner (x+1)^2 + (y+1)^2 <= R^2. Intersects if inner corner <= R^2 and outer corner > R^2.

**中文解題思路：** 利用四象限對稱性：若外頂點 (x+1)^2 + (y+1)^2 <= R^2 則完全在圓內；若內外頂點跨越圓半徑則為相交邊界格。 ==========================================================================


<a id="uva-357_let-me-count-the-ways"></a>

### UVa 357 — Let Me Count The Ways／算算有多少種方法

- 原始碼：[357_let-me-count-the-ways.c](357_let-me-count-the-ways.c)
- 演算法：完全背包動態規劃（dynamic programming, coin change）

**English description:** For each amount in cents, count the unordered ways to make exactly that amount using unlimited U.S. coins of 1, 5, 10, 25, and 50 cents. Print the grammatically correct singular or plural sentence with the computed count.

**中文詳細描述：** 每行輸入一個以分為單位的金額，可不限枚數使用 1、5、10、25、50 分硬幣，計算組合而非排列的找零方法數。以完全背包依硬幣順序更新方法數，逐筆輸出答案，並依答案是否為 1 選用題目指定的單複數句型。

<a id="uva-369_combinations"></a>

### UVa 369 — Combinations／組合數精確計算 (防止溢位的 C(N, M))

- 原始碼：[369_combinations.c](369_combinations.c)
- 難度：UVa Star 1
- 演算法：math, combinatorics

**English description:** Compute exact combination C(N, M) for N <= 100 without intermediate 64-bit overflow.

**中文詳細描述：** 精確計算二項式係數 C(N, M) = N! / (M! * (N-M)!)，避免乘法中途發生數值溢位。

**English approach:** Pascal's identity C(n, k) = C(n-1, k-1) + C(n-1, k) or running multiplication with GCD division.

**中文解題思路：** 以巴斯卡三角形動態規劃預先建表，或在乘法過程中逐項除以因子，確保計算中途數值不溢位。 ==========================================================================


<a id="uva-371_ackermann-functions"></a>

### UVa 371 — Ackermann Functions／考拉茲序列極大值點

- 原始碼：[371_ackermann-functions.c](371_ackermann-functions.c)
- 難度：UVa Star 1
- 演算法：simulation, math, collatz

**English description:** Find integer in range [L, H] that produces the longest Collatz sequence (where f(1) continues to 4-2-1, len >= 3).

**中文詳細描述：** 尋找區間 [L, H] 內產生最長 3n+1 序列長度的整數 (注意 n=1 時依題目定義長度為 3)。

**English approach:** Collatz sequence simulation. Note special case: n=1 performs 1 step to 4, taking 3 steps to return to 1.

**中文解題思路：** 模擬 3n+1 運算流程。注意此題特別規定輸入為 1 時須執行一步變成 4 再回到 1 (長度為 3)。 ==========================================================================


<a id="uva-374_big-mod"></a>

### UVa 374 — Big Mod／大數快速冪模運算

- 原始碼：[374_big-mod.c](374_big-mod.c)
- 演算法：二進位快速冪（number theory, modular exponentiation）

**English description:** Repeatedly read integers `B`, `P`, and `M`, and compute `B^P mod M` without constructing the enormous power itself. Print one modular result for each input triple.

**中文詳細描述：** 每組輸入底數 `B`、指數 `P` 與模數 `M`，要求輸出 `B^P mod M`。利用指數的二進位分解反覆平方，每當目前位元為 1 就把該冪乘入答案，所有乘法過程立即取模，因此不用真的建立龐大的 `B^P`。

<a id="uva-377_cowmulting"></a>

### UVa 377 — Cowmulting／牛之四進制運算器

- 原始碼：[377_cowmulting.c](377_cowmulting.c)
- 難度：Medium
- 演算法：simulation, base-conversion, math

**English description:** Simulate a base-4 arithmetic processor with symbols 'V'=0, 'U'=1, 'C'=2, 'D'=3 and operations A, S, R, N.

**中文詳細描述：** 模擬以四進制字元 'V'=0, 'U'=1, 'C'=2, 'D'=3 表示的 8 位數運算器，支援加法、左移、右移與空操作。

**English approach:** Convert cow string to integer, perform simulated operations (Add, Shift left with 'V', Shift right, Nop), compare with expected result.

**中文解題思路：** 將符號轉換為 4 進制整數，按指令執行加法、左移填 0、右移等操作，並判斷最終暫存器數值是否與期望相符。 ==========================================================================


<a id="uva-378_intersecting-lines"></a>

### UVa 378 — Intersecting Lines／直線相交判斷與交點計算

- 原始碼：[378_intersecting-lines.c](378_intersecting-lines.c)
- 難度：UVa Star 2
- 演算法：geometry, math, linear-equations

**English description:** Given two 2D lines defined by points, determine if they are identical (LINE), parallel (NONE), or intersect (POINT x y).

**中文詳細描述：** 給定二維平面上的兩條直線，判定兩線是否重合 (LINE)、平行 (NONE) 或相交於單一點 (POINT x y)。

**English approach:** Cross product of direction vectors to check parallelism. If parallel, cross product with offset vector checks collinearity.

**中文解題思路：** 以直線一般式 A x + B y = C 求解克拉瑪法則，外積為 0 則平行；若常數項成比例則重合，否則求出唯一交點座標。 ==========================================================================


<a id="uva-382_perfection"></a>

### UVa 382 — Perfection／完美數、虧數與盈數判定

- 原始碼：[382_perfection.c](382_perfection.c)
- 演算法：因數枚舉、數論分類（number theory, divisors）

**English description:** For each positive integer, sum all of its proper positive divisors. Classify the number as `PERFECT` when the sum equals it, `DEFICIENT` when the sum is smaller, or `ABUNDANT` when the sum is larger, and print the classifications in the required report format. Input ends with zero.

**中文詳細描述：** 逐筆讀入正整數，列舉並加總其所有不含自身的正因數。因數和等於原數時分類為 `PERFECT`，小於原數為 `DEFICIENT`，大於原數為 `ABUNDANT`；依題目規定先後印出報表標頭、每個數的對齊結果與結尾，輸入 0 時停止。

<a id="uva-383_shipping-routes"></a>

### UVa 383 — Shipping Routes／貨物航線

- 原始碼：[383_shipping-routes.c](383_shipping-routes.c)
- 難度：Easy
- 演算法：graph, bfs, shortest-path

**English description:** Given a network of warehouse shipping legs, find the shortest path in legs between source and destination and calculate cost ($100 * size * legs).

**中文詳細描述：** 給定倉庫間的航線網絡，求起點到終點的最短航線段數，並計算運輸成本（$100 * 貨物大小 * 段數）。

**English approach:** Standard unweighted BFS to find the shortest hop distance between two warehouse nodes.

**中文解題思路：** 無權圖 BFS 最短路徑搜尋兩節點間的最少段數，若連通則費用為 legs * size * 100。 ==========================================================================


<a id="uva-384_slurmys"></a>

### UVa 384 — Slurmys／外星字串文法解析 (Slump, Slimp, Slurpy)

- 原始碼：[384_slurmys.c](384_slurmys.c)
- 難度：Medium
- 演算法：string, grammar, parsing

**English description:** Determine if a string is a Slurpy, which consists of a Slimp followed by a Slump.

**中文詳細描述：** 解析特定外星文法：判斷字串是否為 Slurpy（由一個 Slimp 後接一個 Slump 組成）。

**English approach:** Recursively check Slump and Slimp grammar rules according to the specification.

**中文解題思路：** 根據 Slump 和 Slimp 的形式文法定義，分別編寫遞歸解析函數判斷前綴與後綴。 ==========================================================================


<a id="uva-386_perfect-cubes"></a>

### UVa 386 — Perfect Cubes／完全立方等式 (a^3 = b^3 + c^3 + d^3)

- 原始碼：[386_perfect-cubes.c](386_perfect-cubes.c)
- 難度：UVa Star 1
- 演算法：math, brute-force

**English description:** Find all integer quadruples 2 <= b <= c <= d <= a <= 200 such that a^3 = b^3 + c^3 + d^3.

**中文詳細描述：** 求出所有滿足 a^3 = b^3 + c^3 + d^3 且 2 <= b <= c <= d <= a <= 200 的整數四元組。

**English approach:** Precompute cubes 1..200. Four nested loops with pruning b^3 + c^3 + d^3 <= a^3.

**中文解題思路：** 預先計算 1..200 的立方值。四重迴圈枚舉 a, b, c, d，利用單調性進行提早跳出剪枝。 ==========================================================================


<a id="uva-389_basically-speaking"></a>

### UVa 389 — Basically Speaking／基本進位制轉換

- 原始碼：[389_basically-speaking.c](389_basically-speaking.c)
- 演算法：進位制轉換（math, base conversion）

**English description:** Each input line contains a numeral, its source base, and its target base. Convert digits `0–9` and `A–F` through their numeric value, then right-align the target representation in a field of width seven. Print `ERROR` instead if the converted representation needs more than seven characters.

**中文詳細描述：** 每行輸入一個數字字串、原進位與目標進位，進位範圍使用 `0`–`9`、`A`–`F` 表示數字。先依原進位解析數值，再除以目標進位取得輸出字串；結果在寬度 7 的欄位中靠右輸出，若轉換後超過 7 個字元則輸出 `ERROR`。

<a id="uva-392_polynomial-showdown"></a>

### UVa 392 — Polynomial Showdown／多項式美觀格式化輸出

- 原始碼：[392_polynomial-showdown.c](392_polynomial-showdown.c)
- 難度：UVa Star 1
- 演算法：string, math

**English description:** Format a degree 8 polynomial given its 9 integer coefficients, omitting zero terms and formatting signs cleanly.

**中文詳細描述：** 給定 8 次多項式的 9 個係數，省略係數為 0 的項，美觀排版正負號與次方符號 (如 3x^2 - x + 5)。

**English approach:** Traverse coefficients from degree 8 down to 0. Handle leading sign, magnitude 1 for variable terms, and constant zero edge case.

**中文解題思路：** 自最高次降序走訪係數：首項負號緊隨其後、其餘項以 " + " 或 " - " 分隔，係數為 1 且次數大於 0 時省略係數。 ==========================================================================


<a id="uva-394_mapmaker"></a>

### UVa 394 — Mapmaker／地圖製作者 (數組定址計算)

- 原始碼：[394_mapmaker.c](394_mapmaker.c)
- 難度：Medium
- 演算法：data-structures, array-addressing

**English description:** Compute memory address of multi-dimensional array elements given base address, element size, and dimension bounds.

**中文詳細描述：** 給定多維數組的起始基底位址、元素大小及各維度上下界，計算指定下標的記憶體位址。

**English approach:** Use the standard row-major addressing formula: C_D = size, C_i = C_{i+1} * (U_{i+1} - L_{i+1} + 1), C_0 = B - sum(C_i * L_i). Address = C_0 + sum(C_i * i_k).

**中文解題思路：** 依照以列為主 (row-major) 映射公式計算常數 C_0 至 C_D，再代入下標求得記憶體位址。 ==========================================================================
