# 0804. Unique Morse Code Words《獨特的摩斯密碼詞》

- **Difficulty**: Easy
- **Tags**: array, hash-table, string
- **題目連結**: https://leetcode.com/problems/unique-morse-code-words/
- **程式碼**: [`804_unique-morse-code-words.c`](./804_unique-morse-code-words.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將 words 中每個小寫英文單字依國際摩斯碼逐字串接，形成其轉換結果。回傳所有轉換結果中不同字串的數量；單字數最多為 100，單字長度最多為 12。

**思路**：以字母對應表組合每個單字的摩斯碼，並將完整字串存入自製雜湊集合，集合大小即為答案。

## Problem Statement (English)

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:
For convenience, the full table for the 26 letters of the English alphabet is given below:
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
Return the number of different transformations among all words we have.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

Input: words = ["a"]
Output: 1
```

## 限制 Constraints

1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
int uniqueMorseRepresentations(char** words, int wordsSize) {
    
}
```
