# 0268. Missing Number《缺失的數字》

- **Difficulty**: Easy
- **Tags**: array, hash-table, math, binary-search, bit-manipulation, sorting
- **題目連結**: https://leetcode.com/problems/missing-number/
- **程式碼**: [`268_missing-number.c`](./268_missing-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定含有 n 個相異數字的陣列 nums，所有數字皆在 [0, n] 中，找出範圍內唯一沒有出現的數字。題目追問要求以 O(n) 時間及 O(1) 額外空間完成。

**思路**：先計算 0 到 n 的等差級數總和，再逐一扣除陣列中的數字。最終剩餘值就是缺失數字。

## Problem Statement (English)

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

## 範例 Examples

```text
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3] . 2 is the missing number in the range since it does not appear in nums .

Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2] . 2 is the missing number in the range since it does not appear in nums .

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9] . 8 is the missing number in the range since it does not appear in nums .
```

## 限制 Constraints

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

## 官方 C 函式簽名 Signature

```c
int missingNumber(int* nums, int numsSize) {
    
}
```
