# 0461. Hamming Distance《漢明距離》

- **Difficulty**: Easy
- **Tags**: bit-manipulation
- **題目連結**: https://leetcode.com/problems/hamming-distance/
- **程式碼**: [`461_hamming-distance.c`](./461_hamming-distance.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

兩個整數的漢明距離，是其二進位表示中對應位元不同的位置數量。給定 x 與 y，回傳兩者的漢明距離。

**思路**：先以 XOR 取得不同位元，再反覆執行 k &= k - 1 消去最低位的 1。消去次數就是答案。

## Problem Statement (English)

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them.
Example 1:
Example 2:
Constraints:
Note: This question is the same as  2220: Minimum Bit Flips to Convert Number.

## 範例 Examples

```text
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Input: x = 3, y = 1
Output: 1
```

## 限制 Constraints

0 <= x, y <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int hammingDistance(int x, int y) {
    
}
```
