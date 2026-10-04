# 0684. Redundant Connection《冗餘連線》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, union-find, graph
- **題目連結**: https://leetcode.com/problems/redundant-connection/
- **程式碼**: [`684_redundant-connection.c`](./684_redundant-connection.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

無向連通圖原本是一棵含 n 個節點的樹，後來額外加入一條不重複的邊。找出刪除後能使圖重新成為樹的邊；若有多個可能，應回傳輸入中最後出現的那條。

**思路**：使用並查集逐邊合併兩端節點。若某條邊的兩端已屬於同一集合，該邊便形成環並作為答案。

## Problem Statement (English)

In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

## 限制 Constraints

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
}
```
