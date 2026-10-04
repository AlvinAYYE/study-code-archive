# 0394. Decode String《字串解碼》

- **Difficulty**: Medium
- **Tags**: string, stack, recursion
- **題目連結**: https://leetcode.com/problems/decode-string/
- **程式碼**: [`394_decode-string.c`](./394_decode-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定編碼字串，依 k[encoded_string] 規則將中括號內容重複 k 次並回傳解碼結果。輸入保證有效、沒有額外空白、數字只用於重複次數，且解碼結果長度不超過 10^5。

**思路**：以堆疊保存每層括號前的字串與重複次數，讀到右括號時彈出一層，將目前內容重複後接回前綴字串。

## Problem Statement (English)

Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Input: s = "3[a2[c]]"
Output: "accaccacc"

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

## 限制 Constraints

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

## 官方 C 函式簽名 Signature

```c
char* decodeString(char* s) {
    
}
```
