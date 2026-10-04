# 0521. Longest Uncommon Subsequence I《最長特殊子序列 I》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/longest-uncommon-subsequence-i/
- **程式碼**: [`521_longest-uncommon-subsequence-i.c`](./521_longest-uncommon-subsequence-i.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個小寫字串 a 與 b，求最長特殊子序列的長度。特殊子序列必須恰好是兩個字串其中之一的子序列；若不存在則回傳 -1。

**思路**：程式同步比較兩字串；只要長度或對應字元不同，便回傳較長字串的長度，完全相同才回傳 -1。

## Problem Statement (English)

Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If no such uncommon subsequence exists, return -1.
An uncommon subsequence between two strings is a string that is a subsequence of exactly one of them.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: a = "aba", b = "cdc"
Output: 3
Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.

Input: a = "aaa", b = "bbb"
Output: 3
Explanation: The longest uncommon subsequences are "aaa" and "bbb".

Input: a = "aaa", b = "aaa"
Output: -1
Explanation: Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a. So the answer would be -1.
```

## 限制 Constraints

1 <= a.length, b.length <= 100
a and b consist of lower-case English letters.

## 官方 C 函式簽名 Signature

```c
int findLUSlength(char* a, char* b) {
    
}
```
