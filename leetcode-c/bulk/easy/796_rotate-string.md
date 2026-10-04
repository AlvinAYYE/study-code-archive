# 0796. Rotate String《旋轉字串》

- **Difficulty**: Easy
- **Tags**: string, string-matching
- **題目連結**: https://leetcode.com/problems/rotate-string/
- **程式碼**: [`796_rotate-string.c`](./796_rotate-string.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定小寫字串 s 與 goal，判斷 s 經過任意次左旋後能否成為 goal。一次左旋會將 s 最左字元移到最右端，兩字串長度最多為 100。

**思路**：先檢查長度，接著反覆把目前字串首字元移至尾端並與 goal 比較；任一次相同即回傳 true。

## Problem Statement (English)

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abcde", goal = "cdeab"
Output: true

Input: s = "abcde", goal = "abced"
Output: false
```

## 限制 Constraints

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool rotateString(char* s, char* goal) {
    
}
```
