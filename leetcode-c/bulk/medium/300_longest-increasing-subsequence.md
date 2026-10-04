# 0300. Longest Increasing Subsequence《最長遞增子序列》

- **Difficulty**: Medium
- **Tags**: array, binary-search, dynamic-programming
- **題目連結**: https://leetcode.com/problems/longest-increasing-subsequence/
- **程式碼**: [`300_longest-increasing-subsequence.c`](./300_longest-increasing-subsequence.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，請回傳最長嚴格遞增子序列的長度。子序列不必連續，但必須保留原本的元素相對順序。

**思路**：維護各長度遞增子序列可達到的最小結尾值。對每個數字以二分搜尋其第一個可替換位置，最後有效尾端陣列的長度即為答案。

## Problem Statement (English)

Given an integer array nums, return the length of the longest strictly increasing subsequence.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

## 範例 Examples

```text
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Input: nums = [0,1,0,3,2,3]
Output: 4

Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

## 限制 Constraints

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
int lengthOfLIS(int* nums, int numsSize) {
    
}
```
