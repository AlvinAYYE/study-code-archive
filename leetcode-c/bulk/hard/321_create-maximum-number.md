# 0321. Create Maximum Number《建立最大數》

- **Difficulty**: Hard
- **Tags**: array, two-pointers, stack, greedy, monotonic-stack
- **題目連結**: https://leetcode.com/problems/create-maximum-number/
- **程式碼**: [`321_create-maximum-number.c`](./321_create-maximum-number.c) — 社群解答（repo tongtzeho_LeetCode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個數字陣列 nums1、nums2 與長度 k，請從兩陣列挑出共 k 個數字組成字典序最大的數字。從同一陣列選出的數字必須維持原本相對順序。

**思路**：枚舉從兩陣列各取幾位，透過預先記錄右方較大數字的位置來挑出每一側的最大子序列。再以剩餘後綴的字典序比較合併兩序列，並保留所有分配中最大的候選答案。

## Problem Statement (English)

You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
Return an array of the k digits representing the answer.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]

Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]

Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
```

## 限制 Constraints

m == nums1.length
n == nums2.length
1 <= m, n <= 500
0 <= nums1[i], nums2[i] <= 9
1 <= k <= m + n
nums1 and nums2 do not have leading zeros.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    
}
```
