# 0645. Set Mismatch《錯誤的集合》

- **Difficulty**: Easy
- **Tags**: array, hash-table, bit-manipulation, sorting
- **題目連結**: https://leetcode.com/problems/set-mismatch/
- **程式碼**: [`645_set-mismatch.c`](./645_set-mismatch.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

原本應包含 1 到 n 各一次的集合，因一個數字被重複寫成另一個數字，造成一個數重複、另一個數缺失。給定錯誤後的陣列，回傳重複的數與缺失的數。

**思路**：建立大小為 n 的計數陣列，逐一統計每個值出現次數。出現兩次的位置對應重複值，從未出現的位置對應缺失值。

## Problem Statement (English)

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,2,4]
Output: [2,3]

Input: nums = [1,1]
Output: [1,2]
```

## 限制 Constraints

2 <= nums.length <= 104
1 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    
}
```
