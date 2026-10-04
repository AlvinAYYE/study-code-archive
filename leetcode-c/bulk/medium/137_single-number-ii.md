# 0137. Single Number II《只出現一次的數字 II》

- **Difficulty**: Medium
- **Tags**: array, bit-manipulation
- **題目連結**: https://leetcode.com/problems/single-number-ii/
- **程式碼**: [`137_single-number-ii.c`](./137_single-number-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，除了某個元素恰好出現一次外，其餘每個元素都恰好出現三次。請找出並回傳這個唯一元素。解法必須為線性時間且只使用常數額外空間。nums 長度介於 1 至 3×10^4，元素值介於 -2^31 至 2^31−1。

**思路**：使用 ones 與 twos 兩個位元遮罩記錄每個位元出現次數對 3 取模後的狀態，掃描完後 ones 即為唯一數字。

## Problem Statement (English)

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,2,3,2]
Output: 3

Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

## 官方 C 函式簽名 Signature

```c
int singleNumber(int* nums, int numsSize) {
    
}
```
