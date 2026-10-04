# 0205. Isomorphic Strings《同構字串》

- **Difficulty**: Easy
- **Tags**: hash-table, string
- **題目連結**: https://leetcode.com/problems/isomorphic-strings/
- **程式碼**: [`205_isomorphic-strings.c`](./205_isomorphic-strings.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定等長字串 s 與 t，判斷是否能將 s 的每種字元一致地替換後得到 t，且字元順序必須保留。不同來源字元不可映射到同一目標字元，但字元可以映射為自己。

**思路**：以兩個大小為 128 的表格同時記錄 s→t 與 t→s 映射；每一對字元都需符合既有雙向映射，否則回傳 false。

## Problem Statement (English)

Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:

Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r' .

Input: s = "paper", t = "title"
Output: true
```

## 限制 Constraints

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

## 官方 C 函式簽名 Signature

```c
bool isIsomorphic(char* s, char* t) {
    
}
```
