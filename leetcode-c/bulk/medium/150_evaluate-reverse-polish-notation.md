# 0150. Evaluate Reverse Polish Notation《逆波蘭表示法求值》

- **Difficulty**: Medium
- **Tags**: array, math, stack
- **題目連結**: https://leetcode.com/problems/evaluate-reverse-polish-notation/
- **程式碼**: [`150_evaluate-reverse-polish-notation.c`](./150_evaluate-reverse-polish-notation.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串陣列 tokens，代表一個逆波蘭表示法的算術運算式，請計算並回傳其整數值。token 可能是整數或 +、-、*、/ 四種運算子；整數除法須朝 0 截斷。輸入運算式保證有效且不會除以 0。tokens 長度介於 1 至 10^4，整數 token 介於 -200 至 200。

**思路**：掃描 token 並用堆疊保存運算元；遇到運算子時依序彈出右、左兩數計算，再將結果推回堆疊。

## Problem Statement (English)

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

## 限制 Constraints

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

## 官方 C 函式簽名 Signature

```c
int evalRPN(char** tokens, int tokensSize) {
    
}
```
