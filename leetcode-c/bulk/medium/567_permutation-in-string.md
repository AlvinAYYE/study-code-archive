# 0567. Permutation in String《字串的排列》

- **Difficulty**: Medium
- **Tags**: hash-table, two-pointers, string, sliding-window
- **題目連結**: https://leetcode.com/problems/permutation-in-string/
- **程式碼**: [`567_permutation-in-string.c`](./567_permutation-in-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個只含小寫字母的字串 s1 與 s2，判斷 s2 是否含有某個 s1 排列組成的連續子字串。若有回傳 true，否則回傳 false。

**思路**：以 26 格計數陣列維護 s1 所需字元，滑動掃描 s2；遇到某字元超量便縮小左界，所需字元總數歸零時即找到排列視窗。

## Problem Statement (English)

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

## 限制 Constraints

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool checkInclusion(char* s1, char* s2) {
    
}
```
