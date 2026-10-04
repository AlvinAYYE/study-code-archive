# 0713. Subarray Product Less Than K《乘積小於 K 的子陣列》

- **Difficulty**: Medium
- **Tags**: array, binary-search, sliding-window, prefix-sum
- **題目連結**: https://leetcode.com/problems/subarray-product-less-than-k/
- **程式碼**: [`713_subarray-product-less-than-k.c`](./713_subarray-product-less-than-k.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數陣列 nums 與整數 k，計算所有元素乘積嚴格小於 k 的連續子陣列數量。乘積等於 k 的子陣列不應計入。

**思路**：以雙指針維護乘積小於 k 的滑動視窗，右端加入元素後，必要時不斷移動左端並除回其值。每個右端能產生的有效子陣列數就是目前視窗長度。

## Problem Statement (English)

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Input: nums = [1,2,3], k = 0
Output: 0
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106

## 官方 C 函式簽名 Signature

```c
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    
}
```
