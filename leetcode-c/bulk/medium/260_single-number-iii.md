# 0260. Single Number III《只出現一次的數字 III》

- **Difficulty**: Medium
- **Tags**: array, bit-manipulation
- **題目連結**: https://leetcode.com/problems/single-number-iii/
- **程式碼**: [`260_single-number-iii.c`](./260_single-number-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，其中恰有兩個元素只出現一次，其餘元素皆剛好出現兩次，找出這兩個元素。答案順序不限，且必須使用線性時間與常數額外空間。

**思路**：先對所有數字做 XOR，得到兩個單獨數字的異或值，並取其最低位的 1 作為分組位元。依該位元分兩組各自 XOR，即可求出兩個答案。

## Problem Statement (English)

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Input: nums = [-1,0]
Output: [-1,0]

Input: nums = [0,1]
Output: [1,0]
```

## 限制 Constraints

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    
}
```
