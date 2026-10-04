# 0033. Search in Rotated Sorted Array《搜尋旋轉排序陣列》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/search-in-rotated-sorted-array/
- **程式碼**: [`033_search-in-rotated-sorted-array.c`](./033_search-in-rotated-sorted-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個元素互異、原本遞增但可能在未知樞紐旋轉過的陣列 nums，以及 target，找到 target 時回傳其索引，否則回傳 -1。演算法必須在 O(log n) 時間內完成。

**思路**：程式使用二分搜尋，並在每一步判斷中點左半或右半哪一側仍保持遞增。再依 target 是否落在該有序區間內，選擇保留對應的一半繼續搜尋。

## Problem Statement (English)

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1
```

## 限制 Constraints

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

## 官方 C 函式簽名 Signature

```c
int search(int* nums, int numsSize, int target) {
    
}
```
