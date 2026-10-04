# 0922. Sort Array By Parity II《按奇偶排序陣列 II》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, sorting
- **題目連結**: https://leetcode.com/problems/sort-array-by-parity-ii/
- **程式碼**: [`922_sort-array-by-parity-ii.c`](./922_sort-array-by-parity-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，其中一半元素為奇數、另一半為偶數。請重新排列陣列，使奇數位於奇數索引、偶數位於偶數索引，並回傳任一符合條件的結果。

**思路**：先將奇數與偶數分別推入兩個堆疊，再依索引奇偶從對應堆疊取值回填原陣列。

## Problem Statement (English)

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
Return any answer array that satisfies this condition.
Example 1:
Example 2:
Constraints:
Follow Up: Could you solve it in-place?

## 範例 Examples

```text
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Input: nums = [2,3]
Output: [2,3]
```

## 限制 Constraints

2 <= nums.length <= 2 * 104
nums.length is even.
Half of the integers in nums are even.
0 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    
}
```
