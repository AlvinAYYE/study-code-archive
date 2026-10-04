# 0204. Count Primes《計數質數》

- **Difficulty**: Medium
- **Tags**: array, math, enumeration, number-theory
- **題目連結**: https://leetcode.com/problems/count-primes/
- **程式碼**: [`204_count-primes.c`](./204_count-primes.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，請回傳所有嚴格小於 n 的質數數量。n 可為 0，最大可達 5 × 10^6。

**思路**：採線性篩法維護已發現的質數與合數標記；每個數以現有質數標記乘積，遇到其最小質因數後停止，避免重複篩除。

## Problem Statement (English)

Given an integer n, return the number of prime numbers that are strictly less than n.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Input: n = 0
Output: 0

Input: n = 1
Output: 0
```

## 限制 Constraints

0 <= n <= 5 * 106

## 官方 C 函式簽名 Signature

```c
int countPrimes(int n) {
    
}
```
