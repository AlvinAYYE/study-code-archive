# 0118. Pascal's Triangle《楊輝三角》

- **Difficulty**: Easy
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/pascals-triangle/
- **程式碼**: [`118_pascals-triangle.c`](./118_pascals-triangle.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 numRows，回傳楊輝三角的前 numRows 列。每列兩端皆為 1，內部每個數字等於上一列正上方兩個相鄰數字之和。numRows 介於 1 至 30。

**思路**：逐列配置陣列，先將首尾設為 1，再以前一列相鄰兩數之和填入中間位置。

## Problem Statement (English)

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Input: numRows = 1
Output: [[1]]
```

## 限制 Constraints

1 <= numRows <= 30

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    
}
```
