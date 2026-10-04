# 0313. Super Ugly Number《超級醜數》

- **Difficulty**: Medium
- **Tags**: array, math, dynamic-programming
- **題目連結**: https://leetcode.com/problems/super-ugly-number/
- **程式碼**: [`313_super-ugly-number.c`](./313_super-ugly-number.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

超級醜數是所有質因數都包含在 primes 中的正整數。給定 n 與遞增且不重複的質數陣列 primes，請回傳第 n 個超級醜數；結果保證落在 32 位元有號整數內。

**思路**：由 1 開始建立遞增結果陣列，為每個質數維護一個指向既有醜數的索引。每輪取所有「目前醜數 × 質數」候選中的最小值，並將產生該最小值的所有索引一起前進以去重。

## Problem Statement (English)

A super ugly number is a positive integer whose prime factors are in the array primes.
Given an integer n and an array of integers primes, return the nth super ugly number.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].

Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
```

## 限制 Constraints

1 <= n <= 105
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.

## 官方 C 函式簽名 Signature

```c
int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    
}
```
