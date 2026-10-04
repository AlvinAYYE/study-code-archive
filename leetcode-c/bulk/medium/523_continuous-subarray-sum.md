# 0523. Continuous Subarray Sum《連續子陣列和》

- **Difficulty**: Medium
- **Tags**: array, hash-table, math, prefix-sum
- **題目連結**: https://leetcode.com/problems/continuous-subarray-sum/
- **程式碼**: [`523_continuous-subarray-sum.c`](./523_continuous-subarray-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數陣列 nums 與正整數 k，判斷是否存在長度至少為 2 的連續子陣列，使其元素和為 k 的倍數。若存在回傳 true，否則回傳 false。

**思路**：維護前綴和除以 k 的餘數及其首次出現索引；兩個相同餘數之間的子陣列和可被 k 整除，索引差至少 2 時即成立。

## Problem Statement (English)

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
A good subarray is a subarray where:
Note that:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Input: nums = [23,2,6,4,7], k = 13
Output: false
```

## 限制 Constraints

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool checkSubarraySum(int* nums, int numsSize, int k) {
    
}
```
