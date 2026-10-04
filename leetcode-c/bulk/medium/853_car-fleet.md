# 0853. Car Fleet《車隊》

- **Difficulty**: Medium
- **Tags**: array, stack, sorting, monotonic-stack
- **題目連結**: https://leetcode.com/problems/car-fleet/
- **程式碼**: [`853_car-fleet.c`](./853_car-fleet.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

n 輛車從不同起點 position 以各自 speed 駛向 target，車不能超車，但可追上前方車或車隊並以較慢速度同行。即使在終點才追上也算同一車隊；回傳會抵達終點的車隊數量。

**思路**：程式先依起點位置排序，計算每輛車到終點的時間並以堆疊維護車隊時間。若後方車的到達時間不小於前方車隊，就合併並移除其獨立紀錄；最後堆疊大小即為車隊數。

## Problem Statement (English)

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
Return the number of car fleets that will arrive at the destination.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:

Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation:

Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
```

## 限制 Constraints

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106

## 官方 C 函式簽名 Signature

```c
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    
}
```
