# 0017. Letter Combinations of a Phone Number《電話號碼的字母組合》

- **Difficulty**: Medium
- **Tags**: hash-table, string, backtracking
- **題目連結**: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
- **程式碼**: [`017_letter-combinations-of-a-phone-number.c`](./017_letter-combinations-of-a-phone-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定只含 2 到 9 的數字字串，回傳電話按鍵對應的所有可能字母組合，順序不限。數字 1 不對應任何字母；空字串的結果為空集合。

**思路**：程式先依各按鍵可選字母數計算結果容量，再以深度優先搜尋逐位填入緩衝字串。遞迴走到輸入結尾時複製目前組合加入答案。

## Problem Statement (English)

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits = ""
Output: []

Input: digits = "2"
Output: ["a","b","c"]
```

## 限制 Constraints

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    
}
```
