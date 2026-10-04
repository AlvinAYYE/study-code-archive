# 0119. Pascal's Triangle II《楊輝三角 II》

- **Difficulty**: Easy
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/pascals-triangle-ii/
- **程式碼**: [`119_pascals-triangle-ii.c`](./119_pascals-triangle-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定從 0 開始計數的 rowIndex，回傳楊輝三角的第 rowIndex 列。楊輝三角每個內部數字都等於上一列正上方兩個相鄰數字之和。題目進一步要求可將額外空間最佳化為 O(rowIndex)。rowIndex 介於 0 至 33。

**思路**：迭代產生各列，利用 tmp 保留前一列，並藉由楊輝三角的對稱性只計算一半後同步寫入兩側。

## Problem Statement (English)

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

## 範例 Examples

```text
Input: rowIndex = 3
Output: [1,3,3,1]

Input: rowIndex = 0
Output: [1]

Input: rowIndex = 1
Output: [1,1]
```

## 限制 Constraints

0 <= rowIndex <= 33

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    
}
```
