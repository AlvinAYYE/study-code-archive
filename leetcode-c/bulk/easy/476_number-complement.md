# 0476. Number Complement《數字的補數》

- **Difficulty**: Easy
- **Tags**: bit-manipulation
- **題目連結**: https://leetcode.com/problems/number-complement/
- **程式碼**: [`476_number-complement.c`](./476_number-complement.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

整數的補數，是將其不含前導零的二進位表示中每個 0 與 1 全部互換後得到的值。給定正整數 num，回傳它的補數。

**思路**：程式從低位走訪 num 的有效位元：原本為 0 的位元設入結果，原本為 1 的位元則從 num 清除。所有 1 清除後，累積值即為補數。

## Problem Statement (English)

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
Given an integer num, return its complement.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

## 範例 Examples

```text
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

## 限制 Constraints

1 <= num < 231

## 官方 C 函式簽名 Signature

```c
int findComplement(int num) {
    
}
```
