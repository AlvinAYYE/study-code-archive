# 0179. Largest Number《最大數》

- **Difficulty**: Medium
- **Tags**: array, string, greedy, sorting
- **題目連結**: https://leetcode.com/problems/largest-number/
- **程式碼**: [`179_largest-number.c`](./179_largest-number.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一串非負整數，請重新排列它們，使串接後形成的數值最大。由於結果可能非常大，必須回傳字串而非整數。

**思路**：自訂排序比較 a+b 與 b+a 的字典序，讓較大的串接順序排在前面，再依序串接；若首項為 0，直接回傳單一 0。

## Problem Statement (English)

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [10,2]
Output: "210"

Input: nums = [3,30,34,5,9]
Output: "9534330"
```

## 限制 Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
char* largestNumber(int* nums, int numsSize) {
    
}
```
