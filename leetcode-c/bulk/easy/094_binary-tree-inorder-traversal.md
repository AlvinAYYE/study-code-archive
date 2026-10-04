# 0094. Binary Tree Inorder Traversal《二元樹的中序走訪》

- **Difficulty**: Easy
- **Tags**: stack, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-inorder-traversal/
- **程式碼**: [`094_binary-tree-inorder-traversal.c`](./094_binary-tree-inorder-traversal.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定二元樹根節點，回傳所有節點值的中序走訪結果。中序走訪順序為左子樹、目前節點、右子樹；空樹的結果為空陣列。

**思路**：以遞迴先走訪左子樹，再寫入目前節點值，最後走訪右子樹。

## Problem Statement (English)

Given the root of a binary tree, return the inorder traversal of its nodes' values.
Example 1:
Example 2:
Example 3:
Example 4:
Constraints:

## 範例 Examples

```text
Input: root = [1,null,2,3]
Output: [1,3,2]
Explanation:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]
Explanation:

Input: root = []
Output: []

Input: root = [1]
Output: [1]
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 100].
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
}
```
