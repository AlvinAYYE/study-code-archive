# 0925. Long Pressed Name《長按鍵入的名稱》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/long-pressed-name/
- **程式碼**: [`925_long-pressed-name.c`](./925_long-pressed-name.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

朋友輸入名稱時，某個按鍵可能被長按，因此該字元會連續輸入一次或多次。給定原名稱 name 與實際輸入 typed，判斷 typed 是否可能由 name 的部分字元長按而成。可以回傳 true，否則回傳 false。

**思路**：程式先把 name 建成字典樹，逐字走訪 typed；若下一個字元沒有對應子節點，僅在它等於前一個已匹配字元時將其視為長按並略過。

## Problem Statement (English)

Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.
```

## 限制 Constraints

1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool isLongPressedName(char* name, char* typed) {
    
}
```
