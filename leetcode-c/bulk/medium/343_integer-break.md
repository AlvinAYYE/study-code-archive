# 0343. Integer Break《整數拆分》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming
- **題目連結**: https://leetcode.com/problems/integer-break/
- **程式碼**: [`343_integer-break.c`](./343_integer-break.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，將它拆成 k 個正整數的和，其中 k 至少為 2。回傳所有拆分方式中，這些整數乘積可達到的最大值。

**思路**：以 dp[x] 儲存 x 可取得的最佳乘積，逐一枚舉 x 的兩部分切法並取 dp[i] * dp[x-i] 的最大值；2 與 3 則個別處理。

## Problem Statement (English)

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
```

## 限制 Constraints

2 <= n <= 58

## 官方 C 函式簽名 Signature

```c
int integerBreak(int n) {
    
}
```
