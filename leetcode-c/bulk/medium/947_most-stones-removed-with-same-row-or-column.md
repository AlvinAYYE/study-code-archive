# 0947. Most Stones Removed with Same Row or Column《移除最多的同行或同列石頭》

- **Difficulty**: Medium
- **Tags**: hash-table, depth-first-search, union-find, graph
- **題目連結**: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
- **程式碼**: [`947_most-stones-removed-with-same-row-or-column.c`](./947_most-stones-removed-with-same-row-or-column.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

平面上有 n 顆石頭，每個座標至多一顆；若一顆石頭與另一顆尚未移除的石頭同列或同行，就可移除它。給定各石頭座標，請回傳最多能移除多少顆石頭。

**思路**：以 DFS 尋找由同行或同列關係連通的石頭群；每個大小為 m 的連通元件可移除 m-1 顆，累加所有元件即可。

## Problem Statement (English)

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
```

## 限制 Constraints

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

## 官方 C 函式簽名 Signature

```c
int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    
}
```
