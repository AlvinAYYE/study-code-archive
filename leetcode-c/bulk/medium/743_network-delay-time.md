# 0743. Network Delay Time《網路延遲時間》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, graph, heap-(priority-queue, shortest-path
- **題目連結**: https://leetcode.com/problems/network-delay-time/
- **程式碼**: [`743_network-delay-time.c`](./743_network-delay-time.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n 個編號 1 到 n 的節點與有向邊 times[i] = (ui, vi, wi)，wi 是訊號沿邊傳遞所需時間。從節點 k 發送訊號，回傳所有節點收到訊號所需的最短總等待時間；若有節點無法收到則回傳 -1。

**思路**：建立各節點的出邊資料，採用 Dijkstra 演算法反覆選取距離最小的未確定節點並鬆弛其鄰邊。所有節點確定後取最大最短距離，若有未走訪節點則回傳 -1。

## Problem Statement (English)

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

## 限制 Constraints

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

## 官方 C 函式簽名 Signature

```c
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){

}
```
