# 0124. Binary Tree Maximum Path Sum《二元樹中的最大路徑和》

- **Difficulty**: Hard
- **Tags**: dynamic-programming, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-maximum-path-sum/
- **程式碼**: [`124_binary-tree-maximum-path-sum.c`](./124_binary-tree-maximum-path-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

二元樹中的路徑由相鄰節點間的邊連接，且同一節點最多只能出現一次，路徑不一定經過根節點。路徑和為路徑上所有節點值的總和。給定根節點，回傳任一非空路徑可得到的最大路徑和。樹的節點數介於 1 至 3×10^4，節點值介於 -1000 至 1000。

**思路**：後序 DFS 回傳從目前節點向下延伸的最佳單邊貢獻，負貢獻歸零，並以左右貢獻加目前節點更新全域最大路徑和。

## Problem Statement (English)

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 3 * 104].
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
int maxPathSum(struct TreeNode* root) {
    
}
```
