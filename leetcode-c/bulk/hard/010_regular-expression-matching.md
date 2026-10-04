# 0010. Regular Expression Matching《正则表达式匹配》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, recursion
- **題目連結**: https://leetcode.com/problems/regular-expression-matching/
- **程式碼**: [`010_regular-expression-matching.c`](./010_regular-expression-matching.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與模式 p，實作支援 '.' 與 '*' 的正則匹配；'.' 可匹配任一單一字元，'*' 可匹配其前一元素的零次或多次。匹配必須覆蓋整個輸入字串，而非只匹配其中一段。

**思路**：程式建立字串位置與模式位置的二維動態規劃表，先初始化可由 a* 類形式匹配空字串的狀態。遇到 '*' 時合併匹配零個、單個或更多前導元素的轉移；其他字元則依前一格與字元相容性轉移。

## Problem Statement (English)

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
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

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

## 限制 Constraints

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

## 官方 C 函式簽名 Signature

```c
bool isMatch(char* s, char* p) {
    
}
```
