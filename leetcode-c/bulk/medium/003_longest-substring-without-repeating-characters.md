# 0003. Longest Substring Without Repeating Characters《无重复字符的最长子串》

- **Difficulty**: Medium
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/longest-substring-without-repeating-characters/
- **程式碼**: [`003_longest-substring-without-repeating-characters.c`](./003_longest-substring-without-repeating-characters.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，求其中不含重複字元的最長連續子字串長度。子字串必須連續，不能以跳過字元的子序列取代。

**思路**：程式用長度 128 的陣列記錄每個字元最近一次出現位置，掃描時據此縮短目前視窗長度。每一步更新目前無重複區間與全域最大長度。

## Problem Statement (English)

Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## 限制 Constraints

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

## 官方 C 函式簽名 Signature

```c
int lengthOfLongestSubstring(char* s) {
    
}
```
