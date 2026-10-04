# 0501. Find Mode in Binary Search Tree《二元搜尋樹中的眾數》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/find-mode-in-binary-search-tree/
- **程式碼**: [`501_find-mode-in-binary-search-tree.c`](./501_find-mode-in-binary-search-tree.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵允許重複值的二元搜尋樹，回傳其中出現頻率最高的所有值。若有多個眾數，可用任意順序回傳。

**思路**：程式以中序走訪取得非遞減節點值，並比較目前值與前一值來維護連續出現次數。更新最高頻率時，重新設定或擴充答案陣列。

## Problem Statement (English)

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
Assume a BST is defined as follows:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,null,2,2]
Output: [2]

Input: root = [0]
Output: [0]
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

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
int* findMode(struct TreeNode* root, int* returnSize) {
    
}
```
