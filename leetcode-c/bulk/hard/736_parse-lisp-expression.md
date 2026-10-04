# 0736. Parse Lisp Expression《解析 Lisp 表達式》

- **Difficulty**: Hard
- **Tags**: hash-table, string, stack, recursion
- **題目連結**: https://leetcode.com/problems/parse-lisp-expression/
- **程式碼**: [`736_parse-lisp-expression.c`](./736_parse-lisp-expression.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定合法的 Lisp 風格字串表達式，計算其整數結果；表達式可為整數、變數、add、mult 或 let。let 的賦值依序執行，變數查找採由內而外的作用域規則，而 add 與 mult 各對兩個子表達式做加法或乘法。

**思路**：遞迴剖析括號、運算子、整數與識別字，並以符號鏈結串列保存變數綁定。每層 let 以深度標記其新綁定，完成該層後移除，變數解析時自然優先取得最內層值。

## Problem Statement (English)

You are given a string expression representing a Lisp-like expression to return the integer value of.
The syntax for these expressions is given as follows.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
Output: 14
Explanation: In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.

Input: expression = "(let x 3 x 2 x)"
Output: 2
Explanation: Assignment in let statements is processed sequentially.

Input: expression = "(let x 1 y 2 x (add x y) (add x y))"
Output: 5
Explanation: The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.
```

## 限制 Constraints

1 <= expression.length <= 2000
There are no leading or trailing spaces in expression.
All tokens are separated by a single space in expression.
The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.
The expression is guaranteed to be legal and evaluate to an integer.

## 官方 C 函式簽名 Signature

```c
int evaluate(char* expression) {
    
}
```
