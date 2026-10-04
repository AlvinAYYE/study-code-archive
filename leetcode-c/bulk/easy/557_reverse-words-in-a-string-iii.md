# 0557. Reverse Words in a String III《反轉字串中的單字 III》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/reverse-words-in-a-string-iii/
- **程式碼**: [`557_reverse-words-in-a-string-iii.c`](./557_reverse-words-in-a-string-iii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一句字串，反轉每個單字內的字元順序，同時保留原本的單字順序與空白位置。輸入沒有頭尾空白，且單字之間恰有一個空白。

**思路**：程式逐字元讀取每個單字，將字元由後往前寫入緩衝區，再拷回原字串，並在單字間保留空白。

## Problem Statement (English)

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Input: s = "Mr Ding"
Output: "rM gniD"
```

## 限制 Constraints

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

## 官方 C 函式簽名 Signature

```c
char* reverseWords(char* s) {
    
}
```
