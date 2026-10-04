# 0336. Palindrome Pairs《回文配對》

- **Difficulty**: Hard
- **Tags**: array, hash-table, string, trie
- **題目連結**: https://leetcode.com/problems/palindrome-pairs/
- **程式碼**: [`336_palindrome-pairs.c`](./336_palindrome-pairs.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由互不相同字串組成的陣列 words，找出所有索引對 (i, j)，使 i 不等於 j 且 words[i] + words[j] 為回文。回傳所有這類索引對，並須處理空字串情況。

**思路**：把所有非空單字存入 Trie，針對每個單字查找其反轉字串。再枚舉切分點，若其中一側是回文便到 Trie 查找另一側的反轉字串，同時特別處理空字串與完整回文。

## Problem Statement (English)

You are given a 0-indexed array of unique strings words.
A palindrome pair is a pair of integers (i, j) such that:
Return an array of all the palindrome pairs of words.
You must write an algorithm with O(sum of words[i].length) runtime complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
```

## 限制 Constraints

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** palindromePairs(char** words, int wordsSize, int* returnSize, int** returnColumnSizes) {
    
}
```
