# UVa Volume 012 題目索引

本卷收錄 7 份 C 解答，涵蓋 7 個 UVa 題號，以下依題號排序。

<a id="uva-1203_argus"></a>

### UVa 1203 — Argus／阿格斯週期查詢優先佇列排程

- 原始碼：[1203_argus.c](1203_argus.c)
- 難度：UVa Star 2
- 演算法：data-structures, priority-queue

**English description:** Simulate periodic query registrations: repeatedly return next query ID scheduled to execute by time (tie-broken by query ID).

**中文詳細描述：** 模擬多個週期性查詢註冊：依據下次觸發時間 (時間相同時按查詢 ID 升序) 循序提取前 K 個被執行的查詢 ID。

**English approach:** Simulate via priority queue or sorted state array storing (cur_time, period, q_num). Advance time by period after each pop.

**中文解題思路：** 以優先佇列或狀態陣列維護各註冊項之 (當前時間, 週期, 查詢編號)，每次選出時間最小者加入輸出序列並更新其下次觸發時間。 ==========================================================================


<a id="uva-1210_sum-of-consecutive-prime-numbers"></a>

### UVa 1210 — Sum of Consecutive Prime Numbers／連續質數之和

- 原始碼：[1210_sum-of-consecutive-prime-numbers.c](1210_sum-of-consecutive-prime-numbers.c)
- 難度：Easy
- 演算法：math, number-theory, sliding-window

**English description:** Count how many representations of integer N exist as the sum of one or more consecutive prime numbers.

**中文詳細描述：** 計算整數 N 可表示為連續一個或多個質數之和的方案數。

**English approach:** Precompute primes up to 10000. Use sliding window or prefix sums to count ranges of primes whose sum equals N.

**中文解題思路：** 預先篩出 10000 內質數，使用滑動窗口或雙指針遍歷連續質數區間，統計和為 N 的區間數量。 ==========================================================================


<a id="uva-1213_sum-of-different-primes"></a>

### UVa 1213 — Sum of Different Primes／不同質數之和 (0/1背包計數DP)

- 原始碼：[1213_sum-of-different-primes.c](1213_sum-of-different-primes.c)
- 難度：Medium
- 演算法：dp, knapsack, prime

**English description:** Count the number of ways to express integer n as the sum of k distinct prime numbers.

**中文詳細描述：** 求將正整數 n 表示為 k 個互不相同的質數之和的組合方案數。

**English approach:** 0/1 Knapsack DP where items are primes: dp[j][s] = number of ways to choose j primes summing to s. dp[j][s] += dp[j-1][s - prime].

**中文解題思路：** 以質數為物品的二維 0/1 背包計數 DP：dp[j][s] 表示選取 j 個質數和為 s 的方案數，倒序更新。 ==========================================================================


<a id="uva-1225_digit-counting"></a>

### UVa 1225 — Digit Counting／數字符號出現頻率計數

- 原始碼：[1225_digit-counting.c](1225_digit-counting.c)
- 難度：UVa Star 1
- 演算法：math, simulation

**English description:** Count the number of occurrences of each digit 0 to 9 in the sequence of integers from 1 up to N concatenated together.

**中文詳細描述：** 統計將 1 到 N 的所有整數依序寫下後，數字 0 到 9 各自出現的總次數。

**English approach:** Iterate from 1 to N. Extract each digit via modulo 10 and division by 10, incrementing counts in an array of size 10.

**中文解題思路：** 從 1 走訪至 N，透過除以 10 與取餘數拆解每個整數的各數位，並累加至長度 10 的計數陣列。 ==========================================================================


<a id="uva-1230_modex"></a>

### UVa 1230 — MODEX／大數快速冪模運算

- 原始碼：[1230_modex.c](1230_modex.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Compute (x^y) mod n efficiently for large integers.

**中文詳細描述：** 高效計算大整數的次方取模運算 (x^y) mod n。

**English approach:** Binary exponentiation (repeated squaring) in O(log y) time.

**中文解題思路：** 使用平方求冪二分快速冪演算法，時間複雜度為 O(log y)。 ==========================================================================


<a id="uva-1237_expert-enough"></a>

### UVa 1237 — Expert Enough?／汽車價格區間資料庫單一製造商查詢

- 原始碼：[1237_expert-enough.c](1237_expert-enough.c)
- 難度：UVa Star 1
- 演算法：brute-force

**English description:** Given price ranges [L_i, H_i] for car makers, determine if a query price P falls in the range of exactly one maker.

**中文詳細描述：** 給定多家汽車製造商的價格區間 [L_i, H_i]，對於查詢價格 P，若恰好只有一家製造商符合則輸出廠牌名稱，否則輸出 UNDETERMINED。

**English approach:** Iterate database: count makers with L_i <= P <= H_i. If count == 1 return maker index, else return -1.

**中文解題思路：** 循序掃描資料庫中所有區間，統計滿足 L_i <= P <= H_i 的廠商數，若恰好為 1 則回傳該廠商，否則標記無解。 ==========================================================================


<a id="uva-1260_sales"></a>

### UVa 1260 — Sales／每日銷售額歷史小於等於計數總和

- 原始碼：[1260_sales.c](1260_sales.c)
- 難度：UVa Star 1
- 演算法：basics, simulation

**English description:** Given daily sales array A of n days, for each day i from 2 to n, count how many earlier days j < i had sales A[j] <= A[i]. Sum all counts.

**中文詳細描述：** 給定 n 天的每日銷售額陣列 A，對於第 2 到 n 天中的每一天 i，統計先前有多少天 j < i 的銷售額 A[j] <= A[i]，求所有計數的總和。

**English approach:** Double loop: for i from 1 to n-1, count elements in A[0..i-1] that are <= A[i]. Sum and return total.

**中文解題思路：** 雙重迴圈走訪：外層走訪第 i 天，內層統計前 i-1 天中小於等於當日銷售額的天數並予以累加。 ==========================================================================
