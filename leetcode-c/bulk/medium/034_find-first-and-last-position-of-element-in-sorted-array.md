# 0034. Find First and Last Position of Element in Sorted Array《在排序陣列中找元素的第一個和最後一個位置》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
- **程式碼**: [`034_find-first-and-last-position-of-element-in-sorted-array.c`](./034_find-first-and-last-position-of-element-in-sorted-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個非遞減排序的整數陣列 nums，找出目標值 target 首次與最後一次出現的索引。若不存在目標值，回傳 [-1, -1]；演算法必須達到 O(log n) 的時間複雜度。

**思路**：程式先以二分搜尋找到 target 的任一位置；命中後再向左右線性擴展，取得連續相同值的邊界。

## Problem Statement (English)

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]
```

## 限制 Constraints

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
}
```
