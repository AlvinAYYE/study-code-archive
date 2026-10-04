# 0217. Contains Duplicate《存在重複元素》

- **Difficulty**: Easy
- **Tags**: array, hash-table, sorting
- **題目連結**: https://leetcode.com/problems/contains-duplicate/
- **程式碼**: [`217_contains-duplicate.c`](./217_contains-duplicate.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，判斷是否有任一數值至少出現兩次。若所有元素皆相異則回傳 false，否則回傳 true。

**思路**：先將陣列排序，再線性檢查相鄰元素是否相等；一旦相等便回傳 true。

## Problem Statement (English)

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

## 限制 Constraints

1 <= nums.length <= 105
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
bool containsDuplicate(int* nums, int numsSize) {
    
}
```
