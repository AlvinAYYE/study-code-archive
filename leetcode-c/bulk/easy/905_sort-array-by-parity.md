# 0905. Sort Array By Parity《依奇偶排序陣列》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, sorting
- **題目連結**: https://leetcode.com/problems/sort-array-by-parity/
- **程式碼**: [`905_sort-array-by-parity.c`](./905_sort-array-by-parity.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，將所有偶數移到陣列前方，所有奇數放在後方。回傳任一符合此條件的陣列即可，元素間的相對順序不受限制。

**思路**：程式從左側掃描，遇到奇數便與目前右側尾端元素交換，並縮小右側界線。如此會將偶數留在前段、奇數逐步推往後段。

## Problem Statement (English)

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Input: nums = [0]
Output: [0]
```

## 限制 Constraints

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    
}
```
