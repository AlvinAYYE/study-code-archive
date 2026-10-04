# 0598. Range Addition II《範圍加法 II》

- **Difficulty**: Easy
- **Tags**: array, math
- **題目連結**: https://leetcode.com/problems/range-addition-ii/
- **程式碼**: [`598_range-addition-ii.c`](./598_range-addition-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

m × n 矩陣初始全為 0，每個操作 [ai, bi] 都會把左上角 ai × bi 區域的元素加 1。完成所有操作後，請回傳矩陣中最大值出現的元素個數。

**思路**：最大值只會出現在所有操作矩形的共同左上交集；因此遍歷操作取最小 ai 與最小 bi，兩者乘積即為答案。

## Problem Statement (English)

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.
Count and return the number of maximum integers in the matrix after performing all the operations.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.

Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4

Input: m = 3, n = 3, ops = []
Output: 9
```

## 限制 Constraints

1 <= m, n <= 4 * 104
0 <= ops.length <= 104
ops[i].length == 2
1 <= ai <= m
1 <= bi <= n

## 官方 C 函式簽名 Signature

```c
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    
}
```
