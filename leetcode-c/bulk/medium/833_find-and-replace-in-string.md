# 0833. Find And Replace in String《字串中的查找與替換》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, sorting
- **題目連結**: https://leetcode.com/problems/find-and-replace-in-string/
- **程式碼**: [`833_find-and-replace-in-string.c`](./833_find-and-replace-in-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，以及長度相同的 indices、sources、targets 三個平行陣列，需執行多個替換操作。若 sources[i] 恰好從 s 的 indices[i] 開始出現，便以 targets[i] 替換；所有替換必須同時進行，且測資保證替換區間不重疊。回傳替換後的字串。

**思路**：程式先依起始索引排序所有操作，再由左至右掃描原字串並建立結果緩衝區。每個索引處以字首比對確認 source 是否相符，只有相符時才附加 target 並跳過原片段。

## Problem Statement (English)

You are given a 0-indexed string s that you must perform k replacement operations on. The replacement operations are given as three 0-indexed parallel arrays, indices, sources, and targets, all of length k.
To complete the ith replacement operation:
For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and targets[i] = "eee", then the result of this replacement will be "eeecd".
All replacement operations must occur simultaneously, meaning the replacement operations should not affect the indexing of each other. The testcases will be generated such that the replacements will not overlap.
Return the resulting string after performing all replacement operations on s.
A substring is a contiguous sequence of characters in a string.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
Output: "eeebffff"
Explanation:
"a" occurs at index 0 in s, so we replace it with "eee".
"cd" occurs at index 2 in s, so we replace it with "ffff".

Input: s = "abcd", indices = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation:
"ab" occurs at index 0 in s, so we replace it with "eee".
"ec" does not occur at index 2 in s, so we do nothing.
```

## 限制 Constraints

1 <= s.length <= 1000
k == indices.length == sources.length == targets.length
1 <= k <= 100
0 <= indexes[i] < s.length
1 <= sources[i].length, targets[i].length <= 50
s consists of only lowercase English letters.
sources[i] and targets[i] consist of only lowercase English letters.

## 官方 C 函式簽名 Signature

```c
char* findReplaceString(char* s, int* indices, int indicesSize, char** sources, int sourcesSize, char** targets, int targetsSize) {
    
}
```
