# 0073. Set Matrix Zeroes《矩陣置零》

- **Difficulty**: Medium
- **Tags**: array, hash-table, matrix
- **題目連結**: https://leetcode.com/problems/set-matrix-zeroes/
- **程式碼**: [`073_set-matrix-zeroes.c`](./073_set-matrix-zeroes.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 整數矩陣，只要某個元素為 0，就必須將它所在的整列與整欄都設為 0。必須直接在原矩陣中完成修改。矩陣的列數與欄數皆介於 1 到 200。

**思路**：先用第一列與第一欄記錄其餘各列、各欄是否應歸零，並另外保存第一列與第一欄原本是否含零。再依標記填零，最後處理第一列和第一欄。

## Problem Statement (English)

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## 限制 Constraints

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
}
```
