# 0513. Find Bottom Left Tree Value《找樹左下角的值》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/find-bottom-left-tree-value/
- **程式碼**: [`513_find-bottom-left-tree-value.c`](./513_find-bottom-left-tree-value.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹的根節點，找出最底層那一列最左側的節點值。回傳該值。

**思路**：程式以佇列做層序走訪，但每個節點先將右子節點、再將左子節點入隊。如此最後被取出的最深節點便是最底層最左側的節點。

## Problem Statement (English)

Given the root of a binary tree, return the leftmost value in the last row of the tree.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [2,1,3]
Output: 1

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

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
int findBottomLeftValue(struct TreeNode* root) {
    
}
```
