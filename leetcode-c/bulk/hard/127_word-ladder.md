# 0127. Word Ladder《單字接龍》

- **Difficulty**: Hard
- **Tags**: hash-table, string, breadth-first-search
- **題目連結**: https://leetcode.com/problems/word-ladder/
- **程式碼**: [`127_word-ladder.c`](./127_word-ladder.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 beginWord、endWord 與字典 wordList，轉換序列中每一步只能改變一個字母，且每個轉換後的單字都必須在字典中。請回傳從 beginWord 到 endWord 的最短轉換序列所含單字數；若不存在則回傳 0。所有單字等長且由小寫英文字母組成，beginWord 與 endWord 不同，字典單字不重複。單字長度至多 10，wordList 長度至多 5000。

**思路**：從 beginWord 做廣度優先搜尋，以兩個佇列分層處理；對每個未拜訪字典單字檢查是否只差一個字母，首次到達 endWord 即得到最短層數。

## Problem Statement (English)

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

## 限制 Constraints

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

## 官方 C 函式簽名 Signature

```c
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    
}
```
