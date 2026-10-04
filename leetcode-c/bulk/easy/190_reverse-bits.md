# 0190. Reverse Bits《反轉位元》

- **Difficulty**: Easy
- **Tags**: divide-and-conquer, bit-manipulation
- **題目連結**: https://leetcode.com/problems/reverse-bits/
- **程式碼**: [`190_reverse-bits.c`](./190_reverse-bits.c) — 社群解答（repo lennylxx_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個 32 位元無號整數，請將它的 32 個二進位位元順序完全反轉，並回傳結果。題目也詢問在函式需多次呼叫時可如何最佳化。

**思路**：以遮罩分階段交換相鄰的 1、2、4、8 與 16 位元區塊，五輪即可完成整個 32 位元字的反轉。

## Problem Statement (English)

Reverse bits of a given 32 bits unsigned integer.
Note:
Example 1:
Example 2:
Constraints:
Follow up: If this function is called many times, how would you optimize it?

## 範例 Examples

```text
Input: n = 43261596
Output: 964176192
Explanation:

Input: n = 2147483644
Output: 1073741822
Explanation:
```

## 限制 Constraints

0 <= n <= 231 - 2
n is even.

## 官方 C 函式簽名 Signature

```c
int reverseBits(int n) {
    
}
```
