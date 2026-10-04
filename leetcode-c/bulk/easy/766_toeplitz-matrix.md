# 0766. Toeplitz Matrix《托普利茲矩陣》

- **Difficulty**: Easy
- **Tags**: array, matrix
- **題目連結**: https://leetcode.com/problems/toeplitz-matrix/
- **程式碼**: [`766_toeplitz-matrix.c`](./766_toeplitz-matrix.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個 m × n 矩陣，判斷它是否為托普利茲矩陣。若每條由左上往右下的對角線元素都相同，便回傳 true，否則回傳 false。

**思路**：逐一比較每個非最後一列、非最後一欄的元素與其右下方元素；任一對不同即回傳 false。

## Problem Statement (English)

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
```

## 限制 Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99

## 官方 C 函式簽名 Signature

```c
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    
}
```
