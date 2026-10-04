# 0452. Minimum Number of Arrows to Burst Balloons《用最少數量的箭引爆氣球》

- **Difficulty**: Medium
- **Tags**: array, greedy, sorting
- **題目連結**: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
- **程式碼**: [`452_minimum-number-of-arrows-to-burst-balloons.c`](./452_minimum-number-of-arrows-to-burst-balloons.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

牆面上的每個氣球以水平直徑區間 [xstart,xend] 表示，從 x 軸某一位置垂直往上射出的箭可引爆所有涵蓋該 x 座標的氣球。箭可無限向上飛行且數量不限，請求引爆全部氣球所需的最少箭數。

**思路**：將氣球依右端點遞增排序，先在第一個右端點射箭。其後只有當下一氣球的左端點大於目前箭的位置時才需新增一箭，並將位置改為該氣球的右端點。

## Problem Statement (English)

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
```

## 限制 Constraints

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    
}
```
