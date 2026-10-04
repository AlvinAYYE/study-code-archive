# 0011. Container With Most Water《盛最多水的容器》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, greedy
- **題目連結**: https://leetcode.com/problems/container-with-most-water/
- **程式碼**: [`011_container-with-most-water.c`](./011_container-with-most-water.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定陣列 height，索引 i 對應從 (i,0) 到 (i,height[i]) 的垂直線。選出兩條線與 x 軸形成不能傾斜的容器，回傳可盛水的最大容量。

**思路**：程式以左右雙指針從陣列兩端夾逼，每次用較短邊乘上寬度更新最大面積。由於較短邊限制容量，之後只移動較短的一側。

## Problem Statement (English)

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Input: height = [1,1]
Output: 1
```

## 限制 Constraints

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

## 官方 C 函式簽名 Signature

```c
int maxArea(int* height, int heightSize) {
    
}
```
