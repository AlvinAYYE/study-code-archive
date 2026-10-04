# 0074. Search a 2D Matrix《搜尋二維矩陣》

- **Difficulty**: Medium
- **Tags**: array, binary-search, matrix
- **題目連結**: https://leetcode.com/problems/search-a-2d-matrix/
- **程式碼**: [`074_search-a-2d-matrix.c`](./074_search-a-2d-matrix.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個每列由左到右遞增、且下一列首值大於上一列末值的 m × n 整數矩陣，判斷 target 是否存在其中。解法的時間複雜度必須為 O(log(m × n))。

**思路**：把矩陣視為一維有序陣列進行二分搜尋，再以 mid 除以欄數與取餘數換算回列、欄索引。

## Problem Statement (English)

You are given an m x n integer matrix matrix with the following two properties:
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

## 官方 C 函式簽名 Signature

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    
}
```
