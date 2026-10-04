# 0088. Merge Sorted Array《合併兩個排序陣列》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, sorting
- **題目連結**: https://leetcode.com/problems/merge-sorted-array/
- **程式碼**: [`088_merge-sorted-array.c`](./088_merge-sorted-array.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個非遞減排序陣列 nums1、nums2，以及各自有效元素數 m、n，將兩者合併為非遞減排序結果。nums1 長度為 m + n，前 m 個才是有效值，後 n 個預留位置；結果必須存回 nums1，而非另行回傳。

**思路**：先把 nums2 的所有元素複製到 nums1 的預留空間，再以 qsort 對整個 nums1 進行排序。

## Problem Statement (English)

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Can you come up with an algorithm that runs in O(m + n) time?

## 範例 Examples

```text
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

## 限制 Constraints

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

## 官方 C 函式簽名 Signature

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
}
```
