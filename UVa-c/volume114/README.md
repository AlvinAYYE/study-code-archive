# UVa Volume 114

本卷共收錄 5 題 C 題目檔，以下依題號排序。

<a id="uva-11417_gcd"></a>
### UVa 11417 — GCD／最大公因數總和

- 原始碼：[11417_gcd.c](11417_gcd.c)
- 演算法：歐幾里得算法、成對枚舉（GCD, Number Theory）

**English description:**

For each input `N` until zero, compute the sum of `gcd(i, j)` over every pair satisfying `1 ≤ i < j ≤ N`. Output the resulting total.

**中文詳細描述：**

逐筆讀入 `N` 直到 0，枚舉所有滿足 `1 ≤ i < j ≤ N` 的整數對，利用歐幾里得算法求每對的最大公因數並累加，最後輸出總和 `G`。

<a id="uva-11461_square-numbers"></a>
### UVa 11461 — Square Numbers／平方數

- 原始碼：[11461_square-numbers.c](11461_square-numbers.c)
- 演算法：平方根、區間計數（Math）

**English description:**

For each inclusive range `[a, b]` until the terminating pair, count how many integers in the range are perfect squares and output the count.

**中文詳細描述：**

每筆輸入給閉區間 `[a, b]`，直到終止資料。要統計區間內有多少完全平方數；由最小可行平方根 `ceil(sqrt(a))` 與最大平方根 `floor(sqrt(b))` 的差即可得到數量，並輸出結果。

<a id="uva-11462_age-sort"></a>
### UVa 11462 — Age Sort／年齡排序

- 原始碼：[11462_age-sort.c](11462_age-sort.c)
- 演算法：計數排序（Counting Sort）

**English description:**

Each data set contains many people's ages from a small fixed range. Sort all ages in nondecreasing order and output them on one line; a frequency array avoids comparison sorting for the large input.

**中文詳細描述：**

每組輸入包含大量年齡，而年齡只會落在很小的固定範圍。使用頻率陣列統計每個年齡出現次數，再由小到大依次輸出相應次數，即可在線性時間完成非遞減排序。

<a id="uva-11470_square-sums"></a>
### UVa 11470 — Square Sums／方框總和

- 原始碼：[11470_square-sums.c](11470_square-sums.c)
- 演算法：矩陣分層、模擬（2D Array, Simulation）

**English description:**

Given an `N × N` integer matrix, sum the values on each concentric square border, from the outside toward the center. Output all layer sums in order for every case.

**中文詳細描述：**

每組輸入是一個 `N × N` 整數矩陣，要從最外圈開始，分別計算每一層同心方框邊界上的元素總和。逐層縮小上下左右邊界，避免角落重複計算，最後依外到內的順序輸出各層總和。

<a id="uva-11498_division-of-nlogonia"></a>
### UVa 11498 — Division of Nlogonia／諾格洛尼亞分界

- 原始碼：[11498_division-of-nlogonia.c](11498_division-of-nlogonia.c)
- 演算法：座標比較（Geometry, Simulation）

**English description:**

The input gives a division point followed by query coordinates. For each query, output whether it lies northeast, northwest, southeast, southwest, or on either dividing line.

**中文詳細描述：**

每組資料先給垂直與水平分界線交點，再給多個待判斷座標。比較查詢點與分界點的橫、縱座標，輸出 `NE`、`NO`、`SE` 或 `SO`；若任一座標相同、落在分界線上，則輸出 `divisa`。
