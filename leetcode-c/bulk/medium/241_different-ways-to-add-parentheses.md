# 0241. Different Ways to Add Parentheses《為運算式設計優先序》

- **Difficulty**: Medium
- **Tags**: math, string, dynamic-programming, recursion, memoization
- **題目連結**: https://leetcode.com/problems/different-ways-to-add-parentheses/
- **程式碼**: [`241_different-ways-to-add-parentheses.c`](./241_different-ways-to-add-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定僅含數字與 +、-、* 的運算式字串，列出以所有不同括號分組方式計算所能得到的結果。結果順序不限，且測資保證結果值在 32 位元整數範圍內、可能結果數不超過 10^4。

**思路**：遞迴把每一個運算子當作最後一步，分別求左右子字串的所有結果。將左右結果兩兩套用該運算子並累積。

## Problem Statement (English)

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
```

## 限制 Constraints

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char* expression, int* returnSize) {
    
}
```
