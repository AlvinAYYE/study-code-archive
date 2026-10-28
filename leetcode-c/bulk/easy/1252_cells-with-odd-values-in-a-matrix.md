# LeetCode 1252. Cells with Odd Values in a Matrix

**難度：Easy**

## 題意完整翻譯

有一個 m 列、n 欄的零矩陣。每個 indices[i] = [ri, ci] 表示一次操作：第 ri 列的每個格子都加 1，且第 ci 欄的每個格子也都加 1。所有操作完成後，請回傳值為奇數的格子總數。

## 範例

1. m = 2, n = 3, indices = [[0,1],[1,1]] → 6
2. m = 2, n = 2, indices = [[1,1],[0,0]] → 0

## 限制

- 1 <= m, n <= 50
- 1 <= indices.length <= 100
- 0 <= ri < m
- 0 <= ci < n

## 解題思路

1. 每一列、每一欄只需記錄目前被加了奇數次還是偶數次；再被操作一次就切換奇偶狀態。
2. 統計奇數次被加的列數 oddRows，以及奇數次被加的欄數 oddCols。
3. 一個格子在列、欄兩邊被加的總次數為奇數時才是奇數值，因此答案是 oddRows × (n - oddCols) + (m - oddRows) × oddCols。

## 複雜度

- 時間：O(indices.length + m + n)
- 空間：O(m + n)

## C 函式簽名

~~~c
int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。
