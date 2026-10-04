# 0653. Two Sum IV - Input is a BST《兩數之和 IV－輸入為 BST》

- **Difficulty**: Easy
- **Tags**: hash-table, two-pointers, tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
- **程式碼**: [`653_two-sum-iv-input-is-a-bst.c`](./653_two-sum-iv-input-is-a-bst.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元搜尋樹與整數 k，判斷樹中是否存在兩個不同節點，其值相加恰好等於 k。若存在回傳 true，否則回傳 false。

**思路**：走訪 BST 時用雜湊表保存已看過的節點值。對每個目前值先查找補數 k - value 是否已出現，若沒有再將目前值放入表中。

## Problem Statement (English)

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

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
bool findTarget(struct TreeNode* root, int k) {
    
}
```
