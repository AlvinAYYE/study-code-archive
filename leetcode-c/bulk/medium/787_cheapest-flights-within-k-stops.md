# 0787. Cheapest Flights Within K Stops《K 次轉機內最便宜的航班》

- **Difficulty**: Medium
- **Tags**: dynamic-programming, depth-first-search, breadth-first-search, graph, heap-(priority-queue, shortest-path
- **題目連結**: https://leetcode.com/problems/cheapest-flights-within-k-stops/
- **程式碼**: [`787_cheapest-flights-within-k-stops.c`](./787_cheapest-flights-within-k-stops.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n 個城市與航班 [from, to, price]，求從 src 到 dst、至多經過 k 個中途停靠點的最低票價。若不存在符合條件的路徑則回傳 -1；城市數最多為 100，且兩城市間沒有重複航班。

**思路**：以 dp 與前一輪 pre 陣列逐輪鬆弛航班：先初始化直飛價格，再進行 K 輪更新，因此只會使用至多 K+1 段航班。

## Problem Statement (English)

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

## 限制 Constraints

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

## 官方 C 函式簽名 Signature

```c
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    
}
```
