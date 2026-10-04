# 0709. To Lower Case《轉換成小寫字母》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/to-lower-case/
- **程式碼**: [`709_to-lower-case.c`](./709_to-lower-case.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由可列印 ASCII 字元組成的字串 s，將其中所有大寫英文字母改成對應的小寫字母。回傳轉換後的字串。

**思路**：逐字元掃描字串，遇到 'A' 到 'Z' 就用 ASCII 差值原地改為小寫，其餘字元保持不變。

## Problem Statement (English)

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "Hello"
Output: "hello"

Input: s = "here"
Output: "here"

Input: s = "LOVELY"
Output: "lovely"
```

## 限制 Constraints

1 <= s.length <= 100
s consists of printable ASCII characters.

## 官方 C 函式簽名 Signature

```c
char* toLowerCase(char* s) {
    
}
```
