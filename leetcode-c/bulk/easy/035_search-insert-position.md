# 0035. Search Insert Position《搜尋插入位置》

- **Difficulty**: Easy
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/search-insert-position/
- **程式碼**: [`035_search-insert-position.c`](./035_search-insert-position.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定遞增排序且元素互異的整數陣列 nums 與目標值 target，若 target 已存在就回傳其索引。否則回傳將它插入後仍能維持排序的索引，且需使用 O(log n) 時間。

**思路**：以 head、tail 進行二分搜尋；找不到時，最後的 head 正好是 target 應插入的位置。

## Problem Statement (English)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4
```

## 限制 Constraints

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

## 官方 C 函式簽名 Signature

```c
int searchInsert(int* nums, int numsSize, int target) {
    
}
```
