# 0704. Binary Search《二分搜尋》

- **Difficulty**: Easy
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/binary-search/
- **程式碼**: [`704_binary-search.c`](./704_binary-search.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定遞增排序且元素互異的整數陣列 nums 與 target，找出 target 的索引。若不存在則回傳 -1，且演算法時間複雜度必須為 O(log n)。

**思路**：維護左右邊界並反覆比較中點與 target，捨棄不可能的一半區間。找到即回傳索引，邊界交錯後回傳 -1。

## Problem Statement (English)

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

## 限制 Constraints

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

## 官方 C 函式簽名 Signature

```c
int search(int* nums, int numsSize, int target) {
    
}
```
