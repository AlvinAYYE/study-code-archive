# 0032. Longest Valid Parentheses《最長有效括號》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming, stack
- **題目連結**: https://leetcode.com/problems/longest-valid-parentheses/
- **程式碼**: [`032_longest-valid-parentheses.c`](./032_longest-valid-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個只包含 `(` 與 `)` 的字串 `s`，請回傳最長「格式正確」的連續括號子字串長度。空字串的答案為 0。

## 解題思路

1. 配置 `v[]`，標記哪些位置能屬於一段有效括號。
2. 由左往右掃描，以計數器記錄尚未配對的左括號；沒有左括號可配的 `)` 標為 0，其餘位置先標為 1。
3. 再由右往左掃描，以計數器記錄尚未配對的右括號；沒有右括號可配的 `(` 也標為 0。
4. 兩次掃描後，所有無法配對的括號都成為分隔點。最後累積連續的 1，途中更新最大長度。

演算法共做三次線性掃描，時間複雜度為 `O(n)`，額外空間為 `O(n)`。

## Problem Statement (English)

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：s = "(()"
輸出：2
說明：最長有效括號子字串是 "()"。

輸入：s = ")()())"
輸出：4
說明：最長有效括號子字串是 "()()"。

輸入：s = ""
輸出：0
```

## 限制

- `0 <= s.length <= 3 * 10^4`
- `s[i]` 只會是 `(` 或 `)`。

## 官方 C 函式簽名 Signature

```c
int longestValidParentheses(char* s) {
    
}
```
