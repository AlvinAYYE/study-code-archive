# 0334. Increasing Triplet Subsequence《遞增三元子序列》

- **Difficulty**: Medium
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/increasing-triplet-subsequence/
- **程式碼**: [`334_increasing-triplet-subsequence.c`](./334_increasing-triplet-subsequence.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，判斷是否存在索引 i < j < k，使 nums[i] < nums[j] < nums[k]。若存在任一嚴格遞增的長度 3 子序列則回傳 true，否則回傳 false。

**思路**：單次掃描維護目前最小的第一個值 min1，以及可作為第二個值的最小 min2。若遇到大於 min2 的數字，便已找到遞增三元組。

## Problem Statement (English)

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

## 限制 Constraints

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool increasingTriplet(int* nums, int numsSize) {
    
}
```
