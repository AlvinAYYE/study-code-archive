# 0783. Minimum Distance Between BST Nodes《BST 節點間的最小距離》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
- **程式碼**: [`783_minimum-distance-between-bst-nodes.c`](./783_minimum-distance-between-bst-nodes.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵至少有兩個節點的二元搜尋樹，求任兩個不同節點值的最小差值。節點值範圍為 0 至 10^5。

**思路**：以中序走訪 BST，節點值會遞增；只需比較目前節點與前一個走訪節點的差值並維護最小值。

## Problem Statement (English)

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

## 範例 Examples

```text
Input: root = [4,2,6,1,3]
Output: 1

Input: root = [1,0,48,null,null,12,49]
Output: 1
```

## 限制 Constraints

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105

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
int minDiffInBST(struct TreeNode* root) {
    
}
```
