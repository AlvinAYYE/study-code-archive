# 0020. Valid Parentheses《有效的括號》

- **Difficulty**: Easy
- **Tags**: string, stack
- **題目連結**: https://leetcode.com/problems/valid-parentheses/
- **程式碼**: [`020_valid-parentheses.c`](./020_valid-parentheses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含 ()[]{} 的字串，判斷其括號是否有效。有效字串要求每個左括號都由相同類型的右括號依正確順序閉合。

**思路**：程式使用字元堆疊儲存左括號。遇到右括號時檢查堆疊頂端是否為對應類型，最後僅在堆疊清空時回傳 true。

## Problem Statement (English)

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Example 1:
Example 2:
Example 3:
Example 4:
Example 5:
Constraints:

## 範例 Examples

```text
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([])"
Output: true
```

## 限制 Constraints

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

## 官方 C 函式簽名 Signature

```c
bool isValid(char* s) {
    
}
```
