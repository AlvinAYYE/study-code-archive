# 0446. Arithmetic Slices II - Subsequence《等差數列劃分 II：子序列》

- **Difficulty**: Hard
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
- **程式碼**: [`446_arithmetic-slices-ii-subsequence.c`](./446_arithmetic-slices-ii-subsequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，回傳所有長度至少為 3 的等差子序列數量。子序列可刪除任意元素但必須保留原順序，且測資保證答案可裝入 32 位元整數。

**思路**：對每個結尾索引 i，以雜湊串列記錄各公差的二元以上序列數量。枚舉前一索引 j 時，將 j 的同公差序列延伸到 i，並把原本長度至少 3 的延伸數累加到答案。

## Problem Statement (English)

Given an integer array nums, return the number of all the arithmetic subsequences of nums.
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
The test cases are generated so that the answer fits in 32-bit integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
```

## 限制 Constraints

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int numberOfArithmeticSlices(int* nums, int numsSize) {
    
}
```
