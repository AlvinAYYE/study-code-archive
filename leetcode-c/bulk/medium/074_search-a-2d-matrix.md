# 0074. Search a 2D Matrix｜搜尋二維矩陣

- **難度**：中等
- **標籤**：陣列、二分搜尋、矩陣
- **題目連結**：[LeetCode 0074](https://leetcode.com/problems/search-a-2d-matrix/)
- **C 程式**：[074_search-a-2d-matrix.c](./074_search-a-2d-matrix.c)

## 題目說明

給定一個矩陣和目標值 `target`。每列由左到右遞增，而且每列第一個數都大於上一列最後一個數；因此把矩陣逐列接起來會形成一個遞增陣列。請在 `O(log(m × n))` 時間內判斷 `target` 是否存在。

## 範例

```text
輸入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
輸出：true

輸入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
輸出：false
```

## 限制

- `matrix` 有 `m` 列、`n` 欄，且每列欄數相同。
- `1 <= m, n <= 100`。
- `-10^4 <= matrix[i][j], target <= 10^4`。
- 每列遞增，且下一列首值大於上一列末值。

## 解題步驟

1. 把矩陣想成長度 `m × n` 的一維遞增陣列，二分搜尋的左右界設為 `0` 和 `m × n - 1`。
2. 取中間一維索引 `mid`。它所在的列是 `mid / n`，所在的欄是 `mid % n`。
3. 比較該格與 `target`：較小就搜尋右半部，較大就搜尋左半部，相等就回傳 `true`。
4. 搜尋範圍縮空仍未找到時回傳 `false`。

## 複雜度

- 時間：`O(log(m × n))`。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);
```
