# 0689. Maximum Sum of 3 Non-Overlapping Subarrays《三個不重疊子陣列的最大和》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming, sliding-window, prefix-sum
- **題目連結**: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
- **程式碼**: [`689_maximum-sum-of-3-non-overlapping-subarrays.c`](./689_maximum-sum-of-3-non-overlapping-subarrays.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與 k，選出三個長度皆為 k 且彼此不重疊的子陣列，使三者總和最大。回傳三段的起始索引；若有多組最佳解，回傳字典序最小的一組。

**思路**：先以滑動視窗算出每個長度 k 區間的和，再預處理每個位置左側與右側的最佳區間起點。枚舉中間區間，直接組合左右最佳選擇並保留總和最大的三個起點。

## Problem Statement (English)

Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
```

## 限制 Constraints

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    
}
```
