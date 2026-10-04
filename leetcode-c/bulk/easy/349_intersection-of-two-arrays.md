# 0349. Intersection of Two Arrays《兩個陣列的交集》

- **Difficulty**: Easy
- **Tags**: array, hash-table, two-pointers, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/intersection-of-two-arrays/
- **程式碼**: [`349_intersection-of-two-arrays.c`](./349_intersection-of-two-arrays.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個整數陣列 nums1 與 nums2，回傳它們的交集陣列。結果中的每個元素只能出現一次，輸出順序不限。

**思路**：將 nums1 放入雜湊集合，再掃描 nums2；找到共同元素時加入答案並自集合移除，以確保不重複。

## Problem Statement (English)

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

## 限制 Constraints

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
}
```
