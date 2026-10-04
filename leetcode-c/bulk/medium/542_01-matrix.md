# 0542. 01 Matrix《01 矩陣》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, breadth-first-search, matrix
- **題目連結**: https://leetcode.com/problems/01-matrix/
- **程式碼**: [`542_01-matrix.c`](./542_01-matrix.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 的 0/1 矩陣，回傳每個儲存格到最近 0 的距離。共邊的上下左右儲存格距離為 1，且矩陣至少包含一個 0。

**思路**：將所有值為 0 的位置同時放入佇列，做多源廣度優先搜尋；每一層首次走到的未標記格子即取得最近 0 的距離。

## Problem Statement (English)

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

## 範例 Examples

```text
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

## 限制 Constraints

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    
}
```
