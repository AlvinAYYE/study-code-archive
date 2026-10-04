# 0665. Non-decreasing Array《非遞減陣列》

- **Difficulty**: Medium
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/non-decreasing-array/
- **程式碼**: [`665_non-decreasing-array.c`](./665_non-decreasing-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列，判斷最多修改一個元素後，能否使整列滿足每個 nums[i] ≤ nums[i+1]。若原陣列已非遞減也應回傳 true。

**思路**：用堆疊保存目前的非遞減前綴，遇到下降處最多只允許一次修正。程式比較前一個保留值與目前值，決定等效於降低前值或提高目前值的處理方式。

## Problem Statement (English)

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one element.
```

## 限制 Constraints

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105

## 官方 C 函式簽名 Signature

```c
bool checkPossibility(int* nums, int numsSize) {
    
}
```
