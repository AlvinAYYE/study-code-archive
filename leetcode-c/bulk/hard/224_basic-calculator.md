# 0224. Basic Calculator《基本計算機》

- **Difficulty**: Hard
- **Tags**: math, string, stack, recursion
- **題目連結**: https://leetcode.com/problems/basic-calculator/
- **程式碼**: [`224_basic-calculator.c`](./224_basic-calculator.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定合法運算式字串 s，計算只含整數、加減、括號與空白的結果。不可使用 eval 等內建字串運算功能；加號不可作一元運算，減號可以，結果保證在 32 位元有號整數範圍內。

**思路**：剖析字串後分別以動態堆疊保存運算元與運算子，並依優先序在適當時機歸約。左括號直接入堆疊，右括號會結算至對應左括號為止。

## Problem Statement (English)

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "1 + 1"
Output: 2

Input: s = " 2-1 + 2 "
Output: 3

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

## 限制 Constraints

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int calculate(char* s) {
    
}
```
