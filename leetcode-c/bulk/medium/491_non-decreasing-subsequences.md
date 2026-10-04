# 0491. Non-decreasing Subsequences《遞增子序列》

- **Difficulty**: Medium
- **Tags**: array, hash-table, backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/non-decreasing-subsequences/
- **程式碼**: [`491_non-decreasing-subsequences.c`](./491_non-decreasing-subsequences.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，回傳所有長度至少為 2 的不同非遞減子序列，且必須保留原陣列中的相對順序。答案可用任意順序回傳。

**思路**：程式以回溯法嘗試後續元素，只在其不小於目前序列尾端時加入。每一層用值域 -100 到 100 的集合排除重複選擇，並在長度至少 2 時輸出副本。

## Problem Statement (English)

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
```

## 限制 Constraints

1 <= nums.length <= 15
-100 <= nums[i] <= 100

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
