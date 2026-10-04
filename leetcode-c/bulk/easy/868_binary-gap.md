# 0868. Binary Gap《二進位間距》

- **Difficulty**: Easy
- **Tags**: bit-manipulation
- **題目連結**: https://leetcode.com/problems/binary-gap/
- **程式碼**: [`868_binary-gap.c`](./868_binary-gap.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，求其二進位表示中任兩個相鄰 1 的最大距離；相鄰指兩者之間只可能有 0。距離為兩個位元位置之差，若不足兩個 1 則回傳 0。

**思路**：程式掃描 n 的 32 個位元，記錄前一次出現 1 的位置。每遇到新的 1 就計算與前一個 1 的距離並更新最大值。

## Problem Statement (English)

Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.

Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.

Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
```

## 限制 Constraints

1 <= n <= 109

## 官方 C 函式簽名 Signature

```c
int binaryGap(int n) {
    
}
```
