# 0931. Minimum Falling Path Sum《最小下降路徑和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, matrix
- **題目連結**: https://leetcode.com/problems/minimum-falling-path-sum/
- **程式碼**: [`931_minimum-falling-path-sum.c`](./931_minimum-falling-path-sum.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 整數矩陣 matrix，下降路徑可從第一列任一元素開始，往下一列時只能走正下方、左下方或右下方。請回傳所有下降路徑中的最小元素總和。

**思路**：直接在矩陣中做列方向 DP，將每格加上前一列正上、左上、右上可用位置的最小值，最後取最末列最小值。

## Problem Statement (English)

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

## 限制 Constraints

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

## 官方 C 函式簽名 Signature

```c
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    
}
```
