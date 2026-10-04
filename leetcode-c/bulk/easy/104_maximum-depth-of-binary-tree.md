# 0104. Maximum Depth of Binary Tree《二元樹的最大深度》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/maximum-depth-of-binary-tree/
- **程式碼**: [`104_maximum-depth-of-binary-tree.c`](./104_maximum-depth-of-binary-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，回傳其最大深度。最大深度是從根節點到最遠葉節點的最長路徑所經過的節點數。空樹的深度為 0。

**思路**：遞迴求出左右子樹深度，回傳其中較大值再加一；空節點回傳零。

## Problem Statement (English)

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,9,20,null,null,15,7]
Output: 3

Input: root = [1,null,2]
Output: 2
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

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
int maxDepth(struct TreeNode* root) {
    
}
```
