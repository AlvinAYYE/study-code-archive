# 0140. Word Break II《單字拆分 II》

- **Difficulty**: Hard
- **Tags**: array, hash-table, string, dynamic-programming, backtracking, trie, memoization
- **題目連結**: https://leetcode.com/problems/word-break-ii/
- **程式碼**: [`140_word-break-ii.c`](./140_word-break-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與字典 wordDict，請在 s 中加入空格，形成每個單字都存在於字典中的所有可能句子，順序不限。切分時同一個字典單字可以重複使用。若無合法切分則回傳空陣列。s 長度至多 20，字典最多 1000 個不重複的小寫單字，每個單字長度至多 10，且答案總長度不超過 10^5。

**思路**：先以 DP 從每個可到達切點記錄可接上的下一個切點，再沿這些切點回溯，逐段加入單字並組出所有句子。

## Problem Statement (English)

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

## 限制 Constraints

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    
}
```
