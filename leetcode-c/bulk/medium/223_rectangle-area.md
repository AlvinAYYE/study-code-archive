# 0223. Rectangle Area《矩形面積》

- **Difficulty**: Medium
- **Tags**: math, geometry
- **題目連結**: https://leetcode.com/problems/rectangle-area/
- **程式碼**: [`223_rectangle-area.c`](./223_rectangle-area.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定平面上兩個軸對齊矩形的左下與右上座標，計算兩矩形覆蓋的總面積。重疊區域只能計算一次。

**思路**：先計算兩矩形面積總和，再依座標判斷是否有交集。若有交集，計算其寬高並從總和扣除重疊面積。

## Problem Statement (English)

Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
```

## 限制 Constraints

-104 <= ax1 <= ax2 <= 104
-104 <= ay1 <= ay2 <= 104
-104 <= bx1 <= bx2 <= 104
-104 <= by1 <= by2 <= 104

## 官方 C 函式簽名 Signature

```c
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    
}
```
