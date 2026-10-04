# 0836. Rectangle Overlap《矩形重疊》

- **Difficulty**: Easy
- **Tags**: math, geometry
- **題目連結**: https://leetcode.com/problems/rectangle-overlap/
- **程式碼**: [`836_rectangle-overlap.c`](./836_rectangle-overlap.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每個與座標軸平行的矩形以 [x1, y1, x2, y2] 表示，其中前者為左下角、後者為右上角。判斷兩矩形的交集面積是否為正；僅在邊或角相接不算重疊。回傳是否重疊。

**思路**：分別以嚴格不等式檢查兩矩形在 x 軸與 y 軸上的區間是否交疊。兩個軸向皆有正長度交集時才回傳 true。

## Problem Statement (English)

An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.
Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false
```

## 限制 Constraints

rec1.length == 4
rec2.length == 4
-109 <= rec1[i], rec2[i] <= 109
rec1 and rec2 represent a valid rectangle with a non-zero area.

## 官方 C 函式簽名 Signature

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    
}
```
