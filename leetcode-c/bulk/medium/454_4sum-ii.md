# 0454. 4Sum II《四數相加 II》

- **Difficulty**: Medium
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/4sum-ii/
- **程式碼**: [`454_4sum-ii.c`](./454_4sum-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定四個長度皆為 n 的整數陣列 nums1、nums2、nums3、nums4，計算索引四元組 (i,j,k,l) 使四個對應元素總和為 0 的數量。每個索引都分別選自其對應陣列。

**思路**：先用自製雜湊表統計 nums3 與 nums4 每一組和的相反數出現次數。接著枚舉 nums1 與 nums2 的所有組合，查表並加上相同和值的計數。

## Problem Statement (English)

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
```

## 限制 Constraints

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

## 官方 C 函式簽名 Signature

```c
int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
    
}
```
