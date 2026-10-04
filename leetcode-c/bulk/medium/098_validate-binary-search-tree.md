# 0098. Validate Binary Search Tree《驗證二元搜尋樹》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/validate-binary-search-tree/
- **程式碼**: [`098_validate-binary-search-tree.c`](./098_validate-binary-search-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，判斷它是否為有效的二元搜尋樹。每個節點的左子樹值都必須嚴格小於該節點，右子樹值都必須嚴格大於該節點，且兩側子樹也必須各自有效。

**思路**：以中序遞迴走訪二元樹並保留前一個走訪節點。只要目前值不嚴格大於前值，即可判定不是有效 BST。

## Problem Statement (English)

Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
bool isValidBST(struct TreeNode* root) {
    
}
```
