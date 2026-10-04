# 0350. Intersection of Two Arrays II《兩個陣列的交集 II》

- **Difficulty**: Easy
- **Tags**: array, hash-table, two-pointers, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/intersection-of-two-arrays-ii/
- **程式碼**: [`350_intersection-of-two-arrays-ii.c`](./350_intersection-of-two-arrays-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個整數陣列 nums1 與 nums2，回傳它們的交集。每個值在結果中出現的次數，必須等於它在兩個陣列中共同出現的次數，順序不限。

**思路**：先以雜湊表記錄 nums2 各值的剩餘次數，掃描 nums1 時若仍有可配對次數便輸出該值並遞減計數。

## Problem Statement (English)

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

## 限制 Constraints

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
}
```
