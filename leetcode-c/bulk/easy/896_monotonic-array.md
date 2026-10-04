# 0896. Monotonic Array《單調陣列》

- **Difficulty**: Easy
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/monotonic-array/
- **程式碼**: [`896_monotonic-array.c`](./896_monotonic-array.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

若整數陣列為單調遞增（可相等）或單調遞減（可相等），便稱為單調陣列。給定 nums，判斷它是否單調。

**思路**：程式略過相等的相鄰元素，並由第一個不相等的相鄰對決定方向。之後只要發現方向反轉便回傳 false。

## Problem Statement (English)

An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i = nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,2,3]
Output: true

Input: nums = [6,5,4,4]
Output: true

Input: nums = [1,3,2]
Output: false
```

## 限制 Constraints

1 <= nums.length <= 105
-105 <= nums[i] <= 105

## 官方 C 函式簽名 Signature

```c
bool isMonotonic(int* nums, int numsSize) {
    
}
```
