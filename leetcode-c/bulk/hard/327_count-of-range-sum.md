# 0327. Count of Range Sum《區間和的個數》

- **Difficulty**: Hard
- **Tags**: array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set
- **題目連結**: https://leetcode.com/problems/count-of-range-sum/
- **程式碼**: [`327_count-of-range-sum.c`](./327_count-of-range-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 及 lower、upper，請計算所有連續區間和落在閉區間 [lower, upper] 的區間數。區間和 S(i, j) 為 nums 從 i 到 j（含）的元素總和，且 i ≤ j。

**思路**：先建立前綴和，並以遞迴分治處理左右兩半。合併前在已排序的右半中檢查每個左側前綴和的差是否落在範圍內並計數，接著執行合併排序。

## Problem Statement (English)

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

Input: nums = [0], lower = 0, upper = 0
Output: 1
```

## 限制 Constraints

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
-105 <= lower <= upper <= 105
The answer is guaranteed to fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    
}
```
