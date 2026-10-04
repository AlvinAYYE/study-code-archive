# 0442. Find All Duplicates in an Array《陣列中所有重複項》

- **Difficulty**: Medium
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/find-all-duplicates-in-an-array/
- **程式碼**: [`442_find-all-duplicates-in-an-array.c`](./442_find-all-duplicates-in-an-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定長度為 n 的整數陣列 nums，所有值皆在 [1,n] 範圍且每個值最多出現兩次。回傳所有恰好出現兩次的數字，演算法必須為 O(n) 時間，且除輸出外只能使用常數額外空間。

**思路**：把每個值 x 對應到索引 abs(x)-1，第一次遇到時將該位置數值改為負數。若對應位置已為負，表示此值第二次出現，便加入答案。

## Problem Statement (English)

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Input: nums = [1,1,2]
Output: [1]

Input: nums = [1]
Output: []
```

## 限制 Constraints

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    
}
```
