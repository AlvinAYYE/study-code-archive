# 0733. Flood Fill《圖像渲染》

- **Difficulty**: Easy
- **Tags**: array, depth-first-search, breadth-first-search, matrix
- **題目連結**: https://leetcode.com/problems/flood-fill/
- **程式碼**: [`733_flood-fill.c`](./733_flood-fill.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數矩陣 image、起點 (sr, sc) 與新顏色 color，從起點開始對同色且四向連通的像素進行填色。回傳填色後的影像，未與起點四向連通的同色像素不改變。

**思路**：先複製原影像作為回傳陣列，再 DFS 走訪與起點原色相同的四向連通格。遞迴期間暫以特殊值標記原陣列避免重訪，並同步將複本改為新色。

## Problem Statement (English)

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill:
Return the modified image after performing the flood fill.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:

From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
```

## 限制 Constraints

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
}
```
