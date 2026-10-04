# 0090. Subsets II《子集 II》

- **Difficulty**: Medium
- **Tags**: array, backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/subsets-ii/
- **程式碼**: [`090_subsets-ii.c`](./090_subsets-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定可能含重複元素的整數陣列 nums，回傳所有可能的子集。答案不得包含重複子集，回傳順序不限。nums 長度介於 1 到 10。

**思路**：先排序並壓縮為每個不同數值及其出現次數。回溯時對每個數值選擇加入 0 到其出現次數個，因而避免產生重複子集。

## Problem Statement (English)

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Input: nums = [0]
Output: [[],[0]]
```

## 限制 Constraints

1 <= nums.length <= 10
-10 <= nums[i] <= 10

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
