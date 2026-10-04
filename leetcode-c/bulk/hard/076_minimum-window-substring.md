# 0076. Minimum Window Substring《最小覆蓋子字串》

- **Difficulty**: Hard
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/minimum-window-substring/
- **程式碼**: [`076_minimum-window-substring.c`](./076_minimum-window-substring.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與 t，找出 s 中最短且包含 t 所有字元的子字串，重複字元也必須包含足夠次數。若不存在則回傳空字串。測資保證最短答案唯一。

**思路**：以字元計數表搭配左右指針維護滑動視窗，右端擴張直到涵蓋 t 的所有字元。視窗有效時持續收縮左端並記錄最短區間。

## Problem Statement (English)

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you find an algorithm that runs in O(m + n) time?

## 範例 Examples

```text
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

## 限制 Constraints

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

## 官方 C 函式簽名 Signature

```c
char* minWindow(char* s, char* t) {
    
}
```
