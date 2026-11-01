# UVa Volume 111

本卷收錄 18 份 C 解答，涵蓋 15 個 UVa 題號，以下依題號排序。

<a id="uva-11100_the-trip-2007"></a>

### UVa 11100 — The Trip, 2007／旅行2007 (背包嵌套與眾數)

- 原始碼：[11100_the-trip-2007.c](11100_the-trip-2007.c)
- 難度：Medium
- 演算法：greedy, sorting

**English description:** Nest bags inside strictly larger bags to minimize the total number of visible outer bags.

**中文詳細描述：** 小背包可嵌套放入嚴格大於它的背包中，求最少需要多少個外層背包。

**English approach:** The minimum number of outer bags k equals the maximum frequency of any bag size. Distribute elements into k chains by taking elements at stride k.

**中文解題思路：** 由抽屜原理可知，最小外層背包數 k 必等於出現次數最多的背包尺寸頻率。依跨度 k 交錯放入各背包鏈中。 ==========================================================================


<a id="uva-11110_equidivisions"></a>

### UVa 11110 — Equidivisions／等分網格連通性檢測

- 原始碼：[11110_equidivisions.c](11110_equidivisions.c)
- 難度：Easy
- 演算法：dfs, flood-fill, grid

**English description:** Determine if an n x n grid is partitioned into n connected regions of size n each.

**中文詳細描述：** 判定 n x n 的網格是否剛好被劃分為 n 個連通區域，且每個區域的格子數恰好均為 n。

**English approach:** Run flood fill DFS for each region label 1..n. Check that each region is a single connected component of size exactly n.

**中文解題思路：** 對每個區域編號 1..n 進行 DFS 洪水填充連通塊檢測，驗證每個區域均單一連通且大小剛好為 n。 ==========================================================================


<a id="uva-11111_generalized-matrioshkas"></a>

### UVa 11111 — Generalized Matrioshkas／廣義俄羅斯套娃 (堆疊配對與容量驗證)

- 原始碼：[11111_generalized-matrioshkas.c](11111_generalized-matrioshkas.c)
- 難度：Medium
- 演算法：stack, data-structures

**English description:** Verify if a sequence of negative (open) and positive (close) integers represents a valid set of generalized nested matrioshkas.

**中文詳細描述：** 驗證正負整數序列是否為合法嵌套的俄羅斯套娃（負數為開套娃，正數為封套娃，內部直接包含的套娃尺寸和嚴格小於外層）。

**English approach:** Use stack of pairs (size, inner_sum). Match -x with +x. Check that inner_sum < x at closure, then add x to parent's inner_sum.

**中文解題思路：** 使用堆疊維護 (尺寸, 內層尺寸總和)。負數入棧，遇到對應正數時檢查內層和嚴格小於外層尺寸，並累加至上一層父套娃。 ==========================================================================


<a id="uva-11121_base-2"></a>

### UVa 11121 — Base -2／負二進位轉換

- 原始碼：[11121_base-2.c](11121_base-2.c)
- 難度：Easy
- 演算法：math, number-base-conversion

**English description:** Convert a given integer into its base -2 (negative base) representation.

**中文詳細描述：** 將給定的十進位整數轉換為負二進位（base -2）表示法。

**English approach:** Divide by -2 repeatedly with non-negative remainder: if rem < 0, rem += 2 and quotient += 1.

**中文解題思路：** 對 -2 取餘數並向下整除：若餘數為負則餘數加 2 且商數加 1，倒序輸出餘數序列。 ==========================================================================


<a id="uva-11136_hoax-or-what"></a>

### UVa 11136 — Hoax or what／促銷摸彩箱極值差額發放總額

- 原始碼：[11136_hoax-or-what.c](11136_hoax-or-what.c)
- 難度：UVa Star 2
- 演算法：data-structures, multiset

**English description:** Bills are deposited into an urn daily. Each day, the highest and lowest bills are paid out, with difference awarded as prize money. Sum prizes.

**中文詳細描述：** 每日將顧客發票存入彩箱，每日營業結束時取出彩箱內面額最大與最小的發票發放差額獎金，求活動總獎金支出。

**English approach:** Maintain a multiset or frequency array. Each day extract maximum and minimum, add max - min to total cost, and decrement their counts.

**中文解題思路：** 以平衡樹或頻率統計陣列維護摸彩箱內現存發票，每日提取最大與最小值並從容器中刪除，將差值累加至總額。 ==========================================================================


<a id="uva-11137_ingenuous-cubrency"></a>

### UVa 11137 — Ingenuous Cubrency／立方數貨幣找零組合數動態規劃

