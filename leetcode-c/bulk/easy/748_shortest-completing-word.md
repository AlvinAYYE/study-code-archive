# 0748. Shortest Completing Word《最短補全單詞》

- **Difficulty**: Easy
- **Tags**: array, hash-table, string
- **題目連結**: https://leetcode.com/problems/shortest-completing-word/
- **程式碼**: [`748_shortest-completing-word.c`](./748_shortest-completing-word.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定車牌字串 licensePlate 與單詞陣列 words，找出包含車牌所有字母的最短補全單詞；車牌中的數字與空白忽略，字母不分大小寫且重複次數必須滿足。若最短答案有多個，回傳 words 中最先出現者，且保證存在答案。

**思路**：先統計車牌所需的 26 個字母次數，再逐一掃描單詞，用暫存計數扣除已匹配的字母。程式優先保留匹配需求最多且長度較短的候選；因答案保證存在，最終即為最短完整補全詞。

## Problem Statement (English)

Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".
Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
"step" contains 't' and 'p', but only contains 1 's'.
"steps" contains 't', 'p', and both 's' characters.
"stripe" is missing an 's'.
"stepple" is missing an 's'.
Since "steps" is the only word containing all the letters, that is the answer.

Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
Output: "pest"
Explanation: licensePlate only contains the letter 's'. All the words contain 's', but among these "pest", "stew", and "show" are shortest. The answer is "pest" because it is the word that appears earliest of the 3.
```

## 限制 Constraints

1 <= licensePlate.length <= 7
licensePlate contains digits, letters (uppercase or lowercase), or space ' '.
1 <= words.length <= 1000
1 <= words[i].length <= 15
words[i] consists of lower case English letters.

## 官方 C 函式簽名 Signature

```c
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    
}
```
