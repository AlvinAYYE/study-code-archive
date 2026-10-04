# 0912. Sort an Array《排序陣列》

- **Difficulty**: Medium
- **Tags**: array, divide-and-conquer, sorting, heap-(priority-queue, merge-sort, bucket-sort, radix-sort, counting-sort
- **題目連結**: https://leetcode.com/problems/sort-an-array/
- **程式碼**: [`912_sort-an-array.c`](./912_sort-an-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，請將其依遞增順序排序後回傳。不得使用內建排序函式，並需在 O(n log n) 時間內、以盡可能少的額外空間完成。

**思路**：程式採遞迴合併排序，先排序左右半部，再用暫存陣列合併兩段已排序區間並複製回原陣列。

## Problem Statement (English)

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
```

## 限制 Constraints

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    
}
```
