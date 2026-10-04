# 0089. Gray Code《格雷編碼》

- **Difficulty**: Medium
- **Tags**: math, backtracking, bit-manipulation
- **題目連結**: https://leetcode.com/problems/gray-code/
- **程式碼**: [`089_gray-code.c`](./089_gray-code.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

n 位元格雷編碼序列含有 2^n 個介於 0 到 2^n - 1 的整數，必須以 0 開始。任兩個相鄰值（包括首尾）在二進位表示上都只能相差一個位元。給定 n，回傳任一有效序列。

**思路**：從序列 [0] 開始，每加入一個位元便反向走訪既有序列，將該位元設為 1 後附加到尾端，形成鏡射式格雷編碼。

## Problem Statement (English)

An n-bit gray code sequence is a sequence of 2n integers where:
Given an integer n, return any valid n-bit gray code sequence.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit

Input: n = 1
Output: [0,1]
```

## 限制 Constraints

1 <= n <= 16

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    
}
```
