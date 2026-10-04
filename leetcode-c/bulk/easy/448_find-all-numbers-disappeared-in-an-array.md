# 0448. Find All Numbers Disappeared in an Array《找到所有陣列中消失的數字》

- **Difficulty**: Easy
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
- **程式碼**: [`448_find-all-numbers-disappeared-in-an-array.c`](./448_find-all-numbers-disappeared-in-an-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定長度為 n 的整數陣列 nums，所有元素皆在 [1,n] 範圍，回傳此範圍內未曾出現的所有數字。要求能以 O(n) 時間完成，且不計回傳陣列時不得使用額外空間。

**思路**：將每個值 x 對應到索引 abs(x)-1，並把該索引元素標記為負數。最後仍為正數的位置 i 代表數字 i+1 沒有出現，依序加入結果。

## Problem Statement (English)

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
Example 1:
Example 2:
Constraints:
Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

## 範例 Examples

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Input: nums = [1,1]
Output: [2]
```

## 限制 Constraints

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    
}
```
