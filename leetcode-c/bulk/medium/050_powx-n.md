# 0050. Pow(x, n)《Pow(x, n)》

- **Difficulty**: Medium
- **Tags**: math, recursion
- **題目連結**: https://leetcode.com/problems/powx-n/
- **程式碼**: [`050_powx-n.c`](./050_powx-n.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

實作 pow(x, n)，計算實數 x 的整數次方 xⁿ。n 可為負數，且題目保證輸入與結果落在指定範圍內。

**思路**：使用遞迴快速冪，每次把底數平方並將指數除以二；若指數為奇數，再額外乘上一個 x。負指數先把底數取倒數後再計算。

## Problem Statement (English)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 9.26100

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

## 限制 Constraints

-100.0  0.
-104 <= xn <= 104

## 官方 C 函式簽名 Signature

```c
double myPow(double x, int n) {
    
}
```
