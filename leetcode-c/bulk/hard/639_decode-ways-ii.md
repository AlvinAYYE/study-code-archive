# 0639. Decode Ways II《解碼方法 II》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/decode-ways-ii/
- **程式碼**: [`639_decode-ways-ii.c`](./639_decode-ways-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

字母 A 到 Z 分別可由 1 到 26 編碼，給定只含數字與 '*' 的編碼字串，計算所有合法解碼方式。'*' 可代表 1 到 9 的任一數字，而前導 0 的編碼無效。答案可能很大，需對 10^9 + 7 取模。

**思路**：以常數空間的滾動動態規劃保存前兩個位置的解碼數。對目前字元分別處理 0、* 與一般數字，並依前一字元決定可形成的一位或兩位編碼數量。

## Problem Statement (English)

A message containing letters from A-Z can be encoded into numbers using the following mapping:
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.
Given a string s consisting of digits and '*' characters, return the number of ways to decode it.
Since the answer may be very large, return it modulo 109 + 7.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".

Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".

Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is a digit or '*'.

## 官方 C 函式簽名 Signature

```c
int numDecodings(char* s) {
    
}
```
