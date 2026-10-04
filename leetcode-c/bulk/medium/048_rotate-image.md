# 0048. Rotate Image《旋轉影像》

- **Difficulty**: Medium
- **Tags**: array, math, matrix
- **題目連結**: https://leetcode.com/problems/rotate-image/
- **程式碼**: [`048_rotate-image.c`](./048_rotate-image.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 的二維矩陣，請將影像順時針旋轉 90 度。必須直接修改原矩陣，不能另配置第二個二維矩陣。

**思路**：程式以遞迴逐層處理矩陣，將每層同一圈的上、右、下、左四個位置輪換。完成外圈後往內縮一圈繼續旋轉。

## Problem Statement (English)

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

## 限制 Constraints

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

## 官方 C 函式簽名 Signature

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    
}
```
