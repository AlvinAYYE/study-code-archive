# 0030. Substring with Concatenation of All Words《串聯所有單字的子字串》

- **Difficulty**: Hard
- **Tags**: hash-table, string, sliding-window
- **題目連結**: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
- **程式碼**: [`030_substring-with-concatenation-of-all-words.c`](./030_substring-with-concatenation-of-all-words.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與單字陣列 words，其中所有單字長度相同；串聯字串必須恰好包含 words 的所有單字各一次、順序任意且中間沒有其他字元。回傳 s 中所有符合此條件之子字串的起始索引，順序不限。

**思路**：程式建立單字雜湊表，記錄每個相異單字的需求次數與目前視窗次數，並以單字長度逐段掃描。遇到過量單字便從左端移出單字，集滿所有單字時記錄起點並重設下一次搜尋位置。

## Problem Statement (English)

You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo" . It is the concatenation of ["bar","foo"] which is a permutation of words . The substring starting at 9 is "foobar" . It is the concatenation of ["foo","bar"] which is a permutation of words .

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:
The substring starting at 6 is "foobarthe" . It is the concatenation of ["foo","bar","the"] . The substring starting at 9 is "barthefoo" . It is the concatenation of ["bar","the","foo"] . The substring starting at 12 is "thefoobar" . It is the concatenation of ["the","foo","bar"] .
```

## 限制 Constraints

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
}
```
