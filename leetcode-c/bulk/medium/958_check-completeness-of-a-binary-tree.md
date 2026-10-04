# 0958. Check Completeness of a Binary Tree《檢查二元樹完整性》

- **Difficulty**: Medium
- **Tags**: tree, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
- **程式碼**: [`958_check-completeness-of-a-binary-tree.c`](./958_check-completeness-of-a-binary-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，判斷它是否為完全二元樹。完全二元樹除最後一層外各層皆填滿，最後一層的節點必須盡可能靠左。

**思路**：程式以 DFS 中序式地檢查空子節點的深度，記住可接受的深度與是否已縮短一層；一旦空節點深度不符合完整樹的排列規則即回傳 false。

## Problem Statement (English)

Given the root of a binary tree, determine if it is a complete binary tree.
In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000

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
bool isCompleteTree(struct TreeNode* root) {
    
}
```
