# 0678. Valid Parenthesis String《有效的括號字串》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming, stack, greedy
- **題目連結**: https://leetcode.com/problems/valid-parenthesis-string/
- **程式碼**: [`678_valid-parenthesis-string.c`](./678_valid-parenthesis-string.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含 '('、')' 與 '*' 的字串，判斷它是否能成為有效括號字串。'*' 可視為左括號、右括號或空字串；有效字串須讓每個左括號有對應右括號，且右括號不能先於可配對的左括號。

**思路**：先由左至右把 '*' 視為可能的左括號，確保任一前綴不會右括號過多。再由右至左把 '*' 視為可能的右括號，確保任一後綴不會左括號過多。

## Problem Statement (English)

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "()"
Output: true

Input: s = "(*)"
Output: true

Input: s = "(*))"
Output: true
```

## 限制 Constraints

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

## 官方 C 函式簽名 Signature

```c
bool checkValidString(char* s) {
    
}
```
