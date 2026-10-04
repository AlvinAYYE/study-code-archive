# 0840. Magic Squares In Grid《網格中的幻方》

- **Difficulty**: Medium
- **Tags**: array, hash-table, math, matrix
- **題目連結**: https://leetcode.com/problems/magic-squares-in-grid/
- **程式碼**: [`840_magic-squares-in-grid.c`](./840_magic-squares-in-grid.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

3×3 幻方須恰好使用 1 到 9 的相異數字，且每一列、每一行與兩條對角線的總和都相同。給定元素可達 15 的整數網格，計算其中有多少個 3×3 子網格是幻方。

**思路**：程式逐一檢查可作為中心且值為 5 的位置，利用相對兩格和為 10 驗證 1 到 9 的配對與不重複性。再檢查各列與各行和為 15，以確認該 3×3 區塊。

## Problem Statement (English)

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Input: grid = [[8]]
Output: 0
```

## 限制 Constraints

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15

## 官方 C 函式簽名 Signature

```c
int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    
}
```
