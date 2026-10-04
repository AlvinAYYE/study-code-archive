# 0867. Transpose Matrix《轉置矩陣》

- **Difficulty**: Easy
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/transpose-matrix/
- **程式碼**: [`867_transpose-matrix.c`](./867_transpose-matrix.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二維整數矩陣，回傳其轉置矩陣。轉置會沿主對角線翻轉，將原本的列索引與行索引互換。

**思路**：程式配置列數與行數互換的新矩陣。以雙層迴圈將原矩陣的 A[j][i] 複製到結果的 ret[i][j]。

## Problem Statement (English)

Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    
}
```
