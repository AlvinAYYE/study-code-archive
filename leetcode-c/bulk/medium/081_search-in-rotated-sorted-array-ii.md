# 0081. Search in Rotated Sorted Array II《搜尋旋轉排序陣列 II》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
- **程式碼**: [`081_search-in-rotated-sorted-array-ii.c`](./081_search-in-rotated-sorted-array-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個原本非遞減排序、但在未知位置旋轉過的整數陣列 nums，其中可能包含重複值。判斷 target 是否存在於陣列中，存在回傳 true，否則回傳 false。應盡量減少操作步數。

**思路**：採用二分搜尋判斷哪一半仍有序，並依 target 所在範圍縮小搜尋區間。當左端與中點相等而無法判定時，左端逐步右移以排除重複值。

## Problem Statement (English)

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.
Example 1:
Example 2:
Constraints:
Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

## 範例 Examples

```text
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

## 限制 Constraints

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104

## 官方 C 函式簽名 Signature

```c
bool search(int* nums, int numsSize, int target) {
    
}
```
