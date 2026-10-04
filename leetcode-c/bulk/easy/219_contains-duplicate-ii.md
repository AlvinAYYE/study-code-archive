# 0219. Contains Duplicate II《存在重複元素 II》

- **Difficulty**: Easy
- **Tags**: array, hash-table, sliding-window
- **題目連結**: https://leetcode.com/problems/contains-duplicate-ii/
- **程式碼**: [`219_contains-duplicate-ii.c`](./219_contains-duplicate-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與 k，判斷是否存在兩個不同索引 i、j，使 nums[i] 等於 nums[j]。兩索引的絕對差必須不大於 k。

**思路**：將每個值與原索引組成配對後，依值、索引排序。相同值會相鄰，比較相鄰配對的索引差是否不超過 k。

## Problem Statement (English)

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,1], k = 3
Output: true

Input: nums = [1,0,1,1], k = 1
Output: true

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

## 限制 Constraints

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

## 官方 C 函式簽名 Signature

```c
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    
}
```
