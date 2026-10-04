# 0416. Partition Equal Subset Sum《分割等和子集》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/partition-equal-subset-sum/
- **程式碼**: [`416_partition-equal-subset-sum.c`](./416_partition-equal-subset-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含正整數的陣列 nums，判斷能否分成兩個元素和相等的子集合。若總和為奇數必定無法分割，否則需判斷是否可選出總和為總和一半的元素。

**思路**：先計算總和並排除奇數情況，再以一維布林 DP 記錄可達的子集合和。每個數字由目標和向下更新，避免同一元素被重複選取。

## Problem Statement (English)

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```

## 限制 Constraints

1 <= nums.length <= 200
1 <= nums[i] <= 100

## 官方 C 函式簽名 Signature

```c
bool canPartition(int* nums, int numsSize) {
    
}
```
