# 0144. Binary Tree Preorder Traversal《二元樹的前序走訪》

- **Difficulty**: Easy
- **Tags**: stack, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-preorder-traversal/
- **程式碼**: [`144_binary-tree-preorder-traversal.c`](./144_binary-tree-preorder-traversal.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定二元樹根節點，回傳節點值的前序走訪結果。前序走訪順序為根節點、左子樹、右子樹。題目進一步詢問能否使用迭代方式完成。樹的節點數介於 0 至 100，節點值介於 -100 至 100。

**思路**：依根、左、右的順序遞迴 DFS，造訪節點時立刻將其值寫入輸出陣列。

## Problem Statement (English)

Given the root of a binary tree, return the preorder traversal of its nodes' values.
Example 1:
Example 2:
Example 3:
Example 4:
Constraints:
Follow up: Recursive solution is trivial, could you do it iteratively?

## 範例 Examples

```text
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]
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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
}
```
