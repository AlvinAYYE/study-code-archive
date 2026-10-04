# 0145. Binary Tree Postorder Traversal《二元樹的後序走訪》

- **Difficulty**: Easy
- **Tags**: stack, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-postorder-traversal/
- **程式碼**: [`145_binary-tree-postorder-traversal.c`](./145_binary-tree-postorder-traversal.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定二元樹根節點，回傳節點值的後序走訪結果。後序走訪順序為左子樹、右子樹、根節點。樹的節點數介於 0 至 100，節點值介於 -100 至 100。

**思路**：依左、右、根的順序遞迴 DFS，待兩個子樹都走訪後才將目前節點值寫入輸出。

## Problem Statement (English)

Given the root of a binary tree, return the postorder traversal of its nodes' values.
Example 1:
Example 2:
Example 3:
Example 4:
Constraints:

## 範例 Examples

```text
Input: root = [1,null,2,3]
Output: [3,2,1]
Explanation:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]
Explanation:

Input: root = []
Output: []

Input: root = [1]
Output: [1]
```

## 限制 Constraints

The number of the nodes in the tree is in the range [0, 100].
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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
}
```
