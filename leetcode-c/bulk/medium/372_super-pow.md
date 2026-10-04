# 0372. Super Pow《超級次方》

- **Difficulty**: Medium
- **Tags**: math, divide-and-conquer
- **題目連結**: https://leetcode.com/problems/super-pow/
- **程式碼**: [`372_super-pow.c`](./372_super-pow.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 a 與以數字陣列表示的極大正整數 b，計算 a^b mod 1337。b 的陣列不含前導零。

**思路**：遞迴拆開指數最後一位，使用 a^b = a^lastDigit * (a^prefix)^10，並以快速冪在每步對 1337 取模。

## Problem Statement (English)

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: a = 2, b = [3]
Output: 8

Input: a = 2, b = [1,0]
Output: 1024

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
```

## 限制 Constraints

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.

## 官方 C 函式簽名 Signature

```c
int superPow(int a, int* b, int bSize) {
    
}
```
