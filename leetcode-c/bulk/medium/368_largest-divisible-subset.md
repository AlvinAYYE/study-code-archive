# 0368. Largest Divisible Subset《最大可整除子集》

- **Difficulty**: Medium
- **Tags**: array, math, dynamic-programming, sorting
- **題目連結**: https://leetcode.com/problems/largest-divisible-subset/
- **程式碼**: [`368_largest-divisible-subset.c`](./368_largest-divisible-subset.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由相異正整數構成的陣列 nums，回傳最大的子集，使其中任兩個元素之一皆可被另一個整除。若有多種答案，可回傳任一種。

**思路**：先排序，再由後往前做動態規劃；對每個候選除數尋找可整除的後續元素，記錄最長鏈及其下一個索引以回溯答案。

## Problem Statement (English)

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
If there are multiple solutions, return any of them.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

## 限制 Constraints

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    
}
```
