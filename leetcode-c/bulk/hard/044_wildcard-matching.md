# 0044. Wildcard Matching《萬用字元匹配》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, greedy, recursion
- **題目連結**: https://leetcode.com/problems/wildcard-matching/
- **程式碼**: [`044_wildcard-matching.c`](./044_wildcard-matching.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

判斷字串 s 是否能被樣式 p 完整匹配，其中 '?' 可匹配任一單一字元，'*' 可匹配任意長度的字元序列（包含空序列）。匹配必須涵蓋整個 s，而非只比對其中一段。

**思路**：遞迴比對一般字元與 '?'；遇到 '*' 時先跳過連續星號，接著依序嘗試讓它吞掉不同長度的字串後綴。

## Problem Statement (English)

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
The matching should cover the entire input string (not partial).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

## 限制 Constraints

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

## 官方 C 函式簽名 Signature

```c
bool isMatch(char* s, char* p) {
    
}
```
