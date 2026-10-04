# 0227. Basic Calculator II《基本計算機 II》

- **Difficulty**: Medium
- **Tags**: math, string, stack
- **題目連結**: https://leetcode.com/problems/basic-calculator-ii/
- **程式碼**: [`227_basic-calculator-ii.c`](./227_basic-calculator-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

計算合法字串運算式的值，式中含非負整數、加減乘除與空白。整數除法須朝零截斷，且不得使用 eval 等內建字串運算功能。

**思路**：將數字與運算子分別推入兩個堆疊，遇到同等或較低優先序的運算子時先結算。乘除優先於加減，掃描結束時透過結尾哨兵完成所有歸約。

## Problem Statement (English)

Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "3+2*2"
Output: 7

Input: s = " 3/2 "
Output: 1

Input: s = " 3+5 / 2 "
Output: 5
```

## 限制 Constraints

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int calculate(char* s) {
    
}
```
