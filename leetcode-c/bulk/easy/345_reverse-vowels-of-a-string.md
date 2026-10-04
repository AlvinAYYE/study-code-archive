# 0345. Reverse Vowels of a String《反轉字串中的母音字母》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/reverse-vowels-of-a-string/
- **程式碼**: [`345_reverse-vowels-of-a-string.c`](./345_reverse-vowels-of-a-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，只反轉其中所有母音字母後回傳。母音為 a、e、i、o、u，且可能以大小寫形式重複出現。

**思路**：使用左右雙指標向中間掃描，兩端都是母音時交換，否則移動尚未指到母音的一端。

## Problem Statement (English)

Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A'] . On reversing the vowels, s becomes "AceCreIm" .

Input: s = "leetcode"
Output: "leotcede"
```

## 限制 Constraints

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

## 官方 C 函式簽名 Signature

```c
char* reverseVowels(char* s) {
    
}
```
