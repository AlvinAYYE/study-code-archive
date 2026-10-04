# 0957. Prison Cells After N Days《N 天後的監獄牢房》

- **Difficulty**: Medium
- **Tags**: array, hash-table, math, bit-manipulation
- **題目連結**: https://leetcode.com/problems/prison-cells-after-n-days/
- **程式碼**: [`957_prison-cells-after-n-days.c`](./957_prison-cells-after-n-days.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

一列有 8 間牢房，每格為有人或空置；每天一格在兩側相鄰牢房狀態相同時變為有人，否則變為空置。第一格與最後一格因沒有兩個相鄰牢房，隔天必定為空置。給定初始 cells 與 n，回傳 n 天後的狀態。

**思路**：利用此 8 格狀態在首日後以 14 天為週期的特性，先將天數化簡為 1 至 14，再逐日模擬相鄰兩格是否相同。

## Problem Statement (English)

There are 8 prison cells in a row and each cell is either occupied or vacant.
Each day, whether the cell is occupied or vacant changes according to the following rules:
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
Return the state of the prison after n days (i.e., n such changes described above).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]
```

## 限制 Constraints

cells.length == 8
cells[i] is either 0 or 1.
1 <= n <= 109

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    
}
```
