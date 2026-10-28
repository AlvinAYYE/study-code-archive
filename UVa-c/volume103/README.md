# UVa Volume 103

本卷共收錄 8 題 C 題目檔，以下依題號排序。

<a id="uva-10300_ecological-premium"></a>
### UVa 10300 — Ecological Premium／生態獎金

- 原始碼：[10300_ecological-premium.c](10300_ecological-premium.c)
- 演算法：數學化簡、加總（Math）

**English description:**

For each test case, the input lists several farmers by farm size, number of animals, and an environmental rating. Compute each farmer's premium as the farm size multiplied by the rating, sum these premiums, and output the total.

**中文詳細描述：**

每組輸入會給出多位農民，以及各自的農地面積、動物數量與環保等級。題目要求把每位農民的面積乘上環保等級，再將所有補助金相加，輸出該組資料的補助總額；動物數在原公式中會互相消去。

<a id="uva-10305_ordering-tasks"></a>
### UVa 10305 — Ordering Tasks／工作排序

- 原始碼：[10305_ordering-tasks.c](10305_ordering-tasks.c)
- 演算法：圖論、拓撲排序（Graph, Topological Sort）

**English description:**

The input gives a set of tasks and directed precedence relations, where one task must be completed before another. Produce and output any ordering that satisfies every relation.

**中文詳細描述：**

輸入包含若干工作與有向的先後限制，每條限制表示某項工作必須在另一項工作之前完成。需要對這張有向圖做拓撲排序，輸出任一個符合全部限制的工作執行順序。

<a id="uva-10306_e-coins"></a>
### UVa 10306 — e-Coins／電子硬幣

- 原始碼：[10306_e-coins.c](10306_e-coins.c)
- 演算法：二維動態規劃、完全背包（Dynamic Programming, Unbounded Knapsack）

**English description:**

Each coin contributes a pair of integer values. From the available coin types, choose coins with repetition so that the sums of the two coordinates satisfy x² + y² = S². Output the minimum number of coins, or report that no such combination exists.

**中文詳細描述：**

輸入給出多種電子硬幣，每種硬幣具有一對整數值，且每種可以重複使用。要讓所選硬幣在兩個座標上的總和 `(x, y)` 滿足 `x² + y² = S²`，輸出需要的最少硬幣數；若無法達成則輸出題目指定的無解訊息。

<a id="uva-10327_flip-sort"></a>
### UVa 10327 — Flip Sort／翻轉排序

- 原始碼：[10327_flip-sort.c](10327_flip-sort.c)
- 演算法：逆序對計數、排序（Inversion Count）

**English description:**

Given a sequence of numbers, sorting is performed by swapping adjacent out-of-order elements. Determine and output the minimum number of such swaps needed to put the sequence in increasing order.

**中文詳細描述：**

輸入是一串數字，只允許交換相鄰且順序錯誤的元素來完成遞增排序。相鄰交換的最少次數等於序列中的逆序對數量，因此逐一計數所有前大後小的數對，並輸出交換次數。

<a id="uva-10340_all-in-all"></a>
### UVa 10340 — All in All／全都包含

- 原始碼：[10340_all-in-all.c](10340_all-in-all.c)
- 演算法：字串、雙指標、貪心（String, Two Pointers）

**English description:**

For every input pair of strings `s` and `t`, decide whether `s` is a subsequence of `t`: its characters must appear in order but need not be consecutive. Output the required affirmative or negative answer.

**中文詳細描述：**

每筆輸入包含字串 `s` 與 `t`，要判斷 `s` 是否為 `t` 的子序列，也就是 `s` 的每個字元能否依原順序在 `t` 中找到，但不必相鄰。以雙指標由左至右配對，最後輸出成功或失敗的結果。

<a id="uva-10346_peters-smokes"></a>
### UVa 10346 — Peter's Smokes／彼得的香菸

- 原始碼：[10346_peters-smokes.c](10346_peters-smokes.c)
- 演算法：模擬、數學（Simulation, Math）

**English description:**

Peter starts with `n` cigarettes and can exchange every `k` cigarette butts for one new cigarette. Repeatedly use all possible exchanges and output the total number of cigarettes he can smoke.

**中文詳細描述：**

輸入給出彼得一開始擁有的 `n` 根香菸，以及每 `k` 個菸蒂可換一根新香菸的規則。每抽完一根就多一個菸蒂，持續交換到不足 `k` 個為止，輸出總共能抽的香菸數。

<a id="uva-10360_rat-attack"></a>
### UVa 10360 — Rat Attack／老鼠攻擊

- 原始碼：[10360_rat-attack.c](10360_rat-attack.c)
- 演算法：二維陣列、範圍累加（2D Array, Range Accumulation）

**English description:**

The input gives rat populations at grid coordinates and a bomb radius `d`. A bomb centered at `(x, y)` kills rats in the square from `x-d` to `x+d` and `y-d` to `y+d`; output the best center and the maximum population eliminated.

**中文詳細描述：**

輸入列出網格上各座標的老鼠數量，以及炸彈影響半徑 `d`。炸彈放在 `(x, y)` 時會消滅橫、縱座標各相差不超過 `d` 的正方形範圍內所有老鼠；需要找出可消滅最多老鼠的中心座標，並輸出座標與最大數量。

<a id="uva-10370_above-average"></a>
### UVa 10370 — Above Average／高於平均

- 原始碼：[10370_above-average.c](10370_above-average.c)
- 演算法：陣列統計、平均值（Array, Arithmetic）

**English description:**

For each class, the input supplies all students' grades. Compute the class average, count the grades strictly above it, and output that count as a percentage of the class with the required formatting.

**中文詳細描述：**

每組輸入包含一個班級的學生人數與所有成績。先算出全班平均分數，再統計成績嚴格高於平均的人數，最後依題目要求的格式輸出其占全班的百分比。