- 原始碼：[11137_ingenuous-cubrency.c](11137_ingenuous-cubrency.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Find the number of ways to pay an amount N using cubic coin denominations 1^3, 2^3, ..., 21^3.

**中文詳細描述：** 使用 21 種立方數硬幣面額 (1^3, 2^3, ..., 21^3 = 9261) 湊出金額 N 的方法數 (完全背包計數)。

**English approach:** Unbounded knapsack DP: dp[j] += dp[j - coin]. Use 64-bit integers.

**中文解題思路：** 完全背包動態規劃：預先計算 21 個立方數面額，由小到大遞推更新 dp[j] += dp[j - coin]。 ==========================================================================


<a id="uva-11150_cola"></a>
### UVa 11150 — Cola／可樂

- 原始碼：[11150_cola.c](11150_cola.c)
- 演算法：貪心模擬、數學（Greedy, Simulation）

**English description:**

Starting with `n` full cola bottles, every three empty bottles can be exchanged for one full bottle. One empty bottle may be borrowed at the end when it can be repaid; output the maximum total number of bottles that can be drunk.

**中文詳細描述：**

輸入給一開始擁有的 `n` 瓶可樂，每喝完三瓶可用三個空瓶換一瓶新的；在最後可借一個空瓶，但必須能在交換後歸還。計算所有可行交換並輸出最多能喝幾瓶，結果可化簡為 `n + n/2`。

<a id="uva-11150_cola-pr"></a>

### UVa 11150 — Cola／喝可樂空瓶兌換 (借空瓶技巧)

- 原始碼：[11150_cola-pr.c](11150_cola-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, greedy

**English description:** Buy n colas. 3 empty bottles exchange for 1 new cola. You may borrow empty bottles as long as you return them. Maximize colas.

**中文詳細描述：** 買 n 瓶可樂，每 3 個空瓶換 1 瓶新可樂。允許向朋友借空瓶但最後必須還清，求最多能喝到幾瓶可樂。

**English approach:** Formula: total = n + n / 2 = 3 * n / 2.

**中文解題思路：** 貪婪借空瓶技巧：相當於每 2 個空瓶可淨喝 1 瓶新可樂，數學公式為 n + n / 2。 ==========================================================================


<a id="uva-11151_longest-palindrome"></a>

### UVa 11151 — Longest Palindrome／字串中最長迴文子序列區間 DP

- 原始碼：[11151_longest-palindrome.c](11151_longest-palindrome.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, string

**English description:** Find the length of the longest palindromic subsequence of a given string (not necessarily contiguous).

**中文詳細描述：** 計算給定字串中最長迴文子序列 (LPS，不必連續) 的最大長度。

**English approach:** Interval dynamic programming: dp[i][j] = dp[i+1][j-1] + 2 if s[i]==s[j], else max(dp[i+1][j], dp[i][j-1]).

**中文解題思路：** 區間動態規劃：若兩端字元相等則 dp[i][j] = dp[i+1][j-1] + 2；否則取兩側縮小區間之較大值 max(dp[i+1][j], dp[i][j-1])。 ==========================================================================


<a id="uva-11152_colourful-flowers"></a>

### UVa 11152 — Colourful Flowers／幾何花朵內切圓與外接圓面積差

- 原始碼：[11152_colourful-flowers.c](11152_colourful-flowers.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Compute area of sunflowers (circumcircle minus triangle), violets (triangle minus incircle), and roses (incircle) for given side lengths a, b, c.

**中文詳細描述：** 給定三角形三邊長 a, b, c，計算向日葵黃色區域 (外接圓扣除三角形)、紫羅蘭藍色區域 (三角形扣除內切圓) 與玫瑰紅色區域 (內切圓) 面積。

**English approach:** Semiperimeter s = (a+b+c)/2; Heron's formula for area T; incircle radius r = T/s; circumcircle radius R = abc / (4T). Compute circle areas pi*R^2 and pi*r^2.

**中文解題思路：** 海龍公式求面積 T，內切圓半徑 r = T/s，外接圓半徑 R = abc/(4T)，面積分別為 pi*R^2 - T、T - pi*r^2 與 pi*r^2。 ==========================================================================


<a id="uva-11157_dynamic-frog"></a>

### UVa 11157 — Dynamic Frog／動態青蛙過河 (貪心跳躍與最大間距)

- 原始碼：[11157_dynamic-frog.c](11157_dynamic-frog.c)
- 難度：Medium
- 演算法：greedy

**English description:** A frog must cross a river of width D and return. Big rocks can be stepped on twice; small rocks sink after one step. Minimize maximum leap distance.

**中文詳細描述：** 青蛙需橫渡寬度為 D 的河流並返回。大石頭可用兩次，小石頭踩過即沉，求往返過程中單次跳躍最大距離的最小值。

**English approach:** Greedy: duplicate big rocks. Take alternating small rocks on the forward trip, and remaining small rocks on the return trip. Maximize adjacent step differences.

**中文解題思路：** 貪心法：大石頭拆成兩塊；去程隔塊跳躍選取小石頭，回程使用剩餘的小石頭，取相鄰石頭間距的最大值即為答案。 ==========================================================================


<a id="uva-11172_relational-operator"></a>
### UVa 11172 — Relational Operator／關係運算子

- 原始碼：[11172_relational-operator.c](11172_relational-operator.c)
- 演算法：條件判斷（Basic I/O）

**English description:**

For each input pair of integers `a` and `b`, compare the two values and output exactly one of `>`, `<`, or `=` to describe their relation.

**中文詳細描述：**

每組輸入包含兩個整數 `a` 與 `b`。直接比較兩者大小，若 `a` 較大輸出 `>`、較小輸出 `<`，兩者相等則輸出 `=`。

<a id="uva-11172_relational-operator-pr"></a>

### UVa 11172 — Relational Operator／關係運算子大小比較

- 原始碼：[11172_relational-operator-pr.c](11172_relational-operator-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation

**English description:** Compare two integers a and b, outputting '>', '<', or '='.

**中文詳細描述：** 比較兩整數 a 與 b 的大小關係，輸出相應的大於、小於或等於運算子。

**English approach:** Simple if-else branching.

**中文解題思路：** 基礎條件判斷分支：a > b 輸出 '>'，a < b 輸出 '<'，否則輸出 '='。 ==========================================================================


<a id="uva-11173_grey-codes"></a>

### UVa 11173 — Grey Codes／格雷碼

- 原始碼：[11173_grey-codes.c](11173_grey-codes.c)
- 難度：Easy
- 演算法：bit-manipulation, gray-code

**English description:** Find the k-th entry in an n-bit binary reflected Gray code sequence.

**中文詳細描述：** 求 n 位二進位反射格雷碼序列中的第 k 個數值。

**English approach:** Standard Gray code conversion formula: G(k) = k ^ (k >> 1).

**中文解題思路：** 利用二進位格雷碼轉換公式直接求得：G(k) = k ^ (k >> 1)。 ==========================================================================


<a id="uva-11185_ternary"></a>
### UVa 11185 — Ternary／三進位

- 原始碼：[11185_ternary.c](11185_ternary.c)
- 演算法：進位轉換（Base Conversion）

**English description:**

Read non-negative decimal integers until the terminating negative value. Convert each number to base 3 by repeated division and output its ternary representation, handling zero explicitly.

**中文詳細描述：**

逐筆讀入非負十進位整數，遇到負數時結束。反覆除以 3 並收集餘數，再反向排列得到三進位表示；輸入為 0 時直接輸出 `0`，其餘逐筆輸出轉換結果。

<a id="uva-11185_ternary-pr"></a>

### UVa 11185 — Ternary／三進位制轉換

- 原始碼：[11185_ternary-pr.c](11185_ternary-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：base-conversion, math

**English description:** Convert non-negative decimal integer N into base 3 (ternary).

**中文詳細描述：** 將非負十進位整數 N 轉換為三進位制字串輸出。

**English approach:** Standard base conversion: repeatedly take N % 3, divide N by 3, reverse digits.

**中文解題思路：** 除以 3 取餘數法：反覆將數值除以 3 並收集餘數，最後將數位倒序輸出 (N=0 特判為 "0")。 ==========================================================================


<a id="uva-11192_group-reverse"></a>

### UVa 11192 — Group Reverse／分組字串原地翻轉

- 原始碼：[11192_group-reverse.c](11192_group-reverse.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Given string and number of groups G, reverse characters in each group of length len/G.

**中文詳細描述：** 將長度為 L 的字串平均分為 G 組 (每組長度 L/G)，將每組內部的字元各自原地反轉。

**English approach:** Group length k = L / G. For each group from start i = 0, k, 2k..., reverse slice [i, i + k - 1].

**中文解題思路：** 計算每組長度 k = strlen(s) / G。以步長 k 巡訪各分組起點，對 [i, i+k-1] 區間實施雙向對調翻轉。 ==========================================================================


<a id="uva-11195_another_n_queen_problem"></a>

### UVa 11195 — Another n-Queen Problem／帶障礙格的 N 皇后問題

- 原始碼：[11195_another_n_queen_problem.c](11195_another_n_queen_problem.c)
- 難度：Medium
- 演算法：backtracking, bitmask, n-queens

**English description:** Count the number of valid n-Queens arrangements on an n x n board with some squares blocked.

**中文詳細描述：** 在有部分格子為障礙物 '*' 的 n x n 棋盤上，計算可放置 n 個互不攻擊皇后的總方案數。

**English approach:** Use fast bitmask backtracking: track column, left-diagonal, and right-diagonal availability along with row obstacle mask.

**中文解題思路：** 使用經典位元運算回溯：利用位元遮罩維護列、主對角線、副對角線佔用狀態與該列障礙物遮罩。 ==========================================================================
