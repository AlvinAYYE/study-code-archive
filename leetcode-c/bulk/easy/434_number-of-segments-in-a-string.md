# 0434. Number of Segments in a String《字串中的單詞數》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/number-of-segments-in-a-string/
- **程式碼**: [`434_number-of-segments-in-a-string.c`](./434_number-of-segments-in-a-string.c) — 社群解答（repo BlackDragonF_LeetcodeSolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s，回傳其中片段的數量。片段定義為一段連續的非空白字元；題目中的唯一空白字元為一般空格。

**思路**：以兩種狀態記錄目前是在片段內或片段之間。每當從空白或開頭進入非空白字元時，就將答案加一。

## Problem Statement (English)

Given a string s, return the number of segments in the string.
A segment is defined to be a contiguous sequence of non-space characters.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Input: s = "Hello"
Output: 1
```

## 限制 Constraints

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.

## 官方 C 函式簽名 Signature

```c
int countSegments(char* s) {
    
}
```
