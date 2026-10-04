# 0029. Divide Two Integers《兩數相除》

- **Difficulty**: Medium
- **Tags**: math, bit-manipulation
- **題目連結**: https://leetcode.com/problems/divide-two-integers/
- **程式碼**: [`029_divide-two-integers.c`](./029_divide-two-integers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 dividend 與 divisor，不能使用乘法、除法或取模運算，請回傳整數除法的商。結果須朝零截斷，並限制在 32 位元有號整數範圍；超過上界時回傳 2^31-1，除數保證不為零。

**思路**：程式先處理符號與 INT_MIN 的特殊情況，再將兩數轉為正值。它反覆以左移倍增除數，找到不超過剩餘被除數的最大倍數後扣除並累加相應的 2 次冪商。

## Problem Statement (English)

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```

## 限制 Constraints

-231 <= dividend, divisor <= 231 - 1
divisor != 0

## 官方 C 函式簽名 Signature

```c
int divide(int dividend, int divisor) {
    
}
```
