# 0780. Reaching Points《到達座標》

- **Difficulty**: Hard
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/reaching-points/
- **程式碼**: [`780_reaching-points.c`](./780_reaching-points.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

起點為 (sx, sy)，每次可將 (x, y) 變成 (x, x+y) 或 (x+y, y)。判斷能否到達目標 (tx, ty)，四個座標值皆介於 1 與 10^9。

**思路**：從目標反向推回起點：較大的座標持續減去較小座標，直到兩點相同或任一座標小於起點。

## Problem Statement (English)

Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: false

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: true
```

## 限制 Constraints

1 <= sx, sy, tx, ty <= 109

## 官方 C 函式簽名 Signature

```c
bool reachingPoints(int sx, int sy, int tx, int ty) {
    
}
```
