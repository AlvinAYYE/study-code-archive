# 0084. Largest Rectangle in Histogram《柱狀圖中最大的矩形》

- **Difficulty**: Hard
- **Tags**: array, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/largest-rectangle-in-histogram/
- **程式碼**: [`084_largest-rectangle-in-histogram.c`](./084_largest-rectangle-in-histogram.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 `heights`，`heights[i]` 代表直方圖第 `i` 根柱子的高度，每根柱子的寬度皆為 1。請回傳直方圖中可形成的最大矩形面積。

## 解題思路

1. 將每根尚未略過的柱子 `heights[x]` 當成候選矩形高度。
2. 往左右擴張，直到遇到第一根比它矮的柱子；途中每根柱都能支撐 `heights[x]`，所以走過的總根數就是矩形寬度。
3. 同高度且落在此區間的位置記入暫存標記。若本次面積成為新最大值，保存這些標記，之後可略過會得到相同候選矩形的位置。
4. 比較所有未略過候選的 `heights[x] * width`，回傳最大值。

目前實作的最壞時間複雜度為 `O(n^2)`，標記陣列使用 `O(n)` 額外空間。

## Problem Statement (English)

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：heights = [2,1,5,6,2,3]
輸出：10
說明：高度 5、6 的相鄰柱可形成高 5、寬 2、面積 10 的矩形。

輸入：heights = [2,4]
輸出：4
```

## 限制

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

## 官方 C 函式簽名 Signature

```c
int largestRectangleArea(int* heights, int heightsSize) {
    
}
```
