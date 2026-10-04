# 0042. Trapping Rain Water《接雨水》

- **Difficulty**: Hard
- **Tags**: array, two-pointers, dynamic-programming, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/trapping-rain-water/
- **程式碼**: [`042_trapping-rain-water.c`](./042_trapping-rain-water.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定代表地形高度的非負整數陣列，每根柱子的寬度皆為 1。請計算下雨後所有柱子之間可儲存的雨水總量。

**思路**：使用左右雙指針，每次處理較低的一端，並維護目前遇過的最高邊界。若該高度低於最高邊界，就把高度差累加為可接的水量。

## Problem Statement (English)

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Input: height = [4,2,0,3,2,5]
Output: 9
```

## 限制 Constraints

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

## 官方 C 函式簽名 Signature

```c
int trap(int* height, int heightSize) {
    
}
```
