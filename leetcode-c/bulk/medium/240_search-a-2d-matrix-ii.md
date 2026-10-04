# 0240. Search a 2D Matrix II《搜尋二維矩陣 II》

- **Difficulty**: Medium
- **Tags**: array, binary-search, divide-and-conquer, matrix
- **題目連結**: https://leetcode.com/problems/search-a-2d-matrix-ii/
- **程式碼**: [`240_search-a-2d-matrix-ii.c`](./240_search-a-2d-matrix-ii.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 m×n 整數矩陣中搜尋 target；每一列由左至右遞增，每一欄由上至下遞增。存在 target 時回傳 true，否則回傳 false。

**思路**：從左下角開始比較目標值；目前值過大就往上移，過小就往右移。每一步都能排除一整列或一整欄。

## Problem Statement (English)

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109

## 官方 C 函式簽名 Signature

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){

}
```
