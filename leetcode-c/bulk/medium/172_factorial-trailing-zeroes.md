# 0172. Factorial Trailing Zeroes《階乘後的零》

- **Difficulty**: Medium
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/factorial-trailing-zeroes/
- **程式碼**: [`172_factorial-trailing-zeroes.c`](./172_factorial-trailing-zeroes.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，請回傳 n! 十進位表示中結尾連續 0 的個數。階乘中的尾零由 2 與 5 的因子配對產生，且 5 是較稀少的因子。題目追問能否以對數時間完成。

**思路**：程式列舉不超過 n 的各個 5 次冪，累加 n 除以每個 5 次冪的商，以計入所有 5 因子。

## Problem Statement (English)

Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you write a solution that works in logarithmic time complexity?

## 範例 Examples

```text
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Input: n = 0
Output: 0
```

## 限制 Constraints

0 <= n <= 104

## 官方 C 函式簽名 Signature

```c
int trailingZeroes(int n) {
    
}
```
