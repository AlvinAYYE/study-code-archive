# 0485. Max Consecutive Ones《最大連續 1 的個數》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/max-consecutive-ones/
- **程式碼**: [`485_max-consecutive-ones.c`](./485_max-consecutive-ones.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只由 0 與 1 組成的二進位陣列 nums。回傳其中連續出現的 1 的最大個數。

**思路**：程式單次掃描並維護目前連續 1 的長度，讀到 0 時將其重設。每一步同步更新歷史最大長度。

## Problem Statement (English)

Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Input: nums = [1,0,1,1,0,1]
Output: 2
```

## 限制 Constraints

1 <= nums.length <= 105
nums[i] is either 0 or 1.

## 官方 C 函式簽名 Signature

```c
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    
}
```
