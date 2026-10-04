# 0583. Delete Operation for Two Strings《兩個字串的刪除操作》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/delete-operation-for-two-strings/
- **程式碼**: [`583_delete-operation-for-two-strings.c`](./583_delete-operation-for-two-strings.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個小寫字串 word1 與 word2，每次可從其中任一字串刪除一個字元。請回傳讓兩字串變成相同所需的最少刪除步數。

**思路**：先用二維動態規劃求兩字串的最長共同子序列長度，再以兩字串總長減去該長度的兩倍得到最少刪除數。

## Problem Statement (English)

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

## 限制 Constraints

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int minDistance(char* word1, char* word2) {
    
}
```
