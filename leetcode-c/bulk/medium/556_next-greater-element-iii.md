# 0556. Next Greater Element III《下一個更大元素 III》

- **Difficulty**: Medium
- **Tags**: math, two-pointers, string
- **題目連結**: https://leetcode.com/problems/next-greater-element-iii/
- **程式碼**: [`556_next-greater-element-iii.c`](./556_next-greater-element-iii.c) — 社群解答（repo caotrongphuoc_algorithms），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定正整數 n，找出使用完全相同數字且比 n 大的最小整數。若不存在此數，或結果超出 32 位元有號整數範圍，回傳 -1。

**思路**：套用下一個排列：從右尋找遞減後綴前的樞紐，與右側剛好較大的數字交換後反轉後綴；最後檢查轉回整數是否溢位。

## Problem Statement (English)

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 12
Output: 21

Input: n = 21
Output: -1
```

## 限制 Constraints

1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int nextGreaterElement(int n) {
    
}
```
