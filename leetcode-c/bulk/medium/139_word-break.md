# 0139. Word Break《單字拆分》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, dynamic-programming, trie, memoization
- **題目連結**: https://leetcode.com/problems/word-break/
- **程式碼**: [`139_word-break.c`](./139_word-break.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與字典 wordDict，判斷 s 能否被切分為一個或多個字典單字並以空格分隔的序列。切分時同一個字典單字可以重複使用。可行時回傳 true，否則回傳 false。s 長度至多 300，字典最多 1000 個不重複的小寫單字，且每個單字長度至多 20。

**思路**：以布林 DP 記錄各前綴能否切分，對每個結尾位置倒查可能起點，若前一前綴可行且目前片段在字典中便標記可行。

## Problem Statement (English)

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

## 限制 Constraints

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

## 官方 C 函式簽名 Signature

```c
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    
}
```
