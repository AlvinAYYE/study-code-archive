# 0001. Two Sum《两数之和》

- **Difficulty**: Easy
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/two-sum/
- **程式碼**: [`001_two-sum.c`](./001_two-sum.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與整數 target，找出兩個相加恰為 target 的元素，並回傳它們的索引。每筆輸入恰有一組答案，且同一個元素不得使用兩次；索引的回傳順序不限。

**思路**：程式以開放定址雜湊表儲存已走訪的數值及索引，逐一查詢 target 減目前數值的補數。找到補數後立即回傳該索引與目前索引。

## Problem Statement (English)

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
```

## 限制 Constraints

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
}
```
