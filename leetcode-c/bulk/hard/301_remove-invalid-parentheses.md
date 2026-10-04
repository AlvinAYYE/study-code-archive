# 0301. Remove Invalid Parentheses《移除無效括號》

- **Difficulty**: Hard
- **Tags**: string, backtracking, breadth-first-search
- **題目連結**: https://leetcode.com/problems/remove-invalid-parentheses/
- **程式碼**: [`301_remove-invalid-parentheses.c`](./301_remove-invalid-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定含有小寫字母與圓括號的字串 s，請移除最少數量的無效括號，使字串成為有效括號字串。回傳所有不重複且移除數最少的有效結果，順序不限。

**思路**：遞迴掃描括號平衡，首次出現多餘右括號時，嘗試刪除該段中每個可作為第一個的右括號以避免重複。正向處理完後反轉字串，再以同樣方式移除多餘左括號。

## Problem Statement (English)

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "()())()"
Output: ["(())()","()()()"]

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Input: s = ")("
Output: [""]
```

## 限制 Constraints

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeInvalidParentheses(char* s, int* returnSize) {
    
}
```
