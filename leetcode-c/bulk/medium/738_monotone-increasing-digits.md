# 0738. Monotone Increasing Digits《單調遞增的數字》

- **Difficulty**: Medium
- **Tags**: math, greedy
- **題目連結**: https://leetcode.com/problems/monotone-increasing-digits/
- **程式碼**: [`738_monotone-increasing-digits.c`](./738_monotone-increasing-digits.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

若整數任兩個相鄰十進位數字皆滿足左邊不大於右邊，便稱其數字單調遞增。給定 n，回傳不大於 n 的最大單調遞增數字。

**思路**：由個位數往高位處理，若高位大於右側已確定的數字，就將該高位減一並把較低位全設為 9。最後反轉所組出的字串並轉回整數。

## Problem Statement (English)

An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 10
Output: 9

Input: n = 1234
Output: 1234

Input: n = 332
Output: 299
```

## 限制 Constraints

0 <= n <= 109

## 官方 C 函式簽名 Signature

```c
int monotoneIncreasingDigits(int n) {
    
}
```
