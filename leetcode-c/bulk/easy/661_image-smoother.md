# 0661. Image Smoother《圖片平滑器》

- **Difficulty**: Easy
- **Tags**: array, matrix
- **題目連結**: https://leetcode.com/problems/image-smoother/
- **程式碼**: [`661_image-smoother.c`](./661_image-smoother.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定灰階整數矩陣，對每個儲存格套用 3×3 平滑器，取自身與周圍最多八格的平均值並向下取整。位於邊界而不存在的鄰格不可納入平均，回傳平滑後的矩陣。

**思路**：對每個格子從八個方向檢查合法鄰居，連同自身累加總和與數量。以整數除法計算平均值並寫入新的結果矩陣。

## Problem Statement (English)

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
```

## 限制 Constraints

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    
}
```
