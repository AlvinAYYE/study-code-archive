# 0685. Redundant Connection II《冗餘連線 II》

- **Difficulty**: Hard
- **Tags**: depth-first-search, breadth-first-search, union-find, graph
- **題目連結**: https://leetcode.com/problems/redundant-connection-ii/
- **程式碼**: [`685_redundant-connection-ii.c`](./685_redundant-connection-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

根樹是一種有向圖：根節點沒有父節點，其餘每個節點恰有一個父節點，且皆為根的後代。給定一棵含 1 到 n 節點的根樹加上一條額外有向邊後的邊列表，請回傳刪除後可恢復為根樹的邊；若有多個答案，回傳列表中最靠後者。

**思路**：先找出入度變成 2 的節點，暫時略過後出現的那條入邊，再以並查集檢測環。若仍形成環則刪較早的入邊，若未形成環則刪被略過的較晚入邊。

## Problem Statement (English)

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
```

## 限制 Constraints

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n
ui != vi

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
}
```
