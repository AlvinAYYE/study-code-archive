# 0078. Subsets《子集》

- **Difficulty**: Medium
- **Tags**: array, backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/subsets/
- **程式碼**: [`078_subsets.c`](./078_subsets.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個元素彼此不同的整數陣列 nums，回傳所有可能的子集，也就是冪集。答案中不得有重複子集，回傳順序不限。nums 長度介於 1 到 10。

**思路**：以深度優先搜尋對每個元素分別走不選與選取兩個分支。遞迴走到陣列尾端時，將目前暫存的子集加入結果。

## Problem Statement (English)

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Input: nums = [0]
Output: [[],[0]]
```

## 限制 Constraints

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
