# 0498. Diagonal Traverse《對角線遍歷》

- **Difficulty**: Medium
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/diagonal-traverse/
- **程式碼**: [`498_diagonal-traverse.c`](./498_diagonal-traverse.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 m × n 矩陣 mat，請依對角線順序取出全部元素。相鄰對角線的走訪方向需交替，並回傳形成的一維陣列。

**思路**：程式依 row + col 的對角線編號逐條走訪，列舉可能座標並略過越界位置。每處理完一條對角線就切換方向，以交換列與欄取得交替順序。

## Problem Statement (English)

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
```

## 限制 Constraints

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
}
```
