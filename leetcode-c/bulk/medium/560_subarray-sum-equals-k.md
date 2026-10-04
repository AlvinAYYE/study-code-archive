# 0560. Subarray Sum Equals K《和為 K 的子陣列》

- **Difficulty**: Medium
- **Tags**: array, hash-table, prefix-sum
- **題目連結**: https://leetcode.com/problems/subarray-sum-equals-k/
- **程式碼**: [`560_subarray-sum-equals-k.c`](./560_subarray-sum-equals-k.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與整數 k，回傳元素總和恰為 k 的非空連續子陣列數量。nums 可包含負數。

**思路**：以雜湊表統計已出現的前綴和頻率；掃描到目前前綴和 s 時，累加先前 s-k 的出現次數，再記錄 s。

## Problem Statement (English)

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2
```

## 限制 Constraints

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

## 官方 C 函式簽名 Signature

```c
int subarraySum(int* nums, int numsSize, int k) {
    
}
```
