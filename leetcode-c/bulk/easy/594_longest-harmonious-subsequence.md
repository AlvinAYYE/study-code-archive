# 0594. Longest Harmonious Subsequence《最長和諧子序列》

- **Difficulty**: Easy
- **Tags**: array, hash-table, sliding-window, sorting, counting
- **題目連結**: https://leetcode.com/problems/longest-harmonious-subsequence/
- **程式碼**: [`594_longest-harmonious-subsequence.c`](./594_longest-harmonious-subsequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

和諧陣列的最大值與最小值差恰為 1。給定整數陣列 nums，請在所有子序列中找出最長和諧子序列的長度；若不存在則回傳 0。

**思路**：以雜湊表累積每個數值的出現次數，插入一個值後查詢它減一與加一的頻率，並更新可組成的最大長度。

## Problem Statement (English)

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation:
The longest harmonious subsequence is [3,2,2,2,3] .

Input: nums = [1,2,3,4]
Output: 2
Explanation:
The longest harmonious subsequences are [1,2] , [2,3] , and [3,4] , all of which have a length of 2.

Input: nums = [1,1,1,1]
Output: 0
Explanation:
No harmonic subsequence exists.
```

## 限制 Constraints

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
int findLHS(int* nums, int numsSize) {
    
}
```
