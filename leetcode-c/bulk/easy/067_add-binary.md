# 0067. Add Binary《二進位求和》

- **Difficulty**: Easy
- **Tags**: math, string, bit-manipulation, simulation
- **題目連結**: https://leetcode.com/problems/add-binary/
- **程式碼**: [`067_add-binary.c`](./067_add-binary.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個只由 '0' 與 '1' 組成的二進位字串 a、b，回傳它們的二進位和。除了數字零本身外，兩個輸入都不含前導零。

**思路**：由兩字串尾端開始逐位相加並攜帶進位，先把結果以反向順序寫入緩衝區。處理完剩餘位與最後進位後，再將字串反轉。

## Problem Statement (English)

Given two binary strings a and b, return their sum as a binary string.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"
```

## 限制 Constraints

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

## 官方 C 函式簽名 Signature

```c
char* addBinary(char* a, char* b) {
    
}
```
