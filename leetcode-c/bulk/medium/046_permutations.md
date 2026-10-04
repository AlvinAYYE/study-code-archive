# 0046. Permutations《全排列》

- **Difficulty**: Medium
- **Tags**: array, backtracking
- **題目連結**: https://leetcode.com/problems/permutations/
- **程式碼**: [`046_permutations.c`](./046_permutations.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個元素互異的整數陣列 nums，回傳所有可能的排列，順序不限。每個排列都必須包含原陣列的所有元素各一次。

**思路**：以深度優先搜尋建立暫存排列，並用 used 陣列標記已選取的元素。暫存排列長度等於輸入長度時複製為一個答案。

## Problem Statement (English)

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Input: nums = [1]
Output: [[1]]
```

## 限制 Constraints

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
