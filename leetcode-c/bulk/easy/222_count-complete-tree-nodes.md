# 0222. Count Complete Tree Nodes《完全二元樹的節點個數》

- **Difficulty**: Easy
- **Tags**: binary-search, bit-manipulation, tree, binary-tree
- **題目連結**: https://leetcode.com/problems/count-complete-tree-nodes/
- **程式碼**: [`222_count-complete-tree-nodes.c`](./222_count-complete-tree-nodes.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定一棵完全二元樹的根節點，回傳樹中節點總數。完全二元樹除最後一層外皆填滿，最後一層節點靠左排列，並要求演算法優於 O(n)。

**思路**：分別量測子樹最左路徑與最右路徑高度；兩者相等時該子樹為滿二元樹，可直接以 2^h - 1 計數。否則遞迴計算左右子樹再加上根節點。

## Problem Statement (English)

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3,4,5,6]
Output: 6

Input: root = []
Output: 0

Input: root = [1]
Output: 1
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

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
int countNodes(struct TreeNode* root) {
    
}
```
