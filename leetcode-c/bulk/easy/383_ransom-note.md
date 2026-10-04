# 0383. Ransom Note《贖金信》

- **Difficulty**: Easy
- **Tags**: hash-table, string, counting
- **題目連結**: https://leetcode.com/problems/ransom-note/
- **程式碼**: [`383_ransom-note.c`](./383_ransom-note.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 ransomNote 與 magazine，判斷能否只使用 magazine 中的字母組成 ransomNote。magazine 的每個字母最多只能使用一次。

**思路**：先統計贖金信各字母需求量，再掃描雜誌字母並扣除尚未滿足的需求，最後檢查是否仍有缺字。

## Problem Statement (English)

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: ransomNote = "a", magazine = "b"
Output: false

Input: ransomNote = "aa", magazine = "ab"
Output: false

Input: ransomNote = "aa", magazine = "aab"
Output: true
```

## 限制 Constraints

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
bool canConstruct(char* ransomNote, char* magazine) {
    
}
```
