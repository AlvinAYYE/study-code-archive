# 0282. Expression Add Operators《為運算式加上運算子》

- **Difficulty**: Hard
- **Tags**: math, string, backtracking
- **題目連結**: https://leetcode.com/problems/expression-add-operators/
- **程式碼**: [`282_expression-add-operators.c`](./282_expression-add-operators.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定僅含數字的字串 num 與整數 target，請在相鄰數字間插入 +、- 或 *，列出所有計算值等於 target 的運算式。運算元可由多個數字組成，但不得有前導零（單一 0 除外）。答案的排列順序不限。

**思路**：以回溯枚舉下一個運算元和三種運算子，遞迴保留目前總值與最後一項。遇到乘法時用「總值減去最後一項再加上乘積」修正運算優先序，並略過前導零與溢位的數字。

## Problem Statement (English)

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
Note that operands in the returned expressions should not contain leading zeros.
Note that a number can contain multiple digits.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```

## 限制 Constraints

1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** addOperators(char* num, int target, int* returnSize) {
    
}
```
