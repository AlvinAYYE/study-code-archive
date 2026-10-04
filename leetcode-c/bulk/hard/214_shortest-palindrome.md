# 0214. Shortest Palindrome《最短迴文》

- **Difficulty**: Hard
- **Tags**: string, rolling-hash, string-matching, hash-function
- **題目連結**: https://leetcode.com/problems/shortest-palindrome/
- **程式碼**: [`214_shortest-palindrome.c`](./214_shortest-palindrome.c) — 社群解答（repo tongtzeho_LeetCode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，只能在字串前方加入字元，使結果成為迴文。請回傳可得到的最短迴文字串。字串只含小寫英文字母，長度最多為 5 × 10^4。

**思路**：先建立原字串的 KMP 失配表，再以反轉字串去匹配原字串前綴，求出最長迴文前綴；保留反轉字串並接上尚未匹配的原字串後綴。

## Problem Statement (English)

You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "aacecaaa"
Output: "aaacecaaa"

Input: s = "abcd"
Output: "dcbabcd"
```

## 限制 Constraints

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

## 官方 C 函式簽名 Signature

```c
char* shortestPalindrome(char* s) {
    
}
```
