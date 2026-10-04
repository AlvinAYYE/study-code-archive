# 0059. Spiral Matrix II《螺旋矩陣 II》

- **Difficulty**: Medium
- **Tags**: array, matrix, simulation
- **題目連結**: https://leetcode.com/problems/spiral-matrix-ii/
- **程式碼**: [`059_spiral-matrix-ii.c`](./059_spiral-matrix-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，建立一個 n × n 矩陣。將 1 到 n² 依順時針螺旋順序填入並回傳該矩陣。

**思路**：依右、下、左、上的方向逐格填入遞增數字，並在碰到各層邊界時轉向與收縮邊界。直到填完 n² 個位置為止。

## Problem Statement (English)

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Input: n = 1
Output: [[1]]
```

## 限制 Constraints

1 <= n <= 20

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    
}
```
