# 0647. Palindromic Substrings《回文子串》

- **Difficulty**: Medium
- **Tags**: two-pointers, string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/palindromic-substrings/
- **程式碼**: [`647_palindromic-substrings.c`](./647_palindromic-substrings.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串，計算其中所有回文子字串的數量。子字串必須連續，且即使內容相同，只要起訖位置不同就要分別計數。

**思路**：用二維 DP 記錄各起訖位置的子字串是否為回文。當兩端字元相同，且長度不超過 2 或內部子字串已是回文時，即計入答案。

## Problem Statement (English)

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## 限制 Constraints

1 <= s.length <= 1000
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int countSubstrings(char* s) {
    
}
```
