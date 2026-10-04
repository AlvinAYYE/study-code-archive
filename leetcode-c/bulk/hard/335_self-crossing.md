# 0335. Self Crossing《路徑交叉》

- **Difficulty**: Hard
- **Tags**: array, math, geometry
- **題目連結**: https://leetcode.com/problems/self-crossing/
- **程式碼**: [`335_self-crossing.c`](./335_self-crossing.c) — 社群解答（repo tongtzeho_LeetCode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

從原點開始，依序向北、西、南、東移動 distance[0]、distance[1]、distance[2]、distance[3] 的距離，之後持續以逆時針方向循環。請判斷走出的路徑是否在任何位置與自身交叉。

**思路**：程式逐步更新目前座標，並用四個邊界記錄螺旋路徑的外框。在路徑開始向內收縮後，每一步檢查是否越過對向邊界；若越界即代表發生交叉。

## Problem Statement (English)

You are given an array of integers distance.
You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
Return true if your path crosses itself or false if it does not.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: distance = [2,1,1,2]
Output: true
Explanation: The path crosses itself at the point (0, 1).

Input: distance = [1,2,3,4]
Output: false
Explanation: The path does not cross itself at any point.

Input: distance = [1,1,1,2,1]
Output: true
Explanation: The path crosses itself at the point (0, 0).
```

## 限制 Constraints

1 <= distance.length <= 105
1 <= distance[i] <= 105

## 官方 C 函式簽名 Signature

```c
bool isSelfCrossing(int* distance, int distanceSize) {
    
}
```
