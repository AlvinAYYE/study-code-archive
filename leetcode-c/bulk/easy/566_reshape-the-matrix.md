# 0566. Reshape the Matrix《重塑矩陣》

- **Difficulty**: Easy
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/reshape-the-matrix/
- **程式碼**: [`566_reshape-the-matrix.c`](./566_reshape-the-matrix.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 矩陣 mat 與目標列數 r、欄數 c，若可行，依原本逐列走訪順序重塑成 r × c 矩陣。若元素總數不相等而無法重塑，則回傳原矩陣。

**思路**：先比較原矩陣與目標矩陣的元素總數；可行時以兩個原矩陣索引依列序逐格填入新配置的 r × c 結果。

## Problem Statement (English)

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
```

## 限制 Constraints

m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    
}
```
