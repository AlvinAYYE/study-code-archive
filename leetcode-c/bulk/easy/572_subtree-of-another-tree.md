# 0572. Subtree of Another Tree《另一棵樹的子樹》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, string-matching, binary-tree, hash-function
- **題目連結**: https://leetcode.com/problems/subtree-of-another-tree/
- **程式碼**: [`572_subtree-of-another-tree.c`](./572_subtree-of-another-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩棵二元樹 root 與 subRoot，判斷 root 是否存在一棵子樹，其節點值與結構完全等同於 subRoot。樹本身也可視為自己的子樹。

**思路**：遞迴走訪 root 的每個節點，並用另一個遞迴函式逐節點比較兩棵樹的值與左右結構是否完全相同。

## Problem Statement (English)

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```

## 限制 Constraints

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104

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
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    
}
```
