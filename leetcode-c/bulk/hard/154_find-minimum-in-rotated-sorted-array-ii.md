# 0154. Find Minimum in Rotated Sorted Array II《尋找旋轉排序陣列中的最小值 II》

- **Difficulty**: Hard
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
- **程式碼**: [`154_find-minimum-in-rotated-sorted-array-ii.c`](./154_find-minimum-in-rotated-sorted-array-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個原本遞增排序、經過旋轉的整數陣列，其中可能含有重複元素。請回傳其中的最小元素，並盡量減少操作次數。重複值可能使二分搜尋的最壞時間複雜度退化。

**思路**：二分比較中點與右端值：中點較大時最小值在右半部，較小時保留左半部；兩者相等時只將右端左移一格以排除重複值。

## Problem Statement (English)

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
You must decrease the overall operation steps as much as possible.
Example 1:
Example 2:
Constraints:
Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

## 範例 Examples

```text
Input: nums = [1,3,5]
Output: 1

Input: nums = [2,2,2,0,1]
Output: 0
```

## 限制 Constraints

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.

## 官方 C 函式簽名 Signature

```c
int findMin(int* nums, int numsSize) {
    
}
```
