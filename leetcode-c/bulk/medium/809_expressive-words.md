# 0809. Expressive Words《彈性字串》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, string
- **題目連結**: https://leetcode.com/problems/expressive-words/
- **程式碼**: [`809_expressive-words.c`](./809_expressive-words.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定目標字串 s 與查詢陣列 words；一個字元連續群組只有在擴充後長度至少為 3 時，才可加入同字元使查詢字串變成 s。回傳可經任意次此類擴充而變為 s 的查詢字串數量；字串皆為小寫英文字母且長度最多為 100。

**思路**：逐群組掃描 s，對仍候選的每個 word 消耗同字元群組；群組字元不同、word 群組太長，或 s 群組不足 3 卻長度不同時淘汰該候選。

## Problem Statement (English)

Sometimes people repeat letters to represent extra feeling. For example:
In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".
You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.
Return the number of query strings that are stretchy.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.

Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3
```

## 限制 Constraints

1 <= s.length, words.length <= 100
1 <= words[i].length <= 100
s and words[i] consist of lowercase letters.

## 官方 C 函式簽名 Signature

```c
int expressiveWords(char* s, char** words, int wordsSize) {
    
}
```
