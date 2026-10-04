# 0402. Remove K Digits《移掉 K 位數字》

- **Difficulty**: Medium
- **Tags**: string, stack, greedy, monotonic-stack
- **題目連結**: https://leetcode.com/problems/remove-k-digits/
- **程式碼**: [`402_remove-k-digits.c`](./402_remove-k-digits.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定表示非負整數的字串 num 與整數 k，移除恰好 k 個數字後回傳可得到的最小整數。輸入除數值 0 外沒有前導零，結果也不得保留前導零；若全數移除則回傳 0。

**思路**：每次尋找第一個大於下一位的數字並刪除，若一路非遞減就刪除最後一位；重複 k 次後移除剩餘前導零。

## Problem Statement (English)

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

## 限制 Constraints

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

## 官方 C 函式簽名 Signature

```c
char* removeKdigits(char* num, int k) {
    
}
```
