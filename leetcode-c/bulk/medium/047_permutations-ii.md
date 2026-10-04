# 0047. Permutations II《全排列 II》

- **Difficulty**: Medium
- **Tags**: array, backtracking, sorting
- **題目連結**: https://leetcode.com/problems/permutations-ii/
- **程式碼**: [`047_permutations-ii.c`](./047_permutations-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定可能含重複元素的整數陣列 nums，回傳所有不重複的排列，輸出順序不限。重複數值不能導致相同排列重複出現在答案中。

**思路**：先排序，再用 DFS 與已使用標記建立排列。若當前值與前一值相同且前一位置尚未使用，就跳過它以避免產生重複排列。

## Problem Statement (English)

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

## 限制 Constraints

1 <= nums.length <= 8
-10 <= nums[i] <= 10

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
