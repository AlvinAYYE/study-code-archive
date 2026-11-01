# UVa Volume 131

本卷收錄 7 份 C 解答，涵蓋 6 個 UVa 題號，以下依題號排序。

<a id="uva-13109_elephants"></a>

### UVa 13109 — Elephants／大象過橋最多數量 (貪婪重量排序)

- 原始碼：[13109_elephants.c](13109_elephants.c)
- 難度：UVa Star 1
- 演算法：greedy, sorting

**English description:** Find maximum number of elephants that can stand on a bridge of total capacity W.

**中文詳細描述：** 木橋最大載重為 W，求在不超出橋樑負載限制下，最多能讓多少隻大象同時上橋 (貪婪重量由小到大排序)。

**English approach:** Greedy choice: sort elephant weights in ascending order. Greedily pick lightest elephants while cumulative sum <= W.

**中文解題思路：** 貪婪策略：大象重量升序排序，優先選最輕的大象累加重量，直到超出承重限制為止。 ==========================================================================


<a id="uva-13130_cacho"></a>

### UVa 13130 — Cacho／Cacho 骰子連續順子判定 (Escala)

- 原始碼：[13130_cacho.c](13130_cacho.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Determine if 5 dice values form a consecutive straight (Escala) i.e. 1-2-3-4-5 or 2-3-4-5-6.

**中文詳細描述：** 判定 5 顆骰子的點數是否形成嚴格公差為 1 的連續順子 (即 a[i] == a[i-1] + 1)。

**English approach:** Check if d[i] == d[i-1] + 1 for all i in 1..4.

**中文解題思路：** 直接檢驗相鄰元素差值：若每一對相鄰骰子皆滿足 d[i] == d[i-1] + 1 則輸出 'Y'，否則輸出 'N'。 ==========================================================================


<a id="uva-13148_a_giveaway"></a>

### UVa 13148 — A Giveaway／雙重冪次判別 (既是平方又是立方)

- 原始碼：[13148_a_giveaway.c](13148_a_giveaway.c)
- 難度：Easy
- 演算法：math, number-theory

**English description:** Determine whether a number is 'Special' (both an integer square and an integer cube, i.e., a sixth power).

**中文詳細描述：** 判斷給定整數是否為「特殊數」（同時為整數的完全平方與完全立方，即六次方數）。

**English approach:** Compute round(pow(n, 1.0/6.0)) and verify if its 6th power equals n.

**中文解題思路：** 計算 n 的 1/6 次方四捨五入為整數 r，檢查 r^6 是否等於 n。 ==========================================================================


<a id="uva-13178_is-it-multiple-of-3"></a>
### UVa 13178 — Is it multiple of 3?／是 3 的倍數嗎？

- 原始碼：[13178_is-it-multiple-of-3.c](13178_is-it-multiple-of-3.c)
- 演算法：模運算、整除性（Number Theory）

**English description:**

For each input `N`, consider the huge decimal number formed by concatenating `1, 2, ..., N`. Determine whether that number is divisible by 3 and output the required answer without constructing the concatenation.

**中文詳細描述：**

每組輸入給 `N`，題目把 `1、2、…、N` 依序串接成一個可能非常大的十進位數，要求判斷它能否被 3 整除。利用十進位數各位和的整除規則，串接數的數字和等價於 `1` 到 `N` 的數字和，因此依 `N mod 3` 即可輸出答案，無需建立大數。

<a id="uva-13185_dpa-numbers-pr"></a>

### UVa 13185 — DPA Numbers／真因數和性質分類 (虧數、完全數、盈數)

- 原始碼：[13185_dpa-numbers-pr.c](13185_dpa-numbers-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, number-theory

**English description:** Classify number as deficient (sum of proper divisors < n), perfect (== n), or abundant (> n).

**中文詳細描述：** 計算正整數的所有真因數之和，分類判定其為虧數 (deficient)、完全數 (perfect) 還是盈數 (abundant)。

**English approach:** Compute aliquot sum = sum of proper divisors up to n/2. Compare with n.

**中文解題思路：** 迴圈枚舉 1 到 n/2 求所有真因數之和：小於 n 輸出 deficient，等於 n 輸出 perfect，大於 n 輸出 abundant。 ==========================================================================


<a id="uva-13185_dpd-numbers"></a>
### UVa 13185 — DPD Numbers／不足數、完全數與過剩數

- 原始碼：[13185_dpd-numbers.c](13185_dpd-numbers.c)
- 演算法：因數枚舉（Number Theory）

**English description:**

For each positive integer `N`, sum all proper divisors smaller than `N`. Output `deficient`, `perfect`, or `abundant` according to whether that sum is less than, equal to, or greater than `N`.

**中文詳細描述：**

每組輸入一個正整數 `N`，找出所有小於 `N` 且能整除 `N` 的真因數並加總。若總和小於 `N`，輸出 `deficient`；等於 `N` 輸出 `perfect`；大於 `N` 則輸出 `abundant`。

<a id="uva-13190_rockabye-taby"></a>

### UVa 13190 — Rockabye Taby／定時服藥排程模擬 (優先佇列)

- 原始碼：[13190_rockabye-taby.c](13190_rockabye-taby.c)
- 難度：UVa Star 2
- 演算法：data-structures, priority-queue, simulation

**English description:** Simulate medication schedule with periodic reminders. Print next k medication events in chronological order.

**中文詳細描述：** 模擬多種具有各自週期的藥物服用提醒，依時間順序輸出接下來 k 次服藥提醒的時刻與藥物名稱 (遇同時取優先度高者)。

**English approach:** Min-heap priority queue keyed on (time ASC, priority ASC). Pop earliest medicine, push next occurrence time + period.

**中文解題思路：** 以最小堆積維護三元組 (下次提醒時間, 原始優先順序, 藥品週期)。每次彈出最早者，將時間加上週期後重新壓入堆積。 ==========================================================================
