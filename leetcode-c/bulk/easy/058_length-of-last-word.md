# 0058. Length of Last Word《最後一個單字的長度》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/length-of-last-word/
- **程式碼**: [`058_length-of-last-word.c`](./058_length-of-last-word.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定由英文單字與空格組成、且至少含一個單字的字串 s，回傳最後一個單字的長度。單字定義為由非空白字元組成的最長連續子字串。

**思路**：從字串尾端向前掃描，先略過尾端空格，再計算連續非空格字元數。遇到空格且已開始計數時即停止。

## Problem Statement (English)

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

## 限制 Constraints

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

## 官方 C 函式簽名 Signature

```c
int lengthOfLastWord(char* s) {
    
}
```
