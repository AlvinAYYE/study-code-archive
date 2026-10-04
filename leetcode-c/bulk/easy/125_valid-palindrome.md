# 0125. Valid Palindrome《驗證回文串》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/valid-palindrome/
- **程式碼**: [`125_valid-palindrome.c`](./125_valid-palindrome.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

若將字串中的大寫字母轉成小寫、移除所有非英數字元後，正讀與反讀相同，則該字串是回文。給定字串 s，請判斷它是否為回文並回傳 true 或 false。s 的長度介於 1 至 2×10^5，且只包含可列印 ASCII 字元。

**思路**：以左右雙指針向中間掃描，跳過非英數字元，將英文字母統一大小寫後比較；任一對不同即可回傳 false。

## Problem Statement (English)

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

## 限制 Constraints

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

## 官方 C 函式簽名 Signature

```c
bool isPalindrome(char* s) {
    
}
```
