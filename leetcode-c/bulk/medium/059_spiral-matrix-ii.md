# 0059. Spiral Matrix II｜螺旋矩陣 II

- **難度**：中等
- **標籤**：陣列、矩陣、模擬
- **題目連結**：[LeetCode 0059](https://leetcode.com/problems/spiral-matrix-ii/)
- **C 程式**：[059_spiral-matrix-ii.c](./059_spiral-matrix-ii.c)

## 題目說明

給定正整數 `n`，建立一個 `n × n` 矩陣，將 `1` 到 `n²` 依順時針螺旋順序填入並回傳。

## 範例

```text
輸入：n = 3
輸出：[[1,2,3],[8,9,4],[7,6,5]]

輸入：n = 1
輸出：[[1]]
```

## 限制

- `1 <= n <= 20`。

## 解題步驟

1. 用 `top`、`bottom`、`left`、`right` 設定目前尚未填入的矩形邊界。
2. 依序沿上邊向右、右邊向下、下邊向左、左邊向上填入遞增數字。
3. 每完成一邊就把該邊界向內縮一格；下邊與左邊開始前先確認範圍仍有效。
4. 重複直到所有邊界交錯，矩陣就填滿了。

## 複雜度

- 時間：`O(n²)`，每格填入一次。
- 額外空間：`O(n²)`，用於回傳矩陣。

## LeetCode C 函式簽名

```c
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);
```

`returnSize` 是矩陣列數，`returnColumnSizes` 記錄每列長度。
