# 0014. Longest Common Prefix《最長共同前綴》

- **Difficulty**: Easy
- **Tags**: array, string, trie
- **題目連結**: https://leetcode.com/problems/longest-common-prefix/
- **程式碼**: [`014_longest-common-prefix.c`](./014_longest-common-prefix.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一組字串，找出它們共同擁有的最長前綴字串。若不存在共同前綴，應回傳空字串。

**思路**：程式逐一檢查第一個字串的每個字元是否在所有其他字串的同一位置相同。一旦不相同，便在第一個字串該處寫入結束字元並將其作為答案回傳。

## Problem Statement (English)

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

## 限制 Constraints

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

## 官方 C 函式簽名 Signature

```c
char* longestCommonPrefix(char** strs, int strsSize) {
    
}
```
