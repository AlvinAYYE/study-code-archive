# 0084. Largest Rectangle in Histogram《柱狀圖中最大的矩形》

- **Difficulty**: Hard
- **Tags**: array, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/largest-rectangle-in-histogram/
- **程式碼**: [`084_largest-rectangle-in-histogram.c`](./084_largest-rectangle-in-histogram.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定陣列 heights，其中每個元素代表寬度為 1 的直方圖柱高，求直方圖內最大矩形的面積。柱高可為 0，陣列長度至多為 10^5。

**思路**：逐一將每根柱子視為矩形高度，向左右擴張到遇到較低柱為止並計算可涵蓋的寬度與面積。程式以標記略過已包含在目前最大矩形中的相同高度位置。

## Problem Statement (English)

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4
```

## 限制 Constraints

1 <= heights.length <= 105
0 <= heights[i] <= 104

## 官方 C 函式簽名 Signature

```c
int largestRectangleArea(int* heights, int heightsSize) {
    
}
```
