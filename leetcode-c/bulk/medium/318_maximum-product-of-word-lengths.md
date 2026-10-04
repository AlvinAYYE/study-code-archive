# 0318. Maximum Product of Word Lengths《最大單字長度乘積》

- **Difficulty**: Medium
- **Tags**: array, string, bit-manipulation
- **題目連結**: https://leetcode.com/problems/maximum-product-of-word-lengths/
- **程式碼**: [`318_maximum-product-of-word-lengths.c`](./318_maximum-product-of-word-lengths.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串陣列 words，請在兩個沒有任何共同字母的單字中，找出長度乘積的最大值。若不存在符合條件的單字對，回傳 0。

**思路**：把每個單字的出現字母壓成 26 位元遮罩，並記錄單字長度。逐對檢查兩遮罩的 AND 是否為 0，符合時更新長度乘積最大值。

## Problem Statement (English)

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
```

## 限制 Constraints

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int maxProduct(char** words, int wordsSize) {
    
}
```
