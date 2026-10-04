# 0022. Generate Parentheses《括號生成》

- **Difficulty**: Medium
- **Tags**: string, dynamic-programming, backtracking
- **題目連結**: https://leetcode.com/problems/generate-parentheses/
- **程式碼**: [`022_generate-parentheses.c`](./022_generate-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n 對括號，產生所有格式正確的括號組合。n 的範圍為 1 到 8。

**思路**：啟用的程式以動態規劃建立各對數的答案，利用 f(n) = '(' + f(j) + ')' + f(n-j-1) 的分解來組合結果。每個新組合都配置並複製到對應的答案集合。

## Problem Statement (English)

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Input: n = 1
Output: ["()"]
```

## 限制 Constraints

1 <= n <= 8

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    
}
```
