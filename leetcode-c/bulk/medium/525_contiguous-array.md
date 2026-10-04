# 0525. Contiguous Array《連續陣列》

- **Difficulty**: Medium
- **Tags**: array, hash-table, prefix-sum
- **題目連結**: https://leetcode.com/problems/contiguous-array/
- **程式碼**: [`525_contiguous-array.c`](./525_contiguous-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含 0 與 1 的二元陣列，找出其中 0 和 1 數量相等的最長連續子陣列長度。陣列長度最多為 10^5。

**思路**：以 0 的累計數減去 1 的累計數作為前綴差值，雜湊表保存每個差值最早出現的位置；再次遇到相同差值即可更新最長距離。

## Problem Statement (English)

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
```

## 限制 Constraints

1 <= nums.length <= 105
nums[i] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
int findMaxLength(int* nums, int numsSize) {
    
}
```
