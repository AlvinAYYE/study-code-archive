# 0674. Longest Continuous Increasing Subsequence《最長連續遞增序列》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
- **程式碼**: [`674_longest-continuous-increasing-subsequence.c`](./674_longest-continuous-increasing-subsequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定未排序整數陣列，回傳最長嚴格遞增且連續的子陣列長度。若相鄰兩值不遞增，新的連續遞增序列必須從該位置重新開始。

**思路**：dp[i] 記錄以第 i 個元素結尾的連續遞增長度。若前一值小於目前值便接續前一長度，否則重設為 1，並維護最大值。

## Problem Statement (English)

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.

Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.
```

## 限制 Constraints

1 <= nums.length <= 104
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
int findLengthOfLCIS(int* nums, int numsSize) {
    
}
```
