# 0413. Arithmetic Slices《等差數列劃分》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, sliding-window
- **題目連結**: https://leetcode.com/problems/arithmetic-slices/
- **程式碼**: [`413_arithmetic-slices.c`](./413_arithmetic-slices.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

整數陣列中，長度至少為 3 且相鄰元素差皆相同的連續子陣列稱為等差子陣列。給定 nums，回傳其中所有等差子陣列的數量。

**思路**：線性掃描並追蹤目前連續等差區段長度。每段長度為 L 的區段可產生 (L-1)(L-2)/2 個合法子陣列，於差值中斷及掃描結束時累加。

## Problem Statement (English)

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
Given an integer array nums, return the number of arithmetic subarrays of nums.
A subarray is a contiguous subsequence of the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Input: nums = [1]
Output: 0
```

## 限制 Constraints

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int numberOfArithmeticSlices(int* nums, int numsSize) {
    
}
```
