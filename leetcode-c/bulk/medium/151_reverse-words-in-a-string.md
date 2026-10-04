# 0151. Reverse Words in a String《反轉字串中的單字》

- **Difficulty**: Medium
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/reverse-words-in-a-string/
- **程式碼**: [`151_reverse-words-in-a-string.c`](./151_reverse-words-in-a-string.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，請反轉其中單字的順序；單字是由非空白字元組成的連續序列。輸入可能有前後空白或多個連續空白，輸出單字間必須恰好一個空白，且不可有多餘前後空白。題目進一步詢問在可變字串型別下能否原地使用 O(1) 額外空間完成。s 長度至多 10^4，至少含一個單字，且只含英文字母、數字與空白。

**思路**：先複製原字串並把每個單字的起訖位置推入堆疊，再依彈出順序寫回原字串，於單字間插入一個空白。

## Problem Statement (English)

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
Example 1:
Example 2:
Example 3:
Constraints:
Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

## 範例 Examples

```text
Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

## 限制 Constraints

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

## 官方 C 函式簽名 Signature

```c
char* reverseWords(char* s) {
    
}
```
