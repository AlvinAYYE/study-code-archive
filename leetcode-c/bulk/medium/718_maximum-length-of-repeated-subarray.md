# 0718. Maximum Length of Repeated Subarray《最長重複子陣列》

- **Difficulty**: Medium
- **Tags**: array, binary-search, dynamic-programming, sliding-window, rolling-hash, hash-function
- **題目連結**: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
- **程式碼**: [`718_maximum-length-of-repeated-subarray.c`](./718_maximum-length-of-repeated-subarray.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個整數陣列 nums1 與 nums2，找出同時出現在兩者中的最長連續子陣列長度。回傳該最大長度。

**思路**：以二維 DP 記錄兩陣列各前綴結尾處的共同連續子陣列長度。元素相等時由左上角狀態加一，並在掃描中更新最大值。

## Problem Statement (English)

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
```

## 限制 Constraints

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100

## 官方 C 函式簽名 Signature

```c
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
}
```
