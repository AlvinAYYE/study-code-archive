# 0423. Reconstruct Original Digits from English《從英文重建原始數字》

- **Difficulty**: Medium
- **Tags**: hash-table, math, string
- **題目連結**: https://leetcode.com/problems/reconstruct-original-digits-from-english/
- **程式碼**: [`423_reconstruct-original-digits-from-english.c`](./423_reconstruct-original-digits-from-english.c) — 社群解答（repo BlackDragonF_LeetcodeSolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由零到九英文名稱字母任意打亂組成的字串 s，重建所有數字並以遞增順序回傳字串。輸入保證有效，且字元只會來自英文數字名稱所需的小寫字母。

**思路**：先統計各字母數量，利用 z、w、u、x、g 等只屬於特定數字的字母依序找出 0、2、4、6、8 並扣除。剩餘數字再從其特徵字母推得，最後按 0 到 9 輸出。

## Problem Statement (English)

Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "owoztneoer"
Output: "012"

Input: s = "fviefuro"
Output: "45"
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
s is guaranteed to be valid.

## 官方 C 函式簽名 Signature

```c
char* originalDigits(char* s) {
    
}
```
