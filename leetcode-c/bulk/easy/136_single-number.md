# 0136. Single Number《只出現一次的數字》

- **Difficulty**: Easy
- **Tags**: array, bit-manipulation
- **題目連結**: https://leetcode.com/problems/single-number/
- **程式碼**: [`136_single-number.c`](./136_single-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非空整數陣列 nums，除了某一個元素只出現一次外，其餘每個元素都恰好出現兩次。請找出並回傳該唯一元素。解法必須為線性時間且只使用常數額外空間。nums 長度介於 1 至 3×10^4，元素值介於 -3×10^4 至 3×10^4。

**思路**：將所有元素逐一做 XOR；成對元素會互相消去，最後保留只出現一次的數字。

## Problem Statement (English)

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

## 官方 C 函式簽名 Signature

```c
int singleNumber(int* nums, int numsSize) {
    
}
```
