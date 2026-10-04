# 0441. Arranging Coins《排列硬幣》

- **Difficulty**: Easy
- **Tags**: math, binary-search
- **題目連結**: https://leetcode.com/problems/arranging-coins/
- **程式碼**: [`441_arranging-coins.c`](./441_arranging-coins.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 n 枚硬幣，要排成第 i 列恰有 i 枚硬幣的階梯。最後一列可以不完整，請回傳可完成的列數。

**思路**：以二分搜尋完整列數 k，利用 k(k+1)/2 判斷所需硬幣是否不超過 n。最後回傳第一個不可行列數減一。

## Problem Statement (English)

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int arrangeCoins(int n) {
    
}
```
