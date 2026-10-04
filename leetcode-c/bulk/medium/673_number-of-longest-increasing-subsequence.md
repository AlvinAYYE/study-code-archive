# 0673. Number of Longest Increasing Subsequence《最長遞增子序列的個數》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, binary-indexed-tree, segment-tree
- **題目連結**: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
- **程式碼**: [`673_number-of-longest-increasing-subsequence.c`](./673_number-of-longest-increasing-subsequence.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列，計算最長嚴格遞增子序列的數量。子序列不要求元素連續，且答案保證可放入 32 位元帶符號整數。

**思路**：對每個位置以 O(n²) 動態規劃維護最長遞增子序列長度與達到該長度的方案數。接上更長前序時覆寫計數，接上同長前序時累加計數，最後加總全域最長者。

## Problem Statement (English)

Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
```

## 限制 Constraints

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
The answer is guaranteed to fit inside a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int findNumberOfLIS(int* nums, int numsSize) {
    
}
```
