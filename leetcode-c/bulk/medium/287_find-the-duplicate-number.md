# 0287. Find the Duplicate Number《尋找重複數》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search, bit-manipulation
- **題目連結**: https://leetcode.com/problems/find-the-duplicate-number/
- **程式碼**: [`287_find-the-duplicate-number.c`](./287_find-the-duplicate-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

nums 含有 n + 1 個整數，且每個值都在 [1, n] 範圍內，其中恰有一個數值重複出現，重複次數可能超過兩次。請找出該重複數，且不得修改陣列並只能使用 O(1) 額外空間。

**思路**：把陣列值視為下一個索引，使用 Floyd 快慢指標先在環中相遇。再讓其中一指標回到起點並同步前進，第二次相遇的位置就是重複值。

## Problem Statement (English)

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up:

## 範例 Examples

```text
Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3,1,3,4,2]
Output: 3

Input: nums = [3,3,3,3,3]
Output: 3
```

## 限制 Constraints

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

## 官方 C 函式簽名 Signature

```c
int findDuplicate(int* nums, int numsSize) {
    
}
```
