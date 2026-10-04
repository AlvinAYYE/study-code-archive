# 0201. Bitwise AND of Numbers Range《數字範圍的位元 AND》

- **Difficulty**: Medium
- **Tags**: bit-manipulation
- **題目連結**: https://leetcode.com/problems/bitwise-and-of-numbers-range/
- **程式碼**: [`201_bitwise-and-of-numbers-range.c`](./201_bitwise-and-of-numbers-range.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 left 與 right，代表閉區間 [left, right]，請回傳區間內所有整數做位元 AND 的結果。輸入滿足 0 ≤ left ≤ right ≤ 2^31 - 1。

**思路**：程式由低位元開始清除遮罩中的位元，直到 left 與 right 的保留位元相同；最終以 left 與此共同前綴遮罩做 AND。

## Problem Statement (English)

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: left = 5, right = 7
Output: 4

Input: left = 0, right = 0
Output: 0

Input: left = 1, right = 2147483647
Output: 0
```

## 限制 Constraints

0 <= left <= right <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int rangeBitwiseAnd(int left, int right) {
    
}
```
