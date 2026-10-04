# 0500. Keyboard Row《鍵盤列》

- **Difficulty**: Easy
- **Tags**: array, hash-table, string
- **題目連結**: https://leetcode.com/problems/keyboard-row/
- **程式碼**: [`500_keyboard-row.c`](./500_keyboard-row.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串陣列 words，回傳能只使用美式鍵盤同一列字母輸入的所有單字。字母不分大小寫，大小寫相同的字母視為位於同一列。

**思路**：程式預先建立每個英文字母對應鍵盤列的查表。對每個單字比較所有字母列號是否和第一個字母相同，完全相同才加入結果。

## Problem Statement (English)

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
In the American keyboard:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Explanation:
Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Input: words = ["omk"]
Output: []

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
```

## 限制 Constraints

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    
}
```
