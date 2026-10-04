# 0273. Integer to English Words《整數轉英文單字》

- **Difficulty**: Hard
- **Tags**: math, string, recursion
- **題目連結**: https://leetcode.com/problems/integer-to-english-words/
- **程式碼**: [`273_integer-to-english-words.c`](./273_integer-to-english-words.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將非負整數 num 轉換為英文單字表示。輸入範圍為 0 到 2^31 - 1，單字間以單一空白分隔，0 應輸出 Zero。

**思路**：利用個位、十位、teen、百與 Billion／Million／Thousand 字詞表，從十億位開始逐個三位數區塊組裝。完成後移除最後多餘空白，並對零特別回傳 Zero。

## Problem Statement (English)

Convert a non-negative integer num to its English words representation.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: num = 123
Output: "One Hundred Twenty Three"

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

## 限制 Constraints

0 <= num <= 231 - 1

## 官方 C 函式簽名 Signature

```c
char* numberToWords(int num) {
    
}
```
