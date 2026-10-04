# 0032. Longest Valid Parentheses《最長有效括號》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, stack
- **題目連結**: https://leetcode.com/problems/longest-valid-parentheses/
- **程式碼**: [`032_longest-valid-parentheses.c`](./032_longest-valid-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定僅含 '(' 與 ')' 的字串，回傳最長格式正確且連續的括號子字串長度。空字串的答案為 0。

**思路**：程式先由左至右標記可與前方左括號配對的字元，再由右至左清除無法配對的左括號。最後掃描連續被保留的標記區段，取其最大長度。

## Problem Statement (English)

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Input: s = ""
Output: 0
```

## 限制 Constraints

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

## 官方 C 函式簽名 Signature

```c
int longestValidParentheses(char* s) {
    
}
```
