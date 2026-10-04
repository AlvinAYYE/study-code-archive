# 0391. Perfect Rectangle《完美矩形》

- **Difficulty**: Hard
- **Tags**: array, hash-table, math, geometry, line-sweep
- **題目連結**: https://leetcode.com/problems/perfect-rectangle/
- **程式碼**: [`391_perfect-rectangle.c`](./391_perfect-rectangle.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定多個軸對齊矩形，每個 rectangles[i] = [xi, yi, ai, bi] 的左下角為 (xi, yi)、右上角為 (ai, bi)。判斷所有矩形合起來是否恰好完整覆蓋一個矩形區域，不能有缺口或重疊。

**思路**：累加各矩形面積並維護外框，同時以集合切換每個角點的存在狀態；最後面積須等於外框面積，且集合只剩外框四個角。

## Problem Statement (English)

Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
Return true if all the rectangles together form an exact cover of a rectangular region.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.

Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.

Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.
```

## 限制 Constraints

1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi < ai <= 105
-105 <= yi < bi <= 105

## 官方 C 函式簽名 Signature

```c
bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    
}
```
