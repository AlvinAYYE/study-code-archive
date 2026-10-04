# 0493. Reverse Pairs《翻轉對》

- **Difficulty**: Hard
- **Tags**: array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set
- **題目連結**: https://leetcode.com/problems/reverse-pairs/
- **程式碼**: [`493_reverse-pairs.c`](./493_reverse-pairs.c) — 社群解答（repo tongtzeho_LeetCode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，翻轉對是滿足 i < j 且 nums[i] > 2 × nums[j] 的索引對 (i, j)。回傳陣列中翻轉對的總數。

**思路**：程式使用合併排序，在兩個已排序半區間以雙指標計數符合條件的配對，並以 long long 避免乘法溢位。接著合併兩半，讓上層遞迴也能線性計數。

## Problem Statement (English)

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```

## 限制 Constraints

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int reversePairs(int* nums, int numsSize) {
    
}
```
