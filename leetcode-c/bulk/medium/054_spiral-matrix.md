# 0054. Spiral Matrix《螺旋矩陣》

- **Difficulty**: Medium
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/spiral-matrix/
- **程式碼**: [`054_spiral-matrix.c`](./054_spiral-matrix.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 矩陣，依順時針螺旋順序回傳所有元素。每個元素都要恰好輸出一次。

**思路**：維護上、下、左、右四個邊界與目前方向，依序走訪上列、右行、下列、左行。每走完一側就收縮對應邊界，直到沒有可走的區域。

## Problem Statement (English)

Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
}
```
