# 0893. Groups of Special-Equivalent Strings《特殊等價字串群組》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, sorting
- **題目連結**: https://leetcode.com/problems/groups-of-special-equivalent-strings/
- **程式碼**: [`893_groups-of-special-equivalent-strings.c`](./893_groups-of-special-equivalent-strings.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一組等長字串，每次可交換同一字串中任兩個偶數索引字元，或任兩個奇數索引字元。經任意次操作可互相轉換的字串屬於同一特殊等價群組，回傳群組數量。

**思路**：程式將每個字串的奇數索引字元與偶數索引字元分開排序，再串接成標準化簽名。以表格儲存不同簽名並計數，即可得到群組數。

## Problem Statement (English)

You are given an array of strings of the same length words.
In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].
Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j].
A group of special-equivalent strings from words is a non-empty subset of words such that:
Return the number of groups of special-equivalent strings from words.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
Output: 3
Explanation: 
One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings is all pairwise special equivalent to these.
The other two groups are ["xyzz", "zzxy"] and ["zzyx"].
Note that in particular, "zzxy" is not special equivalent to "zzyx".

Input: words = ["abc","acb","bac","bca","cab","cba"]
Output: 3
```

## 限制 Constraints

1 <= words.length <= 1000
1 <= words[i].length <= 20
words[i] consist of lowercase English letters.
All the strings are of the same length.

## 官方 C 函式簽名 Signature

```c
int numSpecialEquivGroups(char** words, int wordsSize) {
    
}
```
