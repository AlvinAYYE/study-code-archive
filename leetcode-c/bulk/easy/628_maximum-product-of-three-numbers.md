# 0628. Maximum Product of Three Numbers《三個數的最大乘積》

- **Difficulty**: Easy
- **Tags**: array, math, sorting
- **題目連結**: https://leetcode.com/problems/maximum-product-of-three-numbers/
- **程式碼**: [`628_maximum-product-of-three-numbers.c`](./628_maximum-product-of-three-numbers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定至少含三個整數的陣列，選出三個數使其乘積最大，並回傳該乘積。陣列可能含負數，因此兩個最小負數與最大正數的組合也必須考慮。

**思路**：將陣列由大到小排序後，比較前三大數的乘積，以及最大數乘上最後兩個最小數的乘積。兩者較大者即為答案。

## Problem Statement (English)

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: 6

Input: nums = [1,2,3,4]
Output: 24

Input: nums = [-1,-2,-3]
Output: -6
```

## 限制 Constraints

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int maximumProduct(int* nums, int numsSize) {
    
}
```
