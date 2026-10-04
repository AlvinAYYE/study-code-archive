# 0290. Word Pattern《單詞規律》

- **Difficulty**: Easy
- **Tags**: hash-table, string
- **題目連結**: https://leetcode.com/problems/word-pattern/
- **程式碼**: [`290_word-pattern.c`](./290_word-pattern.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字元模式 pattern 與以單一空白分隔的字串 s，判斷 s 是否完整遵循該模式。每個模式字元必須對應到一個非空單字，且字元與單字之間必須是一對一雙射；兩邊的項目數也必須完全相符。

**思路**：掃描每個單字，以 26 個桶記錄模式字元首次對應的字串。既有對應必須相同；建立新對應時再檢查其他字元沒有對應到同一個單字。

## Problem Statement (English)

Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

## 限制 Constraints

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

## 官方 C 函式簽名 Signature

```c
bool wordPattern(char* pattern, char* s) {
    
}
```
