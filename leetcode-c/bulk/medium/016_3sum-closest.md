# 0016. 3Sum Closest《最接近的三數之和》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, sorting
- **題目連結**: https://leetcode.com/problems/3sum-closest/
- **程式碼**: [`016_3sum-closest.c`](./016_3sum-closest.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與 target，找出三個元素，使其總和最接近 target，並回傳該總和。每筆輸入保證恰有一個答案。

**思路**：程式先排序，逐一固定第一個元素，並以兩個指針在其右側逼近 target。每次計算目前和與 target 的差距，保存絕對值最小的差；若剛好相等則立即回傳。

## Problem Statement (English)

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```

## 限制 Constraints

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

## 官方 C 函式簽名 Signature

```c
int threeSumClosest(int* nums, int numsSize, int target) {
    
}
```
