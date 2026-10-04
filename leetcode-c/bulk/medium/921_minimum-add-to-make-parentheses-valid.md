# 0921. Minimum Add to Make Parentheses Valid《使括號字串有效的最少新增次數》

- **Difficulty**: Medium
- **Tags**: string, stack, greedy
- **題目連結**: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
- **程式碼**: [`921_minimum-add-to-make-parentheses-valid.c`](./921_minimum-add-to-make-parentheses-valid.c) — 社群解答（repo caotrongphuoc_algorithms），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有效括號字串可以是空字串、兩個有效字串的串接，或由一對括號包住的有效字串。給定只含左右括號的字串 s，每次可在任意位置插入一個括號。請回傳使 s 成為有效括號字串所需的最少插入次數。

**思路**：掃描字串並計算尚未配對的左括號；遇到無法配對的右括號便計入必須補上的左括號，最後加上剩餘左括號數量。

## Problem Statement (English)

A parentheses string is valid if and only if:
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
Return the minimum number of moves required to make s valid.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "())"
Output: 1

Input: s = "((("
Output: 3
```

## 限制 Constraints

1 <= s.length <= 1000
s[i] is either '(' or ')'.

## 官方 C 函式簽名 Signature

```c
int minAddToMakeValid(char* s) {
    
}
```
