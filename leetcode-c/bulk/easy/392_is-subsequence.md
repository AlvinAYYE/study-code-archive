# 0392. Is Subsequence《判斷子序列》

- **Difficulty**: Easy
- **Tags**: two-pointers, string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/is-subsequence/
- **程式碼**: [`392_is-subsequence.c`](./392_is-subsequence.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與 t，判斷 s 是否為 t 的子序列。子序列可刪除原字串中的任意字元，但剩餘字元的相對順序不可改變。

**思路**：以兩個指標掃描，依序在 t 中尋找 s 當前需要的字元；s 全部匹配即為 true。

## Problem Statement (English)

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abc", t = "ahbgdc"
Output: true

Input: s = "axc", t = "ahbgdc"
Output: false
```

## 限制 Constraints

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool isSubsequence(char* s, char* t) {
    
}
```
