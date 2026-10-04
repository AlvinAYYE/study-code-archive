# 0541. Reverse String II《反轉字串 II》

- **Difficulty**: Easy
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/reverse-string-ii/
- **程式碼**: [`541_reverse-string-ii.c`](./541_reverse-string-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與整數 k，從開頭起每 2k 個字元為一組，反轉每組前 k 個字元。尾端不足 k 個字元時全部反轉；尾端不少於 k 但少於 2k 時，只反轉前 k 個字元。

**思路**：程式以 2k 為步長，利用雙指標交換每一段開頭的 k 個字元；迴圈結束後若有尾段，便將該尾段反轉至字串末端。

## Problem Statement (English)

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Input: s = "abcd", k = 2
Output: "bacd"
```

## 限制 Constraints

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104

## 官方 C 函式簽名 Signature

```c
char* reverseStr(char* s, int k) {
    
}
```
