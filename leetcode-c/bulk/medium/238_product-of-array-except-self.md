# 0238. Product of Array Except Self《除自身以外陣列的乘積》

- **Difficulty**: Medium
- **Tags**: array, prefix-sum
- **題目連結**: https://leetcode.com/problems/product-of-array-except-self/
- **程式碼**: [`238_product-of-array-except-self.c`](./238_product-of-array-except-self.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，建立 answer，其中 answer[i] 為除 nums[i] 外所有元素的乘積。必須在 O(n) 時間內且不可使用除法；各前綴或後綴乘積保證可放入 32 位元整數。

**思路**：先由左至右把每個位置左側的前綴乘積寫入答案陣列。再由右至左維護後綴乘積，乘到對應答案位置。

## Problem Statement (English)

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
Example 2:
Constraints:
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## 範例 Examples

```text
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

## 限制 Constraints

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
}
```
