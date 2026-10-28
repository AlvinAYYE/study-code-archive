# 0030. Substring with Concatenation of All Words《串聯所有單字的子字串》

- **Difficulty**: Hard
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
- **程式碼**: [`030_substring-with-concatenation-of-all-words.c`](./030_substring-with-concatenation-of-all-words.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 `s` 與單字陣列 `words`，其中所有單字長度相同。合法的串聯字串必須恰好包含 `words` 中的每個單字一次；重複單字也須計入，單字排列順序任意，且中間不能夾雜其他字元。請回傳 `s` 中所有符合條件之子字串的起始索引，順序不限。

## 解題思路

1. 因為所有單字等長，可把 `s` 依 `word_len` 為步長切成一個個候選單字。
2. 先用雜湊表為每個相異單字編號；`counts` 記錄需求次數，`counts2` 記錄目前視窗已有的次數。
3. `right` 每次讀取一個候選單字。若它不在 `words` 中，清空視窗並把搜尋起點向右移一個字元，改試下一種對齊位置。
4. 若某個單字出現過量，持續從 `mid` 移出左端單字，直到次數重新合法。
5. 視窗累計 `wordsSize` 個單字時記錄 `mid`，再從下一個可能起點繼續搜尋，因此也能找到彼此重疊的答案。

平均時間約為 `O(|s| * word_len)`，額外空間為 `O(|s| + wordsSize)`。

## Problem Statement (English)

You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：s = "barfoothefoobarman", words = ["foo","bar"]
輸出：[0,9]
說明：索引 0 的 "barfoo" 與索引 9 的 "foobar" 都恰好串聯全部單字。

輸入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
輸出：[]
說明：不存在符合條件的連續子字串。

輸入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
輸出：[6,9,12]
說明：三個起點對應的子字串依序為 "foobarthe"、"barthefoo"、"thefoobar"。
```

## 限制

- `1 <= s.length <= 10^4`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` 與 `words[i]` 僅包含小寫英文字母。

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
}
```
