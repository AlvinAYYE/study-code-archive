# 0064. Minimum Path Sum｜最小路徑和

- **難度**：中等
- **標籤**：陣列、動態規劃、矩陣
- **題目連結**：[LeetCode 0064](https://leetcode.com/problems/minimum-path-sum/)
- **C 程式**：[064_minimum-path-sum.c](./064_minimum-path-sum.c)

## 題目說明

給定填有非負整數的 `m × n` 網格，從左上角走到右下角。每一步只能往右或往下，請回傳路徑上所有格子數值總和的最小值。

## 範例

```text
輸入：grid = [[1,3,1],[1,5,1],[4,2,1]]
輸出：7
說明：路徑 1 → 3 → 1 → 1 → 1 的總和是 7，且最小。

輸入：grid = [[1,2,3],[4,5,6]]
輸出：12
```

## 限制

- `m == grid.length`，`n == grid[i].length`。
- `1 <= m, n <= 200`。
- `0 <= grid[i][j] <= 200`。

## 解題步驟

1. `minSum[column]` 保存走到目前列該欄的最小累積和。
2. 起點直接設為 `grid[0][0]`。第一列只能從左邊進入，第一欄只能從上方進入。
3. 其他格子可由上方或左方抵達，選較小的累積和，再加上目前格子的值：`minSum[column] = min(上方, 左方) + grid[row][column]`。
4. 最後一欄的累積和就是最小路徑和。

## 複雜度

- 時間：`O(m × n)`。
- 額外空間：`O(n)`，只保存一列累積和。

## LeetCode C 函式簽名

```c
int minPathSum(int** grid, int gridSize, int* gridColSize);
```
