# 0788. Rotated Digits《旋轉數字》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming
- **題目連結**: https://leetcode.com/problems/rotated-digits/
- **程式碼**: [`788_rotated-digits.c`](./788_rotated-digits.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

若整數的每一位都旋轉 180 度後仍是數字，且得到的數與原數不同，則稱為好數字。給定 n，回傳區間 [1, n] 中的好數字個數，n 最多為 10^4。

**思路**：逐一枚舉 0 到 N，檢查各位數：3、4、7 直接無效，而 2、5、6、9 會使結果改變；有效且至少改變一位者計入答案。

## Problem Statement (English)

An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.
A number is valid if each digit remains a digit after rotation. For example:
Given an integer n, return the number of good integers in the range [1, n].
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Input: n = 1
Output: 0

Input: n = 2
Output: 1
```

## 限制 Constraints

1 <= n <= 104

## 官方 C 函式簽名 Signature

```c
int rotatedDigits(int n) {
    
}
```
