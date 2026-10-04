# 0547. Number of Provinces《省份數量》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, union-find, graph
- **題目連結**: https://leetcode.com/problems/number-of-provinces/
- **程式碼**: [`547_number-of-provinces.c`](./547_number-of-provinces.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 n 座城市，isConnected[i][j] 為 1 代表第 i 與第 j 座城市直接相連；直接或間接相連的城市形成一個省份。請回傳全部省份的數量。

**思路**：逐一尋找尚未拜訪的城市，將其加入佇列進行 BFS 並標記所有可達城市；每啟動一次新的搜尋就多一個省份。

## Problem Statement (English)

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
```

## 限制 Constraints

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

## 官方 C 函式簽名 Signature

```c
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    
}
```
