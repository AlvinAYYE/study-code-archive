# 0005. Longest Palindromic Substring《最长回文子串》

- **Difficulty**: Medium
- **Tags**: two-pointers, string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/longest-palindromic-substring/
- **程式碼**: [`005_longest-palindromic-substring.c`](./005_longest-palindromic-substring.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，回傳其中最長的連續回文字串。回文在正向與反向讀取時相同。

**思路**：程式將每段相同字元視為中心，先合併連續相同字元，再向左右擴張以取得回文範圍。它記錄最長範圍，最後在原字串終點寫入結束字元後回傳該起點。

## Problem Statement (English)

Given a string s, return the longest palindromic substring in s.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Input: s = "cbbd"
Output: "bb"
```

## 限制 Constraints

1 <= s.length <= 1000
s consist of only digits and English letters.

## 官方 C 函式簽名 Signature

```c
char* longestPalindrome(char* s) {
    
}
```
