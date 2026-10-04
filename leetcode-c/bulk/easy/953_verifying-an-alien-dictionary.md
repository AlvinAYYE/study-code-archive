# 0953. Verifying an Alien Dictionary《驗證外星語字典》

- **Difficulty**: Easy
- **Tags**: array, hash-table, string
- **題目連結**: https://leetcode.com/problems/verifying-an-alien-dictionary/
- **程式碼**: [`953_verifying-an-alien-dictionary.c`](./953_verifying-an-alien-dictionary.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

外星語同樣使用小寫英文字母，但字母順序由 order 指定，且它是 26 個字母的一種排列。給定單字序列 words，判斷它們是否依該外星語的字典序排列。

**思路**：先建立字元到外星排序順位的映射，再逐對比較相鄰單字的第一個不同字元；利用字串結尾的順位處理前綴關係。

## Problem Statement (English)

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
```

## 限制 Constraints

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

## 官方 C 函式簽名 Signature

```c
bool isAlienSorted(char** words, int wordsSize, char* order) {
    
}
```
