# 0516. Longest Palindromic Subsequence《最長回文子序列》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/longest-palindromic-subsequence/
- **程式碼**: [`516_longest-palindromic-subsequence.c`](./516_longest-palindromic-subsequence.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含小寫英文字母的字串 s，求其中最長回文子序列的長度。子序列可刪除任意數量字元，但必須保留剩餘字元的原始相對順序。

**思路**：以區間遞迴搭配記憶化搜尋：兩端字元相同時取內部結果加 2，否則比較捨去左端或右端後的較大值。

## Problem Statement (English)

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

## 限制 Constraints

1 <= s.length <= 1000
s consists only of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int longestPalindromeSubseq(char* s) {
    
}
```
