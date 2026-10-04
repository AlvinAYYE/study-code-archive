# 0543. Diameter of Binary Tree《二元樹的直徑》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/diameter-of-binary-tree/
- **程式碼**: [`543_diameter-of-binary-tree.c`](./543_diameter-of-binary-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，回傳樹的直徑，也就是任兩個節點間最長路徑的邊數。這條路徑不一定通過根節點。

**思路**：後序遞迴回傳每個節點往下的最大深度，並以左右子樹深度和更新全域最大直徑。

## Problem Statement (English)

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Input: root = [1,2]
Output: 1
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
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
int diameterOfBinaryTree(struct TreeNode* root) {
    
}
```
