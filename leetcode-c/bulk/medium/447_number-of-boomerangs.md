# 0447. Number of Boomerangs《迴力鏢的數量》

- **Difficulty**: Medium
- **Tags**: array, hash-table, math
- **題目連結**: https://leetcode.com/problems/number-of-boomerangs/
- **程式碼**: [`447_number-of-boomerangs.c`](./447_number-of-boomerangs.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定平面上互不重複的 n 個點，迴力鏢為有序三元組 (i,j,k)，其中 i 到 j 的距離等於 i 到 k 的距離。請回傳迴力鏢的總數，且三元組順序不同要分別計算。

**思路**：固定中心點 i，枚舉第一個端點 j，再枚舉 j 後的第二個端點 k 比較平方距離。每找到一對等距端點即計一次無序對，最後乘以 2 以計入兩種端點順序。

## Problem Statement (English)

You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
Return the number of boomerangs.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

Input: points = [[1,1],[2,2],[3,3]]
Output: 2

Input: points = [[1,1]]
Output: 0
```

## 限制 Constraints

n == points.length
1 <= n <= 500
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

## 官方 C 函式簽名 Signature

```c
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    
}
```
