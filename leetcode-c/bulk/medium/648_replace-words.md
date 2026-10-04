# 0648. Replace Words《單詞替換》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, trie
- **題目連結**: https://leetcode.com/problems/replace-words/
- **程式碼**: [`648_replace-words.c`](./648_replace-words.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

字典提供多個字根，句子中的衍生詞若以前綴字根開頭，須以該字根取代。若同一詞可由多個字根取代，必須選擇最短的字根。句子只含小寫字母與單一空格分隔的單詞。

**思路**：將所有字根插入 Trie，並逐一走訪句子的每個單詞。搜尋時一旦到達存有字根的節點便停止，因而自然取得最短可替換字根。

## Problem Statement (English)

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```

## 限制 Constraints

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

## 官方 C 函式簽名 Signature

```c
char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
    
}
```
