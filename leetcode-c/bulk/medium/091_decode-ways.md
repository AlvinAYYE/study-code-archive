# 0091. Decode Ways《解碼方法》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/decode-ways/
- **程式碼**: [`091_decode-ways.c`](./091_decode-ways.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

數字字串可依 1 對應 A、2 對應 B，一直到 26 對應 Z 的規則解碼。給定只含數字的字串，求所有有效完整解碼方式的數量；若無法有效解碼則回傳 0。前導 0 不可單獨解碼，且答案保證在 32 位元整數範圍內。

**思路**：以三個變數滾動保存前綴 DP 值：目前字元可單獨解碼時承接前一值，與前字元能組成 10 到 26 時再加上前兩步的值。遇到 0 則必須由前一個 1 或 2 配對，否則立即失敗。

## Problem Statement (English)

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'
However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
For example, "11106" can be decoded into:
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
The test cases are generated so that the answer fits in a 32-bit integer.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "12"
Output: 2
Explanation:
"12" could be decoded as "AB" (1 2) or "L" (12).

Input: s = "226"
Output: 3
Explanation:
"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Input: s = "06"
Output: 0
Explanation:
"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.
```

## 限制 Constraints

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

## 官方 C 函式簽名 Signature

```c
int numDecodings(char* s) {
    
}
```
