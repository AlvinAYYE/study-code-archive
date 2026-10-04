# 0100. Same Tree《相同的樹》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/same-tree/
- **程式碼**: [`100_same-tree.c`](./100_same-tree.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩棵二元樹的根節點 p 與 q，判斷兩棵樹是否相同。兩棵樹必須結構完全一致，且對應節點的值也相同，才算相同。

**思路**：遞迴同步比較兩棵樹：兩者皆空為真，僅一者為空或節點值不同為假，否則再比較左右子樹。

## Problem Statement (English)

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false

Input: p = [1,2,1], q = [1,1,2]
Output: false
```

## 限制 Constraints

The number of nodes in both trees is in the range [0, 100].
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
}
```
