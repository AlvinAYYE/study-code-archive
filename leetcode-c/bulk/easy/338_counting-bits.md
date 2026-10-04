# 0338. Counting Bits《位元計數》

- **Difficulty**: Easy
- **Tags**: dynamic-programming, bit-manipulation
- **題目連結**: https://leetcode.com/problems/counting-bits/
- **程式碼**: [`338_counting-bits.c`](./338_counting-bits.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，回傳長度為 n + 1 的陣列 ans。對每個 0 到 n 的整數 i，ans[i] 必須是 i 的二進位表示中 1 的個數。

**思路**：建立動態規劃陣列，利用 i & (i - 1) 會清除最低位 1 的性質，令 dp[i] = dp[i & (i - 1)] + 1。

## Problem Statement (English)

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

## 限制 Constraints

0 <= n <= 105

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    
}
```
