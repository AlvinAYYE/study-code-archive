# 0693. Binary Number with Alternating Bits《交替位元的二進位數》

- **Difficulty**: Easy
- **Tags**: bit-manipulation
- **題目連結**: https://leetcode.com/problems/binary-number-with-alternating-bits/
- **程式碼**: [`693_binary-number-with-alternating-bits.c`](./693_binary-number-with-alternating-bits.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，判斷其二進位表示中的任兩個相鄰位元是否都不同。若位元 0 與 1 全程交替出現，回傳 true，否則回傳 false。

**思路**：程式先遞迴找出最高有效位元的位置，再檢查 n 與 n 右移一位的 XOR 是否恰為全 1。這個位元型態等價於原數的相鄰位元全都不同。

## Problem Statement (English)

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool hasAlternatingBits(int n) {
    
}
```
