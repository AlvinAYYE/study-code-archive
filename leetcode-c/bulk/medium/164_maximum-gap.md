# 0164. Maximum Gap《最大間距》

- **Difficulty**: Medium
- **Tags**: array, sorting, bucket-sort, radix-sort
- **題目連結**: https://leetcode.com/problems/maximum-gap/
- **程式碼**: [`164_maximum-gap.c`](./164_maximum-gap.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列，請在其排序後的相鄰元素中找出最大的差值。若陣列少於兩個元素，回傳 0。解法必須使用線性時間與線性額外空間。

**思路**：程式以每次 8 位元的 LSD 基數排序進行四輪排序，再線性掃描排序結果，更新相鄰數字的最大差值。

## Problem Statement (English)

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

## 限制 Constraints

1 <= nums.length <= 105
0 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
int maximumGap(int* nums, int numsSize) {
    
}
```
