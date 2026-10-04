# 0438. Find All Anagrams in a String《找到字串中所有字母異位詞》

- **Difficulty**: Medium
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/find-all-anagrams-in-a-string/
- **程式碼**: [`438_find-all-anagrams-in-a-string.c`](./438_find-all-anagrams-in-a-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定小寫字串 s 與 p，回傳 s 中所有為 p 字母異位詞的子字串起始索引，順序不限。兩字串皆只含小寫英文字母。

**思路**：以字母計數與滑動視窗維護尚未配對的 p 字元總數。加入字元後若某字元超量便從左縮窗，當未配對數為 0 時記錄起點並移出左端一字元繼續搜尋。

## Problem Statement (English)

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

## 限制 Constraints

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    
}
```
