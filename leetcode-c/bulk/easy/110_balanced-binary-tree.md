# 0110. Balanced Binary Tree《平衡二元樹》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/balanced-binary-tree/
- **程式碼**: [`110_balanced-binary-tree.c`](./110_balanced-binary-tree.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定二元樹，判斷它是否為高度平衡樹。高度平衡表示每個節點的左右子樹高度差都不超過 1。空樹也視為平衡。

**思路**：以後序遞迴回傳子樹高度，若任何子樹已不平衡或兩側高度差超過一便回傳 -1。根節點結果非負時即為平衡。

## Problem Statement (English)

Given a binary tree, determine if it is height-balanced.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Input: root = []
Output: true
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

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
bool isBalanced(struct TreeNode* root) {
    
}
```
