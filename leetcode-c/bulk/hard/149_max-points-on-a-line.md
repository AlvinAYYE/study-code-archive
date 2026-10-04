# 0149. Max Points on a Line《直線上的最大點數》

- **Difficulty**: Hard
- **Tags**: array, hash-table, math, geometry
- **題目連結**: https://leetcode.com/problems/max-points-on-a-line/
- **程式碼**: [`149_max-points-on-a-line.c`](./149_max-points-on-a-line.c) — 社群解答（repo Senthil455_Leetcode-Code），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定平面點陣列 points，其中 points[i] = [xi, yi]，求同一直線上最多有多少點。所有點皆互不相同。點數介於 1 至 300，座標 xi、yi 介於 -10^4 至 10^4。

**思路**：逐一固定一個點作為錨點，將其與其他點的斜率以最大公因數約分並正規化後放入雜湊表計數，取各錨點的最大值。

## Problem Statement (English)

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
```

## 限制 Constraints

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

## 官方 C 函式簽名 Signature

```c
int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    
}
```
