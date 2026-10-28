# 0063. Unique Paths II｜不同路徑 II

- **難度**：中等
- **標籤**：陣列、動態規劃、矩陣
- **題目連結**：[LeetCode 0063](https://leetcode.com/problems/unique-paths-ii/)
- **C 程式**：[063_unique-paths-ii.c](./063_unique-paths-ii.c)

## 題目說明

給定 `m × n` 網格 `obstacleGrid`，`0` 表示空格，`1` 表示障礙物。機器人從左上角出發，每次只能往右或往下，且不能走進障礙格。回傳到達右下角的不同路徑數。

## 範例

```text
輸入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
輸出：2
說明：中間格是障礙物，只剩上方繞行或左側繞行兩條路。

輸入：obstacleGrid = [[0,1],[0,0]]
輸出：1
```

## 限制

- `m == obstacleGrid.length`，`n == obstacleGrid[i].length`。
- `1 <= m, n <= 100`。
- `obstacleGrid[i][j]` 只會是 `0` 或 `1`。
- 答案不超過 `2 × 10^9`。

## 解題步驟

1. `ways[column]` 保存目前列各欄可到達的方法數；起點沒有障礙時，先設 `ways[0] = 1`。
2. 逐列掃描。遇到障礙物時將該欄 `ways[column]` 清為 0，因為不能穿越。
3. 遇到空格且不是最左欄時，把從左邊走來的方法數加進來；原本的 `ways[column]` 已是從上方走來的數量。
4. 掃描結束後，最後一欄保存的就是到達終點的方法數。

## 複雜度

- 時間：`O(m × n)`。
- 額外空間：`O(n)`。

## LeetCode C 函式簽名

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                              int* obstacleGridColSize);
```
