# 0152. Maximum Product Subarray《乘積最大的子陣列》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/maximum-product-subarray/
- **程式碼**: [`152_maximum-product-subarray.c`](./152_maximum-product-subarray.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，找出乘積最大的非空連續子陣列並回傳其乘積。測資保證答案可放入 32 位元帶符號整數。nums 長度介於 1 至 2×10^4，元素值介於 -10 至 10，且任一子陣列乘積皆可放入 32 位元帶符號整數。

**思路**：線性掃描時同時維護以目前位置結尾的最大與最小乘積；負數會交換兩者作用，再更新全域最大乘積。

## Problem Statement (English)

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## 限制 Constraints

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int maxProduct(int* nums, int numsSize) {
    
}
```
