# 0832. Flipping an Image《翻轉影像》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, bit-manipulation, matrix, simulation
- **題目連結**: https://leetcode.com/problems/flipping-an-image/
- **程式碼**: [`832_flipping-an-image.c`](./832_flipping-an-image.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n × n 二元矩陣 image，先將每一列水平翻轉，再把所有 0 與 1 互換。回傳處理後矩陣；n 介於 1 與 20。

**思路**：對每列以頭尾雙指針交換，同時將兩端位元以 XOR 1 反轉；若列長為奇數，最後再反轉中央元素。

## Problem Statement (English)

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
```

## 限制 Constraints

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    
}
```
