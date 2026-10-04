# 0069. Sqrt(x)《x 的平方根》

- **Difficulty**: Easy
- **Tags**: math, binary-search
- **題目連結**: https://leetcode.com/problems/sqrtx/
- **程式碼**: [`069_sqrtx.c`](./069_sqrtx.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非負整數 x，回傳其平方根向下取整後的非負整數。不得使用任何內建次方函式或運算子。

**思路**：在 1 到安全上界之間進行二分搜尋，以 mid × mid 與 x 比較來調整範圍。未命中時，最終的右界就是平方根向下取整的值。

## Problem Statement (English)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

## 限制 Constraints

0 <= x <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int mySqrt(int x) {
    
}
```
