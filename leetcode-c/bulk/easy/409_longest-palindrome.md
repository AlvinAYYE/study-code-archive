# 0409. Longest Palindrome《最長迴文串》

- **Difficulty**: Easy
- **Tags**: hash-table, string, greedy
- **題目連結**: https://leetcode.com/problems/longest-palindrome/
- **程式碼**: [`409_longest-palindrome.c`](./409_longest-palindrome.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含英文大小寫字母的字串 s，求能以其中字元重新排列出的最長迴文串長度。字母大小寫有別，例如 "A" 與 "a" 不視為相同字元。

**思路**：以 52 格計數陣列統計每種大小寫字母出現次數。每種字元可貢獻最大的偶數數量，若存在任一奇數次字元，額外放一個到迴文中心。

## Problem Statement (English)

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
```

## 限制 Constraints

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

## 官方 C 函式簽名 Signature

```c
int longestPalindrome(char* s) {
    
}
```
