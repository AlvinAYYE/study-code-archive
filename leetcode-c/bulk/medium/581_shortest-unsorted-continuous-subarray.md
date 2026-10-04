# 0581. Shortest Unsorted Continuous Subarray《最短未排序連續子陣列》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, stack, greedy, sorting, monotonic-stack
- **題目連結**: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
- **程式碼**: [`581_shortest-unsorted-continuous-subarray.c`](./581_shortest-unsorted-continuous-subarray.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，找出最短的連續子陣列，使只要將它非遞減排序，整個陣列便會非遞減排序。請回傳此子陣列長度；若原本已有序則回傳 0。

**思路**：複製陣列並排序，從左右兩端分別找出原陣列與排序副本第一個不同的位置，兩位置之間的長度就是答案。

## Problem Statement (English)

Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
Return the shortest such subarray and output its length.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Input: nums = [1,2,3,4]
Output: 0

Input: nums = [1]
Output: 0
```

## 限制 Constraints

1 <= nums.length <= 104
-105 <= nums[i] <= 105

## 官方 C 函式簽名 Signature

```c
int findUnsortedSubarray(int* nums, int numsSize) {
    
}
```
