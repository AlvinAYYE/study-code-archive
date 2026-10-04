# 0844. Backspace String Compare《比較含退格的字串》

- **Difficulty**: Easy
- **Tags**: two-pointers, string, stack, simulation
- **題目連結**: https://leetcode.com/problems/backspace-string-compare/
- **程式碼**: [`844_backspace-string-compare.c`](./844_backspace-string-compare.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個輸入到空白文字編輯器的字串 s 與 t，其中 # 代表退格。即使對空文字退格，結果仍保持空白；判斷兩者處理後是否相等。

**思路**：程式對兩字串各自原地模擬輸入，以寫入索引保留有效字元，遇到 # 就刪除前一個有效字元。兩者壓縮完成後直接比較結果字串。

## Problem Statement (English)

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Can you solve it in O(n) time and O(1) space?

## 範例 Examples

```text
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
```

## 限制 Constraints

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

## 官方 C 函式簽名 Signature

```c
bool backspaceCompare(char* s, char* t) {
    
}
```
