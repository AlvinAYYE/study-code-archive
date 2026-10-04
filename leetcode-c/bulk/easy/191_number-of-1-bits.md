# 0191. Number of 1 Bits《1 的個數》

- **Difficulty**: Easy
- **Tags**: divide-and-conquer, bit-manipulation
- **題目連結**: https://leetcode.com/problems/number-of-1-bits/
- **程式碼**: [`191_number-of-1-bits.c`](./191_number-of-1-bits.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個正整數 n，請回傳其二進位表示中設定位元（1）的數量，也就是漢明重量。n 的範圍在 32 位元正整數內。

**思路**：實際函式使用平行位元計數：反覆以遮罩在各個 4 位元區塊累加位元數，再合併位元組總和並取出最高位元組。

## Problem Statement (English)

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.

Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int hammingWeight(int n) {
    
}
```
