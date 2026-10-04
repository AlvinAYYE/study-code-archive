# 0376. Wiggle Subsequence《擺動子序列》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy
- **題目連結**: https://leetcode.com/problems/wiggle-subsequence/
- **程式碼**: [`376_wiggle-subsequence.c`](./376_wiggle-subsequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

擺動序列中相鄰元素的差必須嚴格在正、負之間交替，第一個差可為正或負；單一元素或兩個不相等元素也符合。給定整數陣列 nums，回傳其最長擺動子序列的長度；子序列刪除元素後須保留原順序。

**思路**：線性掃描相鄰差值，只有當目前差值的符號與前一次採用的差值不相同時，才計入一個新的擺動長度。

## Problem Statement (English)

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
Given an integer array nums, return the length of the longest wiggle subsequence of nums.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you solve this in O(n) time?

## 範例 Examples

```text
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
```

## 限制 Constraints

1 <= nums.length <= 1000
0 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int wiggleMaxLength(int* nums, int numsSize) {
    
}
```
