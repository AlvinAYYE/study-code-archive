# 0767. Reorganize String《重組字串》

- **Difficulty**: Medium
- **Tags**: hash-table, string, greedy, sorting, heap-(priority-queue, counting
- **題目連結**: https://leetcode.com/problems/reorganize-string/
- **程式碼**: [`767_reorganize-string.c`](./767_reorganize-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含小寫英文字母的字串 s，重新排列其中字元，使任兩個相鄰字元皆不相同。若無法做到則回傳空字串，否則可回傳任一合法排列；s 長度介於 1 與 500。

**思路**：統計字母頻率並依頻率遞減排序，每輪取目前最多的兩種字母交錯放入答案後重新排序；若只剩同一字母仍未用完，便判定無解。

## Problem Statement (English)

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""
```

## 限制 Constraints

1 <= s.length <= 500
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
char* reorganizeString(char* s) {
    
}
```
