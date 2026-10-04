# 0310. Minimum Height Trees《最小高度樹》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, graph, topological-sort
- **題目連結**: https://leetcode.com/problems/minimum-height-trees/
- **程式碼**: [`310_minimum-height-trees.c`](./310_minimum-height-trees.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵有 n 個節點、編號 0 到 n - 1 的無向樹，以及 n - 1 條邊，可任選一個節點作為根。請回傳所有能讓根到最遠葉節點距離最小的根節點編號；樹高定義為這條最長向下路徑的邊數。

**思路**：建立鄰接串列與每個節點的度數，將所有葉節點加入佇列。反覆分層剝除葉節點並降低鄰居度數，最後剩下的一或兩個中心節點即為結果。

## Problem Statement (English)

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
```

## 限制 Constraints

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    
}
```
