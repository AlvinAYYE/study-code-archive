# 0859. Buddy Strings《親密字串》

- **Difficulty**: Easy
- **Tags**: hash-table, string
- **題目連結**: https://leetcode.com/problems/buddy-strings/
- **程式碼**: [`859_buddy-strings.c`](./859_buddy-strings.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與 goal，判斷是否能在 s 中交換兩個不同索引的字元後使其等於 goal。若 s 與 goal 原本相同，仍須存在兩個相同字元可交換才算可行。

**思路**：程式逐字比較並記錄不相同的位置。恰有兩處差異時檢查交叉字元是否相等；沒有差異時，檢查字串是否含有重複字元。

## Problem Statement (English)

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
```

## 限制 Constraints

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.

## 官方 C 函式簽名 Signature

```c
bool buddyStrings(char* s, char* goal) {
    
}
```
