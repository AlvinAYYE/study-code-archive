# 0242. Valid Anagram《有效的字母異位詞》

- **Difficulty**: Easy
- **Tags**: hash-table, string, sorting
- **題目連結**: https://leetcode.com/problems/valid-anagram/
- **程式碼**: [`242_valid-anagram.c`](./242_valid-anagram.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與 t，判斷 t 是否為由 s 的字元重新排列而成的字母異位詞。輸入只含小寫英文字母，若字元及各自出現次數完全相同即回傳 true。

**思路**：分別以兩個長度 26 的計數陣列統計 s、t 中每個字母出現次數。先確認兩字串等長，再逐項比較計數。

## Problem Statement (English)

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Example 2:
Constraints:
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## 範例 Examples

```text
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
```

## 限制 Constraints

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool isAnagram(char* s, char* t) {
    
}
```
