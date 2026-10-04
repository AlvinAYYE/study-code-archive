# 0414. Third Maximum Number《第三大的數》

- **Difficulty**: Easy
- **Tags**: array, sorting
- **題目連結**: https://leetcode.com/problems/third-maximum-number/
- **程式碼**: [`414_third-maximum-number.c`](./414_third-maximum-number.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，回傳其中第三大的不同數值。若不同數值不足三個，則回傳最大值；重複值只計算一次。

**思路**：將原陣列建成最大堆，持續取出最大元素。以先前取出的值判斷是否為新數值，數到第三個不同值時回傳，否則保留第一個最大值。

## Problem Statement (English)

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
```

## 限制 Constraints

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int thirdMax(int* nums, int numsSize) {
    
}
```
