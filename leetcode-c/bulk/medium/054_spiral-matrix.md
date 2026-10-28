# 0054. Spiral Matrix｜螺旋矩陣

- **難度**：中等
- **標籤**：陣列、矩陣、模擬
- **題目連結**：[LeetCode 0054](https://leetcode.com/problems/spiral-matrix/)
- **C 程式**：[054_spiral-matrix.c](./054_spiral-matrix.c)

## 題目說明

給定 `m × n` 矩陣，依照順時針螺旋順序讀出所有元素並回傳。每個元素都要恰好出現一次。

## 範例

```text
輸入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
輸出：[1,2,3,6,9,8,7,4,5]

輸入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
輸出：[1,2,3,4,8,12,11,10,9,5,6,7]
```

## 限制

- `m == matrix.length`，`n == matrix[i].length`。
- `1 <= m, n <= 10`。
- `-100 <= matrix[i][j] <= 100`。

## 解題步驟

1. 用 `top`、`bottom`、`left`、`right` 框住尚未輸出的矩形。
2. 依序讀取上邊（左到右）、右邊（上到下）、下邊（右到左）、左邊（下到上）。
3. 每讀完一邊，就把對應邊界向內縮一格。
4. 讀取下邊或左邊前再次確認上下界、左右界尚未交錯，避免單列或單行被重複讀取。
5. 所有邊界交錯時結束，回傳已填入的元素陣列。

## 複雜度

- 時間：`O(m × n)`，每格讀取一次。
- 額外空間：`O(m × n)`，用於題目要求的回傳陣列。

## LeetCode C 函式簽名

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
```

回傳陣列由函式配置，`returnSize` 是元素數量。
