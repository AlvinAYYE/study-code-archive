# 0935. Knight Dialer《騎士撥號器》

- **Difficulty**: Medium
- **Tags**: dynamic-programming
- **題目連結**: https://leetcode.com/problems/knight-dialer/
- **程式碼**: [`935_knight-dialer.c`](./935_knight-dialer.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

騎士每次可走標準西洋棋的 L 形跳法，且只能落在電話鍵盤的數字鍵上。給定 n，可任選起始數字並再跳 n - 1 次，計算可撥出的不同長度 n 電話號碼數量。答案請對 10⁹ + 7 取模。

**思路**：以滾動 DP 記錄每個數字鍵作為目前結尾的方案數，依騎士可跳到的前一鍵更新下一輪，最後加總十個鍵的數量。

## Problem Statement (English)

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:
A chess knight can move as indicated in the chess diagram below:
We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
Given an integer n, return how many distinct phone numbers of length n we can dial.
You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
As the answer may be very large, return the answer modulo 109 + 7.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
```

## 限制 Constraints

1 <= n <= 5000

## 官方 C 函式簽名 Signature

```c
int knightDialer(int n) {
    
}
```
