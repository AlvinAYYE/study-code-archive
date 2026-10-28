# UVa Volume 106

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-10608_friends"></a>
### UVa 10608 — Friends／朋友

- 原始碼：[10608_friends.c](10608_friends.c)
- 演算法：並查集、連通分量（Disjoint Set Union）

**English description:**

The input describes people and pairs of friends. Friendship connects people transitively, so merge every pair into groups and output the size of the largest connected group.

**中文詳細描述：**

每組輸入先給出總人數與朋友關係數，再列出每一對互為朋友的人。朋友關係具有傳遞性，因此使用並查集合併所有關係、維護各集合大小，最後輸出最大朋友圈的人數。

<a id="uva-10642_can-you-solve-it"></a>
### UVa 10642 — Can You Solve It?／你能解出來嗎？

- 原始碼：[10642_can-you-solve-it.c](10642_can-you-solve-it.c)
- 演算法：座標編號、等差級數（Math, Geometry）

**English description:**

Grid points are visited in a fixed diagonal order. For each pair of coordinates, map both points to their sequence indices and output the number of steps from the first point to the second.

**中文詳細描述：**

平面上的整數座標依斜對角線順序編號，輸入每組的起點 `(x1, y1)` 與終點 `(x2, y2)`。利用 `s=x+y` 的三角數公式求出兩點編號，再輸出從起點走到終點所需的步數差。

<a id="uva-10696_f91"></a>
### UVa 10696 — f91／f91 函數

- 原始碼：[10696_f91.c](10696_f91.c)
- 演算法：分段函數、數學（Recursion, Math）

**English description:**

For each positive input `n` until the terminating zero, evaluate McCarthy's recursively defined `f91` function and print the result in the specified sentence format. The recursion simplifies to 91 for `n ≤ 100`, and `n-10` otherwise.

**中文詳細描述：**

逐筆讀入正整數 `n`，直到輸入 0 結束；題目要求計算以巢狀遞迴定義的 McCarthy `f91` 函數，並按指定句型輸出結果。由函數性質可化簡為 `n ≤ 100` 時答案為 91，否則為 `n-10`。
