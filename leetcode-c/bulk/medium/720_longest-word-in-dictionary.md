# 0720. Longest Word in Dictionary《字典中的最長單詞》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, trie, sorting
- **題目連結**: https://leetcode.com/problems/longest-word-in-dictionary/
- **程式碼**: [`720_longest-word-in-dictionary.c`](./720_longest-word-in-dictionary.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字典單詞陣列，找出可由字典中其他單詞每次在尾端增加一個字元、由左至右建成的最長單詞。若最長者不唯一，回傳字典序最小者；若無符合者則回傳空字串。

**思路**：先按長度遞增、同長度字典序遞增排序，並用 Trie 標記已可建成的前綴。只有所有前綴都已標記的單詞能加入，掃描時保留最長結果。

## Problem Statement (English)

Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
Note that the word should be built from left to right with each additional character being added to the end of a previous word.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
```

## 限制 Constraints

1 <= words.length <= 1000
1 <= words[i].length <= 30
words[i] consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
char* longestWord(char** words, int wordsSize) {
    
}
```
