# 0816. Ambiguous Coordinates《模糊座標》

- **Difficulty**: Medium
- **Tags**: string, backtracking, enumeration
- **題目連結**: https://leetcode.com/problems/ambiguous-coordinates/
- **程式碼**: [`816_ambiguous-coordinates.c`](./816_ambiguous-coordinates.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

原本的二維座標移除了逗號、小數點與空白後得到字串 s，需列出所有可能的原座標表示。數字不得有多餘前導或尾隨 0，且小數點前至少要有一位數字；每個輸出座標的逗號後必須恰有一個空白。

**思路**：枚舉數字字串的每個切分點作為 x、y，再遞迴嘗試各段合法的整數或小數插點，並將兩側組合成座標。

## Problem Statement (English)

We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas, decimal points, and spaces and ended up with the string s.
Return a list of strings representing all possibilities for what our original coordinates could have been.
Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like ".1".
The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "(123)"
Output: ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]

Input: s = "(0123)"
Output: ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
Explanation: 0.0, 00, 0001 or 00.01 are not allowed.

Input: s = "(00011)"
Output: ["(0, 0.011)","(0.001, 1)"]
```

## 限制 Constraints

4 <= s.length <= 12
s[0] == '(' and s[s.length - 1] == ')'.
The rest of s are digits.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** ambiguousCoordinates(char* s, int* returnSize) {
    
}
```
