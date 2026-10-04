# 0187. Repeated DNA Sequences《重複的 DNA 序列》

- **Difficulty**: Medium
- **Tags**: hash-table, string, bit-manipulation, sliding-window, rolling-hash, hash-function
- **題目連結**: https://leetcode.com/problems/repeated-dna-sequences/
- **程式碼**: [`187_repeated-dna-sequences.c`](./187_repeated-dna-sequences.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

DNA 字串只由 A、C、G、T 組成。請找出其中所有長度恰為 10、且在該 DNA 序列中出現超過一次的子字串，回傳順序不限。字串長度最多為 10^5。

**思路**：將四種鹼基映射為 2 位元，為每個長度 10 的視窗編成整數碼並放入雜湊桶；第二次出現時輸出一次，並以旗標避免重複加入。

## Problem Statement (English)

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    
}
```
