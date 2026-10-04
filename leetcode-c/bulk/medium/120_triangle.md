# 0120. Triangle《三角形最小路徑和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming
- **題目連結**: https://leetcode.com/problems/triangle/
- **程式碼**: [`120_triangle.c`](./120_triangle.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數三角形陣列，求從頂端走到底端的最小路徑總和。位於目前列索引 i 時，下一列只能移到索引 i 或 i + 1 的相鄰數字。三角形列數介於 1 至 200，每列比前一列多一個元素，元素值介於 -10^4 至 10^4。

**思路**：由底向上以一維陣列做 DP，將每個位置更新為目前值加上下列兩個可達位置的較小路徑和。

## Problem Statement (English)

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Input: triangle = [[-10]]
Output: -10
```

## 限制 Constraints

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

## 官方 C 函式簽名 Signature

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    
}
```
