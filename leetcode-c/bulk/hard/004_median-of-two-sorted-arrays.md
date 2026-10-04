# 0004. Median of Two Sorted Arrays《寻找两个正序数组的中位数》

- **Difficulty**: Hard
- **Tags**: array, binary-search, divide-and-conquer
- **題目連結**: https://leetcode.com/problems/median-of-two-sorted-arrays/
- **程式碼**: [`004_median-of-two-sorted-arrays.c`](./004_median-of-two-sorted-arrays.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個已排序陣列 nums1 和 nums2，回傳合併後資料的中位數。整體執行時間必須為 O(log(m+n))。

**思路**：程式固定在較短陣列上調整分割位置，並讓另一陣列的分割位置補足左右兩半的元素數。當兩側邊界滿足排序關係後，依總長度奇偶取左右邊界的中位數；另行處理其中一個陣列為空的情況。

## Problem Statement (English)

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

## 限制 Constraints

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

## 官方 C 函式簽名 Signature

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
}
```
