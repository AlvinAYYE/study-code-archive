# UVa Volume 120

本卷收錄 7 份 C 解答，涵蓋 7 個 UVa 題號，以下依題號排序。

<a id="uva-12004_bubble_sort"></a>

### UVa 12004 — Bubble Sort／氣泡排序期望交換次數

- 原始碼：[12004_bubble_sort.c](12004_bubble_sort.c)
- 難度：Easy
- 演算法：math, probability, combinatorics

**English description:** Find the expected number of swap operations in bubble sort on a random permutation of length n.

**中文詳細描述：** 求長度為 n 的隨機排列在氣泡排序下的期望交換次數（以最簡分數表示）。

**English approach:** Expected swaps = n * (n - 1) / 4. Simplify fraction: if divisible by 4 output integer, if divisible by 2 output P/2, else P/4.

**中文解題思路：** 隨機排列逆序對期望值為 n*(n-1)/4。化簡為最簡分數：能被 4 整除則為整數，能被 2 整除則為 P/2，否則為 P/4。 ==========================================================================


<a id="uva-12015_google-is-feeling-lucky"></a>
### UVa 12015 — Google is Feeling Lucky／Google 好手氣

- 原始碼：[12015_google-is-feeling-lucky.c](12015_google-is-feeling-lucky.c)
- 演算法：最大值搜尋、篩選（Simulation, String）

**English description:**

Each test case contains ten website URLs with relevance scores. Find the maximum score and output every URL whose score equals that maximum, preserving the input order and printing the required case heading.

**中文詳細描述：**

每組輸入固定包含十個網站網址及各自的關聯分數。先找出最高分，再按照原輸入順序輸出所有分數等於最高值的網址，前方並輸出題目要求的案例標題。

<a id="uva-12019_dooms-day-algorithm"></a>

### UVa 12019 — Doom's Day Algorithm／末日審判演算法 (2011年星期幾計算)

- 原始碼：[12019_dooms-day-algorithm.c](12019_dooms-day-algorithm.c)
- 難度：UVa Star 1
- 演算法：math, date

**English description:** Determine the day of week for any date in year 2011 (knowing 2011/1/1 was Saturday).

**中文詳細描述：** 計算 2011 年中任意日期 (月/日) 是星期幾 (已知 2011 年 1 月 1 日為星期六)。

**English approach:** Sum days in preceding months plus day of month. Day of week = (start_offset + total_days - 1) % 7.

**中文解題思路：** 累計各月份天數計算自 1 月 1 日起的天數偏移量，對 7 取模對應星期陣列輸出。 ==========================================================================


<a id="uva-12032_the-monkey-and-the-oiled-bamboo"></a>

### UVa 12032 — The Monkey and the Oiled Bamboo／油竹竿猴子跳躍初始彈力二分搜尋

- 原始碼：[12032_the-monkey-and-the-oiled-bamboo.c](12032_the-monkey-and-the-oiled-bamboo.c)
- 難度：UVa Star 2
- 演算法：binary-search, greedy

**English description:** Find minimum initial jump strength k such that a monkey can climb all bamboo rungs: jumping distance == k consumes 1 strength; jumping > k is impossible.

**中文詳細描述：** 猴子攀爬塗油竹竿梯子：跳躍距離恰好等於當前彈力 k 時彈力減 1，跳躍距離小於 k 時彈力不變，大於 k 則跳不上去，求最小初始 k 值。

**English approach:** Binary search on k in [1, max_height]. Simulate climb greedily to verify feasibility.

**中文解題思路：** 在 [1, 最高高度] 區間對初始彈力 k 進行二分搜尋，每次模擬自地面向上攀爬梯階檢驗可行性。 ==========================================================================


<a id="uva-12049_just-prune-the-list"></a>

### UVa 12049 — Just Prune The List／修剪串列至完全相同

- 原始碼：[12049_just-prune-the-list.c](12049_just-prune-the-list.c)
- 難度：Easy
- 演算法：sorting, two-pointers

**English description:** Find the minimum number of elements to remove from two integer lists so that both lists become identical multisets.

**中文詳細描述：** 求最少需要從兩個整數串列中移除多少個元素，才能使兩個串列變成完全相同的多重集合。

**English approach:** Sort both lists. Use two pointers to count common elements. Total removed = (n + m) - 2 * common.

**中文解題思路：** 將兩數列排序後用雙指針統計公共元素數量，最少移除總數即為兩數列總長度減去 2 倍公共元素數。 ==========================================================================


<a id="uva-12086_potentiometers"></a>

### UVa 12086 — Potentiometers／電位器單點更新區間和樹狀陣列

- 原始碼：[12086_potentiometers.c](12086_potentiometers.c)
- 難度：UVa Star 2
- 演算法：data-structures, bit, fenwick-tree

**English description:** Maintain a sequence of potentiometer resistance values supporting point update 'S x r' and range sum query 'M x y'.

**中文詳細描述：** 維護一列電位器阻值序列，高效支援單點阻值修改與區間電阻總和查詢 (Fenwick Tree / 樹狀陣列)。

**English approach:** Binary Indexed Tree (Fenwick Tree): O(log N) point update and O(log N) prefix sum query.

**中文解題思路：** 樹狀陣列 (BIT)：利用 lowbit 進行 O(log N) 區間查詢 query(y) - query(x-1) 與單點更新 update(x, delta)。 ==========================================================================


<a id="uva-12096_the-setstack-computer"></a>

### UVa 12096 — The SetStack Computer／集合堆疊計算機

- 原始碼：[12096_the-setstack-computer.c](12096_the-setstack-computer.c)
- 難度：Hard
- 演算法：stack, data-structures, hash

**English description:** Simulate a stack machine operating on sets: PUSH (empty set), DUP, UNION, INTERSECT, ADD (insert set into set). Print set cardinality after each operation.

**中文詳細描述：** 模擬基於集合的堆疊計算機（PUSH 空集、DUP、UNION 聯集、INTERSECT 交集、ADD 作為子元素加入），每次操作後輸出棧頂集合的大小。

**English approach:** Assign a unique integer ID to every distinct set using map/hash. Stack stores integer set IDs. Implement set union/intersection via set IDs.

**中文解題思路：** 為每個相異的集合分配唯一整數 ID，堆疊中僅存儲集合 ID，以 ID 表達集合嵌套結構，每次操作輸出頂層集合元素個數。 ==========================================================================
