# 0539. Minimum Time Difference《最小時間差》

- **Difficulty**: Medium
- **Tags**: array, math, string, sorting
- **題目連結**: https://leetcode.com/problems/minimum-time-difference/
- **程式碼**: [`539_minimum-time-difference.c`](./539_minimum-time-difference.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定至少兩個 24 小時制的時間字串，找出任兩個時間點之間的最小分鐘差。時間字串格式固定為 HH:MM，跨越午夜的差距也要納入比較。

**思路**：先依 HH:MM 字串排序並換算為分鐘，比較相鄰時間差，最後再比較首尾跨過 1440 分鐘的環狀差距。

## Problem Statement (English)

Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: timePoints = ["23:59","00:00"]
Output: 1

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
```

## 限制 Constraints

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

## 官方 C 函式簽名 Signature

```c
int findMinDifference(char** timePoints, int timePointsSize) {
    
}
```
