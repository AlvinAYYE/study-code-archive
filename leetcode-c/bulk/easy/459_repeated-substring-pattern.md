# 0459. Repeated Substring Pattern《重複的子字串模式》

- **Difficulty**: Easy
- **Tags**: string, string-matching
- **題目連結**: https://leetcode.com/problems/repeated-substring-pattern/
- **程式碼**: [`459_repeated-substring-pattern.c`](./459_repeated-substring-pattern.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，判斷它是否可由某個非空子字串重複串接多次組成。若可以則回傳 true，否則回傳 false。

**思路**：程式枚舉可整除字串長度的重複次數，將字串切成等長區塊。所有區塊都與第一塊相同時便回傳 true。

## Problem Statement (English)

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Input: s = "aba"
Output: false

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
```

## 限制 Constraints

1 <= s.length <= 104
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool repeatedSubstringPattern(char* s) {
    
}
```
