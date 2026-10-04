# 0477. Total Hamming Distance《漢明距離總和》

- **Difficulty**: Medium
- **Tags**: array, math, bit-manipulation
- **題目連結**: https://leetcode.com/problems/total-hamming-distance/
- **程式碼**: [`477_total-hamming-distance.c`](./477_total-hamming-distance.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

兩個整數的漢明距離是二進位表示中對應位元不同的數量。給定整數陣列 nums，回傳所有整數配對的漢明距離總和。

**思路**：程式逐一檢查 32 個位元，統計該位為 1 的元素數 k。此位貢獻 k × (numsSize - k)，將各位貢獻相加即可。

## Problem Statement (English)

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Input: nums = [4,14,4]
Output: 4
```

## 限制 Constraints

1 <= nums.length <= 104
0 <= nums[i] <= 109
The answer for the given input will fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int totalHammingDistance(int* nums, int numsSize) {
    
}
```
