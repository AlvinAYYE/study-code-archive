# 0747. Largest Number At Least Twice of Others《至少是其他數字兩倍的最大數》

- **Difficulty**: Easy
- **Tags**: array, sorting
- **題目連結**: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
- **程式碼**: [`747_largest-number-at-least-twice-of-others.c`](./747_largest-number-at-least-twice-of-others.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定最大值唯一的整數陣列，判斷最大元素是否至少為其他每個元素的兩倍。若是則回傳最大元素索引，否則回傳 -1。

**思路**：分別掃描找出最大值及其索引，以及排除最大值後的次大值。只要最大值不少於次大值的兩倍，就回傳其索引。

## Problem Statement (English)

You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
```

## 限制 Constraints

2 <= nums.length <= 50
0 <= nums[i] <= 100
The largest element in nums is unique.

## 官方 C 函式簽名 Signature

```c
int dominantIndex(int* nums, int numsSize) {
    
}
```
