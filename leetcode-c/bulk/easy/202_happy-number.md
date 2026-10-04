# 0202. Happy Number《快樂數》

- **Difficulty**: Easy
- **Tags**: hash-table, math, two-pointers
- **題目連結**: https://leetcode.com/problems/happy-number/
- **程式碼**: [`202_happy-number.c`](./202_happy-number.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

對正整數反覆將數字替換為其各位數平方和；若最終到達 1，該數為快樂數，若進入不含 1 的循環則不是。請判斷給定 n 是否為快樂數。

**思路**：每輪計算各位數平方和，並將已出現的數值存入動態陣列；若結果為 1 則成功，若新值已出現則判定進入循環。

## Problem Statement (English)

Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Return true if n is a happy number, and false if not.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Input: n = 2
Output: false
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
bool isHappy(int n) {
    
}
```
