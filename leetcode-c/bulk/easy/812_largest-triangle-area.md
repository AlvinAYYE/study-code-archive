# 0812. Largest Triangle Area《最大三角形面積》

- **Difficulty**: Easy
- **Tags**: array, math, geometry
- **題目連結**: https://leetcode.com/problems/largest-triangle-area/
- **程式碼**: [`812_largest-triangle-area.c`](./812_largest-triangle-area.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定平面上的互異整數座標點，從任三個不同點組成三角形，求其最大面積。點數介於 3 與 50，答案誤差在 10^-5 內可接受。

**思路**：枚舉所有三點組合，利用鞋帶公式（叉積絕對值的一半）計算面積並保留最大值。

## Problem Statement (English)

Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.

Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000
```

## 限制 Constraints

3 <= points.length <= 50
-50 <= xi, yi <= 50
All the given points are unique.

## 官方 C 函式簽名 Signature

```c
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    
}
```
