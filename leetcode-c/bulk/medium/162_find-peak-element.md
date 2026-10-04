# 0162. Find Peak Element《尋找峰值元素》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/find-peak-element/
- **程式碼**: [`162_find-peak-element.c`](./162_find-peak-element.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

峰值元素嚴格大於左右相鄰元素；陣列外側的值視為負無限大。給定相鄰元素不相等的整數陣列，請回傳任一峰值的索引。演算法必須使用 O(log n) 時間。

**思路**：以二分搜尋比較 nums[mid] 與 nums[mid + 1]；若正在上坡便往右找，否則往左側（含 mid）找，最後收斂到一個峰值。

## Problem Statement (English)

A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

## 限制 Constraints

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

## 官方 C 函式簽名 Signature

```c
int findPeakElement(int* nums, int numsSize) {
    
}
```
