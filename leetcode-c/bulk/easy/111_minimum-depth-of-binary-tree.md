# 0111. Minimum Depth of Binary Tree《二元樹的最小深度》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/minimum-depth-of-binary-tree/
- **程式碼**: [`111_minimum-depth-of-binary-tree.c`](./111_minimum-depth-of-binary-tree.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵二元樹，求其最小深度。最小深度是從根節點到最近葉節點的最短路徑所包含的節點數。葉節點是沒有任何子節點的節點；樹可為空。樹的節點數介於 0 至 10^5，節點值介於 -1000 至 1000。

**思路**：以遞迴 DFS 走訪樹，沿途累計深度；每到葉節點便用目前深度更新最小值。

## Problem Statement (English)

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,9,20,null,null,15,7]
Output: 2

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    
}
```
