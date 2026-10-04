# 0680. Valid Palindrome II《驗證回文字符串 II》

- **Difficulty**: Easy
- **Tags**: two-pointers, string, greedy
- **題目連結**: https://leetcode.com/problems/valid-palindrome-ii/
- **程式碼**: [`680_valid-palindrome-ii.c`](./680_valid-palindrome-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含小寫英文字母的字串，判斷刪除至多一個字元後是否可成為回文。若原字串本身已是回文，也應回傳 true。

**思路**：以雙指針從兩端向中央比較。第一次遇到不符時，遞迴嘗試跳過左端或右端其中一個字元，之後不再允許刪除。

## Problem Statement (English)

Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "aba"
Output: true

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Input: s = "abc"
Output: false
```

## 限制 Constraints

1 <= s.length <= 105
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool validPalindrome(char* s) {
    
}
```
