# 0127. Word Ladder《單字接龍》

- **Difficulty**: Hard
- **Tags**: hash-table, string, breadth-first-search
- **題目連結**: https://leetcode.com/problems/word-ladder/
- **程式碼**: [`127_word-ladder.c`](./127_word-ladder.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 `beginWord`、`endWord` 與字典 `wordList`。轉換序列每一步只能改變一個字母，且轉換後的每個單字都必須在 `wordList` 中。請回傳從 `beginWord` 到 `endWord` 的最短轉換序列所含單字數；若不存在則回傳 0。

## 解題思路

1. 把每個單字視為圖上的節點；兩個單字只差一個字母時，兩者之間存在一條邊。
2. 從 `beginWord` 做廣度優先搜尋。`q1` 保存目前層，`q2` 收集下一層，`d` 記錄已走的邊數。
3. 對目前層的每個單字，掃描尚未拜訪的字典單字，用 `one_diff` 判斷是否恰好只差一個字母；符合者標記並加入下一層。
4. 第一次遇到 `endWord` 時一定走的是最短路徑，立即回傳層數。
5. 佇列耗盡仍未找到時回傳 0。

若字典有 `N` 個單字、每個長度為 `L`，時間複雜度為 `O(N^2 L)`；`visited` 與佇列使用 `O(N)` 空間。

## Problem Statement (English)

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
輸出：5
說明：最短序列之一為 hit -> hot -> dot -> dog -> cog，共 5 個單字。

輸入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
輸出：0
說明：`endWord` 不在字典中，因此不存在合法轉換序列。
```

## 限制

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord`、`endWord` 與 `wordList[i]` 僅包含小寫英文字母。
- `beginWord != endWord`
- `wordList` 中的單字互不重複。

## 官方 C 函式簽名 Signature

```c
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    
}
```
