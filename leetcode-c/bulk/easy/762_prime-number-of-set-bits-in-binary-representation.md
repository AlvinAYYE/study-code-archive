# 0762. Prime Number of Set Bits in Binary Representation《二進位表示中質數個計算置位》

- **Difficulty**: Easy
- **Tags**: math, bit-manipulation
- **題目連結**: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
- **程式碼**: [`762_prime-number-of-set-bits-in-binary-representation.c`](./762_prime-number-of-set-bits-in-binary-representation.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定 left 與 right，計算閉區間 [left, right] 中二進位表示裡 1 的個數為質數的整數數量。置位數即該整數二進位表示中 1 出現的次數。

**思路**：逐一走訪區間內的數字，以位元右移累計 1 的數量。再用試除法判斷該數量是否為質數並計數。

## Problem Statement (English)

Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
Recall that the number of set bits an integer has is the number of 1's present when written in binary.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.

Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
```

## 限制 Constraints

1 <= left <= right <= 106
0 <= right - left <= 104

## 官方 C 函式簽名 Signature

```c
int countPrimeSetBits(int left, int right) {
    
}
```
