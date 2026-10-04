# 0072. Edit Distance《編輯距離》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/edit-distance/
- **程式碼**: [`072_edit-distance.c`](./072_edit-distance.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個小寫字串 word1 與 word2，求把 word1 轉換成 word2 所需的最少操作次數。每次可插入、刪除或替換一個字元。兩字串長度都可為 0，且至多為 500。

**思路**：建立二維 DP 表，列與欄分別表示兩字串前綴的最小編輯距離。字元相同時沿用左上值，否則取插入、刪除、替換三種前一狀態的最小值加一。

## Problem Statement (English)

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

## 限制 Constraints

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int minDistance(char* word1, char* word2) {
    
}
```
